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
V_11 -> V_15 , V_11 -> V_20 , F_15 ( & V_11 -> V_17 ) ) ;
F_8 ( & V_11 -> V_14 ) ;
F_14 ( V_21 , V_11 ) ;
}
}
static inline void F_16 ( const char * V_22 ,
struct V_23 * V_24 , T_1 V_15 , T_1 V_16 )
{
struct V_25 * V_25 ;
T_1 V_26 ;
if ( ! V_24 -> V_27 )
return;
V_25 = V_24 -> V_27 -> V_28 ;
V_26 = F_17 ( V_25 ) ;
if ( V_16 >= V_29 && ( V_16 % 2 ) == 0 && V_16 != V_26 - 1 ) {
F_18 ( F_19 ( V_25 ) -> V_30 -> V_31 ,
L_3 ,
V_22 , F_20 ( F_19 ( V_25 ) ) , V_26 , V_15 , V_16 ) ;
}
}
static void F_21 ( struct V_1 * V_2 , unsigned V_32 ,
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
V_36 = F_22 ( & V_34 -> V_38 , V_2 -> V_15 , V_2 -> V_16 ,
V_39 ) ;
F_23 ( V_36 < 0 ) ;
}
static inline struct V_40 *
F_24 ( struct V_23 * V_24 )
{
if ( ! V_24 -> V_27 )
return NULL ;
return F_25 ( V_24 -> V_27 -> V_28 -> V_41 ) ;
}
int T_2 F_26 ( void )
{
V_18 = F_27 ( L_4 ,
sizeof( struct V_1 ) , 0 ,
V_42 , NULL ) ;
if ( ! V_18 )
return - V_43 ;
V_21 = F_27 ( L_5 ,
sizeof( struct V_10 ) , 0 ,
V_42 , NULL ) ;
if ( ! V_21 )
goto V_44;
V_45 = F_28 ( V_46 ,
F_29 ( struct V_47 , V_48 ) ) ;
if ( ! V_45 )
goto V_49;
if ( F_30 ( V_45 , V_46 ) )
goto V_50;
return 0 ;
V_50:
F_31 ( V_45 ) ;
V_45 = NULL ;
V_49:
F_32 ( V_21 ) ;
V_21 = NULL ;
V_44:
F_32 ( V_18 ) ;
V_18 = NULL ;
return - V_43 ;
}
void F_33 ( void )
{
F_9 () ;
F_34 () ;
F_32 ( V_18 ) ;
F_32 ( V_21 ) ;
if ( V_45 )
F_31 ( V_45 ) ;
}
void F_35 ( struct V_23 * V_24 ,
struct V_51 * V_27 )
{
V_24 -> V_2 = V_52 ;
V_24 -> V_53 = NULL ;
V_24 -> V_54 = 0 ;
F_36 ( & V_24 -> V_55 ) ;
V_24 -> V_27 = V_27 ;
}
static struct V_1 * F_37 ( T_3 V_56 )
{
struct V_1 * V_2 ;
V_56 &= ~ ( V_57 | V_58 ) ;
V_2 = F_38 ( V_18 , V_56 ) ;
if ( ! V_2 )
return V_2 ;
V_2 -> V_2 = 0 ;
V_2 -> V_59 = NULL ;
F_39 ( & V_2 -> V_3 ) ;
F_3 ( & V_2 -> V_14 , & V_12 ) ;
F_40 ( & V_2 -> V_17 , 1 ) ;
F_41 ( & V_2 -> V_60 ) ;
F_42 ( V_2 , V_56 , V_61 ) ;
return V_2 ;
}
void F_43 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( F_44 ( & V_2 -> V_17 ) ) {
F_45 ( F_1 ( V_2 ) ) ;
F_7 ( & V_2 -> V_14 ) ;
F_46 ( V_2 , V_61 ) ;
F_14 ( V_18 , V_2 ) ;
}
}
static struct V_3 * F_47 ( struct V_62 * V_30 ,
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
V_9 = F_48 ( V_69 , struct V_70 , V_3 ) ;
if ( V_64 < V_9 -> V_15 )
V_68 = & ( * V_68 ) -> V_72 ;
else if ( V_64 > V_9 -> V_16 )
V_68 = & ( * V_68 ) -> V_73 ;
else
return V_69 ;
}
V_71:
F_49 ( V_65 , V_69 , V_68 ) ;
F_50 ( V_65 , V_30 ) ;
return NULL ;
}
static struct V_3 * F_51 ( struct V_23 * V_24 , T_1 V_64 ,
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
V_9 = F_48 ( V_79 , struct V_70 , V_3 ) ;
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
V_79 = F_52 ( V_79 ) ;
V_81 = F_48 ( V_79 , struct V_70 , V_3 ) ;
}
* V_74 = V_79 ;
V_79 = V_80 ;
}
if ( V_75 ) {
V_81 = F_48 ( V_79 , struct V_70 , V_3 ) ;
while ( V_79 && V_64 < V_81 -> V_15 ) {
V_79 = F_53 ( V_79 ) ;
V_81 = F_48 ( V_79 , struct V_70 , V_3 ) ;
}
* V_75 = V_79 ;
}
return NULL ;
}
static inline struct V_3 *
F_54 ( struct V_23 * V_24 ,
T_1 V_64 ,
struct V_3 * * * V_76 ,
struct V_3 * * V_77 )
{
struct V_3 * V_79 = NULL ;
struct V_3 * V_36 ;
V_36 = F_51 ( V_24 , V_64 , & V_79 , NULL , V_76 , V_77 ) ;
if ( ! V_36 )
return V_79 ;
return V_36 ;
}
static inline struct V_3 * F_55 ( struct V_23 * V_24 ,
T_1 V_64 )
{
return F_54 ( V_24 , V_64 , NULL , NULL ) ;
}
static void F_56 ( struct V_23 * V_24 , struct V_1 * V_5 ,
struct V_1 * V_82 )
{
if ( V_24 -> V_53 && V_24 -> V_53 -> V_83 )
V_24 -> V_53 -> V_83 ( V_24 -> V_27 -> V_28 , V_5 ,
V_82 ) ;
}
static void F_57 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_1 * V_82 ;
struct V_3 * V_84 ;
if ( V_2 -> V_2 & ( V_85 | V_86 ) )
return;
V_84 = F_53 ( & V_2 -> V_3 ) ;
if ( V_84 ) {
V_82 = F_48 ( V_84 , struct V_1 , V_3 ) ;
if ( V_82 -> V_16 == V_2 -> V_15 - 1 &&
V_82 -> V_2 == V_2 -> V_2 ) {
F_56 ( V_24 , V_2 , V_82 ) ;
V_2 -> V_15 = V_82 -> V_15 ;
F_58 ( & V_82 -> V_3 , & V_24 -> V_2 ) ;
F_39 ( & V_82 -> V_3 ) ;
F_43 ( V_82 ) ;
}
}
V_84 = F_52 ( & V_2 -> V_3 ) ;
if ( V_84 ) {
V_82 = F_48 ( V_84 , struct V_1 , V_3 ) ;
if ( V_82 -> V_15 == V_2 -> V_16 + 1 &&
V_82 -> V_2 == V_2 -> V_2 ) {
F_56 ( V_24 , V_2 , V_82 ) ;
V_2 -> V_16 = V_82 -> V_16 ;
F_58 ( & V_82 -> V_3 , & V_24 -> V_2 ) ;
F_39 ( & V_82 -> V_3 ) ;
F_43 ( V_82 ) ;
}
}
}
static void F_59 ( struct V_23 * V_24 ,
struct V_1 * V_2 , unsigned * V_32 )
{
if ( V_24 -> V_53 && V_24 -> V_53 -> V_87 )
V_24 -> V_53 -> V_87 ( V_24 -> V_27 -> V_28 , V_2 , V_32 ) ;
}
static void F_60 ( struct V_23 * V_24 ,
struct V_1 * V_2 , unsigned * V_32 )
{
if ( V_24 -> V_53 && V_24 -> V_53 -> V_88 )
V_24 -> V_53 -> V_88 ( F_19 ( V_24 -> V_27 -> V_28 ) ,
V_2 , V_32 ) ;
}
static int F_61 ( struct V_23 * V_24 ,
struct V_1 * V_2 , T_1 V_15 , T_1 V_16 ,
struct V_3 * * * V_68 ,
struct V_3 * * V_69 ,
unsigned * V_32 , struct V_33 * V_34 )
{
struct V_3 * V_65 ;
if ( V_16 < V_15 )
F_62 ( 1 , V_89 L_6 ,
V_16 , V_15 ) ;
V_2 -> V_15 = V_15 ;
V_2 -> V_16 = V_16 ;
F_63 ( V_24 , V_2 , V_32 , V_34 ) ;
V_65 = F_47 ( & V_24 -> V_2 , NULL , V_16 , & V_2 -> V_3 , V_68 , V_69 ) ;
if ( V_65 ) {
struct V_1 * V_90 ;
V_90 = F_48 ( V_65 , struct V_1 , V_3 ) ;
F_12 ( L_7 ,
V_90 -> V_15 , V_90 -> V_16 , V_15 , V_16 ) ;
return - V_91 ;
}
F_57 ( V_24 , V_2 ) ;
return 0 ;
}
static void F_64 ( struct V_23 * V_24 , struct V_1 * V_92 ,
T_1 V_93 )
{
if ( V_24 -> V_53 && V_24 -> V_53 -> V_94 )
V_24 -> V_53 -> V_94 ( V_24 -> V_27 -> V_28 , V_92 , V_93 ) ;
}
static int F_65 ( struct V_23 * V_24 , struct V_1 * V_92 ,
struct V_1 * V_95 , T_1 V_93 )
{
struct V_3 * V_65 ;
F_64 ( V_24 , V_92 , V_93 ) ;
V_95 -> V_15 = V_92 -> V_15 ;
V_95 -> V_16 = V_93 - 1 ;
V_95 -> V_2 = V_92 -> V_2 ;
V_92 -> V_15 = V_93 ;
V_65 = F_47 ( & V_24 -> V_2 , & V_92 -> V_3 , V_95 -> V_16 ,
& V_95 -> V_3 , NULL , NULL ) ;
if ( V_65 ) {
F_43 ( V_95 ) ;
return - V_91 ;
}
return 0 ;
}
static struct V_1 * F_66 ( struct V_1 * V_2 )
{
struct V_3 * V_13 = F_52 ( & V_2 -> V_3 ) ;
if ( V_13 )
return F_48 ( V_13 , struct V_1 , V_3 ) ;
else
return NULL ;
}
static struct V_1 * F_67 ( struct V_23 * V_24 ,
struct V_1 * V_2 ,
unsigned * V_32 , int V_96 ,
struct V_33 * V_34 )
{
struct V_1 * V_13 ;
unsigned V_97 = * V_32 & ~ V_98 ;
if ( ( V_97 & V_99 ) && ( V_2 -> V_2 & V_99 ) ) {
T_1 V_100 = V_2 -> V_16 - V_2 -> V_15 + 1 ;
F_45 ( V_100 > V_24 -> V_54 ) ;
V_24 -> V_54 -= V_100 ;
}
F_60 ( V_24 , V_2 , V_32 ) ;
F_21 ( V_2 , V_97 , V_34 , 0 ) ;
V_2 -> V_2 &= ~ V_97 ;
if ( V_96 )
F_68 ( & V_2 -> V_60 ) ;
if ( V_2 -> V_2 == 0 ) {
V_13 = F_66 ( V_2 ) ;
if ( F_1 ( V_2 ) ) {
F_58 ( & V_2 -> V_3 , & V_24 -> V_2 ) ;
F_39 ( & V_2 -> V_3 ) ;
F_43 ( V_2 ) ;
} else {
F_45 ( 1 ) ;
}
} else {
F_57 ( V_24 , V_2 ) ;
V_13 = F_66 ( V_2 ) ;
}
return V_13 ;
}
static struct V_1 *
F_69 ( struct V_1 * V_95 )
{
if ( ! V_95 )
V_95 = F_37 ( V_39 ) ;
return V_95 ;
}
static void F_70 ( struct V_23 * V_24 , int V_101 )
{
F_71 ( F_24 ( V_24 ) , V_101 ,
L_8 ) ;
}
static int F_72 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
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
F_73 ( V_24 , V_15 , V_16 ) ;
if ( V_32 & V_107 )
V_32 |= V_108 ;
if ( V_102 )
V_32 |= ~ V_98 ;
V_32 |= V_109 ;
if ( V_32 & ( V_85 | V_86 ) )
V_106 = 1 ;
V_110:
if ( ! V_95 && F_74 ( V_56 ) ) {
V_95 = F_37 ( V_56 ) ;
}
F_75 ( & V_24 -> V_55 ) ;
if ( V_103 ) {
V_104 = * V_103 ;
if ( V_106 ) {
* V_103 = NULL ;
V_103 = NULL ;
}
if ( V_104 && F_1 ( V_104 ) &&
V_104 -> V_15 <= V_15 && V_104 -> V_16 > V_15 ) {
if ( V_106 )
F_76 ( & V_104 -> V_17 ) ;
V_2 = V_104 ;
goto V_111;
}
if ( V_106 )
F_43 ( V_104 ) ;
}
V_65 = F_55 ( V_24 , V_15 ) ;
if ( ! V_65 )
goto V_112;
V_2 = F_48 ( V_65 , struct V_1 , V_3 ) ;
V_111:
if ( V_2 -> V_15 > V_16 )
goto V_112;
F_45 ( V_2 -> V_16 < V_15 ) ;
V_105 = V_2 -> V_16 ;
if ( ! ( V_2 -> V_2 & V_32 ) ) {
V_2 = F_66 ( V_2 ) ;
goto V_13;
}
if ( V_2 -> V_15 < V_15 ) {
V_95 = F_69 ( V_95 ) ;
F_23 ( ! V_95 ) ;
V_101 = F_65 ( V_24 , V_2 , V_95 , V_15 ) ;
if ( V_101 )
F_70 ( V_24 , V_101 ) ;
V_95 = NULL ;
if ( V_101 )
goto V_112;
if ( V_2 -> V_16 <= V_16 ) {
V_2 = F_67 ( V_24 , V_2 , & V_32 , V_96 ,
V_34 ) ;
goto V_13;
}
goto V_113;
}
if ( V_2 -> V_15 <= V_16 && V_2 -> V_16 > V_16 ) {
V_95 = F_69 ( V_95 ) ;
F_23 ( ! V_95 ) ;
V_101 = F_65 ( V_24 , V_2 , V_95 , V_16 + 1 ) ;
if ( V_101 )
F_70 ( V_24 , V_101 ) ;
if ( V_96 )
F_68 ( & V_2 -> V_60 ) ;
F_67 ( V_24 , V_95 , & V_32 , V_96 , V_34 ) ;
V_95 = NULL ;
goto V_112;
}
V_2 = F_67 ( V_24 , V_2 , & V_32 , V_96 , V_34 ) ;
V_13:
if ( V_105 == ( T_1 ) - 1 )
goto V_112;
V_15 = V_105 + 1 ;
if ( V_15 <= V_16 && V_2 && ! F_77 () )
goto V_111;
V_113:
if ( V_15 > V_16 )
goto V_112;
F_78 ( & V_24 -> V_55 ) ;
if ( F_74 ( V_56 ) )
F_79 () ;
goto V_110;
V_112:
F_78 ( & V_24 -> V_55 ) ;
if ( V_95 )
F_43 ( V_95 ) ;
return 0 ;
}
static void F_80 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
__releases( V_24 -> V_55 )
__acquires( V_24 -> V_55 )
{
F_81 ( V_114 ) ;
F_82 ( & V_2 -> V_60 , & V_114 , V_115 ) ;
F_78 ( & V_24 -> V_55 ) ;
F_83 () ;
F_75 ( & V_24 -> V_55 ) ;
F_84 ( & V_2 -> V_60 , & V_114 ) ;
}
static void F_85 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned long V_32 )
{
struct V_1 * V_2 ;
struct V_3 * V_65 ;
F_73 ( V_24 , V_15 , V_16 ) ;
F_75 ( & V_24 -> V_55 ) ;
V_110:
while ( 1 ) {
V_65 = F_55 ( V_24 , V_15 ) ;
V_116:
if ( ! V_65 )
break;
V_2 = F_48 ( V_65 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 > V_16 )
goto V_112;
if ( V_2 -> V_2 & V_32 ) {
V_15 = V_2 -> V_15 ;
F_86 ( & V_2 -> V_17 ) ;
F_80 ( V_24 , V_2 ) ;
F_43 ( V_2 ) ;
goto V_110;
}
V_15 = V_2 -> V_16 + 1 ;
if ( V_15 > V_16 )
break;
if ( ! F_87 ( & V_24 -> V_55 ) ) {
V_65 = F_52 ( V_65 ) ;
goto V_116;
}
}
V_112:
F_78 ( & V_24 -> V_55 ) ;
}
static void F_63 ( struct V_23 * V_24 ,
struct V_1 * V_2 ,
unsigned * V_32 , struct V_33 * V_34 )
{
unsigned V_117 = * V_32 & ~ V_98 ;
F_59 ( V_24 , V_2 , V_32 ) ;
if ( ( V_117 & V_99 ) && ! ( V_2 -> V_2 & V_99 ) ) {
T_1 V_100 = V_2 -> V_16 - V_2 -> V_15 + 1 ;
V_24 -> V_54 += V_100 ;
}
F_21 ( V_2 , V_117 , V_34 , 1 ) ;
V_2 -> V_2 |= V_117 ;
}
static void F_88 ( struct V_1 * V_2 ,
struct V_1 * * V_118 ,
unsigned V_7 )
{
if ( V_118 && ! ( * V_118 ) ) {
if ( ! V_7 || ( V_2 -> V_2 & V_7 ) ) {
* V_118 = V_2 ;
F_86 ( & V_2 -> V_17 ) ;
}
}
}
static void F_89 ( struct V_1 * V_2 ,
struct V_1 * * V_118 )
{
return F_88 ( V_2 , V_118 ,
V_85 | V_86 ) ;
}
static int T_4
F_90 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
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
F_73 ( V_24 , V_15 , V_16 ) ;
V_32 |= V_109 ;
V_110:
if ( ! V_95 && F_74 ( V_56 ) ) {
V_95 = F_37 ( V_56 ) ;
}
F_75 ( & V_24 -> V_55 ) ;
if ( V_103 && * V_103 ) {
V_2 = * V_103 ;
if ( V_2 -> V_15 <= V_15 && V_2 -> V_16 > V_15 &&
F_1 ( V_2 ) ) {
V_65 = & V_2 -> V_3 ;
goto V_111;
}
}
V_65 = F_54 ( V_24 , V_15 , & V_68 , & V_69 ) ;
if ( ! V_65 ) {
V_95 = F_69 ( V_95 ) ;
F_23 ( ! V_95 ) ;
V_101 = F_61 ( V_24 , V_95 , V_15 , V_16 ,
& V_68 , & V_69 , & V_32 , V_34 ) ;
if ( V_101 )
F_70 ( V_24 , V_101 ) ;
F_89 ( V_95 , V_103 ) ;
V_95 = NULL ;
goto V_112;
}
V_2 = F_48 ( V_65 , struct V_1 , V_3 ) ;
V_111:
V_121 = V_2 -> V_15 ;
V_105 = V_2 -> V_16 ;
if ( V_2 -> V_15 == V_15 && V_2 -> V_16 <= V_16 ) {
if ( V_2 -> V_2 & V_119 ) {
* V_120 = V_2 -> V_15 ;
V_101 = - V_91 ;
goto V_112;
}
F_63 ( V_24 , V_2 , & V_32 , V_34 ) ;
F_89 ( V_2 , V_103 ) ;
F_57 ( V_24 , V_2 ) ;
if ( V_105 == ( T_1 ) - 1 )
goto V_112;
V_15 = V_105 + 1 ;
V_2 = F_66 ( V_2 ) ;
if ( V_15 < V_16 && V_2 && V_2 -> V_15 == V_15 &&
! F_77 () )
goto V_111;
goto V_113;
}
if ( V_2 -> V_15 < V_15 ) {
if ( V_2 -> V_2 & V_119 ) {
* V_120 = V_15 ;
V_101 = - V_91 ;
goto V_112;
}
V_95 = F_69 ( V_95 ) ;
F_23 ( ! V_95 ) ;
V_101 = F_65 ( V_24 , V_2 , V_95 , V_15 ) ;
if ( V_101 )
F_70 ( V_24 , V_101 ) ;
V_95 = NULL ;
if ( V_101 )
goto V_112;
if ( V_2 -> V_16 <= V_16 ) {
F_63 ( V_24 , V_2 , & V_32 , V_34 ) ;
F_89 ( V_2 , V_103 ) ;
F_57 ( V_24 , V_2 ) ;
if ( V_105 == ( T_1 ) - 1 )
goto V_112;
V_15 = V_105 + 1 ;
V_2 = F_66 ( V_2 ) ;
if ( V_15 < V_16 && V_2 && V_2 -> V_15 == V_15 &&
! F_77 () )
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
V_95 = F_69 ( V_95 ) ;
F_23 ( ! V_95 ) ;
V_101 = F_61 ( V_24 , V_95 , V_15 , V_122 ,
NULL , NULL , & V_32 , V_34 ) ;
if ( V_101 )
F_70 ( V_24 , V_101 ) ;
F_89 ( V_95 , V_103 ) ;
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
V_95 = F_69 ( V_95 ) ;
F_23 ( ! V_95 ) ;
V_101 = F_65 ( V_24 , V_2 , V_95 , V_16 + 1 ) ;
if ( V_101 )
F_70 ( V_24 , V_101 ) ;
F_63 ( V_24 , V_95 , & V_32 , V_34 ) ;
F_89 ( V_95 , V_103 ) ;
F_57 ( V_24 , V_95 ) ;
V_95 = NULL ;
goto V_112;
}
V_113:
if ( V_15 > V_16 )
goto V_112;
F_78 ( & V_24 -> V_55 ) ;
if ( F_74 ( V_56 ) )
F_79 () ;
goto V_110;
V_112:
F_78 ( & V_24 -> V_55 ) ;
if ( V_95 )
F_43 ( V_95 ) ;
return V_101 ;
}
int F_91 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned V_32 , T_1 * V_120 ,
struct V_1 * * V_103 , T_3 V_56 )
{
return F_90 ( V_24 , V_15 , V_16 , V_32 , 0 , V_120 ,
V_103 , V_56 , NULL ) ;
}
int F_92 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
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
F_73 ( V_24 , V_15 , V_16 ) ;
V_110:
if ( ! V_95 ) {
V_95 = F_37 ( V_125 ) ;
if ( ! V_95 && ! V_124 )
return - V_43 ;
}
F_75 ( & V_24 -> V_55 ) ;
if ( V_103 && * V_103 ) {
V_2 = * V_103 ;
if ( V_2 -> V_15 <= V_15 && V_2 -> V_16 > V_15 &&
F_1 ( V_2 ) ) {
V_65 = & V_2 -> V_3 ;
goto V_111;
}
}
V_65 = F_54 ( V_24 , V_15 , & V_68 , & V_69 ) ;
if ( ! V_65 ) {
V_95 = F_69 ( V_95 ) ;
if ( ! V_95 ) {
V_101 = - V_43 ;
goto V_112;
}
V_101 = F_61 ( V_24 , V_95 , V_15 , V_16 ,
& V_68 , & V_69 , & V_32 , NULL ) ;
if ( V_101 )
F_70 ( V_24 , V_101 ) ;
F_89 ( V_95 , V_103 ) ;
V_95 = NULL ;
goto V_112;
}
V_2 = F_48 ( V_65 , struct V_1 , V_3 ) ;
V_111:
V_121 = V_2 -> V_15 ;
V_105 = V_2 -> V_16 ;
if ( V_2 -> V_15 == V_15 && V_2 -> V_16 <= V_16 ) {
F_63 ( V_24 , V_2 , & V_32 , NULL ) ;
F_89 ( V_2 , V_103 ) ;
V_2 = F_67 ( V_24 , V_2 , & V_123 , 0 , NULL ) ;
if ( V_105 == ( T_1 ) - 1 )
goto V_112;
V_15 = V_105 + 1 ;
if ( V_15 < V_16 && V_2 && V_2 -> V_15 == V_15 &&
! F_77 () )
goto V_111;
goto V_113;
}
if ( V_2 -> V_15 < V_15 ) {
V_95 = F_69 ( V_95 ) ;
if ( ! V_95 ) {
V_101 = - V_43 ;
goto V_112;
}
V_101 = F_65 ( V_24 , V_2 , V_95 , V_15 ) ;
if ( V_101 )
F_70 ( V_24 , V_101 ) ;
V_95 = NULL ;
if ( V_101 )
goto V_112;
if ( V_2 -> V_16 <= V_16 ) {
F_63 ( V_24 , V_2 , & V_32 , NULL ) ;
F_89 ( V_2 , V_103 ) ;
V_2 = F_67 ( V_24 , V_2 , & V_123 , 0 ,
NULL ) ;
if ( V_105 == ( T_1 ) - 1 )
goto V_112;
V_15 = V_105 + 1 ;
if ( V_15 < V_16 && V_2 && V_2 -> V_15 == V_15 &&
! F_77 () )
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
V_95 = F_69 ( V_95 ) ;
if ( ! V_95 ) {
V_101 = - V_43 ;
goto V_112;
}
V_101 = F_61 ( V_24 , V_95 , V_15 , V_122 ,
NULL , NULL , & V_32 , NULL ) ;
if ( V_101 )
F_70 ( V_24 , V_101 ) ;
F_89 ( V_95 , V_103 ) ;
V_95 = NULL ;
V_15 = V_122 + 1 ;
goto V_113;
}
if ( V_2 -> V_15 <= V_16 && V_2 -> V_16 > V_16 ) {
V_95 = F_69 ( V_95 ) ;
if ( ! V_95 ) {
V_101 = - V_43 ;
goto V_112;
}
V_101 = F_65 ( V_24 , V_2 , V_95 , V_16 + 1 ) ;
if ( V_101 )
F_70 ( V_24 , V_101 ) ;
F_63 ( V_24 , V_95 , & V_32 , NULL ) ;
F_89 ( V_95 , V_103 ) ;
F_67 ( V_24 , V_95 , & V_123 , 0 , NULL ) ;
V_95 = NULL ;
goto V_112;
}
V_113:
if ( V_15 > V_16 )
goto V_112;
F_78 ( & V_24 -> V_55 ) ;
F_79 () ;
V_124 = false ;
goto V_110;
V_112:
F_78 ( & V_24 -> V_55 ) ;
if ( V_95 )
F_43 ( V_95 ) ;
return V_101 ;
}
int F_93 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned V_32 , struct V_33 * V_34 )
{
F_23 ( V_32 & V_126 ) ;
return F_90 ( V_24 , V_15 , V_16 , V_32 , 0 , NULL , NULL , V_125 ,
V_34 ) ;
}
int F_94 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned V_32 , int V_96 , int V_102 ,
struct V_1 * * V_104 , T_3 V_56 )
{
return F_72 ( V_24 , V_15 , V_16 , V_32 , V_96 , V_102 ,
V_104 , V_56 , NULL ) ;
}
int F_95 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned V_32 , struct V_33 * V_34 )
{
F_23 ( V_32 & V_126 ) ;
return F_72 ( V_24 , V_15 , V_16 , V_32 , 0 , 0 , NULL , V_125 ,
V_34 ) ;
}
int F_96 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
struct V_1 * * V_103 )
{
int V_101 ;
T_1 V_120 ;
while ( 1 ) {
V_101 = F_90 ( V_24 , V_15 , V_16 , V_126 ,
V_126 , & V_120 ,
V_103 , V_125 , NULL ) ;
if ( V_101 == - V_91 ) {
F_85 ( V_24 , V_120 , V_16 , V_126 ) ;
V_15 = V_120 ;
} else
break;
F_45 ( V_15 > V_16 ) ;
}
return V_101 ;
}
int F_97 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 )
{
int V_101 ;
T_1 V_120 ;
V_101 = F_90 ( V_24 , V_15 , V_16 , V_126 , V_126 ,
& V_120 , NULL , V_125 , NULL ) ;
if ( V_101 == - V_91 ) {
if ( V_120 > V_15 )
F_94 ( V_24 , V_15 , V_120 - 1 ,
V_126 , 1 , 0 , NULL , V_125 ) ;
return 0 ;
}
return 1 ;
}
void F_98 ( struct V_25 * V_25 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_127 = V_15 >> V_128 ;
unsigned long V_129 = V_16 >> V_128 ;
struct V_130 * V_130 ;
while ( V_127 <= V_129 ) {
V_130 = F_99 ( V_25 -> V_131 , V_127 ) ;
F_23 ( ! V_130 ) ;
F_100 ( V_130 ) ;
F_101 ( V_130 ) ;
V_127 ++ ;
}
}
void F_102 ( struct V_25 * V_25 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_127 = V_15 >> V_128 ;
unsigned long V_129 = V_16 >> V_128 ;
struct V_130 * V_130 ;
while ( V_127 <= V_129 ) {
V_130 = F_99 ( V_25 -> V_131 , V_127 ) ;
F_23 ( ! V_130 ) ;
F_103 ( V_130 ) ;
F_104 ( V_130 ) ;
F_101 ( V_130 ) ;
V_127 ++ ;
}
}
static void F_105 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_127 = V_15 >> V_128 ;
unsigned long V_129 = V_16 >> V_128 ;
struct V_130 * V_130 ;
while ( V_127 <= V_129 ) {
V_130 = F_99 ( V_24 -> V_27 , V_127 ) ;
F_23 ( ! V_130 ) ;
F_106 ( V_130 ) ;
F_101 ( V_130 ) ;
V_127 ++ ;
}
}
static struct V_1 *
F_107 ( struct V_23 * V_24 ,
T_1 V_15 , unsigned V_32 )
{
struct V_3 * V_65 ;
struct V_1 * V_2 ;
V_65 = F_55 ( V_24 , V_15 ) ;
if ( ! V_65 )
goto V_112;
while ( 1 ) {
V_2 = F_48 ( V_65 , struct V_1 , V_3 ) ;
if ( V_2 -> V_16 >= V_15 && ( V_2 -> V_2 & V_32 ) )
return V_2 ;
V_65 = F_52 ( V_65 ) ;
if ( ! V_65 )
break;
}
V_112:
return NULL ;
}
int F_108 ( struct V_23 * V_24 , T_1 V_15 ,
T_1 * V_132 , T_1 * V_133 , unsigned V_32 ,
struct V_1 * * V_103 )
{
struct V_1 * V_2 ;
struct V_3 * V_78 ;
int V_36 = 1 ;
F_75 ( & V_24 -> V_55 ) ;
if ( V_103 && * V_103 ) {
V_2 = * V_103 ;
if ( V_2 -> V_16 == V_15 - 1 && F_1 ( V_2 ) ) {
V_78 = F_52 ( & V_2 -> V_3 ) ;
while ( V_78 ) {
V_2 = F_48 ( V_78 , struct V_1 ,
V_3 ) ;
if ( V_2 -> V_2 & V_32 )
goto V_134;
V_78 = F_52 ( V_78 ) ;
}
F_43 ( * V_103 ) ;
* V_103 = NULL ;
goto V_112;
}
F_43 ( * V_103 ) ;
* V_103 = NULL ;
}
V_2 = F_107 ( V_24 , V_15 , V_32 ) ;
V_134:
if ( V_2 ) {
F_88 ( V_2 , V_103 , 0 ) ;
* V_132 = V_2 -> V_15 ;
* V_133 = V_2 -> V_16 ;
V_36 = 0 ;
}
V_112:
F_78 ( & V_24 -> V_55 ) ;
return V_36 ;
}
static T_5 T_1 F_109 ( struct V_23 * V_24 ,
T_1 * V_15 , T_1 * V_16 , T_1 V_135 ,
struct V_1 * * V_103 )
{
struct V_3 * V_65 ;
struct V_1 * V_2 ;
T_1 V_136 = * V_15 ;
T_1 V_90 = 0 ;
T_1 V_137 = 0 ;
F_75 ( & V_24 -> V_55 ) ;
V_65 = F_55 ( V_24 , V_136 ) ;
if ( ! V_65 ) {
if ( ! V_90 )
* V_16 = ( T_1 ) - 1 ;
goto V_112;
}
while ( 1 ) {
V_2 = F_48 ( V_65 , struct V_1 , V_3 ) ;
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
F_86 ( & V_2 -> V_17 ) ;
}
V_90 ++ ;
* V_16 = V_2 -> V_16 ;
V_136 = V_2 -> V_16 + 1 ;
V_65 = F_52 ( V_65 ) ;
V_137 += V_2 -> V_16 - V_2 -> V_15 + 1 ;
if ( V_137 >= V_135 )
break;
if ( ! V_65 )
break;
}
V_112:
F_78 ( & V_24 -> V_55 ) ;
return V_90 ;
}
static T_5 void F_110 ( struct V_25 * V_25 ,
struct V_130 * V_138 ,
T_1 V_15 , T_1 V_16 )
{
unsigned long V_127 = V_15 >> V_128 ;
unsigned long V_129 = V_16 >> V_128 ;
ASSERT ( V_138 ) ;
if ( V_127 == V_138 -> V_127 && V_129 == V_127 )
return;
F_111 ( V_25 -> V_131 , V_138 , V_127 , V_129 ,
V_139 , NULL ) ;
}
static T_5 int F_112 ( struct V_25 * V_25 ,
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
V_36 = F_111 ( V_25 -> V_131 , V_138 , V_127 ,
V_129 , V_143 , & V_142 ) ;
if ( V_36 == - V_144 )
F_110 ( V_25 , V_138 , V_140 ,
( T_1 ) V_142 << V_128 ) ;
return V_36 ;
}
STATIC T_1 F_113 ( struct V_25 * V_25 ,
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
V_90 = F_109 ( V_24 , & V_140 , & V_141 ,
V_135 , & V_103 ) ;
if ( ! V_90 || V_141 <= * V_15 ) {
* V_15 = V_140 ;
* V_16 = V_141 ;
F_43 ( V_103 ) ;
return 0 ;
}
if ( V_140 < * V_15 )
V_140 = * V_15 ;
if ( V_141 + 1 - V_140 > V_135 )
V_141 = V_140 + V_135 - 1 ;
V_36 = F_112 ( V_25 , V_138 ,
V_140 , V_141 ) ;
if ( V_36 == - V_144 ) {
F_43 ( V_103 ) ;
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
F_23 ( V_36 ) ;
F_96 ( V_24 , V_140 , V_141 , & V_103 ) ;
V_36 = F_114 ( V_24 , V_140 , V_141 ,
V_107 , 1 , V_103 ) ;
if ( ! V_36 ) {
F_115 ( V_24 , V_140 , V_141 ,
& V_103 , V_125 ) ;
F_110 ( V_25 , V_138 ,
V_140 , V_141 ) ;
F_79 () ;
goto V_110;
}
F_43 ( V_103 ) ;
* V_15 = V_140 ;
* V_16 = V_141 ;
V_146:
return V_90 ;
}
static int F_111 ( struct V_51 * V_27 ,
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
F_116 ( V_27 , - V_154 ) ;
while ( V_149 > 0 ) {
V_36 = F_117 ( V_27 , V_127 ,
F_118 (unsigned long,
nr_pages, ARRAY_SIZE(pages)) , V_151 ) ;
if ( V_36 == 0 ) {
ASSERT ( V_148 & V_143 ) ;
V_101 = - V_144 ;
goto V_112;
}
for ( V_152 = 0 ; V_152 < V_36 ; V_152 ++ ) {
if ( V_148 & V_155 )
F_119 ( V_151 [ V_152 ] ) ;
if ( V_151 [ V_152 ] == V_138 ) {
F_101 ( V_151 [ V_152 ] ) ;
V_150 ++ ;
continue;
}
if ( V_148 & V_156 )
F_100 ( V_151 [ V_152 ] ) ;
if ( V_148 & V_157 )
F_106 ( V_151 [ V_152 ] ) ;
if ( V_148 & V_153 )
F_120 ( V_151 [ V_152 ] ) ;
if ( V_148 & V_158 )
F_121 ( V_151 [ V_152 ] ) ;
if ( V_148 & V_139 )
F_122 ( V_151 [ V_152 ] ) ;
if ( V_148 & V_143 ) {
F_123 ( V_151 [ V_152 ] ) ;
if ( ! F_124 ( V_151 [ V_152 ] ) ||
V_151 [ V_152 ] -> V_27 != V_27 ) {
F_122 ( V_151 [ V_152 ] ) ;
F_101 ( V_151 [ V_152 ] ) ;
V_101 = - V_144 ;
goto V_112;
}
}
F_101 ( V_151 [ V_152 ] ) ;
V_150 ++ ;
}
V_149 -= V_36 ;
V_127 += V_36 ;
F_79 () ;
}
V_112:
if ( V_101 && V_142 )
* V_142 = V_147 + V_150 - 1 ;
return V_101 ;
}
void F_125 ( struct V_25 * V_25 , T_1 V_15 , T_1 V_16 ,
T_1 V_141 , struct V_130 * V_138 ,
unsigned V_123 ,
unsigned long V_148 )
{
F_94 ( & F_19 ( V_25 ) -> V_159 , V_15 , V_16 , V_123 , 1 , 0 ,
NULL , V_125 ) ;
F_111 ( V_25 -> V_131 , V_138 ,
V_15 >> V_128 , V_16 >> V_128 ,
V_148 , NULL ) ;
}
T_1 F_126 ( struct V_23 * V_24 ,
T_1 * V_15 , T_1 V_160 , T_1 V_135 ,
unsigned V_32 , int V_161 )
{
struct V_3 * V_65 ;
struct V_1 * V_2 ;
T_1 V_136 = * V_15 ;
T_1 V_137 = 0 ;
T_1 V_162 = 0 ;
int V_90 = 0 ;
if ( F_45 ( V_160 <= V_136 ) )
return 0 ;
F_75 ( & V_24 -> V_55 ) ;
if ( V_136 == 0 && V_32 == V_99 ) {
V_137 = V_24 -> V_54 ;
goto V_112;
}
V_65 = F_55 ( V_24 , V_136 ) ;
if ( ! V_65 )
goto V_112;
while ( 1 ) {
V_2 = F_48 ( V_65 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 > V_160 )
break;
if ( V_161 && V_90 && V_2 -> V_15 > V_162 + 1 )
break;
if ( V_2 -> V_16 >= V_136 && ( V_2 -> V_2 & V_32 ) == V_32 ) {
V_137 += F_127 ( V_160 , V_2 -> V_16 ) + 1 -
F_128 ( V_136 , V_2 -> V_15 ) ;
if ( V_137 >= V_135 )
break;
if ( ! V_90 ) {
* V_15 = F_128 ( V_136 , V_2 -> V_15 ) ;
V_90 = 1 ;
}
V_162 = V_2 -> V_16 ;
} else if ( V_161 && V_90 ) {
break;
}
V_65 = F_52 ( V_65 ) ;
if ( ! V_65 )
break;
}
V_112:
F_78 ( & V_24 -> V_55 ) ;
return V_137 ;
}
static T_5 int F_129 ( struct V_23 * V_24 , T_1 V_15 ,
struct V_163 * V_59 )
{
struct V_3 * V_65 ;
struct V_1 * V_2 ;
int V_36 = 0 ;
F_75 ( & V_24 -> V_55 ) ;
V_65 = F_55 ( V_24 , V_15 ) ;
if ( ! V_65 ) {
V_36 = - V_164 ;
goto V_112;
}
V_2 = F_48 ( V_65 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 != V_15 ) {
V_36 = - V_164 ;
goto V_112;
}
V_2 -> V_59 = V_59 ;
V_112:
F_78 ( & V_24 -> V_55 ) ;
return V_36 ;
}
static T_5 int F_130 ( struct V_23 * V_24 , T_1 V_15 ,
struct V_163 * * V_59 )
{
struct V_3 * V_65 ;
struct V_1 * V_2 ;
int V_36 = 0 ;
F_75 ( & V_24 -> V_55 ) ;
V_65 = F_55 ( V_24 , V_15 ) ;
if ( ! V_65 ) {
V_36 = - V_164 ;
goto V_112;
}
V_2 = F_48 ( V_65 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 != V_15 ) {
V_36 = - V_164 ;
goto V_112;
}
* V_59 = V_2 -> V_59 ;
V_112:
F_78 ( & V_24 -> V_55 ) ;
return V_36 ;
}
int F_114 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned V_32 , int V_165 , struct V_1 * V_104 )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_65 ;
int V_166 = 0 ;
F_75 ( & V_24 -> V_55 ) ;
if ( V_104 && F_1 ( V_104 ) && V_104 -> V_15 <= V_15 &&
V_104 -> V_16 > V_15 )
V_65 = & V_104 -> V_3 ;
else
V_65 = F_55 ( V_24 , V_15 ) ;
while ( V_65 && V_15 <= V_16 ) {
V_2 = F_48 ( V_65 , struct V_1 , V_3 ) ;
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
V_65 = F_52 ( V_65 ) ;
if ( ! V_65 ) {
if ( V_165 )
V_166 = 0 ;
break;
}
}
F_78 ( & V_24 -> V_55 ) ;
return V_166 ;
}
static void F_131 ( struct V_23 * V_24 , struct V_130 * V_130 )
{
T_1 V_15 = F_132 ( V_130 ) ;
T_1 V_16 = V_15 + V_29 - 1 ;
if ( F_114 ( V_24 , V_15 , V_16 , V_167 , 1 , NULL ) )
F_133 ( V_130 ) ;
}
int F_134 ( struct V_168 * V_25 , struct V_163 * V_169 )
{
int V_36 ;
int V_101 = 0 ;
struct V_23 * V_170 = & V_25 -> V_171 ;
F_129 ( V_170 , V_169 -> V_15 , NULL ) ;
V_36 = F_135 ( V_170 , V_169 -> V_15 ,
V_169 -> V_15 + V_169 -> V_20 - 1 ,
V_126 | V_99 ) ;
if ( V_36 )
V_101 = V_36 ;
V_36 = F_135 ( & V_25 -> V_159 , V_169 -> V_15 ,
V_169 -> V_15 + V_169 -> V_20 - 1 ,
V_172 ) ;
if ( V_36 && ! V_101 )
V_101 = V_36 ;
F_136 ( V_169 ) ;
return V_101 ;
}
int F_137 ( struct V_168 * V_25 , T_1 V_15 , T_1 V_173 ,
T_1 V_174 , struct V_130 * V_130 ,
unsigned int V_175 , int V_176 )
{
struct V_40 * V_31 = V_25 -> V_30 -> V_31 ;
struct V_48 * V_48 ;
struct V_177 * V_178 ;
T_1 V_179 = 0 ;
T_1 V_180 ;
struct V_181 * V_182 = NULL ;
int V_36 ;
ASSERT ( ! ( V_31 -> V_183 -> V_184 & V_185 ) ) ;
F_23 ( ! V_176 ) ;
V_48 = F_138 ( V_125 , 1 ) ;
if ( ! V_48 )
return - V_154 ;
V_48 -> V_186 . V_187 = 0 ;
V_179 = V_173 ;
F_139 ( V_31 ) ;
if ( F_140 ( V_31 , V_174 , V_173 , V_176 ) ) {
V_36 = F_141 ( V_31 , V_188 , V_174 ,
& V_179 , & V_182 , 0 ) ;
if ( V_36 ) {
F_142 ( V_31 ) ;
F_143 ( V_48 ) ;
return - V_154 ;
}
ASSERT ( V_182 -> V_176 == 1 ) ;
} else {
V_36 = F_141 ( V_31 , V_189 , V_174 ,
& V_179 , & V_182 , V_176 ) ;
if ( V_36 ) {
F_142 ( V_31 ) ;
F_143 ( V_48 ) ;
return - V_154 ;
}
F_23 ( V_176 != V_182 -> V_176 ) ;
}
V_180 = V_182 -> V_190 [ V_182 -> V_176 - 1 ] . V_191 >> 9 ;
V_48 -> V_186 . V_192 = V_180 ;
V_178 = V_182 -> V_190 [ V_182 -> V_176 - 1 ] . V_178 ;
F_144 ( V_182 ) ;
if ( ! V_178 || ! V_178 -> V_193 || ! V_178 -> V_194 ) {
F_142 ( V_31 ) ;
F_143 ( V_48 ) ;
return - V_154 ;
}
V_48 -> V_195 = V_178 -> V_193 ;
V_48 -> V_196 = V_197 | V_198 ;
F_145 ( V_48 , V_130 , V_173 , V_175 ) ;
if ( F_146 ( V_48 ) ) {
F_142 ( V_31 ) ;
F_143 ( V_48 ) ;
F_147 ( V_178 , V_199 ) ;
return - V_154 ;
}
F_148 ( V_31 ,
L_9 ,
F_20 ( V_25 ) , V_15 ,
F_149 ( V_178 -> V_200 ) , V_180 ) ;
F_142 ( V_31 ) ;
F_143 ( V_48 ) ;
return 0 ;
}
int F_150 ( struct V_40 * V_31 ,
struct V_10 * V_11 , int V_176 )
{
T_1 V_15 = V_11 -> V_15 ;
unsigned long V_152 , V_201 = F_151 ( V_11 -> V_15 , V_11 -> V_20 ) ;
int V_36 = 0 ;
if ( V_31 -> V_183 -> V_184 & V_185 )
return - V_202 ;
for ( V_152 = 0 ; V_152 < V_201 ; V_152 ++ ) {
struct V_130 * V_68 = V_11 -> V_151 [ V_152 ] ;
V_36 = F_137 ( F_19 ( V_31 -> V_203 ) , V_15 ,
V_29 , V_15 , V_68 ,
V_15 - F_132 ( V_68 ) , V_176 ) ;
if ( V_36 )
break;
V_15 += V_29 ;
}
return V_36 ;
}
int F_152 ( struct V_168 * V_25 , T_1 V_15 , struct V_130 * V_130 ,
unsigned int V_175 )
{
T_1 V_204 ;
struct V_163 * V_59 ;
struct V_40 * V_31 = V_25 -> V_30 -> V_31 ;
struct V_1 * V_2 ;
int V_205 ;
int V_36 ;
V_204 = 0 ;
V_36 = F_126 ( & V_25 -> V_171 , & V_204 ,
( T_1 ) - 1 , 1 , V_99 , 0 ) ;
if ( ! V_36 )
return 0 ;
V_36 = F_130 ( & V_25 -> V_171 , V_15 ,
& V_59 ) ;
if ( V_36 )
return 0 ;
F_23 ( ! V_59 -> V_206 ) ;
if ( V_59 -> V_207 ) {
F_153 ( V_31 ,
L_10 ,
V_59 -> V_15 ) ;
goto V_112;
}
if ( V_31 -> V_183 -> V_184 & V_185 )
goto V_112;
F_75 ( & V_25 -> V_159 . V_55 ) ;
V_2 = F_107 ( & V_25 -> V_159 ,
V_59 -> V_15 ,
V_126 ) ;
F_78 ( & V_25 -> V_159 . V_55 ) ;
if ( V_2 && V_2 -> V_15 <= V_59 -> V_15 &&
V_2 -> V_16 >= V_59 -> V_15 + V_59 -> V_20 - 1 ) {
V_205 = F_154 ( V_31 , V_59 -> V_174 ,
V_59 -> V_20 ) ;
if ( V_205 > 1 ) {
F_137 ( V_25 , V_15 , V_59 -> V_20 ,
V_59 -> V_174 , V_130 ,
V_175 , V_59 -> V_208 ) ;
}
}
V_112:
F_134 ( V_25 , V_59 ) ;
return 0 ;
}
void F_155 ( struct V_168 * V_25 , T_1 V_15 , T_1 V_16 )
{
struct V_23 * V_170 = & V_25 -> V_171 ;
struct V_163 * V_59 ;
struct V_1 * V_2 , * V_13 ;
if ( F_156 ( & V_170 -> V_2 ) )
return;
F_75 ( & V_170 -> V_55 ) ;
V_2 = F_107 ( V_170 , V_15 , V_99 ) ;
while ( V_2 ) {
if ( V_2 -> V_15 > V_16 )
break;
ASSERT ( V_2 -> V_16 <= V_16 ) ;
V_13 = F_66 ( V_2 ) ;
V_59 = V_2 -> V_59 ;
F_43 ( V_2 ) ;
F_136 ( V_59 ) ;
V_2 = V_13 ;
}
F_78 ( & V_170 -> V_55 ) ;
}
int F_157 ( struct V_25 * V_25 , T_1 V_15 , T_1 V_16 ,
struct V_163 * * V_209 )
{
struct V_40 * V_31 = F_25 ( V_25 -> V_41 ) ;
struct V_163 * V_59 ;
struct V_210 * V_211 ;
struct V_23 * V_170 = & F_19 ( V_25 ) -> V_171 ;
struct V_23 * V_24 = & F_19 ( V_25 ) -> V_159 ;
struct V_212 * V_213 = & F_19 ( V_25 ) -> V_214 ;
int V_36 ;
T_1 V_174 ;
V_36 = F_130 ( V_170 , V_15 , & V_59 ) ;
if ( V_36 ) {
V_59 = F_158 ( sizeof( * V_59 ) , V_125 ) ;
if ( ! V_59 )
return - V_43 ;
V_59 -> V_15 = V_15 ;
V_59 -> V_20 = V_16 - V_15 + 1 ;
V_59 -> V_206 = 0 ;
V_59 -> V_215 = 0 ;
V_59 -> V_207 = 0 ;
F_159 ( & V_213 -> V_55 ) ;
V_211 = F_160 ( V_213 , V_15 , V_59 -> V_20 ) ;
if ( ! V_211 ) {
F_161 ( & V_213 -> V_55 ) ;
F_136 ( V_59 ) ;
return - V_154 ;
}
if ( V_211 -> V_15 > V_15 || V_211 -> V_15 + V_211 -> V_20 <= V_15 ) {
F_162 ( V_211 ) ;
V_211 = NULL ;
}
F_161 ( & V_213 -> V_55 ) ;
if ( ! V_211 ) {
F_136 ( V_59 ) ;
return - V_154 ;
}
V_174 = V_15 - V_211 -> V_15 ;
V_174 = V_211 -> V_216 + V_174 ;
if ( F_163 ( V_217 , & V_211 -> V_7 ) ) {
V_174 = V_211 -> V_216 ;
V_59 -> V_215 = V_218 ;
F_164 ( & V_59 -> V_215 ,
V_211 -> V_219 ) ;
}
F_153 ( V_31 ,
L_11 ,
V_174 , V_15 , V_59 -> V_20 ) ;
V_59 -> V_174 = V_174 ;
F_162 ( V_211 ) ;
V_36 = F_165 ( V_170 , V_15 , V_16 ,
V_126 | V_99 ) ;
if ( V_36 >= 0 )
V_36 = F_129 ( V_170 , V_15 , V_59 ) ;
if ( V_36 >= 0 )
V_36 = F_165 ( V_24 , V_15 , V_16 , V_172 ) ;
if ( V_36 < 0 ) {
F_136 ( V_59 ) ;
return V_36 ;
}
} else {
F_153 ( V_31 ,
L_12 ,
V_59 -> V_174 , V_59 -> V_15 , V_59 -> V_20 ,
V_59 -> V_207 ) ;
}
* V_209 = V_59 ;
return 0 ;
}
int F_166 ( struct V_25 * V_25 , struct V_48 * V_220 ,
struct V_163 * V_59 , int V_208 )
{
struct V_40 * V_31 = F_25 ( V_25 -> V_41 ) ;
int V_205 ;
V_205 = F_154 ( V_31 , V_59 -> V_174 , V_59 -> V_20 ) ;
if ( V_205 == 1 ) {
F_153 ( V_31 ,
L_13 ,
V_205 , V_59 -> V_206 , V_208 ) ;
return 0 ;
}
if ( V_220 -> V_221 > 1 ) {
F_23 ( V_59 -> V_207 ) ;
V_59 -> V_207 = 1 ;
V_59 -> V_206 = V_208 ;
} else {
if ( V_59 -> V_207 ) {
F_23 ( V_59 -> V_206 != V_208 ) ;
V_59 -> V_207 = 0 ;
V_59 -> V_206 = 0 ;
}
V_59 -> V_208 = V_208 ;
V_59 -> V_206 ++ ;
if ( V_59 -> V_206 == V_208 )
V_59 -> V_206 ++ ;
}
if ( V_59 -> V_206 > V_205 ) {
F_153 ( V_31 ,
L_14 ,
V_205 , V_59 -> V_206 , V_208 ) ;
return 0 ;
}
return 1 ;
}
struct V_48 * F_167 ( struct V_25 * V_25 , struct V_48 * V_220 ,
struct V_163 * V_59 ,
struct V_130 * V_130 , int V_175 , int V_222 ,
T_7 * V_223 , void * V_224 )
{
struct V_40 * V_31 = F_25 ( V_25 -> V_41 ) ;
struct V_48 * V_48 ;
struct V_47 * V_225 ;
struct V_47 * V_181 ;
V_48 = F_138 ( V_125 , 1 ) ;
if ( ! V_48 )
return NULL ;
V_48 -> V_226 = V_223 ;
V_48 -> V_186 . V_192 = V_59 -> V_174 >> 9 ;
V_48 -> V_195 = V_31 -> V_227 -> V_228 ;
V_48 -> V_186 . V_187 = 0 ;
V_48 -> V_229 = V_224 ;
V_225 = V_47 ( V_220 ) ;
if ( V_225 -> V_230 ) {
T_8 V_231 = F_168 ( V_31 -> V_232 ) ;
V_181 = V_47 ( V_48 ) ;
V_181 -> V_230 = V_181 -> V_233 ;
V_222 *= V_231 ;
memcpy ( V_181 -> V_230 , V_225 -> V_230 + V_222 ,
V_231 ) ;
}
F_145 ( V_48 , V_130 , V_59 -> V_20 , V_175 ) ;
return V_48 ;
}
static int F_169 ( struct V_48 * V_220 , T_1 V_234 ,
struct V_130 * V_130 , T_1 V_15 , T_1 V_16 ,
int V_208 )
{
struct V_163 * V_59 ;
struct V_25 * V_25 = V_130 -> V_27 -> V_28 ;
struct V_23 * V_24 = & F_19 ( V_25 ) -> V_159 ;
struct V_48 * V_48 ;
int V_235 = 0 ;
int V_36 ;
F_23 ( F_170 ( V_220 ) == V_197 ) ;
V_36 = F_157 ( V_25 , V_15 , V_16 , & V_59 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_166 ( V_25 , V_220 , V_59 , V_208 ) ;
if ( ! V_36 ) {
F_134 ( F_19 ( V_25 ) , V_59 ) ;
return - V_154 ;
}
if ( V_220 -> V_221 > 1 )
V_235 |= V_236 ;
V_234 >>= V_25 -> V_41 -> V_237 ;
V_48 = F_167 ( V_25 , V_220 , V_59 , V_130 ,
V_15 - F_132 ( V_130 ) ,
( int ) V_234 , V_220 -> V_226 ,
NULL ) ;
if ( ! V_48 ) {
F_134 ( F_19 ( V_25 ) , V_59 ) ;
return - V_154 ;
}
F_171 ( V_48 , V_238 , V_235 ) ;
F_153 ( F_25 ( V_25 -> V_41 ) ,
L_15 ,
V_235 , V_59 -> V_206 , V_59 -> V_207 ) ;
V_36 = V_24 -> V_53 -> V_239 ( V_25 , V_48 , V_59 -> V_206 ,
V_59 -> V_215 , 0 ) ;
if ( V_36 ) {
F_134 ( F_19 ( V_25 ) , V_59 ) ;
F_143 ( V_48 ) ;
}
return V_36 ;
}
void F_172 ( struct V_130 * V_130 , int V_101 , T_1 V_15 , T_1 V_16 )
{
int V_240 = ( V_101 == 0 ) ;
struct V_23 * V_24 ;
int V_36 = 0 ;
V_24 = & F_19 ( V_130 -> V_27 -> V_28 ) -> V_159 ;
if ( V_24 -> V_53 && V_24 -> V_53 -> V_241 )
V_24 -> V_53 -> V_241 ( V_130 , V_15 , V_16 , NULL ,
V_240 ) ;
if ( ! V_240 ) {
F_173 ( V_130 ) ;
F_120 ( V_130 ) ;
V_36 = V_101 < 0 ? V_101 : - V_154 ;
F_116 ( V_130 -> V_27 , V_36 ) ;
}
}
static void F_174 ( struct V_48 * V_48 )
{
struct V_242 * V_243 ;
T_1 V_15 ;
T_1 V_16 ;
int V_152 ;
F_175 (bvec, bio, i) {
struct V_130 * V_130 = V_243 -> V_244 ;
struct V_25 * V_25 = V_130 -> V_27 -> V_28 ;
struct V_40 * V_31 = F_25 ( V_25 -> V_41 ) ;
if ( V_243 -> V_245 || V_243 -> V_246 != V_29 ) {
if ( V_243 -> V_245 + V_243 -> V_246 != V_29 )
F_176 ( V_31 ,
L_16 ,
V_243 -> V_245 , V_243 -> V_246 ) ;
else
F_177 ( V_31 ,
L_17 ,
V_243 -> V_245 , V_243 -> V_246 ) ;
}
V_15 = F_132 ( V_130 ) ;
V_16 = V_15 + V_243 -> V_245 + V_243 -> V_246 - 1 ;
F_172 ( V_130 , V_48 -> V_247 , V_15 , V_16 ) ;
F_121 ( V_130 ) ;
}
F_143 ( V_48 ) ;
}
static void
F_178 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_20 ,
int V_240 )
{
struct V_1 * V_104 = NULL ;
T_1 V_16 = V_15 + V_20 - 1 ;
if ( V_240 && V_24 -> V_248 )
F_179 ( V_24 , V_15 , V_16 , & V_104 , V_39 ) ;
F_115 ( V_24 , V_15 , V_16 , & V_104 , V_39 ) ;
}
static void F_180 ( struct V_48 * V_48 )
{
struct V_242 * V_243 ;
int V_240 = ! V_48 -> V_247 ;
struct V_47 * V_249 = V_47 ( V_48 ) ;
struct V_23 * V_24 ;
T_1 V_64 = 0 ;
T_1 V_15 ;
T_1 V_16 ;
T_1 V_20 ;
T_1 V_250 = 0 ;
T_1 V_251 = 0 ;
int V_252 ;
int V_36 ;
int V_152 ;
F_175 (bvec, bio, i) {
struct V_130 * V_130 = V_243 -> V_244 ;
struct V_25 * V_25 = V_130 -> V_27 -> V_28 ;
struct V_40 * V_31 = F_25 ( V_25 -> V_41 ) ;
F_153 ( V_31 ,
L_18 ,
( T_1 ) V_48 -> V_186 . V_192 , V_48 -> V_247 ,
V_249 -> V_176 ) ;
V_24 = & F_19 ( V_25 ) -> V_159 ;
if ( V_243 -> V_245 || V_243 -> V_246 != V_29 ) {
if ( V_243 -> V_245 + V_243 -> V_246 != V_29 )
F_176 ( V_31 ,
L_19 ,
V_243 -> V_245 , V_243 -> V_246 ) ;
else
F_177 ( V_31 ,
L_20 ,
V_243 -> V_245 , V_243 -> V_246 ) ;
}
V_15 = F_132 ( V_130 ) ;
V_16 = V_15 + V_243 -> V_245 + V_243 -> V_246 - 1 ;
V_20 = V_243 -> V_246 ;
V_252 = V_249 -> V_176 ;
if ( F_181 ( V_240 && V_24 -> V_53 ) ) {
V_36 = V_24 -> V_53 -> V_253 ( V_249 , V_64 ,
V_130 , V_15 , V_16 ,
V_252 ) ;
if ( V_36 )
V_240 = 0 ;
else
F_152 ( F_19 ( V_25 ) , V_15 ,
V_130 , 0 ) ;
}
if ( F_181 ( V_240 ) )
goto V_254;
if ( V_24 -> V_53 ) {
V_36 = V_24 -> V_53 -> V_255 ( V_130 , V_252 ) ;
if ( V_36 == - V_144 ) {
V_36 = F_169 ( V_48 , V_64 , V_130 ,
V_15 , V_16 , V_252 ) ;
if ( V_36 == 0 ) {
V_240 = ! V_48 -> V_247 ;
V_64 += V_20 ;
continue;
}
}
ASSERT ( V_36 == - V_154 ) ;
}
V_254:
if ( F_181 ( V_240 ) ) {
T_9 V_256 = F_17 ( V_25 ) ;
T_6 V_129 = V_256 >> V_128 ;
unsigned V_257 ;
V_257 = V_256 & ( V_29 - 1 ) ;
if ( V_130 -> V_127 == V_129 && V_257 )
F_182 ( V_130 , V_257 , V_29 ) ;
F_133 ( V_130 ) ;
} else {
F_173 ( V_130 ) ;
F_120 ( V_130 ) ;
}
F_122 ( V_130 ) ;
V_64 += V_20 ;
if ( F_183 ( ! V_240 ) ) {
if ( V_251 ) {
F_178 ( V_24 ,
V_250 ,
V_251 , 1 ) ;
V_250 = 0 ;
V_251 = 0 ;
}
F_178 ( V_24 , V_15 ,
V_16 - V_15 + 1 , 0 ) ;
} else if ( ! V_251 ) {
V_250 = V_15 ;
V_251 = V_16 + 1 - V_15 ;
} else if ( V_250 + V_251 == V_15 ) {
V_251 += V_16 + 1 - V_15 ;
} else {
F_178 ( V_24 , V_250 ,
V_251 , V_240 ) ;
V_250 = V_15 ;
V_251 = V_16 + 1 - V_15 ;
}
}
if ( V_251 )
F_178 ( V_24 , V_250 , V_251 ,
V_240 ) ;
if ( V_249 -> V_258 )
V_249 -> V_258 ( V_249 , V_48 -> V_247 ) ;
F_143 ( V_48 ) ;
}
struct V_48 *
F_184 ( struct V_259 * V_193 , T_1 V_260 , int V_261 ,
T_3 V_262 )
{
struct V_47 * V_181 ;
struct V_48 * V_48 ;
V_48 = F_185 ( V_262 , V_261 , V_45 ) ;
if ( V_48 == NULL && ( V_263 -> V_7 & V_264 ) ) {
while ( ! V_48 && ( V_261 /= 2 ) ) {
V_48 = F_185 ( V_262 ,
V_261 , V_45 ) ;
}
}
if ( V_48 ) {
V_48 -> V_195 = V_193 ;
V_48 -> V_186 . V_192 = V_260 ;
V_181 = V_47 ( V_48 ) ;
V_181 -> V_230 = NULL ;
V_181 -> V_265 = NULL ;
V_181 -> V_258 = NULL ;
}
return V_48 ;
}
struct V_48 * F_186 ( struct V_48 * V_48 , T_3 V_266 )
{
struct V_47 * V_181 ;
struct V_48 * V_5 ;
V_5 = F_187 ( V_48 , V_266 , V_45 ) ;
if ( V_5 ) {
V_181 = V_47 ( V_5 ) ;
V_181 -> V_230 = NULL ;
V_181 -> V_265 = NULL ;
V_181 -> V_258 = NULL ;
}
return V_5 ;
}
struct V_48 * F_138 ( T_3 V_266 , unsigned int V_267 )
{
struct V_47 * V_181 ;
struct V_48 * V_48 ;
V_48 = F_185 ( V_266 , V_267 , V_45 ) ;
if ( V_48 ) {
V_181 = V_47 ( V_48 ) ;
V_181 -> V_230 = NULL ;
V_181 -> V_265 = NULL ;
V_181 -> V_258 = NULL ;
}
return V_48 ;
}
static int T_4 F_188 ( struct V_48 * V_48 , int V_176 ,
unsigned long V_215 )
{
int V_36 = 0 ;
struct V_242 * V_243 = V_48 -> V_268 + V_48 -> V_221 - 1 ;
struct V_130 * V_130 = V_243 -> V_244 ;
struct V_23 * V_24 = V_48 -> V_229 ;
T_1 V_15 ;
V_15 = F_132 ( V_130 ) + V_243 -> V_245 ;
V_48 -> V_229 = NULL ;
F_189 ( V_48 ) ;
if ( V_24 -> V_53 )
V_36 = V_24 -> V_53 -> V_239 ( V_130 -> V_27 -> V_28 , V_48 ,
V_176 , V_215 , V_15 ) ;
else
F_190 ( V_48 ) ;
F_143 ( V_48 ) ;
return V_36 ;
}
static int F_191 ( struct V_23 * V_24 , struct V_130 * V_130 ,
unsigned long V_64 , T_10 V_269 , struct V_48 * V_48 ,
unsigned long V_215 )
{
int V_36 = 0 ;
if ( V_24 -> V_53 )
V_36 = V_24 -> V_53 -> V_270 ( V_130 , V_64 , V_269 , V_48 ,
V_215 ) ;
return V_36 ;
}
static int F_192 ( int V_271 , int V_272 , struct V_23 * V_24 ,
struct V_273 * V_274 ,
struct V_130 * V_130 , T_11 V_180 ,
T_10 V_269 , unsigned long V_64 ,
struct V_259 * V_193 ,
struct V_48 * * V_275 ,
T_7 V_276 ,
int V_176 ,
unsigned long V_277 ,
unsigned long V_215 ,
bool V_278 )
{
int V_36 = 0 ;
struct V_48 * V_48 ;
int V_161 = 0 ;
int V_279 = V_277 & V_218 ;
T_10 V_280 = F_118 ( T_10 , V_269 , V_29 ) ;
if ( V_275 && * V_275 ) {
V_48 = * V_275 ;
if ( V_279 )
V_161 = V_48 -> V_186 . V_192 == V_180 ;
else
V_161 = F_193 ( V_48 ) == V_180 ;
if ( V_277 != V_215 || ! V_161 ||
V_278 ||
F_191 ( V_24 , V_130 , V_64 , V_280 , V_48 , V_215 ) ||
F_145 ( V_48 , V_130 , V_280 , V_64 ) < V_280 ) {
V_36 = F_188 ( V_48 , V_176 , V_277 ) ;
if ( V_36 < 0 ) {
* V_275 = NULL ;
return V_36 ;
}
V_48 = NULL ;
} else {
if ( V_274 )
F_194 ( V_274 , V_130 , V_280 ) ;
return 0 ;
}
}
V_48 = F_184 ( V_193 , V_180 , V_281 ,
V_125 | V_282 ) ;
if ( ! V_48 )
return - V_43 ;
F_145 ( V_48 , V_130 , V_280 , V_64 ) ;
V_48 -> V_226 = V_276 ;
V_48 -> V_229 = V_24 ;
F_171 ( V_48 , V_271 , V_272 ) ;
if ( V_274 ) {
F_195 ( V_274 , V_48 ) ;
F_194 ( V_274 , V_130 , V_280 ) ;
}
if ( V_275 )
* V_275 = V_48 ;
else
V_36 = F_188 ( V_48 , V_176 , V_215 ) ;
return V_36 ;
}
static void F_196 ( struct V_10 * V_11 ,
struct V_130 * V_130 )
{
if ( ! F_197 ( V_130 ) ) {
F_198 ( V_130 ) ;
F_199 ( V_130 ) ;
F_200 ( V_130 , ( unsigned long ) V_11 ) ;
} else {
F_45 ( V_130 -> V_204 != ( unsigned long ) V_11 ) ;
}
}
void F_201 ( struct V_130 * V_130 )
{
if ( ! F_197 ( V_130 ) ) {
F_198 ( V_130 ) ;
F_199 ( V_130 ) ;
F_200 ( V_130 , V_283 ) ;
}
}
static struct V_210 *
F_202 ( struct V_25 * V_25 , struct V_130 * V_130 , T_10 V_175 ,
T_1 V_15 , T_1 V_20 , T_12 * V_284 ,
struct V_210 * * V_285 )
{
struct V_210 * V_211 ;
if ( V_285 && * V_285 ) {
V_211 = * V_285 ;
if ( F_203 ( V_211 ) && V_15 >= V_211 -> V_15 &&
V_15 < F_204 ( V_211 ) ) {
F_86 ( & V_211 -> V_17 ) ;
return V_211 ;
}
F_162 ( V_211 ) ;
* V_285 = NULL ;
}
V_211 = V_284 ( F_19 ( V_25 ) , V_130 , V_175 , V_15 , V_20 , 0 ) ;
if ( V_285 && ! F_205 ( V_211 ) ) {
F_23 ( * V_285 ) ;
F_86 ( & V_211 -> V_17 ) ;
* V_285 = V_211 ;
}
return V_211 ;
}
static int F_206 ( struct V_23 * V_24 ,
struct V_130 * V_130 ,
T_12 * V_284 ,
struct V_210 * * V_285 ,
struct V_48 * * V_48 , int V_176 ,
unsigned long * V_215 , int V_286 ,
T_1 * V_287 )
{
struct V_25 * V_25 = V_130 -> V_27 -> V_28 ;
T_1 V_15 = F_132 ( V_130 ) ;
T_1 V_288 = V_15 + V_29 - 1 ;
T_1 V_16 ;
T_1 V_289 = V_15 ;
T_1 V_290 ;
T_1 V_291 = F_17 ( V_25 ) ;
T_1 V_216 ;
T_1 V_292 ;
T_11 V_180 ;
struct V_210 * V_211 ;
struct V_259 * V_193 ;
int V_36 = 0 ;
int V_293 = 0 ;
T_10 V_175 = 0 ;
T_10 V_294 ;
T_10 V_295 ;
T_10 V_296 = V_25 -> V_41 -> V_297 ;
unsigned long V_298 = 0 ;
F_201 ( V_130 ) ;
V_16 = V_288 ;
if ( ! F_207 ( V_130 ) ) {
if ( F_208 ( V_130 ) == 0 ) {
F_23 ( V_296 != V_29 ) ;
F_209 ( V_24 , V_15 , V_16 ) ;
goto V_112;
}
}
if ( V_130 -> V_127 == V_291 >> V_128 ) {
char * V_299 ;
T_10 V_300 = V_291 & ( V_29 - 1 ) ;
if ( V_300 ) {
V_294 = V_29 - V_300 ;
V_299 = F_210 ( V_130 ) ;
memset ( V_299 + V_300 , 0 , V_294 ) ;
F_211 ( V_130 ) ;
F_212 ( V_299 ) ;
}
}
while ( V_289 <= V_16 ) {
bool V_278 = false ;
if ( V_289 >= V_291 ) {
char * V_299 ;
struct V_1 * V_104 = NULL ;
V_294 = V_29 - V_175 ;
V_299 = F_210 ( V_130 ) ;
memset ( V_299 + V_175 , 0 , V_294 ) ;
F_211 ( V_130 ) ;
F_212 ( V_299 ) ;
F_179 ( V_24 , V_289 , V_289 + V_294 - 1 ,
& V_104 , V_125 ) ;
F_115 ( V_24 , V_289 ,
V_289 + V_294 - 1 ,
& V_104 , V_125 ) ;
break;
}
V_211 = F_202 ( V_25 , V_130 , V_175 , V_289 ,
V_16 - V_289 + 1 , V_284 , V_285 ) ;
if ( F_205 ( V_211 ) ) {
F_120 ( V_130 ) ;
F_209 ( V_24 , V_289 , V_16 ) ;
break;
}
V_290 = V_289 - V_211 -> V_15 ;
F_23 ( F_204 ( V_211 ) <= V_289 ) ;
F_23 ( V_16 < V_289 ) ;
if ( F_163 ( V_217 , & V_211 -> V_7 ) ) {
V_298 |= V_218 ;
F_164 ( & V_298 ,
V_211 -> V_219 ) ;
}
V_294 = F_127 ( F_204 ( V_211 ) - V_289 , V_16 - V_289 + 1 ) ;
V_292 = F_127 ( F_204 ( V_211 ) - 1 , V_16 ) ;
V_294 = F_213 ( V_294 , V_296 ) ;
if ( V_298 & V_218 ) {
V_295 = V_211 -> V_301 ;
V_180 = V_211 -> V_216 >> 9 ;
} else {
V_180 = ( V_211 -> V_216 + V_290 ) >> 9 ;
V_295 = V_294 ;
}
V_193 = V_211 -> V_193 ;
V_216 = V_211 -> V_216 ;
if ( F_163 ( V_302 , & V_211 -> V_7 ) )
V_216 = V_303 ;
if ( F_163 ( V_217 , & V_211 -> V_7 ) &&
V_287 && * V_287 != ( T_1 ) - 1 &&
* V_287 != V_211 -> V_304 )
V_278 = true ;
if ( V_287 )
* V_287 = V_211 -> V_304 ;
F_162 ( V_211 ) ;
V_211 = NULL ;
if ( V_216 == V_303 ) {
char * V_299 ;
struct V_1 * V_104 = NULL ;
V_299 = F_210 ( V_130 ) ;
memset ( V_299 + V_175 , 0 , V_294 ) ;
F_211 ( V_130 ) ;
F_212 ( V_299 ) ;
F_179 ( V_24 , V_289 , V_289 + V_294 - 1 ,
& V_104 , V_125 ) ;
F_115 ( V_24 , V_289 ,
V_289 + V_294 - 1 ,
& V_104 , V_125 ) ;
V_289 = V_289 + V_294 ;
V_175 += V_294 ;
continue;
}
if ( F_114 ( V_24 , V_289 , V_292 ,
V_167 , 1 , NULL ) ) {
F_131 ( V_24 , V_130 ) ;
F_209 ( V_24 , V_289 , V_289 + V_294 - 1 ) ;
V_289 = V_289 + V_294 ;
V_175 += V_294 ;
continue;
}
if ( V_216 == V_305 ) {
F_120 ( V_130 ) ;
F_209 ( V_24 , V_289 , V_289 + V_294 - 1 ) ;
V_289 = V_289 + V_294 ;
V_175 += V_294 ;
continue;
}
V_36 = F_192 ( V_238 , V_286 , V_24 , NULL ,
V_130 , V_180 , V_295 , V_175 ,
V_193 , V_48 ,
F_180 , V_176 ,
* V_215 ,
V_298 ,
V_278 ) ;
if ( ! V_36 ) {
V_293 ++ ;
* V_215 = V_298 ;
} else {
F_120 ( V_130 ) ;
F_209 ( V_24 , V_289 , V_289 + V_294 - 1 ) ;
goto V_112;
}
V_289 = V_289 + V_294 ;
V_175 += V_294 ;
}
V_112:
if ( ! V_293 ) {
if ( ! F_214 ( V_130 ) )
F_133 ( V_130 ) ;
F_122 ( V_130 ) ;
}
return V_36 ;
}
static inline void F_215 ( struct V_23 * V_24 ,
struct V_130 * V_151 [] , int V_149 ,
T_1 V_15 , T_1 V_16 ,
T_12 * V_284 ,
struct V_210 * * V_285 ,
struct V_48 * * V_48 , int V_176 ,
unsigned long * V_215 ,
T_1 * V_287 )
{
struct V_25 * V_25 ;
struct V_306 * V_307 ;
int V_127 ;
V_25 = V_151 [ 0 ] -> V_27 -> V_28 ;
while ( 1 ) {
F_216 ( V_24 , V_15 , V_16 ) ;
V_307 = F_217 ( F_19 ( V_25 ) , V_15 ,
V_16 - V_15 + 1 ) ;
if ( ! V_307 )
break;
F_209 ( V_24 , V_15 , V_16 ) ;
F_218 ( V_25 , V_307 , 1 ) ;
F_219 ( V_307 ) ;
}
for ( V_127 = 0 ; V_127 < V_149 ; V_127 ++ ) {
F_206 ( V_24 , V_151 [ V_127 ] , V_284 , V_285 , V_48 ,
V_176 , V_215 , 0 , V_287 ) ;
F_101 ( V_151 [ V_127 ] ) ;
}
}
static void F_220 ( struct V_23 * V_24 ,
struct V_130 * V_151 [] ,
int V_149 , T_12 * V_284 ,
struct V_210 * * V_285 ,
struct V_48 * * V_48 , int V_176 ,
unsigned long * V_215 ,
T_1 * V_287 )
{
T_1 V_15 = 0 ;
T_1 V_16 = 0 ;
T_1 V_308 ;
int V_127 ;
int V_309 = 0 ;
for ( V_127 = 0 ; V_127 < V_149 ; V_127 ++ ) {
V_308 = F_132 ( V_151 [ V_127 ] ) ;
if ( ! V_16 ) {
V_15 = V_308 ;
V_16 = V_15 + V_29 - 1 ;
V_309 = V_127 ;
} else if ( V_16 + 1 == V_308 ) {
V_16 += V_29 ;
} else {
F_215 ( V_24 , & V_151 [ V_309 ] ,
V_127 - V_309 , V_15 ,
V_16 , V_284 , V_285 ,
V_48 , V_176 , V_215 ,
V_287 ) ;
V_15 = V_308 ;
V_16 = V_15 + V_29 - 1 ;
V_309 = V_127 ;
}
}
if ( V_16 )
F_215 ( V_24 , & V_151 [ V_309 ] ,
V_127 - V_309 , V_15 ,
V_16 , V_284 , V_285 , V_48 ,
V_176 , V_215 ,
V_287 ) ;
}
static int F_221 ( struct V_23 * V_24 ,
struct V_130 * V_130 ,
T_12 * V_284 ,
struct V_48 * * V_48 , int V_176 ,
unsigned long * V_215 , int V_286 )
{
struct V_25 * V_25 = V_130 -> V_27 -> V_28 ;
struct V_306 * V_307 ;
T_1 V_15 = F_132 ( V_130 ) ;
T_1 V_16 = V_15 + V_29 - 1 ;
int V_36 ;
while ( 1 ) {
F_216 ( V_24 , V_15 , V_16 ) ;
V_307 = F_217 ( F_19 ( V_25 ) , V_15 ,
V_29 ) ;
if ( ! V_307 )
break;
F_209 ( V_24 , V_15 , V_16 ) ;
F_218 ( V_25 , V_307 , 1 ) ;
F_219 ( V_307 ) ;
}
V_36 = F_206 ( V_24 , V_130 , V_284 , NULL , V_48 , V_176 ,
V_215 , V_286 , NULL ) ;
return V_36 ;
}
int F_222 ( struct V_23 * V_24 , struct V_130 * V_130 ,
T_12 * V_284 , int V_176 )
{
struct V_48 * V_48 = NULL ;
unsigned long V_215 = 0 ;
int V_36 ;
V_36 = F_221 ( V_24 , V_130 , V_284 , & V_48 , V_176 ,
& V_215 , 0 ) ;
if ( V_48 )
V_36 = F_188 ( V_48 , V_176 , V_215 ) ;
return V_36 ;
}
static void F_223 ( struct V_273 * V_274 ,
unsigned long V_310 )
{
V_274 -> V_311 -= V_310 ;
}
static T_13 int F_224 ( struct V_25 * V_25 ,
struct V_130 * V_130 , struct V_273 * V_274 ,
struct V_312 * V_313 ,
T_1 V_140 ,
unsigned long * V_310 )
{
struct V_23 * V_24 = V_313 -> V_24 ;
T_1 V_288 = V_140 + V_29 - 1 ;
T_1 V_314 ;
T_1 V_315 = 0 ;
T_1 V_141 = 0 ;
int V_36 ;
int V_316 = 0 ;
if ( V_313 -> V_317 || ! V_24 -> V_53 || ! V_24 -> V_53 -> V_318 )
return 0 ;
while ( V_141 < V_288 ) {
V_314 = F_113 ( V_25 , V_24 ,
V_130 ,
& V_140 ,
& V_141 ,
V_319 ) ;
if ( V_314 == 0 ) {
V_140 = V_141 + 1 ;
continue;
}
V_36 = V_24 -> V_53 -> V_318 ( V_25 , V_130 ,
V_140 ,
V_141 ,
& V_316 ,
V_310 ) ;
if ( V_36 ) {
F_120 ( V_130 ) ;
V_36 = V_36 < 0 ? V_36 : - V_154 ;
goto V_320;
}
V_315 += ( V_141 - V_140 +
V_29 ) >> V_128 ;
V_140 = V_141 + 1 ;
}
if ( V_274 -> V_311 < V_315 ) {
int V_321 = 8192 ;
if ( V_315 < V_321 * 2 )
V_321 = V_315 ;
V_274 -> V_311 = F_118 ( T_1 , V_315 ,
V_321 ) ;
}
if ( V_316 ) {
V_274 -> V_311 -= * V_310 ;
return 1 ;
}
V_36 = 0 ;
V_320:
return V_36 ;
}
static T_13 int F_225 ( struct V_25 * V_25 ,
struct V_130 * V_130 ,
struct V_273 * V_274 ,
struct V_312 * V_313 ,
T_9 V_256 ,
unsigned long V_310 ,
int V_322 , int * V_323 )
{
struct V_23 * V_24 = V_313 -> V_24 ;
T_1 V_15 = F_132 ( V_130 ) ;
T_1 V_288 = V_15 + V_29 - 1 ;
T_1 V_16 ;
T_1 V_289 = V_15 ;
T_1 V_290 ;
T_1 V_216 ;
T_1 V_294 ;
T_11 V_180 ;
struct V_210 * V_211 ;
struct V_259 * V_193 ;
T_10 V_175 = 0 ;
T_10 V_296 ;
int V_36 = 0 ;
int V_293 = 0 ;
bool V_324 ;
if ( V_24 -> V_53 && V_24 -> V_53 -> V_325 ) {
V_36 = V_24 -> V_53 -> V_325 ( V_130 , V_15 ,
V_288 ) ;
if ( V_36 ) {
if ( V_36 == - V_326 )
V_274 -> V_327 ++ ;
else
F_226 ( V_274 , V_130 ) ;
F_223 ( V_274 , V_310 ) ;
F_122 ( V_130 ) ;
return 1 ;
}
}
F_223 ( V_274 , V_310 + 1 ) ;
V_16 = V_288 ;
if ( V_256 <= V_15 ) {
if ( V_24 -> V_53 && V_24 -> V_53 -> V_241 )
V_24 -> V_53 -> V_241 ( V_130 , V_15 ,
V_288 , NULL , 1 ) ;
goto V_320;
}
V_296 = V_25 -> V_41 -> V_297 ;
while ( V_289 <= V_16 ) {
T_1 V_328 ;
if ( V_289 >= V_256 ) {
if ( V_24 -> V_53 && V_24 -> V_53 -> V_241 )
V_24 -> V_53 -> V_241 ( V_130 , V_289 ,
V_288 , NULL , 1 ) ;
break;
}
V_211 = V_313 -> V_284 ( F_19 ( V_25 ) , V_130 , V_175 , V_289 ,
V_16 - V_289 + 1 , 1 ) ;
if ( F_205 ( V_211 ) ) {
F_120 ( V_130 ) ;
V_36 = F_227 ( V_211 ) ;
break;
}
V_290 = V_289 - V_211 -> V_15 ;
V_328 = F_204 ( V_211 ) ;
F_23 ( V_328 <= V_289 ) ;
F_23 ( V_16 < V_289 ) ;
V_294 = F_127 ( V_328 - V_289 , V_16 - V_289 + 1 ) ;
V_294 = F_213 ( V_294 , V_296 ) ;
V_180 = ( V_211 -> V_216 + V_290 ) >> 9 ;
V_193 = V_211 -> V_193 ;
V_216 = V_211 -> V_216 ;
V_324 = F_163 ( V_217 , & V_211 -> V_7 ) ;
F_162 ( V_211 ) ;
V_211 = NULL ;
if ( V_324 || V_216 == V_303 ||
V_216 == V_305 ) {
if ( ! V_324 && V_24 -> V_53 &&
V_24 -> V_53 -> V_241 )
V_24 -> V_53 -> V_241 ( V_130 , V_289 ,
V_289 + V_294 - 1 ,
NULL , 1 ) ;
else if ( V_324 ) {
V_293 ++ ;
}
V_289 += V_294 ;
V_175 += V_294 ;
continue;
}
F_105 ( V_24 , V_289 , V_289 + V_294 - 1 ) ;
if ( ! F_228 ( V_130 ) ) {
F_176 ( F_19 ( V_25 ) -> V_30 -> V_31 ,
L_21 ,
V_130 -> V_127 , V_289 , V_16 ) ;
}
V_36 = F_192 ( V_197 , V_322 , V_24 , V_274 ,
V_130 , V_180 , V_294 , V_175 ,
V_193 , & V_313 -> V_48 ,
F_174 ,
0 , 0 , 0 , false ) ;
if ( V_36 ) {
F_120 ( V_130 ) ;
if ( F_228 ( V_130 ) )
F_121 ( V_130 ) ;
}
V_289 = V_289 + V_294 ;
V_175 += V_294 ;
V_293 ++ ;
}
V_320:
* V_323 = V_293 ;
return V_36 ;
}
static int F_229 ( struct V_130 * V_130 , struct V_273 * V_274 ,
void * V_224 )
{
struct V_25 * V_25 = V_130 -> V_27 -> V_28 ;
struct V_312 * V_313 = V_224 ;
T_1 V_15 = F_132 ( V_130 ) ;
T_1 V_288 = V_15 + V_29 - 1 ;
int V_36 ;
int V_293 = 0 ;
T_10 V_175 = 0 ;
T_9 V_256 = F_17 ( V_25 ) ;
unsigned long V_129 = V_256 >> V_128 ;
int V_322 = 0 ;
unsigned long V_310 = 0 ;
if ( V_274 -> V_329 == V_330 )
V_322 = V_198 ;
F_230 ( V_130 , V_25 , V_274 ) ;
F_45 ( ! F_231 ( V_130 ) ) ;
F_232 ( V_130 ) ;
V_175 = V_256 & ( V_29 - 1 ) ;
if ( V_130 -> V_127 > V_129 ||
( V_130 -> V_127 == V_129 && ! V_175 ) ) {
V_130 -> V_27 -> V_331 -> V_332 ( V_130 , 0 , V_29 ) ;
F_122 ( V_130 ) ;
return 0 ;
}
if ( V_130 -> V_127 == V_129 ) {
char * V_299 ;
V_299 = F_210 ( V_130 ) ;
memset ( V_299 + V_175 , 0 ,
V_29 - V_175 ) ;
F_212 ( V_299 ) ;
F_211 ( V_130 ) ;
}
V_175 = 0 ;
F_201 ( V_130 ) ;
V_36 = F_224 ( V_25 , V_130 , V_274 , V_313 , V_15 , & V_310 ) ;
if ( V_36 == 1 )
goto V_333;
if ( V_36 )
goto V_320;
V_36 = F_225 ( V_25 , V_130 , V_274 , V_313 ,
V_256 , V_310 , V_322 , & V_293 ) ;
if ( V_36 == 1 )
goto V_333;
V_320:
if ( V_293 == 0 ) {
F_106 ( V_130 ) ;
F_121 ( V_130 ) ;
}
if ( F_214 ( V_130 ) ) {
V_36 = V_36 < 0 ? V_36 : - V_154 ;
F_172 ( V_130 , V_36 , V_15 , V_288 ) ;
}
F_122 ( V_130 ) ;
return V_36 ;
V_333:
return 0 ;
}
void F_233 ( struct V_10 * V_11 )
{
F_234 ( & V_11 -> V_334 , V_335 ,
V_115 ) ;
}
static T_13 int
F_235 ( struct V_10 * V_11 ,
struct V_40 * V_31 ,
struct V_312 * V_313 )
{
unsigned long V_152 , V_201 ;
int V_336 = 0 ;
int V_36 = 0 ;
if ( ! F_236 ( V_11 ) ) {
V_336 = 1 ;
F_237 ( V_313 ) ;
F_238 ( V_11 ) ;
}
if ( F_163 ( V_335 , & V_11 -> V_334 ) ) {
F_239 ( V_11 ) ;
if ( ! V_313 -> V_337 )
return 0 ;
if ( ! V_336 ) {
F_237 ( V_313 ) ;
V_336 = 1 ;
}
while ( 1 ) {
F_233 ( V_11 ) ;
F_238 ( V_11 ) ;
if ( ! F_163 ( V_335 , & V_11 -> V_334 ) )
break;
F_239 ( V_11 ) ;
}
}
F_75 ( & V_11 -> V_338 ) ;
if ( F_240 ( V_339 , & V_11 -> V_334 ) ) {
F_241 ( V_335 , & V_11 -> V_334 ) ;
F_78 ( & V_11 -> V_338 ) ;
F_242 ( V_11 , V_340 ) ;
F_243 ( & V_31 -> V_341 ,
- V_11 -> V_20 ,
V_31 -> V_342 ) ;
V_36 = 1 ;
} else {
F_78 ( & V_11 -> V_338 ) ;
}
F_239 ( V_11 ) ;
if ( ! V_36 )
return V_36 ;
V_201 = F_151 ( V_11 -> V_15 , V_11 -> V_20 ) ;
for ( V_152 = 0 ; V_152 < V_201 ; V_152 ++ ) {
struct V_130 * V_68 = V_11 -> V_151 [ V_152 ] ;
if ( ! F_244 ( V_68 ) ) {
if ( ! V_336 ) {
F_237 ( V_313 ) ;
V_336 = 1 ;
}
F_123 ( V_68 ) ;
}
}
return V_36 ;
}
static void F_245 ( struct V_10 * V_11 )
{
F_246 ( V_335 , & V_11 -> V_334 ) ;
F_247 () ;
F_248 ( & V_11 -> V_334 , V_335 ) ;
}
static void F_249 ( struct V_130 * V_130 )
{
struct V_10 * V_11 = (struct V_10 * ) V_130 -> V_204 ;
F_120 ( V_130 ) ;
if ( F_250 ( V_343 , & V_11 -> V_334 ) )
return;
switch ( V_11 -> V_344 ) {
case - 1 :
F_241 ( V_345 , & V_11 -> V_31 -> V_7 ) ;
break;
case 0 :
F_241 ( V_346 , & V_11 -> V_31 -> V_7 ) ;
break;
case 1 :
F_241 ( V_347 , & V_11 -> V_31 -> V_7 ) ;
break;
default:
F_251 () ;
}
}
static void F_252 ( struct V_48 * V_48 )
{
struct V_242 * V_243 ;
struct V_10 * V_11 ;
int V_152 , V_320 ;
F_175 (bvec, bio, i) {
struct V_130 * V_130 = V_243 -> V_244 ;
V_11 = (struct V_10 * ) V_130 -> V_204 ;
F_23 ( ! V_11 ) ;
V_320 = F_253 ( & V_11 -> V_348 ) ;
if ( V_48 -> V_247 ||
F_163 ( V_343 , & V_11 -> V_334 ) ) {
F_173 ( V_130 ) ;
F_249 ( V_130 ) ;
}
F_121 ( V_130 ) ;
if ( ! V_320 )
continue;
F_245 ( V_11 ) ;
}
F_143 ( V_48 ) ;
}
static T_13 int F_254 ( struct V_10 * V_11 ,
struct V_40 * V_31 ,
struct V_273 * V_274 ,
struct V_312 * V_313 )
{
struct V_259 * V_193 = V_31 -> V_227 -> V_228 ;
struct V_23 * V_24 = & F_19 ( V_31 -> V_203 ) -> V_159 ;
T_1 V_64 = V_11 -> V_15 ;
T_14 V_349 ;
unsigned long V_152 , V_201 ;
unsigned long V_215 = 0 ;
unsigned long V_15 , V_16 ;
int V_322 = ( V_313 -> V_337 ? V_198 : 0 ) | V_350 ;
int V_36 = 0 ;
F_246 ( V_343 , & V_11 -> V_334 ) ;
V_201 = F_151 ( V_11 -> V_15 , V_11 -> V_20 ) ;
F_255 ( & V_11 -> V_348 , V_201 ) ;
if ( F_256 ( V_11 ) == V_351 )
V_215 = V_352 ;
V_349 = F_257 ( V_11 ) ;
if ( F_258 ( V_11 ) > 0 ) {
V_16 = F_259 ( V_349 ) ;
F_260 ( V_11 , V_16 , V_11 -> V_20 - V_16 ) ;
} else {
V_15 = F_261 ( V_349 ) ;
V_16 = F_262 ( V_11 ) + F_263 ( V_31 , V_11 ) ;
F_260 ( V_11 , V_15 , V_16 - V_15 ) ;
}
for ( V_152 = 0 ; V_152 < V_201 ; V_152 ++ ) {
struct V_130 * V_68 = V_11 -> V_151 [ V_152 ] ;
F_100 ( V_68 ) ;
F_106 ( V_68 ) ;
V_36 = F_192 ( V_197 , V_322 , V_24 , V_274 ,
V_68 , V_64 >> 9 , V_29 , 0 , V_193 ,
& V_313 -> V_48 ,
F_252 ,
0 , V_313 -> V_215 , V_215 , false ) ;
V_313 -> V_215 = V_215 ;
if ( V_36 ) {
F_249 ( V_68 ) ;
if ( F_228 ( V_68 ) )
F_121 ( V_68 ) ;
if ( F_264 ( V_201 - V_152 , & V_11 -> V_348 ) )
F_245 ( V_11 ) ;
V_36 = - V_154 ;
break;
}
V_64 += V_29 ;
F_223 ( V_274 , 1 ) ;
F_122 ( V_68 ) ;
}
if ( F_183 ( V_36 ) ) {
for (; V_152 < V_201 ; V_152 ++ ) {
struct V_130 * V_68 = V_11 -> V_151 [ V_152 ] ;
F_100 ( V_68 ) ;
F_122 ( V_68 ) ;
}
}
return V_36 ;
}
int F_265 ( struct V_51 * V_27 ,
struct V_273 * V_274 )
{
struct V_23 * V_24 = & F_19 ( V_27 -> V_28 ) -> V_159 ;
struct V_40 * V_31 = F_19 ( V_27 -> V_28 ) -> V_30 -> V_31 ;
struct V_10 * V_11 , * V_353 = NULL ;
struct V_312 V_313 = {
. V_48 = NULL ,
. V_24 = V_24 ,
. V_317 = 0 ,
. V_337 = V_274 -> V_329 == V_330 ,
. V_215 = 0 ,
} ;
int V_36 = 0 ;
int V_320 = 0 ;
int V_354 = 0 ;
struct V_355 V_356 ;
int V_149 ;
T_6 V_127 ;
T_6 V_16 ;
int V_357 = 0 ;
int V_358 ;
F_266 ( & V_356 , 0 ) ;
if ( V_274 -> V_359 ) {
V_127 = V_27 -> V_360 ;
V_16 = - 1 ;
} else {
V_127 = V_274 -> V_361 >> V_128 ;
V_16 = V_274 -> V_362 >> V_128 ;
V_357 = 1 ;
}
if ( V_274 -> V_329 == V_330 )
V_358 = V_363 ;
else
V_358 = V_364 ;
V_365:
if ( V_274 -> V_329 == V_330 )
F_267 ( V_27 , V_127 , V_16 ) ;
while ( ! V_320 && ! V_354 && ( V_127 <= V_16 ) &&
( V_149 = F_268 ( & V_356 , V_27 , & V_127 , V_358 ,
F_127 ( V_16 - V_127 , ( T_6 ) V_366 - 1 ) + 1 ) ) ) {
unsigned V_152 ;
V_357 = 1 ;
for ( V_152 = 0 ; V_152 < V_149 ; V_152 ++ ) {
struct V_130 * V_130 = V_356 . V_151 [ V_152 ] ;
if ( ! F_197 ( V_130 ) )
continue;
if ( ! V_274 -> V_359 && V_130 -> V_127 > V_16 ) {
V_320 = 1 ;
break;
}
F_75 ( & V_27 -> V_367 ) ;
if ( ! F_197 ( V_130 ) ) {
F_78 ( & V_27 -> V_367 ) ;
continue;
}
V_11 = (struct V_10 * ) V_130 -> V_204 ;
if ( F_45 ( ! V_11 ) ) {
F_78 ( & V_27 -> V_367 ) ;
continue;
}
if ( V_11 == V_353 ) {
F_78 ( & V_27 -> V_367 ) ;
continue;
}
V_36 = F_269 ( & V_11 -> V_17 ) ;
F_78 ( & V_27 -> V_367 ) ;
if ( ! V_36 )
continue;
V_353 = V_11 ;
V_36 = F_235 ( V_11 , V_31 , & V_313 ) ;
if ( ! V_36 ) {
F_270 ( V_11 ) ;
continue;
}
V_36 = F_254 ( V_11 , V_31 , V_274 , & V_313 ) ;
if ( V_36 ) {
V_320 = 1 ;
F_270 ( V_11 ) ;
break;
}
F_270 ( V_11 ) ;
V_354 = V_274 -> V_311 <= 0 ;
}
F_271 ( & V_356 ) ;
F_79 () ;
}
if ( ! V_357 && ! V_320 ) {
V_357 = 1 ;
V_127 = 0 ;
goto V_365;
}
F_237 ( & V_313 ) ;
return V_36 ;
}
static int F_272 ( struct V_51 * V_27 ,
struct V_273 * V_274 ,
T_15 V_368 , void * V_224 ,
void (* F_273)( void * ) )
{
struct V_25 * V_25 = V_27 -> V_28 ;
int V_36 = 0 ;
int V_320 = 0 ;
int V_354 = 0 ;
struct V_355 V_356 ;
int V_149 ;
T_6 V_127 ;
T_6 V_16 ;
T_6 V_369 ;
int V_370 = 0 ;
int V_357 = 0 ;
int V_358 ;
if ( ! F_274 ( V_25 ) )
return 0 ;
F_266 ( & V_356 , 0 ) ;
if ( V_274 -> V_359 ) {
V_127 = V_27 -> V_360 ;
V_16 = - 1 ;
} else {
V_127 = V_274 -> V_361 >> V_128 ;
V_16 = V_274 -> V_362 >> V_128 ;
if ( V_274 -> V_361 == 0 && V_274 -> V_362 == V_371 )
V_370 = 1 ;
V_357 = 1 ;
}
if ( V_274 -> V_329 == V_330 )
V_358 = V_363 ;
else
V_358 = V_364 ;
V_365:
if ( V_274 -> V_329 == V_330 )
F_267 ( V_27 , V_127 , V_16 ) ;
V_369 = V_127 ;
while ( ! V_320 && ! V_354 && ( V_127 <= V_16 ) &&
( V_149 = F_268 ( & V_356 , V_27 , & V_127 , V_358 ,
F_127 ( V_16 - V_127 , ( T_6 ) V_366 - 1 ) + 1 ) ) ) {
unsigned V_152 ;
V_357 = 1 ;
for ( V_152 = 0 ; V_152 < V_149 ; V_152 ++ ) {
struct V_130 * V_130 = V_356 . V_151 [ V_152 ] ;
V_369 = V_130 -> V_127 ;
if ( ! F_244 ( V_130 ) ) {
F_273 ( V_224 ) ;
F_123 ( V_130 ) ;
}
if ( F_183 ( V_130 -> V_27 != V_27 ) ) {
F_122 ( V_130 ) ;
continue;
}
if ( ! V_274 -> V_359 && V_130 -> V_127 > V_16 ) {
V_320 = 1 ;
F_122 ( V_130 ) ;
continue;
}
if ( V_274 -> V_329 != V_372 ) {
if ( F_228 ( V_130 ) )
F_273 ( V_224 ) ;
F_275 ( V_130 ) ;
}
if ( F_228 ( V_130 ) ||
! F_100 ( V_130 ) ) {
F_122 ( V_130 ) ;
continue;
}
V_36 = (* V_368)( V_130 , V_274 , V_224 ) ;
if ( F_183 ( V_36 == V_373 ) ) {
F_122 ( V_130 ) ;
V_36 = 0 ;
}
if ( V_36 < 0 ) {
V_369 = V_130 -> V_127 + 1 ;
V_320 = 1 ;
break;
}
V_354 = V_274 -> V_311 <= 0 ;
}
F_271 ( & V_356 ) ;
F_79 () ;
}
if ( ! V_357 && ! V_320 ) {
V_357 = 1 ;
V_127 = 0 ;
goto V_365;
}
if ( V_274 -> V_359 || ( V_274 -> V_311 > 0 && V_370 ) )
V_27 -> V_360 = V_369 ;
F_276 ( V_25 ) ;
return V_36 ;
}
static void F_277 ( struct V_312 * V_313 )
{
if ( V_313 -> V_48 ) {
int V_36 ;
F_171 ( V_313 -> V_48 , V_197 ,
V_313 -> V_337 ? V_198 : 0 ) ;
V_36 = F_188 ( V_313 -> V_48 , 0 , V_313 -> V_215 ) ;
F_23 ( V_36 < 0 ) ;
V_313 -> V_48 = NULL ;
}
}
static T_5 void F_237 ( void * V_224 )
{
struct V_312 * V_313 = V_224 ;
F_277 ( V_313 ) ;
}
int F_278 ( struct V_23 * V_24 , struct V_130 * V_130 ,
T_12 * V_284 ,
struct V_273 * V_274 )
{
int V_36 ;
struct V_312 V_313 = {
. V_48 = NULL ,
. V_24 = V_24 ,
. V_284 = V_284 ,
. V_317 = 0 ,
. V_337 = V_274 -> V_329 == V_330 ,
. V_215 = 0 ,
} ;
V_36 = F_229 ( V_130 , V_274 , & V_313 ) ;
F_277 ( & V_313 ) ;
return V_36 ;
}
int F_279 ( struct V_23 * V_24 , struct V_25 * V_25 ,
T_1 V_15 , T_1 V_16 , T_12 * V_284 ,
int V_374 )
{
int V_36 = 0 ;
struct V_51 * V_27 = V_25 -> V_131 ;
struct V_130 * V_130 ;
unsigned long V_149 = ( V_16 - V_15 + V_29 ) >>
V_128 ;
struct V_312 V_313 = {
. V_48 = NULL ,
. V_24 = V_24 ,
. V_284 = V_284 ,
. V_317 = 1 ,
. V_337 = V_374 == V_330 ,
. V_215 = 0 ,
} ;
struct V_273 V_375 = {
. V_329 = V_374 ,
. V_311 = V_149 * 2 ,
. V_361 = V_15 ,
. V_362 = V_16 + 1 ,
} ;
while ( V_15 <= V_16 ) {
V_130 = F_99 ( V_27 , V_15 >> V_128 ) ;
if ( F_100 ( V_130 ) )
V_36 = F_229 ( V_130 , & V_375 , & V_313 ) ;
else {
if ( V_24 -> V_53 && V_24 -> V_53 -> V_241 )
V_24 -> V_53 -> V_241 ( V_130 , V_15 ,
V_15 + V_29 - 1 ,
NULL , 1 ) ;
F_122 ( V_130 ) ;
}
F_101 ( V_130 ) ;
V_15 += V_29 ;
}
F_277 ( & V_313 ) ;
return V_36 ;
}
int F_280 ( struct V_23 * V_24 ,
struct V_51 * V_27 ,
T_12 * V_284 ,
struct V_273 * V_274 )
{
int V_36 = 0 ;
struct V_312 V_313 = {
. V_48 = NULL ,
. V_24 = V_24 ,
. V_284 = V_284 ,
. V_317 = 0 ,
. V_337 = V_274 -> V_329 == V_330 ,
. V_215 = 0 ,
} ;
V_36 = F_272 ( V_27 , V_274 , F_229 , & V_313 ,
F_237 ) ;
F_277 ( & V_313 ) ;
return V_36 ;
}
int F_281 ( struct V_23 * V_24 ,
struct V_51 * V_27 ,
struct V_4 * V_151 , unsigned V_149 ,
T_12 V_284 )
{
struct V_48 * V_48 = NULL ;
unsigned V_376 ;
unsigned long V_215 = 0 ;
struct V_130 * V_377 [ 16 ] ;
struct V_130 * V_130 ;
struct V_210 * V_285 = NULL ;
int V_293 = 0 ;
T_1 V_287 = ( T_1 ) - 1 ;
for ( V_376 = 0 ; V_376 < V_149 ; V_376 ++ ) {
V_130 = F_11 ( V_151 -> V_79 , struct V_130 , V_378 ) ;
F_282 ( & V_130 -> V_7 ) ;
F_8 ( & V_130 -> V_378 ) ;
if ( F_283 ( V_130 , V_27 ,
V_130 -> V_127 ,
F_284 ( V_27 ) ) ) {
F_101 ( V_130 ) ;
continue;
}
V_377 [ V_293 ++ ] = V_130 ;
if ( V_293 < F_285 ( V_377 ) )
continue;
F_220 ( V_24 , V_377 , V_293 , V_284 , & V_285 ,
& V_48 , 0 , & V_215 , & V_287 ) ;
V_293 = 0 ;
}
if ( V_293 )
F_220 ( V_24 , V_377 , V_293 , V_284 , & V_285 ,
& V_48 , 0 , & V_215 , & V_287 ) ;
if ( V_285 )
F_162 ( V_285 ) ;
F_23 ( ! F_10 ( V_151 ) ) ;
if ( V_48 )
return F_188 ( V_48 , 0 , V_215 ) ;
return 0 ;
}
int F_286 ( struct V_23 * V_24 ,
struct V_130 * V_130 , unsigned long V_64 )
{
struct V_1 * V_103 = NULL ;
T_1 V_15 = F_132 ( V_130 ) ;
T_1 V_16 = V_15 + V_29 - 1 ;
T_10 V_296 = V_130 -> V_27 -> V_28 -> V_41 -> V_297 ;
V_15 += F_213 ( V_64 , V_296 ) ;
if ( V_15 > V_16 )
return 0 ;
F_96 ( V_24 , V_15 , V_16 , & V_103 ) ;
F_275 ( V_130 ) ;
F_94 ( V_24 , V_15 , V_16 ,
V_126 | V_99 | V_107 |
V_379 ,
1 , 1 , & V_103 , V_125 ) ;
return 0 ;
}
static int F_287 ( struct V_212 * V_380 ,
struct V_23 * V_24 ,
struct V_130 * V_130 , T_3 V_56 )
{
T_1 V_15 = F_132 ( V_130 ) ;
T_1 V_16 = V_15 + V_29 - 1 ;
int V_36 = 1 ;
if ( F_114 ( V_24 , V_15 , V_16 ,
V_85 , 0 , NULL ) )
V_36 = 0 ;
else {
V_36 = F_94 ( V_24 , V_15 , V_16 ,
~ ( V_126 | V_381 ) ,
0 , 0 , NULL , V_56 ) ;
if ( V_36 < 0 )
V_36 = 0 ;
else
V_36 = 1 ;
}
return V_36 ;
}
int F_288 ( struct V_212 * V_380 ,
struct V_23 * V_24 , struct V_130 * V_130 ,
T_3 V_56 )
{
struct V_210 * V_211 ;
T_1 V_15 = F_132 ( V_130 ) ;
T_1 V_16 = V_15 + V_29 - 1 ;
if ( F_74 ( V_56 ) &&
V_130 -> V_27 -> V_28 -> V_256 > V_382 ) {
T_1 V_20 ;
while ( V_15 <= V_16 ) {
V_20 = V_16 - V_15 + 1 ;
F_289 ( & V_380 -> V_55 ) ;
V_211 = F_160 ( V_380 , V_15 , V_20 ) ;
if ( ! V_211 ) {
F_290 ( & V_380 -> V_55 ) ;
break;
}
if ( F_163 ( V_383 , & V_211 -> V_7 ) ||
V_211 -> V_15 != V_15 ) {
F_290 ( & V_380 -> V_55 ) ;
F_162 ( V_211 ) ;
break;
}
if ( ! F_114 ( V_24 , V_211 -> V_15 ,
F_204 ( V_211 ) - 1 ,
V_126 | V_384 ,
0 , NULL ) ) {
F_291 ( V_380 , V_211 ) ;
F_162 ( V_211 ) ;
}
V_15 = F_204 ( V_211 ) ;
F_290 ( & V_380 -> V_55 ) ;
F_162 ( V_211 ) ;
}
}
return F_287 ( V_380 , V_24 , V_130 , V_56 ) ;
}
static struct V_210 * F_292 ( struct V_25 * V_25 ,
T_1 V_64 ,
T_1 V_162 ,
T_12 * V_284 )
{
T_1 V_385 = F_293 ( V_25 ) ;
struct V_210 * V_211 ;
T_1 V_20 ;
if ( V_64 >= V_162 )
return NULL ;
while ( 1 ) {
V_20 = V_162 - V_64 ;
if ( V_20 == 0 )
break;
V_20 = F_213 ( V_20 , V_385 ) ;
V_211 = V_284 ( F_19 ( V_25 ) , NULL , 0 , V_64 , V_20 , 0 ) ;
if ( F_205 ( V_211 ) )
return V_211 ;
if ( ! F_163 ( V_386 , & V_211 -> V_7 ) &&
V_211 -> V_216 != V_303 ) {
return V_211 ;
}
V_64 = F_204 ( V_211 ) ;
F_162 ( V_211 ) ;
if ( V_64 >= V_162 )
break;
}
return NULL ;
}
static int F_294 ( struct V_387 * V_388 ,
struct V_389 * V_390 ,
T_1 V_64 , T_1 V_391 , T_1 V_20 , T_14 V_7 )
{
int V_36 = 0 ;
if ( ! V_390 -> V_104 )
goto V_392;
if ( V_390 -> V_64 + V_390 -> V_20 > V_64 ) {
F_45 ( 1 ) ;
return - V_393 ;
}
if ( V_390 -> V_64 + V_390 -> V_20 == V_64 &&
V_390 -> V_391 + V_390 -> V_20 == V_391 &&
( V_390 -> V_7 & ~ V_394 ) ==
( V_7 & ~ V_394 ) ) {
V_390 -> V_20 += V_20 ;
V_390 -> V_7 |= V_7 ;
goto V_395;
}
V_36 = F_295 ( V_388 , V_390 -> V_64 , V_390 -> V_391 ,
V_390 -> V_20 , V_390 -> V_7 ) ;
V_390 -> V_104 = false ;
if ( V_36 )
return V_36 ;
V_392:
V_390 -> V_104 = true ;
V_390 -> V_64 = V_64 ;
V_390 -> V_391 = V_391 ;
V_390 -> V_20 = V_20 ;
V_390 -> V_7 = V_7 ;
V_395:
if ( V_390 -> V_7 & V_394 ) {
V_36 = F_295 ( V_388 , V_390 -> V_64 ,
V_390 -> V_391 , V_390 -> V_20 , V_390 -> V_7 ) ;
V_390 -> V_104 = false ;
}
return V_36 ;
}
static int F_296 ( struct V_40 * V_31 ,
struct V_387 * V_388 ,
struct V_389 * V_390 )
{
int V_36 ;
if ( ! V_390 -> V_104 )
return 0 ;
#ifdef F_297
F_45 ( 1 ) ;
#endif
F_298 ( V_31 ,
L_22 ,
V_390 -> V_64 , V_390 -> V_391 , V_390 -> V_20 , V_390 -> V_7 ) ;
V_36 = F_295 ( V_388 , V_390 -> V_64 , V_390 -> V_391 ,
V_390 -> V_20 , V_390 -> V_7 ) ;
V_390 -> V_104 = false ;
if ( V_36 > 0 )
V_36 = 0 ;
return V_36 ;
}
int F_299 ( struct V_25 * V_25 , struct V_387 * V_388 ,
T_16 V_15 , T_16 V_20 , T_12 * V_284 )
{
int V_36 = 0 ;
T_1 V_257 = V_15 ;
T_1 F_128 = V_15 + V_20 ;
T_14 V_7 = 0 ;
T_14 V_396 ;
T_1 V_162 ;
T_1 V_397 = 0 ;
T_1 V_398 = 0 ;
T_1 V_26 = F_17 ( V_25 ) ;
struct V_399 V_400 ;
struct V_210 * V_211 = NULL ;
struct V_1 * V_103 = NULL ;
struct V_401 * V_402 ;
struct V_403 * V_30 = F_19 ( V_25 ) -> V_30 ;
struct V_389 V_390 = { 0 } ;
int V_16 = 0 ;
T_1 V_404 = 0 ;
T_1 V_405 = 0 ;
T_1 V_328 = 0 ;
if ( V_20 == 0 )
return - V_393 ;
V_402 = F_300 () ;
if ( ! V_402 )
return - V_43 ;
V_402 -> V_406 = 1 ;
V_15 = F_301 ( V_15 , F_293 ( V_25 ) ) ;
V_20 = F_302 ( F_128 , F_293 ( V_25 ) ) - V_15 ;
V_36 = F_303 ( NULL , V_30 , V_402 ,
F_20 ( F_19 ( V_25 ) ) , - 1 , 0 ) ;
if ( V_36 < 0 ) {
F_304 ( V_402 ) ;
return V_36 ;
} else {
F_45 ( ! V_36 ) ;
if ( V_36 == 1 )
V_36 = 0 ;
}
V_402 -> V_407 [ 0 ] -- ;
F_305 ( V_402 -> V_408 [ 0 ] , & V_400 , V_402 -> V_407 [ 0 ] ) ;
V_396 = V_400 . type ;
if ( V_400 . V_409 != F_20 ( F_19 ( V_25 ) ) ||
V_396 != V_410 ) {
V_162 = ( T_1 ) - 1 ;
V_397 = V_26 ;
} else {
V_162 = V_400 . V_64 ;
V_397 = V_162 + 1 ;
}
F_306 ( V_402 ) ;
if ( V_162 < V_26 ) {
V_162 = ( T_1 ) - 1 ;
V_397 = V_26 ;
}
F_96 ( & F_19 ( V_25 ) -> V_159 , V_15 , V_15 + V_20 - 1 ,
& V_103 ) ;
V_211 = F_292 ( V_25 , V_15 , V_397 ,
V_284 ) ;
if ( ! V_211 )
goto V_112;
if ( F_307 ( V_211 ) ) {
V_36 = F_308 ( V_211 ) ;
goto V_112;
}
while ( ! V_16 ) {
T_1 V_411 = 0 ;
if ( V_211 -> V_15 >= F_128 || F_204 ( V_211 ) < V_257 )
break;
V_404 = F_128 ( V_211 -> V_15 , V_257 ) ;
if ( ! F_163 ( V_217 , & V_211 -> V_7 ) )
V_411 = V_404 - V_211 -> V_15 ;
V_328 = F_204 ( V_211 ) ;
V_405 = V_328 - V_404 ;
V_398 = 0 ;
V_7 = 0 ;
V_257 = F_204 ( V_211 ) ;
if ( V_257 >= F_128 )
V_16 = 1 ;
if ( V_211 -> V_216 == V_412 ) {
V_16 = 1 ;
V_7 |= V_394 ;
} else if ( V_211 -> V_216 == V_305 ) {
V_7 |= ( V_413 |
V_414 ) ;
} else if ( V_211 -> V_216 == V_415 ) {
V_7 |= ( V_416 |
V_417 ) ;
} else if ( V_388 -> V_418 ) {
struct V_419 * V_420 ;
T_1 V_421 = V_211 -> V_216 -
( V_211 -> V_15 - V_211 -> V_304 ) ;
V_398 = V_211 -> V_216 + V_411 ;
V_420 = F_309 ( V_30 ) ;
if ( F_307 ( V_420 ) )
V_420 = NULL ;
V_36 = F_310 ( V_420 , V_30 -> V_31 ,
V_30 -> V_409 ,
F_20 ( F_19 ( V_25 ) ) , V_421 ) ;
if ( V_420 )
F_311 ( V_420 ) ;
if ( V_36 < 0 )
goto V_422;
if ( V_36 )
V_7 |= V_423 ;
V_36 = 0 ;
}
if ( F_163 ( V_217 , & V_211 -> V_7 ) )
V_7 |= V_424 ;
if ( F_163 ( V_302 , & V_211 -> V_7 ) )
V_7 |= V_425 ;
F_162 ( V_211 ) ;
V_211 = NULL ;
if ( ( V_404 >= V_162 ) || V_405 == ( T_1 ) - 1 ||
( V_162 == ( T_1 ) - 1 && V_26 <= V_328 ) ) {
V_7 |= V_394 ;
V_16 = 1 ;
}
V_211 = F_292 ( V_25 , V_257 , V_397 ,
V_284 ) ;
if ( F_307 ( V_211 ) ) {
V_36 = F_308 ( V_211 ) ;
goto V_112;
}
if ( ! V_211 ) {
V_7 |= V_394 ;
V_16 = 1 ;
}
V_36 = F_294 ( V_388 , & V_390 , V_404 , V_398 ,
V_405 , V_7 ) ;
if ( V_36 ) {
if ( V_36 == 1 )
V_36 = 0 ;
goto V_422;
}
}
V_422:
if ( ! V_36 )
V_36 = F_296 ( V_30 -> V_31 , V_388 , & V_390 ) ;
F_162 ( V_211 ) ;
V_112:
F_304 ( V_402 ) ;
F_115 ( & F_19 ( V_25 ) -> V_159 , V_15 , V_15 + V_20 - 1 ,
& V_103 , V_125 ) ;
return V_36 ;
}
static void F_312 ( struct V_10 * V_11 )
{
F_7 ( & V_11 -> V_14 ) ;
F_14 ( V_21 , V_11 ) ;
}
int F_313 ( struct V_10 * V_11 )
{
return ( F_15 ( & V_11 -> V_348 ) ||
F_163 ( V_335 , & V_11 -> V_334 ) ||
F_163 ( V_339 , & V_11 -> V_334 ) ) ;
}
static void F_314 ( struct V_10 * V_11 )
{
unsigned long V_127 ;
struct V_130 * V_130 ;
int V_426 = ! F_163 ( V_427 , & V_11 -> V_334 ) ;
F_23 ( F_313 ( V_11 ) ) ;
V_127 = F_151 ( V_11 -> V_15 , V_11 -> V_20 ) ;
if ( V_127 == 0 )
return;
do {
V_127 -- ;
V_130 = V_11 -> V_151 [ V_127 ] ;
if ( ! V_130 )
continue;
if ( V_426 )
F_75 ( & V_130 -> V_27 -> V_367 ) ;
if ( F_197 ( V_130 ) &&
V_130 -> V_204 == ( unsigned long ) V_11 ) {
F_23 ( F_163 ( V_339 , & V_11 -> V_334 ) ) ;
F_23 ( F_124 ( V_130 ) ) ;
F_23 ( F_228 ( V_130 ) ) ;
F_315 ( V_130 ) ;
F_200 ( V_130 , 0 ) ;
F_101 ( V_130 ) ;
}
if ( V_426 )
F_78 ( & V_130 -> V_27 -> V_367 ) ;
F_101 ( V_130 ) ;
} while ( V_127 != 0 );
}
static inline void F_316 ( struct V_10 * V_11 )
{
F_314 ( V_11 ) ;
F_312 ( V_11 ) ;
}
static struct V_10 *
F_317 ( struct V_40 * V_31 , T_1 V_15 ,
unsigned long V_20 )
{
struct V_10 * V_11 = NULL ;
V_11 = F_318 ( V_21 , V_125 | V_428 ) ;
V_11 -> V_15 = V_15 ;
V_11 -> V_20 = V_20 ;
V_11 -> V_31 = V_31 ;
V_11 -> V_334 = 0 ;
F_319 ( & V_11 -> V_55 ) ;
F_255 ( & V_11 -> V_429 , 0 ) ;
F_255 ( & V_11 -> V_430 , 0 ) ;
F_255 ( & V_11 -> V_431 , 0 ) ;
F_255 ( & V_11 -> V_432 , 0 ) ;
F_255 ( & V_11 -> V_433 , 0 ) ;
F_255 ( & V_11 -> V_434 , 0 ) ;
V_11 -> V_435 = 0 ;
F_41 ( & V_11 -> V_436 ) ;
F_41 ( & V_11 -> V_437 ) ;
F_3 ( & V_11 -> V_14 , & V_19 ) ;
F_36 ( & V_11 -> V_338 ) ;
F_255 ( & V_11 -> V_17 , 1 ) ;
F_255 ( & V_11 -> V_348 , 0 ) ;
F_320 ( V_438
> V_439 ) ;
F_23 ( V_20 > V_439 ) ;
return V_11 ;
}
struct V_10 * F_321 ( struct V_10 * V_440 )
{
unsigned long V_152 ;
struct V_130 * V_68 ;
struct V_10 * V_5 ;
unsigned long V_201 = F_151 ( V_440 -> V_15 , V_440 -> V_20 ) ;
V_5 = F_317 ( V_440 -> V_31 , V_440 -> V_15 , V_440 -> V_20 ) ;
if ( V_5 == NULL )
return NULL ;
for ( V_152 = 0 ; V_152 < V_201 ; V_152 ++ ) {
V_68 = F_322 ( V_125 ) ;
if ( ! V_68 ) {
F_316 ( V_5 ) ;
return NULL ;
}
F_196 ( V_5 , V_68 ) ;
F_45 ( F_124 ( V_68 ) ) ;
F_133 ( V_68 ) ;
V_5 -> V_151 [ V_152 ] = V_68 ;
F_323 ( F_324 ( V_68 ) , F_324 ( V_440 -> V_151 [ V_152 ] ) ) ;
}
F_241 ( V_441 , & V_5 -> V_334 ) ;
F_241 ( V_427 , & V_5 -> V_334 ) ;
return V_5 ;
}
struct V_10 * F_325 ( struct V_40 * V_31 ,
T_1 V_15 , unsigned long V_20 )
{
struct V_10 * V_11 ;
unsigned long V_201 ;
unsigned long V_152 ;
V_201 = F_151 ( V_15 , V_20 ) ;
V_11 = F_317 ( V_31 , V_15 , V_20 ) ;
if ( ! V_11 )
return NULL ;
for ( V_152 = 0 ; V_152 < V_201 ; V_152 ++ ) {
V_11 -> V_151 [ V_152 ] = F_322 ( V_125 ) ;
if ( ! V_11 -> V_151 [ V_152 ] )
goto V_101;
}
F_326 ( V_11 ) ;
F_327 ( V_11 , 0 ) ;
F_241 ( V_427 , & V_11 -> V_334 ) ;
return V_11 ;
V_101:
for (; V_152 > 0 ; V_152 -- )
F_328 ( V_11 -> V_151 [ V_152 - 1 ] ) ;
F_312 ( V_11 ) ;
return NULL ;
}
struct V_10 * F_329 ( struct V_40 * V_31 ,
T_1 V_15 )
{
return F_325 ( V_31 , V_15 , V_31 -> V_442 ) ;
}
static void F_330 ( struct V_10 * V_11 )
{
int V_17 ;
V_17 = F_15 ( & V_11 -> V_17 ) ;
if ( V_17 >= 2 && F_163 ( V_443 , & V_11 -> V_334 ) )
return;
F_75 ( & V_11 -> V_338 ) ;
if ( ! F_250 ( V_443 , & V_11 -> V_334 ) )
F_331 ( & V_11 -> V_17 ) ;
F_78 ( & V_11 -> V_338 ) ;
}
static void F_332 ( struct V_10 * V_11 ,
struct V_130 * V_444 )
{
unsigned long V_201 , V_152 ;
F_330 ( V_11 ) ;
V_201 = F_151 ( V_11 -> V_15 , V_11 -> V_20 ) ;
for ( V_152 = 0 ; V_152 < V_201 ; V_152 ++ ) {
struct V_130 * V_68 = V_11 -> V_151 [ V_152 ] ;
if ( V_68 != V_444 )
F_333 ( V_68 ) ;
}
}
struct V_10 * F_334 ( struct V_40 * V_31 ,
T_1 V_15 )
{
struct V_10 * V_11 ;
F_335 () ;
V_11 = F_336 ( & V_31 -> V_445 ,
V_15 >> V_128 ) ;
if ( V_11 && F_269 ( & V_11 -> V_17 ) ) {
F_337 () ;
if ( F_163 ( V_446 , & V_11 -> V_334 ) ) {
F_75 ( & V_11 -> V_338 ) ;
F_78 ( & V_11 -> V_338 ) ;
}
F_332 ( V_11 , NULL ) ;
return V_11 ;
}
F_337 () ;
return NULL ;
}
struct V_10 * F_338 ( struct V_40 * V_31 ,
T_1 V_15 )
{
struct V_10 * V_11 , * V_447 = NULL ;
int V_36 ;
V_11 = F_334 ( V_31 , V_15 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_329 ( V_31 , V_15 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_31 = V_31 ;
V_110:
V_36 = F_339 ( V_125 ) ;
if ( V_36 )
goto V_448;
F_75 ( & V_31 -> V_449 ) ;
V_36 = F_340 ( & V_31 -> V_445 ,
V_15 >> V_128 , V_11 ) ;
F_78 ( & V_31 -> V_449 ) ;
F_341 () ;
if ( V_36 == - V_91 ) {
V_447 = F_334 ( V_31 , V_15 ) ;
if ( V_447 )
goto V_448;
else
goto V_110;
}
F_330 ( V_11 ) ;
F_241 ( V_450 , & V_11 -> V_334 ) ;
F_331 ( & V_11 -> V_17 ) ;
return V_11 ;
V_448:
F_316 ( V_11 ) ;
return V_447 ;
}
struct V_10 * F_342 ( struct V_40 * V_31 ,
T_1 V_15 )
{
unsigned long V_20 = V_31 -> V_442 ;
unsigned long V_201 = F_151 ( V_15 , V_20 ) ;
unsigned long V_152 ;
unsigned long V_127 = V_15 >> V_128 ;
struct V_10 * V_11 ;
struct V_10 * V_447 = NULL ;
struct V_130 * V_68 ;
struct V_51 * V_27 = V_31 -> V_203 -> V_131 ;
int V_240 = 1 ;
int V_36 ;
if ( ! F_343 ( V_15 , V_31 -> V_385 ) ) {
F_176 ( V_31 , L_23 , V_15 ) ;
return F_344 ( - V_393 ) ;
}
V_11 = F_334 ( V_31 , V_15 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_317 ( V_31 , V_15 , V_20 ) ;
if ( ! V_11 )
return F_344 ( - V_43 ) ;
for ( V_152 = 0 ; V_152 < V_201 ; V_152 ++ , V_127 ++ ) {
V_68 = F_345 ( V_27 , V_127 , V_125 | V_428 ) ;
if ( ! V_68 ) {
V_447 = F_344 ( - V_43 ) ;
goto V_448;
}
F_75 ( & V_27 -> V_367 ) ;
if ( F_197 ( V_68 ) ) {
V_447 = (struct V_10 * ) V_68 -> V_204 ;
if ( F_269 ( & V_447 -> V_17 ) ) {
F_78 ( & V_27 -> V_367 ) ;
F_122 ( V_68 ) ;
F_101 ( V_68 ) ;
F_332 ( V_447 , V_68 ) ;
goto V_448;
}
V_447 = NULL ;
F_315 ( V_68 ) ;
F_45 ( F_124 ( V_68 ) ) ;
F_101 ( V_68 ) ;
}
F_196 ( V_11 , V_68 ) ;
F_78 ( & V_27 -> V_367 ) ;
F_45 ( F_124 ( V_68 ) ) ;
V_11 -> V_151 [ V_152 ] = V_68 ;
if ( ! F_207 ( V_68 ) )
V_240 = 0 ;
}
if ( V_240 )
F_241 ( V_441 , & V_11 -> V_334 ) ;
V_110:
V_36 = F_339 ( V_125 ) ;
if ( V_36 ) {
V_447 = F_344 ( V_36 ) ;
goto V_448;
}
F_75 ( & V_31 -> V_449 ) ;
V_36 = F_340 ( & V_31 -> V_445 ,
V_15 >> V_128 , V_11 ) ;
F_78 ( & V_31 -> V_449 ) ;
F_341 () ;
if ( V_36 == - V_91 ) {
V_447 = F_334 ( V_31 , V_15 ) ;
if ( V_447 )
goto V_448;
else
goto V_110;
}
F_330 ( V_11 ) ;
F_241 ( V_450 , & V_11 -> V_334 ) ;
F_346 ( V_11 -> V_151 [ 0 ] ) ;
for ( V_152 = 1 ; V_152 < V_201 ; V_152 ++ ) {
V_68 = V_11 -> V_151 [ V_152 ] ;
F_347 ( V_68 ) ;
F_122 ( V_68 ) ;
}
F_122 ( V_11 -> V_151 [ 0 ] ) ;
return V_11 ;
V_448:
F_45 ( ! F_253 ( & V_11 -> V_17 ) ) ;
for ( V_152 = 0 ; V_152 < V_201 ; V_152 ++ ) {
if ( V_11 -> V_151 [ V_152 ] )
F_122 ( V_11 -> V_151 [ V_152 ] ) ;
}
F_316 ( V_11 ) ;
return V_447 ;
}
static inline void F_348 ( struct V_451 * V_6 )
{
struct V_10 * V_11 =
F_349 ( V_6 , struct V_10 , V_451 ) ;
F_312 ( V_11 ) ;
}
static int F_350 ( struct V_10 * V_11 )
{
F_45 ( F_15 ( & V_11 -> V_17 ) == 0 ) ;
if ( F_253 ( & V_11 -> V_17 ) ) {
if ( F_240 ( V_450 , & V_11 -> V_334 ) ) {
struct V_40 * V_31 = V_11 -> V_31 ;
F_78 ( & V_11 -> V_338 ) ;
F_75 ( & V_31 -> V_449 ) ;
F_351 ( & V_31 -> V_445 ,
V_11 -> V_15 >> V_128 ) ;
F_78 ( & V_31 -> V_449 ) ;
} else {
F_78 ( & V_11 -> V_338 ) ;
}
F_314 ( V_11 ) ;
#ifdef F_352
if ( F_183 ( F_163 ( V_427 , & V_11 -> V_334 ) ) ) {
F_312 ( V_11 ) ;
return 1 ;
}
#endif
F_353 ( & V_11 -> V_451 , F_348 ) ;
return 1 ;
}
F_78 ( & V_11 -> V_338 ) ;
return 0 ;
}
void F_270 ( struct V_10 * V_11 )
{
int V_17 ;
int V_452 ;
if ( ! V_11 )
return;
while ( 1 ) {
V_17 = F_15 ( & V_11 -> V_17 ) ;
if ( V_17 <= 3 )
break;
V_452 = F_354 ( & V_11 -> V_17 , V_17 , V_17 - 1 ) ;
if ( V_452 == V_17 )
return;
}
F_75 ( & V_11 -> V_338 ) ;
if ( F_15 ( & V_11 -> V_17 ) == 2 &&
F_163 ( V_427 , & V_11 -> V_334 ) )
F_355 ( & V_11 -> V_17 ) ;
if ( F_15 ( & V_11 -> V_17 ) == 2 &&
F_163 ( V_446 , & V_11 -> V_334 ) &&
! F_313 ( V_11 ) &&
F_240 ( V_443 , & V_11 -> V_334 ) )
F_355 ( & V_11 -> V_17 ) ;
F_350 ( V_11 ) ;
}
void F_356 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return;
F_75 ( & V_11 -> V_338 ) ;
F_241 ( V_446 , & V_11 -> V_334 ) ;
if ( F_15 ( & V_11 -> V_17 ) == 2 && ! F_313 ( V_11 ) &&
F_240 ( V_443 , & V_11 -> V_334 ) )
F_355 ( & V_11 -> V_17 ) ;
F_350 ( V_11 ) ;
}
void F_357 ( struct V_10 * V_11 )
{
unsigned long V_152 ;
unsigned long V_201 ;
struct V_130 * V_130 ;
V_201 = F_151 ( V_11 -> V_15 , V_11 -> V_20 ) ;
for ( V_152 = 0 ; V_152 < V_201 ; V_152 ++ ) {
V_130 = V_11 -> V_151 [ V_152 ] ;
if ( ! F_124 ( V_130 ) )
continue;
F_123 ( V_130 ) ;
F_45 ( ! F_197 ( V_130 ) ) ;
F_100 ( V_130 ) ;
F_358 ( & V_130 -> V_27 -> V_453 ) ;
if ( ! F_124 ( V_130 ) ) {
F_359 ( & V_130 -> V_27 -> V_454 ,
F_360 ( V_130 ) ,
V_364 ) ;
}
F_361 ( & V_130 -> V_27 -> V_453 ) ;
F_232 ( V_130 ) ;
F_122 ( V_130 ) ;
}
F_45 ( F_15 ( & V_11 -> V_17 ) == 0 ) ;
}
int F_362 ( struct V_10 * V_11 )
{
unsigned long V_152 ;
unsigned long V_201 ;
int V_455 = 0 ;
F_330 ( V_11 ) ;
V_455 = F_250 ( V_339 , & V_11 -> V_334 ) ;
V_201 = F_151 ( V_11 -> V_15 , V_11 -> V_20 ) ;
F_45 ( F_15 ( & V_11 -> V_17 ) == 0 ) ;
F_45 ( ! F_163 ( V_443 , & V_11 -> V_334 ) ) ;
for ( V_152 = 0 ; V_152 < V_201 ; V_152 ++ )
F_363 ( V_11 -> V_151 [ V_152 ] ) ;
return V_455 ;
}
void F_364 ( struct V_10 * V_11 )
{
unsigned long V_152 ;
struct V_130 * V_130 ;
unsigned long V_201 ;
F_246 ( V_441 , & V_11 -> V_334 ) ;
V_201 = F_151 ( V_11 -> V_15 , V_11 -> V_20 ) ;
for ( V_152 = 0 ; V_152 < V_201 ; V_152 ++ ) {
V_130 = V_11 -> V_151 [ V_152 ] ;
if ( V_130 )
F_173 ( V_130 ) ;
}
}
void F_326 ( struct V_10 * V_11 )
{
unsigned long V_152 ;
struct V_130 * V_130 ;
unsigned long V_201 ;
F_241 ( V_441 , & V_11 -> V_334 ) ;
V_201 = F_151 ( V_11 -> V_15 , V_11 -> V_20 ) ;
for ( V_152 = 0 ; V_152 < V_201 ; V_152 ++ ) {
V_130 = V_11 -> V_151 [ V_152 ] ;
F_133 ( V_130 ) ;
}
}
int F_365 ( struct V_10 * V_11 )
{
return F_163 ( V_441 , & V_11 -> V_334 ) ;
}
int F_366 ( struct V_23 * V_24 ,
struct V_10 * V_11 , int V_114 ,
T_12 * V_284 , int V_176 )
{
unsigned long V_152 ;
struct V_130 * V_130 ;
int V_101 ;
int V_36 = 0 ;
int V_456 = 0 ;
int V_457 = 1 ;
unsigned long V_201 ;
unsigned long V_458 = 0 ;
struct V_48 * V_48 = NULL ;
unsigned long V_215 = 0 ;
if ( F_163 ( V_441 , & V_11 -> V_334 ) )
return 0 ;
V_201 = F_151 ( V_11 -> V_15 , V_11 -> V_20 ) ;
for ( V_152 = 0 ; V_152 < V_201 ; V_152 ++ ) {
V_130 = V_11 -> V_151 [ V_152 ] ;
if ( V_114 == V_459 ) {
if ( ! F_244 ( V_130 ) )
goto V_460;
} else {
F_123 ( V_130 ) ;
}
V_456 ++ ;
}
for ( V_152 = 0 ; V_152 < V_201 ; V_152 ++ ) {
V_130 = V_11 -> V_151 [ V_152 ] ;
if ( ! F_207 ( V_130 ) ) {
V_458 ++ ;
V_457 = 0 ;
}
}
if ( V_457 ) {
F_241 ( V_441 , & V_11 -> V_334 ) ;
goto V_460;
}
F_246 ( V_461 , & V_11 -> V_334 ) ;
V_11 -> V_462 = 0 ;
F_255 ( & V_11 -> V_348 , V_458 ) ;
for ( V_152 = 0 ; V_152 < V_201 ; V_152 ++ ) {
V_130 = V_11 -> V_151 [ V_152 ] ;
if ( ! F_207 ( V_130 ) ) {
if ( V_36 ) {
F_355 ( & V_11 -> V_348 ) ;
F_122 ( V_130 ) ;
continue;
}
F_232 ( V_130 ) ;
V_101 = F_221 ( V_24 , V_130 ,
V_284 , & V_48 ,
V_176 , & V_215 ,
V_350 ) ;
if ( V_101 ) {
V_36 = V_101 ;
F_355 ( & V_11 -> V_348 ) ;
}
} else {
F_122 ( V_130 ) ;
}
}
if ( V_48 ) {
V_101 = F_188 ( V_48 , V_176 , V_215 ) ;
if ( V_101 )
return V_101 ;
}
if ( V_36 || V_114 != V_463 )
return V_36 ;
for ( V_152 = 0 ; V_152 < V_201 ; V_152 ++ ) {
V_130 = V_11 -> V_151 [ V_152 ] ;
F_367 ( V_130 ) ;
if ( ! F_207 ( V_130 ) )
V_36 = - V_154 ;
}
return V_36 ;
V_460:
while ( V_456 > 0 ) {
V_456 -- ;
V_130 = V_11 -> V_151 [ V_456 ] ;
F_122 ( V_130 ) ;
}
return V_36 ;
}
void F_368 ( struct V_10 * V_11 , void * V_464 ,
unsigned long V_15 ,
unsigned long V_20 )
{
T_10 V_289 ;
T_10 V_64 ;
struct V_130 * V_130 ;
char * V_465 ;
char * V_466 = ( char * ) V_464 ;
T_10 V_467 = V_11 -> V_15 & ( ( T_1 ) V_29 - 1 ) ;
unsigned long V_152 = ( V_467 + V_15 ) >> V_128 ;
F_45 ( V_15 > V_11 -> V_20 ) ;
F_45 ( V_15 + V_20 > V_11 -> V_15 + V_11 -> V_20 ) ;
V_64 = ( V_467 + V_15 ) & ( V_29 - 1 ) ;
while ( V_20 > 0 ) {
V_130 = V_11 -> V_151 [ V_152 ] ;
V_289 = F_127 ( V_20 , ( V_29 - V_64 ) ) ;
V_465 = F_324 ( V_130 ) ;
memcpy ( V_466 , V_465 + V_64 , V_289 ) ;
V_466 += V_289 ;
V_20 -= V_289 ;
V_64 = 0 ;
V_152 ++ ;
}
}
int F_369 ( struct V_10 * V_11 , void T_17 * V_464 ,
unsigned long V_15 ,
unsigned long V_20 )
{
T_10 V_289 ;
T_10 V_64 ;
struct V_130 * V_130 ;
char * V_465 ;
char T_17 * V_466 = ( char T_17 * ) V_464 ;
T_10 V_467 = V_11 -> V_15 & ( ( T_1 ) V_29 - 1 ) ;
unsigned long V_152 = ( V_467 + V_15 ) >> V_128 ;
int V_36 = 0 ;
F_45 ( V_15 > V_11 -> V_20 ) ;
F_45 ( V_15 + V_20 > V_11 -> V_15 + V_11 -> V_20 ) ;
V_64 = ( V_467 + V_15 ) & ( V_29 - 1 ) ;
while ( V_20 > 0 ) {
V_130 = V_11 -> V_151 [ V_152 ] ;
V_289 = F_127 ( V_20 , ( V_29 - V_64 ) ) ;
V_465 = F_324 ( V_130 ) ;
if ( F_370 ( V_466 , V_465 + V_64 , V_289 ) ) {
V_36 = - V_468 ;
break;
}
V_466 += V_289 ;
V_20 -= V_289 ;
V_64 = 0 ;
V_152 ++ ;
}
return V_36 ;
}
int F_371 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_469 , char * * V_380 ,
unsigned long * V_470 ,
unsigned long * V_471 )
{
T_10 V_64 = V_15 & ( V_29 - 1 ) ;
char * V_465 ;
struct V_130 * V_68 ;
T_10 V_467 = V_11 -> V_15 & ( ( T_1 ) V_29 - 1 ) ;
unsigned long V_152 = ( V_467 + V_15 ) >> V_128 ;
unsigned long V_472 = ( V_467 + V_15 + V_469 - 1 ) >>
V_128 ;
if ( V_152 != V_472 )
return 1 ;
if ( V_152 == 0 ) {
V_64 = V_467 ;
* V_470 = 0 ;
} else {
V_64 = 0 ;
* V_470 = ( ( T_1 ) V_152 << V_128 ) - V_467 ;
}
if ( V_15 + V_469 > V_11 -> V_20 ) {
F_62 ( 1 , V_89 L_24 ,
V_11 -> V_15 , V_11 -> V_20 , V_15 , V_469 ) ;
return - V_393 ;
}
V_68 = V_11 -> V_151 [ V_152 ] ;
V_465 = F_324 ( V_68 ) ;
* V_380 = V_465 + V_64 ;
* V_471 = V_29 - V_64 ;
return 0 ;
}
int F_372 ( struct V_10 * V_11 , const void * V_473 ,
unsigned long V_15 ,
unsigned long V_20 )
{
T_10 V_289 ;
T_10 V_64 ;
struct V_130 * V_130 ;
char * V_465 ;
char * V_474 = ( char * ) V_473 ;
T_10 V_467 = V_11 -> V_15 & ( ( T_1 ) V_29 - 1 ) ;
unsigned long V_152 = ( V_467 + V_15 ) >> V_128 ;
int V_36 = 0 ;
F_45 ( V_15 > V_11 -> V_20 ) ;
F_45 ( V_15 + V_20 > V_11 -> V_15 + V_11 -> V_20 ) ;
V_64 = ( V_467 + V_15 ) & ( V_29 - 1 ) ;
while ( V_20 > 0 ) {
V_130 = V_11 -> V_151 [ V_152 ] ;
V_289 = F_127 ( V_20 , ( V_29 - V_64 ) ) ;
V_465 = F_324 ( V_130 ) ;
V_36 = memcmp ( V_474 , V_465 + V_64 , V_289 ) ;
if ( V_36 )
break;
V_474 += V_289 ;
V_20 -= V_289 ;
V_64 = 0 ;
V_152 ++ ;
}
return V_36 ;
}
void F_373 ( struct V_10 * V_11 ,
const void * V_475 )
{
char * V_465 ;
F_45 ( ! F_207 ( V_11 -> V_151 [ 0 ] ) ) ;
V_465 = F_324 ( V_11 -> V_151 [ 0 ] ) ;
memcpy ( V_465 + F_29 ( struct V_476 , V_477 ) , V_475 ,
V_478 ) ;
}
void F_374 ( struct V_10 * V_11 , const void * V_475 )
{
char * V_465 ;
F_45 ( ! F_207 ( V_11 -> V_151 [ 0 ] ) ) ;
V_465 = F_324 ( V_11 -> V_151 [ 0 ] ) ;
memcpy ( V_465 + F_29 ( struct V_476 , V_479 ) , V_475 ,
V_478 ) ;
}
void F_375 ( struct V_10 * V_11 , const void * V_475 ,
unsigned long V_15 , unsigned long V_20 )
{
T_10 V_289 ;
T_10 V_64 ;
struct V_130 * V_130 ;
char * V_465 ;
char * V_440 = ( char * ) V_475 ;
T_10 V_467 = V_11 -> V_15 & ( ( T_1 ) V_29 - 1 ) ;
unsigned long V_152 = ( V_467 + V_15 ) >> V_128 ;
F_45 ( V_15 > V_11 -> V_20 ) ;
F_45 ( V_15 + V_20 > V_11 -> V_15 + V_11 -> V_20 ) ;
V_64 = ( V_467 + V_15 ) & ( V_29 - 1 ) ;
while ( V_20 > 0 ) {
V_130 = V_11 -> V_151 [ V_152 ] ;
F_45 ( ! F_207 ( V_130 ) ) ;
V_289 = F_127 ( V_20 , V_29 - V_64 ) ;
V_465 = F_324 ( V_130 ) ;
memcpy ( V_465 + V_64 , V_440 , V_289 ) ;
V_440 += V_289 ;
V_20 -= V_289 ;
V_64 = 0 ;
V_152 ++ ;
}
}
void F_260 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_20 )
{
T_10 V_289 ;
T_10 V_64 ;
struct V_130 * V_130 ;
char * V_465 ;
T_10 V_467 = V_11 -> V_15 & ( ( T_1 ) V_29 - 1 ) ;
unsigned long V_152 = ( V_467 + V_15 ) >> V_128 ;
F_45 ( V_15 > V_11 -> V_20 ) ;
F_45 ( V_15 + V_20 > V_11 -> V_15 + V_11 -> V_20 ) ;
V_64 = ( V_467 + V_15 ) & ( V_29 - 1 ) ;
while ( V_20 > 0 ) {
V_130 = V_11 -> V_151 [ V_152 ] ;
F_45 ( ! F_207 ( V_130 ) ) ;
V_289 = F_127 ( V_20 , V_29 - V_64 ) ;
V_465 = F_324 ( V_130 ) ;
memset ( V_465 + V_64 , 0 , V_289 ) ;
V_20 -= V_289 ;
V_64 = 0 ;
V_152 ++ ;
}
}
void F_376 ( struct V_10 * V_466 ,
struct V_10 * V_440 )
{
int V_152 ;
unsigned V_201 ;
ASSERT ( V_466 -> V_20 == V_440 -> V_20 ) ;
V_201 = F_151 ( V_466 -> V_15 , V_466 -> V_20 ) ;
for ( V_152 = 0 ; V_152 < V_201 ; V_152 ++ )
F_323 ( F_324 ( V_466 -> V_151 [ V_152 ] ) ,
F_324 ( V_440 -> V_151 [ V_152 ] ) ) ;
}
void F_377 ( struct V_10 * V_466 , struct V_10 * V_440 ,
unsigned long V_480 , unsigned long V_481 ,
unsigned long V_20 )
{
T_1 V_482 = V_466 -> V_20 ;
T_10 V_289 ;
T_10 V_64 ;
struct V_130 * V_130 ;
char * V_465 ;
T_10 V_467 = V_466 -> V_15 & ( ( T_1 ) V_29 - 1 ) ;
unsigned long V_152 = ( V_467 + V_480 ) >> V_128 ;
F_45 ( V_440 -> V_20 != V_482 ) ;
V_64 = ( V_467 + V_480 ) &
( V_29 - 1 ) ;
while ( V_20 > 0 ) {
V_130 = V_466 -> V_151 [ V_152 ] ;
F_45 ( ! F_207 ( V_130 ) ) ;
V_289 = F_127 ( V_20 , ( unsigned long ) ( V_29 - V_64 ) ) ;
V_465 = F_324 ( V_130 ) ;
F_368 ( V_440 , V_465 + V_64 , V_481 , V_289 ) ;
V_481 += V_289 ;
V_20 -= V_289 ;
V_64 = 0 ;
V_152 ++ ;
}
}
void F_378 ( T_18 * V_380 , unsigned int V_15 , int V_20 )
{
T_18 * V_68 = V_380 + F_379 ( V_15 ) ;
const unsigned int V_269 = V_15 + V_20 ;
int V_117 = V_483 - ( V_15 % V_483 ) ;
T_18 V_484 = F_380 ( V_15 ) ;
while ( V_20 - V_117 >= 0 ) {
* V_68 |= V_484 ;
V_20 -= V_117 ;
V_117 = V_483 ;
V_484 = ~ 0 ;
V_68 ++ ;
}
if ( V_20 ) {
V_484 &= F_381 ( V_269 ) ;
* V_68 |= V_484 ;
}
}
void F_382 ( T_18 * V_380 , unsigned int V_15 , int V_20 )
{
T_18 * V_68 = V_380 + F_379 ( V_15 ) ;
const unsigned int V_269 = V_15 + V_20 ;
int V_97 = V_483 - ( V_15 % V_483 ) ;
T_18 V_485 = F_380 ( V_15 ) ;
while ( V_20 - V_97 >= 0 ) {
* V_68 &= ~ V_485 ;
V_20 -= V_97 ;
V_97 = V_483 ;
V_485 = ~ 0 ;
V_68 ++ ;
}
if ( V_20 ) {
V_485 &= F_381 ( V_269 ) ;
* V_68 &= ~ V_485 ;
}
}
static inline void F_383 ( struct V_10 * V_11 ,
unsigned long V_15 , unsigned long V_293 ,
unsigned long * F_360 ,
T_10 * F_132 )
{
T_10 V_467 = V_11 -> V_15 & ( ( T_1 ) V_29 - 1 ) ;
T_10 V_486 = F_379 ( V_293 ) ;
T_10 V_64 ;
V_64 = V_467 + V_15 + V_486 ;
* F_360 = V_64 >> V_128 ;
* F_132 = V_64 & ( V_29 - 1 ) ;
}
int F_384 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_293 )
{
T_18 * V_465 ;
struct V_130 * V_130 ;
unsigned long V_152 ;
T_10 V_64 ;
F_383 ( V_11 , V_15 , V_293 , & V_152 , & V_64 ) ;
V_130 = V_11 -> V_151 [ V_152 ] ;
F_45 ( ! F_207 ( V_130 ) ) ;
V_465 = F_324 ( V_130 ) ;
return 1U & ( V_465 [ V_64 ] >> ( V_293 & ( V_483 - 1 ) ) ) ;
}
void F_385 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_487 , unsigned long V_20 )
{
T_18 * V_465 ;
struct V_130 * V_130 ;
unsigned long V_152 ;
T_10 V_64 ;
const unsigned int V_269 = V_487 + V_20 ;
int V_117 = V_483 - ( V_487 % V_483 ) ;
T_18 V_484 = F_380 ( V_487 ) ;
F_383 ( V_11 , V_15 , V_487 , & V_152 , & V_64 ) ;
V_130 = V_11 -> V_151 [ V_152 ] ;
F_45 ( ! F_207 ( V_130 ) ) ;
V_465 = F_324 ( V_130 ) ;
while ( V_20 >= V_117 ) {
V_465 [ V_64 ] |= V_484 ;
V_20 -= V_117 ;
V_117 = V_483 ;
V_484 = ~ 0 ;
if ( ++ V_64 >= V_29 && V_20 > 0 ) {
V_64 = 0 ;
V_130 = V_11 -> V_151 [ ++ V_152 ] ;
F_45 ( ! F_207 ( V_130 ) ) ;
V_465 = F_324 ( V_130 ) ;
}
}
if ( V_20 ) {
V_484 &= F_381 ( V_269 ) ;
V_465 [ V_64 ] |= V_484 ;
}
}
void F_386 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_487 , unsigned long V_20 )
{
T_18 * V_465 ;
struct V_130 * V_130 ;
unsigned long V_152 ;
T_10 V_64 ;
const unsigned int V_269 = V_487 + V_20 ;
int V_97 = V_483 - ( V_487 % V_483 ) ;
T_18 V_485 = F_380 ( V_487 ) ;
F_383 ( V_11 , V_15 , V_487 , & V_152 , & V_64 ) ;
V_130 = V_11 -> V_151 [ V_152 ] ;
F_45 ( ! F_207 ( V_130 ) ) ;
V_465 = F_324 ( V_130 ) ;
while ( V_20 >= V_97 ) {
V_465 [ V_64 ] &= ~ V_485 ;
V_20 -= V_97 ;
V_97 = V_483 ;
V_485 = ~ 0 ;
if ( ++ V_64 >= V_29 && V_20 > 0 ) {
V_64 = 0 ;
V_130 = V_11 -> V_151 [ ++ V_152 ] ;
F_45 ( ! F_207 ( V_130 ) ) ;
V_465 = F_324 ( V_130 ) ;
}
}
if ( V_20 ) {
V_485 &= F_381 ( V_269 ) ;
V_465 [ V_64 ] &= ~ V_485 ;
}
}
static inline bool F_387 ( unsigned long V_440 , unsigned long V_466 , unsigned long V_20 )
{
unsigned long V_488 = ( V_440 > V_466 ) ? V_440 - V_466 : V_466 - V_440 ;
return V_488 < V_20 ;
}
static void F_388 ( struct V_130 * V_489 , struct V_130 * V_490 ,
unsigned long V_491 , unsigned long V_492 ,
unsigned long V_20 )
{
char * V_493 = F_324 ( V_489 ) ;
char * V_494 ;
int V_495 = 0 ;
if ( V_489 != V_490 ) {
V_494 = F_324 ( V_490 ) ;
} else {
V_494 = V_493 ;
if ( F_387 ( V_492 , V_491 , V_20 ) )
V_495 = 1 ;
}
if ( V_495 )
memmove ( V_493 + V_491 , V_494 + V_492 , V_20 ) ;
else
memcpy ( V_493 + V_491 , V_494 + V_492 , V_20 ) ;
}
void F_389 ( struct V_10 * V_466 , unsigned long V_480 ,
unsigned long V_481 , unsigned long V_20 )
{
struct V_40 * V_31 = V_466 -> V_31 ;
T_10 V_289 ;
T_10 V_496 ;
T_10 V_497 ;
T_10 V_467 = V_466 -> V_15 & ( ( T_1 ) V_29 - 1 ) ;
unsigned long V_498 ;
unsigned long V_499 ;
if ( V_481 + V_20 > V_466 -> V_20 ) {
F_176 ( V_31 ,
L_25 ,
V_481 , V_20 , V_466 -> V_20 ) ;
F_23 ( 1 ) ;
}
if ( V_480 + V_20 > V_466 -> V_20 ) {
F_176 ( V_31 ,
L_26 ,
V_480 , V_20 , V_466 -> V_20 ) ;
F_23 ( 1 ) ;
}
while ( V_20 > 0 ) {
V_496 = ( V_467 + V_480 ) &
( V_29 - 1 ) ;
V_497 = ( V_467 + V_481 ) &
( V_29 - 1 ) ;
V_498 = ( V_467 + V_480 ) >> V_128 ;
V_499 = ( V_467 + V_481 ) >> V_128 ;
V_289 = F_127 ( V_20 , ( unsigned long ) ( V_29 -
V_497 ) ) ;
V_289 = F_118 (unsigned long, cur,
(unsigned long)(PAGE_SIZE - dst_off_in_page)) ;
F_388 ( V_466 -> V_151 [ V_498 ] , V_466 -> V_151 [ V_499 ] ,
V_496 , V_497 , V_289 ) ;
V_481 += V_289 ;
V_480 += V_289 ;
V_20 -= V_289 ;
}
}
void F_390 ( struct V_10 * V_466 , unsigned long V_480 ,
unsigned long V_481 , unsigned long V_20 )
{
struct V_40 * V_31 = V_466 -> V_31 ;
T_10 V_289 ;
T_10 V_496 ;
T_10 V_497 ;
unsigned long V_500 = V_480 + V_20 - 1 ;
unsigned long V_501 = V_481 + V_20 - 1 ;
T_10 V_467 = V_466 -> V_15 & ( ( T_1 ) V_29 - 1 ) ;
unsigned long V_498 ;
unsigned long V_499 ;
if ( V_481 + V_20 > V_466 -> V_20 ) {
F_176 ( V_31 ,
L_27 ,
V_481 , V_20 , V_466 -> V_20 ) ;
F_23 ( 1 ) ;
}
if ( V_480 + V_20 > V_466 -> V_20 ) {
F_176 ( V_31 ,
L_28 ,
V_480 , V_20 , V_466 -> V_20 ) ;
F_23 ( 1 ) ;
}
if ( V_480 < V_481 ) {
F_389 ( V_466 , V_480 , V_481 , V_20 ) ;
return;
}
while ( V_20 > 0 ) {
V_498 = ( V_467 + V_500 ) >> V_128 ;
V_499 = ( V_467 + V_501 ) >> V_128 ;
V_496 = ( V_467 + V_500 ) &
( V_29 - 1 ) ;
V_497 = ( V_467 + V_501 ) &
( V_29 - 1 ) ;
V_289 = F_118 (unsigned long, len, src_off_in_page + 1 ) ;
V_289 = F_127 ( V_289 , V_496 + 1 ) ;
F_388 ( V_466 -> V_151 [ V_498 ] , V_466 -> V_151 [ V_499 ] ,
V_496 - V_289 + 1 ,
V_497 - V_289 + 1 , V_289 ) ;
V_500 -= V_289 ;
V_501 -= V_289 ;
V_20 -= V_289 ;
}
}
int F_391 ( struct V_130 * V_130 )
{
struct V_10 * V_11 ;
F_75 ( & V_130 -> V_27 -> V_367 ) ;
if ( ! F_197 ( V_130 ) ) {
F_78 ( & V_130 -> V_27 -> V_367 ) ;
return 1 ;
}
V_11 = (struct V_10 * ) V_130 -> V_204 ;
F_23 ( ! V_11 ) ;
F_75 ( & V_11 -> V_338 ) ;
if ( F_15 ( & V_11 -> V_17 ) != 1 || F_313 ( V_11 ) ) {
F_78 ( & V_11 -> V_338 ) ;
F_78 ( & V_130 -> V_27 -> V_367 ) ;
return 0 ;
}
F_78 ( & V_130 -> V_27 -> V_367 ) ;
if ( ! F_240 ( V_443 , & V_11 -> V_334 ) ) {
F_78 ( & V_11 -> V_338 ) ;
return 0 ;
}
return F_350 ( V_11 ) ;
}
