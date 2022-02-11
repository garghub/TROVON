char * F_1 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_3 :
return L_1 ;
case V_4 :
return L_2 ;
case V_5 :
return L_3 ;
case V_6 :
return L_4 ;
default:
return L_5 ;
}
return L_5 ;
}
static inline void F_2 ( struct V_7 * V_8 ,
enum V_1 V_9 )
{
F_3 ( V_10 , L_6 ,
F_1 ( V_8 -> V_1 ) ,
F_1 ( V_9 ) ) ;
V_8 -> V_1 = V_9 ;
}
void F_4 ( struct V_7 * V_8 )
{
struct V_11 * V_12 = & V_8 -> V_12 ;
V_12 -> V_13 = true ;
V_12 -> V_14 = V_15 ;
V_12 -> V_16 = 0 ;
V_12 -> V_17 = 0 ;
V_12 -> V_18 = 0 ;
V_12 -> V_19 = 0 ;
V_12 -> V_20 = 0 ;
V_12 -> V_21 = V_22 ;
V_12 -> V_23 = 0 ;
V_12 -> V_24 = 0 ;
V_12 -> V_25 = 0 ;
V_12 -> V_26 = V_27 ;
}
void F_5 ( struct V_7 * V_8 )
{
if ( V_8 -> V_1 != V_3 ) {
F_3 ( V_28 ,
L_7 ,
V_29 , F_1 ( V_8 -> V_1 ) ) ;
return;
}
if ( F_6 ( V_8 , true ) ) {
F_3 ( V_28 ,
L_8 ,
V_29 ) ;
return;
}
F_2 ( V_8 , V_5 ) ;
}
void F_7 ( struct V_7 * V_8 )
{
if ( V_8 -> V_1 != V_6 ) {
F_3 ( V_28 ,
L_9 ,
V_29 , F_1 ( V_8 -> V_1 ) ) ;
return;
}
if ( F_6 ( V_8 , false ) ) {
F_3 ( V_28 ,
L_8 ,
V_29 ) ;
return;
}
F_2 ( V_8 , V_4 ) ;
}
void F_8 ( struct V_7 * V_8 )
{
int V_30 ;
if ( V_8 -> V_1 != V_6 )
return;
V_30 = F_6 ( V_8 , false ) ;
if ( ! V_30 )
V_30 = F_6 ( V_8 , true ) ;
if ( V_30 )
F_3 ( V_28 ,
L_8 ,
V_29 ) ;
}
int F_9 ( struct V_7 * V_8 , T_1 * V_31 )
{
T_2 V_32 = F_10 ( V_31 + V_33 ) ;
switch ( V_32 ) {
case V_34 :
if ( V_8 -> V_1 == V_5 )
F_2 ( V_8 , V_6 ) ;
break;
case V_35 :
if ( V_8 -> V_1 == V_4 )
F_2 ( V_8 , V_3 ) ;
break;
default:
F_3 ( V_28 ,
L_10 ,
V_32 , F_1 ( V_8 -> V_1 ) ) ;
return - 1 ;
}
return 0 ;
}
