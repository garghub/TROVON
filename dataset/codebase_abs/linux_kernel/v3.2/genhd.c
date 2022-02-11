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
if ( ! V_5 -> V_19 &&
! ( V_11 -> V_12 & V_20 ) &&
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
void F_12 ( struct V_10 * V_11 )
{
F_11 ( V_11 -> V_5 ) ;
V_11 -> V_5 = NULL ;
}
static inline int F_13 ( struct V_1 * V_5 , T_1 V_21 )
{
return V_5 -> V_22 <= V_21 &&
V_21 < V_5 -> V_22 + V_5 -> V_19 ;
}
struct V_1 * F_14 ( struct V_2 * V_3 , T_1 V_21 )
{
struct V_6 * V_7 ;
struct V_1 * V_5 ;
int V_23 ;
V_7 = F_4 ( V_3 -> V_8 ) ;
V_5 = F_4 ( V_7 -> V_24 ) ;
if ( V_5 && F_13 ( V_5 , V_21 ) )
return V_5 ;
for ( V_23 = 1 ; V_23 < V_7 -> V_9 ; V_23 ++ ) {
V_5 = F_4 ( V_7 -> V_5 [ V_23 ] ) ;
if ( V_5 && F_13 ( V_5 , V_21 ) ) {
F_15 ( V_7 -> V_24 , V_5 ) ;
return V_5 ;
}
}
return & V_3 -> V_25 ;
}
static inline int F_16 ( unsigned V_26 )
{
return V_26 % V_27 ;
}
void F_17 ( struct V_28 * V_29 , T_2 V_30 )
{
struct V_31 * V_32 ;
if ( V_30 < V_27 ) {
F_18 ( & V_33 ) ;
for ( V_32 = V_34 [ V_30 ] ; V_32 ; V_32 = V_32 -> V_35 )
F_19 ( V_29 , L_1 , V_32 -> V_26 , V_32 -> V_36 ) ;
F_20 ( & V_33 ) ;
}
}
int F_21 ( unsigned int V_26 , const char * V_36 )
{
struct V_31 * * V_37 , * V_38 ;
int V_39 , V_40 = 0 ;
F_18 ( & V_33 ) ;
if ( V_26 == 0 ) {
for ( V_39 = F_22 ( V_34 ) - 1 ; V_39 > 0 ; V_39 -- ) {
if ( V_34 [ V_39 ] == NULL )
break;
}
if ( V_39 == 0 ) {
F_23 ( L_2 ,
V_36 ) ;
V_40 = - V_41 ;
goto V_42;
}
V_26 = V_39 ;
V_40 = V_26 ;
}
V_38 = F_24 ( sizeof( struct V_31 ) , V_43 ) ;
if ( V_38 == NULL ) {
V_40 = - V_44 ;
goto V_42;
}
V_38 -> V_26 = V_26 ;
F_25 ( V_38 -> V_36 , V_36 , sizeof( V_38 -> V_36 ) ) ;
V_38 -> V_35 = NULL ;
V_39 = F_16 ( V_26 ) ;
for ( V_37 = & V_34 [ V_39 ] ; * V_37 ; V_37 = & ( * V_37 ) -> V_35 ) {
if ( ( * V_37 ) -> V_26 == V_26 )
break;
}
if ( ! * V_37 )
* V_37 = V_38 ;
else
V_40 = - V_41 ;
if ( V_40 < 0 ) {
F_23 ( L_3 ,
V_26 , V_36 ) ;
F_26 ( V_38 ) ;
}
V_42:
F_20 ( & V_33 ) ;
return V_40 ;
}
void F_27 ( unsigned int V_26 , const char * V_36 )
{
struct V_31 * * V_37 ;
struct V_31 * V_38 = NULL ;
int V_39 = F_16 ( V_26 ) ;
F_18 ( & V_33 ) ;
for ( V_37 = & V_34 [ V_39 ] ; * V_37 ; V_37 = & ( * V_37 ) -> V_35 )
if ( ( * V_37 ) -> V_26 == V_26 )
break;
if ( ! * V_37 || strcmp ( ( * V_37 ) -> V_36 , V_36 ) ) {
F_28 ( 1 ) ;
} else {
V_38 = * V_37 ;
* V_37 = V_38 -> V_35 ;
}
F_20 ( & V_33 ) ;
F_26 ( V_38 ) ;
}
static int F_29 ( int V_45 )
{
#ifdef F_30
int V_23 ;
for ( V_23 = 0 ; V_23 < V_46 / 2 ; V_23 ++ ) {
int V_47 = V_45 & ( 1 << V_23 ) ;
int V_48 = V_45 & ( 1 << ( V_46 - 1 - V_23 ) ) ;
int V_49 = V_46 - 1 - 2 * V_23 ;
V_45 ^= V_47 | V_48 ;
V_47 <<= V_49 ;
V_48 >>= V_49 ;
V_45 |= V_47 | V_48 ;
}
#endif
return V_45 ;
}
int F_31 ( struct V_1 * V_5 , T_3 * V_50 )
{
struct V_2 * V_3 = F_32 ( V_5 ) ;
int V_14 , V_51 ;
if ( V_5 -> V_4 < V_3 -> V_52 ) {
* V_50 = F_33 ( V_3 -> V_26 , V_3 -> V_53 + V_5 -> V_4 ) ;
return 0 ;
}
do {
if ( ! F_34 ( & V_54 , V_43 ) )
return - V_44 ;
V_51 = F_35 ( & V_54 , V_5 , & V_14 ) ;
} while ( V_51 == - V_55 );
if ( V_51 )
return V_51 ;
if ( V_14 > V_56 ) {
F_36 ( & V_54 , V_14 ) ;
return - V_41 ;
}
* V_50 = F_33 ( V_57 , F_29 ( V_14 ) ) ;
return 0 ;
}
void F_37 ( T_3 V_50 )
{
F_38 () ;
if ( V_50 == F_33 ( 0 , 0 ) )
return;
if ( F_39 ( V_50 ) == V_57 ) {
F_18 ( & V_58 ) ;
F_36 ( & V_54 , F_29 ( F_40 ( V_50 ) ) ) ;
F_20 ( & V_58 ) ;
}
}
static char * F_41 ( T_3 V_50 , char * V_59 )
{
if ( F_39 ( V_50 ) <= 0xff && F_40 ( V_50 ) <= 0xff ) {
char V_60 [ V_61 ] ;
snprintf ( V_60 , V_61 , L_4 , F_39 ( V_50 ) , F_40 ( V_50 ) ) ;
snprintf ( V_59 , V_61 , L_5 , V_60 ) ;
} else
snprintf ( V_59 , V_61 , L_6 , F_39 ( V_50 ) , F_40 ( V_50 ) ) ;
return V_59 ;
}
void F_42 ( T_3 V_50 , unsigned long V_62 )
{
F_43 ( V_63 , V_50 , V_62 ) ;
}
static struct V_64 * F_44 ( T_3 V_50 , int * V_4 , void * V_65 )
{
struct V_2 * V_38 = V_65 ;
return & F_45 ( V_38 ) -> V_66 ;
}
static int F_46 ( T_3 V_50 , void * V_65 )
{
struct V_2 * V_38 = V_65 ;
if ( ! F_47 ( V_38 ) )
return - 1 ;
return 0 ;
}
void F_48 ( struct V_2 * V_3 )
{
struct V_67 * V_68 = F_45 ( V_3 ) ;
struct V_69 * V_70 ;
struct V_10 V_11 ;
struct V_1 * V_5 ;
int V_71 ;
V_68 -> V_72 = V_3 -> V_73 ;
F_49 ( V_68 , V_3 -> V_74 ) ;
F_50 ( V_68 , 1 ) ;
if ( F_51 ( V_68 ) )
return;
if ( ! V_75 ) {
V_71 = F_52 ( V_76 , & V_68 -> V_66 ,
F_53 ( & V_68 -> V_66 ) ) ;
if ( V_71 ) {
F_54 ( V_68 ) ;
return;
}
}
V_3 -> V_25 . V_77 = F_55 ( L_7 , & V_68 -> V_66 ) ;
V_3 -> V_78 = F_55 ( L_8 , & V_68 -> V_66 ) ;
if ( ! F_56 ( V_3 ) )
goto exit;
if ( ! F_57 ( V_3 ) )
goto exit;
V_70 = F_58 ( V_3 , 0 ) ;
if ( ! V_70 )
goto exit;
V_70 -> V_79 = 1 ;
V_71 = F_59 ( V_70 , V_80 , NULL ) ;
if ( V_71 < 0 )
goto exit;
F_60 ( V_70 , V_80 ) ;
exit:
F_50 ( V_68 , 0 ) ;
F_61 ( & V_68 -> V_66 , V_81 ) ;
F_9 ( & V_11 , V_3 , 0 ) ;
while ( ( V_5 = F_10 ( & V_11 ) ) )
F_61 ( & F_7 ( V_5 ) -> V_66 , V_81 ) ;
F_12 ( & V_11 ) ;
}
void F_62 ( struct V_2 * V_3 )
{
struct V_82 * V_83 ;
T_3 V_50 ;
int V_84 ;
F_28 ( V_3 -> V_52 && ! ( V_3 -> V_26 || V_3 -> V_53 ) ) ;
F_28 ( ! V_3 -> V_52 && ! ( V_3 -> V_12 & V_85 ) ) ;
V_3 -> V_12 |= V_86 ;
V_84 = F_31 ( & V_3 -> V_25 , & V_50 ) ;
if ( V_84 ) {
F_28 ( 1 ) ;
return;
}
F_45 ( V_3 ) -> V_50 = V_50 ;
V_3 -> V_26 = F_39 ( V_50 ) ;
V_3 -> V_53 = F_40 ( V_50 ) ;
V_83 = & V_3 -> V_87 -> V_82 ;
F_63 ( V_83 , F_64 ( V_3 ) ) ;
F_65 ( F_64 ( V_3 ) , V_3 -> V_52 , NULL ,
F_44 , F_46 , V_3 ) ;
F_48 ( V_3 ) ;
F_66 ( V_3 ) ;
F_67 ( F_68 ( V_3 -> V_87 ) ) ;
V_84 = F_52 ( & F_45 ( V_3 ) -> V_66 , & V_83 -> V_88 -> V_66 ,
L_9 ) ;
F_28 ( V_84 ) ;
F_69 ( V_3 ) ;
}
void F_70 ( struct V_2 * V_3 )
{
struct V_10 V_11 ;
struct V_1 * V_5 ;
F_71 ( V_3 ) ;
F_9 ( & V_11 , V_3 ,
V_20 | V_13 ) ;
while ( ( V_5 = F_10 ( & V_11 ) ) ) {
F_72 ( V_3 , V_5 -> V_4 ) ;
F_73 ( V_3 , V_5 -> V_4 ) ;
}
F_12 ( & V_11 ) ;
F_72 ( V_3 , 0 ) ;
F_37 ( F_45 ( V_3 ) -> V_50 ) ;
F_74 ( V_3 , 0 ) ;
V_3 -> V_12 &= ~ V_86 ;
F_75 ( & F_45 ( V_3 ) -> V_66 , L_9 ) ;
F_76 ( & V_3 -> V_87 -> V_82 ) ;
F_77 ( V_3 ) ;
F_42 ( F_64 ( V_3 ) , V_3 -> V_52 ) ;
F_78 ( & V_3 -> V_25 , 0 ) ;
V_3 -> V_25 . V_89 = 0 ;
F_79 ( V_3 -> V_25 . V_77 ) ;
F_79 ( V_3 -> V_78 ) ;
V_3 -> V_73 = NULL ;
if ( ! V_75 )
F_75 ( V_76 , F_80 ( F_45 ( V_3 ) ) ) ;
F_54 ( F_45 ( V_3 ) ) ;
}
struct V_2 * F_81 ( T_3 V_50 , int * V_4 )
{
struct V_2 * V_3 = NULL ;
if ( F_39 ( V_50 ) != V_57 ) {
struct V_64 * V_66 ;
V_66 = F_82 ( V_63 , V_50 , V_4 ) ;
if ( V_66 )
V_3 = F_83 ( F_84 ( V_66 ) ) ;
} else {
struct V_1 * V_5 ;
F_18 ( & V_58 ) ;
V_5 = F_85 ( & V_54 , F_29 ( F_40 ( V_50 ) ) ) ;
if ( V_5 && F_47 ( F_32 ( V_5 ) ) ) {
* V_4 = V_5 -> V_4 ;
V_3 = F_32 ( V_5 ) ;
}
F_20 ( & V_58 ) ;
}
return V_3 ;
}
struct V_69 * F_58 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 ;
struct V_69 * V_70 = NULL ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 )
V_70 = F_86 ( F_87 ( V_5 ) ) ;
F_11 ( V_5 ) ;
return V_70 ;
}
void T_4 F_88 ( void )
{
struct V_90 V_91 ;
struct V_67 * V_88 ;
F_89 ( & V_91 , & V_92 , NULL , & V_93 ) ;
while ( ( V_88 = F_90 ( & V_91 ) ) ) {
struct V_2 * V_3 = F_83 ( V_88 ) ;
struct V_10 V_11 ;
struct V_1 * V_5 ;
char V_94 [ V_95 ] ;
char V_96 [ V_61 ] ;
T_5 V_97 [ V_98 * 2 + 1 ] ;
if ( F_57 ( V_3 ) == 0 ||
( V_3 -> V_12 & V_99 ) )
continue;
F_9 ( & V_11 , V_3 , V_15 ) ;
while ( ( V_5 = F_10 ( & V_11 ) ) ) {
bool V_100 = V_5 == & V_3 -> V_25 ;
V_97 [ 0 ] = 0 ;
if ( V_5 -> V_101 )
F_91 ( V_5 -> V_101 -> V_97 , V_97 ) ;
F_23 ( L_10 , V_100 ? L_11 : L_12 ,
F_41 ( F_87 ( V_5 ) , V_96 ) ,
( unsigned long long ) V_5 -> V_19 >> 1 ,
V_74 ( V_3 , V_5 -> V_4 , V_94 ) , V_97 ) ;
if ( V_100 ) {
if ( V_3 -> V_73 != NULL &&
V_3 -> V_73 -> V_102 != NULL )
F_23 ( L_13 ,
V_3 -> V_73 -> V_102 -> V_36 ) ;
else
F_23 ( L_14 ) ;
} else
F_23 ( L_15 ) ;
}
F_12 ( & V_11 ) ;
}
F_92 ( & V_91 ) ;
}
static void * F_93 ( struct V_28 * V_29 , T_6 * V_103 )
{
T_6 V_104 = * V_103 ;
struct V_90 * V_91 ;
struct V_67 * V_88 ;
V_91 = F_24 ( sizeof( * V_91 ) , V_43 ) ;
if ( ! V_91 )
return F_94 ( - V_44 ) ;
V_29 -> V_105 = V_91 ;
F_89 ( V_91 , & V_92 , NULL , & V_93 ) ;
do {
V_88 = F_90 ( V_91 ) ;
if ( ! V_88 )
return NULL ;
} while ( V_104 -- );
return F_83 ( V_88 ) ;
}
static void * F_95 ( struct V_28 * V_29 , void * V_106 , T_6 * V_103 )
{
struct V_67 * V_88 ;
( * V_103 ) ++ ;
V_88 = F_90 ( V_29 -> V_105 ) ;
if ( V_88 )
return F_83 ( V_88 ) ;
return NULL ;
}
static void F_96 ( struct V_28 * V_29 , void * V_106 )
{
struct V_90 * V_91 = V_29 -> V_105 ;
if ( V_91 ) {
F_92 ( V_91 ) ;
F_26 ( V_91 ) ;
}
}
static void * F_97 ( struct V_28 * V_29 , T_6 * V_103 )
{
static void * V_38 ;
V_38 = F_93 ( V_29 , V_103 ) ;
if ( ! F_98 ( V_38 ) && ! * V_103 )
F_99 ( V_29 , L_16 ) ;
return V_38 ;
}
static int F_100 ( struct V_28 * V_29 , void * V_106 )
{
struct V_2 * V_107 = V_106 ;
struct V_10 V_11 ;
struct V_1 * V_5 ;
char V_59 [ V_95 ] ;
if ( ! F_57 ( V_107 ) || ( ! F_101 ( V_107 ) &&
( V_107 -> V_12 & V_108 ) ) )
return 0 ;
if ( V_107 -> V_12 & V_99 )
return 0 ;
F_9 ( & V_11 , V_107 , V_15 ) ;
while ( ( V_5 = F_10 ( & V_11 ) ) )
F_19 ( V_29 , L_17 ,
F_39 ( F_87 ( V_5 ) ) , F_40 ( F_87 ( V_5 ) ) ,
( unsigned long long ) V_5 -> V_19 >> 1 ,
V_74 ( V_107 , V_5 -> V_4 , V_59 ) ) ;
F_12 ( & V_11 ) ;
return 0 ;
}
static int F_102 ( struct V_109 * V_109 , struct V_110 * V_110 )
{
return F_103 ( V_110 , & V_111 ) ;
}
static struct V_64 * F_104 ( T_3 V_50 , int * V_4 , void * V_65 )
{
if ( F_105 ( L_18 , F_39 ( V_50 ) , F_40 ( V_50 ) ) > 0 )
F_105 ( L_19 , F_39 ( V_50 ) ) ;
return NULL ;
}
static int T_4 F_106 ( void )
{
int error ;
V_92 . V_112 = V_113 ;
error = F_107 ( & V_92 ) ;
if ( F_2 ( error ) )
return error ;
V_63 = F_108 ( F_104 , & V_33 ) ;
F_109 () ;
F_21 ( V_57 , L_20 ) ;
if ( ! V_75 )
V_76 = F_55 ( L_21 , NULL ) ;
return 0 ;
}
static T_7 F_110 ( struct V_67 * V_88 ,
struct V_114 * V_115 , char * V_59 )
{
struct V_2 * V_3 = F_83 ( V_88 ) ;
return sprintf ( V_59 , L_22 , V_3 -> V_52 ) ;
}
static T_7 F_111 ( struct V_67 * V_88 ,
struct V_114 * V_115 , char * V_59 )
{
struct V_2 * V_3 = F_83 ( V_88 ) ;
return sprintf ( V_59 , L_22 , F_101 ( V_3 ) ) ;
}
static T_7 F_112 ( struct V_67 * V_88 ,
struct V_114 * V_115 , char * V_59 )
{
struct V_2 * V_3 = F_83 ( V_88 ) ;
return sprintf ( V_59 , L_22 ,
( V_3 -> V_12 & V_108 ? 1 : 0 ) ) ;
}
static T_7 F_113 ( struct V_67 * V_88 ,
struct V_114 * V_115 , char * V_59 )
{
struct V_2 * V_3 = F_83 ( V_88 ) ;
return sprintf ( V_59 , L_22 , F_114 ( V_3 ) ? 1 : 0 ) ;
}
static T_7 F_115 ( struct V_67 * V_88 ,
struct V_114 * V_115 , char * V_59 )
{
struct V_2 * V_3 = F_83 ( V_88 ) ;
return sprintf ( V_59 , L_23 , V_3 -> V_12 ) ;
}
static T_7 F_116 ( struct V_67 * V_88 ,
struct V_114 * V_115 ,
char * V_59 )
{
struct V_2 * V_3 = F_83 ( V_88 ) ;
return sprintf ( V_59 , L_22 , F_117 ( V_3 -> V_87 ) ) ;
}
static T_7 F_118 ( struct V_67 * V_88 ,
struct V_114 * V_115 ,
char * V_59 )
{
struct V_2 * V_3 = F_83 ( V_88 ) ;
return sprintf ( V_59 , L_22 , F_119 ( V_3 -> V_87 ) ) ;
}
static void F_120 ( struct V_2 * V_3 ,
struct V_6 * V_116 )
{
struct V_6 * V_117 = V_3 -> V_8 ;
F_15 ( V_3 -> V_8 , V_116 ) ;
if ( V_117 ) {
F_15 ( V_117 -> V_24 , NULL ) ;
F_121 ( V_117 , V_118 ) ;
}
}
int F_122 ( struct V_2 * V_3 , int V_4 )
{
struct V_6 * V_117 = V_3 -> V_8 ;
struct V_6 * V_116 ;
int V_9 = V_117 ? V_117 -> V_9 : 0 ;
int V_119 = V_4 + 1 ;
T_8 V_120 ;
int V_23 ;
if ( F_101 ( V_3 ) && V_119 > F_101 ( V_3 ) )
return - V_121 ;
if ( V_119 <= V_9 )
return 0 ;
V_120 = sizeof( * V_116 ) + V_119 * sizeof( V_116 -> V_5 [ 0 ] ) ;
V_116 = F_123 ( V_120 , V_43 , V_3 -> V_122 ) ;
if ( ! V_116 )
return - V_44 ;
V_116 -> V_9 = V_119 ;
for ( V_23 = 0 ; V_23 < V_9 ; V_23 ++ )
F_15 ( V_116 -> V_5 [ V_23 ] , V_117 -> V_5 [ V_23 ] ) ;
F_120 ( V_3 , V_116 ) ;
return 0 ;
}
static void F_124 ( struct V_67 * V_88 )
{
struct V_2 * V_3 = F_83 ( V_88 ) ;
F_125 ( V_3 ) ;
F_26 ( V_3 -> V_123 ) ;
F_120 ( V_3 , NULL ) ;
F_126 ( & V_3 -> V_25 ) ;
F_127 ( & V_3 -> V_25 ) ;
if ( V_3 -> V_87 )
F_128 ( V_3 -> V_87 ) ;
F_26 ( V_3 ) ;
}
static char * F_129 ( struct V_67 * V_88 , T_9 * V_124 )
{
struct V_2 * V_3 = F_83 ( V_88 ) ;
if ( V_3 -> V_125 )
return V_3 -> V_125 ( V_3 , V_124 ) ;
return NULL ;
}
static int F_130 ( struct V_28 * V_29 , void * V_106 )
{
struct V_2 * V_126 = V_106 ;
struct V_10 V_11 ;
struct V_1 * V_127 ;
char V_59 [ V_95 ] ;
int V_128 ;
F_9 ( & V_11 , V_126 , V_16 ) ;
while ( ( V_127 = F_10 ( & V_11 ) ) ) {
V_128 = F_131 () ;
F_132 ( V_128 , V_127 ) ;
F_133 () ;
F_19 ( V_29 , L_24
L_25 ,
F_39 ( F_87 ( V_127 ) ) , F_40 ( F_87 ( V_127 ) ) ,
V_74 ( V_126 , V_127 -> V_4 , V_59 ) ,
F_134 ( V_127 , V_129 [ V_130 ] ) ,
F_134 ( V_127 , V_131 [ V_130 ] ) ,
F_134 ( V_127 , V_132 [ V_130 ] ) ,
F_135 ( F_134 ( V_127 , V_133 [ V_130 ] ) ) ,
F_134 ( V_127 , V_129 [ V_134 ] ) ,
F_134 ( V_127 , V_131 [ V_134 ] ) ,
F_134 ( V_127 , V_132 [ V_134 ] ) ,
F_135 ( F_134 ( V_127 , V_133 [ V_134 ] ) ) ,
F_136 ( V_127 ) ,
F_135 ( F_134 ( V_127 , V_135 ) ) ,
F_135 ( F_134 ( V_127 , V_136 ) )
) ;
}
F_12 ( & V_11 ) ;
return 0 ;
}
static int F_137 ( struct V_109 * V_109 , struct V_110 * V_110 )
{
return F_103 ( V_110 , & V_137 ) ;
}
static int T_4 F_138 ( void )
{
F_139 ( L_26 , 0 , NULL , & V_138 ) ;
F_139 ( L_27 , 0 , NULL , & V_139 ) ;
return 0 ;
}
T_3 F_140 ( const char * V_36 , int V_4 )
{
T_3 V_50 = F_33 ( 0 , 0 ) ;
struct V_90 V_91 ;
struct V_67 * V_88 ;
F_89 ( & V_91 , & V_92 , NULL , & V_93 ) ;
while ( ( V_88 = F_90 ( & V_91 ) ) ) {
struct V_2 * V_3 = F_83 ( V_88 ) ;
struct V_1 * V_5 ;
if ( strcmp ( F_80 ( V_88 ) , V_36 ) )
continue;
if ( V_4 < V_3 -> V_52 ) {
V_50 = F_33 ( F_39 ( V_88 -> V_50 ) ,
F_40 ( V_88 -> V_50 ) + V_4 ) ;
break;
}
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 ) {
V_50 = F_87 ( V_5 ) ;
F_11 ( V_5 ) ;
break;
}
F_11 ( V_5 ) ;
}
F_92 ( & V_91 ) ;
return V_50 ;
}
struct V_2 * F_141 ( int V_52 )
{
return F_142 ( V_52 , - 1 ) ;
}
struct V_2 * F_142 ( int V_52 , int V_122 )
{
struct V_2 * V_3 ;
V_3 = F_143 ( sizeof( struct V_2 ) ,
V_43 | V_140 , V_122 ) ;
if ( V_3 ) {
if ( ! F_144 ( & V_3 -> V_25 ) ) {
F_26 ( V_3 ) ;
return NULL ;
}
V_3 -> V_122 = V_122 ;
if ( F_122 ( V_3 , 0 ) ) {
F_126 ( & V_3 -> V_25 ) ;
F_26 ( V_3 ) ;
return NULL ;
}
V_3 -> V_8 -> V_5 [ 0 ] = & V_3 -> V_25 ;
F_145 ( & V_3 -> V_25 ) ;
V_3 -> V_52 = V_52 ;
F_146 ( V_3 ) ;
F_45 ( V_3 ) -> V_141 = & V_92 ;
F_45 ( V_3 ) -> type = & V_93 ;
F_147 ( F_45 ( V_3 ) ) ;
}
return V_3 ;
}
struct V_64 * F_47 ( struct V_2 * V_3 )
{
struct V_142 * V_143 ;
struct V_64 * V_66 ;
if ( ! V_3 -> V_144 )
return NULL ;
V_143 = V_3 -> V_144 -> V_143 ;
if ( V_143 && ! F_148 ( V_143 ) )
return NULL ;
V_66 = F_149 ( & F_45 ( V_3 ) -> V_66 ) ;
if ( V_66 == NULL ) {
F_150 ( V_143 ) ;
return NULL ;
}
return V_66 ;
}
void F_151 ( struct V_2 * V_3 )
{
if ( V_3 )
F_79 ( & F_45 ( V_3 ) -> V_66 ) ;
}
static void F_152 ( struct V_2 * V_145 , int V_146 )
{
char V_147 [] = L_28 ;
char * V_148 [] = { V_147 , NULL } ;
if ( ! V_146 )
V_147 [ 8 ] = '0' ;
F_153 ( & F_45 ( V_145 ) -> V_66 , V_149 , V_148 ) ;
}
void F_154 ( struct V_69 * V_70 , int V_150 )
{
V_70 -> V_151 -> V_152 = V_150 ;
}
void F_155 ( struct V_2 * V_3 , int V_150 )
{
struct V_10 V_11 ;
struct V_1 * V_5 ;
if ( V_3 -> V_25 . V_152 != V_150 ) {
F_152 ( V_3 , V_150 ) ;
V_3 -> V_25 . V_152 = V_150 ;
}
F_9 ( & V_11 , V_3 , V_20 ) ;
while ( ( V_5 = F_10 ( & V_11 ) ) )
V_5 -> V_152 = V_150 ;
F_12 ( & V_11 ) ;
}
int F_156 ( struct V_69 * V_70 )
{
if ( ! V_70 )
return 0 ;
return V_70 -> V_151 -> V_152 ;
}
int F_72 ( struct V_2 * V_3 , int V_4 )
{
int V_153 = 0 ;
struct V_69 * V_70 = F_58 ( V_3 , V_4 ) ;
if ( V_70 ) {
F_157 ( V_70 ) ;
V_153 = F_158 ( V_70 , true ) ;
F_159 ( V_70 ) ;
}
return V_153 ;
}
static unsigned long F_160 ( struct V_2 * V_3 )
{
struct V_154 * V_155 = V_3 -> V_155 ;
long V_156 = 0 ;
if ( V_155 -> V_157 >= 0 )
V_156 = V_155 -> V_157 ;
else if ( V_3 -> V_158 & ~ V_3 -> V_159 )
V_156 = V_160 ;
return F_161 ( V_156 ) ;
}
void F_162 ( struct V_2 * V_3 )
{
struct V_154 * V_155 = V_3 -> V_155 ;
unsigned long V_12 ;
bool V_161 ;
if ( ! V_155 )
return;
F_18 ( & V_155 -> V_162 ) ;
F_163 ( & V_155 -> V_163 , V_12 ) ;
V_161 = ! V_155 -> V_164 ++ ;
F_164 ( & V_155 -> V_163 , V_12 ) ;
if ( V_161 )
F_165 ( & V_3 -> V_155 -> V_165 ) ;
F_20 ( & V_155 -> V_162 ) ;
}
static void F_166 ( struct V_2 * V_3 , bool V_166 )
{
struct V_154 * V_155 = V_3 -> V_155 ;
unsigned long V_167 ;
unsigned long V_12 ;
F_163 ( & V_155 -> V_163 , V_12 ) ;
if ( F_67 ( V_155 -> V_164 <= 0 ) )
goto V_168;
if ( -- V_155 -> V_164 )
goto V_168;
V_167 = F_160 ( V_3 ) ;
F_167 ( & V_155 -> V_165 . V_169 , V_167 / 4 ) ;
if ( V_166 )
F_168 ( V_170 , & V_155 -> V_165 , 0 ) ;
else if ( V_167 )
F_168 ( V_170 , & V_155 -> V_165 , V_167 ) ;
V_168:
F_164 ( & V_155 -> V_163 , V_12 ) ;
}
void F_169 ( struct V_2 * V_3 )
{
if ( V_3 -> V_155 )
F_166 ( V_3 , false ) ;
}
void F_170 ( struct V_2 * V_3 , unsigned int V_171 )
{
struct V_154 * V_155 = V_3 -> V_155 ;
if ( ! V_155 )
return;
F_171 ( & V_155 -> V_163 ) ;
V_155 -> V_172 |= V_171 ;
if ( ! V_155 -> V_164 ) {
F_172 ( & V_155 -> V_165 ) ;
F_168 ( V_170 , & V_155 -> V_165 , 0 ) ;
}
F_173 ( & V_155 -> V_163 ) ;
}
unsigned int F_174 ( struct V_2 * V_3 , unsigned int V_171 )
{
const struct V_173 * V_174 = V_3 -> V_144 ;
struct V_154 * V_155 = V_3 -> V_155 ;
unsigned int V_175 ;
if ( ! V_155 ) {
if ( ( V_171 & V_176 ) &&
V_174 -> V_177 && V_174 -> V_177 ( V_3 ) )
return V_176 ;
return 0 ;
}
F_171 ( & V_155 -> V_163 ) ;
V_155 -> V_172 |= V_171 ;
F_173 ( & V_155 -> V_163 ) ;
F_162 ( V_3 ) ;
F_168 ( V_170 , & V_155 -> V_165 , 0 ) ;
F_175 ( & V_155 -> V_165 ) ;
F_166 ( V_3 , false ) ;
F_171 ( & V_155 -> V_163 ) ;
F_67 ( V_155 -> V_172 & V_171 ) ;
V_175 = V_155 -> V_175 & V_171 ;
V_155 -> V_175 &= ~ V_171 ;
F_173 ( & V_155 -> V_163 ) ;
return V_175 ;
}
static void F_176 ( struct V_178 * V_179 )
{
struct V_180 * V_165 = F_177 ( V_179 ) ;
struct V_154 * V_155 = F_178 ( V_165 , struct V_154 , V_165 ) ;
struct V_2 * V_3 = V_155 -> V_3 ;
char * V_148 [ F_22 ( V_181 ) + 1 ] = { } ;
unsigned int V_172 = V_155 -> V_172 ;
unsigned int V_158 ;
unsigned long V_167 ;
int V_182 = 0 , V_23 ;
V_158 = V_3 -> V_144 -> V_183 ( V_3 , V_172 ) ;
F_171 ( & V_155 -> V_163 ) ;
V_158 &= ~ V_155 -> V_175 ;
V_155 -> V_175 |= V_158 ;
V_155 -> V_172 &= ~ V_172 ;
V_167 = F_160 ( V_3 ) ;
if ( ! V_155 -> V_164 && V_167 )
F_168 ( V_170 , & V_155 -> V_165 , V_167 ) ;
F_173 ( & V_155 -> V_163 ) ;
for ( V_23 = 0 ; V_23 < F_22 ( V_181 ) ; V_23 ++ )
if ( V_158 & V_3 -> V_158 & ( 1 << V_23 ) )
V_148 [ V_182 ++ ] = V_181 [ V_23 ] ;
if ( V_182 )
F_153 ( & F_45 ( V_3 ) -> V_66 , V_149 , V_148 ) ;
}
static T_7 F_179 ( unsigned int V_158 , char * V_59 )
{
const char * V_184 = L_11 ;
T_7 V_103 = 0 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < F_22 ( V_185 ) ; V_23 ++ )
if ( V_158 & ( 1 << V_23 ) ) {
V_103 += sprintf ( V_59 + V_103 , L_29 ,
V_184 , V_185 [ V_23 ] ) ;
V_184 = L_30 ;
}
if ( V_103 )
V_103 += sprintf ( V_59 + V_103 , L_15 ) ;
return V_103 ;
}
static T_7 F_180 ( struct V_67 * V_88 ,
struct V_114 * V_115 , char * V_59 )
{
struct V_2 * V_3 = F_83 ( V_88 ) ;
return F_179 ( V_3 -> V_158 , V_59 ) ;
}
static T_7 F_181 ( struct V_67 * V_88 ,
struct V_114 * V_115 , char * V_59 )
{
struct V_2 * V_3 = F_83 ( V_88 ) ;
return F_179 ( V_3 -> V_159 , V_59 ) ;
}
static T_7 F_182 ( struct V_67 * V_88 ,
struct V_114 * V_115 ,
char * V_59 )
{
struct V_2 * V_3 = F_83 ( V_88 ) ;
return sprintf ( V_59 , L_31 , V_3 -> V_155 -> V_157 ) ;
}
static T_7 F_183 ( struct V_67 * V_88 ,
struct V_114 * V_115 ,
const char * V_59 , T_8 V_186 )
{
struct V_2 * V_3 = F_83 ( V_88 ) ;
long V_167 ;
if ( ! V_186 || ! sscanf ( V_59 , L_32 , & V_167 ) )
return - V_121 ;
if ( V_167 < 0 && V_167 != - 1 )
return - V_121 ;
F_162 ( V_3 ) ;
V_3 -> V_155 -> V_157 = V_167 ;
F_166 ( V_3 , true ) ;
return V_186 ;
}
static int F_184 ( const char * V_187 ,
const struct V_188 * V_189 )
{
struct V_154 * V_155 ;
int V_40 ;
V_40 = F_185 ( V_187 , V_189 ) ;
if ( V_40 < 0 )
return V_40 ;
F_18 ( & V_190 ) ;
F_186 (ev, &disk_events, node)
F_170 ( V_155 -> V_3 , 0 ) ;
F_20 ( & V_190 ) ;
return 0 ;
}
static void F_69 ( struct V_2 * V_3 )
{
struct V_154 * V_155 ;
if ( ! V_3 -> V_144 -> V_183 )
return;
V_155 = F_187 ( sizeof( * V_155 ) , V_43 ) ;
if ( ! V_155 ) {
F_188 ( L_33 , V_3 -> V_74 ) ;
return;
}
if ( F_189 ( & F_45 ( V_3 ) -> V_66 ,
V_191 ) < 0 ) {
F_188 ( L_34 ,
V_3 -> V_74 ) ;
F_26 ( V_155 ) ;
return;
}
V_3 -> V_155 = V_155 ;
F_190 ( & V_155 -> V_192 ) ;
V_155 -> V_3 = V_3 ;
F_191 ( & V_155 -> V_163 ) ;
F_192 ( & V_155 -> V_162 ) ;
V_155 -> V_164 = 1 ;
V_155 -> V_157 = - 1 ;
F_193 ( & V_155 -> V_165 , F_176 ) ;
F_18 ( & V_190 ) ;
F_194 ( & V_155 -> V_192 , & V_154 ) ;
F_20 ( & V_190 ) ;
F_166 ( V_3 , true ) ;
}
static void F_71 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_155 )
return;
F_162 ( V_3 ) ;
F_18 ( & V_190 ) ;
F_195 ( & V_3 -> V_155 -> V_192 ) ;
F_20 ( & V_190 ) ;
F_196 ( & F_45 ( V_3 ) -> V_66 , V_191 ) ;
}
static void F_125 ( struct V_2 * V_3 )
{
F_67 ( V_3 -> V_155 && V_3 -> V_155 -> V_164 != 1 ) ;
F_26 ( V_3 -> V_155 ) ;
}
