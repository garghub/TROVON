static void T_1 F_1 ( void )
{
V_1 = F_2 ( L_1 , 1 , 1 , 4 * sizeof( long ) ) ;
F_3 ( V_1 , & V_2 ) ;
F_4 ( V_1 , 3 ) ;
}
static void T_2 F_5 ( void )
{
F_6 ( V_1 ) ;
}
static int F_7 ( const T_3 * V_3 , int V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 ;
if ( V_6 -> type != 0x01 ) {
F_8 (
L_2 ,
( int ) V_6 -> type ) ;
return - V_7 ;
}
if ( V_6 -> V_8 != 0x04 ) {
F_8 (
L_3 ,
( int ) V_6 -> V_8 ) ;
return - V_7 ;
}
if ( V_4 > 0 && V_6 -> V_9 != V_4 ) {
F_8 (
L_4 ,
( int ) V_6 -> V_9 , V_4 ) ;
return - V_7 ;
}
return 0 ;
}
static int F_9 ( T_4 V_10 ,
T_3 * * V_11 ,
struct V_12 * * V_13 ,
struct V_12 * * V_14 )
{
T_3 * V_15 ;
T_4 V_16 = sizeof( struct V_12 ) + V_10 ;
struct V_12 * V_17 , * V_18 ;
V_15 = F_10 ( 2 * V_16 , V_19 ) ;
if ( ! V_15 )
return - V_20 ;
memset ( V_15 , 0 , 2 * V_16 ) ;
V_17 = (struct V_12 * ) V_15 ;
V_18 = (struct V_12 * ) ( V_15 + V_16 ) ;
V_17 -> V_21 = sizeof( struct V_12 ) ;
V_17 -> V_22 = 0x02 ;
memcpy ( V_17 -> V_23 , L_5 , 2 ) ;
V_17 -> V_24 = V_16 ;
if ( V_10 ) {
V_17 -> V_25 =
( ( T_3 * ) V_17 ) + sizeof( struct V_12 ) ;
V_17 -> V_26 =
( ( T_3 * ) V_18 ) + sizeof( struct V_12 ) ;
}
* V_11 = V_15 ;
* V_13 = V_17 ;
* V_14 = V_18 ;
return 0 ;
}
static void F_11 ( void * V_27 , T_4 V_10 , int V_28 )
{
if ( V_28 )
F_12 ( V_27 , 2 * ( sizeof( struct V_12 ) + V_10 ) ) ;
F_13 ( V_27 ) ;
}
static inline void F_14 ( struct V_29 * V_30 ,
T_5 V_31 ,
struct V_12 * V_17 ,
struct V_12 * V_18 )
{
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
V_30 -> V_32 = 0x4341 ;
V_30 -> V_33 = ( V_31 == 0xFFFF ? V_34 : V_31 ) ;
V_30 -> V_35 =
V_17 -> V_21 + V_17 -> V_36 ;
V_30 -> V_37 = ( void V_38 * ) V_17 ;
V_30 -> V_39 = V_17 -> V_24 ;
V_30 -> V_40 = ( void V_38 * ) V_18 ;
}
static inline int F_15 ( struct V_29 * V_41 )
{
int V_42 ;
T_6 V_43 = F_16 () ;
F_17 ( V_44 ) ;
V_42 = F_18 ( V_41 ) ;
F_17 ( V_43 ) ;
return V_42 ;
}
int F_19 ( T_5 V_31 , T_5 V_45 ,
T_7 V_46 , struct V_47 * V_48 )
{
int V_49 , V_42 , V_50 ;
int V_51 ;
T_3 * V_27 ;
struct V_12 * V_17 , * V_18 ;
struct V_29 V_41 ;
struct V_52 {
T_3 V_53 [ 2 ] ;
T_5 V_54 ;
struct V_55 {
T_5 V_56 ;
char V_57 [ 8 ] ;
char V_58 [ 8 ] ;
char V_59 [ 8 ] ;
char V_60 [ 8 ] ;
} V_55 ;
struct V_61 {
T_5 V_56 ;
struct V_62 {
T_5 V_56 ;
T_5 V_63 ;
T_3 V_64 [ V_65 ] ;
} V_62 [ 6 ] ;
} V_61 ;
} * V_66 ;
struct V_67 {
T_3 V_53 [ 2 ] ;
T_5 V_54 ;
struct V_68 {
T_5 V_56 ;
T_5 V_69 ;
struct {
T_5 V_70 ;
T_5 V_71 ;
T_3 V_72 [ 0 ] ;
} V_73 ;
} V_68 ;
} * V_74 ;
V_42 = F_9 ( V_75 , & V_27 , & V_17 , & V_18 ) ;
if ( V_42 )
return V_42 ;
V_17 -> V_45 = V_45 ;
V_66 = (struct V_52 * ) V_17 -> V_25 ;
memcpy ( V_66 -> V_53 , L_6 , 2 ) ;
V_66 -> V_54 = sizeof( V_66 -> V_54 ) ;
V_66 -> V_55 . V_56 = sizeof( struct V_55 ) ;
memcpy ( V_66 -> V_55 . V_57 , L_7 , 8 ) ;
switch ( V_46 ) {
case V_76 :
V_50 = 16 ;
memcpy ( V_66 -> V_55 . V_58 , L_8 , 8 ) ;
break;
case V_77 :
V_50 = 24 ;
memcpy ( V_66 -> V_55 . V_58 , L_9 , 8 ) ;
break;
case V_78 :
V_50 = 32 ;
memcpy ( V_66 -> V_55 . V_58 , L_10 , 8 ) ;
break;
default:
F_8 (
L_11 ,
V_46 ) ;
V_42 = - V_7 ;
goto V_79;
}
memcpy ( V_66 -> V_55 . V_59 , L_12 , 8 ) ;
V_66 -> V_61 . V_56 = sizeof( struct V_61 ) ;
for ( V_49 = 0 ; V_49 < 6 ; V_49 ++ ) {
V_66 -> V_61 . V_62 [ V_49 ] . V_56 = sizeof( struct V_62 ) ;
V_66 -> V_61 . V_62 [ V_49 ] . V_63 = ( V_49 == 2 ? 0x30 : 0x10 ) ;
}
V_17 -> V_36 = sizeof( struct V_52 ) ;
F_14 ( & V_41 , V_31 , V_17 , V_18 ) ;
V_42 = F_15 ( & V_41 ) ;
if ( V_42 ) {
F_8 (
L_13 ,
( int ) V_31 , ( int ) V_45 , V_42 ) ;
goto V_79;
}
if ( V_18 -> V_80 != 0 ) {
F_8 (
L_14 ,
( int ) V_18 -> V_80 ,
( int ) V_18 -> V_81 ) ;
V_42 = - V_82 ;
goto V_79;
}
V_18 -> V_26 = ( ( T_3 * ) V_18 ) + sizeof( struct V_12 ) ;
V_74 = (struct V_67 * ) V_18 -> V_26 ;
V_51 = V_74 -> V_68 . V_73 . V_70
- sizeof( V_74 -> V_68 . V_73 . V_70 )
- sizeof( V_74 -> V_68 . V_73 . V_71 ) ;
if ( V_51 != V_65 ) {
F_8 (
L_15 ,
V_51 , V_65 ) ;
V_42 = - V_82 ;
goto V_79;
}
V_42 = F_7 ( V_74 -> V_68 . V_73 . V_72 , 8 * V_50 ) ;
if ( V_42 ) {
V_42 = - V_82 ;
goto V_79;
}
memcpy ( V_48 -> V_48 , V_74 -> V_68 . V_73 . V_72 , V_65 ) ;
V_79:
F_11 ( V_27 , V_75 , 0 ) ;
return V_42 ;
}
int F_20 ( T_5 V_31 , T_5 V_45 , T_7 V_46 ,
const struct V_83 * V_84 ,
struct V_47 * V_48 )
{
int V_42 , V_50 , V_51 ;
T_3 * V_27 ;
struct V_12 * V_17 , * V_18 ;
struct V_29 V_41 ;
struct V_85 {
T_3 V_53 [ 2 ] ;
T_5 V_54 ;
char V_86 [ 8 ] ;
struct V_55 {
T_5 V_56 ;
T_3 V_84 [ 0 ] ;
} V_55 ;
struct V_61 {
T_5 V_56 ;
struct V_62 {
T_5 V_56 ;
T_5 V_63 ;
T_3 V_64 [ V_65 ] ;
} V_62 ;
} V_61 ;
} * V_66 ;
struct V_61 * V_87 ;
struct V_88 {
T_3 V_53 [ 2 ] ;
T_5 V_54 ;
struct V_68 {
T_5 V_56 ;
T_5 V_69 ;
struct {
T_5 V_70 ;
T_5 V_71 ;
T_3 V_72 [ 0 ] ;
} V_73 ;
} V_68 ;
} * V_74 ;
V_42 = F_9 ( V_75 , & V_27 , & V_17 , & V_18 ) ;
if ( V_42 )
return V_42 ;
V_17 -> V_45 = V_45 ;
V_66 = (struct V_85 * ) V_17 -> V_25 ;
memcpy ( V_66 -> V_53 , L_16 , 2 ) ;
memcpy ( V_66 -> V_86 , L_17 , 8 ) ;
V_66 -> V_54 =
sizeof( V_66 -> V_54 ) + sizeof( V_66 -> V_86 ) ;
switch ( V_46 ) {
case V_76 :
V_50 = 16 ;
break;
case V_77 :
V_50 = 24 ;
break;
case V_78 :
V_50 = 32 ;
break;
default:
F_8 (
L_18 ,
V_46 ) ;
V_42 = - V_7 ;
goto V_79;
}
V_66 -> V_55 . V_56 = sizeof( struct V_55 ) + V_50 ;
memcpy ( V_66 -> V_55 . V_84 , V_84 -> V_84 , V_50 ) ;
V_87 = (struct V_61 * ) ( ( ( T_3 * ) & V_66 -> V_61 ) + V_50 ) ;
V_87 -> V_56 = sizeof( struct V_61 ) ;
V_87 -> V_62 . V_56 = sizeof( struct V_62 ) ;
V_87 -> V_62 . V_63 = 0x30 ;
V_17 -> V_36 = sizeof( struct V_85 ) + V_50 ;
F_14 ( & V_41 , V_31 , V_17 , V_18 ) ;
V_42 = F_15 ( & V_41 ) ;
if ( V_42 ) {
F_8 (
L_19 ,
( int ) V_31 , ( int ) V_45 , V_42 ) ;
goto V_79;
}
if ( V_18 -> V_80 != 0 ) {
F_8 (
L_20 ,
( int ) V_18 -> V_80 ,
( int ) V_18 -> V_81 ) ;
V_42 = - V_82 ;
goto V_79;
}
V_18 -> V_26 = ( ( T_3 * ) V_18 ) + sizeof( struct V_12 ) ;
V_74 = (struct V_88 * ) V_18 -> V_26 ;
V_51 = V_74 -> V_68 . V_73 . V_70
- sizeof( V_74 -> V_68 . V_73 . V_70 )
- sizeof( V_74 -> V_68 . V_73 . V_71 ) ;
if ( V_51 != V_65 ) {
F_8 (
L_21 ,
V_51 , V_65 ) ;
V_42 = - V_82 ;
goto V_79;
}
V_42 = F_7 ( V_74 -> V_68 . V_73 . V_72 , 8 * V_50 ) ;
if ( V_42 ) {
V_42 = - V_82 ;
goto V_79;
}
memcpy ( V_48 -> V_48 , V_74 -> V_68 . V_73 . V_72 , V_65 ) ;
V_79:
F_11 ( V_27 , V_75 , 1 ) ;
return V_42 ;
}
int F_21 ( T_5 V_31 , T_5 V_45 ,
const struct V_47 * V_48 ,
struct V_89 * V_90 )
{
int V_42 ;
T_3 * V_27 ;
struct V_12 * V_17 , * V_18 ;
struct V_29 V_41 ;
struct V_91 {
T_3 V_53 [ 2 ] ;
T_5 V_54 ;
struct V_55 {
T_5 V_56 ;
T_5 V_92 ;
T_5 V_93 ;
} V_55 ;
struct V_61 {
T_5 V_56 ;
T_5 V_92 ;
T_5 V_93 ;
T_3 V_3 [ 0 ] ;
} V_61 V_94 ;
} * V_66 ;
struct V_95 {
T_3 V_53 [ 2 ] ;
T_5 V_54 ;
struct V_68 {
T_5 V_56 ;
T_5 V_92 ;
T_5 V_93 ;
struct V_96 {
T_3 V_8 ;
T_3 V_97 [ 2 ] ;
T_3 V_98 ;
T_3 V_99 ;
T_3 V_100 [ 3 ] ;
T_5 V_101 ;
T_3 V_102 [ 64 ] ;
T_5 V_103 ;
T_3 V_104 [ 32 ] ;
T_3 V_105 [ 1 ] ;
T_3 V_106 ;
T_3 V_107 [ 32 ] ;
} V_73 ;
} V_68 V_94 ;
} * V_74 ;
V_42 = F_9 ( V_75 , & V_27 , & V_17 , & V_18 ) ;
if ( V_42 )
return V_42 ;
V_17 -> V_45 = V_45 ;
V_66 = (struct V_91 * ) V_17 -> V_25 ;
memcpy ( V_66 -> V_53 , L_22 , 2 ) ;
V_66 -> V_54 = sizeof( V_66 -> V_54 ) ;
V_66 -> V_55 . V_56 = sizeof( struct V_55 ) ;
V_66 -> V_55 . V_92 = sizeof( struct V_55 ) - sizeof( V_66 -> V_55 . V_56 ) ;
V_66 -> V_55 . V_93 = 0x0001 ;
V_66 -> V_61 . V_56 = sizeof( struct V_61 ) + V_65 ;
V_66 -> V_61 . V_92 = sizeof( struct V_61 )
- sizeof( V_66 -> V_61 . V_56 ) + V_65 ;
V_66 -> V_61 . V_93 = 0x0000 ;
memcpy ( V_66 -> V_61 . V_3 , V_48 -> V_48 , V_65 ) ;
V_17 -> V_36 = sizeof( struct V_91 ) + V_65 ;
F_14 ( & V_41 , V_31 , V_17 , V_18 ) ;
V_42 = F_15 ( & V_41 ) ;
if ( V_42 ) {
F_8 (
L_23 ,
( int ) V_31 , ( int ) V_45 , V_42 ) ;
goto V_79;
}
if ( V_18 -> V_80 != 0 ) {
F_8 (
L_24 ,
( int ) V_18 -> V_80 ,
( int ) V_18 -> V_81 ) ;
V_42 = - V_82 ;
goto V_79;
}
if ( V_18 -> V_81 != 0 ) {
F_22 (
L_25 ,
( int ) V_18 -> V_80 ,
( int ) V_18 -> V_81 ) ;
}
V_18 -> V_26 = ( ( T_3 * ) V_18 ) + sizeof( struct V_12 ) ;
V_74 = (struct V_95 * ) V_18 -> V_26 ;
if ( V_74 -> V_68 . V_73 . V_8 != 0x01 ) {
F_8 (
L_26 ,
( int ) V_74 -> V_68 . V_73 . V_8 ) ;
V_42 = - V_82 ;
goto V_79;
}
switch ( V_74 -> V_68 . V_73 . V_101 ) {
case 16 + 32 :
V_90 -> type = V_76 ;
break;
case 24 + 32 :
V_90 -> type = V_77 ;
break;
case 32 + 32 :
V_90 -> type = V_78 ;
break;
default:
F_8 ( L_27 ,
V_74 -> V_68 . V_73 . V_101 ) ;
V_42 = - V_82 ;
goto V_79;
}
V_90 -> V_56 = V_74 -> V_68 . V_73 . V_101 ;
memcpy ( V_90 -> V_90 , V_74 -> V_68 . V_73 . V_102 , V_90 -> V_56 ) ;
V_79:
F_11 ( V_27 , V_75 , 0 ) ;
return V_42 ;
}
int F_23 ( T_7 V_46 ,
const struct V_83 * V_84 ,
struct V_89 * V_90 )
{
long V_108 ;
int V_50 ;
T_3 V_109 [ 64 ] ;
switch ( V_46 ) {
case V_76 :
V_50 = 16 ;
V_108 = V_110 ;
break;
case V_77 :
V_50 = 24 ;
V_108 = V_111 ;
break;
case V_78 :
V_50 = 32 ;
V_108 = V_112 ;
break;
default:
F_8 ( L_28 ,
V_46 ) ;
return - V_7 ;
}
memset ( V_109 , 0 , sizeof( V_109 ) ) ;
memcpy ( V_109 , V_84 -> V_84 , V_50 ) ;
F_24 ( V_108 , V_109 ) ;
V_90 -> type = V_46 ;
V_90 -> V_56 = V_50 + 32 ;
memcpy ( V_90 -> V_90 , V_109 , V_50 + 32 ) ;
return 0 ;
}
static int F_25 ( T_5 V_31 , T_5 V_45 ,
const char * V_113 ,
T_3 * V_114 , T_4 * V_115 ,
T_3 * V_116 , T_4 * V_117 )
{
int V_42 ;
T_5 V_56 ;
T_3 * V_27 , * V_118 ;
struct V_12 * V_17 , * V_18 ;
struct V_29 V_41 ;
struct V_119 {
T_3 V_53 [ 2 ] ;
T_5 V_54 ;
char V_86 [ 8 ] ;
struct V_55 {
T_5 V_56 ;
T_3 V_64 [ V_120 ] ;
} V_55 ;
T_5 V_121 ;
} * V_66 ;
T_4 V_122 = sizeof( struct V_119 ) ;
struct V_123 {
T_3 V_53 [ 2 ] ;
T_3 V_124 [ 0 ] ;
} * V_74 ;
V_42 = F_9 ( V_122 , & V_27 , & V_17 , & V_18 ) ;
if ( V_42 )
return V_42 ;
V_17 -> V_45 = V_45 ;
V_66 = (struct V_119 * ) V_17 -> V_25 ;
memcpy ( V_66 -> V_53 , L_29 , 2 ) ;
strncpy ( V_66 -> V_86 , V_113 , sizeof( V_66 -> V_86 ) ) ;
V_66 -> V_54 =
sizeof( V_66 -> V_54 ) + sizeof( V_66 -> V_86 ) ;
V_66 -> V_55 . V_56 = sizeof( V_66 -> V_55 ) ;
V_66 -> V_121 = sizeof( V_66 -> V_121 ) ;
V_17 -> V_36 = V_122 ;
F_14 ( & V_41 , V_31 , V_17 , V_18 ) ;
V_42 = F_15 ( & V_41 ) ;
if ( V_42 ) {
F_8 (
L_30 ,
( int ) V_31 , ( int ) V_45 , V_42 ) ;
goto V_79;
}
if ( V_18 -> V_80 != 0 ) {
F_8 (
L_31 ,
( int ) V_18 -> V_80 ,
( int ) V_18 -> V_81 ) ;
V_42 = - V_82 ;
goto V_79;
}
V_18 -> V_26 = ( ( T_3 * ) V_18 ) + sizeof( struct V_12 ) ;
V_74 = (struct V_123 * ) V_18 -> V_26 ;
V_118 = V_74 -> V_124 ;
V_56 = * ( ( T_5 * ) V_118 ) ;
if ( V_56 > sizeof( T_5 ) ) {
V_118 += sizeof( T_5 ) ;
V_56 -= sizeof( T_5 ) ;
if ( V_114 && V_115 && * V_115 > 0 ) {
* V_115 = ( V_56 > * V_115 ? * V_115 : V_56 ) ;
memcpy ( V_114 , V_118 , * V_115 ) ;
}
V_118 += V_56 ;
}
V_56 = * ( ( T_5 * ) V_118 ) ;
if ( V_56 > sizeof( T_5 ) ) {
V_118 += sizeof( T_5 ) ;
V_56 -= sizeof( T_5 ) ;
if ( V_116 && V_117 && * V_117 > 0 ) {
* V_117 = ( V_56 > * V_117 ? * V_117 : V_56 ) ;
memcpy ( V_116 , V_118 , * V_117 ) ;
}
V_118 += V_56 ;
}
V_79:
F_11 ( V_27 , V_122 , 0 ) ;
return V_42 ;
}
static int F_26 ( T_5 V_31 , T_5 V_45 , T_8 V_125 [ 2 ] )
{
int V_42 , V_126 = 0 ;
T_4 V_127 , V_128 ;
T_3 * V_114 , * V_116 , * V_129 ;
V_129 = ( T_3 * ) F_27 ( V_19 ) ;
if ( ! V_129 )
return - V_20 ;
V_114 = V_129 ;
V_116 = V_129 + V_130 / 2 ;
V_127 = V_128 = V_130 / 2 ;
V_42 = F_25 ( V_31 , V_45 , L_32 ,
V_114 , & V_127 , V_116 , & V_128 ) ;
if ( V_42 == 0 && V_127 > 8 * 8 && V_128 > 184 + 8 ) {
if ( V_114 [ 8 * 8 ] == '2' ) {
V_125 [ 0 ] = * ( ( T_8 * ) ( V_116 + 184 ) ) ;
V_125 [ 1 ] = * ( ( T_8 * ) ( V_116 + 172 ) ) ;
V_126 = 1 ;
}
}
F_28 ( ( unsigned long ) V_129 ) ;
return V_126 ? 0 : - V_131 ;
}
static int F_29 ( T_5 V_31 , T_5 V_45 , T_8 V_125 [ 2 ] )
{
int V_42 = - V_131 ;
struct V_132 * V_118 ;
F_30 ( & V_133 ) ;
F_31 (ptr, &mkvp_list, list) {
if ( V_118 -> V_31 == V_31 &&
V_118 -> V_45 == V_45 ) {
memcpy ( V_125 , V_118 -> V_125 , 2 * sizeof( T_8 ) ) ;
V_42 = 0 ;
break;
}
}
F_32 ( & V_133 ) ;
return V_42 ;
}
static void F_33 ( T_5 V_31 , T_5 V_45 , T_8 V_125 [ 2 ] )
{
int V_126 = 0 ;
struct V_132 * V_118 ;
F_30 ( & V_133 ) ;
F_31 (ptr, &mkvp_list, list) {
if ( V_118 -> V_31 == V_31 &&
V_118 -> V_45 == V_45 ) {
memcpy ( V_118 -> V_125 , V_125 , 2 * sizeof( T_8 ) ) ;
V_126 = 1 ;
break;
}
}
if ( ! V_126 ) {
V_118 = F_10 ( sizeof( * V_118 ) , V_134 ) ;
if ( ! V_118 ) {
F_32 ( & V_133 ) ;
return;
}
V_118 -> V_31 = V_31 ;
V_118 -> V_45 = V_45 ;
memcpy ( V_118 -> V_125 , V_125 , 2 * sizeof( T_8 ) ) ;
F_34 ( & V_118 -> V_135 , & V_136 ) ;
}
F_32 ( & V_133 ) ;
}
static void F_35 ( T_5 V_31 , T_5 V_45 )
{
struct V_132 * V_118 ;
F_30 ( & V_133 ) ;
F_31 (ptr, &mkvp_list, list) {
if ( V_118 -> V_31 == V_31 &&
V_118 -> V_45 == V_45 ) {
F_36 ( & V_118 -> V_135 ) ;
F_13 ( V_118 ) ;
break;
}
}
F_32 ( & V_133 ) ;
}
static void T_2 F_37 ( void )
{
struct V_132 * V_118 , * V_137 ;
F_30 ( & V_133 ) ;
F_38 (ptr, pnext, &mkvp_list, list) {
F_36 ( & V_118 -> V_135 ) ;
F_13 ( V_118 ) ;
}
F_32 ( & V_133 ) ;
}
int F_39 ( const struct V_47 * V_48 ,
T_5 * V_138 , T_5 * V_139 , int V_140 )
{
struct V_5 * V_6 = (struct V_5 * ) V_48 ;
struct V_141 * V_142 ;
T_5 V_143 , V_144 ;
T_8 V_125 [ 2 ] ;
int V_49 , V_42 , V_145 = - 1 ;
if ( V_6 -> V_125 == 0 )
return - V_7 ;
V_142 = F_10 ( sizeof( struct V_141 ) ,
V_19 ) ;
if ( ! V_142 )
return - V_20 ;
F_40 ( V_142 ) ;
for ( V_49 = 0 ; V_49 < V_146 ; V_49 ++ ) {
V_143 = F_41 ( V_142 -> V_147 [ V_49 ] . V_148 ) ;
V_144 = F_42 ( V_142 -> V_147 [ V_49 ] . V_148 ) ;
if ( V_142 -> V_147 [ V_49 ] . V_149 &&
V_142 -> V_147 [ V_49 ] . V_150 & 0x04 ) {
if ( F_29 ( V_143 , V_144 , V_125 ) == 0 &&
V_6 -> V_125 == V_125 [ 0 ] ) {
if ( ! V_140 )
break;
if ( F_26 ( V_143 , V_144 , V_125 ) == 0 ) {
F_33 ( V_143 , V_144 , V_125 ) ;
if ( V_6 -> V_125 == V_125 [ 0 ] )
break;
}
}
} else {
F_35 ( V_143 , V_144 ) ;
}
}
if ( V_49 >= V_146 ) {
for ( V_49 = 0 ; V_49 < V_146 ; V_49 ++ ) {
if ( ! ( V_142 -> V_147 [ V_49 ] . V_149 &&
V_142 -> V_147 [ V_49 ] . V_150 & 0x04 ) )
continue;
V_143 = F_41 ( V_142 -> V_147 [ V_49 ] . V_148 ) ;
V_144 = F_42 ( V_142 -> V_147 [ V_49 ] . V_148 ) ;
if ( F_26 ( V_143 , V_144 , V_125 ) == 0 ) {
F_33 ( V_143 , V_144 , V_125 ) ;
if ( V_6 -> V_125 == V_125 [ 0 ] )
break;
if ( V_6 -> V_125 == V_125 [ 1 ] && V_145 < 0 )
V_145 = V_49 ;
}
}
if ( V_49 >= V_146 && V_145 >= 0 ) {
V_143 = F_41 ( V_142 -> V_147 [ V_145 ] . V_148 ) ;
V_144 = F_42 ( V_142 -> V_147 [ V_145 ] . V_148 ) ;
}
}
if ( V_49 < V_146 || V_145 >= 0 ) {
if ( V_138 )
* V_138 = V_143 ;
if ( V_139 )
* V_139 = V_144 ;
V_42 = 0 ;
} else
V_42 = - V_151 ;
F_13 ( V_142 ) ;
return V_42 ;
}
int F_43 ( const struct V_47 * V_48 ,
struct V_89 * V_90 )
{
T_5 V_31 , V_45 ;
int V_42 , V_140 ;
for ( V_140 = 0 ; V_140 < 2 ; V_140 ++ ) {
V_42 = F_39 ( V_48 , & V_31 , & V_45 , V_140 ) ;
if ( V_42 )
continue;
V_42 = F_21 ( V_31 , V_45 , V_48 , V_90 ) ;
if ( V_42 == 0 )
break;
}
if ( V_42 )
F_44 ( L_33 , V_42 ) ;
return V_42 ;
}
int F_45 ( const struct V_47 * V_48 ,
T_5 * V_138 , T_5 * V_139 ,
T_5 * V_152 , T_7 * V_153 )
{
struct V_5 * V_6 = (struct V_5 * ) V_48 ;
T_5 V_31 , V_45 ;
T_8 V_125 [ 2 ] ;
int V_42 ;
V_42 = F_7 ( ( T_3 * ) V_48 , 0 ) ;
if ( V_42 )
goto V_79;
if ( V_153 )
* V_153 = V_154 ;
if ( V_152 )
* V_152 = V_6 -> V_9 ;
V_42 = F_39 ( V_48 , & V_31 , & V_45 , 1 ) ;
if ( V_42 )
goto V_79;
V_42 = F_29 ( V_31 , V_45 , V_125 ) ;
if ( V_42 )
goto V_79;
if ( V_6 -> V_125 == V_125 [ 1 ] ) {
F_44 ( L_34 ) ;
if ( V_153 )
* V_153 |= V_155 ;
}
if ( V_138 )
* V_138 = V_31 ;
if ( V_139 )
* V_139 = V_45 ;
V_79:
F_44 ( L_35 , V_42 ) ;
return V_42 ;
}
static long F_46 ( struct V_156 * V_157 , unsigned int V_158 ,
unsigned long V_159 )
{
int V_42 ;
switch ( V_158 ) {
case V_160 : {
struct V_161 V_38 * V_162 = ( void V_38 * ) V_159 ;
struct V_161 V_163 ;
if ( F_47 ( & V_163 , V_162 , sizeof( V_163 ) ) )
return - V_164 ;
V_42 = F_19 ( V_163 . V_31 , V_163 . V_45 ,
V_163 . V_46 , & V_163 . V_48 ) ;
F_44 ( L_36 , V_42 ) ;
if ( V_42 )
break;
if ( F_48 ( V_162 , & V_163 , sizeof( V_163 ) ) )
return - V_164 ;
break;
}
case V_165 : {
struct V_166 V_38 * V_167 = ( void V_38 * ) V_159 ;
struct V_166 V_168 ;
if ( F_47 ( & V_168 , V_167 , sizeof( V_168 ) ) )
return - V_164 ;
V_42 = F_20 ( V_168 . V_31 , V_168 . V_45 , V_168 . V_46 ,
& V_168 . V_84 , & V_168 . V_48 ) ;
F_44 ( L_37 , V_42 ) ;
if ( V_42 )
break;
if ( F_48 ( V_167 , & V_168 , sizeof( V_168 ) ) )
return - V_164 ;
F_12 ( & V_168 , sizeof( V_168 ) ) ;
break;
}
case V_169 : {
struct V_170 V_38 * V_171 = ( void V_38 * ) V_159 ;
struct V_170 V_172 ;
if ( F_47 ( & V_172 , V_171 , sizeof( V_172 ) ) )
return - V_164 ;
V_42 = F_21 ( V_172 . V_31 , V_172 . V_45 ,
& V_172 . V_48 , & V_172 . V_90 ) ;
F_44 ( L_38 , V_42 ) ;
if ( V_42 )
break;
if ( F_48 ( V_171 , & V_172 , sizeof( V_172 ) ) )
return - V_164 ;
break;
}
case V_173 : {
struct V_174 V_38 * V_175 = ( void V_38 * ) V_159 ;
struct V_174 V_176 ;
if ( F_47 ( & V_176 , V_175 , sizeof( V_176 ) ) )
return - V_164 ;
V_42 = F_23 ( V_176 . V_46 ,
& V_176 . V_84 , & V_176 . V_90 ) ;
F_44 ( L_39 , V_42 ) ;
if ( V_42 )
break;
if ( F_48 ( V_175 , & V_176 , sizeof( V_176 ) ) )
return - V_164 ;
F_12 ( & V_176 , sizeof( V_176 ) ) ;
break;
}
case V_177 : {
struct F_39 V_38 * V_178 = ( void V_38 * ) V_159 ;
struct F_39 V_179 ;
if ( F_47 ( & V_179 , V_178 , sizeof( V_179 ) ) )
return - V_164 ;
V_42 = F_39 ( & V_179 . V_48 ,
& V_179 . V_31 , & V_179 . V_45 , 1 ) ;
F_44 ( L_40 , V_42 ) ;
if ( V_42 )
break;
if ( F_48 ( V_178 , & V_179 , sizeof( V_179 ) ) )
return - V_164 ;
break;
}
case V_180 : {
struct F_43 V_38 * V_171 = ( void V_38 * ) V_159 ;
struct F_43 V_172 ;
if ( F_47 ( & V_172 , V_171 , sizeof( V_172 ) ) )
return - V_164 ;
V_42 = F_43 ( & V_172 . V_48 , & V_172 . V_90 ) ;
F_44 ( L_41 , V_42 ) ;
if ( V_42 )
break;
if ( F_48 ( V_171 , & V_172 , sizeof( V_172 ) ) )
return - V_164 ;
break;
}
case V_181 : {
struct F_45 V_38 * V_182 = ( void V_38 * ) V_159 ;
struct F_45 V_183 ;
if ( F_47 ( & V_183 , V_182 , sizeof( V_183 ) ) )
return - V_164 ;
V_42 = F_45 ( & V_183 . V_48 , & V_183 . V_31 , & V_183 . V_45 ,
& V_183 . V_50 , & V_183 . V_184 ) ;
F_44 ( L_42 , V_42 ) ;
if ( V_42 )
break;
if ( F_48 ( V_182 , & V_183 , sizeof( V_183 ) ) )
return - V_164 ;
break;
}
default:
return - V_185 ;
}
return V_42 ;
}
static int T_1 F_49 ( void )
{
T_9 V_186 ;
if ( ! F_50 ( V_187 , & V_186 ) )
return - V_188 ;
if ( ! F_51 ( & V_186 , V_110 ) ||
! F_51 ( & V_186 , V_111 ) ||
! F_51 ( & V_186 , V_112 ) )
return - V_188 ;
F_1 () ;
return F_52 ( & V_189 ) ;
}
static void T_2 F_53 ( void )
{
F_54 ( & V_189 ) ;
F_37 () ;
F_5 () ;
}
