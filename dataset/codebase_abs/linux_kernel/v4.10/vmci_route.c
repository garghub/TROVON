int F_1 ( struct V_1 * V_2 ,
const struct V_1 * V_3 ,
bool V_4 ,
enum F_1 * V_5 )
{
bool V_6 = F_2 () ;
bool V_7 = F_3 () ;
* V_5 = V_8 ;
if ( V_9 == V_3 -> V_10 )
return V_11 ;
if ( V_12 == V_3 -> V_10 ) {
if ( V_4 )
return V_13 ;
if ( ! V_7 )
return V_14 ;
if ( V_15 == V_2 -> V_10 )
return V_11 ;
if ( V_9 == V_2 -> V_10 &&
V_9 != V_2 -> V_16 )
V_2 -> V_10 = F_4 () ;
* V_5 = V_17 ;
return V_18 ;
}
if ( V_15 == V_3 -> V_10 ) {
if ( V_2 -> V_10 == V_12 ) {
if ( V_6 ) {
* V_5 = V_19 ;
return V_18 ;
} else {
return V_14 ;
}
}
if ( ! V_4 && V_7 ) {
if ( V_9 == V_2 -> V_10 )
V_2 -> V_10 = F_4 () ;
* V_5 = V_17 ;
return V_18 ;
}
if ( ! V_6 )
return V_14 ;
if ( V_9 == V_2 -> V_10 ) {
if ( V_4 )
return V_11 ;
V_2 -> V_10 = V_15 ;
}
* V_5 = V_19 ;
return V_18 ;
}
if ( V_6 ) {
if ( F_5 ( V_3 -> V_10 ) ) {
if ( V_9 == V_2 -> V_10 ) {
if ( V_4 )
return V_11 ;
V_2 -> V_10 = V_15 ;
} else if ( F_6 ( V_2 -> V_10 ) &&
V_2 -> V_10 != V_3 -> V_10 ) {
return V_13 ;
}
* V_5 = V_19 ;
return V_18 ;
} else if ( ! V_7 ) {
return V_13 ;
}
}
if ( ! V_7 ) {
return V_14 ;
}
if ( V_9 == V_2 -> V_10 )
V_2 -> V_10 = F_4 () ;
* V_5 = V_17 ;
return V_18 ;
}
