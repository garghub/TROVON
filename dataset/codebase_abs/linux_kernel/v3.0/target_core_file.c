static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_4 ;
V_4 = F_2 ( sizeof( struct V_4 ) , V_5 ) ;
if ( ! ( V_4 ) ) {
F_3 ( V_6 L_1 ) ;
return - 1 ;
}
V_4 -> V_7 = V_3 ;
F_4 ( & V_2 -> V_8 , V_9 ) ;
F_4 ( & V_2 -> V_10 , V_9 ) ;
V_2 -> V_11 = ( void * ) V_4 ;
F_3 ( V_12 L_2
L_3 , V_2 -> V_13 , V_14 ,
V_15 ) ;
F_3 ( V_12 L_4
L_5 ,
V_2 -> V_13 , V_4 -> V_7 ,
F_5 ( & V_2 -> V_10 ) , V_16 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_2 -> V_11 ;
F_3 ( V_12 L_6
L_7 , V_2 -> V_13 , V_4 -> V_7 ) ;
F_7 ( V_4 ) ;
V_2 -> V_11 = NULL ;
}
static void * F_8 ( struct V_1 * V_2 , const char * V_17 )
{
struct V_18 * V_18 ;
struct V_4 * V_4 = (struct V_4 * ) V_2 -> V_11 ;
V_18 = F_2 ( sizeof( struct V_18 ) , V_5 ) ;
if ( ! ( V_18 ) ) {
F_3 ( V_6 L_8 ) ;
return NULL ;
}
V_18 -> V_4 = V_4 ;
F_3 ( V_12 L_9 , V_17 ) ;
return V_18 ;
}
static struct V_19 * F_9 (
struct V_1 * V_2 ,
struct V_20 * V_21 ,
void * V_22 )
{
char * V_23 = NULL ;
struct V_19 * V_24 ;
struct V_25 V_26 ;
struct V_27 * V_28 ;
struct V_18 * V_18 = (struct V_18 * ) V_22 ;
struct V_4 * V_4 = (struct V_4 * ) V_2 -> V_11 ;
T_2 V_29 ;
struct V_30 * V_30 ;
struct V_31 * V_31 = NULL ;
int V_32 = 0 , V_33 , V_34 = - V_35 ;
memset ( & V_26 , 0 , sizeof( struct V_25 ) ) ;
V_29 = F_10 () ;
F_11 ( F_12 () ) ;
V_23 = F_13 ( V_18 -> V_36 ) ;
F_11 ( V_29 ) ;
if ( F_14 ( V_23 ) ) {
F_3 ( V_6 L_10 ,
V_18 -> V_36 , F_14 ( V_23 ) ) ;
V_34 = F_15 ( V_23 ) ;
goto V_37;
}
#if 0
if (di->no_create_file)
flags = O_RDWR | O_LARGEFILE;
else
flags = O_RDWR | O_CREAT | O_LARGEFILE;
#else
V_33 = V_38 | V_39 | V_40 ;
#endif
if ( ! ( V_18 -> V_41 & V_42 ) )
V_33 |= V_43 ;
V_30 = F_16 ( V_23 , V_33 , 0600 ) ;
if ( F_14 ( V_30 ) ) {
F_3 ( V_6 L_11 , V_23 ) ;
V_34 = F_15 ( V_30 ) ;
goto V_37;
}
if ( ! V_30 || ! V_30 -> V_44 ) {
F_3 ( V_6 L_11 , V_23 ) ;
goto V_37;
}
V_18 -> V_45 = V_30 ;
V_31 = V_30 -> V_46 -> V_47 ;
if ( F_17 ( V_31 -> V_48 ) ) {
struct V_49 * V_50 ;
V_50 = F_18 ( V_31 -> V_51 ) ;
V_28 = & V_26 . V_28 ;
V_28 -> V_52 = F_19 ( V_31 -> V_51 ) ;
V_28 -> V_53 = F_20 ( V_50 ) ;
V_28 -> V_54 = F_21 ( V_50 ) ;
V_18 -> V_55 = F_19 ( V_31 -> V_51 ) ;
V_18 -> V_56 = ( F_22 ( V_30 -> V_46 -> V_47 ) -
V_18 -> V_55 ) ;
F_3 ( V_12 L_12
L_13 ,
V_18 -> V_56 ,
F_23 ( V_18 -> V_56 , V_18 -> V_55 ) ,
V_18 -> V_55 ) ;
} else {
if ( ! ( V_18 -> V_41 & V_57 ) ) {
F_3 ( V_6 L_14
L_15
L_16 ) ;
goto V_37;
}
V_28 = & V_26 . V_28 ;
V_28 -> V_52 = V_58 ;
V_28 -> V_53 = V_16 ;
V_28 -> V_54 = V_16 ;
V_18 -> V_55 = V_58 ;
}
V_26 . V_59 = V_60 ;
V_26 . V_61 = V_62 ;
V_24 = F_24 ( V_2 , & V_63 ,
V_21 , V_32 , ( void * ) V_18 ,
& V_26 , L_17 , V_14 ) ;
if ( ! ( V_24 ) )
goto V_37;
V_18 -> V_64 = V_4 -> V_65 ++ ;
V_18 -> V_66 = V_24 -> V_61 ;
F_3 ( V_12 L_18
L_19 , V_4 -> V_7 , V_18 -> V_64 ,
V_18 -> V_36 , V_18 -> V_56 ) ;
F_25 ( V_23 ) ;
return V_24 ;
V_37:
if ( V_18 -> V_45 ) {
F_26 ( V_18 -> V_45 , NULL ) ;
V_18 -> V_45 = NULL ;
}
F_25 ( V_23 ) ;
return F_27 ( V_34 ) ;
}
static void F_28 ( void * V_22 )
{
struct V_18 * V_18 = (struct V_18 * ) V_22 ;
if ( V_18 -> V_45 ) {
F_26 ( V_18 -> V_45 , NULL ) ;
V_18 -> V_45 = NULL ;
}
F_7 ( V_18 ) ;
}
static inline struct V_67 * F_29 ( struct V_68 * V_69 )
{
return F_30 ( V_69 , struct V_67 , V_70 ) ;
}
static struct V_68 *
F_31 ( struct V_71 * V_72 )
{
struct V_67 * V_73 ;
V_73 = F_2 ( sizeof( struct V_67 ) , V_5 ) ;
if ( ! ( V_73 ) ) {
F_3 ( V_6 L_20 ) ;
return NULL ;
}
V_73 -> V_18 = F_32 ( V_72 ) -> V_74 ;
return & V_73 -> V_70 ;
}
static int F_33 ( struct V_68 * V_69 )
{
struct V_67 * V_75 = F_29 ( V_69 ) ;
struct V_30 * V_76 = V_75 -> V_18 -> V_45 ;
struct V_77 * V_78 = V_69 -> V_79 ;
struct V_80 * V_81 ;
T_2 V_29 ;
T_3 V_82 = ( V_69 -> V_83 * F_34 ( V_69 -> V_21 ) -> V_84 ) ;
int V_34 = 0 , V_85 ;
V_81 = F_2 ( sizeof( struct V_80 ) * V_69 -> V_86 , V_5 ) ;
if ( ! ( V_81 ) ) {
F_3 ( V_6 L_21 ) ;
return - 1 ;
}
for ( V_85 = 0 ; V_85 < V_69 -> V_86 ; V_85 ++ ) {
V_81 [ V_85 ] . V_87 = V_78 [ V_85 ] . V_88 ;
V_81 [ V_85 ] . V_89 = F_35 ( & V_78 [ V_85 ] ) ;
}
V_29 = F_10 () ;
F_11 ( F_12 () ) ;
V_34 = F_36 ( V_76 , & V_81 [ 0 ] , V_69 -> V_86 , & V_82 ) ;
F_11 ( V_29 ) ;
F_7 ( V_81 ) ;
if ( F_17 ( V_76 -> V_44 -> V_90 -> V_48 ) ) {
if ( V_34 < 0 || V_34 != V_69 -> V_91 ) {
F_3 ( V_6 L_22
L_23 , V_34 ,
( int ) V_69 -> V_91 ) ;
return - 1 ;
}
} else {
if ( V_34 < 0 ) {
F_3 ( V_6 L_24
L_25 , V_34 ) ;
return - 1 ;
}
}
return 1 ;
}
static int F_37 ( struct V_68 * V_69 )
{
struct V_67 * V_75 = F_29 ( V_69 ) ;
struct V_30 * V_76 = V_75 -> V_18 -> V_45 ;
struct V_77 * V_78 = V_69 -> V_79 ;
struct V_80 * V_81 ;
T_2 V_29 ;
T_3 V_82 = ( V_69 -> V_83 * F_34 ( V_69 -> V_21 ) -> V_84 ) ;
int V_34 , V_85 = 0 ;
V_81 = F_2 ( sizeof( struct V_80 ) * V_69 -> V_86 , V_5 ) ;
if ( ! ( V_81 ) ) {
F_3 ( V_6 L_26 ) ;
return - 1 ;
}
for ( V_85 = 0 ; V_85 < V_69 -> V_86 ; V_85 ++ ) {
V_81 [ V_85 ] . V_87 = V_78 [ V_85 ] . V_88 ;
V_81 [ V_85 ] . V_89 = F_35 ( & V_78 [ V_85 ] ) ;
}
V_29 = F_10 () ;
F_11 ( F_12 () ) ;
V_34 = F_38 ( V_76 , & V_81 [ 0 ] , V_69 -> V_86 , & V_82 ) ;
F_11 ( V_29 ) ;
F_7 ( V_81 ) ;
if ( V_34 < 0 || V_34 != V_69 -> V_91 ) {
F_3 ( V_6 L_27 , V_34 ) ;
return - 1 ;
}
return 1 ;
}
static void F_39 ( struct V_68 * V_69 )
{
struct V_71 * V_72 = F_40 ( V_69 ) ;
struct V_19 * V_24 = V_72 -> V_21 ;
struct V_18 * V_18 = V_24 -> V_74 ;
int V_92 = ( V_72 -> V_93 -> V_94 [ 1 ] & 0x2 ) ;
T_3 V_95 , V_96 ;
int V_34 ;
if ( V_92 )
F_41 ( V_72 , 1 ) ;
if ( V_72 -> V_93 -> V_97 == 0 && V_72 -> V_98 == 0 ) {
V_95 = 0 ;
V_96 = V_99 ;
} else {
V_95 = V_72 -> V_93 -> V_97 * F_34 ( V_24 ) -> V_84 ;
if ( V_72 -> V_98 )
V_96 = V_95 + V_72 -> V_98 ;
else
V_96 = V_99 ;
}
V_34 = F_42 ( V_18 -> V_45 , V_95 , V_96 , 1 ) ;
if ( V_34 != 0 )
F_3 ( V_6 L_28 , V_34 ) ;
if ( ! V_92 )
F_41 ( V_72 , V_34 == 0 ) ;
}
static int F_43 ( struct V_19 * V_24 )
{
return 1 ;
}
static int F_44 ( struct V_19 * V_24 )
{
return 0 ;
}
static int F_45 ( struct V_19 * V_24 )
{
return 1 ;
}
static int F_46 ( struct V_19 * V_24 )
{
return 0 ;
}
static void F_47 ( struct V_71 * V_72 , struct V_68 * V_69 )
{
struct V_19 * V_24 = V_72 -> V_21 ;
struct V_18 * V_18 = V_24 -> V_74 ;
T_3 V_95 = V_69 -> V_83 * F_34 ( V_24 ) -> V_84 ;
T_3 V_96 = V_95 + V_69 -> V_91 ;
int V_34 ;
F_48 ( L_29 ,
V_69 -> V_83 , V_69 -> V_91 ) ;
V_34 = F_42 ( V_18 -> V_45 , V_95 , V_96 , 1 ) ;
if ( V_34 != 0 )
F_3 ( V_6 L_28 , V_34 ) ;
}
static int F_49 ( struct V_68 * V_69 )
{
struct V_71 * V_72 = V_69 -> V_100 ;
struct V_19 * V_24 = V_72 -> V_21 ;
int V_34 = 0 ;
if ( V_69 -> V_101 == V_102 ) {
V_34 = F_33 ( V_69 ) ;
} else {
V_34 = F_37 ( V_69 ) ;
if ( V_34 > 0 &&
F_34 ( V_24 ) -> V_103 > 0 &&
F_34 ( V_24 ) -> V_104 > 0 &&
F_50 ( V_72 ) -> V_105 ) {
F_47 ( V_72 , V_69 ) ;
}
}
if ( V_34 < 0 )
return V_34 ;
if ( V_34 ) {
V_69 -> V_106 = V_107 ;
F_51 ( V_69 , 1 ) ;
}
return V_108 ;
}
static void F_52 ( struct V_68 * V_69 )
{
struct V_67 * V_75 = F_29 ( V_69 ) ;
F_7 ( V_75 ) ;
}
static T_4 F_53 (
struct V_1 * V_2 ,
struct V_20 * V_21 ,
const char * V_109 , T_4 V_110 )
{
struct V_18 * V_18 = V_21 -> V_111 ;
char * V_112 , * V_113 , * V_114 , * V_115 ;
T_5 args [ V_116 ] ;
int V_34 = 0 , V_117 , V_118 ;
V_115 = F_54 ( V_109 , V_5 ) ;
if ( ! V_115 )
return - V_119 ;
V_112 = V_115 ;
while ( ( V_113 = F_55 ( & V_115 , L_30 ) ) != NULL ) {
if ( ! * V_113 )
continue;
V_118 = F_56 ( V_113 , V_120 , args ) ;
switch ( V_118 ) {
case V_121 :
V_114 = F_57 ( & args [ 0 ] ) ;
if ( ! V_114 ) {
V_34 = - V_119 ;
break;
}
snprintf ( V_18 -> V_36 , V_122 ,
L_31 , V_114 ) ;
F_7 ( V_114 ) ;
F_3 ( V_12 L_32 ,
V_18 -> V_36 ) ;
V_18 -> V_41 |= V_123 ;
break;
case V_124 :
V_114 = F_57 ( & args [ 0 ] ) ;
if ( ! V_114 ) {
V_34 = - V_119 ;
break;
}
V_34 = F_58 ( V_114 , 0 , & V_18 -> V_56 ) ;
F_7 ( V_114 ) ;
if ( V_34 < 0 ) {
F_3 ( V_6 L_33
L_34 ) ;
goto V_125;
}
F_3 ( V_12 L_35
L_36 , V_18 -> V_56 ) ;
V_18 -> V_41 |= V_57 ;
break;
case V_126 :
F_59 ( args , & V_117 ) ;
if ( V_117 != 1 ) {
F_3 ( V_6 L_37 , V_117 ) ;
V_34 = - V_35 ;
goto V_125;
}
F_3 ( V_12 L_38
L_39 ) ;
V_18 -> V_41 |= V_42 ;
break;
default:
break;
}
}
V_125:
F_7 ( V_112 ) ;
return ( ! V_34 ) ? V_110 : V_34 ;
}
static T_4 F_60 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_18 * V_18 = (struct V_18 * ) V_21 -> V_111 ;
if ( ! ( V_18 -> V_41 & V_123 ) ) {
F_3 ( V_6 L_40 ) ;
return - 1 ;
}
return 0 ;
}
static T_4 F_61 (
struct V_1 * V_2 ,
struct V_20 * V_21 ,
char * V_127 )
{
struct V_18 * V_18 = V_21 -> V_111 ;
T_4 V_128 = 0 ;
V_128 = sprintf ( V_127 + V_128 , L_41 , V_18 -> V_64 ) ;
V_128 += sprintf ( V_127 + V_128 , L_42 ,
V_18 -> V_36 , V_18 -> V_56 ,
( V_18 -> V_41 & V_42 ) ?
L_43 : L_44 ) ;
return V_128 ;
}
static unsigned char * F_62 ( struct V_68 * V_69 )
{
struct V_67 * V_75 = F_29 ( V_69 ) ;
return V_75 -> V_129 ;
}
static T_1 F_63 ( struct V_19 * V_24 )
{
return V_130 ;
}
static T_1 F_64 ( struct V_19 * V_24 )
{
return V_131 ;
}
static T_6 F_65 ( struct V_19 * V_24 )
{
struct V_18 * V_18 = V_24 -> V_74 ;
unsigned long long V_132 = F_23 ( V_18 -> V_56 ,
F_34 ( V_24 ) -> V_84 ) ;
return V_132 ;
}
static int T_7 F_66 ( void )
{
return F_67 ( & V_63 ) ;
}
static void F_68 ( void )
{
F_69 ( & V_63 ) ;
}
