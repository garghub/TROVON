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
unsigned int V_39 ;
int V_40 = 0 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_41 = V_34 ;
V_38 . V_33 = V_33 ;
V_38 . V_35 = V_35 ;
V_38 . V_36 = V_36 ;
F_14 ( & V_32 -> V_42 ) ;
for ( V_39 = 0 ; V_39 < 32 ; V_39 ++ ) {
V_40 = V_32 -> V_43 ( V_32 , & V_38 ) ;
if ( V_40 < 0 ) {
if ( V_40 == - V_44 )
continue;
goto V_45;
}
switch ( V_38 . V_46 & V_47 ) {
case V_48 :
if ( V_40 < V_36 )
V_40 = - V_49 ;
goto V_45;
case V_50 :
V_40 = - V_51 ;
goto V_45;
case V_52 :
F_15 ( V_53 , V_53 + 100 ) ;
break;
}
}
F_16 ( L_1 ) ;
V_40 = - V_51 ;
V_45:
F_17 ( & V_32 -> V_42 ) ;
return V_40 ;
}
T_3 F_18 ( struct V_31 * V_32 , unsigned int V_34 ,
void * V_35 , T_2 V_36 )
{
return F_13 ( V_32 , V_54 , V_34 , V_35 ,
V_36 ) ;
}
T_3 F_19 ( struct V_31 * V_32 , unsigned int V_34 ,
void * V_35 , T_2 V_36 )
{
return F_13 ( V_32 , V_55 , V_34 , V_35 ,
V_36 ) ;
}
int F_20 ( struct V_31 * V_32 ,
T_1 V_56 [ V_2 ] )
{
return F_18 ( V_32 , V_4 , V_56 ,
V_2 ) ;
}
int F_21 ( struct V_31 * V_32 , struct V_57 * V_58 )
{
T_1 V_59 [ 3 ] ;
int V_40 ;
memset ( V_58 , 0 , sizeof( * V_58 ) ) ;
V_40 = F_18 ( V_32 , V_60 , V_59 , sizeof( V_59 ) ) ;
if ( V_40 < 0 )
return V_40 ;
V_58 -> V_61 = V_59 [ 0 ] ;
V_58 -> V_62 = F_12 ( V_59 [ 1 ] ) ;
V_58 -> V_63 = V_59 [ 2 ] & V_64 ;
if ( V_59 [ 2 ] & V_65 )
V_58 -> V_66 |= V_67 ;
return 0 ;
}
int F_22 ( struct V_31 * V_32 , struct V_57 * V_58 )
{
T_1 V_68 ;
int V_40 ;
if ( V_58 -> V_61 < 0x11 )
return 0 ;
V_40 = F_23 ( V_32 , V_69 , & V_68 ) ;
if ( V_40 < 0 )
return V_40 ;
V_68 &= ~ V_70 ;
V_68 |= V_71 ;
V_40 = F_24 ( V_32 , V_69 , V_68 ) ;
if ( V_40 < 0 )
return V_40 ;
F_15 ( 1000 , 2000 ) ;
return 0 ;
}
int F_25 ( struct V_31 * V_32 , struct V_57 * V_58 )
{
T_1 V_68 ;
int V_40 ;
if ( V_58 -> V_61 < 0x11 )
return 0 ;
V_40 = F_23 ( V_32 , V_69 , & V_68 ) ;
if ( V_40 < 0 )
return V_40 ;
V_68 &= ~ V_70 ;
V_68 |= V_72 ;
V_40 = F_24 ( V_32 , V_69 , V_68 ) ;
if ( V_40 < 0 )
return V_40 ;
return 0 ;
}
int F_26 ( struct V_31 * V_32 , struct V_57 * V_58 )
{
T_1 V_59 [ 2 ] ;
int V_40 ;
V_59 [ 0 ] = F_11 ( V_58 -> V_62 ) ;
V_59 [ 1 ] = V_58 -> V_63 ;
if ( V_58 -> V_66 & V_67 )
V_59 [ 1 ] |= V_73 ;
V_40 = F_19 ( V_32 , V_74 , V_59 , sizeof( V_59 ) ) ;
if ( V_40 < 0 )
return V_40 ;
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
return F_32 ( V_100 , V_99 + V_53 ) ;
}
static int F_34 ( struct V_31 * V_32 , struct V_37 * V_38 )
{
unsigned int V_39 , V_101 ;
int V_102 ;
int V_103 = F_35 ( 7 , F_33 ( V_38 , V_104 ) ) ;
for ( V_39 = 0 , V_101 = 0 ; V_39 < ( V_103 + V_101 ) ; V_39 ++ ) {
V_102 = V_32 -> V_43 ( V_32 , V_38 ) ;
if ( V_102 < 0 ) {
if ( V_102 == - V_44 )
continue;
F_16 ( L_2 , V_102 ) ;
return V_102 ;
}
switch ( V_38 -> V_46 & V_47 ) {
case V_48 :
break;
case V_50 :
F_16 ( L_3 , V_102 , V_38 -> V_36 ) ;
return - V_105 ;
case V_52 :
F_16 ( L_4 ) ;
F_15 ( V_53 , V_53 + 100 ) ;
continue;
default:
F_36 ( L_5 , V_38 -> V_46 ) ;
return - V_105 ;
}
switch ( V_38 -> V_46 & V_106 ) {
case V_107 :
if ( V_102 != V_38 -> V_36 )
F_28 ( V_38 ) ;
return V_102 ;
case V_108 :
F_16 ( L_6 , V_102 , V_38 -> V_36 ) ;
V_32 -> V_109 ++ ;
return - V_105 ;
case V_110 :
F_16 ( L_7 ) ;
V_32 -> V_111 ++ ;
if ( V_101 < 7 )
V_101 ++ ;
F_15 ( V_53 , V_53 + 100 ) ;
F_28 ( V_38 ) ;
continue;
default:
F_36 ( L_8 , V_38 -> V_46 ) ;
return - V_105 ;
}
}
F_16 ( L_1 ) ;
return - V_105 ;
}
static void F_37 ( struct V_37 * V_38 ,
const struct V_112 * V_112 )
{
V_38 -> V_33 = ( V_112 -> V_113 & V_114 ) ?
V_92 : V_83 ;
V_38 -> V_33 |= V_82 ;
}
static int F_38 ( struct V_31 * V_32 , struct V_37 * V_115 )
{
int V_40 , V_102 = V_115 -> V_36 ;
struct V_37 V_38 = * V_115 ;
while ( V_38 . V_36 > 0 ) {
V_40 = F_34 ( V_32 , & V_38 ) ;
if ( V_40 <= 0 )
return V_40 == 0 ? - V_49 : V_40 ;
if ( V_40 < V_38 . V_36 && V_40 < V_102 ) {
F_16 ( L_9 ,
V_38 . V_36 , V_40 ) ;
V_102 = V_40 ;
}
V_38 . V_36 -= V_40 ;
V_38 . V_35 += V_40 ;
}
return V_102 ;
}
static int F_39 ( struct V_75 * V_76 , struct V_112 * V_116 ,
int V_117 )
{
struct V_31 * V_32 = V_76 -> V_118 ;
unsigned int V_6 , V_119 ;
unsigned V_120 ;
struct V_37 V_38 ;
int V_40 = 0 ;
V_121 = F_40 ( V_121 , 1 , V_122 ) ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
F_14 ( & V_32 -> V_42 ) ;
for ( V_6 = 0 ; V_6 < V_117 ; V_6 ++ ) {
V_38 . V_41 = V_116 [ V_6 ] . V_123 ;
F_37 ( & V_38 , & V_116 [ V_6 ] ) ;
V_38 . V_35 = NULL ;
V_38 . V_36 = 0 ;
V_40 = F_34 ( V_32 , & V_38 ) ;
F_37 ( & V_38 , & V_116 [ V_6 ] ) ;
if ( V_40 < 0 )
break;
V_120 = V_121 ;
for ( V_119 = 0 ; V_119 < V_116 [ V_6 ] . V_85 ; V_119 += V_38 . V_36 ) {
V_38 . V_35 = V_116 [ V_6 ] . V_124 + V_119 ;
V_38 . V_36 = F_41 ( V_120 , V_116 [ V_6 ] . V_85 - V_119 ) ;
V_40 = F_38 ( V_32 , & V_38 ) ;
F_37 ( & V_38 , & V_116 [ V_6 ] ) ;
if ( V_40 < 0 )
break;
V_120 = V_40 ;
}
if ( V_40 < 0 )
break;
}
if ( V_40 >= 0 )
V_40 = V_117 ;
V_38 . V_33 &= ~ V_82 ;
V_38 . V_35 = NULL ;
V_38 . V_36 = 0 ;
( void ) F_34 ( V_32 , & V_38 ) ;
F_17 ( & V_32 -> V_42 ) ;
return V_40 ;
}
int F_42 ( struct V_31 * V_32 )
{
int V_102 ;
F_43 ( & V_32 -> V_42 ) ;
V_32 -> V_125 . V_126 = & V_127 ;
V_32 -> V_125 . V_118 = V_32 ;
V_32 -> V_125 . V_128 = 3 ;
V_32 -> V_125 . V_129 = V_130 ;
V_32 -> V_125 . V_131 = V_132 ;
V_32 -> V_125 . V_133 . V_134 = V_32 -> V_133 ;
V_32 -> V_125 . V_133 . V_135 = V_32 -> V_133 -> V_135 ;
F_44 ( V_32 -> V_125 . V_136 , V_32 -> V_136 ? V_32 -> V_136 : F_45 ( V_32 -> V_133 ) ,
sizeof( V_32 -> V_125 . V_136 ) ) ;
V_102 = F_46 ( V_32 ) ;
if ( V_102 )
return V_102 ;
V_102 = F_47 ( & V_32 -> V_125 ) ;
if ( V_102 ) {
F_48 ( V_32 ) ;
return V_102 ;
}
return 0 ;
}
void F_49 ( struct V_31 * V_32 )
{
F_48 ( V_32 ) ;
F_50 ( & V_32 -> V_125 ) ;
}
