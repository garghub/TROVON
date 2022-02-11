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
static struct V_52 * F_39 ( struct V_53 * V_54 ,
struct V_52 * V_55 ,
T_1 V_56 ,
struct V_52 * V_57 ,
struct V_52 * * * V_58 ,
struct V_52 * * V_59 )
{
struct V_52 * * V_60 ;
struct V_52 * V_61 = NULL ;
struct V_62 * V_6 ;
if ( V_58 && V_59 ) {
V_60 = * V_58 ;
V_61 = * V_59 ;
goto V_63;
}
V_60 = V_55 ? & V_55 : & V_54 -> V_52 ;
while ( * V_60 ) {
V_61 = * V_60 ;
V_6 = F_40 ( V_61 , struct V_62 , V_52 ) ;
if ( V_56 < V_6 -> V_15 )
V_60 = & ( * V_60 ) -> V_64 ;
else if ( V_56 > V_6 -> V_16 )
V_60 = & ( * V_60 ) -> V_65 ;
else
return V_61 ;
}
V_63:
F_41 ( V_57 , V_61 , V_60 ) ;
F_42 ( V_57 , V_54 ) ;
return NULL ;
}
static struct V_52 * F_43 ( struct V_24 * V_17 , T_1 V_56 ,
struct V_52 * * V_66 ,
struct V_52 * * V_67 ,
struct V_52 * * * V_68 ,
struct V_52 * * V_69 )
{
struct V_53 * V_54 = & V_17 -> V_8 ;
struct V_52 * * V_70 = & V_54 -> V_52 ;
struct V_52 * V_71 = NULL ;
struct V_52 * V_72 = NULL ;
struct V_62 * V_6 ;
struct V_62 * V_73 = NULL ;
while ( * V_70 ) {
V_71 = * V_70 ;
V_6 = F_40 ( V_71 , struct V_62 , V_52 ) ;
V_73 = V_6 ;
if ( V_56 < V_6 -> V_15 )
V_70 = & ( * V_70 ) -> V_64 ;
else if ( V_56 > V_6 -> V_16 )
V_70 = & ( * V_70 ) -> V_65 ;
else
return * V_70 ;
}
if ( V_68 )
* V_68 = V_70 ;
if ( V_69 )
* V_69 = V_71 ;
if ( V_66 ) {
V_72 = V_71 ;
while ( V_71 && V_56 > V_73 -> V_16 ) {
V_71 = F_44 ( V_71 ) ;
V_73 = F_40 ( V_71 , struct V_62 , V_52 ) ;
}
* V_66 = V_71 ;
V_71 = V_72 ;
}
if ( V_67 ) {
V_73 = F_40 ( V_71 , struct V_62 , V_52 ) ;
while ( V_71 && V_56 < V_73 -> V_15 ) {
V_71 = F_45 ( V_71 ) ;
V_73 = F_40 ( V_71 , struct V_62 , V_52 ) ;
}
* V_67 = V_71 ;
}
return NULL ;
}
static inline struct V_52 *
F_46 ( struct V_24 * V_17 ,
T_1 V_56 ,
struct V_52 * * * V_68 ,
struct V_52 * * V_69 )
{
struct V_52 * V_71 = NULL ;
struct V_52 * V_74 ;
V_74 = F_43 ( V_17 , V_56 , & V_71 , NULL , V_68 , V_69 ) ;
if ( ! V_74 )
return V_71 ;
return V_74 ;
}
static inline struct V_52 * F_47 ( struct V_24 * V_17 ,
T_1 V_56 )
{
return F_46 ( V_17 , V_56 , NULL , NULL ) ;
}
static void F_48 ( struct V_24 * V_17 , struct V_7 * V_2 ,
struct V_7 * V_75 )
{
if ( V_17 -> V_45 && V_17 -> V_45 -> V_76 )
V_17 -> V_45 -> V_76 ( V_17 -> V_27 -> V_28 , V_2 ,
V_75 ) ;
}
static void F_49 ( struct V_24 * V_17 ,
struct V_7 * V_8 )
{
struct V_7 * V_75 ;
struct V_52 * V_77 ;
if ( V_8 -> V_8 & ( V_78 | V_79 ) )
return;
V_77 = F_45 ( & V_8 -> V_52 ) ;
if ( V_77 ) {
V_75 = F_40 ( V_77 , struct V_7 , V_52 ) ;
if ( V_75 -> V_16 == V_8 -> V_15 - 1 &&
V_75 -> V_8 == V_8 -> V_8 ) {
F_48 ( V_17 , V_8 , V_75 ) ;
V_8 -> V_15 = V_75 -> V_15 ;
V_75 -> V_17 = NULL ;
F_50 ( & V_75 -> V_52 , & V_17 -> V_8 ) ;
F_35 ( V_75 ) ;
}
}
V_77 = F_44 ( & V_8 -> V_52 ) ;
if ( V_77 ) {
V_75 = F_40 ( V_77 , struct V_7 , V_52 ) ;
if ( V_75 -> V_15 == V_8 -> V_16 + 1 &&
V_75 -> V_8 == V_8 -> V_8 ) {
F_48 ( V_17 , V_8 , V_75 ) ;
V_8 -> V_16 = V_75 -> V_16 ;
V_75 -> V_17 = NULL ;
F_50 ( & V_75 -> V_52 , & V_17 -> V_8 ) ;
F_35 ( V_75 ) ;
}
}
}
static void F_51 ( struct V_24 * V_17 ,
struct V_7 * V_8 , unsigned long * V_80 )
{
if ( V_17 -> V_45 && V_17 -> V_45 -> V_81 )
V_17 -> V_45 -> V_81 ( V_17 -> V_27 -> V_28 , V_8 , V_80 ) ;
}
static void F_52 ( struct V_24 * V_17 ,
struct V_7 * V_8 , unsigned long * V_80 )
{
if ( V_17 -> V_45 && V_17 -> V_45 -> V_82 )
V_17 -> V_45 -> V_82 ( V_17 -> V_27 -> V_28 , V_8 , V_80 ) ;
}
static int F_53 ( struct V_24 * V_17 ,
struct V_7 * V_8 , T_1 V_15 , T_1 V_16 ,
struct V_52 * * * V_60 ,
struct V_52 * * V_61 ,
unsigned long * V_80 )
{
struct V_52 * V_57 ;
if ( V_16 < V_15 )
F_54 ( 1 , V_14 L_8 ,
V_16 , V_15 ) ;
V_8 -> V_15 = V_15 ;
V_8 -> V_16 = V_16 ;
F_55 ( V_17 , V_8 , V_80 ) ;
V_57 = F_39 ( & V_17 -> V_8 , NULL , V_16 , & V_8 -> V_52 , V_60 , V_61 ) ;
if ( V_57 ) {
struct V_7 * V_83 ;
V_83 = F_40 ( V_57 , struct V_7 , V_52 ) ;
F_10 ( V_14 L_9
L_10 ,
V_83 -> V_15 , V_83 -> V_16 , V_15 , V_16 ) ;
return - V_84 ;
}
V_8 -> V_17 = V_17 ;
F_49 ( V_17 , V_8 ) ;
return 0 ;
}
static void F_56 ( struct V_24 * V_17 , struct V_7 * V_85 ,
T_1 V_86 )
{
if ( V_17 -> V_45 && V_17 -> V_45 -> V_87 )
V_17 -> V_45 -> V_87 ( V_17 -> V_27 -> V_28 , V_85 , V_86 ) ;
}
static int F_57 ( struct V_24 * V_17 , struct V_7 * V_85 ,
struct V_7 * V_88 , T_1 V_86 )
{
struct V_52 * V_57 ;
F_56 ( V_17 , V_85 , V_86 ) ;
V_88 -> V_15 = V_85 -> V_15 ;
V_88 -> V_16 = V_86 - 1 ;
V_88 -> V_8 = V_85 -> V_8 ;
V_85 -> V_15 = V_86 ;
V_57 = F_39 ( & V_17 -> V_8 , & V_85 -> V_52 , V_88 -> V_16 ,
& V_88 -> V_52 , NULL , NULL ) ;
if ( V_57 ) {
F_35 ( V_88 ) ;
return - V_84 ;
}
V_88 -> V_17 = V_17 ;
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
unsigned long * V_80 , int V_89 )
{
struct V_7 * V_12 ;
unsigned long V_90 = * V_80 & ~ V_91 ;
if ( ( V_90 & V_92 ) && ( V_8 -> V_8 & V_92 ) ) {
T_1 V_93 = V_8 -> V_16 - V_8 -> V_15 + 1 ;
F_37 ( V_93 > V_17 -> V_46 ) ;
V_17 -> V_46 -= V_93 ;
}
F_52 ( V_17 , V_8 , V_80 ) ;
V_8 -> V_8 &= ~ V_90 ;
if ( V_89 )
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
F_61 ( struct V_7 * V_88 )
{
if ( ! V_88 )
V_88 = F_30 ( V_94 ) ;
return V_88 ;
}
static void F_62 ( struct V_24 * V_17 , int V_95 )
{
F_63 ( F_17 ( V_17 ) , V_95 , L_11
L_12
L_13 ) ;
}
int F_64 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_80 , int V_89 , int V_96 ,
struct V_7 * * V_97 ,
T_3 V_48 )
{
struct V_7 * V_8 ;
struct V_7 * V_98 ;
struct V_7 * V_88 = NULL ;
struct V_52 * V_57 ;
T_1 V_99 ;
int V_95 ;
int V_100 = 0 ;
F_65 ( V_17 , V_15 , V_16 ) ;
if ( V_80 & V_101 )
V_80 |= V_102 ;
if ( V_96 )
V_80 |= ~ V_91 ;
V_80 |= V_103 ;
if ( V_80 & ( V_78 | V_79 ) )
V_100 = 1 ;
V_104:
if ( ! V_88 && ( V_48 & V_105 ) ) {
V_88 = F_30 ( V_48 ) ;
if ( ! V_88 )
return - V_35 ;
}
F_66 ( & V_17 -> V_47 ) ;
if ( V_97 ) {
V_98 = * V_97 ;
if ( V_100 ) {
* V_97 = NULL ;
V_97 = NULL ;
}
if ( V_98 && V_98 -> V_17 && V_98 -> V_15 <= V_15 &&
V_98 -> V_16 > V_15 ) {
if ( V_100 )
F_67 ( & V_98 -> V_18 ) ;
V_8 = V_98 ;
goto V_106;
}
if ( V_100 )
F_35 ( V_98 ) ;
}
V_57 = F_47 ( V_17 , V_15 ) ;
if ( ! V_57 )
goto V_107;
V_8 = F_40 ( V_57 , struct V_7 , V_52 ) ;
V_106:
if ( V_8 -> V_15 > V_16 )
goto V_107;
F_37 ( V_8 -> V_16 < V_15 ) ;
V_99 = V_8 -> V_16 ;
if ( ! ( V_8 -> V_8 & V_80 ) ) {
V_8 = F_58 ( V_8 ) ;
goto V_12;
}
if ( V_8 -> V_15 < V_15 ) {
V_88 = F_61 ( V_88 ) ;
F_68 ( ! V_88 ) ;
V_95 = F_57 ( V_17 , V_8 , V_88 , V_15 ) ;
if ( V_95 )
F_62 ( V_17 , V_95 ) ;
V_88 = NULL ;
if ( V_95 )
goto V_107;
if ( V_8 -> V_16 <= V_16 ) {
V_8 = F_59 ( V_17 , V_8 , & V_80 , V_89 ) ;
goto V_12;
}
goto V_108;
}
if ( V_8 -> V_15 <= V_16 && V_8 -> V_16 > V_16 ) {
V_88 = F_61 ( V_88 ) ;
F_68 ( ! V_88 ) ;
V_95 = F_57 ( V_17 , V_8 , V_88 , V_16 + 1 ) ;
if ( V_95 )
F_62 ( V_17 , V_95 ) ;
if ( V_89 )
F_60 ( & V_8 -> V_50 ) ;
F_59 ( V_17 , V_88 , & V_80 , V_89 ) ;
V_88 = NULL ;
goto V_107;
}
V_8 = F_59 ( V_17 , V_8 , & V_80 , V_89 ) ;
V_12:
if ( V_99 == ( T_1 ) - 1 )
goto V_107;
V_15 = V_99 + 1 ;
if ( V_15 <= V_16 && V_8 && ! F_69 () )
goto V_106;
goto V_108;
V_107:
F_70 ( & V_17 -> V_47 ) ;
if ( V_88 )
F_35 ( V_88 ) ;
return 0 ;
V_108:
if ( V_15 > V_16 )
goto V_107;
F_70 ( & V_17 -> V_47 ) ;
if ( V_48 & V_105 )
F_71 () ;
goto V_104;
}
static void F_72 ( struct V_24 * V_17 ,
struct V_7 * V_8 )
__releases( V_17 -> V_47 )
__acquires( V_17 -> V_47 )
{
F_73 ( V_109 ) ;
F_74 ( & V_8 -> V_50 , & V_109 , V_110 ) ;
F_70 ( & V_17 -> V_47 ) ;
F_75 () ;
F_66 ( & V_17 -> V_47 ) ;
F_76 ( & V_8 -> V_50 , & V_109 ) ;
}
static void F_77 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_80 )
{
struct V_7 * V_8 ;
struct V_52 * V_57 ;
F_65 ( V_17 , V_15 , V_16 ) ;
F_66 ( & V_17 -> V_47 ) ;
V_104:
while ( 1 ) {
V_57 = F_47 ( V_17 , V_15 ) ;
V_111:
if ( ! V_57 )
break;
V_8 = F_40 ( V_57 , struct V_7 , V_52 ) ;
if ( V_8 -> V_15 > V_16 )
goto V_107;
if ( V_8 -> V_8 & V_80 ) {
V_15 = V_8 -> V_15 ;
F_78 ( & V_8 -> V_18 ) ;
F_72 ( V_17 , V_8 ) ;
F_35 ( V_8 ) ;
goto V_104;
}
V_15 = V_8 -> V_16 + 1 ;
if ( V_15 > V_16 )
break;
if ( ! F_79 ( & V_17 -> V_47 ) ) {
V_57 = F_44 ( V_57 ) ;
goto V_111;
}
}
V_107:
F_70 ( & V_17 -> V_47 ) ;
}
static void F_55 ( struct V_24 * V_17 ,
struct V_7 * V_8 ,
unsigned long * V_80 )
{
unsigned long V_112 = * V_80 & ~ V_91 ;
F_51 ( V_17 , V_8 , V_80 ) ;
if ( ( V_112 & V_92 ) && ! ( V_8 -> V_8 & V_92 ) ) {
T_1 V_93 = V_8 -> V_16 - V_8 -> V_15 + 1 ;
V_17 -> V_46 += V_93 ;
}
V_8 -> V_8 |= V_112 ;
}
static void F_80 ( struct V_7 * V_8 ,
struct V_7 * * V_113 )
{
if ( V_113 && ! ( * V_113 ) ) {
if ( V_8 -> V_8 & ( V_78 | V_79 ) ) {
* V_113 = V_8 ;
F_78 ( & V_8 -> V_18 ) ;
}
}
}
static int T_4
F_81 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_80 , unsigned long V_114 ,
T_1 * V_115 , struct V_7 * * V_97 ,
T_3 V_48 )
{
struct V_7 * V_8 ;
struct V_7 * V_88 = NULL ;
struct V_52 * V_57 ;
struct V_52 * * V_60 ;
struct V_52 * V_61 ;
int V_95 = 0 ;
T_1 V_116 ;
T_1 V_99 ;
F_65 ( V_17 , V_15 , V_16 ) ;
V_80 |= V_103 ;
V_104:
if ( ! V_88 && ( V_48 & V_105 ) ) {
V_88 = F_30 ( V_48 ) ;
F_68 ( ! V_88 ) ;
}
F_66 ( & V_17 -> V_47 ) ;
if ( V_97 && * V_97 ) {
V_8 = * V_97 ;
if ( V_8 -> V_15 <= V_15 && V_8 -> V_16 > V_15 &&
V_8 -> V_17 ) {
V_57 = & V_8 -> V_52 ;
goto V_106;
}
}
V_57 = F_46 ( V_17 , V_15 , & V_60 , & V_61 ) ;
if ( ! V_57 ) {
V_88 = F_61 ( V_88 ) ;
F_68 ( ! V_88 ) ;
V_95 = F_53 ( V_17 , V_88 , V_15 , V_16 ,
& V_60 , & V_61 , & V_80 ) ;
if ( V_95 )
F_62 ( V_17 , V_95 ) ;
F_80 ( V_88 , V_97 ) ;
V_88 = NULL ;
goto V_107;
}
V_8 = F_40 ( V_57 , struct V_7 , V_52 ) ;
V_106:
V_116 = V_8 -> V_15 ;
V_99 = V_8 -> V_16 ;
if ( V_8 -> V_15 == V_15 && V_8 -> V_16 <= V_16 ) {
if ( V_8 -> V_8 & V_114 ) {
* V_115 = V_8 -> V_15 ;
V_95 = - V_84 ;
goto V_107;
}
F_55 ( V_17 , V_8 , & V_80 ) ;
F_80 ( V_8 , V_97 ) ;
F_49 ( V_17 , V_8 ) ;
if ( V_99 == ( T_1 ) - 1 )
goto V_107;
V_15 = V_99 + 1 ;
V_8 = F_58 ( V_8 ) ;
if ( V_15 < V_16 && V_8 && V_8 -> V_15 == V_15 &&
! F_69 () )
goto V_106;
goto V_108;
}
if ( V_8 -> V_15 < V_15 ) {
if ( V_8 -> V_8 & V_114 ) {
* V_115 = V_15 ;
V_95 = - V_84 ;
goto V_107;
}
V_88 = F_61 ( V_88 ) ;
F_68 ( ! V_88 ) ;
V_95 = F_57 ( V_17 , V_8 , V_88 , V_15 ) ;
if ( V_95 )
F_62 ( V_17 , V_95 ) ;
V_88 = NULL ;
if ( V_95 )
goto V_107;
if ( V_8 -> V_16 <= V_16 ) {
F_55 ( V_17 , V_8 , & V_80 ) ;
F_80 ( V_8 , V_97 ) ;
F_49 ( V_17 , V_8 ) ;
if ( V_99 == ( T_1 ) - 1 )
goto V_107;
V_15 = V_99 + 1 ;
V_8 = F_58 ( V_8 ) ;
if ( V_15 < V_16 && V_8 && V_8 -> V_15 == V_15 &&
! F_69 () )
goto V_106;
}
goto V_108;
}
if ( V_8 -> V_15 > V_15 ) {
T_1 V_117 ;
if ( V_16 < V_116 )
V_117 = V_16 ;
else
V_117 = V_116 - 1 ;
V_88 = F_61 ( V_88 ) ;
F_68 ( ! V_88 ) ;
V_95 = F_53 ( V_17 , V_88 , V_15 , V_117 ,
NULL , NULL , & V_80 ) ;
if ( V_95 )
F_62 ( V_17 , V_95 ) ;
F_80 ( V_88 , V_97 ) ;
V_88 = NULL ;
V_15 = V_117 + 1 ;
goto V_108;
}
if ( V_8 -> V_15 <= V_16 && V_8 -> V_16 > V_16 ) {
if ( V_8 -> V_8 & V_114 ) {
* V_115 = V_15 ;
V_95 = - V_84 ;
goto V_107;
}
V_88 = F_61 ( V_88 ) ;
F_68 ( ! V_88 ) ;
V_95 = F_57 ( V_17 , V_8 , V_88 , V_16 + 1 ) ;
if ( V_95 )
F_62 ( V_17 , V_95 ) ;
F_55 ( V_17 , V_88 , & V_80 ) ;
F_80 ( V_88 , V_97 ) ;
F_49 ( V_17 , V_88 ) ;
V_88 = NULL ;
goto V_107;
}
goto V_108;
V_107:
F_70 ( & V_17 -> V_47 ) ;
if ( V_88 )
F_35 ( V_88 ) ;
return V_95 ;
V_108:
if ( V_15 > V_16 )
goto V_107;
F_70 ( & V_17 -> V_47 ) ;
if ( V_48 & V_105 )
F_71 () ;
goto V_104;
}
int F_82 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_80 , T_1 * V_115 ,
struct V_7 * * V_97 , T_3 V_48 )
{
return F_81 ( V_17 , V_15 , V_16 , V_80 , 0 , V_115 ,
V_97 , V_48 ) ;
}
int F_83 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_80 , unsigned long V_118 ,
struct V_7 * * V_97 , T_3 V_48 )
{
struct V_7 * V_8 ;
struct V_7 * V_88 = NULL ;
struct V_52 * V_57 ;
struct V_52 * * V_60 ;
struct V_52 * V_61 ;
int V_95 = 0 ;
T_1 V_116 ;
T_1 V_99 ;
F_65 ( V_17 , V_15 , V_16 ) ;
V_104:
if ( ! V_88 && ( V_48 & V_105 ) ) {
V_88 = F_30 ( V_48 ) ;
if ( ! V_88 )
return - V_35 ;
}
F_66 ( & V_17 -> V_47 ) ;
if ( V_97 && * V_97 ) {
V_8 = * V_97 ;
if ( V_8 -> V_15 <= V_15 && V_8 -> V_16 > V_15 &&
V_8 -> V_17 ) {
V_57 = & V_8 -> V_52 ;
goto V_106;
}
}
V_57 = F_46 ( V_17 , V_15 , & V_60 , & V_61 ) ;
if ( ! V_57 ) {
V_88 = F_61 ( V_88 ) ;
if ( ! V_88 ) {
V_95 = - V_35 ;
goto V_107;
}
V_95 = F_53 ( V_17 , V_88 , V_15 , V_16 ,
& V_60 , & V_61 , & V_80 ) ;
if ( V_95 )
F_62 ( V_17 , V_95 ) ;
F_80 ( V_88 , V_97 ) ;
V_88 = NULL ;
goto V_107;
}
V_8 = F_40 ( V_57 , struct V_7 , V_52 ) ;
V_106:
V_116 = V_8 -> V_15 ;
V_99 = V_8 -> V_16 ;
if ( V_8 -> V_15 == V_15 && V_8 -> V_16 <= V_16 ) {
F_55 ( V_17 , V_8 , & V_80 ) ;
F_80 ( V_8 , V_97 ) ;
V_8 = F_59 ( V_17 , V_8 , & V_118 , 0 ) ;
if ( V_99 == ( T_1 ) - 1 )
goto V_107;
V_15 = V_99 + 1 ;
if ( V_15 < V_16 && V_8 && V_8 -> V_15 == V_15 &&
! F_69 () )
goto V_106;
goto V_108;
}
if ( V_8 -> V_15 < V_15 ) {
V_88 = F_61 ( V_88 ) ;
if ( ! V_88 ) {
V_95 = - V_35 ;
goto V_107;
}
V_95 = F_57 ( V_17 , V_8 , V_88 , V_15 ) ;
if ( V_95 )
F_62 ( V_17 , V_95 ) ;
V_88 = NULL ;
if ( V_95 )
goto V_107;
if ( V_8 -> V_16 <= V_16 ) {
F_55 ( V_17 , V_8 , & V_80 ) ;
F_80 ( V_8 , V_97 ) ;
V_8 = F_59 ( V_17 , V_8 , & V_118 , 0 ) ;
if ( V_99 == ( T_1 ) - 1 )
goto V_107;
V_15 = V_99 + 1 ;
if ( V_15 < V_16 && V_8 && V_8 -> V_15 == V_15 &&
! F_69 () )
goto V_106;
}
goto V_108;
}
if ( V_8 -> V_15 > V_15 ) {
T_1 V_117 ;
if ( V_16 < V_116 )
V_117 = V_16 ;
else
V_117 = V_116 - 1 ;
V_88 = F_61 ( V_88 ) ;
if ( ! V_88 ) {
V_95 = - V_35 ;
goto V_107;
}
V_95 = F_53 ( V_17 , V_88 , V_15 , V_117 ,
NULL , NULL , & V_80 ) ;
if ( V_95 )
F_62 ( V_17 , V_95 ) ;
F_80 ( V_88 , V_97 ) ;
V_88 = NULL ;
V_15 = V_117 + 1 ;
goto V_108;
}
if ( V_8 -> V_15 <= V_16 && V_8 -> V_16 > V_16 ) {
V_88 = F_61 ( V_88 ) ;
if ( ! V_88 ) {
V_95 = - V_35 ;
goto V_107;
}
V_95 = F_57 ( V_17 , V_8 , V_88 , V_16 + 1 ) ;
if ( V_95 )
F_62 ( V_17 , V_95 ) ;
F_55 ( V_17 , V_88 , & V_80 ) ;
F_80 ( V_88 , V_97 ) ;
F_59 ( V_17 , V_88 , & V_118 , 0 ) ;
V_88 = NULL ;
goto V_107;
}
goto V_108;
V_107:
F_70 ( & V_17 -> V_47 ) ;
if ( V_88 )
F_35 ( V_88 ) ;
return V_95 ;
V_108:
if ( V_15 > V_16 )
goto V_107;
F_70 ( & V_17 -> V_47 ) ;
if ( V_48 & V_105 )
F_71 () ;
goto V_104;
}
int F_84 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
T_3 V_48 )
{
return F_82 ( V_17 , V_15 , V_16 , V_92 , NULL ,
NULL , V_48 ) ;
}
int F_85 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_80 , T_3 V_48 )
{
return F_82 ( V_17 , V_15 , V_16 , V_80 , NULL ,
NULL , V_48 ) ;
}
int F_86 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_80 , T_3 V_48 )
{
return F_64 ( V_17 , V_15 , V_16 , V_80 , 0 , 0 , NULL , V_48 ) ;
}
int F_87 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
struct V_7 * * V_97 , T_3 V_48 )
{
return F_82 ( V_17 , V_15 , V_16 ,
V_101 | V_119 ,
NULL , V_97 , V_48 ) ;
}
int F_88 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
struct V_7 * * V_97 , T_3 V_48 )
{
return F_82 ( V_17 , V_15 , V_16 ,
V_101 | V_119 | V_120 ,
NULL , V_97 , V_48 ) ;
}
int F_89 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
T_3 V_48 )
{
return F_64 ( V_17 , V_15 , V_16 ,
V_92 | V_101 |
V_121 , 0 , 0 , NULL , V_48 ) ;
}
int F_90 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
T_3 V_48 )
{
return F_82 ( V_17 , V_15 , V_16 , V_122 , NULL ,
NULL , V_48 ) ;
}
int F_91 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
struct V_7 * * V_97 , T_3 V_48 )
{
return F_82 ( V_17 , V_15 , V_16 , V_119 , NULL ,
V_97 , V_48 ) ;
}
int F_92 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
struct V_7 * * V_97 , T_3 V_48 )
{
return F_64 ( V_17 , V_15 , V_16 , V_119 , 0 , 0 ,
V_97 , V_48 ) ;
}
int F_93 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_80 , struct V_7 * * V_97 )
{
int V_95 ;
T_1 V_115 ;
while ( 1 ) {
V_95 = F_81 ( V_17 , V_15 , V_16 , V_123 | V_80 ,
V_123 , & V_115 ,
V_97 , V_124 ) ;
if ( V_95 == - V_84 ) {
F_77 ( V_17 , V_115 , V_16 , V_123 ) ;
V_15 = V_115 ;
} else
break;
F_37 ( V_15 > V_16 ) ;
}
return V_95 ;
}
int F_94 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 )
{
return F_93 ( V_17 , V_15 , V_16 , 0 , NULL ) ;
}
int F_95 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 )
{
int V_95 ;
T_1 V_115 ;
V_95 = F_81 ( V_17 , V_15 , V_16 , V_123 , V_123 ,
& V_115 , NULL , V_124 ) ;
if ( V_95 == - V_84 ) {
if ( V_115 > V_15 )
F_64 ( V_17 , V_15 , V_115 - 1 ,
V_123 , 1 , 0 , NULL , V_124 ) ;
return 0 ;
}
return 1 ;
}
int F_96 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
struct V_7 * * V_98 , T_3 V_48 )
{
return F_64 ( V_17 , V_15 , V_16 , V_123 , 1 , 0 , V_98 ,
V_48 ) ;
}
int F_97 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 )
{
return F_64 ( V_17 , V_15 , V_16 , V_123 , 1 , 0 , NULL ,
V_124 ) ;
}
int F_98 ( struct V_25 * V_25 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_125 = V_15 >> V_126 ;
unsigned long V_127 = V_16 >> V_126 ;
struct V_128 * V_128 ;
while ( V_125 <= V_127 ) {
V_128 = F_99 ( V_25 -> V_129 , V_125 ) ;
F_68 ( ! V_128 ) ;
F_100 ( V_128 ) ;
F_101 ( V_128 ) ;
V_125 ++ ;
}
return 0 ;
}
int F_102 ( struct V_25 * V_25 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_125 = V_15 >> V_126 ;
unsigned long V_127 = V_16 >> V_126 ;
struct V_128 * V_128 ;
while ( V_125 <= V_127 ) {
V_128 = F_99 ( V_25 -> V_129 , V_125 ) ;
F_68 ( ! V_128 ) ;
F_103 ( V_128 ) ;
F_104 ( V_128 ) ;
F_101 ( V_128 ) ;
V_125 ++ ;
}
return 0 ;
}
static int F_105 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_125 = V_15 >> V_126 ;
unsigned long V_127 = V_16 >> V_126 ;
struct V_128 * V_128 ;
while ( V_125 <= V_127 ) {
V_128 = F_99 ( V_17 -> V_27 , V_125 ) ;
F_68 ( ! V_128 ) ;
F_106 ( V_128 ) ;
F_101 ( V_128 ) ;
V_125 ++ ;
}
return 0 ;
}
static struct V_7 *
F_107 ( struct V_24 * V_17 ,
T_1 V_15 , unsigned long V_80 )
{
struct V_52 * V_57 ;
struct V_7 * V_8 ;
V_57 = F_47 ( V_17 , V_15 ) ;
if ( ! V_57 )
goto V_107;
while ( 1 ) {
V_8 = F_40 ( V_57 , struct V_7 , V_52 ) ;
if ( V_8 -> V_16 >= V_15 && ( V_8 -> V_8 & V_80 ) )
return V_8 ;
V_57 = F_44 ( V_57 ) ;
if ( ! V_57 )
break;
}
V_107:
return NULL ;
}
int F_108 ( struct V_24 * V_17 , T_1 V_15 ,
T_1 * V_130 , T_1 * V_131 , unsigned long V_80 ,
struct V_7 * * V_97 )
{
struct V_7 * V_8 ;
struct V_52 * V_70 ;
int V_74 = 1 ;
F_66 ( & V_17 -> V_47 ) ;
if ( V_97 && * V_97 ) {
V_8 = * V_97 ;
if ( V_8 -> V_16 == V_15 - 1 && V_8 -> V_17 ) {
V_70 = F_44 ( & V_8 -> V_52 ) ;
while ( V_70 ) {
V_8 = F_40 ( V_70 , struct V_7 ,
V_52 ) ;
if ( V_8 -> V_8 & V_80 )
goto V_132;
V_70 = F_44 ( V_70 ) ;
}
F_35 ( * V_97 ) ;
* V_97 = NULL ;
goto V_107;
}
F_35 ( * V_97 ) ;
* V_97 = NULL ;
}
V_8 = F_107 ( V_17 , V_15 , V_80 ) ;
V_132:
if ( V_8 ) {
F_80 ( V_8 , V_97 ) ;
* V_130 = V_8 -> V_15 ;
* V_131 = V_8 -> V_16 ;
V_74 = 0 ;
}
V_107:
F_70 ( & V_17 -> V_47 ) ;
return V_74 ;
}
static T_5 T_1 F_109 ( struct V_24 * V_17 ,
T_1 * V_15 , T_1 * V_16 , T_1 V_133 ,
struct V_7 * * V_97 )
{
struct V_52 * V_57 ;
struct V_7 * V_8 ;
T_1 V_134 = * V_15 ;
T_1 V_83 = 0 ;
T_1 V_135 = 0 ;
F_66 ( & V_17 -> V_47 ) ;
V_57 = F_47 ( V_17 , V_134 ) ;
if ( ! V_57 ) {
if ( ! V_83 )
* V_16 = ( T_1 ) - 1 ;
goto V_107;
}
while ( 1 ) {
V_8 = F_40 ( V_57 , struct V_7 , V_52 ) ;
if ( V_83 && ( V_8 -> V_15 != V_134 ||
( V_8 -> V_8 & V_79 ) ) ) {
goto V_107;
}
if ( ! ( V_8 -> V_8 & V_101 ) ) {
if ( ! V_83 )
* V_16 = V_8 -> V_16 ;
goto V_107;
}
if ( ! V_83 ) {
* V_15 = V_8 -> V_15 ;
* V_97 = V_8 ;
F_78 ( & V_8 -> V_18 ) ;
}
V_83 ++ ;
* V_16 = V_8 -> V_16 ;
V_134 = V_8 -> V_16 + 1 ;
V_57 = F_44 ( V_57 ) ;
V_135 += V_8 -> V_16 - V_8 -> V_15 + 1 ;
if ( V_135 >= V_133 )
break;
if ( ! V_57 )
break;
}
V_107:
F_70 ( & V_17 -> V_47 ) ;
return V_83 ;
}
static T_5 void F_110 ( struct V_25 * V_25 ,
struct V_128 * V_136 ,
T_1 V_15 , T_1 V_16 )
{
int V_74 ;
struct V_128 * V_137 [ 16 ] ;
unsigned long V_125 = V_15 >> V_126 ;
unsigned long V_127 = V_16 >> V_126 ;
unsigned long V_138 = V_127 - V_125 + 1 ;
int V_139 ;
if ( V_125 == V_136 -> V_125 && V_127 == V_125 )
return;
while ( V_138 > 0 ) {
V_74 = F_111 ( V_25 -> V_129 , V_125 ,
F_112 (unsigned long, nr_pages,
ARRAY_SIZE(pages)) , V_137 ) ;
for ( V_139 = 0 ; V_139 < V_74 ; V_139 ++ ) {
if ( V_137 [ V_139 ] != V_136 )
F_113 ( V_137 [ V_139 ] ) ;
F_101 ( V_137 [ V_139 ] ) ;
}
V_138 -= V_74 ;
V_125 += V_74 ;
F_71 () ;
}
}
static T_5 int F_114 ( struct V_25 * V_25 ,
struct V_128 * V_136 ,
T_1 V_140 ,
T_1 V_141 )
{
unsigned long V_125 = V_140 >> V_126 ;
unsigned long V_142 = V_125 ;
unsigned long V_127 = V_141 >> V_126 ;
unsigned long V_143 = 0 ;
struct V_128 * V_137 [ 16 ] ;
unsigned long V_144 ;
int V_74 ;
int V_139 ;
if ( V_125 == V_136 -> V_125 && V_125 == V_127 )
return 0 ;
V_144 = V_127 - V_125 + 1 ;
while ( V_144 > 0 ) {
V_74 = F_111 ( V_25 -> V_129 , V_125 ,
F_112 (unsigned long,
nrpages, ARRAY_SIZE(pages)) , V_137 ) ;
if ( V_74 == 0 ) {
V_74 = - V_145 ;
goto V_146;
}
for ( V_139 = 0 ; V_139 < V_74 ; V_139 ++ ) {
if ( V_137 [ V_139 ] != V_136 ) {
F_115 ( V_137 [ V_139 ] ) ;
if ( ! F_116 ( V_137 [ V_139 ] ) ||
V_137 [ V_139 ] -> V_27 != V_25 -> V_129 ) {
V_74 = - V_145 ;
F_113 ( V_137 [ V_139 ] ) ;
F_101 ( V_137 [ V_139 ] ) ;
goto V_146;
}
}
F_101 ( V_137 [ V_139 ] ) ;
V_143 ++ ;
}
V_144 -= V_74 ;
V_125 += V_74 ;
F_71 () ;
}
V_74 = 0 ;
V_146:
if ( V_74 && V_143 ) {
F_110 ( V_25 , V_136 ,
V_140 ,
( ( T_1 ) ( V_142 + V_143 - 1 ) ) <<
V_126 ) ;
}
return V_74 ;
}
STATIC T_1 F_117 ( struct V_25 * V_25 ,
struct V_24 * V_17 ,
struct V_128 * V_136 , T_1 * V_15 ,
T_1 * V_16 , T_1 V_133 )
{
T_1 V_140 ;
T_1 V_141 ;
T_1 V_83 ;
struct V_7 * V_97 = NULL ;
int V_74 ;
int V_147 = 0 ;
V_104:
V_140 = * V_15 ;
V_141 = 0 ;
V_83 = F_109 ( V_17 , & V_140 , & V_141 ,
V_133 , & V_97 ) ;
if ( ! V_83 || V_141 <= * V_15 ) {
* V_15 = V_140 ;
* V_16 = V_141 ;
F_35 ( V_97 ) ;
return 0 ;
}
if ( V_140 < * V_15 )
V_140 = * V_15 ;
if ( V_141 + 1 - V_140 > V_133 )
V_141 = V_140 + V_133 - 1 ;
V_74 = F_114 ( V_25 , V_136 ,
V_140 , V_141 ) ;
if ( V_74 == - V_145 ) {
F_35 ( V_97 ) ;
V_97 = NULL ;
if ( ! V_147 ) {
V_133 = V_148 ;
V_147 = 1 ;
goto V_104;
} else {
V_83 = 0 ;
goto V_149;
}
}
F_68 ( V_74 ) ;
F_93 ( V_17 , V_140 , V_141 , 0 , & V_97 ) ;
V_74 = F_118 ( V_17 , V_140 , V_141 ,
V_101 , 1 , V_97 ) ;
if ( ! V_74 ) {
F_96 ( V_17 , V_140 , V_141 ,
& V_97 , V_124 ) ;
F_110 ( V_25 , V_136 ,
V_140 , V_141 ) ;
F_71 () ;
goto V_104;
}
F_35 ( V_97 ) ;
* V_15 = V_140 ;
* V_16 = V_141 ;
V_149:
return V_83 ;
}
int F_119 ( struct V_25 * V_25 , T_1 V_15 , T_1 V_16 ,
struct V_128 * V_136 ,
unsigned long V_118 ,
unsigned long V_150 )
{
struct V_24 * V_17 = & F_120 ( V_25 ) -> V_151 ;
int V_74 ;
struct V_128 * V_137 [ 16 ] ;
unsigned long V_125 = V_15 >> V_126 ;
unsigned long V_127 = V_16 >> V_126 ;
unsigned long V_138 = V_127 - V_125 + 1 ;
int V_139 ;
F_64 ( V_17 , V_15 , V_16 , V_118 , 1 , 0 , NULL , V_124 ) ;
if ( V_150 == 0 )
return 0 ;
while ( V_138 > 0 ) {
V_74 = F_111 ( V_25 -> V_129 , V_125 ,
F_112 (unsigned long,
nr_pages, ARRAY_SIZE(pages)) , V_137 ) ;
for ( V_139 = 0 ; V_139 < V_74 ; V_139 ++ ) {
if ( V_150 & V_152 )
F_121 ( V_137 [ V_139 ] ) ;
if ( V_137 [ V_139 ] == V_136 ) {
F_101 ( V_137 [ V_139 ] ) ;
continue;
}
if ( V_150 & V_153 )
F_100 ( V_137 [ V_139 ] ) ;
if ( V_150 & V_154 )
F_106 ( V_137 [ V_139 ] ) ;
if ( V_150 & V_155 )
F_122 ( V_137 [ V_139 ] ) ;
if ( V_150 & V_156 )
F_113 ( V_137 [ V_139 ] ) ;
F_101 ( V_137 [ V_139 ] ) ;
}
V_138 -= V_74 ;
V_125 += V_74 ;
F_71 () ;
}
return 0 ;
}
T_1 F_123 ( struct V_24 * V_17 ,
T_1 * V_15 , T_1 V_157 , T_1 V_133 ,
unsigned long V_80 , int V_158 )
{
struct V_52 * V_57 ;
struct V_7 * V_8 ;
T_1 V_134 = * V_15 ;
T_1 V_135 = 0 ;
T_1 V_159 = 0 ;
int V_83 = 0 ;
if ( F_37 ( V_157 <= V_134 ) )
return 0 ;
F_66 ( & V_17 -> V_47 ) ;
if ( V_134 == 0 && V_80 == V_92 ) {
V_135 = V_17 -> V_46 ;
goto V_107;
}
V_57 = F_47 ( V_17 , V_134 ) ;
if ( ! V_57 )
goto V_107;
while ( 1 ) {
V_8 = F_40 ( V_57 , struct V_7 , V_52 ) ;
if ( V_8 -> V_15 > V_157 )
break;
if ( V_158 && V_83 && V_8 -> V_15 > V_159 + 1 )
break;
if ( V_8 -> V_16 >= V_134 && ( V_8 -> V_8 & V_80 ) == V_80 ) {
V_135 += F_124 ( V_157 , V_8 -> V_16 ) + 1 -
F_125 ( V_134 , V_8 -> V_15 ) ;
if ( V_135 >= V_133 )
break;
if ( ! V_83 ) {
* V_15 = F_125 ( V_134 , V_8 -> V_15 ) ;
V_83 = 1 ;
}
V_159 = V_8 -> V_16 ;
} else if ( V_158 && V_83 ) {
break;
}
V_57 = F_44 ( V_57 ) ;
if ( ! V_57 )
break;
}
V_107:
F_70 ( & V_17 -> V_47 ) ;
return V_135 ;
}
static int F_126 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_49 )
{
struct V_52 * V_57 ;
struct V_7 * V_8 ;
int V_74 = 0 ;
F_66 ( & V_17 -> V_47 ) ;
V_57 = F_47 ( V_17 , V_15 ) ;
if ( ! V_57 ) {
V_74 = - V_160 ;
goto V_107;
}
V_8 = F_40 ( V_57 , struct V_7 , V_52 ) ;
if ( V_8 -> V_15 != V_15 ) {
V_74 = - V_160 ;
goto V_107;
}
V_8 -> V_49 = V_49 ;
V_107:
F_70 ( & V_17 -> V_47 ) ;
return V_74 ;
}
int F_127 ( struct V_24 * V_17 , T_1 V_15 , T_1 * V_49 )
{
struct V_52 * V_57 ;
struct V_7 * V_8 ;
int V_74 = 0 ;
F_66 ( & V_17 -> V_47 ) ;
V_57 = F_47 ( V_17 , V_15 ) ;
if ( ! V_57 ) {
V_74 = - V_160 ;
goto V_107;
}
V_8 = F_40 ( V_57 , struct V_7 , V_52 ) ;
if ( V_8 -> V_15 != V_15 ) {
V_74 = - V_160 ;
goto V_107;
}
* V_49 = V_8 -> V_49 ;
V_107:
F_70 ( & V_17 -> V_47 ) ;
return V_74 ;
}
int F_118 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_80 , int V_161 , struct V_7 * V_98 )
{
struct V_7 * V_8 = NULL ;
struct V_52 * V_57 ;
int V_162 = 0 ;
F_66 ( & V_17 -> V_47 ) ;
if ( V_98 && V_98 -> V_17 && V_98 -> V_15 <= V_15 &&
V_98 -> V_16 > V_15 )
V_57 = & V_98 -> V_52 ;
else
V_57 = F_47 ( V_17 , V_15 ) ;
while ( V_57 && V_15 <= V_16 ) {
V_8 = F_40 ( V_57 , struct V_7 , V_52 ) ;
if ( V_161 && V_8 -> V_15 > V_15 ) {
V_162 = 0 ;
break;
}
if ( V_8 -> V_15 > V_16 )
break;
if ( V_8 -> V_8 & V_80 ) {
V_162 = 1 ;
if ( ! V_161 )
break;
} else if ( V_161 ) {
V_162 = 0 ;
break;
}
if ( V_8 -> V_16 == ( T_1 ) - 1 )
break;
V_15 = V_8 -> V_16 + 1 ;
if ( V_15 > V_16 )
break;
V_57 = F_44 ( V_57 ) ;
if ( ! V_57 ) {
if ( V_161 )
V_162 = 0 ;
break;
}
}
F_70 ( & V_17 -> V_47 ) ;
return V_162 ;
}
static void F_128 ( struct V_24 * V_17 , struct V_128 * V_128 )
{
T_1 V_15 = F_129 ( V_128 ) ;
T_1 V_16 = V_15 + V_148 - 1 ;
if ( F_118 ( V_17 , V_15 , V_16 , V_119 , 1 , NULL ) )
F_130 ( V_128 ) ;
}
static int F_131 ( struct V_25 * V_25 , struct V_163 * V_164 ,
int V_165 )
{
int V_74 ;
int V_95 = 0 ;
struct V_24 * V_166 = & F_120 ( V_25 ) -> V_167 ;
F_126 ( V_166 , V_164 -> V_15 , 0 ) ;
V_74 = F_86 ( V_166 , V_164 -> V_15 ,
V_164 -> V_15 + V_164 -> V_21 - 1 ,
V_123 | V_92 , V_124 ) ;
if ( V_74 )
V_95 = V_74 ;
V_74 = F_86 ( & F_120 ( V_25 ) -> V_151 , V_164 -> V_15 ,
V_164 -> V_15 + V_164 -> V_21 - 1 ,
V_168 , V_124 ) ;
if ( V_74 && ! V_95 )
V_95 = V_74 ;
F_132 ( V_164 ) ;
return V_95 ;
}
int F_133 ( struct V_31 * V_169 , T_1 V_15 ,
T_1 V_170 , T_1 V_171 , struct V_128 * V_128 ,
int V_172 )
{
struct V_40 * V_40 ;
struct V_173 * V_174 ;
T_1 V_175 = 0 ;
T_1 V_176 ;
struct V_177 * V_178 = NULL ;
struct V_179 * V_180 = & V_169 -> V_181 ;
int V_74 ;
ASSERT ( ! ( V_169 -> V_182 -> V_183 & V_184 ) ) ;
F_68 ( ! V_172 ) ;
if ( F_134 ( V_180 , V_171 , V_170 , V_172 ) )
return 0 ;
V_40 = F_135 ( V_124 , 1 ) ;
if ( ! V_40 )
return - V_185 ;
V_40 -> V_186 . V_187 = 0 ;
V_175 = V_170 ;
V_74 = F_136 ( V_169 , V_188 , V_171 ,
& V_175 , & V_178 , V_172 ) ;
if ( V_74 ) {
F_137 ( V_40 ) ;
return - V_185 ;
}
F_68 ( V_172 != V_178 -> V_172 ) ;
V_176 = V_178 -> V_189 [ V_172 - 1 ] . V_190 >> 9 ;
V_40 -> V_186 . V_191 = V_176 ;
V_174 = V_178 -> V_189 [ V_172 - 1 ] . V_174 ;
F_132 ( V_178 ) ;
if ( ! V_174 || ! V_174 -> V_192 || ! V_174 -> V_193 ) {
F_137 ( V_40 ) ;
return - V_185 ;
}
V_40 -> V_194 = V_174 -> V_192 ;
F_138 ( V_40 , V_128 , V_170 , V_15 - F_129 ( V_128 ) ) ;
if ( F_139 ( V_195 , V_40 ) ) {
F_137 ( V_40 ) ;
F_140 ( V_174 , V_196 ) ;
return - V_185 ;
}
F_141 ( V_197
L_14
L_15 , V_128 -> V_27 -> V_28 -> V_198 ,
V_15 , F_142 ( V_174 -> V_199 ) , V_176 ) ;
F_137 ( V_40 ) ;
return 0 ;
}
int F_143 ( struct V_200 * V_54 , struct V_9 * V_10 ,
int V_172 )
{
T_1 V_15 = V_10 -> V_15 ;
unsigned long V_139 , V_201 = F_144 ( V_10 -> V_15 , V_10 -> V_21 ) ;
int V_74 = 0 ;
if ( V_54 -> V_169 -> V_182 -> V_183 & V_184 )
return - V_202 ;
for ( V_139 = 0 ; V_139 < V_201 ; V_139 ++ ) {
struct V_128 * V_60 = F_145 ( V_10 , V_139 ) ;
V_74 = F_133 ( V_54 -> V_169 , V_15 , V_148 ,
V_15 , V_60 , V_172 ) ;
if ( V_74 )
break;
V_15 += V_148 ;
}
return V_74 ;
}
static int F_146 ( T_1 V_15 , struct V_128 * V_128 )
{
T_1 V_49 ;
T_1 V_203 ;
struct V_163 * V_204 ;
struct V_25 * V_25 = V_128 -> V_27 -> V_28 ;
struct V_31 * V_169 = F_120 ( V_25 ) -> V_54 -> V_169 ;
struct V_7 * V_8 ;
int V_205 ;
int V_165 = 0 ;
int V_74 ;
V_49 = 0 ;
V_74 = F_123 ( & F_120 ( V_25 ) -> V_167 , & V_49 ,
( T_1 ) - 1 , 1 , V_92 , 0 ) ;
if ( ! V_74 )
return 0 ;
V_74 = F_127 ( & F_120 ( V_25 ) -> V_167 , V_15 ,
& V_203 ) ;
if ( V_74 )
return 0 ;
V_204 = (struct V_163 * ) ( unsigned long ) V_203 ;
F_68 ( ! V_204 -> V_206 ) ;
if ( V_204 -> V_207 ) {
F_147 ( L_16 ,
V_204 -> V_15 ) ;
V_165 = 1 ;
goto V_107;
}
if ( V_169 -> V_182 -> V_183 & V_184 )
goto V_107;
F_66 ( & F_120 ( V_25 ) -> V_151 . V_47 ) ;
V_8 = F_107 ( & F_120 ( V_25 ) -> V_151 ,
V_204 -> V_15 ,
V_123 ) ;
F_70 ( & F_120 ( V_25 ) -> V_151 . V_47 ) ;
if ( V_8 && V_8 -> V_15 <= V_204 -> V_15 &&
V_8 -> V_16 >= V_204 -> V_15 + V_204 -> V_21 - 1 ) {
V_205 = F_148 ( V_169 , V_204 -> V_171 ,
V_204 -> V_21 ) ;
if ( V_205 > 1 ) {
V_74 = F_133 ( V_169 , V_15 , V_204 -> V_21 ,
V_204 -> V_171 , V_128 ,
V_204 -> V_208 ) ;
V_165 = ! V_74 ;
}
V_74 = 0 ;
}
V_107:
if ( ! V_74 )
V_74 = F_131 ( V_25 , V_204 , V_165 ) ;
return V_74 ;
}
static int F_149 ( struct V_40 * V_209 , T_1 V_210 ,
struct V_128 * V_128 , T_1 V_15 , T_1 V_16 ,
int V_208 )
{
struct V_163 * V_204 = NULL ;
T_1 V_49 ;
struct V_211 * V_212 ;
struct V_25 * V_25 = V_128 -> V_27 -> V_28 ;
struct V_24 * V_166 = & F_120 ( V_25 ) -> V_167 ;
struct V_24 * V_17 = & F_120 ( V_25 ) -> V_151 ;
struct V_213 * V_214 = & F_120 ( V_25 ) -> V_215 ;
struct V_40 * V_40 ;
struct V_39 * V_216 ;
struct V_39 * V_177 ;
int V_205 ;
int V_74 ;
int V_217 ;
T_1 V_171 ;
F_68 ( V_209 -> V_218 & V_219 ) ;
V_74 = F_127 ( V_166 , V_15 , & V_49 ) ;
if ( V_74 ) {
V_204 = F_150 ( sizeof( * V_204 ) , V_124 ) ;
if ( ! V_204 )
return - V_35 ;
V_204 -> V_15 = V_15 ;
V_204 -> V_21 = V_16 - V_15 + 1 ;
V_204 -> V_206 = 0 ;
V_204 -> V_220 = 0 ;
V_204 -> V_207 = 0 ;
F_151 ( & V_214 -> V_47 ) ;
V_212 = F_152 ( V_214 , V_15 , V_204 -> V_21 ) ;
if ( ! V_212 ) {
F_153 ( & V_214 -> V_47 ) ;
F_132 ( V_204 ) ;
return - V_185 ;
}
if ( V_212 -> V_15 > V_15 || V_212 -> V_15 + V_212 -> V_21 <= V_15 ) {
F_154 ( V_212 ) ;
V_212 = NULL ;
}
F_153 ( & V_214 -> V_47 ) ;
if ( ! V_212 ) {
F_132 ( V_204 ) ;
return - V_185 ;
}
V_171 = V_15 - V_212 -> V_15 ;
V_171 = V_212 -> V_221 + V_171 ;
if ( F_155 ( V_222 , & V_212 -> V_4 ) ) {
V_171 = V_212 -> V_221 ;
V_204 -> V_220 = V_223 ;
F_156 ( & V_204 -> V_220 ,
V_212 -> V_224 ) ;
}
F_147 ( L_17
L_18 , V_171 , V_15 , V_204 -> V_21 ) ;
V_204 -> V_171 = V_171 ;
F_154 ( V_212 ) ;
V_74 = F_85 ( V_166 , V_15 , V_16 ,
V_123 | V_92 , V_124 ) ;
if ( V_74 >= 0 )
V_74 = F_126 ( V_166 , V_15 ,
( T_1 ) ( unsigned long ) V_204 ) ;
if ( V_74 >= 0 )
V_74 = F_85 ( V_17 , V_15 , V_16 , V_168 ,
V_124 ) ;
if ( V_74 < 0 ) {
F_132 ( V_204 ) ;
return V_74 ;
}
} else {
V_204 = (struct V_163 * ) ( unsigned long ) V_49 ;
F_147 ( L_19
L_20 ,
V_204 -> V_171 , V_204 -> V_15 , V_204 -> V_21 ,
V_204 -> V_207 ) ;
}
V_205 = F_148 ( F_120 ( V_25 ) -> V_54 -> V_169 ,
V_204 -> V_171 , V_204 -> V_21 ) ;
if ( V_205 == 1 ) {
F_147 ( L_21 ,
V_205 , V_204 -> V_206 , V_208 ) ;
F_131 ( V_25 , V_204 , 0 ) ;
return - V_185 ;
}
if ( V_209 -> V_225 > 1 ) {
F_68 ( V_204 -> V_207 ) ;
V_204 -> V_207 = 1 ;
V_204 -> V_206 = V_208 ;
V_217 = V_226 | V_227 ;
} else {
if ( V_204 -> V_207 ) {
F_68 ( V_204 -> V_206 != V_208 ) ;
V_204 -> V_207 = 0 ;
V_204 -> V_206 = 0 ;
}
V_204 -> V_208 = V_208 ;
V_204 -> V_206 ++ ;
if ( V_204 -> V_206 == V_208 )
V_204 -> V_206 ++ ;
V_217 = V_226 ;
}
if ( V_204 -> V_206 > V_205 ) {
F_147 ( L_22 ,
V_205 , V_204 -> V_206 , V_208 ) ;
F_131 ( V_25 , V_204 , 0 ) ;
return - V_185 ;
}
V_40 = F_135 ( V_124 , 1 ) ;
if ( ! V_40 ) {
F_131 ( V_25 , V_204 , 0 ) ;
return - V_185 ;
}
V_40 -> V_228 = V_209 -> V_228 ;
V_40 -> V_186 . V_191 = V_204 -> V_171 >> 9 ;
V_40 -> V_194 = F_120 ( V_25 ) -> V_54 -> V_169 -> V_229 -> V_230 ;
V_40 -> V_186 . V_187 = 0 ;
V_216 = V_39 ( V_209 ) ;
if ( V_216 -> V_231 ) {
struct V_31 * V_169 = F_120 ( V_25 ) -> V_54 -> V_169 ;
T_6 V_232 = F_157 ( V_169 -> V_233 ) ;
V_177 = V_39 ( V_40 ) ;
V_177 -> V_231 = V_177 -> V_234 ;
V_210 >>= V_25 -> V_32 -> V_235 ;
V_210 *= V_232 ;
memcpy ( V_177 -> V_231 , V_216 -> V_231 + V_210 ,
V_232 ) ;
}
F_138 ( V_40 , V_128 , V_204 -> V_21 , V_15 - F_129 ( V_128 ) ) ;
F_147 ( L_23
L_24 , V_217 ,
V_204 -> V_206 , V_205 , V_204 -> V_207 ) ;
V_74 = V_17 -> V_45 -> V_236 ( V_25 , V_217 , V_40 ,
V_204 -> V_206 ,
V_204 -> V_220 , 0 ) ;
return V_74 ;
}
int F_158 ( struct V_128 * V_128 , int V_95 , T_1 V_15 , T_1 V_16 )
{
int V_237 = ( V_95 == 0 ) ;
struct V_24 * V_17 ;
int V_74 = 0 ;
V_17 = & F_120 ( V_128 -> V_27 -> V_28 ) -> V_151 ;
if ( V_17 -> V_45 && V_17 -> V_45 -> V_238 ) {
V_74 = V_17 -> V_45 -> V_238 ( V_128 , V_15 ,
V_16 , NULL , V_237 ) ;
if ( V_74 )
V_237 = 0 ;
}
if ( ! V_237 ) {
F_159 ( V_128 ) ;
F_160 ( V_128 ) ;
V_74 = V_74 < 0 ? V_74 : - V_185 ;
F_161 ( V_128 -> V_27 , V_74 ) ;
}
return 0 ;
}
static void F_162 ( struct V_40 * V_40 , int V_95 )
{
struct V_239 * V_240 ;
T_1 V_15 ;
T_1 V_16 ;
int V_139 ;
F_163 (bvec, bio, i) {
struct V_128 * V_128 = V_240 -> V_241 ;
if ( V_240 -> V_242 || V_240 -> V_243 != V_148 ) {
if ( V_240 -> V_242 + V_240 -> V_243 != V_148 )
F_164 ( F_120 ( V_128 -> V_27 -> V_28 ) -> V_54 -> V_169 ,
L_25 ,
V_240 -> V_242 , V_240 -> V_243 ) ;
else
F_165 ( F_120 ( V_128 -> V_27 -> V_28 ) -> V_54 -> V_169 ,
L_26
L_27 ,
V_240 -> V_242 , V_240 -> V_243 ) ;
}
V_15 = F_129 ( V_128 ) ;
V_16 = V_15 + V_240 -> V_242 + V_240 -> V_243 - 1 ;
if ( F_158 ( V_128 , V_95 , V_15 , V_16 ) )
continue;
F_122 ( V_128 ) ;
}
F_137 ( V_40 ) ;
}
static void
F_166 ( struct V_24 * V_17 , T_1 V_15 , T_1 V_21 ,
int V_237 )
{
struct V_7 * V_98 = NULL ;
T_1 V_16 = V_15 + V_21 - 1 ;
if ( V_237 && V_17 -> V_244 )
F_91 ( V_17 , V_15 , V_16 , & V_98 , V_94 ) ;
F_96 ( V_17 , V_15 , V_16 , & V_98 , V_94 ) ;
}
static void F_167 ( struct V_40 * V_40 , int V_95 )
{
struct V_239 * V_240 ;
int V_237 = F_155 ( V_245 , & V_40 -> V_246 ) ;
struct V_39 * V_247 = V_39 ( V_40 ) ;
struct V_24 * V_17 ;
T_1 V_56 = 0 ;
T_1 V_15 ;
T_1 V_16 ;
T_1 V_21 ;
T_1 V_248 = 0 ;
T_1 V_249 = 0 ;
int V_250 ;
int V_74 ;
int V_139 ;
if ( V_95 )
V_237 = 0 ;
F_163 (bvec, bio, i) {
struct V_128 * V_128 = V_240 -> V_241 ;
struct V_25 * V_25 = V_128 -> V_27 -> V_28 ;
F_147 ( L_28
L_29 , ( T_1 ) V_40 -> V_186 . V_191 , V_95 ,
V_247 -> V_172 ) ;
V_17 = & F_120 ( V_25 ) -> V_151 ;
if ( V_240 -> V_242 || V_240 -> V_243 != V_148 ) {
if ( V_240 -> V_242 + V_240 -> V_243 != V_148 )
F_164 ( F_120 ( V_128 -> V_27 -> V_28 ) -> V_54 -> V_169 ,
L_30 ,
V_240 -> V_242 , V_240 -> V_243 ) ;
else
F_165 ( F_120 ( V_128 -> V_27 -> V_28 ) -> V_54 -> V_169 ,
L_31
L_27 ,
V_240 -> V_242 , V_240 -> V_243 ) ;
}
V_15 = F_129 ( V_128 ) ;
V_16 = V_15 + V_240 -> V_242 + V_240 -> V_243 - 1 ;
V_21 = V_240 -> V_243 ;
V_250 = V_247 -> V_172 ;
if ( F_168 ( V_237 && V_17 -> V_45 &&
V_17 -> V_45 -> V_251 ) ) {
V_74 = V_17 -> V_45 -> V_251 ( V_247 , V_56 ,
V_128 , V_15 , V_16 ,
V_250 ) ;
if ( V_74 )
V_237 = 0 ;
else
F_146 ( V_15 , V_128 ) ;
}
if ( F_168 ( V_237 ) )
goto V_252;
if ( V_17 -> V_45 && V_17 -> V_45 -> V_253 ) {
V_74 = V_17 -> V_45 -> V_253 ( V_128 , V_250 ) ;
if ( ! V_74 && ! V_95 &&
F_155 ( V_245 , & V_40 -> V_246 ) )
V_237 = 1 ;
} else {
V_74 = F_149 ( V_40 , V_56 , V_128 , V_15 , V_16 ,
V_250 ) ;
if ( V_74 == 0 ) {
V_237 =
F_155 ( V_245 , & V_40 -> V_246 ) ;
if ( V_95 )
V_237 = 0 ;
V_56 += V_21 ;
continue;
}
}
V_252:
if ( F_168 ( V_237 ) ) {
T_7 V_254 = F_14 ( V_25 ) ;
T_8 V_127 = V_254 >> V_126 ;
unsigned V_56 ;
V_56 = V_254 & ( V_148 - 1 ) ;
if ( V_128 -> V_125 == V_127 && V_56 )
F_169 ( V_128 , V_56 , V_148 ) ;
F_130 ( V_128 ) ;
} else {
F_159 ( V_128 ) ;
F_160 ( V_128 ) ;
}
F_113 ( V_128 ) ;
V_56 += V_21 ;
if ( F_170 ( ! V_237 ) ) {
if ( V_249 ) {
F_166 ( V_17 ,
V_248 ,
V_249 , 1 ) ;
V_248 = 0 ;
V_249 = 0 ;
}
F_166 ( V_17 , V_15 ,
V_16 - V_15 + 1 , 0 ) ;
} else if ( ! V_249 ) {
V_248 = V_15 ;
V_249 = V_16 + 1 - V_15 ;
} else if ( V_248 + V_249 == V_15 ) {
V_249 += V_16 + 1 - V_15 ;
} else {
F_166 ( V_17 , V_248 ,
V_249 , V_237 ) ;
V_248 = V_15 ;
V_249 = V_16 + 1 - V_15 ;
}
}
if ( V_249 )
F_166 ( V_17 , V_248 , V_249 ,
V_237 ) ;
if ( V_247 -> V_255 )
V_247 -> V_255 ( V_247 , V_95 ) ;
F_137 ( V_40 ) ;
}
struct V_40 *
F_171 ( struct V_256 * V_192 , T_1 V_257 , int V_258 ,
T_3 V_259 )
{
struct V_39 * V_177 ;
struct V_40 * V_40 ;
V_40 = F_172 ( V_259 , V_258 , V_37 ) ;
if ( V_40 == NULL && ( V_260 -> V_4 & V_261 ) ) {
while ( ! V_40 && ( V_258 /= 2 ) ) {
V_40 = F_172 ( V_259 ,
V_258 , V_37 ) ;
}
}
if ( V_40 ) {
V_40 -> V_194 = V_192 ;
V_40 -> V_186 . V_191 = V_257 ;
V_177 = V_39 ( V_40 ) ;
V_177 -> V_231 = NULL ;
V_177 -> V_262 = NULL ;
V_177 -> V_255 = NULL ;
}
return V_40 ;
}
struct V_40 * F_173 ( struct V_40 * V_40 , T_3 V_263 )
{
return F_174 ( V_40 , V_263 , V_37 ) ;
}
struct V_40 * F_135 ( T_3 V_263 , unsigned int V_264 )
{
struct V_39 * V_177 ;
struct V_40 * V_40 ;
V_40 = F_172 ( V_263 , V_264 , V_37 ) ;
if ( V_40 ) {
V_177 = V_39 ( V_40 ) ;
V_177 -> V_231 = NULL ;
V_177 -> V_262 = NULL ;
V_177 -> V_255 = NULL ;
}
return V_40 ;
}
static int T_4 F_175 ( int V_265 , struct V_40 * V_40 ,
int V_172 , unsigned long V_220 )
{
int V_74 = 0 ;
struct V_239 * V_240 = V_40 -> V_266 + V_40 -> V_225 - 1 ;
struct V_128 * V_128 = V_240 -> V_241 ;
struct V_24 * V_17 = V_40 -> V_267 ;
T_1 V_15 ;
V_15 = F_129 ( V_128 ) + V_240 -> V_242 ;
V_40 -> V_267 = NULL ;
F_176 ( V_40 ) ;
if ( V_17 -> V_45 && V_17 -> V_45 -> V_236 )
V_74 = V_17 -> V_45 -> V_236 ( V_128 -> V_27 -> V_28 , V_265 , V_40 ,
V_172 , V_220 , V_15 ) ;
else
F_177 ( V_265 , V_40 ) ;
if ( F_178 ( V_40 , V_268 ) )
V_74 = - V_269 ;
F_137 ( V_40 ) ;
return V_74 ;
}
static int F_179 ( int V_265 , struct V_24 * V_17 , struct V_128 * V_128 ,
unsigned long V_56 , T_9 V_270 , struct V_40 * V_40 ,
unsigned long V_220 )
{
int V_74 = 0 ;
if ( V_17 -> V_45 && V_17 -> V_45 -> V_271 )
V_74 = V_17 -> V_45 -> V_271 ( V_265 , V_128 , V_56 , V_270 , V_40 ,
V_220 ) ;
F_68 ( V_74 < 0 ) ;
return V_74 ;
}
static int F_180 ( int V_265 , struct V_24 * V_17 ,
struct V_128 * V_128 , T_10 V_176 ,
T_9 V_270 , unsigned long V_56 ,
struct V_256 * V_192 ,
struct V_40 * * V_272 ,
unsigned long V_273 ,
T_11 V_274 ,
int V_172 ,
unsigned long V_275 ,
unsigned long V_220 )
{
int V_74 = 0 ;
struct V_40 * V_40 ;
int V_276 ;
int V_158 = 0 ;
int V_277 = V_220 & V_223 ;
int V_278 = V_275 & V_223 ;
T_9 V_279 = F_112 ( T_9 , V_270 , V_148 ) ;
if ( V_272 && * V_272 ) {
V_40 = * V_272 ;
if ( V_278 )
V_158 = V_40 -> V_186 . V_191 == V_176 ;
else
V_158 = F_181 ( V_40 ) == V_176 ;
if ( V_275 != V_220 || ! V_158 ||
F_179 ( V_265 , V_17 , V_128 , V_56 , V_279 , V_40 , V_220 ) ||
F_138 ( V_40 , V_128 , V_279 , V_56 ) < V_279 ) {
V_74 = F_175 ( V_265 , V_40 , V_172 ,
V_275 ) ;
if ( V_74 < 0 )
return V_74 ;
V_40 = NULL ;
} else {
return 0 ;
}
}
if ( V_277 )
V_276 = V_280 ;
else
V_276 = F_182 ( V_192 ) ;
V_40 = F_171 ( V_192 , V_176 , V_276 , V_124 | V_281 ) ;
if ( ! V_40 )
return - V_35 ;
F_138 ( V_40 , V_128 , V_279 , V_56 ) ;
V_40 -> V_228 = V_274 ;
V_40 -> V_267 = V_17 ;
if ( V_272 )
* V_272 = V_40 ;
else
V_74 = F_175 ( V_265 , V_40 , V_172 , V_220 ) ;
return V_74 ;
}
static void F_183 ( struct V_9 * V_10 ,
struct V_128 * V_128 )
{
if ( ! F_184 ( V_128 ) ) {
F_185 ( V_128 ) ;
F_186 ( V_128 ) ;
F_187 ( V_128 , ( unsigned long ) V_10 ) ;
} else {
F_37 ( V_128 -> V_49 != ( unsigned long ) V_10 ) ;
}
}
void F_188 ( struct V_128 * V_128 )
{
if ( ! F_184 ( V_128 ) ) {
F_185 ( V_128 ) ;
F_186 ( V_128 ) ;
F_187 ( V_128 , V_282 ) ;
}
}
static struct V_211 *
F_189 ( struct V_25 * V_25 , struct V_128 * V_128 , T_9 V_283 ,
T_1 V_15 , T_1 V_21 , T_12 * V_284 ,
struct V_211 * * V_285 )
{
struct V_211 * V_212 ;
if ( V_285 && * V_285 ) {
V_212 = * V_285 ;
if ( F_190 ( V_212 ) && V_15 >= V_212 -> V_15 &&
V_15 < F_191 ( V_212 ) ) {
F_78 ( & V_212 -> V_18 ) ;
return V_212 ;
}
F_154 ( V_212 ) ;
* V_285 = NULL ;
}
V_212 = V_284 ( V_25 , V_128 , V_283 , V_15 , V_21 , 0 ) ;
if ( V_285 && ! F_192 ( V_212 ) ) {
F_68 ( * V_285 ) ;
F_78 ( & V_212 -> V_18 ) ;
* V_285 = V_212 ;
}
return V_212 ;
}
static int F_193 ( struct V_24 * V_17 ,
struct V_128 * V_128 ,
T_12 * V_284 ,
struct V_211 * * V_285 ,
struct V_40 * * V_40 , int V_172 ,
unsigned long * V_220 , int V_265 )
{
struct V_25 * V_25 = V_128 -> V_27 -> V_28 ;
T_1 V_15 = F_129 ( V_128 ) ;
T_1 V_286 = V_15 + V_148 - 1 ;
T_1 V_16 ;
T_1 V_287 = V_15 ;
T_1 V_288 ;
T_1 V_289 = F_14 ( V_25 ) ;
T_1 V_221 ;
T_1 V_290 ;
T_10 V_176 ;
struct V_211 * V_212 ;
struct V_256 * V_192 ;
int V_74 ;
int V_276 = 0 ;
int V_291 = * V_220 & V_292 ;
T_9 V_283 = 0 ;
T_9 V_293 ;
T_9 V_294 ;
T_9 V_295 = V_25 -> V_32 -> V_296 ;
unsigned long V_297 = * V_220 & V_292 ;
F_188 ( V_128 ) ;
V_16 = V_286 ;
if ( ! F_194 ( V_128 ) ) {
if ( F_195 ( V_128 ) == 0 ) {
F_68 ( V_295 != V_29 ) ;
F_97 ( V_17 , V_15 , V_16 ) ;
goto V_107;
}
}
if ( V_128 -> V_125 == V_289 >> V_126 ) {
char * V_298 ;
T_9 V_299 = V_289 & ( V_148 - 1 ) ;
if ( V_299 ) {
V_293 = V_148 - V_299 ;
V_298 = F_196 ( V_128 ) ;
memset ( V_298 + V_299 , 0 , V_293 ) ;
F_197 ( V_128 ) ;
F_198 ( V_298 ) ;
}
}
while ( V_287 <= V_16 ) {
unsigned long V_300 = ( V_289 >> V_126 ) + 1 ;
if ( V_287 >= V_289 ) {
char * V_298 ;
struct V_7 * V_98 = NULL ;
V_293 = V_148 - V_283 ;
V_298 = F_196 ( V_128 ) ;
memset ( V_298 + V_283 , 0 , V_293 ) ;
F_197 ( V_128 ) ;
F_198 ( V_298 ) ;
F_91 ( V_17 , V_287 , V_287 + V_293 - 1 ,
& V_98 , V_124 ) ;
if ( ! V_291 )
F_96 ( V_17 , V_287 ,
V_287 + V_293 - 1 ,
& V_98 , V_124 ) ;
break;
}
V_212 = F_189 ( V_25 , V_128 , V_283 , V_287 ,
V_16 - V_287 + 1 , V_284 , V_285 ) ;
if ( F_192 ( V_212 ) ) {
F_160 ( V_128 ) ;
if ( ! V_291 )
F_97 ( V_17 , V_287 , V_16 ) ;
break;
}
V_288 = V_287 - V_212 -> V_15 ;
F_68 ( F_191 ( V_212 ) <= V_287 ) ;
F_68 ( V_16 < V_287 ) ;
if ( F_155 ( V_222 , & V_212 -> V_4 ) ) {
V_297 |= V_223 ;
F_156 ( & V_297 ,
V_212 -> V_224 ) ;
}
V_293 = F_124 ( F_191 ( V_212 ) - V_287 , V_16 - V_287 + 1 ) ;
V_290 = F_124 ( F_191 ( V_212 ) - 1 , V_16 ) ;
V_293 = F_199 ( V_293 , V_295 ) ;
if ( V_297 & V_223 ) {
V_294 = V_212 -> V_301 ;
V_176 = V_212 -> V_221 >> 9 ;
} else {
V_176 = ( V_212 -> V_221 + V_288 ) >> 9 ;
V_294 = V_293 ;
}
V_192 = V_212 -> V_192 ;
V_221 = V_212 -> V_221 ;
if ( F_155 ( V_302 , & V_212 -> V_4 ) )
V_221 = V_303 ;
F_154 ( V_212 ) ;
V_212 = NULL ;
if ( V_221 == V_303 ) {
char * V_298 ;
struct V_7 * V_98 = NULL ;
V_298 = F_196 ( V_128 ) ;
memset ( V_298 + V_283 , 0 , V_293 ) ;
F_197 ( V_128 ) ;
F_198 ( V_298 ) ;
F_91 ( V_17 , V_287 , V_287 + V_293 - 1 ,
& V_98 , V_124 ) ;
F_96 ( V_17 , V_287 , V_287 + V_293 - 1 ,
& V_98 , V_124 ) ;
V_287 = V_287 + V_293 ;
V_283 += V_293 ;
continue;
}
if ( F_118 ( V_17 , V_287 , V_290 ,
V_119 , 1 , NULL ) ) {
F_128 ( V_17 , V_128 ) ;
if ( ! V_291 )
F_97 ( V_17 , V_287 , V_287 + V_293 - 1 ) ;
V_287 = V_287 + V_293 ;
V_283 += V_293 ;
continue;
}
if ( V_221 == V_304 ) {
F_160 ( V_128 ) ;
if ( ! V_291 )
F_97 ( V_17 , V_287 , V_287 + V_293 - 1 ) ;
V_287 = V_287 + V_293 ;
V_283 += V_293 ;
continue;
}
V_300 -= V_128 -> V_125 ;
V_74 = F_180 ( V_265 , V_17 , V_128 ,
V_176 , V_294 , V_283 ,
V_192 , V_40 , V_300 ,
F_167 , V_172 ,
* V_220 ,
V_297 ) ;
if ( ! V_74 ) {
V_276 ++ ;
* V_220 = V_297 ;
} else {
F_160 ( V_128 ) ;
if ( ! V_291 )
F_97 ( V_17 , V_287 , V_287 + V_293 - 1 ) ;
}
V_287 = V_287 + V_293 ;
V_283 += V_293 ;
}
V_107:
if ( ! V_276 ) {
if ( ! F_200 ( V_128 ) )
F_130 ( V_128 ) ;
F_113 ( V_128 ) ;
}
return 0 ;
}
static inline void F_201 ( struct V_24 * V_17 ,
struct V_128 * V_137 [] , int V_138 ,
T_1 V_15 , T_1 V_16 ,
T_12 * V_284 ,
struct V_211 * * V_285 ,
struct V_40 * * V_40 , int V_172 ,
unsigned long * V_220 , int V_265 )
{
struct V_25 * V_25 ;
struct V_305 * V_306 ;
int V_125 ;
V_25 = V_137 [ 0 ] -> V_27 -> V_28 ;
while ( 1 ) {
F_94 ( V_17 , V_15 , V_16 ) ;
V_306 = F_202 ( V_25 , V_15 ,
V_16 - V_15 + 1 ) ;
if ( ! V_306 )
break;
F_97 ( V_17 , V_15 , V_16 ) ;
F_203 ( V_25 , V_306 , 1 ) ;
F_204 ( V_306 ) ;
}
for ( V_125 = 0 ; V_125 < V_138 ; V_125 ++ ) {
F_193 ( V_17 , V_137 [ V_125 ] , V_284 , V_285 , V_40 ,
V_172 , V_220 , V_265 ) ;
F_101 ( V_137 [ V_125 ] ) ;
}
}
static void F_205 ( struct V_24 * V_17 ,
struct V_128 * V_137 [] ,
int V_138 , T_12 * V_284 ,
struct V_211 * * V_285 ,
struct V_40 * * V_40 , int V_172 ,
unsigned long * V_220 , int V_265 )
{
T_1 V_15 = 0 ;
T_1 V_16 = 0 ;
T_1 V_307 ;
int V_125 ;
int V_308 = 0 ;
for ( V_125 = 0 ; V_125 < V_138 ; V_125 ++ ) {
V_307 = F_129 ( V_137 [ V_125 ] ) ;
if ( ! V_16 ) {
V_15 = V_307 ;
V_16 = V_15 + V_148 - 1 ;
V_308 = V_125 ;
} else if ( V_16 + 1 == V_307 ) {
V_16 += V_148 ;
} else {
F_201 ( V_17 , & V_137 [ V_308 ] ,
V_125 - V_308 , V_15 ,
V_16 , V_284 , V_285 ,
V_40 , V_172 , V_220 ,
V_265 ) ;
V_15 = V_307 ;
V_16 = V_15 + V_148 - 1 ;
V_308 = V_125 ;
}
}
if ( V_16 )
F_201 ( V_17 , & V_137 [ V_308 ] ,
V_125 - V_308 , V_15 ,
V_16 , V_284 , V_285 , V_40 ,
V_172 , V_220 , V_265 ) ;
}
static int F_206 ( struct V_24 * V_17 ,
struct V_128 * V_128 ,
T_12 * V_284 ,
struct V_40 * * V_40 , int V_172 ,
unsigned long * V_220 , int V_265 )
{
struct V_25 * V_25 = V_128 -> V_27 -> V_28 ;
struct V_305 * V_306 ;
T_1 V_15 = F_129 ( V_128 ) ;
T_1 V_16 = V_15 + V_148 - 1 ;
int V_74 ;
while ( 1 ) {
F_94 ( V_17 , V_15 , V_16 ) ;
V_306 = F_207 ( V_25 , V_15 ) ;
if ( ! V_306 )
break;
F_97 ( V_17 , V_15 , V_16 ) ;
F_203 ( V_25 , V_306 , 1 ) ;
F_204 ( V_306 ) ;
}
V_74 = F_193 ( V_17 , V_128 , V_284 , NULL , V_40 , V_172 ,
V_220 , V_265 ) ;
return V_74 ;
}
int F_208 ( struct V_24 * V_17 , struct V_128 * V_128 ,
T_12 * V_284 , int V_172 )
{
struct V_40 * V_40 = NULL ;
unsigned long V_220 = 0 ;
int V_74 ;
V_74 = F_206 ( V_17 , V_128 , V_284 , & V_40 , V_172 ,
& V_220 , V_309 ) ;
if ( V_40 )
V_74 = F_175 ( V_309 , V_40 , V_172 , V_220 ) ;
return V_74 ;
}
int F_209 ( struct V_24 * V_17 , struct V_128 * V_128 ,
T_12 * V_284 , int V_172 )
{
struct V_40 * V_40 = NULL ;
unsigned long V_220 = V_292 ;
int V_74 ;
V_74 = F_193 ( V_17 , V_128 , V_284 , NULL , & V_40 , V_172 ,
& V_220 , V_309 ) ;
if ( V_40 )
V_74 = F_175 ( V_309 , V_40 , V_172 , V_220 ) ;
return V_74 ;
}
static T_5 void F_210 ( struct V_128 * V_128 ,
struct V_310 * V_311 ,
unsigned long V_312 )
{
V_311 -> V_313 -= V_312 ;
if ( V_311 -> V_314 || ( V_311 -> V_313 > 0 &&
V_311 -> V_315 == 0 && V_311 -> V_316 == V_317 ) )
V_128 -> V_27 -> V_318 = V_128 -> V_125 + V_312 ;
}
static T_13 int F_211 ( struct V_25 * V_25 ,
struct V_128 * V_128 , struct V_310 * V_311 ,
struct V_319 * V_320 ,
T_1 V_140 ,
unsigned long * V_312 )
{
struct V_24 * V_17 = V_320 -> V_17 ;
T_1 V_286 = V_140 + V_148 - 1 ;
T_1 V_321 ;
T_1 V_322 = 0 ;
T_1 V_141 = 0 ;
int V_74 ;
int V_323 = 0 ;
if ( V_320 -> V_324 || ! V_17 -> V_45 || ! V_17 -> V_45 -> V_325 )
return 0 ;
while ( V_141 < V_286 ) {
V_321 = F_117 ( V_25 , V_17 ,
V_128 ,
& V_140 ,
& V_141 ,
128 * 1024 * 1024 ) ;
if ( V_321 == 0 ) {
V_140 = V_141 + 1 ;
continue;
}
V_74 = V_17 -> V_45 -> V_325 ( V_25 , V_128 ,
V_140 ,
V_141 ,
& V_323 ,
V_312 ) ;
if ( V_74 ) {
F_160 ( V_128 ) ;
V_74 = V_74 < 0 ? V_74 : - V_185 ;
goto V_146;
}
V_322 += ( V_141 - V_140 +
V_148 ) >>
V_126 ;
V_140 = V_141 + 1 ;
}
if ( V_311 -> V_313 < V_322 ) {
int V_326 = 8192 ;
if ( V_322 < V_326 * 2 )
V_326 = V_322 ;
V_311 -> V_313 = F_112 ( T_1 , V_322 ,
V_326 ) ;
}
if ( V_323 ) {
V_311 -> V_313 -= * V_312 ;
return 1 ;
}
V_74 = 0 ;
V_146:
return V_74 ;
}
static T_13 int F_212 ( struct V_25 * V_25 ,
struct V_128 * V_128 ,
struct V_310 * V_311 ,
struct V_319 * V_320 ,
T_7 V_254 ,
unsigned long V_312 ,
int V_327 , int * V_328 )
{
struct V_24 * V_17 = V_320 -> V_17 ;
T_1 V_15 = F_129 ( V_128 ) ;
T_1 V_286 = V_15 + V_148 - 1 ;
T_1 V_16 ;
T_1 V_287 = V_15 ;
T_1 V_288 ;
T_1 V_221 ;
T_1 V_293 ;
T_10 V_176 ;
struct V_7 * V_97 = NULL ;
struct V_211 * V_212 ;
struct V_256 * V_192 ;
T_9 V_283 = 0 ;
T_9 V_295 ;
int V_74 = 0 ;
int V_276 = 0 ;
bool V_329 ;
if ( V_17 -> V_45 && V_17 -> V_45 -> V_330 ) {
V_74 = V_17 -> V_45 -> V_330 ( V_128 , V_15 ,
V_286 ) ;
if ( V_74 ) {
if ( V_74 == - V_331 )
V_311 -> V_332 ++ ;
else
F_213 ( V_311 , V_128 ) ;
F_210 ( V_128 , V_311 , V_312 ) ;
F_113 ( V_128 ) ;
V_74 = 1 ;
goto V_333;
}
}
F_210 ( V_128 , V_311 , V_312 + 1 ) ;
V_16 = V_286 ;
if ( V_254 <= V_15 ) {
if ( V_17 -> V_45 && V_17 -> V_45 -> V_238 )
V_17 -> V_45 -> V_238 ( V_128 , V_15 ,
V_286 , NULL , 1 ) ;
goto V_146;
}
V_295 = V_25 -> V_32 -> V_296 ;
while ( V_287 <= V_16 ) {
T_1 V_334 ;
if ( V_287 >= V_254 ) {
if ( V_17 -> V_45 && V_17 -> V_45 -> V_238 )
V_17 -> V_45 -> V_238 ( V_128 , V_287 ,
V_286 , NULL , 1 ) ;
break;
}
V_212 = V_320 -> V_284 ( V_25 , V_128 , V_283 , V_287 ,
V_16 - V_287 + 1 , 1 ) ;
if ( F_192 ( V_212 ) ) {
F_160 ( V_128 ) ;
V_74 = F_214 ( V_212 ) ;
break;
}
V_288 = V_287 - V_212 -> V_15 ;
V_334 = F_191 ( V_212 ) ;
F_68 ( V_334 <= V_287 ) ;
F_68 ( V_16 < V_287 ) ;
V_293 = F_124 ( V_334 - V_287 , V_16 - V_287 + 1 ) ;
V_293 = F_199 ( V_293 , V_295 ) ;
V_176 = ( V_212 -> V_221 + V_288 ) >> 9 ;
V_192 = V_212 -> V_192 ;
V_221 = V_212 -> V_221 ;
V_329 = F_155 ( V_222 , & V_212 -> V_4 ) ;
F_154 ( V_212 ) ;
V_212 = NULL ;
if ( V_329 || V_221 == V_303 ||
V_221 == V_304 ) {
if ( ! V_329 && V_17 -> V_45 &&
V_17 -> V_45 -> V_238 )
V_17 -> V_45 -> V_238 ( V_128 , V_287 ,
V_287 + V_293 - 1 ,
NULL , 1 ) ;
else if ( V_329 ) {
V_276 ++ ;
}
V_287 += V_293 ;
V_283 += V_293 ;
continue;
}
if ( V_17 -> V_45 && V_17 -> V_45 -> V_335 ) {
V_74 = V_17 -> V_45 -> V_335 ( V_128 , V_287 ,
V_287 + V_293 - 1 ) ;
} else {
V_74 = 0 ;
}
if ( V_74 ) {
F_160 ( V_128 ) ;
} else {
unsigned long V_336 = ( V_254 >> V_126 ) + 1 ;
F_105 ( V_17 , V_287 , V_287 + V_293 - 1 ) ;
if ( ! F_215 ( V_128 ) ) {
F_164 ( F_120 ( V_25 ) -> V_54 -> V_169 ,
L_32 ,
V_128 -> V_125 , V_287 , V_16 ) ;
}
V_74 = F_180 ( V_327 , V_17 , V_128 ,
V_176 , V_293 , V_283 ,
V_192 , & V_320 -> V_40 , V_336 ,
F_162 ,
0 , 0 , 0 ) ;
if ( V_74 )
F_160 ( V_128 ) ;
}
V_287 = V_287 + V_293 ;
V_283 += V_293 ;
V_276 ++ ;
}
V_146:
* V_328 = V_276 ;
V_333:
F_35 ( V_97 ) ;
return V_74 ;
}
static int F_216 ( struct V_128 * V_128 , struct V_310 * V_311 ,
void * V_337 )
{
struct V_25 * V_25 = V_128 -> V_27 -> V_28 ;
struct V_319 * V_320 = V_337 ;
T_1 V_15 = F_129 ( V_128 ) ;
T_1 V_286 = V_15 + V_148 - 1 ;
int V_74 ;
int V_276 = 0 ;
T_9 V_283 = 0 ;
T_7 V_254 = F_14 ( V_25 ) ;
unsigned long V_127 = V_254 >> V_126 ;
int V_327 ;
unsigned long V_312 = 0 ;
if ( V_311 -> V_338 == V_339 )
V_327 = V_195 ;
else
V_327 = V_188 ;
F_217 ( V_128 , V_25 , V_311 ) ;
F_37 ( ! F_218 ( V_128 ) ) ;
F_219 ( V_128 ) ;
V_283 = V_254 & ( V_148 - 1 ) ;
if ( V_128 -> V_125 > V_127 ||
( V_128 -> V_125 == V_127 && ! V_283 ) ) {
V_128 -> V_27 -> V_340 -> V_341 ( V_128 , 0 , V_148 ) ;
F_113 ( V_128 ) ;
return 0 ;
}
if ( V_128 -> V_125 == V_127 ) {
char * V_298 ;
V_298 = F_196 ( V_128 ) ;
memset ( V_298 + V_283 , 0 ,
V_148 - V_283 ) ;
F_198 ( V_298 ) ;
F_197 ( V_128 ) ;
}
V_283 = 0 ;
F_188 ( V_128 ) ;
V_74 = F_211 ( V_25 , V_128 , V_311 , V_320 , V_15 , & V_312 ) ;
if ( V_74 == 1 )
goto V_333;
if ( V_74 )
goto V_146;
V_74 = F_212 ( V_25 , V_128 , V_311 , V_320 ,
V_254 , V_312 , V_327 , & V_276 ) ;
if ( V_74 == 1 )
goto V_333;
V_146:
if ( V_276 == 0 ) {
F_106 ( V_128 ) ;
F_122 ( V_128 ) ;
}
if ( F_200 ( V_128 ) ) {
V_74 = V_74 < 0 ? V_74 : - V_185 ;
F_158 ( V_128 , V_74 , V_15 , V_286 ) ;
}
F_113 ( V_128 ) ;
return V_74 ;
V_333:
return 0 ;
}
void F_220 ( struct V_9 * V_10 )
{
F_221 ( & V_10 -> V_342 , V_343 ,
V_110 ) ;
}
static T_13 int
F_222 ( struct V_9 * V_10 ,
struct V_31 * V_169 ,
struct V_319 * V_320 )
{
unsigned long V_139 , V_201 ;
int V_344 = 0 ;
int V_74 = 0 ;
if ( ! F_223 ( V_10 ) ) {
V_344 = 1 ;
F_224 ( V_320 ) ;
F_225 ( V_10 ) ;
}
if ( F_155 ( V_343 , & V_10 -> V_342 ) ) {
F_226 ( V_10 ) ;
if ( ! V_320 -> V_345 )
return 0 ;
if ( ! V_344 ) {
F_224 ( V_320 ) ;
V_344 = 1 ;
}
while ( 1 ) {
F_220 ( V_10 ) ;
F_225 ( V_10 ) ;
if ( ! F_155 ( V_343 , & V_10 -> V_342 ) )
break;
F_226 ( V_10 ) ;
}
}
F_66 ( & V_10 -> V_346 ) ;
if ( F_227 ( V_347 , & V_10 -> V_342 ) ) {
F_228 ( V_343 , & V_10 -> V_342 ) ;
F_70 ( & V_10 -> V_346 ) ;
F_229 ( V_10 , V_348 ) ;
F_230 ( & V_169 -> V_349 ,
- V_10 -> V_21 ,
V_169 -> V_350 ) ;
V_74 = 1 ;
} else {
F_70 ( & V_10 -> V_346 ) ;
}
F_226 ( V_10 ) ;
if ( ! V_74 )
return V_74 ;
V_201 = F_144 ( V_10 -> V_15 , V_10 -> V_21 ) ;
for ( V_139 = 0 ; V_139 < V_201 ; V_139 ++ ) {
struct V_128 * V_60 = F_145 ( V_10 , V_139 ) ;
if ( ! F_231 ( V_60 ) ) {
if ( ! V_344 ) {
F_224 ( V_320 ) ;
V_344 = 1 ;
}
F_115 ( V_60 ) ;
}
}
return V_74 ;
}
static void F_232 ( struct V_9 * V_10 )
{
F_233 ( V_343 , & V_10 -> V_342 ) ;
F_234 () ;
F_235 ( & V_10 -> V_342 , V_343 ) ;
}
static void F_236 ( struct V_40 * V_40 , int V_95 )
{
struct V_239 * V_240 ;
struct V_9 * V_10 ;
int V_139 , V_146 ;
F_163 (bvec, bio, i) {
struct V_128 * V_128 = V_240 -> V_241 ;
V_10 = (struct V_9 * ) V_128 -> V_49 ;
F_68 ( ! V_10 ) ;
V_146 = F_36 ( & V_10 -> V_351 ) ;
if ( V_95 || F_155 ( V_352 , & V_10 -> V_342 ) ) {
F_228 ( V_352 , & V_10 -> V_342 ) ;
F_159 ( V_128 ) ;
F_160 ( V_128 ) ;
}
F_122 ( V_128 ) ;
if ( ! V_146 )
continue;
F_232 ( V_10 ) ;
}
F_137 ( V_40 ) ;
}
static T_13 int F_237 ( struct V_9 * V_10 ,
struct V_31 * V_169 ,
struct V_310 * V_311 ,
struct V_319 * V_320 )
{
struct V_256 * V_192 = V_169 -> V_229 -> V_230 ;
struct V_24 * V_17 = & F_120 ( V_169 -> V_353 ) -> V_151 ;
T_1 V_56 = V_10 -> V_15 ;
unsigned long V_139 , V_201 ;
unsigned long V_220 = 0 ;
int V_265 = ( V_320 -> V_345 ? V_195 : V_188 ) | V_354 ;
int V_74 = 0 ;
F_233 ( V_352 , & V_10 -> V_342 ) ;
V_201 = F_144 ( V_10 -> V_15 , V_10 -> V_21 ) ;
F_32 ( & V_10 -> V_351 , V_201 ) ;
if ( F_238 ( V_10 ) == V_355 )
V_220 = V_356 ;
for ( V_139 = 0 ; V_139 < V_201 ; V_139 ++ ) {
struct V_128 * V_60 = F_145 ( V_10 , V_139 ) ;
F_100 ( V_60 ) ;
F_106 ( V_60 ) ;
V_74 = F_180 ( V_265 , V_17 , V_60 , V_56 >> 9 ,
V_148 , 0 , V_192 , & V_320 -> V_40 ,
- 1 , F_236 ,
0 , V_320 -> V_220 , V_220 ) ;
V_320 -> V_220 = V_220 ;
if ( V_74 ) {
F_228 ( V_352 , & V_10 -> V_342 ) ;
F_160 ( V_60 ) ;
if ( F_239 ( V_201 - V_139 , & V_10 -> V_351 ) )
F_232 ( V_10 ) ;
V_74 = - V_185 ;
break;
}
V_56 += V_148 ;
F_210 ( V_60 , V_311 , 1 ) ;
F_113 ( V_60 ) ;
}
if ( F_170 ( V_74 ) ) {
for (; V_139 < V_201 ; V_139 ++ ) {
struct V_128 * V_60 = F_145 ( V_10 , V_139 ) ;
F_113 ( V_60 ) ;
}
}
return V_74 ;
}
int F_240 ( struct V_43 * V_27 ,
struct V_310 * V_311 )
{
struct V_24 * V_17 = & F_120 ( V_27 -> V_28 ) -> V_151 ;
struct V_31 * V_169 = F_120 ( V_27 -> V_28 ) -> V_54 -> V_169 ;
struct V_9 * V_10 , * V_357 = NULL ;
struct V_319 V_320 = {
. V_40 = NULL ,
. V_17 = V_17 ,
. V_324 = 0 ,
. V_345 = V_311 -> V_338 == V_339 ,
. V_220 = 0 ,
} ;
int V_74 = 0 ;
int V_146 = 0 ;
int V_358 = 0 ;
struct V_359 V_360 ;
int V_138 ;
T_8 V_125 ;
T_8 V_16 ;
int V_361 = 0 ;
int V_362 ;
F_241 ( & V_360 , 0 ) ;
if ( V_311 -> V_314 ) {
V_125 = V_27 -> V_318 ;
V_16 = - 1 ;
} else {
V_125 = V_311 -> V_315 >> V_126 ;
V_16 = V_311 -> V_316 >> V_126 ;
V_361 = 1 ;
}
if ( V_311 -> V_338 == V_339 )
V_362 = V_363 ;
else
V_362 = V_364 ;
V_365:
if ( V_311 -> V_338 == V_339 )
F_242 ( V_27 , V_125 , V_16 ) ;
while ( ! V_146 && ! V_358 && ( V_125 <= V_16 ) &&
( V_138 = F_243 ( & V_360 , V_27 , & V_125 , V_362 ,
F_124 ( V_16 - V_125 , ( T_8 ) V_366 - 1 ) + 1 ) ) ) {
unsigned V_139 ;
V_361 = 1 ;
for ( V_139 = 0 ; V_139 < V_138 ; V_139 ++ ) {
struct V_128 * V_128 = V_360 . V_137 [ V_139 ] ;
if ( ! F_184 ( V_128 ) )
continue;
if ( ! V_311 -> V_314 && V_128 -> V_125 > V_16 ) {
V_146 = 1 ;
break;
}
F_66 ( & V_27 -> V_367 ) ;
if ( ! F_184 ( V_128 ) ) {
F_70 ( & V_27 -> V_367 ) ;
continue;
}
V_10 = (struct V_9 * ) V_128 -> V_49 ;
if ( F_37 ( ! V_10 ) ) {
F_70 ( & V_27 -> V_367 ) ;
continue;
}
if ( V_10 == V_357 ) {
F_70 ( & V_27 -> V_367 ) ;
continue;
}
V_74 = F_244 ( & V_10 -> V_18 ) ;
F_70 ( & V_27 -> V_367 ) ;
if ( ! V_74 )
continue;
V_357 = V_10 ;
V_74 = F_222 ( V_10 , V_169 , & V_320 ) ;
if ( ! V_74 ) {
F_245 ( V_10 ) ;
continue;
}
V_74 = F_237 ( V_10 , V_169 , V_311 , & V_320 ) ;
if ( V_74 ) {
V_146 = 1 ;
F_245 ( V_10 ) ;
break;
}
F_245 ( V_10 ) ;
V_358 = V_311 -> V_313 <= 0 ;
}
F_246 ( & V_360 ) ;
F_71 () ;
}
if ( ! V_361 && ! V_146 ) {
V_361 = 1 ;
V_125 = 0 ;
goto V_365;
}
F_224 ( & V_320 ) ;
return V_74 ;
}
static int F_247 ( struct V_24 * V_17 ,
struct V_43 * V_27 ,
struct V_310 * V_311 ,
T_14 V_368 , void * V_337 ,
void (* F_248)( void * ) )
{
struct V_25 * V_25 = V_27 -> V_28 ;
int V_74 = 0 ;
int V_146 = 0 ;
int V_95 = 0 ;
int V_358 = 0 ;
struct V_359 V_360 ;
int V_138 ;
T_8 V_125 ;
T_8 V_16 ;
int V_361 = 0 ;
int V_362 ;
if ( ! F_249 ( V_25 ) )
return 0 ;
F_241 ( & V_360 , 0 ) ;
if ( V_311 -> V_314 ) {
V_125 = V_27 -> V_318 ;
V_16 = - 1 ;
} else {
V_125 = V_311 -> V_315 >> V_126 ;
V_16 = V_311 -> V_316 >> V_126 ;
V_361 = 1 ;
}
if ( V_311 -> V_338 == V_339 )
V_362 = V_363 ;
else
V_362 = V_364 ;
V_365:
if ( V_311 -> V_338 == V_339 )
F_242 ( V_27 , V_125 , V_16 ) ;
while ( ! V_146 && ! V_358 && ( V_125 <= V_16 ) &&
( V_138 = F_243 ( & V_360 , V_27 , & V_125 , V_362 ,
F_124 ( V_16 - V_125 , ( T_8 ) V_366 - 1 ) + 1 ) ) ) {
unsigned V_139 ;
V_361 = 1 ;
for ( V_139 = 0 ; V_139 < V_138 ; V_139 ++ ) {
struct V_128 * V_128 = V_360 . V_137 [ V_139 ] ;
if ( ! F_231 ( V_128 ) ) {
F_248 ( V_337 ) ;
F_115 ( V_128 ) ;
}
if ( F_170 ( V_128 -> V_27 != V_27 ) ) {
F_113 ( V_128 ) ;
continue;
}
if ( ! V_311 -> V_314 && V_128 -> V_125 > V_16 ) {
V_146 = 1 ;
F_113 ( V_128 ) ;
continue;
}
if ( V_311 -> V_338 != V_369 ) {
if ( F_215 ( V_128 ) )
F_248 ( V_337 ) ;
F_250 ( V_128 ) ;
}
if ( F_215 ( V_128 ) ||
! F_100 ( V_128 ) ) {
F_113 ( V_128 ) ;
continue;
}
V_74 = (* V_368)( V_128 , V_311 , V_337 ) ;
if ( F_170 ( V_74 == V_370 ) ) {
F_113 ( V_128 ) ;
V_74 = 0 ;
}
if ( ! V_95 && V_74 < 0 )
V_95 = V_74 ;
V_358 = V_311 -> V_313 <= 0 ;
}
F_246 ( & V_360 ) ;
F_71 () ;
}
if ( ! V_361 && ! V_146 && ! V_95 ) {
V_361 = 1 ;
V_125 = 0 ;
goto V_365;
}
F_251 ( V_25 ) ;
return V_95 ;
}
static void F_252 ( struct V_319 * V_320 )
{
if ( V_320 -> V_40 ) {
int V_265 = V_188 ;
int V_74 ;
if ( V_320 -> V_345 )
V_265 = V_195 ;
V_74 = F_175 ( V_265 , V_320 -> V_40 , 0 , V_320 -> V_220 ) ;
F_68 ( V_74 < 0 ) ;
V_320 -> V_40 = NULL ;
}
}
static T_5 void F_224 ( void * V_337 )
{
struct V_319 * V_320 = V_337 ;
F_252 ( V_320 ) ;
}
int F_253 ( struct V_24 * V_17 , struct V_128 * V_128 ,
T_12 * V_284 ,
struct V_310 * V_311 )
{
int V_74 ;
struct V_319 V_320 = {
. V_40 = NULL ,
. V_17 = V_17 ,
. V_284 = V_284 ,
. V_324 = 0 ,
. V_345 = V_311 -> V_338 == V_339 ,
. V_220 = 0 ,
} ;
V_74 = F_216 ( V_128 , V_311 , & V_320 ) ;
F_252 ( & V_320 ) ;
return V_74 ;
}
int F_254 ( struct V_24 * V_17 , struct V_25 * V_25 ,
T_1 V_15 , T_1 V_16 , T_12 * V_284 ,
int V_371 )
{
int V_74 = 0 ;
struct V_43 * V_27 = V_25 -> V_129 ;
struct V_128 * V_128 ;
unsigned long V_138 = ( V_16 - V_15 + V_148 ) >>
V_126 ;
struct V_319 V_320 = {
. V_40 = NULL ,
. V_17 = V_17 ,
. V_284 = V_284 ,
. V_324 = 1 ,
. V_345 = V_371 == V_339 ,
. V_220 = 0 ,
} ;
struct V_310 V_372 = {
. V_338 = V_371 ,
. V_313 = V_138 * 2 ,
. V_315 = V_15 ,
. V_316 = V_16 + 1 ,
} ;
while ( V_15 <= V_16 ) {
V_128 = F_99 ( V_27 , V_15 >> V_126 ) ;
if ( F_100 ( V_128 ) )
V_74 = F_216 ( V_128 , & V_372 , & V_320 ) ;
else {
if ( V_17 -> V_45 && V_17 -> V_45 -> V_238 )
V_17 -> V_45 -> V_238 ( V_128 , V_15 ,
V_15 + V_148 - 1 ,
NULL , 1 ) ;
F_113 ( V_128 ) ;
}
F_101 ( V_128 ) ;
V_15 += V_148 ;
}
F_252 ( & V_320 ) ;
return V_74 ;
}
int F_255 ( struct V_24 * V_17 ,
struct V_43 * V_27 ,
T_12 * V_284 ,
struct V_310 * V_311 )
{
int V_74 = 0 ;
struct V_319 V_320 = {
. V_40 = NULL ,
. V_17 = V_17 ,
. V_284 = V_284 ,
. V_324 = 0 ,
. V_345 = V_311 -> V_338 == V_339 ,
. V_220 = 0 ,
} ;
V_74 = F_247 ( V_17 , V_27 , V_311 ,
F_216 , & V_320 ,
F_224 ) ;
F_252 ( & V_320 ) ;
return V_74 ;
}
int F_256 ( struct V_24 * V_17 ,
struct V_43 * V_27 ,
struct V_1 * V_137 , unsigned V_138 ,
T_12 V_284 )
{
struct V_40 * V_40 = NULL ;
unsigned V_373 ;
unsigned long V_220 = 0 ;
struct V_128 * V_374 [ 16 ] ;
struct V_128 * V_128 ;
struct V_211 * V_285 = NULL ;
int V_276 = 0 ;
for ( V_373 = 0 ; V_373 < V_138 ; V_373 ++ ) {
V_128 = F_9 ( V_137 -> V_71 , struct V_128 , V_375 ) ;
F_257 ( & V_128 -> V_4 ) ;
F_6 ( & V_128 -> V_375 ) ;
if ( F_258 ( V_128 , V_27 ,
V_128 -> V_125 , V_124 ) ) {
F_101 ( V_128 ) ;
continue;
}
V_374 [ V_276 ++ ] = V_128 ;
if ( V_276 < F_259 ( V_374 ) )
continue;
F_205 ( V_17 , V_374 , V_276 , V_284 , & V_285 ,
& V_40 , 0 , & V_220 , V_309 ) ;
V_276 = 0 ;
}
if ( V_276 )
F_205 ( V_17 , V_374 , V_276 , V_284 , & V_285 ,
& V_40 , 0 , & V_220 , V_309 ) ;
if ( V_285 )
F_154 ( V_285 ) ;
F_68 ( ! F_8 ( V_137 ) ) ;
if ( V_40 )
return F_175 ( V_309 , V_40 , 0 , V_220 ) ;
return 0 ;
}
int F_260 ( struct V_24 * V_17 ,
struct V_128 * V_128 , unsigned long V_56 )
{
struct V_7 * V_97 = NULL ;
T_1 V_15 = F_129 ( V_128 ) ;
T_1 V_16 = V_15 + V_148 - 1 ;
T_9 V_295 = V_128 -> V_27 -> V_28 -> V_32 -> V_296 ;
V_15 += F_199 ( V_56 , V_295 ) ;
if ( V_15 > V_16 )
return 0 ;
F_93 ( V_17 , V_15 , V_16 , 0 , & V_97 ) ;
F_250 ( V_128 ) ;
F_64 ( V_17 , V_15 , V_16 ,
V_123 | V_92 | V_101 |
V_121 ,
1 , 1 , & V_97 , V_124 ) ;
return 0 ;
}
static int F_261 ( struct V_213 * V_376 ,
struct V_24 * V_17 ,
struct V_128 * V_128 , T_3 V_48 )
{
T_1 V_15 = F_129 ( V_128 ) ;
T_1 V_16 = V_15 + V_148 - 1 ;
int V_74 = 1 ;
if ( F_118 ( V_17 , V_15 , V_16 ,
V_78 , 0 , NULL ) )
V_74 = 0 ;
else {
if ( ( V_48 & V_124 ) == V_124 )
V_48 = V_124 ;
V_74 = F_64 ( V_17 , V_15 , V_16 ,
~ ( V_123 | V_377 ) ,
0 , 0 , NULL , V_48 ) ;
if ( V_74 < 0 )
V_74 = 0 ;
else
V_74 = 1 ;
}
return V_74 ;
}
int F_262 ( struct V_213 * V_376 ,
struct V_24 * V_17 , struct V_128 * V_128 ,
T_3 V_48 )
{
struct V_211 * V_212 ;
T_1 V_15 = F_129 ( V_128 ) ;
T_1 V_16 = V_15 + V_148 - 1 ;
if ( ( V_48 & V_105 ) &&
V_128 -> V_27 -> V_28 -> V_254 > 16 * 1024 * 1024 ) {
T_1 V_21 ;
while ( V_15 <= V_16 ) {
V_21 = V_16 - V_15 + 1 ;
F_263 ( & V_376 -> V_47 ) ;
V_212 = F_152 ( V_376 , V_15 , V_21 ) ;
if ( ! V_212 ) {
F_264 ( & V_376 -> V_47 ) ;
break;
}
if ( F_155 ( V_378 , & V_212 -> V_4 ) ||
V_212 -> V_15 != V_15 ) {
F_264 ( & V_376 -> V_47 ) ;
F_154 ( V_212 ) ;
break;
}
if ( ! F_118 ( V_17 , V_212 -> V_15 ,
F_191 ( V_212 ) - 1 ,
V_123 | V_379 ,
0 , NULL ) ) {
F_265 ( V_376 , V_212 ) ;
F_154 ( V_212 ) ;
}
V_15 = F_191 ( V_212 ) ;
F_264 ( & V_376 -> V_47 ) ;
F_154 ( V_212 ) ;
}
}
return F_261 ( V_376 , V_17 , V_128 , V_48 ) ;
}
static struct V_211 * F_266 ( struct V_25 * V_25 ,
T_1 V_56 ,
T_1 V_159 ,
T_12 * V_284 )
{
T_1 V_380 = F_120 ( V_25 ) -> V_54 -> V_380 ;
struct V_211 * V_212 ;
T_1 V_21 ;
if ( V_56 >= V_159 )
return NULL ;
while ( 1 ) {
V_21 = V_159 - V_56 ;
if ( V_21 == 0 )
break;
V_21 = F_199 ( V_21 , V_380 ) ;
V_212 = V_284 ( V_25 , NULL , 0 , V_56 , V_21 , 0 ) ;
if ( F_192 ( V_212 ) )
return V_212 ;
if ( ! F_155 ( V_381 , & V_212 -> V_4 ) &&
V_212 -> V_221 != V_303 ) {
return V_212 ;
}
V_56 = F_191 ( V_212 ) ;
F_154 ( V_212 ) ;
if ( V_56 >= V_159 )
break;
}
return NULL ;
}
static T_5 int F_267 ( T_1 V_382 , T_1 V_56 , T_1 V_383 , void * V_384 )
{
unsigned long V_385 = * ( ( unsigned long * ) V_384 ) ;
V_385 ++ ;
* ( ( unsigned long * ) V_384 ) = V_385 ;
if ( V_385 > 1 )
return 1 ;
return 0 ;
}
int F_268 ( struct V_25 * V_25 , struct V_386 * V_387 ,
T_15 V_15 , T_15 V_21 , T_12 * V_284 )
{
int V_74 = 0 ;
T_1 V_388 = V_15 ;
T_1 F_125 = V_15 + V_21 ;
T_16 V_4 = 0 ;
T_16 V_389 ;
T_1 V_159 ;
T_1 V_390 = 0 ;
T_1 V_391 = 0 ;
T_1 V_26 = F_14 ( V_25 ) ;
struct V_392 V_393 ;
struct V_211 * V_212 = NULL ;
struct V_7 * V_97 = NULL ;
struct V_394 * V_395 ;
int V_16 = 0 ;
T_1 V_396 = 0 ;
T_1 V_397 = 0 ;
T_1 V_334 = 0 ;
if ( V_21 == 0 )
return - V_398 ;
V_395 = F_269 () ;
if ( ! V_395 )
return - V_35 ;
V_395 -> V_399 = 1 ;
V_15 = F_270 ( V_15 , F_120 ( V_25 ) -> V_54 -> V_380 ) ;
V_21 = F_271 ( F_125 , F_120 ( V_25 ) -> V_54 -> V_380 ) - V_15 ;
V_74 = F_272 ( NULL , F_120 ( V_25 ) -> V_54 ,
V_395 , F_16 ( V_25 ) , - 1 , 0 ) ;
if ( V_74 < 0 ) {
F_273 ( V_395 ) ;
return V_74 ;
}
F_37 ( ! V_74 ) ;
V_395 -> V_400 [ 0 ] -- ;
F_274 ( V_395 -> V_401 [ 0 ] , & V_393 , V_395 -> V_400 [ 0 ] ) ;
V_389 = F_275 ( & V_393 ) ;
if ( V_393 . V_402 != F_16 ( V_25 ) ||
V_389 != V_403 ) {
V_159 = ( T_1 ) - 1 ;
V_390 = V_26 ;
} else {
V_159 = V_393 . V_56 ;
V_390 = V_159 + 1 ;
}
F_276 ( V_395 ) ;
if ( V_159 < V_26 ) {
V_159 = ( T_1 ) - 1 ;
V_390 = V_26 ;
}
F_93 ( & F_120 ( V_25 ) -> V_151 , V_15 , V_15 + V_21 - 1 , 0 ,
& V_97 ) ;
V_212 = F_266 ( V_25 , V_15 , V_390 ,
V_284 ) ;
if ( ! V_212 )
goto V_107;
if ( F_277 ( V_212 ) ) {
V_74 = F_278 ( V_212 ) ;
goto V_107;
}
while ( ! V_16 ) {
T_1 V_404 = 0 ;
if ( V_212 -> V_15 >= F_125 || F_191 ( V_212 ) < V_388 )
break;
V_396 = F_125 ( V_212 -> V_15 , V_388 ) ;
if ( ! F_155 ( V_222 , & V_212 -> V_4 ) )
V_404 = V_396 - V_212 -> V_15 ;
V_334 = F_191 ( V_212 ) ;
V_397 = V_334 - V_396 ;
V_391 = 0 ;
V_4 = 0 ;
V_388 = F_191 ( V_212 ) ;
if ( V_388 >= F_125 )
V_16 = 1 ;
if ( V_212 -> V_221 == V_405 ) {
V_16 = 1 ;
V_4 |= V_406 ;
} else if ( V_212 -> V_221 == V_304 ) {
V_4 |= ( V_407 |
V_408 ) ;
} else if ( V_212 -> V_221 == V_409 ) {
V_4 |= ( V_410 |
V_411 ) ;
} else {
unsigned long V_412 = 0 ;
V_391 = V_212 -> V_221 + V_404 ;
V_74 = F_279 (
V_212 -> V_221 ,
F_120 ( V_25 ) -> V_54 -> V_169 ,
V_395 , F_267 , & V_412 ) ;
if ( V_74 < 0 && V_74 != - V_160 )
goto V_413;
if ( V_412 > 1 )
V_4 |= V_414 ;
}
if ( F_155 ( V_222 , & V_212 -> V_4 ) )
V_4 |= V_415 ;
F_154 ( V_212 ) ;
V_212 = NULL ;
if ( ( V_396 >= V_159 ) || V_397 == ( T_1 ) - 1 ||
( V_159 == ( T_1 ) - 1 && V_26 <= V_334 ) ) {
V_4 |= V_406 ;
V_16 = 1 ;
}
V_212 = F_266 ( V_25 , V_388 , V_390 ,
V_284 ) ;
if ( F_277 ( V_212 ) ) {
V_74 = F_278 ( V_212 ) ;
goto V_107;
}
if ( ! V_212 ) {
V_4 |= V_406 ;
V_16 = 1 ;
}
V_74 = F_280 ( V_387 , V_396 , V_391 ,
V_397 , V_4 ) ;
if ( V_74 )
goto V_413;
}
V_413:
F_154 ( V_212 ) ;
V_107:
F_273 ( V_395 ) ;
F_96 ( & F_120 ( V_25 ) -> V_151 , V_15 , V_15 + V_21 - 1 ,
& V_97 , V_124 ) ;
return V_74 ;
}
static void F_281 ( struct V_9 * V_10 )
{
F_5 ( & V_10 -> V_13 ) ;
F_12 ( V_22 , V_10 ) ;
}
int F_282 ( struct V_9 * V_10 )
{
return ( F_11 ( & V_10 -> V_351 ) ||
F_155 ( V_343 , & V_10 -> V_342 ) ||
F_155 ( V_347 , & V_10 -> V_342 ) ) ;
}
static void F_283 ( struct V_9 * V_10 ,
unsigned long V_416 )
{
unsigned long V_125 ;
unsigned long V_201 ;
struct V_128 * V_128 ;
int V_417 = ! F_155 ( V_418 , & V_10 -> V_342 ) ;
F_68 ( F_282 ( V_10 ) ) ;
V_201 = F_144 ( V_10 -> V_15 , V_10 -> V_21 ) ;
V_125 = V_416 + V_201 ;
if ( V_416 >= V_125 )
return;
do {
V_125 -- ;
V_128 = F_145 ( V_10 , V_125 ) ;
if ( V_128 && V_417 ) {
F_66 ( & V_128 -> V_27 -> V_367 ) ;
if ( F_184 ( V_128 ) &&
V_128 -> V_49 == ( unsigned long ) V_10 ) {
F_68 ( F_155 ( V_347 , & V_10 -> V_342 ) ) ;
F_68 ( F_116 ( V_128 ) ) ;
F_68 ( F_215 ( V_128 ) ) ;
F_284 ( V_128 ) ;
F_187 ( V_128 , 0 ) ;
F_101 ( V_128 ) ;
}
F_70 ( & V_128 -> V_27 -> V_367 ) ;
}
if ( V_128 ) {
F_101 ( V_128 ) ;
}
} while ( V_125 != V_416 );
}
static inline void F_285 ( struct V_9 * V_10 )
{
F_283 ( V_10 , 0 ) ;
F_281 ( V_10 ) ;
}
static struct V_9 *
F_286 ( struct V_31 * V_169 , T_1 V_15 ,
unsigned long V_21 , T_3 V_48 )
{
struct V_9 * V_10 = NULL ;
V_10 = F_287 ( V_22 , V_48 ) ;
if ( V_10 == NULL )
return NULL ;
V_10 -> V_15 = V_15 ;
V_10 -> V_21 = V_21 ;
V_10 -> V_169 = V_169 ;
V_10 -> V_342 = 0 ;
F_288 ( & V_10 -> V_47 ) ;
F_32 ( & V_10 -> V_419 , 0 ) ;
F_32 ( & V_10 -> V_420 , 0 ) ;
F_32 ( & V_10 -> V_421 , 0 ) ;
F_32 ( & V_10 -> V_422 , 0 ) ;
F_32 ( & V_10 -> V_423 , 0 ) ;
F_32 ( & V_10 -> V_424 , 0 ) ;
V_10 -> V_425 = 0 ;
F_33 ( & V_10 -> V_426 ) ;
F_33 ( & V_10 -> V_427 ) ;
F_1 ( & V_10 -> V_13 , & V_20 ) ;
F_29 ( & V_10 -> V_346 ) ;
F_32 ( & V_10 -> V_18 , 1 ) ;
F_32 ( & V_10 -> V_351 , 0 ) ;
F_289 ( V_428
> V_429 ) ;
F_68 ( V_21 > V_429 ) ;
return V_10 ;
}
struct V_9 * F_290 ( struct V_9 * V_430 )
{
unsigned long V_139 ;
struct V_128 * V_60 ;
struct V_9 * V_2 ;
unsigned long V_201 = F_144 ( V_430 -> V_15 , V_430 -> V_21 ) ;
V_2 = F_286 ( NULL , V_430 -> V_15 , V_430 -> V_21 , V_124 ) ;
if ( V_2 == NULL )
return NULL ;
for ( V_139 = 0 ; V_139 < V_201 ; V_139 ++ ) {
V_60 = F_291 ( V_124 ) ;
if ( ! V_60 ) {
F_285 ( V_2 ) ;
return NULL ;
}
F_183 ( V_2 , V_60 ) ;
F_37 ( F_116 ( V_60 ) ) ;
F_130 ( V_60 ) ;
V_2 -> V_137 [ V_139 ] = V_60 ;
}
F_292 ( V_2 , V_430 , 0 , 0 , V_430 -> V_21 ) ;
F_228 ( V_431 , & V_2 -> V_342 ) ;
F_228 ( V_418 , & V_2 -> V_342 ) ;
return V_2 ;
}
struct V_9 * F_293 ( T_1 V_15 , unsigned long V_21 )
{
struct V_9 * V_10 ;
unsigned long V_201 = F_144 ( 0 , V_21 ) ;
unsigned long V_139 ;
V_10 = F_286 ( NULL , V_15 , V_21 , V_124 ) ;
if ( ! V_10 )
return NULL ;
for ( V_139 = 0 ; V_139 < V_201 ; V_139 ++ ) {
V_10 -> V_137 [ V_139 ] = F_291 ( V_124 ) ;
if ( ! V_10 -> V_137 [ V_139 ] )
goto V_95;
}
F_294 ( V_10 ) ;
F_295 ( V_10 , 0 ) ;
F_228 ( V_418 , & V_10 -> V_342 ) ;
return V_10 ;
V_95:
for (; V_139 > 0 ; V_139 -- )
F_296 ( V_10 -> V_137 [ V_139 - 1 ] ) ;
F_281 ( V_10 ) ;
return NULL ;
}
static void F_297 ( struct V_9 * V_10 )
{
int V_18 ;
V_18 = F_11 ( & V_10 -> V_18 ) ;
if ( V_18 >= 2 && F_155 ( V_432 , & V_10 -> V_342 ) )
return;
F_66 ( & V_10 -> V_346 ) ;
if ( ! F_298 ( V_432 , & V_10 -> V_342 ) )
F_78 ( & V_10 -> V_18 ) ;
F_70 ( & V_10 -> V_346 ) ;
}
static void F_299 ( struct V_9 * V_10 ,
struct V_128 * V_433 )
{
unsigned long V_201 , V_139 ;
F_297 ( V_10 ) ;
V_201 = F_144 ( V_10 -> V_15 , V_10 -> V_21 ) ;
for ( V_139 = 0 ; V_139 < V_201 ; V_139 ++ ) {
struct V_128 * V_60 = F_145 ( V_10 , V_139 ) ;
if ( V_60 != V_433 )
F_300 ( V_60 ) ;
}
}
struct V_9 * F_301 ( struct V_31 * V_169 ,
T_1 V_15 )
{
struct V_9 * V_10 ;
F_302 () ;
V_10 = F_303 ( & V_169 -> V_434 ,
V_15 >> V_126 ) ;
if ( V_10 && F_244 ( & V_10 -> V_18 ) ) {
F_304 () ;
F_299 ( V_10 , NULL ) ;
return V_10 ;
}
F_304 () ;
return NULL ;
}
struct V_9 * F_305 ( struct V_31 * V_169 ,
T_1 V_15 , unsigned long V_21 )
{
struct V_9 * V_10 , * V_435 = NULL ;
int V_74 ;
V_10 = F_301 ( V_169 , V_15 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_293 ( V_15 , V_21 ) ;
if ( ! V_10 )
return NULL ;
V_10 -> V_169 = V_169 ;
V_104:
V_74 = F_306 ( V_124 & ~ V_436 ) ;
if ( V_74 )
goto V_437;
F_66 ( & V_169 -> V_438 ) ;
V_74 = F_307 ( & V_169 -> V_434 ,
V_15 >> V_126 , V_10 ) ;
F_70 ( & V_169 -> V_438 ) ;
F_308 () ;
if ( V_74 == - V_84 ) {
V_435 = F_301 ( V_169 , V_15 ) ;
if ( V_435 )
goto V_437;
else
goto V_104;
}
F_297 ( V_10 ) ;
F_228 ( V_439 , & V_10 -> V_342 ) ;
F_78 ( & V_10 -> V_18 ) ;
return V_10 ;
V_437:
F_285 ( V_10 ) ;
return V_435 ;
}
struct V_9 * F_309 ( struct V_31 * V_169 ,
T_1 V_15 , unsigned long V_21 )
{
unsigned long V_201 = F_144 ( V_15 , V_21 ) ;
unsigned long V_139 ;
unsigned long V_125 = V_15 >> V_126 ;
struct V_9 * V_10 ;
struct V_9 * V_435 = NULL ;
struct V_128 * V_60 ;
struct V_43 * V_27 = V_169 -> V_353 -> V_129 ;
int V_237 = 1 ;
int V_74 ;
V_10 = F_301 ( V_169 , V_15 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_286 ( V_169 , V_15 , V_21 , V_124 ) ;
if ( ! V_10 )
return NULL ;
for ( V_139 = 0 ; V_139 < V_201 ; V_139 ++ , V_125 ++ ) {
V_60 = F_310 ( V_27 , V_125 , V_124 ) ;
if ( ! V_60 )
goto V_437;
F_66 ( & V_27 -> V_367 ) ;
if ( F_184 ( V_60 ) ) {
V_435 = (struct V_9 * ) V_60 -> V_49 ;
if ( F_244 ( & V_435 -> V_18 ) ) {
F_70 ( & V_27 -> V_367 ) ;
F_113 ( V_60 ) ;
F_101 ( V_60 ) ;
F_299 ( V_435 , V_60 ) ;
goto V_437;
}
F_284 ( V_60 ) ;
F_37 ( F_116 ( V_60 ) ) ;
F_101 ( V_60 ) ;
}
F_183 ( V_10 , V_60 ) ;
F_70 ( & V_27 -> V_367 ) ;
F_37 ( F_116 ( V_60 ) ) ;
V_10 -> V_137 [ V_139 ] = V_60 ;
if ( ! F_194 ( V_60 ) )
V_237 = 0 ;
}
if ( V_237 )
F_228 ( V_431 , & V_10 -> V_342 ) ;
V_104:
V_74 = F_306 ( V_124 & ~ V_436 ) ;
if ( V_74 )
goto V_437;
F_66 ( & V_169 -> V_438 ) ;
V_74 = F_307 ( & V_169 -> V_434 ,
V_15 >> V_126 , V_10 ) ;
F_70 ( & V_169 -> V_438 ) ;
F_308 () ;
if ( V_74 == - V_84 ) {
V_435 = F_301 ( V_169 , V_15 ) ;
if ( V_435 )
goto V_437;
else
goto V_104;
}
F_297 ( V_10 ) ;
F_228 ( V_439 , & V_10 -> V_342 ) ;
F_311 ( V_10 -> V_137 [ 0 ] ) ;
for ( V_139 = 1 ; V_139 < V_201 ; V_139 ++ ) {
V_60 = F_145 ( V_10 , V_139 ) ;
F_312 ( V_60 ) ;
F_113 ( V_60 ) ;
}
F_113 ( V_10 -> V_137 [ 0 ] ) ;
return V_10 ;
V_437:
for ( V_139 = 0 ; V_139 < V_201 ; V_139 ++ ) {
if ( V_10 -> V_137 [ V_139 ] )
F_113 ( V_10 -> V_137 [ V_139 ] ) ;
}
F_37 ( ! F_36 ( & V_10 -> V_18 ) ) ;
F_285 ( V_10 ) ;
return V_435 ;
}
static inline void F_313 ( struct V_440 * V_3 )
{
struct V_9 * V_10 =
F_314 ( V_3 , struct V_9 , V_440 ) ;
F_281 ( V_10 ) ;
}
static int F_315 ( struct V_9 * V_10 )
{
F_37 ( F_11 ( & V_10 -> V_18 ) == 0 ) ;
if ( F_36 ( & V_10 -> V_18 ) ) {
if ( F_227 ( V_439 , & V_10 -> V_342 ) ) {
struct V_31 * V_169 = V_10 -> V_169 ;
F_70 ( & V_10 -> V_346 ) ;
F_66 ( & V_169 -> V_438 ) ;
F_316 ( & V_169 -> V_434 ,
V_10 -> V_15 >> V_126 ) ;
F_70 ( & V_169 -> V_438 ) ;
} else {
F_70 ( & V_10 -> V_346 ) ;
}
F_283 ( V_10 , 0 ) ;
F_317 ( & V_10 -> V_440 , F_313 ) ;
return 1 ;
}
F_70 ( & V_10 -> V_346 ) ;
return 0 ;
}
void F_245 ( struct V_9 * V_10 )
{
int V_18 ;
int V_441 ;
if ( ! V_10 )
return;
while ( 1 ) {
V_18 = F_11 ( & V_10 -> V_18 ) ;
if ( V_18 <= 3 )
break;
V_441 = F_318 ( & V_10 -> V_18 , V_18 , V_18 - 1 ) ;
if ( V_441 == V_18 )
return;
}
F_66 ( & V_10 -> V_346 ) ;
if ( F_11 ( & V_10 -> V_18 ) == 2 &&
F_155 ( V_418 , & V_10 -> V_342 ) )
F_67 ( & V_10 -> V_18 ) ;
if ( F_11 ( & V_10 -> V_18 ) == 2 &&
F_155 ( V_442 , & V_10 -> V_342 ) &&
! F_282 ( V_10 ) &&
F_227 ( V_432 , & V_10 -> V_342 ) )
F_67 ( & V_10 -> V_18 ) ;
F_315 ( V_10 ) ;
}
void F_319 ( struct V_9 * V_10 )
{
if ( ! V_10 )
return;
F_66 ( & V_10 -> V_346 ) ;
F_228 ( V_442 , & V_10 -> V_342 ) ;
if ( F_11 ( & V_10 -> V_18 ) == 2 && ! F_282 ( V_10 ) &&
F_227 ( V_432 , & V_10 -> V_342 ) )
F_67 ( & V_10 -> V_18 ) ;
F_315 ( V_10 ) ;
}
void F_320 ( struct V_9 * V_10 )
{
unsigned long V_139 ;
unsigned long V_201 ;
struct V_128 * V_128 ;
V_201 = F_144 ( V_10 -> V_15 , V_10 -> V_21 ) ;
for ( V_139 = 0 ; V_139 < V_201 ; V_139 ++ ) {
V_128 = F_145 ( V_10 , V_139 ) ;
if ( ! F_116 ( V_128 ) )
continue;
F_115 ( V_128 ) ;
F_37 ( ! F_184 ( V_128 ) ) ;
F_100 ( V_128 ) ;
F_321 ( & V_128 -> V_27 -> V_443 ) ;
if ( ! F_116 ( V_128 ) ) {
F_322 ( & V_128 -> V_27 -> V_444 ,
F_323 ( V_128 ) ,
V_364 ) ;
}
F_324 ( & V_128 -> V_27 -> V_443 ) ;
F_219 ( V_128 ) ;
F_113 ( V_128 ) ;
}
F_37 ( F_11 ( & V_10 -> V_18 ) == 0 ) ;
}
int F_325 ( struct V_9 * V_10 )
{
unsigned long V_139 ;
unsigned long V_201 ;
int V_445 = 0 ;
F_297 ( V_10 ) ;
V_445 = F_298 ( V_347 , & V_10 -> V_342 ) ;
V_201 = F_144 ( V_10 -> V_15 , V_10 -> V_21 ) ;
F_37 ( F_11 ( & V_10 -> V_18 ) == 0 ) ;
F_37 ( ! F_155 ( V_432 , & V_10 -> V_342 ) ) ;
for ( V_139 = 0 ; V_139 < V_201 ; V_139 ++ )
F_326 ( F_145 ( V_10 , V_139 ) ) ;
return V_445 ;
}
int F_327 ( struct V_9 * V_10 )
{
unsigned long V_139 ;
struct V_128 * V_128 ;
unsigned long V_201 ;
F_233 ( V_431 , & V_10 -> V_342 ) ;
V_201 = F_144 ( V_10 -> V_15 , V_10 -> V_21 ) ;
for ( V_139 = 0 ; V_139 < V_201 ; V_139 ++ ) {
V_128 = F_145 ( V_10 , V_139 ) ;
if ( V_128 )
F_159 ( V_128 ) ;
}
return 0 ;
}
int F_294 ( struct V_9 * V_10 )
{
unsigned long V_139 ;
struct V_128 * V_128 ;
unsigned long V_201 ;
F_228 ( V_431 , & V_10 -> V_342 ) ;
V_201 = F_144 ( V_10 -> V_15 , V_10 -> V_21 ) ;
for ( V_139 = 0 ; V_139 < V_201 ; V_139 ++ ) {
V_128 = F_145 ( V_10 , V_139 ) ;
F_130 ( V_128 ) ;
}
return 0 ;
}
int F_328 ( struct V_9 * V_10 )
{
return F_155 ( V_431 , & V_10 -> V_342 ) ;
}
int F_329 ( struct V_24 * V_17 ,
struct V_9 * V_10 , T_1 V_15 , int V_109 ,
T_12 * V_284 , int V_172 )
{
unsigned long V_139 ;
unsigned long V_446 ;
struct V_128 * V_128 ;
int V_95 ;
int V_74 = 0 ;
int V_447 = 0 ;
int V_448 = 1 ;
unsigned long V_201 ;
unsigned long V_449 = 0 ;
struct V_40 * V_40 = NULL ;
unsigned long V_220 = 0 ;
if ( F_155 ( V_431 , & V_10 -> V_342 ) )
return 0 ;
if ( V_15 ) {
F_37 ( V_15 < V_10 -> V_15 ) ;
V_446 = ( V_15 >> V_126 ) -
( V_10 -> V_15 >> V_126 ) ;
} else {
V_446 = 0 ;
}
V_201 = F_144 ( V_10 -> V_15 , V_10 -> V_21 ) ;
for ( V_139 = V_446 ; V_139 < V_201 ; V_139 ++ ) {
V_128 = F_145 ( V_10 , V_139 ) ;
if ( V_109 == V_450 ) {
if ( ! F_231 ( V_128 ) )
goto V_451;
} else {
F_115 ( V_128 ) ;
}
V_447 ++ ;
if ( ! F_194 ( V_128 ) ) {
V_449 ++ ;
V_448 = 0 ;
}
}
if ( V_448 ) {
if ( V_446 == 0 )
F_228 ( V_431 , & V_10 -> V_342 ) ;
goto V_451;
}
F_233 ( V_352 , & V_10 -> V_342 ) ;
V_10 -> V_452 = 0 ;
F_32 ( & V_10 -> V_351 , V_449 ) ;
for ( V_139 = V_446 ; V_139 < V_201 ; V_139 ++ ) {
V_128 = F_145 ( V_10 , V_139 ) ;
if ( ! F_194 ( V_128 ) ) {
F_219 ( V_128 ) ;
V_95 = F_206 ( V_17 , V_128 ,
V_284 , & V_40 ,
V_172 , & V_220 ,
V_309 | V_354 ) ;
if ( V_95 )
V_74 = V_95 ;
} else {
F_113 ( V_128 ) ;
}
}
if ( V_40 ) {
V_95 = F_175 ( V_309 | V_354 , V_40 , V_172 ,
V_220 ) ;
if ( V_95 )
return V_95 ;
}
if ( V_74 || V_109 != V_453 )
return V_74 ;
for ( V_139 = V_446 ; V_139 < V_201 ; V_139 ++ ) {
V_128 = F_145 ( V_10 , V_139 ) ;
F_330 ( V_128 ) ;
if ( ! F_194 ( V_128 ) )
V_74 = - V_185 ;
}
return V_74 ;
V_451:
V_139 = V_446 ;
while ( V_447 > 0 ) {
V_128 = F_145 ( V_10 , V_139 ) ;
V_139 ++ ;
F_113 ( V_128 ) ;
V_447 -- ;
}
return V_74 ;
}
void F_331 ( struct V_9 * V_10 , void * V_454 ,
unsigned long V_15 ,
unsigned long V_21 )
{
T_9 V_287 ;
T_9 V_56 ;
struct V_128 * V_128 ;
char * V_455 ;
char * V_456 = ( char * ) V_454 ;
T_9 V_457 = V_10 -> V_15 & ( ( T_1 ) V_148 - 1 ) ;
unsigned long V_139 = ( V_457 + V_15 ) >> V_126 ;
F_37 ( V_15 > V_10 -> V_21 ) ;
F_37 ( V_15 + V_21 > V_10 -> V_15 + V_10 -> V_21 ) ;
V_56 = ( V_457 + V_15 ) & ( V_148 - 1 ) ;
while ( V_21 > 0 ) {
V_128 = F_145 ( V_10 , V_139 ) ;
V_287 = F_124 ( V_21 , ( V_148 - V_56 ) ) ;
V_455 = F_332 ( V_128 ) ;
memcpy ( V_456 , V_455 + V_56 , V_287 ) ;
V_456 += V_287 ;
V_21 -= V_287 ;
V_56 = 0 ;
V_139 ++ ;
}
}
int F_333 ( struct V_9 * V_10 , void T_17 * V_454 ,
unsigned long V_15 ,
unsigned long V_21 )
{
T_9 V_287 ;
T_9 V_56 ;
struct V_128 * V_128 ;
char * V_455 ;
char T_17 * V_456 = ( char T_17 * ) V_454 ;
T_9 V_457 = V_10 -> V_15 & ( ( T_1 ) V_148 - 1 ) ;
unsigned long V_139 = ( V_457 + V_15 ) >> V_126 ;
int V_74 = 0 ;
F_37 ( V_15 > V_10 -> V_21 ) ;
F_37 ( V_15 + V_21 > V_10 -> V_15 + V_10 -> V_21 ) ;
V_56 = ( V_457 + V_15 ) & ( V_148 - 1 ) ;
while ( V_21 > 0 ) {
V_128 = F_145 ( V_10 , V_139 ) ;
V_287 = F_124 ( V_21 , ( V_148 - V_56 ) ) ;
V_455 = F_332 ( V_128 ) ;
if ( F_334 ( V_456 , V_455 + V_56 , V_287 ) ) {
V_74 = - V_458 ;
break;
}
V_456 += V_287 ;
V_21 -= V_287 ;
V_56 = 0 ;
V_139 ++ ;
}
return V_74 ;
}
int F_335 ( struct V_9 * V_10 , unsigned long V_15 ,
unsigned long V_459 , char * * V_376 ,
unsigned long * V_460 ,
unsigned long * V_461 )
{
T_9 V_56 = V_15 & ( V_148 - 1 ) ;
char * V_455 ;
struct V_128 * V_60 ;
T_9 V_457 = V_10 -> V_15 & ( ( T_1 ) V_148 - 1 ) ;
unsigned long V_139 = ( V_457 + V_15 ) >> V_126 ;
unsigned long V_462 = ( V_457 + V_15 + V_459 - 1 ) >>
V_126 ;
if ( V_139 != V_462 )
return - V_398 ;
if ( V_139 == 0 ) {
V_56 = V_457 ;
* V_460 = 0 ;
} else {
V_56 = 0 ;
* V_460 = ( ( T_1 ) V_139 << V_126 ) - V_457 ;
}
if ( V_15 + V_459 > V_10 -> V_21 ) {
F_54 ( 1 , V_14 L_33
L_34 ,
V_10 -> V_15 , V_10 -> V_21 , V_15 , V_459 ) ;
return - V_398 ;
}
V_60 = F_145 ( V_10 , V_139 ) ;
V_455 = F_332 ( V_60 ) ;
* V_376 = V_455 + V_56 ;
* V_461 = V_148 - V_56 ;
return 0 ;
}
int F_336 ( struct V_9 * V_10 , const void * V_463 ,
unsigned long V_15 ,
unsigned long V_21 )
{
T_9 V_287 ;
T_9 V_56 ;
struct V_128 * V_128 ;
char * V_455 ;
char * V_464 = ( char * ) V_463 ;
T_9 V_457 = V_10 -> V_15 & ( ( T_1 ) V_148 - 1 ) ;
unsigned long V_139 = ( V_457 + V_15 ) >> V_126 ;
int V_74 = 0 ;
F_37 ( V_15 > V_10 -> V_21 ) ;
F_37 ( V_15 + V_21 > V_10 -> V_15 + V_10 -> V_21 ) ;
V_56 = ( V_457 + V_15 ) & ( V_148 - 1 ) ;
while ( V_21 > 0 ) {
V_128 = F_145 ( V_10 , V_139 ) ;
V_287 = F_124 ( V_21 , ( V_148 - V_56 ) ) ;
V_455 = F_332 ( V_128 ) ;
V_74 = memcmp ( V_464 , V_455 + V_56 , V_287 ) ;
if ( V_74 )
break;
V_464 += V_287 ;
V_21 -= V_287 ;
V_56 = 0 ;
V_139 ++ ;
}
return V_74 ;
}
void F_337 ( struct V_9 * V_10 , const void * V_465 ,
unsigned long V_15 , unsigned long V_21 )
{
T_9 V_287 ;
T_9 V_56 ;
struct V_128 * V_128 ;
char * V_455 ;
char * V_430 = ( char * ) V_465 ;
T_9 V_457 = V_10 -> V_15 & ( ( T_1 ) V_148 - 1 ) ;
unsigned long V_139 = ( V_457 + V_15 ) >> V_126 ;
F_37 ( V_15 > V_10 -> V_21 ) ;
F_37 ( V_15 + V_21 > V_10 -> V_15 + V_10 -> V_21 ) ;
V_56 = ( V_457 + V_15 ) & ( V_148 - 1 ) ;
while ( V_21 > 0 ) {
V_128 = F_145 ( V_10 , V_139 ) ;
F_37 ( ! F_194 ( V_128 ) ) ;
V_287 = F_124 ( V_21 , V_148 - V_56 ) ;
V_455 = F_332 ( V_128 ) ;
memcpy ( V_455 + V_56 , V_430 , V_287 ) ;
V_430 += V_287 ;
V_21 -= V_287 ;
V_56 = 0 ;
V_139 ++ ;
}
}
void F_338 ( struct V_9 * V_10 , char V_466 ,
unsigned long V_15 , unsigned long V_21 )
{
T_9 V_287 ;
T_9 V_56 ;
struct V_128 * V_128 ;
char * V_455 ;
T_9 V_457 = V_10 -> V_15 & ( ( T_1 ) V_148 - 1 ) ;
unsigned long V_139 = ( V_457 + V_15 ) >> V_126 ;
F_37 ( V_15 > V_10 -> V_21 ) ;
F_37 ( V_15 + V_21 > V_10 -> V_15 + V_10 -> V_21 ) ;
V_56 = ( V_457 + V_15 ) & ( V_148 - 1 ) ;
while ( V_21 > 0 ) {
V_128 = F_145 ( V_10 , V_139 ) ;
F_37 ( ! F_194 ( V_128 ) ) ;
V_287 = F_124 ( V_21 , V_148 - V_56 ) ;
V_455 = F_332 ( V_128 ) ;
memset ( V_455 + V_56 , V_466 , V_287 ) ;
V_21 -= V_287 ;
V_56 = 0 ;
V_139 ++ ;
}
}
void F_292 ( struct V_9 * V_456 , struct V_9 * V_430 ,
unsigned long V_467 , unsigned long V_468 ,
unsigned long V_21 )
{
T_1 V_469 = V_456 -> V_21 ;
T_9 V_287 ;
T_9 V_56 ;
struct V_128 * V_128 ;
char * V_455 ;
T_9 V_457 = V_456 -> V_15 & ( ( T_1 ) V_148 - 1 ) ;
unsigned long V_139 = ( V_457 + V_467 ) >> V_126 ;
F_37 ( V_430 -> V_21 != V_469 ) ;
V_56 = ( V_457 + V_467 ) &
( V_148 - 1 ) ;
while ( V_21 > 0 ) {
V_128 = F_145 ( V_456 , V_139 ) ;
F_37 ( ! F_194 ( V_128 ) ) ;
V_287 = F_124 ( V_21 , ( unsigned long ) ( V_148 - V_56 ) ) ;
V_455 = F_332 ( V_128 ) ;
F_331 ( V_430 , V_455 + V_56 , V_468 , V_287 ) ;
V_468 += V_287 ;
V_21 -= V_287 ;
V_56 = 0 ;
V_139 ++ ;
}
}
static inline bool F_339 ( unsigned long V_430 , unsigned long V_456 , unsigned long V_21 )
{
unsigned long V_470 = ( V_430 > V_456 ) ? V_430 - V_456 : V_456 - V_430 ;
return V_470 < V_21 ;
}
static void F_340 ( struct V_128 * V_471 , struct V_128 * V_472 ,
unsigned long V_473 , unsigned long V_474 ,
unsigned long V_21 )
{
char * V_475 = F_332 ( V_471 ) ;
char * V_476 ;
int V_477 = 0 ;
if ( V_471 != V_472 ) {
V_476 = F_332 ( V_472 ) ;
} else {
V_476 = V_475 ;
if ( F_339 ( V_474 , V_473 , V_21 ) )
V_477 = 1 ;
}
if ( V_477 )
memmove ( V_475 + V_473 , V_476 + V_474 , V_21 ) ;
else
memcpy ( V_475 + V_473 , V_476 + V_474 , V_21 ) ;
}
void F_341 ( struct V_9 * V_456 , unsigned long V_467 ,
unsigned long V_468 , unsigned long V_21 )
{
T_9 V_287 ;
T_9 V_478 ;
T_9 V_479 ;
T_9 V_457 = V_456 -> V_15 & ( ( T_1 ) V_148 - 1 ) ;
unsigned long V_480 ;
unsigned long V_481 ;
if ( V_468 + V_21 > V_456 -> V_21 ) {
F_10 ( V_14 L_35
L_36 , V_468 , V_21 , V_456 -> V_21 ) ;
F_68 ( 1 ) ;
}
if ( V_467 + V_21 > V_456 -> V_21 ) {
F_10 ( V_14 L_37
L_36 , V_467 , V_21 , V_456 -> V_21 ) ;
F_68 ( 1 ) ;
}
while ( V_21 > 0 ) {
V_478 = ( V_457 + V_467 ) &
( V_148 - 1 ) ;
V_479 = ( V_457 + V_468 ) &
( V_148 - 1 ) ;
V_480 = ( V_457 + V_467 ) >> V_126 ;
V_481 = ( V_457 + V_468 ) >> V_126 ;
V_287 = F_124 ( V_21 , ( unsigned long ) ( V_148 -
V_479 ) ) ;
V_287 = F_112 (unsigned long, cur,
(unsigned long)(PAGE_CACHE_SIZE - dst_off_in_page)) ;
F_340 ( F_145 ( V_456 , V_480 ) ,
F_145 ( V_456 , V_481 ) ,
V_478 , V_479 , V_287 ) ;
V_468 += V_287 ;
V_467 += V_287 ;
V_21 -= V_287 ;
}
}
void F_342 ( struct V_9 * V_456 , unsigned long V_467 ,
unsigned long V_468 , unsigned long V_21 )
{
T_9 V_287 ;
T_9 V_478 ;
T_9 V_479 ;
unsigned long V_482 = V_467 + V_21 - 1 ;
unsigned long V_483 = V_468 + V_21 - 1 ;
T_9 V_457 = V_456 -> V_15 & ( ( T_1 ) V_148 - 1 ) ;
unsigned long V_480 ;
unsigned long V_481 ;
if ( V_468 + V_21 > V_456 -> V_21 ) {
F_10 ( V_14 L_35
L_38 , V_468 , V_21 , V_456 -> V_21 ) ;
F_68 ( 1 ) ;
}
if ( V_467 + V_21 > V_456 -> V_21 ) {
F_10 ( V_14 L_37
L_38 , V_467 , V_21 , V_456 -> V_21 ) ;
F_68 ( 1 ) ;
}
if ( V_467 < V_468 ) {
F_341 ( V_456 , V_467 , V_468 , V_21 ) ;
return;
}
while ( V_21 > 0 ) {
V_480 = ( V_457 + V_482 ) >> V_126 ;
V_481 = ( V_457 + V_483 ) >> V_126 ;
V_478 = ( V_457 + V_482 ) &
( V_148 - 1 ) ;
V_479 = ( V_457 + V_483 ) &
( V_148 - 1 ) ;
V_287 = F_112 (unsigned long, len, src_off_in_page + 1 ) ;
V_287 = F_124 ( V_287 , V_478 + 1 ) ;
F_340 ( F_145 ( V_456 , V_480 ) ,
F_145 ( V_456 , V_481 ) ,
V_478 - V_287 + 1 ,
V_479 - V_287 + 1 , V_287 ) ;
V_482 -= V_287 ;
V_483 -= V_287 ;
V_21 -= V_287 ;
}
}
int F_343 ( struct V_128 * V_128 )
{
struct V_9 * V_10 ;
F_66 ( & V_128 -> V_27 -> V_367 ) ;
if ( ! F_184 ( V_128 ) ) {
F_70 ( & V_128 -> V_27 -> V_367 ) ;
return 1 ;
}
V_10 = (struct V_9 * ) V_128 -> V_49 ;
F_68 ( ! V_10 ) ;
F_66 ( & V_10 -> V_346 ) ;
if ( F_11 ( & V_10 -> V_18 ) != 1 || F_282 ( V_10 ) ) {
F_70 ( & V_10 -> V_346 ) ;
F_70 ( & V_128 -> V_27 -> V_367 ) ;
return 0 ;
}
F_70 ( & V_128 -> V_27 -> V_367 ) ;
if ( ! F_227 ( V_432 , & V_10 -> V_342 ) ) {
F_70 ( & V_10 -> V_346 ) ;
return 0 ;
}
return F_315 ( V_10 ) ;
}
