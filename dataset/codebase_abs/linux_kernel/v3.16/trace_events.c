static inline int F_1 ( struct V_1 * system )
{
return system -> V_2 & ~ V_3 ;
}
static int F_2 ( struct V_1 * system )
{
return ( system -> V_2 ++ ) & ~ V_3 ;
}
static int F_3 ( struct V_1 * system )
{
return ( -- system -> V_2 ) & ~ V_3 ;
}
static struct V_4 *
F_4 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_7 -> V_8 )
return & V_6 -> V_7 -> V_9 ;
return V_6 -> V_7 -> V_8 ( V_6 ) ;
}
static struct V_10 *
F_5 ( struct V_4 * V_11 , char * V_12 )
{
struct V_10 * V_13 ;
F_6 (field, head, link) {
if ( ! strcmp ( V_13 -> V_12 , V_12 ) )
return V_13 ;
}
return NULL ;
}
struct V_10 *
F_7 ( struct V_5 * V_14 , char * V_12 )
{
struct V_10 * V_13 ;
struct V_4 * V_11 ;
V_13 = F_5 ( & V_15 , V_12 ) ;
if ( V_13 )
return V_13 ;
V_11 = F_4 ( V_14 ) ;
return F_5 ( V_11 , V_12 ) ;
}
static int F_8 ( struct V_4 * V_11 , const char * type ,
const char * V_12 , int V_16 , int V_17 ,
int V_18 , int V_19 )
{
struct V_10 * V_13 ;
V_13 = F_9 ( V_20 , V_21 ) ;
if ( ! V_13 )
return - V_22 ;
V_13 -> V_12 = V_12 ;
V_13 -> type = type ;
if ( V_19 == V_23 )
V_13 -> V_19 = F_10 ( type ) ;
else
V_13 -> V_19 = V_19 ;
V_13 -> V_16 = V_16 ;
V_13 -> V_17 = V_17 ;
V_13 -> V_18 = V_18 ;
F_11 ( & V_13 -> V_24 , V_11 ) ;
return 0 ;
}
int F_12 ( struct V_5 * V_14 , const char * type ,
const char * V_12 , int V_16 , int V_17 , int V_18 ,
int V_19 )
{
struct V_4 * V_11 ;
if ( F_13 ( ! V_14 -> V_7 ) )
return 0 ;
V_11 = F_4 ( V_14 ) ;
return F_8 ( V_11 , type , V_12 , V_16 , V_17 ,
V_18 , V_19 ) ;
}
static int F_14 ( void )
{
int V_25 ;
struct V_26 V_27 ;
F_15 (unsigned short, type) ;
F_15 (unsigned char, flags) ;
F_15 (unsigned char, preempt_count) ;
F_15 ( int , V_28 ) ;
return V_25 ;
}
static void F_16 ( struct V_5 * V_14 )
{
struct V_10 * V_13 , * V_29 ;
struct V_4 * V_11 ;
V_11 = F_4 ( V_14 ) ;
F_17 (field, next, head, link) {
F_18 ( & V_13 -> V_24 ) ;
F_19 ( V_20 , V_13 ) ;
}
}
int F_20 ( struct V_5 * V_14 )
{
int V_30 ;
V_30 = F_21 ( & V_14 -> V_31 ) ;
if ( ! V_30 )
return - V_32 ;
return 0 ;
}
void * F_22 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
unsigned long V_37 )
{
struct V_5 * V_6 = V_36 -> V_6 ;
F_23 ( V_34 -> V_38 ) ;
V_34 -> V_39 = F_24 () ;
V_34 -> V_36 = V_36 ;
V_34 -> V_31 =
F_25 ( & V_34 -> V_40 , V_36 ,
V_6 -> V_31 . type , V_37 ,
V_34 -> V_38 , V_34 -> V_39 ) ;
if ( ! V_34 -> V_31 )
return NULL ;
V_34 -> V_41 = F_26 ( V_34 -> V_31 ) ;
return V_34 -> V_41 ;
}
void F_27 ( struct V_33 * V_34 )
{
F_28 ( V_34 -> V_36 , V_34 -> V_40 ,
V_34 -> V_31 , V_34 -> V_41 ,
V_34 -> V_38 , V_34 -> V_39 ) ;
}
int F_29 ( struct V_5 * V_14 ,
enum V_42 type , void * V_43 )
{
struct V_35 * V_44 = V_43 ;
F_13 ( ! ( V_14 -> V_38 & V_45 ) ) ;
switch ( type ) {
case V_46 :
return F_30 ( V_14 -> V_47 ,
V_14 -> V_7 -> V_48 ,
V_44 ) ;
case V_49 :
F_31 ( V_14 -> V_47 ,
V_14 -> V_7 -> V_48 ,
V_44 ) ;
return 0 ;
#ifdef F_32
case V_50 :
return F_30 ( V_14 -> V_47 ,
V_14 -> V_7 -> V_51 ,
V_14 ) ;
case V_52 :
F_31 ( V_14 -> V_47 ,
V_14 -> V_7 -> V_51 ,
V_14 ) ;
return 0 ;
case V_53 :
case V_54 :
case V_55 :
case V_56 :
return 0 ;
#endif
}
return 0 ;
}
void F_33 ( bool V_57 )
{
struct V_35 * V_44 ;
struct V_58 * V_59 ;
F_34 ( & V_60 ) ;
F_35 (tr, file) {
if ( ! ( V_44 -> V_38 & V_61 ) )
continue;
if ( V_57 ) {
F_36 () ;
F_37 ( V_62 , & V_44 -> V_38 ) ;
} else {
F_38 () ;
F_39 ( V_62 , & V_44 -> V_38 ) ;
}
} F_40 () ;
F_41 ( & V_60 ) ;
}
static int F_42 ( struct V_35 * V_44 ,
int V_57 , int V_63 )
{
struct V_5 * V_14 = V_44 -> V_6 ;
int V_25 = 0 ;
int V_64 ;
switch ( V_57 ) {
case 0 :
if ( V_63 ) {
if ( F_43 ( & V_44 -> V_65 ) > 0 )
break;
V_64 = V_44 -> V_38 & V_66 ;
F_39 ( V_67 , & V_44 -> V_38 ) ;
} else
V_64 = ! ( V_44 -> V_38 & V_68 ) ;
if ( V_64 && ( V_44 -> V_38 & V_61 ) ) {
F_39 ( V_69 , & V_44 -> V_38 ) ;
if ( V_44 -> V_38 & V_70 ) {
F_38 () ;
F_39 ( V_62 , & V_44 -> V_38 ) ;
}
V_14 -> V_7 -> V_71 ( V_14 , V_49 , V_44 ) ;
}
if ( V_44 -> V_38 & V_68 )
F_37 ( V_72 , & V_44 -> V_38 ) ;
else
F_39 ( V_72 , & V_44 -> V_38 ) ;
break;
case 1 :
if ( ! V_63 )
F_39 ( V_72 , & V_44 -> V_38 ) ;
else {
if ( F_44 ( & V_44 -> V_65 ) > 1 )
break;
F_37 ( V_67 , & V_44 -> V_38 ) ;
}
if ( ! ( V_44 -> V_38 & V_61 ) ) {
if ( V_63 )
F_37 ( V_72 , & V_44 -> V_38 ) ;
if ( V_73 & V_74 ) {
F_36 () ;
F_37 ( V_62 , & V_44 -> V_38 ) ;
}
V_25 = V_14 -> V_7 -> V_71 ( V_14 , V_46 , V_44 ) ;
if ( V_25 ) {
F_38 () ;
F_45 ( L_1
L_2 , F_46 ( V_14 ) ) ;
break;
}
F_37 ( V_69 , & V_44 -> V_38 ) ;
V_14 -> V_38 |= V_75 ;
}
break;
}
return V_25 ;
}
int F_47 ( struct V_35 * V_44 ,
int V_57 , int V_63 )
{
return F_42 ( V_44 , V_57 , V_63 ) ;
}
static int F_48 ( struct V_35 * V_44 ,
int V_57 )
{
return F_42 ( V_44 , V_57 , 0 ) ;
}
static void F_49 ( struct V_58 * V_59 )
{
struct V_35 * V_44 ;
F_34 ( & V_60 ) ;
F_6 (file, &tr->events, list) {
F_48 ( V_44 , 0 ) ;
}
F_41 ( & V_60 ) ;
}
static void F_50 ( struct V_1 * system )
{
struct V_76 * V_77 = system -> V_77 ;
F_51 ( F_1 ( system ) == 0 ) ;
if ( F_3 ( system ) )
return;
F_18 ( & system -> V_78 ) ;
if ( V_77 ) {
F_52 ( V_77 -> V_79 ) ;
F_52 ( V_77 ) ;
}
if ( system -> V_2 & V_3 )
F_52 ( system -> V_12 ) ;
F_52 ( system ) ;
}
static void F_53 ( struct V_1 * system )
{
F_51 ( F_1 ( system ) == 0 ) ;
F_2 ( system ) ;
}
static void F_54 ( struct V_80 * V_81 )
{
F_51 ( V_81 -> V_2 == 0 ) ;
V_81 -> V_2 ++ ;
F_53 ( V_81 -> V_82 ) ;
}
static void F_55 ( struct V_80 * V_81 )
{
F_51 ( V_81 -> V_2 == 0 ) ;
F_51 ( F_1 ( V_81 -> V_82 ) == 1 && V_81 -> V_2 != 1 ) ;
F_50 ( V_81 -> V_82 ) ;
if ( ! -- V_81 -> V_2 )
F_52 ( V_81 ) ;
}
static void F_56 ( struct V_80 * V_81 )
{
F_34 ( & V_60 ) ;
F_55 ( V_81 ) ;
F_41 ( & V_60 ) ;
}
static void F_57 ( struct V_80 * V_81 )
{
if ( ! V_81 )
return;
if ( ! -- V_81 -> V_83 ) {
F_58 ( V_81 -> V_41 ) ;
F_18 ( & V_81 -> V_78 ) ;
F_55 ( V_81 ) ;
}
}
static void F_59 ( struct V_35 * V_44 )
{
struct V_84 * V_81 = V_44 -> V_81 ;
struct V_84 * V_85 ;
if ( V_81 ) {
F_60 ( & V_81 -> V_86 ) ;
F_6 (child, &dir->d_subdirs, d_u.d_child) {
if ( V_85 -> V_87 )
V_85 -> V_87 -> V_88 = NULL ;
}
F_61 ( & V_81 -> V_86 ) ;
F_58 ( V_81 ) ;
}
F_18 ( & V_44 -> V_78 ) ;
F_57 ( V_44 -> system ) ;
F_62 ( V_44 -> V_77 ) ;
F_19 ( V_89 , V_44 ) ;
}
static int
F_63 ( struct V_58 * V_59 , const char * V_90 ,
const char * V_91 , const char * V_31 , int V_92 )
{
struct V_35 * V_44 ;
struct V_5 * V_14 ;
const char * V_12 ;
int V_25 = - V_93 ;
F_6 (file, &tr->events, list) {
V_14 = V_44 -> V_6 ;
V_12 = F_46 ( V_14 ) ;
if ( ! V_12 || ! V_14 -> V_7 || ! V_14 -> V_7 -> V_71 )
continue;
if ( V_14 -> V_38 & V_94 )
continue;
if ( V_90 &&
strcmp ( V_90 , V_12 ) != 0 &&
strcmp ( V_90 , V_14 -> V_7 -> system ) != 0 )
continue;
if ( V_91 && strcmp ( V_91 , V_14 -> V_7 -> system ) != 0 )
continue;
if ( V_31 && strcmp ( V_31 , V_12 ) != 0 )
continue;
F_48 ( V_44 , V_92 ) ;
V_25 = 0 ;
}
return V_25 ;
}
static int F_64 ( struct V_58 * V_59 , const char * V_90 ,
const char * V_91 , const char * V_31 , int V_92 )
{
int V_25 ;
F_34 ( & V_60 ) ;
V_25 = F_63 ( V_59 , V_90 , V_91 , V_31 , V_92 ) ;
F_41 ( & V_60 ) ;
return V_25 ;
}
static int F_65 ( struct V_58 * V_59 , char * V_95 , int V_92 )
{
char * V_31 = NULL , * V_91 = NULL , * V_90 ;
V_90 = F_66 ( & V_95 , L_3 ) ;
if ( V_95 ) {
V_91 = V_90 ;
V_31 = V_95 ;
V_90 = NULL ;
if ( ! strlen ( V_91 ) || strcmp ( V_91 , L_4 ) == 0 )
V_91 = NULL ;
if ( ! strlen ( V_31 ) || strcmp ( V_31 , L_4 ) == 0 )
V_31 = NULL ;
}
return F_64 ( V_59 , V_90 , V_91 , V_31 , V_92 ) ;
}
int F_67 ( const char * system , const char * V_31 , int V_92 )
{
struct V_58 * V_59 = F_68 () ;
if ( ! V_59 )
return - V_32 ;
return F_64 ( V_59 , NULL , system , V_31 , V_92 ) ;
}
static T_1
F_69 ( struct V_44 * V_44 , const char T_2 * V_96 ,
T_3 V_97 , T_4 * V_98 )
{
struct V_99 V_100 ;
struct V_101 * V_102 = V_44 -> V_103 ;
struct V_58 * V_59 = V_102 -> V_104 ;
T_1 V_105 , V_25 ;
if ( ! V_97 )
return 0 ;
V_25 = F_70 () ;
if ( V_25 < 0 )
return V_25 ;
if ( F_71 ( & V_100 , V_106 + 1 ) )
return - V_22 ;
V_105 = F_72 ( & V_100 , V_96 , V_97 , V_98 ) ;
if ( V_105 >= 0 && F_73 ( ( & V_100 ) ) ) {
int V_92 = 1 ;
if ( * V_100 . V_40 == '!' )
V_92 = 0 ;
V_100 . V_40 [ V_100 . V_107 ] = 0 ;
V_25 = F_65 ( V_59 , V_100 . V_40 + ! V_92 , V_92 ) ;
if ( V_25 )
goto V_108;
}
V_25 = V_105 ;
V_108:
F_74 ( & V_100 ) ;
return V_25 ;
}
static void *
F_75 ( struct V_101 * V_102 , void * V_109 , T_4 * V_110 )
{
struct V_35 * V_44 = V_109 ;
struct V_5 * V_14 ;
struct V_58 * V_59 = V_102 -> V_104 ;
( * V_110 ) ++ ;
F_76 (file, &tr->events, list) {
V_14 = V_44 -> V_6 ;
if ( V_14 -> V_7 && V_14 -> V_7 -> V_71 )
return V_44 ;
}
return NULL ;
}
static void * F_77 ( struct V_101 * V_102 , T_4 * V_110 )
{
struct V_35 * V_44 ;
struct V_58 * V_59 = V_102 -> V_104 ;
T_4 V_111 ;
F_34 ( & V_60 ) ;
V_44 = F_78 ( & V_59 -> V_112 , struct V_35 , V_78 ) ;
for ( V_111 = 0 ; V_111 <= * V_110 ; ) {
V_44 = F_75 ( V_102 , V_44 , & V_111 ) ;
if ( ! V_44 )
break;
}
return V_44 ;
}
static void *
F_79 ( struct V_101 * V_102 , void * V_109 , T_4 * V_110 )
{
struct V_35 * V_44 = V_109 ;
struct V_58 * V_59 = V_102 -> V_104 ;
( * V_110 ) ++ ;
F_76 (file, &tr->events, list) {
if ( V_44 -> V_38 & V_61 )
return V_44 ;
}
return NULL ;
}
static void * F_80 ( struct V_101 * V_102 , T_4 * V_110 )
{
struct V_35 * V_44 ;
struct V_58 * V_59 = V_102 -> V_104 ;
T_4 V_111 ;
F_34 ( & V_60 ) ;
V_44 = F_78 ( & V_59 -> V_112 , struct V_35 , V_78 ) ;
for ( V_111 = 0 ; V_111 <= * V_110 ; ) {
V_44 = F_79 ( V_102 , V_44 , & V_111 ) ;
if ( ! V_44 )
break;
}
return V_44 ;
}
static int F_81 ( struct V_101 * V_102 , void * V_109 )
{
struct V_35 * V_44 = V_109 ;
struct V_5 * V_14 = V_44 -> V_6 ;
if ( strcmp ( V_14 -> V_7 -> system , V_113 ) != 0 )
F_82 ( V_102 , L_5 , V_14 -> V_7 -> system ) ;
F_82 ( V_102 , L_2 , F_46 ( V_14 ) ) ;
return 0 ;
}
static void F_83 ( struct V_101 * V_102 , void * V_114 )
{
F_41 ( & V_60 ) ;
}
static T_1
F_84 ( struct V_44 * V_115 , char T_2 * V_96 , T_3 V_97 ,
T_4 * V_98 )
{
struct V_35 * V_44 ;
unsigned long V_38 ;
char V_95 [ 4 ] = L_6 ;
F_34 ( & V_60 ) ;
V_44 = F_85 ( V_115 ) ;
if ( F_86 ( V_44 ) )
V_38 = V_44 -> V_38 ;
F_41 ( & V_60 ) ;
if ( ! V_44 )
return - V_32 ;
if ( V_38 & V_61 &&
! ( V_38 & V_66 ) )
strcpy ( V_95 , L_7 ) ;
if ( V_38 & V_66 ||
V_38 & V_68 )
strcat ( V_95 , L_4 ) ;
strcat ( V_95 , L_8 ) ;
return F_87 ( V_96 , V_97 , V_98 , V_95 , strlen ( V_95 ) ) ;
}
static T_1
F_88 ( struct V_44 * V_115 , const char T_2 * V_96 , T_3 V_97 ,
T_4 * V_98 )
{
struct V_35 * V_44 ;
unsigned long V_116 ;
int V_25 ;
V_25 = F_89 ( V_96 , V_97 , 10 , & V_116 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_70 () ;
if ( V_25 < 0 )
return V_25 ;
switch ( V_116 ) {
case 0 :
case 1 :
V_25 = - V_32 ;
F_34 ( & V_60 ) ;
V_44 = F_85 ( V_115 ) ;
if ( F_86 ( V_44 ) )
V_25 = F_48 ( V_44 , V_116 ) ;
F_41 ( & V_60 ) ;
break;
default:
return - V_93 ;
}
* V_98 += V_97 ;
return V_25 ? V_25 : V_97 ;
}
static T_1
F_90 ( struct V_44 * V_115 , char T_2 * V_96 , T_3 V_97 ,
T_4 * V_98 )
{
const char V_117 [ 4 ] = { '?' , '0' , '1' , 'X' } ;
struct V_80 * V_81 = V_115 -> V_103 ;
struct V_1 * system = V_81 -> V_82 ;
struct V_5 * V_14 ;
struct V_35 * V_44 ;
struct V_58 * V_59 = V_81 -> V_59 ;
char V_95 [ 2 ] ;
int V_92 = 0 ;
int V_25 ;
F_34 ( & V_60 ) ;
F_6 (file, &tr->events, list) {
V_14 = V_44 -> V_6 ;
if ( ! F_46 ( V_14 ) || ! V_14 -> V_7 || ! V_14 -> V_7 -> V_71 )
continue;
if ( system && strcmp ( V_14 -> V_7 -> system , system -> V_12 ) != 0 )
continue;
V_92 |= ( 1 << ! ! ( V_44 -> V_38 & V_61 ) ) ;
if ( V_92 == 3 )
break;
}
F_41 ( & V_60 ) ;
V_95 [ 0 ] = V_117 [ V_92 ] ;
V_95 [ 1 ] = '\n' ;
V_25 = F_87 ( V_96 , V_97 , V_98 , V_95 , 2 ) ;
return V_25 ;
}
static T_1
F_91 ( struct V_44 * V_115 , const char T_2 * V_96 , T_3 V_97 ,
T_4 * V_98 )
{
struct V_80 * V_81 = V_115 -> V_103 ;
struct V_1 * system = V_81 -> V_82 ;
const char * V_12 = NULL ;
unsigned long V_116 ;
T_1 V_25 ;
V_25 = F_89 ( V_96 , V_97 , 10 , & V_116 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_70 () ;
if ( V_25 < 0 )
return V_25 ;
if ( V_116 != 0 && V_116 != 1 )
return - V_93 ;
if ( system )
V_12 = system -> V_12 ;
V_25 = F_64 ( V_81 -> V_59 , NULL , V_12 , NULL , V_116 ) ;
if ( V_25 )
goto V_118;
V_25 = V_97 ;
V_118:
* V_98 += V_97 ;
return V_25 ;
}
static void * F_92 ( struct V_101 * V_102 , void * V_109 , T_4 * V_110 )
{
struct V_5 * V_14 = F_85 ( V_102 -> V_104 ) ;
struct V_4 * V_119 = & V_15 ;
struct V_4 * V_11 = F_4 ( V_14 ) ;
struct V_4 * V_120 = V_109 ;
( * V_110 ) ++ ;
switch ( ( unsigned long ) V_109 ) {
case V_121 :
V_120 = V_119 ;
break;
case V_122 :
V_120 = V_11 ;
break;
case V_123 :
return NULL ;
}
V_120 = V_120 -> V_124 ;
if ( V_120 == V_119 )
return ( void * ) V_122 ;
else if ( V_120 == V_11 )
return ( void * ) V_123 ;
else
return V_120 ;
}
static int F_93 ( struct V_101 * V_102 , void * V_109 )
{
struct V_5 * V_14 = F_85 ( V_102 -> V_104 ) ;
struct V_10 * V_13 ;
const char * V_125 ;
switch ( ( unsigned long ) V_109 ) {
case V_121 :
F_82 ( V_102 , L_9 , F_46 ( V_14 ) ) ;
F_82 ( V_102 , L_10 , V_14 -> V_31 . type ) ;
F_82 ( V_102 , L_11 ) ;
return 0 ;
case V_122 :
F_94 ( V_102 , '\n' ) ;
return 0 ;
case V_123 :
F_82 ( V_102 , L_12 ,
V_14 -> V_126 ) ;
return 0 ;
}
V_13 = F_78 ( V_109 , struct V_10 , V_24 ) ;
V_125 = strchr ( V_13 -> type , '[' ) ;
if ( ! strncmp ( V_13 -> type , L_13 , 10 ) )
V_125 = NULL ;
if ( ! V_125 )
F_82 ( V_102 , L_14 ,
V_13 -> type , V_13 -> V_12 , V_13 -> V_16 ,
V_13 -> V_17 , ! ! V_13 -> V_18 ) ;
else
F_82 ( V_102 , L_15 ,
( int ) ( V_125 - V_13 -> type ) ,
V_13 -> type , V_13 -> V_12 ,
V_125 , V_13 -> V_16 ,
V_13 -> V_17 , ! ! V_13 -> V_18 ) ;
return 0 ;
}
static void * F_95 ( struct V_101 * V_102 , T_4 * V_110 )
{
void * V_114 = ( void * ) V_121 ;
T_4 V_111 = 0 ;
F_34 ( & V_60 ) ;
if ( ! F_85 ( V_102 -> V_104 ) )
return F_96 ( - V_32 ) ;
while ( V_111 < * V_110 && V_114 )
V_114 = F_92 ( V_102 , V_114 , & V_111 ) ;
return V_114 ;
}
static void F_97 ( struct V_101 * V_102 , void * V_114 )
{
F_41 ( & V_60 ) ;
}
static int F_98 ( struct V_127 * V_127 , struct V_44 * V_44 )
{
struct V_101 * V_102 ;
int V_25 ;
V_25 = F_99 ( V_44 , & V_128 ) ;
if ( V_25 < 0 )
return V_25 ;
V_102 = V_44 -> V_103 ;
V_102 -> V_104 = V_44 ;
return 0 ;
}
static T_1
F_100 ( struct V_44 * V_115 , char T_2 * V_96 , T_3 V_97 , T_4 * V_98 )
{
int V_30 = ( long ) F_85 ( V_115 ) ;
char V_95 [ 32 ] ;
int V_37 ;
if ( * V_98 )
return 0 ;
if ( F_101 ( ! V_30 ) )
return - V_32 ;
V_37 = sprintf ( V_95 , L_16 , V_30 ) ;
return F_87 ( V_96 , V_97 , V_98 , V_95 , V_37 ) ;
}
static T_1
F_102 ( struct V_44 * V_115 , char T_2 * V_96 , T_3 V_97 ,
T_4 * V_98 )
{
struct V_35 * V_44 ;
struct V_129 * V_130 ;
int V_131 = - V_32 ;
if ( * V_98 )
return 0 ;
V_130 = F_103 ( sizeof( * V_130 ) , V_132 ) ;
if ( ! V_130 )
return - V_22 ;
F_104 ( V_130 ) ;
F_34 ( & V_60 ) ;
V_44 = F_85 ( V_115 ) ;
if ( V_44 )
F_105 ( V_44 , V_130 ) ;
F_41 ( & V_60 ) ;
if ( V_44 )
V_131 = F_87 ( V_96 , V_97 , V_98 , V_130 -> V_40 , V_130 -> V_37 ) ;
F_52 ( V_130 ) ;
return V_131 ;
}
static T_1
F_106 ( struct V_44 * V_115 , const char T_2 * V_96 , T_3 V_97 ,
T_4 * V_98 )
{
struct V_35 * V_44 ;
char * V_95 ;
int V_133 = - V_32 ;
if ( V_97 >= V_134 )
return - V_93 ;
V_95 = ( char * ) F_107 ( V_135 ) ;
if ( ! V_95 )
return - V_22 ;
if ( F_108 ( V_95 , V_96 , V_97 ) ) {
F_109 ( ( unsigned long ) V_95 ) ;
return - V_136 ;
}
V_95 [ V_97 ] = '\0' ;
F_34 ( & V_60 ) ;
V_44 = F_85 ( V_115 ) ;
if ( V_44 )
V_133 = F_110 ( V_44 , V_95 ) ;
F_41 ( & V_60 ) ;
F_109 ( ( unsigned long ) V_95 ) ;
if ( V_133 < 0 )
return V_133 ;
* V_98 += V_97 ;
return V_97 ;
}
static int F_111 ( struct V_127 * V_127 , struct V_44 * V_115 )
{
struct V_1 * system = NULL ;
struct V_80 * V_81 = NULL ;
struct V_58 * V_59 ;
int V_25 ;
if ( F_112 () )
return - V_32 ;
F_34 ( & V_137 ) ;
F_34 ( & V_60 ) ;
F_6 (tr, &ftrace_trace_arrays, list) {
F_6 (dir, &tr->systems, list) {
if ( V_81 == V_127 -> V_88 ) {
if ( V_81 -> V_83 ) {
F_54 ( V_81 ) ;
system = V_81 -> V_82 ;
}
goto V_138;
}
}
}
V_138:
F_41 ( & V_60 ) ;
F_41 ( & V_137 ) ;
if ( ! system )
return - V_32 ;
F_13 ( ! V_81 ) ;
if ( F_113 ( V_59 ) < 0 ) {
F_56 ( V_81 ) ;
return - V_32 ;
}
V_25 = F_114 ( V_127 , V_115 ) ;
if ( V_25 < 0 ) {
F_115 ( V_59 ) ;
F_56 ( V_81 ) ;
}
return V_25 ;
}
static int F_116 ( struct V_127 * V_127 , struct V_44 * V_115 )
{
struct V_80 * V_81 ;
struct V_58 * V_59 = V_127 -> V_88 ;
int V_25 ;
if ( F_112 () )
return - V_32 ;
if ( F_113 ( V_59 ) < 0 )
return - V_32 ;
V_81 = F_117 ( sizeof( * V_81 ) , V_132 ) ;
if ( ! V_81 ) {
F_115 ( V_59 ) ;
return - V_22 ;
}
V_81 -> V_59 = V_59 ;
V_25 = F_114 ( V_127 , V_115 ) ;
if ( V_25 < 0 ) {
F_115 ( V_59 ) ;
F_52 ( V_81 ) ;
return V_25 ;
}
V_115 -> V_103 = V_81 ;
return 0 ;
}
static int F_118 ( struct V_127 * V_127 , struct V_44 * V_44 )
{
struct V_80 * V_81 = V_44 -> V_103 ;
F_115 ( V_81 -> V_59 ) ;
if ( V_81 -> V_82 )
F_56 ( V_81 ) ;
else
F_52 ( V_81 ) ;
return 0 ;
}
static T_1
F_119 ( struct V_44 * V_115 , char T_2 * V_96 , T_3 V_97 ,
T_4 * V_98 )
{
struct V_80 * V_81 = V_115 -> V_103 ;
struct V_1 * system = V_81 -> V_82 ;
struct V_129 * V_130 ;
int V_131 ;
if ( * V_98 )
return 0 ;
V_130 = F_103 ( sizeof( * V_130 ) , V_132 ) ;
if ( ! V_130 )
return - V_22 ;
F_104 ( V_130 ) ;
F_120 ( system , V_130 ) ;
V_131 = F_87 ( V_96 , V_97 , V_98 , V_130 -> V_40 , V_130 -> V_37 ) ;
F_52 ( V_130 ) ;
return V_131 ;
}
static T_1
F_121 ( struct V_44 * V_115 , const char T_2 * V_96 , T_3 V_97 ,
T_4 * V_98 )
{
struct V_80 * V_81 = V_115 -> V_103 ;
char * V_95 ;
int V_133 ;
if ( V_97 >= V_134 )
return - V_93 ;
V_95 = ( char * ) F_107 ( V_135 ) ;
if ( ! V_95 )
return - V_22 ;
if ( F_108 ( V_95 , V_96 , V_97 ) ) {
F_109 ( ( unsigned long ) V_95 ) ;
return - V_136 ;
}
V_95 [ V_97 ] = '\0' ;
V_133 = F_122 ( V_81 , V_95 ) ;
F_109 ( ( unsigned long ) V_95 ) ;
if ( V_133 < 0 )
return V_133 ;
* V_98 += V_97 ;
return V_97 ;
}
static T_1
F_123 ( struct V_44 * V_115 , char T_2 * V_96 , T_3 V_97 , T_4 * V_98 )
{
int (* F_124)( struct V_129 * V_130 ) = V_115 -> V_103 ;
struct V_129 * V_130 ;
int V_131 ;
if ( * V_98 )
return 0 ;
V_130 = F_103 ( sizeof( * V_130 ) , V_132 ) ;
if ( ! V_130 )
return - V_22 ;
F_104 ( V_130 ) ;
F_124 ( V_130 ) ;
V_131 = F_87 ( V_96 , V_97 , V_98 , V_130 -> V_40 , V_130 -> V_37 ) ;
F_52 ( V_130 ) ;
return V_131 ;
}
static int
F_125 ( struct V_127 * V_127 , struct V_44 * V_44 ,
const struct V_139 * V_140 )
{
struct V_101 * V_102 ;
int V_25 ;
V_25 = F_99 ( V_44 , V_140 ) ;
if ( V_25 < 0 )
return V_25 ;
V_102 = V_44 -> V_103 ;
V_102 -> V_104 = V_127 -> V_88 ;
return V_25 ;
}
static int F_126 ( struct V_127 * V_127 , struct V_44 * V_44 )
{
struct V_58 * V_59 = V_127 -> V_88 ;
F_115 ( V_59 ) ;
return F_127 ( V_127 , V_44 ) ;
}
static int
F_128 ( struct V_127 * V_127 , struct V_44 * V_44 )
{
const struct V_139 * V_140 = & V_141 ;
return F_125 ( V_127 , V_44 , V_140 ) ;
}
static int
F_129 ( struct V_127 * V_127 , struct V_44 * V_44 )
{
const struct V_139 * V_140 = & V_142 ;
struct V_58 * V_59 = V_127 -> V_88 ;
int V_25 ;
if ( F_113 ( V_59 ) < 0 )
return - V_32 ;
if ( ( V_44 -> V_143 & V_144 ) &&
( V_44 -> V_145 & V_146 ) )
F_49 ( V_59 ) ;
V_25 = F_125 ( V_127 , V_44 , V_140 ) ;
if ( V_25 < 0 )
F_115 ( V_59 ) ;
return V_25 ;
}
static struct V_1 *
F_130 ( const char * V_12 )
{
struct V_1 * system ;
system = F_103 ( sizeof( * system ) , V_132 ) ;
if ( ! system )
return NULL ;
system -> V_2 = 1 ;
if ( ! F_131 ( ( unsigned long ) V_12 ) ) {
system -> V_2 |= V_3 ;
system -> V_12 = F_132 ( V_12 , V_132 ) ;
if ( ! system -> V_12 )
goto V_147;
} else
system -> V_12 = V_12 ;
system -> V_77 = NULL ;
system -> V_77 = F_117 ( sizeof( struct V_76 ) , V_132 ) ;
if ( ! system -> V_77 )
goto V_147;
F_11 ( & system -> V_78 , & V_148 ) ;
return system ;
V_147:
if ( system -> V_2 & V_3 )
F_52 ( system -> V_12 ) ;
F_52 ( system ) ;
return NULL ;
}
static struct V_84 *
F_133 ( struct V_58 * V_59 , const char * V_12 ,
struct V_35 * V_44 , struct V_84 * V_149 )
{
struct V_80 * V_81 ;
struct V_1 * system ;
struct V_84 * V_41 ;
F_6 (dir, &tr->systems, list) {
system = V_81 -> V_82 ;
if ( strcmp ( system -> V_12 , V_12 ) == 0 ) {
V_81 -> V_83 ++ ;
V_44 -> system = V_81 ;
return V_81 -> V_41 ;
}
}
F_6 (system, &event_subsystems, list) {
if ( strcmp ( system -> V_12 , V_12 ) == 0 )
break;
}
if ( & system -> V_78 == & V_148 )
system = NULL ;
V_81 = F_103 ( sizeof( * V_81 ) , V_132 ) ;
if ( ! V_81 )
goto V_150;
if ( ! system ) {
system = F_130 ( V_12 ) ;
if ( ! system )
goto V_147;
} else
F_53 ( system ) ;
V_81 -> V_41 = F_134 ( V_12 , V_149 ) ;
if ( ! V_81 -> V_41 ) {
F_135 ( L_17 , V_12 ) ;
F_50 ( system ) ;
goto V_147;
}
V_81 -> V_59 = V_59 ;
V_81 -> V_2 = 1 ;
V_81 -> V_83 = 1 ;
V_81 -> V_82 = system ;
V_44 -> system = V_81 ;
V_41 = F_136 ( L_18 , 0644 , V_81 -> V_41 , V_81 ,
& V_151 ) ;
if ( ! V_41 ) {
F_52 ( system -> V_77 ) ;
system -> V_77 = NULL ;
F_135 ( L_19 , V_12 ) ;
}
F_137 ( L_20 , 0644 , V_81 -> V_41 , V_81 ,
& V_152 ) ;
F_11 ( & V_81 -> V_78 , & V_59 -> V_153 ) ;
return V_81 -> V_41 ;
V_147:
F_52 ( V_81 ) ;
V_150:
if ( ! V_81 || ! system )
F_135 ( L_21 ,
V_12 ) ;
return NULL ;
}
static int
F_138 ( struct V_84 * V_149 , struct V_35 * V_44 )
{
struct V_5 * V_14 = V_44 -> V_6 ;
struct V_58 * V_59 = V_44 -> V_59 ;
struct V_4 * V_11 ;
struct V_84 * V_154 ;
const char * V_12 ;
int V_25 ;
if ( strcmp ( V_14 -> V_7 -> system , V_113 ) != 0 ) {
V_154 = F_133 ( V_59 , V_14 -> V_7 -> system , V_44 , V_149 ) ;
if ( ! V_154 )
return - V_22 ;
} else
V_154 = V_149 ;
V_12 = F_46 ( V_14 ) ;
V_44 -> V_81 = F_134 ( V_12 , V_154 ) ;
if ( ! V_44 -> V_81 ) {
F_135 ( L_22 ,
V_12 ) ;
return - 1 ;
}
if ( V_14 -> V_7 -> V_71 && ! ( V_14 -> V_38 & V_94 ) )
F_137 ( L_20 , 0644 , V_44 -> V_81 , V_44 ,
& V_155 ) ;
#ifdef F_32
if ( V_14 -> V_31 . type && V_14 -> V_7 -> V_71 )
F_137 ( L_23 , 0444 , V_44 -> V_81 ,
( void * ) ( long ) V_14 -> V_31 . type ,
& V_156 ) ;
#endif
V_11 = F_4 ( V_14 ) ;
if ( F_139 ( V_11 ) ) {
V_25 = V_14 -> V_7 -> V_157 ( V_14 ) ;
if ( V_25 < 0 ) {
F_135 ( L_24
L_25 , V_12 ) ;
return - 1 ;
}
}
F_137 ( L_18 , 0644 , V_44 -> V_81 , V_44 ,
& V_158 ) ;
F_137 ( L_26 , 0644 , V_44 -> V_81 , V_44 ,
& V_159 ) ;
F_137 ( L_27 , 0444 , V_44 -> V_81 , V_14 ,
& V_160 ) ;
return 0 ;
}
static void F_140 ( struct V_5 * V_14 )
{
struct V_35 * V_44 ;
struct V_58 * V_59 ;
F_141 (tr, file) {
if ( V_44 -> V_6 != V_14 )
continue;
F_59 ( V_44 ) ;
break;
} F_40 () ;
}
static void F_142 ( struct V_5 * V_14 )
{
struct V_58 * V_59 ;
struct V_35 * V_44 ;
F_35 (tr, file) {
if ( V_44 -> V_6 != V_14 )
continue;
F_48 ( V_44 , 0 ) ;
F_143 ( V_44 ) ;
break;
} F_40 () ;
if ( V_14 -> V_31 . V_161 )
F_144 ( & V_14 -> V_31 ) ;
F_140 ( V_14 ) ;
F_18 ( & V_14 -> V_78 ) ;
}
static int F_145 ( struct V_5 * V_14 )
{
int V_25 = 0 ;
const char * V_12 ;
V_12 = F_46 ( V_14 ) ;
if ( F_13 ( ! V_12 ) )
return - V_93 ;
if ( V_14 -> V_7 -> V_162 ) {
V_25 = V_14 -> V_7 -> V_162 ( V_14 ) ;
if ( V_25 < 0 && V_25 != - V_163 )
F_146 ( L_28 ,
V_12 ) ;
}
return V_25 ;
}
static int
F_147 ( struct V_5 * V_14 , struct V_164 * V_165 )
{
int V_25 ;
V_25 = F_145 ( V_14 ) ;
if ( V_25 < 0 )
return V_25 ;
F_11 ( & V_14 -> V_78 , & V_166 ) ;
V_14 -> V_165 = V_165 ;
return 0 ;
}
static struct V_35 *
F_148 ( struct V_5 * V_14 ,
struct V_58 * V_59 )
{
struct V_35 * V_44 ;
V_44 = F_9 ( V_89 , V_21 ) ;
if ( ! V_44 )
return NULL ;
V_44 -> V_6 = V_14 ;
V_44 -> V_59 = V_59 ;
F_149 ( & V_44 -> V_65 , 0 ) ;
F_149 ( & V_44 -> V_167 , 0 ) ;
F_150 ( & V_44 -> V_168 ) ;
F_11 ( & V_44 -> V_78 , & V_59 -> V_112 ) ;
return V_44 ;
}
static int
F_151 ( struct V_5 * V_14 , struct V_58 * V_59 )
{
struct V_35 * V_44 ;
V_44 = F_148 ( V_14 , V_59 ) ;
if ( ! V_44 )
return - V_22 ;
return F_138 ( V_59 -> V_169 , V_44 ) ;
}
static T_5 int
F_152 ( struct V_5 * V_14 ,
struct V_58 * V_59 )
{
struct V_35 * V_44 ;
V_44 = F_148 ( V_14 , V_59 ) ;
if ( ! V_44 )
return - V_22 ;
return 0 ;
}
int F_153 ( struct V_5 * V_14 )
{
int V_25 ;
F_34 ( & V_137 ) ;
F_34 ( & V_60 ) ;
V_25 = F_147 ( V_14 , NULL ) ;
if ( V_25 >= 0 )
F_154 ( V_14 ) ;
F_41 ( & V_60 ) ;
F_41 ( & V_137 ) ;
return V_25 ;
}
static void F_155 ( struct V_5 * V_14 )
{
F_142 ( V_14 ) ;
F_16 ( V_14 ) ;
F_156 ( V_14 ) ;
}
static int F_157 ( struct V_5 * V_14 )
{
struct V_58 * V_59 ;
struct V_35 * V_44 ;
#ifdef F_32
if ( V_14 -> V_170 )
return - V_171 ;
#endif
F_35 (tr, file) {
if ( V_44 -> V_6 != V_14 )
continue;
if ( V_44 -> V_38 & V_61 )
return - V_171 ;
break;
} F_40 () ;
F_155 ( V_14 ) ;
return 0 ;
}
int F_158 ( struct V_5 * V_14 )
{
int V_25 ;
F_34 ( & V_137 ) ;
F_34 ( & V_60 ) ;
F_159 ( & V_172 ) ;
V_25 = F_157 ( V_14 ) ;
F_160 ( & V_172 ) ;
F_41 ( & V_60 ) ;
F_41 ( & V_137 ) ;
return V_25 ;
}
static void F_161 ( struct V_164 * V_165 )
{
struct V_5 * * V_14 , * * V_173 , * * V_174 ;
if ( ! V_165 -> V_175 )
return;
if ( F_162 ( V_165 ) ) {
F_163 ( L_29 ,
V_165 -> V_12 ) ;
return;
}
V_173 = V_165 -> V_176 ;
V_174 = V_165 -> V_176 + V_165 -> V_175 ;
F_164 (call, start, end) {
F_147 ( * V_14 , V_165 ) ;
F_154 ( * V_14 ) ;
}
}
static void F_165 ( struct V_164 * V_165 )
{
struct V_5 * V_14 , * V_114 ;
bool V_177 = false ;
F_159 ( & V_172 ) ;
F_17 (call, p, &ftrace_events, list) {
if ( V_14 -> V_165 == V_165 ) {
if ( V_14 -> V_38 & V_75 )
V_177 = true ;
F_155 ( V_14 ) ;
}
}
F_160 ( & V_172 ) ;
if ( V_177 )
F_166 () ;
}
static int F_167 ( struct V_178 * V_179 ,
unsigned long V_116 , void * V_43 )
{
struct V_164 * V_165 = V_43 ;
F_34 ( & V_137 ) ;
F_34 ( & V_60 ) ;
switch ( V_116 ) {
case V_180 :
F_161 ( V_165 ) ;
break;
case V_181 :
F_165 ( V_165 ) ;
break;
}
F_41 ( & V_60 ) ;
F_41 ( & V_137 ) ;
return 0 ;
}
static void
F_168 ( struct V_58 * V_59 )
{
struct V_5 * V_14 ;
int V_25 ;
F_6 (call, &ftrace_events, list) {
V_25 = F_151 ( V_14 , V_59 ) ;
if ( V_25 < 0 )
F_135 ( L_30 ,
F_46 ( V_14 ) ) ;
}
}
struct V_35 *
F_169 ( struct V_58 * V_59 , const char * system , const char * V_31 )
{
struct V_35 * V_44 ;
struct V_5 * V_14 ;
const char * V_12 ;
F_6 (file, &tr->events, list) {
V_14 = V_44 -> V_6 ;
V_12 = F_46 ( V_14 ) ;
if ( ! V_12 || ! V_14 -> V_7 || ! V_14 -> V_7 -> V_71 )
continue;
if ( V_14 -> V_38 & V_94 )
continue;
if ( strcmp ( V_31 , V_12 ) == 0 &&
strcmp ( system , V_14 -> V_7 -> system ) == 0 )
return V_44 ;
}
return NULL ;
}
static void
F_170 ( unsigned long V_182 , unsigned long V_183 , void * * V_184 )
{
struct V_185 * * V_186 = (struct V_185 * * ) V_184 ;
struct V_185 * V_43 = * V_186 ;
if ( ! V_43 )
return;
if ( V_43 -> V_57 )
F_39 ( V_72 , & V_43 -> V_44 -> V_38 ) ;
else
F_37 ( V_72 , & V_43 -> V_44 -> V_38 ) ;
}
static void
F_171 ( unsigned long V_182 , unsigned long V_183 , void * * V_184 )
{
struct V_185 * * V_186 = (struct V_185 * * ) V_184 ;
struct V_185 * V_43 = * V_186 ;
if ( ! V_43 )
return;
if ( ! V_43 -> V_187 )
return;
if ( V_43 -> V_57 == ! ( V_43 -> V_44 -> V_38 & V_66 ) )
return;
if ( V_43 -> V_187 != - 1 )
( V_43 -> V_187 ) -- ;
F_170 ( V_182 , V_183 , V_184 ) ;
}
static int
F_172 ( struct V_101 * V_102 , unsigned long V_182 ,
struct V_188 * V_189 , void * V_184 )
{
struct V_185 * V_43 = V_184 ;
F_82 ( V_102 , L_31 , ( void * ) V_182 ) ;
F_82 ( V_102 , L_32 ,
V_43 -> V_57 ? V_190 : V_191 ,
V_43 -> V_44 -> V_6 -> V_7 -> system ,
F_46 ( V_43 -> V_44 -> V_6 ) ) ;
if ( V_43 -> V_187 == - 1 )
F_82 ( V_102 , L_33 ) ;
else
F_82 ( V_102 , L_34 , V_43 -> V_187 ) ;
return 0 ;
}
static int
F_173 ( struct V_188 * V_189 , unsigned long V_182 ,
void * * V_184 )
{
struct V_185 * * V_186 = (struct V_185 * * ) V_184 ;
struct V_185 * V_43 = * V_186 ;
V_43 -> V_192 ++ ;
return 0 ;
}
static void
F_174 ( struct V_188 * V_189 , unsigned long V_182 ,
void * * V_184 )
{
struct V_185 * * V_186 = (struct V_185 * * ) V_184 ;
struct V_185 * V_43 = * V_186 ;
if ( F_51 ( V_43 -> V_192 <= 0 ) )
return;
V_43 -> V_192 -- ;
if ( ! V_43 -> V_192 ) {
F_42 ( V_43 -> V_44 , 0 , 1 ) ;
F_175 ( V_43 -> V_44 -> V_6 -> V_165 ) ;
F_52 ( V_43 ) ;
}
* V_186 = NULL ;
}
static int
F_176 ( struct V_193 * V_194 ,
char * V_195 , char * V_196 , char * V_197 , int V_198 )
{
struct V_58 * V_59 = F_68 () ;
struct V_35 * V_44 ;
struct V_188 * V_189 ;
struct V_185 * V_43 ;
const char * system ;
const char * V_31 ;
char * V_199 ;
bool V_57 ;
int V_25 ;
if ( ! V_59 )
return - V_32 ;
if ( ! V_198 || ! V_197 )
return - V_93 ;
system = F_66 ( & V_197 , L_3 ) ;
if ( ! V_197 )
return - V_93 ;
V_31 = F_66 ( & V_197 , L_3 ) ;
F_34 ( & V_60 ) ;
V_25 = - V_93 ;
V_44 = F_169 ( V_59 , system , V_31 ) ;
if ( ! V_44 )
goto V_118;
V_57 = strcmp ( V_196 , V_190 ) == 0 ;
if ( V_57 )
V_189 = V_197 ? & V_200 : & V_201 ;
else
V_189 = V_197 ? & V_202 : & V_203 ;
if ( V_195 [ 0 ] == '!' ) {
F_177 ( V_195 + 1 , V_189 ) ;
V_25 = 0 ;
goto V_118;
}
V_25 = - V_22 ;
V_43 = F_117 ( sizeof( * V_43 ) , V_132 ) ;
if ( ! V_43 )
goto V_118;
V_43 -> V_57 = V_57 ;
V_43 -> V_187 = - 1 ;
V_43 -> V_44 = V_44 ;
if ( ! V_197 )
goto V_204;
V_199 = F_66 ( & V_197 , L_3 ) ;
V_25 = - V_93 ;
if ( ! strlen ( V_199 ) )
goto V_147;
V_25 = F_178 ( V_199 , 0 , & V_43 -> V_187 ) ;
if ( V_25 )
goto V_147;
V_204:
V_25 = F_179 ( V_44 -> V_6 -> V_165 ) ;
if ( ! V_25 ) {
V_25 = - V_171 ;
goto V_147;
}
V_25 = F_42 ( V_44 , 1 , 1 ) ;
if ( V_25 < 0 )
goto V_108;
V_25 = F_180 ( V_195 , V_189 , V_43 ) ;
if ( ! V_25 ) {
V_25 = - V_205 ;
goto V_206;
} else if ( V_25 < 0 )
goto V_206;
V_25 = 0 ;
V_118:
F_41 ( & V_60 ) ;
return V_25 ;
V_206:
F_42 ( V_44 , 0 , 1 ) ;
V_108:
F_175 ( V_44 -> V_6 -> V_165 ) ;
V_147:
F_52 ( V_43 ) ;
goto V_118;
}
static T_5 int F_181 ( void )
{
int V_25 ;
V_25 = F_182 ( & V_207 ) ;
if ( F_13 ( V_25 < 0 ) )
return V_25 ;
V_25 = F_182 ( & V_208 ) ;
if ( F_13 ( V_25 < 0 ) )
F_183 ( & V_207 ) ;
return V_25 ;
}
static inline int F_181 ( void ) { return 0 ; }
static T_5 void
F_184 ( struct V_58 * V_59 )
{
struct V_35 * V_44 ;
int V_25 ;
F_6 (file, &tr->events, list) {
V_25 = F_138 ( V_59 -> V_169 , V_44 ) ;
if ( V_25 < 0 )
F_135 ( L_30 ,
F_46 ( V_44 -> V_6 ) ) ;
}
}
static T_5 void
F_185 ( struct V_58 * V_59 )
{
struct V_5 * V_14 ;
int V_25 ;
F_6 (call, &ftrace_events, list) {
if ( F_51 ( V_14 -> V_165 ) )
continue;
V_25 = F_152 ( V_14 , V_59 ) ;
if ( V_25 < 0 )
F_135 ( L_35 ,
F_46 ( V_14 ) ) ;
}
}
static void
F_186 ( struct V_58 * V_59 )
{
struct V_35 * V_44 , * V_29 ;
F_17 (file, next, &tr->events, list)
F_59 ( V_44 ) ;
}
static void F_154 ( struct V_5 * V_14 )
{
struct V_58 * V_59 ;
F_6 (tr, &ftrace_trace_arrays, list)
F_151 ( V_14 , V_59 ) ;
}
static T_5 int F_187 ( char * V_209 )
{
F_188 ( V_210 , V_209 , V_211 ) ;
V_212 = true ;
V_213 = true ;
return 1 ;
}
static int
F_189 ( struct V_84 * V_149 , struct V_58 * V_59 )
{
struct V_84 * V_154 ;
struct V_84 * V_41 ;
V_41 = F_136 ( L_36 , 0644 , V_149 ,
V_59 , & V_214 ) ;
if ( ! V_41 ) {
F_135 ( L_37 ) ;
return - V_22 ;
}
V_154 = F_134 ( L_38 , V_149 ) ;
if ( ! V_154 ) {
F_135 ( L_39 ) ;
return - V_22 ;
}
F_137 ( L_40 , 0444 , V_154 ,
V_215 ,
& V_216 ) ;
F_137 ( L_41 , 0444 , V_154 ,
V_217 ,
& V_216 ) ;
F_137 ( L_20 , 0644 , V_154 ,
V_59 , & V_218 ) ;
V_59 -> V_169 = V_154 ;
return 0 ;
}
int F_190 ( struct V_84 * V_149 , struct V_58 * V_59 )
{
int V_25 ;
F_34 ( & V_60 ) ;
V_25 = F_189 ( V_149 , V_59 ) ;
if ( V_25 )
goto V_219;
F_159 ( & V_172 ) ;
F_168 ( V_59 ) ;
F_160 ( & V_172 ) ;
V_219:
F_41 ( & V_60 ) ;
return V_25 ;
}
static T_5 int
F_191 ( struct V_84 * V_149 , struct V_58 * V_59 )
{
int V_25 ;
F_34 ( & V_60 ) ;
V_25 = F_189 ( V_149 , V_59 ) ;
if ( V_25 )
goto V_219;
F_159 ( & V_172 ) ;
F_184 ( V_59 ) ;
F_160 ( & V_172 ) ;
V_219:
F_41 ( & V_60 ) ;
return V_25 ;
}
int F_192 ( struct V_58 * V_59 )
{
F_34 ( & V_60 ) ;
F_193 ( V_59 ) ;
F_63 ( V_59 , NULL , NULL , NULL , 0 ) ;
F_194 () ;
F_159 ( & V_172 ) ;
F_186 ( V_59 ) ;
F_58 ( V_59 -> V_169 ) ;
F_160 ( & V_172 ) ;
V_59 -> V_169 = NULL ;
F_41 ( & V_60 ) ;
return 0 ;
}
static T_5 int F_195 ( void )
{
V_20 = F_196 ( V_10 , V_220 ) ;
V_89 = F_196 ( V_35 , V_220 ) ;
return 0 ;
}
static T_5 int F_197 ( void )
{
struct V_58 * V_59 = F_68 () ;
struct V_5 * * V_221 , * V_14 ;
char * V_95 = V_210 ;
char * V_222 ;
int V_25 ;
if ( ! V_59 )
return - V_32 ;
F_164 (iter, __start_ftrace_events, __stop_ftrace_events) {
V_14 = * V_221 ;
V_25 = F_145 ( V_14 ) ;
if ( ! V_25 )
F_11 ( & V_14 -> V_78 , & V_166 ) ;
}
F_185 ( V_59 ) ;
while ( true ) {
V_222 = F_66 ( & V_95 , L_42 ) ;
if ( ! V_222 )
break;
if ( ! * V_222 )
continue;
V_25 = F_65 ( V_59 , V_222 , 1 ) ;
if ( V_25 )
F_146 ( L_43 , V_222 ) ;
}
F_198 () ;
F_181 () ;
F_199 () ;
return 0 ;
}
static T_5 int F_200 ( void )
{
struct V_58 * V_59 ;
struct V_84 * V_223 ;
struct V_84 * V_41 ;
int V_25 ;
V_59 = F_68 () ;
if ( ! V_59 )
return - V_32 ;
V_223 = F_201 () ;
if ( ! V_223 )
return 0 ;
V_41 = F_136 ( L_44 , 0444 , V_223 ,
V_59 , & V_224 ) ;
if ( ! V_41 )
F_135 ( L_45
L_46 ) ;
if ( F_14 () )
F_135 ( L_47 ) ;
V_25 = F_191 ( V_223 , V_59 ) ;
if ( V_25 )
return V_25 ;
#ifdef F_202
V_25 = F_203 ( & V_225 ) ;
if ( V_25 )
F_135 ( L_48 ) ;
#endif
return 0 ;
}
static T_5 void F_204 ( struct V_226 * V_227 )
{
F_60 ( & V_228 ) ;
F_205 ( & V_229 ) ;
F_206 ( 1 ) ;
F_207 ( & V_229 ) ;
F_61 ( & V_228 ) ;
F_34 ( & V_230 ) ;
F_208 ( 1 ) ;
F_41 ( & V_230 ) ;
}
static T_5 int F_209 ( void * V_231 )
{
void * V_232 ;
V_232 = F_103 ( 1234 , V_132 ) ;
if ( ! V_232 )
F_45 ( L_49 ) ;
F_210 ( F_204 ) ;
F_52 ( V_232 ) ;
F_211 ( V_233 ) ;
while ( ! F_212 () )
F_213 () ;
return 0 ;
}
static T_5 void F_214 ( void )
{
struct V_234 * V_235 ;
V_235 = F_215 ( F_209 , NULL , L_50 ) ;
F_208 ( 1 ) ;
F_216 ( V_235 ) ;
}
static T_5 void F_217 ( void )
{
struct V_80 * V_81 ;
struct V_35 * V_44 ;
struct V_5 * V_14 ;
struct V_1 * system ;
struct V_58 * V_59 ;
int V_25 ;
V_59 = F_68 () ;
if ( ! V_59 )
return;
F_45 ( L_51 ) ;
F_6 (file, &tr->events, list) {
V_14 = V_44 -> V_6 ;
if ( ! V_14 -> V_7 || ! V_14 -> V_7 -> V_48 )
continue;
#ifndef F_218
if ( V_14 -> V_7 -> system &&
strcmp ( V_14 -> V_7 -> system , L_52 ) == 0 )
continue;
#endif
F_45 ( L_53 , F_46 ( V_14 ) ) ;
if ( V_44 -> V_38 & V_61 ) {
F_135 ( L_54 ) ;
F_51 ( 1 ) ;
continue;
}
F_48 ( V_44 , 1 ) ;
F_214 () ;
F_48 ( V_44 , 0 ) ;
F_219 ( L_55 ) ;
}
F_45 ( L_56 ) ;
F_6 (dir, &tr->systems, list) {
system = V_81 -> V_82 ;
if ( strcmp ( system -> V_12 , L_57 ) == 0 )
continue;
F_45 ( L_58 , system -> V_12 ) ;
V_25 = F_64 ( V_59 , NULL , system -> V_12 , NULL , 1 ) ;
if ( F_51 ( V_25 ) ) {
F_135 ( L_59 ,
system -> V_12 ) ;
continue;
}
F_214 () ;
V_25 = F_64 ( V_59 , NULL , system -> V_12 , NULL , 0 ) ;
if ( F_51 ( V_25 ) ) {
F_135 ( L_60 ,
system -> V_12 ) ;
continue;
}
F_219 ( L_55 ) ;
}
F_45 ( L_61 ) ;
F_45 ( L_62 ) ;
V_25 = F_64 ( V_59 , NULL , NULL , NULL , 1 ) ;
if ( F_51 ( V_25 ) ) {
F_135 ( L_63 ) ;
return;
}
F_214 () ;
V_25 = F_64 ( V_59 , NULL , NULL , NULL , 0 ) ;
if ( F_51 ( V_25 ) ) {
F_135 ( L_64 ) ;
return;
}
F_219 ( L_55 ) ;
}
static void
F_220 ( unsigned long V_182 , unsigned long V_183 ,
struct V_236 * V_237 , struct V_238 * V_238 )
{
struct V_239 * V_31 ;
struct V_240 * V_40 ;
struct V_241 * V_41 ;
unsigned long V_38 ;
long V_242 ;
int V_243 ;
int V_39 ;
V_39 = F_24 () ;
F_221 () ;
V_243 = F_222 () ;
V_242 = F_44 ( & F_223 ( V_244 , V_243 ) ) ;
if ( V_242 != 1 )
goto V_118;
F_23 ( V_38 ) ;
V_31 = F_224 ( & V_40 ,
V_245 , sizeof( * V_41 ) ,
V_38 , V_39 ) ;
if ( ! V_31 )
goto V_118;
V_41 = F_26 ( V_31 ) ;
V_41 -> V_182 = V_182 ;
V_41 -> V_183 = V_183 ;
F_225 ( V_40 , V_31 , V_38 , V_39 ) ;
V_118:
F_226 ( & F_223 ( V_244 , V_243 ) ) ;
F_227 () ;
}
static T_5 void F_228 ( void )
{
int V_25 ;
V_25 = F_229 ( & V_246 ) ;
if ( F_13 ( V_25 < 0 ) ) {
F_45 ( L_65 ) ;
return;
}
F_45 ( L_66 ) ;
F_217 () ;
F_230 ( & V_246 ) ;
}
static T_5 void F_228 ( void )
{
}
static T_5 int F_231 ( void )
{
if ( ! V_213 ) {
F_217 () ;
F_228 () ;
}
return 0 ;
}
