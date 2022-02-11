static bool F_1 ( struct V_1 * V_2 , const char * V_3 ,
void * V_4 , T_1 V_5 )
{
struct V_6 * V_7 ;
for ( V_7 = V_8 ; V_7 != V_9 ; V_7 ++ ) {
if ( strcmp ( V_3 , V_7 -> V_3 ) == 0 ) {
V_2 -> V_5 = V_7 -> V_5 ;
V_2 -> V_10 = V_7 -> V_10 ;
if ( V_4 && V_2 -> V_5 <= V_5 )
memcpy ( V_4 , V_2 -> V_10 , V_2 -> V_5 ) ;
return true ;
}
}
return false ;
}
static bool F_2 ( const struct V_1 * V_2 )
{
struct V_6 * V_7 ;
for ( V_7 = V_8 ; V_7 != V_9 ; V_7 ++ )
if ( V_2 -> V_10 == V_7 -> V_10 )
return true ;
return false ;
}
static inline bool F_1 ( struct V_1 * V_2 ,
const char * V_3 , void * V_4 ,
T_1 V_5 )
{
return false ;
}
static inline bool F_2 ( const struct V_1 * V_2 )
{
return false ;
}
static inline long F_3 ( void )
{
return V_11 > 0 ? V_11 * V_12 : V_13 ;
}
static void F_4 ( struct V_14 * V_15 )
{
F_5 ( & V_15 -> V_16 ) ;
V_15 -> V_17 = V_18 ;
}
static inline bool F_6 ( enum V_19 V_17 )
{
return V_17 == V_20 || V_17 == V_21 ;
}
static int F_7 ( struct V_14 * V_15 , long V_22 )
{
long V_23 ;
V_23 = F_8 ( & V_15 -> V_16 , V_22 ) ;
if ( V_23 != 0 && V_15 -> V_17 == V_21 )
return - V_24 ;
if ( ! V_23 )
return - V_25 ;
return V_23 < 0 ? V_23 : 0 ;
}
static void F_9 ( struct V_14 * V_15 ,
enum V_19 V_17 )
{
F_10 ( V_15 -> V_17 , V_17 ) ;
if ( V_17 == V_20 || V_17 == V_21 )
F_11 ( & V_15 -> V_16 ) ;
}
static int F_12 ( struct V_14 * V_15 , enum V_19 V_17 )
{
return V_15 -> V_17 == V_17 ;
}
static void F_13 ( void )
{
F_14 ( & V_26 ) ;
V_27 = true ;
F_15 ( & V_26 ) ;
}
static void F_16 ( void )
{
F_14 ( & V_26 ) ;
V_27 = false ;
F_15 ( & V_26 ) ;
}
static bool F_17 ( void )
{
bool V_28 = false ;
F_14 ( & V_26 ) ;
if ( V_27 )
V_28 = true ;
F_15 ( & V_26 ) ;
return V_28 ;
}
static struct V_29 * F_18 ( const char * V_30 ,
struct V_31 * V_32 ,
void * V_33 , T_1 V_5 )
{
struct V_29 * V_4 ;
V_4 = F_19 ( sizeof( * V_4 ) , V_34 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_35 = F_20 ( V_30 , V_34 ) ;
if ( ! V_4 -> V_35 ) {
F_21 ( V_4 ) ;
return NULL ;
}
F_22 ( & V_4 -> V_36 ) ;
V_4 -> V_32 = V_32 ;
V_4 -> V_10 = V_33 ;
V_4 -> V_37 = V_5 ;
F_4 ( & V_4 -> V_15 ) ;
#ifdef F_23
F_24 ( & V_4 -> V_38 ) ;
#endif
F_25 ( L_1 , V_39 , V_30 , V_4 ) ;
return V_4 ;
}
static struct V_29 * F_26 ( const char * V_30 )
{
struct V_29 * V_40 ;
struct V_31 * V_32 = & V_41 ;
F_27 (tmp, &fwc->head, list)
if ( ! strcmp ( V_40 -> V_35 , V_30 ) )
return V_40 ;
return NULL ;
}
static int F_28 ( const char * V_30 ,
struct V_31 * V_32 ,
struct V_29 * * V_4 , void * V_33 ,
T_1 V_5 )
{
struct V_29 * V_40 ;
F_29 ( & V_32 -> V_42 ) ;
V_40 = F_26 ( V_30 ) ;
if ( V_40 ) {
F_30 ( & V_40 -> V_36 ) ;
F_31 ( & V_32 -> V_42 ) ;
* V_4 = V_40 ;
return 1 ;
}
V_40 = F_18 ( V_30 , V_32 , V_33 , V_5 ) ;
if ( V_40 )
F_32 ( & V_40 -> V_43 , & V_32 -> V_44 ) ;
F_31 ( & V_32 -> V_42 ) ;
* V_4 = V_40 ;
return V_40 ? 0 : - V_45 ;
}
static void F_33 ( struct V_46 * V_36 )
__releases( &fwc->lock
static void F_34 ( struct V_29 * V_4 )
{
struct V_31 * V_32 = V_4 -> V_32 ;
F_29 ( & V_32 -> V_42 ) ;
if ( ! F_35 ( & V_4 -> V_36 , F_33 ) )
F_31 ( & V_32 -> V_42 ) ;
}
static int
F_36 ( struct V_47 * V_47 , struct V_29 * V_4 )
{
T_2 V_5 ;
int V_48 , V_49 ;
int V_50 = - V_24 ;
char * V_51 ;
enum V_52 V_53 = V_54 ;
T_1 V_55 = V_56 ;
if ( V_4 -> V_10 ) {
V_53 = V_57 ;
V_55 = V_4 -> V_37 ;
}
V_51 = F_37 () ;
if ( ! V_51 )
return - V_45 ;
for ( V_48 = 0 ; V_48 < F_38 ( V_58 ) ; V_48 ++ ) {
if ( ! V_58 [ V_48 ] [ 0 ] )
continue;
V_49 = snprintf ( V_51 , V_59 , L_2 ,
V_58 [ V_48 ] , V_4 -> V_35 ) ;
if ( V_49 >= V_59 ) {
V_50 = - V_60 ;
break;
}
V_4 -> V_5 = 0 ;
V_50 = F_39 ( V_51 , & V_4 -> V_10 , & V_5 , V_55 ,
V_53 ) ;
if ( V_50 ) {
if ( V_50 == - V_24 )
F_40 ( V_47 , L_3 ,
V_51 , V_50 ) ;
else
F_41 ( V_47 , L_3 ,
V_51 , V_50 ) ;
continue;
}
F_40 ( V_47 , L_4 , V_4 -> V_35 ) ;
V_4 -> V_5 = V_5 ;
F_42 ( & V_4 -> V_15 ) ;
break;
}
F_43 ( V_51 ) ;
return V_50 ;
}
static void F_44 ( const struct V_1 * V_2 )
{
if ( ! V_2 -> V_61 ) {
F_45 ( V_2 -> V_10 ) ;
return;
}
F_34 ( V_2 -> V_61 ) ;
}
static void F_46 ( struct V_29 * V_4 , struct V_1 * V_2 )
{
V_2 -> V_61 = V_4 ;
#ifdef F_23
V_2 -> V_62 = V_4 -> V_62 ;
#endif
V_2 -> V_5 = V_4 -> V_5 ;
V_2 -> V_10 = V_4 -> V_10 ;
F_25 ( L_5 ,
V_39 , V_4 -> V_35 , V_4 , V_4 -> V_10 ,
( unsigned int ) V_4 -> V_5 ) ;
}
static void F_47 ( struct V_47 * V_63 , void * V_64 )
{
struct V_65 * V_66 = V_64 ;
if ( V_66 -> V_67 == ( unsigned long ) & V_41 )
F_25 ( L_6 ,
V_39 , V_66 -> V_3 , V_64 ) ;
F_48 ( V_66 -> V_3 ) ;
}
static int F_49 ( struct V_47 * V_63 , void * V_64 ,
void * V_68 )
{
struct V_65 * V_66 = V_64 ;
return ( V_66 -> V_67 == ( unsigned long ) & V_41 ) &&
! strcmp ( V_66 -> V_3 , V_68 ) ;
}
static struct V_65 * F_50 ( struct V_47 * V_63 ,
const char * V_3 )
{
struct V_65 * V_66 ;
V_66 = F_51 ( V_63 , F_47 ,
F_49 , ( void * ) V_3 ) ;
return V_66 ;
}
static int F_52 ( struct V_47 * V_63 , const char * V_3 )
{
struct V_65 * V_66 ;
V_66 = F_50 ( V_63 , V_3 ) ;
if ( V_66 )
return 1 ;
V_66 = F_53 ( F_47 , sizeof( struct V_65 ) ,
V_69 ) ;
if ( ! V_66 )
return - V_45 ;
V_66 -> V_3 = F_20 ( V_3 , V_69 ) ;
if ( ! V_66 -> V_3 ) {
F_54 ( V_66 ) ;
return - V_45 ;
}
V_66 -> V_67 = ( unsigned long ) & V_41 ;
F_55 ( V_63 , V_66 ) ;
return 0 ;
}
static int F_52 ( struct V_47 * V_63 , const char * V_3 )
{
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , struct V_47 * V_47 ,
unsigned int V_70 )
{
struct V_29 * V_4 = V_2 -> V_61 ;
F_14 ( & V_26 ) ;
if ( ! V_4 -> V_5 || F_57 ( & V_4 -> V_15 ) ) {
F_15 ( & V_26 ) ;
return - V_24 ;
}
if ( V_47 && ( V_70 & V_71 ) &&
! ( V_70 & V_72 ) )
F_52 ( V_47 , V_4 -> V_35 ) ;
if ( ! ( V_70 & V_72 ) &&
V_4 -> V_32 -> V_73 == V_74 ) {
if ( F_58 ( V_4 -> V_35 ) )
F_30 ( & V_4 -> V_36 ) ;
}
F_46 ( V_4 , V_2 ) ;
F_15 ( & V_26 ) ;
return 0 ;
}
static struct V_75 * F_59 ( struct V_47 * V_63 )
{
return F_60 ( V_63 , struct V_75 , V_63 ) ;
}
static void F_61 ( struct V_29 * V_4 )
{
if ( F_62 ( & V_4 -> V_15 ) )
return;
F_63 ( & V_4 -> V_38 ) ;
F_64 ( & V_4 -> V_15 ) ;
}
static void F_65 ( struct V_75 * V_76 )
{
struct V_29 * V_4 = V_76 -> V_4 ;
F_61 ( V_4 ) ;
}
static void F_66 ( bool V_77 )
{
struct V_29 * V_4 ;
struct V_29 * V_78 ;
F_14 ( & V_26 ) ;
F_67 (buf, next, &pending_fw_head, pending_list) {
if ( ! V_4 -> V_79 || ! V_77 )
F_61 ( V_4 ) ;
}
F_15 ( & V_26 ) ;
}
static T_3 F_68 ( struct V_80 * V_80 , struct V_81 * V_82 ,
char * V_4 )
{
return sprintf ( V_4 , L_7 , V_11 ) ;
}
static T_3 F_69 ( struct V_80 * V_80 , struct V_81 * V_82 ,
const char * V_4 , T_1 V_83 )
{
V_11 = F_70 ( V_4 , NULL , 10 ) ;
if ( V_11 < 0 )
V_11 = 0 ;
return V_83 ;
}
static void F_71 ( struct V_47 * V_63 )
{
struct V_75 * V_76 = F_59 ( V_63 ) ;
F_21 ( V_76 ) ;
}
static int F_72 ( struct V_75 * V_76 , struct V_84 * V_85 )
{
if ( F_73 ( V_85 , L_8 , V_76 -> V_4 -> V_35 ) )
return - V_45 ;
if ( F_73 ( V_85 , L_9 , V_11 ) )
return - V_45 ;
if ( F_73 ( V_85 , L_10 , V_76 -> V_86 ) )
return - V_45 ;
return 0 ;
}
static int F_74 ( struct V_47 * V_63 , struct V_84 * V_85 )
{
struct V_75 * V_76 = F_59 ( V_63 ) ;
int V_87 = 0 ;
F_14 ( & V_26 ) ;
if ( V_76 -> V_4 )
V_87 = F_72 ( V_76 , V_85 ) ;
F_15 ( & V_26 ) ;
return V_87 ;
}
static T_3 F_75 ( struct V_47 * V_63 ,
struct V_88 * V_82 , char * V_4 )
{
struct V_75 * V_76 = F_59 ( V_63 ) ;
int V_89 = 0 ;
F_14 ( & V_26 ) ;
if ( V_76 -> V_4 )
V_89 = F_76 ( & V_76 -> V_4 -> V_15 ) ;
F_15 ( & V_26 ) ;
return sprintf ( V_4 , L_7 , V_89 ) ;
}
static int F_77 ( struct V_29 * V_4 )
{
if ( ! V_4 -> V_90 )
return 0 ;
F_78 ( V_4 -> V_10 ) ;
V_4 -> V_10 = F_79 ( V_4 -> V_62 , V_4 -> V_91 , 0 , V_92 ) ;
if ( ! V_4 -> V_10 )
return - V_45 ;
return 0 ;
}
static T_3 F_80 ( struct V_47 * V_63 ,
struct V_88 * V_82 ,
const char * V_4 , T_1 V_83 )
{
struct V_75 * V_76 = F_59 ( V_63 ) ;
struct V_29 * V_93 ;
T_3 V_94 = V_83 ;
int V_89 = F_70 ( V_4 , NULL , 10 ) ;
int V_48 ;
F_14 ( & V_26 ) ;
V_93 = V_76 -> V_4 ;
if ( F_57 ( & V_93 -> V_15 ) )
goto V_95;
switch ( V_89 ) {
case 1 :
if ( ! F_62 ( & V_93 -> V_15 ) ) {
for ( V_48 = 0 ; V_48 < V_93 -> V_91 ; V_48 ++ )
F_81 ( V_93 -> V_62 [ V_48 ] ) ;
F_45 ( V_93 -> V_62 ) ;
V_93 -> V_62 = NULL ;
V_93 -> V_96 = 0 ;
V_93 -> V_91 = 0 ;
F_82 ( & V_93 -> V_15 ) ;
}
break;
case 0 :
if ( F_76 ( & V_93 -> V_15 ) ) {
int V_50 ;
V_50 = F_77 ( V_93 ) ;
if ( V_50 )
F_83 ( V_63 , L_11 ,
V_39 ) ;
else
V_50 = F_84 ( NULL ,
V_93 -> V_10 , V_93 -> V_5 ,
V_54 ) ;
F_63 ( & V_93 -> V_38 ) ;
if ( V_50 ) {
F_64 ( & V_93 -> V_15 ) ;
V_94 = V_50 ;
} else {
F_42 ( & V_93 -> V_15 ) ;
}
break;
}
default:
F_83 ( V_63 , L_12 , V_39 , V_89 ) ;
case - 1 :
F_65 ( V_76 ) ;
break;
}
V_95:
F_15 ( & V_26 ) ;
return V_94 ;
}
static void F_85 ( struct V_29 * V_4 , char * V_97 ,
T_2 V_98 , T_1 V_83 , bool V_99 )
{
if ( V_99 )
memcpy ( V_97 , V_4 -> V_10 + V_98 , V_83 ) ;
else
memcpy ( V_4 -> V_10 + V_98 , V_97 , V_83 ) ;
}
static void F_86 ( struct V_29 * V_4 , char * V_97 ,
T_2 V_98 , T_1 V_83 , bool V_99 )
{
while ( V_83 ) {
void * V_100 ;
int V_101 = V_98 >> V_102 ;
int V_103 = V_98 & ( V_104 - 1 ) ;
int V_105 = F_87 ( T_1 , V_104 - V_103 , V_83 ) ;
V_100 = F_88 ( V_4 -> V_62 [ V_101 ] ) ;
if ( V_99 )
memcpy ( V_97 , V_100 + V_103 , V_105 ) ;
else
memcpy ( V_100 + V_103 , V_97 , V_105 ) ;
F_89 ( V_4 -> V_62 [ V_101 ] ) ;
V_97 += V_105 ;
V_98 += V_105 ;
V_83 -= V_105 ;
}
}
static T_3 F_90 ( struct V_106 * V_107 , struct V_108 * V_109 ,
struct V_110 * V_111 ,
char * V_97 , T_2 V_98 , T_1 V_83 )
{
struct V_47 * V_63 = F_91 ( V_109 ) ;
struct V_75 * V_76 = F_59 ( V_63 ) ;
struct V_29 * V_4 ;
T_3 V_112 ;
F_14 ( & V_26 ) ;
V_4 = V_76 -> V_4 ;
if ( ! V_4 || F_62 ( & V_4 -> V_15 ) ) {
V_112 = - V_113 ;
goto V_95;
}
if ( V_98 > V_4 -> V_5 ) {
V_112 = 0 ;
goto V_95;
}
if ( V_83 > V_4 -> V_5 - V_98 )
V_83 = V_4 -> V_5 - V_98 ;
V_112 = V_83 ;
if ( V_4 -> V_10 )
F_85 ( V_4 , V_97 , V_98 , V_83 , true ) ;
else
F_86 ( V_4 , V_97 , V_98 , V_83 , true ) ;
V_95:
F_15 ( & V_26 ) ;
return V_112 ;
}
static int F_92 ( struct V_75 * V_76 , int V_114 )
{
struct V_29 * V_4 = V_76 -> V_4 ;
int V_115 = F_93 ( V_114 ) >> V_102 ;
if ( V_4 -> V_96 < V_115 ) {
int V_116 = F_94 ( V_115 ,
V_4 -> V_96 * 2 ) ;
struct V_117 * * V_118 ;
V_118 = F_95 ( V_116 * sizeof( void * ) ) ;
if ( ! V_118 ) {
F_65 ( V_76 ) ;
return - V_45 ;
}
memcpy ( V_118 , V_4 -> V_62 ,
V_4 -> V_96 * sizeof( void * ) ) ;
memset ( & V_118 [ V_4 -> V_96 ] , 0 , sizeof( void * ) *
( V_116 - V_4 -> V_96 ) ) ;
F_45 ( V_4 -> V_62 ) ;
V_4 -> V_62 = V_118 ;
V_4 -> V_96 = V_116 ;
}
while ( V_4 -> V_91 < V_115 ) {
V_4 -> V_62 [ V_4 -> V_91 ] =
F_96 ( V_69 | V_119 ) ;
if ( ! V_4 -> V_62 [ V_4 -> V_91 ] ) {
F_65 ( V_76 ) ;
return - V_45 ;
}
V_4 -> V_91 ++ ;
}
return 0 ;
}
static T_3 F_97 ( struct V_106 * V_107 , struct V_108 * V_109 ,
struct V_110 * V_111 ,
char * V_97 , T_2 V_98 , T_1 V_83 )
{
struct V_47 * V_63 = F_91 ( V_109 ) ;
struct V_75 * V_76 = F_59 ( V_63 ) ;
struct V_29 * V_4 ;
T_3 V_120 ;
if ( ! F_98 ( V_121 ) )
return - V_122 ;
F_14 ( & V_26 ) ;
V_4 = V_76 -> V_4 ;
if ( ! V_4 || F_62 ( & V_4 -> V_15 ) ) {
V_120 = - V_113 ;
goto V_95;
}
if ( V_4 -> V_10 ) {
if ( V_98 + V_83 > V_4 -> V_37 ) {
V_120 = - V_45 ;
goto V_95;
}
F_85 ( V_4 , V_97 , V_98 , V_83 , false ) ;
V_120 = V_83 ;
} else {
V_120 = F_92 ( V_76 , V_98 + V_83 ) ;
if ( V_120 )
goto V_95;
V_120 = V_83 ;
F_86 ( V_4 , V_97 , V_98 , V_83 , false ) ;
}
V_4 -> V_5 = F_99 ( T_1 , V_98 + V_83 , V_4 -> V_5 ) ;
V_95:
F_15 ( & V_26 ) ;
return V_120 ;
}
static struct V_75 *
F_100 ( struct V_1 * V_1 , const char * V_30 ,
struct V_47 * V_47 , unsigned int V_70 )
{
struct V_75 * V_76 ;
struct V_47 * V_123 ;
V_76 = F_19 ( sizeof( * V_76 ) , V_69 ) ;
if ( ! V_76 ) {
V_76 = F_101 ( - V_45 ) ;
goto exit;
}
V_76 -> V_86 = ! ! ( V_70 & V_124 ) ;
V_76 -> V_2 = V_1 ;
V_123 = & V_76 -> V_63 ;
F_102 ( V_123 ) ;
F_103 ( V_123 , L_13 , V_30 ) ;
V_123 -> V_125 = V_47 ;
V_123 -> V_80 = & V_126 ;
V_123 -> V_127 = V_128 ;
exit:
return V_76 ;
}
static int F_104 ( struct V_75 * V_76 ,
unsigned int V_70 , long V_22 )
{
int V_120 = 0 ;
struct V_47 * V_123 = & V_76 -> V_63 ;
struct V_29 * V_4 = V_76 -> V_4 ;
if ( ! V_4 -> V_10 )
V_4 -> V_90 = true ;
F_105 ( V_123 , true ) ;
V_120 = F_106 ( V_123 ) ;
if ( V_120 ) {
F_83 ( V_123 , L_14 , V_39 ) ;
goto V_129;
}
F_14 ( & V_26 ) ;
F_32 ( & V_4 -> V_38 , & V_130 ) ;
F_15 ( & V_26 ) ;
if ( V_70 & V_71 ) {
V_4 -> V_79 = true ;
F_105 ( V_123 , false ) ;
F_40 ( V_123 , L_15 , V_4 -> V_35 ) ;
F_107 ( & V_76 -> V_63 . V_109 , V_131 ) ;
} else {
V_22 = V_13 ;
}
V_120 = F_108 ( & V_4 -> V_15 , V_22 ) ;
if ( V_120 < 0 ) {
F_14 ( & V_26 ) ;
F_65 ( V_76 ) ;
F_15 ( & V_26 ) ;
}
if ( F_57 ( & V_4 -> V_15 ) )
V_120 = - V_132 ;
else if ( V_4 -> V_90 && ! V_4 -> V_10 )
V_120 = - V_45 ;
F_109 ( V_123 ) ;
V_129:
F_110 ( V_123 ) ;
return V_120 ;
}
static int F_111 ( struct V_1 * V_1 ,
const char * V_3 , struct V_47 * V_47 ,
unsigned int V_70 )
{
struct V_75 * V_76 ;
long V_22 ;
int V_23 ;
V_22 = F_3 () ;
if ( V_70 & V_124 ) {
V_22 = F_112 ( V_22 ) ;
if ( ! V_22 ) {
F_40 ( V_47 , L_16 ,
V_3 ) ;
return - V_133 ;
}
} else {
V_23 = F_113 () ;
if ( F_114 ( V_23 ) ) {
F_83 ( V_47 , L_17 ,
V_3 ) ;
return V_23 ;
}
}
V_76 = F_100 ( V_1 , V_3 , V_47 , V_70 ) ;
if ( F_115 ( V_76 ) ) {
V_23 = F_116 ( V_76 ) ;
goto V_134;
}
V_76 -> V_4 = V_1 -> V_61 ;
V_23 = F_104 ( V_76 , V_70 , V_22 ) ;
if ( ! V_23 )
V_23 = F_56 ( V_1 , V_47 , V_70 ) ;
V_134:
F_117 () ;
return V_23 ;
}
static inline int
F_111 ( struct V_1 * V_1 , const char * V_3 ,
struct V_47 * V_47 , unsigned int V_70 )
{
return - V_24 ;
}
static inline void F_66 ( bool V_77 ) { }
static int
F_118 ( struct V_1 * * V_135 , const char * V_3 ,
struct V_47 * V_47 , void * V_33 , T_1 V_5 )
{
struct V_1 * V_1 ;
struct V_29 * V_4 ;
int V_23 ;
* V_135 = V_1 = F_19 ( sizeof( * V_1 ) , V_69 ) ;
if ( ! V_1 ) {
F_83 ( V_47 , L_18 ,
V_39 ) ;
return - V_45 ;
}
if ( F_1 ( V_1 , V_3 , V_33 , V_5 ) ) {
F_40 ( V_47 , L_19 , V_3 ) ;
return 0 ;
}
V_23 = F_28 ( V_3 , & V_41 , & V_4 , V_33 , V_5 ) ;
V_1 -> V_61 = V_4 ;
if ( V_23 > 0 ) {
V_23 = F_119 ( & V_4 -> V_15 ) ;
if ( ! V_23 ) {
F_46 ( V_4 , V_1 ) ;
return 0 ;
}
}
if ( V_23 < 0 )
return V_23 ;
return 1 ;
}
static void F_120 ( struct V_1 * V_2 )
{
struct V_29 * V_4 ;
if ( ! V_2 || ! V_2 -> V_61 )
return;
V_4 = V_2 -> V_61 ;
if ( ! F_57 ( & V_4 -> V_15 ) )
F_64 ( & V_4 -> V_15 ) ;
}
static int
F_121 ( const struct V_1 * * V_135 , const char * V_3 ,
struct V_47 * V_47 , void * V_4 , T_1 V_5 ,
unsigned int V_70 )
{
struct V_1 * V_2 = NULL ;
int V_23 ;
if ( ! V_135 )
return - V_136 ;
if ( ! V_3 || V_3 [ 0 ] == '\0' ) {
V_23 = - V_136 ;
goto V_95;
}
V_23 = F_118 ( & V_2 , V_3 , V_47 , V_4 , V_5 ) ;
if ( V_23 <= 0 )
goto V_95;
if ( ! F_17 () ) {
F_122 ( 1 , L_20 ) ;
V_23 = - V_137 ;
goto V_95;
}
V_23 = F_36 ( V_47 , V_2 -> V_61 ) ;
if ( V_23 ) {
if ( ! ( V_70 & V_138 ) )
F_41 ( V_47 ,
L_21 ,
V_3 , V_23 ) ;
if ( V_70 & V_139 ) {
F_41 ( V_47 , L_22 ) ;
V_23 = F_111 ( V_2 , V_3 , V_47 ,
V_70 ) ;
}
} else
V_23 = F_56 ( V_2 , V_47 , V_70 ) ;
V_95:
if ( V_23 < 0 ) {
F_120 ( V_2 ) ;
F_123 ( V_2 ) ;
V_2 = NULL ;
}
* V_135 = V_2 ;
return V_23 ;
}
int
F_124 ( const struct V_1 * * V_135 , const char * V_3 ,
struct V_47 * V_47 )
{
int V_23 ;
F_125 ( V_140 ) ;
V_23 = F_121 ( V_135 , V_3 , V_47 , NULL , 0 ,
V_71 | V_141 ) ;
F_126 ( V_140 ) ;
return V_23 ;
}
int F_127 ( const struct V_1 * * V_135 ,
const char * V_3 , struct V_47 * V_47 )
{
int V_23 ;
F_125 ( V_140 ) ;
V_23 = F_121 ( V_135 , V_3 , V_47 , NULL , 0 ,
V_71 | V_138 ) ;
F_126 ( V_140 ) ;
return V_23 ;
}
int
F_128 ( const struct V_1 * * V_135 , const char * V_3 ,
struct V_47 * V_47 , void * V_4 , T_1 V_5 )
{
int V_23 ;
F_125 ( V_140 ) ;
V_23 = F_121 ( V_135 , V_3 , V_47 , V_4 , V_5 ,
V_71 | V_141 |
V_72 ) ;
F_126 ( V_140 ) ;
return V_23 ;
}
void F_123 ( const struct V_1 * V_2 )
{
if ( V_2 ) {
if ( ! F_2 ( V_2 ) )
F_44 ( V_2 ) ;
F_21 ( V_2 ) ;
}
}
static void F_129 ( struct V_142 * V_143 )
{
struct V_144 * V_145 ;
const struct V_1 * V_2 ;
V_145 = F_60 ( V_143 , struct V_144 , V_143 ) ;
F_121 ( & V_2 , V_145 -> V_3 , V_145 -> V_47 , NULL , 0 ,
V_145 -> V_70 ) ;
V_145 -> V_146 ( V_2 , V_145 -> V_147 ) ;
F_110 ( V_145 -> V_47 ) ;
F_126 ( V_145 -> V_148 ) ;
F_48 ( V_145 -> V_3 ) ;
F_21 ( V_145 ) ;
}
int
F_130 (
struct V_148 * V_148 , bool V_149 ,
const char * V_3 , struct V_47 * V_47 , T_4 V_150 , void * V_147 ,
void (* V_146)( const struct V_1 * V_2 , void * V_147 ) )
{
struct V_144 * V_145 ;
V_145 = F_19 ( sizeof( struct V_144 ) , V_150 ) ;
if ( ! V_145 )
return - V_45 ;
V_145 -> V_148 = V_148 ;
V_145 -> V_3 = F_20 ( V_3 , V_150 ) ;
if ( ! V_145 -> V_3 ) {
F_21 ( V_145 ) ;
return - V_45 ;
}
V_145 -> V_47 = V_47 ;
V_145 -> V_147 = V_147 ;
V_145 -> V_146 = V_146 ;
V_145 -> V_70 = V_124 | V_141 |
( V_149 ? V_71 : V_139 ) ;
if ( ! F_131 ( V_148 ) ) {
F_48 ( V_145 -> V_3 ) ;
F_21 ( V_145 ) ;
return - V_151 ;
}
F_132 ( V_145 -> V_47 ) ;
F_133 ( & V_145 -> V_143 , F_129 ) ;
F_134 ( & V_145 -> V_143 ) ;
return 0 ;
}
static int F_135 ( const char * V_30 )
{
int V_23 ;
const struct V_1 * V_2 ;
F_25 ( L_23 , V_39 , V_30 ) ;
V_23 = F_124 ( & V_2 , V_30 , NULL ) ;
if ( ! V_23 )
F_21 ( V_2 ) ;
F_25 ( L_24 , V_39 , V_30 , V_23 ) ;
return V_23 ;
}
static struct V_29 * F_136 ( const char * V_30 )
{
struct V_29 * V_40 ;
struct V_31 * V_32 = & V_41 ;
F_29 ( & V_32 -> V_42 ) ;
V_40 = F_26 ( V_30 ) ;
F_31 ( & V_32 -> V_42 ) ;
return V_40 ;
}
static int F_137 ( const char * V_30 )
{
struct V_29 * V_4 ;
struct V_1 V_2 ;
F_25 ( L_23 , V_39 , V_30 ) ;
if ( F_1 ( & V_2 , V_30 , NULL , 0 ) )
return 0 ;
V_4 = F_136 ( V_30 ) ;
if ( V_4 ) {
F_34 ( V_4 ) ;
return 0 ;
}
return - V_136 ;
}
static struct V_152 * F_138 ( const char * V_3 )
{
struct V_152 * V_153 ;
V_153 = F_19 ( sizeof( * V_153 ) , V_34 ) ;
if ( ! V_153 )
goto exit;
V_153 -> V_3 = F_20 ( V_3 , V_34 ) ;
if ( ! V_153 -> V_3 ) {
F_21 ( V_153 ) ;
V_153 = NULL ;
goto exit;
}
exit:
return V_153 ;
}
static int F_139 ( const char * V_3 )
{
struct V_31 * V_32 = & V_41 ;
struct V_152 * V_153 ;
F_27 (fce, &fwc->fw_names, list) {
if ( ! strcmp ( V_153 -> V_3 , V_3 ) )
return 1 ;
}
return 0 ;
}
static int F_58 ( const char * V_3 )
{
struct V_31 * V_32 = & V_41 ;
struct V_152 * V_153 ;
int V_23 = 0 ;
F_29 ( & V_32 -> V_154 ) ;
if ( F_139 ( V_3 ) )
goto V_155;
V_153 = F_138 ( V_3 ) ;
if ( V_153 ) {
V_23 = 1 ;
F_32 ( & V_153 -> V_43 , & V_32 -> V_156 ) ;
F_25 ( L_25 , V_39 , V_3 ) ;
}
V_155:
F_31 ( & V_32 -> V_154 ) ;
return V_23 ;
}
static void F_140 ( struct V_152 * V_153 )
{
F_48 ( V_153 -> V_3 ) ;
F_21 ( V_153 ) ;
}
static void F_141 ( void * V_157 ,
T_5 V_158 )
{
struct V_152 * V_153 = V_157 ;
struct V_31 * V_32 = & V_41 ;
int V_23 ;
V_23 = F_135 ( V_153 -> V_3 ) ;
if ( V_23 ) {
F_29 ( & V_32 -> V_154 ) ;
F_142 ( & V_153 -> V_43 ) ;
F_31 ( & V_32 -> V_154 ) ;
F_140 ( V_153 ) ;
}
}
static void F_143 ( struct V_47 * V_63 , void * V_64 ,
void * V_10 )
{
struct V_65 * V_66 = V_64 ;
const char * V_30 = V_66 -> V_3 ;
struct V_159 * V_44 = V_10 ;
struct V_152 * V_153 ;
V_153 = F_138 ( V_30 ) ;
if ( V_153 )
F_32 ( & V_153 -> V_43 , V_44 ) ;
}
static int F_144 ( struct V_47 * V_63 , void * V_64 ,
void * V_68 )
{
struct V_65 * V_66 = V_64 ;
return ( V_66 -> V_67 == ( unsigned long ) V_68 ) ;
}
static void F_145 ( struct V_47 * V_63 , void * V_10 )
{
F_146 ( V_160 ) ;
struct V_152 * V_153 ;
struct V_152 * V_161 ;
struct V_31 * V_32 = & V_41 ;
F_147 ( V_63 , F_47 ,
F_144 , & V_41 ,
F_143 , & V_160 ) ;
F_67 (fce, fce_next, &todo, list) {
F_142 ( & V_153 -> V_43 ) ;
F_29 ( & V_32 -> V_154 ) ;
if ( ! F_139 ( V_153 -> V_3 ) ) {
F_32 ( & V_153 -> V_43 , & V_32 -> V_156 ) ;
} else {
F_140 ( V_153 ) ;
V_153 = NULL ;
}
F_31 ( & V_32 -> V_154 ) ;
if ( V_153 )
F_148 ( F_141 ,
( void * ) V_153 ,
& V_162 ) ;
}
}
static void F_149 ( void )
{
struct V_31 * V_32 = & V_41 ;
struct V_152 * V_153 ;
F_29 ( & V_32 -> V_154 ) ;
while ( ! F_150 ( & V_32 -> V_156 ) ) {
V_153 = F_151 ( V_32 -> V_156 . V_78 ,
struct V_152 , V_43 ) ;
F_142 ( & V_153 -> V_43 ) ;
F_31 ( & V_32 -> V_154 ) ;
F_137 ( V_153 -> V_3 ) ;
F_140 ( V_153 ) ;
F_29 ( & V_32 -> V_154 ) ;
}
F_31 ( & V_32 -> V_154 ) ;
}
static void F_152 ( void )
{
struct V_31 * V_32 = & V_41 ;
int V_163 ;
F_153 ( V_164 ) ;
F_25 ( L_26 , V_39 ) ;
F_154 ( & V_32 -> V_143 ) ;
V_163 = V_11 ;
V_11 = 10 ;
F_14 ( & V_26 ) ;
V_32 -> V_73 = V_74 ;
F_155 ( NULL , F_145 ) ;
F_15 ( & V_26 ) ;
F_156 ( & V_162 ) ;
V_11 = V_163 ;
}
static void F_157 ( void )
{
F_25 ( L_26 , V_39 ) ;
F_149 () ;
}
static void F_158 ( struct V_142 * V_143 )
{
F_157 () ;
}
static void F_159 ( unsigned long V_165 )
{
F_160 ( V_166 , & V_41 . V_143 ,
F_161 ( V_165 ) ) ;
}
static int F_162 ( struct V_167 * V_168 ,
unsigned long V_169 , void * V_170 )
{
switch ( V_169 ) {
case V_171 :
case V_172 :
case V_173 :
F_66 ( true ) ;
F_152 () ;
F_16 () ;
break;
case V_174 :
case V_175 :
case V_176 :
F_14 ( & V_26 ) ;
V_41 . V_73 = V_177 ;
F_15 ( & V_26 ) ;
F_13 () ;
F_159 ( 10 * V_178 ) ;
break;
}
return 0 ;
}
static int F_163 ( void )
{
V_41 . V_73 = V_177 ;
return 0 ;
}
static int F_58 ( const char * V_3 )
{
return 0 ;
}
static void T_6 F_164 ( void )
{
F_165 ( & V_41 . V_42 ) ;
F_24 ( & V_41 . V_44 ) ;
V_41 . V_73 = V_177 ;
#ifdef F_166
F_165 ( & V_41 . V_154 ) ;
F_24 ( & V_41 . V_156 ) ;
F_167 ( & V_41 . V_143 ,
F_158 ) ;
V_41 . V_179 . V_180 = F_162 ;
F_168 ( & V_41 . V_179 ) ;
F_169 ( & V_181 ) ;
#endif
}
static int F_170 ( struct V_167 * V_182 ,
unsigned long V_183 , void * V_184 )
{
F_16 () ;
F_66 ( false ) ;
return V_185 ;
}
static int T_6 F_171 ( void )
{
F_13 () ;
F_164 () ;
F_172 ( & V_186 ) ;
#ifdef F_23
return F_173 ( & V_126 ) ;
#else
return 0 ;
#endif
}
static void T_7 F_174 ( void )
{
F_16 () ;
#ifdef F_166
F_175 ( & V_181 ) ;
F_176 ( & V_41 . V_179 ) ;
#endif
F_177 ( & V_186 ) ;
#ifdef F_23
F_178 ( & V_126 ) ;
#endif
}
