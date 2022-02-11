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
V_30 -> V_37 = ( void * ) V_17 ;
V_30 -> V_38 = V_17 -> V_24 ;
V_30 -> V_39 = ( void * ) V_18 ;
}
static inline int F_15 ( struct V_29 * V_40 )
{
int V_41 ;
T_6 V_42 = F_16 () ;
F_17 ( V_43 ) ;
V_41 = F_18 ( V_40 ) ;
F_17 ( V_42 ) ;
return V_41 ;
}
int F_19 ( T_5 V_31 , T_5 V_44 ,
T_7 V_45 , struct V_46 * V_47 )
{
int V_48 , V_41 , V_49 ;
int V_50 ;
T_3 * V_27 ;
struct V_12 * V_17 , * V_18 ;
struct V_29 V_40 ;
struct V_51 {
T_3 V_52 [ 2 ] ;
T_5 V_53 ;
struct V_54 {
T_5 V_55 ;
char V_56 [ 8 ] ;
char V_57 [ 8 ] ;
char V_58 [ 8 ] ;
char V_59 [ 8 ] ;
} V_54 ;
struct V_60 {
T_5 V_55 ;
struct V_61 {
T_5 V_55 ;
T_5 V_62 ;
T_3 V_63 [ V_64 ] ;
} V_61 [ 6 ] ;
} V_60 ;
} * V_65 ;
struct V_66 {
T_3 V_52 [ 2 ] ;
T_5 V_53 ;
struct V_67 {
T_5 V_55 ;
T_5 V_68 ;
struct {
T_5 V_69 ;
T_5 V_70 ;
T_3 V_71 [ 0 ] ;
} V_72 ;
} V_67 ;
} * V_73 ;
V_41 = F_9 ( V_74 , & V_27 , & V_17 , & V_18 ) ;
if ( V_41 )
return V_41 ;
V_17 -> V_44 = V_44 ;
V_65 = (struct V_51 * ) V_17 -> V_25 ;
memcpy ( V_65 -> V_52 , L_6 , 2 ) ;
V_65 -> V_53 = sizeof( V_65 -> V_53 ) ;
V_65 -> V_54 . V_55 = sizeof( struct V_54 ) ;
memcpy ( V_65 -> V_54 . V_56 , L_7 , 8 ) ;
switch ( V_45 ) {
case V_75 :
V_49 = 16 ;
memcpy ( V_65 -> V_54 . V_57 , L_8 , 8 ) ;
break;
case V_76 :
V_49 = 24 ;
memcpy ( V_65 -> V_54 . V_57 , L_9 , 8 ) ;
break;
case V_77 :
V_49 = 32 ;
memcpy ( V_65 -> V_54 . V_57 , L_10 , 8 ) ;
break;
default:
F_8 (
L_11 ,
V_45 ) ;
V_41 = - V_7 ;
goto V_78;
}
memcpy ( V_65 -> V_54 . V_58 , L_12 , 8 ) ;
V_65 -> V_60 . V_55 = sizeof( struct V_60 ) ;
for ( V_48 = 0 ; V_48 < 6 ; V_48 ++ ) {
V_65 -> V_60 . V_61 [ V_48 ] . V_55 = sizeof( struct V_61 ) ;
V_65 -> V_60 . V_61 [ V_48 ] . V_62 = ( V_48 == 2 ? 0x30 : 0x10 ) ;
}
V_17 -> V_36 = sizeof( struct V_51 ) ;
F_14 ( & V_40 , V_31 , V_17 , V_18 ) ;
V_41 = F_15 ( & V_40 ) ;
if ( V_41 ) {
F_8 (
L_13 ,
( int ) V_31 , ( int ) V_44 , V_41 ) ;
goto V_78;
}
if ( V_18 -> V_79 != 0 ) {
F_8 (
L_14 ,
( int ) V_18 -> V_79 ,
( int ) V_18 -> V_80 ) ;
V_41 = - V_81 ;
goto V_78;
}
V_18 -> V_26 = ( ( T_3 * ) V_18 ) + sizeof( struct V_12 ) ;
V_73 = (struct V_66 * ) V_18 -> V_26 ;
V_50 = V_73 -> V_67 . V_72 . V_69
- sizeof( V_73 -> V_67 . V_72 . V_69 )
- sizeof( V_73 -> V_67 . V_72 . V_70 ) ;
if ( V_50 != V_64 ) {
F_8 (
L_15 ,
V_50 , V_64 ) ;
V_41 = - V_81 ;
goto V_78;
}
V_41 = F_7 ( V_73 -> V_67 . V_72 . V_71 , 8 * V_49 ) ;
if ( V_41 ) {
V_41 = - V_81 ;
goto V_78;
}
memcpy ( V_47 -> V_47 , V_73 -> V_67 . V_72 . V_71 , V_64 ) ;
V_78:
F_11 ( V_27 , V_74 , 0 ) ;
return V_41 ;
}
int F_20 ( T_5 V_31 , T_5 V_44 , T_7 V_45 ,
const struct V_82 * V_83 ,
struct V_46 * V_47 )
{
int V_41 , V_49 , V_50 ;
T_3 * V_27 ;
struct V_12 * V_17 , * V_18 ;
struct V_29 V_40 ;
struct V_84 {
T_3 V_52 [ 2 ] ;
T_5 V_53 ;
char V_85 [ 8 ] ;
struct V_54 {
T_5 V_55 ;
T_3 V_83 [ 0 ] ;
} V_54 ;
struct V_60 {
T_5 V_55 ;
struct V_61 {
T_5 V_55 ;
T_5 V_62 ;
T_3 V_63 [ V_64 ] ;
} V_61 ;
} V_60 ;
} * V_65 ;
struct V_60 * V_86 ;
struct V_87 {
T_3 V_52 [ 2 ] ;
T_5 V_53 ;
struct V_67 {
T_5 V_55 ;
T_5 V_68 ;
struct {
T_5 V_69 ;
T_5 V_70 ;
T_3 V_71 [ 0 ] ;
} V_72 ;
} V_67 ;
} * V_73 ;
V_41 = F_9 ( V_74 , & V_27 , & V_17 , & V_18 ) ;
if ( V_41 )
return V_41 ;
V_17 -> V_44 = V_44 ;
V_65 = (struct V_84 * ) V_17 -> V_25 ;
memcpy ( V_65 -> V_52 , L_16 , 2 ) ;
memcpy ( V_65 -> V_85 , L_17 , 8 ) ;
V_65 -> V_53 =
sizeof( V_65 -> V_53 ) + sizeof( V_65 -> V_85 ) ;
switch ( V_45 ) {
case V_75 :
V_49 = 16 ;
break;
case V_76 :
V_49 = 24 ;
break;
case V_77 :
V_49 = 32 ;
break;
default:
F_8 (
L_18 ,
V_45 ) ;
V_41 = - V_7 ;
goto V_78;
}
V_65 -> V_54 . V_55 = sizeof( struct V_54 ) + V_49 ;
memcpy ( V_65 -> V_54 . V_83 , V_83 -> V_83 , V_49 ) ;
V_86 = (struct V_60 * ) ( ( ( T_3 * ) & V_65 -> V_60 ) + V_49 ) ;
V_86 -> V_55 = sizeof( struct V_60 ) ;
V_86 -> V_61 . V_55 = sizeof( struct V_61 ) ;
V_86 -> V_61 . V_62 = 0x30 ;
V_17 -> V_36 = sizeof( struct V_84 ) + V_49 ;
F_14 ( & V_40 , V_31 , V_17 , V_18 ) ;
V_41 = F_15 ( & V_40 ) ;
if ( V_41 ) {
F_8 (
L_19 ,
( int ) V_31 , ( int ) V_44 , V_41 ) ;
goto V_78;
}
if ( V_18 -> V_79 != 0 ) {
F_8 (
L_20 ,
( int ) V_18 -> V_79 ,
( int ) V_18 -> V_80 ) ;
V_41 = - V_81 ;
goto V_78;
}
V_18 -> V_26 = ( ( T_3 * ) V_18 ) + sizeof( struct V_12 ) ;
V_73 = (struct V_87 * ) V_18 -> V_26 ;
V_50 = V_73 -> V_67 . V_72 . V_69
- sizeof( V_73 -> V_67 . V_72 . V_69 )
- sizeof( V_73 -> V_67 . V_72 . V_70 ) ;
if ( V_50 != V_64 ) {
F_8 (
L_21 ,
V_50 , V_64 ) ;
V_41 = - V_81 ;
goto V_78;
}
V_41 = F_7 ( V_73 -> V_67 . V_72 . V_71 , 8 * V_49 ) ;
if ( V_41 ) {
V_41 = - V_81 ;
goto V_78;
}
memcpy ( V_47 -> V_47 , V_73 -> V_67 . V_72 . V_71 , V_64 ) ;
V_78:
F_11 ( V_27 , V_74 , 1 ) ;
return V_41 ;
}
int F_21 ( T_5 V_31 , T_5 V_44 ,
const struct V_46 * V_47 ,
struct V_88 * V_89 )
{
int V_41 ;
T_3 * V_27 ;
struct V_12 * V_17 , * V_18 ;
struct V_29 V_40 ;
struct V_90 {
T_3 V_52 [ 2 ] ;
T_5 V_53 ;
struct V_54 {
T_5 V_55 ;
T_5 V_91 ;
T_5 V_92 ;
} V_54 ;
struct V_60 {
T_5 V_55 ;
T_5 V_91 ;
T_5 V_92 ;
T_3 V_3 [ 0 ] ;
} V_60 V_93 ;
} * V_65 ;
struct V_94 {
T_3 V_52 [ 2 ] ;
T_5 V_53 ;
struct V_67 {
T_5 V_55 ;
T_5 V_91 ;
T_5 V_92 ;
struct V_95 {
T_3 V_8 ;
T_3 V_96 [ 2 ] ;
T_3 V_97 ;
T_3 V_98 ;
T_3 V_99 [ 3 ] ;
T_5 V_100 ;
T_3 V_101 [ 64 ] ;
T_5 V_102 ;
T_3 V_103 [ 32 ] ;
T_3 V_104 [ 1 ] ;
T_3 V_105 ;
T_3 V_106 [ 32 ] ;
} V_72 ;
} V_67 V_93 ;
} * V_73 ;
V_41 = F_9 ( V_74 , & V_27 , & V_17 , & V_18 ) ;
if ( V_41 )
return V_41 ;
V_17 -> V_44 = V_44 ;
V_65 = (struct V_90 * ) V_17 -> V_25 ;
memcpy ( V_65 -> V_52 , L_22 , 2 ) ;
V_65 -> V_53 = sizeof( V_65 -> V_53 ) ;
V_65 -> V_54 . V_55 = sizeof( struct V_54 ) ;
V_65 -> V_54 . V_91 = sizeof( struct V_54 ) - sizeof( V_65 -> V_54 . V_55 ) ;
V_65 -> V_54 . V_92 = 0x0001 ;
V_65 -> V_60 . V_55 = sizeof( struct V_60 ) + V_64 ;
V_65 -> V_60 . V_91 = sizeof( struct V_60 )
- sizeof( V_65 -> V_60 . V_55 ) + V_64 ;
V_65 -> V_60 . V_92 = 0x0000 ;
memcpy ( V_65 -> V_60 . V_3 , V_47 -> V_47 , V_64 ) ;
V_17 -> V_36 = sizeof( struct V_90 ) + V_64 ;
F_14 ( & V_40 , V_31 , V_17 , V_18 ) ;
V_41 = F_15 ( & V_40 ) ;
if ( V_41 ) {
F_8 (
L_23 ,
( int ) V_31 , ( int ) V_44 , V_41 ) ;
goto V_78;
}
if ( V_18 -> V_79 != 0 ) {
F_8 (
L_24 ,
( int ) V_18 -> V_79 ,
( int ) V_18 -> V_80 ) ;
V_41 = - V_81 ;
goto V_78;
}
if ( V_18 -> V_80 != 0 ) {
F_22 (
L_25 ,
( int ) V_18 -> V_79 ,
( int ) V_18 -> V_80 ) ;
}
V_18 -> V_26 = ( ( T_3 * ) V_18 ) + sizeof( struct V_12 ) ;
V_73 = (struct V_94 * ) V_18 -> V_26 ;
if ( V_73 -> V_67 . V_72 . V_8 != 0x01 ) {
F_8 (
L_26 ,
( int ) V_73 -> V_67 . V_72 . V_8 ) ;
V_41 = - V_81 ;
goto V_78;
}
switch ( V_73 -> V_67 . V_72 . V_100 ) {
case 16 + 32 :
V_89 -> type = V_75 ;
break;
case 24 + 32 :
V_89 -> type = V_76 ;
break;
case 32 + 32 :
V_89 -> type = V_77 ;
break;
default:
F_8 ( L_27 ,
V_73 -> V_67 . V_72 . V_100 ) ;
V_41 = - V_81 ;
goto V_78;
}
V_89 -> V_55 = V_73 -> V_67 . V_72 . V_100 ;
memcpy ( V_89 -> V_89 , V_73 -> V_67 . V_72 . V_101 , V_89 -> V_55 ) ;
V_78:
F_11 ( V_27 , V_74 , 0 ) ;
return V_41 ;
}
int F_23 ( T_7 V_45 ,
const struct V_82 * V_83 ,
struct V_88 * V_89 )
{
long V_107 ;
int V_49 ;
T_3 V_108 [ 64 ] ;
switch ( V_45 ) {
case V_75 :
V_49 = 16 ;
V_107 = V_109 ;
break;
case V_76 :
V_49 = 24 ;
V_107 = V_110 ;
break;
case V_77 :
V_49 = 32 ;
V_107 = V_111 ;
break;
default:
F_8 ( L_28 ,
V_45 ) ;
return - V_7 ;
}
memset ( V_108 , 0 , sizeof( V_108 ) ) ;
memcpy ( V_108 , V_83 -> V_83 , V_49 ) ;
F_24 ( V_107 , V_108 ) ;
V_89 -> type = V_45 ;
V_89 -> V_55 = V_49 + 32 ;
memcpy ( V_89 -> V_89 , V_108 , V_49 + 32 ) ;
return 0 ;
}
static int F_25 ( T_5 V_31 , T_5 V_44 ,
const char * V_112 ,
T_3 * V_113 , T_4 * V_114 ,
T_3 * V_115 , T_4 * V_116 )
{
int V_41 ;
T_5 V_55 ;
T_3 * V_27 , * V_117 ;
struct V_12 * V_17 , * V_18 ;
struct V_29 V_40 ;
struct V_118 {
T_3 V_52 [ 2 ] ;
T_5 V_53 ;
char V_85 [ 8 ] ;
struct V_54 {
T_5 V_55 ;
T_3 V_63 [ V_119 ] ;
} V_54 ;
T_5 V_120 ;
} * V_65 ;
T_4 V_121 = sizeof( struct V_118 ) ;
struct V_122 {
T_3 V_52 [ 2 ] ;
T_3 V_123 [ 0 ] ;
} * V_73 ;
V_41 = F_9 ( V_121 , & V_27 , & V_17 , & V_18 ) ;
if ( V_41 )
return V_41 ;
V_17 -> V_44 = V_44 ;
V_65 = (struct V_118 * ) V_17 -> V_25 ;
memcpy ( V_65 -> V_52 , L_29 , 2 ) ;
strncpy ( V_65 -> V_85 , V_112 , sizeof( V_65 -> V_85 ) ) ;
V_65 -> V_53 =
sizeof( V_65 -> V_53 ) + sizeof( V_65 -> V_85 ) ;
V_65 -> V_54 . V_55 = sizeof( V_65 -> V_54 ) ;
V_65 -> V_120 = sizeof( V_65 -> V_120 ) ;
V_17 -> V_36 = V_121 ;
F_14 ( & V_40 , V_31 , V_17 , V_18 ) ;
V_41 = F_15 ( & V_40 ) ;
if ( V_41 ) {
F_8 (
L_30 ,
( int ) V_31 , ( int ) V_44 , V_41 ) ;
goto V_78;
}
if ( V_18 -> V_79 != 0 ) {
F_8 (
L_31 ,
( int ) V_18 -> V_79 ,
( int ) V_18 -> V_80 ) ;
V_41 = - V_81 ;
goto V_78;
}
V_18 -> V_26 = ( ( T_3 * ) V_18 ) + sizeof( struct V_12 ) ;
V_73 = (struct V_122 * ) V_18 -> V_26 ;
V_117 = V_73 -> V_123 ;
V_55 = * ( ( T_5 * ) V_117 ) ;
if ( V_55 > sizeof( T_5 ) ) {
V_117 += sizeof( T_5 ) ;
V_55 -= sizeof( T_5 ) ;
if ( V_113 && V_114 && * V_114 > 0 ) {
* V_114 = ( V_55 > * V_114 ? * V_114 : V_55 ) ;
memcpy ( V_113 , V_117 , * V_114 ) ;
}
V_117 += V_55 ;
}
V_55 = * ( ( T_5 * ) V_117 ) ;
if ( V_55 > sizeof( T_5 ) ) {
V_117 += sizeof( T_5 ) ;
V_55 -= sizeof( T_5 ) ;
if ( V_115 && V_116 && * V_116 > 0 ) {
* V_116 = ( V_55 > * V_116 ? * V_116 : V_55 ) ;
memcpy ( V_115 , V_117 , * V_116 ) ;
}
V_117 += V_55 ;
}
V_78:
F_11 ( V_27 , V_121 , 0 ) ;
return V_41 ;
}
static int F_26 ( T_5 V_31 , T_5 V_44 , T_8 V_124 [ 2 ] )
{
int V_41 , V_125 = 0 ;
T_4 V_126 , V_127 ;
T_3 * V_113 , * V_115 , * V_128 ;
V_128 = ( T_3 * ) F_27 ( V_19 ) ;
if ( ! V_128 )
return - V_20 ;
V_113 = V_128 ;
V_115 = V_128 + V_129 / 2 ;
V_126 = V_127 = V_129 / 2 ;
V_41 = F_25 ( V_31 , V_44 , L_32 ,
V_113 , & V_126 , V_115 , & V_127 ) ;
if ( V_41 == 0 && V_126 > 8 * 8 && V_127 > 184 + 8 ) {
if ( V_113 [ 8 * 8 ] == '2' ) {
V_124 [ 0 ] = * ( ( T_8 * ) ( V_115 + 184 ) ) ;
V_124 [ 1 ] = * ( ( T_8 * ) ( V_115 + 172 ) ) ;
V_125 = 1 ;
}
}
F_28 ( ( unsigned long ) V_128 ) ;
return V_125 ? 0 : - V_130 ;
}
static int F_29 ( T_5 V_31 , T_5 V_44 , T_8 V_124 [ 2 ] )
{
int V_41 = - V_130 ;
struct V_131 * V_117 ;
F_30 ( & V_132 ) ;
F_31 (ptr, &mkvp_list, list) {
if ( V_117 -> V_31 == V_31 &&
V_117 -> V_44 == V_44 ) {
memcpy ( V_124 , V_117 -> V_124 , 2 * sizeof( T_8 ) ) ;
V_41 = 0 ;
break;
}
}
F_32 ( & V_132 ) ;
return V_41 ;
}
static void F_33 ( T_5 V_31 , T_5 V_44 , T_8 V_124 [ 2 ] )
{
int V_125 = 0 ;
struct V_131 * V_117 ;
F_30 ( & V_132 ) ;
F_31 (ptr, &mkvp_list, list) {
if ( V_117 -> V_31 == V_31 &&
V_117 -> V_44 == V_44 ) {
memcpy ( V_117 -> V_124 , V_124 , 2 * sizeof( T_8 ) ) ;
V_125 = 1 ;
break;
}
}
if ( ! V_125 ) {
V_117 = F_10 ( sizeof( * V_117 ) , V_133 ) ;
if ( ! V_117 ) {
F_32 ( & V_132 ) ;
return;
}
V_117 -> V_31 = V_31 ;
V_117 -> V_44 = V_44 ;
memcpy ( V_117 -> V_124 , V_124 , 2 * sizeof( T_8 ) ) ;
F_34 ( & V_117 -> V_134 , & V_135 ) ;
}
F_32 ( & V_132 ) ;
}
static void F_35 ( T_5 V_31 , T_5 V_44 )
{
struct V_131 * V_117 ;
F_30 ( & V_132 ) ;
F_31 (ptr, &mkvp_list, list) {
if ( V_117 -> V_31 == V_31 &&
V_117 -> V_44 == V_44 ) {
F_36 ( & V_117 -> V_134 ) ;
F_13 ( V_117 ) ;
break;
}
}
F_32 ( & V_132 ) ;
}
static void T_2 F_37 ( void )
{
struct V_131 * V_117 , * V_136 ;
F_30 ( & V_132 ) ;
F_38 (ptr, pnext, &mkvp_list, list) {
F_36 ( & V_117 -> V_134 ) ;
F_13 ( V_117 ) ;
}
F_32 ( & V_132 ) ;
}
int F_39 ( const struct V_46 * V_47 ,
T_5 * V_137 , T_5 * V_138 , int V_139 )
{
struct V_5 * V_6 = (struct V_5 * ) V_47 ;
struct V_140 * V_141 ;
T_5 V_142 , V_143 ;
T_8 V_124 [ 2 ] ;
int V_48 , V_41 , V_144 = - 1 ;
if ( V_6 -> V_124 == 0 )
return - V_7 ;
V_141 = F_10 ( sizeof( struct V_140 ) ,
V_19 ) ;
if ( ! V_141 )
return - V_20 ;
F_40 ( V_141 ) ;
for ( V_48 = 0 ; V_48 < V_145 ; V_48 ++ ) {
V_142 = F_41 ( V_141 -> V_146 [ V_48 ] . V_147 ) ;
V_143 = F_42 ( V_141 -> V_146 [ V_48 ] . V_147 ) ;
if ( V_141 -> V_146 [ V_48 ] . V_148 &&
V_141 -> V_146 [ V_48 ] . V_149 & 0x04 ) {
if ( F_29 ( V_142 , V_143 , V_124 ) == 0 &&
V_6 -> V_124 == V_124 [ 0 ] ) {
if ( ! V_139 )
break;
if ( F_26 ( V_142 , V_143 , V_124 ) == 0 ) {
F_33 ( V_142 , V_143 , V_124 ) ;
if ( V_6 -> V_124 == V_124 [ 0 ] )
break;
}
}
} else {
F_35 ( V_142 , V_143 ) ;
}
}
if ( V_48 >= V_145 ) {
for ( V_48 = 0 ; V_48 < V_145 ; V_48 ++ ) {
if ( ! ( V_141 -> V_146 [ V_48 ] . V_148 &&
V_141 -> V_146 [ V_48 ] . V_149 & 0x04 ) )
continue;
V_142 = F_41 ( V_141 -> V_146 [ V_48 ] . V_147 ) ;
V_143 = F_42 ( V_141 -> V_146 [ V_48 ] . V_147 ) ;
if ( F_26 ( V_142 , V_143 , V_124 ) == 0 ) {
F_33 ( V_142 , V_143 , V_124 ) ;
if ( V_6 -> V_124 == V_124 [ 0 ] )
break;
if ( V_6 -> V_124 == V_124 [ 1 ] && V_144 < 0 )
V_144 = V_48 ;
}
}
if ( V_48 >= V_145 && V_144 >= 0 ) {
V_142 = F_41 ( V_141 -> V_146 [ V_144 ] . V_147 ) ;
V_143 = F_42 ( V_141 -> V_146 [ V_144 ] . V_147 ) ;
}
}
if ( V_48 < V_145 || V_144 >= 0 ) {
if ( V_137 )
* V_137 = V_142 ;
if ( V_138 )
* V_138 = V_143 ;
V_41 = 0 ;
} else
V_41 = - V_150 ;
F_13 ( V_141 ) ;
return V_41 ;
}
int F_43 ( const struct V_46 * V_47 ,
struct V_88 * V_89 )
{
T_5 V_31 , V_44 ;
int V_41 , V_139 ;
for ( V_139 = 0 ; V_139 < 2 ; V_139 ++ ) {
V_41 = F_39 ( V_47 , & V_31 , & V_44 , V_139 ) ;
if ( V_41 )
continue;
V_41 = F_21 ( V_31 , V_44 , V_47 , V_89 ) ;
if ( V_41 == 0 )
break;
}
if ( V_41 )
F_44 ( L_33 , V_41 ) ;
return V_41 ;
}
int F_45 ( const struct V_46 * V_47 ,
T_5 * V_137 , T_5 * V_138 ,
T_5 * V_151 , T_7 * V_152 )
{
struct V_5 * V_6 = (struct V_5 * ) V_47 ;
T_5 V_31 , V_44 ;
T_8 V_124 [ 2 ] ;
int V_41 ;
V_41 = F_7 ( ( T_3 * ) V_47 , 0 ) ;
if ( V_41 )
goto V_78;
if ( V_152 )
* V_152 = V_153 ;
if ( V_151 )
* V_151 = V_6 -> V_9 ;
V_41 = F_39 ( V_47 , & V_31 , & V_44 , 1 ) ;
if ( V_41 )
goto V_78;
V_41 = F_29 ( V_31 , V_44 , V_124 ) ;
if ( V_41 )
goto V_78;
if ( V_6 -> V_124 == V_124 [ 1 ] ) {
F_44 ( L_34 ) ;
if ( V_152 )
* V_152 |= V_154 ;
}
if ( V_137 )
* V_137 = V_31 ;
if ( V_138 )
* V_138 = V_44 ;
V_78:
F_44 ( L_35 , V_41 ) ;
return V_41 ;
}
static long F_46 ( struct V_155 * V_156 , unsigned int V_157 ,
unsigned long V_158 )
{
int V_41 ;
switch ( V_157 ) {
case V_159 : {
struct V_160 T_9 * V_161 = ( void T_9 * ) V_158 ;
struct V_160 V_162 ;
if ( F_47 ( & V_162 , V_161 , sizeof( V_162 ) ) )
return - V_163 ;
V_41 = F_19 ( V_162 . V_31 , V_162 . V_44 ,
V_162 . V_45 , & V_162 . V_47 ) ;
F_44 ( L_36 , V_41 ) ;
if ( V_41 )
break;
if ( F_48 ( V_161 , & V_162 , sizeof( V_162 ) ) )
return - V_163 ;
break;
}
case V_164 : {
struct V_165 T_9 * V_166 = ( void T_9 * ) V_158 ;
struct V_165 V_167 ;
if ( F_47 ( & V_167 , V_166 , sizeof( V_167 ) ) )
return - V_163 ;
V_41 = F_20 ( V_167 . V_31 , V_167 . V_44 , V_167 . V_45 ,
& V_167 . V_83 , & V_167 . V_47 ) ;
F_44 ( L_37 , V_41 ) ;
if ( V_41 )
break;
if ( F_48 ( V_166 , & V_167 , sizeof( V_167 ) ) )
return - V_163 ;
F_12 ( & V_167 , sizeof( V_167 ) ) ;
break;
}
case V_168 : {
struct V_169 T_9 * V_170 = ( void T_9 * ) V_158 ;
struct V_169 V_171 ;
if ( F_47 ( & V_171 , V_170 , sizeof( V_171 ) ) )
return - V_163 ;
V_41 = F_21 ( V_171 . V_31 , V_171 . V_44 ,
& V_171 . V_47 , & V_171 . V_89 ) ;
F_44 ( L_38 , V_41 ) ;
if ( V_41 )
break;
if ( F_48 ( V_170 , & V_171 , sizeof( V_171 ) ) )
return - V_163 ;
break;
}
case V_172 : {
struct V_173 T_9 * V_174 = ( void T_9 * ) V_158 ;
struct V_173 V_175 ;
if ( F_47 ( & V_175 , V_174 , sizeof( V_175 ) ) )
return - V_163 ;
V_41 = F_23 ( V_175 . V_45 ,
& V_175 . V_83 , & V_175 . V_89 ) ;
F_44 ( L_39 , V_41 ) ;
if ( V_41 )
break;
if ( F_48 ( V_174 , & V_175 , sizeof( V_175 ) ) )
return - V_163 ;
F_12 ( & V_175 , sizeof( V_175 ) ) ;
break;
}
case V_176 : {
struct F_39 T_9 * V_177 = ( void T_9 * ) V_158 ;
struct F_39 V_178 ;
if ( F_47 ( & V_178 , V_177 , sizeof( V_178 ) ) )
return - V_163 ;
V_41 = F_39 ( & V_178 . V_47 ,
& V_178 . V_31 , & V_178 . V_44 , 1 ) ;
F_44 ( L_40 , V_41 ) ;
if ( V_41 )
break;
if ( F_48 ( V_177 , & V_178 , sizeof( V_178 ) ) )
return - V_163 ;
break;
}
case V_179 : {
struct F_43 T_9 * V_170 = ( void T_9 * ) V_158 ;
struct F_43 V_171 ;
if ( F_47 ( & V_171 , V_170 , sizeof( V_171 ) ) )
return - V_163 ;
V_41 = F_43 ( & V_171 . V_47 , & V_171 . V_89 ) ;
F_44 ( L_41 , V_41 ) ;
if ( V_41 )
break;
if ( F_48 ( V_170 , & V_171 , sizeof( V_171 ) ) )
return - V_163 ;
break;
}
case V_180 : {
struct F_45 T_9 * V_181 = ( void T_9 * ) V_158 ;
struct F_45 V_182 ;
if ( F_47 ( & V_182 , V_181 , sizeof( V_182 ) ) )
return - V_163 ;
V_41 = F_45 ( & V_182 . V_47 , & V_182 . V_31 , & V_182 . V_44 ,
& V_182 . V_49 , & V_182 . V_183 ) ;
F_44 ( L_42 , V_41 ) ;
if ( V_41 )
break;
if ( F_48 ( V_181 , & V_182 , sizeof( V_182 ) ) )
return - V_163 ;
break;
}
default:
return - V_184 ;
}
return V_41 ;
}
int T_1 F_49 ( void )
{
T_10 V_185 ;
if ( ! F_50 ( V_186 , & V_185 ) )
return - V_187 ;
if ( ! F_51 ( & V_185 , V_109 ) ||
! F_51 ( & V_185 , V_110 ) ||
! F_51 ( & V_185 , V_111 ) )
return - V_187 ;
F_1 () ;
return F_52 ( & V_188 ) ;
}
static void T_2 F_53 ( void )
{
F_54 ( & V_188 ) ;
F_37 () ;
F_5 () ;
}
