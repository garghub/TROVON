static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
return 0 ;
}
static int F_3 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_1 * * V_7 )
{
struct V_1 * V_2 ;
* V_7 = NULL ;
V_2 = F_4 ( sizeof( struct V_1 ) , V_8 ) ;
if ( V_2 == NULL )
return - V_9 ;
F_5 ( & V_2 -> V_10 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_11 = - 1 ;
V_2 -> V_12 = - 1 ;
* V_7 = V_2 ;
return 0 ;
}
static void F_6 ( struct V_13 * V_14 )
{
T_1 V_15 ;
V_15 = F_7 ( V_14 ) ;
V_15 |= V_16 ;
F_8 ( V_14 , V_15 ) ;
}
static void F_9 ( struct V_13 * V_14 )
{
T_1 V_15 ;
V_15 = F_7 ( V_14 ) ;
V_15 &= ~ V_16 ;
F_8 ( V_14 , V_15 ) ;
}
static int F_10 ( struct V_13 * V_14 )
{
int V_17 ;
T_1 V_15 ;
for ( V_17 = 0 ; V_17 < 0xffff ; ++ V_17 ) {
V_15 = F_11 ( V_14 ) ;
V_15 &= V_18 ;
if ( V_15 != 0 )
return 1 ;
}
return 0 ;
}
static int F_12 ( struct V_13 * V_14 )
{
int V_17 ;
F_13 ( V_14 , V_19 ) ;
for ( V_17 = 0 ; V_17 < 64 ; ++ V_17 ) {
F_14 ( 100 ) ;
if ( F_15 ( V_14 ) == 0 ) {
F_9 ( V_14 ) ;
return 0 ;
}
}
F_9 ( V_14 ) ;
return - V_20 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_17 ;
struct V_13 * V_14 = V_2 -> V_6 -> V_21 ;
for ( V_17 = 0 ; V_17 < 5 ; ++ V_17 )
F_13 ( V_14 , V_22 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_17 ;
struct V_13 * V_14 = V_2 -> V_6 -> V_21 ;
for ( V_17 = 0 ; V_17 < 5 ; ++ V_17 ) {
F_13 ( V_14 , V_23 ) ;
F_13 ( V_14 , V_24 ) ;
}
return 0 ;
}
static T_1 F_18 ( T_1 V_15 )
{
static T_1 V_25 [] = { 0 , 1 , 4 , 2 , 3 } ;
return V_25 [ V_15 ] ;
}
static int F_15 ( struct V_13 * V_14 )
{
T_1 V_15 ;
F_19 ( V_14 ) ;
F_13 ( V_14 , V_26 ) ;
F_14 ( 50 ) ;
V_15 = F_20 ( V_14 ) ;
V_15 &= 0x00ff ;
if ( V_15 != V_26 )
return - V_27 ;
else
return 0 ;
}
static T_2 F_20 ( struct V_13 * V_14 )
{
T_1 V_28 , V_29 ;
F_10 ( V_14 ) ;
F_6 ( V_14 ) ;
V_29 = F_11 ( V_14 ) ;
V_28 = F_21 ( V_14 ) ;
F_9 ( V_14 ) ;
return ( V_29 << 8 ) | V_28 ;
}
static T_1 F_21 ( struct V_13 * V_14 )
{
T_1 V_15 = 0 ;
T_1 V_29 ;
T_1 V_17 ;
for ( V_17 = 0 ; V_17 < 8 ; ++ V_17 ) {
F_22 ( V_14 , V_17 ) ;
V_15 >>= 1 ;
V_29 = F_11 ( V_14 ) ;
if ( V_29 & V_30 )
V_15 |= 0x80 ;
}
return V_15 ;
}
static void F_23 ( struct V_13 * V_14 ,
T_1 V_31 , T_1 V_32 ,
T_1 V_33 , T_1 V_34 ,
T_1 V_35 )
{
static T_1 V_36 [ 5 ] = { V_37 ,
V_38 ,
V_39 ,
V_40 ,
V_41 } ;
F_13 ( V_14 , V_42 ) ;
F_13 ( V_14 , V_34 ) ;
F_13 ( V_14 , V_33 ) ;
F_13 ( V_14 , V_32 ) ;
F_13 ( V_14 , V_31 ) ;
F_13 ( V_14 , V_43 ) ;
F_13 ( V_14 , V_36 [ V_35 ] ) ;
}
static void F_19 ( struct V_13 * V_14 )
{
F_13 ( V_14 , V_44 ) ;
}
static void F_13 ( struct V_13 * V_14 , T_1 V_15 )
{
F_10 ( V_14 ) ;
F_22 ( V_14 , V_15 ) ;
F_8 ( V_14 , V_45 ) ;
F_8 ( V_14 , V_45 | V_46 ) ;
F_8 ( V_14 , V_45 ) ;
}
static void F_24 ( struct V_13 * V_14 , T_1 V_15 )
{
F_10 ( V_14 ) ;
F_22 ( V_14 , V_15 ) ;
F_8 ( V_14 , V_47 ) ;
F_8 ( V_14 , V_47 | V_46 ) ;
F_8 ( V_14 , V_47 ) ;
}
static void F_25 ( struct V_1 * V_2 , T_1 V_15 ,
int V_48 )
{
struct V_13 * V_14 = V_2 -> V_6 -> V_21 ;
if ( V_2 -> V_11 != V_48 )
F_13 ( V_14 , V_48 ) ;
F_24 ( V_14 , V_15 ) ;
}
static int F_26 ( struct V_49 * V_50 ,
struct V_51 * V_52 )
{
struct V_1 * V_2 = F_27 ( V_50 ) ;
F_28 ( & V_2 -> V_10 ) ;
V_52 -> V_53 . integer . V_53 [ 0 ] = V_2 -> V_54 ;
F_29 ( & V_2 -> V_10 ) ;
return 0 ;
}
static int F_30 ( struct V_49 * V_50 ,
struct V_51 * V_52 )
{
struct V_1 * V_2 = F_27 ( V_50 ) ;
int V_55 = 0 ;
int V_56 = ! ! V_52 -> V_53 . integer . V_53 [ 0 ] ;
F_28 ( & V_2 -> V_10 ) ;
if ( V_2 -> V_54 == V_56 )
goto V_57;
V_55 = 1 ;
V_2 -> V_54 = V_56 ;
if ( V_2 -> V_54 ) {
F_23 ( V_2 -> V_6 -> V_21 ,
V_2 -> time [ 0 ] , V_2 -> time [ 1 ] ,
V_2 -> time [ 2 ] , V_2 -> time [ 3 ] ,
V_2 -> V_36 ) ;
} else {
F_19 ( V_2 -> V_6 -> V_21 ) ;
}
V_57:
F_29 ( & V_2 -> V_10 ) ;
return V_55 ;
}
static int F_31 ( struct V_49 * V_50 ,
struct V_58 * V_59 )
{
V_59 -> type = V_60 ;
V_59 -> V_61 = 1 ;
V_59 -> V_53 . integer . V_62 = 0 ;
V_59 -> V_53 . integer . V_63 = 23 ;
return 0 ;
}
static int F_32 ( struct V_49 * V_50 ,
struct V_58 * V_59 )
{
V_59 -> type = V_60 ;
V_59 -> V_61 = 1 ;
V_59 -> V_53 . integer . V_62 = 0 ;
V_59 -> V_53 . integer . V_63 = 99 ;
return 0 ;
}
static int F_33 ( struct V_49 * V_50 ,
struct V_58 * V_59 )
{
V_59 -> type = V_60 ;
V_59 -> V_61 = 1 ;
V_59 -> V_53 . integer . V_62 = 0 ;
V_59 -> V_53 . integer . V_63 = 59 ;
return 0 ;
}
static int F_34 ( struct V_49 * V_50 ,
struct V_51 * V_52 )
{
struct V_1 * V_2 = F_27 ( V_50 ) ;
int V_35 = V_50 -> V_64 ;
F_28 ( & V_2 -> V_10 ) ;
V_52 -> V_53 . integer . V_53 [ 0 ] = V_2 -> time [ V_35 ] ;
F_29 ( & V_2 -> V_10 ) ;
return 0 ;
}
static int F_35 ( struct V_49 * V_50 ,
struct V_51 * V_52 )
{
struct V_1 * V_2 = F_27 ( V_50 ) ;
int V_35 = V_50 -> V_64 ;
unsigned int time = V_52 -> V_53 . integer . V_53 [ 0 ] % 60 ;
int V_55 = 0 ;
F_28 ( & V_2 -> V_10 ) ;
if ( V_2 -> time [ V_35 ] != time ) {
V_55 = 1 ;
V_2 -> time [ V_35 ] = time ;
}
F_29 ( & V_2 -> V_10 ) ;
return V_55 ;
}
static int F_36 ( struct V_49 * V_50 ,
struct V_58 * V_59 )
{
static char * V_65 [ 5 ] = { L_1 ,
L_2 ,
L_3 ,
L_4 ,
L_5 } ;
V_59 -> type = V_66 ;
V_59 -> V_61 = 1 ;
V_59 -> V_53 . V_67 . V_68 = 5 ;
if ( V_59 -> V_53 . V_67 . V_69 > 4 )
V_59 -> V_53 . V_67 . V_69 = 4 ;
strcpy ( V_59 -> V_53 . V_67 . V_70 ,
V_65 [ V_59 -> V_53 . V_67 . V_69 ] ) ;
return 0 ;
}
static int F_37 ( struct V_49 * V_50 ,
struct V_51 * V_52 )
{
struct V_1 * V_2 = F_27 ( V_50 ) ;
F_28 ( & V_2 -> V_10 ) ;
V_52 -> V_53 . V_67 . V_69 [ 0 ] = V_2 -> V_36 ;
F_29 ( & V_2 -> V_10 ) ;
return 0 ;
}
static int F_38 ( struct V_49 * V_50 ,
struct V_51 * V_52 )
{
struct V_1 * V_2 = F_27 ( V_50 ) ;
int V_55 = 0 ;
if ( V_52 -> V_53 . V_67 . V_69 [ 0 ] >= 5 )
return - V_71 ;
F_28 ( & V_2 -> V_10 ) ;
if ( V_2 -> V_36 != V_52 -> V_53 . V_67 . V_69 [ 0 ] ) {
V_55 = 1 ;
V_2 -> V_36 = V_52 -> V_53 . V_67 . V_69 [ 0 ] ;
}
F_29 ( & V_2 -> V_10 ) ;
return V_55 ;
}
static int F_39 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
int V_72 , V_17 ;
static struct V_73 * V_74 [] = {
& V_75 ,
& V_76 ,
& V_77 ,
& V_78 ,
& V_79 ,
& V_80 ,
NULL } ;
for ( V_17 = 0 ; V_74 [ V_17 ] ; ++ V_17 ) {
V_72 = F_40 ( V_4 , F_41 ( V_74 [ V_17 ] , V_2 ) ) ;
if ( V_72 < 0 ) {
F_42 ( L_6 ,
V_74 [ V_17 ] -> V_70 ) ;
return V_72 ;
}
}
return 0 ;
}
static int F_43 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_83 -> V_84 ;
if ( V_2 -> V_85 == 0 ) {
F_16 ( V_2 ) ;
F_14 ( 50 ) ;
}
++ ( V_2 -> V_85 ) ;
return 0 ;
}
static int F_44 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_83 -> V_84 ;
unsigned long V_86 ;
-- ( V_2 -> V_85 ) ;
if ( V_2 -> V_85 == 0 ) {
F_45 ( & V_2 -> V_10 , V_86 ) ;
F_17 ( V_2 ) ;
F_46 ( & V_2 -> V_10 , V_86 ) ;
F_14 ( 500 ) ;
} else if ( V_2 -> V_85 < 0 )
V_2 -> V_85 = 0 ;
return 0 ;
}
static void F_47 ( struct V_81 * V_82 ,
int V_87 )
{
struct V_1 * V_2 = V_82 -> V_83 -> V_84 ;
T_1 V_28 ;
unsigned long V_86 ;
F_45 ( & V_2 -> V_10 , V_86 ) ;
while ( F_48 ( V_82 , & V_28 , 1 ) == 1 ) {
F_25 ( V_2 , V_28 , V_82 -> V_88 + 1 ) ;
F_49 ( V_82 , 1 ) ;
}
F_46 ( & V_2 -> V_10 , V_86 ) ;
}
static void F_50 ( struct V_81 * V_82 ,
int V_87 )
{
struct V_1 * V_2 = V_82 -> V_83 -> V_84 ;
unsigned long V_86 ;
F_45 ( & V_2 -> V_10 , V_86 ) ;
if ( V_87 )
V_2 -> V_89 [ V_82 -> V_88 ] |= V_90 ;
else
V_2 -> V_89 [ V_82 -> V_88 ] &= ~ V_90 ;
F_46 ( & V_2 -> V_10 , V_86 ) ;
}
static int F_51 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_84 ;
struct V_91 * V_83 ;
struct V_81 * V_82 ;
struct V_92 * V_93 ;
int V_72 ;
V_72 = F_52 ( V_4 , V_94 , 0 ,
V_95 ,
V_96 ,
& V_83 ) ;
if ( V_72 < 0 )
return V_72 ;
V_83 -> V_84 = V_2 ;
strcpy ( V_83 -> V_70 , V_94 ) ;
V_83 -> V_97 = V_98 |
V_99 |
V_100 ;
V_2 -> V_83 = V_83 ;
F_53 ( V_83 , V_101 ,
& V_102 ) ;
F_53 ( V_83 , V_103 ,
& V_104 ) ;
F_54 (list,
&rmidi->streams[SNDRV_RAWMIDI_STREAM_OUTPUT].substreams) {
V_82 = F_55 ( V_93 , struct V_81 , V_93 ) ;
sprintf ( V_82 -> V_70 ,
L_7 , V_82 -> V_88 + 1 ) ;
}
F_54 (list,
&rmidi->streams[SNDRV_RAWMIDI_STREAM_INPUT].substreams) {
V_82 = F_55 ( V_93 , struct V_81 , V_93 ) ;
V_2 -> V_105 [ V_82 -> V_88 ] = V_82 ;
switch( V_82 -> V_88 ) {
case V_106 :
strcpy ( V_82 -> V_70 , L_8 ) ;
break;
default:
sprintf ( V_82 -> V_70 ,
L_7 , V_82 -> V_88 + 1 ) ;
}
}
V_72 = F_39 ( V_4 , V_2 ) ;
return V_72 ;
}
static void F_56 ( void * V_107 )
{
struct V_1 * V_2 = ( (struct V_3 * ) V_107 ) -> V_84 ;
T_2 V_108 ;
T_1 V_29 , V_28 ;
struct V_81 * V_82 ;
F_57 ( & V_2 -> V_10 ) ;
V_108 = F_20 ( V_2 -> V_6 -> V_21 ) ;
V_28 = V_108 & 0x00ff ;
V_29 = V_108 >> 8 ;
if ( V_29 & V_109 ) {
V_2 -> V_12 = F_18 ( V_28 ) ;
} else {
if ( V_2 -> V_12 == - 1 )
goto V_57;
V_82 = V_2 -> V_105 [ V_2 -> V_12 ] ;
if ( V_2 -> V_89 [ V_82 -> V_88 ] & V_90 )
F_58 ( V_82 , & V_28 , 1 ) ;
}
V_57:
F_59 ( & V_2 -> V_10 ) ;
}
static int F_60 ( struct V_13 * V_14 )
{
struct V_5 * V_6 ;
int V_110 ;
V_6 = F_61 ( V_14 , V_111 ,
NULL , NULL , NULL ,
0 , NULL ) ;
if ( ! V_6 )
return - V_20 ;
if ( F_62 ( V_6 ) ) {
F_63 ( V_6 ) ;
return - V_20 ;
}
V_110 = F_15 ( V_14 ) ;
F_64 ( V_6 ) ;
F_63 ( V_6 ) ;
return V_110 ;
}
static void F_65 ( struct V_13 * V_14 )
{
struct V_112 * V_113 ;
V_113 = F_66 ( V_114 , V_115 ) ;
if ( ! V_113 )
return;
F_67 ( V_113 , V_14 ) ;
if ( F_68 ( V_113 ) < 0 ) {
F_69 ( V_113 ) ;
return;
}
if ( ! F_70 ( V_113 ) ) {
F_71 ( V_113 ) ;
return;
}
V_116 [ V_115 ] = V_113 ;
V_115 ++ ;
}
static void F_72 ( struct V_13 * V_14 )
{
}
static void F_73 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_84 ;
struct V_5 * V_6 = V_2 -> V_6 ;
if ( V_6 ) {
if ( V_2 -> V_117 )
F_64 ( V_6 ) ;
F_63 ( V_6 ) ;
}
F_1 ( V_2 ) ;
}
static int F_74 ( struct V_112 * V_118 )
{
struct V_5 * V_6 ;
struct V_13 * V_14 ;
int V_119 = V_118 -> V_120 ;
struct V_3 * V_4 = NULL ;
struct V_1 * V_2 = NULL ;
int V_72 ;
V_14 = F_70 ( V_118 ) ;
F_67 ( V_118 , NULL ) ;
if ( V_119 >= V_121 )
return - V_27 ;
if ( ! V_122 [ V_119 ] )
return - V_123 ;
if ( ( V_72 = F_60 ( V_14 ) ) < 0 )
return V_72 ;
V_72 = F_75 ( & V_118 -> V_119 , V_124 [ V_119 ] , V_120 [ V_119 ] , V_125 ,
0 , & V_4 ) ;
if ( V_72 < 0 ) {
F_42 ( L_9 ) ;
return V_72 ;
}
strcpy ( V_4 -> V_126 , V_111 ) ;
strcpy ( V_4 -> V_127 , L_10 V_94 ) ;
sprintf ( V_4 -> V_128 , L_11 ,
V_4 -> V_127 , V_14 -> V_129 , V_14 -> V_130 ) ;
V_6 = F_61 ( V_14 ,
V_111 ,
NULL ,
NULL ,
F_56 ,
V_131 ,
( void * ) V_4 ) ;
if ( V_6 == NULL ) {
F_42 ( L_12 ) ;
V_72 = - V_20 ;
goto V_132;
}
if ( ( V_72 = F_3 ( V_4 , V_6 , & V_2 ) ) < 0 ) {
F_42 ( L_13 ) ;
F_63 ( V_6 ) ;
goto V_132;
}
V_4 -> V_84 = V_2 ;
V_4 -> V_133 = F_73 ;
if ( ( V_72 = F_51 ( V_4 ) ) < 0 ) {
F_42 ( L_14 ) ;
goto V_132;
}
if ( F_62 ( V_6 ) ) {
F_42 ( L_15 , V_6 -> V_21 -> V_129 ) ;
V_72 = - V_20 ;
goto V_132;
}
V_2 -> V_117 = 1 ;
if ( ( V_72 = F_12 ( V_14 ) ) < 0 )
goto V_132;
F_67 ( V_118 , V_4 ) ;
if ( ( V_72 = F_76 ( V_4 ) ) < 0 ) {
F_42 ( L_16 ) ;
goto V_132;
}
F_77 ( V_134 L_17 , V_14 -> V_129 ) ;
return 0 ;
V_132:
F_78 ( V_4 ) ;
return V_72 ;
}
static int F_79 ( struct V_112 * V_118 )
{
struct V_3 * V_4 = F_70 ( V_118 ) ;
if ( V_4 )
F_78 ( V_4 ) ;
return 0 ;
}
static void F_80 ( void )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_121 ; ++ V_17 ) {
if ( V_116 [ V_17 ] ) {
F_71 ( V_116 [ V_17 ] ) ;
V_116 [ V_17 ] = NULL ;
}
}
F_81 ( & V_135 ) ;
F_82 ( & V_136 ) ;
}
static int T_3 F_83 ( void )
{
int V_72 ;
if ( ( V_72 = F_84 ( & V_135 ) ) < 0 )
return V_72 ;
if ( F_85 ( & V_136 ) != 0 ) {
F_81 ( & V_135 ) ;
return - V_20 ;
}
if ( V_115 == 0 ) {
F_80 () ;
return - V_27 ;
}
return 0 ;
}
static void T_4 F_86 ( void )
{
F_80 () ;
}
