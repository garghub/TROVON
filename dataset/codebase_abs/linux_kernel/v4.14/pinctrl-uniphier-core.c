static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 -> V_6 ;
}
static const char * F_3 ( struct V_1 * V_2 ,
unsigned V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 -> V_8 [ V_7 ] . V_9 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned V_7 ,
const unsigned * * V_10 ,
unsigned * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_10 = V_4 -> V_5 -> V_8 [ V_7 ] . V_10 ;
* V_11 = V_4 -> V_5 -> V_8 [ V_7 ] . V_11 ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_12 * V_13 , unsigned V_14 )
{
const struct V_15 * V_16 = F_6 ( V_2 , V_14 ) ;
const char * V_17 , * V_18 ;
switch ( F_7 ( V_16 -> V_19 ) ) {
case V_20 :
V_17 = L_1 ;
break;
case V_21 :
V_17 = L_2 ;
break;
case V_22 :
V_17 = L_3 ;
break;
case V_23 :
V_17 = L_4 ;
break;
case V_24 :
V_17 = L_5 ;
break;
default:
F_8 () ;
}
switch ( F_9 ( V_16 -> V_19 ) ) {
case V_25 :
V_18 = L_6 ;
break;
case V_26 :
V_18 = L_7 ;
break;
case V_27 :
V_18 = L_8 ;
break;
case V_28 :
V_18 = L_9 ;
break;
case V_29 :
V_18 = L_10 ;
break;
case V_30 :
V_18 = L_11 ;
break;
case V_31 :
V_18 = L_5 ;
break;
default:
F_8 () ;
}
F_10 ( V_13 , L_12 , V_17 , V_18 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned int V_32 ,
enum V_33 V_34 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_15 * V_16 = F_6 ( V_2 , V_32 ) ;
enum V_35 V_17 =
F_7 ( V_16 -> V_19 ) ;
unsigned int V_36 , V_37 , V_38 , V_39 ;
unsigned int V_40 = 1 ;
int V_41 ;
switch ( V_34 ) {
case V_42 :
if ( V_17 == V_24 )
return 0 ;
if ( V_17 == V_22 ||
V_17 == V_23 )
return - V_43 ;
V_40 = 0 ;
break;
case V_44 :
if ( V_17 == V_22 )
return 0 ;
if ( V_17 != V_20 )
return - V_43 ;
break;
case V_45 :
if ( V_17 == V_23 )
return 0 ;
if ( V_17 != V_21 )
return - V_43 ;
break;
default:
F_8 () ;
}
V_36 = F_12 ( V_16 -> V_19 ) ;
V_37 = V_46 + V_36 / 32 * 4 ;
V_38 = V_36 % 32 ;
V_41 = F_13 ( V_4 -> V_47 , V_37 , & V_39 ) ;
if ( V_41 )
return V_41 ;
V_39 = ( V_39 >> V_38 ) & 1 ;
return ( V_39 == V_40 ) ? 0 : - V_43 ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned int V_32 , T_1 * V_48 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_15 * V_16 = F_6 ( V_2 , V_32 ) ;
enum V_49 type =
F_9 ( V_16 -> V_19 ) ;
const unsigned int V_50 [] = { 4 , 8 } ;
const unsigned int V_51 [] = { 8 , 12 , 16 , 20 } ;
const unsigned int V_52 [] = { 4 , 5 , 7 , 9 , 11 , 12 , 14 , 16 } ;
const unsigned int * V_53 ;
unsigned int V_54 , V_37 , V_38 , V_55 , V_56 , V_39 ;
int V_41 ;
switch ( type ) {
case V_25 :
V_53 = V_50 ;
V_37 = V_57 ;
V_56 = 1 ;
break;
case V_26 :
V_53 = V_51 ;
V_37 = V_58 ;
V_56 = 2 ;
break;
case V_27 :
V_53 = V_52 ;
V_37 = V_59 ;
V_56 = 4 ;
break;
case V_28 :
* V_48 = 4 ;
return 0 ;
case V_29 :
* V_48 = 5 ;
return 0 ;
case V_30 :
* V_48 = 8 ;
return 0 ;
default:
return - V_43 ;
}
V_54 = F_15 ( V_16 -> V_19 ) ;
V_54 *= V_56 ;
V_37 += V_54 / 32 * 4 ;
V_38 = V_54 % 32 ;
V_55 = ( 1U << V_56 ) - 1 ;
V_41 = F_13 ( V_4 -> V_47 , V_37 , & V_39 ) ;
if ( V_41 )
return V_41 ;
* V_48 = V_53 [ ( V_39 >> V_38 ) & V_55 ] ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
unsigned int V_32 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_15 * V_16 = F_6 ( V_2 , V_32 ) ;
unsigned int V_60 = F_17 ( V_16 -> V_19 ) ;
unsigned int V_37 , V_55 , V_39 ;
int V_41 ;
if ( V_60 == V_61 )
return 0 ;
if ( V_4 -> V_5 -> V_62 & V_63 )
V_60 = V_32 ;
V_37 = V_64 + V_60 / 32 * 4 ;
V_55 = F_18 ( V_60 % 32 ) ;
V_41 = F_13 ( V_4 -> V_47 , V_37 , & V_39 ) ;
if ( V_41 )
return V_41 ;
return V_39 & V_55 ? 0 : - V_43 ;
}
static int F_19 ( struct V_1 * V_2 ,
unsigned V_32 ,
unsigned long * V_65 )
{
enum V_33 V_34 = F_20 ( * V_65 ) ;
bool V_66 = false ;
T_1 V_67 ;
int V_41 ;
switch ( V_34 ) {
case V_42 :
case V_44 :
case V_45 :
V_41 = F_11 ( V_2 , V_32 , V_34 ) ;
break;
case V_68 :
V_41 = F_14 ( V_2 , V_32 , & V_67 ) ;
V_66 = true ;
break;
case V_69 :
V_41 = F_16 ( V_2 , V_32 ) ;
break;
default:
V_41 = - V_43 ;
break;
}
if ( V_41 == 0 && V_66 )
* V_65 = F_21 ( V_34 , V_67 ) ;
return V_41 ;
}
static int F_22 ( struct V_1 * V_2 ,
unsigned int V_32 ,
enum V_33 V_34 , T_1 V_67 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_15 * V_16 = F_6 ( V_2 , V_32 ) ;
enum V_35 V_17 =
F_7 ( V_16 -> V_19 ) ;
unsigned int V_36 , V_37 , V_38 ;
unsigned int V_39 = 1 ;
switch ( V_34 ) {
case V_42 :
if ( V_17 == V_24 )
return 0 ;
if ( V_17 == V_22 ||
V_17 == V_23 ) {
F_23 ( V_2 -> V_70 ,
L_13 ,
V_16 -> V_9 ) ;
return - V_43 ;
}
V_39 = 0 ;
break;
case V_44 :
if ( V_17 == V_22 && V_67 != 0 )
return 0 ;
if ( V_17 != V_20 ) {
F_23 ( V_2 -> V_70 ,
L_14 ,
V_16 -> V_9 ) ;
return - V_43 ;
}
if ( V_67 == 0 ) {
F_23 ( V_2 -> V_70 , L_15 ) ;
return - V_43 ;
}
break;
case V_45 :
if ( V_17 == V_23 && V_67 != 0 )
return 0 ;
if ( V_17 != V_21 ) {
F_23 ( V_2 -> V_70 ,
L_16 ,
V_16 -> V_9 ) ;
return - V_43 ;
}
if ( V_67 == 0 ) {
F_23 ( V_2 -> V_70 , L_17 ) ;
return - V_43 ;
}
break;
case V_71 :
if ( V_17 == V_24 ) {
F_23 ( V_2 -> V_70 ,
L_18 ,
V_16 -> V_9 ) ;
return - V_43 ;
}
if ( V_67 == 0 )
return 0 ;
break;
default:
F_8 () ;
}
V_36 = F_12 ( V_16 -> V_19 ) ;
V_37 = V_46 + V_36 / 32 * 4 ;
V_38 = V_36 % 32 ;
return F_24 ( V_4 -> V_47 , V_37 , 1 << V_38 , V_39 << V_38 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
unsigned int V_32 , T_1 V_48 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_15 * V_16 = F_6 ( V_2 , V_32 ) ;
enum V_49 type =
F_9 ( V_16 -> V_19 ) ;
const unsigned int V_50 [] = { 4 , 8 , - 1 } ;
const unsigned int V_51 [] = { 8 , 12 , 16 , 20 , - 1 } ;
const unsigned int V_52 [] = { 4 , 5 , 7 , 9 , 11 , 12 , 14 , 16 , - 1 } ;
const unsigned int * V_53 ;
unsigned int V_54 , V_37 , V_38 , V_55 , V_56 , V_39 ;
switch ( type ) {
case V_25 :
V_53 = V_50 ;
V_37 = V_57 ;
V_56 = 1 ;
break;
case V_26 :
V_53 = V_51 ;
V_37 = V_58 ;
V_56 = 2 ;
break;
case V_27 :
V_53 = V_52 ;
V_37 = V_59 ;
V_56 = 4 ;
break;
default:
F_23 ( V_2 -> V_70 ,
L_19 ,
V_16 -> V_9 ) ;
return - V_43 ;
}
for ( V_39 = 0 ; V_53 [ V_39 ] > 0 ; V_39 ++ ) {
if ( V_53 [ V_39 ] > V_48 )
break;
}
if ( V_39 == 0 ) {
F_23 ( V_2 -> V_70 ,
L_20 ,
V_48 , V_16 -> V_9 ) ;
return - V_43 ;
}
V_39 -- ;
V_54 = F_15 ( V_16 -> V_19 ) ;
V_54 *= V_56 ;
V_37 += V_54 / 32 * 4 ;
V_38 = V_54 % 32 ;
V_55 = ( 1U << V_56 ) - 1 ;
return F_24 ( V_4 -> V_47 , V_37 ,
V_55 << V_38 , V_39 << V_38 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
unsigned int V_32 , T_1 V_72 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_15 * V_16 = F_6 ( V_2 , V_32 ) ;
unsigned int V_60 = F_17 ( V_16 -> V_19 ) ;
unsigned int V_37 , V_55 ;
if ( ! ( V_4 -> V_5 -> V_62 & V_63 ) &&
! V_72 )
return - V_43 ;
if ( V_60 == V_61 )
return V_72 ? 0 : - V_43 ;
if ( V_4 -> V_5 -> V_62 & V_63 )
V_60 = V_32 ;
V_37 = V_64 + V_60 / 32 * 4 ;
V_55 = F_18 ( V_60 % 32 ) ;
return F_24 ( V_4 -> V_47 , V_37 , V_55 , V_72 ? V_55 : 0 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
unsigned V_32 ,
unsigned long * V_65 ,
unsigned V_73 )
{
int V_74 , V_41 ;
for ( V_74 = 0 ; V_74 < V_73 ; V_74 ++ ) {
enum V_33 V_34 =
F_20 ( V_65 [ V_74 ] ) ;
T_1 V_67 = F_28 ( V_65 [ V_74 ] ) ;
switch ( V_34 ) {
case V_42 :
case V_44 :
case V_45 :
case V_71 :
V_41 = F_22 ( V_2 , V_32 ,
V_34 , V_67 ) ;
break;
case V_68 :
V_41 = F_25 ( V_2 , V_32 , V_67 ) ;
break;
case V_69 :
V_41 = F_26 ( V_2 , V_32 , V_67 ) ;
break;
default:
F_23 ( V_2 -> V_70 ,
L_21 ,
V_34 ) ;
return - V_43 ;
}
if ( V_41 )
return V_41 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
unsigned V_7 ,
unsigned long * V_65 ,
unsigned V_73 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const unsigned * V_10 = V_4 -> V_5 -> V_8 [ V_7 ] . V_10 ;
unsigned V_11 = V_4 -> V_5 -> V_8 [ V_7 ] . V_11 ;
int V_74 , V_41 ;
for ( V_74 = 0 ; V_74 < V_11 ; V_74 ++ ) {
V_41 = F_27 ( V_2 , V_10 [ V_74 ] ,
V_65 , V_73 ) ;
if ( V_41 )
return V_41 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 -> V_75 ;
}
static const char * F_31 ( struct V_1 * V_2 ,
unsigned V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 -> V_76 [ V_7 ] . V_9 ;
}
static int F_32 ( struct V_1 * V_2 ,
unsigned V_7 ,
const char * const * * V_8 ,
unsigned * V_77 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_8 = V_4 -> V_5 -> V_76 [ V_7 ] . V_8 ;
* V_77 = V_4 -> V_5 -> V_76 [ V_7 ] . V_77 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , unsigned V_32 ,
int V_78 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_79 , V_80 , V_37 , V_81 , V_38 , V_55 ;
bool V_82 ;
int V_41 ;
V_41 = F_26 ( V_2 , V_32 , 1 ) ;
if ( V_41 )
return V_41 ;
if ( V_78 < 0 )
return 0 ;
if ( V_4 -> V_5 -> V_62 & V_83 ) {
V_79 = 4 ;
V_80 = 8 ;
V_82 = true ;
} else {
V_79 = 8 ;
V_80 = 4 ;
V_82 = false ;
}
V_37 = V_84 + V_32 * V_79 / 32 * V_80 ;
V_81 = V_37 + V_80 ;
V_38 = V_32 * V_79 % 32 ;
V_55 = ( 1U << V_79 ) - 1 ;
for (; V_37 < V_81 ; V_37 += 4 ) {
V_41 = F_24 ( V_4 -> V_47 , V_37 ,
V_55 << V_38 , V_78 << V_38 ) ;
if ( V_41 )
return V_41 ;
V_78 >>= V_79 ;
}
if ( V_82 ) {
V_41 = F_34 ( V_4 -> V_47 ,
V_85 , 1 ) ;
if ( V_41 )
return V_41 ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
unsigned V_86 ,
unsigned V_87 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_88 * V_89 =
& V_4 -> V_5 -> V_8 [ V_87 ] ;
int V_74 ;
int V_41 ;
for ( V_74 = 0 ; V_74 < V_89 -> V_11 ; V_74 ++ ) {
V_41 = F_33 ( V_2 , V_89 -> V_10 [ V_74 ] ,
V_89 -> V_90 [ V_74 ] ) ;
if ( V_41 )
return V_41 ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_91 * V_92 ,
unsigned V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_93 ;
int V_78 , V_74 ;
if ( V_92 -> V_10 ) {
for ( V_74 = 0 ; V_74 < V_92 -> V_94 ; V_74 ++ )
if ( V_92 -> V_10 [ V_74 ] == V_14 )
break;
if ( F_37 ( V_74 == V_92 -> V_94 ) )
return - V_43 ;
V_93 = V_74 ;
} else {
V_93 = V_14 - V_92 -> V_95 ;
}
V_93 += V_92 -> V_96 ;
V_78 = V_4 -> V_5 -> V_97 ( V_14 , V_93 ) ;
return F_33 ( V_2 , V_14 , V_78 ) ;
}
static int F_38 ( struct V_98 * V_70 )
{
struct V_3 * V_4 = F_39 ( V_70 ) ;
struct V_99 * V_100 ;
int V_41 ;
F_40 (r, &priv->reg_regions, node) {
V_41 = F_41 ( V_4 -> V_47 , V_100 -> V_101 , V_100 -> V_102 ,
V_100 -> V_103 ) ;
if ( V_41 )
return V_41 ;
}
return 0 ;
}
static int F_42 ( struct V_98 * V_70 )
{
struct V_3 * V_4 = F_39 ( V_70 ) ;
struct V_99 * V_100 ;
int V_41 ;
F_40 (r, &priv->reg_regions, node) {
V_41 = F_43 ( V_4 -> V_47 , V_100 -> V_101 , V_100 -> V_102 ,
V_100 -> V_103 ) ;
if ( V_41 )
return V_41 ;
}
if ( V_4 -> V_5 -> V_62 & V_83 ) {
V_41 = F_34 ( V_4 -> V_47 ,
V_85 , 1 ) ;
if ( V_41 )
return V_41 ;
}
return 0 ;
}
static int F_44 ( struct V_98 * V_70 ,
struct V_3 * V_4 ,
unsigned int V_101 ,
unsigned int V_104 ,
unsigned int V_56 )
{
struct V_99 * V_105 ;
unsigned int V_103 ;
if ( ! V_104 )
return 0 ;
V_103 = F_45 ( V_104 * V_56 , 32 ) ;
V_105 = F_46 ( V_70 ,
sizeof( * V_105 ) + sizeof( V_105 -> V_102 [ 0 ] ) * V_103 ,
V_106 ) ;
if ( ! V_105 )
return - V_107 ;
V_105 -> V_101 = V_101 ;
V_105 -> V_103 = V_103 ;
F_47 ( & V_105 -> V_108 , & V_4 -> V_109 ) ;
return 0 ;
}
static int F_48 ( struct V_98 * V_70 ,
struct V_3 * V_4 )
{
#ifdef F_49
const struct V_110 * V_5 = V_4 -> V_5 ;
unsigned int V_111 = 0 ;
unsigned int V_112 = 0 ;
unsigned int V_113 = 0 ;
unsigned int V_114 = 0 ;
unsigned int V_115 = 0 ;
unsigned int V_60 , V_54 , V_36 ;
enum V_49 V_18 ;
enum V_35 V_17 ;
int V_74 , V_41 ;
for ( V_74 = 0 ; V_74 < V_5 -> V_94 ; V_74 ++ ) {
void * V_19 = V_5 -> V_10 [ V_74 ] . V_19 ;
V_54 = F_15 ( V_19 ) ;
V_18 = F_9 ( V_19 ) ;
V_36 = F_12 ( V_19 ) ;
V_17 = F_7 ( V_19 ) ;
V_60 = F_17 ( V_19 ) ;
switch ( V_18 ) {
case V_25 :
V_111 = F_50 ( V_111 , V_54 + 1 ) ;
break;
case V_26 :
V_112 = F_50 ( V_112 , V_54 + 1 ) ;
break;
case V_27 :
V_113 = F_50 ( V_113 , V_54 + 1 ) ;
break;
default:
break;
}
if ( V_17 == V_20 ||
V_17 == V_21 )
V_114 = F_50 ( V_114 , V_36 + 1 ) ;
if ( V_60 != V_61 ) {
if ( V_5 -> V_62 & V_63 )
V_60 = V_74 ;
V_115 = F_50 ( V_115 , V_60 + 1 ) ;
}
}
F_51 ( & V_4 -> V_109 ) ;
V_41 = F_44 ( V_70 , V_4 ,
V_84 ,
V_5 -> V_94 , 8 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_44 ( V_70 , V_4 ,
V_57 ,
V_111 , 1 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_44 ( V_70 , V_4 ,
V_58 ,
V_112 , 2 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_44 ( V_70 , V_4 ,
V_59 ,
V_113 , 3 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_44 ( V_70 , V_4 ,
V_46 ,
V_114 , 1 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_44 ( V_70 , V_4 ,
V_64 ,
V_115 , 1 ) ;
if ( V_41 )
return V_41 ;
#endif
return 0 ;
}
int F_52 ( struct V_116 * V_117 ,
struct V_110 * V_5 )
{
struct V_98 * V_70 = & V_117 -> V_70 ;
struct V_3 * V_4 ;
struct V_118 * V_119 ;
int V_41 ;
if ( ! V_5 ||
! V_5 -> V_10 || ! V_5 -> V_94 ||
! V_5 -> V_8 || ! V_5 -> V_6 ||
! V_5 -> V_76 || ! V_5 -> V_75 ) {
F_23 ( V_70 , L_22 ) ;
return - V_43 ;
}
V_4 = F_46 ( V_70 , sizeof( * V_4 ) , V_106 ) ;
if ( ! V_4 )
return - V_107 ;
V_119 = F_53 ( V_70 -> V_120 ) ;
V_4 -> V_47 = F_54 ( V_119 ) ;
F_55 ( V_119 ) ;
if ( F_56 ( V_4 -> V_47 ) ) {
F_23 ( V_70 , L_23 ) ;
return F_57 ( V_4 -> V_47 ) ;
}
V_4 -> V_5 = V_5 ;
V_4 -> V_121 . V_9 = V_70 -> V_122 -> V_9 ;
V_4 -> V_121 . V_10 = V_5 -> V_10 ;
V_4 -> V_121 . V_94 = V_5 -> V_94 ;
V_4 -> V_121 . V_123 = & V_124 ;
V_4 -> V_121 . V_125 = & V_126 ;
V_4 -> V_121 . V_127 = & V_128 ;
V_4 -> V_121 . V_129 = V_70 -> V_122 -> V_129 ;
V_41 = F_48 ( V_70 , V_4 ) ;
if ( V_41 )
return V_41 ;
V_4 -> V_2 = F_58 ( V_70 , & V_4 -> V_121 , V_4 ) ;
if ( F_56 ( V_4 -> V_2 ) ) {
F_23 ( V_70 , L_24 ) ;
return F_57 ( V_4 -> V_2 ) ;
}
F_59 ( V_117 , V_4 ) ;
return 0 ;
}
