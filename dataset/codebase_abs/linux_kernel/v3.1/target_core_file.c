static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_4 ;
V_4 = F_2 ( sizeof( struct V_4 ) , V_5 ) ;
if ( ! V_4 ) {
F_3 ( L_1 ) ;
return - V_6 ;
}
V_4 -> V_7 = V_3 ;
V_2 -> V_8 = V_4 ;
F_4 ( L_2
L_3 , V_2 -> V_9 , V_10 ,
V_11 ) ;
F_4 ( L_4
L_5 ,
V_2 -> V_9 , V_4 -> V_7 , V_12 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_2 -> V_8 ;
F_4 ( L_6
L_7 , V_2 -> V_9 , V_4 -> V_7 ) ;
F_6 ( V_4 ) ;
V_2 -> V_8 = NULL ;
}
static void * F_7 ( struct V_1 * V_2 , const char * V_13 )
{
struct V_14 * V_14 ;
struct V_4 * V_4 = (struct V_4 * ) V_2 -> V_8 ;
V_14 = F_2 ( sizeof( struct V_14 ) , V_5 ) ;
if ( ! V_14 ) {
F_3 ( L_8 ) ;
return NULL ;
}
V_14 -> V_4 = V_4 ;
F_4 ( L_9 , V_13 ) ;
return V_14 ;
}
static struct V_15 * F_8 (
struct V_1 * V_2 ,
struct V_16 * V_17 ,
void * V_18 )
{
char * V_19 = NULL ;
struct V_15 * V_20 ;
struct V_21 V_22 ;
struct V_23 * V_24 ;
struct V_14 * V_14 = (struct V_14 * ) V_18 ;
struct V_4 * V_4 = (struct V_4 * ) V_2 -> V_8 ;
T_2 V_25 ;
struct V_26 * V_26 ;
struct V_27 * V_27 = NULL ;
int V_28 = 0 , V_29 , V_30 = - V_31 ;
memset ( & V_22 , 0 , sizeof( struct V_21 ) ) ;
V_25 = F_9 () ;
F_10 ( F_11 () ) ;
V_19 = F_12 ( V_14 -> V_32 ) ;
F_10 ( V_25 ) ;
if ( F_13 ( V_19 ) ) {
F_3 ( L_10 ,
V_14 -> V_32 , F_13 ( V_19 ) ) ;
V_30 = F_14 ( V_19 ) ;
goto V_33;
}
#if 0
if (di->no_create_file)
flags = O_RDWR | O_LARGEFILE;
else
flags = O_RDWR | O_CREAT | O_LARGEFILE;
#else
V_29 = V_34 | V_35 | V_36 ;
#endif
if ( ! ( V_14 -> V_37 & V_38 ) )
V_29 |= V_39 ;
V_26 = F_15 ( V_19 , V_29 , 0600 ) ;
if ( F_13 ( V_26 ) ) {
F_3 ( L_11 , V_19 ) ;
V_30 = F_14 ( V_26 ) ;
goto V_33;
}
if ( ! V_26 || ! V_26 -> V_40 ) {
F_3 ( L_11 , V_19 ) ;
goto V_33;
}
V_14 -> V_41 = V_26 ;
V_27 = V_26 -> V_42 -> V_43 ;
if ( F_16 ( V_27 -> V_44 ) ) {
struct V_45 * V_46 ;
V_46 = F_17 ( V_27 -> V_47 ) ;
V_24 = & V_22 . V_24 ;
V_24 -> V_48 = F_18 ( V_27 -> V_47 ) ;
V_24 -> V_49 = F_19 ( V_46 ) ;
V_24 -> V_50 = F_20 ( V_46 ) ;
V_14 -> V_51 = F_18 ( V_27 -> V_47 ) ;
V_14 -> V_52 = ( F_21 ( V_26 -> V_42 -> V_43 ) -
V_14 -> V_51 ) ;
F_4 ( L_12
L_13 ,
V_14 -> V_52 ,
F_22 ( V_14 -> V_52 , V_14 -> V_51 ) ,
V_14 -> V_51 ) ;
} else {
if ( ! ( V_14 -> V_37 & V_53 ) ) {
F_3 ( L_14
L_15
L_16 ) ;
goto V_33;
}
V_24 = & V_22 . V_24 ;
V_24 -> V_48 = V_54 ;
V_24 -> V_49 = V_12 ;
V_24 -> V_50 = V_12 ;
V_14 -> V_51 = V_54 ;
}
V_22 . V_55 = V_56 ;
V_22 . V_57 = V_58 ;
V_20 = F_23 ( V_2 , & V_59 ,
V_17 , V_28 , V_14 ,
& V_22 , L_17 , V_10 ) ;
if ( ! V_20 )
goto V_33;
V_14 -> V_60 = V_4 -> V_61 ++ ;
V_14 -> V_62 = V_20 -> V_57 ;
F_4 ( L_18
L_19 , V_4 -> V_7 , V_14 -> V_60 ,
V_14 -> V_32 , V_14 -> V_52 ) ;
F_24 ( V_19 ) ;
return V_20 ;
V_33:
if ( V_14 -> V_41 ) {
F_25 ( V_14 -> V_41 , NULL ) ;
V_14 -> V_41 = NULL ;
}
F_24 ( V_19 ) ;
return F_26 ( V_30 ) ;
}
static void F_27 ( void * V_18 )
{
struct V_14 * V_14 = (struct V_14 * ) V_18 ;
if ( V_14 -> V_41 ) {
F_25 ( V_14 -> V_41 , NULL ) ;
V_14 -> V_41 = NULL ;
}
F_6 ( V_14 ) ;
}
static inline struct V_63 * F_28 ( struct V_64 * V_65 )
{
return F_29 ( V_65 , struct V_63 , V_66 ) ;
}
static struct V_64 *
F_30 ( unsigned char * V_67 )
{
struct V_63 * V_68 ;
V_68 = F_2 ( sizeof( struct V_63 ) , V_5 ) ;
if ( ! V_68 ) {
F_3 ( L_20 ) ;
return NULL ;
}
return & V_68 -> V_66 ;
}
static int F_31 ( struct V_64 * V_65 )
{
struct V_63 * V_69 = F_28 ( V_65 ) ;
struct V_14 * V_20 = V_69 -> V_66 . V_17 -> V_70 ;
struct V_26 * V_71 = V_20 -> V_41 ;
struct V_72 * V_73 = V_65 -> V_74 ;
struct V_75 * V_76 ;
T_2 V_25 ;
T_3 V_77 = ( V_65 -> V_78 *
V_65 -> V_17 -> V_79 -> V_80 . V_81 ) ;
int V_30 = 0 , V_82 ;
V_76 = F_2 ( sizeof( struct V_75 ) * V_65 -> V_83 , V_5 ) ;
if ( ! V_76 ) {
F_3 ( L_21 ) ;
return - V_6 ;
}
for ( V_82 = 0 ; V_82 < V_65 -> V_83 ; V_82 ++ ) {
V_76 [ V_82 ] . V_84 = V_73 [ V_82 ] . V_85 ;
V_76 [ V_82 ] . V_86 = F_32 ( & V_73 [ V_82 ] ) ;
}
V_25 = F_9 () ;
F_10 ( F_11 () ) ;
V_30 = F_33 ( V_71 , & V_76 [ 0 ] , V_65 -> V_83 , & V_77 ) ;
F_10 ( V_25 ) ;
F_6 ( V_76 ) ;
if ( F_16 ( V_71 -> V_40 -> V_87 -> V_44 ) ) {
if ( V_30 < 0 || V_30 != V_65 -> V_88 ) {
F_3 ( L_22
L_23 , V_30 ,
( int ) V_65 -> V_88 ) ;
return ( V_30 < 0 ? V_30 : - V_31 ) ;
}
} else {
if ( V_30 < 0 ) {
F_3 ( L_24
L_25 , V_30 ) ;
return V_30 ;
}
}
return 1 ;
}
static int F_34 ( struct V_64 * V_65 )
{
struct V_63 * V_69 = F_28 ( V_65 ) ;
struct V_14 * V_20 = V_69 -> V_66 . V_17 -> V_70 ;
struct V_26 * V_71 = V_20 -> V_41 ;
struct V_72 * V_73 = V_65 -> V_74 ;
struct V_75 * V_76 ;
T_2 V_25 ;
T_3 V_77 = ( V_65 -> V_78 *
V_65 -> V_17 -> V_79 -> V_80 . V_81 ) ;
int V_30 , V_82 = 0 ;
V_76 = F_2 ( sizeof( struct V_75 ) * V_65 -> V_83 , V_5 ) ;
if ( ! V_76 ) {
F_3 ( L_26 ) ;
return - V_6 ;
}
for ( V_82 = 0 ; V_82 < V_65 -> V_83 ; V_82 ++ ) {
V_76 [ V_82 ] . V_84 = V_73 [ V_82 ] . V_85 ;
V_76 [ V_82 ] . V_86 = F_32 ( & V_73 [ V_82 ] ) ;
}
V_25 = F_9 () ;
F_10 ( F_11 () ) ;
V_30 = F_35 ( V_71 , & V_76 [ 0 ] , V_65 -> V_83 , & V_77 ) ;
F_10 ( V_25 ) ;
F_6 ( V_76 ) ;
if ( V_30 < 0 || V_30 != V_65 -> V_88 ) {
F_3 ( L_27 , V_30 ) ;
return ( V_30 < 0 ? V_30 : - V_31 ) ;
}
return 1 ;
}
static void F_36 ( struct V_64 * V_65 )
{
struct V_89 * V_90 = V_65 -> V_91 ;
struct V_15 * V_20 = V_90 -> V_17 ;
struct V_14 * V_14 = V_20 -> V_70 ;
int V_92 = ( V_90 -> V_93 [ 1 ] & 0x2 ) ;
T_3 V_94 , V_95 ;
int V_30 ;
if ( V_92 )
F_37 ( V_90 , 1 ) ;
if ( V_90 -> V_96 == 0 && V_90 -> V_97 == 0 ) {
V_94 = 0 ;
V_95 = V_98 ;
} else {
V_94 = V_90 -> V_96 * V_20 -> V_79 -> V_80 . V_81 ;
if ( V_90 -> V_97 )
V_95 = V_94 + V_90 -> V_97 ;
else
V_95 = V_98 ;
}
V_30 = F_38 ( V_14 -> V_41 , V_94 , V_95 , 1 ) ;
if ( V_30 != 0 )
F_3 ( L_28 , V_30 ) ;
if ( ! V_92 )
F_37 ( V_90 , V_30 == 0 ) ;
}
static int F_39 ( struct V_15 * V_20 )
{
return 1 ;
}
static int F_40 ( struct V_15 * V_20 )
{
return 0 ;
}
static int F_41 ( struct V_15 * V_20 )
{
return 1 ;
}
static int F_42 ( struct V_15 * V_20 )
{
return 0 ;
}
static void F_43 ( struct V_89 * V_90 , struct V_64 * V_65 )
{
struct V_15 * V_20 = V_90 -> V_17 ;
struct V_14 * V_14 = V_20 -> V_70 ;
T_3 V_94 = V_65 -> V_78 * V_20 -> V_79 -> V_80 . V_81 ;
T_3 V_95 = V_94 + V_65 -> V_88 ;
int V_30 ;
F_4 ( L_29 ,
V_65 -> V_78 , V_65 -> V_88 ) ;
V_30 = F_38 ( V_14 -> V_41 , V_94 , V_95 , 1 ) ;
if ( V_30 != 0 )
F_3 ( L_28 , V_30 ) ;
}
static int F_44 ( struct V_64 * V_65 )
{
struct V_89 * V_90 = V_65 -> V_91 ;
struct V_15 * V_20 = V_90 -> V_17 ;
int V_30 = 0 ;
if ( V_65 -> V_99 == V_100 ) {
V_30 = F_31 ( V_65 ) ;
} else {
V_30 = F_34 ( V_65 ) ;
if ( V_30 > 0 &&
V_20 -> V_79 -> V_80 . V_101 > 0 &&
V_20 -> V_79 -> V_80 . V_102 > 0 &&
V_90 -> V_103 ) {
F_43 ( V_90 , V_65 ) ;
}
}
if ( V_30 < 0 )
return V_30 ;
if ( V_30 ) {
V_65 -> V_104 = V_105 ;
F_45 ( V_65 , 1 ) ;
}
return V_106 ;
}
static void F_46 ( struct V_64 * V_65 )
{
struct V_63 * V_69 = F_28 ( V_65 ) ;
F_6 ( V_69 ) ;
}
static T_4 F_47 (
struct V_1 * V_2 ,
struct V_16 * V_17 ,
const char * V_107 , T_4 V_108 )
{
struct V_14 * V_14 = V_17 -> V_109 ;
char * V_110 , * V_111 , * V_112 , * V_113 ;
T_5 args [ V_114 ] ;
int V_30 = 0 , V_115 , V_116 ;
V_113 = F_48 ( V_107 , V_5 ) ;
if ( ! V_113 )
return - V_6 ;
V_110 = V_113 ;
while ( ( V_111 = F_49 ( & V_113 , L_30 ) ) != NULL ) {
if ( ! * V_111 )
continue;
V_116 = F_50 ( V_111 , V_117 , args ) ;
switch ( V_116 ) {
case V_118 :
V_112 = F_51 ( & args [ 0 ] ) ;
if ( ! V_112 ) {
V_30 = - V_6 ;
break;
}
snprintf ( V_14 -> V_32 , V_119 ,
L_31 , V_112 ) ;
F_6 ( V_112 ) ;
F_4 ( L_32 ,
V_14 -> V_32 ) ;
V_14 -> V_37 |= V_120 ;
break;
case V_121 :
V_112 = F_51 ( & args [ 0 ] ) ;
if ( ! V_112 ) {
V_30 = - V_6 ;
break;
}
V_30 = F_52 ( V_112 , 0 , & V_14 -> V_52 ) ;
F_6 ( V_112 ) ;
if ( V_30 < 0 ) {
F_3 ( L_33
L_34 ) ;
goto V_122;
}
F_4 ( L_35
L_36 , V_14 -> V_52 ) ;
V_14 -> V_37 |= V_53 ;
break;
case V_123 :
F_53 ( args , & V_115 ) ;
if ( V_115 != 1 ) {
F_3 ( L_37 , V_115 ) ;
V_30 = - V_31 ;
goto V_122;
}
F_4 ( L_38
L_39 ) ;
V_14 -> V_37 |= V_38 ;
break;
default:
break;
}
}
V_122:
F_6 ( V_110 ) ;
return ( ! V_30 ) ? V_108 : V_30 ;
}
static T_4 F_54 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_14 * V_14 = (struct V_14 * ) V_17 -> V_109 ;
if ( ! ( V_14 -> V_37 & V_120 ) ) {
F_3 ( L_40 ) ;
return - V_31 ;
}
return 0 ;
}
static T_4 F_55 (
struct V_1 * V_2 ,
struct V_16 * V_17 ,
char * V_124 )
{
struct V_14 * V_14 = V_17 -> V_109 ;
T_4 V_125 = 0 ;
V_125 = sprintf ( V_124 + V_125 , L_41 , V_14 -> V_60 ) ;
V_125 += sprintf ( V_124 + V_125 , L_42 ,
V_14 -> V_32 , V_14 -> V_52 ,
( V_14 -> V_37 & V_38 ) ?
L_43 : L_44 ) ;
return V_125 ;
}
static unsigned char * F_56 ( struct V_64 * V_65 )
{
struct V_63 * V_69 = F_28 ( V_65 ) ;
return V_69 -> V_126 ;
}
static T_1 F_57 ( struct V_15 * V_20 )
{
return V_127 ;
}
static T_1 F_58 ( struct V_15 * V_20 )
{
return V_128 ;
}
static T_6 F_59 ( struct V_15 * V_20 )
{
struct V_14 * V_14 = V_20 -> V_70 ;
unsigned long long V_129 = F_22 ( V_14 -> V_52 ,
V_20 -> V_79 -> V_80 . V_81 ) ;
return V_129 ;
}
static int T_7 F_60 ( void )
{
return F_61 ( & V_59 ) ;
}
static void F_62 ( void )
{
F_63 ( & V_59 ) ;
}
