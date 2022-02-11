static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_2 * V_5 )
{
int V_6 ;
struct V_7 V_8 ;
unsigned char V_9 [ 4 ] ;
if ( ! V_2 -> V_10 )
return - V_11 ;
if ( V_3 != V_12 && V_3 != V_13 )
return - V_14 ;
V_8 . V_15 = V_2 -> V_15 ;
V_8 . V_16 = 0 ;
V_8 . V_17 = 2 ;
V_8 . V_18 = V_9 ;
V_9 [ 0 ] = ( V_19 ) ( V_4 >> 8 ) ;
V_9 [ 1 ] = ( V_19 ) ( V_4 & 0xff ) ;
V_6 = F_2 ( V_2 -> V_10 , & V_8 , 1 ) ;
if ( V_6 < 0 )
goto V_20;
V_8 . V_17 = V_3 ;
V_8 . V_16 = V_21 ;
V_6 = F_2 ( V_2 -> V_10 , & V_8 , 1 ) ;
if ( V_6 < 0 )
goto V_20;
* V_5 = 0 ;
if ( V_3 == V_12 )
* V_5 = V_9 [ 0 ] ;
else
* V_5 = ( V_9 [ 1 ] << 8 ) + V_9 [ 0 ] ;
return 0 ;
V_20:
F_3 ( & V_2 -> V_22 , L_1 , V_4 , V_6 ) ;
return V_6 ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_17 , T_1 V_4 ,
T_2 V_5 , struct V_7 * V_8 ,
unsigned char * V_18 )
{
V_8 -> V_15 = V_2 -> V_15 ;
V_8 -> V_16 = 0 ;
V_8 -> V_17 = 2 + V_17 ;
V_8 -> V_18 = V_18 ;
V_18 [ 0 ] = ( V_19 ) ( V_4 >> 8 ) ;
V_18 [ 1 ] = ( V_19 ) ( V_4 & 0xff ) ;
switch ( V_17 ) {
case V_12 :
V_18 [ 2 ] = ( V_19 ) ( V_5 ) & 0xff ;
break;
case V_13 :
V_18 [ 2 ] = ( V_19 ) ( V_5 ) & 0xff ;
V_18 [ 3 ] = ( V_19 ) ( V_5 >> 8 ) & 0xff ;
break;
default:
F_5 ( 1 , V_23 L_2 ,
V_24 ) ;
}
}
static int F_6 ( struct V_1 * V_2 ,
const struct V_25 * V_26 ,
int V_27 )
{
struct V_7 V_8 [ V_28 ] ;
unsigned char V_9 [ V_28 ] [ 6 ] ;
int V_29 = 0 ;
T_1 V_4 , V_3 ;
T_2 V_5 ;
if ( F_5 ( V_27 > V_28 ,
V_23 L_3 , V_24 ) ) {
return - V_14 ;
}
while ( V_29 < V_27 ) {
V_3 = V_26 -> type ;
V_4 = V_26 -> V_4 ;
V_5 = V_26 -> V_5 ;
V_26 ++ ;
F_4 ( V_2 , V_3 , V_4 ,
V_5 , & V_8 [ V_29 ] , & V_9 [ V_29 ] [ 0 ] ) ;
V_29 ++ ;
}
return F_2 ( V_2 -> V_10 , V_8 , V_29 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
const struct V_25 * V_30 )
{
int V_6 , V_27 = 0 ;
const struct V_25 * V_31 ;
if ( ! V_2 -> V_10 )
return - V_11 ;
if ( ! V_30 )
return - V_14 ;
V_31 = V_30 ;
do {
while ( V_31 -> type != V_32 &&
V_31 -> type != V_33 ) {
if ( F_8 ( V_31 -> type != V_12 &&
V_31 -> type != V_13 ,
L_4 , V_31 -> type ) ) {
return - V_14 ;
}
V_27 ++ ;
V_31 ++ ;
}
V_6 = F_6 ( V_2 , V_30 , V_27 ) ;
if ( V_6 < 0 ) {
F_3 ( & V_2 -> V_22 , L_5 ) ;
return V_6 ;
}
if ( V_31 -> type == V_33 ) {
F_9 ( V_31 -> V_5 ) ;
V_31 ++ ;
V_30 = V_31 ;
V_27 = 0 ;
}
} while ( V_31 -> type != V_32 );
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_2 V_5 )
{
int V_6 ;
struct V_7 V_8 ;
unsigned char V_9 [ 6 ] ;
if ( ! V_2 -> V_10 )
return - V_11 ;
if ( V_3 != V_12 && V_3 != V_13 )
return - V_14 ;
F_4 ( V_2 , V_3 , V_4 , V_5 , & V_8 , V_9 ) ;
V_6 = F_2 ( V_2 -> V_10 , & V_8 , 1 ) ;
if ( V_6 < 0 ) {
F_3 ( & V_2 -> V_22 ,
L_6 , V_5 , V_4 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
static struct V_34 * F_11 (
struct V_35 * V_36 ,
T_1 type )
{
struct V_34 * * V_31 = & V_36 -> V_37 [ 0 ] . V_38 ;
while ( * V_31 ) {
if ( ( * V_31 ) -> type == type )
return * V_31 ;
V_31 ++ ;
}
return NULL ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
T_1 type )
{
struct V_34 * V_37 ;
V_37 = F_11 ( V_36 , type ) ;
if ( ! V_37 )
return - V_14 ;
return F_7 ( V_2 , V_37 -> V_30 ) ;
}
static struct V_34 * * F_13 (
struct V_35 * V_36 )
{
return & V_36 -> V_37 [ 0 ] . V_38 ;
}
static void F_14 ( const struct V_34 * V_37 ,
struct V_39 * V_40 )
{
V_40 -> V_41 = V_37 -> V_42 . V_43 ;
V_40 -> V_44 = V_37 -> V_42 . V_45 ;
V_40 -> V_46 = V_37 -> V_42 . V_47 ;
}
static struct V_34 * F_15 (
struct V_35 * V_36 ,
struct V_39 * V_40 )
{
struct V_34 * * V_48 = F_13 ( V_36 ) ;
struct V_34 * V_49 = NULL ;
struct V_34 * V_50 = NULL ;
struct V_39 V_51 ;
unsigned int V_52 = ( unsigned int ) - 1 ;
unsigned int V_53 = ( unsigned int ) - 1 ;
for (; * V_48 ; V_48 ++ ) {
unsigned int V_54 ;
if ( ( * V_48 ) -> type != V_55 )
continue;
F_14 ( * V_48 , & V_51 ) ;
V_54 = F_16 ( V_40 -> V_41 , V_51 . V_41 )
* F_16 ( V_40 -> V_44 , V_51 . V_44 ) ;
V_54 = V_51 . V_41 * V_51 . V_44
+ V_40 -> V_41 * V_40 -> V_44 - 2 * V_54 ;
if ( V_40 -> V_46 == V_51 . V_46 ) {
if ( V_54 < V_52 || ! V_49 ) {
V_49 = * V_48 ;
V_52 = V_54 ;
}
} else {
if ( V_54 < V_53 || ! V_50 ) {
V_50 = * V_48 ;
V_53 = V_54 ;
}
}
}
return V_49 ? V_49 : V_50 ;
}
static struct V_34 * F_17 (
struct V_35 * V_36 ,
struct V_34 * V_56 ,
struct V_57 * V_58 )
{
int V_59 = F_18 ( * V_58 ) ;
struct V_34 * * V_48 = F_13 ( V_36 ) ;
struct V_60 * V_61 = & V_56 -> V_42 ;
for (; * V_48 ; V_48 ++ ) {
struct V_60 * V_42 = & ( * V_48 ) -> V_42 ;
if ( ( * V_48 ) -> type != V_55 )
continue;
if ( V_42 -> V_43 != V_61 -> V_43 ||
V_42 -> V_45 != V_61 -> V_45 )
continue;
if ( F_18 ( V_42 -> V_58 ) == V_59 )
return * V_48 ;
}
return NULL ;
}
static int F_19 ( const void * V_62 , const void * V_63 )
{
const struct V_34 * * V_64 = ( const struct V_34 * * ) V_62 ,
* * V_65 = ( const struct V_34 * * ) V_63 ;
if ( ( * V_64 ) -> type == V_55 &&
( * V_65 ) -> type != V_55 )
return - 1 ;
if ( ( * V_64 ) -> type != V_55 &&
( * V_65 ) -> type == V_55 )
return 1 ;
if ( ( * V_64 ) -> V_42 . V_43 > ( * V_65 ) -> V_42 . V_43 )
return - 1 ;
if ( ( * V_64 ) -> V_42 . V_43 < ( * V_65 ) -> V_42 . V_43 )
return 1 ;
if ( ( * V_64 ) -> V_42 . V_45 > ( * V_65 ) -> V_42 . V_45 )
return - 1 ;
if ( ( * V_64 ) -> V_42 . V_45 < ( * V_65 ) -> V_42 . V_45 )
return 1 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
int V_66 = 0 , V_67 ;
F_21 ( & V_2 -> V_22 , L_7 , V_36 -> V_68 ) ;
while ( V_36 -> V_37 [ V_66 ] . V_38 )
V_66 ++ ;
if ( ! V_66 )
return - V_14 ;
F_22 ( & V_36 -> V_37 [ 0 ] . V_38 , V_66 , sizeof( V_36 -> V_37 [ 0 ] . V_38 ) ,
F_19 , NULL ) ;
V_67 = V_66 ;
V_66 = 0 ;
while ( V_67 -- ) {
struct V_34 * V_48 ;
V_48 = V_36 -> V_37 [ V_66 ] . V_38 ;
F_23 ( & V_2 -> V_22 ,
L_8 ,
V_24 ,
V_48 -> type ,
V_48 -> V_42 . V_43 , V_48 -> V_42 . V_45 ,
V_48 -> V_42 . V_47 ,
V_48 -> V_42 . V_58 . V_69 ,
V_48 -> V_42 . V_58 . V_70 ,
( void * ) V_36 -> V_37 [ V_66 ] . V_38 ) ;
V_66 ++ ;
}
return 0 ;
}
static int F_24 ( struct V_71 * V_72 , T_3 V_73 )
{
struct V_1 * V_2 = F_25 ( & V_72 -> V_74 ) ;
struct V_75 V_76 ;
int V_6 ;
V_76 = V_77 [ V_73 ] ;
V_6 = F_10 ( V_2 , V_12 ,
0x124a , V_76 . V_78 >> 8 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_10 ( V_2 , V_12 ,
0x1249 , V_76 . V_78 & 0xff ) ;
if ( V_6 )
return V_6 ;
V_6 = F_10 ( V_2 , V_12 ,
0x124d , V_76 . V_79 >> 8 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_10 ( V_2 , V_12 ,
0x124c , V_76 . V_79 & 0xff ) ;
return V_6 ;
}
static int F_26 ( struct V_71 * V_72 , T_3 V_42 )
{
struct V_1 * V_2 = F_25 ( & V_72 -> V_74 ) ;
int V_80 , V_81 , V_82 , V_83 , V_84 , V_85 ;
V_80 = 0 ;
V_81 = 0 ;
V_82 = 0 ;
V_83 = 0x00 ;
V_84 = 0xF0 ;
if ( V_42 ) {
if ( V_42 < 5 ) {
V_80 = 1 ;
V_81 = 1 ;
V_82 = V_42 + 3 ;
} else {
V_80 = 0 ;
V_81 = 0 ;
V_82 = V_42 - 4 + 3 ;
}
V_83 = 0x01 ;
V_84 = 0xE0 ;
}
V_85 = F_10 ( V_2 , V_12 , 0x111B ,
V_82 << 4 ) ;
if ( V_85 )
return V_85 ;
V_85 = F_10 ( V_2 , V_12 , 0x1121 ,
V_80 << 7 ) ;
if ( V_85 )
return V_85 ;
V_85 = F_10 ( V_2 , V_12 , 0x1124 ,
V_81 << 7 ) ;
if ( V_85 )
return V_85 ;
V_85 = F_10 ( V_2 , V_12 , 0x112C , V_83 ) ;
if ( V_85 )
return V_85 ;
return F_10 ( V_2 , V_12 , 0x1420 , V_84 ) ;
}
static int F_27 ( struct V_86 * V_87 )
{
struct V_71 * V_72 =
F_28 ( V_87 -> V_88 , struct V_71 , V_89 ) ;
switch ( V_87 -> V_90 ) {
case V_91 :
return F_24 ( V_72 , V_87 -> V_5 ) ;
case V_92 :
{
struct V_1 * V_2 =
F_25 ( & V_72 -> V_74 ) ;
return F_10 ( V_2 , V_13 , 0x1243 ,
V_87 -> V_5 ) ;
}
case V_93 :
return F_26 ( V_72 , V_87 -> V_5 ) ;
case V_94 :
return 0 ;
default:
return - V_14 ;
}
}
static int F_29 ( struct V_71 * V_72 )
{
T_3 V_95 ;
F_30 ( & V_72 -> V_89 , 4 ) ;
F_31 ( & V_72 -> V_89 , & V_96 ,
V_91 , 0 , F_32 ( V_77 ) - 1 ,
1 , 0 ) ;
V_95 = V_72 -> V_56 -> V_42 . V_97 ;
{
T_2 F_16 = 1 , V_98 = V_95 ;
V_72 -> V_99 =
F_31 ( & V_72 -> V_89 ,
& V_96 , V_92 ,
F_16 , V_98 , F_16 , V_98 ) ;
}
V_72 -> V_100 =
F_31 ( & V_72 -> V_89 , & V_96 ,
V_94 , 1 , V_101 , 1 , 1 ) ;
F_33 ( & V_72 -> V_89 ,
& V_96 , V_93 ,
F_32 ( V_102 ) - 1 ,
0 , 0 , V_102 ) ;
if ( V_72 -> V_89 . error )
return V_72 -> V_89 . error ;
V_72 -> V_74 . V_89 = & V_72 -> V_89 ;
return 0 ;
}
static void F_34 ( struct V_71 * V_72 )
{
struct V_86 * V_87 ;
struct V_60 * V_42 = & V_72 -> V_56 -> V_42 ;
T_2 F_16 , V_98 , V_100 ;
static const int V_103 = 8 ;
V_87 = V_72 -> V_99 ;
F_16 = 1 ;
V_98 = V_42 -> V_97 ;
V_100 = ( ( V_42 -> V_104 + ( 1 << V_103 ) - 1 ) >> V_103 ) + V_42 -> V_41 ;
V_100 = V_42 -> V_43 * ( V_100 - 1 ) / V_42 -> V_41 ;
F_35 ( V_87 , F_16 , V_98 , F_16 , V_98 ) ;
F_36 ( V_72 -> V_100 , V_100 << V_103 ) ;
}
static int F_37 ( struct V_71 * V_72 )
{
struct V_105 * V_74 = & V_72 -> V_74 ;
struct V_1 * V_2 = F_25 ( V_74 ) ;
int V_85 ;
V_85 = F_7 ( V_2 , V_72 -> V_56 -> V_30 ) ;
if ( V_85 )
goto V_106;
V_85 = F_38 ( & V_72 -> V_89 ) ;
if ( V_85 )
goto V_106;
return 0 ;
V_106:
F_3 ( & V_2 -> V_22 , L_9 ) ;
return V_85 ;
}
static int F_39 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = F_25 ( & V_72 -> V_74 ) ;
return F_10 ( V_2 , V_12 , 0x1252 , 0xb0 ) ;
}
static int F_40 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = F_25 ( & V_72 -> V_74 ) ;
return F_10 ( V_2 , V_12 , 0x1252 , 0x30 ) ;
}
static int F_41 ( struct V_105 * V_74 , int V_107 )
{
struct V_71 * V_72 = F_42 ( V_74 ) ;
int V_108 ;
if ( ! V_107 )
return F_40 ( V_72 ) ;
V_108 = F_37 ( V_72 ) ;
if ( V_108 < 0 )
return V_108 ;
return F_39 ( V_72 ) ;
}
static int F_43 ( struct V_71 * V_72 )
{
F_44 ( V_72 -> V_109 , 0 ) ;
F_45 ( 1 ) ;
F_46 ( V_72 -> V_110 ) ;
return F_47 ( V_72 -> V_111 ) ;
}
static int F_48 ( struct V_71 * V_72 )
{
struct V_105 * V_74 = & V_72 -> V_74 ;
struct V_1 * V_2 = F_25 ( V_74 ) ;
unsigned int V_112 ;
int V_5 , V_85 ;
V_85 = F_49 ( V_72 -> V_111 ) ;
if ( V_85 ) {
F_3 ( & V_2 -> V_22 , L_10 ) ;
return V_85 ;
}
if ( V_72 -> V_56 )
V_112 = V_72 -> V_56 -> V_42 . V_113 ;
else
V_112 = V_72 -> V_112 ;
V_85 = F_50 ( V_72 -> V_110 , V_112 ) ;
if ( V_85 < 0 ) {
F_3 ( & V_2 -> V_22 , L_11 ,
V_112 ) ;
goto V_114;
}
V_85 = F_51 ( V_72 -> V_110 ) ;
if ( V_85 < 0 ) {
F_3 ( & V_2 -> V_22 , L_12 ) ;
goto V_114;
}
if ( V_85 )
goto V_114;
F_45 ( 10 ) ;
F_44 ( V_72 -> V_109 , 1 ) ;
F_9 ( 5000 * 1000 / V_112 + 1 ) ;
V_85 = F_12 ( V_2 , & V_115 ,
V_116 ) ;
if ( V_85 )
goto V_114;
#ifdef F_52
V_85 = F_1 ( V_2 , V_12 , 0x1263 , & V_5 ) ;
if ( V_85 )
goto V_114;
#if F_52
V_5 |= F_53 ( 4 ) ;
#else
V_5 &= ~ F_53 ( 4 ) ;
#endif
V_85 = F_10 ( V_2 , V_12 , 0x1263 , V_5 ) ;
if ( V_85 )
goto V_114;
#endif
V_114:
if ( V_85 )
F_43 ( V_72 ) ;
return V_85 ;
}
static int F_54 ( struct V_105 * V_74 ,
struct V_117 * V_118 ,
struct V_119 * V_46 )
{
struct V_34 * * V_48 =
F_13 ( & V_115 ) ;
T_2 V_120 [ V_121 ] ;
int V_122 = 0 ;
if ( V_46 -> V_123 >= V_121 )
return - V_14 ;
for (; * V_48 ; V_48 ++ ) {
struct V_60 * V_42 = & ( * V_48 ) -> V_42 ;
int V_67 ;
if ( ( * V_48 ) -> type != V_55 )
continue;
for ( V_67 = 0 ; V_67 < V_122 ; V_67 ++ ) {
if ( V_120 [ V_67 ] == V_42 -> V_47 )
break;
}
if ( V_67 != V_122 )
continue;
if ( V_46 -> V_123 == V_122 ) {
V_46 -> V_46 = V_42 -> V_47 ;
return 0 ;
}
V_120 [ V_122 ] = V_42 -> V_47 ;
V_122 ++ ;
}
return - V_14 ;
}
static int F_55 ( struct V_105 * V_74 ,
struct V_117 * V_118 ,
struct V_124 * V_125 )
{
struct V_34 * * V_48 =
F_13 ( & V_115 ) ;
struct V_39 V_51 ;
int V_126 = V_101 ;
int V_127 = V_101 ;
int V_123 = V_125 -> V_123 ;
for (; * V_48 ; V_48 ++ ) {
if ( ( * V_48 ) -> type != V_55 )
continue;
F_14 ( * V_48 , & V_51 ) ;
if ( V_125 -> V_46 != V_51 . V_46 )
continue;
if ( V_51 . V_41 == V_126 && V_51 . V_44 == V_127 )
continue;
V_126 = V_51 . V_41 ;
V_127 = V_51 . V_44 ;
if ( V_123 -- == 0 ) {
V_125 -> V_128 = V_51 . V_41 ;
V_125 -> V_129 = V_51 . V_44 ;
V_125 -> V_130 = V_51 . V_41 ;
V_125 -> V_131 = V_51 . V_44 ;
return 0 ;
}
}
return - V_14 ;
}
static int F_56 ( struct V_105 * V_74 ,
struct V_117 * V_118 ,
struct V_132 * V_133 )
{
struct V_34 * * V_48 =
F_13 ( & V_115 ) ;
struct V_39 V_51 ;
int V_123 = V_133 -> V_123 ;
for (; * V_48 ; V_48 ++ ) {
struct V_60 * V_42 = & ( * V_48 ) -> V_42 ;
if ( ( * V_48 ) -> type != V_55 )
continue;
F_14 ( * V_48 , & V_51 ) ;
if ( V_133 -> V_46 != V_51 . V_46 )
continue;
if ( V_133 -> V_41 != V_51 . V_41 || V_133 -> V_44 != V_51 . V_44 )
continue;
if ( V_123 -- == 0 ) {
V_133 -> V_134 = V_42 -> V_58 ;
return 0 ;
}
}
return - V_14 ;
}
static struct V_39 *
F_57 ( struct V_71 * V_72 ,
struct V_117 * V_118 ,
unsigned int V_135 , enum V_136 V_137 )
{
switch ( V_137 ) {
case V_138 :
return F_58 ( & V_72 -> V_74 , V_118 , V_135 ) ;
case V_139 :
return & V_72 -> V_51 ;
default:
return NULL ;
}
}
static int F_59 ( struct V_105 * V_74 ,
struct V_117 * V_118 ,
struct V_140 * V_40 )
{
struct V_71 * V_72 = F_42 ( V_74 ) ;
struct V_39 * V_51 ;
V_51 = F_57 ( V_72 , V_118 , V_40 -> V_135 , V_40 -> V_137 ) ;
if ( ! V_51 )
return - V_14 ;
V_40 -> V_51 = * V_51 ;
return 0 ;
}
static int F_60 ( struct V_105 * V_74 ,
struct V_117 * V_118 ,
struct V_140 * V_40 )
{
struct V_71 * V_72 = F_42 ( V_74 ) ;
struct V_39 * V_51 ;
struct V_34 * V_37 ;
V_51 = F_57 ( V_72 , V_118 , V_40 -> V_135 , V_40 -> V_137 ) ;
if ( ! V_51 )
return - V_14 ;
V_37 = F_15 ( & V_115 , & V_40 -> V_51 ) ;
F_14 ( V_37 , & V_40 -> V_51 ) ;
* V_51 = V_40 -> V_51 ;
if ( V_40 -> V_137 == V_139 ) {
V_72 -> V_56 = V_37 ;
F_34 ( V_72 ) ;
}
return 0 ;
}
static int F_61 ( struct V_105 * V_74 ,
struct V_141 * V_142 )
{
struct V_71 * V_72 = F_42 ( V_74 ) ;
memset ( V_142 , 0 , sizeof( * V_142 ) ) ;
V_142 -> V_134 = V_72 -> V_56 -> V_42 . V_58 ;
return 0 ;
}
static int F_62 ( struct V_105 * V_74 ,
struct V_141 * V_142 )
{
struct V_71 * V_72 = F_42 ( V_74 ) ;
struct V_34 * V_37 ;
V_37 = F_17 ( & V_115 ,
V_72 -> V_56 ,
& V_142 -> V_134 ) ;
if ( ! V_37 )
return - V_14 ;
if ( V_72 -> V_56 -> V_42 . V_113 != V_37 -> V_42 . V_113 )
return - V_14 ;
V_72 -> V_56 = V_37 ;
F_34 ( V_72 ) ;
return 0 ;
}
static int F_63 ( struct V_105 * V_74 )
{
struct V_71 * V_72 = F_42 ( V_74 ) ;
struct V_1 * V_2 = F_25 ( V_74 ) ;
unsigned int V_143 = V_144 ;
unsigned int V_145 = 0 ;
V_19 * V_38 = V_72 -> V_146 ;
int V_85 = 0 ;
do {
V_19 V_147 [ V_148 ] ;
struct V_7 V_8 ;
int V_149 , V_67 ;
int V_150 ;
V_85 = F_10 ( V_2 , V_12 , 0x0001 ,
0xe0 | ( V_145 >> 3 ) ) ;
if ( V_85 < 0 )
return V_85 ;
for ( V_67 = 0 ; V_67 < 1000 ; ++ V_67 ) {
T_2 V_151 ;
V_85 = F_1 ( V_2 , V_12 ,
0x0003 , & V_151 ) ;
if ( V_85 < 0 )
return V_85 ;
if ( ! ( V_151 & 0x08 ) )
break;
F_64 ( 1000 , 2000 ) ;
}
if ( V_67 == 1000 )
return - V_152 ;
V_150 = V_145 & 0x07 ;
V_149 = V_143 + V_150 > 8 ? 8 - V_150 : V_143 ;
V_8 . V_15 = V_2 -> V_15 ;
V_8 . V_16 = 0 ;
V_8 . V_17 = 2 ;
V_8 . V_18 = V_147 ;
V_150 += V_153 ;
V_147 [ 0 ] = ( V_19 ) ( V_150 >> 8 ) ;
V_147 [ 1 ] = ( V_19 ) ( V_150 & 0xFF ) ;
V_85 = F_2 ( V_2 -> V_10 , & V_8 , 1 ) ;
if ( V_85 < 0 )
return V_85 ;
F_65 ( V_154 ) ;
V_8 . V_15 = V_2 -> V_15 ;
V_8 . V_17 = V_149 ;
V_8 . V_16 = V_21 ;
V_8 . V_18 = V_147 ;
memset ( V_147 , 0 , sizeof( V_147 ) ) ;
V_85 = F_2 ( V_2 -> V_10 , & V_8 , 1 ) ;
if ( V_85 < 0 )
return V_85 ;
V_85 = 0 ;
memcpy ( V_38 , V_147 , V_149 ) ;
V_143 -= V_149 ;
V_145 += V_149 ;
V_38 += V_149 ;
} while ( V_143 > 0 );
return V_85 ;
}
static int F_66 ( struct V_105 * V_74 )
{
struct V_71 * V_72 = F_42 ( V_74 ) ;
struct V_1 * V_2 = F_25 ( V_74 ) ;
int V_85 , V_155 , V_156 ;
V_85 = F_48 ( V_72 ) ;
if ( V_85 ) {
F_3 ( & V_2 -> V_22 , L_13 ) ;
return V_85 ;
}
V_85 = F_1 ( V_2 , V_12 ,
V_157 , & V_155 ) ;
if ( ! V_85 )
V_85 = F_1 ( V_2 , V_12 ,
V_158 , & V_156 ) ;
if ( V_85 ) {
F_3 ( & V_2 -> V_22 , L_14 ) ;
goto V_159;
}
V_72 -> V_68 = ( V_156 << 8 ) + V_155 ;
if ( V_72 -> V_68 != V_160 && V_72 -> V_68 != V_161 )
F_21 ( & V_2 -> V_22 ,
L_15 ,
V_72 -> V_68 ) ;
V_85 = F_20 ( V_2 , & V_115 ) ;
if ( V_85 ) {
F_3 ( & V_2 -> V_22 ,
L_16 ,
V_23 ) ;
goto V_159;
}
V_72 -> V_56 = F_11 ( & V_115 ,
V_55 ) ;
if ( ! V_72 -> V_56 ) {
F_3 ( & V_2 -> V_22 ,
L_17 ,
V_23 ) ;
V_85 = - V_11 ;
goto V_159;
}
F_14 ( V_72 -> V_56 , & V_72 -> V_51 ) ;
V_85 = F_12 ( V_2 , & V_115 ,
V_116 ) ;
if ( V_85 ) {
F_3 ( & V_2 -> V_22 ,
L_18 ,
V_23 ) ;
goto V_159;
}
V_85 = F_39 ( V_72 ) ;
if ( V_85 )
goto V_159;
V_85 = F_63 ( V_74 ) ;
if ( V_85 )
F_67 ( & V_2 -> V_22 ,
L_19 ) ;
V_85 = F_40 ( V_72 ) ;
if ( V_85 )
goto V_159;
V_85 = F_43 ( V_72 ) ;
if ( V_85 )
goto V_159;
return 0 ;
V_159:
F_43 ( V_72 ) ;
return V_85 ;
}
static T_4
F_68 ( struct V_162 * V_22 , struct V_163 * V_164 ,
char * V_18 )
{
struct V_105 * V_74 = F_69 ( F_70 ( V_22 ) ) ;
struct V_71 * V_72 = F_42 ( V_74 ) ;
#if V_165 < V_144
#error PAGE_SIZE too small!
#endif
memcpy ( V_18 , V_72 -> V_146 , V_144 ) ;
return V_144 ;
}
static int
F_71 ( struct V_105 * V_74 )
{
struct V_71 * V_72 = F_42 ( V_74 ) ;
struct V_1 * V_2 = F_25 ( V_74 ) ;
int V_85 ;
F_23 ( & V_2 -> V_22 , L_20 ) ;
V_85 = F_72 ( & V_2 -> V_22 , & V_166 ) ;
if ( V_85 ) {
F_3 ( & V_2 -> V_22 , L_21 ) ;
return V_85 ;
}
V_85 = F_66 ( V_74 ) ;
if ( V_85 )
goto V_167;
V_85 = F_29 ( V_72 ) ;
if ( V_85 ) {
F_3 ( & V_2 -> V_22 , L_22 ) ;
goto V_167;
}
F_57 ( V_72 , NULL , 0 , V_139 ) ;
return 0 ;
V_167:
F_73 ( & V_2 -> V_22 , & V_166 ) ;
return V_85 ;
}
static int F_74 ( struct V_71 * V_72 , bool V_168 )
{
return V_168 ? F_48 ( V_72 ) : F_43 ( V_72 ) ;
}
static int F_75 ( struct V_105 * V_74 , int V_168 )
{
struct V_71 * V_72 = F_42 ( V_74 ) ;
int V_108 = 0 ;
F_76 ( & V_72 -> V_169 ) ;
if ( V_72 -> V_170 == ! V_168 ) {
V_108 = F_74 ( V_72 , ! ! V_168 ) ;
if ( V_108 < 0 )
goto V_171;
}
V_72 -> V_170 += V_168 ? 1 : - 1 ;
F_77 ( V_72 -> V_170 < 0 ) ;
V_171:
F_78 ( & V_72 -> V_169 ) ;
return V_108 ;
}
static int F_79 ( struct V_105 * V_172 , struct V_173 * V_174 )
{
struct V_71 * V_72 = F_42 ( V_172 ) ;
struct V_39 * V_51 ;
struct V_34 * V_37 ;
V_37 = F_11 ( & V_115 , V_55 ) ;
V_51 = F_57 ( V_72 , V_174 -> V_135 , 0 ,
V_138 ) ;
F_14 ( V_37 , V_51 ) ;
return F_75 ( V_172 , true ) ;
}
static int F_80 ( struct V_105 * V_172 , struct V_173 * V_174 )
{
return F_75 ( V_172 , false ) ;
}
static int T_5 F_81 ( struct V_162 * V_22 )
{
struct V_1 * V_2 = F_70 ( V_22 ) ;
struct V_105 * V_74 = F_69 ( V_2 ) ;
struct V_71 * V_72 = F_42 ( V_74 ) ;
if ( ! V_72 -> V_170 )
return 0 ;
return F_74 ( V_72 , false ) ;
}
static int T_5 F_82 ( struct V_162 * V_22 )
{
struct V_1 * V_2 = F_70 ( V_22 ) ;
struct V_105 * V_74 = F_69 ( V_2 ) ;
struct V_71 * V_72 = F_42 ( V_74 ) ;
if ( ! V_72 -> V_170 )
return 0 ;
return F_74 ( V_72 , true ) ;
}
static int F_83 ( struct V_1 * V_2 ,
const struct V_175 * V_176 )
{
struct V_71 * V_72 ;
struct V_162 * V_22 = & V_2 -> V_22 ;
int V_108 ;
V_72 = F_84 ( & V_2 -> V_22 , sizeof( * V_72 ) , V_177 ) ;
if ( ! V_72 )
return - V_178 ;
V_72 -> V_109 = F_85 ( V_22 , L_23 , V_179 ) ;
if ( F_86 ( V_72 -> V_109 ) ) {
F_23 ( & V_2 -> V_22 , L_24 ) ;
return F_87 ( V_72 -> V_109 ) ;
}
V_72 -> V_111 = F_88 ( V_22 , L_25 ) ;
if ( F_86 ( V_72 -> V_111 ) ) {
F_3 ( & V_2 -> V_22 , L_26 ) ;
return F_87 ( V_72 -> V_111 ) ;
}
V_72 -> V_110 = F_89 ( V_22 , NULL ) ;
if ( F_86 ( V_72 -> V_110 ) ) {
F_3 ( & V_2 -> V_22 , L_27 ) ;
return F_87 ( V_72 -> V_110 ) ;
}
V_108 = F_90 ( V_22 -> V_180 , L_28 ,
& V_72 -> V_112 ) ;
if ( V_108 ) {
F_67 ( V_22 , L_29 ) ;
return V_108 ;
}
F_91 ( & V_72 -> V_169 ) ;
F_92 ( & V_72 -> V_74 , V_2 , & V_181 ) ;
V_72 -> V_74 . V_16 |= V_182 ;
V_72 -> V_74 . V_183 = & V_184 ;
V_72 -> V_135 . V_16 = V_185 ;
V_108 = F_93 ( & V_72 -> V_74 . V_186 , 1 , & V_72 -> V_135 ) ;
if ( V_108 < 0 ) {
F_3 ( & V_2 -> V_22 , L_30 ) ;
goto V_187;
}
V_108 = F_94 ( & V_72 -> V_74 ) ;
if ( V_108 < 0 )
goto V_188;
F_23 ( V_22 , L_31 ) ;
return 0 ;
V_188:
F_95 ( & V_72 -> V_74 . V_186 ) ;
V_187:
F_96 ( & V_72 -> V_169 ) ;
return V_108 ;
}
static int T_6 F_97 ( struct V_1 * V_2 )
{
struct V_105 * V_74 = F_69 ( V_2 ) ;
struct V_71 * V_72 = F_42 ( V_74 ) ;
if ( V_72 -> V_170 ) {
F_77 ( 1 ) ;
F_43 ( V_72 ) ;
V_72 -> V_170 = 0 ;
}
F_98 ( & V_72 -> V_74 ) ;
F_73 ( & V_2 -> V_22 , & V_166 ) ;
F_99 ( & V_72 -> V_89 ) ;
F_100 ( & V_72 -> V_74 ) ;
F_95 ( & V_72 -> V_74 . V_186 ) ;
F_96 ( & V_72 -> V_169 ) ;
return 0 ;
}
