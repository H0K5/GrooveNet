/***************************************************************************
 *   Copyright (C) 2005, Carnegie Mellon University.                       *
 *   Maintained by: Daniel Weller                                          *
 *                  Rahul Mangharam                                        *
 *                  and the rest of the GrooveNet Team                     *
 *                                                                         *
 *   Email: dweller@ece.cmu.edu or rahulm@ece.cmu.edu                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef _MULTIPHYSMODEL
#define _MULTIPHYSMODEL

#include "CarModel.h"

#define MULTIPHYSMODEL_NAME "MultiPhysModel"

class MultiPhysModel : public CarPhysModel
{
public:
	inline virtual QString GetModelType() const
	{
		return MULTIPHYSMODEL_NAME;
	}
	inline virtual bool IsModelTypeOf(const QString & strModelType, bool bDescendSufficient = true) const
	{
		return strModelType.compare(MULTIPHYSMODEL_NAME) == 0 || (bDescendSufficient && CarPhysModel::IsModelTypeOf(strModelType, bDescendSufficient));
	}

	MultiPhysModel(const QString & strModelName = QString::null);
	MultiPhysModel(const MultiPhysModel & copy);
	virtual ~MultiPhysModel();

	virtual int Init(const std::map<QString, QString> & mapParams);
	virtual int Save(std::map<QString, QString> & mapParams);

	virtual MultiPhysModel & operator = (const MultiPhysModel & copy);

	static void GetParams(std::map<QString, ModelParameter> & mapParams);
	virtual bool DoUpdate(struct timeval tCurrent);

	virtual void SetCar(in_addr_t ipCar);

	virtual bool BeginProcessPacket(Packet * packet);
	virtual bool EndProcessPacket(Packet * packet);
	virtual bool ReceivePacket(Packet * packet);
	virtual float GetRXRange(const Packet * packet) const;
	virtual bool IsCarInRange(const Coords & ptCar, const Coords & ptPosition) const;
	virtual unsigned int GetMessageCount() const;
	virtual unsigned int GetCollisionCount() const;

protected:
	virtual CarPhysModel * GetRelevantModel(const Packet * packet);
	virtual CarPhysModel * GetRelevantModel(const Packet * packet) const;

	std::map<QString, CarPhysModel *> m_mapPhysModels;
	std::map<QString, QString> m_mapPhysModelNames;
};

inline Model * MultiPhysModelCreator(const QString & strModelName)
{
	return new MultiPhysModel(strModelName);
}

#endif
