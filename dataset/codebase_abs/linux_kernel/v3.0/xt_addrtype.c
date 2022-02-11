static T_1 F_1 ( struct V_1 * V_1 , const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
const struct V_6 * V_7 ;
struct V_8 V_9 ;
struct V_10 * V_11 ;
T_1 V_12 ;
int V_13 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
F_2 ( & V_9 . V_14 , V_5 ) ;
if ( V_3 )
V_9 . V_15 = V_3 -> V_16 ;
F_3 () ;
V_7 = F_4 ( V_17 ) ;
if ( V_7 != NULL )
V_13 = V_7 -> V_18 ( V_1 , (struct V_19 * * ) & V_11 ,
F_5 ( & V_9 ) , ! ! V_3 ) ;
else
V_13 = 1 ;
F_6 () ;
if ( V_13 )
return V_20 ;
if ( V_11 -> V_21 & V_22 )
V_12 = V_20 ;
else
V_12 = 0 ;
if ( V_11 -> V_21 & V_23 )
V_12 |= V_24 ;
if ( V_11 -> V_21 & V_25 )
V_12 |= V_26 ;
F_7 ( & V_11 -> V_27 ) ;
return V_12 ;
}
static bool F_8 ( struct V_1 * V_1 , const struct V_2 * V_3 ,
const struct V_4 * V_5 , T_2 V_28 )
{
int V_29 = F_9 ( V_5 ) ;
if ( ( V_28 & V_30 ) &&
! ( V_29 & V_31 ) )
return false ;
if ( ( V_28 & V_32 ) && ! ( V_29 & V_33 ) )
return false ;
if ( ( V_28 & V_34 ) && V_29 != V_35 )
return false ;
if ( ( V_24 | V_26 |
V_20 ) & V_28 )
return ! ! ( V_28 & F_1 ( V_1 , V_3 , V_5 ) ) ;
return true ;
}
static bool
F_10 ( struct V_1 * V_1 , const struct V_2 * V_3 ,
const struct V_36 * V_37 , const struct V_38 * V_39 )
{
const struct V_40 * V_41 = F_11 ( V_37 ) ;
bool V_12 = true ;
if ( V_39 -> V_42 )
V_12 &= F_8 ( V_1 , V_3 , & V_41 -> V_43 , V_39 -> V_42 ) ^
( V_39 -> V_44 & V_45 ) ;
if ( V_12 && V_39 -> V_46 )
V_12 &= F_8 ( V_1 , V_3 , & V_41 -> V_14 , V_39 -> V_46 ) ^
! ! ( V_39 -> V_44 & V_47 ) ;
return V_12 ;
}
static inline bool F_12 ( struct V_1 * V_1 , const struct V_2 * V_3 ,
T_3 V_5 , T_4 V_28 )
{
return ! ! ( V_28 & ( 1 << F_13 ( V_1 , V_3 , V_5 ) ) ) ;
}
static bool
F_14 ( const struct V_36 * V_37 , struct V_48 * V_49 )
{
struct V_1 * V_1 = F_15 ( V_49 -> V_50 ? V_49 -> V_50 : V_49 -> V_51 ) ;
const struct V_52 * V_39 = V_49 -> V_53 ;
const struct V_54 * V_41 = F_16 ( V_37 ) ;
bool V_12 = true ;
if ( V_39 -> V_42 )
V_12 &= F_12 ( V_1 , NULL , V_41 -> V_43 , V_39 -> V_42 ) ^
V_39 -> V_55 ;
if ( V_39 -> V_46 )
V_12 &= F_12 ( V_1 , NULL , V_41 -> V_14 , V_39 -> V_46 ) ^
V_39 -> V_56 ;
return V_12 ;
}
static bool
F_17 ( const struct V_36 * V_37 , struct V_48 * V_49 )
{
struct V_1 * V_1 = F_15 ( V_49 -> V_50 ? V_49 -> V_50 : V_49 -> V_51 ) ;
const struct V_38 * V_39 = V_49 -> V_53 ;
const struct V_54 * V_41 ;
const struct V_2 * V_3 = NULL ;
bool V_12 = true ;
if ( V_39 -> V_44 & V_57 )
V_3 = V_49 -> V_50 ;
else if ( V_39 -> V_44 & V_58 )
V_3 = V_49 -> V_51 ;
#if F_18 ( V_59 ) || F_18 ( V_60 )
if ( V_49 -> V_61 == V_17 )
return F_10 ( V_1 , V_3 , V_37 , V_39 ) ;
#endif
V_41 = F_16 ( V_37 ) ;
if ( V_39 -> V_42 )
V_12 &= F_12 ( V_1 , V_3 , V_41 -> V_43 , V_39 -> V_42 ) ^
( V_39 -> V_44 & V_45 ) ;
if ( V_12 && V_39 -> V_46 )
V_12 &= F_12 ( V_1 , V_3 , V_41 -> V_14 , V_39 -> V_46 ) ^
! ! ( V_39 -> V_44 & V_47 ) ;
return V_12 ;
}
static int F_19 ( const struct V_62 * V_49 )
{
struct V_38 * V_39 = V_49 -> V_53 ;
if ( V_39 -> V_44 & V_57 &&
V_39 -> V_44 & V_58 ) {
F_20 ( L_1
L_2 ) ;
return - V_63 ;
}
if ( V_49 -> V_64 & ( ( 1 << V_65 ) |
( 1 << V_66 ) ) &&
V_39 -> V_44 & V_58 ) {
F_20 ( L_3
L_4 ) ;
return - V_63 ;
}
if ( V_49 -> V_64 & ( ( 1 << V_67 ) |
( 1 << V_68 ) ) &&
V_39 -> V_44 & V_57 ) {
F_20 ( L_5
L_6 ) ;
return - V_63 ;
}
#if F_18 ( V_59 ) || F_18 ( V_60 )
if ( V_49 -> V_61 == V_17 ) {
if ( ( V_39 -> V_42 | V_39 -> V_46 ) & V_69 ) {
F_21 ( L_7 ) ;
return - V_63 ;
}
if ( ( V_39 -> V_42 | V_39 -> V_46 ) >= V_70 ) {
F_21 ( L_8 ) ;
return - V_63 ;
}
if ( ( V_39 -> V_42 | V_39 -> V_46 ) & V_71 ) {
F_21 ( L_9 ) ;
return - V_63 ;
}
}
#endif
return 0 ;
}
static int T_5 F_22 ( void )
{
return F_23 ( V_72 ,
F_24 ( V_72 ) ) ;
}
static void T_6 F_25 ( void )
{
F_26 ( V_72 , F_24 ( V_72 ) ) ;
}
