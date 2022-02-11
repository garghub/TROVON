static inline bool F_1 ( const struct V_1 * V_2 )
{
return ! F_2 ( & V_2 -> V_3 ) ;
}
static inline
void F_3 ( struct V_4 * V_5 , struct V_4 * V_6 )
{
unsigned long V_7 ;
F_4 ( & V_8 , V_7 ) ;
F_5 ( V_5 , V_6 ) ;
F_6 ( & V_8 , V_7 ) ;
}
static inline
void F_7 ( struct V_4 * V_9 )
{
unsigned long V_7 ;
F_4 ( & V_8 , V_7 ) ;
F_8 ( V_9 ) ;
F_6 ( & V_8 , V_7 ) ;
}
static inline
void F_9 ( void )
{
struct V_1 * V_2 ;
struct V_10 * V_11 ;
while ( ! F_10 ( & V_12 ) ) {
V_2 = F_11 ( V_12 . V_13 , struct V_1 , V_14 ) ;
F_12 ( L_1 ,
V_2 -> V_15 , V_2 -> V_16 , V_2 -> V_2 ,
F_1 ( V_2 ) ,
F_13 ( & V_2 -> V_17 ) ) ;
F_8 ( & V_2 -> V_14 ) ;
F_14 ( V_18 , V_2 ) ;
}
while ( ! F_10 ( & V_19 ) ) {
V_11 = F_11 ( V_19 . V_13 , struct V_10 , V_14 ) ;
F_12 ( L_2 ,
V_11 -> V_15 , V_11 -> V_20 , F_13 ( & V_11 -> V_17 ) ) ;
F_8 ( & V_11 -> V_14 ) ;
F_14 ( V_21 , V_11 ) ;
}
}
static inline void F_15 ( const char * V_22 ,
struct V_23 * V_24 , T_1 V_15 , T_1 V_16 )
{
struct V_25 * V_25 ;
T_1 V_26 ;
if ( ! V_24 -> V_27 )
return;
V_25 = V_24 -> V_27 -> V_28 ;
V_26 = F_16 ( V_25 ) ;
if ( V_16 >= V_29 && ( V_16 % 2 ) == 0 && V_16 != V_26 - 1 ) {
F_17 ( F_18 ( V_25 ) -> V_30 -> V_31 ,
L_3 ,
V_22 , F_19 ( F_18 ( V_25 ) ) , V_26 , V_15 , V_16 ) ;
}
}
static void F_20 ( struct V_1 * V_2 , unsigned V_32 ,
struct V_33 * V_34 ,
int V_35 )
{
int V_36 ;
if ( ! V_34 )
return;
if ( V_35 && ( V_2 -> V_2 & V_32 ) == V_32 )
return;
if ( ! V_35 && ( V_2 -> V_2 & V_32 ) == 0 )
return;
V_34 -> V_37 += V_2 -> V_16 - V_2 -> V_15 + 1 ;
V_36 = F_21 ( & V_34 -> V_38 , V_2 -> V_15 , V_2 -> V_16 ,
V_39 ) ;
F_22 ( V_36 < 0 ) ;
}
static inline struct V_40 *
F_23 ( struct V_23 * V_24 )
{
if ( ! V_24 -> V_27 )
return NULL ;
return F_24 ( V_24 -> V_27 -> V_28 -> V_41 ) ;
}
int T_2 F_25 ( void )
{
V_18 = F_26 ( L_4 ,
sizeof( struct V_1 ) , 0 ,
V_42 , NULL ) ;
if ( ! V_18 )
return - V_43 ;
V_21 = F_26 ( L_5 ,
sizeof( struct V_10 ) , 0 ,
V_42 , NULL ) ;
if ( ! V_21 )
goto V_44;
V_45 = F_27 ( V_46 ,
F_28 ( struct V_47 , V_48 ) ) ;
if ( ! V_45 )
goto V_49;
if ( F_29 ( V_45 , V_46 ) )
goto V_50;
return 0 ;
V_50:
F_30 ( V_45 ) ;
V_45 = NULL ;
V_49:
F_31 ( V_21 ) ;
V_21 = NULL ;
V_44:
F_31 ( V_18 ) ;
V_18 = NULL ;
return - V_43 ;
}
void F_32 ( void )
{
F_9 () ;
F_33 () ;
F_31 ( V_18 ) ;
F_31 ( V_21 ) ;
if ( V_45 )
F_30 ( V_45 ) ;
}
void F_34 ( struct V_23 * V_24 ,
struct V_51 * V_27 )
{
V_24 -> V_2 = V_52 ;
V_24 -> V_53 = NULL ;
V_24 -> V_54 = 0 ;
F_35 ( & V_24 -> V_55 ) ;
V_24 -> V_27 = V_27 ;
}
static struct V_1 * F_36 ( T_3 V_56 )
{
struct V_1 * V_2 ;
V_56 &= ~ ( V_57 | V_58 ) ;
V_2 = F_37 ( V_18 , V_56 ) ;
if ( ! V_2 )
return V_2 ;
V_2 -> V_2 = 0 ;
V_2 -> V_59 = NULL ;
F_38 ( & V_2 -> V_3 ) ;
F_3 ( & V_2 -> V_14 , & V_12 ) ;
F_39 ( & V_2 -> V_17 , 1 ) ;
F_40 ( & V_2 -> V_60 ) ;
F_41 ( V_2 , V_56 , V_61 ) ;
return V_2 ;
}
void F_42 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( F_43 ( & V_2 -> V_17 ) ) {
F_44 ( F_1 ( V_2 ) ) ;
F_7 ( & V_2 -> V_14 ) ;
F_45 ( V_2 , V_61 ) ;
F_14 ( V_18 , V_2 ) ;
}
}
static struct V_3 * F_46 ( struct V_62 * V_30 ,
struct V_3 * V_63 ,
T_1 V_64 ,
struct V_3 * V_65 ,
struct V_3 * * * V_66 ,
struct V_3 * * V_67 )
{
struct V_3 * * V_68 ;
struct V_3 * V_69 = NULL ;
struct V_70 * V_9 ;
if ( V_66 && V_67 ) {
V_68 = * V_66 ;
V_69 = * V_67 ;
goto V_71;
}
V_68 = V_63 ? & V_63 : & V_30 -> V_3 ;
while ( * V_68 ) {
V_69 = * V_68 ;
V_9 = F_47 ( V_69 , struct V_70 , V_3 ) ;
if ( V_64 < V_9 -> V_15 )
V_68 = & ( * V_68 ) -> V_72 ;
else if ( V_64 > V_9 -> V_16 )
V_68 = & ( * V_68 ) -> V_73 ;
else
return V_69 ;
}
V_71:
F_48 ( V_65 , V_69 , V_68 ) ;
F_49 ( V_65 , V_30 ) ;
return NULL ;
}
static struct V_3 * F_50 ( struct V_23 * V_24 , T_1 V_64 ,
struct V_3 * * V_74 ,
struct V_3 * * V_75 ,
struct V_3 * * * V_76 ,
struct V_3 * * V_77 )
{
struct V_62 * V_30 = & V_24 -> V_2 ;
struct V_3 * * V_78 = & V_30 -> V_3 ;
struct V_3 * V_79 = NULL ;
struct V_3 * V_80 = NULL ;
struct V_70 * V_9 ;
struct V_70 * V_81 = NULL ;
while ( * V_78 ) {
V_79 = * V_78 ;
V_9 = F_47 ( V_79 , struct V_70 , V_3 ) ;
V_81 = V_9 ;
if ( V_64 < V_9 -> V_15 )
V_78 = & ( * V_78 ) -> V_72 ;
else if ( V_64 > V_9 -> V_16 )
V_78 = & ( * V_78 ) -> V_73 ;
else
return * V_78 ;
}
if ( V_76 )
* V_76 = V_78 ;
if ( V_77 )
* V_77 = V_79 ;
if ( V_74 ) {
V_80 = V_79 ;
while ( V_79 && V_64 > V_81 -> V_16 ) {
V_79 = F_51 ( V_79 ) ;
V_81 = F_47 ( V_79 , struct V_70 , V_3 ) ;
}
* V_74 = V_79 ;
V_79 = V_80 ;
}
if ( V_75 ) {
V_81 = F_47 ( V_79 , struct V_70 , V_3 ) ;
while ( V_79 && V_64 < V_81 -> V_15 ) {
V_79 = F_52 ( V_79 ) ;
V_81 = F_47 ( V_79 , struct V_70 , V_3 ) ;
}
* V_75 = V_79 ;
}
return NULL ;
}
static inline struct V_3 *
F_53 ( struct V_23 * V_24 ,
T_1 V_64 ,
struct V_3 * * * V_76 ,
struct V_3 * * V_77 )
{
struct V_3 * V_79 = NULL ;
struct V_3 * V_36 ;
V_36 = F_50 ( V_24 , V_64 , & V_79 , NULL , V_76 , V_77 ) ;
if ( ! V_36 )
return V_79 ;
return V_36 ;
}
static inline struct V_3 * F_54 ( struct V_23 * V_24 ,
T_1 V_64 )
{
return F_53 ( V_24 , V_64 , NULL , NULL ) ;
}
static void F_55 ( struct V_23 * V_24 , struct V_1 * V_5 ,
struct V_1 * V_82 )
{
if ( V_24 -> V_53 && V_24 -> V_53 -> V_83 )
V_24 -> V_53 -> V_83 ( V_24 -> V_27 -> V_28 , V_5 ,
V_82 ) ;
}
static void F_56 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_1 * V_82 ;
struct V_3 * V_84 ;
if ( V_2 -> V_2 & ( V_85 | V_86 ) )
return;
V_84 = F_52 ( & V_2 -> V_3 ) ;
if ( V_84 ) {
V_82 = F_47 ( V_84 , struct V_1 , V_3 ) ;
if ( V_82 -> V_16 == V_2 -> V_15 - 1 &&
V_82 -> V_2 == V_2 -> V_2 ) {
F_55 ( V_24 , V_2 , V_82 ) ;
V_2 -> V_15 = V_82 -> V_15 ;
F_57 ( & V_82 -> V_3 , & V_24 -> V_2 ) ;
F_38 ( & V_82 -> V_3 ) ;
F_42 ( V_82 ) ;
}
}
V_84 = F_51 ( & V_2 -> V_3 ) ;
if ( V_84 ) {
V_82 = F_47 ( V_84 , struct V_1 , V_3 ) ;
if ( V_82 -> V_15 == V_2 -> V_16 + 1 &&
V_82 -> V_2 == V_2 -> V_2 ) {
F_55 ( V_24 , V_2 , V_82 ) ;
V_2 -> V_16 = V_82 -> V_16 ;
F_57 ( & V_82 -> V_3 , & V_24 -> V_2 ) ;
F_38 ( & V_82 -> V_3 ) ;
F_42 ( V_82 ) ;
}
}
}
static void F_58 ( struct V_23 * V_24 ,
struct V_1 * V_2 , unsigned * V_32 )
{
if ( V_24 -> V_53 && V_24 -> V_53 -> V_87 )
V_24 -> V_53 -> V_87 ( V_24 -> V_27 -> V_28 , V_2 , V_32 ) ;
}
static void F_59 ( struct V_23 * V_24 ,
struct V_1 * V_2 , unsigned * V_32 )
{
if ( V_24 -> V_53 && V_24 -> V_53 -> V_88 )
V_24 -> V_53 -> V_88 ( F_18 ( V_24 -> V_27 -> V_28 ) ,
V_2 , V_32 ) ;
}
static int F_60 ( struct V_23 * V_24 ,
struct V_1 * V_2 , T_1 V_15 , T_1 V_16 ,
struct V_3 * * * V_68 ,
struct V_3 * * V_69 ,
unsigned * V_32 , struct V_33 * V_34 )
{
struct V_3 * V_65 ;
if ( V_16 < V_15 )
F_61 ( 1 , V_89 L_6 ,
V_16 , V_15 ) ;
V_2 -> V_15 = V_15 ;
V_2 -> V_16 = V_16 ;
F_62 ( V_24 , V_2 , V_32 , V_34 ) ;
V_65 = F_46 ( & V_24 -> V_2 , NULL , V_16 , & V_2 -> V_3 , V_68 , V_69 ) ;
if ( V_65 ) {
struct V_1 * V_90 ;
V_90 = F_47 ( V_65 , struct V_1 , V_3 ) ;
F_12 ( L_7 ,
V_90 -> V_15 , V_90 -> V_16 , V_15 , V_16 ) ;
return - V_91 ;
}
F_56 ( V_24 , V_2 ) ;
return 0 ;
}
static void F_63 ( struct V_23 * V_24 , struct V_1 * V_92 ,
T_1 V_93 )
{
if ( V_24 -> V_53 && V_24 -> V_53 -> V_94 )
V_24 -> V_53 -> V_94 ( V_24 -> V_27 -> V_28 , V_92 , V_93 ) ;
}
static int F_64 ( struct V_23 * V_24 , struct V_1 * V_92 ,
struct V_1 * V_95 , T_1 V_93 )
{
struct V_3 * V_65 ;
F_63 ( V_24 , V_92 , V_93 ) ;
V_95 -> V_15 = V_92 -> V_15 ;
V_95 -> V_16 = V_93 - 1 ;
V_95 -> V_2 = V_92 -> V_2 ;
V_92 -> V_15 = V_93 ;
V_65 = F_46 ( & V_24 -> V_2 , & V_92 -> V_3 , V_95 -> V_16 ,
& V_95 -> V_3 , NULL , NULL ) ;
if ( V_65 ) {
F_42 ( V_95 ) ;
return - V_91 ;
}
return 0 ;
}
static struct V_1 * F_65 ( struct V_1 * V_2 )
{
struct V_3 * V_13 = F_51 ( & V_2 -> V_3 ) ;
if ( V_13 )
return F_47 ( V_13 , struct V_1 , V_3 ) ;
else
return NULL ;
}
static struct V_1 * F_66 ( struct V_23 * V_24 ,
struct V_1 * V_2 ,
unsigned * V_32 , int V_96 ,
struct V_33 * V_34 )
{
struct V_1 * V_13 ;
unsigned V_97 = * V_32 & ~ V_98 ;
if ( ( V_97 & V_99 ) && ( V_2 -> V_2 & V_99 ) ) {
T_1 V_100 = V_2 -> V_16 - V_2 -> V_15 + 1 ;
F_44 ( V_100 > V_24 -> V_54 ) ;
V_24 -> V_54 -= V_100 ;
}
F_59 ( V_24 , V_2 , V_32 ) ;
F_20 ( V_2 , V_97 , V_34 , 0 ) ;
V_2 -> V_2 &= ~ V_97 ;
if ( V_96 )
F_67 ( & V_2 -> V_60 ) ;
if ( V_2 -> V_2 == 0 ) {
V_13 = F_65 ( V_2 ) ;
if ( F_1 ( V_2 ) ) {
F_57 ( & V_2 -> V_3 , & V_24 -> V_2 ) ;
F_38 ( & V_2 -> V_3 ) ;
F_42 ( V_2 ) ;
} else {
F_44 ( 1 ) ;
}
} else {
F_56 ( V_24 , V_2 ) ;
V_13 = F_65 ( V_2 ) ;
}
return V_13 ;
}
static struct V_1 *
F_68 ( struct V_1 * V_95 )
{
if ( ! V_95 )
V_95 = F_36 ( V_39 ) ;
return V_95 ;
}
static void F_69 ( struct V_23 * V_24 , int V_101 )
{
F_70 ( F_23 ( V_24 ) , V_101 ,
L_8 ) ;
}
static int F_71 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned V_32 , int V_96 , int V_102 ,
struct V_1 * * V_103 ,
T_3 V_56 , struct V_33 * V_34 )
{
struct V_1 * V_2 ;
struct V_1 * V_104 ;
struct V_1 * V_95 = NULL ;
struct V_3 * V_65 ;
T_1 V_105 ;
int V_101 ;
int V_106 = 0 ;
F_72 ( V_24 , V_15 , V_16 ) ;
if ( V_32 & V_107 )
V_32 |= V_108 ;
if ( V_102 )
V_32 |= ~ V_98 ;
V_32 |= V_109 ;
if ( V_32 & ( V_85 | V_86 ) )
V_106 = 1 ;
V_110:
if ( ! V_95 && F_73 ( V_56 ) ) {
V_95 = F_36 ( V_56 ) ;
}
F_74 ( & V_24 -> V_55 ) ;
if ( V_103 ) {
V_104 = * V_103 ;
if ( V_106 ) {
* V_103 = NULL ;
V_103 = NULL ;
}
if ( V_104 && F_1 ( V_104 ) &&
V_104 -> V_15 <= V_15 && V_104 -> V_16 > V_15 ) {
if ( V_106 )
F_75 ( & V_104 -> V_17 ) ;
V_2 = V_104 ;
goto V_111;
}
if ( V_106 )
F_42 ( V_104 ) ;
}
V_65 = F_54 ( V_24 , V_15 ) ;
if ( ! V_65 )
goto V_112;
V_2 = F_47 ( V_65 , struct V_1 , V_3 ) ;
V_111:
if ( V_2 -> V_15 > V_16 )
goto V_112;
F_44 ( V_2 -> V_16 < V_15 ) ;
V_105 = V_2 -> V_16 ;
if ( ! ( V_2 -> V_2 & V_32 ) ) {
V_2 = F_65 ( V_2 ) ;
goto V_13;
}
if ( V_2 -> V_15 < V_15 ) {
V_95 = F_68 ( V_95 ) ;
F_22 ( ! V_95 ) ;
V_101 = F_64 ( V_24 , V_2 , V_95 , V_15 ) ;
if ( V_101 )
F_69 ( V_24 , V_101 ) ;
V_95 = NULL ;
if ( V_101 )
goto V_112;
if ( V_2 -> V_16 <= V_16 ) {
V_2 = F_66 ( V_24 , V_2 , & V_32 , V_96 ,
V_34 ) ;
goto V_13;
}
goto V_113;
}
if ( V_2 -> V_15 <= V_16 && V_2 -> V_16 > V_16 ) {
V_95 = F_68 ( V_95 ) ;
F_22 ( ! V_95 ) ;
V_101 = F_64 ( V_24 , V_2 , V_95 , V_16 + 1 ) ;
if ( V_101 )
F_69 ( V_24 , V_101 ) ;
if ( V_96 )
F_67 ( & V_2 -> V_60 ) ;
F_66 ( V_24 , V_95 , & V_32 , V_96 , V_34 ) ;
V_95 = NULL ;
goto V_112;
}
V_2 = F_66 ( V_24 , V_2 , & V_32 , V_96 , V_34 ) ;
V_13:
if ( V_105 == ( T_1 ) - 1 )
goto V_112;
V_15 = V_105 + 1 ;
if ( V_15 <= V_16 && V_2 && ! F_76 () )
goto V_111;
V_113:
if ( V_15 > V_16 )
goto V_112;
F_77 ( & V_24 -> V_55 ) ;
if ( F_73 ( V_56 ) )
F_78 () ;
goto V_110;
V_112:
F_77 ( & V_24 -> V_55 ) ;
if ( V_95 )
F_42 ( V_95 ) ;
return 0 ;
}
static void F_79 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
__releases( V_24 -> V_55 )
__acquires( V_24 -> V_55 )
{
F_80 ( V_114 ) ;
F_81 ( & V_2 -> V_60 , & V_114 , V_115 ) ;
F_77 ( & V_24 -> V_55 ) ;
F_82 () ;
F_74 ( & V_24 -> V_55 ) ;
F_83 ( & V_2 -> V_60 , & V_114 ) ;
}
static void F_84 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned long V_32 )
{
struct V_1 * V_2 ;
struct V_3 * V_65 ;
F_72 ( V_24 , V_15 , V_16 ) ;
F_74 ( & V_24 -> V_55 ) ;
V_110:
while ( 1 ) {
V_65 = F_54 ( V_24 , V_15 ) ;
V_116:
if ( ! V_65 )
break;
V_2 = F_47 ( V_65 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 > V_16 )
goto V_112;
if ( V_2 -> V_2 & V_32 ) {
V_15 = V_2 -> V_15 ;
F_85 ( & V_2 -> V_17 ) ;
F_79 ( V_24 , V_2 ) ;
F_42 ( V_2 ) ;
goto V_110;
}
V_15 = V_2 -> V_16 + 1 ;
if ( V_15 > V_16 )
break;
if ( ! F_86 ( & V_24 -> V_55 ) ) {
V_65 = F_51 ( V_65 ) ;
goto V_116;
}
}
V_112:
F_77 ( & V_24 -> V_55 ) ;
}
static void F_62 ( struct V_23 * V_24 ,
struct V_1 * V_2 ,
unsigned * V_32 , struct V_33 * V_34 )
{
unsigned V_117 = * V_32 & ~ V_98 ;
F_58 ( V_24 , V_2 , V_32 ) ;
if ( ( V_117 & V_99 ) && ! ( V_2 -> V_2 & V_99 ) ) {
T_1 V_100 = V_2 -> V_16 - V_2 -> V_15 + 1 ;
V_24 -> V_54 += V_100 ;
}
F_20 ( V_2 , V_117 , V_34 , 1 ) ;
V_2 -> V_2 |= V_117 ;
}
static void F_87 ( struct V_1 * V_2 ,
struct V_1 * * V_118 ,
unsigned V_7 )
{
if ( V_118 && ! ( * V_118 ) ) {
if ( ! V_7 || ( V_2 -> V_2 & V_7 ) ) {
* V_118 = V_2 ;
F_85 ( & V_2 -> V_17 ) ;
}
}
}
static void F_88 ( struct V_1 * V_2 ,
struct V_1 * * V_118 )
{
return F_87 ( V_2 , V_118 ,
V_85 | V_86 ) ;
}
static int T_4
F_89 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned V_32 , unsigned V_119 ,
T_1 * V_120 , struct V_1 * * V_103 ,
T_3 V_56 , struct V_33 * V_34 )
{
struct V_1 * V_2 ;
struct V_1 * V_95 = NULL ;
struct V_3 * V_65 ;
struct V_3 * * V_68 ;
struct V_3 * V_69 ;
int V_101 = 0 ;
T_1 V_121 ;
T_1 V_105 ;
F_72 ( V_24 , V_15 , V_16 ) ;
V_32 |= V_109 ;
V_110:
if ( ! V_95 && F_73 ( V_56 ) ) {
V_95 = F_36 ( V_56 ) ;
}
F_74 ( & V_24 -> V_55 ) ;
if ( V_103 && * V_103 ) {
V_2 = * V_103 ;
if ( V_2 -> V_15 <= V_15 && V_2 -> V_16 > V_15 &&
F_1 ( V_2 ) ) {
V_65 = & V_2 -> V_3 ;
goto V_111;
}
}
V_65 = F_53 ( V_24 , V_15 , & V_68 , & V_69 ) ;
if ( ! V_65 ) {
V_95 = F_68 ( V_95 ) ;
F_22 ( ! V_95 ) ;
V_101 = F_60 ( V_24 , V_95 , V_15 , V_16 ,
& V_68 , & V_69 , & V_32 , V_34 ) ;
if ( V_101 )
F_69 ( V_24 , V_101 ) ;
F_88 ( V_95 , V_103 ) ;
V_95 = NULL ;
goto V_112;
}
V_2 = F_47 ( V_65 , struct V_1 , V_3 ) ;
V_111:
V_121 = V_2 -> V_15 ;
V_105 = V_2 -> V_16 ;
if ( V_2 -> V_15 == V_15 && V_2 -> V_16 <= V_16 ) {
if ( V_2 -> V_2 & V_119 ) {
* V_120 = V_2 -> V_15 ;
V_101 = - V_91 ;
goto V_112;
}
F_62 ( V_24 , V_2 , & V_32 , V_34 ) ;
F_88 ( V_2 , V_103 ) ;
F_56 ( V_24 , V_2 ) ;
if ( V_105 == ( T_1 ) - 1 )
goto V_112;
V_15 = V_105 + 1 ;
V_2 = F_65 ( V_2 ) ;
if ( V_15 < V_16 && V_2 && V_2 -> V_15 == V_15 &&
! F_76 () )
goto V_111;
goto V_113;
}
if ( V_2 -> V_15 < V_15 ) {
if ( V_2 -> V_2 & V_119 ) {
* V_120 = V_15 ;
V_101 = - V_91 ;
goto V_112;
}
V_95 = F_68 ( V_95 ) ;
F_22 ( ! V_95 ) ;
V_101 = F_64 ( V_24 , V_2 , V_95 , V_15 ) ;
if ( V_101 )
F_69 ( V_24 , V_101 ) ;
V_95 = NULL ;
if ( V_101 )
goto V_112;
if ( V_2 -> V_16 <= V_16 ) {
F_62 ( V_24 , V_2 , & V_32 , V_34 ) ;
F_88 ( V_2 , V_103 ) ;
F_56 ( V_24 , V_2 ) ;
if ( V_105 == ( T_1 ) - 1 )
goto V_112;
V_15 = V_105 + 1 ;
V_2 = F_65 ( V_2 ) ;
if ( V_15 < V_16 && V_2 && V_2 -> V_15 == V_15 &&
! F_76 () )
goto V_111;
}
goto V_113;
}
if ( V_2 -> V_15 > V_15 ) {
T_1 V_122 ;
if ( V_16 < V_121 )
V_122 = V_16 ;
else
V_122 = V_121 - 1 ;
V_95 = F_68 ( V_95 ) ;
F_22 ( ! V_95 ) ;
V_101 = F_60 ( V_24 , V_95 , V_15 , V_122 ,
NULL , NULL , & V_32 , V_34 ) ;
if ( V_101 )
F_69 ( V_24 , V_101 ) ;
F_88 ( V_95 , V_103 ) ;
V_95 = NULL ;
V_15 = V_122 + 1 ;
goto V_113;
}
if ( V_2 -> V_15 <= V_16 && V_2 -> V_16 > V_16 ) {
if ( V_2 -> V_2 & V_119 ) {
* V_120 = V_15 ;
V_101 = - V_91 ;
goto V_112;
}
V_95 = F_68 ( V_95 ) ;
F_22 ( ! V_95 ) ;
V_101 = F_64 ( V_24 , V_2 , V_95 , V_16 + 1 ) ;
if ( V_101 )
F_69 ( V_24 , V_101 ) ;
F_62 ( V_24 , V_95 , & V_32 , V_34 ) ;
F_88 ( V_95 , V_103 ) ;
F_56 ( V_24 , V_95 ) ;
V_95 = NULL ;
goto V_112;
}
V_113:
if ( V_15 > V_16 )
goto V_112;
F_77 ( & V_24 -> V_55 ) ;
if ( F_73 ( V_56 ) )
F_78 () ;
goto V_110;
V_112:
F_77 ( & V_24 -> V_55 ) ;
if ( V_95 )
F_42 ( V_95 ) ;
return V_101 ;
}
int F_90 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned V_32 , T_1 * V_120 ,
struct V_1 * * V_103 , T_3 V_56 )
{
return F_89 ( V_24 , V_15 , V_16 , V_32 , 0 , V_120 ,
V_103 , V_56 , NULL ) ;
}
int F_91 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned V_32 , unsigned V_123 ,
struct V_1 * * V_103 )
{
struct V_1 * V_2 ;
struct V_1 * V_95 = NULL ;
struct V_3 * V_65 ;
struct V_3 * * V_68 ;
struct V_3 * V_69 ;
int V_101 = 0 ;
T_1 V_121 ;
T_1 V_105 ;
bool V_124 = true ;
F_72 ( V_24 , V_15 , V_16 ) ;
V_110:
if ( ! V_95 ) {
V_95 = F_36 ( V_125 ) ;
if ( ! V_95 && ! V_124 )
return - V_43 ;
}
F_74 ( & V_24 -> V_55 ) ;
if ( V_103 && * V_103 ) {
V_2 = * V_103 ;
if ( V_2 -> V_15 <= V_15 && V_2 -> V_16 > V_15 &&
F_1 ( V_2 ) ) {
V_65 = & V_2 -> V_3 ;
goto V_111;
}
}
V_65 = F_53 ( V_24 , V_15 , & V_68 , & V_69 ) ;
if ( ! V_65 ) {
V_95 = F_68 ( V_95 ) ;
if ( ! V_95 ) {
V_101 = - V_43 ;
goto V_112;
}
V_101 = F_60 ( V_24 , V_95 , V_15 , V_16 ,
& V_68 , & V_69 , & V_32 , NULL ) ;
if ( V_101 )
F_69 ( V_24 , V_101 ) ;
F_88 ( V_95 , V_103 ) ;
V_95 = NULL ;
goto V_112;
}
V_2 = F_47 ( V_65 , struct V_1 , V_3 ) ;
V_111:
V_121 = V_2 -> V_15 ;
V_105 = V_2 -> V_16 ;
if ( V_2 -> V_15 == V_15 && V_2 -> V_16 <= V_16 ) {
F_62 ( V_24 , V_2 , & V_32 , NULL ) ;
F_88 ( V_2 , V_103 ) ;
V_2 = F_66 ( V_24 , V_2 , & V_123 , 0 , NULL ) ;
if ( V_105 == ( T_1 ) - 1 )
goto V_112;
V_15 = V_105 + 1 ;
if ( V_15 < V_16 && V_2 && V_2 -> V_15 == V_15 &&
! F_76 () )
goto V_111;
goto V_113;
}
if ( V_2 -> V_15 < V_15 ) {
V_95 = F_68 ( V_95 ) ;
if ( ! V_95 ) {
V_101 = - V_43 ;
goto V_112;
}
V_101 = F_64 ( V_24 , V_2 , V_95 , V_15 ) ;
if ( V_101 )
F_69 ( V_24 , V_101 ) ;
V_95 = NULL ;
if ( V_101 )
goto V_112;
if ( V_2 -> V_16 <= V_16 ) {
F_62 ( V_24 , V_2 , & V_32 , NULL ) ;
F_88 ( V_2 , V_103 ) ;
V_2 = F_66 ( V_24 , V_2 , & V_123 , 0 ,
NULL ) ;
if ( V_105 == ( T_1 ) - 1 )
goto V_112;
V_15 = V_105 + 1 ;
if ( V_15 < V_16 && V_2 && V_2 -> V_15 == V_15 &&
! F_76 () )
goto V_111;
}
goto V_113;
}
if ( V_2 -> V_15 > V_15 ) {
T_1 V_122 ;
if ( V_16 < V_121 )
V_122 = V_16 ;
else
V_122 = V_121 - 1 ;
V_95 = F_68 ( V_95 ) ;
if ( ! V_95 ) {
V_101 = - V_43 ;
goto V_112;
}
V_101 = F_60 ( V_24 , V_95 , V_15 , V_122 ,
NULL , NULL , & V_32 , NULL ) ;
if ( V_101 )
F_69 ( V_24 , V_101 ) ;
F_88 ( V_95 , V_103 ) ;
V_95 = NULL ;
V_15 = V_122 + 1 ;
goto V_113;
}
if ( V_2 -> V_15 <= V_16 && V_2 -> V_16 > V_16 ) {
V_95 = F_68 ( V_95 ) ;
if ( ! V_95 ) {
V_101 = - V_43 ;
goto V_112;
}
V_101 = F_64 ( V_24 , V_2 , V_95 , V_16 + 1 ) ;
if ( V_101 )
F_69 ( V_24 , V_101 ) ;
F_62 ( V_24 , V_95 , & V_32 , NULL ) ;
F_88 ( V_95 , V_103 ) ;
F_66 ( V_24 , V_95 , & V_123 , 0 , NULL ) ;
V_95 = NULL ;
goto V_112;
}
V_113:
if ( V_15 > V_16 )
goto V_112;
F_77 ( & V_24 -> V_55 ) ;
F_78 () ;
V_124 = false ;
goto V_110;
V_112:
F_77 ( & V_24 -> V_55 ) ;
if ( V_95 )
F_42 ( V_95 ) ;
return V_101 ;
}
int F_92 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned V_32 , struct V_33 * V_34 )
{
F_22 ( V_32 & V_126 ) ;
return F_89 ( V_24 , V_15 , V_16 , V_32 , 0 , NULL , NULL , V_125 ,
V_34 ) ;
}
int F_93 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned V_32 , int V_96 , int V_102 ,
struct V_1 * * V_104 , T_3 V_56 )
{
return F_71 ( V_24 , V_15 , V_16 , V_32 , V_96 , V_102 ,
V_104 , V_56 , NULL ) ;
}
int F_94 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned V_32 , struct V_33 * V_34 )
{
F_22 ( V_32 & V_126 ) ;
return F_71 ( V_24 , V_15 , V_16 , V_32 , 0 , 0 , NULL , V_125 ,
V_34 ) ;
}
int F_95 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
struct V_1 * * V_103 )
{
int V_101 ;
T_1 V_120 ;
while ( 1 ) {
V_101 = F_89 ( V_24 , V_15 , V_16 , V_126 ,
V_126 , & V_120 ,
V_103 , V_125 , NULL ) ;
if ( V_101 == - V_91 ) {
F_84 ( V_24 , V_120 , V_16 , V_126 ) ;
V_15 = V_120 ;
} else
break;
F_44 ( V_15 > V_16 ) ;
}
return V_101 ;
}
int F_96 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 )
{
int V_101 ;
T_1 V_120 ;
V_101 = F_89 ( V_24 , V_15 , V_16 , V_126 , V_126 ,
& V_120 , NULL , V_125 , NULL ) ;
if ( V_101 == - V_91 ) {
if ( V_120 > V_15 )
F_93 ( V_24 , V_15 , V_120 - 1 ,
V_126 , 1 , 0 , NULL , V_125 ) ;
return 0 ;
}
return 1 ;
}
void F_97 ( struct V_25 * V_25 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_127 = V_15 >> V_128 ;
unsigned long V_129 = V_16 >> V_128 ;
struct V_130 * V_130 ;
while ( V_127 <= V_129 ) {
V_130 = F_98 ( V_25 -> V_131 , V_127 ) ;
F_22 ( ! V_130 ) ;
F_99 ( V_130 ) ;
F_100 ( V_130 ) ;
V_127 ++ ;
}
}
void F_101 ( struct V_25 * V_25 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_127 = V_15 >> V_128 ;
unsigned long V_129 = V_16 >> V_128 ;
struct V_130 * V_130 ;
while ( V_127 <= V_129 ) {
V_130 = F_98 ( V_25 -> V_131 , V_127 ) ;
F_22 ( ! V_130 ) ;
F_102 ( V_130 ) ;
F_103 ( V_130 ) ;
F_100 ( V_130 ) ;
V_127 ++ ;
}
}
static void F_104 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_127 = V_15 >> V_128 ;
unsigned long V_129 = V_16 >> V_128 ;
struct V_130 * V_130 ;
while ( V_127 <= V_129 ) {
V_130 = F_98 ( V_24 -> V_27 , V_127 ) ;
F_22 ( ! V_130 ) ;
F_105 ( V_130 ) ;
F_100 ( V_130 ) ;
V_127 ++ ;
}
}
static struct V_1 *
F_106 ( struct V_23 * V_24 ,
T_1 V_15 , unsigned V_32 )
{
struct V_3 * V_65 ;
struct V_1 * V_2 ;
V_65 = F_54 ( V_24 , V_15 ) ;
if ( ! V_65 )
goto V_112;
while ( 1 ) {
V_2 = F_47 ( V_65 , struct V_1 , V_3 ) ;
if ( V_2 -> V_16 >= V_15 && ( V_2 -> V_2 & V_32 ) )
return V_2 ;
V_65 = F_51 ( V_65 ) ;
if ( ! V_65 )
break;
}
V_112:
return NULL ;
}
int F_107 ( struct V_23 * V_24 , T_1 V_15 ,
T_1 * V_132 , T_1 * V_133 , unsigned V_32 ,
struct V_1 * * V_103 )
{
struct V_1 * V_2 ;
struct V_3 * V_78 ;
int V_36 = 1 ;
F_74 ( & V_24 -> V_55 ) ;
if ( V_103 && * V_103 ) {
V_2 = * V_103 ;
if ( V_2 -> V_16 == V_15 - 1 && F_1 ( V_2 ) ) {
V_78 = F_51 ( & V_2 -> V_3 ) ;
while ( V_78 ) {
V_2 = F_47 ( V_78 , struct V_1 ,
V_3 ) ;
if ( V_2 -> V_2 & V_32 )
goto V_134;
V_78 = F_51 ( V_78 ) ;
}
F_42 ( * V_103 ) ;
* V_103 = NULL ;
goto V_112;
}
F_42 ( * V_103 ) ;
* V_103 = NULL ;
}
V_2 = F_106 ( V_24 , V_15 , V_32 ) ;
V_134:
if ( V_2 ) {
F_87 ( V_2 , V_103 , 0 ) ;
* V_132 = V_2 -> V_15 ;
* V_133 = V_2 -> V_16 ;
V_36 = 0 ;
}
V_112:
F_77 ( & V_24 -> V_55 ) ;
return V_36 ;
}
static T_5 T_1 F_108 ( struct V_23 * V_24 ,
T_1 * V_15 , T_1 * V_16 , T_1 V_135 ,
struct V_1 * * V_103 )
{
struct V_3 * V_65 ;
struct V_1 * V_2 ;
T_1 V_136 = * V_15 ;
T_1 V_90 = 0 ;
T_1 V_137 = 0 ;
F_74 ( & V_24 -> V_55 ) ;
V_65 = F_54 ( V_24 , V_136 ) ;
if ( ! V_65 ) {
if ( ! V_90 )
* V_16 = ( T_1 ) - 1 ;
goto V_112;
}
while ( 1 ) {
V_2 = F_47 ( V_65 , struct V_1 , V_3 ) ;
if ( V_90 && ( V_2 -> V_15 != V_136 ||
( V_2 -> V_2 & V_86 ) ) ) {
goto V_112;
}
if ( ! ( V_2 -> V_2 & V_107 ) ) {
if ( ! V_90 )
* V_16 = V_2 -> V_16 ;
goto V_112;
}
if ( ! V_90 ) {
* V_15 = V_2 -> V_15 ;
* V_103 = V_2 ;
F_85 ( & V_2 -> V_17 ) ;
}
V_90 ++ ;
* V_16 = V_2 -> V_16 ;
V_136 = V_2 -> V_16 + 1 ;
V_65 = F_51 ( V_65 ) ;
V_137 += V_2 -> V_16 - V_2 -> V_15 + 1 ;
if ( V_137 >= V_135 )
break;
if ( ! V_65 )
break;
}
V_112:
F_77 ( & V_24 -> V_55 ) ;
return V_90 ;
}
static T_5 void F_109 ( struct V_25 * V_25 ,
struct V_130 * V_138 ,
T_1 V_15 , T_1 V_16 )
{
unsigned long V_127 = V_15 >> V_128 ;
unsigned long V_129 = V_16 >> V_128 ;
ASSERT ( V_138 ) ;
if ( V_127 == V_138 -> V_127 && V_129 == V_127 )
return;
F_110 ( V_25 -> V_131 , V_138 , V_127 , V_129 ,
V_139 , NULL ) ;
}
static T_5 int F_111 ( struct V_25 * V_25 ,
struct V_130 * V_138 ,
T_1 V_140 ,
T_1 V_141 )
{
unsigned long V_127 = V_140 >> V_128 ;
unsigned long V_142 = V_127 ;
unsigned long V_129 = V_141 >> V_128 ;
int V_36 ;
ASSERT ( V_138 ) ;
if ( V_127 == V_138 -> V_127 && V_127 == V_129 )
return 0 ;
V_36 = F_110 ( V_25 -> V_131 , V_138 , V_127 ,
V_129 , V_143 , & V_142 ) ;
if ( V_36 == - V_144 )
F_109 ( V_25 , V_138 , V_140 ,
( T_1 ) V_142 << V_128 ) ;
return V_36 ;
}
STATIC T_1 F_112 ( struct V_25 * V_25 ,
struct V_23 * V_24 ,
struct V_130 * V_138 , T_1 * V_15 ,
T_1 * V_16 , T_1 V_135 )
{
T_1 V_140 ;
T_1 V_141 ;
T_1 V_90 ;
struct V_1 * V_103 = NULL ;
int V_36 ;
int V_145 = 0 ;
V_110:
V_140 = * V_15 ;
V_141 = 0 ;
V_90 = F_108 ( V_24 , & V_140 , & V_141 ,
V_135 , & V_103 ) ;
if ( ! V_90 || V_141 <= * V_15 ) {
* V_15 = V_140 ;
* V_16 = V_141 ;
F_42 ( V_103 ) ;
return 0 ;
}
if ( V_140 < * V_15 )
V_140 = * V_15 ;
if ( V_141 + 1 - V_140 > V_135 )
V_141 = V_140 + V_135 - 1 ;
V_36 = F_111 ( V_25 , V_138 ,
V_140 , V_141 ) ;
if ( V_36 == - V_144 ) {
F_42 ( V_103 ) ;
V_103 = NULL ;
if ( ! V_145 ) {
V_135 = V_29 ;
V_145 = 1 ;
goto V_110;
} else {
V_90 = 0 ;
goto V_146;
}
}
F_22 ( V_36 ) ;
F_95 ( V_24 , V_140 , V_141 , & V_103 ) ;
V_36 = F_113 ( V_24 , V_140 , V_141 ,
V_107 , 1 , V_103 ) ;
if ( ! V_36 ) {
F_114 ( V_24 , V_140 , V_141 ,
& V_103 , V_125 ) ;
F_109 ( V_25 , V_138 ,
V_140 , V_141 ) ;
F_78 () ;
goto V_110;
}
F_42 ( V_103 ) ;
* V_15 = V_140 ;
* V_16 = V_141 ;
V_146:
return V_90 ;
}
static int F_110 ( struct V_51 * V_27 ,
struct V_130 * V_138 ,
T_6 V_147 , T_6 V_129 ,
unsigned long V_148 , T_6 * V_142 )
{
unsigned long V_149 = V_129 - V_147 + 1 ;
unsigned long V_150 = 0 ;
T_6 V_127 = V_147 ;
struct V_130 * V_151 [ 16 ] ;
unsigned V_36 ;
int V_101 = 0 ;
int V_152 ;
if ( V_148 & V_143 ) {
ASSERT ( V_148 == V_143 ) ;
ASSERT ( V_142 && * V_142 == V_147 ) ;
}
if ( ( V_148 & V_153 ) && V_149 > 0 )
F_115 ( V_27 , - V_154 ) ;
while ( V_149 > 0 ) {
V_36 = F_116 ( V_27 , V_127 ,
F_117 (unsigned long,
nr_pages, ARRAY_SIZE(pages)) , V_151 ) ;
if ( V_36 == 0 ) {
ASSERT ( V_148 & V_143 ) ;
V_101 = - V_144 ;
goto V_112;
}
for ( V_152 = 0 ; V_152 < V_36 ; V_152 ++ ) {
if ( V_148 & V_155 )
F_118 ( V_151 [ V_152 ] ) ;
if ( V_151 [ V_152 ] == V_138 ) {
F_100 ( V_151 [ V_152 ] ) ;
V_150 ++ ;
continue;
}
if ( V_148 & V_156 )
F_99 ( V_151 [ V_152 ] ) ;
if ( V_148 & V_157 )
F_105 ( V_151 [ V_152 ] ) ;
if ( V_148 & V_153 )
F_119 ( V_151 [ V_152 ] ) ;
if ( V_148 & V_158 )
F_120 ( V_151 [ V_152 ] ) ;
if ( V_148 & V_139 )
F_121 ( V_151 [ V_152 ] ) ;
if ( V_148 & V_143 ) {
F_122 ( V_151 [ V_152 ] ) ;
if ( ! F_123 ( V_151 [ V_152 ] ) ||
V_151 [ V_152 ] -> V_27 != V_27 ) {
F_121 ( V_151 [ V_152 ] ) ;
F_100 ( V_151 [ V_152 ] ) ;
V_101 = - V_144 ;
goto V_112;
}
}
F_100 ( V_151 [ V_152 ] ) ;
V_150 ++ ;
}
V_149 -= V_36 ;
V_127 += V_36 ;
F_78 () ;
}
V_112:
if ( V_101 && V_142 )
* V_142 = V_147 + V_150 - 1 ;
return V_101 ;
}
void F_124 ( struct V_25 * V_25 , T_1 V_15 , T_1 V_16 ,
T_1 V_141 , struct V_130 * V_138 ,
unsigned V_123 ,
unsigned long V_148 )
{
F_93 ( & F_18 ( V_25 ) -> V_159 , V_15 , V_16 , V_123 , 1 , 0 ,
NULL , V_125 ) ;
F_110 ( V_25 -> V_131 , V_138 ,
V_15 >> V_128 , V_16 >> V_128 ,
V_148 , NULL ) ;
}
T_1 F_125 ( struct V_23 * V_24 ,
T_1 * V_15 , T_1 V_160 , T_1 V_135 ,
unsigned V_32 , int V_161 )
{
struct V_3 * V_65 ;
struct V_1 * V_2 ;
T_1 V_136 = * V_15 ;
T_1 V_137 = 0 ;
T_1 V_162 = 0 ;
int V_90 = 0 ;
if ( F_44 ( V_160 <= V_136 ) )
return 0 ;
F_74 ( & V_24 -> V_55 ) ;
if ( V_136 == 0 && V_32 == V_99 ) {
V_137 = V_24 -> V_54 ;
goto V_112;
}
V_65 = F_54 ( V_24 , V_136 ) ;
if ( ! V_65 )
goto V_112;
while ( 1 ) {
V_2 = F_47 ( V_65 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 > V_160 )
break;
if ( V_161 && V_90 && V_2 -> V_15 > V_162 + 1 )
break;
if ( V_2 -> V_16 >= V_136 && ( V_2 -> V_2 & V_32 ) == V_32 ) {
V_137 += F_126 ( V_160 , V_2 -> V_16 ) + 1 -
F_127 ( V_136 , V_2 -> V_15 ) ;
if ( V_137 >= V_135 )
break;
if ( ! V_90 ) {
* V_15 = F_127 ( V_136 , V_2 -> V_15 ) ;
V_90 = 1 ;
}
V_162 = V_2 -> V_16 ;
} else if ( V_161 && V_90 ) {
break;
}
V_65 = F_51 ( V_65 ) ;
if ( ! V_65 )
break;
}
V_112:
F_77 ( & V_24 -> V_55 ) ;
return V_137 ;
}
static T_5 int F_128 ( struct V_23 * V_24 , T_1 V_15 ,
struct V_163 * V_59 )
{
struct V_3 * V_65 ;
struct V_1 * V_2 ;
int V_36 = 0 ;
F_74 ( & V_24 -> V_55 ) ;
V_65 = F_54 ( V_24 , V_15 ) ;
if ( ! V_65 ) {
V_36 = - V_164 ;
goto V_112;
}
V_2 = F_47 ( V_65 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 != V_15 ) {
V_36 = - V_164 ;
goto V_112;
}
V_2 -> V_59 = V_59 ;
V_112:
F_77 ( & V_24 -> V_55 ) ;
return V_36 ;
}
static T_5 int F_129 ( struct V_23 * V_24 , T_1 V_15 ,
struct V_163 * * V_59 )
{
struct V_3 * V_65 ;
struct V_1 * V_2 ;
int V_36 = 0 ;
F_74 ( & V_24 -> V_55 ) ;
V_65 = F_54 ( V_24 , V_15 ) ;
if ( ! V_65 ) {
V_36 = - V_164 ;
goto V_112;
}
V_2 = F_47 ( V_65 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 != V_15 ) {
V_36 = - V_164 ;
goto V_112;
}
* V_59 = V_2 -> V_59 ;
V_112:
F_77 ( & V_24 -> V_55 ) ;
return V_36 ;
}
int F_113 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned V_32 , int V_165 , struct V_1 * V_104 )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_65 ;
int V_166 = 0 ;
F_74 ( & V_24 -> V_55 ) ;
if ( V_104 && F_1 ( V_104 ) && V_104 -> V_15 <= V_15 &&
V_104 -> V_16 > V_15 )
V_65 = & V_104 -> V_3 ;
else
V_65 = F_54 ( V_24 , V_15 ) ;
while ( V_65 && V_15 <= V_16 ) {
V_2 = F_47 ( V_65 , struct V_1 , V_3 ) ;
if ( V_165 && V_2 -> V_15 > V_15 ) {
V_166 = 0 ;
break;
}
if ( V_2 -> V_15 > V_16 )
break;
if ( V_2 -> V_2 & V_32 ) {
V_166 = 1 ;
if ( ! V_165 )
break;
} else if ( V_165 ) {
V_166 = 0 ;
break;
}
if ( V_2 -> V_16 == ( T_1 ) - 1 )
break;
V_15 = V_2 -> V_16 + 1 ;
if ( V_15 > V_16 )
break;
V_65 = F_51 ( V_65 ) ;
if ( ! V_65 ) {
if ( V_165 )
V_166 = 0 ;
break;
}
}
F_77 ( & V_24 -> V_55 ) ;
return V_166 ;
}
static void F_130 ( struct V_23 * V_24 , struct V_130 * V_130 )
{
T_1 V_15 = F_131 ( V_130 ) ;
T_1 V_16 = V_15 + V_29 - 1 ;
if ( F_113 ( V_24 , V_15 , V_16 , V_167 , 1 , NULL ) )
F_132 ( V_130 ) ;
}
int F_133 ( struct V_168 * V_25 , struct V_163 * V_169 )
{
int V_36 ;
int V_101 = 0 ;
struct V_23 * V_170 = & V_25 -> V_171 ;
F_128 ( V_170 , V_169 -> V_15 , NULL ) ;
V_36 = F_134 ( V_170 , V_169 -> V_15 ,
V_169 -> V_15 + V_169 -> V_20 - 1 ,
V_126 | V_99 ) ;
if ( V_36 )
V_101 = V_36 ;
V_36 = F_134 ( & V_25 -> V_159 , V_169 -> V_15 ,
V_169 -> V_15 + V_169 -> V_20 - 1 ,
V_172 ) ;
if ( V_36 && ! V_101 )
V_101 = V_36 ;
F_135 ( V_169 ) ;
return V_101 ;
}
int F_136 ( struct V_168 * V_25 , T_1 V_15 , T_1 V_173 ,
T_1 V_174 , struct V_130 * V_130 ,
unsigned int V_175 , int V_176 )
{
struct V_40 * V_31 = V_25 -> V_30 -> V_31 ;
struct V_48 * V_48 ;
struct V_177 * V_178 ;
T_1 V_179 = 0 ;
T_1 V_180 ;
struct V_181 * V_182 = NULL ;
struct V_183 * V_184 = & V_31 -> V_185 ;
int V_36 ;
ASSERT ( ! ( V_31 -> V_186 -> V_187 & V_188 ) ) ;
F_22 ( ! V_176 ) ;
if ( F_137 ( V_184 , V_174 , V_173 , V_176 ) )
return 0 ;
V_48 = F_138 ( V_125 , 1 ) ;
if ( ! V_48 )
return - V_154 ;
V_48 -> V_189 . V_190 = 0 ;
V_179 = V_173 ;
F_139 ( V_31 ) ;
V_36 = F_140 ( V_31 , V_191 , V_174 ,
& V_179 , & V_182 , V_176 ) ;
if ( V_36 ) {
F_141 ( V_31 ) ;
F_142 ( V_48 ) ;
return - V_154 ;
}
F_22 ( V_176 != V_182 -> V_176 ) ;
V_180 = V_182 -> V_192 [ V_176 - 1 ] . V_193 >> 9 ;
V_48 -> V_189 . V_194 = V_180 ;
V_178 = V_182 -> V_192 [ V_176 - 1 ] . V_178 ;
F_143 ( V_182 ) ;
if ( ! V_178 || ! V_178 -> V_195 || ! V_178 -> V_196 ) {
F_141 ( V_31 ) ;
F_142 ( V_48 ) ;
return - V_154 ;
}
V_48 -> V_197 = V_178 -> V_195 ;
V_48 -> V_198 = V_199 | V_200 ;
F_144 ( V_48 , V_130 , V_173 , V_175 ) ;
if ( F_145 ( V_48 ) ) {
F_141 ( V_31 ) ;
F_142 ( V_48 ) ;
F_146 ( V_178 , V_201 ) ;
return - V_154 ;
}
F_147 ( V_31 ,
L_9 ,
F_19 ( V_25 ) , V_15 ,
F_148 ( V_178 -> V_202 ) , V_180 ) ;
F_141 ( V_31 ) ;
F_142 ( V_48 ) ;
return 0 ;
}
int F_149 ( struct V_40 * V_31 ,
struct V_10 * V_11 , int V_176 )
{
T_1 V_15 = V_11 -> V_15 ;
unsigned long V_152 , V_203 = F_150 ( V_11 -> V_15 , V_11 -> V_20 ) ;
int V_36 = 0 ;
if ( V_31 -> V_186 -> V_187 & V_188 )
return - V_204 ;
for ( V_152 = 0 ; V_152 < V_203 ; V_152 ++ ) {
struct V_130 * V_68 = V_11 -> V_151 [ V_152 ] ;
V_36 = F_136 ( F_18 ( V_31 -> V_205 ) , V_15 ,
V_29 , V_15 , V_68 ,
V_15 - F_131 ( V_68 ) , V_176 ) ;
if ( V_36 )
break;
V_15 += V_29 ;
}
return V_36 ;
}
int F_151 ( struct V_168 * V_25 , T_1 V_15 , struct V_130 * V_130 ,
unsigned int V_175 )
{
T_1 V_206 ;
struct V_163 * V_59 ;
struct V_40 * V_31 = V_25 -> V_30 -> V_31 ;
struct V_1 * V_2 ;
int V_207 ;
int V_36 ;
V_206 = 0 ;
V_36 = F_125 ( & V_25 -> V_171 , & V_206 ,
( T_1 ) - 1 , 1 , V_99 , 0 ) ;
if ( ! V_36 )
return 0 ;
V_36 = F_129 ( & V_25 -> V_171 , V_15 ,
& V_59 ) ;
if ( V_36 )
return 0 ;
F_22 ( ! V_59 -> V_208 ) ;
if ( V_59 -> V_209 ) {
F_152 ( V_31 ,
L_10 ,
V_59 -> V_15 ) ;
goto V_112;
}
if ( V_31 -> V_186 -> V_187 & V_188 )
goto V_112;
F_74 ( & V_25 -> V_159 . V_55 ) ;
V_2 = F_106 ( & V_25 -> V_159 ,
V_59 -> V_15 ,
V_126 ) ;
F_77 ( & V_25 -> V_159 . V_55 ) ;
if ( V_2 && V_2 -> V_15 <= V_59 -> V_15 &&
V_2 -> V_16 >= V_59 -> V_15 + V_59 -> V_20 - 1 ) {
V_207 = F_153 ( V_31 , V_59 -> V_174 ,
V_59 -> V_20 ) ;
if ( V_207 > 1 ) {
F_136 ( V_25 , V_15 , V_59 -> V_20 ,
V_59 -> V_174 , V_130 ,
V_175 , V_59 -> V_210 ) ;
}
}
V_112:
F_133 ( V_25 , V_59 ) ;
return 0 ;
}
void F_154 ( struct V_168 * V_25 , T_1 V_15 , T_1 V_16 )
{
struct V_23 * V_170 = & V_25 -> V_171 ;
struct V_163 * V_59 ;
struct V_1 * V_2 , * V_13 ;
if ( F_155 ( & V_170 -> V_2 ) )
return;
F_74 ( & V_170 -> V_55 ) ;
V_2 = F_106 ( V_170 , V_15 , V_99 ) ;
while ( V_2 ) {
if ( V_2 -> V_15 > V_16 )
break;
ASSERT ( V_2 -> V_16 <= V_16 ) ;
V_13 = F_65 ( V_2 ) ;
V_59 = V_2 -> V_59 ;
F_42 ( V_2 ) ;
F_135 ( V_59 ) ;
V_2 = V_13 ;
}
F_77 ( & V_170 -> V_55 ) ;
}
int F_156 ( struct V_25 * V_25 , T_1 V_15 , T_1 V_16 ,
struct V_163 * * V_211 )
{
struct V_40 * V_31 = F_24 ( V_25 -> V_41 ) ;
struct V_163 * V_59 ;
struct V_212 * V_213 ;
struct V_23 * V_170 = & F_18 ( V_25 ) -> V_171 ;
struct V_23 * V_24 = & F_18 ( V_25 ) -> V_159 ;
struct V_214 * V_215 = & F_18 ( V_25 ) -> V_216 ;
int V_36 ;
T_1 V_174 ;
V_36 = F_129 ( V_170 , V_15 , & V_59 ) ;
if ( V_36 ) {
V_59 = F_157 ( sizeof( * V_59 ) , V_125 ) ;
if ( ! V_59 )
return - V_43 ;
V_59 -> V_15 = V_15 ;
V_59 -> V_20 = V_16 - V_15 + 1 ;
V_59 -> V_208 = 0 ;
V_59 -> V_217 = 0 ;
V_59 -> V_209 = 0 ;
F_158 ( & V_215 -> V_55 ) ;
V_213 = F_159 ( V_215 , V_15 , V_59 -> V_20 ) ;
if ( ! V_213 ) {
F_160 ( & V_215 -> V_55 ) ;
F_135 ( V_59 ) ;
return - V_154 ;
}
if ( V_213 -> V_15 > V_15 || V_213 -> V_15 + V_213 -> V_20 <= V_15 ) {
F_161 ( V_213 ) ;
V_213 = NULL ;
}
F_160 ( & V_215 -> V_55 ) ;
if ( ! V_213 ) {
F_135 ( V_59 ) ;
return - V_154 ;
}
V_174 = V_15 - V_213 -> V_15 ;
V_174 = V_213 -> V_218 + V_174 ;
if ( F_162 ( V_219 , & V_213 -> V_7 ) ) {
V_174 = V_213 -> V_218 ;
V_59 -> V_217 = V_220 ;
F_163 ( & V_59 -> V_217 ,
V_213 -> V_221 ) ;
}
F_152 ( V_31 ,
L_11 ,
V_174 , V_15 , V_59 -> V_20 ) ;
V_59 -> V_174 = V_174 ;
F_161 ( V_213 ) ;
V_36 = F_164 ( V_170 , V_15 , V_16 ,
V_126 | V_99 ) ;
if ( V_36 >= 0 )
V_36 = F_128 ( V_170 , V_15 , V_59 ) ;
if ( V_36 >= 0 )
V_36 = F_164 ( V_24 , V_15 , V_16 , V_172 ) ;
if ( V_36 < 0 ) {
F_135 ( V_59 ) ;
return V_36 ;
}
} else {
F_152 ( V_31 ,
L_12 ,
V_59 -> V_174 , V_59 -> V_15 , V_59 -> V_20 ,
V_59 -> V_209 ) ;
}
* V_211 = V_59 ;
return 0 ;
}
int F_165 ( struct V_25 * V_25 , struct V_48 * V_222 ,
struct V_163 * V_59 , int V_210 )
{
struct V_40 * V_31 = F_24 ( V_25 -> V_41 ) ;
int V_207 ;
V_207 = F_153 ( V_31 , V_59 -> V_174 , V_59 -> V_20 ) ;
if ( V_207 == 1 ) {
F_152 ( V_31 ,
L_13 ,
V_207 , V_59 -> V_208 , V_210 ) ;
return 0 ;
}
if ( V_222 -> V_223 > 1 ) {
F_22 ( V_59 -> V_209 ) ;
V_59 -> V_209 = 1 ;
V_59 -> V_208 = V_210 ;
} else {
if ( V_59 -> V_209 ) {
F_22 ( V_59 -> V_208 != V_210 ) ;
V_59 -> V_209 = 0 ;
V_59 -> V_208 = 0 ;
}
V_59 -> V_210 = V_210 ;
V_59 -> V_208 ++ ;
if ( V_59 -> V_208 == V_210 )
V_59 -> V_208 ++ ;
}
if ( V_59 -> V_208 > V_207 ) {
F_152 ( V_31 ,
L_14 ,
V_207 , V_59 -> V_208 , V_210 ) ;
return 0 ;
}
return 1 ;
}
struct V_48 * F_166 ( struct V_25 * V_25 , struct V_48 * V_222 ,
struct V_163 * V_59 ,
struct V_130 * V_130 , int V_175 , int V_224 ,
T_7 * V_225 , void * V_226 )
{
struct V_40 * V_31 = F_24 ( V_25 -> V_41 ) ;
struct V_48 * V_48 ;
struct V_47 * V_227 ;
struct V_47 * V_181 ;
V_48 = F_138 ( V_125 , 1 ) ;
if ( ! V_48 )
return NULL ;
V_48 -> V_228 = V_225 ;
V_48 -> V_189 . V_194 = V_59 -> V_174 >> 9 ;
V_48 -> V_197 = V_31 -> V_229 -> V_230 ;
V_48 -> V_189 . V_190 = 0 ;
V_48 -> V_231 = V_226 ;
V_227 = V_47 ( V_222 ) ;
if ( V_227 -> V_232 ) {
T_8 V_233 = F_167 ( V_31 -> V_234 ) ;
V_181 = V_47 ( V_48 ) ;
V_181 -> V_232 = V_181 -> V_235 ;
V_224 *= V_233 ;
memcpy ( V_181 -> V_232 , V_227 -> V_232 + V_224 ,
V_233 ) ;
}
F_144 ( V_48 , V_130 , V_59 -> V_20 , V_175 ) ;
return V_48 ;
}
static int F_168 ( struct V_48 * V_222 , T_1 V_236 ,
struct V_130 * V_130 , T_1 V_15 , T_1 V_16 ,
int V_210 )
{
struct V_163 * V_59 ;
struct V_25 * V_25 = V_130 -> V_27 -> V_28 ;
struct V_23 * V_24 = & F_18 ( V_25 ) -> V_159 ;
struct V_48 * V_48 ;
int V_237 = 0 ;
int V_36 ;
F_22 ( F_169 ( V_222 ) == V_199 ) ;
V_36 = F_156 ( V_25 , V_15 , V_16 , & V_59 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_165 ( V_25 , V_222 , V_59 , V_210 ) ;
if ( ! V_36 ) {
F_133 ( F_18 ( V_25 ) , V_59 ) ;
return - V_154 ;
}
if ( V_222 -> V_223 > 1 )
V_237 |= V_238 ;
V_236 >>= V_25 -> V_41 -> V_239 ;
V_48 = F_166 ( V_25 , V_222 , V_59 , V_130 ,
V_15 - F_131 ( V_130 ) ,
( int ) V_236 , V_222 -> V_228 ,
NULL ) ;
if ( ! V_48 ) {
F_133 ( F_18 ( V_25 ) , V_59 ) ;
return - V_154 ;
}
F_170 ( V_48 , V_240 , V_237 ) ;
F_152 ( F_24 ( V_25 -> V_41 ) ,
L_15 ,
V_237 , V_59 -> V_208 , V_59 -> V_209 ) ;
V_36 = V_24 -> V_53 -> V_241 ( V_25 , V_48 , V_59 -> V_208 ,
V_59 -> V_217 , 0 ) ;
if ( V_36 ) {
F_133 ( F_18 ( V_25 ) , V_59 ) ;
F_142 ( V_48 ) ;
}
return V_36 ;
}
void F_171 ( struct V_130 * V_130 , int V_101 , T_1 V_15 , T_1 V_16 )
{
int V_242 = ( V_101 == 0 ) ;
struct V_23 * V_24 ;
int V_36 = 0 ;
V_24 = & F_18 ( V_130 -> V_27 -> V_28 ) -> V_159 ;
if ( V_24 -> V_53 && V_24 -> V_53 -> V_243 )
V_24 -> V_53 -> V_243 ( V_130 , V_15 , V_16 , NULL ,
V_242 ) ;
if ( ! V_242 ) {
F_172 ( V_130 ) ;
F_119 ( V_130 ) ;
V_36 = V_36 < 0 ? V_36 : - V_154 ;
F_115 ( V_130 -> V_27 , V_36 ) ;
}
}
static void F_173 ( struct V_48 * V_48 )
{
struct V_244 * V_245 ;
T_1 V_15 ;
T_1 V_16 ;
int V_152 ;
F_174 (bvec, bio, i) {
struct V_130 * V_130 = V_245 -> V_246 ;
struct V_25 * V_25 = V_130 -> V_27 -> V_28 ;
struct V_40 * V_31 = F_24 ( V_25 -> V_41 ) ;
if ( V_245 -> V_247 || V_245 -> V_248 != V_29 ) {
if ( V_245 -> V_247 + V_245 -> V_248 != V_29 )
F_175 ( V_31 ,
L_16 ,
V_245 -> V_247 , V_245 -> V_248 ) ;
else
F_176 ( V_31 ,
L_17 ,
V_245 -> V_247 , V_245 -> V_248 ) ;
}
V_15 = F_131 ( V_130 ) ;
V_16 = V_15 + V_245 -> V_247 + V_245 -> V_248 - 1 ;
F_171 ( V_130 , V_48 -> V_249 , V_15 , V_16 ) ;
F_120 ( V_130 ) ;
}
F_142 ( V_48 ) ;
}
static void
F_177 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_20 ,
int V_242 )
{
struct V_1 * V_104 = NULL ;
T_1 V_16 = V_15 + V_20 - 1 ;
if ( V_242 && V_24 -> V_250 )
F_178 ( V_24 , V_15 , V_16 , & V_104 , V_39 ) ;
F_114 ( V_24 , V_15 , V_16 , & V_104 , V_39 ) ;
}
static void F_179 ( struct V_48 * V_48 )
{
struct V_244 * V_245 ;
int V_242 = ! V_48 -> V_249 ;
struct V_47 * V_251 = V_47 ( V_48 ) ;
struct V_23 * V_24 ;
T_1 V_64 = 0 ;
T_1 V_15 ;
T_1 V_16 ;
T_1 V_20 ;
T_1 V_252 = 0 ;
T_1 V_253 = 0 ;
int V_254 ;
int V_36 ;
int V_152 ;
F_174 (bvec, bio, i) {
struct V_130 * V_130 = V_245 -> V_246 ;
struct V_25 * V_25 = V_130 -> V_27 -> V_28 ;
struct V_40 * V_31 = F_24 ( V_25 -> V_41 ) ;
F_152 ( V_31 ,
L_18 ,
( T_1 ) V_48 -> V_189 . V_194 , V_48 -> V_249 ,
V_251 -> V_176 ) ;
V_24 = & F_18 ( V_25 ) -> V_159 ;
if ( V_245 -> V_247 || V_245 -> V_248 != V_29 ) {
if ( V_245 -> V_247 + V_245 -> V_248 != V_29 )
F_175 ( V_31 ,
L_19 ,
V_245 -> V_247 , V_245 -> V_248 ) ;
else
F_176 ( V_31 ,
L_20 ,
V_245 -> V_247 , V_245 -> V_248 ) ;
}
V_15 = F_131 ( V_130 ) ;
V_16 = V_15 + V_245 -> V_247 + V_245 -> V_248 - 1 ;
V_20 = V_245 -> V_248 ;
V_254 = V_251 -> V_176 ;
if ( F_180 ( V_242 && V_24 -> V_53 ) ) {
V_36 = V_24 -> V_53 -> V_255 ( V_251 , V_64 ,
V_130 , V_15 , V_16 ,
V_254 ) ;
if ( V_36 )
V_242 = 0 ;
else
F_151 ( F_18 ( V_25 ) , V_15 ,
V_130 , 0 ) ;
}
if ( F_180 ( V_242 ) )
goto V_256;
if ( V_24 -> V_53 ) {
V_36 = V_24 -> V_53 -> V_257 ( V_130 , V_254 ) ;
if ( V_36 == - V_144 ) {
V_36 = F_168 ( V_48 , V_64 , V_130 ,
V_15 , V_16 , V_254 ) ;
if ( V_36 == 0 ) {
V_242 = ! V_48 -> V_249 ;
V_64 += V_20 ;
continue;
}
}
ASSERT ( V_36 == - V_154 ) ;
}
V_256:
if ( F_180 ( V_242 ) ) {
T_9 V_258 = F_16 ( V_25 ) ;
T_6 V_129 = V_258 >> V_128 ;
unsigned V_259 ;
V_259 = V_258 & ( V_29 - 1 ) ;
if ( V_130 -> V_127 == V_129 && V_259 )
F_181 ( V_130 , V_259 , V_29 ) ;
F_132 ( V_130 ) ;
} else {
F_172 ( V_130 ) ;
F_119 ( V_130 ) ;
}
F_121 ( V_130 ) ;
V_64 += V_20 ;
if ( F_182 ( ! V_242 ) ) {
if ( V_253 ) {
F_177 ( V_24 ,
V_252 ,
V_253 , 1 ) ;
V_252 = 0 ;
V_253 = 0 ;
}
F_177 ( V_24 , V_15 ,
V_16 - V_15 + 1 , 0 ) ;
} else if ( ! V_253 ) {
V_252 = V_15 ;
V_253 = V_16 + 1 - V_15 ;
} else if ( V_252 + V_253 == V_15 ) {
V_253 += V_16 + 1 - V_15 ;
} else {
F_177 ( V_24 , V_252 ,
V_253 , V_242 ) ;
V_252 = V_15 ;
V_253 = V_16 + 1 - V_15 ;
}
}
if ( V_253 )
F_177 ( V_24 , V_252 , V_253 ,
V_242 ) ;
if ( V_251 -> V_260 )
V_251 -> V_260 ( V_251 , V_48 -> V_249 ) ;
F_142 ( V_48 ) ;
}
struct V_48 *
F_183 ( struct V_261 * V_195 , T_1 V_262 , int V_263 ,
T_3 V_264 )
{
struct V_47 * V_181 ;
struct V_48 * V_48 ;
V_48 = F_184 ( V_264 , V_263 , V_45 ) ;
if ( V_48 == NULL && ( V_265 -> V_7 & V_266 ) ) {
while ( ! V_48 && ( V_263 /= 2 ) ) {
V_48 = F_184 ( V_264 ,
V_263 , V_45 ) ;
}
}
if ( V_48 ) {
V_48 -> V_197 = V_195 ;
V_48 -> V_189 . V_194 = V_262 ;
V_181 = V_47 ( V_48 ) ;
V_181 -> V_232 = NULL ;
V_181 -> V_267 = NULL ;
V_181 -> V_260 = NULL ;
}
return V_48 ;
}
struct V_48 * F_185 ( struct V_48 * V_48 , T_3 V_268 )
{
struct V_47 * V_181 ;
struct V_48 * V_5 ;
V_5 = F_186 ( V_48 , V_268 , V_45 ) ;
if ( V_5 ) {
V_181 = V_47 ( V_5 ) ;
V_181 -> V_232 = NULL ;
V_181 -> V_267 = NULL ;
V_181 -> V_260 = NULL ;
}
return V_5 ;
}
struct V_48 * F_138 ( T_3 V_268 , unsigned int V_269 )
{
struct V_47 * V_181 ;
struct V_48 * V_48 ;
V_48 = F_184 ( V_268 , V_269 , V_45 ) ;
if ( V_48 ) {
V_181 = V_47 ( V_48 ) ;
V_181 -> V_232 = NULL ;
V_181 -> V_267 = NULL ;
V_181 -> V_260 = NULL ;
}
return V_48 ;
}
static int T_4 F_187 ( struct V_48 * V_48 , int V_176 ,
unsigned long V_217 )
{
int V_36 = 0 ;
struct V_244 * V_245 = V_48 -> V_270 + V_48 -> V_223 - 1 ;
struct V_130 * V_130 = V_245 -> V_246 ;
struct V_23 * V_24 = V_48 -> V_231 ;
T_1 V_15 ;
V_15 = F_131 ( V_130 ) + V_245 -> V_247 ;
V_48 -> V_231 = NULL ;
F_188 ( V_48 ) ;
if ( V_24 -> V_53 )
V_36 = V_24 -> V_53 -> V_241 ( V_130 -> V_27 -> V_28 , V_48 ,
V_176 , V_217 , V_15 ) ;
else
F_189 ( V_48 ) ;
F_142 ( V_48 ) ;
return V_36 ;
}
static int F_190 ( struct V_23 * V_24 , struct V_130 * V_130 ,
unsigned long V_64 , T_10 V_271 , struct V_48 * V_48 ,
unsigned long V_217 )
{
int V_36 = 0 ;
if ( V_24 -> V_53 )
V_36 = V_24 -> V_53 -> V_272 ( V_130 , V_64 , V_271 , V_48 ,
V_217 ) ;
return V_36 ;
}
static int F_191 ( int V_273 , int V_274 , struct V_23 * V_24 ,
struct V_275 * V_276 ,
struct V_130 * V_130 , T_11 V_180 ,
T_10 V_271 , unsigned long V_64 ,
struct V_261 * V_195 ,
struct V_48 * * V_277 ,
T_7 V_278 ,
int V_176 ,
unsigned long V_279 ,
unsigned long V_217 ,
bool V_280 )
{
int V_36 = 0 ;
struct V_48 * V_48 ;
int V_161 = 0 ;
int V_281 = V_279 & V_220 ;
T_10 V_282 = F_117 ( T_10 , V_271 , V_29 ) ;
if ( V_277 && * V_277 ) {
V_48 = * V_277 ;
if ( V_281 )
V_161 = V_48 -> V_189 . V_194 == V_180 ;
else
V_161 = F_192 ( V_48 ) == V_180 ;
if ( V_279 != V_217 || ! V_161 ||
V_280 ||
F_190 ( V_24 , V_130 , V_64 , V_282 , V_48 , V_217 ) ||
F_144 ( V_48 , V_130 , V_282 , V_64 ) < V_282 ) {
V_36 = F_187 ( V_48 , V_176 , V_279 ) ;
if ( V_36 < 0 ) {
* V_277 = NULL ;
return V_36 ;
}
V_48 = NULL ;
} else {
if ( V_276 )
F_193 ( V_276 , V_130 , V_282 ) ;
return 0 ;
}
}
V_48 = F_183 ( V_195 , V_180 , V_283 ,
V_125 | V_284 ) ;
if ( ! V_48 )
return - V_43 ;
F_144 ( V_48 , V_130 , V_282 , V_64 ) ;
V_48 -> V_228 = V_278 ;
V_48 -> V_231 = V_24 ;
F_170 ( V_48 , V_273 , V_274 ) ;
if ( V_276 ) {
F_194 ( V_276 , V_48 ) ;
F_193 ( V_276 , V_130 , V_282 ) ;
}
if ( V_277 )
* V_277 = V_48 ;
else
V_36 = F_187 ( V_48 , V_176 , V_217 ) ;
return V_36 ;
}
static void F_195 ( struct V_10 * V_11 ,
struct V_130 * V_130 )
{
if ( ! F_196 ( V_130 ) ) {
F_197 ( V_130 ) ;
F_198 ( V_130 ) ;
F_199 ( V_130 , ( unsigned long ) V_11 ) ;
} else {
F_44 ( V_130 -> V_206 != ( unsigned long ) V_11 ) ;
}
}
void F_200 ( struct V_130 * V_130 )
{
if ( ! F_196 ( V_130 ) ) {
F_197 ( V_130 ) ;
F_198 ( V_130 ) ;
F_199 ( V_130 , V_285 ) ;
}
}
static struct V_212 *
F_201 ( struct V_25 * V_25 , struct V_130 * V_130 , T_10 V_175 ,
T_1 V_15 , T_1 V_20 , T_12 * V_286 ,
struct V_212 * * V_287 )
{
struct V_212 * V_213 ;
if ( V_287 && * V_287 ) {
V_213 = * V_287 ;
if ( F_202 ( V_213 ) && V_15 >= V_213 -> V_15 &&
V_15 < F_203 ( V_213 ) ) {
F_85 ( & V_213 -> V_17 ) ;
return V_213 ;
}
F_161 ( V_213 ) ;
* V_287 = NULL ;
}
V_213 = V_286 ( F_18 ( V_25 ) , V_130 , V_175 , V_15 , V_20 , 0 ) ;
if ( V_287 && ! F_204 ( V_213 ) ) {
F_22 ( * V_287 ) ;
F_85 ( & V_213 -> V_17 ) ;
* V_287 = V_213 ;
}
return V_213 ;
}
static int F_205 ( struct V_23 * V_24 ,
struct V_130 * V_130 ,
T_12 * V_286 ,
struct V_212 * * V_287 ,
struct V_48 * * V_48 , int V_176 ,
unsigned long * V_217 , int V_288 ,
T_1 * V_289 )
{
struct V_25 * V_25 = V_130 -> V_27 -> V_28 ;
T_1 V_15 = F_131 ( V_130 ) ;
T_1 V_290 = V_15 + V_29 - 1 ;
T_1 V_16 ;
T_1 V_291 = V_15 ;
T_1 V_292 ;
T_1 V_293 = F_16 ( V_25 ) ;
T_1 V_218 ;
T_1 V_294 ;
T_11 V_180 ;
struct V_212 * V_213 ;
struct V_261 * V_195 ;
int V_36 = 0 ;
int V_295 = 0 ;
T_10 V_175 = 0 ;
T_10 V_296 ;
T_10 V_297 ;
T_10 V_298 = V_25 -> V_41 -> V_299 ;
unsigned long V_300 = 0 ;
F_200 ( V_130 ) ;
V_16 = V_290 ;
if ( ! F_206 ( V_130 ) ) {
if ( F_207 ( V_130 ) == 0 ) {
F_22 ( V_298 != V_29 ) ;
F_208 ( V_24 , V_15 , V_16 ) ;
goto V_112;
}
}
if ( V_130 -> V_127 == V_293 >> V_128 ) {
char * V_301 ;
T_10 V_302 = V_293 & ( V_29 - 1 ) ;
if ( V_302 ) {
V_296 = V_29 - V_302 ;
V_301 = F_209 ( V_130 ) ;
memset ( V_301 + V_302 , 0 , V_296 ) ;
F_210 ( V_130 ) ;
F_211 ( V_301 ) ;
}
}
while ( V_291 <= V_16 ) {
bool V_280 = false ;
if ( V_291 >= V_293 ) {
char * V_301 ;
struct V_1 * V_104 = NULL ;
V_296 = V_29 - V_175 ;
V_301 = F_209 ( V_130 ) ;
memset ( V_301 + V_175 , 0 , V_296 ) ;
F_210 ( V_130 ) ;
F_211 ( V_301 ) ;
F_178 ( V_24 , V_291 , V_291 + V_296 - 1 ,
& V_104 , V_125 ) ;
F_114 ( V_24 , V_291 ,
V_291 + V_296 - 1 ,
& V_104 , V_125 ) ;
break;
}
V_213 = F_201 ( V_25 , V_130 , V_175 , V_291 ,
V_16 - V_291 + 1 , V_286 , V_287 ) ;
if ( F_204 ( V_213 ) ) {
F_119 ( V_130 ) ;
F_208 ( V_24 , V_291 , V_16 ) ;
break;
}
V_292 = V_291 - V_213 -> V_15 ;
F_22 ( F_203 ( V_213 ) <= V_291 ) ;
F_22 ( V_16 < V_291 ) ;
if ( F_162 ( V_219 , & V_213 -> V_7 ) ) {
V_300 |= V_220 ;
F_163 ( & V_300 ,
V_213 -> V_221 ) ;
}
V_296 = F_126 ( F_203 ( V_213 ) - V_291 , V_16 - V_291 + 1 ) ;
V_294 = F_126 ( F_203 ( V_213 ) - 1 , V_16 ) ;
V_296 = F_212 ( V_296 , V_298 ) ;
if ( V_300 & V_220 ) {
V_297 = V_213 -> V_303 ;
V_180 = V_213 -> V_218 >> 9 ;
} else {
V_180 = ( V_213 -> V_218 + V_292 ) >> 9 ;
V_297 = V_296 ;
}
V_195 = V_213 -> V_195 ;
V_218 = V_213 -> V_218 ;
if ( F_162 ( V_304 , & V_213 -> V_7 ) )
V_218 = V_305 ;
if ( F_162 ( V_219 , & V_213 -> V_7 ) &&
V_289 && * V_289 != ( T_1 ) - 1 &&
* V_289 != V_213 -> V_306 )
V_280 = true ;
if ( V_289 )
* V_289 = V_213 -> V_306 ;
F_161 ( V_213 ) ;
V_213 = NULL ;
if ( V_218 == V_305 ) {
char * V_301 ;
struct V_1 * V_104 = NULL ;
V_301 = F_209 ( V_130 ) ;
memset ( V_301 + V_175 , 0 , V_296 ) ;
F_210 ( V_130 ) ;
F_211 ( V_301 ) ;
F_178 ( V_24 , V_291 , V_291 + V_296 - 1 ,
& V_104 , V_125 ) ;
F_114 ( V_24 , V_291 ,
V_291 + V_296 - 1 ,
& V_104 , V_125 ) ;
V_291 = V_291 + V_296 ;
V_175 += V_296 ;
continue;
}
if ( F_113 ( V_24 , V_291 , V_294 ,
V_167 , 1 , NULL ) ) {
F_130 ( V_24 , V_130 ) ;
F_208 ( V_24 , V_291 , V_291 + V_296 - 1 ) ;
V_291 = V_291 + V_296 ;
V_175 += V_296 ;
continue;
}
if ( V_218 == V_307 ) {
F_119 ( V_130 ) ;
F_208 ( V_24 , V_291 , V_291 + V_296 - 1 ) ;
V_291 = V_291 + V_296 ;
V_175 += V_296 ;
continue;
}
V_36 = F_191 ( V_240 , V_288 , V_24 , NULL ,
V_130 , V_180 , V_297 , V_175 ,
V_195 , V_48 ,
F_179 , V_176 ,
* V_217 ,
V_300 ,
V_280 ) ;
if ( ! V_36 ) {
V_295 ++ ;
* V_217 = V_300 ;
} else {
F_119 ( V_130 ) ;
F_208 ( V_24 , V_291 , V_291 + V_296 - 1 ) ;
goto V_112;
}
V_291 = V_291 + V_296 ;
V_175 += V_296 ;
}
V_112:
if ( ! V_295 ) {
if ( ! F_213 ( V_130 ) )
F_132 ( V_130 ) ;
F_121 ( V_130 ) ;
}
return V_36 ;
}
static inline void F_214 ( struct V_23 * V_24 ,
struct V_130 * V_151 [] , int V_149 ,
T_1 V_15 , T_1 V_16 ,
T_12 * V_286 ,
struct V_212 * * V_287 ,
struct V_48 * * V_48 , int V_176 ,
unsigned long * V_217 ,
T_1 * V_289 )
{
struct V_25 * V_25 ;
struct V_308 * V_309 ;
int V_127 ;
V_25 = V_151 [ 0 ] -> V_27 -> V_28 ;
while ( 1 ) {
F_215 ( V_24 , V_15 , V_16 ) ;
V_309 = F_216 ( F_18 ( V_25 ) , V_15 ,
V_16 - V_15 + 1 ) ;
if ( ! V_309 )
break;
F_208 ( V_24 , V_15 , V_16 ) ;
F_217 ( V_25 , V_309 , 1 ) ;
F_218 ( V_309 ) ;
}
for ( V_127 = 0 ; V_127 < V_149 ; V_127 ++ ) {
F_205 ( V_24 , V_151 [ V_127 ] , V_286 , V_287 , V_48 ,
V_176 , V_217 , 0 , V_289 ) ;
F_100 ( V_151 [ V_127 ] ) ;
}
}
static void F_219 ( struct V_23 * V_24 ,
struct V_130 * V_151 [] ,
int V_149 , T_12 * V_286 ,
struct V_212 * * V_287 ,
struct V_48 * * V_48 , int V_176 ,
unsigned long * V_217 ,
T_1 * V_289 )
{
T_1 V_15 = 0 ;
T_1 V_16 = 0 ;
T_1 V_310 ;
int V_127 ;
int V_311 = 0 ;
for ( V_127 = 0 ; V_127 < V_149 ; V_127 ++ ) {
V_310 = F_131 ( V_151 [ V_127 ] ) ;
if ( ! V_16 ) {
V_15 = V_310 ;
V_16 = V_15 + V_29 - 1 ;
V_311 = V_127 ;
} else if ( V_16 + 1 == V_310 ) {
V_16 += V_29 ;
} else {
F_214 ( V_24 , & V_151 [ V_311 ] ,
V_127 - V_311 , V_15 ,
V_16 , V_286 , V_287 ,
V_48 , V_176 , V_217 ,
V_289 ) ;
V_15 = V_310 ;
V_16 = V_15 + V_29 - 1 ;
V_311 = V_127 ;
}
}
if ( V_16 )
F_214 ( V_24 , & V_151 [ V_311 ] ,
V_127 - V_311 , V_15 ,
V_16 , V_286 , V_287 , V_48 ,
V_176 , V_217 ,
V_289 ) ;
}
static int F_220 ( struct V_23 * V_24 ,
struct V_130 * V_130 ,
T_12 * V_286 ,
struct V_48 * * V_48 , int V_176 ,
unsigned long * V_217 , int V_288 )
{
struct V_25 * V_25 = V_130 -> V_27 -> V_28 ;
struct V_308 * V_309 ;
T_1 V_15 = F_131 ( V_130 ) ;
T_1 V_16 = V_15 + V_29 - 1 ;
int V_36 ;
while ( 1 ) {
F_215 ( V_24 , V_15 , V_16 ) ;
V_309 = F_216 ( F_18 ( V_25 ) , V_15 ,
V_29 ) ;
if ( ! V_309 )
break;
F_208 ( V_24 , V_15 , V_16 ) ;
F_217 ( V_25 , V_309 , 1 ) ;
F_218 ( V_309 ) ;
}
V_36 = F_205 ( V_24 , V_130 , V_286 , NULL , V_48 , V_176 ,
V_217 , V_288 , NULL ) ;
return V_36 ;
}
int F_221 ( struct V_23 * V_24 , struct V_130 * V_130 ,
T_12 * V_286 , int V_176 )
{
struct V_48 * V_48 = NULL ;
unsigned long V_217 = 0 ;
int V_36 ;
V_36 = F_220 ( V_24 , V_130 , V_286 , & V_48 , V_176 ,
& V_217 , 0 ) ;
if ( V_48 )
V_36 = F_187 ( V_48 , V_176 , V_217 ) ;
return V_36 ;
}
static void F_222 ( struct V_275 * V_276 ,
unsigned long V_312 )
{
V_276 -> V_313 -= V_312 ;
}
static T_13 int F_223 ( struct V_25 * V_25 ,
struct V_130 * V_130 , struct V_275 * V_276 ,
struct V_314 * V_315 ,
T_1 V_140 ,
unsigned long * V_312 )
{
struct V_23 * V_24 = V_315 -> V_24 ;
T_1 V_290 = V_140 + V_29 - 1 ;
T_1 V_316 ;
T_1 V_317 = 0 ;
T_1 V_141 = 0 ;
int V_36 ;
int V_318 = 0 ;
if ( V_315 -> V_319 || ! V_24 -> V_53 || ! V_24 -> V_53 -> V_320 )
return 0 ;
while ( V_141 < V_290 ) {
V_316 = F_112 ( V_25 , V_24 ,
V_130 ,
& V_140 ,
& V_141 ,
V_321 ) ;
if ( V_316 == 0 ) {
V_140 = V_141 + 1 ;
continue;
}
V_36 = V_24 -> V_53 -> V_320 ( V_25 , V_130 ,
V_140 ,
V_141 ,
& V_318 ,
V_312 ) ;
if ( V_36 ) {
F_119 ( V_130 ) ;
V_36 = V_36 < 0 ? V_36 : - V_154 ;
goto V_322;
}
V_317 += ( V_141 - V_140 +
V_29 ) >> V_128 ;
V_140 = V_141 + 1 ;
}
if ( V_276 -> V_313 < V_317 ) {
int V_323 = 8192 ;
if ( V_317 < V_323 * 2 )
V_323 = V_317 ;
V_276 -> V_313 = F_117 ( T_1 , V_317 ,
V_323 ) ;
}
if ( V_318 ) {
V_276 -> V_313 -= * V_312 ;
return 1 ;
}
V_36 = 0 ;
V_322:
return V_36 ;
}
static T_13 int F_224 ( struct V_25 * V_25 ,
struct V_130 * V_130 ,
struct V_275 * V_276 ,
struct V_314 * V_315 ,
T_9 V_258 ,
unsigned long V_312 ,
int V_324 , int * V_325 )
{
struct V_23 * V_24 = V_315 -> V_24 ;
T_1 V_15 = F_131 ( V_130 ) ;
T_1 V_290 = V_15 + V_29 - 1 ;
T_1 V_16 ;
T_1 V_291 = V_15 ;
T_1 V_292 ;
T_1 V_218 ;
T_1 V_296 ;
T_11 V_180 ;
struct V_212 * V_213 ;
struct V_261 * V_195 ;
T_10 V_175 = 0 ;
T_10 V_298 ;
int V_36 = 0 ;
int V_295 = 0 ;
bool V_326 ;
if ( V_24 -> V_53 && V_24 -> V_53 -> V_327 ) {
V_36 = V_24 -> V_53 -> V_327 ( V_130 , V_15 ,
V_290 ) ;
if ( V_36 ) {
if ( V_36 == - V_328 )
V_276 -> V_329 ++ ;
else
F_225 ( V_276 , V_130 ) ;
F_222 ( V_276 , V_312 ) ;
F_121 ( V_130 ) ;
return 1 ;
}
}
F_222 ( V_276 , V_312 + 1 ) ;
V_16 = V_290 ;
if ( V_258 <= V_15 ) {
if ( V_24 -> V_53 && V_24 -> V_53 -> V_243 )
V_24 -> V_53 -> V_243 ( V_130 , V_15 ,
V_290 , NULL , 1 ) ;
goto V_322;
}
V_298 = V_25 -> V_41 -> V_299 ;
while ( V_291 <= V_16 ) {
T_1 V_330 ;
if ( V_291 >= V_258 ) {
if ( V_24 -> V_53 && V_24 -> V_53 -> V_243 )
V_24 -> V_53 -> V_243 ( V_130 , V_291 ,
V_290 , NULL , 1 ) ;
break;
}
V_213 = V_315 -> V_286 ( F_18 ( V_25 ) , V_130 , V_175 , V_291 ,
V_16 - V_291 + 1 , 1 ) ;
if ( F_204 ( V_213 ) ) {
F_119 ( V_130 ) ;
V_36 = F_226 ( V_213 ) ;
break;
}
V_292 = V_291 - V_213 -> V_15 ;
V_330 = F_203 ( V_213 ) ;
F_22 ( V_330 <= V_291 ) ;
F_22 ( V_16 < V_291 ) ;
V_296 = F_126 ( V_330 - V_291 , V_16 - V_291 + 1 ) ;
V_296 = F_212 ( V_296 , V_298 ) ;
V_180 = ( V_213 -> V_218 + V_292 ) >> 9 ;
V_195 = V_213 -> V_195 ;
V_218 = V_213 -> V_218 ;
V_326 = F_162 ( V_219 , & V_213 -> V_7 ) ;
F_161 ( V_213 ) ;
V_213 = NULL ;
if ( V_326 || V_218 == V_305 ||
V_218 == V_307 ) {
if ( ! V_326 && V_24 -> V_53 &&
V_24 -> V_53 -> V_243 )
V_24 -> V_53 -> V_243 ( V_130 , V_291 ,
V_291 + V_296 - 1 ,
NULL , 1 ) ;
else if ( V_326 ) {
V_295 ++ ;
}
V_291 += V_296 ;
V_175 += V_296 ;
continue;
}
F_104 ( V_24 , V_291 , V_291 + V_296 - 1 ) ;
if ( ! F_227 ( V_130 ) ) {
F_175 ( F_18 ( V_25 ) -> V_30 -> V_31 ,
L_21 ,
V_130 -> V_127 , V_291 , V_16 ) ;
}
V_36 = F_191 ( V_199 , V_324 , V_24 , V_276 ,
V_130 , V_180 , V_296 , V_175 ,
V_195 , & V_315 -> V_48 ,
F_173 ,
0 , 0 , 0 , false ) ;
if ( V_36 ) {
F_119 ( V_130 ) ;
if ( F_227 ( V_130 ) )
F_120 ( V_130 ) ;
}
V_291 = V_291 + V_296 ;
V_175 += V_296 ;
V_295 ++ ;
}
V_322:
* V_325 = V_295 ;
return V_36 ;
}
static int F_228 ( struct V_130 * V_130 , struct V_275 * V_276 ,
void * V_226 )
{
struct V_25 * V_25 = V_130 -> V_27 -> V_28 ;
struct V_314 * V_315 = V_226 ;
T_1 V_15 = F_131 ( V_130 ) ;
T_1 V_290 = V_15 + V_29 - 1 ;
int V_36 ;
int V_295 = 0 ;
T_10 V_175 = 0 ;
T_9 V_258 = F_16 ( V_25 ) ;
unsigned long V_129 = V_258 >> V_128 ;
int V_324 = 0 ;
unsigned long V_312 = 0 ;
if ( V_276 -> V_331 == V_332 )
V_324 = V_200 ;
F_229 ( V_130 , V_25 , V_276 ) ;
F_44 ( ! F_230 ( V_130 ) ) ;
F_231 ( V_130 ) ;
V_175 = V_258 & ( V_29 - 1 ) ;
if ( V_130 -> V_127 > V_129 ||
( V_130 -> V_127 == V_129 && ! V_175 ) ) {
V_130 -> V_27 -> V_333 -> V_334 ( V_130 , 0 , V_29 ) ;
F_121 ( V_130 ) ;
return 0 ;
}
if ( V_130 -> V_127 == V_129 ) {
char * V_301 ;
V_301 = F_209 ( V_130 ) ;
memset ( V_301 + V_175 , 0 ,
V_29 - V_175 ) ;
F_211 ( V_301 ) ;
F_210 ( V_130 ) ;
}
V_175 = 0 ;
F_200 ( V_130 ) ;
V_36 = F_223 ( V_25 , V_130 , V_276 , V_315 , V_15 , & V_312 ) ;
if ( V_36 == 1 )
goto V_335;
if ( V_36 )
goto V_322;
V_36 = F_224 ( V_25 , V_130 , V_276 , V_315 ,
V_258 , V_312 , V_324 , & V_295 ) ;
if ( V_36 == 1 )
goto V_335;
V_322:
if ( V_295 == 0 ) {
F_105 ( V_130 ) ;
F_120 ( V_130 ) ;
}
if ( F_213 ( V_130 ) ) {
V_36 = V_36 < 0 ? V_36 : - V_154 ;
F_171 ( V_130 , V_36 , V_15 , V_290 ) ;
}
F_121 ( V_130 ) ;
return V_36 ;
V_335:
return 0 ;
}
void F_232 ( struct V_10 * V_11 )
{
F_233 ( & V_11 -> V_336 , V_337 ,
V_115 ) ;
}
static T_13 int
F_234 ( struct V_10 * V_11 ,
struct V_40 * V_31 ,
struct V_314 * V_315 )
{
unsigned long V_152 , V_203 ;
int V_338 = 0 ;
int V_36 = 0 ;
if ( ! F_235 ( V_11 ) ) {
V_338 = 1 ;
F_236 ( V_315 ) ;
F_237 ( V_11 ) ;
}
if ( F_162 ( V_337 , & V_11 -> V_336 ) ) {
F_238 ( V_11 ) ;
if ( ! V_315 -> V_339 )
return 0 ;
if ( ! V_338 ) {
F_236 ( V_315 ) ;
V_338 = 1 ;
}
while ( 1 ) {
F_232 ( V_11 ) ;
F_237 ( V_11 ) ;
if ( ! F_162 ( V_337 , & V_11 -> V_336 ) )
break;
F_238 ( V_11 ) ;
}
}
F_74 ( & V_11 -> V_340 ) ;
if ( F_239 ( V_341 , & V_11 -> V_336 ) ) {
F_240 ( V_337 , & V_11 -> V_336 ) ;
F_77 ( & V_11 -> V_340 ) ;
F_241 ( V_11 , V_342 ) ;
F_242 ( & V_31 -> V_343 ,
- V_11 -> V_20 ,
V_31 -> V_344 ) ;
V_36 = 1 ;
} else {
F_77 ( & V_11 -> V_340 ) ;
}
F_238 ( V_11 ) ;
if ( ! V_36 )
return V_36 ;
V_203 = F_150 ( V_11 -> V_15 , V_11 -> V_20 ) ;
for ( V_152 = 0 ; V_152 < V_203 ; V_152 ++ ) {
struct V_130 * V_68 = V_11 -> V_151 [ V_152 ] ;
if ( ! F_243 ( V_68 ) ) {
if ( ! V_338 ) {
F_236 ( V_315 ) ;
V_338 = 1 ;
}
F_122 ( V_68 ) ;
}
}
return V_36 ;
}
static void F_244 ( struct V_10 * V_11 )
{
F_245 ( V_337 , & V_11 -> V_336 ) ;
F_246 () ;
F_247 ( & V_11 -> V_336 , V_337 ) ;
}
static void F_248 ( struct V_130 * V_130 )
{
struct V_10 * V_11 = (struct V_10 * ) V_130 -> V_206 ;
F_119 ( V_130 ) ;
if ( F_249 ( V_345 , & V_11 -> V_336 ) )
return;
switch ( V_11 -> V_346 ) {
case - 1 :
F_240 ( V_347 , & V_11 -> V_31 -> V_7 ) ;
break;
case 0 :
F_240 ( V_348 , & V_11 -> V_31 -> V_7 ) ;
break;
case 1 :
F_240 ( V_349 , & V_11 -> V_31 -> V_7 ) ;
break;
default:
F_250 () ;
}
}
static void F_251 ( struct V_48 * V_48 )
{
struct V_244 * V_245 ;
struct V_10 * V_11 ;
int V_152 , V_322 ;
F_174 (bvec, bio, i) {
struct V_130 * V_130 = V_245 -> V_246 ;
V_11 = (struct V_10 * ) V_130 -> V_206 ;
F_22 ( ! V_11 ) ;
V_322 = F_43 ( & V_11 -> V_350 ) ;
if ( V_48 -> V_249 ||
F_162 ( V_345 , & V_11 -> V_336 ) ) {
F_172 ( V_130 ) ;
F_248 ( V_130 ) ;
}
F_120 ( V_130 ) ;
if ( ! V_322 )
continue;
F_244 ( V_11 ) ;
}
F_142 ( V_48 ) ;
}
static T_13 int F_252 ( struct V_10 * V_11 ,
struct V_40 * V_31 ,
struct V_275 * V_276 ,
struct V_314 * V_315 )
{
struct V_261 * V_195 = V_31 -> V_229 -> V_230 ;
struct V_23 * V_24 = & F_18 ( V_31 -> V_205 ) -> V_159 ;
T_1 V_64 = V_11 -> V_15 ;
T_14 V_351 ;
unsigned long V_152 , V_203 ;
unsigned long V_217 = 0 ;
unsigned long V_15 , V_16 ;
int V_324 = ( V_315 -> V_339 ? V_200 : 0 ) | V_352 ;
int V_36 = 0 ;
F_245 ( V_345 , & V_11 -> V_336 ) ;
V_203 = F_150 ( V_11 -> V_15 , V_11 -> V_20 ) ;
F_39 ( & V_11 -> V_350 , V_203 ) ;
if ( F_253 ( V_11 ) == V_353 )
V_217 = V_354 ;
V_351 = F_254 ( V_11 ) ;
if ( F_255 ( V_11 ) > 0 ) {
V_16 = F_256 ( V_351 ) ;
F_257 ( V_11 , V_16 , V_11 -> V_20 - V_16 ) ;
} else {
V_15 = F_258 ( V_351 ) ;
V_16 = F_259 ( V_11 ) + F_260 ( V_31 , V_11 ) ;
F_257 ( V_11 , V_15 , V_16 - V_15 ) ;
}
for ( V_152 = 0 ; V_152 < V_203 ; V_152 ++ ) {
struct V_130 * V_68 = V_11 -> V_151 [ V_152 ] ;
F_99 ( V_68 ) ;
F_105 ( V_68 ) ;
V_36 = F_191 ( V_199 , V_324 , V_24 , V_276 ,
V_68 , V_64 >> 9 , V_29 , 0 , V_195 ,
& V_315 -> V_48 ,
F_251 ,
0 , V_315 -> V_217 , V_217 , false ) ;
V_315 -> V_217 = V_217 ;
if ( V_36 ) {
F_248 ( V_68 ) ;
if ( F_227 ( V_68 ) )
F_120 ( V_68 ) ;
if ( F_261 ( V_203 - V_152 , & V_11 -> V_350 ) )
F_244 ( V_11 ) ;
V_36 = - V_154 ;
break;
}
V_64 += V_29 ;
F_222 ( V_276 , 1 ) ;
F_121 ( V_68 ) ;
}
if ( F_182 ( V_36 ) ) {
for (; V_152 < V_203 ; V_152 ++ ) {
struct V_130 * V_68 = V_11 -> V_151 [ V_152 ] ;
F_99 ( V_68 ) ;
F_121 ( V_68 ) ;
}
}
return V_36 ;
}
int F_262 ( struct V_51 * V_27 ,
struct V_275 * V_276 )
{
struct V_23 * V_24 = & F_18 ( V_27 -> V_28 ) -> V_159 ;
struct V_40 * V_31 = F_18 ( V_27 -> V_28 ) -> V_30 -> V_31 ;
struct V_10 * V_11 , * V_355 = NULL ;
struct V_314 V_315 = {
. V_48 = NULL ,
. V_24 = V_24 ,
. V_319 = 0 ,
. V_339 = V_276 -> V_331 == V_332 ,
. V_217 = 0 ,
} ;
int V_36 = 0 ;
int V_322 = 0 ;
int V_356 = 0 ;
struct V_357 V_358 ;
int V_149 ;
T_6 V_127 ;
T_6 V_16 ;
int V_359 = 0 ;
int V_360 ;
F_263 ( & V_358 , 0 ) ;
if ( V_276 -> V_361 ) {
V_127 = V_27 -> V_362 ;
V_16 = - 1 ;
} else {
V_127 = V_276 -> V_363 >> V_128 ;
V_16 = V_276 -> V_364 >> V_128 ;
V_359 = 1 ;
}
if ( V_276 -> V_331 == V_332 )
V_360 = V_365 ;
else
V_360 = V_366 ;
V_367:
if ( V_276 -> V_331 == V_332 )
F_264 ( V_27 , V_127 , V_16 ) ;
while ( ! V_322 && ! V_356 && ( V_127 <= V_16 ) &&
( V_149 = F_265 ( & V_358 , V_27 , & V_127 , V_360 ,
F_126 ( V_16 - V_127 , ( T_6 ) V_368 - 1 ) + 1 ) ) ) {
unsigned V_152 ;
V_359 = 1 ;
for ( V_152 = 0 ; V_152 < V_149 ; V_152 ++ ) {
struct V_130 * V_130 = V_358 . V_151 [ V_152 ] ;
if ( ! F_196 ( V_130 ) )
continue;
if ( ! V_276 -> V_361 && V_130 -> V_127 > V_16 ) {
V_322 = 1 ;
break;
}
F_74 ( & V_27 -> V_369 ) ;
if ( ! F_196 ( V_130 ) ) {
F_77 ( & V_27 -> V_369 ) ;
continue;
}
V_11 = (struct V_10 * ) V_130 -> V_206 ;
if ( F_44 ( ! V_11 ) ) {
F_77 ( & V_27 -> V_369 ) ;
continue;
}
if ( V_11 == V_355 ) {
F_77 ( & V_27 -> V_369 ) ;
continue;
}
V_36 = F_266 ( & V_11 -> V_17 ) ;
F_77 ( & V_27 -> V_369 ) ;
if ( ! V_36 )
continue;
V_355 = V_11 ;
V_36 = F_234 ( V_11 , V_31 , & V_315 ) ;
if ( ! V_36 ) {
F_267 ( V_11 ) ;
continue;
}
V_36 = F_252 ( V_11 , V_31 , V_276 , & V_315 ) ;
if ( V_36 ) {
V_322 = 1 ;
F_267 ( V_11 ) ;
break;
}
F_267 ( V_11 ) ;
V_356 = V_276 -> V_313 <= 0 ;
}
F_268 ( & V_358 ) ;
F_78 () ;
}
if ( ! V_359 && ! V_322 ) {
V_359 = 1 ;
V_127 = 0 ;
goto V_367;
}
F_236 ( & V_315 ) ;
return V_36 ;
}
static int F_269 ( struct V_51 * V_27 ,
struct V_275 * V_276 ,
T_15 V_370 , void * V_226 ,
void (* F_270)( void * ) )
{
struct V_25 * V_25 = V_27 -> V_28 ;
int V_36 = 0 ;
int V_322 = 0 ;
int V_356 = 0 ;
struct V_357 V_358 ;
int V_149 ;
T_6 V_127 ;
T_6 V_16 ;
T_6 V_371 ;
int V_372 = 0 ;
int V_359 = 0 ;
int V_360 ;
if ( ! F_271 ( V_25 ) )
return 0 ;
F_263 ( & V_358 , 0 ) ;
if ( V_276 -> V_361 ) {
V_127 = V_27 -> V_362 ;
V_16 = - 1 ;
} else {
V_127 = V_276 -> V_363 >> V_128 ;
V_16 = V_276 -> V_364 >> V_128 ;
if ( V_276 -> V_363 == 0 && V_276 -> V_364 == V_373 )
V_372 = 1 ;
V_359 = 1 ;
}
if ( V_276 -> V_331 == V_332 )
V_360 = V_365 ;
else
V_360 = V_366 ;
V_367:
if ( V_276 -> V_331 == V_332 )
F_264 ( V_27 , V_127 , V_16 ) ;
V_371 = V_127 ;
while ( ! V_322 && ! V_356 && ( V_127 <= V_16 ) &&
( V_149 = F_265 ( & V_358 , V_27 , & V_127 , V_360 ,
F_126 ( V_16 - V_127 , ( T_6 ) V_368 - 1 ) + 1 ) ) ) {
unsigned V_152 ;
V_359 = 1 ;
for ( V_152 = 0 ; V_152 < V_149 ; V_152 ++ ) {
struct V_130 * V_130 = V_358 . V_151 [ V_152 ] ;
V_371 = V_130 -> V_127 ;
if ( ! F_243 ( V_130 ) ) {
F_270 ( V_226 ) ;
F_122 ( V_130 ) ;
}
if ( F_182 ( V_130 -> V_27 != V_27 ) ) {
F_121 ( V_130 ) ;
continue;
}
if ( ! V_276 -> V_361 && V_130 -> V_127 > V_16 ) {
V_322 = 1 ;
F_121 ( V_130 ) ;
continue;
}
if ( V_276 -> V_331 != V_374 ) {
if ( F_227 ( V_130 ) )
F_270 ( V_226 ) ;
F_272 ( V_130 ) ;
}
if ( F_227 ( V_130 ) ||
! F_99 ( V_130 ) ) {
F_121 ( V_130 ) ;
continue;
}
V_36 = (* V_370)( V_130 , V_276 , V_226 ) ;
if ( F_182 ( V_36 == V_375 ) ) {
F_121 ( V_130 ) ;
V_36 = 0 ;
}
if ( V_36 < 0 ) {
V_371 = V_130 -> V_127 + 1 ;
V_322 = 1 ;
break;
}
V_356 = V_276 -> V_313 <= 0 ;
}
F_268 ( & V_358 ) ;
F_78 () ;
}
if ( ! V_359 && ! V_322 ) {
V_359 = 1 ;
V_127 = 0 ;
goto V_367;
}
if ( V_276 -> V_361 || ( V_276 -> V_313 > 0 && V_372 ) )
V_27 -> V_362 = V_371 ;
F_273 ( V_25 ) ;
return V_36 ;
}
static void F_274 ( struct V_314 * V_315 )
{
if ( V_315 -> V_48 ) {
int V_36 ;
F_170 ( V_315 -> V_48 , V_199 ,
V_315 -> V_339 ? V_200 : 0 ) ;
V_36 = F_187 ( V_315 -> V_48 , 0 , V_315 -> V_217 ) ;
F_22 ( V_36 < 0 ) ;
V_315 -> V_48 = NULL ;
}
}
static T_5 void F_236 ( void * V_226 )
{
struct V_314 * V_315 = V_226 ;
F_274 ( V_315 ) ;
}
int F_275 ( struct V_23 * V_24 , struct V_130 * V_130 ,
T_12 * V_286 ,
struct V_275 * V_276 )
{
int V_36 ;
struct V_314 V_315 = {
. V_48 = NULL ,
. V_24 = V_24 ,
. V_286 = V_286 ,
. V_319 = 0 ,
. V_339 = V_276 -> V_331 == V_332 ,
. V_217 = 0 ,
} ;
V_36 = F_228 ( V_130 , V_276 , & V_315 ) ;
F_274 ( & V_315 ) ;
return V_36 ;
}
int F_276 ( struct V_23 * V_24 , struct V_25 * V_25 ,
T_1 V_15 , T_1 V_16 , T_12 * V_286 ,
int V_376 )
{
int V_36 = 0 ;
struct V_51 * V_27 = V_25 -> V_131 ;
struct V_130 * V_130 ;
unsigned long V_149 = ( V_16 - V_15 + V_29 ) >>
V_128 ;
struct V_314 V_315 = {
. V_48 = NULL ,
. V_24 = V_24 ,
. V_286 = V_286 ,
. V_319 = 1 ,
. V_339 = V_376 == V_332 ,
. V_217 = 0 ,
} ;
struct V_275 V_377 = {
. V_331 = V_376 ,
. V_313 = V_149 * 2 ,
. V_363 = V_15 ,
. V_364 = V_16 + 1 ,
} ;
while ( V_15 <= V_16 ) {
V_130 = F_98 ( V_27 , V_15 >> V_128 ) ;
if ( F_99 ( V_130 ) )
V_36 = F_228 ( V_130 , & V_377 , & V_315 ) ;
else {
if ( V_24 -> V_53 && V_24 -> V_53 -> V_243 )
V_24 -> V_53 -> V_243 ( V_130 , V_15 ,
V_15 + V_29 - 1 ,
NULL , 1 ) ;
F_121 ( V_130 ) ;
}
F_100 ( V_130 ) ;
V_15 += V_29 ;
}
F_274 ( & V_315 ) ;
return V_36 ;
}
int F_277 ( struct V_23 * V_24 ,
struct V_51 * V_27 ,
T_12 * V_286 ,
struct V_275 * V_276 )
{
int V_36 = 0 ;
struct V_314 V_315 = {
. V_48 = NULL ,
. V_24 = V_24 ,
. V_286 = V_286 ,
. V_319 = 0 ,
. V_339 = V_276 -> V_331 == V_332 ,
. V_217 = 0 ,
} ;
V_36 = F_269 ( V_27 , V_276 , F_228 , & V_315 ,
F_236 ) ;
F_274 ( & V_315 ) ;
return V_36 ;
}
int F_278 ( struct V_23 * V_24 ,
struct V_51 * V_27 ,
struct V_4 * V_151 , unsigned V_149 ,
T_12 V_286 )
{
struct V_48 * V_48 = NULL ;
unsigned V_378 ;
unsigned long V_217 = 0 ;
struct V_130 * V_379 [ 16 ] ;
struct V_130 * V_130 ;
struct V_212 * V_287 = NULL ;
int V_295 = 0 ;
T_1 V_289 = ( T_1 ) - 1 ;
for ( V_378 = 0 ; V_378 < V_149 ; V_378 ++ ) {
V_130 = F_11 ( V_151 -> V_79 , struct V_130 , V_380 ) ;
F_279 ( & V_130 -> V_7 ) ;
F_8 ( & V_130 -> V_380 ) ;
if ( F_280 ( V_130 , V_27 ,
V_130 -> V_127 ,
F_281 ( V_27 ) ) ) {
F_100 ( V_130 ) ;
continue;
}
V_379 [ V_295 ++ ] = V_130 ;
if ( V_295 < F_282 ( V_379 ) )
continue;
F_219 ( V_24 , V_379 , V_295 , V_286 , & V_287 ,
& V_48 , 0 , & V_217 , & V_289 ) ;
V_295 = 0 ;
}
if ( V_295 )
F_219 ( V_24 , V_379 , V_295 , V_286 , & V_287 ,
& V_48 , 0 , & V_217 , & V_289 ) ;
if ( V_287 )
F_161 ( V_287 ) ;
F_22 ( ! F_10 ( V_151 ) ) ;
if ( V_48 )
return F_187 ( V_48 , 0 , V_217 ) ;
return 0 ;
}
int F_283 ( struct V_23 * V_24 ,
struct V_130 * V_130 , unsigned long V_64 )
{
struct V_1 * V_103 = NULL ;
T_1 V_15 = F_131 ( V_130 ) ;
T_1 V_16 = V_15 + V_29 - 1 ;
T_10 V_298 = V_130 -> V_27 -> V_28 -> V_41 -> V_299 ;
V_15 += F_212 ( V_64 , V_298 ) ;
if ( V_15 > V_16 )
return 0 ;
F_95 ( V_24 , V_15 , V_16 , & V_103 ) ;
F_272 ( V_130 ) ;
F_93 ( V_24 , V_15 , V_16 ,
V_126 | V_99 | V_107 |
V_381 ,
1 , 1 , & V_103 , V_125 ) ;
return 0 ;
}
static int F_284 ( struct V_214 * V_382 ,
struct V_23 * V_24 ,
struct V_130 * V_130 , T_3 V_56 )
{
T_1 V_15 = F_131 ( V_130 ) ;
T_1 V_16 = V_15 + V_29 - 1 ;
int V_36 = 1 ;
if ( F_113 ( V_24 , V_15 , V_16 ,
V_85 , 0 , NULL ) )
V_36 = 0 ;
else {
V_36 = F_93 ( V_24 , V_15 , V_16 ,
~ ( V_126 | V_383 ) ,
0 , 0 , NULL , V_56 ) ;
if ( V_36 < 0 )
V_36 = 0 ;
else
V_36 = 1 ;
}
return V_36 ;
}
int F_285 ( struct V_214 * V_382 ,
struct V_23 * V_24 , struct V_130 * V_130 ,
T_3 V_56 )
{
struct V_212 * V_213 ;
T_1 V_15 = F_131 ( V_130 ) ;
T_1 V_16 = V_15 + V_29 - 1 ;
if ( F_73 ( V_56 ) &&
V_130 -> V_27 -> V_28 -> V_258 > V_384 ) {
T_1 V_20 ;
while ( V_15 <= V_16 ) {
V_20 = V_16 - V_15 + 1 ;
F_286 ( & V_382 -> V_55 ) ;
V_213 = F_159 ( V_382 , V_15 , V_20 ) ;
if ( ! V_213 ) {
F_287 ( & V_382 -> V_55 ) ;
break;
}
if ( F_162 ( V_385 , & V_213 -> V_7 ) ||
V_213 -> V_15 != V_15 ) {
F_287 ( & V_382 -> V_55 ) ;
F_161 ( V_213 ) ;
break;
}
if ( ! F_113 ( V_24 , V_213 -> V_15 ,
F_203 ( V_213 ) - 1 ,
V_126 | V_386 ,
0 , NULL ) ) {
F_288 ( V_382 , V_213 ) ;
F_161 ( V_213 ) ;
}
V_15 = F_203 ( V_213 ) ;
F_287 ( & V_382 -> V_55 ) ;
F_161 ( V_213 ) ;
}
}
return F_284 ( V_382 , V_24 , V_130 , V_56 ) ;
}
static struct V_212 * F_289 ( struct V_25 * V_25 ,
T_1 V_64 ,
T_1 V_162 ,
T_12 * V_286 )
{
T_1 V_387 = F_290 ( V_25 ) ;
struct V_212 * V_213 ;
T_1 V_20 ;
if ( V_64 >= V_162 )
return NULL ;
while ( 1 ) {
V_20 = V_162 - V_64 ;
if ( V_20 == 0 )
break;
V_20 = F_212 ( V_20 , V_387 ) ;
V_213 = V_286 ( F_18 ( V_25 ) , NULL , 0 , V_64 , V_20 , 0 ) ;
if ( F_204 ( V_213 ) )
return V_213 ;
if ( ! F_162 ( V_388 , & V_213 -> V_7 ) &&
V_213 -> V_218 != V_305 ) {
return V_213 ;
}
V_64 = F_203 ( V_213 ) ;
F_161 ( V_213 ) ;
if ( V_64 >= V_162 )
break;
}
return NULL ;
}
int F_291 ( struct V_25 * V_25 , struct V_389 * V_390 ,
T_16 V_15 , T_16 V_20 , T_12 * V_286 )
{
int V_36 = 0 ;
T_1 V_259 = V_15 ;
T_1 F_127 = V_15 + V_20 ;
T_14 V_7 = 0 ;
T_14 V_391 ;
T_1 V_162 ;
T_1 V_392 = 0 ;
T_1 V_393 = 0 ;
T_1 V_26 = F_16 ( V_25 ) ;
struct V_394 V_395 ;
struct V_212 * V_213 = NULL ;
struct V_1 * V_103 = NULL ;
struct V_396 * V_397 ;
struct V_398 * V_30 = F_18 ( V_25 ) -> V_30 ;
int V_16 = 0 ;
T_1 V_399 = 0 ;
T_1 V_400 = 0 ;
T_1 V_330 = 0 ;
if ( V_20 == 0 )
return - V_401 ;
V_397 = F_292 () ;
if ( ! V_397 )
return - V_43 ;
V_397 -> V_402 = 1 ;
V_15 = F_293 ( V_15 , F_290 ( V_25 ) ) ;
V_20 = F_294 ( F_127 , F_290 ( V_25 ) ) - V_15 ;
V_36 = F_295 ( NULL , V_30 , V_397 ,
F_19 ( F_18 ( V_25 ) ) , - 1 , 0 ) ;
if ( V_36 < 0 ) {
F_296 ( V_397 ) ;
return V_36 ;
} else {
F_44 ( ! V_36 ) ;
if ( V_36 == 1 )
V_36 = 0 ;
}
V_397 -> V_403 [ 0 ] -- ;
F_297 ( V_397 -> V_404 [ 0 ] , & V_395 , V_397 -> V_403 [ 0 ] ) ;
V_391 = V_395 . type ;
if ( V_395 . V_405 != F_19 ( F_18 ( V_25 ) ) ||
V_391 != V_406 ) {
V_162 = ( T_1 ) - 1 ;
V_392 = V_26 ;
} else {
V_162 = V_395 . V_64 ;
V_392 = V_162 + 1 ;
}
F_298 ( V_397 ) ;
if ( V_162 < V_26 ) {
V_162 = ( T_1 ) - 1 ;
V_392 = V_26 ;
}
F_95 ( & F_18 ( V_25 ) -> V_159 , V_15 , V_15 + V_20 - 1 ,
& V_103 ) ;
V_213 = F_289 ( V_25 , V_15 , V_392 ,
V_286 ) ;
if ( ! V_213 )
goto V_112;
if ( F_299 ( V_213 ) ) {
V_36 = F_300 ( V_213 ) ;
goto V_112;
}
while ( ! V_16 ) {
T_1 V_407 = 0 ;
if ( V_213 -> V_15 >= F_127 || F_203 ( V_213 ) < V_259 )
break;
V_399 = F_127 ( V_213 -> V_15 , V_259 ) ;
if ( ! F_162 ( V_219 , & V_213 -> V_7 ) )
V_407 = V_399 - V_213 -> V_15 ;
V_330 = F_203 ( V_213 ) ;
V_400 = V_330 - V_399 ;
V_393 = 0 ;
V_7 = 0 ;
V_259 = F_203 ( V_213 ) ;
if ( V_259 >= F_127 )
V_16 = 1 ;
if ( V_213 -> V_218 == V_408 ) {
V_16 = 1 ;
V_7 |= V_409 ;
} else if ( V_213 -> V_218 == V_307 ) {
V_7 |= ( V_410 |
V_411 ) ;
} else if ( V_213 -> V_218 == V_412 ) {
V_7 |= ( V_413 |
V_414 ) ;
} else if ( V_390 -> V_415 ) {
struct V_416 * V_417 ;
T_1 V_418 = V_213 -> V_218 -
( V_213 -> V_15 - V_213 -> V_306 ) ;
V_393 = V_213 -> V_218 + V_407 ;
V_417 = F_301 ( V_30 ) ;
if ( F_299 ( V_417 ) )
V_417 = NULL ;
V_36 = F_302 ( V_417 , V_30 -> V_31 ,
V_30 -> V_405 ,
F_19 ( F_18 ( V_25 ) ) , V_418 ) ;
if ( V_417 )
F_303 ( V_417 ) ;
if ( V_36 < 0 )
goto V_419;
if ( V_36 )
V_7 |= V_420 ;
V_36 = 0 ;
}
if ( F_162 ( V_219 , & V_213 -> V_7 ) )
V_7 |= V_421 ;
if ( F_162 ( V_304 , & V_213 -> V_7 ) )
V_7 |= V_422 ;
F_161 ( V_213 ) ;
V_213 = NULL ;
if ( ( V_399 >= V_162 ) || V_400 == ( T_1 ) - 1 ||
( V_162 == ( T_1 ) - 1 && V_26 <= V_330 ) ) {
V_7 |= V_409 ;
V_16 = 1 ;
}
V_213 = F_289 ( V_25 , V_259 , V_392 ,
V_286 ) ;
if ( F_299 ( V_213 ) ) {
V_36 = F_300 ( V_213 ) ;
goto V_112;
}
if ( ! V_213 ) {
V_7 |= V_409 ;
V_16 = 1 ;
}
V_36 = F_304 ( V_390 , V_399 , V_393 ,
V_400 , V_7 ) ;
if ( V_36 ) {
if ( V_36 == 1 )
V_36 = 0 ;
goto V_419;
}
}
V_419:
F_161 ( V_213 ) ;
V_112:
F_296 ( V_397 ) ;
F_114 ( & F_18 ( V_25 ) -> V_159 , V_15 , V_15 + V_20 - 1 ,
& V_103 , V_125 ) ;
return V_36 ;
}
static void F_305 ( struct V_10 * V_11 )
{
F_7 ( & V_11 -> V_14 ) ;
F_14 ( V_21 , V_11 ) ;
}
int F_306 ( struct V_10 * V_11 )
{
return ( F_13 ( & V_11 -> V_350 ) ||
F_162 ( V_337 , & V_11 -> V_336 ) ||
F_162 ( V_341 , & V_11 -> V_336 ) ) ;
}
static void F_307 ( struct V_10 * V_11 )
{
unsigned long V_127 ;
struct V_130 * V_130 ;
int V_423 = ! F_162 ( V_424 , & V_11 -> V_336 ) ;
F_22 ( F_306 ( V_11 ) ) ;
V_127 = F_150 ( V_11 -> V_15 , V_11 -> V_20 ) ;
if ( V_127 == 0 )
return;
do {
V_127 -- ;
V_130 = V_11 -> V_151 [ V_127 ] ;
if ( ! V_130 )
continue;
if ( V_423 )
F_74 ( & V_130 -> V_27 -> V_369 ) ;
if ( F_196 ( V_130 ) &&
V_130 -> V_206 == ( unsigned long ) V_11 ) {
F_22 ( F_162 ( V_341 , & V_11 -> V_336 ) ) ;
F_22 ( F_123 ( V_130 ) ) ;
F_22 ( F_227 ( V_130 ) ) ;
F_308 ( V_130 ) ;
F_199 ( V_130 , 0 ) ;
F_100 ( V_130 ) ;
}
if ( V_423 )
F_77 ( & V_130 -> V_27 -> V_369 ) ;
F_100 ( V_130 ) ;
} while ( V_127 != 0 );
}
static inline void F_309 ( struct V_10 * V_11 )
{
F_307 ( V_11 ) ;
F_305 ( V_11 ) ;
}
static struct V_10 *
F_310 ( struct V_40 * V_31 , T_1 V_15 ,
unsigned long V_20 )
{
struct V_10 * V_11 = NULL ;
V_11 = F_311 ( V_21 , V_125 | V_425 ) ;
V_11 -> V_15 = V_15 ;
V_11 -> V_20 = V_20 ;
V_11 -> V_31 = V_31 ;
V_11 -> V_336 = 0 ;
F_312 ( & V_11 -> V_55 ) ;
F_39 ( & V_11 -> V_426 , 0 ) ;
F_39 ( & V_11 -> V_427 , 0 ) ;
F_39 ( & V_11 -> V_428 , 0 ) ;
F_39 ( & V_11 -> V_429 , 0 ) ;
F_39 ( & V_11 -> V_430 , 0 ) ;
F_39 ( & V_11 -> V_431 , 0 ) ;
V_11 -> V_432 = 0 ;
F_40 ( & V_11 -> V_433 ) ;
F_40 ( & V_11 -> V_434 ) ;
F_3 ( & V_11 -> V_14 , & V_19 ) ;
F_35 ( & V_11 -> V_340 ) ;
F_39 ( & V_11 -> V_17 , 1 ) ;
F_39 ( & V_11 -> V_350 , 0 ) ;
F_313 ( V_435
> V_436 ) ;
F_22 ( V_20 > V_436 ) ;
return V_11 ;
}
struct V_10 * F_314 ( struct V_10 * V_437 )
{
unsigned long V_152 ;
struct V_130 * V_68 ;
struct V_10 * V_5 ;
unsigned long V_203 = F_150 ( V_437 -> V_15 , V_437 -> V_20 ) ;
V_5 = F_310 ( V_437 -> V_31 , V_437 -> V_15 , V_437 -> V_20 ) ;
if ( V_5 == NULL )
return NULL ;
for ( V_152 = 0 ; V_152 < V_203 ; V_152 ++ ) {
V_68 = F_315 ( V_125 ) ;
if ( ! V_68 ) {
F_309 ( V_5 ) ;
return NULL ;
}
F_195 ( V_5 , V_68 ) ;
F_44 ( F_123 ( V_68 ) ) ;
F_132 ( V_68 ) ;
V_5 -> V_151 [ V_152 ] = V_68 ;
F_316 ( F_317 ( V_68 ) , F_317 ( V_437 -> V_151 [ V_152 ] ) ) ;
}
F_240 ( V_438 , & V_5 -> V_336 ) ;
F_240 ( V_424 , & V_5 -> V_336 ) ;
return V_5 ;
}
struct V_10 * F_318 ( struct V_40 * V_31 ,
T_1 V_15 , unsigned long V_20 )
{
struct V_10 * V_11 ;
unsigned long V_203 ;
unsigned long V_152 ;
V_203 = F_150 ( V_15 , V_20 ) ;
V_11 = F_310 ( V_31 , V_15 , V_20 ) ;
if ( ! V_11 )
return NULL ;
for ( V_152 = 0 ; V_152 < V_203 ; V_152 ++ ) {
V_11 -> V_151 [ V_152 ] = F_315 ( V_125 ) ;
if ( ! V_11 -> V_151 [ V_152 ] )
goto V_101;
}
F_319 ( V_11 ) ;
F_320 ( V_11 , 0 ) ;
F_240 ( V_424 , & V_11 -> V_336 ) ;
return V_11 ;
V_101:
for (; V_152 > 0 ; V_152 -- )
F_321 ( V_11 -> V_151 [ V_152 - 1 ] ) ;
F_305 ( V_11 ) ;
return NULL ;
}
struct V_10 * F_322 ( struct V_40 * V_31 ,
T_1 V_15 )
{
return F_318 ( V_31 , V_15 , V_31 -> V_439 ) ;
}
static void F_323 ( struct V_10 * V_11 )
{
int V_17 ;
V_17 = F_13 ( & V_11 -> V_17 ) ;
if ( V_17 >= 2 && F_162 ( V_440 , & V_11 -> V_336 ) )
return;
F_74 ( & V_11 -> V_340 ) ;
if ( ! F_249 ( V_440 , & V_11 -> V_336 ) )
F_85 ( & V_11 -> V_17 ) ;
F_77 ( & V_11 -> V_340 ) ;
}
static void F_324 ( struct V_10 * V_11 ,
struct V_130 * V_441 )
{
unsigned long V_203 , V_152 ;
F_323 ( V_11 ) ;
V_203 = F_150 ( V_11 -> V_15 , V_11 -> V_20 ) ;
for ( V_152 = 0 ; V_152 < V_203 ; V_152 ++ ) {
struct V_130 * V_68 = V_11 -> V_151 [ V_152 ] ;
if ( V_68 != V_441 )
F_325 ( V_68 ) ;
}
}
struct V_10 * F_326 ( struct V_40 * V_31 ,
T_1 V_15 )
{
struct V_10 * V_11 ;
F_327 () ;
V_11 = F_328 ( & V_31 -> V_442 ,
V_15 >> V_128 ) ;
if ( V_11 && F_266 ( & V_11 -> V_17 ) ) {
F_329 () ;
if ( F_162 ( V_443 , & V_11 -> V_336 ) ) {
F_74 ( & V_11 -> V_340 ) ;
F_77 ( & V_11 -> V_340 ) ;
}
F_324 ( V_11 , NULL ) ;
return V_11 ;
}
F_329 () ;
return NULL ;
}
struct V_10 * F_330 ( struct V_40 * V_31 ,
T_1 V_15 )
{
struct V_10 * V_11 , * V_444 = NULL ;
int V_36 ;
V_11 = F_326 ( V_31 , V_15 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_322 ( V_31 , V_15 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_31 = V_31 ;
V_110:
V_36 = F_331 ( V_125 ) ;
if ( V_36 )
goto V_445;
F_74 ( & V_31 -> V_446 ) ;
V_36 = F_332 ( & V_31 -> V_442 ,
V_15 >> V_128 , V_11 ) ;
F_77 ( & V_31 -> V_446 ) ;
F_333 () ;
if ( V_36 == - V_91 ) {
V_444 = F_326 ( V_31 , V_15 ) ;
if ( V_444 )
goto V_445;
else
goto V_110;
}
F_323 ( V_11 ) ;
F_240 ( V_447 , & V_11 -> V_336 ) ;
F_85 ( & V_11 -> V_17 ) ;
return V_11 ;
V_445:
F_309 ( V_11 ) ;
return V_444 ;
}
struct V_10 * F_334 ( struct V_40 * V_31 ,
T_1 V_15 )
{
unsigned long V_20 = V_31 -> V_439 ;
unsigned long V_203 = F_150 ( V_15 , V_20 ) ;
unsigned long V_152 ;
unsigned long V_127 = V_15 >> V_128 ;
struct V_10 * V_11 ;
struct V_10 * V_444 = NULL ;
struct V_130 * V_68 ;
struct V_51 * V_27 = V_31 -> V_205 -> V_131 ;
int V_242 = 1 ;
int V_36 ;
if ( ! F_335 ( V_15 , V_31 -> V_387 ) ) {
F_175 ( V_31 , L_22 , V_15 ) ;
return F_336 ( - V_401 ) ;
}
V_11 = F_326 ( V_31 , V_15 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_310 ( V_31 , V_15 , V_20 ) ;
if ( ! V_11 )
return F_336 ( - V_43 ) ;
for ( V_152 = 0 ; V_152 < V_203 ; V_152 ++ , V_127 ++ ) {
V_68 = F_337 ( V_27 , V_127 , V_125 | V_425 ) ;
if ( ! V_68 ) {
V_444 = F_336 ( - V_43 ) ;
goto V_445;
}
F_74 ( & V_27 -> V_369 ) ;
if ( F_196 ( V_68 ) ) {
V_444 = (struct V_10 * ) V_68 -> V_206 ;
if ( F_266 ( & V_444 -> V_17 ) ) {
F_77 ( & V_27 -> V_369 ) ;
F_121 ( V_68 ) ;
F_100 ( V_68 ) ;
F_324 ( V_444 , V_68 ) ;
goto V_445;
}
V_444 = NULL ;
F_308 ( V_68 ) ;
F_44 ( F_123 ( V_68 ) ) ;
F_100 ( V_68 ) ;
}
F_195 ( V_11 , V_68 ) ;
F_77 ( & V_27 -> V_369 ) ;
F_44 ( F_123 ( V_68 ) ) ;
V_11 -> V_151 [ V_152 ] = V_68 ;
if ( ! F_206 ( V_68 ) )
V_242 = 0 ;
}
if ( V_242 )
F_240 ( V_438 , & V_11 -> V_336 ) ;
V_110:
V_36 = F_331 ( V_125 ) ;
if ( V_36 ) {
V_444 = F_336 ( V_36 ) ;
goto V_445;
}
F_74 ( & V_31 -> V_446 ) ;
V_36 = F_332 ( & V_31 -> V_442 ,
V_15 >> V_128 , V_11 ) ;
F_77 ( & V_31 -> V_446 ) ;
F_333 () ;
if ( V_36 == - V_91 ) {
V_444 = F_326 ( V_31 , V_15 ) ;
if ( V_444 )
goto V_445;
else
goto V_110;
}
F_323 ( V_11 ) ;
F_240 ( V_447 , & V_11 -> V_336 ) ;
F_338 ( V_11 -> V_151 [ 0 ] ) ;
for ( V_152 = 1 ; V_152 < V_203 ; V_152 ++ ) {
V_68 = V_11 -> V_151 [ V_152 ] ;
F_339 ( V_68 ) ;
F_121 ( V_68 ) ;
}
F_121 ( V_11 -> V_151 [ 0 ] ) ;
return V_11 ;
V_445:
F_44 ( ! F_43 ( & V_11 -> V_17 ) ) ;
for ( V_152 = 0 ; V_152 < V_203 ; V_152 ++ ) {
if ( V_11 -> V_151 [ V_152 ] )
F_121 ( V_11 -> V_151 [ V_152 ] ) ;
}
F_309 ( V_11 ) ;
return V_444 ;
}
static inline void F_340 ( struct V_448 * V_6 )
{
struct V_10 * V_11 =
F_341 ( V_6 , struct V_10 , V_448 ) ;
F_305 ( V_11 ) ;
}
static int F_342 ( struct V_10 * V_11 )
{
F_44 ( F_13 ( & V_11 -> V_17 ) == 0 ) ;
if ( F_43 ( & V_11 -> V_17 ) ) {
if ( F_239 ( V_447 , & V_11 -> V_336 ) ) {
struct V_40 * V_31 = V_11 -> V_31 ;
F_77 ( & V_11 -> V_340 ) ;
F_74 ( & V_31 -> V_446 ) ;
F_343 ( & V_31 -> V_442 ,
V_11 -> V_15 >> V_128 ) ;
F_77 ( & V_31 -> V_446 ) ;
} else {
F_77 ( & V_11 -> V_340 ) ;
}
F_307 ( V_11 ) ;
#ifdef F_344
if ( F_182 ( F_162 ( V_424 , & V_11 -> V_336 ) ) ) {
F_305 ( V_11 ) ;
return 1 ;
}
#endif
F_345 ( & V_11 -> V_448 , F_340 ) ;
return 1 ;
}
F_77 ( & V_11 -> V_340 ) ;
return 0 ;
}
void F_267 ( struct V_10 * V_11 )
{
int V_17 ;
int V_449 ;
if ( ! V_11 )
return;
while ( 1 ) {
V_17 = F_13 ( & V_11 -> V_17 ) ;
if ( V_17 <= 3 )
break;
V_449 = F_346 ( & V_11 -> V_17 , V_17 , V_17 - 1 ) ;
if ( V_449 == V_17 )
return;
}
F_74 ( & V_11 -> V_340 ) ;
if ( F_13 ( & V_11 -> V_17 ) == 2 &&
F_162 ( V_424 , & V_11 -> V_336 ) )
F_75 ( & V_11 -> V_17 ) ;
if ( F_13 ( & V_11 -> V_17 ) == 2 &&
F_162 ( V_443 , & V_11 -> V_336 ) &&
! F_306 ( V_11 ) &&
F_239 ( V_440 , & V_11 -> V_336 ) )
F_75 ( & V_11 -> V_17 ) ;
F_342 ( V_11 ) ;
}
void F_347 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return;
F_74 ( & V_11 -> V_340 ) ;
F_240 ( V_443 , & V_11 -> V_336 ) ;
if ( F_13 ( & V_11 -> V_17 ) == 2 && ! F_306 ( V_11 ) &&
F_239 ( V_440 , & V_11 -> V_336 ) )
F_75 ( & V_11 -> V_17 ) ;
F_342 ( V_11 ) ;
}
void F_348 ( struct V_10 * V_11 )
{
unsigned long V_152 ;
unsigned long V_203 ;
struct V_130 * V_130 ;
V_203 = F_150 ( V_11 -> V_15 , V_11 -> V_20 ) ;
for ( V_152 = 0 ; V_152 < V_203 ; V_152 ++ ) {
V_130 = V_11 -> V_151 [ V_152 ] ;
if ( ! F_123 ( V_130 ) )
continue;
F_122 ( V_130 ) ;
F_44 ( ! F_196 ( V_130 ) ) ;
F_99 ( V_130 ) ;
F_349 ( & V_130 -> V_27 -> V_450 ) ;
if ( ! F_123 ( V_130 ) ) {
F_350 ( & V_130 -> V_27 -> V_451 ,
F_351 ( V_130 ) ,
V_366 ) ;
}
F_352 ( & V_130 -> V_27 -> V_450 ) ;
F_231 ( V_130 ) ;
F_121 ( V_130 ) ;
}
F_44 ( F_13 ( & V_11 -> V_17 ) == 0 ) ;
}
int F_353 ( struct V_10 * V_11 )
{
unsigned long V_152 ;
unsigned long V_203 ;
int V_452 = 0 ;
F_323 ( V_11 ) ;
V_452 = F_249 ( V_341 , & V_11 -> V_336 ) ;
V_203 = F_150 ( V_11 -> V_15 , V_11 -> V_20 ) ;
F_44 ( F_13 ( & V_11 -> V_17 ) == 0 ) ;
F_44 ( ! F_162 ( V_440 , & V_11 -> V_336 ) ) ;
for ( V_152 = 0 ; V_152 < V_203 ; V_152 ++ )
F_354 ( V_11 -> V_151 [ V_152 ] ) ;
return V_452 ;
}
void F_355 ( struct V_10 * V_11 )
{
unsigned long V_152 ;
struct V_130 * V_130 ;
unsigned long V_203 ;
F_245 ( V_438 , & V_11 -> V_336 ) ;
V_203 = F_150 ( V_11 -> V_15 , V_11 -> V_20 ) ;
for ( V_152 = 0 ; V_152 < V_203 ; V_152 ++ ) {
V_130 = V_11 -> V_151 [ V_152 ] ;
if ( V_130 )
F_172 ( V_130 ) ;
}
}
void F_319 ( struct V_10 * V_11 )
{
unsigned long V_152 ;
struct V_130 * V_130 ;
unsigned long V_203 ;
F_240 ( V_438 , & V_11 -> V_336 ) ;
V_203 = F_150 ( V_11 -> V_15 , V_11 -> V_20 ) ;
for ( V_152 = 0 ; V_152 < V_203 ; V_152 ++ ) {
V_130 = V_11 -> V_151 [ V_152 ] ;
F_132 ( V_130 ) ;
}
}
int F_356 ( struct V_10 * V_11 )
{
return F_162 ( V_438 , & V_11 -> V_336 ) ;
}
int F_357 ( struct V_23 * V_24 ,
struct V_10 * V_11 , int V_114 ,
T_12 * V_286 , int V_176 )
{
unsigned long V_152 ;
struct V_130 * V_130 ;
int V_101 ;
int V_36 = 0 ;
int V_453 = 0 ;
int V_454 = 1 ;
unsigned long V_203 ;
unsigned long V_455 = 0 ;
struct V_48 * V_48 = NULL ;
unsigned long V_217 = 0 ;
if ( F_162 ( V_438 , & V_11 -> V_336 ) )
return 0 ;
V_203 = F_150 ( V_11 -> V_15 , V_11 -> V_20 ) ;
for ( V_152 = 0 ; V_152 < V_203 ; V_152 ++ ) {
V_130 = V_11 -> V_151 [ V_152 ] ;
if ( V_114 == V_456 ) {
if ( ! F_243 ( V_130 ) )
goto V_457;
} else {
F_122 ( V_130 ) ;
}
V_453 ++ ;
}
for ( V_152 = 0 ; V_152 < V_203 ; V_152 ++ ) {
V_130 = V_11 -> V_151 [ V_152 ] ;
if ( ! F_206 ( V_130 ) ) {
V_455 ++ ;
V_454 = 0 ;
}
}
if ( V_454 ) {
F_240 ( V_438 , & V_11 -> V_336 ) ;
goto V_457;
}
F_245 ( V_458 , & V_11 -> V_336 ) ;
V_11 -> V_459 = 0 ;
F_39 ( & V_11 -> V_350 , V_455 ) ;
for ( V_152 = 0 ; V_152 < V_203 ; V_152 ++ ) {
V_130 = V_11 -> V_151 [ V_152 ] ;
if ( ! F_206 ( V_130 ) ) {
if ( V_36 ) {
F_75 ( & V_11 -> V_350 ) ;
F_121 ( V_130 ) ;
continue;
}
F_231 ( V_130 ) ;
V_101 = F_220 ( V_24 , V_130 ,
V_286 , & V_48 ,
V_176 , & V_217 ,
V_352 ) ;
if ( V_101 ) {
V_36 = V_101 ;
F_75 ( & V_11 -> V_350 ) ;
}
} else {
F_121 ( V_130 ) ;
}
}
if ( V_48 ) {
V_101 = F_187 ( V_48 , V_176 , V_217 ) ;
if ( V_101 )
return V_101 ;
}
if ( V_36 || V_114 != V_460 )
return V_36 ;
for ( V_152 = 0 ; V_152 < V_203 ; V_152 ++ ) {
V_130 = V_11 -> V_151 [ V_152 ] ;
F_358 ( V_130 ) ;
if ( ! F_206 ( V_130 ) )
V_36 = - V_154 ;
}
return V_36 ;
V_457:
while ( V_453 > 0 ) {
V_453 -- ;
V_130 = V_11 -> V_151 [ V_453 ] ;
F_121 ( V_130 ) ;
}
return V_36 ;
}
void F_359 ( struct V_10 * V_11 , void * V_461 ,
unsigned long V_15 ,
unsigned long V_20 )
{
T_10 V_291 ;
T_10 V_64 ;
struct V_130 * V_130 ;
char * V_462 ;
char * V_463 = ( char * ) V_461 ;
T_10 V_464 = V_11 -> V_15 & ( ( T_1 ) V_29 - 1 ) ;
unsigned long V_152 = ( V_464 + V_15 ) >> V_128 ;
F_44 ( V_15 > V_11 -> V_20 ) ;
F_44 ( V_15 + V_20 > V_11 -> V_15 + V_11 -> V_20 ) ;
V_64 = ( V_464 + V_15 ) & ( V_29 - 1 ) ;
while ( V_20 > 0 ) {
V_130 = V_11 -> V_151 [ V_152 ] ;
V_291 = F_126 ( V_20 , ( V_29 - V_64 ) ) ;
V_462 = F_317 ( V_130 ) ;
memcpy ( V_463 , V_462 + V_64 , V_291 ) ;
V_463 += V_291 ;
V_20 -= V_291 ;
V_64 = 0 ;
V_152 ++ ;
}
}
int F_360 ( struct V_10 * V_11 , void T_17 * V_461 ,
unsigned long V_15 ,
unsigned long V_20 )
{
T_10 V_291 ;
T_10 V_64 ;
struct V_130 * V_130 ;
char * V_462 ;
char T_17 * V_463 = ( char T_17 * ) V_461 ;
T_10 V_464 = V_11 -> V_15 & ( ( T_1 ) V_29 - 1 ) ;
unsigned long V_152 = ( V_464 + V_15 ) >> V_128 ;
int V_36 = 0 ;
F_44 ( V_15 > V_11 -> V_20 ) ;
F_44 ( V_15 + V_20 > V_11 -> V_15 + V_11 -> V_20 ) ;
V_64 = ( V_464 + V_15 ) & ( V_29 - 1 ) ;
while ( V_20 > 0 ) {
V_130 = V_11 -> V_151 [ V_152 ] ;
V_291 = F_126 ( V_20 , ( V_29 - V_64 ) ) ;
V_462 = F_317 ( V_130 ) ;
if ( F_361 ( V_463 , V_462 + V_64 , V_291 ) ) {
V_36 = - V_465 ;
break;
}
V_463 += V_291 ;
V_20 -= V_291 ;
V_64 = 0 ;
V_152 ++ ;
}
return V_36 ;
}
int F_362 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_466 , char * * V_382 ,
unsigned long * V_467 ,
unsigned long * V_468 )
{
T_10 V_64 = V_15 & ( V_29 - 1 ) ;
char * V_462 ;
struct V_130 * V_68 ;
T_10 V_464 = V_11 -> V_15 & ( ( T_1 ) V_29 - 1 ) ;
unsigned long V_152 = ( V_464 + V_15 ) >> V_128 ;
unsigned long V_469 = ( V_464 + V_15 + V_466 - 1 ) >>
V_128 ;
if ( V_152 != V_469 )
return 1 ;
if ( V_152 == 0 ) {
V_64 = V_464 ;
* V_467 = 0 ;
} else {
V_64 = 0 ;
* V_467 = ( ( T_1 ) V_152 << V_128 ) - V_464 ;
}
if ( V_15 + V_466 > V_11 -> V_20 ) {
F_61 ( 1 , V_89 L_23 ,
V_11 -> V_15 , V_11 -> V_20 , V_15 , V_466 ) ;
return - V_401 ;
}
V_68 = V_11 -> V_151 [ V_152 ] ;
V_462 = F_317 ( V_68 ) ;
* V_382 = V_462 + V_64 ;
* V_468 = V_29 - V_64 ;
return 0 ;
}
int F_363 ( struct V_10 * V_11 , const void * V_470 ,
unsigned long V_15 ,
unsigned long V_20 )
{
T_10 V_291 ;
T_10 V_64 ;
struct V_130 * V_130 ;
char * V_462 ;
char * V_471 = ( char * ) V_470 ;
T_10 V_464 = V_11 -> V_15 & ( ( T_1 ) V_29 - 1 ) ;
unsigned long V_152 = ( V_464 + V_15 ) >> V_128 ;
int V_36 = 0 ;
F_44 ( V_15 > V_11 -> V_20 ) ;
F_44 ( V_15 + V_20 > V_11 -> V_15 + V_11 -> V_20 ) ;
V_64 = ( V_464 + V_15 ) & ( V_29 - 1 ) ;
while ( V_20 > 0 ) {
V_130 = V_11 -> V_151 [ V_152 ] ;
V_291 = F_126 ( V_20 , ( V_29 - V_64 ) ) ;
V_462 = F_317 ( V_130 ) ;
V_36 = memcmp ( V_471 , V_462 + V_64 , V_291 ) ;
if ( V_36 )
break;
V_471 += V_291 ;
V_20 -= V_291 ;
V_64 = 0 ;
V_152 ++ ;
}
return V_36 ;
}
void F_364 ( struct V_10 * V_11 ,
const void * V_472 )
{
char * V_462 ;
F_44 ( ! F_206 ( V_11 -> V_151 [ 0 ] ) ) ;
V_462 = F_317 ( V_11 -> V_151 [ 0 ] ) ;
memcpy ( V_462 + F_28 ( struct V_473 , V_474 ) , V_472 ,
V_475 ) ;
}
void F_365 ( struct V_10 * V_11 , const void * V_472 )
{
char * V_462 ;
F_44 ( ! F_206 ( V_11 -> V_151 [ 0 ] ) ) ;
V_462 = F_317 ( V_11 -> V_151 [ 0 ] ) ;
memcpy ( V_462 + F_28 ( struct V_473 , V_476 ) , V_472 ,
V_475 ) ;
}
void F_366 ( struct V_10 * V_11 , const void * V_472 ,
unsigned long V_15 , unsigned long V_20 )
{
T_10 V_291 ;
T_10 V_64 ;
struct V_130 * V_130 ;
char * V_462 ;
char * V_437 = ( char * ) V_472 ;
T_10 V_464 = V_11 -> V_15 & ( ( T_1 ) V_29 - 1 ) ;
unsigned long V_152 = ( V_464 + V_15 ) >> V_128 ;
F_44 ( V_15 > V_11 -> V_20 ) ;
F_44 ( V_15 + V_20 > V_11 -> V_15 + V_11 -> V_20 ) ;
V_64 = ( V_464 + V_15 ) & ( V_29 - 1 ) ;
while ( V_20 > 0 ) {
V_130 = V_11 -> V_151 [ V_152 ] ;
F_44 ( ! F_206 ( V_130 ) ) ;
V_291 = F_126 ( V_20 , V_29 - V_64 ) ;
V_462 = F_317 ( V_130 ) ;
memcpy ( V_462 + V_64 , V_437 , V_291 ) ;
V_437 += V_291 ;
V_20 -= V_291 ;
V_64 = 0 ;
V_152 ++ ;
}
}
void F_257 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_20 )
{
T_10 V_291 ;
T_10 V_64 ;
struct V_130 * V_130 ;
char * V_462 ;
T_10 V_464 = V_11 -> V_15 & ( ( T_1 ) V_29 - 1 ) ;
unsigned long V_152 = ( V_464 + V_15 ) >> V_128 ;
F_44 ( V_15 > V_11 -> V_20 ) ;
F_44 ( V_15 + V_20 > V_11 -> V_15 + V_11 -> V_20 ) ;
V_64 = ( V_464 + V_15 ) & ( V_29 - 1 ) ;
while ( V_20 > 0 ) {
V_130 = V_11 -> V_151 [ V_152 ] ;
F_44 ( ! F_206 ( V_130 ) ) ;
V_291 = F_126 ( V_20 , V_29 - V_64 ) ;
V_462 = F_317 ( V_130 ) ;
memset ( V_462 + V_64 , 0 , V_291 ) ;
V_20 -= V_291 ;
V_64 = 0 ;
V_152 ++ ;
}
}
void F_367 ( struct V_10 * V_463 ,
struct V_10 * V_437 )
{
int V_152 ;
unsigned V_203 ;
ASSERT ( V_463 -> V_20 == V_437 -> V_20 ) ;
V_203 = F_150 ( V_463 -> V_15 , V_463 -> V_20 ) ;
for ( V_152 = 0 ; V_152 < V_203 ; V_152 ++ )
F_316 ( F_317 ( V_463 -> V_151 [ V_152 ] ) ,
F_317 ( V_437 -> V_151 [ V_152 ] ) ) ;
}
void F_368 ( struct V_10 * V_463 , struct V_10 * V_437 ,
unsigned long V_477 , unsigned long V_478 ,
unsigned long V_20 )
{
T_1 V_479 = V_463 -> V_20 ;
T_10 V_291 ;
T_10 V_64 ;
struct V_130 * V_130 ;
char * V_462 ;
T_10 V_464 = V_463 -> V_15 & ( ( T_1 ) V_29 - 1 ) ;
unsigned long V_152 = ( V_464 + V_477 ) >> V_128 ;
F_44 ( V_437 -> V_20 != V_479 ) ;
V_64 = ( V_464 + V_477 ) &
( V_29 - 1 ) ;
while ( V_20 > 0 ) {
V_130 = V_463 -> V_151 [ V_152 ] ;
F_44 ( ! F_206 ( V_130 ) ) ;
V_291 = F_126 ( V_20 , ( unsigned long ) ( V_29 - V_64 ) ) ;
V_462 = F_317 ( V_130 ) ;
F_359 ( V_437 , V_462 + V_64 , V_478 , V_291 ) ;
V_478 += V_291 ;
V_20 -= V_291 ;
V_64 = 0 ;
V_152 ++ ;
}
}
void F_369 ( T_18 * V_382 , unsigned int V_15 , int V_20 )
{
T_18 * V_68 = V_382 + F_370 ( V_15 ) ;
const unsigned int V_271 = V_15 + V_20 ;
int V_117 = V_480 - ( V_15 % V_480 ) ;
T_18 V_481 = F_371 ( V_15 ) ;
while ( V_20 - V_117 >= 0 ) {
* V_68 |= V_481 ;
V_20 -= V_117 ;
V_117 = V_480 ;
V_481 = ~ 0 ;
V_68 ++ ;
}
if ( V_20 ) {
V_481 &= F_372 ( V_271 ) ;
* V_68 |= V_481 ;
}
}
void F_373 ( T_18 * V_382 , unsigned int V_15 , int V_20 )
{
T_18 * V_68 = V_382 + F_370 ( V_15 ) ;
const unsigned int V_271 = V_15 + V_20 ;
int V_97 = V_480 - ( V_15 % V_480 ) ;
T_18 V_482 = F_371 ( V_15 ) ;
while ( V_20 - V_97 >= 0 ) {
* V_68 &= ~ V_482 ;
V_20 -= V_97 ;
V_97 = V_480 ;
V_482 = ~ 0 ;
V_68 ++ ;
}
if ( V_20 ) {
V_482 &= F_372 ( V_271 ) ;
* V_68 &= ~ V_482 ;
}
}
static inline void F_374 ( struct V_10 * V_11 ,
unsigned long V_15 , unsigned long V_295 ,
unsigned long * F_351 ,
T_10 * F_131 )
{
T_10 V_464 = V_11 -> V_15 & ( ( T_1 ) V_29 - 1 ) ;
T_10 V_483 = F_370 ( V_295 ) ;
T_10 V_64 ;
V_64 = V_464 + V_15 + V_483 ;
* F_351 = V_64 >> V_128 ;
* F_131 = V_64 & ( V_29 - 1 ) ;
}
int F_375 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_295 )
{
T_18 * V_462 ;
struct V_130 * V_130 ;
unsigned long V_152 ;
T_10 V_64 ;
F_374 ( V_11 , V_15 , V_295 , & V_152 , & V_64 ) ;
V_130 = V_11 -> V_151 [ V_152 ] ;
F_44 ( ! F_206 ( V_130 ) ) ;
V_462 = F_317 ( V_130 ) ;
return 1U & ( V_462 [ V_64 ] >> ( V_295 & ( V_480 - 1 ) ) ) ;
}
void F_376 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_484 , unsigned long V_20 )
{
T_18 * V_462 ;
struct V_130 * V_130 ;
unsigned long V_152 ;
T_10 V_64 ;
const unsigned int V_271 = V_484 + V_20 ;
int V_117 = V_480 - ( V_484 % V_480 ) ;
T_18 V_481 = F_371 ( V_484 ) ;
F_374 ( V_11 , V_15 , V_484 , & V_152 , & V_64 ) ;
V_130 = V_11 -> V_151 [ V_152 ] ;
F_44 ( ! F_206 ( V_130 ) ) ;
V_462 = F_317 ( V_130 ) ;
while ( V_20 >= V_117 ) {
V_462 [ V_64 ] |= V_481 ;
V_20 -= V_117 ;
V_117 = V_480 ;
V_481 = ~ 0 ;
if ( ++ V_64 >= V_29 && V_20 > 0 ) {
V_64 = 0 ;
V_130 = V_11 -> V_151 [ ++ V_152 ] ;
F_44 ( ! F_206 ( V_130 ) ) ;
V_462 = F_317 ( V_130 ) ;
}
}
if ( V_20 ) {
V_481 &= F_372 ( V_271 ) ;
V_462 [ V_64 ] |= V_481 ;
}
}
void F_377 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_484 , unsigned long V_20 )
{
T_18 * V_462 ;
struct V_130 * V_130 ;
unsigned long V_152 ;
T_10 V_64 ;
const unsigned int V_271 = V_484 + V_20 ;
int V_97 = V_480 - ( V_484 % V_480 ) ;
T_18 V_482 = F_371 ( V_484 ) ;
F_374 ( V_11 , V_15 , V_484 , & V_152 , & V_64 ) ;
V_130 = V_11 -> V_151 [ V_152 ] ;
F_44 ( ! F_206 ( V_130 ) ) ;
V_462 = F_317 ( V_130 ) ;
while ( V_20 >= V_97 ) {
V_462 [ V_64 ] &= ~ V_482 ;
V_20 -= V_97 ;
V_97 = V_480 ;
V_482 = ~ 0 ;
if ( ++ V_64 >= V_29 && V_20 > 0 ) {
V_64 = 0 ;
V_130 = V_11 -> V_151 [ ++ V_152 ] ;
F_44 ( ! F_206 ( V_130 ) ) ;
V_462 = F_317 ( V_130 ) ;
}
}
if ( V_20 ) {
V_482 &= F_372 ( V_271 ) ;
V_462 [ V_64 ] &= ~ V_482 ;
}
}
static inline bool F_378 ( unsigned long V_437 , unsigned long V_463 , unsigned long V_20 )
{
unsigned long V_485 = ( V_437 > V_463 ) ? V_437 - V_463 : V_463 - V_437 ;
return V_485 < V_20 ;
}
static void F_379 ( struct V_130 * V_486 , struct V_130 * V_487 ,
unsigned long V_488 , unsigned long V_489 ,
unsigned long V_20 )
{
char * V_490 = F_317 ( V_486 ) ;
char * V_491 ;
int V_492 = 0 ;
if ( V_486 != V_487 ) {
V_491 = F_317 ( V_487 ) ;
} else {
V_491 = V_490 ;
if ( F_378 ( V_489 , V_488 , V_20 ) )
V_492 = 1 ;
}
if ( V_492 )
memmove ( V_490 + V_488 , V_491 + V_489 , V_20 ) ;
else
memcpy ( V_490 + V_488 , V_491 + V_489 , V_20 ) ;
}
void F_380 ( struct V_10 * V_463 , unsigned long V_477 ,
unsigned long V_478 , unsigned long V_20 )
{
struct V_40 * V_31 = V_463 -> V_31 ;
T_10 V_291 ;
T_10 V_493 ;
T_10 V_494 ;
T_10 V_464 = V_463 -> V_15 & ( ( T_1 ) V_29 - 1 ) ;
unsigned long V_495 ;
unsigned long V_496 ;
if ( V_478 + V_20 > V_463 -> V_20 ) {
F_175 ( V_31 ,
L_24 ,
V_478 , V_20 , V_463 -> V_20 ) ;
F_22 ( 1 ) ;
}
if ( V_477 + V_20 > V_463 -> V_20 ) {
F_175 ( V_31 ,
L_25 ,
V_477 , V_20 , V_463 -> V_20 ) ;
F_22 ( 1 ) ;
}
while ( V_20 > 0 ) {
V_493 = ( V_464 + V_477 ) &
( V_29 - 1 ) ;
V_494 = ( V_464 + V_478 ) &
( V_29 - 1 ) ;
V_495 = ( V_464 + V_477 ) >> V_128 ;
V_496 = ( V_464 + V_478 ) >> V_128 ;
V_291 = F_126 ( V_20 , ( unsigned long ) ( V_29 -
V_494 ) ) ;
V_291 = F_117 (unsigned long, cur,
(unsigned long)(PAGE_SIZE - dst_off_in_page)) ;
F_379 ( V_463 -> V_151 [ V_495 ] , V_463 -> V_151 [ V_496 ] ,
V_493 , V_494 , V_291 ) ;
V_478 += V_291 ;
V_477 += V_291 ;
V_20 -= V_291 ;
}
}
void F_381 ( struct V_10 * V_463 , unsigned long V_477 ,
unsigned long V_478 , unsigned long V_20 )
{
struct V_40 * V_31 = V_463 -> V_31 ;
T_10 V_291 ;
T_10 V_493 ;
T_10 V_494 ;
unsigned long V_497 = V_477 + V_20 - 1 ;
unsigned long V_498 = V_478 + V_20 - 1 ;
T_10 V_464 = V_463 -> V_15 & ( ( T_1 ) V_29 - 1 ) ;
unsigned long V_495 ;
unsigned long V_496 ;
if ( V_478 + V_20 > V_463 -> V_20 ) {
F_175 ( V_31 ,
L_26 ,
V_478 , V_20 , V_463 -> V_20 ) ;
F_22 ( 1 ) ;
}
if ( V_477 + V_20 > V_463 -> V_20 ) {
F_175 ( V_31 ,
L_27 ,
V_477 , V_20 , V_463 -> V_20 ) ;
F_22 ( 1 ) ;
}
if ( V_477 < V_478 ) {
F_380 ( V_463 , V_477 , V_478 , V_20 ) ;
return;
}
while ( V_20 > 0 ) {
V_495 = ( V_464 + V_497 ) >> V_128 ;
V_496 = ( V_464 + V_498 ) >> V_128 ;
V_493 = ( V_464 + V_497 ) &
( V_29 - 1 ) ;
V_494 = ( V_464 + V_498 ) &
( V_29 - 1 ) ;
V_291 = F_117 (unsigned long, len, src_off_in_page + 1 ) ;
V_291 = F_126 ( V_291 , V_493 + 1 ) ;
F_379 ( V_463 -> V_151 [ V_495 ] , V_463 -> V_151 [ V_496 ] ,
V_493 - V_291 + 1 ,
V_494 - V_291 + 1 , V_291 ) ;
V_497 -= V_291 ;
V_498 -= V_291 ;
V_20 -= V_291 ;
}
}
int F_382 ( struct V_130 * V_130 )
{
struct V_10 * V_11 ;
F_74 ( & V_130 -> V_27 -> V_369 ) ;
if ( ! F_196 ( V_130 ) ) {
F_77 ( & V_130 -> V_27 -> V_369 ) ;
return 1 ;
}
V_11 = (struct V_10 * ) V_130 -> V_206 ;
F_22 ( ! V_11 ) ;
F_74 ( & V_11 -> V_340 ) ;
if ( F_13 ( & V_11 -> V_17 ) != 1 || F_306 ( V_11 ) ) {
F_77 ( & V_11 -> V_340 ) ;
F_77 ( & V_130 -> V_27 -> V_369 ) ;
return 0 ;
}
F_77 ( & V_130 -> V_27 -> V_369 ) ;
if ( ! F_239 ( V_440 , & V_11 -> V_336 ) ) {
F_77 ( & V_11 -> V_340 ) ;
return 0 ;
}
return F_342 ( V_11 ) ;
}
