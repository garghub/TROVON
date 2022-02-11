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
V_23 = F_8 ( V_15 -> V_16 ,
F_6 ( F_9 ( V_15 -> V_17 ) ) ,
V_22 ) ;
if ( V_23 != 0 && V_15 -> V_17 == V_21 )
return - V_24 ;
if ( ! V_23 )
return - V_25 ;
return V_23 < 0 ? V_23 : 0 ;
}
static void F_10 ( struct V_14 * V_15 ,
enum V_19 V_17 )
{
F_11 ( V_15 -> V_17 , V_17 ) ;
if ( V_17 == V_20 || V_17 == V_21 )
F_12 ( & V_15 -> V_16 ) ;
}
static int F_13 ( struct V_14 * V_15 , enum V_19 V_17 )
{
return V_15 -> V_17 == V_17 ;
}
static struct V_26 * F_14 ( const char * V_27 ,
struct V_28 * V_29 ,
void * V_30 , T_1 V_5 )
{
struct V_26 * V_4 ;
V_4 = F_15 ( sizeof( * V_4 ) , V_31 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_32 = F_16 ( V_27 , V_31 ) ;
if ( ! V_4 -> V_32 ) {
F_17 ( V_4 ) ;
return NULL ;
}
F_18 ( & V_4 -> V_33 ) ;
V_4 -> V_29 = V_29 ;
V_4 -> V_10 = V_30 ;
V_4 -> V_34 = V_5 ;
F_4 ( & V_4 -> V_15 ) ;
#ifdef F_19
F_20 ( & V_4 -> V_35 ) ;
#endif
F_21 ( L_1 , V_36 , V_27 , V_4 ) ;
return V_4 ;
}
static struct V_26 * F_22 ( const char * V_27 )
{
struct V_26 * V_37 ;
struct V_28 * V_29 = & V_38 ;
F_23 (tmp, &fwc->head, list)
if ( ! strcmp ( V_37 -> V_32 , V_27 ) )
return V_37 ;
return NULL ;
}
static int F_24 ( const char * V_27 ,
struct V_28 * V_29 ,
struct V_26 * * V_4 , void * V_30 ,
T_1 V_5 )
{
struct V_26 * V_37 ;
F_25 ( & V_29 -> V_39 ) ;
V_37 = F_22 ( V_27 ) ;
if ( V_37 ) {
F_26 ( & V_37 -> V_33 ) ;
F_27 ( & V_29 -> V_39 ) ;
* V_4 = V_37 ;
return 1 ;
}
V_37 = F_14 ( V_27 , V_29 , V_30 , V_5 ) ;
if ( V_37 )
F_28 ( & V_37 -> V_40 , & V_29 -> V_41 ) ;
F_27 ( & V_29 -> V_39 ) ;
* V_4 = V_37 ;
return V_37 ? 0 : - V_42 ;
}
static void F_29 ( struct V_43 * V_33 )
__releases( &fwc->lock
static void F_30 ( struct V_26 * V_4 )
{
struct V_28 * V_29 = V_4 -> V_29 ;
F_25 ( & V_29 -> V_39 ) ;
if ( ! F_31 ( & V_4 -> V_33 , F_29 ) )
F_27 ( & V_29 -> V_39 ) ;
}
static int
F_32 ( struct V_44 * V_44 , struct V_26 * V_4 )
{
T_2 V_5 ;
int V_45 , V_46 ;
int V_47 = - V_24 ;
char * V_48 ;
enum V_49 V_50 = V_51 ;
T_1 V_52 = V_53 ;
if ( V_4 -> V_10 ) {
V_50 = V_54 ;
V_52 = V_4 -> V_34 ;
}
V_48 = F_33 () ;
if ( ! V_48 )
return - V_42 ;
for ( V_45 = 0 ; V_45 < F_34 ( V_55 ) ; V_45 ++ ) {
if ( ! V_55 [ V_45 ] [ 0 ] )
continue;
V_46 = snprintf ( V_48 , V_56 , L_2 ,
V_55 [ V_45 ] , V_4 -> V_32 ) ;
if ( V_46 >= V_56 ) {
V_47 = - V_57 ;
break;
}
V_4 -> V_5 = 0 ;
V_47 = F_35 ( V_48 , & V_4 -> V_10 , & V_5 , V_52 ,
V_50 ) ;
if ( V_47 ) {
if ( V_47 == - V_24 )
F_36 ( V_44 , L_3 ,
V_48 , V_47 ) ;
else
F_37 ( V_44 , L_3 ,
V_48 , V_47 ) ;
continue;
}
F_36 ( V_44 , L_4 , V_4 -> V_32 ) ;
V_4 -> V_5 = V_5 ;
F_38 ( & V_4 -> V_15 ) ;
break;
}
F_39 ( V_48 ) ;
return V_47 ;
}
static void F_40 ( const struct V_1 * V_2 )
{
if ( ! V_2 -> V_58 ) {
F_41 ( V_2 -> V_10 ) ;
return;
}
F_30 ( V_2 -> V_58 ) ;
}
static void F_42 ( struct V_26 * V_4 , struct V_1 * V_2 )
{
V_2 -> V_58 = V_4 ;
#ifdef F_19
V_2 -> V_59 = V_4 -> V_59 ;
#endif
V_2 -> V_5 = V_4 -> V_5 ;
V_2 -> V_10 = V_4 -> V_10 ;
F_21 ( L_5 ,
V_36 , V_4 -> V_32 , V_4 , V_4 -> V_10 ,
( unsigned int ) V_4 -> V_5 ) ;
}
static void F_43 ( struct V_44 * V_60 , void * V_61 )
{
struct V_62 * V_63 = V_61 ;
if ( V_63 -> V_64 == ( unsigned long ) & V_38 )
F_21 ( L_6 ,
V_36 , V_63 -> V_3 , V_61 ) ;
F_44 ( V_63 -> V_3 ) ;
}
static int F_45 ( struct V_44 * V_60 , void * V_61 ,
void * V_65 )
{
struct V_62 * V_63 = V_61 ;
return ( V_63 -> V_64 == ( unsigned long ) & V_38 ) &&
! strcmp ( V_63 -> V_3 , V_65 ) ;
}
static struct V_62 * F_46 ( struct V_44 * V_60 ,
const char * V_3 )
{
struct V_62 * V_63 ;
V_63 = F_47 ( V_60 , F_43 ,
F_45 , ( void * ) V_3 ) ;
return V_63 ;
}
static int F_48 ( struct V_44 * V_60 , const char * V_3 )
{
struct V_62 * V_63 ;
V_63 = F_46 ( V_60 , V_3 ) ;
if ( V_63 )
return 1 ;
V_63 = F_49 ( F_43 , sizeof( struct V_62 ) ,
V_66 ) ;
if ( ! V_63 )
return - V_42 ;
V_63 -> V_3 = F_16 ( V_3 , V_66 ) ;
if ( ! V_63 -> V_3 ) {
F_50 ( V_63 ) ;
return - V_42 ;
}
V_63 -> V_64 = ( unsigned long ) & V_38 ;
F_51 ( V_60 , V_63 ) ;
return 0 ;
}
static int F_48 ( struct V_44 * V_60 , const char * V_3 )
{
return 0 ;
}
static struct V_67 * F_52 ( struct V_44 * V_60 )
{
return F_53 ( V_60 , struct V_67 , V_60 ) ;
}
static void F_54 ( struct V_26 * V_4 )
{
if ( F_55 ( & V_4 -> V_15 ) )
return;
F_56 ( & V_4 -> V_35 ) ;
F_57 ( & V_4 -> V_15 ) ;
}
static void F_58 ( struct V_67 * V_68 )
{
struct V_26 * V_4 = V_68 -> V_4 ;
F_54 ( V_4 ) ;
}
static int F_59 ( struct V_69 * V_70 ,
unsigned long V_71 , void * V_72 )
{
F_60 ( & V_73 ) ;
while ( ! F_61 ( & V_74 ) )
F_54 ( F_62 ( & V_74 ,
struct V_26 ,
V_35 ) ) ;
F_63 ( & V_73 ) ;
return V_75 ;
}
static T_3 F_64 ( struct V_76 * V_76 , struct V_77 * V_78 ,
char * V_4 )
{
return sprintf ( V_4 , L_7 , V_11 ) ;
}
static T_3 F_65 ( struct V_76 * V_76 , struct V_77 * V_78 ,
const char * V_4 , T_1 V_79 )
{
V_11 = F_66 ( V_4 , NULL , 10 ) ;
if ( V_11 < 0 )
V_11 = 0 ;
return V_79 ;
}
static void F_67 ( struct V_44 * V_60 )
{
struct V_67 * V_68 = F_52 ( V_60 ) ;
F_17 ( V_68 ) ;
}
static int F_68 ( struct V_67 * V_68 , struct V_80 * V_81 )
{
if ( F_69 ( V_81 , L_8 , V_68 -> V_4 -> V_32 ) )
return - V_42 ;
if ( F_69 ( V_81 , L_9 , V_11 ) )
return - V_42 ;
if ( F_69 ( V_81 , L_10 , V_68 -> V_82 ) )
return - V_42 ;
return 0 ;
}
static int F_70 ( struct V_44 * V_60 , struct V_80 * V_81 )
{
struct V_67 * V_68 = F_52 ( V_60 ) ;
int V_83 = 0 ;
F_60 ( & V_73 ) ;
if ( V_68 -> V_4 )
V_83 = F_68 ( V_68 , V_81 ) ;
F_63 ( & V_73 ) ;
return V_83 ;
}
static T_3 F_71 ( struct V_44 * V_60 ,
struct V_84 * V_78 , char * V_4 )
{
struct V_67 * V_68 = F_52 ( V_60 ) ;
int V_85 = 0 ;
F_60 ( & V_73 ) ;
if ( V_68 -> V_4 )
V_85 = F_72 ( & V_68 -> V_4 -> V_15 ) ;
F_63 ( & V_73 ) ;
return sprintf ( V_4 , L_7 , V_85 ) ;
}
static int F_73 ( struct V_26 * V_4 )
{
if ( ! V_4 -> V_86 )
return 0 ;
F_74 ( V_4 -> V_10 ) ;
V_4 -> V_10 = F_75 ( V_4 -> V_59 , V_4 -> V_87 , 0 , V_88 ) ;
if ( ! V_4 -> V_10 )
return - V_42 ;
return 0 ;
}
static T_3 F_76 ( struct V_44 * V_60 ,
struct V_84 * V_78 ,
const char * V_4 , T_1 V_79 )
{
struct V_67 * V_68 = F_52 ( V_60 ) ;
struct V_26 * V_89 ;
T_3 V_90 = V_79 ;
int V_85 = F_66 ( V_4 , NULL , 10 ) ;
int V_45 ;
F_60 ( & V_73 ) ;
V_89 = V_68 -> V_4 ;
if ( F_77 ( & V_89 -> V_15 ) )
goto V_91;
switch ( V_85 ) {
case 1 :
if ( ! F_55 ( & V_89 -> V_15 ) ) {
for ( V_45 = 0 ; V_45 < V_89 -> V_87 ; V_45 ++ )
F_78 ( V_89 -> V_59 [ V_45 ] ) ;
F_41 ( V_89 -> V_59 ) ;
V_89 -> V_59 = NULL ;
V_89 -> V_92 = 0 ;
V_89 -> V_87 = 0 ;
F_79 ( & V_89 -> V_15 ) ;
}
break;
case 0 :
if ( F_72 ( & V_89 -> V_15 ) ) {
int V_47 ;
V_47 = F_73 ( V_89 ) ;
if ( V_47 )
F_80 ( V_60 , L_11 ,
V_36 ) ;
else
V_47 = F_81 ( NULL ,
V_89 -> V_10 , V_89 -> V_5 ,
V_51 ) ;
F_56 ( & V_89 -> V_35 ) ;
if ( V_47 ) {
F_57 ( & V_89 -> V_15 ) ;
V_90 = V_47 ;
} else {
F_38 ( & V_89 -> V_15 ) ;
}
break;
}
default:
F_80 ( V_60 , L_12 , V_36 , V_85 ) ;
case - 1 :
F_58 ( V_68 ) ;
break;
}
V_91:
F_63 ( & V_73 ) ;
return V_90 ;
}
static void F_82 ( struct V_26 * V_4 , char * V_93 ,
T_2 V_94 , T_1 V_79 , bool V_95 )
{
if ( V_95 )
memcpy ( V_93 , V_4 -> V_10 + V_94 , V_79 ) ;
else
memcpy ( V_4 -> V_10 + V_94 , V_93 , V_79 ) ;
}
static void F_83 ( struct V_26 * V_4 , char * V_93 ,
T_2 V_94 , T_1 V_79 , bool V_95 )
{
while ( V_79 ) {
void * V_96 ;
int V_97 = V_94 >> V_98 ;
int V_99 = V_94 & ( V_100 - 1 ) ;
int V_101 = F_84 ( T_1 , V_100 - V_99 , V_79 ) ;
V_96 = F_85 ( V_4 -> V_59 [ V_97 ] ) ;
if ( V_95 )
memcpy ( V_93 , V_96 + V_99 , V_101 ) ;
else
memcpy ( V_96 + V_99 , V_93 , V_101 ) ;
F_86 ( V_4 -> V_59 [ V_97 ] ) ;
V_93 += V_101 ;
V_94 += V_101 ;
V_79 -= V_101 ;
}
}
static T_3 F_87 ( struct V_102 * V_103 , struct V_104 * V_105 ,
struct V_106 * V_107 ,
char * V_93 , T_2 V_94 , T_1 V_79 )
{
struct V_44 * V_60 = F_88 ( V_105 ) ;
struct V_67 * V_68 = F_52 ( V_60 ) ;
struct V_26 * V_4 ;
T_3 V_108 ;
F_60 ( & V_73 ) ;
V_4 = V_68 -> V_4 ;
if ( ! V_4 || F_55 ( & V_4 -> V_15 ) ) {
V_108 = - V_109 ;
goto V_91;
}
if ( V_94 > V_4 -> V_5 ) {
V_108 = 0 ;
goto V_91;
}
if ( V_79 > V_4 -> V_5 - V_94 )
V_79 = V_4 -> V_5 - V_94 ;
V_108 = V_79 ;
if ( V_4 -> V_10 )
F_82 ( V_4 , V_93 , V_94 , V_79 , true ) ;
else
F_83 ( V_4 , V_93 , V_94 , V_79 , true ) ;
V_91:
F_63 ( & V_73 ) ;
return V_108 ;
}
static int F_89 ( struct V_67 * V_68 , int V_110 )
{
struct V_26 * V_4 = V_68 -> V_4 ;
int V_111 = F_90 ( V_110 ) >> V_98 ;
if ( V_4 -> V_92 < V_111 ) {
int V_112 = F_91 ( V_111 ,
V_4 -> V_92 * 2 ) ;
struct V_113 * * V_114 ;
V_114 = F_92 ( V_112 * sizeof( void * ) ) ;
if ( ! V_114 ) {
F_58 ( V_68 ) ;
return - V_42 ;
}
memcpy ( V_114 , V_4 -> V_59 ,
V_4 -> V_92 * sizeof( void * ) ) ;
memset ( & V_114 [ V_4 -> V_92 ] , 0 , sizeof( void * ) *
( V_112 - V_4 -> V_92 ) ) ;
F_41 ( V_4 -> V_59 ) ;
V_4 -> V_59 = V_114 ;
V_4 -> V_92 = V_112 ;
}
while ( V_4 -> V_87 < V_111 ) {
V_4 -> V_59 [ V_4 -> V_87 ] =
F_93 ( V_66 | V_115 ) ;
if ( ! V_4 -> V_59 [ V_4 -> V_87 ] ) {
F_58 ( V_68 ) ;
return - V_42 ;
}
V_4 -> V_87 ++ ;
}
return 0 ;
}
static T_3 F_94 ( struct V_102 * V_103 , struct V_104 * V_105 ,
struct V_106 * V_107 ,
char * V_93 , T_2 V_94 , T_1 V_79 )
{
struct V_44 * V_60 = F_88 ( V_105 ) ;
struct V_67 * V_68 = F_52 ( V_60 ) ;
struct V_26 * V_4 ;
T_3 V_116 ;
if ( ! F_95 ( V_117 ) )
return - V_118 ;
F_60 ( & V_73 ) ;
V_4 = V_68 -> V_4 ;
if ( ! V_4 || F_55 ( & V_4 -> V_15 ) ) {
V_116 = - V_109 ;
goto V_91;
}
if ( V_4 -> V_10 ) {
if ( V_94 + V_79 > V_4 -> V_34 ) {
V_116 = - V_42 ;
goto V_91;
}
F_82 ( V_4 , V_93 , V_94 , V_79 , false ) ;
V_116 = V_79 ;
} else {
V_116 = F_89 ( V_68 , V_94 + V_79 ) ;
if ( V_116 )
goto V_91;
V_116 = V_79 ;
F_83 ( V_4 , V_93 , V_94 , V_79 , false ) ;
}
V_4 -> V_5 = F_96 ( T_1 , V_94 + V_79 , V_4 -> V_5 ) ;
V_91:
F_63 ( & V_73 ) ;
return V_116 ;
}
static struct V_67 *
F_97 ( struct V_1 * V_1 , const char * V_27 ,
struct V_44 * V_44 , unsigned int V_119 )
{
struct V_67 * V_68 ;
struct V_44 * V_120 ;
V_68 = F_15 ( sizeof( * V_68 ) , V_66 ) ;
if ( ! V_68 ) {
V_68 = F_98 ( - V_42 ) ;
goto exit;
}
V_68 -> V_82 = ! ! ( V_119 & V_121 ) ;
V_68 -> V_2 = V_1 ;
V_120 = & V_68 -> V_60 ;
F_99 ( V_120 ) ;
F_100 ( V_120 , L_13 , V_27 ) ;
V_120 -> V_122 = V_44 ;
V_120 -> V_76 = & V_123 ;
V_120 -> V_124 = V_125 ;
exit:
return V_68 ;
}
static int F_101 ( struct V_67 * V_68 ,
unsigned int V_119 , long V_22 )
{
int V_116 = 0 ;
struct V_44 * V_120 = & V_68 -> V_60 ;
struct V_26 * V_4 = V_68 -> V_4 ;
if ( ! V_4 -> V_10 )
V_4 -> V_86 = true ;
F_102 ( V_120 , true ) ;
V_116 = F_103 ( V_120 ) ;
if ( V_116 ) {
F_80 ( V_120 , L_14 , V_36 ) ;
goto V_126;
}
F_60 ( & V_73 ) ;
F_28 ( & V_4 -> V_35 , & V_74 ) ;
F_63 ( & V_73 ) ;
if ( V_119 & V_127 ) {
V_4 -> V_128 = true ;
F_102 ( V_120 , false ) ;
F_36 ( V_120 , L_15 , V_4 -> V_32 ) ;
F_104 ( & V_68 -> V_60 . V_105 , V_129 ) ;
} else {
V_22 = V_13 ;
}
V_116 = F_105 ( & V_4 -> V_15 , V_22 ) ;
if ( V_116 < 0 ) {
F_60 ( & V_73 ) ;
F_58 ( V_68 ) ;
F_63 ( & V_73 ) ;
}
if ( F_77 ( & V_4 -> V_15 ) )
V_116 = - V_130 ;
else if ( V_4 -> V_86 && ! V_4 -> V_10 )
V_116 = - V_42 ;
F_106 ( V_120 ) ;
V_126:
F_107 ( V_120 ) ;
return V_116 ;
}
static int F_108 ( struct V_1 * V_1 ,
const char * V_3 , struct V_44 * V_44 ,
unsigned int V_119 , long V_22 )
{
struct V_67 * V_68 ;
V_68 = F_97 ( V_1 , V_3 , V_44 , V_119 ) ;
if ( F_109 ( V_68 ) )
return F_110 ( V_68 ) ;
V_68 -> V_4 = V_1 -> V_58 ;
return F_101 ( V_68 , V_119 , V_22 ) ;
}
static void F_111 ( void )
{
struct V_26 * V_4 ;
struct V_26 * V_131 ;
F_60 ( & V_73 ) ;
F_112 (buf, next, &pending_fw_head, pending_list) {
if ( ! V_4 -> V_128 )
F_54 ( V_4 ) ;
}
F_63 ( & V_73 ) ;
}
static inline int
F_108 ( struct V_1 * V_1 , const char * V_3 ,
struct V_44 * V_44 , unsigned int V_119 ,
long V_22 )
{
return - V_24 ;
}
static inline void F_111 ( void ) { }
static int
F_113 ( struct V_1 * * V_132 , const char * V_3 ,
struct V_44 * V_44 , void * V_30 , T_1 V_5 )
{
struct V_1 * V_1 ;
struct V_26 * V_4 ;
int V_23 ;
* V_132 = V_1 = F_15 ( sizeof( * V_1 ) , V_66 ) ;
if ( ! V_1 ) {
F_80 ( V_44 , L_16 ,
V_36 ) ;
return - V_42 ;
}
if ( F_1 ( V_1 , V_3 , V_30 , V_5 ) ) {
F_36 ( V_44 , L_17 , V_3 ) ;
return 0 ;
}
V_23 = F_24 ( V_3 , & V_38 , & V_4 , V_30 , V_5 ) ;
V_1 -> V_58 = V_4 ;
if ( V_23 > 0 ) {
V_23 = F_114 ( & V_4 -> V_15 ) ;
if ( ! V_23 ) {
F_42 ( V_4 , V_1 ) ;
return 0 ;
}
}
if ( V_23 < 0 )
return V_23 ;
return 1 ;
}
static int F_115 ( struct V_1 * V_2 , struct V_44 * V_44 ,
unsigned int V_119 )
{
struct V_26 * V_4 = V_2 -> V_58 ;
F_60 ( & V_73 ) ;
if ( ! V_4 -> V_5 || F_77 ( & V_4 -> V_15 ) ) {
F_63 ( & V_73 ) ;
return - V_24 ;
}
if ( V_44 && ( V_119 & V_127 ) &&
! ( V_119 & V_133 ) )
F_48 ( V_44 , V_4 -> V_32 ) ;
if ( ! ( V_119 & V_133 ) &&
V_4 -> V_29 -> V_134 == V_135 ) {
if ( F_116 ( V_4 -> V_32 ) )
F_26 ( & V_4 -> V_33 ) ;
}
F_42 ( V_4 , V_2 ) ;
F_63 ( & V_73 ) ;
return 0 ;
}
static int
F_117 ( const struct V_1 * * V_132 , const char * V_3 ,
struct V_44 * V_44 , void * V_4 , T_1 V_5 ,
unsigned int V_119 )
{
struct V_1 * V_2 = NULL ;
long V_22 ;
int V_23 ;
if ( ! V_132 )
return - V_136 ;
if ( ! V_3 || V_3 [ 0 ] == '\0' ) {
V_23 = - V_136 ;
goto V_91;
}
V_23 = F_113 ( & V_2 , V_3 , V_44 , V_4 , V_5 ) ;
if ( V_23 <= 0 )
goto V_91;
V_23 = 0 ;
V_22 = F_3 () ;
if ( V_119 & V_121 ) {
V_22 = F_118 ( V_22 ) ;
if ( ! V_22 ) {
F_36 ( V_44 , L_18 ,
V_3 ) ;
V_23 = - V_137 ;
goto V_91;
}
} else {
V_23 = F_119 () ;
if ( F_120 ( V_23 ) ) {
F_80 ( V_44 , L_19 ,
V_3 ) ;
goto V_91;
}
}
V_23 = F_32 ( V_44 , V_2 -> V_58 ) ;
if ( V_23 ) {
if ( ! ( V_119 & V_138 ) )
F_37 ( V_44 ,
L_20 ,
V_3 , V_23 ) ;
if ( V_119 & V_139 ) {
F_37 ( V_44 , L_21 ) ;
V_23 = F_108 ( V_2 , V_3 , V_44 ,
V_119 , V_22 ) ;
}
}
if ( ! V_23 )
V_23 = F_115 ( V_2 , V_44 , V_119 ) ;
F_121 () ;
V_91:
if ( V_23 < 0 ) {
F_122 ( V_2 ) ;
V_2 = NULL ;
}
* V_132 = V_2 ;
return V_23 ;
}
int
F_123 ( const struct V_1 * * V_132 , const char * V_3 ,
struct V_44 * V_44 )
{
int V_23 ;
F_124 ( V_140 ) ;
V_23 = F_117 ( V_132 , V_3 , V_44 , NULL , 0 ,
V_127 | V_141 ) ;
F_125 ( V_140 ) ;
return V_23 ;
}
int F_126 ( const struct V_1 * * V_132 ,
const char * V_3 , struct V_44 * V_44 )
{
int V_23 ;
F_124 ( V_140 ) ;
V_23 = F_117 ( V_132 , V_3 , V_44 , NULL , 0 ,
V_127 | V_138 ) ;
F_125 ( V_140 ) ;
return V_23 ;
}
int
F_127 ( const struct V_1 * * V_132 , const char * V_3 ,
struct V_44 * V_44 , void * V_4 , T_1 V_5 )
{
int V_23 ;
F_124 ( V_140 ) ;
V_23 = F_117 ( V_132 , V_3 , V_44 , V_4 , V_5 ,
V_127 | V_141 |
V_133 ) ;
F_125 ( V_140 ) ;
return V_23 ;
}
void F_122 ( const struct V_1 * V_2 )
{
if ( V_2 ) {
if ( ! F_2 ( V_2 ) )
F_40 ( V_2 ) ;
F_17 ( V_2 ) ;
}
}
static void F_128 ( struct V_142 * V_143 )
{
struct V_144 * V_145 ;
const struct V_1 * V_2 ;
V_145 = F_53 ( V_143 , struct V_144 , V_143 ) ;
F_117 ( & V_2 , V_145 -> V_3 , V_145 -> V_44 , NULL , 0 ,
V_145 -> V_119 ) ;
V_145 -> V_146 ( V_2 , V_145 -> V_147 ) ;
F_107 ( V_145 -> V_44 ) ;
F_125 ( V_145 -> V_148 ) ;
F_44 ( V_145 -> V_3 ) ;
F_17 ( V_145 ) ;
}
int
F_129 (
struct V_148 * V_148 , bool V_149 ,
const char * V_3 , struct V_44 * V_44 , T_4 V_150 , void * V_147 ,
void (* V_146)( const struct V_1 * V_2 , void * V_147 ) )
{
struct V_144 * V_145 ;
V_145 = F_15 ( sizeof( struct V_144 ) , V_150 ) ;
if ( ! V_145 )
return - V_42 ;
V_145 -> V_148 = V_148 ;
V_145 -> V_3 = F_16 ( V_3 , V_150 ) ;
if ( ! V_145 -> V_3 ) {
F_17 ( V_145 ) ;
return - V_42 ;
}
V_145 -> V_44 = V_44 ;
V_145 -> V_147 = V_147 ;
V_145 -> V_146 = V_146 ;
V_145 -> V_119 = V_121 | V_141 |
( V_149 ? V_127 : V_139 ) ;
if ( ! F_130 ( V_148 ) ) {
F_44 ( V_145 -> V_3 ) ;
F_17 ( V_145 ) ;
return - V_151 ;
}
F_131 ( V_145 -> V_44 ) ;
F_132 ( & V_145 -> V_143 , F_128 ) ;
F_133 ( & V_145 -> V_143 ) ;
return 0 ;
}
static int F_134 ( const char * V_27 )
{
int V_23 ;
const struct V_1 * V_2 ;
F_21 ( L_22 , V_36 , V_27 ) ;
V_23 = F_123 ( & V_2 , V_27 , NULL ) ;
if ( ! V_23 )
F_17 ( V_2 ) ;
F_21 ( L_23 , V_36 , V_27 , V_23 ) ;
return V_23 ;
}
static struct V_26 * F_135 ( const char * V_27 )
{
struct V_26 * V_37 ;
struct V_28 * V_29 = & V_38 ;
F_25 ( & V_29 -> V_39 ) ;
V_37 = F_22 ( V_27 ) ;
F_27 ( & V_29 -> V_39 ) ;
return V_37 ;
}
static int F_136 ( const char * V_27 )
{
struct V_26 * V_4 ;
struct V_1 V_2 ;
F_21 ( L_22 , V_36 , V_27 ) ;
if ( F_1 ( & V_2 , V_27 , NULL , 0 ) )
return 0 ;
V_4 = F_135 ( V_27 ) ;
if ( V_4 ) {
F_30 ( V_4 ) ;
return 0 ;
}
return - V_136 ;
}
static struct V_152 * F_137 ( const char * V_3 )
{
struct V_152 * V_153 ;
V_153 = F_15 ( sizeof( * V_153 ) , V_31 ) ;
if ( ! V_153 )
goto exit;
V_153 -> V_3 = F_16 ( V_3 , V_31 ) ;
if ( ! V_153 -> V_3 ) {
F_17 ( V_153 ) ;
V_153 = NULL ;
goto exit;
}
exit:
return V_153 ;
}
static int F_138 ( const char * V_3 )
{
struct V_28 * V_29 = & V_38 ;
struct V_152 * V_153 ;
F_23 (fce, &fwc->fw_names, list) {
if ( ! strcmp ( V_153 -> V_3 , V_3 ) )
return 1 ;
}
return 0 ;
}
static int F_116 ( const char * V_3 )
{
struct V_28 * V_29 = & V_38 ;
struct V_152 * V_153 ;
int V_23 = 0 ;
F_25 ( & V_29 -> V_154 ) ;
if ( F_138 ( V_3 ) )
goto V_155;
V_153 = F_137 ( V_3 ) ;
if ( V_153 ) {
V_23 = 1 ;
F_28 ( & V_153 -> V_40 , & V_29 -> V_156 ) ;
F_21 ( L_24 , V_36 , V_3 ) ;
}
V_155:
F_27 ( & V_29 -> V_154 ) ;
return V_23 ;
}
static void F_139 ( struct V_152 * V_153 )
{
F_44 ( V_153 -> V_3 ) ;
F_17 ( V_153 ) ;
}
static void F_140 ( void * V_157 ,
T_5 V_158 )
{
struct V_152 * V_153 = V_157 ;
struct V_28 * V_29 = & V_38 ;
int V_23 ;
V_23 = F_134 ( V_153 -> V_3 ) ;
if ( V_23 ) {
F_25 ( & V_29 -> V_154 ) ;
F_141 ( & V_153 -> V_40 ) ;
F_27 ( & V_29 -> V_154 ) ;
F_139 ( V_153 ) ;
}
}
static void F_142 ( struct V_44 * V_60 , void * V_61 ,
void * V_10 )
{
struct V_62 * V_63 = V_61 ;
const char * V_27 = V_63 -> V_3 ;
struct V_159 * V_41 = V_10 ;
struct V_152 * V_153 ;
V_153 = F_137 ( V_27 ) ;
if ( V_153 )
F_28 ( & V_153 -> V_40 , V_41 ) ;
}
static int F_143 ( struct V_44 * V_60 , void * V_61 ,
void * V_65 )
{
struct V_62 * V_63 = V_61 ;
return ( V_63 -> V_64 == ( unsigned long ) V_65 ) ;
}
static void F_144 ( struct V_44 * V_60 , void * V_10 )
{
F_145 ( V_160 ) ;
struct V_152 * V_153 ;
struct V_152 * V_161 ;
struct V_28 * V_29 = & V_38 ;
F_146 ( V_60 , F_43 ,
F_143 , & V_38 ,
F_142 , & V_160 ) ;
F_112 (fce, fce_next, &todo, list) {
F_141 ( & V_153 -> V_40 ) ;
F_25 ( & V_29 -> V_154 ) ;
if ( ! F_138 ( V_153 -> V_3 ) ) {
F_28 ( & V_153 -> V_40 , & V_29 -> V_156 ) ;
} else {
F_139 ( V_153 ) ;
V_153 = NULL ;
}
F_27 ( & V_29 -> V_154 ) ;
if ( V_153 )
F_147 ( F_140 ,
( void * ) V_153 ,
& V_162 ) ;
}
}
static void F_148 ( void )
{
struct V_28 * V_29 = & V_38 ;
struct V_152 * V_153 ;
F_25 ( & V_29 -> V_154 ) ;
while ( ! F_61 ( & V_29 -> V_156 ) ) {
V_153 = F_149 ( V_29 -> V_156 . V_131 ,
struct V_152 , V_40 ) ;
F_141 ( & V_153 -> V_40 ) ;
F_27 ( & V_29 -> V_154 ) ;
F_136 ( V_153 -> V_3 ) ;
F_139 ( V_153 ) ;
F_25 ( & V_29 -> V_154 ) ;
}
F_27 ( & V_29 -> V_154 ) ;
}
static void F_150 ( void )
{
struct V_28 * V_29 = & V_38 ;
int V_163 ;
F_151 ( V_164 ) ;
F_21 ( L_25 , V_36 ) ;
F_152 ( & V_29 -> V_143 ) ;
V_163 = V_11 ;
V_11 = 10 ;
F_60 ( & V_73 ) ;
V_29 -> V_134 = V_135 ;
F_153 ( NULL , F_144 ) ;
F_63 ( & V_73 ) ;
F_154 ( & V_162 ) ;
V_11 = V_163 ;
}
static void F_155 ( void )
{
F_21 ( L_25 , V_36 ) ;
F_148 () ;
}
static void F_156 ( struct V_142 * V_143 )
{
F_155 () ;
}
static void F_157 ( unsigned long V_165 )
{
F_158 ( V_166 , & V_38 . V_143 ,
F_159 ( V_165 ) ) ;
}
static int F_160 ( struct V_69 * V_167 ,
unsigned long V_168 , void * V_169 )
{
switch ( V_168 ) {
case V_170 :
case V_171 :
case V_172 :
F_111 () ;
F_150 () ;
break;
case V_173 :
case V_174 :
case V_175 :
F_60 ( & V_73 ) ;
V_38 . V_134 = V_176 ;
F_63 ( & V_73 ) ;
F_157 ( 10 * V_177 ) ;
break;
}
return 0 ;
}
static int F_161 ( void )
{
V_38 . V_134 = V_176 ;
return 0 ;
}
static int F_116 ( const char * V_3 )
{
return 0 ;
}
static void T_6 F_162 ( void )
{
F_163 ( & V_38 . V_39 ) ;
F_20 ( & V_38 . V_41 ) ;
V_38 . V_134 = V_176 ;
#ifdef F_164
F_163 ( & V_38 . V_154 ) ;
F_20 ( & V_38 . V_156 ) ;
F_165 ( & V_38 . V_143 ,
F_156 ) ;
V_38 . V_178 . V_179 = F_160 ;
F_166 ( & V_38 . V_178 ) ;
F_167 ( & V_180 ) ;
#endif
}
static int T_6 F_168 ( void )
{
F_162 () ;
#ifdef F_19
F_169 ( & V_181 ) ;
return F_170 ( & V_123 ) ;
#else
return 0 ;
#endif
}
static void T_7 F_171 ( void )
{
#ifdef F_164
F_172 ( & V_180 ) ;
F_173 ( & V_38 . V_178 ) ;
#endif
#ifdef F_19
F_174 ( & V_181 ) ;
F_175 ( & V_123 ) ;
#endif
}
