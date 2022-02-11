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
static const char * const V_65 [ 5 ] = {
L_1 , L_2 , L_3 , L_4 , L_5
} ;
return F_37 ( V_59 , 1 , 5 , V_65 ) ;
}
static int F_38 ( struct V_49 * V_50 ,
struct V_51 * V_52 )
{
struct V_1 * V_2 = F_27 ( V_50 ) ;
F_28 ( & V_2 -> V_10 ) ;
V_52 -> V_53 . V_66 . V_67 [ 0 ] = V_2 -> V_36 ;
F_29 ( & V_2 -> V_10 ) ;
return 0 ;
}
static int F_39 ( struct V_49 * V_50 ,
struct V_51 * V_52 )
{
struct V_1 * V_2 = F_27 ( V_50 ) ;
int V_55 = 0 ;
if ( V_52 -> V_53 . V_66 . V_67 [ 0 ] >= 5 )
return - V_68 ;
F_28 ( & V_2 -> V_10 ) ;
if ( V_2 -> V_36 != V_52 -> V_53 . V_66 . V_67 [ 0 ] ) {
V_55 = 1 ;
V_2 -> V_36 = V_52 -> V_53 . V_66 . V_67 [ 0 ] ;
}
F_29 ( & V_2 -> V_10 ) ;
return V_55 ;
}
static int F_40 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
int V_69 , V_17 ;
static struct V_70 * V_71 [] = {
& V_72 ,
& V_73 ,
& V_74 ,
& V_75 ,
& V_76 ,
& V_77 ,
NULL } ;
for ( V_17 = 0 ; V_71 [ V_17 ] ; ++ V_17 ) {
V_69 = F_41 ( V_4 , F_42 ( V_71 [ V_17 ] , V_2 ) ) ;
if ( V_69 < 0 ) {
F_43 ( L_6 ,
V_71 [ V_17 ] -> V_78 ) ;
return V_69 ;
}
}
return 0 ;
}
static int F_44 ( struct V_79 * V_80 )
{
struct V_1 * V_2 = V_80 -> V_81 -> V_82 ;
if ( V_2 -> V_83 == 0 ) {
F_16 ( V_2 ) ;
F_14 ( 50 ) ;
}
++ ( V_2 -> V_83 ) ;
return 0 ;
}
static int F_45 ( struct V_79 * V_80 )
{
struct V_1 * V_2 = V_80 -> V_81 -> V_82 ;
unsigned long V_84 ;
-- ( V_2 -> V_83 ) ;
if ( V_2 -> V_83 == 0 ) {
F_46 ( & V_2 -> V_10 , V_84 ) ;
F_17 ( V_2 ) ;
F_47 ( & V_2 -> V_10 , V_84 ) ;
F_14 ( 500 ) ;
} else if ( V_2 -> V_83 < 0 )
V_2 -> V_83 = 0 ;
return 0 ;
}
static void F_48 ( struct V_79 * V_80 ,
int V_85 )
{
struct V_1 * V_2 = V_80 -> V_81 -> V_82 ;
T_1 V_28 ;
unsigned long V_84 ;
F_46 ( & V_2 -> V_10 , V_84 ) ;
while ( F_49 ( V_80 , & V_28 , 1 ) == 1 ) {
F_25 ( V_2 , V_28 , V_80 -> V_86 + 1 ) ;
F_50 ( V_80 , 1 ) ;
}
F_47 ( & V_2 -> V_10 , V_84 ) ;
}
static void F_51 ( struct V_79 * V_80 ,
int V_85 )
{
struct V_1 * V_2 = V_80 -> V_81 -> V_82 ;
unsigned long V_84 ;
F_46 ( & V_2 -> V_10 , V_84 ) ;
if ( V_85 )
V_2 -> V_87 [ V_80 -> V_86 ] |= V_88 ;
else
V_2 -> V_87 [ V_80 -> V_86 ] &= ~ V_88 ;
F_47 ( & V_2 -> V_10 , V_84 ) ;
}
static int F_52 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_82 ;
struct V_89 * V_81 ;
struct V_79 * V_80 ;
struct V_90 * V_91 ;
int V_69 ;
V_69 = F_53 ( V_4 , V_92 , 0 ,
V_93 ,
V_94 ,
& V_81 ) ;
if ( V_69 < 0 )
return V_69 ;
V_81 -> V_82 = V_2 ;
strcpy ( V_81 -> V_78 , V_92 ) ;
V_81 -> V_95 = V_96 |
V_97 |
V_98 ;
V_2 -> V_81 = V_81 ;
F_54 ( V_81 , V_99 ,
& V_100 ) ;
F_54 ( V_81 , V_101 ,
& V_102 ) ;
F_55 (list,
&rmidi->streams[SNDRV_RAWMIDI_STREAM_OUTPUT].substreams) {
V_80 = F_56 ( V_91 , struct V_79 , V_91 ) ;
sprintf ( V_80 -> V_78 ,
L_7 , V_80 -> V_86 + 1 ) ;
}
F_55 (list,
&rmidi->streams[SNDRV_RAWMIDI_STREAM_INPUT].substreams) {
V_80 = F_56 ( V_91 , struct V_79 , V_91 ) ;
V_2 -> V_103 [ V_80 -> V_86 ] = V_80 ;
switch( V_80 -> V_86 ) {
case V_104 :
strcpy ( V_80 -> V_78 , L_8 ) ;
break;
default:
sprintf ( V_80 -> V_78 ,
L_7 , V_80 -> V_86 + 1 ) ;
}
}
V_69 = F_40 ( V_4 , V_2 ) ;
return V_69 ;
}
static void F_57 ( void * V_105 )
{
struct V_1 * V_2 = ( (struct V_3 * ) V_105 ) -> V_82 ;
T_2 V_106 ;
T_1 V_29 , V_28 ;
struct V_79 * V_80 ;
F_58 ( & V_2 -> V_10 ) ;
V_106 = F_20 ( V_2 -> V_6 -> V_21 ) ;
V_28 = V_106 & 0x00ff ;
V_29 = V_106 >> 8 ;
if ( V_29 & V_107 ) {
V_2 -> V_12 = F_18 ( V_28 ) ;
} else {
if ( V_2 -> V_12 == - 1 )
goto V_57;
V_80 = V_2 -> V_103 [ V_2 -> V_12 ] ;
if ( V_2 -> V_87 [ V_80 -> V_86 ] & V_88 )
F_59 ( V_80 , & V_28 , 1 ) ;
}
V_57:
F_60 ( & V_2 -> V_10 ) ;
}
static void F_61 ( struct V_13 * V_14 )
{
struct V_108 * V_109 ;
V_109 = F_62 ( V_110 , V_111 ) ;
if ( ! V_109 )
return;
F_63 ( V_109 , V_14 ) ;
if ( F_64 ( V_109 ) < 0 ) {
F_65 ( V_109 ) ;
return;
}
if ( ! F_66 ( V_109 ) ) {
F_67 ( V_109 ) ;
return;
}
V_112 [ V_111 ] = V_109 ;
V_111 ++ ;
}
static void F_68 ( struct V_13 * V_14 )
{
}
static int F_69 ( struct V_5 * V_6 )
{
if ( strcmp ( V_6 -> V_78 , V_113 ) )
return - V_27 ;
return 0 ;
}
static void F_70 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_82 ;
struct V_5 * V_6 = V_2 -> V_6 ;
if ( V_6 ) {
F_71 ( V_6 ) ;
F_72 ( V_6 ) ;
}
F_1 ( V_2 ) ;
}
static int F_73 ( struct V_108 * V_114 )
{
struct V_5 * V_6 ;
struct V_13 * V_14 ;
int V_115 = V_114 -> V_116 ;
struct V_3 * V_4 = NULL ;
struct V_1 * V_2 = NULL ;
int V_69 ;
struct V_117 V_118 = {
. V_119 = NULL ,
. V_120 = NULL ,
. V_121 = F_57 ,
. V_84 = V_122 ,
} ;
V_14 = F_66 ( V_114 ) ;
F_63 ( V_114 , NULL ) ;
if ( V_115 >= V_123 )
return - V_27 ;
if ( ! V_124 [ V_115 ] )
return - V_125 ;
V_69 = F_74 ( & V_114 -> V_115 , V_126 [ V_115 ] , V_116 [ V_115 ] , V_127 ,
0 , & V_4 ) ;
if ( V_69 < 0 ) {
F_43 ( L_9 ) ;
return V_69 ;
}
strcpy ( V_4 -> V_128 , V_113 ) ;
strcpy ( V_4 -> V_129 , L_10 V_92 ) ;
sprintf ( V_4 -> V_130 , L_11 ,
V_4 -> V_129 , V_14 -> V_131 , V_14 -> V_132 ) ;
V_118 . V_105 = V_4 ;
V_6 = F_75 ( V_14 ,
V_113 ,
& V_118 ,
V_114 -> V_116 ) ;
if ( ! V_6 ) {
F_43 ( L_12 ) ;
V_69 = - V_20 ;
goto V_133;
}
if ( F_76 ( V_6 ) ) {
F_43 ( L_13 , V_6 -> V_21 -> V_131 ) ;
V_69 = - V_20 ;
goto V_134;
}
if ( ( V_69 = F_3 ( V_4 , V_6 , & V_2 ) ) < 0 ) {
F_43 ( L_14 ) ;
goto V_135;
}
V_4 -> V_82 = V_2 ;
V_4 -> V_136 = F_70 ;
V_69 = F_15 ( V_14 ) ;
if ( V_69 ) {
V_69 = - V_20 ;
goto V_133;
}
if ( ( V_69 = F_52 ( V_4 ) ) < 0 ) {
F_43 ( L_15 ) ;
goto V_133;
}
if ( ( V_69 = F_12 ( V_14 ) ) < 0 )
goto V_133;
F_63 ( V_114 , V_4 ) ;
if ( ( V_69 = F_77 ( V_4 ) ) < 0 ) {
F_43 ( L_16 ) ;
goto V_133;
}
F_78 ( V_137 L_17 , V_14 -> V_131 ) ;
return 0 ;
V_135:
F_71 ( V_6 ) ;
V_134:
F_72 ( V_6 ) ;
V_133:
F_79 ( V_4 ) ;
return V_69 ;
}
static int F_80 ( struct V_108 * V_114 )
{
struct V_3 * V_4 = F_66 ( V_114 ) ;
if ( V_4 )
F_79 ( V_4 ) ;
return 0 ;
}
static void F_81 ( void )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_123 ; ++ V_17 ) {
if ( V_112 [ V_17 ] ) {
F_67 ( V_112 [ V_17 ] ) ;
V_112 [ V_17 ] = NULL ;
}
}
F_82 ( & V_138 ) ;
F_83 ( & V_139 ) ;
}
static int T_3 F_84 ( void )
{
int V_69 ;
if ( ( V_69 = F_85 ( & V_138 ) ) < 0 )
return V_69 ;
if ( F_86 ( & V_139 ) != 0 ) {
F_82 ( & V_138 ) ;
return - V_20 ;
}
if ( V_111 == 0 ) {
F_81 () ;
return - V_27 ;
}
return 0 ;
}
static void T_4 F_87 ( void )
{
F_81 () ;
}
