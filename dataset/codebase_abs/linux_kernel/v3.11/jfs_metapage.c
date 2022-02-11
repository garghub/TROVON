static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , & V_2 -> V_4 ) ;
F_3 ( & V_2 -> V_5 ) ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_5 , V_6 ) ;
F_6 ( V_7 . V_8 ) ;
F_7 ( & V_2 -> V_5 , & V_5 ) ;
do {
F_8 ( V_9 ) ;
if ( F_9 ( V_2 ) ) {
F_10 ( V_2 -> V_10 ) ;
F_11 () ;
F_12 ( V_2 -> V_10 ) ;
}
} while ( F_13 ( V_2 ) );
F_14 ( V_11 ) ;
F_15 ( & V_2 -> V_5 , & V_5 ) ;
}
static inline void F_16 ( struct V_1 * V_2 )
{
if ( F_13 ( V_2 ) )
F_4 ( V_2 ) ;
}
static inline struct V_1 * F_17 ( struct V_10 * V_10 , int V_12 )
{
if ( ! F_18 ( V_10 ) )
return NULL ;
return F_19 ( V_10 ) -> V_2 [ V_12 >> V_13 ] ;
}
static inline int F_20 ( struct V_10 * V_10 , struct V_1 * V_2 )
{
struct V_14 * V_15 ;
int V_16 ;
int V_17 ;
if ( F_18 ( V_10 ) )
V_15 = F_19 ( V_10 ) ;
else {
V_15 = F_21 ( sizeof( struct V_14 ) , V_18 ) ;
if ( ! V_15 )
return - V_19 ;
F_22 ( V_10 , ( unsigned long ) V_15 ) ;
F_23 ( V_10 ) ;
F_24 ( V_10 ) ;
}
if ( V_2 ) {
V_17 = V_13 - V_10 -> V_20 -> V_21 -> V_22 ;
V_16 = ( V_2 -> V_16 >> V_17 ) & ( V_23 - 1 ) ;
V_15 -> V_24 ++ ;
V_15 -> V_2 [ V_16 ] = V_2 ;
}
return 0 ;
}
static inline void F_25 ( struct V_10 * V_10 , struct V_1 * V_2 )
{
struct V_14 * V_15 = F_19 ( V_10 ) ;
int V_17 = V_13 - V_10 -> V_20 -> V_21 -> V_22 ;
int V_16 ;
V_16 = ( V_2 -> V_16 >> V_17 ) & ( V_23 - 1 ) ;
F_26 ( V_15 -> V_2 [ V_16 ] != V_2 ) ;
V_15 -> V_2 [ V_16 ] = NULL ;
if ( -- V_15 -> V_24 == 0 ) {
F_27 ( V_15 ) ;
F_22 ( V_10 , 0 ) ;
F_28 ( V_10 ) ;
F_29 ( V_10 ) ;
}
}
static inline void F_30 ( struct V_10 * V_10 )
{
F_31 ( & F_19 ( V_10 ) -> V_25 ) ;
}
static inline void F_32 ( struct V_10 * V_10 , void (* F_33) ( struct V_10 * ) )
{
if ( F_34 ( & F_19 ( V_10 ) -> V_25 ) )
F_33 ( V_10 ) ;
}
static inline struct V_1 * F_17 ( struct V_10 * V_10 , int V_12 )
{
return F_18 ( V_10 ) ? (struct V_1 * ) F_35 ( V_10 ) : NULL ;
}
static inline int F_20 ( struct V_10 * V_10 , struct V_1 * V_2 )
{
if ( V_2 ) {
F_22 ( V_10 , ( unsigned long ) V_2 ) ;
F_23 ( V_10 ) ;
F_24 ( V_10 ) ;
}
return 0 ;
}
static inline void F_25 ( struct V_10 * V_10 , struct V_1 * V_2 )
{
F_22 ( V_10 , 0 ) ;
F_28 ( V_10 ) ;
F_29 ( V_10 ) ;
}
static void F_36 ( void * V_26 )
{
struct V_1 * V_2 = (struct V_1 * ) V_26 ;
V_2 -> V_27 = 0 ;
V_2 -> V_28 = 0 ;
V_2 -> V_4 = 0 ;
V_2 -> V_29 = NULL ;
V_2 -> V_30 = 0 ;
V_2 -> log = NULL ;
F_37 ( V_31 , & V_2 -> V_4 ) ;
F_38 ( & V_2 -> V_5 ) ;
}
static inline struct V_1 * F_39 ( T_1 V_32 )
{
return F_40 ( V_33 , V_32 ) ;
}
static inline void F_41 ( struct V_1 * V_2 )
{
V_2 -> V_4 = 0 ;
F_37 ( V_31 , & V_2 -> V_4 ) ;
F_42 ( V_2 , V_33 ) ;
}
int T_2 F_43 ( void )
{
V_34 = F_44 ( L_1 , sizeof( struct V_1 ) ,
0 , 0 , F_36 ) ;
if ( V_34 == NULL )
return - V_19 ;
V_33 = F_45 ( V_35 ,
V_34 ) ;
if ( V_33 == NULL ) {
F_46 ( V_34 ) ;
return - V_19 ;
}
return 0 ;
}
void F_47 ( void )
{
F_48 ( V_33 ) ;
F_46 ( V_34 ) ;
}
static inline void F_49 ( struct V_10 * V_10 , struct V_1 * V_2 )
{
if ( V_2 -> V_36 || V_2 -> V_37 || F_50 ( V_38 , & V_2 -> V_4 ) ||
F_50 ( V_39 , & V_2 -> V_4 ) )
return;
F_25 ( V_10 , V_2 ) ;
F_6 ( V_7 . V_40 ) ;
F_41 ( V_2 ) ;
}
static T_3 F_51 ( struct V_41 * V_41 , T_3 V_42 ,
int * V_43 )
{
int V_44 = 0 ;
int V_45 ;
T_4 V_46 ;
T_3 V_47 = ( V_41 -> V_48 + V_41 -> V_49 -> V_50 - 1 ) >>
V_41 -> V_22 ;
if ( V_42 >= V_47 )
return 0 ;
if ( V_42 + * V_43 > V_47 )
* V_43 = V_47 - V_42 ;
if ( V_41 -> V_51 ) {
V_44 = F_52 ( V_41 , ( T_4 ) V_42 , * V_43 , & V_45 , & V_46 , V_43 , 0 ) ;
if ( ( V_44 == 0 ) && * V_43 )
V_42 = ( T_3 ) V_46 ;
else
V_42 = 0 ;
}
return V_42 ;
}
static void F_53 ( struct V_10 * V_10 )
{
if ( ! F_54 ( V_10 ) )
F_55 ( V_10 ) ;
F_10 ( V_10 ) ;
}
static void F_56 ( struct V_52 * V_52 , int V_53 )
{
struct V_10 * V_10 = V_52 -> V_54 ;
if ( ! F_50 ( V_55 , & V_52 -> V_56 ) ) {
F_57 ( V_57 L_2 ) ;
F_58 ( V_10 ) ;
}
F_32 ( V_10 , F_53 ) ;
F_59 ( V_52 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_58 * log = V_2 -> log ;
unsigned long V_59 ;
if ( ! log )
return;
F_61 ( log , V_59 ) ;
if ( V_2 -> V_28 ) {
V_2 -> log = NULL ;
V_2 -> V_28 = 0 ;
V_2 -> V_30 = 0 ;
log -> V_36 -- ;
F_62 ( & V_2 -> V_60 ) ;
}
F_63 ( log , V_59 ) ;
}
static void F_64 ( struct V_10 * V_10 )
{
struct V_1 * V_2 ;
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < V_61 ; V_12 += V_62 ) {
V_2 = F_17 ( V_10 , V_12 ) ;
if ( V_2 && F_50 ( V_39 , & V_2 -> V_4 ) ) {
if ( V_2 -> V_28 )
F_60 ( V_2 ) ;
F_65 ( V_39 , & V_2 -> V_4 ) ;
}
}
F_66 ( V_10 ) ;
}
static void F_67 ( struct V_52 * V_52 , int V_53 )
{
struct V_10 * V_10 = V_52 -> V_54 ;
F_26 ( ! F_18 ( V_10 ) ) ;
if ( ! F_50 ( V_55 , & V_52 -> V_56 ) ) {
F_57 ( V_57 L_3 ) ;
F_58 ( V_10 ) ;
}
F_32 ( V_10 , F_64 ) ;
F_59 ( V_52 ) ;
}
static int F_68 ( struct V_10 * V_10 , struct V_63 * V_64 )
{
struct V_52 * V_52 = NULL ;
int V_65 ;
struct V_41 * V_41 = V_10 -> V_20 -> V_21 ;
int V_66 = F_69 ( V_41 -> V_49 ) -> V_67 ;
int V_43 ;
int V_68 ;
struct V_1 * V_2 ;
int V_69 = 0 ;
T_3 V_42 ;
int V_70 = 0 ;
T_3 V_71 ;
T_3 V_72 = 0 ;
T_3 V_73 ;
unsigned long V_74 = 0 ;
unsigned long V_75 = 0 ;
int V_12 ;
int V_76 = 0 ;
V_73 = ( T_3 ) V_10 -> V_16 <<
( V_77 - V_41 -> V_22 ) ;
F_26 ( ! F_70 ( V_10 ) ) ;
F_26 ( F_71 ( V_10 ) ) ;
F_72 ( V_10 ) ;
for ( V_12 = 0 ; V_12 < V_61 ; V_12 += V_62 ) {
V_2 = F_17 ( V_10 , V_12 ) ;
if ( ! V_2 || ! F_50 ( V_38 , & V_2 -> V_4 ) )
continue;
if ( V_2 -> V_37 && ! F_50 ( V_78 , & V_2 -> V_4 ) ) {
V_69 = 1 ;
if ( V_2 -> log && ! ( V_2 -> log -> V_79 & V_80 ) )
F_73 ( V_2 -> log , 0 ) ;
continue;
}
F_65 ( V_38 , & V_2 -> V_4 ) ;
F_37 ( V_39 , & V_2 -> V_4 ) ;
V_65 = V_12 >> V_41 -> V_22 ;
V_42 = V_73 + V_65 ;
if ( V_52 ) {
if ( V_68 && V_42 == V_72 ) {
V_43 = F_74 ( V_68 , V_66 ) ;
V_68 -= V_43 ;
V_74 += V_43 << V_41 -> V_22 ;
continue;
}
if ( F_75 ( V_52 , V_10 , V_74 , V_75 ) <
V_74 )
goto V_81;
F_30 ( V_10 ) ;
if ( ! V_52 -> V_82 )
goto V_83;
F_76 ( V_84 , V_52 ) ;
V_70 ++ ;
V_52 = NULL ;
} else
F_30 ( V_10 ) ;
V_68 = ( V_61 - V_12 ) >> V_41 -> V_22 ;
V_71 = F_51 ( V_41 , V_42 , & V_68 ) ;
if ( ! V_71 ) {
F_57 ( V_57 L_4 ) ;
V_76 ++ ;
continue;
}
V_43 = F_74 ( V_68 , ( int ) F_69 ( V_41 -> V_49 ) -> V_67 ) ;
V_52 = F_77 ( V_18 , 1 ) ;
V_52 -> V_85 = V_41 -> V_49 -> V_86 ;
V_52 -> V_87 = V_71 << ( V_41 -> V_22 - 9 ) ;
V_52 -> V_88 = F_67 ;
V_52 -> V_54 = V_10 ;
V_75 = V_12 ;
V_74 = V_43 << V_41 -> V_22 ;
V_68 -= V_43 ;
V_72 = V_42 + V_43 ;
}
if ( V_52 ) {
if ( F_75 ( V_52 , V_10 , V_74 , V_75 ) < V_74 )
goto V_81;
if ( ! V_52 -> V_82 )
goto V_83;
F_76 ( V_84 , V_52 ) ;
V_70 ++ ;
}
if ( V_69 )
F_78 ( V_64 , V_10 ) ;
F_10 ( V_10 ) ;
if ( V_76 )
goto V_89;
if ( V_70 == 0 )
F_66 ( V_10 ) ;
return 0 ;
V_81:
F_57 ( V_57 L_5 ) ;
goto V_90;
V_83:
F_79 ( V_57 , L_6 , V_91 , 16 ,
4 , V_52 , sizeof( * V_52 ) , 0 ) ;
V_90:
F_59 ( V_52 ) ;
F_10 ( V_10 ) ;
F_32 ( V_10 , F_64 ) ;
V_89:
while ( V_76 -- )
F_32 ( V_10 , F_64 ) ;
return - V_92 ;
}
static int F_80 ( struct V_93 * V_94 , struct V_10 * V_10 )
{
struct V_41 * V_41 = V_10 -> V_20 -> V_21 ;
struct V_52 * V_52 = NULL ;
int V_65 ;
int V_95 = V_61 >> V_41 -> V_22 ;
T_3 V_73 ;
T_3 V_71 ;
int V_68 ;
unsigned int V_43 ;
int V_12 ;
F_26 ( ! F_70 ( V_10 ) ) ;
V_73 = ( T_3 ) V_10 -> V_16 <<
( V_77 - V_41 -> V_22 ) ;
V_65 = 0 ;
while ( V_65 < V_95 ) {
V_68 = V_95 - V_65 ;
V_71 = F_51 ( V_41 , V_73 + V_65 ,
& V_68 ) ;
if ( V_71 ) {
if ( ! F_18 ( V_10 ) )
F_20 ( V_10 , NULL ) ;
F_30 ( V_10 ) ;
if ( V_52 )
F_76 ( V_96 , V_52 ) ;
V_52 = F_77 ( V_18 , 1 ) ;
V_52 -> V_85 = V_41 -> V_49 -> V_86 ;
V_52 -> V_87 = V_71 << ( V_41 -> V_22 - 9 ) ;
V_52 -> V_88 = F_56 ;
V_52 -> V_54 = V_10 ;
V_43 = V_68 << V_41 -> V_22 ;
V_12 = V_65 << V_41 -> V_22 ;
if ( F_75 ( V_52 , V_10 , V_43 , V_12 ) < V_43 )
goto V_81;
V_65 += V_68 ;
} else
V_65 ++ ;
}
if ( V_52 )
F_76 ( V_96 , V_52 ) ;
else
F_10 ( V_10 ) ;
return 0 ;
V_81:
F_57 ( V_57 L_5 ) ;
F_59 ( V_52 ) ;
F_32 ( V_10 , F_53 ) ;
return - V_92 ;
}
static int F_81 ( struct V_10 * V_10 , T_1 V_32 )
{
struct V_1 * V_2 ;
int V_97 = 1 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_61 ; V_12 += V_62 ) {
V_2 = F_17 ( V_10 , V_12 ) ;
if ( ! V_2 )
continue;
F_82 ( L_7 , V_2 ) ;
if ( V_2 -> V_36 || V_2 -> V_37 ||
F_50 ( V_38 , & V_2 -> V_4 ) ) {
F_82 ( L_8 , V_2 -> V_36 ,
V_2 -> V_37 ) ;
V_97 = 0 ;
continue;
}
if ( V_2 -> V_28 )
F_60 ( V_2 ) ;
F_25 ( V_10 , V_2 ) ;
F_6 ( V_7 . V_40 ) ;
F_41 ( V_2 ) ;
}
return V_97 ;
}
static void F_83 ( struct V_10 * V_10 , unsigned int V_12 ,
unsigned int V_98 )
{
F_26 ( V_12 || V_98 < V_61 ) ;
F_26 ( F_71 ( V_10 ) ) ;
F_81 ( V_10 , 0 ) ;
}
struct V_1 * F_84 ( struct V_41 * V_41 , unsigned long V_42 ,
unsigned int V_99 , int V_100 ,
unsigned long V_101 )
{
int V_102 ;
int V_103 ;
struct V_104 * V_20 ;
struct V_1 * V_2 = NULL ;
struct V_10 * V_10 ;
unsigned long V_105 ;
unsigned long V_106 ;
F_82 ( L_9 ,
V_41 -> V_51 , V_42 , V_100 ) ;
V_103 = V_41 -> V_22 ;
V_102 = V_77 - V_103 ;
V_105 = V_42 >> V_102 ;
V_106 = ( V_42 - ( V_105 << V_102 ) ) << V_103 ;
if ( ( V_106 + V_99 ) > V_61 ) {
F_85 ( L_10 ) ;
F_85 ( L_11 , V_42 , V_99 ) ;
F_86 () ;
return NULL ;
}
if ( V_100 )
V_20 = F_69 ( V_41 -> V_49 ) -> V_107 -> V_108 ;
else {
if ( ( V_42 << V_41 -> V_22 ) >= V_41 -> V_48 )
return NULL ;
V_20 = V_41 -> V_108 ;
}
if ( V_101 && ( V_62 == V_61 ) ) {
V_10 = F_87 ( V_20 , V_105 ) ;
if ( ! V_10 ) {
F_85 ( L_12 ) ;
return NULL ;
}
F_55 ( V_10 ) ;
} else {
V_10 = F_88 ( V_20 , V_105 , NULL ) ;
if ( F_89 ( V_10 ) || ! F_90 ( V_10 ) ) {
F_85 ( L_13 ) ;
return NULL ;
}
F_12 ( V_10 ) ;
}
V_2 = F_17 ( V_10 , V_106 ) ;
if ( V_2 ) {
if ( V_2 -> V_109 != V_99 ) {
F_91 ( V_41 -> V_49 ,
L_14 ) ;
F_85 ( L_15 ,
V_2 -> V_109 , V_99 ) ;
F_86 () ;
goto V_110;
}
V_2 -> V_36 ++ ;
F_16 ( V_2 ) ;
if ( F_50 ( V_111 , & V_2 -> V_4 ) ) {
if ( ! V_101 ) {
F_91 ( V_41 -> V_49 ,
L_16 ) ;
F_92 ( V_2 ) ;
goto V_110;
}
F_65 ( V_111 , & V_2 -> V_4 ) ;
}
} else {
F_6 ( V_7 . V_112 ) ;
V_2 = F_39 ( V_18 ) ;
V_2 -> V_10 = V_10 ;
V_2 -> V_4 = 0 ;
V_2 -> V_45 = V_113 ;
V_2 -> V_36 = 1 ;
V_2 -> V_37 = 0 ;
V_2 -> V_109 = V_99 ;
V_2 -> V_29 = F_93 ( V_10 ) + V_106 ;
V_2 -> V_16 = V_42 ;
if ( F_94 ( F_20 ( V_10 , V_2 ) ) ) {
F_41 ( V_2 ) ;
goto V_110;
}
F_16 ( V_2 ) ;
}
if ( V_101 ) {
F_82 ( L_17 , V_2 ) ;
memset ( V_2 -> V_29 , 0 , V_62 ) ;
}
F_10 ( V_10 ) ;
F_82 ( L_18 , V_2 , V_2 -> V_29 ) ;
return V_2 ;
V_110:
F_10 ( V_10 ) ;
return NULL ;
}
void F_95 ( struct V_1 * V_2 )
{
F_82 ( L_19 , V_2 ) ;
F_96 ( V_2 -> V_10 ) ;
F_12 ( V_2 -> V_10 ) ;
V_2 -> V_36 ++ ;
F_16 ( V_2 ) ;
F_10 ( V_2 -> V_10 ) ;
}
void F_97 ( struct V_1 * V_2 )
{
struct V_10 * V_10 = V_2 -> V_10 ;
F_82 ( L_20 , V_2 ) ;
F_37 ( V_78 , & V_2 -> V_4 ) ;
F_65 ( V_114 , & V_2 -> V_4 ) ;
F_96 ( V_10 ) ;
F_12 ( V_10 ) ;
F_98 ( V_10 ) ;
F_99 ( V_10 , 1 ) ;
F_65 ( V_78 , & V_2 -> V_4 ) ;
F_100 ( V_10 ) ;
}
void F_101 ( struct V_1 * V_2 )
{
F_12 ( V_2 -> V_10 ) ;
}
void F_102 ( struct V_1 * V_2 )
{
if ( V_2 -> V_36 || V_2 -> V_37 ) {
F_10 ( V_2 -> V_10 ) ;
return;
}
F_96 ( V_2 -> V_10 ) ;
V_2 -> V_36 ++ ;
F_16 ( V_2 ) ;
F_10 ( V_2 -> V_10 ) ;
F_103 ( V_2 ) ;
}
void F_103 ( struct V_1 * V_2 )
{
struct V_10 * V_10 = V_2 -> V_10 ;
F_82 ( L_21 , V_2 , V_2 -> V_4 ) ;
F_26 ( ! V_10 ) ;
F_12 ( V_10 ) ;
F_1 ( V_2 ) ;
assert ( V_2 -> V_36 ) ;
if ( -- V_2 -> V_36 || V_2 -> V_37 ) {
F_10 ( V_10 ) ;
F_100 ( V_10 ) ;
return;
}
if ( F_50 ( V_38 , & V_2 -> V_4 ) ) {
F_98 ( V_10 ) ;
if ( F_50 ( V_114 , & V_2 -> V_4 ) ) {
F_65 ( V_114 , & V_2 -> V_4 ) ;
F_99 ( V_10 , 1 ) ;
F_12 ( V_10 ) ;
}
} else if ( V_2 -> V_28 )
F_60 ( V_2 ) ;
F_49 ( V_10 , V_2 ) ;
F_10 ( V_10 ) ;
F_100 ( V_10 ) ;
}
void F_104 ( struct V_41 * V_115 , T_4 V_116 , int V_43 )
{
T_3 V_42 ;
int V_102 = V_77 - V_115 -> V_22 ;
int V_117 = 1 << V_102 ;
struct V_104 * V_20 =
F_69 ( V_115 -> V_49 ) -> V_107 -> V_108 ;
struct V_1 * V_2 ;
struct V_10 * V_10 ;
unsigned int V_12 ;
for ( V_42 = V_116 & ~ ( V_117 - 1 ) ; V_42 < V_116 + V_43 ;
V_42 += V_117 ) {
V_10 = F_105 ( V_20 , V_42 >> V_102 ) ;
if ( ! V_10 )
continue;
for ( V_12 = 0 ; V_12 < V_61 ; V_12 += V_62 ) {
V_2 = F_17 ( V_10 , V_12 ) ;
if ( ! V_2 )
continue;
if ( V_2 -> V_16 < V_116 )
continue;
if ( V_2 -> V_16 >= V_116 + V_43 )
break;
F_65 ( V_38 , & V_2 -> V_4 ) ;
F_37 ( V_111 , & V_2 -> V_4 ) ;
if ( V_2 -> V_28 )
F_60 ( V_2 ) ;
}
F_10 ( V_10 ) ;
F_100 ( V_10 ) ;
}
}
static int F_106 ( struct V_118 * V_119 , void * V_120 )
{
F_107 ( V_119 ,
L_22
L_23
L_24
L_25
L_26 ,
V_7 . V_112 ,
V_7 . V_40 ,
V_7 . V_8 ) ;
return 0 ;
}
static int F_108 ( struct V_41 * V_41 , struct V_93 * V_93 )
{
return F_109 ( V_93 , F_106 , NULL ) ;
}
