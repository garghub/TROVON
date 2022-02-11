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
static bool F_30 ( struct V_35 * V_35 , struct V_13 * V_40 )
{
long V_8 ;
char * V_17 ;
V_8 = F_27 ( V_35 ) ;
if ( V_8 <= 0 )
return false ;
V_17 = F_31 ( V_8 ) ;
if ( ! V_17 )
return false ;
if ( F_32 ( V_35 , 0 , V_17 , V_8 ) != V_8 ) {
F_24 ( V_17 ) ;
return false ;
}
V_40 -> V_9 = V_17 ;
V_40 -> V_8 = V_8 ;
return true ;
}
static bool F_33 ( struct V_41 * V_41 ,
struct V_13 * V_17 )
{
int V_32 ;
bool V_42 = false ;
char * V_43 = F_34 () ;
for ( V_32 = 0 ; V_32 < F_35 ( V_44 ) ; V_32 ++ ) {
struct V_35 * V_35 ;
if ( ! V_44 [ V_32 ] [ 0 ] )
continue;
snprintf ( V_43 , V_45 , L_3 , V_44 [ V_32 ] , V_17 -> V_20 ) ;
V_35 = F_36 ( V_43 , V_46 , 0 ) ;
if ( F_37 ( V_35 ) )
continue;
V_42 = F_30 ( V_35 , V_17 ) ;
F_38 ( V_35 ) ;
if ( V_42 )
break;
}
F_39 ( V_43 ) ;
if ( V_42 ) {
F_40 ( V_41 , L_4 ,
V_17 -> V_20 ) ;
F_41 ( & V_47 ) ;
F_42 ( V_48 , & V_17 -> V_49 ) ;
F_43 ( & V_17 -> V_21 ) ;
F_44 ( & V_47 ) ;
}
return V_42 ;
}
static void F_45 ( const struct V_1 * V_2 )
{
if ( ! V_2 -> V_50 ) {
F_24 ( V_2 -> V_9 ) ;
return;
}
F_25 ( V_2 -> V_50 ) ;
}
static void F_46 ( struct V_13 * V_17 , struct V_1 * V_2 )
{
V_2 -> V_50 = V_17 ;
#ifdef F_8
V_2 -> V_34 = V_17 -> V_34 ;
#endif
V_2 -> V_8 = V_17 -> V_8 ;
V_2 -> V_9 = V_17 -> V_9 ;
F_10 ( L_2 ,
V_23 , V_17 -> V_20 , V_17 , V_17 -> V_9 ,
( unsigned int ) V_17 -> V_8 ) ;
}
static void F_47 ( struct V_41 * V_51 , void * V_52 )
{
struct V_53 * V_54 = V_52 ;
if ( V_54 -> V_55 == ( unsigned long ) & V_25 )
F_10 ( L_5 ,
V_23 , V_54 -> V_3 , V_52 ) ;
}
static int F_48 ( struct V_41 * V_51 , void * V_52 ,
void * V_56 )
{
struct V_53 * V_54 = V_52 ;
return ( V_54 -> V_55 == ( unsigned long ) & V_25 ) &&
! strcmp ( V_54 -> V_3 , V_56 ) ;
}
static struct V_53 * F_49 ( struct V_41 * V_51 ,
const char * V_3 )
{
struct V_53 * V_54 ;
V_54 = F_50 ( V_51 , F_47 ,
F_48 , ( void * ) V_3 ) ;
return V_54 ;
}
static int F_51 ( struct V_41 * V_51 , const char * V_3 )
{
struct V_53 * V_54 ;
V_54 = F_49 ( V_51 , V_3 ) ;
if ( V_54 )
return 1 ;
V_54 = F_52 ( F_47 , sizeof( struct V_53 ) +
strlen ( V_3 ) + 1 , V_57 ) ;
if ( ! V_54 )
return - V_29 ;
V_54 -> V_55 = ( unsigned long ) & V_25 ;
strcpy ( V_54 -> V_3 , V_3 ) ;
F_53 ( V_51 , V_54 ) ;
return 0 ;
}
static int F_51 ( struct V_41 * V_51 , const char * V_3 )
{
return 0 ;
}
static struct V_58 * F_54 ( struct V_41 * V_51 )
{
return F_55 ( V_51 , struct V_58 , V_51 ) ;
}
static void F_56 ( struct V_13 * V_17 )
{
if ( F_57 ( V_48 , & V_17 -> V_49 ) )
return;
F_58 ( & V_17 -> V_22 ) ;
F_42 ( V_59 , & V_17 -> V_49 ) ;
F_43 ( & V_17 -> V_21 ) ;
}
static void F_59 ( struct V_58 * V_60 )
{
struct V_13 * V_17 = V_60 -> V_17 ;
F_56 ( V_17 ) ;
V_60 -> V_17 = NULL ;
}
static int F_60 ( struct V_61 * V_62 ,
unsigned long V_63 , void * V_64 )
{
F_41 ( & V_47 ) ;
while ( ! F_61 ( & V_65 ) )
F_56 ( F_62 ( & V_65 ,
struct V_13 ,
V_22 ) ) ;
F_44 ( & V_47 ) ;
return V_66 ;
}
static T_2 F_63 ( struct V_67 * V_67 , struct V_68 * V_69 ,
char * V_17 )
{
return sprintf ( V_17 , L_6 , V_10 ) ;
}
static T_2 F_64 ( struct V_67 * V_67 , struct V_68 * V_69 ,
const char * V_17 , T_3 V_70 )
{
V_10 = F_65 ( V_17 , NULL , 10 ) ;
if ( V_10 < 0 )
V_10 = 0 ;
return V_70 ;
}
static void F_66 ( struct V_41 * V_51 )
{
struct V_58 * V_60 = F_54 ( V_51 ) ;
F_23 ( V_60 ) ;
}
static int F_67 ( struct V_41 * V_51 , struct V_71 * V_72 )
{
struct V_58 * V_60 = F_54 ( V_51 ) ;
if ( F_68 ( V_72 , L_7 , V_60 -> V_17 -> V_20 ) )
return - V_29 ;
if ( F_68 ( V_72 , L_8 , V_10 ) )
return - V_29 ;
if ( F_68 ( V_72 , L_9 , V_60 -> V_73 ) )
return - V_29 ;
return 0 ;
}
static T_2 F_69 ( struct V_41 * V_51 ,
struct V_74 * V_69 , char * V_17 )
{
struct V_58 * V_60 = F_54 ( V_51 ) ;
int V_75 = 0 ;
F_41 ( & V_47 ) ;
if ( V_60 -> V_17 )
V_75 = F_57 ( V_76 , & V_60 -> V_17 -> V_49 ) ;
F_44 ( & V_47 ) ;
return sprintf ( V_17 , L_6 , V_75 ) ;
}
static int F_70 ( struct V_13 * V_17 )
{
if ( ! V_17 -> V_31 )
return 0 ;
if ( V_17 -> V_9 )
F_21 ( V_17 -> V_9 ) ;
V_17 -> V_9 = F_71 ( V_17 -> V_34 , V_17 -> V_33 , 0 , V_77 ) ;
if ( ! V_17 -> V_9 )
return - V_29 ;
return 0 ;
}
static T_2 F_72 ( struct V_41 * V_51 ,
struct V_74 * V_69 ,
const char * V_17 , T_3 V_70 )
{
struct V_58 * V_60 = F_54 ( V_51 ) ;
struct V_13 * V_40 ;
int V_75 = F_65 ( V_17 , NULL , 10 ) ;
int V_32 ;
F_41 ( & V_47 ) ;
V_40 = V_60 -> V_17 ;
if ( ! V_40 )
goto V_78;
switch ( V_75 ) {
case 1 :
if ( ! F_57 ( V_48 , & V_40 -> V_49 ) ) {
for ( V_32 = 0 ; V_32 < V_40 -> V_33 ; V_32 ++ )
F_22 ( V_40 -> V_34 [ V_32 ] ) ;
F_23 ( V_40 -> V_34 ) ;
V_40 -> V_34 = NULL ;
V_40 -> V_79 = 0 ;
V_40 -> V_33 = 0 ;
F_42 ( V_76 , & V_40 -> V_49 ) ;
}
break;
case 0 :
if ( F_57 ( V_76 , & V_40 -> V_49 ) ) {
F_42 ( V_48 , & V_40 -> V_49 ) ;
F_73 ( V_76 , & V_40 -> V_49 ) ;
F_70 ( V_40 ) ;
F_58 ( & V_40 -> V_22 ) ;
F_43 ( & V_40 -> V_21 ) ;
break;
}
default:
F_74 ( V_51 , L_10 , V_23 , V_75 ) ;
case - 1 :
F_59 ( V_60 ) ;
break;
}
V_78:
F_44 ( & V_47 ) ;
return V_70 ;
}
static T_2 F_75 ( struct V_35 * V_80 , struct V_81 * V_82 ,
struct V_83 * V_84 ,
char * V_85 , T_4 V_86 , T_3 V_70 )
{
struct V_41 * V_51 = F_76 ( V_82 ) ;
struct V_58 * V_60 = F_54 ( V_51 ) ;
struct V_13 * V_17 ;
T_2 V_87 ;
F_41 ( & V_47 ) ;
V_17 = V_60 -> V_17 ;
if ( ! V_17 || F_57 ( V_48 , & V_17 -> V_49 ) ) {
V_87 = - V_88 ;
goto V_78;
}
if ( V_86 > V_17 -> V_8 ) {
V_87 = 0 ;
goto V_78;
}
if ( V_70 > V_17 -> V_8 - V_86 )
V_70 = V_17 -> V_8 - V_86 ;
V_87 = V_70 ;
while ( V_70 ) {
void * V_89 ;
int V_90 = V_86 >> V_91 ;
int V_92 = V_86 & ( V_93 - 1 ) ;
int V_94 = F_77 ( T_3 , V_93 - V_92 , V_70 ) ;
V_89 = F_78 ( V_17 -> V_34 [ V_90 ] ) ;
memcpy ( V_85 , V_89 + V_92 , V_94 ) ;
F_79 ( V_17 -> V_34 [ V_90 ] ) ;
V_85 += V_94 ;
V_86 += V_94 ;
V_70 -= V_94 ;
}
V_78:
F_44 ( & V_47 ) ;
return V_87 ;
}
static int F_80 ( struct V_58 * V_60 , int V_95 )
{
struct V_13 * V_17 = V_60 -> V_17 ;
int V_96 = F_81 ( V_95 , V_93 ) >> V_91 ;
if ( V_17 -> V_79 < V_96 ) {
int V_97 = F_82 ( V_96 ,
V_17 -> V_79 * 2 ) ;
struct V_98 * * V_99 ;
V_99 = F_83 ( V_97 * sizeof( void * ) ,
V_57 ) ;
if ( ! V_99 ) {
F_59 ( V_60 ) ;
return - V_29 ;
}
memcpy ( V_99 , V_17 -> V_34 ,
V_17 -> V_79 * sizeof( void * ) ) ;
memset ( & V_99 [ V_17 -> V_79 ] , 0 , sizeof( void * ) *
( V_97 - V_17 -> V_79 ) ) ;
F_23 ( V_17 -> V_34 ) ;
V_17 -> V_34 = V_99 ;
V_17 -> V_79 = V_97 ;
}
while ( V_17 -> V_33 < V_96 ) {
V_17 -> V_34 [ V_17 -> V_33 ] =
F_84 ( V_57 | V_100 ) ;
if ( ! V_17 -> V_34 [ V_17 -> V_33 ] ) {
F_59 ( V_60 ) ;
return - V_29 ;
}
V_17 -> V_33 ++ ;
}
return 0 ;
}
static T_2 F_85 ( struct V_35 * V_80 , struct V_81 * V_82 ,
struct V_83 * V_84 ,
char * V_85 , T_4 V_86 , T_3 V_70 )
{
struct V_41 * V_51 = F_76 ( V_82 ) ;
struct V_58 * V_60 = F_54 ( V_51 ) ;
struct V_13 * V_17 ;
T_2 V_101 ;
if ( ! F_86 ( V_102 ) )
return - V_103 ;
F_41 ( & V_47 ) ;
V_17 = V_60 -> V_17 ;
if ( ! V_17 || F_57 ( V_48 , & V_17 -> V_49 ) ) {
V_101 = - V_88 ;
goto V_78;
}
V_101 = F_80 ( V_60 , V_86 + V_70 ) ;
if ( V_101 )
goto V_78;
V_101 = V_70 ;
while ( V_70 ) {
void * V_89 ;
int V_90 = V_86 >> V_91 ;
int V_92 = V_86 & ( V_93 - 1 ) ;
int V_94 = F_77 ( T_3 , V_93 - V_92 , V_70 ) ;
V_89 = F_78 ( V_17 -> V_34 [ V_90 ] ) ;
memcpy ( V_89 + V_92 , V_85 , V_94 ) ;
F_79 ( V_17 -> V_34 [ V_90 ] ) ;
V_85 += V_94 ;
V_86 += V_94 ;
V_70 -= V_94 ;
}
V_17 -> V_8 = F_87 ( T_3 , V_86 , V_17 -> V_8 ) ;
V_78:
F_44 ( & V_47 ) ;
return V_101 ;
}
static void F_88 ( struct V_104 * V_105 )
{
struct V_58 * V_60 = F_55 ( V_105 ,
struct V_58 , V_106 . V_105 ) ;
F_41 ( & V_47 ) ;
F_59 ( V_60 ) ;
F_44 ( & V_47 ) ;
}
static struct V_58 *
F_89 ( struct V_1 * V_1 , const char * V_14 ,
struct V_41 * V_41 , bool V_107 , bool V_73 )
{
struct V_58 * V_60 ;
struct V_41 * V_108 ;
V_60 = F_5 ( sizeof( * V_60 ) , V_57 ) ;
if ( ! V_60 ) {
F_74 ( V_41 , L_11 , V_23 ) ;
V_60 = F_90 ( - V_29 ) ;
goto exit;
}
V_60 -> V_73 = V_73 ;
V_60 -> V_2 = V_1 ;
F_91 ( & V_60 -> V_106 ,
F_88 ) ;
V_108 = & V_60 -> V_51 ;
F_92 ( V_108 ) ;
F_93 ( V_108 , L_12 , V_14 ) ;
V_108 -> V_109 = V_41 ;
V_108 -> V_67 = & V_110 ;
exit:
return V_60 ;
}
static int F_94 ( struct V_58 * V_60 , bool V_107 ,
long V_111 )
{
int V_101 = 0 ;
struct V_41 * V_108 = & V_60 -> V_51 ;
struct V_13 * V_17 = V_60 -> V_17 ;
V_17 -> V_31 = true ;
F_95 ( V_108 , true ) ;
V_101 = F_96 ( V_108 ) ;
if ( V_101 ) {
F_74 ( V_108 , L_13 , V_23 ) ;
goto V_112;
}
V_101 = F_97 ( V_108 , & V_113 ) ;
if ( V_101 ) {
F_74 ( V_108 , L_14 , V_23 ) ;
goto V_114;
}
F_41 ( & V_47 ) ;
F_17 ( & V_17 -> V_22 , & V_65 ) ;
F_44 ( & V_47 ) ;
V_101 = F_98 ( V_108 , & V_115 ) ;
if ( V_101 ) {
F_41 ( & V_47 ) ;
F_58 ( & V_17 -> V_22 ) ;
F_44 ( & V_47 ) ;
F_74 ( V_108 , L_15 , V_23 ) ;
goto V_116;
}
if ( V_107 ) {
V_17 -> V_117 = true ;
F_95 ( V_108 , false ) ;
F_40 ( V_108 , L_16 , V_17 -> V_20 ) ;
if ( V_111 != V_12 )
F_99 ( & V_60 -> V_106 , V_111 ) ;
F_100 ( & V_60 -> V_51 . V_82 , V_118 ) ;
}
F_101 ( & V_17 -> V_21 ) ;
F_102 ( & V_60 -> V_106 ) ;
F_103 ( V_108 , & V_115 ) ;
V_116:
F_104 ( V_108 , & V_113 ) ;
V_114:
F_105 ( V_108 ) ;
V_112:
F_106 ( V_108 ) ;
return V_101 ;
}
static int F_107 ( struct V_1 * V_1 ,
const char * V_3 , struct V_41 * V_41 ,
bool V_107 , bool V_73 , long V_111 )
{
struct V_58 * V_60 ;
V_60 = F_89 ( V_1 , V_3 , V_41 , V_107 , V_73 ) ;
if ( F_37 ( V_60 ) )
return F_108 ( V_60 ) ;
V_60 -> V_17 = V_1 -> V_50 ;
return F_94 ( V_60 , V_107 , V_111 ) ;
}
static void F_109 ( void )
{
struct V_13 * V_17 ;
struct V_13 * V_119 ;
F_41 ( & V_47 ) ;
F_110 (buf, next, &pending_fw_head, pending_list) {
if ( ! V_17 -> V_117 )
F_56 ( V_17 ) ;
}
F_44 ( & V_47 ) ;
}
static inline int
F_107 ( struct V_1 * V_1 , const char * V_3 ,
struct V_41 * V_41 , bool V_107 , bool V_73 ,
long V_111 )
{
return - V_120 ;
}
static inline void F_109 ( void ) { }
static int F_111 ( struct V_13 * V_17 )
{
int V_121 = 0 ;
F_41 ( & V_47 ) ;
while ( ! F_57 ( V_48 , & V_17 -> V_49 ) ) {
if ( F_112 ( V_17 ) ) {
V_121 = - V_120 ;
break;
}
F_44 ( & V_47 ) ;
F_101 ( & V_17 -> V_21 ) ;
F_41 ( & V_47 ) ;
}
F_44 ( & V_47 ) ;
return V_121 ;
}
static int
F_113 ( struct V_1 * * V_122 , const char * V_3 ,
struct V_41 * V_41 )
{
struct V_1 * V_1 ;
struct V_13 * V_17 ;
int V_121 ;
* V_122 = V_1 = F_5 ( sizeof( * V_1 ) , V_57 ) ;
if ( ! V_1 ) {
F_74 ( V_41 , L_17 ,
V_23 ) ;
return - V_29 ;
}
if ( F_1 ( V_1 , V_3 ) ) {
F_40 ( V_41 , L_18 , V_3 ) ;
return 0 ;
}
V_121 = F_13 ( V_3 , & V_25 , & V_17 ) ;
V_1 -> V_50 = V_17 ;
if ( V_121 > 0 ) {
V_121 = F_111 ( V_17 ) ;
if ( ! V_121 ) {
F_46 ( V_17 , V_1 ) ;
return 0 ;
}
}
if ( V_121 < 0 )
return V_121 ;
return 1 ;
}
static int F_114 ( struct V_1 * V_2 , struct V_41 * V_41 ,
bool V_123 )
{
struct V_13 * V_17 = V_2 -> V_50 ;
F_41 ( & V_47 ) ;
if ( ! V_17 -> V_8 || F_112 ( V_17 ) ) {
F_44 ( & V_47 ) ;
return - V_120 ;
}
if ( V_41 && ! V_123 )
F_51 ( V_41 , V_17 -> V_20 ) ;
if ( V_17 -> V_16 -> V_124 == V_125 ) {
if ( F_115 ( V_17 -> V_20 ) )
F_15 ( & V_17 -> V_19 ) ;
}
F_46 ( V_17 , V_2 ) ;
F_44 ( & V_47 ) ;
return 0 ;
}
static int
F_116 ( const struct V_1 * * V_122 , const char * V_3 ,
struct V_41 * V_41 , bool V_107 , bool V_73 )
{
struct V_1 * V_2 ;
long V_111 ;
int V_121 ;
if ( ! V_122 )
return - V_126 ;
V_121 = F_113 ( & V_2 , V_3 , V_41 ) ;
if ( V_121 <= 0 )
goto V_78;
V_121 = 0 ;
V_111 = F_3 () ;
if ( V_73 ) {
V_111 = F_117 ( V_111 ) ;
if ( ! V_111 ) {
F_40 ( V_41 , L_19 ,
V_3 ) ;
V_121 = - V_127 ;
goto V_78;
}
} else {
V_121 = F_118 () ;
if ( F_119 ( V_121 ) ) {
F_74 ( V_41 , L_20 ,
V_3 ) ;
goto V_78;
}
}
if ( ! F_33 ( V_41 , V_2 -> V_50 ) )
V_121 = F_107 ( V_2 , V_3 , V_41 ,
V_107 , V_73 , V_111 ) ;
if ( ! V_121 )
V_121 = F_114 ( V_2 , V_41 , ! V_107 ) ;
F_120 () ;
V_78:
if ( V_121 < 0 ) {
F_121 ( V_2 ) ;
V_2 = NULL ;
}
* V_122 = V_2 ;
return V_121 ;
}
int
F_122 ( const struct V_1 * * V_122 , const char * V_3 ,
struct V_41 * V_41 )
{
int V_121 ;
F_123 ( V_128 ) ;
V_121 = F_116 ( V_122 , V_3 , V_41 , true , false ) ;
F_124 ( V_128 ) ;
return V_121 ;
}
void F_121 ( const struct V_1 * V_2 )
{
if ( V_2 ) {
if ( ! F_2 ( V_2 ) )
F_45 ( V_2 ) ;
F_23 ( V_2 ) ;
}
}
static void F_125 ( struct V_104 * V_105 )
{
struct V_129 * V_130 ;
const struct V_1 * V_2 ;
V_130 = F_55 ( V_105 , struct V_129 , V_105 ) ;
F_116 ( & V_2 , V_130 -> V_3 , V_130 -> V_41 ,
V_130 -> V_107 , true ) ;
V_130 -> V_131 ( V_2 , V_130 -> V_132 ) ;
F_106 ( V_130 -> V_41 ) ;
F_124 ( V_130 -> V_133 ) ;
F_23 ( V_130 ) ;
}
int
F_126 (
struct V_133 * V_133 , bool V_107 ,
const char * V_3 , struct V_41 * V_41 , T_5 V_134 , void * V_132 ,
void (* V_131)( const struct V_1 * V_2 , void * V_132 ) )
{
struct V_129 * V_130 ;
V_130 = F_5 ( sizeof ( struct V_129 ) , V_134 ) ;
if ( ! V_130 )
return - V_29 ;
V_130 -> V_133 = V_133 ;
V_130 -> V_3 = V_3 ;
V_130 -> V_41 = V_41 ;
V_130 -> V_132 = V_132 ;
V_130 -> V_131 = V_131 ;
V_130 -> V_107 = V_107 ;
if ( ! F_127 ( V_133 ) ) {
F_23 ( V_130 ) ;
return - V_135 ;
}
F_128 ( V_130 -> V_41 ) ;
F_129 ( & V_130 -> V_105 , F_125 ) ;
F_130 ( & V_130 -> V_105 ) ;
return 0 ;
}
static int F_131 ( const char * V_14 )
{
int V_121 ;
const struct V_1 * V_2 ;
F_10 ( L_21 , V_23 , V_14 ) ;
V_121 = F_122 ( & V_2 , V_14 , NULL ) ;
if ( ! V_121 )
F_23 ( V_2 ) ;
F_10 ( L_22 , V_23 , V_14 , V_121 ) ;
return V_121 ;
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
F_10 ( L_21 , V_23 , V_14 ) ;
if ( F_1 ( & V_2 , V_14 ) )
return 0 ;
V_17 = F_132 ( V_14 ) ;
if ( V_17 ) {
F_25 ( V_17 ) ;
return 0 ;
}
return - V_126 ;
}
static struct V_136 * F_134 ( const char * V_3 )
{
struct V_136 * V_137 ;
V_137 = F_5 ( sizeof( * V_137 ) + strlen ( V_3 ) + 1 , V_18 ) ;
if ( ! V_137 )
goto exit;
strcpy ( V_137 -> V_3 , V_3 ) ;
exit:
return V_137 ;
}
static int F_135 ( const char * V_3 )
{
struct V_15 * V_16 = & V_25 ;
struct V_136 * V_137 ;
F_12 (fce, &fwc->fw_names, list) {
if ( ! strcmp ( V_137 -> V_3 , V_3 ) )
return 1 ;
}
return 0 ;
}
static int F_115 ( const char * V_3 )
{
struct V_15 * V_16 = & V_25 ;
struct V_136 * V_137 ;
int V_121 = 0 ;
F_14 ( & V_16 -> V_138 ) ;
if ( F_135 ( V_3 ) )
goto V_139;
V_137 = F_134 ( V_3 ) ;
if ( V_137 ) {
V_121 = 1 ;
F_17 ( & V_137 -> V_27 , & V_16 -> V_140 ) ;
F_10 ( L_23 , V_23 , V_3 ) ;
}
V_139:
F_16 ( & V_16 -> V_138 ) ;
return V_121 ;
}
static void F_136 ( struct V_136 * V_137 )
{
F_23 ( V_137 ) ;
}
static void F_137 ( void * V_141 ,
T_6 V_142 )
{
struct V_136 * V_137 = V_141 ;
struct V_15 * V_16 = & V_25 ;
int V_121 ;
V_121 = F_131 ( V_137 -> V_3 ) ;
if ( V_121 ) {
F_14 ( & V_16 -> V_138 ) ;
F_20 ( & V_137 -> V_27 ) ;
F_16 ( & V_16 -> V_138 ) ;
F_136 ( V_137 ) ;
}
}
static void F_138 ( struct V_41 * V_51 , void * V_52 ,
void * V_9 )
{
struct V_53 * V_54 = V_52 ;
const char * V_14 = V_54 -> V_3 ;
struct V_143 * V_28 = V_9 ;
struct V_136 * V_137 ;
V_137 = F_134 ( V_14 ) ;
if ( V_137 )
F_17 ( & V_137 -> V_27 , V_28 ) ;
}
static int F_139 ( struct V_41 * V_51 , void * V_52 ,
void * V_56 )
{
struct V_53 * V_54 = V_52 ;
return ( V_54 -> V_55 == ( unsigned long ) V_56 ) ;
}
static void F_140 ( struct V_41 * V_51 , void * V_9 )
{
F_141 ( V_144 ) ;
struct V_136 * V_137 ;
struct V_136 * V_145 ;
struct V_15 * V_16 = & V_25 ;
F_142 ( V_51 , F_47 ,
F_139 , & V_25 ,
F_138 , & V_144 ) ;
F_110 (fce, fce_next, &todo, list) {
F_20 ( & V_137 -> V_27 ) ;
F_14 ( & V_16 -> V_138 ) ;
if ( ! F_135 ( V_137 -> V_3 ) ) {
F_17 ( & V_137 -> V_27 , & V_16 -> V_140 ) ;
} else {
F_136 ( V_137 ) ;
V_137 = NULL ;
}
F_16 ( & V_16 -> V_138 ) ;
if ( V_137 )
F_143 ( F_137 ,
( void * ) V_137 ,
& V_146 ) ;
}
}
static void F_144 ( void )
{
struct V_15 * V_16 = & V_25 ;
struct V_136 * V_137 ;
F_14 ( & V_16 -> V_138 ) ;
while ( ! F_61 ( & V_16 -> V_140 ) ) {
V_137 = F_145 ( V_16 -> V_140 . V_119 ,
struct V_136 , V_27 ) ;
F_20 ( & V_137 -> V_27 ) ;
F_16 ( & V_16 -> V_138 ) ;
F_133 ( V_137 -> V_3 ) ;
F_136 ( V_137 ) ;
F_14 ( & V_16 -> V_138 ) ;
}
F_16 ( & V_16 -> V_138 ) ;
}
static void F_146 ( void )
{
struct V_15 * V_16 = & V_25 ;
int V_147 ;
F_147 ( V_148 ) ;
F_10 ( L_24 , V_23 ) ;
F_102 ( & V_16 -> V_105 ) ;
V_147 = V_10 ;
V_10 = 10 ;
F_41 ( & V_47 ) ;
V_16 -> V_124 = V_125 ;
F_148 ( NULL , F_140 ) ;
F_44 ( & V_47 ) ;
F_149 ( & V_146 ) ;
V_10 = V_147 ;
}
static void F_150 ( void )
{
F_10 ( L_24 , V_23 ) ;
F_144 () ;
}
static void F_151 ( struct V_104 * V_105 )
{
F_150 () ;
}
static void F_152 ( unsigned long V_149 )
{
F_99 ( & V_25 . V_105 ,
F_153 ( V_149 ) ) ;
}
static int F_154 ( struct V_61 * V_150 ,
unsigned long V_39 , void * V_151 )
{
switch ( V_39 ) {
case V_152 :
case V_153 :
F_109 () ;
F_146 () ;
break;
case V_154 :
case V_155 :
case V_156 :
F_41 ( & V_47 ) ;
V_25 . V_124 = V_157 ;
F_44 ( & V_47 ) ;
F_152 ( 10 * V_158 ) ;
break;
}
return 0 ;
}
static int F_155 ( void )
{
V_25 . V_124 = V_157 ;
return 0 ;
}
static int F_115 ( const char * V_3 )
{
return 0 ;
}
static void T_7 F_156 ( void )
{
F_157 ( & V_25 . V_26 ) ;
F_9 ( & V_25 . V_28 ) ;
V_25 . V_124 = V_157 ;
#ifdef F_158
F_157 ( & V_25 . V_138 ) ;
F_9 ( & V_25 . V_140 ) ;
F_91 ( & V_25 . V_105 ,
F_151 ) ;
V_25 . V_159 . V_160 = F_154 ;
F_159 ( & V_25 . V_159 ) ;
F_160 ( & V_161 ) ;
#endif
}
static int T_7 F_161 ( void )
{
F_156 () ;
#ifdef F_8
F_162 ( & V_162 ) ;
return F_163 ( & V_110 ) ;
#else
return 0 ;
#endif
}
static void T_8 F_164 ( void )
{
#ifdef F_158
F_165 ( & V_161 ) ;
F_166 ( & V_25 . V_159 ) ;
#endif
#ifdef F_8
F_167 ( & V_162 ) ;
F_168 ( & V_110 ) ;
#endif
}
