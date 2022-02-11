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
F_32 ( V_18 ) ;
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
V_2 -> V_59 = NULL ;
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
V_134 = V_30 ;
V_148 = 1 ;
goto V_109;
} else {
V_89 = 0 ;
goto V_149;
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
V_149:
return V_89 ;
}
void F_120 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_16 ,
struct V_129 * V_137 ,
unsigned V_122 ,
unsigned long V_150 )
{
struct V_24 * V_25 = & F_19 ( V_26 ) -> V_151 ;
int V_37 ;
struct V_129 * V_138 [ 16 ] ;
unsigned long V_126 = V_15 >> V_127 ;
unsigned long V_128 = V_16 >> V_127 ;
unsigned long V_139 = V_128 - V_126 + 1 ;
int V_140 ;
F_94 ( V_25 , V_15 , V_16 , V_122 , 1 , 0 , NULL , V_125 ) ;
if ( V_150 == 0 )
return;
if ( ( V_150 & V_152 ) && V_139 > 0 )
F_121 ( V_26 -> V_130 , - V_153 ) ;
while ( V_139 > 0 ) {
V_37 = F_111 ( V_26 -> V_130 , V_126 ,
F_112 (unsigned long,
nr_pages, ARRAY_SIZE(pages)) , V_138 ) ;
for ( V_140 = 0 ; V_140 < V_37 ; V_140 ++ ) {
if ( V_150 & V_154 )
F_122 ( V_138 [ V_140 ] ) ;
if ( V_138 [ V_140 ] == V_137 ) {
F_101 ( V_138 [ V_140 ] ) ;
continue;
}
if ( V_150 & V_155 )
F_100 ( V_138 [ V_140 ] ) ;
if ( V_150 & V_156 )
F_106 ( V_138 [ V_140 ] ) ;
if ( V_150 & V_152 )
F_123 ( V_138 [ V_140 ] ) ;
if ( V_150 & V_157 )
F_124 ( V_138 [ V_140 ] ) ;
if ( V_150 & V_158 )
F_113 ( V_138 [ V_140 ] ) ;
F_101 ( V_138 [ V_140 ] ) ;
}
V_139 -= V_37 ;
V_126 += V_37 ;
F_79 () ;
}
}
T_1 F_125 ( struct V_24 * V_25 ,
T_1 * V_15 , T_1 V_159 , T_1 V_134 ,
unsigned V_33 , int V_160 )
{
struct V_3 * V_65 ;
struct V_1 * V_2 ;
T_1 V_135 = * V_15 ;
T_1 V_136 = 0 ;
T_1 V_161 = 0 ;
int V_89 = 0 ;
if ( F_45 ( V_159 <= V_135 ) )
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
if ( V_2 -> V_15 > V_159 )
break;
if ( V_160 && V_89 && V_2 -> V_15 > V_161 + 1 )
break;
if ( V_2 -> V_16 >= V_135 && ( V_2 -> V_2 & V_33 ) == V_33 ) {
V_136 += F_126 ( V_159 , V_2 -> V_16 ) + 1 -
F_127 ( V_135 , V_2 -> V_15 ) ;
if ( V_136 >= V_134 )
break;
if ( ! V_89 ) {
* V_15 = F_127 ( V_135 , V_2 -> V_15 ) ;
V_89 = 1 ;
}
V_161 = V_2 -> V_16 ;
} else if ( V_160 && V_89 ) {
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
static T_5 int F_128 ( struct V_24 * V_25 , T_1 V_15 ,
struct V_162 * V_59 )
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
static T_5 int F_129 ( struct V_24 * V_25 , T_1 V_15 ,
struct V_162 * * V_59 )
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
T_1 V_16 = V_15 + V_30 - 1 ;
if ( F_118 ( V_25 , V_15 , V_16 , V_166 , 1 , NULL ) )
F_132 ( V_129 ) ;
}
int F_133 ( struct V_26 * V_26 , struct V_162 * V_167 )
{
int V_37 ;
int V_100 = 0 ;
struct V_24 * V_168 = & F_19 ( V_26 ) -> V_169 ;
F_128 ( V_168 , V_167 -> V_15 , NULL ) ;
V_37 = F_134 ( V_168 , V_167 -> V_15 ,
V_167 -> V_15 + V_167 -> V_21 - 1 ,
V_124 | V_98 , V_125 ) ;
if ( V_37 )
V_100 = V_37 ;
V_37 = F_134 ( & F_19 ( V_26 ) -> V_151 , V_167 -> V_15 ,
V_167 -> V_15 + V_167 -> V_21 - 1 ,
V_170 , V_125 ) ;
if ( V_37 && ! V_100 )
V_100 = V_37 ;
F_135 ( V_167 ) ;
return V_100 ;
}
int F_136 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_171 , T_1 V_172 ,
struct V_129 * V_129 , unsigned int V_173 , int V_174 )
{
struct V_41 * V_32 = F_19 ( V_26 ) -> V_31 -> V_32 ;
struct V_50 * V_50 ;
struct V_175 * V_176 ;
T_1 V_177 = 0 ;
T_1 V_178 ;
struct V_179 * V_180 = NULL ;
struct V_181 * V_182 = & V_32 -> V_183 ;
int V_37 ;
ASSERT ( ! ( V_32 -> V_184 -> V_185 & V_186 ) ) ;
F_23 ( ! V_174 ) ;
if ( F_137 ( V_182 , V_172 , V_171 , V_174 ) )
return 0 ;
V_50 = F_138 ( V_125 , 1 ) ;
if ( ! V_50 )
return - V_153 ;
V_50 -> V_187 . V_188 = 0 ;
V_177 = V_171 ;
V_37 = F_139 ( V_32 , V_189 , V_172 ,
& V_177 , & V_180 , V_174 ) ;
if ( V_37 ) {
F_140 ( V_50 ) ;
return - V_153 ;
}
F_23 ( V_174 != V_180 -> V_174 ) ;
V_178 = V_180 -> V_190 [ V_174 - 1 ] . V_191 >> 9 ;
V_50 -> V_187 . V_192 = V_178 ;
V_176 = V_180 -> V_190 [ V_174 - 1 ] . V_176 ;
F_141 ( V_180 ) ;
if ( ! V_176 || ! V_176 -> V_193 || ! V_176 -> V_194 ) {
F_140 ( V_50 ) ;
return - V_153 ;
}
V_50 -> V_195 = V_176 -> V_193 ;
F_142 ( V_50 , V_129 , V_171 , V_173 ) ;
if ( F_143 ( V_196 , V_50 ) ) {
F_140 ( V_50 ) ;
F_144 ( V_176 , V_197 ) ;
return - V_153 ;
}
F_145 ( V_32 ,
L_13 ,
F_20 ( V_26 ) , V_15 ,
F_146 ( V_176 -> V_198 ) , V_178 ) ;
F_140 ( V_50 ) ;
return 0 ;
}
int F_147 ( struct V_199 * V_31 , struct V_10 * V_11 ,
int V_174 )
{
T_1 V_15 = V_11 -> V_15 ;
unsigned long V_140 , V_200 = F_148 ( V_11 -> V_15 , V_11 -> V_21 ) ;
int V_37 = 0 ;
if ( V_31 -> V_32 -> V_184 -> V_185 & V_186 )
return - V_201 ;
for ( V_140 = 0 ; V_140 < V_200 ; V_140 ++ ) {
struct V_129 * V_68 = V_11 -> V_138 [ V_140 ] ;
V_37 = F_136 ( V_31 -> V_32 -> V_202 , V_15 ,
V_30 , V_15 , V_68 ,
V_15 - F_131 ( V_68 ) , V_174 ) ;
if ( V_37 )
break;
V_15 += V_30 ;
}
return V_37 ;
}
int F_149 ( struct V_26 * V_26 , T_1 V_15 , struct V_129 * V_129 ,
unsigned int V_173 )
{
T_1 V_203 ;
struct V_162 * V_59 ;
struct V_41 * V_32 = F_19 ( V_26 ) -> V_31 -> V_32 ;
struct V_1 * V_2 ;
int V_204 ;
int V_37 ;
V_203 = 0 ;
V_37 = F_125 ( & F_19 ( V_26 ) -> V_169 , & V_203 ,
( T_1 ) - 1 , 1 , V_98 , 0 ) ;
if ( ! V_37 )
return 0 ;
V_37 = F_129 ( & F_19 ( V_26 ) -> V_169 , V_15 ,
& V_59 ) ;
if ( V_37 )
return 0 ;
F_23 ( ! V_59 -> V_205 ) ;
if ( V_59 -> V_206 ) {
F_150 ( L_14 ,
V_59 -> V_15 ) ;
goto V_111;
}
if ( V_32 -> V_184 -> V_185 & V_186 )
goto V_111;
F_75 ( & F_19 ( V_26 ) -> V_151 . V_57 ) ;
V_2 = F_107 ( & F_19 ( V_26 ) -> V_151 ,
V_59 -> V_15 ,
V_124 ) ;
F_78 ( & F_19 ( V_26 ) -> V_151 . V_57 ) ;
if ( V_2 && V_2 -> V_15 <= V_59 -> V_15 &&
V_2 -> V_16 >= V_59 -> V_15 + V_59 -> V_21 - 1 ) {
V_204 = F_151 ( V_32 , V_59 -> V_172 ,
V_59 -> V_21 ) ;
if ( V_204 > 1 ) {
F_136 ( V_26 , V_15 , V_59 -> V_21 ,
V_59 -> V_172 , V_129 ,
V_173 , V_59 -> V_207 ) ;
}
}
V_111:
F_133 ( V_26 , V_59 ) ;
return 0 ;
}
void F_152 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_16 )
{
struct V_24 * V_168 = & F_19 ( V_26 ) -> V_169 ;
struct V_162 * V_59 ;
struct V_1 * V_2 , * V_13 ;
if ( F_153 ( & V_168 -> V_2 ) )
return;
F_75 ( & V_168 -> V_57 ) ;
V_2 = F_107 ( V_168 , V_15 , V_98 ) ;
while ( V_2 ) {
if ( V_2 -> V_15 > V_16 )
break;
ASSERT ( V_2 -> V_16 <= V_16 ) ;
V_13 = F_66 ( V_2 ) ;
V_59 = V_2 -> V_59 ;
F_43 ( V_2 ) ;
F_135 ( V_59 ) ;
V_2 = V_13 ;
}
F_78 ( & V_168 -> V_57 ) ;
}
int F_154 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_16 ,
struct V_162 * * V_208 )
{
struct V_162 * V_59 ;
struct V_209 * V_210 ;
struct V_24 * V_168 = & F_19 ( V_26 ) -> V_169 ;
struct V_24 * V_25 = & F_19 ( V_26 ) -> V_151 ;
struct V_211 * V_212 = & F_19 ( V_26 ) -> V_213 ;
int V_37 ;
T_1 V_172 ;
V_37 = F_129 ( V_168 , V_15 , & V_59 ) ;
if ( V_37 ) {
V_59 = F_155 ( sizeof( * V_59 ) , V_125 ) ;
if ( ! V_59 )
return - V_45 ;
V_59 -> V_15 = V_15 ;
V_59 -> V_21 = V_16 - V_15 + 1 ;
V_59 -> V_205 = 0 ;
V_59 -> V_214 = 0 ;
V_59 -> V_206 = 0 ;
F_156 ( & V_212 -> V_57 ) ;
V_210 = F_157 ( V_212 , V_15 , V_59 -> V_21 ) ;
if ( ! V_210 ) {
F_158 ( & V_212 -> V_57 ) ;
F_135 ( V_59 ) ;
return - V_153 ;
}
if ( V_210 -> V_15 > V_15 || V_210 -> V_15 + V_210 -> V_21 <= V_15 ) {
F_159 ( V_210 ) ;
V_210 = NULL ;
}
F_158 ( & V_212 -> V_57 ) ;
if ( ! V_210 ) {
F_135 ( V_59 ) ;
return - V_153 ;
}
V_172 = V_15 - V_210 -> V_15 ;
V_172 = V_210 -> V_215 + V_172 ;
if ( F_160 ( V_216 , & V_210 -> V_7 ) ) {
V_172 = V_210 -> V_215 ;
V_59 -> V_214 = V_217 ;
F_161 ( & V_59 -> V_214 ,
V_210 -> V_218 ) ;
}
F_150 ( L_15 ,
V_172 , V_15 , V_59 -> V_21 ) ;
V_59 -> V_172 = V_172 ;
F_159 ( V_210 ) ;
V_37 = F_162 ( V_168 , V_15 , V_16 ,
V_124 | V_98 , V_125 ) ;
if ( V_37 >= 0 )
V_37 = F_128 ( V_168 , V_15 , V_59 ) ;
if ( V_37 >= 0 )
V_37 = F_162 ( V_25 , V_15 , V_16 , V_170 ,
V_125 ) ;
if ( V_37 < 0 ) {
F_135 ( V_59 ) ;
return V_37 ;
}
} else {
F_150 ( L_16 ,
V_59 -> V_172 , V_59 -> V_15 , V_59 -> V_21 ,
V_59 -> V_206 ) ;
}
* V_208 = V_59 ;
return 0 ;
}
int F_163 ( struct V_26 * V_26 , struct V_50 * V_219 ,
struct V_162 * V_59 , int V_207 )
{
int V_204 ;
V_204 = F_151 ( F_19 ( V_26 ) -> V_31 -> V_32 ,
V_59 -> V_172 , V_59 -> V_21 ) ;
if ( V_204 == 1 ) {
F_150 ( L_17 ,
V_204 , V_59 -> V_205 , V_207 ) ;
return 0 ;
}
if ( V_219 -> V_220 > 1 ) {
F_23 ( V_59 -> V_206 ) ;
V_59 -> V_206 = 1 ;
V_59 -> V_205 = V_207 ;
} else {
if ( V_59 -> V_206 ) {
F_23 ( V_59 -> V_205 != V_207 ) ;
V_59 -> V_206 = 0 ;
V_59 -> V_205 = 0 ;
}
V_59 -> V_207 = V_207 ;
V_59 -> V_205 ++ ;
if ( V_59 -> V_205 == V_207 )
V_59 -> V_205 ++ ;
}
if ( V_59 -> V_205 > V_204 ) {
F_150 ( L_18 ,
V_204 , V_59 -> V_205 , V_207 ) ;
return 0 ;
}
return 1 ;
}
struct V_50 * F_164 ( struct V_26 * V_26 , struct V_50 * V_219 ,
struct V_162 * V_59 ,
struct V_129 * V_129 , int V_173 , int V_221 ,
T_6 * V_222 , void * V_223 )
{
struct V_50 * V_50 ;
struct V_49 * V_224 ;
struct V_49 * V_179 ;
V_50 = F_138 ( V_125 , 1 ) ;
if ( ! V_50 )
return NULL ;
V_50 -> V_225 = V_222 ;
V_50 -> V_187 . V_192 = V_59 -> V_172 >> 9 ;
V_50 -> V_195 = F_19 ( V_26 ) -> V_31 -> V_32 -> V_226 -> V_227 ;
V_50 -> V_187 . V_188 = 0 ;
V_50 -> V_228 = V_223 ;
V_224 = V_49 ( V_219 ) ;
if ( V_224 -> V_229 ) {
struct V_41 * V_32 = F_19 ( V_26 ) -> V_31 -> V_32 ;
T_7 V_230 = F_165 ( V_32 -> V_231 ) ;
V_179 = V_49 ( V_50 ) ;
V_179 -> V_229 = V_179 -> V_232 ;
V_221 *= V_230 ;
memcpy ( V_179 -> V_229 , V_224 -> V_229 + V_221 ,
V_230 ) ;
}
F_142 ( V_50 , V_129 , V_59 -> V_21 , V_173 ) ;
return V_50 ;
}
static int F_166 ( struct V_50 * V_219 , T_1 V_233 ,
struct V_129 * V_129 , T_1 V_15 , T_1 V_16 ,
int V_207 )
{
struct V_162 * V_59 ;
struct V_26 * V_26 = V_129 -> V_28 -> V_29 ;
struct V_24 * V_25 = & F_19 ( V_26 ) -> V_151 ;
struct V_50 * V_50 ;
int V_234 ;
int V_37 ;
F_23 ( V_219 -> V_235 & V_236 ) ;
V_37 = F_154 ( V_26 , V_15 , V_16 , & V_59 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_163 ( V_26 , V_219 , V_59 , V_207 ) ;
if ( ! V_37 ) {
F_133 ( V_26 , V_59 ) ;
return - V_153 ;
}
if ( V_219 -> V_220 > 1 )
V_234 = V_237 | V_238 ;
else
V_234 = V_237 ;
V_233 >>= V_26 -> V_42 -> V_239 ;
V_50 = F_164 ( V_26 , V_219 , V_59 , V_129 ,
V_15 - F_131 ( V_129 ) ,
( int ) V_233 , V_219 -> V_225 ,
NULL ) ;
if ( ! V_50 ) {
F_133 ( V_26 , V_59 ) ;
return - V_153 ;
}
F_150 ( L_19 ,
V_234 , V_59 -> V_205 , V_59 -> V_206 ) ;
V_37 = V_25 -> V_55 -> V_240 ( V_26 , V_234 , V_50 ,
V_59 -> V_205 ,
V_59 -> V_214 , 0 ) ;
if ( V_37 ) {
F_133 ( V_26 , V_59 ) ;
F_140 ( V_50 ) ;
}
return V_37 ;
}
void F_167 ( struct V_129 * V_129 , int V_100 , T_1 V_15 , T_1 V_16 )
{
int V_241 = ( V_100 == 0 ) ;
struct V_24 * V_25 ;
int V_37 = 0 ;
V_25 = & F_19 ( V_129 -> V_28 -> V_29 ) -> V_151 ;
if ( V_25 -> V_55 && V_25 -> V_55 -> V_242 ) {
V_37 = V_25 -> V_55 -> V_242 ( V_129 , V_15 ,
V_16 , NULL , V_241 ) ;
if ( V_37 )
V_241 = 0 ;
}
if ( ! V_241 ) {
F_168 ( V_129 ) ;
F_123 ( V_129 ) ;
V_37 = V_37 < 0 ? V_37 : - V_153 ;
F_121 ( V_129 -> V_28 , V_37 ) ;
}
}
static void F_169 ( struct V_50 * V_50 )
{
struct V_243 * V_244 ;
T_1 V_15 ;
T_1 V_16 ;
int V_140 ;
F_170 (bvec, bio, i) {
struct V_129 * V_129 = V_244 -> V_245 ;
if ( V_244 -> V_246 || V_244 -> V_247 != V_30 ) {
if ( V_244 -> V_246 + V_244 -> V_247 != V_30 )
F_171 ( F_19 ( V_129 -> V_28 -> V_29 ) -> V_31 -> V_32 ,
L_20 ,
V_244 -> V_246 , V_244 -> V_247 ) ;
else
F_172 ( F_19 ( V_129 -> V_28 -> V_29 ) -> V_31 -> V_32 ,
L_21
L_22 ,
V_244 -> V_246 , V_244 -> V_247 ) ;
}
V_15 = F_131 ( V_129 ) ;
V_16 = V_15 + V_244 -> V_246 + V_244 -> V_247 - 1 ;
F_167 ( V_129 , V_50 -> V_248 , V_15 , V_16 ) ;
F_124 ( V_129 ) ;
}
F_140 ( V_50 ) ;
}
static void
F_173 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_21 ,
int V_241 )
{
struct V_1 * V_103 = NULL ;
T_1 V_16 = V_15 + V_21 - 1 ;
if ( V_241 && V_25 -> V_249 )
F_174 ( V_25 , V_15 , V_16 , & V_103 , V_40 ) ;
F_119 ( V_25 , V_15 , V_16 , & V_103 , V_40 ) ;
}
static void F_175 ( struct V_50 * V_50 )
{
struct V_243 * V_244 ;
int V_241 = ! V_50 -> V_248 ;
struct V_49 * V_250 = V_49 ( V_50 ) ;
struct V_24 * V_25 ;
T_1 V_64 = 0 ;
T_1 V_15 ;
T_1 V_16 ;
T_1 V_21 ;
T_1 V_251 = 0 ;
T_1 V_252 = 0 ;
int V_253 ;
int V_37 ;
int V_140 ;
F_170 (bvec, bio, i) {
struct V_129 * V_129 = V_244 -> V_245 ;
struct V_26 * V_26 = V_129 -> V_28 -> V_29 ;
F_150 ( L_23
L_24 , ( T_1 ) V_50 -> V_187 . V_192 ,
V_50 -> V_248 , V_250 -> V_174 ) ;
V_25 = & F_19 ( V_26 ) -> V_151 ;
if ( V_244 -> V_246 || V_244 -> V_247 != V_30 ) {
if ( V_244 -> V_246 + V_244 -> V_247 != V_30 )
F_171 ( F_19 ( V_129 -> V_28 -> V_29 ) -> V_31 -> V_32 ,
L_25 ,
V_244 -> V_246 , V_244 -> V_247 ) ;
else
F_172 ( F_19 ( V_129 -> V_28 -> V_29 ) -> V_31 -> V_32 ,
L_26
L_22 ,
V_244 -> V_246 , V_244 -> V_247 ) ;
}
V_15 = F_131 ( V_129 ) ;
V_16 = V_15 + V_244 -> V_246 + V_244 -> V_247 - 1 ;
V_21 = V_244 -> V_247 ;
V_253 = V_250 -> V_174 ;
if ( F_176 ( V_241 && V_25 -> V_55 &&
V_25 -> V_55 -> V_254 ) ) {
V_37 = V_25 -> V_55 -> V_254 ( V_250 , V_64 ,
V_129 , V_15 , V_16 ,
V_253 ) ;
if ( V_37 )
V_241 = 0 ;
else
F_149 ( V_26 , V_15 , V_129 , 0 ) ;
}
if ( F_176 ( V_241 ) )
goto V_255;
if ( V_25 -> V_55 && V_25 -> V_55 -> V_256 ) {
V_37 = V_25 -> V_55 -> V_256 ( V_129 , V_253 ) ;
if ( ! V_37 && ! V_50 -> V_248 )
V_241 = 1 ;
} else {
V_37 = F_166 ( V_50 , V_64 , V_129 , V_15 , V_16 ,
V_253 ) ;
if ( V_37 == 0 ) {
V_241 = ! V_50 -> V_248 ;
V_64 += V_21 ;
continue;
}
}
V_255:
if ( F_176 ( V_241 ) ) {
T_8 V_257 = F_17 ( V_26 ) ;
T_9 V_128 = V_257 >> V_127 ;
unsigned V_258 ;
V_258 = V_257 & ( V_30 - 1 ) ;
if ( V_129 -> V_126 == V_128 && V_258 )
F_177 ( V_129 , V_258 , V_30 ) ;
F_132 ( V_129 ) ;
} else {
F_168 ( V_129 ) ;
F_123 ( V_129 ) ;
}
F_113 ( V_129 ) ;
V_64 += V_21 ;
if ( F_178 ( ! V_241 ) ) {
if ( V_252 ) {
F_173 ( V_25 ,
V_251 ,
V_252 , 1 ) ;
V_251 = 0 ;
V_252 = 0 ;
}
F_173 ( V_25 , V_15 ,
V_16 - V_15 + 1 , 0 ) ;
} else if ( ! V_252 ) {
V_251 = V_15 ;
V_252 = V_16 + 1 - V_15 ;
} else if ( V_251 + V_252 == V_15 ) {
V_252 += V_16 + 1 - V_15 ;
} else {
F_173 ( V_25 , V_251 ,
V_252 , V_241 ) ;
V_251 = V_15 ;
V_252 = V_16 + 1 - V_15 ;
}
}
if ( V_252 )
F_173 ( V_25 , V_251 , V_252 ,
V_241 ) ;
if ( V_250 -> V_259 )
V_250 -> V_259 ( V_250 , V_50 -> V_248 ) ;
F_140 ( V_50 ) ;
}
struct V_50 *
F_179 ( struct V_260 * V_193 , T_1 V_261 , int V_262 ,
T_3 V_263 )
{
struct V_49 * V_179 ;
struct V_50 * V_50 ;
V_50 = F_180 ( V_263 , V_262 , V_47 ) ;
if ( V_50 == NULL && ( V_264 -> V_7 & V_265 ) ) {
while ( ! V_50 && ( V_262 /= 2 ) ) {
V_50 = F_180 ( V_263 ,
V_262 , V_47 ) ;
}
}
if ( V_50 ) {
V_50 -> V_195 = V_193 ;
V_50 -> V_187 . V_192 = V_261 ;
V_179 = V_49 ( V_50 ) ;
V_179 -> V_229 = NULL ;
V_179 -> V_266 = NULL ;
V_179 -> V_259 = NULL ;
}
return V_50 ;
}
struct V_50 * F_181 ( struct V_50 * V_50 , T_3 V_267 )
{
struct V_49 * V_179 ;
struct V_50 * V_5 ;
V_5 = F_182 ( V_50 , V_267 , V_47 ) ;
if ( V_5 ) {
V_179 = V_49 ( V_5 ) ;
V_179 -> V_229 = NULL ;
V_179 -> V_266 = NULL ;
V_179 -> V_259 = NULL ;
#ifdef F_183
if ( V_50 -> V_268 )
F_184 ( V_5 , V_50 -> V_268 ) ;
#endif
}
return V_5 ;
}
struct V_50 * F_138 ( T_3 V_267 , unsigned int V_269 )
{
struct V_49 * V_179 ;
struct V_50 * V_50 ;
V_50 = F_180 ( V_267 , V_269 , V_47 ) ;
if ( V_50 ) {
V_179 = V_49 ( V_50 ) ;
V_179 -> V_229 = NULL ;
V_179 -> V_266 = NULL ;
V_179 -> V_259 = NULL ;
}
return V_50 ;
}
static int T_4 F_185 ( int V_270 , struct V_50 * V_50 ,
int V_174 , unsigned long V_214 )
{
int V_37 = 0 ;
struct V_243 * V_244 = V_50 -> V_271 + V_50 -> V_220 - 1 ;
struct V_129 * V_129 = V_244 -> V_245 ;
struct V_24 * V_25 = V_50 -> V_228 ;
T_1 V_15 ;
V_15 = F_131 ( V_129 ) + V_244 -> V_246 ;
V_50 -> V_228 = NULL ;
F_186 ( V_50 ) ;
if ( V_25 -> V_55 && V_25 -> V_55 -> V_240 )
V_37 = V_25 -> V_55 -> V_240 ( V_129 -> V_28 -> V_29 , V_270 , V_50 ,
V_174 , V_214 , V_15 ) ;
else
F_187 ( V_270 , V_50 ) ;
F_140 ( V_50 ) ;
return V_37 ;
}
static int F_188 ( int V_270 , struct V_24 * V_25 , struct V_129 * V_129 ,
unsigned long V_64 , T_10 V_272 , struct V_50 * V_50 ,
unsigned long V_214 )
{
int V_37 = 0 ;
if ( V_25 -> V_55 && V_25 -> V_55 -> V_273 )
V_37 = V_25 -> V_55 -> V_273 ( V_270 , V_129 , V_64 , V_272 , V_50 ,
V_214 ) ;
F_23 ( V_37 < 0 ) ;
return V_37 ;
}
static int F_189 ( int V_270 , struct V_24 * V_25 ,
struct V_274 * V_275 ,
struct V_129 * V_129 , T_11 V_178 ,
T_10 V_272 , unsigned long V_64 ,
struct V_260 * V_193 ,
struct V_50 * * V_276 ,
unsigned long V_277 ,
T_6 V_278 ,
int V_174 ,
unsigned long V_279 ,
unsigned long V_214 ,
bool V_280 )
{
int V_37 = 0 ;
struct V_50 * V_50 ;
int V_160 = 0 ;
int V_281 = V_279 & V_217 ;
T_10 V_282 = F_112 ( T_10 , V_272 , V_30 ) ;
if ( V_276 && * V_276 ) {
V_50 = * V_276 ;
if ( V_281 )
V_160 = V_50 -> V_187 . V_192 == V_178 ;
else
V_160 = F_190 ( V_50 ) == V_178 ;
if ( V_279 != V_214 || ! V_160 ||
V_280 ||
F_188 ( V_270 , V_25 , V_129 , V_64 , V_282 , V_50 , V_214 ) ||
F_142 ( V_50 , V_129 , V_282 , V_64 ) < V_282 ) {
V_37 = F_185 ( V_270 , V_50 , V_174 ,
V_279 ) ;
if ( V_37 < 0 ) {
* V_276 = NULL ;
return V_37 ;
}
V_50 = NULL ;
} else {
if ( V_275 )
F_191 ( V_275 , V_129 , V_282 ) ;
return 0 ;
}
}
V_50 = F_179 ( V_193 , V_178 , V_283 ,
V_125 | V_284 ) ;
if ( ! V_50 )
return - V_45 ;
F_142 ( V_50 , V_129 , V_282 , V_64 ) ;
V_50 -> V_225 = V_278 ;
V_50 -> V_228 = V_25 ;
if ( V_275 ) {
F_192 ( V_275 , V_50 ) ;
F_191 ( V_275 , V_129 , V_282 ) ;
}
if ( V_276 )
* V_276 = V_50 ;
else
V_37 = F_185 ( V_270 , V_50 , V_174 , V_214 ) ;
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
F_45 ( V_129 -> V_203 != ( unsigned long ) V_11 ) ;
}
}
void F_198 ( struct V_129 * V_129 )
{
if ( ! F_194 ( V_129 ) ) {
F_195 ( V_129 ) ;
F_196 ( V_129 ) ;
F_197 ( V_129 , V_285 ) ;
}
}
static struct V_209 *
F_199 ( struct V_26 * V_26 , struct V_129 * V_129 , T_10 V_173 ,
T_1 V_15 , T_1 V_21 , T_12 * V_286 ,
struct V_209 * * V_287 )
{
struct V_209 * V_210 ;
if ( V_287 && * V_287 ) {
V_210 = * V_287 ;
if ( F_200 ( V_210 ) && V_15 >= V_210 -> V_15 &&
V_15 < F_201 ( V_210 ) ) {
F_86 ( & V_210 -> V_17 ) ;
return V_210 ;
}
F_159 ( V_210 ) ;
* V_287 = NULL ;
}
V_210 = V_286 ( V_26 , V_129 , V_173 , V_15 , V_21 , 0 ) ;
if ( V_287 && ! F_202 ( V_210 ) ) {
F_23 ( * V_287 ) ;
F_86 ( & V_210 -> V_17 ) ;
* V_287 = V_210 ;
}
return V_210 ;
}
static int F_203 ( struct V_24 * V_25 ,
struct V_129 * V_129 ,
T_12 * V_286 ,
struct V_209 * * V_287 ,
struct V_50 * * V_50 , int V_174 ,
unsigned long * V_214 , int V_270 ,
T_1 * V_288 )
{
struct V_26 * V_26 = V_129 -> V_28 -> V_29 ;
T_1 V_15 = F_131 ( V_129 ) ;
T_1 V_289 = V_15 + V_30 - 1 ;
T_1 V_16 ;
T_1 V_290 = V_15 ;
T_1 V_291 ;
T_1 V_292 = F_17 ( V_26 ) ;
T_1 V_215 ;
T_1 V_293 ;
T_11 V_178 ;
struct V_209 * V_210 ;
struct V_260 * V_193 ;
int V_37 ;
int V_294 = 0 ;
T_10 V_173 = 0 ;
T_10 V_295 ;
T_10 V_296 ;
T_10 V_297 = V_26 -> V_42 -> V_298 ;
unsigned long V_299 = 0 ;
F_198 ( V_129 ) ;
V_16 = V_289 ;
if ( ! F_204 ( V_129 ) ) {
if ( F_205 ( V_129 ) == 0 ) {
F_23 ( V_297 != V_30 ) ;
F_206 ( V_25 , V_15 , V_16 ) ;
goto V_111;
}
}
if ( V_129 -> V_126 == V_292 >> V_127 ) {
char * V_300 ;
T_10 V_301 = V_292 & ( V_30 - 1 ) ;
if ( V_301 ) {
V_295 = V_30 - V_301 ;
V_300 = F_207 ( V_129 ) ;
memset ( V_300 + V_301 , 0 , V_295 ) ;
F_208 ( V_129 ) ;
F_209 ( V_300 ) ;
}
}
while ( V_290 <= V_16 ) {
unsigned long V_302 = ( V_292 >> V_127 ) + 1 ;
bool V_280 = false ;
if ( V_290 >= V_292 ) {
char * V_300 ;
struct V_1 * V_103 = NULL ;
V_295 = V_30 - V_173 ;
V_300 = F_207 ( V_129 ) ;
memset ( V_300 + V_173 , 0 , V_295 ) ;
F_208 ( V_129 ) ;
F_209 ( V_300 ) ;
F_174 ( V_25 , V_290 , V_290 + V_295 - 1 ,
& V_103 , V_125 ) ;
F_119 ( V_25 , V_290 ,
V_290 + V_295 - 1 ,
& V_103 , V_125 ) ;
break;
}
V_210 = F_199 ( V_26 , V_129 , V_173 , V_290 ,
V_16 - V_290 + 1 , V_286 , V_287 ) ;
if ( F_202 ( V_210 ) ) {
F_123 ( V_129 ) ;
F_206 ( V_25 , V_290 , V_16 ) ;
break;
}
V_291 = V_290 - V_210 -> V_15 ;
F_23 ( F_201 ( V_210 ) <= V_290 ) ;
F_23 ( V_16 < V_290 ) ;
if ( F_160 ( V_216 , & V_210 -> V_7 ) ) {
V_299 |= V_217 ;
F_161 ( & V_299 ,
V_210 -> V_218 ) ;
}
V_295 = F_126 ( F_201 ( V_210 ) - V_290 , V_16 - V_290 + 1 ) ;
V_293 = F_126 ( F_201 ( V_210 ) - 1 , V_16 ) ;
V_295 = F_210 ( V_295 , V_297 ) ;
if ( V_299 & V_217 ) {
V_296 = V_210 -> V_303 ;
V_178 = V_210 -> V_215 >> 9 ;
} else {
V_178 = ( V_210 -> V_215 + V_291 ) >> 9 ;
V_296 = V_295 ;
}
V_193 = V_210 -> V_193 ;
V_215 = V_210 -> V_215 ;
if ( F_160 ( V_304 , & V_210 -> V_7 ) )
V_215 = V_305 ;
if ( F_160 ( V_216 , & V_210 -> V_7 ) &&
V_288 && * V_288 != ( T_1 ) - 1 &&
* V_288 != V_210 -> V_306 )
V_280 = true ;
if ( V_288 )
* V_288 = V_210 -> V_306 ;
F_159 ( V_210 ) ;
V_210 = NULL ;
if ( V_215 == V_305 ) {
char * V_300 ;
struct V_1 * V_103 = NULL ;
V_300 = F_207 ( V_129 ) ;
memset ( V_300 + V_173 , 0 , V_295 ) ;
F_208 ( V_129 ) ;
F_209 ( V_300 ) ;
F_174 ( V_25 , V_290 , V_290 + V_295 - 1 ,
& V_103 , V_125 ) ;
F_119 ( V_25 , V_290 ,
V_290 + V_295 - 1 ,
& V_103 , V_125 ) ;
V_290 = V_290 + V_295 ;
V_173 += V_295 ;
continue;
}
if ( F_118 ( V_25 , V_290 , V_293 ,
V_166 , 1 , NULL ) ) {
F_130 ( V_25 , V_129 ) ;
F_206 ( V_25 , V_290 , V_290 + V_295 - 1 ) ;
V_290 = V_290 + V_295 ;
V_173 += V_295 ;
continue;
}
if ( V_215 == V_307 ) {
F_123 ( V_129 ) ;
F_206 ( V_25 , V_290 , V_290 + V_295 - 1 ) ;
V_290 = V_290 + V_295 ;
V_173 += V_295 ;
continue;
}
V_302 -= V_129 -> V_126 ;
V_37 = F_189 ( V_270 , V_25 , NULL , V_129 ,
V_178 , V_296 , V_173 ,
V_193 , V_50 , V_302 ,
F_175 , V_174 ,
* V_214 ,
V_299 ,
V_280 ) ;
if ( ! V_37 ) {
V_294 ++ ;
* V_214 = V_299 ;
} else {
F_123 ( V_129 ) ;
F_206 ( V_25 , V_290 , V_290 + V_295 - 1 ) ;
}
V_290 = V_290 + V_295 ;
V_173 += V_295 ;
}
V_111:
if ( ! V_294 ) {
if ( ! F_211 ( V_129 ) )
F_132 ( V_129 ) ;
F_113 ( V_129 ) ;
}
return 0 ;
}
static inline void F_212 ( struct V_24 * V_25 ,
struct V_129 * V_138 [] , int V_139 ,
T_1 V_15 , T_1 V_16 ,
T_12 * V_286 ,
struct V_209 * * V_287 ,
struct V_50 * * V_50 , int V_174 ,
unsigned long * V_214 , int V_270 ,
T_1 * V_288 )
{
struct V_26 * V_26 ;
struct V_308 * V_309 ;
int V_126 ;
V_26 = V_138 [ 0 ] -> V_28 -> V_29 ;
while ( 1 ) {
F_213 ( V_25 , V_15 , V_16 ) ;
V_309 = F_214 ( V_26 , V_15 ,
V_16 - V_15 + 1 ) ;
if ( ! V_309 )
break;
F_206 ( V_25 , V_15 , V_16 ) ;
F_215 ( V_26 , V_309 , 1 ) ;
F_216 ( V_309 ) ;
}
for ( V_126 = 0 ; V_126 < V_139 ; V_126 ++ ) {
F_203 ( V_25 , V_138 [ V_126 ] , V_286 , V_287 , V_50 ,
V_174 , V_214 , V_270 , V_288 ) ;
F_101 ( V_138 [ V_126 ] ) ;
}
}
static void F_217 ( struct V_24 * V_25 ,
struct V_129 * V_138 [] ,
int V_139 , T_12 * V_286 ,
struct V_209 * * V_287 ,
struct V_50 * * V_50 , int V_174 ,
unsigned long * V_214 , int V_270 ,
T_1 * V_288 )
{
T_1 V_15 = 0 ;
T_1 V_16 = 0 ;
T_1 V_310 ;
int V_126 ;
int V_311 = 0 ;
for ( V_126 = 0 ; V_126 < V_139 ; V_126 ++ ) {
V_310 = F_131 ( V_138 [ V_126 ] ) ;
if ( ! V_16 ) {
V_15 = V_310 ;
V_16 = V_15 + V_30 - 1 ;
V_311 = V_126 ;
} else if ( V_16 + 1 == V_310 ) {
V_16 += V_30 ;
} else {
F_212 ( V_25 , & V_138 [ V_311 ] ,
V_126 - V_311 , V_15 ,
V_16 , V_286 , V_287 ,
V_50 , V_174 , V_214 ,
V_270 , V_288 ) ;
V_15 = V_310 ;
V_16 = V_15 + V_30 - 1 ;
V_311 = V_126 ;
}
}
if ( V_16 )
F_212 ( V_25 , & V_138 [ V_311 ] ,
V_126 - V_311 , V_15 ,
V_16 , V_286 , V_287 , V_50 ,
V_174 , V_214 , V_270 ,
V_288 ) ;
}
static int F_218 ( struct V_24 * V_25 ,
struct V_129 * V_129 ,
T_12 * V_286 ,
struct V_50 * * V_50 , int V_174 ,
unsigned long * V_214 , int V_270 )
{
struct V_26 * V_26 = V_129 -> V_28 -> V_29 ;
struct V_308 * V_309 ;
T_1 V_15 = F_131 ( V_129 ) ;
T_1 V_16 = V_15 + V_30 - 1 ;
int V_37 ;
while ( 1 ) {
F_213 ( V_25 , V_15 , V_16 ) ;
V_309 = F_214 ( V_26 , V_15 ,
V_30 ) ;
if ( ! V_309 )
break;
F_206 ( V_25 , V_15 , V_16 ) ;
F_215 ( V_26 , V_309 , 1 ) ;
F_216 ( V_309 ) ;
}
V_37 = F_203 ( V_25 , V_129 , V_286 , NULL , V_50 , V_174 ,
V_214 , V_270 , NULL ) ;
return V_37 ;
}
int F_219 ( struct V_24 * V_25 , struct V_129 * V_129 ,
T_12 * V_286 , int V_174 )
{
struct V_50 * V_50 = NULL ;
unsigned long V_214 = 0 ;
int V_37 ;
V_37 = F_218 ( V_25 , V_129 , V_286 , & V_50 , V_174 ,
& V_214 , V_312 ) ;
if ( V_50 )
V_37 = F_185 ( V_312 , V_50 , V_174 , V_214 ) ;
return V_37 ;
}
static T_5 void F_220 ( struct V_129 * V_129 ,
struct V_274 * V_275 ,
unsigned long V_313 )
{
V_275 -> V_314 -= V_313 ;
if ( V_275 -> V_315 || ( V_275 -> V_314 > 0 &&
V_275 -> V_316 == 0 && V_275 -> V_317 == V_318 ) )
V_129 -> V_28 -> V_319 = V_129 -> V_126 + V_313 ;
}
static T_13 int F_221 ( struct V_26 * V_26 ,
struct V_129 * V_129 , struct V_274 * V_275 ,
struct V_320 * V_321 ,
T_1 V_141 ,
unsigned long * V_313 )
{
struct V_24 * V_25 = V_321 -> V_25 ;
T_1 V_289 = V_141 + V_30 - 1 ;
T_1 V_322 ;
T_1 V_323 = 0 ;
T_1 V_142 = 0 ;
int V_37 ;
int V_324 = 0 ;
if ( V_321 -> V_325 || ! V_25 -> V_55 || ! V_25 -> V_55 -> V_326 )
return 0 ;
while ( V_142 < V_289 ) {
V_322 = F_117 ( V_26 , V_25 ,
V_129 ,
& V_141 ,
& V_142 ,
V_327 ) ;
if ( V_322 == 0 ) {
V_141 = V_142 + 1 ;
continue;
}
V_37 = V_25 -> V_55 -> V_326 ( V_26 , V_129 ,
V_141 ,
V_142 ,
& V_324 ,
V_313 ) ;
if ( V_37 ) {
F_123 ( V_129 ) ;
V_37 = V_37 < 0 ? V_37 : - V_153 ;
goto V_147;
}
V_323 += ( V_142 - V_141 +
V_30 ) >> V_127 ;
V_141 = V_142 + 1 ;
}
if ( V_275 -> V_314 < V_323 ) {
int V_328 = 8192 ;
if ( V_323 < V_328 * 2 )
V_328 = V_323 ;
V_275 -> V_314 = F_112 ( T_1 , V_323 ,
V_328 ) ;
}
if ( V_324 ) {
V_275 -> V_314 -= * V_313 ;
return 1 ;
}
V_37 = 0 ;
V_147:
return V_37 ;
}
static T_13 int F_222 ( struct V_26 * V_26 ,
struct V_129 * V_129 ,
struct V_274 * V_275 ,
struct V_320 * V_321 ,
T_8 V_257 ,
unsigned long V_313 ,
int V_329 , int * V_330 )
{
struct V_24 * V_25 = V_321 -> V_25 ;
T_1 V_15 = F_131 ( V_129 ) ;
T_1 V_289 = V_15 + V_30 - 1 ;
T_1 V_16 ;
T_1 V_290 = V_15 ;
T_1 V_291 ;
T_1 V_215 ;
T_1 V_295 ;
T_11 V_178 ;
struct V_1 * V_102 = NULL ;
struct V_209 * V_210 ;
struct V_260 * V_193 ;
T_10 V_173 = 0 ;
T_10 V_297 ;
int V_37 = 0 ;
int V_294 = 0 ;
bool V_331 ;
if ( V_25 -> V_55 && V_25 -> V_55 -> V_332 ) {
V_37 = V_25 -> V_55 -> V_332 ( V_129 , V_15 ,
V_289 ) ;
if ( V_37 ) {
if ( V_37 == - V_333 )
V_275 -> V_334 ++ ;
else
F_223 ( V_275 , V_129 ) ;
F_220 ( V_129 , V_275 , V_313 ) ;
F_113 ( V_129 ) ;
V_37 = 1 ;
goto V_335;
}
}
F_220 ( V_129 , V_275 , V_313 + 1 ) ;
V_16 = V_289 ;
if ( V_257 <= V_15 ) {
if ( V_25 -> V_55 && V_25 -> V_55 -> V_242 )
V_25 -> V_55 -> V_242 ( V_129 , V_15 ,
V_289 , NULL , 1 ) ;
goto V_147;
}
V_297 = V_26 -> V_42 -> V_298 ;
while ( V_290 <= V_16 ) {
T_1 V_336 ;
if ( V_290 >= V_257 ) {
if ( V_25 -> V_55 && V_25 -> V_55 -> V_242 )
V_25 -> V_55 -> V_242 ( V_129 , V_290 ,
V_289 , NULL , 1 ) ;
break;
}
V_210 = V_321 -> V_286 ( V_26 , V_129 , V_173 , V_290 ,
V_16 - V_290 + 1 , 1 ) ;
if ( F_202 ( V_210 ) ) {
F_123 ( V_129 ) ;
V_37 = F_224 ( V_210 ) ;
break;
}
V_291 = V_290 - V_210 -> V_15 ;
V_336 = F_201 ( V_210 ) ;
F_23 ( V_336 <= V_290 ) ;
F_23 ( V_16 < V_290 ) ;
V_295 = F_126 ( V_336 - V_290 , V_16 - V_290 + 1 ) ;
V_295 = F_210 ( V_295 , V_297 ) ;
V_178 = ( V_210 -> V_215 + V_291 ) >> 9 ;
V_193 = V_210 -> V_193 ;
V_215 = V_210 -> V_215 ;
V_331 = F_160 ( V_216 , & V_210 -> V_7 ) ;
F_159 ( V_210 ) ;
V_210 = NULL ;
if ( V_331 || V_215 == V_305 ||
V_215 == V_307 ) {
if ( ! V_331 && V_25 -> V_55 &&
V_25 -> V_55 -> V_242 )
V_25 -> V_55 -> V_242 ( V_129 , V_290 ,
V_290 + V_295 - 1 ,
NULL , 1 ) ;
else if ( V_331 ) {
V_294 ++ ;
}
V_290 += V_295 ;
V_173 += V_295 ;
continue;
}
if ( V_25 -> V_55 && V_25 -> V_55 -> V_337 ) {
V_37 = V_25 -> V_55 -> V_337 ( V_129 , V_290 ,
V_290 + V_295 - 1 ) ;
} else {
V_37 = 0 ;
}
if ( V_37 ) {
F_123 ( V_129 ) ;
} else {
unsigned long V_338 = ( V_257 >> V_127 ) + 1 ;
F_105 ( V_25 , V_290 , V_290 + V_295 - 1 ) ;
if ( ! F_225 ( V_129 ) ) {
F_171 ( F_19 ( V_26 ) -> V_31 -> V_32 ,
L_27 ,
V_129 -> V_126 , V_290 , V_16 ) ;
}
V_37 = F_189 ( V_329 , V_25 , V_275 , V_129 ,
V_178 , V_295 , V_173 ,
V_193 , & V_321 -> V_50 , V_338 ,
F_169 ,
0 , 0 , 0 , false ) ;
if ( V_37 )
F_123 ( V_129 ) ;
}
V_290 = V_290 + V_295 ;
V_173 += V_295 ;
V_294 ++ ;
}
V_147:
* V_330 = V_294 ;
V_335:
F_43 ( V_102 ) ;
return V_37 ;
}
static int F_226 ( struct V_129 * V_129 , struct V_274 * V_275 ,
void * V_223 )
{
struct V_26 * V_26 = V_129 -> V_28 -> V_29 ;
struct V_320 * V_321 = V_223 ;
T_1 V_15 = F_131 ( V_129 ) ;
T_1 V_289 = V_15 + V_30 - 1 ;
int V_37 ;
int V_294 = 0 ;
T_10 V_173 = 0 ;
T_8 V_257 = F_17 ( V_26 ) ;
unsigned long V_128 = V_257 >> V_127 ;
int V_329 ;
unsigned long V_313 = 0 ;
if ( V_275 -> V_339 == V_340 )
V_329 = V_196 ;
else
V_329 = V_189 ;
F_227 ( V_129 , V_26 , V_275 ) ;
F_45 ( ! F_228 ( V_129 ) ) ;
F_229 ( V_129 ) ;
V_173 = V_257 & ( V_30 - 1 ) ;
if ( V_129 -> V_126 > V_128 ||
( V_129 -> V_126 == V_128 && ! V_173 ) ) {
V_129 -> V_28 -> V_341 -> V_342 ( V_129 , 0 , V_30 ) ;
F_113 ( V_129 ) ;
return 0 ;
}
if ( V_129 -> V_126 == V_128 ) {
char * V_300 ;
V_300 = F_207 ( V_129 ) ;
memset ( V_300 + V_173 , 0 ,
V_30 - V_173 ) ;
F_209 ( V_300 ) ;
F_208 ( V_129 ) ;
}
V_173 = 0 ;
F_198 ( V_129 ) ;
V_37 = F_221 ( V_26 , V_129 , V_275 , V_321 , V_15 , & V_313 ) ;
if ( V_37 == 1 )
goto V_335;
if ( V_37 )
goto V_147;
V_37 = F_222 ( V_26 , V_129 , V_275 , V_321 ,
V_257 , V_313 , V_329 , & V_294 ) ;
if ( V_37 == 1 )
goto V_335;
V_147:
if ( V_294 == 0 ) {
F_106 ( V_129 ) ;
F_124 ( V_129 ) ;
}
if ( F_211 ( V_129 ) ) {
V_37 = V_37 < 0 ? V_37 : - V_153 ;
F_167 ( V_129 , V_37 , V_15 , V_289 ) ;
}
F_113 ( V_129 ) ;
return V_37 ;
V_335:
return 0 ;
}
void F_230 ( struct V_10 * V_11 )
{
F_231 ( & V_11 -> V_343 , V_344 ,
V_114 ) ;
}
static T_13 int
F_232 ( struct V_10 * V_11 ,
struct V_41 * V_32 ,
struct V_320 * V_321 )
{
unsigned long V_140 , V_200 ;
int V_345 = 0 ;
int V_37 = 0 ;
if ( ! F_233 ( V_11 ) ) {
V_345 = 1 ;
F_234 ( V_321 ) ;
F_235 ( V_11 ) ;
}
if ( F_160 ( V_344 , & V_11 -> V_343 ) ) {
F_236 ( V_11 ) ;
if ( ! V_321 -> V_346 )
return 0 ;
if ( ! V_345 ) {
F_234 ( V_321 ) ;
V_345 = 1 ;
}
while ( 1 ) {
F_230 ( V_11 ) ;
F_235 ( V_11 ) ;
if ( ! F_160 ( V_344 , & V_11 -> V_343 ) )
break;
F_236 ( V_11 ) ;
}
}
F_75 ( & V_11 -> V_347 ) ;
if ( F_237 ( V_348 , & V_11 -> V_343 ) ) {
F_238 ( V_344 , & V_11 -> V_343 ) ;
F_78 ( & V_11 -> V_347 ) ;
F_239 ( V_11 , V_349 ) ;
F_240 ( & V_32 -> V_350 ,
- V_11 -> V_21 ,
V_32 -> V_351 ) ;
V_37 = 1 ;
} else {
F_78 ( & V_11 -> V_347 ) ;
}
F_236 ( V_11 ) ;
if ( ! V_37 )
return V_37 ;
V_200 = F_148 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_140 = 0 ; V_140 < V_200 ; V_140 ++ ) {
struct V_129 * V_68 = V_11 -> V_138 [ V_140 ] ;
if ( ! F_241 ( V_68 ) ) {
if ( ! V_345 ) {
F_234 ( V_321 ) ;
V_345 = 1 ;
}
F_115 ( V_68 ) ;
}
}
return V_37 ;
}
static void F_242 ( struct V_10 * V_11 )
{
F_243 ( V_344 , & V_11 -> V_343 ) ;
F_244 () ;
F_245 ( & V_11 -> V_343 , V_344 ) ;
}
static void F_246 ( struct V_129 * V_129 )
{
struct V_10 * V_11 = (struct V_10 * ) V_129 -> V_203 ;
struct V_352 * V_353 = F_19 ( V_11 -> V_32 -> V_202 ) ;
F_123 ( V_129 ) ;
if ( F_247 ( V_354 , & V_11 -> V_343 ) )
return;
switch ( V_11 -> V_355 ) {
case - 1 :
F_238 ( V_356 , & V_353 -> V_357 ) ;
break;
case 0 :
F_238 ( V_358 , & V_353 -> V_357 ) ;
break;
case 1 :
F_238 ( V_359 , & V_353 -> V_357 ) ;
break;
default:
F_248 () ;
}
}
static void F_249 ( struct V_50 * V_50 )
{
struct V_243 * V_244 ;
struct V_10 * V_11 ;
int V_140 , V_147 ;
F_170 (bvec, bio, i) {
struct V_129 * V_129 = V_244 -> V_245 ;
V_11 = (struct V_10 * ) V_129 -> V_203 ;
F_23 ( ! V_11 ) ;
V_147 = F_44 ( & V_11 -> V_360 ) ;
if ( V_50 -> V_248 ||
F_160 ( V_354 , & V_11 -> V_343 ) ) {
F_168 ( V_129 ) ;
F_246 ( V_129 ) ;
}
F_124 ( V_129 ) ;
if ( ! V_147 )
continue;
F_242 ( V_11 ) ;
}
F_140 ( V_50 ) ;
}
static T_13 int F_250 ( struct V_10 * V_11 ,
struct V_41 * V_32 ,
struct V_274 * V_275 ,
struct V_320 * V_321 )
{
struct V_260 * V_193 = V_32 -> V_226 -> V_227 ;
struct V_24 * V_25 = & F_19 ( V_32 -> V_202 ) -> V_151 ;
T_1 V_64 = V_11 -> V_15 ;
unsigned long V_140 , V_200 ;
unsigned long V_214 = 0 ;
int V_270 = ( V_321 -> V_346 ? V_196 : V_189 ) | V_361 ;
int V_37 = 0 ;
F_243 ( V_354 , & V_11 -> V_343 ) ;
V_200 = F_148 ( V_11 -> V_15 , V_11 -> V_21 ) ;
F_40 ( & V_11 -> V_360 , V_200 ) ;
if ( F_251 ( V_11 ) == V_362 )
V_214 = V_363 ;
for ( V_140 = 0 ; V_140 < V_200 ; V_140 ++ ) {
struct V_129 * V_68 = V_11 -> V_138 [ V_140 ] ;
F_100 ( V_68 ) ;
F_106 ( V_68 ) ;
V_37 = F_189 ( V_270 , V_25 , V_275 , V_68 , V_64 >> 9 ,
V_30 , 0 , V_193 , & V_321 -> V_50 ,
- 1 , F_249 ,
0 , V_321 -> V_214 , V_214 , false ) ;
V_321 -> V_214 = V_214 ;
if ( V_37 ) {
F_246 ( V_68 ) ;
F_124 ( V_68 ) ;
if ( F_252 ( V_200 - V_140 , & V_11 -> V_360 ) )
F_242 ( V_11 ) ;
V_37 = - V_153 ;
break;
}
V_64 += V_30 ;
F_220 ( V_68 , V_275 , 1 ) ;
F_113 ( V_68 ) ;
}
if ( F_178 ( V_37 ) ) {
for (; V_140 < V_200 ; V_140 ++ ) {
struct V_129 * V_68 = V_11 -> V_138 [ V_140 ] ;
F_100 ( V_68 ) ;
F_113 ( V_68 ) ;
}
}
return V_37 ;
}
int F_253 ( struct V_53 * V_28 ,
struct V_274 * V_275 )
{
struct V_24 * V_25 = & F_19 ( V_28 -> V_29 ) -> V_151 ;
struct V_41 * V_32 = F_19 ( V_28 -> V_29 ) -> V_31 -> V_32 ;
struct V_10 * V_11 , * V_364 = NULL ;
struct V_320 V_321 = {
. V_50 = NULL ,
. V_25 = V_25 ,
. V_325 = 0 ,
. V_346 = V_275 -> V_339 == V_340 ,
. V_214 = 0 ,
} ;
int V_37 = 0 ;
int V_147 = 0 ;
int V_365 = 0 ;
struct V_366 V_367 ;
int V_139 ;
T_9 V_126 ;
T_9 V_16 ;
int V_368 = 0 ;
int V_369 ;
F_254 ( & V_367 , 0 ) ;
if ( V_275 -> V_315 ) {
V_126 = V_28 -> V_319 ;
V_16 = - 1 ;
} else {
V_126 = V_275 -> V_316 >> V_127 ;
V_16 = V_275 -> V_317 >> V_127 ;
V_368 = 1 ;
}
if ( V_275 -> V_339 == V_340 )
V_369 = V_370 ;
else
V_369 = V_371 ;
V_372:
if ( V_275 -> V_339 == V_340 )
F_255 ( V_28 , V_126 , V_16 ) ;
while ( ! V_147 && ! V_365 && ( V_126 <= V_16 ) &&
( V_139 = F_256 ( & V_367 , V_28 , & V_126 , V_369 ,
F_126 ( V_16 - V_126 , ( T_9 ) V_373 - 1 ) + 1 ) ) ) {
unsigned V_140 ;
V_368 = 1 ;
for ( V_140 = 0 ; V_140 < V_139 ; V_140 ++ ) {
struct V_129 * V_129 = V_367 . V_138 [ V_140 ] ;
if ( ! F_194 ( V_129 ) )
continue;
if ( ! V_275 -> V_315 && V_129 -> V_126 > V_16 ) {
V_147 = 1 ;
break;
}
F_75 ( & V_28 -> V_374 ) ;
if ( ! F_194 ( V_129 ) ) {
F_78 ( & V_28 -> V_374 ) ;
continue;
}
V_11 = (struct V_10 * ) V_129 -> V_203 ;
if ( F_45 ( ! V_11 ) ) {
F_78 ( & V_28 -> V_374 ) ;
continue;
}
if ( V_11 == V_364 ) {
F_78 ( & V_28 -> V_374 ) ;
continue;
}
V_37 = F_257 ( & V_11 -> V_17 ) ;
F_78 ( & V_28 -> V_374 ) ;
if ( ! V_37 )
continue;
V_364 = V_11 ;
V_37 = F_232 ( V_11 , V_32 , & V_321 ) ;
if ( ! V_37 ) {
F_258 ( V_11 ) ;
continue;
}
V_37 = F_250 ( V_11 , V_32 , V_275 , & V_321 ) ;
if ( V_37 ) {
V_147 = 1 ;
F_258 ( V_11 ) ;
break;
}
F_258 ( V_11 ) ;
V_365 = V_275 -> V_314 <= 0 ;
}
F_259 ( & V_367 ) ;
F_79 () ;
}
if ( ! V_368 && ! V_147 ) {
V_368 = 1 ;
V_126 = 0 ;
goto V_372;
}
F_234 ( & V_321 ) ;
return V_37 ;
}
static int F_260 ( struct V_24 * V_25 ,
struct V_53 * V_28 ,
struct V_274 * V_275 ,
T_14 V_375 , void * V_223 ,
void (* F_261)( void * ) )
{
struct V_26 * V_26 = V_28 -> V_29 ;
int V_37 = 0 ;
int V_147 = 0 ;
int V_100 = 0 ;
int V_365 = 0 ;
struct V_366 V_367 ;
int V_139 ;
T_9 V_126 ;
T_9 V_16 ;
int V_368 = 0 ;
int V_369 ;
if ( ! F_262 ( V_26 ) )
return 0 ;
F_254 ( & V_367 , 0 ) ;
if ( V_275 -> V_315 ) {
V_126 = V_28 -> V_319 ;
V_16 = - 1 ;
} else {
V_126 = V_275 -> V_316 >> V_127 ;
V_16 = V_275 -> V_317 >> V_127 ;
V_368 = 1 ;
}
if ( V_275 -> V_339 == V_340 )
V_369 = V_370 ;
else
V_369 = V_371 ;
V_372:
if ( V_275 -> V_339 == V_340 )
F_255 ( V_28 , V_126 , V_16 ) ;
while ( ! V_147 && ! V_365 && ( V_126 <= V_16 ) &&
( V_139 = F_256 ( & V_367 , V_28 , & V_126 , V_369 ,
F_126 ( V_16 - V_126 , ( T_9 ) V_373 - 1 ) + 1 ) ) ) {
unsigned V_140 ;
V_368 = 1 ;
for ( V_140 = 0 ; V_140 < V_139 ; V_140 ++ ) {
struct V_129 * V_129 = V_367 . V_138 [ V_140 ] ;
if ( ! F_241 ( V_129 ) ) {
F_261 ( V_223 ) ;
F_115 ( V_129 ) ;
}
if ( F_178 ( V_129 -> V_28 != V_28 ) ) {
F_113 ( V_129 ) ;
continue;
}
if ( ! V_275 -> V_315 && V_129 -> V_126 > V_16 ) {
V_147 = 1 ;
F_113 ( V_129 ) ;
continue;
}
if ( V_275 -> V_339 != V_376 ) {
if ( F_225 ( V_129 ) )
F_261 ( V_223 ) ;
F_263 ( V_129 ) ;
}
if ( F_225 ( V_129 ) ||
! F_100 ( V_129 ) ) {
F_113 ( V_129 ) ;
continue;
}
V_37 = (* V_375)( V_129 , V_275 , V_223 ) ;
if ( F_178 ( V_37 == V_377 ) ) {
F_113 ( V_129 ) ;
V_37 = 0 ;
}
if ( ! V_100 && V_37 < 0 )
V_100 = V_37 ;
V_365 = V_275 -> V_314 <= 0 ;
}
F_259 ( & V_367 ) ;
F_79 () ;
}
if ( ! V_368 && ! V_147 && ! V_100 ) {
V_368 = 1 ;
V_126 = 0 ;
goto V_372;
}
F_264 ( V_26 ) ;
return V_100 ;
}
static void F_265 ( struct V_320 * V_321 )
{
if ( V_321 -> V_50 ) {
int V_270 = V_189 ;
int V_37 ;
if ( V_321 -> V_346 )
V_270 = V_196 ;
V_37 = F_185 ( V_270 , V_321 -> V_50 , 0 , V_321 -> V_214 ) ;
F_23 ( V_37 < 0 ) ;
V_321 -> V_50 = NULL ;
}
}
static T_5 void F_234 ( void * V_223 )
{
struct V_320 * V_321 = V_223 ;
F_265 ( V_321 ) ;
}
int F_266 ( struct V_24 * V_25 , struct V_129 * V_129 ,
T_12 * V_286 ,
struct V_274 * V_275 )
{
int V_37 ;
struct V_320 V_321 = {
. V_50 = NULL ,
. V_25 = V_25 ,
. V_286 = V_286 ,
. V_325 = 0 ,
. V_346 = V_275 -> V_339 == V_340 ,
. V_214 = 0 ,
} ;
V_37 = F_226 ( V_129 , V_275 , & V_321 ) ;
F_265 ( & V_321 ) ;
return V_37 ;
}
int F_267 ( struct V_24 * V_25 , struct V_26 * V_26 ,
T_1 V_15 , T_1 V_16 , T_12 * V_286 ,
int V_378 )
{
int V_37 = 0 ;
struct V_53 * V_28 = V_26 -> V_130 ;
struct V_129 * V_129 ;
unsigned long V_139 = ( V_16 - V_15 + V_30 ) >>
V_127 ;
struct V_320 V_321 = {
. V_50 = NULL ,
. V_25 = V_25 ,
. V_286 = V_286 ,
. V_325 = 1 ,
. V_346 = V_378 == V_340 ,
. V_214 = 0 ,
} ;
struct V_274 V_379 = {
. V_339 = V_378 ,
. V_314 = V_139 * 2 ,
. V_316 = V_15 ,
. V_317 = V_16 + 1 ,
} ;
while ( V_15 <= V_16 ) {
V_129 = F_99 ( V_28 , V_15 >> V_127 ) ;
if ( F_100 ( V_129 ) )
V_37 = F_226 ( V_129 , & V_379 , & V_321 ) ;
else {
if ( V_25 -> V_55 && V_25 -> V_55 -> V_242 )
V_25 -> V_55 -> V_242 ( V_129 , V_15 ,
V_15 + V_30 - 1 ,
NULL , 1 ) ;
F_113 ( V_129 ) ;
}
F_101 ( V_129 ) ;
V_15 += V_30 ;
}
F_265 ( & V_321 ) ;
return V_37 ;
}
int F_268 ( struct V_24 * V_25 ,
struct V_53 * V_28 ,
T_12 * V_286 ,
struct V_274 * V_275 )
{
int V_37 = 0 ;
struct V_320 V_321 = {
. V_50 = NULL ,
. V_25 = V_25 ,
. V_286 = V_286 ,
. V_325 = 0 ,
. V_346 = V_275 -> V_339 == V_340 ,
. V_214 = 0 ,
} ;
V_37 = F_260 ( V_25 , V_28 , V_275 ,
F_226 , & V_321 ,
F_234 ) ;
F_265 ( & V_321 ) ;
return V_37 ;
}
int F_269 ( struct V_24 * V_25 ,
struct V_53 * V_28 ,
struct V_4 * V_138 , unsigned V_139 ,
T_12 V_286 )
{
struct V_50 * V_50 = NULL ;
unsigned V_380 ;
unsigned long V_214 = 0 ;
struct V_129 * V_381 [ 16 ] ;
struct V_129 * V_129 ;
struct V_209 * V_287 = NULL ;
int V_294 = 0 ;
T_1 V_288 = ( T_1 ) - 1 ;
for ( V_380 = 0 ; V_380 < V_139 ; V_380 ++ ) {
V_129 = F_11 ( V_138 -> V_79 , struct V_129 , V_382 ) ;
F_270 ( & V_129 -> V_7 ) ;
F_8 ( & V_129 -> V_382 ) ;
if ( F_271 ( V_129 , V_28 ,
V_129 -> V_126 , V_125 ) ) {
F_101 ( V_129 ) ;
continue;
}
V_381 [ V_294 ++ ] = V_129 ;
if ( V_294 < F_272 ( V_381 ) )
continue;
F_217 ( V_25 , V_381 , V_294 , V_286 , & V_287 ,
& V_50 , 0 , & V_214 , V_312 , & V_288 ) ;
V_294 = 0 ;
}
if ( V_294 )
F_217 ( V_25 , V_381 , V_294 , V_286 , & V_287 ,
& V_50 , 0 , & V_214 , V_312 , & V_288 ) ;
if ( V_287 )
F_159 ( V_287 ) ;
F_23 ( ! F_10 ( V_138 ) ) ;
if ( V_50 )
return F_185 ( V_312 , V_50 , 0 , V_214 ) ;
return 0 ;
}
int F_273 ( struct V_24 * V_25 ,
struct V_129 * V_129 , unsigned long V_64 )
{
struct V_1 * V_102 = NULL ;
T_1 V_15 = F_131 ( V_129 ) ;
T_1 V_16 = V_15 + V_30 - 1 ;
T_10 V_297 = V_129 -> V_28 -> V_29 -> V_42 -> V_298 ;
V_15 += F_210 ( V_64 , V_297 ) ;
if ( V_15 > V_16 )
return 0 ;
F_96 ( V_25 , V_15 , V_16 , & V_102 ) ;
F_263 ( V_129 ) ;
F_94 ( V_25 , V_15 , V_16 ,
V_124 | V_98 | V_106 |
V_383 ,
1 , 1 , & V_102 , V_125 ) ;
return 0 ;
}
static int F_274 ( struct V_211 * V_384 ,
struct V_24 * V_25 ,
struct V_129 * V_129 , T_3 V_58 )
{
T_1 V_15 = F_131 ( V_129 ) ;
T_1 V_16 = V_15 + V_30 - 1 ;
int V_37 = 1 ;
if ( F_118 ( V_25 , V_15 , V_16 ,
V_85 , 0 , NULL ) )
V_37 = 0 ;
else {
if ( ( V_58 & V_125 ) == V_125 )
V_58 = V_125 ;
V_37 = F_94 ( V_25 , V_15 , V_16 ,
~ ( V_124 | V_385 ) ,
0 , 0 , NULL , V_58 ) ;
if ( V_37 < 0 )
V_37 = 0 ;
else
V_37 = 1 ;
}
return V_37 ;
}
int F_275 ( struct V_211 * V_384 ,
struct V_24 * V_25 , struct V_129 * V_129 ,
T_3 V_58 )
{
struct V_209 * V_210 ;
T_1 V_15 = F_131 ( V_129 ) ;
T_1 V_16 = V_15 + V_30 - 1 ;
if ( F_74 ( V_58 ) &&
V_129 -> V_28 -> V_29 -> V_257 > V_386 ) {
T_1 V_21 ;
while ( V_15 <= V_16 ) {
V_21 = V_16 - V_15 + 1 ;
F_276 ( & V_384 -> V_57 ) ;
V_210 = F_157 ( V_384 , V_15 , V_21 ) ;
if ( ! V_210 ) {
F_277 ( & V_384 -> V_57 ) ;
break;
}
if ( F_160 ( V_387 , & V_210 -> V_7 ) ||
V_210 -> V_15 != V_15 ) {
F_277 ( & V_384 -> V_57 ) ;
F_159 ( V_210 ) ;
break;
}
if ( ! F_118 ( V_25 , V_210 -> V_15 ,
F_201 ( V_210 ) - 1 ,
V_124 | V_388 ,
0 , NULL ) ) {
F_278 ( V_384 , V_210 ) ;
F_159 ( V_210 ) ;
}
V_15 = F_201 ( V_210 ) ;
F_277 ( & V_384 -> V_57 ) ;
F_159 ( V_210 ) ;
}
}
return F_274 ( V_384 , V_25 , V_129 , V_58 ) ;
}
static struct V_209 * F_279 ( struct V_26 * V_26 ,
T_1 V_64 ,
T_1 V_161 ,
T_12 * V_286 )
{
T_1 V_389 = F_19 ( V_26 ) -> V_31 -> V_389 ;
struct V_209 * V_210 ;
T_1 V_21 ;
if ( V_64 >= V_161 )
return NULL ;
while ( 1 ) {
V_21 = V_161 - V_64 ;
if ( V_21 == 0 )
break;
V_21 = F_210 ( V_21 , V_389 ) ;
V_210 = V_286 ( V_26 , NULL , 0 , V_64 , V_21 , 0 ) ;
if ( F_202 ( V_210 ) )
return V_210 ;
if ( ! F_160 ( V_390 , & V_210 -> V_7 ) &&
V_210 -> V_215 != V_305 ) {
return V_210 ;
}
V_64 = F_201 ( V_210 ) ;
F_159 ( V_210 ) ;
if ( V_64 >= V_161 )
break;
}
return NULL ;
}
int F_280 ( struct V_26 * V_26 , struct V_391 * V_392 ,
T_15 V_15 , T_15 V_21 , T_12 * V_286 )
{
int V_37 = 0 ;
T_1 V_258 = V_15 ;
T_1 F_127 = V_15 + V_21 ;
T_16 V_7 = 0 ;
T_16 V_393 ;
T_1 V_161 ;
T_1 V_394 = 0 ;
T_1 V_395 = 0 ;
T_1 V_27 = F_17 ( V_26 ) ;
struct V_396 V_397 ;
struct V_209 * V_210 = NULL ;
struct V_1 * V_102 = NULL ;
struct V_398 * V_399 ;
struct V_199 * V_31 = F_19 ( V_26 ) -> V_31 ;
int V_16 = 0 ;
T_1 V_400 = 0 ;
T_1 V_401 = 0 ;
T_1 V_336 = 0 ;
if ( V_21 == 0 )
return - V_402 ;
V_399 = F_281 () ;
if ( ! V_399 )
return - V_45 ;
V_399 -> V_403 = 1 ;
V_15 = F_282 ( V_15 , F_19 ( V_26 ) -> V_31 -> V_389 ) ;
V_21 = F_283 ( F_127 , F_19 ( V_26 ) -> V_31 -> V_389 ) - V_15 ;
V_37 = F_284 ( NULL , V_31 , V_399 , F_20 ( V_26 ) , - 1 ,
0 ) ;
if ( V_37 < 0 ) {
F_285 ( V_399 ) ;
return V_37 ;
}
F_45 ( ! V_37 ) ;
V_399 -> V_404 [ 0 ] -- ;
F_286 ( V_399 -> V_405 [ 0 ] , & V_397 , V_399 -> V_404 [ 0 ] ) ;
V_393 = V_397 . type ;
if ( V_397 . V_406 != F_20 ( V_26 ) ||
V_393 != V_407 ) {
V_161 = ( T_1 ) - 1 ;
V_394 = V_27 ;
} else {
V_161 = V_397 . V_64 ;
V_394 = V_161 + 1 ;
}
F_287 ( V_399 ) ;
if ( V_161 < V_27 ) {
V_161 = ( T_1 ) - 1 ;
V_394 = V_27 ;
}
F_96 ( & F_19 ( V_26 ) -> V_151 , V_15 , V_15 + V_21 - 1 ,
& V_102 ) ;
V_210 = F_279 ( V_26 , V_15 , V_394 ,
V_286 ) ;
if ( ! V_210 )
goto V_111;
if ( F_288 ( V_210 ) ) {
V_37 = F_289 ( V_210 ) ;
goto V_111;
}
while ( ! V_16 ) {
T_1 V_408 = 0 ;
if ( V_210 -> V_15 >= F_127 || F_201 ( V_210 ) < V_258 )
break;
V_400 = F_127 ( V_210 -> V_15 , V_258 ) ;
if ( ! F_160 ( V_216 , & V_210 -> V_7 ) )
V_408 = V_400 - V_210 -> V_15 ;
V_336 = F_201 ( V_210 ) ;
V_401 = V_336 - V_400 ;
V_395 = 0 ;
V_7 = 0 ;
V_258 = F_201 ( V_210 ) ;
if ( V_258 >= F_127 )
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
V_37 = F_290 ( NULL , V_31 -> V_32 ,
V_31 -> V_406 ,
F_20 ( V_26 ) , V_417 ) ;
if ( V_37 < 0 )
goto V_418;
if ( V_37 )
V_7 |= V_419 ;
V_37 = 0 ;
}
if ( F_160 ( V_216 , & V_210 -> V_7 ) )
V_7 |= V_420 ;
if ( F_160 ( V_304 , & V_210 -> V_7 ) )
V_7 |= V_421 ;
F_159 ( V_210 ) ;
V_210 = NULL ;
if ( ( V_400 >= V_161 ) || V_401 == ( T_1 ) - 1 ||
( V_161 == ( T_1 ) - 1 && V_27 <= V_336 ) ) {
V_7 |= V_410 ;
V_16 = 1 ;
}
V_210 = F_279 ( V_26 , V_258 , V_394 ,
V_286 ) ;
if ( F_288 ( V_210 ) ) {
V_37 = F_289 ( V_210 ) ;
goto V_111;
}
if ( ! V_210 ) {
V_7 |= V_410 ;
V_16 = 1 ;
}
V_37 = F_291 ( V_392 , V_400 , V_395 ,
V_401 , V_7 ) ;
if ( V_37 ) {
if ( V_37 == 1 )
V_37 = 0 ;
goto V_418;
}
}
V_418:
F_159 ( V_210 ) ;
V_111:
F_285 ( V_399 ) ;
F_119 ( & F_19 ( V_26 ) -> V_151 , V_15 , V_15 + V_21 - 1 ,
& V_102 , V_125 ) ;
return V_37 ;
}
static void F_292 ( struct V_10 * V_11 )
{
F_7 ( & V_11 -> V_14 ) ;
F_14 ( V_22 , V_11 ) ;
}
int F_293 ( struct V_10 * V_11 )
{
return ( F_13 ( & V_11 -> V_360 ) ||
F_160 ( V_344 , & V_11 -> V_343 ) ||
F_160 ( V_348 , & V_11 -> V_343 ) ) ;
}
static void F_294 ( struct V_10 * V_11 )
{
unsigned long V_126 ;
struct V_129 * V_129 ;
int V_422 = ! F_160 ( V_423 , & V_11 -> V_343 ) ;
F_23 ( F_293 ( V_11 ) ) ;
V_126 = F_148 ( V_11 -> V_15 , V_11 -> V_21 ) ;
if ( V_126 == 0 )
return;
do {
V_126 -- ;
V_129 = V_11 -> V_138 [ V_126 ] ;
if ( ! V_129 )
continue;
if ( V_422 )
F_75 ( & V_129 -> V_28 -> V_374 ) ;
if ( F_194 ( V_129 ) &&
V_129 -> V_203 == ( unsigned long ) V_11 ) {
F_23 ( F_160 ( V_348 , & V_11 -> V_343 ) ) ;
F_23 ( F_116 ( V_129 ) ) ;
F_23 ( F_225 ( V_129 ) ) ;
F_295 ( V_129 ) ;
F_197 ( V_129 , 0 ) ;
F_101 ( V_129 ) ;
}
if ( V_422 )
F_78 ( & V_129 -> V_28 -> V_374 ) ;
F_101 ( V_129 ) ;
} while ( V_126 != 0 );
}
static inline void F_296 ( struct V_10 * V_11 )
{
F_294 ( V_11 ) ;
F_292 ( V_11 ) ;
}
static struct V_10 *
F_297 ( struct V_41 * V_32 , T_1 V_15 ,
unsigned long V_21 )
{
struct V_10 * V_11 = NULL ;
V_11 = F_298 ( V_22 , V_125 | V_424 ) ;
V_11 -> V_15 = V_15 ;
V_11 -> V_21 = V_21 ;
V_11 -> V_32 = V_32 ;
V_11 -> V_343 = 0 ;
F_299 ( & V_11 -> V_57 ) ;
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
F_36 ( & V_11 -> V_347 ) ;
F_40 ( & V_11 -> V_17 , 1 ) ;
F_40 ( & V_11 -> V_360 , 0 ) ;
F_300 ( V_434
> V_435 ) ;
F_23 ( V_21 > V_435 ) ;
return V_11 ;
}
struct V_10 * F_301 ( struct V_10 * V_436 )
{
unsigned long V_140 ;
struct V_129 * V_68 ;
struct V_10 * V_5 ;
unsigned long V_200 = F_148 ( V_436 -> V_15 , V_436 -> V_21 ) ;
V_5 = F_297 ( V_436 -> V_32 , V_436 -> V_15 , V_436 -> V_21 ) ;
if ( V_5 == NULL )
return NULL ;
for ( V_140 = 0 ; V_140 < V_200 ; V_140 ++ ) {
V_68 = F_302 ( V_125 ) ;
if ( ! V_68 ) {
F_296 ( V_5 ) ;
return NULL ;
}
F_193 ( V_5 , V_68 ) ;
F_45 ( F_116 ( V_68 ) ) ;
F_132 ( V_68 ) ;
V_5 -> V_138 [ V_140 ] = V_68 ;
}
F_303 ( V_5 , V_436 , 0 , 0 , V_436 -> V_21 ) ;
F_238 ( V_437 , & V_5 -> V_343 ) ;
F_238 ( V_423 , & V_5 -> V_343 ) ;
return V_5 ;
}
struct V_10 * F_304 ( struct V_41 * V_32 ,
T_1 V_15 , unsigned long V_21 )
{
struct V_10 * V_11 ;
unsigned long V_200 ;
unsigned long V_140 ;
V_200 = F_148 ( V_15 , V_21 ) ;
V_11 = F_297 ( V_32 , V_15 , V_21 ) ;
if ( ! V_11 )
return NULL ;
for ( V_140 = 0 ; V_140 < V_200 ; V_140 ++ ) {
V_11 -> V_138 [ V_140 ] = F_302 ( V_125 ) ;
if ( ! V_11 -> V_138 [ V_140 ] )
goto V_100;
}
F_305 ( V_11 ) ;
F_306 ( V_11 , 0 ) ;
F_238 ( V_423 , & V_11 -> V_343 ) ;
return V_11 ;
V_100:
for (; V_140 > 0 ; V_140 -- )
F_307 ( V_11 -> V_138 [ V_140 - 1 ] ) ;
F_292 ( V_11 ) ;
return NULL ;
}
struct V_10 * F_308 ( struct V_41 * V_32 ,
T_1 V_15 )
{
unsigned long V_21 ;
if ( ! V_32 ) {
V_21 = 4096 ;
} else {
V_21 = V_32 -> V_438 -> V_439 ;
}
return F_304 ( V_32 , V_15 , V_21 ) ;
}
static void F_309 ( struct V_10 * V_11 )
{
int V_17 ;
V_17 = F_13 ( & V_11 -> V_17 ) ;
if ( V_17 >= 2 && F_160 ( V_440 , & V_11 -> V_343 ) )
return;
F_75 ( & V_11 -> V_347 ) ;
if ( ! F_247 ( V_440 , & V_11 -> V_343 ) )
F_86 ( & V_11 -> V_17 ) ;
F_78 ( & V_11 -> V_347 ) ;
}
static void F_310 ( struct V_10 * V_11 ,
struct V_129 * V_441 )
{
unsigned long V_200 , V_140 ;
F_309 ( V_11 ) ;
V_200 = F_148 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_140 = 0 ; V_140 < V_200 ; V_140 ++ ) {
struct V_129 * V_68 = V_11 -> V_138 [ V_140 ] ;
if ( V_68 != V_441 )
F_311 ( V_68 ) ;
}
}
struct V_10 * F_312 ( struct V_41 * V_32 ,
T_1 V_15 )
{
struct V_10 * V_11 ;
F_313 () ;
V_11 = F_314 ( & V_32 -> V_442 ,
V_15 >> V_127 ) ;
if ( V_11 && F_257 ( & V_11 -> V_17 ) ) {
F_315 () ;
if ( F_160 ( V_443 , & V_11 -> V_343 ) ) {
F_75 ( & V_11 -> V_347 ) ;
F_78 ( & V_11 -> V_347 ) ;
}
F_310 ( V_11 , NULL ) ;
return V_11 ;
}
F_315 () ;
return NULL ;
}
struct V_10 * F_316 ( struct V_41 * V_32 ,
T_1 V_15 )
{
struct V_10 * V_11 , * V_444 = NULL ;
int V_37 ;
V_11 = F_312 ( V_32 , V_15 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_308 ( V_32 , V_15 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_32 = V_32 ;
V_109:
V_37 = F_317 ( V_125 & ~ V_445 ) ;
if ( V_37 )
goto V_446;
F_75 ( & V_32 -> V_447 ) ;
V_37 = F_318 ( & V_32 -> V_442 ,
V_15 >> V_127 , V_11 ) ;
F_78 ( & V_32 -> V_447 ) ;
F_319 () ;
if ( V_37 == - V_90 ) {
V_444 = F_312 ( V_32 , V_15 ) ;
if ( V_444 )
goto V_446;
else
goto V_109;
}
F_309 ( V_11 ) ;
F_238 ( V_448 , & V_11 -> V_343 ) ;
F_86 ( & V_11 -> V_17 ) ;
return V_11 ;
V_446:
F_296 ( V_11 ) ;
return V_444 ;
}
struct V_10 * F_320 ( struct V_41 * V_32 ,
T_1 V_15 )
{
unsigned long V_21 = V_32 -> V_438 -> V_439 ;
unsigned long V_200 = F_148 ( V_15 , V_21 ) ;
unsigned long V_140 ;
unsigned long V_126 = V_15 >> V_127 ;
struct V_10 * V_11 ;
struct V_10 * V_444 = NULL ;
struct V_129 * V_68 ;
struct V_53 * V_28 = V_32 -> V_202 -> V_130 ;
int V_241 = 1 ;
int V_37 ;
V_11 = F_312 ( V_32 , V_15 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_297 ( V_32 , V_15 , V_21 ) ;
if ( ! V_11 )
return NULL ;
for ( V_140 = 0 ; V_140 < V_200 ; V_140 ++ , V_126 ++ ) {
V_68 = F_321 ( V_28 , V_126 , V_125 | V_424 ) ;
if ( ! V_68 )
goto V_446;
F_75 ( & V_28 -> V_374 ) ;
if ( F_194 ( V_68 ) ) {
V_444 = (struct V_10 * ) V_68 -> V_203 ;
if ( F_257 ( & V_444 -> V_17 ) ) {
F_78 ( & V_28 -> V_374 ) ;
F_113 ( V_68 ) ;
F_101 ( V_68 ) ;
F_310 ( V_444 , V_68 ) ;
goto V_446;
}
V_444 = NULL ;
F_295 ( V_68 ) ;
F_45 ( F_116 ( V_68 ) ) ;
F_101 ( V_68 ) ;
}
F_193 ( V_11 , V_68 ) ;
F_78 ( & V_28 -> V_374 ) ;
F_45 ( F_116 ( V_68 ) ) ;
V_11 -> V_138 [ V_140 ] = V_68 ;
if ( ! F_204 ( V_68 ) )
V_241 = 0 ;
}
if ( V_241 )
F_238 ( V_437 , & V_11 -> V_343 ) ;
V_109:
V_37 = F_317 ( V_125 & ~ V_445 ) ;
if ( V_37 )
goto V_446;
F_75 ( & V_32 -> V_447 ) ;
V_37 = F_318 ( & V_32 -> V_442 ,
V_15 >> V_127 , V_11 ) ;
F_78 ( & V_32 -> V_447 ) ;
F_319 () ;
if ( V_37 == - V_90 ) {
V_444 = F_312 ( V_32 , V_15 ) ;
if ( V_444 )
goto V_446;
else
goto V_109;
}
F_309 ( V_11 ) ;
F_238 ( V_448 , & V_11 -> V_343 ) ;
F_322 ( V_11 -> V_138 [ 0 ] ) ;
for ( V_140 = 1 ; V_140 < V_200 ; V_140 ++ ) {
V_68 = V_11 -> V_138 [ V_140 ] ;
F_323 ( V_68 ) ;
F_113 ( V_68 ) ;
}
F_113 ( V_11 -> V_138 [ 0 ] ) ;
return V_11 ;
V_446:
F_45 ( ! F_44 ( & V_11 -> V_17 ) ) ;
for ( V_140 = 0 ; V_140 < V_200 ; V_140 ++ ) {
if ( V_11 -> V_138 [ V_140 ] )
F_113 ( V_11 -> V_138 [ V_140 ] ) ;
}
F_296 ( V_11 ) ;
return V_444 ;
}
static inline void F_324 ( struct V_449 * V_6 )
{
struct V_10 * V_11 =
F_325 ( V_6 , struct V_10 , V_449 ) ;
F_292 ( V_11 ) ;
}
static int F_326 ( struct V_10 * V_11 )
{
F_45 ( F_13 ( & V_11 -> V_17 ) == 0 ) ;
if ( F_44 ( & V_11 -> V_17 ) ) {
if ( F_237 ( V_448 , & V_11 -> V_343 ) ) {
struct V_41 * V_32 = V_11 -> V_32 ;
F_78 ( & V_11 -> V_347 ) ;
F_75 ( & V_32 -> V_447 ) ;
F_327 ( & V_32 -> V_442 ,
V_11 -> V_15 >> V_127 ) ;
F_78 ( & V_32 -> V_447 ) ;
} else {
F_78 ( & V_11 -> V_347 ) ;
}
F_294 ( V_11 ) ;
#ifdef F_328
if ( F_178 ( F_160 ( V_423 , & V_11 -> V_343 ) ) ) {
F_292 ( V_11 ) ;
return 1 ;
}
#endif
F_329 ( & V_11 -> V_449 , F_324 ) ;
return 1 ;
}
F_78 ( & V_11 -> V_347 ) ;
return 0 ;
}
void F_258 ( struct V_10 * V_11 )
{
int V_17 ;
int V_450 ;
if ( ! V_11 )
return;
while ( 1 ) {
V_17 = F_13 ( & V_11 -> V_17 ) ;
if ( V_17 <= 3 )
break;
V_450 = F_330 ( & V_11 -> V_17 , V_17 , V_17 - 1 ) ;
if ( V_450 == V_17 )
return;
}
F_75 ( & V_11 -> V_347 ) ;
if ( F_13 ( & V_11 -> V_17 ) == 2 &&
F_160 ( V_423 , & V_11 -> V_343 ) )
F_76 ( & V_11 -> V_17 ) ;
if ( F_13 ( & V_11 -> V_17 ) == 2 &&
F_160 ( V_443 , & V_11 -> V_343 ) &&
! F_293 ( V_11 ) &&
F_237 ( V_440 , & V_11 -> V_343 ) )
F_76 ( & V_11 -> V_17 ) ;
F_326 ( V_11 ) ;
}
void F_331 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return;
F_75 ( & V_11 -> V_347 ) ;
F_238 ( V_443 , & V_11 -> V_343 ) ;
if ( F_13 ( & V_11 -> V_17 ) == 2 && ! F_293 ( V_11 ) &&
F_237 ( V_440 , & V_11 -> V_343 ) )
F_76 ( & V_11 -> V_17 ) ;
F_326 ( V_11 ) ;
}
void F_332 ( struct V_10 * V_11 )
{
unsigned long V_140 ;
unsigned long V_200 ;
struct V_129 * V_129 ;
V_200 = F_148 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_140 = 0 ; V_140 < V_200 ; V_140 ++ ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
if ( ! F_116 ( V_129 ) )
continue;
F_115 ( V_129 ) ;
F_45 ( ! F_194 ( V_129 ) ) ;
F_100 ( V_129 ) ;
F_333 ( & V_129 -> V_28 -> V_451 ) ;
if ( ! F_116 ( V_129 ) ) {
F_334 ( & V_129 -> V_28 -> V_452 ,
F_335 ( V_129 ) ,
V_371 ) ;
}
F_336 ( & V_129 -> V_28 -> V_451 ) ;
F_229 ( V_129 ) ;
F_113 ( V_129 ) ;
}
F_45 ( F_13 ( & V_11 -> V_17 ) == 0 ) ;
}
int F_337 ( struct V_10 * V_11 )
{
unsigned long V_140 ;
unsigned long V_200 ;
int V_453 = 0 ;
F_309 ( V_11 ) ;
V_453 = F_247 ( V_348 , & V_11 -> V_343 ) ;
V_200 = F_148 ( V_11 -> V_15 , V_11 -> V_21 ) ;
F_45 ( F_13 ( & V_11 -> V_17 ) == 0 ) ;
F_45 ( ! F_160 ( V_440 , & V_11 -> V_343 ) ) ;
for ( V_140 = 0 ; V_140 < V_200 ; V_140 ++ )
F_338 ( V_11 -> V_138 [ V_140 ] ) ;
return V_453 ;
}
void F_339 ( struct V_10 * V_11 )
{
unsigned long V_140 ;
struct V_129 * V_129 ;
unsigned long V_200 ;
F_243 ( V_437 , & V_11 -> V_343 ) ;
V_200 = F_148 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_140 = 0 ; V_140 < V_200 ; V_140 ++ ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
if ( V_129 )
F_168 ( V_129 ) ;
}
}
void F_305 ( struct V_10 * V_11 )
{
unsigned long V_140 ;
struct V_129 * V_129 ;
unsigned long V_200 ;
F_238 ( V_437 , & V_11 -> V_343 ) ;
V_200 = F_148 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_140 = 0 ; V_140 < V_200 ; V_140 ++ ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
F_132 ( V_129 ) ;
}
}
int F_340 ( struct V_10 * V_11 )
{
return F_160 ( V_437 , & V_11 -> V_343 ) ;
}
int F_341 ( struct V_24 * V_25 ,
struct V_10 * V_11 , T_1 V_15 , int V_113 ,
T_12 * V_286 , int V_174 )
{
unsigned long V_140 ;
unsigned long V_454 ;
struct V_129 * V_129 ;
int V_100 ;
int V_37 = 0 ;
int V_455 = 0 ;
int V_456 = 1 ;
unsigned long V_200 ;
unsigned long V_457 = 0 ;
struct V_50 * V_50 = NULL ;
unsigned long V_214 = 0 ;
if ( F_160 ( V_437 , & V_11 -> V_343 ) )
return 0 ;
if ( V_15 ) {
F_45 ( V_15 < V_11 -> V_15 ) ;
V_454 = ( V_15 >> V_127 ) -
( V_11 -> V_15 >> V_127 ) ;
} else {
V_454 = 0 ;
}
V_200 = F_148 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_140 = V_454 ; V_140 < V_200 ; V_140 ++ ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
if ( V_113 == V_458 ) {
if ( ! F_241 ( V_129 ) )
goto V_459;
} else {
F_115 ( V_129 ) ;
}
V_455 ++ ;
if ( ! F_204 ( V_129 ) ) {
V_457 ++ ;
V_456 = 0 ;
}
}
if ( V_456 ) {
if ( V_454 == 0 )
F_238 ( V_437 , & V_11 -> V_343 ) ;
goto V_459;
}
F_243 ( V_460 , & V_11 -> V_343 ) ;
V_11 -> V_461 = 0 ;
F_40 ( & V_11 -> V_360 , V_457 ) ;
for ( V_140 = V_454 ; V_140 < V_200 ; V_140 ++ ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
if ( ! F_204 ( V_129 ) ) {
F_229 ( V_129 ) ;
V_100 = F_218 ( V_25 , V_129 ,
V_286 , & V_50 ,
V_174 , & V_214 ,
V_312 | V_361 ) ;
if ( V_100 )
V_37 = V_100 ;
} else {
F_113 ( V_129 ) ;
}
}
if ( V_50 ) {
V_100 = F_185 ( V_312 | V_361 , V_50 , V_174 ,
V_214 ) ;
if ( V_100 )
return V_100 ;
}
if ( V_37 || V_113 != V_462 )
return V_37 ;
for ( V_140 = V_454 ; V_140 < V_200 ; V_140 ++ ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
F_342 ( V_129 ) ;
if ( ! F_204 ( V_129 ) )
V_37 = - V_153 ;
}
return V_37 ;
V_459:
V_140 = V_454 ;
while ( V_455 > 0 ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
V_140 ++ ;
F_113 ( V_129 ) ;
V_455 -- ;
}
return V_37 ;
}
void F_343 ( struct V_10 * V_11 , void * V_463 ,
unsigned long V_15 ,
unsigned long V_21 )
{
T_10 V_290 ;
T_10 V_64 ;
struct V_129 * V_129 ;
char * V_464 ;
char * V_465 = ( char * ) V_463 ;
T_10 V_466 = V_11 -> V_15 & ( ( T_1 ) V_30 - 1 ) ;
unsigned long V_140 = ( V_466 + V_15 ) >> V_127 ;
F_45 ( V_15 > V_11 -> V_21 ) ;
F_45 ( V_15 + V_21 > V_11 -> V_15 + V_11 -> V_21 ) ;
V_64 = ( V_466 + V_15 ) & ( V_30 - 1 ) ;
while ( V_21 > 0 ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
V_290 = F_126 ( V_21 , ( V_30 - V_64 ) ) ;
V_464 = F_344 ( V_129 ) ;
memcpy ( V_465 , V_464 + V_64 , V_290 ) ;
V_465 += V_290 ;
V_21 -= V_290 ;
V_64 = 0 ;
V_140 ++ ;
}
}
int F_345 ( struct V_10 * V_11 , void T_17 * V_463 ,
unsigned long V_15 ,
unsigned long V_21 )
{
T_10 V_290 ;
T_10 V_64 ;
struct V_129 * V_129 ;
char * V_464 ;
char T_17 * V_465 = ( char T_17 * ) V_463 ;
T_10 V_466 = V_11 -> V_15 & ( ( T_1 ) V_30 - 1 ) ;
unsigned long V_140 = ( V_466 + V_15 ) >> V_127 ;
int V_37 = 0 ;
F_45 ( V_15 > V_11 -> V_21 ) ;
F_45 ( V_15 + V_21 > V_11 -> V_15 + V_11 -> V_21 ) ;
V_64 = ( V_466 + V_15 ) & ( V_30 - 1 ) ;
while ( V_21 > 0 ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
V_290 = F_126 ( V_21 , ( V_30 - V_64 ) ) ;
V_464 = F_344 ( V_129 ) ;
if ( F_346 ( V_465 , V_464 + V_64 , V_290 ) ) {
V_37 = - V_467 ;
break;
}
V_465 += V_290 ;
V_21 -= V_290 ;
V_64 = 0 ;
V_140 ++ ;
}
return V_37 ;
}
int F_347 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_468 , char * * V_384 ,
unsigned long * V_469 ,
unsigned long * V_470 )
{
T_10 V_64 = V_15 & ( V_30 - 1 ) ;
char * V_464 ;
struct V_129 * V_68 ;
T_10 V_466 = V_11 -> V_15 & ( ( T_1 ) V_30 - 1 ) ;
unsigned long V_140 = ( V_466 + V_15 ) >> V_127 ;
unsigned long V_471 = ( V_466 + V_15 + V_468 - 1 ) >>
V_127 ;
if ( V_140 != V_471 )
return - V_402 ;
if ( V_140 == 0 ) {
V_64 = V_466 ;
* V_469 = 0 ;
} else {
V_64 = 0 ;
* V_469 = ( ( T_1 ) V_140 << V_127 ) - V_466 ;
}
if ( V_15 + V_468 > V_11 -> V_21 ) {
F_62 ( 1 , V_20 L_28
L_29 ,
V_11 -> V_15 , V_11 -> V_21 , V_15 , V_468 ) ;
return - V_402 ;
}
V_68 = V_11 -> V_138 [ V_140 ] ;
V_464 = F_344 ( V_68 ) ;
* V_384 = V_464 + V_64 ;
* V_470 = V_30 - V_64 ;
return 0 ;
}
int F_348 ( struct V_10 * V_11 , const void * V_472 ,
unsigned long V_15 ,
unsigned long V_21 )
{
T_10 V_290 ;
T_10 V_64 ;
struct V_129 * V_129 ;
char * V_464 ;
char * V_473 = ( char * ) V_472 ;
T_10 V_466 = V_11 -> V_15 & ( ( T_1 ) V_30 - 1 ) ;
unsigned long V_140 = ( V_466 + V_15 ) >> V_127 ;
int V_37 = 0 ;
F_45 ( V_15 > V_11 -> V_21 ) ;
F_45 ( V_15 + V_21 > V_11 -> V_15 + V_11 -> V_21 ) ;
V_64 = ( V_466 + V_15 ) & ( V_30 - 1 ) ;
while ( V_21 > 0 ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
V_290 = F_126 ( V_21 , ( V_30 - V_64 ) ) ;
V_464 = F_344 ( V_129 ) ;
V_37 = memcmp ( V_473 , V_464 + V_64 , V_290 ) ;
if ( V_37 )
break;
V_473 += V_290 ;
V_21 -= V_290 ;
V_64 = 0 ;
V_140 ++ ;
}
return V_37 ;
}
void F_349 ( struct V_10 * V_11 , const void * V_474 ,
unsigned long V_15 , unsigned long V_21 )
{
T_10 V_290 ;
T_10 V_64 ;
struct V_129 * V_129 ;
char * V_464 ;
char * V_436 = ( char * ) V_474 ;
T_10 V_466 = V_11 -> V_15 & ( ( T_1 ) V_30 - 1 ) ;
unsigned long V_140 = ( V_466 + V_15 ) >> V_127 ;
F_45 ( V_15 > V_11 -> V_21 ) ;
F_45 ( V_15 + V_21 > V_11 -> V_15 + V_11 -> V_21 ) ;
V_64 = ( V_466 + V_15 ) & ( V_30 - 1 ) ;
while ( V_21 > 0 ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
F_45 ( ! F_204 ( V_129 ) ) ;
V_290 = F_126 ( V_21 , V_30 - V_64 ) ;
V_464 = F_344 ( V_129 ) ;
memcpy ( V_464 + V_64 , V_436 , V_290 ) ;
V_436 += V_290 ;
V_21 -= V_290 ;
V_64 = 0 ;
V_140 ++ ;
}
}
void F_350 ( struct V_10 * V_11 , char V_475 ,
unsigned long V_15 , unsigned long V_21 )
{
T_10 V_290 ;
T_10 V_64 ;
struct V_129 * V_129 ;
char * V_464 ;
T_10 V_466 = V_11 -> V_15 & ( ( T_1 ) V_30 - 1 ) ;
unsigned long V_140 = ( V_466 + V_15 ) >> V_127 ;
F_45 ( V_15 > V_11 -> V_21 ) ;
F_45 ( V_15 + V_21 > V_11 -> V_15 + V_11 -> V_21 ) ;
V_64 = ( V_466 + V_15 ) & ( V_30 - 1 ) ;
while ( V_21 > 0 ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
F_45 ( ! F_204 ( V_129 ) ) ;
V_290 = F_126 ( V_21 , V_30 - V_64 ) ;
V_464 = F_344 ( V_129 ) ;
memset ( V_464 + V_64 , V_475 , V_290 ) ;
V_21 -= V_290 ;
V_64 = 0 ;
V_140 ++ ;
}
}
void F_303 ( struct V_10 * V_465 , struct V_10 * V_436 ,
unsigned long V_476 , unsigned long V_477 ,
unsigned long V_21 )
{
T_1 V_478 = V_465 -> V_21 ;
T_10 V_290 ;
T_10 V_64 ;
struct V_129 * V_129 ;
char * V_464 ;
T_10 V_466 = V_465 -> V_15 & ( ( T_1 ) V_30 - 1 ) ;
unsigned long V_140 = ( V_466 + V_476 ) >> V_127 ;
F_45 ( V_436 -> V_21 != V_478 ) ;
V_64 = ( V_466 + V_476 ) &
( V_30 - 1 ) ;
while ( V_21 > 0 ) {
V_129 = V_465 -> V_138 [ V_140 ] ;
F_45 ( ! F_204 ( V_129 ) ) ;
V_290 = F_126 ( V_21 , ( unsigned long ) ( V_30 - V_64 ) ) ;
V_464 = F_344 ( V_129 ) ;
F_343 ( V_436 , V_464 + V_64 , V_477 , V_290 ) ;
V_477 += V_290 ;
V_21 -= V_290 ;
V_64 = 0 ;
V_140 ++ ;
}
}
static inline void F_351 ( struct V_10 * V_11 ,
unsigned long V_15 , unsigned long V_294 ,
unsigned long * F_335 ,
T_10 * F_131 )
{
T_10 V_466 = V_11 -> V_15 & ( ( T_1 ) V_30 - 1 ) ;
T_10 V_479 = F_352 ( V_294 ) ;
T_10 V_64 ;
V_64 = V_466 + V_15 + V_479 ;
* F_335 = V_64 >> V_127 ;
* F_131 = V_64 & ( V_30 - 1 ) ;
}
int F_353 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_294 )
{
char * V_464 ;
struct V_129 * V_129 ;
unsigned long V_140 ;
T_10 V_64 ;
F_351 ( V_11 , V_15 , V_294 , & V_140 , & V_64 ) ;
V_129 = V_11 -> V_138 [ V_140 ] ;
F_45 ( ! F_204 ( V_129 ) ) ;
V_464 = F_344 ( V_129 ) ;
return 1U & ( V_464 [ V_64 ] >> ( V_294 & ( V_480 - 1 ) ) ) ;
}
void F_354 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_481 , unsigned long V_21 )
{
char * V_464 ;
struct V_129 * V_129 ;
unsigned long V_140 ;
T_10 V_64 ;
const unsigned int V_272 = V_481 + V_21 ;
int V_116 = V_480 - ( V_481 % V_480 ) ;
unsigned int V_482 = F_355 ( V_481 ) ;
F_351 ( V_11 , V_15 , V_481 , & V_140 , & V_64 ) ;
V_129 = V_11 -> V_138 [ V_140 ] ;
F_45 ( ! F_204 ( V_129 ) ) ;
V_464 = F_344 ( V_129 ) ;
while ( V_21 >= V_116 ) {
V_464 [ V_64 ] |= V_482 ;
V_21 -= V_116 ;
V_116 = V_480 ;
V_482 = ~ 0U ;
if ( ++ V_64 >= V_30 && V_21 > 0 ) {
V_64 = 0 ;
V_129 = V_11 -> V_138 [ ++ V_140 ] ;
F_45 ( ! F_204 ( V_129 ) ) ;
V_464 = F_344 ( V_129 ) ;
}
}
if ( V_21 ) {
V_482 &= F_356 ( V_272 ) ;
V_464 [ V_64 ] |= V_482 ;
}
}
void F_357 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_481 , unsigned long V_21 )
{
char * V_464 ;
struct V_129 * V_129 ;
unsigned long V_140 ;
T_10 V_64 ;
const unsigned int V_272 = V_481 + V_21 ;
int V_96 = V_480 - ( V_481 % V_480 ) ;
unsigned int V_483 = F_355 ( V_481 ) ;
F_351 ( V_11 , V_15 , V_481 , & V_140 , & V_64 ) ;
V_129 = V_11 -> V_138 [ V_140 ] ;
F_45 ( ! F_204 ( V_129 ) ) ;
V_464 = F_344 ( V_129 ) ;
while ( V_21 >= V_96 ) {
V_464 [ V_64 ] &= ~ V_483 ;
V_21 -= V_96 ;
V_96 = V_480 ;
V_483 = ~ 0U ;
if ( ++ V_64 >= V_30 && V_21 > 0 ) {
V_64 = 0 ;
V_129 = V_11 -> V_138 [ ++ V_140 ] ;
F_45 ( ! F_204 ( V_129 ) ) ;
V_464 = F_344 ( V_129 ) ;
}
}
if ( V_21 ) {
V_483 &= F_356 ( V_272 ) ;
V_464 [ V_64 ] &= ~ V_483 ;
}
}
static inline bool F_358 ( unsigned long V_436 , unsigned long V_465 , unsigned long V_21 )
{
unsigned long V_484 = ( V_436 > V_465 ) ? V_436 - V_465 : V_465 - V_436 ;
return V_484 < V_21 ;
}
static void F_359 ( struct V_129 * V_485 , struct V_129 * V_486 ,
unsigned long V_487 , unsigned long V_488 ,
unsigned long V_21 )
{
char * V_489 = F_344 ( V_485 ) ;
char * V_490 ;
int V_491 = 0 ;
if ( V_485 != V_486 ) {
V_490 = F_344 ( V_486 ) ;
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
void F_360 ( struct V_10 * V_465 , unsigned long V_476 ,
unsigned long V_477 , unsigned long V_21 )
{
T_10 V_290 ;
T_10 V_492 ;
T_10 V_493 ;
T_10 V_466 = V_465 -> V_15 & ( ( T_1 ) V_30 - 1 ) ;
unsigned long V_494 ;
unsigned long V_495 ;
if ( V_477 + V_21 > V_465 -> V_21 ) {
F_171 ( V_465 -> V_32 ,
L_30
L_31 , V_477 , V_21 , V_465 -> V_21 ) ;
F_23 ( 1 ) ;
}
if ( V_476 + V_21 > V_465 -> V_21 ) {
F_171 ( V_465 -> V_32 ,
L_32
L_31 , V_476 , V_21 , V_465 -> V_21 ) ;
F_23 ( 1 ) ;
}
while ( V_21 > 0 ) {
V_492 = ( V_466 + V_476 ) &
( V_30 - 1 ) ;
V_493 = ( V_466 + V_477 ) &
( V_30 - 1 ) ;
V_494 = ( V_466 + V_476 ) >> V_127 ;
V_495 = ( V_466 + V_477 ) >> V_127 ;
V_290 = F_126 ( V_21 , ( unsigned long ) ( V_30 -
V_493 ) ) ;
V_290 = F_112 (unsigned long, cur,
(unsigned long)(PAGE_SIZE - dst_off_in_page)) ;
F_359 ( V_465 -> V_138 [ V_494 ] , V_465 -> V_138 [ V_495 ] ,
V_492 , V_493 , V_290 ) ;
V_477 += V_290 ;
V_476 += V_290 ;
V_21 -= V_290 ;
}
}
void F_361 ( struct V_10 * V_465 , unsigned long V_476 ,
unsigned long V_477 , unsigned long V_21 )
{
T_10 V_290 ;
T_10 V_492 ;
T_10 V_493 ;
unsigned long V_496 = V_476 + V_21 - 1 ;
unsigned long V_497 = V_477 + V_21 - 1 ;
T_10 V_466 = V_465 -> V_15 & ( ( T_1 ) V_30 - 1 ) ;
unsigned long V_494 ;
unsigned long V_495 ;
if ( V_477 + V_21 > V_465 -> V_21 ) {
F_171 ( V_465 -> V_32 , L_30
L_33 , V_477 , V_21 , V_465 -> V_21 ) ;
F_23 ( 1 ) ;
}
if ( V_476 + V_21 > V_465 -> V_21 ) {
F_171 ( V_465 -> V_32 , L_32
L_33 , V_476 , V_21 , V_465 -> V_21 ) ;
F_23 ( 1 ) ;
}
if ( V_476 < V_477 ) {
F_360 ( V_465 , V_476 , V_477 , V_21 ) ;
return;
}
while ( V_21 > 0 ) {
V_494 = ( V_466 + V_496 ) >> V_127 ;
V_495 = ( V_466 + V_497 ) >> V_127 ;
V_492 = ( V_466 + V_496 ) &
( V_30 - 1 ) ;
V_493 = ( V_466 + V_497 ) &
( V_30 - 1 ) ;
V_290 = F_112 (unsigned long, len, src_off_in_page + 1 ) ;
V_290 = F_126 ( V_290 , V_492 + 1 ) ;
F_359 ( V_465 -> V_138 [ V_494 ] , V_465 -> V_138 [ V_495 ] ,
V_492 - V_290 + 1 ,
V_493 - V_290 + 1 , V_290 ) ;
V_496 -= V_290 ;
V_497 -= V_290 ;
V_21 -= V_290 ;
}
}
int F_362 ( struct V_129 * V_129 )
{
struct V_10 * V_11 ;
F_75 ( & V_129 -> V_28 -> V_374 ) ;
if ( ! F_194 ( V_129 ) ) {
F_78 ( & V_129 -> V_28 -> V_374 ) ;
return 1 ;
}
V_11 = (struct V_10 * ) V_129 -> V_203 ;
F_23 ( ! V_11 ) ;
F_75 ( & V_11 -> V_347 ) ;
if ( F_13 ( & V_11 -> V_17 ) != 1 || F_293 ( V_11 ) ) {
F_78 ( & V_11 -> V_347 ) ;
F_78 ( & V_129 -> V_28 -> V_374 ) ;
return 0 ;
}
F_78 ( & V_129 -> V_28 -> V_374 ) ;
if ( ! F_237 ( V_440 , & V_11 -> V_343 ) ) {
F_78 ( & V_11 -> V_347 ) ;
return 0 ;
}
return F_326 ( V_11 ) ;
}
