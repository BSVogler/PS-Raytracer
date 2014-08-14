/* 
 * File:   RenderObject.hpp
 * Author: Benedikt Vogler
 *
 * Created on 14. August 2014, 15:47
 */

#ifndef RENDEROBJECT_HPP
#define	RENDEROBJECT_HPP

#include <glm/glm.hpp>
#include "ray.hpp"
#include "Material.hpp"

class RenderObject {
public:
    RenderObject(Material const& material) :
        material(material)
    {}

    virtual std::pair<bool, glm::vec3> intersect(Ray const& ray) const  =0;
private:
    Material material;
};

#endif	/* RENDEROBJECT_HPP */