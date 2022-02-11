static inline void F_1 ( struct V_1 * V_2 , const T_1 V_3 ,
const T_1 V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , const T_1 V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static bool F_5 ( struct V_1 * V_2 )
{
return ! ! ( ( F_3 ( V_2 , V_6 ) & V_7 ) == V_8 ) ;
}
static void F_6 ( struct V_9 * V_10 )
{
T_2 V_11 , V_12 ;
struct V_1 * V_2 = V_10 -> V_13 -> V_14 ;
int V_15 = 0 ;
if ( ! F_5 ( V_2 ) )
return;
F_7 ( V_10 , V_16 , & V_11 ) ;
if ( ( V_11 & V_17 ) <= V_18 )
return;
F_7 ( V_10 , V_19 , & V_12 ) ;
if ( ( V_12 & V_20 ) == V_21 ) {
F_8 ( V_10 , V_22 ,
V_23 ) ;
while ( ! F_5 ( V_2 ) ) {
V_15 ++ ;
if ( V_15 > V_24 )
break;
F_9 ( 5 ) ;
}
}
}
static bool F_10 ( struct V_25 * V_13 , unsigned int V_26 ,
int V_27 )
{
if ( F_11 ( V_13 ) && ( V_26 == 0 ) &&
( V_27 == V_28 ) )
return true ;
return false ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
F_1 ( V_2 , V_30 -> V_31 , V_32 ) ;
F_1 ( V_2 , V_30 -> V_33 , V_34 ) ;
F_1 ( V_2 , V_30 -> V_35 , V_36 ) ;
}
static bool F_13 ( struct V_1 * V_2 ,
struct V_25 * V_13 , int V_10 )
{
if ( V_13 -> V_37 != V_2 -> V_38 ) {
if ( ! F_5 ( V_2 ) )
return false ;
}
if ( V_13 -> V_37 == V_2 -> V_38 && V_10 > 0 )
return false ;
if ( V_13 -> V_39 == V_2 -> V_38 && V_10 > 0 )
return false ;
return true ;
}
static int F_14 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_40 ;
bool V_41 = 0 ;
T_1 V_35 ;
T_1 V_31 , V_33 ;
T_1 V_42 = 1 ;
for ( V_40 = 0 ; V_40 < V_43 ; V_40 ++ ) {
V_35 = F_3 ( V_2 , V_44 ) ;
if ( ( V_35 & V_45 ) || ( V_35 & V_46 ) || V_41 ) {
V_31 = F_3 ( V_2 , V_47 ) ;
V_33 = F_3 ( V_2 , V_48 ) ;
if ( V_35 & V_45 ) {
V_41 = true ;
V_42 = F_15 ( V_33 ) ;
}
if ( V_35 & V_46 ) {
if ( V_42 )
return V_49 ;
if ( V_3 )
* V_3 = V_31 ;
return V_50 ;
}
}
F_9 ( 5 ) ;
}
return V_49 ;
}
static void F_16 ( struct V_1 * V_2 , T_1 * V_51 ,
T_1 V_52 , bool V_53 )
{
struct V_29 V_30 ;
V_30 . V_31 = V_51 [ 0 ] ;
V_30 . V_33 = V_51 [ 1 ] ;
V_30 . V_35 = V_54 ;
F_12 ( V_2 , & V_30 ) ;
if ( V_53 ) {
V_30 . V_31 = V_51 [ 2 ] ;
V_30 . V_33 = 0 ;
V_30 . V_35 = 0 ;
F_12 ( V_2 , & V_30 ) ;
V_30 . V_31 = V_52 ;
V_30 . V_33 = 0 ;
} else {
V_30 . V_31 = V_51 [ 2 ] ;
V_30 . V_33 = V_52 ;
}
V_30 . V_35 = V_55 ;
F_12 ( V_2 , & V_30 ) ;
}
static int F_17 ( struct V_1 * V_2 , T_3 V_13 , T_1 V_26 ,
int V_56 , T_3 V_57 , T_1 * V_3 )
{
T_1 V_51 [ V_58 ] ;
if ( V_13 == V_2 -> V_38 )
V_51 [ 0 ] = F_18 ( V_59 ) ;
else
V_51 [ 0 ] = F_18 ( V_60 ) ;
V_51 [ 1 ] = F_19 ( F_20 ( V_2 -> V_38 , V_61 ) ,
V_62 , V_57 ) ;
V_51 [ 2 ] = F_21 ( V_13 , V_26 , V_56 ) ;
F_16 ( V_2 , V_51 , 0 , false ) ;
return F_14 ( V_2 , V_3 ) ;
}
static int F_22 ( struct V_1 * V_2 , T_3 V_13 , T_1 V_26 ,
int V_56 , T_3 V_57 , T_1 V_3 )
{
T_1 V_51 [ V_58 ] ;
int V_63 ;
if ( V_13 == V_2 -> V_38 )
V_51 [ 0 ] = F_18 ( V_64 ) ;
else
V_51 [ 0 ] = F_18 ( V_65 ) ;
V_51 [ 1 ] = F_19 ( F_20 ( V_2 -> V_38 , V_61 ) ,
V_66 , V_57 ) ;
V_51 [ 2 ] = F_21 ( V_13 , V_26 , V_56 ) ;
if ( ( V_56 & 0x7 ) == 0 )
F_16 ( V_2 , V_51 , V_3 , true ) ;
else
F_16 ( V_2 , V_51 , V_3 , false ) ;
V_63 = F_14 ( V_2 , NULL ) ;
if ( V_63 != V_50 )
return V_63 ;
if ( ( V_13 == V_2 -> V_38 ) && ( V_56 == V_67 ) )
V_2 -> V_38 = ( T_3 ) ( V_3 ) ;
return V_50 ;
}
static int F_23 ( struct V_25 * V_13 , unsigned int V_26 ,
int V_56 , int V_68 , T_1 * V_3 )
{
struct V_1 * V_2 = V_13 -> V_14 ;
int V_63 ;
T_1 V_52 ;
T_3 V_57 ;
if ( F_10 ( V_13 , V_26 , V_56 ) )
return V_69 ;
if ( ! F_13 ( V_2 , V_13 , F_24 ( V_26 ) ) ) {
* V_3 = 0xffffffff ;
return V_49 ;
}
switch ( V_68 ) {
case 1 :
V_57 = 1 << ( V_56 & 3 ) ;
break;
case 2 :
V_57 = 3 << ( V_56 & 3 ) ;
break;
default:
V_57 = 0xf ;
break;
}
V_63 = F_17 ( V_2 , V_13 -> V_37 , V_26 ,
( V_56 & ~ V_70 ) , V_57 , & V_52 ) ;
if ( V_63 != V_50 )
return V_63 ;
switch ( V_68 ) {
case 1 :
* V_3 = ( V_52 >> ( 8 * ( V_56 & 0x3 ) ) ) & 0xff ;
break;
case 2 :
* V_3 = ( V_52 >> ( 8 * ( V_56 & 0x2 ) ) ) & 0xffff ;
break;
default:
* V_3 = V_52 ;
break;
}
return V_50 ;
}
static int F_25 ( struct V_25 * V_13 , unsigned int V_26 ,
int V_56 , int V_68 , T_1 V_3 )
{
struct V_1 * V_2 = V_13 -> V_14 ;
T_1 V_71 ;
T_1 V_72 = 8 * ( V_56 & 3 ) ;
T_3 V_57 ;
if ( F_10 ( V_13 , V_26 , V_56 ) )
return V_69 ;
if ( ! F_13 ( V_2 , V_13 , F_24 ( V_26 ) ) )
return V_49 ;
switch ( V_68 ) {
case 1 :
V_71 = ( V_3 & 0xff ) << V_72 ;
V_57 = 1 << ( V_56 & 3 ) ;
break;
case 2 :
V_71 = ( V_3 & 0xffff ) << V_72 ;
V_57 = 3 << ( V_56 & 3 ) ;
break;
default:
V_71 = V_3 ;
V_57 = 0xf ;
break;
}
return F_22 ( V_2 , V_13 -> V_37 , V_26 ,
( V_56 & ~ V_70 ) , V_57 , V_71 ) ;
}
static int F_26 ( struct V_73 * V_74 , unsigned int V_75 ,
T_4 V_76 )
{
F_27 ( V_75 , & V_77 , V_78 ) ;
F_28 ( V_75 , V_74 -> V_79 ) ;
return 0 ;
}
static void F_29 ( struct V_80 * V_81 )
{
struct V_82 * V_83 = F_30 ( V_81 ) ;
struct V_1 * V_2 ;
unsigned long V_84 ;
T_1 V_85 ;
T_1 V_86 ;
F_31 ( V_83 , V_81 ) ;
V_2 = F_32 ( V_81 ) ;
while ( ( V_84 = F_3 ( V_2 , V_87 )
& V_88 ) != 0 ) {
F_33 (bit, &status, INTX_NUM) {
F_1 ( V_2 , 1 << V_85 , V_87 ) ;
V_86 = F_34 ( V_2 -> V_73 , V_85 + 1 ) ;
if ( V_86 )
F_35 ( V_86 ) ;
else
F_36 ( & V_2 -> V_89 -> V_10 ,
L_1 , V_85 ) ;
}
}
F_37 ( V_83 , V_81 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
int V_90 , V_91 = 0 ;
struct V_92 * V_10 = & V_2 -> V_89 -> V_10 ;
struct V_93 * V_94 = V_10 -> V_95 ;
struct V_96 * V_97 ;
V_90 = F_39 ( V_94 , 0 , 0xff , & V_2 -> V_98 ,
NULL ) ;
if ( V_90 )
return V_90 ;
V_90 = F_40 ( V_10 , & V_2 -> V_98 ) ;
if ( V_90 )
goto V_99;
F_41 (win, &pcie->resources) {
struct V_100 * V_101 = V_97 -> V_101 ;
if ( F_42 ( V_101 ) == V_102 )
V_91 |= ! ( V_101 -> V_103 & V_104 ) ;
}
if ( V_91 )
return 0 ;
F_36 ( V_10 , L_2 ) ;
V_90 = - V_105 ;
V_99:
F_43 ( & V_2 -> V_98 ) ;
return V_90 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_92 * V_10 = & V_2 -> V_89 -> V_10 ;
struct V_93 * V_106 = V_10 -> V_95 ;
V_2 -> V_73 = F_45 ( V_106 , V_107 + 1 ,
& V_108 , V_2 ) ;
if ( ! V_2 -> V_73 ) {
F_36 ( V_10 , L_3 ) ;
return - V_109 ;
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_100 * V_110 ;
struct V_111 * V_89 = V_2 -> V_89 ;
V_110 = F_47 ( V_89 , V_102 , L_4 ) ;
if ( ! V_110 ) {
F_36 ( & V_89 -> V_10 , L_5 ) ;
return - V_112 ;
}
V_2 -> V_5 = F_48 ( & V_89 -> V_10 , V_110 ) ;
if ( F_49 ( V_2 -> V_5 ) ) {
F_36 ( & V_89 -> V_10 , L_6 ) ;
return F_50 ( V_2 -> V_5 ) ;
}
V_2 -> V_75 = F_51 ( V_89 , 0 ) ;
if ( V_2 -> V_75 <= 0 ) {
F_36 ( & V_89 -> V_10 , L_7 , V_2 -> V_75 ) ;
return - V_105 ;
}
F_52 ( V_2 -> V_75 , F_29 , V_2 ) ;
return 0 ;
}
static int F_53 ( struct V_111 * V_89 )
{
struct V_1 * V_2 ;
struct V_25 * V_13 ;
struct V_25 * V_113 ;
int V_63 ;
V_2 = F_54 ( & V_89 -> V_10 , sizeof( * V_2 ) , V_114 ) ;
if ( ! V_2 )
return - V_109 ;
V_2 -> V_89 = V_89 ;
V_63 = F_46 ( V_2 ) ;
if ( V_63 ) {
F_36 ( & V_89 -> V_10 , L_8 ) ;
return V_63 ;
}
F_55 ( & V_2 -> V_98 ) ;
V_63 = F_38 ( V_2 ) ;
if ( V_63 ) {
F_36 ( & V_89 -> V_10 , L_9 ) ;
return V_63 ;
}
V_63 = F_44 ( V_2 ) ;
if ( V_63 ) {
F_36 ( & V_89 -> V_10 , L_10 ) ;
return V_63 ;
}
F_1 ( V_2 , V_88 , V_87 ) ;
F_1 ( V_2 , V_115 , V_116 ) ;
V_13 = F_56 ( & V_89 -> V_10 , V_2 -> V_38 , & V_117 ,
V_2 , & V_2 -> V_98 ) ;
if ( ! V_13 )
return - V_109 ;
F_57 ( V_118 , V_119 ) ;
F_58 ( V_13 ) ;
F_59 (child, &bus->children, node)
F_60 ( V_113 ) ;
F_61 ( V_13 ) ;
F_62 ( V_89 , V_2 ) ;
return V_63 ;
}
static int F_63 ( void )
{
return F_64 ( & V_120 ) ;
}
