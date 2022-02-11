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
static void F_23 ( struct V_31 * V_31 ,
struct V_13 * V_17 )
{
F_24 ( & V_32 ) ;
F_25 ( V_33 , & V_17 -> V_34 ) ;
F_26 ( & V_17 -> V_21 ) ;
F_27 ( & V_32 ) ;
}
static int F_28 ( struct V_31 * V_31 ,
struct V_13 * V_17 )
{
T_1 V_8 ;
int V_35 , V_36 ;
int V_37 = - V_38 ;
char * V_39 ;
V_39 = F_29 () ;
if ( ! V_39 )
return - V_29 ;
for ( V_35 = 0 ; V_35 < F_30 ( V_40 ) ; V_35 ++ ) {
if ( ! V_40 [ V_35 ] [ 0 ] )
continue;
V_36 = snprintf ( V_39 , V_41 , L_2 ,
V_40 [ V_35 ] , V_17 -> V_19 ) ;
if ( V_36 >= V_41 ) {
V_37 = - V_42 ;
break;
}
V_17 -> V_8 = 0 ;
V_37 = F_31 ( V_39 , & V_17 -> V_9 , & V_8 ,
V_43 , V_44 ) ;
if ( V_37 ) {
if ( V_37 == - V_38 )
F_32 ( V_31 , L_3 ,
V_39 , V_37 ) ;
else
F_33 ( V_31 , L_3 ,
V_39 , V_37 ) ;
continue;
}
F_32 ( V_31 , L_4 , V_17 -> V_19 ) ;
V_17 -> V_8 = V_8 ;
F_23 ( V_31 , V_17 ) ;
break;
}
F_34 ( V_39 ) ;
return V_37 ;
}
static void F_35 ( const struct V_1 * V_2 )
{
if ( ! V_2 -> V_45 ) {
F_36 ( V_2 -> V_9 ) ;
return;
}
F_21 ( V_2 -> V_45 ) ;
}
static void F_37 ( struct V_13 * V_17 , struct V_1 * V_2 )
{
V_2 -> V_45 = V_17 ;
#ifdef F_10
V_2 -> V_46 = V_17 -> V_46 ;
#endif
V_2 -> V_8 = V_17 -> V_8 ;
V_2 -> V_9 = V_17 -> V_9 ;
F_12 ( L_5 ,
V_23 , V_17 -> V_19 , V_17 , V_17 -> V_9 ,
( unsigned int ) V_17 -> V_8 ) ;
}
static void F_38 ( struct V_31 * V_47 , void * V_48 )
{
struct V_49 * V_50 = V_48 ;
if ( V_50 -> V_51 == ( unsigned long ) & V_25 )
F_12 ( L_6 ,
V_23 , V_50 -> V_3 , V_48 ) ;
F_39 ( V_50 -> V_3 ) ;
}
static int F_40 ( struct V_31 * V_47 , void * V_48 ,
void * V_52 )
{
struct V_49 * V_50 = V_48 ;
return ( V_50 -> V_51 == ( unsigned long ) & V_25 ) &&
! strcmp ( V_50 -> V_3 , V_52 ) ;
}
static struct V_49 * F_41 ( struct V_31 * V_47 ,
const char * V_3 )
{
struct V_49 * V_50 ;
V_50 = F_42 ( V_47 , F_38 ,
F_40 , ( void * ) V_3 ) ;
return V_50 ;
}
static int F_43 ( struct V_31 * V_47 , const char * V_3 )
{
struct V_49 * V_50 ;
V_50 = F_41 ( V_47 , V_3 ) ;
if ( V_50 )
return 1 ;
V_50 = F_44 ( F_38 , sizeof( struct V_49 ) ,
V_53 ) ;
if ( ! V_50 )
return - V_29 ;
V_50 -> V_3 = F_6 ( V_3 , V_53 ) ;
if ( ! V_50 -> V_3 ) {
F_45 ( V_50 ) ;
return - V_29 ;
}
V_50 -> V_51 = ( unsigned long ) & V_25 ;
F_46 ( V_47 , V_50 ) ;
return 0 ;
}
static int F_43 ( struct V_31 * V_47 , const char * V_3 )
{
return 0 ;
}
static struct V_54 * F_47 ( struct V_31 * V_47 )
{
return F_48 ( V_47 , struct V_54 , V_47 ) ;
}
static void F_49 ( struct V_13 * V_17 )
{
if ( F_50 ( V_33 , & V_17 -> V_34 ) )
return;
F_51 ( & V_17 -> V_22 ) ;
F_25 ( V_55 , & V_17 -> V_34 ) ;
F_26 ( & V_17 -> V_21 ) ;
}
static void F_52 ( struct V_54 * V_56 )
{
struct V_13 * V_17 = V_56 -> V_17 ;
F_49 ( V_17 ) ;
V_56 -> V_17 = NULL ;
}
static int F_53 ( struct V_57 * V_58 ,
unsigned long V_59 , void * V_60 )
{
F_24 ( & V_32 ) ;
while ( ! F_54 ( & V_61 ) )
F_49 ( F_55 ( & V_61 ,
struct V_13 ,
V_22 ) ) ;
F_27 ( & V_32 ) ;
return V_62 ;
}
static T_2 F_56 ( struct V_63 * V_63 , struct V_64 * V_65 ,
char * V_17 )
{
return sprintf ( V_17 , L_7 , V_10 ) ;
}
static T_2 F_57 ( struct V_63 * V_63 , struct V_64 * V_65 ,
const char * V_17 , T_3 V_66 )
{
V_10 = F_58 ( V_17 , NULL , 10 ) ;
if ( V_10 < 0 )
V_10 = 0 ;
return V_66 ;
}
static void F_59 ( struct V_31 * V_47 )
{
struct V_54 * V_56 = F_47 ( V_47 ) ;
F_7 ( V_56 ) ;
}
static int F_60 ( struct V_54 * V_56 , struct V_67 * V_68 )
{
if ( F_61 ( V_68 , L_8 , V_56 -> V_17 -> V_19 ) )
return - V_29 ;
if ( F_61 ( V_68 , L_9 , V_10 ) )
return - V_29 ;
if ( F_61 ( V_68 , L_10 , V_56 -> V_69 ) )
return - V_29 ;
return 0 ;
}
static int F_62 ( struct V_31 * V_47 , struct V_67 * V_68 )
{
struct V_54 * V_56 = F_47 ( V_47 ) ;
int V_70 = 0 ;
F_24 ( & V_32 ) ;
if ( V_56 -> V_17 )
V_70 = F_60 ( V_56 , V_68 ) ;
F_27 ( & V_32 ) ;
return V_70 ;
}
static T_2 F_63 ( struct V_31 * V_47 ,
struct V_71 * V_65 , char * V_17 )
{
struct V_54 * V_56 = F_47 ( V_47 ) ;
int V_72 = 0 ;
F_24 ( & V_32 ) ;
if ( V_56 -> V_17 )
V_72 = F_50 ( V_73 , & V_56 -> V_17 -> V_34 ) ;
F_27 ( & V_32 ) ;
return sprintf ( V_17 , L_7 , V_72 ) ;
}
static int F_64 ( struct V_13 * V_17 )
{
if ( ! V_17 -> V_74 )
return 0 ;
F_65 ( V_17 -> V_9 ) ;
V_17 -> V_9 = F_66 ( V_17 -> V_46 , V_17 -> V_75 , 0 , V_76 ) ;
if ( ! V_17 -> V_9 )
return - V_29 ;
return 0 ;
}
static T_2 F_67 ( struct V_31 * V_47 ,
struct V_71 * V_65 ,
const char * V_17 , T_3 V_66 )
{
struct V_54 * V_56 = F_47 ( V_47 ) ;
struct V_13 * V_77 ;
T_2 V_78 = V_66 ;
int V_72 = F_58 ( V_17 , NULL , 10 ) ;
int V_35 ;
F_24 ( & V_32 ) ;
V_77 = V_56 -> V_17 ;
if ( ! V_77 )
goto V_79;
switch ( V_72 ) {
case 1 :
if ( ! F_50 ( V_33 , & V_77 -> V_34 ) ) {
for ( V_35 = 0 ; V_35 < V_77 -> V_75 ; V_35 ++ )
F_68 ( V_77 -> V_46 [ V_35 ] ) ;
F_36 ( V_77 -> V_46 ) ;
V_77 -> V_46 = NULL ;
V_77 -> V_80 = 0 ;
V_77 -> V_75 = 0 ;
F_25 ( V_73 , & V_77 -> V_34 ) ;
}
break;
case 0 :
if ( F_50 ( V_73 , & V_77 -> V_34 ) ) {
int V_37 ;
F_25 ( V_33 , & V_77 -> V_34 ) ;
F_69 ( V_73 , & V_77 -> V_34 ) ;
V_37 = F_64 ( V_77 ) ;
if ( V_37 )
F_70 ( V_47 , L_11 ,
V_23 ) ;
else
V_37 = F_71 ( NULL ,
V_77 -> V_9 , V_77 -> V_8 ,
V_44 ) ;
F_51 ( & V_77 -> V_22 ) ;
if ( V_37 ) {
F_25 ( V_55 , & V_77 -> V_34 ) ;
V_78 = V_37 ;
}
F_26 ( & V_77 -> V_21 ) ;
break;
}
default:
F_70 ( V_47 , L_12 , V_23 , V_72 ) ;
case - 1 :
F_52 ( V_56 ) ;
break;
}
V_79:
F_27 ( & V_32 ) ;
return V_78 ;
}
static T_2 F_72 ( struct V_81 * V_82 , struct V_83 * V_84 ,
struct V_85 * V_86 ,
char * V_87 , T_1 V_88 , T_3 V_66 )
{
struct V_31 * V_47 = F_73 ( V_84 ) ;
struct V_54 * V_56 = F_47 ( V_47 ) ;
struct V_13 * V_17 ;
T_2 V_89 ;
F_24 ( & V_32 ) ;
V_17 = V_56 -> V_17 ;
if ( ! V_17 || F_50 ( V_33 , & V_17 -> V_34 ) ) {
V_89 = - V_90 ;
goto V_79;
}
if ( V_88 > V_17 -> V_8 ) {
V_89 = 0 ;
goto V_79;
}
if ( V_66 > V_17 -> V_8 - V_88 )
V_66 = V_17 -> V_8 - V_88 ;
V_89 = V_66 ;
while ( V_66 ) {
void * V_91 ;
int V_92 = V_88 >> V_93 ;
int V_94 = V_88 & ( V_95 - 1 ) ;
int V_96 = F_74 ( T_3 , V_95 - V_94 , V_66 ) ;
V_91 = F_75 ( V_17 -> V_46 [ V_92 ] ) ;
memcpy ( V_87 , V_91 + V_94 , V_96 ) ;
F_76 ( V_17 -> V_46 [ V_92 ] ) ;
V_87 += V_96 ;
V_88 += V_96 ;
V_66 -= V_96 ;
}
V_79:
F_27 ( & V_32 ) ;
return V_89 ;
}
static int F_77 ( struct V_54 * V_56 , int V_97 )
{
struct V_13 * V_17 = V_56 -> V_17 ;
int V_98 = F_78 ( V_97 ) >> V_93 ;
if ( V_17 -> V_80 < V_98 ) {
int V_99 = F_79 ( V_98 ,
V_17 -> V_80 * 2 ) ;
struct V_100 * * V_101 ;
V_101 = F_80 ( V_99 * sizeof( void * ) ) ;
if ( ! V_101 ) {
F_52 ( V_56 ) ;
return - V_29 ;
}
memcpy ( V_101 , V_17 -> V_46 ,
V_17 -> V_80 * sizeof( void * ) ) ;
memset ( & V_101 [ V_17 -> V_80 ] , 0 , sizeof( void * ) *
( V_99 - V_17 -> V_80 ) ) ;
F_36 ( V_17 -> V_46 ) ;
V_17 -> V_46 = V_101 ;
V_17 -> V_80 = V_99 ;
}
while ( V_17 -> V_75 < V_98 ) {
V_17 -> V_46 [ V_17 -> V_75 ] =
F_81 ( V_53 | V_102 ) ;
if ( ! V_17 -> V_46 [ V_17 -> V_75 ] ) {
F_52 ( V_56 ) ;
return - V_29 ;
}
V_17 -> V_75 ++ ;
}
return 0 ;
}
static T_2 F_82 ( struct V_81 * V_82 , struct V_83 * V_84 ,
struct V_85 * V_86 ,
char * V_87 , T_1 V_88 , T_3 V_66 )
{
struct V_31 * V_47 = F_73 ( V_84 ) ;
struct V_54 * V_56 = F_47 ( V_47 ) ;
struct V_13 * V_17 ;
T_2 V_103 ;
if ( ! F_83 ( V_104 ) )
return - V_105 ;
F_24 ( & V_32 ) ;
V_17 = V_56 -> V_17 ;
if ( ! V_17 || F_50 ( V_33 , & V_17 -> V_34 ) ) {
V_103 = - V_90 ;
goto V_79;
}
V_103 = F_77 ( V_56 , V_88 + V_66 ) ;
if ( V_103 )
goto V_79;
V_103 = V_66 ;
while ( V_66 ) {
void * V_91 ;
int V_92 = V_88 >> V_93 ;
int V_94 = V_88 & ( V_95 - 1 ) ;
int V_96 = F_74 ( T_3 , V_95 - V_94 , V_66 ) ;
V_91 = F_75 ( V_17 -> V_46 [ V_92 ] ) ;
memcpy ( V_91 + V_94 , V_87 , V_96 ) ;
F_76 ( V_17 -> V_46 [ V_92 ] ) ;
V_87 += V_96 ;
V_88 += V_96 ;
V_66 -= V_96 ;
}
V_17 -> V_8 = F_84 ( T_3 , V_88 , V_17 -> V_8 ) ;
V_79:
F_27 ( & V_32 ) ;
return V_103 ;
}
static struct V_54 *
F_85 ( struct V_1 * V_1 , const char * V_14 ,
struct V_31 * V_31 , unsigned int V_106 )
{
struct V_54 * V_56 ;
struct V_31 * V_107 ;
V_56 = F_5 ( sizeof( * V_56 ) , V_53 ) ;
if ( ! V_56 ) {
V_56 = F_86 ( - V_29 ) ;
goto exit;
}
V_56 -> V_69 = ! ! ( V_106 & V_108 ) ;
V_56 -> V_2 = V_1 ;
V_107 = & V_56 -> V_47 ;
F_87 ( V_107 ) ;
F_88 ( V_107 , L_13 , V_14 ) ;
V_107 -> V_109 = V_31 ;
V_107 -> V_63 = & V_110 ;
V_107 -> V_111 = V_112 ;
exit:
return V_56 ;
}
static int F_89 ( struct V_54 * V_56 ,
unsigned int V_106 , long V_113 )
{
int V_103 = 0 ;
struct V_31 * V_107 = & V_56 -> V_47 ;
struct V_13 * V_17 = V_56 -> V_17 ;
V_17 -> V_74 = true ;
F_90 ( V_107 , true ) ;
V_103 = F_91 ( V_107 ) ;
if ( V_103 ) {
F_70 ( V_107 , L_14 , V_23 ) ;
goto V_114;
}
F_24 ( & V_32 ) ;
F_19 ( & V_17 -> V_22 , & V_61 ) ;
F_27 ( & V_32 ) ;
if ( V_106 & V_115 ) {
V_17 -> V_116 = true ;
F_90 ( V_107 , false ) ;
F_32 ( V_107 , L_15 , V_17 -> V_19 ) ;
F_92 ( & V_56 -> V_47 . V_84 , V_117 ) ;
} else {
V_113 = V_12 ;
}
V_103 = F_93 ( & V_17 -> V_21 ,
V_113 ) ;
if ( V_103 == - V_118 || ! V_103 ) {
F_24 ( & V_32 ) ;
F_52 ( V_56 ) ;
F_27 ( & V_32 ) ;
} else if ( V_103 > 0 ) {
V_103 = 0 ;
}
if ( F_94 ( V_17 ) )
V_103 = - V_119 ;
else if ( ! V_17 -> V_9 )
V_103 = - V_29 ;
F_95 ( V_107 ) ;
V_114:
F_96 ( V_107 ) ;
return V_103 ;
}
static int F_97 ( struct V_1 * V_1 ,
const char * V_3 , struct V_31 * V_31 ,
unsigned int V_106 , long V_113 )
{
struct V_54 * V_56 ;
V_56 = F_85 ( V_1 , V_3 , V_31 , V_106 ) ;
if ( F_98 ( V_56 ) )
return F_99 ( V_56 ) ;
V_56 -> V_17 = V_1 -> V_45 ;
return F_89 ( V_56 , V_106 , V_113 ) ;
}
static void F_100 ( void )
{
struct V_13 * V_17 ;
struct V_13 * V_120 ;
F_24 ( & V_32 ) ;
F_101 (buf, next, &pending_fw_head, pending_list) {
if ( ! V_17 -> V_116 )
F_49 ( V_17 ) ;
}
F_27 ( & V_32 ) ;
}
static inline int
F_97 ( struct V_1 * V_1 , const char * V_3 ,
struct V_31 * V_31 , unsigned int V_106 ,
long V_113 )
{
return - V_38 ;
}
static inline void F_100 ( void ) { }
static int F_102 ( struct V_13 * V_17 )
{
int V_121 = 0 ;
F_24 ( & V_32 ) ;
while ( ! F_50 ( V_33 , & V_17 -> V_34 ) ) {
if ( F_94 ( V_17 ) ) {
V_121 = - V_38 ;
break;
}
F_27 ( & V_32 ) ;
V_121 = F_103 ( & V_17 -> V_21 ) ;
F_24 ( & V_32 ) ;
}
F_27 ( & V_32 ) ;
return V_121 ;
}
static int
F_104 ( struct V_1 * * V_122 , const char * V_3 ,
struct V_31 * V_31 )
{
struct V_1 * V_1 ;
struct V_13 * V_17 ;
int V_121 ;
* V_122 = V_1 = F_5 ( sizeof( * V_1 ) , V_53 ) ;
if ( ! V_1 ) {
F_70 ( V_31 , L_16 ,
V_23 ) ;
return - V_29 ;
}
if ( F_1 ( V_1 , V_3 ) ) {
F_32 ( V_31 , L_17 , V_3 ) ;
return 0 ;
}
V_121 = F_15 ( V_3 , & V_25 , & V_17 ) ;
V_1 -> V_45 = V_17 ;
if ( V_121 > 0 ) {
V_121 = F_102 ( V_17 ) ;
if ( ! V_121 ) {
F_37 ( V_17 , V_1 ) ;
return 0 ;
}
}
if ( V_121 < 0 )
return V_121 ;
return 1 ;
}
static int F_105 ( struct V_1 * V_2 , struct V_31 * V_31 ,
unsigned int V_106 )
{
struct V_13 * V_17 = V_2 -> V_45 ;
F_24 ( & V_32 ) ;
if ( ! V_17 -> V_8 || F_94 ( V_17 ) ) {
F_27 ( & V_32 ) ;
return - V_38 ;
}
if ( V_31 && ( V_106 & V_115 ) )
F_43 ( V_31 , V_17 -> V_19 ) ;
if ( V_17 -> V_16 -> V_123 == V_124 ) {
if ( F_106 ( V_17 -> V_19 ) )
F_17 ( & V_17 -> V_20 ) ;
}
F_37 ( V_17 , V_2 ) ;
F_27 ( & V_32 ) ;
return 0 ;
}
static int
F_107 ( const struct V_1 * * V_122 , const char * V_3 ,
struct V_31 * V_31 , unsigned int V_106 )
{
struct V_1 * V_2 = NULL ;
long V_113 ;
int V_121 ;
if ( ! V_122 )
return - V_125 ;
if ( ! V_3 || V_3 [ 0 ] == '\0' ) {
V_121 = - V_125 ;
goto V_79;
}
V_121 = F_104 ( & V_2 , V_3 , V_31 ) ;
if ( V_121 <= 0 )
goto V_79;
V_121 = 0 ;
V_113 = F_3 () ;
if ( V_106 & V_108 ) {
V_113 = F_108 ( V_113 ) ;
if ( ! V_113 ) {
F_32 ( V_31 , L_18 ,
V_3 ) ;
V_121 = - V_126 ;
goto V_79;
}
} else {
V_121 = F_109 () ;
if ( F_110 ( V_121 ) ) {
F_70 ( V_31 , L_19 ,
V_3 ) ;
goto V_79;
}
}
V_121 = F_28 ( V_31 , V_2 -> V_45 ) ;
if ( V_121 ) {
if ( ! ( V_106 & V_127 ) )
F_33 ( V_31 ,
L_20 ,
V_3 , V_121 ) ;
if ( V_106 & V_128 ) {
F_33 ( V_31 , L_21 ) ;
V_121 = F_97 ( V_2 , V_3 , V_31 ,
V_106 , V_113 ) ;
}
}
if ( ! V_121 )
V_121 = F_105 ( V_2 , V_31 , V_106 ) ;
F_111 () ;
V_79:
if ( V_121 < 0 ) {
F_112 ( V_2 ) ;
V_2 = NULL ;
}
* V_122 = V_2 ;
return V_121 ;
}
int
F_113 ( const struct V_1 * * V_122 , const char * V_3 ,
struct V_31 * V_31 )
{
int V_121 ;
F_114 ( V_129 ) ;
V_121 = F_107 ( V_122 , V_3 , V_31 ,
V_115 | V_130 ) ;
F_115 ( V_129 ) ;
return V_121 ;
}
int F_116 ( const struct V_1 * * V_122 ,
const char * V_3 , struct V_31 * V_31 )
{
int V_121 ;
F_114 ( V_129 ) ;
V_121 = F_107 ( V_122 , V_3 , V_31 ,
V_115 | V_127 ) ;
F_115 ( V_129 ) ;
return V_121 ;
}
void F_112 ( const struct V_1 * V_2 )
{
if ( V_2 ) {
if ( ! F_2 ( V_2 ) )
F_35 ( V_2 ) ;
F_7 ( V_2 ) ;
}
}
static void F_117 ( struct V_131 * V_132 )
{
struct V_133 * V_134 ;
const struct V_1 * V_2 ;
V_134 = F_48 ( V_132 , struct V_133 , V_132 ) ;
F_107 ( & V_2 , V_134 -> V_3 , V_134 -> V_31 ,
V_134 -> V_106 ) ;
V_134 -> V_135 ( V_2 , V_134 -> V_136 ) ;
F_96 ( V_134 -> V_31 ) ;
F_115 ( V_134 -> V_137 ) ;
F_39 ( V_134 -> V_3 ) ;
F_7 ( V_134 ) ;
}
int
F_118 (
struct V_137 * V_137 , bool V_138 ,
const char * V_3 , struct V_31 * V_31 , T_4 V_139 , void * V_136 ,
void (* V_135)( const struct V_1 * V_2 , void * V_136 ) )
{
struct V_133 * V_134 ;
V_134 = F_5 ( sizeof( struct V_133 ) , V_139 ) ;
if ( ! V_134 )
return - V_29 ;
V_134 -> V_137 = V_137 ;
V_134 -> V_3 = F_6 ( V_3 , V_139 ) ;
if ( ! V_134 -> V_3 ) {
F_7 ( V_134 ) ;
return - V_29 ;
}
V_134 -> V_31 = V_31 ;
V_134 -> V_136 = V_136 ;
V_134 -> V_135 = V_135 ;
V_134 -> V_106 = V_108 | V_130 |
( V_138 ? V_115 : V_128 ) ;
if ( ! F_119 ( V_137 ) ) {
F_39 ( V_134 -> V_3 ) ;
F_7 ( V_134 ) ;
return - V_140 ;
}
F_120 ( V_134 -> V_31 ) ;
F_121 ( & V_134 -> V_132 , F_117 ) ;
F_122 ( & V_134 -> V_132 ) ;
return 0 ;
}
static int F_123 ( const char * V_14 )
{
int V_121 ;
const struct V_1 * V_2 ;
F_12 ( L_22 , V_23 , V_14 ) ;
V_121 = F_113 ( & V_2 , V_14 , NULL ) ;
if ( ! V_121 )
F_7 ( V_2 ) ;
F_12 ( L_23 , V_23 , V_14 , V_121 ) ;
return V_121 ;
}
static struct V_13 * F_124 ( const char * V_14 )
{
struct V_13 * V_24 ;
struct V_15 * V_16 = & V_25 ;
F_16 ( & V_16 -> V_26 ) ;
V_24 = F_13 ( V_14 ) ;
F_18 ( & V_16 -> V_26 ) ;
return V_24 ;
}
static int F_125 ( const char * V_14 )
{
struct V_13 * V_17 ;
struct V_1 V_2 ;
F_12 ( L_22 , V_23 , V_14 ) ;
if ( F_1 ( & V_2 , V_14 ) )
return 0 ;
V_17 = F_124 ( V_14 ) ;
if ( V_17 ) {
F_21 ( V_17 ) ;
return 0 ;
}
return - V_125 ;
}
static struct V_141 * F_126 ( const char * V_3 )
{
struct V_141 * V_142 ;
V_142 = F_5 ( sizeof( * V_142 ) , V_18 ) ;
if ( ! V_142 )
goto exit;
V_142 -> V_3 = F_6 ( V_3 , V_18 ) ;
if ( ! V_142 -> V_3 ) {
F_7 ( V_142 ) ;
V_142 = NULL ;
goto exit;
}
exit:
return V_142 ;
}
static int F_127 ( const char * V_3 )
{
struct V_15 * V_16 = & V_25 ;
struct V_141 * V_142 ;
F_14 (fce, &fwc->fw_names, list) {
if ( ! strcmp ( V_142 -> V_3 , V_3 ) )
return 1 ;
}
return 0 ;
}
static int F_106 ( const char * V_3 )
{
struct V_15 * V_16 = & V_25 ;
struct V_141 * V_142 ;
int V_121 = 0 ;
F_16 ( & V_16 -> V_143 ) ;
if ( F_127 ( V_3 ) )
goto V_144;
V_142 = F_126 ( V_3 ) ;
if ( V_142 ) {
V_121 = 1 ;
F_19 ( & V_142 -> V_27 , & V_16 -> V_145 ) ;
F_12 ( L_24 , V_23 , V_3 ) ;
}
V_144:
F_18 ( & V_16 -> V_143 ) ;
return V_121 ;
}
static void F_128 ( struct V_141 * V_142 )
{
F_39 ( V_142 -> V_3 ) ;
F_7 ( V_142 ) ;
}
static void F_129 ( void * V_146 ,
T_5 V_147 )
{
struct V_141 * V_142 = V_146 ;
struct V_15 * V_16 = & V_25 ;
int V_121 ;
V_121 = F_123 ( V_142 -> V_3 ) ;
if ( V_121 ) {
F_16 ( & V_16 -> V_143 ) ;
F_130 ( & V_142 -> V_27 ) ;
F_18 ( & V_16 -> V_143 ) ;
F_128 ( V_142 ) ;
}
}
static void F_131 ( struct V_31 * V_47 , void * V_48 ,
void * V_9 )
{
struct V_49 * V_50 = V_48 ;
const char * V_14 = V_50 -> V_3 ;
struct V_148 * V_28 = V_9 ;
struct V_141 * V_142 ;
V_142 = F_126 ( V_14 ) ;
if ( V_142 )
F_19 ( & V_142 -> V_27 , V_28 ) ;
}
static int F_132 ( struct V_31 * V_47 , void * V_48 ,
void * V_52 )
{
struct V_49 * V_50 = V_48 ;
return ( V_50 -> V_51 == ( unsigned long ) V_52 ) ;
}
static void F_133 ( struct V_31 * V_47 , void * V_9 )
{
F_134 ( V_149 ) ;
struct V_141 * V_142 ;
struct V_141 * V_150 ;
struct V_15 * V_16 = & V_25 ;
F_135 ( V_47 , F_38 ,
F_132 , & V_25 ,
F_131 , & V_149 ) ;
F_101 (fce, fce_next, &todo, list) {
F_130 ( & V_142 -> V_27 ) ;
F_16 ( & V_16 -> V_143 ) ;
if ( ! F_127 ( V_142 -> V_3 ) ) {
F_19 ( & V_142 -> V_27 , & V_16 -> V_145 ) ;
} else {
F_128 ( V_142 ) ;
V_142 = NULL ;
}
F_18 ( & V_16 -> V_143 ) ;
if ( V_142 )
F_136 ( F_129 ,
( void * ) V_142 ,
& V_151 ) ;
}
}
static void F_137 ( void )
{
struct V_15 * V_16 = & V_25 ;
struct V_141 * V_142 ;
F_16 ( & V_16 -> V_143 ) ;
while ( ! F_54 ( & V_16 -> V_145 ) ) {
V_142 = F_138 ( V_16 -> V_145 . V_120 ,
struct V_141 , V_27 ) ;
F_130 ( & V_142 -> V_27 ) ;
F_18 ( & V_16 -> V_143 ) ;
F_125 ( V_142 -> V_3 ) ;
F_128 ( V_142 ) ;
F_16 ( & V_16 -> V_143 ) ;
}
F_18 ( & V_16 -> V_143 ) ;
}
static void F_139 ( void )
{
struct V_15 * V_16 = & V_25 ;
int V_152 ;
F_140 ( V_153 ) ;
F_12 ( L_25 , V_23 ) ;
F_141 ( & V_16 -> V_132 ) ;
V_152 = V_10 ;
V_10 = 10 ;
F_24 ( & V_32 ) ;
V_16 -> V_123 = V_124 ;
F_142 ( NULL , F_133 ) ;
F_27 ( & V_32 ) ;
F_143 ( & V_151 ) ;
V_10 = V_152 ;
}
static void F_144 ( void )
{
F_12 ( L_25 , V_23 ) ;
F_137 () ;
}
static void F_145 ( struct V_131 * V_132 )
{
F_144 () ;
}
static void F_146 ( unsigned long V_154 )
{
F_147 ( V_155 , & V_25 . V_132 ,
F_148 ( V_154 ) ) ;
}
static int F_149 ( struct V_57 * V_156 ,
unsigned long V_157 , void * V_158 )
{
switch ( V_157 ) {
case V_159 :
case V_160 :
case V_161 :
F_100 () ;
F_139 () ;
break;
case V_162 :
case V_163 :
case V_164 :
F_24 ( & V_32 ) ;
V_25 . V_123 = V_165 ;
F_27 ( & V_32 ) ;
F_146 ( 10 * V_166 ) ;
break;
}
return 0 ;
}
static int F_150 ( void )
{
V_25 . V_123 = V_165 ;
return 0 ;
}
static int F_106 ( const char * V_3 )
{
return 0 ;
}
static void T_6 F_151 ( void )
{
F_152 ( & V_25 . V_26 ) ;
F_11 ( & V_25 . V_28 ) ;
V_25 . V_123 = V_165 ;
#ifdef F_153
F_152 ( & V_25 . V_143 ) ;
F_11 ( & V_25 . V_145 ) ;
F_154 ( & V_25 . V_132 ,
F_145 ) ;
V_25 . V_167 . V_168 = F_149 ;
F_155 ( & V_25 . V_167 ) ;
F_156 ( & V_169 ) ;
#endif
}
static int T_6 F_157 ( void )
{
F_151 () ;
#ifdef F_10
F_158 ( & V_170 ) ;
return F_159 ( & V_110 ) ;
#else
return 0 ;
#endif
}
static void T_7 F_160 ( void )
{
#ifdef F_153
F_161 ( & V_169 ) ;
F_162 ( & V_25 . V_167 ) ;
#endif
#ifdef F_10
F_163 ( & V_170 ) ;
F_164 ( & V_110 ) ;
#endif
}
