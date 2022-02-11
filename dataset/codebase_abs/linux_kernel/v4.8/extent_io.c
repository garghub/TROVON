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
F_15 ( V_20 L_2
L_3 ,
V_11 -> V_15 , V_11 -> V_21 , F_13 ( & V_11 -> V_17 ) ) ;
F_8 ( & V_11 -> V_14 ) ;
F_14 ( V_22 , V_11 ) ;
}
}
static inline void F_16 ( const char * V_23 ,
struct V_24 * V_25 , T_1 V_15 , T_1 V_16 )
{
struct V_26 * V_26 ;
T_1 V_27 ;
if ( ! V_25 -> V_28 )
return;
V_26 = V_25 -> V_28 -> V_29 ;
V_27 = F_17 ( V_26 ) ;
if ( V_16 >= V_30 && ( V_16 % 2 ) == 0 && V_16 != V_27 - 1 ) {
F_18 ( F_19 ( V_26 ) -> V_31 -> V_32 ,
L_4 ,
V_23 , F_20 ( V_26 ) , V_27 , V_15 , V_16 ) ;
}
}
static void F_21 ( struct V_1 * V_2 , unsigned V_33 ,
struct V_34 * V_35 ,
int V_36 )
{
int V_37 ;
if ( ! V_35 )
return;
if ( V_36 && ( V_2 -> V_2 & V_33 ) == V_33 )
return;
if ( ! V_36 && ( V_2 -> V_2 & V_33 ) == 0 )
return;
V_35 -> V_38 += V_2 -> V_16 - V_2 -> V_15 + 1 ;
V_37 = F_22 ( V_35 -> V_39 , V_2 -> V_15 , V_2 -> V_16 ,
V_40 ) ;
F_23 ( V_37 < 0 ) ;
}
static inline struct V_41 *
F_24 ( struct V_24 * V_25 )
{
if ( ! V_25 -> V_28 )
return NULL ;
return F_25 ( V_25 -> V_28 -> V_29 -> V_42 ) ;
}
int T_2 F_26 ( void )
{
V_18 = F_27 ( L_5 ,
sizeof( struct V_1 ) , 0 ,
V_43 , NULL ) ;
if ( ! V_18 )
return - V_44 ;
V_22 = F_27 ( L_6 ,
sizeof( struct V_10 ) , 0 ,
V_43 , NULL ) ;
if ( ! V_22 )
goto V_45;
V_46 = F_28 ( V_47 ,
F_29 ( struct V_48 , V_49 ) ) ;
if ( ! V_46 )
goto V_50;
if ( F_30 ( V_46 , V_47 ) )
goto V_51;
return 0 ;
V_51:
F_31 ( V_46 ) ;
V_46 = NULL ;
V_50:
F_32 ( V_22 ) ;
V_22 = NULL ;
V_45:
F_32 ( V_18 ) ;
V_18 = NULL ;
return - V_44 ;
}
void F_33 ( void )
{
F_9 () ;
F_34 () ;
F_32 ( V_18 ) ;
F_32 ( V_22 ) ;
if ( V_46 )
F_31 ( V_46 ) ;
}
void F_35 ( struct V_24 * V_25 ,
struct V_52 * V_28 )
{
V_25 -> V_2 = V_53 ;
V_25 -> V_54 = NULL ;
V_25 -> V_55 = 0 ;
F_36 ( & V_25 -> V_56 ) ;
V_25 -> V_28 = V_28 ;
}
static struct V_1 * F_37 ( T_3 V_57 )
{
struct V_1 * V_2 ;
V_2 = F_38 ( V_18 , V_57 ) ;
if ( ! V_2 )
return V_2 ;
V_2 -> V_2 = 0 ;
V_2 -> V_58 = NULL ;
F_39 ( & V_2 -> V_3 ) ;
F_3 ( & V_2 -> V_14 , & V_12 ) ;
F_40 ( & V_2 -> V_17 , 1 ) ;
F_41 ( & V_2 -> V_59 ) ;
F_42 ( V_2 , V_57 , V_60 ) ;
return V_2 ;
}
void F_43 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( F_44 ( & V_2 -> V_17 ) ) {
F_45 ( F_1 ( V_2 ) ) ;
F_7 ( & V_2 -> V_14 ) ;
F_46 ( V_2 , V_60 ) ;
F_14 ( V_18 , V_2 ) ;
}
}
static struct V_3 * F_47 ( struct V_61 * V_31 ,
struct V_3 * V_62 ,
T_1 V_63 ,
struct V_3 * V_64 ,
struct V_3 * * * V_65 ,
struct V_3 * * V_66 )
{
struct V_3 * * V_67 ;
struct V_3 * V_68 = NULL ;
struct V_69 * V_9 ;
if ( V_65 && V_66 ) {
V_67 = * V_65 ;
V_68 = * V_66 ;
goto V_70;
}
V_67 = V_62 ? & V_62 : & V_31 -> V_3 ;
while ( * V_67 ) {
V_68 = * V_67 ;
V_9 = F_48 ( V_68 , struct V_69 , V_3 ) ;
if ( V_63 < V_9 -> V_15 )
V_67 = & ( * V_67 ) -> V_71 ;
else if ( V_63 > V_9 -> V_16 )
V_67 = & ( * V_67 ) -> V_72 ;
else
return V_68 ;
}
V_70:
F_49 ( V_64 , V_68 , V_67 ) ;
F_50 ( V_64 , V_31 ) ;
return NULL ;
}
static struct V_3 * F_51 ( struct V_24 * V_25 , T_1 V_63 ,
struct V_3 * * V_73 ,
struct V_3 * * V_74 ,
struct V_3 * * * V_75 ,
struct V_3 * * V_76 )
{
struct V_61 * V_31 = & V_25 -> V_2 ;
struct V_3 * * V_77 = & V_31 -> V_3 ;
struct V_3 * V_78 = NULL ;
struct V_3 * V_79 = NULL ;
struct V_69 * V_9 ;
struct V_69 * V_80 = NULL ;
while ( * V_77 ) {
V_78 = * V_77 ;
V_9 = F_48 ( V_78 , struct V_69 , V_3 ) ;
V_80 = V_9 ;
if ( V_63 < V_9 -> V_15 )
V_77 = & ( * V_77 ) -> V_71 ;
else if ( V_63 > V_9 -> V_16 )
V_77 = & ( * V_77 ) -> V_72 ;
else
return * V_77 ;
}
if ( V_75 )
* V_75 = V_77 ;
if ( V_76 )
* V_76 = V_78 ;
if ( V_73 ) {
V_79 = V_78 ;
while ( V_78 && V_63 > V_80 -> V_16 ) {
V_78 = F_52 ( V_78 ) ;
V_80 = F_48 ( V_78 , struct V_69 , V_3 ) ;
}
* V_73 = V_78 ;
V_78 = V_79 ;
}
if ( V_74 ) {
V_80 = F_48 ( V_78 , struct V_69 , V_3 ) ;
while ( V_78 && V_63 < V_80 -> V_15 ) {
V_78 = F_53 ( V_78 ) ;
V_80 = F_48 ( V_78 , struct V_69 , V_3 ) ;
}
* V_74 = V_78 ;
}
return NULL ;
}
static inline struct V_3 *
F_54 ( struct V_24 * V_25 ,
T_1 V_63 ,
struct V_3 * * * V_75 ,
struct V_3 * * V_76 )
{
struct V_3 * V_78 = NULL ;
struct V_3 * V_37 ;
V_37 = F_51 ( V_25 , V_63 , & V_78 , NULL , V_75 , V_76 ) ;
if ( ! V_37 )
return V_78 ;
return V_37 ;
}
static inline struct V_3 * F_55 ( struct V_24 * V_25 ,
T_1 V_63 )
{
return F_54 ( V_25 , V_63 , NULL , NULL ) ;
}
static void F_56 ( struct V_24 * V_25 , struct V_1 * V_5 ,
struct V_1 * V_81 )
{
if ( V_25 -> V_54 && V_25 -> V_54 -> V_82 )
V_25 -> V_54 -> V_82 ( V_25 -> V_28 -> V_29 , V_5 ,
V_81 ) ;
}
static void F_57 ( struct V_24 * V_25 ,
struct V_1 * V_2 )
{
struct V_1 * V_81 ;
struct V_3 * V_83 ;
if ( V_2 -> V_2 & ( V_84 | V_85 ) )
return;
V_83 = F_53 ( & V_2 -> V_3 ) ;
if ( V_83 ) {
V_81 = F_48 ( V_83 , struct V_1 , V_3 ) ;
if ( V_81 -> V_16 == V_2 -> V_15 - 1 &&
V_81 -> V_2 == V_2 -> V_2 ) {
F_56 ( V_25 , V_2 , V_81 ) ;
V_2 -> V_15 = V_81 -> V_15 ;
F_58 ( & V_81 -> V_3 , & V_25 -> V_2 ) ;
F_39 ( & V_81 -> V_3 ) ;
F_43 ( V_81 ) ;
}
}
V_83 = F_52 ( & V_2 -> V_3 ) ;
if ( V_83 ) {
V_81 = F_48 ( V_83 , struct V_1 , V_3 ) ;
if ( V_81 -> V_15 == V_2 -> V_16 + 1 &&
V_81 -> V_2 == V_2 -> V_2 ) {
F_56 ( V_25 , V_2 , V_81 ) ;
V_2 -> V_16 = V_81 -> V_16 ;
F_58 ( & V_81 -> V_3 , & V_25 -> V_2 ) ;
F_39 ( & V_81 -> V_3 ) ;
F_43 ( V_81 ) ;
}
}
}
static void F_59 ( struct V_24 * V_25 ,
struct V_1 * V_2 , unsigned * V_33 )
{
if ( V_25 -> V_54 && V_25 -> V_54 -> V_86 )
V_25 -> V_54 -> V_86 ( V_25 -> V_28 -> V_29 , V_2 , V_33 ) ;
}
static void F_60 ( struct V_24 * V_25 ,
struct V_1 * V_2 , unsigned * V_33 )
{
if ( V_25 -> V_54 && V_25 -> V_54 -> V_87 )
V_25 -> V_54 -> V_87 ( V_25 -> V_28 -> V_29 , V_2 , V_33 ) ;
}
static int F_61 ( struct V_24 * V_25 ,
struct V_1 * V_2 , T_1 V_15 , T_1 V_16 ,
struct V_3 * * * V_67 ,
struct V_3 * * V_68 ,
unsigned * V_33 , struct V_34 * V_35 )
{
struct V_3 * V_64 ;
if ( V_16 < V_15 )
F_62 ( 1 , V_20 L_7 ,
V_16 , V_15 ) ;
V_2 -> V_15 = V_15 ;
V_2 -> V_16 = V_16 ;
F_63 ( V_25 , V_2 , V_33 , V_35 ) ;
V_64 = F_47 ( & V_25 -> V_2 , NULL , V_16 , & V_2 -> V_3 , V_67 , V_68 ) ;
if ( V_64 ) {
struct V_1 * V_88 ;
V_88 = F_48 ( V_64 , struct V_1 , V_3 ) ;
F_15 ( V_20 L_8
L_9 ,
V_88 -> V_15 , V_88 -> V_16 , V_15 , V_16 ) ;
return - V_89 ;
}
F_57 ( V_25 , V_2 ) ;
return 0 ;
}
static void F_64 ( struct V_24 * V_25 , struct V_1 * V_90 ,
T_1 V_91 )
{
if ( V_25 -> V_54 && V_25 -> V_54 -> V_92 )
V_25 -> V_54 -> V_92 ( V_25 -> V_28 -> V_29 , V_90 , V_91 ) ;
}
static int F_65 ( struct V_24 * V_25 , struct V_1 * V_90 ,
struct V_1 * V_93 , T_1 V_91 )
{
struct V_3 * V_64 ;
F_64 ( V_25 , V_90 , V_91 ) ;
V_93 -> V_15 = V_90 -> V_15 ;
V_93 -> V_16 = V_91 - 1 ;
V_93 -> V_2 = V_90 -> V_2 ;
V_90 -> V_15 = V_91 ;
V_64 = F_47 ( & V_25 -> V_2 , & V_90 -> V_3 , V_93 -> V_16 ,
& V_93 -> V_3 , NULL , NULL ) ;
if ( V_64 ) {
F_43 ( V_93 ) ;
return - V_89 ;
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
static struct V_1 * F_67 ( struct V_24 * V_25 ,
struct V_1 * V_2 ,
unsigned * V_33 , int V_94 ,
struct V_34 * V_35 )
{
struct V_1 * V_13 ;
unsigned V_95 = * V_33 & ~ V_96 ;
if ( ( V_95 & V_97 ) && ( V_2 -> V_2 & V_97 ) ) {
T_1 V_98 = V_2 -> V_16 - V_2 -> V_15 + 1 ;
F_45 ( V_98 > V_25 -> V_55 ) ;
V_25 -> V_55 -= V_98 ;
}
F_60 ( V_25 , V_2 , V_33 ) ;
F_21 ( V_2 , V_95 , V_35 , 0 ) ;
V_2 -> V_2 &= ~ V_95 ;
if ( V_94 )
F_68 ( & V_2 -> V_59 ) ;
if ( V_2 -> V_2 == 0 ) {
V_13 = F_66 ( V_2 ) ;
if ( F_1 ( V_2 ) ) {
F_58 ( & V_2 -> V_3 , & V_25 -> V_2 ) ;
F_39 ( & V_2 -> V_3 ) ;
F_43 ( V_2 ) ;
} else {
F_45 ( 1 ) ;
}
} else {
F_57 ( V_25 , V_2 ) ;
V_13 = F_66 ( V_2 ) ;
}
return V_13 ;
}
static struct V_1 *
F_69 ( struct V_1 * V_93 )
{
if ( ! V_93 )
V_93 = F_37 ( V_40 ) ;
return V_93 ;
}
static void F_70 ( struct V_24 * V_25 , int V_99 )
{
F_71 ( F_24 ( V_25 ) , V_99 , L_10
L_11
L_12 ) ;
}
static int F_72 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned V_33 , int V_94 , int V_100 ,
struct V_1 * * V_101 ,
T_3 V_57 , struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_1 * V_102 ;
struct V_1 * V_93 = NULL ;
struct V_3 * V_64 ;
T_1 V_103 ;
int V_99 ;
int V_104 = 0 ;
F_73 ( V_25 , V_15 , V_16 ) ;
if ( V_33 & V_105 )
V_33 |= V_106 ;
if ( V_100 )
V_33 |= ~ V_96 ;
V_33 |= V_107 ;
if ( V_33 & ( V_84 | V_85 ) )
V_104 = 1 ;
V_108:
if ( ! V_93 && F_74 ( V_57 ) ) {
V_93 = F_37 ( V_57 ) ;
}
F_75 ( & V_25 -> V_56 ) ;
if ( V_101 ) {
V_102 = * V_101 ;
if ( V_104 ) {
* V_101 = NULL ;
V_101 = NULL ;
}
if ( V_102 && F_1 ( V_102 ) &&
V_102 -> V_15 <= V_15 && V_102 -> V_16 > V_15 ) {
if ( V_104 )
F_76 ( & V_102 -> V_17 ) ;
V_2 = V_102 ;
goto V_109;
}
if ( V_104 )
F_43 ( V_102 ) ;
}
V_64 = F_55 ( V_25 , V_15 ) ;
if ( ! V_64 )
goto V_110;
V_2 = F_48 ( V_64 , struct V_1 , V_3 ) ;
V_109:
if ( V_2 -> V_15 > V_16 )
goto V_110;
F_45 ( V_2 -> V_16 < V_15 ) ;
V_103 = V_2 -> V_16 ;
if ( ! ( V_2 -> V_2 & V_33 ) ) {
V_2 = F_66 ( V_2 ) ;
goto V_13;
}
if ( V_2 -> V_15 < V_15 ) {
V_93 = F_69 ( V_93 ) ;
F_23 ( ! V_93 ) ;
V_99 = F_65 ( V_25 , V_2 , V_93 , V_15 ) ;
if ( V_99 )
F_70 ( V_25 , V_99 ) ;
V_93 = NULL ;
if ( V_99 )
goto V_110;
if ( V_2 -> V_16 <= V_16 ) {
V_2 = F_67 ( V_25 , V_2 , & V_33 , V_94 ,
V_35 ) ;
goto V_13;
}
goto V_111;
}
if ( V_2 -> V_15 <= V_16 && V_2 -> V_16 > V_16 ) {
V_93 = F_69 ( V_93 ) ;
F_23 ( ! V_93 ) ;
V_99 = F_65 ( V_25 , V_2 , V_93 , V_16 + 1 ) ;
if ( V_99 )
F_70 ( V_25 , V_99 ) ;
if ( V_94 )
F_68 ( & V_2 -> V_59 ) ;
F_67 ( V_25 , V_93 , & V_33 , V_94 , V_35 ) ;
V_93 = NULL ;
goto V_110;
}
V_2 = F_67 ( V_25 , V_2 , & V_33 , V_94 , V_35 ) ;
V_13:
if ( V_103 == ( T_1 ) - 1 )
goto V_110;
V_15 = V_103 + 1 ;
if ( V_15 <= V_16 && V_2 && ! F_77 () )
goto V_109;
V_111:
if ( V_15 > V_16 )
goto V_110;
F_78 ( & V_25 -> V_56 ) ;
if ( F_74 ( V_57 ) )
F_79 () ;
goto V_108;
V_110:
F_78 ( & V_25 -> V_56 ) ;
if ( V_93 )
F_43 ( V_93 ) ;
return 0 ;
}
static void F_80 ( struct V_24 * V_25 ,
struct V_1 * V_2 )
__releases( V_25 -> V_56 )
__acquires( V_25 -> V_56 )
{
F_81 ( V_112 ) ;
F_82 ( & V_2 -> V_59 , & V_112 , V_113 ) ;
F_78 ( & V_25 -> V_56 ) ;
F_83 () ;
F_75 ( & V_25 -> V_56 ) ;
F_84 ( & V_2 -> V_59 , & V_112 ) ;
}
static void F_85 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned long V_33 )
{
struct V_1 * V_2 ;
struct V_3 * V_64 ;
F_73 ( V_25 , V_15 , V_16 ) ;
F_75 ( & V_25 -> V_56 ) ;
V_108:
while ( 1 ) {
V_64 = F_55 ( V_25 , V_15 ) ;
V_114:
if ( ! V_64 )
break;
V_2 = F_48 ( V_64 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 > V_16 )
goto V_110;
if ( V_2 -> V_2 & V_33 ) {
V_15 = V_2 -> V_15 ;
F_86 ( & V_2 -> V_17 ) ;
F_80 ( V_25 , V_2 ) ;
F_43 ( V_2 ) ;
goto V_108;
}
V_15 = V_2 -> V_16 + 1 ;
if ( V_15 > V_16 )
break;
if ( ! F_87 ( & V_25 -> V_56 ) ) {
V_64 = F_52 ( V_64 ) ;
goto V_114;
}
}
V_110:
F_78 ( & V_25 -> V_56 ) ;
}
static void F_63 ( struct V_24 * V_25 ,
struct V_1 * V_2 ,
unsigned * V_33 , struct V_34 * V_35 )
{
unsigned V_115 = * V_33 & ~ V_96 ;
F_59 ( V_25 , V_2 , V_33 ) ;
if ( ( V_115 & V_97 ) && ! ( V_2 -> V_2 & V_97 ) ) {
T_1 V_98 = V_2 -> V_16 - V_2 -> V_15 + 1 ;
V_25 -> V_55 += V_98 ;
}
F_21 ( V_2 , V_115 , V_35 , 1 ) ;
V_2 -> V_2 |= V_115 ;
}
static void F_88 ( struct V_1 * V_2 ,
struct V_1 * * V_116 ,
unsigned V_7 )
{
if ( V_116 && ! ( * V_116 ) ) {
if ( ! V_7 || ( V_2 -> V_2 & V_7 ) ) {
* V_116 = V_2 ;
F_86 ( & V_2 -> V_17 ) ;
}
}
}
static void F_89 ( struct V_1 * V_2 ,
struct V_1 * * V_116 )
{
return F_88 ( V_2 , V_116 ,
V_84 | V_85 ) ;
}
static int T_4
F_90 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned V_33 , unsigned V_117 ,
T_1 * V_118 , struct V_1 * * V_101 ,
T_3 V_57 , struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_1 * V_93 = NULL ;
struct V_3 * V_64 ;
struct V_3 * * V_67 ;
struct V_3 * V_68 ;
int V_99 = 0 ;
T_1 V_119 ;
T_1 V_103 ;
F_73 ( V_25 , V_15 , V_16 ) ;
V_33 |= V_107 ;
V_108:
if ( ! V_93 && F_74 ( V_57 ) ) {
V_93 = F_37 ( V_57 ) ;
}
F_75 ( & V_25 -> V_56 ) ;
if ( V_101 && * V_101 ) {
V_2 = * V_101 ;
if ( V_2 -> V_15 <= V_15 && V_2 -> V_16 > V_15 &&
F_1 ( V_2 ) ) {
V_64 = & V_2 -> V_3 ;
goto V_109;
}
}
V_64 = F_54 ( V_25 , V_15 , & V_67 , & V_68 ) ;
if ( ! V_64 ) {
V_93 = F_69 ( V_93 ) ;
F_23 ( ! V_93 ) ;
V_99 = F_61 ( V_25 , V_93 , V_15 , V_16 ,
& V_67 , & V_68 , & V_33 , V_35 ) ;
if ( V_99 )
F_70 ( V_25 , V_99 ) ;
F_89 ( V_93 , V_101 ) ;
V_93 = NULL ;
goto V_110;
}
V_2 = F_48 ( V_64 , struct V_1 , V_3 ) ;
V_109:
V_119 = V_2 -> V_15 ;
V_103 = V_2 -> V_16 ;
if ( V_2 -> V_15 == V_15 && V_2 -> V_16 <= V_16 ) {
if ( V_2 -> V_2 & V_117 ) {
* V_118 = V_2 -> V_15 ;
V_99 = - V_89 ;
goto V_110;
}
F_63 ( V_25 , V_2 , & V_33 , V_35 ) ;
F_89 ( V_2 , V_101 ) ;
F_57 ( V_25 , V_2 ) ;
if ( V_103 == ( T_1 ) - 1 )
goto V_110;
V_15 = V_103 + 1 ;
V_2 = F_66 ( V_2 ) ;
if ( V_15 < V_16 && V_2 && V_2 -> V_15 == V_15 &&
! F_77 () )
goto V_109;
goto V_111;
}
if ( V_2 -> V_15 < V_15 ) {
if ( V_2 -> V_2 & V_117 ) {
* V_118 = V_15 ;
V_99 = - V_89 ;
goto V_110;
}
V_93 = F_69 ( V_93 ) ;
F_23 ( ! V_93 ) ;
V_99 = F_65 ( V_25 , V_2 , V_93 , V_15 ) ;
if ( V_99 )
F_70 ( V_25 , V_99 ) ;
V_93 = NULL ;
if ( V_99 )
goto V_110;
if ( V_2 -> V_16 <= V_16 ) {
F_63 ( V_25 , V_2 , & V_33 , V_35 ) ;
F_89 ( V_2 , V_101 ) ;
F_57 ( V_25 , V_2 ) ;
if ( V_103 == ( T_1 ) - 1 )
goto V_110;
V_15 = V_103 + 1 ;
V_2 = F_66 ( V_2 ) ;
if ( V_15 < V_16 && V_2 && V_2 -> V_15 == V_15 &&
! F_77 () )
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
V_93 = F_69 ( V_93 ) ;
F_23 ( ! V_93 ) ;
V_99 = F_61 ( V_25 , V_93 , V_15 , V_120 ,
NULL , NULL , & V_33 , V_35 ) ;
if ( V_99 )
F_70 ( V_25 , V_99 ) ;
F_89 ( V_93 , V_101 ) ;
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
V_93 = F_69 ( V_93 ) ;
F_23 ( ! V_93 ) ;
V_99 = F_65 ( V_25 , V_2 , V_93 , V_16 + 1 ) ;
if ( V_99 )
F_70 ( V_25 , V_99 ) ;
F_63 ( V_25 , V_93 , & V_33 , V_35 ) ;
F_89 ( V_93 , V_101 ) ;
F_57 ( V_25 , V_93 ) ;
V_93 = NULL ;
goto V_110;
}
V_111:
if ( V_15 > V_16 )
goto V_110;
F_78 ( & V_25 -> V_56 ) ;
if ( F_74 ( V_57 ) )
F_79 () ;
goto V_108;
V_110:
F_78 ( & V_25 -> V_56 ) ;
if ( V_93 )
F_43 ( V_93 ) ;
return V_99 ;
}
int F_91 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned V_33 , T_1 * V_118 ,
struct V_1 * * V_101 , T_3 V_57 )
{
return F_90 ( V_25 , V_15 , V_16 , V_33 , 0 , V_118 ,
V_101 , V_57 , NULL ) ;
}
int F_92 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned V_33 , unsigned V_121 ,
struct V_1 * * V_101 )
{
struct V_1 * V_2 ;
struct V_1 * V_93 = NULL ;
struct V_3 * V_64 ;
struct V_3 * * V_67 ;
struct V_3 * V_68 ;
int V_99 = 0 ;
T_1 V_119 ;
T_1 V_103 ;
bool V_122 = true ;
F_73 ( V_25 , V_15 , V_16 ) ;
V_108:
if ( ! V_93 ) {
V_93 = F_37 ( V_123 ) ;
if ( ! V_93 && ! V_122 )
return - V_44 ;
}
F_75 ( & V_25 -> V_56 ) ;
if ( V_101 && * V_101 ) {
V_2 = * V_101 ;
if ( V_2 -> V_15 <= V_15 && V_2 -> V_16 > V_15 &&
F_1 ( V_2 ) ) {
V_64 = & V_2 -> V_3 ;
goto V_109;
}
}
V_64 = F_54 ( V_25 , V_15 , & V_67 , & V_68 ) ;
if ( ! V_64 ) {
V_93 = F_69 ( V_93 ) ;
if ( ! V_93 ) {
V_99 = - V_44 ;
goto V_110;
}
V_99 = F_61 ( V_25 , V_93 , V_15 , V_16 ,
& V_67 , & V_68 , & V_33 , NULL ) ;
if ( V_99 )
F_70 ( V_25 , V_99 ) ;
F_89 ( V_93 , V_101 ) ;
V_93 = NULL ;
goto V_110;
}
V_2 = F_48 ( V_64 , struct V_1 , V_3 ) ;
V_109:
V_119 = V_2 -> V_15 ;
V_103 = V_2 -> V_16 ;
if ( V_2 -> V_15 == V_15 && V_2 -> V_16 <= V_16 ) {
F_63 ( V_25 , V_2 , & V_33 , NULL ) ;
F_89 ( V_2 , V_101 ) ;
V_2 = F_67 ( V_25 , V_2 , & V_121 , 0 , NULL ) ;
if ( V_103 == ( T_1 ) - 1 )
goto V_110;
V_15 = V_103 + 1 ;
if ( V_15 < V_16 && V_2 && V_2 -> V_15 == V_15 &&
! F_77 () )
goto V_109;
goto V_111;
}
if ( V_2 -> V_15 < V_15 ) {
V_93 = F_69 ( V_93 ) ;
if ( ! V_93 ) {
V_99 = - V_44 ;
goto V_110;
}
V_99 = F_65 ( V_25 , V_2 , V_93 , V_15 ) ;
if ( V_99 )
F_70 ( V_25 , V_99 ) ;
V_93 = NULL ;
if ( V_99 )
goto V_110;
if ( V_2 -> V_16 <= V_16 ) {
F_63 ( V_25 , V_2 , & V_33 , NULL ) ;
F_89 ( V_2 , V_101 ) ;
V_2 = F_67 ( V_25 , V_2 , & V_121 , 0 ,
NULL ) ;
if ( V_103 == ( T_1 ) - 1 )
goto V_110;
V_15 = V_103 + 1 ;
if ( V_15 < V_16 && V_2 && V_2 -> V_15 == V_15 &&
! F_77 () )
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
V_93 = F_69 ( V_93 ) ;
if ( ! V_93 ) {
V_99 = - V_44 ;
goto V_110;
}
V_99 = F_61 ( V_25 , V_93 , V_15 , V_120 ,
NULL , NULL , & V_33 , NULL ) ;
if ( V_99 )
F_70 ( V_25 , V_99 ) ;
F_89 ( V_93 , V_101 ) ;
V_93 = NULL ;
V_15 = V_120 + 1 ;
goto V_111;
}
if ( V_2 -> V_15 <= V_16 && V_2 -> V_16 > V_16 ) {
V_93 = F_69 ( V_93 ) ;
if ( ! V_93 ) {
V_99 = - V_44 ;
goto V_110;
}
V_99 = F_65 ( V_25 , V_2 , V_93 , V_16 + 1 ) ;
if ( V_99 )
F_70 ( V_25 , V_99 ) ;
F_63 ( V_25 , V_93 , & V_33 , NULL ) ;
F_89 ( V_93 , V_101 ) ;
F_67 ( V_25 , V_93 , & V_121 , 0 , NULL ) ;
V_93 = NULL ;
goto V_110;
}
V_111:
if ( V_15 > V_16 )
goto V_110;
F_78 ( & V_25 -> V_56 ) ;
F_79 () ;
V_122 = false ;
goto V_108;
V_110:
F_78 ( & V_25 -> V_56 ) ;
if ( V_93 )
F_43 ( V_93 ) ;
return V_99 ;
}
int F_93 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned V_33 , struct V_34 * V_35 )
{
F_23 ( V_33 & V_124 ) ;
return F_90 ( V_25 , V_15 , V_16 , V_33 , 0 , NULL , NULL , V_123 ,
V_35 ) ;
}
int F_94 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned V_33 , int V_94 , int V_100 ,
struct V_1 * * V_102 , T_3 V_57 )
{
return F_72 ( V_25 , V_15 , V_16 , V_33 , V_94 , V_100 ,
V_102 , V_57 , NULL ) ;
}
int F_95 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned V_33 , struct V_34 * V_35 )
{
F_23 ( V_33 & V_124 ) ;
return F_72 ( V_25 , V_15 , V_16 , V_33 , 0 , 0 , NULL , V_123 ,
V_35 ) ;
}
int F_96 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
struct V_1 * * V_101 )
{
int V_99 ;
T_1 V_118 ;
while ( 1 ) {
V_99 = F_90 ( V_25 , V_15 , V_16 , V_124 ,
V_124 , & V_118 ,
V_101 , V_123 , NULL ) ;
if ( V_99 == - V_89 ) {
F_85 ( V_25 , V_118 , V_16 , V_124 ) ;
V_15 = V_118 ;
} else
break;
F_45 ( V_15 > V_16 ) ;
}
return V_99 ;
}
int F_97 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 )
{
int V_99 ;
T_1 V_118 ;
V_99 = F_90 ( V_25 , V_15 , V_16 , V_124 , V_124 ,
& V_118 , NULL , V_123 , NULL ) ;
if ( V_99 == - V_89 ) {
if ( V_118 > V_15 )
F_94 ( V_25 , V_15 , V_118 - 1 ,
V_124 , 1 , 0 , NULL , V_123 ) ;
return 0 ;
}
return 1 ;
}
void F_98 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_125 = V_15 >> V_126 ;
unsigned long V_127 = V_16 >> V_126 ;
struct V_128 * V_128 ;
while ( V_125 <= V_127 ) {
V_128 = F_99 ( V_26 -> V_129 , V_125 ) ;
F_23 ( ! V_128 ) ;
F_100 ( V_128 ) ;
F_101 ( V_128 ) ;
V_125 ++ ;
}
}
void F_102 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_125 = V_15 >> V_126 ;
unsigned long V_127 = V_16 >> V_126 ;
struct V_128 * V_128 ;
while ( V_125 <= V_127 ) {
V_128 = F_99 ( V_26 -> V_129 , V_125 ) ;
F_23 ( ! V_128 ) ;
F_103 ( V_128 ) ;
F_104 ( V_128 ) ;
F_101 ( V_128 ) ;
V_125 ++ ;
}
}
static void F_105 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_125 = V_15 >> V_126 ;
unsigned long V_127 = V_16 >> V_126 ;
struct V_128 * V_128 ;
while ( V_125 <= V_127 ) {
V_128 = F_99 ( V_25 -> V_28 , V_125 ) ;
F_23 ( ! V_128 ) ;
F_106 ( V_128 ) ;
F_101 ( V_128 ) ;
V_125 ++ ;
}
}
static struct V_1 *
F_107 ( struct V_24 * V_25 ,
T_1 V_15 , unsigned V_33 )
{
struct V_3 * V_64 ;
struct V_1 * V_2 ;
V_64 = F_55 ( V_25 , V_15 ) ;
if ( ! V_64 )
goto V_110;
while ( 1 ) {
V_2 = F_48 ( V_64 , struct V_1 , V_3 ) ;
if ( V_2 -> V_16 >= V_15 && ( V_2 -> V_2 & V_33 ) )
return V_2 ;
V_64 = F_52 ( V_64 ) ;
if ( ! V_64 )
break;
}
V_110:
return NULL ;
}
int F_108 ( struct V_24 * V_25 , T_1 V_15 ,
T_1 * V_130 , T_1 * V_131 , unsigned V_33 ,
struct V_1 * * V_101 )
{
struct V_1 * V_2 ;
struct V_3 * V_77 ;
int V_37 = 1 ;
F_75 ( & V_25 -> V_56 ) ;
if ( V_101 && * V_101 ) {
V_2 = * V_101 ;
if ( V_2 -> V_16 == V_15 - 1 && F_1 ( V_2 ) ) {
V_77 = F_52 ( & V_2 -> V_3 ) ;
while ( V_77 ) {
V_2 = F_48 ( V_77 , struct V_1 ,
V_3 ) ;
if ( V_2 -> V_2 & V_33 )
goto V_132;
V_77 = F_52 ( V_77 ) ;
}
F_43 ( * V_101 ) ;
* V_101 = NULL ;
goto V_110;
}
F_43 ( * V_101 ) ;
* V_101 = NULL ;
}
V_2 = F_107 ( V_25 , V_15 , V_33 ) ;
V_132:
if ( V_2 ) {
F_88 ( V_2 , V_101 , 0 ) ;
* V_130 = V_2 -> V_15 ;
* V_131 = V_2 -> V_16 ;
V_37 = 0 ;
}
V_110:
F_78 ( & V_25 -> V_56 ) ;
return V_37 ;
}
static T_5 T_1 F_109 ( struct V_24 * V_25 ,
T_1 * V_15 , T_1 * V_16 , T_1 V_133 ,
struct V_1 * * V_101 )
{
struct V_3 * V_64 ;
struct V_1 * V_2 ;
T_1 V_134 = * V_15 ;
T_1 V_88 = 0 ;
T_1 V_135 = 0 ;
F_75 ( & V_25 -> V_56 ) ;
V_64 = F_55 ( V_25 , V_134 ) ;
if ( ! V_64 ) {
if ( ! V_88 )
* V_16 = ( T_1 ) - 1 ;
goto V_110;
}
while ( 1 ) {
V_2 = F_48 ( V_64 , struct V_1 , V_3 ) ;
if ( V_88 && ( V_2 -> V_15 != V_134 ||
( V_2 -> V_2 & V_85 ) ) ) {
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
F_86 ( & V_2 -> V_17 ) ;
}
V_88 ++ ;
* V_16 = V_2 -> V_16 ;
V_134 = V_2 -> V_16 + 1 ;
V_64 = F_52 ( V_64 ) ;
V_135 += V_2 -> V_16 - V_2 -> V_15 + 1 ;
if ( V_135 >= V_133 )
break;
if ( ! V_64 )
break;
}
V_110:
F_78 ( & V_25 -> V_56 ) ;
return V_88 ;
}
static T_5 void F_110 ( struct V_26 * V_26 ,
struct V_128 * V_136 ,
T_1 V_15 , T_1 V_16 )
{
int V_37 ;
struct V_128 * V_137 [ 16 ] ;
unsigned long V_125 = V_15 >> V_126 ;
unsigned long V_127 = V_16 >> V_126 ;
unsigned long V_138 = V_127 - V_125 + 1 ;
int V_139 ;
if ( V_125 == V_136 -> V_125 && V_127 == V_125 )
return;
while ( V_138 > 0 ) {
V_37 = F_111 ( V_26 -> V_129 , V_125 ,
F_112 (unsigned long, nr_pages,
ARRAY_SIZE(pages)) , V_137 ) ;
for ( V_139 = 0 ; V_139 < V_37 ; V_139 ++ ) {
if ( V_137 [ V_139 ] != V_136 )
F_113 ( V_137 [ V_139 ] ) ;
F_101 ( V_137 [ V_139 ] ) ;
}
V_138 -= V_37 ;
V_125 += V_37 ;
F_79 () ;
}
}
static T_5 int F_114 ( struct V_26 * V_26 ,
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
int V_37 ;
int V_139 ;
if ( V_125 == V_136 -> V_125 && V_125 == V_127 )
return 0 ;
V_144 = V_127 - V_125 + 1 ;
while ( V_144 > 0 ) {
V_37 = F_111 ( V_26 -> V_129 , V_125 ,
F_112 (unsigned long,
nrpages, ARRAY_SIZE(pages)) , V_137 ) ;
if ( V_37 == 0 ) {
V_37 = - V_145 ;
goto V_146;
}
for ( V_139 = 0 ; V_139 < V_37 ; V_139 ++ ) {
if ( V_137 [ V_139 ] != V_136 ) {
F_115 ( V_137 [ V_139 ] ) ;
if ( ! F_116 ( V_137 [ V_139 ] ) ||
V_137 [ V_139 ] -> V_28 != V_26 -> V_129 ) {
V_37 = - V_145 ;
F_113 ( V_137 [ V_139 ] ) ;
F_101 ( V_137 [ V_139 ] ) ;
goto V_146;
}
}
F_101 ( V_137 [ V_139 ] ) ;
V_143 ++ ;
}
V_144 -= V_37 ;
V_125 += V_37 ;
F_79 () ;
}
V_37 = 0 ;
V_146:
if ( V_37 && V_143 ) {
F_110 ( V_26 , V_136 ,
V_140 ,
( ( T_1 ) ( V_142 + V_143 - 1 ) ) <<
V_126 ) ;
}
return V_37 ;
}
STATIC T_1 F_117 ( struct V_26 * V_26 ,
struct V_24 * V_25 ,
struct V_128 * V_136 , T_1 * V_15 ,
T_1 * V_16 , T_1 V_133 )
{
T_1 V_140 ;
T_1 V_141 ;
T_1 V_88 ;
struct V_1 * V_101 = NULL ;
int V_37 ;
int V_147 = 0 ;
V_108:
V_140 = * V_15 ;
V_141 = 0 ;
V_88 = F_109 ( V_25 , & V_140 , & V_141 ,
V_133 , & V_101 ) ;
if ( ! V_88 || V_141 <= * V_15 ) {
* V_15 = V_140 ;
* V_16 = V_141 ;
F_43 ( V_101 ) ;
return 0 ;
}
if ( V_140 < * V_15 )
V_140 = * V_15 ;
if ( V_141 + 1 - V_140 > V_133 )
V_141 = V_140 + V_133 - 1 ;
V_37 = F_114 ( V_26 , V_136 ,
V_140 , V_141 ) ;
if ( V_37 == - V_145 ) {
F_43 ( V_101 ) ;
V_101 = NULL ;
if ( ! V_147 ) {
V_133 = V_30 ;
V_147 = 1 ;
goto V_108;
} else {
V_88 = 0 ;
goto V_148;
}
}
F_23 ( V_37 ) ;
F_96 ( V_25 , V_140 , V_141 , & V_101 ) ;
V_37 = F_118 ( V_25 , V_140 , V_141 ,
V_105 , 1 , V_101 ) ;
if ( ! V_37 ) {
F_119 ( V_25 , V_140 , V_141 ,
& V_101 , V_123 ) ;
F_110 ( V_26 , V_136 ,
V_140 , V_141 ) ;
F_79 () ;
goto V_108;
}
F_43 ( V_101 ) ;
* V_15 = V_140 ;
* V_16 = V_141 ;
V_148:
return V_88 ;
}
void F_120 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_16 ,
struct V_128 * V_136 ,
unsigned V_121 ,
unsigned long V_149 )
{
struct V_24 * V_25 = & F_19 ( V_26 ) -> V_150 ;
int V_37 ;
struct V_128 * V_137 [ 16 ] ;
unsigned long V_125 = V_15 >> V_126 ;
unsigned long V_127 = V_16 >> V_126 ;
unsigned long V_138 = V_127 - V_125 + 1 ;
int V_139 ;
F_94 ( V_25 , V_15 , V_16 , V_121 , 1 , 0 , NULL , V_123 ) ;
if ( V_149 == 0 )
return;
if ( ( V_149 & V_151 ) && V_138 > 0 )
F_121 ( V_26 -> V_129 , - V_152 ) ;
while ( V_138 > 0 ) {
V_37 = F_111 ( V_26 -> V_129 , V_125 ,
F_112 (unsigned long,
nr_pages, ARRAY_SIZE(pages)) , V_137 ) ;
for ( V_139 = 0 ; V_139 < V_37 ; V_139 ++ ) {
if ( V_149 & V_153 )
F_122 ( V_137 [ V_139 ] ) ;
if ( V_137 [ V_139 ] == V_136 ) {
F_101 ( V_137 [ V_139 ] ) ;
continue;
}
if ( V_149 & V_154 )
F_100 ( V_137 [ V_139 ] ) ;
if ( V_149 & V_155 )
F_106 ( V_137 [ V_139 ] ) ;
if ( V_149 & V_151 )
F_123 ( V_137 [ V_139 ] ) ;
if ( V_149 & V_156 )
F_124 ( V_137 [ V_139 ] ) ;
if ( V_149 & V_157 )
F_113 ( V_137 [ V_139 ] ) ;
F_101 ( V_137 [ V_139 ] ) ;
}
V_138 -= V_37 ;
V_125 += V_37 ;
F_79 () ;
}
}
T_1 F_125 ( struct V_24 * V_25 ,
T_1 * V_15 , T_1 V_158 , T_1 V_133 ,
unsigned V_33 , int V_159 )
{
struct V_3 * V_64 ;
struct V_1 * V_2 ;
T_1 V_134 = * V_15 ;
T_1 V_135 = 0 ;
T_1 V_160 = 0 ;
int V_88 = 0 ;
if ( F_45 ( V_158 <= V_134 ) )
return 0 ;
F_75 ( & V_25 -> V_56 ) ;
if ( V_134 == 0 && V_33 == V_97 ) {
V_135 = V_25 -> V_55 ;
goto V_110;
}
V_64 = F_55 ( V_25 , V_134 ) ;
if ( ! V_64 )
goto V_110;
while ( 1 ) {
V_2 = F_48 ( V_64 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 > V_158 )
break;
if ( V_159 && V_88 && V_2 -> V_15 > V_160 + 1 )
break;
if ( V_2 -> V_16 >= V_134 && ( V_2 -> V_2 & V_33 ) == V_33 ) {
V_135 += F_126 ( V_158 , V_2 -> V_16 ) + 1 -
F_127 ( V_134 , V_2 -> V_15 ) ;
if ( V_135 >= V_133 )
break;
if ( ! V_88 ) {
* V_15 = F_127 ( V_134 , V_2 -> V_15 ) ;
V_88 = 1 ;
}
V_160 = V_2 -> V_16 ;
} else if ( V_159 && V_88 ) {
break;
}
V_64 = F_52 ( V_64 ) ;
if ( ! V_64 )
break;
}
V_110:
F_78 ( & V_25 -> V_56 ) ;
return V_135 ;
}
static T_5 int F_128 ( struct V_24 * V_25 , T_1 V_15 ,
struct V_161 * V_58 )
{
struct V_3 * V_64 ;
struct V_1 * V_2 ;
int V_37 = 0 ;
F_75 ( & V_25 -> V_56 ) ;
V_64 = F_55 ( V_25 , V_15 ) ;
if ( ! V_64 ) {
V_37 = - V_162 ;
goto V_110;
}
V_2 = F_48 ( V_64 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 != V_15 ) {
V_37 = - V_162 ;
goto V_110;
}
V_2 -> V_58 = V_58 ;
V_110:
F_78 ( & V_25 -> V_56 ) ;
return V_37 ;
}
static T_5 int F_129 ( struct V_24 * V_25 , T_1 V_15 ,
struct V_161 * * V_58 )
{
struct V_3 * V_64 ;
struct V_1 * V_2 ;
int V_37 = 0 ;
F_75 ( & V_25 -> V_56 ) ;
V_64 = F_55 ( V_25 , V_15 ) ;
if ( ! V_64 ) {
V_37 = - V_162 ;
goto V_110;
}
V_2 = F_48 ( V_64 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 != V_15 ) {
V_37 = - V_162 ;
goto V_110;
}
* V_58 = V_2 -> V_58 ;
V_110:
F_78 ( & V_25 -> V_56 ) ;
return V_37 ;
}
int F_118 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned V_33 , int V_163 , struct V_1 * V_102 )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_64 ;
int V_164 = 0 ;
F_75 ( & V_25 -> V_56 ) ;
if ( V_102 && F_1 ( V_102 ) && V_102 -> V_15 <= V_15 &&
V_102 -> V_16 > V_15 )
V_64 = & V_102 -> V_3 ;
else
V_64 = F_55 ( V_25 , V_15 ) ;
while ( V_64 && V_15 <= V_16 ) {
V_2 = F_48 ( V_64 , struct V_1 , V_3 ) ;
if ( V_163 && V_2 -> V_15 > V_15 ) {
V_164 = 0 ;
break;
}
if ( V_2 -> V_15 > V_16 )
break;
if ( V_2 -> V_2 & V_33 ) {
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
V_64 = F_52 ( V_64 ) ;
if ( ! V_64 ) {
if ( V_163 )
V_164 = 0 ;
break;
}
}
F_78 ( & V_25 -> V_56 ) ;
return V_164 ;
}
static void F_130 ( struct V_24 * V_25 , struct V_128 * V_128 )
{
T_1 V_15 = F_131 ( V_128 ) ;
T_1 V_16 = V_15 + V_30 - 1 ;
if ( F_118 ( V_25 , V_15 , V_16 , V_165 , 1 , NULL ) )
F_132 ( V_128 ) ;
}
int F_133 ( struct V_26 * V_26 , struct V_161 * V_166 )
{
int V_37 ;
int V_99 = 0 ;
struct V_24 * V_167 = & F_19 ( V_26 ) -> V_168 ;
F_128 ( V_167 , V_166 -> V_15 , NULL ) ;
V_37 = F_134 ( V_167 , V_166 -> V_15 ,
V_166 -> V_15 + V_166 -> V_21 - 1 ,
V_124 | V_97 ) ;
if ( V_37 )
V_99 = V_37 ;
V_37 = F_134 ( & F_19 ( V_26 ) -> V_150 , V_166 -> V_15 ,
V_166 -> V_15 + V_166 -> V_21 - 1 ,
V_169 ) ;
if ( V_37 && ! V_99 )
V_99 = V_37 ;
F_135 ( V_166 ) ;
return V_99 ;
}
int F_136 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_170 , T_1 V_171 ,
struct V_128 * V_128 , unsigned int V_172 , int V_173 )
{
struct V_41 * V_32 = F_19 ( V_26 ) -> V_31 -> V_32 ;
struct V_49 * V_49 ;
struct V_174 * V_175 ;
T_1 V_176 = 0 ;
T_1 V_177 ;
struct V_178 * V_179 = NULL ;
struct V_180 * V_181 = & V_32 -> V_182 ;
int V_37 ;
ASSERT ( ! ( V_32 -> V_183 -> V_184 & V_185 ) ) ;
F_23 ( ! V_173 ) ;
if ( F_137 ( V_181 , V_171 , V_170 , V_173 ) )
return 0 ;
V_49 = F_138 ( V_123 , 1 ) ;
if ( ! V_49 )
return - V_152 ;
V_49 -> V_186 . V_187 = 0 ;
V_176 = V_170 ;
F_139 ( V_32 ) ;
V_37 = F_140 ( V_32 , V_188 , V_171 ,
& V_176 , & V_179 , V_173 ) ;
if ( V_37 ) {
F_141 ( V_32 ) ;
F_142 ( V_49 ) ;
return - V_152 ;
}
F_23 ( V_173 != V_179 -> V_173 ) ;
V_177 = V_179 -> V_189 [ V_173 - 1 ] . V_190 >> 9 ;
V_49 -> V_186 . V_191 = V_177 ;
V_175 = V_179 -> V_189 [ V_173 - 1 ] . V_175 ;
F_143 ( V_179 ) ;
if ( ! V_175 || ! V_175 -> V_192 || ! V_175 -> V_193 ) {
F_141 ( V_32 ) ;
F_142 ( V_49 ) ;
return - V_152 ;
}
V_49 -> V_194 = V_175 -> V_192 ;
F_144 ( V_49 , V_195 , V_196 ) ;
F_145 ( V_49 , V_128 , V_170 , V_172 ) ;
if ( F_146 ( V_49 ) ) {
F_141 ( V_32 ) ;
F_142 ( V_49 ) ;
F_147 ( V_175 , V_197 ) ;
return - V_152 ;
}
F_148 ( V_32 ,
L_13 ,
F_20 ( V_26 ) , V_15 ,
F_149 ( V_175 -> V_198 ) , V_177 ) ;
F_141 ( V_32 ) ;
F_142 ( V_49 ) ;
return 0 ;
}
int F_150 ( struct V_199 * V_31 , struct V_10 * V_11 ,
int V_173 )
{
T_1 V_15 = V_11 -> V_15 ;
unsigned long V_139 , V_200 = F_151 ( V_11 -> V_15 , V_11 -> V_21 ) ;
int V_37 = 0 ;
if ( V_31 -> V_32 -> V_183 -> V_184 & V_185 )
return - V_201 ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
struct V_128 * V_67 = V_11 -> V_137 [ V_139 ] ;
V_37 = F_136 ( V_31 -> V_32 -> V_202 , V_15 ,
V_30 , V_15 , V_67 ,
V_15 - F_131 ( V_67 ) , V_173 ) ;
if ( V_37 )
break;
V_15 += V_30 ;
}
return V_37 ;
}
int F_152 ( struct V_26 * V_26 , T_1 V_15 , struct V_128 * V_128 ,
unsigned int V_172 )
{
T_1 V_203 ;
struct V_161 * V_58 ;
struct V_41 * V_32 = F_19 ( V_26 ) -> V_31 -> V_32 ;
struct V_1 * V_2 ;
int V_204 ;
int V_37 ;
V_203 = 0 ;
V_37 = F_125 ( & F_19 ( V_26 ) -> V_168 , & V_203 ,
( T_1 ) - 1 , 1 , V_97 , 0 ) ;
if ( ! V_37 )
return 0 ;
V_37 = F_129 ( & F_19 ( V_26 ) -> V_168 , V_15 ,
& V_58 ) ;
if ( V_37 )
return 0 ;
F_23 ( ! V_58 -> V_205 ) ;
if ( V_58 -> V_206 ) {
F_153 ( L_14 ,
V_58 -> V_15 ) ;
goto V_110;
}
if ( V_32 -> V_183 -> V_184 & V_185 )
goto V_110;
F_75 ( & F_19 ( V_26 ) -> V_150 . V_56 ) ;
V_2 = F_107 ( & F_19 ( V_26 ) -> V_150 ,
V_58 -> V_15 ,
V_124 ) ;
F_78 ( & F_19 ( V_26 ) -> V_150 . V_56 ) ;
if ( V_2 && V_2 -> V_15 <= V_58 -> V_15 &&
V_2 -> V_16 >= V_58 -> V_15 + V_58 -> V_21 - 1 ) {
V_204 = F_154 ( V_32 , V_58 -> V_171 ,
V_58 -> V_21 ) ;
if ( V_204 > 1 ) {
F_136 ( V_26 , V_15 , V_58 -> V_21 ,
V_58 -> V_171 , V_128 ,
V_172 , V_58 -> V_207 ) ;
}
}
V_110:
F_133 ( V_26 , V_58 ) ;
return 0 ;
}
void F_155 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_16 )
{
struct V_24 * V_167 = & F_19 ( V_26 ) -> V_168 ;
struct V_161 * V_58 ;
struct V_1 * V_2 , * V_13 ;
if ( F_156 ( & V_167 -> V_2 ) )
return;
F_75 ( & V_167 -> V_56 ) ;
V_2 = F_107 ( V_167 , V_15 , V_97 ) ;
while ( V_2 ) {
if ( V_2 -> V_15 > V_16 )
break;
ASSERT ( V_2 -> V_16 <= V_16 ) ;
V_13 = F_66 ( V_2 ) ;
V_58 = V_2 -> V_58 ;
F_43 ( V_2 ) ;
F_135 ( V_58 ) ;
V_2 = V_13 ;
}
F_78 ( & V_167 -> V_56 ) ;
}
int F_157 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_16 ,
struct V_161 * * V_208 )
{
struct V_161 * V_58 ;
struct V_209 * V_210 ;
struct V_24 * V_167 = & F_19 ( V_26 ) -> V_168 ;
struct V_24 * V_25 = & F_19 ( V_26 ) -> V_150 ;
struct V_211 * V_212 = & F_19 ( V_26 ) -> V_213 ;
int V_37 ;
T_1 V_171 ;
V_37 = F_129 ( V_167 , V_15 , & V_58 ) ;
if ( V_37 ) {
V_58 = F_158 ( sizeof( * V_58 ) , V_123 ) ;
if ( ! V_58 )
return - V_44 ;
V_58 -> V_15 = V_15 ;
V_58 -> V_21 = V_16 - V_15 + 1 ;
V_58 -> V_205 = 0 ;
V_58 -> V_214 = 0 ;
V_58 -> V_206 = 0 ;
F_159 ( & V_212 -> V_56 ) ;
V_210 = F_160 ( V_212 , V_15 , V_58 -> V_21 ) ;
if ( ! V_210 ) {
F_161 ( & V_212 -> V_56 ) ;
F_135 ( V_58 ) ;
return - V_152 ;
}
if ( V_210 -> V_15 > V_15 || V_210 -> V_15 + V_210 -> V_21 <= V_15 ) {
F_162 ( V_210 ) ;
V_210 = NULL ;
}
F_161 ( & V_212 -> V_56 ) ;
if ( ! V_210 ) {
F_135 ( V_58 ) ;
return - V_152 ;
}
V_171 = V_15 - V_210 -> V_15 ;
V_171 = V_210 -> V_215 + V_171 ;
if ( F_163 ( V_216 , & V_210 -> V_7 ) ) {
V_171 = V_210 -> V_215 ;
V_58 -> V_214 = V_217 ;
F_164 ( & V_58 -> V_214 ,
V_210 -> V_218 ) ;
}
F_153 ( L_15 ,
V_171 , V_15 , V_58 -> V_21 ) ;
V_58 -> V_171 = V_171 ;
F_162 ( V_210 ) ;
V_37 = F_165 ( V_167 , V_15 , V_16 ,
V_124 | V_97 ) ;
if ( V_37 >= 0 )
V_37 = F_128 ( V_167 , V_15 , V_58 ) ;
if ( V_37 >= 0 )
V_37 = F_165 ( V_25 , V_15 , V_16 , V_169 ) ;
if ( V_37 < 0 ) {
F_135 ( V_58 ) ;
return V_37 ;
}
} else {
F_153 ( L_16 ,
V_58 -> V_171 , V_58 -> V_15 , V_58 -> V_21 ,
V_58 -> V_206 ) ;
}
* V_208 = V_58 ;
return 0 ;
}
int F_166 ( struct V_26 * V_26 , struct V_49 * V_219 ,
struct V_161 * V_58 , int V_207 )
{
int V_204 ;
V_204 = F_154 ( F_19 ( V_26 ) -> V_31 -> V_32 ,
V_58 -> V_171 , V_58 -> V_21 ) ;
if ( V_204 == 1 ) {
F_153 ( L_17 ,
V_204 , V_58 -> V_205 , V_207 ) ;
return 0 ;
}
if ( V_219 -> V_220 > 1 ) {
F_23 ( V_58 -> V_206 ) ;
V_58 -> V_206 = 1 ;
V_58 -> V_205 = V_207 ;
} else {
if ( V_58 -> V_206 ) {
F_23 ( V_58 -> V_205 != V_207 ) ;
V_58 -> V_206 = 0 ;
V_58 -> V_205 = 0 ;
}
V_58 -> V_207 = V_207 ;
V_58 -> V_205 ++ ;
if ( V_58 -> V_205 == V_207 )
V_58 -> V_205 ++ ;
}
if ( V_58 -> V_205 > V_204 ) {
F_153 ( L_18 ,
V_204 , V_58 -> V_205 , V_207 ) ;
return 0 ;
}
return 1 ;
}
struct V_49 * F_167 ( struct V_26 * V_26 , struct V_49 * V_219 ,
struct V_161 * V_58 ,
struct V_128 * V_128 , int V_172 , int V_221 ,
T_6 * V_222 , void * V_223 )
{
struct V_49 * V_49 ;
struct V_48 * V_224 ;
struct V_48 * V_178 ;
V_49 = F_138 ( V_123 , 1 ) ;
if ( ! V_49 )
return NULL ;
V_49 -> V_225 = V_222 ;
V_49 -> V_186 . V_191 = V_58 -> V_171 >> 9 ;
V_49 -> V_194 = F_19 ( V_26 ) -> V_31 -> V_32 -> V_226 -> V_227 ;
V_49 -> V_186 . V_187 = 0 ;
V_49 -> V_228 = V_223 ;
V_224 = V_48 ( V_219 ) ;
if ( V_224 -> V_229 ) {
struct V_41 * V_32 = F_19 ( V_26 ) -> V_31 -> V_32 ;
T_7 V_230 = F_168 ( V_32 -> V_231 ) ;
V_178 = V_48 ( V_49 ) ;
V_178 -> V_229 = V_178 -> V_232 ;
V_221 *= V_230 ;
memcpy ( V_178 -> V_229 , V_224 -> V_229 + V_221 ,
V_230 ) ;
}
F_145 ( V_49 , V_128 , V_58 -> V_21 , V_172 ) ;
return V_49 ;
}
static int F_169 ( struct V_49 * V_219 , T_1 V_233 ,
struct V_128 * V_128 , T_1 V_15 , T_1 V_16 ,
int V_207 )
{
struct V_161 * V_58 ;
struct V_26 * V_26 = V_128 -> V_28 -> V_29 ;
struct V_24 * V_25 = & F_19 ( V_26 ) -> V_150 ;
struct V_49 * V_49 ;
int V_234 ;
int V_37 ;
F_23 ( F_170 ( V_219 ) == V_195 ) ;
V_37 = F_157 ( V_26 , V_15 , V_16 , & V_58 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_166 ( V_26 , V_219 , V_58 , V_207 ) ;
if ( ! V_37 ) {
F_133 ( V_26 , V_58 ) ;
return - V_152 ;
}
if ( V_219 -> V_220 > 1 )
V_234 = V_235 | V_236 ;
else
V_234 = V_235 ;
V_233 >>= V_26 -> V_42 -> V_237 ;
V_49 = F_167 ( V_26 , V_219 , V_58 , V_128 ,
V_15 - F_131 ( V_128 ) ,
( int ) V_233 , V_219 -> V_225 ,
NULL ) ;
if ( ! V_49 ) {
F_133 ( V_26 , V_58 ) ;
return - V_152 ;
}
F_144 ( V_49 , V_238 , V_234 ) ;
F_153 ( L_19 ,
V_234 , V_58 -> V_205 , V_58 -> V_206 ) ;
V_37 = V_25 -> V_54 -> V_239 ( V_26 , V_49 , V_58 -> V_205 ,
V_58 -> V_214 , 0 ) ;
if ( V_37 ) {
F_133 ( V_26 , V_58 ) ;
F_142 ( V_49 ) ;
}
return V_37 ;
}
void F_171 ( struct V_128 * V_128 , int V_99 , T_1 V_15 , T_1 V_16 )
{
int V_240 = ( V_99 == 0 ) ;
struct V_24 * V_25 ;
int V_37 = 0 ;
V_25 = & F_19 ( V_128 -> V_28 -> V_29 ) -> V_150 ;
if ( V_25 -> V_54 && V_25 -> V_54 -> V_241 ) {
V_37 = V_25 -> V_54 -> V_241 ( V_128 , V_15 ,
V_16 , NULL , V_240 ) ;
if ( V_37 )
V_240 = 0 ;
}
if ( ! V_240 ) {
F_172 ( V_128 ) ;
F_123 ( V_128 ) ;
V_37 = V_37 < 0 ? V_37 : - V_152 ;
F_121 ( V_128 -> V_28 , V_37 ) ;
}
}
static void F_173 ( struct V_49 * V_49 )
{
struct V_242 * V_243 ;
T_1 V_15 ;
T_1 V_16 ;
int V_139 ;
F_174 (bvec, bio, i) {
struct V_128 * V_128 = V_243 -> V_244 ;
if ( V_243 -> V_245 || V_243 -> V_246 != V_30 ) {
if ( V_243 -> V_245 + V_243 -> V_246 != V_30 )
F_175 ( F_19 ( V_128 -> V_28 -> V_29 ) -> V_31 -> V_32 ,
L_20 ,
V_243 -> V_245 , V_243 -> V_246 ) ;
else
F_176 ( F_19 ( V_128 -> V_28 -> V_29 ) -> V_31 -> V_32 ,
L_21
L_22 ,
V_243 -> V_245 , V_243 -> V_246 ) ;
}
V_15 = F_131 ( V_128 ) ;
V_16 = V_15 + V_243 -> V_245 + V_243 -> V_246 - 1 ;
F_171 ( V_128 , V_49 -> V_247 , V_15 , V_16 ) ;
F_124 ( V_128 ) ;
}
F_142 ( V_49 ) ;
}
static void
F_177 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_21 ,
int V_240 )
{
struct V_1 * V_102 = NULL ;
T_1 V_16 = V_15 + V_21 - 1 ;
if ( V_240 && V_25 -> V_248 )
F_178 ( V_25 , V_15 , V_16 , & V_102 , V_40 ) ;
F_119 ( V_25 , V_15 , V_16 , & V_102 , V_40 ) ;
}
static void F_179 ( struct V_49 * V_49 )
{
struct V_242 * V_243 ;
int V_240 = ! V_49 -> V_247 ;
struct V_48 * V_249 = V_48 ( V_49 ) ;
struct V_24 * V_25 ;
T_1 V_63 = 0 ;
T_1 V_15 ;
T_1 V_16 ;
T_1 V_21 ;
T_1 V_250 = 0 ;
T_1 V_251 = 0 ;
int V_252 ;
int V_37 ;
int V_139 ;
F_174 (bvec, bio, i) {
struct V_128 * V_128 = V_243 -> V_244 ;
struct V_26 * V_26 = V_128 -> V_28 -> V_29 ;
F_153 ( L_23
L_24 , ( T_1 ) V_49 -> V_186 . V_191 ,
V_49 -> V_247 , V_249 -> V_173 ) ;
V_25 = & F_19 ( V_26 ) -> V_150 ;
if ( V_243 -> V_245 || V_243 -> V_246 != V_30 ) {
if ( V_243 -> V_245 + V_243 -> V_246 != V_30 )
F_175 ( F_19 ( V_128 -> V_28 -> V_29 ) -> V_31 -> V_32 ,
L_25 ,
V_243 -> V_245 , V_243 -> V_246 ) ;
else
F_176 ( F_19 ( V_128 -> V_28 -> V_29 ) -> V_31 -> V_32 ,
L_26
L_22 ,
V_243 -> V_245 , V_243 -> V_246 ) ;
}
V_15 = F_131 ( V_128 ) ;
V_16 = V_15 + V_243 -> V_245 + V_243 -> V_246 - 1 ;
V_21 = V_243 -> V_246 ;
V_252 = V_249 -> V_173 ;
if ( F_180 ( V_240 && V_25 -> V_54 &&
V_25 -> V_54 -> V_253 ) ) {
V_37 = V_25 -> V_54 -> V_253 ( V_249 , V_63 ,
V_128 , V_15 , V_16 ,
V_252 ) ;
if ( V_37 )
V_240 = 0 ;
else
F_152 ( V_26 , V_15 , V_128 , 0 ) ;
}
if ( F_180 ( V_240 ) )
goto V_254;
if ( V_25 -> V_54 && V_25 -> V_54 -> V_255 ) {
V_37 = V_25 -> V_54 -> V_255 ( V_128 , V_252 ) ;
if ( ! V_37 && ! V_49 -> V_247 )
V_240 = 1 ;
} else {
V_37 = F_169 ( V_49 , V_63 , V_128 , V_15 , V_16 ,
V_252 ) ;
if ( V_37 == 0 ) {
V_240 = ! V_49 -> V_247 ;
V_63 += V_21 ;
continue;
}
}
V_254:
if ( F_180 ( V_240 ) ) {
T_8 V_256 = F_17 ( V_26 ) ;
T_9 V_127 = V_256 >> V_126 ;
unsigned V_257 ;
V_257 = V_256 & ( V_30 - 1 ) ;
if ( V_128 -> V_125 == V_127 && V_257 )
F_181 ( V_128 , V_257 , V_30 ) ;
F_132 ( V_128 ) ;
} else {
F_172 ( V_128 ) ;
F_123 ( V_128 ) ;
}
F_113 ( V_128 ) ;
V_63 += V_21 ;
if ( F_182 ( ! V_240 ) ) {
if ( V_251 ) {
F_177 ( V_25 ,
V_250 ,
V_251 , 1 ) ;
V_250 = 0 ;
V_251 = 0 ;
}
F_177 ( V_25 , V_15 ,
V_16 - V_15 + 1 , 0 ) ;
} else if ( ! V_251 ) {
V_250 = V_15 ;
V_251 = V_16 + 1 - V_15 ;
} else if ( V_250 + V_251 == V_15 ) {
V_251 += V_16 + 1 - V_15 ;
} else {
F_177 ( V_25 , V_250 ,
V_251 , V_240 ) ;
V_250 = V_15 ;
V_251 = V_16 + 1 - V_15 ;
}
}
if ( V_251 )
F_177 ( V_25 , V_250 , V_251 ,
V_240 ) ;
if ( V_249 -> V_258 )
V_249 -> V_258 ( V_249 , V_49 -> V_247 ) ;
F_142 ( V_49 ) ;
}
struct V_49 *
F_183 ( struct V_259 * V_192 , T_1 V_260 , int V_261 ,
T_3 V_262 )
{
struct V_48 * V_178 ;
struct V_49 * V_49 ;
V_49 = F_184 ( V_262 , V_261 , V_46 ) ;
if ( V_49 == NULL && ( V_263 -> V_7 & V_264 ) ) {
while ( ! V_49 && ( V_261 /= 2 ) ) {
V_49 = F_184 ( V_262 ,
V_261 , V_46 ) ;
}
}
if ( V_49 ) {
V_49 -> V_194 = V_192 ;
V_49 -> V_186 . V_191 = V_260 ;
V_178 = V_48 ( V_49 ) ;
V_178 -> V_229 = NULL ;
V_178 -> V_265 = NULL ;
V_178 -> V_258 = NULL ;
}
return V_49 ;
}
struct V_49 * F_185 ( struct V_49 * V_49 , T_3 V_266 )
{
struct V_48 * V_178 ;
struct V_49 * V_5 ;
V_5 = F_186 ( V_49 , V_266 , V_46 ) ;
if ( V_5 ) {
V_178 = V_48 ( V_5 ) ;
V_178 -> V_229 = NULL ;
V_178 -> V_265 = NULL ;
V_178 -> V_258 = NULL ;
}
return V_5 ;
}
struct V_49 * F_138 ( T_3 V_266 , unsigned int V_267 )
{
struct V_48 * V_178 ;
struct V_49 * V_49 ;
V_49 = F_184 ( V_266 , V_267 , V_46 ) ;
if ( V_49 ) {
V_178 = V_48 ( V_49 ) ;
V_178 -> V_229 = NULL ;
V_178 -> V_265 = NULL ;
V_178 -> V_258 = NULL ;
}
return V_49 ;
}
static int T_4 F_187 ( struct V_49 * V_49 , int V_173 ,
unsigned long V_214 )
{
int V_37 = 0 ;
struct V_242 * V_243 = V_49 -> V_268 + V_49 -> V_220 - 1 ;
struct V_128 * V_128 = V_243 -> V_244 ;
struct V_24 * V_25 = V_49 -> V_228 ;
T_1 V_15 ;
V_15 = F_131 ( V_128 ) + V_243 -> V_245 ;
V_49 -> V_228 = NULL ;
F_188 ( V_49 ) ;
if ( V_25 -> V_54 && V_25 -> V_54 -> V_239 )
V_37 = V_25 -> V_54 -> V_239 ( V_128 -> V_28 -> V_29 , V_49 ,
V_173 , V_214 , V_15 ) ;
else
F_189 ( V_49 ) ;
F_142 ( V_49 ) ;
return V_37 ;
}
static int F_190 ( struct V_24 * V_25 , struct V_128 * V_128 ,
unsigned long V_63 , T_10 V_269 , struct V_49 * V_49 ,
unsigned long V_214 )
{
int V_37 = 0 ;
if ( V_25 -> V_54 && V_25 -> V_54 -> V_270 )
V_37 = V_25 -> V_54 -> V_270 ( V_128 , V_63 , V_269 , V_49 ,
V_214 ) ;
return V_37 ;
}
static int F_191 ( int V_271 , int V_272 , struct V_24 * V_25 ,
struct V_273 * V_274 ,
struct V_128 * V_128 , T_11 V_177 ,
T_10 V_269 , unsigned long V_63 ,
struct V_259 * V_192 ,
struct V_49 * * V_275 ,
unsigned long V_276 ,
T_6 V_277 ,
int V_173 ,
unsigned long V_278 ,
unsigned long V_214 ,
bool V_279 )
{
int V_37 = 0 ;
struct V_49 * V_49 ;
int V_159 = 0 ;
int V_280 = V_278 & V_217 ;
T_10 V_281 = F_112 ( T_10 , V_269 , V_30 ) ;
if ( V_275 && * V_275 ) {
V_49 = * V_275 ;
if ( V_280 )
V_159 = V_49 -> V_186 . V_191 == V_177 ;
else
V_159 = F_192 ( V_49 ) == V_177 ;
if ( V_278 != V_214 || ! V_159 ||
V_279 ||
F_190 ( V_25 , V_128 , V_63 , V_281 , V_49 , V_214 ) ||
F_145 ( V_49 , V_128 , V_281 , V_63 ) < V_281 ) {
V_37 = F_187 ( V_49 , V_173 , V_278 ) ;
if ( V_37 < 0 ) {
* V_275 = NULL ;
return V_37 ;
}
V_49 = NULL ;
} else {
if ( V_274 )
F_193 ( V_274 , V_128 , V_281 ) ;
return 0 ;
}
}
V_49 = F_183 ( V_192 , V_177 , V_282 ,
V_123 | V_283 ) ;
if ( ! V_49 )
return - V_44 ;
F_145 ( V_49 , V_128 , V_281 , V_63 ) ;
V_49 -> V_225 = V_277 ;
V_49 -> V_228 = V_25 ;
F_144 ( V_49 , V_271 , V_272 ) ;
if ( V_274 ) {
F_194 ( V_274 , V_49 ) ;
F_193 ( V_274 , V_128 , V_281 ) ;
}
if ( V_275 )
* V_275 = V_49 ;
else
V_37 = F_187 ( V_49 , V_173 , V_214 ) ;
return V_37 ;
}
static void F_195 ( struct V_10 * V_11 ,
struct V_128 * V_128 )
{
if ( ! F_196 ( V_128 ) ) {
F_197 ( V_128 ) ;
F_198 ( V_128 ) ;
F_199 ( V_128 , ( unsigned long ) V_11 ) ;
} else {
F_45 ( V_128 -> V_203 != ( unsigned long ) V_11 ) ;
}
}
void F_200 ( struct V_128 * V_128 )
{
if ( ! F_196 ( V_128 ) ) {
F_197 ( V_128 ) ;
F_198 ( V_128 ) ;
F_199 ( V_128 , V_284 ) ;
}
}
static struct V_209 *
F_201 ( struct V_26 * V_26 , struct V_128 * V_128 , T_10 V_172 ,
T_1 V_15 , T_1 V_21 , T_12 * V_285 ,
struct V_209 * * V_286 )
{
struct V_209 * V_210 ;
if ( V_286 && * V_286 ) {
V_210 = * V_286 ;
if ( F_202 ( V_210 ) && V_15 >= V_210 -> V_15 &&
V_15 < F_203 ( V_210 ) ) {
F_86 ( & V_210 -> V_17 ) ;
return V_210 ;
}
F_162 ( V_210 ) ;
* V_286 = NULL ;
}
V_210 = V_285 ( V_26 , V_128 , V_172 , V_15 , V_21 , 0 ) ;
if ( V_286 && ! F_204 ( V_210 ) ) {
F_23 ( * V_286 ) ;
F_86 ( & V_210 -> V_17 ) ;
* V_286 = V_210 ;
}
return V_210 ;
}
static int F_205 ( struct V_24 * V_25 ,
struct V_128 * V_128 ,
T_12 * V_285 ,
struct V_209 * * V_286 ,
struct V_49 * * V_49 , int V_173 ,
unsigned long * V_214 , int V_287 ,
T_1 * V_288 )
{
struct V_26 * V_26 = V_128 -> V_28 -> V_29 ;
T_1 V_15 = F_131 ( V_128 ) ;
T_1 V_289 = V_15 + V_30 - 1 ;
T_1 V_16 ;
T_1 V_290 = V_15 ;
T_1 V_291 ;
T_1 V_292 = F_17 ( V_26 ) ;
T_1 V_215 ;
T_1 V_293 ;
T_11 V_177 ;
struct V_209 * V_210 ;
struct V_259 * V_192 ;
int V_37 = 0 ;
int V_294 = 0 ;
T_10 V_172 = 0 ;
T_10 V_295 ;
T_10 V_296 ;
T_10 V_297 = V_26 -> V_42 -> V_298 ;
unsigned long V_299 = 0 ;
F_200 ( V_128 ) ;
V_16 = V_289 ;
if ( ! F_206 ( V_128 ) ) {
if ( F_207 ( V_128 ) == 0 ) {
F_23 ( V_297 != V_30 ) ;
F_208 ( V_25 , V_15 , V_16 ) ;
goto V_110;
}
}
if ( V_128 -> V_125 == V_292 >> V_126 ) {
char * V_300 ;
T_10 V_301 = V_292 & ( V_30 - 1 ) ;
if ( V_301 ) {
V_295 = V_30 - V_301 ;
V_300 = F_209 ( V_128 ) ;
memset ( V_300 + V_301 , 0 , V_295 ) ;
F_210 ( V_128 ) ;
F_211 ( V_300 ) ;
}
}
while ( V_290 <= V_16 ) {
unsigned long V_302 = ( V_292 >> V_126 ) + 1 ;
bool V_279 = false ;
if ( V_290 >= V_292 ) {
char * V_300 ;
struct V_1 * V_102 = NULL ;
V_295 = V_30 - V_172 ;
V_300 = F_209 ( V_128 ) ;
memset ( V_300 + V_172 , 0 , V_295 ) ;
F_210 ( V_128 ) ;
F_211 ( V_300 ) ;
F_178 ( V_25 , V_290 , V_290 + V_295 - 1 ,
& V_102 , V_123 ) ;
F_119 ( V_25 , V_290 ,
V_290 + V_295 - 1 ,
& V_102 , V_123 ) ;
break;
}
V_210 = F_201 ( V_26 , V_128 , V_172 , V_290 ,
V_16 - V_290 + 1 , V_285 , V_286 ) ;
if ( F_204 ( V_210 ) ) {
F_123 ( V_128 ) ;
F_208 ( V_25 , V_290 , V_16 ) ;
break;
}
V_291 = V_290 - V_210 -> V_15 ;
F_23 ( F_203 ( V_210 ) <= V_290 ) ;
F_23 ( V_16 < V_290 ) ;
if ( F_163 ( V_216 , & V_210 -> V_7 ) ) {
V_299 |= V_217 ;
F_164 ( & V_299 ,
V_210 -> V_218 ) ;
}
V_295 = F_126 ( F_203 ( V_210 ) - V_290 , V_16 - V_290 + 1 ) ;
V_293 = F_126 ( F_203 ( V_210 ) - 1 , V_16 ) ;
V_295 = F_212 ( V_295 , V_297 ) ;
if ( V_299 & V_217 ) {
V_296 = V_210 -> V_303 ;
V_177 = V_210 -> V_215 >> 9 ;
} else {
V_177 = ( V_210 -> V_215 + V_291 ) >> 9 ;
V_296 = V_295 ;
}
V_192 = V_210 -> V_192 ;
V_215 = V_210 -> V_215 ;
if ( F_163 ( V_304 , & V_210 -> V_7 ) )
V_215 = V_305 ;
if ( F_163 ( V_216 , & V_210 -> V_7 ) &&
V_288 && * V_288 != ( T_1 ) - 1 &&
* V_288 != V_210 -> V_306 )
V_279 = true ;
if ( V_288 )
* V_288 = V_210 -> V_306 ;
F_162 ( V_210 ) ;
V_210 = NULL ;
if ( V_215 == V_305 ) {
char * V_300 ;
struct V_1 * V_102 = NULL ;
V_300 = F_209 ( V_128 ) ;
memset ( V_300 + V_172 , 0 , V_295 ) ;
F_210 ( V_128 ) ;
F_211 ( V_300 ) ;
F_178 ( V_25 , V_290 , V_290 + V_295 - 1 ,
& V_102 , V_123 ) ;
F_119 ( V_25 , V_290 ,
V_290 + V_295 - 1 ,
& V_102 , V_123 ) ;
V_290 = V_290 + V_295 ;
V_172 += V_295 ;
continue;
}
if ( F_118 ( V_25 , V_290 , V_293 ,
V_165 , 1 , NULL ) ) {
F_130 ( V_25 , V_128 ) ;
F_208 ( V_25 , V_290 , V_290 + V_295 - 1 ) ;
V_290 = V_290 + V_295 ;
V_172 += V_295 ;
continue;
}
if ( V_215 == V_307 ) {
F_123 ( V_128 ) ;
F_208 ( V_25 , V_290 , V_290 + V_295 - 1 ) ;
V_290 = V_290 + V_295 ;
V_172 += V_295 ;
continue;
}
V_302 -= V_128 -> V_125 ;
V_37 = F_191 ( V_238 , V_287 , V_25 , NULL ,
V_128 , V_177 , V_296 , V_172 ,
V_192 , V_49 , V_302 ,
F_179 , V_173 ,
* V_214 ,
V_299 ,
V_279 ) ;
if ( ! V_37 ) {
V_294 ++ ;
* V_214 = V_299 ;
} else {
F_123 ( V_128 ) ;
F_208 ( V_25 , V_290 , V_290 + V_295 - 1 ) ;
goto V_110;
}
V_290 = V_290 + V_295 ;
V_172 += V_295 ;
}
V_110:
if ( ! V_294 ) {
if ( ! F_213 ( V_128 ) )
F_132 ( V_128 ) ;
F_113 ( V_128 ) ;
}
return V_37 ;
}
static inline void F_214 ( struct V_24 * V_25 ,
struct V_128 * V_137 [] , int V_138 ,
T_1 V_15 , T_1 V_16 ,
T_12 * V_285 ,
struct V_209 * * V_286 ,
struct V_49 * * V_49 , int V_173 ,
unsigned long * V_214 ,
T_1 * V_288 )
{
struct V_26 * V_26 ;
struct V_308 * V_309 ;
int V_125 ;
V_26 = V_137 [ 0 ] -> V_28 -> V_29 ;
while ( 1 ) {
F_215 ( V_25 , V_15 , V_16 ) ;
V_309 = F_216 ( V_26 , V_15 ,
V_16 - V_15 + 1 ) ;
if ( ! V_309 )
break;
F_208 ( V_25 , V_15 , V_16 ) ;
F_217 ( V_26 , V_309 , 1 ) ;
F_218 ( V_309 ) ;
}
for ( V_125 = 0 ; V_125 < V_138 ; V_125 ++ ) {
F_205 ( V_25 , V_137 [ V_125 ] , V_285 , V_286 , V_49 ,
V_173 , V_214 , 0 , V_288 ) ;
F_101 ( V_137 [ V_125 ] ) ;
}
}
static void F_219 ( struct V_24 * V_25 ,
struct V_128 * V_137 [] ,
int V_138 , T_12 * V_285 ,
struct V_209 * * V_286 ,
struct V_49 * * V_49 , int V_173 ,
unsigned long * V_214 ,
T_1 * V_288 )
{
T_1 V_15 = 0 ;
T_1 V_16 = 0 ;
T_1 V_310 ;
int V_125 ;
int V_311 = 0 ;
for ( V_125 = 0 ; V_125 < V_138 ; V_125 ++ ) {
V_310 = F_131 ( V_137 [ V_125 ] ) ;
if ( ! V_16 ) {
V_15 = V_310 ;
V_16 = V_15 + V_30 - 1 ;
V_311 = V_125 ;
} else if ( V_16 + 1 == V_310 ) {
V_16 += V_30 ;
} else {
F_214 ( V_25 , & V_137 [ V_311 ] ,
V_125 - V_311 , V_15 ,
V_16 , V_285 , V_286 ,
V_49 , V_173 , V_214 ,
V_288 ) ;
V_15 = V_310 ;
V_16 = V_15 + V_30 - 1 ;
V_311 = V_125 ;
}
}
if ( V_16 )
F_214 ( V_25 , & V_137 [ V_311 ] ,
V_125 - V_311 , V_15 ,
V_16 , V_285 , V_286 , V_49 ,
V_173 , V_214 ,
V_288 ) ;
}
static int F_220 ( struct V_24 * V_25 ,
struct V_128 * V_128 ,
T_12 * V_285 ,
struct V_49 * * V_49 , int V_173 ,
unsigned long * V_214 , int V_287 )
{
struct V_26 * V_26 = V_128 -> V_28 -> V_29 ;
struct V_308 * V_309 ;
T_1 V_15 = F_131 ( V_128 ) ;
T_1 V_16 = V_15 + V_30 - 1 ;
int V_37 ;
while ( 1 ) {
F_215 ( V_25 , V_15 , V_16 ) ;
V_309 = F_216 ( V_26 , V_15 ,
V_30 ) ;
if ( ! V_309 )
break;
F_208 ( V_25 , V_15 , V_16 ) ;
F_217 ( V_26 , V_309 , 1 ) ;
F_218 ( V_309 ) ;
}
V_37 = F_205 ( V_25 , V_128 , V_285 , NULL , V_49 , V_173 ,
V_214 , V_287 , NULL ) ;
return V_37 ;
}
int F_221 ( struct V_24 * V_25 , struct V_128 * V_128 ,
T_12 * V_285 , int V_173 )
{
struct V_49 * V_49 = NULL ;
unsigned long V_214 = 0 ;
int V_37 ;
V_37 = F_220 ( V_25 , V_128 , V_285 , & V_49 , V_173 ,
& V_214 , 0 ) ;
if ( V_49 )
V_37 = F_187 ( V_49 , V_173 , V_214 ) ;
return V_37 ;
}
static void F_222 ( struct V_128 * V_128 , struct V_273 * V_274 ,
unsigned long V_312 )
{
V_274 -> V_313 -= V_312 ;
}
static T_13 int F_223 ( struct V_26 * V_26 ,
struct V_128 * V_128 , struct V_273 * V_274 ,
struct V_314 * V_315 ,
T_1 V_140 ,
unsigned long * V_312 )
{
struct V_24 * V_25 = V_315 -> V_25 ;
T_1 V_289 = V_140 + V_30 - 1 ;
T_1 V_316 ;
T_1 V_317 = 0 ;
T_1 V_141 = 0 ;
int V_37 ;
int V_318 = 0 ;
if ( V_315 -> V_319 || ! V_25 -> V_54 || ! V_25 -> V_54 -> V_320 )
return 0 ;
while ( V_141 < V_289 ) {
V_316 = F_117 ( V_26 , V_25 ,
V_128 ,
& V_140 ,
& V_141 ,
V_321 ) ;
if ( V_316 == 0 ) {
V_140 = V_141 + 1 ;
continue;
}
V_37 = V_25 -> V_54 -> V_320 ( V_26 , V_128 ,
V_140 ,
V_141 ,
& V_318 ,
V_312 ) ;
if ( V_37 ) {
F_123 ( V_128 ) ;
V_37 = V_37 < 0 ? V_37 : - V_152 ;
goto V_146;
}
V_317 += ( V_141 - V_140 +
V_30 ) >> V_126 ;
V_140 = V_141 + 1 ;
}
if ( V_274 -> V_313 < V_317 ) {
int V_322 = 8192 ;
if ( V_317 < V_322 * 2 )
V_322 = V_317 ;
V_274 -> V_313 = F_112 ( T_1 , V_317 ,
V_322 ) ;
}
if ( V_318 ) {
V_274 -> V_313 -= * V_312 ;
return 1 ;
}
V_37 = 0 ;
V_146:
return V_37 ;
}
static T_13 int F_224 ( struct V_26 * V_26 ,
struct V_128 * V_128 ,
struct V_273 * V_274 ,
struct V_314 * V_315 ,
T_8 V_256 ,
unsigned long V_312 ,
int V_323 , int * V_324 )
{
struct V_24 * V_25 = V_315 -> V_25 ;
T_1 V_15 = F_131 ( V_128 ) ;
T_1 V_289 = V_15 + V_30 - 1 ;
T_1 V_16 ;
T_1 V_290 = V_15 ;
T_1 V_291 ;
T_1 V_215 ;
T_1 V_295 ;
T_11 V_177 ;
struct V_1 * V_101 = NULL ;
struct V_209 * V_210 ;
struct V_259 * V_192 ;
T_10 V_172 = 0 ;
T_10 V_297 ;
int V_37 = 0 ;
int V_294 = 0 ;
bool V_325 ;
if ( V_25 -> V_54 && V_25 -> V_54 -> V_326 ) {
V_37 = V_25 -> V_54 -> V_326 ( V_128 , V_15 ,
V_289 ) ;
if ( V_37 ) {
if ( V_37 == - V_327 )
V_274 -> V_328 ++ ;
else
F_225 ( V_274 , V_128 ) ;
F_222 ( V_128 , V_274 , V_312 ) ;
F_113 ( V_128 ) ;
V_37 = 1 ;
goto V_329;
}
}
F_222 ( V_128 , V_274 , V_312 + 1 ) ;
V_16 = V_289 ;
if ( V_256 <= V_15 ) {
if ( V_25 -> V_54 && V_25 -> V_54 -> V_241 )
V_25 -> V_54 -> V_241 ( V_128 , V_15 ,
V_289 , NULL , 1 ) ;
goto V_146;
}
V_297 = V_26 -> V_42 -> V_298 ;
while ( V_290 <= V_16 ) {
T_1 V_330 ;
unsigned long V_331 ;
if ( V_290 >= V_256 ) {
if ( V_25 -> V_54 && V_25 -> V_54 -> V_241 )
V_25 -> V_54 -> V_241 ( V_128 , V_290 ,
V_289 , NULL , 1 ) ;
break;
}
V_210 = V_315 -> V_285 ( V_26 , V_128 , V_172 , V_290 ,
V_16 - V_290 + 1 , 1 ) ;
if ( F_204 ( V_210 ) ) {
F_123 ( V_128 ) ;
V_37 = F_226 ( V_210 ) ;
break;
}
V_291 = V_290 - V_210 -> V_15 ;
V_330 = F_203 ( V_210 ) ;
F_23 ( V_330 <= V_290 ) ;
F_23 ( V_16 < V_290 ) ;
V_295 = F_126 ( V_330 - V_290 , V_16 - V_290 + 1 ) ;
V_295 = F_212 ( V_295 , V_297 ) ;
V_177 = ( V_210 -> V_215 + V_291 ) >> 9 ;
V_192 = V_210 -> V_192 ;
V_215 = V_210 -> V_215 ;
V_325 = F_163 ( V_216 , & V_210 -> V_7 ) ;
F_162 ( V_210 ) ;
V_210 = NULL ;
if ( V_325 || V_215 == V_305 ||
V_215 == V_307 ) {
if ( ! V_325 && V_25 -> V_54 &&
V_25 -> V_54 -> V_241 )
V_25 -> V_54 -> V_241 ( V_128 , V_290 ,
V_290 + V_295 - 1 ,
NULL , 1 ) ;
else if ( V_325 ) {
V_294 ++ ;
}
V_290 += V_295 ;
V_172 += V_295 ;
continue;
}
V_331 = ( V_256 >> V_126 ) + 1 ;
F_105 ( V_25 , V_290 , V_290 + V_295 - 1 ) ;
if ( ! F_227 ( V_128 ) ) {
F_175 ( F_19 ( V_26 ) -> V_31 -> V_32 ,
L_27 ,
V_128 -> V_125 , V_290 , V_16 ) ;
}
V_37 = F_191 ( V_195 , V_323 , V_25 , V_274 ,
V_128 , V_177 , V_295 , V_172 ,
V_192 , & V_315 -> V_49 , V_331 ,
F_173 ,
0 , 0 , 0 , false ) ;
if ( V_37 )
F_123 ( V_128 ) ;
V_290 = V_290 + V_295 ;
V_172 += V_295 ;
V_294 ++ ;
}
V_146:
* V_324 = V_294 ;
V_329:
F_43 ( V_101 ) ;
return V_37 ;
}
static int F_228 ( struct V_128 * V_128 , struct V_273 * V_274 ,
void * V_223 )
{
struct V_26 * V_26 = V_128 -> V_28 -> V_29 ;
struct V_314 * V_315 = V_223 ;
T_1 V_15 = F_131 ( V_128 ) ;
T_1 V_289 = V_15 + V_30 - 1 ;
int V_37 ;
int V_294 = 0 ;
T_10 V_172 = 0 ;
T_8 V_256 = F_17 ( V_26 ) ;
unsigned long V_127 = V_256 >> V_126 ;
int V_323 = 0 ;
unsigned long V_312 = 0 ;
if ( V_274 -> V_332 == V_333 )
V_323 = V_196 ;
F_229 ( V_128 , V_26 , V_274 ) ;
F_45 ( ! F_230 ( V_128 ) ) ;
F_231 ( V_128 ) ;
V_172 = V_256 & ( V_30 - 1 ) ;
if ( V_128 -> V_125 > V_127 ||
( V_128 -> V_125 == V_127 && ! V_172 ) ) {
V_128 -> V_28 -> V_334 -> V_335 ( V_128 , 0 , V_30 ) ;
F_113 ( V_128 ) ;
return 0 ;
}
if ( V_128 -> V_125 == V_127 ) {
char * V_300 ;
V_300 = F_209 ( V_128 ) ;
memset ( V_300 + V_172 , 0 ,
V_30 - V_172 ) ;
F_211 ( V_300 ) ;
F_210 ( V_128 ) ;
}
V_172 = 0 ;
F_200 ( V_128 ) ;
V_37 = F_223 ( V_26 , V_128 , V_274 , V_315 , V_15 , & V_312 ) ;
if ( V_37 == 1 )
goto V_329;
if ( V_37 )
goto V_146;
V_37 = F_224 ( V_26 , V_128 , V_274 , V_315 ,
V_256 , V_312 , V_323 , & V_294 ) ;
if ( V_37 == 1 )
goto V_329;
V_146:
if ( V_294 == 0 ) {
F_106 ( V_128 ) ;
F_124 ( V_128 ) ;
}
if ( F_213 ( V_128 ) ) {
V_37 = V_37 < 0 ? V_37 : - V_152 ;
F_171 ( V_128 , V_37 , V_15 , V_289 ) ;
}
F_113 ( V_128 ) ;
return V_37 ;
V_329:
return 0 ;
}
void F_232 ( struct V_10 * V_11 )
{
F_233 ( & V_11 -> V_336 , V_337 ,
V_113 ) ;
}
static T_13 int
F_234 ( struct V_10 * V_11 ,
struct V_41 * V_32 ,
struct V_314 * V_315 )
{
unsigned long V_139 , V_200 ;
int V_338 = 0 ;
int V_37 = 0 ;
if ( ! F_235 ( V_11 ) ) {
V_338 = 1 ;
F_236 ( V_315 ) ;
F_237 ( V_11 ) ;
}
if ( F_163 ( V_337 , & V_11 -> V_336 ) ) {
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
if ( ! F_163 ( V_337 , & V_11 -> V_336 ) )
break;
F_238 ( V_11 ) ;
}
}
F_75 ( & V_11 -> V_340 ) ;
if ( F_239 ( V_341 , & V_11 -> V_336 ) ) {
F_240 ( V_337 , & V_11 -> V_336 ) ;
F_78 ( & V_11 -> V_340 ) ;
F_241 ( V_11 , V_342 ) ;
F_242 ( & V_32 -> V_343 ,
- V_11 -> V_21 ,
V_32 -> V_344 ) ;
V_37 = 1 ;
} else {
F_78 ( & V_11 -> V_340 ) ;
}
F_238 ( V_11 ) ;
if ( ! V_37 )
return V_37 ;
V_200 = F_151 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
struct V_128 * V_67 = V_11 -> V_137 [ V_139 ] ;
if ( ! F_243 ( V_67 ) ) {
if ( ! V_338 ) {
F_236 ( V_315 ) ;
V_338 = 1 ;
}
F_115 ( V_67 ) ;
}
}
return V_37 ;
}
static void F_244 ( struct V_10 * V_11 )
{
F_245 ( V_337 , & V_11 -> V_336 ) ;
F_246 () ;
F_247 ( & V_11 -> V_336 , V_337 ) ;
}
static void F_248 ( struct V_128 * V_128 )
{
struct V_10 * V_11 = (struct V_10 * ) V_128 -> V_203 ;
struct V_345 * V_346 = F_19 ( V_11 -> V_32 -> V_202 ) ;
F_123 ( V_128 ) ;
if ( F_249 ( V_347 , & V_11 -> V_336 ) )
return;
switch ( V_11 -> V_348 ) {
case - 1 :
F_240 ( V_349 , & V_346 -> V_350 ) ;
break;
case 0 :
F_240 ( V_351 , & V_346 -> V_350 ) ;
break;
case 1 :
F_240 ( V_352 , & V_346 -> V_350 ) ;
break;
default:
F_250 () ;
}
}
static void F_251 ( struct V_49 * V_49 )
{
struct V_242 * V_243 ;
struct V_10 * V_11 ;
int V_139 , V_146 ;
F_174 (bvec, bio, i) {
struct V_128 * V_128 = V_243 -> V_244 ;
V_11 = (struct V_10 * ) V_128 -> V_203 ;
F_23 ( ! V_11 ) ;
V_146 = F_44 ( & V_11 -> V_353 ) ;
if ( V_49 -> V_247 ||
F_163 ( V_347 , & V_11 -> V_336 ) ) {
F_172 ( V_128 ) ;
F_248 ( V_128 ) ;
}
F_124 ( V_128 ) ;
if ( ! V_146 )
continue;
F_244 ( V_11 ) ;
}
F_142 ( V_49 ) ;
}
static T_13 int F_252 ( struct V_10 * V_11 ,
struct V_41 * V_32 ,
struct V_273 * V_274 ,
struct V_314 * V_315 )
{
struct V_259 * V_192 = V_32 -> V_226 -> V_227 ;
struct V_24 * V_25 = & F_19 ( V_32 -> V_202 ) -> V_150 ;
T_1 V_63 = V_11 -> V_15 ;
unsigned long V_139 , V_200 ;
unsigned long V_214 = 0 ;
int V_323 = ( V_315 -> V_339 ? V_196 : 0 ) | V_354 ;
int V_37 = 0 ;
F_245 ( V_347 , & V_11 -> V_336 ) ;
V_200 = F_151 ( V_11 -> V_15 , V_11 -> V_21 ) ;
F_40 ( & V_11 -> V_353 , V_200 ) ;
if ( F_253 ( V_11 ) == V_355 )
V_214 = V_356 ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
struct V_128 * V_67 = V_11 -> V_137 [ V_139 ] ;
F_100 ( V_67 ) ;
F_106 ( V_67 ) ;
V_37 = F_191 ( V_195 , V_323 , V_25 , V_274 ,
V_67 , V_63 >> 9 , V_30 , 0 , V_192 ,
& V_315 -> V_49 , - 1 ,
F_251 ,
0 , V_315 -> V_214 , V_214 , false ) ;
V_315 -> V_214 = V_214 ;
if ( V_37 ) {
F_248 ( V_67 ) ;
F_124 ( V_67 ) ;
if ( F_254 ( V_200 - V_139 , & V_11 -> V_353 ) )
F_244 ( V_11 ) ;
V_37 = - V_152 ;
break;
}
V_63 += V_30 ;
F_222 ( V_67 , V_274 , 1 ) ;
F_113 ( V_67 ) ;
}
if ( F_182 ( V_37 ) ) {
for (; V_139 < V_200 ; V_139 ++ ) {
struct V_128 * V_67 = V_11 -> V_137 [ V_139 ] ;
F_100 ( V_67 ) ;
F_113 ( V_67 ) ;
}
}
return V_37 ;
}
int F_255 ( struct V_52 * V_28 ,
struct V_273 * V_274 )
{
struct V_24 * V_25 = & F_19 ( V_28 -> V_29 ) -> V_150 ;
struct V_41 * V_32 = F_19 ( V_28 -> V_29 ) -> V_31 -> V_32 ;
struct V_10 * V_11 , * V_357 = NULL ;
struct V_314 V_315 = {
. V_49 = NULL ,
. V_25 = V_25 ,
. V_319 = 0 ,
. V_339 = V_274 -> V_332 == V_333 ,
. V_214 = 0 ,
} ;
int V_37 = 0 ;
int V_146 = 0 ;
int V_358 = 0 ;
struct V_359 V_360 ;
int V_138 ;
T_9 V_125 ;
T_9 V_16 ;
int V_361 = 0 ;
int V_362 ;
F_256 ( & V_360 , 0 ) ;
if ( V_274 -> V_363 ) {
V_125 = V_28 -> V_364 ;
V_16 = - 1 ;
} else {
V_125 = V_274 -> V_365 >> V_126 ;
V_16 = V_274 -> V_366 >> V_126 ;
V_361 = 1 ;
}
if ( V_274 -> V_332 == V_333 )
V_362 = V_367 ;
else
V_362 = V_368 ;
V_369:
if ( V_274 -> V_332 == V_333 )
F_257 ( V_28 , V_125 , V_16 ) ;
while ( ! V_146 && ! V_358 && ( V_125 <= V_16 ) &&
( V_138 = F_258 ( & V_360 , V_28 , & V_125 , V_362 ,
F_126 ( V_16 - V_125 , ( T_9 ) V_370 - 1 ) + 1 ) ) ) {
unsigned V_139 ;
V_361 = 1 ;
for ( V_139 = 0 ; V_139 < V_138 ; V_139 ++ ) {
struct V_128 * V_128 = V_360 . V_137 [ V_139 ] ;
if ( ! F_196 ( V_128 ) )
continue;
if ( ! V_274 -> V_363 && V_128 -> V_125 > V_16 ) {
V_146 = 1 ;
break;
}
F_75 ( & V_28 -> V_371 ) ;
if ( ! F_196 ( V_128 ) ) {
F_78 ( & V_28 -> V_371 ) ;
continue;
}
V_11 = (struct V_10 * ) V_128 -> V_203 ;
if ( F_45 ( ! V_11 ) ) {
F_78 ( & V_28 -> V_371 ) ;
continue;
}
if ( V_11 == V_357 ) {
F_78 ( & V_28 -> V_371 ) ;
continue;
}
V_37 = F_259 ( & V_11 -> V_17 ) ;
F_78 ( & V_28 -> V_371 ) ;
if ( ! V_37 )
continue;
V_357 = V_11 ;
V_37 = F_234 ( V_11 , V_32 , & V_315 ) ;
if ( ! V_37 ) {
F_260 ( V_11 ) ;
continue;
}
V_37 = F_252 ( V_11 , V_32 , V_274 , & V_315 ) ;
if ( V_37 ) {
V_146 = 1 ;
F_260 ( V_11 ) ;
break;
}
F_260 ( V_11 ) ;
V_358 = V_274 -> V_313 <= 0 ;
}
F_261 ( & V_360 ) ;
F_79 () ;
}
if ( ! V_361 && ! V_146 ) {
V_361 = 1 ;
V_125 = 0 ;
goto V_369;
}
F_236 ( & V_315 ) ;
return V_37 ;
}
static int F_262 ( struct V_24 * V_25 ,
struct V_52 * V_28 ,
struct V_273 * V_274 ,
T_14 V_372 , void * V_223 ,
void (* F_263)( void * ) )
{
struct V_26 * V_26 = V_28 -> V_29 ;
int V_37 = 0 ;
int V_146 = 0 ;
int V_358 = 0 ;
struct V_359 V_360 ;
int V_138 ;
T_9 V_125 ;
T_9 V_16 ;
T_9 V_373 ;
int V_374 = 0 ;
int V_361 = 0 ;
int V_362 ;
if ( ! F_264 ( V_26 ) )
return 0 ;
F_256 ( & V_360 , 0 ) ;
if ( V_274 -> V_363 ) {
V_125 = V_28 -> V_364 ;
V_16 = - 1 ;
} else {
V_125 = V_274 -> V_365 >> V_126 ;
V_16 = V_274 -> V_366 >> V_126 ;
if ( V_274 -> V_365 == 0 && V_274 -> V_366 == V_375 )
V_374 = 1 ;
V_361 = 1 ;
}
if ( V_274 -> V_332 == V_333 )
V_362 = V_367 ;
else
V_362 = V_368 ;
V_369:
if ( V_274 -> V_332 == V_333 )
F_257 ( V_28 , V_125 , V_16 ) ;
V_373 = V_125 ;
while ( ! V_146 && ! V_358 && ( V_125 <= V_16 ) &&
( V_138 = F_258 ( & V_360 , V_28 , & V_125 , V_362 ,
F_126 ( V_16 - V_125 , ( T_9 ) V_370 - 1 ) + 1 ) ) ) {
unsigned V_139 ;
V_361 = 1 ;
for ( V_139 = 0 ; V_139 < V_138 ; V_139 ++ ) {
struct V_128 * V_128 = V_360 . V_137 [ V_139 ] ;
V_373 = V_128 -> V_125 ;
if ( ! F_243 ( V_128 ) ) {
F_263 ( V_223 ) ;
F_115 ( V_128 ) ;
}
if ( F_182 ( V_128 -> V_28 != V_28 ) ) {
F_113 ( V_128 ) ;
continue;
}
if ( ! V_274 -> V_363 && V_128 -> V_125 > V_16 ) {
V_146 = 1 ;
F_113 ( V_128 ) ;
continue;
}
if ( V_274 -> V_332 != V_376 ) {
if ( F_227 ( V_128 ) )
F_263 ( V_223 ) ;
F_265 ( V_128 ) ;
}
if ( F_227 ( V_128 ) ||
! F_100 ( V_128 ) ) {
F_113 ( V_128 ) ;
continue;
}
V_37 = (* V_372)( V_128 , V_274 , V_223 ) ;
if ( F_182 ( V_37 == V_377 ) ) {
F_113 ( V_128 ) ;
V_37 = 0 ;
}
if ( V_37 < 0 ) {
V_373 = V_128 -> V_125 + 1 ;
V_146 = 1 ;
break;
}
V_358 = V_274 -> V_313 <= 0 ;
}
F_261 ( & V_360 ) ;
F_79 () ;
}
if ( ! V_361 && ! V_146 ) {
V_361 = 1 ;
V_125 = 0 ;
goto V_369;
}
if ( V_274 -> V_363 || ( V_274 -> V_313 > 0 && V_374 ) )
V_28 -> V_364 = V_373 ;
F_266 ( V_26 ) ;
return V_37 ;
}
static void F_267 ( struct V_314 * V_315 )
{
if ( V_315 -> V_49 ) {
int V_37 ;
F_144 ( V_315 -> V_49 , V_195 ,
V_315 -> V_339 ? V_196 : 0 ) ;
V_37 = F_187 ( V_315 -> V_49 , 0 , V_315 -> V_214 ) ;
F_23 ( V_37 < 0 ) ;
V_315 -> V_49 = NULL ;
}
}
static T_5 void F_236 ( void * V_223 )
{
struct V_314 * V_315 = V_223 ;
F_267 ( V_315 ) ;
}
int F_268 ( struct V_24 * V_25 , struct V_128 * V_128 ,
T_12 * V_285 ,
struct V_273 * V_274 )
{
int V_37 ;
struct V_314 V_315 = {
. V_49 = NULL ,
. V_25 = V_25 ,
. V_285 = V_285 ,
. V_319 = 0 ,
. V_339 = V_274 -> V_332 == V_333 ,
. V_214 = 0 ,
} ;
V_37 = F_228 ( V_128 , V_274 , & V_315 ) ;
F_267 ( & V_315 ) ;
return V_37 ;
}
int F_269 ( struct V_24 * V_25 , struct V_26 * V_26 ,
T_1 V_15 , T_1 V_16 , T_12 * V_285 ,
int V_378 )
{
int V_37 = 0 ;
struct V_52 * V_28 = V_26 -> V_129 ;
struct V_128 * V_128 ;
unsigned long V_138 = ( V_16 - V_15 + V_30 ) >>
V_126 ;
struct V_314 V_315 = {
. V_49 = NULL ,
. V_25 = V_25 ,
. V_285 = V_285 ,
. V_319 = 1 ,
. V_339 = V_378 == V_333 ,
. V_214 = 0 ,
} ;
struct V_273 V_379 = {
. V_332 = V_378 ,
. V_313 = V_138 * 2 ,
. V_365 = V_15 ,
. V_366 = V_16 + 1 ,
} ;
while ( V_15 <= V_16 ) {
V_128 = F_99 ( V_28 , V_15 >> V_126 ) ;
if ( F_100 ( V_128 ) )
V_37 = F_228 ( V_128 , & V_379 , & V_315 ) ;
else {
if ( V_25 -> V_54 && V_25 -> V_54 -> V_241 )
V_25 -> V_54 -> V_241 ( V_128 , V_15 ,
V_15 + V_30 - 1 ,
NULL , 1 ) ;
F_113 ( V_128 ) ;
}
F_101 ( V_128 ) ;
V_15 += V_30 ;
}
F_267 ( & V_315 ) ;
return V_37 ;
}
int F_270 ( struct V_24 * V_25 ,
struct V_52 * V_28 ,
T_12 * V_285 ,
struct V_273 * V_274 )
{
int V_37 = 0 ;
struct V_314 V_315 = {
. V_49 = NULL ,
. V_25 = V_25 ,
. V_285 = V_285 ,
. V_319 = 0 ,
. V_339 = V_274 -> V_332 == V_333 ,
. V_214 = 0 ,
} ;
V_37 = F_262 ( V_25 , V_28 , V_274 ,
F_228 , & V_315 ,
F_236 ) ;
F_267 ( & V_315 ) ;
return V_37 ;
}
int F_271 ( struct V_24 * V_25 ,
struct V_52 * V_28 ,
struct V_4 * V_137 , unsigned V_138 ,
T_12 V_285 )
{
struct V_49 * V_49 = NULL ;
unsigned V_380 ;
unsigned long V_214 = 0 ;
struct V_128 * V_381 [ 16 ] ;
struct V_128 * V_128 ;
struct V_209 * V_286 = NULL ;
int V_294 = 0 ;
T_1 V_288 = ( T_1 ) - 1 ;
for ( V_380 = 0 ; V_380 < V_138 ; V_380 ++ ) {
V_128 = F_11 ( V_137 -> V_78 , struct V_128 , V_382 ) ;
F_272 ( & V_128 -> V_7 ) ;
F_8 ( & V_128 -> V_382 ) ;
if ( F_273 ( V_128 , V_28 ,
V_128 -> V_125 ,
F_274 ( V_28 ) ) ) {
F_101 ( V_128 ) ;
continue;
}
V_381 [ V_294 ++ ] = V_128 ;
if ( V_294 < F_275 ( V_381 ) )
continue;
F_219 ( V_25 , V_381 , V_294 , V_285 , & V_286 ,
& V_49 , 0 , & V_214 , & V_288 ) ;
V_294 = 0 ;
}
if ( V_294 )
F_219 ( V_25 , V_381 , V_294 , V_285 , & V_286 ,
& V_49 , 0 , & V_214 , & V_288 ) ;
if ( V_286 )
F_162 ( V_286 ) ;
F_23 ( ! F_10 ( V_137 ) ) ;
if ( V_49 )
return F_187 ( V_49 , 0 , V_214 ) ;
return 0 ;
}
int F_276 ( struct V_24 * V_25 ,
struct V_128 * V_128 , unsigned long V_63 )
{
struct V_1 * V_101 = NULL ;
T_1 V_15 = F_131 ( V_128 ) ;
T_1 V_16 = V_15 + V_30 - 1 ;
T_10 V_297 = V_128 -> V_28 -> V_29 -> V_42 -> V_298 ;
V_15 += F_212 ( V_63 , V_297 ) ;
if ( V_15 > V_16 )
return 0 ;
F_96 ( V_25 , V_15 , V_16 , & V_101 ) ;
F_265 ( V_128 ) ;
F_94 ( V_25 , V_15 , V_16 ,
V_124 | V_97 | V_105 |
V_383 ,
1 , 1 , & V_101 , V_123 ) ;
return 0 ;
}
static int F_277 ( struct V_211 * V_384 ,
struct V_24 * V_25 ,
struct V_128 * V_128 , T_3 V_57 )
{
T_1 V_15 = F_131 ( V_128 ) ;
T_1 V_16 = V_15 + V_30 - 1 ;
int V_37 = 1 ;
if ( F_118 ( V_25 , V_15 , V_16 ,
V_84 , 0 , NULL ) )
V_37 = 0 ;
else {
if ( ( V_57 & V_123 ) == V_123 )
V_57 = V_123 ;
V_37 = F_94 ( V_25 , V_15 , V_16 ,
~ ( V_124 | V_385 ) ,
0 , 0 , NULL , V_57 ) ;
if ( V_37 < 0 )
V_37 = 0 ;
else
V_37 = 1 ;
}
return V_37 ;
}
int F_278 ( struct V_211 * V_384 ,
struct V_24 * V_25 , struct V_128 * V_128 ,
T_3 V_57 )
{
struct V_209 * V_210 ;
T_1 V_15 = F_131 ( V_128 ) ;
T_1 V_16 = V_15 + V_30 - 1 ;
if ( F_74 ( V_57 ) &&
V_128 -> V_28 -> V_29 -> V_256 > V_386 ) {
T_1 V_21 ;
while ( V_15 <= V_16 ) {
V_21 = V_16 - V_15 + 1 ;
F_279 ( & V_384 -> V_56 ) ;
V_210 = F_160 ( V_384 , V_15 , V_21 ) ;
if ( ! V_210 ) {
F_280 ( & V_384 -> V_56 ) ;
break;
}
if ( F_163 ( V_387 , & V_210 -> V_7 ) ||
V_210 -> V_15 != V_15 ) {
F_280 ( & V_384 -> V_56 ) ;
F_162 ( V_210 ) ;
break;
}
if ( ! F_118 ( V_25 , V_210 -> V_15 ,
F_203 ( V_210 ) - 1 ,
V_124 | V_388 ,
0 , NULL ) ) {
F_281 ( V_384 , V_210 ) ;
F_162 ( V_210 ) ;
}
V_15 = F_203 ( V_210 ) ;
F_280 ( & V_384 -> V_56 ) ;
F_162 ( V_210 ) ;
}
}
return F_277 ( V_384 , V_25 , V_128 , V_57 ) ;
}
static struct V_209 * F_282 ( struct V_26 * V_26 ,
T_1 V_63 ,
T_1 V_160 ,
T_12 * V_285 )
{
T_1 V_389 = F_19 ( V_26 ) -> V_31 -> V_389 ;
struct V_209 * V_210 ;
T_1 V_21 ;
if ( V_63 >= V_160 )
return NULL ;
while ( 1 ) {
V_21 = V_160 - V_63 ;
if ( V_21 == 0 )
break;
V_21 = F_212 ( V_21 , V_389 ) ;
V_210 = V_285 ( V_26 , NULL , 0 , V_63 , V_21 , 0 ) ;
if ( F_204 ( V_210 ) )
return V_210 ;
if ( ! F_163 ( V_390 , & V_210 -> V_7 ) &&
V_210 -> V_215 != V_305 ) {
return V_210 ;
}
V_63 = F_203 ( V_210 ) ;
F_162 ( V_210 ) ;
if ( V_63 >= V_160 )
break;
}
return NULL ;
}
int F_283 ( struct V_26 * V_26 , struct V_391 * V_392 ,
T_15 V_15 , T_15 V_21 , T_12 * V_285 )
{
int V_37 = 0 ;
T_1 V_257 = V_15 ;
T_1 F_127 = V_15 + V_21 ;
T_16 V_7 = 0 ;
T_16 V_393 ;
T_1 V_160 ;
T_1 V_394 = 0 ;
T_1 V_395 = 0 ;
T_1 V_27 = F_17 ( V_26 ) ;
struct V_396 V_397 ;
struct V_209 * V_210 = NULL ;
struct V_1 * V_101 = NULL ;
struct V_398 * V_399 ;
struct V_199 * V_31 = F_19 ( V_26 ) -> V_31 ;
int V_16 = 0 ;
T_1 V_400 = 0 ;
T_1 V_401 = 0 ;
T_1 V_330 = 0 ;
if ( V_21 == 0 )
return - V_402 ;
V_399 = F_284 () ;
if ( ! V_399 )
return - V_44 ;
V_399 -> V_403 = 1 ;
V_15 = F_285 ( V_15 , F_19 ( V_26 ) -> V_31 -> V_389 ) ;
V_21 = F_286 ( F_127 , F_19 ( V_26 ) -> V_31 -> V_389 ) - V_15 ;
V_37 = F_287 ( NULL , V_31 , V_399 , F_20 ( V_26 ) , - 1 ,
0 ) ;
if ( V_37 < 0 ) {
F_288 ( V_399 ) ;
return V_37 ;
} else {
F_45 ( ! V_37 ) ;
if ( V_37 == 1 )
V_37 = 0 ;
}
V_399 -> V_404 [ 0 ] -- ;
F_289 ( V_399 -> V_405 [ 0 ] , & V_397 , V_399 -> V_404 [ 0 ] ) ;
V_393 = V_397 . type ;
if ( V_397 . V_406 != F_20 ( V_26 ) ||
V_393 != V_407 ) {
V_160 = ( T_1 ) - 1 ;
V_394 = V_27 ;
} else {
V_160 = V_397 . V_63 ;
V_394 = V_160 + 1 ;
}
F_290 ( V_399 ) ;
if ( V_160 < V_27 ) {
V_160 = ( T_1 ) - 1 ;
V_394 = V_27 ;
}
F_96 ( & F_19 ( V_26 ) -> V_150 , V_15 , V_15 + V_21 - 1 ,
& V_101 ) ;
V_210 = F_282 ( V_26 , V_15 , V_394 ,
V_285 ) ;
if ( ! V_210 )
goto V_110;
if ( F_291 ( V_210 ) ) {
V_37 = F_292 ( V_210 ) ;
goto V_110;
}
while ( ! V_16 ) {
T_1 V_408 = 0 ;
if ( V_210 -> V_15 >= F_127 || F_203 ( V_210 ) < V_257 )
break;
V_400 = F_127 ( V_210 -> V_15 , V_257 ) ;
if ( ! F_163 ( V_216 , & V_210 -> V_7 ) )
V_408 = V_400 - V_210 -> V_15 ;
V_330 = F_203 ( V_210 ) ;
V_401 = V_330 - V_400 ;
V_395 = 0 ;
V_7 = 0 ;
V_257 = F_203 ( V_210 ) ;
if ( V_257 >= F_127 )
V_16 = 1 ;
if ( V_210 -> V_215 == V_409 ) {
V_16 = 1 ;
V_7 |= V_410 ;
} else if ( V_210 -> V_215 == V_307 ) {
V_7 |= ( V_411 |
V_412 ) ;
} else if ( V_210 -> V_215 == V_413 ) {
V_7 |= ( V_414 |
V_415 ) ;
} else if ( V_392 -> V_416 ) {
T_1 V_417 = V_210 -> V_215 -
( V_210 -> V_15 - V_210 -> V_306 ) ;
V_395 = V_210 -> V_215 + V_408 ;
V_37 = F_293 ( NULL , V_31 -> V_32 ,
V_31 -> V_406 ,
F_20 ( V_26 ) , V_417 ) ;
if ( V_37 < 0 )
goto V_418;
if ( V_37 )
V_7 |= V_419 ;
V_37 = 0 ;
}
if ( F_163 ( V_216 , & V_210 -> V_7 ) )
V_7 |= V_420 ;
if ( F_163 ( V_304 , & V_210 -> V_7 ) )
V_7 |= V_421 ;
F_162 ( V_210 ) ;
V_210 = NULL ;
if ( ( V_400 >= V_160 ) || V_401 == ( T_1 ) - 1 ||
( V_160 == ( T_1 ) - 1 && V_27 <= V_330 ) ) {
V_7 |= V_410 ;
V_16 = 1 ;
}
V_210 = F_282 ( V_26 , V_257 , V_394 ,
V_285 ) ;
if ( F_291 ( V_210 ) ) {
V_37 = F_292 ( V_210 ) ;
goto V_110;
}
if ( ! V_210 ) {
V_7 |= V_410 ;
V_16 = 1 ;
}
V_37 = F_294 ( V_392 , V_400 , V_395 ,
V_401 , V_7 ) ;
if ( V_37 ) {
if ( V_37 == 1 )
V_37 = 0 ;
goto V_418;
}
}
V_418:
F_162 ( V_210 ) ;
V_110:
F_288 ( V_399 ) ;
F_119 ( & F_19 ( V_26 ) -> V_150 , V_15 , V_15 + V_21 - 1 ,
& V_101 , V_123 ) ;
return V_37 ;
}
static void F_295 ( struct V_10 * V_11 )
{
F_7 ( & V_11 -> V_14 ) ;
F_14 ( V_22 , V_11 ) ;
}
int F_296 ( struct V_10 * V_11 )
{
return ( F_13 ( & V_11 -> V_353 ) ||
F_163 ( V_337 , & V_11 -> V_336 ) ||
F_163 ( V_341 , & V_11 -> V_336 ) ) ;
}
static void F_297 ( struct V_10 * V_11 )
{
unsigned long V_125 ;
struct V_128 * V_128 ;
int V_422 = ! F_163 ( V_423 , & V_11 -> V_336 ) ;
F_23 ( F_296 ( V_11 ) ) ;
V_125 = F_151 ( V_11 -> V_15 , V_11 -> V_21 ) ;
if ( V_125 == 0 )
return;
do {
V_125 -- ;
V_128 = V_11 -> V_137 [ V_125 ] ;
if ( ! V_128 )
continue;
if ( V_422 )
F_75 ( & V_128 -> V_28 -> V_371 ) ;
if ( F_196 ( V_128 ) &&
V_128 -> V_203 == ( unsigned long ) V_11 ) {
F_23 ( F_163 ( V_341 , & V_11 -> V_336 ) ) ;
F_23 ( F_116 ( V_128 ) ) ;
F_23 ( F_227 ( V_128 ) ) ;
F_298 ( V_128 ) ;
F_199 ( V_128 , 0 ) ;
F_101 ( V_128 ) ;
}
if ( V_422 )
F_78 ( & V_128 -> V_28 -> V_371 ) ;
F_101 ( V_128 ) ;
} while ( V_125 != 0 );
}
static inline void F_299 ( struct V_10 * V_11 )
{
F_297 ( V_11 ) ;
F_295 ( V_11 ) ;
}
static struct V_10 *
F_300 ( struct V_41 * V_32 , T_1 V_15 ,
unsigned long V_21 )
{
struct V_10 * V_11 = NULL ;
V_11 = F_301 ( V_22 , V_123 | V_424 ) ;
V_11 -> V_15 = V_15 ;
V_11 -> V_21 = V_21 ;
V_11 -> V_32 = V_32 ;
V_11 -> V_336 = 0 ;
F_302 ( & V_11 -> V_56 ) ;
F_40 ( & V_11 -> V_425 , 0 ) ;
F_40 ( & V_11 -> V_426 , 0 ) ;
F_40 ( & V_11 -> V_427 , 0 ) ;
F_40 ( & V_11 -> V_428 , 0 ) ;
F_40 ( & V_11 -> V_429 , 0 ) ;
F_40 ( & V_11 -> V_430 , 0 ) ;
V_11 -> V_431 = 0 ;
F_41 ( & V_11 -> V_432 ) ;
F_41 ( & V_11 -> V_433 ) ;
F_3 ( & V_11 -> V_14 , & V_19 ) ;
F_36 ( & V_11 -> V_340 ) ;
F_40 ( & V_11 -> V_17 , 1 ) ;
F_40 ( & V_11 -> V_353 , 0 ) ;
F_303 ( V_434
> V_435 ) ;
F_23 ( V_21 > V_435 ) ;
return V_11 ;
}
struct V_10 * F_304 ( struct V_10 * V_436 )
{
unsigned long V_139 ;
struct V_128 * V_67 ;
struct V_10 * V_5 ;
unsigned long V_200 = F_151 ( V_436 -> V_15 , V_436 -> V_21 ) ;
V_5 = F_300 ( V_436 -> V_32 , V_436 -> V_15 , V_436 -> V_21 ) ;
if ( V_5 == NULL )
return NULL ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
V_67 = F_305 ( V_123 ) ;
if ( ! V_67 ) {
F_299 ( V_5 ) ;
return NULL ;
}
F_195 ( V_5 , V_67 ) ;
F_45 ( F_116 ( V_67 ) ) ;
F_132 ( V_67 ) ;
V_5 -> V_137 [ V_139 ] = V_67 ;
}
F_306 ( V_5 , V_436 , 0 , 0 , V_436 -> V_21 ) ;
F_240 ( V_437 , & V_5 -> V_336 ) ;
F_240 ( V_423 , & V_5 -> V_336 ) ;
return V_5 ;
}
struct V_10 * F_307 ( struct V_41 * V_32 ,
T_1 V_15 , unsigned long V_21 )
{
struct V_10 * V_11 ;
unsigned long V_200 ;
unsigned long V_139 ;
V_200 = F_151 ( V_15 , V_21 ) ;
V_11 = F_300 ( V_32 , V_15 , V_21 ) ;
if ( ! V_11 )
return NULL ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
V_11 -> V_137 [ V_139 ] = F_305 ( V_123 ) ;
if ( ! V_11 -> V_137 [ V_139 ] )
goto V_99;
}
F_308 ( V_11 ) ;
F_309 ( V_11 , 0 ) ;
F_240 ( V_423 , & V_11 -> V_336 ) ;
return V_11 ;
V_99:
for (; V_139 > 0 ; V_139 -- )
F_310 ( V_11 -> V_137 [ V_139 - 1 ] ) ;
F_295 ( V_11 ) ;
return NULL ;
}
struct V_10 * F_311 ( struct V_41 * V_32 ,
T_1 V_15 , T_16 V_438 )
{
unsigned long V_21 ;
if ( ! V_32 ) {
V_21 = V_438 ;
} else {
V_21 = V_32 -> V_439 -> V_438 ;
}
return F_307 ( V_32 , V_15 , V_21 ) ;
}
static void F_312 ( struct V_10 * V_11 )
{
int V_17 ;
V_17 = F_13 ( & V_11 -> V_17 ) ;
if ( V_17 >= 2 && F_163 ( V_440 , & V_11 -> V_336 ) )
return;
F_75 ( & V_11 -> V_340 ) ;
if ( ! F_249 ( V_440 , & V_11 -> V_336 ) )
F_86 ( & V_11 -> V_17 ) ;
F_78 ( & V_11 -> V_340 ) ;
}
static void F_313 ( struct V_10 * V_11 ,
struct V_128 * V_441 )
{
unsigned long V_200 , V_139 ;
F_312 ( V_11 ) ;
V_200 = F_151 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
struct V_128 * V_67 = V_11 -> V_137 [ V_139 ] ;
if ( V_67 != V_441 )
F_314 ( V_67 ) ;
}
}
struct V_10 * F_315 ( struct V_41 * V_32 ,
T_1 V_15 )
{
struct V_10 * V_11 ;
F_316 () ;
V_11 = F_317 ( & V_32 -> V_442 ,
V_15 >> V_126 ) ;
if ( V_11 && F_259 ( & V_11 -> V_17 ) ) {
F_318 () ;
if ( F_163 ( V_443 , & V_11 -> V_336 ) ) {
F_75 ( & V_11 -> V_340 ) ;
F_78 ( & V_11 -> V_340 ) ;
}
F_313 ( V_11 , NULL ) ;
return V_11 ;
}
F_318 () ;
return NULL ;
}
struct V_10 * F_319 ( struct V_41 * V_32 ,
T_1 V_15 , T_16 V_438 )
{
struct V_10 * V_11 , * V_444 = NULL ;
int V_37 ;
V_11 = F_315 ( V_32 , V_15 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_311 ( V_32 , V_15 , V_438 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_32 = V_32 ;
V_108:
V_37 = F_320 ( V_123 ) ;
if ( V_37 )
goto V_445;
F_75 ( & V_32 -> V_446 ) ;
V_37 = F_321 ( & V_32 -> V_442 ,
V_15 >> V_126 , V_11 ) ;
F_78 ( & V_32 -> V_446 ) ;
F_322 () ;
if ( V_37 == - V_89 ) {
V_444 = F_315 ( V_32 , V_15 ) ;
if ( V_444 )
goto V_445;
else
goto V_108;
}
F_312 ( V_11 ) ;
F_240 ( V_447 , & V_11 -> V_336 ) ;
F_86 ( & V_11 -> V_17 ) ;
return V_11 ;
V_445:
F_299 ( V_11 ) ;
return V_444 ;
}
struct V_10 * F_323 ( struct V_41 * V_32 ,
T_1 V_15 )
{
unsigned long V_21 = V_32 -> V_439 -> V_438 ;
unsigned long V_200 = F_151 ( V_15 , V_21 ) ;
unsigned long V_139 ;
unsigned long V_125 = V_15 >> V_126 ;
struct V_10 * V_11 ;
struct V_10 * V_444 = NULL ;
struct V_128 * V_67 ;
struct V_52 * V_28 = V_32 -> V_202 -> V_129 ;
int V_240 = 1 ;
int V_37 ;
if ( ! F_324 ( V_15 , V_32 -> V_439 -> V_389 ) ) {
F_175 ( V_32 , L_28 , V_15 ) ;
return F_325 ( - V_402 ) ;
}
V_11 = F_315 ( V_32 , V_15 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_300 ( V_32 , V_15 , V_21 ) ;
if ( ! V_11 )
return F_325 ( - V_44 ) ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ , V_125 ++ ) {
V_67 = F_326 ( V_28 , V_125 , V_123 | V_424 ) ;
if ( ! V_67 ) {
V_444 = F_325 ( - V_44 ) ;
goto V_445;
}
F_75 ( & V_28 -> V_371 ) ;
if ( F_196 ( V_67 ) ) {
V_444 = (struct V_10 * ) V_67 -> V_203 ;
if ( F_259 ( & V_444 -> V_17 ) ) {
F_78 ( & V_28 -> V_371 ) ;
F_113 ( V_67 ) ;
F_101 ( V_67 ) ;
F_313 ( V_444 , V_67 ) ;
goto V_445;
}
V_444 = NULL ;
F_298 ( V_67 ) ;
F_45 ( F_116 ( V_67 ) ) ;
F_101 ( V_67 ) ;
}
F_195 ( V_11 , V_67 ) ;
F_78 ( & V_28 -> V_371 ) ;
F_45 ( F_116 ( V_67 ) ) ;
V_11 -> V_137 [ V_139 ] = V_67 ;
if ( ! F_206 ( V_67 ) )
V_240 = 0 ;
}
if ( V_240 )
F_240 ( V_437 , & V_11 -> V_336 ) ;
V_108:
V_37 = F_320 ( V_123 ) ;
if ( V_37 ) {
V_444 = F_325 ( V_37 ) ;
goto V_445;
}
F_75 ( & V_32 -> V_446 ) ;
V_37 = F_321 ( & V_32 -> V_442 ,
V_15 >> V_126 , V_11 ) ;
F_78 ( & V_32 -> V_446 ) ;
F_322 () ;
if ( V_37 == - V_89 ) {
V_444 = F_315 ( V_32 , V_15 ) ;
if ( V_444 )
goto V_445;
else
goto V_108;
}
F_312 ( V_11 ) ;
F_240 ( V_447 , & V_11 -> V_336 ) ;
F_327 ( V_11 -> V_137 [ 0 ] ) ;
for ( V_139 = 1 ; V_139 < V_200 ; V_139 ++ ) {
V_67 = V_11 -> V_137 [ V_139 ] ;
F_328 ( V_67 ) ;
F_113 ( V_67 ) ;
}
F_113 ( V_11 -> V_137 [ 0 ] ) ;
return V_11 ;
V_445:
F_45 ( ! F_44 ( & V_11 -> V_17 ) ) ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
if ( V_11 -> V_137 [ V_139 ] )
F_113 ( V_11 -> V_137 [ V_139 ] ) ;
}
F_299 ( V_11 ) ;
return V_444 ;
}
static inline void F_329 ( struct V_448 * V_6 )
{
struct V_10 * V_11 =
F_330 ( V_6 , struct V_10 , V_448 ) ;
F_295 ( V_11 ) ;
}
static int F_331 ( struct V_10 * V_11 )
{
F_45 ( F_13 ( & V_11 -> V_17 ) == 0 ) ;
if ( F_44 ( & V_11 -> V_17 ) ) {
if ( F_239 ( V_447 , & V_11 -> V_336 ) ) {
struct V_41 * V_32 = V_11 -> V_32 ;
F_78 ( & V_11 -> V_340 ) ;
F_75 ( & V_32 -> V_446 ) ;
F_332 ( & V_32 -> V_442 ,
V_11 -> V_15 >> V_126 ) ;
F_78 ( & V_32 -> V_446 ) ;
} else {
F_78 ( & V_11 -> V_340 ) ;
}
F_297 ( V_11 ) ;
#ifdef F_333
if ( F_182 ( F_163 ( V_423 , & V_11 -> V_336 ) ) ) {
F_295 ( V_11 ) ;
return 1 ;
}
#endif
F_334 ( & V_11 -> V_448 , F_329 ) ;
return 1 ;
}
F_78 ( & V_11 -> V_340 ) ;
return 0 ;
}
void F_260 ( struct V_10 * V_11 )
{
int V_17 ;
int V_449 ;
if ( ! V_11 )
return;
while ( 1 ) {
V_17 = F_13 ( & V_11 -> V_17 ) ;
if ( V_17 <= 3 )
break;
V_449 = F_335 ( & V_11 -> V_17 , V_17 , V_17 - 1 ) ;
if ( V_449 == V_17 )
return;
}
F_75 ( & V_11 -> V_340 ) ;
if ( F_13 ( & V_11 -> V_17 ) == 2 &&
F_163 ( V_423 , & V_11 -> V_336 ) )
F_76 ( & V_11 -> V_17 ) ;
if ( F_13 ( & V_11 -> V_17 ) == 2 &&
F_163 ( V_443 , & V_11 -> V_336 ) &&
! F_296 ( V_11 ) &&
F_239 ( V_440 , & V_11 -> V_336 ) )
F_76 ( & V_11 -> V_17 ) ;
F_331 ( V_11 ) ;
}
void F_336 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return;
F_75 ( & V_11 -> V_340 ) ;
F_240 ( V_443 , & V_11 -> V_336 ) ;
if ( F_13 ( & V_11 -> V_17 ) == 2 && ! F_296 ( V_11 ) &&
F_239 ( V_440 , & V_11 -> V_336 ) )
F_76 ( & V_11 -> V_17 ) ;
F_331 ( V_11 ) ;
}
void F_337 ( struct V_10 * V_11 )
{
unsigned long V_139 ;
unsigned long V_200 ;
struct V_128 * V_128 ;
V_200 = F_151 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
if ( ! F_116 ( V_128 ) )
continue;
F_115 ( V_128 ) ;
F_45 ( ! F_196 ( V_128 ) ) ;
F_100 ( V_128 ) ;
F_338 ( & V_128 -> V_28 -> V_450 ) ;
if ( ! F_116 ( V_128 ) ) {
F_339 ( & V_128 -> V_28 -> V_451 ,
F_340 ( V_128 ) ,
V_368 ) ;
}
F_341 ( & V_128 -> V_28 -> V_450 ) ;
F_231 ( V_128 ) ;
F_113 ( V_128 ) ;
}
F_45 ( F_13 ( & V_11 -> V_17 ) == 0 ) ;
}
int F_342 ( struct V_10 * V_11 )
{
unsigned long V_139 ;
unsigned long V_200 ;
int V_452 = 0 ;
F_312 ( V_11 ) ;
V_452 = F_249 ( V_341 , & V_11 -> V_336 ) ;
V_200 = F_151 ( V_11 -> V_15 , V_11 -> V_21 ) ;
F_45 ( F_13 ( & V_11 -> V_17 ) == 0 ) ;
F_45 ( ! F_163 ( V_440 , & V_11 -> V_336 ) ) ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ )
F_343 ( V_11 -> V_137 [ V_139 ] ) ;
return V_452 ;
}
void F_344 ( struct V_10 * V_11 )
{
unsigned long V_139 ;
struct V_128 * V_128 ;
unsigned long V_200 ;
F_245 ( V_437 , & V_11 -> V_336 ) ;
V_200 = F_151 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
if ( V_128 )
F_172 ( V_128 ) ;
}
}
void F_308 ( struct V_10 * V_11 )
{
unsigned long V_139 ;
struct V_128 * V_128 ;
unsigned long V_200 ;
F_240 ( V_437 , & V_11 -> V_336 ) ;
V_200 = F_151 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
F_132 ( V_128 ) ;
}
}
int F_345 ( struct V_10 * V_11 )
{
return F_163 ( V_437 , & V_11 -> V_336 ) ;
}
int F_346 ( struct V_24 * V_25 ,
struct V_10 * V_11 , T_1 V_15 , int V_112 ,
T_12 * V_285 , int V_173 )
{
unsigned long V_139 ;
unsigned long V_453 ;
struct V_128 * V_128 ;
int V_99 ;
int V_37 = 0 ;
int V_454 = 0 ;
int V_455 = 1 ;
unsigned long V_200 ;
unsigned long V_456 = 0 ;
struct V_49 * V_49 = NULL ;
unsigned long V_214 = 0 ;
if ( F_163 ( V_437 , & V_11 -> V_336 ) )
return 0 ;
if ( V_15 ) {
F_45 ( V_15 < V_11 -> V_15 ) ;
V_453 = ( V_15 >> V_126 ) -
( V_11 -> V_15 >> V_126 ) ;
} else {
V_453 = 0 ;
}
V_200 = F_151 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_139 = V_453 ; V_139 < V_200 ; V_139 ++ ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
if ( V_112 == V_457 ) {
if ( ! F_243 ( V_128 ) )
goto V_458;
} else {
F_115 ( V_128 ) ;
}
V_454 ++ ;
if ( ! F_206 ( V_128 ) ) {
V_456 ++ ;
V_455 = 0 ;
}
}
if ( V_455 ) {
if ( V_453 == 0 )
F_240 ( V_437 , & V_11 -> V_336 ) ;
goto V_458;
}
F_245 ( V_459 , & V_11 -> V_336 ) ;
V_11 -> V_460 = 0 ;
F_40 ( & V_11 -> V_353 , V_456 ) ;
for ( V_139 = V_453 ; V_139 < V_200 ; V_139 ++ ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
if ( ! F_206 ( V_128 ) ) {
if ( V_37 ) {
F_76 ( & V_11 -> V_353 ) ;
F_113 ( V_128 ) ;
continue;
}
F_231 ( V_128 ) ;
V_99 = F_220 ( V_25 , V_128 ,
V_285 , & V_49 ,
V_173 , & V_214 ,
V_354 ) ;
if ( V_99 ) {
V_37 = V_99 ;
F_76 ( & V_11 -> V_353 ) ;
}
} else {
F_113 ( V_128 ) ;
}
}
if ( V_49 ) {
V_99 = F_187 ( V_49 , V_173 , V_214 ) ;
if ( V_99 )
return V_99 ;
}
if ( V_37 || V_112 != V_461 )
return V_37 ;
for ( V_139 = V_453 ; V_139 < V_200 ; V_139 ++ ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
F_347 ( V_128 ) ;
if ( ! F_206 ( V_128 ) )
V_37 = - V_152 ;
}
return V_37 ;
V_458:
V_139 = V_453 ;
while ( V_454 > 0 ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
V_139 ++ ;
F_113 ( V_128 ) ;
V_454 -- ;
}
return V_37 ;
}
void F_348 ( struct V_10 * V_11 , void * V_462 ,
unsigned long V_15 ,
unsigned long V_21 )
{
T_10 V_290 ;
T_10 V_63 ;
struct V_128 * V_128 ;
char * V_463 ;
char * V_464 = ( char * ) V_462 ;
T_10 V_465 = V_11 -> V_15 & ( ( T_1 ) V_30 - 1 ) ;
unsigned long V_139 = ( V_465 + V_15 ) >> V_126 ;
F_45 ( V_15 > V_11 -> V_21 ) ;
F_45 ( V_15 + V_21 > V_11 -> V_15 + V_11 -> V_21 ) ;
V_63 = ( V_465 + V_15 ) & ( V_30 - 1 ) ;
while ( V_21 > 0 ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
V_290 = F_126 ( V_21 , ( V_30 - V_63 ) ) ;
V_463 = F_349 ( V_128 ) ;
memcpy ( V_464 , V_463 + V_63 , V_290 ) ;
V_464 += V_290 ;
V_21 -= V_290 ;
V_63 = 0 ;
V_139 ++ ;
}
}
int F_350 ( struct V_10 * V_11 , void T_17 * V_462 ,
unsigned long V_15 ,
unsigned long V_21 )
{
T_10 V_290 ;
T_10 V_63 ;
struct V_128 * V_128 ;
char * V_463 ;
char T_17 * V_464 = ( char T_17 * ) V_462 ;
T_10 V_465 = V_11 -> V_15 & ( ( T_1 ) V_30 - 1 ) ;
unsigned long V_139 = ( V_465 + V_15 ) >> V_126 ;
int V_37 = 0 ;
F_45 ( V_15 > V_11 -> V_21 ) ;
F_45 ( V_15 + V_21 > V_11 -> V_15 + V_11 -> V_21 ) ;
V_63 = ( V_465 + V_15 ) & ( V_30 - 1 ) ;
while ( V_21 > 0 ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
V_290 = F_126 ( V_21 , ( V_30 - V_63 ) ) ;
V_463 = F_349 ( V_128 ) ;
if ( F_351 ( V_464 , V_463 + V_63 , V_290 ) ) {
V_37 = - V_466 ;
break;
}
V_464 += V_290 ;
V_21 -= V_290 ;
V_63 = 0 ;
V_139 ++ ;
}
return V_37 ;
}
int F_352 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_467 , char * * V_384 ,
unsigned long * V_468 ,
unsigned long * V_469 )
{
T_10 V_63 = V_15 & ( V_30 - 1 ) ;
char * V_463 ;
struct V_128 * V_67 ;
T_10 V_465 = V_11 -> V_15 & ( ( T_1 ) V_30 - 1 ) ;
unsigned long V_139 = ( V_465 + V_15 ) >> V_126 ;
unsigned long V_470 = ( V_465 + V_15 + V_467 - 1 ) >>
V_126 ;
if ( V_139 != V_470 )
return 1 ;
if ( V_139 == 0 ) {
V_63 = V_465 ;
* V_468 = 0 ;
} else {
V_63 = 0 ;
* V_468 = ( ( T_1 ) V_139 << V_126 ) - V_465 ;
}
if ( V_15 + V_467 > V_11 -> V_21 ) {
F_62 ( 1 , V_20 L_29
L_30 ,
V_11 -> V_15 , V_11 -> V_21 , V_15 , V_467 ) ;
return - V_402 ;
}
V_67 = V_11 -> V_137 [ V_139 ] ;
V_463 = F_349 ( V_67 ) ;
* V_384 = V_463 + V_63 ;
* V_469 = V_30 - V_63 ;
return 0 ;
}
int F_353 ( struct V_10 * V_11 , const void * V_471 ,
unsigned long V_15 ,
unsigned long V_21 )
{
T_10 V_290 ;
T_10 V_63 ;
struct V_128 * V_128 ;
char * V_463 ;
char * V_472 = ( char * ) V_471 ;
T_10 V_465 = V_11 -> V_15 & ( ( T_1 ) V_30 - 1 ) ;
unsigned long V_139 = ( V_465 + V_15 ) >> V_126 ;
int V_37 = 0 ;
F_45 ( V_15 > V_11 -> V_21 ) ;
F_45 ( V_15 + V_21 > V_11 -> V_15 + V_11 -> V_21 ) ;
V_63 = ( V_465 + V_15 ) & ( V_30 - 1 ) ;
while ( V_21 > 0 ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
V_290 = F_126 ( V_21 , ( V_30 - V_63 ) ) ;
V_463 = F_349 ( V_128 ) ;
V_37 = memcmp ( V_472 , V_463 + V_63 , V_290 ) ;
if ( V_37 )
break;
V_472 += V_290 ;
V_21 -= V_290 ;
V_63 = 0 ;
V_139 ++ ;
}
return V_37 ;
}
void F_354 ( struct V_10 * V_11 , const void * V_473 ,
unsigned long V_15 , unsigned long V_21 )
{
T_10 V_290 ;
T_10 V_63 ;
struct V_128 * V_128 ;
char * V_463 ;
char * V_436 = ( char * ) V_473 ;
T_10 V_465 = V_11 -> V_15 & ( ( T_1 ) V_30 - 1 ) ;
unsigned long V_139 = ( V_465 + V_15 ) >> V_126 ;
F_45 ( V_15 > V_11 -> V_21 ) ;
F_45 ( V_15 + V_21 > V_11 -> V_15 + V_11 -> V_21 ) ;
V_63 = ( V_465 + V_15 ) & ( V_30 - 1 ) ;
while ( V_21 > 0 ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
F_45 ( ! F_206 ( V_128 ) ) ;
V_290 = F_126 ( V_21 , V_30 - V_63 ) ;
V_463 = F_349 ( V_128 ) ;
memcpy ( V_463 + V_63 , V_436 , V_290 ) ;
V_436 += V_290 ;
V_21 -= V_290 ;
V_63 = 0 ;
V_139 ++ ;
}
}
void F_355 ( struct V_10 * V_11 , char V_474 ,
unsigned long V_15 , unsigned long V_21 )
{
T_10 V_290 ;
T_10 V_63 ;
struct V_128 * V_128 ;
char * V_463 ;
T_10 V_465 = V_11 -> V_15 & ( ( T_1 ) V_30 - 1 ) ;
unsigned long V_139 = ( V_465 + V_15 ) >> V_126 ;
F_45 ( V_15 > V_11 -> V_21 ) ;
F_45 ( V_15 + V_21 > V_11 -> V_15 + V_11 -> V_21 ) ;
V_63 = ( V_465 + V_15 ) & ( V_30 - 1 ) ;
while ( V_21 > 0 ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
F_45 ( ! F_206 ( V_128 ) ) ;
V_290 = F_126 ( V_21 , V_30 - V_63 ) ;
V_463 = F_349 ( V_128 ) ;
memset ( V_463 + V_63 , V_474 , V_290 ) ;
V_21 -= V_290 ;
V_63 = 0 ;
V_139 ++ ;
}
}
void F_306 ( struct V_10 * V_464 , struct V_10 * V_436 ,
unsigned long V_475 , unsigned long V_476 ,
unsigned long V_21 )
{
T_1 V_477 = V_464 -> V_21 ;
T_10 V_290 ;
T_10 V_63 ;
struct V_128 * V_128 ;
char * V_463 ;
T_10 V_465 = V_464 -> V_15 & ( ( T_1 ) V_30 - 1 ) ;
unsigned long V_139 = ( V_465 + V_475 ) >> V_126 ;
F_45 ( V_436 -> V_21 != V_477 ) ;
V_63 = ( V_465 + V_475 ) &
( V_30 - 1 ) ;
while ( V_21 > 0 ) {
V_128 = V_464 -> V_137 [ V_139 ] ;
F_45 ( ! F_206 ( V_128 ) ) ;
V_290 = F_126 ( V_21 , ( unsigned long ) ( V_30 - V_63 ) ) ;
V_463 = F_349 ( V_128 ) ;
F_348 ( V_436 , V_463 + V_63 , V_476 , V_290 ) ;
V_476 += V_290 ;
V_21 -= V_290 ;
V_63 = 0 ;
V_139 ++ ;
}
}
static inline void F_356 ( struct V_10 * V_11 ,
unsigned long V_15 , unsigned long V_294 ,
unsigned long * F_340 ,
T_10 * F_131 )
{
T_10 V_465 = V_11 -> V_15 & ( ( T_1 ) V_30 - 1 ) ;
T_10 V_478 = F_357 ( V_294 ) ;
T_10 V_63 ;
V_63 = V_465 + V_15 + V_478 ;
* F_340 = V_63 >> V_126 ;
* F_131 = V_63 & ( V_30 - 1 ) ;
}
int F_358 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_294 )
{
char * V_463 ;
struct V_128 * V_128 ;
unsigned long V_139 ;
T_10 V_63 ;
F_356 ( V_11 , V_15 , V_294 , & V_139 , & V_63 ) ;
V_128 = V_11 -> V_137 [ V_139 ] ;
F_45 ( ! F_206 ( V_128 ) ) ;
V_463 = F_349 ( V_128 ) ;
return 1U & ( V_463 [ V_63 ] >> ( V_294 & ( V_479 - 1 ) ) ) ;
}
void F_359 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_480 , unsigned long V_21 )
{
char * V_463 ;
struct V_128 * V_128 ;
unsigned long V_139 ;
T_10 V_63 ;
const unsigned int V_269 = V_480 + V_21 ;
int V_115 = V_479 - ( V_480 % V_479 ) ;
unsigned int V_481 = F_360 ( V_480 ) ;
F_356 ( V_11 , V_15 , V_480 , & V_139 , & V_63 ) ;
V_128 = V_11 -> V_137 [ V_139 ] ;
F_45 ( ! F_206 ( V_128 ) ) ;
V_463 = F_349 ( V_128 ) ;
while ( V_21 >= V_115 ) {
V_463 [ V_63 ] |= V_481 ;
V_21 -= V_115 ;
V_115 = V_479 ;
V_481 = ~ 0U ;
if ( ++ V_63 >= V_30 && V_21 > 0 ) {
V_63 = 0 ;
V_128 = V_11 -> V_137 [ ++ V_139 ] ;
F_45 ( ! F_206 ( V_128 ) ) ;
V_463 = F_349 ( V_128 ) ;
}
}
if ( V_21 ) {
V_481 &= F_361 ( V_269 ) ;
V_463 [ V_63 ] |= V_481 ;
}
}
void F_362 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_480 , unsigned long V_21 )
{
char * V_463 ;
struct V_128 * V_128 ;
unsigned long V_139 ;
T_10 V_63 ;
const unsigned int V_269 = V_480 + V_21 ;
int V_95 = V_479 - ( V_480 % V_479 ) ;
unsigned int V_482 = F_360 ( V_480 ) ;
F_356 ( V_11 , V_15 , V_480 , & V_139 , & V_63 ) ;
V_128 = V_11 -> V_137 [ V_139 ] ;
F_45 ( ! F_206 ( V_128 ) ) ;
V_463 = F_349 ( V_128 ) ;
while ( V_21 >= V_95 ) {
V_463 [ V_63 ] &= ~ V_482 ;
V_21 -= V_95 ;
V_95 = V_479 ;
V_482 = ~ 0U ;
if ( ++ V_63 >= V_30 && V_21 > 0 ) {
V_63 = 0 ;
V_128 = V_11 -> V_137 [ ++ V_139 ] ;
F_45 ( ! F_206 ( V_128 ) ) ;
V_463 = F_349 ( V_128 ) ;
}
}
if ( V_21 ) {
V_482 &= F_361 ( V_269 ) ;
V_463 [ V_63 ] &= ~ V_482 ;
}
}
static inline bool F_363 ( unsigned long V_436 , unsigned long V_464 , unsigned long V_21 )
{
unsigned long V_483 = ( V_436 > V_464 ) ? V_436 - V_464 : V_464 - V_436 ;
return V_483 < V_21 ;
}
static void F_364 ( struct V_128 * V_484 , struct V_128 * V_485 ,
unsigned long V_486 , unsigned long V_487 ,
unsigned long V_21 )
{
char * V_488 = F_349 ( V_484 ) ;
char * V_489 ;
int V_490 = 0 ;
if ( V_484 != V_485 ) {
V_489 = F_349 ( V_485 ) ;
} else {
V_489 = V_488 ;
if ( F_363 ( V_487 , V_486 , V_21 ) )
V_490 = 1 ;
}
if ( V_490 )
memmove ( V_488 + V_486 , V_489 + V_487 , V_21 ) ;
else
memcpy ( V_488 + V_486 , V_489 + V_487 , V_21 ) ;
}
void F_365 ( struct V_10 * V_464 , unsigned long V_475 ,
unsigned long V_476 , unsigned long V_21 )
{
T_10 V_290 ;
T_10 V_491 ;
T_10 V_492 ;
T_10 V_465 = V_464 -> V_15 & ( ( T_1 ) V_30 - 1 ) ;
unsigned long V_493 ;
unsigned long V_494 ;
if ( V_476 + V_21 > V_464 -> V_21 ) {
F_175 ( V_464 -> V_32 ,
L_31
L_32 , V_476 , V_21 , V_464 -> V_21 ) ;
F_23 ( 1 ) ;
}
if ( V_475 + V_21 > V_464 -> V_21 ) {
F_175 ( V_464 -> V_32 ,
L_33
L_32 , V_475 , V_21 , V_464 -> V_21 ) ;
F_23 ( 1 ) ;
}
while ( V_21 > 0 ) {
V_491 = ( V_465 + V_475 ) &
( V_30 - 1 ) ;
V_492 = ( V_465 + V_476 ) &
( V_30 - 1 ) ;
V_493 = ( V_465 + V_475 ) >> V_126 ;
V_494 = ( V_465 + V_476 ) >> V_126 ;
V_290 = F_126 ( V_21 , ( unsigned long ) ( V_30 -
V_492 ) ) ;
V_290 = F_112 (unsigned long, cur,
(unsigned long)(PAGE_SIZE - dst_off_in_page)) ;
F_364 ( V_464 -> V_137 [ V_493 ] , V_464 -> V_137 [ V_494 ] ,
V_491 , V_492 , V_290 ) ;
V_476 += V_290 ;
V_475 += V_290 ;
V_21 -= V_290 ;
}
}
void F_366 ( struct V_10 * V_464 , unsigned long V_475 ,
unsigned long V_476 , unsigned long V_21 )
{
T_10 V_290 ;
T_10 V_491 ;
T_10 V_492 ;
unsigned long V_495 = V_475 + V_21 - 1 ;
unsigned long V_496 = V_476 + V_21 - 1 ;
T_10 V_465 = V_464 -> V_15 & ( ( T_1 ) V_30 - 1 ) ;
unsigned long V_493 ;
unsigned long V_494 ;
if ( V_476 + V_21 > V_464 -> V_21 ) {
F_175 ( V_464 -> V_32 , L_31
L_34 , V_476 , V_21 , V_464 -> V_21 ) ;
F_23 ( 1 ) ;
}
if ( V_475 + V_21 > V_464 -> V_21 ) {
F_175 ( V_464 -> V_32 , L_33
L_34 , V_475 , V_21 , V_464 -> V_21 ) ;
F_23 ( 1 ) ;
}
if ( V_475 < V_476 ) {
F_365 ( V_464 , V_475 , V_476 , V_21 ) ;
return;
}
while ( V_21 > 0 ) {
V_493 = ( V_465 + V_495 ) >> V_126 ;
V_494 = ( V_465 + V_496 ) >> V_126 ;
V_491 = ( V_465 + V_495 ) &
( V_30 - 1 ) ;
V_492 = ( V_465 + V_496 ) &
( V_30 - 1 ) ;
V_290 = F_112 (unsigned long, len, src_off_in_page + 1 ) ;
V_290 = F_126 ( V_290 , V_491 + 1 ) ;
F_364 ( V_464 -> V_137 [ V_493 ] , V_464 -> V_137 [ V_494 ] ,
V_491 - V_290 + 1 ,
V_492 - V_290 + 1 , V_290 ) ;
V_495 -= V_290 ;
V_496 -= V_290 ;
V_21 -= V_290 ;
}
}
int F_367 ( struct V_128 * V_128 )
{
struct V_10 * V_11 ;
F_75 ( & V_128 -> V_28 -> V_371 ) ;
if ( ! F_196 ( V_128 ) ) {
F_78 ( & V_128 -> V_28 -> V_371 ) ;
return 1 ;
}
V_11 = (struct V_10 * ) V_128 -> V_203 ;
F_23 ( ! V_11 ) ;
F_75 ( & V_11 -> V_340 ) ;
if ( F_13 ( & V_11 -> V_17 ) != 1 || F_296 ( V_11 ) ) {
F_78 ( & V_11 -> V_340 ) ;
F_78 ( & V_128 -> V_28 -> V_371 ) ;
return 0 ;
}
F_78 ( & V_128 -> V_28 -> V_371 ) ;
if ( ! F_239 ( V_440 , & V_11 -> V_336 ) ) {
F_78 ( & V_11 -> V_340 ) ;
return 0 ;
}
return F_331 ( V_11 ) ;
}
