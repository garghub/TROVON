struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 = NULL ;
struct V_6 * V_7 ;
if ( F_2 ( V_4 < 0 ) )
return NULL ;
F_3 () ;
V_7 = F_4 ( V_3 -> V_8 ) ;
if ( F_5 ( V_4 < V_7 -> V_9 ) ) {
V_5 = F_4 ( V_7 -> V_5 [ V_4 ] ) ;
if ( V_5 )
F_6 ( F_7 ( V_5 ) ) ;
}
F_8 () ;
return V_5 ;
}
void F_9 ( struct V_10 * V_11 , struct V_2 * V_3 ,
unsigned int V_12 )
{
struct V_6 * V_7 ;
F_3 () ;
V_7 = F_4 ( V_3 -> V_8 ) ;
V_11 -> V_3 = V_3 ;
V_11 -> V_5 = NULL ;
if ( V_12 & V_13 )
V_11 -> V_14 = V_7 -> V_9 - 1 ;
else if ( V_12 & ( V_15 | V_16 ) )
V_11 -> V_14 = 0 ;
else
V_11 -> V_14 = 1 ;
V_11 -> V_12 = V_12 ;
F_8 () ;
}
struct V_1 * F_10 ( struct V_10 * V_11 )
{
struct V_6 * V_7 ;
int V_17 , V_18 ;
F_11 ( V_11 -> V_5 ) ;
V_11 -> V_5 = NULL ;
F_3 () ;
V_7 = F_4 ( V_11 -> V_3 -> V_8 ) ;
if ( V_11 -> V_12 & V_13 ) {
V_17 = - 1 ;
if ( V_11 -> V_12 & ( V_15 |
V_16 ) )
V_18 = - 1 ;
else
V_18 = 0 ;
} else {
V_17 = 1 ;
V_18 = V_7 -> V_9 ;
}
for (; V_11 -> V_14 != V_18 ; V_11 -> V_14 += V_17 ) {
struct V_1 * V_5 ;
V_5 = F_4 ( V_7 -> V_5 [ V_11 -> V_14 ] ) ;
if ( ! V_5 )
continue;
if ( ! F_12 ( V_5 ) &&
! ( V_11 -> V_12 & V_19 ) &&
! ( V_11 -> V_12 & V_16 &&
V_11 -> V_14 == 0 ) )
continue;
F_6 ( F_7 ( V_5 ) ) ;
V_11 -> V_5 = V_5 ;
V_11 -> V_14 += V_17 ;
break;
}
F_8 () ;
return V_11 -> V_5 ;
}
void F_13 ( struct V_10 * V_11 )
{
F_11 ( V_11 -> V_5 ) ;
V_11 -> V_5 = NULL ;
}
static inline int F_14 ( struct V_1 * V_5 , T_1 V_20 )
{
return V_5 -> V_21 <= V_20 &&
V_20 < V_5 -> V_21 + F_12 ( V_5 ) ;
}
struct V_1 * F_15 ( struct V_2 * V_3 , T_1 V_20 )
{
struct V_6 * V_7 ;
struct V_1 * V_5 ;
int V_22 ;
V_7 = F_4 ( V_3 -> V_8 ) ;
V_5 = F_4 ( V_7 -> V_23 ) ;
if ( V_5 && F_14 ( V_5 , V_20 ) )
return V_5 ;
for ( V_22 = 1 ; V_22 < V_7 -> V_9 ; V_22 ++ ) {
V_5 = F_4 ( V_7 -> V_5 [ V_22 ] ) ;
if ( V_5 && F_14 ( V_5 , V_20 ) ) {
F_16 ( V_7 -> V_23 , V_5 ) ;
return V_5 ;
}
}
return & V_3 -> V_24 ;
}
static inline int F_17 ( unsigned V_25 )
{
return V_25 % V_26 ;
}
void F_18 ( struct V_27 * V_28 , T_2 V_29 )
{
struct V_30 * V_31 ;
if ( V_29 < V_26 ) {
F_19 ( & V_32 ) ;
for ( V_31 = V_33 [ V_29 ] ; V_31 ; V_31 = V_31 -> V_34 )
F_20 ( V_28 , L_1 , V_31 -> V_25 , V_31 -> V_35 ) ;
F_21 ( & V_32 ) ;
}
}
int F_22 ( unsigned int V_25 , const char * V_35 )
{
struct V_30 * * V_36 , * V_37 ;
int V_38 , V_39 = 0 ;
F_19 ( & V_32 ) ;
if ( V_25 == 0 ) {
for ( V_38 = F_23 ( V_33 ) - 1 ; V_38 > 0 ; V_38 -- ) {
if ( V_33 [ V_38 ] == NULL )
break;
}
if ( V_38 == 0 ) {
F_24 ( L_2 ,
V_35 ) ;
V_39 = - V_40 ;
goto V_41;
}
V_25 = V_38 ;
V_39 = V_25 ;
}
V_37 = F_25 ( sizeof( struct V_30 ) , V_42 ) ;
if ( V_37 == NULL ) {
V_39 = - V_43 ;
goto V_41;
}
V_37 -> V_25 = V_25 ;
F_26 ( V_37 -> V_35 , V_35 , sizeof( V_37 -> V_35 ) ) ;
V_37 -> V_34 = NULL ;
V_38 = F_17 ( V_25 ) ;
for ( V_36 = & V_33 [ V_38 ] ; * V_36 ; V_36 = & ( * V_36 ) -> V_34 ) {
if ( ( * V_36 ) -> V_25 == V_25 )
break;
}
if ( ! * V_36 )
* V_36 = V_37 ;
else
V_39 = - V_40 ;
if ( V_39 < 0 ) {
F_24 ( L_3 ,
V_25 , V_35 ) ;
F_27 ( V_37 ) ;
}
V_41:
F_21 ( & V_32 ) ;
return V_39 ;
}
void F_28 ( unsigned int V_25 , const char * V_35 )
{
struct V_30 * * V_36 ;
struct V_30 * V_37 = NULL ;
int V_38 = F_17 ( V_25 ) ;
F_19 ( & V_32 ) ;
for ( V_36 = & V_33 [ V_38 ] ; * V_36 ; V_36 = & ( * V_36 ) -> V_34 )
if ( ( * V_36 ) -> V_25 == V_25 )
break;
if ( ! * V_36 || strcmp ( ( * V_36 ) -> V_35 , V_35 ) ) {
F_29 ( 1 ) ;
} else {
V_37 = * V_36 ;
* V_36 = V_37 -> V_34 ;
}
F_21 ( & V_32 ) ;
F_27 ( V_37 ) ;
}
static int F_30 ( int V_44 )
{
#ifdef F_31
int V_22 ;
for ( V_22 = 0 ; V_22 < V_45 / 2 ; V_22 ++ ) {
int V_46 = V_44 & ( 1 << V_22 ) ;
int V_47 = V_44 & ( 1 << ( V_45 - 1 - V_22 ) ) ;
int V_48 = V_45 - 1 - 2 * V_22 ;
V_44 ^= V_46 | V_47 ;
V_46 <<= V_48 ;
V_47 >>= V_48 ;
V_44 |= V_46 | V_47 ;
}
#endif
return V_44 ;
}
int F_32 ( struct V_1 * V_5 , T_3 * V_49 )
{
struct V_2 * V_3 = F_33 ( V_5 ) ;
int V_14 ;
if ( V_5 -> V_4 < V_3 -> V_50 ) {
* V_49 = F_34 ( V_3 -> V_25 , V_3 -> V_51 + V_5 -> V_4 ) ;
return 0 ;
}
F_19 ( & V_52 ) ;
V_14 = F_35 ( & V_53 , V_5 , 0 , V_54 , V_42 ) ;
F_21 ( & V_52 ) ;
if ( V_14 < 0 )
return V_14 == - V_55 ? - V_40 : V_14 ;
* V_49 = F_34 ( V_56 , F_30 ( V_14 ) ) ;
return 0 ;
}
void F_36 ( T_3 V_49 )
{
F_37 () ;
if ( V_49 == F_34 ( 0 , 0 ) )
return;
if ( F_38 ( V_49 ) == V_56 ) {
F_19 ( & V_52 ) ;
F_39 ( & V_53 , F_30 ( F_40 ( V_49 ) ) ) ;
F_21 ( & V_52 ) ;
}
}
static char * F_41 ( T_3 V_49 , char * V_57 )
{
if ( F_38 ( V_49 ) <= 0xff && F_40 ( V_49 ) <= 0xff ) {
char V_58 [ V_59 ] ;
snprintf ( V_58 , V_59 , L_4 , F_38 ( V_49 ) , F_40 ( V_49 ) ) ;
snprintf ( V_57 , V_59 , L_5 , V_58 ) ;
} else
snprintf ( V_57 , V_59 , L_6 , F_38 ( V_49 ) , F_40 ( V_49 ) ) ;
return V_57 ;
}
void F_42 ( T_3 V_49 , unsigned long V_60 )
{
F_43 ( V_61 , V_49 , V_60 ) ;
}
static struct V_62 * F_44 ( T_3 V_49 , int * V_4 , void * V_63 )
{
struct V_2 * V_37 = V_63 ;
return & F_45 ( V_37 ) -> V_64 ;
}
static int F_46 ( T_3 V_49 , void * V_63 )
{
struct V_2 * V_37 = V_63 ;
if ( ! F_47 ( V_37 ) )
return - 1 ;
return 0 ;
}
static void F_48 ( struct V_2 * V_3 )
{
struct V_65 * V_66 = F_45 ( V_3 ) ;
struct V_67 * V_68 ;
struct V_10 V_11 ;
struct V_1 * V_5 ;
int V_69 ;
V_66 -> V_70 = V_3 -> V_71 ;
F_49 ( V_66 , V_3 -> V_72 ) ;
F_50 ( V_66 , 1 ) ;
if ( F_51 ( V_66 ) )
return;
if ( ! V_73 ) {
V_69 = F_52 ( V_74 , & V_66 -> V_64 ,
F_53 ( & V_66 -> V_64 ) ) ;
if ( V_69 ) {
F_54 ( V_66 ) ;
return;
}
}
F_55 ( V_66 , true ) ;
V_3 -> V_24 . V_75 = F_56 ( L_7 , & V_66 -> V_64 ) ;
V_3 -> V_76 = F_56 ( L_8 , & V_66 -> V_64 ) ;
if ( ! F_57 ( V_3 ) )
goto exit;
if ( ! F_58 ( V_3 ) )
goto exit;
V_68 = F_59 ( V_3 , 0 ) ;
if ( ! V_68 )
goto exit;
V_68 -> V_77 = 1 ;
V_69 = F_60 ( V_68 , V_78 , NULL ) ;
if ( V_69 < 0 )
goto exit;
F_61 ( V_68 , V_78 ) ;
exit:
F_50 ( V_66 , 0 ) ;
F_62 ( & V_66 -> V_64 , V_79 ) ;
F_9 ( & V_11 , V_3 , 0 ) ;
while ( ( V_5 = F_10 ( & V_11 ) ) )
F_62 ( & F_7 ( V_5 ) -> V_64 , V_79 ) ;
F_13 ( & V_11 ) ;
}
void F_63 ( struct V_2 * V_3 )
{
struct V_80 * V_81 ;
T_3 V_49 ;
int V_82 ;
F_29 ( V_3 -> V_50 && ! ( V_3 -> V_25 || V_3 -> V_51 ) ) ;
F_29 ( ! V_3 -> V_50 && ! ( V_3 -> V_12 & V_83 ) ) ;
V_3 -> V_12 |= V_84 ;
V_82 = F_32 ( & V_3 -> V_24 , & V_49 ) ;
if ( V_82 ) {
F_29 ( 1 ) ;
return;
}
F_45 ( V_3 ) -> V_49 = V_49 ;
V_3 -> V_25 = F_38 ( V_49 ) ;
V_3 -> V_51 = F_40 ( V_49 ) ;
F_64 ( V_3 ) ;
V_81 = & V_3 -> V_85 -> V_80 ;
F_65 ( V_81 , F_66 ( V_3 ) ) ;
F_67 ( F_66 ( V_3 ) , V_3 -> V_50 , NULL ,
F_44 , F_46 , V_3 ) ;
F_48 ( V_3 ) ;
F_68 ( V_3 ) ;
F_69 ( ! F_70 ( V_3 -> V_85 ) ) ;
V_82 = F_52 ( & F_45 ( V_3 ) -> V_64 , & V_81 -> V_86 -> V_64 ,
L_9 ) ;
F_29 ( V_82 ) ;
F_71 ( V_3 ) ;
}
void F_72 ( struct V_2 * V_3 )
{
struct V_10 V_11 ;
struct V_1 * V_5 ;
F_73 ( V_3 ) ;
F_9 ( & V_11 , V_3 ,
V_19 | V_13 ) ;
while ( ( V_5 = F_10 ( & V_11 ) ) ) {
F_74 ( V_3 , V_5 -> V_4 ) ;
F_75 ( V_3 , V_5 -> V_4 ) ;
}
F_13 ( & V_11 ) ;
F_74 ( V_3 , 0 ) ;
F_76 ( V_3 , 0 ) ;
V_3 -> V_12 &= ~ V_84 ;
F_77 ( & F_45 ( V_3 ) -> V_64 , L_9 ) ;
F_78 ( & V_3 -> V_85 -> V_80 ) ;
F_79 ( V_3 ) ;
F_42 ( F_66 ( V_3 ) , V_3 -> V_50 ) ;
F_80 ( & V_3 -> V_24 , 0 ) ;
V_3 -> V_24 . V_87 = 0 ;
F_81 ( V_3 -> V_24 . V_75 ) ;
F_81 ( V_3 -> V_76 ) ;
V_3 -> V_71 = NULL ;
if ( ! V_73 )
F_77 ( V_74 , F_82 ( F_45 ( V_3 ) ) ) ;
F_55 ( F_45 ( V_3 ) , false ) ;
F_54 ( F_45 ( V_3 ) ) ;
F_36 ( F_45 ( V_3 ) -> V_49 ) ;
}
struct V_2 * F_83 ( T_3 V_49 , int * V_4 )
{
struct V_2 * V_3 = NULL ;
if ( F_38 ( V_49 ) != V_56 ) {
struct V_62 * V_64 ;
V_64 = F_84 ( V_61 , V_49 , V_4 ) ;
if ( V_64 )
V_3 = F_85 ( F_86 ( V_64 ) ) ;
} else {
struct V_1 * V_5 ;
F_19 ( & V_52 ) ;
V_5 = F_87 ( & V_53 , F_30 ( F_40 ( V_49 ) ) ) ;
if ( V_5 && F_47 ( F_33 ( V_5 ) ) ) {
* V_4 = V_5 -> V_4 ;
V_3 = F_33 ( V_5 ) ;
}
F_21 ( & V_52 ) ;
}
return V_3 ;
}
struct V_67 * F_59 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 ;
struct V_67 * V_68 = NULL ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 )
V_68 = F_88 ( F_89 ( V_5 ) ) ;
F_11 ( V_5 ) ;
return V_68 ;
}
void T_4 F_90 ( void )
{
struct V_88 V_89 ;
struct V_65 * V_86 ;
F_91 ( & V_89 , & V_90 , NULL , & V_91 ) ;
while ( ( V_86 = F_92 ( & V_89 ) ) ) {
struct V_2 * V_3 = F_85 ( V_86 ) ;
struct V_10 V_11 ;
struct V_1 * V_5 ;
char V_92 [ V_93 ] ;
char V_94 [ V_59 ] ;
if ( F_58 ( V_3 ) == 0 ||
( V_3 -> V_12 & V_95 ) )
continue;
F_9 ( & V_11 , V_3 , V_15 ) ;
while ( ( V_5 = F_10 ( & V_11 ) ) ) {
bool V_96 = V_5 == & V_3 -> V_24 ;
F_24 ( L_10 , V_96 ? L_11 : L_12 ,
F_41 ( F_89 ( V_5 ) , V_94 ) ,
( unsigned long long ) F_12 ( V_5 ) >> 1
, V_72 ( V_3 , V_5 -> V_4 , V_92 ) ,
V_5 -> V_97 ? V_5 -> V_97 -> V_98 : L_11 ) ;
if ( V_96 ) {
if ( V_3 -> V_71 != NULL &&
V_3 -> V_71 -> V_99 != NULL )
F_24 ( L_13 ,
V_3 -> V_71 -> V_99 -> V_35 ) ;
else
F_24 ( L_14 ) ;
} else
F_24 ( L_15 ) ;
}
F_13 ( & V_11 ) ;
}
F_93 ( & V_89 ) ;
}
static void * F_94 ( struct V_27 * V_28 , T_5 * V_100 )
{
T_5 V_101 = * V_100 ;
struct V_88 * V_89 ;
struct V_65 * V_86 ;
V_89 = F_25 ( sizeof( * V_89 ) , V_42 ) ;
if ( ! V_89 )
return F_95 ( - V_43 ) ;
V_28 -> V_102 = V_89 ;
F_91 ( V_89 , & V_90 , NULL , & V_91 ) ;
do {
V_86 = F_92 ( V_89 ) ;
if ( ! V_86 )
return NULL ;
} while ( V_101 -- );
return F_85 ( V_86 ) ;
}
static void * F_96 ( struct V_27 * V_28 , void * V_103 , T_5 * V_100 )
{
struct V_65 * V_86 ;
( * V_100 ) ++ ;
V_86 = F_92 ( V_28 -> V_102 ) ;
if ( V_86 )
return F_85 ( V_86 ) ;
return NULL ;
}
static void F_97 ( struct V_27 * V_28 , void * V_103 )
{
struct V_88 * V_89 = V_28 -> V_102 ;
if ( V_89 ) {
F_93 ( V_89 ) ;
F_27 ( V_89 ) ;
}
}
static void * F_98 ( struct V_27 * V_28 , T_5 * V_100 )
{
void * V_37 ;
V_37 = F_94 ( V_28 , V_100 ) ;
if ( ! F_99 ( V_37 ) && ! * V_100 )
F_100 ( V_28 , L_16 ) ;
return V_37 ;
}
static int F_101 ( struct V_27 * V_28 , void * V_103 )
{
struct V_2 * V_104 = V_103 ;
struct V_10 V_11 ;
struct V_1 * V_5 ;
char V_57 [ V_93 ] ;
if ( ! F_58 ( V_104 ) || ( ! F_102 ( V_104 ) &&
( V_104 -> V_12 & V_105 ) ) )
return 0 ;
if ( V_104 -> V_12 & V_95 )
return 0 ;
F_9 ( & V_11 , V_104 , V_15 ) ;
while ( ( V_5 = F_10 ( & V_11 ) ) )
F_20 ( V_28 , L_17 ,
F_38 ( F_89 ( V_5 ) ) , F_40 ( F_89 ( V_5 ) ) ,
( unsigned long long ) F_12 ( V_5 ) >> 1 ,
V_72 ( V_104 , V_5 -> V_4 , V_57 ) ) ;
F_13 ( & V_11 ) ;
return 0 ;
}
static int F_103 ( struct V_106 * V_106 , struct V_107 * V_107 )
{
return F_104 ( V_107 , & V_108 ) ;
}
static struct V_62 * F_105 ( T_3 V_49 , int * V_4 , void * V_63 )
{
if ( F_106 ( L_18 , F_38 ( V_49 ) , F_40 ( V_49 ) ) > 0 )
F_106 ( L_19 , F_38 ( V_49 ) ) ;
return NULL ;
}
static int T_4 F_107 ( void )
{
int error ;
V_90 . V_109 = V_110 ;
error = F_108 ( & V_90 ) ;
if ( F_2 ( error ) )
return error ;
V_61 = F_109 ( F_105 , & V_32 ) ;
F_110 () ;
F_22 ( V_56 , L_20 ) ;
if ( ! V_73 )
V_74 = F_56 ( L_21 , NULL ) ;
return 0 ;
}
static T_6 F_111 ( struct V_65 * V_86 ,
struct V_111 * V_112 , char * V_57 )
{
struct V_2 * V_3 = F_85 ( V_86 ) ;
return sprintf ( V_57 , L_22 , V_3 -> V_50 ) ;
}
static T_6 F_112 ( struct V_65 * V_86 ,
struct V_111 * V_112 , char * V_57 )
{
struct V_2 * V_3 = F_85 ( V_86 ) ;
return sprintf ( V_57 , L_22 , F_102 ( V_3 ) ) ;
}
static T_6 F_113 ( struct V_65 * V_86 ,
struct V_111 * V_112 , char * V_57 )
{
struct V_2 * V_3 = F_85 ( V_86 ) ;
return sprintf ( V_57 , L_22 ,
( V_3 -> V_12 & V_105 ? 1 : 0 ) ) ;
}
static T_6 F_114 ( struct V_65 * V_86 ,
struct V_111 * V_112 , char * V_57 )
{
struct V_2 * V_3 = F_85 ( V_86 ) ;
return sprintf ( V_57 , L_22 , F_115 ( V_3 ) ? 1 : 0 ) ;
}
static T_6 F_116 ( struct V_65 * V_86 ,
struct V_111 * V_112 , char * V_57 )
{
struct V_2 * V_3 = F_85 ( V_86 ) ;
return sprintf ( V_57 , L_23 , V_3 -> V_12 ) ;
}
static T_6 F_117 ( struct V_65 * V_86 ,
struct V_111 * V_112 ,
char * V_57 )
{
struct V_2 * V_3 = F_85 ( V_86 ) ;
return sprintf ( V_57 , L_22 , F_118 ( V_3 -> V_85 ) ) ;
}
static T_6 F_119 ( struct V_65 * V_86 ,
struct V_111 * V_112 ,
char * V_57 )
{
struct V_2 * V_3 = F_85 ( V_86 ) ;
return sprintf ( V_57 , L_22 , F_120 ( V_3 -> V_85 ) ) ;
}
static void F_121 ( struct V_2 * V_3 ,
struct V_6 * V_113 )
{
struct V_6 * V_114 = V_3 -> V_8 ;
F_16 ( V_3 -> V_8 , V_113 ) ;
if ( V_114 ) {
F_16 ( V_114 -> V_23 , NULL ) ;
F_122 ( V_114 , V_115 ) ;
}
}
int F_123 ( struct V_2 * V_3 , int V_4 )
{
struct V_6 * V_114 = V_3 -> V_8 ;
struct V_6 * V_113 ;
int V_9 = V_114 ? V_114 -> V_9 : 0 ;
int V_116 = V_4 + 1 ;
T_7 V_117 ;
int V_22 ;
if ( F_102 ( V_3 ) && V_116 > F_102 ( V_3 ) )
return - V_118 ;
if ( V_116 <= V_9 )
return 0 ;
V_117 = sizeof( * V_113 ) + V_116 * sizeof( V_113 -> V_5 [ 0 ] ) ;
V_113 = F_124 ( V_117 , V_42 , V_3 -> V_119 ) ;
if ( ! V_113 )
return - V_43 ;
V_113 -> V_9 = V_116 ;
for ( V_22 = 0 ; V_22 < V_9 ; V_22 ++ )
F_16 ( V_113 -> V_5 [ V_22 ] , V_114 -> V_5 [ V_22 ] ) ;
F_121 ( V_3 , V_113 ) ;
return 0 ;
}
static void F_125 ( struct V_65 * V_86 )
{
struct V_2 * V_3 = F_85 ( V_86 ) ;
F_126 ( V_3 ) ;
F_27 ( V_3 -> V_120 ) ;
F_121 ( V_3 , NULL ) ;
F_127 ( & V_3 -> V_24 ) ;
F_128 ( & V_3 -> V_24 ) ;
if ( V_3 -> V_85 )
F_129 ( V_3 -> V_85 ) ;
F_27 ( V_3 ) ;
}
static char * F_130 ( struct V_65 * V_86 , T_8 * V_121 ,
T_9 * V_122 , T_10 * V_123 )
{
struct V_2 * V_3 = F_85 ( V_86 ) ;
if ( V_3 -> V_124 )
return V_3 -> V_124 ( V_3 , V_121 ) ;
return NULL ;
}
static int F_131 ( struct V_27 * V_28 , void * V_103 )
{
struct V_2 * V_125 = V_103 ;
struct V_10 V_11 ;
struct V_1 * V_126 ;
char V_57 [ V_93 ] ;
int V_127 ;
F_9 ( & V_11 , V_125 , V_16 ) ;
while ( ( V_126 = F_10 ( & V_11 ) ) ) {
V_127 = F_132 () ;
F_133 ( V_127 , V_126 ) ;
F_134 () ;
F_20 ( V_28 , L_24
L_25 ,
F_38 ( F_89 ( V_126 ) ) , F_40 ( F_89 ( V_126 ) ) ,
V_72 ( V_125 , V_126 -> V_4 , V_57 ) ,
F_135 ( V_126 , V_128 [ V_129 ] ) ,
F_135 ( V_126 , V_130 [ V_129 ] ) ,
F_135 ( V_126 , V_131 [ V_129 ] ) ,
F_136 ( F_135 ( V_126 , V_132 [ V_129 ] ) ) ,
F_135 ( V_126 , V_128 [ V_133 ] ) ,
F_135 ( V_126 , V_130 [ V_133 ] ) ,
F_135 ( V_126 , V_131 [ V_133 ] ) ,
F_136 ( F_135 ( V_126 , V_132 [ V_133 ] ) ) ,
F_137 ( V_126 ) ,
F_136 ( F_135 ( V_126 , V_134 ) ) ,
F_136 ( F_135 ( V_126 , V_135 ) )
) ;
}
F_13 ( & V_11 ) ;
return 0 ;
}
static int F_138 ( struct V_106 * V_106 , struct V_107 * V_107 )
{
return F_104 ( V_107 , & V_136 ) ;
}
static int T_4 F_139 ( void )
{
F_140 ( L_26 , 0 , NULL , & V_137 ) ;
F_140 ( L_27 , 0 , NULL , & V_138 ) ;
return 0 ;
}
T_3 F_141 ( const char * V_35 , int V_4 )
{
T_3 V_49 = F_34 ( 0 , 0 ) ;
struct V_88 V_89 ;
struct V_65 * V_86 ;
F_91 ( & V_89 , & V_90 , NULL , & V_91 ) ;
while ( ( V_86 = F_92 ( & V_89 ) ) ) {
struct V_2 * V_3 = F_85 ( V_86 ) ;
struct V_1 * V_5 ;
if ( strcmp ( F_82 ( V_86 ) , V_35 ) )
continue;
if ( V_4 < V_3 -> V_50 ) {
V_49 = F_34 ( F_38 ( V_86 -> V_49 ) ,
F_40 ( V_86 -> V_49 ) + V_4 ) ;
break;
}
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 ) {
V_49 = F_89 ( V_5 ) ;
F_11 ( V_5 ) ;
break;
}
F_11 ( V_5 ) ;
}
F_93 ( & V_89 ) ;
return V_49 ;
}
struct V_2 * F_142 ( int V_50 )
{
return F_143 ( V_50 , V_139 ) ;
}
struct V_2 * F_143 ( int V_50 , int V_119 )
{
struct V_2 * V_3 ;
V_3 = F_144 ( sizeof( struct V_2 ) ,
V_42 | V_140 , V_119 ) ;
if ( V_3 ) {
if ( ! F_145 ( & V_3 -> V_24 ) ) {
F_27 ( V_3 ) ;
return NULL ;
}
V_3 -> V_119 = V_119 ;
if ( F_123 ( V_3 , 0 ) ) {
F_127 ( & V_3 -> V_24 ) ;
F_27 ( V_3 ) ;
return NULL ;
}
V_3 -> V_8 -> V_5 [ 0 ] = & V_3 -> V_24 ;
F_146 ( & V_3 -> V_24 . V_141 ) ;
F_147 ( & V_3 -> V_24 ) ;
V_3 -> V_50 = V_50 ;
F_148 ( V_3 ) ;
F_45 ( V_3 ) -> V_142 = & V_90 ;
F_45 ( V_3 ) -> type = & V_91 ;
F_149 ( F_45 ( V_3 ) ) ;
}
return V_3 ;
}
struct V_62 * F_47 ( struct V_2 * V_3 )
{
struct V_143 * V_144 ;
struct V_62 * V_64 ;
if ( ! V_3 -> V_145 )
return NULL ;
V_144 = V_3 -> V_145 -> V_144 ;
if ( V_144 && ! F_150 ( V_144 ) )
return NULL ;
V_64 = F_151 ( & F_45 ( V_3 ) -> V_64 ) ;
if ( V_64 == NULL ) {
F_152 ( V_144 ) ;
return NULL ;
}
return V_64 ;
}
void F_153 ( struct V_2 * V_3 )
{
if ( V_3 )
F_81 ( & F_45 ( V_3 ) -> V_64 ) ;
}
static void F_154 ( struct V_2 * V_146 , int V_147 )
{
char V_148 [] = L_28 ;
char * V_149 [] = { V_148 , NULL } ;
if ( ! V_147 )
V_148 [ 8 ] = '0' ;
F_155 ( & F_45 ( V_146 ) -> V_64 , V_150 , V_149 ) ;
}
void F_156 ( struct V_67 * V_68 , int V_151 )
{
V_68 -> V_152 -> V_153 = V_151 ;
}
void F_157 ( struct V_2 * V_3 , int V_151 )
{
struct V_10 V_11 ;
struct V_1 * V_5 ;
if ( V_3 -> V_24 . V_153 != V_151 ) {
F_154 ( V_3 , V_151 ) ;
V_3 -> V_24 . V_153 = V_151 ;
}
F_9 ( & V_11 , V_3 , V_19 ) ;
while ( ( V_5 = F_10 ( & V_11 ) ) )
V_5 -> V_153 = V_151 ;
F_13 ( & V_11 ) ;
}
int F_158 ( struct V_67 * V_68 )
{
if ( ! V_68 )
return 0 ;
return V_68 -> V_152 -> V_153 ;
}
int F_74 ( struct V_2 * V_3 , int V_4 )
{
int V_154 = 0 ;
struct V_67 * V_68 = F_59 ( V_3 , V_4 ) ;
if ( V_68 ) {
F_159 ( V_68 ) ;
V_154 = F_160 ( V_68 , true ) ;
F_161 ( V_68 ) ;
}
return V_154 ;
}
static unsigned long F_162 ( struct V_2 * V_3 )
{
struct V_155 * V_156 = V_3 -> V_156 ;
long V_157 = 0 ;
if ( V_156 -> V_158 >= 0 )
V_157 = V_156 -> V_158 ;
else if ( V_3 -> V_159 & ~ V_3 -> V_160 )
V_157 = V_161 ;
return F_163 ( V_157 ) ;
}
void F_164 ( struct V_2 * V_3 )
{
struct V_155 * V_156 = V_3 -> V_156 ;
unsigned long V_12 ;
bool V_162 ;
if ( ! V_156 )
return;
F_19 ( & V_156 -> V_163 ) ;
F_165 ( & V_156 -> V_164 , V_12 ) ;
V_162 = ! V_156 -> V_165 ++ ;
F_166 ( & V_156 -> V_164 , V_12 ) ;
if ( V_162 )
F_167 ( & V_3 -> V_156 -> V_166 ) ;
F_21 ( & V_156 -> V_163 ) ;
}
static void F_168 ( struct V_2 * V_3 , bool V_167 )
{
struct V_155 * V_156 = V_3 -> V_156 ;
unsigned long V_168 ;
unsigned long V_12 ;
F_165 ( & V_156 -> V_164 , V_12 ) ;
if ( F_69 ( V_156 -> V_165 <= 0 ) )
goto V_169;
if ( -- V_156 -> V_165 )
goto V_169;
V_168 = F_162 ( V_3 ) ;
F_169 ( & V_156 -> V_166 . V_170 , V_168 / 4 ) ;
if ( V_167 )
F_170 ( V_171 , & V_156 -> V_166 , 0 ) ;
else if ( V_168 )
F_170 ( V_171 , & V_156 -> V_166 , V_168 ) ;
V_169:
F_166 ( & V_156 -> V_164 , V_12 ) ;
}
void F_171 ( struct V_2 * V_3 )
{
if ( V_3 -> V_156 )
F_168 ( V_3 , false ) ;
}
void F_172 ( struct V_2 * V_3 , unsigned int V_172 )
{
struct V_155 * V_156 = V_3 -> V_156 ;
if ( ! V_156 )
return;
F_173 ( & V_156 -> V_164 ) ;
V_156 -> V_173 |= V_172 ;
if ( ! V_156 -> V_165 )
F_174 ( V_171 , & V_156 -> V_166 , 0 ) ;
F_175 ( & V_156 -> V_164 ) ;
}
unsigned int F_176 ( struct V_2 * V_3 , unsigned int V_172 )
{
const struct V_174 * V_175 = V_3 -> V_145 ;
struct V_155 * V_156 = V_3 -> V_156 ;
unsigned int V_176 ;
unsigned int V_173 = V_172 ;
if ( ! V_156 ) {
if ( ( V_172 & V_177 ) &&
V_175 -> V_178 && V_175 -> V_178 ( V_3 ) )
return V_177 ;
return 0 ;
}
F_164 ( V_3 ) ;
F_173 ( & V_156 -> V_164 ) ;
V_173 |= V_156 -> V_173 ;
V_156 -> V_173 = 0 ;
F_175 ( & V_156 -> V_164 ) ;
F_177 ( V_156 , & V_173 ) ;
F_168 ( V_3 , V_156 -> V_173 ? true : false ) ;
F_173 ( & V_156 -> V_164 ) ;
V_176 = V_156 -> V_176 & V_172 ;
V_156 -> V_176 &= ~ V_172 ;
F_175 ( & V_156 -> V_164 ) ;
F_69 ( V_173 & V_172 ) ;
return V_176 ;
}
static void F_178 ( struct V_179 * V_180 )
{
struct V_181 * V_166 = F_179 ( V_180 ) ;
struct V_155 * V_156 = F_180 ( V_166 , struct V_155 , V_166 ) ;
F_177 ( V_156 , & V_156 -> V_173 ) ;
}
static void F_177 ( struct V_155 * V_156 ,
unsigned int * V_182 )
{
struct V_2 * V_3 = V_156 -> V_3 ;
char * V_149 [ F_23 ( V_183 ) + 1 ] = { } ;
unsigned int V_173 = * V_182 ;
unsigned int V_159 ;
unsigned long V_168 ;
int V_184 = 0 , V_22 ;
V_159 = V_3 -> V_145 -> V_185 ( V_3 , V_173 ) ;
F_173 ( & V_156 -> V_164 ) ;
V_159 &= ~ V_156 -> V_176 ;
V_156 -> V_176 |= V_159 ;
* V_182 &= ~ V_173 ;
V_168 = F_162 ( V_3 ) ;
if ( ! V_156 -> V_165 && V_168 )
F_170 ( V_171 , & V_156 -> V_166 , V_168 ) ;
F_175 ( & V_156 -> V_164 ) ;
for ( V_22 = 0 ; V_22 < F_23 ( V_183 ) ; V_22 ++ )
if ( V_159 & V_3 -> V_159 & ( 1 << V_22 ) )
V_149 [ V_184 ++ ] = V_183 [ V_22 ] ;
if ( V_184 )
F_155 ( & F_45 ( V_3 ) -> V_64 , V_150 , V_149 ) ;
}
static T_6 F_181 ( unsigned int V_159 , char * V_57 )
{
const char * V_186 = L_11 ;
T_6 V_100 = 0 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < F_23 ( V_187 ) ; V_22 ++ )
if ( V_159 & ( 1 << V_22 ) ) {
V_100 += sprintf ( V_57 + V_100 , L_29 ,
V_186 , V_187 [ V_22 ] ) ;
V_186 = L_30 ;
}
if ( V_100 )
V_100 += sprintf ( V_57 + V_100 , L_15 ) ;
return V_100 ;
}
static T_6 F_182 ( struct V_65 * V_86 ,
struct V_111 * V_112 , char * V_57 )
{
struct V_2 * V_3 = F_85 ( V_86 ) ;
return F_181 ( V_3 -> V_159 , V_57 ) ;
}
static T_6 F_183 ( struct V_65 * V_86 ,
struct V_111 * V_112 , char * V_57 )
{
struct V_2 * V_3 = F_85 ( V_86 ) ;
return F_181 ( V_3 -> V_160 , V_57 ) ;
}
static T_6 F_184 ( struct V_65 * V_86 ,
struct V_111 * V_112 ,
char * V_57 )
{
struct V_2 * V_3 = F_85 ( V_86 ) ;
return sprintf ( V_57 , L_31 , V_3 -> V_156 -> V_158 ) ;
}
static T_6 F_185 ( struct V_65 * V_86 ,
struct V_111 * V_112 ,
const char * V_57 , T_7 V_188 )
{
struct V_2 * V_3 = F_85 ( V_86 ) ;
long V_168 ;
if ( ! V_188 || ! sscanf ( V_57 , L_32 , & V_168 ) )
return - V_118 ;
if ( V_168 < 0 && V_168 != - 1 )
return - V_118 ;
F_164 ( V_3 ) ;
V_3 -> V_156 -> V_158 = V_168 ;
F_168 ( V_3 , true ) ;
return V_188 ;
}
static int F_186 ( const char * V_189 ,
const struct V_190 * V_191 )
{
struct V_155 * V_156 ;
int V_39 ;
V_39 = F_187 ( V_189 , V_191 ) ;
if ( V_39 < 0 )
return V_39 ;
F_19 ( & V_192 ) ;
F_188 (ev, &disk_events, node)
F_172 ( V_156 -> V_3 , 0 ) ;
F_21 ( & V_192 ) ;
return 0 ;
}
static void F_64 ( struct V_2 * V_3 )
{
struct V_155 * V_156 ;
if ( ! V_3 -> V_145 -> V_185 )
return;
V_156 = F_189 ( sizeof( * V_156 ) , V_42 ) ;
if ( ! V_156 ) {
F_190 ( L_33 , V_3 -> V_72 ) ;
return;
}
F_191 ( & V_156 -> V_193 ) ;
V_156 -> V_3 = V_3 ;
F_192 ( & V_156 -> V_164 ) ;
F_193 ( & V_156 -> V_163 ) ;
V_156 -> V_165 = 1 ;
V_156 -> V_158 = - 1 ;
F_194 ( & V_156 -> V_166 , F_178 ) ;
V_3 -> V_156 = V_156 ;
}
static void F_71 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_156 )
return;
if ( F_195 ( & F_45 ( V_3 ) -> V_64 , V_194 ) < 0 )
F_190 ( L_34 ,
V_3 -> V_72 ) ;
F_19 ( & V_192 ) ;
F_196 ( & V_3 -> V_156 -> V_193 , & V_155 ) ;
F_21 ( & V_192 ) ;
F_168 ( V_3 , true ) ;
}
static void F_73 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_156 )
return;
F_164 ( V_3 ) ;
F_19 ( & V_192 ) ;
F_197 ( & V_3 -> V_156 -> V_193 ) ;
F_21 ( & V_192 ) ;
F_198 ( & F_45 ( V_3 ) -> V_64 , V_194 ) ;
}
static void F_126 ( struct V_2 * V_3 )
{
F_69 ( V_3 -> V_156 && V_3 -> V_156 -> V_165 != 1 ) ;
F_27 ( V_3 -> V_156 ) ;
}
