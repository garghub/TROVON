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
if ( V_24 -> V_25 && V_24 -> V_25 -> V_26 )
V_24 -> V_25 -> V_26 ( V_24 -> V_27 , V_22 ,
V_15 , V_16 ) ;
}
static void F_17 ( struct V_1 * V_2 , unsigned V_28 ,
struct V_29 * V_30 ,
int V_31 )
{
int V_32 ;
if ( ! V_30 )
return;
if ( V_31 && ( V_2 -> V_2 & V_28 ) == V_28 )
return;
if ( ! V_31 && ( V_2 -> V_2 & V_28 ) == 0 )
return;
V_30 -> V_33 += V_2 -> V_16 - V_2 -> V_15 + 1 ;
V_32 = F_18 ( & V_30 -> V_34 , V_2 -> V_15 , V_2 -> V_16 ,
V_35 ) ;
F_19 ( V_32 < 0 ) ;
}
static inline struct V_36 *
F_20 ( struct V_23 * V_24 )
{
if ( V_24 -> V_25 )
return V_24 -> V_25 -> F_20 ( V_24 -> V_27 ) ;
return NULL ;
}
int T_2 F_21 ( void )
{
V_18 = F_22 ( L_3 ,
sizeof( struct V_1 ) , 0 ,
V_37 , NULL ) ;
if ( ! V_18 )
return - V_38 ;
V_21 = F_22 ( L_4 ,
sizeof( struct V_10 ) , 0 ,
V_37 , NULL ) ;
if ( ! V_21 )
goto V_39;
V_40 = F_23 ( V_41 ,
F_24 ( struct V_42 , V_43 ) ,
V_44 ) ;
if ( ! V_40 )
goto V_45;
if ( F_25 ( V_40 , V_41 ) )
goto V_46;
return 0 ;
V_46:
F_26 ( V_40 ) ;
V_40 = NULL ;
V_45:
F_27 ( V_21 ) ;
V_21 = NULL ;
V_39:
F_27 ( V_18 ) ;
V_18 = NULL ;
return - V_38 ;
}
void F_28 ( void )
{
F_9 () ;
F_29 () ;
F_27 ( V_18 ) ;
F_27 ( V_21 ) ;
if ( V_40 )
F_26 ( V_40 ) ;
}
void F_30 ( struct V_23 * V_24 ,
void * V_27 )
{
V_24 -> V_2 = V_47 ;
V_24 -> V_25 = NULL ;
V_24 -> V_48 = 0 ;
F_31 ( & V_24 -> V_49 ) ;
V_24 -> V_27 = V_27 ;
}
static struct V_1 * F_32 ( T_3 V_50 )
{
struct V_1 * V_2 ;
V_50 &= ~ ( V_51 | V_52 ) ;
V_2 = F_33 ( V_18 , V_50 ) ;
if ( ! V_2 )
return V_2 ;
V_2 -> V_2 = 0 ;
V_2 -> V_53 = NULL ;
F_34 ( & V_2 -> V_3 ) ;
F_3 ( & V_2 -> V_14 , & V_12 ) ;
F_35 ( & V_2 -> V_17 , 1 ) ;
F_36 ( & V_2 -> V_54 ) ;
F_37 ( V_2 , V_50 , V_55 ) ;
return V_2 ;
}
void F_38 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( F_39 ( & V_2 -> V_17 ) ) {
F_40 ( F_1 ( V_2 ) ) ;
F_7 ( & V_2 -> V_14 ) ;
F_41 ( V_2 , V_55 ) ;
F_14 ( V_18 , V_2 ) ;
}
}
static struct V_3 * F_42 ( struct V_56 * V_57 ,
struct V_3 * V_58 ,
T_1 V_59 ,
struct V_3 * V_60 ,
struct V_3 * * * V_61 ,
struct V_3 * * V_62 )
{
struct V_3 * * V_63 ;
struct V_3 * V_64 = NULL ;
struct V_65 * V_9 ;
if ( V_61 && V_62 ) {
V_63 = * V_61 ;
V_64 = * V_62 ;
goto V_66;
}
V_63 = V_58 ? & V_58 : & V_57 -> V_3 ;
while ( * V_63 ) {
V_64 = * V_63 ;
V_9 = F_43 ( V_64 , struct V_65 , V_3 ) ;
if ( V_59 < V_9 -> V_15 )
V_63 = & ( * V_63 ) -> V_67 ;
else if ( V_59 > V_9 -> V_16 )
V_63 = & ( * V_63 ) -> V_68 ;
else
return V_64 ;
}
V_66:
F_44 ( V_60 , V_64 , V_63 ) ;
F_45 ( V_60 , V_57 ) ;
return NULL ;
}
static struct V_3 * F_46 ( struct V_23 * V_24 , T_1 V_59 ,
struct V_3 * * V_69 ,
struct V_3 * * V_70 ,
struct V_3 * * * V_71 ,
struct V_3 * * V_72 )
{
struct V_56 * V_57 = & V_24 -> V_2 ;
struct V_3 * * V_73 = & V_57 -> V_3 ;
struct V_3 * V_74 = NULL ;
struct V_3 * V_75 = NULL ;
struct V_65 * V_9 ;
struct V_65 * V_76 = NULL ;
while ( * V_73 ) {
V_74 = * V_73 ;
V_9 = F_43 ( V_74 , struct V_65 , V_3 ) ;
V_76 = V_9 ;
if ( V_59 < V_9 -> V_15 )
V_73 = & ( * V_73 ) -> V_67 ;
else if ( V_59 > V_9 -> V_16 )
V_73 = & ( * V_73 ) -> V_68 ;
else
return * V_73 ;
}
if ( V_71 )
* V_71 = V_73 ;
if ( V_72 )
* V_72 = V_74 ;
if ( V_69 ) {
V_75 = V_74 ;
while ( V_74 && V_59 > V_76 -> V_16 ) {
V_74 = F_47 ( V_74 ) ;
V_76 = F_43 ( V_74 , struct V_65 , V_3 ) ;
}
* V_69 = V_74 ;
V_74 = V_75 ;
}
if ( V_70 ) {
V_76 = F_43 ( V_74 , struct V_65 , V_3 ) ;
while ( V_74 && V_59 < V_76 -> V_15 ) {
V_74 = F_48 ( V_74 ) ;
V_76 = F_43 ( V_74 , struct V_65 , V_3 ) ;
}
* V_70 = V_74 ;
}
return NULL ;
}
static inline struct V_3 *
F_49 ( struct V_23 * V_24 ,
T_1 V_59 ,
struct V_3 * * * V_71 ,
struct V_3 * * V_72 )
{
struct V_3 * V_74 = NULL ;
struct V_3 * V_32 ;
V_32 = F_46 ( V_24 , V_59 , & V_74 , NULL , V_71 , V_72 ) ;
if ( ! V_32 )
return V_74 ;
return V_32 ;
}
static inline struct V_3 * F_50 ( struct V_23 * V_24 ,
T_1 V_59 )
{
return F_49 ( V_24 , V_59 , NULL , NULL ) ;
}
static void F_51 ( struct V_23 * V_24 , struct V_1 * V_5 ,
struct V_1 * V_77 )
{
if ( V_24 -> V_25 && V_24 -> V_25 -> V_78 )
V_24 -> V_25 -> V_78 ( V_24 -> V_27 , V_5 , V_77 ) ;
}
static void F_52 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_1 * V_77 ;
struct V_3 * V_79 ;
if ( V_2 -> V_2 & ( V_80 | V_81 ) )
return;
V_79 = F_48 ( & V_2 -> V_3 ) ;
if ( V_79 ) {
V_77 = F_43 ( V_79 , struct V_1 , V_3 ) ;
if ( V_77 -> V_16 == V_2 -> V_15 - 1 &&
V_77 -> V_2 == V_2 -> V_2 ) {
F_51 ( V_24 , V_2 , V_77 ) ;
V_2 -> V_15 = V_77 -> V_15 ;
F_53 ( & V_77 -> V_3 , & V_24 -> V_2 ) ;
F_34 ( & V_77 -> V_3 ) ;
F_38 ( V_77 ) ;
}
}
V_79 = F_47 ( & V_2 -> V_3 ) ;
if ( V_79 ) {
V_77 = F_43 ( V_79 , struct V_1 , V_3 ) ;
if ( V_77 -> V_15 == V_2 -> V_16 + 1 &&
V_77 -> V_2 == V_2 -> V_2 ) {
F_51 ( V_24 , V_2 , V_77 ) ;
V_2 -> V_16 = V_77 -> V_16 ;
F_53 ( & V_77 -> V_3 , & V_24 -> V_2 ) ;
F_34 ( & V_77 -> V_3 ) ;
F_38 ( V_77 ) ;
}
}
}
static void F_54 ( struct V_23 * V_24 ,
struct V_1 * V_2 , unsigned * V_28 )
{
if ( V_24 -> V_25 && V_24 -> V_25 -> V_82 )
V_24 -> V_25 -> V_82 ( V_24 -> V_27 , V_2 , V_28 ) ;
}
static void F_55 ( struct V_23 * V_24 ,
struct V_1 * V_2 , unsigned * V_28 )
{
if ( V_24 -> V_25 && V_24 -> V_25 -> V_83 )
V_24 -> V_25 -> V_83 ( V_24 -> V_27 , V_2 , V_28 ) ;
}
static int F_56 ( struct V_23 * V_24 ,
struct V_1 * V_2 , T_1 V_15 , T_1 V_16 ,
struct V_3 * * * V_63 ,
struct V_3 * * V_64 ,
unsigned * V_28 , struct V_29 * V_30 )
{
struct V_3 * V_60 ;
if ( V_16 < V_15 )
F_57 ( 1 , V_84 L_5 ,
V_16 , V_15 ) ;
V_2 -> V_15 = V_15 ;
V_2 -> V_16 = V_16 ;
F_58 ( V_24 , V_2 , V_28 , V_30 ) ;
V_60 = F_42 ( & V_24 -> V_2 , NULL , V_16 , & V_2 -> V_3 , V_63 , V_64 ) ;
if ( V_60 ) {
struct V_1 * V_85 ;
V_85 = F_43 ( V_60 , struct V_1 , V_3 ) ;
F_12 ( L_6 ,
V_85 -> V_15 , V_85 -> V_16 , V_15 , V_16 ) ;
return - V_86 ;
}
F_52 ( V_24 , V_2 ) ;
return 0 ;
}
static void F_59 ( struct V_23 * V_24 , struct V_1 * V_87 ,
T_1 V_88 )
{
if ( V_24 -> V_25 && V_24 -> V_25 -> V_89 )
V_24 -> V_25 -> V_89 ( V_24 -> V_27 , V_87 , V_88 ) ;
}
static int F_60 ( struct V_23 * V_24 , struct V_1 * V_87 ,
struct V_1 * V_90 , T_1 V_88 )
{
struct V_3 * V_60 ;
F_59 ( V_24 , V_87 , V_88 ) ;
V_90 -> V_15 = V_87 -> V_15 ;
V_90 -> V_16 = V_88 - 1 ;
V_90 -> V_2 = V_87 -> V_2 ;
V_87 -> V_15 = V_88 ;
V_60 = F_42 ( & V_24 -> V_2 , & V_87 -> V_3 , V_90 -> V_16 ,
& V_90 -> V_3 , NULL , NULL ) ;
if ( V_60 ) {
F_38 ( V_90 ) ;
return - V_86 ;
}
return 0 ;
}
static struct V_1 * F_61 ( struct V_1 * V_2 )
{
struct V_3 * V_13 = F_47 ( & V_2 -> V_3 ) ;
if ( V_13 )
return F_43 ( V_13 , struct V_1 , V_3 ) ;
else
return NULL ;
}
static struct V_1 * F_62 ( struct V_23 * V_24 ,
struct V_1 * V_2 ,
unsigned * V_28 , int V_91 ,
struct V_29 * V_30 )
{
struct V_1 * V_13 ;
unsigned V_92 = * V_28 & ~ V_93 ;
if ( ( V_92 & V_94 ) && ( V_2 -> V_2 & V_94 ) ) {
T_1 V_95 = V_2 -> V_16 - V_2 -> V_15 + 1 ;
F_40 ( V_95 > V_24 -> V_48 ) ;
V_24 -> V_48 -= V_95 ;
}
F_55 ( V_24 , V_2 , V_28 ) ;
F_17 ( V_2 , V_92 , V_30 , 0 ) ;
V_2 -> V_2 &= ~ V_92 ;
if ( V_91 )
F_63 ( & V_2 -> V_54 ) ;
if ( V_2 -> V_2 == 0 ) {
V_13 = F_61 ( V_2 ) ;
if ( F_1 ( V_2 ) ) {
F_53 ( & V_2 -> V_3 , & V_24 -> V_2 ) ;
F_34 ( & V_2 -> V_3 ) ;
F_38 ( V_2 ) ;
} else {
F_40 ( 1 ) ;
}
} else {
F_52 ( V_24 , V_2 ) ;
V_13 = F_61 ( V_2 ) ;
}
return V_13 ;
}
static struct V_1 *
F_64 ( struct V_1 * V_90 )
{
if ( ! V_90 )
V_90 = F_32 ( V_35 ) ;
return V_90 ;
}
static void F_65 ( struct V_23 * V_24 , int V_96 )
{
F_66 ( F_20 ( V_24 ) , V_96 ,
L_7 ) ;
}
static int F_67 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned V_28 , int V_91 , int V_97 ,
struct V_1 * * V_98 ,
T_3 V_50 , struct V_29 * V_30 )
{
struct V_1 * V_2 ;
struct V_1 * V_99 ;
struct V_1 * V_90 = NULL ;
struct V_3 * V_60 ;
T_1 V_100 ;
int V_96 ;
int V_101 = 0 ;
F_68 ( V_24 , V_15 , V_16 ) ;
if ( V_28 & V_102 )
V_28 |= V_103 ;
if ( V_97 )
V_28 |= ~ V_93 ;
V_28 |= V_104 ;
if ( V_28 & ( V_80 | V_81 ) )
V_101 = 1 ;
V_105:
if ( ! V_90 && F_69 ( V_50 ) ) {
V_90 = F_32 ( V_50 ) ;
}
F_70 ( & V_24 -> V_49 ) ;
if ( V_98 ) {
V_99 = * V_98 ;
if ( V_101 ) {
* V_98 = NULL ;
V_98 = NULL ;
}
if ( V_99 && F_1 ( V_99 ) &&
V_99 -> V_15 <= V_15 && V_99 -> V_16 > V_15 ) {
if ( V_101 )
F_71 ( & V_99 -> V_17 ) ;
V_2 = V_99 ;
goto V_106;
}
if ( V_101 )
F_38 ( V_99 ) ;
}
V_60 = F_50 ( V_24 , V_15 ) ;
if ( ! V_60 )
goto V_107;
V_2 = F_43 ( V_60 , struct V_1 , V_3 ) ;
V_106:
if ( V_2 -> V_15 > V_16 )
goto V_107;
F_40 ( V_2 -> V_16 < V_15 ) ;
V_100 = V_2 -> V_16 ;
if ( ! ( V_2 -> V_2 & V_28 ) ) {
V_2 = F_61 ( V_2 ) ;
goto V_13;
}
if ( V_2 -> V_15 < V_15 ) {
V_90 = F_64 ( V_90 ) ;
F_19 ( ! V_90 ) ;
V_96 = F_60 ( V_24 , V_2 , V_90 , V_15 ) ;
if ( V_96 )
F_65 ( V_24 , V_96 ) ;
V_90 = NULL ;
if ( V_96 )
goto V_107;
if ( V_2 -> V_16 <= V_16 ) {
V_2 = F_62 ( V_24 , V_2 , & V_28 , V_91 ,
V_30 ) ;
goto V_13;
}
goto V_108;
}
if ( V_2 -> V_15 <= V_16 && V_2 -> V_16 > V_16 ) {
V_90 = F_64 ( V_90 ) ;
F_19 ( ! V_90 ) ;
V_96 = F_60 ( V_24 , V_2 , V_90 , V_16 + 1 ) ;
if ( V_96 )
F_65 ( V_24 , V_96 ) ;
if ( V_91 )
F_63 ( & V_2 -> V_54 ) ;
F_62 ( V_24 , V_90 , & V_28 , V_91 , V_30 ) ;
V_90 = NULL ;
goto V_107;
}
V_2 = F_62 ( V_24 , V_2 , & V_28 , V_91 , V_30 ) ;
V_13:
if ( V_100 == ( T_1 ) - 1 )
goto V_107;
V_15 = V_100 + 1 ;
if ( V_15 <= V_16 && V_2 && ! F_72 () )
goto V_106;
V_108:
if ( V_15 > V_16 )
goto V_107;
F_73 ( & V_24 -> V_49 ) ;
if ( F_69 ( V_50 ) )
F_74 () ;
goto V_105;
V_107:
F_73 ( & V_24 -> V_49 ) ;
if ( V_90 )
F_38 ( V_90 ) ;
return 0 ;
}
static void F_75 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
__releases( V_24 -> V_49 )
__acquires( V_24 -> V_49 )
{
F_76 ( V_109 ) ;
F_77 ( & V_2 -> V_54 , & V_109 , V_110 ) ;
F_73 ( & V_24 -> V_49 ) ;
F_78 () ;
F_70 ( & V_24 -> V_49 ) ;
F_79 ( & V_2 -> V_54 , & V_109 ) ;
}
static void F_80 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned long V_28 )
{
struct V_1 * V_2 ;
struct V_3 * V_60 ;
F_68 ( V_24 , V_15 , V_16 ) ;
F_70 ( & V_24 -> V_49 ) ;
V_105:
while ( 1 ) {
V_60 = F_50 ( V_24 , V_15 ) ;
V_111:
if ( ! V_60 )
break;
V_2 = F_43 ( V_60 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 > V_16 )
goto V_107;
if ( V_2 -> V_2 & V_28 ) {
V_15 = V_2 -> V_15 ;
F_81 ( & V_2 -> V_17 ) ;
F_75 ( V_24 , V_2 ) ;
F_38 ( V_2 ) ;
goto V_105;
}
V_15 = V_2 -> V_16 + 1 ;
if ( V_15 > V_16 )
break;
if ( ! F_82 ( & V_24 -> V_49 ) ) {
V_60 = F_47 ( V_60 ) ;
goto V_111;
}
}
V_107:
F_73 ( & V_24 -> V_49 ) ;
}
static void F_58 ( struct V_23 * V_24 ,
struct V_1 * V_2 ,
unsigned * V_28 , struct V_29 * V_30 )
{
unsigned V_112 = * V_28 & ~ V_93 ;
F_54 ( V_24 , V_2 , V_28 ) ;
if ( ( V_112 & V_94 ) && ! ( V_2 -> V_2 & V_94 ) ) {
T_1 V_95 = V_2 -> V_16 - V_2 -> V_15 + 1 ;
V_24 -> V_48 += V_95 ;
}
F_17 ( V_2 , V_112 , V_30 , 1 ) ;
V_2 -> V_2 |= V_112 ;
}
static void F_83 ( struct V_1 * V_2 ,
struct V_1 * * V_113 ,
unsigned V_7 )
{
if ( V_113 && ! ( * V_113 ) ) {
if ( ! V_7 || ( V_2 -> V_2 & V_7 ) ) {
* V_113 = V_2 ;
F_81 ( & V_2 -> V_17 ) ;
}
}
}
static void F_84 ( struct V_1 * V_2 ,
struct V_1 * * V_113 )
{
return F_83 ( V_2 , V_113 ,
V_80 | V_81 ) ;
}
static int T_4
F_85 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned V_28 , unsigned V_114 ,
T_1 * V_115 , struct V_1 * * V_98 ,
T_3 V_50 , struct V_29 * V_30 )
{
struct V_1 * V_2 ;
struct V_1 * V_90 = NULL ;
struct V_3 * V_60 ;
struct V_3 * * V_63 ;
struct V_3 * V_64 ;
int V_96 = 0 ;
T_1 V_116 ;
T_1 V_100 ;
F_68 ( V_24 , V_15 , V_16 ) ;
V_28 |= V_104 ;
V_105:
if ( ! V_90 && F_69 ( V_50 ) ) {
V_90 = F_32 ( V_50 ) ;
}
F_70 ( & V_24 -> V_49 ) ;
if ( V_98 && * V_98 ) {
V_2 = * V_98 ;
if ( V_2 -> V_15 <= V_15 && V_2 -> V_16 > V_15 &&
F_1 ( V_2 ) ) {
V_60 = & V_2 -> V_3 ;
goto V_106;
}
}
V_60 = F_49 ( V_24 , V_15 , & V_63 , & V_64 ) ;
if ( ! V_60 ) {
V_90 = F_64 ( V_90 ) ;
F_19 ( ! V_90 ) ;
V_96 = F_56 ( V_24 , V_90 , V_15 , V_16 ,
& V_63 , & V_64 , & V_28 , V_30 ) ;
if ( V_96 )
F_65 ( V_24 , V_96 ) ;
F_84 ( V_90 , V_98 ) ;
V_90 = NULL ;
goto V_107;
}
V_2 = F_43 ( V_60 , struct V_1 , V_3 ) ;
V_106:
V_116 = V_2 -> V_15 ;
V_100 = V_2 -> V_16 ;
if ( V_2 -> V_15 == V_15 && V_2 -> V_16 <= V_16 ) {
if ( V_2 -> V_2 & V_114 ) {
* V_115 = V_2 -> V_15 ;
V_96 = - V_86 ;
goto V_107;
}
F_58 ( V_24 , V_2 , & V_28 , V_30 ) ;
F_84 ( V_2 , V_98 ) ;
F_52 ( V_24 , V_2 ) ;
if ( V_100 == ( T_1 ) - 1 )
goto V_107;
V_15 = V_100 + 1 ;
V_2 = F_61 ( V_2 ) ;
if ( V_15 < V_16 && V_2 && V_2 -> V_15 == V_15 &&
! F_72 () )
goto V_106;
goto V_108;
}
if ( V_2 -> V_15 < V_15 ) {
if ( V_2 -> V_2 & V_114 ) {
* V_115 = V_15 ;
V_96 = - V_86 ;
goto V_107;
}
V_90 = F_64 ( V_90 ) ;
F_19 ( ! V_90 ) ;
V_96 = F_60 ( V_24 , V_2 , V_90 , V_15 ) ;
if ( V_96 )
F_65 ( V_24 , V_96 ) ;
V_90 = NULL ;
if ( V_96 )
goto V_107;
if ( V_2 -> V_16 <= V_16 ) {
F_58 ( V_24 , V_2 , & V_28 , V_30 ) ;
F_84 ( V_2 , V_98 ) ;
F_52 ( V_24 , V_2 ) ;
if ( V_100 == ( T_1 ) - 1 )
goto V_107;
V_15 = V_100 + 1 ;
V_2 = F_61 ( V_2 ) ;
if ( V_15 < V_16 && V_2 && V_2 -> V_15 == V_15 &&
! F_72 () )
goto V_106;
}
goto V_108;
}
if ( V_2 -> V_15 > V_15 ) {
T_1 V_117 ;
if ( V_16 < V_116 )
V_117 = V_16 ;
else
V_117 = V_116 - 1 ;
V_90 = F_64 ( V_90 ) ;
F_19 ( ! V_90 ) ;
V_96 = F_56 ( V_24 , V_90 , V_15 , V_117 ,
NULL , NULL , & V_28 , V_30 ) ;
if ( V_96 )
F_65 ( V_24 , V_96 ) ;
F_84 ( V_90 , V_98 ) ;
V_90 = NULL ;
V_15 = V_117 + 1 ;
goto V_108;
}
if ( V_2 -> V_15 <= V_16 && V_2 -> V_16 > V_16 ) {
if ( V_2 -> V_2 & V_114 ) {
* V_115 = V_15 ;
V_96 = - V_86 ;
goto V_107;
}
V_90 = F_64 ( V_90 ) ;
F_19 ( ! V_90 ) ;
V_96 = F_60 ( V_24 , V_2 , V_90 , V_16 + 1 ) ;
if ( V_96 )
F_65 ( V_24 , V_96 ) ;
F_58 ( V_24 , V_90 , & V_28 , V_30 ) ;
F_84 ( V_90 , V_98 ) ;
F_52 ( V_24 , V_90 ) ;
V_90 = NULL ;
goto V_107;
}
V_108:
if ( V_15 > V_16 )
goto V_107;
F_73 ( & V_24 -> V_49 ) ;
if ( F_69 ( V_50 ) )
F_74 () ;
goto V_105;
V_107:
F_73 ( & V_24 -> V_49 ) ;
if ( V_90 )
F_38 ( V_90 ) ;
return V_96 ;
}
int F_86 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned V_28 , T_1 * V_115 ,
struct V_1 * * V_98 , T_3 V_50 )
{
return F_85 ( V_24 , V_15 , V_16 , V_28 , 0 , V_115 ,
V_98 , V_50 , NULL ) ;
}
int F_87 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned V_28 , unsigned V_118 ,
struct V_1 * * V_98 )
{
struct V_1 * V_2 ;
struct V_1 * V_90 = NULL ;
struct V_3 * V_60 ;
struct V_3 * * V_63 ;
struct V_3 * V_64 ;
int V_96 = 0 ;
T_1 V_116 ;
T_1 V_100 ;
bool V_119 = true ;
F_68 ( V_24 , V_15 , V_16 ) ;
V_105:
if ( ! V_90 ) {
V_90 = F_32 ( V_120 ) ;
if ( ! V_90 && ! V_119 )
return - V_38 ;
}
F_70 ( & V_24 -> V_49 ) ;
if ( V_98 && * V_98 ) {
V_2 = * V_98 ;
if ( V_2 -> V_15 <= V_15 && V_2 -> V_16 > V_15 &&
F_1 ( V_2 ) ) {
V_60 = & V_2 -> V_3 ;
goto V_106;
}
}
V_60 = F_49 ( V_24 , V_15 , & V_63 , & V_64 ) ;
if ( ! V_60 ) {
V_90 = F_64 ( V_90 ) ;
if ( ! V_90 ) {
V_96 = - V_38 ;
goto V_107;
}
V_96 = F_56 ( V_24 , V_90 , V_15 , V_16 ,
& V_63 , & V_64 , & V_28 , NULL ) ;
if ( V_96 )
F_65 ( V_24 , V_96 ) ;
F_84 ( V_90 , V_98 ) ;
V_90 = NULL ;
goto V_107;
}
V_2 = F_43 ( V_60 , struct V_1 , V_3 ) ;
V_106:
V_116 = V_2 -> V_15 ;
V_100 = V_2 -> V_16 ;
if ( V_2 -> V_15 == V_15 && V_2 -> V_16 <= V_16 ) {
F_58 ( V_24 , V_2 , & V_28 , NULL ) ;
F_84 ( V_2 , V_98 ) ;
V_2 = F_62 ( V_24 , V_2 , & V_118 , 0 , NULL ) ;
if ( V_100 == ( T_1 ) - 1 )
goto V_107;
V_15 = V_100 + 1 ;
if ( V_15 < V_16 && V_2 && V_2 -> V_15 == V_15 &&
! F_72 () )
goto V_106;
goto V_108;
}
if ( V_2 -> V_15 < V_15 ) {
V_90 = F_64 ( V_90 ) ;
if ( ! V_90 ) {
V_96 = - V_38 ;
goto V_107;
}
V_96 = F_60 ( V_24 , V_2 , V_90 , V_15 ) ;
if ( V_96 )
F_65 ( V_24 , V_96 ) ;
V_90 = NULL ;
if ( V_96 )
goto V_107;
if ( V_2 -> V_16 <= V_16 ) {
F_58 ( V_24 , V_2 , & V_28 , NULL ) ;
F_84 ( V_2 , V_98 ) ;
V_2 = F_62 ( V_24 , V_2 , & V_118 , 0 ,
NULL ) ;
if ( V_100 == ( T_1 ) - 1 )
goto V_107;
V_15 = V_100 + 1 ;
if ( V_15 < V_16 && V_2 && V_2 -> V_15 == V_15 &&
! F_72 () )
goto V_106;
}
goto V_108;
}
if ( V_2 -> V_15 > V_15 ) {
T_1 V_117 ;
if ( V_16 < V_116 )
V_117 = V_16 ;
else
V_117 = V_116 - 1 ;
V_90 = F_64 ( V_90 ) ;
if ( ! V_90 ) {
V_96 = - V_38 ;
goto V_107;
}
V_96 = F_56 ( V_24 , V_90 , V_15 , V_117 ,
NULL , NULL , & V_28 , NULL ) ;
if ( V_96 )
F_65 ( V_24 , V_96 ) ;
F_84 ( V_90 , V_98 ) ;
V_90 = NULL ;
V_15 = V_117 + 1 ;
goto V_108;
}
if ( V_2 -> V_15 <= V_16 && V_2 -> V_16 > V_16 ) {
V_90 = F_64 ( V_90 ) ;
if ( ! V_90 ) {
V_96 = - V_38 ;
goto V_107;
}
V_96 = F_60 ( V_24 , V_2 , V_90 , V_16 + 1 ) ;
if ( V_96 )
F_65 ( V_24 , V_96 ) ;
F_58 ( V_24 , V_90 , & V_28 , NULL ) ;
F_84 ( V_90 , V_98 ) ;
F_62 ( V_24 , V_90 , & V_118 , 0 , NULL ) ;
V_90 = NULL ;
goto V_107;
}
V_108:
if ( V_15 > V_16 )
goto V_107;
F_73 ( & V_24 -> V_49 ) ;
F_74 () ;
V_119 = false ;
goto V_105;
V_107:
F_73 ( & V_24 -> V_49 ) ;
if ( V_90 )
F_38 ( V_90 ) ;
return V_96 ;
}
int F_88 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned V_28 , struct V_29 * V_30 )
{
F_19 ( V_28 & V_121 ) ;
return F_85 ( V_24 , V_15 , V_16 , V_28 , 0 , NULL , NULL , V_120 ,
V_30 ) ;
}
int F_89 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned V_28 , int V_91 , int V_97 ,
struct V_1 * * V_99 , T_3 V_50 )
{
return F_67 ( V_24 , V_15 , V_16 , V_28 , V_91 , V_97 ,
V_99 , V_50 , NULL ) ;
}
int F_90 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned V_28 , struct V_29 * V_30 )
{
F_19 ( V_28 & V_121 ) ;
return F_67 ( V_24 , V_15 , V_16 , V_28 , 0 , 0 , NULL , V_120 ,
V_30 ) ;
}
int F_91 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
struct V_1 * * V_98 )
{
int V_96 ;
T_1 V_115 ;
while ( 1 ) {
V_96 = F_85 ( V_24 , V_15 , V_16 , V_121 ,
V_121 , & V_115 ,
V_98 , V_120 , NULL ) ;
if ( V_96 == - V_86 ) {
F_80 ( V_24 , V_115 , V_16 , V_121 ) ;
V_15 = V_115 ;
} else
break;
F_40 ( V_15 > V_16 ) ;
}
return V_96 ;
}
int F_92 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 )
{
int V_96 ;
T_1 V_115 ;
V_96 = F_85 ( V_24 , V_15 , V_16 , V_121 , V_121 ,
& V_115 , NULL , V_120 , NULL ) ;
if ( V_96 == - V_86 ) {
if ( V_115 > V_15 )
F_89 ( V_24 , V_15 , V_115 - 1 ,
V_121 , 1 , 0 , NULL , V_120 ) ;
return 0 ;
}
return 1 ;
}
void F_93 ( struct V_122 * V_122 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_123 = V_15 >> V_124 ;
unsigned long V_125 = V_16 >> V_124 ;
struct V_126 * V_126 ;
while ( V_123 <= V_125 ) {
V_126 = F_94 ( V_122 -> V_127 , V_123 ) ;
F_19 ( ! V_126 ) ;
F_95 ( V_126 ) ;
F_96 ( V_126 ) ;
V_123 ++ ;
}
}
void F_97 ( struct V_122 * V_122 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_123 = V_15 >> V_124 ;
unsigned long V_125 = V_16 >> V_124 ;
struct V_126 * V_126 ;
while ( V_123 <= V_125 ) {
V_126 = F_94 ( V_122 -> V_127 , V_123 ) ;
F_19 ( ! V_126 ) ;
F_98 ( V_126 ) ;
F_99 ( V_126 ) ;
F_96 ( V_126 ) ;
V_123 ++ ;
}
}
static void F_100 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 )
{
V_24 -> V_25 -> F_100 ( V_24 -> V_27 , V_15 , V_16 ) ;
}
static struct V_1 *
F_101 ( struct V_23 * V_24 ,
T_1 V_15 , unsigned V_28 )
{
struct V_3 * V_60 ;
struct V_1 * V_2 ;
V_60 = F_50 ( V_24 , V_15 ) ;
if ( ! V_60 )
goto V_107;
while ( 1 ) {
V_2 = F_43 ( V_60 , struct V_1 , V_3 ) ;
if ( V_2 -> V_16 >= V_15 && ( V_2 -> V_2 & V_28 ) )
return V_2 ;
V_60 = F_47 ( V_60 ) ;
if ( ! V_60 )
break;
}
V_107:
return NULL ;
}
int F_102 ( struct V_23 * V_24 , T_1 V_15 ,
T_1 * V_128 , T_1 * V_129 , unsigned V_28 ,
struct V_1 * * V_98 )
{
struct V_1 * V_2 ;
struct V_3 * V_73 ;
int V_32 = 1 ;
F_70 ( & V_24 -> V_49 ) ;
if ( V_98 && * V_98 ) {
V_2 = * V_98 ;
if ( V_2 -> V_16 == V_15 - 1 && F_1 ( V_2 ) ) {
V_73 = F_47 ( & V_2 -> V_3 ) ;
while ( V_73 ) {
V_2 = F_43 ( V_73 , struct V_1 ,
V_3 ) ;
if ( V_2 -> V_2 & V_28 )
goto V_130;
V_73 = F_47 ( V_73 ) ;
}
F_38 ( * V_98 ) ;
* V_98 = NULL ;
goto V_107;
}
F_38 ( * V_98 ) ;
* V_98 = NULL ;
}
V_2 = F_101 ( V_24 , V_15 , V_28 ) ;
V_130:
if ( V_2 ) {
F_83 ( V_2 , V_98 , 0 ) ;
* V_128 = V_2 -> V_15 ;
* V_129 = V_2 -> V_16 ;
V_32 = 0 ;
}
V_107:
F_73 ( & V_24 -> V_49 ) ;
return V_32 ;
}
static T_5 T_1 F_103 ( struct V_23 * V_24 ,
T_1 * V_15 , T_1 * V_16 , T_1 V_131 ,
struct V_1 * * V_98 )
{
struct V_3 * V_60 ;
struct V_1 * V_2 ;
T_1 V_132 = * V_15 ;
T_1 V_85 = 0 ;
T_1 V_133 = 0 ;
F_70 ( & V_24 -> V_49 ) ;
V_60 = F_50 ( V_24 , V_132 ) ;
if ( ! V_60 ) {
if ( ! V_85 )
* V_16 = ( T_1 ) - 1 ;
goto V_107;
}
while ( 1 ) {
V_2 = F_43 ( V_60 , struct V_1 , V_3 ) ;
if ( V_85 && ( V_2 -> V_15 != V_132 ||
( V_2 -> V_2 & V_81 ) ) ) {
goto V_107;
}
if ( ! ( V_2 -> V_2 & V_102 ) ) {
if ( ! V_85 )
* V_16 = V_2 -> V_16 ;
goto V_107;
}
if ( ! V_85 ) {
* V_15 = V_2 -> V_15 ;
* V_98 = V_2 ;
F_81 ( & V_2 -> V_17 ) ;
}
V_85 ++ ;
* V_16 = V_2 -> V_16 ;
V_132 = V_2 -> V_16 + 1 ;
V_60 = F_47 ( V_60 ) ;
V_133 += V_2 -> V_16 - V_2 -> V_15 + 1 ;
if ( V_133 >= V_131 )
break;
if ( ! V_60 )
break;
}
V_107:
F_73 ( & V_24 -> V_49 ) ;
return V_85 ;
}
static T_5 void F_104 ( struct V_122 * V_122 ,
struct V_126 * V_134 ,
T_1 V_15 , T_1 V_16 )
{
unsigned long V_123 = V_15 >> V_124 ;
unsigned long V_125 = V_16 >> V_124 ;
ASSERT ( V_134 ) ;
if ( V_123 == V_134 -> V_123 && V_125 == V_123 )
return;
F_105 ( V_122 -> V_127 , V_134 , V_123 , V_125 ,
V_135 , NULL ) ;
}
static T_5 int F_106 ( struct V_122 * V_122 ,
struct V_126 * V_134 ,
T_1 V_136 ,
T_1 V_137 )
{
unsigned long V_123 = V_136 >> V_124 ;
unsigned long V_138 = V_123 ;
unsigned long V_125 = V_137 >> V_124 ;
int V_32 ;
ASSERT ( V_134 ) ;
if ( V_123 == V_134 -> V_123 && V_123 == V_125 )
return 0 ;
V_32 = F_105 ( V_122 -> V_127 , V_134 , V_123 ,
V_125 , V_139 , & V_138 ) ;
if ( V_32 == - V_140 )
F_104 ( V_122 , V_134 , V_136 ,
( T_1 ) V_138 << V_124 ) ;
return V_32 ;
}
STATIC T_1 F_107 ( struct V_122 * V_122 ,
struct V_23 * V_24 ,
struct V_126 * V_134 , T_1 * V_15 ,
T_1 * V_16 , T_1 V_131 )
{
T_1 V_136 ;
T_1 V_137 ;
T_1 V_85 ;
struct V_1 * V_98 = NULL ;
int V_32 ;
int V_141 = 0 ;
V_105:
V_136 = * V_15 ;
V_137 = 0 ;
V_85 = F_103 ( V_24 , & V_136 , & V_137 ,
V_131 , & V_98 ) ;
if ( ! V_85 || V_137 <= * V_15 ) {
* V_15 = V_136 ;
* V_16 = V_137 ;
F_38 ( V_98 ) ;
return 0 ;
}
if ( V_136 < * V_15 )
V_136 = * V_15 ;
if ( V_137 + 1 - V_136 > V_131 )
V_137 = V_136 + V_131 - 1 ;
V_32 = F_106 ( V_122 , V_134 ,
V_136 , V_137 ) ;
if ( V_32 == - V_140 ) {
F_38 ( V_98 ) ;
V_98 = NULL ;
if ( ! V_141 ) {
V_131 = V_142 ;
V_141 = 1 ;
goto V_105;
} else {
V_85 = 0 ;
goto V_143;
}
}
F_19 ( V_32 ) ;
F_91 ( V_24 , V_136 , V_137 , & V_98 ) ;
V_32 = F_108 ( V_24 , V_136 , V_137 ,
V_102 , 1 , V_98 ) ;
if ( ! V_32 ) {
F_109 ( V_24 , V_136 , V_137 ,
& V_98 , V_120 ) ;
F_104 ( V_122 , V_134 ,
V_136 , V_137 ) ;
F_74 () ;
goto V_105;
}
F_38 ( V_98 ) ;
* V_15 = V_136 ;
* V_16 = V_137 ;
V_143:
return V_85 ;
}
static int F_105 ( struct V_144 * V_145 ,
struct V_126 * V_134 ,
T_6 V_146 , T_6 V_125 ,
unsigned long V_147 , T_6 * V_138 )
{
unsigned long V_148 = V_125 - V_146 + 1 ;
unsigned long V_149 = 0 ;
T_6 V_123 = V_146 ;
struct V_126 * V_150 [ 16 ] ;
unsigned V_32 ;
int V_96 = 0 ;
int V_151 ;
if ( V_147 & V_139 ) {
ASSERT ( V_147 == V_139 ) ;
ASSERT ( V_138 && * V_138 == V_146 ) ;
}
if ( ( V_147 & V_152 ) && V_148 > 0 )
F_110 ( V_145 , - V_153 ) ;
while ( V_148 > 0 ) {
V_32 = F_111 ( V_145 , V_123 ,
F_112 (unsigned long,
nr_pages, ARRAY_SIZE(pages)) , V_150 ) ;
if ( V_32 == 0 ) {
ASSERT ( V_147 & V_139 ) ;
V_96 = - V_140 ;
goto V_107;
}
for ( V_151 = 0 ; V_151 < V_32 ; V_151 ++ ) {
if ( V_147 & V_154 )
F_113 ( V_150 [ V_151 ] ) ;
if ( V_150 [ V_151 ] == V_134 ) {
F_96 ( V_150 [ V_151 ] ) ;
V_149 ++ ;
continue;
}
if ( V_147 & V_155 )
F_95 ( V_150 [ V_151 ] ) ;
if ( V_147 & V_156 )
F_114 ( V_150 [ V_151 ] ) ;
if ( V_147 & V_152 )
F_115 ( V_150 [ V_151 ] ) ;
if ( V_147 & V_157 )
F_116 ( V_150 [ V_151 ] ) ;
if ( V_147 & V_135 )
F_117 ( V_150 [ V_151 ] ) ;
if ( V_147 & V_139 ) {
F_118 ( V_150 [ V_151 ] ) ;
if ( ! F_119 ( V_150 [ V_151 ] ) ||
V_150 [ V_151 ] -> V_145 != V_145 ) {
F_117 ( V_150 [ V_151 ] ) ;
F_96 ( V_150 [ V_151 ] ) ;
V_96 = - V_140 ;
goto V_107;
}
}
F_96 ( V_150 [ V_151 ] ) ;
V_149 ++ ;
}
V_148 -= V_32 ;
V_123 += V_32 ;
F_74 () ;
}
V_107:
if ( V_96 && V_138 )
* V_138 = V_146 + V_149 - 1 ;
return V_96 ;
}
void F_120 ( struct V_122 * V_122 , T_1 V_15 , T_1 V_16 ,
T_1 V_137 , struct V_126 * V_134 ,
unsigned V_118 ,
unsigned long V_147 )
{
F_89 ( & F_121 ( V_122 ) -> V_158 , V_15 , V_16 , V_118 , 1 , 0 ,
NULL , V_120 ) ;
F_105 ( V_122 -> V_127 , V_134 ,
V_15 >> V_124 , V_16 >> V_124 ,
V_147 , NULL ) ;
}
T_1 F_122 ( struct V_23 * V_24 ,
T_1 * V_15 , T_1 V_159 , T_1 V_131 ,
unsigned V_28 , int V_160 )
{
struct V_3 * V_60 ;
struct V_1 * V_2 ;
T_1 V_132 = * V_15 ;
T_1 V_133 = 0 ;
T_1 V_161 = 0 ;
int V_85 = 0 ;
if ( F_40 ( V_159 <= V_132 ) )
return 0 ;
F_70 ( & V_24 -> V_49 ) ;
if ( V_132 == 0 && V_28 == V_94 ) {
V_133 = V_24 -> V_48 ;
goto V_107;
}
V_60 = F_50 ( V_24 , V_132 ) ;
if ( ! V_60 )
goto V_107;
while ( 1 ) {
V_2 = F_43 ( V_60 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 > V_159 )
break;
if ( V_160 && V_85 && V_2 -> V_15 > V_161 + 1 )
break;
if ( V_2 -> V_16 >= V_132 && ( V_2 -> V_2 & V_28 ) == V_28 ) {
V_133 += F_123 ( V_159 , V_2 -> V_16 ) + 1 -
F_124 ( V_132 , V_2 -> V_15 ) ;
if ( V_133 >= V_131 )
break;
if ( ! V_85 ) {
* V_15 = F_124 ( V_132 , V_2 -> V_15 ) ;
V_85 = 1 ;
}
V_161 = V_2 -> V_16 ;
} else if ( V_160 && V_85 ) {
break;
}
V_60 = F_47 ( V_60 ) ;
if ( ! V_60 )
break;
}
V_107:
F_73 ( & V_24 -> V_49 ) ;
return V_133 ;
}
static T_5 int F_125 ( struct V_23 * V_24 , T_1 V_15 ,
struct V_162 * V_53 )
{
struct V_3 * V_60 ;
struct V_1 * V_2 ;
int V_32 = 0 ;
F_70 ( & V_24 -> V_49 ) ;
V_60 = F_50 ( V_24 , V_15 ) ;
if ( ! V_60 ) {
V_32 = - V_163 ;
goto V_107;
}
V_2 = F_43 ( V_60 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 != V_15 ) {
V_32 = - V_163 ;
goto V_107;
}
V_2 -> V_53 = V_53 ;
V_107:
F_73 ( & V_24 -> V_49 ) ;
return V_32 ;
}
static T_5 int F_126 ( struct V_23 * V_24 , T_1 V_15 ,
struct V_162 * * V_53 )
{
struct V_3 * V_60 ;
struct V_1 * V_2 ;
int V_32 = 0 ;
F_70 ( & V_24 -> V_49 ) ;
V_60 = F_50 ( V_24 , V_15 ) ;
if ( ! V_60 ) {
V_32 = - V_163 ;
goto V_107;
}
V_2 = F_43 ( V_60 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 != V_15 ) {
V_32 = - V_163 ;
goto V_107;
}
* V_53 = V_2 -> V_53 ;
V_107:
F_73 ( & V_24 -> V_49 ) ;
return V_32 ;
}
int F_108 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_16 ,
unsigned V_28 , int V_164 , struct V_1 * V_99 )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_60 ;
int V_165 = 0 ;
F_70 ( & V_24 -> V_49 ) ;
if ( V_99 && F_1 ( V_99 ) && V_99 -> V_15 <= V_15 &&
V_99 -> V_16 > V_15 )
V_60 = & V_99 -> V_3 ;
else
V_60 = F_50 ( V_24 , V_15 ) ;
while ( V_60 && V_15 <= V_16 ) {
V_2 = F_43 ( V_60 , struct V_1 , V_3 ) ;
if ( V_164 && V_2 -> V_15 > V_15 ) {
V_165 = 0 ;
break;
}
if ( V_2 -> V_15 > V_16 )
break;
if ( V_2 -> V_2 & V_28 ) {
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
V_60 = F_47 ( V_60 ) ;
if ( ! V_60 ) {
if ( V_164 )
V_165 = 0 ;
break;
}
}
F_73 ( & V_24 -> V_49 ) ;
return V_165 ;
}
static void F_127 ( struct V_23 * V_24 , struct V_126 * V_126 )
{
T_1 V_15 = F_128 ( V_126 ) ;
T_1 V_16 = V_15 + V_142 - 1 ;
if ( F_108 ( V_24 , V_15 , V_16 , V_166 , 1 , NULL ) )
F_129 ( V_126 ) ;
}
int F_130 ( struct V_23 * V_167 ,
struct V_23 * V_158 ,
struct V_162 * V_168 )
{
int V_32 ;
int V_96 = 0 ;
F_125 ( V_167 , V_168 -> V_15 , NULL ) ;
V_32 = F_131 ( V_167 , V_168 -> V_15 ,
V_168 -> V_15 + V_168 -> V_20 - 1 ,
V_121 | V_94 ) ;
if ( V_32 )
V_96 = V_32 ;
V_32 = F_131 ( V_158 , V_168 -> V_15 ,
V_168 -> V_15 + V_168 -> V_20 - 1 ,
V_169 ) ;
if ( V_32 && ! V_96 )
V_96 = V_32 ;
F_132 ( V_168 ) ;
return V_96 ;
}
int F_133 ( struct V_36 * V_170 , T_1 V_171 , T_1 V_15 ,
T_1 V_172 , T_1 V_173 , struct V_126 * V_126 ,
unsigned int V_174 , int V_175 )
{
struct V_43 * V_43 ;
struct V_176 * V_177 ;
T_1 V_178 = 0 ;
T_1 V_179 ;
struct V_180 * V_181 = NULL ;
int V_32 ;
ASSERT ( ! ( V_170 -> V_182 -> V_183 & V_184 ) ) ;
F_19 ( ! V_175 ) ;
V_43 = F_134 ( 1 ) ;
V_43 -> V_185 . V_186 = 0 ;
V_178 = V_172 ;
F_135 ( V_170 ) ;
if ( F_136 ( V_170 , V_173 , V_172 , V_175 ) ) {
V_32 = F_137 ( V_170 , V_187 , V_173 ,
& V_178 , & V_181 , 0 ) ;
if ( V_32 ) {
F_138 ( V_170 ) ;
F_139 ( V_43 ) ;
return - V_153 ;
}
ASSERT ( V_181 -> V_175 == 1 ) ;
} else {
V_32 = F_137 ( V_170 , V_188 , V_173 ,
& V_178 , & V_181 , V_175 ) ;
if ( V_32 ) {
F_138 ( V_170 ) ;
F_139 ( V_43 ) ;
return - V_153 ;
}
F_19 ( V_175 != V_181 -> V_175 ) ;
}
V_179 = V_181 -> V_189 [ V_181 -> V_175 - 1 ] . V_190 >> 9 ;
V_43 -> V_185 . V_191 = V_179 ;
V_177 = V_181 -> V_189 [ V_181 -> V_175 - 1 ] . V_177 ;
F_140 ( V_181 ) ;
if ( ! V_177 || ! V_177 -> V_192 || ! V_177 -> V_193 ) {
F_138 ( V_170 ) ;
F_139 ( V_43 ) ;
return - V_153 ;
}
V_43 -> V_194 = V_177 -> V_192 ;
V_43 -> V_195 = V_196 | V_197 ;
F_141 ( V_43 , V_126 , V_172 , V_174 ) ;
if ( F_142 ( V_43 ) ) {
F_138 ( V_170 ) ;
F_139 ( V_43 ) ;
F_143 ( V_177 , V_198 ) ;
return - V_153 ;
}
F_144 ( V_170 ,
L_8 ,
V_171 , V_15 ,
F_145 ( V_177 -> V_199 ) , V_179 ) ;
F_138 ( V_170 ) ;
F_139 ( V_43 ) ;
return 0 ;
}
int F_146 ( struct V_36 * V_170 ,
struct V_10 * V_11 , int V_175 )
{
T_1 V_15 = V_11 -> V_15 ;
unsigned long V_151 , V_200 = F_147 ( V_11 -> V_15 , V_11 -> V_20 ) ;
int V_32 = 0 ;
if ( V_170 -> V_182 -> V_183 & V_184 )
return - V_201 ;
for ( V_151 = 0 ; V_151 < V_200 ; V_151 ++ ) {
struct V_126 * V_63 = V_11 -> V_150 [ V_151 ] ;
V_32 = F_133 ( V_170 , 0 , V_15 , V_142 , V_15 , V_63 ,
V_15 - F_128 ( V_63 ) , V_175 ) ;
if ( V_32 )
break;
V_15 += V_142 ;
}
return V_32 ;
}
int F_148 ( struct V_36 * V_170 ,
struct V_23 * V_167 ,
struct V_23 * V_158 , T_1 V_15 ,
struct V_126 * V_126 , T_1 V_171 , unsigned int V_174 )
{
T_1 V_202 ;
struct V_162 * V_53 ;
struct V_1 * V_2 ;
int V_203 ;
int V_32 ;
V_202 = 0 ;
V_32 = F_122 ( V_167 , & V_202 , ( T_1 ) - 1 , 1 ,
V_94 , 0 ) ;
if ( ! V_32 )
return 0 ;
V_32 = F_126 ( V_167 , V_15 , & V_53 ) ;
if ( V_32 )
return 0 ;
F_19 ( ! V_53 -> V_204 ) ;
if ( V_53 -> V_205 ) {
F_149 ( V_170 ,
L_9 ,
V_53 -> V_15 ) ;
goto V_107;
}
if ( V_170 -> V_182 -> V_183 & V_184 )
goto V_107;
F_70 ( & V_158 -> V_49 ) ;
V_2 = F_101 ( V_158 ,
V_53 -> V_15 ,
V_121 ) ;
F_73 ( & V_158 -> V_49 ) ;
if ( V_2 && V_2 -> V_15 <= V_53 -> V_15 &&
V_2 -> V_16 >= V_53 -> V_15 + V_53 -> V_20 - 1 ) {
V_203 = F_150 ( V_170 , V_53 -> V_173 ,
V_53 -> V_20 ) ;
if ( V_203 > 1 ) {
F_133 ( V_170 , V_171 , V_15 , V_53 -> V_20 ,
V_53 -> V_173 , V_126 , V_174 ,
V_53 -> V_206 ) ;
}
}
V_107:
F_130 ( V_167 , V_158 , V_53 ) ;
return 0 ;
}
void F_151 ( struct V_207 * V_122 , T_1 V_15 , T_1 V_16 )
{
struct V_23 * V_167 = & V_122 -> V_208 ;
struct V_162 * V_53 ;
struct V_1 * V_2 , * V_13 ;
if ( F_152 ( & V_167 -> V_2 ) )
return;
F_70 ( & V_167 -> V_49 ) ;
V_2 = F_101 ( V_167 , V_15 , V_94 ) ;
while ( V_2 ) {
if ( V_2 -> V_15 > V_16 )
break;
ASSERT ( V_2 -> V_16 <= V_16 ) ;
V_13 = F_61 ( V_2 ) ;
V_53 = V_2 -> V_53 ;
F_38 ( V_2 ) ;
F_132 ( V_53 ) ;
V_2 = V_13 ;
}
F_73 ( & V_167 -> V_49 ) ;
}
int F_153 ( struct V_122 * V_122 , T_1 V_15 , T_1 V_16 ,
struct V_162 * * V_209 )
{
struct V_36 * V_170 = F_154 ( V_122 -> V_210 ) ;
struct V_162 * V_53 ;
struct V_211 * V_212 ;
struct V_23 * V_167 = & F_121 ( V_122 ) -> V_208 ;
struct V_23 * V_24 = & F_121 ( V_122 ) -> V_158 ;
struct V_213 * V_214 = & F_121 ( V_122 ) -> V_215 ;
int V_32 ;
T_1 V_173 ;
V_32 = F_126 ( V_167 , V_15 , & V_53 ) ;
if ( V_32 ) {
V_53 = F_155 ( sizeof( * V_53 ) , V_120 ) ;
if ( ! V_53 )
return - V_38 ;
V_53 -> V_15 = V_15 ;
V_53 -> V_20 = V_16 - V_15 + 1 ;
V_53 -> V_204 = 0 ;
V_53 -> V_216 = 0 ;
V_53 -> V_205 = 0 ;
F_156 ( & V_214 -> V_49 ) ;
V_212 = F_157 ( V_214 , V_15 , V_53 -> V_20 ) ;
if ( ! V_212 ) {
F_158 ( & V_214 -> V_49 ) ;
F_132 ( V_53 ) ;
return - V_153 ;
}
if ( V_212 -> V_15 > V_15 || V_212 -> V_15 + V_212 -> V_20 <= V_15 ) {
F_159 ( V_212 ) ;
V_212 = NULL ;
}
F_158 ( & V_214 -> V_49 ) ;
if ( ! V_212 ) {
F_132 ( V_53 ) ;
return - V_153 ;
}
V_173 = V_15 - V_212 -> V_15 ;
V_173 = V_212 -> V_217 + V_173 ;
if ( F_160 ( V_218 , & V_212 -> V_7 ) ) {
V_173 = V_212 -> V_217 ;
V_53 -> V_216 = V_219 ;
F_161 ( & V_53 -> V_216 ,
V_212 -> V_220 ) ;
}
F_149 ( V_170 ,
L_10 ,
V_173 , V_15 , V_53 -> V_20 ) ;
V_53 -> V_173 = V_173 ;
F_159 ( V_212 ) ;
V_32 = F_162 ( V_167 , V_15 , V_16 ,
V_121 | V_94 ) ;
if ( V_32 >= 0 )
V_32 = F_125 ( V_167 , V_15 , V_53 ) ;
if ( V_32 >= 0 )
V_32 = F_162 ( V_24 , V_15 , V_16 , V_169 ) ;
if ( V_32 < 0 ) {
F_132 ( V_53 ) ;
return V_32 ;
}
} else {
F_149 ( V_170 ,
L_11 ,
V_53 -> V_173 , V_53 -> V_15 , V_53 -> V_20 ,
V_53 -> V_205 ) ;
}
* V_209 = V_53 ;
return 0 ;
}
bool F_163 ( struct V_122 * V_122 , struct V_43 * V_221 ,
struct V_162 * V_53 , int V_206 )
{
struct V_36 * V_170 = F_154 ( V_122 -> V_210 ) ;
int V_203 ;
V_203 = F_150 ( V_170 , V_53 -> V_173 , V_53 -> V_20 ) ;
if ( V_203 == 1 ) {
F_149 ( V_170 ,
L_12 ,
V_203 , V_53 -> V_204 , V_206 ) ;
return false ;
}
if ( V_221 -> V_222 > 1 ) {
F_19 ( V_53 -> V_205 ) ;
V_53 -> V_205 = 1 ;
V_53 -> V_204 = V_206 ;
} else {
if ( V_53 -> V_205 ) {
F_19 ( V_53 -> V_204 != V_206 ) ;
V_53 -> V_205 = 0 ;
V_53 -> V_204 = 0 ;
}
V_53 -> V_206 = V_206 ;
V_53 -> V_204 ++ ;
if ( V_53 -> V_204 == V_206 )
V_53 -> V_204 ++ ;
}
if ( V_53 -> V_204 > V_203 ) {
F_149 ( V_170 ,
L_13 ,
V_203 , V_53 -> V_204 , V_206 ) ;
return false ;
}
return true ;
}
struct V_43 * F_164 ( struct V_122 * V_122 , struct V_43 * V_221 ,
struct V_162 * V_53 ,
struct V_126 * V_126 , int V_174 , int V_223 ,
T_7 * V_224 , void * V_225 )
{
struct V_36 * V_170 = F_154 ( V_122 -> V_210 ) ;
struct V_43 * V_43 ;
struct V_42 * V_226 ;
struct V_42 * V_180 ;
V_43 = F_134 ( 1 ) ;
V_43 -> V_227 = V_224 ;
V_43 -> V_185 . V_191 = V_53 -> V_173 >> 9 ;
V_43 -> V_194 = V_170 -> V_228 -> V_229 ;
V_43 -> V_185 . V_186 = 0 ;
V_43 -> V_230 = V_225 ;
V_226 = V_42 ( V_221 ) ;
if ( V_226 -> V_231 ) {
T_8 V_232 = F_165 ( V_170 -> V_233 ) ;
V_180 = V_42 ( V_43 ) ;
V_180 -> V_231 = V_180 -> V_234 ;
V_223 *= V_232 ;
memcpy ( V_180 -> V_231 , V_226 -> V_231 + V_223 ,
V_232 ) ;
}
F_141 ( V_43 , V_126 , V_53 -> V_20 , V_174 ) ;
return V_43 ;
}
static int F_166 ( struct V_43 * V_221 , T_1 V_235 ,
struct V_126 * V_126 , T_1 V_15 , T_1 V_16 ,
int V_206 )
{
struct V_162 * V_53 ;
struct V_122 * V_122 = V_126 -> V_145 -> V_236 ;
struct V_23 * V_24 = & F_121 ( V_122 ) -> V_158 ;
struct V_23 * V_167 = & F_121 ( V_122 ) -> V_208 ;
struct V_43 * V_43 ;
int V_237 = 0 ;
T_9 V_238 ;
int V_32 ;
F_19 ( F_167 ( V_221 ) == V_196 ) ;
V_32 = F_153 ( V_122 , V_15 , V_16 , & V_53 ) ;
if ( V_32 )
return V_32 ;
if ( ! F_163 ( V_122 , V_221 , V_53 ,
V_206 ) ) {
F_130 ( V_167 , V_24 , V_53 ) ;
return - V_153 ;
}
if ( V_221 -> V_222 > 1 )
V_237 |= V_239 ;
V_235 >>= V_122 -> V_210 -> V_240 ;
V_43 = F_164 ( V_122 , V_221 , V_53 , V_126 ,
V_15 - F_128 ( V_126 ) ,
( int ) V_235 , V_221 -> V_227 ,
NULL ) ;
F_168 ( V_43 , V_241 , V_237 ) ;
F_149 ( F_154 ( V_122 -> V_210 ) ,
L_14 ,
V_237 , V_53 -> V_204 , V_53 -> V_205 ) ;
V_238 = V_24 -> V_25 -> V_242 ( V_24 -> V_27 , V_43 , V_53 -> V_204 ,
V_53 -> V_216 , 0 ) ;
if ( V_238 ) {
F_130 ( V_167 , V_24 , V_53 ) ;
F_139 ( V_43 ) ;
V_32 = F_169 ( V_238 ) ;
}
return V_32 ;
}
void F_170 ( struct V_126 * V_126 , int V_96 , T_1 V_15 , T_1 V_16 )
{
int V_243 = ( V_96 == 0 ) ;
struct V_23 * V_24 ;
int V_32 = 0 ;
V_24 = & F_121 ( V_126 -> V_145 -> V_236 ) -> V_158 ;
if ( V_24 -> V_25 && V_24 -> V_25 -> V_244 )
V_24 -> V_25 -> V_244 ( V_126 , V_15 , V_16 , NULL ,
V_243 ) ;
if ( ! V_243 ) {
F_171 ( V_126 ) ;
F_115 ( V_126 ) ;
V_32 = V_96 < 0 ? V_96 : - V_153 ;
F_110 ( V_126 -> V_145 , V_32 ) ;
}
}
static void F_172 ( struct V_43 * V_43 )
{
int error = F_169 ( V_43 -> V_245 ) ;
struct V_246 * V_247 ;
T_1 V_15 ;
T_1 V_16 ;
int V_151 ;
ASSERT ( ! F_173 ( V_43 , V_248 ) ) ;
F_174 (bvec, bio, i) {
struct V_126 * V_126 = V_247 -> V_249 ;
struct V_122 * V_122 = V_126 -> V_145 -> V_236 ;
struct V_36 * V_170 = F_154 ( V_122 -> V_210 ) ;
if ( V_247 -> V_250 || V_247 -> V_251 != V_142 ) {
if ( V_247 -> V_250 + V_247 -> V_251 != V_142 )
F_175 ( V_170 ,
L_15 ,
V_247 -> V_250 , V_247 -> V_251 ) ;
else
F_176 ( V_170 ,
L_16 ,
V_247 -> V_250 , V_247 -> V_251 ) ;
}
V_15 = F_128 ( V_126 ) ;
V_16 = V_15 + V_247 -> V_250 + V_247 -> V_251 - 1 ;
F_170 ( V_126 , error , V_15 , V_16 ) ;
F_116 ( V_126 ) ;
}
F_139 ( V_43 ) ;
}
static void
F_177 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_20 ,
int V_243 )
{
struct V_1 * V_99 = NULL ;
T_1 V_16 = V_15 + V_20 - 1 ;
if ( V_243 && V_24 -> V_252 )
F_178 ( V_24 , V_15 , V_16 , & V_99 , V_35 ) ;
F_109 ( V_24 , V_15 , V_16 , & V_99 , V_35 ) ;
}
static void F_179 ( struct V_43 * V_43 )
{
struct V_246 * V_247 ;
int V_243 = ! V_43 -> V_245 ;
struct V_42 * V_253 = V_42 ( V_43 ) ;
struct V_23 * V_24 , * V_167 ;
T_1 V_59 = 0 ;
T_1 V_15 ;
T_1 V_16 ;
T_1 V_20 ;
T_1 V_254 = 0 ;
T_1 V_255 = 0 ;
int V_256 ;
int V_32 ;
int V_151 ;
ASSERT ( ! F_173 ( V_43 , V_248 ) ) ;
F_174 (bvec, bio, i) {
struct V_126 * V_126 = V_247 -> V_249 ;
struct V_122 * V_122 = V_126 -> V_145 -> V_236 ;
struct V_36 * V_170 = F_154 ( V_122 -> V_210 ) ;
F_149 ( V_170 ,
L_17 ,
( T_1 ) V_43 -> V_185 . V_191 , V_43 -> V_245 ,
V_253 -> V_175 ) ;
V_24 = & F_121 ( V_122 ) -> V_158 ;
V_167 = & F_121 ( V_122 ) -> V_208 ;
if ( V_247 -> V_250 || V_247 -> V_251 != V_142 ) {
if ( V_247 -> V_250 + V_247 -> V_251 != V_142 )
F_175 ( V_170 ,
L_18 ,
V_247 -> V_250 , V_247 -> V_251 ) ;
else
F_176 ( V_170 ,
L_19 ,
V_247 -> V_250 , V_247 -> V_251 ) ;
}
V_15 = F_128 ( V_126 ) ;
V_16 = V_15 + V_247 -> V_250 + V_247 -> V_251 - 1 ;
V_20 = V_247 -> V_251 ;
V_256 = V_253 -> V_175 ;
if ( F_180 ( V_243 && V_24 -> V_25 ) ) {
V_32 = V_24 -> V_25 -> V_257 ( V_253 , V_59 ,
V_126 , V_15 , V_16 ,
V_256 ) ;
if ( V_32 )
V_243 = 0 ;
else
F_148 ( F_121 ( V_122 ) -> V_57 -> V_170 ,
V_167 , V_24 , V_15 ,
V_126 ,
F_181 ( F_121 ( V_122 ) ) , 0 ) ;
}
if ( F_180 ( V_243 ) )
goto V_258;
if ( V_24 -> V_25 ) {
V_32 = V_24 -> V_25 -> V_259 ( V_126 , V_256 ) ;
if ( V_32 == - V_140 ) {
V_32 = F_166 ( V_43 , V_59 , V_126 ,
V_15 , V_16 , V_256 ) ;
if ( V_32 == 0 ) {
V_243 = ! V_43 -> V_245 ;
V_59 += V_20 ;
continue;
}
}
ASSERT ( V_32 == - V_153 ) ;
}
V_258:
if ( F_180 ( V_243 ) ) {
T_10 V_260 = F_182 ( V_122 ) ;
T_6 V_125 = V_260 >> V_124 ;
unsigned V_261 ;
V_261 = V_260 & ( V_142 - 1 ) ;
if ( V_126 -> V_123 == V_125 && V_261 )
F_183 ( V_126 , V_261 , V_142 ) ;
F_129 ( V_126 ) ;
} else {
F_171 ( V_126 ) ;
F_115 ( V_126 ) ;
}
F_117 ( V_126 ) ;
V_59 += V_20 ;
if ( F_184 ( ! V_243 ) ) {
if ( V_255 ) {
F_177 ( V_24 ,
V_254 ,
V_255 , 1 ) ;
V_254 = 0 ;
V_255 = 0 ;
}
F_177 ( V_24 , V_15 ,
V_16 - V_15 + 1 , 0 ) ;
} else if ( ! V_255 ) {
V_254 = V_15 ;
V_255 = V_16 + 1 - V_15 ;
} else if ( V_254 + V_255 == V_15 ) {
V_255 += V_16 + 1 - V_15 ;
} else {
F_177 ( V_24 , V_254 ,
V_255 , V_243 ) ;
V_254 = V_15 ;
V_255 = V_16 + 1 - V_15 ;
}
}
if ( V_255 )
F_177 ( V_24 , V_254 , V_255 ,
V_243 ) ;
if ( V_253 -> V_262 )
V_253 -> V_262 ( V_253 , F_169 ( V_43 -> V_245 ) ) ;
F_139 ( V_43 ) ;
}
static inline void F_185 ( struct V_42 * V_180 )
{
memset ( V_180 , 0 , F_24 ( struct V_42 , V_43 ) ) ;
}
struct V_43 * F_186 ( struct V_263 * V_192 , T_1 V_264 )
{
struct V_43 * V_43 ;
V_43 = F_187 ( V_120 , V_265 , V_40 ) ;
V_43 -> V_194 = V_192 ;
V_43 -> V_185 . V_191 = V_264 >> 9 ;
F_185 ( V_42 ( V_43 ) ) ;
return V_43 ;
}
struct V_43 * F_188 ( struct V_43 * V_43 )
{
struct V_42 * V_180 ;
struct V_43 * V_5 ;
V_5 = F_189 ( V_43 , V_120 , V_40 ) ;
V_180 = V_42 ( V_5 ) ;
F_185 ( V_180 ) ;
V_180 -> V_266 = V_43 -> V_185 ;
return V_5 ;
}
struct V_43 * F_134 ( unsigned int V_267 )
{
struct V_43 * V_43 ;
V_43 = F_187 ( V_120 , V_267 , V_40 ) ;
F_185 ( V_42 ( V_43 ) ) ;
return V_43 ;
}
struct V_43 * F_190 ( struct V_43 * V_87 , int V_59 , int V_268 )
{
struct V_43 * V_43 ;
struct V_42 * V_180 ;
V_43 = F_189 ( V_87 , V_120 , V_40 ) ;
ASSERT ( V_43 ) ;
V_180 = V_42 ( V_43 ) ;
F_185 ( V_180 ) ;
F_191 ( V_43 , V_59 >> 9 , V_268 >> 9 ) ;
V_180 -> V_266 = V_43 -> V_185 ;
return V_43 ;
}
static int T_4 F_192 ( struct V_43 * V_43 , int V_175 ,
unsigned long V_216 )
{
T_9 V_32 = 0 ;
struct V_246 * V_247 = V_43 -> V_269 + V_43 -> V_222 - 1 ;
struct V_126 * V_126 = V_247 -> V_249 ;
struct V_23 * V_24 = V_43 -> V_230 ;
T_1 V_15 ;
V_15 = F_128 ( V_126 ) + V_247 -> V_250 ;
V_43 -> V_230 = NULL ;
F_193 ( V_43 ) ;
if ( V_24 -> V_25 )
V_32 = V_24 -> V_25 -> V_242 ( V_24 -> V_27 , V_43 ,
V_175 , V_216 , V_15 ) ;
else
F_194 ( V_43 ) ;
F_139 ( V_43 ) ;
return F_169 ( V_32 ) ;
}
static int F_195 ( struct V_23 * V_24 , struct V_126 * V_126 ,
unsigned long V_59 , T_11 V_268 , struct V_43 * V_43 ,
unsigned long V_216 )
{
int V_32 = 0 ;
if ( V_24 -> V_25 )
V_32 = V_24 -> V_25 -> V_270 ( V_126 , V_59 , V_268 , V_43 ,
V_216 ) ;
return V_32 ;
}
static int F_196 ( int V_271 , int V_272 , struct V_23 * V_24 ,
struct V_273 * V_274 ,
struct V_126 * V_126 , T_12 V_179 ,
T_11 V_268 , unsigned long V_59 ,
struct V_263 * V_192 ,
struct V_43 * * V_275 ,
T_7 V_276 ,
int V_175 ,
unsigned long V_277 ,
unsigned long V_216 ,
bool V_278 )
{
int V_32 = 0 ;
struct V_43 * V_43 ;
int V_160 = 0 ;
int V_279 = V_277 & V_219 ;
T_11 V_280 = F_112 ( T_11 , V_268 , V_142 ) ;
if ( V_275 && * V_275 ) {
V_43 = * V_275 ;
if ( V_279 )
V_160 = V_43 -> V_185 . V_191 == V_179 ;
else
V_160 = F_197 ( V_43 ) == V_179 ;
if ( V_277 != V_216 || ! V_160 ||
V_278 ||
F_195 ( V_24 , V_126 , V_59 , V_280 , V_43 , V_216 ) ||
F_141 ( V_43 , V_126 , V_280 , V_59 ) < V_280 ) {
V_32 = F_192 ( V_43 , V_175 , V_277 ) ;
if ( V_32 < 0 ) {
* V_275 = NULL ;
return V_32 ;
}
V_43 = NULL ;
} else {
if ( V_274 )
F_198 ( V_274 , V_126 , V_280 ) ;
return 0 ;
}
}
V_43 = F_186 ( V_192 , V_179 << 9 ) ;
F_141 ( V_43 , V_126 , V_280 , V_59 ) ;
V_43 -> V_227 = V_276 ;
V_43 -> V_230 = V_24 ;
V_43 -> V_281 = V_126 -> V_145 -> V_236 -> V_282 ;
F_168 ( V_43 , V_271 , V_272 ) ;
if ( V_274 ) {
F_199 ( V_274 , V_43 ) ;
F_198 ( V_274 , V_126 , V_280 ) ;
}
if ( V_275 )
* V_275 = V_43 ;
else
V_32 = F_192 ( V_43 , V_175 , V_216 ) ;
return V_32 ;
}
static void F_200 ( struct V_10 * V_11 ,
struct V_126 * V_126 )
{
if ( ! F_201 ( V_126 ) ) {
F_202 ( V_126 ) ;
F_203 ( V_126 ) ;
F_204 ( V_126 , ( unsigned long ) V_11 ) ;
} else {
F_40 ( V_126 -> V_202 != ( unsigned long ) V_11 ) ;
}
}
void F_205 ( struct V_126 * V_126 )
{
if ( ! F_201 ( V_126 ) ) {
F_202 ( V_126 ) ;
F_203 ( V_126 ) ;
F_204 ( V_126 , V_283 ) ;
}
}
static struct V_211 *
F_206 ( struct V_122 * V_122 , struct V_126 * V_126 , T_11 V_174 ,
T_1 V_15 , T_1 V_20 , T_13 * V_284 ,
struct V_211 * * V_285 )
{
struct V_211 * V_212 ;
if ( V_285 && * V_285 ) {
V_212 = * V_285 ;
if ( F_207 ( V_212 ) && V_15 >= V_212 -> V_15 &&
V_15 < F_208 ( V_212 ) ) {
F_81 ( & V_212 -> V_17 ) ;
return V_212 ;
}
F_159 ( V_212 ) ;
* V_285 = NULL ;
}
V_212 = V_284 ( F_121 ( V_122 ) , V_126 , V_174 , V_15 , V_20 , 0 ) ;
if ( V_285 && ! F_209 ( V_212 ) ) {
F_19 ( * V_285 ) ;
F_81 ( & V_212 -> V_17 ) ;
* V_285 = V_212 ;
}
return V_212 ;
}
static int F_210 ( struct V_23 * V_24 ,
struct V_126 * V_126 ,
T_13 * V_284 ,
struct V_211 * * V_285 ,
struct V_43 * * V_43 , int V_175 ,
unsigned long * V_216 , int V_286 ,
T_1 * V_287 )
{
struct V_122 * V_122 = V_126 -> V_145 -> V_236 ;
T_1 V_15 = F_128 ( V_126 ) ;
T_1 V_288 = V_15 + V_142 - 1 ;
T_1 V_16 ;
T_1 V_289 = V_15 ;
T_1 V_290 ;
T_1 V_291 = F_182 ( V_122 ) ;
T_1 V_217 ;
T_1 V_292 ;
T_12 V_179 ;
struct V_211 * V_212 ;
struct V_263 * V_192 ;
int V_32 = 0 ;
int V_293 = 0 ;
T_11 V_174 = 0 ;
T_11 V_294 ;
T_11 V_295 ;
T_11 V_296 = V_122 -> V_210 -> V_297 ;
unsigned long V_298 = 0 ;
F_205 ( V_126 ) ;
V_16 = V_288 ;
if ( ! F_211 ( V_126 ) ) {
if ( F_212 ( V_126 ) == 0 ) {
F_19 ( V_296 != V_142 ) ;
F_213 ( V_24 , V_15 , V_16 ) ;
goto V_107;
}
}
if ( V_126 -> V_123 == V_291 >> V_124 ) {
char * V_299 ;
T_11 V_300 = V_291 & ( V_142 - 1 ) ;
if ( V_300 ) {
V_294 = V_142 - V_300 ;
V_299 = F_214 ( V_126 ) ;
memset ( V_299 + V_300 , 0 , V_294 ) ;
F_215 ( V_126 ) ;
F_216 ( V_299 ) ;
}
}
while ( V_289 <= V_16 ) {
bool V_278 = false ;
if ( V_289 >= V_291 ) {
char * V_299 ;
struct V_1 * V_99 = NULL ;
V_294 = V_142 - V_174 ;
V_299 = F_214 ( V_126 ) ;
memset ( V_299 + V_174 , 0 , V_294 ) ;
F_215 ( V_126 ) ;
F_216 ( V_299 ) ;
F_178 ( V_24 , V_289 , V_289 + V_294 - 1 ,
& V_99 , V_120 ) ;
F_109 ( V_24 , V_289 ,
V_289 + V_294 - 1 ,
& V_99 , V_120 ) ;
break;
}
V_212 = F_206 ( V_122 , V_126 , V_174 , V_289 ,
V_16 - V_289 + 1 , V_284 , V_285 ) ;
if ( F_209 ( V_212 ) ) {
F_115 ( V_126 ) ;
F_213 ( V_24 , V_289 , V_16 ) ;
break;
}
V_290 = V_289 - V_212 -> V_15 ;
F_19 ( F_208 ( V_212 ) <= V_289 ) ;
F_19 ( V_16 < V_289 ) ;
if ( F_160 ( V_218 , & V_212 -> V_7 ) ) {
V_298 |= V_219 ;
F_161 ( & V_298 ,
V_212 -> V_220 ) ;
}
V_294 = F_123 ( F_208 ( V_212 ) - V_289 , V_16 - V_289 + 1 ) ;
V_292 = F_123 ( F_208 ( V_212 ) - 1 , V_16 ) ;
V_294 = F_217 ( V_294 , V_296 ) ;
if ( V_298 & V_219 ) {
V_295 = V_212 -> V_301 ;
V_179 = V_212 -> V_217 >> 9 ;
} else {
V_179 = ( V_212 -> V_217 + V_290 ) >> 9 ;
V_295 = V_294 ;
}
V_192 = V_212 -> V_192 ;
V_217 = V_212 -> V_217 ;
if ( F_160 ( V_302 , & V_212 -> V_7 ) )
V_217 = V_303 ;
if ( F_160 ( V_218 , & V_212 -> V_7 ) &&
V_287 && * V_287 != ( T_1 ) - 1 &&
* V_287 != V_212 -> V_304 )
V_278 = true ;
if ( V_287 )
* V_287 = V_212 -> V_304 ;
F_159 ( V_212 ) ;
V_212 = NULL ;
if ( V_217 == V_303 ) {
char * V_299 ;
struct V_1 * V_99 = NULL ;
V_299 = F_214 ( V_126 ) ;
memset ( V_299 + V_174 , 0 , V_294 ) ;
F_215 ( V_126 ) ;
F_216 ( V_299 ) ;
F_178 ( V_24 , V_289 , V_289 + V_294 - 1 ,
& V_99 , V_120 ) ;
F_109 ( V_24 , V_289 ,
V_289 + V_294 - 1 ,
& V_99 , V_120 ) ;
V_289 = V_289 + V_294 ;
V_174 += V_294 ;
continue;
}
if ( F_108 ( V_24 , V_289 , V_292 ,
V_166 , 1 , NULL ) ) {
F_127 ( V_24 , V_126 ) ;
F_213 ( V_24 , V_289 , V_289 + V_294 - 1 ) ;
V_289 = V_289 + V_294 ;
V_174 += V_294 ;
continue;
}
if ( V_217 == V_305 ) {
F_115 ( V_126 ) ;
F_213 ( V_24 , V_289 , V_289 + V_294 - 1 ) ;
V_289 = V_289 + V_294 ;
V_174 += V_294 ;
continue;
}
V_32 = F_196 ( V_241 , V_286 , V_24 , NULL ,
V_126 , V_179 , V_295 , V_174 ,
V_192 , V_43 ,
F_179 , V_175 ,
* V_216 ,
V_298 ,
V_278 ) ;
if ( ! V_32 ) {
V_293 ++ ;
* V_216 = V_298 ;
} else {
F_115 ( V_126 ) ;
F_213 ( V_24 , V_289 , V_289 + V_294 - 1 ) ;
goto V_107;
}
V_289 = V_289 + V_294 ;
V_174 += V_294 ;
}
V_107:
if ( ! V_293 ) {
if ( ! F_218 ( V_126 ) )
F_129 ( V_126 ) ;
F_117 ( V_126 ) ;
}
return V_32 ;
}
static inline void F_219 ( struct V_23 * V_24 ,
struct V_126 * V_150 [] , int V_148 ,
T_1 V_15 , T_1 V_16 ,
T_13 * V_284 ,
struct V_211 * * V_285 ,
struct V_43 * * V_43 , int V_175 ,
unsigned long * V_216 ,
T_1 * V_287 )
{
struct V_122 * V_122 ;
struct V_306 * V_307 ;
int V_123 ;
V_122 = V_150 [ 0 ] -> V_145 -> V_236 ;
while ( 1 ) {
F_220 ( V_24 , V_15 , V_16 ) ;
V_307 = F_221 ( F_121 ( V_122 ) , V_15 ,
V_16 - V_15 + 1 ) ;
if ( ! V_307 )
break;
F_213 ( V_24 , V_15 , V_16 ) ;
F_222 ( V_122 , V_307 , 1 ) ;
F_223 ( V_307 ) ;
}
for ( V_123 = 0 ; V_123 < V_148 ; V_123 ++ ) {
F_210 ( V_24 , V_150 [ V_123 ] , V_284 , V_285 , V_43 ,
V_175 , V_216 , 0 , V_287 ) ;
F_96 ( V_150 [ V_123 ] ) ;
}
}
static void F_224 ( struct V_23 * V_24 ,
struct V_126 * V_150 [] ,
int V_148 , T_13 * V_284 ,
struct V_211 * * V_285 ,
struct V_43 * * V_43 , int V_175 ,
unsigned long * V_216 ,
T_1 * V_287 )
{
T_1 V_15 = 0 ;
T_1 V_16 = 0 ;
T_1 V_308 ;
int V_123 ;
int V_309 = 0 ;
for ( V_123 = 0 ; V_123 < V_148 ; V_123 ++ ) {
V_308 = F_128 ( V_150 [ V_123 ] ) ;
if ( ! V_16 ) {
V_15 = V_308 ;
V_16 = V_15 + V_142 - 1 ;
V_309 = V_123 ;
} else if ( V_16 + 1 == V_308 ) {
V_16 += V_142 ;
} else {
F_219 ( V_24 , & V_150 [ V_309 ] ,
V_123 - V_309 , V_15 ,
V_16 , V_284 , V_285 ,
V_43 , V_175 , V_216 ,
V_287 ) ;
V_15 = V_308 ;
V_16 = V_15 + V_142 - 1 ;
V_309 = V_123 ;
}
}
if ( V_16 )
F_219 ( V_24 , & V_150 [ V_309 ] ,
V_123 - V_309 , V_15 ,
V_16 , V_284 , V_285 , V_43 ,
V_175 , V_216 ,
V_287 ) ;
}
static int F_225 ( struct V_23 * V_24 ,
struct V_126 * V_126 ,
T_13 * V_284 ,
struct V_43 * * V_43 , int V_175 ,
unsigned long * V_216 , int V_286 )
{
struct V_122 * V_122 = V_126 -> V_145 -> V_236 ;
struct V_306 * V_307 ;
T_1 V_15 = F_128 ( V_126 ) ;
T_1 V_16 = V_15 + V_142 - 1 ;
int V_32 ;
while ( 1 ) {
F_220 ( V_24 , V_15 , V_16 ) ;
V_307 = F_221 ( F_121 ( V_122 ) , V_15 ,
V_142 ) ;
if ( ! V_307 )
break;
F_213 ( V_24 , V_15 , V_16 ) ;
F_222 ( V_122 , V_307 , 1 ) ;
F_223 ( V_307 ) ;
}
V_32 = F_210 ( V_24 , V_126 , V_284 , NULL , V_43 , V_175 ,
V_216 , V_286 , NULL ) ;
return V_32 ;
}
int F_226 ( struct V_23 * V_24 , struct V_126 * V_126 ,
T_13 * V_284 , int V_175 )
{
struct V_43 * V_43 = NULL ;
unsigned long V_216 = 0 ;
int V_32 ;
V_32 = F_225 ( V_24 , V_126 , V_284 , & V_43 , V_175 ,
& V_216 , 0 ) ;
if ( V_43 )
V_32 = F_192 ( V_43 , V_175 , V_216 ) ;
return V_32 ;
}
static void F_227 ( struct V_273 * V_274 ,
unsigned long V_310 )
{
V_274 -> V_311 -= V_310 ;
}
static T_14 int F_228 ( struct V_122 * V_122 ,
struct V_126 * V_126 , struct V_273 * V_274 ,
struct V_312 * V_313 ,
T_1 V_136 ,
unsigned long * V_310 )
{
struct V_23 * V_24 = V_313 -> V_24 ;
T_1 V_288 = V_136 + V_142 - 1 ;
T_1 V_314 ;
T_1 V_315 = 0 ;
T_1 V_137 = 0 ;
int V_32 ;
int V_316 = 0 ;
if ( V_313 -> V_317 || ! V_24 -> V_25 || ! V_24 -> V_25 -> V_318 )
return 0 ;
while ( V_137 < V_288 ) {
V_314 = F_107 ( V_122 , V_24 ,
V_126 ,
& V_136 ,
& V_137 ,
V_319 ) ;
if ( V_314 == 0 ) {
V_136 = V_137 + 1 ;
continue;
}
V_32 = V_24 -> V_25 -> V_318 ( V_122 , V_126 ,
V_136 ,
V_137 ,
& V_316 ,
V_310 ) ;
if ( V_32 ) {
F_115 ( V_126 ) ;
V_32 = V_32 < 0 ? V_32 : - V_153 ;
goto V_320;
}
V_315 += ( V_137 - V_136 +
V_142 ) >> V_124 ;
V_136 = V_137 + 1 ;
}
if ( V_274 -> V_311 < V_315 ) {
int V_321 = 8192 ;
if ( V_315 < V_321 * 2 )
V_321 = V_315 ;
V_274 -> V_311 = F_112 ( T_1 , V_315 ,
V_321 ) ;
}
if ( V_316 ) {
V_274 -> V_311 -= * V_310 ;
return 1 ;
}
V_32 = 0 ;
V_320:
return V_32 ;
}
static T_14 int F_229 ( struct V_122 * V_122 ,
struct V_126 * V_126 ,
struct V_273 * V_274 ,
struct V_312 * V_313 ,
T_10 V_260 ,
unsigned long V_310 ,
int V_322 , int * V_323 )
{
struct V_23 * V_24 = V_313 -> V_24 ;
T_1 V_15 = F_128 ( V_126 ) ;
T_1 V_288 = V_15 + V_142 - 1 ;
T_1 V_16 ;
T_1 V_289 = V_15 ;
T_1 V_290 ;
T_1 V_217 ;
T_1 V_294 ;
T_12 V_179 ;
struct V_211 * V_212 ;
struct V_263 * V_192 ;
T_11 V_174 = 0 ;
T_11 V_296 ;
int V_32 = 0 ;
int V_293 = 0 ;
bool V_324 ;
if ( V_24 -> V_25 && V_24 -> V_25 -> V_325 ) {
V_32 = V_24 -> V_25 -> V_325 ( V_126 , V_15 ,
V_288 ) ;
if ( V_32 ) {
if ( V_32 == - V_326 )
V_274 -> V_327 ++ ;
else
F_230 ( V_274 , V_126 ) ;
F_227 ( V_274 , V_310 ) ;
F_117 ( V_126 ) ;
return 1 ;
}
}
F_227 ( V_274 , V_310 + 1 ) ;
V_16 = V_288 ;
if ( V_260 <= V_15 ) {
if ( V_24 -> V_25 && V_24 -> V_25 -> V_244 )
V_24 -> V_25 -> V_244 ( V_126 , V_15 ,
V_288 , NULL , 1 ) ;
goto V_320;
}
V_296 = V_122 -> V_210 -> V_297 ;
while ( V_289 <= V_16 ) {
T_1 V_328 ;
if ( V_289 >= V_260 ) {
if ( V_24 -> V_25 && V_24 -> V_25 -> V_244 )
V_24 -> V_25 -> V_244 ( V_126 , V_289 ,
V_288 , NULL , 1 ) ;
break;
}
V_212 = V_313 -> V_284 ( F_121 ( V_122 ) , V_126 , V_174 , V_289 ,
V_16 - V_289 + 1 , 1 ) ;
if ( F_209 ( V_212 ) ) {
F_115 ( V_126 ) ;
V_32 = F_231 ( V_212 ) ;
break;
}
V_290 = V_289 - V_212 -> V_15 ;
V_328 = F_208 ( V_212 ) ;
F_19 ( V_328 <= V_289 ) ;
F_19 ( V_16 < V_289 ) ;
V_294 = F_123 ( V_328 - V_289 , V_16 - V_289 + 1 ) ;
V_294 = F_217 ( V_294 , V_296 ) ;
V_179 = ( V_212 -> V_217 + V_290 ) >> 9 ;
V_192 = V_212 -> V_192 ;
V_217 = V_212 -> V_217 ;
V_324 = F_160 ( V_218 , & V_212 -> V_7 ) ;
F_159 ( V_212 ) ;
V_212 = NULL ;
if ( V_324 || V_217 == V_303 ||
V_217 == V_305 ) {
if ( ! V_324 && V_24 -> V_25 &&
V_24 -> V_25 -> V_244 )
V_24 -> V_25 -> V_244 ( V_126 , V_289 ,
V_289 + V_294 - 1 ,
NULL , 1 ) ;
else if ( V_324 ) {
V_293 ++ ;
}
V_289 += V_294 ;
V_174 += V_294 ;
continue;
}
F_100 ( V_24 , V_289 , V_289 + V_294 - 1 ) ;
if ( ! F_232 ( V_126 ) ) {
F_175 ( F_121 ( V_122 ) -> V_57 -> V_170 ,
L_20 ,
V_126 -> V_123 , V_289 , V_16 ) ;
}
V_32 = F_196 ( V_196 , V_322 , V_24 , V_274 ,
V_126 , V_179 , V_294 , V_174 ,
V_192 , & V_313 -> V_43 ,
F_172 ,
0 , 0 , 0 , false ) ;
if ( V_32 ) {
F_115 ( V_126 ) ;
if ( F_232 ( V_126 ) )
F_116 ( V_126 ) ;
}
V_289 = V_289 + V_294 ;
V_174 += V_294 ;
V_293 ++ ;
}
V_320:
* V_323 = V_293 ;
return V_32 ;
}
static int F_233 ( struct V_126 * V_126 , struct V_273 * V_274 ,
void * V_225 )
{
struct V_122 * V_122 = V_126 -> V_145 -> V_236 ;
struct V_312 * V_313 = V_225 ;
T_1 V_15 = F_128 ( V_126 ) ;
T_1 V_288 = V_15 + V_142 - 1 ;
int V_32 ;
int V_293 = 0 ;
T_11 V_174 = 0 ;
T_10 V_260 = F_182 ( V_122 ) ;
unsigned long V_125 = V_260 >> V_124 ;
int V_322 = 0 ;
unsigned long V_310 = 0 ;
if ( V_274 -> V_329 == V_330 )
V_322 = V_197 ;
F_234 ( V_126 , V_122 , V_274 ) ;
F_40 ( ! F_235 ( V_126 ) ) ;
F_236 ( V_126 ) ;
V_174 = V_260 & ( V_142 - 1 ) ;
if ( V_126 -> V_123 > V_125 ||
( V_126 -> V_123 == V_125 && ! V_174 ) ) {
V_126 -> V_145 -> V_331 -> V_332 ( V_126 , 0 , V_142 ) ;
F_117 ( V_126 ) ;
return 0 ;
}
if ( V_126 -> V_123 == V_125 ) {
char * V_299 ;
V_299 = F_214 ( V_126 ) ;
memset ( V_299 + V_174 , 0 ,
V_142 - V_174 ) ;
F_216 ( V_299 ) ;
F_215 ( V_126 ) ;
}
V_174 = 0 ;
F_205 ( V_126 ) ;
V_32 = F_228 ( V_122 , V_126 , V_274 , V_313 , V_15 , & V_310 ) ;
if ( V_32 == 1 )
goto V_333;
if ( V_32 )
goto V_320;
V_32 = F_229 ( V_122 , V_126 , V_274 , V_313 ,
V_260 , V_310 , V_322 , & V_293 ) ;
if ( V_32 == 1 )
goto V_333;
V_320:
if ( V_293 == 0 ) {
F_114 ( V_126 ) ;
F_116 ( V_126 ) ;
}
if ( F_218 ( V_126 ) ) {
V_32 = V_32 < 0 ? V_32 : - V_153 ;
F_170 ( V_126 , V_32 , V_15 , V_288 ) ;
}
F_117 ( V_126 ) ;
return V_32 ;
V_333:
return 0 ;
}
void F_237 ( struct V_10 * V_11 )
{
F_238 ( & V_11 -> V_334 , V_335 ,
V_110 ) ;
}
static T_14 int
F_239 ( struct V_10 * V_11 ,
struct V_36 * V_170 ,
struct V_312 * V_313 )
{
unsigned long V_151 , V_200 ;
int V_336 = 0 ;
int V_32 = 0 ;
if ( ! F_240 ( V_11 ) ) {
V_336 = 1 ;
F_241 ( V_313 ) ;
F_242 ( V_11 ) ;
}
if ( F_160 ( V_335 , & V_11 -> V_334 ) ) {
F_243 ( V_11 ) ;
if ( ! V_313 -> V_337 )
return 0 ;
if ( ! V_336 ) {
F_241 ( V_313 ) ;
V_336 = 1 ;
}
while ( 1 ) {
F_237 ( V_11 ) ;
F_242 ( V_11 ) ;
if ( ! F_160 ( V_335 , & V_11 -> V_334 ) )
break;
F_243 ( V_11 ) ;
}
}
F_70 ( & V_11 -> V_338 ) ;
if ( F_244 ( V_339 , & V_11 -> V_334 ) ) {
F_245 ( V_335 , & V_11 -> V_334 ) ;
F_73 ( & V_11 -> V_338 ) ;
F_246 ( V_11 , V_340 ) ;
F_247 ( & V_170 -> V_341 ,
- V_11 -> V_20 ,
V_170 -> V_342 ) ;
V_32 = 1 ;
} else {
F_73 ( & V_11 -> V_338 ) ;
}
F_243 ( V_11 ) ;
if ( ! V_32 )
return V_32 ;
V_200 = F_147 ( V_11 -> V_15 , V_11 -> V_20 ) ;
for ( V_151 = 0 ; V_151 < V_200 ; V_151 ++ ) {
struct V_126 * V_63 = V_11 -> V_150 [ V_151 ] ;
if ( ! F_248 ( V_63 ) ) {
if ( ! V_336 ) {
F_241 ( V_313 ) ;
V_336 = 1 ;
}
F_118 ( V_63 ) ;
}
}
return V_32 ;
}
static void F_249 ( struct V_10 * V_11 )
{
F_250 ( V_335 , & V_11 -> V_334 ) ;
F_251 () ;
F_252 ( & V_11 -> V_334 , V_335 ) ;
}
static void F_253 ( struct V_126 * V_126 )
{
struct V_10 * V_11 = (struct V_10 * ) V_126 -> V_202 ;
F_115 ( V_126 ) ;
if ( F_254 ( V_343 , & V_11 -> V_334 ) )
return;
switch ( V_11 -> V_344 ) {
case - 1 :
F_245 ( V_345 , & V_11 -> V_170 -> V_7 ) ;
break;
case 0 :
F_245 ( V_346 , & V_11 -> V_170 -> V_7 ) ;
break;
case 1 :
F_245 ( V_347 , & V_11 -> V_170 -> V_7 ) ;
break;
default:
F_255 () ;
}
}
static void F_256 ( struct V_43 * V_43 )
{
struct V_246 * V_247 ;
struct V_10 * V_11 ;
int V_151 , V_320 ;
ASSERT ( ! F_173 ( V_43 , V_248 ) ) ;
F_174 (bvec, bio, i) {
struct V_126 * V_126 = V_247 -> V_249 ;
V_11 = (struct V_10 * ) V_126 -> V_202 ;
F_19 ( ! V_11 ) ;
V_320 = F_257 ( & V_11 -> V_348 ) ;
if ( V_43 -> V_245 ||
F_160 ( V_343 , & V_11 -> V_334 ) ) {
F_171 ( V_126 ) ;
F_253 ( V_126 ) ;
}
F_116 ( V_126 ) ;
if ( ! V_320 )
continue;
F_249 ( V_11 ) ;
}
F_139 ( V_43 ) ;
}
static T_14 int F_258 ( struct V_10 * V_11 ,
struct V_36 * V_170 ,
struct V_273 * V_274 ,
struct V_312 * V_313 )
{
struct V_263 * V_192 = V_170 -> V_228 -> V_229 ;
struct V_23 * V_24 = & F_121 ( V_170 -> V_349 ) -> V_158 ;
T_1 V_59 = V_11 -> V_15 ;
T_15 V_350 ;
unsigned long V_151 , V_200 ;
unsigned long V_216 = 0 ;
unsigned long V_15 , V_16 ;
int V_322 = ( V_313 -> V_337 ? V_197 : 0 ) | V_351 ;
int V_32 = 0 ;
F_250 ( V_343 , & V_11 -> V_334 ) ;
V_200 = F_147 ( V_11 -> V_15 , V_11 -> V_20 ) ;
F_259 ( & V_11 -> V_348 , V_200 ) ;
if ( F_260 ( V_11 ) == V_352 )
V_216 = V_353 ;
V_350 = F_261 ( V_11 ) ;
if ( F_262 ( V_11 ) > 0 ) {
V_16 = F_263 ( V_350 ) ;
F_264 ( V_11 , V_16 , V_11 -> V_20 - V_16 ) ;
} else {
V_15 = F_265 ( V_350 ) ;
V_16 = V_354 + F_266 ( V_170 , V_11 ) ;
F_264 ( V_11 , V_15 , V_16 - V_15 ) ;
}
for ( V_151 = 0 ; V_151 < V_200 ; V_151 ++ ) {
struct V_126 * V_63 = V_11 -> V_150 [ V_151 ] ;
F_95 ( V_63 ) ;
F_114 ( V_63 ) ;
V_32 = F_196 ( V_196 , V_322 , V_24 , V_274 ,
V_63 , V_59 >> 9 , V_142 , 0 , V_192 ,
& V_313 -> V_43 ,
F_256 ,
0 , V_313 -> V_216 , V_216 , false ) ;
V_313 -> V_216 = V_216 ;
if ( V_32 ) {
F_253 ( V_63 ) ;
if ( F_232 ( V_63 ) )
F_116 ( V_63 ) ;
if ( F_267 ( V_200 - V_151 , & V_11 -> V_348 ) )
F_249 ( V_11 ) ;
V_32 = - V_153 ;
break;
}
V_59 += V_142 ;
F_227 ( V_274 , 1 ) ;
F_117 ( V_63 ) ;
}
if ( F_184 ( V_32 ) ) {
for (; V_151 < V_200 ; V_151 ++ ) {
struct V_126 * V_63 = V_11 -> V_150 [ V_151 ] ;
F_95 ( V_63 ) ;
F_117 ( V_63 ) ;
}
}
return V_32 ;
}
int F_268 ( struct V_144 * V_145 ,
struct V_273 * V_274 )
{
struct V_23 * V_24 = & F_121 ( V_145 -> V_236 ) -> V_158 ;
struct V_36 * V_170 = F_121 ( V_145 -> V_236 ) -> V_57 -> V_170 ;
struct V_10 * V_11 , * V_355 = NULL ;
struct V_312 V_313 = {
. V_43 = NULL ,
. V_24 = V_24 ,
. V_317 = 0 ,
. V_337 = V_274 -> V_329 == V_330 ,
. V_216 = 0 ,
} ;
int V_32 = 0 ;
int V_320 = 0 ;
int V_356 = 0 ;
struct V_357 V_358 ;
int V_148 ;
T_6 V_123 ;
T_6 V_16 ;
int V_359 = 0 ;
int V_360 ;
F_269 ( & V_358 , 0 ) ;
if ( V_274 -> V_361 ) {
V_123 = V_145 -> V_362 ;
V_16 = - 1 ;
} else {
V_123 = V_274 -> V_363 >> V_124 ;
V_16 = V_274 -> V_364 >> V_124 ;
V_359 = 1 ;
}
if ( V_274 -> V_329 == V_330 )
V_360 = V_365 ;
else
V_360 = V_366 ;
V_367:
if ( V_274 -> V_329 == V_330 )
F_270 ( V_145 , V_123 , V_16 ) ;
while ( ! V_320 && ! V_356 && ( V_123 <= V_16 ) &&
( V_148 = F_271 ( & V_358 , V_145 , & V_123 , V_360 ,
F_123 ( V_16 - V_123 , ( T_6 ) V_368 - 1 ) + 1 ) ) ) {
unsigned V_151 ;
V_359 = 1 ;
for ( V_151 = 0 ; V_151 < V_148 ; V_151 ++ ) {
struct V_126 * V_126 = V_358 . V_150 [ V_151 ] ;
if ( ! F_201 ( V_126 ) )
continue;
if ( ! V_274 -> V_361 && V_126 -> V_123 > V_16 ) {
V_320 = 1 ;
break;
}
F_70 ( & V_145 -> V_369 ) ;
if ( ! F_201 ( V_126 ) ) {
F_73 ( & V_145 -> V_369 ) ;
continue;
}
V_11 = (struct V_10 * ) V_126 -> V_202 ;
if ( F_40 ( ! V_11 ) ) {
F_73 ( & V_145 -> V_369 ) ;
continue;
}
if ( V_11 == V_355 ) {
F_73 ( & V_145 -> V_369 ) ;
continue;
}
V_32 = F_272 ( & V_11 -> V_17 ) ;
F_73 ( & V_145 -> V_369 ) ;
if ( ! V_32 )
continue;
V_355 = V_11 ;
V_32 = F_239 ( V_11 , V_170 , & V_313 ) ;
if ( ! V_32 ) {
F_273 ( V_11 ) ;
continue;
}
V_32 = F_258 ( V_11 , V_170 , V_274 , & V_313 ) ;
if ( V_32 ) {
V_320 = 1 ;
F_273 ( V_11 ) ;
break;
}
F_273 ( V_11 ) ;
V_356 = V_274 -> V_311 <= 0 ;
}
F_274 ( & V_358 ) ;
F_74 () ;
}
if ( ! V_359 && ! V_320 ) {
V_359 = 1 ;
V_123 = 0 ;
goto V_367;
}
F_241 ( & V_313 ) ;
return V_32 ;
}
static int F_275 ( struct V_144 * V_145 ,
struct V_273 * V_274 ,
T_16 V_370 , void * V_225 ,
void (* F_276)( void * ) )
{
struct V_122 * V_122 = V_145 -> V_236 ;
int V_32 = 0 ;
int V_320 = 0 ;
int V_356 = 0 ;
struct V_357 V_358 ;
int V_148 ;
T_6 V_123 ;
T_6 V_16 ;
T_6 V_371 ;
int V_372 = 0 ;
int V_359 = 0 ;
int V_360 ;
if ( ! F_277 ( V_122 ) )
return 0 ;
F_269 ( & V_358 , 0 ) ;
if ( V_274 -> V_361 ) {
V_123 = V_145 -> V_362 ;
V_16 = - 1 ;
} else {
V_123 = V_274 -> V_363 >> V_124 ;
V_16 = V_274 -> V_364 >> V_124 ;
if ( V_274 -> V_363 == 0 && V_274 -> V_364 == V_373 )
V_372 = 1 ;
V_359 = 1 ;
}
if ( V_274 -> V_329 == V_330 )
V_360 = V_365 ;
else
V_360 = V_366 ;
V_367:
if ( V_274 -> V_329 == V_330 )
F_270 ( V_145 , V_123 , V_16 ) ;
V_371 = V_123 ;
while ( ! V_320 && ! V_356 && ( V_123 <= V_16 ) &&
( V_148 = F_271 ( & V_358 , V_145 , & V_123 , V_360 ,
F_123 ( V_16 - V_123 , ( T_6 ) V_368 - 1 ) + 1 ) ) ) {
unsigned V_151 ;
V_359 = 1 ;
for ( V_151 = 0 ; V_151 < V_148 ; V_151 ++ ) {
struct V_126 * V_126 = V_358 . V_150 [ V_151 ] ;
V_371 = V_126 -> V_123 ;
if ( ! F_248 ( V_126 ) ) {
F_276 ( V_225 ) ;
F_118 ( V_126 ) ;
}
if ( F_184 ( V_126 -> V_145 != V_145 ) ) {
F_117 ( V_126 ) ;
continue;
}
if ( ! V_274 -> V_361 && V_126 -> V_123 > V_16 ) {
V_320 = 1 ;
F_117 ( V_126 ) ;
continue;
}
if ( V_274 -> V_329 != V_374 ) {
if ( F_232 ( V_126 ) )
F_276 ( V_225 ) ;
F_278 ( V_126 ) ;
}
if ( F_232 ( V_126 ) ||
! F_95 ( V_126 ) ) {
F_117 ( V_126 ) ;
continue;
}
V_32 = (* V_370)( V_126 , V_274 , V_225 ) ;
if ( F_184 ( V_32 == V_375 ) ) {
F_117 ( V_126 ) ;
V_32 = 0 ;
}
if ( V_32 < 0 ) {
V_371 = V_126 -> V_123 + 1 ;
V_320 = 1 ;
break;
}
V_356 = V_274 -> V_311 <= 0 ;
}
F_274 ( & V_358 ) ;
F_74 () ;
}
if ( ! V_359 && ! V_320 ) {
V_359 = 1 ;
V_123 = 0 ;
goto V_367;
}
if ( V_274 -> V_361 || ( V_274 -> V_311 > 0 && V_372 ) )
V_145 -> V_362 = V_371 ;
F_279 ( V_122 ) ;
return V_32 ;
}
static void F_280 ( struct V_312 * V_313 )
{
if ( V_313 -> V_43 ) {
int V_32 ;
F_168 ( V_313 -> V_43 , V_196 ,
V_313 -> V_337 ? V_197 : 0 ) ;
V_32 = F_192 ( V_313 -> V_43 , 0 , V_313 -> V_216 ) ;
F_19 ( V_32 < 0 ) ;
V_313 -> V_43 = NULL ;
}
}
static T_5 void F_241 ( void * V_225 )
{
struct V_312 * V_313 = V_225 ;
F_280 ( V_313 ) ;
}
int F_281 ( struct V_23 * V_24 , struct V_126 * V_126 ,
T_13 * V_284 ,
struct V_273 * V_274 )
{
int V_32 ;
struct V_312 V_313 = {
. V_43 = NULL ,
. V_24 = V_24 ,
. V_284 = V_284 ,
. V_317 = 0 ,
. V_337 = V_274 -> V_329 == V_330 ,
. V_216 = 0 ,
} ;
V_32 = F_233 ( V_126 , V_274 , & V_313 ) ;
F_280 ( & V_313 ) ;
return V_32 ;
}
int F_282 ( struct V_23 * V_24 , struct V_122 * V_122 ,
T_1 V_15 , T_1 V_16 , T_13 * V_284 ,
int V_376 )
{
int V_32 = 0 ;
struct V_144 * V_145 = V_122 -> V_127 ;
struct V_126 * V_126 ;
unsigned long V_148 = ( V_16 - V_15 + V_142 ) >>
V_124 ;
struct V_312 V_313 = {
. V_43 = NULL ,
. V_24 = V_24 ,
. V_284 = V_284 ,
. V_317 = 1 ,
. V_337 = V_376 == V_330 ,
. V_216 = 0 ,
} ;
struct V_273 V_377 = {
. V_329 = V_376 ,
. V_311 = V_148 * 2 ,
. V_363 = V_15 ,
. V_364 = V_16 + 1 ,
} ;
while ( V_15 <= V_16 ) {
V_126 = F_94 ( V_145 , V_15 >> V_124 ) ;
if ( F_95 ( V_126 ) )
V_32 = F_233 ( V_126 , & V_377 , & V_313 ) ;
else {
if ( V_24 -> V_25 && V_24 -> V_25 -> V_244 )
V_24 -> V_25 -> V_244 ( V_126 , V_15 ,
V_15 + V_142 - 1 ,
NULL , 1 ) ;
F_117 ( V_126 ) ;
}
F_96 ( V_126 ) ;
V_15 += V_142 ;
}
F_280 ( & V_313 ) ;
return V_32 ;
}
int F_283 ( struct V_23 * V_24 ,
struct V_144 * V_145 ,
T_13 * V_284 ,
struct V_273 * V_274 )
{
int V_32 = 0 ;
struct V_312 V_313 = {
. V_43 = NULL ,
. V_24 = V_24 ,
. V_284 = V_284 ,
. V_317 = 0 ,
. V_337 = V_274 -> V_329 == V_330 ,
. V_216 = 0 ,
} ;
V_32 = F_275 ( V_145 , V_274 , F_233 , & V_313 ,
F_241 ) ;
F_280 ( & V_313 ) ;
return V_32 ;
}
int F_284 ( struct V_23 * V_24 ,
struct V_144 * V_145 ,
struct V_4 * V_150 , unsigned V_148 ,
T_13 V_284 )
{
struct V_43 * V_43 = NULL ;
unsigned V_378 ;
unsigned long V_216 = 0 ;
struct V_126 * V_379 [ 16 ] ;
struct V_126 * V_126 ;
struct V_211 * V_285 = NULL ;
int V_293 = 0 ;
T_1 V_287 = ( T_1 ) - 1 ;
for ( V_378 = 0 ; V_378 < V_148 ; V_378 ++ ) {
V_126 = F_11 ( V_150 -> V_74 , struct V_126 , V_380 ) ;
F_285 ( & V_126 -> V_7 ) ;
F_8 ( & V_126 -> V_380 ) ;
if ( F_286 ( V_126 , V_145 ,
V_126 -> V_123 ,
F_287 ( V_145 ) ) ) {
F_96 ( V_126 ) ;
continue;
}
V_379 [ V_293 ++ ] = V_126 ;
if ( V_293 < F_288 ( V_379 ) )
continue;
F_224 ( V_24 , V_379 , V_293 , V_284 , & V_285 ,
& V_43 , 0 , & V_216 , & V_287 ) ;
V_293 = 0 ;
}
if ( V_293 )
F_224 ( V_24 , V_379 , V_293 , V_284 , & V_285 ,
& V_43 , 0 , & V_216 , & V_287 ) ;
if ( V_285 )
F_159 ( V_285 ) ;
F_19 ( ! F_10 ( V_150 ) ) ;
if ( V_43 )
return F_192 ( V_43 , 0 , V_216 ) ;
return 0 ;
}
int F_289 ( struct V_23 * V_24 ,
struct V_126 * V_126 , unsigned long V_59 )
{
struct V_1 * V_98 = NULL ;
T_1 V_15 = F_128 ( V_126 ) ;
T_1 V_16 = V_15 + V_142 - 1 ;
T_11 V_296 = V_126 -> V_145 -> V_236 -> V_210 -> V_297 ;
V_15 += F_217 ( V_59 , V_296 ) ;
if ( V_15 > V_16 )
return 0 ;
F_91 ( V_24 , V_15 , V_16 , & V_98 ) ;
F_278 ( V_126 ) ;
F_89 ( V_24 , V_15 , V_16 ,
V_121 | V_94 | V_102 |
V_381 ,
1 , 1 , & V_98 , V_120 ) ;
return 0 ;
}
static int F_290 ( struct V_213 * V_382 ,
struct V_23 * V_24 ,
struct V_126 * V_126 , T_3 V_50 )
{
T_1 V_15 = F_128 ( V_126 ) ;
T_1 V_16 = V_15 + V_142 - 1 ;
int V_32 = 1 ;
if ( F_108 ( V_24 , V_15 , V_16 ,
V_80 , 0 , NULL ) )
V_32 = 0 ;
else {
V_32 = F_89 ( V_24 , V_15 , V_16 ,
~ ( V_121 | V_383 ) ,
0 , 0 , NULL , V_50 ) ;
if ( V_32 < 0 )
V_32 = 0 ;
else
V_32 = 1 ;
}
return V_32 ;
}
int F_291 ( struct V_213 * V_382 ,
struct V_23 * V_24 , struct V_126 * V_126 ,
T_3 V_50 )
{
struct V_211 * V_212 ;
T_1 V_15 = F_128 ( V_126 ) ;
T_1 V_16 = V_15 + V_142 - 1 ;
if ( F_69 ( V_50 ) &&
V_126 -> V_145 -> V_236 -> V_260 > V_384 ) {
T_1 V_20 ;
while ( V_15 <= V_16 ) {
V_20 = V_16 - V_15 + 1 ;
F_292 ( & V_382 -> V_49 ) ;
V_212 = F_157 ( V_382 , V_15 , V_20 ) ;
if ( ! V_212 ) {
F_293 ( & V_382 -> V_49 ) ;
break;
}
if ( F_160 ( V_385 , & V_212 -> V_7 ) ||
V_212 -> V_15 != V_15 ) {
F_293 ( & V_382 -> V_49 ) ;
F_159 ( V_212 ) ;
break;
}
if ( ! F_108 ( V_24 , V_212 -> V_15 ,
F_208 ( V_212 ) - 1 ,
V_121 | V_386 ,
0 , NULL ) ) {
F_294 ( V_382 , V_212 ) ;
F_159 ( V_212 ) ;
}
V_15 = F_208 ( V_212 ) ;
F_293 ( & V_382 -> V_49 ) ;
F_159 ( V_212 ) ;
}
}
return F_290 ( V_382 , V_24 , V_126 , V_50 ) ;
}
static struct V_211 * F_295 ( struct V_122 * V_122 ,
T_1 V_59 ,
T_1 V_161 ,
T_13 * V_284 )
{
T_1 V_387 = F_296 ( V_122 ) ;
struct V_211 * V_212 ;
T_1 V_20 ;
if ( V_59 >= V_161 )
return NULL ;
while ( 1 ) {
V_20 = V_161 - V_59 ;
if ( V_20 == 0 )
break;
V_20 = F_217 ( V_20 , V_387 ) ;
V_212 = V_284 ( F_121 ( V_122 ) , NULL , 0 , V_59 , V_20 , 0 ) ;
if ( F_209 ( V_212 ) )
return V_212 ;
if ( ! F_160 ( V_388 , & V_212 -> V_7 ) &&
V_212 -> V_217 != V_303 ) {
return V_212 ;
}
V_59 = F_208 ( V_212 ) ;
F_159 ( V_212 ) ;
if ( V_59 >= V_161 )
break;
}
return NULL ;
}
static int F_297 ( struct V_389 * V_390 ,
struct V_391 * V_392 ,
T_1 V_59 , T_1 V_393 , T_1 V_20 , T_15 V_7 )
{
int V_32 = 0 ;
if ( ! V_392 -> V_99 )
goto V_394;
if ( V_392 -> V_59 + V_392 -> V_20 > V_59 ) {
F_40 ( 1 ) ;
return - V_395 ;
}
if ( V_392 -> V_59 + V_392 -> V_20 == V_59 &&
V_392 -> V_393 + V_392 -> V_20 == V_393 &&
( V_392 -> V_7 & ~ V_396 ) ==
( V_7 & ~ V_396 ) ) {
V_392 -> V_20 += V_20 ;
V_392 -> V_7 |= V_7 ;
goto V_397;
}
V_32 = F_298 ( V_390 , V_392 -> V_59 , V_392 -> V_393 ,
V_392 -> V_20 , V_392 -> V_7 ) ;
V_392 -> V_99 = false ;
if ( V_32 )
return V_32 ;
V_394:
V_392 -> V_99 = true ;
V_392 -> V_59 = V_59 ;
V_392 -> V_393 = V_393 ;
V_392 -> V_20 = V_20 ;
V_392 -> V_7 = V_7 ;
V_397:
if ( V_392 -> V_7 & V_396 ) {
V_32 = F_298 ( V_390 , V_392 -> V_59 ,
V_392 -> V_393 , V_392 -> V_20 , V_392 -> V_7 ) ;
V_392 -> V_99 = false ;
}
return V_32 ;
}
static int F_299 ( struct V_36 * V_170 ,
struct V_389 * V_390 ,
struct V_391 * V_392 )
{
int V_32 ;
if ( ! V_392 -> V_99 )
return 0 ;
V_32 = F_298 ( V_390 , V_392 -> V_59 , V_392 -> V_393 ,
V_392 -> V_20 , V_392 -> V_7 ) ;
V_392 -> V_99 = false ;
if ( V_32 > 0 )
V_32 = 0 ;
return V_32 ;
}
int F_300 ( struct V_122 * V_122 , struct V_389 * V_390 ,
T_17 V_15 , T_17 V_20 , T_13 * V_284 )
{
int V_32 = 0 ;
T_1 V_261 = V_15 ;
T_1 F_124 = V_15 + V_20 ;
T_15 V_7 = 0 ;
T_15 V_398 ;
T_1 V_161 ;
T_1 V_399 = 0 ;
T_1 V_400 = 0 ;
T_1 V_401 = F_182 ( V_122 ) ;
struct V_402 V_403 ;
struct V_211 * V_212 = NULL ;
struct V_1 * V_98 = NULL ;
struct V_404 * V_405 ;
struct V_406 * V_57 = F_121 ( V_122 ) -> V_57 ;
struct V_391 V_392 = { 0 } ;
int V_16 = 0 ;
T_1 V_407 = 0 ;
T_1 V_408 = 0 ;
T_1 V_328 = 0 ;
if ( V_20 == 0 )
return - V_395 ;
V_405 = F_301 () ;
if ( ! V_405 )
return - V_38 ;
V_405 -> V_409 = 1 ;
V_15 = F_302 ( V_15 , F_296 ( V_122 ) ) ;
V_20 = F_303 ( F_124 , F_296 ( V_122 ) ) - V_15 ;
V_32 = F_304 ( NULL , V_57 , V_405 ,
F_181 ( F_121 ( V_122 ) ) , - 1 , 0 ) ;
if ( V_32 < 0 ) {
F_305 ( V_405 ) ;
return V_32 ;
} else {
F_40 ( ! V_32 ) ;
if ( V_32 == 1 )
V_32 = 0 ;
}
V_405 -> V_410 [ 0 ] -- ;
F_306 ( V_405 -> V_411 [ 0 ] , & V_403 , V_405 -> V_410 [ 0 ] ) ;
V_398 = V_403 . type ;
if ( V_403 . V_412 != F_181 ( F_121 ( V_122 ) ) ||
V_398 != V_413 ) {
V_161 = ( T_1 ) - 1 ;
V_399 = V_401 ;
} else {
V_161 = V_403 . V_59 ;
V_399 = V_161 + 1 ;
}
F_307 ( V_405 ) ;
if ( V_161 < V_401 ) {
V_161 = ( T_1 ) - 1 ;
V_399 = V_401 ;
}
F_91 ( & F_121 ( V_122 ) -> V_158 , V_15 , V_15 + V_20 - 1 ,
& V_98 ) ;
V_212 = F_295 ( V_122 , V_15 , V_399 ,
V_284 ) ;
if ( ! V_212 )
goto V_107;
if ( F_308 ( V_212 ) ) {
V_32 = F_309 ( V_212 ) ;
goto V_107;
}
while ( ! V_16 ) {
T_1 V_414 = 0 ;
if ( V_212 -> V_15 >= F_124 || F_208 ( V_212 ) < V_261 )
break;
V_407 = F_124 ( V_212 -> V_15 , V_261 ) ;
if ( ! F_160 ( V_218 , & V_212 -> V_7 ) )
V_414 = V_407 - V_212 -> V_15 ;
V_328 = F_208 ( V_212 ) ;
V_408 = V_328 - V_407 ;
V_400 = 0 ;
V_7 = 0 ;
V_261 = F_208 ( V_212 ) ;
if ( V_261 >= F_124 )
V_16 = 1 ;
if ( V_212 -> V_217 == V_415 ) {
V_16 = 1 ;
V_7 |= V_396 ;
} else if ( V_212 -> V_217 == V_305 ) {
V_7 |= ( V_416 |
V_417 ) ;
} else if ( V_212 -> V_217 == V_418 ) {
V_7 |= ( V_419 |
V_420 ) ;
} else if ( V_390 -> V_421 ) {
struct V_422 * V_423 ;
T_1 V_424 = V_212 -> V_217 -
( V_212 -> V_15 - V_212 -> V_304 ) ;
V_400 = V_212 -> V_217 + V_414 ;
V_423 = F_310 ( V_57 ) ;
if ( F_308 ( V_423 ) )
V_423 = NULL ;
V_32 = F_311 ( V_423 , V_57 -> V_170 ,
V_57 -> V_412 ,
F_181 ( F_121 ( V_122 ) ) , V_424 ) ;
if ( V_423 )
F_312 ( V_423 ) ;
if ( V_32 < 0 )
goto V_425;
if ( V_32 )
V_7 |= V_426 ;
V_32 = 0 ;
}
if ( F_160 ( V_218 , & V_212 -> V_7 ) )
V_7 |= V_427 ;
if ( F_160 ( V_302 , & V_212 -> V_7 ) )
V_7 |= V_428 ;
F_159 ( V_212 ) ;
V_212 = NULL ;
if ( ( V_407 >= V_161 ) || V_408 == ( T_1 ) - 1 ||
( V_161 == ( T_1 ) - 1 && V_401 <= V_328 ) ) {
V_7 |= V_396 ;
V_16 = 1 ;
}
V_212 = F_295 ( V_122 , V_261 , V_399 ,
V_284 ) ;
if ( F_308 ( V_212 ) ) {
V_32 = F_309 ( V_212 ) ;
goto V_107;
}
if ( ! V_212 ) {
V_7 |= V_396 ;
V_16 = 1 ;
}
V_32 = F_297 ( V_390 , & V_392 , V_407 , V_400 ,
V_408 , V_7 ) ;
if ( V_32 ) {
if ( V_32 == 1 )
V_32 = 0 ;
goto V_425;
}
}
V_425:
if ( ! V_32 )
V_32 = F_299 ( V_57 -> V_170 , V_390 , & V_392 ) ;
F_159 ( V_212 ) ;
V_107:
F_305 ( V_405 ) ;
F_109 ( & F_121 ( V_122 ) -> V_158 , V_15 , V_15 + V_20 - 1 ,
& V_98 , V_120 ) ;
return V_32 ;
}
static void F_313 ( struct V_10 * V_11 )
{
F_7 ( & V_11 -> V_14 ) ;
F_14 ( V_21 , V_11 ) ;
}
int F_314 ( struct V_10 * V_11 )
{
return ( F_15 ( & V_11 -> V_348 ) ||
F_160 ( V_335 , & V_11 -> V_334 ) ||
F_160 ( V_339 , & V_11 -> V_334 ) ) ;
}
static void F_315 ( struct V_10 * V_11 )
{
unsigned long V_123 ;
struct V_126 * V_126 ;
int V_429 = ! F_160 ( V_430 , & V_11 -> V_334 ) ;
F_19 ( F_314 ( V_11 ) ) ;
V_123 = F_147 ( V_11 -> V_15 , V_11 -> V_20 ) ;
if ( V_123 == 0 )
return;
do {
V_123 -- ;
V_126 = V_11 -> V_150 [ V_123 ] ;
if ( ! V_126 )
continue;
if ( V_429 )
F_70 ( & V_126 -> V_145 -> V_369 ) ;
if ( F_201 ( V_126 ) &&
V_126 -> V_202 == ( unsigned long ) V_11 ) {
F_19 ( F_160 ( V_339 , & V_11 -> V_334 ) ) ;
F_19 ( F_119 ( V_126 ) ) ;
F_19 ( F_232 ( V_126 ) ) ;
F_316 ( V_126 ) ;
F_204 ( V_126 , 0 ) ;
F_96 ( V_126 ) ;
}
if ( V_429 )
F_73 ( & V_126 -> V_145 -> V_369 ) ;
F_96 ( V_126 ) ;
} while ( V_123 != 0 );
}
static inline void F_317 ( struct V_10 * V_11 )
{
F_315 ( V_11 ) ;
F_313 ( V_11 ) ;
}
static struct V_10 *
F_318 ( struct V_36 * V_170 , T_1 V_15 ,
unsigned long V_20 )
{
struct V_10 * V_11 = NULL ;
V_11 = F_319 ( V_21 , V_120 | V_431 ) ;
V_11 -> V_15 = V_15 ;
V_11 -> V_20 = V_20 ;
V_11 -> V_170 = V_170 ;
V_11 -> V_334 = 0 ;
F_320 ( & V_11 -> V_49 ) ;
F_259 ( & V_11 -> V_432 , 0 ) ;
F_259 ( & V_11 -> V_433 , 0 ) ;
F_259 ( & V_11 -> V_434 , 0 ) ;
F_259 ( & V_11 -> V_435 , 0 ) ;
F_259 ( & V_11 -> V_436 , 0 ) ;
F_259 ( & V_11 -> V_437 , 0 ) ;
V_11 -> V_438 = 0 ;
F_36 ( & V_11 -> V_439 ) ;
F_36 ( & V_11 -> V_440 ) ;
F_3 ( & V_11 -> V_14 , & V_19 ) ;
F_31 ( & V_11 -> V_338 ) ;
F_259 ( & V_11 -> V_17 , 1 ) ;
F_259 ( & V_11 -> V_348 , 0 ) ;
F_321 ( V_441
> V_442 ) ;
F_19 ( V_20 > V_442 ) ;
return V_11 ;
}
struct V_10 * F_322 ( struct V_10 * V_443 )
{
unsigned long V_151 ;
struct V_126 * V_63 ;
struct V_10 * V_5 ;
unsigned long V_200 = F_147 ( V_443 -> V_15 , V_443 -> V_20 ) ;
V_5 = F_318 ( V_443 -> V_170 , V_443 -> V_15 , V_443 -> V_20 ) ;
if ( V_5 == NULL )
return NULL ;
for ( V_151 = 0 ; V_151 < V_200 ; V_151 ++ ) {
V_63 = F_323 ( V_120 ) ;
if ( ! V_63 ) {
F_317 ( V_5 ) ;
return NULL ;
}
F_200 ( V_5 , V_63 ) ;
F_40 ( F_119 ( V_63 ) ) ;
F_129 ( V_63 ) ;
V_5 -> V_150 [ V_151 ] = V_63 ;
F_324 ( F_325 ( V_63 ) , F_325 ( V_443 -> V_150 [ V_151 ] ) ) ;
}
F_245 ( V_444 , & V_5 -> V_334 ) ;
F_245 ( V_430 , & V_5 -> V_334 ) ;
return V_5 ;
}
struct V_10 * F_326 ( struct V_36 * V_170 ,
T_1 V_15 , unsigned long V_20 )
{
struct V_10 * V_11 ;
unsigned long V_200 ;
unsigned long V_151 ;
V_200 = F_147 ( V_15 , V_20 ) ;
V_11 = F_318 ( V_170 , V_15 , V_20 ) ;
if ( ! V_11 )
return NULL ;
for ( V_151 = 0 ; V_151 < V_200 ; V_151 ++ ) {
V_11 -> V_150 [ V_151 ] = F_323 ( V_120 ) ;
if ( ! V_11 -> V_150 [ V_151 ] )
goto V_96;
}
F_327 ( V_11 ) ;
F_328 ( V_11 , 0 ) ;
F_245 ( V_430 , & V_11 -> V_334 ) ;
return V_11 ;
V_96:
for (; V_151 > 0 ; V_151 -- )
F_329 ( V_11 -> V_150 [ V_151 - 1 ] ) ;
F_313 ( V_11 ) ;
return NULL ;
}
struct V_10 * F_330 ( struct V_36 * V_170 ,
T_1 V_15 )
{
return F_326 ( V_170 , V_15 , V_170 -> V_445 ) ;
}
static void F_331 ( struct V_10 * V_11 )
{
int V_17 ;
V_17 = F_15 ( & V_11 -> V_17 ) ;
if ( V_17 >= 2 && F_160 ( V_446 , & V_11 -> V_334 ) )
return;
F_70 ( & V_11 -> V_338 ) ;
if ( ! F_254 ( V_446 , & V_11 -> V_334 ) )
F_332 ( & V_11 -> V_17 ) ;
F_73 ( & V_11 -> V_338 ) ;
}
static void F_333 ( struct V_10 * V_11 ,
struct V_126 * V_447 )
{
unsigned long V_200 , V_151 ;
F_331 ( V_11 ) ;
V_200 = F_147 ( V_11 -> V_15 , V_11 -> V_20 ) ;
for ( V_151 = 0 ; V_151 < V_200 ; V_151 ++ ) {
struct V_126 * V_63 = V_11 -> V_150 [ V_151 ] ;
if ( V_63 != V_447 )
F_334 ( V_63 ) ;
}
}
struct V_10 * F_335 ( struct V_36 * V_170 ,
T_1 V_15 )
{
struct V_10 * V_11 ;
F_336 () ;
V_11 = F_337 ( & V_170 -> V_448 ,
V_15 >> V_124 ) ;
if ( V_11 && F_272 ( & V_11 -> V_17 ) ) {
F_338 () ;
if ( F_160 ( V_449 , & V_11 -> V_334 ) ) {
F_70 ( & V_11 -> V_338 ) ;
F_73 ( & V_11 -> V_338 ) ;
}
F_333 ( V_11 , NULL ) ;
return V_11 ;
}
F_338 () ;
return NULL ;
}
struct V_10 * F_339 ( struct V_36 * V_170 ,
T_1 V_15 )
{
struct V_10 * V_11 , * V_450 = NULL ;
int V_32 ;
V_11 = F_335 ( V_170 , V_15 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_330 ( V_170 , V_15 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_170 = V_170 ;
V_105:
V_32 = F_340 ( V_120 ) ;
if ( V_32 )
goto V_451;
F_70 ( & V_170 -> V_452 ) ;
V_32 = F_341 ( & V_170 -> V_448 ,
V_15 >> V_124 , V_11 ) ;
F_73 ( & V_170 -> V_452 ) ;
F_342 () ;
if ( V_32 == - V_86 ) {
V_450 = F_335 ( V_170 , V_15 ) ;
if ( V_450 )
goto V_451;
else
goto V_105;
}
F_331 ( V_11 ) ;
F_245 ( V_453 , & V_11 -> V_334 ) ;
F_332 ( & V_11 -> V_17 ) ;
return V_11 ;
V_451:
F_317 ( V_11 ) ;
return V_450 ;
}
struct V_10 * F_343 ( struct V_36 * V_170 ,
T_1 V_15 )
{
unsigned long V_20 = V_170 -> V_445 ;
unsigned long V_200 = F_147 ( V_15 , V_20 ) ;
unsigned long V_151 ;
unsigned long V_123 = V_15 >> V_124 ;
struct V_10 * V_11 ;
struct V_10 * V_450 = NULL ;
struct V_126 * V_63 ;
struct V_144 * V_145 = V_170 -> V_349 -> V_127 ;
int V_243 = 1 ;
int V_32 ;
if ( ! F_344 ( V_15 , V_170 -> V_387 ) ) {
F_175 ( V_170 , L_21 , V_15 ) ;
return F_345 ( - V_395 ) ;
}
V_11 = F_335 ( V_170 , V_15 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_318 ( V_170 , V_15 , V_20 ) ;
if ( ! V_11 )
return F_345 ( - V_38 ) ;
for ( V_151 = 0 ; V_151 < V_200 ; V_151 ++ , V_123 ++ ) {
V_63 = F_346 ( V_145 , V_123 , V_120 | V_431 ) ;
if ( ! V_63 ) {
V_450 = F_345 ( - V_38 ) ;
goto V_451;
}
F_70 ( & V_145 -> V_369 ) ;
if ( F_201 ( V_63 ) ) {
V_450 = (struct V_10 * ) V_63 -> V_202 ;
if ( F_272 ( & V_450 -> V_17 ) ) {
F_73 ( & V_145 -> V_369 ) ;
F_117 ( V_63 ) ;
F_96 ( V_63 ) ;
F_333 ( V_450 , V_63 ) ;
goto V_451;
}
V_450 = NULL ;
F_316 ( V_63 ) ;
F_40 ( F_119 ( V_63 ) ) ;
F_96 ( V_63 ) ;
}
F_200 ( V_11 , V_63 ) ;
F_73 ( & V_145 -> V_369 ) ;
F_40 ( F_119 ( V_63 ) ) ;
V_11 -> V_150 [ V_151 ] = V_63 ;
if ( ! F_211 ( V_63 ) )
V_243 = 0 ;
}
if ( V_243 )
F_245 ( V_444 , & V_11 -> V_334 ) ;
V_105:
V_32 = F_340 ( V_120 ) ;
if ( V_32 ) {
V_450 = F_345 ( V_32 ) ;
goto V_451;
}
F_70 ( & V_170 -> V_452 ) ;
V_32 = F_341 ( & V_170 -> V_448 ,
V_15 >> V_124 , V_11 ) ;
F_73 ( & V_170 -> V_452 ) ;
F_342 () ;
if ( V_32 == - V_86 ) {
V_450 = F_335 ( V_170 , V_15 ) ;
if ( V_450 )
goto V_451;
else
goto V_105;
}
F_331 ( V_11 ) ;
F_245 ( V_453 , & V_11 -> V_334 ) ;
F_347 ( V_11 -> V_150 [ 0 ] ) ;
for ( V_151 = 1 ; V_151 < V_200 ; V_151 ++ ) {
V_63 = V_11 -> V_150 [ V_151 ] ;
F_348 ( V_63 ) ;
F_117 ( V_63 ) ;
}
F_117 ( V_11 -> V_150 [ 0 ] ) ;
return V_11 ;
V_451:
F_40 ( ! F_257 ( & V_11 -> V_17 ) ) ;
for ( V_151 = 0 ; V_151 < V_200 ; V_151 ++ ) {
if ( V_11 -> V_150 [ V_151 ] )
F_117 ( V_11 -> V_150 [ V_151 ] ) ;
}
F_317 ( V_11 ) ;
return V_450 ;
}
static inline void F_349 ( struct V_454 * V_6 )
{
struct V_10 * V_11 =
F_350 ( V_6 , struct V_10 , V_454 ) ;
F_313 ( V_11 ) ;
}
static int F_351 ( struct V_10 * V_11 )
{
F_40 ( F_15 ( & V_11 -> V_17 ) == 0 ) ;
if ( F_257 ( & V_11 -> V_17 ) ) {
if ( F_244 ( V_453 , & V_11 -> V_334 ) ) {
struct V_36 * V_170 = V_11 -> V_170 ;
F_73 ( & V_11 -> V_338 ) ;
F_70 ( & V_170 -> V_452 ) ;
F_352 ( & V_170 -> V_448 ,
V_11 -> V_15 >> V_124 ) ;
F_73 ( & V_170 -> V_452 ) ;
} else {
F_73 ( & V_11 -> V_338 ) ;
}
F_315 ( V_11 ) ;
#ifdef F_353
if ( F_184 ( F_160 ( V_430 , & V_11 -> V_334 ) ) ) {
F_313 ( V_11 ) ;
return 1 ;
}
#endif
F_354 ( & V_11 -> V_454 , F_349 ) ;
return 1 ;
}
F_73 ( & V_11 -> V_338 ) ;
return 0 ;
}
void F_273 ( struct V_10 * V_11 )
{
int V_17 ;
int V_455 ;
if ( ! V_11 )
return;
while ( 1 ) {
V_17 = F_15 ( & V_11 -> V_17 ) ;
if ( V_17 <= 3 )
break;
V_455 = F_355 ( & V_11 -> V_17 , V_17 , V_17 - 1 ) ;
if ( V_455 == V_17 )
return;
}
F_70 ( & V_11 -> V_338 ) ;
if ( F_15 ( & V_11 -> V_17 ) == 2 &&
F_160 ( V_430 , & V_11 -> V_334 ) )
F_356 ( & V_11 -> V_17 ) ;
if ( F_15 ( & V_11 -> V_17 ) == 2 &&
F_160 ( V_449 , & V_11 -> V_334 ) &&
! F_314 ( V_11 ) &&
F_244 ( V_446 , & V_11 -> V_334 ) )
F_356 ( & V_11 -> V_17 ) ;
F_351 ( V_11 ) ;
}
void F_357 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return;
F_70 ( & V_11 -> V_338 ) ;
F_245 ( V_449 , & V_11 -> V_334 ) ;
if ( F_15 ( & V_11 -> V_17 ) == 2 && ! F_314 ( V_11 ) &&
F_244 ( V_446 , & V_11 -> V_334 ) )
F_356 ( & V_11 -> V_17 ) ;
F_351 ( V_11 ) ;
}
void F_358 ( struct V_10 * V_11 )
{
unsigned long V_151 ;
unsigned long V_200 ;
struct V_126 * V_126 ;
V_200 = F_147 ( V_11 -> V_15 , V_11 -> V_20 ) ;
for ( V_151 = 0 ; V_151 < V_200 ; V_151 ++ ) {
V_126 = V_11 -> V_150 [ V_151 ] ;
if ( ! F_119 ( V_126 ) )
continue;
F_118 ( V_126 ) ;
F_40 ( ! F_201 ( V_126 ) ) ;
F_95 ( V_126 ) ;
F_359 ( & V_126 -> V_145 -> V_456 ) ;
if ( ! F_119 ( V_126 ) ) {
F_360 ( & V_126 -> V_145 -> V_457 ,
F_361 ( V_126 ) ,
V_366 ) ;
}
F_362 ( & V_126 -> V_145 -> V_456 ) ;
F_236 ( V_126 ) ;
F_117 ( V_126 ) ;
}
F_40 ( F_15 ( & V_11 -> V_17 ) == 0 ) ;
}
int F_363 ( struct V_10 * V_11 )
{
unsigned long V_151 ;
unsigned long V_200 ;
int V_458 = 0 ;
F_331 ( V_11 ) ;
V_458 = F_254 ( V_339 , & V_11 -> V_334 ) ;
V_200 = F_147 ( V_11 -> V_15 , V_11 -> V_20 ) ;
F_40 ( F_15 ( & V_11 -> V_17 ) == 0 ) ;
F_40 ( ! F_160 ( V_446 , & V_11 -> V_334 ) ) ;
for ( V_151 = 0 ; V_151 < V_200 ; V_151 ++ )
F_364 ( V_11 -> V_150 [ V_151 ] ) ;
return V_458 ;
}
void F_365 ( struct V_10 * V_11 )
{
unsigned long V_151 ;
struct V_126 * V_126 ;
unsigned long V_200 ;
F_250 ( V_444 , & V_11 -> V_334 ) ;
V_200 = F_147 ( V_11 -> V_15 , V_11 -> V_20 ) ;
for ( V_151 = 0 ; V_151 < V_200 ; V_151 ++ ) {
V_126 = V_11 -> V_150 [ V_151 ] ;
if ( V_126 )
F_171 ( V_126 ) ;
}
}
void F_327 ( struct V_10 * V_11 )
{
unsigned long V_151 ;
struct V_126 * V_126 ;
unsigned long V_200 ;
F_245 ( V_444 , & V_11 -> V_334 ) ;
V_200 = F_147 ( V_11 -> V_15 , V_11 -> V_20 ) ;
for ( V_151 = 0 ; V_151 < V_200 ; V_151 ++ ) {
V_126 = V_11 -> V_150 [ V_151 ] ;
F_129 ( V_126 ) ;
}
}
int F_366 ( struct V_10 * V_11 )
{
return F_160 ( V_444 , & V_11 -> V_334 ) ;
}
int F_367 ( struct V_23 * V_24 ,
struct V_10 * V_11 , int V_109 ,
T_13 * V_284 , int V_175 )
{
unsigned long V_151 ;
struct V_126 * V_126 ;
int V_96 ;
int V_32 = 0 ;
int V_459 = 0 ;
int V_460 = 1 ;
unsigned long V_200 ;
unsigned long V_461 = 0 ;
struct V_43 * V_43 = NULL ;
unsigned long V_216 = 0 ;
if ( F_160 ( V_444 , & V_11 -> V_334 ) )
return 0 ;
V_200 = F_147 ( V_11 -> V_15 , V_11 -> V_20 ) ;
for ( V_151 = 0 ; V_151 < V_200 ; V_151 ++ ) {
V_126 = V_11 -> V_150 [ V_151 ] ;
if ( V_109 == V_462 ) {
if ( ! F_248 ( V_126 ) )
goto V_463;
} else {
F_118 ( V_126 ) ;
}
V_459 ++ ;
}
for ( V_151 = 0 ; V_151 < V_200 ; V_151 ++ ) {
V_126 = V_11 -> V_150 [ V_151 ] ;
if ( ! F_211 ( V_126 ) ) {
V_461 ++ ;
V_460 = 0 ;
}
}
if ( V_460 ) {
F_245 ( V_444 , & V_11 -> V_334 ) ;
goto V_463;
}
F_250 ( V_464 , & V_11 -> V_334 ) ;
V_11 -> V_465 = 0 ;
F_259 ( & V_11 -> V_348 , V_461 ) ;
for ( V_151 = 0 ; V_151 < V_200 ; V_151 ++ ) {
V_126 = V_11 -> V_150 [ V_151 ] ;
if ( ! F_211 ( V_126 ) ) {
if ( V_32 ) {
F_356 ( & V_11 -> V_348 ) ;
F_117 ( V_126 ) ;
continue;
}
F_236 ( V_126 ) ;
V_96 = F_225 ( V_24 , V_126 ,
V_284 , & V_43 ,
V_175 , & V_216 ,
V_351 ) ;
if ( V_96 ) {
V_32 = V_96 ;
F_356 ( & V_11 -> V_348 ) ;
}
} else {
F_117 ( V_126 ) ;
}
}
if ( V_43 ) {
V_96 = F_192 ( V_43 , V_175 , V_216 ) ;
if ( V_96 )
return V_96 ;
}
if ( V_32 || V_109 != V_466 )
return V_32 ;
for ( V_151 = 0 ; V_151 < V_200 ; V_151 ++ ) {
V_126 = V_11 -> V_150 [ V_151 ] ;
F_368 ( V_126 ) ;
if ( ! F_211 ( V_126 ) )
V_32 = - V_153 ;
}
return V_32 ;
V_463:
while ( V_459 > 0 ) {
V_459 -- ;
V_126 = V_11 -> V_150 [ V_459 ] ;
F_117 ( V_126 ) ;
}
return V_32 ;
}
void F_369 ( struct V_10 * V_11 , void * V_467 ,
unsigned long V_15 ,
unsigned long V_20 )
{
T_11 V_289 ;
T_11 V_59 ;
struct V_126 * V_126 ;
char * V_468 ;
char * V_469 = ( char * ) V_467 ;
T_11 V_470 = V_11 -> V_15 & ( ( T_1 ) V_142 - 1 ) ;
unsigned long V_151 = ( V_470 + V_15 ) >> V_124 ;
F_40 ( V_15 > V_11 -> V_20 ) ;
F_40 ( V_15 + V_20 > V_11 -> V_15 + V_11 -> V_20 ) ;
V_59 = ( V_470 + V_15 ) & ( V_142 - 1 ) ;
while ( V_20 > 0 ) {
V_126 = V_11 -> V_150 [ V_151 ] ;
V_289 = F_123 ( V_20 , ( V_142 - V_59 ) ) ;
V_468 = F_325 ( V_126 ) ;
memcpy ( V_469 , V_468 + V_59 , V_289 ) ;
V_469 += V_289 ;
V_20 -= V_289 ;
V_59 = 0 ;
V_151 ++ ;
}
}
int F_370 ( struct V_10 * V_11 , void T_18 * V_467 ,
unsigned long V_15 ,
unsigned long V_20 )
{
T_11 V_289 ;
T_11 V_59 ;
struct V_126 * V_126 ;
char * V_468 ;
char T_18 * V_469 = ( char T_18 * ) V_467 ;
T_11 V_470 = V_11 -> V_15 & ( ( T_1 ) V_142 - 1 ) ;
unsigned long V_151 = ( V_470 + V_15 ) >> V_124 ;
int V_32 = 0 ;
F_40 ( V_15 > V_11 -> V_20 ) ;
F_40 ( V_15 + V_20 > V_11 -> V_15 + V_11 -> V_20 ) ;
V_59 = ( V_470 + V_15 ) & ( V_142 - 1 ) ;
while ( V_20 > 0 ) {
V_126 = V_11 -> V_150 [ V_151 ] ;
V_289 = F_123 ( V_20 , ( V_142 - V_59 ) ) ;
V_468 = F_325 ( V_126 ) ;
if ( F_371 ( V_469 , V_468 + V_59 , V_289 ) ) {
V_32 = - V_471 ;
break;
}
V_469 += V_289 ;
V_20 -= V_289 ;
V_59 = 0 ;
V_151 ++ ;
}
return V_32 ;
}
int F_372 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_472 , char * * V_382 ,
unsigned long * V_473 ,
unsigned long * V_474 )
{
T_11 V_59 = V_15 & ( V_142 - 1 ) ;
char * V_468 ;
struct V_126 * V_63 ;
T_11 V_470 = V_11 -> V_15 & ( ( T_1 ) V_142 - 1 ) ;
unsigned long V_151 = ( V_470 + V_15 ) >> V_124 ;
unsigned long V_475 = ( V_470 + V_15 + V_472 - 1 ) >>
V_124 ;
if ( V_151 != V_475 )
return 1 ;
if ( V_151 == 0 ) {
V_59 = V_470 ;
* V_473 = 0 ;
} else {
V_59 = 0 ;
* V_473 = ( ( T_1 ) V_151 << V_124 ) - V_470 ;
}
if ( V_15 + V_472 > V_11 -> V_20 ) {
F_57 ( 1 , V_84 L_22 ,
V_11 -> V_15 , V_11 -> V_20 , V_15 , V_472 ) ;
return - V_395 ;
}
V_63 = V_11 -> V_150 [ V_151 ] ;
V_468 = F_325 ( V_63 ) ;
* V_382 = V_468 + V_59 ;
* V_474 = V_142 - V_59 ;
return 0 ;
}
int F_373 ( struct V_10 * V_11 , const void * V_476 ,
unsigned long V_15 ,
unsigned long V_20 )
{
T_11 V_289 ;
T_11 V_59 ;
struct V_126 * V_126 ;
char * V_468 ;
char * V_477 = ( char * ) V_476 ;
T_11 V_470 = V_11 -> V_15 & ( ( T_1 ) V_142 - 1 ) ;
unsigned long V_151 = ( V_470 + V_15 ) >> V_124 ;
int V_32 = 0 ;
F_40 ( V_15 > V_11 -> V_20 ) ;
F_40 ( V_15 + V_20 > V_11 -> V_15 + V_11 -> V_20 ) ;
V_59 = ( V_470 + V_15 ) & ( V_142 - 1 ) ;
while ( V_20 > 0 ) {
V_126 = V_11 -> V_150 [ V_151 ] ;
V_289 = F_123 ( V_20 , ( V_142 - V_59 ) ) ;
V_468 = F_325 ( V_126 ) ;
V_32 = memcmp ( V_477 , V_468 + V_59 , V_289 ) ;
if ( V_32 )
break;
V_477 += V_289 ;
V_20 -= V_289 ;
V_59 = 0 ;
V_151 ++ ;
}
return V_32 ;
}
void F_374 ( struct V_10 * V_11 ,
const void * V_478 )
{
char * V_468 ;
F_40 ( ! F_211 ( V_11 -> V_150 [ 0 ] ) ) ;
V_468 = F_325 ( V_11 -> V_150 [ 0 ] ) ;
memcpy ( V_468 + F_24 ( struct V_479 , V_480 ) , V_478 ,
V_481 ) ;
}
void F_375 ( struct V_10 * V_11 , const void * V_478 )
{
char * V_468 ;
F_40 ( ! F_211 ( V_11 -> V_150 [ 0 ] ) ) ;
V_468 = F_325 ( V_11 -> V_150 [ 0 ] ) ;
memcpy ( V_468 + F_24 ( struct V_479 , V_482 ) , V_478 ,
V_481 ) ;
}
void F_376 ( struct V_10 * V_11 , const void * V_478 ,
unsigned long V_15 , unsigned long V_20 )
{
T_11 V_289 ;
T_11 V_59 ;
struct V_126 * V_126 ;
char * V_468 ;
char * V_443 = ( char * ) V_478 ;
T_11 V_470 = V_11 -> V_15 & ( ( T_1 ) V_142 - 1 ) ;
unsigned long V_151 = ( V_470 + V_15 ) >> V_124 ;
F_40 ( V_15 > V_11 -> V_20 ) ;
F_40 ( V_15 + V_20 > V_11 -> V_15 + V_11 -> V_20 ) ;
V_59 = ( V_470 + V_15 ) & ( V_142 - 1 ) ;
while ( V_20 > 0 ) {
V_126 = V_11 -> V_150 [ V_151 ] ;
F_40 ( ! F_211 ( V_126 ) ) ;
V_289 = F_123 ( V_20 , V_142 - V_59 ) ;
V_468 = F_325 ( V_126 ) ;
memcpy ( V_468 + V_59 , V_443 , V_289 ) ;
V_443 += V_289 ;
V_20 -= V_289 ;
V_59 = 0 ;
V_151 ++ ;
}
}
void F_264 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_20 )
{
T_11 V_289 ;
T_11 V_59 ;
struct V_126 * V_126 ;
char * V_468 ;
T_11 V_470 = V_11 -> V_15 & ( ( T_1 ) V_142 - 1 ) ;
unsigned long V_151 = ( V_470 + V_15 ) >> V_124 ;
F_40 ( V_15 > V_11 -> V_20 ) ;
F_40 ( V_15 + V_20 > V_11 -> V_15 + V_11 -> V_20 ) ;
V_59 = ( V_470 + V_15 ) & ( V_142 - 1 ) ;
while ( V_20 > 0 ) {
V_126 = V_11 -> V_150 [ V_151 ] ;
F_40 ( ! F_211 ( V_126 ) ) ;
V_289 = F_123 ( V_20 , V_142 - V_59 ) ;
V_468 = F_325 ( V_126 ) ;
memset ( V_468 + V_59 , 0 , V_289 ) ;
V_20 -= V_289 ;
V_59 = 0 ;
V_151 ++ ;
}
}
void F_377 ( struct V_10 * V_469 ,
struct V_10 * V_443 )
{
int V_151 ;
unsigned V_200 ;
ASSERT ( V_469 -> V_20 == V_443 -> V_20 ) ;
V_200 = F_147 ( V_469 -> V_15 , V_469 -> V_20 ) ;
for ( V_151 = 0 ; V_151 < V_200 ; V_151 ++ )
F_324 ( F_325 ( V_469 -> V_150 [ V_151 ] ) ,
F_325 ( V_443 -> V_150 [ V_151 ] ) ) ;
}
void F_378 ( struct V_10 * V_469 , struct V_10 * V_443 ,
unsigned long V_483 , unsigned long V_484 ,
unsigned long V_20 )
{
T_1 V_485 = V_469 -> V_20 ;
T_11 V_289 ;
T_11 V_59 ;
struct V_126 * V_126 ;
char * V_468 ;
T_11 V_470 = V_469 -> V_15 & ( ( T_1 ) V_142 - 1 ) ;
unsigned long V_151 = ( V_470 + V_483 ) >> V_124 ;
F_40 ( V_443 -> V_20 != V_485 ) ;
V_59 = ( V_470 + V_483 ) &
( V_142 - 1 ) ;
while ( V_20 > 0 ) {
V_126 = V_469 -> V_150 [ V_151 ] ;
F_40 ( ! F_211 ( V_126 ) ) ;
V_289 = F_123 ( V_20 , ( unsigned long ) ( V_142 - V_59 ) ) ;
V_468 = F_325 ( V_126 ) ;
F_369 ( V_443 , V_468 + V_59 , V_484 , V_289 ) ;
V_484 += V_289 ;
V_20 -= V_289 ;
V_59 = 0 ;
V_151 ++ ;
}
}
void F_379 ( T_19 * V_382 , unsigned int V_15 , int V_20 )
{
T_19 * V_63 = V_382 + F_380 ( V_15 ) ;
const unsigned int V_268 = V_15 + V_20 ;
int V_112 = V_486 - ( V_15 % V_486 ) ;
T_19 V_487 = F_381 ( V_15 ) ;
while ( V_20 - V_112 >= 0 ) {
* V_63 |= V_487 ;
V_20 -= V_112 ;
V_112 = V_486 ;
V_487 = ~ 0 ;
V_63 ++ ;
}
if ( V_20 ) {
V_487 &= F_382 ( V_268 ) ;
* V_63 |= V_487 ;
}
}
void F_383 ( T_19 * V_382 , unsigned int V_15 , int V_20 )
{
T_19 * V_63 = V_382 + F_380 ( V_15 ) ;
const unsigned int V_268 = V_15 + V_20 ;
int V_92 = V_486 - ( V_15 % V_486 ) ;
T_19 V_488 = F_381 ( V_15 ) ;
while ( V_20 - V_92 >= 0 ) {
* V_63 &= ~ V_488 ;
V_20 -= V_92 ;
V_92 = V_486 ;
V_488 = ~ 0 ;
V_63 ++ ;
}
if ( V_20 ) {
V_488 &= F_382 ( V_268 ) ;
* V_63 &= ~ V_488 ;
}
}
static inline void F_384 ( struct V_10 * V_11 ,
unsigned long V_15 , unsigned long V_293 ,
unsigned long * F_361 ,
T_11 * F_128 )
{
T_11 V_470 = V_11 -> V_15 & ( ( T_1 ) V_142 - 1 ) ;
T_11 V_489 = F_380 ( V_293 ) ;
T_11 V_59 ;
V_59 = V_470 + V_15 + V_489 ;
* F_361 = V_59 >> V_124 ;
* F_128 = V_59 & ( V_142 - 1 ) ;
}
int F_385 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_293 )
{
T_19 * V_468 ;
struct V_126 * V_126 ;
unsigned long V_151 ;
T_11 V_59 ;
F_384 ( V_11 , V_15 , V_293 , & V_151 , & V_59 ) ;
V_126 = V_11 -> V_150 [ V_151 ] ;
F_40 ( ! F_211 ( V_126 ) ) ;
V_468 = F_325 ( V_126 ) ;
return 1U & ( V_468 [ V_59 ] >> ( V_293 & ( V_486 - 1 ) ) ) ;
}
void F_386 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_490 , unsigned long V_20 )
{
T_19 * V_468 ;
struct V_126 * V_126 ;
unsigned long V_151 ;
T_11 V_59 ;
const unsigned int V_268 = V_490 + V_20 ;
int V_112 = V_486 - ( V_490 % V_486 ) ;
T_19 V_487 = F_381 ( V_490 ) ;
F_384 ( V_11 , V_15 , V_490 , & V_151 , & V_59 ) ;
V_126 = V_11 -> V_150 [ V_151 ] ;
F_40 ( ! F_211 ( V_126 ) ) ;
V_468 = F_325 ( V_126 ) ;
while ( V_20 >= V_112 ) {
V_468 [ V_59 ] |= V_487 ;
V_20 -= V_112 ;
V_112 = V_486 ;
V_487 = ~ 0 ;
if ( ++ V_59 >= V_142 && V_20 > 0 ) {
V_59 = 0 ;
V_126 = V_11 -> V_150 [ ++ V_151 ] ;
F_40 ( ! F_211 ( V_126 ) ) ;
V_468 = F_325 ( V_126 ) ;
}
}
if ( V_20 ) {
V_487 &= F_382 ( V_268 ) ;
V_468 [ V_59 ] |= V_487 ;
}
}
void F_387 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_490 , unsigned long V_20 )
{
T_19 * V_468 ;
struct V_126 * V_126 ;
unsigned long V_151 ;
T_11 V_59 ;
const unsigned int V_268 = V_490 + V_20 ;
int V_92 = V_486 - ( V_490 % V_486 ) ;
T_19 V_488 = F_381 ( V_490 ) ;
F_384 ( V_11 , V_15 , V_490 , & V_151 , & V_59 ) ;
V_126 = V_11 -> V_150 [ V_151 ] ;
F_40 ( ! F_211 ( V_126 ) ) ;
V_468 = F_325 ( V_126 ) ;
while ( V_20 >= V_92 ) {
V_468 [ V_59 ] &= ~ V_488 ;
V_20 -= V_92 ;
V_92 = V_486 ;
V_488 = ~ 0 ;
if ( ++ V_59 >= V_142 && V_20 > 0 ) {
V_59 = 0 ;
V_126 = V_11 -> V_150 [ ++ V_151 ] ;
F_40 ( ! F_211 ( V_126 ) ) ;
V_468 = F_325 ( V_126 ) ;
}
}
if ( V_20 ) {
V_488 &= F_382 ( V_268 ) ;
V_468 [ V_59 ] &= ~ V_488 ;
}
}
static inline bool F_388 ( unsigned long V_443 , unsigned long V_469 , unsigned long V_20 )
{
unsigned long V_491 = ( V_443 > V_469 ) ? V_443 - V_469 : V_469 - V_443 ;
return V_491 < V_20 ;
}
static void F_389 ( struct V_126 * V_492 , struct V_126 * V_493 ,
unsigned long V_494 , unsigned long V_495 ,
unsigned long V_20 )
{
char * V_496 = F_325 ( V_492 ) ;
char * V_497 ;
int V_498 = 0 ;
if ( V_492 != V_493 ) {
V_497 = F_325 ( V_493 ) ;
} else {
V_497 = V_496 ;
if ( F_388 ( V_495 , V_494 , V_20 ) )
V_498 = 1 ;
}
if ( V_498 )
memmove ( V_496 + V_494 , V_497 + V_495 , V_20 ) ;
else
memcpy ( V_496 + V_494 , V_497 + V_495 , V_20 ) ;
}
void F_390 ( struct V_10 * V_469 , unsigned long V_483 ,
unsigned long V_484 , unsigned long V_20 )
{
struct V_36 * V_170 = V_469 -> V_170 ;
T_11 V_289 ;
T_11 V_499 ;
T_11 V_500 ;
T_11 V_470 = V_469 -> V_15 & ( ( T_1 ) V_142 - 1 ) ;
unsigned long V_501 ;
unsigned long V_502 ;
if ( V_484 + V_20 > V_469 -> V_20 ) {
F_175 ( V_170 ,
L_23 ,
V_484 , V_20 , V_469 -> V_20 ) ;
F_19 ( 1 ) ;
}
if ( V_483 + V_20 > V_469 -> V_20 ) {
F_175 ( V_170 ,
L_24 ,
V_483 , V_20 , V_469 -> V_20 ) ;
F_19 ( 1 ) ;
}
while ( V_20 > 0 ) {
V_499 = ( V_470 + V_483 ) &
( V_142 - 1 ) ;
V_500 = ( V_470 + V_484 ) &
( V_142 - 1 ) ;
V_501 = ( V_470 + V_483 ) >> V_124 ;
V_502 = ( V_470 + V_484 ) >> V_124 ;
V_289 = F_123 ( V_20 , ( unsigned long ) ( V_142 -
V_500 ) ) ;
V_289 = F_112 (unsigned long, cur,
(unsigned long)(PAGE_SIZE - dst_off_in_page)) ;
F_389 ( V_469 -> V_150 [ V_501 ] , V_469 -> V_150 [ V_502 ] ,
V_499 , V_500 , V_289 ) ;
V_484 += V_289 ;
V_483 += V_289 ;
V_20 -= V_289 ;
}
}
void F_391 ( struct V_10 * V_469 , unsigned long V_483 ,
unsigned long V_484 , unsigned long V_20 )
{
struct V_36 * V_170 = V_469 -> V_170 ;
T_11 V_289 ;
T_11 V_499 ;
T_11 V_500 ;
unsigned long V_503 = V_483 + V_20 - 1 ;
unsigned long V_504 = V_484 + V_20 - 1 ;
T_11 V_470 = V_469 -> V_15 & ( ( T_1 ) V_142 - 1 ) ;
unsigned long V_501 ;
unsigned long V_502 ;
if ( V_484 + V_20 > V_469 -> V_20 ) {
F_175 ( V_170 ,
L_25 ,
V_484 , V_20 , V_469 -> V_20 ) ;
F_19 ( 1 ) ;
}
if ( V_483 + V_20 > V_469 -> V_20 ) {
F_175 ( V_170 ,
L_26 ,
V_483 , V_20 , V_469 -> V_20 ) ;
F_19 ( 1 ) ;
}
if ( V_483 < V_484 ) {
F_390 ( V_469 , V_483 , V_484 , V_20 ) ;
return;
}
while ( V_20 > 0 ) {
V_501 = ( V_470 + V_503 ) >> V_124 ;
V_502 = ( V_470 + V_504 ) >> V_124 ;
V_499 = ( V_470 + V_503 ) &
( V_142 - 1 ) ;
V_500 = ( V_470 + V_504 ) &
( V_142 - 1 ) ;
V_289 = F_112 (unsigned long, len, src_off_in_page + 1 ) ;
V_289 = F_123 ( V_289 , V_499 + 1 ) ;
F_389 ( V_469 -> V_150 [ V_501 ] , V_469 -> V_150 [ V_502 ] ,
V_499 - V_289 + 1 ,
V_500 - V_289 + 1 , V_289 ) ;
V_503 -= V_289 ;
V_504 -= V_289 ;
V_20 -= V_289 ;
}
}
int F_392 ( struct V_126 * V_126 )
{
struct V_10 * V_11 ;
F_70 ( & V_126 -> V_145 -> V_369 ) ;
if ( ! F_201 ( V_126 ) ) {
F_73 ( & V_126 -> V_145 -> V_369 ) ;
return 1 ;
}
V_11 = (struct V_10 * ) V_126 -> V_202 ;
F_19 ( ! V_11 ) ;
F_70 ( & V_11 -> V_338 ) ;
if ( F_15 ( & V_11 -> V_17 ) != 1 || F_314 ( V_11 ) ) {
F_73 ( & V_11 -> V_338 ) ;
F_73 ( & V_126 -> V_145 -> V_369 ) ;
return 0 ;
}
F_73 ( & V_126 -> V_145 -> V_369 ) ;
if ( ! F_244 ( V_446 , & V_11 -> V_334 ) ) {
F_73 ( & V_11 -> V_338 ) ;
return 0 ;
}
return F_351 ( V_11 ) ;
}
