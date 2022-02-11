static T_1 F_1 ( const T_1 V_1 [ V_2 ] , int V_3 )
{
return V_1 [ V_3 - V_4 ] ;
}
static T_1 F_2 ( const T_1 V_1 [ V_2 ] ,
int V_5 )
{
int V_6 = V_4 + ( V_5 >> 1 ) ;
int V_7 = ( V_5 & 1 ) * 4 ;
T_1 V_8 = F_1 ( V_1 , V_6 ) ;
return ( V_8 >> V_7 ) & 0xf ;
}
bool F_3 ( const T_1 V_1 [ V_2 ] ,
int V_9 )
{
T_1 V_10 ;
T_1 V_11 ;
int V_5 ;
V_10 = F_1 ( V_1 ,
V_12 ) ;
if ( ( V_10 & V_13 ) == 0 )
return false ;
for ( V_5 = 0 ; V_5 < V_9 ; V_5 ++ ) {
V_11 = F_2 ( V_1 , V_5 ) ;
if ( ( V_11 & V_14 ) != V_14 )
return false ;
}
return true ;
}
bool F_4 ( const T_1 V_1 [ V_2 ] ,
int V_9 )
{
int V_5 ;
T_1 V_11 ;
for ( V_5 = 0 ; V_5 < V_9 ; V_5 ++ ) {
V_11 = F_2 ( V_1 , V_5 ) ;
if ( ( V_11 & V_15 ) == 0 )
return false ;
}
return true ;
}
T_1 F_5 ( const T_1 V_1 [ V_2 ] ,
int V_5 )
{
int V_6 = V_16 + ( V_5 >> 1 ) ;
int V_7 = ( ( V_5 & 1 ) ?
V_17 :
V_18 ) ;
T_1 V_8 = F_1 ( V_1 , V_6 ) ;
return ( ( V_8 >> V_7 ) & 0x3 ) << V_19 ;
}
T_1 F_6 ( const T_1 V_1 [ V_2 ] ,
int V_5 )
{
int V_6 = V_16 + ( V_5 >> 1 ) ;
int V_7 = ( ( V_5 & 1 ) ?
V_20 :
V_21 ) ;
T_1 V_8 = F_1 ( V_1 , V_6 ) ;
return ( ( V_8 >> V_7 ) & 0x3 ) << V_22 ;
}
void F_7 ( const T_1 V_23 [ V_24 ] ) {
if ( V_23 [ V_25 ] == 0 )
F_8 ( 100 ) ;
else
F_9 ( V_23 [ V_25 ] * 4 ) ;
}
void F_10 ( const T_1 V_23 [ V_24 ] ) {
if ( V_23 [ V_25 ] == 0 )
F_8 ( 400 ) ;
else
F_9 ( V_23 [ V_25 ] * 4 ) ;
}
T_1 F_11 ( int V_26 )
{
switch ( V_26 ) {
case 162000 :
default:
return V_27 ;
case 270000 :
return V_28 ;
case 540000 :
return V_29 ;
}
}
int F_12 ( T_1 V_30 )
{
switch ( V_30 ) {
case V_27 :
default:
return 162000 ;
case V_28 :
return 270000 ;
case V_29 :
return 540000 ;
}
}
static int F_13 ( struct V_31 * V_32 , T_1 V_33 ,
unsigned int V_34 , void * V_35 , T_2 V_36 )
{
struct V_37 V_38 ;
unsigned int V_39 , V_40 ;
int V_41 = 0 , V_42 = 0 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_43 = V_34 ;
V_38 . V_33 = V_33 ;
V_38 . V_35 = V_35 ;
V_38 . V_36 = V_36 ;
F_14 ( & V_32 -> V_44 ) ;
for ( V_39 = 0 ; V_39 < 32 ; V_39 ++ ) {
if ( V_42 != 0 && V_42 != - V_45 ) {
F_15 ( V_46 ,
V_46 + 100 ) ;
}
V_42 = V_32 -> V_47 ( V_32 , & V_38 ) ;
if ( V_42 > 0 ) {
V_40 = V_38 . V_48 & V_49 ;
if ( V_40 == V_50 ) {
if ( V_42 == V_36 )
goto V_51;
V_42 = - V_52 ;
} else
V_42 = - V_53 ;
}
if ( ! V_41 )
V_41 = V_42 ;
}
F_16 ( L_1 ) ;
V_42 = V_41 ;
V_51:
F_17 ( & V_32 -> V_44 ) ;
return V_42 ;
}
T_3 F_18 ( struct V_31 * V_32 , unsigned int V_34 ,
void * V_35 , T_2 V_36 )
{
int V_42 ;
V_42 = F_13 ( V_32 , V_54 , V_55 , V_35 ,
1 ) ;
if ( V_42 != 1 )
return V_42 ;
return F_13 ( V_32 , V_54 , V_34 , V_35 ,
V_36 ) ;
}
T_3 F_19 ( struct V_31 * V_32 , unsigned int V_34 ,
void * V_35 , T_2 V_36 )
{
return F_13 ( V_32 , V_56 , V_34 , V_35 ,
V_36 ) ;
}
int F_20 ( struct V_31 * V_32 ,
T_1 V_57 [ V_2 ] )
{
return F_18 ( V_32 , V_4 , V_57 ,
V_2 ) ;
}
int F_21 ( struct V_31 * V_32 , struct V_58 * V_59 )
{
T_1 V_60 [ 3 ] ;
int V_41 ;
memset ( V_59 , 0 , sizeof( * V_59 ) ) ;
V_41 = F_18 ( V_32 , V_55 , V_60 , sizeof( V_60 ) ) ;
if ( V_41 < 0 )
return V_41 ;
V_59 -> V_61 = V_60 [ 0 ] ;
V_59 -> V_62 = F_12 ( V_60 [ 1 ] ) ;
V_59 -> V_63 = V_60 [ 2 ] & V_64 ;
if ( V_60 [ 2 ] & V_65 )
V_59 -> V_66 |= V_67 ;
return 0 ;
}
int F_22 ( struct V_31 * V_32 , struct V_58 * V_59 )
{
T_1 V_68 ;
int V_41 ;
if ( V_59 -> V_61 < 0x11 )
return 0 ;
V_41 = F_23 ( V_32 , V_69 , & V_68 ) ;
if ( V_41 < 0 )
return V_41 ;
V_68 &= ~ V_70 ;
V_68 |= V_71 ;
V_41 = F_24 ( V_32 , V_69 , V_68 ) ;
if ( V_41 < 0 )
return V_41 ;
F_15 ( 1000 , 2000 ) ;
return 0 ;
}
int F_25 ( struct V_31 * V_32 , struct V_58 * V_59 )
{
T_1 V_68 ;
int V_41 ;
if ( V_59 -> V_61 < 0x11 )
return 0 ;
V_41 = F_23 ( V_32 , V_69 , & V_68 ) ;
if ( V_41 < 0 )
return V_41 ;
V_68 &= ~ V_70 ;
V_68 |= V_72 ;
V_41 = F_24 ( V_32 , V_69 , V_68 ) ;
if ( V_41 < 0 )
return V_41 ;
return 0 ;
}
int F_26 ( struct V_31 * V_32 , struct V_58 * V_59 )
{
T_1 V_60 [ 2 ] ;
int V_41 ;
V_60 [ 0 ] = F_11 ( V_59 -> V_62 ) ;
V_60 [ 1 ] = V_59 -> V_63 ;
if ( V_59 -> V_66 & V_67 )
V_60 [ 1 ] |= V_73 ;
V_41 = F_19 ( V_32 , V_74 , V_60 , sizeof( V_60 ) ) ;
if ( V_41 < 0 )
return V_41 ;
return 0 ;
}
static T_4 F_27 ( struct V_75 * V_76 )
{
return V_77 | V_78 |
V_79 |
V_80 |
V_81 ;
}
static void F_28 ( struct V_37 * V_38 )
{
if ( ( V_38 -> V_33 & ~ V_82 ) == V_83 ) {
V_38 -> V_33 &= V_82 ;
V_38 -> V_33 |= V_84 ;
}
}
static int F_29 ( const struct V_37 * V_38 )
{
int V_85 = V_86 + V_87 + V_88 +
V_89 + V_90 + V_91 ;
if ( ( V_38 -> V_33 & V_92 ) == 0 )
V_85 += V_38 -> V_36 * 8 ;
return V_85 ;
}
static int F_30 ( const struct V_37 * V_38 )
{
int V_85 = V_86 + V_87 + V_88 +
V_89 + V_93 ;
if ( V_38 -> V_33 & V_92 )
V_85 += V_38 -> V_36 * 8 ;
return V_85 ;
}
static int F_31 ( const struct V_37 * V_38 ,
int V_94 )
{
return F_32 ( ( V_95 + V_96 +
V_38 -> V_36 * V_97 +
V_98 ) * 1000 , V_94 ) ;
}
static int F_33 ( const struct V_37 * V_38 ,
int V_94 )
{
int V_99 = F_29 ( V_38 ) +
F_30 ( V_38 ) ;
int V_100 = F_31 ( V_38 , V_94 ) ;
return F_32 ( V_100 , V_99 + V_46 ) ;
}
static int F_34 ( struct V_31 * V_32 , struct V_37 * V_38 )
{
unsigned int V_39 , V_101 ;
int V_42 ;
int V_102 = F_35 ( 7 , F_33 ( V_38 , V_103 ) ) ;
for ( V_39 = 0 , V_101 = 0 ; V_39 < ( V_102 + V_101 ) ; V_39 ++ ) {
V_42 = V_32 -> V_47 ( V_32 , V_38 ) ;
if ( V_42 < 0 ) {
if ( V_42 == - V_104 )
continue;
F_16 ( L_2 , V_42 ) ;
return V_42 ;
}
switch ( V_38 -> V_48 & V_49 ) {
case V_50 :
break;
case V_105 :
F_16 ( L_3 , V_42 , V_38 -> V_36 ) ;
return - V_106 ;
case V_107 :
F_16 ( L_4 ) ;
F_15 ( V_46 , V_46 + 100 ) ;
continue;
default:
F_36 ( L_5 , V_38 -> V_48 ) ;
return - V_106 ;
}
switch ( V_38 -> V_48 & V_108 ) {
case V_109 :
if ( V_42 != V_38 -> V_36 )
F_28 ( V_38 ) ;
return V_42 ;
case V_110 :
F_16 ( L_6 , V_42 , V_38 -> V_36 ) ;
V_32 -> V_111 ++ ;
return - V_106 ;
case V_112 :
F_16 ( L_7 ) ;
V_32 -> V_113 ++ ;
if ( V_101 < 7 )
V_101 ++ ;
F_15 ( V_46 , V_46 + 100 ) ;
F_28 ( V_38 ) ;
continue;
default:
F_36 ( L_8 , V_38 -> V_48 ) ;
return - V_106 ;
}
}
F_16 ( L_1 ) ;
return - V_106 ;
}
static void F_37 ( struct V_37 * V_38 ,
const struct V_114 * V_114 )
{
V_38 -> V_33 = ( V_114 -> V_115 & V_116 ) ?
V_92 : V_83 ;
V_38 -> V_33 |= V_82 ;
}
static int F_38 ( struct V_31 * V_32 , struct V_37 * V_117 )
{
int V_41 , V_42 = V_117 -> V_36 ;
struct V_37 V_38 = * V_117 ;
while ( V_38 . V_36 > 0 ) {
V_41 = F_34 ( V_32 , & V_38 ) ;
if ( V_41 <= 0 )
return V_41 == 0 ? - V_52 : V_41 ;
if ( V_41 < V_38 . V_36 && V_41 < V_42 ) {
F_16 ( L_9 ,
V_38 . V_36 , V_41 ) ;
V_42 = V_41 ;
}
V_38 . V_36 -= V_41 ;
V_38 . V_35 += V_41 ;
}
return V_42 ;
}
static int F_39 ( struct V_75 * V_76 , struct V_114 * V_118 ,
int V_119 )
{
struct V_31 * V_32 = V_76 -> V_120 ;
unsigned int V_6 , V_121 ;
unsigned V_122 ;
struct V_37 V_38 ;
int V_41 = 0 ;
V_123 = F_40 ( V_123 , 1 , V_124 ) ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
F_14 ( & V_32 -> V_44 ) ;
for ( V_6 = 0 ; V_6 < V_119 ; V_6 ++ ) {
V_38 . V_43 = V_118 [ V_6 ] . V_125 ;
F_37 ( & V_38 , & V_118 [ V_6 ] ) ;
V_38 . V_35 = NULL ;
V_38 . V_36 = 0 ;
V_41 = F_34 ( V_32 , & V_38 ) ;
F_37 ( & V_38 , & V_118 [ V_6 ] ) ;
if ( V_41 < 0 )
break;
V_122 = V_123 ;
for ( V_121 = 0 ; V_121 < V_118 [ V_6 ] . V_85 ; V_121 += V_38 . V_36 ) {
V_38 . V_35 = V_118 [ V_6 ] . V_126 + V_121 ;
V_38 . V_36 = F_41 ( V_122 , V_118 [ V_6 ] . V_85 - V_121 ) ;
V_41 = F_38 ( V_32 , & V_38 ) ;
F_37 ( & V_38 , & V_118 [ V_6 ] ) ;
if ( V_41 < 0 )
break;
V_122 = V_41 ;
}
if ( V_41 < 0 )
break;
}
if ( V_41 >= 0 )
V_41 = V_119 ;
V_38 . V_33 &= ~ V_82 ;
V_38 . V_35 = NULL ;
V_38 . V_36 = 0 ;
( void ) F_34 ( V_32 , & V_38 ) ;
F_17 ( & V_32 -> V_44 ) ;
return V_41 ;
}
int F_42 ( struct V_31 * V_32 )
{
int V_42 ;
F_43 ( & V_32 -> V_44 ) ;
V_32 -> V_127 . V_128 = & V_129 ;
V_32 -> V_127 . V_120 = V_32 ;
V_32 -> V_127 . V_130 = 3 ;
V_32 -> V_127 . V_131 = V_132 ;
V_32 -> V_127 . V_133 = V_134 ;
V_32 -> V_127 . V_135 . V_136 = V_32 -> V_135 ;
V_32 -> V_127 . V_135 . V_137 = V_32 -> V_135 -> V_137 ;
F_44 ( V_32 -> V_127 . V_138 , V_32 -> V_138 ? V_32 -> V_138 : F_45 ( V_32 -> V_135 ) ,
sizeof( V_32 -> V_127 . V_138 ) ) ;
V_42 = F_46 ( V_32 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_47 ( & V_32 -> V_127 ) ;
if ( V_42 ) {
F_48 ( V_32 ) ;
return V_42 ;
}
return 0 ;
}
void F_49 ( struct V_31 * V_32 )
{
F_48 ( V_32 ) ;
F_50 ( & V_32 -> V_127 ) ;
}
