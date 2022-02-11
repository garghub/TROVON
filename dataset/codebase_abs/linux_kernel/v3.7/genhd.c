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
int V_14 , V_50 ;
if ( V_5 -> V_4 < V_3 -> V_51 ) {
* V_49 = F_34 ( V_3 -> V_25 , V_3 -> V_52 + V_5 -> V_4 ) ;
return 0 ;
}
do {
if ( ! F_35 ( & V_53 , V_42 ) )
return - V_43 ;
V_50 = F_36 ( & V_53 , V_5 , & V_14 ) ;
} while ( V_50 == - V_54 );
if ( V_50 )
return V_50 ;
if ( V_14 > V_55 ) {
F_37 ( & V_53 , V_14 ) ;
return - V_40 ;
}
* V_49 = F_34 ( V_56 , F_30 ( V_14 ) ) ;
return 0 ;
}
void F_38 ( T_3 V_49 )
{
F_39 () ;
if ( V_49 == F_34 ( 0 , 0 ) )
return;
if ( F_40 ( V_49 ) == V_56 ) {
F_19 ( & V_57 ) ;
F_37 ( & V_53 , F_30 ( F_41 ( V_49 ) ) ) ;
F_21 ( & V_57 ) ;
}
}
static char * F_42 ( T_3 V_49 , char * V_58 )
{
if ( F_40 ( V_49 ) <= 0xff && F_41 ( V_49 ) <= 0xff ) {
char V_59 [ V_60 ] ;
snprintf ( V_59 , V_60 , L_4 , F_40 ( V_49 ) , F_41 ( V_49 ) ) ;
snprintf ( V_58 , V_60 , L_5 , V_59 ) ;
} else
snprintf ( V_58 , V_60 , L_6 , F_40 ( V_49 ) , F_41 ( V_49 ) ) ;
return V_58 ;
}
void F_43 ( T_3 V_49 , unsigned long V_61 )
{
F_44 ( V_62 , V_49 , V_61 ) ;
}
static struct V_63 * F_45 ( T_3 V_49 , int * V_4 , void * V_64 )
{
struct V_2 * V_37 = V_64 ;
return & F_46 ( V_37 ) -> V_65 ;
}
static int F_47 ( T_3 V_49 , void * V_64 )
{
struct V_2 * V_37 = V_64 ;
if ( ! F_48 ( V_37 ) )
return - 1 ;
return 0 ;
}
static void F_49 ( struct V_2 * V_3 )
{
struct V_66 * V_67 = F_46 ( V_3 ) ;
struct V_68 * V_69 ;
struct V_10 V_11 ;
struct V_1 * V_5 ;
int V_70 ;
V_67 -> V_71 = V_3 -> V_72 ;
F_50 ( V_67 , V_3 -> V_73 ) ;
F_51 ( V_67 , 1 ) ;
if ( F_52 ( V_67 ) )
return;
if ( ! V_74 ) {
V_70 = F_53 ( V_75 , & V_67 -> V_65 ,
F_54 ( & V_67 -> V_65 ) ) ;
if ( V_70 ) {
F_55 ( V_67 ) ;
return;
}
}
V_3 -> V_24 . V_76 = F_56 ( L_7 , & V_67 -> V_65 ) ;
V_3 -> V_77 = F_56 ( L_8 , & V_67 -> V_65 ) ;
if ( ! F_57 ( V_3 ) )
goto exit;
if ( ! F_58 ( V_3 ) )
goto exit;
V_69 = F_59 ( V_3 , 0 ) ;
if ( ! V_69 )
goto exit;
V_69 -> V_78 = 1 ;
V_70 = F_60 ( V_69 , V_79 , NULL ) ;
if ( V_70 < 0 )
goto exit;
F_61 ( V_69 , V_79 ) ;
exit:
F_51 ( V_67 , 0 ) ;
F_62 ( & V_67 -> V_65 , V_80 ) ;
F_9 ( & V_11 , V_3 , 0 ) ;
while ( ( V_5 = F_10 ( & V_11 ) ) )
F_62 ( & F_7 ( V_5 ) -> V_65 , V_80 ) ;
F_13 ( & V_11 ) ;
}
void F_63 ( struct V_2 * V_3 )
{
struct V_81 * V_82 ;
T_3 V_49 ;
int V_83 ;
F_29 ( V_3 -> V_51 && ! ( V_3 -> V_25 || V_3 -> V_52 ) ) ;
F_29 ( ! V_3 -> V_51 && ! ( V_3 -> V_12 & V_84 ) ) ;
V_3 -> V_12 |= V_85 ;
V_83 = F_32 ( & V_3 -> V_24 , & V_49 ) ;
if ( V_83 ) {
F_29 ( 1 ) ;
return;
}
F_46 ( V_3 ) -> V_49 = V_49 ;
V_3 -> V_25 = F_40 ( V_49 ) ;
V_3 -> V_52 = F_41 ( V_49 ) ;
F_64 ( V_3 ) ;
V_82 = & V_3 -> V_86 -> V_81 ;
F_65 ( V_82 , F_66 ( V_3 ) ) ;
F_67 ( F_66 ( V_3 ) , V_3 -> V_51 , NULL ,
F_45 , F_47 , V_3 ) ;
F_49 ( V_3 ) ;
F_68 ( V_3 ) ;
F_69 ( ! F_70 ( V_3 -> V_86 ) ) ;
V_83 = F_53 ( & F_46 ( V_3 ) -> V_65 , & V_82 -> V_87 -> V_65 ,
L_9 ) ;
F_29 ( V_83 ) ;
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
F_38 ( F_46 ( V_3 ) -> V_49 ) ;
F_76 ( V_3 , 0 ) ;
V_3 -> V_12 &= ~ V_85 ;
F_77 ( & F_46 ( V_3 ) -> V_65 , L_9 ) ;
F_78 ( & V_3 -> V_86 -> V_81 ) ;
F_79 ( V_3 ) ;
F_43 ( F_66 ( V_3 ) , V_3 -> V_51 ) ;
F_80 ( & V_3 -> V_24 , 0 ) ;
V_3 -> V_24 . V_88 = 0 ;
F_81 ( V_3 -> V_24 . V_76 ) ;
F_81 ( V_3 -> V_77 ) ;
V_3 -> V_72 = NULL ;
if ( ! V_74 )
F_77 ( V_75 , F_82 ( F_46 ( V_3 ) ) ) ;
F_55 ( F_46 ( V_3 ) ) ;
}
struct V_2 * F_83 ( T_3 V_49 , int * V_4 )
{
struct V_2 * V_3 = NULL ;
if ( F_40 ( V_49 ) != V_56 ) {
struct V_63 * V_65 ;
V_65 = F_84 ( V_62 , V_49 , V_4 ) ;
if ( V_65 )
V_3 = F_85 ( F_86 ( V_65 ) ) ;
} else {
struct V_1 * V_5 ;
F_19 ( & V_57 ) ;
V_5 = F_87 ( & V_53 , F_30 ( F_41 ( V_49 ) ) ) ;
if ( V_5 && F_48 ( F_33 ( V_5 ) ) ) {
* V_4 = V_5 -> V_4 ;
V_3 = F_33 ( V_5 ) ;
}
F_21 ( & V_57 ) ;
}
return V_3 ;
}
struct V_68 * F_59 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 ;
struct V_68 * V_69 = NULL ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 )
V_69 = F_88 ( F_89 ( V_5 ) ) ;
F_11 ( V_5 ) ;
return V_69 ;
}
void T_4 F_90 ( void )
{
struct V_89 V_90 ;
struct V_66 * V_87 ;
F_91 ( & V_90 , & V_91 , NULL , & V_92 ) ;
while ( ( V_87 = F_92 ( & V_90 ) ) ) {
struct V_2 * V_3 = F_85 ( V_87 ) ;
struct V_10 V_11 ;
struct V_1 * V_5 ;
char V_93 [ V_94 ] ;
char V_95 [ V_60 ] ;
char V_96 [ V_97 * 2 + 5 ] ;
if ( F_58 ( V_3 ) == 0 ||
( V_3 -> V_12 & V_98 ) )
continue;
F_9 ( & V_11 , V_3 , V_15 ) ;
while ( ( V_5 = F_10 ( & V_11 ) ) ) {
bool V_99 = V_5 == & V_3 -> V_24 ;
V_96 [ 0 ] = '\0' ;
if ( V_5 -> V_100 )
snprintf ( V_96 , sizeof( V_96 ) , L_10 ,
V_5 -> V_100 -> V_101 ) ;
F_24 ( L_11 , V_99 ? L_12 : L_13 ,
F_42 ( F_89 ( V_5 ) , V_95 ) ,
( unsigned long long ) F_12 ( V_5 ) >> 1
, V_73 ( V_3 , V_5 -> V_4 , V_93 ) ,
V_96 ) ;
if ( V_99 ) {
if ( V_3 -> V_72 != NULL &&
V_3 -> V_72 -> V_102 != NULL )
F_24 ( L_14 ,
V_3 -> V_72 -> V_102 -> V_35 ) ;
else
F_24 ( L_15 ) ;
} else
F_24 ( L_16 ) ;
}
F_13 ( & V_11 ) ;
}
F_93 ( & V_90 ) ;
}
static void * F_94 ( struct V_27 * V_28 , T_5 * V_103 )
{
T_5 V_104 = * V_103 ;
struct V_89 * V_90 ;
struct V_66 * V_87 ;
V_90 = F_25 ( sizeof( * V_90 ) , V_42 ) ;
if ( ! V_90 )
return F_95 ( - V_43 ) ;
V_28 -> V_105 = V_90 ;
F_91 ( V_90 , & V_91 , NULL , & V_92 ) ;
do {
V_87 = F_92 ( V_90 ) ;
if ( ! V_87 )
return NULL ;
} while ( V_104 -- );
return F_85 ( V_87 ) ;
}
static void * F_96 ( struct V_27 * V_28 , void * V_106 , T_5 * V_103 )
{
struct V_66 * V_87 ;
( * V_103 ) ++ ;
V_87 = F_92 ( V_28 -> V_105 ) ;
if ( V_87 )
return F_85 ( V_87 ) ;
return NULL ;
}
static void F_97 ( struct V_27 * V_28 , void * V_106 )
{
struct V_89 * V_90 = V_28 -> V_105 ;
if ( V_90 ) {
F_93 ( V_90 ) ;
F_27 ( V_90 ) ;
}
}
static void * F_98 ( struct V_27 * V_28 , T_5 * V_103 )
{
void * V_37 ;
V_37 = F_94 ( V_28 , V_103 ) ;
if ( ! F_99 ( V_37 ) && ! * V_103 )
F_100 ( V_28 , L_17 ) ;
return V_37 ;
}
static int F_101 ( struct V_27 * V_28 , void * V_106 )
{
struct V_2 * V_107 = V_106 ;
struct V_10 V_11 ;
struct V_1 * V_5 ;
char V_58 [ V_94 ] ;
if ( ! F_58 ( V_107 ) || ( ! F_102 ( V_107 ) &&
( V_107 -> V_12 & V_108 ) ) )
return 0 ;
if ( V_107 -> V_12 & V_98 )
return 0 ;
F_9 ( & V_11 , V_107 , V_15 ) ;
while ( ( V_5 = F_10 ( & V_11 ) ) )
F_20 ( V_28 , L_18 ,
F_40 ( F_89 ( V_5 ) ) , F_41 ( F_89 ( V_5 ) ) ,
( unsigned long long ) F_12 ( V_5 ) >> 1 ,
V_73 ( V_107 , V_5 -> V_4 , V_58 ) ) ;
F_13 ( & V_11 ) ;
return 0 ;
}
static int F_103 ( struct V_109 * V_109 , struct V_110 * V_110 )
{
return F_104 ( V_110 , & V_111 ) ;
}
static struct V_63 * F_105 ( T_3 V_49 , int * V_4 , void * V_64 )
{
if ( F_106 ( L_19 , F_40 ( V_49 ) , F_41 ( V_49 ) ) > 0 )
F_106 ( L_20 , F_40 ( V_49 ) ) ;
return NULL ;
}
static int T_4 F_107 ( void )
{
int error ;
V_91 . V_112 = V_113 ;
error = F_108 ( & V_91 ) ;
if ( F_2 ( error ) )
return error ;
V_62 = F_109 ( F_105 , & V_32 ) ;
F_110 () ;
F_22 ( V_56 , L_21 ) ;
if ( ! V_74 )
V_75 = F_56 ( L_22 , NULL ) ;
return 0 ;
}
static T_6 F_111 ( struct V_66 * V_87 ,
struct V_114 * V_115 , char * V_58 )
{
struct V_2 * V_3 = F_85 ( V_87 ) ;
return sprintf ( V_58 , L_23 , V_3 -> V_51 ) ;
}
static T_6 F_112 ( struct V_66 * V_87 ,
struct V_114 * V_115 , char * V_58 )
{
struct V_2 * V_3 = F_85 ( V_87 ) ;
return sprintf ( V_58 , L_23 , F_102 ( V_3 ) ) ;
}
static T_6 F_113 ( struct V_66 * V_87 ,
struct V_114 * V_115 , char * V_58 )
{
struct V_2 * V_3 = F_85 ( V_87 ) ;
return sprintf ( V_58 , L_23 ,
( V_3 -> V_12 & V_108 ? 1 : 0 ) ) ;
}
static T_6 F_114 ( struct V_66 * V_87 ,
struct V_114 * V_115 , char * V_58 )
{
struct V_2 * V_3 = F_85 ( V_87 ) ;
return sprintf ( V_58 , L_23 , F_115 ( V_3 ) ? 1 : 0 ) ;
}
static T_6 F_116 ( struct V_66 * V_87 ,
struct V_114 * V_115 , char * V_58 )
{
struct V_2 * V_3 = F_85 ( V_87 ) ;
return sprintf ( V_58 , L_24 , V_3 -> V_12 ) ;
}
static T_6 F_117 ( struct V_66 * V_87 ,
struct V_114 * V_115 ,
char * V_58 )
{
struct V_2 * V_3 = F_85 ( V_87 ) ;
return sprintf ( V_58 , L_23 , F_118 ( V_3 -> V_86 ) ) ;
}
static T_6 F_119 ( struct V_66 * V_87 ,
struct V_114 * V_115 ,
char * V_58 )
{
struct V_2 * V_3 = F_85 ( V_87 ) ;
return sprintf ( V_58 , L_23 , F_120 ( V_3 -> V_86 ) ) ;
}
static void F_121 ( struct V_2 * V_3 ,
struct V_6 * V_116 )
{
struct V_6 * V_117 = V_3 -> V_8 ;
F_16 ( V_3 -> V_8 , V_116 ) ;
if ( V_117 ) {
F_16 ( V_117 -> V_23 , NULL ) ;
F_122 ( V_117 , V_118 ) ;
}
}
int F_123 ( struct V_2 * V_3 , int V_4 )
{
struct V_6 * V_117 = V_3 -> V_8 ;
struct V_6 * V_116 ;
int V_9 = V_117 ? V_117 -> V_9 : 0 ;
int V_119 = V_4 + 1 ;
T_7 V_120 ;
int V_22 ;
if ( F_102 ( V_3 ) && V_119 > F_102 ( V_3 ) )
return - V_121 ;
if ( V_119 <= V_9 )
return 0 ;
V_120 = sizeof( * V_116 ) + V_119 * sizeof( V_116 -> V_5 [ 0 ] ) ;
V_116 = F_124 ( V_120 , V_42 , V_3 -> V_122 ) ;
if ( ! V_116 )
return - V_43 ;
V_116 -> V_9 = V_119 ;
for ( V_22 = 0 ; V_22 < V_9 ; V_22 ++ )
F_16 ( V_116 -> V_5 [ V_22 ] , V_117 -> V_5 [ V_22 ] ) ;
F_121 ( V_3 , V_116 ) ;
return 0 ;
}
static void F_125 ( struct V_66 * V_87 )
{
struct V_2 * V_3 = F_85 ( V_87 ) ;
F_126 ( V_3 ) ;
F_27 ( V_3 -> V_123 ) ;
F_121 ( V_3 , NULL ) ;
F_127 ( & V_3 -> V_24 ) ;
F_128 ( & V_3 -> V_24 ) ;
if ( V_3 -> V_86 )
F_129 ( V_3 -> V_86 ) ;
F_27 ( V_3 ) ;
}
static char * F_130 ( struct V_66 * V_87 , T_8 * V_124 )
{
struct V_2 * V_3 = F_85 ( V_87 ) ;
if ( V_3 -> V_125 )
return V_3 -> V_125 ( V_3 , V_124 ) ;
return NULL ;
}
static int F_131 ( struct V_27 * V_28 , void * V_106 )
{
struct V_2 * V_126 = V_106 ;
struct V_10 V_11 ;
struct V_1 * V_127 ;
char V_58 [ V_94 ] ;
int V_128 ;
F_9 ( & V_11 , V_126 , V_16 ) ;
while ( ( V_127 = F_10 ( & V_11 ) ) ) {
V_128 = F_132 () ;
F_133 ( V_128 , V_127 ) ;
F_134 () ;
F_20 ( V_28 , L_25
L_26 ,
F_40 ( F_89 ( V_127 ) ) , F_41 ( F_89 ( V_127 ) ) ,
V_73 ( V_126 , V_127 -> V_4 , V_58 ) ,
F_135 ( V_127 , V_129 [ V_130 ] ) ,
F_135 ( V_127 , V_131 [ V_130 ] ) ,
F_135 ( V_127 , V_132 [ V_130 ] ) ,
F_136 ( F_135 ( V_127 , V_133 [ V_130 ] ) ) ,
F_135 ( V_127 , V_129 [ V_134 ] ) ,
F_135 ( V_127 , V_131 [ V_134 ] ) ,
F_135 ( V_127 , V_132 [ V_134 ] ) ,
F_136 ( F_135 ( V_127 , V_133 [ V_134 ] ) ) ,
F_137 ( V_127 ) ,
F_136 ( F_135 ( V_127 , V_135 ) ) ,
F_136 ( F_135 ( V_127 , V_136 ) )
) ;
}
F_13 ( & V_11 ) ;
return 0 ;
}
static int F_138 ( struct V_109 * V_109 , struct V_110 * V_110 )
{
return F_104 ( V_110 , & V_137 ) ;
}
static int T_4 F_139 ( void )
{
F_140 ( L_27 , 0 , NULL , & V_138 ) ;
F_140 ( L_28 , 0 , NULL , & V_139 ) ;
return 0 ;
}
T_3 F_141 ( const char * V_35 , int V_4 )
{
T_3 V_49 = F_34 ( 0 , 0 ) ;
struct V_89 V_90 ;
struct V_66 * V_87 ;
F_91 ( & V_90 , & V_91 , NULL , & V_92 ) ;
while ( ( V_87 = F_92 ( & V_90 ) ) ) {
struct V_2 * V_3 = F_85 ( V_87 ) ;
struct V_1 * V_5 ;
if ( strcmp ( F_82 ( V_87 ) , V_35 ) )
continue;
if ( V_4 < V_3 -> V_51 ) {
V_49 = F_34 ( F_40 ( V_87 -> V_49 ) ,
F_41 ( V_87 -> V_49 ) + V_4 ) ;
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
F_93 ( & V_90 ) ;
return V_49 ;
}
struct V_2 * F_142 ( int V_51 )
{
return F_143 ( V_51 , - 1 ) ;
}
struct V_2 * F_143 ( int V_51 , int V_122 )
{
struct V_2 * V_3 ;
V_3 = F_144 ( sizeof( struct V_2 ) ,
V_42 | V_140 , V_122 ) ;
if ( V_3 ) {
if ( ! F_145 ( & V_3 -> V_24 ) ) {
F_27 ( V_3 ) ;
return NULL ;
}
V_3 -> V_122 = V_122 ;
if ( F_123 ( V_3 , 0 ) ) {
F_127 ( & V_3 -> V_24 ) ;
F_27 ( V_3 ) ;
return NULL ;
}
V_3 -> V_8 -> V_5 [ 0 ] = & V_3 -> V_24 ;
F_146 ( & V_3 -> V_24 . V_141 ) ;
F_147 ( & V_3 -> V_24 ) ;
V_3 -> V_51 = V_51 ;
F_148 ( V_3 ) ;
F_46 ( V_3 ) -> V_142 = & V_91 ;
F_46 ( V_3 ) -> type = & V_92 ;
F_149 ( F_46 ( V_3 ) ) ;
}
return V_3 ;
}
struct V_63 * F_48 ( struct V_2 * V_3 )
{
struct V_143 * V_144 ;
struct V_63 * V_65 ;
if ( ! V_3 -> V_145 )
return NULL ;
V_144 = V_3 -> V_145 -> V_144 ;
if ( V_144 && ! F_150 ( V_144 ) )
return NULL ;
V_65 = F_151 ( & F_46 ( V_3 ) -> V_65 ) ;
if ( V_65 == NULL ) {
F_152 ( V_144 ) ;
return NULL ;
}
return V_65 ;
}
void F_153 ( struct V_2 * V_3 )
{
if ( V_3 )
F_81 ( & F_46 ( V_3 ) -> V_65 ) ;
}
static void F_154 ( struct V_2 * V_146 , int V_147 )
{
char V_148 [] = L_29 ;
char * V_149 [] = { V_148 , NULL } ;
if ( ! V_147 )
V_148 [ 8 ] = '0' ;
F_155 ( & F_46 ( V_146 ) -> V_65 , V_150 , V_149 ) ;
}
void F_156 ( struct V_68 * V_69 , int V_151 )
{
V_69 -> V_152 -> V_153 = V_151 ;
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
int F_158 ( struct V_68 * V_69 )
{
if ( ! V_69 )
return 0 ;
return V_69 -> V_152 -> V_153 ;
}
int F_74 ( struct V_2 * V_3 , int V_4 )
{
int V_154 = 0 ;
struct V_68 * V_69 = F_59 ( V_3 , V_4 ) ;
if ( V_69 ) {
F_159 ( V_69 ) ;
V_154 = F_160 ( V_69 , true ) ;
F_161 ( V_69 ) ;
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
if ( ! V_156 ) {
if ( ( V_172 & V_177 ) &&
V_175 -> V_178 && V_175 -> V_178 ( V_3 ) )
return V_177 ;
return 0 ;
}
F_173 ( & V_156 -> V_164 ) ;
V_156 -> V_173 |= V_172 ;
F_175 ( & V_156 -> V_164 ) ;
F_164 ( V_3 ) ;
F_170 ( V_171 , & V_156 -> V_166 , 0 ) ;
F_177 ( & V_156 -> V_166 ) ;
F_168 ( V_3 , false ) ;
F_173 ( & V_156 -> V_164 ) ;
F_69 ( V_156 -> V_173 & V_172 ) ;
V_176 = V_156 -> V_176 & V_172 ;
V_156 -> V_176 &= ~ V_172 ;
F_175 ( & V_156 -> V_164 ) ;
return V_176 ;
}
static void F_178 ( struct V_179 * V_180 )
{
struct V_181 * V_166 = F_179 ( V_180 ) ;
struct V_155 * V_156 = F_180 ( V_166 , struct V_155 , V_166 ) ;
struct V_2 * V_3 = V_156 -> V_3 ;
char * V_149 [ F_23 ( V_182 ) + 1 ] = { } ;
unsigned int V_173 = V_156 -> V_173 ;
unsigned int V_159 ;
unsigned long V_168 ;
int V_183 = 0 , V_22 ;
V_159 = V_3 -> V_145 -> V_184 ( V_3 , V_173 ) ;
F_173 ( & V_156 -> V_164 ) ;
V_159 &= ~ V_156 -> V_176 ;
V_156 -> V_176 |= V_159 ;
V_156 -> V_173 &= ~ V_173 ;
V_168 = F_162 ( V_3 ) ;
if ( ! V_156 -> V_165 && V_168 )
F_170 ( V_171 , & V_156 -> V_166 , V_168 ) ;
F_175 ( & V_156 -> V_164 ) ;
for ( V_22 = 0 ; V_22 < F_23 ( V_182 ) ; V_22 ++ )
if ( V_159 & V_3 -> V_159 & ( 1 << V_22 ) )
V_149 [ V_183 ++ ] = V_182 [ V_22 ] ;
if ( V_183 )
F_155 ( & F_46 ( V_3 ) -> V_65 , V_150 , V_149 ) ;
}
static T_6 F_181 ( unsigned int V_159 , char * V_58 )
{
const char * V_185 = L_12 ;
T_6 V_103 = 0 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < F_23 ( V_186 ) ; V_22 ++ )
if ( V_159 & ( 1 << V_22 ) ) {
V_103 += sprintf ( V_58 + V_103 , L_30 ,
V_185 , V_186 [ V_22 ] ) ;
V_185 = L_31 ;
}
if ( V_103 )
V_103 += sprintf ( V_58 + V_103 , L_16 ) ;
return V_103 ;
}
static T_6 F_182 ( struct V_66 * V_87 ,
struct V_114 * V_115 , char * V_58 )
{
struct V_2 * V_3 = F_85 ( V_87 ) ;
return F_181 ( V_3 -> V_159 , V_58 ) ;
}
static T_6 F_183 ( struct V_66 * V_87 ,
struct V_114 * V_115 , char * V_58 )
{
struct V_2 * V_3 = F_85 ( V_87 ) ;
return F_181 ( V_3 -> V_160 , V_58 ) ;
}
static T_6 F_184 ( struct V_66 * V_87 ,
struct V_114 * V_115 ,
char * V_58 )
{
struct V_2 * V_3 = F_85 ( V_87 ) ;
return sprintf ( V_58 , L_32 , V_3 -> V_156 -> V_158 ) ;
}
static T_6 F_185 ( struct V_66 * V_87 ,
struct V_114 * V_115 ,
const char * V_58 , T_7 V_187 )
{
struct V_2 * V_3 = F_85 ( V_87 ) ;
long V_168 ;
if ( ! V_187 || ! sscanf ( V_58 , L_33 , & V_168 ) )
return - V_121 ;
if ( V_168 < 0 && V_168 != - 1 )
return - V_121 ;
F_164 ( V_3 ) ;
V_3 -> V_156 -> V_158 = V_168 ;
F_168 ( V_3 , true ) ;
return V_187 ;
}
static int F_186 ( const char * V_188 ,
const struct V_189 * V_190 )
{
struct V_155 * V_156 ;
int V_39 ;
V_39 = F_187 ( V_188 , V_190 ) ;
if ( V_39 < 0 )
return V_39 ;
F_19 ( & V_191 ) ;
F_188 (ev, &disk_events, node)
F_172 ( V_156 -> V_3 , 0 ) ;
F_21 ( & V_191 ) ;
return 0 ;
}
static void F_64 ( struct V_2 * V_3 )
{
struct V_155 * V_156 ;
if ( ! V_3 -> V_145 -> V_184 )
return;
V_156 = F_189 ( sizeof( * V_156 ) , V_42 ) ;
if ( ! V_156 ) {
F_190 ( L_34 , V_3 -> V_73 ) ;
return;
}
F_191 ( & V_156 -> V_192 ) ;
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
if ( F_195 ( & F_46 ( V_3 ) -> V_65 , V_193 ) < 0 )
F_190 ( L_35 ,
V_3 -> V_73 ) ;
F_19 ( & V_191 ) ;
F_196 ( & V_3 -> V_156 -> V_192 , & V_155 ) ;
F_21 ( & V_191 ) ;
F_168 ( V_3 , true ) ;
}
static void F_73 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_156 )
return;
F_164 ( V_3 ) ;
F_19 ( & V_191 ) ;
F_197 ( & V_3 -> V_156 -> V_192 ) ;
F_21 ( & V_191 ) ;
F_198 ( & F_46 ( V_3 ) -> V_65 , V_193 ) ;
}
static void F_126 ( struct V_2 * V_3 )
{
F_69 ( V_3 -> V_156 && V_3 -> V_156 -> V_165 != 1 ) ;
F_27 ( V_3 -> V_156 ) ;
}
