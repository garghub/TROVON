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
return ! ! ( F_8 ( V_19 , V_31 ) & V_32 ) ;
}
static bool F_12 ( struct V_18 * V_19 ,
struct V_13 * V_14 , int V_2 )
{
if ( V_14 -> V_33 != V_19 -> V_34 ) {
if ( ! F_11 ( V_19 ) )
return false ;
}
if ( V_14 -> V_33 == V_19 -> V_34 && V_2 > 0 )
return false ;
if ( V_14 -> V_35 == V_19 -> V_34 && V_2 > 0 )
return false ;
return true ;
}
static int F_13 ( struct V_18 * V_19 , T_2 * V_20 )
{
int V_36 ;
bool V_37 = 0 ;
T_2 V_29 ;
T_2 V_25 , V_27 ;
T_2 V_38 = 1 ;
for ( V_36 = 0 ; V_36 < V_39 ; V_36 ++ ) {
V_29 = F_8 ( V_19 , V_40 ) ;
if ( ( V_29 & V_41 ) || ( V_29 & V_42 ) || V_37 ) {
V_25 = F_8 ( V_19 , V_43 ) ;
V_27 = F_8 ( V_19 , V_44 ) ;
if ( V_29 & V_41 ) {
V_37 = true ;
V_38 = F_14 ( V_27 ) ;
}
if ( V_29 & V_42 ) {
if ( V_38 )
return V_45 ;
if ( V_20 )
* V_20 = V_25 ;
return V_46 ;
}
}
F_15 ( 5 ) ;
}
return V_45 ;
}
static void F_16 ( struct V_18 * V_19 , T_2 * V_47 ,
T_2 V_48 , bool V_49 )
{
struct V_23 V_24 ;
V_24 . V_25 = V_47 [ 0 ] ;
V_24 . V_27 = V_47 [ 1 ] ;
V_24 . V_29 = V_50 ;
F_10 ( V_19 , & V_24 ) ;
if ( V_49 ) {
V_24 . V_25 = V_47 [ 2 ] ;
V_24 . V_27 = 0 ;
V_24 . V_29 = 0 ;
F_10 ( V_19 , & V_24 ) ;
V_24 . V_25 = V_48 ;
V_24 . V_27 = 0 ;
} else {
V_24 . V_25 = V_47 [ 2 ] ;
V_24 . V_27 = V_48 ;
}
V_24 . V_29 = V_51 ;
F_10 ( V_19 , & V_24 ) ;
}
static int F_17 ( struct V_18 * V_19 , T_3 V_14 , T_2 V_15 ,
int V_52 , T_3 V_53 , T_2 * V_20 )
{
T_2 V_47 [ V_54 ] ;
if ( V_14 == V_19 -> V_34 )
V_47 [ 0 ] = F_18 ( V_55 ) ;
else
V_47 [ 0 ] = F_18 ( V_56 ) ;
V_47 [ 1 ] = F_19 ( F_20 ( V_19 -> V_34 , V_57 ) ,
V_58 , V_53 ) ;
V_47 [ 2 ] = F_21 ( V_14 , V_15 , V_52 ) ;
F_16 ( V_19 , V_47 , 0 , false ) ;
return F_13 ( V_19 , V_20 ) ;
}
static int F_22 ( struct V_18 * V_19 , T_3 V_14 , T_2 V_15 ,
int V_52 , T_3 V_53 , T_2 V_20 )
{
T_2 V_47 [ V_54 ] ;
int V_59 ;
if ( V_14 == V_19 -> V_34 )
V_47 [ 0 ] = F_18 ( V_60 ) ;
else
V_47 [ 0 ] = F_18 ( V_61 ) ;
V_47 [ 1 ] = F_19 ( F_20 ( V_19 -> V_34 , V_57 ) ,
V_62 , V_53 ) ;
V_47 [ 2 ] = F_21 ( V_14 , V_15 , V_52 ) ;
if ( ( V_52 & 0x7 ) == 0 )
F_16 ( V_19 , V_47 , V_20 , true ) ;
else
F_16 ( V_19 , V_47 , V_20 , false ) ;
V_59 = F_13 ( V_19 , NULL ) ;
if ( V_59 != V_46 )
return V_59 ;
if ( ( V_14 == V_19 -> V_34 ) && ( V_52 == V_63 ) )
V_19 -> V_34 = ( T_3 ) ( V_20 ) ;
return V_46 ;
}
static int F_23 ( struct V_13 * V_14 , unsigned int V_15 ,
int V_52 , int V_64 , T_2 * V_20 )
{
struct V_18 * V_19 = V_14 -> V_65 ;
int V_59 ;
T_2 V_48 ;
T_3 V_53 ;
if ( F_4 ( V_14 , V_15 , V_52 ) )
return V_66 ;
if ( ! F_12 ( V_19 , V_14 , F_24 ( V_15 ) ) ) {
* V_20 = 0xffffffff ;
return V_45 ;
}
switch ( V_64 ) {
case 1 :
V_53 = 1 << ( V_52 & 3 ) ;
break;
case 2 :
V_53 = 3 << ( V_52 & 3 ) ;
break;
default:
V_53 = 0xf ;
break;
}
V_59 = F_17 ( V_19 , V_14 -> V_33 , V_15 ,
( V_52 & ~ V_67 ) , V_53 , & V_48 ) ;
if ( V_59 != V_46 )
return V_59 ;
switch ( V_64 ) {
case 1 :
* V_20 = ( V_48 >> ( 8 * ( V_52 & 0x3 ) ) ) & 0xff ;
break;
case 2 :
* V_20 = ( V_48 >> ( 8 * ( V_52 & 0x2 ) ) ) & 0xffff ;
break;
default:
* V_20 = V_48 ;
break;
}
return V_46 ;
}
static int F_25 ( struct V_13 * V_14 , unsigned int V_15 ,
int V_52 , int V_64 , T_2 V_20 )
{
struct V_18 * V_19 = V_14 -> V_65 ;
T_2 V_68 ;
T_2 V_69 = 8 * ( V_52 & 3 ) ;
T_3 V_53 ;
if ( F_4 ( V_14 , V_15 , V_52 ) )
return V_66 ;
if ( ! F_12 ( V_19 , V_14 , F_24 ( V_15 ) ) )
return V_45 ;
switch ( V_64 ) {
case 1 :
V_68 = ( V_20 & 0xff ) << V_69 ;
V_53 = 1 << ( V_52 & 3 ) ;
break;
case 2 :
V_68 = ( V_20 & 0xffff ) << V_69 ;
V_53 = 3 << ( V_52 & 3 ) ;
break;
default:
V_68 = V_20 ;
V_53 = 0xf ;
break;
}
return F_22 ( V_19 , V_14 -> V_33 , V_15 ,
( V_52 & ~ V_67 ) , V_53 , V_68 ) ;
}
static int F_26 ( struct V_70 * V_71 , unsigned int V_72 ,
T_4 V_73 )
{
F_27 ( V_72 , & V_74 , V_75 ) ;
F_28 ( V_72 , V_71 -> V_76 ) ;
return 0 ;
}
static void F_29 ( struct V_77 * V_78 )
{
struct V_79 * V_80 = F_30 ( V_78 ) ;
struct V_18 * V_19 ;
unsigned long V_81 ;
T_2 V_82 ;
T_2 V_83 ;
F_31 ( V_80 , V_78 ) ;
V_19 = F_32 ( V_78 ) ;
while ( ( V_81 = F_8 ( V_19 , V_84 )
& V_85 ) != 0 ) {
F_33 (bit, &status, INTX_NUM) {
F_6 ( V_19 , 1 << V_82 , V_84 ) ;
V_83 = F_34 ( V_19 -> V_70 , V_82 + 1 ) ;
if ( V_83 )
F_35 ( V_83 ) ;
else
F_36 ( & V_19 -> V_86 -> V_2 ,
L_1 , V_82 ) ;
}
}
F_37 ( V_80 , V_78 ) ;
}
static void F_38 ( struct V_18 * V_19 )
{
F_39 ( & V_19 -> V_87 ) ;
}
static int F_40 ( struct V_18 * V_19 )
{
int V_88 , V_89 = 0 ;
struct V_90 * V_2 = & V_19 -> V_86 -> V_2 ;
struct V_91 * V_92 = V_2 -> V_93 ;
struct V_94 * V_95 ;
V_88 = F_41 ( V_92 , 0 , 0xff , & V_19 -> V_87 ,
NULL ) ;
if ( V_88 )
return V_88 ;
F_42 (win, &pcie->resources) {
struct V_96 * V_97 , * V_98 = V_95 -> V_98 ;
switch ( F_43 ( V_98 ) ) {
case V_99 :
V_97 = & V_100 ;
V_89 |= ! ( V_98 -> V_101 & V_102 ) ;
break;
default:
continue;
}
V_88 = F_44 ( V_2 , V_97 , V_98 ) ;
if ( V_88 )
goto V_103;
}
if ( ! V_89 ) {
F_36 ( V_2 , L_2 ) ;
V_88 = - V_104 ;
goto V_103;
}
return 0 ;
V_103:
F_38 ( V_19 ) ;
return V_88 ;
}
static int F_45 ( struct V_18 * V_19 )
{
struct V_90 * V_2 = & V_19 -> V_86 -> V_2 ;
struct V_91 * V_105 = V_2 -> V_93 ;
V_19 -> V_70 = F_46 ( V_105 , V_106 + 1 ,
& V_107 , V_19 ) ;
if ( ! V_19 -> V_70 ) {
F_36 ( V_2 , L_3 ) ;
return - V_108 ;
}
return 0 ;
}
static int F_47 ( struct V_18 * V_19 )
{
struct V_96 * V_109 ;
struct V_110 * V_86 = V_19 -> V_86 ;
V_109 = F_48 ( V_86 , V_99 , L_4 ) ;
if ( ! V_109 ) {
F_36 ( & V_86 -> V_2 , L_5 ) ;
return - V_111 ;
}
V_19 -> V_22 = F_49 ( & V_86 -> V_2 , V_109 ) ;
if ( F_50 ( V_19 -> V_22 ) ) {
F_36 ( & V_86 -> V_2 , L_6 ) ;
return F_51 ( V_19 -> V_22 ) ;
}
V_19 -> V_72 = F_52 ( V_86 , 0 ) ;
if ( V_19 -> V_72 <= 0 ) {
F_36 ( & V_86 -> V_2 , L_7 , V_19 -> V_72 ) ;
return - V_104 ;
}
F_53 ( V_19 -> V_72 , F_29 , V_19 ) ;
return 0 ;
}
static int F_54 ( struct V_110 * V_86 )
{
struct V_18 * V_19 ;
struct V_13 * V_14 ;
struct V_13 * V_112 ;
int V_59 ;
V_19 = F_55 ( & V_86 -> V_2 , sizeof( * V_19 ) , V_113 ) ;
if ( ! V_19 )
return - V_108 ;
V_19 -> V_86 = V_86 ;
V_59 = F_47 ( V_19 ) ;
if ( V_59 ) {
F_36 ( & V_86 -> V_2 , L_8 ) ;
return V_59 ;
}
F_56 ( & V_19 -> V_87 ) ;
V_59 = F_40 ( V_19 ) ;
if ( V_59 ) {
F_36 ( & V_86 -> V_2 , L_9 ) ;
return V_59 ;
}
V_59 = F_45 ( V_19 ) ;
if ( V_59 ) {
F_36 ( & V_86 -> V_2 , L_10 ) ;
return V_59 ;
}
F_6 ( V_19 , V_85 , V_84 ) ;
F_6 ( V_19 , V_114 , V_115 ) ;
V_14 = F_57 ( & V_86 -> V_2 , V_19 -> V_34 , & V_116 ,
V_19 , & V_19 -> V_87 ) ;
if ( ! V_14 )
return - V_108 ;
F_58 ( V_117 , V_118 ) ;
F_59 ( V_14 ) ;
F_60 (child, &bus->children, node)
F_61 ( V_112 ) ;
F_62 ( V_14 ) ;
F_63 ( V_86 , V_19 ) ;
return V_59 ;
}
static int F_64 ( void )
{
return F_65 ( & V_119 ) ;
}
