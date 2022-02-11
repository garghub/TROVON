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
V_43 | V_44 , NULL ) ;
if ( ! V_18 )
return - V_45 ;
V_22 = F_27 ( L_6 ,
sizeof( struct V_10 ) , 0 ,
V_43 | V_44 , NULL ) ;
if ( ! V_22 )
goto V_46;
V_47 = F_28 ( V_48 ,
F_29 ( struct V_49 , V_50 ) ) ;
if ( ! V_47 )
goto V_51;
if ( F_30 ( V_47 , V_48 ) )
goto V_52;
return 0 ;
V_52:
F_31 ( V_47 ) ;
V_47 = NULL ;
V_51:
F_32 ( V_22 ) ;
V_22 = NULL ;
V_46:
F_32 ( V_18 ) ;
V_18 = NULL ;
return - V_45 ;
}
void F_33 ( void )
{
F_9 () ;
F_34 () ;
if ( V_18 )
F_32 ( V_18 ) ;
if ( V_22 )
F_32 ( V_22 ) ;
if ( V_47 )
F_31 ( V_47 ) ;
}
void F_35 ( struct V_24 * V_25 ,
struct V_53 * V_28 )
{
V_25 -> V_2 = V_54 ;
V_25 -> V_55 = NULL ;
V_25 -> V_56 = 0 ;
F_36 ( & V_25 -> V_57 ) ;
V_25 -> V_28 = V_28 ;
}
static struct V_1 * F_37 ( T_3 V_58 )
{
struct V_1 * V_2 ;
V_2 = F_38 ( V_18 , V_58 ) ;
if ( ! V_2 )
return V_2 ;
V_2 -> V_2 = 0 ;
V_2 -> V_59 = 0 ;
F_39 ( & V_2 -> V_3 ) ;
F_3 ( & V_2 -> V_14 , & V_12 ) ;
F_40 ( & V_2 -> V_17 , 1 ) ;
F_41 ( & V_2 -> V_60 ) ;
F_42 ( V_2 , V_58 , V_61 ) ;
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
static struct V_3 * F_47 ( struct V_62 * V_31 ,
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
V_68 = V_63 ? & V_63 : & V_31 -> V_3 ;
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
F_50 ( V_65 , V_31 ) ;
return NULL ;
}
static struct V_3 * F_51 ( struct V_24 * V_25 , T_1 V_64 ,
struct V_3 * * V_74 ,
struct V_3 * * V_75 ,
struct V_3 * * * V_76 ,
struct V_3 * * V_77 )
{
struct V_62 * V_31 = & V_25 -> V_2 ;
struct V_3 * * V_78 = & V_31 -> V_3 ;
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
F_54 ( struct V_24 * V_25 ,
T_1 V_64 ,
struct V_3 * * * V_76 ,
struct V_3 * * V_77 )
{
struct V_3 * V_79 = NULL ;
struct V_3 * V_37 ;
V_37 = F_51 ( V_25 , V_64 , & V_79 , NULL , V_76 , V_77 ) ;
if ( ! V_37 )
return V_79 ;
return V_37 ;
}
static inline struct V_3 * F_55 ( struct V_24 * V_25 ,
T_1 V_64 )
{
return F_54 ( V_25 , V_64 , NULL , NULL ) ;
}
static void F_56 ( struct V_24 * V_25 , struct V_1 * V_5 ,
struct V_1 * V_82 )
{
if ( V_25 -> V_55 && V_25 -> V_55 -> V_83 )
V_25 -> V_55 -> V_83 ( V_25 -> V_28 -> V_29 , V_5 ,
V_82 ) ;
}
static void F_57 ( struct V_24 * V_25 ,
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
F_56 ( V_25 , V_2 , V_82 ) ;
V_2 -> V_15 = V_82 -> V_15 ;
F_58 ( & V_82 -> V_3 , & V_25 -> V_2 ) ;
F_39 ( & V_82 -> V_3 ) ;
F_43 ( V_82 ) ;
}
}
V_84 = F_52 ( & V_2 -> V_3 ) ;
if ( V_84 ) {
V_82 = F_48 ( V_84 , struct V_1 , V_3 ) ;
if ( V_82 -> V_15 == V_2 -> V_16 + 1 &&
V_82 -> V_2 == V_2 -> V_2 ) {
F_56 ( V_25 , V_2 , V_82 ) ;
V_2 -> V_16 = V_82 -> V_16 ;
F_58 ( & V_82 -> V_3 , & V_25 -> V_2 ) ;
F_39 ( & V_82 -> V_3 ) ;
F_43 ( V_82 ) ;
}
}
}
static void F_59 ( struct V_24 * V_25 ,
struct V_1 * V_2 , unsigned * V_33 )
{
if ( V_25 -> V_55 && V_25 -> V_55 -> V_87 )
V_25 -> V_55 -> V_87 ( V_25 -> V_28 -> V_29 , V_2 , V_33 ) ;
}
static void F_60 ( struct V_24 * V_25 ,
struct V_1 * V_2 , unsigned * V_33 )
{
if ( V_25 -> V_55 && V_25 -> V_55 -> V_88 )
V_25 -> V_55 -> V_88 ( V_25 -> V_28 -> V_29 , V_2 , V_33 ) ;
}
static int F_61 ( struct V_24 * V_25 ,
struct V_1 * V_2 , T_1 V_15 , T_1 V_16 ,
struct V_3 * * * V_68 ,
struct V_3 * * V_69 ,
unsigned * V_33 , struct V_34 * V_35 )
{
struct V_3 * V_65 ;
if ( V_16 < V_15 )
F_62 ( 1 , V_20 L_7 ,
V_16 , V_15 ) ;
V_2 -> V_15 = V_15 ;
V_2 -> V_16 = V_16 ;
F_63 ( V_25 , V_2 , V_33 , V_35 ) ;
V_65 = F_47 ( & V_25 -> V_2 , NULL , V_16 , & V_2 -> V_3 , V_68 , V_69 ) ;
if ( V_65 ) {
struct V_1 * V_89 ;
V_89 = F_48 ( V_65 , struct V_1 , V_3 ) ;
F_15 ( V_20 L_8
L_9 ,
V_89 -> V_15 , V_89 -> V_16 , V_15 , V_16 ) ;
return - V_90 ;
}
F_57 ( V_25 , V_2 ) ;
return 0 ;
}
static void F_64 ( struct V_24 * V_25 , struct V_1 * V_91 ,
T_1 V_92 )
{
if ( V_25 -> V_55 && V_25 -> V_55 -> V_93 )
V_25 -> V_55 -> V_93 ( V_25 -> V_28 -> V_29 , V_91 , V_92 ) ;
}
static int F_65 ( struct V_24 * V_25 , struct V_1 * V_91 ,
struct V_1 * V_94 , T_1 V_92 )
{
struct V_3 * V_65 ;
F_64 ( V_25 , V_91 , V_92 ) ;
V_94 -> V_15 = V_91 -> V_15 ;
V_94 -> V_16 = V_92 - 1 ;
V_94 -> V_2 = V_91 -> V_2 ;
V_91 -> V_15 = V_92 ;
V_65 = F_47 ( & V_25 -> V_2 , & V_91 -> V_3 , V_94 -> V_16 ,
& V_94 -> V_3 , NULL , NULL ) ;
if ( V_65 ) {
F_43 ( V_94 ) ;
return - V_90 ;
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
unsigned * V_33 , int V_95 ,
struct V_34 * V_35 )
{
struct V_1 * V_13 ;
unsigned V_96 = * V_33 & ~ V_97 ;
if ( ( V_96 & V_98 ) && ( V_2 -> V_2 & V_98 ) ) {
T_1 V_99 = V_2 -> V_16 - V_2 -> V_15 + 1 ;
F_45 ( V_99 > V_25 -> V_56 ) ;
V_25 -> V_56 -= V_99 ;
}
F_60 ( V_25 , V_2 , V_33 ) ;
F_21 ( V_2 , V_96 , V_35 , 0 ) ;
V_2 -> V_2 &= ~ V_96 ;
if ( V_95 )
F_68 ( & V_2 -> V_60 ) ;
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
F_69 ( struct V_1 * V_94 )
{
if ( ! V_94 )
V_94 = F_37 ( V_40 ) ;
return V_94 ;
}
static void F_70 ( struct V_24 * V_25 , int V_100 )
{
F_71 ( F_24 ( V_25 ) , V_100 , L_10
L_11
L_12 ) ;
}
static int F_72 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned V_33 , int V_95 , int V_101 ,
struct V_1 * * V_102 ,
T_3 V_58 , struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_1 * V_103 ;
struct V_1 * V_94 = NULL ;
struct V_3 * V_65 ;
T_1 V_104 ;
int V_100 ;
int V_105 = 0 ;
F_73 ( V_25 , V_15 , V_16 ) ;
if ( V_33 & V_106 )
V_33 |= V_107 ;
if ( V_101 )
V_33 |= ~ V_97 ;
V_33 |= V_108 ;
if ( V_33 & ( V_85 | V_86 ) )
V_105 = 1 ;
V_109:
if ( ! V_94 && F_74 ( V_58 ) ) {
V_94 = F_37 ( V_58 ) ;
}
F_75 ( & V_25 -> V_57 ) ;
if ( V_102 ) {
V_103 = * V_102 ;
if ( V_105 ) {
* V_102 = NULL ;
V_102 = NULL ;
}
if ( V_103 && F_1 ( V_103 ) &&
V_103 -> V_15 <= V_15 && V_103 -> V_16 > V_15 ) {
if ( V_105 )
F_76 ( & V_103 -> V_17 ) ;
V_2 = V_103 ;
goto V_110;
}
if ( V_105 )
F_43 ( V_103 ) ;
}
V_65 = F_55 ( V_25 , V_15 ) ;
if ( ! V_65 )
goto V_111;
V_2 = F_48 ( V_65 , struct V_1 , V_3 ) ;
V_110:
if ( V_2 -> V_15 > V_16 )
goto V_111;
F_45 ( V_2 -> V_16 < V_15 ) ;
V_104 = V_2 -> V_16 ;
if ( ! ( V_2 -> V_2 & V_33 ) ) {
V_2 = F_66 ( V_2 ) ;
goto V_13;
}
if ( V_2 -> V_15 < V_15 ) {
V_94 = F_69 ( V_94 ) ;
F_23 ( ! V_94 ) ;
V_100 = F_65 ( V_25 , V_2 , V_94 , V_15 ) ;
if ( V_100 )
F_70 ( V_25 , V_100 ) ;
V_94 = NULL ;
if ( V_100 )
goto V_111;
if ( V_2 -> V_16 <= V_16 ) {
V_2 = F_67 ( V_25 , V_2 , & V_33 , V_95 ,
V_35 ) ;
goto V_13;
}
goto V_112;
}
if ( V_2 -> V_15 <= V_16 && V_2 -> V_16 > V_16 ) {
V_94 = F_69 ( V_94 ) ;
F_23 ( ! V_94 ) ;
V_100 = F_65 ( V_25 , V_2 , V_94 , V_16 + 1 ) ;
if ( V_100 )
F_70 ( V_25 , V_100 ) ;
if ( V_95 )
F_68 ( & V_2 -> V_60 ) ;
F_67 ( V_25 , V_94 , & V_33 , V_95 , V_35 ) ;
V_94 = NULL ;
goto V_111;
}
V_2 = F_67 ( V_25 , V_2 , & V_33 , V_95 , V_35 ) ;
V_13:
if ( V_104 == ( T_1 ) - 1 )
goto V_111;
V_15 = V_104 + 1 ;
if ( V_15 <= V_16 && V_2 && ! F_77 () )
goto V_110;
goto V_112;
V_111:
F_78 ( & V_25 -> V_57 ) ;
if ( V_94 )
F_43 ( V_94 ) ;
return 0 ;
V_112:
if ( V_15 > V_16 )
goto V_111;
F_78 ( & V_25 -> V_57 ) ;
if ( F_74 ( V_58 ) )
F_79 () ;
goto V_109;
}
static void F_80 ( struct V_24 * V_25 ,
struct V_1 * V_2 )
__releases( V_25 -> V_57 )
__acquires( V_25 -> V_57 )
{
F_81 ( V_113 ) ;
F_82 ( & V_2 -> V_60 , & V_113 , V_114 ) ;
F_78 ( & V_25 -> V_57 ) ;
F_83 () ;
F_75 ( & V_25 -> V_57 ) ;
F_84 ( & V_2 -> V_60 , & V_113 ) ;
}
static void F_85 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned long V_33 )
{
struct V_1 * V_2 ;
struct V_3 * V_65 ;
F_73 ( V_25 , V_15 , V_16 ) ;
F_75 ( & V_25 -> V_57 ) ;
V_109:
while ( 1 ) {
V_65 = F_55 ( V_25 , V_15 ) ;
V_115:
if ( ! V_65 )
break;
V_2 = F_48 ( V_65 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 > V_16 )
goto V_111;
if ( V_2 -> V_2 & V_33 ) {
V_15 = V_2 -> V_15 ;
F_86 ( & V_2 -> V_17 ) ;
F_80 ( V_25 , V_2 ) ;
F_43 ( V_2 ) ;
goto V_109;
}
V_15 = V_2 -> V_16 + 1 ;
if ( V_15 > V_16 )
break;
if ( ! F_87 ( & V_25 -> V_57 ) ) {
V_65 = F_52 ( V_65 ) ;
goto V_115;
}
}
V_111:
F_78 ( & V_25 -> V_57 ) ;
}
static void F_63 ( struct V_24 * V_25 ,
struct V_1 * V_2 ,
unsigned * V_33 , struct V_34 * V_35 )
{
unsigned V_116 = * V_33 & ~ V_97 ;
F_59 ( V_25 , V_2 , V_33 ) ;
if ( ( V_116 & V_98 ) && ! ( V_2 -> V_2 & V_98 ) ) {
T_1 V_99 = V_2 -> V_16 - V_2 -> V_15 + 1 ;
V_25 -> V_56 += V_99 ;
}
F_21 ( V_2 , V_116 , V_35 , 1 ) ;
V_2 -> V_2 |= V_116 ;
}
static void F_88 ( struct V_1 * V_2 ,
struct V_1 * * V_117 ,
unsigned V_7 )
{
if ( V_117 && ! ( * V_117 ) ) {
if ( ! V_7 || ( V_2 -> V_2 & V_7 ) ) {
* V_117 = V_2 ;
F_86 ( & V_2 -> V_17 ) ;
}
}
}
static void F_89 ( struct V_1 * V_2 ,
struct V_1 * * V_117 )
{
return F_88 ( V_2 , V_117 ,
V_85 | V_86 ) ;
}
static int T_4
F_90 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned V_33 , unsigned V_118 ,
T_1 * V_119 , struct V_1 * * V_102 ,
T_3 V_58 , struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_1 * V_94 = NULL ;
struct V_3 * V_65 ;
struct V_3 * * V_68 ;
struct V_3 * V_69 ;
int V_100 = 0 ;
T_1 V_120 ;
T_1 V_104 ;
F_73 ( V_25 , V_15 , V_16 ) ;
V_33 |= V_108 ;
V_109:
if ( ! V_94 && F_74 ( V_58 ) ) {
V_94 = F_37 ( V_58 ) ;
F_23 ( ! V_94 ) ;
}
F_75 ( & V_25 -> V_57 ) ;
if ( V_102 && * V_102 ) {
V_2 = * V_102 ;
if ( V_2 -> V_15 <= V_15 && V_2 -> V_16 > V_15 &&
F_1 ( V_2 ) ) {
V_65 = & V_2 -> V_3 ;
goto V_110;
}
}
V_65 = F_54 ( V_25 , V_15 , & V_68 , & V_69 ) ;
if ( ! V_65 ) {
V_94 = F_69 ( V_94 ) ;
F_23 ( ! V_94 ) ;
V_100 = F_61 ( V_25 , V_94 , V_15 , V_16 ,
& V_68 , & V_69 , & V_33 , V_35 ) ;
if ( V_100 )
F_70 ( V_25 , V_100 ) ;
F_89 ( V_94 , V_102 ) ;
V_94 = NULL ;
goto V_111;
}
V_2 = F_48 ( V_65 , struct V_1 , V_3 ) ;
V_110:
V_120 = V_2 -> V_15 ;
V_104 = V_2 -> V_16 ;
if ( V_2 -> V_15 == V_15 && V_2 -> V_16 <= V_16 ) {
if ( V_2 -> V_2 & V_118 ) {
* V_119 = V_2 -> V_15 ;
V_100 = - V_90 ;
goto V_111;
}
F_63 ( V_25 , V_2 , & V_33 , V_35 ) ;
F_89 ( V_2 , V_102 ) ;
F_57 ( V_25 , V_2 ) ;
if ( V_104 == ( T_1 ) - 1 )
goto V_111;
V_15 = V_104 + 1 ;
V_2 = F_66 ( V_2 ) ;
if ( V_15 < V_16 && V_2 && V_2 -> V_15 == V_15 &&
! F_77 () )
goto V_110;
goto V_112;
}
if ( V_2 -> V_15 < V_15 ) {
if ( V_2 -> V_2 & V_118 ) {
* V_119 = V_15 ;
V_100 = - V_90 ;
goto V_111;
}
V_94 = F_69 ( V_94 ) ;
F_23 ( ! V_94 ) ;
V_100 = F_65 ( V_25 , V_2 , V_94 , V_15 ) ;
if ( V_100 )
F_70 ( V_25 , V_100 ) ;
V_94 = NULL ;
if ( V_100 )
goto V_111;
if ( V_2 -> V_16 <= V_16 ) {
F_63 ( V_25 , V_2 , & V_33 , V_35 ) ;
F_89 ( V_2 , V_102 ) ;
F_57 ( V_25 , V_2 ) ;
if ( V_104 == ( T_1 ) - 1 )
goto V_111;
V_15 = V_104 + 1 ;
V_2 = F_66 ( V_2 ) ;
if ( V_15 < V_16 && V_2 && V_2 -> V_15 == V_15 &&
! F_77 () )
goto V_110;
}
goto V_112;
}
if ( V_2 -> V_15 > V_15 ) {
T_1 V_121 ;
if ( V_16 < V_120 )
V_121 = V_16 ;
else
V_121 = V_120 - 1 ;
V_94 = F_69 ( V_94 ) ;
F_23 ( ! V_94 ) ;
V_100 = F_61 ( V_25 , V_94 , V_15 , V_121 ,
NULL , NULL , & V_33 , V_35 ) ;
if ( V_100 )
F_70 ( V_25 , V_100 ) ;
F_89 ( V_94 , V_102 ) ;
V_94 = NULL ;
V_15 = V_121 + 1 ;
goto V_112;
}
if ( V_2 -> V_15 <= V_16 && V_2 -> V_16 > V_16 ) {
if ( V_2 -> V_2 & V_118 ) {
* V_119 = V_15 ;
V_100 = - V_90 ;
goto V_111;
}
V_94 = F_69 ( V_94 ) ;
F_23 ( ! V_94 ) ;
V_100 = F_65 ( V_25 , V_2 , V_94 , V_16 + 1 ) ;
if ( V_100 )
F_70 ( V_25 , V_100 ) ;
F_63 ( V_25 , V_94 , & V_33 , V_35 ) ;
F_89 ( V_94 , V_102 ) ;
F_57 ( V_25 , V_94 ) ;
V_94 = NULL ;
goto V_111;
}
goto V_112;
V_111:
F_78 ( & V_25 -> V_57 ) ;
if ( V_94 )
F_43 ( V_94 ) ;
return V_100 ;
V_112:
if ( V_15 > V_16 )
goto V_111;
F_78 ( & V_25 -> V_57 ) ;
if ( F_74 ( V_58 ) )
F_79 () ;
goto V_109;
}
int F_91 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned V_33 , T_1 * V_119 ,
struct V_1 * * V_102 , T_3 V_58 )
{
return F_90 ( V_25 , V_15 , V_16 , V_33 , 0 , V_119 ,
V_102 , V_58 , NULL ) ;
}
int F_92 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned V_33 , unsigned V_122 ,
struct V_1 * * V_102 , T_3 V_58 )
{
struct V_1 * V_2 ;
struct V_1 * V_94 = NULL ;
struct V_3 * V_65 ;
struct V_3 * * V_68 ;
struct V_3 * V_69 ;
int V_100 = 0 ;
T_1 V_120 ;
T_1 V_104 ;
bool V_123 = true ;
F_73 ( V_25 , V_15 , V_16 ) ;
V_109:
if ( ! V_94 && F_74 ( V_58 ) ) {
V_94 = F_37 ( V_58 ) ;
if ( ! V_94 && ! V_123 )
return - V_45 ;
}
F_75 ( & V_25 -> V_57 ) ;
if ( V_102 && * V_102 ) {
V_2 = * V_102 ;
if ( V_2 -> V_15 <= V_15 && V_2 -> V_16 > V_15 &&
F_1 ( V_2 ) ) {
V_65 = & V_2 -> V_3 ;
goto V_110;
}
}
V_65 = F_54 ( V_25 , V_15 , & V_68 , & V_69 ) ;
if ( ! V_65 ) {
V_94 = F_69 ( V_94 ) ;
if ( ! V_94 ) {
V_100 = - V_45 ;
goto V_111;
}
V_100 = F_61 ( V_25 , V_94 , V_15 , V_16 ,
& V_68 , & V_69 , & V_33 , NULL ) ;
if ( V_100 )
F_70 ( V_25 , V_100 ) ;
F_89 ( V_94 , V_102 ) ;
V_94 = NULL ;
goto V_111;
}
V_2 = F_48 ( V_65 , struct V_1 , V_3 ) ;
V_110:
V_120 = V_2 -> V_15 ;
V_104 = V_2 -> V_16 ;
if ( V_2 -> V_15 == V_15 && V_2 -> V_16 <= V_16 ) {
F_63 ( V_25 , V_2 , & V_33 , NULL ) ;
F_89 ( V_2 , V_102 ) ;
V_2 = F_67 ( V_25 , V_2 , & V_122 , 0 , NULL ) ;
if ( V_104 == ( T_1 ) - 1 )
goto V_111;
V_15 = V_104 + 1 ;
if ( V_15 < V_16 && V_2 && V_2 -> V_15 == V_15 &&
! F_77 () )
goto V_110;
goto V_112;
}
if ( V_2 -> V_15 < V_15 ) {
V_94 = F_69 ( V_94 ) ;
if ( ! V_94 ) {
V_100 = - V_45 ;
goto V_111;
}
V_100 = F_65 ( V_25 , V_2 , V_94 , V_15 ) ;
if ( V_100 )
F_70 ( V_25 , V_100 ) ;
V_94 = NULL ;
if ( V_100 )
goto V_111;
if ( V_2 -> V_16 <= V_16 ) {
F_63 ( V_25 , V_2 , & V_33 , NULL ) ;
F_89 ( V_2 , V_102 ) ;
V_2 = F_67 ( V_25 , V_2 , & V_122 , 0 ,
NULL ) ;
if ( V_104 == ( T_1 ) - 1 )
goto V_111;
V_15 = V_104 + 1 ;
if ( V_15 < V_16 && V_2 && V_2 -> V_15 == V_15 &&
! F_77 () )
goto V_110;
}
goto V_112;
}
if ( V_2 -> V_15 > V_15 ) {
T_1 V_121 ;
if ( V_16 < V_120 )
V_121 = V_16 ;
else
V_121 = V_120 - 1 ;
V_94 = F_69 ( V_94 ) ;
if ( ! V_94 ) {
V_100 = - V_45 ;
goto V_111;
}
V_100 = F_61 ( V_25 , V_94 , V_15 , V_121 ,
NULL , NULL , & V_33 , NULL ) ;
if ( V_100 )
F_70 ( V_25 , V_100 ) ;
F_89 ( V_94 , V_102 ) ;
V_94 = NULL ;
V_15 = V_121 + 1 ;
goto V_112;
}
if ( V_2 -> V_15 <= V_16 && V_2 -> V_16 > V_16 ) {
V_94 = F_69 ( V_94 ) ;
if ( ! V_94 ) {
V_100 = - V_45 ;
goto V_111;
}
V_100 = F_65 ( V_25 , V_2 , V_94 , V_16 + 1 ) ;
if ( V_100 )
F_70 ( V_25 , V_100 ) ;
F_63 ( V_25 , V_94 , & V_33 , NULL ) ;
F_89 ( V_94 , V_102 ) ;
F_67 ( V_25 , V_94 , & V_122 , 0 , NULL ) ;
V_94 = NULL ;
goto V_111;
}
goto V_112;
V_111:
F_78 ( & V_25 -> V_57 ) ;
if ( V_94 )
F_43 ( V_94 ) ;
return V_100 ;
V_112:
if ( V_15 > V_16 )
goto V_111;
F_78 ( & V_25 -> V_57 ) ;
if ( F_74 ( V_58 ) )
F_79 () ;
V_123 = false ;
goto V_109;
}
int F_93 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
T_3 V_58 )
{
return F_91 ( V_25 , V_15 , V_16 , V_98 , NULL ,
NULL , V_58 ) ;
}
int F_94 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned V_33 , T_3 V_58 )
{
return F_91 ( V_25 , V_15 , V_16 , V_33 , NULL ,
NULL , V_58 ) ;
}
int F_95 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned V_33 , T_3 V_58 ,
struct V_34 * V_35 )
{
F_23 ( V_33 & V_124 ) ;
return F_90 ( V_25 , V_15 , V_16 , V_33 , 0 , NULL , NULL , V_58 ,
V_35 ) ;
}
int F_96 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned V_33 , int V_95 , int V_101 ,
struct V_1 * * V_103 , T_3 V_58 )
{
return F_72 ( V_25 , V_15 , V_16 , V_33 , V_95 , V_101 ,
V_103 , V_58 , NULL ) ;
}
int F_97 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned V_33 , T_3 V_58 )
{
int V_95 = 0 ;
if ( V_33 & V_124 )
V_95 = 1 ;
return F_96 ( V_25 , V_15 , V_16 , V_33 , V_95 , 0 , NULL , V_58 ) ;
}
int F_98 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned V_33 , T_3 V_58 ,
struct V_34 * V_35 )
{
F_23 ( V_33 & V_124 ) ;
return F_72 ( V_25 , V_15 , V_16 , V_33 , 0 , 0 , NULL , V_58 ,
V_35 ) ;
}
int F_99 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
struct V_1 * * V_102 , T_3 V_58 )
{
return F_91 ( V_25 , V_15 , V_16 ,
V_106 | V_125 ,
NULL , V_102 , V_58 ) ;
}
int F_100 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
struct V_1 * * V_102 , T_3 V_58 )
{
return F_91 ( V_25 , V_15 , V_16 ,
V_106 | V_125 | V_126 ,
NULL , V_102 , V_58 ) ;
}
int F_101 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
T_3 V_58 )
{
return F_96 ( V_25 , V_15 , V_16 ,
V_98 | V_106 |
V_127 , 0 , 0 , NULL , V_58 ) ;
}
int F_102 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
T_3 V_58 )
{
return F_91 ( V_25 , V_15 , V_16 , V_128 , NULL ,
NULL , V_58 ) ;
}
int F_103 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
struct V_1 * * V_102 , T_3 V_58 )
{
return F_91 ( V_25 , V_15 , V_16 , V_125 , NULL ,
V_102 , V_58 ) ;
}
int F_104 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
struct V_1 * * V_102 , T_3 V_58 )
{
return F_96 ( V_25 , V_15 , V_16 , V_125 , 0 , 0 ,
V_102 , V_58 ) ;
}
int F_105 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned V_33 , struct V_1 * * V_102 )
{
int V_100 ;
T_1 V_119 ;
while ( 1 ) {
V_100 = F_90 ( V_25 , V_15 , V_16 , V_124 | V_33 ,
V_124 , & V_119 ,
V_102 , V_129 , NULL ) ;
if ( V_100 == - V_90 ) {
F_85 ( V_25 , V_119 , V_16 , V_124 ) ;
V_15 = V_119 ;
} else
break;
F_45 ( V_15 > V_16 ) ;
}
return V_100 ;
}
int F_106 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 )
{
return F_105 ( V_25 , V_15 , V_16 , 0 , NULL ) ;
}
int F_107 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 )
{
int V_100 ;
T_1 V_119 ;
V_100 = F_90 ( V_25 , V_15 , V_16 , V_124 , V_124 ,
& V_119 , NULL , V_129 , NULL ) ;
if ( V_100 == - V_90 ) {
if ( V_119 > V_15 )
F_96 ( V_25 , V_15 , V_119 - 1 ,
V_124 , 1 , 0 , NULL , V_129 ) ;
return 0 ;
}
return 1 ;
}
int F_108 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
struct V_1 * * V_103 , T_3 V_58 )
{
return F_96 ( V_25 , V_15 , V_16 , V_124 , 1 , 0 , V_103 ,
V_58 ) ;
}
int F_109 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 )
{
return F_96 ( V_25 , V_15 , V_16 , V_124 , 1 , 0 , NULL ,
V_129 ) ;
}
int F_110 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_130 = V_15 >> V_131 ;
unsigned long V_132 = V_16 >> V_131 ;
struct V_133 * V_133 ;
while ( V_130 <= V_132 ) {
V_133 = F_111 ( V_26 -> V_134 , V_130 ) ;
F_23 ( ! V_133 ) ;
F_112 ( V_133 ) ;
F_113 ( V_133 ) ;
V_130 ++ ;
}
return 0 ;
}
int F_114 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_130 = V_15 >> V_131 ;
unsigned long V_132 = V_16 >> V_131 ;
struct V_133 * V_133 ;
while ( V_130 <= V_132 ) {
V_133 = F_111 ( V_26 -> V_134 , V_130 ) ;
F_23 ( ! V_133 ) ;
F_115 ( V_133 ) ;
F_116 ( V_133 ) ;
F_113 ( V_133 ) ;
V_130 ++ ;
}
return 0 ;
}
static int F_117 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_130 = V_15 >> V_131 ;
unsigned long V_132 = V_16 >> V_131 ;
struct V_133 * V_133 ;
while ( V_130 <= V_132 ) {
V_133 = F_111 ( V_25 -> V_28 , V_130 ) ;
F_23 ( ! V_133 ) ;
F_118 ( V_133 ) ;
F_113 ( V_133 ) ;
V_130 ++ ;
}
return 0 ;
}
static struct V_1 *
F_119 ( struct V_24 * V_25 ,
T_1 V_15 , unsigned V_33 )
{
struct V_3 * V_65 ;
struct V_1 * V_2 ;
V_65 = F_55 ( V_25 , V_15 ) ;
if ( ! V_65 )
goto V_111;
while ( 1 ) {
V_2 = F_48 ( V_65 , struct V_1 , V_3 ) ;
if ( V_2 -> V_16 >= V_15 && ( V_2 -> V_2 & V_33 ) )
return V_2 ;
V_65 = F_52 ( V_65 ) ;
if ( ! V_65 )
break;
}
V_111:
return NULL ;
}
int F_120 ( struct V_24 * V_25 , T_1 V_15 ,
T_1 * V_135 , T_1 * V_136 , unsigned V_33 ,
struct V_1 * * V_102 )
{
struct V_1 * V_2 ;
struct V_3 * V_78 ;
int V_37 = 1 ;
F_75 ( & V_25 -> V_57 ) ;
if ( V_102 && * V_102 ) {
V_2 = * V_102 ;
if ( V_2 -> V_16 == V_15 - 1 && F_1 ( V_2 ) ) {
V_78 = F_52 ( & V_2 -> V_3 ) ;
while ( V_78 ) {
V_2 = F_48 ( V_78 , struct V_1 ,
V_3 ) ;
if ( V_2 -> V_2 & V_33 )
goto V_137;
V_78 = F_52 ( V_78 ) ;
}
F_43 ( * V_102 ) ;
* V_102 = NULL ;
goto V_111;
}
F_43 ( * V_102 ) ;
* V_102 = NULL ;
}
V_2 = F_119 ( V_25 , V_15 , V_33 ) ;
V_137:
if ( V_2 ) {
F_88 ( V_2 , V_102 , 0 ) ;
* V_135 = V_2 -> V_15 ;
* V_136 = V_2 -> V_16 ;
V_37 = 0 ;
}
V_111:
F_78 ( & V_25 -> V_57 ) ;
return V_37 ;
}
static T_5 T_1 F_121 ( struct V_24 * V_25 ,
T_1 * V_15 , T_1 * V_16 , T_1 V_138 ,
struct V_1 * * V_102 )
{
struct V_3 * V_65 ;
struct V_1 * V_2 ;
T_1 V_139 = * V_15 ;
T_1 V_89 = 0 ;
T_1 V_140 = 0 ;
F_75 ( & V_25 -> V_57 ) ;
V_65 = F_55 ( V_25 , V_139 ) ;
if ( ! V_65 ) {
if ( ! V_89 )
* V_16 = ( T_1 ) - 1 ;
goto V_111;
}
while ( 1 ) {
V_2 = F_48 ( V_65 , struct V_1 , V_3 ) ;
if ( V_89 && ( V_2 -> V_15 != V_139 ||
( V_2 -> V_2 & V_86 ) ) ) {
goto V_111;
}
if ( ! ( V_2 -> V_2 & V_106 ) ) {
if ( ! V_89 )
* V_16 = V_2 -> V_16 ;
goto V_111;
}
if ( ! V_89 ) {
* V_15 = V_2 -> V_15 ;
* V_102 = V_2 ;
F_86 ( & V_2 -> V_17 ) ;
}
V_89 ++ ;
* V_16 = V_2 -> V_16 ;
V_139 = V_2 -> V_16 + 1 ;
V_65 = F_52 ( V_65 ) ;
V_140 += V_2 -> V_16 - V_2 -> V_15 + 1 ;
if ( V_140 >= V_138 )
break;
if ( ! V_65 )
break;
}
V_111:
F_78 ( & V_25 -> V_57 ) ;
return V_89 ;
}
static T_5 void F_122 ( struct V_26 * V_26 ,
struct V_133 * V_141 ,
T_1 V_15 , T_1 V_16 )
{
int V_37 ;
struct V_133 * V_142 [ 16 ] ;
unsigned long V_130 = V_15 >> V_131 ;
unsigned long V_132 = V_16 >> V_131 ;
unsigned long V_143 = V_132 - V_130 + 1 ;
int V_144 ;
if ( V_130 == V_141 -> V_130 && V_132 == V_130 )
return;
while ( V_143 > 0 ) {
V_37 = F_123 ( V_26 -> V_134 , V_130 ,
F_124 (unsigned long, nr_pages,
ARRAY_SIZE(pages)) , V_142 ) ;
for ( V_144 = 0 ; V_144 < V_37 ; V_144 ++ ) {
if ( V_142 [ V_144 ] != V_141 )
F_125 ( V_142 [ V_144 ] ) ;
F_113 ( V_142 [ V_144 ] ) ;
}
V_143 -= V_37 ;
V_130 += V_37 ;
F_79 () ;
}
}
static T_5 int F_126 ( struct V_26 * V_26 ,
struct V_133 * V_141 ,
T_1 V_145 ,
T_1 V_146 )
{
unsigned long V_130 = V_145 >> V_131 ;
unsigned long V_147 = V_130 ;
unsigned long V_132 = V_146 >> V_131 ;
unsigned long V_148 = 0 ;
struct V_133 * V_142 [ 16 ] ;
unsigned long V_149 ;
int V_37 ;
int V_144 ;
if ( V_130 == V_141 -> V_130 && V_130 == V_132 )
return 0 ;
V_149 = V_132 - V_130 + 1 ;
while ( V_149 > 0 ) {
V_37 = F_123 ( V_26 -> V_134 , V_130 ,
F_124 (unsigned long,
nrpages, ARRAY_SIZE(pages)) , V_142 ) ;
if ( V_37 == 0 ) {
V_37 = - V_150 ;
goto V_151;
}
for ( V_144 = 0 ; V_144 < V_37 ; V_144 ++ ) {
if ( V_142 [ V_144 ] != V_141 ) {
F_127 ( V_142 [ V_144 ] ) ;
if ( ! F_128 ( V_142 [ V_144 ] ) ||
V_142 [ V_144 ] -> V_28 != V_26 -> V_134 ) {
V_37 = - V_150 ;
F_125 ( V_142 [ V_144 ] ) ;
F_113 ( V_142 [ V_144 ] ) ;
goto V_151;
}
}
F_113 ( V_142 [ V_144 ] ) ;
V_148 ++ ;
}
V_149 -= V_37 ;
V_130 += V_37 ;
F_79 () ;
}
V_37 = 0 ;
V_151:
if ( V_37 && V_148 ) {
F_122 ( V_26 , V_141 ,
V_145 ,
( ( T_1 ) ( V_147 + V_148 - 1 ) ) <<
V_131 ) ;
}
return V_37 ;
}
STATIC T_1 F_129 ( struct V_26 * V_26 ,
struct V_24 * V_25 ,
struct V_133 * V_141 , T_1 * V_15 ,
T_1 * V_16 , T_1 V_138 )
{
T_1 V_145 ;
T_1 V_146 ;
T_1 V_89 ;
struct V_1 * V_102 = NULL ;
int V_37 ;
int V_152 = 0 ;
V_109:
V_145 = * V_15 ;
V_146 = 0 ;
V_89 = F_121 ( V_25 , & V_145 , & V_146 ,
V_138 , & V_102 ) ;
if ( ! V_89 || V_146 <= * V_15 ) {
* V_15 = V_145 ;
* V_16 = V_146 ;
F_43 ( V_102 ) ;
return 0 ;
}
if ( V_145 < * V_15 )
V_145 = * V_15 ;
if ( V_146 + 1 - V_145 > V_138 )
V_146 = V_145 + V_138 - 1 ;
V_37 = F_126 ( V_26 , V_141 ,
V_145 , V_146 ) ;
if ( V_37 == - V_150 ) {
F_43 ( V_102 ) ;
V_102 = NULL ;
if ( ! V_152 ) {
V_138 = V_153 ;
V_152 = 1 ;
goto V_109;
} else {
V_89 = 0 ;
goto V_154;
}
}
F_23 ( V_37 ) ;
F_105 ( V_25 , V_145 , V_146 , 0 , & V_102 ) ;
V_37 = F_130 ( V_25 , V_145 , V_146 ,
V_106 , 1 , V_102 ) ;
if ( ! V_37 ) {
F_108 ( V_25 , V_145 , V_146 ,
& V_102 , V_129 ) ;
F_122 ( V_26 , V_141 ,
V_145 , V_146 ) ;
F_79 () ;
goto V_109;
}
F_43 ( V_102 ) ;
* V_15 = V_145 ;
* V_16 = V_146 ;
V_154:
return V_89 ;
}
int F_131 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_16 ,
struct V_133 * V_141 ,
unsigned V_122 ,
unsigned long V_155 )
{
struct V_24 * V_25 = & F_19 ( V_26 ) -> V_156 ;
int V_37 ;
struct V_133 * V_142 [ 16 ] ;
unsigned long V_130 = V_15 >> V_131 ;
unsigned long V_132 = V_16 >> V_131 ;
unsigned long V_143 = V_132 - V_130 + 1 ;
int V_144 ;
F_96 ( V_25 , V_15 , V_16 , V_122 , 1 , 0 , NULL , V_129 ) ;
if ( V_155 == 0 )
return 0 ;
if ( ( V_155 & V_157 ) && V_143 > 0 )
F_132 ( V_26 -> V_134 , - V_158 ) ;
while ( V_143 > 0 ) {
V_37 = F_123 ( V_26 -> V_134 , V_130 ,
F_124 (unsigned long,
nr_pages, ARRAY_SIZE(pages)) , V_142 ) ;
for ( V_144 = 0 ; V_144 < V_37 ; V_144 ++ ) {
if ( V_155 & V_159 )
F_133 ( V_142 [ V_144 ] ) ;
if ( V_142 [ V_144 ] == V_141 ) {
F_113 ( V_142 [ V_144 ] ) ;
continue;
}
if ( V_155 & V_160 )
F_112 ( V_142 [ V_144 ] ) ;
if ( V_155 & V_161 )
F_118 ( V_142 [ V_144 ] ) ;
if ( V_155 & V_157 )
F_134 ( V_142 [ V_144 ] ) ;
if ( V_155 & V_162 )
F_135 ( V_142 [ V_144 ] ) ;
if ( V_155 & V_163 )
F_125 ( V_142 [ V_144 ] ) ;
F_113 ( V_142 [ V_144 ] ) ;
}
V_143 -= V_37 ;
V_130 += V_37 ;
F_79 () ;
}
return 0 ;
}
T_1 F_136 ( struct V_24 * V_25 ,
T_1 * V_15 , T_1 V_164 , T_1 V_138 ,
unsigned V_33 , int V_165 )
{
struct V_3 * V_65 ;
struct V_1 * V_2 ;
T_1 V_139 = * V_15 ;
T_1 V_140 = 0 ;
T_1 V_166 = 0 ;
int V_89 = 0 ;
if ( F_45 ( V_164 <= V_139 ) )
return 0 ;
F_75 ( & V_25 -> V_57 ) ;
if ( V_139 == 0 && V_33 == V_98 ) {
V_140 = V_25 -> V_56 ;
goto V_111;
}
V_65 = F_55 ( V_25 , V_139 ) ;
if ( ! V_65 )
goto V_111;
while ( 1 ) {
V_2 = F_48 ( V_65 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 > V_164 )
break;
if ( V_165 && V_89 && V_2 -> V_15 > V_166 + 1 )
break;
if ( V_2 -> V_16 >= V_139 && ( V_2 -> V_2 & V_33 ) == V_33 ) {
V_140 += F_137 ( V_164 , V_2 -> V_16 ) + 1 -
F_138 ( V_139 , V_2 -> V_15 ) ;
if ( V_140 >= V_138 )
break;
if ( ! V_89 ) {
* V_15 = F_138 ( V_139 , V_2 -> V_15 ) ;
V_89 = 1 ;
}
V_166 = V_2 -> V_16 ;
} else if ( V_165 && V_89 ) {
break;
}
V_65 = F_52 ( V_65 ) ;
if ( ! V_65 )
break;
}
V_111:
F_78 ( & V_25 -> V_57 ) ;
return V_140 ;
}
static int F_139 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_59 )
{
struct V_3 * V_65 ;
struct V_1 * V_2 ;
int V_37 = 0 ;
F_75 ( & V_25 -> V_57 ) ;
V_65 = F_55 ( V_25 , V_15 ) ;
if ( ! V_65 ) {
V_37 = - V_167 ;
goto V_111;
}
V_2 = F_48 ( V_65 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 != V_15 ) {
V_37 = - V_167 ;
goto V_111;
}
V_2 -> V_59 = V_59 ;
V_111:
F_78 ( & V_25 -> V_57 ) ;
return V_37 ;
}
int F_140 ( struct V_24 * V_25 , T_1 V_15 , T_1 * V_59 )
{
struct V_3 * V_65 ;
struct V_1 * V_2 ;
int V_37 = 0 ;
F_75 ( & V_25 -> V_57 ) ;
V_65 = F_55 ( V_25 , V_15 ) ;
if ( ! V_65 ) {
V_37 = - V_167 ;
goto V_111;
}
V_2 = F_48 ( V_65 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 != V_15 ) {
V_37 = - V_167 ;
goto V_111;
}
* V_59 = V_2 -> V_59 ;
V_111:
F_78 ( & V_25 -> V_57 ) ;
return V_37 ;
}
int F_130 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned V_33 , int V_168 , struct V_1 * V_103 )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_65 ;
int V_169 = 0 ;
F_75 ( & V_25 -> V_57 ) ;
if ( V_103 && F_1 ( V_103 ) && V_103 -> V_15 <= V_15 &&
V_103 -> V_16 > V_15 )
V_65 = & V_103 -> V_3 ;
else
V_65 = F_55 ( V_25 , V_15 ) ;
while ( V_65 && V_15 <= V_16 ) {
V_2 = F_48 ( V_65 , struct V_1 , V_3 ) ;
if ( V_168 && V_2 -> V_15 > V_15 ) {
V_169 = 0 ;
break;
}
if ( V_2 -> V_15 > V_16 )
break;
if ( V_2 -> V_2 & V_33 ) {
V_169 = 1 ;
if ( ! V_168 )
break;
} else if ( V_168 ) {
V_169 = 0 ;
break;
}
if ( V_2 -> V_16 == ( T_1 ) - 1 )
break;
V_15 = V_2 -> V_16 + 1 ;
if ( V_15 > V_16 )
break;
V_65 = F_52 ( V_65 ) ;
if ( ! V_65 ) {
if ( V_168 )
V_169 = 0 ;
break;
}
}
F_78 ( & V_25 -> V_57 ) ;
return V_169 ;
}
static void F_141 ( struct V_24 * V_25 , struct V_133 * V_133 )
{
T_1 V_15 = F_142 ( V_133 ) ;
T_1 V_16 = V_15 + V_153 - 1 ;
if ( F_130 ( V_25 , V_15 , V_16 , V_125 , 1 , NULL ) )
F_143 ( V_133 ) ;
}
int F_144 ( struct V_26 * V_26 , struct V_170 * V_171 )
{
int V_37 ;
int V_100 = 0 ;
struct V_24 * V_172 = & F_19 ( V_26 ) -> V_173 ;
F_139 ( V_172 , V_171 -> V_15 , 0 ) ;
V_37 = F_97 ( V_172 , V_171 -> V_15 ,
V_171 -> V_15 + V_171 -> V_21 - 1 ,
V_124 | V_98 , V_129 ) ;
if ( V_37 )
V_100 = V_37 ;
V_37 = F_97 ( & F_19 ( V_26 ) -> V_156 , V_171 -> V_15 ,
V_171 -> V_15 + V_171 -> V_21 - 1 ,
V_174 , V_129 ) ;
if ( V_37 && ! V_100 )
V_100 = V_37 ;
F_145 ( V_171 ) ;
return V_100 ;
}
int F_146 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_175 , T_1 V_176 ,
struct V_133 * V_133 , unsigned int V_177 , int V_178 )
{
struct V_41 * V_32 = F_19 ( V_26 ) -> V_31 -> V_32 ;
struct V_50 * V_50 ;
struct V_179 * V_180 ;
T_1 V_181 = 0 ;
T_1 V_182 ;
struct V_183 * V_184 = NULL ;
struct V_185 * V_186 = & V_32 -> V_187 ;
int V_37 ;
ASSERT ( ! ( V_32 -> V_188 -> V_189 & V_190 ) ) ;
F_23 ( ! V_178 ) ;
if ( F_147 ( V_186 , V_176 , V_175 , V_178 ) )
return 0 ;
V_50 = F_148 ( V_129 , 1 ) ;
if ( ! V_50 )
return - V_158 ;
V_50 -> V_191 . V_192 = 0 ;
V_181 = V_175 ;
V_37 = F_149 ( V_32 , V_193 , V_176 ,
& V_181 , & V_184 , V_178 ) ;
if ( V_37 ) {
F_150 ( V_50 ) ;
return - V_158 ;
}
F_23 ( V_178 != V_184 -> V_178 ) ;
V_182 = V_184 -> V_194 [ V_178 - 1 ] . V_195 >> 9 ;
V_50 -> V_191 . V_196 = V_182 ;
V_180 = V_184 -> V_194 [ V_178 - 1 ] . V_180 ;
F_151 ( V_184 ) ;
if ( ! V_180 || ! V_180 -> V_197 || ! V_180 -> V_198 ) {
F_150 ( V_50 ) ;
return - V_158 ;
}
V_50 -> V_199 = V_180 -> V_197 ;
F_152 ( V_50 , V_133 , V_175 , V_177 ) ;
if ( F_153 ( V_200 , V_50 ) ) {
F_150 ( V_50 ) ;
F_154 ( V_180 , V_201 ) ;
return - V_158 ;
}
F_155 ( V_32 ,
L_13 ,
F_20 ( V_26 ) , V_15 ,
F_156 ( V_180 -> V_202 ) , V_182 ) ;
F_150 ( V_50 ) ;
return 0 ;
}
int F_157 ( struct V_203 * V_31 , struct V_10 * V_11 ,
int V_178 )
{
T_1 V_15 = V_11 -> V_15 ;
unsigned long V_144 , V_204 = F_158 ( V_11 -> V_15 , V_11 -> V_21 ) ;
int V_37 = 0 ;
if ( V_31 -> V_32 -> V_188 -> V_189 & V_190 )
return - V_205 ;
for ( V_144 = 0 ; V_144 < V_204 ; V_144 ++ ) {
struct V_133 * V_68 = V_11 -> V_142 [ V_144 ] ;
V_37 = F_146 ( V_31 -> V_32 -> V_206 , V_15 ,
V_153 , V_15 , V_68 ,
V_15 - F_142 ( V_68 ) , V_178 ) ;
if ( V_37 )
break;
V_15 += V_153 ;
}
return V_37 ;
}
int F_159 ( struct V_26 * V_26 , T_1 V_15 , struct V_133 * V_133 ,
unsigned int V_177 )
{
T_1 V_59 ;
T_1 V_207 ;
struct V_170 * V_208 ;
struct V_41 * V_32 = F_19 ( V_26 ) -> V_31 -> V_32 ;
struct V_1 * V_2 ;
int V_209 ;
int V_37 ;
V_59 = 0 ;
V_37 = F_136 ( & F_19 ( V_26 ) -> V_173 , & V_59 ,
( T_1 ) - 1 , 1 , V_98 , 0 ) ;
if ( ! V_37 )
return 0 ;
V_37 = F_140 ( & F_19 ( V_26 ) -> V_173 , V_15 ,
& V_207 ) ;
if ( V_37 )
return 0 ;
V_208 = (struct V_170 * ) ( unsigned long ) V_207 ;
F_23 ( ! V_208 -> V_210 ) ;
if ( V_208 -> V_211 ) {
F_160 ( L_14 ,
V_208 -> V_15 ) ;
goto V_111;
}
if ( V_32 -> V_188 -> V_189 & V_190 )
goto V_111;
F_75 ( & F_19 ( V_26 ) -> V_156 . V_57 ) ;
V_2 = F_119 ( & F_19 ( V_26 ) -> V_156 ,
V_208 -> V_15 ,
V_124 ) ;
F_78 ( & F_19 ( V_26 ) -> V_156 . V_57 ) ;
if ( V_2 && V_2 -> V_15 <= V_208 -> V_15 &&
V_2 -> V_16 >= V_208 -> V_15 + V_208 -> V_21 - 1 ) {
V_209 = F_161 ( V_32 , V_208 -> V_176 ,
V_208 -> V_21 ) ;
if ( V_209 > 1 ) {
F_146 ( V_26 , V_15 , V_208 -> V_21 ,
V_208 -> V_176 , V_133 ,
V_177 , V_208 -> V_212 ) ;
}
}
V_111:
F_144 ( V_26 , V_208 ) ;
return 0 ;
}
void F_162 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_16 )
{
struct V_24 * V_172 = & F_19 ( V_26 ) -> V_173 ;
struct V_170 * V_208 ;
struct V_1 * V_2 , * V_13 ;
if ( F_163 ( & V_172 -> V_2 ) )
return;
F_75 ( & V_172 -> V_57 ) ;
V_2 = F_119 ( V_172 , V_15 , V_98 ) ;
while ( V_2 ) {
if ( V_2 -> V_15 > V_16 )
break;
ASSERT ( V_2 -> V_16 <= V_16 ) ;
V_13 = F_66 ( V_2 ) ;
V_208 = (struct V_170 * ) ( unsigned long ) V_2 -> V_59 ;
F_43 ( V_2 ) ;
F_145 ( V_208 ) ;
V_2 = V_13 ;
}
F_78 ( & V_172 -> V_57 ) ;
}
int F_164 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_16 ,
struct V_170 * * V_213 )
{
struct V_170 * V_208 ;
T_1 V_59 ;
struct V_214 * V_215 ;
struct V_24 * V_172 = & F_19 ( V_26 ) -> V_173 ;
struct V_24 * V_25 = & F_19 ( V_26 ) -> V_156 ;
struct V_216 * V_217 = & F_19 ( V_26 ) -> V_218 ;
int V_37 ;
T_1 V_176 ;
V_37 = F_140 ( V_172 , V_15 , & V_59 ) ;
if ( V_37 ) {
V_208 = F_165 ( sizeof( * V_208 ) , V_129 ) ;
if ( ! V_208 )
return - V_45 ;
V_208 -> V_15 = V_15 ;
V_208 -> V_21 = V_16 - V_15 + 1 ;
V_208 -> V_210 = 0 ;
V_208 -> V_219 = 0 ;
V_208 -> V_211 = 0 ;
F_166 ( & V_217 -> V_57 ) ;
V_215 = F_167 ( V_217 , V_15 , V_208 -> V_21 ) ;
if ( ! V_215 ) {
F_168 ( & V_217 -> V_57 ) ;
F_145 ( V_208 ) ;
return - V_158 ;
}
if ( V_215 -> V_15 > V_15 || V_215 -> V_15 + V_215 -> V_21 <= V_15 ) {
F_169 ( V_215 ) ;
V_215 = NULL ;
}
F_168 ( & V_217 -> V_57 ) ;
if ( ! V_215 ) {
F_145 ( V_208 ) ;
return - V_158 ;
}
V_176 = V_15 - V_215 -> V_15 ;
V_176 = V_215 -> V_220 + V_176 ;
if ( F_170 ( V_221 , & V_215 -> V_7 ) ) {
V_176 = V_215 -> V_220 ;
V_208 -> V_219 = V_222 ;
F_171 ( & V_208 -> V_219 ,
V_215 -> V_223 ) ;
}
F_160 ( L_15 ,
V_176 , V_15 , V_208 -> V_21 ) ;
V_208 -> V_176 = V_176 ;
F_169 ( V_215 ) ;
V_37 = F_94 ( V_172 , V_15 , V_16 ,
V_124 | V_98 , V_129 ) ;
if ( V_37 >= 0 )
V_37 = F_139 ( V_172 , V_15 ,
( T_1 ) ( unsigned long ) V_208 ) ;
if ( V_37 >= 0 )
V_37 = F_94 ( V_25 , V_15 , V_16 , V_174 ,
V_129 ) ;
if ( V_37 < 0 ) {
F_145 ( V_208 ) ;
return V_37 ;
}
} else {
V_208 = (struct V_170 * ) ( unsigned long ) V_59 ;
F_160 ( L_16 ,
V_208 -> V_176 , V_208 -> V_15 , V_208 -> V_21 ,
V_208 -> V_211 ) ;
}
* V_213 = V_208 ;
return 0 ;
}
int F_172 ( struct V_26 * V_26 , struct V_50 * V_224 ,
struct V_170 * V_208 , int V_212 )
{
int V_209 ;
V_209 = F_161 ( F_19 ( V_26 ) -> V_31 -> V_32 ,
V_208 -> V_176 , V_208 -> V_21 ) ;
if ( V_209 == 1 ) {
F_160 ( L_17 ,
V_209 , V_208 -> V_210 , V_212 ) ;
return 0 ;
}
if ( V_224 -> V_225 > 1 ) {
F_23 ( V_208 -> V_211 ) ;
V_208 -> V_211 = 1 ;
V_208 -> V_210 = V_212 ;
} else {
if ( V_208 -> V_211 ) {
F_23 ( V_208 -> V_210 != V_212 ) ;
V_208 -> V_211 = 0 ;
V_208 -> V_210 = 0 ;
}
V_208 -> V_212 = V_212 ;
V_208 -> V_210 ++ ;
if ( V_208 -> V_210 == V_212 )
V_208 -> V_210 ++ ;
}
if ( V_208 -> V_210 > V_209 ) {
F_160 ( L_18 ,
V_209 , V_208 -> V_210 , V_212 ) ;
return 0 ;
}
return 1 ;
}
struct V_50 * F_173 ( struct V_26 * V_26 , struct V_50 * V_224 ,
struct V_170 * V_208 ,
struct V_133 * V_133 , int V_177 , int V_226 ,
T_6 * V_227 , void * V_228 )
{
struct V_50 * V_50 ;
struct V_49 * V_229 ;
struct V_49 * V_183 ;
V_50 = F_148 ( V_129 , 1 ) ;
if ( ! V_50 )
return NULL ;
V_50 -> V_230 = V_227 ;
V_50 -> V_191 . V_196 = V_208 -> V_176 >> 9 ;
V_50 -> V_199 = F_19 ( V_26 ) -> V_31 -> V_32 -> V_231 -> V_232 ;
V_50 -> V_191 . V_192 = 0 ;
V_50 -> V_233 = V_228 ;
V_229 = V_49 ( V_224 ) ;
if ( V_229 -> V_234 ) {
struct V_41 * V_32 = F_19 ( V_26 ) -> V_31 -> V_32 ;
T_7 V_235 = F_174 ( V_32 -> V_236 ) ;
V_183 = V_49 ( V_50 ) ;
V_183 -> V_234 = V_183 -> V_237 ;
V_226 *= V_235 ;
memcpy ( V_183 -> V_234 , V_229 -> V_234 + V_226 ,
V_235 ) ;
}
F_152 ( V_50 , V_133 , V_208 -> V_21 , V_177 ) ;
return V_50 ;
}
static int F_175 ( struct V_50 * V_224 , T_1 V_238 ,
struct V_133 * V_133 , T_1 V_15 , T_1 V_16 ,
int V_212 )
{
struct V_170 * V_208 ;
struct V_26 * V_26 = V_133 -> V_28 -> V_29 ;
struct V_24 * V_25 = & F_19 ( V_26 ) -> V_156 ;
struct V_50 * V_50 ;
int V_239 ;
int V_37 ;
F_23 ( V_224 -> V_240 & V_241 ) ;
V_37 = F_164 ( V_26 , V_15 , V_16 , & V_208 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_172 ( V_26 , V_224 , V_208 , V_212 ) ;
if ( ! V_37 ) {
F_144 ( V_26 , V_208 ) ;
return - V_158 ;
}
if ( V_224 -> V_225 > 1 )
V_239 = V_242 | V_243 ;
else
V_239 = V_242 ;
V_238 >>= V_26 -> V_42 -> V_244 ;
V_50 = F_173 ( V_26 , V_224 , V_208 , V_133 ,
V_15 - F_142 ( V_133 ) ,
( int ) V_238 , V_224 -> V_230 ,
NULL ) ;
if ( ! V_50 ) {
F_144 ( V_26 , V_208 ) ;
return - V_158 ;
}
F_160 ( L_19 ,
V_239 , V_208 -> V_210 , V_208 -> V_211 ) ;
V_37 = V_25 -> V_55 -> V_245 ( V_26 , V_239 , V_50 ,
V_208 -> V_210 ,
V_208 -> V_219 , 0 ) ;
if ( V_37 ) {
F_144 ( V_26 , V_208 ) ;
F_150 ( V_50 ) ;
}
return V_37 ;
}
int F_176 ( struct V_133 * V_133 , int V_100 , T_1 V_15 , T_1 V_16 )
{
int V_246 = ( V_100 == 0 ) ;
struct V_24 * V_25 ;
int V_37 = 0 ;
V_25 = & F_19 ( V_133 -> V_28 -> V_29 ) -> V_156 ;
if ( V_25 -> V_55 && V_25 -> V_55 -> V_247 ) {
V_37 = V_25 -> V_55 -> V_247 ( V_133 , V_15 ,
V_16 , NULL , V_246 ) ;
if ( V_37 )
V_246 = 0 ;
}
if ( ! V_246 ) {
F_177 ( V_133 ) ;
F_134 ( V_133 ) ;
V_37 = V_37 < 0 ? V_37 : - V_158 ;
F_132 ( V_133 -> V_28 , V_37 ) ;
}
return 0 ;
}
static void F_178 ( struct V_50 * V_50 )
{
struct V_248 * V_249 ;
T_1 V_15 ;
T_1 V_16 ;
int V_144 ;
F_179 (bvec, bio, i) {
struct V_133 * V_133 = V_249 -> V_250 ;
if ( V_249 -> V_251 || V_249 -> V_252 != V_153 ) {
if ( V_249 -> V_251 + V_249 -> V_252 != V_153 )
F_180 ( F_19 ( V_133 -> V_28 -> V_29 ) -> V_31 -> V_32 ,
L_20 ,
V_249 -> V_251 , V_249 -> V_252 ) ;
else
F_181 ( F_19 ( V_133 -> V_28 -> V_29 ) -> V_31 -> V_32 ,
L_21
L_22 ,
V_249 -> V_251 , V_249 -> V_252 ) ;
}
V_15 = F_142 ( V_133 ) ;
V_16 = V_15 + V_249 -> V_251 + V_249 -> V_252 - 1 ;
if ( F_176 ( V_133 , V_50 -> V_253 , V_15 , V_16 ) )
continue;
F_135 ( V_133 ) ;
}
F_150 ( V_50 ) ;
}
static void
F_182 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_21 ,
int V_246 )
{
struct V_1 * V_103 = NULL ;
T_1 V_16 = V_15 + V_21 - 1 ;
if ( V_246 && V_25 -> V_254 )
F_103 ( V_25 , V_15 , V_16 , & V_103 , V_40 ) ;
F_108 ( V_25 , V_15 , V_16 , & V_103 , V_40 ) ;
}
static void F_183 ( struct V_50 * V_50 )
{
struct V_248 * V_249 ;
int V_246 = ! V_50 -> V_253 ;
struct V_49 * V_255 = V_49 ( V_50 ) ;
struct V_24 * V_25 ;
T_1 V_64 = 0 ;
T_1 V_15 ;
T_1 V_16 ;
T_1 V_21 ;
T_1 V_256 = 0 ;
T_1 V_257 = 0 ;
int V_258 ;
int V_37 ;
int V_144 ;
F_179 (bvec, bio, i) {
struct V_133 * V_133 = V_249 -> V_250 ;
struct V_26 * V_26 = V_133 -> V_28 -> V_29 ;
F_160 ( L_23
L_24 , ( T_1 ) V_50 -> V_191 . V_196 ,
V_50 -> V_253 , V_255 -> V_178 ) ;
V_25 = & F_19 ( V_26 ) -> V_156 ;
if ( V_249 -> V_251 || V_249 -> V_252 != V_153 ) {
if ( V_249 -> V_251 + V_249 -> V_252 != V_153 )
F_180 ( F_19 ( V_133 -> V_28 -> V_29 ) -> V_31 -> V_32 ,
L_25 ,
V_249 -> V_251 , V_249 -> V_252 ) ;
else
F_181 ( F_19 ( V_133 -> V_28 -> V_29 ) -> V_31 -> V_32 ,
L_26
L_22 ,
V_249 -> V_251 , V_249 -> V_252 ) ;
}
V_15 = F_142 ( V_133 ) ;
V_16 = V_15 + V_249 -> V_251 + V_249 -> V_252 - 1 ;
V_21 = V_249 -> V_252 ;
V_258 = V_255 -> V_178 ;
if ( F_184 ( V_246 && V_25 -> V_55 &&
V_25 -> V_55 -> V_259 ) ) {
V_37 = V_25 -> V_55 -> V_259 ( V_255 , V_64 ,
V_133 , V_15 , V_16 ,
V_258 ) ;
if ( V_37 )
V_246 = 0 ;
else
F_159 ( V_26 , V_15 , V_133 , 0 ) ;
}
if ( F_184 ( V_246 ) )
goto V_260;
if ( V_25 -> V_55 && V_25 -> V_55 -> V_261 ) {
V_37 = V_25 -> V_55 -> V_261 ( V_133 , V_258 ) ;
if ( ! V_37 && ! V_50 -> V_253 )
V_246 = 1 ;
} else {
V_37 = F_175 ( V_50 , V_64 , V_133 , V_15 , V_16 ,
V_258 ) ;
if ( V_37 == 0 ) {
V_246 = ! V_50 -> V_253 ;
V_64 += V_21 ;
continue;
}
}
V_260:
if ( F_184 ( V_246 ) ) {
T_8 V_262 = F_17 ( V_26 ) ;
T_9 V_132 = V_262 >> V_131 ;
unsigned V_263 ;
V_263 = V_262 & ( V_153 - 1 ) ;
if ( V_133 -> V_130 == V_132 && V_263 )
F_185 ( V_133 , V_263 , V_153 ) ;
F_143 ( V_133 ) ;
} else {
F_177 ( V_133 ) ;
F_134 ( V_133 ) ;
}
F_125 ( V_133 ) ;
V_64 += V_21 ;
if ( F_186 ( ! V_246 ) ) {
if ( V_257 ) {
F_182 ( V_25 ,
V_256 ,
V_257 , 1 ) ;
V_256 = 0 ;
V_257 = 0 ;
}
F_182 ( V_25 , V_15 ,
V_16 - V_15 + 1 , 0 ) ;
} else if ( ! V_257 ) {
V_256 = V_15 ;
V_257 = V_16 + 1 - V_15 ;
} else if ( V_256 + V_257 == V_15 ) {
V_257 += V_16 + 1 - V_15 ;
} else {
F_182 ( V_25 , V_256 ,
V_257 , V_246 ) ;
V_256 = V_15 ;
V_257 = V_16 + 1 - V_15 ;
}
}
if ( V_257 )
F_182 ( V_25 , V_256 , V_257 ,
V_246 ) ;
if ( V_255 -> V_264 )
V_255 -> V_264 ( V_255 , V_50 -> V_253 ) ;
F_150 ( V_50 ) ;
}
struct V_50 *
F_187 ( struct V_265 * V_197 , T_1 V_266 , int V_267 ,
T_3 V_268 )
{
struct V_49 * V_183 ;
struct V_50 * V_50 ;
V_50 = F_188 ( V_268 , V_267 , V_47 ) ;
if ( V_50 == NULL && ( V_269 -> V_7 & V_270 ) ) {
while ( ! V_50 && ( V_267 /= 2 ) ) {
V_50 = F_188 ( V_268 ,
V_267 , V_47 ) ;
}
}
if ( V_50 ) {
V_50 -> V_199 = V_197 ;
V_50 -> V_191 . V_196 = V_266 ;
V_183 = V_49 ( V_50 ) ;
V_183 -> V_234 = NULL ;
V_183 -> V_271 = NULL ;
V_183 -> V_264 = NULL ;
}
return V_50 ;
}
struct V_50 * F_189 ( struct V_50 * V_50 , T_3 V_272 )
{
struct V_49 * V_183 ;
struct V_50 * V_5 ;
V_5 = F_190 ( V_50 , V_272 , V_47 ) ;
if ( V_5 ) {
V_183 = V_49 ( V_5 ) ;
V_183 -> V_234 = NULL ;
V_183 -> V_271 = NULL ;
V_183 -> V_264 = NULL ;
#ifdef F_191
if ( V_50 -> V_273 )
F_192 ( V_5 , V_50 -> V_273 ) ;
#endif
}
return V_5 ;
}
struct V_50 * F_148 ( T_3 V_272 , unsigned int V_274 )
{
struct V_49 * V_183 ;
struct V_50 * V_50 ;
V_50 = F_188 ( V_272 , V_274 , V_47 ) ;
if ( V_50 ) {
V_183 = V_49 ( V_50 ) ;
V_183 -> V_234 = NULL ;
V_183 -> V_271 = NULL ;
V_183 -> V_264 = NULL ;
}
return V_50 ;
}
static int T_4 F_193 ( int V_275 , struct V_50 * V_50 ,
int V_178 , unsigned long V_219 )
{
int V_37 = 0 ;
struct V_248 * V_249 = V_50 -> V_276 + V_50 -> V_225 - 1 ;
struct V_133 * V_133 = V_249 -> V_250 ;
struct V_24 * V_25 = V_50 -> V_233 ;
T_1 V_15 ;
V_15 = F_142 ( V_133 ) + V_249 -> V_251 ;
V_50 -> V_233 = NULL ;
F_194 ( V_50 ) ;
if ( V_25 -> V_55 && V_25 -> V_55 -> V_245 )
V_37 = V_25 -> V_55 -> V_245 ( V_133 -> V_28 -> V_29 , V_275 , V_50 ,
V_178 , V_219 , V_15 ) ;
else
F_195 ( V_275 , V_50 ) ;
F_150 ( V_50 ) ;
return V_37 ;
}
static int F_196 ( int V_275 , struct V_24 * V_25 , struct V_133 * V_133 ,
unsigned long V_64 , T_10 V_277 , struct V_50 * V_50 ,
unsigned long V_219 )
{
int V_37 = 0 ;
if ( V_25 -> V_55 && V_25 -> V_55 -> V_278 )
V_37 = V_25 -> V_55 -> V_278 ( V_275 , V_133 , V_64 , V_277 , V_50 ,
V_219 ) ;
F_23 ( V_37 < 0 ) ;
return V_37 ;
}
static int F_197 ( int V_275 , struct V_24 * V_25 ,
struct V_279 * V_280 ,
struct V_133 * V_133 , T_11 V_182 ,
T_10 V_277 , unsigned long V_64 ,
struct V_265 * V_197 ,
struct V_50 * * V_281 ,
unsigned long V_282 ,
T_6 V_283 ,
int V_178 ,
unsigned long V_284 ,
unsigned long V_219 ,
bool V_285 )
{
int V_37 = 0 ;
struct V_50 * V_50 ;
int V_165 = 0 ;
int V_286 = V_284 & V_222 ;
T_10 V_287 = F_124 ( T_10 , V_277 , V_153 ) ;
if ( V_281 && * V_281 ) {
V_50 = * V_281 ;
if ( V_286 )
V_165 = V_50 -> V_191 . V_196 == V_182 ;
else
V_165 = F_198 ( V_50 ) == V_182 ;
if ( V_284 != V_219 || ! V_165 ||
V_285 ||
F_196 ( V_275 , V_25 , V_133 , V_64 , V_287 , V_50 , V_219 ) ||
F_152 ( V_50 , V_133 , V_287 , V_64 ) < V_287 ) {
V_37 = F_193 ( V_275 , V_50 , V_178 ,
V_284 ) ;
if ( V_37 < 0 ) {
* V_281 = NULL ;
return V_37 ;
}
V_50 = NULL ;
} else {
if ( V_280 )
F_199 ( V_280 , V_133 , V_287 ) ;
return 0 ;
}
}
V_50 = F_187 ( V_197 , V_182 , V_288 ,
V_129 | V_289 ) ;
if ( ! V_50 )
return - V_45 ;
F_152 ( V_50 , V_133 , V_287 , V_64 ) ;
V_50 -> V_230 = V_283 ;
V_50 -> V_233 = V_25 ;
if ( V_280 ) {
F_200 ( V_280 , V_50 ) ;
F_199 ( V_280 , V_133 , V_287 ) ;
}
if ( V_281 )
* V_281 = V_50 ;
else
V_37 = F_193 ( V_275 , V_50 , V_178 , V_219 ) ;
return V_37 ;
}
static void F_201 ( struct V_10 * V_11 ,
struct V_133 * V_133 )
{
if ( ! F_202 ( V_133 ) ) {
F_203 ( V_133 ) ;
F_204 ( V_133 ) ;
F_205 ( V_133 , ( unsigned long ) V_11 ) ;
} else {
F_45 ( V_133 -> V_59 != ( unsigned long ) V_11 ) ;
}
}
void F_206 ( struct V_133 * V_133 )
{
if ( ! F_202 ( V_133 ) ) {
F_203 ( V_133 ) ;
F_204 ( V_133 ) ;
F_205 ( V_133 , V_290 ) ;
}
}
static struct V_214 *
F_207 ( struct V_26 * V_26 , struct V_133 * V_133 , T_10 V_177 ,
T_1 V_15 , T_1 V_21 , T_12 * V_291 ,
struct V_214 * * V_292 )
{
struct V_214 * V_215 ;
if ( V_292 && * V_292 ) {
V_215 = * V_292 ;
if ( F_208 ( V_215 ) && V_15 >= V_215 -> V_15 &&
V_15 < F_209 ( V_215 ) ) {
F_86 ( & V_215 -> V_17 ) ;
return V_215 ;
}
F_169 ( V_215 ) ;
* V_292 = NULL ;
}
V_215 = V_291 ( V_26 , V_133 , V_177 , V_15 , V_21 , 0 ) ;
if ( V_292 && ! F_210 ( V_215 ) ) {
F_23 ( * V_292 ) ;
F_86 ( & V_215 -> V_17 ) ;
* V_292 = V_215 ;
}
return V_215 ;
}
static int F_211 ( struct V_24 * V_25 ,
struct V_133 * V_133 ,
T_12 * V_291 ,
struct V_214 * * V_292 ,
struct V_50 * * V_50 , int V_178 ,
unsigned long * V_219 , int V_275 ,
T_1 * V_293 )
{
struct V_26 * V_26 = V_133 -> V_28 -> V_29 ;
T_1 V_15 = F_142 ( V_133 ) ;
T_1 V_294 = V_15 + V_153 - 1 ;
T_1 V_16 ;
T_1 V_295 = V_15 ;
T_1 V_296 ;
T_1 V_297 = F_17 ( V_26 ) ;
T_1 V_220 ;
T_1 V_298 ;
T_11 V_182 ;
struct V_214 * V_215 ;
struct V_265 * V_197 ;
int V_37 ;
int V_299 = 0 ;
int V_300 = * V_219 & V_301 ;
T_10 V_177 = 0 ;
T_10 V_302 ;
T_10 V_303 ;
T_10 V_304 = V_26 -> V_42 -> V_305 ;
unsigned long V_306 = * V_219 & V_301 ;
F_206 ( V_133 ) ;
V_16 = V_294 ;
if ( ! F_212 ( V_133 ) ) {
if ( F_213 ( V_133 ) == 0 ) {
F_23 ( V_304 != V_30 ) ;
F_109 ( V_25 , V_15 , V_16 ) ;
goto V_111;
}
}
if ( V_133 -> V_130 == V_297 >> V_131 ) {
char * V_307 ;
T_10 V_308 = V_297 & ( V_153 - 1 ) ;
if ( V_308 ) {
V_302 = V_153 - V_308 ;
V_307 = F_214 ( V_133 ) ;
memset ( V_307 + V_308 , 0 , V_302 ) ;
F_215 ( V_133 ) ;
F_216 ( V_307 ) ;
}
}
while ( V_295 <= V_16 ) {
unsigned long V_309 = ( V_297 >> V_131 ) + 1 ;
bool V_285 = false ;
if ( V_295 >= V_297 ) {
char * V_307 ;
struct V_1 * V_103 = NULL ;
V_302 = V_153 - V_177 ;
V_307 = F_214 ( V_133 ) ;
memset ( V_307 + V_177 , 0 , V_302 ) ;
F_215 ( V_133 ) ;
F_216 ( V_307 ) ;
F_103 ( V_25 , V_295 , V_295 + V_302 - 1 ,
& V_103 , V_129 ) ;
if ( ! V_300 )
F_108 ( V_25 , V_295 ,
V_295 + V_302 - 1 ,
& V_103 , V_129 ) ;
break;
}
V_215 = F_207 ( V_26 , V_133 , V_177 , V_295 ,
V_16 - V_295 + 1 , V_291 , V_292 ) ;
if ( F_210 ( V_215 ) ) {
F_134 ( V_133 ) ;
if ( ! V_300 )
F_109 ( V_25 , V_295 , V_16 ) ;
break;
}
V_296 = V_295 - V_215 -> V_15 ;
F_23 ( F_209 ( V_215 ) <= V_295 ) ;
F_23 ( V_16 < V_295 ) ;
if ( F_170 ( V_221 , & V_215 -> V_7 ) ) {
V_306 |= V_222 ;
F_171 ( & V_306 ,
V_215 -> V_223 ) ;
}
V_302 = F_137 ( F_209 ( V_215 ) - V_295 , V_16 - V_295 + 1 ) ;
V_298 = F_137 ( F_209 ( V_215 ) - 1 , V_16 ) ;
V_302 = F_217 ( V_302 , V_304 ) ;
if ( V_306 & V_222 ) {
V_303 = V_215 -> V_310 ;
V_182 = V_215 -> V_220 >> 9 ;
} else {
V_182 = ( V_215 -> V_220 + V_296 ) >> 9 ;
V_303 = V_302 ;
}
V_197 = V_215 -> V_197 ;
V_220 = V_215 -> V_220 ;
if ( F_170 ( V_311 , & V_215 -> V_7 ) )
V_220 = V_312 ;
if ( F_170 ( V_221 , & V_215 -> V_7 ) &&
V_293 && * V_293 != ( T_1 ) - 1 &&
* V_293 != V_215 -> V_313 )
V_285 = true ;
if ( V_293 )
* V_293 = V_215 -> V_313 ;
F_169 ( V_215 ) ;
V_215 = NULL ;
if ( V_220 == V_312 ) {
char * V_307 ;
struct V_1 * V_103 = NULL ;
V_307 = F_214 ( V_133 ) ;
memset ( V_307 + V_177 , 0 , V_302 ) ;
F_215 ( V_133 ) ;
F_216 ( V_307 ) ;
F_103 ( V_25 , V_295 , V_295 + V_302 - 1 ,
& V_103 , V_129 ) ;
if ( V_300 )
F_43 ( V_103 ) ;
else
F_108 ( V_25 , V_295 ,
V_295 + V_302 - 1 ,
& V_103 , V_129 ) ;
V_295 = V_295 + V_302 ;
V_177 += V_302 ;
continue;
}
if ( F_130 ( V_25 , V_295 , V_298 ,
V_125 , 1 , NULL ) ) {
F_141 ( V_25 , V_133 ) ;
if ( ! V_300 )
F_109 ( V_25 , V_295 , V_295 + V_302 - 1 ) ;
V_295 = V_295 + V_302 ;
V_177 += V_302 ;
continue;
}
if ( V_220 == V_314 ) {
F_134 ( V_133 ) ;
if ( ! V_300 )
F_109 ( V_25 , V_295 , V_295 + V_302 - 1 ) ;
V_295 = V_295 + V_302 ;
V_177 += V_302 ;
continue;
}
V_309 -= V_133 -> V_130 ;
V_37 = F_197 ( V_275 , V_25 , NULL , V_133 ,
V_182 , V_303 , V_177 ,
V_197 , V_50 , V_309 ,
F_183 , V_178 ,
* V_219 ,
V_306 ,
V_285 ) ;
if ( ! V_37 ) {
V_299 ++ ;
* V_219 = V_306 ;
} else {
F_134 ( V_133 ) ;
if ( ! V_300 )
F_109 ( V_25 , V_295 , V_295 + V_302 - 1 ) ;
}
V_295 = V_295 + V_302 ;
V_177 += V_302 ;
}
V_111:
if ( ! V_299 ) {
if ( ! F_218 ( V_133 ) )
F_143 ( V_133 ) ;
F_125 ( V_133 ) ;
}
return 0 ;
}
static inline void F_219 ( struct V_24 * V_25 ,
struct V_133 * V_142 [] , int V_143 ,
T_1 V_15 , T_1 V_16 ,
T_12 * V_291 ,
struct V_214 * * V_292 ,
struct V_50 * * V_50 , int V_178 ,
unsigned long * V_219 , int V_275 ,
T_1 * V_293 )
{
struct V_26 * V_26 ;
struct V_315 * V_316 ;
int V_130 ;
V_26 = V_142 [ 0 ] -> V_28 -> V_29 ;
while ( 1 ) {
F_106 ( V_25 , V_15 , V_16 ) ;
V_316 = F_220 ( V_26 , V_15 ,
V_16 - V_15 + 1 ) ;
if ( ! V_316 )
break;
F_109 ( V_25 , V_15 , V_16 ) ;
F_221 ( V_26 , V_316 , 1 ) ;
F_222 ( V_316 ) ;
}
for ( V_130 = 0 ; V_130 < V_143 ; V_130 ++ ) {
F_211 ( V_25 , V_142 [ V_130 ] , V_291 , V_292 , V_50 ,
V_178 , V_219 , V_275 , V_293 ) ;
F_113 ( V_142 [ V_130 ] ) ;
}
}
static void F_223 ( struct V_24 * V_25 ,
struct V_133 * V_142 [] ,
int V_143 , T_12 * V_291 ,
struct V_214 * * V_292 ,
struct V_50 * * V_50 , int V_178 ,
unsigned long * V_219 , int V_275 ,
T_1 * V_293 )
{
T_1 V_15 = 0 ;
T_1 V_16 = 0 ;
T_1 V_317 ;
int V_130 ;
int V_318 = 0 ;
for ( V_130 = 0 ; V_130 < V_143 ; V_130 ++ ) {
V_317 = F_142 ( V_142 [ V_130 ] ) ;
if ( ! V_16 ) {
V_15 = V_317 ;
V_16 = V_15 + V_153 - 1 ;
V_318 = V_130 ;
} else if ( V_16 + 1 == V_317 ) {
V_16 += V_153 ;
} else {
F_219 ( V_25 , & V_142 [ V_318 ] ,
V_130 - V_318 , V_15 ,
V_16 , V_291 , V_292 ,
V_50 , V_178 , V_219 ,
V_275 , V_293 ) ;
V_15 = V_317 ;
V_16 = V_15 + V_153 - 1 ;
V_318 = V_130 ;
}
}
if ( V_16 )
F_219 ( V_25 , & V_142 [ V_318 ] ,
V_130 - V_318 , V_15 ,
V_16 , V_291 , V_292 , V_50 ,
V_178 , V_219 , V_275 ,
V_293 ) ;
}
static int F_224 ( struct V_24 * V_25 ,
struct V_133 * V_133 ,
T_12 * V_291 ,
struct V_50 * * V_50 , int V_178 ,
unsigned long * V_219 , int V_275 )
{
struct V_26 * V_26 = V_133 -> V_28 -> V_29 ;
struct V_315 * V_316 ;
T_1 V_15 = F_142 ( V_133 ) ;
T_1 V_16 = V_15 + V_153 - 1 ;
int V_37 ;
while ( 1 ) {
F_106 ( V_25 , V_15 , V_16 ) ;
V_316 = F_225 ( V_26 , V_15 ) ;
if ( ! V_316 )
break;
F_109 ( V_25 , V_15 , V_16 ) ;
F_221 ( V_26 , V_316 , 1 ) ;
F_222 ( V_316 ) ;
}
V_37 = F_211 ( V_25 , V_133 , V_291 , NULL , V_50 , V_178 ,
V_219 , V_275 , NULL ) ;
return V_37 ;
}
int F_226 ( struct V_24 * V_25 , struct V_133 * V_133 ,
T_12 * V_291 , int V_178 )
{
struct V_50 * V_50 = NULL ;
unsigned long V_219 = 0 ;
int V_37 ;
V_37 = F_224 ( V_25 , V_133 , V_291 , & V_50 , V_178 ,
& V_219 , V_319 ) ;
if ( V_50 )
V_37 = F_193 ( V_319 , V_50 , V_178 , V_219 ) ;
return V_37 ;
}
int F_227 ( struct V_24 * V_25 , struct V_133 * V_133 ,
T_12 * V_291 , int V_178 )
{
struct V_50 * V_50 = NULL ;
unsigned long V_219 = V_301 ;
int V_37 ;
V_37 = F_211 ( V_25 , V_133 , V_291 , NULL , & V_50 , V_178 ,
& V_219 , V_319 , NULL ) ;
if ( V_50 )
V_37 = F_193 ( V_319 , V_50 , V_178 , V_219 ) ;
return V_37 ;
}
static T_5 void F_228 ( struct V_133 * V_133 ,
struct V_279 * V_280 ,
unsigned long V_320 )
{
V_280 -> V_321 -= V_320 ;
if ( V_280 -> V_322 || ( V_280 -> V_321 > 0 &&
V_280 -> V_323 == 0 && V_280 -> V_324 == V_325 ) )
V_133 -> V_28 -> V_326 = V_133 -> V_130 + V_320 ;
}
static T_13 int F_229 ( struct V_26 * V_26 ,
struct V_133 * V_133 , struct V_279 * V_280 ,
struct V_327 * V_328 ,
T_1 V_145 ,
unsigned long * V_320 )
{
struct V_24 * V_25 = V_328 -> V_25 ;
T_1 V_294 = V_145 + V_153 - 1 ;
T_1 V_329 ;
T_1 V_330 = 0 ;
T_1 V_146 = 0 ;
int V_37 ;
int V_331 = 0 ;
if ( V_328 -> V_332 || ! V_25 -> V_55 || ! V_25 -> V_55 -> V_333 )
return 0 ;
while ( V_146 < V_294 ) {
V_329 = F_129 ( V_26 , V_25 ,
V_133 ,
& V_145 ,
& V_146 ,
V_334 ) ;
if ( V_329 == 0 ) {
V_145 = V_146 + 1 ;
continue;
}
V_37 = V_25 -> V_55 -> V_333 ( V_26 , V_133 ,
V_145 ,
V_146 ,
& V_331 ,
V_320 ) ;
if ( V_37 ) {
F_134 ( V_133 ) ;
V_37 = V_37 < 0 ? V_37 : - V_158 ;
goto V_151;
}
V_330 += ( V_146 - V_145 +
V_153 ) >>
V_131 ;
V_145 = V_146 + 1 ;
}
if ( V_280 -> V_321 < V_330 ) {
int V_335 = 8192 ;
if ( V_330 < V_335 * 2 )
V_335 = V_330 ;
V_280 -> V_321 = F_124 ( T_1 , V_330 ,
V_335 ) ;
}
if ( V_331 ) {
V_280 -> V_321 -= * V_320 ;
return 1 ;
}
V_37 = 0 ;
V_151:
return V_37 ;
}
static T_13 int F_230 ( struct V_26 * V_26 ,
struct V_133 * V_133 ,
struct V_279 * V_280 ,
struct V_327 * V_328 ,
T_8 V_262 ,
unsigned long V_320 ,
int V_336 , int * V_337 )
{
struct V_24 * V_25 = V_328 -> V_25 ;
T_1 V_15 = F_142 ( V_133 ) ;
T_1 V_294 = V_15 + V_153 - 1 ;
T_1 V_16 ;
T_1 V_295 = V_15 ;
T_1 V_296 ;
T_1 V_220 ;
T_1 V_302 ;
T_11 V_182 ;
struct V_1 * V_102 = NULL ;
struct V_214 * V_215 ;
struct V_265 * V_197 ;
T_10 V_177 = 0 ;
T_10 V_304 ;
int V_37 = 0 ;
int V_299 = 0 ;
bool V_338 ;
if ( V_25 -> V_55 && V_25 -> V_55 -> V_339 ) {
V_37 = V_25 -> V_55 -> V_339 ( V_133 , V_15 ,
V_294 ) ;
if ( V_37 ) {
if ( V_37 == - V_340 )
V_280 -> V_341 ++ ;
else
F_231 ( V_280 , V_133 ) ;
F_228 ( V_133 , V_280 , V_320 ) ;
F_125 ( V_133 ) ;
V_37 = 1 ;
goto V_342;
}
}
F_228 ( V_133 , V_280 , V_320 + 1 ) ;
V_16 = V_294 ;
if ( V_262 <= V_15 ) {
if ( V_25 -> V_55 && V_25 -> V_55 -> V_247 )
V_25 -> V_55 -> V_247 ( V_133 , V_15 ,
V_294 , NULL , 1 ) ;
goto V_151;
}
V_304 = V_26 -> V_42 -> V_305 ;
while ( V_295 <= V_16 ) {
T_1 V_343 ;
if ( V_295 >= V_262 ) {
if ( V_25 -> V_55 && V_25 -> V_55 -> V_247 )
V_25 -> V_55 -> V_247 ( V_133 , V_295 ,
V_294 , NULL , 1 ) ;
break;
}
V_215 = V_328 -> V_291 ( V_26 , V_133 , V_177 , V_295 ,
V_16 - V_295 + 1 , 1 ) ;
if ( F_210 ( V_215 ) ) {
F_134 ( V_133 ) ;
V_37 = F_232 ( V_215 ) ;
break;
}
V_296 = V_295 - V_215 -> V_15 ;
V_343 = F_209 ( V_215 ) ;
F_23 ( V_343 <= V_295 ) ;
F_23 ( V_16 < V_295 ) ;
V_302 = F_137 ( V_343 - V_295 , V_16 - V_295 + 1 ) ;
V_302 = F_217 ( V_302 , V_304 ) ;
V_182 = ( V_215 -> V_220 + V_296 ) >> 9 ;
V_197 = V_215 -> V_197 ;
V_220 = V_215 -> V_220 ;
V_338 = F_170 ( V_221 , & V_215 -> V_7 ) ;
F_169 ( V_215 ) ;
V_215 = NULL ;
if ( V_338 || V_220 == V_312 ||
V_220 == V_314 ) {
if ( ! V_338 && V_25 -> V_55 &&
V_25 -> V_55 -> V_247 )
V_25 -> V_55 -> V_247 ( V_133 , V_295 ,
V_295 + V_302 - 1 ,
NULL , 1 ) ;
else if ( V_338 ) {
V_299 ++ ;
}
V_295 += V_302 ;
V_177 += V_302 ;
continue;
}
if ( V_25 -> V_55 && V_25 -> V_55 -> V_344 ) {
V_37 = V_25 -> V_55 -> V_344 ( V_133 , V_295 ,
V_295 + V_302 - 1 ) ;
} else {
V_37 = 0 ;
}
if ( V_37 ) {
F_134 ( V_133 ) ;
} else {
unsigned long V_345 = ( V_262 >> V_131 ) + 1 ;
F_117 ( V_25 , V_295 , V_295 + V_302 - 1 ) ;
if ( ! F_233 ( V_133 ) ) {
F_180 ( F_19 ( V_26 ) -> V_31 -> V_32 ,
L_27 ,
V_133 -> V_130 , V_295 , V_16 ) ;
}
V_37 = F_197 ( V_336 , V_25 , V_280 , V_133 ,
V_182 , V_302 , V_177 ,
V_197 , & V_328 -> V_50 , V_345 ,
F_178 ,
0 , 0 , 0 , false ) ;
if ( V_37 )
F_134 ( V_133 ) ;
}
V_295 = V_295 + V_302 ;
V_177 += V_302 ;
V_299 ++ ;
}
V_151:
* V_337 = V_299 ;
V_342:
F_43 ( V_102 ) ;
return V_37 ;
}
static int F_234 ( struct V_133 * V_133 , struct V_279 * V_280 ,
void * V_228 )
{
struct V_26 * V_26 = V_133 -> V_28 -> V_29 ;
struct V_327 * V_328 = V_228 ;
T_1 V_15 = F_142 ( V_133 ) ;
T_1 V_294 = V_15 + V_153 - 1 ;
int V_37 ;
int V_299 = 0 ;
T_10 V_177 = 0 ;
T_8 V_262 = F_17 ( V_26 ) ;
unsigned long V_132 = V_262 >> V_131 ;
int V_336 ;
unsigned long V_320 = 0 ;
if ( V_280 -> V_346 == V_347 )
V_336 = V_200 ;
else
V_336 = V_193 ;
F_235 ( V_133 , V_26 , V_280 ) ;
F_45 ( ! F_236 ( V_133 ) ) ;
F_237 ( V_133 ) ;
V_177 = V_262 & ( V_153 - 1 ) ;
if ( V_133 -> V_130 > V_132 ||
( V_133 -> V_130 == V_132 && ! V_177 ) ) {
V_133 -> V_28 -> V_348 -> V_349 ( V_133 , 0 , V_153 ) ;
F_125 ( V_133 ) ;
return 0 ;
}
if ( V_133 -> V_130 == V_132 ) {
char * V_307 ;
V_307 = F_214 ( V_133 ) ;
memset ( V_307 + V_177 , 0 ,
V_153 - V_177 ) ;
F_216 ( V_307 ) ;
F_215 ( V_133 ) ;
}
V_177 = 0 ;
F_206 ( V_133 ) ;
V_37 = F_229 ( V_26 , V_133 , V_280 , V_328 , V_15 , & V_320 ) ;
if ( V_37 == 1 )
goto V_342;
if ( V_37 )
goto V_151;
V_37 = F_230 ( V_26 , V_133 , V_280 , V_328 ,
V_262 , V_320 , V_336 , & V_299 ) ;
if ( V_37 == 1 )
goto V_342;
V_151:
if ( V_299 == 0 ) {
F_118 ( V_133 ) ;
F_135 ( V_133 ) ;
}
if ( F_218 ( V_133 ) ) {
V_37 = V_37 < 0 ? V_37 : - V_158 ;
F_176 ( V_133 , V_37 , V_15 , V_294 ) ;
}
F_125 ( V_133 ) ;
return V_37 ;
V_342:
return 0 ;
}
void F_238 ( struct V_10 * V_11 )
{
F_239 ( & V_11 -> V_350 , V_351 ,
V_114 ) ;
}
static T_13 int
F_240 ( struct V_10 * V_11 ,
struct V_41 * V_32 ,
struct V_327 * V_328 )
{
unsigned long V_144 , V_204 ;
int V_352 = 0 ;
int V_37 = 0 ;
if ( ! F_241 ( V_11 ) ) {
V_352 = 1 ;
F_242 ( V_328 ) ;
F_243 ( V_11 ) ;
}
if ( F_170 ( V_351 , & V_11 -> V_350 ) ) {
F_244 ( V_11 ) ;
if ( ! V_328 -> V_353 )
return 0 ;
if ( ! V_352 ) {
F_242 ( V_328 ) ;
V_352 = 1 ;
}
while ( 1 ) {
F_238 ( V_11 ) ;
F_243 ( V_11 ) ;
if ( ! F_170 ( V_351 , & V_11 -> V_350 ) )
break;
F_244 ( V_11 ) ;
}
}
F_75 ( & V_11 -> V_354 ) ;
if ( F_245 ( V_355 , & V_11 -> V_350 ) ) {
F_246 ( V_351 , & V_11 -> V_350 ) ;
F_78 ( & V_11 -> V_354 ) ;
F_247 ( V_11 , V_356 ) ;
F_248 ( & V_32 -> V_357 ,
- V_11 -> V_21 ,
V_32 -> V_358 ) ;
V_37 = 1 ;
} else {
F_78 ( & V_11 -> V_354 ) ;
}
F_244 ( V_11 ) ;
if ( ! V_37 )
return V_37 ;
V_204 = F_158 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_144 = 0 ; V_144 < V_204 ; V_144 ++ ) {
struct V_133 * V_68 = V_11 -> V_142 [ V_144 ] ;
if ( ! F_249 ( V_68 ) ) {
if ( ! V_352 ) {
F_242 ( V_328 ) ;
V_352 = 1 ;
}
F_127 ( V_68 ) ;
}
}
return V_37 ;
}
static void F_250 ( struct V_10 * V_11 )
{
F_251 ( V_351 , & V_11 -> V_350 ) ;
F_252 () ;
F_253 ( & V_11 -> V_350 , V_351 ) ;
}
static void F_254 ( struct V_133 * V_133 )
{
struct V_10 * V_11 = (struct V_10 * ) V_133 -> V_59 ;
struct V_359 * V_360 = F_19 ( V_11 -> V_32 -> V_206 ) ;
F_134 ( V_133 ) ;
if ( F_255 ( V_361 , & V_11 -> V_350 ) )
return;
switch ( V_11 -> V_362 ) {
case - 1 :
F_246 ( V_363 , & V_360 -> V_364 ) ;
break;
case 0 :
F_246 ( V_365 , & V_360 -> V_364 ) ;
break;
case 1 :
F_246 ( V_366 , & V_360 -> V_364 ) ;
break;
default:
F_256 () ;
}
}
static void F_257 ( struct V_50 * V_50 )
{
struct V_248 * V_249 ;
struct V_10 * V_11 ;
int V_144 , V_151 ;
F_179 (bvec, bio, i) {
struct V_133 * V_133 = V_249 -> V_250 ;
V_11 = (struct V_10 * ) V_133 -> V_59 ;
F_23 ( ! V_11 ) ;
V_151 = F_44 ( & V_11 -> V_367 ) ;
if ( V_50 -> V_253 ||
F_170 ( V_361 , & V_11 -> V_350 ) ) {
F_177 ( V_133 ) ;
F_254 ( V_133 ) ;
}
F_135 ( V_133 ) ;
if ( ! V_151 )
continue;
F_250 ( V_11 ) ;
}
F_150 ( V_50 ) ;
}
static T_13 int F_258 ( struct V_10 * V_11 ,
struct V_41 * V_32 ,
struct V_279 * V_280 ,
struct V_327 * V_328 )
{
struct V_265 * V_197 = V_32 -> V_231 -> V_232 ;
struct V_24 * V_25 = & F_19 ( V_32 -> V_206 ) -> V_156 ;
T_1 V_64 = V_11 -> V_15 ;
unsigned long V_144 , V_204 ;
unsigned long V_219 = 0 ;
int V_275 = ( V_328 -> V_353 ? V_200 : V_193 ) | V_368 ;
int V_37 = 0 ;
F_251 ( V_361 , & V_11 -> V_350 ) ;
V_204 = F_158 ( V_11 -> V_15 , V_11 -> V_21 ) ;
F_40 ( & V_11 -> V_367 , V_204 ) ;
if ( F_259 ( V_11 ) == V_369 )
V_219 = V_370 ;
for ( V_144 = 0 ; V_144 < V_204 ; V_144 ++ ) {
struct V_133 * V_68 = V_11 -> V_142 [ V_144 ] ;
F_112 ( V_68 ) ;
F_118 ( V_68 ) ;
V_37 = F_197 ( V_275 , V_25 , V_280 , V_68 , V_64 >> 9 ,
V_153 , 0 , V_197 , & V_328 -> V_50 ,
- 1 , F_257 ,
0 , V_328 -> V_219 , V_219 , false ) ;
V_328 -> V_219 = V_219 ;
if ( V_37 ) {
F_254 ( V_68 ) ;
F_135 ( V_68 ) ;
if ( F_260 ( V_204 - V_144 , & V_11 -> V_367 ) )
F_250 ( V_11 ) ;
V_37 = - V_158 ;
break;
}
V_64 += V_153 ;
F_228 ( V_68 , V_280 , 1 ) ;
F_125 ( V_68 ) ;
}
if ( F_186 ( V_37 ) ) {
for (; V_144 < V_204 ; V_144 ++ ) {
struct V_133 * V_68 = V_11 -> V_142 [ V_144 ] ;
F_112 ( V_68 ) ;
F_125 ( V_68 ) ;
}
}
return V_37 ;
}
int F_261 ( struct V_53 * V_28 ,
struct V_279 * V_280 )
{
struct V_24 * V_25 = & F_19 ( V_28 -> V_29 ) -> V_156 ;
struct V_41 * V_32 = F_19 ( V_28 -> V_29 ) -> V_31 -> V_32 ;
struct V_10 * V_11 , * V_371 = NULL ;
struct V_327 V_328 = {
. V_50 = NULL ,
. V_25 = V_25 ,
. V_332 = 0 ,
. V_353 = V_280 -> V_346 == V_347 ,
. V_219 = 0 ,
} ;
int V_37 = 0 ;
int V_151 = 0 ;
int V_372 = 0 ;
struct V_373 V_374 ;
int V_143 ;
T_9 V_130 ;
T_9 V_16 ;
int V_375 = 0 ;
int V_376 ;
F_262 ( & V_374 , 0 ) ;
if ( V_280 -> V_322 ) {
V_130 = V_28 -> V_326 ;
V_16 = - 1 ;
} else {
V_130 = V_280 -> V_323 >> V_131 ;
V_16 = V_280 -> V_324 >> V_131 ;
V_375 = 1 ;
}
if ( V_280 -> V_346 == V_347 )
V_376 = V_377 ;
else
V_376 = V_378 ;
V_379:
if ( V_280 -> V_346 == V_347 )
F_263 ( V_28 , V_130 , V_16 ) ;
while ( ! V_151 && ! V_372 && ( V_130 <= V_16 ) &&
( V_143 = F_264 ( & V_374 , V_28 , & V_130 , V_376 ,
F_137 ( V_16 - V_130 , ( T_9 ) V_380 - 1 ) + 1 ) ) ) {
unsigned V_144 ;
V_375 = 1 ;
for ( V_144 = 0 ; V_144 < V_143 ; V_144 ++ ) {
struct V_133 * V_133 = V_374 . V_142 [ V_144 ] ;
if ( ! F_202 ( V_133 ) )
continue;
if ( ! V_280 -> V_322 && V_133 -> V_130 > V_16 ) {
V_151 = 1 ;
break;
}
F_75 ( & V_28 -> V_381 ) ;
if ( ! F_202 ( V_133 ) ) {
F_78 ( & V_28 -> V_381 ) ;
continue;
}
V_11 = (struct V_10 * ) V_133 -> V_59 ;
if ( F_45 ( ! V_11 ) ) {
F_78 ( & V_28 -> V_381 ) ;
continue;
}
if ( V_11 == V_371 ) {
F_78 ( & V_28 -> V_381 ) ;
continue;
}
V_37 = F_265 ( & V_11 -> V_17 ) ;
F_78 ( & V_28 -> V_381 ) ;
if ( ! V_37 )
continue;
V_371 = V_11 ;
V_37 = F_240 ( V_11 , V_32 , & V_328 ) ;
if ( ! V_37 ) {
F_266 ( V_11 ) ;
continue;
}
V_37 = F_258 ( V_11 , V_32 , V_280 , & V_328 ) ;
if ( V_37 ) {
V_151 = 1 ;
F_266 ( V_11 ) ;
break;
}
F_266 ( V_11 ) ;
V_372 = V_280 -> V_321 <= 0 ;
}
F_267 ( & V_374 ) ;
F_79 () ;
}
if ( ! V_375 && ! V_151 ) {
V_375 = 1 ;
V_130 = 0 ;
goto V_379;
}
F_242 ( & V_328 ) ;
return V_37 ;
}
static int F_268 ( struct V_24 * V_25 ,
struct V_53 * V_28 ,
struct V_279 * V_280 ,
T_14 V_382 , void * V_228 ,
void (* F_269)( void * ) )
{
struct V_26 * V_26 = V_28 -> V_29 ;
int V_37 = 0 ;
int V_151 = 0 ;
int V_100 = 0 ;
int V_372 = 0 ;
struct V_373 V_374 ;
int V_143 ;
T_9 V_130 ;
T_9 V_16 ;
int V_375 = 0 ;
int V_376 ;
if ( ! F_270 ( V_26 ) )
return 0 ;
F_262 ( & V_374 , 0 ) ;
if ( V_280 -> V_322 ) {
V_130 = V_28 -> V_326 ;
V_16 = - 1 ;
} else {
V_130 = V_280 -> V_323 >> V_131 ;
V_16 = V_280 -> V_324 >> V_131 ;
V_375 = 1 ;
}
if ( V_280 -> V_346 == V_347 )
V_376 = V_377 ;
else
V_376 = V_378 ;
V_379:
if ( V_280 -> V_346 == V_347 )
F_263 ( V_28 , V_130 , V_16 ) ;
while ( ! V_151 && ! V_372 && ( V_130 <= V_16 ) &&
( V_143 = F_264 ( & V_374 , V_28 , & V_130 , V_376 ,
F_137 ( V_16 - V_130 , ( T_9 ) V_380 - 1 ) + 1 ) ) ) {
unsigned V_144 ;
V_375 = 1 ;
for ( V_144 = 0 ; V_144 < V_143 ; V_144 ++ ) {
struct V_133 * V_133 = V_374 . V_142 [ V_144 ] ;
if ( ! F_249 ( V_133 ) ) {
F_269 ( V_228 ) ;
F_127 ( V_133 ) ;
}
if ( F_186 ( V_133 -> V_28 != V_28 ) ) {
F_125 ( V_133 ) ;
continue;
}
if ( ! V_280 -> V_322 && V_133 -> V_130 > V_16 ) {
V_151 = 1 ;
F_125 ( V_133 ) ;
continue;
}
if ( V_280 -> V_346 != V_383 ) {
if ( F_233 ( V_133 ) )
F_269 ( V_228 ) ;
F_271 ( V_133 ) ;
}
if ( F_233 ( V_133 ) ||
! F_112 ( V_133 ) ) {
F_125 ( V_133 ) ;
continue;
}
V_37 = (* V_382)( V_133 , V_280 , V_228 ) ;
if ( F_186 ( V_37 == V_384 ) ) {
F_125 ( V_133 ) ;
V_37 = 0 ;
}
if ( ! V_100 && V_37 < 0 )
V_100 = V_37 ;
V_372 = V_280 -> V_321 <= 0 ;
}
F_267 ( & V_374 ) ;
F_79 () ;
}
if ( ! V_375 && ! V_151 && ! V_100 ) {
V_375 = 1 ;
V_130 = 0 ;
goto V_379;
}
F_272 ( V_26 ) ;
return V_100 ;
}
static void F_273 ( struct V_327 * V_328 )
{
if ( V_328 -> V_50 ) {
int V_275 = V_193 ;
int V_37 ;
if ( V_328 -> V_353 )
V_275 = V_200 ;
V_37 = F_193 ( V_275 , V_328 -> V_50 , 0 , V_328 -> V_219 ) ;
F_23 ( V_37 < 0 ) ;
V_328 -> V_50 = NULL ;
}
}
static T_5 void F_242 ( void * V_228 )
{
struct V_327 * V_328 = V_228 ;
F_273 ( V_328 ) ;
}
int F_274 ( struct V_24 * V_25 , struct V_133 * V_133 ,
T_12 * V_291 ,
struct V_279 * V_280 )
{
int V_37 ;
struct V_327 V_328 = {
. V_50 = NULL ,
. V_25 = V_25 ,
. V_291 = V_291 ,
. V_332 = 0 ,
. V_353 = V_280 -> V_346 == V_347 ,
. V_219 = 0 ,
} ;
V_37 = F_234 ( V_133 , V_280 , & V_328 ) ;
F_273 ( & V_328 ) ;
return V_37 ;
}
int F_275 ( struct V_24 * V_25 , struct V_26 * V_26 ,
T_1 V_15 , T_1 V_16 , T_12 * V_291 ,
int V_385 )
{
int V_37 = 0 ;
struct V_53 * V_28 = V_26 -> V_134 ;
struct V_133 * V_133 ;
unsigned long V_143 = ( V_16 - V_15 + V_153 ) >>
V_131 ;
struct V_327 V_328 = {
. V_50 = NULL ,
. V_25 = V_25 ,
. V_291 = V_291 ,
. V_332 = 1 ,
. V_353 = V_385 == V_347 ,
. V_219 = 0 ,
} ;
struct V_279 V_386 = {
. V_346 = V_385 ,
. V_321 = V_143 * 2 ,
. V_323 = V_15 ,
. V_324 = V_16 + 1 ,
} ;
while ( V_15 <= V_16 ) {
V_133 = F_111 ( V_28 , V_15 >> V_131 ) ;
if ( F_112 ( V_133 ) )
V_37 = F_234 ( V_133 , & V_386 , & V_328 ) ;
else {
if ( V_25 -> V_55 && V_25 -> V_55 -> V_247 )
V_25 -> V_55 -> V_247 ( V_133 , V_15 ,
V_15 + V_153 - 1 ,
NULL , 1 ) ;
F_125 ( V_133 ) ;
}
F_113 ( V_133 ) ;
V_15 += V_153 ;
}
F_273 ( & V_328 ) ;
return V_37 ;
}
int F_276 ( struct V_24 * V_25 ,
struct V_53 * V_28 ,
T_12 * V_291 ,
struct V_279 * V_280 )
{
int V_37 = 0 ;
struct V_327 V_328 = {
. V_50 = NULL ,
. V_25 = V_25 ,
. V_291 = V_291 ,
. V_332 = 0 ,
. V_353 = V_280 -> V_346 == V_347 ,
. V_219 = 0 ,
} ;
V_37 = F_268 ( V_25 , V_28 , V_280 ,
F_234 , & V_328 ,
F_242 ) ;
F_273 ( & V_328 ) ;
return V_37 ;
}
int F_277 ( struct V_24 * V_25 ,
struct V_53 * V_28 ,
struct V_4 * V_142 , unsigned V_143 ,
T_12 V_291 )
{
struct V_50 * V_50 = NULL ;
unsigned V_387 ;
unsigned long V_219 = 0 ;
struct V_133 * V_388 [ 16 ] ;
struct V_133 * V_133 ;
struct V_214 * V_292 = NULL ;
int V_299 = 0 ;
T_1 V_293 = ( T_1 ) - 1 ;
for ( V_387 = 0 ; V_387 < V_143 ; V_387 ++ ) {
V_133 = F_11 ( V_142 -> V_79 , struct V_133 , V_389 ) ;
F_278 ( & V_133 -> V_7 ) ;
F_8 ( & V_133 -> V_389 ) ;
if ( F_279 ( V_133 , V_28 ,
V_133 -> V_130 , V_129 ) ) {
F_113 ( V_133 ) ;
continue;
}
V_388 [ V_299 ++ ] = V_133 ;
if ( V_299 < F_280 ( V_388 ) )
continue;
F_223 ( V_25 , V_388 , V_299 , V_291 , & V_292 ,
& V_50 , 0 , & V_219 , V_319 , & V_293 ) ;
V_299 = 0 ;
}
if ( V_299 )
F_223 ( V_25 , V_388 , V_299 , V_291 , & V_292 ,
& V_50 , 0 , & V_219 , V_319 , & V_293 ) ;
if ( V_292 )
F_169 ( V_292 ) ;
F_23 ( ! F_10 ( V_142 ) ) ;
if ( V_50 )
return F_193 ( V_319 , V_50 , 0 , V_219 ) ;
return 0 ;
}
int F_281 ( struct V_24 * V_25 ,
struct V_133 * V_133 , unsigned long V_64 )
{
struct V_1 * V_102 = NULL ;
T_1 V_15 = F_142 ( V_133 ) ;
T_1 V_16 = V_15 + V_153 - 1 ;
T_10 V_304 = V_133 -> V_28 -> V_29 -> V_42 -> V_305 ;
V_15 += F_217 ( V_64 , V_304 ) ;
if ( V_15 > V_16 )
return 0 ;
F_105 ( V_25 , V_15 , V_16 , 0 , & V_102 ) ;
F_271 ( V_133 ) ;
F_96 ( V_25 , V_15 , V_16 ,
V_124 | V_98 | V_106 |
V_127 ,
1 , 1 , & V_102 , V_129 ) ;
return 0 ;
}
static int F_282 ( struct V_216 * V_390 ,
struct V_24 * V_25 ,
struct V_133 * V_133 , T_3 V_58 )
{
T_1 V_15 = F_142 ( V_133 ) ;
T_1 V_16 = V_15 + V_153 - 1 ;
int V_37 = 1 ;
if ( F_130 ( V_25 , V_15 , V_16 ,
V_85 , 0 , NULL ) )
V_37 = 0 ;
else {
if ( ( V_58 & V_129 ) == V_129 )
V_58 = V_129 ;
V_37 = F_96 ( V_25 , V_15 , V_16 ,
~ ( V_124 | V_391 ) ,
0 , 0 , NULL , V_58 ) ;
if ( V_37 < 0 )
V_37 = 0 ;
else
V_37 = 1 ;
}
return V_37 ;
}
int F_283 ( struct V_216 * V_390 ,
struct V_24 * V_25 , struct V_133 * V_133 ,
T_3 V_58 )
{
struct V_214 * V_215 ;
T_1 V_15 = F_142 ( V_133 ) ;
T_1 V_16 = V_15 + V_153 - 1 ;
if ( F_74 ( V_58 ) &&
V_133 -> V_28 -> V_29 -> V_262 > 16 * 1024 * 1024 ) {
T_1 V_21 ;
while ( V_15 <= V_16 ) {
V_21 = V_16 - V_15 + 1 ;
F_284 ( & V_390 -> V_57 ) ;
V_215 = F_167 ( V_390 , V_15 , V_21 ) ;
if ( ! V_215 ) {
F_285 ( & V_390 -> V_57 ) ;
break;
}
if ( F_170 ( V_392 , & V_215 -> V_7 ) ||
V_215 -> V_15 != V_15 ) {
F_285 ( & V_390 -> V_57 ) ;
F_169 ( V_215 ) ;
break;
}
if ( ! F_130 ( V_25 , V_215 -> V_15 ,
F_209 ( V_215 ) - 1 ,
V_124 | V_393 ,
0 , NULL ) ) {
F_286 ( V_390 , V_215 ) ;
F_169 ( V_215 ) ;
}
V_15 = F_209 ( V_215 ) ;
F_285 ( & V_390 -> V_57 ) ;
F_169 ( V_215 ) ;
}
}
return F_282 ( V_390 , V_25 , V_133 , V_58 ) ;
}
static struct V_214 * F_287 ( struct V_26 * V_26 ,
T_1 V_64 ,
T_1 V_166 ,
T_12 * V_291 )
{
T_1 V_394 = F_19 ( V_26 ) -> V_31 -> V_394 ;
struct V_214 * V_215 ;
T_1 V_21 ;
if ( V_64 >= V_166 )
return NULL ;
while ( 1 ) {
V_21 = V_166 - V_64 ;
if ( V_21 == 0 )
break;
V_21 = F_217 ( V_21 , V_394 ) ;
V_215 = V_291 ( V_26 , NULL , 0 , V_64 , V_21 , 0 ) ;
if ( F_210 ( V_215 ) )
return V_215 ;
if ( ! F_170 ( V_395 , & V_215 -> V_7 ) &&
V_215 -> V_220 != V_312 ) {
return V_215 ;
}
V_64 = F_209 ( V_215 ) ;
F_169 ( V_215 ) ;
if ( V_64 >= V_166 )
break;
}
return NULL ;
}
int F_288 ( struct V_26 * V_26 , struct V_396 * V_397 ,
T_15 V_15 , T_15 V_21 , T_12 * V_291 )
{
int V_37 = 0 ;
T_1 V_263 = V_15 ;
T_1 F_138 = V_15 + V_21 ;
T_16 V_7 = 0 ;
T_16 V_398 ;
T_1 V_166 ;
T_1 V_399 = 0 ;
T_1 V_400 = 0 ;
T_1 V_27 = F_17 ( V_26 ) ;
struct V_401 V_402 ;
struct V_214 * V_215 = NULL ;
struct V_1 * V_102 = NULL ;
struct V_403 * V_404 ;
struct V_203 * V_31 = F_19 ( V_26 ) -> V_31 ;
int V_16 = 0 ;
T_1 V_405 = 0 ;
T_1 V_406 = 0 ;
T_1 V_343 = 0 ;
if ( V_21 == 0 )
return - V_407 ;
V_404 = F_289 () ;
if ( ! V_404 )
return - V_45 ;
V_404 -> V_408 = 1 ;
V_15 = F_290 ( V_15 , F_19 ( V_26 ) -> V_31 -> V_394 ) ;
V_21 = F_291 ( F_138 , F_19 ( V_26 ) -> V_31 -> V_394 ) - V_15 ;
V_37 = F_292 ( NULL , V_31 , V_404 , F_20 ( V_26 ) , - 1 ,
0 ) ;
if ( V_37 < 0 ) {
F_293 ( V_404 ) ;
return V_37 ;
}
F_45 ( ! V_37 ) ;
V_404 -> V_409 [ 0 ] -- ;
F_294 ( V_404 -> V_410 [ 0 ] , & V_402 , V_404 -> V_409 [ 0 ] ) ;
V_398 = V_402 . type ;
if ( V_402 . V_411 != F_20 ( V_26 ) ||
V_398 != V_412 ) {
V_166 = ( T_1 ) - 1 ;
V_399 = V_27 ;
} else {
V_166 = V_402 . V_64 ;
V_399 = V_166 + 1 ;
}
F_295 ( V_404 ) ;
if ( V_166 < V_27 ) {
V_166 = ( T_1 ) - 1 ;
V_399 = V_27 ;
}
F_105 ( & F_19 ( V_26 ) -> V_156 , V_15 , V_15 + V_21 - 1 , 0 ,
& V_102 ) ;
V_215 = F_287 ( V_26 , V_15 , V_399 ,
V_291 ) ;
if ( ! V_215 )
goto V_111;
if ( F_296 ( V_215 ) ) {
V_37 = F_297 ( V_215 ) ;
goto V_111;
}
while ( ! V_16 ) {
T_1 V_413 = 0 ;
if ( V_215 -> V_15 >= F_138 || F_209 ( V_215 ) < V_263 )
break;
V_405 = F_138 ( V_215 -> V_15 , V_263 ) ;
if ( ! F_170 ( V_221 , & V_215 -> V_7 ) )
V_413 = V_405 - V_215 -> V_15 ;
V_343 = F_209 ( V_215 ) ;
V_406 = V_343 - V_405 ;
V_400 = 0 ;
V_7 = 0 ;
V_263 = F_209 ( V_215 ) ;
if ( V_263 >= F_138 )
V_16 = 1 ;
if ( V_215 -> V_220 == V_414 ) {
V_16 = 1 ;
V_7 |= V_415 ;
} else if ( V_215 -> V_220 == V_314 ) {
V_7 |= ( V_416 |
V_417 ) ;
} else if ( V_215 -> V_220 == V_418 ) {
V_7 |= ( V_419 |
V_420 ) ;
} else if ( V_397 -> V_421 ) {
T_1 V_422 = V_215 -> V_220 -
( V_215 -> V_15 - V_215 -> V_313 ) ;
V_400 = V_215 -> V_220 + V_413 ;
V_37 = F_298 ( NULL , V_31 -> V_32 ,
V_31 -> V_411 ,
F_20 ( V_26 ) , V_422 ) ;
if ( V_37 < 0 )
goto V_423;
if ( V_37 )
V_7 |= V_424 ;
V_37 = 0 ;
}
if ( F_170 ( V_221 , & V_215 -> V_7 ) )
V_7 |= V_425 ;
if ( F_170 ( V_311 , & V_215 -> V_7 ) )
V_7 |= V_426 ;
F_169 ( V_215 ) ;
V_215 = NULL ;
if ( ( V_405 >= V_166 ) || V_406 == ( T_1 ) - 1 ||
( V_166 == ( T_1 ) - 1 && V_27 <= V_343 ) ) {
V_7 |= V_415 ;
V_16 = 1 ;
}
V_215 = F_287 ( V_26 , V_263 , V_399 ,
V_291 ) ;
if ( F_296 ( V_215 ) ) {
V_37 = F_297 ( V_215 ) ;
goto V_111;
}
if ( ! V_215 ) {
V_7 |= V_415 ;
V_16 = 1 ;
}
V_37 = F_299 ( V_397 , V_405 , V_400 ,
V_406 , V_7 ) ;
if ( V_37 ) {
if ( V_37 == 1 )
V_37 = 0 ;
goto V_423;
}
}
V_423:
F_169 ( V_215 ) ;
V_111:
F_293 ( V_404 ) ;
F_108 ( & F_19 ( V_26 ) -> V_156 , V_15 , V_15 + V_21 - 1 ,
& V_102 , V_129 ) ;
return V_37 ;
}
static void F_300 ( struct V_10 * V_11 )
{
F_7 ( & V_11 -> V_14 ) ;
F_14 ( V_22 , V_11 ) ;
}
int F_301 ( struct V_10 * V_11 )
{
return ( F_13 ( & V_11 -> V_367 ) ||
F_170 ( V_351 , & V_11 -> V_350 ) ||
F_170 ( V_355 , & V_11 -> V_350 ) ) ;
}
static void F_302 ( struct V_10 * V_11 )
{
unsigned long V_130 ;
struct V_133 * V_133 ;
int V_427 = ! F_170 ( V_428 , & V_11 -> V_350 ) ;
F_23 ( F_301 ( V_11 ) ) ;
V_130 = F_158 ( V_11 -> V_15 , V_11 -> V_21 ) ;
if ( V_130 == 0 )
return;
do {
V_130 -- ;
V_133 = V_11 -> V_142 [ V_130 ] ;
if ( ! V_133 )
continue;
if ( V_427 )
F_75 ( & V_133 -> V_28 -> V_381 ) ;
if ( F_202 ( V_133 ) &&
V_133 -> V_59 == ( unsigned long ) V_11 ) {
F_23 ( F_170 ( V_355 , & V_11 -> V_350 ) ) ;
F_23 ( F_128 ( V_133 ) ) ;
F_23 ( F_233 ( V_133 ) ) ;
F_303 ( V_133 ) ;
F_205 ( V_133 , 0 ) ;
F_113 ( V_133 ) ;
}
if ( V_427 )
F_78 ( & V_133 -> V_28 -> V_381 ) ;
F_113 ( V_133 ) ;
} while ( V_130 != 0 );
}
static inline void F_304 ( struct V_10 * V_11 )
{
F_302 ( V_11 ) ;
F_300 ( V_11 ) ;
}
static struct V_10 *
F_305 ( struct V_41 * V_32 , T_1 V_15 ,
unsigned long V_21 )
{
struct V_10 * V_11 = NULL ;
V_11 = F_306 ( V_22 , V_129 | V_429 ) ;
V_11 -> V_15 = V_15 ;
V_11 -> V_21 = V_21 ;
V_11 -> V_32 = V_32 ;
V_11 -> V_350 = 0 ;
F_307 ( & V_11 -> V_57 ) ;
F_40 ( & V_11 -> V_430 , 0 ) ;
F_40 ( & V_11 -> V_431 , 0 ) ;
F_40 ( & V_11 -> V_432 , 0 ) ;
F_40 ( & V_11 -> V_433 , 0 ) ;
F_40 ( & V_11 -> V_434 , 0 ) ;
F_40 ( & V_11 -> V_435 , 0 ) ;
V_11 -> V_436 = 0 ;
F_41 ( & V_11 -> V_437 ) ;
F_41 ( & V_11 -> V_438 ) ;
F_3 ( & V_11 -> V_14 , & V_19 ) ;
F_36 ( & V_11 -> V_354 ) ;
F_40 ( & V_11 -> V_17 , 1 ) ;
F_40 ( & V_11 -> V_367 , 0 ) ;
F_308 ( V_439
> V_440 ) ;
F_23 ( V_21 > V_440 ) ;
return V_11 ;
}
struct V_10 * F_309 ( struct V_10 * V_441 )
{
unsigned long V_144 ;
struct V_133 * V_68 ;
struct V_10 * V_5 ;
unsigned long V_204 = F_158 ( V_441 -> V_15 , V_441 -> V_21 ) ;
V_5 = F_305 ( V_441 -> V_32 , V_441 -> V_15 , V_441 -> V_21 ) ;
if ( V_5 == NULL )
return NULL ;
for ( V_144 = 0 ; V_144 < V_204 ; V_144 ++ ) {
V_68 = F_310 ( V_129 ) ;
if ( ! V_68 ) {
F_304 ( V_5 ) ;
return NULL ;
}
F_201 ( V_5 , V_68 ) ;
F_45 ( F_128 ( V_68 ) ) ;
F_143 ( V_68 ) ;
V_5 -> V_142 [ V_144 ] = V_68 ;
}
F_311 ( V_5 , V_441 , 0 , 0 , V_441 -> V_21 ) ;
F_246 ( V_442 , & V_5 -> V_350 ) ;
F_246 ( V_428 , & V_5 -> V_350 ) ;
return V_5 ;
}
struct V_10 * F_312 ( struct V_41 * V_32 ,
T_1 V_15 )
{
struct V_10 * V_11 ;
unsigned long V_21 ;
unsigned long V_204 ;
unsigned long V_144 ;
if ( ! V_32 ) {
V_21 = 4096 ;
} else {
V_21 = V_32 -> V_443 -> V_444 ;
}
V_204 = F_158 ( 0 , V_21 ) ;
V_11 = F_305 ( V_32 , V_15 , V_21 ) ;
if ( ! V_11 )
return NULL ;
for ( V_144 = 0 ; V_144 < V_204 ; V_144 ++ ) {
V_11 -> V_142 [ V_144 ] = F_310 ( V_129 ) ;
if ( ! V_11 -> V_142 [ V_144 ] )
goto V_100;
}
F_313 ( V_11 ) ;
F_314 ( V_11 , 0 ) ;
F_246 ( V_428 , & V_11 -> V_350 ) ;
return V_11 ;
V_100:
for (; V_144 > 0 ; V_144 -- )
F_315 ( V_11 -> V_142 [ V_144 - 1 ] ) ;
F_300 ( V_11 ) ;
return NULL ;
}
static void F_316 ( struct V_10 * V_11 )
{
int V_17 ;
V_17 = F_13 ( & V_11 -> V_17 ) ;
if ( V_17 >= 2 && F_170 ( V_445 , & V_11 -> V_350 ) )
return;
F_75 ( & V_11 -> V_354 ) ;
if ( ! F_255 ( V_445 , & V_11 -> V_350 ) )
F_86 ( & V_11 -> V_17 ) ;
F_78 ( & V_11 -> V_354 ) ;
}
static void F_317 ( struct V_10 * V_11 ,
struct V_133 * V_446 )
{
unsigned long V_204 , V_144 ;
F_316 ( V_11 ) ;
V_204 = F_158 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_144 = 0 ; V_144 < V_204 ; V_144 ++ ) {
struct V_133 * V_68 = V_11 -> V_142 [ V_144 ] ;
if ( V_68 != V_446 )
F_318 ( V_68 ) ;
}
}
struct V_10 * F_319 ( struct V_41 * V_32 ,
T_1 V_15 )
{
struct V_10 * V_11 ;
F_320 () ;
V_11 = F_321 ( & V_32 -> V_447 ,
V_15 >> V_131 ) ;
if ( V_11 && F_265 ( & V_11 -> V_17 ) ) {
F_322 () ;
if ( F_170 ( V_448 , & V_11 -> V_350 ) ) {
F_75 ( & V_11 -> V_354 ) ;
F_78 ( & V_11 -> V_354 ) ;
}
F_317 ( V_11 , NULL ) ;
return V_11 ;
}
F_322 () ;
return NULL ;
}
struct V_10 * F_323 ( struct V_41 * V_32 ,
T_1 V_15 )
{
struct V_10 * V_11 , * V_449 = NULL ;
int V_37 ;
V_11 = F_319 ( V_32 , V_15 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_312 ( V_32 , V_15 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_32 = V_32 ;
V_109:
V_37 = F_324 ( V_129 & ~ V_450 ) ;
if ( V_37 )
goto V_451;
F_75 ( & V_32 -> V_452 ) ;
V_37 = F_325 ( & V_32 -> V_447 ,
V_15 >> V_131 , V_11 ) ;
F_78 ( & V_32 -> V_452 ) ;
F_326 () ;
if ( V_37 == - V_90 ) {
V_449 = F_319 ( V_32 , V_15 ) ;
if ( V_449 )
goto V_451;
else
goto V_109;
}
F_316 ( V_11 ) ;
F_246 ( V_453 , & V_11 -> V_350 ) ;
F_86 ( & V_11 -> V_17 ) ;
return V_11 ;
V_451:
F_304 ( V_11 ) ;
return V_449 ;
}
struct V_10 * F_327 ( struct V_41 * V_32 ,
T_1 V_15 )
{
unsigned long V_21 = V_32 -> V_443 -> V_444 ;
unsigned long V_204 = F_158 ( V_15 , V_21 ) ;
unsigned long V_144 ;
unsigned long V_130 = V_15 >> V_131 ;
struct V_10 * V_11 ;
struct V_10 * V_449 = NULL ;
struct V_133 * V_68 ;
struct V_53 * V_28 = V_32 -> V_206 -> V_134 ;
int V_246 = 1 ;
int V_37 ;
V_11 = F_319 ( V_32 , V_15 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_305 ( V_32 , V_15 , V_21 ) ;
if ( ! V_11 )
return NULL ;
for ( V_144 = 0 ; V_144 < V_204 ; V_144 ++ , V_130 ++ ) {
V_68 = F_328 ( V_28 , V_130 , V_129 | V_429 ) ;
if ( ! V_68 )
goto V_451;
F_75 ( & V_28 -> V_381 ) ;
if ( F_202 ( V_68 ) ) {
V_449 = (struct V_10 * ) V_68 -> V_59 ;
if ( F_265 ( & V_449 -> V_17 ) ) {
F_78 ( & V_28 -> V_381 ) ;
F_125 ( V_68 ) ;
F_113 ( V_68 ) ;
F_317 ( V_449 , V_68 ) ;
goto V_451;
}
V_449 = NULL ;
F_303 ( V_68 ) ;
F_45 ( F_128 ( V_68 ) ) ;
F_113 ( V_68 ) ;
}
F_201 ( V_11 , V_68 ) ;
F_78 ( & V_28 -> V_381 ) ;
F_45 ( F_128 ( V_68 ) ) ;
V_11 -> V_142 [ V_144 ] = V_68 ;
if ( ! F_212 ( V_68 ) )
V_246 = 0 ;
}
if ( V_246 )
F_246 ( V_442 , & V_11 -> V_350 ) ;
V_109:
V_37 = F_324 ( V_129 & ~ V_450 ) ;
if ( V_37 )
goto V_451;
F_75 ( & V_32 -> V_452 ) ;
V_37 = F_325 ( & V_32 -> V_447 ,
V_15 >> V_131 , V_11 ) ;
F_78 ( & V_32 -> V_452 ) ;
F_326 () ;
if ( V_37 == - V_90 ) {
V_449 = F_319 ( V_32 , V_15 ) ;
if ( V_449 )
goto V_451;
else
goto V_109;
}
F_316 ( V_11 ) ;
F_246 ( V_453 , & V_11 -> V_350 ) ;
F_329 ( V_11 -> V_142 [ 0 ] ) ;
for ( V_144 = 1 ; V_144 < V_204 ; V_144 ++ ) {
V_68 = V_11 -> V_142 [ V_144 ] ;
F_330 ( V_68 ) ;
F_125 ( V_68 ) ;
}
F_125 ( V_11 -> V_142 [ 0 ] ) ;
return V_11 ;
V_451:
F_45 ( ! F_44 ( & V_11 -> V_17 ) ) ;
for ( V_144 = 0 ; V_144 < V_204 ; V_144 ++ ) {
if ( V_11 -> V_142 [ V_144 ] )
F_125 ( V_11 -> V_142 [ V_144 ] ) ;
}
F_304 ( V_11 ) ;
return V_449 ;
}
static inline void F_331 ( struct V_454 * V_6 )
{
struct V_10 * V_11 =
F_332 ( V_6 , struct V_10 , V_454 ) ;
F_300 ( V_11 ) ;
}
static int F_333 ( struct V_10 * V_11 )
{
F_45 ( F_13 ( & V_11 -> V_17 ) == 0 ) ;
if ( F_44 ( & V_11 -> V_17 ) ) {
if ( F_245 ( V_453 , & V_11 -> V_350 ) ) {
struct V_41 * V_32 = V_11 -> V_32 ;
F_78 ( & V_11 -> V_354 ) ;
F_75 ( & V_32 -> V_452 ) ;
F_334 ( & V_32 -> V_447 ,
V_11 -> V_15 >> V_131 ) ;
F_78 ( & V_32 -> V_452 ) ;
} else {
F_78 ( & V_11 -> V_354 ) ;
}
F_302 ( V_11 ) ;
#ifdef F_335
if ( F_186 ( F_170 ( V_428 , & V_11 -> V_350 ) ) ) {
F_300 ( V_11 ) ;
return 1 ;
}
#endif
F_336 ( & V_11 -> V_454 , F_331 ) ;
return 1 ;
}
F_78 ( & V_11 -> V_354 ) ;
return 0 ;
}
void F_266 ( struct V_10 * V_11 )
{
int V_17 ;
int V_455 ;
if ( ! V_11 )
return;
while ( 1 ) {
V_17 = F_13 ( & V_11 -> V_17 ) ;
if ( V_17 <= 3 )
break;
V_455 = F_337 ( & V_11 -> V_17 , V_17 , V_17 - 1 ) ;
if ( V_455 == V_17 )
return;
}
F_75 ( & V_11 -> V_354 ) ;
if ( F_13 ( & V_11 -> V_17 ) == 2 &&
F_170 ( V_428 , & V_11 -> V_350 ) )
F_76 ( & V_11 -> V_17 ) ;
if ( F_13 ( & V_11 -> V_17 ) == 2 &&
F_170 ( V_448 , & V_11 -> V_350 ) &&
! F_301 ( V_11 ) &&
F_245 ( V_445 , & V_11 -> V_350 ) )
F_76 ( & V_11 -> V_17 ) ;
F_333 ( V_11 ) ;
}
void F_338 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return;
F_75 ( & V_11 -> V_354 ) ;
F_246 ( V_448 , & V_11 -> V_350 ) ;
if ( F_13 ( & V_11 -> V_17 ) == 2 && ! F_301 ( V_11 ) &&
F_245 ( V_445 , & V_11 -> V_350 ) )
F_76 ( & V_11 -> V_17 ) ;
F_333 ( V_11 ) ;
}
void F_339 ( struct V_10 * V_11 )
{
unsigned long V_144 ;
unsigned long V_204 ;
struct V_133 * V_133 ;
V_204 = F_158 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_144 = 0 ; V_144 < V_204 ; V_144 ++ ) {
V_133 = V_11 -> V_142 [ V_144 ] ;
if ( ! F_128 ( V_133 ) )
continue;
F_127 ( V_133 ) ;
F_45 ( ! F_202 ( V_133 ) ) ;
F_112 ( V_133 ) ;
F_340 ( & V_133 -> V_28 -> V_456 ) ;
if ( ! F_128 ( V_133 ) ) {
F_341 ( & V_133 -> V_28 -> V_457 ,
F_342 ( V_133 ) ,
V_378 ) ;
}
F_343 ( & V_133 -> V_28 -> V_456 ) ;
F_237 ( V_133 ) ;
F_125 ( V_133 ) ;
}
F_45 ( F_13 ( & V_11 -> V_17 ) == 0 ) ;
}
int F_344 ( struct V_10 * V_11 )
{
unsigned long V_144 ;
unsigned long V_204 ;
int V_458 = 0 ;
F_316 ( V_11 ) ;
V_458 = F_255 ( V_355 , & V_11 -> V_350 ) ;
V_204 = F_158 ( V_11 -> V_15 , V_11 -> V_21 ) ;
F_45 ( F_13 ( & V_11 -> V_17 ) == 0 ) ;
F_45 ( ! F_170 ( V_445 , & V_11 -> V_350 ) ) ;
for ( V_144 = 0 ; V_144 < V_204 ; V_144 ++ )
F_345 ( V_11 -> V_142 [ V_144 ] ) ;
return V_458 ;
}
int F_346 ( struct V_10 * V_11 )
{
unsigned long V_144 ;
struct V_133 * V_133 ;
unsigned long V_204 ;
F_251 ( V_442 , & V_11 -> V_350 ) ;
V_204 = F_158 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_144 = 0 ; V_144 < V_204 ; V_144 ++ ) {
V_133 = V_11 -> V_142 [ V_144 ] ;
if ( V_133 )
F_177 ( V_133 ) ;
}
return 0 ;
}
int F_313 ( struct V_10 * V_11 )
{
unsigned long V_144 ;
struct V_133 * V_133 ;
unsigned long V_204 ;
F_246 ( V_442 , & V_11 -> V_350 ) ;
V_204 = F_158 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_144 = 0 ; V_144 < V_204 ; V_144 ++ ) {
V_133 = V_11 -> V_142 [ V_144 ] ;
F_143 ( V_133 ) ;
}
return 0 ;
}
int F_347 ( struct V_10 * V_11 )
{
return F_170 ( V_442 , & V_11 -> V_350 ) ;
}
int F_348 ( struct V_24 * V_25 ,
struct V_10 * V_11 , T_1 V_15 , int V_113 ,
T_12 * V_291 , int V_178 )
{
unsigned long V_144 ;
unsigned long V_459 ;
struct V_133 * V_133 ;
int V_100 ;
int V_37 = 0 ;
int V_460 = 0 ;
int V_461 = 1 ;
unsigned long V_204 ;
unsigned long V_462 = 0 ;
struct V_50 * V_50 = NULL ;
unsigned long V_219 = 0 ;
if ( F_170 ( V_442 , & V_11 -> V_350 ) )
return 0 ;
if ( V_15 ) {
F_45 ( V_15 < V_11 -> V_15 ) ;
V_459 = ( V_15 >> V_131 ) -
( V_11 -> V_15 >> V_131 ) ;
} else {
V_459 = 0 ;
}
V_204 = F_158 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_144 = V_459 ; V_144 < V_204 ; V_144 ++ ) {
V_133 = V_11 -> V_142 [ V_144 ] ;
if ( V_113 == V_463 ) {
if ( ! F_249 ( V_133 ) )
goto V_464;
} else {
F_127 ( V_133 ) ;
}
V_460 ++ ;
if ( ! F_212 ( V_133 ) ) {
V_462 ++ ;
V_461 = 0 ;
}
}
if ( V_461 ) {
if ( V_459 == 0 )
F_246 ( V_442 , & V_11 -> V_350 ) ;
goto V_464;
}
F_251 ( V_465 , & V_11 -> V_350 ) ;
V_11 -> V_466 = 0 ;
F_40 ( & V_11 -> V_367 , V_462 ) ;
for ( V_144 = V_459 ; V_144 < V_204 ; V_144 ++ ) {
V_133 = V_11 -> V_142 [ V_144 ] ;
if ( ! F_212 ( V_133 ) ) {
F_237 ( V_133 ) ;
V_100 = F_224 ( V_25 , V_133 ,
V_291 , & V_50 ,
V_178 , & V_219 ,
V_319 | V_368 ) ;
if ( V_100 )
V_37 = V_100 ;
} else {
F_125 ( V_133 ) ;
}
}
if ( V_50 ) {
V_100 = F_193 ( V_319 | V_368 , V_50 , V_178 ,
V_219 ) ;
if ( V_100 )
return V_100 ;
}
if ( V_37 || V_113 != V_467 )
return V_37 ;
for ( V_144 = V_459 ; V_144 < V_204 ; V_144 ++ ) {
V_133 = V_11 -> V_142 [ V_144 ] ;
F_349 ( V_133 ) ;
if ( ! F_212 ( V_133 ) )
V_37 = - V_158 ;
}
return V_37 ;
V_464:
V_144 = V_459 ;
while ( V_460 > 0 ) {
V_133 = V_11 -> V_142 [ V_144 ] ;
V_144 ++ ;
F_125 ( V_133 ) ;
V_460 -- ;
}
return V_37 ;
}
void F_350 ( struct V_10 * V_11 , void * V_468 ,
unsigned long V_15 ,
unsigned long V_21 )
{
T_10 V_295 ;
T_10 V_64 ;
struct V_133 * V_133 ;
char * V_469 ;
char * V_470 = ( char * ) V_468 ;
T_10 V_471 = V_11 -> V_15 & ( ( T_1 ) V_153 - 1 ) ;
unsigned long V_144 = ( V_471 + V_15 ) >> V_131 ;
F_45 ( V_15 > V_11 -> V_21 ) ;
F_45 ( V_15 + V_21 > V_11 -> V_15 + V_11 -> V_21 ) ;
V_64 = ( V_471 + V_15 ) & ( V_153 - 1 ) ;
while ( V_21 > 0 ) {
V_133 = V_11 -> V_142 [ V_144 ] ;
V_295 = F_137 ( V_21 , ( V_153 - V_64 ) ) ;
V_469 = F_351 ( V_133 ) ;
memcpy ( V_470 , V_469 + V_64 , V_295 ) ;
V_470 += V_295 ;
V_21 -= V_295 ;
V_64 = 0 ;
V_144 ++ ;
}
}
int F_352 ( struct V_10 * V_11 , void T_17 * V_468 ,
unsigned long V_15 ,
unsigned long V_21 )
{
T_10 V_295 ;
T_10 V_64 ;
struct V_133 * V_133 ;
char * V_469 ;
char T_17 * V_470 = ( char T_17 * ) V_468 ;
T_10 V_471 = V_11 -> V_15 & ( ( T_1 ) V_153 - 1 ) ;
unsigned long V_144 = ( V_471 + V_15 ) >> V_131 ;
int V_37 = 0 ;
F_45 ( V_15 > V_11 -> V_21 ) ;
F_45 ( V_15 + V_21 > V_11 -> V_15 + V_11 -> V_21 ) ;
V_64 = ( V_471 + V_15 ) & ( V_153 - 1 ) ;
while ( V_21 > 0 ) {
V_133 = V_11 -> V_142 [ V_144 ] ;
V_295 = F_137 ( V_21 , ( V_153 - V_64 ) ) ;
V_469 = F_351 ( V_133 ) ;
if ( F_353 ( V_470 , V_469 + V_64 , V_295 ) ) {
V_37 = - V_472 ;
break;
}
V_470 += V_295 ;
V_21 -= V_295 ;
V_64 = 0 ;
V_144 ++ ;
}
return V_37 ;
}
int F_354 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_473 , char * * V_390 ,
unsigned long * V_474 ,
unsigned long * V_475 )
{
T_10 V_64 = V_15 & ( V_153 - 1 ) ;
char * V_469 ;
struct V_133 * V_68 ;
T_10 V_471 = V_11 -> V_15 & ( ( T_1 ) V_153 - 1 ) ;
unsigned long V_144 = ( V_471 + V_15 ) >> V_131 ;
unsigned long V_476 = ( V_471 + V_15 + V_473 - 1 ) >>
V_131 ;
if ( V_144 != V_476 )
return - V_407 ;
if ( V_144 == 0 ) {
V_64 = V_471 ;
* V_474 = 0 ;
} else {
V_64 = 0 ;
* V_474 = ( ( T_1 ) V_144 << V_131 ) - V_471 ;
}
if ( V_15 + V_473 > V_11 -> V_21 ) {
F_62 ( 1 , V_20 L_28
L_29 ,
V_11 -> V_15 , V_11 -> V_21 , V_15 , V_473 ) ;
return - V_407 ;
}
V_68 = V_11 -> V_142 [ V_144 ] ;
V_469 = F_351 ( V_68 ) ;
* V_390 = V_469 + V_64 ;
* V_475 = V_153 - V_64 ;
return 0 ;
}
int F_355 ( struct V_10 * V_11 , const void * V_477 ,
unsigned long V_15 ,
unsigned long V_21 )
{
T_10 V_295 ;
T_10 V_64 ;
struct V_133 * V_133 ;
char * V_469 ;
char * V_478 = ( char * ) V_477 ;
T_10 V_471 = V_11 -> V_15 & ( ( T_1 ) V_153 - 1 ) ;
unsigned long V_144 = ( V_471 + V_15 ) >> V_131 ;
int V_37 = 0 ;
F_45 ( V_15 > V_11 -> V_21 ) ;
F_45 ( V_15 + V_21 > V_11 -> V_15 + V_11 -> V_21 ) ;
V_64 = ( V_471 + V_15 ) & ( V_153 - 1 ) ;
while ( V_21 > 0 ) {
V_133 = V_11 -> V_142 [ V_144 ] ;
V_295 = F_137 ( V_21 , ( V_153 - V_64 ) ) ;
V_469 = F_351 ( V_133 ) ;
V_37 = memcmp ( V_478 , V_469 + V_64 , V_295 ) ;
if ( V_37 )
break;
V_478 += V_295 ;
V_21 -= V_295 ;
V_64 = 0 ;
V_144 ++ ;
}
return V_37 ;
}
void F_356 ( struct V_10 * V_11 , const void * V_479 ,
unsigned long V_15 , unsigned long V_21 )
{
T_10 V_295 ;
T_10 V_64 ;
struct V_133 * V_133 ;
char * V_469 ;
char * V_441 = ( char * ) V_479 ;
T_10 V_471 = V_11 -> V_15 & ( ( T_1 ) V_153 - 1 ) ;
unsigned long V_144 = ( V_471 + V_15 ) >> V_131 ;
F_45 ( V_15 > V_11 -> V_21 ) ;
F_45 ( V_15 + V_21 > V_11 -> V_15 + V_11 -> V_21 ) ;
V_64 = ( V_471 + V_15 ) & ( V_153 - 1 ) ;
while ( V_21 > 0 ) {
V_133 = V_11 -> V_142 [ V_144 ] ;
F_45 ( ! F_212 ( V_133 ) ) ;
V_295 = F_137 ( V_21 , V_153 - V_64 ) ;
V_469 = F_351 ( V_133 ) ;
memcpy ( V_469 + V_64 , V_441 , V_295 ) ;
V_441 += V_295 ;
V_21 -= V_295 ;
V_64 = 0 ;
V_144 ++ ;
}
}
void F_357 ( struct V_10 * V_11 , char V_480 ,
unsigned long V_15 , unsigned long V_21 )
{
T_10 V_295 ;
T_10 V_64 ;
struct V_133 * V_133 ;
char * V_469 ;
T_10 V_471 = V_11 -> V_15 & ( ( T_1 ) V_153 - 1 ) ;
unsigned long V_144 = ( V_471 + V_15 ) >> V_131 ;
F_45 ( V_15 > V_11 -> V_21 ) ;
F_45 ( V_15 + V_21 > V_11 -> V_15 + V_11 -> V_21 ) ;
V_64 = ( V_471 + V_15 ) & ( V_153 - 1 ) ;
while ( V_21 > 0 ) {
V_133 = V_11 -> V_142 [ V_144 ] ;
F_45 ( ! F_212 ( V_133 ) ) ;
V_295 = F_137 ( V_21 , V_153 - V_64 ) ;
V_469 = F_351 ( V_133 ) ;
memset ( V_469 + V_64 , V_480 , V_295 ) ;
V_21 -= V_295 ;
V_64 = 0 ;
V_144 ++ ;
}
}
void F_311 ( struct V_10 * V_470 , struct V_10 * V_441 ,
unsigned long V_481 , unsigned long V_482 ,
unsigned long V_21 )
{
T_1 V_483 = V_470 -> V_21 ;
T_10 V_295 ;
T_10 V_64 ;
struct V_133 * V_133 ;
char * V_469 ;
T_10 V_471 = V_470 -> V_15 & ( ( T_1 ) V_153 - 1 ) ;
unsigned long V_144 = ( V_471 + V_481 ) >> V_131 ;
F_45 ( V_441 -> V_21 != V_483 ) ;
V_64 = ( V_471 + V_481 ) &
( V_153 - 1 ) ;
while ( V_21 > 0 ) {
V_133 = V_470 -> V_142 [ V_144 ] ;
F_45 ( ! F_212 ( V_133 ) ) ;
V_295 = F_137 ( V_21 , ( unsigned long ) ( V_153 - V_64 ) ) ;
V_469 = F_351 ( V_133 ) ;
F_350 ( V_441 , V_469 + V_64 , V_482 , V_295 ) ;
V_482 += V_295 ;
V_21 -= V_295 ;
V_64 = 0 ;
V_144 ++ ;
}
}
static inline bool F_358 ( unsigned long V_441 , unsigned long V_470 , unsigned long V_21 )
{
unsigned long V_484 = ( V_441 > V_470 ) ? V_441 - V_470 : V_470 - V_441 ;
return V_484 < V_21 ;
}
static void F_359 ( struct V_133 * V_485 , struct V_133 * V_486 ,
unsigned long V_487 , unsigned long V_488 ,
unsigned long V_21 )
{
char * V_489 = F_351 ( V_485 ) ;
char * V_490 ;
int V_491 = 0 ;
if ( V_485 != V_486 ) {
V_490 = F_351 ( V_486 ) ;
} else {
V_490 = V_489 ;
if ( F_358 ( V_488 , V_487 , V_21 ) )
V_491 = 1 ;
}
if ( V_491 )
memmove ( V_489 + V_487 , V_490 + V_488 , V_21 ) ;
else
memcpy ( V_489 + V_487 , V_490 + V_488 , V_21 ) ;
}
void F_360 ( struct V_10 * V_470 , unsigned long V_481 ,
unsigned long V_482 , unsigned long V_21 )
{
T_10 V_295 ;
T_10 V_492 ;
T_10 V_493 ;
T_10 V_471 = V_470 -> V_15 & ( ( T_1 ) V_153 - 1 ) ;
unsigned long V_494 ;
unsigned long V_495 ;
if ( V_482 + V_21 > V_470 -> V_21 ) {
F_180 ( V_470 -> V_32 ,
L_30
L_31 , V_482 , V_21 , V_470 -> V_21 ) ;
F_23 ( 1 ) ;
}
if ( V_481 + V_21 > V_470 -> V_21 ) {
F_180 ( V_470 -> V_32 ,
L_32
L_31 , V_481 , V_21 , V_470 -> V_21 ) ;
F_23 ( 1 ) ;
}
while ( V_21 > 0 ) {
V_492 = ( V_471 + V_481 ) &
( V_153 - 1 ) ;
V_493 = ( V_471 + V_482 ) &
( V_153 - 1 ) ;
V_494 = ( V_471 + V_481 ) >> V_131 ;
V_495 = ( V_471 + V_482 ) >> V_131 ;
V_295 = F_137 ( V_21 , ( unsigned long ) ( V_153 -
V_493 ) ) ;
V_295 = F_124 (unsigned long, cur,
(unsigned long)(PAGE_CACHE_SIZE - dst_off_in_page)) ;
F_359 ( V_470 -> V_142 [ V_494 ] , V_470 -> V_142 [ V_495 ] ,
V_492 , V_493 , V_295 ) ;
V_482 += V_295 ;
V_481 += V_295 ;
V_21 -= V_295 ;
}
}
void F_361 ( struct V_10 * V_470 , unsigned long V_481 ,
unsigned long V_482 , unsigned long V_21 )
{
T_10 V_295 ;
T_10 V_492 ;
T_10 V_493 ;
unsigned long V_496 = V_481 + V_21 - 1 ;
unsigned long V_497 = V_482 + V_21 - 1 ;
T_10 V_471 = V_470 -> V_15 & ( ( T_1 ) V_153 - 1 ) ;
unsigned long V_494 ;
unsigned long V_495 ;
if ( V_482 + V_21 > V_470 -> V_21 ) {
F_180 ( V_470 -> V_32 , L_30
L_33 , V_482 , V_21 , V_470 -> V_21 ) ;
F_23 ( 1 ) ;
}
if ( V_481 + V_21 > V_470 -> V_21 ) {
F_180 ( V_470 -> V_32 , L_32
L_33 , V_481 , V_21 , V_470 -> V_21 ) ;
F_23 ( 1 ) ;
}
if ( V_481 < V_482 ) {
F_360 ( V_470 , V_481 , V_482 , V_21 ) ;
return;
}
while ( V_21 > 0 ) {
V_494 = ( V_471 + V_496 ) >> V_131 ;
V_495 = ( V_471 + V_497 ) >> V_131 ;
V_492 = ( V_471 + V_496 ) &
( V_153 - 1 ) ;
V_493 = ( V_471 + V_497 ) &
( V_153 - 1 ) ;
V_295 = F_124 (unsigned long, len, src_off_in_page + 1 ) ;
V_295 = F_137 ( V_295 , V_492 + 1 ) ;
F_359 ( V_470 -> V_142 [ V_494 ] , V_470 -> V_142 [ V_495 ] ,
V_492 - V_295 + 1 ,
V_493 - V_295 + 1 , V_295 ) ;
V_496 -= V_295 ;
V_497 -= V_295 ;
V_21 -= V_295 ;
}
}
int F_362 ( struct V_133 * V_133 )
{
struct V_10 * V_11 ;
F_75 ( & V_133 -> V_28 -> V_381 ) ;
if ( ! F_202 ( V_133 ) ) {
F_78 ( & V_133 -> V_28 -> V_381 ) ;
return 1 ;
}
V_11 = (struct V_10 * ) V_133 -> V_59 ;
F_23 ( ! V_11 ) ;
F_75 ( & V_11 -> V_354 ) ;
if ( F_13 ( & V_11 -> V_17 ) != 1 || F_301 ( V_11 ) ) {
F_78 ( & V_11 -> V_354 ) ;
F_78 ( & V_133 -> V_28 -> V_381 ) ;
return 0 ;
}
F_78 ( & V_133 -> V_28 -> V_381 ) ;
if ( ! F_245 ( V_445 , & V_11 -> V_350 ) ) {
F_78 ( & V_11 -> V_354 ) ;
return 0 ;
}
return F_333 ( V_11 ) ;
}
