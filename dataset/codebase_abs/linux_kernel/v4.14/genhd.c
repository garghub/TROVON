void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
if ( V_2 -> V_6 )
return;
F_2 ( & V_4 -> V_7 [ V_5 ] ) ;
if ( V_4 -> V_8 )
F_2 ( & F_3 ( V_4 ) -> V_9 . V_7 [ V_5 ] ) ;
}
void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
if ( V_2 -> V_6 )
return;
F_5 ( & V_4 -> V_7 [ V_5 ] ) ;
if ( V_4 -> V_8 )
F_5 ( & F_3 ( V_4 ) -> V_9 . V_7 [ V_5 ] ) ;
}
void F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_10 [ 2 ] )
{
if ( V_2 -> V_6 ) {
F_7 ( V_2 , V_4 , V_10 ) ;
return;
}
V_10 [ 0 ] = F_8 ( & V_4 -> V_7 [ 0 ] ) +
F_8 ( & V_4 -> V_7 [ 1 ] ) ;
if ( V_4 -> V_8 ) {
V_4 = & F_3 ( V_4 ) -> V_9 ;
V_10 [ 1 ] = F_8 ( & V_4 -> V_7 [ 0 ] ) +
F_8 ( & V_4 -> V_7 [ 1 ] ) ;
}
}
struct V_3 * F_9 ( struct V_11 * V_12 , int V_8 )
{
struct V_13 * V_14 = F_10 ( V_12 -> V_15 ) ;
if ( F_11 ( V_8 < 0 || V_8 >= V_14 -> V_16 ) )
return NULL ;
return F_10 ( V_14 -> V_4 [ V_8 ] ) ;
}
struct V_3 * F_12 ( struct V_11 * V_12 , int V_8 )
{
struct V_3 * V_4 ;
F_13 () ;
V_4 = F_9 ( V_12 , V_8 ) ;
if ( V_4 )
F_14 ( F_15 ( V_4 ) ) ;
F_16 () ;
return V_4 ;
}
void F_17 ( struct V_17 * V_18 , struct V_11 * V_12 ,
unsigned int V_19 )
{
struct V_13 * V_14 ;
F_13 () ;
V_14 = F_10 ( V_12 -> V_15 ) ;
V_18 -> V_12 = V_12 ;
V_18 -> V_4 = NULL ;
if ( V_19 & V_20 )
V_18 -> V_21 = V_14 -> V_16 - 1 ;
else if ( V_19 & ( V_22 | V_23 ) )
V_18 -> V_21 = 0 ;
else
V_18 -> V_21 = 1 ;
V_18 -> V_19 = V_19 ;
F_16 () ;
}
struct V_3 * F_18 ( struct V_17 * V_18 )
{
struct V_13 * V_14 ;
int V_24 , V_25 ;
F_19 ( V_18 -> V_4 ) ;
V_18 -> V_4 = NULL ;
F_13 () ;
V_14 = F_10 ( V_18 -> V_12 -> V_15 ) ;
if ( V_18 -> V_19 & V_20 ) {
V_24 = - 1 ;
if ( V_18 -> V_19 & ( V_22 |
V_23 ) )
V_25 = - 1 ;
else
V_25 = 0 ;
} else {
V_24 = 1 ;
V_25 = V_14 -> V_16 ;
}
for (; V_18 -> V_21 != V_25 ; V_18 -> V_21 += V_24 ) {
struct V_3 * V_4 ;
V_4 = F_10 ( V_14 -> V_4 [ V_18 -> V_21 ] ) ;
if ( ! V_4 )
continue;
if ( ! F_20 ( V_4 ) &&
! ( V_18 -> V_19 & V_26 ) &&
! ( V_18 -> V_19 & V_23 &&
V_18 -> V_21 == 0 ) )
continue;
F_14 ( F_15 ( V_4 ) ) ;
V_18 -> V_4 = V_4 ;
V_18 -> V_21 += V_24 ;
break;
}
F_16 () ;
return V_18 -> V_4 ;
}
void F_21 ( struct V_17 * V_18 )
{
F_19 ( V_18 -> V_4 ) ;
V_18 -> V_4 = NULL ;
}
static inline int F_22 ( struct V_3 * V_4 , T_1 V_27 )
{
return V_4 -> V_28 <= V_27 &&
V_27 < V_4 -> V_28 + F_20 ( V_4 ) ;
}
struct V_3 * F_23 ( struct V_11 * V_12 , T_1 V_27 )
{
struct V_13 * V_14 ;
struct V_3 * V_4 ;
int V_29 ;
V_14 = F_10 ( V_12 -> V_15 ) ;
V_4 = F_10 ( V_14 -> V_30 ) ;
if ( V_4 && F_22 ( V_4 , V_27 ) )
return V_4 ;
for ( V_29 = 1 ; V_29 < V_14 -> V_16 ; V_29 ++ ) {
V_4 = F_10 ( V_14 -> V_4 [ V_29 ] ) ;
if ( V_4 && F_22 ( V_4 , V_27 ) ) {
F_24 ( V_14 -> V_30 , V_4 ) ;
return V_4 ;
}
}
return & V_12 -> V_9 ;
}
static inline int F_25 ( unsigned V_31 )
{
return V_31 % V_32 ;
}
void F_26 ( struct V_33 * V_34 , T_2 V_35 )
{
struct V_36 * V_37 ;
F_27 ( & V_38 ) ;
for ( V_37 = V_39 [ F_25 ( V_35 ) ] ; V_37 ; V_37 = V_37 -> V_40 )
if ( V_37 -> V_31 == V_35 )
F_28 ( V_34 , L_1 , V_37 -> V_31 , V_37 -> V_41 ) ;
F_29 ( & V_38 ) ;
}
int F_30 ( unsigned int V_31 , const char * V_41 )
{
struct V_36 * * V_42 , * V_43 ;
int V_44 , V_45 = 0 ;
F_27 ( & V_38 ) ;
if ( V_31 == 0 ) {
for ( V_44 = F_31 ( V_39 ) - 1 ; V_44 > 0 ; V_44 -- ) {
if ( V_39 [ V_44 ] == NULL )
break;
}
if ( V_44 == 0 ) {
F_32 ( L_2 ,
V_41 ) ;
V_45 = - V_46 ;
goto V_47;
}
V_31 = V_44 ;
V_45 = V_31 ;
}
if ( V_31 >= V_48 ) {
F_33 ( L_3 ,
V_31 , V_48 , V_41 ) ;
V_45 = - V_49 ;
goto V_47;
}
V_43 = F_34 ( sizeof( struct V_36 ) , V_50 ) ;
if ( V_43 == NULL ) {
V_45 = - V_51 ;
goto V_47;
}
V_43 -> V_31 = V_31 ;
F_35 ( V_43 -> V_41 , V_41 , sizeof( V_43 -> V_41 ) ) ;
V_43 -> V_40 = NULL ;
V_44 = F_25 ( V_31 ) ;
for ( V_42 = & V_39 [ V_44 ] ; * V_42 ; V_42 = & ( * V_42 ) -> V_40 ) {
if ( ( * V_42 ) -> V_31 == V_31 )
break;
}
if ( ! * V_42 )
* V_42 = V_43 ;
else
V_45 = - V_46 ;
if ( V_45 < 0 ) {
F_32 ( L_4 ,
V_31 , V_41 ) ;
F_36 ( V_43 ) ;
}
V_47:
F_29 ( & V_38 ) ;
return V_45 ;
}
void F_37 ( unsigned int V_31 , const char * V_41 )
{
struct V_36 * * V_42 ;
struct V_36 * V_43 = NULL ;
int V_44 = F_25 ( V_31 ) ;
F_27 ( & V_38 ) ;
for ( V_42 = & V_39 [ V_44 ] ; * V_42 ; V_42 = & ( * V_42 ) -> V_40 )
if ( ( * V_42 ) -> V_31 == V_31 )
break;
if ( ! * V_42 || strcmp ( ( * V_42 ) -> V_41 , V_41 ) ) {
F_38 ( 1 ) ;
} else {
V_43 = * V_42 ;
* V_42 = V_43 -> V_40 ;
}
F_29 ( & V_38 ) ;
F_36 ( V_43 ) ;
}
static int F_39 ( int V_52 )
{
#ifdef F_40
int V_29 ;
for ( V_29 = 0 ; V_29 < V_53 / 2 ; V_29 ++ ) {
int V_54 = V_52 & ( 1 << V_29 ) ;
int V_55 = V_52 & ( 1 << ( V_53 - 1 - V_29 ) ) ;
int V_56 = V_53 - 1 - 2 * V_29 ;
V_52 ^= V_54 | V_55 ;
V_54 <<= V_56 ;
V_55 >>= V_56 ;
V_52 |= V_54 | V_55 ;
}
#endif
return V_52 ;
}
int F_41 ( struct V_3 * V_4 , T_3 * V_57 )
{
struct V_11 * V_12 = F_3 ( V_4 ) ;
int V_21 ;
if ( V_4 -> V_8 < V_12 -> V_58 ) {
* V_57 = F_42 ( V_12 -> V_31 , V_12 -> V_59 + V_4 -> V_8 ) ;
return 0 ;
}
F_43 ( V_50 ) ;
F_44 ( & V_60 ) ;
V_21 = F_45 ( & V_61 , V_4 , 0 , V_62 , V_63 ) ;
F_46 ( & V_60 ) ;
F_47 () ;
if ( V_21 < 0 )
return V_21 == - V_64 ? - V_46 : V_21 ;
* V_57 = F_42 ( V_65 , F_39 ( V_21 ) ) ;
return 0 ;
}
void F_48 ( T_3 V_57 )
{
if ( V_57 == F_42 ( 0 , 0 ) )
return;
if ( F_49 ( V_57 ) == V_65 ) {
F_44 ( & V_60 ) ;
F_50 ( & V_61 , F_39 ( F_51 ( V_57 ) ) ) ;
F_46 ( & V_60 ) ;
}
}
static char * F_52 ( T_3 V_57 , char * V_66 )
{
if ( F_49 ( V_57 ) <= 0xff && F_51 ( V_57 ) <= 0xff ) {
char V_67 [ V_68 ] ;
snprintf ( V_67 , V_68 , L_5 , F_49 ( V_57 ) , F_51 ( V_57 ) ) ;
snprintf ( V_66 , V_68 , L_6 , V_67 ) ;
} else
snprintf ( V_66 , V_68 , L_7 , F_49 ( V_57 ) , F_51 ( V_57 ) ) ;
return V_66 ;
}
void F_53 ( T_3 V_57 , unsigned long V_69 )
{
F_54 ( V_70 , V_57 , V_69 ) ;
}
static struct V_71 * F_55 ( T_3 V_57 , int * V_8 , void * V_72 )
{
struct V_11 * V_43 = V_72 ;
return & F_56 ( V_43 ) -> V_73 ;
}
static int F_57 ( T_3 V_57 , void * V_72 )
{
struct V_11 * V_43 = V_72 ;
if ( ! F_58 ( V_43 ) )
return - 1 ;
return 0 ;
}
static void F_59 ( struct V_74 * V_75 , struct V_11 * V_12 )
{
struct V_74 * V_76 = F_56 ( V_12 ) ;
struct V_77 * V_78 ;
struct V_17 V_18 ;
struct V_3 * V_4 ;
int V_79 ;
V_76 -> V_75 = V_75 ;
F_60 ( V_76 , L_8 , V_12 -> V_80 ) ;
F_61 ( V_76 , 1 ) ;
if ( F_62 ( V_76 ) )
return;
if ( ! V_81 ) {
V_79 = F_63 ( V_82 , & V_76 -> V_73 ,
F_64 ( & V_76 -> V_73 ) ) ;
if ( V_79 ) {
F_65 ( V_76 ) ;
return;
}
}
F_66 ( V_76 , true ) ;
V_12 -> V_9 . V_83 = F_67 ( L_9 , & V_76 -> V_73 ) ;
V_12 -> V_84 = F_67 ( L_10 , & V_76 -> V_73 ) ;
if ( ! F_68 ( V_12 ) )
goto exit;
if ( ! F_69 ( V_12 ) )
goto exit;
V_78 = F_70 ( V_12 , 0 ) ;
if ( ! V_78 )
goto exit;
V_78 -> V_85 = 1 ;
V_79 = F_71 ( V_78 , V_86 , NULL ) ;
if ( V_79 < 0 )
goto exit;
F_72 ( V_78 , V_86 ) ;
exit:
F_61 ( V_76 , 0 ) ;
F_73 ( & V_76 -> V_73 , V_87 ) ;
F_17 ( & V_18 , V_12 , 0 ) ;
while ( ( V_4 = F_18 ( & V_18 ) ) )
F_73 ( & F_15 ( V_4 ) -> V_73 , V_87 ) ;
F_21 ( & V_18 ) ;
}
void F_74 ( struct V_74 * V_75 , struct V_11 * V_12 )
{
struct V_88 * V_89 ;
T_3 V_57 ;
int V_90 ;
F_38 ( V_12 -> V_58 && ! ( V_12 -> V_31 || V_12 -> V_59 ) ) ;
F_38 ( ! V_12 -> V_58 && ! ( V_12 -> V_19 & V_91 ) ) ;
V_12 -> V_19 |= V_92 ;
V_90 = F_41 ( & V_12 -> V_9 , & V_57 ) ;
if ( V_90 ) {
F_38 ( 1 ) ;
return;
}
F_56 ( V_12 ) -> V_57 = V_57 ;
V_12 -> V_31 = F_49 ( V_57 ) ;
V_12 -> V_59 = F_51 ( V_57 ) ;
F_75 ( V_12 ) ;
V_89 = V_12 -> V_93 -> V_88 ;
F_76 ( V_89 , F_56 ( V_12 ) ) ;
F_77 ( F_78 ( V_12 ) , V_12 -> V_58 , NULL ,
F_55 , F_57 , V_12 ) ;
F_59 ( V_75 , V_12 ) ;
F_79 ( V_12 ) ;
F_80 ( ! F_81 ( V_12 -> V_93 ) ) ;
V_90 = F_63 ( & F_56 ( V_12 ) -> V_73 , & V_89 -> V_94 -> V_73 ,
L_11 ) ;
F_38 ( V_90 ) ;
F_82 ( V_12 ) ;
F_83 ( V_12 ) ;
}
void F_84 ( struct V_11 * V_12 )
{
struct V_17 V_18 ;
struct V_3 * V_4 ;
F_85 ( V_12 ) ;
F_86 ( V_12 ) ;
F_17 ( & V_18 , V_12 ,
V_26 | V_20 ) ;
while ( ( V_4 = F_18 ( & V_18 ) ) ) {
F_87 ( V_12 , V_4 -> V_8 ) ;
F_88 ( F_89 ( V_4 ) ) ;
F_90 ( V_12 , V_4 -> V_8 ) ;
}
F_21 ( & V_18 ) ;
F_87 ( V_12 , 0 ) ;
F_88 ( F_78 ( V_12 ) ) ;
F_91 ( V_12 , 0 ) ;
V_12 -> V_19 &= ~ V_92 ;
F_92 ( & F_56 ( V_12 ) -> V_73 , L_11 ) ;
if ( V_12 -> V_93 ) {
F_93 ( V_12 -> V_93 -> V_88 ) ;
F_94 ( V_12 ) ;
} else {
F_38 ( 1 ) ;
}
F_53 ( F_78 ( V_12 ) , V_12 -> V_58 ) ;
F_95 ( & V_12 -> V_9 , 0 ) ;
V_12 -> V_9 . V_95 = 0 ;
F_96 ( V_12 -> V_9 . V_83 ) ;
F_96 ( V_12 -> V_84 ) ;
if ( ! V_81 )
F_92 ( V_82 , F_97 ( F_56 ( V_12 ) ) ) ;
F_66 ( F_56 ( V_12 ) , false ) ;
F_65 ( F_56 ( V_12 ) ) ;
}
static T_4 F_98 ( struct V_74 * V_94 ,
struct V_96 * V_97 ,
char * V_98 )
{
struct V_11 * V_12 = F_99 ( V_94 ) ;
if ( ! V_12 -> V_99 )
return sprintf ( V_98 , L_12 ) ;
return F_100 ( V_12 -> V_99 , V_98 , 0 ) ;
}
static T_4 F_101 ( struct V_74 * V_94 ,
struct V_96 * V_97 ,
const char * V_98 , T_5 V_16 )
{
struct V_11 * V_12 = F_99 ( V_94 ) ;
if ( ! V_12 -> V_99 )
return - V_100 ;
return F_102 ( V_12 -> V_99 , V_98 , V_16 , 0 ) ;
}
struct V_11 * F_103 ( T_3 V_57 , int * V_8 )
{
struct V_11 * V_12 = NULL ;
if ( F_49 ( V_57 ) != V_65 ) {
struct V_71 * V_73 ;
V_73 = F_104 ( V_70 , V_57 , V_8 ) ;
if ( V_73 )
V_12 = F_99 ( F_105 ( V_73 ) ) ;
} else {
struct V_3 * V_4 ;
F_44 ( & V_60 ) ;
V_4 = F_106 ( & V_61 , F_39 ( F_51 ( V_57 ) ) ) ;
if ( V_4 && F_58 ( F_3 ( V_4 ) ) ) {
* V_8 = V_4 -> V_8 ;
V_12 = F_3 ( V_4 ) ;
}
F_46 ( & V_60 ) ;
}
return V_12 ;
}
struct V_77 * F_70 ( struct V_11 * V_12 , int V_8 )
{
struct V_3 * V_4 ;
struct V_77 * V_78 = NULL ;
V_4 = F_12 ( V_12 , V_8 ) ;
if ( V_4 )
V_78 = F_107 ( F_89 ( V_4 ) ) ;
F_19 ( V_4 ) ;
return V_78 ;
}
void T_6 F_108 ( void )
{
struct V_101 V_102 ;
struct V_74 * V_94 ;
F_109 ( & V_102 , & V_103 , NULL , & V_104 ) ;
while ( ( V_94 = F_110 ( & V_102 ) ) ) {
struct V_11 * V_12 = F_99 ( V_94 ) ;
struct V_17 V_18 ;
struct V_3 * V_4 ;
char V_105 [ V_106 ] ;
char V_107 [ V_68 ] ;
if ( F_69 ( V_12 ) == 0 ||
( V_12 -> V_19 & V_108 ) )
continue;
F_17 ( & V_18 , V_12 , V_22 ) ;
while ( ( V_4 = F_18 ( & V_18 ) ) ) {
bool V_109 = V_4 == & V_12 -> V_9 ;
F_32 ( L_13 , V_109 ? L_14 : L_15 ,
F_52 ( F_89 ( V_4 ) , V_107 ) ,
( unsigned long long ) F_20 ( V_4 ) >> 1
, V_80 ( V_12 , V_4 -> V_8 , V_105 ) ,
V_4 -> V_110 ? V_4 -> V_110 -> V_111 : L_14 ) ;
if ( V_109 ) {
if ( V_94 -> V_75 && V_94 -> V_75 -> V_112 )
F_32 ( L_16 ,
V_94 -> V_75 -> V_112 -> V_41 ) ;
else
F_32 ( L_17 ) ;
} else
F_32 ( L_12 ) ;
}
F_21 ( & V_18 ) ;
}
F_111 ( & V_102 ) ;
}
static void * F_112 ( struct V_33 * V_34 , T_7 * V_113 )
{
T_7 V_114 = * V_113 ;
struct V_101 * V_102 ;
struct V_74 * V_94 ;
V_102 = F_34 ( sizeof( * V_102 ) , V_50 ) ;
if ( ! V_102 )
return F_113 ( - V_51 ) ;
V_34 -> V_115 = V_102 ;
F_109 ( V_102 , & V_103 , NULL , & V_104 ) ;
do {
V_94 = F_110 ( V_102 ) ;
if ( ! V_94 )
return NULL ;
} while ( V_114 -- );
return F_99 ( V_94 ) ;
}
static void * F_114 ( struct V_33 * V_34 , void * V_116 , T_7 * V_113 )
{
struct V_74 * V_94 ;
( * V_113 ) ++ ;
V_94 = F_110 ( V_34 -> V_115 ) ;
if ( V_94 )
return F_99 ( V_94 ) ;
return NULL ;
}
static void F_115 ( struct V_33 * V_34 , void * V_116 )
{
struct V_101 * V_102 = V_34 -> V_115 ;
if ( V_102 ) {
F_111 ( V_102 ) ;
F_36 ( V_102 ) ;
V_34 -> V_115 = NULL ;
}
}
static void * F_116 ( struct V_33 * V_34 , T_7 * V_113 )
{
void * V_43 ;
V_43 = F_112 ( V_34 , V_113 ) ;
if ( ! F_117 ( V_43 ) && ! * V_113 )
F_118 ( V_34 , L_18 ) ;
return V_43 ;
}
static int F_119 ( struct V_33 * V_34 , void * V_116 )
{
struct V_11 * V_117 = V_116 ;
struct V_17 V_18 ;
struct V_3 * V_4 ;
char V_66 [ V_106 ] ;
if ( ! F_69 ( V_117 ) || ( ! F_120 ( V_117 ) &&
( V_117 -> V_19 & V_118 ) ) )
return 0 ;
if ( V_117 -> V_19 & V_108 )
return 0 ;
F_17 ( & V_18 , V_117 , V_22 ) ;
while ( ( V_4 = F_18 ( & V_18 ) ) )
F_28 ( V_34 , L_19 ,
F_49 ( F_89 ( V_4 ) ) , F_51 ( F_89 ( V_4 ) ) ,
( unsigned long long ) F_20 ( V_4 ) >> 1 ,
V_80 ( V_117 , V_4 -> V_8 , V_66 ) ) ;
F_21 ( & V_18 ) ;
return 0 ;
}
static int F_121 ( struct V_119 * V_119 , struct V_120 * V_120 )
{
return F_122 ( V_120 , & V_121 ) ;
}
static struct V_71 * F_123 ( T_3 V_57 , int * V_8 , void * V_72 )
{
if ( F_124 ( L_20 , F_49 ( V_57 ) , F_51 ( V_57 ) ) > 0 )
F_124 ( L_21 , F_49 ( V_57 ) ) ;
return NULL ;
}
static int T_6 F_125 ( void )
{
int error ;
V_103 . V_122 = V_123 ;
error = F_126 ( & V_103 ) ;
if ( F_11 ( error ) )
return error ;
V_70 = F_127 ( F_123 , & V_38 ) ;
F_128 () ;
F_30 ( V_65 , L_22 ) ;
if ( ! V_81 )
V_82 = F_67 ( L_23 , NULL ) ;
return 0 ;
}
static T_4 F_129 ( struct V_74 * V_94 ,
struct V_96 * V_97 , char * V_66 )
{
struct V_11 * V_12 = F_99 ( V_94 ) ;
return sprintf ( V_66 , L_24 , V_12 -> V_58 ) ;
}
static T_4 F_130 ( struct V_74 * V_94 ,
struct V_96 * V_97 , char * V_66 )
{
struct V_11 * V_12 = F_99 ( V_94 ) ;
return sprintf ( V_66 , L_24 , F_120 ( V_12 ) ) ;
}
static T_4 F_131 ( struct V_74 * V_94 ,
struct V_96 * V_97 , char * V_66 )
{
struct V_11 * V_12 = F_99 ( V_94 ) ;
return sprintf ( V_66 , L_24 ,
( V_12 -> V_19 & V_118 ? 1 : 0 ) ) ;
}
static T_4 F_132 ( struct V_74 * V_94 ,
struct V_96 * V_97 , char * V_66 )
{
struct V_11 * V_12 = F_99 ( V_94 ) ;
return sprintf ( V_66 , L_24 , F_133 ( V_12 ) ? 1 : 0 ) ;
}
static T_4 F_134 ( struct V_74 * V_94 ,
struct V_96 * V_97 , char * V_66 )
{
struct V_11 * V_12 = F_99 ( V_94 ) ;
return sprintf ( V_66 , L_25 , V_12 -> V_19 ) ;
}
static T_4 F_135 ( struct V_74 * V_94 ,
struct V_96 * V_97 ,
char * V_66 )
{
struct V_11 * V_12 = F_99 ( V_94 ) ;
return sprintf ( V_66 , L_24 , F_136 ( V_12 -> V_93 ) ) ;
}
static T_4 F_137 ( struct V_74 * V_94 ,
struct V_96 * V_97 ,
char * V_66 )
{
struct V_11 * V_12 = F_99 ( V_94 ) ;
return sprintf ( V_66 , L_24 , F_138 ( V_12 -> V_93 ) ) ;
}
static T_8 F_139 ( struct V_71 * V_73 , struct V_124 * V_125 , int V_42 )
{
struct V_74 * V_94 = F_140 ( V_73 , F_141 ( * V_94 ) , V_73 ) ;
struct V_11 * V_12 = F_99 ( V_94 ) ;
if ( V_125 == & V_126 . V_97 && ! V_12 -> V_99 )
return 0 ;
return V_125 -> V_127 ;
}
static void F_142 ( struct V_11 * V_12 ,
struct V_13 * V_128 )
{
struct V_13 * V_129 =
F_143 ( V_12 -> V_15 , 1 ) ;
F_24 ( V_12 -> V_15 , V_128 ) ;
if ( V_129 ) {
F_24 ( V_129 -> V_30 , NULL ) ;
F_144 ( V_129 , V_130 ) ;
}
}
int F_145 ( struct V_11 * V_12 , int V_8 )
{
struct V_13 * V_129 =
F_143 ( V_12 -> V_15 , 1 ) ;
struct V_13 * V_128 ;
int V_16 = V_129 ? V_129 -> V_16 : 0 ;
int V_29 , V_131 ;
T_5 V_132 ;
V_131 = V_8 + 1 ;
if ( V_131 < 0 )
return - V_49 ;
if ( F_120 ( V_12 ) && V_131 > F_120 ( V_12 ) )
return - V_49 ;
if ( V_131 <= V_16 )
return 0 ;
V_132 = sizeof( * V_128 ) + V_131 * sizeof( V_128 -> V_4 [ 0 ] ) ;
V_128 = F_146 ( V_132 , V_50 , V_12 -> V_133 ) ;
if ( ! V_128 )
return - V_51 ;
V_128 -> V_16 = V_131 ;
for ( V_29 = 0 ; V_29 < V_16 ; V_29 ++ )
F_24 ( V_128 -> V_4 [ V_29 ] , V_129 -> V_4 [ V_29 ] ) ;
F_142 ( V_12 , V_128 ) ;
return 0 ;
}
static void F_147 ( struct V_74 * V_94 )
{
struct V_11 * V_12 = F_99 ( V_94 ) ;
F_48 ( V_94 -> V_57 ) ;
F_148 ( V_12 ) ;
F_36 ( V_12 -> V_134 ) ;
F_142 ( V_12 , NULL ) ;
F_149 ( & V_12 -> V_9 ) ;
if ( V_12 -> V_93 )
F_150 ( V_12 -> V_93 ) ;
F_36 ( V_12 ) ;
}
static char * F_151 ( struct V_74 * V_94 , T_8 * V_127 ,
T_9 * V_135 , T_10 * V_136 )
{
struct V_11 * V_12 = F_99 ( V_94 ) ;
if ( V_12 -> V_137 )
return V_12 -> V_137 ( V_12 , V_127 ) ;
return NULL ;
}
static int F_152 ( struct V_33 * V_34 , void * V_116 )
{
struct V_11 * V_138 = V_116 ;
struct V_17 V_18 ;
struct V_3 * V_139 ;
char V_66 [ V_106 ] ;
unsigned int V_10 [ 2 ] ;
int V_140 ;
F_17 ( & V_18 , V_138 , V_23 ) ;
while ( ( V_139 = F_18 ( & V_18 ) ) ) {
V_140 = F_153 () ;
F_154 ( V_138 -> V_93 , V_140 , V_139 ) ;
F_155 () ;
F_6 ( V_138 -> V_93 , V_139 , V_10 ) ;
F_28 ( V_34 , L_26
L_27 ,
F_49 ( F_89 ( V_139 ) ) , F_51 ( F_89 ( V_139 ) ) ,
V_80 ( V_138 , V_139 -> V_8 , V_66 ) ,
F_156 ( V_139 , V_141 [ V_142 ] ) ,
F_156 ( V_139 , V_143 [ V_142 ] ) ,
F_156 ( V_139 , V_144 [ V_142 ] ) ,
F_157 ( F_156 ( V_139 , V_145 [ V_142 ] ) ) ,
F_156 ( V_139 , V_141 [ V_146 ] ) ,
F_156 ( V_139 , V_143 [ V_146 ] ) ,
F_156 ( V_139 , V_144 [ V_146 ] ) ,
F_157 ( F_156 ( V_139 , V_145 [ V_146 ] ) ) ,
V_10 [ 0 ] ,
F_157 ( F_156 ( V_139 , V_147 ) ) ,
F_157 ( F_156 ( V_139 , V_148 ) )
) ;
}
F_21 ( & V_18 ) ;
return 0 ;
}
static int F_158 ( struct V_119 * V_119 , struct V_120 * V_120 )
{
return F_122 ( V_120 , & V_149 ) ;
}
static int T_6 F_159 ( void )
{
F_160 ( L_28 , 0 , NULL , & V_150 ) ;
F_160 ( L_29 , 0 , NULL , & V_151 ) ;
return 0 ;
}
T_3 F_161 ( const char * V_41 , int V_8 )
{
T_3 V_57 = F_42 ( 0 , 0 ) ;
struct V_101 V_102 ;
struct V_74 * V_94 ;
F_109 ( & V_102 , & V_103 , NULL , & V_104 ) ;
while ( ( V_94 = F_110 ( & V_102 ) ) ) {
struct V_11 * V_12 = F_99 ( V_94 ) ;
struct V_3 * V_4 ;
if ( strcmp ( F_97 ( V_94 ) , V_41 ) )
continue;
if ( V_8 < V_12 -> V_58 ) {
V_57 = F_42 ( F_49 ( V_94 -> V_57 ) ,
F_51 ( V_94 -> V_57 ) + V_8 ) ;
break;
}
V_4 = F_12 ( V_12 , V_8 ) ;
if ( V_4 ) {
V_57 = F_89 ( V_4 ) ;
F_19 ( V_4 ) ;
break;
}
F_19 ( V_4 ) ;
}
F_111 ( & V_102 ) ;
return V_57 ;
}
struct V_11 * F_162 ( int V_58 )
{
return F_163 ( V_58 , V_152 ) ;
}
struct V_11 * F_163 ( int V_58 , int V_133 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 ;
if ( V_58 > V_153 ) {
F_32 ( V_154
L_30 ,
V_153 ) ;
V_58 = V_153 ;
}
V_12 = F_146 ( sizeof( struct V_11 ) , V_50 , V_133 ) ;
if ( V_12 ) {
if ( ! F_164 ( & V_12 -> V_9 ) ) {
F_36 ( V_12 ) ;
return NULL ;
}
V_12 -> V_133 = V_133 ;
if ( F_145 ( V_12 , 0 ) ) {
F_165 ( & V_12 -> V_9 ) ;
F_36 ( V_12 ) ;
return NULL ;
}
V_14 = F_143 ( V_12 -> V_15 , 1 ) ;
F_24 ( V_14 -> V_4 [ 0 ] , & V_12 -> V_9 ) ;
F_166 ( & V_12 -> V_9 . V_155 ) ;
if ( F_167 ( & V_12 -> V_9 ) ) {
F_149 ( & V_12 -> V_9 ) ;
F_36 ( V_12 ) ;
return NULL ;
}
V_12 -> V_58 = V_58 ;
F_168 ( V_12 ) ;
F_56 ( V_12 ) -> V_156 = & V_103 ;
F_56 ( V_12 ) -> type = & V_104 ;
F_169 ( F_56 ( V_12 ) ) ;
}
return V_12 ;
}
struct V_71 * F_58 ( struct V_11 * V_12 )
{
struct V_157 * V_158 ;
struct V_71 * V_73 ;
if ( ! V_12 -> V_159 )
return NULL ;
V_158 = V_12 -> V_159 -> V_158 ;
if ( V_158 && ! F_170 ( V_158 ) )
return NULL ;
V_73 = F_171 ( & F_56 ( V_12 ) -> V_73 ) ;
if ( V_73 == NULL ) {
F_172 ( V_158 ) ;
return NULL ;
}
return V_73 ;
}
void F_173 ( struct V_11 * V_12 )
{
if ( V_12 )
F_96 ( & F_56 ( V_12 ) -> V_73 ) ;
}
static void F_174 ( struct V_11 * V_160 , int V_161 )
{
char V_162 [] = L_31 ;
char * V_163 [] = { V_162 , NULL } ;
if ( ! V_161 )
V_162 [ 8 ] = '0' ;
F_175 ( & F_56 ( V_160 ) -> V_73 , V_164 , V_163 ) ;
}
void F_176 ( struct V_77 * V_78 , int V_165 )
{
V_78 -> V_166 -> V_167 = V_165 ;
}
void F_177 ( struct V_11 * V_12 , int V_165 )
{
struct V_17 V_18 ;
struct V_3 * V_4 ;
if ( V_12 -> V_9 . V_167 != V_165 ) {
F_174 ( V_12 , V_165 ) ;
V_12 -> V_9 . V_167 = V_165 ;
}
F_17 ( & V_18 , V_12 , V_26 ) ;
while ( ( V_4 = F_18 ( & V_18 ) ) )
V_4 -> V_167 = V_165 ;
F_21 ( & V_18 ) ;
}
int F_178 ( struct V_77 * V_78 )
{
if ( ! V_78 )
return 0 ;
return V_78 -> V_166 -> V_167 ;
}
int F_87 ( struct V_11 * V_12 , int V_8 )
{
int V_168 = 0 ;
struct V_77 * V_78 = F_70 ( V_12 , V_8 ) ;
if ( V_78 ) {
F_179 ( V_78 ) ;
V_168 = F_180 ( V_78 , true ) ;
F_181 ( V_78 ) ;
}
return V_168 ;
}
static unsigned long F_182 ( struct V_11 * V_12 )
{
struct V_169 * V_170 = V_12 -> V_170 ;
long V_171 = 0 ;
if ( V_170 -> V_172 >= 0 )
V_171 = V_170 -> V_172 ;
else if ( V_12 -> V_173 & ~ V_12 -> V_174 )
V_171 = V_175 ;
return F_183 ( V_171 ) ;
}
void F_184 ( struct V_11 * V_12 )
{
struct V_169 * V_170 = V_12 -> V_170 ;
unsigned long V_19 ;
bool V_176 ;
if ( ! V_170 )
return;
F_27 ( & V_170 -> V_177 ) ;
F_185 ( & V_170 -> V_178 , V_19 ) ;
V_176 = ! V_170 -> V_179 ++ ;
F_186 ( & V_170 -> V_178 , V_19 ) ;
if ( V_176 )
F_187 ( & V_12 -> V_170 -> V_180 ) ;
F_29 ( & V_170 -> V_177 ) ;
}
static void F_188 ( struct V_11 * V_12 , bool V_181 )
{
struct V_169 * V_170 = V_12 -> V_170 ;
unsigned long V_182 ;
unsigned long V_19 ;
F_185 ( & V_170 -> V_178 , V_19 ) ;
if ( F_80 ( V_170 -> V_179 <= 0 ) )
goto V_183;
if ( -- V_170 -> V_179 )
goto V_183;
V_182 = F_182 ( V_12 ) ;
if ( V_181 )
F_189 ( V_184 ,
& V_170 -> V_180 , 0 ) ;
else if ( V_182 )
F_189 ( V_184 ,
& V_170 -> V_180 , V_182 ) ;
V_183:
F_186 ( & V_170 -> V_178 , V_19 ) ;
}
void F_190 ( struct V_11 * V_12 )
{
if ( V_12 -> V_170 )
F_188 ( V_12 , false ) ;
}
void F_191 ( struct V_11 * V_12 , unsigned int V_185 )
{
struct V_169 * V_170 = V_12 -> V_170 ;
if ( ! V_170 )
return;
F_192 ( & V_170 -> V_178 ) ;
V_170 -> V_186 |= V_185 ;
if ( ! V_170 -> V_179 )
F_193 ( V_184 ,
& V_170 -> V_180 , 0 ) ;
F_194 ( & V_170 -> V_178 ) ;
}
unsigned int F_195 ( struct V_11 * V_12 , unsigned int V_185 )
{
const struct V_187 * V_188 = V_12 -> V_159 ;
struct V_169 * V_170 = V_12 -> V_170 ;
unsigned int V_189 ;
unsigned int V_186 = V_185 ;
if ( ! V_170 ) {
if ( ( V_185 & V_190 ) &&
V_188 -> V_191 && V_188 -> V_191 ( V_12 ) )
return V_190 ;
return 0 ;
}
F_184 ( V_12 ) ;
F_192 ( & V_170 -> V_178 ) ;
V_186 |= V_170 -> V_186 ;
V_170 -> V_186 = 0 ;
F_194 ( & V_170 -> V_178 ) ;
F_196 ( V_170 , & V_186 ) ;
F_188 ( V_12 , V_170 -> V_186 ? true : false ) ;
F_192 ( & V_170 -> V_178 ) ;
V_189 = V_170 -> V_189 & V_185 ;
V_170 -> V_189 &= ~ V_185 ;
F_194 ( & V_170 -> V_178 ) ;
F_80 ( V_186 & V_185 ) ;
return V_189 ;
}
static void F_197 ( struct V_192 * V_193 )
{
struct V_194 * V_180 = F_198 ( V_193 ) ;
struct V_169 * V_170 = F_140 ( V_180 , struct V_169 , V_180 ) ;
F_196 ( V_170 , & V_170 -> V_186 ) ;
}
static void F_196 ( struct V_169 * V_170 ,
unsigned int * V_195 )
{
struct V_11 * V_12 = V_170 -> V_12 ;
char * V_163 [ F_31 ( V_196 ) + 1 ] = { } ;
unsigned int V_186 = * V_195 ;
unsigned int V_173 ;
unsigned long V_182 ;
int V_197 = 0 , V_29 ;
V_173 = V_12 -> V_159 -> V_198 ( V_12 , V_186 ) ;
F_192 ( & V_170 -> V_178 ) ;
V_173 &= ~ V_170 -> V_189 ;
V_170 -> V_189 |= V_173 ;
* V_195 &= ~ V_186 ;
V_182 = F_182 ( V_12 ) ;
if ( ! V_170 -> V_179 && V_182 )
F_189 ( V_184 ,
& V_170 -> V_180 , V_182 ) ;
F_194 ( & V_170 -> V_178 ) ;
for ( V_29 = 0 ; V_29 < F_31 ( V_196 ) ; V_29 ++ )
if ( V_173 & V_12 -> V_173 & ( 1 << V_29 ) )
V_163 [ V_197 ++ ] = V_196 [ V_29 ] ;
if ( V_197 )
F_175 ( & F_56 ( V_12 ) -> V_73 , V_164 , V_163 ) ;
}
static T_4 F_199 ( unsigned int V_173 , char * V_66 )
{
const char * V_199 = L_14 ;
T_4 V_113 = 0 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < F_31 ( V_200 ) ; V_29 ++ )
if ( V_173 & ( 1 << V_29 ) ) {
V_113 += sprintf ( V_66 + V_113 , L_32 ,
V_199 , V_200 [ V_29 ] ) ;
V_199 = L_33 ;
}
if ( V_113 )
V_113 += sprintf ( V_66 + V_113 , L_12 ) ;
return V_113 ;
}
static T_4 F_200 ( struct V_74 * V_94 ,
struct V_96 * V_97 , char * V_66 )
{
struct V_11 * V_12 = F_99 ( V_94 ) ;
return F_199 ( V_12 -> V_173 , V_66 ) ;
}
static T_4 F_201 ( struct V_74 * V_94 ,
struct V_96 * V_97 , char * V_66 )
{
struct V_11 * V_12 = F_99 ( V_94 ) ;
return F_199 ( V_12 -> V_174 , V_66 ) ;
}
static T_4 F_202 ( struct V_74 * V_94 ,
struct V_96 * V_97 ,
char * V_66 )
{
struct V_11 * V_12 = F_99 ( V_94 ) ;
return sprintf ( V_66 , L_34 , V_12 -> V_170 -> V_172 ) ;
}
static T_4 F_203 ( struct V_74 * V_94 ,
struct V_96 * V_97 ,
const char * V_66 , T_5 V_201 )
{
struct V_11 * V_12 = F_99 ( V_94 ) ;
long V_182 ;
if ( ! V_201 || ! sscanf ( V_66 , L_35 , & V_182 ) )
return - V_49 ;
if ( V_182 < 0 && V_182 != - 1 )
return - V_49 ;
F_184 ( V_12 ) ;
V_12 -> V_170 -> V_172 = V_182 ;
F_188 ( V_12 , true ) ;
return V_201 ;
}
static int F_204 ( const char * V_202 ,
const struct V_203 * V_204 )
{
struct V_169 * V_170 ;
int V_45 ;
V_45 = F_205 ( V_202 , V_204 ) ;
if ( V_45 < 0 )
return V_45 ;
F_27 ( & V_205 ) ;
F_206 (ev, &disk_events, node)
F_191 ( V_170 -> V_12 , 0 ) ;
F_29 ( & V_205 ) ;
return 0 ;
}
static void F_75 ( struct V_11 * V_12 )
{
struct V_169 * V_170 ;
if ( ! V_12 -> V_159 -> V_198 )
return;
V_170 = F_207 ( sizeof( * V_170 ) , V_50 ) ;
if ( ! V_170 ) {
F_208 ( L_36 , V_12 -> V_80 ) ;
return;
}
F_209 ( & V_170 -> V_206 ) ;
V_170 -> V_12 = V_12 ;
F_210 ( & V_170 -> V_178 ) ;
F_211 ( & V_170 -> V_177 ) ;
V_170 -> V_179 = 1 ;
V_170 -> V_172 = - 1 ;
F_212 ( & V_170 -> V_180 , F_197 ) ;
V_12 -> V_170 = V_170 ;
}
static void F_82 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_170 )
return;
if ( F_213 ( & F_56 ( V_12 ) -> V_73 , V_207 ) < 0 )
F_208 ( L_37 ,
V_12 -> V_80 ) ;
F_27 ( & V_205 ) ;
F_214 ( & V_12 -> V_170 -> V_206 , & V_169 ) ;
F_29 ( & V_205 ) ;
F_188 ( V_12 , true ) ;
}
static void F_86 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_170 )
return;
F_184 ( V_12 ) ;
F_27 ( & V_205 ) ;
F_215 ( & V_12 -> V_170 -> V_206 ) ;
F_29 ( & V_205 ) ;
F_216 ( & F_56 ( V_12 ) -> V_73 , V_207 ) ;
}
static void F_148 ( struct V_11 * V_12 )
{
F_80 ( V_12 -> V_170 && V_12 -> V_170 -> V_179 != 1 ) ;
F_36 ( V_12 -> V_170 ) ;
}
