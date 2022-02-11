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
if ( F_136 ( V_170 , V_173 , V_172 ) ) {
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
F_141 ( V_43 , V_177 -> V_192 ) ;
V_43 -> V_194 = V_195 | V_196 ;
F_142 ( V_43 , V_126 , V_172 , V_174 ) ;
if ( F_143 ( V_43 ) ) {
F_138 ( V_170 ) ;
F_139 ( V_43 ) ;
F_144 ( V_177 , V_197 ) ;
return - V_153 ;
}
F_145 ( V_170 ,
L_8 ,
V_171 , V_15 ,
F_146 ( V_177 -> V_198 ) , V_179 ) ;
F_138 ( V_170 ) ;
F_139 ( V_43 ) ;
return 0 ;
}
int F_147 ( struct V_36 * V_170 ,
struct V_10 * V_11 , int V_175 )
{
T_1 V_15 = V_11 -> V_15 ;
unsigned long V_151 , V_199 = F_148 ( V_11 -> V_15 , V_11 -> V_20 ) ;
int V_32 = 0 ;
if ( F_149 ( V_170 -> V_182 ) )
return - V_200 ;
for ( V_151 = 0 ; V_151 < V_199 ; V_151 ++ ) {
struct V_126 * V_63 = V_11 -> V_150 [ V_151 ] ;
V_32 = F_133 ( V_170 , 0 , V_15 , V_142 , V_15 , V_63 ,
V_15 - F_128 ( V_63 ) , V_175 ) ;
if ( V_32 )
break;
V_15 += V_142 ;
}
return V_32 ;
}
int F_150 ( struct V_36 * V_170 ,
struct V_23 * V_167 ,
struct V_23 * V_158 , T_1 V_15 ,
struct V_126 * V_126 , T_1 V_171 , unsigned int V_174 )
{
T_1 V_201 ;
struct V_162 * V_53 ;
struct V_1 * V_2 ;
int V_202 ;
int V_32 ;
V_201 = 0 ;
V_32 = F_122 ( V_167 , & V_201 , ( T_1 ) - 1 , 1 ,
V_94 , 0 ) ;
if ( ! V_32 )
return 0 ;
V_32 = F_126 ( V_167 , V_15 , & V_53 ) ;
if ( V_32 )
return 0 ;
F_19 ( ! V_53 -> V_203 ) ;
if ( V_53 -> V_204 ) {
F_151 ( V_170 ,
L_9 ,
V_53 -> V_15 ) ;
goto V_107;
}
if ( F_149 ( V_170 -> V_182 ) )
goto V_107;
F_70 ( & V_158 -> V_49 ) ;
V_2 = F_101 ( V_158 ,
V_53 -> V_15 ,
V_121 ) ;
F_73 ( & V_158 -> V_49 ) ;
if ( V_2 && V_2 -> V_15 <= V_53 -> V_15 &&
V_2 -> V_16 >= V_53 -> V_15 + V_53 -> V_20 - 1 ) {
V_202 = F_152 ( V_170 , V_53 -> V_173 ,
V_53 -> V_20 ) ;
if ( V_202 > 1 ) {
F_133 ( V_170 , V_171 , V_15 , V_53 -> V_20 ,
V_53 -> V_173 , V_126 , V_174 ,
V_53 -> V_205 ) ;
}
}
V_107:
F_130 ( V_167 , V_158 , V_53 ) ;
return 0 ;
}
void F_153 ( struct V_206 * V_122 , T_1 V_15 , T_1 V_16 )
{
struct V_23 * V_167 = & V_122 -> V_207 ;
struct V_162 * V_53 ;
struct V_1 * V_2 , * V_13 ;
if ( F_154 ( & V_167 -> V_2 ) )
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
int F_155 ( struct V_122 * V_122 , T_1 V_15 , T_1 V_16 ,
struct V_162 * * V_208 )
{
struct V_36 * V_170 = F_156 ( V_122 -> V_209 ) ;
struct V_162 * V_53 ;
struct V_210 * V_211 ;
struct V_23 * V_167 = & F_121 ( V_122 ) -> V_207 ;
struct V_23 * V_24 = & F_121 ( V_122 ) -> V_158 ;
struct V_212 * V_213 = & F_121 ( V_122 ) -> V_214 ;
int V_32 ;
T_1 V_173 ;
V_32 = F_126 ( V_167 , V_15 , & V_53 ) ;
if ( V_32 ) {
V_53 = F_157 ( sizeof( * V_53 ) , V_120 ) ;
if ( ! V_53 )
return - V_38 ;
V_53 -> V_15 = V_15 ;
V_53 -> V_20 = V_16 - V_15 + 1 ;
V_53 -> V_203 = 0 ;
V_53 -> V_215 = 0 ;
V_53 -> V_204 = 0 ;
F_158 ( & V_213 -> V_49 ) ;
V_211 = F_159 ( V_213 , V_15 , V_53 -> V_20 ) ;
if ( ! V_211 ) {
F_160 ( & V_213 -> V_49 ) ;
F_132 ( V_53 ) ;
return - V_153 ;
}
if ( V_211 -> V_15 > V_15 || V_211 -> V_15 + V_211 -> V_20 <= V_15 ) {
F_161 ( V_211 ) ;
V_211 = NULL ;
}
F_160 ( & V_213 -> V_49 ) ;
if ( ! V_211 ) {
F_132 ( V_53 ) ;
return - V_153 ;
}
V_173 = V_15 - V_211 -> V_15 ;
V_173 = V_211 -> V_216 + V_173 ;
if ( F_162 ( V_217 , & V_211 -> V_7 ) ) {
V_173 = V_211 -> V_216 ;
V_53 -> V_215 = V_218 ;
F_163 ( & V_53 -> V_215 ,
V_211 -> V_219 ) ;
}
F_151 ( V_170 ,
L_10 ,
V_173 , V_15 , V_53 -> V_20 ) ;
V_53 -> V_173 = V_173 ;
F_161 ( V_211 ) ;
V_32 = F_164 ( V_167 , V_15 , V_16 ,
V_121 | V_94 ) ;
if ( V_32 >= 0 )
V_32 = F_125 ( V_167 , V_15 , V_53 ) ;
if ( V_32 >= 0 )
V_32 = F_164 ( V_24 , V_15 , V_16 , V_169 ) ;
if ( V_32 < 0 ) {
F_132 ( V_53 ) ;
return V_32 ;
}
} else {
F_151 ( V_170 ,
L_11 ,
V_53 -> V_173 , V_53 -> V_15 , V_53 -> V_20 ,
V_53 -> V_204 ) ;
}
* V_208 = V_53 ;
return 0 ;
}
bool F_165 ( struct V_122 * V_122 , struct V_43 * V_220 ,
struct V_162 * V_53 , int V_205 )
{
struct V_36 * V_170 = F_156 ( V_122 -> V_209 ) ;
int V_202 ;
V_202 = F_152 ( V_170 , V_53 -> V_173 , V_53 -> V_20 ) ;
if ( V_202 == 1 ) {
F_151 ( V_170 ,
L_12 ,
V_202 , V_53 -> V_203 , V_205 ) ;
return false ;
}
if ( V_220 -> V_221 > 1 ) {
F_19 ( V_53 -> V_204 ) ;
V_53 -> V_204 = 1 ;
V_53 -> V_203 = V_205 ;
} else {
if ( V_53 -> V_204 ) {
F_19 ( V_53 -> V_203 != V_205 ) ;
V_53 -> V_204 = 0 ;
V_53 -> V_203 = 0 ;
}
V_53 -> V_205 = V_205 ;
V_53 -> V_203 ++ ;
if ( V_53 -> V_203 == V_205 )
V_53 -> V_203 ++ ;
}
if ( V_53 -> V_203 > V_202 ) {
F_151 ( V_170 ,
L_13 ,
V_202 , V_53 -> V_203 , V_205 ) ;
return false ;
}
return true ;
}
struct V_43 * F_166 ( struct V_122 * V_122 , struct V_43 * V_220 ,
struct V_162 * V_53 ,
struct V_126 * V_126 , int V_174 , int V_222 ,
T_7 * V_223 , void * V_224 )
{
struct V_36 * V_170 = F_156 ( V_122 -> V_209 ) ;
struct V_43 * V_43 ;
struct V_42 * V_225 ;
struct V_42 * V_180 ;
V_43 = F_134 ( 1 ) ;
V_43 -> V_226 = V_223 ;
V_43 -> V_185 . V_191 = V_53 -> V_173 >> 9 ;
F_141 ( V_43 , V_170 -> V_227 -> V_228 ) ;
V_43 -> V_185 . V_186 = 0 ;
V_43 -> V_229 = V_224 ;
V_225 = V_42 ( V_220 ) ;
if ( V_225 -> V_230 ) {
T_8 V_231 = F_167 ( V_170 -> V_232 ) ;
V_180 = V_42 ( V_43 ) ;
V_180 -> V_230 = V_180 -> V_233 ;
V_222 *= V_231 ;
memcpy ( V_180 -> V_230 , V_225 -> V_230 + V_222 ,
V_231 ) ;
}
F_142 ( V_43 , V_126 , V_53 -> V_20 , V_174 ) ;
return V_43 ;
}
static int F_168 ( struct V_43 * V_220 , T_1 V_234 ,
struct V_126 * V_126 , T_1 V_15 , T_1 V_16 ,
int V_205 )
{
struct V_162 * V_53 ;
struct V_122 * V_122 = V_126 -> V_145 -> V_235 ;
struct V_23 * V_24 = & F_121 ( V_122 ) -> V_158 ;
struct V_23 * V_167 = & F_121 ( V_122 ) -> V_207 ;
struct V_43 * V_43 ;
int V_236 = 0 ;
T_9 V_237 ;
int V_32 ;
F_19 ( F_169 ( V_220 ) == V_195 ) ;
V_32 = F_155 ( V_122 , V_15 , V_16 , & V_53 ) ;
if ( V_32 )
return V_32 ;
if ( ! F_165 ( V_122 , V_220 , V_53 ,
V_205 ) ) {
F_130 ( V_167 , V_24 , V_53 ) ;
return - V_153 ;
}
if ( V_220 -> V_221 > 1 )
V_236 |= V_238 ;
V_234 >>= V_122 -> V_209 -> V_239 ;
V_43 = F_166 ( V_122 , V_220 , V_53 , V_126 ,
V_15 - F_128 ( V_126 ) ,
( int ) V_234 , V_220 -> V_226 ,
NULL ) ;
F_170 ( V_43 , V_240 , V_236 ) ;
F_151 ( F_156 ( V_122 -> V_209 ) ,
L_14 ,
V_236 , V_53 -> V_203 , V_53 -> V_204 ) ;
V_237 = V_24 -> V_25 -> V_241 ( V_24 -> V_27 , V_43 , V_53 -> V_203 ,
V_53 -> V_215 , 0 ) ;
if ( V_237 ) {
F_130 ( V_167 , V_24 , V_53 ) ;
F_139 ( V_43 ) ;
V_32 = F_171 ( V_237 ) ;
}
return V_32 ;
}
void F_172 ( struct V_126 * V_126 , int V_96 , T_1 V_15 , T_1 V_16 )
{
int V_242 = ( V_96 == 0 ) ;
struct V_23 * V_24 ;
int V_32 = 0 ;
V_24 = & F_121 ( V_126 -> V_145 -> V_235 ) -> V_158 ;
if ( V_24 -> V_25 && V_24 -> V_25 -> V_243 )
V_24 -> V_25 -> V_243 ( V_126 , V_15 , V_16 , NULL ,
V_242 ) ;
if ( ! V_242 ) {
F_173 ( V_126 ) ;
F_115 ( V_126 ) ;
V_32 = V_96 < 0 ? V_96 : - V_153 ;
F_110 ( V_126 -> V_145 , V_32 ) ;
}
}
static void F_174 ( struct V_43 * V_43 )
{
int error = F_171 ( V_43 -> V_244 ) ;
struct V_245 * V_246 ;
T_1 V_15 ;
T_1 V_16 ;
int V_151 ;
ASSERT ( ! F_175 ( V_43 , V_247 ) ) ;
F_176 (bvec, bio, i) {
struct V_126 * V_126 = V_246 -> V_248 ;
struct V_122 * V_122 = V_126 -> V_145 -> V_235 ;
struct V_36 * V_170 = F_156 ( V_122 -> V_209 ) ;
if ( V_246 -> V_249 || V_246 -> V_250 != V_142 ) {
if ( V_246 -> V_249 + V_246 -> V_250 != V_142 )
F_177 ( V_170 ,
L_15 ,
V_246 -> V_249 , V_246 -> V_250 ) ;
else
F_178 ( V_170 ,
L_16 ,
V_246 -> V_249 , V_246 -> V_250 ) ;
}
V_15 = F_128 ( V_126 ) ;
V_16 = V_15 + V_246 -> V_249 + V_246 -> V_250 - 1 ;
F_172 ( V_126 , error , V_15 , V_16 ) ;
F_116 ( V_126 ) ;
}
F_139 ( V_43 ) ;
}
static void
F_179 ( struct V_23 * V_24 , T_1 V_15 , T_1 V_20 ,
int V_242 )
{
struct V_1 * V_99 = NULL ;
T_1 V_16 = V_15 + V_20 - 1 ;
if ( V_242 && V_24 -> V_251 )
F_180 ( V_24 , V_15 , V_16 , & V_99 , V_35 ) ;
F_109 ( V_24 , V_15 , V_16 , & V_99 , V_35 ) ;
}
static void F_181 ( struct V_43 * V_43 )
{
struct V_245 * V_246 ;
int V_242 = ! V_43 -> V_244 ;
struct V_42 * V_252 = V_42 ( V_43 ) ;
struct V_23 * V_24 , * V_167 ;
T_1 V_59 = 0 ;
T_1 V_15 ;
T_1 V_16 ;
T_1 V_20 ;
T_1 V_253 = 0 ;
T_1 V_254 = 0 ;
int V_255 ;
int V_32 ;
int V_151 ;
ASSERT ( ! F_175 ( V_43 , V_247 ) ) ;
F_176 (bvec, bio, i) {
struct V_126 * V_126 = V_246 -> V_248 ;
struct V_122 * V_122 = V_126 -> V_145 -> V_235 ;
struct V_36 * V_170 = F_156 ( V_122 -> V_209 ) ;
F_151 ( V_170 ,
L_17 ,
( T_1 ) V_43 -> V_185 . V_191 , V_43 -> V_244 ,
V_252 -> V_175 ) ;
V_24 = & F_121 ( V_122 ) -> V_158 ;
V_167 = & F_121 ( V_122 ) -> V_207 ;
if ( V_246 -> V_249 || V_246 -> V_250 != V_142 ) {
if ( V_246 -> V_249 + V_246 -> V_250 != V_142 )
F_177 ( V_170 ,
L_18 ,
V_246 -> V_249 , V_246 -> V_250 ) ;
else
F_178 ( V_170 ,
L_19 ,
V_246 -> V_249 , V_246 -> V_250 ) ;
}
V_15 = F_128 ( V_126 ) ;
V_16 = V_15 + V_246 -> V_249 + V_246 -> V_250 - 1 ;
V_20 = V_246 -> V_250 ;
V_255 = V_252 -> V_175 ;
if ( F_182 ( V_242 && V_24 -> V_25 ) ) {
V_32 = V_24 -> V_25 -> V_256 ( V_252 , V_59 ,
V_126 , V_15 , V_16 ,
V_255 ) ;
if ( V_32 )
V_242 = 0 ;
else
F_150 ( F_121 ( V_122 ) -> V_57 -> V_170 ,
V_167 , V_24 , V_15 ,
V_126 ,
F_183 ( F_121 ( V_122 ) ) , 0 ) ;
}
if ( F_182 ( V_242 ) )
goto V_257;
if ( V_24 -> V_25 ) {
V_32 = V_24 -> V_25 -> V_258 ( V_126 , V_255 ) ;
if ( V_32 == - V_140 ) {
V_32 = F_168 ( V_43 , V_59 , V_126 ,
V_15 , V_16 , V_255 ) ;
if ( V_32 == 0 ) {
V_242 = ! V_43 -> V_244 ;
V_59 += V_20 ;
continue;
}
}
ASSERT ( V_32 == - V_153 ) ;
}
V_257:
if ( F_182 ( V_242 ) ) {
T_10 V_259 = F_184 ( V_122 ) ;
T_6 V_125 = V_259 >> V_124 ;
unsigned V_260 ;
V_260 = V_259 & ( V_142 - 1 ) ;
if ( V_126 -> V_123 == V_125 && V_260 )
F_185 ( V_126 , V_260 , V_142 ) ;
F_129 ( V_126 ) ;
} else {
F_173 ( V_126 ) ;
F_115 ( V_126 ) ;
}
F_117 ( V_126 ) ;
V_59 += V_20 ;
if ( F_186 ( ! V_242 ) ) {
if ( V_254 ) {
F_179 ( V_24 ,
V_253 ,
V_254 , 1 ) ;
V_253 = 0 ;
V_254 = 0 ;
}
F_179 ( V_24 , V_15 ,
V_16 - V_15 + 1 , 0 ) ;
} else if ( ! V_254 ) {
V_253 = V_15 ;
V_254 = V_16 + 1 - V_15 ;
} else if ( V_253 + V_254 == V_15 ) {
V_254 += V_16 + 1 - V_15 ;
} else {
F_179 ( V_24 , V_253 ,
V_254 , V_242 ) ;
V_253 = V_15 ;
V_254 = V_16 + 1 - V_15 ;
}
}
if ( V_254 )
F_179 ( V_24 , V_253 , V_254 ,
V_242 ) ;
if ( V_252 -> V_261 )
V_252 -> V_261 ( V_252 , F_171 ( V_43 -> V_244 ) ) ;
F_139 ( V_43 ) ;
}
static inline void F_187 ( struct V_42 * V_180 )
{
memset ( V_180 , 0 , F_24 ( struct V_42 , V_43 ) ) ;
}
struct V_43 * F_188 ( struct V_262 * V_192 , T_1 V_263 )
{
struct V_43 * V_43 ;
V_43 = F_189 ( V_120 , V_264 , V_40 ) ;
F_141 ( V_43 , V_192 ) ;
V_43 -> V_185 . V_191 = V_263 >> 9 ;
F_187 ( V_42 ( V_43 ) ) ;
return V_43 ;
}
struct V_43 * F_190 ( struct V_43 * V_43 )
{
struct V_42 * V_180 ;
struct V_43 * V_5 ;
V_5 = F_191 ( V_43 , V_120 , V_40 ) ;
V_180 = V_42 ( V_5 ) ;
F_187 ( V_180 ) ;
V_180 -> V_265 = V_43 -> V_185 ;
return V_5 ;
}
struct V_43 * F_134 ( unsigned int V_266 )
{
struct V_43 * V_43 ;
V_43 = F_189 ( V_120 , V_266 , V_40 ) ;
F_187 ( V_42 ( V_43 ) ) ;
return V_43 ;
}
struct V_43 * F_192 ( struct V_43 * V_87 , int V_59 , int V_267 )
{
struct V_43 * V_43 ;
struct V_42 * V_180 ;
V_43 = F_191 ( V_87 , V_120 , V_40 ) ;
ASSERT ( V_43 ) ;
V_180 = V_42 ( V_43 ) ;
F_187 ( V_180 ) ;
F_193 ( V_43 , V_59 >> 9 , V_267 >> 9 ) ;
V_180 -> V_265 = V_43 -> V_185 ;
return V_43 ;
}
static int T_4 F_194 ( struct V_43 * V_43 , int V_175 ,
unsigned long V_215 )
{
T_9 V_32 = 0 ;
struct V_245 * V_246 = V_43 -> V_268 + V_43 -> V_221 - 1 ;
struct V_126 * V_126 = V_246 -> V_248 ;
struct V_23 * V_24 = V_43 -> V_229 ;
T_1 V_15 ;
V_15 = F_128 ( V_126 ) + V_246 -> V_249 ;
V_43 -> V_229 = NULL ;
F_195 ( V_43 ) ;
if ( V_24 -> V_25 )
V_32 = V_24 -> V_25 -> V_241 ( V_24 -> V_27 , V_43 ,
V_175 , V_215 , V_15 ) ;
else
F_196 ( V_43 ) ;
F_139 ( V_43 ) ;
return F_171 ( V_32 ) ;
}
static int F_197 ( struct V_23 * V_24 , struct V_126 * V_126 ,
unsigned long V_59 , T_11 V_267 , struct V_43 * V_43 ,
unsigned long V_215 )
{
int V_32 = 0 ;
if ( V_24 -> V_25 )
V_32 = V_24 -> V_25 -> V_269 ( V_126 , V_59 , V_267 , V_43 ,
V_215 ) ;
return V_32 ;
}
static int F_198 ( unsigned int V_270 , struct V_23 * V_24 ,
struct V_271 * V_272 ,
struct V_126 * V_126 , T_12 V_179 ,
T_11 V_267 , unsigned long V_59 ,
struct V_262 * V_192 ,
struct V_43 * * V_273 ,
T_7 V_274 ,
int V_175 ,
unsigned long V_275 ,
unsigned long V_215 ,
bool V_276 )
{
int V_32 = 0 ;
struct V_43 * V_43 ;
int V_160 = 0 ;
int V_277 = V_275 & V_218 ;
T_11 V_278 = F_112 ( T_11 , V_267 , V_142 ) ;
if ( V_273 && * V_273 ) {
V_43 = * V_273 ;
if ( V_277 )
V_160 = V_43 -> V_185 . V_191 == V_179 ;
else
V_160 = F_199 ( V_43 ) == V_179 ;
if ( V_275 != V_215 || ! V_160 ||
V_276 ||
F_197 ( V_24 , V_126 , V_59 , V_278 , V_43 , V_215 ) ||
F_142 ( V_43 , V_126 , V_278 , V_59 ) < V_278 ) {
V_32 = F_194 ( V_43 , V_175 , V_275 ) ;
if ( V_32 < 0 ) {
* V_273 = NULL ;
return V_32 ;
}
V_43 = NULL ;
} else {
if ( V_272 )
F_200 ( V_272 , V_126 , V_278 ) ;
return 0 ;
}
}
V_43 = F_188 ( V_192 , ( T_1 ) V_179 << 9 ) ;
F_142 ( V_43 , V_126 , V_278 , V_59 ) ;
V_43 -> V_226 = V_274 ;
V_43 -> V_229 = V_24 ;
V_43 -> V_279 = V_126 -> V_145 -> V_235 -> V_280 ;
V_43 -> V_194 = V_270 ;
if ( V_272 ) {
F_201 ( V_272 , V_43 ) ;
F_200 ( V_272 , V_126 , V_278 ) ;
}
if ( V_273 )
* V_273 = V_43 ;
else
V_32 = F_194 ( V_43 , V_175 , V_215 ) ;
return V_32 ;
}
static void F_202 ( struct V_10 * V_11 ,
struct V_126 * V_126 )
{
if ( ! F_203 ( V_126 ) ) {
F_204 ( V_126 ) ;
F_205 ( V_126 ) ;
F_206 ( V_126 , ( unsigned long ) V_11 ) ;
} else {
F_40 ( V_126 -> V_201 != ( unsigned long ) V_11 ) ;
}
}
void F_207 ( struct V_126 * V_126 )
{
if ( ! F_203 ( V_126 ) ) {
F_204 ( V_126 ) ;
F_205 ( V_126 ) ;
F_206 ( V_126 , V_281 ) ;
}
}
static struct V_210 *
F_208 ( struct V_122 * V_122 , struct V_126 * V_126 , T_11 V_174 ,
T_1 V_15 , T_1 V_20 , T_13 * V_282 ,
struct V_210 * * V_283 )
{
struct V_210 * V_211 ;
if ( V_283 && * V_283 ) {
V_211 = * V_283 ;
if ( F_209 ( V_211 ) && V_15 >= V_211 -> V_15 &&
V_15 < F_210 ( V_211 ) ) {
F_81 ( & V_211 -> V_17 ) ;
return V_211 ;
}
F_161 ( V_211 ) ;
* V_283 = NULL ;
}
V_211 = V_282 ( F_121 ( V_122 ) , V_126 , V_174 , V_15 , V_20 , 0 ) ;
if ( V_283 && ! F_211 ( V_211 ) ) {
F_19 ( * V_283 ) ;
F_81 ( & V_211 -> V_17 ) ;
* V_283 = V_211 ;
}
return V_211 ;
}
static int F_212 ( struct V_23 * V_24 ,
struct V_126 * V_126 ,
T_13 * V_282 ,
struct V_210 * * V_283 ,
struct V_43 * * V_43 , int V_175 ,
unsigned long * V_215 , unsigned int V_284 ,
T_1 * V_285 )
{
struct V_122 * V_122 = V_126 -> V_145 -> V_235 ;
T_1 V_15 = F_128 ( V_126 ) ;
T_1 V_286 = V_15 + V_142 - 1 ;
T_1 V_16 ;
T_1 V_287 = V_15 ;
T_1 V_288 ;
T_1 V_289 = F_184 ( V_122 ) ;
T_1 V_216 ;
T_1 V_290 ;
T_12 V_179 ;
struct V_210 * V_211 ;
struct V_262 * V_192 ;
int V_32 = 0 ;
int V_291 = 0 ;
T_11 V_174 = 0 ;
T_11 V_292 ;
T_11 V_293 ;
T_11 V_294 = V_122 -> V_209 -> V_295 ;
unsigned long V_296 = 0 ;
F_207 ( V_126 ) ;
V_16 = V_286 ;
if ( ! F_213 ( V_126 ) ) {
if ( F_214 ( V_126 ) == 0 ) {
F_19 ( V_294 != V_142 ) ;
F_215 ( V_24 , V_15 , V_16 ) ;
goto V_107;
}
}
if ( V_126 -> V_123 == V_289 >> V_124 ) {
char * V_297 ;
T_11 V_298 = V_289 & ( V_142 - 1 ) ;
if ( V_298 ) {
V_292 = V_142 - V_298 ;
V_297 = F_216 ( V_126 ) ;
memset ( V_297 + V_298 , 0 , V_292 ) ;
F_217 ( V_126 ) ;
F_218 ( V_297 ) ;
}
}
while ( V_287 <= V_16 ) {
bool V_276 = false ;
if ( V_287 >= V_289 ) {
char * V_297 ;
struct V_1 * V_99 = NULL ;
V_292 = V_142 - V_174 ;
V_297 = F_216 ( V_126 ) ;
memset ( V_297 + V_174 , 0 , V_292 ) ;
F_217 ( V_126 ) ;
F_218 ( V_297 ) ;
F_180 ( V_24 , V_287 , V_287 + V_292 - 1 ,
& V_99 , V_120 ) ;
F_109 ( V_24 , V_287 ,
V_287 + V_292 - 1 ,
& V_99 , V_120 ) ;
break;
}
V_211 = F_208 ( V_122 , V_126 , V_174 , V_287 ,
V_16 - V_287 + 1 , V_282 , V_283 ) ;
if ( F_211 ( V_211 ) ) {
F_115 ( V_126 ) ;
F_215 ( V_24 , V_287 , V_16 ) ;
break;
}
V_288 = V_287 - V_211 -> V_15 ;
F_19 ( F_210 ( V_211 ) <= V_287 ) ;
F_19 ( V_16 < V_287 ) ;
if ( F_162 ( V_217 , & V_211 -> V_7 ) ) {
V_296 |= V_218 ;
F_163 ( & V_296 ,
V_211 -> V_219 ) ;
}
V_292 = F_123 ( F_210 ( V_211 ) - V_287 , V_16 - V_287 + 1 ) ;
V_290 = F_123 ( F_210 ( V_211 ) - 1 , V_16 ) ;
V_292 = F_219 ( V_292 , V_294 ) ;
if ( V_296 & V_218 ) {
V_293 = V_211 -> V_299 ;
V_179 = V_211 -> V_216 >> 9 ;
} else {
V_179 = ( V_211 -> V_216 + V_288 ) >> 9 ;
V_293 = V_292 ;
}
V_192 = V_211 -> V_192 ;
V_216 = V_211 -> V_216 ;
if ( F_162 ( V_300 , & V_211 -> V_7 ) )
V_216 = V_301 ;
if ( F_162 ( V_217 , & V_211 -> V_7 ) &&
V_285 && * V_285 != ( T_1 ) - 1 &&
* V_285 != V_211 -> V_302 )
V_276 = true ;
if ( V_285 )
* V_285 = V_211 -> V_302 ;
F_161 ( V_211 ) ;
V_211 = NULL ;
if ( V_216 == V_301 ) {
char * V_297 ;
struct V_1 * V_99 = NULL ;
V_297 = F_216 ( V_126 ) ;
memset ( V_297 + V_174 , 0 , V_292 ) ;
F_217 ( V_126 ) ;
F_218 ( V_297 ) ;
F_180 ( V_24 , V_287 , V_287 + V_292 - 1 ,
& V_99 , V_120 ) ;
F_109 ( V_24 , V_287 ,
V_287 + V_292 - 1 ,
& V_99 , V_120 ) ;
V_287 = V_287 + V_292 ;
V_174 += V_292 ;
continue;
}
if ( F_108 ( V_24 , V_287 , V_290 ,
V_166 , 1 , NULL ) ) {
F_127 ( V_24 , V_126 ) ;
F_215 ( V_24 , V_287 , V_287 + V_292 - 1 ) ;
V_287 = V_287 + V_292 ;
V_174 += V_292 ;
continue;
}
if ( V_216 == V_303 ) {
F_115 ( V_126 ) ;
F_215 ( V_24 , V_287 , V_287 + V_292 - 1 ) ;
V_287 = V_287 + V_292 ;
V_174 += V_292 ;
continue;
}
V_32 = F_198 ( V_240 | V_284 , V_24 , NULL ,
V_126 , V_179 , V_293 , V_174 ,
V_192 , V_43 ,
F_181 , V_175 ,
* V_215 ,
V_296 ,
V_276 ) ;
if ( ! V_32 ) {
V_291 ++ ;
* V_215 = V_296 ;
} else {
F_115 ( V_126 ) ;
F_215 ( V_24 , V_287 , V_287 + V_292 - 1 ) ;
goto V_107;
}
V_287 = V_287 + V_292 ;
V_174 += V_292 ;
}
V_107:
if ( ! V_291 ) {
if ( ! F_220 ( V_126 ) )
F_129 ( V_126 ) ;
F_117 ( V_126 ) ;
}
return V_32 ;
}
static inline void F_221 ( struct V_23 * V_24 ,
struct V_126 * V_150 [] , int V_148 ,
T_1 V_15 , T_1 V_16 ,
T_13 * V_282 ,
struct V_210 * * V_283 ,
struct V_43 * * V_43 , int V_175 ,
unsigned long * V_215 ,
T_1 * V_285 )
{
struct V_122 * V_122 ;
struct V_304 * V_305 ;
int V_123 ;
V_122 = V_150 [ 0 ] -> V_145 -> V_235 ;
while ( 1 ) {
F_222 ( V_24 , V_15 , V_16 ) ;
V_305 = F_223 ( F_121 ( V_122 ) , V_15 ,
V_16 - V_15 + 1 ) ;
if ( ! V_305 )
break;
F_215 ( V_24 , V_15 , V_16 ) ;
F_224 ( V_122 , V_305 , 1 ) ;
F_225 ( V_305 ) ;
}
for ( V_123 = 0 ; V_123 < V_148 ; V_123 ++ ) {
F_212 ( V_24 , V_150 [ V_123 ] , V_282 , V_283 , V_43 ,
V_175 , V_215 , 0 , V_285 ) ;
F_96 ( V_150 [ V_123 ] ) ;
}
}
static void F_226 ( struct V_23 * V_24 ,
struct V_126 * V_150 [] ,
int V_148 , T_13 * V_282 ,
struct V_210 * * V_283 ,
struct V_43 * * V_43 , int V_175 ,
unsigned long * V_215 ,
T_1 * V_285 )
{
T_1 V_15 = 0 ;
T_1 V_16 = 0 ;
T_1 V_306 ;
int V_123 ;
int V_307 = 0 ;
for ( V_123 = 0 ; V_123 < V_148 ; V_123 ++ ) {
V_306 = F_128 ( V_150 [ V_123 ] ) ;
if ( ! V_16 ) {
V_15 = V_306 ;
V_16 = V_15 + V_142 - 1 ;
V_307 = V_123 ;
} else if ( V_16 + 1 == V_306 ) {
V_16 += V_142 ;
} else {
F_221 ( V_24 , & V_150 [ V_307 ] ,
V_123 - V_307 , V_15 ,
V_16 , V_282 , V_283 ,
V_43 , V_175 , V_215 ,
V_285 ) ;
V_15 = V_306 ;
V_16 = V_15 + V_142 - 1 ;
V_307 = V_123 ;
}
}
if ( V_16 )
F_221 ( V_24 , & V_150 [ V_307 ] ,
V_123 - V_307 , V_15 ,
V_16 , V_282 , V_283 , V_43 ,
V_175 , V_215 ,
V_285 ) ;
}
static int F_227 ( struct V_23 * V_24 ,
struct V_126 * V_126 ,
T_13 * V_282 ,
struct V_43 * * V_43 , int V_175 ,
unsigned long * V_215 ,
unsigned int V_284 )
{
struct V_122 * V_122 = V_126 -> V_145 -> V_235 ;
struct V_304 * V_305 ;
T_1 V_15 = F_128 ( V_126 ) ;
T_1 V_16 = V_15 + V_142 - 1 ;
int V_32 ;
while ( 1 ) {
F_222 ( V_24 , V_15 , V_16 ) ;
V_305 = F_223 ( F_121 ( V_122 ) , V_15 ,
V_142 ) ;
if ( ! V_305 )
break;
F_215 ( V_24 , V_15 , V_16 ) ;
F_224 ( V_122 , V_305 , 1 ) ;
F_225 ( V_305 ) ;
}
V_32 = F_212 ( V_24 , V_126 , V_282 , NULL , V_43 , V_175 ,
V_215 , V_284 , NULL ) ;
return V_32 ;
}
int F_228 ( struct V_23 * V_24 , struct V_126 * V_126 ,
T_13 * V_282 , int V_175 )
{
struct V_43 * V_43 = NULL ;
unsigned long V_215 = 0 ;
int V_32 ;
V_32 = F_227 ( V_24 , V_126 , V_282 , & V_43 , V_175 ,
& V_215 , 0 ) ;
if ( V_43 )
V_32 = F_194 ( V_43 , V_175 , V_215 ) ;
return V_32 ;
}
static void F_229 ( struct V_271 * V_272 ,
unsigned long V_308 )
{
V_272 -> V_309 -= V_308 ;
}
static T_14 int F_230 ( struct V_122 * V_122 ,
struct V_126 * V_126 , struct V_271 * V_272 ,
struct V_310 * V_311 ,
T_1 V_136 ,
unsigned long * V_308 )
{
struct V_23 * V_24 = V_311 -> V_24 ;
T_1 V_286 = V_136 + V_142 - 1 ;
T_1 V_312 ;
T_1 V_313 = 0 ;
T_1 V_137 = 0 ;
int V_32 ;
int V_314 = 0 ;
if ( V_311 -> V_315 || ! V_24 -> V_25 || ! V_24 -> V_25 -> V_316 )
return 0 ;
while ( V_137 < V_286 ) {
V_312 = F_107 ( V_122 , V_24 ,
V_126 ,
& V_136 ,
& V_137 ,
V_317 ) ;
if ( V_312 == 0 ) {
V_136 = V_137 + 1 ;
continue;
}
V_32 = V_24 -> V_25 -> V_316 ( V_122 , V_126 ,
V_136 ,
V_137 ,
& V_314 ,
V_308 ) ;
if ( V_32 ) {
F_115 ( V_126 ) ;
V_32 = V_32 < 0 ? V_32 : - V_153 ;
goto V_318;
}
V_313 += ( V_137 - V_136 +
V_142 ) >> V_124 ;
V_136 = V_137 + 1 ;
}
if ( V_272 -> V_309 < V_313 ) {
int V_319 = 8192 ;
if ( V_313 < V_319 * 2 )
V_319 = V_313 ;
V_272 -> V_309 = F_112 ( T_1 , V_313 ,
V_319 ) ;
}
if ( V_314 ) {
V_272 -> V_309 -= * V_308 ;
return 1 ;
}
V_32 = 0 ;
V_318:
return V_32 ;
}
static T_14 int F_231 ( struct V_122 * V_122 ,
struct V_126 * V_126 ,
struct V_271 * V_272 ,
struct V_310 * V_311 ,
T_10 V_259 ,
unsigned long V_308 ,
unsigned int V_320 , int * V_321 )
{
struct V_23 * V_24 = V_311 -> V_24 ;
T_1 V_15 = F_128 ( V_126 ) ;
T_1 V_286 = V_15 + V_142 - 1 ;
T_1 V_16 ;
T_1 V_287 = V_15 ;
T_1 V_288 ;
T_1 V_216 ;
T_1 V_292 ;
T_12 V_179 ;
struct V_210 * V_211 ;
struct V_262 * V_192 ;
T_11 V_174 = 0 ;
T_11 V_294 ;
int V_32 = 0 ;
int V_291 = 0 ;
bool V_322 ;
if ( V_24 -> V_25 && V_24 -> V_25 -> V_323 ) {
V_32 = V_24 -> V_25 -> V_323 ( V_126 , V_15 ,
V_286 ) ;
if ( V_32 ) {
if ( V_32 == - V_324 )
V_272 -> V_325 ++ ;
else
F_232 ( V_272 , V_126 ) ;
F_229 ( V_272 , V_308 ) ;
F_117 ( V_126 ) ;
return 1 ;
}
}
F_229 ( V_272 , V_308 + 1 ) ;
V_16 = V_286 ;
if ( V_259 <= V_15 ) {
if ( V_24 -> V_25 && V_24 -> V_25 -> V_243 )
V_24 -> V_25 -> V_243 ( V_126 , V_15 ,
V_286 , NULL , 1 ) ;
goto V_318;
}
V_294 = V_122 -> V_209 -> V_295 ;
while ( V_287 <= V_16 ) {
T_1 V_326 ;
if ( V_287 >= V_259 ) {
if ( V_24 -> V_25 && V_24 -> V_25 -> V_243 )
V_24 -> V_25 -> V_243 ( V_126 , V_287 ,
V_286 , NULL , 1 ) ;
break;
}
V_211 = V_311 -> V_282 ( F_121 ( V_122 ) , V_126 , V_174 , V_287 ,
V_16 - V_287 + 1 , 1 ) ;
if ( F_211 ( V_211 ) ) {
F_115 ( V_126 ) ;
V_32 = F_233 ( V_211 ) ;
break;
}
V_288 = V_287 - V_211 -> V_15 ;
V_326 = F_210 ( V_211 ) ;
F_19 ( V_326 <= V_287 ) ;
F_19 ( V_16 < V_287 ) ;
V_292 = F_123 ( V_326 - V_287 , V_16 - V_287 + 1 ) ;
V_292 = F_219 ( V_292 , V_294 ) ;
V_179 = ( V_211 -> V_216 + V_288 ) >> 9 ;
V_192 = V_211 -> V_192 ;
V_216 = V_211 -> V_216 ;
V_322 = F_162 ( V_217 , & V_211 -> V_7 ) ;
F_161 ( V_211 ) ;
V_211 = NULL ;
if ( V_322 || V_216 == V_301 ||
V_216 == V_303 ) {
if ( ! V_322 && V_24 -> V_25 &&
V_24 -> V_25 -> V_243 )
V_24 -> V_25 -> V_243 ( V_126 , V_287 ,
V_287 + V_292 - 1 ,
NULL , 1 ) ;
else if ( V_322 ) {
V_291 ++ ;
}
V_287 += V_292 ;
V_174 += V_292 ;
continue;
}
F_100 ( V_24 , V_287 , V_287 + V_292 - 1 ) ;
if ( ! F_234 ( V_126 ) ) {
F_177 ( F_121 ( V_122 ) -> V_57 -> V_170 ,
L_20 ,
V_126 -> V_123 , V_287 , V_16 ) ;
}
V_32 = F_198 ( V_195 | V_320 , V_24 , V_272 ,
V_126 , V_179 , V_292 , V_174 ,
V_192 , & V_311 -> V_43 ,
F_174 ,
0 , 0 , 0 , false ) ;
if ( V_32 ) {
F_115 ( V_126 ) ;
if ( F_234 ( V_126 ) )
F_116 ( V_126 ) ;
}
V_287 = V_287 + V_292 ;
V_174 += V_292 ;
V_291 ++ ;
}
V_318:
* V_321 = V_291 ;
return V_32 ;
}
static int F_235 ( struct V_126 * V_126 , struct V_271 * V_272 ,
void * V_224 )
{
struct V_122 * V_122 = V_126 -> V_145 -> V_235 ;
struct V_310 * V_311 = V_224 ;
T_1 V_15 = F_128 ( V_126 ) ;
T_1 V_286 = V_15 + V_142 - 1 ;
int V_32 ;
int V_291 = 0 ;
T_11 V_174 = 0 ;
T_10 V_259 = F_184 ( V_122 ) ;
unsigned long V_125 = V_259 >> V_124 ;
unsigned int V_320 = 0 ;
unsigned long V_308 = 0 ;
V_320 = F_236 ( V_272 ) ;
F_237 ( V_126 , V_122 , V_272 ) ;
F_40 ( ! F_238 ( V_126 ) ) ;
F_239 ( V_126 ) ;
V_174 = V_259 & ( V_142 - 1 ) ;
if ( V_126 -> V_123 > V_125 ||
( V_126 -> V_123 == V_125 && ! V_174 ) ) {
V_126 -> V_145 -> V_327 -> V_328 ( V_126 , 0 , V_142 ) ;
F_117 ( V_126 ) ;
return 0 ;
}
if ( V_126 -> V_123 == V_125 ) {
char * V_297 ;
V_297 = F_216 ( V_126 ) ;
memset ( V_297 + V_174 , 0 ,
V_142 - V_174 ) ;
F_218 ( V_297 ) ;
F_217 ( V_126 ) ;
}
V_174 = 0 ;
F_207 ( V_126 ) ;
V_32 = F_230 ( V_122 , V_126 , V_272 , V_311 , V_15 , & V_308 ) ;
if ( V_32 == 1 )
goto V_329;
if ( V_32 )
goto V_318;
V_32 = F_231 ( V_122 , V_126 , V_272 , V_311 ,
V_259 , V_308 , V_320 , & V_291 ) ;
if ( V_32 == 1 )
goto V_329;
V_318:
if ( V_291 == 0 ) {
F_114 ( V_126 ) ;
F_116 ( V_126 ) ;
}
if ( F_220 ( V_126 ) ) {
V_32 = V_32 < 0 ? V_32 : - V_153 ;
F_172 ( V_126 , V_32 , V_15 , V_286 ) ;
}
F_117 ( V_126 ) ;
return V_32 ;
V_329:
return 0 ;
}
void F_240 ( struct V_10 * V_11 )
{
F_241 ( & V_11 -> V_330 , V_331 ,
V_110 ) ;
}
static T_14 int
F_242 ( struct V_10 * V_11 ,
struct V_36 * V_170 ,
struct V_310 * V_311 )
{
unsigned long V_151 , V_199 ;
int V_332 = 0 ;
int V_32 = 0 ;
if ( ! F_243 ( V_11 ) ) {
V_332 = 1 ;
F_244 ( V_311 ) ;
F_245 ( V_11 ) ;
}
if ( F_162 ( V_331 , & V_11 -> V_330 ) ) {
F_246 ( V_11 ) ;
if ( ! V_311 -> V_333 )
return 0 ;
if ( ! V_332 ) {
F_244 ( V_311 ) ;
V_332 = 1 ;
}
while ( 1 ) {
F_240 ( V_11 ) ;
F_245 ( V_11 ) ;
if ( ! F_162 ( V_331 , & V_11 -> V_330 ) )
break;
F_246 ( V_11 ) ;
}
}
F_70 ( & V_11 -> V_334 ) ;
if ( F_247 ( V_335 , & V_11 -> V_330 ) ) {
F_248 ( V_331 , & V_11 -> V_330 ) ;
F_73 ( & V_11 -> V_334 ) ;
F_249 ( V_11 , V_336 ) ;
F_250 ( & V_170 -> V_337 ,
- V_11 -> V_20 ,
V_170 -> V_338 ) ;
V_32 = 1 ;
} else {
F_73 ( & V_11 -> V_334 ) ;
}
F_246 ( V_11 ) ;
if ( ! V_32 )
return V_32 ;
V_199 = F_148 ( V_11 -> V_15 , V_11 -> V_20 ) ;
for ( V_151 = 0 ; V_151 < V_199 ; V_151 ++ ) {
struct V_126 * V_63 = V_11 -> V_150 [ V_151 ] ;
if ( ! F_251 ( V_63 ) ) {
if ( ! V_332 ) {
F_244 ( V_311 ) ;
V_332 = 1 ;
}
F_118 ( V_63 ) ;
}
}
return V_32 ;
}
static void F_252 ( struct V_10 * V_11 )
{
F_253 ( V_331 , & V_11 -> V_330 ) ;
F_254 () ;
F_255 ( & V_11 -> V_330 , V_331 ) ;
}
static void F_256 ( struct V_126 * V_126 )
{
struct V_10 * V_11 = (struct V_10 * ) V_126 -> V_201 ;
F_115 ( V_126 ) ;
if ( F_257 ( V_339 , & V_11 -> V_330 ) )
return;
switch ( V_11 -> V_340 ) {
case - 1 :
F_248 ( V_341 , & V_11 -> V_170 -> V_7 ) ;
break;
case 0 :
F_248 ( V_342 , & V_11 -> V_170 -> V_7 ) ;
break;
case 1 :
F_248 ( V_343 , & V_11 -> V_170 -> V_7 ) ;
break;
default:
F_258 () ;
}
}
static void F_259 ( struct V_43 * V_43 )
{
struct V_245 * V_246 ;
struct V_10 * V_11 ;
int V_151 , V_318 ;
ASSERT ( ! F_175 ( V_43 , V_247 ) ) ;
F_176 (bvec, bio, i) {
struct V_126 * V_126 = V_246 -> V_248 ;
V_11 = (struct V_10 * ) V_126 -> V_201 ;
F_19 ( ! V_11 ) ;
V_318 = F_260 ( & V_11 -> V_344 ) ;
if ( V_43 -> V_244 ||
F_162 ( V_339 , & V_11 -> V_330 ) ) {
F_173 ( V_126 ) ;
F_256 ( V_126 ) ;
}
F_116 ( V_126 ) ;
if ( ! V_318 )
continue;
F_252 ( V_11 ) ;
}
F_139 ( V_43 ) ;
}
static T_14 int F_261 ( struct V_10 * V_11 ,
struct V_36 * V_170 ,
struct V_271 * V_272 ,
struct V_310 * V_311 )
{
struct V_262 * V_192 = V_170 -> V_227 -> V_228 ;
struct V_23 * V_24 = & F_121 ( V_170 -> V_345 ) -> V_158 ;
T_1 V_59 = V_11 -> V_15 ;
T_15 V_346 ;
unsigned long V_151 , V_199 ;
unsigned long V_215 = 0 ;
unsigned long V_15 , V_16 ;
unsigned int V_320 = F_236 ( V_272 ) | V_347 ;
int V_32 = 0 ;
F_253 ( V_339 , & V_11 -> V_330 ) ;
V_199 = F_148 ( V_11 -> V_15 , V_11 -> V_20 ) ;
F_262 ( & V_11 -> V_344 , V_199 ) ;
if ( F_263 ( V_11 ) == V_348 )
V_215 = V_349 ;
V_346 = F_264 ( V_11 ) ;
if ( F_265 ( V_11 ) > 0 ) {
V_16 = F_266 ( V_346 ) ;
F_267 ( V_11 , V_16 , V_11 -> V_20 - V_16 ) ;
} else {
V_15 = F_268 ( V_346 ) ;
V_16 = V_350 + F_269 ( V_170 , V_11 ) ;
F_267 ( V_11 , V_15 , V_16 - V_15 ) ;
}
for ( V_151 = 0 ; V_151 < V_199 ; V_151 ++ ) {
struct V_126 * V_63 = V_11 -> V_150 [ V_151 ] ;
F_95 ( V_63 ) ;
F_114 ( V_63 ) ;
V_32 = F_198 ( V_195 | V_320 , V_24 , V_272 ,
V_63 , V_59 >> 9 , V_142 , 0 , V_192 ,
& V_311 -> V_43 ,
F_259 ,
0 , V_311 -> V_215 , V_215 , false ) ;
V_311 -> V_215 = V_215 ;
if ( V_32 ) {
F_256 ( V_63 ) ;
if ( F_234 ( V_63 ) )
F_116 ( V_63 ) ;
if ( F_270 ( V_199 - V_151 , & V_11 -> V_344 ) )
F_252 ( V_11 ) ;
V_32 = - V_153 ;
break;
}
V_59 += V_142 ;
F_229 ( V_272 , 1 ) ;
F_117 ( V_63 ) ;
}
if ( F_186 ( V_32 ) ) {
for (; V_151 < V_199 ; V_151 ++ ) {
struct V_126 * V_63 = V_11 -> V_150 [ V_151 ] ;
F_95 ( V_63 ) ;
F_117 ( V_63 ) ;
}
}
return V_32 ;
}
int F_271 ( struct V_144 * V_145 ,
struct V_271 * V_272 )
{
struct V_23 * V_24 = & F_121 ( V_145 -> V_235 ) -> V_158 ;
struct V_36 * V_170 = F_121 ( V_145 -> V_235 ) -> V_57 -> V_170 ;
struct V_10 * V_11 , * V_351 = NULL ;
struct V_310 V_311 = {
. V_43 = NULL ,
. V_24 = V_24 ,
. V_315 = 0 ,
. V_333 = V_272 -> V_352 == V_353 ,
. V_215 = 0 ,
} ;
int V_32 = 0 ;
int V_318 = 0 ;
int V_354 = 0 ;
struct V_355 V_356 ;
int V_148 ;
T_6 V_123 ;
T_6 V_16 ;
int V_357 = 0 ;
int V_358 ;
F_272 ( & V_356 , 0 ) ;
if ( V_272 -> V_359 ) {
V_123 = V_145 -> V_360 ;
V_16 = - 1 ;
} else {
V_123 = V_272 -> V_361 >> V_124 ;
V_16 = V_272 -> V_362 >> V_124 ;
V_357 = 1 ;
}
if ( V_272 -> V_352 == V_353 )
V_358 = V_363 ;
else
V_358 = V_364 ;
V_365:
if ( V_272 -> V_352 == V_353 )
F_273 ( V_145 , V_123 , V_16 ) ;
while ( ! V_318 && ! V_354 && ( V_123 <= V_16 ) &&
( V_148 = F_274 ( & V_356 , V_145 , & V_123 , V_358 ,
F_123 ( V_16 - V_123 , ( T_6 ) V_366 - 1 ) + 1 ) ) ) {
unsigned V_151 ;
V_357 = 1 ;
for ( V_151 = 0 ; V_151 < V_148 ; V_151 ++ ) {
struct V_126 * V_126 = V_356 . V_150 [ V_151 ] ;
if ( ! F_203 ( V_126 ) )
continue;
if ( ! V_272 -> V_359 && V_126 -> V_123 > V_16 ) {
V_318 = 1 ;
break;
}
F_70 ( & V_145 -> V_367 ) ;
if ( ! F_203 ( V_126 ) ) {
F_73 ( & V_145 -> V_367 ) ;
continue;
}
V_11 = (struct V_10 * ) V_126 -> V_201 ;
if ( F_40 ( ! V_11 ) ) {
F_73 ( & V_145 -> V_367 ) ;
continue;
}
if ( V_11 == V_351 ) {
F_73 ( & V_145 -> V_367 ) ;
continue;
}
V_32 = F_275 ( & V_11 -> V_17 ) ;
F_73 ( & V_145 -> V_367 ) ;
if ( ! V_32 )
continue;
V_351 = V_11 ;
V_32 = F_242 ( V_11 , V_170 , & V_311 ) ;
if ( ! V_32 ) {
F_276 ( V_11 ) ;
continue;
}
V_32 = F_261 ( V_11 , V_170 , V_272 , & V_311 ) ;
if ( V_32 ) {
V_318 = 1 ;
F_276 ( V_11 ) ;
break;
}
F_276 ( V_11 ) ;
V_354 = V_272 -> V_309 <= 0 ;
}
F_277 ( & V_356 ) ;
F_74 () ;
}
if ( ! V_357 && ! V_318 ) {
V_357 = 1 ;
V_123 = 0 ;
goto V_365;
}
F_244 ( & V_311 ) ;
return V_32 ;
}
static int F_278 ( struct V_144 * V_145 ,
struct V_271 * V_272 ,
T_16 V_368 , void * V_224 ,
void (* F_279)( void * ) )
{
struct V_122 * V_122 = V_145 -> V_235 ;
int V_32 = 0 ;
int V_318 = 0 ;
int V_354 = 0 ;
struct V_355 V_356 ;
int V_148 ;
T_6 V_123 ;
T_6 V_16 ;
T_6 V_369 ;
int V_370 = 0 ;
int V_357 = 0 ;
int V_358 ;
if ( ! F_280 ( V_122 ) )
return 0 ;
F_272 ( & V_356 , 0 ) ;
if ( V_272 -> V_359 ) {
V_123 = V_145 -> V_360 ;
V_16 = - 1 ;
} else {
V_123 = V_272 -> V_361 >> V_124 ;
V_16 = V_272 -> V_362 >> V_124 ;
if ( V_272 -> V_361 == 0 && V_272 -> V_362 == V_371 )
V_370 = 1 ;
V_357 = 1 ;
}
if ( V_272 -> V_352 == V_353 )
V_358 = V_363 ;
else
V_358 = V_364 ;
V_365:
if ( V_272 -> V_352 == V_353 )
F_273 ( V_145 , V_123 , V_16 ) ;
V_369 = V_123 ;
while ( ! V_318 && ! V_354 && ( V_123 <= V_16 ) &&
( V_148 = F_274 ( & V_356 , V_145 , & V_123 , V_358 ,
F_123 ( V_16 - V_123 , ( T_6 ) V_366 - 1 ) + 1 ) ) ) {
unsigned V_151 ;
V_357 = 1 ;
for ( V_151 = 0 ; V_151 < V_148 ; V_151 ++ ) {
struct V_126 * V_126 = V_356 . V_150 [ V_151 ] ;
V_369 = V_126 -> V_123 ;
if ( ! F_251 ( V_126 ) ) {
F_279 ( V_224 ) ;
F_118 ( V_126 ) ;
}
if ( F_186 ( V_126 -> V_145 != V_145 ) ) {
F_117 ( V_126 ) ;
continue;
}
if ( ! V_272 -> V_359 && V_126 -> V_123 > V_16 ) {
V_318 = 1 ;
F_117 ( V_126 ) ;
continue;
}
if ( V_272 -> V_352 != V_372 ) {
if ( F_234 ( V_126 ) )
F_279 ( V_224 ) ;
F_281 ( V_126 ) ;
}
if ( F_234 ( V_126 ) ||
! F_95 ( V_126 ) ) {
F_117 ( V_126 ) ;
continue;
}
V_32 = (* V_368)( V_126 , V_272 , V_224 ) ;
if ( F_186 ( V_32 == V_373 ) ) {
F_117 ( V_126 ) ;
V_32 = 0 ;
}
if ( V_32 < 0 ) {
V_369 = V_126 -> V_123 + 1 ;
V_318 = 1 ;
break;
}
V_354 = V_272 -> V_309 <= 0 ;
}
F_277 ( & V_356 ) ;
F_74 () ;
}
if ( ! V_357 && ! V_318 ) {
V_357 = 1 ;
V_123 = 0 ;
goto V_365;
}
if ( V_272 -> V_359 || ( V_272 -> V_309 > 0 && V_370 ) )
V_145 -> V_360 = V_369 ;
F_282 ( V_122 ) ;
return V_32 ;
}
static void F_283 ( struct V_310 * V_311 )
{
if ( V_311 -> V_43 ) {
int V_32 ;
V_32 = F_194 ( V_311 -> V_43 , 0 , V_311 -> V_215 ) ;
F_19 ( V_32 < 0 ) ;
V_311 -> V_43 = NULL ;
}
}
static T_5 void F_244 ( void * V_224 )
{
struct V_310 * V_311 = V_224 ;
F_283 ( V_311 ) ;
}
int F_284 ( struct V_23 * V_24 , struct V_126 * V_126 ,
T_13 * V_282 ,
struct V_271 * V_272 )
{
int V_32 ;
struct V_310 V_311 = {
. V_43 = NULL ,
. V_24 = V_24 ,
. V_282 = V_282 ,
. V_315 = 0 ,
. V_333 = V_272 -> V_352 == V_353 ,
. V_215 = 0 ,
} ;
V_32 = F_235 ( V_126 , V_272 , & V_311 ) ;
F_283 ( & V_311 ) ;
return V_32 ;
}
int F_285 ( struct V_23 * V_24 , struct V_122 * V_122 ,
T_1 V_15 , T_1 V_16 , T_13 * V_282 ,
int V_374 )
{
int V_32 = 0 ;
struct V_144 * V_145 = V_122 -> V_127 ;
struct V_126 * V_126 ;
unsigned long V_148 = ( V_16 - V_15 + V_142 ) >>
V_124 ;
struct V_310 V_311 = {
. V_43 = NULL ,
. V_24 = V_24 ,
. V_282 = V_282 ,
. V_315 = 1 ,
. V_333 = V_374 == V_353 ,
. V_215 = 0 ,
} ;
struct V_271 V_375 = {
. V_352 = V_374 ,
. V_309 = V_148 * 2 ,
. V_361 = V_15 ,
. V_362 = V_16 + 1 ,
} ;
while ( V_15 <= V_16 ) {
V_126 = F_94 ( V_145 , V_15 >> V_124 ) ;
if ( F_95 ( V_126 ) )
V_32 = F_235 ( V_126 , & V_375 , & V_311 ) ;
else {
if ( V_24 -> V_25 && V_24 -> V_25 -> V_243 )
V_24 -> V_25 -> V_243 ( V_126 , V_15 ,
V_15 + V_142 - 1 ,
NULL , 1 ) ;
F_117 ( V_126 ) ;
}
F_96 ( V_126 ) ;
V_15 += V_142 ;
}
F_283 ( & V_311 ) ;
return V_32 ;
}
int F_286 ( struct V_23 * V_24 ,
struct V_144 * V_145 ,
T_13 * V_282 ,
struct V_271 * V_272 )
{
int V_32 = 0 ;
struct V_310 V_311 = {
. V_43 = NULL ,
. V_24 = V_24 ,
. V_282 = V_282 ,
. V_315 = 0 ,
. V_333 = V_272 -> V_352 == V_353 ,
. V_215 = 0 ,
} ;
V_32 = F_278 ( V_145 , V_272 , F_235 , & V_311 ,
F_244 ) ;
F_283 ( & V_311 ) ;
return V_32 ;
}
int F_287 ( struct V_23 * V_24 ,
struct V_144 * V_145 ,
struct V_4 * V_150 , unsigned V_148 ,
T_13 V_282 )
{
struct V_43 * V_43 = NULL ;
unsigned V_376 ;
unsigned long V_215 = 0 ;
struct V_126 * V_377 [ 16 ] ;
struct V_126 * V_126 ;
struct V_210 * V_283 = NULL ;
int V_291 = 0 ;
T_1 V_285 = ( T_1 ) - 1 ;
for ( V_376 = 0 ; V_376 < V_148 ; V_376 ++ ) {
V_126 = F_11 ( V_150 -> V_74 , struct V_126 , V_378 ) ;
F_288 ( & V_126 -> V_7 ) ;
F_8 ( & V_126 -> V_378 ) ;
if ( F_289 ( V_126 , V_145 ,
V_126 -> V_123 ,
F_290 ( V_145 ) ) ) {
F_96 ( V_126 ) ;
continue;
}
V_377 [ V_291 ++ ] = V_126 ;
if ( V_291 < F_291 ( V_377 ) )
continue;
F_226 ( V_24 , V_377 , V_291 , V_282 , & V_283 ,
& V_43 , 0 , & V_215 , & V_285 ) ;
V_291 = 0 ;
}
if ( V_291 )
F_226 ( V_24 , V_377 , V_291 , V_282 , & V_283 ,
& V_43 , 0 , & V_215 , & V_285 ) ;
if ( V_283 )
F_161 ( V_283 ) ;
F_19 ( ! F_10 ( V_150 ) ) ;
if ( V_43 )
return F_194 ( V_43 , 0 , V_215 ) ;
return 0 ;
}
int F_292 ( struct V_23 * V_24 ,
struct V_126 * V_126 , unsigned long V_59 )
{
struct V_1 * V_98 = NULL ;
T_1 V_15 = F_128 ( V_126 ) ;
T_1 V_16 = V_15 + V_142 - 1 ;
T_11 V_294 = V_126 -> V_145 -> V_235 -> V_209 -> V_295 ;
V_15 += F_219 ( V_59 , V_294 ) ;
if ( V_15 > V_16 )
return 0 ;
F_91 ( V_24 , V_15 , V_16 , & V_98 ) ;
F_281 ( V_126 ) ;
F_89 ( V_24 , V_15 , V_16 ,
V_121 | V_94 | V_102 |
V_379 ,
1 , 1 , & V_98 , V_120 ) ;
return 0 ;
}
static int F_293 ( struct V_212 * V_380 ,
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
~ ( V_121 | V_381 ) ,
0 , 0 , NULL , V_50 ) ;
if ( V_32 < 0 )
V_32 = 0 ;
else
V_32 = 1 ;
}
return V_32 ;
}
int F_294 ( struct V_212 * V_380 ,
struct V_23 * V_24 , struct V_126 * V_126 ,
T_3 V_50 )
{
struct V_210 * V_211 ;
T_1 V_15 = F_128 ( V_126 ) ;
T_1 V_16 = V_15 + V_142 - 1 ;
if ( F_69 ( V_50 ) &&
V_126 -> V_145 -> V_235 -> V_259 > V_382 ) {
T_1 V_20 ;
while ( V_15 <= V_16 ) {
V_20 = V_16 - V_15 + 1 ;
F_295 ( & V_380 -> V_49 ) ;
V_211 = F_159 ( V_380 , V_15 , V_20 ) ;
if ( ! V_211 ) {
F_296 ( & V_380 -> V_49 ) ;
break;
}
if ( F_162 ( V_383 , & V_211 -> V_7 ) ||
V_211 -> V_15 != V_15 ) {
F_296 ( & V_380 -> V_49 ) ;
F_161 ( V_211 ) ;
break;
}
if ( ! F_108 ( V_24 , V_211 -> V_15 ,
F_210 ( V_211 ) - 1 ,
V_121 | V_384 ,
0 , NULL ) ) {
F_297 ( V_380 , V_211 ) ;
F_161 ( V_211 ) ;
}
V_15 = F_210 ( V_211 ) ;
F_296 ( & V_380 -> V_49 ) ;
F_161 ( V_211 ) ;
}
}
return F_293 ( V_380 , V_24 , V_126 , V_50 ) ;
}
static struct V_210 * F_298 ( struct V_122 * V_122 ,
T_1 V_59 ,
T_1 V_161 ,
T_13 * V_282 )
{
T_1 V_385 = F_299 ( V_122 ) ;
struct V_210 * V_211 ;
T_1 V_20 ;
if ( V_59 >= V_161 )
return NULL ;
while ( 1 ) {
V_20 = V_161 - V_59 ;
if ( V_20 == 0 )
break;
V_20 = F_219 ( V_20 , V_385 ) ;
V_211 = V_282 ( F_121 ( V_122 ) , NULL , 0 , V_59 , V_20 , 0 ) ;
if ( F_211 ( V_211 ) )
return V_211 ;
if ( ! F_162 ( V_386 , & V_211 -> V_7 ) &&
V_211 -> V_216 != V_301 ) {
return V_211 ;
}
V_59 = F_210 ( V_211 ) ;
F_161 ( V_211 ) ;
if ( V_59 >= V_161 )
break;
}
return NULL ;
}
static int F_300 ( struct V_387 * V_388 ,
struct V_389 * V_390 ,
T_1 V_59 , T_1 V_391 , T_1 V_20 , T_15 V_7 )
{
int V_32 = 0 ;
if ( ! V_390 -> V_99 )
goto V_392;
if ( V_390 -> V_59 + V_390 -> V_20 > V_59 ) {
F_40 ( 1 ) ;
return - V_393 ;
}
if ( V_390 -> V_59 + V_390 -> V_20 == V_59 &&
V_390 -> V_391 + V_390 -> V_20 == V_391 &&
( V_390 -> V_7 & ~ V_394 ) ==
( V_7 & ~ V_394 ) ) {
V_390 -> V_20 += V_20 ;
V_390 -> V_7 |= V_7 ;
goto V_395;
}
V_32 = F_301 ( V_388 , V_390 -> V_59 , V_390 -> V_391 ,
V_390 -> V_20 , V_390 -> V_7 ) ;
V_390 -> V_99 = false ;
if ( V_32 )
return V_32 ;
V_392:
V_390 -> V_99 = true ;
V_390 -> V_59 = V_59 ;
V_390 -> V_391 = V_391 ;
V_390 -> V_20 = V_20 ;
V_390 -> V_7 = V_7 ;
V_395:
if ( V_390 -> V_7 & V_394 ) {
V_32 = F_301 ( V_388 , V_390 -> V_59 ,
V_390 -> V_391 , V_390 -> V_20 , V_390 -> V_7 ) ;
V_390 -> V_99 = false ;
}
return V_32 ;
}
static int F_302 ( struct V_36 * V_170 ,
struct V_387 * V_388 ,
struct V_389 * V_390 )
{
int V_32 ;
if ( ! V_390 -> V_99 )
return 0 ;
V_32 = F_301 ( V_388 , V_390 -> V_59 , V_390 -> V_391 ,
V_390 -> V_20 , V_390 -> V_7 ) ;
V_390 -> V_99 = false ;
if ( V_32 > 0 )
V_32 = 0 ;
return V_32 ;
}
int F_303 ( struct V_122 * V_122 , struct V_387 * V_388 ,
T_17 V_15 , T_17 V_20 , T_13 * V_282 )
{
int V_32 = 0 ;
T_1 V_260 = V_15 ;
T_1 F_124 = V_15 + V_20 ;
T_15 V_7 = 0 ;
T_15 V_396 ;
T_1 V_161 ;
T_1 V_397 = 0 ;
T_1 V_398 = 0 ;
T_1 V_399 = F_184 ( V_122 ) ;
struct V_400 V_401 ;
struct V_210 * V_211 = NULL ;
struct V_1 * V_98 = NULL ;
struct V_402 * V_403 ;
struct V_404 * V_57 = F_121 ( V_122 ) -> V_57 ;
struct V_389 V_390 = { 0 } ;
int V_16 = 0 ;
T_1 V_405 = 0 ;
T_1 V_406 = 0 ;
T_1 V_326 = 0 ;
if ( V_20 == 0 )
return - V_393 ;
V_403 = F_304 () ;
if ( ! V_403 )
return - V_38 ;
V_403 -> V_407 = 1 ;
V_15 = F_305 ( V_15 , F_299 ( V_122 ) ) ;
V_20 = F_306 ( F_124 , F_299 ( V_122 ) ) - V_15 ;
V_32 = F_307 ( NULL , V_57 , V_403 ,
F_183 ( F_121 ( V_122 ) ) , - 1 , 0 ) ;
if ( V_32 < 0 ) {
F_308 ( V_403 ) ;
return V_32 ;
} else {
F_40 ( ! V_32 ) ;
if ( V_32 == 1 )
V_32 = 0 ;
}
V_403 -> V_408 [ 0 ] -- ;
F_309 ( V_403 -> V_409 [ 0 ] , & V_401 , V_403 -> V_408 [ 0 ] ) ;
V_396 = V_401 . type ;
if ( V_401 . V_410 != F_183 ( F_121 ( V_122 ) ) ||
V_396 != V_411 ) {
V_161 = ( T_1 ) - 1 ;
V_397 = V_399 ;
} else {
V_161 = V_401 . V_59 ;
V_397 = V_161 + 1 ;
}
F_310 ( V_403 ) ;
if ( V_161 < V_399 ) {
V_161 = ( T_1 ) - 1 ;
V_397 = V_399 ;
}
F_91 ( & F_121 ( V_122 ) -> V_158 , V_15 , V_15 + V_20 - 1 ,
& V_98 ) ;
V_211 = F_298 ( V_122 , V_15 , V_397 ,
V_282 ) ;
if ( ! V_211 )
goto V_107;
if ( F_311 ( V_211 ) ) {
V_32 = F_312 ( V_211 ) ;
goto V_107;
}
while ( ! V_16 ) {
T_1 V_412 = 0 ;
if ( V_211 -> V_15 >= F_124 || F_210 ( V_211 ) < V_260 )
break;
V_405 = F_124 ( V_211 -> V_15 , V_260 ) ;
if ( ! F_162 ( V_217 , & V_211 -> V_7 ) )
V_412 = V_405 - V_211 -> V_15 ;
V_326 = F_210 ( V_211 ) ;
V_406 = V_326 - V_405 ;
V_398 = 0 ;
V_7 = 0 ;
V_260 = F_210 ( V_211 ) ;
if ( V_260 >= F_124 )
V_16 = 1 ;
if ( V_211 -> V_216 == V_413 ) {
V_16 = 1 ;
V_7 |= V_394 ;
} else if ( V_211 -> V_216 == V_303 ) {
V_7 |= ( V_414 |
V_415 ) ;
} else if ( V_211 -> V_216 == V_416 ) {
V_7 |= ( V_417 |
V_418 ) ;
} else if ( V_388 -> V_419 ) {
T_1 V_420 = V_211 -> V_216 -
( V_211 -> V_15 - V_211 -> V_302 ) ;
V_398 = V_211 -> V_216 + V_412 ;
V_32 = F_313 ( V_57 ,
F_183 ( F_121 ( V_122 ) ) ,
V_420 ) ;
if ( V_32 < 0 )
goto V_421;
if ( V_32 )
V_7 |= V_422 ;
V_32 = 0 ;
}
if ( F_162 ( V_217 , & V_211 -> V_7 ) )
V_7 |= V_423 ;
if ( F_162 ( V_300 , & V_211 -> V_7 ) )
V_7 |= V_424 ;
F_161 ( V_211 ) ;
V_211 = NULL ;
if ( ( V_405 >= V_161 ) || V_406 == ( T_1 ) - 1 ||
( V_161 == ( T_1 ) - 1 && V_399 <= V_326 ) ) {
V_7 |= V_394 ;
V_16 = 1 ;
}
V_211 = F_298 ( V_122 , V_260 , V_397 ,
V_282 ) ;
if ( F_311 ( V_211 ) ) {
V_32 = F_312 ( V_211 ) ;
goto V_107;
}
if ( ! V_211 ) {
V_7 |= V_394 ;
V_16 = 1 ;
}
V_32 = F_300 ( V_388 , & V_390 , V_405 , V_398 ,
V_406 , V_7 ) ;
if ( V_32 ) {
if ( V_32 == 1 )
V_32 = 0 ;
goto V_421;
}
}
V_421:
if ( ! V_32 )
V_32 = F_302 ( V_57 -> V_170 , V_388 , & V_390 ) ;
F_161 ( V_211 ) ;
V_107:
F_308 ( V_403 ) ;
F_109 ( & F_121 ( V_122 ) -> V_158 , V_15 , V_15 + V_20 - 1 ,
& V_98 , V_120 ) ;
return V_32 ;
}
static void F_314 ( struct V_10 * V_11 )
{
F_7 ( & V_11 -> V_14 ) ;
F_14 ( V_21 , V_11 ) ;
}
int F_315 ( struct V_10 * V_11 )
{
return ( F_15 ( & V_11 -> V_344 ) ||
F_162 ( V_331 , & V_11 -> V_330 ) ||
F_162 ( V_335 , & V_11 -> V_330 ) ) ;
}
static void F_316 ( struct V_10 * V_11 )
{
unsigned long V_123 ;
struct V_126 * V_126 ;
int V_425 = ! F_162 ( V_426 , & V_11 -> V_330 ) ;
F_19 ( F_315 ( V_11 ) ) ;
V_123 = F_148 ( V_11 -> V_15 , V_11 -> V_20 ) ;
if ( V_123 == 0 )
return;
do {
V_123 -- ;
V_126 = V_11 -> V_150 [ V_123 ] ;
if ( ! V_126 )
continue;
if ( V_425 )
F_70 ( & V_126 -> V_145 -> V_367 ) ;
if ( F_203 ( V_126 ) &&
V_126 -> V_201 == ( unsigned long ) V_11 ) {
F_19 ( F_162 ( V_335 , & V_11 -> V_330 ) ) ;
F_19 ( F_119 ( V_126 ) ) ;
F_19 ( F_234 ( V_126 ) ) ;
F_317 ( V_126 ) ;
F_206 ( V_126 , 0 ) ;
F_96 ( V_126 ) ;
}
if ( V_425 )
F_73 ( & V_126 -> V_145 -> V_367 ) ;
F_96 ( V_126 ) ;
} while ( V_123 != 0 );
}
static inline void F_318 ( struct V_10 * V_11 )
{
F_316 ( V_11 ) ;
F_314 ( V_11 ) ;
}
static struct V_10 *
F_319 ( struct V_36 * V_170 , T_1 V_15 ,
unsigned long V_20 )
{
struct V_10 * V_11 = NULL ;
V_11 = F_320 ( V_21 , V_120 | V_427 ) ;
V_11 -> V_15 = V_15 ;
V_11 -> V_20 = V_20 ;
V_11 -> V_170 = V_170 ;
V_11 -> V_330 = 0 ;
F_321 ( & V_11 -> V_49 ) ;
F_262 ( & V_11 -> V_428 , 0 ) ;
F_262 ( & V_11 -> V_429 , 0 ) ;
F_262 ( & V_11 -> V_430 , 0 ) ;
F_262 ( & V_11 -> V_431 , 0 ) ;
F_262 ( & V_11 -> V_432 , 0 ) ;
F_262 ( & V_11 -> V_433 , 0 ) ;
V_11 -> V_434 = 0 ;
F_36 ( & V_11 -> V_435 ) ;
F_36 ( & V_11 -> V_436 ) ;
F_3 ( & V_11 -> V_14 , & V_19 ) ;
F_31 ( & V_11 -> V_334 ) ;
F_262 ( & V_11 -> V_17 , 1 ) ;
F_262 ( & V_11 -> V_344 , 0 ) ;
F_322 ( V_437
> V_438 ) ;
F_19 ( V_20 > V_438 ) ;
return V_11 ;
}
struct V_10 * F_323 ( struct V_10 * V_439 )
{
unsigned long V_151 ;
struct V_126 * V_63 ;
struct V_10 * V_5 ;
unsigned long V_199 = F_148 ( V_439 -> V_15 , V_439 -> V_20 ) ;
V_5 = F_319 ( V_439 -> V_170 , V_439 -> V_15 , V_439 -> V_20 ) ;
if ( V_5 == NULL )
return NULL ;
for ( V_151 = 0 ; V_151 < V_199 ; V_151 ++ ) {
V_63 = F_324 ( V_120 ) ;
if ( ! V_63 ) {
F_318 ( V_5 ) ;
return NULL ;
}
F_202 ( V_5 , V_63 ) ;
F_40 ( F_119 ( V_63 ) ) ;
F_129 ( V_63 ) ;
V_5 -> V_150 [ V_151 ] = V_63 ;
F_325 ( F_326 ( V_63 ) , F_326 ( V_439 -> V_150 [ V_151 ] ) ) ;
}
F_248 ( V_440 , & V_5 -> V_330 ) ;
F_248 ( V_426 , & V_5 -> V_330 ) ;
return V_5 ;
}
struct V_10 * F_327 ( struct V_36 * V_170 ,
T_1 V_15 , unsigned long V_20 )
{
struct V_10 * V_11 ;
unsigned long V_199 ;
unsigned long V_151 ;
V_199 = F_148 ( V_15 , V_20 ) ;
V_11 = F_319 ( V_170 , V_15 , V_20 ) ;
if ( ! V_11 )
return NULL ;
for ( V_151 = 0 ; V_151 < V_199 ; V_151 ++ ) {
V_11 -> V_150 [ V_151 ] = F_324 ( V_120 ) ;
if ( ! V_11 -> V_150 [ V_151 ] )
goto V_96;
}
F_328 ( V_11 ) ;
F_329 ( V_11 , 0 ) ;
F_248 ( V_426 , & V_11 -> V_330 ) ;
return V_11 ;
V_96:
for (; V_151 > 0 ; V_151 -- )
F_330 ( V_11 -> V_150 [ V_151 - 1 ] ) ;
F_314 ( V_11 ) ;
return NULL ;
}
struct V_10 * F_331 ( struct V_36 * V_170 ,
T_1 V_15 )
{
return F_327 ( V_170 , V_15 , V_170 -> V_441 ) ;
}
static void F_332 ( struct V_10 * V_11 )
{
int V_17 ;
V_17 = F_15 ( & V_11 -> V_17 ) ;
if ( V_17 >= 2 && F_162 ( V_442 , & V_11 -> V_330 ) )
return;
F_70 ( & V_11 -> V_334 ) ;
if ( ! F_257 ( V_442 , & V_11 -> V_330 ) )
F_333 ( & V_11 -> V_17 ) ;
F_73 ( & V_11 -> V_334 ) ;
}
static void F_334 ( struct V_10 * V_11 ,
struct V_126 * V_443 )
{
unsigned long V_199 , V_151 ;
F_332 ( V_11 ) ;
V_199 = F_148 ( V_11 -> V_15 , V_11 -> V_20 ) ;
for ( V_151 = 0 ; V_151 < V_199 ; V_151 ++ ) {
struct V_126 * V_63 = V_11 -> V_150 [ V_151 ] ;
if ( V_63 != V_443 )
F_335 ( V_63 ) ;
}
}
struct V_10 * F_336 ( struct V_36 * V_170 ,
T_1 V_15 )
{
struct V_10 * V_11 ;
F_337 () ;
V_11 = F_338 ( & V_170 -> V_444 ,
V_15 >> V_124 ) ;
if ( V_11 && F_275 ( & V_11 -> V_17 ) ) {
F_339 () ;
if ( F_162 ( V_445 , & V_11 -> V_330 ) ) {
F_70 ( & V_11 -> V_334 ) ;
F_73 ( & V_11 -> V_334 ) ;
}
F_334 ( V_11 , NULL ) ;
return V_11 ;
}
F_339 () ;
return NULL ;
}
struct V_10 * F_340 ( struct V_36 * V_170 ,
T_1 V_15 )
{
struct V_10 * V_11 , * V_446 = NULL ;
int V_32 ;
V_11 = F_336 ( V_170 , V_15 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_331 ( V_170 , V_15 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_170 = V_170 ;
V_105:
V_32 = F_341 ( V_120 ) ;
if ( V_32 )
goto V_447;
F_70 ( & V_170 -> V_448 ) ;
V_32 = F_342 ( & V_170 -> V_444 ,
V_15 >> V_124 , V_11 ) ;
F_73 ( & V_170 -> V_448 ) ;
F_343 () ;
if ( V_32 == - V_86 ) {
V_446 = F_336 ( V_170 , V_15 ) ;
if ( V_446 )
goto V_447;
else
goto V_105;
}
F_332 ( V_11 ) ;
F_248 ( V_449 , & V_11 -> V_330 ) ;
F_333 ( & V_11 -> V_17 ) ;
return V_11 ;
V_447:
F_318 ( V_11 ) ;
return V_446 ;
}
struct V_10 * F_344 ( struct V_36 * V_170 ,
T_1 V_15 )
{
unsigned long V_20 = V_170 -> V_441 ;
unsigned long V_199 = F_148 ( V_15 , V_20 ) ;
unsigned long V_151 ;
unsigned long V_123 = V_15 >> V_124 ;
struct V_10 * V_11 ;
struct V_10 * V_446 = NULL ;
struct V_126 * V_63 ;
struct V_144 * V_145 = V_170 -> V_345 -> V_127 ;
int V_242 = 1 ;
int V_32 ;
if ( ! F_345 ( V_15 , V_170 -> V_385 ) ) {
F_177 ( V_170 , L_21 , V_15 ) ;
return F_346 ( - V_393 ) ;
}
V_11 = F_336 ( V_170 , V_15 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_319 ( V_170 , V_15 , V_20 ) ;
if ( ! V_11 )
return F_346 ( - V_38 ) ;
for ( V_151 = 0 ; V_151 < V_199 ; V_151 ++ , V_123 ++ ) {
V_63 = F_347 ( V_145 , V_123 , V_120 | V_427 ) ;
if ( ! V_63 ) {
V_446 = F_346 ( - V_38 ) ;
goto V_447;
}
F_70 ( & V_145 -> V_367 ) ;
if ( F_203 ( V_63 ) ) {
V_446 = (struct V_10 * ) V_63 -> V_201 ;
if ( F_275 ( & V_446 -> V_17 ) ) {
F_73 ( & V_145 -> V_367 ) ;
F_117 ( V_63 ) ;
F_96 ( V_63 ) ;
F_334 ( V_446 , V_63 ) ;
goto V_447;
}
V_446 = NULL ;
F_317 ( V_63 ) ;
F_40 ( F_119 ( V_63 ) ) ;
F_96 ( V_63 ) ;
}
F_202 ( V_11 , V_63 ) ;
F_73 ( & V_145 -> V_367 ) ;
F_40 ( F_119 ( V_63 ) ) ;
V_11 -> V_150 [ V_151 ] = V_63 ;
if ( ! F_213 ( V_63 ) )
V_242 = 0 ;
}
if ( V_242 )
F_248 ( V_440 , & V_11 -> V_330 ) ;
V_105:
V_32 = F_341 ( V_120 ) ;
if ( V_32 ) {
V_446 = F_346 ( V_32 ) ;
goto V_447;
}
F_70 ( & V_170 -> V_448 ) ;
V_32 = F_342 ( & V_170 -> V_444 ,
V_15 >> V_124 , V_11 ) ;
F_73 ( & V_170 -> V_448 ) ;
F_343 () ;
if ( V_32 == - V_86 ) {
V_446 = F_336 ( V_170 , V_15 ) ;
if ( V_446 )
goto V_447;
else
goto V_105;
}
F_332 ( V_11 ) ;
F_248 ( V_449 , & V_11 -> V_330 ) ;
F_348 ( V_11 -> V_150 [ 0 ] ) ;
for ( V_151 = 1 ; V_151 < V_199 ; V_151 ++ ) {
V_63 = V_11 -> V_150 [ V_151 ] ;
F_349 ( V_63 ) ;
F_117 ( V_63 ) ;
}
F_117 ( V_11 -> V_150 [ 0 ] ) ;
return V_11 ;
V_447:
F_40 ( ! F_260 ( & V_11 -> V_17 ) ) ;
for ( V_151 = 0 ; V_151 < V_199 ; V_151 ++ ) {
if ( V_11 -> V_150 [ V_151 ] )
F_117 ( V_11 -> V_150 [ V_151 ] ) ;
}
F_318 ( V_11 ) ;
return V_446 ;
}
static inline void F_350 ( struct V_450 * V_6 )
{
struct V_10 * V_11 =
F_351 ( V_6 , struct V_10 , V_450 ) ;
F_314 ( V_11 ) ;
}
static int F_352 ( struct V_10 * V_11 )
{
F_40 ( F_15 ( & V_11 -> V_17 ) == 0 ) ;
if ( F_260 ( & V_11 -> V_17 ) ) {
if ( F_247 ( V_449 , & V_11 -> V_330 ) ) {
struct V_36 * V_170 = V_11 -> V_170 ;
F_73 ( & V_11 -> V_334 ) ;
F_70 ( & V_170 -> V_448 ) ;
F_353 ( & V_170 -> V_444 ,
V_11 -> V_15 >> V_124 ) ;
F_73 ( & V_170 -> V_448 ) ;
} else {
F_73 ( & V_11 -> V_334 ) ;
}
F_316 ( V_11 ) ;
#ifdef F_354
if ( F_186 ( F_162 ( V_426 , & V_11 -> V_330 ) ) ) {
F_314 ( V_11 ) ;
return 1 ;
}
#endif
F_355 ( & V_11 -> V_450 , F_350 ) ;
return 1 ;
}
F_73 ( & V_11 -> V_334 ) ;
return 0 ;
}
void F_276 ( struct V_10 * V_11 )
{
int V_17 ;
int V_451 ;
if ( ! V_11 )
return;
while ( 1 ) {
V_17 = F_15 ( & V_11 -> V_17 ) ;
if ( V_17 <= 3 )
break;
V_451 = F_356 ( & V_11 -> V_17 , V_17 , V_17 - 1 ) ;
if ( V_451 == V_17 )
return;
}
F_70 ( & V_11 -> V_334 ) ;
if ( F_15 ( & V_11 -> V_17 ) == 2 &&
F_162 ( V_426 , & V_11 -> V_330 ) )
F_357 ( & V_11 -> V_17 ) ;
if ( F_15 ( & V_11 -> V_17 ) == 2 &&
F_162 ( V_445 , & V_11 -> V_330 ) &&
! F_315 ( V_11 ) &&
F_247 ( V_442 , & V_11 -> V_330 ) )
F_357 ( & V_11 -> V_17 ) ;
F_352 ( V_11 ) ;
}
void F_358 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return;
F_70 ( & V_11 -> V_334 ) ;
F_248 ( V_445 , & V_11 -> V_330 ) ;
if ( F_15 ( & V_11 -> V_17 ) == 2 && ! F_315 ( V_11 ) &&
F_247 ( V_442 , & V_11 -> V_330 ) )
F_357 ( & V_11 -> V_17 ) ;
F_352 ( V_11 ) ;
}
void F_359 ( struct V_10 * V_11 )
{
unsigned long V_151 ;
unsigned long V_199 ;
struct V_126 * V_126 ;
V_199 = F_148 ( V_11 -> V_15 , V_11 -> V_20 ) ;
for ( V_151 = 0 ; V_151 < V_199 ; V_151 ++ ) {
V_126 = V_11 -> V_150 [ V_151 ] ;
if ( ! F_119 ( V_126 ) )
continue;
F_118 ( V_126 ) ;
F_40 ( ! F_203 ( V_126 ) ) ;
F_95 ( V_126 ) ;
F_360 ( & V_126 -> V_145 -> V_452 ) ;
if ( ! F_119 ( V_126 ) ) {
F_361 ( & V_126 -> V_145 -> V_453 ,
F_362 ( V_126 ) ,
V_364 ) ;
}
F_363 ( & V_126 -> V_145 -> V_452 ) ;
F_239 ( V_126 ) ;
F_117 ( V_126 ) ;
}
F_40 ( F_15 ( & V_11 -> V_17 ) == 0 ) ;
}
int F_364 ( struct V_10 * V_11 )
{
unsigned long V_151 ;
unsigned long V_199 ;
int V_454 = 0 ;
F_332 ( V_11 ) ;
V_454 = F_257 ( V_335 , & V_11 -> V_330 ) ;
V_199 = F_148 ( V_11 -> V_15 , V_11 -> V_20 ) ;
F_40 ( F_15 ( & V_11 -> V_17 ) == 0 ) ;
F_40 ( ! F_162 ( V_442 , & V_11 -> V_330 ) ) ;
for ( V_151 = 0 ; V_151 < V_199 ; V_151 ++ )
F_365 ( V_11 -> V_150 [ V_151 ] ) ;
return V_454 ;
}
void F_366 ( struct V_10 * V_11 )
{
unsigned long V_151 ;
struct V_126 * V_126 ;
unsigned long V_199 ;
F_253 ( V_440 , & V_11 -> V_330 ) ;
V_199 = F_148 ( V_11 -> V_15 , V_11 -> V_20 ) ;
for ( V_151 = 0 ; V_151 < V_199 ; V_151 ++ ) {
V_126 = V_11 -> V_150 [ V_151 ] ;
if ( V_126 )
F_173 ( V_126 ) ;
}
}
void F_328 ( struct V_10 * V_11 )
{
unsigned long V_151 ;
struct V_126 * V_126 ;
unsigned long V_199 ;
F_248 ( V_440 , & V_11 -> V_330 ) ;
V_199 = F_148 ( V_11 -> V_15 , V_11 -> V_20 ) ;
for ( V_151 = 0 ; V_151 < V_199 ; V_151 ++ ) {
V_126 = V_11 -> V_150 [ V_151 ] ;
F_129 ( V_126 ) ;
}
}
int F_367 ( struct V_10 * V_11 )
{
return F_162 ( V_440 , & V_11 -> V_330 ) ;
}
int F_368 ( struct V_23 * V_24 ,
struct V_10 * V_11 , int V_109 ,
T_13 * V_282 , int V_175 )
{
unsigned long V_151 ;
struct V_126 * V_126 ;
int V_96 ;
int V_32 = 0 ;
int V_455 = 0 ;
int V_456 = 1 ;
unsigned long V_199 ;
unsigned long V_457 = 0 ;
struct V_43 * V_43 = NULL ;
unsigned long V_215 = 0 ;
if ( F_162 ( V_440 , & V_11 -> V_330 ) )
return 0 ;
V_199 = F_148 ( V_11 -> V_15 , V_11 -> V_20 ) ;
for ( V_151 = 0 ; V_151 < V_199 ; V_151 ++ ) {
V_126 = V_11 -> V_150 [ V_151 ] ;
if ( V_109 == V_458 ) {
if ( ! F_251 ( V_126 ) )
goto V_459;
} else {
F_118 ( V_126 ) ;
}
V_455 ++ ;
}
for ( V_151 = 0 ; V_151 < V_199 ; V_151 ++ ) {
V_126 = V_11 -> V_150 [ V_151 ] ;
if ( ! F_213 ( V_126 ) ) {
V_457 ++ ;
V_456 = 0 ;
}
}
if ( V_456 ) {
F_248 ( V_440 , & V_11 -> V_330 ) ;
goto V_459;
}
F_253 ( V_460 , & V_11 -> V_330 ) ;
V_11 -> V_461 = 0 ;
F_262 ( & V_11 -> V_344 , V_457 ) ;
for ( V_151 = 0 ; V_151 < V_199 ; V_151 ++ ) {
V_126 = V_11 -> V_150 [ V_151 ] ;
if ( ! F_213 ( V_126 ) ) {
if ( V_32 ) {
F_357 ( & V_11 -> V_344 ) ;
F_117 ( V_126 ) ;
continue;
}
F_239 ( V_126 ) ;
V_96 = F_227 ( V_24 , V_126 ,
V_282 , & V_43 ,
V_175 , & V_215 ,
V_347 ) ;
if ( V_96 ) {
V_32 = V_96 ;
F_357 ( & V_11 -> V_344 ) ;
}
} else {
F_117 ( V_126 ) ;
}
}
if ( V_43 ) {
V_96 = F_194 ( V_43 , V_175 , V_215 ) ;
if ( V_96 )
return V_96 ;
}
if ( V_32 || V_109 != V_462 )
return V_32 ;
for ( V_151 = 0 ; V_151 < V_199 ; V_151 ++ ) {
V_126 = V_11 -> V_150 [ V_151 ] ;
F_369 ( V_126 ) ;
if ( ! F_213 ( V_126 ) )
V_32 = - V_153 ;
}
return V_32 ;
V_459:
while ( V_455 > 0 ) {
V_455 -- ;
V_126 = V_11 -> V_150 [ V_455 ] ;
F_117 ( V_126 ) ;
}
return V_32 ;
}
void F_370 ( const struct V_10 * V_11 , void * V_463 ,
unsigned long V_15 , unsigned long V_20 )
{
T_11 V_287 ;
T_11 V_59 ;
struct V_126 * V_126 ;
char * V_464 ;
char * V_465 = ( char * ) V_463 ;
T_11 V_466 = V_11 -> V_15 & ( ( T_1 ) V_142 - 1 ) ;
unsigned long V_151 = ( V_466 + V_15 ) >> V_124 ;
if ( V_15 + V_20 > V_11 -> V_20 ) {
F_57 ( 1 , V_84 L_22 ,
V_11 -> V_15 , V_11 -> V_20 , V_15 , V_20 ) ;
memset ( V_465 , 0 , V_20 ) ;
return;
}
V_59 = ( V_466 + V_15 ) & ( V_142 - 1 ) ;
while ( V_20 > 0 ) {
V_126 = V_11 -> V_150 [ V_151 ] ;
V_287 = F_123 ( V_20 , ( V_142 - V_59 ) ) ;
V_464 = F_326 ( V_126 ) ;
memcpy ( V_465 , V_464 + V_59 , V_287 ) ;
V_465 += V_287 ;
V_20 -= V_287 ;
V_59 = 0 ;
V_151 ++ ;
}
}
int F_371 ( const struct V_10 * V_11 ,
void T_18 * V_463 ,
unsigned long V_15 , unsigned long V_20 )
{
T_11 V_287 ;
T_11 V_59 ;
struct V_126 * V_126 ;
char * V_464 ;
char T_18 * V_465 = ( char T_18 * ) V_463 ;
T_11 V_466 = V_11 -> V_15 & ( ( T_1 ) V_142 - 1 ) ;
unsigned long V_151 = ( V_466 + V_15 ) >> V_124 ;
int V_32 = 0 ;
F_40 ( V_15 > V_11 -> V_20 ) ;
F_40 ( V_15 + V_20 > V_11 -> V_15 + V_11 -> V_20 ) ;
V_59 = ( V_466 + V_15 ) & ( V_142 - 1 ) ;
while ( V_20 > 0 ) {
V_126 = V_11 -> V_150 [ V_151 ] ;
V_287 = F_123 ( V_20 , ( V_142 - V_59 ) ) ;
V_464 = F_326 ( V_126 ) ;
if ( F_372 ( V_465 , V_464 + V_59 , V_287 ) ) {
V_32 = - V_467 ;
break;
}
V_465 += V_287 ;
V_20 -= V_287 ;
V_59 = 0 ;
V_151 ++ ;
}
return V_32 ;
}
int F_373 ( const struct V_10 * V_11 ,
unsigned long V_15 , unsigned long V_468 ,
char * * V_380 , unsigned long * V_469 ,
unsigned long * V_470 )
{
T_11 V_59 = V_15 & ( V_142 - 1 ) ;
char * V_464 ;
struct V_126 * V_63 ;
T_11 V_466 = V_11 -> V_15 & ( ( T_1 ) V_142 - 1 ) ;
unsigned long V_151 = ( V_466 + V_15 ) >> V_124 ;
unsigned long V_471 = ( V_466 + V_15 + V_468 - 1 ) >>
V_124 ;
if ( V_15 + V_468 > V_11 -> V_20 ) {
F_57 ( 1 , V_84 L_22 ,
V_11 -> V_15 , V_11 -> V_20 , V_15 , V_468 ) ;
return - V_393 ;
}
if ( V_151 != V_471 )
return 1 ;
if ( V_151 == 0 ) {
V_59 = V_466 ;
* V_469 = 0 ;
} else {
V_59 = 0 ;
* V_469 = ( ( T_1 ) V_151 << V_124 ) - V_466 ;
}
V_63 = V_11 -> V_150 [ V_151 ] ;
V_464 = F_326 ( V_63 ) ;
* V_380 = V_464 + V_59 ;
* V_470 = V_142 - V_59 ;
return 0 ;
}
int F_374 ( const struct V_10 * V_11 , const void * V_472 ,
unsigned long V_15 , unsigned long V_20 )
{
T_11 V_287 ;
T_11 V_59 ;
struct V_126 * V_126 ;
char * V_464 ;
char * V_473 = ( char * ) V_472 ;
T_11 V_466 = V_11 -> V_15 & ( ( T_1 ) V_142 - 1 ) ;
unsigned long V_151 = ( V_466 + V_15 ) >> V_124 ;
int V_32 = 0 ;
F_40 ( V_15 > V_11 -> V_20 ) ;
F_40 ( V_15 + V_20 > V_11 -> V_15 + V_11 -> V_20 ) ;
V_59 = ( V_466 + V_15 ) & ( V_142 - 1 ) ;
while ( V_20 > 0 ) {
V_126 = V_11 -> V_150 [ V_151 ] ;
V_287 = F_123 ( V_20 , ( V_142 - V_59 ) ) ;
V_464 = F_326 ( V_126 ) ;
V_32 = memcmp ( V_473 , V_464 + V_59 , V_287 ) ;
if ( V_32 )
break;
V_473 += V_287 ;
V_20 -= V_287 ;
V_59 = 0 ;
V_151 ++ ;
}
return V_32 ;
}
void F_375 ( struct V_10 * V_11 ,
const void * V_474 )
{
char * V_464 ;
F_40 ( ! F_213 ( V_11 -> V_150 [ 0 ] ) ) ;
V_464 = F_326 ( V_11 -> V_150 [ 0 ] ) ;
memcpy ( V_464 + F_24 ( struct V_475 , V_476 ) , V_474 ,
V_477 ) ;
}
void F_376 ( struct V_10 * V_11 , const void * V_474 )
{
char * V_464 ;
F_40 ( ! F_213 ( V_11 -> V_150 [ 0 ] ) ) ;
V_464 = F_326 ( V_11 -> V_150 [ 0 ] ) ;
memcpy ( V_464 + F_24 ( struct V_475 , V_478 ) , V_474 ,
V_477 ) ;
}
void F_377 ( struct V_10 * V_11 , const void * V_474 ,
unsigned long V_15 , unsigned long V_20 )
{
T_11 V_287 ;
T_11 V_59 ;
struct V_126 * V_126 ;
char * V_464 ;
char * V_439 = ( char * ) V_474 ;
T_11 V_466 = V_11 -> V_15 & ( ( T_1 ) V_142 - 1 ) ;
unsigned long V_151 = ( V_466 + V_15 ) >> V_124 ;
F_40 ( V_15 > V_11 -> V_20 ) ;
F_40 ( V_15 + V_20 > V_11 -> V_15 + V_11 -> V_20 ) ;
V_59 = ( V_466 + V_15 ) & ( V_142 - 1 ) ;
while ( V_20 > 0 ) {
V_126 = V_11 -> V_150 [ V_151 ] ;
F_40 ( ! F_213 ( V_126 ) ) ;
V_287 = F_123 ( V_20 , V_142 - V_59 ) ;
V_464 = F_326 ( V_126 ) ;
memcpy ( V_464 + V_59 , V_439 , V_287 ) ;
V_439 += V_287 ;
V_20 -= V_287 ;
V_59 = 0 ;
V_151 ++ ;
}
}
void F_267 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_20 )
{
T_11 V_287 ;
T_11 V_59 ;
struct V_126 * V_126 ;
char * V_464 ;
T_11 V_466 = V_11 -> V_15 & ( ( T_1 ) V_142 - 1 ) ;
unsigned long V_151 = ( V_466 + V_15 ) >> V_124 ;
F_40 ( V_15 > V_11 -> V_20 ) ;
F_40 ( V_15 + V_20 > V_11 -> V_15 + V_11 -> V_20 ) ;
V_59 = ( V_466 + V_15 ) & ( V_142 - 1 ) ;
while ( V_20 > 0 ) {
V_126 = V_11 -> V_150 [ V_151 ] ;
F_40 ( ! F_213 ( V_126 ) ) ;
V_287 = F_123 ( V_20 , V_142 - V_59 ) ;
V_464 = F_326 ( V_126 ) ;
memset ( V_464 + V_59 , 0 , V_287 ) ;
V_20 -= V_287 ;
V_59 = 0 ;
V_151 ++ ;
}
}
void F_378 ( struct V_10 * V_465 ,
struct V_10 * V_439 )
{
int V_151 ;
unsigned V_199 ;
ASSERT ( V_465 -> V_20 == V_439 -> V_20 ) ;
V_199 = F_148 ( V_465 -> V_15 , V_465 -> V_20 ) ;
for ( V_151 = 0 ; V_151 < V_199 ; V_151 ++ )
F_325 ( F_326 ( V_465 -> V_150 [ V_151 ] ) ,
F_326 ( V_439 -> V_150 [ V_151 ] ) ) ;
}
void F_379 ( struct V_10 * V_465 , struct V_10 * V_439 ,
unsigned long V_479 , unsigned long V_480 ,
unsigned long V_20 )
{
T_1 V_481 = V_465 -> V_20 ;
T_11 V_287 ;
T_11 V_59 ;
struct V_126 * V_126 ;
char * V_464 ;
T_11 V_466 = V_465 -> V_15 & ( ( T_1 ) V_142 - 1 ) ;
unsigned long V_151 = ( V_466 + V_479 ) >> V_124 ;
F_40 ( V_439 -> V_20 != V_481 ) ;
V_59 = ( V_466 + V_479 ) &
( V_142 - 1 ) ;
while ( V_20 > 0 ) {
V_126 = V_465 -> V_150 [ V_151 ] ;
F_40 ( ! F_213 ( V_126 ) ) ;
V_287 = F_123 ( V_20 , ( unsigned long ) ( V_142 - V_59 ) ) ;
V_464 = F_326 ( V_126 ) ;
F_370 ( V_439 , V_464 + V_59 , V_480 , V_287 ) ;
V_480 += V_287 ;
V_20 -= V_287 ;
V_59 = 0 ;
V_151 ++ ;
}
}
void F_380 ( T_19 * V_380 , unsigned int V_15 , int V_20 )
{
T_19 * V_63 = V_380 + F_381 ( V_15 ) ;
const unsigned int V_267 = V_15 + V_20 ;
int V_112 = V_482 - ( V_15 % V_482 ) ;
T_19 V_483 = F_382 ( V_15 ) ;
while ( V_20 - V_112 >= 0 ) {
* V_63 |= V_483 ;
V_20 -= V_112 ;
V_112 = V_482 ;
V_483 = ~ 0 ;
V_63 ++ ;
}
if ( V_20 ) {
V_483 &= F_383 ( V_267 ) ;
* V_63 |= V_483 ;
}
}
void F_384 ( T_19 * V_380 , unsigned int V_15 , int V_20 )
{
T_19 * V_63 = V_380 + F_381 ( V_15 ) ;
const unsigned int V_267 = V_15 + V_20 ;
int V_92 = V_482 - ( V_15 % V_482 ) ;
T_19 V_484 = F_382 ( V_15 ) ;
while ( V_20 - V_92 >= 0 ) {
* V_63 &= ~ V_484 ;
V_20 -= V_92 ;
V_92 = V_482 ;
V_484 = ~ 0 ;
V_63 ++ ;
}
if ( V_20 ) {
V_484 &= F_383 ( V_267 ) ;
* V_63 &= ~ V_484 ;
}
}
static inline void F_385 ( struct V_10 * V_11 ,
unsigned long V_15 , unsigned long V_291 ,
unsigned long * F_362 ,
T_11 * F_128 )
{
T_11 V_466 = V_11 -> V_15 & ( ( T_1 ) V_142 - 1 ) ;
T_11 V_485 = F_381 ( V_291 ) ;
T_11 V_59 ;
V_59 = V_466 + V_15 + V_485 ;
* F_362 = V_59 >> V_124 ;
* F_128 = V_59 & ( V_142 - 1 ) ;
}
int F_386 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_291 )
{
T_19 * V_464 ;
struct V_126 * V_126 ;
unsigned long V_151 ;
T_11 V_59 ;
F_385 ( V_11 , V_15 , V_291 , & V_151 , & V_59 ) ;
V_126 = V_11 -> V_150 [ V_151 ] ;
F_40 ( ! F_213 ( V_126 ) ) ;
V_464 = F_326 ( V_126 ) ;
return 1U & ( V_464 [ V_59 ] >> ( V_291 & ( V_482 - 1 ) ) ) ;
}
void F_387 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_486 , unsigned long V_20 )
{
T_19 * V_464 ;
struct V_126 * V_126 ;
unsigned long V_151 ;
T_11 V_59 ;
const unsigned int V_267 = V_486 + V_20 ;
int V_112 = V_482 - ( V_486 % V_482 ) ;
T_19 V_483 = F_382 ( V_486 ) ;
F_385 ( V_11 , V_15 , V_486 , & V_151 , & V_59 ) ;
V_126 = V_11 -> V_150 [ V_151 ] ;
F_40 ( ! F_213 ( V_126 ) ) ;
V_464 = F_326 ( V_126 ) ;
while ( V_20 >= V_112 ) {
V_464 [ V_59 ] |= V_483 ;
V_20 -= V_112 ;
V_112 = V_482 ;
V_483 = ~ 0 ;
if ( ++ V_59 >= V_142 && V_20 > 0 ) {
V_59 = 0 ;
V_126 = V_11 -> V_150 [ ++ V_151 ] ;
F_40 ( ! F_213 ( V_126 ) ) ;
V_464 = F_326 ( V_126 ) ;
}
}
if ( V_20 ) {
V_483 &= F_383 ( V_267 ) ;
V_464 [ V_59 ] |= V_483 ;
}
}
void F_388 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_486 , unsigned long V_20 )
{
T_19 * V_464 ;
struct V_126 * V_126 ;
unsigned long V_151 ;
T_11 V_59 ;
const unsigned int V_267 = V_486 + V_20 ;
int V_92 = V_482 - ( V_486 % V_482 ) ;
T_19 V_484 = F_382 ( V_486 ) ;
F_385 ( V_11 , V_15 , V_486 , & V_151 , & V_59 ) ;
V_126 = V_11 -> V_150 [ V_151 ] ;
F_40 ( ! F_213 ( V_126 ) ) ;
V_464 = F_326 ( V_126 ) ;
while ( V_20 >= V_92 ) {
V_464 [ V_59 ] &= ~ V_484 ;
V_20 -= V_92 ;
V_92 = V_482 ;
V_484 = ~ 0 ;
if ( ++ V_59 >= V_142 && V_20 > 0 ) {
V_59 = 0 ;
V_126 = V_11 -> V_150 [ ++ V_151 ] ;
F_40 ( ! F_213 ( V_126 ) ) ;
V_464 = F_326 ( V_126 ) ;
}
}
if ( V_20 ) {
V_484 &= F_383 ( V_267 ) ;
V_464 [ V_59 ] &= ~ V_484 ;
}
}
static inline bool F_389 ( unsigned long V_439 , unsigned long V_465 , unsigned long V_20 )
{
unsigned long V_487 = ( V_439 > V_465 ) ? V_439 - V_465 : V_465 - V_439 ;
return V_487 < V_20 ;
}
static void F_390 ( struct V_126 * V_488 , struct V_126 * V_489 ,
unsigned long V_490 , unsigned long V_491 ,
unsigned long V_20 )
{
char * V_492 = F_326 ( V_488 ) ;
char * V_493 ;
int V_494 = 0 ;
if ( V_488 != V_489 ) {
V_493 = F_326 ( V_489 ) ;
} else {
V_493 = V_492 ;
if ( F_389 ( V_491 , V_490 , V_20 ) )
V_494 = 1 ;
}
if ( V_494 )
memmove ( V_492 + V_490 , V_493 + V_491 , V_20 ) ;
else
memcpy ( V_492 + V_490 , V_493 + V_491 , V_20 ) ;
}
void F_391 ( struct V_10 * V_465 , unsigned long V_479 ,
unsigned long V_480 , unsigned long V_20 )
{
struct V_36 * V_170 = V_465 -> V_170 ;
T_11 V_287 ;
T_11 V_495 ;
T_11 V_496 ;
T_11 V_466 = V_465 -> V_15 & ( ( T_1 ) V_142 - 1 ) ;
unsigned long V_497 ;
unsigned long V_498 ;
if ( V_480 + V_20 > V_465 -> V_20 ) {
F_177 ( V_170 ,
L_23 ,
V_480 , V_20 , V_465 -> V_20 ) ;
F_19 ( 1 ) ;
}
if ( V_479 + V_20 > V_465 -> V_20 ) {
F_177 ( V_170 ,
L_24 ,
V_479 , V_20 , V_465 -> V_20 ) ;
F_19 ( 1 ) ;
}
while ( V_20 > 0 ) {
V_495 = ( V_466 + V_479 ) &
( V_142 - 1 ) ;
V_496 = ( V_466 + V_480 ) &
( V_142 - 1 ) ;
V_497 = ( V_466 + V_479 ) >> V_124 ;
V_498 = ( V_466 + V_480 ) >> V_124 ;
V_287 = F_123 ( V_20 , ( unsigned long ) ( V_142 -
V_496 ) ) ;
V_287 = F_112 (unsigned long, cur,
(unsigned long)(PAGE_SIZE - dst_off_in_page)) ;
F_390 ( V_465 -> V_150 [ V_497 ] , V_465 -> V_150 [ V_498 ] ,
V_495 , V_496 , V_287 ) ;
V_480 += V_287 ;
V_479 += V_287 ;
V_20 -= V_287 ;
}
}
void F_392 ( struct V_10 * V_465 , unsigned long V_479 ,
unsigned long V_480 , unsigned long V_20 )
{
struct V_36 * V_170 = V_465 -> V_170 ;
T_11 V_287 ;
T_11 V_495 ;
T_11 V_496 ;
unsigned long V_499 = V_479 + V_20 - 1 ;
unsigned long V_500 = V_480 + V_20 - 1 ;
T_11 V_466 = V_465 -> V_15 & ( ( T_1 ) V_142 - 1 ) ;
unsigned long V_497 ;
unsigned long V_498 ;
if ( V_480 + V_20 > V_465 -> V_20 ) {
F_177 ( V_170 ,
L_25 ,
V_480 , V_20 , V_465 -> V_20 ) ;
F_19 ( 1 ) ;
}
if ( V_479 + V_20 > V_465 -> V_20 ) {
F_177 ( V_170 ,
L_26 ,
V_479 , V_20 , V_465 -> V_20 ) ;
F_19 ( 1 ) ;
}
if ( V_479 < V_480 ) {
F_391 ( V_465 , V_479 , V_480 , V_20 ) ;
return;
}
while ( V_20 > 0 ) {
V_497 = ( V_466 + V_499 ) >> V_124 ;
V_498 = ( V_466 + V_500 ) >> V_124 ;
V_495 = ( V_466 + V_499 ) &
( V_142 - 1 ) ;
V_496 = ( V_466 + V_500 ) &
( V_142 - 1 ) ;
V_287 = F_112 (unsigned long, len, src_off_in_page + 1 ) ;
V_287 = F_123 ( V_287 , V_495 + 1 ) ;
F_390 ( V_465 -> V_150 [ V_497 ] , V_465 -> V_150 [ V_498 ] ,
V_495 - V_287 + 1 ,
V_496 - V_287 + 1 , V_287 ) ;
V_499 -= V_287 ;
V_500 -= V_287 ;
V_20 -= V_287 ;
}
}
int F_393 ( struct V_126 * V_126 )
{
struct V_10 * V_11 ;
F_70 ( & V_126 -> V_145 -> V_367 ) ;
if ( ! F_203 ( V_126 ) ) {
F_73 ( & V_126 -> V_145 -> V_367 ) ;
return 1 ;
}
V_11 = (struct V_10 * ) V_126 -> V_201 ;
F_19 ( ! V_11 ) ;
F_70 ( & V_11 -> V_334 ) ;
if ( F_15 ( & V_11 -> V_17 ) != 1 || F_315 ( V_11 ) ) {
F_73 ( & V_11 -> V_334 ) ;
F_73 ( & V_126 -> V_145 -> V_367 ) ;
return 0 ;
}
F_73 ( & V_126 -> V_145 -> V_367 ) ;
if ( ! F_247 ( V_442 , & V_11 -> V_330 ) ) {
F_73 ( & V_11 -> V_334 ) ;
return 0 ;
}
return F_352 ( V_11 ) ;
}
