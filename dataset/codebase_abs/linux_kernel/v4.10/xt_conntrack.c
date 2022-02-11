static bool
F_1 ( const union V_1 * V_2 ,
const union V_1 * V_3 ,
const union V_1 * V_4 , unsigned int V_5 )
{
if ( V_5 == V_6 )
return ( ( V_2 -> V_7 ^ V_3 -> V_7 ) & V_4 -> V_7 ) == 0 ;
else if ( V_5 == V_8 )
return F_2 ( & V_2 -> V_9 , & V_4 -> V_9 ,
& V_3 -> V_9 ) == 0 ;
else
return false ;
}
static inline bool
F_3 ( const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
T_1 V_14 )
{
return F_1 ( & V_11 -> V_15 [ V_16 ] . V_17 . V_18 . V_19 ,
& V_13 -> V_20 , & V_13 -> V_21 , V_14 ) ;
}
static inline bool
F_4 ( const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
T_1 V_14 )
{
return F_1 ( & V_11 -> V_15 [ V_16 ] . V_17 . V_22 . V_19 ,
& V_13 -> V_23 , & V_13 -> V_24 , V_14 ) ;
}
static inline bool
F_5 ( const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
T_1 V_14 )
{
return F_1 ( & V_11 -> V_15 [ V_25 ] . V_17 . V_18 . V_19 ,
& V_13 -> V_26 , & V_13 -> V_27 , V_14 ) ;
}
static inline bool
F_6 ( const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
T_1 V_14 )
{
return F_1 ( & V_11 -> V_15 [ V_25 ] . V_17 . V_22 . V_19 ,
& V_13 -> V_28 , & V_13 -> V_29 , V_14 ) ;
}
static inline bool
F_7 ( const struct V_12 * V_13 ,
const struct V_10 * V_11 )
{
const struct V_30 * V_17 ;
V_17 = & V_11 -> V_15 [ V_16 ] . V_17 ;
if ( ( V_13 -> V_31 & V_32 ) &&
( F_8 ( V_11 ) == V_13 -> V_33 ) ^
! ( V_13 -> V_34 & V_32 ) )
return false ;
if ( ( V_13 -> V_31 & V_35 ) &&
( V_17 -> V_18 . V_36 . V_37 == V_13 -> V_38 ) ^
! ( V_13 -> V_34 & V_35 ) )
return false ;
if ( ( V_13 -> V_31 & V_39 ) &&
( V_17 -> V_22 . V_36 . V_37 == V_13 -> V_40 ) ^
! ( V_13 -> V_34 & V_39 ) )
return false ;
V_17 = & V_11 -> V_15 [ V_25 ] . V_17 ;
if ( ( V_13 -> V_31 & V_41 ) &&
( V_17 -> V_18 . V_36 . V_37 == V_13 -> V_42 ) ^
! ( V_13 -> V_34 & V_41 ) )
return false ;
if ( ( V_13 -> V_31 & V_43 ) &&
( V_17 -> V_22 . V_36 . V_37 == V_13 -> V_44 ) ^
! ( V_13 -> V_34 & V_43 ) )
return false ;
return true ;
}
static inline bool
F_9 ( T_2 V_45 , T_2 V_46 , T_2 V_47 , bool V_48 )
{
return ( V_47 >= V_45 && V_47 <= V_46 ) ^ V_48 ;
}
static inline bool
F_10 ( const struct V_49 * V_13 ,
const struct V_10 * V_11 )
{
const struct V_30 * V_17 ;
V_17 = & V_11 -> V_15 [ V_16 ] . V_17 ;
if ( ( V_13 -> V_31 & V_32 ) &&
( F_8 ( V_11 ) == V_13 -> V_33 ) ^
! ( V_13 -> V_34 & V_32 ) )
return false ;
if ( ( V_13 -> V_31 & V_35 ) &&
! F_9 ( V_13 -> V_38 , V_13 -> V_50 ,
F_11 ( V_17 -> V_18 . V_36 . V_37 ) ,
V_13 -> V_34 & V_35 ) )
return false ;
if ( ( V_13 -> V_31 & V_39 ) &&
! F_9 ( V_13 -> V_40 , V_13 -> V_51 ,
F_11 ( V_17 -> V_22 . V_36 . V_37 ) ,
V_13 -> V_34 & V_39 ) )
return false ;
V_17 = & V_11 -> V_15 [ V_25 ] . V_17 ;
if ( ( V_13 -> V_31 & V_41 ) &&
! F_9 ( V_13 -> V_42 , V_13 -> V_52 ,
F_11 ( V_17 -> V_18 . V_36 . V_37 ) ,
V_13 -> V_34 & V_41 ) )
return false ;
if ( ( V_13 -> V_31 & V_43 ) &&
! F_9 ( V_13 -> V_44 , V_13 -> V_53 ,
F_11 ( V_17 -> V_22 . V_36 . V_37 ) ,
V_13 -> V_34 & V_43 ) )
return false ;
return true ;
}
static bool
F_12 ( const struct V_54 * V_55 , struct V_56 * V_57 ,
T_2 V_58 , T_2 V_59 )
{
const struct V_12 * V_13 = V_57 -> V_60 ;
enum V_61 V_62 ;
const struct V_10 * V_11 ;
unsigned int V_63 ;
V_11 = F_13 ( V_55 , & V_62 ) ;
if ( V_11 ) {
if ( F_14 ( V_11 ) )
V_63 = V_64 ;
else
V_63 = F_15 ( V_62 ) ;
} else
V_63 = V_65 ;
if ( V_13 -> V_31 & V_66 ) {
if ( V_11 != NULL ) {
if ( F_16 ( V_67 , & V_11 -> V_68 ) )
V_63 |= V_69 ;
if ( F_16 ( V_70 , & V_11 -> V_68 ) )
V_63 |= V_71 ;
}
if ( ! ! ( V_58 & V_63 ) ^
! ( V_13 -> V_34 & V_66 ) )
return false ;
}
if ( V_11 == NULL )
return V_13 -> V_31 & V_66 ;
if ( ( V_13 -> V_31 & V_72 ) &&
( F_17 ( V_62 ) == V_16 ) ^
! ( V_13 -> V_34 & V_72 ) )
return false ;
if ( V_13 -> V_31 & V_73 )
if ( F_3 ( V_11 , V_13 , F_18 ( V_57 ) ) ^
! ( V_13 -> V_34 & V_73 ) )
return false ;
if ( V_13 -> V_31 & V_74 )
if ( F_4 ( V_11 , V_13 , F_18 ( V_57 ) ) ^
! ( V_13 -> V_34 & V_74 ) )
return false ;
if ( V_13 -> V_31 & V_75 )
if ( F_5 ( V_11 , V_13 , F_18 ( V_57 ) ) ^
! ( V_13 -> V_34 & V_75 ) )
return false ;
if ( V_13 -> V_31 & V_76 )
if ( F_6 ( V_11 , V_13 , F_18 ( V_57 ) ) ^
! ( V_13 -> V_34 & V_76 ) )
return false ;
if ( V_57 -> V_77 -> V_78 != 3 ) {
if ( ! F_7 ( V_13 , V_11 ) )
return false ;
} else {
if ( ! F_10 ( V_57 -> V_60 , V_11 ) )
return false ;
}
if ( ( V_13 -> V_31 & V_79 ) &&
( ! ! ( V_59 & V_11 -> V_68 ) ^
! ( V_13 -> V_34 & V_79 ) ) )
return false ;
if ( V_13 -> V_31 & V_80 ) {
unsigned long V_81 = F_19 ( V_11 ) / V_82 ;
if ( ( V_81 >= V_13 -> V_83 &&
V_81 <= V_13 -> V_84 ) ^
! ( V_13 -> V_34 & V_80 ) )
return false ;
}
return true ;
}
static bool
F_20 ( const struct V_54 * V_55 , struct V_56 * V_57 )
{
const struct V_85 * V_13 = V_57 -> V_60 ;
return F_12 ( V_55 , V_57 , V_13 -> V_58 , V_13 -> V_59 ) ;
}
static bool
F_21 ( const struct V_54 * V_55 , struct V_56 * V_57 )
{
const struct V_12 * V_13 = V_57 -> V_60 ;
return F_12 ( V_55 , V_57 , V_13 -> V_58 , V_13 -> V_59 ) ;
}
static bool
F_22 ( const struct V_54 * V_55 , struct V_56 * V_57 )
{
const struct V_49 * V_13 = V_57 -> V_60 ;
return F_12 ( V_55 , V_57 , V_13 -> V_58 , V_13 -> V_59 ) ;
}
static int F_23 ( const struct V_86 * V_57 )
{
int V_87 ;
V_87 = F_24 ( V_57 -> V_88 , V_57 -> V_14 ) ;
if ( V_87 < 0 )
F_25 ( L_1 ,
V_57 -> V_14 ) ;
return V_87 ;
}
static void F_26 ( const struct V_89 * V_57 )
{
F_27 ( V_57 -> V_88 , V_57 -> V_14 ) ;
}
static int T_3 F_28 ( void )
{
return F_29 ( V_90 ,
F_30 ( V_90 ) ) ;
}
static void T_4 F_31 ( void )
{
F_32 ( V_90 , F_30 ( V_90 ) ) ;
}
