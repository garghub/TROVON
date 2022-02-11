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
F_35 ( V_42 ) ;
F_36 ( & V_52 ) ;
V_14 = F_37 ( & V_53 , V_5 , 0 , V_54 , V_55 ) ;
F_38 ( & V_52 ) ;
F_39 () ;
if ( V_14 < 0 )
return V_14 == - V_56 ? - V_40 : V_14 ;
* V_49 = F_34 ( V_57 , F_30 ( V_14 ) ) ;
return 0 ;
}
void F_40 ( T_3 V_49 )
{
if ( V_49 == F_34 ( 0 , 0 ) )
return;
if ( F_41 ( V_49 ) == V_57 ) {
F_36 ( & V_52 ) ;
F_42 ( & V_53 , F_30 ( F_43 ( V_49 ) ) ) ;
F_38 ( & V_52 ) ;
}
}
static char * F_44 ( T_3 V_49 , char * V_58 )
{
if ( F_41 ( V_49 ) <= 0xff && F_43 ( V_49 ) <= 0xff ) {
char V_59 [ V_60 ] ;
snprintf ( V_59 , V_60 , L_4 , F_41 ( V_49 ) , F_43 ( V_49 ) ) ;
snprintf ( V_58 , V_60 , L_5 , V_59 ) ;
} else
snprintf ( V_58 , V_60 , L_6 , F_41 ( V_49 ) , F_43 ( V_49 ) ) ;
return V_58 ;
}
void F_45 ( T_3 V_49 , unsigned long V_61 )
{
F_46 ( V_62 , V_49 , V_61 ) ;
}
static struct V_63 * F_47 ( T_3 V_49 , int * V_4 , void * V_64 )
{
struct V_2 * V_37 = V_64 ;
return & F_48 ( V_37 ) -> V_65 ;
}
static int F_49 ( T_3 V_49 , void * V_64 )
{
struct V_2 * V_37 = V_64 ;
if ( ! F_50 ( V_37 ) )
return - 1 ;
return 0 ;
}
static void F_51 ( struct V_66 * V_67 , struct V_2 * V_3 )
{
struct V_66 * V_68 = F_48 ( V_3 ) ;
struct V_69 * V_70 ;
struct V_10 V_11 ;
struct V_1 * V_5 ;
int V_71 ;
V_68 -> V_67 = V_67 ;
F_52 ( V_68 , L_7 , V_3 -> V_72 ) ;
F_53 ( V_68 , 1 ) ;
if ( F_54 ( V_68 ) )
return;
if ( ! V_73 ) {
V_71 = F_55 ( V_74 , & V_68 -> V_65 ,
F_56 ( & V_68 -> V_65 ) ) ;
if ( V_71 ) {
F_57 ( V_68 ) ;
return;
}
}
F_58 ( V_68 , true ) ;
V_3 -> V_24 . V_75 = F_59 ( L_8 , & V_68 -> V_65 ) ;
V_3 -> V_76 = F_59 ( L_9 , & V_68 -> V_65 ) ;
if ( ! F_60 ( V_3 ) )
goto exit;
if ( ! F_61 ( V_3 ) )
goto exit;
V_70 = F_62 ( V_3 , 0 ) ;
if ( ! V_70 )
goto exit;
V_70 -> V_77 = 1 ;
V_71 = F_63 ( V_70 , V_78 , NULL ) ;
if ( V_71 < 0 )
goto exit;
F_64 ( V_70 , V_78 ) ;
exit:
F_53 ( V_68 , 0 ) ;
F_65 ( & V_68 -> V_65 , V_79 ) ;
F_9 ( & V_11 , V_3 , 0 ) ;
while ( ( V_5 = F_10 ( & V_11 ) ) )
F_65 ( & F_7 ( V_5 ) -> V_65 , V_79 ) ;
F_13 ( & V_11 ) ;
}
void F_66 ( struct V_66 * V_67 , struct V_2 * V_3 )
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
F_48 ( V_3 ) -> V_49 = V_49 ;
V_3 -> V_25 = F_41 ( V_49 ) ;
V_3 -> V_51 = F_43 ( V_49 ) ;
F_67 ( V_3 ) ;
V_81 = V_3 -> V_85 -> V_80 ;
F_68 ( V_81 , F_48 ( V_3 ) ) ;
F_69 ( F_70 ( V_3 ) , V_3 -> V_50 , NULL ,
F_47 , F_49 , V_3 ) ;
F_51 ( V_67 , V_3 ) ;
F_71 ( V_3 ) ;
F_72 ( ! F_73 ( V_3 -> V_85 ) ) ;
V_82 = F_55 ( & F_48 ( V_3 ) -> V_65 , & V_81 -> V_86 -> V_65 ,
L_10 ) ;
F_29 ( V_82 ) ;
F_74 ( V_3 ) ;
F_75 ( V_3 ) ;
}
void F_76 ( struct V_2 * V_3 )
{
struct V_10 V_11 ;
struct V_1 * V_5 ;
F_77 ( V_3 ) ;
F_78 ( V_3 ) ;
F_9 ( & V_11 , V_3 ,
V_19 | V_13 ) ;
while ( ( V_5 = F_10 ( & V_11 ) ) ) {
F_79 ( V_3 , V_5 -> V_4 ) ;
F_80 ( F_81 ( V_5 ) ) ;
F_82 ( V_3 , V_5 -> V_4 ) ;
}
F_13 ( & V_11 ) ;
F_79 ( V_3 , 0 ) ;
F_80 ( F_70 ( V_3 ) ) ;
F_83 ( V_3 , 0 ) ;
V_3 -> V_12 &= ~ V_84 ;
F_84 ( & F_48 ( V_3 ) -> V_65 , L_10 ) ;
if ( V_3 -> V_85 ) {
F_85 ( V_3 -> V_85 -> V_80 ) ;
F_86 ( V_3 ) ;
} else {
F_29 ( 1 ) ;
}
F_45 ( F_70 ( V_3 ) , V_3 -> V_50 ) ;
F_87 ( & V_3 -> V_24 , 0 ) ;
V_3 -> V_24 . V_87 = 0 ;
F_88 ( V_3 -> V_24 . V_75 ) ;
F_88 ( V_3 -> V_76 ) ;
if ( ! V_73 )
F_84 ( V_74 , F_89 ( F_48 ( V_3 ) ) ) ;
F_58 ( F_48 ( V_3 ) , false ) ;
F_57 ( F_48 ( V_3 ) ) ;
}
static T_4 F_90 ( struct V_66 * V_86 ,
struct V_88 * V_89 ,
char * V_90 )
{
struct V_2 * V_3 = F_91 ( V_86 ) ;
if ( ! V_3 -> V_91 )
return sprintf ( V_90 , L_11 ) ;
return F_92 ( V_3 -> V_91 , V_90 , 0 ) ;
}
static T_4 F_93 ( struct V_66 * V_86 ,
struct V_88 * V_89 ,
const char * V_90 , T_5 V_9 )
{
struct V_2 * V_3 = F_91 ( V_86 ) ;
if ( ! V_3 -> V_91 )
return - V_92 ;
return F_94 ( V_3 -> V_91 , V_90 , V_9 , 0 ) ;
}
struct V_2 * F_95 ( T_3 V_49 , int * V_4 )
{
struct V_2 * V_3 = NULL ;
if ( F_41 ( V_49 ) != V_57 ) {
struct V_63 * V_65 ;
V_65 = F_96 ( V_62 , V_49 , V_4 ) ;
if ( V_65 )
V_3 = F_91 ( F_97 ( V_65 ) ) ;
} else {
struct V_1 * V_5 ;
F_36 ( & V_52 ) ;
V_5 = F_98 ( & V_53 , F_30 ( F_43 ( V_49 ) ) ) ;
if ( V_5 && F_50 ( F_33 ( V_5 ) ) ) {
* V_4 = V_5 -> V_4 ;
V_3 = F_33 ( V_5 ) ;
}
F_38 ( & V_52 ) ;
}
return V_3 ;
}
struct V_69 * F_62 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 ;
struct V_69 * V_70 = NULL ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 )
V_70 = F_99 ( F_81 ( V_5 ) ) ;
F_11 ( V_5 ) ;
return V_70 ;
}
void T_6 F_100 ( void )
{
struct V_93 V_94 ;
struct V_66 * V_86 ;
F_101 ( & V_94 , & V_95 , NULL , & V_96 ) ;
while ( ( V_86 = F_102 ( & V_94 ) ) ) {
struct V_2 * V_3 = F_91 ( V_86 ) ;
struct V_10 V_11 ;
struct V_1 * V_5 ;
char V_97 [ V_98 ] ;
char V_99 [ V_60 ] ;
if ( F_61 ( V_3 ) == 0 ||
( V_3 -> V_12 & V_100 ) )
continue;
F_9 ( & V_11 , V_3 , V_15 ) ;
while ( ( V_5 = F_10 ( & V_11 ) ) ) {
bool V_101 = V_5 == & V_3 -> V_24 ;
F_24 ( L_12 , V_101 ? L_13 : L_14 ,
F_44 ( F_81 ( V_5 ) , V_99 ) ,
( unsigned long long ) F_12 ( V_5 ) >> 1
, V_72 ( V_3 , V_5 -> V_4 , V_97 ) ,
V_5 -> V_102 ? V_5 -> V_102 -> V_103 : L_13 ) ;
if ( V_101 ) {
if ( V_86 -> V_67 && V_86 -> V_67 -> V_104 )
F_24 ( L_15 ,
V_86 -> V_67 -> V_104 -> V_35 ) ;
else
F_24 ( L_16 ) ;
} else
F_24 ( L_11 ) ;
}
F_13 ( & V_11 ) ;
}
F_103 ( & V_94 ) ;
}
static void * F_104 ( struct V_27 * V_28 , T_7 * V_105 )
{
T_7 V_106 = * V_105 ;
struct V_93 * V_94 ;
struct V_66 * V_86 ;
V_94 = F_25 ( sizeof( * V_94 ) , V_42 ) ;
if ( ! V_94 )
return F_105 ( - V_43 ) ;
V_28 -> V_107 = V_94 ;
F_101 ( V_94 , & V_95 , NULL , & V_96 ) ;
do {
V_86 = F_102 ( V_94 ) ;
if ( ! V_86 )
return NULL ;
} while ( V_106 -- );
return F_91 ( V_86 ) ;
}
static void * F_106 ( struct V_27 * V_28 , void * V_108 , T_7 * V_105 )
{
struct V_66 * V_86 ;
( * V_105 ) ++ ;
V_86 = F_102 ( V_28 -> V_107 ) ;
if ( V_86 )
return F_91 ( V_86 ) ;
return NULL ;
}
static void F_107 ( struct V_27 * V_28 , void * V_108 )
{
struct V_93 * V_94 = V_28 -> V_107 ;
if ( V_94 ) {
F_103 ( V_94 ) ;
F_27 ( V_94 ) ;
V_28 -> V_107 = NULL ;
}
}
static void * F_108 ( struct V_27 * V_28 , T_7 * V_105 )
{
void * V_37 ;
V_37 = F_104 ( V_28 , V_105 ) ;
if ( ! F_109 ( V_37 ) && ! * V_105 )
F_110 ( V_28 , L_17 ) ;
return V_37 ;
}
static int F_111 ( struct V_27 * V_28 , void * V_108 )
{
struct V_2 * V_109 = V_108 ;
struct V_10 V_11 ;
struct V_1 * V_5 ;
char V_58 [ V_98 ] ;
if ( ! F_61 ( V_109 ) || ( ! F_112 ( V_109 ) &&
( V_109 -> V_12 & V_110 ) ) )
return 0 ;
if ( V_109 -> V_12 & V_100 )
return 0 ;
F_9 ( & V_11 , V_109 , V_15 ) ;
while ( ( V_5 = F_10 ( & V_11 ) ) )
F_20 ( V_28 , L_18 ,
F_41 ( F_81 ( V_5 ) ) , F_43 ( F_81 ( V_5 ) ) ,
( unsigned long long ) F_12 ( V_5 ) >> 1 ,
V_72 ( V_109 , V_5 -> V_4 , V_58 ) ) ;
F_13 ( & V_11 ) ;
return 0 ;
}
static int F_113 ( struct V_111 * V_111 , struct V_112 * V_112 )
{
return F_114 ( V_112 , & V_113 ) ;
}
static struct V_63 * F_115 ( T_3 V_49 , int * V_4 , void * V_64 )
{
if ( F_116 ( L_19 , F_41 ( V_49 ) , F_43 ( V_49 ) ) > 0 )
F_116 ( L_20 , F_41 ( V_49 ) ) ;
return NULL ;
}
static int T_6 F_117 ( void )
{
int error ;
V_95 . V_114 = V_115 ;
error = F_118 ( & V_95 ) ;
if ( F_2 ( error ) )
return error ;
V_62 = F_119 ( F_115 , & V_32 ) ;
F_120 () ;
F_22 ( V_57 , L_21 ) ;
if ( ! V_73 )
V_74 = F_59 ( L_22 , NULL ) ;
return 0 ;
}
static T_4 F_121 ( struct V_66 * V_86 ,
struct V_88 * V_89 , char * V_58 )
{
struct V_2 * V_3 = F_91 ( V_86 ) ;
return sprintf ( V_58 , L_23 , V_3 -> V_50 ) ;
}
static T_4 F_122 ( struct V_66 * V_86 ,
struct V_88 * V_89 , char * V_58 )
{
struct V_2 * V_3 = F_91 ( V_86 ) ;
return sprintf ( V_58 , L_23 , F_112 ( V_3 ) ) ;
}
static T_4 F_123 ( struct V_66 * V_86 ,
struct V_88 * V_89 , char * V_58 )
{
struct V_2 * V_3 = F_91 ( V_86 ) ;
return sprintf ( V_58 , L_23 ,
( V_3 -> V_12 & V_110 ? 1 : 0 ) ) ;
}
static T_4 F_124 ( struct V_66 * V_86 ,
struct V_88 * V_89 , char * V_58 )
{
struct V_2 * V_3 = F_91 ( V_86 ) ;
return sprintf ( V_58 , L_23 , F_125 ( V_3 ) ? 1 : 0 ) ;
}
static T_4 F_126 ( struct V_66 * V_86 ,
struct V_88 * V_89 , char * V_58 )
{
struct V_2 * V_3 = F_91 ( V_86 ) ;
return sprintf ( V_58 , L_24 , V_3 -> V_12 ) ;
}
static T_4 F_127 ( struct V_66 * V_86 ,
struct V_88 * V_89 ,
char * V_58 )
{
struct V_2 * V_3 = F_91 ( V_86 ) ;
return sprintf ( V_58 , L_23 , F_128 ( V_3 -> V_85 ) ) ;
}
static T_4 F_129 ( struct V_66 * V_86 ,
struct V_88 * V_89 ,
char * V_58 )
{
struct V_2 * V_3 = F_91 ( V_86 ) ;
return sprintf ( V_58 , L_23 , F_130 ( V_3 -> V_85 ) ) ;
}
static void F_131 ( struct V_2 * V_3 ,
struct V_6 * V_116 )
{
struct V_6 * V_117 = V_3 -> V_8 ;
F_16 ( V_3 -> V_8 , V_116 ) ;
if ( V_117 ) {
F_16 ( V_117 -> V_23 , NULL ) ;
F_132 ( V_117 , V_118 ) ;
}
}
int F_133 ( struct V_2 * V_3 , int V_4 )
{
struct V_6 * V_117 = V_3 -> V_8 ;
struct V_6 * V_116 ;
int V_9 = V_117 ? V_117 -> V_9 : 0 ;
int V_22 , V_119 ;
T_5 V_120 ;
V_119 = V_4 + 1 ;
if ( V_119 < 0 )
return - V_121 ;
if ( F_112 ( V_3 ) && V_119 > F_112 ( V_3 ) )
return - V_121 ;
if ( V_119 <= V_9 )
return 0 ;
V_120 = sizeof( * V_116 ) + V_119 * sizeof( V_116 -> V_5 [ 0 ] ) ;
V_116 = F_134 ( V_120 , V_42 , V_3 -> V_122 ) ;
if ( ! V_116 )
return - V_43 ;
V_116 -> V_9 = V_119 ;
for ( V_22 = 0 ; V_22 < V_9 ; V_22 ++ )
F_16 ( V_116 -> V_5 [ V_22 ] , V_117 -> V_5 [ V_22 ] ) ;
F_131 ( V_3 , V_116 ) ;
return 0 ;
}
static void F_135 ( struct V_66 * V_86 )
{
struct V_2 * V_3 = F_91 ( V_86 ) ;
F_40 ( V_86 -> V_49 ) ;
F_136 ( V_3 ) ;
F_27 ( V_3 -> V_123 ) ;
F_131 ( V_3 , NULL ) ;
F_137 ( & V_3 -> V_24 ) ;
if ( V_3 -> V_85 )
F_138 ( V_3 -> V_85 ) ;
F_27 ( V_3 ) ;
}
static char * F_139 ( struct V_66 * V_86 , T_8 * V_124 ,
T_9 * V_125 , T_10 * V_126 )
{
struct V_2 * V_3 = F_91 ( V_86 ) ;
if ( V_3 -> V_127 )
return V_3 -> V_127 ( V_3 , V_124 ) ;
return NULL ;
}
static int F_140 ( struct V_27 * V_28 , void * V_108 )
{
struct V_2 * V_128 = V_108 ;
struct V_10 V_11 ;
struct V_1 * V_129 ;
char V_58 [ V_98 ] ;
int V_130 ;
F_9 ( & V_11 , V_128 , V_16 ) ;
while ( ( V_129 = F_10 ( & V_11 ) ) ) {
V_130 = F_141 () ;
F_142 ( V_130 , V_129 ) ;
F_143 () ;
F_20 ( V_28 , L_25
L_26 ,
F_41 ( F_81 ( V_129 ) ) , F_43 ( F_81 ( V_129 ) ) ,
V_72 ( V_128 , V_129 -> V_4 , V_58 ) ,
F_144 ( V_129 , V_131 [ V_132 ] ) ,
F_144 ( V_129 , V_133 [ V_132 ] ) ,
F_144 ( V_129 , V_134 [ V_132 ] ) ,
F_145 ( F_144 ( V_129 , V_135 [ V_132 ] ) ) ,
F_144 ( V_129 , V_131 [ V_136 ] ) ,
F_144 ( V_129 , V_133 [ V_136 ] ) ,
F_144 ( V_129 , V_134 [ V_136 ] ) ,
F_145 ( F_144 ( V_129 , V_135 [ V_136 ] ) ) ,
F_146 ( V_129 ) ,
F_145 ( F_144 ( V_129 , V_137 ) ) ,
F_145 ( F_144 ( V_129 , V_138 ) )
) ;
}
F_13 ( & V_11 ) ;
return 0 ;
}
static int F_147 ( struct V_111 * V_111 , struct V_112 * V_112 )
{
return F_114 ( V_112 , & V_139 ) ;
}
static int T_6 F_148 ( void )
{
F_149 ( L_27 , 0 , NULL , & V_140 ) ;
F_149 ( L_28 , 0 , NULL , & V_141 ) ;
return 0 ;
}
T_3 F_150 ( const char * V_35 , int V_4 )
{
T_3 V_49 = F_34 ( 0 , 0 ) ;
struct V_93 V_94 ;
struct V_66 * V_86 ;
F_101 ( & V_94 , & V_95 , NULL , & V_96 ) ;
while ( ( V_86 = F_102 ( & V_94 ) ) ) {
struct V_2 * V_3 = F_91 ( V_86 ) ;
struct V_1 * V_5 ;
if ( strcmp ( F_89 ( V_86 ) , V_35 ) )
continue;
if ( V_4 < V_3 -> V_50 ) {
V_49 = F_34 ( F_41 ( V_86 -> V_49 ) ,
F_43 ( V_86 -> V_49 ) + V_4 ) ;
break;
}
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 ) {
V_49 = F_81 ( V_5 ) ;
F_11 ( V_5 ) ;
break;
}
F_11 ( V_5 ) ;
}
F_103 ( & V_94 ) ;
return V_49 ;
}
struct V_2 * F_151 ( int V_50 )
{
return F_152 ( V_50 , V_142 ) ;
}
struct V_2 * F_152 ( int V_50 , int V_122 )
{
struct V_2 * V_3 ;
V_3 = F_134 ( sizeof( struct V_2 ) , V_42 , V_122 ) ;
if ( V_3 ) {
if ( ! F_153 ( & V_3 -> V_24 ) ) {
F_27 ( V_3 ) ;
return NULL ;
}
V_3 -> V_122 = V_122 ;
if ( F_133 ( V_3 , 0 ) ) {
F_154 ( & V_3 -> V_24 ) ;
F_27 ( V_3 ) ;
return NULL ;
}
V_3 -> V_8 -> V_5 [ 0 ] = & V_3 -> V_24 ;
F_155 ( & V_3 -> V_24 . V_143 ) ;
if ( F_156 ( & V_3 -> V_24 ) ) {
F_137 ( & V_3 -> V_24 ) ;
F_27 ( V_3 ) ;
return NULL ;
}
V_3 -> V_50 = V_50 ;
F_157 ( V_3 ) ;
F_48 ( V_3 ) -> V_144 = & V_95 ;
F_48 ( V_3 ) -> type = & V_96 ;
F_158 ( F_48 ( V_3 ) ) ;
}
return V_3 ;
}
struct V_63 * F_50 ( struct V_2 * V_3 )
{
struct V_145 * V_146 ;
struct V_63 * V_65 ;
if ( ! V_3 -> V_147 )
return NULL ;
V_146 = V_3 -> V_147 -> V_146 ;
if ( V_146 && ! F_159 ( V_146 ) )
return NULL ;
V_65 = F_160 ( & F_48 ( V_3 ) -> V_65 ) ;
if ( V_65 == NULL ) {
F_161 ( V_146 ) ;
return NULL ;
}
return V_65 ;
}
void F_162 ( struct V_2 * V_3 )
{
if ( V_3 )
F_88 ( & F_48 ( V_3 ) -> V_65 ) ;
}
static void F_163 ( struct V_2 * V_148 , int V_149 )
{
char V_150 [] = L_29 ;
char * V_151 [] = { V_150 , NULL } ;
if ( ! V_149 )
V_150 [ 8 ] = '0' ;
F_164 ( & F_48 ( V_148 ) -> V_65 , V_152 , V_151 ) ;
}
void F_165 ( struct V_69 * V_70 , int V_153 )
{
V_70 -> V_154 -> V_155 = V_153 ;
}
void F_166 ( struct V_2 * V_3 , int V_153 )
{
struct V_10 V_11 ;
struct V_1 * V_5 ;
if ( V_3 -> V_24 . V_155 != V_153 ) {
F_163 ( V_3 , V_153 ) ;
V_3 -> V_24 . V_155 = V_153 ;
}
F_9 ( & V_11 , V_3 , V_19 ) ;
while ( ( V_5 = F_10 ( & V_11 ) ) )
V_5 -> V_155 = V_153 ;
F_13 ( & V_11 ) ;
}
int F_167 ( struct V_69 * V_70 )
{
if ( ! V_70 )
return 0 ;
return V_70 -> V_154 -> V_155 ;
}
int F_79 ( struct V_2 * V_3 , int V_4 )
{
int V_156 = 0 ;
struct V_69 * V_70 = F_62 ( V_3 , V_4 ) ;
if ( V_70 ) {
F_168 ( V_70 ) ;
V_156 = F_169 ( V_70 , true ) ;
F_170 ( V_70 ) ;
}
return V_156 ;
}
static unsigned long F_171 ( struct V_2 * V_3 )
{
struct V_157 * V_158 = V_3 -> V_158 ;
long V_159 = 0 ;
if ( V_158 -> V_160 >= 0 )
V_159 = V_158 -> V_160 ;
else if ( V_3 -> V_161 & ~ V_3 -> V_162 )
V_159 = V_163 ;
return F_172 ( V_159 ) ;
}
void F_173 ( struct V_2 * V_3 )
{
struct V_157 * V_158 = V_3 -> V_158 ;
unsigned long V_12 ;
bool V_164 ;
if ( ! V_158 )
return;
F_19 ( & V_158 -> V_165 ) ;
F_174 ( & V_158 -> V_166 , V_12 ) ;
V_164 = ! V_158 -> V_167 ++ ;
F_175 ( & V_158 -> V_166 , V_12 ) ;
if ( V_164 )
F_176 ( & V_3 -> V_158 -> V_168 ) ;
F_21 ( & V_158 -> V_165 ) ;
}
static void F_177 ( struct V_2 * V_3 , bool V_169 )
{
struct V_157 * V_158 = V_3 -> V_158 ;
unsigned long V_170 ;
unsigned long V_12 ;
F_174 ( & V_158 -> V_166 , V_12 ) ;
if ( F_72 ( V_158 -> V_167 <= 0 ) )
goto V_171;
if ( -- V_158 -> V_167 )
goto V_171;
V_170 = F_171 ( V_3 ) ;
if ( V_169 )
F_178 ( V_172 ,
& V_158 -> V_168 , 0 ) ;
else if ( V_170 )
F_178 ( V_172 ,
& V_158 -> V_168 , V_170 ) ;
V_171:
F_175 ( & V_158 -> V_166 , V_12 ) ;
}
void F_179 ( struct V_2 * V_3 )
{
if ( V_3 -> V_158 )
F_177 ( V_3 , false ) ;
}
void F_180 ( struct V_2 * V_3 , unsigned int V_173 )
{
struct V_157 * V_158 = V_3 -> V_158 ;
if ( ! V_158 )
return;
F_181 ( & V_158 -> V_166 ) ;
V_158 -> V_174 |= V_173 ;
if ( ! V_158 -> V_167 )
F_182 ( V_172 ,
& V_158 -> V_168 , 0 ) ;
F_183 ( & V_158 -> V_166 ) ;
}
unsigned int F_184 ( struct V_2 * V_3 , unsigned int V_173 )
{
const struct V_175 * V_176 = V_3 -> V_147 ;
struct V_157 * V_158 = V_3 -> V_158 ;
unsigned int V_177 ;
unsigned int V_174 = V_173 ;
if ( ! V_158 ) {
if ( ( V_173 & V_178 ) &&
V_176 -> V_179 && V_176 -> V_179 ( V_3 ) )
return V_178 ;
return 0 ;
}
F_173 ( V_3 ) ;
F_181 ( & V_158 -> V_166 ) ;
V_174 |= V_158 -> V_174 ;
V_158 -> V_174 = 0 ;
F_183 ( & V_158 -> V_166 ) ;
F_185 ( V_158 , & V_174 ) ;
F_177 ( V_3 , V_158 -> V_174 ? true : false ) ;
F_181 ( & V_158 -> V_166 ) ;
V_177 = V_158 -> V_177 & V_173 ;
V_158 -> V_177 &= ~ V_173 ;
F_183 ( & V_158 -> V_166 ) ;
F_72 ( V_174 & V_173 ) ;
return V_177 ;
}
static void F_186 ( struct V_180 * V_181 )
{
struct V_182 * V_168 = F_187 ( V_181 ) ;
struct V_157 * V_158 = F_188 ( V_168 , struct V_157 , V_168 ) ;
F_185 ( V_158 , & V_158 -> V_174 ) ;
}
static void F_185 ( struct V_157 * V_158 ,
unsigned int * V_183 )
{
struct V_2 * V_3 = V_158 -> V_3 ;
char * V_151 [ F_23 ( V_184 ) + 1 ] = { } ;
unsigned int V_174 = * V_183 ;
unsigned int V_161 ;
unsigned long V_170 ;
int V_185 = 0 , V_22 ;
V_161 = V_3 -> V_147 -> V_186 ( V_3 , V_174 ) ;
F_181 ( & V_158 -> V_166 ) ;
V_161 &= ~ V_158 -> V_177 ;
V_158 -> V_177 |= V_161 ;
* V_183 &= ~ V_174 ;
V_170 = F_171 ( V_3 ) ;
if ( ! V_158 -> V_167 && V_170 )
F_178 ( V_172 ,
& V_158 -> V_168 , V_170 ) ;
F_183 ( & V_158 -> V_166 ) ;
for ( V_22 = 0 ; V_22 < F_23 ( V_184 ) ; V_22 ++ )
if ( V_161 & V_3 -> V_161 & ( 1 << V_22 ) )
V_151 [ V_185 ++ ] = V_184 [ V_22 ] ;
if ( V_185 )
F_164 ( & F_48 ( V_3 ) -> V_65 , V_152 , V_151 ) ;
}
static T_4 F_189 ( unsigned int V_161 , char * V_58 )
{
const char * V_187 = L_13 ;
T_4 V_105 = 0 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < F_23 ( V_188 ) ; V_22 ++ )
if ( V_161 & ( 1 << V_22 ) ) {
V_105 += sprintf ( V_58 + V_105 , L_30 ,
V_187 , V_188 [ V_22 ] ) ;
V_187 = L_31 ;
}
if ( V_105 )
V_105 += sprintf ( V_58 + V_105 , L_11 ) ;
return V_105 ;
}
static T_4 F_190 ( struct V_66 * V_86 ,
struct V_88 * V_89 , char * V_58 )
{
struct V_2 * V_3 = F_91 ( V_86 ) ;
return F_189 ( V_3 -> V_161 , V_58 ) ;
}
static T_4 F_191 ( struct V_66 * V_86 ,
struct V_88 * V_89 , char * V_58 )
{
struct V_2 * V_3 = F_91 ( V_86 ) ;
return F_189 ( V_3 -> V_162 , V_58 ) ;
}
static T_4 F_192 ( struct V_66 * V_86 ,
struct V_88 * V_89 ,
char * V_58 )
{
struct V_2 * V_3 = F_91 ( V_86 ) ;
return sprintf ( V_58 , L_32 , V_3 -> V_158 -> V_160 ) ;
}
static T_4 F_193 ( struct V_66 * V_86 ,
struct V_88 * V_89 ,
const char * V_58 , T_5 V_189 )
{
struct V_2 * V_3 = F_91 ( V_86 ) ;
long V_170 ;
if ( ! V_189 || ! sscanf ( V_58 , L_33 , & V_170 ) )
return - V_121 ;
if ( V_170 < 0 && V_170 != - 1 )
return - V_121 ;
F_173 ( V_3 ) ;
V_3 -> V_158 -> V_160 = V_170 ;
F_177 ( V_3 , true ) ;
return V_189 ;
}
static int F_194 ( const char * V_190 ,
const struct V_191 * V_192 )
{
struct V_157 * V_158 ;
int V_39 ;
V_39 = F_195 ( V_190 , V_192 ) ;
if ( V_39 < 0 )
return V_39 ;
F_19 ( & V_193 ) ;
F_196 (ev, &disk_events, node)
F_180 ( V_158 -> V_3 , 0 ) ;
F_21 ( & V_193 ) ;
return 0 ;
}
static void F_67 ( struct V_2 * V_3 )
{
struct V_157 * V_158 ;
if ( ! V_3 -> V_147 -> V_186 )
return;
V_158 = F_197 ( sizeof( * V_158 ) , V_42 ) ;
if ( ! V_158 ) {
F_198 ( L_34 , V_3 -> V_72 ) ;
return;
}
F_199 ( & V_158 -> V_194 ) ;
V_158 -> V_3 = V_3 ;
F_200 ( & V_158 -> V_166 ) ;
F_201 ( & V_158 -> V_165 ) ;
V_158 -> V_167 = 1 ;
V_158 -> V_160 = - 1 ;
F_202 ( & V_158 -> V_168 , F_186 ) ;
V_3 -> V_158 = V_158 ;
}
static void F_74 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_158 )
return;
if ( F_203 ( & F_48 ( V_3 ) -> V_65 , V_195 ) < 0 )
F_198 ( L_35 ,
V_3 -> V_72 ) ;
F_19 ( & V_193 ) ;
F_204 ( & V_3 -> V_158 -> V_194 , & V_157 ) ;
F_21 ( & V_193 ) ;
F_177 ( V_3 , true ) ;
}
static void F_78 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_158 )
return;
F_173 ( V_3 ) ;
F_19 ( & V_193 ) ;
F_205 ( & V_3 -> V_158 -> V_194 ) ;
F_21 ( & V_193 ) ;
F_206 ( & F_48 ( V_3 ) -> V_65 , V_195 ) ;
}
static void F_136 ( struct V_2 * V_3 )
{
F_72 ( V_3 -> V_158 && V_3 -> V_158 -> V_167 != 1 ) ;
F_27 ( V_3 -> V_158 ) ;
}
