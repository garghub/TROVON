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
{
struct V_13 * V_17 = F_19 ( V_19 ) ;
struct V_15 * V_16 = V_17 -> V_16 ;
F_10 ( L_2 ,
V_23 , V_17 -> V_20 , V_17 , V_17 -> V_9 ,
( unsigned int ) V_17 -> V_8 ) ;
F_20 ( & V_17 -> V_27 ) ;
F_16 ( & V_16 -> V_26 ) ;
#ifdef F_8
if ( V_17 -> V_31 ) {
int V_32 ;
F_21 ( V_17 -> V_9 ) ;
for ( V_32 = 0 ; V_32 < V_17 -> V_33 ; V_32 ++ )
F_22 ( V_17 -> V_34 [ V_32 ] ) ;
F_23 ( V_17 -> V_34 ) ;
} else
#endif
F_24 ( V_17 -> V_9 ) ;
F_23 ( V_17 ) ;
}
static void F_25 ( struct V_13 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_16 ;
F_14 ( & V_16 -> V_26 ) ;
if ( ! F_26 ( & V_17 -> V_19 , F_18 ) )
F_16 ( & V_16 -> V_26 ) ;
}
static T_1 long F_27 ( struct V_35 * V_35 )
{
struct V_36 V_37 ;
if ( F_28 ( & V_35 -> V_38 , & V_37 ) )
return - 1 ;
if ( ! F_29 ( V_37 . V_39 ) )
return - 1 ;
if ( V_37 . V_8 != ( long ) V_37 . V_8 )
return - 1 ;
return V_37 . V_8 ;
}
static int F_30 ( struct V_35 * V_35 , struct V_13 * V_40 )
{
long V_8 ;
char * V_17 ;
int V_41 ;
V_8 = F_27 ( V_35 ) ;
if ( V_8 <= 0 )
return - V_42 ;
V_17 = F_31 ( V_8 ) ;
if ( ! V_17 )
return - V_29 ;
V_41 = F_32 ( V_35 , 0 , V_17 , V_8 ) ;
if ( V_41 != V_8 ) {
if ( V_41 > 0 )
V_41 = - V_43 ;
F_24 ( V_17 ) ;
return V_41 ;
}
V_40 -> V_9 = V_17 ;
V_40 -> V_8 = V_8 ;
return 0 ;
}
static int F_33 ( struct V_44 * V_44 ,
struct V_13 * V_17 )
{
int V_32 ;
int V_41 = - V_45 ;
char * V_46 = F_34 () ;
for ( V_32 = 0 ; V_32 < F_35 ( V_47 ) ; V_32 ++ ) {
struct V_35 * V_35 ;
if ( ! V_47 [ V_32 ] [ 0 ] )
continue;
snprintf ( V_46 , V_48 , L_3 , V_47 [ V_32 ] , V_17 -> V_20 ) ;
V_35 = F_36 ( V_46 , V_49 , 0 ) ;
if ( F_37 ( V_35 ) )
continue;
V_41 = F_30 ( V_35 , V_17 ) ;
F_38 ( V_35 ) ;
if ( V_41 )
F_39 ( V_44 , L_4 ,
V_46 , V_41 ) ;
else
break;
}
F_40 ( V_46 ) ;
if ( ! V_41 ) {
F_41 ( V_44 , L_5 ,
V_17 -> V_20 ) ;
F_42 ( & V_50 ) ;
F_43 ( V_51 , & V_17 -> V_52 ) ;
F_44 ( & V_17 -> V_21 ) ;
F_45 ( & V_50 ) ;
}
return V_41 ;
}
static void F_46 ( const struct V_1 * V_2 )
{
if ( ! V_2 -> V_53 ) {
F_24 ( V_2 -> V_9 ) ;
return;
}
F_25 ( V_2 -> V_53 ) ;
}
static void F_47 ( struct V_13 * V_17 , struct V_1 * V_2 )
{
V_2 -> V_53 = V_17 ;
#ifdef F_8
V_2 -> V_34 = V_17 -> V_34 ;
#endif
V_2 -> V_8 = V_17 -> V_8 ;
V_2 -> V_9 = V_17 -> V_9 ;
F_10 ( L_2 ,
V_23 , V_17 -> V_20 , V_17 , V_17 -> V_9 ,
( unsigned int ) V_17 -> V_8 ) ;
}
static void F_48 ( struct V_44 * V_54 , void * V_55 )
{
struct V_56 * V_57 = V_55 ;
if ( V_57 -> V_58 == ( unsigned long ) & V_25 )
F_10 ( L_6 ,
V_23 , V_57 -> V_3 , V_55 ) ;
}
static int F_49 ( struct V_44 * V_54 , void * V_55 ,
void * V_59 )
{
struct V_56 * V_57 = V_55 ;
return ( V_57 -> V_58 == ( unsigned long ) & V_25 ) &&
! strcmp ( V_57 -> V_3 , V_59 ) ;
}
static struct V_56 * F_50 ( struct V_44 * V_54 ,
const char * V_3 )
{
struct V_56 * V_57 ;
V_57 = F_51 ( V_54 , F_48 ,
F_49 , ( void * ) V_3 ) ;
return V_57 ;
}
static int F_52 ( struct V_44 * V_54 , const char * V_3 )
{
struct V_56 * V_57 ;
V_57 = F_50 ( V_54 , V_3 ) ;
if ( V_57 )
return 1 ;
V_57 = F_53 ( F_48 , sizeof( struct V_56 ) +
strlen ( V_3 ) + 1 , V_60 ) ;
if ( ! V_57 )
return - V_29 ;
V_57 -> V_58 = ( unsigned long ) & V_25 ;
strcpy ( V_57 -> V_3 , V_3 ) ;
F_54 ( V_54 , V_57 ) ;
return 0 ;
}
static int F_52 ( struct V_44 * V_54 , const char * V_3 )
{
return 0 ;
}
static struct V_61 * F_55 ( struct V_44 * V_54 )
{
return F_56 ( V_54 , struct V_61 , V_54 ) ;
}
static void F_57 ( struct V_13 * V_17 )
{
if ( F_58 ( V_51 , & V_17 -> V_52 ) )
return;
F_59 ( & V_17 -> V_22 ) ;
F_43 ( V_62 , & V_17 -> V_52 ) ;
F_44 ( & V_17 -> V_21 ) ;
}
static void F_60 ( struct V_61 * V_63 )
{
struct V_13 * V_17 = V_63 -> V_17 ;
F_57 ( V_17 ) ;
V_63 -> V_17 = NULL ;
}
static int F_61 ( struct V_64 * V_65 ,
unsigned long V_66 , void * V_67 )
{
F_42 ( & V_50 ) ;
while ( ! F_62 ( & V_68 ) )
F_57 ( F_63 ( & V_68 ,
struct V_13 ,
V_22 ) ) ;
F_45 ( & V_50 ) ;
return V_69 ;
}
static T_2 F_64 ( struct V_70 * V_70 , struct V_71 * V_72 ,
char * V_17 )
{
return sprintf ( V_17 , L_7 , V_10 ) ;
}
static T_2 F_65 ( struct V_70 * V_70 , struct V_71 * V_72 ,
const char * V_17 , T_3 V_73 )
{
V_10 = F_66 ( V_17 , NULL , 10 ) ;
if ( V_10 < 0 )
V_10 = 0 ;
return V_73 ;
}
static void F_67 ( struct V_44 * V_54 )
{
struct V_61 * V_63 = F_55 ( V_54 ) ;
F_23 ( V_63 ) ;
}
static int F_68 ( struct V_44 * V_54 , struct V_74 * V_75 )
{
struct V_61 * V_63 = F_55 ( V_54 ) ;
if ( F_69 ( V_75 , L_8 , V_63 -> V_17 -> V_20 ) )
return - V_29 ;
if ( F_69 ( V_75 , L_9 , V_10 ) )
return - V_29 ;
if ( F_69 ( V_75 , L_10 , V_63 -> V_76 ) )
return - V_29 ;
return 0 ;
}
static T_2 F_70 ( struct V_44 * V_54 ,
struct V_77 * V_72 , char * V_17 )
{
struct V_61 * V_63 = F_55 ( V_54 ) ;
int V_78 = 0 ;
F_42 ( & V_50 ) ;
if ( V_63 -> V_17 )
V_78 = F_58 ( V_79 , & V_63 -> V_17 -> V_52 ) ;
F_45 ( & V_50 ) ;
return sprintf ( V_17 , L_7 , V_78 ) ;
}
static int F_71 ( struct V_13 * V_17 )
{
if ( ! V_17 -> V_31 )
return 0 ;
if ( V_17 -> V_9 )
F_21 ( V_17 -> V_9 ) ;
V_17 -> V_9 = F_72 ( V_17 -> V_34 , V_17 -> V_33 , 0 , V_80 ) ;
if ( ! V_17 -> V_9 )
return - V_29 ;
return 0 ;
}
static T_2 F_73 ( struct V_44 * V_54 ,
struct V_77 * V_72 ,
const char * V_17 , T_3 V_73 )
{
struct V_61 * V_63 = F_55 ( V_54 ) ;
struct V_13 * V_40 ;
int V_78 = F_66 ( V_17 , NULL , 10 ) ;
int V_32 ;
F_42 ( & V_50 ) ;
V_40 = V_63 -> V_17 ;
if ( ! V_40 )
goto V_81;
switch ( V_78 ) {
case 1 :
if ( ! F_58 ( V_51 , & V_40 -> V_52 ) ) {
for ( V_32 = 0 ; V_32 < V_40 -> V_33 ; V_32 ++ )
F_22 ( V_40 -> V_34 [ V_32 ] ) ;
F_23 ( V_40 -> V_34 ) ;
V_40 -> V_34 = NULL ;
V_40 -> V_82 = 0 ;
V_40 -> V_33 = 0 ;
F_43 ( V_79 , & V_40 -> V_52 ) ;
}
break;
case 0 :
if ( F_58 ( V_79 , & V_40 -> V_52 ) ) {
F_43 ( V_51 , & V_40 -> V_52 ) ;
F_74 ( V_79 , & V_40 -> V_52 ) ;
F_71 ( V_40 ) ;
F_59 ( & V_40 -> V_22 ) ;
F_44 ( & V_40 -> V_21 ) ;
break;
}
default:
F_75 ( V_54 , L_11 , V_23 , V_78 ) ;
case - 1 :
F_60 ( V_63 ) ;
break;
}
V_81:
F_45 ( & V_50 ) ;
return V_73 ;
}
static T_2 F_76 ( struct V_35 * V_83 , struct V_84 * V_85 ,
struct V_86 * V_87 ,
char * V_88 , T_4 V_89 , T_3 V_73 )
{
struct V_44 * V_54 = F_77 ( V_85 ) ;
struct V_61 * V_63 = F_55 ( V_54 ) ;
struct V_13 * V_17 ;
T_2 V_90 ;
F_42 ( & V_50 ) ;
V_17 = V_63 -> V_17 ;
if ( ! V_17 || F_58 ( V_51 , & V_17 -> V_52 ) ) {
V_90 = - V_91 ;
goto V_81;
}
if ( V_89 > V_17 -> V_8 ) {
V_90 = 0 ;
goto V_81;
}
if ( V_73 > V_17 -> V_8 - V_89 )
V_73 = V_17 -> V_8 - V_89 ;
V_90 = V_73 ;
while ( V_73 ) {
void * V_92 ;
int V_93 = V_89 >> V_94 ;
int V_95 = V_89 & ( V_96 - 1 ) ;
int V_97 = F_78 ( T_3 , V_96 - V_95 , V_73 ) ;
V_92 = F_79 ( V_17 -> V_34 [ V_93 ] ) ;
memcpy ( V_88 , V_92 + V_95 , V_97 ) ;
F_80 ( V_17 -> V_34 [ V_93 ] ) ;
V_88 += V_97 ;
V_89 += V_97 ;
V_73 -= V_97 ;
}
V_81:
F_45 ( & V_50 ) ;
return V_90 ;
}
static int F_81 ( struct V_61 * V_63 , int V_98 )
{
struct V_13 * V_17 = V_63 -> V_17 ;
int V_99 = F_82 ( V_98 , V_96 ) >> V_94 ;
if ( V_17 -> V_82 < V_99 ) {
int V_100 = F_83 ( V_99 ,
V_17 -> V_82 * 2 ) ;
struct V_101 * * V_102 ;
V_102 = F_84 ( V_100 * sizeof( void * ) ,
V_60 ) ;
if ( ! V_102 ) {
F_60 ( V_63 ) ;
return - V_29 ;
}
memcpy ( V_102 , V_17 -> V_34 ,
V_17 -> V_82 * sizeof( void * ) ) ;
memset ( & V_102 [ V_17 -> V_82 ] , 0 , sizeof( void * ) *
( V_100 - V_17 -> V_82 ) ) ;
F_23 ( V_17 -> V_34 ) ;
V_17 -> V_34 = V_102 ;
V_17 -> V_82 = V_100 ;
}
while ( V_17 -> V_33 < V_99 ) {
V_17 -> V_34 [ V_17 -> V_33 ] =
F_85 ( V_60 | V_103 ) ;
if ( ! V_17 -> V_34 [ V_17 -> V_33 ] ) {
F_60 ( V_63 ) ;
return - V_29 ;
}
V_17 -> V_33 ++ ;
}
return 0 ;
}
static T_2 F_86 ( struct V_35 * V_83 , struct V_84 * V_85 ,
struct V_86 * V_87 ,
char * V_88 , T_4 V_89 , T_3 V_73 )
{
struct V_44 * V_54 = F_77 ( V_85 ) ;
struct V_61 * V_63 = F_55 ( V_54 ) ;
struct V_13 * V_17 ;
T_2 V_104 ;
if ( ! F_87 ( V_105 ) )
return - V_106 ;
F_42 ( & V_50 ) ;
V_17 = V_63 -> V_17 ;
if ( ! V_17 || F_58 ( V_51 , & V_17 -> V_52 ) ) {
V_104 = - V_91 ;
goto V_81;
}
V_104 = F_81 ( V_63 , V_89 + V_73 ) ;
if ( V_104 )
goto V_81;
V_104 = V_73 ;
while ( V_73 ) {
void * V_92 ;
int V_93 = V_89 >> V_94 ;
int V_95 = V_89 & ( V_96 - 1 ) ;
int V_97 = F_78 ( T_3 , V_96 - V_95 , V_73 ) ;
V_92 = F_79 ( V_17 -> V_34 [ V_93 ] ) ;
memcpy ( V_92 + V_95 , V_88 , V_97 ) ;
F_80 ( V_17 -> V_34 [ V_93 ] ) ;
V_88 += V_97 ;
V_89 += V_97 ;
V_73 -= V_97 ;
}
V_17 -> V_8 = F_88 ( T_3 , V_89 , V_17 -> V_8 ) ;
V_81:
F_45 ( & V_50 ) ;
return V_104 ;
}
static void F_89 ( struct V_107 * V_108 )
{
struct V_61 * V_63 = F_56 ( V_108 ,
struct V_61 , V_109 . V_108 ) ;
F_42 ( & V_50 ) ;
F_60 ( V_63 ) ;
F_45 ( & V_50 ) ;
}
static struct V_61 *
F_90 ( struct V_1 * V_1 , const char * V_14 ,
struct V_44 * V_44 , bool V_110 , bool V_76 )
{
struct V_61 * V_63 ;
struct V_44 * V_111 ;
V_63 = F_5 ( sizeof( * V_63 ) , V_60 ) ;
if ( ! V_63 ) {
F_75 ( V_44 , L_12 , V_23 ) ;
V_63 = F_91 ( - V_29 ) ;
goto exit;
}
V_63 -> V_76 = V_76 ;
V_63 -> V_2 = V_1 ;
F_92 ( & V_63 -> V_109 ,
F_89 ) ;
V_111 = & V_63 -> V_54 ;
F_93 ( V_111 ) ;
F_94 ( V_111 , L_13 , V_14 ) ;
V_111 -> V_112 = V_44 ;
V_111 -> V_70 = & V_113 ;
exit:
return V_63 ;
}
static int F_95 ( struct V_61 * V_63 , bool V_110 ,
long V_114 )
{
int V_104 = 0 ;
struct V_44 * V_111 = & V_63 -> V_54 ;
struct V_13 * V_17 = V_63 -> V_17 ;
V_17 -> V_31 = true ;
F_96 ( V_111 , true ) ;
V_104 = F_97 ( V_111 ) ;
if ( V_104 ) {
F_75 ( V_111 , L_14 , V_23 ) ;
goto V_115;
}
V_104 = F_98 ( V_111 , & V_116 ) ;
if ( V_104 ) {
F_75 ( V_111 , L_15 , V_23 ) ;
goto V_117;
}
F_42 ( & V_50 ) ;
F_17 ( & V_17 -> V_22 , & V_68 ) ;
F_45 ( & V_50 ) ;
V_104 = F_99 ( V_111 , & V_118 ) ;
if ( V_104 ) {
F_42 ( & V_50 ) ;
F_59 ( & V_17 -> V_22 ) ;
F_45 ( & V_50 ) ;
F_75 ( V_111 , L_16 , V_23 ) ;
goto V_119;
}
if ( V_110 ) {
V_17 -> V_120 = true ;
F_96 ( V_111 , false ) ;
F_41 ( V_111 , L_17 , V_17 -> V_20 ) ;
if ( V_114 != V_12 )
F_100 ( & V_63 -> V_109 , V_114 ) ;
F_101 ( & V_63 -> V_54 . V_85 , V_121 ) ;
}
F_102 ( & V_17 -> V_21 ) ;
F_103 ( & V_63 -> V_109 ) ;
F_104 ( V_111 , & V_118 ) ;
V_119:
F_105 ( V_111 , & V_116 ) ;
V_117:
F_106 ( V_111 ) ;
V_115:
F_107 ( V_111 ) ;
return V_104 ;
}
static int F_108 ( struct V_1 * V_1 ,
const char * V_3 , struct V_44 * V_44 ,
bool V_110 , bool V_76 , long V_114 )
{
struct V_61 * V_63 ;
V_63 = F_90 ( V_1 , V_3 , V_44 , V_110 , V_76 ) ;
if ( F_37 ( V_63 ) )
return F_109 ( V_63 ) ;
V_63 -> V_17 = V_1 -> V_53 ;
return F_95 ( V_63 , V_110 , V_114 ) ;
}
static void F_110 ( void )
{
struct V_13 * V_17 ;
struct V_13 * V_122 ;
F_42 ( & V_50 ) ;
F_111 (buf, next, &pending_fw_head, pending_list) {
if ( ! V_17 -> V_120 )
F_57 ( V_17 ) ;
}
F_45 ( & V_50 ) ;
}
static inline int
F_108 ( struct V_1 * V_1 , const char * V_3 ,
struct V_44 * V_44 , bool V_110 , bool V_76 ,
long V_114 )
{
return - V_45 ;
}
static inline void F_110 ( void ) { }
static int F_112 ( struct V_13 * V_17 )
{
int V_123 = 0 ;
F_42 ( & V_50 ) ;
while ( ! F_58 ( V_51 , & V_17 -> V_52 ) ) {
if ( F_113 ( V_17 ) ) {
V_123 = - V_45 ;
break;
}
F_45 ( & V_50 ) ;
F_102 ( & V_17 -> V_21 ) ;
F_42 ( & V_50 ) ;
}
F_45 ( & V_50 ) ;
return V_123 ;
}
static int
F_114 ( struct V_1 * * V_124 , const char * V_3 ,
struct V_44 * V_44 )
{
struct V_1 * V_1 ;
struct V_13 * V_17 ;
int V_123 ;
* V_124 = V_1 = F_5 ( sizeof( * V_1 ) , V_60 ) ;
if ( ! V_1 ) {
F_75 ( V_44 , L_18 ,
V_23 ) ;
return - V_29 ;
}
if ( F_1 ( V_1 , V_3 ) ) {
F_41 ( V_44 , L_19 , V_3 ) ;
return 0 ;
}
V_123 = F_13 ( V_3 , & V_25 , & V_17 ) ;
V_1 -> V_53 = V_17 ;
if ( V_123 > 0 ) {
V_123 = F_112 ( V_17 ) ;
if ( ! V_123 ) {
F_47 ( V_17 , V_1 ) ;
return 0 ;
}
}
if ( V_123 < 0 )
return V_123 ;
return 1 ;
}
static int F_115 ( struct V_1 * V_2 , struct V_44 * V_44 ,
bool V_125 )
{
struct V_13 * V_17 = V_2 -> V_53 ;
F_42 ( & V_50 ) ;
if ( ! V_17 -> V_8 || F_113 ( V_17 ) ) {
F_45 ( & V_50 ) ;
return - V_45 ;
}
if ( V_44 && ! V_125 )
F_52 ( V_44 , V_17 -> V_20 ) ;
if ( V_17 -> V_16 -> V_126 == V_127 ) {
if ( F_116 ( V_17 -> V_20 ) )
F_15 ( & V_17 -> V_19 ) ;
}
F_47 ( V_17 , V_2 ) ;
F_45 ( & V_50 ) ;
return 0 ;
}
static int
F_117 ( const struct V_1 * * V_124 , const char * V_3 ,
struct V_44 * V_44 , bool V_110 , bool V_76 )
{
struct V_1 * V_2 ;
long V_114 ;
int V_123 ;
if ( ! V_124 )
return - V_42 ;
V_123 = F_114 ( & V_2 , V_3 , V_44 ) ;
if ( V_123 <= 0 )
goto V_81;
V_123 = 0 ;
V_114 = F_3 () ;
if ( V_76 ) {
V_114 = F_118 ( V_114 ) ;
if ( ! V_114 ) {
F_41 ( V_44 , L_20 ,
V_3 ) ;
V_123 = - V_128 ;
goto V_81;
}
} else {
V_123 = F_119 () ;
if ( F_120 ( V_123 ) ) {
F_75 ( V_44 , L_21 ,
V_3 ) ;
goto V_81;
}
}
V_123 = F_33 ( V_44 , V_2 -> V_53 ) ;
if ( V_123 ) {
F_39 ( V_44 , L_22 ,
V_123 ) ;
F_39 ( V_44 , L_23 ) ;
V_123 = F_108 ( V_2 , V_3 , V_44 ,
V_110 , V_76 , V_114 ) ;
}
if ( ! V_123 )
V_123 = F_115 ( V_2 , V_44 , ! V_110 ) ;
F_121 () ;
V_81:
if ( V_123 < 0 ) {
F_122 ( V_2 ) ;
V_2 = NULL ;
}
* V_124 = V_2 ;
return V_123 ;
}
int
F_123 ( const struct V_1 * * V_124 , const char * V_3 ,
struct V_44 * V_44 )
{
int V_123 ;
F_124 ( V_129 ) ;
V_123 = F_117 ( V_124 , V_3 , V_44 , true , false ) ;
F_125 ( V_129 ) ;
return V_123 ;
}
void F_122 ( const struct V_1 * V_2 )
{
if ( V_2 ) {
if ( ! F_2 ( V_2 ) )
F_46 ( V_2 ) ;
F_23 ( V_2 ) ;
}
}
static void F_126 ( struct V_107 * V_108 )
{
struct V_130 * V_131 ;
const struct V_1 * V_2 ;
V_131 = F_56 ( V_108 , struct V_130 , V_108 ) ;
F_117 ( & V_2 , V_131 -> V_3 , V_131 -> V_44 ,
V_131 -> V_110 , true ) ;
V_131 -> V_132 ( V_2 , V_131 -> V_133 ) ;
F_107 ( V_131 -> V_44 ) ;
F_125 ( V_131 -> V_134 ) ;
F_23 ( V_131 ) ;
}
int
F_127 (
struct V_134 * V_134 , bool V_110 ,
const char * V_3 , struct V_44 * V_44 , T_5 V_135 , void * V_133 ,
void (* V_132)( const struct V_1 * V_2 , void * V_133 ) )
{
struct V_130 * V_131 ;
V_131 = F_5 ( sizeof ( struct V_130 ) , V_135 ) ;
if ( ! V_131 )
return - V_29 ;
V_131 -> V_134 = V_134 ;
V_131 -> V_3 = V_3 ;
V_131 -> V_44 = V_44 ;
V_131 -> V_133 = V_133 ;
V_131 -> V_132 = V_132 ;
V_131 -> V_110 = V_110 ;
if ( ! F_128 ( V_134 ) ) {
F_23 ( V_131 ) ;
return - V_136 ;
}
F_129 ( V_131 -> V_44 ) ;
F_130 ( & V_131 -> V_108 , F_126 ) ;
F_131 ( & V_131 -> V_108 ) ;
return 0 ;
}
static int F_132 ( const char * V_14 )
{
int V_123 ;
const struct V_1 * V_2 ;
F_10 ( L_24 , V_23 , V_14 ) ;
V_123 = F_123 ( & V_2 , V_14 , NULL ) ;
if ( ! V_123 )
F_23 ( V_2 ) ;
F_10 ( L_25 , V_23 , V_14 , V_123 ) ;
return V_123 ;
}
static struct V_13 * F_133 ( const char * V_14 )
{
struct V_13 * V_24 ;
struct V_15 * V_16 = & V_25 ;
F_14 ( & V_16 -> V_26 ) ;
V_24 = F_11 ( V_14 ) ;
F_16 ( & V_16 -> V_26 ) ;
return V_24 ;
}
static int F_134 ( const char * V_14 )
{
struct V_13 * V_17 ;
struct V_1 V_2 ;
F_10 ( L_24 , V_23 , V_14 ) ;
if ( F_1 ( & V_2 , V_14 ) )
return 0 ;
V_17 = F_133 ( V_14 ) ;
if ( V_17 ) {
F_25 ( V_17 ) ;
return 0 ;
}
return - V_42 ;
}
static struct V_137 * F_135 ( const char * V_3 )
{
struct V_137 * V_138 ;
V_138 = F_5 ( sizeof( * V_138 ) + strlen ( V_3 ) + 1 , V_18 ) ;
if ( ! V_138 )
goto exit;
strcpy ( V_138 -> V_3 , V_3 ) ;
exit:
return V_138 ;
}
static int F_136 ( const char * V_3 )
{
struct V_15 * V_16 = & V_25 ;
struct V_137 * V_138 ;
F_12 (fce, &fwc->fw_names, list) {
if ( ! strcmp ( V_138 -> V_3 , V_3 ) )
return 1 ;
}
return 0 ;
}
static int F_116 ( const char * V_3 )
{
struct V_15 * V_16 = & V_25 ;
struct V_137 * V_138 ;
int V_123 = 0 ;
F_14 ( & V_16 -> V_139 ) ;
if ( F_136 ( V_3 ) )
goto V_140;
V_138 = F_135 ( V_3 ) ;
if ( V_138 ) {
V_123 = 1 ;
F_17 ( & V_138 -> V_27 , & V_16 -> V_141 ) ;
F_10 ( L_26 , V_23 , V_3 ) ;
}
V_140:
F_16 ( & V_16 -> V_139 ) ;
return V_123 ;
}
static void F_137 ( struct V_137 * V_138 )
{
F_23 ( V_138 ) ;
}
static void F_138 ( void * V_142 ,
T_6 V_143 )
{
struct V_137 * V_138 = V_142 ;
struct V_15 * V_16 = & V_25 ;
int V_123 ;
V_123 = F_132 ( V_138 -> V_3 ) ;
if ( V_123 ) {
F_14 ( & V_16 -> V_139 ) ;
F_20 ( & V_138 -> V_27 ) ;
F_16 ( & V_16 -> V_139 ) ;
F_137 ( V_138 ) ;
}
}
static void F_139 ( struct V_44 * V_54 , void * V_55 ,
void * V_9 )
{
struct V_56 * V_57 = V_55 ;
const char * V_14 = V_57 -> V_3 ;
struct V_144 * V_28 = V_9 ;
struct V_137 * V_138 ;
V_138 = F_135 ( V_14 ) ;
if ( V_138 )
F_17 ( & V_138 -> V_27 , V_28 ) ;
}
static int F_140 ( struct V_44 * V_54 , void * V_55 ,
void * V_59 )
{
struct V_56 * V_57 = V_55 ;
return ( V_57 -> V_58 == ( unsigned long ) V_59 ) ;
}
static void F_141 ( struct V_44 * V_54 , void * V_9 )
{
F_142 ( V_145 ) ;
struct V_137 * V_138 ;
struct V_137 * V_146 ;
struct V_15 * V_16 = & V_25 ;
F_143 ( V_54 , F_48 ,
F_140 , & V_25 ,
F_139 , & V_145 ) ;
F_111 (fce, fce_next, &todo, list) {
F_20 ( & V_138 -> V_27 ) ;
F_14 ( & V_16 -> V_139 ) ;
if ( ! F_136 ( V_138 -> V_3 ) ) {
F_17 ( & V_138 -> V_27 , & V_16 -> V_141 ) ;
} else {
F_137 ( V_138 ) ;
V_138 = NULL ;
}
F_16 ( & V_16 -> V_139 ) ;
if ( V_138 )
F_144 ( F_138 ,
( void * ) V_138 ,
& V_147 ) ;
}
}
static void F_145 ( void )
{
struct V_15 * V_16 = & V_25 ;
struct V_137 * V_138 ;
F_14 ( & V_16 -> V_139 ) ;
while ( ! F_62 ( & V_16 -> V_141 ) ) {
V_138 = F_146 ( V_16 -> V_141 . V_122 ,
struct V_137 , V_27 ) ;
F_20 ( & V_138 -> V_27 ) ;
F_16 ( & V_16 -> V_139 ) ;
F_134 ( V_138 -> V_3 ) ;
F_137 ( V_138 ) ;
F_14 ( & V_16 -> V_139 ) ;
}
F_16 ( & V_16 -> V_139 ) ;
}
static void F_147 ( void )
{
struct V_15 * V_16 = & V_25 ;
int V_148 ;
F_148 ( V_149 ) ;
F_10 ( L_27 , V_23 ) ;
F_103 ( & V_16 -> V_108 ) ;
V_148 = V_10 ;
V_10 = 10 ;
F_42 ( & V_50 ) ;
V_16 -> V_126 = V_127 ;
F_149 ( NULL , F_141 ) ;
F_45 ( & V_50 ) ;
F_150 ( & V_147 ) ;
V_10 = V_148 ;
}
static void F_151 ( void )
{
F_10 ( L_27 , V_23 ) ;
F_145 () ;
}
static void F_152 ( struct V_107 * V_108 )
{
F_151 () ;
}
static void F_153 ( unsigned long V_150 )
{
F_100 ( & V_25 . V_108 ,
F_154 ( V_150 ) ) ;
}
static int F_155 ( struct V_64 * V_151 ,
unsigned long V_39 , void * V_152 )
{
switch ( V_39 ) {
case V_153 :
case V_154 :
F_110 () ;
F_147 () ;
break;
case V_155 :
case V_156 :
case V_157 :
F_42 ( & V_50 ) ;
V_25 . V_126 = V_158 ;
F_45 ( & V_50 ) ;
F_153 ( 10 * V_159 ) ;
break;
}
return 0 ;
}
static int F_156 ( void )
{
V_25 . V_126 = V_158 ;
return 0 ;
}
static int F_116 ( const char * V_3 )
{
return 0 ;
}
static void T_7 F_157 ( void )
{
F_158 ( & V_25 . V_26 ) ;
F_9 ( & V_25 . V_28 ) ;
V_25 . V_126 = V_158 ;
#ifdef F_159
F_158 ( & V_25 . V_139 ) ;
F_9 ( & V_25 . V_141 ) ;
F_92 ( & V_25 . V_108 ,
F_152 ) ;
V_25 . V_160 . V_161 = F_155 ;
F_160 ( & V_25 . V_160 ) ;
F_161 ( & V_162 ) ;
#endif
}
static int T_7 F_162 ( void )
{
F_157 () ;
#ifdef F_8
F_163 ( & V_163 ) ;
return F_164 ( & V_113 ) ;
#else
return 0 ;
#endif
}
static void T_8 F_165 ( void )
{
#ifdef F_159
F_166 ( & V_162 ) ;
F_167 ( & V_25 . V_160 ) ;
#endif
#ifdef F_8
F_168 ( & V_163 ) ;
F_169 ( & V_113 ) ;
#endif
}
