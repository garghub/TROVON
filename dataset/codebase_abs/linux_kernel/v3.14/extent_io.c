static inline
void F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
unsigned long V_4 ;
F_2 ( & V_5 , V_4 ) ;
F_3 ( V_2 , V_3 ) ;
F_4 ( & V_5 , V_4 ) ;
}
static inline
void F_5 ( struct V_1 * V_6 )
{
unsigned long V_4 ;
F_2 ( & V_5 , V_4 ) ;
F_6 ( V_6 ) ;
F_4 ( & V_5 , V_4 ) ;
}
static inline
void F_7 ( void )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
while ( ! F_8 ( & V_11 ) ) {
V_8 = F_9 ( V_11 . V_12 , struct V_7 , V_13 ) ;
F_10 ( V_14 L_1
L_2 ,
V_8 -> V_15 , V_8 -> V_16 , V_8 -> V_8 , V_8 -> V_17 ,
F_11 ( & V_8 -> V_18 ) ) ;
F_6 ( & V_8 -> V_13 ) ;
F_12 ( V_19 , V_8 ) ;
}
while ( ! F_8 ( & V_20 ) ) {
V_10 = F_9 ( V_20 . V_12 , struct V_9 , V_13 ) ;
F_10 ( V_14 L_3
L_4 ,
V_10 -> V_15 , V_10 -> V_21 , F_11 ( & V_10 -> V_18 ) ) ;
F_6 ( & V_10 -> V_13 ) ;
F_12 ( V_22 , V_10 ) ;
}
}
static inline void F_13 ( const char * V_23 ,
struct V_24 * V_17 , T_1 V_15 , T_1 V_16 )
{
struct V_25 * V_25 ;
T_1 V_26 ;
if ( ! V_17 -> V_27 )
return;
V_25 = V_17 -> V_27 -> V_28 ;
V_26 = F_14 ( V_25 ) ;
if ( V_16 >= V_29 && ( V_16 % 2 ) == 0 && V_16 != V_26 - 1 ) {
F_15 ( V_30
L_5 ,
V_23 , F_16 ( V_25 ) , V_26 , V_15 , V_16 ) ;
}
}
static inline struct V_31 *
F_17 ( struct V_24 * V_17 )
{
if ( ! V_17 -> V_27 )
return NULL ;
return F_18 ( V_17 -> V_27 -> V_28 -> V_32 ) ;
}
int T_2 F_19 ( void )
{
V_19 = F_20 ( L_6 ,
sizeof( struct V_7 ) , 0 ,
V_33 | V_34 , NULL ) ;
if ( ! V_19 )
return - V_35 ;
V_22 = F_20 ( L_7 ,
sizeof( struct V_9 ) , 0 ,
V_33 | V_34 , NULL ) ;
if ( ! V_22 )
goto V_36;
V_37 = F_21 ( V_38 ,
F_22 ( struct V_39 , V_40 ) ) ;
if ( ! V_37 )
goto V_41;
if ( F_23 ( V_37 , V_38 ) )
goto V_42;
return 0 ;
V_42:
F_24 ( V_37 ) ;
V_37 = NULL ;
V_41:
F_25 ( V_22 ) ;
V_22 = NULL ;
V_36:
F_25 ( V_19 ) ;
V_19 = NULL ;
return - V_35 ;
}
void F_26 ( void )
{
F_7 () ;
F_27 () ;
if ( V_19 )
F_25 ( V_19 ) ;
if ( V_22 )
F_25 ( V_22 ) ;
if ( V_37 )
F_24 ( V_37 ) ;
}
void F_28 ( struct V_24 * V_17 ,
struct V_43 * V_27 )
{
V_17 -> V_8 = V_44 ;
V_17 -> V_45 = NULL ;
V_17 -> V_46 = 0 ;
F_29 ( & V_17 -> V_47 ) ;
V_17 -> V_27 = V_27 ;
}
static struct V_7 * F_30 ( T_3 V_48 )
{
struct V_7 * V_8 ;
V_8 = F_31 ( V_19 , V_48 ) ;
if ( ! V_8 )
return V_8 ;
V_8 -> V_8 = 0 ;
V_8 -> V_49 = 0 ;
V_8 -> V_17 = NULL ;
F_1 ( & V_8 -> V_13 , & V_11 ) ;
F_32 ( & V_8 -> V_18 , 1 ) ;
F_33 ( & V_8 -> V_50 ) ;
F_34 ( V_8 , V_48 , V_51 ) ;
return V_8 ;
}
void F_35 ( struct V_7 * V_8 )
{
if ( ! V_8 )
return;
if ( F_36 ( & V_8 -> V_18 ) ) {
F_37 ( V_8 -> V_17 ) ;
F_5 ( & V_8 -> V_13 ) ;
F_38 ( V_8 , V_51 ) ;
F_12 ( V_19 , V_8 ) ;
}
}
static struct V_52 * F_39 ( struct V_53 * V_54 , T_1 V_55 ,
struct V_52 * V_56 ,
struct V_52 * * * V_57 ,
struct V_52 * * V_58 )
{
struct V_52 * * V_59 = & V_54 -> V_52 ;
struct V_52 * V_60 = NULL ;
struct V_61 * V_6 ;
if ( V_57 && V_58 ) {
V_59 = * V_57 ;
V_60 = * V_58 ;
goto V_62;
}
while ( * V_59 ) {
V_60 = * V_59 ;
V_6 = F_40 ( V_60 , struct V_61 , V_52 ) ;
if ( V_55 < V_6 -> V_15 )
V_59 = & ( * V_59 ) -> V_63 ;
else if ( V_55 > V_6 -> V_16 )
V_59 = & ( * V_59 ) -> V_64 ;
else
return V_60 ;
}
V_62:
F_41 ( V_56 , V_60 , V_59 ) ;
F_42 ( V_56 , V_54 ) ;
return NULL ;
}
static struct V_52 * F_43 ( struct V_24 * V_17 , T_1 V_55 ,
struct V_52 * * V_65 ,
struct V_52 * * V_66 ,
struct V_52 * * * V_67 ,
struct V_52 * * V_68 )
{
struct V_53 * V_54 = & V_17 -> V_8 ;
struct V_52 * * V_69 = & V_54 -> V_52 ;
struct V_52 * V_70 = NULL ;
struct V_52 * V_71 = NULL ;
struct V_61 * V_6 ;
struct V_61 * V_72 = NULL ;
while ( * V_69 ) {
V_70 = * V_69 ;
V_6 = F_40 ( V_70 , struct V_61 , V_52 ) ;
V_72 = V_6 ;
if ( V_55 < V_6 -> V_15 )
V_69 = & ( * V_69 ) -> V_63 ;
else if ( V_55 > V_6 -> V_16 )
V_69 = & ( * V_69 ) -> V_64 ;
else
return * V_69 ;
}
if ( V_67 )
* V_67 = V_69 ;
if ( V_68 )
* V_68 = V_70 ;
if ( V_65 ) {
V_71 = V_70 ;
while ( V_70 && V_55 > V_72 -> V_16 ) {
V_70 = F_44 ( V_70 ) ;
V_72 = F_40 ( V_70 , struct V_61 , V_52 ) ;
}
* V_65 = V_70 ;
V_70 = V_71 ;
}
if ( V_66 ) {
V_72 = F_40 ( V_70 , struct V_61 , V_52 ) ;
while ( V_70 && V_55 < V_72 -> V_15 ) {
V_70 = F_45 ( V_70 ) ;
V_72 = F_40 ( V_70 , struct V_61 , V_52 ) ;
}
* V_66 = V_70 ;
}
return NULL ;
}
static inline struct V_52 *
F_46 ( struct V_24 * V_17 ,
T_1 V_55 ,
struct V_52 * * * V_67 ,
struct V_52 * * V_68 )
{
struct V_52 * V_70 = NULL ;
struct V_52 * V_73 ;
V_73 = F_43 ( V_17 , V_55 , & V_70 , NULL , V_67 , V_68 ) ;
if ( ! V_73 )
return V_70 ;
return V_73 ;
}
static inline struct V_52 * F_47 ( struct V_24 * V_17 ,
T_1 V_55 )
{
return F_46 ( V_17 , V_55 , NULL , NULL ) ;
}
static void F_48 ( struct V_24 * V_17 , struct V_7 * V_2 ,
struct V_7 * V_74 )
{
if ( V_17 -> V_45 && V_17 -> V_45 -> V_75 )
V_17 -> V_45 -> V_75 ( V_17 -> V_27 -> V_28 , V_2 ,
V_74 ) ;
}
static void F_49 ( struct V_24 * V_17 ,
struct V_7 * V_8 )
{
struct V_7 * V_74 ;
struct V_52 * V_76 ;
if ( V_8 -> V_8 & ( V_77 | V_78 ) )
return;
V_76 = F_45 ( & V_8 -> V_52 ) ;
if ( V_76 ) {
V_74 = F_40 ( V_76 , struct V_7 , V_52 ) ;
if ( V_74 -> V_16 == V_8 -> V_15 - 1 &&
V_74 -> V_8 == V_8 -> V_8 ) {
F_48 ( V_17 , V_8 , V_74 ) ;
V_8 -> V_15 = V_74 -> V_15 ;
V_74 -> V_17 = NULL ;
F_50 ( & V_74 -> V_52 , & V_17 -> V_8 ) ;
F_35 ( V_74 ) ;
}
}
V_76 = F_44 ( & V_8 -> V_52 ) ;
if ( V_76 ) {
V_74 = F_40 ( V_76 , struct V_7 , V_52 ) ;
if ( V_74 -> V_15 == V_8 -> V_16 + 1 &&
V_74 -> V_8 == V_8 -> V_8 ) {
F_48 ( V_17 , V_8 , V_74 ) ;
V_8 -> V_16 = V_74 -> V_16 ;
V_74 -> V_17 = NULL ;
F_50 ( & V_74 -> V_52 , & V_17 -> V_8 ) ;
F_35 ( V_74 ) ;
}
}
}
static void F_51 ( struct V_24 * V_17 ,
struct V_7 * V_8 , unsigned long * V_79 )
{
if ( V_17 -> V_45 && V_17 -> V_45 -> V_80 )
V_17 -> V_45 -> V_80 ( V_17 -> V_27 -> V_28 , V_8 , V_79 ) ;
}
static void F_52 ( struct V_24 * V_17 ,
struct V_7 * V_8 , unsigned long * V_79 )
{
if ( V_17 -> V_45 && V_17 -> V_45 -> V_81 )
V_17 -> V_45 -> V_81 ( V_17 -> V_27 -> V_28 , V_8 , V_79 ) ;
}
static int F_53 ( struct V_24 * V_17 ,
struct V_7 * V_8 , T_1 V_15 , T_1 V_16 ,
struct V_52 * * * V_59 ,
struct V_52 * * V_60 ,
unsigned long * V_79 )
{
struct V_52 * V_56 ;
if ( V_16 < V_15 )
F_54 ( 1 , V_14 L_8 ,
V_16 , V_15 ) ;
V_8 -> V_15 = V_15 ;
V_8 -> V_16 = V_16 ;
F_55 ( V_17 , V_8 , V_79 ) ;
V_56 = F_39 ( & V_17 -> V_8 , V_16 , & V_8 -> V_52 , V_59 , V_60 ) ;
if ( V_56 ) {
struct V_7 * V_82 ;
V_82 = F_40 ( V_56 , struct V_7 , V_52 ) ;
F_10 ( V_14 L_9
L_10 ,
V_82 -> V_15 , V_82 -> V_16 , V_15 , V_16 ) ;
return - V_83 ;
}
V_8 -> V_17 = V_17 ;
F_49 ( V_17 , V_8 ) ;
return 0 ;
}
static void F_56 ( struct V_24 * V_17 , struct V_7 * V_84 ,
T_1 V_85 )
{
if ( V_17 -> V_45 && V_17 -> V_45 -> V_86 )
V_17 -> V_45 -> V_86 ( V_17 -> V_27 -> V_28 , V_84 , V_85 ) ;
}
static int F_57 ( struct V_24 * V_17 , struct V_7 * V_84 ,
struct V_7 * V_87 , T_1 V_85 )
{
struct V_52 * V_56 ;
F_56 ( V_17 , V_84 , V_85 ) ;
V_87 -> V_15 = V_84 -> V_15 ;
V_87 -> V_16 = V_85 - 1 ;
V_87 -> V_8 = V_84 -> V_8 ;
V_84 -> V_15 = V_85 ;
V_56 = F_39 ( & V_17 -> V_8 , V_87 -> V_16 , & V_87 -> V_52 ,
NULL , NULL ) ;
if ( V_56 ) {
F_35 ( V_87 ) ;
return - V_83 ;
}
V_87 -> V_17 = V_17 ;
return 0 ;
}
static struct V_7 * F_58 ( struct V_7 * V_8 )
{
struct V_52 * V_12 = F_44 ( & V_8 -> V_52 ) ;
if ( V_12 )
return F_40 ( V_12 , struct V_7 , V_52 ) ;
else
return NULL ;
}
static struct V_7 * F_59 ( struct V_24 * V_17 ,
struct V_7 * V_8 ,
unsigned long * V_79 , int V_88 )
{
struct V_7 * V_12 ;
unsigned long V_89 = * V_79 & ~ V_90 ;
if ( ( V_89 & V_91 ) && ( V_8 -> V_8 & V_91 ) ) {
T_1 V_92 = V_8 -> V_16 - V_8 -> V_15 + 1 ;
F_37 ( V_92 > V_17 -> V_46 ) ;
V_17 -> V_46 -= V_92 ;
}
F_52 ( V_17 , V_8 , V_79 ) ;
V_8 -> V_8 &= ~ V_89 ;
if ( V_88 )
F_60 ( & V_8 -> V_50 ) ;
if ( V_8 -> V_8 == 0 ) {
V_12 = F_58 ( V_8 ) ;
if ( V_8 -> V_17 ) {
F_50 ( & V_8 -> V_52 , & V_17 -> V_8 ) ;
V_8 -> V_17 = NULL ;
F_35 ( V_8 ) ;
} else {
F_37 ( 1 ) ;
}
} else {
F_49 ( V_17 , V_8 ) ;
V_12 = F_58 ( V_8 ) ;
}
return V_12 ;
}
static struct V_7 *
F_61 ( struct V_7 * V_87 )
{
if ( ! V_87 )
V_87 = F_30 ( V_93 ) ;
return V_87 ;
}
static void F_62 ( struct V_24 * V_17 , int V_94 )
{
F_63 ( F_17 ( V_17 ) , V_94 , L_11
L_12
L_13 ) ;
}
int F_64 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_79 , int V_88 , int V_95 ,
struct V_7 * * V_96 ,
T_3 V_48 )
{
struct V_7 * V_8 ;
struct V_7 * V_97 ;
struct V_7 * V_87 = NULL ;
struct V_52 * V_56 ;
T_1 V_98 ;
int V_94 ;
int V_99 = 0 ;
F_65 ( V_17 , V_15 , V_16 ) ;
if ( V_79 & V_100 )
V_79 |= V_101 ;
if ( V_95 )
V_79 |= ~ V_90 ;
V_79 |= V_102 ;
if ( V_79 & ( V_77 | V_78 ) )
V_99 = 1 ;
V_103:
if ( ! V_87 && ( V_48 & V_104 ) ) {
V_87 = F_30 ( V_48 ) ;
if ( ! V_87 )
return - V_35 ;
}
F_66 ( & V_17 -> V_47 ) ;
if ( V_96 ) {
V_97 = * V_96 ;
if ( V_99 ) {
* V_96 = NULL ;
V_96 = NULL ;
}
if ( V_97 && V_97 -> V_17 && V_97 -> V_15 <= V_15 &&
V_97 -> V_16 > V_15 ) {
if ( V_99 )
F_67 ( & V_97 -> V_18 ) ;
V_8 = V_97 ;
goto V_105;
}
if ( V_99 )
F_35 ( V_97 ) ;
}
V_56 = F_47 ( V_17 , V_15 ) ;
if ( ! V_56 )
goto V_106;
V_8 = F_40 ( V_56 , struct V_7 , V_52 ) ;
V_105:
if ( V_8 -> V_15 > V_16 )
goto V_106;
F_37 ( V_8 -> V_16 < V_15 ) ;
V_98 = V_8 -> V_16 ;
if ( ! ( V_8 -> V_8 & V_79 ) ) {
V_8 = F_58 ( V_8 ) ;
goto V_12;
}
if ( V_8 -> V_15 < V_15 ) {
V_87 = F_61 ( V_87 ) ;
F_68 ( ! V_87 ) ;
V_94 = F_57 ( V_17 , V_8 , V_87 , V_15 ) ;
if ( V_94 )
F_62 ( V_17 , V_94 ) ;
V_87 = NULL ;
if ( V_94 )
goto V_106;
if ( V_8 -> V_16 <= V_16 ) {
V_8 = F_59 ( V_17 , V_8 , & V_79 , V_88 ) ;
goto V_12;
}
goto V_107;
}
if ( V_8 -> V_15 <= V_16 && V_8 -> V_16 > V_16 ) {
V_87 = F_61 ( V_87 ) ;
F_68 ( ! V_87 ) ;
V_94 = F_57 ( V_17 , V_8 , V_87 , V_16 + 1 ) ;
if ( V_94 )
F_62 ( V_17 , V_94 ) ;
if ( V_88 )
F_60 ( & V_8 -> V_50 ) ;
F_59 ( V_17 , V_87 , & V_79 , V_88 ) ;
V_87 = NULL ;
goto V_106;
}
V_8 = F_59 ( V_17 , V_8 , & V_79 , V_88 ) ;
V_12:
if ( V_98 == ( T_1 ) - 1 )
goto V_106;
V_15 = V_98 + 1 ;
if ( V_15 <= V_16 && V_8 && ! F_69 () )
goto V_105;
goto V_107;
V_106:
F_70 ( & V_17 -> V_47 ) ;
if ( V_87 )
F_35 ( V_87 ) ;
return 0 ;
V_107:
if ( V_15 > V_16 )
goto V_106;
F_70 ( & V_17 -> V_47 ) ;
if ( V_48 & V_104 )
F_71 () ;
goto V_103;
}
static void F_72 ( struct V_24 * V_17 ,
struct V_7 * V_8 )
__releases( V_17 -> V_47 )
__acquires( V_17 -> V_47 )
{
F_73 ( V_108 ) ;
F_74 ( & V_8 -> V_50 , & V_108 , V_109 ) ;
F_70 ( & V_17 -> V_47 ) ;
F_75 () ;
F_66 ( & V_17 -> V_47 ) ;
F_76 ( & V_8 -> V_50 , & V_108 ) ;
}
static void F_77 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_79 )
{
struct V_7 * V_8 ;
struct V_52 * V_56 ;
F_65 ( V_17 , V_15 , V_16 ) ;
F_66 ( & V_17 -> V_47 ) ;
V_103:
while ( 1 ) {
V_56 = F_47 ( V_17 , V_15 ) ;
if ( ! V_56 )
break;
V_8 = F_40 ( V_56 , struct V_7 , V_52 ) ;
if ( V_8 -> V_15 > V_16 )
goto V_106;
if ( V_8 -> V_8 & V_79 ) {
V_15 = V_8 -> V_15 ;
F_78 ( & V_8 -> V_18 ) ;
F_72 ( V_17 , V_8 ) ;
F_35 ( V_8 ) ;
goto V_103;
}
V_15 = V_8 -> V_16 + 1 ;
if ( V_15 > V_16 )
break;
F_79 ( & V_17 -> V_47 ) ;
}
V_106:
F_70 ( & V_17 -> V_47 ) ;
}
static void F_55 ( struct V_24 * V_17 ,
struct V_7 * V_8 ,
unsigned long * V_79 )
{
unsigned long V_110 = * V_79 & ~ V_90 ;
F_51 ( V_17 , V_8 , V_79 ) ;
if ( ( V_110 & V_91 ) && ! ( V_8 -> V_8 & V_91 ) ) {
T_1 V_92 = V_8 -> V_16 - V_8 -> V_15 + 1 ;
V_17 -> V_46 += V_92 ;
}
V_8 -> V_8 |= V_110 ;
}
static void F_80 ( struct V_7 * V_8 ,
struct V_7 * * V_111 )
{
if ( V_111 && ! ( * V_111 ) ) {
if ( V_8 -> V_8 & ( V_77 | V_78 ) ) {
* V_111 = V_8 ;
F_78 ( & V_8 -> V_18 ) ;
}
}
}
static int T_4
F_81 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_79 , unsigned long V_112 ,
T_1 * V_113 , struct V_7 * * V_96 ,
T_3 V_48 )
{
struct V_7 * V_8 ;
struct V_7 * V_87 = NULL ;
struct V_52 * V_56 ;
struct V_52 * * V_59 ;
struct V_52 * V_60 ;
int V_94 = 0 ;
T_1 V_114 ;
T_1 V_98 ;
F_65 ( V_17 , V_15 , V_16 ) ;
V_79 |= V_102 ;
V_103:
if ( ! V_87 && ( V_48 & V_104 ) ) {
V_87 = F_30 ( V_48 ) ;
F_68 ( ! V_87 ) ;
}
F_66 ( & V_17 -> V_47 ) ;
if ( V_96 && * V_96 ) {
V_8 = * V_96 ;
if ( V_8 -> V_15 <= V_15 && V_8 -> V_16 > V_15 &&
V_8 -> V_17 ) {
V_56 = & V_8 -> V_52 ;
goto V_105;
}
}
V_56 = F_46 ( V_17 , V_15 , & V_59 , & V_60 ) ;
if ( ! V_56 ) {
V_87 = F_61 ( V_87 ) ;
F_68 ( ! V_87 ) ;
V_94 = F_53 ( V_17 , V_87 , V_15 , V_16 ,
& V_59 , & V_60 , & V_79 ) ;
if ( V_94 )
F_62 ( V_17 , V_94 ) ;
F_80 ( V_87 , V_96 ) ;
V_87 = NULL ;
goto V_106;
}
V_8 = F_40 ( V_56 , struct V_7 , V_52 ) ;
V_105:
V_114 = V_8 -> V_15 ;
V_98 = V_8 -> V_16 ;
if ( V_8 -> V_15 == V_15 && V_8 -> V_16 <= V_16 ) {
if ( V_8 -> V_8 & V_112 ) {
* V_113 = V_8 -> V_15 ;
V_94 = - V_83 ;
goto V_106;
}
F_55 ( V_17 , V_8 , & V_79 ) ;
F_80 ( V_8 , V_96 ) ;
F_49 ( V_17 , V_8 ) ;
if ( V_98 == ( T_1 ) - 1 )
goto V_106;
V_15 = V_98 + 1 ;
V_8 = F_58 ( V_8 ) ;
if ( V_15 < V_16 && V_8 && V_8 -> V_15 == V_15 &&
! F_69 () )
goto V_105;
goto V_107;
}
if ( V_8 -> V_15 < V_15 ) {
if ( V_8 -> V_8 & V_112 ) {
* V_113 = V_15 ;
V_94 = - V_83 ;
goto V_106;
}
V_87 = F_61 ( V_87 ) ;
F_68 ( ! V_87 ) ;
V_94 = F_57 ( V_17 , V_8 , V_87 , V_15 ) ;
if ( V_94 )
F_62 ( V_17 , V_94 ) ;
V_87 = NULL ;
if ( V_94 )
goto V_106;
if ( V_8 -> V_16 <= V_16 ) {
F_55 ( V_17 , V_8 , & V_79 ) ;
F_80 ( V_8 , V_96 ) ;
F_49 ( V_17 , V_8 ) ;
if ( V_98 == ( T_1 ) - 1 )
goto V_106;
V_15 = V_98 + 1 ;
V_8 = F_58 ( V_8 ) ;
if ( V_15 < V_16 && V_8 && V_8 -> V_15 == V_15 &&
! F_69 () )
goto V_105;
}
goto V_107;
}
if ( V_8 -> V_15 > V_15 ) {
T_1 V_115 ;
if ( V_16 < V_114 )
V_115 = V_16 ;
else
V_115 = V_114 - 1 ;
V_87 = F_61 ( V_87 ) ;
F_68 ( ! V_87 ) ;
V_94 = F_53 ( V_17 , V_87 , V_15 , V_115 ,
NULL , NULL , & V_79 ) ;
if ( V_94 )
F_62 ( V_17 , V_94 ) ;
F_80 ( V_87 , V_96 ) ;
V_87 = NULL ;
V_15 = V_115 + 1 ;
goto V_107;
}
if ( V_8 -> V_15 <= V_16 && V_8 -> V_16 > V_16 ) {
if ( V_8 -> V_8 & V_112 ) {
* V_113 = V_15 ;
V_94 = - V_83 ;
goto V_106;
}
V_87 = F_61 ( V_87 ) ;
F_68 ( ! V_87 ) ;
V_94 = F_57 ( V_17 , V_8 , V_87 , V_16 + 1 ) ;
if ( V_94 )
F_62 ( V_17 , V_94 ) ;
F_55 ( V_17 , V_87 , & V_79 ) ;
F_80 ( V_87 , V_96 ) ;
F_49 ( V_17 , V_87 ) ;
V_87 = NULL ;
goto V_106;
}
goto V_107;
V_106:
F_70 ( & V_17 -> V_47 ) ;
if ( V_87 )
F_35 ( V_87 ) ;
return V_94 ;
V_107:
if ( V_15 > V_16 )
goto V_106;
F_70 ( & V_17 -> V_47 ) ;
if ( V_48 & V_104 )
F_71 () ;
goto V_103;
}
int F_82 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_79 , T_1 * V_113 ,
struct V_7 * * V_96 , T_3 V_48 )
{
return F_81 ( V_17 , V_15 , V_16 , V_79 , 0 , V_113 ,
V_96 , V_48 ) ;
}
int F_83 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_79 , unsigned long V_116 ,
struct V_7 * * V_96 , T_3 V_48 )
{
struct V_7 * V_8 ;
struct V_7 * V_87 = NULL ;
struct V_52 * V_56 ;
struct V_52 * * V_59 ;
struct V_52 * V_60 ;
int V_94 = 0 ;
T_1 V_114 ;
T_1 V_98 ;
F_65 ( V_17 , V_15 , V_16 ) ;
V_103:
if ( ! V_87 && ( V_48 & V_104 ) ) {
V_87 = F_30 ( V_48 ) ;
if ( ! V_87 )
return - V_35 ;
}
F_66 ( & V_17 -> V_47 ) ;
if ( V_96 && * V_96 ) {
V_8 = * V_96 ;
if ( V_8 -> V_15 <= V_15 && V_8 -> V_16 > V_15 &&
V_8 -> V_17 ) {
V_56 = & V_8 -> V_52 ;
goto V_105;
}
}
V_56 = F_46 ( V_17 , V_15 , & V_59 , & V_60 ) ;
if ( ! V_56 ) {
V_87 = F_61 ( V_87 ) ;
if ( ! V_87 ) {
V_94 = - V_35 ;
goto V_106;
}
V_94 = F_53 ( V_17 , V_87 , V_15 , V_16 ,
& V_59 , & V_60 , & V_79 ) ;
if ( V_94 )
F_62 ( V_17 , V_94 ) ;
F_80 ( V_87 , V_96 ) ;
V_87 = NULL ;
goto V_106;
}
V_8 = F_40 ( V_56 , struct V_7 , V_52 ) ;
V_105:
V_114 = V_8 -> V_15 ;
V_98 = V_8 -> V_16 ;
if ( V_8 -> V_15 == V_15 && V_8 -> V_16 <= V_16 ) {
F_55 ( V_17 , V_8 , & V_79 ) ;
F_80 ( V_8 , V_96 ) ;
V_8 = F_59 ( V_17 , V_8 , & V_116 , 0 ) ;
if ( V_98 == ( T_1 ) - 1 )
goto V_106;
V_15 = V_98 + 1 ;
if ( V_15 < V_16 && V_8 && V_8 -> V_15 == V_15 &&
! F_69 () )
goto V_105;
goto V_107;
}
if ( V_8 -> V_15 < V_15 ) {
V_87 = F_61 ( V_87 ) ;
if ( ! V_87 ) {
V_94 = - V_35 ;
goto V_106;
}
V_94 = F_57 ( V_17 , V_8 , V_87 , V_15 ) ;
if ( V_94 )
F_62 ( V_17 , V_94 ) ;
V_87 = NULL ;
if ( V_94 )
goto V_106;
if ( V_8 -> V_16 <= V_16 ) {
F_55 ( V_17 , V_8 , & V_79 ) ;
F_80 ( V_8 , V_96 ) ;
V_8 = F_59 ( V_17 , V_8 , & V_116 , 0 ) ;
if ( V_98 == ( T_1 ) - 1 )
goto V_106;
V_15 = V_98 + 1 ;
if ( V_15 < V_16 && V_8 && V_8 -> V_15 == V_15 &&
! F_69 () )
goto V_105;
}
goto V_107;
}
if ( V_8 -> V_15 > V_15 ) {
T_1 V_115 ;
if ( V_16 < V_114 )
V_115 = V_16 ;
else
V_115 = V_114 - 1 ;
V_87 = F_61 ( V_87 ) ;
if ( ! V_87 ) {
V_94 = - V_35 ;
goto V_106;
}
V_94 = F_53 ( V_17 , V_87 , V_15 , V_115 ,
NULL , NULL , & V_79 ) ;
if ( V_94 )
F_62 ( V_17 , V_94 ) ;
F_80 ( V_87 , V_96 ) ;
V_87 = NULL ;
V_15 = V_115 + 1 ;
goto V_107;
}
if ( V_8 -> V_15 <= V_16 && V_8 -> V_16 > V_16 ) {
V_87 = F_61 ( V_87 ) ;
if ( ! V_87 ) {
V_94 = - V_35 ;
goto V_106;
}
V_94 = F_57 ( V_17 , V_8 , V_87 , V_16 + 1 ) ;
if ( V_94 )
F_62 ( V_17 , V_94 ) ;
F_55 ( V_17 , V_87 , & V_79 ) ;
F_80 ( V_87 , V_96 ) ;
F_59 ( V_17 , V_87 , & V_116 , 0 ) ;
V_87 = NULL ;
goto V_106;
}
goto V_107;
V_106:
F_70 ( & V_17 -> V_47 ) ;
if ( V_87 )
F_35 ( V_87 ) ;
return V_94 ;
V_107:
if ( V_15 > V_16 )
goto V_106;
F_70 ( & V_17 -> V_47 ) ;
if ( V_48 & V_104 )
F_71 () ;
goto V_103;
}
int F_84 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
T_3 V_48 )
{
return F_82 ( V_17 , V_15 , V_16 , V_91 , NULL ,
NULL , V_48 ) ;
}
int F_85 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_79 , T_3 V_48 )
{
return F_82 ( V_17 , V_15 , V_16 , V_79 , NULL ,
NULL , V_48 ) ;
}
int F_86 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_79 , T_3 V_48 )
{
return F_64 ( V_17 , V_15 , V_16 , V_79 , 0 , 0 , NULL , V_48 ) ;
}
int F_87 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
struct V_7 * * V_96 , T_3 V_48 )
{
return F_82 ( V_17 , V_15 , V_16 ,
V_100 | V_117 ,
NULL , V_96 , V_48 ) ;
}
int F_88 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
struct V_7 * * V_96 , T_3 V_48 )
{
return F_82 ( V_17 , V_15 , V_16 ,
V_100 | V_117 | V_118 ,
NULL , V_96 , V_48 ) ;
}
int F_89 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
T_3 V_48 )
{
return F_64 ( V_17 , V_15 , V_16 ,
V_91 | V_100 |
V_119 , 0 , 0 , NULL , V_48 ) ;
}
int F_90 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
T_3 V_48 )
{
return F_82 ( V_17 , V_15 , V_16 , V_120 , NULL ,
NULL , V_48 ) ;
}
int F_91 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
struct V_7 * * V_96 , T_3 V_48 )
{
return F_82 ( V_17 , V_15 , V_16 , V_117 , NULL ,
V_96 , V_48 ) ;
}
int F_92 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
struct V_7 * * V_96 , T_3 V_48 )
{
return F_64 ( V_17 , V_15 , V_16 , V_117 , 0 , 0 ,
V_96 , V_48 ) ;
}
int F_93 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_79 , struct V_7 * * V_96 )
{
int V_94 ;
T_1 V_113 ;
while ( 1 ) {
V_94 = F_81 ( V_17 , V_15 , V_16 , V_121 | V_79 ,
V_121 , & V_113 ,
V_96 , V_122 ) ;
if ( V_94 == - V_83 ) {
F_77 ( V_17 , V_113 , V_16 , V_121 ) ;
V_15 = V_113 ;
} else
break;
F_37 ( V_15 > V_16 ) ;
}
return V_94 ;
}
int F_94 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 )
{
return F_93 ( V_17 , V_15 , V_16 , 0 , NULL ) ;
}
int F_95 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 )
{
int V_94 ;
T_1 V_113 ;
V_94 = F_81 ( V_17 , V_15 , V_16 , V_121 , V_121 ,
& V_113 , NULL , V_122 ) ;
if ( V_94 == - V_83 ) {
if ( V_113 > V_15 )
F_64 ( V_17 , V_15 , V_113 - 1 ,
V_121 , 1 , 0 , NULL , V_122 ) ;
return 0 ;
}
return 1 ;
}
int F_96 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
struct V_7 * * V_97 , T_3 V_48 )
{
return F_64 ( V_17 , V_15 , V_16 , V_121 , 1 , 0 , V_97 ,
V_48 ) ;
}
int F_97 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 )
{
return F_64 ( V_17 , V_15 , V_16 , V_121 , 1 , 0 , NULL ,
V_122 ) ;
}
int F_98 ( struct V_25 * V_25 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_123 = V_15 >> V_124 ;
unsigned long V_125 = V_16 >> V_124 ;
struct V_126 * V_126 ;
while ( V_123 <= V_125 ) {
V_126 = F_99 ( V_25 -> V_127 , V_123 ) ;
F_68 ( ! V_126 ) ;
F_100 ( V_126 ) ;
F_101 ( V_126 ) ;
V_123 ++ ;
}
return 0 ;
}
int F_102 ( struct V_25 * V_25 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_123 = V_15 >> V_124 ;
unsigned long V_125 = V_16 >> V_124 ;
struct V_126 * V_126 ;
while ( V_123 <= V_125 ) {
V_126 = F_99 ( V_25 -> V_127 , V_123 ) ;
F_68 ( ! V_126 ) ;
F_103 ( V_126 ) ;
F_104 ( V_126 ) ;
F_101 ( V_126 ) ;
V_123 ++ ;
}
return 0 ;
}
static int F_105 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_123 = V_15 >> V_124 ;
unsigned long V_125 = V_16 >> V_124 ;
struct V_126 * V_126 ;
while ( V_123 <= V_125 ) {
V_126 = F_99 ( V_17 -> V_27 , V_123 ) ;
F_68 ( ! V_126 ) ;
F_106 ( V_126 ) ;
F_101 ( V_126 ) ;
V_123 ++ ;
}
return 0 ;
}
static struct V_7 *
F_107 ( struct V_24 * V_17 ,
T_1 V_15 , unsigned long V_79 )
{
struct V_52 * V_56 ;
struct V_7 * V_8 ;
V_56 = F_47 ( V_17 , V_15 ) ;
if ( ! V_56 )
goto V_106;
while ( 1 ) {
V_8 = F_40 ( V_56 , struct V_7 , V_52 ) ;
if ( V_8 -> V_16 >= V_15 && ( V_8 -> V_8 & V_79 ) )
return V_8 ;
V_56 = F_44 ( V_56 ) ;
if ( ! V_56 )
break;
}
V_106:
return NULL ;
}
int F_108 ( struct V_24 * V_17 , T_1 V_15 ,
T_1 * V_128 , T_1 * V_129 , unsigned long V_79 ,
struct V_7 * * V_96 )
{
struct V_7 * V_8 ;
struct V_52 * V_69 ;
int V_73 = 1 ;
F_66 ( & V_17 -> V_47 ) ;
if ( V_96 && * V_96 ) {
V_8 = * V_96 ;
if ( V_8 -> V_16 == V_15 - 1 && V_8 -> V_17 ) {
V_69 = F_44 ( & V_8 -> V_52 ) ;
while ( V_69 ) {
V_8 = F_40 ( V_69 , struct V_7 ,
V_52 ) ;
if ( V_8 -> V_8 & V_79 )
goto V_130;
V_69 = F_44 ( V_69 ) ;
}
F_35 ( * V_96 ) ;
* V_96 = NULL ;
goto V_106;
}
F_35 ( * V_96 ) ;
* V_96 = NULL ;
}
V_8 = F_107 ( V_17 , V_15 , V_79 ) ;
V_130:
if ( V_8 ) {
F_80 ( V_8 , V_96 ) ;
* V_128 = V_8 -> V_15 ;
* V_129 = V_8 -> V_16 ;
V_73 = 0 ;
}
V_106:
F_70 ( & V_17 -> V_47 ) ;
return V_73 ;
}
static T_5 T_1 F_109 ( struct V_24 * V_17 ,
T_1 * V_15 , T_1 * V_16 , T_1 V_131 ,
struct V_7 * * V_96 )
{
struct V_52 * V_56 ;
struct V_7 * V_8 ;
T_1 V_132 = * V_15 ;
T_1 V_82 = 0 ;
T_1 V_133 = 0 ;
F_66 ( & V_17 -> V_47 ) ;
V_56 = F_47 ( V_17 , V_132 ) ;
if ( ! V_56 ) {
if ( ! V_82 )
* V_16 = ( T_1 ) - 1 ;
goto V_106;
}
while ( 1 ) {
V_8 = F_40 ( V_56 , struct V_7 , V_52 ) ;
if ( V_82 && ( V_8 -> V_15 != V_132 ||
( V_8 -> V_8 & V_78 ) ) ) {
goto V_106;
}
if ( ! ( V_8 -> V_8 & V_100 ) ) {
if ( ! V_82 )
* V_16 = V_8 -> V_16 ;
goto V_106;
}
if ( ! V_82 ) {
* V_15 = V_8 -> V_15 ;
* V_96 = V_8 ;
F_78 ( & V_8 -> V_18 ) ;
}
V_82 ++ ;
* V_16 = V_8 -> V_16 ;
V_132 = V_8 -> V_16 + 1 ;
V_56 = F_44 ( V_56 ) ;
V_133 += V_8 -> V_16 - V_8 -> V_15 + 1 ;
if ( V_133 >= V_131 )
break;
if ( ! V_56 )
break;
}
V_106:
F_70 ( & V_17 -> V_47 ) ;
return V_82 ;
}
static T_5 void F_110 ( struct V_25 * V_25 ,
struct V_126 * V_134 ,
T_1 V_15 , T_1 V_16 )
{
int V_73 ;
struct V_126 * V_135 [ 16 ] ;
unsigned long V_123 = V_15 >> V_124 ;
unsigned long V_125 = V_16 >> V_124 ;
unsigned long V_136 = V_125 - V_123 + 1 ;
int V_137 ;
if ( V_123 == V_134 -> V_123 && V_125 == V_123 )
return;
while ( V_136 > 0 ) {
V_73 = F_111 ( V_25 -> V_127 , V_123 ,
F_112 (unsigned long, nr_pages,
ARRAY_SIZE(pages)) , V_135 ) ;
for ( V_137 = 0 ; V_137 < V_73 ; V_137 ++ ) {
if ( V_135 [ V_137 ] != V_134 )
F_113 ( V_135 [ V_137 ] ) ;
F_101 ( V_135 [ V_137 ] ) ;
}
V_136 -= V_73 ;
V_123 += V_73 ;
F_71 () ;
}
}
static T_5 int F_114 ( struct V_25 * V_25 ,
struct V_126 * V_134 ,
T_1 V_138 ,
T_1 V_139 )
{
unsigned long V_123 = V_138 >> V_124 ;
unsigned long V_140 = V_123 ;
unsigned long V_125 = V_139 >> V_124 ;
unsigned long V_141 = 0 ;
struct V_126 * V_135 [ 16 ] ;
unsigned long V_142 ;
int V_73 ;
int V_137 ;
if ( V_123 == V_134 -> V_123 && V_123 == V_125 )
return 0 ;
V_142 = V_125 - V_123 + 1 ;
while ( V_142 > 0 ) {
V_73 = F_111 ( V_25 -> V_127 , V_123 ,
F_112 (unsigned long,
nrpages, ARRAY_SIZE(pages)) , V_135 ) ;
if ( V_73 == 0 ) {
V_73 = - V_143 ;
goto V_144;
}
for ( V_137 = 0 ; V_137 < V_73 ; V_137 ++ ) {
if ( V_135 [ V_137 ] != V_134 ) {
F_115 ( V_135 [ V_137 ] ) ;
if ( ! F_116 ( V_135 [ V_137 ] ) ||
V_135 [ V_137 ] -> V_27 != V_25 -> V_127 ) {
V_73 = - V_143 ;
F_113 ( V_135 [ V_137 ] ) ;
F_101 ( V_135 [ V_137 ] ) ;
goto V_144;
}
}
F_101 ( V_135 [ V_137 ] ) ;
V_141 ++ ;
}
V_142 -= V_73 ;
V_123 += V_73 ;
F_71 () ;
}
V_73 = 0 ;
V_144:
if ( V_73 && V_141 ) {
F_110 ( V_25 , V_134 ,
V_138 ,
( ( T_1 ) ( V_140 + V_141 - 1 ) ) <<
V_124 ) ;
}
return V_73 ;
}
STATIC T_1 F_117 ( struct V_25 * V_25 ,
struct V_24 * V_17 ,
struct V_126 * V_134 , T_1 * V_15 ,
T_1 * V_16 , T_1 V_131 )
{
T_1 V_138 ;
T_1 V_139 ;
T_1 V_82 ;
struct V_7 * V_96 = NULL ;
int V_73 ;
int V_145 = 0 ;
V_103:
V_138 = * V_15 ;
V_139 = 0 ;
V_82 = F_109 ( V_17 , & V_138 , & V_139 ,
V_131 , & V_96 ) ;
if ( ! V_82 || V_139 <= * V_15 ) {
* V_15 = V_138 ;
* V_16 = V_139 ;
F_35 ( V_96 ) ;
return 0 ;
}
if ( V_138 < * V_15 )
V_138 = * V_15 ;
if ( V_139 + 1 - V_138 > V_131 )
V_139 = V_138 + V_131 - 1 ;
V_73 = F_114 ( V_25 , V_134 ,
V_138 , V_139 ) ;
if ( V_73 == - V_143 ) {
F_35 ( V_96 ) ;
if ( ! V_145 ) {
V_131 = V_146 ;
V_145 = 1 ;
goto V_103;
} else {
V_82 = 0 ;
goto V_147;
}
}
F_68 ( V_73 ) ;
F_93 ( V_17 , V_138 , V_139 , 0 , & V_96 ) ;
V_73 = F_118 ( V_17 , V_138 , V_139 ,
V_100 , 1 , V_96 ) ;
if ( ! V_73 ) {
F_96 ( V_17 , V_138 , V_139 ,
& V_96 , V_122 ) ;
F_110 ( V_25 , V_134 ,
V_138 , V_139 ) ;
F_71 () ;
goto V_103;
}
F_35 ( V_96 ) ;
* V_15 = V_138 ;
* V_16 = V_139 ;
V_147:
return V_82 ;
}
int F_119 ( struct V_25 * V_25 , T_1 V_15 , T_1 V_16 ,
struct V_126 * V_134 ,
unsigned long V_116 ,
unsigned long V_148 )
{
struct V_24 * V_17 = & F_120 ( V_25 ) -> V_149 ;
int V_73 ;
struct V_126 * V_135 [ 16 ] ;
unsigned long V_123 = V_15 >> V_124 ;
unsigned long V_125 = V_16 >> V_124 ;
unsigned long V_136 = V_125 - V_123 + 1 ;
int V_137 ;
F_64 ( V_17 , V_15 , V_16 , V_116 , 1 , 0 , NULL , V_122 ) ;
if ( V_148 == 0 )
return 0 ;
while ( V_136 > 0 ) {
V_73 = F_111 ( V_25 -> V_127 , V_123 ,
F_112 (unsigned long,
nr_pages, ARRAY_SIZE(pages)) , V_135 ) ;
for ( V_137 = 0 ; V_137 < V_73 ; V_137 ++ ) {
if ( V_148 & V_150 )
F_121 ( V_135 [ V_137 ] ) ;
if ( V_135 [ V_137 ] == V_134 ) {
F_101 ( V_135 [ V_137 ] ) ;
continue;
}
if ( V_148 & V_151 )
F_100 ( V_135 [ V_137 ] ) ;
if ( V_148 & V_152 )
F_106 ( V_135 [ V_137 ] ) ;
if ( V_148 & V_153 )
F_122 ( V_135 [ V_137 ] ) ;
if ( V_148 & V_154 )
F_113 ( V_135 [ V_137 ] ) ;
F_101 ( V_135 [ V_137 ] ) ;
}
V_136 -= V_73 ;
V_123 += V_73 ;
F_71 () ;
}
return 0 ;
}
T_1 F_123 ( struct V_24 * V_17 ,
T_1 * V_15 , T_1 V_155 , T_1 V_131 ,
unsigned long V_79 , int V_156 )
{
struct V_52 * V_56 ;
struct V_7 * V_8 ;
T_1 V_132 = * V_15 ;
T_1 V_133 = 0 ;
T_1 V_157 = 0 ;
int V_82 = 0 ;
if ( F_37 ( V_155 <= V_132 ) )
return 0 ;
F_66 ( & V_17 -> V_47 ) ;
if ( V_132 == 0 && V_79 == V_91 ) {
V_133 = V_17 -> V_46 ;
goto V_106;
}
V_56 = F_47 ( V_17 , V_132 ) ;
if ( ! V_56 )
goto V_106;
while ( 1 ) {
V_8 = F_40 ( V_56 , struct V_7 , V_52 ) ;
if ( V_8 -> V_15 > V_155 )
break;
if ( V_156 && V_82 && V_8 -> V_15 > V_157 + 1 )
break;
if ( V_8 -> V_16 >= V_132 && ( V_8 -> V_8 & V_79 ) == V_79 ) {
V_133 += F_124 ( V_155 , V_8 -> V_16 ) + 1 -
F_125 ( V_132 , V_8 -> V_15 ) ;
if ( V_133 >= V_131 )
break;
if ( ! V_82 ) {
* V_15 = F_125 ( V_132 , V_8 -> V_15 ) ;
V_82 = 1 ;
}
V_157 = V_8 -> V_16 ;
} else if ( V_156 && V_82 ) {
break;
}
V_56 = F_44 ( V_56 ) ;
if ( ! V_56 )
break;
}
V_106:
F_70 ( & V_17 -> V_47 ) ;
return V_133 ;
}
static int F_126 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_49 )
{
struct V_52 * V_56 ;
struct V_7 * V_8 ;
int V_73 = 0 ;
F_66 ( & V_17 -> V_47 ) ;
V_56 = F_47 ( V_17 , V_15 ) ;
if ( ! V_56 ) {
V_73 = - V_158 ;
goto V_106;
}
V_8 = F_40 ( V_56 , struct V_7 , V_52 ) ;
if ( V_8 -> V_15 != V_15 ) {
V_73 = - V_158 ;
goto V_106;
}
V_8 -> V_49 = V_49 ;
V_106:
F_70 ( & V_17 -> V_47 ) ;
return V_73 ;
}
int F_127 ( struct V_24 * V_17 , T_1 V_15 , T_1 * V_49 )
{
struct V_52 * V_56 ;
struct V_7 * V_8 ;
int V_73 = 0 ;
F_66 ( & V_17 -> V_47 ) ;
V_56 = F_47 ( V_17 , V_15 ) ;
if ( ! V_56 ) {
V_73 = - V_158 ;
goto V_106;
}
V_8 = F_40 ( V_56 , struct V_7 , V_52 ) ;
if ( V_8 -> V_15 != V_15 ) {
V_73 = - V_158 ;
goto V_106;
}
* V_49 = V_8 -> V_49 ;
V_106:
F_70 ( & V_17 -> V_47 ) ;
return V_73 ;
}
int F_118 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_79 , int V_159 , struct V_7 * V_97 )
{
struct V_7 * V_8 = NULL ;
struct V_52 * V_56 ;
int V_160 = 0 ;
F_66 ( & V_17 -> V_47 ) ;
if ( V_97 && V_97 -> V_17 && V_97 -> V_15 <= V_15 &&
V_97 -> V_16 > V_15 )
V_56 = & V_97 -> V_52 ;
else
V_56 = F_47 ( V_17 , V_15 ) ;
while ( V_56 && V_15 <= V_16 ) {
V_8 = F_40 ( V_56 , struct V_7 , V_52 ) ;
if ( V_159 && V_8 -> V_15 > V_15 ) {
V_160 = 0 ;
break;
}
if ( V_8 -> V_15 > V_16 )
break;
if ( V_8 -> V_8 & V_79 ) {
V_160 = 1 ;
if ( ! V_159 )
break;
} else if ( V_159 ) {
V_160 = 0 ;
break;
}
if ( V_8 -> V_16 == ( T_1 ) - 1 )
break;
V_15 = V_8 -> V_16 + 1 ;
if ( V_15 > V_16 )
break;
V_56 = F_44 ( V_56 ) ;
if ( ! V_56 ) {
if ( V_159 )
V_160 = 0 ;
break;
}
}
F_70 ( & V_17 -> V_47 ) ;
return V_160 ;
}
static void F_128 ( struct V_24 * V_17 , struct V_126 * V_126 )
{
T_1 V_15 = F_129 ( V_126 ) ;
T_1 V_16 = V_15 + V_146 - 1 ;
if ( F_118 ( V_17 , V_15 , V_16 , V_117 , 1 , NULL ) )
F_130 ( V_126 ) ;
}
static int F_131 ( struct V_25 * V_25 , struct V_161 * V_162 ,
int V_163 )
{
int V_73 ;
int V_94 = 0 ;
struct V_24 * V_164 = & F_120 ( V_25 ) -> V_165 ;
F_126 ( V_164 , V_162 -> V_15 , 0 ) ;
V_73 = F_86 ( V_164 , V_162 -> V_15 ,
V_162 -> V_15 + V_162 -> V_21 - 1 ,
V_121 | V_91 , V_122 ) ;
if ( V_73 )
V_94 = V_73 ;
V_73 = F_86 ( & F_120 ( V_25 ) -> V_149 , V_162 -> V_15 ,
V_162 -> V_15 + V_162 -> V_21 - 1 ,
V_166 , V_122 ) ;
if ( V_73 && ! V_94 )
V_94 = V_73 ;
F_132 ( V_162 ) ;
return V_94 ;
}
int F_133 ( struct V_31 * V_167 , T_1 V_15 ,
T_1 V_168 , T_1 V_169 , struct V_126 * V_126 ,
int V_170 )
{
struct V_40 * V_40 ;
struct V_171 * V_172 ;
T_1 V_173 = 0 ;
T_1 V_174 ;
struct V_175 * V_176 = NULL ;
struct V_177 * V_178 = & V_167 -> V_179 ;
int V_73 ;
ASSERT ( ! ( V_167 -> V_180 -> V_181 & V_182 ) ) ;
F_68 ( ! V_170 ) ;
if ( F_134 ( V_178 , V_169 , V_168 , V_170 ) )
return 0 ;
V_40 = F_135 ( V_122 , 1 ) ;
if ( ! V_40 )
return - V_183 ;
V_40 -> V_184 . V_185 = 0 ;
V_173 = V_168 ;
V_73 = F_136 ( V_167 , V_186 , V_169 ,
& V_173 , & V_176 , V_170 ) ;
if ( V_73 ) {
F_137 ( V_40 ) ;
return - V_183 ;
}
F_68 ( V_170 != V_176 -> V_170 ) ;
V_174 = V_176 -> V_187 [ V_170 - 1 ] . V_188 >> 9 ;
V_40 -> V_184 . V_189 = V_174 ;
V_172 = V_176 -> V_187 [ V_170 - 1 ] . V_172 ;
F_132 ( V_176 ) ;
if ( ! V_172 || ! V_172 -> V_190 || ! V_172 -> V_191 ) {
F_137 ( V_40 ) ;
return - V_183 ;
}
V_40 -> V_192 = V_172 -> V_190 ;
F_138 ( V_40 , V_126 , V_168 , V_15 - F_129 ( V_126 ) ) ;
if ( F_139 ( V_193 , V_40 ) ) {
F_137 ( V_40 ) ;
F_140 ( V_172 , V_194 ) ;
return - V_183 ;
}
F_141 ( V_195
L_14
L_15 , V_126 -> V_27 -> V_28 -> V_196 ,
V_15 , F_142 ( V_172 -> V_197 ) , V_174 ) ;
F_137 ( V_40 ) ;
return 0 ;
}
int F_143 ( struct V_198 * V_54 , struct V_9 * V_10 ,
int V_170 )
{
T_1 V_15 = V_10 -> V_15 ;
unsigned long V_137 , V_199 = F_144 ( V_10 -> V_15 , V_10 -> V_21 ) ;
int V_73 = 0 ;
if ( V_54 -> V_167 -> V_180 -> V_181 & V_182 )
return - V_200 ;
for ( V_137 = 0 ; V_137 < V_199 ; V_137 ++ ) {
struct V_126 * V_59 = F_145 ( V_10 , V_137 ) ;
V_73 = F_133 ( V_54 -> V_167 , V_15 , V_146 ,
V_15 , V_59 , V_170 ) ;
if ( V_73 )
break;
V_15 += V_146 ;
}
return V_73 ;
}
static int F_146 ( T_1 V_15 , struct V_126 * V_126 )
{
T_1 V_49 ;
T_1 V_201 ;
struct V_161 * V_202 ;
struct V_25 * V_25 = V_126 -> V_27 -> V_28 ;
struct V_31 * V_167 = F_120 ( V_25 ) -> V_54 -> V_167 ;
struct V_7 * V_8 ;
int V_203 ;
int V_163 = 0 ;
int V_73 ;
V_49 = 0 ;
V_73 = F_123 ( & F_120 ( V_25 ) -> V_165 , & V_49 ,
( T_1 ) - 1 , 1 , V_91 , 0 ) ;
if ( ! V_73 )
return 0 ;
V_73 = F_127 ( & F_120 ( V_25 ) -> V_165 , V_15 ,
& V_201 ) ;
if ( V_73 )
return 0 ;
V_202 = (struct V_161 * ) ( unsigned long ) V_201 ;
F_68 ( ! V_202 -> V_204 ) ;
if ( V_202 -> V_205 ) {
F_147 ( L_16 ,
V_202 -> V_15 ) ;
V_163 = 1 ;
goto V_106;
}
if ( V_167 -> V_180 -> V_181 & V_182 )
goto V_106;
F_66 ( & F_120 ( V_25 ) -> V_149 . V_47 ) ;
V_8 = F_107 ( & F_120 ( V_25 ) -> V_149 ,
V_202 -> V_15 ,
V_121 ) ;
F_70 ( & F_120 ( V_25 ) -> V_149 . V_47 ) ;
if ( V_8 && V_8 -> V_15 <= V_202 -> V_15 &&
V_8 -> V_16 >= V_202 -> V_15 + V_202 -> V_21 - 1 ) {
V_203 = F_148 ( V_167 , V_202 -> V_169 ,
V_202 -> V_21 ) ;
if ( V_203 > 1 ) {
V_73 = F_133 ( V_167 , V_15 , V_202 -> V_21 ,
V_202 -> V_169 , V_126 ,
V_202 -> V_206 ) ;
V_163 = ! V_73 ;
}
V_73 = 0 ;
}
V_106:
if ( ! V_73 )
V_73 = F_131 ( V_25 , V_202 , V_163 ) ;
return V_73 ;
}
static int F_149 ( struct V_40 * V_207 , T_1 V_208 ,
struct V_126 * V_126 , T_1 V_15 , T_1 V_16 ,
int V_206 )
{
struct V_161 * V_202 = NULL ;
T_1 V_49 ;
struct V_209 * V_210 ;
struct V_25 * V_25 = V_126 -> V_27 -> V_28 ;
struct V_24 * V_164 = & F_120 ( V_25 ) -> V_165 ;
struct V_24 * V_17 = & F_120 ( V_25 ) -> V_149 ;
struct V_211 * V_212 = & F_120 ( V_25 ) -> V_213 ;
struct V_40 * V_40 ;
struct V_39 * V_214 ;
struct V_39 * V_175 ;
int V_203 ;
int V_73 ;
int V_215 ;
T_1 V_169 ;
F_68 ( V_207 -> V_216 & V_217 ) ;
V_73 = F_127 ( V_164 , V_15 , & V_49 ) ;
if ( V_73 ) {
V_202 = F_150 ( sizeof( * V_202 ) , V_122 ) ;
if ( ! V_202 )
return - V_35 ;
V_202 -> V_15 = V_15 ;
V_202 -> V_21 = V_16 - V_15 + 1 ;
V_202 -> V_204 = 0 ;
V_202 -> V_218 = 0 ;
V_202 -> V_205 = 0 ;
F_151 ( & V_212 -> V_47 ) ;
V_210 = F_152 ( V_212 , V_15 , V_202 -> V_21 ) ;
if ( ! V_210 ) {
F_153 ( & V_212 -> V_47 ) ;
F_132 ( V_202 ) ;
return - V_183 ;
}
if ( V_210 -> V_15 > V_15 || V_210 -> V_15 + V_210 -> V_21 <= V_15 ) {
F_154 ( V_210 ) ;
V_210 = NULL ;
}
F_153 ( & V_212 -> V_47 ) ;
if ( ! V_210 ) {
F_132 ( V_202 ) ;
return - V_183 ;
}
V_169 = V_15 - V_210 -> V_15 ;
V_169 = V_210 -> V_219 + V_169 ;
if ( F_155 ( V_220 , & V_210 -> V_4 ) ) {
V_169 = V_210 -> V_219 ;
V_202 -> V_218 = V_221 ;
F_156 ( & V_202 -> V_218 ,
V_210 -> V_222 ) ;
}
F_147 ( L_17
L_18 , V_169 , V_15 , V_202 -> V_21 ) ;
V_202 -> V_169 = V_169 ;
F_154 ( V_210 ) ;
V_73 = F_85 ( V_164 , V_15 , V_16 ,
V_121 | V_91 , V_122 ) ;
if ( V_73 >= 0 )
V_73 = F_126 ( V_164 , V_15 ,
( T_1 ) ( unsigned long ) V_202 ) ;
if ( V_73 >= 0 )
V_73 = F_85 ( V_17 , V_15 , V_16 , V_166 ,
V_122 ) ;
if ( V_73 < 0 ) {
F_132 ( V_202 ) ;
return V_73 ;
}
} else {
V_202 = (struct V_161 * ) ( unsigned long ) V_49 ;
F_147 ( L_19
L_20 ,
V_202 -> V_169 , V_202 -> V_15 , V_202 -> V_21 ,
V_202 -> V_205 ) ;
}
V_203 = F_148 ( F_120 ( V_25 ) -> V_54 -> V_167 ,
V_202 -> V_169 , V_202 -> V_21 ) ;
if ( V_203 == 1 ) {
F_147 ( L_21 ,
V_203 , V_202 -> V_204 , V_206 ) ;
F_131 ( V_25 , V_202 , 0 ) ;
return - V_183 ;
}
if ( V_207 -> V_223 > 1 ) {
F_68 ( V_202 -> V_205 ) ;
V_202 -> V_205 = 1 ;
V_202 -> V_204 = V_206 ;
V_215 = V_224 | V_225 ;
} else {
if ( V_202 -> V_205 ) {
F_68 ( V_202 -> V_204 != V_206 ) ;
V_202 -> V_205 = 0 ;
V_202 -> V_204 = 0 ;
}
V_202 -> V_206 = V_206 ;
V_202 -> V_204 ++ ;
if ( V_202 -> V_204 == V_206 )
V_202 -> V_204 ++ ;
V_215 = V_224 ;
}
if ( V_202 -> V_204 > V_203 ) {
F_147 ( L_22 ,
V_203 , V_202 -> V_204 , V_206 ) ;
F_131 ( V_25 , V_202 , 0 ) ;
return - V_183 ;
}
V_40 = F_135 ( V_122 , 1 ) ;
if ( ! V_40 ) {
F_131 ( V_25 , V_202 , 0 ) ;
return - V_183 ;
}
V_40 -> V_226 = V_207 -> V_226 ;
V_40 -> V_184 . V_189 = V_202 -> V_169 >> 9 ;
V_40 -> V_192 = F_120 ( V_25 ) -> V_54 -> V_167 -> V_227 -> V_228 ;
V_40 -> V_184 . V_185 = 0 ;
V_214 = V_39 ( V_207 ) ;
if ( V_214 -> V_229 ) {
struct V_31 * V_167 = F_120 ( V_25 ) -> V_54 -> V_167 ;
T_6 V_230 = F_157 ( V_167 -> V_231 ) ;
V_175 = V_39 ( V_40 ) ;
V_175 -> V_229 = V_175 -> V_232 ;
V_208 >>= V_25 -> V_32 -> V_233 ;
V_208 *= V_230 ;
memcpy ( V_175 -> V_229 , V_214 -> V_229 + V_208 ,
V_230 ) ;
}
F_138 ( V_40 , V_126 , V_202 -> V_21 , V_15 - F_129 ( V_126 ) ) ;
F_147 ( L_23
L_24 , V_215 ,
V_202 -> V_204 , V_203 , V_202 -> V_205 ) ;
V_73 = V_17 -> V_45 -> V_234 ( V_25 , V_215 , V_40 ,
V_202 -> V_204 ,
V_202 -> V_218 , 0 ) ;
return V_73 ;
}
int F_158 ( struct V_126 * V_126 , int V_94 , T_1 V_15 , T_1 V_16 )
{
int V_235 = ( V_94 == 0 ) ;
struct V_24 * V_17 ;
int V_73 ;
V_17 = & F_120 ( V_126 -> V_27 -> V_28 ) -> V_149 ;
if ( V_17 -> V_45 && V_17 -> V_45 -> V_236 ) {
V_73 = V_17 -> V_45 -> V_236 ( V_126 , V_15 ,
V_16 , NULL , V_235 ) ;
if ( V_73 )
V_235 = 0 ;
}
if ( ! V_235 ) {
F_159 ( V_126 ) ;
F_160 ( V_126 ) ;
}
return 0 ;
}
static void F_161 ( struct V_40 * V_40 , int V_94 )
{
struct V_237 * V_238 ;
T_1 V_15 ;
T_1 V_16 ;
int V_137 ;
F_162 (bvec, bio, i) {
struct V_126 * V_126 = V_238 -> V_239 ;
if ( V_238 -> V_240 || V_238 -> V_241 != V_146 ) {
if ( V_238 -> V_240 + V_238 -> V_241 != V_146 )
F_163 ( F_120 ( V_126 -> V_27 -> V_28 ) -> V_54 -> V_167 ,
L_25 ,
V_238 -> V_240 , V_238 -> V_241 ) ;
else
F_164 ( F_120 ( V_126 -> V_27 -> V_28 ) -> V_54 -> V_167 ,
L_26
L_27 ,
V_238 -> V_240 , V_238 -> V_241 ) ;
}
V_15 = F_129 ( V_126 ) ;
V_16 = V_15 + V_238 -> V_240 + V_238 -> V_241 - 1 ;
if ( F_158 ( V_126 , V_94 , V_15 , V_16 ) )
continue;
F_122 ( V_126 ) ;
}
F_137 ( V_40 ) ;
}
static void
F_165 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_21 ,
int V_235 )
{
struct V_7 * V_97 = NULL ;
T_1 V_16 = V_15 + V_21 - 1 ;
if ( V_235 && V_17 -> V_242 )
F_91 ( V_17 , V_15 , V_16 , & V_97 , V_93 ) ;
F_96 ( V_17 , V_15 , V_16 , & V_97 , V_93 ) ;
}
static void F_166 ( struct V_40 * V_40 , int V_94 )
{
struct V_237 * V_238 ;
int V_235 = F_155 ( V_243 , & V_40 -> V_244 ) ;
struct V_39 * V_245 = V_39 ( V_40 ) ;
struct V_24 * V_17 ;
T_1 V_55 = 0 ;
T_1 V_15 ;
T_1 V_16 ;
T_1 V_21 ;
T_1 V_246 = 0 ;
T_1 V_247 = 0 ;
int V_248 ;
int V_73 ;
int V_137 ;
if ( V_94 )
V_235 = 0 ;
F_162 (bvec, bio, i) {
struct V_126 * V_126 = V_238 -> V_239 ;
struct V_25 * V_25 = V_126 -> V_27 -> V_28 ;
F_147 ( L_28
L_29 , ( T_1 ) V_40 -> V_184 . V_189 , V_94 ,
V_245 -> V_170 ) ;
V_17 = & F_120 ( V_25 ) -> V_149 ;
if ( V_238 -> V_240 || V_238 -> V_241 != V_146 ) {
if ( V_238 -> V_240 + V_238 -> V_241 != V_146 )
F_163 ( F_120 ( V_126 -> V_27 -> V_28 ) -> V_54 -> V_167 ,
L_30 ,
V_238 -> V_240 , V_238 -> V_241 ) ;
else
F_164 ( F_120 ( V_126 -> V_27 -> V_28 ) -> V_54 -> V_167 ,
L_31
L_27 ,
V_238 -> V_240 , V_238 -> V_241 ) ;
}
V_15 = F_129 ( V_126 ) ;
V_16 = V_15 + V_238 -> V_240 + V_238 -> V_241 - 1 ;
V_21 = V_238 -> V_241 ;
V_248 = V_245 -> V_170 ;
if ( F_167 ( V_235 && V_17 -> V_45 &&
V_17 -> V_45 -> V_249 ) ) {
V_73 = V_17 -> V_45 -> V_249 ( V_245 , V_55 ,
V_126 , V_15 , V_16 ,
V_248 ) ;
if ( V_73 )
V_235 = 0 ;
else
F_146 ( V_15 , V_126 ) ;
}
if ( F_167 ( V_235 ) )
goto V_250;
if ( V_17 -> V_45 && V_17 -> V_45 -> V_251 ) {
V_73 = V_17 -> V_45 -> V_251 ( V_126 , V_248 ) ;
if ( ! V_73 && ! V_94 &&
F_155 ( V_243 , & V_40 -> V_244 ) )
V_235 = 1 ;
} else {
V_73 = F_149 ( V_40 , V_55 , V_126 , V_15 , V_16 ,
V_248 ) ;
if ( V_73 == 0 ) {
V_235 =
F_155 ( V_243 , & V_40 -> V_244 ) ;
if ( V_94 )
V_235 = 0 ;
continue;
}
}
V_250:
if ( F_167 ( V_235 ) ) {
T_7 V_252 = F_14 ( V_25 ) ;
T_8 V_125 = V_252 >> V_124 ;
unsigned V_55 ;
V_55 = V_252 & ( V_146 - 1 ) ;
if ( V_126 -> V_123 == V_125 && V_55 )
F_168 ( V_126 , V_55 , V_146 ) ;
F_130 ( V_126 ) ;
} else {
F_159 ( V_126 ) ;
F_160 ( V_126 ) ;
}
F_113 ( V_126 ) ;
V_55 += V_21 ;
if ( F_169 ( ! V_235 ) ) {
if ( V_247 ) {
F_165 ( V_17 ,
V_246 ,
V_247 , 1 ) ;
V_246 = 0 ;
V_247 = 0 ;
}
F_165 ( V_17 , V_15 ,
V_16 - V_15 + 1 , 0 ) ;
} else if ( ! V_247 ) {
V_246 = V_15 ;
V_247 = V_16 + 1 - V_15 ;
} else if ( V_246 + V_247 == V_15 ) {
V_247 += V_16 + 1 - V_15 ;
} else {
F_165 ( V_17 , V_246 ,
V_247 , V_235 ) ;
V_246 = V_15 ;
V_247 = V_16 + 1 - V_15 ;
}
}
if ( V_247 )
F_165 ( V_17 , V_246 , V_247 ,
V_235 ) ;
if ( V_245 -> V_253 )
V_245 -> V_253 ( V_245 , V_94 ) ;
F_137 ( V_40 ) ;
}
struct V_40 *
F_170 ( struct V_254 * V_190 , T_1 V_255 , int V_256 ,
T_3 V_257 )
{
struct V_39 * V_175 ;
struct V_40 * V_40 ;
V_40 = F_171 ( V_257 , V_256 , V_37 ) ;
if ( V_40 == NULL && ( V_258 -> V_4 & V_259 ) ) {
while ( ! V_40 && ( V_256 /= 2 ) ) {
V_40 = F_171 ( V_257 ,
V_256 , V_37 ) ;
}
}
if ( V_40 ) {
V_40 -> V_192 = V_190 ;
V_40 -> V_184 . V_189 = V_255 ;
V_175 = V_39 ( V_40 ) ;
V_175 -> V_229 = NULL ;
V_175 -> V_260 = NULL ;
V_175 -> V_253 = NULL ;
}
return V_40 ;
}
struct V_40 * F_172 ( struct V_40 * V_40 , T_3 V_261 )
{
return F_173 ( V_40 , V_261 , V_37 ) ;
}
struct V_40 * F_135 ( T_3 V_261 , unsigned int V_262 )
{
struct V_39 * V_175 ;
struct V_40 * V_40 ;
V_40 = F_171 ( V_261 , V_262 , V_37 ) ;
if ( V_40 ) {
V_175 = V_39 ( V_40 ) ;
V_175 -> V_229 = NULL ;
V_175 -> V_260 = NULL ;
V_175 -> V_253 = NULL ;
}
return V_40 ;
}
static int T_4 F_174 ( int V_263 , struct V_40 * V_40 ,
int V_170 , unsigned long V_218 )
{
int V_73 = 0 ;
struct V_237 * V_238 = V_40 -> V_264 + V_40 -> V_223 - 1 ;
struct V_126 * V_126 = V_238 -> V_239 ;
struct V_24 * V_17 = V_40 -> V_265 ;
T_1 V_15 ;
V_15 = F_129 ( V_126 ) + V_238 -> V_240 ;
V_40 -> V_265 = NULL ;
F_175 ( V_40 ) ;
if ( V_17 -> V_45 && V_17 -> V_45 -> V_234 )
V_73 = V_17 -> V_45 -> V_234 ( V_126 -> V_27 -> V_28 , V_263 , V_40 ,
V_170 , V_218 , V_15 ) ;
else
F_176 ( V_263 , V_40 ) ;
if ( F_177 ( V_40 , V_266 ) )
V_73 = - V_267 ;
F_137 ( V_40 ) ;
return V_73 ;
}
static int F_178 ( int V_263 , struct V_24 * V_17 , struct V_126 * V_126 ,
unsigned long V_55 , T_9 V_268 , struct V_40 * V_40 ,
unsigned long V_218 )
{
int V_73 = 0 ;
if ( V_17 -> V_45 && V_17 -> V_45 -> V_269 )
V_73 = V_17 -> V_45 -> V_269 ( V_263 , V_126 , V_55 , V_268 , V_40 ,
V_218 ) ;
F_68 ( V_73 < 0 ) ;
return V_73 ;
}
static int F_179 ( int V_263 , struct V_24 * V_17 ,
struct V_126 * V_126 , T_10 V_174 ,
T_9 V_268 , unsigned long V_55 ,
struct V_254 * V_190 ,
struct V_40 * * V_270 ,
unsigned long V_271 ,
T_11 V_272 ,
int V_170 ,
unsigned long V_273 ,
unsigned long V_218 )
{
int V_73 = 0 ;
struct V_40 * V_40 ;
int V_274 ;
int V_156 = 0 ;
int V_275 = V_218 & V_221 ;
int V_276 = V_273 & V_221 ;
T_9 V_277 = F_112 ( T_9 , V_268 , V_146 ) ;
if ( V_270 && * V_270 ) {
V_40 = * V_270 ;
if ( V_276 )
V_156 = V_40 -> V_184 . V_189 == V_174 ;
else
V_156 = F_180 ( V_40 ) == V_174 ;
if ( V_273 != V_218 || ! V_156 ||
F_178 ( V_263 , V_17 , V_126 , V_55 , V_277 , V_40 , V_218 ) ||
F_138 ( V_40 , V_126 , V_277 , V_55 ) < V_277 ) {
V_73 = F_174 ( V_263 , V_40 , V_170 ,
V_273 ) ;
if ( V_73 < 0 )
return V_73 ;
V_40 = NULL ;
} else {
return 0 ;
}
}
if ( V_275 )
V_274 = V_278 ;
else
V_274 = F_181 ( V_190 ) ;
V_40 = F_170 ( V_190 , V_174 , V_274 , V_122 | V_279 ) ;
if ( ! V_40 )
return - V_35 ;
F_138 ( V_40 , V_126 , V_277 , V_55 ) ;
V_40 -> V_226 = V_272 ;
V_40 -> V_265 = V_17 ;
if ( V_270 )
* V_270 = V_40 ;
else
V_73 = F_174 ( V_263 , V_40 , V_170 , V_218 ) ;
return V_73 ;
}
static void F_182 ( struct V_9 * V_10 ,
struct V_126 * V_126 )
{
if ( ! F_183 ( V_126 ) ) {
F_184 ( V_126 ) ;
F_185 ( V_126 ) ;
F_186 ( V_126 , ( unsigned long ) V_10 ) ;
} else {
F_37 ( V_126 -> V_49 != ( unsigned long ) V_10 ) ;
}
}
void F_187 ( struct V_126 * V_126 )
{
if ( ! F_183 ( V_126 ) ) {
F_184 ( V_126 ) ;
F_185 ( V_126 ) ;
F_186 ( V_126 , V_280 ) ;
}
}
static struct V_209 *
F_188 ( struct V_25 * V_25 , struct V_126 * V_126 , T_9 V_281 ,
T_1 V_15 , T_1 V_21 , T_12 * V_282 ,
struct V_209 * * V_283 )
{
struct V_209 * V_210 ;
if ( V_283 && * V_283 ) {
V_210 = * V_283 ;
if ( V_210 -> V_284 && V_15 >= V_210 -> V_15 &&
V_15 < F_189 ( V_210 ) ) {
F_78 ( & V_210 -> V_18 ) ;
return V_210 ;
}
F_154 ( V_210 ) ;
* V_283 = NULL ;
}
V_210 = V_282 ( V_25 , V_126 , V_281 , V_15 , V_21 , 0 ) ;
if ( V_283 && ! F_190 ( V_210 ) ) {
F_68 ( * V_283 ) ;
F_78 ( & V_210 -> V_18 ) ;
* V_283 = V_210 ;
}
return V_210 ;
}
static int F_191 ( struct V_24 * V_17 ,
struct V_126 * V_126 ,
T_12 * V_282 ,
struct V_209 * * V_283 ,
struct V_40 * * V_40 , int V_170 ,
unsigned long * V_218 , int V_263 )
{
struct V_25 * V_25 = V_126 -> V_27 -> V_28 ;
T_1 V_15 = F_129 ( V_126 ) ;
T_1 V_285 = V_15 + V_146 - 1 ;
T_1 V_16 ;
T_1 V_286 = V_15 ;
T_1 V_287 ;
T_1 V_288 = F_14 ( V_25 ) ;
T_1 V_219 ;
T_1 V_289 ;
T_10 V_174 ;
struct V_209 * V_210 ;
struct V_254 * V_190 ;
int V_73 ;
int V_274 = 0 ;
int V_290 = * V_218 & V_291 ;
T_9 V_281 = 0 ;
T_9 V_292 ;
T_9 V_293 ;
T_9 V_294 = V_25 -> V_32 -> V_295 ;
unsigned long V_296 = * V_218 & V_291 ;
F_187 ( V_126 ) ;
V_16 = V_285 ;
if ( ! F_192 ( V_126 ) ) {
if ( F_193 ( V_126 ) == 0 ) {
F_68 ( V_294 != V_29 ) ;
F_97 ( V_17 , V_15 , V_16 ) ;
goto V_106;
}
}
if ( V_126 -> V_123 == V_288 >> V_124 ) {
char * V_297 ;
T_9 V_298 = V_288 & ( V_146 - 1 ) ;
if ( V_298 ) {
V_292 = V_146 - V_298 ;
V_297 = F_194 ( V_126 ) ;
memset ( V_297 + V_298 , 0 , V_292 ) ;
F_195 ( V_126 ) ;
F_196 ( V_297 ) ;
}
}
while ( V_286 <= V_16 ) {
unsigned long V_299 = ( V_288 >> V_124 ) + 1 ;
if ( V_286 >= V_288 ) {
char * V_297 ;
struct V_7 * V_97 = NULL ;
V_292 = V_146 - V_281 ;
V_297 = F_194 ( V_126 ) ;
memset ( V_297 + V_281 , 0 , V_292 ) ;
F_195 ( V_126 ) ;
F_196 ( V_297 ) ;
F_91 ( V_17 , V_286 , V_286 + V_292 - 1 ,
& V_97 , V_122 ) ;
if ( ! V_290 )
F_96 ( V_17 , V_286 ,
V_286 + V_292 - 1 ,
& V_97 , V_122 ) ;
break;
}
V_210 = F_188 ( V_25 , V_126 , V_281 , V_286 ,
V_16 - V_286 + 1 , V_282 , V_283 ) ;
if ( F_190 ( V_210 ) ) {
F_160 ( V_126 ) ;
if ( ! V_290 )
F_97 ( V_17 , V_286 , V_16 ) ;
break;
}
V_287 = V_286 - V_210 -> V_15 ;
F_68 ( F_189 ( V_210 ) <= V_286 ) ;
F_68 ( V_16 < V_286 ) ;
if ( F_155 ( V_220 , & V_210 -> V_4 ) ) {
V_296 |= V_221 ;
F_156 ( & V_296 ,
V_210 -> V_222 ) ;
}
V_292 = F_124 ( F_189 ( V_210 ) - V_286 , V_16 - V_286 + 1 ) ;
V_289 = F_124 ( F_189 ( V_210 ) - 1 , V_16 ) ;
V_292 = F_197 ( V_292 , V_294 ) ;
if ( V_296 & V_221 ) {
V_293 = V_210 -> V_300 ;
V_174 = V_210 -> V_219 >> 9 ;
} else {
V_174 = ( V_210 -> V_219 + V_287 ) >> 9 ;
V_293 = V_292 ;
}
V_190 = V_210 -> V_190 ;
V_219 = V_210 -> V_219 ;
if ( F_155 ( V_301 , & V_210 -> V_4 ) )
V_219 = V_302 ;
F_154 ( V_210 ) ;
V_210 = NULL ;
if ( V_219 == V_302 ) {
char * V_297 ;
struct V_7 * V_97 = NULL ;
V_297 = F_194 ( V_126 ) ;
memset ( V_297 + V_281 , 0 , V_292 ) ;
F_195 ( V_126 ) ;
F_196 ( V_297 ) ;
F_91 ( V_17 , V_286 , V_286 + V_292 - 1 ,
& V_97 , V_122 ) ;
F_96 ( V_17 , V_286 , V_286 + V_292 - 1 ,
& V_97 , V_122 ) ;
V_286 = V_286 + V_292 ;
V_281 += V_292 ;
continue;
}
if ( F_118 ( V_17 , V_286 , V_289 ,
V_117 , 1 , NULL ) ) {
F_128 ( V_17 , V_126 ) ;
if ( ! V_290 )
F_97 ( V_17 , V_286 , V_286 + V_292 - 1 ) ;
V_286 = V_286 + V_292 ;
V_281 += V_292 ;
continue;
}
if ( V_219 == V_303 ) {
F_160 ( V_126 ) ;
if ( ! V_290 )
F_97 ( V_17 , V_286 , V_286 + V_292 - 1 ) ;
V_286 = V_286 + V_292 ;
V_281 += V_292 ;
continue;
}
V_299 -= V_126 -> V_123 ;
V_73 = F_179 ( V_263 , V_17 , V_126 ,
V_174 , V_293 , V_281 ,
V_190 , V_40 , V_299 ,
F_166 , V_170 ,
* V_218 ,
V_296 ) ;
if ( ! V_73 ) {
V_274 ++ ;
* V_218 = V_296 ;
} else {
F_160 ( V_126 ) ;
if ( ! V_290 )
F_97 ( V_17 , V_286 , V_286 + V_292 - 1 ) ;
}
V_286 = V_286 + V_292 ;
V_281 += V_292 ;
}
V_106:
if ( ! V_274 ) {
if ( ! F_198 ( V_126 ) )
F_130 ( V_126 ) ;
F_113 ( V_126 ) ;
}
return 0 ;
}
static inline void F_199 ( struct V_24 * V_17 ,
struct V_126 * V_135 [] , int V_136 ,
T_1 V_15 , T_1 V_16 ,
T_12 * V_282 ,
struct V_209 * * V_283 ,
struct V_40 * * V_40 , int V_170 ,
unsigned long * V_218 , int V_263 )
{
struct V_25 * V_25 ;
struct V_304 * V_305 ;
int V_123 ;
V_25 = V_135 [ 0 ] -> V_27 -> V_28 ;
while ( 1 ) {
F_94 ( V_17 , V_15 , V_16 ) ;
V_305 = F_200 ( V_25 , V_15 ,
V_16 - V_15 + 1 ) ;
if ( ! V_305 )
break;
F_97 ( V_17 , V_15 , V_16 ) ;
F_201 ( V_25 , V_305 , 1 ) ;
F_202 ( V_305 ) ;
}
for ( V_123 = 0 ; V_123 < V_136 ; V_123 ++ ) {
F_191 ( V_17 , V_135 [ V_123 ] , V_282 , V_283 , V_40 ,
V_170 , V_218 , V_263 ) ;
F_101 ( V_135 [ V_123 ] ) ;
}
}
static void F_203 ( struct V_24 * V_17 ,
struct V_126 * V_135 [] ,
int V_136 , T_12 * V_282 ,
struct V_209 * * V_283 ,
struct V_40 * * V_40 , int V_170 ,
unsigned long * V_218 , int V_263 )
{
T_1 V_15 = 0 ;
T_1 V_16 = 0 ;
T_1 V_306 ;
int V_123 ;
int V_307 = 0 ;
for ( V_123 = 0 ; V_123 < V_136 ; V_123 ++ ) {
V_306 = F_129 ( V_135 [ V_123 ] ) ;
if ( ! V_16 ) {
V_15 = V_306 ;
V_16 = V_15 + V_146 - 1 ;
V_307 = V_123 ;
} else if ( V_16 + 1 == V_306 ) {
V_16 += V_146 ;
} else {
F_199 ( V_17 , & V_135 [ V_307 ] ,
V_123 - V_307 , V_15 ,
V_16 , V_282 , V_283 ,
V_40 , V_170 , V_218 ,
V_263 ) ;
V_15 = V_306 ;
V_16 = V_15 + V_146 - 1 ;
V_307 = V_123 ;
}
}
if ( V_16 )
F_199 ( V_17 , & V_135 [ V_307 ] ,
V_123 - V_307 , V_15 ,
V_16 , V_282 , V_283 , V_40 ,
V_170 , V_218 , V_263 ) ;
}
static int F_204 ( struct V_24 * V_17 ,
struct V_126 * V_126 ,
T_12 * V_282 ,
struct V_40 * * V_40 , int V_170 ,
unsigned long * V_218 , int V_263 )
{
struct V_25 * V_25 = V_126 -> V_27 -> V_28 ;
struct V_304 * V_305 ;
T_1 V_15 = F_129 ( V_126 ) ;
T_1 V_16 = V_15 + V_146 - 1 ;
int V_73 ;
while ( 1 ) {
F_94 ( V_17 , V_15 , V_16 ) ;
V_305 = F_205 ( V_25 , V_15 ) ;
if ( ! V_305 )
break;
F_97 ( V_17 , V_15 , V_16 ) ;
F_201 ( V_25 , V_305 , 1 ) ;
F_202 ( V_305 ) ;
}
V_73 = F_191 ( V_17 , V_126 , V_282 , NULL , V_40 , V_170 ,
V_218 , V_263 ) ;
return V_73 ;
}
int F_206 ( struct V_24 * V_17 , struct V_126 * V_126 ,
T_12 * V_282 , int V_170 )
{
struct V_40 * V_40 = NULL ;
unsigned long V_218 = 0 ;
int V_73 ;
V_73 = F_204 ( V_17 , V_126 , V_282 , & V_40 , V_170 ,
& V_218 , V_308 ) ;
if ( V_40 )
V_73 = F_174 ( V_308 , V_40 , V_170 , V_218 ) ;
return V_73 ;
}
int F_207 ( struct V_24 * V_17 , struct V_126 * V_126 ,
T_12 * V_282 , int V_170 )
{
struct V_40 * V_40 = NULL ;
unsigned long V_218 = V_291 ;
int V_73 ;
V_73 = F_191 ( V_17 , V_126 , V_282 , NULL , & V_40 , V_170 ,
& V_218 , V_308 ) ;
if ( V_40 )
V_73 = F_174 ( V_308 , V_40 , V_170 , V_218 ) ;
return V_73 ;
}
static T_5 void F_208 ( struct V_126 * V_126 ,
struct V_309 * V_310 ,
unsigned long V_311 )
{
V_310 -> V_312 -= V_311 ;
if ( V_310 -> V_313 || ( V_310 -> V_312 > 0 &&
V_310 -> V_314 == 0 && V_310 -> V_315 == V_316 ) )
V_126 -> V_27 -> V_317 = V_126 -> V_123 + V_311 ;
}
static int F_209 ( struct V_126 * V_126 , struct V_309 * V_310 ,
void * V_318 )
{
struct V_25 * V_25 = V_126 -> V_27 -> V_28 ;
struct V_319 * V_320 = V_318 ;
struct V_24 * V_17 = V_320 -> V_17 ;
T_1 V_15 = F_129 ( V_126 ) ;
T_1 V_138 ;
T_1 V_285 = V_15 + V_146 - 1 ;
T_1 V_16 ;
T_1 V_286 = V_15 ;
T_1 V_287 ;
T_1 V_288 = F_14 ( V_25 ) ;
T_1 V_219 ;
T_1 V_292 ;
T_10 V_174 ;
struct V_7 * V_96 = NULL ;
struct V_209 * V_210 ;
struct V_254 * V_190 ;
int V_73 ;
int V_274 = 0 ;
T_9 V_281 = 0 ;
T_9 V_294 ;
T_7 V_252 = F_14 ( V_25 ) ;
unsigned long V_125 = V_252 >> V_124 ;
T_1 V_321 ;
T_1 V_139 ;
int V_322 ;
int V_323 ;
int V_324 ;
unsigned long V_311 = 0 ;
bool V_325 = true ;
if ( V_310 -> V_326 == V_327 )
V_324 = V_193 ;
else
V_324 = V_186 ;
F_210 ( V_126 , V_25 , V_310 ) ;
F_37 ( ! F_211 ( V_126 ) ) ;
F_212 ( V_126 ) ;
V_281 = V_252 & ( V_146 - 1 ) ;
if ( V_126 -> V_123 > V_125 ||
( V_126 -> V_123 == V_125 && ! V_281 ) ) {
V_126 -> V_27 -> V_328 -> V_329 ( V_126 , 0 , V_146 ) ;
F_113 ( V_126 ) ;
return 0 ;
}
if ( V_126 -> V_123 == V_125 ) {
char * V_297 ;
V_297 = F_194 ( V_126 ) ;
memset ( V_297 + V_281 , 0 ,
V_146 - V_281 ) ;
F_196 ( V_297 ) ;
F_195 ( V_126 ) ;
}
V_281 = 0 ;
F_187 ( V_126 ) ;
if ( ! V_17 -> V_45 || ! V_17 -> V_45 -> V_325 )
V_325 = false ;
V_138 = V_15 ;
V_139 = 0 ;
V_322 = 0 ;
if ( ! V_320 -> V_330 && V_325 ) {
T_1 V_331 = 0 ;
F_208 ( V_126 , V_310 , 0 ) ;
while ( V_139 < V_285 ) {
V_321 = F_117 ( V_25 , V_17 ,
V_126 ,
& V_138 ,
& V_139 ,
128 * 1024 * 1024 ) ;
if ( V_321 == 0 ) {
V_138 = V_139 + 1 ;
continue;
}
V_73 = V_17 -> V_45 -> V_325 ( V_25 , V_126 ,
V_138 ,
V_139 ,
& V_322 ,
& V_311 ) ;
if ( V_73 ) {
F_160 ( V_126 ) ;
goto V_144;
}
V_331 += ( V_139 - V_138 +
V_146 ) >>
V_124 ;
V_138 = V_139 + 1 ;
}
if ( V_310 -> V_312 < V_331 ) {
int V_332 = 8192 ;
if ( V_331 < V_332 * 2 )
V_332 = V_331 ;
V_310 -> V_312 = F_112 ( T_1 , V_331 ,
V_332 ) ;
}
if ( V_322 ) {
V_73 = 0 ;
V_310 -> V_312 -= V_311 ;
goto V_333;
}
}
if ( V_17 -> V_45 && V_17 -> V_45 -> V_334 ) {
V_73 = V_17 -> V_45 -> V_334 ( V_126 , V_15 ,
V_285 ) ;
if ( V_73 ) {
if ( V_73 == - V_335 )
V_310 -> V_336 ++ ;
else
F_213 ( V_310 , V_126 ) ;
F_208 ( V_126 , V_310 , V_311 ) ;
F_113 ( V_126 ) ;
V_73 = 0 ;
goto V_333;
}
}
F_208 ( V_126 , V_310 , V_311 + 1 ) ;
V_16 = V_285 ;
if ( V_288 <= V_15 ) {
if ( V_17 -> V_45 && V_17 -> V_45 -> V_236 )
V_17 -> V_45 -> V_236 ( V_126 , V_15 ,
V_285 , NULL , 1 ) ;
goto V_144;
}
V_294 = V_25 -> V_32 -> V_295 ;
while ( V_286 <= V_16 ) {
if ( V_286 >= V_288 ) {
if ( V_17 -> V_45 && V_17 -> V_45 -> V_236 )
V_17 -> V_45 -> V_236 ( V_126 , V_286 ,
V_285 , NULL , 1 ) ;
break;
}
V_210 = V_320 -> V_282 ( V_25 , V_126 , V_281 , V_286 ,
V_16 - V_286 + 1 , 1 ) ;
if ( F_190 ( V_210 ) ) {
F_160 ( V_126 ) ;
break;
}
V_287 = V_286 - V_210 -> V_15 ;
F_68 ( F_189 ( V_210 ) <= V_286 ) ;
F_68 ( V_16 < V_286 ) ;
V_292 = F_124 ( F_189 ( V_210 ) - V_286 , V_16 - V_286 + 1 ) ;
V_292 = F_197 ( V_292 , V_294 ) ;
V_174 = ( V_210 -> V_219 + V_287 ) >> 9 ;
V_190 = V_210 -> V_190 ;
V_219 = V_210 -> V_219 ;
V_323 = F_155 ( V_220 , & V_210 -> V_4 ) ;
F_154 ( V_210 ) ;
V_210 = NULL ;
if ( V_323 || V_219 == V_302 ||
V_219 == V_303 ) {
if ( ! V_323 && V_17 -> V_45 &&
V_17 -> V_45 -> V_236 )
V_17 -> V_45 -> V_236 ( V_126 , V_286 ,
V_286 + V_292 - 1 ,
NULL , 1 ) ;
else if ( V_323 ) {
V_274 ++ ;
}
V_286 += V_292 ;
V_281 += V_292 ;
continue;
}
if ( 0 && ! F_118 ( V_17 , V_286 , V_286 + V_292 - 1 ,
V_91 , 0 , NULL ) ) {
V_286 = V_286 + V_292 ;
V_281 += V_292 ;
continue;
}
if ( V_17 -> V_45 && V_17 -> V_45 -> V_337 ) {
V_73 = V_17 -> V_45 -> V_337 ( V_126 , V_286 ,
V_286 + V_292 - 1 ) ;
} else {
V_73 = 0 ;
}
if ( V_73 ) {
F_160 ( V_126 ) ;
} else {
unsigned long V_338 = V_125 + 1 ;
F_105 ( V_17 , V_286 , V_286 + V_292 - 1 ) ;
if ( ! F_214 ( V_126 ) ) {
F_163 ( F_120 ( V_25 ) -> V_54 -> V_167 ,
L_32 ,
V_126 -> V_123 , V_286 , V_16 ) ;
}
V_73 = F_179 ( V_324 , V_17 , V_126 ,
V_174 , V_292 , V_281 ,
V_190 , & V_320 -> V_40 , V_338 ,
F_161 ,
0 , 0 , 0 ) ;
if ( V_73 )
F_160 ( V_126 ) ;
}
V_286 = V_286 + V_292 ;
V_281 += V_292 ;
V_274 ++ ;
}
V_144:
if ( V_274 == 0 ) {
F_106 ( V_126 ) ;
F_122 ( V_126 ) ;
}
F_113 ( V_126 ) ;
V_333:
F_35 ( V_96 ) ;
return 0 ;
}
static int F_215 ( void * V_339 )
{
F_216 () ;
return 0 ;
}
void F_217 ( struct V_9 * V_10 )
{
F_218 ( & V_10 -> V_340 , V_341 , F_215 ,
V_109 ) ;
}
static int F_219 ( struct V_9 * V_10 ,
struct V_31 * V_167 ,
struct V_319 * V_320 )
{
unsigned long V_137 , V_199 ;
int V_342 = 0 ;
int V_73 = 0 ;
if ( ! F_220 ( V_10 ) ) {
V_342 = 1 ;
F_221 ( V_320 ) ;
F_222 ( V_10 ) ;
}
if ( F_155 ( V_341 , & V_10 -> V_340 ) ) {
F_223 ( V_10 ) ;
if ( ! V_320 -> V_343 )
return 0 ;
if ( ! V_342 ) {
F_221 ( V_320 ) ;
V_342 = 1 ;
}
while ( 1 ) {
F_217 ( V_10 ) ;
F_222 ( V_10 ) ;
if ( ! F_155 ( V_341 , & V_10 -> V_340 ) )
break;
F_223 ( V_10 ) ;
}
}
F_66 ( & V_10 -> V_344 ) ;
if ( F_224 ( V_345 , & V_10 -> V_340 ) ) {
F_225 ( V_341 , & V_10 -> V_340 ) ;
F_70 ( & V_10 -> V_344 ) ;
F_226 ( V_10 , V_346 ) ;
F_227 ( & V_167 -> V_347 ,
- V_10 -> V_21 ,
V_167 -> V_348 ) ;
V_73 = 1 ;
} else {
F_70 ( & V_10 -> V_344 ) ;
}
F_223 ( V_10 ) ;
if ( ! V_73 )
return V_73 ;
V_199 = F_144 ( V_10 -> V_15 , V_10 -> V_21 ) ;
for ( V_137 = 0 ; V_137 < V_199 ; V_137 ++ ) {
struct V_126 * V_59 = F_145 ( V_10 , V_137 ) ;
if ( ! F_228 ( V_59 ) ) {
if ( ! V_342 ) {
F_221 ( V_320 ) ;
V_342 = 1 ;
}
F_115 ( V_59 ) ;
}
}
return V_73 ;
}
static void F_229 ( struct V_9 * V_10 )
{
F_230 ( V_341 , & V_10 -> V_340 ) ;
F_231 () ;
F_232 ( & V_10 -> V_340 , V_341 ) ;
}
static void F_233 ( struct V_40 * V_40 , int V_94 )
{
struct V_237 * V_238 ;
struct V_9 * V_10 ;
int V_137 , V_144 ;
F_162 (bvec, bio, i) {
struct V_126 * V_126 = V_238 -> V_239 ;
V_10 = (struct V_9 * ) V_126 -> V_49 ;
F_68 ( ! V_10 ) ;
V_144 = F_36 ( & V_10 -> V_349 ) ;
if ( V_94 || F_155 ( V_350 , & V_10 -> V_340 ) ) {
F_225 ( V_350 , & V_10 -> V_340 ) ;
F_159 ( V_126 ) ;
F_160 ( V_126 ) ;
}
F_122 ( V_126 ) ;
if ( ! V_144 )
continue;
F_229 ( V_10 ) ;
}
F_137 ( V_40 ) ;
}
static int F_234 ( struct V_9 * V_10 ,
struct V_31 * V_167 ,
struct V_309 * V_310 ,
struct V_319 * V_320 )
{
struct V_254 * V_190 = V_167 -> V_227 -> V_228 ;
struct V_24 * V_17 = & F_120 ( V_167 -> V_351 ) -> V_149 ;
T_1 V_55 = V_10 -> V_15 ;
unsigned long V_137 , V_199 ;
unsigned long V_218 = 0 ;
int V_263 = ( V_320 -> V_343 ? V_193 : V_186 ) | V_352 ;
int V_73 = 0 ;
F_230 ( V_350 , & V_10 -> V_340 ) ;
V_199 = F_144 ( V_10 -> V_15 , V_10 -> V_21 ) ;
F_32 ( & V_10 -> V_349 , V_199 ) ;
if ( F_235 ( V_10 ) == V_353 )
V_218 = V_354 ;
for ( V_137 = 0 ; V_137 < V_199 ; V_137 ++ ) {
struct V_126 * V_59 = F_145 ( V_10 , V_137 ) ;
F_100 ( V_59 ) ;
F_106 ( V_59 ) ;
V_73 = F_179 ( V_263 , V_17 , V_59 , V_55 >> 9 ,
V_146 , 0 , V_190 , & V_320 -> V_40 ,
- 1 , F_233 ,
0 , V_320 -> V_218 , V_218 ) ;
V_320 -> V_218 = V_218 ;
if ( V_73 ) {
F_225 ( V_350 , & V_10 -> V_340 ) ;
F_160 ( V_59 ) ;
if ( F_236 ( V_199 - V_137 , & V_10 -> V_349 ) )
F_229 ( V_10 ) ;
V_73 = - V_183 ;
break;
}
V_55 += V_146 ;
F_208 ( V_59 , V_310 , 1 ) ;
F_113 ( V_59 ) ;
}
if ( F_169 ( V_73 ) ) {
for (; V_137 < V_199 ; V_137 ++ ) {
struct V_126 * V_59 = F_145 ( V_10 , V_137 ) ;
F_113 ( V_59 ) ;
}
}
return V_73 ;
}
int F_237 ( struct V_43 * V_27 ,
struct V_309 * V_310 )
{
struct V_24 * V_17 = & F_120 ( V_27 -> V_28 ) -> V_149 ;
struct V_31 * V_167 = F_120 ( V_27 -> V_28 ) -> V_54 -> V_167 ;
struct V_9 * V_10 , * V_355 = NULL ;
struct V_319 V_320 = {
. V_40 = NULL ,
. V_17 = V_17 ,
. V_330 = 0 ,
. V_343 = V_310 -> V_326 == V_327 ,
. V_218 = 0 ,
} ;
int V_73 = 0 ;
int V_144 = 0 ;
int V_356 = 0 ;
struct V_357 V_358 ;
int V_136 ;
T_8 V_123 ;
T_8 V_16 ;
int V_359 = 0 ;
int V_360 ;
F_238 ( & V_358 , 0 ) ;
if ( V_310 -> V_313 ) {
V_123 = V_27 -> V_317 ;
V_16 = - 1 ;
} else {
V_123 = V_310 -> V_314 >> V_124 ;
V_16 = V_310 -> V_315 >> V_124 ;
V_359 = 1 ;
}
if ( V_310 -> V_326 == V_327 )
V_360 = V_361 ;
else
V_360 = V_362 ;
V_363:
if ( V_310 -> V_326 == V_327 )
F_239 ( V_27 , V_123 , V_16 ) ;
while ( ! V_144 && ! V_356 && ( V_123 <= V_16 ) &&
( V_136 = F_240 ( & V_358 , V_27 , & V_123 , V_360 ,
F_124 ( V_16 - V_123 , ( T_8 ) V_364 - 1 ) + 1 ) ) ) {
unsigned V_137 ;
V_359 = 1 ;
for ( V_137 = 0 ; V_137 < V_136 ; V_137 ++ ) {
struct V_126 * V_126 = V_358 . V_135 [ V_137 ] ;
if ( ! F_183 ( V_126 ) )
continue;
if ( ! V_310 -> V_313 && V_126 -> V_123 > V_16 ) {
V_144 = 1 ;
break;
}
F_66 ( & V_27 -> V_365 ) ;
if ( ! F_183 ( V_126 ) ) {
F_70 ( & V_27 -> V_365 ) ;
continue;
}
V_10 = (struct V_9 * ) V_126 -> V_49 ;
if ( F_37 ( ! V_10 ) ) {
F_70 ( & V_27 -> V_365 ) ;
continue;
}
if ( V_10 == V_355 ) {
F_70 ( & V_27 -> V_365 ) ;
continue;
}
V_73 = F_241 ( & V_10 -> V_18 ) ;
F_70 ( & V_27 -> V_365 ) ;
if ( ! V_73 )
continue;
V_355 = V_10 ;
V_73 = F_219 ( V_10 , V_167 , & V_320 ) ;
if ( ! V_73 ) {
F_242 ( V_10 ) ;
continue;
}
V_73 = F_234 ( V_10 , V_167 , V_310 , & V_320 ) ;
if ( V_73 ) {
V_144 = 1 ;
F_242 ( V_10 ) ;
break;
}
F_242 ( V_10 ) ;
V_356 = V_310 -> V_312 <= 0 ;
}
F_243 ( & V_358 ) ;
F_71 () ;
}
if ( ! V_359 && ! V_144 ) {
V_359 = 1 ;
V_123 = 0 ;
goto V_363;
}
F_221 ( & V_320 ) ;
return V_73 ;
}
static int F_244 ( struct V_24 * V_17 ,
struct V_43 * V_27 ,
struct V_309 * V_310 ,
T_13 V_366 , void * V_318 ,
void (* F_245)( void * ) )
{
struct V_25 * V_25 = V_27 -> V_28 ;
int V_73 = 0 ;
int V_144 = 0 ;
int V_356 = 0 ;
struct V_357 V_358 ;
int V_136 ;
T_8 V_123 ;
T_8 V_16 ;
int V_359 = 0 ;
int V_360 ;
if ( ! F_246 ( V_25 ) )
return 0 ;
F_238 ( & V_358 , 0 ) ;
if ( V_310 -> V_313 ) {
V_123 = V_27 -> V_317 ;
V_16 = - 1 ;
} else {
V_123 = V_310 -> V_314 >> V_124 ;
V_16 = V_310 -> V_315 >> V_124 ;
V_359 = 1 ;
}
if ( V_310 -> V_326 == V_327 )
V_360 = V_361 ;
else
V_360 = V_362 ;
V_363:
if ( V_310 -> V_326 == V_327 )
F_239 ( V_27 , V_123 , V_16 ) ;
while ( ! V_144 && ! V_356 && ( V_123 <= V_16 ) &&
( V_136 = F_240 ( & V_358 , V_27 , & V_123 , V_360 ,
F_124 ( V_16 - V_123 , ( T_8 ) V_364 - 1 ) + 1 ) ) ) {
unsigned V_137 ;
V_359 = 1 ;
for ( V_137 = 0 ; V_137 < V_136 ; V_137 ++ ) {
struct V_126 * V_126 = V_358 . V_135 [ V_137 ] ;
if ( ! F_228 ( V_126 ) ) {
F_245 ( V_318 ) ;
F_115 ( V_126 ) ;
}
if ( F_169 ( V_126 -> V_27 != V_27 ) ) {
F_113 ( V_126 ) ;
continue;
}
if ( ! V_310 -> V_313 && V_126 -> V_123 > V_16 ) {
V_144 = 1 ;
F_113 ( V_126 ) ;
continue;
}
if ( V_310 -> V_326 != V_367 ) {
if ( F_214 ( V_126 ) )
F_245 ( V_318 ) ;
F_247 ( V_126 ) ;
}
if ( F_214 ( V_126 ) ||
! F_100 ( V_126 ) ) {
F_113 ( V_126 ) ;
continue;
}
V_73 = (* V_366)( V_126 , V_310 , V_318 ) ;
if ( F_169 ( V_73 == V_368 ) ) {
F_113 ( V_126 ) ;
V_73 = 0 ;
}
if ( V_73 )
V_144 = 1 ;
V_356 = V_310 -> V_312 <= 0 ;
}
F_243 ( & V_358 ) ;
F_71 () ;
}
if ( ! V_359 && ! V_144 ) {
V_359 = 1 ;
V_123 = 0 ;
goto V_363;
}
F_248 ( V_25 ) ;
return V_73 ;
}
static void F_249 ( struct V_319 * V_320 )
{
if ( V_320 -> V_40 ) {
int V_263 = V_186 ;
int V_73 ;
if ( V_320 -> V_343 )
V_263 = V_193 ;
V_73 = F_174 ( V_263 , V_320 -> V_40 , 0 , V_320 -> V_218 ) ;
F_68 ( V_73 < 0 ) ;
V_320 -> V_40 = NULL ;
}
}
static T_5 void F_221 ( void * V_318 )
{
struct V_319 * V_320 = V_318 ;
F_249 ( V_320 ) ;
}
int F_250 ( struct V_24 * V_17 , struct V_126 * V_126 ,
T_12 * V_282 ,
struct V_309 * V_310 )
{
int V_73 ;
struct V_319 V_320 = {
. V_40 = NULL ,
. V_17 = V_17 ,
. V_282 = V_282 ,
. V_330 = 0 ,
. V_343 = V_310 -> V_326 == V_327 ,
. V_218 = 0 ,
} ;
V_73 = F_209 ( V_126 , V_310 , & V_320 ) ;
F_249 ( & V_320 ) ;
return V_73 ;
}
int F_251 ( struct V_24 * V_17 , struct V_25 * V_25 ,
T_1 V_15 , T_1 V_16 , T_12 * V_282 ,
int V_369 )
{
int V_73 = 0 ;
struct V_43 * V_27 = V_25 -> V_127 ;
struct V_126 * V_126 ;
unsigned long V_136 = ( V_16 - V_15 + V_146 ) >>
V_124 ;
struct V_319 V_320 = {
. V_40 = NULL ,
. V_17 = V_17 ,
. V_282 = V_282 ,
. V_330 = 1 ,
. V_343 = V_369 == V_327 ,
. V_218 = 0 ,
} ;
struct V_309 V_370 = {
. V_326 = V_369 ,
. V_312 = V_136 * 2 ,
. V_314 = V_15 ,
. V_315 = V_16 + 1 ,
} ;
while ( V_15 <= V_16 ) {
V_126 = F_99 ( V_27 , V_15 >> V_124 ) ;
if ( F_100 ( V_126 ) )
V_73 = F_209 ( V_126 , & V_370 , & V_320 ) ;
else {
if ( V_17 -> V_45 && V_17 -> V_45 -> V_236 )
V_17 -> V_45 -> V_236 ( V_126 , V_15 ,
V_15 + V_146 - 1 ,
NULL , 1 ) ;
F_113 ( V_126 ) ;
}
F_101 ( V_126 ) ;
V_15 += V_146 ;
}
F_249 ( & V_320 ) ;
return V_73 ;
}
int F_252 ( struct V_24 * V_17 ,
struct V_43 * V_27 ,
T_12 * V_282 ,
struct V_309 * V_310 )
{
int V_73 = 0 ;
struct V_319 V_320 = {
. V_40 = NULL ,
. V_17 = V_17 ,
. V_282 = V_282 ,
. V_330 = 0 ,
. V_343 = V_310 -> V_326 == V_327 ,
. V_218 = 0 ,
} ;
V_73 = F_244 ( V_17 , V_27 , V_310 ,
F_209 , & V_320 ,
F_221 ) ;
F_249 ( & V_320 ) ;
return V_73 ;
}
int F_253 ( struct V_24 * V_17 ,
struct V_43 * V_27 ,
struct V_1 * V_135 , unsigned V_136 ,
T_12 V_282 )
{
struct V_40 * V_40 = NULL ;
unsigned V_371 ;
unsigned long V_218 = 0 ;
struct V_126 * V_372 [ 16 ] ;
struct V_126 * V_126 ;
struct V_209 * V_283 = NULL ;
int V_274 = 0 ;
for ( V_371 = 0 ; V_371 < V_136 ; V_371 ++ ) {
V_126 = F_9 ( V_135 -> V_70 , struct V_126 , V_373 ) ;
F_254 ( & V_126 -> V_4 ) ;
F_6 ( & V_126 -> V_373 ) ;
if ( F_255 ( V_126 , V_27 ,
V_126 -> V_123 , V_122 ) ) {
F_101 ( V_126 ) ;
continue;
}
V_372 [ V_274 ++ ] = V_126 ;
if ( V_274 < F_256 ( V_372 ) )
continue;
F_203 ( V_17 , V_372 , V_274 , V_282 , & V_283 ,
& V_40 , 0 , & V_218 , V_308 ) ;
V_274 = 0 ;
}
if ( V_274 )
F_203 ( V_17 , V_372 , V_274 , V_282 , & V_283 ,
& V_40 , 0 , & V_218 , V_308 ) ;
if ( V_283 )
F_154 ( V_283 ) ;
F_68 ( ! F_8 ( V_135 ) ) ;
if ( V_40 )
return F_174 ( V_308 , V_40 , 0 , V_218 ) ;
return 0 ;
}
int F_257 ( struct V_24 * V_17 ,
struct V_126 * V_126 , unsigned long V_55 )
{
struct V_7 * V_96 = NULL ;
T_1 V_15 = F_129 ( V_126 ) ;
T_1 V_16 = V_15 + V_146 - 1 ;
T_9 V_294 = V_126 -> V_27 -> V_28 -> V_32 -> V_295 ;
V_15 += F_197 ( V_55 , V_294 ) ;
if ( V_15 > V_16 )
return 0 ;
F_93 ( V_17 , V_15 , V_16 , 0 , & V_96 ) ;
F_247 ( V_126 ) ;
F_64 ( V_17 , V_15 , V_16 ,
V_121 | V_91 | V_100 |
V_119 ,
1 , 1 , & V_96 , V_122 ) ;
return 0 ;
}
static int F_258 ( struct V_211 * V_374 ,
struct V_24 * V_17 ,
struct V_126 * V_126 , T_3 V_48 )
{
T_1 V_15 = F_129 ( V_126 ) ;
T_1 V_16 = V_15 + V_146 - 1 ;
int V_73 = 1 ;
if ( F_118 ( V_17 , V_15 , V_16 ,
V_77 , 0 , NULL ) )
V_73 = 0 ;
else {
if ( ( V_48 & V_122 ) == V_122 )
V_48 = V_122 ;
V_73 = F_64 ( V_17 , V_15 , V_16 ,
~ ( V_121 | V_375 ) ,
0 , 0 , NULL , V_48 ) ;
if ( V_73 < 0 )
V_73 = 0 ;
else
V_73 = 1 ;
}
return V_73 ;
}
int F_259 ( struct V_211 * V_374 ,
struct V_24 * V_17 , struct V_126 * V_126 ,
T_3 V_48 )
{
struct V_209 * V_210 ;
T_1 V_15 = F_129 ( V_126 ) ;
T_1 V_16 = V_15 + V_146 - 1 ;
if ( ( V_48 & V_104 ) &&
V_126 -> V_27 -> V_28 -> V_252 > 16 * 1024 * 1024 ) {
T_1 V_21 ;
while ( V_15 <= V_16 ) {
V_21 = V_16 - V_15 + 1 ;
F_260 ( & V_374 -> V_47 ) ;
V_210 = F_152 ( V_374 , V_15 , V_21 ) ;
if ( ! V_210 ) {
F_261 ( & V_374 -> V_47 ) ;
break;
}
if ( F_155 ( V_376 , & V_210 -> V_4 ) ||
V_210 -> V_15 != V_15 ) {
F_261 ( & V_374 -> V_47 ) ;
F_154 ( V_210 ) ;
break;
}
if ( ! F_118 ( V_17 , V_210 -> V_15 ,
F_189 ( V_210 ) - 1 ,
V_121 | V_377 ,
0 , NULL ) ) {
F_262 ( V_374 , V_210 ) ;
F_154 ( V_210 ) ;
}
V_15 = F_189 ( V_210 ) ;
F_261 ( & V_374 -> V_47 ) ;
F_154 ( V_210 ) ;
}
}
return F_258 ( V_374 , V_17 , V_126 , V_48 ) ;
}
static struct V_209 * F_263 ( struct V_25 * V_25 ,
T_1 V_55 ,
T_1 V_157 ,
T_12 * V_282 )
{
T_1 V_378 = F_120 ( V_25 ) -> V_54 -> V_378 ;
struct V_209 * V_210 ;
T_1 V_21 ;
if ( V_55 >= V_157 )
return NULL ;
while ( 1 ) {
V_21 = V_157 - V_55 ;
if ( V_21 == 0 )
break;
V_21 = F_197 ( V_21 , V_378 ) ;
V_210 = V_282 ( V_25 , NULL , 0 , V_55 , V_21 , 0 ) ;
if ( F_190 ( V_210 ) )
return V_210 ;
if ( ! F_155 ( V_379 , & V_210 -> V_4 ) &&
V_210 -> V_219 != V_302 ) {
return V_210 ;
}
V_55 = F_189 ( V_210 ) ;
F_154 ( V_210 ) ;
if ( V_55 >= V_157 )
break;
}
return NULL ;
}
static T_5 int F_264 ( T_1 V_380 , T_1 V_55 , T_1 V_381 , void * V_382 )
{
unsigned long V_383 = * ( ( unsigned long * ) V_382 ) ;
V_383 ++ ;
* ( ( unsigned long * ) V_382 ) = V_383 ;
if ( V_383 > 1 )
return 1 ;
return 0 ;
}
int F_265 ( struct V_25 * V_25 , struct V_384 * V_385 ,
T_14 V_15 , T_14 V_21 , T_12 * V_282 )
{
int V_73 = 0 ;
T_1 V_386 = V_15 ;
T_1 F_125 = V_15 + V_21 ;
T_15 V_4 = 0 ;
T_15 V_387 ;
T_1 V_157 ;
T_1 V_388 = 0 ;
T_1 V_389 = 0 ;
T_1 V_26 = F_14 ( V_25 ) ;
struct V_390 V_391 ;
struct V_209 * V_210 = NULL ;
struct V_7 * V_96 = NULL ;
struct V_392 * V_393 ;
int V_16 = 0 ;
T_1 V_394 = 0 ;
T_1 V_395 = 0 ;
T_1 V_396 = 0 ;
if ( V_21 == 0 )
return - V_397 ;
V_393 = F_266 () ;
if ( ! V_393 )
return - V_35 ;
V_393 -> V_398 = 1 ;
V_15 = F_197 ( V_15 , F_120 ( V_25 ) -> V_54 -> V_378 ) ;
V_21 = F_197 ( V_21 , F_120 ( V_25 ) -> V_54 -> V_378 ) ;
V_73 = F_267 ( NULL , F_120 ( V_25 ) -> V_54 ,
V_393 , F_16 ( V_25 ) , - 1 , 0 ) ;
if ( V_73 < 0 ) {
F_268 ( V_393 ) ;
return V_73 ;
}
F_37 ( ! V_73 ) ;
V_393 -> V_399 [ 0 ] -- ;
F_269 ( V_393 -> V_400 [ 0 ] , & V_391 , V_393 -> V_399 [ 0 ] ) ;
V_387 = F_270 ( & V_391 ) ;
if ( V_391 . V_401 != F_16 ( V_25 ) ||
V_387 != V_402 ) {
V_157 = ( T_1 ) - 1 ;
V_388 = V_26 ;
} else {
V_157 = V_391 . V_55 ;
V_388 = V_157 + 1 ;
}
F_271 ( V_393 ) ;
if ( V_157 < V_26 ) {
V_157 = ( T_1 ) - 1 ;
V_388 = V_26 ;
}
F_93 ( & F_120 ( V_25 ) -> V_149 , V_15 , V_15 + V_21 - 1 , 0 ,
& V_96 ) ;
V_210 = F_263 ( V_25 , V_15 , V_388 ,
V_282 ) ;
if ( ! V_210 )
goto V_106;
if ( F_272 ( V_210 ) ) {
V_73 = F_273 ( V_210 ) ;
goto V_106;
}
while ( ! V_16 ) {
T_1 V_403 = 0 ;
if ( V_210 -> V_15 >= F_125 || F_189 ( V_210 ) < V_386 )
break;
V_394 = F_125 ( V_210 -> V_15 , V_386 ) ;
if ( ! F_155 ( V_220 , & V_210 -> V_4 ) )
V_403 = V_394 - V_210 -> V_15 ;
V_396 = F_189 ( V_210 ) ;
V_395 = V_396 - V_394 ;
V_389 = 0 ;
V_4 = 0 ;
V_386 = F_189 ( V_210 ) ;
if ( V_386 >= F_125 )
V_16 = 1 ;
if ( V_210 -> V_219 == V_404 ) {
V_16 = 1 ;
V_4 |= V_405 ;
} else if ( V_210 -> V_219 == V_303 ) {
V_4 |= ( V_406 |
V_407 ) ;
} else if ( V_210 -> V_219 == V_408 ) {
V_4 |= ( V_409 |
V_410 ) ;
} else {
unsigned long V_411 = 0 ;
V_389 = V_210 -> V_219 + V_403 ;
V_73 = F_274 (
V_210 -> V_219 ,
F_120 ( V_25 ) -> V_54 -> V_167 ,
V_393 , F_264 , & V_411 ) ;
if ( V_73 < 0 && V_73 != - V_158 )
goto V_412;
if ( V_411 > 1 )
V_4 |= V_413 ;
}
if ( F_155 ( V_220 , & V_210 -> V_4 ) )
V_4 |= V_414 ;
F_154 ( V_210 ) ;
V_210 = NULL ;
if ( ( V_394 >= V_157 ) || V_395 == ( T_1 ) - 1 ||
( V_157 == ( T_1 ) - 1 && V_26 <= V_396 ) ) {
V_4 |= V_405 ;
V_16 = 1 ;
}
V_210 = F_263 ( V_25 , V_386 , V_388 ,
V_282 ) ;
if ( F_272 ( V_210 ) ) {
V_73 = F_273 ( V_210 ) ;
goto V_106;
}
if ( ! V_210 ) {
V_4 |= V_405 ;
V_16 = 1 ;
}
V_73 = F_275 ( V_385 , V_394 , V_389 ,
V_395 , V_4 ) ;
if ( V_73 )
goto V_412;
}
V_412:
F_154 ( V_210 ) ;
V_106:
F_268 ( V_393 ) ;
F_96 ( & F_120 ( V_25 ) -> V_149 , V_15 , V_15 + V_21 - 1 ,
& V_96 , V_122 ) ;
return V_73 ;
}
static void F_276 ( struct V_9 * V_10 )
{
F_5 ( & V_10 -> V_13 ) ;
F_12 ( V_22 , V_10 ) ;
}
static int F_277 ( struct V_9 * V_10 )
{
return ( F_11 ( & V_10 -> V_349 ) ||
F_155 ( V_341 , & V_10 -> V_340 ) ||
F_155 ( V_345 , & V_10 -> V_340 ) ) ;
}
static void F_278 ( struct V_9 * V_10 ,
unsigned long V_415 )
{
unsigned long V_123 ;
unsigned long V_199 ;
struct V_126 * V_126 ;
int V_416 = ! F_155 ( V_417 , & V_10 -> V_340 ) ;
F_68 ( F_277 ( V_10 ) ) ;
V_199 = F_144 ( V_10 -> V_15 , V_10 -> V_21 ) ;
V_123 = V_415 + V_199 ;
if ( V_415 >= V_123 )
return;
do {
V_123 -- ;
V_126 = F_145 ( V_10 , V_123 ) ;
if ( V_126 && V_416 ) {
F_66 ( & V_126 -> V_27 -> V_365 ) ;
if ( F_183 ( V_126 ) &&
V_126 -> V_49 == ( unsigned long ) V_10 ) {
F_68 ( F_155 ( V_345 , & V_10 -> V_340 ) ) ;
F_68 ( F_116 ( V_126 ) ) ;
F_68 ( F_214 ( V_126 ) ) ;
F_279 ( V_126 ) ;
F_186 ( V_126 , 0 ) ;
F_101 ( V_126 ) ;
}
F_70 ( & V_126 -> V_27 -> V_365 ) ;
}
if ( V_126 ) {
F_101 ( V_126 ) ;
}
} while ( V_123 != V_415 );
}
static inline void F_280 ( struct V_9 * V_10 )
{
F_278 ( V_10 , 0 ) ;
F_276 ( V_10 ) ;
}
static struct V_9 *
F_281 ( struct V_31 * V_167 , T_1 V_15 ,
unsigned long V_21 , T_3 V_48 )
{
struct V_9 * V_10 = NULL ;
V_10 = F_282 ( V_22 , V_48 ) ;
if ( V_10 == NULL )
return NULL ;
V_10 -> V_15 = V_15 ;
V_10 -> V_21 = V_21 ;
V_10 -> V_167 = V_167 ;
V_10 -> V_340 = 0 ;
F_283 ( & V_10 -> V_47 ) ;
F_32 ( & V_10 -> V_418 , 0 ) ;
F_32 ( & V_10 -> V_419 , 0 ) ;
F_32 ( & V_10 -> V_420 , 0 ) ;
F_32 ( & V_10 -> V_421 , 0 ) ;
F_32 ( & V_10 -> V_422 , 0 ) ;
F_32 ( & V_10 -> V_423 , 0 ) ;
V_10 -> V_424 = 0 ;
F_33 ( & V_10 -> V_425 ) ;
F_33 ( & V_10 -> V_426 ) ;
F_1 ( & V_10 -> V_13 , & V_20 ) ;
F_29 ( & V_10 -> V_344 ) ;
F_32 ( & V_10 -> V_18 , 1 ) ;
F_32 ( & V_10 -> V_349 , 0 ) ;
F_284 ( V_427
> V_428 ) ;
F_68 ( V_21 > V_428 ) ;
return V_10 ;
}
struct V_9 * F_285 ( struct V_9 * V_429 )
{
unsigned long V_137 ;
struct V_126 * V_59 ;
struct V_9 * V_2 ;
unsigned long V_199 = F_144 ( V_429 -> V_15 , V_429 -> V_21 ) ;
V_2 = F_281 ( NULL , V_429 -> V_15 , V_429 -> V_21 , V_122 ) ;
if ( V_2 == NULL )
return NULL ;
for ( V_137 = 0 ; V_137 < V_199 ; V_137 ++ ) {
V_59 = F_286 ( V_122 ) ;
if ( ! V_59 ) {
F_280 ( V_2 ) ;
return NULL ;
}
F_182 ( V_2 , V_59 ) ;
F_37 ( F_116 ( V_59 ) ) ;
F_130 ( V_59 ) ;
V_2 -> V_135 [ V_137 ] = V_59 ;
}
F_287 ( V_2 , V_429 , 0 , 0 , V_429 -> V_21 ) ;
F_225 ( V_430 , & V_2 -> V_340 ) ;
F_225 ( V_417 , & V_2 -> V_340 ) ;
return V_2 ;
}
struct V_9 * F_288 ( T_1 V_15 , unsigned long V_21 )
{
struct V_9 * V_10 ;
unsigned long V_199 = F_144 ( 0 , V_21 ) ;
unsigned long V_137 ;
V_10 = F_281 ( NULL , V_15 , V_21 , V_122 ) ;
if ( ! V_10 )
return NULL ;
for ( V_137 = 0 ; V_137 < V_199 ; V_137 ++ ) {
V_10 -> V_135 [ V_137 ] = F_286 ( V_122 ) ;
if ( ! V_10 -> V_135 [ V_137 ] )
goto V_94;
}
F_289 ( V_10 ) ;
F_290 ( V_10 , 0 ) ;
F_225 ( V_417 , & V_10 -> V_340 ) ;
return V_10 ;
V_94:
for (; V_137 > 0 ; V_137 -- )
F_291 ( V_10 -> V_135 [ V_137 - 1 ] ) ;
F_276 ( V_10 ) ;
return NULL ;
}
static void F_292 ( struct V_9 * V_10 )
{
int V_18 ;
V_18 = F_11 ( & V_10 -> V_18 ) ;
if ( V_18 >= 2 && F_155 ( V_431 , & V_10 -> V_340 ) )
return;
F_66 ( & V_10 -> V_344 ) ;
if ( ! F_293 ( V_431 , & V_10 -> V_340 ) )
F_78 ( & V_10 -> V_18 ) ;
F_70 ( & V_10 -> V_344 ) ;
}
static void F_294 ( struct V_9 * V_10 )
{
unsigned long V_199 , V_137 ;
F_292 ( V_10 ) ;
V_199 = F_144 ( V_10 -> V_15 , V_10 -> V_21 ) ;
for ( V_137 = 0 ; V_137 < V_199 ; V_137 ++ ) {
struct V_126 * V_59 = F_145 ( V_10 , V_137 ) ;
F_295 ( V_59 ) ;
}
}
struct V_9 * F_296 ( struct V_31 * V_167 ,
T_1 V_15 )
{
struct V_9 * V_10 ;
F_297 () ;
V_10 = F_298 ( & V_167 -> V_432 ,
V_15 >> V_124 ) ;
if ( V_10 && F_241 ( & V_10 -> V_18 ) ) {
F_299 () ;
F_294 ( V_10 ) ;
return V_10 ;
}
F_299 () ;
return NULL ;
}
struct V_9 * F_300 ( struct V_31 * V_167 ,
T_1 V_15 , unsigned long V_21 )
{
unsigned long V_199 = F_144 ( V_15 , V_21 ) ;
unsigned long V_137 ;
unsigned long V_123 = V_15 >> V_124 ;
struct V_9 * V_10 ;
struct V_9 * V_433 = NULL ;
struct V_126 * V_59 ;
struct V_43 * V_27 = V_167 -> V_351 -> V_127 ;
int V_235 = 1 ;
int V_73 ;
V_10 = F_296 ( V_167 , V_15 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_281 ( V_167 , V_15 , V_21 , V_122 ) ;
if ( ! V_10 )
return NULL ;
for ( V_137 = 0 ; V_137 < V_199 ; V_137 ++ , V_123 ++ ) {
V_59 = F_301 ( V_27 , V_123 , V_122 ) ;
if ( ! V_59 )
goto V_434;
F_66 ( & V_27 -> V_365 ) ;
if ( F_183 ( V_59 ) ) {
V_433 = (struct V_9 * ) V_59 -> V_49 ;
if ( F_241 ( & V_433 -> V_18 ) ) {
F_70 ( & V_27 -> V_365 ) ;
F_113 ( V_59 ) ;
F_101 ( V_59 ) ;
F_294 ( V_433 ) ;
goto V_434;
}
F_279 ( V_59 ) ;
F_37 ( F_116 ( V_59 ) ) ;
F_101 ( V_59 ) ;
}
F_182 ( V_10 , V_59 ) ;
F_70 ( & V_27 -> V_365 ) ;
F_37 ( F_116 ( V_59 ) ) ;
F_295 ( V_59 ) ;
V_10 -> V_135 [ V_137 ] = V_59 ;
if ( ! F_192 ( V_59 ) )
V_235 = 0 ;
}
if ( V_235 )
F_225 ( V_430 , & V_10 -> V_340 ) ;
V_103:
V_73 = F_302 ( V_122 & ~ V_435 ) ;
if ( V_73 )
goto V_434;
F_66 ( & V_167 -> V_436 ) ;
V_73 = F_303 ( & V_167 -> V_432 ,
V_15 >> V_124 , V_10 ) ;
F_70 ( & V_167 -> V_436 ) ;
F_304 () ;
if ( V_73 == - V_83 ) {
V_433 = F_296 ( V_167 , V_15 ) ;
if ( V_433 )
goto V_434;
else
goto V_103;
}
F_292 ( V_10 ) ;
F_225 ( V_437 , & V_10 -> V_340 ) ;
F_305 ( V_10 -> V_135 [ 0 ] ) ;
for ( V_137 = 1 ; V_137 < V_199 ; V_137 ++ ) {
V_59 = F_145 ( V_10 , V_137 ) ;
F_306 ( V_59 ) ;
F_113 ( V_59 ) ;
}
F_113 ( V_10 -> V_135 [ 0 ] ) ;
return V_10 ;
V_434:
for ( V_137 = 0 ; V_137 < V_199 ; V_137 ++ ) {
if ( V_10 -> V_135 [ V_137 ] )
F_113 ( V_10 -> V_135 [ V_137 ] ) ;
}
F_37 ( ! F_36 ( & V_10 -> V_18 ) ) ;
F_280 ( V_10 ) ;
return V_433 ;
}
static inline void F_307 ( struct V_438 * V_3 )
{
struct V_9 * V_10 =
F_308 ( V_3 , struct V_9 , V_438 ) ;
F_276 ( V_10 ) ;
}
static int F_309 ( struct V_9 * V_10 )
{
F_37 ( F_11 ( & V_10 -> V_18 ) == 0 ) ;
if ( F_36 ( & V_10 -> V_18 ) ) {
if ( F_224 ( V_437 , & V_10 -> V_340 ) ) {
struct V_31 * V_167 = V_10 -> V_167 ;
F_70 ( & V_10 -> V_344 ) ;
F_66 ( & V_167 -> V_436 ) ;
F_310 ( & V_167 -> V_432 ,
V_10 -> V_15 >> V_124 ) ;
F_70 ( & V_167 -> V_436 ) ;
} else {
F_70 ( & V_10 -> V_344 ) ;
}
F_278 ( V_10 , 0 ) ;
F_311 ( & V_10 -> V_438 , F_307 ) ;
return 1 ;
}
F_70 ( & V_10 -> V_344 ) ;
return 0 ;
}
void F_242 ( struct V_9 * V_10 )
{
int V_18 ;
int V_439 ;
if ( ! V_10 )
return;
while ( 1 ) {
V_18 = F_11 ( & V_10 -> V_18 ) ;
if ( V_18 <= 3 )
break;
V_439 = F_312 ( & V_10 -> V_18 , V_18 , V_18 - 1 ) ;
if ( V_439 == V_18 )
return;
}
F_66 ( & V_10 -> V_344 ) ;
if ( F_11 ( & V_10 -> V_18 ) == 2 &&
F_155 ( V_417 , & V_10 -> V_340 ) )
F_67 ( & V_10 -> V_18 ) ;
if ( F_11 ( & V_10 -> V_18 ) == 2 &&
F_155 ( V_440 , & V_10 -> V_340 ) &&
! F_277 ( V_10 ) &&
F_224 ( V_431 , & V_10 -> V_340 ) )
F_67 ( & V_10 -> V_18 ) ;
F_309 ( V_10 ) ;
}
void F_313 ( struct V_9 * V_10 )
{
if ( ! V_10 )
return;
F_66 ( & V_10 -> V_344 ) ;
F_225 ( V_440 , & V_10 -> V_340 ) ;
if ( F_11 ( & V_10 -> V_18 ) == 2 && ! F_277 ( V_10 ) &&
F_224 ( V_431 , & V_10 -> V_340 ) )
F_67 ( & V_10 -> V_18 ) ;
F_309 ( V_10 ) ;
}
void F_314 ( struct V_9 * V_10 )
{
unsigned long V_137 ;
unsigned long V_199 ;
struct V_126 * V_126 ;
V_199 = F_144 ( V_10 -> V_15 , V_10 -> V_21 ) ;
for ( V_137 = 0 ; V_137 < V_199 ; V_137 ++ ) {
V_126 = F_145 ( V_10 , V_137 ) ;
if ( ! F_116 ( V_126 ) )
continue;
F_115 ( V_126 ) ;
F_37 ( ! F_183 ( V_126 ) ) ;
F_100 ( V_126 ) ;
F_315 ( & V_126 -> V_27 -> V_441 ) ;
if ( ! F_116 ( V_126 ) ) {
F_316 ( & V_126 -> V_27 -> V_442 ,
F_317 ( V_126 ) ,
V_362 ) ;
}
F_318 ( & V_126 -> V_27 -> V_441 ) ;
F_212 ( V_126 ) ;
F_113 ( V_126 ) ;
}
F_37 ( F_11 ( & V_10 -> V_18 ) == 0 ) ;
}
int F_319 ( struct V_9 * V_10 )
{
unsigned long V_137 ;
unsigned long V_199 ;
int V_443 = 0 ;
F_292 ( V_10 ) ;
V_443 = F_293 ( V_345 , & V_10 -> V_340 ) ;
V_199 = F_144 ( V_10 -> V_15 , V_10 -> V_21 ) ;
F_37 ( F_11 ( & V_10 -> V_18 ) == 0 ) ;
F_37 ( ! F_155 ( V_431 , & V_10 -> V_340 ) ) ;
for ( V_137 = 0 ; V_137 < V_199 ; V_137 ++ )
F_320 ( F_145 ( V_10 , V_137 ) ) ;
return V_443 ;
}
int F_321 ( struct V_9 * V_10 )
{
unsigned long V_137 ;
struct V_126 * V_126 ;
unsigned long V_199 ;
F_230 ( V_430 , & V_10 -> V_340 ) ;
V_199 = F_144 ( V_10 -> V_15 , V_10 -> V_21 ) ;
for ( V_137 = 0 ; V_137 < V_199 ; V_137 ++ ) {
V_126 = F_145 ( V_10 , V_137 ) ;
if ( V_126 )
F_159 ( V_126 ) ;
}
return 0 ;
}
int F_289 ( struct V_9 * V_10 )
{
unsigned long V_137 ;
struct V_126 * V_126 ;
unsigned long V_199 ;
F_225 ( V_430 , & V_10 -> V_340 ) ;
V_199 = F_144 ( V_10 -> V_15 , V_10 -> V_21 ) ;
for ( V_137 = 0 ; V_137 < V_199 ; V_137 ++ ) {
V_126 = F_145 ( V_10 , V_137 ) ;
F_130 ( V_126 ) ;
}
return 0 ;
}
int F_322 ( struct V_9 * V_10 )
{
return F_155 ( V_430 , & V_10 -> V_340 ) ;
}
int F_323 ( struct V_24 * V_17 ,
struct V_9 * V_10 , T_1 V_15 , int V_108 ,
T_12 * V_282 , int V_170 )
{
unsigned long V_137 ;
unsigned long V_444 ;
struct V_126 * V_126 ;
int V_94 ;
int V_73 = 0 ;
int V_445 = 0 ;
int V_446 = 1 ;
unsigned long V_199 ;
unsigned long V_447 = 0 ;
struct V_40 * V_40 = NULL ;
unsigned long V_218 = 0 ;
if ( F_155 ( V_430 , & V_10 -> V_340 ) )
return 0 ;
if ( V_15 ) {
F_37 ( V_15 < V_10 -> V_15 ) ;
V_444 = ( V_15 >> V_124 ) -
( V_10 -> V_15 >> V_124 ) ;
} else {
V_444 = 0 ;
}
V_199 = F_144 ( V_10 -> V_15 , V_10 -> V_21 ) ;
for ( V_137 = V_444 ; V_137 < V_199 ; V_137 ++ ) {
V_126 = F_145 ( V_10 , V_137 ) ;
if ( V_108 == V_448 ) {
if ( ! F_228 ( V_126 ) )
goto V_449;
} else {
F_115 ( V_126 ) ;
}
V_445 ++ ;
if ( ! F_192 ( V_126 ) ) {
V_447 ++ ;
V_446 = 0 ;
}
}
if ( V_446 ) {
if ( V_444 == 0 )
F_225 ( V_430 , & V_10 -> V_340 ) ;
goto V_449;
}
F_230 ( V_350 , & V_10 -> V_340 ) ;
V_10 -> V_450 = 0 ;
F_32 ( & V_10 -> V_349 , V_447 ) ;
for ( V_137 = V_444 ; V_137 < V_199 ; V_137 ++ ) {
V_126 = F_145 ( V_10 , V_137 ) ;
if ( ! F_192 ( V_126 ) ) {
F_212 ( V_126 ) ;
V_94 = F_204 ( V_17 , V_126 ,
V_282 , & V_40 ,
V_170 , & V_218 ,
V_308 | V_352 ) ;
if ( V_94 )
V_73 = V_94 ;
} else {
F_113 ( V_126 ) ;
}
}
if ( V_40 ) {
V_94 = F_174 ( V_308 | V_352 , V_40 , V_170 ,
V_218 ) ;
if ( V_94 )
return V_94 ;
}
if ( V_73 || V_108 != V_451 )
return V_73 ;
for ( V_137 = V_444 ; V_137 < V_199 ; V_137 ++ ) {
V_126 = F_145 ( V_10 , V_137 ) ;
F_324 ( V_126 ) ;
if ( ! F_192 ( V_126 ) )
V_73 = - V_183 ;
}
return V_73 ;
V_449:
V_137 = V_444 ;
while ( V_445 > 0 ) {
V_126 = F_145 ( V_10 , V_137 ) ;
V_137 ++ ;
F_113 ( V_126 ) ;
V_445 -- ;
}
return V_73 ;
}
void F_325 ( struct V_9 * V_10 , void * V_452 ,
unsigned long V_15 ,
unsigned long V_21 )
{
T_9 V_286 ;
T_9 V_55 ;
struct V_126 * V_126 ;
char * V_453 ;
char * V_454 = ( char * ) V_452 ;
T_9 V_455 = V_10 -> V_15 & ( ( T_1 ) V_146 - 1 ) ;
unsigned long V_137 = ( V_455 + V_15 ) >> V_124 ;
F_37 ( V_15 > V_10 -> V_21 ) ;
F_37 ( V_15 + V_21 > V_10 -> V_15 + V_10 -> V_21 ) ;
V_55 = ( V_455 + V_15 ) & ( V_146 - 1 ) ;
while ( V_21 > 0 ) {
V_126 = F_145 ( V_10 , V_137 ) ;
V_286 = F_124 ( V_21 , ( V_146 - V_55 ) ) ;
V_453 = F_326 ( V_126 ) ;
memcpy ( V_454 , V_453 + V_55 , V_286 ) ;
V_454 += V_286 ;
V_21 -= V_286 ;
V_55 = 0 ;
V_137 ++ ;
}
}
int F_327 ( struct V_9 * V_10 , unsigned long V_15 ,
unsigned long V_456 , char * * V_374 ,
unsigned long * V_457 ,
unsigned long * V_458 )
{
T_9 V_55 = V_15 & ( V_146 - 1 ) ;
char * V_453 ;
struct V_126 * V_59 ;
T_9 V_455 = V_10 -> V_15 & ( ( T_1 ) V_146 - 1 ) ;
unsigned long V_137 = ( V_455 + V_15 ) >> V_124 ;
unsigned long V_459 = ( V_455 + V_15 + V_456 - 1 ) >>
V_124 ;
if ( V_137 != V_459 )
return - V_397 ;
if ( V_137 == 0 ) {
V_55 = V_455 ;
* V_457 = 0 ;
} else {
V_55 = 0 ;
* V_457 = ( ( T_1 ) V_137 << V_124 ) - V_455 ;
}
if ( V_15 + V_456 > V_10 -> V_21 ) {
F_54 ( 1 , V_14 L_33
L_34 ,
V_10 -> V_15 , V_10 -> V_21 , V_15 , V_456 ) ;
return - V_397 ;
}
V_59 = F_145 ( V_10 , V_137 ) ;
V_453 = F_326 ( V_59 ) ;
* V_374 = V_453 + V_55 ;
* V_458 = V_146 - V_55 ;
return 0 ;
}
int F_328 ( struct V_9 * V_10 , const void * V_460 ,
unsigned long V_15 ,
unsigned long V_21 )
{
T_9 V_286 ;
T_9 V_55 ;
struct V_126 * V_126 ;
char * V_453 ;
char * V_461 = ( char * ) V_460 ;
T_9 V_455 = V_10 -> V_15 & ( ( T_1 ) V_146 - 1 ) ;
unsigned long V_137 = ( V_455 + V_15 ) >> V_124 ;
int V_73 = 0 ;
F_37 ( V_15 > V_10 -> V_21 ) ;
F_37 ( V_15 + V_21 > V_10 -> V_15 + V_10 -> V_21 ) ;
V_55 = ( V_455 + V_15 ) & ( V_146 - 1 ) ;
while ( V_21 > 0 ) {
V_126 = F_145 ( V_10 , V_137 ) ;
V_286 = F_124 ( V_21 , ( V_146 - V_55 ) ) ;
V_453 = F_326 ( V_126 ) ;
V_73 = memcmp ( V_461 , V_453 + V_55 , V_286 ) ;
if ( V_73 )
break;
V_461 += V_286 ;
V_21 -= V_286 ;
V_55 = 0 ;
V_137 ++ ;
}
return V_73 ;
}
void F_329 ( struct V_9 * V_10 , const void * V_462 ,
unsigned long V_15 , unsigned long V_21 )
{
T_9 V_286 ;
T_9 V_55 ;
struct V_126 * V_126 ;
char * V_453 ;
char * V_429 = ( char * ) V_462 ;
T_9 V_455 = V_10 -> V_15 & ( ( T_1 ) V_146 - 1 ) ;
unsigned long V_137 = ( V_455 + V_15 ) >> V_124 ;
F_37 ( V_15 > V_10 -> V_21 ) ;
F_37 ( V_15 + V_21 > V_10 -> V_15 + V_10 -> V_21 ) ;
V_55 = ( V_455 + V_15 ) & ( V_146 - 1 ) ;
while ( V_21 > 0 ) {
V_126 = F_145 ( V_10 , V_137 ) ;
F_37 ( ! F_192 ( V_126 ) ) ;
V_286 = F_124 ( V_21 , V_146 - V_55 ) ;
V_453 = F_326 ( V_126 ) ;
memcpy ( V_453 + V_55 , V_429 , V_286 ) ;
V_429 += V_286 ;
V_21 -= V_286 ;
V_55 = 0 ;
V_137 ++ ;
}
}
void F_330 ( struct V_9 * V_10 , char V_463 ,
unsigned long V_15 , unsigned long V_21 )
{
T_9 V_286 ;
T_9 V_55 ;
struct V_126 * V_126 ;
char * V_453 ;
T_9 V_455 = V_10 -> V_15 & ( ( T_1 ) V_146 - 1 ) ;
unsigned long V_137 = ( V_455 + V_15 ) >> V_124 ;
F_37 ( V_15 > V_10 -> V_21 ) ;
F_37 ( V_15 + V_21 > V_10 -> V_15 + V_10 -> V_21 ) ;
V_55 = ( V_455 + V_15 ) & ( V_146 - 1 ) ;
while ( V_21 > 0 ) {
V_126 = F_145 ( V_10 , V_137 ) ;
F_37 ( ! F_192 ( V_126 ) ) ;
V_286 = F_124 ( V_21 , V_146 - V_55 ) ;
V_453 = F_326 ( V_126 ) ;
memset ( V_453 + V_55 , V_463 , V_286 ) ;
V_21 -= V_286 ;
V_55 = 0 ;
V_137 ++ ;
}
}
void F_287 ( struct V_9 * V_454 , struct V_9 * V_429 ,
unsigned long V_464 , unsigned long V_465 ,
unsigned long V_21 )
{
T_1 V_466 = V_454 -> V_21 ;
T_9 V_286 ;
T_9 V_55 ;
struct V_126 * V_126 ;
char * V_453 ;
T_9 V_455 = V_454 -> V_15 & ( ( T_1 ) V_146 - 1 ) ;
unsigned long V_137 = ( V_455 + V_464 ) >> V_124 ;
F_37 ( V_429 -> V_21 != V_466 ) ;
V_55 = ( V_455 + V_464 ) &
( V_146 - 1 ) ;
while ( V_21 > 0 ) {
V_126 = F_145 ( V_454 , V_137 ) ;
F_37 ( ! F_192 ( V_126 ) ) ;
V_286 = F_124 ( V_21 , ( unsigned long ) ( V_146 - V_55 ) ) ;
V_453 = F_326 ( V_126 ) ;
F_325 ( V_429 , V_453 + V_55 , V_465 , V_286 ) ;
V_465 += V_286 ;
V_21 -= V_286 ;
V_55 = 0 ;
V_137 ++ ;
}
}
static inline bool F_331 ( unsigned long V_429 , unsigned long V_454 , unsigned long V_21 )
{
unsigned long V_467 = ( V_429 > V_454 ) ? V_429 - V_454 : V_454 - V_429 ;
return V_467 < V_21 ;
}
static void F_332 ( struct V_126 * V_468 , struct V_126 * V_469 ,
unsigned long V_470 , unsigned long V_471 ,
unsigned long V_21 )
{
char * V_472 = F_326 ( V_468 ) ;
char * V_473 ;
int V_474 = 0 ;
if ( V_468 != V_469 ) {
V_473 = F_326 ( V_469 ) ;
} else {
V_473 = V_472 ;
if ( F_331 ( V_471 , V_470 , V_21 ) )
V_474 = 1 ;
}
if ( V_474 )
memmove ( V_472 + V_470 , V_473 + V_471 , V_21 ) ;
else
memcpy ( V_472 + V_470 , V_473 + V_471 , V_21 ) ;
}
void F_333 ( struct V_9 * V_454 , unsigned long V_464 ,
unsigned long V_465 , unsigned long V_21 )
{
T_9 V_286 ;
T_9 V_475 ;
T_9 V_476 ;
T_9 V_455 = V_454 -> V_15 & ( ( T_1 ) V_146 - 1 ) ;
unsigned long V_477 ;
unsigned long V_478 ;
if ( V_465 + V_21 > V_454 -> V_21 ) {
F_10 ( V_14 L_35
L_36 , V_465 , V_21 , V_454 -> V_21 ) ;
F_68 ( 1 ) ;
}
if ( V_464 + V_21 > V_454 -> V_21 ) {
F_10 ( V_14 L_37
L_36 , V_464 , V_21 , V_454 -> V_21 ) ;
F_68 ( 1 ) ;
}
while ( V_21 > 0 ) {
V_475 = ( V_455 + V_464 ) &
( V_146 - 1 ) ;
V_476 = ( V_455 + V_465 ) &
( V_146 - 1 ) ;
V_477 = ( V_455 + V_464 ) >> V_124 ;
V_478 = ( V_455 + V_465 ) >> V_124 ;
V_286 = F_124 ( V_21 , ( unsigned long ) ( V_146 -
V_476 ) ) ;
V_286 = F_112 (unsigned long, cur,
(unsigned long)(PAGE_CACHE_SIZE - dst_off_in_page)) ;
F_332 ( F_145 ( V_454 , V_477 ) ,
F_145 ( V_454 , V_478 ) ,
V_475 , V_476 , V_286 ) ;
V_465 += V_286 ;
V_464 += V_286 ;
V_21 -= V_286 ;
}
}
void F_334 ( struct V_9 * V_454 , unsigned long V_464 ,
unsigned long V_465 , unsigned long V_21 )
{
T_9 V_286 ;
T_9 V_475 ;
T_9 V_476 ;
unsigned long V_479 = V_464 + V_21 - 1 ;
unsigned long V_480 = V_465 + V_21 - 1 ;
T_9 V_455 = V_454 -> V_15 & ( ( T_1 ) V_146 - 1 ) ;
unsigned long V_477 ;
unsigned long V_478 ;
if ( V_465 + V_21 > V_454 -> V_21 ) {
F_10 ( V_14 L_35
L_38 , V_465 , V_21 , V_454 -> V_21 ) ;
F_68 ( 1 ) ;
}
if ( V_464 + V_21 > V_454 -> V_21 ) {
F_10 ( V_14 L_37
L_38 , V_464 , V_21 , V_454 -> V_21 ) ;
F_68 ( 1 ) ;
}
if ( V_464 < V_465 ) {
F_333 ( V_454 , V_464 , V_465 , V_21 ) ;
return;
}
while ( V_21 > 0 ) {
V_477 = ( V_455 + V_479 ) >> V_124 ;
V_478 = ( V_455 + V_480 ) >> V_124 ;
V_475 = ( V_455 + V_479 ) &
( V_146 - 1 ) ;
V_476 = ( V_455 + V_480 ) &
( V_146 - 1 ) ;
V_286 = F_112 (unsigned long, len, src_off_in_page + 1 ) ;
V_286 = F_124 ( V_286 , V_475 + 1 ) ;
F_332 ( F_145 ( V_454 , V_477 ) ,
F_145 ( V_454 , V_478 ) ,
V_475 - V_286 + 1 ,
V_476 - V_286 + 1 , V_286 ) ;
V_479 -= V_286 ;
V_480 -= V_286 ;
V_21 -= V_286 ;
}
}
int F_335 ( struct V_126 * V_126 )
{
struct V_9 * V_10 ;
F_66 ( & V_126 -> V_27 -> V_365 ) ;
if ( ! F_183 ( V_126 ) ) {
F_70 ( & V_126 -> V_27 -> V_365 ) ;
return 1 ;
}
V_10 = (struct V_9 * ) V_126 -> V_49 ;
F_68 ( ! V_10 ) ;
F_66 ( & V_10 -> V_344 ) ;
if ( F_11 ( & V_10 -> V_18 ) != 1 || F_277 ( V_10 ) ) {
F_70 ( & V_10 -> V_344 ) ;
F_70 ( & V_126 -> V_27 -> V_365 ) ;
return 0 ;
}
F_70 ( & V_126 -> V_27 -> V_365 ) ;
if ( ! F_224 ( V_431 , & V_10 -> V_340 ) ) {
F_70 ( & V_10 -> V_344 ) ;
return 0 ;
}
return F_309 ( V_10 ) ;
}
