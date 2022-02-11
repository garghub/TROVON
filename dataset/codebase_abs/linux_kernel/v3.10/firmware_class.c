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
F_8 ( L_1 , V_22 , V_14 , V_17 ) ;
return V_17 ;
}
static struct V_13 * F_9 ( const char * V_14 )
{
struct V_13 * V_23 ;
struct V_15 * V_16 = & V_24 ;
F_10 (tmp, &fwc->head, list)
if ( ! strcmp ( V_23 -> V_20 , V_14 ) )
return V_23 ;
return NULL ;
}
static int F_11 ( const char * V_14 ,
struct V_15 * V_16 ,
struct V_13 * * V_17 )
{
struct V_13 * V_23 ;
F_12 ( & V_16 -> V_25 ) ;
V_23 = F_9 ( V_14 ) ;
if ( V_23 ) {
F_13 ( & V_23 -> V_19 ) ;
F_14 ( & V_16 -> V_25 ) ;
* V_17 = V_23 ;
return 1 ;
}
V_23 = F_4 ( V_14 , V_16 ) ;
if ( V_23 )
F_15 ( & V_23 -> V_26 , & V_16 -> V_27 ) ;
F_14 ( & V_16 -> V_25 ) ;
* V_17 = V_23 ;
return V_23 ? 0 : - V_28 ;
}
static struct V_13 * F_16 ( const char * V_14 )
{
struct V_13 * V_23 ;
struct V_15 * V_16 = & V_24 ;
F_12 ( & V_16 -> V_25 ) ;
V_23 = F_9 ( V_14 ) ;
F_14 ( & V_16 -> V_25 ) ;
return V_23 ;
}
static void F_17 ( struct V_29 * V_19 )
{
struct V_13 * V_17 = F_18 ( V_19 ) ;
struct V_15 * V_16 = V_17 -> V_16 ;
F_8 ( L_2 ,
V_22 , V_17 -> V_20 , V_17 , V_17 -> V_9 ,
( unsigned int ) V_17 -> V_8 ) ;
F_19 ( & V_17 -> V_26 ) ;
F_14 ( & V_16 -> V_25 ) ;
#ifdef F_20
if ( V_17 -> V_30 ) {
int V_31 ;
F_21 ( V_17 -> V_9 ) ;
for ( V_31 = 0 ; V_31 < V_17 -> V_32 ; V_31 ++ )
F_22 ( V_17 -> V_33 [ V_31 ] ) ;
F_23 ( V_17 -> V_33 ) ;
} else
#endif
F_24 ( V_17 -> V_9 ) ;
F_23 ( V_17 ) ;
}
static void F_25 ( struct V_13 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_16 ;
F_12 ( & V_16 -> V_25 ) ;
if ( ! F_26 ( & V_17 -> V_19 , F_17 ) )
F_14 ( & V_16 -> V_25 ) ;
}
static T_1 long F_27 ( struct V_34 * V_34 )
{
struct V_35 V_36 ;
if ( F_28 ( & V_34 -> V_37 , & V_36 ) )
return - 1 ;
if ( ! F_29 ( V_36 . V_38 ) )
return - 1 ;
if ( V_36 . V_8 != ( long ) V_36 . V_8 )
return - 1 ;
return V_36 . V_8 ;
}
static bool F_30 ( struct V_34 * V_34 , struct V_13 * V_39 )
{
long V_8 ;
char * V_17 ;
V_8 = F_27 ( V_34 ) ;
if ( V_8 <= 0 )
return false ;
V_17 = F_31 ( V_8 ) ;
if ( ! V_17 )
return false ;
if ( F_32 ( V_34 , 0 , V_17 , V_8 ) != V_8 ) {
F_24 ( V_17 ) ;
return false ;
}
V_39 -> V_9 = V_17 ;
V_39 -> V_8 = V_8 ;
return true ;
}
static bool F_33 ( struct V_40 * V_40 ,
struct V_13 * V_17 )
{
int V_31 ;
bool V_41 = false ;
char * V_42 = F_34 () ;
for ( V_31 = 0 ; V_31 < F_35 ( V_43 ) ; V_31 ++ ) {
struct V_34 * V_34 ;
if ( ! V_43 [ V_31 ] [ 0 ] )
continue;
snprintf ( V_42 , V_44 , L_3 , V_43 [ V_31 ] , V_17 -> V_20 ) ;
V_34 = F_36 ( V_42 , V_45 , 0 ) ;
if ( F_37 ( V_34 ) )
continue;
V_41 = F_30 ( V_34 , V_17 ) ;
F_38 ( V_34 ) ;
if ( V_41 )
break;
}
F_39 ( V_42 ) ;
if ( V_41 ) {
F_40 ( V_40 , L_4 ,
V_17 -> V_20 ) ;
F_41 ( & V_46 ) ;
F_42 ( V_47 , & V_17 -> V_48 ) ;
F_43 ( & V_17 -> V_21 ) ;
F_44 ( & V_46 ) ;
}
return V_41 ;
}
static void F_45 ( const struct V_1 * V_2 )
{
if ( ! V_2 -> V_49 ) {
F_24 ( V_2 -> V_9 ) ;
return;
}
F_25 ( V_2 -> V_49 ) ;
}
static void F_46 ( struct V_13 * V_17 , struct V_1 * V_2 )
{
V_2 -> V_49 = V_17 ;
#ifdef F_20
V_2 -> V_33 = V_17 -> V_33 ;
#endif
V_2 -> V_8 = V_17 -> V_8 ;
V_2 -> V_9 = V_17 -> V_9 ;
F_8 ( L_2 ,
V_22 , V_17 -> V_20 , V_17 , V_17 -> V_9 ,
( unsigned int ) V_17 -> V_8 ) ;
}
static void F_47 ( struct V_40 * V_50 , void * V_51 )
{
struct V_52 * V_53 = V_51 ;
if ( V_53 -> V_54 == ( unsigned long ) & V_24 )
F_8 ( L_5 ,
V_22 , V_53 -> V_3 , V_51 ) ;
}
static int F_48 ( struct V_40 * V_50 , void * V_51 ,
void * V_55 )
{
struct V_52 * V_53 = V_51 ;
return ( V_53 -> V_54 == ( unsigned long ) & V_24 ) &&
! strcmp ( V_53 -> V_3 , V_55 ) ;
}
static struct V_52 * F_49 ( struct V_40 * V_50 ,
const char * V_3 )
{
struct V_52 * V_53 ;
V_53 = F_50 ( V_50 , F_47 ,
F_48 , ( void * ) V_3 ) ;
return V_53 ;
}
static int F_51 ( struct V_40 * V_50 , const char * V_3 )
{
struct V_52 * V_53 ;
V_53 = F_49 ( V_50 , V_3 ) ;
if ( V_53 )
return 1 ;
V_53 = F_52 ( F_47 , sizeof( struct V_52 ) +
strlen ( V_3 ) + 1 , V_56 ) ;
if ( ! V_53 )
return - V_28 ;
V_53 -> V_54 = ( unsigned long ) & V_24 ;
strcpy ( V_53 -> V_3 , V_3 ) ;
F_53 ( V_50 , V_53 ) ;
return 0 ;
}
static int F_51 ( struct V_40 * V_50 , const char * V_3 )
{
return 0 ;
}
static struct V_57 * F_54 ( struct V_40 * V_50 )
{
return F_55 ( V_50 , struct V_57 , V_50 ) ;
}
static void F_56 ( struct V_57 * V_58 )
{
struct V_13 * V_17 = V_58 -> V_17 ;
if ( F_57 ( V_47 , & V_17 -> V_48 ) )
return;
F_42 ( V_59 , & V_17 -> V_48 ) ;
F_43 ( & V_17 -> V_21 ) ;
V_58 -> V_17 = NULL ;
}
static T_2 F_58 ( struct V_60 * V_60 ,
struct V_61 * V_62 ,
char * V_17 )
{
return sprintf ( V_17 , L_6 , V_10 ) ;
}
static T_2 F_59 ( struct V_60 * V_60 ,
struct V_61 * V_62 ,
const char * V_17 , T_3 V_63 )
{
V_10 = F_60 ( V_17 , NULL , 10 ) ;
if ( V_10 < 0 )
V_10 = 0 ;
return V_63 ;
}
static void F_61 ( struct V_40 * V_50 )
{
struct V_57 * V_58 = F_54 ( V_50 ) ;
F_23 ( V_58 ) ;
F_62 ( V_64 ) ;
}
static int F_63 ( struct V_40 * V_50 , struct V_65 * V_66 )
{
struct V_57 * V_58 = F_54 ( V_50 ) ;
if ( F_64 ( V_66 , L_7 , V_58 -> V_17 -> V_20 ) )
return - V_28 ;
if ( F_64 ( V_66 , L_8 , V_10 ) )
return - V_28 ;
if ( F_64 ( V_66 , L_9 , V_58 -> V_67 ) )
return - V_28 ;
return 0 ;
}
static T_2 F_65 ( struct V_40 * V_50 ,
struct V_68 * V_62 , char * V_17 )
{
struct V_57 * V_58 = F_54 ( V_50 ) ;
int V_69 = 0 ;
F_41 ( & V_46 ) ;
if ( V_58 -> V_17 )
V_69 = F_57 ( V_70 , & V_58 -> V_17 -> V_48 ) ;
F_44 ( & V_46 ) ;
return sprintf ( V_17 , L_6 , V_69 ) ;
}
static int F_66 ( struct V_13 * V_17 )
{
if ( ! V_17 -> V_30 )
return 0 ;
if ( V_17 -> V_9 )
F_21 ( V_17 -> V_9 ) ;
V_17 -> V_9 = F_67 ( V_17 -> V_33 , V_17 -> V_32 , 0 , V_71 ) ;
if ( ! V_17 -> V_9 )
return - V_28 ;
return 0 ;
}
static T_2 F_68 ( struct V_40 * V_50 ,
struct V_68 * V_62 ,
const char * V_17 , T_3 V_63 )
{
struct V_57 * V_58 = F_54 ( V_50 ) ;
struct V_13 * V_39 ;
int V_69 = F_60 ( V_17 , NULL , 10 ) ;
int V_31 ;
F_41 ( & V_46 ) ;
V_39 = V_58 -> V_17 ;
if ( ! V_39 )
goto V_72;
switch ( V_69 ) {
case 1 :
if ( ! F_57 ( V_47 , & V_39 -> V_48 ) ) {
for ( V_31 = 0 ; V_31 < V_39 -> V_32 ; V_31 ++ )
F_22 ( V_39 -> V_33 [ V_31 ] ) ;
F_23 ( V_39 -> V_33 ) ;
V_39 -> V_33 = NULL ;
V_39 -> V_73 = 0 ;
V_39 -> V_32 = 0 ;
F_42 ( V_70 , & V_39 -> V_48 ) ;
}
break;
case 0 :
if ( F_57 ( V_70 , & V_39 -> V_48 ) ) {
F_42 ( V_47 , & V_39 -> V_48 ) ;
F_69 ( V_70 , & V_39 -> V_48 ) ;
F_66 ( V_39 ) ;
F_43 ( & V_39 -> V_21 ) ;
break;
}
default:
F_70 ( V_50 , L_10 , V_22 , V_69 ) ;
case - 1 :
F_56 ( V_58 ) ;
break;
}
V_72:
F_44 ( & V_46 ) ;
return V_63 ;
}
static T_2 F_71 ( struct V_34 * V_74 , struct V_75 * V_76 ,
struct V_77 * V_78 ,
char * V_79 , T_4 V_80 , T_3 V_63 )
{
struct V_40 * V_50 = F_72 ( V_76 ) ;
struct V_57 * V_58 = F_54 ( V_50 ) ;
struct V_13 * V_17 ;
T_2 V_81 ;
F_41 ( & V_46 ) ;
V_17 = V_58 -> V_17 ;
if ( ! V_17 || F_57 ( V_47 , & V_17 -> V_48 ) ) {
V_81 = - V_82 ;
goto V_72;
}
if ( V_80 > V_17 -> V_8 ) {
V_81 = 0 ;
goto V_72;
}
if ( V_63 > V_17 -> V_8 - V_80 )
V_63 = V_17 -> V_8 - V_80 ;
V_81 = V_63 ;
while ( V_63 ) {
void * V_83 ;
int V_84 = V_80 >> V_85 ;
int V_86 = V_80 & ( V_87 - 1 ) ;
int V_88 = F_73 ( T_3 , V_87 - V_86 , V_63 ) ;
V_83 = F_74 ( V_17 -> V_33 [ V_84 ] ) ;
memcpy ( V_79 , V_83 + V_86 , V_88 ) ;
F_75 ( V_17 -> V_33 [ V_84 ] ) ;
V_79 += V_88 ;
V_80 += V_88 ;
V_63 -= V_88 ;
}
V_72:
F_44 ( & V_46 ) ;
return V_81 ;
}
static int F_76 ( struct V_57 * V_58 , int V_89 )
{
struct V_13 * V_17 = V_58 -> V_17 ;
int V_90 = F_77 ( V_89 , V_87 ) >> V_85 ;
if ( V_17 -> V_73 < V_90 ) {
int V_91 = F_78 ( V_90 ,
V_17 -> V_73 * 2 ) ;
struct V_92 * * V_93 ;
V_93 = F_79 ( V_91 * sizeof( void * ) ,
V_56 ) ;
if ( ! V_93 ) {
F_56 ( V_58 ) ;
return - V_28 ;
}
memcpy ( V_93 , V_17 -> V_33 ,
V_17 -> V_73 * sizeof( void * ) ) ;
memset ( & V_93 [ V_17 -> V_73 ] , 0 , sizeof( void * ) *
( V_91 - V_17 -> V_73 ) ) ;
F_23 ( V_17 -> V_33 ) ;
V_17 -> V_33 = V_93 ;
V_17 -> V_73 = V_91 ;
}
while ( V_17 -> V_32 < V_90 ) {
V_17 -> V_33 [ V_17 -> V_32 ] =
F_80 ( V_56 | V_94 ) ;
if ( ! V_17 -> V_33 [ V_17 -> V_32 ] ) {
F_56 ( V_58 ) ;
return - V_28 ;
}
V_17 -> V_32 ++ ;
}
return 0 ;
}
static T_2 F_81 ( struct V_34 * V_74 , struct V_75 * V_76 ,
struct V_77 * V_78 ,
char * V_79 , T_4 V_80 , T_3 V_63 )
{
struct V_40 * V_50 = F_72 ( V_76 ) ;
struct V_57 * V_58 = F_54 ( V_50 ) ;
struct V_13 * V_17 ;
T_2 V_95 ;
if ( ! F_82 ( V_96 ) )
return - V_97 ;
F_41 ( & V_46 ) ;
V_17 = V_58 -> V_17 ;
if ( ! V_17 || F_57 ( V_47 , & V_17 -> V_48 ) ) {
V_95 = - V_82 ;
goto V_72;
}
V_95 = F_76 ( V_58 , V_80 + V_63 ) ;
if ( V_95 )
goto V_72;
V_95 = V_63 ;
while ( V_63 ) {
void * V_83 ;
int V_84 = V_80 >> V_85 ;
int V_86 = V_80 & ( V_87 - 1 ) ;
int V_88 = F_73 ( T_3 , V_87 - V_86 , V_63 ) ;
V_83 = F_74 ( V_17 -> V_33 [ V_84 ] ) ;
memcpy ( V_83 + V_86 , V_79 , V_88 ) ;
F_75 ( V_17 -> V_33 [ V_84 ] ) ;
V_79 += V_88 ;
V_80 += V_88 ;
V_63 -= V_88 ;
}
V_17 -> V_8 = F_83 ( T_3 , V_80 , V_17 -> V_8 ) ;
V_72:
F_44 ( & V_46 ) ;
return V_95 ;
}
static void F_84 ( struct V_98 * V_99 )
{
struct V_57 * V_58 = F_55 ( V_99 ,
struct V_57 , V_100 . V_99 ) ;
F_41 ( & V_46 ) ;
F_56 ( V_58 ) ;
F_44 ( & V_46 ) ;
}
static struct V_57 *
F_85 ( struct V_1 * V_1 , const char * V_14 ,
struct V_40 * V_40 , bool V_101 , bool V_67 )
{
struct V_57 * V_58 ;
struct V_40 * V_102 ;
V_58 = F_5 ( sizeof( * V_58 ) , V_56 ) ;
if ( ! V_58 ) {
F_70 ( V_40 , L_11 , V_22 ) ;
V_58 = F_86 ( - V_28 ) ;
goto exit;
}
V_58 -> V_67 = V_67 ;
V_58 -> V_2 = V_1 ;
F_87 ( & V_58 -> V_100 ,
F_84 ) ;
V_102 = & V_58 -> V_50 ;
F_88 ( V_102 ) ;
F_89 ( V_102 , L_12 , V_14 ) ;
V_102 -> V_103 = V_40 ;
V_102 -> V_60 = & V_104 ;
exit:
return V_58 ;
}
static int F_90 ( struct V_57 * V_58 , bool V_101 ,
long V_105 )
{
int V_95 = 0 ;
struct V_40 * V_102 = & V_58 -> V_50 ;
struct V_13 * V_17 = V_58 -> V_17 ;
V_17 -> V_30 = true ;
F_91 ( V_102 , true ) ;
F_92 ( V_64 ) ;
V_95 = F_93 ( V_102 ) ;
if ( V_95 ) {
F_70 ( V_102 , L_13 , V_22 ) ;
goto V_106;
}
V_95 = F_94 ( V_102 , & V_107 ) ;
if ( V_95 ) {
F_70 ( V_102 , L_14 , V_22 ) ;
goto V_108;
}
V_95 = F_95 ( V_102 , & V_109 ) ;
if ( V_95 ) {
F_70 ( V_102 , L_15 , V_22 ) ;
goto V_110;
}
if ( V_101 ) {
F_91 ( V_102 , false ) ;
F_40 ( V_102 , L_16 , V_17 -> V_20 ) ;
if ( V_105 != V_12 )
F_96 ( & V_58 -> V_100 , V_105 ) ;
F_97 ( & V_58 -> V_50 . V_76 , V_111 ) ;
}
F_98 ( & V_17 -> V_21 ) ;
F_99 ( & V_58 -> V_100 ) ;
F_100 ( V_102 , & V_109 ) ;
V_110:
F_101 ( V_102 , & V_107 ) ;
V_108:
F_102 ( V_102 ) ;
V_106:
F_103 ( V_102 ) ;
return V_95 ;
}
static int F_104 ( struct V_1 * V_1 ,
const char * V_3 , struct V_40 * V_40 ,
bool V_101 , bool V_67 , long V_105 )
{
struct V_57 * V_58 ;
V_58 = F_85 ( V_1 , V_3 , V_40 , V_101 , V_67 ) ;
if ( F_37 ( V_58 ) )
return F_105 ( V_58 ) ;
V_58 -> V_17 = V_1 -> V_49 ;
return F_90 ( V_58 , V_101 , V_105 ) ;
}
static inline int
F_104 ( struct V_1 * V_1 , const char * V_3 ,
struct V_40 * V_40 , bool V_101 , bool V_67 ,
long V_105 )
{
return - V_112 ;
}
static int F_106 ( struct V_13 * V_17 )
{
int V_113 = 0 ;
F_41 ( & V_46 ) ;
while ( ! F_57 ( V_47 , & V_17 -> V_48 ) ) {
if ( F_107 ( V_17 ) ) {
V_113 = - V_112 ;
break;
}
F_44 ( & V_46 ) ;
F_98 ( & V_17 -> V_21 ) ;
F_41 ( & V_46 ) ;
}
F_44 ( & V_46 ) ;
return V_113 ;
}
static int
F_108 ( struct V_1 * * V_114 , const char * V_3 ,
struct V_40 * V_40 )
{
struct V_1 * V_1 ;
struct V_13 * V_17 ;
int V_113 ;
* V_114 = V_1 = F_5 ( sizeof( * V_1 ) , V_56 ) ;
if ( ! V_1 ) {
F_70 ( V_40 , L_17 ,
V_22 ) ;
return - V_28 ;
}
if ( F_1 ( V_1 , V_3 ) ) {
F_40 ( V_40 , L_18 , V_3 ) ;
return 0 ;
}
V_113 = F_11 ( V_3 , & V_24 , & V_17 ) ;
V_1 -> V_49 = V_17 ;
if ( V_113 > 0 ) {
V_113 = F_106 ( V_17 ) ;
if ( ! V_113 ) {
F_46 ( V_17 , V_1 ) ;
return 0 ;
}
}
if ( V_113 < 0 )
return V_113 ;
return 1 ;
}
static int F_109 ( struct V_1 * V_2 , struct V_40 * V_40 )
{
struct V_13 * V_17 = V_2 -> V_49 ;
F_41 ( & V_46 ) ;
if ( ! V_17 -> V_8 || F_107 ( V_17 ) ) {
F_44 ( & V_46 ) ;
return - V_112 ;
}
if ( V_40 )
F_51 ( V_40 , V_17 -> V_20 ) ;
if ( V_17 -> V_16 -> V_115 == V_116 ) {
if ( F_110 ( V_17 -> V_20 ) )
F_13 ( & V_17 -> V_19 ) ;
}
F_46 ( V_17 , V_2 ) ;
F_44 ( & V_46 ) ;
return 0 ;
}
static int
F_111 ( const struct V_1 * * V_114 , const char * V_3 ,
struct V_40 * V_40 , bool V_101 , bool V_67 )
{
struct V_1 * V_2 ;
long V_105 ;
int V_113 ;
if ( ! V_114 )
return - V_117 ;
V_113 = F_108 ( & V_2 , V_3 , V_40 ) ;
if ( V_113 <= 0 )
goto V_72;
V_113 = 0 ;
V_105 = F_3 () ;
if ( V_67 ) {
V_105 = F_112 ( V_105 ) ;
if ( ! V_105 ) {
F_40 ( V_40 , L_19 ,
V_3 ) ;
V_113 = - V_118 ;
goto V_72;
}
} else {
V_113 = F_113 () ;
if ( F_114 ( V_113 ) ) {
F_70 ( V_40 , L_20 ,
V_3 ) ;
goto V_72;
}
}
if ( ! F_33 ( V_40 , V_2 -> V_49 ) )
V_113 = F_104 ( V_2 , V_3 , V_40 ,
V_101 , V_67 , V_105 ) ;
if ( ! V_113 )
V_113 = F_109 ( V_2 , V_40 ) ;
F_115 () ;
V_72:
if ( V_113 < 0 ) {
F_116 ( V_2 ) ;
V_2 = NULL ;
}
* V_114 = V_2 ;
return V_113 ;
}
int
F_117 ( const struct V_1 * * V_114 , const char * V_3 ,
struct V_40 * V_40 )
{
return F_111 ( V_114 , V_3 , V_40 , true , false ) ;
}
void F_116 ( const struct V_1 * V_2 )
{
if ( V_2 ) {
if ( ! F_2 ( V_2 ) )
F_45 ( V_2 ) ;
F_23 ( V_2 ) ;
}
}
static void F_118 ( struct V_98 * V_99 )
{
struct V_119 * V_120 ;
const struct V_1 * V_2 ;
V_120 = F_55 ( V_99 , struct V_119 , V_99 ) ;
F_111 ( & V_2 , V_120 -> V_3 , V_120 -> V_40 ,
V_120 -> V_101 , true ) ;
V_120 -> V_121 ( V_2 , V_120 -> V_122 ) ;
F_103 ( V_120 -> V_40 ) ;
F_62 ( V_120 -> V_123 ) ;
F_23 ( V_120 ) ;
}
int
F_119 (
struct V_123 * V_123 , bool V_101 ,
const char * V_3 , struct V_40 * V_40 , T_5 V_124 , void * V_122 ,
void (* V_121)( const struct V_1 * V_2 , void * V_122 ) )
{
struct V_119 * V_120 ;
V_120 = F_5 ( sizeof ( struct V_119 ) , V_124 ) ;
if ( ! V_120 )
return - V_28 ;
V_120 -> V_123 = V_123 ;
V_120 -> V_3 = V_3 ;
V_120 -> V_40 = V_40 ;
V_120 -> V_122 = V_122 ;
V_120 -> V_121 = V_121 ;
V_120 -> V_101 = V_101 ;
if ( ! F_120 ( V_123 ) ) {
F_23 ( V_120 ) ;
return - V_125 ;
}
F_121 ( V_120 -> V_40 ) ;
F_122 ( & V_120 -> V_99 , F_118 ) ;
F_123 ( & V_120 -> V_99 ) ;
return 0 ;
}
int F_124 ( const char * V_14 )
{
int V_113 ;
const struct V_1 * V_2 ;
F_8 ( L_21 , V_22 , V_14 ) ;
V_113 = F_117 ( & V_2 , V_14 , NULL ) ;
if ( ! V_113 )
F_23 ( V_2 ) ;
F_8 ( L_22 , V_22 , V_14 , V_113 ) ;
return V_113 ;
}
int F_125 ( const char * V_14 )
{
struct V_13 * V_17 ;
struct V_1 V_2 ;
F_8 ( L_21 , V_22 , V_14 ) ;
if ( F_1 ( & V_2 , V_14 ) )
return 0 ;
V_17 = F_16 ( V_14 ) ;
if ( V_17 ) {
F_25 ( V_17 ) ;
return 0 ;
}
return - V_117 ;
}
static struct V_126 * F_126 ( const char * V_3 )
{
struct V_126 * V_127 ;
V_127 = F_5 ( sizeof( * V_127 ) + strlen ( V_3 ) + 1 , V_18 ) ;
if ( ! V_127 )
goto exit;
strcpy ( V_127 -> V_3 , V_3 ) ;
exit:
return V_127 ;
}
static int F_127 ( const char * V_3 )
{
struct V_15 * V_16 = & V_24 ;
struct V_126 * V_127 ;
F_10 (fce, &fwc->fw_names, list) {
if ( ! strcmp ( V_127 -> V_3 , V_3 ) )
return 1 ;
}
return 0 ;
}
static int F_110 ( const char * V_3 )
{
struct V_15 * V_16 = & V_24 ;
struct V_126 * V_127 ;
int V_113 = 0 ;
F_12 ( & V_16 -> V_128 ) ;
if ( F_127 ( V_3 ) )
goto V_129;
V_127 = F_126 ( V_3 ) ;
if ( V_127 ) {
V_113 = 1 ;
F_15 ( & V_127 -> V_26 , & V_16 -> V_130 ) ;
F_8 ( L_23 , V_22 , V_3 ) ;
}
V_129:
F_14 ( & V_16 -> V_128 ) ;
return V_113 ;
}
static void F_128 ( struct V_126 * V_127 )
{
F_23 ( V_127 ) ;
}
static void F_129 ( void * V_131 ,
T_6 V_132 )
{
struct V_126 * V_127 = V_131 ;
struct V_15 * V_16 = & V_24 ;
int V_113 ;
V_113 = F_124 ( V_127 -> V_3 ) ;
if ( V_113 ) {
F_12 ( & V_16 -> V_128 ) ;
F_19 ( & V_127 -> V_26 ) ;
F_14 ( & V_16 -> V_128 ) ;
F_128 ( V_127 ) ;
}
}
static void F_130 ( struct V_40 * V_50 , void * V_51 ,
void * V_9 )
{
struct V_52 * V_53 = V_51 ;
const char * V_14 = V_53 -> V_3 ;
struct V_133 * V_27 = V_9 ;
struct V_126 * V_127 ;
V_127 = F_126 ( V_14 ) ;
if ( V_127 )
F_15 ( & V_127 -> V_26 , V_27 ) ;
}
static int F_131 ( struct V_40 * V_50 , void * V_51 ,
void * V_55 )
{
struct V_52 * V_53 = V_51 ;
return ( V_53 -> V_54 == ( unsigned long ) V_55 ) ;
}
static void F_132 ( struct V_40 * V_50 , void * V_9 )
{
F_133 ( V_134 ) ;
struct V_126 * V_127 ;
struct V_126 * V_135 ;
struct V_15 * V_16 = & V_24 ;
F_134 ( V_50 , F_47 ,
F_131 , & V_24 ,
F_130 , & V_134 ) ;
F_135 (fce, fce_next, &todo, list) {
F_19 ( & V_127 -> V_26 ) ;
F_12 ( & V_16 -> V_128 ) ;
if ( ! F_127 ( V_127 -> V_3 ) ) {
F_15 ( & V_127 -> V_26 , & V_16 -> V_130 ) ;
} else {
F_128 ( V_127 ) ;
V_127 = NULL ;
}
F_14 ( & V_16 -> V_128 ) ;
if ( V_127 )
F_136 ( F_129 ,
( void * ) V_127 ,
& V_136 ) ;
}
}
static void F_137 ( void )
{
struct V_15 * V_16 = & V_24 ;
struct V_126 * V_127 ;
F_12 ( & V_16 -> V_128 ) ;
while ( ! F_138 ( & V_16 -> V_130 ) ) {
V_127 = F_139 ( V_16 -> V_130 . V_137 ,
struct V_126 , V_26 ) ;
F_19 ( & V_127 -> V_26 ) ;
F_14 ( & V_16 -> V_128 ) ;
F_125 ( V_127 -> V_3 ) ;
F_128 ( V_127 ) ;
F_12 ( & V_16 -> V_128 ) ;
}
F_14 ( & V_16 -> V_128 ) ;
}
static void F_140 ( void )
{
struct V_15 * V_16 = & V_24 ;
int V_138 ;
F_141 ( V_139 ) ;
F_8 ( L_24 , V_22 ) ;
F_99 ( & V_16 -> V_99 ) ;
V_138 = V_10 ;
V_10 = 10 ;
F_41 ( & V_46 ) ;
V_16 -> V_115 = V_116 ;
F_142 ( NULL , F_132 ) ;
F_44 ( & V_46 ) ;
F_143 ( & V_136 ) ;
V_10 = V_138 ;
}
static void F_144 ( void )
{
F_8 ( L_24 , V_22 ) ;
F_137 () ;
}
static void F_145 ( struct V_98 * V_99 )
{
F_144 () ;
}
static void F_146 ( unsigned long V_140 )
{
F_96 ( & V_24 . V_99 ,
F_147 ( V_140 ) ) ;
}
static int F_148 ( struct V_141 * V_142 ,
unsigned long V_38 , void * V_143 )
{
switch ( V_38 ) {
case V_144 :
case V_145 :
F_140 () ;
break;
case V_146 :
case V_147 :
case V_148 :
F_41 ( & V_46 ) ;
V_24 . V_115 = V_149 ;
F_44 ( & V_46 ) ;
F_146 ( 10 * V_150 ) ;
break;
}
return 0 ;
}
static int F_149 ( void )
{
V_24 . V_115 = V_149 ;
return 0 ;
}
static int F_110 ( const char * V_3 )
{
return 0 ;
}
static void T_7 F_150 ( void )
{
F_151 ( & V_24 . V_25 ) ;
F_152 ( & V_24 . V_27 ) ;
V_24 . V_115 = V_149 ;
#ifdef F_153
F_151 ( & V_24 . V_128 ) ;
F_152 ( & V_24 . V_130 ) ;
F_87 ( & V_24 . V_99 ,
F_145 ) ;
V_24 . V_151 . V_152 = F_148 ;
F_154 ( & V_24 . V_151 ) ;
F_155 ( & V_153 ) ;
#endif
}
static int T_7 F_156 ( void )
{
F_150 () ;
#ifdef F_20
return F_157 ( & V_104 ) ;
#else
return 0 ;
#endif
}
static void T_8 F_158 ( void )
{
#ifdef F_153
F_159 ( & V_153 ) ;
F_160 ( & V_24 . V_151 ) ;
#endif
#ifdef F_20
F_161 ( & V_104 ) ;
#endif
}
