static T_1 F_1 ( struct V_1 * V_1 , const struct V_2 * V_3 ,
const struct V_4 * V_5 , T_2 V_6 )
{
const struct V_7 * V_8 ;
struct V_9 V_10 ;
struct V_11 * V_12 ;
T_1 V_13 = 0 ;
int V_14 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . V_15 = * V_5 ;
if ( V_3 )
V_10 . V_16 = V_3 -> V_17 ;
F_2 () ;
V_8 = F_3 ( V_18 ) ;
if ( V_8 != NULL ) {
const struct V_19 * V_20 ;
if ( V_3 && ( V_6 & V_21 ) ) {
V_20 = F_4 () ;
if ( V_20 && V_20 -> V_22 ( V_1 , V_5 , V_3 , true ) )
V_13 = V_21 ;
}
V_14 = V_8 -> V_23 ( V_1 , (struct V_24 * * ) & V_12 ,
F_5 ( & V_10 ) , false ) ;
} else {
V_14 = 1 ;
}
F_6 () ;
if ( V_14 )
return V_25 ;
if ( V_12 -> V_26 & V_27 )
V_13 = V_25 ;
if ( V_3 == NULL && V_12 -> V_26 & V_28 )
V_13 |= V_21 ;
if ( F_7 ( (struct V_24 * ) V_12 , V_5 ) )
V_13 |= V_29 ;
F_8 ( & V_12 -> V_30 ) ;
return V_13 ;
}
static bool F_9 ( struct V_1 * V_1 , const struct V_2 * V_3 ,
const struct V_4 * V_5 , T_2 V_6 )
{
int V_31 = F_10 ( V_5 ) ;
if ( ( V_6 & V_32 ) &&
! ( V_31 & V_33 ) )
return false ;
if ( ( V_6 & V_34 ) && ! ( V_31 & V_35 ) )
return false ;
if ( ( V_6 & V_36 ) && V_31 != V_37 )
return false ;
if ( ( V_21 | V_29 |
V_25 ) & V_6 )
return ! ! ( V_6 & F_1 ( V_1 , V_3 , V_5 , V_6 ) ) ;
return true ;
}
static bool
F_11 ( struct V_1 * V_1 , const struct V_2 * V_3 ,
const struct V_38 * V_39 , const struct V_40 * V_41 )
{
const struct V_42 * V_43 = F_12 ( V_39 ) ;
bool V_13 = true ;
if ( V_41 -> V_44 )
V_13 &= F_9 ( V_1 , V_3 , & V_43 -> V_45 , V_41 -> V_44 ) ^
( V_41 -> V_46 & V_47 ) ;
if ( V_13 && V_41 -> V_48 )
V_13 &= F_9 ( V_1 , V_3 , & V_43 -> V_15 , V_41 -> V_48 ) ^
! ! ( V_41 -> V_46 & V_49 ) ;
return V_13 ;
}
static inline bool F_13 ( struct V_1 * V_1 , const struct V_2 * V_3 ,
T_3 V_5 , T_4 V_6 )
{
return ! ! ( V_6 & ( 1 << F_14 ( V_1 , V_3 , V_5 ) ) ) ;
}
static bool
F_15 ( const struct V_38 * V_39 , struct V_50 * V_51 )
{
struct V_1 * V_1 = F_16 ( V_51 ) ;
const struct V_52 * V_41 = V_51 -> V_53 ;
const struct V_54 * V_43 = F_17 ( V_39 ) ;
bool V_13 = true ;
if ( V_41 -> V_44 )
V_13 &= F_13 ( V_1 , NULL , V_43 -> V_45 , V_41 -> V_44 ) ^
V_41 -> V_55 ;
if ( V_41 -> V_48 )
V_13 &= F_13 ( V_1 , NULL , V_43 -> V_15 , V_41 -> V_48 ) ^
V_41 -> V_56 ;
return V_13 ;
}
static bool
F_18 ( const struct V_38 * V_39 , struct V_50 * V_51 )
{
struct V_1 * V_1 = F_16 ( V_51 ) ;
const struct V_40 * V_41 = V_51 -> V_53 ;
const struct V_54 * V_43 ;
const struct V_2 * V_3 = NULL ;
bool V_13 = true ;
if ( V_41 -> V_46 & V_57 )
V_3 = F_19 ( V_51 ) ;
else if ( V_41 -> V_46 & V_58 )
V_3 = F_20 ( V_51 ) ;
#if F_21 ( V_59 )
if ( F_22 ( V_51 ) == V_18 )
return F_11 ( V_1 , V_3 , V_39 , V_41 ) ;
#endif
V_43 = F_17 ( V_39 ) ;
if ( V_41 -> V_44 )
V_13 &= F_13 ( V_1 , V_3 , V_43 -> V_45 , V_41 -> V_44 ) ^
( V_41 -> V_46 & V_47 ) ;
if ( V_13 && V_41 -> V_48 )
V_13 &= F_13 ( V_1 , V_3 , V_43 -> V_15 , V_41 -> V_48 ) ^
! ! ( V_41 -> V_46 & V_49 ) ;
return V_13 ;
}
static int F_23 ( const struct V_60 * V_51 )
{
struct V_40 * V_41 = V_51 -> V_53 ;
if ( V_41 -> V_46 & V_57 &&
V_41 -> V_46 & V_58 ) {
F_24 ( L_1
L_2 ) ;
return - V_61 ;
}
if ( V_51 -> V_62 & ( ( 1 << V_63 ) |
( 1 << V_64 ) ) &&
V_41 -> V_46 & V_58 ) {
F_24 ( L_3
L_4 ) ;
return - V_61 ;
}
if ( V_51 -> V_62 & ( ( 1 << V_65 ) |
( 1 << V_66 ) ) &&
V_41 -> V_46 & V_57 ) {
F_24 ( L_5
L_6 ) ;
return - V_61 ;
}
#if F_21 ( V_59 )
if ( V_51 -> V_67 == V_18 ) {
if ( ( V_41 -> V_44 | V_41 -> V_48 ) & V_68 ) {
F_25 ( L_7 ) ;
return - V_61 ;
}
if ( ( V_41 -> V_44 | V_41 -> V_48 ) >= V_69 ) {
F_25 ( L_8 ) ;
return - V_61 ;
}
if ( ( V_41 -> V_44 | V_41 -> V_48 ) & V_70 ) {
F_25 ( L_9 ) ;
return - V_61 ;
}
}
#endif
return 0 ;
}
static int T_5 F_26 ( void )
{
return F_27 ( V_71 ,
F_28 ( V_71 ) ) ;
}
static void T_6 F_29 ( void )
{
F_30 ( V_71 , F_28 ( V_71 ) ) ;
}
