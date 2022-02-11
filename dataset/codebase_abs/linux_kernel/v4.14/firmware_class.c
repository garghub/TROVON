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
static struct V_26 * F_13 ( const char * V_27 ,
struct V_28 * V_29 ,
void * V_30 , T_1 V_5 )
{
struct V_26 * V_4 ;
V_4 = F_14 ( sizeof( * V_4 ) , V_31 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_32 = F_15 ( V_27 , V_31 ) ;
if ( ! V_4 -> V_32 ) {
F_16 ( V_4 ) ;
return NULL ;
}
F_17 ( & V_4 -> V_33 ) ;
V_4 -> V_29 = V_29 ;
V_4 -> V_10 = V_30 ;
V_4 -> V_34 = V_5 ;
F_4 ( & V_4 -> V_15 ) ;
#ifdef F_18
F_19 ( & V_4 -> V_35 ) ;
#endif
F_20 ( L_1 , V_36 , V_27 , V_4 ) ;
return V_4 ;
}
static struct V_26 * F_21 ( const char * V_27 )
{
struct V_26 * V_37 ;
struct V_28 * V_29 = & V_38 ;
F_22 (tmp, &fwc->head, list)
if ( ! strcmp ( V_37 -> V_32 , V_27 ) )
return V_37 ;
return NULL ;
}
static int F_23 ( const char * V_27 ,
struct V_28 * V_29 ,
struct V_26 * * V_4 , void * V_30 ,
T_1 V_5 )
{
struct V_26 * V_37 ;
F_24 ( & V_29 -> V_39 ) ;
V_37 = F_21 ( V_27 ) ;
if ( V_37 ) {
F_25 ( & V_37 -> V_33 ) ;
F_26 ( & V_29 -> V_39 ) ;
* V_4 = V_37 ;
F_20 ( L_2 ) ;
return 1 ;
}
V_37 = F_13 ( V_27 , V_29 , V_30 , V_5 ) ;
if ( V_37 )
F_27 ( & V_37 -> V_40 , & V_29 -> V_41 ) ;
F_26 ( & V_29 -> V_39 ) ;
* V_4 = V_37 ;
return V_37 ? 0 : - V_42 ;
}
static void F_28 ( struct V_43 * V_33 )
__releases( &fwc->lock
static void F_29 ( struct V_26 * V_4 )
{
struct V_28 * V_29 = V_4 -> V_29 ;
F_24 ( & V_29 -> V_39 ) ;
if ( ! F_30 ( & V_4 -> V_33 , F_28 ) )
F_26 ( & V_29 -> V_39 ) ;
}
static int
F_31 ( struct V_44 * V_44 , struct V_26 * V_4 )
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
V_48 = F_32 () ;
if ( ! V_48 )
return - V_42 ;
for ( V_45 = 0 ; V_45 < F_33 ( V_55 ) ; V_45 ++ ) {
if ( ! V_55 [ V_45 ] [ 0 ] )
continue;
V_46 = snprintf ( V_48 , V_56 , L_3 ,
V_55 [ V_45 ] , V_4 -> V_32 ) ;
if ( V_46 >= V_56 ) {
V_47 = - V_57 ;
break;
}
V_4 -> V_5 = 0 ;
V_47 = F_34 ( V_48 , & V_4 -> V_10 , & V_5 , V_52 ,
V_50 ) ;
if ( V_47 ) {
if ( V_47 == - V_24 )
F_35 ( V_44 , L_4 ,
V_48 , V_47 ) ;
else
F_36 ( V_44 , L_4 ,
V_48 , V_47 ) ;
continue;
}
F_35 ( V_44 , L_5 , V_4 -> V_32 ) ;
V_4 -> V_5 = V_5 ;
F_37 ( & V_4 -> V_15 ) ;
break;
}
F_38 ( V_48 ) ;
return V_47 ;
}
static void F_39 ( const struct V_1 * V_2 )
{
if ( ! V_2 -> V_58 ) {
F_40 ( V_2 -> V_10 ) ;
return;
}
F_29 ( V_2 -> V_58 ) ;
}
static void F_41 ( struct V_26 * V_4 , struct V_1 * V_2 )
{
V_2 -> V_58 = V_4 ;
#ifdef F_18
V_2 -> V_59 = V_4 -> V_59 ;
#endif
V_2 -> V_5 = V_4 -> V_5 ;
V_2 -> V_10 = V_4 -> V_10 ;
F_20 ( L_6 ,
V_36 , V_4 -> V_32 , V_4 , V_4 -> V_10 ,
( unsigned int ) V_4 -> V_5 ) ;
}
static void F_42 ( struct V_44 * V_60 , void * V_61 )
{
struct V_62 * V_63 = V_61 ;
if ( V_63 -> V_64 == ( unsigned long ) & V_38 )
F_20 ( L_7 ,
V_36 , V_63 -> V_3 , V_61 ) ;
F_43 ( V_63 -> V_3 ) ;
}
static int F_44 ( struct V_44 * V_60 , void * V_61 ,
void * V_65 )
{
struct V_62 * V_63 = V_61 ;
return ( V_63 -> V_64 == ( unsigned long ) & V_38 ) &&
! strcmp ( V_63 -> V_3 , V_65 ) ;
}
static struct V_62 * F_45 ( struct V_44 * V_60 ,
const char * V_3 )
{
struct V_62 * V_63 ;
V_63 = F_46 ( V_60 , F_42 ,
F_44 , ( void * ) V_3 ) ;
return V_63 ;
}
static int F_47 ( struct V_44 * V_60 , const char * V_3 )
{
struct V_62 * V_63 ;
V_63 = F_45 ( V_60 , V_3 ) ;
if ( V_63 )
return 1 ;
V_63 = F_48 ( F_42 , sizeof( struct V_62 ) ,
V_66 ) ;
if ( ! V_63 )
return - V_42 ;
V_63 -> V_3 = F_15 ( V_3 , V_66 ) ;
if ( ! V_63 -> V_3 ) {
F_49 ( V_63 ) ;
return - V_42 ;
}
V_63 -> V_64 = ( unsigned long ) & V_38 ;
F_50 ( V_60 , V_63 ) ;
return 0 ;
}
static int F_47 ( struct V_44 * V_60 , const char * V_3 )
{
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , struct V_44 * V_44 ,
unsigned int V_67 )
{
struct V_26 * V_4 = V_2 -> V_58 ;
F_52 ( & V_68 ) ;
if ( ! V_4 -> V_5 || F_53 ( & V_4 -> V_15 ) ) {
F_54 ( & V_68 ) ;
return - V_24 ;
}
if ( V_44 && ( V_67 & V_69 ) &&
! ( V_67 & V_70 ) )
F_47 ( V_44 , V_4 -> V_32 ) ;
if ( ! ( V_67 & V_70 ) &&
V_4 -> V_29 -> V_71 == V_72 ) {
if ( F_55 ( V_4 -> V_32 ) )
F_25 ( & V_4 -> V_33 ) ;
}
F_41 ( V_4 , V_2 ) ;
F_54 ( & V_68 ) ;
return 0 ;
}
static struct V_73 * F_56 ( struct V_44 * V_60 )
{
return F_57 ( V_60 , struct V_73 , V_60 ) ;
}
static void F_58 ( struct V_26 * V_4 )
{
if ( F_59 ( & V_4 -> V_15 ) )
return;
F_60 ( & V_4 -> V_35 ) ;
F_61 ( & V_4 -> V_15 ) ;
}
static void F_62 ( struct V_73 * V_74 )
{
struct V_26 * V_4 = V_74 -> V_4 ;
F_58 ( V_4 ) ;
}
static void F_63 ( bool V_75 )
{
struct V_26 * V_4 ;
struct V_26 * V_76 ;
F_52 ( & V_68 ) ;
F_64 (buf, next, &pending_fw_head, pending_list) {
if ( ! V_4 -> V_77 || ! V_75 )
F_58 ( V_4 ) ;
}
F_54 ( & V_68 ) ;
}
static T_3 F_65 ( struct V_78 * V_78 , struct V_79 * V_80 ,
char * V_4 )
{
return sprintf ( V_4 , L_8 , V_11 ) ;
}
static T_3 F_66 ( struct V_78 * V_78 , struct V_79 * V_80 ,
const char * V_4 , T_1 V_81 )
{
V_11 = F_67 ( V_4 , NULL , 10 ) ;
if ( V_11 < 0 )
V_11 = 0 ;
return V_81 ;
}
static void F_68 ( struct V_44 * V_60 )
{
struct V_73 * V_74 = F_56 ( V_60 ) ;
F_16 ( V_74 ) ;
}
static int F_69 ( struct V_73 * V_74 , struct V_82 * V_83 )
{
if ( F_70 ( V_83 , L_9 , V_74 -> V_4 -> V_32 ) )
return - V_42 ;
if ( F_70 ( V_83 , L_10 , V_11 ) )
return - V_42 ;
if ( F_70 ( V_83 , L_11 , V_74 -> V_84 ) )
return - V_42 ;
return 0 ;
}
static int F_71 ( struct V_44 * V_60 , struct V_82 * V_83 )
{
struct V_73 * V_74 = F_56 ( V_60 ) ;
int V_85 = 0 ;
F_52 ( & V_68 ) ;
if ( V_74 -> V_4 )
V_85 = F_69 ( V_74 , V_83 ) ;
F_54 ( & V_68 ) ;
return V_85 ;
}
static T_3 F_72 ( struct V_44 * V_60 ,
struct V_86 * V_80 , char * V_4 )
{
struct V_73 * V_74 = F_56 ( V_60 ) ;
int V_87 = 0 ;
F_52 ( & V_68 ) ;
if ( V_74 -> V_4 )
V_87 = F_73 ( & V_74 -> V_4 -> V_15 ) ;
F_54 ( & V_68 ) ;
return sprintf ( V_4 , L_8 , V_87 ) ;
}
static int F_74 ( struct V_26 * V_4 )
{
if ( ! V_4 -> V_88 )
return 0 ;
F_75 ( V_4 -> V_10 ) ;
V_4 -> V_10 = F_76 ( V_4 -> V_59 , V_4 -> V_89 , 0 , V_90 ) ;
if ( ! V_4 -> V_10 )
return - V_42 ;
return 0 ;
}
static T_3 F_77 ( struct V_44 * V_60 ,
struct V_86 * V_80 ,
const char * V_4 , T_1 V_81 )
{
struct V_73 * V_74 = F_56 ( V_60 ) ;
struct V_26 * V_91 ;
T_3 V_92 = V_81 ;
int V_87 = F_67 ( V_4 , NULL , 10 ) ;
int V_45 ;
F_52 ( & V_68 ) ;
V_91 = V_74 -> V_4 ;
if ( F_53 ( & V_91 -> V_15 ) )
goto V_93;
switch ( V_87 ) {
case 1 :
if ( ! F_59 ( & V_91 -> V_15 ) ) {
for ( V_45 = 0 ; V_45 < V_91 -> V_89 ; V_45 ++ )
F_78 ( V_91 -> V_59 [ V_45 ] ) ;
F_40 ( V_91 -> V_59 ) ;
V_91 -> V_59 = NULL ;
V_91 -> V_94 = 0 ;
V_91 -> V_89 = 0 ;
F_79 ( & V_91 -> V_15 ) ;
}
break;
case 0 :
if ( F_73 ( & V_91 -> V_15 ) ) {
int V_47 ;
V_47 = F_74 ( V_91 ) ;
if ( V_47 )
F_80 ( V_60 , L_12 ,
V_36 ) ;
else
V_47 = F_81 ( NULL ,
V_91 -> V_10 , V_91 -> V_5 ,
V_51 ) ;
F_60 ( & V_91 -> V_35 ) ;
if ( V_47 ) {
F_61 ( & V_91 -> V_15 ) ;
V_92 = V_47 ;
} else {
F_37 ( & V_91 -> V_15 ) ;
}
break;
}
default:
F_80 ( V_60 , L_13 , V_36 , V_87 ) ;
case - 1 :
F_62 ( V_74 ) ;
break;
}
V_93:
F_54 ( & V_68 ) ;
return V_92 ;
}
static void F_82 ( struct V_26 * V_4 , char * V_95 ,
T_2 V_96 , T_1 V_81 , bool V_97 )
{
if ( V_97 )
memcpy ( V_95 , V_4 -> V_10 + V_96 , V_81 ) ;
else
memcpy ( V_4 -> V_10 + V_96 , V_95 , V_81 ) ;
}
static void F_83 ( struct V_26 * V_4 , char * V_95 ,
T_2 V_96 , T_1 V_81 , bool V_97 )
{
while ( V_81 ) {
void * V_98 ;
int V_99 = V_96 >> V_100 ;
int V_101 = V_96 & ( V_102 - 1 ) ;
int V_103 = F_84 ( T_1 , V_102 - V_101 , V_81 ) ;
V_98 = F_85 ( V_4 -> V_59 [ V_99 ] ) ;
if ( V_97 )
memcpy ( V_95 , V_98 + V_101 , V_103 ) ;
else
memcpy ( V_98 + V_101 , V_95 , V_103 ) ;
F_86 ( V_4 -> V_59 [ V_99 ] ) ;
V_95 += V_103 ;
V_96 += V_103 ;
V_81 -= V_103 ;
}
}
static T_3 F_87 ( struct V_104 * V_105 , struct V_106 * V_107 ,
struct V_108 * V_109 ,
char * V_95 , T_2 V_96 , T_1 V_81 )
{
struct V_44 * V_60 = F_88 ( V_107 ) ;
struct V_73 * V_74 = F_56 ( V_60 ) ;
struct V_26 * V_4 ;
T_3 V_110 ;
F_52 ( & V_68 ) ;
V_4 = V_74 -> V_4 ;
if ( ! V_4 || F_59 ( & V_4 -> V_15 ) ) {
V_110 = - V_111 ;
goto V_93;
}
if ( V_96 > V_4 -> V_5 ) {
V_110 = 0 ;
goto V_93;
}
if ( V_81 > V_4 -> V_5 - V_96 )
V_81 = V_4 -> V_5 - V_96 ;
V_110 = V_81 ;
if ( V_4 -> V_10 )
F_82 ( V_4 , V_95 , V_96 , V_81 , true ) ;
else
F_83 ( V_4 , V_95 , V_96 , V_81 , true ) ;
V_93:
F_54 ( & V_68 ) ;
return V_110 ;
}
static int F_89 ( struct V_73 * V_74 , int V_112 )
{
struct V_26 * V_4 = V_74 -> V_4 ;
int V_113 = F_90 ( V_112 ) >> V_100 ;
if ( V_4 -> V_94 < V_113 ) {
int V_114 = F_91 ( V_113 ,
V_4 -> V_94 * 2 ) ;
struct V_115 * * V_116 ;
V_116 = F_92 ( V_114 * sizeof( void * ) ) ;
if ( ! V_116 ) {
F_62 ( V_74 ) ;
return - V_42 ;
}
memcpy ( V_116 , V_4 -> V_59 ,
V_4 -> V_94 * sizeof( void * ) ) ;
memset ( & V_116 [ V_4 -> V_94 ] , 0 , sizeof( void * ) *
( V_114 - V_4 -> V_94 ) ) ;
F_40 ( V_4 -> V_59 ) ;
V_4 -> V_59 = V_116 ;
V_4 -> V_94 = V_114 ;
}
while ( V_4 -> V_89 < V_113 ) {
V_4 -> V_59 [ V_4 -> V_89 ] =
F_93 ( V_66 | V_117 ) ;
if ( ! V_4 -> V_59 [ V_4 -> V_89 ] ) {
F_62 ( V_74 ) ;
return - V_42 ;
}
V_4 -> V_89 ++ ;
}
return 0 ;
}
static T_3 F_94 ( struct V_104 * V_105 , struct V_106 * V_107 ,
struct V_108 * V_109 ,
char * V_95 , T_2 V_96 , T_1 V_81 )
{
struct V_44 * V_60 = F_88 ( V_107 ) ;
struct V_73 * V_74 = F_56 ( V_60 ) ;
struct V_26 * V_4 ;
T_3 V_118 ;
if ( ! F_95 ( V_119 ) )
return - V_120 ;
F_52 ( & V_68 ) ;
V_4 = V_74 -> V_4 ;
if ( ! V_4 || F_59 ( & V_4 -> V_15 ) ) {
V_118 = - V_111 ;
goto V_93;
}
if ( V_4 -> V_10 ) {
if ( V_96 + V_81 > V_4 -> V_34 ) {
V_118 = - V_42 ;
goto V_93;
}
F_82 ( V_4 , V_95 , V_96 , V_81 , false ) ;
V_118 = V_81 ;
} else {
V_118 = F_89 ( V_74 , V_96 + V_81 ) ;
if ( V_118 )
goto V_93;
V_118 = V_81 ;
F_83 ( V_4 , V_95 , V_96 , V_81 , false ) ;
}
V_4 -> V_5 = F_96 ( T_1 , V_96 + V_81 , V_4 -> V_5 ) ;
V_93:
F_54 ( & V_68 ) ;
return V_118 ;
}
static struct V_73 *
F_97 ( struct V_1 * V_1 , const char * V_27 ,
struct V_44 * V_44 , unsigned int V_67 )
{
struct V_73 * V_74 ;
struct V_44 * V_121 ;
V_74 = F_14 ( sizeof( * V_74 ) , V_66 ) ;
if ( ! V_74 ) {
V_74 = F_98 ( - V_42 ) ;
goto exit;
}
V_74 -> V_84 = ! ! ( V_67 & V_122 ) ;
V_74 -> V_2 = V_1 ;
V_121 = & V_74 -> V_60 ;
F_99 ( V_121 ) ;
F_100 ( V_121 , L_14 , V_27 ) ;
V_121 -> V_123 = V_44 ;
V_121 -> V_78 = & V_124 ;
V_121 -> V_125 = V_126 ;
exit:
return V_74 ;
}
static int F_101 ( struct V_73 * V_74 ,
unsigned int V_67 , long V_22 )
{
int V_118 = 0 ;
struct V_44 * V_121 = & V_74 -> V_60 ;
struct V_26 * V_4 = V_74 -> V_4 ;
if ( ! V_4 -> V_10 )
V_4 -> V_88 = true ;
F_102 ( V_121 , true ) ;
V_118 = F_103 ( V_121 ) ;
if ( V_118 ) {
F_80 ( V_121 , L_15 , V_36 ) ;
goto V_127;
}
F_52 ( & V_68 ) ;
F_27 ( & V_4 -> V_35 , & V_128 ) ;
F_54 ( & V_68 ) ;
if ( V_67 & V_69 ) {
V_4 -> V_77 = true ;
F_102 ( V_121 , false ) ;
F_35 ( V_121 , L_16 , V_4 -> V_32 ) ;
F_104 ( & V_74 -> V_60 . V_107 , V_129 ) ;
} else {
V_22 = V_13 ;
}
V_118 = F_105 ( & V_4 -> V_15 , V_22 ) ;
if ( V_118 < 0 ) {
F_52 ( & V_68 ) ;
F_62 ( V_74 ) ;
F_54 ( & V_68 ) ;
}
if ( F_53 ( & V_4 -> V_15 ) ) {
if ( V_118 == - V_130 )
V_118 = - V_131 ;
else
V_118 = - V_132 ;
} else if ( V_4 -> V_88 && ! V_4 -> V_10 )
V_118 = - V_42 ;
F_106 ( V_121 ) ;
V_127:
F_107 ( V_121 ) ;
return V_118 ;
}
static int F_108 ( struct V_1 * V_1 ,
const char * V_3 , struct V_44 * V_44 ,
unsigned int V_67 )
{
struct V_73 * V_74 ;
long V_22 ;
int V_23 ;
V_22 = F_3 () ;
if ( V_67 & V_122 ) {
V_22 = F_109 ( V_22 ) ;
if ( ! V_22 ) {
F_35 ( V_44 , L_17 ,
V_3 ) ;
return - V_133 ;
}
} else {
V_23 = F_110 () ;
if ( F_111 ( V_23 ) ) {
F_80 ( V_44 , L_18 ,
V_3 ) ;
return V_23 ;
}
}
V_74 = F_97 ( V_1 , V_3 , V_44 , V_67 ) ;
if ( F_112 ( V_74 ) ) {
V_23 = F_113 ( V_74 ) ;
goto V_134;
}
V_74 -> V_4 = V_1 -> V_58 ;
V_23 = F_101 ( V_74 , V_67 , V_22 ) ;
if ( ! V_23 )
V_23 = F_51 ( V_1 , V_44 , V_67 ) ;
V_134:
F_114 () ;
return V_23 ;
}
static inline int
F_108 ( struct V_1 * V_1 , const char * V_3 ,
struct V_44 * V_44 , unsigned int V_67 )
{
return - V_24 ;
}
static inline void F_63 ( bool V_75 ) { }
static int
F_115 ( struct V_1 * * V_135 , const char * V_3 ,
struct V_44 * V_44 , void * V_30 , T_1 V_5 )
{
struct V_1 * V_1 ;
struct V_26 * V_4 ;
int V_23 ;
* V_135 = V_1 = F_14 ( sizeof( * V_1 ) , V_66 ) ;
if ( ! V_1 ) {
F_80 ( V_44 , L_19 ,
V_36 ) ;
return - V_42 ;
}
if ( F_1 ( V_1 , V_3 , V_30 , V_5 ) ) {
F_35 ( V_44 , L_20 , V_3 ) ;
return 0 ;
}
V_23 = F_23 ( V_3 , & V_38 , & V_4 , V_30 , V_5 ) ;
V_1 -> V_58 = V_4 ;
if ( V_23 > 0 ) {
V_23 = F_116 ( & V_4 -> V_15 ) ;
if ( ! V_23 ) {
F_41 ( V_4 , V_1 ) ;
return 0 ;
}
}
if ( V_23 < 0 )
return V_23 ;
return 1 ;
}
static void F_117 ( struct V_1 * V_2 )
{
struct V_26 * V_4 ;
if ( ! V_2 || ! V_2 -> V_58 )
return;
V_4 = V_2 -> V_58 ;
if ( ! F_53 ( & V_4 -> V_15 ) )
F_61 ( & V_4 -> V_15 ) ;
}
static int
F_118 ( const struct V_1 * * V_135 , const char * V_3 ,
struct V_44 * V_44 , void * V_4 , T_1 V_5 ,
unsigned int V_67 )
{
struct V_1 * V_2 = NULL ;
int V_23 ;
if ( ! V_135 )
return - V_136 ;
if ( ! V_3 || V_3 [ 0 ] == '\0' ) {
V_23 = - V_136 ;
goto V_93;
}
V_23 = F_115 ( & V_2 , V_3 , V_44 , V_4 , V_5 ) ;
if ( V_23 <= 0 )
goto V_93;
V_23 = F_31 ( V_44 , V_2 -> V_58 ) ;
if ( V_23 ) {
if ( ! ( V_67 & V_137 ) )
F_36 ( V_44 ,
L_21 ,
V_3 , V_23 ) ;
if ( V_67 & V_138 ) {
F_36 ( V_44 , L_22 ) ;
V_23 = F_108 ( V_2 , V_3 , V_44 ,
V_67 ) ;
}
} else
V_23 = F_51 ( V_2 , V_44 , V_67 ) ;
V_93:
if ( V_23 < 0 ) {
F_117 ( V_2 ) ;
F_119 ( V_2 ) ;
V_2 = NULL ;
}
* V_135 = V_2 ;
return V_23 ;
}
int
F_120 ( const struct V_1 * * V_135 , const char * V_3 ,
struct V_44 * V_44 )
{
int V_23 ;
F_121 ( V_139 ) ;
V_23 = F_118 ( V_135 , V_3 , V_44 , NULL , 0 ,
V_69 | V_140 ) ;
F_122 ( V_139 ) ;
return V_23 ;
}
int F_123 ( const struct V_1 * * V_135 ,
const char * V_3 , struct V_44 * V_44 )
{
int V_23 ;
F_121 ( V_139 ) ;
V_23 = F_118 ( V_135 , V_3 , V_44 , NULL , 0 ,
V_69 | V_137 ) ;
F_122 ( V_139 ) ;
return V_23 ;
}
int
F_124 ( const struct V_1 * * V_135 , const char * V_3 ,
struct V_44 * V_44 , void * V_4 , T_1 V_5 )
{
int V_23 ;
F_121 ( V_139 ) ;
V_23 = F_118 ( V_135 , V_3 , V_44 , V_4 , V_5 ,
V_69 | V_140 |
V_70 ) ;
F_122 ( V_139 ) ;
return V_23 ;
}
void F_119 ( const struct V_1 * V_2 )
{
if ( V_2 ) {
if ( ! F_2 ( V_2 ) )
F_39 ( V_2 ) ;
F_16 ( V_2 ) ;
}
}
static void F_125 ( struct V_141 * V_142 )
{
struct V_143 * V_144 ;
const struct V_1 * V_2 ;
V_144 = F_57 ( V_142 , struct V_143 , V_142 ) ;
F_118 ( & V_2 , V_144 -> V_3 , V_144 -> V_44 , NULL , 0 ,
V_144 -> V_67 ) ;
V_144 -> V_145 ( V_2 , V_144 -> V_146 ) ;
F_107 ( V_144 -> V_44 ) ;
F_122 ( V_144 -> V_147 ) ;
F_43 ( V_144 -> V_3 ) ;
F_16 ( V_144 ) ;
}
int
F_126 (
struct V_147 * V_147 , bool V_148 ,
const char * V_3 , struct V_44 * V_44 , T_4 V_149 , void * V_146 ,
void (* V_145)( const struct V_1 * V_2 , void * V_146 ) )
{
struct V_143 * V_144 ;
V_144 = F_14 ( sizeof( struct V_143 ) , V_149 ) ;
if ( ! V_144 )
return - V_42 ;
V_144 -> V_147 = V_147 ;
V_144 -> V_3 = F_15 ( V_3 , V_149 ) ;
if ( ! V_144 -> V_3 ) {
F_16 ( V_144 ) ;
return - V_42 ;
}
V_144 -> V_44 = V_44 ;
V_144 -> V_146 = V_146 ;
V_144 -> V_145 = V_145 ;
V_144 -> V_67 = V_122 | V_140 |
( V_148 ? V_69 : V_138 ) ;
if ( ! F_127 ( V_147 ) ) {
F_43 ( V_144 -> V_3 ) ;
F_16 ( V_144 ) ;
return - V_150 ;
}
F_128 ( V_144 -> V_44 ) ;
F_129 ( & V_144 -> V_142 , F_125 ) ;
F_130 ( & V_144 -> V_142 ) ;
return 0 ;
}
static int F_131 ( const char * V_27 )
{
int V_23 ;
const struct V_1 * V_2 ;
F_20 ( L_23 , V_36 , V_27 ) ;
V_23 = F_120 ( & V_2 , V_27 , NULL ) ;
if ( ! V_23 )
F_16 ( V_2 ) ;
F_20 ( L_24 , V_36 , V_27 , V_23 ) ;
return V_23 ;
}
static struct V_26 * F_132 ( const char * V_27 )
{
struct V_26 * V_37 ;
struct V_28 * V_29 = & V_38 ;
F_24 ( & V_29 -> V_39 ) ;
V_37 = F_21 ( V_27 ) ;
F_26 ( & V_29 -> V_39 ) ;
return V_37 ;
}
static int F_133 ( const char * V_27 )
{
struct V_26 * V_4 ;
struct V_1 V_2 ;
F_20 ( L_23 , V_36 , V_27 ) ;
if ( F_1 ( & V_2 , V_27 , NULL , 0 ) )
return 0 ;
V_4 = F_132 ( V_27 ) ;
if ( V_4 ) {
F_29 ( V_4 ) ;
return 0 ;
}
return - V_136 ;
}
static struct V_151 * F_134 ( const char * V_3 )
{
struct V_151 * V_152 ;
V_152 = F_14 ( sizeof( * V_152 ) , V_31 ) ;
if ( ! V_152 )
goto exit;
V_152 -> V_3 = F_15 ( V_3 , V_31 ) ;
if ( ! V_152 -> V_3 ) {
F_16 ( V_152 ) ;
V_152 = NULL ;
goto exit;
}
exit:
return V_152 ;
}
static int F_135 ( const char * V_3 )
{
struct V_28 * V_29 = & V_38 ;
struct V_151 * V_152 ;
F_22 (fce, &fwc->fw_names, list) {
if ( ! strcmp ( V_152 -> V_3 , V_3 ) )
return 1 ;
}
return 0 ;
}
static int F_55 ( const char * V_3 )
{
struct V_28 * V_29 = & V_38 ;
struct V_151 * V_152 ;
int V_23 = 0 ;
F_24 ( & V_29 -> V_153 ) ;
if ( F_135 ( V_3 ) )
goto V_154;
V_152 = F_134 ( V_3 ) ;
if ( V_152 ) {
V_23 = 1 ;
F_27 ( & V_152 -> V_40 , & V_29 -> V_155 ) ;
F_20 ( L_25 , V_36 , V_3 ) ;
}
V_154:
F_26 ( & V_29 -> V_153 ) ;
return V_23 ;
}
static void F_136 ( struct V_151 * V_152 )
{
F_43 ( V_152 -> V_3 ) ;
F_16 ( V_152 ) ;
}
static void F_137 ( void * V_156 ,
T_5 V_157 )
{
struct V_151 * V_152 = V_156 ;
struct V_28 * V_29 = & V_38 ;
int V_23 ;
V_23 = F_131 ( V_152 -> V_3 ) ;
if ( V_23 ) {
F_24 ( & V_29 -> V_153 ) ;
F_138 ( & V_152 -> V_40 ) ;
F_26 ( & V_29 -> V_153 ) ;
F_136 ( V_152 ) ;
}
}
static void F_139 ( struct V_44 * V_60 , void * V_61 ,
void * V_10 )
{
struct V_62 * V_63 = V_61 ;
const char * V_27 = V_63 -> V_3 ;
struct V_158 * V_41 = V_10 ;
struct V_151 * V_152 ;
V_152 = F_134 ( V_27 ) ;
if ( V_152 )
F_27 ( & V_152 -> V_40 , V_41 ) ;
}
static int F_140 ( struct V_44 * V_60 , void * V_61 ,
void * V_65 )
{
struct V_62 * V_63 = V_61 ;
return ( V_63 -> V_64 == ( unsigned long ) V_65 ) ;
}
static void F_141 ( struct V_44 * V_60 , void * V_10 )
{
F_142 ( V_159 ) ;
struct V_151 * V_152 ;
struct V_151 * V_160 ;
struct V_28 * V_29 = & V_38 ;
F_143 ( V_60 , F_42 ,
F_140 , & V_38 ,
F_139 , & V_159 ) ;
F_64 (fce, fce_next, &todo, list) {
F_138 ( & V_152 -> V_40 ) ;
F_24 ( & V_29 -> V_153 ) ;
if ( ! F_135 ( V_152 -> V_3 ) ) {
F_27 ( & V_152 -> V_40 , & V_29 -> V_155 ) ;
} else {
F_136 ( V_152 ) ;
V_152 = NULL ;
}
F_26 ( & V_29 -> V_153 ) ;
if ( V_152 )
F_144 ( F_137 ,
( void * ) V_152 ,
& V_161 ) ;
}
}
static void F_145 ( void )
{
struct V_28 * V_29 = & V_38 ;
struct V_151 * V_152 ;
F_24 ( & V_29 -> V_153 ) ;
while ( ! F_146 ( & V_29 -> V_155 ) ) {
V_152 = F_147 ( V_29 -> V_155 . V_76 ,
struct V_151 , V_40 ) ;
F_138 ( & V_152 -> V_40 ) ;
F_26 ( & V_29 -> V_153 ) ;
F_133 ( V_152 -> V_3 ) ;
F_136 ( V_152 ) ;
F_24 ( & V_29 -> V_153 ) ;
}
F_26 ( & V_29 -> V_153 ) ;
}
static void F_148 ( void )
{
struct V_28 * V_29 = & V_38 ;
int V_162 ;
F_149 ( V_163 ) ;
F_20 ( L_26 , V_36 ) ;
F_150 ( & V_29 -> V_142 ) ;
V_162 = V_11 ;
V_11 = 10 ;
F_52 ( & V_68 ) ;
V_29 -> V_71 = V_72 ;
F_151 ( NULL , F_141 ) ;
F_54 ( & V_68 ) ;
F_152 ( & V_161 ) ;
V_11 = V_162 ;
}
static void F_153 ( void )
{
F_20 ( L_26 , V_36 ) ;
F_145 () ;
}
static void F_154 ( struct V_141 * V_142 )
{
F_153 () ;
}
static void F_155 ( unsigned long V_164 )
{
F_156 ( V_165 , & V_38 . V_142 ,
F_157 ( V_164 ) ) ;
}
static int F_158 ( struct V_166 * V_167 ,
unsigned long V_168 , void * V_169 )
{
switch ( V_168 ) {
case V_170 :
case V_171 :
case V_172 :
F_63 ( true ) ;
F_148 () ;
break;
case V_173 :
case V_174 :
case V_175 :
F_52 ( & V_68 ) ;
V_38 . V_71 = V_176 ;
F_54 ( & V_68 ) ;
F_155 ( 10 * V_177 ) ;
break;
}
return 0 ;
}
static int F_159 ( void )
{
V_38 . V_71 = V_176 ;
return 0 ;
}
static int F_55 ( const char * V_3 )
{
return 0 ;
}
static void T_6 F_160 ( void )
{
F_161 ( & V_38 . V_39 ) ;
F_19 ( & V_38 . V_41 ) ;
V_38 . V_71 = V_176 ;
#ifdef F_162
F_161 ( & V_38 . V_153 ) ;
F_19 ( & V_38 . V_155 ) ;
F_163 ( & V_38 . V_142 ,
F_154 ) ;
V_38 . V_178 . V_179 = F_158 ;
F_164 ( & V_38 . V_178 ) ;
F_165 ( & V_180 ) ;
#endif
}
static int F_166 ( struct V_166 * V_181 ,
unsigned long V_182 , void * V_183 )
{
F_63 ( false ) ;
return V_184 ;
}
static int T_6 F_167 ( void )
{
F_160 () ;
F_168 ( & V_185 ) ;
#ifdef F_18
return F_169 ( & V_124 ) ;
#else
return 0 ;
#endif
}
static void T_7 F_170 ( void )
{
#ifdef F_162
F_171 ( & V_180 ) ;
F_172 ( & V_38 . V_178 ) ;
#endif
F_173 ( & V_185 ) ;
#ifdef F_18
F_174 ( & V_124 ) ;
#endif
}
