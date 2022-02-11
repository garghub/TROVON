static bool
F_1 ( const struct V_1 * V_2 , int V_3 , unsigned int V_4 ,
bool V_5 , T_1 * V_6 , T_2 * V_7 )
{
switch ( V_3 ) {
case V_8 : {
struct V_9 V_10 ;
const struct V_9 * V_11 ;
V_11 = F_2 ( V_2 , V_4 , sizeof( V_10 ) , & V_10 ) ;
if ( V_11 == NULL )
return false ;
* V_6 = V_5 ? V_11 -> V_12 : V_11 -> V_13 ;
break;
}
case V_14 : {
T_3 V_15 ;
const T_3 * V_16 ;
V_16 = F_2 ( V_2 , V_4 , sizeof( V_15 ) , & V_15 ) ;
if ( V_16 == NULL )
return false ;
* V_6 = V_5 ? V_16 -> V_12 : V_16 -> V_13 ;
break;
}
case V_17 :
case V_18 : {
struct V_19 V_20 ;
const struct V_19 * V_21 ;
V_21 = F_2 ( V_2 , V_4 , sizeof( V_20 ) , & V_20 ) ;
if ( V_21 == NULL )
return false ;
* V_6 = V_5 ? V_21 -> V_12 : V_21 -> V_13 ;
break;
}
case V_22 : {
struct V_23 V_24 ;
const struct V_23 * V_25 ;
V_25 = F_2 ( V_2 , V_4 , sizeof( V_24 ) , & V_24 ) ;
if ( V_25 == NULL )
return false ;
* V_6 = ( V_26 T_1 ) F_3 ( ( V_25 -> type << 8 ) | V_25 -> V_27 ) ;
break;
}
case V_28 : {
struct V_29 V_24 ;
const struct V_29 * V_25 ;
V_25 = F_2 ( V_2 , V_4 , sizeof( V_24 ) , & V_24 ) ;
if ( V_25 == NULL )
return false ;
* V_6 = ( V_26 T_1 )
F_3 ( ( V_25 -> V_30 << 8 ) | V_25 -> V_31 ) ;
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
const struct V_32 * V_33 = F_5 ( V_2 ) ;
unsigned int V_4 = F_6 ( V_2 ) ;
int V_3 = V_33 -> V_3 ;
if ( V_3 <= 0 )
return false ;
if ( F_7 ( V_33 -> V_34 ) & V_35 )
switch ( V_3 ) {
case V_8 :
case V_14 :
case V_17 :
case V_18 :
case V_22 :
return false ;
default:
* V_7 = V_3 ;
return true ;
}
return F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ) ;
}
bool
F_8 ( const struct V_1 * V_2 , bool V_5 ,
T_1 * V_6 , T_2 * V_7 )
{
int V_36 ;
T_2 V_37 ;
T_1 V_34 = 0 ;
V_37 = F_9 ( V_2 ) -> V_37 ;
V_36 = F_10 ( V_2 , sizeof( struct V_38 ) , & V_37 ,
& V_34 ) ;
if ( V_36 < 0 || ( V_34 & F_3 ( ~ 0x7 ) ) != 0 )
return false ;
return F_1 ( V_2 , V_37 , V_36 , V_5 , V_6 , V_7 ) ;
}
bool
F_11 ( const struct V_1 * V_2 , T_2 V_39 , bool V_5 , T_1 * V_6 )
{
bool V_40 ;
T_2 V_7 ;
switch ( V_39 ) {
case V_41 :
V_40 = F_4 ( V_2 , V_5 , V_6 , & V_7 ) ;
break;
case V_42 :
V_40 = F_8 ( V_2 , V_5 , V_6 , & V_7 ) ;
break;
default:
return false ;
}
if ( ! V_40 )
return V_40 ;
switch ( V_7 ) {
case V_8 :
case V_17 :
return true ;
default:
return false ;
}
}
