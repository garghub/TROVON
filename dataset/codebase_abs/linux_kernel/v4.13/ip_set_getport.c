static bool
F_1 ( const struct V_1 * V_2 , int V_3 , unsigned int V_4 ,
bool V_5 , T_1 * V_6 , T_2 * V_7 )
{
switch ( V_3 ) {
case V_8 : {
struct V_9 V_10 ;
const struct V_9 * V_11 ;
V_11 = F_2 ( V_2 , V_4 , sizeof( V_10 ) , & V_10 ) ;
if ( ! V_11 )
return false ;
* V_6 = V_5 ? V_11 -> V_12 : V_11 -> V_13 ;
break;
}
case V_14 : {
struct V_15 V_16 ;
const struct V_15 * V_17 ;
V_17 = F_2 ( V_2 , V_4 , sizeof( V_16 ) , & V_16 ) ;
if ( ! V_17 )
return false ;
* V_6 = V_5 ? V_17 -> V_12 : V_17 -> V_13 ;
break;
}
case V_18 :
case V_19 : {
struct V_20 V_21 ;
const struct V_20 * V_22 ;
V_22 = F_2 ( V_2 , V_4 , sizeof( V_21 ) , & V_21 ) ;
if ( ! V_22 )
return false ;
* V_6 = V_5 ? V_22 -> V_12 : V_22 -> V_13 ;
break;
}
case V_23 : {
struct V_24 V_25 ;
const struct V_24 * V_26 ;
V_26 = F_2 ( V_2 , V_4 , sizeof( V_25 ) , & V_25 ) ;
if ( ! V_26 )
return false ;
* V_6 = ( V_27 T_1 ) F_3 ( ( V_26 -> type << 8 ) | V_26 -> V_28 ) ;
break;
}
case V_29 : {
struct V_30 V_25 ;
const struct V_30 * V_26 ;
V_26 = F_2 ( V_2 , V_4 , sizeof( V_25 ) , & V_25 ) ;
if ( ! V_26 )
return false ;
* V_6 = ( V_27 T_1 )
F_3 ( ( V_26 -> V_31 << 8 ) | V_26 -> V_32 ) ;
break;
}
default:
break;
}
* V_7 = V_3 ;
return true ;
}
bool
F_4 ( const struct V_1 * V_2 , bool V_5 ,
T_1 * V_6 , T_2 * V_7 )
{
const struct V_33 * V_34 = F_5 ( V_2 ) ;
unsigned int V_4 = F_6 ( V_2 ) + F_7 ( V_2 ) ;
int V_3 = V_34 -> V_3 ;
if ( V_3 <= 0 )
return false ;
if ( F_8 ( V_34 -> V_35 ) & V_36 )
switch ( V_3 ) {
case V_8 :
case V_14 :
case V_18 :
case V_19 :
case V_23 :
return false ;
default:
* V_7 = V_3 ;
return true ;
}
return F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ) ;
}
bool
F_9 ( const struct V_1 * V_2 , bool V_5 ,
T_1 * V_6 , T_2 * V_7 )
{
int V_37 ;
T_2 V_38 ;
T_1 V_35 = 0 ;
V_38 = F_10 ( V_2 ) -> V_38 ;
V_37 = F_11 ( V_2 ,
F_6 ( V_2 ) +
sizeof( struct V_39 ) , & V_38 ,
& V_35 ) ;
if ( V_37 < 0 || ( V_35 & F_3 ( ~ 0x7 ) ) != 0 )
return false ;
return F_1 ( V_2 , V_38 , V_37 , V_5 , V_6 , V_7 ) ;
}
bool
F_12 ( const struct V_1 * V_2 , T_2 V_40 , bool V_5 , T_1 * V_6 )
{
bool V_41 ;
T_2 V_7 ;
switch ( V_40 ) {
case V_42 :
V_41 = F_4 ( V_2 , V_5 , V_6 , & V_7 ) ;
break;
case V_43 :
V_41 = F_9 ( V_2 , V_5 , V_6 , & V_7 ) ;
break;
default:
return false ;
}
if ( ! V_41 )
return V_41 ;
switch ( V_7 ) {
case V_8 :
case V_18 :
return true ;
default:
return false ;
}
}
