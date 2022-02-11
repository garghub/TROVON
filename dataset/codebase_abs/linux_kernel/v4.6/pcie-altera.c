static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 , V_4 ;
F_2 ( V_2 , V_5 , & V_3 ) ;
if ( ( V_3 & V_6 ) <= V_7 )
return;
F_2 ( V_2 , V_8 , & V_4 ) ;
if ( ( V_4 & V_9 ) == V_10 )
F_3 ( V_2 , V_11 ,
V_12 ) ;
}
static bool F_4 ( struct V_13 * V_14 , unsigned int V_15 ,
int V_16 )
{
if ( F_5 ( V_14 ) && ( V_15 == 0 ) &&
( V_16 == V_17 ) )
return true ;
return false ;
}
static inline void F_6 ( struct V_18 * V_19 , const T_2 V_20 ,
const T_2 V_21 )
{
F_7 ( V_20 , V_19 -> V_22 + V_21 ) ;
}
static inline T_2 F_8 ( struct V_18 * V_19 , const T_2 V_21 )
{
return F_9 ( V_19 -> V_22 + V_21 ) ;
}
static void F_10 ( struct V_18 * V_19 ,
struct V_23 * V_24 )
{
F_6 ( V_19 , V_24 -> V_25 , V_26 ) ;
F_6 ( V_19 , V_24 -> V_27 , V_28 ) ;
F_6 ( V_19 , V_24 -> V_29 , V_30 ) ;
}
static bool F_11 ( struct V_18 * V_19 )
{
return ! ! ( ( F_8 ( V_19 , V_31 ) & V_32 ) == V_33 ) ;
}
static bool F_12 ( struct V_18 * V_19 ,
struct V_13 * V_14 , int V_2 )
{
if ( V_14 -> V_34 != V_19 -> V_35 ) {
if ( ! F_11 ( V_19 ) )
return false ;
}
if ( V_14 -> V_34 == V_19 -> V_35 && V_2 > 0 )
return false ;
if ( V_14 -> V_36 == V_19 -> V_35 && V_2 > 0 )
return false ;
return true ;
}
static int F_13 ( struct V_18 * V_19 , T_2 * V_20 )
{
int V_37 ;
bool V_38 = 0 ;
T_2 V_29 ;
T_2 V_25 , V_27 ;
T_2 V_39 = 1 ;
for ( V_37 = 0 ; V_37 < V_40 ; V_37 ++ ) {
V_29 = F_8 ( V_19 , V_41 ) ;
if ( ( V_29 & V_42 ) || ( V_29 & V_43 ) || V_38 ) {
V_25 = F_8 ( V_19 , V_44 ) ;
V_27 = F_8 ( V_19 , V_45 ) ;
if ( V_29 & V_42 ) {
V_38 = true ;
V_39 = F_14 ( V_27 ) ;
}
if ( V_29 & V_43 ) {
if ( V_39 )
return V_46 ;
if ( V_20 )
* V_20 = V_25 ;
return V_47 ;
}
}
F_15 ( 5 ) ;
}
return V_46 ;
}
static void F_16 ( struct V_18 * V_19 , T_2 * V_48 ,
T_2 V_49 , bool V_50 )
{
struct V_23 V_24 ;
V_24 . V_25 = V_48 [ 0 ] ;
V_24 . V_27 = V_48 [ 1 ] ;
V_24 . V_29 = V_51 ;
F_10 ( V_19 , & V_24 ) ;
if ( V_50 ) {
V_24 . V_25 = V_48 [ 2 ] ;
V_24 . V_27 = 0 ;
V_24 . V_29 = 0 ;
F_10 ( V_19 , & V_24 ) ;
V_24 . V_25 = V_49 ;
V_24 . V_27 = 0 ;
} else {
V_24 . V_25 = V_48 [ 2 ] ;
V_24 . V_27 = V_49 ;
}
V_24 . V_29 = V_52 ;
F_10 ( V_19 , & V_24 ) ;
}
static int F_17 ( struct V_18 * V_19 , T_3 V_14 , T_2 V_15 ,
int V_53 , T_3 V_54 , T_2 * V_20 )
{
T_2 V_48 [ V_55 ] ;
if ( V_14 == V_19 -> V_35 )
V_48 [ 0 ] = F_18 ( V_56 ) ;
else
V_48 [ 0 ] = F_18 ( V_57 ) ;
V_48 [ 1 ] = F_19 ( F_20 ( V_19 -> V_35 , V_58 ) ,
V_59 , V_54 ) ;
V_48 [ 2 ] = F_21 ( V_14 , V_15 , V_53 ) ;
F_16 ( V_19 , V_48 , 0 , false ) ;
return F_13 ( V_19 , V_20 ) ;
}
static int F_22 ( struct V_18 * V_19 , T_3 V_14 , T_2 V_15 ,
int V_53 , T_3 V_54 , T_2 V_20 )
{
T_2 V_48 [ V_55 ] ;
int V_60 ;
if ( V_14 == V_19 -> V_35 )
V_48 [ 0 ] = F_18 ( V_61 ) ;
else
V_48 [ 0 ] = F_18 ( V_62 ) ;
V_48 [ 1 ] = F_19 ( F_20 ( V_19 -> V_35 , V_58 ) ,
V_63 , V_54 ) ;
V_48 [ 2 ] = F_21 ( V_14 , V_15 , V_53 ) ;
if ( ( V_53 & 0x7 ) == 0 )
F_16 ( V_19 , V_48 , V_20 , true ) ;
else
F_16 ( V_19 , V_48 , V_20 , false ) ;
V_60 = F_13 ( V_19 , NULL ) ;
if ( V_60 != V_47 )
return V_60 ;
if ( ( V_14 == V_19 -> V_35 ) && ( V_53 == V_64 ) )
V_19 -> V_35 = ( T_3 ) ( V_20 ) ;
return V_47 ;
}
static int F_23 ( struct V_13 * V_14 , unsigned int V_15 ,
int V_53 , int V_65 , T_2 * V_20 )
{
struct V_18 * V_19 = V_14 -> V_66 ;
int V_60 ;
T_2 V_49 ;
T_3 V_54 ;
if ( F_4 ( V_14 , V_15 , V_53 ) )
return V_67 ;
if ( ! F_12 ( V_19 , V_14 , F_24 ( V_15 ) ) ) {
* V_20 = 0xffffffff ;
return V_46 ;
}
switch ( V_65 ) {
case 1 :
V_54 = 1 << ( V_53 & 3 ) ;
break;
case 2 :
V_54 = 3 << ( V_53 & 3 ) ;
break;
default:
V_54 = 0xf ;
break;
}
V_60 = F_17 ( V_19 , V_14 -> V_34 , V_15 ,
( V_53 & ~ V_68 ) , V_54 , & V_49 ) ;
if ( V_60 != V_47 )
return V_60 ;
switch ( V_65 ) {
case 1 :
* V_20 = ( V_49 >> ( 8 * ( V_53 & 0x3 ) ) ) & 0xff ;
break;
case 2 :
* V_20 = ( V_49 >> ( 8 * ( V_53 & 0x2 ) ) ) & 0xffff ;
break;
default:
* V_20 = V_49 ;
break;
}
return V_47 ;
}
static int F_25 ( struct V_13 * V_14 , unsigned int V_15 ,
int V_53 , int V_65 , T_2 V_20 )
{
struct V_18 * V_19 = V_14 -> V_66 ;
T_2 V_69 ;
T_2 V_70 = 8 * ( V_53 & 3 ) ;
T_3 V_54 ;
if ( F_4 ( V_14 , V_15 , V_53 ) )
return V_67 ;
if ( ! F_12 ( V_19 , V_14 , F_24 ( V_15 ) ) )
return V_46 ;
switch ( V_65 ) {
case 1 :
V_69 = ( V_20 & 0xff ) << V_70 ;
V_54 = 1 << ( V_53 & 3 ) ;
break;
case 2 :
V_69 = ( V_20 & 0xffff ) << V_70 ;
V_54 = 3 << ( V_53 & 3 ) ;
break;
default:
V_69 = V_20 ;
V_54 = 0xf ;
break;
}
return F_22 ( V_19 , V_14 -> V_34 , V_15 ,
( V_53 & ~ V_68 ) , V_54 , V_69 ) ;
}
static int F_26 ( struct V_71 * V_72 , unsigned int V_73 ,
T_4 V_74 )
{
F_27 ( V_73 , & V_75 , V_76 ) ;
F_28 ( V_73 , V_72 -> V_77 ) ;
return 0 ;
}
static void F_29 ( struct V_78 * V_79 )
{
struct V_80 * V_81 = F_30 ( V_79 ) ;
struct V_18 * V_19 ;
unsigned long V_82 ;
T_2 V_83 ;
T_2 V_84 ;
F_31 ( V_81 , V_79 ) ;
V_19 = F_32 ( V_79 ) ;
while ( ( V_82 = F_8 ( V_19 , V_85 )
& V_86 ) != 0 ) {
F_33 (bit, &status, INTX_NUM) {
F_6 ( V_19 , 1 << V_83 , V_85 ) ;
V_84 = F_34 ( V_19 -> V_71 , V_83 + 1 ) ;
if ( V_84 )
F_35 ( V_84 ) ;
else
F_36 ( & V_19 -> V_87 -> V_2 ,
L_1 , V_83 ) ;
}
}
F_37 ( V_81 , V_79 ) ;
}
static void F_38 ( struct V_18 * V_19 )
{
F_39 ( & V_19 -> V_88 ) ;
}
static int F_40 ( struct V_18 * V_19 )
{
int V_89 , V_90 = 0 ;
struct V_91 * V_2 = & V_19 -> V_87 -> V_2 ;
struct V_92 * V_93 = V_2 -> V_94 ;
struct V_95 * V_96 ;
V_89 = F_41 ( V_93 , 0 , 0xff , & V_19 -> V_88 ,
NULL ) ;
if ( V_89 )
return V_89 ;
F_42 (win, &pcie->resources) {
struct V_97 * V_98 , * V_99 = V_96 -> V_99 ;
switch ( F_43 ( V_99 ) ) {
case V_100 :
V_98 = & V_101 ;
V_90 |= ! ( V_99 -> V_102 & V_103 ) ;
break;
default:
continue;
}
V_89 = F_44 ( V_2 , V_98 , V_99 ) ;
if ( V_89 )
goto V_104;
}
if ( ! V_90 ) {
F_36 ( V_2 , L_2 ) ;
V_89 = - V_105 ;
goto V_104;
}
return 0 ;
V_104:
F_38 ( V_19 ) ;
return V_89 ;
}
static int F_45 ( struct V_18 * V_19 )
{
struct V_91 * V_2 = & V_19 -> V_87 -> V_2 ;
struct V_92 * V_106 = V_2 -> V_94 ;
V_19 -> V_71 = F_46 ( V_106 , V_107 + 1 ,
& V_108 , V_19 ) ;
if ( ! V_19 -> V_71 ) {
F_36 ( V_2 , L_3 ) ;
return - V_109 ;
}
return 0 ;
}
static int F_47 ( struct V_18 * V_19 )
{
struct V_97 * V_110 ;
struct V_111 * V_87 = V_19 -> V_87 ;
V_110 = F_48 ( V_87 , V_100 , L_4 ) ;
if ( ! V_110 ) {
F_36 ( & V_87 -> V_2 , L_5 ) ;
return - V_112 ;
}
V_19 -> V_22 = F_49 ( & V_87 -> V_2 , V_110 ) ;
if ( F_50 ( V_19 -> V_22 ) ) {
F_36 ( & V_87 -> V_2 , L_6 ) ;
return F_51 ( V_19 -> V_22 ) ;
}
V_19 -> V_73 = F_52 ( V_87 , 0 ) ;
if ( V_19 -> V_73 <= 0 ) {
F_36 ( & V_87 -> V_2 , L_7 , V_19 -> V_73 ) ;
return - V_105 ;
}
F_53 ( V_19 -> V_73 , F_29 , V_19 ) ;
return 0 ;
}
static int F_54 ( struct V_111 * V_87 )
{
struct V_18 * V_19 ;
struct V_13 * V_14 ;
struct V_13 * V_113 ;
int V_60 ;
V_19 = F_55 ( & V_87 -> V_2 , sizeof( * V_19 ) , V_114 ) ;
if ( ! V_19 )
return - V_109 ;
V_19 -> V_87 = V_87 ;
V_60 = F_47 ( V_19 ) ;
if ( V_60 ) {
F_36 ( & V_87 -> V_2 , L_8 ) ;
return V_60 ;
}
F_56 ( & V_19 -> V_88 ) ;
V_60 = F_40 ( V_19 ) ;
if ( V_60 ) {
F_36 ( & V_87 -> V_2 , L_9 ) ;
return V_60 ;
}
V_60 = F_45 ( V_19 ) ;
if ( V_60 ) {
F_36 ( & V_87 -> V_2 , L_10 ) ;
return V_60 ;
}
F_6 ( V_19 , V_86 , V_85 ) ;
F_6 ( V_19 , V_115 , V_116 ) ;
V_14 = F_57 ( & V_87 -> V_2 , V_19 -> V_35 , & V_117 ,
V_19 , & V_19 -> V_88 ) ;
if ( ! V_14 )
return - V_109 ;
F_58 ( V_118 , V_119 ) ;
F_59 ( V_14 ) ;
F_60 (child, &bus->children, node)
F_61 ( V_113 ) ;
F_62 ( V_14 ) ;
F_63 ( V_87 , V_19 ) ;
return V_60 ;
}
static int F_64 ( void )
{
return F_65 ( & V_120 ) ;
}
