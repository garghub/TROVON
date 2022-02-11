static inline int F_1 ( T_1 V_1 )
{
switch ( V_1 ) {
case V_2 :
case V_3 :
case V_4 :
case V_5 :
case V_6 :
case V_7 :
return 0 ;
case V_8 :
return 4 ;
default:
return 0 ;
}
}
static inline int F_2 ( struct V_9 * V_10 , T_1 V_11 )
{
return F_3 ( V_10 , V_11 + F_4 ( struct V_12 , V_13 ) )
& ( V_14 | V_15 ) ;
}
static inline T_2 F_5 ( struct V_9 * V_10 , T_1 V_16 )
{
T_1 V_17 = F_6 ( V_10 , V_16 ) ;
T_1 V_18 = F_6 ( V_10 , V_16 + 4 ) ;
T_1 V_19 = F_6 ( V_10 , V_16 + 8 ) ;
T_1 V_20 = F_6 ( V_10 , V_16 + 12 ) ;
return ( T_2 ) ( V_17 ^ V_18 ^ V_19 ^ V_20 ) ;
}
static inline T_1 F_7 ( struct V_9 * V_21 , T_1 V_11 , T_1 * V_22 ,
struct V_23 * V_24 )
{
T_1 V_25 ;
if ( F_8 ( F_2 ( V_21 , V_11 ) ) )
* V_22 = 0 ;
else
* V_22 = F_9 ( V_21 , V_11 + F_4 ( struct V_12 , V_26 ) ) ;
if ( * V_22 != V_27 ) {
V_24 -> V_28 = F_6 ( V_21 , V_11 + F_4 ( struct V_12 , V_29 ) ) ;
V_24 -> V_30 = F_6 ( V_21 , V_11 + F_4 ( struct V_12 , V_31 ) ) ;
}
V_25 = F_9 ( V_21 , V_11 + 0 ) ;
if ( F_10 ( V_25 == 0x45 ) )
V_11 += 20 ;
else
V_11 += ( V_25 & 0xF ) << 2 ;
return V_11 ;
}
static inline T_1 F_11 ( struct V_9 * V_21 , T_1 V_11 , T_1 * V_22 ,
struct V_23 * V_24 )
{
* V_22 = F_9 ( V_21 ,
V_11 + F_4 ( struct V_32 , V_33 ) ) ;
V_24 -> V_28 = F_5 ( V_21 ,
V_11 + F_4 ( struct V_32 , V_29 ) ) ;
V_24 -> V_30 = F_5 ( V_21 ,
V_11 + F_4 ( struct V_32 , V_31 ) ) ;
V_11 += sizeof( struct V_32 ) ;
return V_11 ;
}
static inline bool F_12 ( struct V_9 * V_21 , struct V_23 * V_24 )
{
T_1 V_11 = V_34 ;
T_1 V_22 ;
T_1 V_1 = F_3 ( V_21 , 12 ) ;
int V_35 ;
if ( V_1 == V_36 ) {
V_1 = F_3 ( V_21 , V_11 + F_4 ( struct V_37 ,
V_38 ) ) ;
V_11 += sizeof( struct V_37 ) ;
}
if ( V_1 == V_39 ) {
V_1 = F_3 ( V_21 , V_11 + F_4 ( struct V_37 ,
V_38 ) ) ;
V_11 += sizeof( struct V_37 ) ;
}
if ( F_10 ( V_1 == V_40 ) )
V_11 = F_7 ( V_21 , V_11 , & V_22 , V_24 ) ;
else if ( V_1 == V_41 )
V_11 = F_11 ( V_21 , V_11 , & V_22 , V_24 ) ;
else
return false ;
switch ( V_22 ) {
case V_27 : {
struct V_42 {
T_3 V_43 ;
T_3 V_1 ;
};
T_1 V_44 = F_3 ( V_21 ,
V_11 + F_4 ( struct V_42 , V_43 ) ) ;
T_1 V_45 = F_3 ( V_21 ,
V_11 + F_4 ( struct V_42 , V_1 ) ) ;
if ( V_44 & ( V_46 | V_47 ) )
break;
V_1 = V_45 ;
V_11 += 4 ;
if ( V_44 & V_48 )
V_11 += 4 ;
if ( V_44 & V_49 )
V_11 += 4 ;
if ( V_44 & V_50 )
V_11 += 4 ;
if ( V_1 == V_39 ) {
V_1 = F_3 ( V_21 ,
V_11 + F_4 ( struct V_37 ,
V_38 ) ) ;
V_11 += sizeof( struct V_37 ) ;
}
if ( V_1 == V_40 )
V_11 = F_7 ( V_21 , V_11 , & V_22 , V_24 ) ;
else if ( V_1 == V_41 )
V_11 = F_11 ( V_21 , V_11 , & V_22 , V_24 ) ;
else
return false ;
break;
}
case V_51 :
V_11 = F_7 ( V_21 , V_11 , & V_22 , V_24 ) ;
break;
case V_52 :
V_11 = F_11 ( V_21 , V_11 , & V_22 , V_24 ) ;
break;
default:
break;
}
V_24 -> V_22 = V_22 ;
V_35 = F_1 ( V_22 ) ;
if ( V_35 >= 0 ) {
V_11 += V_35 ;
V_24 -> V_53 = F_6 ( V_21 , V_11 ) ;
}
V_24 -> V_54 = ( V_55 ) V_11 ;
return true ;
}
int F_13 ( struct V_9 * V_21 )
{
struct V_23 V_24 = {} ;
struct V_56 * V_57 ;
T_4 V_58 ;
if ( ! F_12 ( V_21 , & V_24 ) )
return 0 ;
V_58 = V_24 . V_30 ;
V_57 = F_14 ( & V_59 , & V_58 ) ;
if ( V_57 ) {
F_15 ( & V_57 -> V_60 , 1 ) ;
F_15 ( & V_57 -> V_61 , V_21 -> V_62 ) ;
} else {
struct V_56 V_63 = { 1 , V_21 -> V_62 } ;
F_16 ( & V_59 , & V_58 , & V_63 , V_64 ) ;
}
return 0 ;
}
