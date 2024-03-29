//Author: Wesley Anastasi
//Assignment Title: Program 23
//Assignment Description: Line class
//Due Date: 4/11/2022
//Date Created: 4/6/2022
//Date Last Modified: 4/6/2022

#include "Line.h"

Line::Line(Point point1, Point point2)
{
    p1 = point1;
    p2 = point2;
}

void Line::setFirstPoint(const Point& pointOther)
{
    p1 = pointOther;
}

void Line::setSecondPoint(const Point& pointOther)
{
    p2 = pointOther;
}

Point Line::getFirstPoint() const
{
    return p1;
}

Point Line::getSecondPoint() const
{
    return p2;
}

bool Line::hasSlope() const
{
    bool containsSlope = true;
    if (p1.x == p2.x || p1.y == p2.y)
    {
        containsSlope = false;
    }
    return containsSlope;
}

double Line::slope() const
{
    double getSlope;
    getSlope = static_cast<double>(p1.y - p2.y)/(p1.x-p2.x);
    return getSlope;
}

double Line::yIntercept() const
{
    double yInt;
    yInt = slope()*(-p1.x) + p1.y;
    return yInt;
}

bool Line::isParallel(const Line& otherLine) const
{
    bool isIt = false;
    if (slope() == otherLine.slope() && !isCollinear(otherLine))
    {
        isIt = true;
    }
    return isIt;
}

bool Line::isCollinear(const Line& otherLine) const
{
    bool isIt = false;
    if (slope() == otherLine.slope() && yIntercept() == otherLine.yIntercept())
    {
        isIt = true;
    }
    return isIt;
}

bool Line::isPerpendicular(const Line& otherLine) const
{
    bool isIt = false;
    if (slope() == otherLine.slope()*-1)
    {
        isIt = true;
    }
    return isIt;
}

Point Line::intersect(const Line& otherLine) const
{
    Point point;
    double xSlope;
    double yInt;
    double x;
    double y;
    if (hasSlope() && otherLine.hasSlope())
    {
        //y = ax + b
        //y = cx + d
        //ax + b = cx + d
        //(a-c)x = d-b
        xSlope = slope() + otherLine.slope()*-1;
        yInt = yIntercept()*-1 + otherLine.yIntercept();
        x = yInt/xSlope;
        y = slope()*x + yIntercept();
    }
    else
    {
        if (hasSlope())
        {
            if (otherLine.p1.x == otherLine.p2.x)
            {
                //y = ax + b
                //x = d
                //y = a(d) + b
                x = otherLine.p1.x;
                y = slope()*x + yIntercept();
            }
            else
            {
                //y = ax + b
                //y = d
                //x = (d-b)/a
                x = (otherLine.p1.y - yIntercept())/slope();
                y = otherLine.p1.y;
            }
        }
        else
        {
            if (p1.x == p2.x)
            {
                //y = ax + b
                //x = d
                //y = a(d) + b
                x = p1.x;
                y = otherLine.slope()*x + otherLine.yIntercept();
            }
            else
            {
                //y = ax + b
                //y = d
                //x = (d-b)/a
                x = (p1.y - otherLine.yIntercept())/otherLine.slope();
                y = p1.y;
            }
        }
    }
    x = round(x);
    y = round(y);
    point.x = x;
    point.y = y;
    return point;
}

void Line::display(ostream& out) const
{
    if (!hasSlope())
    {
        if (p1.x == p2.x)
        {
            out << "x = " << p1.x;
        }
        else
        {
            out << "y = " << p1.y;
        }
    }
    else
    {
        out << "y = ";
        if (slope() != 1)
        {
            if (slope() == -1)
            {
                out << "-";
            }
            else
            {
                out << slope();
            }
        }
        out << "x";
        if (yIntercept() != 0)
        {
            if (yIntercept() < 0)
            {
                out << " ";
            }
            else
            {
                out << " + ";
            }
            out << yIntercept();
        }
    }
}