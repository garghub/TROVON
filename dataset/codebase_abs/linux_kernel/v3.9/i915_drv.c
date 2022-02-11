void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 ;
V_7 = F_2 ( V_8 << 8 , NULL ) ;
if ( V_7 ) {
if ( V_7 -> V_9 == V_10 ) {
unsigned short V_11 ;
V_11 = V_7 -> V_12 & V_13 ;
V_4 -> V_14 = V_11 ;
if ( V_11 == V_15 ) {
V_4 -> V_16 = V_17 ;
V_4 -> V_18 = 2 ;
F_3 ( L_1 ) ;
F_4 ( ! F_5 ( V_2 ) ) ;
} else if ( V_11 == V_19 ) {
V_4 -> V_16 = V_20 ;
V_4 -> V_18 = 2 ;
F_3 ( L_2 ) ;
F_4 ( ! ( F_6 ( V_2 ) || F_7 ( V_2 ) ) ) ;
} else if ( V_11 == V_21 ) {
V_4 -> V_16 = V_20 ;
V_4 -> V_18 = 2 ;
F_3 ( L_3 ) ;
F_4 ( ! ( F_6 ( V_2 ) || F_7 ( V_2 ) ) ) ;
} else if ( V_11 == V_22 ) {
V_4 -> V_16 = V_23 ;
V_4 -> V_18 = 0 ;
F_3 ( L_4 ) ;
F_4 ( ! F_8 ( V_2 ) ) ;
} else if ( V_11 == V_24 ) {
V_4 -> V_16 = V_23 ;
V_4 -> V_18 = 0 ;
F_3 ( L_5 ) ;
F_4 ( ! F_8 ( V_2 ) ) ;
}
F_9 ( V_4 -> V_18 > V_25 ) ;
}
F_10 ( V_7 ) ;
}
}
bool F_11 ( struct V_1 * V_2 )
{
if ( F_12 ( V_2 ) -> V_26 < 6 )
return 0 ;
if ( V_27 >= 0 )
return V_27 ;
#ifdef F_13
if ( F_12 ( V_2 ) -> V_26 == 6 && V_28 )
return false ;
#endif
return 1 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_15 ( & V_4 -> V_29 ) ;
V_4 -> V_30 = V_31 ;
F_16 ( & V_4 -> V_29 ) ;
F_17 ( V_2 , true ) ;
F_18 ( V_2 ) ;
F_19 ( V_2 -> V_32 ) ;
if ( F_20 ( V_2 , V_33 ) ) {
int error = F_21 ( V_2 ) ;
if ( error ) {
F_22 ( & V_2 -> V_32 -> V_2 ,
L_6 ) ;
return error ;
}
F_23 ( & V_4 -> V_34 . V_35 ) ;
F_24 ( V_2 ) ;
F_25 ( V_2 ) ;
V_4 -> V_36 = false ;
}
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
F_28 () ;
F_29 ( V_2 , 1 ) ;
F_30 () ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 , T_1 V_37 )
{
int error ;
if ( ! V_2 || ! V_2 -> V_5 ) {
F_32 ( L_7 , V_2 ) ;
F_32 ( L_8 ) ;
return - V_38 ;
}
if ( V_37 . V_39 == V_40 )
return 0 ;
if ( V_2 -> V_41 == V_42 )
return 0 ;
error = F_14 ( V_2 ) ;
if ( error )
return error ;
if ( V_37 . V_39 == V_43 ) {
F_33 ( V_2 -> V_32 ) ;
F_34 ( V_2 -> V_32 , V_44 ) ;
}
return 0 ;
}
void F_35 ( struct V_45 * V_46 )
{
struct V_3 * V_4 =
F_36 ( V_46 , struct V_3 ,
V_47 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_28 () ;
F_29 ( V_2 , 0 ) ;
F_30 () ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int error = 0 ;
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
if ( F_20 ( V_2 , V_33 ) ) {
F_40 ( V_2 ) ;
F_15 ( & V_2 -> V_48 ) ;
V_4 -> V_49 . V_50 = 0 ;
error = F_41 ( V_2 ) ;
F_16 ( & V_2 -> V_48 ) ;
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
F_44 ( V_2 , false ) ;
F_45 ( V_2 ) ;
V_4 -> V_36 = true ;
}
F_46 ( V_2 ) ;
if ( F_47 () ) {
F_29 ( V_2 , 0 ) ;
F_30 () ;
} else {
F_48 ( & V_4 -> V_47 ) ;
}
F_15 ( & V_4 -> V_29 ) ;
V_4 -> V_30 = V_51 ;
F_16 ( & V_4 -> V_29 ) ;
return error ;
}
static int F_49 ( struct V_1 * V_2 )
{
int error = 0 ;
F_50 ( V_2 ) ;
if ( F_20 ( V_2 , V_33 ) ) {
F_15 ( & V_2 -> V_48 ) ;
F_51 ( V_2 ) ;
F_16 ( & V_2 -> V_48 ) ;
}
F_37 ( V_2 ) ;
return error ;
}
int F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_52 ;
if ( V_2 -> V_41 == V_42 )
return 0 ;
if ( F_53 ( V_2 -> V_32 ) )
return - V_53 ;
F_54 ( V_2 -> V_32 ) ;
F_50 ( V_2 ) ;
if ( F_20 ( V_2 , V_33 ) &&
! V_4 -> V_54 . V_55 ) {
F_15 ( & V_2 -> V_48 ) ;
F_51 ( V_2 ) ;
F_16 ( & V_2 -> V_48 ) ;
}
V_52 = F_37 ( V_2 ) ;
if ( V_52 )
return V_52 ;
F_55 ( V_2 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_57 ( V_2 ) )
return - V_38 ;
F_58 ( V_56 , F_59 ( V_56 ) | V_57 ) ;
F_60 ( V_56 ) ;
if ( F_61 ( V_2 ) || F_62 ( V_2 ) ) {
F_58 ( V_58 ,
V_59 |
V_60 |
V_61 ) ;
F_60 ( V_58 ) ;
F_63 ( 1 ) ;
F_58 ( V_58 , 0 ) ;
F_60 ( V_58 ) ;
}
F_63 ( 1 ) ;
F_58 ( V_56 , F_59 ( V_56 ) & ~ V_57 ) ;
F_60 ( V_56 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
T_2 V_62 ;
F_65 ( V_2 -> V_32 , V_63 , & V_62 ) ;
return ( V_62 & V_64 ) == 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
int V_52 ;
T_2 V_62 ;
F_65 ( V_2 -> V_32 , V_63 , & V_62 ) ;
F_67 ( V_2 -> V_32 , V_63 ,
V_62 | V_65 |
V_64 ) ;
V_52 = F_68 ( F_64 ( V_2 ) , 500 ) ;
if ( V_52 )
return V_52 ;
F_65 ( V_2 -> V_32 , V_63 , & V_62 ) ;
F_67 ( V_2 -> V_32 , V_63 ,
V_62 | V_66 |
V_64 ) ;
return F_68 ( F_64 ( V_2 ) , 500 ) ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_62 ;
int V_52 ;
V_62 = F_59 ( V_67 + V_68 ) ;
F_58 ( V_67 + V_68 ,
V_62 | V_65 | V_64 ) ;
V_52 = F_68 ( F_59 ( V_67 + V_68 ) & 0x1 , 500 ) ;
if ( V_52 )
return V_52 ;
V_62 = F_59 ( V_67 + V_68 ) ;
F_58 ( V_67 + V_68 ,
V_62 | V_66 | V_64 ) ;
return F_68 ( F_59 ( V_67 + V_68 ) & 0x1 , 500 ) ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_52 ;
unsigned long V_69 ;
F_71 ( & V_4 -> V_70 , V_69 ) ;
F_72 ( V_71 , V_72 ) ;
V_52 = F_68 ( ( F_73 ( V_71 ) & V_72 ) == 0 , 500 ) ;
if ( V_4 -> V_73 )
V_4 -> V_74 . V_75 ( V_4 ) ;
else
V_4 -> V_74 . V_76 ( V_4 ) ;
V_4 -> V_77 = F_73 ( V_78 ) ;
F_74 ( & V_4 -> V_70 , V_69 ) ;
return V_52 ;
}
int F_75 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_52 = - V_38 ;
switch ( F_12 ( V_2 ) -> V_26 ) {
case 7 :
case 6 :
V_52 = F_70 ( V_2 ) ;
break;
case 5 :
V_52 = F_69 ( V_2 ) ;
break;
case 4 :
V_52 = F_66 ( V_2 ) ;
break;
case 2 :
V_52 = F_56 ( V_2 ) ;
break;
}
if ( V_4 -> V_79 . V_80 ) {
F_76 ( L_9 ) ;
V_4 -> V_79 . V_80 = 0 ;
if ( V_52 == - V_38 ) {
F_32 ( L_10
L_11 ) ;
V_52 = 0 ;
}
}
return V_52 ;
}
int F_77 ( struct V_1 * V_2 )
{
T_4 * V_4 = V_2 -> V_5 ;
int V_52 ;
if ( ! V_81 )
return 0 ;
F_15 ( & V_2 -> V_48 ) ;
F_78 ( V_2 ) ;
V_52 = - V_38 ;
if ( F_79 () - V_4 -> V_79 . V_82 < 5 )
F_32 ( L_12 ) ;
else
V_52 = F_75 ( V_2 ) ;
V_4 -> V_79 . V_82 = F_79 () ;
if ( V_52 ) {
F_32 ( L_13 ) ;
F_16 ( & V_2 -> V_48 ) ;
return V_52 ;
}
if ( F_20 ( V_2 , V_33 ) ||
! V_4 -> V_49 . V_50 ) {
struct V_83 * V_84 ;
int V_85 ;
V_4 -> V_49 . V_50 = 0 ;
F_80 ( V_2 ) ;
F_81 (ring, dev_priv, i)
V_84 -> V_86 ( V_84 ) ;
F_82 ( V_2 ) ;
F_83 ( V_2 ) ;
F_16 ( & V_2 -> V_48 ) ;
F_25 ( V_2 ) ;
F_42 ( V_2 ) ;
F_45 ( V_2 ) ;
} else {
F_16 ( & V_2 -> V_48 ) ;
}
return 0 ;
}
static int F_84 ( struct V_6 * V_32 , const struct V_87 * V_88 )
{
struct V_89 * V_90 =
(struct V_89 * ) V_88 -> V_91 ;
if ( V_90 -> V_92 )
if( ! V_93 ) {
F_32 ( L_14 ) ;
return - V_38 ;
}
if ( F_85 ( V_32 -> V_94 ) )
return - V_38 ;
if ( V_90 -> V_26 != 3 ) {
V_95 . V_96 &=
~ ( V_97 | V_98 ) ;
} else if ( ! V_99 ) {
F_32 ( L_15 ) ;
return - V_38 ;
}
return F_86 ( V_32 , V_88 , & V_95 ) ;
}
static void
F_87 ( struct V_6 * V_32 )
{
struct V_1 * V_2 = F_88 ( V_32 ) ;
F_89 ( V_2 ) ;
}
static int F_90 ( struct V_12 * V_2 )
{
struct V_6 * V_32 = F_91 ( V_2 ) ;
struct V_1 * V_100 = F_88 ( V_32 ) ;
int error ;
if ( ! V_100 || ! V_100 -> V_5 ) {
F_22 ( V_2 , L_8 ) ;
return - V_38 ;
}
if ( V_100 -> V_41 == V_42 )
return 0 ;
error = F_14 ( V_100 ) ;
if ( error )
return error ;
F_33 ( V_32 ) ;
F_34 ( V_32 , V_44 ) ;
return 0 ;
}
static int F_92 ( struct V_12 * V_2 )
{
struct V_6 * V_32 = F_91 ( V_2 ) ;
struct V_1 * V_100 = F_88 ( V_32 ) ;
return F_52 ( V_100 ) ;
}
static int F_93 ( struct V_12 * V_2 )
{
struct V_6 * V_32 = F_91 ( V_2 ) ;
struct V_1 * V_100 = F_88 ( V_32 ) ;
if ( ! V_100 || ! V_100 -> V_5 ) {
F_22 ( V_2 , L_8 ) ;
return - V_38 ;
}
return F_14 ( V_100 ) ;
}
static int F_94 ( struct V_12 * V_2 )
{
struct V_6 * V_32 = F_91 ( V_2 ) ;
struct V_1 * V_100 = F_88 ( V_32 ) ;
return F_49 ( V_100 ) ;
}
static int F_95 ( struct V_12 * V_2 )
{
struct V_6 * V_32 = F_91 ( V_2 ) ;
struct V_1 * V_100 = F_88 ( V_32 ) ;
return F_14 ( V_100 ) ;
}
static int T_5 F_96 ( void )
{
V_95 . V_101 = V_102 ;
#if F_97 ( V_103 )
if ( V_104 != 0 )
V_95 . V_96 |= V_33 ;
#endif
if ( V_104 == 1 )
V_95 . V_96 |= V_33 ;
#ifdef F_98
if ( F_99 () && V_104 == - 1 )
V_95 . V_96 &= ~ V_33 ;
#endif
if ( ! ( V_95 . V_96 & V_33 ) )
V_95 . V_105 = NULL ;
return F_100 ( & V_95 , & V_106 ) ;
}
static void T_6 F_101 ( void )
{
F_102 ( & V_95 , & V_106 ) ;
}
static void
F_103 ( struct V_3 * V_4 )
{
F_72 ( V_107 , 0 ) ;
}
int F_104 ( struct V_1 * V_2 ,
void * V_108 , struct V_109 * V_110 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_111 * V_112 = V_108 ;
struct V_113 const * V_114 = V_115 ;
int V_85 ;
for ( V_85 = 0 ; V_85 < F_105 ( V_115 ) ; V_85 ++ , V_114 ++ ) {
if ( V_114 -> V_116 == V_112 -> V_116 &&
( 1 << F_12 ( V_2 ) -> V_26 & V_114 -> V_117 ) )
break;
}
if ( V_85 == F_105 ( V_115 ) )
return - V_118 ;
switch ( V_114 -> V_119 ) {
case 8 :
V_112 -> V_120 = F_106 ( V_112 -> V_116 ) ;
break;
case 4 :
V_112 -> V_120 = F_59 ( V_112 -> V_116 ) ;
break;
case 2 :
V_112 -> V_120 = F_107 ( V_112 -> V_116 ) ;
break;
case 1 :
V_112 -> V_120 = F_108 ( V_112 -> V_116 ) ;
break;
default:
F_4 ( 1 ) ;
return - V_118 ;
}
return 0 ;
}
