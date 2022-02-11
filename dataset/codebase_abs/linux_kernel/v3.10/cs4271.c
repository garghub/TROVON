static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_3 == V_4 ;
}
static int F_2 ( struct V_5 * V_6 ,
int V_7 , unsigned int V_8 , int V_9 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
V_13 -> V_14 = V_8 ;
return 0 ;
}
static int F_4 ( struct V_5 * V_6 ,
unsigned int V_15 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
unsigned int V_16 = 0 ;
int V_17 ;
switch ( V_15 & V_18 ) {
case V_19 :
V_13 -> V_20 = 0 ;
break;
case V_21 :
V_13 -> V_20 = 1 ;
V_16 |= V_22 ;
break;
default:
F_5 ( V_11 -> V_2 , L_1 ) ;
return - V_23 ;
}
switch ( V_15 & V_24 ) {
case V_25 :
V_16 |= V_26 ;
V_17 = F_6 ( V_13 -> V_27 , V_28 ,
V_29 , V_30 ) ;
if ( V_17 < 0 )
return V_17 ;
break;
case V_31 :
V_16 |= V_32 ;
V_17 = F_6 ( V_13 -> V_27 , V_28 ,
V_29 , V_33 ) ;
if ( V_17 < 0 )
return V_17 ;
break;
default:
F_5 ( V_11 -> V_2 , L_1 ) ;
return - V_23 ;
}
V_17 = F_6 ( V_13 -> V_27 , V_34 ,
V_35 | V_22 , V_16 ) ;
if ( V_17 < 0 )
return V_17 ;
return 0 ;
}
static int F_7 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_3 ( V_11 ) ;
int V_36 , V_17 ;
int V_16 = V_37 ;
if ( V_13 -> V_38 ) {
V_16 = 1 ;
for ( V_36 = 2 ; V_36 < F_8 ( V_39 ) ; V_36 ++ )
if ( abs ( V_39 [ V_36 ] - V_13 -> V_40 ) <
abs ( V_39 [ V_16 ] - V_13 -> V_40 ) )
V_16 = V_36 ;
V_16 <<= 4 ;
}
V_17 = F_6 ( V_13 -> V_27 , V_41 ,
V_42 , V_16 ) ;
if ( V_17 < 0 )
return V_17 ;
return 0 ;
}
static int F_9 ( struct V_43 * V_44 ,
struct V_45 * V_46 )
{
struct V_10 * V_11 = F_10 ( V_44 ) ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
V_46 -> V_47 . V_48 . V_49 [ 0 ] = V_13 -> V_38 ;
return 0 ;
}
static int F_11 ( struct V_43 * V_44 ,
struct V_45 * V_46 )
{
struct V_10 * V_11 = F_10 ( V_44 ) ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
V_13 -> V_38 = V_46 -> V_47 . V_48 . V_49 [ 0 ] ;
return F_7 ( V_11 ) ;
}
static int F_12 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
struct V_5 * V_54 )
{
struct V_10 * V_11 = V_54 -> V_11 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
int V_36 , V_17 ;
unsigned int V_55 , V_16 ;
if ( V_13 -> V_56 ) {
if ( ( V_51 -> V_57 == V_58 &&
! V_54 -> V_59 ) ||
( V_51 -> V_57 == V_60 &&
! V_54 -> V_61 ) ) {
V_17 = F_6 ( V_13 -> V_27 , V_62 ,
V_63 ,
V_63 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_6 ( V_13 -> V_27 , V_62 ,
V_63 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
}
}
V_13 -> V_40 = F_13 ( V_53 ) ;
if ( V_13 -> V_40 < 50000 )
V_16 = V_64 ;
else if ( V_13 -> V_40 < 100000 )
V_16 = V_65 ;
else
V_16 = V_66 ;
V_55 = V_13 -> V_14 / V_13 -> V_40 ;
for ( V_36 = 0 ; V_36 < V_67 ; V_36 ++ )
if ( ( V_68 [ V_36 ] . V_20 == V_13 -> V_20 ) &&
( V_68 [ V_36 ] . V_69 == V_16 ) &&
( V_68 [ V_36 ] . V_55 == V_55 ) )
break;
if ( V_36 == V_67 ) {
F_5 ( V_11 -> V_2 , L_2 ) ;
return - V_23 ;
}
V_16 |= V_68 [ V_36 ] . V_70 ;
V_17 = F_6 ( V_13 -> V_27 , V_34 ,
V_71 | V_72 , V_16 ) ;
if ( V_17 < 0 )
return V_17 ;
return F_7 ( V_11 ) ;
}
static int F_14 ( struct V_5 * V_54 , int V_73 , int V_57 )
{
struct V_10 * V_11 = V_54 -> V_11 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
int V_17 ;
int V_74 = 0 ;
int V_75 = 0 ;
if ( V_57 != V_58 )
return 0 ;
if ( V_73 ) {
V_74 = V_76 ;
V_75 = V_77 ;
}
V_17 = F_6 ( V_13 -> V_27 , V_78 ,
V_76 , V_74 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_6 ( V_13 -> V_27 , V_79 ,
V_77 , V_75 ) ;
if ( V_17 < 0 )
return V_17 ;
return 0 ;
}
static int F_15 ( struct V_10 * V_11 )
{
int V_17 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
V_17 = F_6 ( V_13 -> V_27 , V_62 ,
V_63 , V_63 ) ;
if ( V_17 < 0 )
return V_17 ;
return 0 ;
}
static int F_16 ( struct V_10 * V_11 )
{
int V_17 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
V_17 = F_17 ( V_13 -> V_27 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_6 ( V_13 -> V_27 , V_62 ,
V_63 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
return 0 ;
}
static int F_18 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_80 * V_81 = V_11 -> V_2 -> V_82 ;
int V_17 ;
int V_83 = - V_23 ;
bool V_84 = false ;
#ifdef F_19
if ( F_20 ( V_85 , V_11 -> V_2 ) ) {
V_83 = F_21 ( V_11 -> V_2 -> V_86 ,
L_3 , 0 ) ;
if ( F_22 ( V_11 -> V_2 -> V_86 ,
L_4 , NULL ) )
V_84 = true ;
if ( F_22 ( V_11 -> V_2 -> V_86 ,
L_5 , NULL ) )
V_13 -> V_56 = true ;
}
#endif
if ( V_81 ) {
if ( F_23 ( V_81 -> V_83 ) )
V_83 = V_81 -> V_83 ;
V_84 = V_81 -> V_84 ;
V_13 -> V_56 = V_81 -> V_56 ;
}
if ( V_83 >= 0 )
if ( F_24 ( V_11 -> V_2 , V_83 , L_6 ) )
V_83 = - V_23 ;
if ( V_83 >= 0 ) {
F_25 ( V_83 , 0 ) ;
F_26 ( 1 ) ;
F_27 ( V_83 , 1 ) ;
F_26 ( 1 ) ;
}
V_13 -> V_83 = V_83 ;
V_17 = F_6 ( V_13 -> V_27 , V_62 ,
V_63 | V_87 ,
V_63 | V_87 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_6 ( V_13 -> V_27 , V_62 ,
V_63 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
F_26 ( 85 ) ;
if ( V_84 )
F_6 ( V_13 -> V_27 , V_62 ,
V_88 ,
V_88 ) ;
return F_28 ( V_11 , V_89 ,
F_8 ( V_89 ) ) ;
}
static int F_29 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_3 ( V_11 ) ;
if ( F_23 ( V_13 -> V_83 ) )
F_27 ( V_13 -> V_83 , 0 ) ;
return 0 ;
}
static int F_30 ( struct V_90 * V_91 )
{
struct V_12 * V_13 ;
V_13 = F_31 ( & V_91 -> V_2 , sizeof( * V_13 ) , V_92 ) ;
if ( ! V_13 )
return - V_93 ;
F_32 ( V_91 , V_13 ) ;
V_13 -> V_27 = F_33 ( V_91 , & V_94 ) ;
if ( F_34 ( V_13 -> V_27 ) )
return F_35 ( V_13 -> V_27 ) ;
return F_36 ( & V_91 -> V_2 , & V_95 ,
& V_96 , 1 ) ;
}
static int F_37 ( struct V_90 * V_91 )
{
F_38 ( & V_91 -> V_2 ) ;
return 0 ;
}
static int F_39 ( struct V_97 * V_98 ,
const struct V_99 * V_100 )
{
struct V_12 * V_13 ;
V_13 = F_31 ( & V_98 -> V_2 , sizeof( * V_13 ) , V_92 ) ;
if ( ! V_13 )
return - V_93 ;
F_40 ( V_98 , V_13 ) ;
V_13 -> V_27 = F_41 ( V_98 , & V_101 ) ;
if ( F_34 ( V_13 -> V_27 ) )
return F_35 ( V_13 -> V_27 ) ;
return F_36 ( & V_98 -> V_2 , & V_95 ,
& V_96 , 1 ) ;
}
static int F_42 ( struct V_97 * V_98 )
{
F_38 ( & V_98 -> V_2 ) ;
return 0 ;
}
static int T_1 F_43 ( void )
{
int V_17 ;
#if F_44 ( V_102 ) || F_44 ( V_103 )
V_17 = F_45 ( & V_104 ) ;
if ( V_17 ) {
F_46 ( L_7 , V_17 ) ;
return V_17 ;
}
#endif
#if F_44 ( V_105 )
V_17 = F_47 ( & V_106 ) ;
if ( V_17 ) {
F_46 ( L_8 , V_17 ) ;
return V_17 ;
}
#endif
return 0 ;
}
static void T_2 F_48 ( void )
{
#if F_44 ( V_105 )
F_49 ( & V_106 ) ;
#endif
#if F_44 ( V_102 ) || F_44 ( V_103 )
F_50 ( & V_104 ) ;
#endif
}
