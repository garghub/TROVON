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
if ( V_12 -> V_26 & V_29 )
V_13 |= V_30 ;
F_7 ( & V_12 -> V_31 ) ;
return V_13 ;
}
static bool F_8 ( struct V_1 * V_1 , const struct V_2 * V_3 ,
const struct V_4 * V_5 , T_2 V_6 )
{
int V_32 = F_9 ( V_5 ) ;
if ( ( V_6 & V_33 ) &&
! ( V_32 & V_34 ) )
return false ;
if ( ( V_6 & V_35 ) && ! ( V_32 & V_36 ) )
return false ;
if ( ( V_6 & V_37 ) && V_32 != V_38 )
return false ;
if ( ( V_21 | V_30 |
V_25 ) & V_6 )
return ! ! ( V_6 & F_1 ( V_1 , V_3 , V_5 , V_6 ) ) ;
return true ;
}
static bool
F_10 ( struct V_1 * V_1 , const struct V_2 * V_3 ,
const struct V_39 * V_40 , const struct V_41 * V_42 )
{
const struct V_43 * V_44 = F_11 ( V_40 ) ;
bool V_13 = true ;
if ( V_42 -> V_45 )
V_13 &= F_8 ( V_1 , V_3 , & V_44 -> V_46 , V_42 -> V_45 ) ^
( V_42 -> V_47 & V_48 ) ;
if ( V_13 && V_42 -> V_49 )
V_13 &= F_8 ( V_1 , V_3 , & V_44 -> V_15 , V_42 -> V_49 ) ^
! ! ( V_42 -> V_47 & V_50 ) ;
return V_13 ;
}
static inline bool F_12 ( struct V_1 * V_1 , const struct V_2 * V_3 ,
T_3 V_5 , T_4 V_6 )
{
return ! ! ( V_6 & ( 1 << F_13 ( V_1 , V_3 , V_5 ) ) ) ;
}
static bool
F_14 ( const struct V_39 * V_40 , struct V_51 * V_52 )
{
struct V_1 * V_1 = F_15 ( V_52 -> V_53 ? V_52 -> V_53 : V_52 -> V_54 ) ;
const struct V_55 * V_42 = V_52 -> V_56 ;
const struct V_57 * V_44 = F_16 ( V_40 ) ;
bool V_13 = true ;
if ( V_42 -> V_45 )
V_13 &= F_12 ( V_1 , NULL , V_44 -> V_46 , V_42 -> V_45 ) ^
V_42 -> V_58 ;
if ( V_42 -> V_49 )
V_13 &= F_12 ( V_1 , NULL , V_44 -> V_15 , V_42 -> V_49 ) ^
V_42 -> V_59 ;
return V_13 ;
}
static bool
F_17 ( const struct V_39 * V_40 , struct V_51 * V_52 )
{
struct V_1 * V_1 = F_15 ( V_52 -> V_53 ? V_52 -> V_53 : V_52 -> V_54 ) ;
const struct V_41 * V_42 = V_52 -> V_56 ;
const struct V_57 * V_44 ;
const struct V_2 * V_3 = NULL ;
bool V_13 = true ;
if ( V_42 -> V_47 & V_60 )
V_3 = V_52 -> V_53 ;
else if ( V_42 -> V_47 & V_61 )
V_3 = V_52 -> V_54 ;
#if F_18 ( V_62 )
if ( V_52 -> V_63 == V_18 )
return F_10 ( V_1 , V_3 , V_40 , V_42 ) ;
#endif
V_44 = F_16 ( V_40 ) ;
if ( V_42 -> V_45 )
V_13 &= F_12 ( V_1 , V_3 , V_44 -> V_46 , V_42 -> V_45 ) ^
( V_42 -> V_47 & V_48 ) ;
if ( V_13 && V_42 -> V_49 )
V_13 &= F_12 ( V_1 , V_3 , V_44 -> V_15 , V_42 -> V_49 ) ^
! ! ( V_42 -> V_47 & V_50 ) ;
return V_13 ;
}
static int F_19 ( const struct V_64 * V_52 )
{
struct V_41 * V_42 = V_52 -> V_56 ;
if ( V_42 -> V_47 & V_60 &&
V_42 -> V_47 & V_61 ) {
F_20 ( L_1
L_2 ) ;
return - V_65 ;
}
if ( V_52 -> V_66 & ( ( 1 << V_67 ) |
( 1 << V_68 ) ) &&
V_42 -> V_47 & V_61 ) {
F_20 ( L_3
L_4 ) ;
return - V_65 ;
}
if ( V_52 -> V_66 & ( ( 1 << V_69 ) |
( 1 << V_70 ) ) &&
V_42 -> V_47 & V_60 ) {
F_20 ( L_5
L_6 ) ;
return - V_65 ;
}
#if F_18 ( V_62 )
if ( V_52 -> V_63 == V_18 ) {
if ( ( V_42 -> V_45 | V_42 -> V_49 ) & V_71 ) {
F_21 ( L_7 ) ;
return - V_65 ;
}
if ( ( V_42 -> V_45 | V_42 -> V_49 ) >= V_72 ) {
F_21 ( L_8 ) ;
return - V_65 ;
}
if ( ( V_42 -> V_45 | V_42 -> V_49 ) & V_73 ) {
F_21 ( L_9 ) ;
return - V_65 ;
}
}
#endif
return 0 ;
}
static int T_5 F_22 ( void )
{
return F_23 ( V_74 ,
F_24 ( V_74 ) ) ;
}
static void T_6 F_25 ( void )
{
F_26 ( V_74 , F_24 ( V_74 ) ) ;
}
