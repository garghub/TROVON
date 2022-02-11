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
int V_40 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_41 = V_34 ;
V_38 . V_33 = V_33 ;
V_38 . V_35 = V_35 ;
V_38 . V_36 = V_36 ;
for ( V_39 = 0 ; V_39 < 32 ; V_39 ++ ) {
F_14 ( & V_32 -> V_42 ) ;
V_40 = V_32 -> V_43 ( V_32 , & V_38 ) ;
F_15 ( & V_32 -> V_42 ) ;
if ( V_40 < 0 ) {
if ( V_40 == - V_44 )
continue;
return V_40 ;
}
switch ( V_38 . V_45 & V_46 ) {
case V_47 :
if ( V_40 < V_36 )
return - V_48 ;
return V_40 ;
case V_49 :
return - V_50 ;
case V_51 :
F_16 ( V_52 , V_52 + 100 ) ;
break;
}
}
F_17 ( L_1 ) ;
return - V_50 ;
}
T_3 F_18 ( struct V_31 * V_32 , unsigned int V_34 ,
void * V_35 , T_2 V_36 )
{
return F_13 ( V_32 , V_53 , V_34 , V_35 ,
V_36 ) ;
}
T_3 F_19 ( struct V_31 * V_32 , unsigned int V_34 ,
void * V_35 , T_2 V_36 )
{
return F_13 ( V_32 , V_54 , V_34 , V_35 ,
V_36 ) ;
}
int F_20 ( struct V_31 * V_32 ,
T_1 V_55 [ V_2 ] )
{
return F_18 ( V_32 , V_4 , V_55 ,
V_2 ) ;
}
int F_21 ( struct V_31 * V_32 , struct V_56 * V_57 )
{
T_1 V_58 [ 3 ] ;
int V_40 ;
memset ( V_57 , 0 , sizeof( * V_57 ) ) ;
V_40 = F_18 ( V_32 , V_59 , V_58 , sizeof( V_58 ) ) ;
if ( V_40 < 0 )
return V_40 ;
V_57 -> V_60 = V_58 [ 0 ] ;
V_57 -> V_61 = F_12 ( V_58 [ 1 ] ) ;
V_57 -> V_62 = V_58 [ 2 ] & V_63 ;
if ( V_58 [ 2 ] & V_64 )
V_57 -> V_65 |= V_66 ;
return 0 ;
}
int F_22 ( struct V_31 * V_32 , struct V_56 * V_57 )
{
T_1 V_67 ;
int V_40 ;
if ( V_57 -> V_60 < 0x11 )
return 0 ;
V_40 = F_23 ( V_32 , V_68 , & V_67 ) ;
if ( V_40 < 0 )
return V_40 ;
V_67 &= ~ V_69 ;
V_67 |= V_70 ;
V_40 = F_24 ( V_32 , V_68 , V_67 ) ;
if ( V_40 < 0 )
return V_40 ;
F_16 ( 1000 , 2000 ) ;
return 0 ;
}
int F_25 ( struct V_31 * V_32 , struct V_56 * V_57 )
{
T_1 V_67 ;
int V_40 ;
if ( V_57 -> V_60 < 0x11 )
return 0 ;
V_40 = F_23 ( V_32 , V_68 , & V_67 ) ;
if ( V_40 < 0 )
return V_40 ;
V_67 &= ~ V_69 ;
V_67 |= V_71 ;
V_40 = F_24 ( V_32 , V_68 , V_67 ) ;
if ( V_40 < 0 )
return V_40 ;
return 0 ;
}
int F_26 ( struct V_31 * V_32 , struct V_56 * V_57 )
{
T_1 V_58 [ 2 ] ;
int V_40 ;
V_58 [ 0 ] = F_11 ( V_57 -> V_61 ) ;
V_58 [ 1 ] = V_57 -> V_62 ;
if ( V_57 -> V_65 & V_66 )
V_58 [ 1 ] |= V_72 ;
V_40 = F_19 ( V_32 , V_73 , V_58 , sizeof( V_58 ) ) ;
if ( V_40 < 0 )
return V_40 ;
return 0 ;
}
static T_4 F_27 ( struct V_74 * V_75 )
{
return V_76 | V_77 |
V_78 |
V_79 |
V_80 ;
}
static int F_28 ( const struct V_37 * V_38 )
{
int V_81 = V_82 + V_83 + V_84 +
V_85 + V_86 + V_87 ;
if ( ( V_38 -> V_33 & V_88 ) == 0 )
V_81 += V_38 -> V_36 * 8 ;
return V_81 ;
}
static int F_29 ( const struct V_37 * V_38 )
{
int V_81 = V_82 + V_83 + V_84 +
V_85 + V_89 ;
if ( V_38 -> V_33 & V_88 )
V_81 += V_38 -> V_36 * 8 ;
return V_81 ;
}
static int F_30 ( const struct V_37 * V_38 ,
int V_90 )
{
return F_31 ( ( V_91 + V_92 +
V_38 -> V_36 * V_93 +
V_94 ) * 1000 , V_90 ) ;
}
static int F_32 ( const struct V_37 * V_38 ,
int V_90 )
{
int V_95 = F_28 ( V_38 ) +
F_29 ( V_38 ) ;
int V_96 = F_30 ( V_38 , V_90 ) ;
return F_31 ( V_96 , V_95 + V_52 ) ;
}
static int F_33 ( struct V_31 * V_32 , struct V_37 * V_38 )
{
unsigned int V_39 , V_97 ;
int V_98 ;
int V_99 = F_34 ( 7 , F_32 ( V_38 , V_100 ) ) ;
for ( V_39 = 0 , V_97 = 0 ; V_39 < ( V_99 + V_97 ) ; V_39 ++ ) {
F_14 ( & V_32 -> V_42 ) ;
V_98 = V_32 -> V_43 ( V_32 , V_38 ) ;
F_15 ( & V_32 -> V_42 ) ;
if ( V_98 < 0 ) {
if ( V_98 == - V_44 )
continue;
F_17 ( L_2 , V_98 ) ;
return V_98 ;
}
switch ( V_38 -> V_45 & V_46 ) {
case V_47 :
break;
case V_49 :
F_17 ( L_3 , V_98 , V_38 -> V_36 ) ;
return - V_101 ;
case V_51 :
F_17 ( L_4 ) ;
F_16 ( V_52 , V_52 + 100 ) ;
continue;
default:
F_35 ( L_5 , V_38 -> V_45 ) ;
return - V_101 ;
}
switch ( V_38 -> V_45 & V_102 ) {
case V_103 :
return V_98 ;
case V_104 :
F_17 ( L_6 , V_98 , V_38 -> V_36 ) ;
V_32 -> V_105 ++ ;
return - V_101 ;
case V_106 :
F_17 ( L_7 ) ;
V_32 -> V_107 ++ ;
if ( V_97 < 7 )
V_97 ++ ;
F_16 ( V_52 , V_52 + 100 ) ;
continue;
default:
F_35 ( L_8 , V_38 -> V_45 ) ;
return - V_101 ;
}
}
F_17 ( L_1 ) ;
return - V_101 ;
}
static int F_36 ( struct V_31 * V_32 , struct V_37 * V_108 )
{
int V_40 , V_98 = V_108 -> V_36 ;
struct V_37 V_38 = * V_108 ;
while ( V_38 . V_36 > 0 ) {
V_40 = F_33 ( V_32 , & V_38 ) ;
if ( V_40 <= 0 )
return V_40 == 0 ? - V_48 : V_40 ;
if ( V_40 < V_38 . V_36 && V_40 < V_98 ) {
F_17 ( L_9 ,
V_38 . V_36 , V_40 ) ;
V_98 = V_40 ;
}
V_38 . V_36 -= V_40 ;
V_38 . V_35 += V_40 ;
}
return V_98 ;
}
static int F_37 ( struct V_74 * V_75 , struct V_109 * V_110 ,
int V_111 )
{
struct V_31 * V_32 = V_75 -> V_112 ;
unsigned int V_6 , V_113 ;
unsigned V_114 ;
struct V_37 V_38 ;
int V_40 = 0 ;
V_115 = F_38 ( V_115 , 1 , V_116 ) ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
for ( V_6 = 0 ; V_6 < V_111 ; V_6 ++ ) {
V_38 . V_41 = V_110 [ V_6 ] . V_117 ;
V_38 . V_33 = ( V_110 [ V_6 ] . V_118 & V_119 ) ?
V_88 :
V_120 ;
V_38 . V_33 |= V_121 ;
V_38 . V_35 = NULL ;
V_38 . V_36 = 0 ;
V_40 = F_33 ( V_32 , & V_38 ) ;
if ( V_40 < 0 )
break;
V_114 = V_115 ;
for ( V_113 = 0 ; V_113 < V_110 [ V_6 ] . V_81 ; V_113 += V_38 . V_36 ) {
V_38 . V_35 = V_110 [ V_6 ] . V_122 + V_113 ;
V_38 . V_36 = F_39 ( V_114 , V_110 [ V_6 ] . V_81 - V_113 ) ;
V_40 = F_36 ( V_32 , & V_38 ) ;
if ( V_40 < 0 )
break;
V_114 = V_40 ;
}
if ( V_40 < 0 )
break;
}
if ( V_40 >= 0 )
V_40 = V_111 ;
V_38 . V_33 &= ~ V_121 ;
V_38 . V_35 = NULL ;
V_38 . V_36 = 0 ;
( void ) F_33 ( V_32 , & V_38 ) ;
return V_40 ;
}
int F_40 ( struct V_31 * V_32 )
{
F_41 ( & V_32 -> V_42 ) ;
V_32 -> V_123 . V_124 = & V_125 ;
V_32 -> V_123 . V_112 = V_32 ;
V_32 -> V_123 . V_126 = 3 ;
V_32 -> V_123 . V_127 = V_128 ;
V_32 -> V_123 . V_129 = V_130 ;
V_32 -> V_123 . V_131 . V_132 = V_32 -> V_131 ;
V_32 -> V_123 . V_131 . V_133 = V_32 -> V_131 -> V_133 ;
F_42 ( V_32 -> V_123 . V_134 , V_32 -> V_134 ? V_32 -> V_134 : F_43 ( V_32 -> V_131 ) ,
sizeof( V_32 -> V_123 . V_134 ) ) ;
return F_44 ( & V_32 -> V_123 ) ;
}
void F_45 ( struct V_31 * V_32 )
{
F_46 ( & V_32 -> V_123 ) ;
}
