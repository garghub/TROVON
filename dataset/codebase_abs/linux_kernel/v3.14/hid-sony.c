static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
* V_4 = sizeof( V_5 ) ;
return V_5 ;
}
static int F_2 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_8 * V_9 , struct V_10 * V_11 ,
unsigned long * * V_12 , int * V_13 )
{
unsigned int V_14 = V_11 -> V_15 & V_16 ;
if ( ( V_11 -> V_15 & V_17 ) != V_18 )
return - 1 ;
switch ( V_11 -> V_19 ) {
case 1 :
if ( V_14 >= F_3 ( V_20 ) )
return - 1 ;
V_14 = V_20 [ V_14 ] ;
if ( ! V_14 )
return - 1 ;
break;
case 2 :
if ( V_14 >= F_3 ( V_21 ) )
return - 1 ;
V_14 = V_21 [ V_14 ] ;
if ( ! V_14 )
return - 1 ;
break;
default:
return - 1 ;
}
F_4 ( V_7 , V_11 , V_12 , V_13 , V_22 , V_14 ) ;
return 1 ;
}
static T_1 * F_5 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
struct V_23 * V_24 = F_6 ( V_2 ) ;
if ( ( V_24 -> V_25 & V_26 ) && * V_4 >= 56 &&
V_3 [ 2 ] == 0x09 && V_3 [ 3 ] == 0x02 &&
V_3 [ 54 ] == 0x81 && V_3 [ 55 ] == 0x07 ) {
F_7 ( V_2 , L_1 ) ;
V_3 [ 55 ] = 0x06 ;
}
if ( ( V_24 -> V_25 & V_27 ) && * V_4 == 467 ) {
F_7 ( V_2 , L_2 ) ;
V_3 = V_28 ;
* V_4 = sizeof( V_28 ) ;
}
if ( ( ( ( V_24 -> V_25 & V_29 ) && * V_4 == 148 ) ||
( ( V_24 -> V_25 & V_30 ) && * V_4 == 149 ) ) &&
V_3 [ 83 ] == 0x75 ) {
F_7 ( V_2 , L_3 ) ;
memcpy ( ( void * ) & V_3 [ 83 ] , ( void * ) & V_31 ,
sizeof( V_31 ) ) ;
} else if ( V_24 -> V_25 & V_29 &&
* V_4 > sizeof( V_32 ) ) {
F_7 ( V_2 , L_4 ,
* V_4 , ( int ) sizeof( V_32 ) ) ;
* V_4 = sizeof( V_32 ) ;
memcpy ( V_3 , & V_32 , * V_4 ) ;
}
if ( V_24 -> V_25 & V_33 )
return F_1 ( V_2 , V_3 , V_4 ) ;
return V_3 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_34 * V_35 ,
T_1 * V_36 , int V_37 )
{
struct V_23 * V_24 = F_6 ( V_2 ) ;
if ( ( V_24 -> V_25 & ( V_29 | V_30 ) ) &&
V_36 [ 0 ] == 0x01 && V_37 == 49 ) {
F_9 ( V_36 [ 41 ] , V_36 [ 42 ] ) ;
F_9 ( V_36 [ 43 ] , V_36 [ 44 ] ) ;
F_9 ( V_36 [ 45 ] , V_36 [ 46 ] ) ;
F_9 ( V_36 [ 47 ] , V_36 [ 48 ] ) ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_8 * V_9 , struct V_10 * V_11 ,
unsigned long * * V_12 , int * V_13 )
{
struct V_23 * V_24 = F_6 ( V_2 ) ;
if ( V_24 -> V_25 & V_38 ) {
unsigned int V_14 = V_11 -> V_15 & V_16 ;
if ( ( V_11 -> V_15 & V_17 ) != V_18 )
return - 1 ;
switch ( V_11 -> V_19 ) {
case 1 :
if ( V_14 >= F_3 ( V_39 ) )
return - 1 ;
V_14 = V_39 [ V_14 ] ;
if ( ! V_14 )
return - 1 ;
break;
default:
return - 1 ;
}
F_4 ( V_7 , V_11 , V_12 , V_13 , V_22 , V_14 ) ;
return 1 ;
}
if ( V_24 -> V_25 & V_33 )
return F_2 ( V_2 , V_7 , V_9 , V_11 , V_12 , V_13 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_15 , T_1 * V_40 ,
T_2 V_41 , unsigned char V_42 )
{
struct V_43 * V_44 = F_12 ( V_15 -> V_45 . V_46 ) ;
struct V_47 * V_45 = F_13 ( V_44 ) ;
struct V_48 * V_49 = V_44 -> V_50 ;
int V_51 = V_40 [ 0 ] ;
int V_52 ;
if ( V_42 == V_53 ) {
V_40 ++ ;
V_41 -- ;
}
V_52 = F_14 ( V_45 , F_15 ( V_45 , 0 ) ,
V_54 ,
V_55 | V_56 | V_57 ,
( ( V_42 + 1 ) << 8 ) | V_51 ,
V_49 -> V_58 . V_59 , V_40 , V_41 ,
V_60 ) ;
if ( V_52 > 0 && V_42 == V_53 )
V_52 ++ ;
return V_52 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_52 ;
char * V_40 = F_17 ( 18 , V_61 ) ;
if ( ! V_40 )
return - V_62 ;
V_52 = V_2 -> V_63 ( V_2 , 0xf2 , V_40 , 17 , V_64 ) ;
if ( V_52 < 0 )
F_18 ( V_2 , L_5 ) ;
F_19 ( V_40 ) ;
return V_52 ;
}
static int F_20 ( struct V_1 * V_2 )
{
unsigned char V_40 [] = { 0xf4 , 0x42 , 0x03 , 0x00 , 0x00 } ;
return V_2 -> V_65 ( V_2 , V_40 , sizeof( V_40 ) , V_64 ) ;
}
static void F_21 ( struct V_1 * V_2 , const T_1 * V_66 )
{
struct V_67 * V_68 =
& V_2 -> V_69 [ V_53 ] . V_68 ;
struct V_34 * V_35 = F_22 ( V_68 -> V_70 ,
struct V_34 , V_71 ) ;
T_3 * V_72 = V_35 -> V_9 [ 0 ] -> V_72 ;
V_72 [ 0 ] = 0x00 ;
V_72 [ 1 ] = V_66 [ 0 ] ? 0xff : 0x00 ;
V_72 [ 2 ] = V_66 [ 1 ] ? 0xff : 0x00 ;
V_72 [ 3 ] = V_66 [ 2 ] ? 0xff : 0x00 ;
V_72 [ 4 ] = V_66 [ 3 ] ? 0xff : 0x00 ;
V_72 [ 5 ] = 0x00 ;
V_72 [ 6 ] = 0x00 ;
F_23 ( V_2 , V_35 , V_54 ) ;
}
static void F_24 ( struct V_1 * V_2 , const T_1 * V_66 , int V_41 )
{
struct V_23 * V_73 = F_6 ( V_2 ) ;
int V_74 ;
F_25 ( V_41 > V_75 ) ;
if ( V_73 -> V_25 & V_38 && V_41 == 4 ) {
F_21 ( V_2 , V_66 ) ;
} else if ( ( V_73 -> V_25 & V_29 ) ||
( V_73 -> V_25 & V_27 ) ) {
for ( V_74 = 0 ; V_74 < V_41 ; V_74 ++ )
V_73 -> V_76 [ V_74 ] = V_66 [ V_74 ] ;
F_26 ( & V_73 -> V_77 ) ;
}
}
static void F_27 ( struct V_78 * V_79 ,
enum V_80 V_72 )
{
struct V_81 * V_45 = V_79 -> V_45 -> V_46 ;
struct V_1 * V_2 = F_28 ( V_45 , struct V_1 , V_45 ) ;
struct V_23 * V_73 ;
int V_74 ;
V_73 = F_6 ( V_2 ) ;
if ( ! V_73 ) {
F_18 ( V_2 , L_6 ) ;
return;
}
for ( V_74 = 0 ; V_74 < V_73 -> V_82 ; V_74 ++ ) {
if ( V_79 == V_73 -> V_66 [ V_74 ] ) {
if ( V_72 != V_73 -> V_76 [ V_74 ] ) {
V_73 -> V_76 [ V_74 ] = V_72 ;
F_24 ( V_2 , V_73 -> V_76 , V_73 -> V_82 ) ;
}
break;
}
}
}
static enum V_80 F_29 ( struct V_78 * V_79 )
{
struct V_81 * V_45 = V_79 -> V_45 -> V_46 ;
struct V_1 * V_2 = F_28 ( V_45 , struct V_1 , V_45 ) ;
struct V_23 * V_73 ;
int V_74 ;
int V_83 = 0 ;
V_73 = F_6 ( V_2 ) ;
if ( ! V_73 ) {
F_18 ( V_2 , L_6 ) ;
return V_84 ;
}
for ( V_74 = 0 ; V_74 < V_73 -> V_82 ; V_74 ++ ) {
if ( V_79 == V_73 -> V_66 [ V_74 ] ) {
V_83 = ! ! ( V_73 -> V_76 [ V_74 ] ) ;
break;
}
}
return V_83 ? V_85 : V_84 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_23 * V_73 ;
struct V_78 * V_79 ;
int V_74 ;
V_73 = F_6 ( V_2 ) ;
F_25 ( ! ( V_73 -> V_25 & V_86 ) ) ;
for ( V_74 = 0 ; V_74 < V_73 -> V_82 ; V_74 ++ ) {
V_79 = V_73 -> V_66 [ V_74 ] ;
V_73 -> V_66 [ V_74 ] = NULL ;
if ( ! V_79 )
continue;
F_31 ( V_79 ) ;
F_19 ( V_79 ) ;
}
V_73 -> V_82 = 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_23 * V_73 ;
int V_74 , V_52 = 0 ;
int V_87 ;
int V_88 ;
struct V_78 * V_79 ;
T_2 V_89 ;
char * V_90 ;
T_2 V_91 ;
const char * V_92 ;
static const char * const V_93 [] = { L_7 , L_8 , L_9 } ;
static const T_1 V_94 [ V_75 ] = { 0x00 , 0x00 , 0x00 , 0x00 } ;
V_73 = F_6 ( V_2 ) ;
F_25 ( ! ( V_73 -> V_25 & V_86 ) ) ;
if ( V_73 -> V_25 & V_38 ) {
V_73 -> V_82 = 4 ;
V_87 = 1 ;
V_88 = 0 ;
V_91 = strlen ( L_10 ) ;
V_92 = L_11 ;
if ( ! F_33 ( V_2 , V_53 , 0 , 0 , 7 ) )
return - V_95 ;
} else if ( V_73 -> V_25 & V_27 ) {
V_73 -> V_82 = 3 ;
V_87 = 255 ;
V_88 = 1 ;
V_91 = 0 ;
V_92 = L_12 ;
} else {
V_73 -> V_82 = 4 ;
V_87 = 1 ;
V_88 = 0 ;
V_91 = strlen ( L_13 ) ;
V_92 = L_14 ;
}
F_24 ( V_2 , V_94 , V_73 -> V_82 ) ;
V_89 = strlen ( F_34 ( & V_2 -> V_45 ) ) + V_91 + 1 ;
for ( V_74 = 0 ; V_74 < V_73 -> V_82 ; V_74 ++ ) {
if ( V_88 )
V_89 = strlen ( F_34 ( & V_2 -> V_45 ) ) + strlen ( V_93 [ V_74 ] ) + 2 ;
V_79 = F_35 ( sizeof( struct V_78 ) + V_89 , V_61 ) ;
if ( ! V_79 ) {
F_18 ( V_2 , L_15 , V_74 ) ;
V_52 = - V_62 ;
goto V_96;
}
V_90 = ( void * ) ( & V_79 [ 1 ] ) ;
if ( V_88 )
snprintf ( V_90 , V_89 , V_92 , F_34 ( & V_2 -> V_45 ) , V_93 [ V_74 ] ) ;
else
snprintf ( V_90 , V_89 , V_92 , F_34 ( & V_2 -> V_45 ) , V_74 + 1 ) ;
V_79 -> V_90 = V_90 ;
V_79 -> V_97 = 0 ;
V_79 -> V_87 = V_87 ;
V_79 -> V_98 = F_29 ;
V_79 -> V_99 = F_27 ;
V_52 = F_36 ( & V_2 -> V_45 , V_79 ) ;
if ( V_52 ) {
F_18 ( V_2 , L_16 , V_74 ) ;
F_19 ( V_79 ) ;
goto V_96;
}
V_73 -> V_66 [ V_74 ] = V_79 ;
}
return V_52 ;
V_96:
F_30 ( V_2 ) ;
return V_52 ;
}
static void F_37 ( struct V_100 * V_101 )
{
struct V_23 * V_24 = F_28 ( V_101 , struct V_23 , V_77 ) ;
unsigned char V_40 [] = {
0x01 ,
0x00 , 0xff , 0x00 , 0xff , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0xff , 0x27 , 0x10 , 0x00 , 0x32 ,
0xff , 0x27 , 0x10 , 0x00 , 0x32 ,
0xff , 0x27 , 0x10 , 0x00 , 0x32 ,
0xff , 0x27 , 0x10 , 0x00 , 0x32 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00
} ;
#ifdef F_38
V_40 [ 3 ] = V_24 -> V_102 ? 1 : 0 ;
V_40 [ 5 ] = V_24 -> V_103 ;
#endif
V_40 [ 10 ] |= V_24 -> V_76 [ 0 ] << 1 ;
V_40 [ 10 ] |= V_24 -> V_76 [ 1 ] << 2 ;
V_40 [ 10 ] |= V_24 -> V_76 [ 2 ] << 3 ;
V_40 [ 10 ] |= V_24 -> V_76 [ 3 ] << 4 ;
V_24 -> V_2 -> V_65 ( V_24 -> V_2 , V_40 , sizeof( V_40 ) ,
V_53 ) ;
}
static void F_39 ( struct V_100 * V_101 )
{
struct V_23 * V_24 = F_28 ( V_101 , struct V_23 , V_77 ) ;
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_34 * V_35 = V_24 -> V_104 ;
T_3 * V_72 = V_35 -> V_9 [ 0 ] -> V_72 ;
V_72 [ 0 ] = 0x03 ;
#ifdef F_38
V_72 [ 3 ] = V_24 -> V_102 ;
V_72 [ 4 ] = V_24 -> V_103 ;
#endif
V_72 [ 5 ] = V_24 -> V_76 [ 0 ] ;
V_72 [ 6 ] = V_24 -> V_76 [ 1 ] ;
V_72 [ 7 ] = V_24 -> V_76 [ 2 ] ;
F_23 ( V_2 , V_35 , V_54 ) ;
}
static int F_40 ( struct V_105 * V_45 , void * V_106 ,
struct V_107 * V_108 )
{
struct V_1 * V_15 = F_41 ( V_45 ) ;
struct V_23 * V_24 = F_6 ( V_15 ) ;
if ( V_108 -> type != V_109 )
return 0 ;
V_24 -> V_103 = V_108 -> V_110 . V_111 . V_112 / 256 ;
V_24 -> V_102 = V_108 -> V_110 . V_111 . V_113 / 256 ;
F_26 ( & V_24 -> V_77 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_6 * V_114 = F_22 ( V_2 -> V_115 . V_70 ,
struct V_6 , V_71 ) ;
struct V_105 * V_105 = V_114 -> V_116 ;
F_43 ( V_105 , V_117 , V_109 ) ;
return F_44 ( V_105 , NULL , F_40 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_45 ( struct V_23 * V_24 , int V_118 , int V_119 )
{
struct V_67 * V_120 , * V_71 ;
struct V_34 * V_35 ;
struct V_1 * V_2 = V_24 -> V_2 ;
V_71 = & V_2 -> V_69 [ V_53 ] . V_68 ;
F_46 (head, list) {
V_35 = F_22 ( V_120 , struct V_34 , V_71 ) ;
if ( V_35 -> V_121 == V_118 ) {
if ( V_35 -> V_37 < V_119 ) {
F_18 ( V_2 , L_17 ,
V_118 , V_35 -> V_37 , V_119 ) ;
return - V_122 ;
}
V_24 -> V_104 = V_35 ;
return 0 ;
}
}
F_18 ( V_2 , L_18 , V_118 ) ;
return - V_122 ;
}
static int F_47 ( struct V_1 * V_2 , const struct V_123 * V_121 )
{
int V_52 ;
unsigned long V_25 = V_121 -> V_124 ;
struct V_23 * V_24 ;
unsigned int V_125 = V_126 ;
V_24 = F_48 ( & V_2 -> V_45 , sizeof( * V_24 ) , V_61 ) ;
if ( V_24 == NULL ) {
F_18 ( V_2 , L_19 ) ;
return - V_62 ;
}
V_24 -> V_25 = V_25 ;
F_49 ( V_2 , V_24 ) ;
V_24 -> V_2 = V_2 ;
V_52 = F_50 ( V_2 ) ;
if ( V_52 ) {
F_18 ( V_2 , L_20 ) ;
return V_52 ;
}
if ( V_24 -> V_25 & V_26 )
V_125 |= V_127 ;
else if ( V_24 -> V_25 & V_29 )
V_125 |= V_127 ;
else if ( V_24 -> V_25 & V_30 )
V_125 |= V_127 ;
V_52 = F_51 ( V_2 , V_125 ) ;
if ( V_52 ) {
F_18 ( V_2 , L_21 ) ;
return V_52 ;
}
if ( V_24 -> V_25 & V_29 ) {
V_2 -> V_65 = F_11 ;
V_52 = F_16 ( V_2 ) ;
V_24 -> V_128 = 1 ;
F_52 ( & V_24 -> V_77 , F_37 ) ;
}
else if ( V_24 -> V_25 & V_30 )
V_52 = F_20 ( V_2 ) ;
else if ( V_24 -> V_25 & V_27 ) {
V_52 = F_45 ( V_24 , 0x05 , 248 ) ;
if ( V_52 < 0 )
goto V_129;
V_24 -> V_128 = 1 ;
F_52 ( & V_24 -> V_77 , F_39 ) ;
} else {
V_52 = 0 ;
}
if ( V_52 < 0 )
goto V_129;
if ( V_24 -> V_25 & V_86 ) {
V_52 = F_32 ( V_2 ) ;
if ( V_52 < 0 )
goto V_129;
}
if ( V_24 -> V_25 & V_130 ) {
V_52 = F_42 ( V_2 ) ;
if ( V_52 < 0 )
goto V_129;
}
return 0 ;
V_129:
if ( V_24 -> V_25 & V_86 )
F_30 ( V_2 ) ;
F_53 ( V_2 ) ;
return V_52 ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_6 ( V_2 ) ;
if ( V_24 -> V_25 & V_86 )
F_30 ( V_2 ) ;
if ( V_24 -> V_128 )
F_55 ( & V_24 -> V_77 ) ;
F_53 ( V_2 ) ;
}
