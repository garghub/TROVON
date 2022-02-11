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
static inline struct V_1 * F_36 ( T_1 V_26 )
{
struct V_1 * V_2 = F_37 ( V_27 , V_26 ) ;
if ( V_2 ) {
V_2 -> V_28 = 0 ;
V_2 -> V_29 = 0 ;
V_2 -> V_30 = NULL ;
V_2 -> V_31 = 0 ;
V_2 -> log = NULL ;
F_38 ( & V_2 -> V_5 ) ;
}
return V_2 ;
}
static inline void F_39 ( struct V_1 * V_2 )
{
F_40 ( V_2 , V_27 ) ;
}
int T_2 F_41 ( void )
{
V_32 = F_42 ( L_1 , sizeof( struct V_1 ) ,
0 , 0 , NULL ) ;
if ( V_32 == NULL )
return - V_19 ;
V_27 = F_43 ( V_33 ,
V_32 ) ;
if ( V_27 == NULL ) {
F_44 ( V_32 ) ;
return - V_19 ;
}
return 0 ;
}
void F_45 ( void )
{
F_46 ( V_27 ) ;
F_44 ( V_32 ) ;
}
static inline void F_47 ( struct V_10 * V_10 , struct V_1 * V_2 )
{
if ( V_2 -> V_34 || V_2 -> V_35 || F_48 ( V_36 , & V_2 -> V_4 ) ||
F_48 ( V_37 , & V_2 -> V_4 ) )
return;
F_25 ( V_10 , V_2 ) ;
F_6 ( V_7 . V_38 ) ;
F_39 ( V_2 ) ;
}
static T_3 F_49 ( struct V_39 * V_39 , T_3 V_40 ,
int * V_41 )
{
int V_42 = 0 ;
int V_43 ;
T_4 V_44 ;
T_3 V_45 = ( V_39 -> V_46 + V_39 -> V_47 -> V_48 - 1 ) >>
V_39 -> V_22 ;
if ( V_40 >= V_45 )
return 0 ;
if ( V_40 + * V_41 > V_45 )
* V_41 = V_45 - V_40 ;
if ( V_39 -> V_49 ) {
V_42 = F_50 ( V_39 , ( T_4 ) V_40 , * V_41 , & V_43 , & V_44 , V_41 , 0 ) ;
if ( ( V_42 == 0 ) && * V_41 )
V_40 = ( T_3 ) V_44 ;
else
V_40 = 0 ;
}
return V_40 ;
}
static void F_51 ( struct V_10 * V_10 )
{
if ( ! F_52 ( V_10 ) )
F_53 ( V_10 ) ;
F_10 ( V_10 ) ;
}
static void F_54 ( struct V_50 * V_50 )
{
struct V_10 * V_10 = V_50 -> V_51 ;
if ( V_50 -> V_52 ) {
F_55 ( V_53 L_2 ) ;
F_56 ( V_10 ) ;
}
F_32 ( V_10 , F_51 ) ;
F_57 ( V_50 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_54 * log = V_2 -> log ;
unsigned long V_55 ;
if ( ! log )
return;
F_59 ( log , V_55 ) ;
if ( V_2 -> V_29 ) {
V_2 -> log = NULL ;
V_2 -> V_29 = 0 ;
V_2 -> V_31 = 0 ;
log -> V_34 -- ;
F_60 ( & V_2 -> V_56 ) ;
}
F_61 ( log , V_55 ) ;
}
static void F_62 ( struct V_10 * V_10 )
{
struct V_1 * V_2 ;
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < V_57 ; V_12 += V_58 ) {
V_2 = F_17 ( V_10 , V_12 ) ;
if ( V_2 && F_48 ( V_37 , & V_2 -> V_4 ) ) {
if ( V_2 -> V_29 )
F_58 ( V_2 ) ;
F_63 ( V_37 , & V_2 -> V_4 ) ;
}
}
F_64 ( V_10 ) ;
}
static void F_65 ( struct V_50 * V_50 )
{
struct V_10 * V_10 = V_50 -> V_51 ;
F_26 ( ! F_18 ( V_10 ) ) ;
if ( V_50 -> V_52 ) {
F_55 ( V_53 L_3 ) ;
F_56 ( V_10 ) ;
}
F_32 ( V_10 , F_62 ) ;
F_57 ( V_50 ) ;
}
static int F_66 ( struct V_10 * V_10 , struct V_59 * V_60 )
{
struct V_50 * V_50 = NULL ;
int V_61 ;
struct V_39 * V_39 = V_10 -> V_20 -> V_21 ;
int V_62 = F_67 ( V_39 -> V_47 ) -> V_63 ;
int V_41 ;
int V_64 ;
struct V_1 * V_2 ;
int V_65 = 0 ;
T_3 V_40 ;
int V_66 = 0 ;
T_3 V_67 ;
T_3 V_68 = 0 ;
T_3 V_69 ;
unsigned long V_70 = 0 ;
unsigned long V_71 = 0 ;
int V_12 ;
int V_72 = 0 ;
V_69 = ( T_3 ) V_10 -> V_16 <<
( V_73 - V_39 -> V_22 ) ;
F_26 ( ! F_68 ( V_10 ) ) ;
F_26 ( F_69 ( V_10 ) ) ;
F_70 ( V_10 ) ;
for ( V_12 = 0 ; V_12 < V_57 ; V_12 += V_58 ) {
V_2 = F_17 ( V_10 , V_12 ) ;
if ( ! V_2 || ! F_48 ( V_36 , & V_2 -> V_4 ) )
continue;
if ( V_2 -> V_35 && ! F_48 ( V_74 , & V_2 -> V_4 ) ) {
V_65 = 1 ;
if ( V_2 -> log && ! ( V_2 -> log -> V_75 & V_76 ) )
F_71 ( V_2 -> log , 0 ) ;
continue;
}
F_63 ( V_36 , & V_2 -> V_4 ) ;
F_72 ( V_37 , & V_2 -> V_4 ) ;
V_61 = V_12 >> V_39 -> V_22 ;
V_40 = V_69 + V_61 ;
if ( V_50 ) {
if ( V_64 && V_40 == V_68 ) {
V_41 = F_73 ( V_64 , V_62 ) ;
V_64 -= V_41 ;
V_70 += V_41 << V_39 -> V_22 ;
continue;
}
if ( F_74 ( V_50 , V_10 , V_70 , V_71 ) <
V_70 )
goto V_77;
F_30 ( V_10 ) ;
if ( ! V_50 -> V_78 . V_79 )
goto V_80;
F_75 ( V_50 ) ;
V_66 ++ ;
V_50 = NULL ;
} else
F_30 ( V_10 ) ;
V_64 = ( V_57 - V_12 ) >> V_39 -> V_22 ;
V_67 = F_49 ( V_39 , V_40 , & V_64 ) ;
if ( ! V_67 ) {
F_55 ( V_53 L_4 ) ;
V_72 ++ ;
continue;
}
V_41 = F_73 ( V_64 , ( int ) F_67 ( V_39 -> V_47 ) -> V_63 ) ;
V_50 = F_76 ( V_18 , 1 ) ;
F_77 ( V_50 , V_39 -> V_47 -> V_81 ) ;
V_50 -> V_78 . V_82 = V_67 << ( V_39 -> V_22 - 9 ) ;
V_50 -> V_83 = F_65 ;
V_50 -> V_51 = V_10 ;
F_78 ( V_50 , V_84 , 0 ) ;
V_71 = V_12 ;
V_70 = V_41 << V_39 -> V_22 ;
V_64 -= V_41 ;
V_68 = V_40 + V_41 ;
}
if ( V_50 ) {
if ( F_74 ( V_50 , V_10 , V_70 , V_71 ) < V_70 )
goto V_77;
if ( ! V_50 -> V_78 . V_79 )
goto V_80;
F_75 ( V_50 ) ;
V_66 ++ ;
}
if ( V_65 )
F_79 ( V_60 , V_10 ) ;
F_10 ( V_10 ) ;
if ( V_72 )
goto V_85;
if ( V_66 == 0 )
F_64 ( V_10 ) ;
return 0 ;
V_77:
F_55 ( V_53 L_5 ) ;
goto V_86;
V_80:
F_80 ( V_53 , L_6 , V_87 , 16 ,
4 , V_50 , sizeof( * V_50 ) , 0 ) ;
V_86:
F_57 ( V_50 ) ;
F_10 ( V_10 ) ;
F_32 ( V_10 , F_62 ) ;
V_85:
while ( V_72 -- )
F_32 ( V_10 , F_62 ) ;
return - V_88 ;
}
static int F_81 ( struct V_89 * V_90 , struct V_10 * V_10 )
{
struct V_39 * V_39 = V_10 -> V_20 -> V_21 ;
struct V_50 * V_50 = NULL ;
int V_61 ;
int V_91 = V_57 >> V_39 -> V_22 ;
T_3 V_69 ;
T_3 V_67 ;
int V_64 ;
unsigned int V_41 ;
int V_12 ;
F_26 ( ! F_68 ( V_10 ) ) ;
V_69 = ( T_3 ) V_10 -> V_16 <<
( V_73 - V_39 -> V_22 ) ;
V_61 = 0 ;
while ( V_61 < V_91 ) {
V_64 = V_91 - V_61 ;
V_67 = F_49 ( V_39 , V_69 + V_61 ,
& V_64 ) ;
if ( V_67 ) {
if ( ! F_18 ( V_10 ) )
F_20 ( V_10 , NULL ) ;
F_30 ( V_10 ) ;
if ( V_50 )
F_75 ( V_50 ) ;
V_50 = F_76 ( V_18 , 1 ) ;
F_77 ( V_50 , V_39 -> V_47 -> V_81 ) ;
V_50 -> V_78 . V_82 =
V_67 << ( V_39 -> V_22 - 9 ) ;
V_50 -> V_83 = F_54 ;
V_50 -> V_51 = V_10 ;
F_78 ( V_50 , V_92 , 0 ) ;
V_41 = V_64 << V_39 -> V_22 ;
V_12 = V_61 << V_39 -> V_22 ;
if ( F_74 ( V_50 , V_10 , V_41 , V_12 ) < V_41 )
goto V_77;
V_61 += V_64 ;
} else
V_61 ++ ;
}
if ( V_50 )
F_75 ( V_50 ) ;
else
F_10 ( V_10 ) ;
return 0 ;
V_77:
F_55 ( V_53 L_5 ) ;
F_57 ( V_50 ) ;
F_32 ( V_10 , F_51 ) ;
return - V_88 ;
}
static int F_82 ( struct V_10 * V_10 , T_1 V_26 )
{
struct V_1 * V_2 ;
int V_93 = 1 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_57 ; V_12 += V_58 ) {
V_2 = F_17 ( V_10 , V_12 ) ;
if ( ! V_2 )
continue;
F_83 ( L_7 , V_2 ) ;
if ( V_2 -> V_34 || V_2 -> V_35 ||
F_48 ( V_36 , & V_2 -> V_4 ) ) {
F_83 ( L_8 , V_2 -> V_34 ,
V_2 -> V_35 ) ;
V_93 = 0 ;
continue;
}
if ( V_2 -> V_29 )
F_58 ( V_2 ) ;
F_25 ( V_10 , V_2 ) ;
F_6 ( V_7 . V_38 ) ;
F_39 ( V_2 ) ;
}
return V_93 ;
}
static void F_84 ( struct V_10 * V_10 , unsigned int V_12 ,
unsigned int V_94 )
{
F_26 ( V_12 || V_94 < V_57 ) ;
F_26 ( F_69 ( V_10 ) ) ;
F_82 ( V_10 , 0 ) ;
}
struct V_1 * F_85 ( struct V_39 * V_39 , unsigned long V_40 ,
unsigned int V_95 , int V_96 ,
unsigned long V_97 )
{
int V_98 ;
int V_99 ;
struct V_100 * V_20 ;
struct V_1 * V_2 = NULL ;
struct V_10 * V_10 ;
unsigned long V_101 ;
unsigned long V_102 ;
F_83 ( L_9 ,
V_39 -> V_49 , V_40 , V_96 ) ;
V_99 = V_39 -> V_22 ;
V_98 = V_73 - V_99 ;
V_101 = V_40 >> V_98 ;
V_102 = ( V_40 - ( V_101 << V_98 ) ) << V_99 ;
if ( ( V_102 + V_95 ) > V_57 ) {
F_86 ( L_10 ) ;
F_86 ( L_11 , V_40 , V_95 ) ;
F_87 () ;
return NULL ;
}
if ( V_96 )
V_20 = F_67 ( V_39 -> V_47 ) -> V_103 -> V_104 ;
else {
if ( ( V_40 << V_39 -> V_22 ) >= V_39 -> V_46 )
return NULL ;
V_20 = V_39 -> V_104 ;
}
if ( V_97 && ( V_58 == V_57 ) ) {
V_10 = F_88 ( V_20 , V_101 ) ;
if ( ! V_10 ) {
F_86 ( L_12 ) ;
return NULL ;
}
F_53 ( V_10 ) ;
} else {
V_10 = F_89 ( V_20 , V_101 , NULL ) ;
if ( F_90 ( V_10 ) || ! F_91 ( V_10 ) ) {
F_86 ( L_13 ) ;
return NULL ;
}
F_12 ( V_10 ) ;
}
V_2 = F_17 ( V_10 , V_102 ) ;
if ( V_2 ) {
if ( V_2 -> V_105 != V_95 ) {
F_92 ( V_39 -> V_47 ,
L_14 ) ;
F_86 ( L_15 ,
V_2 -> V_105 , V_95 ) ;
F_87 () ;
goto V_106;
}
V_2 -> V_34 ++ ;
F_16 ( V_2 ) ;
if ( F_48 ( V_107 , & V_2 -> V_4 ) ) {
if ( ! V_97 ) {
F_92 ( V_39 -> V_47 ,
L_16 ) ;
F_93 ( V_2 ) ;
goto V_106;
}
F_63 ( V_107 , & V_2 -> V_4 ) ;
}
} else {
F_6 ( V_7 . V_108 ) ;
V_2 = F_36 ( V_18 ) ;
V_2 -> V_10 = V_10 ;
V_2 -> V_109 = V_39 -> V_47 ;
V_2 -> V_4 = 0 ;
V_2 -> V_43 = V_110 ;
V_2 -> V_34 = 1 ;
V_2 -> V_35 = 0 ;
V_2 -> V_105 = V_95 ;
V_2 -> V_30 = F_94 ( V_10 ) + V_102 ;
V_2 -> V_16 = V_40 ;
if ( F_95 ( F_20 ( V_10 , V_2 ) ) ) {
F_39 ( V_2 ) ;
goto V_106;
}
F_16 ( V_2 ) ;
}
if ( V_97 ) {
F_83 ( L_17 , V_2 ) ;
memset ( V_2 -> V_30 , 0 , V_58 ) ;
}
F_10 ( V_10 ) ;
F_83 ( L_18 , V_2 , V_2 -> V_30 ) ;
return V_2 ;
V_106:
F_10 ( V_10 ) ;
return NULL ;
}
void F_96 ( struct V_1 * V_2 )
{
F_83 ( L_19 , V_2 ) ;
F_97 ( V_2 -> V_10 ) ;
F_12 ( V_2 -> V_10 ) ;
V_2 -> V_34 ++ ;
F_16 ( V_2 ) ;
F_10 ( V_2 -> V_10 ) ;
}
void F_98 ( struct V_1 * V_2 )
{
struct V_10 * V_10 = V_2 -> V_10 ;
F_83 ( L_20 , V_2 ) ;
F_72 ( V_74 , & V_2 -> V_4 ) ;
F_63 ( V_111 , & V_2 -> V_4 ) ;
F_97 ( V_10 ) ;
F_12 ( V_10 ) ;
F_99 ( V_10 ) ;
if ( F_100 ( V_10 ) )
F_92 ( V_2 -> V_109 , L_21 ) ;
F_63 ( V_74 , & V_2 -> V_4 ) ;
F_101 ( V_10 ) ;
}
void F_102 ( struct V_1 * V_2 )
{
F_12 ( V_2 -> V_10 ) ;
}
void F_103 ( struct V_1 * V_2 )
{
if ( V_2 -> V_34 || V_2 -> V_35 ) {
F_10 ( V_2 -> V_10 ) ;
return;
}
F_97 ( V_2 -> V_10 ) ;
V_2 -> V_34 ++ ;
F_16 ( V_2 ) ;
F_10 ( V_2 -> V_10 ) ;
F_104 ( V_2 ) ;
}
void F_104 ( struct V_1 * V_2 )
{
struct V_10 * V_10 = V_2 -> V_10 ;
F_83 ( L_22 , V_2 , V_2 -> V_4 ) ;
F_26 ( ! V_10 ) ;
F_12 ( V_10 ) ;
F_1 ( V_2 ) ;
assert ( V_2 -> V_34 ) ;
if ( -- V_2 -> V_34 || V_2 -> V_35 ) {
F_10 ( V_10 ) ;
F_101 ( V_10 ) ;
return;
}
if ( F_48 ( V_36 , & V_2 -> V_4 ) ) {
F_99 ( V_10 ) ;
if ( F_48 ( V_111 , & V_2 -> V_4 ) ) {
F_63 ( V_111 , & V_2 -> V_4 ) ;
if ( F_100 ( V_10 ) )
F_92 ( V_2 -> V_109 , L_21 ) ;
F_12 ( V_10 ) ;
}
} else if ( V_2 -> V_29 )
F_58 ( V_2 ) ;
F_47 ( V_10 , V_2 ) ;
F_10 ( V_10 ) ;
F_101 ( V_10 ) ;
}
void F_105 ( struct V_39 * V_112 , T_4 V_113 , int V_41 )
{
T_3 V_40 ;
int V_98 = V_73 - V_112 -> V_22 ;
int V_114 = 1 << V_98 ;
struct V_100 * V_20 =
F_67 ( V_112 -> V_47 ) -> V_103 -> V_104 ;
struct V_1 * V_2 ;
struct V_10 * V_10 ;
unsigned int V_12 ;
for ( V_40 = V_113 & ~ ( V_114 - 1 ) ; V_40 < V_113 + V_41 ;
V_40 += V_114 ) {
V_10 = F_106 ( V_20 , V_40 >> V_98 ) ;
if ( ! V_10 )
continue;
for ( V_12 = 0 ; V_12 < V_57 ; V_12 += V_58 ) {
V_2 = F_17 ( V_10 , V_12 ) ;
if ( ! V_2 )
continue;
if ( V_2 -> V_16 < V_113 )
continue;
if ( V_2 -> V_16 >= V_113 + V_41 )
break;
F_63 ( V_36 , & V_2 -> V_4 ) ;
F_72 ( V_107 , & V_2 -> V_4 ) ;
if ( V_2 -> V_29 )
F_58 ( V_2 ) ;
}
F_10 ( V_10 ) ;
F_101 ( V_10 ) ;
}
}
static int F_107 ( struct V_115 * V_116 , void * V_117 )
{
F_108 ( V_116 ,
L_23
L_24
L_25
L_26
L_27 ,
V_7 . V_108 ,
V_7 . V_38 ,
V_7 . V_8 ) ;
return 0 ;
}
static int F_109 ( struct V_39 * V_39 , struct V_89 * V_89 )
{
return F_110 ( V_89 , F_107 , NULL ) ;
}
