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
unsigned V_33 , T_3 V_58 ,
struct V_34 * V_35 )
{
F_23 ( V_33 & V_124 ) ;
return F_90 ( V_25 , V_15 , V_16 , V_33 , 0 , NULL , NULL , V_58 ,
V_35 ) ;
}
int F_94 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned V_33 , int V_95 , int V_101 ,
struct V_1 * * V_103 , T_3 V_58 )
{
return F_72 ( V_25 , V_15 , V_16 , V_33 , V_95 , V_101 ,
V_103 , V_58 , NULL ) ;
}
int F_95 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned V_33 , T_3 V_58 ,
struct V_34 * V_35 )
{
F_23 ( V_33 & V_124 ) ;
return F_72 ( V_25 , V_15 , V_16 , V_33 , 0 , 0 , NULL , V_58 ,
V_35 ) ;
}
int F_96 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
struct V_1 * * V_102 )
{
int V_100 ;
T_1 V_119 ;
while ( 1 ) {
V_100 = F_90 ( V_25 , V_15 , V_16 , V_124 ,
V_124 , & V_119 ,
V_102 , V_125 , NULL ) ;
if ( V_100 == - V_90 ) {
F_85 ( V_25 , V_119 , V_16 , V_124 ) ;
V_15 = V_119 ;
} else
break;
F_45 ( V_15 > V_16 ) ;
}
return V_100 ;
}
int F_97 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 )
{
int V_100 ;
T_1 V_119 ;
V_100 = F_90 ( V_25 , V_15 , V_16 , V_124 , V_124 ,
& V_119 , NULL , V_125 , NULL ) ;
if ( V_100 == - V_90 ) {
if ( V_119 > V_15 )
F_94 ( V_25 , V_15 , V_119 - 1 ,
V_124 , 1 , 0 , NULL , V_125 ) ;
return 0 ;
}
return 1 ;
}
void F_98 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_126 = V_15 >> V_127 ;
unsigned long V_128 = V_16 >> V_127 ;
struct V_129 * V_129 ;
while ( V_126 <= V_128 ) {
V_129 = F_99 ( V_26 -> V_130 , V_126 ) ;
F_23 ( ! V_129 ) ;
F_100 ( V_129 ) ;
F_101 ( V_129 ) ;
V_126 ++ ;
}
}
void F_102 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_126 = V_15 >> V_127 ;
unsigned long V_128 = V_16 >> V_127 ;
struct V_129 * V_129 ;
while ( V_126 <= V_128 ) {
V_129 = F_99 ( V_26 -> V_130 , V_126 ) ;
F_23 ( ! V_129 ) ;
F_103 ( V_129 ) ;
F_104 ( V_129 ) ;
F_101 ( V_129 ) ;
V_126 ++ ;
}
}
static void F_105 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_126 = V_15 >> V_127 ;
unsigned long V_128 = V_16 >> V_127 ;
struct V_129 * V_129 ;
while ( V_126 <= V_128 ) {
V_129 = F_99 ( V_25 -> V_28 , V_126 ) ;
F_23 ( ! V_129 ) ;
F_106 ( V_129 ) ;
F_101 ( V_129 ) ;
V_126 ++ ;
}
}
static struct V_1 *
F_107 ( struct V_24 * V_25 ,
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
int F_108 ( struct V_24 * V_25 , T_1 V_15 ,
T_1 * V_131 , T_1 * V_132 , unsigned V_33 ,
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
goto V_133;
V_78 = F_52 ( V_78 ) ;
}
F_43 ( * V_102 ) ;
* V_102 = NULL ;
goto V_111;
}
F_43 ( * V_102 ) ;
* V_102 = NULL ;
}
V_2 = F_107 ( V_25 , V_15 , V_33 ) ;
V_133:
if ( V_2 ) {
F_88 ( V_2 , V_102 , 0 ) ;
* V_131 = V_2 -> V_15 ;
* V_132 = V_2 -> V_16 ;
V_37 = 0 ;
}
V_111:
F_78 ( & V_25 -> V_57 ) ;
return V_37 ;
}
static T_5 T_1 F_109 ( struct V_24 * V_25 ,
T_1 * V_15 , T_1 * V_16 , T_1 V_134 ,
struct V_1 * * V_102 )
{
struct V_3 * V_65 ;
struct V_1 * V_2 ;
T_1 V_135 = * V_15 ;
T_1 V_89 = 0 ;
T_1 V_136 = 0 ;
F_75 ( & V_25 -> V_57 ) ;
V_65 = F_55 ( V_25 , V_135 ) ;
if ( ! V_65 ) {
if ( ! V_89 )
* V_16 = ( T_1 ) - 1 ;
goto V_111;
}
while ( 1 ) {
V_2 = F_48 ( V_65 , struct V_1 , V_3 ) ;
if ( V_89 && ( V_2 -> V_15 != V_135 ||
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
V_135 = V_2 -> V_16 + 1 ;
V_65 = F_52 ( V_65 ) ;
V_136 += V_2 -> V_16 - V_2 -> V_15 + 1 ;
if ( V_136 >= V_134 )
break;
if ( ! V_65 )
break;
}
V_111:
F_78 ( & V_25 -> V_57 ) ;
return V_89 ;
}
static T_5 void F_110 ( struct V_26 * V_26 ,
struct V_129 * V_137 ,
T_1 V_15 , T_1 V_16 )
{
int V_37 ;
struct V_129 * V_138 [ 16 ] ;
unsigned long V_126 = V_15 >> V_127 ;
unsigned long V_128 = V_16 >> V_127 ;
unsigned long V_139 = V_128 - V_126 + 1 ;
int V_140 ;
if ( V_126 == V_137 -> V_126 && V_128 == V_126 )
return;
while ( V_139 > 0 ) {
V_37 = F_111 ( V_26 -> V_130 , V_126 ,
F_112 (unsigned long, nr_pages,
ARRAY_SIZE(pages)) , V_138 ) ;
for ( V_140 = 0 ; V_140 < V_37 ; V_140 ++ ) {
if ( V_138 [ V_140 ] != V_137 )
F_113 ( V_138 [ V_140 ] ) ;
F_101 ( V_138 [ V_140 ] ) ;
}
V_139 -= V_37 ;
V_126 += V_37 ;
F_79 () ;
}
}
static T_5 int F_114 ( struct V_26 * V_26 ,
struct V_129 * V_137 ,
T_1 V_141 ,
T_1 V_142 )
{
unsigned long V_126 = V_141 >> V_127 ;
unsigned long V_143 = V_126 ;
unsigned long V_128 = V_142 >> V_127 ;
unsigned long V_144 = 0 ;
struct V_129 * V_138 [ 16 ] ;
unsigned long V_145 ;
int V_37 ;
int V_140 ;
if ( V_126 == V_137 -> V_126 && V_126 == V_128 )
return 0 ;
V_145 = V_128 - V_126 + 1 ;
while ( V_145 > 0 ) {
V_37 = F_111 ( V_26 -> V_130 , V_126 ,
F_112 (unsigned long,
nrpages, ARRAY_SIZE(pages)) , V_138 ) ;
if ( V_37 == 0 ) {
V_37 = - V_146 ;
goto V_147;
}
for ( V_140 = 0 ; V_140 < V_37 ; V_140 ++ ) {
if ( V_138 [ V_140 ] != V_137 ) {
F_115 ( V_138 [ V_140 ] ) ;
if ( ! F_116 ( V_138 [ V_140 ] ) ||
V_138 [ V_140 ] -> V_28 != V_26 -> V_130 ) {
V_37 = - V_146 ;
F_113 ( V_138 [ V_140 ] ) ;
F_101 ( V_138 [ V_140 ] ) ;
goto V_147;
}
}
F_101 ( V_138 [ V_140 ] ) ;
V_144 ++ ;
}
V_145 -= V_37 ;
V_126 += V_37 ;
F_79 () ;
}
V_37 = 0 ;
V_147:
if ( V_37 && V_144 ) {
F_110 ( V_26 , V_137 ,
V_141 ,
( ( T_1 ) ( V_143 + V_144 - 1 ) ) <<
V_127 ) ;
}
return V_37 ;
}
STATIC T_1 F_117 ( struct V_26 * V_26 ,
struct V_24 * V_25 ,
struct V_129 * V_137 , T_1 * V_15 ,
T_1 * V_16 , T_1 V_134 )
{
T_1 V_141 ;
T_1 V_142 ;
T_1 V_89 ;
struct V_1 * V_102 = NULL ;
int V_37 ;
int V_148 = 0 ;
V_109:
V_141 = * V_15 ;
V_142 = 0 ;
V_89 = F_109 ( V_25 , & V_141 , & V_142 ,
V_134 , & V_102 ) ;
if ( ! V_89 || V_142 <= * V_15 ) {
* V_15 = V_141 ;
* V_16 = V_142 ;
F_43 ( V_102 ) ;
return 0 ;
}
if ( V_141 < * V_15 )
V_141 = * V_15 ;
if ( V_142 + 1 - V_141 > V_134 )
V_142 = V_141 + V_134 - 1 ;
V_37 = F_114 ( V_26 , V_137 ,
V_141 , V_142 ) ;
if ( V_37 == - V_146 ) {
F_43 ( V_102 ) ;
V_102 = NULL ;
if ( ! V_148 ) {
V_134 = V_149 ;
V_148 = 1 ;
goto V_109;
} else {
V_89 = 0 ;
goto V_150;
}
}
F_23 ( V_37 ) ;
F_96 ( V_25 , V_141 , V_142 , & V_102 ) ;
V_37 = F_118 ( V_25 , V_141 , V_142 ,
V_106 , 1 , V_102 ) ;
if ( ! V_37 ) {
F_119 ( V_25 , V_141 , V_142 ,
& V_102 , V_125 ) ;
F_110 ( V_26 , V_137 ,
V_141 , V_142 ) ;
F_79 () ;
goto V_109;
}
F_43 ( V_102 ) ;
* V_15 = V_141 ;
* V_16 = V_142 ;
V_150:
return V_89 ;
}
void F_120 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_16 ,
struct V_129 * V_137 ,
unsigned V_122 ,
unsigned long V_151 )
{
struct V_24 * V_25 = & F_19 ( V_26 ) -> V_152 ;
int V_37 ;
struct V_129 * V_138 [ 16 ] ;
unsigned long V_126 = V_15 >> V_127 ;
unsigned long V_128 = V_16 >> V_127 ;
unsigned long V_139 = V_128 - V_126 + 1 ;
int V_140 ;
F_94 ( V_25 , V_15 , V_16 , V_122 , 1 , 0 , NULL , V_125 ) ;
if ( V_151 == 0 )
return;
if ( ( V_151 & V_153 ) && V_139 > 0 )
F_121 ( V_26 -> V_130 , - V_154 ) ;
while ( V_139 > 0 ) {
V_37 = F_111 ( V_26 -> V_130 , V_126 ,
F_112 (unsigned long,
nr_pages, ARRAY_SIZE(pages)) , V_138 ) ;
for ( V_140 = 0 ; V_140 < V_37 ; V_140 ++ ) {
if ( V_151 & V_155 )
F_122 ( V_138 [ V_140 ] ) ;
if ( V_138 [ V_140 ] == V_137 ) {
F_101 ( V_138 [ V_140 ] ) ;
continue;
}
if ( V_151 & V_156 )
F_100 ( V_138 [ V_140 ] ) ;
if ( V_151 & V_157 )
F_106 ( V_138 [ V_140 ] ) ;
if ( V_151 & V_153 )
F_123 ( V_138 [ V_140 ] ) ;
if ( V_151 & V_158 )
F_124 ( V_138 [ V_140 ] ) ;
if ( V_151 & V_159 )
F_113 ( V_138 [ V_140 ] ) ;
F_101 ( V_138 [ V_140 ] ) ;
}
V_139 -= V_37 ;
V_126 += V_37 ;
F_79 () ;
}
}
T_1 F_125 ( struct V_24 * V_25 ,
T_1 * V_15 , T_1 V_160 , T_1 V_134 ,
unsigned V_33 , int V_161 )
{
struct V_3 * V_65 ;
struct V_1 * V_2 ;
T_1 V_135 = * V_15 ;
T_1 V_136 = 0 ;
T_1 V_162 = 0 ;
int V_89 = 0 ;
if ( F_45 ( V_160 <= V_135 ) )
return 0 ;
F_75 ( & V_25 -> V_57 ) ;
if ( V_135 == 0 && V_33 == V_98 ) {
V_136 = V_25 -> V_56 ;
goto V_111;
}
V_65 = F_55 ( V_25 , V_135 ) ;
if ( ! V_65 )
goto V_111;
while ( 1 ) {
V_2 = F_48 ( V_65 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 > V_160 )
break;
if ( V_161 && V_89 && V_2 -> V_15 > V_162 + 1 )
break;
if ( V_2 -> V_16 >= V_135 && ( V_2 -> V_2 & V_33 ) == V_33 ) {
V_136 += F_126 ( V_160 , V_2 -> V_16 ) + 1 -
F_127 ( V_135 , V_2 -> V_15 ) ;
if ( V_136 >= V_134 )
break;
if ( ! V_89 ) {
* V_15 = F_127 ( V_135 , V_2 -> V_15 ) ;
V_89 = 1 ;
}
V_162 = V_2 -> V_16 ;
} else if ( V_161 && V_89 ) {
break;
}
V_65 = F_52 ( V_65 ) ;
if ( ! V_65 )
break;
}
V_111:
F_78 ( & V_25 -> V_57 ) ;
return V_136 ;
}
static int F_128 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_59 )
{
struct V_3 * V_65 ;
struct V_1 * V_2 ;
int V_37 = 0 ;
F_75 ( & V_25 -> V_57 ) ;
V_65 = F_55 ( V_25 , V_15 ) ;
if ( ! V_65 ) {
V_37 = - V_163 ;
goto V_111;
}
V_2 = F_48 ( V_65 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 != V_15 ) {
V_37 = - V_163 ;
goto V_111;
}
V_2 -> V_59 = V_59 ;
V_111:
F_78 ( & V_25 -> V_57 ) ;
return V_37 ;
}
int F_129 ( struct V_24 * V_25 , T_1 V_15 , T_1 * V_59 )
{
struct V_3 * V_65 ;
struct V_1 * V_2 ;
int V_37 = 0 ;
F_75 ( & V_25 -> V_57 ) ;
V_65 = F_55 ( V_25 , V_15 ) ;
if ( ! V_65 ) {
V_37 = - V_163 ;
goto V_111;
}
V_2 = F_48 ( V_65 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 != V_15 ) {
V_37 = - V_163 ;
goto V_111;
}
* V_59 = V_2 -> V_59 ;
V_111:
F_78 ( & V_25 -> V_57 ) ;
return V_37 ;
}
int F_118 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned V_33 , int V_164 , struct V_1 * V_103 )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_65 ;
int V_165 = 0 ;
F_75 ( & V_25 -> V_57 ) ;
if ( V_103 && F_1 ( V_103 ) && V_103 -> V_15 <= V_15 &&
V_103 -> V_16 > V_15 )
V_65 = & V_103 -> V_3 ;
else
V_65 = F_55 ( V_25 , V_15 ) ;
while ( V_65 && V_15 <= V_16 ) {
V_2 = F_48 ( V_65 , struct V_1 , V_3 ) ;
if ( V_164 && V_2 -> V_15 > V_15 ) {
V_165 = 0 ;
break;
}
if ( V_2 -> V_15 > V_16 )
break;
if ( V_2 -> V_2 & V_33 ) {
V_165 = 1 ;
if ( ! V_164 )
break;
} else if ( V_164 ) {
V_165 = 0 ;
break;
}
if ( V_2 -> V_16 == ( T_1 ) - 1 )
break;
V_15 = V_2 -> V_16 + 1 ;
if ( V_15 > V_16 )
break;
V_65 = F_52 ( V_65 ) ;
if ( ! V_65 ) {
if ( V_164 )
V_165 = 0 ;
break;
}
}
F_78 ( & V_25 -> V_57 ) ;
return V_165 ;
}
static void F_130 ( struct V_24 * V_25 , struct V_129 * V_129 )
{
T_1 V_15 = F_131 ( V_129 ) ;
T_1 V_16 = V_15 + V_149 - 1 ;
if ( F_118 ( V_25 , V_15 , V_16 , V_166 , 1 , NULL ) )
F_132 ( V_129 ) ;
}
int F_133 ( struct V_26 * V_26 , struct V_167 * V_168 )
{
int V_37 ;
int V_100 = 0 ;
struct V_24 * V_169 = & F_19 ( V_26 ) -> V_170 ;
F_128 ( V_169 , V_168 -> V_15 , 0 ) ;
V_37 = F_134 ( V_169 , V_168 -> V_15 ,
V_168 -> V_15 + V_168 -> V_21 - 1 ,
V_124 | V_98 , V_125 ) ;
if ( V_37 )
V_100 = V_37 ;
V_37 = F_134 ( & F_19 ( V_26 ) -> V_152 , V_168 -> V_15 ,
V_168 -> V_15 + V_168 -> V_21 - 1 ,
V_171 , V_125 ) ;
if ( V_37 && ! V_100 )
V_100 = V_37 ;
F_135 ( V_168 ) ;
return V_100 ;
}
int F_136 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_172 , T_1 V_173 ,
struct V_129 * V_129 , unsigned int V_174 , int V_175 )
{
struct V_41 * V_32 = F_19 ( V_26 ) -> V_31 -> V_32 ;
struct V_50 * V_50 ;
struct V_176 * V_177 ;
T_1 V_178 = 0 ;
T_1 V_179 ;
struct V_180 * V_181 = NULL ;
struct V_182 * V_183 = & V_32 -> V_184 ;
int V_37 ;
ASSERT ( ! ( V_32 -> V_185 -> V_186 & V_187 ) ) ;
F_23 ( ! V_175 ) ;
if ( F_137 ( V_183 , V_173 , V_172 , V_175 ) )
return 0 ;
V_50 = F_138 ( V_125 , 1 ) ;
if ( ! V_50 )
return - V_154 ;
V_50 -> V_188 . V_189 = 0 ;
V_178 = V_172 ;
V_37 = F_139 ( V_32 , V_190 , V_173 ,
& V_178 , & V_181 , V_175 ) ;
if ( V_37 ) {
F_140 ( V_50 ) ;
return - V_154 ;
}
F_23 ( V_175 != V_181 -> V_175 ) ;
V_179 = V_181 -> V_191 [ V_175 - 1 ] . V_192 >> 9 ;
V_50 -> V_188 . V_193 = V_179 ;
V_177 = V_181 -> V_191 [ V_175 - 1 ] . V_177 ;
F_141 ( V_181 ) ;
if ( ! V_177 || ! V_177 -> V_194 || ! V_177 -> V_195 ) {
F_140 ( V_50 ) ;
return - V_154 ;
}
V_50 -> V_196 = V_177 -> V_194 ;
F_142 ( V_50 , V_129 , V_172 , V_174 ) ;
if ( F_143 ( V_197 , V_50 ) ) {
F_140 ( V_50 ) ;
F_144 ( V_177 , V_198 ) ;
return - V_154 ;
}
F_145 ( V_32 ,
L_13 ,
F_20 ( V_26 ) , V_15 ,
F_146 ( V_177 -> V_199 ) , V_179 ) ;
F_140 ( V_50 ) ;
return 0 ;
}
int F_147 ( struct V_200 * V_31 , struct V_10 * V_11 ,
int V_175 )
{
T_1 V_15 = V_11 -> V_15 ;
unsigned long V_140 , V_201 = F_148 ( V_11 -> V_15 , V_11 -> V_21 ) ;
int V_37 = 0 ;
if ( V_31 -> V_32 -> V_185 -> V_186 & V_187 )
return - V_202 ;
for ( V_140 = 0 ; V_140 < V_201 ; V_140 ++ ) {
struct V_129 * V_68 = V_11 -> V_138 [ V_140 ] ;
V_37 = F_136 ( V_31 -> V_32 -> V_203 , V_15 ,
V_149 , V_15 , V_68 ,
V_15 - F_131 ( V_68 ) , V_175 ) ;
if ( V_37 )
break;
V_15 += V_149 ;
}
return V_37 ;
}
int F_149 ( struct V_26 * V_26 , T_1 V_15 , struct V_129 * V_129 ,
unsigned int V_174 )
{
T_1 V_59 ;
T_1 V_204 ;
struct V_167 * V_205 ;
struct V_41 * V_32 = F_19 ( V_26 ) -> V_31 -> V_32 ;
struct V_1 * V_2 ;
int V_206 ;
int V_37 ;
V_59 = 0 ;
V_37 = F_125 ( & F_19 ( V_26 ) -> V_170 , & V_59 ,
( T_1 ) - 1 , 1 , V_98 , 0 ) ;
if ( ! V_37 )
return 0 ;
V_37 = F_129 ( & F_19 ( V_26 ) -> V_170 , V_15 ,
& V_204 ) ;
if ( V_37 )
return 0 ;
V_205 = (struct V_167 * ) ( unsigned long ) V_204 ;
F_23 ( ! V_205 -> V_207 ) ;
if ( V_205 -> V_208 ) {
F_150 ( L_14 ,
V_205 -> V_15 ) ;
goto V_111;
}
if ( V_32 -> V_185 -> V_186 & V_187 )
goto V_111;
F_75 ( & F_19 ( V_26 ) -> V_152 . V_57 ) ;
V_2 = F_107 ( & F_19 ( V_26 ) -> V_152 ,
V_205 -> V_15 ,
V_124 ) ;
F_78 ( & F_19 ( V_26 ) -> V_152 . V_57 ) ;
if ( V_2 && V_2 -> V_15 <= V_205 -> V_15 &&
V_2 -> V_16 >= V_205 -> V_15 + V_205 -> V_21 - 1 ) {
V_206 = F_151 ( V_32 , V_205 -> V_173 ,
V_205 -> V_21 ) ;
if ( V_206 > 1 ) {
F_136 ( V_26 , V_15 , V_205 -> V_21 ,
V_205 -> V_173 , V_129 ,
V_174 , V_205 -> V_209 ) ;
}
}
V_111:
F_133 ( V_26 , V_205 ) ;
return 0 ;
}
void F_152 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_16 )
{
struct V_24 * V_169 = & F_19 ( V_26 ) -> V_170 ;
struct V_167 * V_205 ;
struct V_1 * V_2 , * V_13 ;
if ( F_153 ( & V_169 -> V_2 ) )
return;
F_75 ( & V_169 -> V_57 ) ;
V_2 = F_107 ( V_169 , V_15 , V_98 ) ;
while ( V_2 ) {
if ( V_2 -> V_15 > V_16 )
break;
ASSERT ( V_2 -> V_16 <= V_16 ) ;
V_13 = F_66 ( V_2 ) ;
V_205 = (struct V_167 * ) ( unsigned long ) V_2 -> V_59 ;
F_43 ( V_2 ) ;
F_135 ( V_205 ) ;
V_2 = V_13 ;
}
F_78 ( & V_169 -> V_57 ) ;
}
int F_154 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_16 ,
struct V_167 * * V_210 )
{
struct V_167 * V_205 ;
T_1 V_59 ;
struct V_211 * V_212 ;
struct V_24 * V_169 = & F_19 ( V_26 ) -> V_170 ;
struct V_24 * V_25 = & F_19 ( V_26 ) -> V_152 ;
struct V_213 * V_214 = & F_19 ( V_26 ) -> V_215 ;
int V_37 ;
T_1 V_173 ;
V_37 = F_129 ( V_169 , V_15 , & V_59 ) ;
if ( V_37 ) {
V_205 = F_155 ( sizeof( * V_205 ) , V_125 ) ;
if ( ! V_205 )
return - V_45 ;
V_205 -> V_15 = V_15 ;
V_205 -> V_21 = V_16 - V_15 + 1 ;
V_205 -> V_207 = 0 ;
V_205 -> V_216 = 0 ;
V_205 -> V_208 = 0 ;
F_156 ( & V_214 -> V_57 ) ;
V_212 = F_157 ( V_214 , V_15 , V_205 -> V_21 ) ;
if ( ! V_212 ) {
F_158 ( & V_214 -> V_57 ) ;
F_135 ( V_205 ) ;
return - V_154 ;
}
if ( V_212 -> V_15 > V_15 || V_212 -> V_15 + V_212 -> V_21 <= V_15 ) {
F_159 ( V_212 ) ;
V_212 = NULL ;
}
F_158 ( & V_214 -> V_57 ) ;
if ( ! V_212 ) {
F_135 ( V_205 ) ;
return - V_154 ;
}
V_173 = V_15 - V_212 -> V_15 ;
V_173 = V_212 -> V_217 + V_173 ;
if ( F_160 ( V_218 , & V_212 -> V_7 ) ) {
V_173 = V_212 -> V_217 ;
V_205 -> V_216 = V_219 ;
F_161 ( & V_205 -> V_216 ,
V_212 -> V_220 ) ;
}
F_150 ( L_15 ,
V_173 , V_15 , V_205 -> V_21 ) ;
V_205 -> V_173 = V_173 ;
F_159 ( V_212 ) ;
V_37 = F_162 ( V_169 , V_15 , V_16 ,
V_124 | V_98 , V_125 ) ;
if ( V_37 >= 0 )
V_37 = F_128 ( V_169 , V_15 ,
( T_1 ) ( unsigned long ) V_205 ) ;
if ( V_37 >= 0 )
V_37 = F_162 ( V_25 , V_15 , V_16 , V_171 ,
V_125 ) ;
if ( V_37 < 0 ) {
F_135 ( V_205 ) ;
return V_37 ;
}
} else {
V_205 = (struct V_167 * ) ( unsigned long ) V_59 ;
F_150 ( L_16 ,
V_205 -> V_173 , V_205 -> V_15 , V_205 -> V_21 ,
V_205 -> V_208 ) ;
}
* V_210 = V_205 ;
return 0 ;
}
int F_163 ( struct V_26 * V_26 , struct V_50 * V_221 ,
struct V_167 * V_205 , int V_209 )
{
int V_206 ;
V_206 = F_151 ( F_19 ( V_26 ) -> V_31 -> V_32 ,
V_205 -> V_173 , V_205 -> V_21 ) ;
if ( V_206 == 1 ) {
F_150 ( L_17 ,
V_206 , V_205 -> V_207 , V_209 ) ;
return 0 ;
}
if ( V_221 -> V_222 > 1 ) {
F_23 ( V_205 -> V_208 ) ;
V_205 -> V_208 = 1 ;
V_205 -> V_207 = V_209 ;
} else {
if ( V_205 -> V_208 ) {
F_23 ( V_205 -> V_207 != V_209 ) ;
V_205 -> V_208 = 0 ;
V_205 -> V_207 = 0 ;
}
V_205 -> V_209 = V_209 ;
V_205 -> V_207 ++ ;
if ( V_205 -> V_207 == V_209 )
V_205 -> V_207 ++ ;
}
if ( V_205 -> V_207 > V_206 ) {
F_150 ( L_18 ,
V_206 , V_205 -> V_207 , V_209 ) ;
return 0 ;
}
return 1 ;
}
struct V_50 * F_164 ( struct V_26 * V_26 , struct V_50 * V_221 ,
struct V_167 * V_205 ,
struct V_129 * V_129 , int V_174 , int V_223 ,
T_6 * V_224 , void * V_225 )
{
struct V_50 * V_50 ;
struct V_49 * V_226 ;
struct V_49 * V_180 ;
V_50 = F_138 ( V_125 , 1 ) ;
if ( ! V_50 )
return NULL ;
V_50 -> V_227 = V_224 ;
V_50 -> V_188 . V_193 = V_205 -> V_173 >> 9 ;
V_50 -> V_196 = F_19 ( V_26 ) -> V_31 -> V_32 -> V_228 -> V_229 ;
V_50 -> V_188 . V_189 = 0 ;
V_50 -> V_230 = V_225 ;
V_226 = V_49 ( V_221 ) ;
if ( V_226 -> V_231 ) {
struct V_41 * V_32 = F_19 ( V_26 ) -> V_31 -> V_32 ;
T_7 V_232 = F_165 ( V_32 -> V_233 ) ;
V_180 = V_49 ( V_50 ) ;
V_180 -> V_231 = V_180 -> V_234 ;
V_223 *= V_232 ;
memcpy ( V_180 -> V_231 , V_226 -> V_231 + V_223 ,
V_232 ) ;
}
F_142 ( V_50 , V_129 , V_205 -> V_21 , V_174 ) ;
return V_50 ;
}
static int F_166 ( struct V_50 * V_221 , T_1 V_235 ,
struct V_129 * V_129 , T_1 V_15 , T_1 V_16 ,
int V_209 )
{
struct V_167 * V_205 ;
struct V_26 * V_26 = V_129 -> V_28 -> V_29 ;
struct V_24 * V_25 = & F_19 ( V_26 ) -> V_152 ;
struct V_50 * V_50 ;
int V_236 ;
int V_37 ;
F_23 ( V_221 -> V_237 & V_238 ) ;
V_37 = F_154 ( V_26 , V_15 , V_16 , & V_205 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_163 ( V_26 , V_221 , V_205 , V_209 ) ;
if ( ! V_37 ) {
F_133 ( V_26 , V_205 ) ;
return - V_154 ;
}
if ( V_221 -> V_222 > 1 )
V_236 = V_239 | V_240 ;
else
V_236 = V_239 ;
V_235 >>= V_26 -> V_42 -> V_241 ;
V_50 = F_164 ( V_26 , V_221 , V_205 , V_129 ,
V_15 - F_131 ( V_129 ) ,
( int ) V_235 , V_221 -> V_227 ,
NULL ) ;
if ( ! V_50 ) {
F_133 ( V_26 , V_205 ) ;
return - V_154 ;
}
F_150 ( L_19 ,
V_236 , V_205 -> V_207 , V_205 -> V_208 ) ;
V_37 = V_25 -> V_55 -> V_242 ( V_26 , V_236 , V_50 ,
V_205 -> V_207 ,
V_205 -> V_216 , 0 ) ;
if ( V_37 ) {
F_133 ( V_26 , V_205 ) ;
F_140 ( V_50 ) ;
}
return V_37 ;
}
void F_167 ( struct V_129 * V_129 , int V_100 , T_1 V_15 , T_1 V_16 )
{
int V_243 = ( V_100 == 0 ) ;
struct V_24 * V_25 ;
int V_37 = 0 ;
V_25 = & F_19 ( V_129 -> V_28 -> V_29 ) -> V_152 ;
if ( V_25 -> V_55 && V_25 -> V_55 -> V_244 ) {
V_37 = V_25 -> V_55 -> V_244 ( V_129 , V_15 ,
V_16 , NULL , V_243 ) ;
if ( V_37 )
V_243 = 0 ;
}
if ( ! V_243 ) {
F_168 ( V_129 ) ;
F_123 ( V_129 ) ;
V_37 = V_37 < 0 ? V_37 : - V_154 ;
F_121 ( V_129 -> V_28 , V_37 ) ;
}
}
static void F_169 ( struct V_50 * V_50 )
{
struct V_245 * V_246 ;
T_1 V_15 ;
T_1 V_16 ;
int V_140 ;
F_170 (bvec, bio, i) {
struct V_129 * V_129 = V_246 -> V_247 ;
if ( V_246 -> V_248 || V_246 -> V_249 != V_149 ) {
if ( V_246 -> V_248 + V_246 -> V_249 != V_149 )
F_171 ( F_19 ( V_129 -> V_28 -> V_29 ) -> V_31 -> V_32 ,
L_20 ,
V_246 -> V_248 , V_246 -> V_249 ) ;
else
F_172 ( F_19 ( V_129 -> V_28 -> V_29 ) -> V_31 -> V_32 ,
L_21
L_22 ,
V_246 -> V_248 , V_246 -> V_249 ) ;
}
V_15 = F_131 ( V_129 ) ;
V_16 = V_15 + V_246 -> V_248 + V_246 -> V_249 - 1 ;
F_167 ( V_129 , V_50 -> V_250 , V_15 , V_16 ) ;
F_124 ( V_129 ) ;
}
F_140 ( V_50 ) ;
}
static void
F_173 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_21 ,
int V_243 )
{
struct V_1 * V_103 = NULL ;
T_1 V_16 = V_15 + V_21 - 1 ;
if ( V_243 && V_25 -> V_251 )
F_174 ( V_25 , V_15 , V_16 , & V_103 , V_40 ) ;
F_119 ( V_25 , V_15 , V_16 , & V_103 , V_40 ) ;
}
static void F_175 ( struct V_50 * V_50 )
{
struct V_245 * V_246 ;
int V_243 = ! V_50 -> V_250 ;
struct V_49 * V_252 = V_49 ( V_50 ) ;
struct V_24 * V_25 ;
T_1 V_64 = 0 ;
T_1 V_15 ;
T_1 V_16 ;
T_1 V_21 ;
T_1 V_253 = 0 ;
T_1 V_254 = 0 ;
int V_255 ;
int V_37 ;
int V_140 ;
F_170 (bvec, bio, i) {
struct V_129 * V_129 = V_246 -> V_247 ;
struct V_26 * V_26 = V_129 -> V_28 -> V_29 ;
F_150 ( L_23
L_24 , ( T_1 ) V_50 -> V_188 . V_193 ,
V_50 -> V_250 , V_252 -> V_175 ) ;
V_25 = & F_19 ( V_26 ) -> V_152 ;
if ( V_246 -> V_248 || V_246 -> V_249 != V_149 ) {
if ( V_246 -> V_248 + V_246 -> V_249 != V_149 )
F_171 ( F_19 ( V_129 -> V_28 -> V_29 ) -> V_31 -> V_32 ,
L_25 ,
V_246 -> V_248 , V_246 -> V_249 ) ;
else
F_172 ( F_19 ( V_129 -> V_28 -> V_29 ) -> V_31 -> V_32 ,
L_26
L_22 ,
V_246 -> V_248 , V_246 -> V_249 ) ;
}
V_15 = F_131 ( V_129 ) ;
V_16 = V_15 + V_246 -> V_248 + V_246 -> V_249 - 1 ;
V_21 = V_246 -> V_249 ;
V_255 = V_252 -> V_175 ;
if ( F_176 ( V_243 && V_25 -> V_55 &&
V_25 -> V_55 -> V_256 ) ) {
V_37 = V_25 -> V_55 -> V_256 ( V_252 , V_64 ,
V_129 , V_15 , V_16 ,
V_255 ) ;
if ( V_37 )
V_243 = 0 ;
else
F_149 ( V_26 , V_15 , V_129 , 0 ) ;
}
if ( F_176 ( V_243 ) )
goto V_257;
if ( V_25 -> V_55 && V_25 -> V_55 -> V_258 ) {
V_37 = V_25 -> V_55 -> V_258 ( V_129 , V_255 ) ;
if ( ! V_37 && ! V_50 -> V_250 )
V_243 = 1 ;
} else {
V_37 = F_166 ( V_50 , V_64 , V_129 , V_15 , V_16 ,
V_255 ) ;
if ( V_37 == 0 ) {
V_243 = ! V_50 -> V_250 ;
V_64 += V_21 ;
continue;
}
}
V_257:
if ( F_176 ( V_243 ) ) {
T_8 V_259 = F_17 ( V_26 ) ;
T_9 V_128 = V_259 >> V_127 ;
unsigned V_260 ;
V_260 = V_259 & ( V_149 - 1 ) ;
if ( V_129 -> V_126 == V_128 && V_260 )
F_177 ( V_129 , V_260 , V_149 ) ;
F_132 ( V_129 ) ;
} else {
F_168 ( V_129 ) ;
F_123 ( V_129 ) ;
}
F_113 ( V_129 ) ;
V_64 += V_21 ;
if ( F_178 ( ! V_243 ) ) {
if ( V_254 ) {
F_173 ( V_25 ,
V_253 ,
V_254 , 1 ) ;
V_253 = 0 ;
V_254 = 0 ;
}
F_173 ( V_25 , V_15 ,
V_16 - V_15 + 1 , 0 ) ;
} else if ( ! V_254 ) {
V_253 = V_15 ;
V_254 = V_16 + 1 - V_15 ;
} else if ( V_253 + V_254 == V_15 ) {
V_254 += V_16 + 1 - V_15 ;
} else {
F_173 ( V_25 , V_253 ,
V_254 , V_243 ) ;
V_253 = V_15 ;
V_254 = V_16 + 1 - V_15 ;
}
}
if ( V_254 )
F_173 ( V_25 , V_253 , V_254 ,
V_243 ) ;
if ( V_252 -> V_261 )
V_252 -> V_261 ( V_252 , V_50 -> V_250 ) ;
F_140 ( V_50 ) ;
}
struct V_50 *
F_179 ( struct V_262 * V_194 , T_1 V_263 , int V_264 ,
T_3 V_265 )
{
struct V_49 * V_180 ;
struct V_50 * V_50 ;
V_50 = F_180 ( V_265 , V_264 , V_47 ) ;
if ( V_50 == NULL && ( V_266 -> V_7 & V_267 ) ) {
while ( ! V_50 && ( V_264 /= 2 ) ) {
V_50 = F_180 ( V_265 ,
V_264 , V_47 ) ;
}
}
if ( V_50 ) {
V_50 -> V_196 = V_194 ;
V_50 -> V_188 . V_193 = V_263 ;
V_180 = V_49 ( V_50 ) ;
V_180 -> V_231 = NULL ;
V_180 -> V_268 = NULL ;
V_180 -> V_261 = NULL ;
}
return V_50 ;
}
struct V_50 * F_181 ( struct V_50 * V_50 , T_3 V_269 )
{
struct V_49 * V_180 ;
struct V_50 * V_5 ;
V_5 = F_182 ( V_50 , V_269 , V_47 ) ;
if ( V_5 ) {
V_180 = V_49 ( V_5 ) ;
V_180 -> V_231 = NULL ;
V_180 -> V_268 = NULL ;
V_180 -> V_261 = NULL ;
#ifdef F_183
if ( V_50 -> V_270 )
F_184 ( V_5 , V_50 -> V_270 ) ;
#endif
}
return V_5 ;
}
struct V_50 * F_138 ( T_3 V_269 , unsigned int V_271 )
{
struct V_49 * V_180 ;
struct V_50 * V_50 ;
V_50 = F_180 ( V_269 , V_271 , V_47 ) ;
if ( V_50 ) {
V_180 = V_49 ( V_50 ) ;
V_180 -> V_231 = NULL ;
V_180 -> V_268 = NULL ;
V_180 -> V_261 = NULL ;
}
return V_50 ;
}
static int T_4 F_185 ( int V_272 , struct V_50 * V_50 ,
int V_175 , unsigned long V_216 )
{
int V_37 = 0 ;
struct V_245 * V_246 = V_50 -> V_273 + V_50 -> V_222 - 1 ;
struct V_129 * V_129 = V_246 -> V_247 ;
struct V_24 * V_25 = V_50 -> V_230 ;
T_1 V_15 ;
V_15 = F_131 ( V_129 ) + V_246 -> V_248 ;
V_50 -> V_230 = NULL ;
F_186 ( V_50 ) ;
if ( V_25 -> V_55 && V_25 -> V_55 -> V_242 )
V_37 = V_25 -> V_55 -> V_242 ( V_129 -> V_28 -> V_29 , V_272 , V_50 ,
V_175 , V_216 , V_15 ) ;
else
F_187 ( V_272 , V_50 ) ;
F_140 ( V_50 ) ;
return V_37 ;
}
static int F_188 ( int V_272 , struct V_24 * V_25 , struct V_129 * V_129 ,
unsigned long V_64 , T_10 V_274 , struct V_50 * V_50 ,
unsigned long V_216 )
{
int V_37 = 0 ;
if ( V_25 -> V_55 && V_25 -> V_55 -> V_275 )
V_37 = V_25 -> V_55 -> V_275 ( V_272 , V_129 , V_64 , V_274 , V_50 ,
V_216 ) ;
F_23 ( V_37 < 0 ) ;
return V_37 ;
}
static int F_189 ( int V_272 , struct V_24 * V_25 ,
struct V_276 * V_277 ,
struct V_129 * V_129 , T_11 V_179 ,
T_10 V_274 , unsigned long V_64 ,
struct V_262 * V_194 ,
struct V_50 * * V_278 ,
unsigned long V_279 ,
T_6 V_280 ,
int V_175 ,
unsigned long V_281 ,
unsigned long V_216 ,
bool V_282 )
{
int V_37 = 0 ;
struct V_50 * V_50 ;
int V_161 = 0 ;
int V_283 = V_281 & V_219 ;
T_10 V_284 = F_112 ( T_10 , V_274 , V_149 ) ;
if ( V_278 && * V_278 ) {
V_50 = * V_278 ;
if ( V_283 )
V_161 = V_50 -> V_188 . V_193 == V_179 ;
else
V_161 = F_190 ( V_50 ) == V_179 ;
if ( V_281 != V_216 || ! V_161 ||
V_282 ||
F_188 ( V_272 , V_25 , V_129 , V_64 , V_284 , V_50 , V_216 ) ||
F_142 ( V_50 , V_129 , V_284 , V_64 ) < V_284 ) {
V_37 = F_185 ( V_272 , V_50 , V_175 ,
V_281 ) ;
if ( V_37 < 0 ) {
* V_278 = NULL ;
return V_37 ;
}
V_50 = NULL ;
} else {
if ( V_277 )
F_191 ( V_277 , V_129 , V_284 ) ;
return 0 ;
}
}
V_50 = F_179 ( V_194 , V_179 , V_285 ,
V_125 | V_286 ) ;
if ( ! V_50 )
return - V_45 ;
F_142 ( V_50 , V_129 , V_284 , V_64 ) ;
V_50 -> V_227 = V_280 ;
V_50 -> V_230 = V_25 ;
if ( V_277 ) {
F_192 ( V_277 , V_50 ) ;
F_191 ( V_277 , V_129 , V_284 ) ;
}
if ( V_278 )
* V_278 = V_50 ;
else
V_37 = F_185 ( V_272 , V_50 , V_175 , V_216 ) ;
return V_37 ;
}
static void F_193 ( struct V_10 * V_11 ,
struct V_129 * V_129 )
{
if ( ! F_194 ( V_129 ) ) {
F_195 ( V_129 ) ;
F_196 ( V_129 ) ;
F_197 ( V_129 , ( unsigned long ) V_11 ) ;
} else {
F_45 ( V_129 -> V_59 != ( unsigned long ) V_11 ) ;
}
}
void F_198 ( struct V_129 * V_129 )
{
if ( ! F_194 ( V_129 ) ) {
F_195 ( V_129 ) ;
F_196 ( V_129 ) ;
F_197 ( V_129 , V_287 ) ;
}
}
static struct V_211 *
F_199 ( struct V_26 * V_26 , struct V_129 * V_129 , T_10 V_174 ,
T_1 V_15 , T_1 V_21 , T_12 * V_288 ,
struct V_211 * * V_289 )
{
struct V_211 * V_212 ;
if ( V_289 && * V_289 ) {
V_212 = * V_289 ;
if ( F_200 ( V_212 ) && V_15 >= V_212 -> V_15 &&
V_15 < F_201 ( V_212 ) ) {
F_86 ( & V_212 -> V_17 ) ;
return V_212 ;
}
F_159 ( V_212 ) ;
* V_289 = NULL ;
}
V_212 = V_288 ( V_26 , V_129 , V_174 , V_15 , V_21 , 0 ) ;
if ( V_289 && ! F_202 ( V_212 ) ) {
F_23 ( * V_289 ) ;
F_86 ( & V_212 -> V_17 ) ;
* V_289 = V_212 ;
}
return V_212 ;
}
static int F_203 ( struct V_24 * V_25 ,
struct V_129 * V_129 ,
T_12 * V_288 ,
struct V_211 * * V_289 ,
struct V_50 * * V_50 , int V_175 ,
unsigned long * V_216 , int V_272 ,
T_1 * V_290 )
{
struct V_26 * V_26 = V_129 -> V_28 -> V_29 ;
T_1 V_15 = F_131 ( V_129 ) ;
T_1 V_291 = V_15 + V_149 - 1 ;
T_1 V_16 ;
T_1 V_292 = V_15 ;
T_1 V_293 ;
T_1 V_294 = F_17 ( V_26 ) ;
T_1 V_217 ;
T_1 V_295 ;
T_11 V_179 ;
struct V_211 * V_212 ;
struct V_262 * V_194 ;
int V_37 ;
int V_296 = 0 ;
T_10 V_174 = 0 ;
T_10 V_297 ;
T_10 V_298 ;
T_10 V_299 = V_26 -> V_42 -> V_300 ;
unsigned long V_301 = 0 ;
F_198 ( V_129 ) ;
V_16 = V_291 ;
if ( ! F_204 ( V_129 ) ) {
if ( F_205 ( V_129 ) == 0 ) {
F_23 ( V_299 != V_30 ) ;
F_206 ( V_25 , V_15 , V_16 ) ;
goto V_111;
}
}
if ( V_129 -> V_126 == V_294 >> V_127 ) {
char * V_302 ;
T_10 V_303 = V_294 & ( V_149 - 1 ) ;
if ( V_303 ) {
V_297 = V_149 - V_303 ;
V_302 = F_207 ( V_129 ) ;
memset ( V_302 + V_303 , 0 , V_297 ) ;
F_208 ( V_129 ) ;
F_209 ( V_302 ) ;
}
}
while ( V_292 <= V_16 ) {
unsigned long V_304 = ( V_294 >> V_127 ) + 1 ;
bool V_282 = false ;
if ( V_292 >= V_294 ) {
char * V_302 ;
struct V_1 * V_103 = NULL ;
V_297 = V_149 - V_174 ;
V_302 = F_207 ( V_129 ) ;
memset ( V_302 + V_174 , 0 , V_297 ) ;
F_208 ( V_129 ) ;
F_209 ( V_302 ) ;
F_174 ( V_25 , V_292 , V_292 + V_297 - 1 ,
& V_103 , V_125 ) ;
F_119 ( V_25 , V_292 ,
V_292 + V_297 - 1 ,
& V_103 , V_125 ) ;
break;
}
V_212 = F_199 ( V_26 , V_129 , V_174 , V_292 ,
V_16 - V_292 + 1 , V_288 , V_289 ) ;
if ( F_202 ( V_212 ) ) {
F_123 ( V_129 ) ;
F_206 ( V_25 , V_292 , V_16 ) ;
break;
}
V_293 = V_292 - V_212 -> V_15 ;
F_23 ( F_201 ( V_212 ) <= V_292 ) ;
F_23 ( V_16 < V_292 ) ;
if ( F_160 ( V_218 , & V_212 -> V_7 ) ) {
V_301 |= V_219 ;
F_161 ( & V_301 ,
V_212 -> V_220 ) ;
}
V_297 = F_126 ( F_201 ( V_212 ) - V_292 , V_16 - V_292 + 1 ) ;
V_295 = F_126 ( F_201 ( V_212 ) - 1 , V_16 ) ;
V_297 = F_210 ( V_297 , V_299 ) ;
if ( V_301 & V_219 ) {
V_298 = V_212 -> V_305 ;
V_179 = V_212 -> V_217 >> 9 ;
} else {
V_179 = ( V_212 -> V_217 + V_293 ) >> 9 ;
V_298 = V_297 ;
}
V_194 = V_212 -> V_194 ;
V_217 = V_212 -> V_217 ;
if ( F_160 ( V_306 , & V_212 -> V_7 ) )
V_217 = V_307 ;
if ( F_160 ( V_218 , & V_212 -> V_7 ) &&
V_290 && * V_290 != ( T_1 ) - 1 &&
* V_290 != V_212 -> V_308 )
V_282 = true ;
if ( V_290 )
* V_290 = V_212 -> V_308 ;
F_159 ( V_212 ) ;
V_212 = NULL ;
if ( V_217 == V_307 ) {
char * V_302 ;
struct V_1 * V_103 = NULL ;
V_302 = F_207 ( V_129 ) ;
memset ( V_302 + V_174 , 0 , V_297 ) ;
F_208 ( V_129 ) ;
F_209 ( V_302 ) ;
F_174 ( V_25 , V_292 , V_292 + V_297 - 1 ,
& V_103 , V_125 ) ;
F_119 ( V_25 , V_292 ,
V_292 + V_297 - 1 ,
& V_103 , V_125 ) ;
V_292 = V_292 + V_297 ;
V_174 += V_297 ;
continue;
}
if ( F_118 ( V_25 , V_292 , V_295 ,
V_166 , 1 , NULL ) ) {
F_130 ( V_25 , V_129 ) ;
F_206 ( V_25 , V_292 , V_292 + V_297 - 1 ) ;
V_292 = V_292 + V_297 ;
V_174 += V_297 ;
continue;
}
if ( V_217 == V_309 ) {
F_123 ( V_129 ) ;
F_206 ( V_25 , V_292 , V_292 + V_297 - 1 ) ;
V_292 = V_292 + V_297 ;
V_174 += V_297 ;
continue;
}
V_304 -= V_129 -> V_126 ;
V_37 = F_189 ( V_272 , V_25 , NULL , V_129 ,
V_179 , V_298 , V_174 ,
V_194 , V_50 , V_304 ,
F_175 , V_175 ,
* V_216 ,
V_301 ,
V_282 ) ;
if ( ! V_37 ) {
V_296 ++ ;
* V_216 = V_301 ;
} else {
F_123 ( V_129 ) ;
F_206 ( V_25 , V_292 , V_292 + V_297 - 1 ) ;
}
V_292 = V_292 + V_297 ;
V_174 += V_297 ;
}
V_111:
if ( ! V_296 ) {
if ( ! F_211 ( V_129 ) )
F_132 ( V_129 ) ;
F_113 ( V_129 ) ;
}
return 0 ;
}
static inline void F_212 ( struct V_24 * V_25 ,
struct V_129 * V_138 [] , int V_139 ,
T_1 V_15 , T_1 V_16 ,
T_12 * V_288 ,
struct V_211 * * V_289 ,
struct V_50 * * V_50 , int V_175 ,
unsigned long * V_216 , int V_272 ,
T_1 * V_290 )
{
struct V_26 * V_26 ;
struct V_310 * V_311 ;
int V_126 ;
V_26 = V_138 [ 0 ] -> V_28 -> V_29 ;
while ( 1 ) {
F_213 ( V_25 , V_15 , V_16 ) ;
V_311 = F_214 ( V_26 , V_15 ,
V_16 - V_15 + 1 ) ;
if ( ! V_311 )
break;
F_206 ( V_25 , V_15 , V_16 ) ;
F_215 ( V_26 , V_311 , 1 ) ;
F_216 ( V_311 ) ;
}
for ( V_126 = 0 ; V_126 < V_139 ; V_126 ++ ) {
F_203 ( V_25 , V_138 [ V_126 ] , V_288 , V_289 , V_50 ,
V_175 , V_216 , V_272 , V_290 ) ;
F_101 ( V_138 [ V_126 ] ) ;
}
}
static void F_217 ( struct V_24 * V_25 ,
struct V_129 * V_138 [] ,
int V_139 , T_12 * V_288 ,
struct V_211 * * V_289 ,
struct V_50 * * V_50 , int V_175 ,
unsigned long * V_216 , int V_272 ,
T_1 * V_290 )
{
T_1 V_15 = 0 ;
T_1 V_16 = 0 ;
T_1 V_312 ;
int V_126 ;
int V_313 = 0 ;
for ( V_126 = 0 ; V_126 < V_139 ; V_126 ++ ) {
V_312 = F_131 ( V_138 [ V_126 ] ) ;
if ( ! V_16 ) {
V_15 = V_312 ;
V_16 = V_15 + V_149 - 1 ;
V_313 = V_126 ;
} else if ( V_16 + 1 == V_312 ) {
V_16 += V_149 ;
} else {
F_212 ( V_25 , & V_138 [ V_313 ] ,
V_126 - V_313 , V_15 ,
V_16 , V_288 , V_289 ,
V_50 , V_175 , V_216 ,
V_272 , V_290 ) ;
V_15 = V_312 ;
V_16 = V_15 + V_149 - 1 ;
V_313 = V_126 ;
}
}
if ( V_16 )
F_212 ( V_25 , & V_138 [ V_313 ] ,
V_126 - V_313 , V_15 ,
V_16 , V_288 , V_289 , V_50 ,
V_175 , V_216 , V_272 ,
V_290 ) ;
}
static int F_218 ( struct V_24 * V_25 ,
struct V_129 * V_129 ,
T_12 * V_288 ,
struct V_50 * * V_50 , int V_175 ,
unsigned long * V_216 , int V_272 )
{
struct V_26 * V_26 = V_129 -> V_28 -> V_29 ;
struct V_310 * V_311 ;
T_1 V_15 = F_131 ( V_129 ) ;
T_1 V_16 = V_15 + V_149 - 1 ;
int V_37 ;
while ( 1 ) {
F_213 ( V_25 , V_15 , V_16 ) ;
V_311 = F_219 ( V_26 , V_15 ) ;
if ( ! V_311 )
break;
F_206 ( V_25 , V_15 , V_16 ) ;
F_215 ( V_26 , V_311 , 1 ) ;
F_216 ( V_311 ) ;
}
V_37 = F_203 ( V_25 , V_129 , V_288 , NULL , V_50 , V_175 ,
V_216 , V_272 , NULL ) ;
return V_37 ;
}
int F_220 ( struct V_24 * V_25 , struct V_129 * V_129 ,
T_12 * V_288 , int V_175 )
{
struct V_50 * V_50 = NULL ;
unsigned long V_216 = 0 ;
int V_37 ;
V_37 = F_218 ( V_25 , V_129 , V_288 , & V_50 , V_175 ,
& V_216 , V_314 ) ;
if ( V_50 )
V_37 = F_185 ( V_314 , V_50 , V_175 , V_216 ) ;
return V_37 ;
}
static T_5 void F_221 ( struct V_129 * V_129 ,
struct V_276 * V_277 ,
unsigned long V_315 )
{
V_277 -> V_316 -= V_315 ;
if ( V_277 -> V_317 || ( V_277 -> V_316 > 0 &&
V_277 -> V_318 == 0 && V_277 -> V_319 == V_320 ) )
V_129 -> V_28 -> V_321 = V_129 -> V_126 + V_315 ;
}
static T_13 int F_222 ( struct V_26 * V_26 ,
struct V_129 * V_129 , struct V_276 * V_277 ,
struct V_322 * V_323 ,
T_1 V_141 ,
unsigned long * V_315 )
{
struct V_24 * V_25 = V_323 -> V_25 ;
T_1 V_291 = V_141 + V_149 - 1 ;
T_1 V_324 ;
T_1 V_325 = 0 ;
T_1 V_142 = 0 ;
int V_37 ;
int V_326 = 0 ;
if ( V_323 -> V_327 || ! V_25 -> V_55 || ! V_25 -> V_55 -> V_328 )
return 0 ;
while ( V_142 < V_291 ) {
V_324 = F_117 ( V_26 , V_25 ,
V_129 ,
& V_141 ,
& V_142 ,
V_329 ) ;
if ( V_324 == 0 ) {
V_141 = V_142 + 1 ;
continue;
}
V_37 = V_25 -> V_55 -> V_328 ( V_26 , V_129 ,
V_141 ,
V_142 ,
& V_326 ,
V_315 ) ;
if ( V_37 ) {
F_123 ( V_129 ) ;
V_37 = V_37 < 0 ? V_37 : - V_154 ;
goto V_147;
}
V_325 += ( V_142 - V_141 +
V_149 ) >>
V_127 ;
V_141 = V_142 + 1 ;
}
if ( V_277 -> V_316 < V_325 ) {
int V_330 = 8192 ;
if ( V_325 < V_330 * 2 )
V_330 = V_325 ;
V_277 -> V_316 = F_112 ( T_1 , V_325 ,
V_330 ) ;
}
if ( V_326 ) {
V_277 -> V_316 -= * V_315 ;
return 1 ;
}
V_37 = 0 ;
V_147:
return V_37 ;
}
static T_13 int F_223 ( struct V_26 * V_26 ,
struct V_129 * V_129 ,
struct V_276 * V_277 ,
struct V_322 * V_323 ,
T_8 V_259 ,
unsigned long V_315 ,
int V_331 , int * V_332 )
{
struct V_24 * V_25 = V_323 -> V_25 ;
T_1 V_15 = F_131 ( V_129 ) ;
T_1 V_291 = V_15 + V_149 - 1 ;
T_1 V_16 ;
T_1 V_292 = V_15 ;
T_1 V_293 ;
T_1 V_217 ;
T_1 V_297 ;
T_11 V_179 ;
struct V_1 * V_102 = NULL ;
struct V_211 * V_212 ;
struct V_262 * V_194 ;
T_10 V_174 = 0 ;
T_10 V_299 ;
int V_37 = 0 ;
int V_296 = 0 ;
bool V_333 ;
if ( V_25 -> V_55 && V_25 -> V_55 -> V_334 ) {
V_37 = V_25 -> V_55 -> V_334 ( V_129 , V_15 ,
V_291 ) ;
if ( V_37 ) {
if ( V_37 == - V_335 )
V_277 -> V_336 ++ ;
else
F_224 ( V_277 , V_129 ) ;
F_221 ( V_129 , V_277 , V_315 ) ;
F_113 ( V_129 ) ;
V_37 = 1 ;
goto V_337;
}
}
F_221 ( V_129 , V_277 , V_315 + 1 ) ;
V_16 = V_291 ;
if ( V_259 <= V_15 ) {
if ( V_25 -> V_55 && V_25 -> V_55 -> V_244 )
V_25 -> V_55 -> V_244 ( V_129 , V_15 ,
V_291 , NULL , 1 ) ;
goto V_147;
}
V_299 = V_26 -> V_42 -> V_300 ;
while ( V_292 <= V_16 ) {
T_1 V_338 ;
if ( V_292 >= V_259 ) {
if ( V_25 -> V_55 && V_25 -> V_55 -> V_244 )
V_25 -> V_55 -> V_244 ( V_129 , V_292 ,
V_291 , NULL , 1 ) ;
break;
}
V_212 = V_323 -> V_288 ( V_26 , V_129 , V_174 , V_292 ,
V_16 - V_292 + 1 , 1 ) ;
if ( F_202 ( V_212 ) ) {
F_123 ( V_129 ) ;
V_37 = F_225 ( V_212 ) ;
break;
}
V_293 = V_292 - V_212 -> V_15 ;
V_338 = F_201 ( V_212 ) ;
F_23 ( V_338 <= V_292 ) ;
F_23 ( V_16 < V_292 ) ;
V_297 = F_126 ( V_338 - V_292 , V_16 - V_292 + 1 ) ;
V_297 = F_210 ( V_297 , V_299 ) ;
V_179 = ( V_212 -> V_217 + V_293 ) >> 9 ;
V_194 = V_212 -> V_194 ;
V_217 = V_212 -> V_217 ;
V_333 = F_160 ( V_218 , & V_212 -> V_7 ) ;
F_159 ( V_212 ) ;
V_212 = NULL ;
if ( V_333 || V_217 == V_307 ||
V_217 == V_309 ) {
if ( ! V_333 && V_25 -> V_55 &&
V_25 -> V_55 -> V_244 )
V_25 -> V_55 -> V_244 ( V_129 , V_292 ,
V_292 + V_297 - 1 ,
NULL , 1 ) ;
else if ( V_333 ) {
V_296 ++ ;
}
V_292 += V_297 ;
V_174 += V_297 ;
continue;
}
if ( V_25 -> V_55 && V_25 -> V_55 -> V_339 ) {
V_37 = V_25 -> V_55 -> V_339 ( V_129 , V_292 ,
V_292 + V_297 - 1 ) ;
} else {
V_37 = 0 ;
}
if ( V_37 ) {
F_123 ( V_129 ) ;
} else {
unsigned long V_340 = ( V_259 >> V_127 ) + 1 ;
F_105 ( V_25 , V_292 , V_292 + V_297 - 1 ) ;
if ( ! F_226 ( V_129 ) ) {
F_171 ( F_19 ( V_26 ) -> V_31 -> V_32 ,
L_27 ,
V_129 -> V_126 , V_292 , V_16 ) ;
}
V_37 = F_189 ( V_331 , V_25 , V_277 , V_129 ,
V_179 , V_297 , V_174 ,
V_194 , & V_323 -> V_50 , V_340 ,
F_169 ,
0 , 0 , 0 , false ) ;
if ( V_37 )
F_123 ( V_129 ) ;
}
V_292 = V_292 + V_297 ;
V_174 += V_297 ;
V_296 ++ ;
}
V_147:
* V_332 = V_296 ;
V_337:
F_43 ( V_102 ) ;
return V_37 ;
}
static int F_227 ( struct V_129 * V_129 , struct V_276 * V_277 ,
void * V_225 )
{
struct V_26 * V_26 = V_129 -> V_28 -> V_29 ;
struct V_322 * V_323 = V_225 ;
T_1 V_15 = F_131 ( V_129 ) ;
T_1 V_291 = V_15 + V_149 - 1 ;
int V_37 ;
int V_296 = 0 ;
T_10 V_174 = 0 ;
T_8 V_259 = F_17 ( V_26 ) ;
unsigned long V_128 = V_259 >> V_127 ;
int V_331 ;
unsigned long V_315 = 0 ;
if ( V_277 -> V_341 == V_342 )
V_331 = V_197 ;
else
V_331 = V_190 ;
F_228 ( V_129 , V_26 , V_277 ) ;
F_45 ( ! F_229 ( V_129 ) ) ;
F_230 ( V_129 ) ;
V_174 = V_259 & ( V_149 - 1 ) ;
if ( V_129 -> V_126 > V_128 ||
( V_129 -> V_126 == V_128 && ! V_174 ) ) {
V_129 -> V_28 -> V_343 -> V_344 ( V_129 , 0 , V_149 ) ;
F_113 ( V_129 ) ;
return 0 ;
}
if ( V_129 -> V_126 == V_128 ) {
char * V_302 ;
V_302 = F_207 ( V_129 ) ;
memset ( V_302 + V_174 , 0 ,
V_149 - V_174 ) ;
F_209 ( V_302 ) ;
F_208 ( V_129 ) ;
}
V_174 = 0 ;
F_198 ( V_129 ) ;
V_37 = F_222 ( V_26 , V_129 , V_277 , V_323 , V_15 , & V_315 ) ;
if ( V_37 == 1 )
goto V_337;
if ( V_37 )
goto V_147;
V_37 = F_223 ( V_26 , V_129 , V_277 , V_323 ,
V_259 , V_315 , V_331 , & V_296 ) ;
if ( V_37 == 1 )
goto V_337;
V_147:
if ( V_296 == 0 ) {
F_106 ( V_129 ) ;
F_124 ( V_129 ) ;
}
if ( F_211 ( V_129 ) ) {
V_37 = V_37 < 0 ? V_37 : - V_154 ;
F_167 ( V_129 , V_37 , V_15 , V_291 ) ;
}
F_113 ( V_129 ) ;
return V_37 ;
V_337:
return 0 ;
}
void F_231 ( struct V_10 * V_11 )
{
F_232 ( & V_11 -> V_345 , V_346 ,
V_114 ) ;
}
static T_13 int
F_233 ( struct V_10 * V_11 ,
struct V_41 * V_32 ,
struct V_322 * V_323 )
{
unsigned long V_140 , V_201 ;
int V_347 = 0 ;
int V_37 = 0 ;
if ( ! F_234 ( V_11 ) ) {
V_347 = 1 ;
F_235 ( V_323 ) ;
F_236 ( V_11 ) ;
}
if ( F_160 ( V_346 , & V_11 -> V_345 ) ) {
F_237 ( V_11 ) ;
if ( ! V_323 -> V_348 )
return 0 ;
if ( ! V_347 ) {
F_235 ( V_323 ) ;
V_347 = 1 ;
}
while ( 1 ) {
F_231 ( V_11 ) ;
F_236 ( V_11 ) ;
if ( ! F_160 ( V_346 , & V_11 -> V_345 ) )
break;
F_237 ( V_11 ) ;
}
}
F_75 ( & V_11 -> V_349 ) ;
if ( F_238 ( V_350 , & V_11 -> V_345 ) ) {
F_239 ( V_346 , & V_11 -> V_345 ) ;
F_78 ( & V_11 -> V_349 ) ;
F_240 ( V_11 , V_351 ) ;
F_241 ( & V_32 -> V_352 ,
- V_11 -> V_21 ,
V_32 -> V_353 ) ;
V_37 = 1 ;
} else {
F_78 ( & V_11 -> V_349 ) ;
}
F_237 ( V_11 ) ;
if ( ! V_37 )
return V_37 ;
V_201 = F_148 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_140 = 0 ; V_140 < V_201 ; V_140 ++ ) {
struct V_129 * V_68 = V_11 -> V_138 [ V_140 ] ;
if ( ! F_242 ( V_68 ) ) {
if ( ! V_347 ) {
F_235 ( V_323 ) ;
V_347 = 1 ;
}
F_115 ( V_68 ) ;
}
}
return V_37 ;
}
static void F_243 ( struct V_10 * V_11 )
{
F_244 ( V_346 , & V_11 -> V_345 ) ;
F_245 () ;
F_246 ( & V_11 -> V_345 , V_346 ) ;
}
static void F_247 ( struct V_129 * V_129 )
{
struct V_10 * V_11 = (struct V_10 * ) V_129 -> V_59 ;
struct V_354 * V_355 = F_19 ( V_11 -> V_32 -> V_203 ) ;
F_123 ( V_129 ) ;
if ( F_248 ( V_356 , & V_11 -> V_345 ) )
return;
switch ( V_11 -> V_357 ) {
case - 1 :
F_239 ( V_358 , & V_355 -> V_359 ) ;
break;
case 0 :
F_239 ( V_360 , & V_355 -> V_359 ) ;
break;
case 1 :
F_239 ( V_361 , & V_355 -> V_359 ) ;
break;
default:
F_249 () ;
}
}
static void F_250 ( struct V_50 * V_50 )
{
struct V_245 * V_246 ;
struct V_10 * V_11 ;
int V_140 , V_147 ;
F_170 (bvec, bio, i) {
struct V_129 * V_129 = V_246 -> V_247 ;
V_11 = (struct V_10 * ) V_129 -> V_59 ;
F_23 ( ! V_11 ) ;
V_147 = F_44 ( & V_11 -> V_362 ) ;
if ( V_50 -> V_250 ||
F_160 ( V_356 , & V_11 -> V_345 ) ) {
F_168 ( V_129 ) ;
F_247 ( V_129 ) ;
}
F_124 ( V_129 ) ;
if ( ! V_147 )
continue;
F_243 ( V_11 ) ;
}
F_140 ( V_50 ) ;
}
static T_13 int F_251 ( struct V_10 * V_11 ,
struct V_41 * V_32 ,
struct V_276 * V_277 ,
struct V_322 * V_323 )
{
struct V_262 * V_194 = V_32 -> V_228 -> V_229 ;
struct V_24 * V_25 = & F_19 ( V_32 -> V_203 ) -> V_152 ;
T_1 V_64 = V_11 -> V_15 ;
unsigned long V_140 , V_201 ;
unsigned long V_216 = 0 ;
int V_272 = ( V_323 -> V_348 ? V_197 : V_190 ) | V_363 ;
int V_37 = 0 ;
F_244 ( V_356 , & V_11 -> V_345 ) ;
V_201 = F_148 ( V_11 -> V_15 , V_11 -> V_21 ) ;
F_40 ( & V_11 -> V_362 , V_201 ) ;
if ( F_252 ( V_11 ) == V_364 )
V_216 = V_365 ;
for ( V_140 = 0 ; V_140 < V_201 ; V_140 ++ ) {
struct V_129 * V_68 = V_11 -> V_138 [ V_140 ] ;
F_100 ( V_68 ) ;
F_106 ( V_68 ) ;
V_37 = F_189 ( V_272 , V_25 , V_277 , V_68 , V_64 >> 9 ,
V_149 , 0 , V_194 , & V_323 -> V_50 ,
- 1 , F_250 ,
0 , V_323 -> V_216 , V_216 , false ) ;
V_323 -> V_216 = V_216 ;
if ( V_37 ) {
F_247 ( V_68 ) ;
F_124 ( V_68 ) ;
if ( F_253 ( V_201 - V_140 , & V_11 -> V_362 ) )
F_243 ( V_11 ) ;
V_37 = - V_154 ;
break;
}
V_64 += V_149 ;
F_221 ( V_68 , V_277 , 1 ) ;
F_113 ( V_68 ) ;
}
if ( F_178 ( V_37 ) ) {
for (; V_140 < V_201 ; V_140 ++ ) {
struct V_129 * V_68 = V_11 -> V_138 [ V_140 ] ;
F_100 ( V_68 ) ;
F_113 ( V_68 ) ;
}
}
return V_37 ;
}
int F_254 ( struct V_53 * V_28 ,
struct V_276 * V_277 )
{
struct V_24 * V_25 = & F_19 ( V_28 -> V_29 ) -> V_152 ;
struct V_41 * V_32 = F_19 ( V_28 -> V_29 ) -> V_31 -> V_32 ;
struct V_10 * V_11 , * V_366 = NULL ;
struct V_322 V_323 = {
. V_50 = NULL ,
. V_25 = V_25 ,
. V_327 = 0 ,
. V_348 = V_277 -> V_341 == V_342 ,
. V_216 = 0 ,
} ;
int V_37 = 0 ;
int V_147 = 0 ;
int V_367 = 0 ;
struct V_368 V_369 ;
int V_139 ;
T_9 V_126 ;
T_9 V_16 ;
int V_370 = 0 ;
int V_371 ;
F_255 ( & V_369 , 0 ) ;
if ( V_277 -> V_317 ) {
V_126 = V_28 -> V_321 ;
V_16 = - 1 ;
} else {
V_126 = V_277 -> V_318 >> V_127 ;
V_16 = V_277 -> V_319 >> V_127 ;
V_370 = 1 ;
}
if ( V_277 -> V_341 == V_342 )
V_371 = V_372 ;
else
V_371 = V_373 ;
V_374:
if ( V_277 -> V_341 == V_342 )
F_256 ( V_28 , V_126 , V_16 ) ;
while ( ! V_147 && ! V_367 && ( V_126 <= V_16 ) &&
( V_139 = F_257 ( & V_369 , V_28 , & V_126 , V_371 ,
F_126 ( V_16 - V_126 , ( T_9 ) V_375 - 1 ) + 1 ) ) ) {
unsigned V_140 ;
V_370 = 1 ;
for ( V_140 = 0 ; V_140 < V_139 ; V_140 ++ ) {
struct V_129 * V_129 = V_369 . V_138 [ V_140 ] ;
if ( ! F_194 ( V_129 ) )
continue;
if ( ! V_277 -> V_317 && V_129 -> V_126 > V_16 ) {
V_147 = 1 ;
break;
}
F_75 ( & V_28 -> V_376 ) ;
if ( ! F_194 ( V_129 ) ) {
F_78 ( & V_28 -> V_376 ) ;
continue;
}
V_11 = (struct V_10 * ) V_129 -> V_59 ;
if ( F_45 ( ! V_11 ) ) {
F_78 ( & V_28 -> V_376 ) ;
continue;
}
if ( V_11 == V_366 ) {
F_78 ( & V_28 -> V_376 ) ;
continue;
}
V_37 = F_258 ( & V_11 -> V_17 ) ;
F_78 ( & V_28 -> V_376 ) ;
if ( ! V_37 )
continue;
V_366 = V_11 ;
V_37 = F_233 ( V_11 , V_32 , & V_323 ) ;
if ( ! V_37 ) {
F_259 ( V_11 ) ;
continue;
}
V_37 = F_251 ( V_11 , V_32 , V_277 , & V_323 ) ;
if ( V_37 ) {
V_147 = 1 ;
F_259 ( V_11 ) ;
break;
}
F_259 ( V_11 ) ;
V_367 = V_277 -> V_316 <= 0 ;
}
F_260 ( & V_369 ) ;
F_79 () ;
}
if ( ! V_370 && ! V_147 ) {
V_370 = 1 ;
V_126 = 0 ;
goto V_374;
}
F_235 ( & V_323 ) ;
return V_37 ;
}
static int F_261 ( struct V_24 * V_25 ,
struct V_53 * V_28 ,
struct V_276 * V_277 ,
T_14 V_377 , void * V_225 ,
void (* F_262)( void * ) )
{
struct V_26 * V_26 = V_28 -> V_29 ;
int V_37 = 0 ;
int V_147 = 0 ;
int V_100 = 0 ;
int V_367 = 0 ;
struct V_368 V_369 ;
int V_139 ;
T_9 V_126 ;
T_9 V_16 ;
int V_370 = 0 ;
int V_371 ;
if ( ! F_263 ( V_26 ) )
return 0 ;
F_255 ( & V_369 , 0 ) ;
if ( V_277 -> V_317 ) {
V_126 = V_28 -> V_321 ;
V_16 = - 1 ;
} else {
V_126 = V_277 -> V_318 >> V_127 ;
V_16 = V_277 -> V_319 >> V_127 ;
V_370 = 1 ;
}
if ( V_277 -> V_341 == V_342 )
V_371 = V_372 ;
else
V_371 = V_373 ;
V_374:
if ( V_277 -> V_341 == V_342 )
F_256 ( V_28 , V_126 , V_16 ) ;
while ( ! V_147 && ! V_367 && ( V_126 <= V_16 ) &&
( V_139 = F_257 ( & V_369 , V_28 , & V_126 , V_371 ,
F_126 ( V_16 - V_126 , ( T_9 ) V_375 - 1 ) + 1 ) ) ) {
unsigned V_140 ;
V_370 = 1 ;
for ( V_140 = 0 ; V_140 < V_139 ; V_140 ++ ) {
struct V_129 * V_129 = V_369 . V_138 [ V_140 ] ;
if ( ! F_242 ( V_129 ) ) {
F_262 ( V_225 ) ;
F_115 ( V_129 ) ;
}
if ( F_178 ( V_129 -> V_28 != V_28 ) ) {
F_113 ( V_129 ) ;
continue;
}
if ( ! V_277 -> V_317 && V_129 -> V_126 > V_16 ) {
V_147 = 1 ;
F_113 ( V_129 ) ;
continue;
}
if ( V_277 -> V_341 != V_378 ) {
if ( F_226 ( V_129 ) )
F_262 ( V_225 ) ;
F_264 ( V_129 ) ;
}
if ( F_226 ( V_129 ) ||
! F_100 ( V_129 ) ) {
F_113 ( V_129 ) ;
continue;
}
V_37 = (* V_377)( V_129 , V_277 , V_225 ) ;
if ( F_178 ( V_37 == V_379 ) ) {
F_113 ( V_129 ) ;
V_37 = 0 ;
}
if ( ! V_100 && V_37 < 0 )
V_100 = V_37 ;
V_367 = V_277 -> V_316 <= 0 ;
}
F_260 ( & V_369 ) ;
F_79 () ;
}
if ( ! V_370 && ! V_147 && ! V_100 ) {
V_370 = 1 ;
V_126 = 0 ;
goto V_374;
}
F_265 ( V_26 ) ;
return V_100 ;
}
static void F_266 ( struct V_322 * V_323 )
{
if ( V_323 -> V_50 ) {
int V_272 = V_190 ;
int V_37 ;
if ( V_323 -> V_348 )
V_272 = V_197 ;
V_37 = F_185 ( V_272 , V_323 -> V_50 , 0 , V_323 -> V_216 ) ;
F_23 ( V_37 < 0 ) ;
V_323 -> V_50 = NULL ;
}
}
static T_5 void F_235 ( void * V_225 )
{
struct V_322 * V_323 = V_225 ;
F_266 ( V_323 ) ;
}
int F_267 ( struct V_24 * V_25 , struct V_129 * V_129 ,
T_12 * V_288 ,
struct V_276 * V_277 )
{
int V_37 ;
struct V_322 V_323 = {
. V_50 = NULL ,
. V_25 = V_25 ,
. V_288 = V_288 ,
. V_327 = 0 ,
. V_348 = V_277 -> V_341 == V_342 ,
. V_216 = 0 ,
} ;
V_37 = F_227 ( V_129 , V_277 , & V_323 ) ;
F_266 ( & V_323 ) ;
return V_37 ;
}
int F_268 ( struct V_24 * V_25 , struct V_26 * V_26 ,
T_1 V_15 , T_1 V_16 , T_12 * V_288 ,
int V_380 )
{
int V_37 = 0 ;
struct V_53 * V_28 = V_26 -> V_130 ;
struct V_129 * V_129 ;
unsigned long V_139 = ( V_16 - V_15 + V_149 ) >>
V_127 ;
struct V_322 V_323 = {
. V_50 = NULL ,
. V_25 = V_25 ,
. V_288 = V_288 ,
. V_327 = 1 ,
. V_348 = V_380 == V_342 ,
. V_216 = 0 ,
} ;
struct V_276 V_381 = {
. V_341 = V_380 ,
. V_316 = V_139 * 2 ,
. V_318 = V_15 ,
. V_319 = V_16 + 1 ,
} ;
while ( V_15 <= V_16 ) {
V_129 = F_99 ( V_28 , V_15 >> V_127 ) ;
if ( F_100 ( V_129 ) )
V_37 = F_227 ( V_129 , & V_381 , & V_323 ) ;
else {
if ( V_25 -> V_55 && V_25 -> V_55 -> V_244 )
V_25 -> V_55 -> V_244 ( V_129 , V_15 ,
V_15 + V_149 - 1 ,
NULL , 1 ) ;
F_113 ( V_129 ) ;
}
F_101 ( V_129 ) ;
V_15 += V_149 ;
}
F_266 ( & V_323 ) ;
return V_37 ;
}
int F_269 ( struct V_24 * V_25 ,
struct V_53 * V_28 ,
T_12 * V_288 ,
struct V_276 * V_277 )
{
int V_37 = 0 ;
struct V_322 V_323 = {
. V_50 = NULL ,
. V_25 = V_25 ,
. V_288 = V_288 ,
. V_327 = 0 ,
. V_348 = V_277 -> V_341 == V_342 ,
. V_216 = 0 ,
} ;
V_37 = F_261 ( V_25 , V_28 , V_277 ,
F_227 , & V_323 ,
F_235 ) ;
F_266 ( & V_323 ) ;
return V_37 ;
}
int F_270 ( struct V_24 * V_25 ,
struct V_53 * V_28 ,
struct V_4 * V_138 , unsigned V_139 ,
T_12 V_288 )
{
struct V_50 * V_50 = NULL ;
unsigned V_382 ;
unsigned long V_216 = 0 ;
struct V_129 * V_383 [ 16 ] ;
struct V_129 * V_129 ;
struct V_211 * V_289 = NULL ;
int V_296 = 0 ;
T_1 V_290 = ( T_1 ) - 1 ;
for ( V_382 = 0 ; V_382 < V_139 ; V_382 ++ ) {
V_129 = F_11 ( V_138 -> V_79 , struct V_129 , V_384 ) ;
F_271 ( & V_129 -> V_7 ) ;
F_8 ( & V_129 -> V_384 ) ;
if ( F_272 ( V_129 , V_28 ,
V_129 -> V_126 , V_125 ) ) {
F_101 ( V_129 ) ;
continue;
}
V_383 [ V_296 ++ ] = V_129 ;
if ( V_296 < F_273 ( V_383 ) )
continue;
F_217 ( V_25 , V_383 , V_296 , V_288 , & V_289 ,
& V_50 , 0 , & V_216 , V_314 , & V_290 ) ;
V_296 = 0 ;
}
if ( V_296 )
F_217 ( V_25 , V_383 , V_296 , V_288 , & V_289 ,
& V_50 , 0 , & V_216 , V_314 , & V_290 ) ;
if ( V_289 )
F_159 ( V_289 ) ;
F_23 ( ! F_10 ( V_138 ) ) ;
if ( V_50 )
return F_185 ( V_314 , V_50 , 0 , V_216 ) ;
return 0 ;
}
int F_274 ( struct V_24 * V_25 ,
struct V_129 * V_129 , unsigned long V_64 )
{
struct V_1 * V_102 = NULL ;
T_1 V_15 = F_131 ( V_129 ) ;
T_1 V_16 = V_15 + V_149 - 1 ;
T_10 V_299 = V_129 -> V_28 -> V_29 -> V_42 -> V_300 ;
V_15 += F_210 ( V_64 , V_299 ) ;
if ( V_15 > V_16 )
return 0 ;
F_96 ( V_25 , V_15 , V_16 , & V_102 ) ;
F_264 ( V_129 ) ;
F_94 ( V_25 , V_15 , V_16 ,
V_124 | V_98 | V_106 |
V_385 ,
1 , 1 , & V_102 , V_125 ) ;
return 0 ;
}
static int F_275 ( struct V_213 * V_386 ,
struct V_24 * V_25 ,
struct V_129 * V_129 , T_3 V_58 )
{
T_1 V_15 = F_131 ( V_129 ) ;
T_1 V_16 = V_15 + V_149 - 1 ;
int V_37 = 1 ;
if ( F_118 ( V_25 , V_15 , V_16 ,
V_85 , 0 , NULL ) )
V_37 = 0 ;
else {
if ( ( V_58 & V_125 ) == V_125 )
V_58 = V_125 ;
V_37 = F_94 ( V_25 , V_15 , V_16 ,
~ ( V_124 | V_387 ) ,
0 , 0 , NULL , V_58 ) ;
if ( V_37 < 0 )
V_37 = 0 ;
else
V_37 = 1 ;
}
return V_37 ;
}
int F_276 ( struct V_213 * V_386 ,
struct V_24 * V_25 , struct V_129 * V_129 ,
T_3 V_58 )
{
struct V_211 * V_212 ;
T_1 V_15 = F_131 ( V_129 ) ;
T_1 V_16 = V_15 + V_149 - 1 ;
if ( F_74 ( V_58 ) &&
V_129 -> V_28 -> V_29 -> V_259 > V_388 ) {
T_1 V_21 ;
while ( V_15 <= V_16 ) {
V_21 = V_16 - V_15 + 1 ;
F_277 ( & V_386 -> V_57 ) ;
V_212 = F_157 ( V_386 , V_15 , V_21 ) ;
if ( ! V_212 ) {
F_278 ( & V_386 -> V_57 ) ;
break;
}
if ( F_160 ( V_389 , & V_212 -> V_7 ) ||
V_212 -> V_15 != V_15 ) {
F_278 ( & V_386 -> V_57 ) ;
F_159 ( V_212 ) ;
break;
}
if ( ! F_118 ( V_25 , V_212 -> V_15 ,
F_201 ( V_212 ) - 1 ,
V_124 | V_390 ,
0 , NULL ) ) {
F_279 ( V_386 , V_212 ) ;
F_159 ( V_212 ) ;
}
V_15 = F_201 ( V_212 ) ;
F_278 ( & V_386 -> V_57 ) ;
F_159 ( V_212 ) ;
}
}
return F_275 ( V_386 , V_25 , V_129 , V_58 ) ;
}
static struct V_211 * F_280 ( struct V_26 * V_26 ,
T_1 V_64 ,
T_1 V_162 ,
T_12 * V_288 )
{
T_1 V_391 = F_19 ( V_26 ) -> V_31 -> V_391 ;
struct V_211 * V_212 ;
T_1 V_21 ;
if ( V_64 >= V_162 )
return NULL ;
while ( 1 ) {
V_21 = V_162 - V_64 ;
if ( V_21 == 0 )
break;
V_21 = F_210 ( V_21 , V_391 ) ;
V_212 = V_288 ( V_26 , NULL , 0 , V_64 , V_21 , 0 ) ;
if ( F_202 ( V_212 ) )
return V_212 ;
if ( ! F_160 ( V_392 , & V_212 -> V_7 ) &&
V_212 -> V_217 != V_307 ) {
return V_212 ;
}
V_64 = F_201 ( V_212 ) ;
F_159 ( V_212 ) ;
if ( V_64 >= V_162 )
break;
}
return NULL ;
}
int F_281 ( struct V_26 * V_26 , struct V_393 * V_394 ,
T_15 V_15 , T_15 V_21 , T_12 * V_288 )
{
int V_37 = 0 ;
T_1 V_260 = V_15 ;
T_1 F_127 = V_15 + V_21 ;
T_16 V_7 = 0 ;
T_16 V_395 ;
T_1 V_162 ;
T_1 V_396 = 0 ;
T_1 V_397 = 0 ;
T_1 V_27 = F_17 ( V_26 ) ;
struct V_398 V_399 ;
struct V_211 * V_212 = NULL ;
struct V_1 * V_102 = NULL ;
struct V_400 * V_401 ;
struct V_200 * V_31 = F_19 ( V_26 ) -> V_31 ;
int V_16 = 0 ;
T_1 V_402 = 0 ;
T_1 V_403 = 0 ;
T_1 V_338 = 0 ;
if ( V_21 == 0 )
return - V_404 ;
V_401 = F_282 () ;
if ( ! V_401 )
return - V_45 ;
V_401 -> V_405 = 1 ;
V_15 = F_283 ( V_15 , F_19 ( V_26 ) -> V_31 -> V_391 ) ;
V_21 = F_284 ( F_127 , F_19 ( V_26 ) -> V_31 -> V_391 ) - V_15 ;
V_37 = F_285 ( NULL , V_31 , V_401 , F_20 ( V_26 ) , - 1 ,
0 ) ;
if ( V_37 < 0 ) {
F_286 ( V_401 ) ;
return V_37 ;
}
F_45 ( ! V_37 ) ;
V_401 -> V_406 [ 0 ] -- ;
F_287 ( V_401 -> V_407 [ 0 ] , & V_399 , V_401 -> V_406 [ 0 ] ) ;
V_395 = V_399 . type ;
if ( V_399 . V_408 != F_20 ( V_26 ) ||
V_395 != V_409 ) {
V_162 = ( T_1 ) - 1 ;
V_396 = V_27 ;
} else {
V_162 = V_399 . V_64 ;
V_396 = V_162 + 1 ;
}
F_288 ( V_401 ) ;
if ( V_162 < V_27 ) {
V_162 = ( T_1 ) - 1 ;
V_396 = V_27 ;
}
F_96 ( & F_19 ( V_26 ) -> V_152 , V_15 , V_15 + V_21 - 1 ,
& V_102 ) ;
V_212 = F_280 ( V_26 , V_15 , V_396 ,
V_288 ) ;
if ( ! V_212 )
goto V_111;
if ( F_289 ( V_212 ) ) {
V_37 = F_290 ( V_212 ) ;
goto V_111;
}
while ( ! V_16 ) {
T_1 V_410 = 0 ;
if ( V_212 -> V_15 >= F_127 || F_201 ( V_212 ) < V_260 )
break;
V_402 = F_127 ( V_212 -> V_15 , V_260 ) ;
if ( ! F_160 ( V_218 , & V_212 -> V_7 ) )
V_410 = V_402 - V_212 -> V_15 ;
V_338 = F_201 ( V_212 ) ;
V_403 = V_338 - V_402 ;
V_397 = 0 ;
V_7 = 0 ;
V_260 = F_201 ( V_212 ) ;
if ( V_260 >= F_127 )
V_16 = 1 ;
if ( V_212 -> V_217 == V_411 ) {
V_16 = 1 ;
V_7 |= V_412 ;
} else if ( V_212 -> V_217 == V_309 ) {
V_7 |= ( V_413 |
V_414 ) ;
} else if ( V_212 -> V_217 == V_415 ) {
V_7 |= ( V_416 |
V_417 ) ;
} else if ( V_394 -> V_418 ) {
T_1 V_419 = V_212 -> V_217 -
( V_212 -> V_15 - V_212 -> V_308 ) ;
V_397 = V_212 -> V_217 + V_410 ;
V_37 = F_291 ( NULL , V_31 -> V_32 ,
V_31 -> V_408 ,
F_20 ( V_26 ) , V_419 ) ;
if ( V_37 < 0 )
goto V_420;
if ( V_37 )
V_7 |= V_421 ;
V_37 = 0 ;
}
if ( F_160 ( V_218 , & V_212 -> V_7 ) )
V_7 |= V_422 ;
if ( F_160 ( V_306 , & V_212 -> V_7 ) )
V_7 |= V_423 ;
F_159 ( V_212 ) ;
V_212 = NULL ;
if ( ( V_402 >= V_162 ) || V_403 == ( T_1 ) - 1 ||
( V_162 == ( T_1 ) - 1 && V_27 <= V_338 ) ) {
V_7 |= V_412 ;
V_16 = 1 ;
}
V_212 = F_280 ( V_26 , V_260 , V_396 ,
V_288 ) ;
if ( F_289 ( V_212 ) ) {
V_37 = F_290 ( V_212 ) ;
goto V_111;
}
if ( ! V_212 ) {
V_7 |= V_412 ;
V_16 = 1 ;
}
V_37 = F_292 ( V_394 , V_402 , V_397 ,
V_403 , V_7 ) ;
if ( V_37 ) {
if ( V_37 == 1 )
V_37 = 0 ;
goto V_420;
}
}
V_420:
F_159 ( V_212 ) ;
V_111:
F_286 ( V_401 ) ;
F_119 ( & F_19 ( V_26 ) -> V_152 , V_15 , V_15 + V_21 - 1 ,
& V_102 , V_125 ) ;
return V_37 ;
}
static void F_293 ( struct V_10 * V_11 )
{
F_7 ( & V_11 -> V_14 ) ;
F_14 ( V_22 , V_11 ) ;
}
int F_294 ( struct V_10 * V_11 )
{
return ( F_13 ( & V_11 -> V_362 ) ||
F_160 ( V_346 , & V_11 -> V_345 ) ||
F_160 ( V_350 , & V_11 -> V_345 ) ) ;
}
static void F_295 ( struct V_10 * V_11 )
{
unsigned long V_126 ;
struct V_129 * V_129 ;
int V_424 = ! F_160 ( V_425 , & V_11 -> V_345 ) ;
F_23 ( F_294 ( V_11 ) ) ;
V_126 = F_148 ( V_11 -> V_15 , V_11 -> V_21 ) ;
if ( V_126 == 0 )
return;
do {
V_126 -- ;
V_129 = V_11 -> V_138 [ V_126 ] ;
if ( ! V_129 )
continue;
if ( V_424 )
F_75 ( & V_129 -> V_28 -> V_376 ) ;
if ( F_194 ( V_129 ) &&
V_129 -> V_59 == ( unsigned long ) V_11 ) {
F_23 ( F_160 ( V_350 , & V_11 -> V_345 ) ) ;
F_23 ( F_116 ( V_129 ) ) ;
F_23 ( F_226 ( V_129 ) ) ;
F_296 ( V_129 ) ;
F_197 ( V_129 , 0 ) ;
F_101 ( V_129 ) ;
}
if ( V_424 )
F_78 ( & V_129 -> V_28 -> V_376 ) ;
F_101 ( V_129 ) ;
} while ( V_126 != 0 );
}
static inline void F_297 ( struct V_10 * V_11 )
{
F_295 ( V_11 ) ;
F_293 ( V_11 ) ;
}
static struct V_10 *
F_298 ( struct V_41 * V_32 , T_1 V_15 ,
unsigned long V_21 )
{
struct V_10 * V_11 = NULL ;
V_11 = F_299 ( V_22 , V_125 | V_426 ) ;
V_11 -> V_15 = V_15 ;
V_11 -> V_21 = V_21 ;
V_11 -> V_32 = V_32 ;
V_11 -> V_345 = 0 ;
F_300 ( & V_11 -> V_57 ) ;
F_40 ( & V_11 -> V_427 , 0 ) ;
F_40 ( & V_11 -> V_428 , 0 ) ;
F_40 ( & V_11 -> V_429 , 0 ) ;
F_40 ( & V_11 -> V_430 , 0 ) ;
F_40 ( & V_11 -> V_431 , 0 ) ;
F_40 ( & V_11 -> V_432 , 0 ) ;
V_11 -> V_433 = 0 ;
F_41 ( & V_11 -> V_434 ) ;
F_41 ( & V_11 -> V_435 ) ;
F_3 ( & V_11 -> V_14 , & V_19 ) ;
F_36 ( & V_11 -> V_349 ) ;
F_40 ( & V_11 -> V_17 , 1 ) ;
F_40 ( & V_11 -> V_362 , 0 ) ;
F_301 ( V_436
> V_437 ) ;
F_23 ( V_21 > V_437 ) ;
return V_11 ;
}
struct V_10 * F_302 ( struct V_10 * V_438 )
{
unsigned long V_140 ;
struct V_129 * V_68 ;
struct V_10 * V_5 ;
unsigned long V_201 = F_148 ( V_438 -> V_15 , V_438 -> V_21 ) ;
V_5 = F_298 ( V_438 -> V_32 , V_438 -> V_15 , V_438 -> V_21 ) ;
if ( V_5 == NULL )
return NULL ;
for ( V_140 = 0 ; V_140 < V_201 ; V_140 ++ ) {
V_68 = F_303 ( V_125 ) ;
if ( ! V_68 ) {
F_297 ( V_5 ) ;
return NULL ;
}
F_193 ( V_5 , V_68 ) ;
F_45 ( F_116 ( V_68 ) ) ;
F_132 ( V_68 ) ;
V_5 -> V_138 [ V_140 ] = V_68 ;
}
F_304 ( V_5 , V_438 , 0 , 0 , V_438 -> V_21 ) ;
F_239 ( V_439 , & V_5 -> V_345 ) ;
F_239 ( V_425 , & V_5 -> V_345 ) ;
return V_5 ;
}
struct V_10 * F_305 ( struct V_41 * V_32 ,
T_1 V_15 , unsigned long V_21 )
{
struct V_10 * V_11 ;
unsigned long V_201 ;
unsigned long V_140 ;
V_201 = F_148 ( V_15 , V_21 ) ;
V_11 = F_298 ( V_32 , V_15 , V_21 ) ;
if ( ! V_11 )
return NULL ;
for ( V_140 = 0 ; V_140 < V_201 ; V_140 ++ ) {
V_11 -> V_138 [ V_140 ] = F_303 ( V_125 ) ;
if ( ! V_11 -> V_138 [ V_140 ] )
goto V_100;
}
F_306 ( V_11 ) ;
F_307 ( V_11 , 0 ) ;
F_239 ( V_425 , & V_11 -> V_345 ) ;
return V_11 ;
V_100:
for (; V_140 > 0 ; V_140 -- )
F_308 ( V_11 -> V_138 [ V_140 - 1 ] ) ;
F_293 ( V_11 ) ;
return NULL ;
}
struct V_10 * F_309 ( struct V_41 * V_32 ,
T_1 V_15 )
{
unsigned long V_21 ;
if ( ! V_32 ) {
V_21 = 4096 ;
} else {
V_21 = V_32 -> V_440 -> V_441 ;
}
return F_305 ( V_32 , V_15 , V_21 ) ;
}
static void F_310 ( struct V_10 * V_11 )
{
int V_17 ;
V_17 = F_13 ( & V_11 -> V_17 ) ;
if ( V_17 >= 2 && F_160 ( V_442 , & V_11 -> V_345 ) )
return;
F_75 ( & V_11 -> V_349 ) ;
if ( ! F_248 ( V_442 , & V_11 -> V_345 ) )
F_86 ( & V_11 -> V_17 ) ;
F_78 ( & V_11 -> V_349 ) ;
}
static void F_311 ( struct V_10 * V_11 ,
struct V_129 * V_443 )
{
unsigned long V_201 , V_140 ;
F_310 ( V_11 ) ;
V_201 = F_148 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_140 = 0 ; V_140 < V_201 ; V_140 ++ ) {
struct V_129 * V_68 = V_11 -> V_138 [ V_140 ] ;
if ( V_68 != V_443 )
F_312 ( V_68 ) ;
}
}
struct V_10 * F_313 ( struct V_41 * V_32 ,
T_1 V_15 )
{
struct V_10 * V_11 ;
F_314 () ;
V_11 = F_315 ( & V_32 -> V_444 ,
V_15 >> V_127 ) ;
if ( V_11 && F_258 ( & V_11 -> V_17 ) ) {
F_316 () ;
if ( F_160 ( V_445 , & V_11 -> V_345 ) ) {
F_75 ( & V_11 -> V_349 ) ;
F_78 ( & V_11 -> V_349 ) ;
}
F_311 ( V_11 , NULL ) ;
return V_11 ;
}
F_316 () ;
return NULL ;
}
struct V_10 * F_317 ( struct V_41 * V_32 ,
T_1 V_15 )
{
struct V_10 * V_11 , * V_446 = NULL ;
int V_37 ;
V_11 = F_313 ( V_32 , V_15 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_309 ( V_32 , V_15 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_32 = V_32 ;
V_109:
V_37 = F_318 ( V_125 & ~ V_447 ) ;
if ( V_37 )
goto V_448;
F_75 ( & V_32 -> V_449 ) ;
V_37 = F_319 ( & V_32 -> V_444 ,
V_15 >> V_127 , V_11 ) ;
F_78 ( & V_32 -> V_449 ) ;
F_320 () ;
if ( V_37 == - V_90 ) {
V_446 = F_313 ( V_32 , V_15 ) ;
if ( V_446 )
goto V_448;
else
goto V_109;
}
F_310 ( V_11 ) ;
F_239 ( V_450 , & V_11 -> V_345 ) ;
F_86 ( & V_11 -> V_17 ) ;
return V_11 ;
V_448:
F_297 ( V_11 ) ;
return V_446 ;
}
struct V_10 * F_321 ( struct V_41 * V_32 ,
T_1 V_15 )
{
unsigned long V_21 = V_32 -> V_440 -> V_441 ;
unsigned long V_201 = F_148 ( V_15 , V_21 ) ;
unsigned long V_140 ;
unsigned long V_126 = V_15 >> V_127 ;
struct V_10 * V_11 ;
struct V_10 * V_446 = NULL ;
struct V_129 * V_68 ;
struct V_53 * V_28 = V_32 -> V_203 -> V_130 ;
int V_243 = 1 ;
int V_37 ;
V_11 = F_313 ( V_32 , V_15 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_298 ( V_32 , V_15 , V_21 ) ;
if ( ! V_11 )
return NULL ;
for ( V_140 = 0 ; V_140 < V_201 ; V_140 ++ , V_126 ++ ) {
V_68 = F_322 ( V_28 , V_126 , V_125 | V_426 ) ;
if ( ! V_68 )
goto V_448;
F_75 ( & V_28 -> V_376 ) ;
if ( F_194 ( V_68 ) ) {
V_446 = (struct V_10 * ) V_68 -> V_59 ;
if ( F_258 ( & V_446 -> V_17 ) ) {
F_78 ( & V_28 -> V_376 ) ;
F_113 ( V_68 ) ;
F_101 ( V_68 ) ;
F_311 ( V_446 , V_68 ) ;
goto V_448;
}
V_446 = NULL ;
F_296 ( V_68 ) ;
F_45 ( F_116 ( V_68 ) ) ;
F_101 ( V_68 ) ;
}
F_193 ( V_11 , V_68 ) ;
F_78 ( & V_28 -> V_376 ) ;
F_45 ( F_116 ( V_68 ) ) ;
V_11 -> V_138 [ V_140 ] = V_68 ;
if ( ! F_204 ( V_68 ) )
V_243 = 0 ;
}
if ( V_243 )
F_239 ( V_439 , & V_11 -> V_345 ) ;
V_109:
V_37 = F_318 ( V_125 & ~ V_447 ) ;
if ( V_37 )
goto V_448;
F_75 ( & V_32 -> V_449 ) ;
V_37 = F_319 ( & V_32 -> V_444 ,
V_15 >> V_127 , V_11 ) ;
F_78 ( & V_32 -> V_449 ) ;
F_320 () ;
if ( V_37 == - V_90 ) {
V_446 = F_313 ( V_32 , V_15 ) ;
if ( V_446 )
goto V_448;
else
goto V_109;
}
F_310 ( V_11 ) ;
F_239 ( V_450 , & V_11 -> V_345 ) ;
F_323 ( V_11 -> V_138 [ 0 ] ) ;
for ( V_140 = 1 ; V_140 < V_201 ; V_140 ++ ) {
V_68 = V_11 -> V_138 [ V_140 ] ;
F_324 ( V_68 ) ;
F_113 ( V_68 ) ;
}
F_113 ( V_11 -> V_138 [ 0 ] ) ;
return V_11 ;
V_448:
F_45 ( ! F_44 ( & V_11 -> V_17 ) ) ;
for ( V_140 = 0 ; V_140 < V_201 ; V_140 ++ ) {
if ( V_11 -> V_138 [ V_140 ] )
F_113 ( V_11 -> V_138 [ V_140 ] ) ;
}
F_297 ( V_11 ) ;
return V_446 ;
}
static inline void F_325 ( struct V_451 * V_6 )
{
struct V_10 * V_11 =
F_326 ( V_6 , struct V_10 , V_451 ) ;
F_293 ( V_11 ) ;
}
static int F_327 ( struct V_10 * V_11 )
{
F_45 ( F_13 ( & V_11 -> V_17 ) == 0 ) ;
if ( F_44 ( & V_11 -> V_17 ) ) {
if ( F_238 ( V_450 , & V_11 -> V_345 ) ) {
struct V_41 * V_32 = V_11 -> V_32 ;
F_78 ( & V_11 -> V_349 ) ;
F_75 ( & V_32 -> V_449 ) ;
F_328 ( & V_32 -> V_444 ,
V_11 -> V_15 >> V_127 ) ;
F_78 ( & V_32 -> V_449 ) ;
} else {
F_78 ( & V_11 -> V_349 ) ;
}
F_295 ( V_11 ) ;
#ifdef F_329
if ( F_178 ( F_160 ( V_425 , & V_11 -> V_345 ) ) ) {
F_293 ( V_11 ) ;
return 1 ;
}
#endif
F_330 ( & V_11 -> V_451 , F_325 ) ;
return 1 ;
}
F_78 ( & V_11 -> V_349 ) ;
return 0 ;
}
void F_259 ( struct V_10 * V_11 )
{
int V_17 ;
int V_452 ;
if ( ! V_11 )
return;
while ( 1 ) {
V_17 = F_13 ( & V_11 -> V_17 ) ;
if ( V_17 <= 3 )
break;
V_452 = F_331 ( & V_11 -> V_17 , V_17 , V_17 - 1 ) ;
if ( V_452 == V_17 )
return;
}
F_75 ( & V_11 -> V_349 ) ;
if ( F_13 ( & V_11 -> V_17 ) == 2 &&
F_160 ( V_425 , & V_11 -> V_345 ) )
F_76 ( & V_11 -> V_17 ) ;
if ( F_13 ( & V_11 -> V_17 ) == 2 &&
F_160 ( V_445 , & V_11 -> V_345 ) &&
! F_294 ( V_11 ) &&
F_238 ( V_442 , & V_11 -> V_345 ) )
F_76 ( & V_11 -> V_17 ) ;
F_327 ( V_11 ) ;
}
void F_332 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return;
F_75 ( & V_11 -> V_349 ) ;
F_239 ( V_445 , & V_11 -> V_345 ) ;
if ( F_13 ( & V_11 -> V_17 ) == 2 && ! F_294 ( V_11 ) &&
F_238 ( V_442 , & V_11 -> V_345 ) )
F_76 ( & V_11 -> V_17 ) ;
F_327 ( V_11 ) ;
}
void F_333 ( struct V_10 * V_11 )
{
unsigned long V_140 ;
unsigned long V_201 ;
struct V_129 * V_129 ;
V_201 = F_148 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_140 = 0 ; V_140 < V_201 ; V_140 ++ ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
if ( ! F_116 ( V_129 ) )
continue;
F_115 ( V_129 ) ;
F_45 ( ! F_194 ( V_129 ) ) ;
F_100 ( V_129 ) ;
F_334 ( & V_129 -> V_28 -> V_453 ) ;
if ( ! F_116 ( V_129 ) ) {
F_335 ( & V_129 -> V_28 -> V_454 ,
F_336 ( V_129 ) ,
V_373 ) ;
}
F_337 ( & V_129 -> V_28 -> V_453 ) ;
F_230 ( V_129 ) ;
F_113 ( V_129 ) ;
}
F_45 ( F_13 ( & V_11 -> V_17 ) == 0 ) ;
}
int F_338 ( struct V_10 * V_11 )
{
unsigned long V_140 ;
unsigned long V_201 ;
int V_455 = 0 ;
F_310 ( V_11 ) ;
V_455 = F_248 ( V_350 , & V_11 -> V_345 ) ;
V_201 = F_148 ( V_11 -> V_15 , V_11 -> V_21 ) ;
F_45 ( F_13 ( & V_11 -> V_17 ) == 0 ) ;
F_45 ( ! F_160 ( V_442 , & V_11 -> V_345 ) ) ;
for ( V_140 = 0 ; V_140 < V_201 ; V_140 ++ )
F_339 ( V_11 -> V_138 [ V_140 ] ) ;
return V_455 ;
}
void F_340 ( struct V_10 * V_11 )
{
unsigned long V_140 ;
struct V_129 * V_129 ;
unsigned long V_201 ;
F_244 ( V_439 , & V_11 -> V_345 ) ;
V_201 = F_148 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_140 = 0 ; V_140 < V_201 ; V_140 ++ ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
if ( V_129 )
F_168 ( V_129 ) ;
}
}
void F_306 ( struct V_10 * V_11 )
{
unsigned long V_140 ;
struct V_129 * V_129 ;
unsigned long V_201 ;
F_239 ( V_439 , & V_11 -> V_345 ) ;
V_201 = F_148 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_140 = 0 ; V_140 < V_201 ; V_140 ++ ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
F_132 ( V_129 ) ;
}
}
int F_341 ( struct V_10 * V_11 )
{
return F_160 ( V_439 , & V_11 -> V_345 ) ;
}
int F_342 ( struct V_24 * V_25 ,
struct V_10 * V_11 , T_1 V_15 , int V_113 ,
T_12 * V_288 , int V_175 )
{
unsigned long V_140 ;
unsigned long V_456 ;
struct V_129 * V_129 ;
int V_100 ;
int V_37 = 0 ;
int V_457 = 0 ;
int V_458 = 1 ;
unsigned long V_201 ;
unsigned long V_459 = 0 ;
struct V_50 * V_50 = NULL ;
unsigned long V_216 = 0 ;
if ( F_160 ( V_439 , & V_11 -> V_345 ) )
return 0 ;
if ( V_15 ) {
F_45 ( V_15 < V_11 -> V_15 ) ;
V_456 = ( V_15 >> V_127 ) -
( V_11 -> V_15 >> V_127 ) ;
} else {
V_456 = 0 ;
}
V_201 = F_148 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_140 = V_456 ; V_140 < V_201 ; V_140 ++ ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
if ( V_113 == V_460 ) {
if ( ! F_242 ( V_129 ) )
goto V_461;
} else {
F_115 ( V_129 ) ;
}
V_457 ++ ;
if ( ! F_204 ( V_129 ) ) {
V_459 ++ ;
V_458 = 0 ;
}
}
if ( V_458 ) {
if ( V_456 == 0 )
F_239 ( V_439 , & V_11 -> V_345 ) ;
goto V_461;
}
F_244 ( V_462 , & V_11 -> V_345 ) ;
V_11 -> V_463 = 0 ;
F_40 ( & V_11 -> V_362 , V_459 ) ;
for ( V_140 = V_456 ; V_140 < V_201 ; V_140 ++ ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
if ( ! F_204 ( V_129 ) ) {
F_230 ( V_129 ) ;
V_100 = F_218 ( V_25 , V_129 ,
V_288 , & V_50 ,
V_175 , & V_216 ,
V_314 | V_363 ) ;
if ( V_100 )
V_37 = V_100 ;
} else {
F_113 ( V_129 ) ;
}
}
if ( V_50 ) {
V_100 = F_185 ( V_314 | V_363 , V_50 , V_175 ,
V_216 ) ;
if ( V_100 )
return V_100 ;
}
if ( V_37 || V_113 != V_464 )
return V_37 ;
for ( V_140 = V_456 ; V_140 < V_201 ; V_140 ++ ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
F_343 ( V_129 ) ;
if ( ! F_204 ( V_129 ) )
V_37 = - V_154 ;
}
return V_37 ;
V_461:
V_140 = V_456 ;
while ( V_457 > 0 ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
V_140 ++ ;
F_113 ( V_129 ) ;
V_457 -- ;
}
return V_37 ;
}
void F_344 ( struct V_10 * V_11 , void * V_465 ,
unsigned long V_15 ,
unsigned long V_21 )
{
T_10 V_292 ;
T_10 V_64 ;
struct V_129 * V_129 ;
char * V_466 ;
char * V_467 = ( char * ) V_465 ;
T_10 V_468 = V_11 -> V_15 & ( ( T_1 ) V_149 - 1 ) ;
unsigned long V_140 = ( V_468 + V_15 ) >> V_127 ;
F_45 ( V_15 > V_11 -> V_21 ) ;
F_45 ( V_15 + V_21 > V_11 -> V_15 + V_11 -> V_21 ) ;
V_64 = ( V_468 + V_15 ) & ( V_149 - 1 ) ;
while ( V_21 > 0 ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
V_292 = F_126 ( V_21 , ( V_149 - V_64 ) ) ;
V_466 = F_345 ( V_129 ) ;
memcpy ( V_467 , V_466 + V_64 , V_292 ) ;
V_467 += V_292 ;
V_21 -= V_292 ;
V_64 = 0 ;
V_140 ++ ;
}
}
int F_346 ( struct V_10 * V_11 , void T_17 * V_465 ,
unsigned long V_15 ,
unsigned long V_21 )
{
T_10 V_292 ;
T_10 V_64 ;
struct V_129 * V_129 ;
char * V_466 ;
char T_17 * V_467 = ( char T_17 * ) V_465 ;
T_10 V_468 = V_11 -> V_15 & ( ( T_1 ) V_149 - 1 ) ;
unsigned long V_140 = ( V_468 + V_15 ) >> V_127 ;
int V_37 = 0 ;
F_45 ( V_15 > V_11 -> V_21 ) ;
F_45 ( V_15 + V_21 > V_11 -> V_15 + V_11 -> V_21 ) ;
V_64 = ( V_468 + V_15 ) & ( V_149 - 1 ) ;
while ( V_21 > 0 ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
V_292 = F_126 ( V_21 , ( V_149 - V_64 ) ) ;
V_466 = F_345 ( V_129 ) ;
if ( F_347 ( V_467 , V_466 + V_64 , V_292 ) ) {
V_37 = - V_469 ;
break;
}
V_467 += V_292 ;
V_21 -= V_292 ;
V_64 = 0 ;
V_140 ++ ;
}
return V_37 ;
}
int F_348 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_470 , char * * V_386 ,
unsigned long * V_471 ,
unsigned long * V_472 )
{
T_10 V_64 = V_15 & ( V_149 - 1 ) ;
char * V_466 ;
struct V_129 * V_68 ;
T_10 V_468 = V_11 -> V_15 & ( ( T_1 ) V_149 - 1 ) ;
unsigned long V_140 = ( V_468 + V_15 ) >> V_127 ;
unsigned long V_473 = ( V_468 + V_15 + V_470 - 1 ) >>
V_127 ;
if ( V_140 != V_473 )
return - V_404 ;
if ( V_140 == 0 ) {
V_64 = V_468 ;
* V_471 = 0 ;
} else {
V_64 = 0 ;
* V_471 = ( ( T_1 ) V_140 << V_127 ) - V_468 ;
}
if ( V_15 + V_470 > V_11 -> V_21 ) {
F_62 ( 1 , V_20 L_28
L_29 ,
V_11 -> V_15 , V_11 -> V_21 , V_15 , V_470 ) ;
return - V_404 ;
}
V_68 = V_11 -> V_138 [ V_140 ] ;
V_466 = F_345 ( V_68 ) ;
* V_386 = V_466 + V_64 ;
* V_472 = V_149 - V_64 ;
return 0 ;
}
int F_349 ( struct V_10 * V_11 , const void * V_474 ,
unsigned long V_15 ,
unsigned long V_21 )
{
T_10 V_292 ;
T_10 V_64 ;
struct V_129 * V_129 ;
char * V_466 ;
char * V_475 = ( char * ) V_474 ;
T_10 V_468 = V_11 -> V_15 & ( ( T_1 ) V_149 - 1 ) ;
unsigned long V_140 = ( V_468 + V_15 ) >> V_127 ;
int V_37 = 0 ;
F_45 ( V_15 > V_11 -> V_21 ) ;
F_45 ( V_15 + V_21 > V_11 -> V_15 + V_11 -> V_21 ) ;
V_64 = ( V_468 + V_15 ) & ( V_149 - 1 ) ;
while ( V_21 > 0 ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
V_292 = F_126 ( V_21 , ( V_149 - V_64 ) ) ;
V_466 = F_345 ( V_129 ) ;
V_37 = memcmp ( V_475 , V_466 + V_64 , V_292 ) ;
if ( V_37 )
break;
V_475 += V_292 ;
V_21 -= V_292 ;
V_64 = 0 ;
V_140 ++ ;
}
return V_37 ;
}
void F_350 ( struct V_10 * V_11 , const void * V_476 ,
unsigned long V_15 , unsigned long V_21 )
{
T_10 V_292 ;
T_10 V_64 ;
struct V_129 * V_129 ;
char * V_466 ;
char * V_438 = ( char * ) V_476 ;
T_10 V_468 = V_11 -> V_15 & ( ( T_1 ) V_149 - 1 ) ;
unsigned long V_140 = ( V_468 + V_15 ) >> V_127 ;
F_45 ( V_15 > V_11 -> V_21 ) ;
F_45 ( V_15 + V_21 > V_11 -> V_15 + V_11 -> V_21 ) ;
V_64 = ( V_468 + V_15 ) & ( V_149 - 1 ) ;
while ( V_21 > 0 ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
F_45 ( ! F_204 ( V_129 ) ) ;
V_292 = F_126 ( V_21 , V_149 - V_64 ) ;
V_466 = F_345 ( V_129 ) ;
memcpy ( V_466 + V_64 , V_438 , V_292 ) ;
V_438 += V_292 ;
V_21 -= V_292 ;
V_64 = 0 ;
V_140 ++ ;
}
}
void F_351 ( struct V_10 * V_11 , char V_477 ,
unsigned long V_15 , unsigned long V_21 )
{
T_10 V_292 ;
T_10 V_64 ;
struct V_129 * V_129 ;
char * V_466 ;
T_10 V_468 = V_11 -> V_15 & ( ( T_1 ) V_149 - 1 ) ;
unsigned long V_140 = ( V_468 + V_15 ) >> V_127 ;
F_45 ( V_15 > V_11 -> V_21 ) ;
F_45 ( V_15 + V_21 > V_11 -> V_15 + V_11 -> V_21 ) ;
V_64 = ( V_468 + V_15 ) & ( V_149 - 1 ) ;
while ( V_21 > 0 ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
F_45 ( ! F_204 ( V_129 ) ) ;
V_292 = F_126 ( V_21 , V_149 - V_64 ) ;
V_466 = F_345 ( V_129 ) ;
memset ( V_466 + V_64 , V_477 , V_292 ) ;
V_21 -= V_292 ;
V_64 = 0 ;
V_140 ++ ;
}
}
void F_304 ( struct V_10 * V_467 , struct V_10 * V_438 ,
unsigned long V_478 , unsigned long V_479 ,
unsigned long V_21 )
{
T_1 V_480 = V_467 -> V_21 ;
T_10 V_292 ;
T_10 V_64 ;
struct V_129 * V_129 ;
char * V_466 ;
T_10 V_468 = V_467 -> V_15 & ( ( T_1 ) V_149 - 1 ) ;
unsigned long V_140 = ( V_468 + V_478 ) >> V_127 ;
F_45 ( V_438 -> V_21 != V_480 ) ;
V_64 = ( V_468 + V_478 ) &
( V_149 - 1 ) ;
while ( V_21 > 0 ) {
V_129 = V_467 -> V_138 [ V_140 ] ;
F_45 ( ! F_204 ( V_129 ) ) ;
V_292 = F_126 ( V_21 , ( unsigned long ) ( V_149 - V_64 ) ) ;
V_466 = F_345 ( V_129 ) ;
F_344 ( V_438 , V_466 + V_64 , V_479 , V_292 ) ;
V_479 += V_292 ;
V_21 -= V_292 ;
V_64 = 0 ;
V_140 ++ ;
}
}
static inline void F_352 ( struct V_10 * V_11 ,
unsigned long V_15 , unsigned long V_296 ,
unsigned long * F_336 ,
T_10 * F_131 )
{
T_10 V_468 = V_11 -> V_15 & ( ( T_1 ) V_149 - 1 ) ;
T_10 V_481 = F_353 ( V_296 ) ;
T_10 V_64 ;
V_64 = V_468 + V_15 + V_481 ;
* F_336 = V_64 >> V_127 ;
* F_131 = V_64 & ( V_149 - 1 ) ;
}
int F_354 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_296 )
{
char * V_466 ;
struct V_129 * V_129 ;
unsigned long V_140 ;
T_10 V_64 ;
F_352 ( V_11 , V_15 , V_296 , & V_140 , & V_64 ) ;
V_129 = V_11 -> V_138 [ V_140 ] ;
F_45 ( ! F_204 ( V_129 ) ) ;
V_466 = F_345 ( V_129 ) ;
return 1U & ( V_466 [ V_64 ] >> ( V_296 & ( V_482 - 1 ) ) ) ;
}
void F_355 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_483 , unsigned long V_21 )
{
char * V_466 ;
struct V_129 * V_129 ;
unsigned long V_140 ;
T_10 V_64 ;
const unsigned int V_274 = V_483 + V_21 ;
int V_116 = V_482 - ( V_483 % V_482 ) ;
unsigned int V_484 = F_356 ( V_483 ) ;
F_352 ( V_11 , V_15 , V_483 , & V_140 , & V_64 ) ;
V_129 = V_11 -> V_138 [ V_140 ] ;
F_45 ( ! F_204 ( V_129 ) ) ;
V_466 = F_345 ( V_129 ) ;
while ( V_21 >= V_116 ) {
V_466 [ V_64 ] |= V_484 ;
V_21 -= V_116 ;
V_116 = V_482 ;
V_484 = ~ 0U ;
if ( ++ V_64 >= V_149 && V_21 > 0 ) {
V_64 = 0 ;
V_129 = V_11 -> V_138 [ ++ V_140 ] ;
F_45 ( ! F_204 ( V_129 ) ) ;
V_466 = F_345 ( V_129 ) ;
}
}
if ( V_21 ) {
V_484 &= F_357 ( V_274 ) ;
V_466 [ V_64 ] |= V_484 ;
}
}
void F_358 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_483 , unsigned long V_21 )
{
char * V_466 ;
struct V_129 * V_129 ;
unsigned long V_140 ;
T_10 V_64 ;
const unsigned int V_274 = V_483 + V_21 ;
int V_96 = V_482 - ( V_483 % V_482 ) ;
unsigned int V_485 = F_356 ( V_483 ) ;
F_352 ( V_11 , V_15 , V_483 , & V_140 , & V_64 ) ;
V_129 = V_11 -> V_138 [ V_140 ] ;
F_45 ( ! F_204 ( V_129 ) ) ;
V_466 = F_345 ( V_129 ) ;
while ( V_21 >= V_96 ) {
V_466 [ V_64 ] &= ~ V_485 ;
V_21 -= V_96 ;
V_96 = V_482 ;
V_485 = ~ 0U ;
if ( ++ V_64 >= V_149 && V_21 > 0 ) {
V_64 = 0 ;
V_129 = V_11 -> V_138 [ ++ V_140 ] ;
F_45 ( ! F_204 ( V_129 ) ) ;
V_466 = F_345 ( V_129 ) ;
}
}
if ( V_21 ) {
V_485 &= F_357 ( V_274 ) ;
V_466 [ V_64 ] &= ~ V_485 ;
}
}
static inline bool F_359 ( unsigned long V_438 , unsigned long V_467 , unsigned long V_21 )
{
unsigned long V_486 = ( V_438 > V_467 ) ? V_438 - V_467 : V_467 - V_438 ;
return V_486 < V_21 ;
}
static void F_360 ( struct V_129 * V_487 , struct V_129 * V_488 ,
unsigned long V_489 , unsigned long V_490 ,
unsigned long V_21 )
{
char * V_491 = F_345 ( V_487 ) ;
char * V_492 ;
int V_493 = 0 ;
if ( V_487 != V_488 ) {
V_492 = F_345 ( V_488 ) ;
} else {
V_492 = V_491 ;
if ( F_359 ( V_490 , V_489 , V_21 ) )
V_493 = 1 ;
}
if ( V_493 )
memmove ( V_491 + V_489 , V_492 + V_490 , V_21 ) ;
else
memcpy ( V_491 + V_489 , V_492 + V_490 , V_21 ) ;
}
void F_361 ( struct V_10 * V_467 , unsigned long V_478 ,
unsigned long V_479 , unsigned long V_21 )
{
T_10 V_292 ;
T_10 V_494 ;
T_10 V_495 ;
T_10 V_468 = V_467 -> V_15 & ( ( T_1 ) V_149 - 1 ) ;
unsigned long V_496 ;
unsigned long V_497 ;
if ( V_479 + V_21 > V_467 -> V_21 ) {
F_171 ( V_467 -> V_32 ,
L_30
L_31 , V_479 , V_21 , V_467 -> V_21 ) ;
F_23 ( 1 ) ;
}
if ( V_478 + V_21 > V_467 -> V_21 ) {
F_171 ( V_467 -> V_32 ,
L_32
L_31 , V_478 , V_21 , V_467 -> V_21 ) ;
F_23 ( 1 ) ;
}
while ( V_21 > 0 ) {
V_494 = ( V_468 + V_478 ) &
( V_149 - 1 ) ;
V_495 = ( V_468 + V_479 ) &
( V_149 - 1 ) ;
V_496 = ( V_468 + V_478 ) >> V_127 ;
V_497 = ( V_468 + V_479 ) >> V_127 ;
V_292 = F_126 ( V_21 , ( unsigned long ) ( V_149 -
V_495 ) ) ;
V_292 = F_112 (unsigned long, cur,
(unsigned long)(PAGE_CACHE_SIZE - dst_off_in_page)) ;
F_360 ( V_467 -> V_138 [ V_496 ] , V_467 -> V_138 [ V_497 ] ,
V_494 , V_495 , V_292 ) ;
V_479 += V_292 ;
V_478 += V_292 ;
V_21 -= V_292 ;
}
}
void F_362 ( struct V_10 * V_467 , unsigned long V_478 ,
unsigned long V_479 , unsigned long V_21 )
{
T_10 V_292 ;
T_10 V_494 ;
T_10 V_495 ;
unsigned long V_498 = V_478 + V_21 - 1 ;
unsigned long V_499 = V_479 + V_21 - 1 ;
T_10 V_468 = V_467 -> V_15 & ( ( T_1 ) V_149 - 1 ) ;
unsigned long V_496 ;
unsigned long V_497 ;
if ( V_479 + V_21 > V_467 -> V_21 ) {
F_171 ( V_467 -> V_32 , L_30
L_33 , V_479 , V_21 , V_467 -> V_21 ) ;
F_23 ( 1 ) ;
}
if ( V_478 + V_21 > V_467 -> V_21 ) {
F_171 ( V_467 -> V_32 , L_32
L_33 , V_478 , V_21 , V_467 -> V_21 ) ;
F_23 ( 1 ) ;
}
if ( V_478 < V_479 ) {
F_361 ( V_467 , V_478 , V_479 , V_21 ) ;
return;
}
while ( V_21 > 0 ) {
V_496 = ( V_468 + V_498 ) >> V_127 ;
V_497 = ( V_468 + V_499 ) >> V_127 ;
V_494 = ( V_468 + V_498 ) &
( V_149 - 1 ) ;
V_495 = ( V_468 + V_499 ) &
( V_149 - 1 ) ;
V_292 = F_112 (unsigned long, len, src_off_in_page + 1 ) ;
V_292 = F_126 ( V_292 , V_494 + 1 ) ;
F_360 ( V_467 -> V_138 [ V_496 ] , V_467 -> V_138 [ V_497 ] ,
V_494 - V_292 + 1 ,
V_495 - V_292 + 1 , V_292 ) ;
V_498 -= V_292 ;
V_499 -= V_292 ;
V_21 -= V_292 ;
}
}
int F_363 ( struct V_129 * V_129 )
{
struct V_10 * V_11 ;
F_75 ( & V_129 -> V_28 -> V_376 ) ;
if ( ! F_194 ( V_129 ) ) {
F_78 ( & V_129 -> V_28 -> V_376 ) ;
return 1 ;
}
V_11 = (struct V_10 * ) V_129 -> V_59 ;
F_23 ( ! V_11 ) ;
F_75 ( & V_11 -> V_349 ) ;
if ( F_13 ( & V_11 -> V_17 ) != 1 || F_294 ( V_11 ) ) {
F_78 ( & V_11 -> V_349 ) ;
F_78 ( & V_129 -> V_28 -> V_376 ) ;
return 0 ;
}
F_78 ( & V_129 -> V_28 -> V_376 ) ;
if ( ! F_238 ( V_442 , & V_11 -> V_345 ) ) {
F_78 ( & V_11 -> V_349 ) ;
return 0 ;
}
return F_327 ( V_11 ) ;
}
