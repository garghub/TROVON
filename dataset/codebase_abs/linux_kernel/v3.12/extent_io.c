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
struct V_24 * V_24 , T_1 V_15 , T_1 V_16 )
{
T_1 V_25 = F_14 ( V_24 ) ;
if ( V_16 >= V_26 && ( V_16 % 2 ) == 0 && V_16 != V_25 - 1 ) {
F_15 ( V_27
L_5 ,
V_23 , F_16 ( V_24 ) , V_25 , V_15 , V_16 ) ;
}
}
static inline struct V_28 *
F_17 ( struct V_29 * V_17 )
{
return F_18 ( V_17 -> V_30 -> V_31 -> V_32 ) ;
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
void F_28 ( struct V_29 * V_17 ,
struct V_43 * V_30 )
{
V_17 -> V_8 = V_44 ;
F_29 ( & V_17 -> V_45 , V_46 ) ;
V_17 -> V_47 = NULL ;
V_17 -> V_48 = 0 ;
F_30 ( & V_17 -> V_49 ) ;
F_30 ( & V_17 -> V_50 ) ;
V_17 -> V_30 = V_30 ;
}
static struct V_7 * F_31 ( T_3 V_51 )
{
struct V_7 * V_8 ;
V_8 = F_32 ( V_19 , V_51 ) ;
if ( ! V_8 )
return V_8 ;
V_8 -> V_8 = 0 ;
V_8 -> V_52 = 0 ;
V_8 -> V_17 = NULL ;
F_1 ( & V_8 -> V_13 , & V_11 ) ;
F_33 ( & V_8 -> V_18 , 1 ) ;
F_34 ( & V_8 -> V_53 ) ;
F_35 ( V_8 , V_51 , V_54 ) ;
return V_8 ;
}
void F_36 ( struct V_7 * V_8 )
{
if ( ! V_8 )
return;
if ( F_37 ( & V_8 -> V_18 ) ) {
F_38 ( V_8 -> V_17 ) ;
F_5 ( & V_8 -> V_13 ) ;
F_39 ( V_8 , V_54 ) ;
F_12 ( V_19 , V_8 ) ;
}
}
static struct V_55 * F_40 ( struct V_56 * V_57 , T_1 V_58 ,
struct V_55 * V_59 )
{
struct V_55 * * V_60 = & V_57 -> V_55 ;
struct V_55 * V_61 = NULL ;
struct V_62 * V_6 ;
while ( * V_60 ) {
V_61 = * V_60 ;
V_6 = F_41 ( V_61 , struct V_62 , V_55 ) ;
if ( V_58 < V_6 -> V_15 )
V_60 = & ( * V_60 ) -> V_63 ;
else if ( V_58 > V_6 -> V_16 )
V_60 = & ( * V_60 ) -> V_64 ;
else
return V_61 ;
}
F_42 ( V_59 , V_61 , V_60 ) ;
F_43 ( V_59 , V_57 ) ;
return NULL ;
}
static struct V_55 * F_44 ( struct V_29 * V_17 , T_1 V_58 ,
struct V_55 * * V_65 ,
struct V_55 * * V_66 )
{
struct V_56 * V_57 = & V_17 -> V_8 ;
struct V_55 * V_67 = V_57 -> V_55 ;
struct V_55 * V_68 = NULL ;
struct V_55 * V_69 = NULL ;
struct V_62 * V_6 ;
struct V_62 * V_70 = NULL ;
while ( V_67 ) {
V_6 = F_41 ( V_67 , struct V_62 , V_55 ) ;
V_68 = V_67 ;
V_70 = V_6 ;
if ( V_58 < V_6 -> V_15 )
V_67 = V_67 -> V_63 ;
else if ( V_58 > V_6 -> V_16 )
V_67 = V_67 -> V_64 ;
else
return V_67 ;
}
if ( V_65 ) {
V_69 = V_68 ;
while ( V_68 && V_58 > V_70 -> V_16 ) {
V_68 = F_45 ( V_68 ) ;
V_70 = F_41 ( V_68 , struct V_62 , V_55 ) ;
}
* V_65 = V_68 ;
V_68 = V_69 ;
}
if ( V_66 ) {
V_70 = F_41 ( V_68 , struct V_62 , V_55 ) ;
while ( V_68 && V_58 < V_70 -> V_15 ) {
V_68 = F_46 ( V_68 ) ;
V_70 = F_41 ( V_68 , struct V_62 , V_55 ) ;
}
* V_66 = V_68 ;
}
return NULL ;
}
static inline struct V_55 * F_47 ( struct V_29 * V_17 ,
T_1 V_58 )
{
struct V_55 * V_68 = NULL ;
struct V_55 * V_71 ;
V_71 = F_44 ( V_17 , V_58 , & V_68 , NULL ) ;
if ( ! V_71 )
return V_68 ;
return V_71 ;
}
static void F_48 ( struct V_29 * V_17 , struct V_7 * V_2 ,
struct V_7 * V_72 )
{
if ( V_17 -> V_47 && V_17 -> V_47 -> V_73 )
V_17 -> V_47 -> V_73 ( V_17 -> V_30 -> V_31 , V_2 ,
V_72 ) ;
}
static void F_49 ( struct V_29 * V_17 ,
struct V_7 * V_8 )
{
struct V_7 * V_72 ;
struct V_55 * V_74 ;
if ( V_8 -> V_8 & ( V_75 | V_76 ) )
return;
V_74 = F_46 ( & V_8 -> V_55 ) ;
if ( V_74 ) {
V_72 = F_41 ( V_74 , struct V_7 , V_55 ) ;
if ( V_72 -> V_16 == V_8 -> V_15 - 1 &&
V_72 -> V_8 == V_8 -> V_8 ) {
F_48 ( V_17 , V_8 , V_72 ) ;
V_8 -> V_15 = V_72 -> V_15 ;
V_72 -> V_17 = NULL ;
F_50 ( & V_72 -> V_55 , & V_17 -> V_8 ) ;
F_36 ( V_72 ) ;
}
}
V_74 = F_45 ( & V_8 -> V_55 ) ;
if ( V_74 ) {
V_72 = F_41 ( V_74 , struct V_7 , V_55 ) ;
if ( V_72 -> V_15 == V_8 -> V_16 + 1 &&
V_72 -> V_8 == V_8 -> V_8 ) {
F_48 ( V_17 , V_8 , V_72 ) ;
V_8 -> V_16 = V_72 -> V_16 ;
V_72 -> V_17 = NULL ;
F_50 ( & V_72 -> V_55 , & V_17 -> V_8 ) ;
F_36 ( V_72 ) ;
}
}
}
static void F_51 ( struct V_29 * V_17 ,
struct V_7 * V_8 , unsigned long * V_77 )
{
if ( V_17 -> V_47 && V_17 -> V_47 -> V_78 )
V_17 -> V_47 -> V_78 ( V_17 -> V_30 -> V_31 , V_8 , V_77 ) ;
}
static void F_52 ( struct V_29 * V_17 ,
struct V_7 * V_8 , unsigned long * V_77 )
{
if ( V_17 -> V_47 && V_17 -> V_47 -> V_79 )
V_17 -> V_47 -> V_79 ( V_17 -> V_30 -> V_31 , V_8 , V_77 ) ;
}
static int F_53 ( struct V_29 * V_17 ,
struct V_7 * V_8 , T_1 V_15 , T_1 V_16 ,
unsigned long * V_77 )
{
struct V_55 * V_59 ;
if ( V_16 < V_15 )
F_54 ( 1 , V_14 L_8 ,
V_16 , V_15 ) ;
V_8 -> V_15 = V_15 ;
V_8 -> V_16 = V_16 ;
F_55 ( V_17 , V_8 , V_77 ) ;
V_59 = F_40 ( & V_17 -> V_8 , V_16 , & V_8 -> V_55 ) ;
if ( V_59 ) {
struct V_7 * V_80 ;
V_80 = F_41 ( V_59 , struct V_7 , V_55 ) ;
F_10 ( V_14 L_9
L_10 ,
V_80 -> V_15 , V_80 -> V_16 , V_15 , V_16 ) ;
return - V_81 ;
}
V_8 -> V_17 = V_17 ;
F_49 ( V_17 , V_8 ) ;
return 0 ;
}
static void F_56 ( struct V_29 * V_17 , struct V_7 * V_82 ,
T_1 V_83 )
{
if ( V_17 -> V_47 && V_17 -> V_47 -> V_84 )
V_17 -> V_47 -> V_84 ( V_17 -> V_30 -> V_31 , V_82 , V_83 ) ;
}
static int F_57 ( struct V_29 * V_17 , struct V_7 * V_82 ,
struct V_7 * V_85 , T_1 V_83 )
{
struct V_55 * V_59 ;
F_56 ( V_17 , V_82 , V_83 ) ;
V_85 -> V_15 = V_82 -> V_15 ;
V_85 -> V_16 = V_83 - 1 ;
V_85 -> V_8 = V_82 -> V_8 ;
V_82 -> V_15 = V_83 ;
V_59 = F_40 ( & V_17 -> V_8 , V_85 -> V_16 , & V_85 -> V_55 ) ;
if ( V_59 ) {
F_36 ( V_85 ) ;
return - V_81 ;
}
V_85 -> V_17 = V_17 ;
return 0 ;
}
static struct V_7 * F_58 ( struct V_7 * V_8 )
{
struct V_55 * V_12 = F_45 ( & V_8 -> V_55 ) ;
if ( V_12 )
return F_41 ( V_12 , struct V_7 , V_55 ) ;
else
return NULL ;
}
static struct V_7 * F_59 ( struct V_29 * V_17 ,
struct V_7 * V_8 ,
unsigned long * V_77 , int V_86 )
{
struct V_7 * V_12 ;
unsigned long V_87 = * V_77 & ~ V_88 ;
if ( ( V_87 & V_89 ) && ( V_8 -> V_8 & V_89 ) ) {
T_1 V_90 = V_8 -> V_16 - V_8 -> V_15 + 1 ;
F_38 ( V_90 > V_17 -> V_48 ) ;
V_17 -> V_48 -= V_90 ;
}
F_52 ( V_17 , V_8 , V_77 ) ;
V_8 -> V_8 &= ~ V_87 ;
if ( V_86 )
F_60 ( & V_8 -> V_53 ) ;
if ( V_8 -> V_8 == 0 ) {
V_12 = F_58 ( V_8 ) ;
if ( V_8 -> V_17 ) {
F_50 ( & V_8 -> V_55 , & V_17 -> V_8 ) ;
V_8 -> V_17 = NULL ;
F_36 ( V_8 ) ;
} else {
F_38 ( 1 ) ;
}
} else {
F_49 ( V_17 , V_8 ) ;
V_12 = F_58 ( V_8 ) ;
}
return V_12 ;
}
static struct V_7 *
F_61 ( struct V_7 * V_85 )
{
if ( ! V_85 )
V_85 = F_31 ( V_46 ) ;
return V_85 ;
}
static void F_62 ( struct V_29 * V_17 , int V_91 )
{
F_63 ( F_17 ( V_17 ) , V_91 , L_11
L_12
L_13 ) ;
}
int F_64 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_77 , int V_86 , int V_92 ,
struct V_7 * * V_93 ,
T_3 V_51 )
{
struct V_7 * V_8 ;
struct V_7 * V_94 ;
struct V_7 * V_85 = NULL ;
struct V_55 * V_59 ;
T_1 V_95 ;
int V_91 ;
int V_96 = 0 ;
F_65 ( V_17 -> V_30 -> V_31 , V_15 , V_16 ) ;
if ( V_77 & V_97 )
V_77 |= V_98 ;
if ( V_92 )
V_77 |= ~ V_88 ;
V_77 |= V_99 ;
if ( V_77 & ( V_75 | V_76 ) )
V_96 = 1 ;
V_100:
if ( ! V_85 && ( V_51 & V_101 ) ) {
V_85 = F_31 ( V_51 ) ;
if ( ! V_85 )
return - V_35 ;
}
F_66 ( & V_17 -> V_49 ) ;
if ( V_93 ) {
V_94 = * V_93 ;
if ( V_96 ) {
* V_93 = NULL ;
V_93 = NULL ;
}
if ( V_94 && V_94 -> V_17 && V_94 -> V_15 <= V_15 &&
V_94 -> V_16 > V_15 ) {
if ( V_96 )
F_67 ( & V_94 -> V_18 ) ;
V_8 = V_94 ;
goto V_102;
}
if ( V_96 )
F_36 ( V_94 ) ;
}
V_59 = F_47 ( V_17 , V_15 ) ;
if ( ! V_59 )
goto V_103;
V_8 = F_41 ( V_59 , struct V_7 , V_55 ) ;
V_102:
if ( V_8 -> V_15 > V_16 )
goto V_103;
F_38 ( V_8 -> V_16 < V_15 ) ;
V_95 = V_8 -> V_16 ;
if ( ! ( V_8 -> V_8 & V_77 ) ) {
V_8 = F_58 ( V_8 ) ;
goto V_12;
}
if ( V_8 -> V_15 < V_15 ) {
V_85 = F_61 ( V_85 ) ;
F_68 ( ! V_85 ) ;
V_91 = F_57 ( V_17 , V_8 , V_85 , V_15 ) ;
if ( V_91 )
F_62 ( V_17 , V_91 ) ;
V_85 = NULL ;
if ( V_91 )
goto V_103;
if ( V_8 -> V_16 <= V_16 ) {
V_8 = F_59 ( V_17 , V_8 , & V_77 , V_86 ) ;
goto V_12;
}
goto V_104;
}
if ( V_8 -> V_15 <= V_16 && V_8 -> V_16 > V_16 ) {
V_85 = F_61 ( V_85 ) ;
F_68 ( ! V_85 ) ;
V_91 = F_57 ( V_17 , V_8 , V_85 , V_16 + 1 ) ;
if ( V_91 )
F_62 ( V_17 , V_91 ) ;
if ( V_86 )
F_60 ( & V_8 -> V_53 ) ;
F_59 ( V_17 , V_85 , & V_77 , V_86 ) ;
V_85 = NULL ;
goto V_103;
}
V_8 = F_59 ( V_17 , V_8 , & V_77 , V_86 ) ;
V_12:
if ( V_95 == ( T_1 ) - 1 )
goto V_103;
V_15 = V_95 + 1 ;
if ( V_15 <= V_16 && V_8 && ! F_69 () )
goto V_102;
goto V_104;
V_103:
F_70 ( & V_17 -> V_49 ) ;
if ( V_85 )
F_36 ( V_85 ) ;
return 0 ;
V_104:
if ( V_15 > V_16 )
goto V_103;
F_70 ( & V_17 -> V_49 ) ;
if ( V_51 & V_101 )
F_71 () ;
goto V_100;
}
static void F_72 ( struct V_29 * V_17 ,
struct V_7 * V_8 )
__releases( V_17 -> V_49 )
__acquires( V_17 -> V_49 )
{
F_73 ( V_105 ) ;
F_74 ( & V_8 -> V_53 , & V_105 , V_106 ) ;
F_70 ( & V_17 -> V_49 ) ;
F_75 () ;
F_66 ( & V_17 -> V_49 ) ;
F_76 ( & V_8 -> V_53 , & V_105 ) ;
}
static void F_77 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_77 )
{
struct V_7 * V_8 ;
struct V_55 * V_59 ;
F_65 ( V_17 -> V_30 -> V_31 , V_15 , V_16 ) ;
F_66 ( & V_17 -> V_49 ) ;
V_100:
while ( 1 ) {
V_59 = F_47 ( V_17 , V_15 ) ;
if ( ! V_59 )
break;
V_8 = F_41 ( V_59 , struct V_7 , V_55 ) ;
if ( V_8 -> V_15 > V_16 )
goto V_103;
if ( V_8 -> V_8 & V_77 ) {
V_15 = V_8 -> V_15 ;
F_78 ( & V_8 -> V_18 ) ;
F_72 ( V_17 , V_8 ) ;
F_36 ( V_8 ) ;
goto V_100;
}
V_15 = V_8 -> V_16 + 1 ;
if ( V_15 > V_16 )
break;
F_79 ( & V_17 -> V_49 ) ;
}
V_103:
F_70 ( & V_17 -> V_49 ) ;
}
static void F_55 ( struct V_29 * V_17 ,
struct V_7 * V_8 ,
unsigned long * V_77 )
{
unsigned long V_107 = * V_77 & ~ V_88 ;
F_51 ( V_17 , V_8 , V_77 ) ;
if ( ( V_107 & V_89 ) && ! ( V_8 -> V_8 & V_89 ) ) {
T_1 V_90 = V_8 -> V_16 - V_8 -> V_15 + 1 ;
V_17 -> V_48 += V_90 ;
}
V_8 -> V_8 |= V_107 ;
}
static void F_80 ( struct V_7 * V_8 ,
struct V_7 * * V_108 )
{
if ( V_108 && ! ( * V_108 ) ) {
if ( V_8 -> V_8 & ( V_75 | V_76 ) ) {
* V_108 = V_8 ;
F_78 ( & V_8 -> V_18 ) ;
}
}
}
static int T_4
F_81 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_77 , unsigned long V_109 ,
T_1 * V_110 , struct V_7 * * V_93 ,
T_3 V_51 )
{
struct V_7 * V_8 ;
struct V_7 * V_85 = NULL ;
struct V_55 * V_59 ;
int V_91 = 0 ;
T_1 V_111 ;
T_1 V_95 ;
F_65 ( V_17 -> V_30 -> V_31 , V_15 , V_16 ) ;
V_77 |= V_99 ;
V_100:
if ( ! V_85 && ( V_51 & V_101 ) ) {
V_85 = F_31 ( V_51 ) ;
F_68 ( ! V_85 ) ;
}
F_66 ( & V_17 -> V_49 ) ;
if ( V_93 && * V_93 ) {
V_8 = * V_93 ;
if ( V_8 -> V_15 <= V_15 && V_8 -> V_16 > V_15 &&
V_8 -> V_17 ) {
V_59 = & V_8 -> V_55 ;
goto V_102;
}
}
V_59 = F_47 ( V_17 , V_15 ) ;
if ( ! V_59 ) {
V_85 = F_61 ( V_85 ) ;
F_68 ( ! V_85 ) ;
V_91 = F_53 ( V_17 , V_85 , V_15 , V_16 , & V_77 ) ;
if ( V_91 )
F_62 ( V_17 , V_91 ) ;
V_85 = NULL ;
goto V_103;
}
V_8 = F_41 ( V_59 , struct V_7 , V_55 ) ;
V_102:
V_111 = V_8 -> V_15 ;
V_95 = V_8 -> V_16 ;
if ( V_8 -> V_15 == V_15 && V_8 -> V_16 <= V_16 ) {
if ( V_8 -> V_8 & V_109 ) {
* V_110 = V_8 -> V_15 ;
V_91 = - V_81 ;
goto V_103;
}
F_55 ( V_17 , V_8 , & V_77 ) ;
F_80 ( V_8 , V_93 ) ;
F_49 ( V_17 , V_8 ) ;
if ( V_95 == ( T_1 ) - 1 )
goto V_103;
V_15 = V_95 + 1 ;
V_8 = F_58 ( V_8 ) ;
if ( V_15 < V_16 && V_8 && V_8 -> V_15 == V_15 &&
! F_69 () )
goto V_102;
goto V_104;
}
if ( V_8 -> V_15 < V_15 ) {
if ( V_8 -> V_8 & V_109 ) {
* V_110 = V_15 ;
V_91 = - V_81 ;
goto V_103;
}
V_85 = F_61 ( V_85 ) ;
F_68 ( ! V_85 ) ;
V_91 = F_57 ( V_17 , V_8 , V_85 , V_15 ) ;
if ( V_91 )
F_62 ( V_17 , V_91 ) ;
V_85 = NULL ;
if ( V_91 )
goto V_103;
if ( V_8 -> V_16 <= V_16 ) {
F_55 ( V_17 , V_8 , & V_77 ) ;
F_80 ( V_8 , V_93 ) ;
F_49 ( V_17 , V_8 ) ;
if ( V_95 == ( T_1 ) - 1 )
goto V_103;
V_15 = V_95 + 1 ;
V_8 = F_58 ( V_8 ) ;
if ( V_15 < V_16 && V_8 && V_8 -> V_15 == V_15 &&
! F_69 () )
goto V_102;
}
goto V_104;
}
if ( V_8 -> V_15 > V_15 ) {
T_1 V_112 ;
if ( V_16 < V_111 )
V_112 = V_16 ;
else
V_112 = V_111 - 1 ;
V_85 = F_61 ( V_85 ) ;
F_68 ( ! V_85 ) ;
V_91 = F_53 ( V_17 , V_85 , V_15 , V_112 ,
& V_77 ) ;
if ( V_91 )
F_62 ( V_17 , V_91 ) ;
F_80 ( V_85 , V_93 ) ;
V_85 = NULL ;
V_15 = V_112 + 1 ;
goto V_104;
}
if ( V_8 -> V_15 <= V_16 && V_8 -> V_16 > V_16 ) {
if ( V_8 -> V_8 & V_109 ) {
* V_110 = V_15 ;
V_91 = - V_81 ;
goto V_103;
}
V_85 = F_61 ( V_85 ) ;
F_68 ( ! V_85 ) ;
V_91 = F_57 ( V_17 , V_8 , V_85 , V_16 + 1 ) ;
if ( V_91 )
F_62 ( V_17 , V_91 ) ;
F_55 ( V_17 , V_85 , & V_77 ) ;
F_80 ( V_85 , V_93 ) ;
F_49 ( V_17 , V_85 ) ;
V_85 = NULL ;
goto V_103;
}
goto V_104;
V_103:
F_70 ( & V_17 -> V_49 ) ;
if ( V_85 )
F_36 ( V_85 ) ;
return V_91 ;
V_104:
if ( V_15 > V_16 )
goto V_103;
F_70 ( & V_17 -> V_49 ) ;
if ( V_51 & V_101 )
F_71 () ;
goto V_100;
}
int F_82 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_77 , T_1 * V_110 ,
struct V_7 * * V_93 , T_3 V_51 )
{
return F_81 ( V_17 , V_15 , V_16 , V_77 , 0 , V_110 ,
V_93 , V_51 ) ;
}
int F_83 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_77 , unsigned long V_113 ,
struct V_7 * * V_93 , T_3 V_51 )
{
struct V_7 * V_8 ;
struct V_7 * V_85 = NULL ;
struct V_55 * V_59 ;
int V_91 = 0 ;
T_1 V_111 ;
T_1 V_95 ;
F_65 ( V_17 -> V_30 -> V_31 , V_15 , V_16 ) ;
V_100:
if ( ! V_85 && ( V_51 & V_101 ) ) {
V_85 = F_31 ( V_51 ) ;
if ( ! V_85 )
return - V_35 ;
}
F_66 ( & V_17 -> V_49 ) ;
if ( V_93 && * V_93 ) {
V_8 = * V_93 ;
if ( V_8 -> V_15 <= V_15 && V_8 -> V_16 > V_15 &&
V_8 -> V_17 ) {
V_59 = & V_8 -> V_55 ;
goto V_102;
}
}
V_59 = F_47 ( V_17 , V_15 ) ;
if ( ! V_59 ) {
V_85 = F_61 ( V_85 ) ;
if ( ! V_85 ) {
V_91 = - V_35 ;
goto V_103;
}
V_91 = F_53 ( V_17 , V_85 , V_15 , V_16 , & V_77 ) ;
V_85 = NULL ;
if ( V_91 )
F_62 ( V_17 , V_91 ) ;
goto V_103;
}
V_8 = F_41 ( V_59 , struct V_7 , V_55 ) ;
V_102:
V_111 = V_8 -> V_15 ;
V_95 = V_8 -> V_16 ;
if ( V_8 -> V_15 == V_15 && V_8 -> V_16 <= V_16 ) {
F_55 ( V_17 , V_8 , & V_77 ) ;
F_80 ( V_8 , V_93 ) ;
V_8 = F_59 ( V_17 , V_8 , & V_113 , 0 ) ;
if ( V_95 == ( T_1 ) - 1 )
goto V_103;
V_15 = V_95 + 1 ;
if ( V_15 < V_16 && V_8 && V_8 -> V_15 == V_15 &&
! F_69 () )
goto V_102;
goto V_104;
}
if ( V_8 -> V_15 < V_15 ) {
V_85 = F_61 ( V_85 ) ;
if ( ! V_85 ) {
V_91 = - V_35 ;
goto V_103;
}
V_91 = F_57 ( V_17 , V_8 , V_85 , V_15 ) ;
if ( V_91 )
F_62 ( V_17 , V_91 ) ;
V_85 = NULL ;
if ( V_91 )
goto V_103;
if ( V_8 -> V_16 <= V_16 ) {
F_55 ( V_17 , V_8 , & V_77 ) ;
F_80 ( V_8 , V_93 ) ;
V_8 = F_59 ( V_17 , V_8 , & V_113 , 0 ) ;
if ( V_95 == ( T_1 ) - 1 )
goto V_103;
V_15 = V_95 + 1 ;
if ( V_15 < V_16 && V_8 && V_8 -> V_15 == V_15 &&
! F_69 () )
goto V_102;
}
goto V_104;
}
if ( V_8 -> V_15 > V_15 ) {
T_1 V_112 ;
if ( V_16 < V_111 )
V_112 = V_16 ;
else
V_112 = V_111 - 1 ;
V_85 = F_61 ( V_85 ) ;
if ( ! V_85 ) {
V_91 = - V_35 ;
goto V_103;
}
V_91 = F_53 ( V_17 , V_85 , V_15 , V_112 ,
& V_77 ) ;
if ( V_91 )
F_62 ( V_17 , V_91 ) ;
F_80 ( V_85 , V_93 ) ;
V_85 = NULL ;
V_15 = V_112 + 1 ;
goto V_104;
}
if ( V_8 -> V_15 <= V_16 && V_8 -> V_16 > V_16 ) {
V_85 = F_61 ( V_85 ) ;
if ( ! V_85 ) {
V_91 = - V_35 ;
goto V_103;
}
V_91 = F_57 ( V_17 , V_8 , V_85 , V_16 + 1 ) ;
if ( V_91 )
F_62 ( V_17 , V_91 ) ;
F_55 ( V_17 , V_85 , & V_77 ) ;
F_80 ( V_85 , V_93 ) ;
F_59 ( V_17 , V_85 , & V_113 , 0 ) ;
V_85 = NULL ;
goto V_103;
}
goto V_104;
V_103:
F_70 ( & V_17 -> V_49 ) ;
if ( V_85 )
F_36 ( V_85 ) ;
return V_91 ;
V_104:
if ( V_15 > V_16 )
goto V_103;
F_70 ( & V_17 -> V_49 ) ;
if ( V_51 & V_101 )
F_71 () ;
goto V_100;
}
int F_84 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
T_3 V_51 )
{
return F_82 ( V_17 , V_15 , V_16 , V_89 , NULL ,
NULL , V_51 ) ;
}
int F_85 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_77 , T_3 V_51 )
{
return F_82 ( V_17 , V_15 , V_16 , V_77 , NULL ,
NULL , V_51 ) ;
}
int F_86 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_77 , T_3 V_51 )
{
return F_64 ( V_17 , V_15 , V_16 , V_77 , 0 , 0 , NULL , V_51 ) ;
}
int F_87 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
struct V_7 * * V_93 , T_3 V_51 )
{
return F_82 ( V_17 , V_15 , V_16 ,
V_97 | V_114 ,
NULL , V_93 , V_51 ) ;
}
int F_88 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
struct V_7 * * V_93 , T_3 V_51 )
{
return F_82 ( V_17 , V_15 , V_16 ,
V_97 | V_114 | V_115 ,
NULL , V_93 , V_51 ) ;
}
int F_89 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
T_3 V_51 )
{
return F_64 ( V_17 , V_15 , V_16 ,
V_89 | V_97 |
V_116 , 0 , 0 , NULL , V_51 ) ;
}
int F_90 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
T_3 V_51 )
{
return F_82 ( V_17 , V_15 , V_16 , V_117 , NULL ,
NULL , V_51 ) ;
}
int F_91 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
struct V_7 * * V_93 , T_3 V_51 )
{
return F_82 ( V_17 , V_15 , V_16 , V_114 , NULL ,
V_93 , V_51 ) ;
}
int F_92 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
struct V_7 * * V_93 , T_3 V_51 )
{
return F_64 ( V_17 , V_15 , V_16 , V_114 , 0 , 0 ,
V_93 , V_51 ) ;
}
int F_93 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_77 , struct V_7 * * V_93 )
{
int V_91 ;
T_1 V_110 ;
while ( 1 ) {
V_91 = F_81 ( V_17 , V_15 , V_16 , V_118 | V_77 ,
V_118 , & V_110 ,
V_93 , V_119 ) ;
if ( V_91 == - V_81 ) {
F_77 ( V_17 , V_110 , V_16 , V_118 ) ;
V_15 = V_110 ;
} else
break;
F_38 ( V_15 > V_16 ) ;
}
return V_91 ;
}
int F_94 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 )
{
return F_93 ( V_17 , V_15 , V_16 , 0 , NULL ) ;
}
int F_95 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 )
{
int V_91 ;
T_1 V_110 ;
V_91 = F_81 ( V_17 , V_15 , V_16 , V_118 , V_118 ,
& V_110 , NULL , V_119 ) ;
if ( V_91 == - V_81 ) {
if ( V_110 > V_15 )
F_64 ( V_17 , V_15 , V_110 - 1 ,
V_118 , 1 , 0 , NULL , V_119 ) ;
return 0 ;
}
return 1 ;
}
int F_96 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
struct V_7 * * V_94 , T_3 V_51 )
{
return F_64 ( V_17 , V_15 , V_16 , V_118 , 1 , 0 , V_94 ,
V_51 ) ;
}
int F_97 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 )
{
return F_64 ( V_17 , V_15 , V_16 , V_118 , 1 , 0 , NULL ,
V_119 ) ;
}
int F_98 ( struct V_24 * V_24 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_120 = V_15 >> V_121 ;
unsigned long V_122 = V_16 >> V_121 ;
struct V_123 * V_123 ;
while ( V_120 <= V_122 ) {
V_123 = F_99 ( V_24 -> V_124 , V_120 ) ;
F_68 ( ! V_123 ) ;
F_100 ( V_123 ) ;
F_101 ( V_123 ) ;
V_120 ++ ;
}
return 0 ;
}
int F_102 ( struct V_24 * V_24 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_120 = V_15 >> V_121 ;
unsigned long V_122 = V_16 >> V_121 ;
struct V_123 * V_123 ;
while ( V_120 <= V_122 ) {
V_123 = F_99 ( V_24 -> V_124 , V_120 ) ;
F_68 ( ! V_123 ) ;
F_103 ( V_123 ) ;
F_104 ( V_123 ) ;
F_101 ( V_123 ) ;
V_120 ++ ;
}
return 0 ;
}
static int F_105 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_120 = V_15 >> V_121 ;
unsigned long V_122 = V_16 >> V_121 ;
struct V_123 * V_123 ;
while ( V_120 <= V_122 ) {
V_123 = F_99 ( V_17 -> V_30 , V_120 ) ;
F_68 ( ! V_123 ) ;
F_106 ( V_123 ) ;
F_101 ( V_123 ) ;
V_120 ++ ;
}
return 0 ;
}
static struct V_7 *
F_107 ( struct V_29 * V_17 ,
T_1 V_15 , unsigned long V_77 )
{
struct V_55 * V_59 ;
struct V_7 * V_8 ;
V_59 = F_47 ( V_17 , V_15 ) ;
if ( ! V_59 )
goto V_103;
while ( 1 ) {
V_8 = F_41 ( V_59 , struct V_7 , V_55 ) ;
if ( V_8 -> V_16 >= V_15 && ( V_8 -> V_8 & V_77 ) )
return V_8 ;
V_59 = F_45 ( V_59 ) ;
if ( ! V_59 )
break;
}
V_103:
return NULL ;
}
int F_108 ( struct V_29 * V_17 , T_1 V_15 ,
T_1 * V_125 , T_1 * V_126 , unsigned long V_77 ,
struct V_7 * * V_93 )
{
struct V_7 * V_8 ;
struct V_55 * V_67 ;
int V_71 = 1 ;
F_66 ( & V_17 -> V_49 ) ;
if ( V_93 && * V_93 ) {
V_8 = * V_93 ;
if ( V_8 -> V_16 == V_15 - 1 && V_8 -> V_17 ) {
V_67 = F_45 ( & V_8 -> V_55 ) ;
while ( V_67 ) {
V_8 = F_41 ( V_67 , struct V_7 ,
V_55 ) ;
if ( V_8 -> V_8 & V_77 )
goto V_127;
V_67 = F_45 ( V_67 ) ;
}
F_36 ( * V_93 ) ;
* V_93 = NULL ;
goto V_103;
}
F_36 ( * V_93 ) ;
* V_93 = NULL ;
}
V_8 = F_107 ( V_17 , V_15 , V_77 ) ;
V_127:
if ( V_8 ) {
F_80 ( V_8 , V_93 ) ;
* V_125 = V_8 -> V_15 ;
* V_126 = V_8 -> V_16 ;
V_71 = 0 ;
}
V_103:
F_70 ( & V_17 -> V_49 ) ;
return V_71 ;
}
static T_5 T_1 F_109 ( struct V_29 * V_17 ,
T_1 * V_15 , T_1 * V_16 , T_1 V_128 ,
struct V_7 * * V_93 )
{
struct V_55 * V_59 ;
struct V_7 * V_8 ;
T_1 V_129 = * V_15 ;
T_1 V_80 = 0 ;
T_1 V_130 = 0 ;
F_66 ( & V_17 -> V_49 ) ;
V_59 = F_47 ( V_17 , V_129 ) ;
if ( ! V_59 ) {
if ( ! V_80 )
* V_16 = ( T_1 ) - 1 ;
goto V_103;
}
while ( 1 ) {
V_8 = F_41 ( V_59 , struct V_7 , V_55 ) ;
if ( V_80 && ( V_8 -> V_15 != V_129 ||
( V_8 -> V_8 & V_76 ) ) ) {
goto V_103;
}
if ( ! ( V_8 -> V_8 & V_97 ) ) {
if ( ! V_80 )
* V_16 = V_8 -> V_16 ;
goto V_103;
}
if ( ! V_80 ) {
* V_15 = V_8 -> V_15 ;
* V_93 = V_8 ;
F_78 ( & V_8 -> V_18 ) ;
}
V_80 ++ ;
* V_16 = V_8 -> V_16 ;
V_129 = V_8 -> V_16 + 1 ;
V_59 = F_45 ( V_59 ) ;
V_130 += V_8 -> V_16 - V_8 -> V_15 + 1 ;
if ( V_130 >= V_128 )
break;
if ( ! V_59 )
break;
}
V_103:
F_70 ( & V_17 -> V_49 ) ;
return V_80 ;
}
static T_5 void F_110 ( struct V_24 * V_24 ,
struct V_123 * V_131 ,
T_1 V_15 , T_1 V_16 )
{
int V_71 ;
struct V_123 * V_132 [ 16 ] ;
unsigned long V_120 = V_15 >> V_121 ;
unsigned long V_122 = V_16 >> V_121 ;
unsigned long V_133 = V_122 - V_120 + 1 ;
int V_134 ;
if ( V_120 == V_131 -> V_120 && V_122 == V_120 )
return;
while ( V_133 > 0 ) {
V_71 = F_111 ( V_24 -> V_124 , V_120 ,
F_112 (unsigned long, nr_pages,
ARRAY_SIZE(pages)) , V_132 ) ;
for ( V_134 = 0 ; V_134 < V_71 ; V_134 ++ ) {
if ( V_132 [ V_134 ] != V_131 )
F_113 ( V_132 [ V_134 ] ) ;
F_101 ( V_132 [ V_134 ] ) ;
}
V_133 -= V_71 ;
V_120 += V_71 ;
F_71 () ;
}
}
static T_5 int F_114 ( struct V_24 * V_24 ,
struct V_123 * V_131 ,
T_1 V_135 ,
T_1 V_136 )
{
unsigned long V_120 = V_135 >> V_121 ;
unsigned long V_137 = V_120 ;
unsigned long V_122 = V_136 >> V_121 ;
unsigned long V_138 = 0 ;
struct V_123 * V_132 [ 16 ] ;
unsigned long V_139 ;
int V_71 ;
int V_134 ;
if ( V_120 == V_131 -> V_120 && V_120 == V_122 )
return 0 ;
V_139 = V_122 - V_120 + 1 ;
while ( V_139 > 0 ) {
V_71 = F_111 ( V_24 -> V_124 , V_120 ,
F_112 (unsigned long,
nrpages, ARRAY_SIZE(pages)) , V_132 ) ;
if ( V_71 == 0 ) {
V_71 = - V_140 ;
goto V_141;
}
for ( V_134 = 0 ; V_134 < V_71 ; V_134 ++ ) {
if ( V_132 [ V_134 ] != V_131 ) {
F_115 ( V_132 [ V_134 ] ) ;
if ( ! F_116 ( V_132 [ V_134 ] ) ||
V_132 [ V_134 ] -> V_30 != V_24 -> V_124 ) {
V_71 = - V_140 ;
F_113 ( V_132 [ V_134 ] ) ;
F_101 ( V_132 [ V_134 ] ) ;
goto V_141;
}
}
F_101 ( V_132 [ V_134 ] ) ;
V_138 ++ ;
}
V_139 -= V_71 ;
V_120 += V_71 ;
F_71 () ;
}
V_71 = 0 ;
V_141:
if ( V_71 && V_138 ) {
F_110 ( V_24 , V_131 ,
V_135 ,
( ( T_1 ) ( V_137 + V_138 - 1 ) ) <<
V_121 ) ;
}
return V_71 ;
}
static T_5 T_1 F_117 ( struct V_24 * V_24 ,
struct V_29 * V_17 ,
struct V_123 * V_131 ,
T_1 * V_15 , T_1 * V_16 ,
T_1 V_128 )
{
T_1 V_135 ;
T_1 V_136 ;
T_1 V_80 ;
struct V_7 * V_93 = NULL ;
int V_71 ;
int V_142 = 0 ;
V_100:
V_135 = * V_15 ;
V_136 = 0 ;
V_80 = F_109 ( V_17 , & V_135 , & V_136 ,
V_128 , & V_93 ) ;
if ( ! V_80 || V_136 <= * V_15 ) {
* V_15 = V_135 ;
* V_16 = V_136 ;
F_36 ( V_93 ) ;
return 0 ;
}
if ( V_135 < * V_15 )
V_135 = * V_15 ;
if ( V_136 + 1 - V_135 > V_128 )
V_136 = V_135 + V_128 - 1 ;
V_71 = F_114 ( V_24 , V_131 ,
V_135 , V_136 ) ;
if ( V_71 == - V_140 ) {
F_36 ( V_93 ) ;
if ( ! V_142 ) {
V_128 = V_143 ;
V_142 = 1 ;
goto V_100;
} else {
V_80 = 0 ;
goto V_144;
}
}
F_68 ( V_71 ) ;
F_93 ( V_17 , V_135 , V_136 , 0 , & V_93 ) ;
V_71 = F_118 ( V_17 , V_135 , V_136 ,
V_97 , 1 , V_93 ) ;
if ( ! V_71 ) {
F_96 ( V_17 , V_135 , V_136 ,
& V_93 , V_119 ) ;
F_110 ( V_24 , V_131 ,
V_135 , V_136 ) ;
F_71 () ;
goto V_100;
}
F_36 ( V_93 ) ;
* V_15 = V_135 ;
* V_16 = V_136 ;
V_144:
return V_80 ;
}
int F_119 ( struct V_24 * V_24 , T_1 V_15 , T_1 V_16 ,
struct V_123 * V_131 ,
unsigned long V_113 ,
unsigned long V_145 )
{
struct V_29 * V_17 = & F_120 ( V_24 ) -> V_146 ;
int V_71 ;
struct V_123 * V_132 [ 16 ] ;
unsigned long V_120 = V_15 >> V_121 ;
unsigned long V_122 = V_16 >> V_121 ;
unsigned long V_133 = V_122 - V_120 + 1 ;
int V_134 ;
F_64 ( V_17 , V_15 , V_16 , V_113 , 1 , 0 , NULL , V_119 ) ;
if ( V_145 == 0 )
return 0 ;
while ( V_133 > 0 ) {
V_71 = F_111 ( V_24 -> V_124 , V_120 ,
F_112 (unsigned long,
nr_pages, ARRAY_SIZE(pages)) , V_132 ) ;
for ( V_134 = 0 ; V_134 < V_71 ; V_134 ++ ) {
if ( V_145 & V_147 )
F_121 ( V_132 [ V_134 ] ) ;
if ( V_132 [ V_134 ] == V_131 ) {
F_101 ( V_132 [ V_134 ] ) ;
continue;
}
if ( V_145 & V_148 )
F_100 ( V_132 [ V_134 ] ) ;
if ( V_145 & V_149 )
F_106 ( V_132 [ V_134 ] ) ;
if ( V_145 & V_150 )
F_122 ( V_132 [ V_134 ] ) ;
if ( V_145 & V_151 )
F_113 ( V_132 [ V_134 ] ) ;
F_101 ( V_132 [ V_134 ] ) ;
}
V_133 -= V_71 ;
V_120 += V_71 ;
F_71 () ;
}
return 0 ;
}
T_1 F_123 ( struct V_29 * V_17 ,
T_1 * V_15 , T_1 V_152 , T_1 V_128 ,
unsigned long V_77 , int V_153 )
{
struct V_55 * V_59 ;
struct V_7 * V_8 ;
T_1 V_129 = * V_15 ;
T_1 V_130 = 0 ;
T_1 V_154 = 0 ;
int V_80 = 0 ;
if ( V_152 <= V_129 ) {
F_38 ( 1 ) ;
return 0 ;
}
F_66 ( & V_17 -> V_49 ) ;
if ( V_129 == 0 && V_77 == V_89 ) {
V_130 = V_17 -> V_48 ;
goto V_103;
}
V_59 = F_47 ( V_17 , V_129 ) ;
if ( ! V_59 )
goto V_103;
while ( 1 ) {
V_8 = F_41 ( V_59 , struct V_7 , V_55 ) ;
if ( V_8 -> V_15 > V_152 )
break;
if ( V_153 && V_80 && V_8 -> V_15 > V_154 + 1 )
break;
if ( V_8 -> V_16 >= V_129 && ( V_8 -> V_8 & V_77 ) == V_77 ) {
V_130 += F_124 ( V_152 , V_8 -> V_16 ) + 1 -
F_125 ( V_129 , V_8 -> V_15 ) ;
if ( V_130 >= V_128 )
break;
if ( ! V_80 ) {
* V_15 = F_125 ( V_129 , V_8 -> V_15 ) ;
V_80 = 1 ;
}
V_154 = V_8 -> V_16 ;
} else if ( V_153 && V_80 ) {
break;
}
V_59 = F_45 ( V_59 ) ;
if ( ! V_59 )
break;
}
V_103:
F_70 ( & V_17 -> V_49 ) ;
return V_130 ;
}
static int F_126 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_52 )
{
struct V_55 * V_59 ;
struct V_7 * V_8 ;
int V_71 = 0 ;
F_66 ( & V_17 -> V_49 ) ;
V_59 = F_47 ( V_17 , V_15 ) ;
if ( ! V_59 ) {
V_71 = - V_155 ;
goto V_103;
}
V_8 = F_41 ( V_59 , struct V_7 , V_55 ) ;
if ( V_8 -> V_15 != V_15 ) {
V_71 = - V_155 ;
goto V_103;
}
V_8 -> V_52 = V_52 ;
V_103:
F_70 ( & V_17 -> V_49 ) ;
return V_71 ;
}
int F_127 ( struct V_29 * V_17 , T_1 V_15 , T_1 * V_52 )
{
struct V_55 * V_59 ;
struct V_7 * V_8 ;
int V_71 = 0 ;
F_66 ( & V_17 -> V_49 ) ;
V_59 = F_47 ( V_17 , V_15 ) ;
if ( ! V_59 ) {
V_71 = - V_155 ;
goto V_103;
}
V_8 = F_41 ( V_59 , struct V_7 , V_55 ) ;
if ( V_8 -> V_15 != V_15 ) {
V_71 = - V_155 ;
goto V_103;
}
* V_52 = V_8 -> V_52 ;
V_103:
F_70 ( & V_17 -> V_49 ) ;
return V_71 ;
}
int F_118 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_16 ,
unsigned long V_77 , int V_156 , struct V_7 * V_94 )
{
struct V_7 * V_8 = NULL ;
struct V_55 * V_59 ;
int V_157 = 0 ;
F_66 ( & V_17 -> V_49 ) ;
if ( V_94 && V_94 -> V_17 && V_94 -> V_15 <= V_15 &&
V_94 -> V_16 > V_15 )
V_59 = & V_94 -> V_55 ;
else
V_59 = F_47 ( V_17 , V_15 ) ;
while ( V_59 && V_15 <= V_16 ) {
V_8 = F_41 ( V_59 , struct V_7 , V_55 ) ;
if ( V_156 && V_8 -> V_15 > V_15 ) {
V_157 = 0 ;
break;
}
if ( V_8 -> V_15 > V_16 )
break;
if ( V_8 -> V_8 & V_77 ) {
V_157 = 1 ;
if ( ! V_156 )
break;
} else if ( V_156 ) {
V_157 = 0 ;
break;
}
if ( V_8 -> V_16 == ( T_1 ) - 1 )
break;
V_15 = V_8 -> V_16 + 1 ;
if ( V_15 > V_16 )
break;
V_59 = F_45 ( V_59 ) ;
if ( ! V_59 ) {
if ( V_156 )
V_157 = 0 ;
break;
}
}
F_70 ( & V_17 -> V_49 ) ;
return V_157 ;
}
static void F_128 ( struct V_29 * V_17 , struct V_123 * V_123 )
{
T_1 V_15 = F_129 ( V_123 ) ;
T_1 V_16 = V_15 + V_143 - 1 ;
if ( F_118 ( V_17 , V_15 , V_16 , V_114 , 1 , NULL ) )
F_130 ( V_123 ) ;
}
static int F_131 ( struct V_24 * V_24 , struct V_158 * V_159 ,
int V_160 )
{
int V_71 ;
int V_91 = 0 ;
struct V_29 * V_161 = & F_120 ( V_24 ) -> V_162 ;
F_126 ( V_161 , V_159 -> V_15 , 0 ) ;
V_71 = F_86 ( V_161 , V_159 -> V_15 ,
V_159 -> V_15 + V_159 -> V_21 - 1 ,
V_118 | V_89 , V_119 ) ;
if ( V_71 )
V_91 = V_71 ;
V_71 = F_86 ( & F_120 ( V_24 ) -> V_146 , V_159 -> V_15 ,
V_159 -> V_15 + V_159 -> V_21 - 1 ,
V_163 , V_119 ) ;
if ( V_71 && ! V_91 )
V_91 = V_71 ;
F_132 ( V_159 ) ;
return V_91 ;
}
static void F_133 ( struct V_40 * V_40 , int V_91 )
{
F_134 ( V_40 -> V_164 ) ;
}
int F_135 ( struct V_28 * V_165 , T_1 V_15 ,
T_1 V_166 , T_1 V_167 , struct V_123 * V_123 ,
int V_168 )
{
struct V_40 * V_40 ;
struct V_169 * V_170 ;
F_136 ( V_171 ) ;
T_1 V_172 = 0 ;
T_1 V_173 ;
struct V_174 * V_175 = NULL ;
struct V_176 * V_177 = & V_165 -> V_178 ;
int V_71 ;
F_68 ( ! V_168 ) ;
if ( F_137 ( V_177 , V_167 , V_166 , V_168 ) )
return 0 ;
V_40 = F_138 ( V_119 , 1 ) ;
if ( ! V_40 )
return - V_179 ;
V_40 -> V_164 = & V_171 ;
V_40 -> V_180 = F_133 ;
V_40 -> V_181 = 0 ;
V_172 = V_166 ;
V_71 = F_139 ( V_165 , V_182 , V_167 ,
& V_172 , & V_175 , V_168 ) ;
if ( V_71 ) {
F_140 ( V_40 ) ;
return - V_179 ;
}
F_68 ( V_168 != V_175 -> V_168 ) ;
V_173 = V_175 -> V_183 [ V_168 - 1 ] . V_184 >> 9 ;
V_40 -> V_185 = V_173 ;
V_170 = V_175 -> V_183 [ V_168 - 1 ] . V_170 ;
F_132 ( V_175 ) ;
if ( ! V_170 || ! V_170 -> V_186 || ! V_170 -> V_187 ) {
F_140 ( V_40 ) ;
return - V_179 ;
}
V_40 -> V_188 = V_170 -> V_186 ;
F_141 ( V_40 , V_123 , V_166 , V_15 - F_129 ( V_123 ) ) ;
F_142 ( V_189 , V_40 ) ;
F_143 ( & V_171 ) ;
if ( ! F_144 ( V_190 , & V_40 -> V_191 ) ) {
F_140 ( V_40 ) ;
F_145 ( V_170 , V_192 ) ;
return - V_179 ;
}
F_146 ( V_193 L_14
L_15 , V_123 -> V_30 -> V_31 -> V_194 ,
V_15 , F_147 ( V_170 -> V_195 ) , V_173 ) ;
F_140 ( V_40 ) ;
return 0 ;
}
int F_148 ( struct V_196 * V_57 , struct V_9 * V_10 ,
int V_168 )
{
T_1 V_15 = V_10 -> V_15 ;
unsigned long V_134 , V_197 = F_149 ( V_10 -> V_15 , V_10 -> V_21 ) ;
int V_71 = 0 ;
for ( V_134 = 0 ; V_134 < V_197 ; V_134 ++ ) {
struct V_123 * V_60 = F_150 ( V_10 , V_134 ) ;
V_71 = F_135 ( V_57 -> V_165 , V_15 , V_143 ,
V_15 , V_60 , V_168 ) ;
if ( V_71 )
break;
V_15 += V_143 ;
}
return V_71 ;
}
static int F_151 ( T_1 V_15 , struct V_123 * V_123 )
{
T_1 V_52 ;
T_1 V_198 ;
struct V_158 * V_199 ;
struct V_28 * V_165 ;
struct V_7 * V_8 ;
int V_200 ;
int V_160 = 0 ;
int V_71 ;
struct V_24 * V_24 = V_123 -> V_30 -> V_31 ;
V_52 = 0 ;
V_71 = F_123 ( & F_120 ( V_24 ) -> V_162 , & V_52 ,
( T_1 ) - 1 , 1 , V_89 , 0 ) ;
if ( ! V_71 )
return 0 ;
V_71 = F_127 ( & F_120 ( V_24 ) -> V_162 , V_15 ,
& V_198 ) ;
if ( V_71 )
return 0 ;
V_199 = (struct V_158 * ) ( unsigned long ) V_198 ;
F_68 ( ! V_199 -> V_201 ) ;
if ( V_199 -> V_202 ) {
F_152 ( L_16 ,
V_199 -> V_15 ) ;
V_160 = 1 ;
goto V_103;
}
F_66 ( & F_120 ( V_24 ) -> V_146 . V_49 ) ;
V_8 = F_107 ( & F_120 ( V_24 ) -> V_146 ,
V_199 -> V_15 ,
V_118 ) ;
F_70 ( & F_120 ( V_24 ) -> V_146 . V_49 ) ;
if ( V_8 && V_8 -> V_15 <= V_199 -> V_15 &&
V_8 -> V_16 >= V_199 -> V_15 + V_199 -> V_21 - 1 ) {
V_165 = F_120 ( V_24 ) -> V_57 -> V_165 ;
V_200 = F_153 ( V_165 , V_199 -> V_167 ,
V_199 -> V_21 ) ;
if ( V_200 > 1 ) {
V_71 = F_135 ( V_165 , V_15 , V_199 -> V_21 ,
V_199 -> V_167 , V_123 ,
V_199 -> V_203 ) ;
V_160 = ! V_71 ;
}
V_71 = 0 ;
}
V_103:
if ( ! V_71 )
V_71 = F_131 ( V_24 , V_199 , V_160 ) ;
return V_71 ;
}
static int F_154 ( struct V_40 * V_204 , T_1 V_205 ,
struct V_123 * V_123 , T_1 V_15 , T_1 V_16 ,
int V_203 )
{
struct V_158 * V_199 = NULL ;
T_1 V_52 ;
struct V_206 * V_207 ;
struct V_24 * V_24 = V_123 -> V_30 -> V_31 ;
struct V_29 * V_161 = & F_120 ( V_24 ) -> V_162 ;
struct V_29 * V_17 = & F_120 ( V_24 ) -> V_146 ;
struct V_208 * V_209 = & F_120 ( V_24 ) -> V_210 ;
struct V_40 * V_40 ;
struct V_39 * V_211 ;
struct V_39 * V_174 ;
int V_200 ;
int V_71 ;
int V_212 ;
T_1 V_167 ;
F_68 ( V_204 -> V_213 & V_214 ) ;
V_71 = F_127 ( V_161 , V_15 , & V_52 ) ;
if ( V_71 ) {
V_199 = F_155 ( sizeof( * V_199 ) , V_119 ) ;
if ( ! V_199 )
return - V_35 ;
V_199 -> V_15 = V_15 ;
V_199 -> V_21 = V_16 - V_15 + 1 ;
V_199 -> V_201 = 0 ;
V_199 -> V_215 = 0 ;
V_199 -> V_202 = 0 ;
F_156 ( & V_209 -> V_49 ) ;
V_207 = F_157 ( V_209 , V_15 , V_199 -> V_21 ) ;
if ( ! V_207 ) {
F_158 ( & V_209 -> V_49 ) ;
F_132 ( V_199 ) ;
return - V_179 ;
}
if ( V_207 -> V_15 > V_15 || V_207 -> V_15 + V_207 -> V_21 < V_15 ) {
F_159 ( V_207 ) ;
V_207 = NULL ;
}
F_158 ( & V_209 -> V_49 ) ;
if ( ! V_207 ) {
F_132 ( V_199 ) ;
return - V_179 ;
}
V_167 = V_15 - V_207 -> V_15 ;
V_167 = V_207 -> V_216 + V_167 ;
if ( F_144 ( V_217 , & V_207 -> V_4 ) ) {
V_167 = V_207 -> V_216 ;
V_199 -> V_215 = V_218 ;
F_160 ( & V_199 -> V_215 ,
V_207 -> V_219 ) ;
}
F_152 ( L_17
L_18 , V_167 , V_15 , V_199 -> V_21 ) ;
V_199 -> V_167 = V_167 ;
F_159 ( V_207 ) ;
V_71 = F_85 ( V_161 , V_15 , V_16 ,
V_118 | V_89 , V_119 ) ;
if ( V_71 >= 0 )
V_71 = F_126 ( V_161 , V_15 ,
( T_1 ) ( unsigned long ) V_199 ) ;
if ( V_71 >= 0 )
V_71 = F_85 ( V_17 , V_15 , V_16 , V_163 ,
V_119 ) ;
if ( V_71 < 0 ) {
F_132 ( V_199 ) ;
return V_71 ;
}
} else {
V_199 = (struct V_158 * ) ( unsigned long ) V_52 ;
F_152 ( L_19
L_20 ,
V_199 -> V_167 , V_199 -> V_15 , V_199 -> V_21 ,
V_199 -> V_202 ) ;
}
V_200 = F_153 ( F_120 ( V_24 ) -> V_57 -> V_165 ,
V_199 -> V_167 , V_199 -> V_21 ) ;
if ( V_200 == 1 ) {
F_152 ( L_21 ,
V_200 , V_199 -> V_201 , V_203 ) ;
F_131 ( V_24 , V_199 , 0 ) ;
return - V_179 ;
}
if ( V_204 -> V_220 > 1 ) {
F_68 ( V_199 -> V_202 ) ;
V_199 -> V_202 = 1 ;
V_199 -> V_201 = V_203 ;
V_212 = V_221 | V_222 ;
} else {
if ( V_199 -> V_202 ) {
F_68 ( V_199 -> V_201 != V_203 ) ;
V_199 -> V_202 = 0 ;
V_199 -> V_201 = 0 ;
}
V_199 -> V_203 = V_203 ;
V_199 -> V_201 ++ ;
if ( V_199 -> V_201 == V_203 )
V_199 -> V_201 ++ ;
V_212 = V_221 ;
}
if ( V_199 -> V_201 > V_200 ) {
F_152 ( L_22 ,
V_200 , V_199 -> V_201 , V_203 ) ;
F_131 ( V_24 , V_199 , 0 ) ;
return - V_179 ;
}
V_40 = F_138 ( V_119 , 1 ) ;
if ( ! V_40 ) {
F_131 ( V_24 , V_199 , 0 ) ;
return - V_179 ;
}
V_40 -> V_180 = V_204 -> V_180 ;
V_40 -> V_185 = V_199 -> V_167 >> 9 ;
V_40 -> V_188 = F_120 ( V_24 ) -> V_57 -> V_165 -> V_223 -> V_224 ;
V_40 -> V_181 = 0 ;
V_211 = V_39 ( V_204 ) ;
if ( V_211 -> V_225 ) {
struct V_28 * V_165 = F_120 ( V_24 ) -> V_57 -> V_165 ;
T_6 V_226 = F_161 ( V_165 -> V_227 ) ;
V_174 = V_39 ( V_40 ) ;
V_174 -> V_225 = V_174 -> V_228 ;
V_205 >>= V_24 -> V_32 -> V_229 ;
V_205 *= V_226 ;
memcpy ( V_174 -> V_225 , V_211 -> V_225 + V_205 ,
V_226 ) ;
}
F_141 ( V_40 , V_123 , V_199 -> V_21 , V_15 - F_129 ( V_123 ) ) ;
F_152 ( L_23
L_24 , V_212 ,
V_199 -> V_201 , V_200 , V_199 -> V_202 ) ;
V_71 = V_17 -> V_47 -> V_230 ( V_24 , V_212 , V_40 ,
V_199 -> V_201 ,
V_199 -> V_215 , 0 ) ;
return V_71 ;
}
int F_162 ( struct V_123 * V_123 , int V_91 , T_1 V_15 , T_1 V_16 )
{
int V_231 = ( V_91 == 0 ) ;
struct V_29 * V_17 ;
int V_71 ;
V_17 = & F_120 ( V_123 -> V_30 -> V_31 ) -> V_146 ;
if ( V_17 -> V_47 && V_17 -> V_47 -> V_232 ) {
V_71 = V_17 -> V_47 -> V_232 ( V_123 , V_15 ,
V_16 , NULL , V_231 ) ;
if ( V_71 )
V_231 = 0 ;
}
if ( ! V_231 ) {
F_163 ( V_123 ) ;
F_164 ( V_123 ) ;
}
return 0 ;
}
static void F_165 ( struct V_40 * V_40 , int V_91 )
{
struct V_233 * V_234 = V_40 -> V_235 + V_40 -> V_220 - 1 ;
struct V_29 * V_17 ;
T_1 V_15 ;
T_1 V_16 ;
do {
struct V_123 * V_123 = V_234 -> V_236 ;
V_17 = & F_120 ( V_123 -> V_30 -> V_31 ) -> V_146 ;
if ( V_234 -> V_237 || V_234 -> V_238 != V_143 )
F_10 ( L_25 ,
V_234 -> V_237 + V_234 -> V_238 != V_143
? V_14 L_26 : V_193 L_27 ,
V_234 -> V_237 , V_234 -> V_238 ) ;
V_15 = F_129 ( V_123 ) ;
V_16 = V_15 + V_234 -> V_237 + V_234 -> V_238 - 1 ;
if ( -- V_234 >= V_40 -> V_235 )
F_166 ( & V_234 -> V_236 -> V_4 ) ;
if ( F_162 ( V_123 , V_91 , V_15 , V_16 ) )
continue;
F_122 ( V_123 ) ;
} while ( V_234 >= V_40 -> V_235 );
F_140 ( V_40 ) ;
}
static void
F_167 ( struct V_29 * V_17 , T_1 V_15 , T_1 V_21 ,
int V_231 )
{
struct V_7 * V_94 = NULL ;
T_1 V_16 = V_15 + V_21 - 1 ;
if ( V_231 && V_17 -> V_239 )
F_91 ( V_17 , V_15 , V_16 , & V_94 , V_46 ) ;
F_96 ( V_17 , V_15 , V_16 , & V_94 , V_46 ) ;
}
static void F_168 ( struct V_40 * V_40 , int V_91 )
{
int V_231 = F_144 ( V_190 , & V_40 -> V_191 ) ;
struct V_233 * V_240 = V_40 -> V_235 + V_40 -> V_220 - 1 ;
struct V_233 * V_234 = V_40 -> V_235 ;
struct V_39 * V_241 = V_39 ( V_40 ) ;
struct V_29 * V_17 ;
T_1 V_58 = 0 ;
T_1 V_15 ;
T_1 V_16 ;
T_1 V_21 ;
T_1 V_242 = 0 ;
T_1 V_243 = 0 ;
int V_244 ;
int V_71 ;
if ( V_91 )
V_231 = 0 ;
do {
struct V_123 * V_123 = V_234 -> V_236 ;
struct V_24 * V_24 = V_123 -> V_30 -> V_31 ;
F_152 ( L_28
L_29 , ( T_1 ) V_40 -> V_185 , V_91 ,
V_241 -> V_168 ) ;
V_17 = & F_120 ( V_24 ) -> V_146 ;
if ( V_234 -> V_237 || V_234 -> V_238 != V_143 )
F_10 ( L_30 ,
V_234 -> V_237 + V_234 -> V_238 != V_143
? V_14 L_26 : V_193 L_27 ,
V_234 -> V_237 , V_234 -> V_238 ) ;
V_15 = F_129 ( V_123 ) ;
V_16 = V_15 + V_234 -> V_237 + V_234 -> V_238 - 1 ;
V_21 = V_234 -> V_238 ;
if ( ++ V_234 <= V_240 )
F_166 ( & V_234 -> V_236 -> V_4 ) ;
V_244 = V_241 -> V_168 ;
if ( F_169 ( V_231 && V_17 -> V_47 &&
V_17 -> V_47 -> V_245 ) ) {
V_71 = V_17 -> V_47 -> V_245 ( V_241 , V_58 ,
V_123 , V_15 , V_16 ,
V_244 ) ;
if ( V_71 )
V_231 = 0 ;
else
F_151 ( V_15 , V_123 ) ;
}
if ( F_169 ( V_231 ) )
goto V_246;
if ( V_17 -> V_47 && V_17 -> V_47 -> V_247 ) {
V_71 = V_17 -> V_47 -> V_247 ( V_123 , V_244 ) ;
if ( ! V_71 && ! V_91 &&
F_144 ( V_190 , & V_40 -> V_191 ) )
V_231 = 1 ;
} else {
V_71 = F_154 ( V_40 , V_58 , V_123 , V_15 , V_16 ,
V_244 ) ;
if ( V_71 == 0 ) {
V_231 =
F_144 ( V_190 , & V_40 -> V_191 ) ;
if ( V_91 )
V_231 = 0 ;
continue;
}
}
V_246:
if ( F_169 ( V_231 ) ) {
T_7 V_248 = F_14 ( V_24 ) ;
T_8 V_122 = V_248 >> V_121 ;
unsigned V_58 ;
V_58 = V_248 & ( V_143 - 1 ) ;
if ( V_123 -> V_120 == V_122 && V_58 )
F_170 ( V_123 , V_58 , V_143 ) ;
F_130 ( V_123 ) ;
} else {
F_163 ( V_123 ) ;
F_164 ( V_123 ) ;
}
F_113 ( V_123 ) ;
V_58 += V_21 ;
if ( F_171 ( ! V_231 ) ) {
if ( V_243 ) {
F_167 ( V_17 ,
V_242 ,
V_243 , 1 ) ;
V_242 = 0 ;
V_243 = 0 ;
}
F_167 ( V_17 , V_15 ,
V_16 - V_15 + 1 , 0 ) ;
} else if ( ! V_243 ) {
V_242 = V_15 ;
V_243 = V_16 + 1 - V_15 ;
} else if ( V_242 + V_243 == V_15 ) {
V_243 += V_16 + 1 - V_15 ;
} else {
F_167 ( V_17 , V_242 ,
V_243 , V_231 ) ;
V_242 = V_15 ;
V_243 = V_16 + 1 - V_15 ;
}
} while ( V_234 <= V_240 );
if ( V_243 )
F_167 ( V_17 , V_242 , V_243 ,
V_231 ) ;
if ( V_241 -> V_249 )
V_241 -> V_249 ( V_241 , V_91 ) ;
F_140 ( V_40 ) ;
}
struct V_40 *
F_172 ( struct V_250 * V_186 , T_1 V_251 , int V_252 ,
T_3 V_253 )
{
struct V_39 * V_174 ;
struct V_40 * V_40 ;
V_40 = F_173 ( V_253 , V_252 , V_37 ) ;
if ( V_40 == NULL && ( V_254 -> V_4 & V_255 ) ) {
while ( ! V_40 && ( V_252 /= 2 ) ) {
V_40 = F_173 ( V_253 ,
V_252 , V_37 ) ;
}
}
if ( V_40 ) {
V_40 -> V_181 = 0 ;
V_40 -> V_188 = V_186 ;
V_40 -> V_185 = V_251 ;
V_174 = V_39 ( V_40 ) ;
V_174 -> V_225 = NULL ;
V_174 -> V_256 = NULL ;
V_174 -> V_249 = NULL ;
}
return V_40 ;
}
struct V_40 * F_174 ( struct V_40 * V_40 , T_3 V_257 )
{
return F_175 ( V_40 , V_257 , V_37 ) ;
}
struct V_40 * F_138 ( T_3 V_257 , unsigned int V_258 )
{
struct V_39 * V_174 ;
struct V_40 * V_40 ;
V_40 = F_173 ( V_257 , V_258 , V_37 ) ;
if ( V_40 ) {
V_174 = V_39 ( V_40 ) ;
V_174 -> V_225 = NULL ;
V_174 -> V_256 = NULL ;
V_174 -> V_249 = NULL ;
}
return V_40 ;
}
static int T_4 F_176 ( int V_259 , struct V_40 * V_40 ,
int V_168 , unsigned long V_215 )
{
int V_71 = 0 ;
struct V_233 * V_234 = V_40 -> V_235 + V_40 -> V_220 - 1 ;
struct V_123 * V_123 = V_234 -> V_236 ;
struct V_29 * V_17 = V_40 -> V_164 ;
T_1 V_15 ;
V_15 = F_129 ( V_123 ) + V_234 -> V_237 ;
V_40 -> V_164 = NULL ;
F_177 ( V_40 ) ;
if ( V_17 -> V_47 && V_17 -> V_47 -> V_230 )
V_71 = V_17 -> V_47 -> V_230 ( V_123 -> V_30 -> V_31 , V_259 , V_40 ,
V_168 , V_215 , V_15 ) ;
else
F_142 ( V_259 , V_40 ) ;
if ( F_178 ( V_40 , V_260 ) )
V_71 = - V_261 ;
F_140 ( V_40 ) ;
return V_71 ;
}
static int F_179 ( int V_259 , struct V_29 * V_17 , struct V_123 * V_123 ,
unsigned long V_58 , T_9 V_262 , struct V_40 * V_40 ,
unsigned long V_215 )
{
int V_71 = 0 ;
if ( V_17 -> V_47 && V_17 -> V_47 -> V_263 )
V_71 = V_17 -> V_47 -> V_263 ( V_259 , V_123 , V_58 , V_262 , V_40 ,
V_215 ) ;
F_68 ( V_71 < 0 ) ;
return V_71 ;
}
static int F_180 ( int V_259 , struct V_29 * V_17 ,
struct V_123 * V_123 , T_10 V_173 ,
T_9 V_262 , unsigned long V_58 ,
struct V_250 * V_186 ,
struct V_40 * * V_264 ,
unsigned long V_265 ,
T_11 V_266 ,
int V_168 ,
unsigned long V_267 ,
unsigned long V_215 )
{
int V_71 = 0 ;
struct V_40 * V_40 ;
int V_268 ;
int V_153 = 0 ;
int V_269 = V_215 & V_218 ;
int V_270 = V_267 & V_218 ;
T_9 V_271 = F_112 ( T_9 , V_262 , V_143 ) ;
if ( V_264 && * V_264 ) {
V_40 = * V_264 ;
if ( V_270 )
V_153 = V_40 -> V_185 == V_173 ;
else
V_153 = F_181 ( V_40 ) == V_173 ;
if ( V_267 != V_215 || ! V_153 ||
F_179 ( V_259 , V_17 , V_123 , V_58 , V_271 , V_40 , V_215 ) ||
F_141 ( V_40 , V_123 , V_271 , V_58 ) < V_271 ) {
V_71 = F_176 ( V_259 , V_40 , V_168 ,
V_267 ) ;
if ( V_71 < 0 )
return V_71 ;
V_40 = NULL ;
} else {
return 0 ;
}
}
if ( V_269 )
V_268 = V_272 ;
else
V_268 = F_182 ( V_186 ) ;
V_40 = F_172 ( V_186 , V_173 , V_268 , V_119 | V_273 ) ;
if ( ! V_40 )
return - V_35 ;
F_141 ( V_40 , V_123 , V_271 , V_58 ) ;
V_40 -> V_180 = V_266 ;
V_40 -> V_164 = V_17 ;
if ( V_264 )
* V_264 = V_40 ;
else
V_71 = F_176 ( V_259 , V_40 , V_168 , V_215 ) ;
return V_71 ;
}
static void F_183 ( struct V_9 * V_10 ,
struct V_123 * V_123 )
{
if ( ! F_184 ( V_123 ) ) {
F_185 ( V_123 ) ;
F_186 ( V_123 ) ;
F_187 ( V_123 , ( unsigned long ) V_10 ) ;
} else {
F_38 ( V_123 -> V_52 != ( unsigned long ) V_10 ) ;
}
}
void F_188 ( struct V_123 * V_123 )
{
if ( ! F_184 ( V_123 ) ) {
F_185 ( V_123 ) ;
F_186 ( V_123 ) ;
F_187 ( V_123 , V_274 ) ;
}
}
static struct V_206 *
F_189 ( struct V_24 * V_24 , struct V_123 * V_123 , T_9 V_275 ,
T_1 V_15 , T_1 V_21 , T_12 * V_276 ,
struct V_206 * * V_277 )
{
struct V_206 * V_207 ;
if ( V_277 && * V_277 ) {
V_207 = * V_277 ;
if ( V_207 -> V_278 && V_15 >= V_207 -> V_15 &&
V_15 < F_190 ( V_207 ) ) {
F_78 ( & V_207 -> V_18 ) ;
return V_207 ;
}
F_159 ( V_207 ) ;
* V_277 = NULL ;
}
V_207 = V_276 ( V_24 , V_123 , V_275 , V_15 , V_21 , 0 ) ;
if ( V_277 && ! F_191 ( V_207 ) ) {
F_68 ( * V_277 ) ;
F_78 ( & V_207 -> V_18 ) ;
* V_277 = V_207 ;
}
return V_207 ;
}
static int F_192 ( struct V_29 * V_17 ,
struct V_123 * V_123 ,
T_12 * V_276 ,
struct V_206 * * V_277 ,
struct V_40 * * V_40 , int V_168 ,
unsigned long * V_215 , int V_259 )
{
struct V_24 * V_24 = V_123 -> V_30 -> V_31 ;
T_1 V_15 = F_129 ( V_123 ) ;
T_1 V_279 = V_15 + V_143 - 1 ;
T_1 V_16 ;
T_1 V_280 = V_15 ;
T_1 V_281 ;
T_1 V_282 = F_14 ( V_24 ) ;
T_1 V_216 ;
T_1 V_283 ;
T_10 V_173 ;
struct V_206 * V_207 ;
struct V_250 * V_186 ;
int V_71 ;
int V_268 = 0 ;
int V_284 = * V_215 & V_285 ;
T_9 V_275 = 0 ;
T_9 V_286 ;
T_9 V_287 ;
T_9 V_288 = V_24 -> V_32 -> V_289 ;
unsigned long V_290 = * V_215 & V_285 ;
F_188 ( V_123 ) ;
V_16 = V_279 ;
if ( ! F_193 ( V_123 ) ) {
if ( F_194 ( V_123 ) == 0 ) {
F_68 ( V_288 != V_26 ) ;
F_97 ( V_17 , V_15 , V_16 ) ;
goto V_103;
}
}
if ( V_123 -> V_120 == V_282 >> V_121 ) {
char * V_291 ;
T_9 V_292 = V_282 & ( V_143 - 1 ) ;
if ( V_292 ) {
V_286 = V_143 - V_292 ;
V_291 = F_195 ( V_123 ) ;
memset ( V_291 + V_292 , 0 , V_286 ) ;
F_196 ( V_123 ) ;
F_197 ( V_291 ) ;
}
}
while ( V_280 <= V_16 ) {
unsigned long V_293 = ( V_282 >> V_121 ) + 1 ;
if ( V_280 >= V_282 ) {
char * V_291 ;
struct V_7 * V_94 = NULL ;
V_286 = V_143 - V_275 ;
V_291 = F_195 ( V_123 ) ;
memset ( V_291 + V_275 , 0 , V_286 ) ;
F_196 ( V_123 ) ;
F_197 ( V_291 ) ;
F_91 ( V_17 , V_280 , V_280 + V_286 - 1 ,
& V_94 , V_119 ) ;
if ( ! V_284 )
F_96 ( V_17 , V_280 ,
V_280 + V_286 - 1 ,
& V_94 , V_119 ) ;
break;
}
V_207 = F_189 ( V_24 , V_123 , V_275 , V_280 ,
V_16 - V_280 + 1 , V_276 , V_277 ) ;
if ( F_191 ( V_207 ) ) {
F_164 ( V_123 ) ;
if ( ! V_284 )
F_97 ( V_17 , V_280 , V_16 ) ;
break;
}
V_281 = V_280 - V_207 -> V_15 ;
F_68 ( F_190 ( V_207 ) <= V_280 ) ;
F_68 ( V_16 < V_280 ) ;
if ( F_144 ( V_217 , & V_207 -> V_4 ) ) {
V_290 |= V_218 ;
F_160 ( & V_290 ,
V_207 -> V_219 ) ;
}
V_286 = F_124 ( F_190 ( V_207 ) - V_280 , V_16 - V_280 + 1 ) ;
V_283 = F_124 ( F_190 ( V_207 ) - 1 , V_16 ) ;
V_286 = F_198 ( V_286 , V_288 ) ;
if ( V_290 & V_218 ) {
V_287 = V_207 -> V_294 ;
V_173 = V_207 -> V_216 >> 9 ;
} else {
V_173 = ( V_207 -> V_216 + V_281 ) >> 9 ;
V_287 = V_286 ;
}
V_186 = V_207 -> V_186 ;
V_216 = V_207 -> V_216 ;
if ( F_144 ( V_295 , & V_207 -> V_4 ) )
V_216 = V_296 ;
F_159 ( V_207 ) ;
V_207 = NULL ;
if ( V_216 == V_296 ) {
char * V_291 ;
struct V_7 * V_94 = NULL ;
V_291 = F_195 ( V_123 ) ;
memset ( V_291 + V_275 , 0 , V_286 ) ;
F_196 ( V_123 ) ;
F_197 ( V_291 ) ;
F_91 ( V_17 , V_280 , V_280 + V_286 - 1 ,
& V_94 , V_119 ) ;
F_96 ( V_17 , V_280 , V_280 + V_286 - 1 ,
& V_94 , V_119 ) ;
V_280 = V_280 + V_286 ;
V_275 += V_286 ;
continue;
}
if ( F_118 ( V_17 , V_280 , V_283 ,
V_114 , 1 , NULL ) ) {
F_128 ( V_17 , V_123 ) ;
if ( ! V_284 )
F_97 ( V_17 , V_280 , V_280 + V_286 - 1 ) ;
V_280 = V_280 + V_286 ;
V_275 += V_286 ;
continue;
}
if ( V_216 == V_297 ) {
F_164 ( V_123 ) ;
if ( ! V_284 )
F_97 ( V_17 , V_280 , V_280 + V_286 - 1 ) ;
V_280 = V_280 + V_286 ;
V_275 += V_286 ;
continue;
}
V_293 -= V_123 -> V_120 ;
V_71 = F_180 ( V_259 , V_17 , V_123 ,
V_173 , V_287 , V_275 ,
V_186 , V_40 , V_293 ,
F_168 , V_168 ,
* V_215 ,
V_290 ) ;
if ( ! V_71 ) {
V_268 ++ ;
* V_215 = V_290 ;
} else {
F_164 ( V_123 ) ;
if ( ! V_284 )
F_97 ( V_17 , V_280 , V_280 + V_286 - 1 ) ;
}
V_280 = V_280 + V_286 ;
V_275 += V_286 ;
}
V_103:
if ( ! V_268 ) {
if ( ! F_199 ( V_123 ) )
F_130 ( V_123 ) ;
F_113 ( V_123 ) ;
}
return 0 ;
}
static inline void F_200 ( struct V_29 * V_17 ,
struct V_123 * V_132 [] , int V_133 ,
T_1 V_15 , T_1 V_16 ,
T_12 * V_276 ,
struct V_206 * * V_277 ,
struct V_40 * * V_40 , int V_168 ,
unsigned long * V_215 , int V_259 )
{
struct V_24 * V_24 ;
struct V_298 * V_299 ;
int V_120 ;
V_24 = V_132 [ 0 ] -> V_30 -> V_31 ;
while ( 1 ) {
F_94 ( V_17 , V_15 , V_16 ) ;
V_299 = F_201 ( V_24 , V_15 ,
V_16 - V_15 + 1 ) ;
if ( ! V_299 )
break;
F_97 ( V_17 , V_15 , V_16 ) ;
F_202 ( V_24 , V_299 , 1 ) ;
F_203 ( V_299 ) ;
}
for ( V_120 = 0 ; V_120 < V_133 ; V_120 ++ ) {
F_192 ( V_17 , V_132 [ V_120 ] , V_276 , V_277 , V_40 ,
V_168 , V_215 , V_259 ) ;
F_101 ( V_132 [ V_120 ] ) ;
}
}
static void F_204 ( struct V_29 * V_17 ,
struct V_123 * V_132 [] ,
int V_133 , T_12 * V_276 ,
struct V_206 * * V_277 ,
struct V_40 * * V_40 , int V_168 ,
unsigned long * V_215 , int V_259 )
{
T_1 V_15 = 0 ;
T_1 V_16 = 0 ;
T_1 V_300 ;
int V_120 ;
int V_301 = 0 ;
for ( V_120 = 0 ; V_120 < V_133 ; V_120 ++ ) {
V_300 = F_129 ( V_132 [ V_120 ] ) ;
if ( ! V_16 ) {
V_15 = V_300 ;
V_16 = V_15 + V_143 - 1 ;
V_301 = V_120 ;
} else if ( V_16 + 1 == V_300 ) {
V_16 += V_143 ;
} else {
F_200 ( V_17 , & V_132 [ V_301 ] ,
V_120 - V_301 , V_15 ,
V_16 , V_276 , V_277 ,
V_40 , V_168 , V_215 ,
V_259 ) ;
V_15 = V_300 ;
V_16 = V_15 + V_143 - 1 ;
V_301 = V_120 ;
}
}
if ( V_16 )
F_200 ( V_17 , & V_132 [ V_301 ] ,
V_120 - V_301 , V_15 ,
V_16 , V_276 , V_277 , V_40 ,
V_168 , V_215 , V_259 ) ;
}
static int F_205 ( struct V_29 * V_17 ,
struct V_123 * V_123 ,
T_12 * V_276 ,
struct V_40 * * V_40 , int V_168 ,
unsigned long * V_215 , int V_259 )
{
struct V_24 * V_24 = V_123 -> V_30 -> V_31 ;
struct V_298 * V_299 ;
T_1 V_15 = F_129 ( V_123 ) ;
T_1 V_16 = V_15 + V_143 - 1 ;
int V_71 ;
while ( 1 ) {
F_94 ( V_17 , V_15 , V_16 ) ;
V_299 = F_206 ( V_24 , V_15 ) ;
if ( ! V_299 )
break;
F_97 ( V_17 , V_15 , V_16 ) ;
F_202 ( V_24 , V_299 , 1 ) ;
F_203 ( V_299 ) ;
}
V_71 = F_192 ( V_17 , V_123 , V_276 , NULL , V_40 , V_168 ,
V_215 , V_259 ) ;
return V_71 ;
}
int F_207 ( struct V_29 * V_17 , struct V_123 * V_123 ,
T_12 * V_276 , int V_168 )
{
struct V_40 * V_40 = NULL ;
unsigned long V_215 = 0 ;
int V_71 ;
V_71 = F_205 ( V_17 , V_123 , V_276 , & V_40 , V_168 ,
& V_215 , V_302 ) ;
if ( V_40 )
V_71 = F_176 ( V_302 , V_40 , V_168 , V_215 ) ;
return V_71 ;
}
int F_208 ( struct V_29 * V_17 , struct V_123 * V_123 ,
T_12 * V_276 , int V_168 )
{
struct V_40 * V_40 = NULL ;
unsigned long V_215 = V_285 ;
int V_71 ;
V_71 = F_192 ( V_17 , V_123 , V_276 , NULL , & V_40 , V_168 ,
& V_215 , V_302 ) ;
if ( V_40 )
V_71 = F_176 ( V_302 , V_40 , V_168 , V_215 ) ;
return V_71 ;
}
static T_5 void F_209 ( struct V_123 * V_123 ,
struct V_303 * V_304 ,
unsigned long V_305 )
{
V_304 -> V_306 -= V_305 ;
if ( V_304 -> V_307 || ( V_304 -> V_306 > 0 &&
V_304 -> V_308 == 0 && V_304 -> V_309 == V_310 ) )
V_123 -> V_30 -> V_311 = V_123 -> V_120 + V_305 ;
}
static int F_210 ( struct V_123 * V_123 , struct V_303 * V_304 ,
void * V_312 )
{
struct V_24 * V_24 = V_123 -> V_30 -> V_31 ;
struct V_313 * V_314 = V_312 ;
struct V_29 * V_17 = V_314 -> V_17 ;
T_1 V_15 = F_129 ( V_123 ) ;
T_1 V_135 ;
T_1 V_279 = V_15 + V_143 - 1 ;
T_1 V_16 ;
T_1 V_280 = V_15 ;
T_1 V_281 ;
T_1 V_282 = F_14 ( V_24 ) ;
T_1 V_216 ;
T_1 V_286 ;
T_10 V_173 ;
struct V_7 * V_93 = NULL ;
struct V_206 * V_207 ;
struct V_250 * V_186 ;
int V_71 ;
int V_268 = 0 ;
T_9 V_275 = 0 ;
T_9 V_288 ;
T_7 V_248 = F_14 ( V_24 ) ;
unsigned long V_122 = V_248 >> V_121 ;
T_1 V_315 ;
T_1 V_136 ;
int V_316 ;
int V_317 ;
int V_318 ;
unsigned long V_305 = 0 ;
bool V_319 = true ;
if ( V_304 -> V_320 == V_321 )
V_318 = V_189 ;
else
V_318 = V_182 ;
F_211 ( V_123 , V_24 , V_304 ) ;
F_38 ( ! F_212 ( V_123 ) ) ;
F_213 ( V_123 ) ;
V_275 = V_248 & ( V_143 - 1 ) ;
if ( V_123 -> V_120 > V_122 ||
( V_123 -> V_120 == V_122 && ! V_275 ) ) {
V_123 -> V_30 -> V_322 -> V_323 ( V_123 , 0 , V_143 ) ;
F_113 ( V_123 ) ;
return 0 ;
}
if ( V_123 -> V_120 == V_122 ) {
char * V_291 ;
V_291 = F_195 ( V_123 ) ;
memset ( V_291 + V_275 , 0 ,
V_143 - V_275 ) ;
F_197 ( V_291 ) ;
F_196 ( V_123 ) ;
}
V_275 = 0 ;
F_188 ( V_123 ) ;
if ( ! V_17 -> V_47 || ! V_17 -> V_47 -> V_319 )
V_319 = false ;
V_135 = V_15 ;
V_136 = 0 ;
V_316 = 0 ;
if ( ! V_314 -> V_324 && V_319 ) {
T_1 V_325 = 0 ;
F_209 ( V_123 , V_304 , 0 ) ;
while ( V_136 < V_279 ) {
V_315 = F_117 ( V_24 , V_17 ,
V_123 ,
& V_135 ,
& V_136 ,
128 * 1024 * 1024 ) ;
if ( V_315 == 0 ) {
V_135 = V_136 + 1 ;
continue;
}
V_71 = V_17 -> V_47 -> V_319 ( V_24 , V_123 ,
V_135 ,
V_136 ,
& V_316 ,
& V_305 ) ;
if ( V_71 ) {
F_164 ( V_123 ) ;
goto V_141;
}
V_325 += ( V_136 - V_135 +
V_143 ) >>
V_121 ;
V_135 = V_136 + 1 ;
}
if ( V_304 -> V_306 < V_325 ) {
int V_326 = 8192 ;
if ( V_325 < V_326 * 2 )
V_326 = V_325 ;
V_304 -> V_306 = F_112 ( T_1 , V_325 ,
V_326 ) ;
}
if ( V_316 ) {
V_71 = 0 ;
V_304 -> V_306 -= V_305 ;
goto V_327;
}
}
if ( V_17 -> V_47 && V_17 -> V_47 -> V_328 ) {
V_71 = V_17 -> V_47 -> V_328 ( V_123 , V_15 ,
V_279 ) ;
if ( V_71 ) {
if ( V_71 == - V_329 )
V_304 -> V_330 ++ ;
else
F_214 ( V_304 , V_123 ) ;
F_209 ( V_123 , V_304 , V_305 ) ;
F_113 ( V_123 ) ;
V_71 = 0 ;
goto V_327;
}
}
F_209 ( V_123 , V_304 , V_305 + 1 ) ;
V_16 = V_279 ;
if ( V_282 <= V_15 ) {
if ( V_17 -> V_47 && V_17 -> V_47 -> V_232 )
V_17 -> V_47 -> V_232 ( V_123 , V_15 ,
V_279 , NULL , 1 ) ;
goto V_141;
}
V_288 = V_24 -> V_32 -> V_289 ;
while ( V_280 <= V_16 ) {
if ( V_280 >= V_282 ) {
if ( V_17 -> V_47 && V_17 -> V_47 -> V_232 )
V_17 -> V_47 -> V_232 ( V_123 , V_280 ,
V_279 , NULL , 1 ) ;
break;
}
V_207 = V_314 -> V_276 ( V_24 , V_123 , V_275 , V_280 ,
V_16 - V_280 + 1 , 1 ) ;
if ( F_191 ( V_207 ) ) {
F_164 ( V_123 ) ;
break;
}
V_281 = V_280 - V_207 -> V_15 ;
F_68 ( F_190 ( V_207 ) <= V_280 ) ;
F_68 ( V_16 < V_280 ) ;
V_286 = F_124 ( F_190 ( V_207 ) - V_280 , V_16 - V_280 + 1 ) ;
V_286 = F_198 ( V_286 , V_288 ) ;
V_173 = ( V_207 -> V_216 + V_281 ) >> 9 ;
V_186 = V_207 -> V_186 ;
V_216 = V_207 -> V_216 ;
V_317 = F_144 ( V_217 , & V_207 -> V_4 ) ;
F_159 ( V_207 ) ;
V_207 = NULL ;
if ( V_317 || V_216 == V_296 ||
V_216 == V_297 ) {
if ( ! V_317 && V_17 -> V_47 &&
V_17 -> V_47 -> V_232 )
V_17 -> V_47 -> V_232 ( V_123 , V_280 ,
V_280 + V_286 - 1 ,
NULL , 1 ) ;
else if ( V_317 ) {
V_268 ++ ;
}
V_280 += V_286 ;
V_275 += V_286 ;
continue;
}
if ( 0 && ! F_118 ( V_17 , V_280 , V_280 + V_286 - 1 ,
V_89 , 0 , NULL ) ) {
V_280 = V_280 + V_286 ;
V_275 += V_286 ;
continue;
}
if ( V_17 -> V_47 && V_17 -> V_47 -> V_331 ) {
V_71 = V_17 -> V_47 -> V_331 ( V_123 , V_280 ,
V_280 + V_286 - 1 ) ;
} else {
V_71 = 0 ;
}
if ( V_71 ) {
F_164 ( V_123 ) ;
} else {
unsigned long V_332 = V_122 + 1 ;
F_105 ( V_17 , V_280 , V_280 + V_286 - 1 ) ;
if ( ! F_215 ( V_123 ) ) {
F_10 ( V_14 L_31
L_32 ,
V_123 -> V_120 , V_280 , V_16 ) ;
}
V_71 = F_180 ( V_318 , V_17 , V_123 ,
V_173 , V_286 , V_275 ,
V_186 , & V_314 -> V_40 , V_332 ,
F_165 ,
0 , 0 , 0 ) ;
if ( V_71 )
F_164 ( V_123 ) ;
}
V_280 = V_280 + V_286 ;
V_275 += V_286 ;
V_268 ++ ;
}
V_141:
if ( V_268 == 0 ) {
F_106 ( V_123 ) ;
F_122 ( V_123 ) ;
}
F_113 ( V_123 ) ;
V_327:
F_36 ( V_93 ) ;
return 0 ;
}
static int F_216 ( void * V_333 )
{
F_217 () ;
return 0 ;
}
void F_218 ( struct V_9 * V_10 )
{
F_219 ( & V_10 -> V_334 , V_335 , F_216 ,
V_106 ) ;
}
static int F_220 ( struct V_9 * V_10 ,
struct V_28 * V_165 ,
struct V_313 * V_314 )
{
unsigned long V_134 , V_197 ;
int V_336 = 0 ;
int V_71 = 0 ;
if ( ! F_221 ( V_10 ) ) {
V_336 = 1 ;
F_222 ( V_314 ) ;
F_223 ( V_10 ) ;
}
if ( F_144 ( V_335 , & V_10 -> V_334 ) ) {
F_224 ( V_10 ) ;
if ( ! V_314 -> V_337 )
return 0 ;
if ( ! V_336 ) {
F_222 ( V_314 ) ;
V_336 = 1 ;
}
while ( 1 ) {
F_218 ( V_10 ) ;
F_223 ( V_10 ) ;
if ( ! F_144 ( V_335 , & V_10 -> V_334 ) )
break;
F_224 ( V_10 ) ;
}
}
F_66 ( & V_10 -> V_338 ) ;
if ( F_225 ( V_339 , & V_10 -> V_334 ) ) {
F_226 ( V_335 , & V_10 -> V_334 ) ;
F_70 ( & V_10 -> V_338 ) ;
F_227 ( V_10 , V_340 ) ;
F_228 ( & V_165 -> V_341 ,
- V_10 -> V_21 ,
V_165 -> V_342 ) ;
V_71 = 1 ;
} else {
F_70 ( & V_10 -> V_338 ) ;
}
F_224 ( V_10 ) ;
if ( ! V_71 )
return V_71 ;
V_197 = F_149 ( V_10 -> V_15 , V_10 -> V_21 ) ;
for ( V_134 = 0 ; V_134 < V_197 ; V_134 ++ ) {
struct V_123 * V_60 = F_150 ( V_10 , V_134 ) ;
if ( ! F_229 ( V_60 ) ) {
if ( ! V_336 ) {
F_222 ( V_314 ) ;
V_336 = 1 ;
}
F_115 ( V_60 ) ;
}
}
return V_71 ;
}
static void F_230 ( struct V_9 * V_10 )
{
F_231 ( V_335 , & V_10 -> V_334 ) ;
F_232 () ;
F_233 ( & V_10 -> V_334 , V_335 ) ;
}
static void F_234 ( struct V_40 * V_40 , int V_91 )
{
int V_231 = V_91 == 0 ;
struct V_233 * V_234 = V_40 -> V_235 + V_40 -> V_220 - 1 ;
struct V_9 * V_10 ;
int V_141 ;
do {
struct V_123 * V_123 = V_234 -> V_236 ;
V_234 -- ;
V_10 = (struct V_9 * ) V_123 -> V_52 ;
F_68 ( ! V_10 ) ;
V_141 = F_37 ( & V_10 -> V_343 ) ;
if ( ! V_231 || F_144 ( V_344 , & V_10 -> V_334 ) ) {
F_226 ( V_344 , & V_10 -> V_334 ) ;
F_163 ( V_123 ) ;
F_164 ( V_123 ) ;
}
F_122 ( V_123 ) ;
if ( ! V_141 )
continue;
F_230 ( V_10 ) ;
} while ( V_234 >= V_40 -> V_235 );
F_140 ( V_40 ) ;
}
static int F_235 ( struct V_9 * V_10 ,
struct V_28 * V_165 ,
struct V_303 * V_304 ,
struct V_313 * V_314 )
{
struct V_250 * V_186 = V_165 -> V_223 -> V_224 ;
T_1 V_58 = V_10 -> V_15 ;
unsigned long V_134 , V_197 ;
unsigned long V_215 = 0 ;
int V_259 = ( V_314 -> V_337 ? V_189 : V_182 ) | V_345 ;
int V_71 = 0 ;
F_231 ( V_344 , & V_10 -> V_334 ) ;
V_197 = F_149 ( V_10 -> V_15 , V_10 -> V_21 ) ;
F_33 ( & V_10 -> V_343 , V_197 ) ;
if ( F_236 ( V_10 ) == V_346 )
V_215 = V_347 ;
for ( V_134 = 0 ; V_134 < V_197 ; V_134 ++ ) {
struct V_123 * V_60 = F_150 ( V_10 , V_134 ) ;
F_100 ( V_60 ) ;
F_106 ( V_60 ) ;
V_71 = F_180 ( V_259 , V_10 -> V_17 , V_60 , V_58 >> 9 ,
V_143 , 0 , V_186 , & V_314 -> V_40 ,
- 1 , F_234 ,
0 , V_314 -> V_215 , V_215 ) ;
V_314 -> V_215 = V_215 ;
if ( V_71 ) {
F_226 ( V_344 , & V_10 -> V_334 ) ;
F_164 ( V_60 ) ;
if ( F_237 ( V_197 - V_134 , & V_10 -> V_343 ) )
F_230 ( V_10 ) ;
V_71 = - V_179 ;
break;
}
V_58 += V_143 ;
F_209 ( V_60 , V_304 , 1 ) ;
F_113 ( V_60 ) ;
}
if ( F_171 ( V_71 ) ) {
for (; V_134 < V_197 ; V_134 ++ ) {
struct V_123 * V_60 = F_150 ( V_10 , V_134 ) ;
F_113 ( V_60 ) ;
}
}
return V_71 ;
}
int F_238 ( struct V_43 * V_30 ,
struct V_303 * V_304 )
{
struct V_29 * V_17 = & F_120 ( V_30 -> V_31 ) -> V_146 ;
struct V_28 * V_165 = F_120 ( V_30 -> V_31 ) -> V_57 -> V_165 ;
struct V_9 * V_10 , * V_348 = NULL ;
struct V_313 V_314 = {
. V_40 = NULL ,
. V_17 = V_17 ,
. V_324 = 0 ,
. V_337 = V_304 -> V_320 == V_321 ,
. V_215 = 0 ,
} ;
int V_71 = 0 ;
int V_141 = 0 ;
int V_349 = 0 ;
struct V_350 V_351 ;
int V_133 ;
T_8 V_120 ;
T_8 V_16 ;
int V_352 = 0 ;
int V_353 ;
F_239 ( & V_351 , 0 ) ;
if ( V_304 -> V_307 ) {
V_120 = V_30 -> V_311 ;
V_16 = - 1 ;
} else {
V_120 = V_304 -> V_308 >> V_121 ;
V_16 = V_304 -> V_309 >> V_121 ;
V_352 = 1 ;
}
if ( V_304 -> V_320 == V_321 )
V_353 = V_354 ;
else
V_353 = V_355 ;
V_356:
if ( V_304 -> V_320 == V_321 )
F_240 ( V_30 , V_120 , V_16 ) ;
while ( ! V_141 && ! V_349 && ( V_120 <= V_16 ) &&
( V_133 = F_241 ( & V_351 , V_30 , & V_120 , V_353 ,
F_124 ( V_16 - V_120 , ( T_8 ) V_357 - 1 ) + 1 ) ) ) {
unsigned V_134 ;
V_352 = 1 ;
for ( V_134 = 0 ; V_134 < V_133 ; V_134 ++ ) {
struct V_123 * V_123 = V_351 . V_132 [ V_134 ] ;
if ( ! F_184 ( V_123 ) )
continue;
if ( ! V_304 -> V_307 && V_123 -> V_120 > V_16 ) {
V_141 = 1 ;
break;
}
F_66 ( & V_30 -> V_358 ) ;
if ( ! F_184 ( V_123 ) ) {
F_70 ( & V_30 -> V_358 ) ;
continue;
}
V_10 = (struct V_9 * ) V_123 -> V_52 ;
if ( ! V_10 ) {
F_70 ( & V_30 -> V_358 ) ;
F_38 ( 1 ) ;
continue;
}
if ( V_10 == V_348 ) {
F_70 ( & V_30 -> V_358 ) ;
continue;
}
V_71 = F_242 ( & V_10 -> V_18 ) ;
F_70 ( & V_30 -> V_358 ) ;
if ( ! V_71 )
continue;
V_348 = V_10 ;
V_71 = F_220 ( V_10 , V_165 , & V_314 ) ;
if ( ! V_71 ) {
F_243 ( V_10 ) ;
continue;
}
V_71 = F_235 ( V_10 , V_165 , V_304 , & V_314 ) ;
if ( V_71 ) {
V_141 = 1 ;
F_243 ( V_10 ) ;
break;
}
F_243 ( V_10 ) ;
V_349 = V_304 -> V_306 <= 0 ;
}
F_244 ( & V_351 ) ;
F_71 () ;
}
if ( ! V_352 && ! V_141 ) {
V_352 = 1 ;
V_120 = 0 ;
goto V_356;
}
F_222 ( & V_314 ) ;
return V_71 ;
}
static int F_245 ( struct V_29 * V_17 ,
struct V_43 * V_30 ,
struct V_303 * V_304 ,
T_13 V_359 , void * V_312 ,
void (* F_246)( void * ) )
{
struct V_24 * V_24 = V_30 -> V_31 ;
int V_71 = 0 ;
int V_141 = 0 ;
int V_349 = 0 ;
struct V_350 V_351 ;
int V_133 ;
T_8 V_120 ;
T_8 V_16 ;
int V_352 = 0 ;
int V_353 ;
if ( ! F_247 ( V_24 ) )
return 0 ;
F_239 ( & V_351 , 0 ) ;
if ( V_304 -> V_307 ) {
V_120 = V_30 -> V_311 ;
V_16 = - 1 ;
} else {
V_120 = V_304 -> V_308 >> V_121 ;
V_16 = V_304 -> V_309 >> V_121 ;
V_352 = 1 ;
}
if ( V_304 -> V_320 == V_321 )
V_353 = V_354 ;
else
V_353 = V_355 ;
V_356:
if ( V_304 -> V_320 == V_321 )
F_240 ( V_30 , V_120 , V_16 ) ;
while ( ! V_141 && ! V_349 && ( V_120 <= V_16 ) &&
( V_133 = F_241 ( & V_351 , V_30 , & V_120 , V_353 ,
F_124 ( V_16 - V_120 , ( T_8 ) V_357 - 1 ) + 1 ) ) ) {
unsigned V_134 ;
V_352 = 1 ;
for ( V_134 = 0 ; V_134 < V_133 ; V_134 ++ ) {
struct V_123 * V_123 = V_351 . V_132 [ V_134 ] ;
if ( ! F_229 ( V_123 ) ) {
F_246 ( V_312 ) ;
F_115 ( V_123 ) ;
}
if ( F_171 ( V_123 -> V_30 != V_30 ) ) {
F_113 ( V_123 ) ;
continue;
}
if ( ! V_304 -> V_307 && V_123 -> V_120 > V_16 ) {
V_141 = 1 ;
F_113 ( V_123 ) ;
continue;
}
if ( V_304 -> V_320 != V_360 ) {
if ( F_215 ( V_123 ) )
F_246 ( V_312 ) ;
F_248 ( V_123 ) ;
}
if ( F_215 ( V_123 ) ||
! F_100 ( V_123 ) ) {
F_113 ( V_123 ) ;
continue;
}
V_71 = (* V_359)( V_123 , V_304 , V_312 ) ;
if ( F_171 ( V_71 == V_361 ) ) {
F_113 ( V_123 ) ;
V_71 = 0 ;
}
if ( V_71 )
V_141 = 1 ;
V_349 = V_304 -> V_306 <= 0 ;
}
F_244 ( & V_351 ) ;
F_71 () ;
}
if ( ! V_352 && ! V_141 ) {
V_352 = 1 ;
V_120 = 0 ;
goto V_356;
}
F_249 ( V_24 ) ;
return V_71 ;
}
static void F_250 ( struct V_313 * V_314 )
{
if ( V_314 -> V_40 ) {
int V_259 = V_182 ;
int V_71 ;
if ( V_314 -> V_337 )
V_259 = V_189 ;
V_71 = F_176 ( V_259 , V_314 -> V_40 , 0 , V_314 -> V_215 ) ;
F_68 ( V_71 < 0 ) ;
V_314 -> V_40 = NULL ;
}
}
static T_5 void F_222 ( void * V_312 )
{
struct V_313 * V_314 = V_312 ;
F_250 ( V_314 ) ;
}
int F_251 ( struct V_29 * V_17 , struct V_123 * V_123 ,
T_12 * V_276 ,
struct V_303 * V_304 )
{
int V_71 ;
struct V_313 V_314 = {
. V_40 = NULL ,
. V_17 = V_17 ,
. V_276 = V_276 ,
. V_324 = 0 ,
. V_337 = V_304 -> V_320 == V_321 ,
. V_215 = 0 ,
} ;
V_71 = F_210 ( V_123 , V_304 , & V_314 ) ;
F_250 ( & V_314 ) ;
return V_71 ;
}
int F_252 ( struct V_29 * V_17 , struct V_24 * V_24 ,
T_1 V_15 , T_1 V_16 , T_12 * V_276 ,
int V_362 )
{
int V_71 = 0 ;
struct V_43 * V_30 = V_24 -> V_124 ;
struct V_123 * V_123 ;
unsigned long V_133 = ( V_16 - V_15 + V_143 ) >>
V_121 ;
struct V_313 V_314 = {
. V_40 = NULL ,
. V_17 = V_17 ,
. V_276 = V_276 ,
. V_324 = 1 ,
. V_337 = V_362 == V_321 ,
. V_215 = 0 ,
} ;
struct V_303 V_363 = {
. V_320 = V_362 ,
. V_306 = V_133 * 2 ,
. V_308 = V_15 ,
. V_309 = V_16 + 1 ,
} ;
while ( V_15 <= V_16 ) {
V_123 = F_99 ( V_30 , V_15 >> V_121 ) ;
if ( F_100 ( V_123 ) )
V_71 = F_210 ( V_123 , & V_363 , & V_314 ) ;
else {
if ( V_17 -> V_47 && V_17 -> V_47 -> V_232 )
V_17 -> V_47 -> V_232 ( V_123 , V_15 ,
V_15 + V_143 - 1 ,
NULL , 1 ) ;
F_113 ( V_123 ) ;
}
F_101 ( V_123 ) ;
V_15 += V_143 ;
}
F_250 ( & V_314 ) ;
return V_71 ;
}
int F_253 ( struct V_29 * V_17 ,
struct V_43 * V_30 ,
T_12 * V_276 ,
struct V_303 * V_304 )
{
int V_71 = 0 ;
struct V_313 V_314 = {
. V_40 = NULL ,
. V_17 = V_17 ,
. V_276 = V_276 ,
. V_324 = 0 ,
. V_337 = V_304 -> V_320 == V_321 ,
. V_215 = 0 ,
} ;
V_71 = F_245 ( V_17 , V_30 , V_304 ,
F_210 , & V_314 ,
F_222 ) ;
F_250 ( & V_314 ) ;
return V_71 ;
}
int F_254 ( struct V_29 * V_17 ,
struct V_43 * V_30 ,
struct V_1 * V_132 , unsigned V_133 ,
T_12 V_276 )
{
struct V_40 * V_40 = NULL ;
unsigned V_364 ;
unsigned long V_215 = 0 ;
struct V_123 * V_365 [ 16 ] ;
struct V_123 * V_123 ;
struct V_206 * V_277 = NULL ;
int V_268 = 0 ;
for ( V_364 = 0 ; V_364 < V_133 ; V_364 ++ ) {
V_123 = F_9 ( V_132 -> V_68 , struct V_123 , V_366 ) ;
F_166 ( & V_123 -> V_4 ) ;
F_6 ( & V_123 -> V_366 ) ;
if ( F_255 ( V_123 , V_30 ,
V_123 -> V_120 , V_119 ) ) {
F_101 ( V_123 ) ;
continue;
}
V_365 [ V_268 ++ ] = V_123 ;
if ( V_268 < F_256 ( V_365 ) )
continue;
F_204 ( V_17 , V_365 , V_268 , V_276 , & V_277 ,
& V_40 , 0 , & V_215 , V_302 ) ;
V_268 = 0 ;
}
if ( V_268 )
F_204 ( V_17 , V_365 , V_268 , V_276 , & V_277 ,
& V_40 , 0 , & V_215 , V_302 ) ;
if ( V_277 )
F_159 ( V_277 ) ;
F_68 ( ! F_8 ( V_132 ) ) ;
if ( V_40 )
return F_176 ( V_302 , V_40 , 0 , V_215 ) ;
return 0 ;
}
int F_257 ( struct V_29 * V_17 ,
struct V_123 * V_123 , unsigned long V_58 )
{
struct V_7 * V_93 = NULL ;
T_1 V_15 = F_129 ( V_123 ) ;
T_1 V_16 = V_15 + V_143 - 1 ;
T_9 V_288 = V_123 -> V_30 -> V_31 -> V_32 -> V_289 ;
V_15 += F_198 ( V_58 , V_288 ) ;
if ( V_15 > V_16 )
return 0 ;
F_93 ( V_17 , V_15 , V_16 , 0 , & V_93 ) ;
F_248 ( V_123 ) ;
F_64 ( V_17 , V_15 , V_16 ,
V_118 | V_89 | V_97 |
V_116 ,
1 , 1 , & V_93 , V_119 ) ;
return 0 ;
}
static int F_258 ( struct V_208 * V_367 ,
struct V_29 * V_17 ,
struct V_123 * V_123 , T_3 V_51 )
{
T_1 V_15 = F_129 ( V_123 ) ;
T_1 V_16 = V_15 + V_143 - 1 ;
int V_71 = 1 ;
if ( F_118 ( V_17 , V_15 , V_16 ,
V_75 , 0 , NULL ) )
V_71 = 0 ;
else {
if ( ( V_51 & V_119 ) == V_119 )
V_51 = V_119 ;
V_71 = F_64 ( V_17 , V_15 , V_16 ,
~ ( V_118 | V_368 ) ,
0 , 0 , NULL , V_51 ) ;
if ( V_71 < 0 )
V_71 = 0 ;
else
V_71 = 1 ;
}
return V_71 ;
}
int F_259 ( struct V_208 * V_367 ,
struct V_29 * V_17 , struct V_123 * V_123 ,
T_3 V_51 )
{
struct V_206 * V_207 ;
T_1 V_15 = F_129 ( V_123 ) ;
T_1 V_16 = V_15 + V_143 - 1 ;
if ( ( V_51 & V_101 ) &&
V_123 -> V_30 -> V_31 -> V_248 > 16 * 1024 * 1024 ) {
T_1 V_21 ;
while ( V_15 <= V_16 ) {
V_21 = V_16 - V_15 + 1 ;
F_260 ( & V_367 -> V_49 ) ;
V_207 = F_157 ( V_367 , V_15 , V_21 ) ;
if ( ! V_207 ) {
F_261 ( & V_367 -> V_49 ) ;
break;
}
if ( F_144 ( V_369 , & V_207 -> V_4 ) ||
V_207 -> V_15 != V_15 ) {
F_261 ( & V_367 -> V_49 ) ;
F_159 ( V_207 ) ;
break;
}
if ( ! F_118 ( V_17 , V_207 -> V_15 ,
F_190 ( V_207 ) - 1 ,
V_118 | V_370 ,
0 , NULL ) ) {
F_262 ( V_367 , V_207 ) ;
F_159 ( V_207 ) ;
}
V_15 = F_190 ( V_207 ) ;
F_261 ( & V_367 -> V_49 ) ;
F_159 ( V_207 ) ;
}
}
return F_258 ( V_367 , V_17 , V_123 , V_51 ) ;
}
static struct V_206 * F_263 ( struct V_24 * V_24 ,
T_1 V_58 ,
T_1 V_154 ,
T_12 * V_276 )
{
T_1 V_371 = F_120 ( V_24 ) -> V_57 -> V_371 ;
struct V_206 * V_207 ;
T_1 V_21 ;
if ( V_58 >= V_154 )
return NULL ;
while( 1 ) {
V_21 = V_154 - V_58 ;
if ( V_21 == 0 )
break;
V_21 = F_198 ( V_21 , V_371 ) ;
V_207 = V_276 ( V_24 , NULL , 0 , V_58 , V_21 , 0 ) ;
if ( F_191 ( V_207 ) )
return V_207 ;
if ( ! F_144 ( V_372 , & V_207 -> V_4 ) &&
V_207 -> V_216 != V_296 ) {
return V_207 ;
}
V_58 = F_190 ( V_207 ) ;
F_159 ( V_207 ) ;
if ( V_58 >= V_154 )
break;
}
return NULL ;
}
int F_264 ( struct V_24 * V_24 , struct V_373 * V_374 ,
T_14 V_15 , T_14 V_21 , T_12 * V_276 )
{
int V_71 = 0 ;
T_1 V_375 = V_15 ;
T_1 F_125 = V_15 + V_21 ;
T_15 V_4 = 0 ;
T_15 V_376 ;
T_1 V_154 ;
T_1 V_377 = 0 ;
T_1 V_378 = 0 ;
T_1 V_25 = F_14 ( V_24 ) ;
struct V_379 V_380 ;
struct V_206 * V_207 = NULL ;
struct V_7 * V_93 = NULL ;
struct V_381 * V_382 ;
struct V_383 * V_384 ;
int V_16 = 0 ;
T_1 V_385 = 0 ;
T_1 V_386 = 0 ;
T_1 V_387 = 0 ;
unsigned long V_388 ;
if ( V_21 == 0 )
return - V_389 ;
V_382 = F_265 () ;
if ( ! V_382 )
return - V_35 ;
V_382 -> V_390 = 1 ;
V_15 = F_198 ( V_15 , F_120 ( V_24 ) -> V_57 -> V_371 ) ;
V_21 = F_198 ( V_21 , F_120 ( V_24 ) -> V_57 -> V_371 ) ;
V_71 = F_266 ( NULL , F_120 ( V_24 ) -> V_57 ,
V_382 , F_16 ( V_24 ) , - 1 , 0 ) ;
if ( V_71 < 0 ) {
F_267 ( V_382 ) ;
return V_71 ;
}
F_38 ( ! V_71 ) ;
V_382 -> V_391 [ 0 ] -- ;
V_384 = F_268 ( V_382 -> V_392 [ 0 ] , V_382 -> V_391 [ 0 ] ,
struct V_383 ) ;
F_269 ( V_382 -> V_392 [ 0 ] , & V_380 , V_382 -> V_391 [ 0 ] ) ;
V_376 = F_270 ( & V_380 ) ;
if ( V_380 . V_393 != F_16 ( V_24 ) ||
V_376 != V_394 ) {
V_154 = ( T_1 ) - 1 ;
V_377 = V_25 ;
} else {
V_154 = V_380 . V_58 ;
V_377 = V_154 + 1 ;
}
F_267 ( V_382 ) ;
if ( V_154 < V_25 ) {
V_154 = ( T_1 ) - 1 ;
V_377 = V_25 ;
}
F_93 ( & F_120 ( V_24 ) -> V_146 , V_15 , V_15 + V_21 - 1 , 0 ,
& V_93 ) ;
V_207 = F_263 ( V_24 , V_15 , V_377 ,
V_276 ) ;
if ( ! V_207 )
goto V_103;
if ( F_271 ( V_207 ) ) {
V_71 = F_272 ( V_207 ) ;
goto V_103;
}
while ( ! V_16 ) {
T_1 V_395 = 0 ;
if ( V_207 -> V_15 >= F_125 || F_190 ( V_207 ) < V_375 )
break;
V_385 = F_125 ( V_207 -> V_15 , V_375 ) ;
if ( ! F_144 ( V_217 , & V_207 -> V_4 ) )
V_395 = V_385 - V_207 -> V_15 ;
V_387 = F_190 ( V_207 ) ;
V_386 = V_387 - V_385 ;
V_388 = V_207 -> V_4 ;
V_378 = 0 ;
V_4 = 0 ;
V_375 = F_190 ( V_207 ) ;
if ( V_375 >= F_125 )
V_16 = 1 ;
if ( V_207 -> V_216 == V_396 ) {
V_16 = 1 ;
V_4 |= V_397 ;
} else if ( V_207 -> V_216 == V_297 ) {
V_4 |= ( V_398 |
V_399 ) ;
} else if ( V_207 -> V_216 == V_400 ) {
V_4 |= ( V_401 |
V_402 ) ;
} else {
V_378 = V_207 -> V_216 + V_395 ;
}
if ( F_144 ( V_217 , & V_207 -> V_4 ) )
V_4 |= V_403 ;
F_159 ( V_207 ) ;
V_207 = NULL ;
if ( ( V_385 >= V_154 ) || V_386 == ( T_1 ) - 1 ||
( V_154 == ( T_1 ) - 1 && V_25 <= V_387 ) ) {
V_4 |= V_397 ;
V_16 = 1 ;
}
V_207 = F_263 ( V_24 , V_375 , V_377 ,
V_276 ) ;
if ( F_271 ( V_207 ) ) {
V_71 = F_272 ( V_207 ) ;
goto V_103;
}
if ( ! V_207 ) {
V_4 |= V_397 ;
V_16 = 1 ;
}
V_71 = F_273 ( V_374 , V_385 , V_378 ,
V_386 , V_4 ) ;
if ( V_71 )
goto V_404;
}
V_404:
F_159 ( V_207 ) ;
V_103:
F_96 ( & F_120 ( V_24 ) -> V_146 , V_15 , V_15 + V_21 - 1 ,
& V_93 , V_119 ) ;
return V_71 ;
}
static void F_274 ( struct V_9 * V_10 )
{
F_5 ( & V_10 -> V_13 ) ;
F_12 ( V_22 , V_10 ) ;
}
static int F_275 ( struct V_9 * V_10 )
{
return ( F_11 ( & V_10 -> V_343 ) ||
F_144 ( V_335 , & V_10 -> V_334 ) ||
F_144 ( V_339 , & V_10 -> V_334 ) ) ;
}
static void F_276 ( struct V_9 * V_10 ,
unsigned long V_405 )
{
unsigned long V_120 ;
unsigned long V_197 ;
struct V_123 * V_123 ;
int V_406 = ! F_144 ( V_407 , & V_10 -> V_334 ) ;
F_68 ( F_275 ( V_10 ) ) ;
V_197 = F_149 ( V_10 -> V_15 , V_10 -> V_21 ) ;
V_120 = V_405 + V_197 ;
if ( V_405 >= V_120 )
return;
do {
V_120 -- ;
V_123 = F_150 ( V_10 , V_120 ) ;
if ( V_123 && V_406 ) {
F_66 ( & V_123 -> V_30 -> V_358 ) ;
if ( F_184 ( V_123 ) &&
V_123 -> V_52 == ( unsigned long ) V_10 ) {
F_68 ( F_144 ( V_339 , & V_10 -> V_334 ) ) ;
F_68 ( F_116 ( V_123 ) ) ;
F_68 ( F_215 ( V_123 ) ) ;
F_277 ( V_123 ) ;
F_187 ( V_123 , 0 ) ;
F_101 ( V_123 ) ;
}
F_70 ( & V_123 -> V_30 -> V_358 ) ;
}
if ( V_123 ) {
F_101 ( V_123 ) ;
}
} while ( V_120 != V_405 );
}
static inline void F_278 ( struct V_9 * V_10 )
{
F_276 ( V_10 , 0 ) ;
F_274 ( V_10 ) ;
}
static struct V_9 * F_279 ( struct V_29 * V_17 ,
T_1 V_15 ,
unsigned long V_21 ,
T_3 V_51 )
{
struct V_9 * V_10 = NULL ;
V_10 = F_280 ( V_22 , V_51 ) ;
if ( V_10 == NULL )
return NULL ;
V_10 -> V_15 = V_15 ;
V_10 -> V_21 = V_21 ;
V_10 -> V_17 = V_17 ;
V_10 -> V_334 = 0 ;
F_281 ( & V_10 -> V_49 ) ;
F_33 ( & V_10 -> V_408 , 0 ) ;
F_33 ( & V_10 -> V_409 , 0 ) ;
F_33 ( & V_10 -> V_410 , 0 ) ;
F_33 ( & V_10 -> V_411 , 0 ) ;
F_33 ( & V_10 -> V_412 , 0 ) ;
F_33 ( & V_10 -> V_413 , 0 ) ;
V_10 -> V_414 = 0 ;
F_34 ( & V_10 -> V_415 ) ;
F_34 ( & V_10 -> V_416 ) ;
F_1 ( & V_10 -> V_13 , & V_20 ) ;
F_30 ( & V_10 -> V_338 ) ;
F_33 ( & V_10 -> V_18 , 1 ) ;
F_33 ( & V_10 -> V_343 , 0 ) ;
F_282 ( V_417
> V_418 ) ;
F_68 ( V_21 > V_418 ) ;
return V_10 ;
}
struct V_9 * F_283 ( struct V_9 * V_419 )
{
unsigned long V_134 ;
struct V_123 * V_60 ;
struct V_9 * V_2 ;
unsigned long V_197 = F_149 ( V_419 -> V_15 , V_419 -> V_21 ) ;
V_2 = F_279 ( NULL , V_419 -> V_15 , V_419 -> V_21 , V_119 ) ;
if ( V_2 == NULL )
return NULL ;
for ( V_134 = 0 ; V_134 < V_197 ; V_134 ++ ) {
V_60 = F_284 ( V_119 ) ;
if ( ! V_60 ) {
F_278 ( V_2 ) ;
return NULL ;
}
F_183 ( V_2 , V_60 ) ;
F_38 ( F_116 ( V_60 ) ) ;
F_130 ( V_60 ) ;
V_2 -> V_132 [ V_134 ] = V_60 ;
}
F_285 ( V_2 , V_419 , 0 , 0 , V_419 -> V_21 ) ;
F_226 ( V_420 , & V_2 -> V_334 ) ;
F_226 ( V_407 , & V_2 -> V_334 ) ;
return V_2 ;
}
struct V_9 * F_286 ( T_1 V_15 , unsigned long V_21 )
{
struct V_9 * V_10 ;
unsigned long V_197 = F_149 ( 0 , V_21 ) ;
unsigned long V_134 ;
V_10 = F_279 ( NULL , V_15 , V_21 , V_119 ) ;
if ( ! V_10 )
return NULL ;
for ( V_134 = 0 ; V_134 < V_197 ; V_134 ++ ) {
V_10 -> V_132 [ V_134 ] = F_284 ( V_119 ) ;
if ( ! V_10 -> V_132 [ V_134 ] )
goto V_91;
}
F_287 ( V_10 ) ;
F_288 ( V_10 , 0 ) ;
F_226 ( V_407 , & V_10 -> V_334 ) ;
return V_10 ;
V_91:
for (; V_134 > 0 ; V_134 -- )
F_289 ( V_10 -> V_132 [ V_134 - 1 ] ) ;
F_274 ( V_10 ) ;
return NULL ;
}
static void F_290 ( struct V_9 * V_10 )
{
int V_18 ;
V_18 = F_11 ( & V_10 -> V_18 ) ;
if ( V_18 >= 2 && F_144 ( V_421 , & V_10 -> V_334 ) )
return;
F_66 ( & V_10 -> V_338 ) ;
if ( ! F_291 ( V_421 , & V_10 -> V_334 ) )
F_78 ( & V_10 -> V_18 ) ;
F_70 ( & V_10 -> V_338 ) ;
}
static void F_292 ( struct V_9 * V_10 )
{
unsigned long V_197 , V_134 ;
F_290 ( V_10 ) ;
V_197 = F_149 ( V_10 -> V_15 , V_10 -> V_21 ) ;
for ( V_134 = 0 ; V_134 < V_197 ; V_134 ++ ) {
struct V_123 * V_60 = F_150 ( V_10 , V_134 ) ;
F_293 ( V_60 ) ;
}
}
struct V_9 * F_294 ( struct V_29 * V_17 ,
T_1 V_15 , unsigned long V_21 )
{
unsigned long V_197 = F_149 ( V_15 , V_21 ) ;
unsigned long V_134 ;
unsigned long V_120 = V_15 >> V_121 ;
struct V_9 * V_10 ;
struct V_9 * V_422 = NULL ;
struct V_123 * V_60 ;
struct V_43 * V_30 = V_17 -> V_30 ;
int V_231 = 1 ;
int V_71 ;
F_295 () ;
V_10 = F_296 ( & V_17 -> V_45 , V_15 >> V_121 ) ;
if ( V_10 && F_242 ( & V_10 -> V_18 ) ) {
F_297 () ;
F_292 ( V_10 ) ;
return V_10 ;
}
F_297 () ;
V_10 = F_279 ( V_17 , V_15 , V_21 , V_119 ) ;
if ( ! V_10 )
return NULL ;
for ( V_134 = 0 ; V_134 < V_197 ; V_134 ++ , V_120 ++ ) {
V_60 = F_298 ( V_30 , V_120 , V_119 ) ;
if ( ! V_60 )
goto V_423;
F_66 ( & V_30 -> V_358 ) ;
if ( F_184 ( V_60 ) ) {
V_422 = (struct V_9 * ) V_60 -> V_52 ;
if ( F_242 ( & V_422 -> V_18 ) ) {
F_70 ( & V_30 -> V_358 ) ;
F_113 ( V_60 ) ;
F_101 ( V_60 ) ;
F_292 ( V_422 ) ;
goto V_423;
}
F_277 ( V_60 ) ;
F_38 ( F_116 ( V_60 ) ) ;
F_101 ( V_60 ) ;
}
F_183 ( V_10 , V_60 ) ;
F_70 ( & V_30 -> V_358 ) ;
F_38 ( F_116 ( V_60 ) ) ;
F_293 ( V_60 ) ;
V_10 -> V_132 [ V_134 ] = V_60 ;
if ( ! F_193 ( V_60 ) )
V_231 = 0 ;
}
if ( V_231 )
F_226 ( V_420 , & V_10 -> V_334 ) ;
V_100:
V_71 = F_299 ( V_119 & ~ V_424 ) ;
if ( V_71 )
goto V_423;
F_66 ( & V_17 -> V_50 ) ;
V_71 = F_300 ( & V_17 -> V_45 , V_15 >> V_121 , V_10 ) ;
if ( V_71 == - V_81 ) {
V_422 = F_296 ( & V_17 -> V_45 ,
V_15 >> V_121 ) ;
if ( ! F_242 ( & V_422 -> V_18 ) ) {
F_70 ( & V_17 -> V_50 ) ;
F_301 () ;
V_422 = NULL ;
goto V_100;
}
F_70 ( & V_17 -> V_50 ) ;
F_301 () ;
F_292 ( V_422 ) ;
goto V_423;
}
F_290 ( V_10 ) ;
F_70 ( & V_17 -> V_50 ) ;
F_301 () ;
F_302 ( V_10 -> V_132 [ 0 ] ) ;
for ( V_134 = 1 ; V_134 < V_197 ; V_134 ++ ) {
V_60 = F_150 ( V_10 , V_134 ) ;
F_303 ( V_60 ) ;
F_113 ( V_60 ) ;
}
F_113 ( V_10 -> V_132 [ 0 ] ) ;
return V_10 ;
V_423:
for ( V_134 = 0 ; V_134 < V_197 ; V_134 ++ ) {
if ( V_10 -> V_132 [ V_134 ] )
F_113 ( V_10 -> V_132 [ V_134 ] ) ;
}
F_38 ( ! F_37 ( & V_10 -> V_18 ) ) ;
F_278 ( V_10 ) ;
return V_422 ;
}
struct V_9 * F_304 ( struct V_29 * V_17 ,
T_1 V_15 , unsigned long V_21 )
{
struct V_9 * V_10 ;
F_295 () ;
V_10 = F_296 ( & V_17 -> V_45 , V_15 >> V_121 ) ;
if ( V_10 && F_242 ( & V_10 -> V_18 ) ) {
F_297 () ;
F_292 ( V_10 ) ;
return V_10 ;
}
F_297 () ;
return NULL ;
}
static inline void F_305 ( struct V_425 * V_3 )
{
struct V_9 * V_10 =
F_306 ( V_3 , struct V_9 , V_425 ) ;
F_274 ( V_10 ) ;
}
static int F_307 ( struct V_9 * V_10 )
{
F_38 ( F_11 ( & V_10 -> V_18 ) == 0 ) ;
if ( F_37 ( & V_10 -> V_18 ) ) {
if ( F_144 ( V_407 , & V_10 -> V_334 ) ) {
F_70 ( & V_10 -> V_338 ) ;
} else {
struct V_29 * V_17 = V_10 -> V_17 ;
F_70 ( & V_10 -> V_338 ) ;
F_66 ( & V_17 -> V_50 ) ;
F_308 ( & V_17 -> V_45 ,
V_10 -> V_15 >> V_121 ) ;
F_70 ( & V_17 -> V_50 ) ;
}
F_276 ( V_10 , 0 ) ;
F_309 ( & V_10 -> V_425 , F_305 ) ;
return 1 ;
}
F_70 ( & V_10 -> V_338 ) ;
return 0 ;
}
void F_243 ( struct V_9 * V_10 )
{
int V_18 ;
int V_426 ;
if ( ! V_10 )
return;
while ( 1 ) {
V_18 = F_11 ( & V_10 -> V_18 ) ;
if ( V_18 <= 3 )
break;
V_426 = F_310 ( & V_10 -> V_18 , V_18 , V_18 - 1 ) ;
if ( V_426 == V_18 )
return;
}
F_66 ( & V_10 -> V_338 ) ;
if ( F_11 ( & V_10 -> V_18 ) == 2 &&
F_144 ( V_407 , & V_10 -> V_334 ) )
F_67 ( & V_10 -> V_18 ) ;
if ( F_11 ( & V_10 -> V_18 ) == 2 &&
F_144 ( V_427 , & V_10 -> V_334 ) &&
! F_275 ( V_10 ) &&
F_225 ( V_421 , & V_10 -> V_334 ) )
F_67 ( & V_10 -> V_18 ) ;
F_307 ( V_10 ) ;
}
void F_311 ( struct V_9 * V_10 )
{
if ( ! V_10 )
return;
F_66 ( & V_10 -> V_338 ) ;
F_226 ( V_427 , & V_10 -> V_334 ) ;
if ( F_11 ( & V_10 -> V_18 ) == 2 && ! F_275 ( V_10 ) &&
F_225 ( V_421 , & V_10 -> V_334 ) )
F_67 ( & V_10 -> V_18 ) ;
F_307 ( V_10 ) ;
}
void F_312 ( struct V_9 * V_10 )
{
unsigned long V_134 ;
unsigned long V_197 ;
struct V_123 * V_123 ;
V_197 = F_149 ( V_10 -> V_15 , V_10 -> V_21 ) ;
for ( V_134 = 0 ; V_134 < V_197 ; V_134 ++ ) {
V_123 = F_150 ( V_10 , V_134 ) ;
if ( ! F_116 ( V_123 ) )
continue;
F_115 ( V_123 ) ;
F_38 ( ! F_184 ( V_123 ) ) ;
F_100 ( V_123 ) ;
F_313 ( & V_123 -> V_30 -> V_428 ) ;
if ( ! F_116 ( V_123 ) ) {
F_314 ( & V_123 -> V_30 -> V_429 ,
F_315 ( V_123 ) ,
V_355 ) ;
}
F_316 ( & V_123 -> V_30 -> V_428 ) ;
F_213 ( V_123 ) ;
F_113 ( V_123 ) ;
}
F_38 ( F_11 ( & V_10 -> V_18 ) == 0 ) ;
}
int F_317 ( struct V_9 * V_10 )
{
unsigned long V_134 ;
unsigned long V_197 ;
int V_430 = 0 ;
F_290 ( V_10 ) ;
V_430 = F_291 ( V_339 , & V_10 -> V_334 ) ;
V_197 = F_149 ( V_10 -> V_15 , V_10 -> V_21 ) ;
F_38 ( F_11 ( & V_10 -> V_18 ) == 0 ) ;
F_38 ( ! F_144 ( V_421 , & V_10 -> V_334 ) ) ;
for ( V_134 = 0 ; V_134 < V_197 ; V_134 ++ )
F_318 ( F_150 ( V_10 , V_134 ) ) ;
return V_430 ;
}
int F_319 ( struct V_9 * V_10 )
{
unsigned long V_134 ;
struct V_123 * V_123 ;
unsigned long V_197 ;
F_231 ( V_420 , & V_10 -> V_334 ) ;
V_197 = F_149 ( V_10 -> V_15 , V_10 -> V_21 ) ;
for ( V_134 = 0 ; V_134 < V_197 ; V_134 ++ ) {
V_123 = F_150 ( V_10 , V_134 ) ;
if ( V_123 )
F_163 ( V_123 ) ;
}
return 0 ;
}
int F_287 ( struct V_9 * V_10 )
{
unsigned long V_134 ;
struct V_123 * V_123 ;
unsigned long V_197 ;
F_226 ( V_420 , & V_10 -> V_334 ) ;
V_197 = F_149 ( V_10 -> V_15 , V_10 -> V_21 ) ;
for ( V_134 = 0 ; V_134 < V_197 ; V_134 ++ ) {
V_123 = F_150 ( V_10 , V_134 ) ;
F_130 ( V_123 ) ;
}
return 0 ;
}
int F_320 ( struct V_9 * V_10 )
{
return F_144 ( V_420 , & V_10 -> V_334 ) ;
}
int F_321 ( struct V_29 * V_17 ,
struct V_9 * V_10 , T_1 V_15 , int V_105 ,
T_12 * V_276 , int V_168 )
{
unsigned long V_134 ;
unsigned long V_431 ;
struct V_123 * V_123 ;
int V_91 ;
int V_71 = 0 ;
int V_432 = 0 ;
int V_433 = 1 ;
unsigned long V_197 ;
unsigned long V_434 = 0 ;
struct V_40 * V_40 = NULL ;
unsigned long V_215 = 0 ;
if ( F_144 ( V_420 , & V_10 -> V_334 ) )
return 0 ;
if ( V_15 ) {
F_38 ( V_15 < V_10 -> V_15 ) ;
V_431 = ( V_15 >> V_121 ) -
( V_10 -> V_15 >> V_121 ) ;
} else {
V_431 = 0 ;
}
V_197 = F_149 ( V_10 -> V_15 , V_10 -> V_21 ) ;
for ( V_134 = V_431 ; V_134 < V_197 ; V_134 ++ ) {
V_123 = F_150 ( V_10 , V_134 ) ;
if ( V_105 == V_435 ) {
if ( ! F_229 ( V_123 ) )
goto V_436;
} else {
F_115 ( V_123 ) ;
}
V_432 ++ ;
if ( ! F_193 ( V_123 ) ) {
V_434 ++ ;
V_433 = 0 ;
}
}
if ( V_433 ) {
if ( V_431 == 0 )
F_226 ( V_420 , & V_10 -> V_334 ) ;
goto V_436;
}
F_231 ( V_344 , & V_10 -> V_334 ) ;
V_10 -> V_437 = 0 ;
F_33 ( & V_10 -> V_343 , V_434 ) ;
for ( V_134 = V_431 ; V_134 < V_197 ; V_134 ++ ) {
V_123 = F_150 ( V_10 , V_134 ) ;
if ( ! F_193 ( V_123 ) ) {
F_213 ( V_123 ) ;
V_91 = F_205 ( V_17 , V_123 ,
V_276 , & V_40 ,
V_168 , & V_215 ,
V_302 | V_345 ) ;
if ( V_91 )
V_71 = V_91 ;
} else {
F_113 ( V_123 ) ;
}
}
if ( V_40 ) {
V_91 = F_176 ( V_302 | V_345 , V_40 , V_168 ,
V_215 ) ;
if ( V_91 )
return V_91 ;
}
if ( V_71 || V_105 != V_438 )
return V_71 ;
for ( V_134 = V_431 ; V_134 < V_197 ; V_134 ++ ) {
V_123 = F_150 ( V_10 , V_134 ) ;
F_322 ( V_123 ) ;
if ( ! F_193 ( V_123 ) )
V_71 = - V_179 ;
}
return V_71 ;
V_436:
V_134 = V_431 ;
while ( V_432 > 0 ) {
V_123 = F_150 ( V_10 , V_134 ) ;
V_134 ++ ;
F_113 ( V_123 ) ;
V_432 -- ;
}
return V_71 ;
}
void F_323 ( struct V_9 * V_10 , void * V_439 ,
unsigned long V_15 ,
unsigned long V_21 )
{
T_9 V_280 ;
T_9 V_58 ;
struct V_123 * V_123 ;
char * V_440 ;
char * V_441 = ( char * ) V_439 ;
T_9 V_442 = V_10 -> V_15 & ( ( T_1 ) V_143 - 1 ) ;
unsigned long V_134 = ( V_442 + V_15 ) >> V_121 ;
F_38 ( V_15 > V_10 -> V_21 ) ;
F_38 ( V_15 + V_21 > V_10 -> V_15 + V_10 -> V_21 ) ;
V_58 = ( V_442 + V_15 ) & ( V_143 - 1 ) ;
while ( V_21 > 0 ) {
V_123 = F_150 ( V_10 , V_134 ) ;
V_280 = F_124 ( V_21 , ( V_143 - V_58 ) ) ;
V_440 = F_324 ( V_123 ) ;
memcpy ( V_441 , V_440 + V_58 , V_280 ) ;
V_441 += V_280 ;
V_21 -= V_280 ;
V_58 = 0 ;
V_134 ++ ;
}
}
int F_325 ( struct V_9 * V_10 , unsigned long V_15 ,
unsigned long V_443 , char * * V_367 ,
unsigned long * V_444 ,
unsigned long * V_445 )
{
T_9 V_58 = V_15 & ( V_143 - 1 ) ;
char * V_440 ;
struct V_123 * V_60 ;
T_9 V_442 = V_10 -> V_15 & ( ( T_1 ) V_143 - 1 ) ;
unsigned long V_134 = ( V_442 + V_15 ) >> V_121 ;
unsigned long V_446 = ( V_442 + V_15 + V_443 - 1 ) >>
V_121 ;
if ( V_134 != V_446 )
return - V_389 ;
if ( V_134 == 0 ) {
V_58 = V_442 ;
* V_444 = 0 ;
} else {
V_58 = 0 ;
* V_444 = ( ( T_1 ) V_134 << V_121 ) - V_442 ;
}
if ( V_15 + V_443 > V_10 -> V_21 ) {
F_54 ( 1 , V_14 L_33
L_34 ,
V_10 -> V_15 , V_10 -> V_21 , V_15 , V_443 ) ;
return - V_389 ;
}
V_60 = F_150 ( V_10 , V_134 ) ;
V_440 = F_324 ( V_60 ) ;
* V_367 = V_440 + V_58 ;
* V_445 = V_143 - V_58 ;
return 0 ;
}
int F_326 ( struct V_9 * V_10 , const void * V_447 ,
unsigned long V_15 ,
unsigned long V_21 )
{
T_9 V_280 ;
T_9 V_58 ;
struct V_123 * V_123 ;
char * V_440 ;
char * V_448 = ( char * ) V_447 ;
T_9 V_442 = V_10 -> V_15 & ( ( T_1 ) V_143 - 1 ) ;
unsigned long V_134 = ( V_442 + V_15 ) >> V_121 ;
int V_71 = 0 ;
F_38 ( V_15 > V_10 -> V_21 ) ;
F_38 ( V_15 + V_21 > V_10 -> V_15 + V_10 -> V_21 ) ;
V_58 = ( V_442 + V_15 ) & ( V_143 - 1 ) ;
while ( V_21 > 0 ) {
V_123 = F_150 ( V_10 , V_134 ) ;
V_280 = F_124 ( V_21 , ( V_143 - V_58 ) ) ;
V_440 = F_324 ( V_123 ) ;
V_71 = memcmp ( V_448 , V_440 + V_58 , V_280 ) ;
if ( V_71 )
break;
V_448 += V_280 ;
V_21 -= V_280 ;
V_58 = 0 ;
V_134 ++ ;
}
return V_71 ;
}
void F_327 ( struct V_9 * V_10 , const void * V_449 ,
unsigned long V_15 , unsigned long V_21 )
{
T_9 V_280 ;
T_9 V_58 ;
struct V_123 * V_123 ;
char * V_440 ;
char * V_419 = ( char * ) V_449 ;
T_9 V_442 = V_10 -> V_15 & ( ( T_1 ) V_143 - 1 ) ;
unsigned long V_134 = ( V_442 + V_15 ) >> V_121 ;
F_38 ( V_15 > V_10 -> V_21 ) ;
F_38 ( V_15 + V_21 > V_10 -> V_15 + V_10 -> V_21 ) ;
V_58 = ( V_442 + V_15 ) & ( V_143 - 1 ) ;
while ( V_21 > 0 ) {
V_123 = F_150 ( V_10 , V_134 ) ;
F_38 ( ! F_193 ( V_123 ) ) ;
V_280 = F_124 ( V_21 , V_143 - V_58 ) ;
V_440 = F_324 ( V_123 ) ;
memcpy ( V_440 + V_58 , V_419 , V_280 ) ;
V_419 += V_280 ;
V_21 -= V_280 ;
V_58 = 0 ;
V_134 ++ ;
}
}
void F_328 ( struct V_9 * V_10 , char V_450 ,
unsigned long V_15 , unsigned long V_21 )
{
T_9 V_280 ;
T_9 V_58 ;
struct V_123 * V_123 ;
char * V_440 ;
T_9 V_442 = V_10 -> V_15 & ( ( T_1 ) V_143 - 1 ) ;
unsigned long V_134 = ( V_442 + V_15 ) >> V_121 ;
F_38 ( V_15 > V_10 -> V_21 ) ;
F_38 ( V_15 + V_21 > V_10 -> V_15 + V_10 -> V_21 ) ;
V_58 = ( V_442 + V_15 ) & ( V_143 - 1 ) ;
while ( V_21 > 0 ) {
V_123 = F_150 ( V_10 , V_134 ) ;
F_38 ( ! F_193 ( V_123 ) ) ;
V_280 = F_124 ( V_21 , V_143 - V_58 ) ;
V_440 = F_324 ( V_123 ) ;
memset ( V_440 + V_58 , V_450 , V_280 ) ;
V_21 -= V_280 ;
V_58 = 0 ;
V_134 ++ ;
}
}
void F_285 ( struct V_9 * V_441 , struct V_9 * V_419 ,
unsigned long V_451 , unsigned long V_452 ,
unsigned long V_21 )
{
T_1 V_453 = V_441 -> V_21 ;
T_9 V_280 ;
T_9 V_58 ;
struct V_123 * V_123 ;
char * V_440 ;
T_9 V_442 = V_441 -> V_15 & ( ( T_1 ) V_143 - 1 ) ;
unsigned long V_134 = ( V_442 + V_451 ) >> V_121 ;
F_38 ( V_419 -> V_21 != V_453 ) ;
V_58 = ( V_442 + V_451 ) &
( V_143 - 1 ) ;
while ( V_21 > 0 ) {
V_123 = F_150 ( V_441 , V_134 ) ;
F_38 ( ! F_193 ( V_123 ) ) ;
V_280 = F_124 ( V_21 , ( unsigned long ) ( V_143 - V_58 ) ) ;
V_440 = F_324 ( V_123 ) ;
F_323 ( V_419 , V_440 + V_58 , V_452 , V_280 ) ;
V_452 += V_280 ;
V_21 -= V_280 ;
V_58 = 0 ;
V_134 ++ ;
}
}
static void F_329 ( struct V_123 * V_454 , struct V_123 * V_455 ,
unsigned long V_456 , unsigned long V_457 ,
unsigned long V_21 )
{
char * V_458 = F_324 ( V_454 ) ;
if ( V_454 == V_455 ) {
memmove ( V_458 + V_456 , V_458 + V_457 , V_21 ) ;
} else {
char * V_459 = F_324 ( V_455 ) ;
char * V_60 = V_458 + V_456 + V_21 ;
char * V_460 = V_459 + V_457 + V_21 ;
while ( V_21 -- )
* -- V_60 = * -- V_460 ;
}
}
static inline bool F_330 ( unsigned long V_419 , unsigned long V_441 , unsigned long V_21 )
{
unsigned long V_461 = ( V_419 > V_441 ) ? V_419 - V_441 : V_441 - V_419 ;
return V_461 < V_21 ;
}
static void F_331 ( struct V_123 * V_454 , struct V_123 * V_455 ,
unsigned long V_456 , unsigned long V_457 ,
unsigned long V_21 )
{
char * V_458 = F_324 ( V_454 ) ;
char * V_459 ;
int V_462 = 0 ;
if ( V_454 != V_455 ) {
V_459 = F_324 ( V_455 ) ;
} else {
V_459 = V_458 ;
if ( F_330 ( V_457 , V_456 , V_21 ) )
V_462 = 1 ;
}
if ( V_462 )
memmove ( V_458 + V_456 , V_459 + V_457 , V_21 ) ;
else
memcpy ( V_458 + V_456 , V_459 + V_457 , V_21 ) ;
}
void F_332 ( struct V_9 * V_441 , unsigned long V_451 ,
unsigned long V_452 , unsigned long V_21 )
{
T_9 V_280 ;
T_9 V_463 ;
T_9 V_464 ;
T_9 V_442 = V_441 -> V_15 & ( ( T_1 ) V_143 - 1 ) ;
unsigned long V_465 ;
unsigned long V_466 ;
if ( V_452 + V_21 > V_441 -> V_21 ) {
F_10 ( V_14 L_35
L_36 , V_452 , V_21 , V_441 -> V_21 ) ;
F_68 ( 1 ) ;
}
if ( V_451 + V_21 > V_441 -> V_21 ) {
F_10 ( V_14 L_37
L_36 , V_451 , V_21 , V_441 -> V_21 ) ;
F_68 ( 1 ) ;
}
while ( V_21 > 0 ) {
V_463 = ( V_442 + V_451 ) &
( V_143 - 1 ) ;
V_464 = ( V_442 + V_452 ) &
( V_143 - 1 ) ;
V_465 = ( V_442 + V_451 ) >> V_121 ;
V_466 = ( V_442 + V_452 ) >> V_121 ;
V_280 = F_124 ( V_21 , ( unsigned long ) ( V_143 -
V_464 ) ) ;
V_280 = F_112 (unsigned long, cur,
(unsigned long)(PAGE_CACHE_SIZE - dst_off_in_page)) ;
F_331 ( F_150 ( V_441 , V_465 ) ,
F_150 ( V_441 , V_466 ) ,
V_463 , V_464 , V_280 ) ;
V_452 += V_280 ;
V_451 += V_280 ;
V_21 -= V_280 ;
}
}
void F_333 ( struct V_9 * V_441 , unsigned long V_451 ,
unsigned long V_452 , unsigned long V_21 )
{
T_9 V_280 ;
T_9 V_463 ;
T_9 V_464 ;
unsigned long V_467 = V_451 + V_21 - 1 ;
unsigned long V_468 = V_452 + V_21 - 1 ;
T_9 V_442 = V_441 -> V_15 & ( ( T_1 ) V_143 - 1 ) ;
unsigned long V_465 ;
unsigned long V_466 ;
if ( V_452 + V_21 > V_441 -> V_21 ) {
F_10 ( V_14 L_35
L_38 , V_452 , V_21 , V_441 -> V_21 ) ;
F_68 ( 1 ) ;
}
if ( V_451 + V_21 > V_441 -> V_21 ) {
F_10 ( V_14 L_37
L_38 , V_451 , V_21 , V_441 -> V_21 ) ;
F_68 ( 1 ) ;
}
if ( V_451 < V_452 ) {
F_332 ( V_441 , V_451 , V_452 , V_21 ) ;
return;
}
while ( V_21 > 0 ) {
V_465 = ( V_442 + V_467 ) >> V_121 ;
V_466 = ( V_442 + V_468 ) >> V_121 ;
V_463 = ( V_442 + V_467 ) &
( V_143 - 1 ) ;
V_464 = ( V_442 + V_468 ) &
( V_143 - 1 ) ;
V_280 = F_112 (unsigned long, len, src_off_in_page + 1 ) ;
V_280 = F_124 ( V_280 , V_463 + 1 ) ;
F_329 ( F_150 ( V_441 , V_465 ) ,
F_150 ( V_441 , V_466 ) ,
V_463 - V_280 + 1 ,
V_464 - V_280 + 1 , V_280 ) ;
V_467 -= V_280 ;
V_468 -= V_280 ;
V_21 -= V_280 ;
}
}
int F_334 ( struct V_123 * V_123 )
{
struct V_9 * V_10 ;
F_66 ( & V_123 -> V_30 -> V_358 ) ;
if ( ! F_184 ( V_123 ) ) {
F_70 ( & V_123 -> V_30 -> V_358 ) ;
return 1 ;
}
V_10 = (struct V_9 * ) V_123 -> V_52 ;
F_68 ( ! V_10 ) ;
F_66 ( & V_10 -> V_338 ) ;
if ( F_11 ( & V_10 -> V_18 ) != 1 || F_275 ( V_10 ) ) {
F_70 ( & V_10 -> V_338 ) ;
F_70 ( & V_123 -> V_30 -> V_358 ) ;
return 0 ;
}
F_70 ( & V_123 -> V_30 -> V_358 ) ;
if ( ! F_225 ( V_421 , & V_10 -> V_334 ) ) {
F_70 ( & V_10 -> V_338 ) ;
return 0 ;
}
return F_307 ( V_10 ) ;
}
