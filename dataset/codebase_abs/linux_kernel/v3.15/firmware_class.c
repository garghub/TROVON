static bool F_1 ( struct V_1 * V_2 , const char * V_3 )
{
struct V_4 * V_5 ;
for ( V_5 = V_6 ; V_5 != V_7 ; V_5 ++ ) {
if ( strcmp ( V_3 , V_5 -> V_3 ) == 0 ) {
V_2 -> V_8 = V_5 -> V_8 ;
V_2 -> V_9 = V_5 -> V_9 ;
return true ;
}
}
return false ;
}
static bool F_2 ( const struct V_1 * V_2 )
{
struct V_4 * V_5 ;
for ( V_5 = V_6 ; V_5 != V_7 ; V_5 ++ )
if ( V_2 -> V_9 == V_5 -> V_9 )
return true ;
return false ;
}
static inline bool F_1 ( struct V_1 * V_2 , const char * V_3 )
{
return false ;
}
static inline bool F_2 ( const struct V_1 * V_2 )
{
return false ;
}
static inline long F_3 ( void )
{
return V_10 > 0 ? V_10 * V_11 : V_12 ;
}
static struct V_13 * F_4 ( const char * V_14 ,
struct V_15 * V_16 )
{
struct V_13 * V_17 ;
V_17 = F_5 ( sizeof( * V_17 ) + strlen ( V_14 ) + 1 , V_18 ) ;
if ( ! V_17 )
return V_17 ;
F_6 ( & V_17 -> V_19 ) ;
strcpy ( V_17 -> V_20 , V_14 ) ;
V_17 -> V_16 = V_16 ;
F_7 ( & V_17 -> V_21 ) ;
#ifdef F_8
F_9 ( & V_17 -> V_22 ) ;
#endif
F_10 ( L_1 , V_23 , V_14 , V_17 ) ;
return V_17 ;
}
static struct V_13 * F_11 ( const char * V_14 )
{
struct V_13 * V_24 ;
struct V_15 * V_16 = & V_25 ;
F_12 (tmp, &fwc->head, list)
if ( ! strcmp ( V_24 -> V_20 , V_14 ) )
return V_24 ;
return NULL ;
}
static int F_13 ( const char * V_14 ,
struct V_15 * V_16 ,
struct V_13 * * V_17 )
{
struct V_13 * V_24 ;
F_14 ( & V_16 -> V_26 ) ;
V_24 = F_11 ( V_14 ) ;
if ( V_24 ) {
F_15 ( & V_24 -> V_19 ) ;
F_16 ( & V_16 -> V_26 ) ;
* V_17 = V_24 ;
return 1 ;
}
V_24 = F_4 ( V_14 , V_16 ) ;
if ( V_24 )
F_17 ( & V_24 -> V_27 , & V_16 -> V_28 ) ;
F_16 ( & V_16 -> V_26 ) ;
* V_17 = V_24 ;
return V_24 ? 0 : - V_29 ;
}
static void F_18 ( struct V_30 * V_19 )
__releases( &fwc->lock
static void F_19 ( struct V_13 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_16 ;
F_14 ( & V_16 -> V_26 ) ;
if ( ! F_20 ( & V_17 -> V_19 , F_18 ) )
F_16 ( & V_16 -> V_26 ) ;
}
static T_1 int F_21 ( struct V_31 * V_31 )
{
struct V_32 V_33 ;
if ( F_22 ( & V_31 -> V_34 , & V_33 ) )
return - 1 ;
if ( ! F_23 ( V_33 . V_35 ) )
return - 1 ;
if ( V_33 . V_8 != ( int ) V_33 . V_8 )
return - 1 ;
return V_33 . V_8 ;
}
static int F_24 ( struct V_31 * V_31 , struct V_13 * V_36 )
{
int V_8 ;
char * V_17 ;
int V_37 ;
V_8 = F_21 ( V_31 ) ;
if ( V_8 <= 0 )
return - V_38 ;
V_17 = F_25 ( V_8 ) ;
if ( ! V_17 )
return - V_29 ;
V_37 = F_26 ( V_31 , 0 , V_17 , V_8 ) ;
if ( V_37 != V_8 ) {
if ( V_37 > 0 )
V_37 = - V_39 ;
F_27 ( V_17 ) ;
return V_37 ;
}
V_36 -> V_9 = V_17 ;
V_36 -> V_8 = V_8 ;
return 0 ;
}
static int F_28 ( struct V_40 * V_40 ,
struct V_13 * V_17 )
{
int V_41 ;
int V_37 = - V_42 ;
char * V_43 = F_29 () ;
for ( V_41 = 0 ; V_41 < F_30 ( V_44 ) ; V_41 ++ ) {
struct V_31 * V_31 ;
if ( ! V_44 [ V_41 ] [ 0 ] )
continue;
snprintf ( V_43 , V_45 , L_2 , V_44 [ V_41 ] , V_17 -> V_20 ) ;
V_31 = F_31 ( V_43 , V_46 , 0 ) ;
if ( F_32 ( V_31 ) )
continue;
V_37 = F_24 ( V_31 , V_17 ) ;
F_33 ( V_31 ) ;
if ( V_37 )
F_34 ( V_40 , L_3 ,
V_43 , V_37 ) ;
else
break;
}
F_35 ( V_43 ) ;
if ( ! V_37 ) {
F_36 ( V_40 , L_4 ,
V_17 -> V_20 ) ;
F_37 ( & V_47 ) ;
F_38 ( V_48 , & V_17 -> V_49 ) ;
F_39 ( & V_17 -> V_21 ) ;
F_40 ( & V_47 ) ;
}
return V_37 ;
}
static void F_41 ( const struct V_1 * V_2 )
{
if ( ! V_2 -> V_50 ) {
F_27 ( V_2 -> V_9 ) ;
return;
}
F_19 ( V_2 -> V_50 ) ;
}
static void F_42 ( struct V_13 * V_17 , struct V_1 * V_2 )
{
V_2 -> V_50 = V_17 ;
#ifdef F_8
V_2 -> V_51 = V_17 -> V_51 ;
#endif
V_2 -> V_8 = V_17 -> V_8 ;
V_2 -> V_9 = V_17 -> V_9 ;
F_10 ( L_5 ,
V_23 , V_17 -> V_20 , V_17 , V_17 -> V_9 ,
( unsigned int ) V_17 -> V_8 ) ;
}
static void F_43 ( struct V_40 * V_52 , void * V_53 )
{
struct V_54 * V_55 = V_53 ;
if ( V_55 -> V_56 == ( unsigned long ) & V_25 )
F_10 ( L_6 ,
V_23 , V_55 -> V_3 , V_53 ) ;
}
static int F_44 ( struct V_40 * V_52 , void * V_53 ,
void * V_57 )
{
struct V_54 * V_55 = V_53 ;
return ( V_55 -> V_56 == ( unsigned long ) & V_25 ) &&
! strcmp ( V_55 -> V_3 , V_57 ) ;
}
static struct V_54 * F_45 ( struct V_40 * V_52 ,
const char * V_3 )
{
struct V_54 * V_55 ;
V_55 = F_46 ( V_52 , F_43 ,
F_44 , ( void * ) V_3 ) ;
return V_55 ;
}
static int F_47 ( struct V_40 * V_52 , const char * V_3 )
{
struct V_54 * V_55 ;
V_55 = F_45 ( V_52 , V_3 ) ;
if ( V_55 )
return 1 ;
V_55 = F_48 ( F_43 , sizeof( struct V_54 ) +
strlen ( V_3 ) + 1 , V_58 ) ;
if ( ! V_55 )
return - V_29 ;
V_55 -> V_56 = ( unsigned long ) & V_25 ;
strcpy ( V_55 -> V_3 , V_3 ) ;
F_49 ( V_52 , V_55 ) ;
return 0 ;
}
static int F_47 ( struct V_40 * V_52 , const char * V_3 )
{
return 0 ;
}
static struct V_59 * F_50 ( struct V_40 * V_52 )
{
return F_51 ( V_52 , struct V_59 , V_52 ) ;
}
static void F_52 ( struct V_13 * V_17 )
{
if ( F_53 ( V_48 , & V_17 -> V_49 ) )
return;
F_54 ( & V_17 -> V_22 ) ;
F_38 ( V_60 , & V_17 -> V_49 ) ;
F_39 ( & V_17 -> V_21 ) ;
}
static void F_55 ( struct V_59 * V_61 )
{
struct V_13 * V_17 = V_61 -> V_17 ;
F_52 ( V_17 ) ;
V_61 -> V_17 = NULL ;
}
static int F_56 ( struct V_62 * V_63 ,
unsigned long V_64 , void * V_65 )
{
F_37 ( & V_47 ) ;
while ( ! F_57 ( & V_66 ) )
F_52 ( F_58 ( & V_66 ,
struct V_13 ,
V_22 ) ) ;
F_40 ( & V_47 ) ;
return V_67 ;
}
static T_2 F_59 ( struct V_68 * V_68 , struct V_69 * V_70 ,
char * V_17 )
{
return sprintf ( V_17 , L_7 , V_10 ) ;
}
static T_2 F_60 ( struct V_68 * V_68 , struct V_69 * V_70 ,
const char * V_17 , T_3 V_71 )
{
V_10 = F_61 ( V_17 , NULL , 10 ) ;
if ( V_10 < 0 )
V_10 = 0 ;
return V_71 ;
}
static void F_62 ( struct V_40 * V_52 )
{
struct V_59 * V_61 = F_50 ( V_52 ) ;
F_63 ( V_61 ) ;
}
static int F_64 ( struct V_40 * V_52 , struct V_72 * V_73 )
{
struct V_59 * V_61 = F_50 ( V_52 ) ;
if ( F_65 ( V_73 , L_8 , V_61 -> V_17 -> V_20 ) )
return - V_29 ;
if ( F_65 ( V_73 , L_9 , V_10 ) )
return - V_29 ;
if ( F_65 ( V_73 , L_10 , V_61 -> V_74 ) )
return - V_29 ;
return 0 ;
}
static T_2 F_66 ( struct V_40 * V_52 ,
struct V_75 * V_70 , char * V_17 )
{
struct V_59 * V_61 = F_50 ( V_52 ) ;
int V_76 = 0 ;
F_37 ( & V_47 ) ;
if ( V_61 -> V_17 )
V_76 = F_53 ( V_77 , & V_61 -> V_17 -> V_49 ) ;
F_40 ( & V_47 ) ;
return sprintf ( V_17 , L_7 , V_76 ) ;
}
static int F_67 ( struct V_13 * V_17 )
{
if ( ! V_17 -> V_78 )
return 0 ;
if ( V_17 -> V_9 )
F_68 ( V_17 -> V_9 ) ;
V_17 -> V_9 = F_69 ( V_17 -> V_51 , V_17 -> V_79 , 0 , V_80 ) ;
if ( ! V_17 -> V_9 )
return - V_29 ;
return 0 ;
}
static T_2 F_70 ( struct V_40 * V_52 ,
struct V_75 * V_70 ,
const char * V_17 , T_3 V_71 )
{
struct V_59 * V_61 = F_50 ( V_52 ) ;
struct V_13 * V_36 ;
int V_76 = F_61 ( V_17 , NULL , 10 ) ;
int V_41 ;
F_37 ( & V_47 ) ;
V_36 = V_61 -> V_17 ;
if ( ! V_36 )
goto V_81;
switch ( V_76 ) {
case 1 :
if ( ! F_53 ( V_48 , & V_36 -> V_49 ) ) {
for ( V_41 = 0 ; V_41 < V_36 -> V_79 ; V_41 ++ )
F_71 ( V_36 -> V_51 [ V_41 ] ) ;
F_63 ( V_36 -> V_51 ) ;
V_36 -> V_51 = NULL ;
V_36 -> V_82 = 0 ;
V_36 -> V_79 = 0 ;
F_38 ( V_77 , & V_36 -> V_49 ) ;
}
break;
case 0 :
if ( F_53 ( V_77 , & V_36 -> V_49 ) ) {
F_38 ( V_48 , & V_36 -> V_49 ) ;
F_72 ( V_77 , & V_36 -> V_49 ) ;
if ( F_67 ( V_36 ) )
F_73 ( V_52 , L_11 ,
V_23 ) ;
F_54 ( & V_36 -> V_22 ) ;
F_39 ( & V_36 -> V_21 ) ;
break;
}
default:
F_73 ( V_52 , L_12 , V_23 , V_76 ) ;
case - 1 :
F_55 ( V_61 ) ;
break;
}
V_81:
F_40 ( & V_47 ) ;
return V_71 ;
}
static T_2 F_74 ( struct V_31 * V_83 , struct V_84 * V_85 ,
struct V_86 * V_87 ,
char * V_88 , T_4 V_89 , T_3 V_71 )
{
struct V_40 * V_52 = F_75 ( V_85 ) ;
struct V_59 * V_61 = F_50 ( V_52 ) ;
struct V_13 * V_17 ;
T_2 V_90 ;
F_37 ( & V_47 ) ;
V_17 = V_61 -> V_17 ;
if ( ! V_17 || F_53 ( V_48 , & V_17 -> V_49 ) ) {
V_90 = - V_91 ;
goto V_81;
}
if ( V_89 > V_17 -> V_8 ) {
V_90 = 0 ;
goto V_81;
}
if ( V_71 > V_17 -> V_8 - V_89 )
V_71 = V_17 -> V_8 - V_89 ;
V_90 = V_71 ;
while ( V_71 ) {
void * V_92 ;
int V_93 = V_89 >> V_94 ;
int V_95 = V_89 & ( V_96 - 1 ) ;
int V_97 = F_76 ( T_3 , V_96 - V_95 , V_71 ) ;
V_92 = F_77 ( V_17 -> V_51 [ V_93 ] ) ;
memcpy ( V_88 , V_92 + V_95 , V_97 ) ;
F_78 ( V_17 -> V_51 [ V_93 ] ) ;
V_88 += V_97 ;
V_89 += V_97 ;
V_71 -= V_97 ;
}
V_81:
F_40 ( & V_47 ) ;
return V_90 ;
}
static int F_79 ( struct V_59 * V_61 , int V_98 )
{
struct V_13 * V_17 = V_61 -> V_17 ;
int V_99 = F_80 ( V_98 , V_96 ) >> V_94 ;
if ( V_17 -> V_82 < V_99 ) {
int V_100 = F_81 ( V_99 ,
V_17 -> V_82 * 2 ) ;
struct V_101 * * V_102 ;
V_102 = F_82 ( V_100 * sizeof( void * ) ,
V_58 ) ;
if ( ! V_102 ) {
F_55 ( V_61 ) ;
return - V_29 ;
}
memcpy ( V_102 , V_17 -> V_51 ,
V_17 -> V_82 * sizeof( void * ) ) ;
memset ( & V_102 [ V_17 -> V_82 ] , 0 , sizeof( void * ) *
( V_100 - V_17 -> V_82 ) ) ;
F_63 ( V_17 -> V_51 ) ;
V_17 -> V_51 = V_102 ;
V_17 -> V_82 = V_100 ;
}
while ( V_17 -> V_79 < V_99 ) {
V_17 -> V_51 [ V_17 -> V_79 ] =
F_83 ( V_58 | V_103 ) ;
if ( ! V_17 -> V_51 [ V_17 -> V_79 ] ) {
F_55 ( V_61 ) ;
return - V_29 ;
}
V_17 -> V_79 ++ ;
}
return 0 ;
}
static T_2 F_84 ( struct V_31 * V_83 , struct V_84 * V_85 ,
struct V_86 * V_87 ,
char * V_88 , T_4 V_89 , T_3 V_71 )
{
struct V_40 * V_52 = F_75 ( V_85 ) ;
struct V_59 * V_61 = F_50 ( V_52 ) ;
struct V_13 * V_17 ;
T_2 V_104 ;
if ( ! F_85 ( V_105 ) )
return - V_106 ;
F_37 ( & V_47 ) ;
V_17 = V_61 -> V_17 ;
if ( ! V_17 || F_53 ( V_48 , & V_17 -> V_49 ) ) {
V_104 = - V_91 ;
goto V_81;
}
V_104 = F_79 ( V_61 , V_89 + V_71 ) ;
if ( V_104 )
goto V_81;
V_104 = V_71 ;
while ( V_71 ) {
void * V_92 ;
int V_93 = V_89 >> V_94 ;
int V_95 = V_89 & ( V_96 - 1 ) ;
int V_97 = F_76 ( T_3 , V_96 - V_95 , V_71 ) ;
V_92 = F_77 ( V_17 -> V_51 [ V_93 ] ) ;
memcpy ( V_92 + V_95 , V_88 , V_97 ) ;
F_78 ( V_17 -> V_51 [ V_93 ] ) ;
V_88 += V_97 ;
V_89 += V_97 ;
V_71 -= V_97 ;
}
V_17 -> V_8 = F_86 ( T_3 , V_89 , V_17 -> V_8 ) ;
V_81:
F_40 ( & V_47 ) ;
return V_104 ;
}
static void F_87 ( struct V_107 * V_108 )
{
struct V_59 * V_61 = F_51 ( V_108 ,
struct V_59 , V_109 . V_108 ) ;
F_37 ( & V_47 ) ;
F_55 ( V_61 ) ;
F_40 ( & V_47 ) ;
}
static struct V_59 *
F_88 ( struct V_1 * V_1 , const char * V_14 ,
struct V_40 * V_40 , unsigned int V_110 )
{
struct V_59 * V_61 ;
struct V_40 * V_111 ;
V_61 = F_5 ( sizeof( * V_61 ) , V_58 ) ;
if ( ! V_61 ) {
F_73 ( V_40 , L_13 , V_23 ) ;
V_61 = F_89 ( - V_29 ) ;
goto exit;
}
V_61 -> V_74 = ! ! ( V_110 & V_112 ) ;
V_61 -> V_2 = V_1 ;
F_90 ( & V_61 -> V_109 ,
F_87 ) ;
V_111 = & V_61 -> V_52 ;
F_91 ( V_111 ) ;
F_92 ( V_111 , L_14 , V_14 ) ;
V_111 -> V_113 = V_40 ;
V_111 -> V_68 = & V_114 ;
exit:
return V_61 ;
}
static int F_93 ( struct V_59 * V_61 ,
unsigned int V_110 , long V_115 )
{
int V_104 = 0 ;
struct V_40 * V_111 = & V_61 -> V_52 ;
struct V_13 * V_17 = V_61 -> V_17 ;
V_17 -> V_78 = true ;
F_94 ( V_111 , true ) ;
V_104 = F_95 ( V_111 ) ;
if ( V_104 ) {
F_73 ( V_111 , L_15 , V_23 ) ;
goto V_116;
}
V_104 = F_96 ( V_111 , & V_117 ) ;
if ( V_104 ) {
F_73 ( V_111 , L_16 , V_23 ) ;
goto V_118;
}
F_37 ( & V_47 ) ;
F_17 ( & V_17 -> V_22 , & V_66 ) ;
F_40 ( & V_47 ) ;
V_104 = F_97 ( V_111 , & V_119 ) ;
if ( V_104 ) {
F_37 ( & V_47 ) ;
F_54 ( & V_17 -> V_22 ) ;
F_40 ( & V_47 ) ;
F_73 ( V_111 , L_17 , V_23 ) ;
goto V_120;
}
if ( V_110 & V_121 ) {
V_17 -> V_122 = true ;
F_94 ( V_111 , false ) ;
F_36 ( V_111 , L_18 , V_17 -> V_20 ) ;
if ( V_115 != V_12 )
F_98 ( V_123 ,
& V_61 -> V_109 , V_115 ) ;
F_99 ( & V_61 -> V_52 . V_85 , V_124 ) ;
}
F_100 ( & V_17 -> V_21 ) ;
F_101 ( & V_61 -> V_109 ) ;
if ( ! V_17 -> V_9 )
V_104 = - V_29 ;
F_102 ( V_111 , & V_119 ) ;
V_120:
F_103 ( V_111 , & V_117 ) ;
V_118:
F_104 ( V_111 ) ;
V_116:
F_105 ( V_111 ) ;
return V_104 ;
}
static int F_106 ( struct V_1 * V_1 ,
const char * V_3 , struct V_40 * V_40 ,
unsigned int V_110 , long V_115 )
{
struct V_59 * V_61 ;
V_61 = F_88 ( V_1 , V_3 , V_40 , V_110 ) ;
if ( F_32 ( V_61 ) )
return F_107 ( V_61 ) ;
V_61 -> V_17 = V_1 -> V_50 ;
return F_93 ( V_61 , V_110 , V_115 ) ;
}
static void F_108 ( void )
{
struct V_13 * V_17 ;
struct V_13 * V_125 ;
F_37 ( & V_47 ) ;
F_109 (buf, next, &pending_fw_head, pending_list) {
if ( ! V_17 -> V_122 )
F_52 ( V_17 ) ;
}
F_40 ( & V_47 ) ;
}
static inline int
F_106 ( struct V_1 * V_1 , const char * V_3 ,
struct V_40 * V_40 , unsigned int V_110 ,
long V_115 )
{
return - V_42 ;
}
static inline void F_108 ( void ) { }
static int F_110 ( struct V_13 * V_17 )
{
int V_126 = 0 ;
F_37 ( & V_47 ) ;
while ( ! F_53 ( V_48 , & V_17 -> V_49 ) ) {
if ( F_111 ( V_17 ) ) {
V_126 = - V_42 ;
break;
}
F_40 ( & V_47 ) ;
F_100 ( & V_17 -> V_21 ) ;
F_37 ( & V_47 ) ;
}
F_40 ( & V_47 ) ;
return V_126 ;
}
static int
F_112 ( struct V_1 * * V_127 , const char * V_3 ,
struct V_40 * V_40 )
{
struct V_1 * V_1 ;
struct V_13 * V_17 ;
int V_126 ;
* V_127 = V_1 = F_5 ( sizeof( * V_1 ) , V_58 ) ;
if ( ! V_1 ) {
F_73 ( V_40 , L_19 ,
V_23 ) ;
return - V_29 ;
}
if ( F_1 ( V_1 , V_3 ) ) {
F_36 ( V_40 , L_20 , V_3 ) ;
return 0 ;
}
V_126 = F_13 ( V_3 , & V_25 , & V_17 ) ;
V_1 -> V_50 = V_17 ;
if ( V_126 > 0 ) {
V_126 = F_110 ( V_17 ) ;
if ( ! V_126 ) {
F_42 ( V_17 , V_1 ) ;
return 0 ;
}
}
if ( V_126 < 0 )
return V_126 ;
return 1 ;
}
static int F_113 ( struct V_1 * V_2 , struct V_40 * V_40 ,
unsigned int V_110 )
{
struct V_13 * V_17 = V_2 -> V_50 ;
F_37 ( & V_47 ) ;
if ( ! V_17 -> V_8 || F_111 ( V_17 ) ) {
F_40 ( & V_47 ) ;
return - V_42 ;
}
if ( V_40 && ( V_110 & V_121 ) )
F_47 ( V_40 , V_17 -> V_20 ) ;
if ( V_17 -> V_16 -> V_128 == V_129 ) {
if ( F_114 ( V_17 -> V_20 ) )
F_15 ( & V_17 -> V_19 ) ;
}
F_42 ( V_17 , V_2 ) ;
F_40 ( & V_47 ) ;
return 0 ;
}
static int
F_115 ( const struct V_1 * * V_127 , const char * V_3 ,
struct V_40 * V_40 , unsigned int V_110 )
{
struct V_1 * V_2 ;
long V_115 ;
int V_126 ;
if ( ! V_127 )
return - V_38 ;
V_126 = F_112 ( & V_2 , V_3 , V_40 ) ;
if ( V_126 <= 0 )
goto V_81;
V_126 = 0 ;
V_115 = F_3 () ;
if ( V_110 & V_112 ) {
V_115 = F_116 ( V_115 ) ;
if ( ! V_115 ) {
F_36 ( V_40 , L_21 ,
V_3 ) ;
V_126 = - V_130 ;
goto V_81;
}
} else {
V_126 = F_117 () ;
if ( F_118 ( V_126 ) ) {
F_73 ( V_40 , L_22 ,
V_3 ) ;
goto V_81;
}
}
V_126 = F_28 ( V_40 , V_2 -> V_50 ) ;
if ( V_126 ) {
if ( V_110 & V_131 ) {
F_34 ( V_40 ,
L_23 ,
V_126 ) ;
F_34 ( V_40 , L_24 ) ;
V_126 = F_106 ( V_2 , V_3 , V_40 ,
V_110 , V_115 ) ;
}
}
if ( ! V_126 )
V_126 = F_113 ( V_2 , V_40 , V_110 ) ;
F_119 () ;
V_81:
if ( V_126 < 0 ) {
F_120 ( V_2 ) ;
V_2 = NULL ;
}
* V_127 = V_2 ;
return V_126 ;
}
int
F_121 ( const struct V_1 * * V_127 , const char * V_3 ,
struct V_40 * V_40 )
{
int V_126 ;
F_122 ( V_132 ) ;
V_126 = F_115 ( V_127 , V_3 , V_40 ,
V_121 | V_131 ) ;
F_123 ( V_132 ) ;
return V_126 ;
}
int F_124 ( const struct V_1 * * V_127 ,
const char * V_3 , struct V_40 * V_40 )
{
int V_126 ;
F_122 ( V_132 ) ;
V_126 = F_115 ( V_127 , V_3 , V_40 , V_121 ) ;
F_123 ( V_132 ) ;
return V_126 ;
}
void F_120 ( const struct V_1 * V_2 )
{
if ( V_2 ) {
if ( ! F_2 ( V_2 ) )
F_41 ( V_2 ) ;
F_63 ( V_2 ) ;
}
}
static void F_125 ( struct V_107 * V_108 )
{
struct V_133 * V_134 ;
const struct V_1 * V_2 ;
V_134 = F_51 ( V_108 , struct V_133 , V_108 ) ;
F_115 ( & V_2 , V_134 -> V_3 , V_134 -> V_40 ,
V_134 -> V_110 ) ;
V_134 -> V_135 ( V_2 , V_134 -> V_136 ) ;
F_105 ( V_134 -> V_40 ) ;
F_123 ( V_134 -> V_137 ) ;
F_63 ( V_134 ) ;
}
int
F_126 (
struct V_137 * V_137 , bool V_138 ,
const char * V_3 , struct V_40 * V_40 , T_5 V_139 , void * V_136 ,
void (* V_135)( const struct V_1 * V_2 , void * V_136 ) )
{
struct V_133 * V_134 ;
V_134 = F_5 ( sizeof ( struct V_133 ) , V_139 ) ;
if ( ! V_134 )
return - V_29 ;
V_134 -> V_137 = V_137 ;
V_134 -> V_3 = V_3 ;
V_134 -> V_40 = V_40 ;
V_134 -> V_136 = V_136 ;
V_134 -> V_135 = V_135 ;
V_134 -> V_110 = V_112 | V_131 |
( V_138 ? V_121 : 0 ) ;
if ( ! F_127 ( V_137 ) ) {
F_63 ( V_134 ) ;
return - V_140 ;
}
F_128 ( V_134 -> V_40 ) ;
F_129 ( & V_134 -> V_108 , F_125 ) ;
F_130 ( & V_134 -> V_108 ) ;
return 0 ;
}
static int F_131 ( const char * V_14 )
{
int V_126 ;
const struct V_1 * V_2 ;
F_10 ( L_25 , V_23 , V_14 ) ;
V_126 = F_121 ( & V_2 , V_14 , NULL ) ;
if ( ! V_126 )
F_63 ( V_2 ) ;
F_10 ( L_26 , V_23 , V_14 , V_126 ) ;
return V_126 ;
}
static struct V_13 * F_132 ( const char * V_14 )
{
struct V_13 * V_24 ;
struct V_15 * V_16 = & V_25 ;
F_14 ( & V_16 -> V_26 ) ;
V_24 = F_11 ( V_14 ) ;
F_16 ( & V_16 -> V_26 ) ;
return V_24 ;
}
static int F_133 ( const char * V_14 )
{
struct V_13 * V_17 ;
struct V_1 V_2 ;
F_10 ( L_25 , V_23 , V_14 ) ;
if ( F_1 ( & V_2 , V_14 ) )
return 0 ;
V_17 = F_132 ( V_14 ) ;
if ( V_17 ) {
F_19 ( V_17 ) ;
return 0 ;
}
return - V_38 ;
}
static struct V_141 * F_134 ( const char * V_3 )
{
struct V_141 * V_142 ;
V_142 = F_5 ( sizeof( * V_142 ) + strlen ( V_3 ) + 1 , V_18 ) ;
if ( ! V_142 )
goto exit;
strcpy ( V_142 -> V_3 , V_3 ) ;
exit:
return V_142 ;
}
static int F_135 ( const char * V_3 )
{
struct V_15 * V_16 = & V_25 ;
struct V_141 * V_142 ;
F_12 (fce, &fwc->fw_names, list) {
if ( ! strcmp ( V_142 -> V_3 , V_3 ) )
return 1 ;
}
return 0 ;
}
static int F_114 ( const char * V_3 )
{
struct V_15 * V_16 = & V_25 ;
struct V_141 * V_142 ;
int V_126 = 0 ;
F_14 ( & V_16 -> V_143 ) ;
if ( F_135 ( V_3 ) )
goto V_144;
V_142 = F_134 ( V_3 ) ;
if ( V_142 ) {
V_126 = 1 ;
F_17 ( & V_142 -> V_27 , & V_16 -> V_145 ) ;
F_10 ( L_27 , V_23 , V_3 ) ;
}
V_144:
F_16 ( & V_16 -> V_143 ) ;
return V_126 ;
}
static void F_136 ( struct V_141 * V_142 )
{
F_63 ( V_142 ) ;
}
static void F_137 ( void * V_146 ,
T_6 V_147 )
{
struct V_141 * V_142 = V_146 ;
struct V_15 * V_16 = & V_25 ;
int V_126 ;
V_126 = F_131 ( V_142 -> V_3 ) ;
if ( V_126 ) {
F_14 ( & V_16 -> V_143 ) ;
F_138 ( & V_142 -> V_27 ) ;
F_16 ( & V_16 -> V_143 ) ;
F_136 ( V_142 ) ;
}
}
static void F_139 ( struct V_40 * V_52 , void * V_53 ,
void * V_9 )
{
struct V_54 * V_55 = V_53 ;
const char * V_14 = V_55 -> V_3 ;
struct V_148 * V_28 = V_9 ;
struct V_141 * V_142 ;
V_142 = F_134 ( V_14 ) ;
if ( V_142 )
F_17 ( & V_142 -> V_27 , V_28 ) ;
}
static int F_140 ( struct V_40 * V_52 , void * V_53 ,
void * V_57 )
{
struct V_54 * V_55 = V_53 ;
return ( V_55 -> V_56 == ( unsigned long ) V_57 ) ;
}
static void F_141 ( struct V_40 * V_52 , void * V_9 )
{
F_142 ( V_149 ) ;
struct V_141 * V_142 ;
struct V_141 * V_150 ;
struct V_15 * V_16 = & V_25 ;
F_143 ( V_52 , F_43 ,
F_140 , & V_25 ,
F_139 , & V_149 ) ;
F_109 (fce, fce_next, &todo, list) {
F_138 ( & V_142 -> V_27 ) ;
F_14 ( & V_16 -> V_143 ) ;
if ( ! F_135 ( V_142 -> V_3 ) ) {
F_17 ( & V_142 -> V_27 , & V_16 -> V_145 ) ;
} else {
F_136 ( V_142 ) ;
V_142 = NULL ;
}
F_16 ( & V_16 -> V_143 ) ;
if ( V_142 )
F_144 ( F_137 ,
( void * ) V_142 ,
& V_151 ) ;
}
}
static void F_145 ( void )
{
struct V_15 * V_16 = & V_25 ;
struct V_141 * V_142 ;
F_14 ( & V_16 -> V_143 ) ;
while ( ! F_57 ( & V_16 -> V_145 ) ) {
V_142 = F_146 ( V_16 -> V_145 . V_125 ,
struct V_141 , V_27 ) ;
F_138 ( & V_142 -> V_27 ) ;
F_16 ( & V_16 -> V_143 ) ;
F_133 ( V_142 -> V_3 ) ;
F_136 ( V_142 ) ;
F_14 ( & V_16 -> V_143 ) ;
}
F_16 ( & V_16 -> V_143 ) ;
}
static void F_147 ( void )
{
struct V_15 * V_16 = & V_25 ;
int V_152 ;
F_148 ( V_153 ) ;
F_10 ( L_28 , V_23 ) ;
F_101 ( & V_16 -> V_108 ) ;
V_152 = V_10 ;
V_10 = 10 ;
F_37 ( & V_47 ) ;
V_16 -> V_128 = V_129 ;
F_149 ( NULL , F_141 ) ;
F_40 ( & V_47 ) ;
F_150 ( & V_151 ) ;
V_10 = V_152 ;
}
static void F_151 ( void )
{
F_10 ( L_28 , V_23 ) ;
F_145 () ;
}
static void F_152 ( struct V_107 * V_108 )
{
F_151 () ;
}
static void F_153 ( unsigned long V_154 )
{
F_98 ( V_123 , & V_25 . V_108 ,
F_154 ( V_154 ) ) ;
}
static int F_155 ( struct V_62 * V_155 ,
unsigned long V_35 , void * V_156 )
{
switch ( V_35 ) {
case V_157 :
case V_158 :
case V_159 :
F_108 () ;
F_147 () ;
break;
case V_160 :
case V_161 :
case V_162 :
F_37 ( & V_47 ) ;
V_25 . V_128 = V_163 ;
F_40 ( & V_47 ) ;
F_153 ( 10 * V_164 ) ;
break;
}
return 0 ;
}
static int F_156 ( void )
{
V_25 . V_128 = V_163 ;
return 0 ;
}
static int F_114 ( const char * V_3 )
{
return 0 ;
}
static void T_7 F_157 ( void )
{
F_158 ( & V_25 . V_26 ) ;
F_9 ( & V_25 . V_28 ) ;
V_25 . V_128 = V_163 ;
#ifdef F_159
F_158 ( & V_25 . V_143 ) ;
F_9 ( & V_25 . V_145 ) ;
F_90 ( & V_25 . V_108 ,
F_152 ) ;
V_25 . V_165 . V_166 = F_155 ;
F_160 ( & V_25 . V_165 ) ;
F_161 ( & V_167 ) ;
#endif
}
static int T_7 F_162 ( void )
{
F_157 () ;
#ifdef F_8
F_163 ( & V_168 ) ;
return F_164 ( & V_114 ) ;
#else
return 0 ;
#endif
}
static void T_8 F_165 ( void )
{
#ifdef F_159
F_166 ( & V_167 ) ;
F_167 ( & V_25 . V_165 ) ;
#endif
#ifdef F_8
F_168 ( & V_168 ) ;
F_169 ( & V_114 ) ;
#endif
}
