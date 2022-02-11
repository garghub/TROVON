static inline void F_1 ( void )
{
int V_1 = F_2 ( V_2 , V_3 ) ;
F_3 ( V_4 != 8 ) ;
F_3 ( V_5 != 8 ) ;
F_3 ( V_6 != 4 ) ;
F_3 ( V_7 != 5 ) ;
F_3 ( V_8 != 4 ) ;
F_3 ( V_9 != 6 ) ;
F_3 ( V_10 != 1 ) ;
F_3 ( sizeof( V_2 ) != 128 ) ;
F_3 ( F_2 ( V_2 , V_3 ) != 3 * sizeof( int ) ) ;
#define F_4 ( T_1 ) BUILD_BUG_ON(_sifields_offset != offsetof(compat_siginfo_t, _sifields.name))
#define F_5 ( T_1 , T_2 ) BUILD_BUG_ON(size != sizeof(((compat_siginfo_t *)0)->_sifields.name))
#define F_6 ( T_1 , T_2 ) BUILD_BUG_ON(size != sizeof(((siginfo_t *)0)->_sifields.name))
F_4 ( V_11 ) ;
F_5 ( V_11 , 2 * sizeof( int ) ) ;
F_6 ( V_11 , 2 * sizeof( int ) ) ;
F_4 ( V_12 ) ;
F_5 ( V_12 , 5 * sizeof( int ) ) ;
F_6 ( V_12 , 6 * sizeof( int ) ) ;
F_4 ( V_13 ) ;
F_5 ( V_13 , 3 * sizeof( int ) ) ;
F_6 ( V_13 , 4 * sizeof( int ) ) ;
F_4 ( V_14 ) ;
F_5 ( V_14 , 5 * sizeof( int ) ) ;
F_6 ( V_14 , 8 * sizeof( int ) ) ;
F_4 ( V_15 ) ;
F_5 ( V_15 , 7 * sizeof( int ) ) ;
F_4 ( V_16 ) ;
F_5 ( V_16 , 4 * sizeof( int ) ) ;
F_6 ( V_16 , 8 * sizeof( int ) ) ;
F_4 ( V_17 ) ;
F_5 ( V_17 , 2 * sizeof( int ) ) ;
F_6 ( V_17 , 4 * sizeof( int ) ) ;
F_4 ( V_18 ) ;
F_5 ( V_18 , 3 * sizeof( int ) ) ;
F_6 ( V_18 , 4 * sizeof( int ) ) ;
}
int F_7 ( V_2 T_3 * V_19 , const T_4 * V_20 )
{
int V_21 = 0 ;
bool V_22 = F_8 ( V_23 ) ;
F_1 () ;
if ( ! F_9 ( V_24 , V_19 , sizeof( V_2 ) ) )
return - V_25 ;
F_10 {
F_11 ( V_20 -> V_26 , & V_19 -> V_26 ) ;
F_11 ( V_20 -> V_27 , & V_19 -> V_27 ) ;
F_11 ( ( short ) V_20 -> V_28 , & V_19 -> V_28 ) ;
if ( V_20 -> V_28 < 0 ) {
F_11 ( V_20 -> V_29 , & V_19 -> V_29 ) ;
F_11 ( V_20 -> V_30 , & V_19 -> V_30 ) ;
F_11 ( F_12 ( V_20 -> V_31 ) , & V_19 -> V_31 ) ;
} else {
F_11 ( V_20 -> V_3 . V_32 [ 0 ] ,
& V_19 -> V_3 . V_32 [ 0 ] ) ;
switch ( V_20 -> V_28 >> 16 ) {
case V_33 >> 16 :
if ( V_20 -> V_26 == V_34 &&
( V_20 -> V_28 == V_35 ||
V_20 -> V_28 == V_36 ) )
F_11 ( V_20 -> V_37 , & V_19 -> V_37 ) ;
if ( V_20 -> V_26 == V_38 ) {
if ( V_20 -> V_28 == V_39 ) {
T_5 V_40 = ( unsigned long ) & V_19 -> V_41 ;
T_5 V_42 = ( unsigned long ) & V_19 -> V_43 ;
F_11 ( V_40 , & V_19 -> V_41 ) ;
F_11 ( V_42 , & V_19 -> V_43 ) ;
}
if ( V_20 -> V_28 == V_44 )
F_11 ( V_20 -> V_45 , & V_19 -> V_45 ) ;
}
break;
case V_46 >> 16 :
F_11 ( V_20 -> V_47 , & V_19 -> V_47 ) ;
F_11 ( V_20 -> V_48 , & V_19 -> V_48 ) ;
break;
case V_49 >> 16 :
if ( V_22 ) {
F_11 ( V_20 -> V_50 , & V_19 -> V_50 ) ;
F_11 ( V_20 -> V_51 , & V_19 -> V_51 ) ;
} else {
F_11 ( V_20 -> V_50 , & V_19 -> V_3 . V_15 . V_52 ) ;
F_11 ( V_20 -> V_51 , & V_19 -> V_3 . V_15 . V_53 ) ;
}
F_11 ( V_20 -> V_54 , & V_19 -> V_54 ) ;
default:
case V_55 >> 16 :
F_11 ( V_20 -> V_30 , & V_19 -> V_30 ) ;
break;
case V_56 >> 16 :
F_11 ( V_20 -> V_57 , & V_19 -> V_57 ) ;
break;
case V_58 >> 16 :
F_11 ( V_20 -> V_59 , & V_19 -> V_59 ) ;
F_11 ( F_12 ( V_20 -> V_31 ) ,
& V_19 -> V_31 ) ;
break;
case V_60 >> 16 :
case V_61 >> 16 :
F_11 ( V_20 -> V_30 , & V_19 -> V_30 ) ;
F_11 ( V_20 -> V_62 , & V_19 -> V_62 ) ;
break;
}
}
} F_13 ( V_21 ) ;
return V_21 ;
}
int F_14 ( T_4 * V_19 , V_2 T_3 * V_20 )
{
int V_21 = 0 ;
T_6 V_63 ;
if ( ! F_9 ( V_64 , V_20 , sizeof( V_2 ) ) )
return - V_25 ;
F_15 {
F_16 ( V_19 -> V_26 , & V_20 -> V_26 ) ;
F_16 ( V_19 -> V_27 , & V_20 -> V_27 ) ;
F_16 ( V_19 -> V_28 , & V_20 -> V_28 ) ;
F_16 ( V_19 -> V_29 , & V_20 -> V_29 ) ;
F_16 ( V_19 -> V_30 , & V_20 -> V_30 ) ;
F_16 ( V_63 , & V_20 -> V_31 ) ;
V_19 -> V_31 = F_17 ( V_63 ) ;
} F_18 ( V_21 ) ;
return V_21 ;
}
