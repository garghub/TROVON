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
void F_7 ( struct V_19 * V_20 , struct V_19 * V_21 )
{
if ( V_21 )
V_21 -> V_22 . V_23 &= ~ ( V_24 | V_25 ) ;
if ( ! V_20 )
return;
V_20 -> V_22 . V_23 &= ~ ( V_24 | V_25 ) ;
if ( F_8 () )
V_20 -> V_22 . V_23 |= V_24 ;
if ( F_9 () )
V_20 -> V_22 . V_23 |= V_25 ;
}
int F_10 ( V_2 T_3 * V_26 , const T_4 * V_27 ,
bool V_28 )
{
int V_29 = 0 ;
F_1 () ;
if ( ! F_11 ( V_30 , V_26 , sizeof( V_2 ) ) )
return - V_31 ;
F_12 {
F_13 ( V_27 -> V_32 , & V_26 -> V_32 ) ;
F_13 ( V_27 -> V_33 , & V_26 -> V_33 ) ;
F_13 ( ( short ) V_27 -> V_34 , & V_26 -> V_34 ) ;
if ( V_27 -> V_34 < 0 ) {
F_13 ( V_27 -> V_35 , & V_26 -> V_35 ) ;
F_13 ( V_27 -> V_36 , & V_26 -> V_36 ) ;
F_13 ( F_14 ( V_27 -> V_37 ) , & V_26 -> V_37 ) ;
} else {
F_13 ( V_27 -> V_3 . V_38 [ 0 ] ,
& V_26 -> V_3 . V_38 [ 0 ] ) ;
switch ( V_27 -> V_34 >> 16 ) {
case V_39 >> 16 :
if ( V_27 -> V_32 == V_40 &&
( V_27 -> V_34 == V_41 ||
V_27 -> V_34 == V_42 ) )
F_13 ( V_27 -> V_43 , & V_26 -> V_43 ) ;
if ( V_27 -> V_32 == V_44 ) {
if ( V_27 -> V_34 == V_45 ) {
T_5 V_46 = ( unsigned long ) & V_26 -> V_47 ;
T_5 V_48 = ( unsigned long ) & V_26 -> V_49 ;
F_13 ( V_46 , & V_26 -> V_47 ) ;
F_13 ( V_48 , & V_26 -> V_49 ) ;
}
if ( V_27 -> V_34 == V_50 )
F_13 ( V_27 -> V_51 , & V_26 -> V_51 ) ;
}
break;
case V_52 >> 16 :
F_13 ( V_27 -> V_53 , & V_26 -> V_53 ) ;
F_13 ( V_27 -> V_54 , & V_26 -> V_54 ) ;
break;
case V_55 >> 16 :
if ( ! V_28 ) {
F_13 ( V_27 -> V_56 , & V_26 -> V_56 ) ;
F_13 ( V_27 -> V_57 , & V_26 -> V_57 ) ;
} else {
F_13 ( V_27 -> V_56 , & V_26 -> V_3 . V_15 . V_58 ) ;
F_13 ( V_27 -> V_57 , & V_26 -> V_3 . V_15 . V_59 ) ;
}
F_13 ( V_27 -> V_60 , & V_26 -> V_60 ) ;
default:
case V_61 >> 16 :
F_13 ( V_27 -> V_36 , & V_26 -> V_36 ) ;
break;
case V_62 >> 16 :
F_13 ( V_27 -> V_63 , & V_26 -> V_63 ) ;
break;
case V_64 >> 16 :
F_13 ( V_27 -> V_65 , & V_26 -> V_65 ) ;
F_13 ( F_14 ( V_27 -> V_37 ) ,
& V_26 -> V_37 ) ;
break;
case V_66 >> 16 :
case V_67 >> 16 :
F_13 ( V_27 -> V_36 , & V_26 -> V_36 ) ;
F_13 ( V_27 -> V_68 , & V_26 -> V_68 ) ;
break;
}
}
} F_15 ( V_29 ) ;
return V_29 ;
}
int F_16 ( V_2 T_3 * V_26 , const T_4 * V_27 )
{
return F_10 ( V_26 , V_27 , F_9 () ) ;
}
int F_17 ( T_4 * V_26 , V_2 T_3 * V_27 )
{
int V_29 = 0 ;
T_6 V_69 ;
if ( ! F_11 ( V_70 , V_27 , sizeof( V_2 ) ) )
return - V_31 ;
F_18 {
F_19 ( V_26 -> V_32 , & V_27 -> V_32 ) ;
F_19 ( V_26 -> V_33 , & V_27 -> V_33 ) ;
F_19 ( V_26 -> V_34 , & V_27 -> V_34 ) ;
F_19 ( V_26 -> V_35 , & V_27 -> V_35 ) ;
F_19 ( V_26 -> V_36 , & V_27 -> V_36 ) ;
F_19 ( V_69 , & V_27 -> V_37 ) ;
V_26 -> V_37 = F_20 ( V_69 ) ;
} F_21 ( V_29 ) ;
return V_29 ;
}
