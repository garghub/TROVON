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
static int F_21 ( struct V_31 * V_31 , struct V_13 * V_32 )
{
int V_8 ;
char * V_17 ;
int V_33 ;
if ( ! F_22 ( F_23 ( V_31 ) -> V_34 ) )
return - V_35 ;
V_8 = F_24 ( F_23 ( V_31 ) ) ;
if ( V_8 <= 0 )
return - V_35 ;
V_17 = F_25 ( V_8 ) ;
if ( ! V_17 )
return - V_29 ;
V_33 = F_26 ( V_31 , 0 , V_17 , V_8 ) ;
if ( V_33 != V_8 ) {
if ( V_33 > 0 )
V_33 = - V_36 ;
goto V_37;
}
V_33 = F_27 ( V_31 , V_17 , V_8 ) ;
if ( V_33 )
goto V_37;
V_32 -> V_9 = V_17 ;
V_32 -> V_8 = V_8 ;
return 0 ;
V_37:
F_28 ( V_17 ) ;
return V_33 ;
}
static int F_29 ( struct V_38 * V_38 ,
struct V_13 * V_17 )
{
int V_39 ;
int V_33 = - V_40 ;
char * V_41 = F_30 () ;
for ( V_39 = 0 ; V_39 < F_31 ( V_42 ) ; V_39 ++ ) {
struct V_31 * V_31 ;
if ( ! V_42 [ V_39 ] [ 0 ] )
continue;
snprintf ( V_41 , V_43 , L_2 , V_42 [ V_39 ] , V_17 -> V_20 ) ;
V_31 = F_32 ( V_41 , V_44 , 0 ) ;
if ( F_33 ( V_31 ) )
continue;
V_33 = F_21 ( V_31 , V_17 ) ;
F_34 ( V_31 ) ;
if ( V_33 )
F_35 ( V_38 , L_3 ,
V_41 , V_33 ) ;
else
break;
}
F_36 ( V_41 ) ;
if ( ! V_33 ) {
F_37 ( V_38 , L_4 ,
V_17 -> V_20 ) ;
F_38 ( & V_45 ) ;
F_39 ( V_46 , & V_17 -> V_47 ) ;
F_40 ( & V_17 -> V_21 ) ;
F_41 ( & V_45 ) ;
}
return V_33 ;
}
static void F_42 ( const struct V_1 * V_2 )
{
if ( ! V_2 -> V_48 ) {
F_28 ( V_2 -> V_9 ) ;
return;
}
F_19 ( V_2 -> V_48 ) ;
}
static void F_43 ( struct V_13 * V_17 , struct V_1 * V_2 )
{
V_2 -> V_48 = V_17 ;
#ifdef F_8
V_2 -> V_49 = V_17 -> V_49 ;
#endif
V_2 -> V_8 = V_17 -> V_8 ;
V_2 -> V_9 = V_17 -> V_9 ;
F_10 ( L_5 ,
V_23 , V_17 -> V_20 , V_17 , V_17 -> V_9 ,
( unsigned int ) V_17 -> V_8 ) ;
}
static void F_44 ( struct V_38 * V_50 , void * V_51 )
{
struct V_52 * V_53 = V_51 ;
if ( V_53 -> V_54 == ( unsigned long ) & V_25 )
F_10 ( L_6 ,
V_23 , V_53 -> V_3 , V_51 ) ;
}
static int F_45 ( struct V_38 * V_50 , void * V_51 ,
void * V_55 )
{
struct V_52 * V_53 = V_51 ;
return ( V_53 -> V_54 == ( unsigned long ) & V_25 ) &&
! strcmp ( V_53 -> V_3 , V_55 ) ;
}
static struct V_52 * F_46 ( struct V_38 * V_50 ,
const char * V_3 )
{
struct V_52 * V_53 ;
V_53 = F_47 ( V_50 , F_44 ,
F_45 , ( void * ) V_3 ) ;
return V_53 ;
}
static int F_48 ( struct V_38 * V_50 , const char * V_3 )
{
struct V_52 * V_53 ;
V_53 = F_46 ( V_50 , V_3 ) ;
if ( V_53 )
return 1 ;
V_53 = F_49 ( F_44 , sizeof( struct V_52 ) +
strlen ( V_3 ) + 1 , V_56 ) ;
if ( ! V_53 )
return - V_29 ;
V_53 -> V_54 = ( unsigned long ) & V_25 ;
strcpy ( V_53 -> V_3 , V_3 ) ;
F_50 ( V_50 , V_53 ) ;
return 0 ;
}
static int F_48 ( struct V_38 * V_50 , const char * V_3 )
{
return 0 ;
}
static struct V_57 * F_51 ( struct V_38 * V_50 )
{
return F_52 ( V_50 , struct V_57 , V_50 ) ;
}
static void F_53 ( struct V_13 * V_17 )
{
if ( F_54 ( V_46 , & V_17 -> V_47 ) )
return;
F_55 ( & V_17 -> V_22 ) ;
F_39 ( V_58 , & V_17 -> V_47 ) ;
F_40 ( & V_17 -> V_21 ) ;
}
static void F_56 ( struct V_57 * V_59 )
{
struct V_13 * V_17 = V_59 -> V_17 ;
F_53 ( V_17 ) ;
V_59 -> V_17 = NULL ;
}
static int F_57 ( struct V_60 * V_61 ,
unsigned long V_62 , void * V_63 )
{
F_38 ( & V_45 ) ;
while ( ! F_58 ( & V_64 ) )
F_53 ( F_59 ( & V_64 ,
struct V_13 ,
V_22 ) ) ;
F_41 ( & V_45 ) ;
return V_65 ;
}
static T_1 F_60 ( struct V_66 * V_66 , struct V_67 * V_68 ,
char * V_17 )
{
return sprintf ( V_17 , L_7 , V_10 ) ;
}
static T_1 F_61 ( struct V_66 * V_66 , struct V_67 * V_68 ,
const char * V_17 , T_2 V_69 )
{
V_10 = F_62 ( V_17 , NULL , 10 ) ;
if ( V_10 < 0 )
V_10 = 0 ;
return V_69 ;
}
static void F_63 ( struct V_38 * V_50 )
{
struct V_57 * V_59 = F_51 ( V_50 ) ;
F_64 ( V_59 ) ;
}
static int F_65 ( struct V_38 * V_50 , struct V_70 * V_71 )
{
struct V_57 * V_59 = F_51 ( V_50 ) ;
if ( F_66 ( V_71 , L_8 , V_59 -> V_17 -> V_20 ) )
return - V_29 ;
if ( F_66 ( V_71 , L_9 , V_10 ) )
return - V_29 ;
if ( F_66 ( V_71 , L_10 , V_59 -> V_72 ) )
return - V_29 ;
return 0 ;
}
static T_1 F_67 ( struct V_38 * V_50 ,
struct V_73 * V_68 , char * V_17 )
{
struct V_57 * V_59 = F_51 ( V_50 ) ;
int V_74 = 0 ;
F_38 ( & V_45 ) ;
if ( V_59 -> V_17 )
V_74 = F_54 ( V_75 , & V_59 -> V_17 -> V_47 ) ;
F_41 ( & V_45 ) ;
return sprintf ( V_17 , L_7 , V_74 ) ;
}
static int F_68 ( struct V_13 * V_17 )
{
if ( ! V_17 -> V_76 )
return 0 ;
if ( V_17 -> V_9 )
F_69 ( V_17 -> V_9 ) ;
V_17 -> V_9 = F_70 ( V_17 -> V_49 , V_17 -> V_77 , 0 , V_78 ) ;
if ( ! V_17 -> V_9 )
return - V_29 ;
return 0 ;
}
static T_1 F_71 ( struct V_38 * V_50 ,
struct V_73 * V_68 ,
const char * V_17 , T_2 V_69 )
{
struct V_57 * V_59 = F_51 ( V_50 ) ;
struct V_13 * V_32 ;
T_1 V_79 = V_69 ;
int V_74 = F_62 ( V_17 , NULL , 10 ) ;
int V_39 ;
F_38 ( & V_45 ) ;
V_32 = V_59 -> V_17 ;
if ( ! V_32 )
goto V_80;
switch ( V_74 ) {
case 1 :
if ( ! F_54 ( V_46 , & V_32 -> V_47 ) ) {
for ( V_39 = 0 ; V_39 < V_32 -> V_77 ; V_39 ++ )
F_72 ( V_32 -> V_49 [ V_39 ] ) ;
F_64 ( V_32 -> V_49 ) ;
V_32 -> V_49 = NULL ;
V_32 -> V_81 = 0 ;
V_32 -> V_77 = 0 ;
F_39 ( V_75 , & V_32 -> V_47 ) ;
}
break;
case 0 :
if ( F_54 ( V_75 , & V_32 -> V_47 ) ) {
int V_33 ;
F_39 ( V_46 , & V_32 -> V_47 ) ;
F_73 ( V_75 , & V_32 -> V_47 ) ;
V_33 = F_68 ( V_32 ) ;
if ( V_33 )
F_74 ( V_50 , L_11 ,
V_23 ) ;
else
V_33 = F_27 ( NULL ,
V_32 -> V_9 , V_32 -> V_8 ) ;
F_55 ( & V_32 -> V_22 ) ;
if ( V_33 ) {
F_39 ( V_58 , & V_32 -> V_47 ) ;
V_79 = V_33 ;
}
F_40 ( & V_32 -> V_21 ) ;
break;
}
default:
F_74 ( V_50 , L_12 , V_23 , V_74 ) ;
case - 1 :
F_56 ( V_59 ) ;
break;
}
V_80:
F_41 ( & V_45 ) ;
return V_79 ;
}
static T_1 F_75 ( struct V_31 * V_82 , struct V_83 * V_84 ,
struct V_85 * V_86 ,
char * V_87 , T_3 V_88 , T_2 V_69 )
{
struct V_38 * V_50 = F_76 ( V_84 ) ;
struct V_57 * V_59 = F_51 ( V_50 ) ;
struct V_13 * V_17 ;
T_1 V_89 ;
F_38 ( & V_45 ) ;
V_17 = V_59 -> V_17 ;
if ( ! V_17 || F_54 ( V_46 , & V_17 -> V_47 ) ) {
V_89 = - V_90 ;
goto V_80;
}
if ( V_88 > V_17 -> V_8 ) {
V_89 = 0 ;
goto V_80;
}
if ( V_69 > V_17 -> V_8 - V_88 )
V_69 = V_17 -> V_8 - V_88 ;
V_89 = V_69 ;
while ( V_69 ) {
void * V_91 ;
int V_92 = V_88 >> V_93 ;
int V_94 = V_88 & ( V_95 - 1 ) ;
int V_96 = F_77 ( T_2 , V_95 - V_94 , V_69 ) ;
V_91 = F_78 ( V_17 -> V_49 [ V_92 ] ) ;
memcpy ( V_87 , V_91 + V_94 , V_96 ) ;
F_79 ( V_17 -> V_49 [ V_92 ] ) ;
V_87 += V_96 ;
V_88 += V_96 ;
V_69 -= V_96 ;
}
V_80:
F_41 ( & V_45 ) ;
return V_89 ;
}
static int F_80 ( struct V_57 * V_59 , int V_97 )
{
struct V_13 * V_17 = V_59 -> V_17 ;
int V_98 = F_81 ( V_97 ) >> V_93 ;
if ( V_17 -> V_81 < V_98 ) {
int V_99 = F_82 ( V_98 ,
V_17 -> V_81 * 2 ) ;
struct V_100 * * V_101 ;
V_101 = F_83 ( V_99 * sizeof( void * ) ,
V_56 ) ;
if ( ! V_101 ) {
F_56 ( V_59 ) ;
return - V_29 ;
}
memcpy ( V_101 , V_17 -> V_49 ,
V_17 -> V_81 * sizeof( void * ) ) ;
memset ( & V_101 [ V_17 -> V_81 ] , 0 , sizeof( void * ) *
( V_99 - V_17 -> V_81 ) ) ;
F_64 ( V_17 -> V_49 ) ;
V_17 -> V_49 = V_101 ;
V_17 -> V_81 = V_99 ;
}
while ( V_17 -> V_77 < V_98 ) {
V_17 -> V_49 [ V_17 -> V_77 ] =
F_84 ( V_56 | V_102 ) ;
if ( ! V_17 -> V_49 [ V_17 -> V_77 ] ) {
F_56 ( V_59 ) ;
return - V_29 ;
}
V_17 -> V_77 ++ ;
}
return 0 ;
}
static T_1 F_85 ( struct V_31 * V_82 , struct V_83 * V_84 ,
struct V_85 * V_86 ,
char * V_87 , T_3 V_88 , T_2 V_69 )
{
struct V_38 * V_50 = F_76 ( V_84 ) ;
struct V_57 * V_59 = F_51 ( V_50 ) ;
struct V_13 * V_17 ;
T_1 V_103 ;
if ( ! F_86 ( V_104 ) )
return - V_105 ;
F_38 ( & V_45 ) ;
V_17 = V_59 -> V_17 ;
if ( ! V_17 || F_54 ( V_46 , & V_17 -> V_47 ) ) {
V_103 = - V_90 ;
goto V_80;
}
V_103 = F_80 ( V_59 , V_88 + V_69 ) ;
if ( V_103 )
goto V_80;
V_103 = V_69 ;
while ( V_69 ) {
void * V_91 ;
int V_92 = V_88 >> V_93 ;
int V_94 = V_88 & ( V_95 - 1 ) ;
int V_96 = F_77 ( T_2 , V_95 - V_94 , V_69 ) ;
V_91 = F_78 ( V_17 -> V_49 [ V_92 ] ) ;
memcpy ( V_91 + V_94 , V_87 , V_96 ) ;
F_79 ( V_17 -> V_49 [ V_92 ] ) ;
V_87 += V_96 ;
V_88 += V_96 ;
V_69 -= V_96 ;
}
V_17 -> V_8 = F_87 ( T_2 , V_88 , V_17 -> V_8 ) ;
V_80:
F_41 ( & V_45 ) ;
return V_103 ;
}
static void F_88 ( struct V_106 * V_107 )
{
struct V_57 * V_59 = F_52 ( V_107 ,
struct V_57 , V_108 . V_107 ) ;
F_38 ( & V_45 ) ;
F_56 ( V_59 ) ;
F_41 ( & V_45 ) ;
}
static struct V_57 *
F_89 ( struct V_1 * V_1 , const char * V_14 ,
struct V_38 * V_38 , unsigned int V_109 )
{
struct V_57 * V_59 ;
struct V_38 * V_110 ;
V_59 = F_5 ( sizeof( * V_59 ) , V_56 ) ;
if ( ! V_59 ) {
F_74 ( V_38 , L_13 , V_23 ) ;
V_59 = F_90 ( - V_29 ) ;
goto exit;
}
V_59 -> V_72 = ! ! ( V_109 & V_111 ) ;
V_59 -> V_2 = V_1 ;
F_91 ( & V_59 -> V_108 ,
F_88 ) ;
V_110 = & V_59 -> V_50 ;
F_92 ( V_110 ) ;
F_93 ( V_110 , L_14 , V_14 ) ;
V_110 -> V_112 = V_38 ;
V_110 -> V_66 = & V_113 ;
exit:
return V_59 ;
}
static int F_94 ( struct V_57 * V_59 ,
unsigned int V_109 , long V_114 )
{
int V_103 = 0 ;
struct V_38 * V_110 = & V_59 -> V_50 ;
struct V_13 * V_17 = V_59 -> V_17 ;
V_17 -> V_76 = true ;
F_95 ( V_110 , true ) ;
V_103 = F_96 ( V_110 ) ;
if ( V_103 ) {
F_74 ( V_110 , L_15 , V_23 ) ;
goto V_115;
}
V_103 = F_97 ( V_110 , & V_116 ) ;
if ( V_103 ) {
F_74 ( V_110 , L_16 , V_23 ) ;
goto V_117;
}
F_38 ( & V_45 ) ;
F_17 ( & V_17 -> V_22 , & V_64 ) ;
F_41 ( & V_45 ) ;
V_103 = F_98 ( V_110 , & V_118 ) ;
if ( V_103 ) {
F_38 ( & V_45 ) ;
F_55 ( & V_17 -> V_22 ) ;
F_41 ( & V_45 ) ;
F_74 ( V_110 , L_17 , V_23 ) ;
goto V_119;
}
if ( V_109 & V_120 ) {
V_17 -> V_121 = true ;
F_95 ( V_110 , false ) ;
F_37 ( V_110 , L_18 , V_17 -> V_20 ) ;
if ( V_114 != V_12 )
F_99 ( V_122 ,
& V_59 -> V_108 , V_114 ) ;
F_100 ( & V_59 -> V_50 . V_84 , V_123 ) ;
}
F_101 ( & V_17 -> V_21 ) ;
F_102 ( & V_59 -> V_108 ) ;
if ( F_103 ( V_17 ) )
V_103 = - V_124 ;
else if ( ! V_17 -> V_9 )
V_103 = - V_29 ;
F_104 ( V_110 , & V_118 ) ;
V_119:
F_105 ( V_110 , & V_116 ) ;
V_117:
F_106 ( V_110 ) ;
V_115:
F_107 ( V_110 ) ;
return V_103 ;
}
static int F_108 ( struct V_1 * V_1 ,
const char * V_3 , struct V_38 * V_38 ,
unsigned int V_109 , long V_114 )
{
struct V_57 * V_59 ;
V_59 = F_89 ( V_1 , V_3 , V_38 , V_109 ) ;
if ( F_33 ( V_59 ) )
return F_109 ( V_59 ) ;
V_59 -> V_17 = V_1 -> V_48 ;
return F_94 ( V_59 , V_109 , V_114 ) ;
}
static void F_110 ( void )
{
struct V_13 * V_17 ;
struct V_13 * V_125 ;
F_38 ( & V_45 ) ;
F_111 (buf, next, &pending_fw_head, pending_list) {
if ( ! V_17 -> V_121 )
F_53 ( V_17 ) ;
}
F_41 ( & V_45 ) ;
}
static inline int
F_108 ( struct V_1 * V_1 , const char * V_3 ,
struct V_38 * V_38 , unsigned int V_109 ,
long V_114 )
{
return - V_40 ;
}
static inline void F_110 ( void ) { }
static int F_112 ( struct V_13 * V_17 )
{
int V_126 = 0 ;
F_38 ( & V_45 ) ;
while ( ! F_54 ( V_46 , & V_17 -> V_47 ) ) {
if ( F_103 ( V_17 ) ) {
V_126 = - V_40 ;
break;
}
F_41 ( & V_45 ) ;
F_101 ( & V_17 -> V_21 ) ;
F_38 ( & V_45 ) ;
}
F_41 ( & V_45 ) ;
return V_126 ;
}
static int
F_113 ( struct V_1 * * V_127 , const char * V_3 ,
struct V_38 * V_38 )
{
struct V_1 * V_1 ;
struct V_13 * V_17 ;
int V_126 ;
* V_127 = V_1 = F_5 ( sizeof( * V_1 ) , V_56 ) ;
if ( ! V_1 ) {
F_74 ( V_38 , L_19 ,
V_23 ) ;
return - V_29 ;
}
if ( F_1 ( V_1 , V_3 ) ) {
F_37 ( V_38 , L_20 , V_3 ) ;
return 0 ;
}
V_126 = F_13 ( V_3 , & V_25 , & V_17 ) ;
V_1 -> V_48 = V_17 ;
if ( V_126 > 0 ) {
V_126 = F_112 ( V_17 ) ;
if ( ! V_126 ) {
F_43 ( V_17 , V_1 ) ;
return 0 ;
}
}
if ( V_126 < 0 )
return V_126 ;
return 1 ;
}
static int F_114 ( struct V_1 * V_2 , struct V_38 * V_38 ,
unsigned int V_109 )
{
struct V_13 * V_17 = V_2 -> V_48 ;
F_38 ( & V_45 ) ;
if ( ! V_17 -> V_8 || F_103 ( V_17 ) ) {
F_41 ( & V_45 ) ;
return - V_40 ;
}
if ( V_38 && ( V_109 & V_120 ) )
F_48 ( V_38 , V_17 -> V_20 ) ;
if ( V_17 -> V_16 -> V_128 == V_129 ) {
if ( F_115 ( V_17 -> V_20 ) )
F_15 ( & V_17 -> V_19 ) ;
}
F_43 ( V_17 , V_2 ) ;
F_41 ( & V_45 ) ;
return 0 ;
}
static int
F_116 ( const struct V_1 * * V_127 , const char * V_3 ,
struct V_38 * V_38 , unsigned int V_109 )
{
struct V_1 * V_2 ;
long V_114 ;
int V_126 ;
if ( ! V_127 )
return - V_35 ;
V_126 = F_113 ( & V_2 , V_3 , V_38 ) ;
if ( V_126 <= 0 )
goto V_80;
V_126 = 0 ;
V_114 = F_3 () ;
if ( V_109 & V_111 ) {
V_114 = F_117 ( V_114 ) ;
if ( ! V_114 ) {
F_37 ( V_38 , L_21 ,
V_3 ) ;
V_126 = - V_130 ;
goto V_80;
}
} else {
V_126 = F_118 () ;
if ( F_119 ( V_126 ) ) {
F_74 ( V_38 , L_22 ,
V_3 ) ;
goto V_80;
}
}
V_126 = F_29 ( V_38 , V_2 -> V_48 ) ;
if ( V_126 ) {
if ( ! ( V_109 & V_131 ) )
F_35 ( V_38 ,
L_23 ,
V_3 , V_126 ) ;
if ( V_109 & V_132 ) {
F_35 ( V_38 , L_24 ) ;
V_126 = F_108 ( V_2 , V_3 , V_38 ,
V_109 , V_114 ) ;
}
}
if ( ! V_126 )
V_126 = F_114 ( V_2 , V_38 , V_109 ) ;
F_120 () ;
V_80:
if ( V_126 < 0 ) {
F_121 ( V_2 ) ;
V_2 = NULL ;
}
* V_127 = V_2 ;
return V_126 ;
}
int
F_122 ( const struct V_1 * * V_127 , const char * V_3 ,
struct V_38 * V_38 )
{
int V_126 ;
F_123 ( V_133 ) ;
V_126 = F_116 ( V_127 , V_3 , V_38 ,
V_120 | V_134 ) ;
F_124 ( V_133 ) ;
return V_126 ;
}
int F_125 ( const struct V_1 * * V_127 ,
const char * V_3 , struct V_38 * V_38 )
{
int V_126 ;
F_123 ( V_133 ) ;
V_126 = F_116 ( V_127 , V_3 , V_38 ,
V_120 | V_131 ) ;
F_124 ( V_133 ) ;
return V_126 ;
}
void F_121 ( const struct V_1 * V_2 )
{
if ( V_2 ) {
if ( ! F_2 ( V_2 ) )
F_42 ( V_2 ) ;
F_64 ( V_2 ) ;
}
}
static void F_126 ( struct V_106 * V_107 )
{
struct V_135 * V_136 ;
const struct V_1 * V_2 ;
V_136 = F_52 ( V_107 , struct V_135 , V_107 ) ;
F_116 ( & V_2 , V_136 -> V_3 , V_136 -> V_38 ,
V_136 -> V_109 ) ;
V_136 -> V_137 ( V_2 , V_136 -> V_138 ) ;
F_107 ( V_136 -> V_38 ) ;
F_124 ( V_136 -> V_139 ) ;
F_64 ( V_136 ) ;
}
int
F_127 (
struct V_139 * V_139 , bool V_140 ,
const char * V_3 , struct V_38 * V_38 , T_4 V_141 , void * V_138 ,
void (* V_137)( const struct V_1 * V_2 , void * V_138 ) )
{
struct V_135 * V_136 ;
V_136 = F_5 ( sizeof ( struct V_135 ) , V_141 ) ;
if ( ! V_136 )
return - V_29 ;
V_136 -> V_139 = V_139 ;
V_136 -> V_3 = V_3 ;
V_136 -> V_38 = V_38 ;
V_136 -> V_138 = V_138 ;
V_136 -> V_137 = V_137 ;
V_136 -> V_109 = V_111 | V_134 |
( V_140 ? V_120 : V_132 ) ;
if ( ! F_128 ( V_139 ) ) {
F_64 ( V_136 ) ;
return - V_142 ;
}
F_129 ( V_136 -> V_38 ) ;
F_130 ( & V_136 -> V_107 , F_126 ) ;
F_131 ( & V_136 -> V_107 ) ;
return 0 ;
}
static int F_132 ( const char * V_14 )
{
int V_126 ;
const struct V_1 * V_2 ;
F_10 ( L_25 , V_23 , V_14 ) ;
V_126 = F_122 ( & V_2 , V_14 , NULL ) ;
if ( ! V_126 )
F_64 ( V_2 ) ;
F_10 ( L_26 , V_23 , V_14 , V_126 ) ;
return V_126 ;
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
F_10 ( L_25 , V_23 , V_14 ) ;
if ( F_1 ( & V_2 , V_14 ) )
return 0 ;
V_17 = F_133 ( V_14 ) ;
if ( V_17 ) {
F_19 ( V_17 ) ;
return 0 ;
}
return - V_35 ;
}
static struct V_143 * F_135 ( const char * V_3 )
{
struct V_143 * V_144 ;
V_144 = F_5 ( sizeof( * V_144 ) + strlen ( V_3 ) + 1 , V_18 ) ;
if ( ! V_144 )
goto exit;
strcpy ( V_144 -> V_3 , V_3 ) ;
exit:
return V_144 ;
}
static int F_136 ( const char * V_3 )
{
struct V_15 * V_16 = & V_25 ;
struct V_143 * V_144 ;
F_12 (fce, &fwc->fw_names, list) {
if ( ! strcmp ( V_144 -> V_3 , V_3 ) )
return 1 ;
}
return 0 ;
}
static int F_115 ( const char * V_3 )
{
struct V_15 * V_16 = & V_25 ;
struct V_143 * V_144 ;
int V_126 = 0 ;
F_14 ( & V_16 -> V_145 ) ;
if ( F_136 ( V_3 ) )
goto V_146;
V_144 = F_135 ( V_3 ) ;
if ( V_144 ) {
V_126 = 1 ;
F_17 ( & V_144 -> V_27 , & V_16 -> V_147 ) ;
F_10 ( L_27 , V_23 , V_3 ) ;
}
V_146:
F_16 ( & V_16 -> V_145 ) ;
return V_126 ;
}
static void F_137 ( struct V_143 * V_144 )
{
F_64 ( V_144 ) ;
}
static void F_138 ( void * V_148 ,
T_5 V_149 )
{
struct V_143 * V_144 = V_148 ;
struct V_15 * V_16 = & V_25 ;
int V_126 ;
V_126 = F_132 ( V_144 -> V_3 ) ;
if ( V_126 ) {
F_14 ( & V_16 -> V_145 ) ;
F_139 ( & V_144 -> V_27 ) ;
F_16 ( & V_16 -> V_145 ) ;
F_137 ( V_144 ) ;
}
}
static void F_140 ( struct V_38 * V_50 , void * V_51 ,
void * V_9 )
{
struct V_52 * V_53 = V_51 ;
const char * V_14 = V_53 -> V_3 ;
struct V_150 * V_28 = V_9 ;
struct V_143 * V_144 ;
V_144 = F_135 ( V_14 ) ;
if ( V_144 )
F_17 ( & V_144 -> V_27 , V_28 ) ;
}
static int F_141 ( struct V_38 * V_50 , void * V_51 ,
void * V_55 )
{
struct V_52 * V_53 = V_51 ;
return ( V_53 -> V_54 == ( unsigned long ) V_55 ) ;
}
static void F_142 ( struct V_38 * V_50 , void * V_9 )
{
F_143 ( V_151 ) ;
struct V_143 * V_144 ;
struct V_143 * V_152 ;
struct V_15 * V_16 = & V_25 ;
F_144 ( V_50 , F_44 ,
F_141 , & V_25 ,
F_140 , & V_151 ) ;
F_111 (fce, fce_next, &todo, list) {
F_139 ( & V_144 -> V_27 ) ;
F_14 ( & V_16 -> V_145 ) ;
if ( ! F_136 ( V_144 -> V_3 ) ) {
F_17 ( & V_144 -> V_27 , & V_16 -> V_147 ) ;
} else {
F_137 ( V_144 ) ;
V_144 = NULL ;
}
F_16 ( & V_16 -> V_145 ) ;
if ( V_144 )
F_145 ( F_138 ,
( void * ) V_144 ,
& V_153 ) ;
}
}
static void F_146 ( void )
{
struct V_15 * V_16 = & V_25 ;
struct V_143 * V_144 ;
F_14 ( & V_16 -> V_145 ) ;
while ( ! F_58 ( & V_16 -> V_147 ) ) {
V_144 = F_147 ( V_16 -> V_147 . V_125 ,
struct V_143 , V_27 ) ;
F_139 ( & V_144 -> V_27 ) ;
F_16 ( & V_16 -> V_145 ) ;
F_134 ( V_144 -> V_3 ) ;
F_137 ( V_144 ) ;
F_14 ( & V_16 -> V_145 ) ;
}
F_16 ( & V_16 -> V_145 ) ;
}
static void F_148 ( void )
{
struct V_15 * V_16 = & V_25 ;
int V_154 ;
F_149 ( V_155 ) ;
F_10 ( L_28 , V_23 ) ;
F_102 ( & V_16 -> V_107 ) ;
V_154 = V_10 ;
V_10 = 10 ;
F_38 ( & V_45 ) ;
V_16 -> V_128 = V_129 ;
F_150 ( NULL , F_142 ) ;
F_41 ( & V_45 ) ;
F_151 ( & V_153 ) ;
V_10 = V_154 ;
}
static void F_152 ( void )
{
F_10 ( L_28 , V_23 ) ;
F_146 () ;
}
static void F_153 ( struct V_106 * V_107 )
{
F_152 () ;
}
static void F_154 ( unsigned long V_156 )
{
F_99 ( V_122 , & V_25 . V_107 ,
F_155 ( V_156 ) ) ;
}
static int F_156 ( struct V_60 * V_157 ,
unsigned long V_158 , void * V_159 )
{
switch ( V_158 ) {
case V_160 :
case V_161 :
case V_162 :
F_110 () ;
F_148 () ;
break;
case V_163 :
case V_164 :
case V_165 :
F_38 ( & V_45 ) ;
V_25 . V_128 = V_166 ;
F_41 ( & V_45 ) ;
F_154 ( 10 * V_167 ) ;
break;
}
return 0 ;
}
static int F_157 ( void )
{
V_25 . V_128 = V_166 ;
return 0 ;
}
static int F_115 ( const char * V_3 )
{
return 0 ;
}
static void T_6 F_158 ( void )
{
F_159 ( & V_25 . V_26 ) ;
F_9 ( & V_25 . V_28 ) ;
V_25 . V_128 = V_166 ;
#ifdef F_160
F_159 ( & V_25 . V_145 ) ;
F_9 ( & V_25 . V_147 ) ;
F_91 ( & V_25 . V_107 ,
F_153 ) ;
V_25 . V_168 . V_169 = F_156 ;
F_161 ( & V_25 . V_168 ) ;
F_162 ( & V_170 ) ;
#endif
}
static int T_6 F_163 ( void )
{
F_158 () ;
#ifdef F_8
F_164 ( & V_171 ) ;
return F_165 ( & V_113 ) ;
#else
return 0 ;
#endif
}
static void T_7 F_166 ( void )
{
#ifdef F_160
F_167 ( & V_170 ) ;
F_168 ( & V_25 . V_168 ) ;
#endif
#ifdef F_8
F_169 ( & V_171 ) ;
F_170 ( & V_113 ) ;
#endif
}
