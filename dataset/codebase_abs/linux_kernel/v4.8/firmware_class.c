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
static struct V_14 * F_4 ( const char * V_15 ,
struct V_16 * V_17 ,
void * V_18 , T_1 V_5 )
{
struct V_14 * V_4 ;
V_4 = F_5 ( sizeof( * V_4 ) , V_19 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_20 = F_6 ( V_15 , V_19 ) ;
if ( ! V_4 -> V_20 ) {
F_7 ( V_4 ) ;
return NULL ;
}
F_8 ( & V_4 -> V_21 ) ;
V_4 -> V_17 = V_17 ;
V_4 -> V_10 = V_18 ;
V_4 -> V_22 = V_5 ;
F_9 ( & V_4 -> V_23 ) ;
#ifdef F_10
F_11 ( & V_4 -> V_24 ) ;
#endif
F_12 ( L_1 , V_25 , V_15 , V_4 ) ;
return V_4 ;
}
static struct V_14 * F_13 ( const char * V_15 )
{
struct V_14 * V_26 ;
struct V_16 * V_17 = & V_27 ;
F_14 (tmp, &fwc->head, list)
if ( ! strcmp ( V_26 -> V_20 , V_15 ) )
return V_26 ;
return NULL ;
}
static int F_15 ( const char * V_15 ,
struct V_16 * V_17 ,
struct V_14 * * V_4 , void * V_18 ,
T_1 V_5 )
{
struct V_14 * V_26 ;
F_16 ( & V_17 -> V_28 ) ;
V_26 = F_13 ( V_15 ) ;
if ( V_26 ) {
F_17 ( & V_26 -> V_21 ) ;
F_18 ( & V_17 -> V_28 ) ;
* V_4 = V_26 ;
return 1 ;
}
V_26 = F_4 ( V_15 , V_17 , V_18 , V_5 ) ;
if ( V_26 )
F_19 ( & V_26 -> V_29 , & V_17 -> V_30 ) ;
F_18 ( & V_17 -> V_28 ) ;
* V_4 = V_26 ;
return V_26 ? 0 : - V_31 ;
}
static void F_20 ( struct V_32 * V_21 )
__releases( &fwc->lock
static void F_21 ( struct V_14 * V_4 )
{
struct V_16 * V_17 = V_4 -> V_17 ;
F_16 ( & V_17 -> V_28 ) ;
if ( ! F_22 ( & V_4 -> V_21 , F_20 ) )
F_18 ( & V_17 -> V_28 ) ;
}
static void F_23 ( struct V_33 * V_33 ,
struct V_14 * V_4 )
{
F_24 ( & V_34 ) ;
F_25 ( V_35 , & V_4 -> V_36 ) ;
F_26 ( & V_4 -> V_23 ) ;
F_27 ( & V_34 ) ;
}
static int
F_28 ( struct V_33 * V_33 , struct V_14 * V_4 )
{
T_2 V_5 ;
int V_37 , V_38 ;
int V_39 = - V_40 ;
char * V_41 ;
enum V_42 V_43 = V_44 ;
T_1 V_45 = V_46 ;
if ( V_4 -> V_10 ) {
V_43 = V_47 ;
V_45 = V_4 -> V_22 ;
}
V_41 = F_29 () ;
if ( ! V_41 )
return - V_31 ;
for ( V_37 = 0 ; V_37 < F_30 ( V_48 ) ; V_37 ++ ) {
if ( ! V_48 [ V_37 ] [ 0 ] )
continue;
V_38 = snprintf ( V_41 , V_49 , L_2 ,
V_48 [ V_37 ] , V_4 -> V_20 ) ;
if ( V_38 >= V_49 ) {
V_39 = - V_50 ;
break;
}
V_4 -> V_5 = 0 ;
V_39 = F_31 ( V_41 , & V_4 -> V_10 , & V_5 , V_45 ,
V_43 ) ;
if ( V_39 ) {
if ( V_39 == - V_40 )
F_32 ( V_33 , L_3 ,
V_41 , V_39 ) ;
else
F_33 ( V_33 , L_3 ,
V_41 , V_39 ) ;
continue;
}
F_32 ( V_33 , L_4 , V_4 -> V_20 ) ;
V_4 -> V_5 = V_5 ;
F_23 ( V_33 , V_4 ) ;
break;
}
F_34 ( V_41 ) ;
return V_39 ;
}
static void F_35 ( const struct V_1 * V_2 )
{
if ( ! V_2 -> V_51 ) {
F_36 ( V_2 -> V_10 ) ;
return;
}
F_21 ( V_2 -> V_51 ) ;
}
static void F_37 ( struct V_14 * V_4 , struct V_1 * V_2 )
{
V_2 -> V_51 = V_4 ;
#ifdef F_10
V_2 -> V_52 = V_4 -> V_52 ;
#endif
V_2 -> V_5 = V_4 -> V_5 ;
V_2 -> V_10 = V_4 -> V_10 ;
F_12 ( L_5 ,
V_25 , V_4 -> V_20 , V_4 , V_4 -> V_10 ,
( unsigned int ) V_4 -> V_5 ) ;
}
static void F_38 ( struct V_33 * V_53 , void * V_54 )
{
struct V_55 * V_56 = V_54 ;
if ( V_56 -> V_57 == ( unsigned long ) & V_27 )
F_12 ( L_6 ,
V_25 , V_56 -> V_3 , V_54 ) ;
F_39 ( V_56 -> V_3 ) ;
}
static int F_40 ( struct V_33 * V_53 , void * V_54 ,
void * V_58 )
{
struct V_55 * V_56 = V_54 ;
return ( V_56 -> V_57 == ( unsigned long ) & V_27 ) &&
! strcmp ( V_56 -> V_3 , V_58 ) ;
}
static struct V_55 * F_41 ( struct V_33 * V_53 ,
const char * V_3 )
{
struct V_55 * V_56 ;
V_56 = F_42 ( V_53 , F_38 ,
F_40 , ( void * ) V_3 ) ;
return V_56 ;
}
static int F_43 ( struct V_33 * V_53 , const char * V_3 )
{
struct V_55 * V_56 ;
V_56 = F_41 ( V_53 , V_3 ) ;
if ( V_56 )
return 1 ;
V_56 = F_44 ( F_38 , sizeof( struct V_55 ) ,
V_59 ) ;
if ( ! V_56 )
return - V_31 ;
V_56 -> V_3 = F_6 ( V_3 , V_59 ) ;
if ( ! V_56 -> V_3 ) {
F_45 ( V_56 ) ;
return - V_31 ;
}
V_56 -> V_57 = ( unsigned long ) & V_27 ;
F_46 ( V_53 , V_56 ) ;
return 0 ;
}
static int F_43 ( struct V_33 * V_53 , const char * V_3 )
{
return 0 ;
}
static struct V_60 * F_47 ( struct V_33 * V_53 )
{
return F_48 ( V_53 , struct V_60 , V_53 ) ;
}
static void F_49 ( struct V_14 * V_4 )
{
if ( F_50 ( V_35 , & V_4 -> V_36 ) )
return;
F_51 ( & V_4 -> V_24 ) ;
F_25 ( V_61 , & V_4 -> V_36 ) ;
F_26 ( & V_4 -> V_23 ) ;
}
static void F_52 ( struct V_60 * V_62 )
{
struct V_14 * V_4 = V_62 -> V_4 ;
F_49 ( V_4 ) ;
V_62 -> V_4 = NULL ;
}
static int F_53 ( struct V_63 * V_64 ,
unsigned long V_65 , void * V_66 )
{
F_24 ( & V_34 ) ;
while ( ! F_54 ( & V_67 ) )
F_49 ( F_55 ( & V_67 ,
struct V_14 ,
V_24 ) ) ;
F_27 ( & V_34 ) ;
return V_68 ;
}
static T_3 F_56 ( struct V_69 * V_69 , struct V_70 * V_71 ,
char * V_4 )
{
return sprintf ( V_4 , L_7 , V_11 ) ;
}
static T_3 F_57 ( struct V_69 * V_69 , struct V_70 * V_71 ,
const char * V_4 , T_1 V_72 )
{
V_11 = F_58 ( V_4 , NULL , 10 ) ;
if ( V_11 < 0 )
V_11 = 0 ;
return V_72 ;
}
static void F_59 ( struct V_33 * V_53 )
{
struct V_60 * V_62 = F_47 ( V_53 ) ;
F_7 ( V_62 ) ;
}
static int F_60 ( struct V_60 * V_62 , struct V_73 * V_74 )
{
if ( F_61 ( V_74 , L_8 , V_62 -> V_4 -> V_20 ) )
return - V_31 ;
if ( F_61 ( V_74 , L_9 , V_11 ) )
return - V_31 ;
if ( F_61 ( V_74 , L_10 , V_62 -> V_75 ) )
return - V_31 ;
return 0 ;
}
static int F_62 ( struct V_33 * V_53 , struct V_73 * V_74 )
{
struct V_60 * V_62 = F_47 ( V_53 ) ;
int V_76 = 0 ;
F_24 ( & V_34 ) ;
if ( V_62 -> V_4 )
V_76 = F_60 ( V_62 , V_74 ) ;
F_27 ( & V_34 ) ;
return V_76 ;
}
static T_3 F_63 ( struct V_33 * V_53 ,
struct V_77 * V_71 , char * V_4 )
{
struct V_60 * V_62 = F_47 ( V_53 ) ;
int V_78 = 0 ;
F_24 ( & V_34 ) ;
if ( V_62 -> V_4 )
V_78 = F_50 ( V_79 , & V_62 -> V_4 -> V_36 ) ;
F_27 ( & V_34 ) ;
return sprintf ( V_4 , L_7 , V_78 ) ;
}
static int F_64 ( struct V_14 * V_4 )
{
if ( ! V_4 -> V_80 )
return 0 ;
F_65 ( V_4 -> V_10 ) ;
V_4 -> V_10 = F_66 ( V_4 -> V_52 , V_4 -> V_81 , 0 , V_82 ) ;
if ( ! V_4 -> V_10 )
return - V_31 ;
return 0 ;
}
static T_3 F_67 ( struct V_33 * V_53 ,
struct V_77 * V_71 ,
const char * V_4 , T_1 V_72 )
{
struct V_60 * V_62 = F_47 ( V_53 ) ;
struct V_14 * V_83 ;
T_3 V_84 = V_72 ;
int V_78 = F_58 ( V_4 , NULL , 10 ) ;
int V_37 ;
F_24 ( & V_34 ) ;
V_83 = V_62 -> V_4 ;
if ( ! V_83 )
goto V_85;
switch ( V_78 ) {
case 1 :
if ( ! F_50 ( V_35 , & V_83 -> V_36 ) ) {
for ( V_37 = 0 ; V_37 < V_83 -> V_81 ; V_37 ++ )
F_68 ( V_83 -> V_52 [ V_37 ] ) ;
F_36 ( V_83 -> V_52 ) ;
V_83 -> V_52 = NULL ;
V_83 -> V_86 = 0 ;
V_83 -> V_81 = 0 ;
F_25 ( V_79 , & V_83 -> V_36 ) ;
}
break;
case 0 :
if ( F_50 ( V_79 , & V_83 -> V_36 ) ) {
int V_39 ;
F_25 ( V_35 , & V_83 -> V_36 ) ;
F_69 ( V_79 , & V_83 -> V_36 ) ;
V_39 = F_64 ( V_83 ) ;
if ( V_39 )
F_70 ( V_53 , L_11 ,
V_25 ) ;
else
V_39 = F_71 ( NULL ,
V_83 -> V_10 , V_83 -> V_5 ,
V_44 ) ;
F_51 ( & V_83 -> V_24 ) ;
if ( V_39 ) {
F_25 ( V_61 , & V_83 -> V_36 ) ;
V_84 = V_39 ;
}
F_26 ( & V_83 -> V_23 ) ;
break;
}
default:
F_70 ( V_53 , L_12 , V_25 , V_78 ) ;
case - 1 :
F_52 ( V_62 ) ;
break;
}
V_85:
F_27 ( & V_34 ) ;
return V_84 ;
}
static void F_72 ( struct V_14 * V_4 , char * V_87 ,
T_2 V_88 , T_1 V_72 , bool V_89 )
{
if ( V_89 )
memcpy ( V_87 , V_4 -> V_10 + V_88 , V_72 ) ;
else
memcpy ( V_4 -> V_10 + V_88 , V_87 , V_72 ) ;
}
static void F_73 ( struct V_14 * V_4 , char * V_87 ,
T_2 V_88 , T_1 V_72 , bool V_89 )
{
while ( V_72 ) {
void * V_90 ;
int V_91 = V_88 >> V_92 ;
int V_93 = V_88 & ( V_94 - 1 ) ;
int V_95 = F_74 ( T_1 , V_94 - V_93 , V_72 ) ;
V_90 = F_75 ( V_4 -> V_52 [ V_91 ] ) ;
if ( V_89 )
memcpy ( V_87 , V_90 + V_93 , V_95 ) ;
else
memcpy ( V_90 + V_93 , V_87 , V_95 ) ;
F_76 ( V_4 -> V_52 [ V_91 ] ) ;
V_87 += V_95 ;
V_88 += V_95 ;
V_72 -= V_95 ;
}
}
static T_3 F_77 ( struct V_96 * V_97 , struct V_98 * V_99 ,
struct V_100 * V_101 ,
char * V_87 , T_2 V_88 , T_1 V_72 )
{
struct V_33 * V_53 = F_78 ( V_99 ) ;
struct V_60 * V_62 = F_47 ( V_53 ) ;
struct V_14 * V_4 ;
T_3 V_102 ;
F_24 ( & V_34 ) ;
V_4 = V_62 -> V_4 ;
if ( ! V_4 || F_50 ( V_35 , & V_4 -> V_36 ) ) {
V_102 = - V_103 ;
goto V_85;
}
if ( V_88 > V_4 -> V_5 ) {
V_102 = 0 ;
goto V_85;
}
if ( V_72 > V_4 -> V_5 - V_88 )
V_72 = V_4 -> V_5 - V_88 ;
V_102 = V_72 ;
if ( V_4 -> V_10 )
F_72 ( V_4 , V_87 , V_88 , V_72 , true ) ;
else
F_73 ( V_4 , V_87 , V_88 , V_72 , true ) ;
V_85:
F_27 ( & V_34 ) ;
return V_102 ;
}
static int F_79 ( struct V_60 * V_62 , int V_104 )
{
struct V_14 * V_4 = V_62 -> V_4 ;
int V_105 = F_80 ( V_104 ) >> V_92 ;
if ( V_4 -> V_86 < V_105 ) {
int V_106 = F_81 ( V_105 ,
V_4 -> V_86 * 2 ) ;
struct V_107 * * V_108 ;
V_108 = F_82 ( V_106 * sizeof( void * ) ) ;
if ( ! V_108 ) {
F_52 ( V_62 ) ;
return - V_31 ;
}
memcpy ( V_108 , V_4 -> V_52 ,
V_4 -> V_86 * sizeof( void * ) ) ;
memset ( & V_108 [ V_4 -> V_86 ] , 0 , sizeof( void * ) *
( V_106 - V_4 -> V_86 ) ) ;
F_36 ( V_4 -> V_52 ) ;
V_4 -> V_52 = V_108 ;
V_4 -> V_86 = V_106 ;
}
while ( V_4 -> V_81 < V_105 ) {
V_4 -> V_52 [ V_4 -> V_81 ] =
F_83 ( V_59 | V_109 ) ;
if ( ! V_4 -> V_52 [ V_4 -> V_81 ] ) {
F_52 ( V_62 ) ;
return - V_31 ;
}
V_4 -> V_81 ++ ;
}
return 0 ;
}
static T_3 F_84 ( struct V_96 * V_97 , struct V_98 * V_99 ,
struct V_100 * V_101 ,
char * V_87 , T_2 V_88 , T_1 V_72 )
{
struct V_33 * V_53 = F_78 ( V_99 ) ;
struct V_60 * V_62 = F_47 ( V_53 ) ;
struct V_14 * V_4 ;
T_3 V_110 ;
if ( ! F_85 ( V_111 ) )
return - V_112 ;
F_24 ( & V_34 ) ;
V_4 = V_62 -> V_4 ;
if ( ! V_4 || F_50 ( V_35 , & V_4 -> V_36 ) ) {
V_110 = - V_103 ;
goto V_85;
}
if ( V_4 -> V_10 ) {
if ( V_88 + V_72 > V_4 -> V_22 ) {
V_110 = - V_31 ;
goto V_85;
}
F_72 ( V_4 , V_87 , V_88 , V_72 , false ) ;
V_110 = V_72 ;
} else {
V_110 = F_79 ( V_62 , V_88 + V_72 ) ;
if ( V_110 )
goto V_85;
V_110 = V_72 ;
F_73 ( V_4 , V_87 , V_88 , V_72 , false ) ;
}
V_4 -> V_5 = F_86 ( T_1 , V_88 + V_72 , V_4 -> V_5 ) ;
V_85:
F_27 ( & V_34 ) ;
return V_110 ;
}
static struct V_60 *
F_87 ( struct V_1 * V_1 , const char * V_15 ,
struct V_33 * V_33 , unsigned int V_113 )
{
struct V_60 * V_62 ;
struct V_33 * V_114 ;
V_62 = F_5 ( sizeof( * V_62 ) , V_59 ) ;
if ( ! V_62 ) {
V_62 = F_88 ( - V_31 ) ;
goto exit;
}
V_62 -> V_75 = ! ! ( V_113 & V_115 ) ;
V_62 -> V_2 = V_1 ;
V_114 = & V_62 -> V_53 ;
F_89 ( V_114 ) ;
F_90 ( V_114 , L_13 , V_15 ) ;
V_114 -> V_116 = V_33 ;
V_114 -> V_69 = & V_117 ;
V_114 -> V_118 = V_119 ;
exit:
return V_62 ;
}
static int F_91 ( struct V_60 * V_62 ,
unsigned int V_113 , long V_120 )
{
int V_110 = 0 ;
struct V_33 * V_114 = & V_62 -> V_53 ;
struct V_14 * V_4 = V_62 -> V_4 ;
if ( ! V_4 -> V_10 )
V_4 -> V_80 = true ;
F_92 ( V_114 , true ) ;
V_110 = F_93 ( V_114 ) ;
if ( V_110 ) {
F_70 ( V_114 , L_14 , V_25 ) ;
goto V_121;
}
F_24 ( & V_34 ) ;
F_19 ( & V_4 -> V_24 , & V_67 ) ;
F_27 ( & V_34 ) ;
if ( V_113 & V_122 ) {
V_4 -> V_123 = true ;
F_92 ( V_114 , false ) ;
F_32 ( V_114 , L_15 , V_4 -> V_20 ) ;
F_94 ( & V_62 -> V_53 . V_99 , V_124 ) ;
} else {
V_120 = V_13 ;
}
V_110 = F_95 ( & V_4 -> V_23 ,
V_120 ) ;
if ( V_110 == - V_125 || ! V_110 ) {
F_24 ( & V_34 ) ;
F_52 ( V_62 ) ;
F_27 ( & V_34 ) ;
} else if ( V_110 > 0 ) {
V_110 = 0 ;
}
if ( F_96 ( V_4 ) )
V_110 = - V_126 ;
else if ( V_4 -> V_80 && ! V_4 -> V_10 )
V_110 = - V_31 ;
F_97 ( V_114 ) ;
V_121:
F_98 ( V_114 ) ;
return V_110 ;
}
static int F_99 ( struct V_1 * V_1 ,
const char * V_3 , struct V_33 * V_33 ,
unsigned int V_113 , long V_120 )
{
struct V_60 * V_62 ;
V_62 = F_87 ( V_1 , V_3 , V_33 , V_113 ) ;
if ( F_100 ( V_62 ) )
return F_101 ( V_62 ) ;
V_62 -> V_4 = V_1 -> V_51 ;
return F_91 ( V_62 , V_113 , V_120 ) ;
}
static void F_102 ( void )
{
struct V_14 * V_4 ;
struct V_14 * V_127 ;
F_24 ( & V_34 ) ;
F_103 (buf, next, &pending_fw_head, pending_list) {
if ( ! V_4 -> V_123 )
F_49 ( V_4 ) ;
}
F_27 ( & V_34 ) ;
}
static inline int
F_99 ( struct V_1 * V_1 , const char * V_3 ,
struct V_33 * V_33 , unsigned int V_113 ,
long V_120 )
{
return - V_40 ;
}
static inline void F_102 ( void ) { }
static int F_104 ( struct V_14 * V_4 )
{
int V_128 = 0 ;
F_24 ( & V_34 ) ;
while ( ! F_50 ( V_35 , & V_4 -> V_36 ) ) {
if ( F_96 ( V_4 ) ) {
V_128 = - V_40 ;
break;
}
F_27 ( & V_34 ) ;
V_128 = F_105 ( & V_4 -> V_23 ) ;
F_24 ( & V_34 ) ;
}
F_27 ( & V_34 ) ;
return V_128 ;
}
static int
F_106 ( struct V_1 * * V_129 , const char * V_3 ,
struct V_33 * V_33 , void * V_18 , T_1 V_5 )
{
struct V_1 * V_1 ;
struct V_14 * V_4 ;
int V_128 ;
* V_129 = V_1 = F_5 ( sizeof( * V_1 ) , V_59 ) ;
if ( ! V_1 ) {
F_70 ( V_33 , L_16 ,
V_25 ) ;
return - V_31 ;
}
if ( F_1 ( V_1 , V_3 , V_18 , V_5 ) ) {
F_32 ( V_33 , L_17 , V_3 ) ;
return 0 ;
}
V_128 = F_15 ( V_3 , & V_27 , & V_4 , V_18 , V_5 ) ;
V_1 -> V_51 = V_4 ;
if ( V_128 > 0 ) {
V_128 = F_104 ( V_4 ) ;
if ( ! V_128 ) {
F_37 ( V_4 , V_1 ) ;
return 0 ;
}
}
if ( V_128 < 0 )
return V_128 ;
return 1 ;
}
static int F_107 ( struct V_1 * V_2 , struct V_33 * V_33 ,
unsigned int V_113 )
{
struct V_14 * V_4 = V_2 -> V_51 ;
F_24 ( & V_34 ) ;
if ( ! V_4 -> V_5 || F_96 ( V_4 ) ) {
F_27 ( & V_34 ) ;
return - V_40 ;
}
if ( V_33 && ( V_113 & V_122 ) &&
! ( V_113 & V_130 ) )
F_43 ( V_33 , V_4 -> V_20 ) ;
if ( ! ( V_113 & V_130 ) &&
V_4 -> V_17 -> V_131 == V_132 ) {
if ( F_108 ( V_4 -> V_20 ) )
F_17 ( & V_4 -> V_21 ) ;
}
F_37 ( V_4 , V_2 ) ;
F_27 ( & V_34 ) ;
return 0 ;
}
static int
F_109 ( const struct V_1 * * V_129 , const char * V_3 ,
struct V_33 * V_33 , void * V_4 , T_1 V_5 ,
unsigned int V_113 )
{
struct V_1 * V_2 = NULL ;
long V_120 ;
int V_128 ;
if ( ! V_129 )
return - V_133 ;
if ( ! V_3 || V_3 [ 0 ] == '\0' ) {
V_128 = - V_133 ;
goto V_85;
}
V_128 = F_106 ( & V_2 , V_3 , V_33 , V_4 , V_5 ) ;
if ( V_128 <= 0 )
goto V_85;
V_128 = 0 ;
V_120 = F_3 () ;
if ( V_113 & V_115 ) {
V_120 = F_110 ( V_120 ) ;
if ( ! V_120 ) {
F_32 ( V_33 , L_18 ,
V_3 ) ;
V_128 = - V_134 ;
goto V_85;
}
} else {
V_128 = F_111 () ;
if ( F_112 ( V_128 ) ) {
F_70 ( V_33 , L_19 ,
V_3 ) ;
goto V_85;
}
}
V_128 = F_28 ( V_33 , V_2 -> V_51 ) ;
if ( V_128 ) {
if ( ! ( V_113 & V_135 ) )
F_33 ( V_33 ,
L_20 ,
V_3 , V_128 ) ;
if ( V_113 & V_136 ) {
F_33 ( V_33 , L_21 ) ;
V_128 = F_99 ( V_2 , V_3 , V_33 ,
V_113 , V_120 ) ;
}
}
if ( ! V_128 )
V_128 = F_107 ( V_2 , V_33 , V_113 ) ;
F_113 () ;
V_85:
if ( V_128 < 0 ) {
F_114 ( V_2 ) ;
V_2 = NULL ;
}
* V_129 = V_2 ;
return V_128 ;
}
int
F_115 ( const struct V_1 * * V_129 , const char * V_3 ,
struct V_33 * V_33 )
{
int V_128 ;
F_116 ( V_137 ) ;
V_128 = F_109 ( V_129 , V_3 , V_33 , NULL , 0 ,
V_122 | V_138 ) ;
F_117 ( V_137 ) ;
return V_128 ;
}
int F_118 ( const struct V_1 * * V_129 ,
const char * V_3 , struct V_33 * V_33 )
{
int V_128 ;
F_116 ( V_137 ) ;
V_128 = F_109 ( V_129 , V_3 , V_33 , NULL , 0 ,
V_122 | V_135 ) ;
F_117 ( V_137 ) ;
return V_128 ;
}
int
F_119 ( const struct V_1 * * V_129 , const char * V_3 ,
struct V_33 * V_33 , void * V_4 , T_1 V_5 )
{
int V_128 ;
F_116 ( V_137 ) ;
V_128 = F_109 ( V_129 , V_3 , V_33 , V_4 , V_5 ,
V_122 | V_138 |
V_130 ) ;
F_117 ( V_137 ) ;
return V_128 ;
}
void F_114 ( const struct V_1 * V_2 )
{
if ( V_2 ) {
if ( ! F_2 ( V_2 ) )
F_35 ( V_2 ) ;
F_7 ( V_2 ) ;
}
}
static void F_120 ( struct V_139 * V_140 )
{
struct V_141 * V_142 ;
const struct V_1 * V_2 ;
V_142 = F_48 ( V_140 , struct V_141 , V_140 ) ;
F_109 ( & V_2 , V_142 -> V_3 , V_142 -> V_33 , NULL , 0 ,
V_142 -> V_113 ) ;
V_142 -> V_143 ( V_2 , V_142 -> V_144 ) ;
F_98 ( V_142 -> V_33 ) ;
F_117 ( V_142 -> V_145 ) ;
F_39 ( V_142 -> V_3 ) ;
F_7 ( V_142 ) ;
}
int
F_121 (
struct V_145 * V_145 , bool V_146 ,
const char * V_3 , struct V_33 * V_33 , T_4 V_147 , void * V_144 ,
void (* V_143)( const struct V_1 * V_2 , void * V_144 ) )
{
struct V_141 * V_142 ;
V_142 = F_5 ( sizeof( struct V_141 ) , V_147 ) ;
if ( ! V_142 )
return - V_31 ;
V_142 -> V_145 = V_145 ;
V_142 -> V_3 = F_6 ( V_3 , V_147 ) ;
if ( ! V_142 -> V_3 ) {
F_7 ( V_142 ) ;
return - V_31 ;
}
V_142 -> V_33 = V_33 ;
V_142 -> V_144 = V_144 ;
V_142 -> V_143 = V_143 ;
V_142 -> V_113 = V_115 | V_138 |
( V_146 ? V_122 : V_136 ) ;
if ( ! F_122 ( V_145 ) ) {
F_39 ( V_142 -> V_3 ) ;
F_7 ( V_142 ) ;
return - V_148 ;
}
F_123 ( V_142 -> V_33 ) ;
F_124 ( & V_142 -> V_140 , F_120 ) ;
F_125 ( & V_142 -> V_140 ) ;
return 0 ;
}
static int F_126 ( const char * V_15 )
{
int V_128 ;
const struct V_1 * V_2 ;
F_12 ( L_22 , V_25 , V_15 ) ;
V_128 = F_115 ( & V_2 , V_15 , NULL ) ;
if ( ! V_128 )
F_7 ( V_2 ) ;
F_12 ( L_23 , V_25 , V_15 , V_128 ) ;
return V_128 ;
}
static struct V_14 * F_127 ( const char * V_15 )
{
struct V_14 * V_26 ;
struct V_16 * V_17 = & V_27 ;
F_16 ( & V_17 -> V_28 ) ;
V_26 = F_13 ( V_15 ) ;
F_18 ( & V_17 -> V_28 ) ;
return V_26 ;
}
static int F_128 ( const char * V_15 )
{
struct V_14 * V_4 ;
struct V_1 V_2 ;
F_12 ( L_22 , V_25 , V_15 ) ;
if ( F_1 ( & V_2 , V_15 , NULL , 0 ) )
return 0 ;
V_4 = F_127 ( V_15 ) ;
if ( V_4 ) {
F_21 ( V_4 ) ;
return 0 ;
}
return - V_133 ;
}
static struct V_149 * F_129 ( const char * V_3 )
{
struct V_149 * V_150 ;
V_150 = F_5 ( sizeof( * V_150 ) , V_19 ) ;
if ( ! V_150 )
goto exit;
V_150 -> V_3 = F_6 ( V_3 , V_19 ) ;
if ( ! V_150 -> V_3 ) {
F_7 ( V_150 ) ;
V_150 = NULL ;
goto exit;
}
exit:
return V_150 ;
}
static int F_130 ( const char * V_3 )
{
struct V_16 * V_17 = & V_27 ;
struct V_149 * V_150 ;
F_14 (fce, &fwc->fw_names, list) {
if ( ! strcmp ( V_150 -> V_3 , V_3 ) )
return 1 ;
}
return 0 ;
}
static int F_108 ( const char * V_3 )
{
struct V_16 * V_17 = & V_27 ;
struct V_149 * V_150 ;
int V_128 = 0 ;
F_16 ( & V_17 -> V_151 ) ;
if ( F_130 ( V_3 ) )
goto V_152;
V_150 = F_129 ( V_3 ) ;
if ( V_150 ) {
V_128 = 1 ;
F_19 ( & V_150 -> V_29 , & V_17 -> V_153 ) ;
F_12 ( L_24 , V_25 , V_3 ) ;
}
V_152:
F_18 ( & V_17 -> V_151 ) ;
return V_128 ;
}
static void F_131 ( struct V_149 * V_150 )
{
F_39 ( V_150 -> V_3 ) ;
F_7 ( V_150 ) ;
}
static void F_132 ( void * V_154 ,
T_5 V_155 )
{
struct V_149 * V_150 = V_154 ;
struct V_16 * V_17 = & V_27 ;
int V_128 ;
V_128 = F_126 ( V_150 -> V_3 ) ;
if ( V_128 ) {
F_16 ( & V_17 -> V_151 ) ;
F_133 ( & V_150 -> V_29 ) ;
F_18 ( & V_17 -> V_151 ) ;
F_131 ( V_150 ) ;
}
}
static void F_134 ( struct V_33 * V_53 , void * V_54 ,
void * V_10 )
{
struct V_55 * V_56 = V_54 ;
const char * V_15 = V_56 -> V_3 ;
struct V_156 * V_30 = V_10 ;
struct V_149 * V_150 ;
V_150 = F_129 ( V_15 ) ;
if ( V_150 )
F_19 ( & V_150 -> V_29 , V_30 ) ;
}
static int F_135 ( struct V_33 * V_53 , void * V_54 ,
void * V_58 )
{
struct V_55 * V_56 = V_54 ;
return ( V_56 -> V_57 == ( unsigned long ) V_58 ) ;
}
static void F_136 ( struct V_33 * V_53 , void * V_10 )
{
F_137 ( V_157 ) ;
struct V_149 * V_150 ;
struct V_149 * V_158 ;
struct V_16 * V_17 = & V_27 ;
F_138 ( V_53 , F_38 ,
F_135 , & V_27 ,
F_134 , & V_157 ) ;
F_103 (fce, fce_next, &todo, list) {
F_133 ( & V_150 -> V_29 ) ;
F_16 ( & V_17 -> V_151 ) ;
if ( ! F_130 ( V_150 -> V_3 ) ) {
F_19 ( & V_150 -> V_29 , & V_17 -> V_153 ) ;
} else {
F_131 ( V_150 ) ;
V_150 = NULL ;
}
F_18 ( & V_17 -> V_151 ) ;
if ( V_150 )
F_139 ( F_132 ,
( void * ) V_150 ,
& V_159 ) ;
}
}
static void F_140 ( void )
{
struct V_16 * V_17 = & V_27 ;
struct V_149 * V_150 ;
F_16 ( & V_17 -> V_151 ) ;
while ( ! F_54 ( & V_17 -> V_153 ) ) {
V_150 = F_141 ( V_17 -> V_153 . V_127 ,
struct V_149 , V_29 ) ;
F_133 ( & V_150 -> V_29 ) ;
F_18 ( & V_17 -> V_151 ) ;
F_128 ( V_150 -> V_3 ) ;
F_131 ( V_150 ) ;
F_16 ( & V_17 -> V_151 ) ;
}
F_18 ( & V_17 -> V_151 ) ;
}
static void F_142 ( void )
{
struct V_16 * V_17 = & V_27 ;
int V_160 ;
F_143 ( V_161 ) ;
F_12 ( L_25 , V_25 ) ;
F_144 ( & V_17 -> V_140 ) ;
V_160 = V_11 ;
V_11 = 10 ;
F_24 ( & V_34 ) ;
V_17 -> V_131 = V_132 ;
F_145 ( NULL , F_136 ) ;
F_27 ( & V_34 ) ;
F_146 ( & V_159 ) ;
V_11 = V_160 ;
}
static void F_147 ( void )
{
F_12 ( L_25 , V_25 ) ;
F_140 () ;
}
static void F_148 ( struct V_139 * V_140 )
{
F_147 () ;
}
static void F_149 ( unsigned long V_162 )
{
F_150 ( V_163 , & V_27 . V_140 ,
F_151 ( V_162 ) ) ;
}
static int F_152 ( struct V_63 * V_164 ,
unsigned long V_165 , void * V_166 )
{
switch ( V_165 ) {
case V_167 :
case V_168 :
case V_169 :
F_102 () ;
F_142 () ;
break;
case V_170 :
case V_171 :
case V_172 :
F_24 ( & V_34 ) ;
V_27 . V_131 = V_173 ;
F_27 ( & V_34 ) ;
F_149 ( 10 * V_174 ) ;
break;
}
return 0 ;
}
static int F_153 ( void )
{
V_27 . V_131 = V_173 ;
return 0 ;
}
static int F_108 ( const char * V_3 )
{
return 0 ;
}
static void T_6 F_154 ( void )
{
F_155 ( & V_27 . V_28 ) ;
F_11 ( & V_27 . V_30 ) ;
V_27 . V_131 = V_173 ;
#ifdef F_156
F_155 ( & V_27 . V_151 ) ;
F_11 ( & V_27 . V_153 ) ;
F_157 ( & V_27 . V_140 ,
F_148 ) ;
V_27 . V_175 . V_176 = F_152 ;
F_158 ( & V_27 . V_175 ) ;
F_159 ( & V_177 ) ;
#endif
}
static int T_6 F_160 ( void )
{
F_154 () ;
#ifdef F_10
F_161 ( & V_178 ) ;
return F_162 ( & V_117 ) ;
#else
return 0 ;
#endif
}
static void T_7 F_163 ( void )
{
#ifdef F_156
F_164 ( & V_177 ) ;
F_165 ( & V_27 . V_175 ) ;
#endif
#ifdef F_10
F_166 ( & V_178 ) ;
F_167 ( & V_117 ) ;
#endif
}
