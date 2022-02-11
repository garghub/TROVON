static inline unsigned
F_1 ( unsigned V_1 )
{
return F_2 ( V_1 , 8 ) ;
}
static enum V_2
F_3 ( enum V_3 V_4 )
{
switch ( V_4 ) {
case V_5 :
return V_6 ;
case V_7 :
case V_8 :
case V_9 :
return V_10 ;
case V_11 :
case V_12 :
case V_13 :
return V_14 ;
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
return V_20 ;
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
return V_28 ;
case V_29 :
default:
return V_28 ;
}
}
void
F_4 (
struct V_30 * V_31 ,
const struct V_32 * V_4 ,
unsigned V_33 )
{
unsigned V_34 = V_35 ;
const struct V_36 * V_37 = V_4 -> V_37 ;
const struct V_36 * V_38 = V_4 -> V_38 ;
( void ) V_33 ;
#if ! F_5 ( V_39 )
V_37 = V_38 ;
#else
if ( V_37 )
( void ) V_38 ;
else
V_37 = V_38 ;
#endif
F_6 ( & V_31 -> V_40 , V_37 ) ;
assert ( ( V_37 -> V_41 == V_42 ) ||
( V_34 % V_31 -> V_40 . V_43 == 0 ) ) ;
V_31 -> V_44 = V_34 / V_31 -> V_40 . V_43 ;
V_31 -> V_45 = V_4 -> V_46 -> V_45 ;
V_31 -> V_41 = V_37 -> V_41 ;
V_31 -> V_47 = V_4 -> V_46 -> V_47 ;
V_31 -> V_48 = V_4 -> V_48 ;
V_31 -> V_49 = F_3 ( V_4 -> V_49 ) ;
V_31 -> V_50 = V_4 -> V_50 ;
#if ( F_5 ( V_39 ) || F_5 ( V_51 ) )
V_31 -> V_52 = V_37 -> V_53 . V_52 ;
V_31 -> V_54 = V_37 -> V_53 . V_54 ;
V_31 -> V_55 = V_4 -> V_55 ;
#endif
}
void
F_7 (
const struct V_56 * V_46 ,
const struct V_57 * V_58 ,
const struct V_36 * V_37 ,
const struct V_36 * V_38 ,
bool V_48 ,
bool V_50 )
{
T_1 V_55 = ( T_1 ) ( ( V_58 -> V_59 ) ? 1 : 0 ) ;
struct V_32 V_60 = V_61 ;
V_60 . V_46 = V_46 ;
V_60 . V_37 = V_37 ;
V_60 . V_38 = V_38 ;
V_60 . V_48 = V_48 ;
V_60 . V_49 = V_58 -> V_62 ;
V_60 . V_50 = V_50 ;
V_60 . V_55 = V_55 ;
F_8 ( V_58 , & V_60 ) ;
}
