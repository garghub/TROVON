static int F_1 ( struct V_1 * V_2 ,
int V_3 , unsigned int V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
V_9 -> V_10 = V_4 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned int V_11 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
unsigned int V_12 = 0 ;
int V_13 ;
switch ( V_11 & V_14 ) {
case V_15 :
V_9 -> V_16 = 0 ;
break;
case V_17 :
V_9 -> V_16 = 1 ;
V_12 |= V_18 ;
break;
default:
F_4 ( V_7 -> V_19 , L_1 ) ;
return - V_20 ;
}
switch ( V_11 & V_21 ) {
case V_22 :
V_12 |= V_23 ;
V_13 = F_5 ( V_7 , V_24 ,
V_25 , V_26 ) ;
if ( V_13 < 0 )
return V_13 ;
break;
case V_27 :
V_12 |= V_28 ;
V_13 = F_5 ( V_7 , V_24 ,
V_25 , V_29 ) ;
if ( V_13 < 0 )
return V_13 ;
break;
default:
F_4 ( V_7 -> V_19 , L_1 ) ;
return - V_20 ;
}
V_13 = F_5 ( V_7 , V_30 ,
V_31 | V_18 , V_12 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static int F_6 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
int V_32 , V_13 ;
int V_12 = V_33 ;
if ( V_9 -> V_34 ) {
V_12 = 1 ;
for ( V_32 = 2 ; V_32 < F_7 ( V_35 ) ; V_32 ++ )
if ( abs ( V_35 [ V_32 ] - V_9 -> V_36 ) <
abs ( V_35 [ V_12 ] - V_9 -> V_36 ) )
V_12 = V_32 ;
V_12 <<= 4 ;
}
V_13 = F_5 ( V_7 , V_37 ,
V_38 , V_12 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static int F_8 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_6 * V_7 = F_9 ( V_40 ) ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
V_42 -> V_43 . V_44 . V_45 [ 0 ] = V_9 -> V_34 ;
return 0 ;
}
static int F_10 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_6 * V_7 = F_9 ( V_40 ) ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
V_9 -> V_34 = V_42 -> V_43 . V_44 . V_45 [ 0 ] ;
return F_6 ( V_7 ) ;
}
static int F_11 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
struct V_1 * V_50 )
{
struct V_6 * V_7 = V_50 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
int V_32 , V_13 ;
unsigned int V_51 , V_12 ;
if ( V_9 -> V_52 ) {
if ( ( V_47 -> V_53 == V_54 &&
! V_50 -> V_55 ) ||
( V_47 -> V_53 == V_56 &&
! V_50 -> V_57 ) ) {
V_13 = F_5 ( V_7 , V_58 ,
V_59 ,
V_59 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_7 , V_58 ,
V_59 , 0 ) ;
if ( V_13 < 0 )
return V_13 ;
}
}
V_9 -> V_36 = F_12 ( V_49 ) ;
if ( V_9 -> V_36 < 50000 )
V_12 = V_60 ;
else if ( V_9 -> V_36 < 100000 )
V_12 = V_61 ;
else
V_12 = V_62 ;
V_51 = V_9 -> V_10 / V_9 -> V_36 ;
for ( V_32 = 0 ; V_32 < V_63 ; V_32 ++ )
if ( ( V_64 [ V_32 ] . V_16 == V_9 -> V_16 ) &&
( V_64 [ V_32 ] . V_65 == V_12 ) &&
( V_64 [ V_32 ] . V_51 == V_51 ) )
break;
if ( V_32 == V_63 ) {
F_4 ( V_7 -> V_19 , L_2 ) ;
return - V_20 ;
}
V_12 |= V_64 [ V_32 ] . V_66 ;
V_13 = F_5 ( V_7 , V_30 ,
V_67 | V_68 , V_12 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_6 ( V_7 ) ;
}
static int F_13 ( struct V_1 * V_50 , int V_69 )
{
struct V_6 * V_7 = V_50 -> V_7 ;
int V_13 ;
int V_70 = 0 ;
int V_71 = 0 ;
if ( V_69 ) {
V_70 = V_72 ;
V_71 = V_73 ;
}
V_13 = F_5 ( V_7 , V_74 , V_72 , V_70 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_7 , V_75 , V_73 , V_71 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static int F_14 ( struct V_6 * V_7 )
{
int V_13 ;
V_13 = F_5 ( V_7 , V_58 , V_59 ,
V_59 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 )
{
int V_13 ;
V_13 = F_16 ( V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_7 , V_58 , V_59 , 0 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static int F_17 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
struct V_76 * V_77 = V_7 -> V_19 -> V_78 ;
int V_13 ;
int V_79 = - V_20 ;
bool V_80 = false ;
#ifdef F_18
if ( F_19 ( V_81 , V_7 -> V_19 ) ) {
V_79 = F_20 ( V_7 -> V_19 -> V_82 ,
L_3 , 0 ) ;
if ( F_21 ( V_7 -> V_19 -> V_82 ,
L_4 , NULL ) )
V_80 = true ;
if ( F_21 ( V_7 -> V_19 -> V_82 ,
L_5 , NULL ) )
V_9 -> V_52 = true ;
}
#endif
if ( V_77 ) {
if ( F_22 ( V_77 -> V_79 ) )
V_79 = V_77 -> V_79 ;
V_80 = V_77 -> V_80 ;
V_9 -> V_52 = V_77 -> V_52 ;
}
if ( V_79 >= 0 )
if ( F_23 ( V_7 -> V_19 , V_79 , L_6 ) )
V_79 = - V_20 ;
if ( V_79 >= 0 ) {
F_24 ( V_79 , 0 ) ;
F_25 ( 1 ) ;
F_26 ( V_79 , 1 ) ;
F_25 ( 1 ) ;
}
V_9 -> V_79 = V_79 ;
if ( V_9 -> V_83 == V_84 )
V_13 = F_27 ( V_7 , 16 , 8 ,
V_9 -> V_83 ) ;
else
V_13 = F_27 ( V_7 , 8 , 8 ,
V_9 -> V_83 ) ;
if ( V_13 ) {
F_4 ( V_7 -> V_19 , L_7 , V_13 ) ;
return V_13 ;
}
V_13 = F_5 ( V_7 , V_58 ,
V_59 | V_85 ,
V_59 | V_85 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_7 , V_58 , V_59 , 0 ) ;
if ( V_13 < 0 )
return V_13 ;
F_25 ( 85 ) ;
if ( V_80 )
F_5 ( V_7 , V_58 ,
V_86 ,
V_86 ) ;
return F_28 ( V_7 , V_87 ,
F_7 ( V_87 ) ) ;
}
static int F_29 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
if ( F_22 ( V_9 -> V_79 ) )
F_26 ( V_9 -> V_79 , 0 ) ;
return 0 ;
}
static int F_30 ( struct V_88 * V_89 )
{
struct V_8 * V_9 ;
V_9 = F_31 ( & V_89 -> V_19 , sizeof( * V_9 ) , V_90 ) ;
if ( ! V_9 )
return - V_91 ;
F_32 ( V_89 , V_9 ) ;
V_9 -> V_83 = V_84 ;
return F_33 ( & V_89 -> V_19 , & V_92 ,
& V_93 , 1 ) ;
}
static int F_34 ( struct V_88 * V_89 )
{
F_35 ( & V_89 -> V_19 ) ;
return 0 ;
}
static int F_36 ( struct V_94 * V_95 ,
const struct V_96 * V_97 )
{
struct V_8 * V_9 ;
V_9 = F_31 ( & V_95 -> V_19 , sizeof( * V_9 ) , V_90 ) ;
if ( ! V_9 )
return - V_91 ;
F_37 ( V_95 , V_9 ) ;
V_9 -> V_83 = V_98 ;
return F_33 ( & V_95 -> V_19 , & V_92 ,
& V_93 , 1 ) ;
}
static int F_38 ( struct V_94 * V_95 )
{
F_35 ( & V_95 -> V_19 ) ;
return 0 ;
}
static int T_1 F_39 ( void )
{
int V_13 ;
#if F_40 ( V_99 ) || F_40 ( V_100 )
V_13 = F_41 ( & V_101 ) ;
if ( V_13 ) {
F_42 ( L_8 , V_13 ) ;
return V_13 ;
}
#endif
#if F_40 ( V_102 )
V_13 = F_43 ( & V_103 ) ;
if ( V_13 ) {
F_42 ( L_9 , V_13 ) ;
return V_13 ;
}
#endif
return 0 ;
}
static void T_2 F_44 ( void )
{
#if F_40 ( V_102 )
F_45 ( & V_103 ) ;
#endif
#if F_40 ( V_99 ) || F_40 ( V_100 )
F_46 ( & V_101 ) ;
#endif
}
