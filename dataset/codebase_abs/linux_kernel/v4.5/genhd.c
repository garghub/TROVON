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
static void F_51 ( struct V_2 * V_3 )
{
struct V_66 * V_67 = F_48 ( V_3 ) ;
struct V_68 * V_69 ;
struct V_10 V_11 ;
struct V_1 * V_5 ;
int V_70 ;
V_67 -> V_71 = V_3 -> V_72 ;
F_52 ( V_67 , L_7 , V_3 -> V_73 ) ;
F_53 ( V_67 , 1 ) ;
if ( F_54 ( V_67 ) )
return;
if ( ! V_74 ) {
V_70 = F_55 ( V_75 , & V_67 -> V_65 ,
F_56 ( & V_67 -> V_65 ) ) ;
if ( V_70 ) {
F_57 ( V_67 ) ;
return;
}
}
F_58 ( V_67 , true ) ;
V_3 -> V_24 . V_76 = F_59 ( L_8 , & V_67 -> V_65 ) ;
V_3 -> V_77 = F_59 ( L_9 , & V_67 -> V_65 ) ;
if ( ! F_60 ( V_3 ) )
goto exit;
if ( ! F_61 ( V_3 ) )
goto exit;
V_69 = F_62 ( V_3 , 0 ) ;
if ( ! V_69 )
goto exit;
V_69 -> V_78 = 1 ;
V_70 = F_63 ( V_69 , V_79 , NULL ) ;
if ( V_70 < 0 )
goto exit;
F_64 ( V_69 , V_79 ) ;
exit:
F_53 ( V_67 , 0 ) ;
F_65 ( & V_67 -> V_65 , V_80 ) ;
F_9 ( & V_11 , V_3 , 0 ) ;
while ( ( V_5 = F_10 ( & V_11 ) ) )
F_65 ( & F_7 ( V_5 ) -> V_65 , V_80 ) ;
F_13 ( & V_11 ) ;
}
void F_66 ( struct V_2 * V_3 )
{
struct V_81 * V_82 ;
T_3 V_49 ;
int V_83 ;
F_29 ( V_3 -> V_50 && ! ( V_3 -> V_25 || V_3 -> V_51 ) ) ;
F_29 ( ! V_3 -> V_50 && ! ( V_3 -> V_12 & V_84 ) ) ;
V_3 -> V_12 |= V_85 ;
V_83 = F_32 ( & V_3 -> V_24 , & V_49 ) ;
if ( V_83 ) {
F_29 ( 1 ) ;
return;
}
F_48 ( V_3 ) -> V_49 = V_49 ;
V_3 -> V_25 = F_41 ( V_49 ) ;
V_3 -> V_51 = F_43 ( V_49 ) ;
F_67 ( V_3 ) ;
V_82 = & V_3 -> V_86 -> V_81 ;
F_68 ( V_82 , F_69 ( V_3 ) ) ;
F_70 ( F_69 ( V_3 ) , V_3 -> V_50 , NULL ,
F_47 , F_49 , V_3 ) ;
F_51 ( V_3 ) ;
F_71 ( V_3 ) ;
F_72 ( ! F_73 ( V_3 -> V_86 ) ) ;
V_83 = F_55 ( & F_48 ( V_3 ) -> V_65 , & V_82 -> V_87 -> V_65 ,
L_10 ) ;
F_29 ( V_83 ) ;
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
F_80 ( V_3 , V_5 -> V_4 ) ;
}
F_13 ( & V_11 ) ;
F_79 ( V_3 , 0 ) ;
F_81 ( V_3 , 0 ) ;
V_3 -> V_12 &= ~ V_85 ;
F_82 ( & F_48 ( V_3 ) -> V_65 , L_10 ) ;
F_83 ( V_3 ) ;
F_45 ( F_69 ( V_3 ) , V_3 -> V_50 ) ;
F_84 ( & V_3 -> V_24 , 0 ) ;
V_3 -> V_24 . V_88 = 0 ;
F_85 ( V_3 -> V_24 . V_76 ) ;
F_85 ( V_3 -> V_77 ) ;
if ( ! V_74 )
F_82 ( V_75 , F_86 ( F_48 ( V_3 ) ) ) ;
F_58 ( F_48 ( V_3 ) , false ) ;
F_57 ( F_48 ( V_3 ) ) ;
}
static T_4 F_87 ( struct V_66 * V_87 ,
struct V_89 * V_90 ,
char * V_91 )
{
struct V_2 * V_3 = F_88 ( V_87 ) ;
if ( ! V_3 -> V_92 )
return sprintf ( V_91 , L_11 ) ;
return F_89 ( V_3 -> V_92 , V_91 , 0 ) ;
}
static T_4 F_90 ( struct V_66 * V_87 ,
struct V_89 * V_90 ,
const char * V_91 , T_5 V_9 )
{
struct V_2 * V_3 = F_88 ( V_87 ) ;
if ( ! V_3 -> V_92 )
return - V_93 ;
return F_91 ( V_3 -> V_92 , V_91 , V_9 , 0 ) ;
}
struct V_2 * F_92 ( T_3 V_49 , int * V_4 )
{
struct V_2 * V_3 = NULL ;
if ( F_41 ( V_49 ) != V_57 ) {
struct V_63 * V_65 ;
V_65 = F_93 ( V_62 , V_49 , V_4 ) ;
if ( V_65 )
V_3 = F_88 ( F_94 ( V_65 ) ) ;
} else {
struct V_1 * V_5 ;
F_36 ( & V_52 ) ;
V_5 = F_95 ( & V_53 , F_30 ( F_43 ( V_49 ) ) ) ;
if ( V_5 && F_50 ( F_33 ( V_5 ) ) ) {
* V_4 = V_5 -> V_4 ;
V_3 = F_33 ( V_5 ) ;
}
F_38 ( & V_52 ) ;
}
return V_3 ;
}
struct V_68 * F_62 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 ;
struct V_68 * V_69 = NULL ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 )
V_69 = F_96 ( F_97 ( V_5 ) ) ;
F_11 ( V_5 ) ;
return V_69 ;
}
void T_6 F_98 ( void )
{
struct V_94 V_95 ;
struct V_66 * V_87 ;
F_99 ( & V_95 , & V_96 , NULL , & V_97 ) ;
while ( ( V_87 = F_100 ( & V_95 ) ) ) {
struct V_2 * V_3 = F_88 ( V_87 ) ;
struct V_10 V_11 ;
struct V_1 * V_5 ;
char V_98 [ V_99 ] ;
char V_100 [ V_60 ] ;
if ( F_61 ( V_3 ) == 0 ||
( V_3 -> V_12 & V_101 ) )
continue;
F_9 ( & V_11 , V_3 , V_15 ) ;
while ( ( V_5 = F_10 ( & V_11 ) ) ) {
bool V_102 = V_5 == & V_3 -> V_24 ;
F_24 ( L_12 , V_102 ? L_13 : L_14 ,
F_44 ( F_97 ( V_5 ) , V_100 ) ,
( unsigned long long ) F_12 ( V_5 ) >> 1
, V_73 ( V_3 , V_5 -> V_4 , V_98 ) ,
V_5 -> V_103 ? V_5 -> V_103 -> V_104 : L_13 ) ;
if ( V_102 ) {
if ( V_3 -> V_72 != NULL &&
V_3 -> V_72 -> V_105 != NULL )
F_24 ( L_15 ,
V_3 -> V_72 -> V_105 -> V_35 ) ;
else
F_24 ( L_16 ) ;
} else
F_24 ( L_11 ) ;
}
F_13 ( & V_11 ) ;
}
F_101 ( & V_95 ) ;
}
static void * F_102 ( struct V_27 * V_28 , T_7 * V_106 )
{
T_7 V_107 = * V_106 ;
struct V_94 * V_95 ;
struct V_66 * V_87 ;
V_95 = F_25 ( sizeof( * V_95 ) , V_42 ) ;
if ( ! V_95 )
return F_103 ( - V_43 ) ;
V_28 -> V_108 = V_95 ;
F_99 ( V_95 , & V_96 , NULL , & V_97 ) ;
do {
V_87 = F_100 ( V_95 ) ;
if ( ! V_87 )
return NULL ;
} while ( V_107 -- );
return F_88 ( V_87 ) ;
}
static void * F_104 ( struct V_27 * V_28 , void * V_109 , T_7 * V_106 )
{
struct V_66 * V_87 ;
( * V_106 ) ++ ;
V_87 = F_100 ( V_28 -> V_108 ) ;
if ( V_87 )
return F_88 ( V_87 ) ;
return NULL ;
}
static void F_105 ( struct V_27 * V_28 , void * V_109 )
{
struct V_94 * V_95 = V_28 -> V_108 ;
if ( V_95 ) {
F_101 ( V_95 ) ;
F_27 ( V_95 ) ;
}
}
static void * F_106 ( struct V_27 * V_28 , T_7 * V_106 )
{
void * V_37 ;
V_37 = F_102 ( V_28 , V_106 ) ;
if ( ! F_107 ( V_37 ) && ! * V_106 )
F_108 ( V_28 , L_17 ) ;
return V_37 ;
}
static int F_109 ( struct V_27 * V_28 , void * V_109 )
{
struct V_2 * V_110 = V_109 ;
struct V_10 V_11 ;
struct V_1 * V_5 ;
char V_58 [ V_99 ] ;
if ( ! F_61 ( V_110 ) || ( ! F_110 ( V_110 ) &&
( V_110 -> V_12 & V_111 ) ) )
return 0 ;
if ( V_110 -> V_12 & V_101 )
return 0 ;
F_9 ( & V_11 , V_110 , V_15 ) ;
while ( ( V_5 = F_10 ( & V_11 ) ) )
F_20 ( V_28 , L_18 ,
F_41 ( F_97 ( V_5 ) ) , F_43 ( F_97 ( V_5 ) ) ,
( unsigned long long ) F_12 ( V_5 ) >> 1 ,
V_73 ( V_110 , V_5 -> V_4 , V_58 ) ) ;
F_13 ( & V_11 ) ;
return 0 ;
}
static int F_111 ( struct V_112 * V_112 , struct V_113 * V_113 )
{
return F_112 ( V_113 , & V_114 ) ;
}
static struct V_63 * F_113 ( T_3 V_49 , int * V_4 , void * V_64 )
{
if ( F_114 ( L_19 , F_41 ( V_49 ) , F_43 ( V_49 ) ) > 0 )
F_114 ( L_20 , F_41 ( V_49 ) ) ;
return NULL ;
}
static int T_6 F_115 ( void )
{
int error ;
V_96 . V_115 = V_116 ;
error = F_116 ( & V_96 ) ;
if ( F_2 ( error ) )
return error ;
V_62 = F_117 ( F_113 , & V_32 ) ;
F_118 () ;
F_22 ( V_57 , L_21 ) ;
if ( ! V_74 )
V_75 = F_59 ( L_22 , NULL ) ;
return 0 ;
}
static T_4 F_119 ( struct V_66 * V_87 ,
struct V_89 * V_90 , char * V_58 )
{
struct V_2 * V_3 = F_88 ( V_87 ) ;
return sprintf ( V_58 , L_23 , V_3 -> V_50 ) ;
}
static T_4 F_120 ( struct V_66 * V_87 ,
struct V_89 * V_90 , char * V_58 )
{
struct V_2 * V_3 = F_88 ( V_87 ) ;
return sprintf ( V_58 , L_23 , F_110 ( V_3 ) ) ;
}
static T_4 F_121 ( struct V_66 * V_87 ,
struct V_89 * V_90 , char * V_58 )
{
struct V_2 * V_3 = F_88 ( V_87 ) ;
return sprintf ( V_58 , L_23 ,
( V_3 -> V_12 & V_111 ? 1 : 0 ) ) ;
}
static T_4 F_122 ( struct V_66 * V_87 ,
struct V_89 * V_90 , char * V_58 )
{
struct V_2 * V_3 = F_88 ( V_87 ) ;
return sprintf ( V_58 , L_23 , F_123 ( V_3 ) ? 1 : 0 ) ;
}
static T_4 F_124 ( struct V_66 * V_87 ,
struct V_89 * V_90 , char * V_58 )
{
struct V_2 * V_3 = F_88 ( V_87 ) ;
return sprintf ( V_58 , L_24 , V_3 -> V_12 ) ;
}
static T_4 F_125 ( struct V_66 * V_87 ,
struct V_89 * V_90 ,
char * V_58 )
{
struct V_2 * V_3 = F_88 ( V_87 ) ;
return sprintf ( V_58 , L_23 , F_126 ( V_3 -> V_86 ) ) ;
}
static T_4 F_127 ( struct V_66 * V_87 ,
struct V_89 * V_90 ,
char * V_58 )
{
struct V_2 * V_3 = F_88 ( V_87 ) ;
return sprintf ( V_58 , L_23 , F_128 ( V_3 -> V_86 ) ) ;
}
static void F_129 ( struct V_2 * V_3 ,
struct V_6 * V_117 )
{
struct V_6 * V_118 = V_3 -> V_8 ;
F_16 ( V_3 -> V_8 , V_117 ) ;
if ( V_118 ) {
F_16 ( V_118 -> V_23 , NULL ) ;
F_130 ( V_118 , V_119 ) ;
}
}
int F_131 ( struct V_2 * V_3 , int V_4 )
{
struct V_6 * V_118 = V_3 -> V_8 ;
struct V_6 * V_117 ;
int V_9 = V_118 ? V_118 -> V_9 : 0 ;
int V_22 , V_120 ;
T_5 V_121 ;
V_120 = V_4 + 1 ;
if ( V_120 < 0 )
return - V_122 ;
if ( F_110 ( V_3 ) && V_120 > F_110 ( V_3 ) )
return - V_122 ;
if ( V_120 <= V_9 )
return 0 ;
V_121 = sizeof( * V_117 ) + V_120 * sizeof( V_117 -> V_5 [ 0 ] ) ;
V_117 = F_132 ( V_121 , V_42 , V_3 -> V_123 ) ;
if ( ! V_117 )
return - V_43 ;
V_117 -> V_9 = V_120 ;
for ( V_22 = 0 ; V_22 < V_9 ; V_22 ++ )
F_16 ( V_117 -> V_5 [ V_22 ] , V_118 -> V_5 [ V_22 ] ) ;
F_129 ( V_3 , V_117 ) ;
return 0 ;
}
static void F_133 ( struct V_66 * V_87 )
{
struct V_2 * V_3 = F_88 ( V_87 ) ;
F_40 ( V_87 -> V_49 ) ;
F_134 ( V_3 ) ;
F_27 ( V_3 -> V_124 ) ;
F_129 ( V_3 , NULL ) ;
F_135 ( & V_3 -> V_24 ) ;
if ( V_3 -> V_86 )
F_136 ( V_3 -> V_86 ) ;
F_27 ( V_3 ) ;
}
static char * F_137 ( struct V_66 * V_87 , T_8 * V_125 ,
T_9 * V_126 , T_10 * V_127 )
{
struct V_2 * V_3 = F_88 ( V_87 ) ;
if ( V_3 -> V_128 )
return V_3 -> V_128 ( V_3 , V_125 ) ;
return NULL ;
}
static int F_138 ( struct V_27 * V_28 , void * V_109 )
{
struct V_2 * V_129 = V_109 ;
struct V_10 V_11 ;
struct V_1 * V_130 ;
char V_58 [ V_99 ] ;
int V_131 ;
F_9 ( & V_11 , V_129 , V_16 ) ;
while ( ( V_130 = F_10 ( & V_11 ) ) ) {
V_131 = F_139 () ;
F_140 ( V_131 , V_130 ) ;
F_141 () ;
F_20 ( V_28 , L_25
L_26 ,
F_41 ( F_97 ( V_130 ) ) , F_43 ( F_97 ( V_130 ) ) ,
V_73 ( V_129 , V_130 -> V_4 , V_58 ) ,
F_142 ( V_130 , V_132 [ V_133 ] ) ,
F_142 ( V_130 , V_134 [ V_133 ] ) ,
F_142 ( V_130 , V_135 [ V_133 ] ) ,
F_143 ( F_142 ( V_130 , V_136 [ V_133 ] ) ) ,
F_142 ( V_130 , V_132 [ V_137 ] ) ,
F_142 ( V_130 , V_134 [ V_137 ] ) ,
F_142 ( V_130 , V_135 [ V_137 ] ) ,
F_143 ( F_142 ( V_130 , V_136 [ V_137 ] ) ) ,
F_144 ( V_130 ) ,
F_143 ( F_142 ( V_130 , V_138 ) ) ,
F_143 ( F_142 ( V_130 , V_139 ) )
) ;
}
F_13 ( & V_11 ) ;
return 0 ;
}
static int F_145 ( struct V_112 * V_112 , struct V_113 * V_113 )
{
return F_112 ( V_113 , & V_140 ) ;
}
static int T_6 F_146 ( void )
{
F_147 ( L_27 , 0 , NULL , & V_141 ) ;
F_147 ( L_28 , 0 , NULL , & V_142 ) ;
return 0 ;
}
T_3 F_148 ( const char * V_35 , int V_4 )
{
T_3 V_49 = F_34 ( 0 , 0 ) ;
struct V_94 V_95 ;
struct V_66 * V_87 ;
F_99 ( & V_95 , & V_96 , NULL , & V_97 ) ;
while ( ( V_87 = F_100 ( & V_95 ) ) ) {
struct V_2 * V_3 = F_88 ( V_87 ) ;
struct V_1 * V_5 ;
if ( strcmp ( F_86 ( V_87 ) , V_35 ) )
continue;
if ( V_4 < V_3 -> V_50 ) {
V_49 = F_34 ( F_41 ( V_87 -> V_49 ) ,
F_43 ( V_87 -> V_49 ) + V_4 ) ;
break;
}
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 ) {
V_49 = F_97 ( V_5 ) ;
F_11 ( V_5 ) ;
break;
}
F_11 ( V_5 ) ;
}
F_101 ( & V_95 ) ;
return V_49 ;
}
struct V_2 * F_149 ( int V_50 )
{
return F_150 ( V_50 , V_143 ) ;
}
struct V_2 * F_150 ( int V_50 , int V_123 )
{
struct V_2 * V_3 ;
V_3 = F_132 ( sizeof( struct V_2 ) , V_42 , V_123 ) ;
if ( V_3 ) {
if ( ! F_151 ( & V_3 -> V_24 ) ) {
F_27 ( V_3 ) ;
return NULL ;
}
V_3 -> V_123 = V_123 ;
if ( F_131 ( V_3 , 0 ) ) {
F_152 ( & V_3 -> V_24 ) ;
F_27 ( V_3 ) ;
return NULL ;
}
V_3 -> V_8 -> V_5 [ 0 ] = & V_3 -> V_24 ;
F_153 ( & V_3 -> V_24 . V_144 ) ;
if ( F_154 ( & V_3 -> V_24 ) ) {
F_135 ( & V_3 -> V_24 ) ;
F_27 ( V_3 ) ;
return NULL ;
}
V_3 -> V_50 = V_50 ;
F_155 ( V_3 ) ;
F_48 ( V_3 ) -> V_145 = & V_96 ;
F_48 ( V_3 ) -> type = & V_97 ;
F_156 ( F_48 ( V_3 ) ) ;
}
return V_3 ;
}
struct V_63 * F_50 ( struct V_2 * V_3 )
{
struct V_146 * V_147 ;
struct V_63 * V_65 ;
if ( ! V_3 -> V_148 )
return NULL ;
V_147 = V_3 -> V_148 -> V_147 ;
if ( V_147 && ! F_157 ( V_147 ) )
return NULL ;
V_65 = F_158 ( & F_48 ( V_3 ) -> V_65 ) ;
if ( V_65 == NULL ) {
F_159 ( V_147 ) ;
return NULL ;
}
return V_65 ;
}
void F_160 ( struct V_2 * V_3 )
{
if ( V_3 )
F_85 ( & F_48 ( V_3 ) -> V_65 ) ;
}
static void F_161 ( struct V_2 * V_149 , int V_150 )
{
char V_151 [] = L_29 ;
char * V_152 [] = { V_151 , NULL } ;
if ( ! V_150 )
V_151 [ 8 ] = '0' ;
F_162 ( & F_48 ( V_149 ) -> V_65 , V_153 , V_152 ) ;
}
void F_163 ( struct V_68 * V_69 , int V_154 )
{
V_69 -> V_155 -> V_156 = V_154 ;
}
void F_164 ( struct V_2 * V_3 , int V_154 )
{
struct V_10 V_11 ;
struct V_1 * V_5 ;
if ( V_3 -> V_24 . V_156 != V_154 ) {
F_161 ( V_3 , V_154 ) ;
V_3 -> V_24 . V_156 = V_154 ;
}
F_9 ( & V_11 , V_3 , V_19 ) ;
while ( ( V_5 = F_10 ( & V_11 ) ) )
V_5 -> V_156 = V_154 ;
F_13 ( & V_11 ) ;
}
int F_165 ( struct V_68 * V_69 )
{
if ( ! V_69 )
return 0 ;
return V_69 -> V_155 -> V_156 ;
}
int F_79 ( struct V_2 * V_3 , int V_4 )
{
int V_157 = 0 ;
struct V_68 * V_69 = F_62 ( V_3 , V_4 ) ;
if ( V_69 ) {
F_166 ( V_69 ) ;
V_157 = F_167 ( V_69 , true ) ;
F_168 ( V_69 ) ;
}
return V_157 ;
}
static unsigned long F_169 ( struct V_2 * V_3 )
{
struct V_158 * V_159 = V_3 -> V_159 ;
long V_160 = 0 ;
if ( V_159 -> V_161 >= 0 )
V_160 = V_159 -> V_161 ;
else if ( V_3 -> V_162 & ~ V_3 -> V_163 )
V_160 = V_164 ;
return F_170 ( V_160 ) ;
}
void F_171 ( struct V_2 * V_3 )
{
struct V_158 * V_159 = V_3 -> V_159 ;
unsigned long V_12 ;
bool V_165 ;
if ( ! V_159 )
return;
F_19 ( & V_159 -> V_166 ) ;
F_172 ( & V_159 -> V_167 , V_12 ) ;
V_165 = ! V_159 -> V_168 ++ ;
F_173 ( & V_159 -> V_167 , V_12 ) ;
if ( V_165 )
F_174 ( & V_3 -> V_159 -> V_169 ) ;
F_21 ( & V_159 -> V_166 ) ;
}
static void F_175 ( struct V_2 * V_3 , bool V_170 )
{
struct V_158 * V_159 = V_3 -> V_159 ;
unsigned long V_171 ;
unsigned long V_12 ;
F_172 ( & V_159 -> V_167 , V_12 ) ;
if ( F_72 ( V_159 -> V_168 <= 0 ) )
goto V_172;
if ( -- V_159 -> V_168 )
goto V_172;
V_171 = F_169 ( V_3 ) ;
F_176 ( & V_159 -> V_169 . V_173 , V_171 / 4 ) ;
if ( V_170 )
F_177 ( V_174 ,
& V_159 -> V_169 , 0 ) ;
else if ( V_171 )
F_177 ( V_174 ,
& V_159 -> V_169 , V_171 ) ;
V_172:
F_173 ( & V_159 -> V_167 , V_12 ) ;
}
void F_178 ( struct V_2 * V_3 )
{
if ( V_3 -> V_159 )
F_175 ( V_3 , false ) ;
}
void F_179 ( struct V_2 * V_3 , unsigned int V_175 )
{
struct V_158 * V_159 = V_3 -> V_159 ;
if ( ! V_159 )
return;
F_180 ( & V_159 -> V_167 ) ;
V_159 -> V_176 |= V_175 ;
if ( ! V_159 -> V_168 )
F_181 ( V_174 ,
& V_159 -> V_169 , 0 ) ;
F_182 ( & V_159 -> V_167 ) ;
}
unsigned int F_183 ( struct V_2 * V_3 , unsigned int V_175 )
{
const struct V_177 * V_178 = V_3 -> V_148 ;
struct V_158 * V_159 = V_3 -> V_159 ;
unsigned int V_179 ;
unsigned int V_176 = V_175 ;
if ( ! V_159 ) {
if ( ( V_175 & V_180 ) &&
V_178 -> V_181 && V_178 -> V_181 ( V_3 ) )
return V_180 ;
return 0 ;
}
F_171 ( V_3 ) ;
F_180 ( & V_159 -> V_167 ) ;
V_176 |= V_159 -> V_176 ;
V_159 -> V_176 = 0 ;
F_182 ( & V_159 -> V_167 ) ;
F_184 ( V_159 , & V_176 ) ;
F_175 ( V_3 , V_159 -> V_176 ? true : false ) ;
F_180 ( & V_159 -> V_167 ) ;
V_179 = V_159 -> V_179 & V_175 ;
V_159 -> V_179 &= ~ V_175 ;
F_182 ( & V_159 -> V_167 ) ;
F_72 ( V_176 & V_175 ) ;
return V_179 ;
}
static void F_185 ( struct V_182 * V_183 )
{
struct V_184 * V_169 = F_186 ( V_183 ) ;
struct V_158 * V_159 = F_187 ( V_169 , struct V_158 , V_169 ) ;
F_184 ( V_159 , & V_159 -> V_176 ) ;
}
static void F_184 ( struct V_158 * V_159 ,
unsigned int * V_185 )
{
struct V_2 * V_3 = V_159 -> V_3 ;
char * V_152 [ F_23 ( V_186 ) + 1 ] = { } ;
unsigned int V_176 = * V_185 ;
unsigned int V_162 ;
unsigned long V_171 ;
int V_187 = 0 , V_22 ;
V_162 = V_3 -> V_148 -> V_188 ( V_3 , V_176 ) ;
F_180 ( & V_159 -> V_167 ) ;
V_162 &= ~ V_159 -> V_179 ;
V_159 -> V_179 |= V_162 ;
* V_185 &= ~ V_176 ;
V_171 = F_169 ( V_3 ) ;
if ( ! V_159 -> V_168 && V_171 )
F_177 ( V_174 ,
& V_159 -> V_169 , V_171 ) ;
F_182 ( & V_159 -> V_167 ) ;
for ( V_22 = 0 ; V_22 < F_23 ( V_186 ) ; V_22 ++ )
if ( V_162 & V_3 -> V_162 & ( 1 << V_22 ) )
V_152 [ V_187 ++ ] = V_186 [ V_22 ] ;
if ( V_187 )
F_162 ( & F_48 ( V_3 ) -> V_65 , V_153 , V_152 ) ;
}
static T_4 F_188 ( unsigned int V_162 , char * V_58 )
{
const char * V_189 = L_13 ;
T_4 V_106 = 0 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < F_23 ( V_190 ) ; V_22 ++ )
if ( V_162 & ( 1 << V_22 ) ) {
V_106 += sprintf ( V_58 + V_106 , L_30 ,
V_189 , V_190 [ V_22 ] ) ;
V_189 = L_31 ;
}
if ( V_106 )
V_106 += sprintf ( V_58 + V_106 , L_11 ) ;
return V_106 ;
}
static T_4 F_189 ( struct V_66 * V_87 ,
struct V_89 * V_90 , char * V_58 )
{
struct V_2 * V_3 = F_88 ( V_87 ) ;
return F_188 ( V_3 -> V_162 , V_58 ) ;
}
static T_4 F_190 ( struct V_66 * V_87 ,
struct V_89 * V_90 , char * V_58 )
{
struct V_2 * V_3 = F_88 ( V_87 ) ;
return F_188 ( V_3 -> V_163 , V_58 ) ;
}
static T_4 F_191 ( struct V_66 * V_87 ,
struct V_89 * V_90 ,
char * V_58 )
{
struct V_2 * V_3 = F_88 ( V_87 ) ;
return sprintf ( V_58 , L_32 , V_3 -> V_159 -> V_161 ) ;
}
static T_4 F_192 ( struct V_66 * V_87 ,
struct V_89 * V_90 ,
const char * V_58 , T_5 V_191 )
{
struct V_2 * V_3 = F_88 ( V_87 ) ;
long V_171 ;
if ( ! V_191 || ! sscanf ( V_58 , L_33 , & V_171 ) )
return - V_122 ;
if ( V_171 < 0 && V_171 != - 1 )
return - V_122 ;
F_171 ( V_3 ) ;
V_3 -> V_159 -> V_161 = V_171 ;
F_175 ( V_3 , true ) ;
return V_191 ;
}
static int F_193 ( const char * V_192 ,
const struct V_193 * V_194 )
{
struct V_158 * V_159 ;
int V_39 ;
V_39 = F_194 ( V_192 , V_194 ) ;
if ( V_39 < 0 )
return V_39 ;
F_19 ( & V_195 ) ;
F_195 (ev, &disk_events, node)
F_179 ( V_159 -> V_3 , 0 ) ;
F_21 ( & V_195 ) ;
return 0 ;
}
static void F_67 ( struct V_2 * V_3 )
{
struct V_158 * V_159 ;
if ( ! V_3 -> V_148 -> V_188 )
return;
V_159 = F_196 ( sizeof( * V_159 ) , V_42 ) ;
if ( ! V_159 ) {
F_197 ( L_34 , V_3 -> V_73 ) ;
return;
}
F_198 ( & V_159 -> V_196 ) ;
V_159 -> V_3 = V_3 ;
F_199 ( & V_159 -> V_167 ) ;
F_200 ( & V_159 -> V_166 ) ;
V_159 -> V_168 = 1 ;
V_159 -> V_161 = - 1 ;
F_201 ( & V_159 -> V_169 , F_185 ) ;
V_3 -> V_159 = V_159 ;
}
static void F_74 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_159 )
return;
if ( F_202 ( & F_48 ( V_3 ) -> V_65 , V_197 ) < 0 )
F_197 ( L_35 ,
V_3 -> V_73 ) ;
F_19 ( & V_195 ) ;
F_203 ( & V_3 -> V_159 -> V_196 , & V_158 ) ;
F_21 ( & V_195 ) ;
F_175 ( V_3 , true ) ;
}
static void F_78 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_159 )
return;
F_171 ( V_3 ) ;
F_19 ( & V_195 ) ;
F_204 ( & V_3 -> V_159 -> V_196 ) ;
F_21 ( & V_195 ) ;
F_205 ( & F_48 ( V_3 ) -> V_65 , V_197 ) ;
}
static void F_134 ( struct V_2 * V_3 )
{
F_72 ( V_3 -> V_159 && V_3 -> V_159 -> V_168 != 1 ) ;
F_27 ( V_3 -> V_159 ) ;
}
