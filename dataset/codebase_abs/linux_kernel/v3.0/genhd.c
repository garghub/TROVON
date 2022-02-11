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
V_84 = F_52 ( & F_45 ( V_3 ) -> V_66 , & V_83 -> V_88 -> V_66 ,
L_9 ) ;
F_28 ( V_84 ) ;
F_67 ( V_3 ) ;
}
void F_68 ( struct V_2 * V_3 )
{
struct V_10 V_11 ;
struct V_1 * V_5 ;
F_69 ( V_3 ) ;
F_9 ( & V_11 , V_3 ,
V_20 | V_13 ) ;
while ( ( V_5 = F_10 ( & V_11 ) ) ) {
F_70 ( V_3 , V_5 -> V_4 ) ;
F_71 ( V_3 , V_5 -> V_4 ) ;
}
F_12 ( & V_11 ) ;
F_70 ( V_3 , 0 ) ;
F_37 ( F_45 ( V_3 ) -> V_50 ) ;
F_72 ( V_3 , 0 ) ;
V_3 -> V_12 &= ~ V_86 ;
F_73 ( & F_45 ( V_3 ) -> V_66 , L_9 ) ;
F_74 ( & V_3 -> V_87 -> V_82 ) ;
F_75 ( V_3 ) ;
F_42 ( F_64 ( V_3 ) , V_3 -> V_52 ) ;
F_76 ( & V_3 -> V_25 , 0 ) ;
V_3 -> V_25 . V_89 = 0 ;
F_77 ( V_3 -> V_25 . V_77 ) ;
F_77 ( V_3 -> V_78 ) ;
V_3 -> V_73 = NULL ;
if ( ! V_75 )
F_73 ( V_76 , F_78 ( F_45 ( V_3 ) ) ) ;
F_54 ( F_45 ( V_3 ) ) ;
}
struct V_2 * F_79 ( T_3 V_50 , int * V_4 )
{
struct V_2 * V_3 = NULL ;
if ( F_39 ( V_50 ) != V_57 ) {
struct V_64 * V_66 ;
V_66 = F_80 ( V_63 , V_50 , V_4 ) ;
if ( V_66 )
V_3 = F_81 ( F_82 ( V_66 ) ) ;
} else {
struct V_1 * V_5 ;
F_18 ( & V_58 ) ;
V_5 = F_83 ( & V_54 , F_29 ( F_40 ( V_50 ) ) ) ;
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
V_70 = F_84 ( F_85 ( V_5 ) ) ;
F_11 ( V_5 ) ;
return V_70 ;
}
void T_4 F_86 ( void )
{
struct V_90 V_91 ;
struct V_67 * V_88 ;
F_87 ( & V_91 , & V_92 , NULL , & V_93 ) ;
while ( ( V_88 = F_88 ( & V_91 ) ) ) {
struct V_2 * V_3 = F_81 ( V_88 ) ;
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
F_89 ( V_5 -> V_101 -> V_97 , V_97 ) ;
F_23 ( L_10 , V_100 ? L_11 : L_12 ,
F_41 ( F_85 ( V_5 ) , V_96 ) ,
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
F_90 ( & V_91 ) ;
}
static void * F_91 ( struct V_28 * V_29 , T_6 * V_103 )
{
T_6 V_104 = * V_103 ;
struct V_90 * V_91 ;
struct V_67 * V_88 ;
V_91 = F_24 ( sizeof( * V_91 ) , V_43 ) ;
if ( ! V_91 )
return F_92 ( - V_44 ) ;
V_29 -> V_105 = V_91 ;
F_87 ( V_91 , & V_92 , NULL , & V_93 ) ;
do {
V_88 = F_88 ( V_91 ) ;
if ( ! V_88 )
return NULL ;
} while ( V_104 -- );
return F_81 ( V_88 ) ;
}
static void * F_93 ( struct V_28 * V_29 , void * V_106 , T_6 * V_103 )
{
struct V_67 * V_88 ;
( * V_103 ) ++ ;
V_88 = F_88 ( V_29 -> V_105 ) ;
if ( V_88 )
return F_81 ( V_88 ) ;
return NULL ;
}
static void F_94 ( struct V_28 * V_29 , void * V_106 )
{
struct V_90 * V_91 = V_29 -> V_105 ;
if ( V_91 ) {
F_90 ( V_91 ) ;
F_26 ( V_91 ) ;
}
}
static void * F_95 ( struct V_28 * V_29 , T_6 * V_103 )
{
static void * V_38 ;
V_38 = F_91 ( V_29 , V_103 ) ;
if ( ! F_96 ( V_38 ) && ! * V_103 )
F_97 ( V_29 , L_16 ) ;
return V_38 ;
}
static int F_98 ( struct V_28 * V_29 , void * V_106 )
{
struct V_2 * V_107 = V_106 ;
struct V_10 V_11 ;
struct V_1 * V_5 ;
char V_59 [ V_95 ] ;
if ( ! F_57 ( V_107 ) || ( ! F_56 ( V_107 ) &&
( V_107 -> V_12 & V_108 ) ) )
return 0 ;
if ( V_107 -> V_12 & V_99 )
return 0 ;
F_9 ( & V_11 , V_107 , V_15 ) ;
while ( ( V_5 = F_10 ( & V_11 ) ) )
F_19 ( V_29 , L_17 ,
F_39 ( F_85 ( V_5 ) ) , F_40 ( F_85 ( V_5 ) ) ,
( unsigned long long ) V_5 -> V_19 >> 1 ,
V_74 ( V_107 , V_5 -> V_4 , V_59 ) ) ;
F_12 ( & V_11 ) ;
return 0 ;
}
static int F_99 ( struct V_109 * V_109 , struct V_110 * V_110 )
{
return F_100 ( V_110 , & V_111 ) ;
}
static struct V_64 * F_101 ( T_3 V_50 , int * V_4 , void * V_65 )
{
if ( F_102 ( L_18 , F_39 ( V_50 ) , F_40 ( V_50 ) ) > 0 )
F_102 ( L_19 , F_39 ( V_50 ) ) ;
return NULL ;
}
static int T_4 F_103 ( void )
{
int error ;
V_92 . V_112 = V_113 ;
error = F_104 ( & V_92 ) ;
if ( F_2 ( error ) )
return error ;
V_63 = F_105 ( F_101 , & V_33 ) ;
F_106 () ;
F_21 ( V_57 , L_20 ) ;
if ( ! V_75 )
V_76 = F_55 ( L_21 , NULL ) ;
return 0 ;
}
static T_7 F_107 ( struct V_67 * V_88 ,
struct V_114 * V_115 , char * V_59 )
{
struct V_2 * V_3 = F_81 ( V_88 ) ;
return sprintf ( V_59 , L_22 , V_3 -> V_52 ) ;
}
static T_7 F_108 ( struct V_67 * V_88 ,
struct V_114 * V_115 , char * V_59 )
{
struct V_2 * V_3 = F_81 ( V_88 ) ;
return sprintf ( V_59 , L_22 , F_109 ( V_3 ) ) ;
}
static T_7 F_110 ( struct V_67 * V_88 ,
struct V_114 * V_115 , char * V_59 )
{
struct V_2 * V_3 = F_81 ( V_88 ) ;
return sprintf ( V_59 , L_22 ,
( V_3 -> V_12 & V_108 ? 1 : 0 ) ) ;
}
static T_7 F_111 ( struct V_67 * V_88 ,
struct V_114 * V_115 , char * V_59 )
{
struct V_2 * V_3 = F_81 ( V_88 ) ;
return sprintf ( V_59 , L_22 , F_112 ( V_3 ) ? 1 : 0 ) ;
}
static T_7 F_113 ( struct V_67 * V_88 ,
struct V_114 * V_115 , char * V_59 )
{
struct V_2 * V_3 = F_81 ( V_88 ) ;
return sprintf ( V_59 , L_23 , V_3 -> V_12 ) ;
}
static T_7 F_114 ( struct V_67 * V_88 ,
struct V_114 * V_115 ,
char * V_59 )
{
struct V_2 * V_3 = F_81 ( V_88 ) ;
return sprintf ( V_59 , L_22 , F_115 ( V_3 -> V_87 ) ) ;
}
static T_7 F_116 ( struct V_67 * V_88 ,
struct V_114 * V_115 ,
char * V_59 )
{
struct V_2 * V_3 = F_81 ( V_88 ) ;
return sprintf ( V_59 , L_22 , F_117 ( V_3 -> V_87 ) ) ;
}
static void F_118 ( struct V_116 * V_117 )
{
struct V_6 * V_7 =
F_119 ( V_117 , struct V_6 , V_116 ) ;
F_26 ( V_7 ) ;
}
static void F_120 ( struct V_2 * V_3 ,
struct V_6 * V_118 )
{
struct V_6 * V_119 = V_3 -> V_8 ;
F_15 ( V_3 -> V_8 , V_118 ) ;
if ( V_119 ) {
F_15 ( V_119 -> V_24 , NULL ) ;
F_121 ( & V_119 -> V_116 , F_118 ) ;
}
}
int F_122 ( struct V_2 * V_3 , int V_4 )
{
struct V_6 * V_119 = V_3 -> V_8 ;
struct V_6 * V_118 ;
int V_9 = V_119 ? V_119 -> V_9 : 0 ;
int V_120 = V_4 + 1 ;
T_8 V_121 ;
int V_23 ;
if ( F_109 ( V_3 ) && V_120 > F_109 ( V_3 ) )
return - V_122 ;
if ( V_120 <= V_9 )
return 0 ;
V_121 = sizeof( * V_118 ) + V_120 * sizeof( V_118 -> V_5 [ 0 ] ) ;
V_118 = F_123 ( V_121 , V_43 , V_3 -> V_123 ) ;
if ( ! V_118 )
return - V_44 ;
V_118 -> V_9 = V_120 ;
for ( V_23 = 0 ; V_23 < V_9 ; V_23 ++ )
F_15 ( V_118 -> V_5 [ V_23 ] , V_119 -> V_5 [ V_23 ] ) ;
F_120 ( V_3 , V_118 ) ;
return 0 ;
}
static void F_124 ( struct V_67 * V_88 )
{
struct V_2 * V_3 = F_81 ( V_88 ) ;
F_125 ( V_3 ) ;
F_26 ( V_3 -> V_124 ) ;
F_120 ( V_3 , NULL ) ;
F_126 ( & V_3 -> V_25 ) ;
F_127 ( & V_3 -> V_25 ) ;
F_26 ( V_3 ) ;
}
static char * F_128 ( struct V_67 * V_88 , T_9 * V_125 )
{
struct V_2 * V_3 = F_81 ( V_88 ) ;
if ( V_3 -> V_126 )
return V_3 -> V_126 ( V_3 , V_125 ) ;
return NULL ;
}
static int F_129 ( struct V_28 * V_29 , void * V_106 )
{
struct V_2 * V_127 = V_106 ;
struct V_10 V_11 ;
struct V_1 * V_128 ;
char V_59 [ V_95 ] ;
int V_129 ;
F_9 ( & V_11 , V_127 , V_16 ) ;
while ( ( V_128 = F_10 ( & V_11 ) ) ) {
V_129 = F_130 () ;
F_131 ( V_129 , V_128 ) ;
F_132 () ;
F_19 ( V_29 , L_24
L_25 ,
F_39 ( F_85 ( V_128 ) ) , F_40 ( F_85 ( V_128 ) ) ,
V_74 ( V_127 , V_128 -> V_4 , V_59 ) ,
F_133 ( V_128 , V_130 [ V_131 ] ) ,
F_133 ( V_128 , V_132 [ V_131 ] ) ,
( unsigned long long ) F_133 ( V_128 , V_133 [ V_131 ] ) ,
F_134 ( F_133 ( V_128 , V_134 [ V_131 ] ) ) ,
F_133 ( V_128 , V_130 [ V_135 ] ) ,
F_133 ( V_128 , V_132 [ V_135 ] ) ,
( unsigned long long ) F_133 ( V_128 , V_133 [ V_135 ] ) ,
F_134 ( F_133 ( V_128 , V_134 [ V_135 ] ) ) ,
F_135 ( V_128 ) ,
F_134 ( F_133 ( V_128 , V_136 ) ) ,
F_134 ( F_133 ( V_128 , V_137 ) )
) ;
}
F_12 ( & V_11 ) ;
return 0 ;
}
static int F_136 ( struct V_109 * V_109 , struct V_110 * V_110 )
{
return F_100 ( V_110 , & V_138 ) ;
}
static int T_4 F_137 ( void )
{
F_138 ( L_26 , 0 , NULL , & V_139 ) ;
F_138 ( L_27 , 0 , NULL , & V_140 ) ;
return 0 ;
}
T_3 F_139 ( const char * V_36 , int V_4 )
{
T_3 V_50 = F_33 ( 0 , 0 ) ;
struct V_90 V_91 ;
struct V_67 * V_88 ;
F_87 ( & V_91 , & V_92 , NULL , & V_93 ) ;
while ( ( V_88 = F_88 ( & V_91 ) ) ) {
struct V_2 * V_3 = F_81 ( V_88 ) ;
struct V_1 * V_5 ;
if ( strcmp ( F_78 ( V_88 ) , V_36 ) )
continue;
if ( V_4 < V_3 -> V_52 ) {
V_50 = F_33 ( F_39 ( V_88 -> V_50 ) ,
F_40 ( V_88 -> V_50 ) + V_4 ) ;
break;
}
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 ) {
V_50 = F_85 ( V_5 ) ;
F_11 ( V_5 ) ;
break;
}
F_11 ( V_5 ) ;
}
F_90 ( & V_91 ) ;
return V_50 ;
}
struct V_2 * F_140 ( int V_52 )
{
return F_141 ( V_52 , - 1 ) ;
}
struct V_2 * F_141 ( int V_52 , int V_123 )
{
struct V_2 * V_3 ;
V_3 = F_142 ( sizeof( struct V_2 ) ,
V_43 | V_141 , V_123 ) ;
if ( V_3 ) {
if ( ! F_143 ( & V_3 -> V_25 ) ) {
F_26 ( V_3 ) ;
return NULL ;
}
V_3 -> V_123 = V_123 ;
if ( F_122 ( V_3 , 0 ) ) {
F_126 ( & V_3 -> V_25 ) ;
F_26 ( V_3 ) ;
return NULL ;
}
V_3 -> V_8 -> V_5 [ 0 ] = & V_3 -> V_25 ;
F_144 ( & V_3 -> V_25 ) ;
V_3 -> V_52 = V_52 ;
F_145 ( V_3 ) ;
F_45 ( V_3 ) -> V_142 = & V_92 ;
F_45 ( V_3 ) -> type = & V_93 ;
F_146 ( F_45 ( V_3 ) ) ;
}
return V_3 ;
}
struct V_64 * F_47 ( struct V_2 * V_3 )
{
struct V_143 * V_144 ;
struct V_64 * V_66 ;
if ( ! V_3 -> V_145 )
return NULL ;
V_144 = V_3 -> V_145 -> V_144 ;
if ( V_144 && ! F_147 ( V_144 ) )
return NULL ;
V_66 = F_148 ( & F_45 ( V_3 ) -> V_66 ) ;
if ( V_66 == NULL ) {
F_149 ( V_144 ) ;
return NULL ;
}
return V_66 ;
}
void F_150 ( struct V_2 * V_3 )
{
if ( V_3 )
F_77 ( & F_45 ( V_3 ) -> V_66 ) ;
}
static void F_151 ( struct V_2 * V_146 , int V_147 )
{
char V_148 [] = L_28 ;
char * V_149 [] = { V_148 , NULL } ;
if ( ! V_147 )
V_148 [ 8 ] = '0' ;
F_152 ( & F_45 ( V_146 ) -> V_66 , V_150 , V_149 ) ;
}
void F_153 ( struct V_69 * V_70 , int V_151 )
{
V_70 -> V_152 -> V_153 = V_151 ;
}
void F_154 ( struct V_2 * V_3 , int V_151 )
{
struct V_10 V_11 ;
struct V_1 * V_5 ;
if ( V_3 -> V_25 . V_153 != V_151 ) {
F_151 ( V_3 , V_151 ) ;
V_3 -> V_25 . V_153 = V_151 ;
}
F_9 ( & V_11 , V_3 , V_20 ) ;
while ( ( V_5 = F_10 ( & V_11 ) ) )
V_5 -> V_153 = V_151 ;
F_12 ( & V_11 ) ;
}
int F_155 ( struct V_69 * V_70 )
{
if ( ! V_70 )
return 0 ;
return V_70 -> V_152 -> V_153 ;
}
int F_70 ( struct V_2 * V_3 , int V_4 )
{
int V_154 = 0 ;
struct V_69 * V_70 = F_58 ( V_3 , V_4 ) ;
if ( V_70 ) {
F_156 ( V_70 ) ;
V_154 = F_157 ( V_70 , true ) ;
F_158 ( V_70 ) ;
}
return V_154 ;
}
static unsigned long F_159 ( struct V_2 * V_3 )
{
struct V_155 * V_156 = V_3 -> V_156 ;
long V_157 = 0 ;
if ( V_156 -> V_158 >= 0 )
V_157 = V_156 -> V_158 ;
else if ( V_3 -> V_159 & ~ V_3 -> V_160 )
V_157 = V_161 ;
return F_160 ( V_157 ) ;
}
void F_161 ( struct V_2 * V_3 )
{
struct V_155 * V_156 = V_3 -> V_156 ;
unsigned long V_12 ;
bool V_162 ;
if ( ! V_156 )
return;
F_18 ( & V_156 -> V_163 ) ;
F_162 ( & V_156 -> V_164 , V_12 ) ;
V_162 = ! V_156 -> V_165 ++ ;
F_163 ( & V_156 -> V_164 , V_12 ) ;
if ( V_162 )
F_164 ( & V_3 -> V_156 -> V_166 ) ;
F_20 ( & V_156 -> V_163 ) ;
}
static void F_165 ( struct V_2 * V_3 , bool V_167 )
{
struct V_155 * V_156 = V_3 -> V_156 ;
unsigned long V_168 ;
unsigned long V_12 ;
F_162 ( & V_156 -> V_164 , V_12 ) ;
if ( F_166 ( V_156 -> V_165 <= 0 ) )
goto V_169;
if ( -- V_156 -> V_165 )
goto V_169;
V_168 = F_159 ( V_3 ) ;
F_167 ( & V_156 -> V_166 . V_170 , V_168 / 4 ) ;
if ( V_167 )
F_168 ( V_171 , & V_156 -> V_166 , 0 ) ;
else if ( V_168 )
F_168 ( V_171 , & V_156 -> V_166 , V_168 ) ;
V_169:
F_163 ( & V_156 -> V_164 , V_12 ) ;
}
void F_169 ( struct V_2 * V_3 )
{
if ( V_3 -> V_156 )
F_165 ( V_3 , false ) ;
}
void F_170 ( struct V_2 * V_3 )
{
struct V_155 * V_156 = V_3 -> V_156 ;
unsigned long V_12 ;
if ( ! V_156 )
return;
F_162 ( & V_156 -> V_164 , V_12 ) ;
if ( ! V_156 -> V_165 ) {
F_171 ( & V_156 -> V_166 ) ;
F_168 ( V_171 , & V_156 -> V_166 , 0 ) ;
}
F_163 ( & V_156 -> V_164 , V_12 ) ;
}
unsigned int F_172 ( struct V_2 * V_3 , unsigned int V_172 )
{
const struct V_173 * V_174 = V_3 -> V_145 ;
struct V_155 * V_156 = V_3 -> V_156 ;
unsigned int V_175 ;
if ( ! V_156 ) {
if ( ( V_172 & V_176 ) &&
V_174 -> V_177 && V_174 -> V_177 ( V_3 ) )
return V_176 ;
return 0 ;
}
F_173 ( & V_156 -> V_164 ) ;
V_156 -> V_178 |= V_172 ;
F_174 ( & V_156 -> V_164 ) ;
F_161 ( V_3 ) ;
F_168 ( V_171 , & V_156 -> V_166 , 0 ) ;
F_175 ( & V_156 -> V_166 ) ;
F_165 ( V_3 , false ) ;
F_173 ( & V_156 -> V_164 ) ;
F_166 ( V_156 -> V_178 & V_172 ) ;
V_175 = V_156 -> V_175 & V_172 ;
V_156 -> V_175 &= ~ V_172 ;
F_174 ( & V_156 -> V_164 ) ;
return V_175 ;
}
static void F_176 ( struct V_179 * V_180 )
{
struct V_181 * V_166 = F_177 ( V_180 ) ;
struct V_155 * V_156 = F_119 ( V_166 , struct V_155 , V_166 ) ;
struct V_2 * V_3 = V_156 -> V_3 ;
char * V_149 [ F_22 ( V_182 ) + 1 ] = { } ;
unsigned int V_178 = V_156 -> V_178 ;
unsigned int V_159 ;
unsigned long V_168 ;
int V_183 = 0 , V_23 ;
V_159 = V_3 -> V_145 -> V_184 ( V_3 , V_178 ) ;
F_173 ( & V_156 -> V_164 ) ;
V_159 &= ~ V_156 -> V_175 ;
V_156 -> V_175 |= V_159 ;
V_156 -> V_178 &= ~ V_178 ;
V_168 = F_159 ( V_3 ) ;
if ( ! V_156 -> V_165 && V_168 )
F_168 ( V_171 , & V_156 -> V_166 , V_168 ) ;
F_174 ( & V_156 -> V_164 ) ;
for ( V_23 = 0 ; V_23 < F_22 ( V_182 ) ; V_23 ++ )
if ( V_159 & V_3 -> V_159 & ( 1 << V_23 ) )
V_149 [ V_183 ++ ] = V_182 [ V_23 ] ;
if ( V_183 )
F_152 ( & F_45 ( V_3 ) -> V_66 , V_150 , V_149 ) ;
}
static T_7 F_178 ( unsigned int V_159 , char * V_59 )
{
const char * V_185 = L_11 ;
T_7 V_103 = 0 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < F_22 ( V_186 ) ; V_23 ++ )
if ( V_159 & ( 1 << V_23 ) ) {
V_103 += sprintf ( V_59 + V_103 , L_29 ,
V_185 , V_186 [ V_23 ] ) ;
V_185 = L_30 ;
}
if ( V_103 )
V_103 += sprintf ( V_59 + V_103 , L_15 ) ;
return V_103 ;
}
static T_7 F_179 ( struct V_67 * V_88 ,
struct V_114 * V_115 , char * V_59 )
{
struct V_2 * V_3 = F_81 ( V_88 ) ;
return F_178 ( V_3 -> V_159 , V_59 ) ;
}
static T_7 F_180 ( struct V_67 * V_88 ,
struct V_114 * V_115 , char * V_59 )
{
struct V_2 * V_3 = F_81 ( V_88 ) ;
return F_178 ( V_3 -> V_160 , V_59 ) ;
}
static T_7 F_181 ( struct V_67 * V_88 ,
struct V_114 * V_115 ,
char * V_59 )
{
struct V_2 * V_3 = F_81 ( V_88 ) ;
return sprintf ( V_59 , L_31 , V_3 -> V_156 -> V_158 ) ;
}
static T_7 F_182 ( struct V_67 * V_88 ,
struct V_114 * V_115 ,
const char * V_59 , T_8 V_187 )
{
struct V_2 * V_3 = F_81 ( V_88 ) ;
long V_168 ;
if ( ! V_187 || ! sscanf ( V_59 , L_32 , & V_168 ) )
return - V_122 ;
if ( V_168 < 0 && V_168 != - 1 )
return - V_122 ;
F_161 ( V_3 ) ;
V_3 -> V_156 -> V_158 = V_168 ;
F_165 ( V_3 , true ) ;
return V_187 ;
}
static int F_183 ( const char * V_188 ,
const struct V_189 * V_190 )
{
struct V_155 * V_156 ;
int V_40 ;
V_40 = F_184 ( V_188 , V_190 ) ;
if ( V_40 < 0 )
return V_40 ;
F_18 ( & V_191 ) ;
F_185 (ev, &disk_events, node)
F_170 ( V_156 -> V_3 ) ;
F_20 ( & V_191 ) ;
return 0 ;
}
static void F_67 ( struct V_2 * V_3 )
{
struct V_155 * V_156 ;
if ( ! V_3 -> V_145 -> V_184 )
return;
V_156 = F_186 ( sizeof( * V_156 ) , V_43 ) ;
if ( ! V_156 ) {
F_187 ( L_33 , V_3 -> V_74 ) ;
return;
}
if ( F_188 ( & F_45 ( V_3 ) -> V_66 ,
V_192 ) < 0 ) {
F_187 ( L_34 ,
V_3 -> V_74 ) ;
F_26 ( V_156 ) ;
return;
}
V_3 -> V_156 = V_156 ;
F_189 ( & V_156 -> V_193 ) ;
V_156 -> V_3 = V_3 ;
F_190 ( & V_156 -> V_164 ) ;
F_191 ( & V_156 -> V_163 ) ;
V_156 -> V_165 = 1 ;
V_156 -> V_158 = - 1 ;
F_192 ( & V_156 -> V_166 , F_176 ) ;
F_18 ( & V_191 ) ;
F_193 ( & V_156 -> V_193 , & V_155 ) ;
F_20 ( & V_191 ) ;
F_165 ( V_3 , true ) ;
}
static void F_69 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_156 )
return;
F_161 ( V_3 ) ;
F_18 ( & V_191 ) ;
F_194 ( & V_3 -> V_156 -> V_193 ) ;
F_20 ( & V_191 ) ;
F_195 ( & F_45 ( V_3 ) -> V_66 , V_192 ) ;
}
static void F_125 ( struct V_2 * V_3 )
{
F_166 ( V_3 -> V_156 && V_3 -> V_156 -> V_165 != 1 ) ;
F_26 ( V_3 -> V_156 ) ;
}
