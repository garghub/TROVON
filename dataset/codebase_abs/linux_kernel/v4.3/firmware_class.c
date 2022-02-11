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
V_17 = F_5 ( sizeof( * V_17 ) , V_18 ) ;
if ( ! V_17 )
return NULL ;
V_17 -> V_19 = F_6 ( V_14 , V_18 ) ;
if ( ! V_17 -> V_19 ) {
F_7 ( V_17 ) ;
return NULL ;
}
F_8 ( & V_17 -> V_20 ) ;
V_17 -> V_16 = V_16 ;
F_9 ( & V_17 -> V_21 ) ;
#ifdef F_10
F_11 ( & V_17 -> V_22 ) ;
#endif
F_12 ( L_1 , V_23 , V_14 , V_17 ) ;
return V_17 ;
}
static struct V_13 * F_13 ( const char * V_14 )
{
struct V_13 * V_24 ;
struct V_15 * V_16 = & V_25 ;
F_14 (tmp, &fwc->head, list)
if ( ! strcmp ( V_24 -> V_19 , V_14 ) )
return V_24 ;
return NULL ;
}
static int F_15 ( const char * V_14 ,
struct V_15 * V_16 ,
struct V_13 * * V_17 )
{
struct V_13 * V_24 ;
F_16 ( & V_16 -> V_26 ) ;
V_24 = F_13 ( V_14 ) ;
if ( V_24 ) {
F_17 ( & V_24 -> V_20 ) ;
F_18 ( & V_16 -> V_26 ) ;
* V_17 = V_24 ;
return 1 ;
}
V_24 = F_4 ( V_14 , V_16 ) ;
if ( V_24 )
F_19 ( & V_24 -> V_27 , & V_16 -> V_28 ) ;
F_18 ( & V_16 -> V_26 ) ;
* V_17 = V_24 ;
return V_24 ? 0 : - V_29 ;
}
static void F_20 ( struct V_30 * V_20 )
__releases( &fwc->lock
static void F_21 ( struct V_13 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_16 ;
F_16 ( & V_16 -> V_26 ) ;
if ( ! F_22 ( & V_17 -> V_20 , F_20 ) )
F_18 ( & V_16 -> V_26 ) ;
}
static int F_23 ( struct V_31 * V_31 , struct V_13 * V_32 )
{
int V_8 ;
char * V_17 ;
int V_33 ;
if ( ! F_24 ( F_25 ( V_31 ) -> V_34 ) )
return - V_35 ;
V_8 = F_26 ( F_25 ( V_31 ) ) ;
if ( V_8 <= 0 )
return - V_35 ;
V_17 = F_27 ( V_8 ) ;
if ( ! V_17 )
return - V_29 ;
V_33 = F_28 ( V_31 , 0 , V_17 , V_8 ) ;
if ( V_33 != V_8 ) {
if ( V_33 > 0 )
V_33 = - V_36 ;
goto V_37;
}
V_33 = F_29 ( V_31 , V_17 , V_8 ) ;
if ( V_33 )
goto V_37;
V_32 -> V_9 = V_17 ;
V_32 -> V_8 = V_8 ;
return 0 ;
V_37:
F_30 ( V_17 ) ;
return V_33 ;
}
static int F_31 ( struct V_38 * V_38 ,
struct V_13 * V_17 )
{
int V_39 , V_40 ;
int V_33 = - V_41 ;
char * V_42 ;
V_42 = F_32 () ;
if ( ! V_42 )
return - V_29 ;
for ( V_39 = 0 ; V_39 < F_33 ( V_43 ) ; V_39 ++ ) {
struct V_31 * V_31 ;
if ( ! V_43 [ V_39 ] [ 0 ] )
continue;
V_40 = snprintf ( V_42 , V_44 , L_2 ,
V_43 [ V_39 ] , V_17 -> V_19 ) ;
if ( V_40 >= V_44 ) {
V_33 = - V_45 ;
break;
}
V_31 = F_34 ( V_42 , V_46 , 0 ) ;
if ( F_35 ( V_31 ) )
continue;
V_33 = F_23 ( V_31 , V_17 ) ;
F_36 ( V_31 ) ;
if ( V_33 )
F_37 ( V_38 , L_3 ,
V_42 , V_33 ) ;
else
break;
}
F_38 ( V_42 ) ;
if ( ! V_33 ) {
F_39 ( V_38 , L_4 ,
V_17 -> V_19 ) ;
F_40 ( & V_47 ) ;
F_41 ( V_48 , & V_17 -> V_49 ) ;
F_42 ( & V_17 -> V_21 ) ;
F_43 ( & V_47 ) ;
}
return V_33 ;
}
static void F_44 ( const struct V_1 * V_2 )
{
if ( ! V_2 -> V_50 ) {
F_30 ( V_2 -> V_9 ) ;
return;
}
F_21 ( V_2 -> V_50 ) ;
}
static void F_45 ( struct V_13 * V_17 , struct V_1 * V_2 )
{
V_2 -> V_50 = V_17 ;
#ifdef F_10
V_2 -> V_51 = V_17 -> V_51 ;
#endif
V_2 -> V_8 = V_17 -> V_8 ;
V_2 -> V_9 = V_17 -> V_9 ;
F_12 ( L_5 ,
V_23 , V_17 -> V_19 , V_17 , V_17 -> V_9 ,
( unsigned int ) V_17 -> V_8 ) ;
}
static void F_46 ( struct V_38 * V_52 , void * V_53 )
{
struct V_54 * V_55 = V_53 ;
if ( V_55 -> V_56 == ( unsigned long ) & V_25 )
F_12 ( L_6 ,
V_23 , V_55 -> V_3 , V_53 ) ;
F_47 ( V_55 -> V_3 ) ;
}
static int F_48 ( struct V_38 * V_52 , void * V_53 ,
void * V_57 )
{
struct V_54 * V_55 = V_53 ;
return ( V_55 -> V_56 == ( unsigned long ) & V_25 ) &&
! strcmp ( V_55 -> V_3 , V_57 ) ;
}
static struct V_54 * F_49 ( struct V_38 * V_52 ,
const char * V_3 )
{
struct V_54 * V_55 ;
V_55 = F_50 ( V_52 , F_46 ,
F_48 , ( void * ) V_3 ) ;
return V_55 ;
}
static int F_51 ( struct V_38 * V_52 , const char * V_3 )
{
struct V_54 * V_55 ;
V_55 = F_49 ( V_52 , V_3 ) ;
if ( V_55 )
return 1 ;
V_55 = F_52 ( F_46 , sizeof( struct V_54 ) ,
V_58 ) ;
if ( ! V_55 )
return - V_29 ;
V_55 -> V_3 = F_6 ( V_3 , V_58 ) ;
if ( ! V_55 -> V_3 ) {
F_53 ( V_55 ) ;
return - V_29 ;
}
V_55 -> V_56 = ( unsigned long ) & V_25 ;
F_54 ( V_52 , V_55 ) ;
return 0 ;
}
static int F_51 ( struct V_38 * V_52 , const char * V_3 )
{
return 0 ;
}
static struct V_59 * F_55 ( struct V_38 * V_52 )
{
return F_56 ( V_52 , struct V_59 , V_52 ) ;
}
static void F_57 ( struct V_13 * V_17 )
{
if ( F_58 ( V_48 , & V_17 -> V_49 ) )
return;
F_59 ( & V_17 -> V_22 ) ;
F_41 ( V_60 , & V_17 -> V_49 ) ;
F_42 ( & V_17 -> V_21 ) ;
}
static void F_60 ( struct V_59 * V_61 )
{
struct V_13 * V_17 = V_61 -> V_17 ;
F_57 ( V_17 ) ;
V_61 -> V_17 = NULL ;
}
static int F_61 ( struct V_62 * V_63 ,
unsigned long V_64 , void * V_65 )
{
F_40 ( & V_47 ) ;
while ( ! F_62 ( & V_66 ) )
F_57 ( F_63 ( & V_66 ,
struct V_13 ,
V_22 ) ) ;
F_43 ( & V_47 ) ;
return V_67 ;
}
static T_1 F_64 ( struct V_68 * V_68 , struct V_69 * V_70 ,
char * V_17 )
{
return sprintf ( V_17 , L_7 , V_10 ) ;
}
static T_1 F_65 ( struct V_68 * V_68 , struct V_69 * V_70 ,
const char * V_17 , T_2 V_71 )
{
V_10 = F_66 ( V_17 , NULL , 10 ) ;
if ( V_10 < 0 )
V_10 = 0 ;
return V_71 ;
}
static void F_67 ( struct V_38 * V_52 )
{
struct V_59 * V_61 = F_55 ( V_52 ) ;
F_7 ( V_61 ) ;
}
static int F_68 ( struct V_59 * V_61 , struct V_72 * V_73 )
{
if ( F_69 ( V_73 , L_8 , V_61 -> V_17 -> V_19 ) )
return - V_29 ;
if ( F_69 ( V_73 , L_9 , V_10 ) )
return - V_29 ;
if ( F_69 ( V_73 , L_10 , V_61 -> V_74 ) )
return - V_29 ;
return 0 ;
}
static int F_70 ( struct V_38 * V_52 , struct V_72 * V_73 )
{
struct V_59 * V_61 = F_55 ( V_52 ) ;
int V_75 = 0 ;
F_40 ( & V_47 ) ;
if ( V_61 -> V_17 )
V_75 = F_68 ( V_61 , V_73 ) ;
F_43 ( & V_47 ) ;
return V_75 ;
}
static T_1 F_71 ( struct V_38 * V_52 ,
struct V_76 * V_70 , char * V_17 )
{
struct V_59 * V_61 = F_55 ( V_52 ) ;
int V_77 = 0 ;
F_40 ( & V_47 ) ;
if ( V_61 -> V_17 )
V_77 = F_58 ( V_78 , & V_61 -> V_17 -> V_49 ) ;
F_43 ( & V_47 ) ;
return sprintf ( V_17 , L_7 , V_77 ) ;
}
static int F_72 ( struct V_13 * V_17 )
{
if ( ! V_17 -> V_79 )
return 0 ;
F_73 ( V_17 -> V_9 ) ;
V_17 -> V_9 = F_74 ( V_17 -> V_51 , V_17 -> V_80 , 0 , V_81 ) ;
if ( ! V_17 -> V_9 )
return - V_29 ;
return 0 ;
}
static T_1 F_75 ( struct V_38 * V_52 ,
struct V_76 * V_70 ,
const char * V_17 , T_2 V_71 )
{
struct V_59 * V_61 = F_55 ( V_52 ) ;
struct V_13 * V_32 ;
T_1 V_82 = V_71 ;
int V_77 = F_66 ( V_17 , NULL , 10 ) ;
int V_39 ;
F_40 ( & V_47 ) ;
V_32 = V_61 -> V_17 ;
if ( ! V_32 )
goto V_83;
switch ( V_77 ) {
case 1 :
if ( ! F_58 ( V_48 , & V_32 -> V_49 ) ) {
for ( V_39 = 0 ; V_39 < V_32 -> V_80 ; V_39 ++ )
F_76 ( V_32 -> V_51 [ V_39 ] ) ;
F_7 ( V_32 -> V_51 ) ;
V_32 -> V_51 = NULL ;
V_32 -> V_84 = 0 ;
V_32 -> V_80 = 0 ;
F_41 ( V_78 , & V_32 -> V_49 ) ;
}
break;
case 0 :
if ( F_58 ( V_78 , & V_32 -> V_49 ) ) {
int V_33 ;
F_41 ( V_48 , & V_32 -> V_49 ) ;
F_77 ( V_78 , & V_32 -> V_49 ) ;
V_33 = F_72 ( V_32 ) ;
if ( V_33 )
F_78 ( V_52 , L_11 ,
V_23 ) ;
else
V_33 = F_29 ( NULL ,
V_32 -> V_9 , V_32 -> V_8 ) ;
F_59 ( & V_32 -> V_22 ) ;
if ( V_33 ) {
F_41 ( V_60 , & V_32 -> V_49 ) ;
V_82 = V_33 ;
}
F_42 ( & V_32 -> V_21 ) ;
break;
}
default:
F_78 ( V_52 , L_12 , V_23 , V_77 ) ;
case - 1 :
F_60 ( V_61 ) ;
break;
}
V_83:
F_43 ( & V_47 ) ;
return V_82 ;
}
static T_1 F_79 ( struct V_31 * V_85 , struct V_86 * V_87 ,
struct V_88 * V_89 ,
char * V_90 , T_3 V_91 , T_2 V_71 )
{
struct V_38 * V_52 = F_80 ( V_87 ) ;
struct V_59 * V_61 = F_55 ( V_52 ) ;
struct V_13 * V_17 ;
T_1 V_92 ;
F_40 ( & V_47 ) ;
V_17 = V_61 -> V_17 ;
if ( ! V_17 || F_58 ( V_48 , & V_17 -> V_49 ) ) {
V_92 = - V_93 ;
goto V_83;
}
if ( V_91 > V_17 -> V_8 ) {
V_92 = 0 ;
goto V_83;
}
if ( V_71 > V_17 -> V_8 - V_91 )
V_71 = V_17 -> V_8 - V_91 ;
V_92 = V_71 ;
while ( V_71 ) {
void * V_94 ;
int V_95 = V_91 >> V_96 ;
int V_97 = V_91 & ( V_98 - 1 ) ;
int V_99 = F_81 ( T_2 , V_98 - V_97 , V_71 ) ;
V_94 = F_82 ( V_17 -> V_51 [ V_95 ] ) ;
memcpy ( V_90 , V_94 + V_97 , V_99 ) ;
F_83 ( V_17 -> V_51 [ V_95 ] ) ;
V_90 += V_99 ;
V_91 += V_99 ;
V_71 -= V_99 ;
}
V_83:
F_43 ( & V_47 ) ;
return V_92 ;
}
static int F_84 ( struct V_59 * V_61 , int V_100 )
{
struct V_13 * V_17 = V_61 -> V_17 ;
int V_101 = F_85 ( V_100 ) >> V_96 ;
if ( V_17 -> V_84 < V_101 ) {
int V_102 = F_86 ( V_101 ,
V_17 -> V_84 * 2 ) ;
struct V_103 * * V_104 ;
V_104 = F_87 ( V_102 * sizeof( void * ) ,
V_58 ) ;
if ( ! V_104 ) {
F_60 ( V_61 ) ;
return - V_29 ;
}
memcpy ( V_104 , V_17 -> V_51 ,
V_17 -> V_84 * sizeof( void * ) ) ;
memset ( & V_104 [ V_17 -> V_84 ] , 0 , sizeof( void * ) *
( V_102 - V_17 -> V_84 ) ) ;
F_7 ( V_17 -> V_51 ) ;
V_17 -> V_51 = V_104 ;
V_17 -> V_84 = V_102 ;
}
while ( V_17 -> V_80 < V_101 ) {
V_17 -> V_51 [ V_17 -> V_80 ] =
F_88 ( V_58 | V_105 ) ;
if ( ! V_17 -> V_51 [ V_17 -> V_80 ] ) {
F_60 ( V_61 ) ;
return - V_29 ;
}
V_17 -> V_80 ++ ;
}
return 0 ;
}
static T_1 F_89 ( struct V_31 * V_85 , struct V_86 * V_87 ,
struct V_88 * V_89 ,
char * V_90 , T_3 V_91 , T_2 V_71 )
{
struct V_38 * V_52 = F_80 ( V_87 ) ;
struct V_59 * V_61 = F_55 ( V_52 ) ;
struct V_13 * V_17 ;
T_1 V_106 ;
if ( ! F_90 ( V_107 ) )
return - V_108 ;
F_40 ( & V_47 ) ;
V_17 = V_61 -> V_17 ;
if ( ! V_17 || F_58 ( V_48 , & V_17 -> V_49 ) ) {
V_106 = - V_93 ;
goto V_83;
}
V_106 = F_84 ( V_61 , V_91 + V_71 ) ;
if ( V_106 )
goto V_83;
V_106 = V_71 ;
while ( V_71 ) {
void * V_94 ;
int V_95 = V_91 >> V_96 ;
int V_97 = V_91 & ( V_98 - 1 ) ;
int V_99 = F_81 ( T_2 , V_98 - V_97 , V_71 ) ;
V_94 = F_82 ( V_17 -> V_51 [ V_95 ] ) ;
memcpy ( V_94 + V_97 , V_90 , V_99 ) ;
F_83 ( V_17 -> V_51 [ V_95 ] ) ;
V_90 += V_99 ;
V_91 += V_99 ;
V_71 -= V_99 ;
}
V_17 -> V_8 = F_91 ( T_2 , V_91 , V_17 -> V_8 ) ;
V_83:
F_43 ( & V_47 ) ;
return V_106 ;
}
static struct V_59 *
F_92 ( struct V_1 * V_1 , const char * V_14 ,
struct V_38 * V_38 , unsigned int V_109 )
{
struct V_59 * V_61 ;
struct V_38 * V_110 ;
V_61 = F_5 ( sizeof( * V_61 ) , V_58 ) ;
if ( ! V_61 ) {
V_61 = F_93 ( - V_29 ) ;
goto exit;
}
V_61 -> V_74 = ! ! ( V_109 & V_111 ) ;
V_61 -> V_2 = V_1 ;
V_110 = & V_61 -> V_52 ;
F_94 ( V_110 ) ;
F_95 ( V_110 , L_13 , V_14 ) ;
V_110 -> V_112 = V_38 ;
V_110 -> V_68 = & V_113 ;
V_110 -> V_114 = V_115 ;
exit:
return V_61 ;
}
static int F_96 ( struct V_59 * V_61 ,
unsigned int V_109 , long V_116 )
{
int V_106 = 0 ;
struct V_38 * V_110 = & V_61 -> V_52 ;
struct V_13 * V_17 = V_61 -> V_17 ;
V_17 -> V_79 = true ;
F_97 ( V_110 , true ) ;
V_106 = F_98 ( V_110 ) ;
if ( V_106 ) {
F_78 ( V_110 , L_14 , V_23 ) ;
goto V_117;
}
F_40 ( & V_47 ) ;
F_19 ( & V_17 -> V_22 , & V_66 ) ;
F_43 ( & V_47 ) ;
if ( V_109 & V_118 ) {
V_17 -> V_119 = true ;
F_97 ( V_110 , false ) ;
F_39 ( V_110 , L_15 , V_17 -> V_19 ) ;
F_99 ( & V_61 -> V_52 . V_87 , V_120 ) ;
} else {
V_116 = V_12 ;
}
V_106 = F_100 ( & V_17 -> V_21 ,
V_116 ) ;
if ( V_106 == - V_121 || ! V_106 ) {
F_40 ( & V_47 ) ;
F_60 ( V_61 ) ;
F_43 ( & V_47 ) ;
} else if ( V_106 > 0 ) {
V_106 = 0 ;
}
if ( F_101 ( V_17 ) )
V_106 = - V_122 ;
else if ( ! V_17 -> V_9 )
V_106 = - V_29 ;
F_102 ( V_110 ) ;
V_117:
F_103 ( V_110 ) ;
return V_106 ;
}
static int F_104 ( struct V_1 * V_1 ,
const char * V_3 , struct V_38 * V_38 ,
unsigned int V_109 , long V_116 )
{
struct V_59 * V_61 ;
V_61 = F_92 ( V_1 , V_3 , V_38 , V_109 ) ;
if ( F_35 ( V_61 ) )
return F_105 ( V_61 ) ;
V_61 -> V_17 = V_1 -> V_50 ;
return F_96 ( V_61 , V_109 , V_116 ) ;
}
static void F_106 ( void )
{
struct V_13 * V_17 ;
struct V_13 * V_123 ;
F_40 ( & V_47 ) ;
F_107 (buf, next, &pending_fw_head, pending_list) {
if ( ! V_17 -> V_119 )
F_57 ( V_17 ) ;
}
F_43 ( & V_47 ) ;
}
static inline int
F_104 ( struct V_1 * V_1 , const char * V_3 ,
struct V_38 * V_38 , unsigned int V_109 ,
long V_116 )
{
return - V_41 ;
}
static inline void F_106 ( void ) { }
static int F_108 ( struct V_13 * V_17 )
{
int V_124 = 0 ;
F_40 ( & V_47 ) ;
while ( ! F_58 ( V_48 , & V_17 -> V_49 ) ) {
if ( F_101 ( V_17 ) ) {
V_124 = - V_41 ;
break;
}
F_43 ( & V_47 ) ;
V_124 = F_109 ( & V_17 -> V_21 ) ;
F_40 ( & V_47 ) ;
}
F_43 ( & V_47 ) ;
return V_124 ;
}
static int
F_110 ( struct V_1 * * V_125 , const char * V_3 ,
struct V_38 * V_38 )
{
struct V_1 * V_1 ;
struct V_13 * V_17 ;
int V_124 ;
* V_125 = V_1 = F_5 ( sizeof( * V_1 ) , V_58 ) ;
if ( ! V_1 ) {
F_78 ( V_38 , L_16 ,
V_23 ) ;
return - V_29 ;
}
if ( F_1 ( V_1 , V_3 ) ) {
F_39 ( V_38 , L_17 , V_3 ) ;
return 0 ;
}
V_124 = F_15 ( V_3 , & V_25 , & V_17 ) ;
V_1 -> V_50 = V_17 ;
if ( V_124 > 0 ) {
V_124 = F_108 ( V_17 ) ;
if ( ! V_124 ) {
F_45 ( V_17 , V_1 ) ;
return 0 ;
}
}
if ( V_124 < 0 )
return V_124 ;
return 1 ;
}
static int F_111 ( struct V_1 * V_2 , struct V_38 * V_38 ,
unsigned int V_109 )
{
struct V_13 * V_17 = V_2 -> V_50 ;
F_40 ( & V_47 ) ;
if ( ! V_17 -> V_8 || F_101 ( V_17 ) ) {
F_43 ( & V_47 ) ;
return - V_41 ;
}
if ( V_38 && ( V_109 & V_118 ) )
F_51 ( V_38 , V_17 -> V_19 ) ;
if ( V_17 -> V_16 -> V_126 == V_127 ) {
if ( F_112 ( V_17 -> V_19 ) )
F_17 ( & V_17 -> V_20 ) ;
}
F_45 ( V_17 , V_2 ) ;
F_43 ( & V_47 ) ;
return 0 ;
}
static int
F_113 ( const struct V_1 * * V_125 , const char * V_3 ,
struct V_38 * V_38 , unsigned int V_109 )
{
struct V_1 * V_2 ;
long V_116 ;
int V_124 ;
if ( ! V_125 )
return - V_35 ;
if ( ! V_3 || V_3 [ 0 ] == '\0' )
return - V_35 ;
V_124 = F_110 ( & V_2 , V_3 , V_38 ) ;
if ( V_124 <= 0 )
goto V_83;
V_124 = 0 ;
V_116 = F_3 () ;
if ( V_109 & V_111 ) {
V_116 = F_114 ( V_116 ) ;
if ( ! V_116 ) {
F_39 ( V_38 , L_18 ,
V_3 ) ;
V_124 = - V_128 ;
goto V_83;
}
} else {
V_124 = F_115 () ;
if ( F_116 ( V_124 ) ) {
F_78 ( V_38 , L_19 ,
V_3 ) ;
goto V_83;
}
}
V_124 = F_31 ( V_38 , V_2 -> V_50 ) ;
if ( V_124 ) {
if ( ! ( V_109 & V_129 ) )
F_37 ( V_38 ,
L_20 ,
V_3 , V_124 ) ;
if ( V_109 & V_130 ) {
F_37 ( V_38 , L_21 ) ;
V_124 = F_104 ( V_2 , V_3 , V_38 ,
V_109 , V_116 ) ;
}
}
if ( ! V_124 )
V_124 = F_111 ( V_2 , V_38 , V_109 ) ;
F_117 () ;
V_83:
if ( V_124 < 0 ) {
F_118 ( V_2 ) ;
V_2 = NULL ;
}
* V_125 = V_2 ;
return V_124 ;
}
int
F_119 ( const struct V_1 * * V_125 , const char * V_3 ,
struct V_38 * V_38 )
{
int V_124 ;
F_120 ( V_131 ) ;
V_124 = F_113 ( V_125 , V_3 , V_38 ,
V_118 | V_132 ) ;
F_121 ( V_131 ) ;
return V_124 ;
}
int F_122 ( const struct V_1 * * V_125 ,
const char * V_3 , struct V_38 * V_38 )
{
int V_124 ;
F_120 ( V_131 ) ;
V_124 = F_113 ( V_125 , V_3 , V_38 ,
V_118 | V_129 ) ;
F_121 ( V_131 ) ;
return V_124 ;
}
void F_118 ( const struct V_1 * V_2 )
{
if ( V_2 ) {
if ( ! F_2 ( V_2 ) )
F_44 ( V_2 ) ;
F_7 ( V_2 ) ;
}
}
static void F_123 ( struct V_133 * V_134 )
{
struct V_135 * V_136 ;
const struct V_1 * V_2 ;
V_136 = F_56 ( V_134 , struct V_135 , V_134 ) ;
F_113 ( & V_2 , V_136 -> V_3 , V_136 -> V_38 ,
V_136 -> V_109 ) ;
V_136 -> V_137 ( V_2 , V_136 -> V_138 ) ;
F_103 ( V_136 -> V_38 ) ;
F_121 ( V_136 -> V_139 ) ;
F_47 ( V_136 -> V_3 ) ;
F_7 ( V_136 ) ;
}
int
F_124 (
struct V_139 * V_139 , bool V_140 ,
const char * V_3 , struct V_38 * V_38 , T_4 V_141 , void * V_138 ,
void (* V_137)( const struct V_1 * V_2 , void * V_138 ) )
{
struct V_135 * V_136 ;
V_136 = F_5 ( sizeof( struct V_135 ) , V_141 ) ;
if ( ! V_136 )
return - V_29 ;
V_136 -> V_139 = V_139 ;
V_136 -> V_3 = F_6 ( V_3 , V_141 ) ;
if ( ! V_136 -> V_3 ) {
F_7 ( V_136 ) ;
return - V_29 ;
}
V_136 -> V_38 = V_38 ;
V_136 -> V_138 = V_138 ;
V_136 -> V_137 = V_137 ;
V_136 -> V_109 = V_111 | V_132 |
( V_140 ? V_118 : V_130 ) ;
if ( ! F_125 ( V_139 ) ) {
F_47 ( V_136 -> V_3 ) ;
F_7 ( V_136 ) ;
return - V_142 ;
}
F_126 ( V_136 -> V_38 ) ;
F_127 ( & V_136 -> V_134 , F_123 ) ;
F_128 ( & V_136 -> V_134 ) ;
return 0 ;
}
static int F_129 ( const char * V_14 )
{
int V_124 ;
const struct V_1 * V_2 ;
F_12 ( L_22 , V_23 , V_14 ) ;
V_124 = F_119 ( & V_2 , V_14 , NULL ) ;
if ( ! V_124 )
F_7 ( V_2 ) ;
F_12 ( L_23 , V_23 , V_14 , V_124 ) ;
return V_124 ;
}
static struct V_13 * F_130 ( const char * V_14 )
{
struct V_13 * V_24 ;
struct V_15 * V_16 = & V_25 ;
F_16 ( & V_16 -> V_26 ) ;
V_24 = F_13 ( V_14 ) ;
F_18 ( & V_16 -> V_26 ) ;
return V_24 ;
}
static int F_131 ( const char * V_14 )
{
struct V_13 * V_17 ;
struct V_1 V_2 ;
F_12 ( L_22 , V_23 , V_14 ) ;
if ( F_1 ( & V_2 , V_14 ) )
return 0 ;
V_17 = F_130 ( V_14 ) ;
if ( V_17 ) {
F_21 ( V_17 ) ;
return 0 ;
}
return - V_35 ;
}
static struct V_143 * F_132 ( const char * V_3 )
{
struct V_143 * V_144 ;
V_144 = F_5 ( sizeof( * V_144 ) , V_18 ) ;
if ( ! V_144 )
goto exit;
V_144 -> V_3 = F_6 ( V_3 , V_18 ) ;
if ( ! V_144 -> V_3 ) {
F_7 ( V_144 ) ;
V_144 = NULL ;
goto exit;
}
exit:
return V_144 ;
}
static int F_133 ( const char * V_3 )
{
struct V_15 * V_16 = & V_25 ;
struct V_143 * V_144 ;
F_14 (fce, &fwc->fw_names, list) {
if ( ! strcmp ( V_144 -> V_3 , V_3 ) )
return 1 ;
}
return 0 ;
}
static int F_112 ( const char * V_3 )
{
struct V_15 * V_16 = & V_25 ;
struct V_143 * V_144 ;
int V_124 = 0 ;
F_16 ( & V_16 -> V_145 ) ;
if ( F_133 ( V_3 ) )
goto V_146;
V_144 = F_132 ( V_3 ) ;
if ( V_144 ) {
V_124 = 1 ;
F_19 ( & V_144 -> V_27 , & V_16 -> V_147 ) ;
F_12 ( L_24 , V_23 , V_3 ) ;
}
V_146:
F_18 ( & V_16 -> V_145 ) ;
return V_124 ;
}
static void F_134 ( struct V_143 * V_144 )
{
F_47 ( V_144 -> V_3 ) ;
F_7 ( V_144 ) ;
}
static void F_135 ( void * V_148 ,
T_5 V_149 )
{
struct V_143 * V_144 = V_148 ;
struct V_15 * V_16 = & V_25 ;
int V_124 ;
V_124 = F_129 ( V_144 -> V_3 ) ;
if ( V_124 ) {
F_16 ( & V_16 -> V_145 ) ;
F_136 ( & V_144 -> V_27 ) ;
F_18 ( & V_16 -> V_145 ) ;
F_134 ( V_144 ) ;
}
}
static void F_137 ( struct V_38 * V_52 , void * V_53 ,
void * V_9 )
{
struct V_54 * V_55 = V_53 ;
const char * V_14 = V_55 -> V_3 ;
struct V_150 * V_28 = V_9 ;
struct V_143 * V_144 ;
V_144 = F_132 ( V_14 ) ;
if ( V_144 )
F_19 ( & V_144 -> V_27 , V_28 ) ;
}
static int F_138 ( struct V_38 * V_52 , void * V_53 ,
void * V_57 )
{
struct V_54 * V_55 = V_53 ;
return ( V_55 -> V_56 == ( unsigned long ) V_57 ) ;
}
static void F_139 ( struct V_38 * V_52 , void * V_9 )
{
F_140 ( V_151 ) ;
struct V_143 * V_144 ;
struct V_143 * V_152 ;
struct V_15 * V_16 = & V_25 ;
F_141 ( V_52 , F_46 ,
F_138 , & V_25 ,
F_137 , & V_151 ) ;
F_107 (fce, fce_next, &todo, list) {
F_136 ( & V_144 -> V_27 ) ;
F_16 ( & V_16 -> V_145 ) ;
if ( ! F_133 ( V_144 -> V_3 ) ) {
F_19 ( & V_144 -> V_27 , & V_16 -> V_147 ) ;
} else {
F_134 ( V_144 ) ;
V_144 = NULL ;
}
F_18 ( & V_16 -> V_145 ) ;
if ( V_144 )
F_142 ( F_135 ,
( void * ) V_144 ,
& V_153 ) ;
}
}
static void F_143 ( void )
{
struct V_15 * V_16 = & V_25 ;
struct V_143 * V_144 ;
F_16 ( & V_16 -> V_145 ) ;
while ( ! F_62 ( & V_16 -> V_147 ) ) {
V_144 = F_144 ( V_16 -> V_147 . V_123 ,
struct V_143 , V_27 ) ;
F_136 ( & V_144 -> V_27 ) ;
F_18 ( & V_16 -> V_145 ) ;
F_131 ( V_144 -> V_3 ) ;
F_134 ( V_144 ) ;
F_16 ( & V_16 -> V_145 ) ;
}
F_18 ( & V_16 -> V_145 ) ;
}
static void F_145 ( void )
{
struct V_15 * V_16 = & V_25 ;
int V_154 ;
F_146 ( V_155 ) ;
F_12 ( L_25 , V_23 ) ;
F_147 ( & V_16 -> V_134 ) ;
V_154 = V_10 ;
V_10 = 10 ;
F_40 ( & V_47 ) ;
V_16 -> V_126 = V_127 ;
F_148 ( NULL , F_139 ) ;
F_43 ( & V_47 ) ;
F_149 ( & V_153 ) ;
V_10 = V_154 ;
}
static void F_150 ( void )
{
F_12 ( L_25 , V_23 ) ;
F_143 () ;
}
static void F_151 ( struct V_133 * V_134 )
{
F_150 () ;
}
static void F_152 ( unsigned long V_156 )
{
F_153 ( V_157 , & V_25 . V_134 ,
F_154 ( V_156 ) ) ;
}
static int F_155 ( struct V_62 * V_158 ,
unsigned long V_159 , void * V_160 )
{
switch ( V_159 ) {
case V_161 :
case V_162 :
case V_163 :
F_106 () ;
F_145 () ;
break;
case V_164 :
case V_165 :
case V_166 :
F_40 ( & V_47 ) ;
V_25 . V_126 = V_167 ;
F_43 ( & V_47 ) ;
F_152 ( 10 * V_168 ) ;
break;
}
return 0 ;
}
static int F_156 ( void )
{
V_25 . V_126 = V_167 ;
return 0 ;
}
static int F_112 ( const char * V_3 )
{
return 0 ;
}
static void T_6 F_157 ( void )
{
F_158 ( & V_25 . V_26 ) ;
F_11 ( & V_25 . V_28 ) ;
V_25 . V_126 = V_167 ;
#ifdef F_159
F_158 ( & V_25 . V_145 ) ;
F_11 ( & V_25 . V_147 ) ;
F_160 ( & V_25 . V_134 ,
F_151 ) ;
V_25 . V_169 . V_170 = F_155 ;
F_161 ( & V_25 . V_169 ) ;
F_162 ( & V_171 ) ;
#endif
}
static int T_6 F_163 ( void )
{
F_157 () ;
#ifdef F_10
F_164 ( & V_172 ) ;
return F_165 ( & V_113 ) ;
#else
return 0 ;
#endif
}
static void T_7 F_166 ( void )
{
#ifdef F_159
F_167 ( & V_171 ) ;
F_168 ( & V_25 . V_169 ) ;
#endif
#ifdef F_10
F_169 ( & V_172 ) ;
F_170 ( & V_113 ) ;
#endif
}
