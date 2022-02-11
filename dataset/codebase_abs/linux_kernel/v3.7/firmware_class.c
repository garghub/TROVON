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
V_17 -> V_22 = V_23 ;
F_8 ( L_1 , V_24 , V_14 , V_17 ) ;
return V_17 ;
}
static struct V_13 * F_9 ( const char * V_14 )
{
struct V_13 * V_25 ;
struct V_15 * V_16 = & V_26 ;
F_10 (tmp, &fwc->head, list)
if ( ! strcmp ( V_25 -> V_20 , V_14 ) )
return V_25 ;
return NULL ;
}
static int F_11 ( const char * V_14 ,
struct V_15 * V_16 ,
struct V_13 * * V_17 )
{
struct V_13 * V_25 ;
F_12 ( & V_16 -> V_27 ) ;
V_25 = F_9 ( V_14 ) ;
if ( V_25 ) {
F_13 ( & V_25 -> V_19 ) ;
F_14 ( & V_16 -> V_27 ) ;
* V_17 = V_25 ;
return 1 ;
}
V_25 = F_4 ( V_14 , V_16 ) ;
if ( V_25 )
F_15 ( & V_25 -> V_28 , & V_16 -> V_29 ) ;
F_14 ( & V_16 -> V_27 ) ;
* V_17 = V_25 ;
return V_25 ? 0 : - V_30 ;
}
static struct V_13 * F_16 ( const char * V_14 )
{
struct V_13 * V_25 ;
struct V_15 * V_16 = & V_26 ;
F_12 ( & V_16 -> V_27 ) ;
V_25 = F_9 ( V_14 ) ;
F_14 ( & V_16 -> V_27 ) ;
return V_25 ;
}
static void F_17 ( struct V_31 * V_19 )
{
struct V_13 * V_17 = F_18 ( V_19 ) ;
struct V_15 * V_16 = V_17 -> V_16 ;
int V_32 ;
F_8 ( L_2 ,
V_24 , V_17 -> V_20 , V_17 , V_17 -> V_9 ,
( unsigned int ) V_17 -> V_8 ) ;
F_12 ( & V_16 -> V_27 ) ;
F_19 ( & V_17 -> V_28 ) ;
F_14 ( & V_16 -> V_27 ) ;
if ( V_17 -> V_22 == V_33 ) {
F_20 ( V_17 -> V_9 ) ;
for ( V_32 = 0 ; V_32 < V_17 -> V_34 ; V_32 ++ )
F_21 ( V_17 -> V_35 [ V_32 ] ) ;
F_22 ( V_17 -> V_35 ) ;
} else
F_23 ( V_17 -> V_9 ) ;
F_22 ( V_17 ) ;
}
static void F_24 ( struct V_13 * V_17 )
{
F_25 ( & V_17 -> V_19 , F_17 ) ;
}
static T_1 long F_26 ( struct V_36 * V_36 )
{
struct V_37 V_38 ;
if ( F_27 ( V_36 -> V_39 . V_40 , V_36 -> V_39 . V_41 , & V_38 ) )
return - 1 ;
if ( ! F_28 ( V_38 . V_42 ) )
return - 1 ;
if ( V_38 . V_8 != ( long ) V_38 . V_8 )
return - 1 ;
return V_38 . V_8 ;
}
static bool F_29 ( struct V_36 * V_36 , struct V_13 * V_43 )
{
long V_8 ;
char * V_17 ;
V_8 = F_26 ( V_36 ) ;
if ( V_8 < 0 )
return false ;
V_17 = F_30 ( V_8 ) ;
if ( ! V_17 )
return false ;
if ( F_31 ( V_36 , 0 , V_17 , V_8 ) != V_8 ) {
F_23 ( V_17 ) ;
return false ;
}
V_43 -> V_9 = V_17 ;
V_43 -> V_8 = V_8 ;
return true ;
}
static bool F_32 ( struct V_13 * V_17 )
{
int V_32 ;
bool V_44 = false ;
char * V_45 = F_33 () ;
for ( V_32 = 0 ; V_32 < F_34 ( V_46 ) ; V_32 ++ ) {
struct V_36 * V_36 ;
snprintf ( V_45 , V_47 , L_3 , V_46 [ V_32 ] , V_17 -> V_20 ) ;
V_36 = F_35 ( V_45 , V_48 , 0 ) ;
if ( F_36 ( V_36 ) )
continue;
V_44 = F_29 ( V_36 , V_17 ) ;
F_37 ( V_36 ) ;
if ( V_44 )
break;
}
F_38 ( V_45 ) ;
return V_44 ;
}
static struct V_49 * F_39 ( struct V_50 * V_51 )
{
return F_40 ( V_51 , struct V_49 , V_51 ) ;
}
static void F_41 ( struct V_49 * V_52 )
{
struct V_13 * V_17 = V_52 -> V_17 ;
F_42 ( V_53 , & V_17 -> V_54 ) ;
F_43 ( & V_17 -> V_21 ) ;
}
static T_2 F_44 ( struct V_55 * V_55 ,
struct V_56 * V_57 ,
char * V_17 )
{
return sprintf ( V_17 , L_4 , V_10 ) ;
}
static T_2 F_45 ( struct V_55 * V_55 ,
struct V_56 * V_57 ,
const char * V_17 , T_3 V_58 )
{
V_10 = F_46 ( V_17 , NULL , 10 ) ;
if ( V_10 < 0 )
V_10 = 0 ;
return V_58 ;
}
static void F_47 ( struct V_50 * V_51 )
{
struct V_49 * V_52 = F_39 ( V_51 ) ;
F_22 ( V_52 ) ;
F_48 ( V_59 ) ;
}
static int F_49 ( struct V_50 * V_51 , struct V_60 * V_61 )
{
struct V_49 * V_52 = F_39 ( V_51 ) ;
if ( F_50 ( V_61 , L_5 , V_52 -> V_17 -> V_20 ) )
return - V_30 ;
if ( F_50 ( V_61 , L_6 , V_10 ) )
return - V_30 ;
if ( F_50 ( V_61 , L_7 , V_52 -> V_62 ) )
return - V_30 ;
return 0 ;
}
static T_2 F_51 ( struct V_50 * V_51 ,
struct V_63 * V_57 , char * V_17 )
{
struct V_49 * V_52 = F_39 ( V_51 ) ;
int V_64 = F_52 ( V_65 , & V_52 -> V_17 -> V_54 ) ;
return sprintf ( V_17 , L_4 , V_64 ) ;
}
static void F_53 ( const struct V_1 * V_2 )
{
if ( ! V_2 -> V_66 ) {
F_23 ( V_2 -> V_9 ) ;
return;
}
F_24 ( V_2 -> V_66 ) ;
}
static int F_54 ( struct V_13 * V_17 )
{
if ( V_17 -> V_22 != V_33 )
return 0 ;
if ( V_17 -> V_9 )
F_20 ( V_17 -> V_9 ) ;
V_17 -> V_9 = F_55 ( V_17 -> V_35 , V_17 -> V_34 , 0 , V_67 ) ;
if ( ! V_17 -> V_9 )
return - V_30 ;
return 0 ;
}
static T_2 F_56 ( struct V_50 * V_51 ,
struct V_63 * V_57 ,
const char * V_17 , T_3 V_58 )
{
struct V_49 * V_52 = F_39 ( V_51 ) ;
struct V_13 * V_43 = V_52 -> V_17 ;
int V_64 = F_46 ( V_17 , NULL , 10 ) ;
int V_32 ;
F_57 ( & V_68 ) ;
if ( ! V_43 )
goto V_69;
switch ( V_64 ) {
case 1 :
if ( ! F_52 ( V_70 , & V_43 -> V_54 ) ) {
for ( V_32 = 0 ; V_32 < V_43 -> V_34 ; V_32 ++ )
F_21 ( V_43 -> V_35 [ V_32 ] ) ;
F_22 ( V_43 -> V_35 ) ;
V_43 -> V_35 = NULL ;
V_43 -> V_71 = 0 ;
V_43 -> V_34 = 0 ;
F_42 ( V_65 , & V_43 -> V_54 ) ;
}
break;
case 0 :
if ( F_52 ( V_65 , & V_43 -> V_54 ) ) {
F_42 ( V_70 , & V_43 -> V_54 ) ;
F_58 ( V_65 , & V_43 -> V_54 ) ;
F_54 ( V_43 ) ;
F_43 ( & V_43 -> V_21 ) ;
break;
}
default:
F_59 ( V_51 , L_8 , V_24 , V_64 ) ;
case - 1 :
F_41 ( V_52 ) ;
break;
}
V_69:
F_60 ( & V_68 ) ;
return V_58 ;
}
static T_2 F_61 ( struct V_36 * V_72 , struct V_73 * V_74 ,
struct V_75 * V_76 ,
char * V_77 , T_4 V_78 , T_3 V_58 )
{
struct V_50 * V_51 = F_62 ( V_74 ) ;
struct V_49 * V_52 = F_39 ( V_51 ) ;
struct V_13 * V_17 ;
T_2 V_79 ;
F_57 ( & V_68 ) ;
V_17 = V_52 -> V_17 ;
if ( ! V_17 || F_52 ( V_70 , & V_17 -> V_54 ) ) {
V_79 = - V_80 ;
goto V_69;
}
if ( V_78 > V_17 -> V_8 ) {
V_79 = 0 ;
goto V_69;
}
if ( V_58 > V_17 -> V_8 - V_78 )
V_58 = V_17 -> V_8 - V_78 ;
V_79 = V_58 ;
while ( V_58 ) {
void * V_81 ;
int V_82 = V_78 >> V_83 ;
int V_84 = V_78 & ( V_85 - 1 ) ;
int V_86 = F_63 ( T_3 , V_85 - V_84 , V_58 ) ;
V_81 = F_64 ( V_17 -> V_35 [ V_82 ] ) ;
memcpy ( V_77 , V_81 + V_84 , V_86 ) ;
F_65 ( V_17 -> V_35 [ V_82 ] ) ;
V_77 += V_86 ;
V_78 += V_86 ;
V_58 -= V_86 ;
}
V_69:
F_60 ( & V_68 ) ;
return V_79 ;
}
static int F_66 ( struct V_49 * V_52 , int V_87 )
{
struct V_13 * V_17 = V_52 -> V_17 ;
int V_88 = F_67 ( V_87 , V_85 ) >> V_83 ;
if ( V_17 -> V_71 < V_88 ) {
int V_89 = F_68 ( V_88 ,
V_17 -> V_71 * 2 ) ;
struct V_90 * * V_91 ;
V_91 = F_69 ( V_89 * sizeof( void * ) ,
V_92 ) ;
if ( ! V_91 ) {
F_41 ( V_52 ) ;
return - V_30 ;
}
memcpy ( V_91 , V_17 -> V_35 ,
V_17 -> V_71 * sizeof( void * ) ) ;
memset ( & V_91 [ V_17 -> V_71 ] , 0 , sizeof( void * ) *
( V_89 - V_17 -> V_71 ) ) ;
F_22 ( V_17 -> V_35 ) ;
V_17 -> V_35 = V_91 ;
V_17 -> V_71 = V_89 ;
}
while ( V_17 -> V_34 < V_88 ) {
V_17 -> V_35 [ V_17 -> V_34 ] =
F_70 ( V_92 | V_93 ) ;
if ( ! V_17 -> V_35 [ V_17 -> V_34 ] ) {
F_41 ( V_52 ) ;
return - V_30 ;
}
V_17 -> V_34 ++ ;
}
return 0 ;
}
static T_2 F_71 ( struct V_36 * V_72 , struct V_73 * V_74 ,
struct V_75 * V_76 ,
char * V_77 , T_4 V_78 , T_3 V_58 )
{
struct V_50 * V_51 = F_62 ( V_74 ) ;
struct V_49 * V_52 = F_39 ( V_51 ) ;
struct V_13 * V_17 ;
T_2 V_94 ;
if ( ! F_72 ( V_95 ) )
return - V_96 ;
F_57 ( & V_68 ) ;
V_17 = V_52 -> V_17 ;
if ( ! V_17 || F_52 ( V_70 , & V_17 -> V_54 ) ) {
V_94 = - V_80 ;
goto V_69;
}
V_94 = F_66 ( V_52 , V_78 + V_58 ) ;
if ( V_94 )
goto V_69;
V_94 = V_58 ;
while ( V_58 ) {
void * V_81 ;
int V_82 = V_78 >> V_83 ;
int V_84 = V_78 & ( V_85 - 1 ) ;
int V_86 = F_63 ( T_3 , V_85 - V_84 , V_58 ) ;
V_81 = F_64 ( V_17 -> V_35 [ V_82 ] ) ;
memcpy ( V_81 + V_84 , V_77 , V_86 ) ;
F_65 ( V_17 -> V_35 [ V_82 ] ) ;
V_77 += V_86 ;
V_78 += V_86 ;
V_58 -= V_86 ;
}
V_17 -> V_8 = F_73 ( T_3 , V_78 , V_17 -> V_8 ) ;
V_69:
F_60 ( & V_68 ) ;
return V_94 ;
}
static void F_74 ( T_5 V_9 )
{
struct V_49 * V_52 = (struct V_49 * ) V_9 ;
F_41 ( V_52 ) ;
}
static struct V_49 *
F_75 ( struct V_1 * V_1 , const char * V_14 ,
struct V_50 * V_50 , bool V_97 , bool V_62 )
{
struct V_49 * V_52 ;
struct V_50 * V_98 ;
V_52 = F_5 ( sizeof( * V_52 ) , V_92 ) ;
if ( ! V_52 ) {
F_59 ( V_50 , L_9 , V_24 ) ;
V_52 = F_76 ( - V_30 ) ;
goto exit;
}
V_52 -> V_62 = V_62 ;
V_52 -> V_2 = V_1 ;
F_77 ( & V_52 -> V_99 ,
F_74 , ( T_5 ) V_52 ) ;
V_98 = & V_52 -> V_51 ;
F_78 ( V_98 ) ;
F_79 ( V_98 , L_10 , V_14 ) ;
V_98 -> V_100 = V_50 ;
V_98 -> V_55 = & V_101 ;
exit:
return V_52 ;
}
static void F_80 ( struct V_13 * V_17 , struct V_1 * V_2 )
{
V_2 -> V_66 = V_17 ;
V_2 -> V_35 = V_17 -> V_35 ;
V_2 -> V_8 = V_17 -> V_8 ;
V_2 -> V_9 = V_17 -> V_9 ;
F_8 ( L_2 ,
V_24 , V_17 -> V_20 , V_17 , V_17 -> V_9 ,
( unsigned int ) V_17 -> V_8 ) ;
}
static void F_81 ( struct V_50 * V_51 , void * V_102 )
{
struct V_103 * V_104 = V_102 ;
if ( V_104 -> V_105 == ( unsigned long ) & V_26 )
F_8 ( L_11 ,
V_24 , V_104 -> V_3 , V_102 ) ;
}
static int F_82 ( struct V_50 * V_51 , void * V_102 ,
void * V_106 )
{
struct V_103 * V_104 = V_102 ;
return ( V_104 -> V_105 == ( unsigned long ) & V_26 ) &&
! strcmp ( V_104 -> V_3 , V_106 ) ;
}
static struct V_103 * F_83 ( struct V_50 * V_51 ,
const char * V_3 )
{
struct V_103 * V_104 ;
V_104 = F_84 ( V_51 , F_81 ,
F_82 , ( void * ) V_3 ) ;
return V_104 ;
}
static int F_85 ( struct V_50 * V_51 , const char * V_3 )
{
struct V_103 * V_104 ;
V_104 = F_83 ( V_51 , V_3 ) ;
if ( V_104 )
return 1 ;
V_104 = F_86 ( F_81 , sizeof( struct V_103 ) +
strlen ( V_3 ) + 1 , V_92 ) ;
if ( ! V_104 )
return - V_30 ;
V_104 -> V_105 = ( unsigned long ) & V_26 ;
strcpy ( V_104 -> V_3 , V_3 ) ;
F_87 ( V_51 , V_104 ) ;
return 0 ;
}
static int F_85 ( struct V_50 * V_51 , const char * V_3 )
{
return 0 ;
}
static void F_88 ( const struct V_1 * * V_107 )
{
F_89 ( * V_107 ) ;
* V_107 = NULL ;
}
static struct V_49 *
F_90 ( const struct V_1 * * V_107 , const char * V_3 ,
struct V_50 * V_50 , bool V_97 , bool V_62 )
{
struct V_1 * V_1 ;
struct V_49 * V_52 = NULL ;
struct V_13 * V_17 ;
int V_108 ;
if ( ! V_107 )
return F_76 ( - V_109 ) ;
* V_107 = V_1 = F_5 ( sizeof( * V_1 ) , V_92 ) ;
if ( ! V_1 ) {
F_59 ( V_50 , L_12 ,
V_24 ) ;
return F_76 ( - V_30 ) ;
}
if ( F_1 ( V_1 , V_3 ) ) {
F_91 ( V_50 , L_13 , V_3 ) ;
return NULL ;
}
V_108 = F_11 ( V_3 , & V_26 , & V_17 ) ;
if ( ! V_108 )
V_52 = F_75 ( V_1 , V_3 , V_50 ,
V_97 , V_62 ) ;
if ( F_36 ( V_52 ) || V_108 < 0 ) {
F_22 ( V_1 ) ;
* V_107 = NULL ;
return F_76 ( - V_30 ) ;
} else if ( V_52 ) {
V_52 -> V_17 = V_17 ;
V_1 -> V_66 = V_17 ;
return V_52 ;
}
V_110:
F_57 ( & V_68 ) ;
if ( F_52 ( V_53 , & V_17 -> V_54 ) ) {
V_52 = F_76 ( - V_111 ) ;
V_1 -> V_66 = V_17 ;
F_88 ( V_107 ) ;
goto exit;
} else if ( F_52 ( V_70 , & V_17 -> V_54 ) ) {
V_52 = NULL ;
F_80 ( V_17 , V_1 ) ;
goto exit;
}
F_60 ( & V_68 ) ;
F_92 ( & V_17 -> V_21 ) ;
goto V_110;
exit:
F_60 ( & V_68 ) ;
return V_52 ;
}
static int F_93 ( struct V_49 * V_52 , bool V_97 ,
long V_99 )
{
int V_94 = 0 ;
struct V_50 * V_98 = & V_52 -> V_51 ;
struct V_13 * V_17 = V_52 -> V_17 ;
struct V_15 * V_16 = & V_26 ;
int V_112 = 0 ;
if ( F_32 ( V_17 ) ) {
F_91 ( V_98 -> V_100 , L_14
L_15 , V_17 -> V_20 ) ;
F_42 ( V_70 , & V_17 -> V_54 ) ;
F_43 ( & V_17 -> V_21 ) ;
V_112 = 1 ;
goto V_113;
}
V_17 -> V_22 = V_33 ;
F_94 ( V_98 , true ) ;
F_95 ( V_59 ) ;
V_94 = F_96 ( V_98 ) ;
if ( V_94 ) {
F_59 ( V_98 , L_16 , V_24 ) ;
goto V_114;
}
V_94 = F_97 ( V_98 , & V_115 ) ;
if ( V_94 ) {
F_59 ( V_98 , L_17 , V_24 ) ;
goto V_116;
}
V_94 = F_98 ( V_98 , & V_117 ) ;
if ( V_94 ) {
F_59 ( V_98 , L_18 , V_24 ) ;
goto V_118;
}
if ( V_97 ) {
F_94 ( V_98 , false ) ;
F_91 ( V_98 , L_19 , V_17 -> V_20 ) ;
if ( V_99 != V_12 )
F_99 ( & V_52 -> V_99 ,
F_100 ( V_119 + V_99 ) ) ;
F_101 ( & V_52 -> V_51 . V_74 , V_120 ) ;
}
F_92 ( & V_17 -> V_21 ) ;
F_102 ( & V_52 -> V_99 ) ;
V_113:
F_57 ( & V_68 ) ;
if ( ! V_17 -> V_8 || F_52 ( V_53 , & V_17 -> V_54 ) )
V_94 = - V_111 ;
if ( ! V_94 && V_98 -> V_100 )
F_85 ( V_98 -> V_100 , V_17 -> V_20 ) ;
if ( ! V_94 && V_16 -> V_121 == V_122 ) {
if ( F_103 ( V_17 -> V_20 ) )
F_13 ( & V_17 -> V_19 ) ;
}
F_80 ( V_17 , V_52 -> V_2 ) ;
V_52 -> V_17 = NULL ;
F_60 ( & V_68 ) ;
if ( V_112 )
goto V_114;
F_104 ( V_98 , & V_117 ) ;
V_118:
F_105 ( V_98 , & V_115 ) ;
V_116:
F_106 ( V_98 ) ;
V_114:
F_107 ( V_98 ) ;
return V_94 ;
}
int
F_108 ( const struct V_1 * * V_107 , const char * V_3 ,
struct V_50 * V_50 )
{
struct V_49 * V_52 ;
int V_108 ;
V_52 = F_90 ( V_107 , V_3 , V_50 , true ,
false ) ;
if ( F_109 ( V_52 ) )
return F_110 ( V_52 ) ;
V_108 = F_111 () ;
if ( F_112 ( V_108 ) ) {
F_59 ( V_50 , L_20 , V_3 ) ;
} else {
V_108 = F_93 ( V_52 , true ,
F_3 () ) ;
F_113 () ;
}
if ( V_108 )
F_88 ( V_107 ) ;
return V_108 ;
}
void F_89 ( const struct V_1 * V_2 )
{
if ( V_2 ) {
if ( ! F_2 ( V_2 ) )
F_53 ( V_2 ) ;
F_22 ( V_2 ) ;
}
}
static void F_114 ( struct V_123 * V_124 )
{
struct V_125 * V_126 ;
const struct V_1 * V_2 ;
struct V_49 * V_52 ;
long V_99 ;
int V_108 ;
V_126 = F_40 ( V_124 , struct V_125 , V_124 ) ;
V_52 = F_90 ( & V_2 , V_126 -> V_3 , V_126 -> V_50 ,
V_126 -> V_97 , true ) ;
if ( F_109 ( V_52 ) ) {
V_108 = F_110 ( V_52 ) ;
goto V_69;
}
V_99 = F_115 ( F_3 () ) ;
if ( V_99 ) {
V_108 = F_93 ( V_52 , V_126 -> V_97 , V_99 ) ;
F_113 () ;
} else {
F_91 ( V_126 -> V_50 , L_21 ,
V_126 -> V_3 ) ;
V_108 = - V_127 ;
}
if ( V_108 )
F_88 ( & V_2 ) ;
V_69:
V_126 -> V_128 ( V_2 , V_126 -> V_129 ) ;
F_107 ( V_126 -> V_50 ) ;
F_48 ( V_126 -> V_130 ) ;
F_22 ( V_126 ) ;
}
int
F_116 (
struct V_130 * V_130 , bool V_97 ,
const char * V_3 , struct V_50 * V_50 , T_6 V_131 , void * V_129 ,
void (* V_128)( const struct V_1 * V_2 , void * V_129 ) )
{
struct V_125 * V_126 ;
V_126 = F_5 ( sizeof ( struct V_125 ) , V_131 ) ;
if ( ! V_126 )
return - V_30 ;
V_126 -> V_130 = V_130 ;
V_126 -> V_3 = V_3 ;
V_126 -> V_50 = V_50 ;
V_126 -> V_129 = V_129 ;
V_126 -> V_128 = V_128 ;
V_126 -> V_97 = V_97 ;
if ( ! F_117 ( V_130 ) ) {
F_22 ( V_126 ) ;
return - V_132 ;
}
F_118 ( V_126 -> V_50 ) ;
F_119 ( & V_126 -> V_124 , F_114 ) ;
F_120 ( & V_126 -> V_124 ) ;
return 0 ;
}
int F_121 ( const char * V_14 )
{
int V_108 ;
const struct V_1 * V_2 ;
F_8 ( L_22 , V_24 , V_14 ) ;
V_108 = F_108 ( & V_2 , V_14 , NULL ) ;
if ( ! V_108 )
F_22 ( V_2 ) ;
F_8 ( L_23 , V_24 , V_14 , V_108 ) ;
return V_108 ;
}
int F_122 ( const char * V_14 )
{
struct V_13 * V_17 ;
struct V_1 V_2 ;
F_8 ( L_22 , V_24 , V_14 ) ;
if ( F_1 ( & V_2 , V_14 ) )
return 0 ;
V_17 = F_16 ( V_14 ) ;
if ( V_17 ) {
F_24 ( V_17 ) ;
return 0 ;
}
return - V_109 ;
}
static struct V_133 * F_123 ( const char * V_3 )
{
struct V_133 * V_134 ;
V_134 = F_5 ( sizeof( * V_134 ) + strlen ( V_3 ) + 1 , V_18 ) ;
if ( ! V_134 )
goto exit;
strcpy ( V_134 -> V_3 , V_3 ) ;
exit:
return V_134 ;
}
static int F_124 ( const char * V_3 )
{
struct V_15 * V_16 = & V_26 ;
struct V_133 * V_134 ;
F_10 (fce, &fwc->fw_names, list) {
if ( ! strcmp ( V_134 -> V_3 , V_3 ) )
return 1 ;
}
return 0 ;
}
static int F_103 ( const char * V_3 )
{
struct V_15 * V_16 = & V_26 ;
struct V_133 * V_134 ;
int V_108 = 0 ;
F_12 ( & V_16 -> V_135 ) ;
if ( F_124 ( V_3 ) )
goto V_136;
V_134 = F_123 ( V_3 ) ;
if ( V_134 ) {
V_108 = 1 ;
F_15 ( & V_134 -> V_28 , & V_16 -> V_137 ) ;
F_8 ( L_24 , V_24 , V_3 ) ;
}
V_136:
F_14 ( & V_16 -> V_135 ) ;
return V_108 ;
}
static void F_125 ( struct V_133 * V_134 )
{
F_22 ( V_134 ) ;
}
static void F_126 ( void * V_138 ,
T_7 V_139 )
{
struct V_133 * V_134 = V_138 ;
struct V_15 * V_16 = & V_26 ;
int V_108 ;
V_108 = F_121 ( V_134 -> V_3 ) ;
if ( V_108 ) {
F_12 ( & V_16 -> V_135 ) ;
F_19 ( & V_134 -> V_28 ) ;
F_14 ( & V_16 -> V_135 ) ;
F_125 ( V_134 ) ;
}
}
static void F_127 ( struct V_50 * V_51 , void * V_102 ,
void * V_9 )
{
struct V_103 * V_104 = V_102 ;
const char * V_14 = V_104 -> V_3 ;
struct V_140 * V_29 = V_9 ;
struct V_133 * V_134 ;
V_134 = F_123 ( V_14 ) ;
if ( V_134 )
F_15 ( & V_134 -> V_28 , V_29 ) ;
}
static int F_128 ( struct V_50 * V_51 , void * V_102 ,
void * V_106 )
{
struct V_103 * V_104 = V_102 ;
return ( V_104 -> V_105 == ( unsigned long ) V_106 ) ;
}
static void F_129 ( struct V_50 * V_51 , void * V_9 )
{
F_130 ( V_141 ) ;
struct V_133 * V_134 ;
struct V_133 * V_142 ;
struct V_15 * V_16 = & V_26 ;
F_131 ( V_51 , F_81 ,
F_128 , & V_26 ,
F_127 , & V_141 ) ;
F_132 (fce, fce_next, &todo, list) {
F_19 ( & V_134 -> V_28 ) ;
F_12 ( & V_16 -> V_135 ) ;
if ( ! F_124 ( V_134 -> V_3 ) ) {
F_15 ( & V_134 -> V_28 , & V_16 -> V_137 ) ;
} else {
F_125 ( V_134 ) ;
V_134 = NULL ;
}
F_14 ( & V_16 -> V_135 ) ;
if ( V_134 )
F_133 ( F_126 ,
( void * ) V_134 ,
& V_143 ) ;
}
}
static void F_134 ( void )
{
struct V_15 * V_16 = & V_26 ;
struct V_133 * V_134 ;
F_12 ( & V_16 -> V_135 ) ;
while ( ! F_135 ( & V_16 -> V_137 ) ) {
V_134 = F_136 ( V_16 -> V_137 . V_144 ,
struct V_133 , V_28 ) ;
F_19 ( & V_134 -> V_28 ) ;
F_14 ( & V_16 -> V_135 ) ;
F_122 ( V_134 -> V_3 ) ;
F_125 ( V_134 ) ;
F_12 ( & V_16 -> V_135 ) ;
}
F_14 ( & V_16 -> V_135 ) ;
}
static void F_137 ( void )
{
struct V_15 * V_16 = & V_26 ;
int V_145 ;
F_138 ( V_146 ) ;
F_8 ( L_25 , V_24 ) ;
F_139 ( & V_16 -> V_124 ) ;
V_145 = V_10 ;
V_10 = 10 ;
F_57 ( & V_68 ) ;
V_16 -> V_121 = V_122 ;
F_140 ( NULL , F_129 ) ;
F_60 ( & V_68 ) ;
F_141 ( & V_143 ) ;
V_10 = V_145 ;
}
static void F_142 ( void )
{
F_8 ( L_25 , V_24 ) ;
F_134 () ;
}
static void F_143 ( struct V_123 * V_124 )
{
F_142 () ;
}
static void F_144 ( unsigned long V_147 )
{
F_145 ( & V_26 . V_124 ,
F_146 ( V_147 ) ) ;
}
static int F_147 ( struct V_148 * V_149 ,
unsigned long V_42 , void * V_150 )
{
switch ( V_42 ) {
case V_151 :
case V_152 :
F_137 () ;
break;
case V_153 :
case V_154 :
case V_155 :
F_57 ( & V_68 ) ;
V_26 . V_121 = V_156 ;
F_60 ( & V_68 ) ;
F_144 ( 10 * V_157 ) ;
break;
}
return 0 ;
}
static int F_148 ( void )
{
V_26 . V_121 = V_156 ;
return 0 ;
}
static int F_103 ( const char * V_3 )
{
return 0 ;
}
static void T_8 F_149 ( void )
{
F_150 ( & V_26 . V_27 ) ;
F_151 ( & V_26 . V_29 ) ;
V_26 . V_121 = V_156 ;
#ifdef F_152
F_150 ( & V_26 . V_135 ) ;
F_151 ( & V_26 . V_137 ) ;
F_153 ( & V_26 . V_124 ,
F_143 ) ;
V_26 . V_158 . V_159 = F_147 ;
F_154 ( & V_26 . V_158 ) ;
F_155 ( & V_160 ) ;
#endif
}
static int T_8 F_156 ( void )
{
F_149 () ;
return F_157 ( & V_101 ) ;
}
static void T_9 F_158 ( void )
{
#ifdef F_152
F_159 ( & V_160 ) ;
F_160 ( & V_26 . V_158 ) ;
#endif
F_161 ( & V_101 ) ;
}
