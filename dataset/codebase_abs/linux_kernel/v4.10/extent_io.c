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
V_22 , F_19 ( V_25 ) , V_26 , V_15 , V_16 ) ;
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
V_36 = F_21 ( V_34 -> V_38 , V_2 -> V_15 , V_2 -> V_16 ,
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
V_2 = F_37 ( V_18 , V_56 ) ;
if ( ! V_2 )
return V_2 ;
V_2 -> V_2 = 0 ;
V_2 -> V_57 = NULL ;
F_38 ( & V_2 -> V_3 ) ;
F_3 ( & V_2 -> V_14 , & V_12 ) ;
F_39 ( & V_2 -> V_17 , 1 ) ;
F_40 ( & V_2 -> V_58 ) ;
F_41 ( V_2 , V_56 , V_59 ) ;
return V_2 ;
}
void F_42 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( F_43 ( & V_2 -> V_17 ) ) {
F_44 ( F_1 ( V_2 ) ) ;
F_7 ( & V_2 -> V_14 ) ;
F_45 ( V_2 , V_59 ) ;
F_14 ( V_18 , V_2 ) ;
}
}
static struct V_3 * F_46 ( struct V_60 * V_30 ,
struct V_3 * V_61 ,
T_1 V_62 ,
struct V_3 * V_63 ,
struct V_3 * * * V_64 ,
struct V_3 * * V_65 )
{
struct V_3 * * V_66 ;
struct V_3 * V_67 = NULL ;
struct V_68 * V_9 ;
if ( V_64 && V_65 ) {
V_66 = * V_64 ;
V_67 = * V_65 ;
goto V_69;
}
V_66 = V_61 ? & V_61 : & V_30 -> V_3 ;
while ( * V_66 ) {
V_67 = * V_66 ;
V_9 = F_47 ( V_67 , struct V_68 , V_3 ) ;
if ( V_62 < V_9 -> V_15 )
V_66 = & ( * V_66 ) -> V_70 ;
else if ( V_62 > V_9 -> V_16 )
V_66 = & ( * V_66 ) -> V_71 ;
else
return V_67 ;
}
V_69:
F_48 ( V_63 , V_67 , V_66 ) ;
F_49 ( V_63 , V_30 ) ;
return NULL ;
}
static struct V_3 * F_50 ( struct V_23 * V_24 , T_1 V_62 ,
struct V_3 * * V_72 ,
struct V_3 * * V_73 ,
struct V_3 * * * V_74 ,
struct V_3 * * V_75 )
{
struct V_60 * V_30 = & V_24 -> V_2 ;
struct V_3 * * V_76 = & V_30 -> V_3 ;
struct V_3 * V_77 = NULL ;
struct V_3 * V_78 = NULL ;
struct V_68 * V_9 ;
struct V_68 * V_79 = NULL ;
while ( * V_76 ) {
V_77 = * V_76 ;
V_9 = F_47 ( V_77 , struct V_68 , V_3 ) ;
V_79 = V_9 ;
if ( V_62 < V_9 -> V_15 )
V_76 = & ( * V_76 ) -> V_70 ;
else if ( V_62 > V_9 -> V_16 )
V_76 = & ( * V_76 ) -> V_71 ;
else
return * V_76 ;
}
if ( V_74 )
* V_74 = V_76 ;
if ( V_75 )
* V_75 = V_77 ;
if ( V_72 ) {
V_78 = V_77 ;
while ( V_77 && V_62 > V_79 -> V_16 ) {
V_77 = F_51 ( V_77 ) ;
V_79 = F_47 ( V_77 , struct V_68 , V_3 ) ;
}
* V_72 = V_77 ;
V_77 = V_78 ;
}
if ( V_73 ) {
V_79 = F_47 ( V_77 , struct V_68 , V_3 ) ;
while ( V_77 && V_62 < V_79 -> V_15 ) {
V_77 = F_52 ( V_77 ) ;
V_79 = F_47 ( V_77 , struct V_68 , V_3 ) ;
}
* V_73 = V_77 ;
}
return NULL ;
}
static inline struct V_3 *
F_53 ( struct V_23 * V_24 ,
T_1 V_62 ,
struct V_3 * * * V_74 ,
struct V_3 * * V_75 )
{
struct V_3 * V_77 = NULL ;
struct V_3 * V_36 ;
V_36 = F_50 ( V_24 , V_62 , & V_77 , NULL , V_74 , V_75 ) ;
if ( ! V_36 )
return V_77 ;
return V_36 ;
}
static inline struct V_3 * F_54 ( struct V_23 * V_24 ,
T_1 V_62 )
{
return F_53 ( V_24 , V_62 , NULL , NULL ) ;
}
static void F_55 ( struct V_23 * V_24 , struct V_1 * V_5 ,
struct V_1 * V_80 )
{
if ( V_24 -> V_53 && V_24 -> V_53 -> V_81 )
V_24 -> V_53 -> V_81 ( V_24 -> V_27 -> V_28 , V_5 ,
V_80 ) ;
}
static void F_56 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_1 * V_80 ;
struct V_3 * V_82 ;
if ( V_2 -> V_2 & ( V_83 | V_84 ) )
return;
V_82 = F_52 ( & V_2 -> V_3 ) ;
if ( V_82 ) {
V_80 = F_47 ( V_82 , struct V_1 , V_3 ) ;
if ( V_80 -> V_16 == V_2 -> V_15 - 1 &&
V_80 -> V_2 == V_2 -> V_2 ) {
F_55 ( V_24 , V_2 , V_80 ) ;
V_2 -> V_15 = V_80 -> V_15 ;
F_57 ( & V_80 -> V_3 , & V_24 -> V_2 ) ;
F_38 ( & V_80 -> V_3 ) ;
F_42 ( V_80 ) ;
}
}
V_82 = F_51 ( & V_2 -> V_3 ) ;
if ( V_82 ) {
V_80 = F_47 ( V_82 , struct V_1 , V_3 ) ;
if ( V_80 -> V_15 == V_2 -> V_16 + 1 &&
V_80 -> V_2 == V_2 -> V_2 ) {
F_55 ( V_24 , V_2 , V_80 ) ;
V_2 -> V_16 = V_80 -> V_16 ;
F_57 ( & V_80 -> V_3 , & V_24 -> V_2 ) ;
F_38 ( & V_80 -> V_3 ) ;
F_42 ( V_80 ) ;
}
}
}
static void F_58 ( struct V_23 * V_24 ,
struct V_1 * V_2 , unsigned * V_32 )
{
if ( V_24 -> V_53 && V_24 -> V_53 -> V_85 )
V_24 -> V_53 -> V_85 ( V_24 -> V_27 -> V_28 , V_2 , V_32 ) ;
}
static void F_59 ( struct V_23 * V_24 ,
struct V_1 * V_2 , unsigned * V_32 )
{
if ( V_24 -> V_53 && V_24 -> V_53 -> V_86 )
V_24 -> V_53 -> V_86 ( V_24 -> V_27 -> V_28 , V_2 , V_32 ) ;
}
static int F_60 ( struct V_23 * V_24 ,
struct V_1 * V_2 , T_1 V_15 , T_1 V_16 ,
struct V_3 * * * V_66 ,
struct V_3 * * V_67 ,
unsigned * V_32 , struct V_33 * V_34 )
{
struct V_3 * V_63 ;
if ( V_16 < V_15 )
F_61 ( 1 , V_87 L_6 ,
V_16 , V_15 ) ;
V_2 -> V_15 = V_15 ;
V_2 -> V_16 = V_16 ;
F_62 ( V_24 , V_2 , V_32 , V_34 ) ;
V_63 = F_46 ( & V_24 -> V_2 , NULL , V_16 , & V_2 -> V_3 , V_66 , V_67 ) ;
if ( V_63 ) {
struct V_1 * V_88 ;
V_88 = F_47 ( V_63 , struct V_1 , V_3 ) ;
F_12 ( L_7 ,
V_88 -> V_15 , V_88 -> V_16 , V_15 , V_16 ) ;
return - V_89 ;
}
F_56 ( V_24 , V_2 ) ;
return 0 ;
}
static void F_63 ( struct V_23 * V_24 , struct V_1 * V_90 ,
T_1 V_91 )
{
if ( V_24 -> V_53 && V_24 -> V_53 -> V_92 )
V_24 -> V_53 -> V_92 ( V_24 -> V_27 -> V_28 , V_90 , V_91 ) ;
}
static int F_64 ( struct V_23 * V_24 , struct V_1 * V_90 ,
struct V_1 * V_93 , T_1 V_91 )
{
struct V_3 * V_63 ;
F_63 ( V_24 , V_90 , V_91 ) ;
V_93 -> V_15 = V_90 -> V_15 ;
V_93 -> V_16 = V_91 - 1 ;
V_93 -> V_2 = V_90 -> V_2 ;
V_90 -> V_15 = V_91 ;
V_63 = F_46 ( & V_24 -> V_2 , & V_90 -> V_3 , V_93 -> V_16 ,
& V_93 -> V_3 , NULL , NULL ) ;
if ( V_63 ) {
F_42 ( V_93 ) ;
return - V_89 ;
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
unsigned * V_32 , int V_94 ,
struct V_33 * V_34 )
{
struct V_1 * V_13 ;
unsigned V_95 = * V_32 & ~ V_96 ;
if ( ( V_95 & V_97 ) && ( V_2 -> V_2 & V_97 ) ) {
T_1 V_98 = V_2 -> V_16 - V_2 -> V_15 + 1 ;
F_44 ( V_98 > V_24 -> V_54 ) ;
V_24 -> V_54 -= V_98 ;
}
F_59 ( V_24 , V_2 , V_32 ) ;
F_20 ( V_2 , V_95 , V_34 , 0 ) ;
V_2 -> V_2 &= ~ V_95 ;
if ( V_94 )
F_67 ( & V_2 -> V_58 ) ;
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
F_68 ( struct V_1 * V_93 )
{
if ( ! V_93 )
V_93 = F_36 ( V_39 ) ;
return V_93 ;
}
static void F_69 ( struct V_23 * V_24 , int V_99 )
{
F_70 ( F_23 ( V_24 ) , V_99 ,
L_8 ) ;
}
static int F_71 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned V_32 , int V_94 , int V_100 ,
struct V_1 * * V_101 ,
T_3 V_56 , struct V_33 * V_34 )
{
struct V_1 * V_2 ;
struct V_1 * V_102 ;
struct V_1 * V_93 = NULL ;
struct V_3 * V_63 ;
T_1 V_103 ;
int V_99 ;
int V_104 = 0 ;
F_72 ( V_24 , V_15 , V_16 ) ;
if ( V_32 & V_105 )
V_32 |= V_106 ;
if ( V_100 )
V_32 |= ~ V_96 ;
V_32 |= V_107 ;
if ( V_32 & ( V_83 | V_84 ) )
V_104 = 1 ;
V_108:
if ( ! V_93 && F_73 ( V_56 ) ) {
V_93 = F_36 ( V_56 ) ;
}
F_74 ( & V_24 -> V_55 ) ;
if ( V_101 ) {
V_102 = * V_101 ;
if ( V_104 ) {
* V_101 = NULL ;
V_101 = NULL ;
}
if ( V_102 && F_1 ( V_102 ) &&
V_102 -> V_15 <= V_15 && V_102 -> V_16 > V_15 ) {
if ( V_104 )
F_75 ( & V_102 -> V_17 ) ;
V_2 = V_102 ;
goto V_109;
}
if ( V_104 )
F_42 ( V_102 ) ;
}
V_63 = F_54 ( V_24 , V_15 ) ;
if ( ! V_63 )
goto V_110;
V_2 = F_47 ( V_63 , struct V_1 , V_3 ) ;
V_109:
if ( V_2 -> V_15 > V_16 )
goto V_110;
F_44 ( V_2 -> V_16 < V_15 ) ;
V_103 = V_2 -> V_16 ;
if ( ! ( V_2 -> V_2 & V_32 ) ) {
V_2 = F_65 ( V_2 ) ;
goto V_13;
}
if ( V_2 -> V_15 < V_15 ) {
V_93 = F_68 ( V_93 ) ;
F_22 ( ! V_93 ) ;
V_99 = F_64 ( V_24 , V_2 , V_93 , V_15 ) ;
if ( V_99 )
F_69 ( V_24 , V_99 ) ;
V_93 = NULL ;
if ( V_99 )
goto V_110;
if ( V_2 -> V_16 <= V_16 ) {
V_2 = F_66 ( V_24 , V_2 , & V_32 , V_94 ,
V_34 ) ;
goto V_13;
}
goto V_111;
}
if ( V_2 -> V_15 <= V_16 && V_2 -> V_16 > V_16 ) {
V_93 = F_68 ( V_93 ) ;
F_22 ( ! V_93 ) ;
V_99 = F_64 ( V_24 , V_2 , V_93 , V_16 + 1 ) ;
if ( V_99 )
F_69 ( V_24 , V_99 ) ;
if ( V_94 )
F_67 ( & V_2 -> V_58 ) ;
F_66 ( V_24 , V_93 , & V_32 , V_94 , V_34 ) ;
V_93 = NULL ;
goto V_110;
}
V_2 = F_66 ( V_24 , V_2 , & V_32 , V_94 , V_34 ) ;
V_13:
if ( V_103 == ( T_1 ) - 1 )
goto V_110;
V_15 = V_103 + 1 ;
if ( V_15 <= V_16 && V_2 && ! F_76 () )
goto V_109;
V_111:
if ( V_15 > V_16 )
goto V_110;
F_77 ( & V_24 -> V_55 ) ;
if ( F_73 ( V_56 ) )
F_78 () ;
goto V_108;
V_110:
F_77 ( & V_24 -> V_55 ) ;
if ( V_93 )
F_42 ( V_93 ) ;
return 0 ;
}
static void F_79 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
__releases( V_24 -> V_55 )
__acquires( V_24 -> V_55 )
{
F_80 ( V_112 ) ;
F_81 ( & V_2 -> V_58 , & V_112 , V_113 ) ;
F_77 ( & V_24 -> V_55 ) ;
F_82 () ;
F_74 ( & V_24 -> V_55 ) ;
F_83 ( & V_2 -> V_58 , & V_112 ) ;
}
static void F_84 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned long V_32 )
{
struct V_1 * V_2 ;
struct V_3 * V_63 ;
F_72 ( V_24 , V_15 , V_16 ) ;
F_74 ( & V_24 -> V_55 ) ;
V_108:
while ( 1 ) {
V_63 = F_54 ( V_24 , V_15 ) ;
V_114:
if ( ! V_63 )
break;
V_2 = F_47 ( V_63 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 > V_16 )
goto V_110;
if ( V_2 -> V_2 & V_32 ) {
V_15 = V_2 -> V_15 ;
F_85 ( & V_2 -> V_17 ) ;
F_79 ( V_24 , V_2 ) ;
F_42 ( V_2 ) ;
goto V_108;
}
V_15 = V_2 -> V_16 + 1 ;
if ( V_15 > V_16 )
break;
if ( ! F_86 ( & V_24 -> V_55 ) ) {
V_63 = F_51 ( V_63 ) ;
goto V_114;
}
}
V_110:
F_77 ( & V_24 -> V_55 ) ;
}
static void F_62 ( struct V_23 * V_24 ,
struct V_1 * V_2 ,
unsigned * V_32 , struct V_33 * V_34 )
{
unsigned V_115 = * V_32 & ~ V_96 ;
F_58 ( V_24 , V_2 , V_32 ) ;
if ( ( V_115 & V_97 ) && ! ( V_2 -> V_2 & V_97 ) ) {
T_1 V_98 = V_2 -> V_16 - V_2 -> V_15 + 1 ;
V_24 -> V_54 += V_98 ;
}
F_20 ( V_2 , V_115 , V_34 , 1 ) ;
V_2 -> V_2 |= V_115 ;
}
static void F_87 ( struct V_1 * V_2 ,
struct V_1 * * V_116 ,
unsigned V_7 )
{
if ( V_116 && ! ( * V_116 ) ) {
if ( ! V_7 || ( V_2 -> V_2 & V_7 ) ) {
* V_116 = V_2 ;
F_85 ( & V_2 -> V_17 ) ;
}
}
}
static void F_88 ( struct V_1 * V_2 ,
struct V_1 * * V_116 )
{
return F_87 ( V_2 , V_116 ,
V_83 | V_84 ) ;
}
static int T_4
F_89 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned V_32 , unsigned V_117 ,
T_1 * V_118 , struct V_1 * * V_101 ,
T_3 V_56 , struct V_33 * V_34 )
{
struct V_1 * V_2 ;
struct V_1 * V_93 = NULL ;
struct V_3 * V_63 ;
struct V_3 * * V_66 ;
struct V_3 * V_67 ;
int V_99 = 0 ;
T_1 V_119 ;
T_1 V_103 ;
F_72 ( V_24 , V_15 , V_16 ) ;
V_32 |= V_107 ;
V_108:
if ( ! V_93 && F_73 ( V_56 ) ) {
V_93 = F_36 ( V_56 ) ;
}
F_74 ( & V_24 -> V_55 ) ;
if ( V_101 && * V_101 ) {
V_2 = * V_101 ;
if ( V_2 -> V_15 <= V_15 && V_2 -> V_16 > V_15 &&
F_1 ( V_2 ) ) {
V_63 = & V_2 -> V_3 ;
goto V_109;
}
}
V_63 = F_53 ( V_24 , V_15 , & V_66 , & V_67 ) ;
if ( ! V_63 ) {
V_93 = F_68 ( V_93 ) ;
F_22 ( ! V_93 ) ;
V_99 = F_60 ( V_24 , V_93 , V_15 , V_16 ,
& V_66 , & V_67 , & V_32 , V_34 ) ;
if ( V_99 )
F_69 ( V_24 , V_99 ) ;
F_88 ( V_93 , V_101 ) ;
V_93 = NULL ;
goto V_110;
}
V_2 = F_47 ( V_63 , struct V_1 , V_3 ) ;
V_109:
V_119 = V_2 -> V_15 ;
V_103 = V_2 -> V_16 ;
if ( V_2 -> V_15 == V_15 && V_2 -> V_16 <= V_16 ) {
if ( V_2 -> V_2 & V_117 ) {
* V_118 = V_2 -> V_15 ;
V_99 = - V_89 ;
goto V_110;
}
F_62 ( V_24 , V_2 , & V_32 , V_34 ) ;
F_88 ( V_2 , V_101 ) ;
F_56 ( V_24 , V_2 ) ;
if ( V_103 == ( T_1 ) - 1 )
goto V_110;
V_15 = V_103 + 1 ;
V_2 = F_65 ( V_2 ) ;
if ( V_15 < V_16 && V_2 && V_2 -> V_15 == V_15 &&
! F_76 () )
goto V_109;
goto V_111;
}
if ( V_2 -> V_15 < V_15 ) {
if ( V_2 -> V_2 & V_117 ) {
* V_118 = V_15 ;
V_99 = - V_89 ;
goto V_110;
}
V_93 = F_68 ( V_93 ) ;
F_22 ( ! V_93 ) ;
V_99 = F_64 ( V_24 , V_2 , V_93 , V_15 ) ;
if ( V_99 )
F_69 ( V_24 , V_99 ) ;
V_93 = NULL ;
if ( V_99 )
goto V_110;
if ( V_2 -> V_16 <= V_16 ) {
F_62 ( V_24 , V_2 , & V_32 , V_34 ) ;
F_88 ( V_2 , V_101 ) ;
F_56 ( V_24 , V_2 ) ;
if ( V_103 == ( T_1 ) - 1 )
goto V_110;
V_15 = V_103 + 1 ;
V_2 = F_65 ( V_2 ) ;
if ( V_15 < V_16 && V_2 && V_2 -> V_15 == V_15 &&
! F_76 () )
goto V_109;
}
goto V_111;
}
if ( V_2 -> V_15 > V_15 ) {
T_1 V_120 ;
if ( V_16 < V_119 )
V_120 = V_16 ;
else
V_120 = V_119 - 1 ;
V_93 = F_68 ( V_93 ) ;
F_22 ( ! V_93 ) ;
V_99 = F_60 ( V_24 , V_93 , V_15 , V_120 ,
NULL , NULL , & V_32 , V_34 ) ;
if ( V_99 )
F_69 ( V_24 , V_99 ) ;
F_88 ( V_93 , V_101 ) ;
V_93 = NULL ;
V_15 = V_120 + 1 ;
goto V_111;
}
if ( V_2 -> V_15 <= V_16 && V_2 -> V_16 > V_16 ) {
if ( V_2 -> V_2 & V_117 ) {
* V_118 = V_15 ;
V_99 = - V_89 ;
goto V_110;
}
V_93 = F_68 ( V_93 ) ;
F_22 ( ! V_93 ) ;
V_99 = F_64 ( V_24 , V_2 , V_93 , V_16 + 1 ) ;
if ( V_99 )
F_69 ( V_24 , V_99 ) ;
F_62 ( V_24 , V_93 , & V_32 , V_34 ) ;
F_88 ( V_93 , V_101 ) ;
F_56 ( V_24 , V_93 ) ;
V_93 = NULL ;
goto V_110;
}
V_111:
if ( V_15 > V_16 )
goto V_110;
F_77 ( & V_24 -> V_55 ) ;
if ( F_73 ( V_56 ) )
F_78 () ;
goto V_108;
V_110:
F_77 ( & V_24 -> V_55 ) ;
if ( V_93 )
F_42 ( V_93 ) ;
return V_99 ;
}
int F_90 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned V_32 , T_1 * V_118 ,
struct V_1 * * V_101 , T_3 V_56 )
{
return F_89 ( V_24 , V_15 , V_16 , V_32 , 0 , V_118 ,
V_101 , V_56 , NULL ) ;
}
int F_91 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned V_32 , unsigned V_121 ,
struct V_1 * * V_101 )
{
struct V_1 * V_2 ;
struct V_1 * V_93 = NULL ;
struct V_3 * V_63 ;
struct V_3 * * V_66 ;
struct V_3 * V_67 ;
int V_99 = 0 ;
T_1 V_119 ;
T_1 V_103 ;
bool V_122 = true ;
F_72 ( V_24 , V_15 , V_16 ) ;
V_108:
if ( ! V_93 ) {
V_93 = F_36 ( V_123 ) ;
if ( ! V_93 && ! V_122 )
return - V_43 ;
}
F_74 ( & V_24 -> V_55 ) ;
if ( V_101 && * V_101 ) {
V_2 = * V_101 ;
if ( V_2 -> V_15 <= V_15 && V_2 -> V_16 > V_15 &&
F_1 ( V_2 ) ) {
V_63 = & V_2 -> V_3 ;
goto V_109;
}
}
V_63 = F_53 ( V_24 , V_15 , & V_66 , & V_67 ) ;
if ( ! V_63 ) {
V_93 = F_68 ( V_93 ) ;
if ( ! V_93 ) {
V_99 = - V_43 ;
goto V_110;
}
V_99 = F_60 ( V_24 , V_93 , V_15 , V_16 ,
& V_66 , & V_67 , & V_32 , NULL ) ;
if ( V_99 )
F_69 ( V_24 , V_99 ) ;
F_88 ( V_93 , V_101 ) ;
V_93 = NULL ;
goto V_110;
}
V_2 = F_47 ( V_63 , struct V_1 , V_3 ) ;
V_109:
V_119 = V_2 -> V_15 ;
V_103 = V_2 -> V_16 ;
if ( V_2 -> V_15 == V_15 && V_2 -> V_16 <= V_16 ) {
F_62 ( V_24 , V_2 , & V_32 , NULL ) ;
F_88 ( V_2 , V_101 ) ;
V_2 = F_66 ( V_24 , V_2 , & V_121 , 0 , NULL ) ;
if ( V_103 == ( T_1 ) - 1 )
goto V_110;
V_15 = V_103 + 1 ;
if ( V_15 < V_16 && V_2 && V_2 -> V_15 == V_15 &&
! F_76 () )
goto V_109;
goto V_111;
}
if ( V_2 -> V_15 < V_15 ) {
V_93 = F_68 ( V_93 ) ;
if ( ! V_93 ) {
V_99 = - V_43 ;
goto V_110;
}
V_99 = F_64 ( V_24 , V_2 , V_93 , V_15 ) ;
if ( V_99 )
F_69 ( V_24 , V_99 ) ;
V_93 = NULL ;
if ( V_99 )
goto V_110;
if ( V_2 -> V_16 <= V_16 ) {
F_62 ( V_24 , V_2 , & V_32 , NULL ) ;
F_88 ( V_2 , V_101 ) ;
V_2 = F_66 ( V_24 , V_2 , & V_121 , 0 ,
NULL ) ;
if ( V_103 == ( T_1 ) - 1 )
goto V_110;
V_15 = V_103 + 1 ;
if ( V_15 < V_16 && V_2 && V_2 -> V_15 == V_15 &&
! F_76 () )
goto V_109;
}
goto V_111;
}
if ( V_2 -> V_15 > V_15 ) {
T_1 V_120 ;
if ( V_16 < V_119 )
V_120 = V_16 ;
else
V_120 = V_119 - 1 ;
V_93 = F_68 ( V_93 ) ;
if ( ! V_93 ) {
V_99 = - V_43 ;
goto V_110;
}
V_99 = F_60 ( V_24 , V_93 , V_15 , V_120 ,
NULL , NULL , & V_32 , NULL ) ;
if ( V_99 )
F_69 ( V_24 , V_99 ) ;
F_88 ( V_93 , V_101 ) ;
V_93 = NULL ;
V_15 = V_120 + 1 ;
goto V_111;
}
if ( V_2 -> V_15 <= V_16 && V_2 -> V_16 > V_16 ) {
V_93 = F_68 ( V_93 ) ;
if ( ! V_93 ) {
V_99 = - V_43 ;
goto V_110;
}
V_99 = F_64 ( V_24 , V_2 , V_93 , V_16 + 1 ) ;
if ( V_99 )
F_69 ( V_24 , V_99 ) ;
F_62 ( V_24 , V_93 , & V_32 , NULL ) ;
F_88 ( V_93 , V_101 ) ;
F_66 ( V_24 , V_93 , & V_121 , 0 , NULL ) ;
V_93 = NULL ;
goto V_110;
}
V_111:
if ( V_15 > V_16 )
goto V_110;
F_77 ( & V_24 -> V_55 ) ;
F_78 () ;
V_122 = false ;
goto V_108;
V_110:
F_77 ( & V_24 -> V_55 ) ;
if ( V_93 )
F_42 ( V_93 ) ;
return V_99 ;
}
int F_92 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned V_32 , struct V_33 * V_34 )
{
F_22 ( V_32 & V_124 ) ;
return F_89 ( V_24 , V_15 , V_16 , V_32 , 0 , NULL , NULL , V_123 ,
V_34 ) ;
}
int F_93 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned V_32 , int V_94 , int V_100 ,
struct V_1 * * V_102 , T_3 V_56 )
{
return F_71 ( V_24 , V_15 , V_16 , V_32 , V_94 , V_100 ,
V_102 , V_56 , NULL ) ;
}
int F_94 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned V_32 , struct V_33 * V_34 )
{
F_22 ( V_32 & V_124 ) ;
return F_71 ( V_24 , V_15 , V_16 , V_32 , 0 , 0 , NULL , V_123 ,
V_34 ) ;
}
int F_95 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
struct V_1 * * V_101 )
{
int V_99 ;
T_1 V_118 ;
while ( 1 ) {
V_99 = F_89 ( V_24 , V_15 , V_16 , V_124 ,
V_124 , & V_118 ,
V_101 , V_123 , NULL ) ;
if ( V_99 == - V_89 ) {
F_84 ( V_24 , V_118 , V_16 , V_124 ) ;
V_15 = V_118 ;
} else
break;
F_44 ( V_15 > V_16 ) ;
}
return V_99 ;
}
int F_96 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 )
{
int V_99 ;
T_1 V_118 ;
V_99 = F_89 ( V_24 , V_15 , V_16 , V_124 , V_124 ,
& V_118 , NULL , V_123 , NULL ) ;
if ( V_99 == - V_89 ) {
if ( V_118 > V_15 )
F_93 ( V_24 , V_15 , V_118 - 1 ,
V_124 , 1 , 0 , NULL , V_123 ) ;
return 0 ;
}
return 1 ;
}
void F_97 ( struct V_25 * V_25 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_125 = V_15 >> V_126 ;
unsigned long V_127 = V_16 >> V_126 ;
struct V_128 * V_128 ;
while ( V_125 <= V_127 ) {
V_128 = F_98 ( V_25 -> V_129 , V_125 ) ;
F_22 ( ! V_128 ) ;
F_99 ( V_128 ) ;
F_100 ( V_128 ) ;
V_125 ++ ;
}
}
void F_101 ( struct V_25 * V_25 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_125 = V_15 >> V_126 ;
unsigned long V_127 = V_16 >> V_126 ;
struct V_128 * V_128 ;
while ( V_125 <= V_127 ) {
V_128 = F_98 ( V_25 -> V_129 , V_125 ) ;
F_22 ( ! V_128 ) ;
F_102 ( V_128 ) ;
F_103 ( V_128 ) ;
F_100 ( V_128 ) ;
V_125 ++ ;
}
}
static void F_104 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_125 = V_15 >> V_126 ;
unsigned long V_127 = V_16 >> V_126 ;
struct V_128 * V_128 ;
while ( V_125 <= V_127 ) {
V_128 = F_98 ( V_24 -> V_27 , V_125 ) ;
F_22 ( ! V_128 ) ;
F_105 ( V_128 ) ;
F_100 ( V_128 ) ;
V_125 ++ ;
}
}
static struct V_1 *
F_106 ( struct V_23 * V_24 ,
T_1 V_15 , unsigned V_32 )
{
struct V_3 * V_63 ;
struct V_1 * V_2 ;
V_63 = F_54 ( V_24 , V_15 ) ;
if ( ! V_63 )
goto V_110;
while ( 1 ) {
V_2 = F_47 ( V_63 , struct V_1 , V_3 ) ;
if ( V_2 -> V_16 >= V_15 && ( V_2 -> V_2 & V_32 ) )
return V_2 ;
V_63 = F_51 ( V_63 ) ;
if ( ! V_63 )
break;
}
V_110:
return NULL ;
}
int F_107 ( struct V_23 * V_24 , T_1 V_15 ,
T_1 * V_130 , T_1 * V_131 , unsigned V_32 ,
struct V_1 * * V_101 )
{
struct V_1 * V_2 ;
struct V_3 * V_76 ;
int V_36 = 1 ;
F_74 ( & V_24 -> V_55 ) ;
if ( V_101 && * V_101 ) {
V_2 = * V_101 ;
if ( V_2 -> V_16 == V_15 - 1 && F_1 ( V_2 ) ) {
V_76 = F_51 ( & V_2 -> V_3 ) ;
while ( V_76 ) {
V_2 = F_47 ( V_76 , struct V_1 ,
V_3 ) ;
if ( V_2 -> V_2 & V_32 )
goto V_132;
V_76 = F_51 ( V_76 ) ;
}
F_42 ( * V_101 ) ;
* V_101 = NULL ;
goto V_110;
}
F_42 ( * V_101 ) ;
* V_101 = NULL ;
}
V_2 = F_106 ( V_24 , V_15 , V_32 ) ;
V_132:
if ( V_2 ) {
F_87 ( V_2 , V_101 , 0 ) ;
* V_130 = V_2 -> V_15 ;
* V_131 = V_2 -> V_16 ;
V_36 = 0 ;
}
V_110:
F_77 ( & V_24 -> V_55 ) ;
return V_36 ;
}
static T_5 T_1 F_108 ( struct V_23 * V_24 ,
T_1 * V_15 , T_1 * V_16 , T_1 V_133 ,
struct V_1 * * V_101 )
{
struct V_3 * V_63 ;
struct V_1 * V_2 ;
T_1 V_134 = * V_15 ;
T_1 V_88 = 0 ;
T_1 V_135 = 0 ;
F_74 ( & V_24 -> V_55 ) ;
V_63 = F_54 ( V_24 , V_134 ) ;
if ( ! V_63 ) {
if ( ! V_88 )
* V_16 = ( T_1 ) - 1 ;
goto V_110;
}
while ( 1 ) {
V_2 = F_47 ( V_63 , struct V_1 , V_3 ) ;
if ( V_88 && ( V_2 -> V_15 != V_134 ||
( V_2 -> V_2 & V_84 ) ) ) {
goto V_110;
}
if ( ! ( V_2 -> V_2 & V_105 ) ) {
if ( ! V_88 )
* V_16 = V_2 -> V_16 ;
goto V_110;
}
if ( ! V_88 ) {
* V_15 = V_2 -> V_15 ;
* V_101 = V_2 ;
F_85 ( & V_2 -> V_17 ) ;
}
V_88 ++ ;
* V_16 = V_2 -> V_16 ;
V_134 = V_2 -> V_16 + 1 ;
V_63 = F_51 ( V_63 ) ;
V_135 += V_2 -> V_16 - V_2 -> V_15 + 1 ;
if ( V_135 >= V_133 )
break;
if ( ! V_63 )
break;
}
V_110:
F_77 ( & V_24 -> V_55 ) ;
return V_88 ;
}
static T_5 void F_109 ( struct V_25 * V_25 ,
struct V_128 * V_136 ,
T_1 V_15 , T_1 V_16 )
{
int V_36 ;
struct V_128 * V_137 [ 16 ] ;
unsigned long V_125 = V_15 >> V_126 ;
unsigned long V_127 = V_16 >> V_126 ;
unsigned long V_138 = V_127 - V_125 + 1 ;
int V_139 ;
if ( V_125 == V_136 -> V_125 && V_127 == V_125 )
return;
while ( V_138 > 0 ) {
V_36 = F_110 ( V_25 -> V_129 , V_125 ,
F_111 (unsigned long, nr_pages,
ARRAY_SIZE(pages)) , V_137 ) ;
for ( V_139 = 0 ; V_139 < V_36 ; V_139 ++ ) {
if ( V_137 [ V_139 ] != V_136 )
F_112 ( V_137 [ V_139 ] ) ;
F_100 ( V_137 [ V_139 ] ) ;
}
V_138 -= V_36 ;
V_125 += V_36 ;
F_78 () ;
}
}
static T_5 int F_113 ( struct V_25 * V_25 ,
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
int V_36 ;
int V_139 ;
if ( V_125 == V_136 -> V_125 && V_125 == V_127 )
return 0 ;
V_144 = V_127 - V_125 + 1 ;
while ( V_144 > 0 ) {
V_36 = F_110 ( V_25 -> V_129 , V_125 ,
F_111 (unsigned long,
nrpages, ARRAY_SIZE(pages)) , V_137 ) ;
if ( V_36 == 0 ) {
V_36 = - V_145 ;
goto V_146;
}
for ( V_139 = 0 ; V_139 < V_36 ; V_139 ++ ) {
if ( V_137 [ V_139 ] != V_136 ) {
F_114 ( V_137 [ V_139 ] ) ;
if ( ! F_115 ( V_137 [ V_139 ] ) ||
V_137 [ V_139 ] -> V_27 != V_25 -> V_129 ) {
V_36 = - V_145 ;
F_112 ( V_137 [ V_139 ] ) ;
F_100 ( V_137 [ V_139 ] ) ;
goto V_146;
}
}
F_100 ( V_137 [ V_139 ] ) ;
V_143 ++ ;
}
V_144 -= V_36 ;
V_125 += V_36 ;
F_78 () ;
}
V_36 = 0 ;
V_146:
if ( V_36 && V_143 ) {
F_109 ( V_25 , V_136 ,
V_140 ,
( ( T_1 ) ( V_142 + V_143 - 1 ) ) <<
V_126 ) ;
}
return V_36 ;
}
STATIC T_1 F_116 ( struct V_25 * V_25 ,
struct V_23 * V_24 ,
struct V_128 * V_136 , T_1 * V_15 ,
T_1 * V_16 , T_1 V_133 )
{
T_1 V_140 ;
T_1 V_141 ;
T_1 V_88 ;
struct V_1 * V_101 = NULL ;
int V_36 ;
int V_147 = 0 ;
V_108:
V_140 = * V_15 ;
V_141 = 0 ;
V_88 = F_108 ( V_24 , & V_140 , & V_141 ,
V_133 , & V_101 ) ;
if ( ! V_88 || V_141 <= * V_15 ) {
* V_15 = V_140 ;
* V_16 = V_141 ;
F_42 ( V_101 ) ;
return 0 ;
}
if ( V_140 < * V_15 )
V_140 = * V_15 ;
if ( V_141 + 1 - V_140 > V_133 )
V_141 = V_140 + V_133 - 1 ;
V_36 = F_113 ( V_25 , V_136 ,
V_140 , V_141 ) ;
if ( V_36 == - V_145 ) {
F_42 ( V_101 ) ;
V_101 = NULL ;
if ( ! V_147 ) {
V_133 = V_29 ;
V_147 = 1 ;
goto V_108;
} else {
V_88 = 0 ;
goto V_148;
}
}
F_22 ( V_36 ) ;
F_95 ( V_24 , V_140 , V_141 , & V_101 ) ;
V_36 = F_117 ( V_24 , V_140 , V_141 ,
V_105 , 1 , V_101 ) ;
if ( ! V_36 ) {
F_118 ( V_24 , V_140 , V_141 ,
& V_101 , V_123 ) ;
F_109 ( V_25 , V_136 ,
V_140 , V_141 ) ;
F_78 () ;
goto V_108;
}
F_42 ( V_101 ) ;
* V_15 = V_140 ;
* V_16 = V_141 ;
V_148:
return V_88 ;
}
void F_119 ( struct V_25 * V_25 , T_1 V_15 , T_1 V_16 ,
T_1 V_141 , struct V_128 * V_136 ,
unsigned V_121 ,
unsigned long V_149 )
{
struct V_23 * V_24 = & F_18 ( V_25 ) -> V_150 ;
int V_36 ;
struct V_128 * V_137 [ 16 ] ;
unsigned long V_125 = V_15 >> V_126 ;
unsigned long V_127 = V_16 >> V_126 ;
unsigned long V_138 = V_127 - V_125 + 1 ;
int V_139 ;
F_93 ( V_24 , V_15 , V_16 , V_121 , 1 , 0 , NULL , V_123 ) ;
if ( V_149 == 0 )
return;
if ( ( V_149 & V_151 ) && V_138 > 0 )
F_120 ( V_25 -> V_129 , - V_152 ) ;
while ( V_138 > 0 ) {
V_36 = F_110 ( V_25 -> V_129 , V_125 ,
F_111 (unsigned long,
nr_pages, ARRAY_SIZE(pages)) , V_137 ) ;
for ( V_139 = 0 ; V_139 < V_36 ; V_139 ++ ) {
if ( V_149 & V_153 )
F_121 ( V_137 [ V_139 ] ) ;
if ( V_137 [ V_139 ] == V_136 ) {
F_100 ( V_137 [ V_139 ] ) ;
continue;
}
if ( V_149 & V_154 )
F_99 ( V_137 [ V_139 ] ) ;
if ( V_149 & V_155 )
F_105 ( V_137 [ V_139 ] ) ;
if ( V_149 & V_151 )
F_122 ( V_137 [ V_139 ] ) ;
if ( V_149 & V_156 )
F_123 ( V_137 [ V_139 ] ) ;
if ( V_149 & V_157 )
F_112 ( V_137 [ V_139 ] ) ;
F_100 ( V_137 [ V_139 ] ) ;
}
V_138 -= V_36 ;
V_125 += V_36 ;
F_78 () ;
}
}
T_1 F_124 ( struct V_23 * V_24 ,
T_1 * V_15 , T_1 V_158 , T_1 V_133 ,
unsigned V_32 , int V_159 )
{
struct V_3 * V_63 ;
struct V_1 * V_2 ;
T_1 V_134 = * V_15 ;
T_1 V_135 = 0 ;
T_1 V_160 = 0 ;
int V_88 = 0 ;
if ( F_44 ( V_158 <= V_134 ) )
return 0 ;
F_74 ( & V_24 -> V_55 ) ;
if ( V_134 == 0 && V_32 == V_97 ) {
V_135 = V_24 -> V_54 ;
goto V_110;
}
V_63 = F_54 ( V_24 , V_134 ) ;
if ( ! V_63 )
goto V_110;
while ( 1 ) {
V_2 = F_47 ( V_63 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 > V_158 )
break;
if ( V_159 && V_88 && V_2 -> V_15 > V_160 + 1 )
break;
if ( V_2 -> V_16 >= V_134 && ( V_2 -> V_2 & V_32 ) == V_32 ) {
V_135 += F_125 ( V_158 , V_2 -> V_16 ) + 1 -
F_126 ( V_134 , V_2 -> V_15 ) ;
if ( V_135 >= V_133 )
break;
if ( ! V_88 ) {
* V_15 = F_126 ( V_134 , V_2 -> V_15 ) ;
V_88 = 1 ;
}
V_160 = V_2 -> V_16 ;
} else if ( V_159 && V_88 ) {
break;
}
V_63 = F_51 ( V_63 ) ;
if ( ! V_63 )
break;
}
V_110:
F_77 ( & V_24 -> V_55 ) ;
return V_135 ;
}
static T_5 int F_127 ( struct V_23 * V_24 , T_1 V_15 ,
struct V_161 * V_57 )
{
struct V_3 * V_63 ;
struct V_1 * V_2 ;
int V_36 = 0 ;
F_74 ( & V_24 -> V_55 ) ;
V_63 = F_54 ( V_24 , V_15 ) ;
if ( ! V_63 ) {
V_36 = - V_162 ;
goto V_110;
}
V_2 = F_47 ( V_63 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 != V_15 ) {
V_36 = - V_162 ;
goto V_110;
}
V_2 -> V_57 = V_57 ;
V_110:
F_77 ( & V_24 -> V_55 ) ;
return V_36 ;
}
static T_5 int F_128 ( struct V_23 * V_24 , T_1 V_15 ,
struct V_161 * * V_57 )
{
struct V_3 * V_63 ;
struct V_1 * V_2 ;
int V_36 = 0 ;
F_74 ( & V_24 -> V_55 ) ;
V_63 = F_54 ( V_24 , V_15 ) ;
if ( ! V_63 ) {
V_36 = - V_162 ;
goto V_110;
}
V_2 = F_47 ( V_63 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 != V_15 ) {
V_36 = - V_162 ;
goto V_110;
}
* V_57 = V_2 -> V_57 ;
V_110:
F_77 ( & V_24 -> V_55 ) ;
return V_36 ;
}
int F_117 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned V_32 , int V_163 , struct V_1 * V_102 )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_63 ;
int V_164 = 0 ;
F_74 ( & V_24 -> V_55 ) ;
if ( V_102 && F_1 ( V_102 ) && V_102 -> V_15 <= V_15 &&
V_102 -> V_16 > V_15 )
V_63 = & V_102 -> V_3 ;
else
V_63 = F_54 ( V_24 , V_15 ) ;
while ( V_63 && V_15 <= V_16 ) {
V_2 = F_47 ( V_63 , struct V_1 , V_3 ) ;
if ( V_163 && V_2 -> V_15 > V_15 ) {
V_164 = 0 ;
break;
}
if ( V_2 -> V_15 > V_16 )
break;
if ( V_2 -> V_2 & V_32 ) {
V_164 = 1 ;
if ( ! V_163 )
break;
} else if ( V_163 ) {
V_164 = 0 ;
break;
}
if ( V_2 -> V_16 == ( T_1 ) - 1 )
break;
V_15 = V_2 -> V_16 + 1 ;
if ( V_15 > V_16 )
break;
V_63 = F_51 ( V_63 ) ;
if ( ! V_63 ) {
if ( V_163 )
V_164 = 0 ;
break;
}
}
F_77 ( & V_24 -> V_55 ) ;
return V_164 ;
}
static void F_129 ( struct V_23 * V_24 , struct V_128 * V_128 )
{
T_1 V_15 = F_130 ( V_128 ) ;
T_1 V_16 = V_15 + V_29 - 1 ;
if ( F_117 ( V_24 , V_15 , V_16 , V_165 , 1 , NULL ) )
F_131 ( V_128 ) ;
}
int F_132 ( struct V_25 * V_25 , struct V_161 * V_166 )
{
int V_36 ;
int V_99 = 0 ;
struct V_23 * V_167 = & F_18 ( V_25 ) -> V_168 ;
F_127 ( V_167 , V_166 -> V_15 , NULL ) ;
V_36 = F_133 ( V_167 , V_166 -> V_15 ,
V_166 -> V_15 + V_166 -> V_20 - 1 ,
V_124 | V_97 ) ;
if ( V_36 )
V_99 = V_36 ;
V_36 = F_133 ( & F_18 ( V_25 ) -> V_150 , V_166 -> V_15 ,
V_166 -> V_15 + V_166 -> V_20 - 1 ,
V_169 ) ;
if ( V_36 && ! V_99 )
V_99 = V_36 ;
F_134 ( V_166 ) ;
return V_99 ;
}
int F_135 ( struct V_25 * V_25 , T_1 V_15 , T_1 V_170 , T_1 V_171 ,
struct V_128 * V_128 , unsigned int V_172 , int V_173 )
{
struct V_40 * V_31 = F_18 ( V_25 ) -> V_30 -> V_31 ;
struct V_48 * V_48 ;
struct V_174 * V_175 ;
T_1 V_176 = 0 ;
T_1 V_177 ;
struct V_178 * V_179 = NULL ;
struct V_180 * V_181 = & V_31 -> V_182 ;
int V_36 ;
ASSERT ( ! ( V_31 -> V_183 -> V_184 & V_185 ) ) ;
F_22 ( ! V_173 ) ;
if ( F_136 ( V_181 , V_171 , V_170 , V_173 ) )
return 0 ;
V_48 = F_137 ( V_123 , 1 ) ;
if ( ! V_48 )
return - V_152 ;
V_48 -> V_186 . V_187 = 0 ;
V_176 = V_170 ;
F_138 ( V_31 ) ;
V_36 = F_139 ( V_31 , V_188 , V_171 ,
& V_176 , & V_179 , V_173 ) ;
if ( V_36 ) {
F_140 ( V_31 ) ;
F_141 ( V_48 ) ;
return - V_152 ;
}
F_22 ( V_173 != V_179 -> V_173 ) ;
V_177 = V_179 -> V_189 [ V_173 - 1 ] . V_190 >> 9 ;
V_48 -> V_186 . V_191 = V_177 ;
V_175 = V_179 -> V_189 [ V_173 - 1 ] . V_175 ;
F_142 ( V_179 ) ;
if ( ! V_175 || ! V_175 -> V_192 || ! V_175 -> V_193 ) {
F_140 ( V_31 ) ;
F_141 ( V_48 ) ;
return - V_152 ;
}
V_48 -> V_194 = V_175 -> V_192 ;
V_48 -> V_195 = V_196 | V_197 ;
F_143 ( V_48 , V_128 , V_170 , V_172 ) ;
if ( F_144 ( V_48 ) ) {
F_140 ( V_31 ) ;
F_141 ( V_48 ) ;
F_145 ( V_175 , V_198 ) ;
return - V_152 ;
}
F_146 ( V_31 ,
L_9 ,
F_19 ( V_25 ) , V_15 ,
F_147 ( V_175 -> V_199 ) , V_177 ) ;
F_140 ( V_31 ) ;
F_141 ( V_48 ) ;
return 0 ;
}
int F_148 ( struct V_40 * V_31 ,
struct V_10 * V_11 , int V_173 )
{
T_1 V_15 = V_11 -> V_15 ;
unsigned long V_139 , V_200 = F_149 ( V_11 -> V_15 , V_11 -> V_20 ) ;
int V_36 = 0 ;
if ( V_31 -> V_183 -> V_184 & V_185 )
return - V_201 ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
struct V_128 * V_66 = V_11 -> V_137 [ V_139 ] ;
V_36 = F_135 ( V_31 -> V_202 , V_15 ,
V_29 , V_15 , V_66 ,
V_15 - F_130 ( V_66 ) , V_173 ) ;
if ( V_36 )
break;
V_15 += V_29 ;
}
return V_36 ;
}
int F_150 ( struct V_25 * V_25 , T_1 V_15 , struct V_128 * V_128 ,
unsigned int V_172 )
{
T_1 V_203 ;
struct V_161 * V_57 ;
struct V_40 * V_31 = F_18 ( V_25 ) -> V_30 -> V_31 ;
struct V_1 * V_2 ;
int V_204 ;
int V_36 ;
V_203 = 0 ;
V_36 = F_124 ( & F_18 ( V_25 ) -> V_168 , & V_203 ,
( T_1 ) - 1 , 1 , V_97 , 0 ) ;
if ( ! V_36 )
return 0 ;
V_36 = F_128 ( & F_18 ( V_25 ) -> V_168 , V_15 ,
& V_57 ) ;
if ( V_36 )
return 0 ;
F_22 ( ! V_57 -> V_205 ) ;
if ( V_57 -> V_206 ) {
F_151 ( V_31 ,
L_10 ,
V_57 -> V_15 ) ;
goto V_110;
}
if ( V_31 -> V_183 -> V_184 & V_185 )
goto V_110;
F_74 ( & F_18 ( V_25 ) -> V_150 . V_55 ) ;
V_2 = F_106 ( & F_18 ( V_25 ) -> V_150 ,
V_57 -> V_15 ,
V_124 ) ;
F_77 ( & F_18 ( V_25 ) -> V_150 . V_55 ) ;
if ( V_2 && V_2 -> V_15 <= V_57 -> V_15 &&
V_2 -> V_16 >= V_57 -> V_15 + V_57 -> V_20 - 1 ) {
V_204 = F_152 ( V_31 , V_57 -> V_171 ,
V_57 -> V_20 ) ;
if ( V_204 > 1 ) {
F_135 ( V_25 , V_15 , V_57 -> V_20 ,
V_57 -> V_171 , V_128 ,
V_172 , V_57 -> V_207 ) ;
}
}
V_110:
F_132 ( V_25 , V_57 ) ;
return 0 ;
}
void F_153 ( struct V_25 * V_25 , T_1 V_15 , T_1 V_16 )
{
struct V_23 * V_167 = & F_18 ( V_25 ) -> V_168 ;
struct V_161 * V_57 ;
struct V_1 * V_2 , * V_13 ;
if ( F_154 ( & V_167 -> V_2 ) )
return;
F_74 ( & V_167 -> V_55 ) ;
V_2 = F_106 ( V_167 , V_15 , V_97 ) ;
while ( V_2 ) {
if ( V_2 -> V_15 > V_16 )
break;
ASSERT ( V_2 -> V_16 <= V_16 ) ;
V_13 = F_65 ( V_2 ) ;
V_57 = V_2 -> V_57 ;
F_42 ( V_2 ) ;
F_134 ( V_57 ) ;
V_2 = V_13 ;
}
F_77 ( & V_167 -> V_55 ) ;
}
int F_155 ( struct V_25 * V_25 , T_1 V_15 , T_1 V_16 ,
struct V_161 * * V_208 )
{
struct V_40 * V_31 = F_24 ( V_25 -> V_41 ) ;
struct V_161 * V_57 ;
struct V_209 * V_210 ;
struct V_23 * V_167 = & F_18 ( V_25 ) -> V_168 ;
struct V_23 * V_24 = & F_18 ( V_25 ) -> V_150 ;
struct V_211 * V_212 = & F_18 ( V_25 ) -> V_213 ;
int V_36 ;
T_1 V_171 ;
V_36 = F_128 ( V_167 , V_15 , & V_57 ) ;
if ( V_36 ) {
V_57 = F_156 ( sizeof( * V_57 ) , V_123 ) ;
if ( ! V_57 )
return - V_43 ;
V_57 -> V_15 = V_15 ;
V_57 -> V_20 = V_16 - V_15 + 1 ;
V_57 -> V_205 = 0 ;
V_57 -> V_214 = 0 ;
V_57 -> V_206 = 0 ;
F_157 ( & V_212 -> V_55 ) ;
V_210 = F_158 ( V_212 , V_15 , V_57 -> V_20 ) ;
if ( ! V_210 ) {
F_159 ( & V_212 -> V_55 ) ;
F_134 ( V_57 ) ;
return - V_152 ;
}
if ( V_210 -> V_15 > V_15 || V_210 -> V_15 + V_210 -> V_20 <= V_15 ) {
F_160 ( V_210 ) ;
V_210 = NULL ;
}
F_159 ( & V_212 -> V_55 ) ;
if ( ! V_210 ) {
F_134 ( V_57 ) ;
return - V_152 ;
}
V_171 = V_15 - V_210 -> V_15 ;
V_171 = V_210 -> V_215 + V_171 ;
if ( F_161 ( V_216 , & V_210 -> V_7 ) ) {
V_171 = V_210 -> V_215 ;
V_57 -> V_214 = V_217 ;
F_162 ( & V_57 -> V_214 ,
V_210 -> V_218 ) ;
}
F_151 ( V_31 ,
L_11 ,
V_171 , V_15 , V_57 -> V_20 ) ;
V_57 -> V_171 = V_171 ;
F_160 ( V_210 ) ;
V_36 = F_163 ( V_167 , V_15 , V_16 ,
V_124 | V_97 ) ;
if ( V_36 >= 0 )
V_36 = F_127 ( V_167 , V_15 , V_57 ) ;
if ( V_36 >= 0 )
V_36 = F_163 ( V_24 , V_15 , V_16 , V_169 ) ;
if ( V_36 < 0 ) {
F_134 ( V_57 ) ;
return V_36 ;
}
} else {
F_151 ( V_31 ,
L_12 ,
V_57 -> V_171 , V_57 -> V_15 , V_57 -> V_20 ,
V_57 -> V_206 ) ;
}
* V_208 = V_57 ;
return 0 ;
}
int F_164 ( struct V_25 * V_25 , struct V_48 * V_219 ,
struct V_161 * V_57 , int V_207 )
{
struct V_40 * V_31 = F_24 ( V_25 -> V_41 ) ;
int V_204 ;
V_204 = F_152 ( V_31 , V_57 -> V_171 , V_57 -> V_20 ) ;
if ( V_204 == 1 ) {
F_151 ( V_31 ,
L_13 ,
V_204 , V_57 -> V_205 , V_207 ) ;
return 0 ;
}
if ( V_219 -> V_220 > 1 ) {
F_22 ( V_57 -> V_206 ) ;
V_57 -> V_206 = 1 ;
V_57 -> V_205 = V_207 ;
} else {
if ( V_57 -> V_206 ) {
F_22 ( V_57 -> V_205 != V_207 ) ;
V_57 -> V_206 = 0 ;
V_57 -> V_205 = 0 ;
}
V_57 -> V_207 = V_207 ;
V_57 -> V_205 ++ ;
if ( V_57 -> V_205 == V_207 )
V_57 -> V_205 ++ ;
}
if ( V_57 -> V_205 > V_204 ) {
F_151 ( V_31 ,
L_14 ,
V_204 , V_57 -> V_205 , V_207 ) ;
return 0 ;
}
return 1 ;
}
struct V_48 * F_165 ( struct V_25 * V_25 , struct V_48 * V_219 ,
struct V_161 * V_57 ,
struct V_128 * V_128 , int V_172 , int V_221 ,
T_6 * V_222 , void * V_223 )
{
struct V_40 * V_31 = F_24 ( V_25 -> V_41 ) ;
struct V_48 * V_48 ;
struct V_47 * V_224 ;
struct V_47 * V_178 ;
V_48 = F_137 ( V_123 , 1 ) ;
if ( ! V_48 )
return NULL ;
V_48 -> V_225 = V_222 ;
V_48 -> V_186 . V_191 = V_57 -> V_171 >> 9 ;
V_48 -> V_194 = V_31 -> V_226 -> V_227 ;
V_48 -> V_186 . V_187 = 0 ;
V_48 -> V_228 = V_223 ;
V_224 = V_47 ( V_219 ) ;
if ( V_224 -> V_229 ) {
T_7 V_230 = F_166 ( V_31 -> V_231 ) ;
V_178 = V_47 ( V_48 ) ;
V_178 -> V_229 = V_178 -> V_232 ;
V_221 *= V_230 ;
memcpy ( V_178 -> V_229 , V_224 -> V_229 + V_221 ,
V_230 ) ;
}
F_143 ( V_48 , V_128 , V_57 -> V_20 , V_172 ) ;
return V_48 ;
}
static int F_167 ( struct V_48 * V_219 , T_1 V_233 ,
struct V_128 * V_128 , T_1 V_15 , T_1 V_16 ,
int V_207 )
{
struct V_161 * V_57 ;
struct V_25 * V_25 = V_128 -> V_27 -> V_28 ;
struct V_23 * V_24 = & F_18 ( V_25 ) -> V_150 ;
struct V_48 * V_48 ;
int V_234 = 0 ;
int V_36 ;
F_22 ( F_168 ( V_219 ) == V_196 ) ;
V_36 = F_155 ( V_25 , V_15 , V_16 , & V_57 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_164 ( V_25 , V_219 , V_57 , V_207 ) ;
if ( ! V_36 ) {
F_132 ( V_25 , V_57 ) ;
return - V_152 ;
}
if ( V_219 -> V_220 > 1 )
V_234 |= V_235 ;
V_233 >>= V_25 -> V_41 -> V_236 ;
V_48 = F_165 ( V_25 , V_219 , V_57 , V_128 ,
V_15 - F_130 ( V_128 ) ,
( int ) V_233 , V_219 -> V_225 ,
NULL ) ;
if ( ! V_48 ) {
F_132 ( V_25 , V_57 ) ;
return - V_152 ;
}
F_169 ( V_48 , V_237 , V_234 ) ;
F_151 ( F_24 ( V_25 -> V_41 ) ,
L_15 ,
V_234 , V_57 -> V_205 , V_57 -> V_206 ) ;
V_36 = V_24 -> V_53 -> V_238 ( V_25 , V_48 , V_57 -> V_205 ,
V_57 -> V_214 , 0 ) ;
if ( V_36 ) {
F_132 ( V_25 , V_57 ) ;
F_141 ( V_48 ) ;
}
return V_36 ;
}
void F_170 ( struct V_128 * V_128 , int V_99 , T_1 V_15 , T_1 V_16 )
{
int V_239 = ( V_99 == 0 ) ;
struct V_23 * V_24 ;
int V_36 = 0 ;
V_24 = & F_18 ( V_128 -> V_27 -> V_28 ) -> V_150 ;
if ( V_24 -> V_53 && V_24 -> V_53 -> V_240 ) {
V_36 = V_24 -> V_53 -> V_240 ( V_128 , V_15 ,
V_16 , NULL , V_239 ) ;
if ( V_36 )
V_239 = 0 ;
}
if ( ! V_239 ) {
F_171 ( V_128 ) ;
F_122 ( V_128 ) ;
V_36 = V_36 < 0 ? V_36 : - V_152 ;
F_120 ( V_128 -> V_27 , V_36 ) ;
}
}
static void F_172 ( struct V_48 * V_48 )
{
struct V_241 * V_242 ;
T_1 V_15 ;
T_1 V_16 ;
int V_139 ;
F_173 (bvec, bio, i) {
struct V_128 * V_128 = V_242 -> V_243 ;
struct V_25 * V_25 = V_128 -> V_27 -> V_28 ;
struct V_40 * V_31 = F_24 ( V_25 -> V_41 ) ;
if ( V_242 -> V_244 || V_242 -> V_245 != V_29 ) {
if ( V_242 -> V_244 + V_242 -> V_245 != V_29 )
F_174 ( V_31 ,
L_16 ,
V_242 -> V_244 , V_242 -> V_245 ) ;
else
F_175 ( V_31 ,
L_17 ,
V_242 -> V_244 , V_242 -> V_245 ) ;
}
V_15 = F_130 ( V_128 ) ;
V_16 = V_15 + V_242 -> V_244 + V_242 -> V_245 - 1 ;
F_170 ( V_128 , V_48 -> V_246 , V_15 , V_16 ) ;
F_123 ( V_128 ) ;
}
F_141 ( V_48 ) ;
}
static void
F_176 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_20 ,
int V_239 )
{
struct V_1 * V_102 = NULL ;
T_1 V_16 = V_15 + V_20 - 1 ;
if ( V_239 && V_24 -> V_247 )
F_177 ( V_24 , V_15 , V_16 , & V_102 , V_39 ) ;
F_118 ( V_24 , V_15 , V_16 , & V_102 , V_39 ) ;
}
static void F_178 ( struct V_48 * V_48 )
{
struct V_241 * V_242 ;
int V_239 = ! V_48 -> V_246 ;
struct V_47 * V_248 = V_47 ( V_48 ) ;
struct V_23 * V_24 ;
T_1 V_62 = 0 ;
T_1 V_15 ;
T_1 V_16 ;
T_1 V_20 ;
T_1 V_249 = 0 ;
T_1 V_250 = 0 ;
int V_251 ;
int V_36 ;
int V_139 ;
F_173 (bvec, bio, i) {
struct V_128 * V_128 = V_242 -> V_243 ;
struct V_25 * V_25 = V_128 -> V_27 -> V_28 ;
struct V_40 * V_31 = F_24 ( V_25 -> V_41 ) ;
F_151 ( V_31 ,
L_18 ,
( T_1 ) V_48 -> V_186 . V_191 , V_48 -> V_246 ,
V_248 -> V_173 ) ;
V_24 = & F_18 ( V_25 ) -> V_150 ;
if ( V_242 -> V_244 || V_242 -> V_245 != V_29 ) {
if ( V_242 -> V_244 + V_242 -> V_245 != V_29 )
F_174 ( V_31 ,
L_19 ,
V_242 -> V_244 , V_242 -> V_245 ) ;
else
F_175 ( V_31 ,
L_20 ,
V_242 -> V_244 , V_242 -> V_245 ) ;
}
V_15 = F_130 ( V_128 ) ;
V_16 = V_15 + V_242 -> V_244 + V_242 -> V_245 - 1 ;
V_20 = V_242 -> V_245 ;
V_251 = V_248 -> V_173 ;
if ( F_179 ( V_239 && V_24 -> V_53 &&
V_24 -> V_53 -> V_252 ) ) {
V_36 = V_24 -> V_53 -> V_252 ( V_248 , V_62 ,
V_128 , V_15 , V_16 ,
V_251 ) ;
if ( V_36 )
V_239 = 0 ;
else
F_150 ( V_25 , V_15 , V_128 , 0 ) ;
}
if ( F_179 ( V_239 ) )
goto V_253;
if ( V_24 -> V_53 && V_24 -> V_53 -> V_254 ) {
V_36 = V_24 -> V_53 -> V_254 ( V_128 , V_251 ) ;
if ( ! V_36 && ! V_48 -> V_246 )
V_239 = 1 ;
} else {
V_36 = F_167 ( V_48 , V_62 , V_128 , V_15 , V_16 ,
V_251 ) ;
if ( V_36 == 0 ) {
V_239 = ! V_48 -> V_246 ;
V_62 += V_20 ;
continue;
}
}
V_253:
if ( F_179 ( V_239 ) ) {
T_8 V_255 = F_16 ( V_25 ) ;
T_9 V_127 = V_255 >> V_126 ;
unsigned V_256 ;
V_256 = V_255 & ( V_29 - 1 ) ;
if ( V_128 -> V_125 == V_127 && V_256 )
F_180 ( V_128 , V_256 , V_29 ) ;
F_131 ( V_128 ) ;
} else {
F_171 ( V_128 ) ;
F_122 ( V_128 ) ;
}
F_112 ( V_128 ) ;
V_62 += V_20 ;
if ( F_181 ( ! V_239 ) ) {
if ( V_250 ) {
F_176 ( V_24 ,
V_249 ,
V_250 , 1 ) ;
V_249 = 0 ;
V_250 = 0 ;
}
F_176 ( V_24 , V_15 ,
V_16 - V_15 + 1 , 0 ) ;
} else if ( ! V_250 ) {
V_249 = V_15 ;
V_250 = V_16 + 1 - V_15 ;
} else if ( V_249 + V_250 == V_15 ) {
V_250 += V_16 + 1 - V_15 ;
} else {
F_176 ( V_24 , V_249 ,
V_250 , V_239 ) ;
V_249 = V_15 ;
V_250 = V_16 + 1 - V_15 ;
}
}
if ( V_250 )
F_176 ( V_24 , V_249 , V_250 ,
V_239 ) ;
if ( V_248 -> V_257 )
V_248 -> V_257 ( V_248 , V_48 -> V_246 ) ;
F_141 ( V_48 ) ;
}
struct V_48 *
F_182 ( struct V_258 * V_192 , T_1 V_259 , int V_260 ,
T_3 V_261 )
{
struct V_47 * V_178 ;
struct V_48 * V_48 ;
V_48 = F_183 ( V_261 , V_260 , V_45 ) ;
if ( V_48 == NULL && ( V_262 -> V_7 & V_263 ) ) {
while ( ! V_48 && ( V_260 /= 2 ) ) {
V_48 = F_183 ( V_261 ,
V_260 , V_45 ) ;
}
}
if ( V_48 ) {
V_48 -> V_194 = V_192 ;
V_48 -> V_186 . V_191 = V_259 ;
V_178 = V_47 ( V_48 ) ;
V_178 -> V_229 = NULL ;
V_178 -> V_264 = NULL ;
V_178 -> V_257 = NULL ;
}
return V_48 ;
}
struct V_48 * F_184 ( struct V_48 * V_48 , T_3 V_265 )
{
struct V_47 * V_178 ;
struct V_48 * V_5 ;
V_5 = F_185 ( V_48 , V_265 , V_45 ) ;
if ( V_5 ) {
V_178 = V_47 ( V_5 ) ;
V_178 -> V_229 = NULL ;
V_178 -> V_264 = NULL ;
V_178 -> V_257 = NULL ;
}
return V_5 ;
}
struct V_48 * F_137 ( T_3 V_265 , unsigned int V_266 )
{
struct V_47 * V_178 ;
struct V_48 * V_48 ;
V_48 = F_183 ( V_265 , V_266 , V_45 ) ;
if ( V_48 ) {
V_178 = V_47 ( V_48 ) ;
V_178 -> V_229 = NULL ;
V_178 -> V_264 = NULL ;
V_178 -> V_257 = NULL ;
}
return V_48 ;
}
static int T_4 F_186 ( struct V_48 * V_48 , int V_173 ,
unsigned long V_214 )
{
int V_36 = 0 ;
struct V_241 * V_242 = V_48 -> V_267 + V_48 -> V_220 - 1 ;
struct V_128 * V_128 = V_242 -> V_243 ;
struct V_23 * V_24 = V_48 -> V_228 ;
T_1 V_15 ;
V_15 = F_130 ( V_128 ) + V_242 -> V_244 ;
V_48 -> V_228 = NULL ;
F_187 ( V_48 ) ;
if ( V_24 -> V_53 && V_24 -> V_53 -> V_238 )
V_36 = V_24 -> V_53 -> V_238 ( V_128 -> V_27 -> V_28 , V_48 ,
V_173 , V_214 , V_15 ) ;
else
F_188 ( V_48 ) ;
F_141 ( V_48 ) ;
return V_36 ;
}
static int F_189 ( struct V_23 * V_24 , struct V_128 * V_128 ,
unsigned long V_62 , T_10 V_268 , struct V_48 * V_48 ,
unsigned long V_214 )
{
int V_36 = 0 ;
if ( V_24 -> V_53 && V_24 -> V_53 -> V_269 )
V_36 = V_24 -> V_53 -> V_269 ( V_128 , V_62 , V_268 , V_48 ,
V_214 ) ;
return V_36 ;
}
static int F_190 ( int V_270 , int V_271 , struct V_23 * V_24 ,
struct V_272 * V_273 ,
struct V_128 * V_128 , T_11 V_177 ,
T_10 V_268 , unsigned long V_62 ,
struct V_258 * V_192 ,
struct V_48 * * V_274 ,
unsigned long V_275 ,
T_6 V_276 ,
int V_173 ,
unsigned long V_277 ,
unsigned long V_214 ,
bool V_278 )
{
int V_36 = 0 ;
struct V_48 * V_48 ;
int V_159 = 0 ;
int V_279 = V_277 & V_217 ;
T_10 V_280 = F_111 ( T_10 , V_268 , V_29 ) ;
if ( V_274 && * V_274 ) {
V_48 = * V_274 ;
if ( V_279 )
V_159 = V_48 -> V_186 . V_191 == V_177 ;
else
V_159 = F_191 ( V_48 ) == V_177 ;
if ( V_277 != V_214 || ! V_159 ||
V_278 ||
F_189 ( V_24 , V_128 , V_62 , V_280 , V_48 , V_214 ) ||
F_143 ( V_48 , V_128 , V_280 , V_62 ) < V_280 ) {
V_36 = F_186 ( V_48 , V_173 , V_277 ) ;
if ( V_36 < 0 ) {
* V_274 = NULL ;
return V_36 ;
}
V_48 = NULL ;
} else {
if ( V_273 )
F_192 ( V_273 , V_128 , V_280 ) ;
return 0 ;
}
}
V_48 = F_182 ( V_192 , V_177 , V_281 ,
V_123 | V_282 ) ;
if ( ! V_48 )
return - V_43 ;
F_143 ( V_48 , V_128 , V_280 , V_62 ) ;
V_48 -> V_225 = V_276 ;
V_48 -> V_228 = V_24 ;
F_169 ( V_48 , V_270 , V_271 ) ;
if ( V_273 ) {
F_193 ( V_273 , V_48 ) ;
F_192 ( V_273 , V_128 , V_280 ) ;
}
if ( V_274 )
* V_274 = V_48 ;
else
V_36 = F_186 ( V_48 , V_173 , V_214 ) ;
return V_36 ;
}
static void F_194 ( struct V_10 * V_11 ,
struct V_128 * V_128 )
{
if ( ! F_195 ( V_128 ) ) {
F_196 ( V_128 ) ;
F_197 ( V_128 ) ;
F_198 ( V_128 , ( unsigned long ) V_11 ) ;
} else {
F_44 ( V_128 -> V_203 != ( unsigned long ) V_11 ) ;
}
}
void F_199 ( struct V_128 * V_128 )
{
if ( ! F_195 ( V_128 ) ) {
F_196 ( V_128 ) ;
F_197 ( V_128 ) ;
F_198 ( V_128 , V_283 ) ;
}
}
static struct V_209 *
F_200 ( struct V_25 * V_25 , struct V_128 * V_128 , T_10 V_172 ,
T_1 V_15 , T_1 V_20 , T_12 * V_284 ,
struct V_209 * * V_285 )
{
struct V_209 * V_210 ;
if ( V_285 && * V_285 ) {
V_210 = * V_285 ;
if ( F_201 ( V_210 ) && V_15 >= V_210 -> V_15 &&
V_15 < F_202 ( V_210 ) ) {
F_85 ( & V_210 -> V_17 ) ;
return V_210 ;
}
F_160 ( V_210 ) ;
* V_285 = NULL ;
}
V_210 = V_284 ( V_25 , V_128 , V_172 , V_15 , V_20 , 0 ) ;
if ( V_285 && ! F_203 ( V_210 ) ) {
F_22 ( * V_285 ) ;
F_85 ( & V_210 -> V_17 ) ;
* V_285 = V_210 ;
}
return V_210 ;
}
static int F_204 ( struct V_23 * V_24 ,
struct V_128 * V_128 ,
T_12 * V_284 ,
struct V_209 * * V_285 ,
struct V_48 * * V_48 , int V_173 ,
unsigned long * V_214 , int V_286 ,
T_1 * V_287 )
{
struct V_25 * V_25 = V_128 -> V_27 -> V_28 ;
T_1 V_15 = F_130 ( V_128 ) ;
T_1 V_288 = V_15 + V_29 - 1 ;
T_1 V_16 ;
T_1 V_289 = V_15 ;
T_1 V_290 ;
T_1 V_291 = F_16 ( V_25 ) ;
T_1 V_215 ;
T_1 V_292 ;
T_11 V_177 ;
struct V_209 * V_210 ;
struct V_258 * V_192 ;
int V_36 = 0 ;
int V_293 = 0 ;
T_10 V_172 = 0 ;
T_10 V_294 ;
T_10 V_295 ;
T_10 V_296 = V_25 -> V_41 -> V_297 ;
unsigned long V_298 = 0 ;
F_199 ( V_128 ) ;
V_16 = V_288 ;
if ( ! F_205 ( V_128 ) ) {
if ( F_206 ( V_128 ) == 0 ) {
F_22 ( V_296 != V_29 ) ;
F_207 ( V_24 , V_15 , V_16 ) ;
goto V_110;
}
}
if ( V_128 -> V_125 == V_291 >> V_126 ) {
char * V_299 ;
T_10 V_300 = V_291 & ( V_29 - 1 ) ;
if ( V_300 ) {
V_294 = V_29 - V_300 ;
V_299 = F_208 ( V_128 ) ;
memset ( V_299 + V_300 , 0 , V_294 ) ;
F_209 ( V_128 ) ;
F_210 ( V_299 ) ;
}
}
while ( V_289 <= V_16 ) {
unsigned long V_301 = ( V_291 >> V_126 ) + 1 ;
bool V_278 = false ;
if ( V_289 >= V_291 ) {
char * V_299 ;
struct V_1 * V_102 = NULL ;
V_294 = V_29 - V_172 ;
V_299 = F_208 ( V_128 ) ;
memset ( V_299 + V_172 , 0 , V_294 ) ;
F_209 ( V_128 ) ;
F_210 ( V_299 ) ;
F_177 ( V_24 , V_289 , V_289 + V_294 - 1 ,
& V_102 , V_123 ) ;
F_118 ( V_24 , V_289 ,
V_289 + V_294 - 1 ,
& V_102 , V_123 ) ;
break;
}
V_210 = F_200 ( V_25 , V_128 , V_172 , V_289 ,
V_16 - V_289 + 1 , V_284 , V_285 ) ;
if ( F_203 ( V_210 ) ) {
F_122 ( V_128 ) ;
F_207 ( V_24 , V_289 , V_16 ) ;
break;
}
V_290 = V_289 - V_210 -> V_15 ;
F_22 ( F_202 ( V_210 ) <= V_289 ) ;
F_22 ( V_16 < V_289 ) ;
if ( F_161 ( V_216 , & V_210 -> V_7 ) ) {
V_298 |= V_217 ;
F_162 ( & V_298 ,
V_210 -> V_218 ) ;
}
V_294 = F_125 ( F_202 ( V_210 ) - V_289 , V_16 - V_289 + 1 ) ;
V_292 = F_125 ( F_202 ( V_210 ) - 1 , V_16 ) ;
V_294 = F_211 ( V_294 , V_296 ) ;
if ( V_298 & V_217 ) {
V_295 = V_210 -> V_302 ;
V_177 = V_210 -> V_215 >> 9 ;
} else {
V_177 = ( V_210 -> V_215 + V_290 ) >> 9 ;
V_295 = V_294 ;
}
V_192 = V_210 -> V_192 ;
V_215 = V_210 -> V_215 ;
if ( F_161 ( V_303 , & V_210 -> V_7 ) )
V_215 = V_304 ;
if ( F_161 ( V_216 , & V_210 -> V_7 ) &&
V_287 && * V_287 != ( T_1 ) - 1 &&
* V_287 != V_210 -> V_305 )
V_278 = true ;
if ( V_287 )
* V_287 = V_210 -> V_305 ;
F_160 ( V_210 ) ;
V_210 = NULL ;
if ( V_215 == V_304 ) {
char * V_299 ;
struct V_1 * V_102 = NULL ;
V_299 = F_208 ( V_128 ) ;
memset ( V_299 + V_172 , 0 , V_294 ) ;
F_209 ( V_128 ) ;
F_210 ( V_299 ) ;
F_177 ( V_24 , V_289 , V_289 + V_294 - 1 ,
& V_102 , V_123 ) ;
F_118 ( V_24 , V_289 ,
V_289 + V_294 - 1 ,
& V_102 , V_123 ) ;
V_289 = V_289 + V_294 ;
V_172 += V_294 ;
continue;
}
if ( F_117 ( V_24 , V_289 , V_292 ,
V_165 , 1 , NULL ) ) {
F_129 ( V_24 , V_128 ) ;
F_207 ( V_24 , V_289 , V_289 + V_294 - 1 ) ;
V_289 = V_289 + V_294 ;
V_172 += V_294 ;
continue;
}
if ( V_215 == V_306 ) {
F_122 ( V_128 ) ;
F_207 ( V_24 , V_289 , V_289 + V_294 - 1 ) ;
V_289 = V_289 + V_294 ;
V_172 += V_294 ;
continue;
}
V_301 -= V_128 -> V_125 ;
V_36 = F_190 ( V_237 , V_286 , V_24 , NULL ,
V_128 , V_177 , V_295 , V_172 ,
V_192 , V_48 , V_301 ,
F_178 , V_173 ,
* V_214 ,
V_298 ,
V_278 ) ;
if ( ! V_36 ) {
V_293 ++ ;
* V_214 = V_298 ;
} else {
F_122 ( V_128 ) ;
F_207 ( V_24 , V_289 , V_289 + V_294 - 1 ) ;
goto V_110;
}
V_289 = V_289 + V_294 ;
V_172 += V_294 ;
}
V_110:
if ( ! V_293 ) {
if ( ! F_212 ( V_128 ) )
F_131 ( V_128 ) ;
F_112 ( V_128 ) ;
}
return V_36 ;
}
static inline void F_213 ( struct V_23 * V_24 ,
struct V_128 * V_137 [] , int V_138 ,
T_1 V_15 , T_1 V_16 ,
T_12 * V_284 ,
struct V_209 * * V_285 ,
struct V_48 * * V_48 , int V_173 ,
unsigned long * V_214 ,
T_1 * V_287 )
{
struct V_25 * V_25 ;
struct V_307 * V_308 ;
int V_125 ;
V_25 = V_137 [ 0 ] -> V_27 -> V_28 ;
while ( 1 ) {
F_214 ( V_24 , V_15 , V_16 ) ;
V_308 = F_215 ( V_25 , V_15 ,
V_16 - V_15 + 1 ) ;
if ( ! V_308 )
break;
F_207 ( V_24 , V_15 , V_16 ) ;
F_216 ( V_25 , V_308 , 1 ) ;
F_217 ( V_308 ) ;
}
for ( V_125 = 0 ; V_125 < V_138 ; V_125 ++ ) {
F_204 ( V_24 , V_137 [ V_125 ] , V_284 , V_285 , V_48 ,
V_173 , V_214 , 0 , V_287 ) ;
F_100 ( V_137 [ V_125 ] ) ;
}
}
static void F_218 ( struct V_23 * V_24 ,
struct V_128 * V_137 [] ,
int V_138 , T_12 * V_284 ,
struct V_209 * * V_285 ,
struct V_48 * * V_48 , int V_173 ,
unsigned long * V_214 ,
T_1 * V_287 )
{
T_1 V_15 = 0 ;
T_1 V_16 = 0 ;
T_1 V_309 ;
int V_125 ;
int V_310 = 0 ;
for ( V_125 = 0 ; V_125 < V_138 ; V_125 ++ ) {
V_309 = F_130 ( V_137 [ V_125 ] ) ;
if ( ! V_16 ) {
V_15 = V_309 ;
V_16 = V_15 + V_29 - 1 ;
V_310 = V_125 ;
} else if ( V_16 + 1 == V_309 ) {
V_16 += V_29 ;
} else {
F_213 ( V_24 , & V_137 [ V_310 ] ,
V_125 - V_310 , V_15 ,
V_16 , V_284 , V_285 ,
V_48 , V_173 , V_214 ,
V_287 ) ;
V_15 = V_309 ;
V_16 = V_15 + V_29 - 1 ;
V_310 = V_125 ;
}
}
if ( V_16 )
F_213 ( V_24 , & V_137 [ V_310 ] ,
V_125 - V_310 , V_15 ,
V_16 , V_284 , V_285 , V_48 ,
V_173 , V_214 ,
V_287 ) ;
}
static int F_219 ( struct V_23 * V_24 ,
struct V_128 * V_128 ,
T_12 * V_284 ,
struct V_48 * * V_48 , int V_173 ,
unsigned long * V_214 , int V_286 )
{
struct V_25 * V_25 = V_128 -> V_27 -> V_28 ;
struct V_307 * V_308 ;
T_1 V_15 = F_130 ( V_128 ) ;
T_1 V_16 = V_15 + V_29 - 1 ;
int V_36 ;
while ( 1 ) {
F_214 ( V_24 , V_15 , V_16 ) ;
V_308 = F_215 ( V_25 , V_15 ,
V_29 ) ;
if ( ! V_308 )
break;
F_207 ( V_24 , V_15 , V_16 ) ;
F_216 ( V_25 , V_308 , 1 ) ;
F_217 ( V_308 ) ;
}
V_36 = F_204 ( V_24 , V_128 , V_284 , NULL , V_48 , V_173 ,
V_214 , V_286 , NULL ) ;
return V_36 ;
}
int F_220 ( struct V_23 * V_24 , struct V_128 * V_128 ,
T_12 * V_284 , int V_173 )
{
struct V_48 * V_48 = NULL ;
unsigned long V_214 = 0 ;
int V_36 ;
V_36 = F_219 ( V_24 , V_128 , V_284 , & V_48 , V_173 ,
& V_214 , 0 ) ;
if ( V_48 )
V_36 = F_186 ( V_48 , V_173 , V_214 ) ;
return V_36 ;
}
static void F_221 ( struct V_128 * V_128 , struct V_272 * V_273 ,
unsigned long V_311 )
{
V_273 -> V_312 -= V_311 ;
}
static T_13 int F_222 ( struct V_25 * V_25 ,
struct V_128 * V_128 , struct V_272 * V_273 ,
struct V_313 * V_314 ,
T_1 V_140 ,
unsigned long * V_311 )
{
struct V_23 * V_24 = V_314 -> V_24 ;
T_1 V_288 = V_140 + V_29 - 1 ;
T_1 V_315 ;
T_1 V_316 = 0 ;
T_1 V_141 = 0 ;
int V_36 ;
int V_317 = 0 ;
if ( V_314 -> V_318 || ! V_24 -> V_53 || ! V_24 -> V_53 -> V_319 )
return 0 ;
while ( V_141 < V_288 ) {
V_315 = F_116 ( V_25 , V_24 ,
V_128 ,
& V_140 ,
& V_141 ,
V_320 ) ;
if ( V_315 == 0 ) {
V_140 = V_141 + 1 ;
continue;
}
V_36 = V_24 -> V_53 -> V_319 ( V_25 , V_128 ,
V_140 ,
V_141 ,
& V_317 ,
V_311 ) ;
if ( V_36 ) {
F_122 ( V_128 ) ;
V_36 = V_36 < 0 ? V_36 : - V_152 ;
goto V_146;
}
V_316 += ( V_141 - V_140 +
V_29 ) >> V_126 ;
V_140 = V_141 + 1 ;
}
if ( V_273 -> V_312 < V_316 ) {
int V_321 = 8192 ;
if ( V_316 < V_321 * 2 )
V_321 = V_316 ;
V_273 -> V_312 = F_111 ( T_1 , V_316 ,
V_321 ) ;
}
if ( V_317 ) {
V_273 -> V_312 -= * V_311 ;
return 1 ;
}
V_36 = 0 ;
V_146:
return V_36 ;
}
static T_13 int F_223 ( struct V_25 * V_25 ,
struct V_128 * V_128 ,
struct V_272 * V_273 ,
struct V_313 * V_314 ,
T_8 V_255 ,
unsigned long V_311 ,
int V_322 , int * V_323 )
{
struct V_23 * V_24 = V_314 -> V_24 ;
T_1 V_15 = F_130 ( V_128 ) ;
T_1 V_288 = V_15 + V_29 - 1 ;
T_1 V_16 ;
T_1 V_289 = V_15 ;
T_1 V_290 ;
T_1 V_215 ;
T_1 V_294 ;
T_11 V_177 ;
struct V_1 * V_101 = NULL ;
struct V_209 * V_210 ;
struct V_258 * V_192 ;
T_10 V_172 = 0 ;
T_10 V_296 ;
int V_36 = 0 ;
int V_293 = 0 ;
bool V_324 ;
if ( V_24 -> V_53 && V_24 -> V_53 -> V_325 ) {
V_36 = V_24 -> V_53 -> V_325 ( V_128 , V_15 ,
V_288 ) ;
if ( V_36 ) {
if ( V_36 == - V_326 )
V_273 -> V_327 ++ ;
else
F_224 ( V_273 , V_128 ) ;
F_221 ( V_128 , V_273 , V_311 ) ;
F_112 ( V_128 ) ;
V_36 = 1 ;
goto V_328;
}
}
F_221 ( V_128 , V_273 , V_311 + 1 ) ;
V_16 = V_288 ;
if ( V_255 <= V_15 ) {
if ( V_24 -> V_53 && V_24 -> V_53 -> V_240 )
V_24 -> V_53 -> V_240 ( V_128 , V_15 ,
V_288 , NULL , 1 ) ;
goto V_146;
}
V_296 = V_25 -> V_41 -> V_297 ;
while ( V_289 <= V_16 ) {
T_1 V_329 ;
unsigned long V_330 ;
if ( V_289 >= V_255 ) {
if ( V_24 -> V_53 && V_24 -> V_53 -> V_240 )
V_24 -> V_53 -> V_240 ( V_128 , V_289 ,
V_288 , NULL , 1 ) ;
break;
}
V_210 = V_314 -> V_284 ( V_25 , V_128 , V_172 , V_289 ,
V_16 - V_289 + 1 , 1 ) ;
if ( F_203 ( V_210 ) ) {
F_122 ( V_128 ) ;
V_36 = F_225 ( V_210 ) ;
break;
}
V_290 = V_289 - V_210 -> V_15 ;
V_329 = F_202 ( V_210 ) ;
F_22 ( V_329 <= V_289 ) ;
F_22 ( V_16 < V_289 ) ;
V_294 = F_125 ( V_329 - V_289 , V_16 - V_289 + 1 ) ;
V_294 = F_211 ( V_294 , V_296 ) ;
V_177 = ( V_210 -> V_215 + V_290 ) >> 9 ;
V_192 = V_210 -> V_192 ;
V_215 = V_210 -> V_215 ;
V_324 = F_161 ( V_216 , & V_210 -> V_7 ) ;
F_160 ( V_210 ) ;
V_210 = NULL ;
if ( V_324 || V_215 == V_304 ||
V_215 == V_306 ) {
if ( ! V_324 && V_24 -> V_53 &&
V_24 -> V_53 -> V_240 )
V_24 -> V_53 -> V_240 ( V_128 , V_289 ,
V_289 + V_294 - 1 ,
NULL , 1 ) ;
else if ( V_324 ) {
V_293 ++ ;
}
V_289 += V_294 ;
V_172 += V_294 ;
continue;
}
V_330 = ( V_255 >> V_126 ) + 1 ;
F_104 ( V_24 , V_289 , V_289 + V_294 - 1 ) ;
if ( ! F_226 ( V_128 ) ) {
F_174 ( F_18 ( V_25 ) -> V_30 -> V_31 ,
L_21 ,
V_128 -> V_125 , V_289 , V_16 ) ;
}
V_36 = F_190 ( V_196 , V_322 , V_24 , V_273 ,
V_128 , V_177 , V_294 , V_172 ,
V_192 , & V_314 -> V_48 , V_330 ,
F_172 ,
0 , 0 , 0 , false ) ;
if ( V_36 )
F_122 ( V_128 ) ;
V_289 = V_289 + V_294 ;
V_172 += V_294 ;
V_293 ++ ;
}
V_146:
* V_323 = V_293 ;
V_328:
F_42 ( V_101 ) ;
return V_36 ;
}
static int F_227 ( struct V_128 * V_128 , struct V_272 * V_273 ,
void * V_223 )
{
struct V_25 * V_25 = V_128 -> V_27 -> V_28 ;
struct V_313 * V_314 = V_223 ;
T_1 V_15 = F_130 ( V_128 ) ;
T_1 V_288 = V_15 + V_29 - 1 ;
int V_36 ;
int V_293 = 0 ;
T_10 V_172 = 0 ;
T_8 V_255 = F_16 ( V_25 ) ;
unsigned long V_127 = V_255 >> V_126 ;
int V_322 = 0 ;
unsigned long V_311 = 0 ;
if ( V_273 -> V_331 == V_332 )
V_322 = V_197 ;
F_228 ( V_128 , V_25 , V_273 ) ;
F_44 ( ! F_229 ( V_128 ) ) ;
F_230 ( V_128 ) ;
V_172 = V_255 & ( V_29 - 1 ) ;
if ( V_128 -> V_125 > V_127 ||
( V_128 -> V_125 == V_127 && ! V_172 ) ) {
V_128 -> V_27 -> V_333 -> V_334 ( V_128 , 0 , V_29 ) ;
F_112 ( V_128 ) ;
return 0 ;
}
if ( V_128 -> V_125 == V_127 ) {
char * V_299 ;
V_299 = F_208 ( V_128 ) ;
memset ( V_299 + V_172 , 0 ,
V_29 - V_172 ) ;
F_210 ( V_299 ) ;
F_209 ( V_128 ) ;
}
V_172 = 0 ;
F_199 ( V_128 ) ;
V_36 = F_222 ( V_25 , V_128 , V_273 , V_314 , V_15 , & V_311 ) ;
if ( V_36 == 1 )
goto V_328;
if ( V_36 )
goto V_146;
V_36 = F_223 ( V_25 , V_128 , V_273 , V_314 ,
V_255 , V_311 , V_322 , & V_293 ) ;
if ( V_36 == 1 )
goto V_328;
V_146:
if ( V_293 == 0 ) {
F_105 ( V_128 ) ;
F_123 ( V_128 ) ;
}
if ( F_212 ( V_128 ) ) {
V_36 = V_36 < 0 ? V_36 : - V_152 ;
F_170 ( V_128 , V_36 , V_15 , V_288 ) ;
}
F_112 ( V_128 ) ;
return V_36 ;
V_328:
return 0 ;
}
void F_231 ( struct V_10 * V_11 )
{
F_232 ( & V_11 -> V_335 , V_336 ,
V_113 ) ;
}
static T_13 int
F_233 ( struct V_10 * V_11 ,
struct V_40 * V_31 ,
struct V_313 * V_314 )
{
unsigned long V_139 , V_200 ;
int V_337 = 0 ;
int V_36 = 0 ;
if ( ! F_234 ( V_11 ) ) {
V_337 = 1 ;
F_235 ( V_314 ) ;
F_236 ( V_11 ) ;
}
if ( F_161 ( V_336 , & V_11 -> V_335 ) ) {
F_237 ( V_11 ) ;
if ( ! V_314 -> V_338 )
return 0 ;
if ( ! V_337 ) {
F_235 ( V_314 ) ;
V_337 = 1 ;
}
while ( 1 ) {
F_231 ( V_11 ) ;
F_236 ( V_11 ) ;
if ( ! F_161 ( V_336 , & V_11 -> V_335 ) )
break;
F_237 ( V_11 ) ;
}
}
F_74 ( & V_11 -> V_339 ) ;
if ( F_238 ( V_340 , & V_11 -> V_335 ) ) {
F_239 ( V_336 , & V_11 -> V_335 ) ;
F_77 ( & V_11 -> V_339 ) ;
F_240 ( V_11 , V_341 ) ;
F_241 ( & V_31 -> V_342 ,
- V_11 -> V_20 ,
V_31 -> V_343 ) ;
V_36 = 1 ;
} else {
F_77 ( & V_11 -> V_339 ) ;
}
F_237 ( V_11 ) ;
if ( ! V_36 )
return V_36 ;
V_200 = F_149 ( V_11 -> V_15 , V_11 -> V_20 ) ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
struct V_128 * V_66 = V_11 -> V_137 [ V_139 ] ;
if ( ! F_242 ( V_66 ) ) {
if ( ! V_337 ) {
F_235 ( V_314 ) ;
V_337 = 1 ;
}
F_114 ( V_66 ) ;
}
}
return V_36 ;
}
static void F_243 ( struct V_10 * V_11 )
{
F_244 ( V_336 , & V_11 -> V_335 ) ;
F_245 () ;
F_246 ( & V_11 -> V_335 , V_336 ) ;
}
static void F_247 ( struct V_128 * V_128 )
{
struct V_10 * V_11 = (struct V_10 * ) V_128 -> V_203 ;
F_122 ( V_128 ) ;
if ( F_248 ( V_344 , & V_11 -> V_335 ) )
return;
switch ( V_11 -> V_345 ) {
case - 1 :
F_239 ( V_346 , & V_11 -> V_31 -> V_7 ) ;
break;
case 0 :
F_239 ( V_347 , & V_11 -> V_31 -> V_7 ) ;
break;
case 1 :
F_239 ( V_348 , & V_11 -> V_31 -> V_7 ) ;
break;
default:
F_249 () ;
}
}
static void F_250 ( struct V_48 * V_48 )
{
struct V_241 * V_242 ;
struct V_10 * V_11 ;
int V_139 , V_146 ;
F_173 (bvec, bio, i) {
struct V_128 * V_128 = V_242 -> V_243 ;
V_11 = (struct V_10 * ) V_128 -> V_203 ;
F_22 ( ! V_11 ) ;
V_146 = F_43 ( & V_11 -> V_349 ) ;
if ( V_48 -> V_246 ||
F_161 ( V_344 , & V_11 -> V_335 ) ) {
F_171 ( V_128 ) ;
F_247 ( V_128 ) ;
}
F_123 ( V_128 ) ;
if ( ! V_146 )
continue;
F_243 ( V_11 ) ;
}
F_141 ( V_48 ) ;
}
static T_13 int F_251 ( struct V_10 * V_11 ,
struct V_40 * V_31 ,
struct V_272 * V_273 ,
struct V_313 * V_314 )
{
struct V_258 * V_192 = V_31 -> V_226 -> V_227 ;
struct V_23 * V_24 = & F_18 ( V_31 -> V_202 ) -> V_150 ;
T_1 V_62 = V_11 -> V_15 ;
T_14 V_350 ;
unsigned long V_139 , V_200 ;
unsigned long V_214 = 0 ;
unsigned long V_15 , V_16 ;
int V_322 = ( V_314 -> V_338 ? V_197 : 0 ) | V_351 ;
int V_36 = 0 ;
F_244 ( V_344 , & V_11 -> V_335 ) ;
V_200 = F_149 ( V_11 -> V_15 , V_11 -> V_20 ) ;
F_39 ( & V_11 -> V_349 , V_200 ) ;
if ( F_252 ( V_11 ) == V_352 )
V_214 = V_353 ;
V_350 = F_253 ( V_11 ) ;
if ( F_254 ( V_11 ) > 0 ) {
V_16 = F_255 ( V_350 ) ;
F_256 ( V_11 , V_16 , V_11 -> V_20 - V_16 ) ;
} else {
V_15 = F_257 ( V_350 ) ;
V_16 = F_258 ( V_11 ) + F_259 ( V_31 , V_11 ) ;
F_256 ( V_11 , V_15 , V_16 - V_15 ) ;
}
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
struct V_128 * V_66 = V_11 -> V_137 [ V_139 ] ;
F_99 ( V_66 ) ;
F_105 ( V_66 ) ;
V_36 = F_190 ( V_196 , V_322 , V_24 , V_273 ,
V_66 , V_62 >> 9 , V_29 , 0 , V_192 ,
& V_314 -> V_48 , - 1 ,
F_250 ,
0 , V_314 -> V_214 , V_214 , false ) ;
V_314 -> V_214 = V_214 ;
if ( V_36 ) {
F_247 ( V_66 ) ;
F_123 ( V_66 ) ;
if ( F_260 ( V_200 - V_139 , & V_11 -> V_349 ) )
F_243 ( V_11 ) ;
V_36 = - V_152 ;
break;
}
V_62 += V_29 ;
F_221 ( V_66 , V_273 , 1 ) ;
F_112 ( V_66 ) ;
}
if ( F_181 ( V_36 ) ) {
for (; V_139 < V_200 ; V_139 ++ ) {
struct V_128 * V_66 = V_11 -> V_137 [ V_139 ] ;
F_99 ( V_66 ) ;
F_112 ( V_66 ) ;
}
}
return V_36 ;
}
int F_261 ( struct V_51 * V_27 ,
struct V_272 * V_273 )
{
struct V_23 * V_24 = & F_18 ( V_27 -> V_28 ) -> V_150 ;
struct V_40 * V_31 = F_18 ( V_27 -> V_28 ) -> V_30 -> V_31 ;
struct V_10 * V_11 , * V_354 = NULL ;
struct V_313 V_314 = {
. V_48 = NULL ,
. V_24 = V_24 ,
. V_318 = 0 ,
. V_338 = V_273 -> V_331 == V_332 ,
. V_214 = 0 ,
} ;
int V_36 = 0 ;
int V_146 = 0 ;
int V_355 = 0 ;
struct V_356 V_357 ;
int V_138 ;
T_9 V_125 ;
T_9 V_16 ;
int V_358 = 0 ;
int V_359 ;
F_262 ( & V_357 , 0 ) ;
if ( V_273 -> V_360 ) {
V_125 = V_27 -> V_361 ;
V_16 = - 1 ;
} else {
V_125 = V_273 -> V_362 >> V_126 ;
V_16 = V_273 -> V_363 >> V_126 ;
V_358 = 1 ;
}
if ( V_273 -> V_331 == V_332 )
V_359 = V_364 ;
else
V_359 = V_365 ;
V_366:
if ( V_273 -> V_331 == V_332 )
F_263 ( V_27 , V_125 , V_16 ) ;
while ( ! V_146 && ! V_355 && ( V_125 <= V_16 ) &&
( V_138 = F_264 ( & V_357 , V_27 , & V_125 , V_359 ,
F_125 ( V_16 - V_125 , ( T_9 ) V_367 - 1 ) + 1 ) ) ) {
unsigned V_139 ;
V_358 = 1 ;
for ( V_139 = 0 ; V_139 < V_138 ; V_139 ++ ) {
struct V_128 * V_128 = V_357 . V_137 [ V_139 ] ;
if ( ! F_195 ( V_128 ) )
continue;
if ( ! V_273 -> V_360 && V_128 -> V_125 > V_16 ) {
V_146 = 1 ;
break;
}
F_74 ( & V_27 -> V_368 ) ;
if ( ! F_195 ( V_128 ) ) {
F_77 ( & V_27 -> V_368 ) ;
continue;
}
V_11 = (struct V_10 * ) V_128 -> V_203 ;
if ( F_44 ( ! V_11 ) ) {
F_77 ( & V_27 -> V_368 ) ;
continue;
}
if ( V_11 == V_354 ) {
F_77 ( & V_27 -> V_368 ) ;
continue;
}
V_36 = F_265 ( & V_11 -> V_17 ) ;
F_77 ( & V_27 -> V_368 ) ;
if ( ! V_36 )
continue;
V_354 = V_11 ;
V_36 = F_233 ( V_11 , V_31 , & V_314 ) ;
if ( ! V_36 ) {
F_266 ( V_11 ) ;
continue;
}
V_36 = F_251 ( V_11 , V_31 , V_273 , & V_314 ) ;
if ( V_36 ) {
V_146 = 1 ;
F_266 ( V_11 ) ;
break;
}
F_266 ( V_11 ) ;
V_355 = V_273 -> V_312 <= 0 ;
}
F_267 ( & V_357 ) ;
F_78 () ;
}
if ( ! V_358 && ! V_146 ) {
V_358 = 1 ;
V_125 = 0 ;
goto V_366;
}
F_235 ( & V_314 ) ;
return V_36 ;
}
static int F_268 ( struct V_23 * V_24 ,
struct V_51 * V_27 ,
struct V_272 * V_273 ,
T_15 V_369 , void * V_223 ,
void (* F_269)( void * ) )
{
struct V_25 * V_25 = V_27 -> V_28 ;
int V_36 = 0 ;
int V_146 = 0 ;
int V_355 = 0 ;
struct V_356 V_357 ;
int V_138 ;
T_9 V_125 ;
T_9 V_16 ;
T_9 V_370 ;
int V_371 = 0 ;
int V_358 = 0 ;
int V_359 ;
if ( ! F_270 ( V_25 ) )
return 0 ;
F_262 ( & V_357 , 0 ) ;
if ( V_273 -> V_360 ) {
V_125 = V_27 -> V_361 ;
V_16 = - 1 ;
} else {
V_125 = V_273 -> V_362 >> V_126 ;
V_16 = V_273 -> V_363 >> V_126 ;
if ( V_273 -> V_362 == 0 && V_273 -> V_363 == V_372 )
V_371 = 1 ;
V_358 = 1 ;
}
if ( V_273 -> V_331 == V_332 )
V_359 = V_364 ;
else
V_359 = V_365 ;
V_366:
if ( V_273 -> V_331 == V_332 )
F_263 ( V_27 , V_125 , V_16 ) ;
V_370 = V_125 ;
while ( ! V_146 && ! V_355 && ( V_125 <= V_16 ) &&
( V_138 = F_264 ( & V_357 , V_27 , & V_125 , V_359 ,
F_125 ( V_16 - V_125 , ( T_9 ) V_367 - 1 ) + 1 ) ) ) {
unsigned V_139 ;
V_358 = 1 ;
for ( V_139 = 0 ; V_139 < V_138 ; V_139 ++ ) {
struct V_128 * V_128 = V_357 . V_137 [ V_139 ] ;
V_370 = V_128 -> V_125 ;
if ( ! F_242 ( V_128 ) ) {
F_269 ( V_223 ) ;
F_114 ( V_128 ) ;
}
if ( F_181 ( V_128 -> V_27 != V_27 ) ) {
F_112 ( V_128 ) ;
continue;
}
if ( ! V_273 -> V_360 && V_128 -> V_125 > V_16 ) {
V_146 = 1 ;
F_112 ( V_128 ) ;
continue;
}
if ( V_273 -> V_331 != V_373 ) {
if ( F_226 ( V_128 ) )
F_269 ( V_223 ) ;
F_271 ( V_128 ) ;
}
if ( F_226 ( V_128 ) ||
! F_99 ( V_128 ) ) {
F_112 ( V_128 ) ;
continue;
}
V_36 = (* V_369)( V_128 , V_273 , V_223 ) ;
if ( F_181 ( V_36 == V_374 ) ) {
F_112 ( V_128 ) ;
V_36 = 0 ;
}
if ( V_36 < 0 ) {
V_370 = V_128 -> V_125 + 1 ;
V_146 = 1 ;
break;
}
V_355 = V_273 -> V_312 <= 0 ;
}
F_267 ( & V_357 ) ;
F_78 () ;
}
if ( ! V_358 && ! V_146 ) {
V_358 = 1 ;
V_125 = 0 ;
goto V_366;
}
if ( V_273 -> V_360 || ( V_273 -> V_312 > 0 && V_371 ) )
V_27 -> V_361 = V_370 ;
F_272 ( V_25 ) ;
return V_36 ;
}
static void F_273 ( struct V_313 * V_314 )
{
if ( V_314 -> V_48 ) {
int V_36 ;
F_169 ( V_314 -> V_48 , V_196 ,
V_314 -> V_338 ? V_197 : 0 ) ;
V_36 = F_186 ( V_314 -> V_48 , 0 , V_314 -> V_214 ) ;
F_22 ( V_36 < 0 ) ;
V_314 -> V_48 = NULL ;
}
}
static T_5 void F_235 ( void * V_223 )
{
struct V_313 * V_314 = V_223 ;
F_273 ( V_314 ) ;
}
int F_274 ( struct V_23 * V_24 , struct V_128 * V_128 ,
T_12 * V_284 ,
struct V_272 * V_273 )
{
int V_36 ;
struct V_313 V_314 = {
. V_48 = NULL ,
. V_24 = V_24 ,
. V_284 = V_284 ,
. V_318 = 0 ,
. V_338 = V_273 -> V_331 == V_332 ,
. V_214 = 0 ,
} ;
V_36 = F_227 ( V_128 , V_273 , & V_314 ) ;
F_273 ( & V_314 ) ;
return V_36 ;
}
int F_275 ( struct V_23 * V_24 , struct V_25 * V_25 ,
T_1 V_15 , T_1 V_16 , T_12 * V_284 ,
int V_375 )
{
int V_36 = 0 ;
struct V_51 * V_27 = V_25 -> V_129 ;
struct V_128 * V_128 ;
unsigned long V_138 = ( V_16 - V_15 + V_29 ) >>
V_126 ;
struct V_313 V_314 = {
. V_48 = NULL ,
. V_24 = V_24 ,
. V_284 = V_284 ,
. V_318 = 1 ,
. V_338 = V_375 == V_332 ,
. V_214 = 0 ,
} ;
struct V_272 V_376 = {
. V_331 = V_375 ,
. V_312 = V_138 * 2 ,
. V_362 = V_15 ,
. V_363 = V_16 + 1 ,
} ;
while ( V_15 <= V_16 ) {
V_128 = F_98 ( V_27 , V_15 >> V_126 ) ;
if ( F_99 ( V_128 ) )
V_36 = F_227 ( V_128 , & V_376 , & V_314 ) ;
else {
if ( V_24 -> V_53 && V_24 -> V_53 -> V_240 )
V_24 -> V_53 -> V_240 ( V_128 , V_15 ,
V_15 + V_29 - 1 ,
NULL , 1 ) ;
F_112 ( V_128 ) ;
}
F_100 ( V_128 ) ;
V_15 += V_29 ;
}
F_273 ( & V_314 ) ;
return V_36 ;
}
int F_276 ( struct V_23 * V_24 ,
struct V_51 * V_27 ,
T_12 * V_284 ,
struct V_272 * V_273 )
{
int V_36 = 0 ;
struct V_313 V_314 = {
. V_48 = NULL ,
. V_24 = V_24 ,
. V_284 = V_284 ,
. V_318 = 0 ,
. V_338 = V_273 -> V_331 == V_332 ,
. V_214 = 0 ,
} ;
V_36 = F_268 ( V_24 , V_27 , V_273 ,
F_227 , & V_314 ,
F_235 ) ;
F_273 ( & V_314 ) ;
return V_36 ;
}
int F_277 ( struct V_23 * V_24 ,
struct V_51 * V_27 ,
struct V_4 * V_137 , unsigned V_138 ,
T_12 V_284 )
{
struct V_48 * V_48 = NULL ;
unsigned V_377 ;
unsigned long V_214 = 0 ;
struct V_128 * V_378 [ 16 ] ;
struct V_128 * V_128 ;
struct V_209 * V_285 = NULL ;
int V_293 = 0 ;
T_1 V_287 = ( T_1 ) - 1 ;
for ( V_377 = 0 ; V_377 < V_138 ; V_377 ++ ) {
V_128 = F_11 ( V_137 -> V_77 , struct V_128 , V_379 ) ;
F_278 ( & V_128 -> V_7 ) ;
F_8 ( & V_128 -> V_379 ) ;
if ( F_279 ( V_128 , V_27 ,
V_128 -> V_125 ,
F_280 ( V_27 ) ) ) {
F_100 ( V_128 ) ;
continue;
}
V_378 [ V_293 ++ ] = V_128 ;
if ( V_293 < F_281 ( V_378 ) )
continue;
F_218 ( V_24 , V_378 , V_293 , V_284 , & V_285 ,
& V_48 , 0 , & V_214 , & V_287 ) ;
V_293 = 0 ;
}
if ( V_293 )
F_218 ( V_24 , V_378 , V_293 , V_284 , & V_285 ,
& V_48 , 0 , & V_214 , & V_287 ) ;
if ( V_285 )
F_160 ( V_285 ) ;
F_22 ( ! F_10 ( V_137 ) ) ;
if ( V_48 )
return F_186 ( V_48 , 0 , V_214 ) ;
return 0 ;
}
int F_282 ( struct V_23 * V_24 ,
struct V_128 * V_128 , unsigned long V_62 )
{
struct V_1 * V_101 = NULL ;
T_1 V_15 = F_130 ( V_128 ) ;
T_1 V_16 = V_15 + V_29 - 1 ;
T_10 V_296 = V_128 -> V_27 -> V_28 -> V_41 -> V_297 ;
V_15 += F_211 ( V_62 , V_296 ) ;
if ( V_15 > V_16 )
return 0 ;
F_95 ( V_24 , V_15 , V_16 , & V_101 ) ;
F_271 ( V_128 ) ;
F_93 ( V_24 , V_15 , V_16 ,
V_124 | V_97 | V_105 |
V_380 ,
1 , 1 , & V_101 , V_123 ) ;
return 0 ;
}
static int F_283 ( struct V_211 * V_381 ,
struct V_23 * V_24 ,
struct V_128 * V_128 , T_3 V_56 )
{
T_1 V_15 = F_130 ( V_128 ) ;
T_1 V_16 = V_15 + V_29 - 1 ;
int V_36 = 1 ;
if ( F_117 ( V_24 , V_15 , V_16 ,
V_83 , 0 , NULL ) )
V_36 = 0 ;
else {
if ( ( V_56 & V_123 ) == V_123 )
V_56 = V_123 ;
V_36 = F_93 ( V_24 , V_15 , V_16 ,
~ ( V_124 | V_382 ) ,
0 , 0 , NULL , V_56 ) ;
if ( V_36 < 0 )
V_36 = 0 ;
else
V_36 = 1 ;
}
return V_36 ;
}
int F_284 ( struct V_211 * V_381 ,
struct V_23 * V_24 , struct V_128 * V_128 ,
T_3 V_56 )
{
struct V_209 * V_210 ;
T_1 V_15 = F_130 ( V_128 ) ;
T_1 V_16 = V_15 + V_29 - 1 ;
if ( F_73 ( V_56 ) &&
V_128 -> V_27 -> V_28 -> V_255 > V_383 ) {
T_1 V_20 ;
while ( V_15 <= V_16 ) {
V_20 = V_16 - V_15 + 1 ;
F_285 ( & V_381 -> V_55 ) ;
V_210 = F_158 ( V_381 , V_15 , V_20 ) ;
if ( ! V_210 ) {
F_286 ( & V_381 -> V_55 ) ;
break;
}
if ( F_161 ( V_384 , & V_210 -> V_7 ) ||
V_210 -> V_15 != V_15 ) {
F_286 ( & V_381 -> V_55 ) ;
F_160 ( V_210 ) ;
break;
}
if ( ! F_117 ( V_24 , V_210 -> V_15 ,
F_202 ( V_210 ) - 1 ,
V_124 | V_385 ,
0 , NULL ) ) {
F_287 ( V_381 , V_210 ) ;
F_160 ( V_210 ) ;
}
V_15 = F_202 ( V_210 ) ;
F_286 ( & V_381 -> V_55 ) ;
F_160 ( V_210 ) ;
}
}
return F_283 ( V_381 , V_24 , V_128 , V_56 ) ;
}
static struct V_209 * F_288 ( struct V_25 * V_25 ,
T_1 V_62 ,
T_1 V_160 ,
T_12 * V_284 )
{
T_1 V_386 = F_289 ( V_25 ) ;
struct V_209 * V_210 ;
T_1 V_20 ;
if ( V_62 >= V_160 )
return NULL ;
while ( 1 ) {
V_20 = V_160 - V_62 ;
if ( V_20 == 0 )
break;
V_20 = F_211 ( V_20 , V_386 ) ;
V_210 = V_284 ( V_25 , NULL , 0 , V_62 , V_20 , 0 ) ;
if ( F_203 ( V_210 ) )
return V_210 ;
if ( ! F_161 ( V_387 , & V_210 -> V_7 ) &&
V_210 -> V_215 != V_304 ) {
return V_210 ;
}
V_62 = F_202 ( V_210 ) ;
F_160 ( V_210 ) ;
if ( V_62 >= V_160 )
break;
}
return NULL ;
}
int F_290 ( struct V_25 * V_25 , struct V_388 * V_389 ,
T_16 V_15 , T_16 V_20 , T_12 * V_284 )
{
int V_36 = 0 ;
T_1 V_256 = V_15 ;
T_1 F_126 = V_15 + V_20 ;
T_14 V_7 = 0 ;
T_14 V_390 ;
T_1 V_160 ;
T_1 V_391 = 0 ;
T_1 V_392 = 0 ;
T_1 V_26 = F_16 ( V_25 ) ;
struct V_393 V_394 ;
struct V_209 * V_210 = NULL ;
struct V_1 * V_101 = NULL ;
struct V_395 * V_396 ;
struct V_397 * V_30 = F_18 ( V_25 ) -> V_30 ;
int V_16 = 0 ;
T_1 V_398 = 0 ;
T_1 V_399 = 0 ;
T_1 V_329 = 0 ;
if ( V_20 == 0 )
return - V_400 ;
V_396 = F_291 () ;
if ( ! V_396 )
return - V_43 ;
V_396 -> V_401 = 1 ;
V_15 = F_292 ( V_15 , F_289 ( V_25 ) ) ;
V_20 = F_293 ( F_126 , F_289 ( V_25 ) ) - V_15 ;
V_36 = F_294 ( NULL , V_30 , V_396 , F_19 ( V_25 ) , - 1 ,
0 ) ;
if ( V_36 < 0 ) {
F_295 ( V_396 ) ;
return V_36 ;
} else {
F_44 ( ! V_36 ) ;
if ( V_36 == 1 )
V_36 = 0 ;
}
V_396 -> V_402 [ 0 ] -- ;
F_296 ( V_396 -> V_403 [ 0 ] , & V_394 , V_396 -> V_402 [ 0 ] ) ;
V_390 = V_394 . type ;
if ( V_394 . V_404 != F_19 ( V_25 ) ||
V_390 != V_405 ) {
V_160 = ( T_1 ) - 1 ;
V_391 = V_26 ;
} else {
V_160 = V_394 . V_62 ;
V_391 = V_160 + 1 ;
}
F_297 ( V_396 ) ;
if ( V_160 < V_26 ) {
V_160 = ( T_1 ) - 1 ;
V_391 = V_26 ;
}
F_95 ( & F_18 ( V_25 ) -> V_150 , V_15 , V_15 + V_20 - 1 ,
& V_101 ) ;
V_210 = F_288 ( V_25 , V_15 , V_391 ,
V_284 ) ;
if ( ! V_210 )
goto V_110;
if ( F_298 ( V_210 ) ) {
V_36 = F_299 ( V_210 ) ;
goto V_110;
}
while ( ! V_16 ) {
T_1 V_406 = 0 ;
if ( V_210 -> V_15 >= F_126 || F_202 ( V_210 ) < V_256 )
break;
V_398 = F_126 ( V_210 -> V_15 , V_256 ) ;
if ( ! F_161 ( V_216 , & V_210 -> V_7 ) )
V_406 = V_398 - V_210 -> V_15 ;
V_329 = F_202 ( V_210 ) ;
V_399 = V_329 - V_398 ;
V_392 = 0 ;
V_7 = 0 ;
V_256 = F_202 ( V_210 ) ;
if ( V_256 >= F_126 )
V_16 = 1 ;
if ( V_210 -> V_215 == V_407 ) {
V_16 = 1 ;
V_7 |= V_408 ;
} else if ( V_210 -> V_215 == V_306 ) {
V_7 |= ( V_409 |
V_410 ) ;
} else if ( V_210 -> V_215 == V_411 ) {
V_7 |= ( V_412 |
V_413 ) ;
} else if ( V_389 -> V_414 ) {
struct V_415 * V_416 ;
T_1 V_417 = V_210 -> V_215 -
( V_210 -> V_15 - V_210 -> V_305 ) ;
V_392 = V_210 -> V_215 + V_406 ;
V_416 = F_300 ( V_30 ) ;
if ( F_298 ( V_416 ) )
V_416 = NULL ;
V_36 = F_301 ( V_416 , V_30 -> V_31 ,
V_30 -> V_404 ,
F_19 ( V_25 ) , V_417 ) ;
if ( V_416 )
F_302 ( V_416 ) ;
if ( V_36 < 0 )
goto V_418;
if ( V_36 )
V_7 |= V_419 ;
V_36 = 0 ;
}
if ( F_161 ( V_216 , & V_210 -> V_7 ) )
V_7 |= V_420 ;
if ( F_161 ( V_303 , & V_210 -> V_7 ) )
V_7 |= V_421 ;
F_160 ( V_210 ) ;
V_210 = NULL ;
if ( ( V_398 >= V_160 ) || V_399 == ( T_1 ) - 1 ||
( V_160 == ( T_1 ) - 1 && V_26 <= V_329 ) ) {
V_7 |= V_408 ;
V_16 = 1 ;
}
V_210 = F_288 ( V_25 , V_256 , V_391 ,
V_284 ) ;
if ( F_298 ( V_210 ) ) {
V_36 = F_299 ( V_210 ) ;
goto V_110;
}
if ( ! V_210 ) {
V_7 |= V_408 ;
V_16 = 1 ;
}
V_36 = F_303 ( V_389 , V_398 , V_392 ,
V_399 , V_7 ) ;
if ( V_36 ) {
if ( V_36 == 1 )
V_36 = 0 ;
goto V_418;
}
}
V_418:
F_160 ( V_210 ) ;
V_110:
F_295 ( V_396 ) ;
F_118 ( & F_18 ( V_25 ) -> V_150 , V_15 , V_15 + V_20 - 1 ,
& V_101 , V_123 ) ;
return V_36 ;
}
static void F_304 ( struct V_10 * V_11 )
{
F_7 ( & V_11 -> V_14 ) ;
F_14 ( V_21 , V_11 ) ;
}
int F_305 ( struct V_10 * V_11 )
{
return ( F_13 ( & V_11 -> V_349 ) ||
F_161 ( V_336 , & V_11 -> V_335 ) ||
F_161 ( V_340 , & V_11 -> V_335 ) ) ;
}
static void F_306 ( struct V_10 * V_11 )
{
unsigned long V_125 ;
struct V_128 * V_128 ;
int V_422 = ! F_161 ( V_423 , & V_11 -> V_335 ) ;
F_22 ( F_305 ( V_11 ) ) ;
V_125 = F_149 ( V_11 -> V_15 , V_11 -> V_20 ) ;
if ( V_125 == 0 )
return;
do {
V_125 -- ;
V_128 = V_11 -> V_137 [ V_125 ] ;
if ( ! V_128 )
continue;
if ( V_422 )
F_74 ( & V_128 -> V_27 -> V_368 ) ;
if ( F_195 ( V_128 ) &&
V_128 -> V_203 == ( unsigned long ) V_11 ) {
F_22 ( F_161 ( V_340 , & V_11 -> V_335 ) ) ;
F_22 ( F_115 ( V_128 ) ) ;
F_22 ( F_226 ( V_128 ) ) ;
F_307 ( V_128 ) ;
F_198 ( V_128 , 0 ) ;
F_100 ( V_128 ) ;
}
if ( V_422 )
F_77 ( & V_128 -> V_27 -> V_368 ) ;
F_100 ( V_128 ) ;
} while ( V_125 != 0 );
}
static inline void F_308 ( struct V_10 * V_11 )
{
F_306 ( V_11 ) ;
F_304 ( V_11 ) ;
}
static struct V_10 *
F_309 ( struct V_40 * V_31 , T_1 V_15 ,
unsigned long V_20 )
{
struct V_10 * V_11 = NULL ;
V_11 = F_310 ( V_21 , V_123 | V_424 ) ;
V_11 -> V_15 = V_15 ;
V_11 -> V_20 = V_20 ;
V_11 -> V_31 = V_31 ;
V_11 -> V_335 = 0 ;
F_311 ( & V_11 -> V_55 ) ;
F_39 ( & V_11 -> V_425 , 0 ) ;
F_39 ( & V_11 -> V_426 , 0 ) ;
F_39 ( & V_11 -> V_427 , 0 ) ;
F_39 ( & V_11 -> V_428 , 0 ) ;
F_39 ( & V_11 -> V_429 , 0 ) ;
F_39 ( & V_11 -> V_430 , 0 ) ;
V_11 -> V_431 = 0 ;
F_40 ( & V_11 -> V_432 ) ;
F_40 ( & V_11 -> V_433 ) ;
F_3 ( & V_11 -> V_14 , & V_19 ) ;
F_35 ( & V_11 -> V_339 ) ;
F_39 ( & V_11 -> V_17 , 1 ) ;
F_39 ( & V_11 -> V_349 , 0 ) ;
F_312 ( V_434
> V_435 ) ;
F_22 ( V_20 > V_435 ) ;
return V_11 ;
}
struct V_10 * F_313 ( struct V_10 * V_436 )
{
unsigned long V_139 ;
struct V_128 * V_66 ;
struct V_10 * V_5 ;
unsigned long V_200 = F_149 ( V_436 -> V_15 , V_436 -> V_20 ) ;
V_5 = F_309 ( V_436 -> V_31 , V_436 -> V_15 , V_436 -> V_20 ) ;
if ( V_5 == NULL )
return NULL ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
V_66 = F_314 ( V_123 ) ;
if ( ! V_66 ) {
F_308 ( V_5 ) ;
return NULL ;
}
F_194 ( V_5 , V_66 ) ;
F_44 ( F_115 ( V_66 ) ) ;
F_131 ( V_66 ) ;
V_5 -> V_137 [ V_139 ] = V_66 ;
F_315 ( F_316 ( V_66 ) , F_316 ( V_436 -> V_137 [ V_139 ] ) ) ;
}
F_239 ( V_437 , & V_5 -> V_335 ) ;
F_239 ( V_423 , & V_5 -> V_335 ) ;
return V_5 ;
}
struct V_10 * F_317 ( struct V_40 * V_31 ,
T_1 V_15 , unsigned long V_20 )
{
struct V_10 * V_11 ;
unsigned long V_200 ;
unsigned long V_139 ;
V_200 = F_149 ( V_15 , V_20 ) ;
V_11 = F_309 ( V_31 , V_15 , V_20 ) ;
if ( ! V_11 )
return NULL ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
V_11 -> V_137 [ V_139 ] = F_314 ( V_123 ) ;
if ( ! V_11 -> V_137 [ V_139 ] )
goto V_99;
}
F_318 ( V_11 ) ;
F_319 ( V_11 , 0 ) ;
F_239 ( V_423 , & V_11 -> V_335 ) ;
return V_11 ;
V_99:
for (; V_139 > 0 ; V_139 -- )
F_320 ( V_11 -> V_137 [ V_139 - 1 ] ) ;
F_304 ( V_11 ) ;
return NULL ;
}
struct V_10 * F_321 ( struct V_40 * V_31 ,
T_1 V_15 )
{
return F_317 ( V_31 , V_15 , V_31 -> V_438 ) ;
}
static void F_322 ( struct V_10 * V_11 )
{
int V_17 ;
V_17 = F_13 ( & V_11 -> V_17 ) ;
if ( V_17 >= 2 && F_161 ( V_439 , & V_11 -> V_335 ) )
return;
F_74 ( & V_11 -> V_339 ) ;
if ( ! F_248 ( V_439 , & V_11 -> V_335 ) )
F_85 ( & V_11 -> V_17 ) ;
F_77 ( & V_11 -> V_339 ) ;
}
static void F_323 ( struct V_10 * V_11 ,
struct V_128 * V_440 )
{
unsigned long V_200 , V_139 ;
F_322 ( V_11 ) ;
V_200 = F_149 ( V_11 -> V_15 , V_11 -> V_20 ) ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
struct V_128 * V_66 = V_11 -> V_137 [ V_139 ] ;
if ( V_66 != V_440 )
F_324 ( V_66 ) ;
}
}
struct V_10 * F_325 ( struct V_40 * V_31 ,
T_1 V_15 )
{
struct V_10 * V_11 ;
F_326 () ;
V_11 = F_327 ( & V_31 -> V_441 ,
V_15 >> V_126 ) ;
if ( V_11 && F_265 ( & V_11 -> V_17 ) ) {
F_328 () ;
if ( F_161 ( V_442 , & V_11 -> V_335 ) ) {
F_74 ( & V_11 -> V_339 ) ;
F_77 ( & V_11 -> V_339 ) ;
}
F_323 ( V_11 , NULL ) ;
return V_11 ;
}
F_328 () ;
return NULL ;
}
struct V_10 * F_329 ( struct V_40 * V_31 ,
T_1 V_15 )
{
struct V_10 * V_11 , * V_443 = NULL ;
int V_36 ;
V_11 = F_325 ( V_31 , V_15 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_321 ( V_31 , V_15 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_31 = V_31 ;
V_108:
V_36 = F_330 ( V_123 ) ;
if ( V_36 )
goto V_444;
F_74 ( & V_31 -> V_445 ) ;
V_36 = F_331 ( & V_31 -> V_441 ,
V_15 >> V_126 , V_11 ) ;
F_77 ( & V_31 -> V_445 ) ;
F_332 () ;
if ( V_36 == - V_89 ) {
V_443 = F_325 ( V_31 , V_15 ) ;
if ( V_443 )
goto V_444;
else
goto V_108;
}
F_322 ( V_11 ) ;
F_239 ( V_446 , & V_11 -> V_335 ) ;
F_85 ( & V_11 -> V_17 ) ;
return V_11 ;
V_444:
F_308 ( V_11 ) ;
return V_443 ;
}
struct V_10 * F_333 ( struct V_40 * V_31 ,
T_1 V_15 )
{
unsigned long V_20 = V_31 -> V_438 ;
unsigned long V_200 = F_149 ( V_15 , V_20 ) ;
unsigned long V_139 ;
unsigned long V_125 = V_15 >> V_126 ;
struct V_10 * V_11 ;
struct V_10 * V_443 = NULL ;
struct V_128 * V_66 ;
struct V_51 * V_27 = V_31 -> V_202 -> V_129 ;
int V_239 = 1 ;
int V_36 ;
if ( ! F_334 ( V_15 , V_31 -> V_386 ) ) {
F_174 ( V_31 , L_22 , V_15 ) ;
return F_335 ( - V_400 ) ;
}
V_11 = F_325 ( V_31 , V_15 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_309 ( V_31 , V_15 , V_20 ) ;
if ( ! V_11 )
return F_335 ( - V_43 ) ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ , V_125 ++ ) {
V_66 = F_336 ( V_27 , V_125 , V_123 | V_424 ) ;
if ( ! V_66 ) {
V_443 = F_335 ( - V_43 ) ;
goto V_444;
}
F_74 ( & V_27 -> V_368 ) ;
if ( F_195 ( V_66 ) ) {
V_443 = (struct V_10 * ) V_66 -> V_203 ;
if ( F_265 ( & V_443 -> V_17 ) ) {
F_77 ( & V_27 -> V_368 ) ;
F_112 ( V_66 ) ;
F_100 ( V_66 ) ;
F_323 ( V_443 , V_66 ) ;
goto V_444;
}
V_443 = NULL ;
F_307 ( V_66 ) ;
F_44 ( F_115 ( V_66 ) ) ;
F_100 ( V_66 ) ;
}
F_194 ( V_11 , V_66 ) ;
F_77 ( & V_27 -> V_368 ) ;
F_44 ( F_115 ( V_66 ) ) ;
V_11 -> V_137 [ V_139 ] = V_66 ;
if ( ! F_205 ( V_66 ) )
V_239 = 0 ;
}
if ( V_239 )
F_239 ( V_437 , & V_11 -> V_335 ) ;
V_108:
V_36 = F_330 ( V_123 ) ;
if ( V_36 ) {
V_443 = F_335 ( V_36 ) ;
goto V_444;
}
F_74 ( & V_31 -> V_445 ) ;
V_36 = F_331 ( & V_31 -> V_441 ,
V_15 >> V_126 , V_11 ) ;
F_77 ( & V_31 -> V_445 ) ;
F_332 () ;
if ( V_36 == - V_89 ) {
V_443 = F_325 ( V_31 , V_15 ) ;
if ( V_443 )
goto V_444;
else
goto V_108;
}
F_322 ( V_11 ) ;
F_239 ( V_446 , & V_11 -> V_335 ) ;
F_337 ( V_11 -> V_137 [ 0 ] ) ;
for ( V_139 = 1 ; V_139 < V_200 ; V_139 ++ ) {
V_66 = V_11 -> V_137 [ V_139 ] ;
F_338 ( V_66 ) ;
F_112 ( V_66 ) ;
}
F_112 ( V_11 -> V_137 [ 0 ] ) ;
return V_11 ;
V_444:
F_44 ( ! F_43 ( & V_11 -> V_17 ) ) ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
if ( V_11 -> V_137 [ V_139 ] )
F_112 ( V_11 -> V_137 [ V_139 ] ) ;
}
F_308 ( V_11 ) ;
return V_443 ;
}
static inline void F_339 ( struct V_447 * V_6 )
{
struct V_10 * V_11 =
F_340 ( V_6 , struct V_10 , V_447 ) ;
F_304 ( V_11 ) ;
}
static int F_341 ( struct V_10 * V_11 )
{
F_44 ( F_13 ( & V_11 -> V_17 ) == 0 ) ;
if ( F_43 ( & V_11 -> V_17 ) ) {
if ( F_238 ( V_446 , & V_11 -> V_335 ) ) {
struct V_40 * V_31 = V_11 -> V_31 ;
F_77 ( & V_11 -> V_339 ) ;
F_74 ( & V_31 -> V_445 ) ;
F_342 ( & V_31 -> V_441 ,
V_11 -> V_15 >> V_126 ) ;
F_77 ( & V_31 -> V_445 ) ;
} else {
F_77 ( & V_11 -> V_339 ) ;
}
F_306 ( V_11 ) ;
#ifdef F_343
if ( F_181 ( F_161 ( V_423 , & V_11 -> V_335 ) ) ) {
F_304 ( V_11 ) ;
return 1 ;
}
#endif
F_344 ( & V_11 -> V_447 , F_339 ) ;
return 1 ;
}
F_77 ( & V_11 -> V_339 ) ;
return 0 ;
}
void F_266 ( struct V_10 * V_11 )
{
int V_17 ;
int V_448 ;
if ( ! V_11 )
return;
while ( 1 ) {
V_17 = F_13 ( & V_11 -> V_17 ) ;
if ( V_17 <= 3 )
break;
V_448 = F_345 ( & V_11 -> V_17 , V_17 , V_17 - 1 ) ;
if ( V_448 == V_17 )
return;
}
F_74 ( & V_11 -> V_339 ) ;
if ( F_13 ( & V_11 -> V_17 ) == 2 &&
F_161 ( V_423 , & V_11 -> V_335 ) )
F_75 ( & V_11 -> V_17 ) ;
if ( F_13 ( & V_11 -> V_17 ) == 2 &&
F_161 ( V_442 , & V_11 -> V_335 ) &&
! F_305 ( V_11 ) &&
F_238 ( V_439 , & V_11 -> V_335 ) )
F_75 ( & V_11 -> V_17 ) ;
F_341 ( V_11 ) ;
}
void F_346 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return;
F_74 ( & V_11 -> V_339 ) ;
F_239 ( V_442 , & V_11 -> V_335 ) ;
if ( F_13 ( & V_11 -> V_17 ) == 2 && ! F_305 ( V_11 ) &&
F_238 ( V_439 , & V_11 -> V_335 ) )
F_75 ( & V_11 -> V_17 ) ;
F_341 ( V_11 ) ;
}
void F_347 ( struct V_10 * V_11 )
{
unsigned long V_139 ;
unsigned long V_200 ;
struct V_128 * V_128 ;
V_200 = F_149 ( V_11 -> V_15 , V_11 -> V_20 ) ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
if ( ! F_115 ( V_128 ) )
continue;
F_114 ( V_128 ) ;
F_44 ( ! F_195 ( V_128 ) ) ;
F_99 ( V_128 ) ;
F_348 ( & V_128 -> V_27 -> V_449 ) ;
if ( ! F_115 ( V_128 ) ) {
F_349 ( & V_128 -> V_27 -> V_450 ,
F_350 ( V_128 ) ,
V_365 ) ;
}
F_351 ( & V_128 -> V_27 -> V_449 ) ;
F_230 ( V_128 ) ;
F_112 ( V_128 ) ;
}
F_44 ( F_13 ( & V_11 -> V_17 ) == 0 ) ;
}
int F_352 ( struct V_10 * V_11 )
{
unsigned long V_139 ;
unsigned long V_200 ;
int V_451 = 0 ;
F_322 ( V_11 ) ;
V_451 = F_248 ( V_340 , & V_11 -> V_335 ) ;
V_200 = F_149 ( V_11 -> V_15 , V_11 -> V_20 ) ;
F_44 ( F_13 ( & V_11 -> V_17 ) == 0 ) ;
F_44 ( ! F_161 ( V_439 , & V_11 -> V_335 ) ) ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ )
F_353 ( V_11 -> V_137 [ V_139 ] ) ;
return V_451 ;
}
void F_354 ( struct V_10 * V_11 )
{
unsigned long V_139 ;
struct V_128 * V_128 ;
unsigned long V_200 ;
F_244 ( V_437 , & V_11 -> V_335 ) ;
V_200 = F_149 ( V_11 -> V_15 , V_11 -> V_20 ) ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
if ( V_128 )
F_171 ( V_128 ) ;
}
}
void F_318 ( struct V_10 * V_11 )
{
unsigned long V_139 ;
struct V_128 * V_128 ;
unsigned long V_200 ;
F_239 ( V_437 , & V_11 -> V_335 ) ;
V_200 = F_149 ( V_11 -> V_15 , V_11 -> V_20 ) ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
F_131 ( V_128 ) ;
}
}
int F_355 ( struct V_10 * V_11 )
{
return F_161 ( V_437 , & V_11 -> V_335 ) ;
}
int F_356 ( struct V_23 * V_24 ,
struct V_10 * V_11 , int V_112 ,
T_12 * V_284 , int V_173 )
{
unsigned long V_139 ;
struct V_128 * V_128 ;
int V_99 ;
int V_36 = 0 ;
int V_452 = 0 ;
int V_453 = 1 ;
unsigned long V_200 ;
unsigned long V_454 = 0 ;
struct V_48 * V_48 = NULL ;
unsigned long V_214 = 0 ;
if ( F_161 ( V_437 , & V_11 -> V_335 ) )
return 0 ;
V_200 = F_149 ( V_11 -> V_15 , V_11 -> V_20 ) ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
if ( V_112 == V_455 ) {
if ( ! F_242 ( V_128 ) )
goto V_456;
} else {
F_114 ( V_128 ) ;
}
V_452 ++ ;
}
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
if ( ! F_205 ( V_128 ) ) {
V_454 ++ ;
V_453 = 0 ;
}
}
if ( V_453 ) {
F_239 ( V_437 , & V_11 -> V_335 ) ;
goto V_456;
}
F_244 ( V_457 , & V_11 -> V_335 ) ;
V_11 -> V_458 = 0 ;
F_39 ( & V_11 -> V_349 , V_454 ) ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
if ( ! F_205 ( V_128 ) ) {
if ( V_36 ) {
F_75 ( & V_11 -> V_349 ) ;
F_112 ( V_128 ) ;
continue;
}
F_230 ( V_128 ) ;
V_99 = F_219 ( V_24 , V_128 ,
V_284 , & V_48 ,
V_173 , & V_214 ,
V_351 ) ;
if ( V_99 ) {
V_36 = V_99 ;
F_75 ( & V_11 -> V_349 ) ;
}
} else {
F_112 ( V_128 ) ;
}
}
if ( V_48 ) {
V_99 = F_186 ( V_48 , V_173 , V_214 ) ;
if ( V_99 )
return V_99 ;
}
if ( V_36 || V_112 != V_459 )
return V_36 ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
F_357 ( V_128 ) ;
if ( ! F_205 ( V_128 ) )
V_36 = - V_152 ;
}
return V_36 ;
V_456:
while ( V_452 > 0 ) {
V_452 -- ;
V_128 = V_11 -> V_137 [ V_452 ] ;
F_112 ( V_128 ) ;
}
return V_36 ;
}
void F_358 ( struct V_10 * V_11 , void * V_460 ,
unsigned long V_15 ,
unsigned long V_20 )
{
T_10 V_289 ;
T_10 V_62 ;
struct V_128 * V_128 ;
char * V_461 ;
char * V_462 = ( char * ) V_460 ;
T_10 V_463 = V_11 -> V_15 & ( ( T_1 ) V_29 - 1 ) ;
unsigned long V_139 = ( V_463 + V_15 ) >> V_126 ;
F_44 ( V_15 > V_11 -> V_20 ) ;
F_44 ( V_15 + V_20 > V_11 -> V_15 + V_11 -> V_20 ) ;
V_62 = ( V_463 + V_15 ) & ( V_29 - 1 ) ;
while ( V_20 > 0 ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
V_289 = F_125 ( V_20 , ( V_29 - V_62 ) ) ;
V_461 = F_316 ( V_128 ) ;
memcpy ( V_462 , V_461 + V_62 , V_289 ) ;
V_462 += V_289 ;
V_20 -= V_289 ;
V_62 = 0 ;
V_139 ++ ;
}
}
int F_359 ( struct V_10 * V_11 , void T_17 * V_460 ,
unsigned long V_15 ,
unsigned long V_20 )
{
T_10 V_289 ;
T_10 V_62 ;
struct V_128 * V_128 ;
char * V_461 ;
char T_17 * V_462 = ( char T_17 * ) V_460 ;
T_10 V_463 = V_11 -> V_15 & ( ( T_1 ) V_29 - 1 ) ;
unsigned long V_139 = ( V_463 + V_15 ) >> V_126 ;
int V_36 = 0 ;
F_44 ( V_15 > V_11 -> V_20 ) ;
F_44 ( V_15 + V_20 > V_11 -> V_15 + V_11 -> V_20 ) ;
V_62 = ( V_463 + V_15 ) & ( V_29 - 1 ) ;
while ( V_20 > 0 ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
V_289 = F_125 ( V_20 , ( V_29 - V_62 ) ) ;
V_461 = F_316 ( V_128 ) ;
if ( F_360 ( V_462 , V_461 + V_62 , V_289 ) ) {
V_36 = - V_464 ;
break;
}
V_462 += V_289 ;
V_20 -= V_289 ;
V_62 = 0 ;
V_139 ++ ;
}
return V_36 ;
}
int F_361 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_465 , char * * V_381 ,
unsigned long * V_466 ,
unsigned long * V_467 )
{
T_10 V_62 = V_15 & ( V_29 - 1 ) ;
char * V_461 ;
struct V_128 * V_66 ;
T_10 V_463 = V_11 -> V_15 & ( ( T_1 ) V_29 - 1 ) ;
unsigned long V_139 = ( V_463 + V_15 ) >> V_126 ;
unsigned long V_468 = ( V_463 + V_15 + V_465 - 1 ) >>
V_126 ;
if ( V_139 != V_468 )
return 1 ;
if ( V_139 == 0 ) {
V_62 = V_463 ;
* V_466 = 0 ;
} else {
V_62 = 0 ;
* V_466 = ( ( T_1 ) V_139 << V_126 ) - V_463 ;
}
if ( V_15 + V_465 > V_11 -> V_20 ) {
F_61 ( 1 , V_87 L_23 ,
V_11 -> V_15 , V_11 -> V_20 , V_15 , V_465 ) ;
return - V_400 ;
}
V_66 = V_11 -> V_137 [ V_139 ] ;
V_461 = F_316 ( V_66 ) ;
* V_381 = V_461 + V_62 ;
* V_467 = V_29 - V_62 ;
return 0 ;
}
int F_362 ( struct V_10 * V_11 , const void * V_469 ,
unsigned long V_15 ,
unsigned long V_20 )
{
T_10 V_289 ;
T_10 V_62 ;
struct V_128 * V_128 ;
char * V_461 ;
char * V_470 = ( char * ) V_469 ;
T_10 V_463 = V_11 -> V_15 & ( ( T_1 ) V_29 - 1 ) ;
unsigned long V_139 = ( V_463 + V_15 ) >> V_126 ;
int V_36 = 0 ;
F_44 ( V_15 > V_11 -> V_20 ) ;
F_44 ( V_15 + V_20 > V_11 -> V_15 + V_11 -> V_20 ) ;
V_62 = ( V_463 + V_15 ) & ( V_29 - 1 ) ;
while ( V_20 > 0 ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
V_289 = F_125 ( V_20 , ( V_29 - V_62 ) ) ;
V_461 = F_316 ( V_128 ) ;
V_36 = memcmp ( V_470 , V_461 + V_62 , V_289 ) ;
if ( V_36 )
break;
V_470 += V_289 ;
V_20 -= V_289 ;
V_62 = 0 ;
V_139 ++ ;
}
return V_36 ;
}
void F_363 ( struct V_10 * V_11 ,
const void * V_471 )
{
char * V_461 ;
F_44 ( ! F_205 ( V_11 -> V_137 [ 0 ] ) ) ;
V_461 = F_316 ( V_11 -> V_137 [ 0 ] ) ;
memcpy ( V_461 + F_28 ( struct V_472 , V_473 ) , V_471 ,
V_474 ) ;
}
void F_364 ( struct V_10 * V_11 , const void * V_471 )
{
char * V_461 ;
F_44 ( ! F_205 ( V_11 -> V_137 [ 0 ] ) ) ;
V_461 = F_316 ( V_11 -> V_137 [ 0 ] ) ;
memcpy ( V_461 + F_28 ( struct V_472 , V_475 ) , V_471 ,
V_474 ) ;
}
void F_365 ( struct V_10 * V_11 , const void * V_471 ,
unsigned long V_15 , unsigned long V_20 )
{
T_10 V_289 ;
T_10 V_62 ;
struct V_128 * V_128 ;
char * V_461 ;
char * V_436 = ( char * ) V_471 ;
T_10 V_463 = V_11 -> V_15 & ( ( T_1 ) V_29 - 1 ) ;
unsigned long V_139 = ( V_463 + V_15 ) >> V_126 ;
F_44 ( V_15 > V_11 -> V_20 ) ;
F_44 ( V_15 + V_20 > V_11 -> V_15 + V_11 -> V_20 ) ;
V_62 = ( V_463 + V_15 ) & ( V_29 - 1 ) ;
while ( V_20 > 0 ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
F_44 ( ! F_205 ( V_128 ) ) ;
V_289 = F_125 ( V_20 , V_29 - V_62 ) ;
V_461 = F_316 ( V_128 ) ;
memcpy ( V_461 + V_62 , V_436 , V_289 ) ;
V_436 += V_289 ;
V_20 -= V_289 ;
V_62 = 0 ;
V_139 ++ ;
}
}
void F_256 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_20 )
{
T_10 V_289 ;
T_10 V_62 ;
struct V_128 * V_128 ;
char * V_461 ;
T_10 V_463 = V_11 -> V_15 & ( ( T_1 ) V_29 - 1 ) ;
unsigned long V_139 = ( V_463 + V_15 ) >> V_126 ;
F_44 ( V_15 > V_11 -> V_20 ) ;
F_44 ( V_15 + V_20 > V_11 -> V_15 + V_11 -> V_20 ) ;
V_62 = ( V_463 + V_15 ) & ( V_29 - 1 ) ;
while ( V_20 > 0 ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
F_44 ( ! F_205 ( V_128 ) ) ;
V_289 = F_125 ( V_20 , V_29 - V_62 ) ;
V_461 = F_316 ( V_128 ) ;
memset ( V_461 + V_62 , 0 , V_289 ) ;
V_20 -= V_289 ;
V_62 = 0 ;
V_139 ++ ;
}
}
void F_366 ( struct V_10 * V_462 ,
struct V_10 * V_436 )
{
int V_139 ;
unsigned V_200 ;
ASSERT ( V_462 -> V_20 == V_436 -> V_20 ) ;
V_200 = F_149 ( V_462 -> V_15 , V_462 -> V_20 ) ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ )
F_315 ( F_316 ( V_462 -> V_137 [ V_139 ] ) ,
F_316 ( V_436 -> V_137 [ V_139 ] ) ) ;
}
void F_367 ( struct V_10 * V_462 , struct V_10 * V_436 ,
unsigned long V_476 , unsigned long V_477 ,
unsigned long V_20 )
{
T_1 V_478 = V_462 -> V_20 ;
T_10 V_289 ;
T_10 V_62 ;
struct V_128 * V_128 ;
char * V_461 ;
T_10 V_463 = V_462 -> V_15 & ( ( T_1 ) V_29 - 1 ) ;
unsigned long V_139 = ( V_463 + V_476 ) >> V_126 ;
F_44 ( V_436 -> V_20 != V_478 ) ;
V_62 = ( V_463 + V_476 ) &
( V_29 - 1 ) ;
while ( V_20 > 0 ) {
V_128 = V_462 -> V_137 [ V_139 ] ;
F_44 ( ! F_205 ( V_128 ) ) ;
V_289 = F_125 ( V_20 , ( unsigned long ) ( V_29 - V_62 ) ) ;
V_461 = F_316 ( V_128 ) ;
F_358 ( V_436 , V_461 + V_62 , V_477 , V_289 ) ;
V_477 += V_289 ;
V_20 -= V_289 ;
V_62 = 0 ;
V_139 ++ ;
}
}
void F_368 ( T_18 * V_381 , unsigned int V_15 , int V_20 )
{
T_18 * V_66 = V_381 + F_369 ( V_15 ) ;
const unsigned int V_268 = V_15 + V_20 ;
int V_115 = V_479 - ( V_15 % V_479 ) ;
T_18 V_480 = F_370 ( V_15 ) ;
while ( V_20 - V_115 >= 0 ) {
* V_66 |= V_480 ;
V_20 -= V_115 ;
V_115 = V_479 ;
V_480 = ~ 0 ;
V_66 ++ ;
}
if ( V_20 ) {
V_480 &= F_371 ( V_268 ) ;
* V_66 |= V_480 ;
}
}
void F_372 ( T_18 * V_381 , unsigned int V_15 , int V_20 )
{
T_18 * V_66 = V_381 + F_369 ( V_15 ) ;
const unsigned int V_268 = V_15 + V_20 ;
int V_95 = V_479 - ( V_15 % V_479 ) ;
T_18 V_481 = F_370 ( V_15 ) ;
while ( V_20 - V_95 >= 0 ) {
* V_66 &= ~ V_481 ;
V_20 -= V_95 ;
V_95 = V_479 ;
V_481 = ~ 0 ;
V_66 ++ ;
}
if ( V_20 ) {
V_481 &= F_371 ( V_268 ) ;
* V_66 &= ~ V_481 ;
}
}
static inline void F_373 ( struct V_10 * V_11 ,
unsigned long V_15 , unsigned long V_293 ,
unsigned long * F_350 ,
T_10 * F_130 )
{
T_10 V_463 = V_11 -> V_15 & ( ( T_1 ) V_29 - 1 ) ;
T_10 V_482 = F_369 ( V_293 ) ;
T_10 V_62 ;
V_62 = V_463 + V_15 + V_482 ;
* F_350 = V_62 >> V_126 ;
* F_130 = V_62 & ( V_29 - 1 ) ;
}
int F_374 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_293 )
{
T_18 * V_461 ;
struct V_128 * V_128 ;
unsigned long V_139 ;
T_10 V_62 ;
F_373 ( V_11 , V_15 , V_293 , & V_139 , & V_62 ) ;
V_128 = V_11 -> V_137 [ V_139 ] ;
F_44 ( ! F_205 ( V_128 ) ) ;
V_461 = F_316 ( V_128 ) ;
return 1U & ( V_461 [ V_62 ] >> ( V_293 & ( V_479 - 1 ) ) ) ;
}
void F_375 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_483 , unsigned long V_20 )
{
T_18 * V_461 ;
struct V_128 * V_128 ;
unsigned long V_139 ;
T_10 V_62 ;
const unsigned int V_268 = V_483 + V_20 ;
int V_115 = V_479 - ( V_483 % V_479 ) ;
T_18 V_480 = F_370 ( V_483 ) ;
F_373 ( V_11 , V_15 , V_483 , & V_139 , & V_62 ) ;
V_128 = V_11 -> V_137 [ V_139 ] ;
F_44 ( ! F_205 ( V_128 ) ) ;
V_461 = F_316 ( V_128 ) ;
while ( V_20 >= V_115 ) {
V_461 [ V_62 ] |= V_480 ;
V_20 -= V_115 ;
V_115 = V_479 ;
V_480 = ~ 0 ;
if ( ++ V_62 >= V_29 && V_20 > 0 ) {
V_62 = 0 ;
V_128 = V_11 -> V_137 [ ++ V_139 ] ;
F_44 ( ! F_205 ( V_128 ) ) ;
V_461 = F_316 ( V_128 ) ;
}
}
if ( V_20 ) {
V_480 &= F_371 ( V_268 ) ;
V_461 [ V_62 ] |= V_480 ;
}
}
void F_376 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_483 , unsigned long V_20 )
{
T_18 * V_461 ;
struct V_128 * V_128 ;
unsigned long V_139 ;
T_10 V_62 ;
const unsigned int V_268 = V_483 + V_20 ;
int V_95 = V_479 - ( V_483 % V_479 ) ;
T_18 V_481 = F_370 ( V_483 ) ;
F_373 ( V_11 , V_15 , V_483 , & V_139 , & V_62 ) ;
V_128 = V_11 -> V_137 [ V_139 ] ;
F_44 ( ! F_205 ( V_128 ) ) ;
V_461 = F_316 ( V_128 ) ;
while ( V_20 >= V_95 ) {
V_461 [ V_62 ] &= ~ V_481 ;
V_20 -= V_95 ;
V_95 = V_479 ;
V_481 = ~ 0 ;
if ( ++ V_62 >= V_29 && V_20 > 0 ) {
V_62 = 0 ;
V_128 = V_11 -> V_137 [ ++ V_139 ] ;
F_44 ( ! F_205 ( V_128 ) ) ;
V_461 = F_316 ( V_128 ) ;
}
}
if ( V_20 ) {
V_481 &= F_371 ( V_268 ) ;
V_461 [ V_62 ] &= ~ V_481 ;
}
}
static inline bool F_377 ( unsigned long V_436 , unsigned long V_462 , unsigned long V_20 )
{
unsigned long V_484 = ( V_436 > V_462 ) ? V_436 - V_462 : V_462 - V_436 ;
return V_484 < V_20 ;
}
static void F_378 ( struct V_128 * V_485 , struct V_128 * V_486 ,
unsigned long V_487 , unsigned long V_488 ,
unsigned long V_20 )
{
char * V_489 = F_316 ( V_485 ) ;
char * V_490 ;
int V_491 = 0 ;
if ( V_485 != V_486 ) {
V_490 = F_316 ( V_486 ) ;
} else {
V_490 = V_489 ;
if ( F_377 ( V_488 , V_487 , V_20 ) )
V_491 = 1 ;
}
if ( V_491 )
memmove ( V_489 + V_487 , V_490 + V_488 , V_20 ) ;
else
memcpy ( V_489 + V_487 , V_490 + V_488 , V_20 ) ;
}
void F_379 ( struct V_10 * V_462 , unsigned long V_476 ,
unsigned long V_477 , unsigned long V_20 )
{
struct V_40 * V_31 = V_462 -> V_31 ;
T_10 V_289 ;
T_10 V_492 ;
T_10 V_493 ;
T_10 V_463 = V_462 -> V_15 & ( ( T_1 ) V_29 - 1 ) ;
unsigned long V_494 ;
unsigned long V_495 ;
if ( V_477 + V_20 > V_462 -> V_20 ) {
F_174 ( V_31 ,
L_24 ,
V_477 , V_20 , V_462 -> V_20 ) ;
F_22 ( 1 ) ;
}
if ( V_476 + V_20 > V_462 -> V_20 ) {
F_174 ( V_31 ,
L_25 ,
V_476 , V_20 , V_462 -> V_20 ) ;
F_22 ( 1 ) ;
}
while ( V_20 > 0 ) {
V_492 = ( V_463 + V_476 ) &
( V_29 - 1 ) ;
V_493 = ( V_463 + V_477 ) &
( V_29 - 1 ) ;
V_494 = ( V_463 + V_476 ) >> V_126 ;
V_495 = ( V_463 + V_477 ) >> V_126 ;
V_289 = F_125 ( V_20 , ( unsigned long ) ( V_29 -
V_493 ) ) ;
V_289 = F_111 (unsigned long, cur,
(unsigned long)(PAGE_SIZE - dst_off_in_page)) ;
F_378 ( V_462 -> V_137 [ V_494 ] , V_462 -> V_137 [ V_495 ] ,
V_492 , V_493 , V_289 ) ;
V_477 += V_289 ;
V_476 += V_289 ;
V_20 -= V_289 ;
}
}
void F_380 ( struct V_10 * V_462 , unsigned long V_476 ,
unsigned long V_477 , unsigned long V_20 )
{
struct V_40 * V_31 = V_462 -> V_31 ;
T_10 V_289 ;
T_10 V_492 ;
T_10 V_493 ;
unsigned long V_496 = V_476 + V_20 - 1 ;
unsigned long V_497 = V_477 + V_20 - 1 ;
T_10 V_463 = V_462 -> V_15 & ( ( T_1 ) V_29 - 1 ) ;
unsigned long V_494 ;
unsigned long V_495 ;
if ( V_477 + V_20 > V_462 -> V_20 ) {
F_174 ( V_31 ,
L_26 ,
V_477 , V_20 , V_462 -> V_20 ) ;
F_22 ( 1 ) ;
}
if ( V_476 + V_20 > V_462 -> V_20 ) {
F_174 ( V_31 ,
L_27 ,
V_476 , V_20 , V_462 -> V_20 ) ;
F_22 ( 1 ) ;
}
if ( V_476 < V_477 ) {
F_379 ( V_462 , V_476 , V_477 , V_20 ) ;
return;
}
while ( V_20 > 0 ) {
V_494 = ( V_463 + V_496 ) >> V_126 ;
V_495 = ( V_463 + V_497 ) >> V_126 ;
V_492 = ( V_463 + V_496 ) &
( V_29 - 1 ) ;
V_493 = ( V_463 + V_497 ) &
( V_29 - 1 ) ;
V_289 = F_111 (unsigned long, len, src_off_in_page + 1 ) ;
V_289 = F_125 ( V_289 , V_492 + 1 ) ;
F_378 ( V_462 -> V_137 [ V_494 ] , V_462 -> V_137 [ V_495 ] ,
V_492 - V_289 + 1 ,
V_493 - V_289 + 1 , V_289 ) ;
V_496 -= V_289 ;
V_497 -= V_289 ;
V_20 -= V_289 ;
}
}
int F_381 ( struct V_128 * V_128 )
{
struct V_10 * V_11 ;
F_74 ( & V_128 -> V_27 -> V_368 ) ;
if ( ! F_195 ( V_128 ) ) {
F_77 ( & V_128 -> V_27 -> V_368 ) ;
return 1 ;
}
V_11 = (struct V_10 * ) V_128 -> V_203 ;
F_22 ( ! V_11 ) ;
F_74 ( & V_11 -> V_339 ) ;
if ( F_13 ( & V_11 -> V_17 ) != 1 || F_305 ( V_11 ) ) {
F_77 ( & V_11 -> V_339 ) ;
F_77 ( & V_128 -> V_27 -> V_368 ) ;
return 0 ;
}
F_77 ( & V_128 -> V_27 -> V_368 ) ;
if ( ! F_238 ( V_439 , & V_11 -> V_335 ) ) {
F_77 ( & V_11 -> V_339 ) ;
return 0 ;
}
return F_341 ( V_11 ) ;
}
