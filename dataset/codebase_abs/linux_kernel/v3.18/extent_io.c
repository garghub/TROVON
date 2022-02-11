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
F_18 ( V_31
L_4 ,
V_23 , F_19 ( V_26 ) , V_27 , V_15 , V_16 ) ;
}
}
static inline struct V_32 *
F_20 ( struct V_24 * V_25 )
{
if ( ! V_25 -> V_28 )
return NULL ;
return F_21 ( V_25 -> V_28 -> V_29 -> V_33 ) ;
}
int T_2 F_22 ( void )
{
V_18 = F_23 ( L_5 ,
sizeof( struct V_1 ) , 0 ,
V_34 | V_35 , NULL ) ;
if ( ! V_18 )
return - V_36 ;
V_22 = F_23 ( L_6 ,
sizeof( struct V_10 ) , 0 ,
V_34 | V_35 , NULL ) ;
if ( ! V_22 )
goto V_37;
V_38 = F_24 ( V_39 ,
F_25 ( struct V_40 , V_41 ) ) ;
if ( ! V_38 )
goto V_42;
if ( F_26 ( V_38 , V_39 ) )
goto V_43;
return 0 ;
V_43:
F_27 ( V_38 ) ;
V_38 = NULL ;
V_42:
F_28 ( V_22 ) ;
V_22 = NULL ;
V_37:
F_28 ( V_18 ) ;
V_18 = NULL ;
return - V_36 ;
}
void F_29 ( void )
{
F_9 () ;
F_30 () ;
if ( V_18 )
F_28 ( V_18 ) ;
if ( V_22 )
F_28 ( V_22 ) ;
if ( V_38 )
F_27 ( V_38 ) ;
}
void F_31 ( struct V_24 * V_25 ,
struct V_44 * V_28 )
{
V_25 -> V_2 = V_45 ;
V_25 -> V_46 = NULL ;
V_25 -> V_47 = 0 ;
F_32 ( & V_25 -> V_48 ) ;
V_25 -> V_28 = V_28 ;
}
static struct V_1 * F_33 ( T_3 V_49 )
{
struct V_1 * V_2 ;
V_2 = F_34 ( V_18 , V_49 ) ;
if ( ! V_2 )
return V_2 ;
V_2 -> V_2 = 0 ;
V_2 -> V_50 = 0 ;
F_35 ( & V_2 -> V_3 ) ;
F_3 ( & V_2 -> V_14 , & V_12 ) ;
F_36 ( & V_2 -> V_17 , 1 ) ;
F_37 ( & V_2 -> V_51 ) ;
F_38 ( V_2 , V_49 , V_52 ) ;
return V_2 ;
}
void F_39 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( F_40 ( & V_2 -> V_17 ) ) {
F_41 ( F_1 ( V_2 ) ) ;
F_7 ( & V_2 -> V_14 ) ;
F_42 ( V_2 , V_52 ) ;
F_14 ( V_18 , V_2 ) ;
}
}
static struct V_3 * F_43 ( struct V_53 * V_54 ,
struct V_3 * V_55 ,
T_1 V_56 ,
struct V_3 * V_57 ,
struct V_3 * * * V_58 ,
struct V_3 * * V_59 )
{
struct V_3 * * V_60 ;
struct V_3 * V_61 = NULL ;
struct V_62 * V_9 ;
if ( V_58 && V_59 ) {
V_60 = * V_58 ;
V_61 = * V_59 ;
goto V_63;
}
V_60 = V_55 ? & V_55 : & V_54 -> V_3 ;
while ( * V_60 ) {
V_61 = * V_60 ;
V_9 = F_44 ( V_61 , struct V_62 , V_3 ) ;
if ( V_56 < V_9 -> V_15 )
V_60 = & ( * V_60 ) -> V_64 ;
else if ( V_56 > V_9 -> V_16 )
V_60 = & ( * V_60 ) -> V_65 ;
else
return V_61 ;
}
V_63:
F_45 ( V_57 , V_61 , V_60 ) ;
F_46 ( V_57 , V_54 ) ;
return NULL ;
}
static struct V_3 * F_47 ( struct V_24 * V_25 , T_1 V_56 ,
struct V_3 * * V_66 ,
struct V_3 * * V_67 ,
struct V_3 * * * V_68 ,
struct V_3 * * V_69 )
{
struct V_53 * V_54 = & V_25 -> V_2 ;
struct V_3 * * V_70 = & V_54 -> V_3 ;
struct V_3 * V_71 = NULL ;
struct V_3 * V_72 = NULL ;
struct V_62 * V_9 ;
struct V_62 * V_73 = NULL ;
while ( * V_70 ) {
V_71 = * V_70 ;
V_9 = F_44 ( V_71 , struct V_62 , V_3 ) ;
V_73 = V_9 ;
if ( V_56 < V_9 -> V_15 )
V_70 = & ( * V_70 ) -> V_64 ;
else if ( V_56 > V_9 -> V_16 )
V_70 = & ( * V_70 ) -> V_65 ;
else
return * V_70 ;
}
if ( V_68 )
* V_68 = V_70 ;
if ( V_69 )
* V_69 = V_71 ;
if ( V_66 ) {
V_72 = V_71 ;
while ( V_71 && V_56 > V_73 -> V_16 ) {
V_71 = F_48 ( V_71 ) ;
V_73 = F_44 ( V_71 , struct V_62 , V_3 ) ;
}
* V_66 = V_71 ;
V_71 = V_72 ;
}
if ( V_67 ) {
V_73 = F_44 ( V_71 , struct V_62 , V_3 ) ;
while ( V_71 && V_56 < V_73 -> V_15 ) {
V_71 = F_49 ( V_71 ) ;
V_73 = F_44 ( V_71 , struct V_62 , V_3 ) ;
}
* V_67 = V_71 ;
}
return NULL ;
}
static inline struct V_3 *
F_50 ( struct V_24 * V_25 ,
T_1 V_56 ,
struct V_3 * * * V_68 ,
struct V_3 * * V_69 )
{
struct V_3 * V_71 = NULL ;
struct V_3 * V_74 ;
V_74 = F_47 ( V_25 , V_56 , & V_71 , NULL , V_68 , V_69 ) ;
if ( ! V_74 )
return V_71 ;
return V_74 ;
}
static inline struct V_3 * F_51 ( struct V_24 * V_25 ,
T_1 V_56 )
{
return F_50 ( V_25 , V_56 , NULL , NULL ) ;
}
static void F_52 ( struct V_24 * V_25 , struct V_1 * V_5 ,
struct V_1 * V_75 )
{
if ( V_25 -> V_46 && V_25 -> V_46 -> V_76 )
V_25 -> V_46 -> V_76 ( V_25 -> V_28 -> V_29 , V_5 ,
V_75 ) ;
}
static void F_53 ( struct V_24 * V_25 ,
struct V_1 * V_2 )
{
struct V_1 * V_75 ;
struct V_3 * V_77 ;
if ( V_2 -> V_2 & ( V_78 | V_79 ) )
return;
V_77 = F_49 ( & V_2 -> V_3 ) ;
if ( V_77 ) {
V_75 = F_44 ( V_77 , struct V_1 , V_3 ) ;
if ( V_75 -> V_16 == V_2 -> V_15 - 1 &&
V_75 -> V_2 == V_2 -> V_2 ) {
F_52 ( V_25 , V_2 , V_75 ) ;
V_2 -> V_15 = V_75 -> V_15 ;
F_54 ( & V_75 -> V_3 , & V_25 -> V_2 ) ;
F_35 ( & V_75 -> V_3 ) ;
F_39 ( V_75 ) ;
}
}
V_77 = F_48 ( & V_2 -> V_3 ) ;
if ( V_77 ) {
V_75 = F_44 ( V_77 , struct V_1 , V_3 ) ;
if ( V_75 -> V_15 == V_2 -> V_16 + 1 &&
V_75 -> V_2 == V_2 -> V_2 ) {
F_52 ( V_25 , V_2 , V_75 ) ;
V_2 -> V_16 = V_75 -> V_16 ;
F_54 ( & V_75 -> V_3 , & V_25 -> V_2 ) ;
F_35 ( & V_75 -> V_3 ) ;
F_39 ( V_75 ) ;
}
}
}
static void F_55 ( struct V_24 * V_25 ,
struct V_1 * V_2 , unsigned long * V_80 )
{
if ( V_25 -> V_46 && V_25 -> V_46 -> V_81 )
V_25 -> V_46 -> V_81 ( V_25 -> V_28 -> V_29 , V_2 , V_80 ) ;
}
static void F_56 ( struct V_24 * V_25 ,
struct V_1 * V_2 , unsigned long * V_80 )
{
if ( V_25 -> V_46 && V_25 -> V_46 -> V_82 )
V_25 -> V_46 -> V_82 ( V_25 -> V_28 -> V_29 , V_2 , V_80 ) ;
}
static int F_57 ( struct V_24 * V_25 ,
struct V_1 * V_2 , T_1 V_15 , T_1 V_16 ,
struct V_3 * * * V_60 ,
struct V_3 * * V_61 ,
unsigned long * V_80 )
{
struct V_3 * V_57 ;
if ( V_16 < V_15 )
F_58 ( 1 , V_20 L_7 ,
V_16 , V_15 ) ;
V_2 -> V_15 = V_15 ;
V_2 -> V_16 = V_16 ;
F_59 ( V_25 , V_2 , V_80 ) ;
V_57 = F_43 ( & V_25 -> V_2 , NULL , V_16 , & V_2 -> V_3 , V_60 , V_61 ) ;
if ( V_57 ) {
struct V_1 * V_83 ;
V_83 = F_44 ( V_57 , struct V_1 , V_3 ) ;
F_15 ( V_20 L_8
L_9 ,
V_83 -> V_15 , V_83 -> V_16 , V_15 , V_16 ) ;
return - V_84 ;
}
F_53 ( V_25 , V_2 ) ;
return 0 ;
}
static void F_60 ( struct V_24 * V_25 , struct V_1 * V_85 ,
T_1 V_86 )
{
if ( V_25 -> V_46 && V_25 -> V_46 -> V_87 )
V_25 -> V_46 -> V_87 ( V_25 -> V_28 -> V_29 , V_85 , V_86 ) ;
}
static int F_61 ( struct V_24 * V_25 , struct V_1 * V_85 ,
struct V_1 * V_88 , T_1 V_86 )
{
struct V_3 * V_57 ;
F_60 ( V_25 , V_85 , V_86 ) ;
V_88 -> V_15 = V_85 -> V_15 ;
V_88 -> V_16 = V_86 - 1 ;
V_88 -> V_2 = V_85 -> V_2 ;
V_85 -> V_15 = V_86 ;
V_57 = F_43 ( & V_25 -> V_2 , & V_85 -> V_3 , V_88 -> V_16 ,
& V_88 -> V_3 , NULL , NULL ) ;
if ( V_57 ) {
F_39 ( V_88 ) ;
return - V_84 ;
}
return 0 ;
}
static struct V_1 * F_62 ( struct V_1 * V_2 )
{
struct V_3 * V_13 = F_48 ( & V_2 -> V_3 ) ;
if ( V_13 )
return F_44 ( V_13 , struct V_1 , V_3 ) ;
else
return NULL ;
}
static struct V_1 * F_63 ( struct V_24 * V_25 ,
struct V_1 * V_2 ,
unsigned long * V_80 , int V_89 )
{
struct V_1 * V_13 ;
unsigned long V_90 = * V_80 & ~ V_91 ;
if ( ( V_90 & V_92 ) && ( V_2 -> V_2 & V_92 ) ) {
T_1 V_93 = V_2 -> V_16 - V_2 -> V_15 + 1 ;
F_41 ( V_93 > V_25 -> V_47 ) ;
V_25 -> V_47 -= V_93 ;
}
F_56 ( V_25 , V_2 , V_80 ) ;
V_2 -> V_2 &= ~ V_90 ;
if ( V_89 )
F_64 ( & V_2 -> V_51 ) ;
if ( V_2 -> V_2 == 0 ) {
V_13 = F_62 ( V_2 ) ;
if ( F_1 ( V_2 ) ) {
F_54 ( & V_2 -> V_3 , & V_25 -> V_2 ) ;
F_35 ( & V_2 -> V_3 ) ;
F_39 ( V_2 ) ;
} else {
F_41 ( 1 ) ;
}
} else {
F_53 ( V_25 , V_2 ) ;
V_13 = F_62 ( V_2 ) ;
}
return V_13 ;
}
static struct V_1 *
F_65 ( struct V_1 * V_88 )
{
if ( ! V_88 )
V_88 = F_33 ( V_94 ) ;
return V_88 ;
}
static void F_66 ( struct V_24 * V_25 , int V_95 )
{
F_67 ( F_20 ( V_25 ) , V_95 , L_10
L_11
L_12 ) ;
}
int F_68 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned long V_80 , int V_89 , int V_96 ,
struct V_1 * * V_97 ,
T_3 V_49 )
{
struct V_1 * V_2 ;
struct V_1 * V_98 ;
struct V_1 * V_88 = NULL ;
struct V_3 * V_57 ;
T_1 V_99 ;
int V_95 ;
int V_100 = 0 ;
F_69 ( V_25 , V_15 , V_16 ) ;
if ( V_80 & V_101 )
V_80 |= V_102 ;
if ( V_96 )
V_80 |= ~ V_91 ;
V_80 |= V_103 ;
if ( V_80 & ( V_78 | V_79 ) )
V_100 = 1 ;
V_104:
if ( ! V_88 && ( V_49 & V_105 ) ) {
V_88 = F_33 ( V_49 ) ;
if ( ! V_88 )
return - V_36 ;
}
F_70 ( & V_25 -> V_48 ) ;
if ( V_97 ) {
V_98 = * V_97 ;
if ( V_100 ) {
* V_97 = NULL ;
V_97 = NULL ;
}
if ( V_98 && F_1 ( V_98 ) &&
V_98 -> V_15 <= V_15 && V_98 -> V_16 > V_15 ) {
if ( V_100 )
F_71 ( & V_98 -> V_17 ) ;
V_2 = V_98 ;
goto V_106;
}
if ( V_100 )
F_39 ( V_98 ) ;
}
V_57 = F_51 ( V_25 , V_15 ) ;
if ( ! V_57 )
goto V_107;
V_2 = F_44 ( V_57 , struct V_1 , V_3 ) ;
V_106:
if ( V_2 -> V_15 > V_16 )
goto V_107;
F_41 ( V_2 -> V_16 < V_15 ) ;
V_99 = V_2 -> V_16 ;
if ( ! ( V_2 -> V_2 & V_80 ) ) {
V_2 = F_62 ( V_2 ) ;
goto V_13;
}
if ( V_2 -> V_15 < V_15 ) {
V_88 = F_65 ( V_88 ) ;
F_72 ( ! V_88 ) ;
V_95 = F_61 ( V_25 , V_2 , V_88 , V_15 ) ;
if ( V_95 )
F_66 ( V_25 , V_95 ) ;
V_88 = NULL ;
if ( V_95 )
goto V_107;
if ( V_2 -> V_16 <= V_16 ) {
V_2 = F_63 ( V_25 , V_2 , & V_80 , V_89 ) ;
goto V_13;
}
goto V_108;
}
if ( V_2 -> V_15 <= V_16 && V_2 -> V_16 > V_16 ) {
V_88 = F_65 ( V_88 ) ;
F_72 ( ! V_88 ) ;
V_95 = F_61 ( V_25 , V_2 , V_88 , V_16 + 1 ) ;
if ( V_95 )
F_66 ( V_25 , V_95 ) ;
if ( V_89 )
F_64 ( & V_2 -> V_51 ) ;
F_63 ( V_25 , V_88 , & V_80 , V_89 ) ;
V_88 = NULL ;
goto V_107;
}
V_2 = F_63 ( V_25 , V_2 , & V_80 , V_89 ) ;
V_13:
if ( V_99 == ( T_1 ) - 1 )
goto V_107;
V_15 = V_99 + 1 ;
if ( V_15 <= V_16 && V_2 && ! F_73 () )
goto V_106;
goto V_108;
V_107:
F_74 ( & V_25 -> V_48 ) ;
if ( V_88 )
F_39 ( V_88 ) ;
return 0 ;
V_108:
if ( V_15 > V_16 )
goto V_107;
F_74 ( & V_25 -> V_48 ) ;
if ( V_49 & V_105 )
F_75 () ;
goto V_104;
}
static void F_76 ( struct V_24 * V_25 ,
struct V_1 * V_2 )
__releases( V_25 -> V_48 )
__acquires( V_25 -> V_48 )
{
F_77 ( V_109 ) ;
F_78 ( & V_2 -> V_51 , & V_109 , V_110 ) ;
F_74 ( & V_25 -> V_48 ) ;
F_79 () ;
F_70 ( & V_25 -> V_48 ) ;
F_80 ( & V_2 -> V_51 , & V_109 ) ;
}
static void F_81 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned long V_80 )
{
struct V_1 * V_2 ;
struct V_3 * V_57 ;
F_69 ( V_25 , V_15 , V_16 ) ;
F_70 ( & V_25 -> V_48 ) ;
V_104:
while ( 1 ) {
V_57 = F_51 ( V_25 , V_15 ) ;
V_111:
if ( ! V_57 )
break;
V_2 = F_44 ( V_57 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 > V_16 )
goto V_107;
if ( V_2 -> V_2 & V_80 ) {
V_15 = V_2 -> V_15 ;
F_82 ( & V_2 -> V_17 ) ;
F_76 ( V_25 , V_2 ) ;
F_39 ( V_2 ) ;
goto V_104;
}
V_15 = V_2 -> V_16 + 1 ;
if ( V_15 > V_16 )
break;
if ( ! F_83 ( & V_25 -> V_48 ) ) {
V_57 = F_48 ( V_57 ) ;
goto V_111;
}
}
V_107:
F_74 ( & V_25 -> V_48 ) ;
}
static void F_59 ( struct V_24 * V_25 ,
struct V_1 * V_2 ,
unsigned long * V_80 )
{
unsigned long V_112 = * V_80 & ~ V_91 ;
F_55 ( V_25 , V_2 , V_80 ) ;
if ( ( V_112 & V_92 ) && ! ( V_2 -> V_2 & V_92 ) ) {
T_1 V_93 = V_2 -> V_16 - V_2 -> V_15 + 1 ;
V_25 -> V_47 += V_93 ;
}
V_2 -> V_2 |= V_112 ;
}
static void F_84 ( struct V_1 * V_2 ,
struct V_1 * * V_113 )
{
if ( V_113 && ! ( * V_113 ) ) {
if ( V_2 -> V_2 & ( V_78 | V_79 ) ) {
* V_113 = V_2 ;
F_82 ( & V_2 -> V_17 ) ;
}
}
}
static int T_4
F_85 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned long V_80 , unsigned long V_114 ,
T_1 * V_115 , struct V_1 * * V_97 ,
T_3 V_49 )
{
struct V_1 * V_2 ;
struct V_1 * V_88 = NULL ;
struct V_3 * V_57 ;
struct V_3 * * V_60 ;
struct V_3 * V_61 ;
int V_95 = 0 ;
T_1 V_116 ;
T_1 V_99 ;
F_69 ( V_25 , V_15 , V_16 ) ;
V_80 |= V_103 ;
V_104:
if ( ! V_88 && ( V_49 & V_105 ) ) {
V_88 = F_33 ( V_49 ) ;
F_72 ( ! V_88 ) ;
}
F_70 ( & V_25 -> V_48 ) ;
if ( V_97 && * V_97 ) {
V_2 = * V_97 ;
if ( V_2 -> V_15 <= V_15 && V_2 -> V_16 > V_15 &&
F_1 ( V_2 ) ) {
V_57 = & V_2 -> V_3 ;
goto V_106;
}
}
V_57 = F_50 ( V_25 , V_15 , & V_60 , & V_61 ) ;
if ( ! V_57 ) {
V_88 = F_65 ( V_88 ) ;
F_72 ( ! V_88 ) ;
V_95 = F_57 ( V_25 , V_88 , V_15 , V_16 ,
& V_60 , & V_61 , & V_80 ) ;
if ( V_95 )
F_66 ( V_25 , V_95 ) ;
F_84 ( V_88 , V_97 ) ;
V_88 = NULL ;
goto V_107;
}
V_2 = F_44 ( V_57 , struct V_1 , V_3 ) ;
V_106:
V_116 = V_2 -> V_15 ;
V_99 = V_2 -> V_16 ;
if ( V_2 -> V_15 == V_15 && V_2 -> V_16 <= V_16 ) {
if ( V_2 -> V_2 & V_114 ) {
* V_115 = V_2 -> V_15 ;
V_95 = - V_84 ;
goto V_107;
}
F_59 ( V_25 , V_2 , & V_80 ) ;
F_84 ( V_2 , V_97 ) ;
F_53 ( V_25 , V_2 ) ;
if ( V_99 == ( T_1 ) - 1 )
goto V_107;
V_15 = V_99 + 1 ;
V_2 = F_62 ( V_2 ) ;
if ( V_15 < V_16 && V_2 && V_2 -> V_15 == V_15 &&
! F_73 () )
goto V_106;
goto V_108;
}
if ( V_2 -> V_15 < V_15 ) {
if ( V_2 -> V_2 & V_114 ) {
* V_115 = V_15 ;
V_95 = - V_84 ;
goto V_107;
}
V_88 = F_65 ( V_88 ) ;
F_72 ( ! V_88 ) ;
V_95 = F_61 ( V_25 , V_2 , V_88 , V_15 ) ;
if ( V_95 )
F_66 ( V_25 , V_95 ) ;
V_88 = NULL ;
if ( V_95 )
goto V_107;
if ( V_2 -> V_16 <= V_16 ) {
F_59 ( V_25 , V_2 , & V_80 ) ;
F_84 ( V_2 , V_97 ) ;
F_53 ( V_25 , V_2 ) ;
if ( V_99 == ( T_1 ) - 1 )
goto V_107;
V_15 = V_99 + 1 ;
V_2 = F_62 ( V_2 ) ;
if ( V_15 < V_16 && V_2 && V_2 -> V_15 == V_15 &&
! F_73 () )
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
V_88 = F_65 ( V_88 ) ;
F_72 ( ! V_88 ) ;
V_95 = F_57 ( V_25 , V_88 , V_15 , V_117 ,
NULL , NULL , & V_80 ) ;
if ( V_95 )
F_66 ( V_25 , V_95 ) ;
F_84 ( V_88 , V_97 ) ;
V_88 = NULL ;
V_15 = V_117 + 1 ;
goto V_108;
}
if ( V_2 -> V_15 <= V_16 && V_2 -> V_16 > V_16 ) {
if ( V_2 -> V_2 & V_114 ) {
* V_115 = V_15 ;
V_95 = - V_84 ;
goto V_107;
}
V_88 = F_65 ( V_88 ) ;
F_72 ( ! V_88 ) ;
V_95 = F_61 ( V_25 , V_2 , V_88 , V_16 + 1 ) ;
if ( V_95 )
F_66 ( V_25 , V_95 ) ;
F_59 ( V_25 , V_88 , & V_80 ) ;
F_84 ( V_88 , V_97 ) ;
F_53 ( V_25 , V_88 ) ;
V_88 = NULL ;
goto V_107;
}
goto V_108;
V_107:
F_74 ( & V_25 -> V_48 ) ;
if ( V_88 )
F_39 ( V_88 ) ;
return V_95 ;
V_108:
if ( V_15 > V_16 )
goto V_107;
F_74 ( & V_25 -> V_48 ) ;
if ( V_49 & V_105 )
F_75 () ;
goto V_104;
}
int F_86 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned long V_80 , T_1 * V_115 ,
struct V_1 * * V_97 , T_3 V_49 )
{
return F_85 ( V_25 , V_15 , V_16 , V_80 , 0 , V_115 ,
V_97 , V_49 ) ;
}
int F_87 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned long V_80 , unsigned long V_118 ,
struct V_1 * * V_97 , T_3 V_49 )
{
struct V_1 * V_2 ;
struct V_1 * V_88 = NULL ;
struct V_3 * V_57 ;
struct V_3 * * V_60 ;
struct V_3 * V_61 ;
int V_95 = 0 ;
T_1 V_116 ;
T_1 V_99 ;
F_69 ( V_25 , V_15 , V_16 ) ;
V_104:
if ( ! V_88 && ( V_49 & V_105 ) ) {
V_88 = F_33 ( V_49 ) ;
if ( ! V_88 )
return - V_36 ;
}
F_70 ( & V_25 -> V_48 ) ;
if ( V_97 && * V_97 ) {
V_2 = * V_97 ;
if ( V_2 -> V_15 <= V_15 && V_2 -> V_16 > V_15 &&
F_1 ( V_2 ) ) {
V_57 = & V_2 -> V_3 ;
goto V_106;
}
}
V_57 = F_50 ( V_25 , V_15 , & V_60 , & V_61 ) ;
if ( ! V_57 ) {
V_88 = F_65 ( V_88 ) ;
if ( ! V_88 ) {
V_95 = - V_36 ;
goto V_107;
}
V_95 = F_57 ( V_25 , V_88 , V_15 , V_16 ,
& V_60 , & V_61 , & V_80 ) ;
if ( V_95 )
F_66 ( V_25 , V_95 ) ;
F_84 ( V_88 , V_97 ) ;
V_88 = NULL ;
goto V_107;
}
V_2 = F_44 ( V_57 , struct V_1 , V_3 ) ;
V_106:
V_116 = V_2 -> V_15 ;
V_99 = V_2 -> V_16 ;
if ( V_2 -> V_15 == V_15 && V_2 -> V_16 <= V_16 ) {
F_59 ( V_25 , V_2 , & V_80 ) ;
F_84 ( V_2 , V_97 ) ;
V_2 = F_63 ( V_25 , V_2 , & V_118 , 0 ) ;
if ( V_99 == ( T_1 ) - 1 )
goto V_107;
V_15 = V_99 + 1 ;
if ( V_15 < V_16 && V_2 && V_2 -> V_15 == V_15 &&
! F_73 () )
goto V_106;
goto V_108;
}
if ( V_2 -> V_15 < V_15 ) {
V_88 = F_65 ( V_88 ) ;
if ( ! V_88 ) {
V_95 = - V_36 ;
goto V_107;
}
V_95 = F_61 ( V_25 , V_2 , V_88 , V_15 ) ;
if ( V_95 )
F_66 ( V_25 , V_95 ) ;
V_88 = NULL ;
if ( V_95 )
goto V_107;
if ( V_2 -> V_16 <= V_16 ) {
F_59 ( V_25 , V_2 , & V_80 ) ;
F_84 ( V_2 , V_97 ) ;
V_2 = F_63 ( V_25 , V_2 , & V_118 , 0 ) ;
if ( V_99 == ( T_1 ) - 1 )
goto V_107;
V_15 = V_99 + 1 ;
if ( V_15 < V_16 && V_2 && V_2 -> V_15 == V_15 &&
! F_73 () )
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
V_88 = F_65 ( V_88 ) ;
if ( ! V_88 ) {
V_95 = - V_36 ;
goto V_107;
}
V_95 = F_57 ( V_25 , V_88 , V_15 , V_117 ,
NULL , NULL , & V_80 ) ;
if ( V_95 )
F_66 ( V_25 , V_95 ) ;
F_84 ( V_88 , V_97 ) ;
V_88 = NULL ;
V_15 = V_117 + 1 ;
goto V_108;
}
if ( V_2 -> V_15 <= V_16 && V_2 -> V_16 > V_16 ) {
V_88 = F_65 ( V_88 ) ;
if ( ! V_88 ) {
V_95 = - V_36 ;
goto V_107;
}
V_95 = F_61 ( V_25 , V_2 , V_88 , V_16 + 1 ) ;
if ( V_95 )
F_66 ( V_25 , V_95 ) ;
F_59 ( V_25 , V_88 , & V_80 ) ;
F_84 ( V_88 , V_97 ) ;
F_63 ( V_25 , V_88 , & V_118 , 0 ) ;
V_88 = NULL ;
goto V_107;
}
goto V_108;
V_107:
F_74 ( & V_25 -> V_48 ) ;
if ( V_88 )
F_39 ( V_88 ) ;
return V_95 ;
V_108:
if ( V_15 > V_16 )
goto V_107;
F_74 ( & V_25 -> V_48 ) ;
if ( V_49 & V_105 )
F_75 () ;
goto V_104;
}
int F_88 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
T_3 V_49 )
{
return F_86 ( V_25 , V_15 , V_16 , V_92 , NULL ,
NULL , V_49 ) ;
}
int F_89 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned long V_80 , T_3 V_49 )
{
return F_86 ( V_25 , V_15 , V_16 , V_80 , NULL ,
NULL , V_49 ) ;
}
int F_90 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned long V_80 , T_3 V_49 )
{
return F_68 ( V_25 , V_15 , V_16 , V_80 , 0 , 0 , NULL , V_49 ) ;
}
int F_91 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
struct V_1 * * V_97 , T_3 V_49 )
{
return F_86 ( V_25 , V_15 , V_16 ,
V_101 | V_119 ,
NULL , V_97 , V_49 ) ;
}
int F_92 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
struct V_1 * * V_97 , T_3 V_49 )
{
return F_86 ( V_25 , V_15 , V_16 ,
V_101 | V_119 | V_120 ,
NULL , V_97 , V_49 ) ;
}
int F_93 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
T_3 V_49 )
{
return F_68 ( V_25 , V_15 , V_16 ,
V_92 | V_101 |
V_121 , 0 , 0 , NULL , V_49 ) ;
}
int F_94 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
T_3 V_49 )
{
return F_86 ( V_25 , V_15 , V_16 , V_122 , NULL ,
NULL , V_49 ) ;
}
int F_95 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
struct V_1 * * V_97 , T_3 V_49 )
{
return F_86 ( V_25 , V_15 , V_16 , V_119 , NULL ,
V_97 , V_49 ) ;
}
int F_96 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
struct V_1 * * V_97 , T_3 V_49 )
{
return F_68 ( V_25 , V_15 , V_16 , V_119 , 0 , 0 ,
V_97 , V_49 ) ;
}
int F_97 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned long V_80 , struct V_1 * * V_97 )
{
int V_95 ;
T_1 V_115 ;
while ( 1 ) {
V_95 = F_85 ( V_25 , V_15 , V_16 , V_123 | V_80 ,
V_123 , & V_115 ,
V_97 , V_124 ) ;
if ( V_95 == - V_84 ) {
F_81 ( V_25 , V_115 , V_16 , V_123 ) ;
V_15 = V_115 ;
} else
break;
F_41 ( V_15 > V_16 ) ;
}
return V_95 ;
}
int F_98 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 )
{
return F_97 ( V_25 , V_15 , V_16 , 0 , NULL ) ;
}
int F_99 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 )
{
int V_95 ;
T_1 V_115 ;
V_95 = F_85 ( V_25 , V_15 , V_16 , V_123 , V_123 ,
& V_115 , NULL , V_124 ) ;
if ( V_95 == - V_84 ) {
if ( V_115 > V_15 )
F_68 ( V_25 , V_15 , V_115 - 1 ,
V_123 , 1 , 0 , NULL , V_124 ) ;
return 0 ;
}
return 1 ;
}
int F_100 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
struct V_1 * * V_98 , T_3 V_49 )
{
return F_68 ( V_25 , V_15 , V_16 , V_123 , 1 , 0 , V_98 ,
V_49 ) ;
}
int F_101 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 )
{
return F_68 ( V_25 , V_15 , V_16 , V_123 , 1 , 0 , NULL ,
V_124 ) ;
}
int F_102 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_125 = V_15 >> V_126 ;
unsigned long V_127 = V_16 >> V_126 ;
struct V_128 * V_128 ;
while ( V_125 <= V_127 ) {
V_128 = F_103 ( V_26 -> V_129 , V_125 ) ;
F_72 ( ! V_128 ) ;
F_104 ( V_128 ) ;
F_105 ( V_128 ) ;
V_125 ++ ;
}
return 0 ;
}
int F_106 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_125 = V_15 >> V_126 ;
unsigned long V_127 = V_16 >> V_126 ;
struct V_128 * V_128 ;
while ( V_125 <= V_127 ) {
V_128 = F_103 ( V_26 -> V_129 , V_125 ) ;
F_72 ( ! V_128 ) ;
F_107 ( V_128 ) ;
F_108 ( V_128 ) ;
F_105 ( V_128 ) ;
V_125 ++ ;
}
return 0 ;
}
static int F_109 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_125 = V_15 >> V_126 ;
unsigned long V_127 = V_16 >> V_126 ;
struct V_128 * V_128 ;
while ( V_125 <= V_127 ) {
V_128 = F_103 ( V_25 -> V_28 , V_125 ) ;
F_72 ( ! V_128 ) ;
F_110 ( V_128 ) ;
F_105 ( V_128 ) ;
V_125 ++ ;
}
return 0 ;
}
static struct V_1 *
F_111 ( struct V_24 * V_25 ,
T_1 V_15 , unsigned long V_80 )
{
struct V_3 * V_57 ;
struct V_1 * V_2 ;
V_57 = F_51 ( V_25 , V_15 ) ;
if ( ! V_57 )
goto V_107;
while ( 1 ) {
V_2 = F_44 ( V_57 , struct V_1 , V_3 ) ;
if ( V_2 -> V_16 >= V_15 && ( V_2 -> V_2 & V_80 ) )
return V_2 ;
V_57 = F_48 ( V_57 ) ;
if ( ! V_57 )
break;
}
V_107:
return NULL ;
}
int F_112 ( struct V_24 * V_25 , T_1 V_15 ,
T_1 * V_130 , T_1 * V_131 , unsigned long V_80 ,
struct V_1 * * V_97 )
{
struct V_1 * V_2 ;
struct V_3 * V_70 ;
int V_74 = 1 ;
F_70 ( & V_25 -> V_48 ) ;
if ( V_97 && * V_97 ) {
V_2 = * V_97 ;
if ( V_2 -> V_16 == V_15 - 1 && F_1 ( V_2 ) ) {
V_70 = F_48 ( & V_2 -> V_3 ) ;
while ( V_70 ) {
V_2 = F_44 ( V_70 , struct V_1 ,
V_3 ) ;
if ( V_2 -> V_2 & V_80 )
goto V_132;
V_70 = F_48 ( V_70 ) ;
}
F_39 ( * V_97 ) ;
* V_97 = NULL ;
goto V_107;
}
F_39 ( * V_97 ) ;
* V_97 = NULL ;
}
V_2 = F_111 ( V_25 , V_15 , V_80 ) ;
V_132:
if ( V_2 ) {
F_84 ( V_2 , V_97 ) ;
* V_130 = V_2 -> V_15 ;
* V_131 = V_2 -> V_16 ;
V_74 = 0 ;
}
V_107:
F_74 ( & V_25 -> V_48 ) ;
return V_74 ;
}
static T_5 T_1 F_113 ( struct V_24 * V_25 ,
T_1 * V_15 , T_1 * V_16 , T_1 V_133 ,
struct V_1 * * V_97 )
{
struct V_3 * V_57 ;
struct V_1 * V_2 ;
T_1 V_134 = * V_15 ;
T_1 V_83 = 0 ;
T_1 V_135 = 0 ;
F_70 ( & V_25 -> V_48 ) ;
V_57 = F_51 ( V_25 , V_134 ) ;
if ( ! V_57 ) {
if ( ! V_83 )
* V_16 = ( T_1 ) - 1 ;
goto V_107;
}
while ( 1 ) {
V_2 = F_44 ( V_57 , struct V_1 , V_3 ) ;
if ( V_83 && ( V_2 -> V_15 != V_134 ||
( V_2 -> V_2 & V_79 ) ) ) {
goto V_107;
}
if ( ! ( V_2 -> V_2 & V_101 ) ) {
if ( ! V_83 )
* V_16 = V_2 -> V_16 ;
goto V_107;
}
if ( ! V_83 ) {
* V_15 = V_2 -> V_15 ;
* V_97 = V_2 ;
F_82 ( & V_2 -> V_17 ) ;
}
V_83 ++ ;
* V_16 = V_2 -> V_16 ;
V_134 = V_2 -> V_16 + 1 ;
V_57 = F_48 ( V_57 ) ;
V_135 += V_2 -> V_16 - V_2 -> V_15 + 1 ;
if ( V_135 >= V_133 )
break;
if ( ! V_57 )
break;
}
V_107:
F_74 ( & V_25 -> V_48 ) ;
return V_83 ;
}
static T_5 void F_114 ( struct V_26 * V_26 ,
struct V_128 * V_136 ,
T_1 V_15 , T_1 V_16 )
{
int V_74 ;
struct V_128 * V_137 [ 16 ] ;
unsigned long V_125 = V_15 >> V_126 ;
unsigned long V_127 = V_16 >> V_126 ;
unsigned long V_138 = V_127 - V_125 + 1 ;
int V_139 ;
if ( V_125 == V_136 -> V_125 && V_127 == V_125 )
return;
while ( V_138 > 0 ) {
V_74 = F_115 ( V_26 -> V_129 , V_125 ,
F_116 (unsigned long, nr_pages,
ARRAY_SIZE(pages)) , V_137 ) ;
for ( V_139 = 0 ; V_139 < V_74 ; V_139 ++ ) {
if ( V_137 [ V_139 ] != V_136 )
F_117 ( V_137 [ V_139 ] ) ;
F_105 ( V_137 [ V_139 ] ) ;
}
V_138 -= V_74 ;
V_125 += V_74 ;
F_75 () ;
}
}
static T_5 int F_118 ( struct V_26 * V_26 ,
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
int V_74 ;
int V_139 ;
if ( V_125 == V_136 -> V_125 && V_125 == V_127 )
return 0 ;
V_144 = V_127 - V_125 + 1 ;
while ( V_144 > 0 ) {
V_74 = F_115 ( V_26 -> V_129 , V_125 ,
F_116 (unsigned long,
nrpages, ARRAY_SIZE(pages)) , V_137 ) ;
if ( V_74 == 0 ) {
V_74 = - V_145 ;
goto V_146;
}
for ( V_139 = 0 ; V_139 < V_74 ; V_139 ++ ) {
if ( V_137 [ V_139 ] != V_136 ) {
F_119 ( V_137 [ V_139 ] ) ;
if ( ! F_120 ( V_137 [ V_139 ] ) ||
V_137 [ V_139 ] -> V_28 != V_26 -> V_129 ) {
V_74 = - V_145 ;
F_117 ( V_137 [ V_139 ] ) ;
F_105 ( V_137 [ V_139 ] ) ;
goto V_146;
}
}
F_105 ( V_137 [ V_139 ] ) ;
V_143 ++ ;
}
V_144 -= V_74 ;
V_125 += V_74 ;
F_75 () ;
}
V_74 = 0 ;
V_146:
if ( V_74 && V_143 ) {
F_114 ( V_26 , V_136 ,
V_140 ,
( ( T_1 ) ( V_142 + V_143 - 1 ) ) <<
V_126 ) ;
}
return V_74 ;
}
STATIC T_1 F_121 ( struct V_26 * V_26 ,
struct V_24 * V_25 ,
struct V_128 * V_136 , T_1 * V_15 ,
T_1 * V_16 , T_1 V_133 )
{
T_1 V_140 ;
T_1 V_141 ;
T_1 V_83 ;
struct V_1 * V_97 = NULL ;
int V_74 ;
int V_147 = 0 ;
V_104:
V_140 = * V_15 ;
V_141 = 0 ;
V_83 = F_113 ( V_25 , & V_140 , & V_141 ,
V_133 , & V_97 ) ;
if ( ! V_83 || V_141 <= * V_15 ) {
* V_15 = V_140 ;
* V_16 = V_141 ;
F_39 ( V_97 ) ;
return 0 ;
}
if ( V_140 < * V_15 )
V_140 = * V_15 ;
if ( V_141 + 1 - V_140 > V_133 )
V_141 = V_140 + V_133 - 1 ;
V_74 = F_118 ( V_26 , V_136 ,
V_140 , V_141 ) ;
if ( V_74 == - V_145 ) {
F_39 ( V_97 ) ;
V_97 = NULL ;
if ( ! V_147 ) {
V_133 = V_148 ;
V_147 = 1 ;
goto V_104;
} else {
V_83 = 0 ;
goto V_149;
}
}
F_72 ( V_74 ) ;
F_97 ( V_25 , V_140 , V_141 , 0 , & V_97 ) ;
V_74 = F_122 ( V_25 , V_140 , V_141 ,
V_101 , 1 , V_97 ) ;
if ( ! V_74 ) {
F_100 ( V_25 , V_140 , V_141 ,
& V_97 , V_124 ) ;
F_114 ( V_26 , V_136 ,
V_140 , V_141 ) ;
F_75 () ;
goto V_104;
}
F_39 ( V_97 ) ;
* V_15 = V_140 ;
* V_16 = V_141 ;
V_149:
return V_83 ;
}
int F_123 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_16 ,
struct V_128 * V_136 ,
unsigned long V_118 ,
unsigned long V_150 )
{
struct V_24 * V_25 = & F_124 ( V_26 ) -> V_151 ;
int V_74 ;
struct V_128 * V_137 [ 16 ] ;
unsigned long V_125 = V_15 >> V_126 ;
unsigned long V_127 = V_16 >> V_126 ;
unsigned long V_138 = V_127 - V_125 + 1 ;
int V_139 ;
F_68 ( V_25 , V_15 , V_16 , V_118 , 1 , 0 , NULL , V_124 ) ;
if ( V_150 == 0 )
return 0 ;
while ( V_138 > 0 ) {
V_74 = F_115 ( V_26 -> V_129 , V_125 ,
F_116 (unsigned long,
nr_pages, ARRAY_SIZE(pages)) , V_137 ) ;
for ( V_139 = 0 ; V_139 < V_74 ; V_139 ++ ) {
if ( V_150 & V_152 )
F_125 ( V_137 [ V_139 ] ) ;
if ( V_137 [ V_139 ] == V_136 ) {
F_105 ( V_137 [ V_139 ] ) ;
continue;
}
if ( V_150 & V_153 )
F_104 ( V_137 [ V_139 ] ) ;
if ( V_150 & V_154 )
F_110 ( V_137 [ V_139 ] ) ;
if ( V_150 & V_155 )
F_126 ( V_137 [ V_139 ] ) ;
if ( V_150 & V_156 )
F_117 ( V_137 [ V_139 ] ) ;
F_105 ( V_137 [ V_139 ] ) ;
}
V_138 -= V_74 ;
V_125 += V_74 ;
F_75 () ;
}
return 0 ;
}
T_1 F_127 ( struct V_24 * V_25 ,
T_1 * V_15 , T_1 V_157 , T_1 V_133 ,
unsigned long V_80 , int V_158 )
{
struct V_3 * V_57 ;
struct V_1 * V_2 ;
T_1 V_134 = * V_15 ;
T_1 V_135 = 0 ;
T_1 V_159 = 0 ;
int V_83 = 0 ;
if ( F_41 ( V_157 <= V_134 ) )
return 0 ;
F_70 ( & V_25 -> V_48 ) ;
if ( V_134 == 0 && V_80 == V_92 ) {
V_135 = V_25 -> V_47 ;
goto V_107;
}
V_57 = F_51 ( V_25 , V_134 ) ;
if ( ! V_57 )
goto V_107;
while ( 1 ) {
V_2 = F_44 ( V_57 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 > V_157 )
break;
if ( V_158 && V_83 && V_2 -> V_15 > V_159 + 1 )
break;
if ( V_2 -> V_16 >= V_134 && ( V_2 -> V_2 & V_80 ) == V_80 ) {
V_135 += F_128 ( V_157 , V_2 -> V_16 ) + 1 -
F_129 ( V_134 , V_2 -> V_15 ) ;
if ( V_135 >= V_133 )
break;
if ( ! V_83 ) {
* V_15 = F_129 ( V_134 , V_2 -> V_15 ) ;
V_83 = 1 ;
}
V_159 = V_2 -> V_16 ;
} else if ( V_158 && V_83 ) {
break;
}
V_57 = F_48 ( V_57 ) ;
if ( ! V_57 )
break;
}
V_107:
F_74 ( & V_25 -> V_48 ) ;
return V_135 ;
}
static int F_130 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_50 )
{
struct V_3 * V_57 ;
struct V_1 * V_2 ;
int V_74 = 0 ;
F_70 ( & V_25 -> V_48 ) ;
V_57 = F_51 ( V_25 , V_15 ) ;
if ( ! V_57 ) {
V_74 = - V_160 ;
goto V_107;
}
V_2 = F_44 ( V_57 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 != V_15 ) {
V_74 = - V_160 ;
goto V_107;
}
V_2 -> V_50 = V_50 ;
V_107:
F_74 ( & V_25 -> V_48 ) ;
return V_74 ;
}
int F_131 ( struct V_24 * V_25 , T_1 V_15 , T_1 * V_50 )
{
struct V_3 * V_57 ;
struct V_1 * V_2 ;
int V_74 = 0 ;
F_70 ( & V_25 -> V_48 ) ;
V_57 = F_51 ( V_25 , V_15 ) ;
if ( ! V_57 ) {
V_74 = - V_160 ;
goto V_107;
}
V_2 = F_44 ( V_57 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 != V_15 ) {
V_74 = - V_160 ;
goto V_107;
}
* V_50 = V_2 -> V_50 ;
V_107:
F_74 ( & V_25 -> V_48 ) ;
return V_74 ;
}
int F_122 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned long V_80 , int V_161 , struct V_1 * V_98 )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_57 ;
int V_162 = 0 ;
F_70 ( & V_25 -> V_48 ) ;
if ( V_98 && F_1 ( V_98 ) && V_98 -> V_15 <= V_15 &&
V_98 -> V_16 > V_15 )
V_57 = & V_98 -> V_3 ;
else
V_57 = F_51 ( V_25 , V_15 ) ;
while ( V_57 && V_15 <= V_16 ) {
V_2 = F_44 ( V_57 , struct V_1 , V_3 ) ;
if ( V_161 && V_2 -> V_15 > V_15 ) {
V_162 = 0 ;
break;
}
if ( V_2 -> V_15 > V_16 )
break;
if ( V_2 -> V_2 & V_80 ) {
V_162 = 1 ;
if ( ! V_161 )
break;
} else if ( V_161 ) {
V_162 = 0 ;
break;
}
if ( V_2 -> V_16 == ( T_1 ) - 1 )
break;
V_15 = V_2 -> V_16 + 1 ;
if ( V_15 > V_16 )
break;
V_57 = F_48 ( V_57 ) ;
if ( ! V_57 ) {
if ( V_161 )
V_162 = 0 ;
break;
}
}
F_74 ( & V_25 -> V_48 ) ;
return V_162 ;
}
static void F_132 ( struct V_24 * V_25 , struct V_128 * V_128 )
{
T_1 V_15 = F_133 ( V_128 ) ;
T_1 V_16 = V_15 + V_148 - 1 ;
if ( F_122 ( V_25 , V_15 , V_16 , V_119 , 1 , NULL ) )
F_134 ( V_128 ) ;
}
int F_135 ( struct V_26 * V_26 , struct V_163 * V_164 )
{
int V_74 ;
int V_95 = 0 ;
struct V_24 * V_165 = & F_124 ( V_26 ) -> V_166 ;
F_130 ( V_165 , V_164 -> V_15 , 0 ) ;
V_74 = F_90 ( V_165 , V_164 -> V_15 ,
V_164 -> V_15 + V_164 -> V_21 - 1 ,
V_123 | V_92 , V_124 ) ;
if ( V_74 )
V_95 = V_74 ;
V_74 = F_90 ( & F_124 ( V_26 ) -> V_151 , V_164 -> V_15 ,
V_164 -> V_15 + V_164 -> V_21 - 1 ,
V_167 , V_124 ) ;
if ( V_74 && ! V_95 )
V_95 = V_74 ;
F_136 ( V_164 ) ;
return V_95 ;
}
int F_137 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_168 , T_1 V_169 ,
struct V_128 * V_128 , unsigned int V_170 , int V_171 )
{
struct V_32 * V_172 = F_124 ( V_26 ) -> V_54 -> V_172 ;
struct V_41 * V_41 ;
struct V_173 * V_174 ;
T_1 V_175 = 0 ;
T_1 V_176 ;
struct V_177 * V_178 = NULL ;
struct V_179 * V_180 = & V_172 -> V_181 ;
int V_74 ;
ASSERT ( ! ( V_172 -> V_182 -> V_183 & V_184 ) ) ;
F_72 ( ! V_171 ) ;
if ( F_138 ( V_180 , V_169 , V_168 , V_171 ) )
return 0 ;
V_41 = F_139 ( V_124 , 1 ) ;
if ( ! V_41 )
return - V_185 ;
V_41 -> V_186 . V_187 = 0 ;
V_175 = V_168 ;
V_74 = F_140 ( V_172 , V_188 , V_169 ,
& V_175 , & V_178 , V_171 ) ;
if ( V_74 ) {
F_141 ( V_41 ) ;
return - V_185 ;
}
F_72 ( V_171 != V_178 -> V_171 ) ;
V_176 = V_178 -> V_189 [ V_171 - 1 ] . V_190 >> 9 ;
V_41 -> V_186 . V_191 = V_176 ;
V_174 = V_178 -> V_189 [ V_171 - 1 ] . V_174 ;
F_136 ( V_178 ) ;
if ( ! V_174 || ! V_174 -> V_192 || ! V_174 -> V_193 ) {
F_141 ( V_41 ) ;
return - V_185 ;
}
V_41 -> V_194 = V_174 -> V_192 ;
F_142 ( V_41 , V_128 , V_168 , V_170 ) ;
if ( F_143 ( V_195 , V_41 ) ) {
F_141 ( V_41 ) ;
F_144 ( V_174 , V_196 ) ;
return - V_185 ;
}
F_145 ( V_197
L_13 ,
F_19 ( V_26 ) , V_15 ,
F_146 ( V_174 -> V_198 ) , V_176 ) ;
F_141 ( V_41 ) ;
return 0 ;
}
int F_147 ( struct V_199 * V_54 , struct V_10 * V_11 ,
int V_171 )
{
T_1 V_15 = V_11 -> V_15 ;
unsigned long V_139 , V_200 = F_148 ( V_11 -> V_15 , V_11 -> V_21 ) ;
int V_74 = 0 ;
if ( V_54 -> V_172 -> V_182 -> V_183 & V_184 )
return - V_201 ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
struct V_128 * V_60 = V_11 -> V_137 [ V_139 ] ;
V_74 = F_137 ( V_54 -> V_172 -> V_202 , V_15 ,
V_148 , V_15 , V_60 ,
V_15 - F_133 ( V_60 ) , V_171 ) ;
if ( V_74 )
break;
V_15 += V_148 ;
}
return V_74 ;
}
int F_149 ( struct V_26 * V_26 , T_1 V_15 , struct V_128 * V_128 ,
unsigned int V_170 )
{
T_1 V_50 ;
T_1 V_203 ;
struct V_163 * V_204 ;
struct V_32 * V_172 = F_124 ( V_26 ) -> V_54 -> V_172 ;
struct V_1 * V_2 ;
int V_205 ;
int V_74 ;
V_50 = 0 ;
V_74 = F_127 ( & F_124 ( V_26 ) -> V_166 , & V_50 ,
( T_1 ) - 1 , 1 , V_92 , 0 ) ;
if ( ! V_74 )
return 0 ;
V_74 = F_131 ( & F_124 ( V_26 ) -> V_166 , V_15 ,
& V_203 ) ;
if ( V_74 )
return 0 ;
V_204 = (struct V_163 * ) ( unsigned long ) V_203 ;
F_72 ( ! V_204 -> V_206 ) ;
if ( V_204 -> V_207 ) {
F_150 ( L_14 ,
V_204 -> V_15 ) ;
goto V_107;
}
if ( V_172 -> V_182 -> V_183 & V_184 )
goto V_107;
F_70 ( & F_124 ( V_26 ) -> V_151 . V_48 ) ;
V_2 = F_111 ( & F_124 ( V_26 ) -> V_151 ,
V_204 -> V_15 ,
V_123 ) ;
F_74 ( & F_124 ( V_26 ) -> V_151 . V_48 ) ;
if ( V_2 && V_2 -> V_15 <= V_204 -> V_15 &&
V_2 -> V_16 >= V_204 -> V_15 + V_204 -> V_21 - 1 ) {
V_205 = F_151 ( V_172 , V_204 -> V_169 ,
V_204 -> V_21 ) ;
if ( V_205 > 1 ) {
F_137 ( V_26 , V_15 , V_204 -> V_21 ,
V_204 -> V_169 , V_128 ,
V_170 , V_204 -> V_208 ) ;
}
}
V_107:
F_135 ( V_26 , V_204 ) ;
return 0 ;
}
void F_152 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_16 )
{
struct V_24 * V_165 = & F_124 ( V_26 ) -> V_166 ;
struct V_163 * V_204 ;
struct V_1 * V_2 , * V_13 ;
if ( F_153 ( & V_165 -> V_2 ) )
return;
F_70 ( & V_165 -> V_48 ) ;
V_2 = F_111 ( V_165 , V_15 , V_92 ) ;
while ( V_2 ) {
if ( V_2 -> V_15 > V_16 )
break;
ASSERT ( V_2 -> V_16 <= V_16 ) ;
V_13 = F_62 ( V_2 ) ;
V_204 = (struct V_163 * ) V_2 -> V_50 ;
F_39 ( V_2 ) ;
F_136 ( V_204 ) ;
V_2 = V_13 ;
}
F_74 ( & V_165 -> V_48 ) ;
}
int F_154 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_16 ,
struct V_163 * * V_209 )
{
struct V_163 * V_204 ;
T_1 V_50 ;
struct V_210 * V_211 ;
struct V_24 * V_165 = & F_124 ( V_26 ) -> V_166 ;
struct V_24 * V_25 = & F_124 ( V_26 ) -> V_151 ;
struct V_212 * V_213 = & F_124 ( V_26 ) -> V_214 ;
int V_74 ;
T_1 V_169 ;
V_74 = F_131 ( V_165 , V_15 , & V_50 ) ;
if ( V_74 ) {
V_204 = F_155 ( sizeof( * V_204 ) , V_124 ) ;
if ( ! V_204 )
return - V_36 ;
V_204 -> V_15 = V_15 ;
V_204 -> V_21 = V_16 - V_15 + 1 ;
V_204 -> V_206 = 0 ;
V_204 -> V_215 = 0 ;
V_204 -> V_207 = 0 ;
F_156 ( & V_213 -> V_48 ) ;
V_211 = F_157 ( V_213 , V_15 , V_204 -> V_21 ) ;
if ( ! V_211 ) {
F_158 ( & V_213 -> V_48 ) ;
F_136 ( V_204 ) ;
return - V_185 ;
}
if ( V_211 -> V_15 > V_15 || V_211 -> V_15 + V_211 -> V_21 <= V_15 ) {
F_159 ( V_211 ) ;
V_211 = NULL ;
}
F_158 ( & V_213 -> V_48 ) ;
if ( ! V_211 ) {
F_136 ( V_204 ) ;
return - V_185 ;
}
V_169 = V_15 - V_211 -> V_15 ;
V_169 = V_211 -> V_216 + V_169 ;
if ( F_160 ( V_217 , & V_211 -> V_7 ) ) {
V_169 = V_211 -> V_216 ;
V_204 -> V_215 = V_218 ;
F_161 ( & V_204 -> V_215 ,
V_211 -> V_219 ) ;
}
F_150 ( L_15 ,
V_169 , V_15 , V_204 -> V_21 ) ;
V_204 -> V_169 = V_169 ;
F_159 ( V_211 ) ;
V_74 = F_89 ( V_165 , V_15 , V_16 ,
V_123 | V_92 , V_124 ) ;
if ( V_74 >= 0 )
V_74 = F_130 ( V_165 , V_15 ,
( T_1 ) ( unsigned long ) V_204 ) ;
if ( V_74 >= 0 )
V_74 = F_89 ( V_25 , V_15 , V_16 , V_167 ,
V_124 ) ;
if ( V_74 < 0 ) {
F_136 ( V_204 ) ;
return V_74 ;
}
} else {
V_204 = (struct V_163 * ) ( unsigned long ) V_50 ;
F_150 ( L_16 ,
V_204 -> V_169 , V_204 -> V_15 , V_204 -> V_21 ,
V_204 -> V_207 ) ;
}
* V_209 = V_204 ;
return 0 ;
}
int F_162 ( struct V_26 * V_26 , struct V_41 * V_220 ,
struct V_163 * V_204 , int V_208 )
{
int V_205 ;
V_205 = F_151 ( F_124 ( V_26 ) -> V_54 -> V_172 ,
V_204 -> V_169 , V_204 -> V_21 ) ;
if ( V_205 == 1 ) {
F_150 ( L_17 ,
V_205 , V_204 -> V_206 , V_208 ) ;
return 0 ;
}
if ( V_220 -> V_221 > 1 ) {
F_72 ( V_204 -> V_207 ) ;
V_204 -> V_207 = 1 ;
V_204 -> V_206 = V_208 ;
} else {
if ( V_204 -> V_207 ) {
F_72 ( V_204 -> V_206 != V_208 ) ;
V_204 -> V_207 = 0 ;
V_204 -> V_206 = 0 ;
}
V_204 -> V_208 = V_208 ;
V_204 -> V_206 ++ ;
if ( V_204 -> V_206 == V_208 )
V_204 -> V_206 ++ ;
}
if ( V_204 -> V_206 > V_205 ) {
F_150 ( L_18 ,
V_205 , V_204 -> V_206 , V_208 ) ;
return 0 ;
}
return 1 ;
}
struct V_41 * F_163 ( struct V_26 * V_26 , struct V_41 * V_220 ,
struct V_163 * V_204 ,
struct V_128 * V_128 , int V_170 , int V_222 ,
T_6 * V_223 , void * V_224 )
{
struct V_41 * V_41 ;
struct V_40 * V_225 ;
struct V_40 * V_177 ;
V_41 = F_139 ( V_124 , 1 ) ;
if ( ! V_41 )
return NULL ;
V_41 -> V_226 = V_223 ;
V_41 -> V_186 . V_191 = V_204 -> V_169 >> 9 ;
V_41 -> V_194 = F_124 ( V_26 ) -> V_54 -> V_172 -> V_227 -> V_228 ;
V_41 -> V_186 . V_187 = 0 ;
V_41 -> V_229 = V_224 ;
V_225 = V_40 ( V_220 ) ;
if ( V_225 -> V_230 ) {
struct V_32 * V_172 = F_124 ( V_26 ) -> V_54 -> V_172 ;
T_7 V_231 = F_164 ( V_172 -> V_232 ) ;
V_177 = V_40 ( V_41 ) ;
V_177 -> V_230 = V_177 -> V_233 ;
V_222 *= V_231 ;
memcpy ( V_177 -> V_230 , V_225 -> V_230 + V_222 ,
V_231 ) ;
}
F_142 ( V_41 , V_128 , V_204 -> V_21 , V_170 ) ;
return V_41 ;
}
static int F_165 ( struct V_41 * V_220 , T_1 V_234 ,
struct V_128 * V_128 , T_1 V_15 , T_1 V_16 ,
int V_208 )
{
struct V_163 * V_204 ;
struct V_26 * V_26 = V_128 -> V_28 -> V_29 ;
struct V_24 * V_25 = & F_124 ( V_26 ) -> V_151 ;
struct V_41 * V_41 ;
int V_235 ;
int V_74 ;
F_72 ( V_220 -> V_236 & V_237 ) ;
V_74 = F_154 ( V_26 , V_15 , V_16 , & V_204 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_162 ( V_26 , V_220 , V_204 , V_208 ) ;
if ( ! V_74 ) {
F_135 ( V_26 , V_204 ) ;
return - V_185 ;
}
if ( V_220 -> V_221 > 1 )
V_235 = V_238 | V_239 ;
else
V_235 = V_238 ;
V_234 >>= V_26 -> V_33 -> V_240 ;
V_41 = F_163 ( V_26 , V_220 , V_204 , V_128 ,
V_15 - F_133 ( V_128 ) ,
( int ) V_234 , V_220 -> V_226 ,
NULL ) ;
if ( ! V_41 ) {
F_135 ( V_26 , V_204 ) ;
return - V_185 ;
}
F_150 ( L_19 ,
V_235 , V_204 -> V_206 , V_204 -> V_207 ) ;
V_74 = V_25 -> V_46 -> V_241 ( V_26 , V_235 , V_41 ,
V_204 -> V_206 ,
V_204 -> V_215 , 0 ) ;
if ( V_74 ) {
F_135 ( V_26 , V_204 ) ;
F_141 ( V_41 ) ;
}
return V_74 ;
}
int F_166 ( struct V_128 * V_128 , int V_95 , T_1 V_15 , T_1 V_16 )
{
int V_242 = ( V_95 == 0 ) ;
struct V_24 * V_25 ;
int V_74 = 0 ;
V_25 = & F_124 ( V_128 -> V_28 -> V_29 ) -> V_151 ;
if ( V_25 -> V_46 && V_25 -> V_46 -> V_243 ) {
V_74 = V_25 -> V_46 -> V_243 ( V_128 , V_15 ,
V_16 , NULL , V_242 ) ;
if ( V_74 )
V_242 = 0 ;
}
if ( ! V_242 ) {
F_167 ( V_128 ) ;
F_168 ( V_128 ) ;
V_74 = V_74 < 0 ? V_74 : - V_185 ;
F_169 ( V_128 -> V_28 , V_74 ) ;
}
return 0 ;
}
static void F_170 ( struct V_41 * V_41 , int V_95 )
{
struct V_244 * V_245 ;
T_1 V_15 ;
T_1 V_16 ;
int V_139 ;
F_171 (bvec, bio, i) {
struct V_128 * V_128 = V_245 -> V_246 ;
if ( V_245 -> V_247 || V_245 -> V_248 != V_148 ) {
if ( V_245 -> V_247 + V_245 -> V_248 != V_148 )
F_172 ( F_124 ( V_128 -> V_28 -> V_29 ) -> V_54 -> V_172 ,
L_20 ,
V_245 -> V_247 , V_245 -> V_248 ) ;
else
F_173 ( F_124 ( V_128 -> V_28 -> V_29 ) -> V_54 -> V_172 ,
L_21
L_22 ,
V_245 -> V_247 , V_245 -> V_248 ) ;
}
V_15 = F_133 ( V_128 ) ;
V_16 = V_15 + V_245 -> V_247 + V_245 -> V_248 - 1 ;
if ( F_166 ( V_128 , V_95 , V_15 , V_16 ) )
continue;
F_126 ( V_128 ) ;
}
F_141 ( V_41 ) ;
}
static void
F_174 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_21 ,
int V_242 )
{
struct V_1 * V_98 = NULL ;
T_1 V_16 = V_15 + V_21 - 1 ;
if ( V_242 && V_25 -> V_249 )
F_95 ( V_25 , V_15 , V_16 , & V_98 , V_94 ) ;
F_100 ( V_25 , V_15 , V_16 , & V_98 , V_94 ) ;
}
static void F_175 ( struct V_41 * V_41 , int V_95 )
{
struct V_244 * V_245 ;
int V_242 = F_160 ( V_250 , & V_41 -> V_251 ) ;
struct V_40 * V_252 = V_40 ( V_41 ) ;
struct V_24 * V_25 ;
T_1 V_56 = 0 ;
T_1 V_15 ;
T_1 V_16 ;
T_1 V_21 ;
T_1 V_253 = 0 ;
T_1 V_254 = 0 ;
int V_255 ;
int V_74 ;
int V_139 ;
if ( V_95 )
V_242 = 0 ;
F_171 (bvec, bio, i) {
struct V_128 * V_128 = V_245 -> V_246 ;
struct V_26 * V_26 = V_128 -> V_28 -> V_29 ;
F_150 ( L_23
L_24 , ( T_1 ) V_41 -> V_186 . V_191 , V_95 ,
V_252 -> V_171 ) ;
V_25 = & F_124 ( V_26 ) -> V_151 ;
if ( V_245 -> V_247 || V_245 -> V_248 != V_148 ) {
if ( V_245 -> V_247 + V_245 -> V_248 != V_148 )
F_172 ( F_124 ( V_128 -> V_28 -> V_29 ) -> V_54 -> V_172 ,
L_25 ,
V_245 -> V_247 , V_245 -> V_248 ) ;
else
F_173 ( F_124 ( V_128 -> V_28 -> V_29 ) -> V_54 -> V_172 ,
L_26
L_22 ,
V_245 -> V_247 , V_245 -> V_248 ) ;
}
V_15 = F_133 ( V_128 ) ;
V_16 = V_15 + V_245 -> V_247 + V_245 -> V_248 - 1 ;
V_21 = V_245 -> V_248 ;
V_255 = V_252 -> V_171 ;
if ( F_176 ( V_242 && V_25 -> V_46 &&
V_25 -> V_46 -> V_256 ) ) {
V_74 = V_25 -> V_46 -> V_256 ( V_252 , V_56 ,
V_128 , V_15 , V_16 ,
V_255 ) ;
if ( V_74 )
V_242 = 0 ;
else
F_149 ( V_26 , V_15 , V_128 , 0 ) ;
}
if ( F_176 ( V_242 ) )
goto V_257;
if ( V_25 -> V_46 && V_25 -> V_46 -> V_258 ) {
V_74 = V_25 -> V_46 -> V_258 ( V_128 , V_255 ) ;
if ( ! V_74 && ! V_95 &&
F_160 ( V_250 , & V_41 -> V_251 ) )
V_242 = 1 ;
} else {
V_74 = F_165 ( V_41 , V_56 , V_128 , V_15 , V_16 ,
V_255 ) ;
if ( V_74 == 0 ) {
V_242 =
F_160 ( V_250 , & V_41 -> V_251 ) ;
if ( V_95 )
V_242 = 0 ;
V_56 += V_21 ;
continue;
}
}
V_257:
if ( F_176 ( V_242 ) ) {
T_8 V_259 = F_17 ( V_26 ) ;
T_9 V_127 = V_259 >> V_126 ;
unsigned V_260 ;
V_260 = V_259 & ( V_148 - 1 ) ;
if ( V_128 -> V_125 == V_127 && V_260 )
F_177 ( V_128 , V_260 , V_148 ) ;
F_134 ( V_128 ) ;
} else {
F_167 ( V_128 ) ;
F_168 ( V_128 ) ;
}
F_117 ( V_128 ) ;
V_56 += V_21 ;
if ( F_178 ( ! V_242 ) ) {
if ( V_254 ) {
F_174 ( V_25 ,
V_253 ,
V_254 , 1 ) ;
V_253 = 0 ;
V_254 = 0 ;
}
F_174 ( V_25 , V_15 ,
V_16 - V_15 + 1 , 0 ) ;
} else if ( ! V_254 ) {
V_253 = V_15 ;
V_254 = V_16 + 1 - V_15 ;
} else if ( V_253 + V_254 == V_15 ) {
V_254 += V_16 + 1 - V_15 ;
} else {
F_174 ( V_25 , V_253 ,
V_254 , V_242 ) ;
V_253 = V_15 ;
V_254 = V_16 + 1 - V_15 ;
}
}
if ( V_254 )
F_174 ( V_25 , V_253 , V_254 ,
V_242 ) ;
if ( V_252 -> V_261 )
V_252 -> V_261 ( V_252 , V_95 ) ;
F_141 ( V_41 ) ;
}
struct V_41 *
F_179 ( struct V_262 * V_192 , T_1 V_263 , int V_264 ,
T_3 V_265 )
{
struct V_40 * V_177 ;
struct V_41 * V_41 ;
V_41 = F_180 ( V_265 , V_264 , V_38 ) ;
if ( V_41 == NULL && ( V_266 -> V_7 & V_267 ) ) {
while ( ! V_41 && ( V_264 /= 2 ) ) {
V_41 = F_180 ( V_265 ,
V_264 , V_38 ) ;
}
}
if ( V_41 ) {
V_41 -> V_194 = V_192 ;
V_41 -> V_186 . V_191 = V_263 ;
V_177 = V_40 ( V_41 ) ;
V_177 -> V_230 = NULL ;
V_177 -> V_268 = NULL ;
V_177 -> V_261 = NULL ;
}
return V_41 ;
}
struct V_41 * F_181 ( struct V_41 * V_41 , T_3 V_269 )
{
struct V_40 * V_177 ;
struct V_41 * V_5 ;
V_5 = F_182 ( V_41 , V_269 , V_38 ) ;
if ( V_5 ) {
V_177 = V_40 ( V_5 ) ;
V_177 -> V_230 = NULL ;
V_177 -> V_268 = NULL ;
V_177 -> V_261 = NULL ;
}
return V_5 ;
}
struct V_41 * F_139 ( T_3 V_269 , unsigned int V_270 )
{
struct V_40 * V_177 ;
struct V_41 * V_41 ;
V_41 = F_180 ( V_269 , V_270 , V_38 ) ;
if ( V_41 ) {
V_177 = V_40 ( V_41 ) ;
V_177 -> V_230 = NULL ;
V_177 -> V_268 = NULL ;
V_177 -> V_261 = NULL ;
}
return V_41 ;
}
static int T_4 F_183 ( int V_271 , struct V_41 * V_41 ,
int V_171 , unsigned long V_215 )
{
int V_74 = 0 ;
struct V_244 * V_245 = V_41 -> V_272 + V_41 -> V_221 - 1 ;
struct V_128 * V_128 = V_245 -> V_246 ;
struct V_24 * V_25 = V_41 -> V_229 ;
T_1 V_15 ;
V_15 = F_133 ( V_128 ) + V_245 -> V_247 ;
V_41 -> V_229 = NULL ;
F_184 ( V_41 ) ;
if ( V_25 -> V_46 && V_25 -> V_46 -> V_241 )
V_74 = V_25 -> V_46 -> V_241 ( V_128 -> V_28 -> V_29 , V_271 , V_41 ,
V_171 , V_215 , V_15 ) ;
else
F_185 ( V_271 , V_41 ) ;
if ( F_186 ( V_41 , V_273 ) )
V_74 = - V_274 ;
F_141 ( V_41 ) ;
return V_74 ;
}
static int F_187 ( int V_271 , struct V_24 * V_25 , struct V_128 * V_128 ,
unsigned long V_56 , T_10 V_275 , struct V_41 * V_41 ,
unsigned long V_215 )
{
int V_74 = 0 ;
if ( V_25 -> V_46 && V_25 -> V_46 -> V_276 )
V_74 = V_25 -> V_46 -> V_276 ( V_271 , V_128 , V_56 , V_275 , V_41 ,
V_215 ) ;
F_72 ( V_74 < 0 ) ;
return V_74 ;
}
static int F_188 ( int V_271 , struct V_24 * V_25 ,
struct V_128 * V_128 , T_11 V_176 ,
T_10 V_275 , unsigned long V_56 ,
struct V_262 * V_192 ,
struct V_41 * * V_277 ,
unsigned long V_278 ,
T_6 V_279 ,
int V_171 ,
unsigned long V_280 ,
unsigned long V_215 )
{
int V_74 = 0 ;
struct V_41 * V_41 ;
int V_281 ;
int V_158 = 0 ;
int V_282 = V_215 & V_218 ;
int V_283 = V_280 & V_218 ;
T_10 V_284 = F_116 ( T_10 , V_275 , V_148 ) ;
if ( V_277 && * V_277 ) {
V_41 = * V_277 ;
if ( V_283 )
V_158 = V_41 -> V_186 . V_191 == V_176 ;
else
V_158 = F_189 ( V_41 ) == V_176 ;
if ( V_280 != V_215 || ! V_158 ||
F_187 ( V_271 , V_25 , V_128 , V_56 , V_284 , V_41 , V_215 ) ||
F_142 ( V_41 , V_128 , V_284 , V_56 ) < V_284 ) {
V_74 = F_183 ( V_271 , V_41 , V_171 ,
V_280 ) ;
if ( V_74 < 0 )
return V_74 ;
V_41 = NULL ;
} else {
return 0 ;
}
}
if ( V_282 )
V_281 = V_285 ;
else
V_281 = F_190 ( V_192 ) ;
V_41 = F_179 ( V_192 , V_176 , V_281 , V_124 | V_286 ) ;
if ( ! V_41 )
return - V_36 ;
F_142 ( V_41 , V_128 , V_284 , V_56 ) ;
V_41 -> V_226 = V_279 ;
V_41 -> V_229 = V_25 ;
if ( V_277 )
* V_277 = V_41 ;
else
V_74 = F_183 ( V_271 , V_41 , V_171 , V_215 ) ;
return V_74 ;
}
static void F_191 ( struct V_10 * V_11 ,
struct V_128 * V_128 )
{
if ( ! F_192 ( V_128 ) ) {
F_193 ( V_128 ) ;
F_194 ( V_128 ) ;
F_195 ( V_128 , ( unsigned long ) V_11 ) ;
} else {
F_41 ( V_128 -> V_50 != ( unsigned long ) V_11 ) ;
}
}
void F_196 ( struct V_128 * V_128 )
{
if ( ! F_192 ( V_128 ) ) {
F_193 ( V_128 ) ;
F_194 ( V_128 ) ;
F_195 ( V_128 , V_287 ) ;
}
}
static struct V_210 *
F_197 ( struct V_26 * V_26 , struct V_128 * V_128 , T_10 V_170 ,
T_1 V_15 , T_1 V_21 , T_12 * V_288 ,
struct V_210 * * V_289 )
{
struct V_210 * V_211 ;
if ( V_289 && * V_289 ) {
V_211 = * V_289 ;
if ( F_198 ( V_211 ) && V_15 >= V_211 -> V_15 &&
V_15 < F_199 ( V_211 ) ) {
F_82 ( & V_211 -> V_17 ) ;
return V_211 ;
}
F_159 ( V_211 ) ;
* V_289 = NULL ;
}
V_211 = V_288 ( V_26 , V_128 , V_170 , V_15 , V_21 , 0 ) ;
if ( V_289 && ! F_200 ( V_211 ) ) {
F_72 ( * V_289 ) ;
F_82 ( & V_211 -> V_17 ) ;
* V_289 = V_211 ;
}
return V_211 ;
}
static int F_201 ( struct V_24 * V_25 ,
struct V_128 * V_128 ,
T_12 * V_288 ,
struct V_210 * * V_289 ,
struct V_41 * * V_41 , int V_171 ,
unsigned long * V_215 , int V_271 )
{
struct V_26 * V_26 = V_128 -> V_28 -> V_29 ;
T_1 V_15 = F_133 ( V_128 ) ;
T_1 V_290 = V_15 + V_148 - 1 ;
T_1 V_16 ;
T_1 V_291 = V_15 ;
T_1 V_292 ;
T_1 V_293 = F_17 ( V_26 ) ;
T_1 V_216 ;
T_1 V_294 ;
T_11 V_176 ;
struct V_210 * V_211 ;
struct V_262 * V_192 ;
int V_74 ;
int V_281 = 0 ;
int V_295 = * V_215 & V_296 ;
T_10 V_170 = 0 ;
T_10 V_297 ;
T_10 V_298 ;
T_10 V_299 = V_26 -> V_33 -> V_300 ;
unsigned long V_301 = * V_215 & V_296 ;
F_196 ( V_128 ) ;
V_16 = V_290 ;
if ( ! F_202 ( V_128 ) ) {
if ( F_203 ( V_128 ) == 0 ) {
F_72 ( V_299 != V_30 ) ;
F_101 ( V_25 , V_15 , V_16 ) ;
goto V_107;
}
}
if ( V_128 -> V_125 == V_293 >> V_126 ) {
char * V_302 ;
T_10 V_303 = V_293 & ( V_148 - 1 ) ;
if ( V_303 ) {
V_297 = V_148 - V_303 ;
V_302 = F_204 ( V_128 ) ;
memset ( V_302 + V_303 , 0 , V_297 ) ;
F_205 ( V_128 ) ;
F_206 ( V_302 ) ;
}
}
while ( V_291 <= V_16 ) {
unsigned long V_304 = ( V_293 >> V_126 ) + 1 ;
if ( V_291 >= V_293 ) {
char * V_302 ;
struct V_1 * V_98 = NULL ;
V_297 = V_148 - V_170 ;
V_302 = F_204 ( V_128 ) ;
memset ( V_302 + V_170 , 0 , V_297 ) ;
F_205 ( V_128 ) ;
F_206 ( V_302 ) ;
F_95 ( V_25 , V_291 , V_291 + V_297 - 1 ,
& V_98 , V_124 ) ;
if ( ! V_295 )
F_100 ( V_25 , V_291 ,
V_291 + V_297 - 1 ,
& V_98 , V_124 ) ;
break;
}
V_211 = F_197 ( V_26 , V_128 , V_170 , V_291 ,
V_16 - V_291 + 1 , V_288 , V_289 ) ;
if ( F_200 ( V_211 ) ) {
F_168 ( V_128 ) ;
if ( ! V_295 )
F_101 ( V_25 , V_291 , V_16 ) ;
break;
}
V_292 = V_291 - V_211 -> V_15 ;
F_72 ( F_199 ( V_211 ) <= V_291 ) ;
F_72 ( V_16 < V_291 ) ;
if ( F_160 ( V_217 , & V_211 -> V_7 ) ) {
V_301 |= V_218 ;
F_161 ( & V_301 ,
V_211 -> V_219 ) ;
}
V_297 = F_128 ( F_199 ( V_211 ) - V_291 , V_16 - V_291 + 1 ) ;
V_294 = F_128 ( F_199 ( V_211 ) - 1 , V_16 ) ;
V_297 = F_207 ( V_297 , V_299 ) ;
if ( V_301 & V_218 ) {
V_298 = V_211 -> V_305 ;
V_176 = V_211 -> V_216 >> 9 ;
} else {
V_176 = ( V_211 -> V_216 + V_292 ) >> 9 ;
V_298 = V_297 ;
}
V_192 = V_211 -> V_192 ;
V_216 = V_211 -> V_216 ;
if ( F_160 ( V_306 , & V_211 -> V_7 ) )
V_216 = V_307 ;
F_159 ( V_211 ) ;
V_211 = NULL ;
if ( V_216 == V_307 ) {
char * V_302 ;
struct V_1 * V_98 = NULL ;
V_302 = F_204 ( V_128 ) ;
memset ( V_302 + V_170 , 0 , V_297 ) ;
F_205 ( V_128 ) ;
F_206 ( V_302 ) ;
F_95 ( V_25 , V_291 , V_291 + V_297 - 1 ,
& V_98 , V_124 ) ;
F_100 ( V_25 , V_291 , V_291 + V_297 - 1 ,
& V_98 , V_124 ) ;
V_291 = V_291 + V_297 ;
V_170 += V_297 ;
continue;
}
if ( F_122 ( V_25 , V_291 , V_294 ,
V_119 , 1 , NULL ) ) {
F_132 ( V_25 , V_128 ) ;
if ( ! V_295 )
F_101 ( V_25 , V_291 , V_291 + V_297 - 1 ) ;
V_291 = V_291 + V_297 ;
V_170 += V_297 ;
continue;
}
if ( V_216 == V_308 ) {
F_168 ( V_128 ) ;
if ( ! V_295 )
F_101 ( V_25 , V_291 , V_291 + V_297 - 1 ) ;
V_291 = V_291 + V_297 ;
V_170 += V_297 ;
continue;
}
V_304 -= V_128 -> V_125 ;
V_74 = F_188 ( V_271 , V_25 , V_128 ,
V_176 , V_298 , V_170 ,
V_192 , V_41 , V_304 ,
F_175 , V_171 ,
* V_215 ,
V_301 ) ;
if ( ! V_74 ) {
V_281 ++ ;
* V_215 = V_301 ;
} else {
F_168 ( V_128 ) ;
if ( ! V_295 )
F_101 ( V_25 , V_291 , V_291 + V_297 - 1 ) ;
}
V_291 = V_291 + V_297 ;
V_170 += V_297 ;
}
V_107:
if ( ! V_281 ) {
if ( ! F_208 ( V_128 ) )
F_134 ( V_128 ) ;
F_117 ( V_128 ) ;
}
return 0 ;
}
static inline void F_209 ( struct V_24 * V_25 ,
struct V_128 * V_137 [] , int V_138 ,
T_1 V_15 , T_1 V_16 ,
T_12 * V_288 ,
struct V_210 * * V_289 ,
struct V_41 * * V_41 , int V_171 ,
unsigned long * V_215 , int V_271 )
{
struct V_26 * V_26 ;
struct V_309 * V_310 ;
int V_125 ;
V_26 = V_137 [ 0 ] -> V_28 -> V_29 ;
while ( 1 ) {
F_98 ( V_25 , V_15 , V_16 ) ;
V_310 = F_210 ( V_26 , V_15 ,
V_16 - V_15 + 1 ) ;
if ( ! V_310 )
break;
F_101 ( V_25 , V_15 , V_16 ) ;
F_211 ( V_26 , V_310 , 1 ) ;
F_212 ( V_310 ) ;
}
for ( V_125 = 0 ; V_125 < V_138 ; V_125 ++ ) {
F_201 ( V_25 , V_137 [ V_125 ] , V_288 , V_289 , V_41 ,
V_171 , V_215 , V_271 ) ;
F_105 ( V_137 [ V_125 ] ) ;
}
}
static void F_213 ( struct V_24 * V_25 ,
struct V_128 * V_137 [] ,
int V_138 , T_12 * V_288 ,
struct V_210 * * V_289 ,
struct V_41 * * V_41 , int V_171 ,
unsigned long * V_215 , int V_271 )
{
T_1 V_15 = 0 ;
T_1 V_16 = 0 ;
T_1 V_311 ;
int V_125 ;
int V_312 = 0 ;
for ( V_125 = 0 ; V_125 < V_138 ; V_125 ++ ) {
V_311 = F_133 ( V_137 [ V_125 ] ) ;
if ( ! V_16 ) {
V_15 = V_311 ;
V_16 = V_15 + V_148 - 1 ;
V_312 = V_125 ;
} else if ( V_16 + 1 == V_311 ) {
V_16 += V_148 ;
} else {
F_209 ( V_25 , & V_137 [ V_312 ] ,
V_125 - V_312 , V_15 ,
V_16 , V_288 , V_289 ,
V_41 , V_171 , V_215 ,
V_271 ) ;
V_15 = V_311 ;
V_16 = V_15 + V_148 - 1 ;
V_312 = V_125 ;
}
}
if ( V_16 )
F_209 ( V_25 , & V_137 [ V_312 ] ,
V_125 - V_312 , V_15 ,
V_16 , V_288 , V_289 , V_41 ,
V_171 , V_215 , V_271 ) ;
}
static int F_214 ( struct V_24 * V_25 ,
struct V_128 * V_128 ,
T_12 * V_288 ,
struct V_41 * * V_41 , int V_171 ,
unsigned long * V_215 , int V_271 )
{
struct V_26 * V_26 = V_128 -> V_28 -> V_29 ;
struct V_309 * V_310 ;
T_1 V_15 = F_133 ( V_128 ) ;
T_1 V_16 = V_15 + V_148 - 1 ;
int V_74 ;
while ( 1 ) {
F_98 ( V_25 , V_15 , V_16 ) ;
V_310 = F_215 ( V_26 , V_15 ) ;
if ( ! V_310 )
break;
F_101 ( V_25 , V_15 , V_16 ) ;
F_211 ( V_26 , V_310 , 1 ) ;
F_212 ( V_310 ) ;
}
V_74 = F_201 ( V_25 , V_128 , V_288 , NULL , V_41 , V_171 ,
V_215 , V_271 ) ;
return V_74 ;
}
int F_216 ( struct V_24 * V_25 , struct V_128 * V_128 ,
T_12 * V_288 , int V_171 )
{
struct V_41 * V_41 = NULL ;
unsigned long V_215 = 0 ;
int V_74 ;
V_74 = F_214 ( V_25 , V_128 , V_288 , & V_41 , V_171 ,
& V_215 , V_313 ) ;
if ( V_41 )
V_74 = F_183 ( V_313 , V_41 , V_171 , V_215 ) ;
return V_74 ;
}
int F_217 ( struct V_24 * V_25 , struct V_128 * V_128 ,
T_12 * V_288 , int V_171 )
{
struct V_41 * V_41 = NULL ;
unsigned long V_215 = V_296 ;
int V_74 ;
V_74 = F_201 ( V_25 , V_128 , V_288 , NULL , & V_41 , V_171 ,
& V_215 , V_313 ) ;
if ( V_41 )
V_74 = F_183 ( V_313 , V_41 , V_171 , V_215 ) ;
return V_74 ;
}
static T_5 void F_218 ( struct V_128 * V_128 ,
struct V_314 * V_315 ,
unsigned long V_316 )
{
V_315 -> V_317 -= V_316 ;
if ( V_315 -> V_318 || ( V_315 -> V_317 > 0 &&
V_315 -> V_319 == 0 && V_315 -> V_320 == V_321 ) )
V_128 -> V_28 -> V_322 = V_128 -> V_125 + V_316 ;
}
static T_13 int F_219 ( struct V_26 * V_26 ,
struct V_128 * V_128 , struct V_314 * V_315 ,
struct V_323 * V_324 ,
T_1 V_140 ,
unsigned long * V_316 )
{
struct V_24 * V_25 = V_324 -> V_25 ;
T_1 V_290 = V_140 + V_148 - 1 ;
T_1 V_325 ;
T_1 V_326 = 0 ;
T_1 V_141 = 0 ;
int V_74 ;
int V_327 = 0 ;
if ( V_324 -> V_328 || ! V_25 -> V_46 || ! V_25 -> V_46 -> V_329 )
return 0 ;
while ( V_141 < V_290 ) {
V_325 = F_121 ( V_26 , V_25 ,
V_128 ,
& V_140 ,
& V_141 ,
128 * 1024 * 1024 ) ;
if ( V_325 == 0 ) {
V_140 = V_141 + 1 ;
continue;
}
V_74 = V_25 -> V_46 -> V_329 ( V_26 , V_128 ,
V_140 ,
V_141 ,
& V_327 ,
V_316 ) ;
if ( V_74 ) {
F_168 ( V_128 ) ;
V_74 = V_74 < 0 ? V_74 : - V_185 ;
goto V_146;
}
V_326 += ( V_141 - V_140 +
V_148 ) >>
V_126 ;
V_140 = V_141 + 1 ;
}
if ( V_315 -> V_317 < V_326 ) {
int V_330 = 8192 ;
if ( V_326 < V_330 * 2 )
V_330 = V_326 ;
V_315 -> V_317 = F_116 ( T_1 , V_326 ,
V_330 ) ;
}
if ( V_327 ) {
V_315 -> V_317 -= * V_316 ;
return 1 ;
}
V_74 = 0 ;
V_146:
return V_74 ;
}
static T_13 int F_220 ( struct V_26 * V_26 ,
struct V_128 * V_128 ,
struct V_314 * V_315 ,
struct V_323 * V_324 ,
T_8 V_259 ,
unsigned long V_316 ,
int V_331 , int * V_332 )
{
struct V_24 * V_25 = V_324 -> V_25 ;
T_1 V_15 = F_133 ( V_128 ) ;
T_1 V_290 = V_15 + V_148 - 1 ;
T_1 V_16 ;
T_1 V_291 = V_15 ;
T_1 V_292 ;
T_1 V_216 ;
T_1 V_297 ;
T_11 V_176 ;
struct V_1 * V_97 = NULL ;
struct V_210 * V_211 ;
struct V_262 * V_192 ;
T_10 V_170 = 0 ;
T_10 V_299 ;
int V_74 = 0 ;
int V_281 = 0 ;
bool V_333 ;
if ( V_25 -> V_46 && V_25 -> V_46 -> V_334 ) {
V_74 = V_25 -> V_46 -> V_334 ( V_128 , V_15 ,
V_290 ) ;
if ( V_74 ) {
if ( V_74 == - V_335 )
V_315 -> V_336 ++ ;
else
F_221 ( V_315 , V_128 ) ;
F_218 ( V_128 , V_315 , V_316 ) ;
F_117 ( V_128 ) ;
V_74 = 1 ;
goto V_337;
}
}
F_218 ( V_128 , V_315 , V_316 + 1 ) ;
V_16 = V_290 ;
if ( V_259 <= V_15 ) {
if ( V_25 -> V_46 && V_25 -> V_46 -> V_243 )
V_25 -> V_46 -> V_243 ( V_128 , V_15 ,
V_290 , NULL , 1 ) ;
goto V_146;
}
V_299 = V_26 -> V_33 -> V_300 ;
while ( V_291 <= V_16 ) {
T_1 V_338 ;
if ( V_291 >= V_259 ) {
if ( V_25 -> V_46 && V_25 -> V_46 -> V_243 )
V_25 -> V_46 -> V_243 ( V_128 , V_291 ,
V_290 , NULL , 1 ) ;
break;
}
V_211 = V_324 -> V_288 ( V_26 , V_128 , V_170 , V_291 ,
V_16 - V_291 + 1 , 1 ) ;
if ( F_200 ( V_211 ) ) {
F_168 ( V_128 ) ;
V_74 = F_222 ( V_211 ) ;
break;
}
V_292 = V_291 - V_211 -> V_15 ;
V_338 = F_199 ( V_211 ) ;
F_72 ( V_338 <= V_291 ) ;
F_72 ( V_16 < V_291 ) ;
V_297 = F_128 ( V_338 - V_291 , V_16 - V_291 + 1 ) ;
V_297 = F_207 ( V_297 , V_299 ) ;
V_176 = ( V_211 -> V_216 + V_292 ) >> 9 ;
V_192 = V_211 -> V_192 ;
V_216 = V_211 -> V_216 ;
V_333 = F_160 ( V_217 , & V_211 -> V_7 ) ;
F_159 ( V_211 ) ;
V_211 = NULL ;
if ( V_333 || V_216 == V_307 ||
V_216 == V_308 ) {
if ( ! V_333 && V_25 -> V_46 &&
V_25 -> V_46 -> V_243 )
V_25 -> V_46 -> V_243 ( V_128 , V_291 ,
V_291 + V_297 - 1 ,
NULL , 1 ) ;
else if ( V_333 ) {
V_281 ++ ;
}
V_291 += V_297 ;
V_170 += V_297 ;
continue;
}
if ( V_25 -> V_46 && V_25 -> V_46 -> V_339 ) {
V_74 = V_25 -> V_46 -> V_339 ( V_128 , V_291 ,
V_291 + V_297 - 1 ) ;
} else {
V_74 = 0 ;
}
if ( V_74 ) {
F_168 ( V_128 ) ;
} else {
unsigned long V_340 = ( V_259 >> V_126 ) + 1 ;
F_109 ( V_25 , V_291 , V_291 + V_297 - 1 ) ;
if ( ! F_223 ( V_128 ) ) {
F_172 ( F_124 ( V_26 ) -> V_54 -> V_172 ,
L_27 ,
V_128 -> V_125 , V_291 , V_16 ) ;
}
V_74 = F_188 ( V_331 , V_25 , V_128 ,
V_176 , V_297 , V_170 ,
V_192 , & V_324 -> V_41 , V_340 ,
F_170 ,
0 , 0 , 0 ) ;
if ( V_74 )
F_168 ( V_128 ) ;
}
V_291 = V_291 + V_297 ;
V_170 += V_297 ;
V_281 ++ ;
}
V_146:
* V_332 = V_281 ;
V_337:
F_39 ( V_97 ) ;
return V_74 ;
}
static int F_224 ( struct V_128 * V_128 , struct V_314 * V_315 ,
void * V_224 )
{
struct V_26 * V_26 = V_128 -> V_28 -> V_29 ;
struct V_323 * V_324 = V_224 ;
T_1 V_15 = F_133 ( V_128 ) ;
T_1 V_290 = V_15 + V_148 - 1 ;
int V_74 ;
int V_281 = 0 ;
T_10 V_170 = 0 ;
T_8 V_259 = F_17 ( V_26 ) ;
unsigned long V_127 = V_259 >> V_126 ;
int V_331 ;
unsigned long V_316 = 0 ;
if ( V_315 -> V_341 == V_342 )
V_331 = V_195 ;
else
V_331 = V_188 ;
F_225 ( V_128 , V_26 , V_315 ) ;
F_41 ( ! F_226 ( V_128 ) ) ;
F_227 ( V_128 ) ;
V_170 = V_259 & ( V_148 - 1 ) ;
if ( V_128 -> V_125 > V_127 ||
( V_128 -> V_125 == V_127 && ! V_170 ) ) {
V_128 -> V_28 -> V_343 -> V_344 ( V_128 , 0 , V_148 ) ;
F_117 ( V_128 ) ;
return 0 ;
}
if ( V_128 -> V_125 == V_127 ) {
char * V_302 ;
V_302 = F_204 ( V_128 ) ;
memset ( V_302 + V_170 , 0 ,
V_148 - V_170 ) ;
F_206 ( V_302 ) ;
F_205 ( V_128 ) ;
}
V_170 = 0 ;
F_196 ( V_128 ) ;
V_74 = F_219 ( V_26 , V_128 , V_315 , V_324 , V_15 , & V_316 ) ;
if ( V_74 == 1 )
goto V_337;
if ( V_74 )
goto V_146;
V_74 = F_220 ( V_26 , V_128 , V_315 , V_324 ,
V_259 , V_316 , V_331 , & V_281 ) ;
if ( V_74 == 1 )
goto V_337;
V_146:
if ( V_281 == 0 ) {
F_110 ( V_128 ) ;
F_126 ( V_128 ) ;
}
if ( F_208 ( V_128 ) ) {
V_74 = V_74 < 0 ? V_74 : - V_185 ;
F_166 ( V_128 , V_74 , V_15 , V_290 ) ;
}
F_117 ( V_128 ) ;
return V_74 ;
V_337:
return 0 ;
}
void F_228 ( struct V_10 * V_11 )
{
F_229 ( & V_11 -> V_345 , V_346 ,
V_110 ) ;
}
static T_13 int
F_230 ( struct V_10 * V_11 ,
struct V_32 * V_172 ,
struct V_323 * V_324 )
{
unsigned long V_139 , V_200 ;
int V_347 = 0 ;
int V_74 = 0 ;
if ( ! F_231 ( V_11 ) ) {
V_347 = 1 ;
F_232 ( V_324 ) ;
F_233 ( V_11 ) ;
}
if ( F_160 ( V_346 , & V_11 -> V_345 ) ) {
F_234 ( V_11 ) ;
if ( ! V_324 -> V_348 )
return 0 ;
if ( ! V_347 ) {
F_232 ( V_324 ) ;
V_347 = 1 ;
}
while ( 1 ) {
F_228 ( V_11 ) ;
F_233 ( V_11 ) ;
if ( ! F_160 ( V_346 , & V_11 -> V_345 ) )
break;
F_234 ( V_11 ) ;
}
}
F_70 ( & V_11 -> V_349 ) ;
if ( F_235 ( V_350 , & V_11 -> V_345 ) ) {
F_236 ( V_346 , & V_11 -> V_345 ) ;
F_74 ( & V_11 -> V_349 ) ;
F_237 ( V_11 , V_351 ) ;
F_238 ( & V_172 -> V_352 ,
- V_11 -> V_21 ,
V_172 -> V_353 ) ;
V_74 = 1 ;
} else {
F_74 ( & V_11 -> V_349 ) ;
}
F_234 ( V_11 ) ;
if ( ! V_74 )
return V_74 ;
V_200 = F_148 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
struct V_128 * V_60 = V_11 -> V_137 [ V_139 ] ;
if ( ! F_239 ( V_60 ) ) {
if ( ! V_347 ) {
F_232 ( V_324 ) ;
V_347 = 1 ;
}
F_119 ( V_60 ) ;
}
}
return V_74 ;
}
static void F_240 ( struct V_10 * V_11 )
{
F_241 ( V_346 , & V_11 -> V_345 ) ;
F_242 () ;
F_243 ( & V_11 -> V_345 , V_346 ) ;
}
static void F_244 ( struct V_128 * V_128 )
{
struct V_10 * V_11 = (struct V_10 * ) V_128 -> V_50 ;
struct V_354 * V_355 = F_124 ( V_11 -> V_172 -> V_202 ) ;
F_168 ( V_128 ) ;
if ( F_245 ( V_356 , & V_11 -> V_345 ) )
return;
switch ( V_11 -> V_357 ) {
case - 1 :
F_236 ( V_358 , & V_355 -> V_359 ) ;
break;
case 0 :
F_236 ( V_360 , & V_355 -> V_359 ) ;
break;
case 1 :
F_236 ( V_361 , & V_355 -> V_359 ) ;
break;
default:
F_246 () ;
}
}
static void F_247 ( struct V_41 * V_41 , int V_95 )
{
struct V_244 * V_245 ;
struct V_10 * V_11 ;
int V_139 , V_146 ;
F_171 (bvec, bio, i) {
struct V_128 * V_128 = V_245 -> V_246 ;
V_11 = (struct V_10 * ) V_128 -> V_50 ;
F_72 ( ! V_11 ) ;
V_146 = F_40 ( & V_11 -> V_362 ) ;
if ( V_95 || F_160 ( V_356 , & V_11 -> V_345 ) ) {
F_167 ( V_128 ) ;
F_244 ( V_128 ) ;
}
F_126 ( V_128 ) ;
if ( ! V_146 )
continue;
F_240 ( V_11 ) ;
}
F_141 ( V_41 ) ;
}
static T_13 int F_248 ( struct V_10 * V_11 ,
struct V_32 * V_172 ,
struct V_314 * V_315 ,
struct V_323 * V_324 )
{
struct V_262 * V_192 = V_172 -> V_227 -> V_228 ;
struct V_24 * V_25 = & F_124 ( V_172 -> V_202 ) -> V_151 ;
T_1 V_56 = V_11 -> V_15 ;
unsigned long V_139 , V_200 ;
unsigned long V_215 = 0 ;
int V_271 = ( V_324 -> V_348 ? V_195 : V_188 ) | V_363 ;
int V_74 = 0 ;
F_241 ( V_356 , & V_11 -> V_345 ) ;
V_200 = F_148 ( V_11 -> V_15 , V_11 -> V_21 ) ;
F_36 ( & V_11 -> V_362 , V_200 ) ;
if ( F_249 ( V_11 ) == V_364 )
V_215 = V_365 ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
struct V_128 * V_60 = V_11 -> V_137 [ V_139 ] ;
F_104 ( V_60 ) ;
F_110 ( V_60 ) ;
V_74 = F_188 ( V_271 , V_25 , V_60 , V_56 >> 9 ,
V_148 , 0 , V_192 , & V_324 -> V_41 ,
- 1 , F_247 ,
0 , V_324 -> V_215 , V_215 ) ;
V_324 -> V_215 = V_215 ;
if ( V_74 ) {
F_244 ( V_60 ) ;
F_126 ( V_60 ) ;
if ( F_250 ( V_200 - V_139 , & V_11 -> V_362 ) )
F_240 ( V_11 ) ;
V_74 = - V_185 ;
break;
}
V_56 += V_148 ;
F_218 ( V_60 , V_315 , 1 ) ;
F_117 ( V_60 ) ;
}
if ( F_178 ( V_74 ) ) {
for (; V_139 < V_200 ; V_139 ++ ) {
struct V_128 * V_60 = V_11 -> V_137 [ V_139 ] ;
F_104 ( V_60 ) ;
F_117 ( V_60 ) ;
}
}
return V_74 ;
}
int F_251 ( struct V_44 * V_28 ,
struct V_314 * V_315 )
{
struct V_24 * V_25 = & F_124 ( V_28 -> V_29 ) -> V_151 ;
struct V_32 * V_172 = F_124 ( V_28 -> V_29 ) -> V_54 -> V_172 ;
struct V_10 * V_11 , * V_366 = NULL ;
struct V_323 V_324 = {
. V_41 = NULL ,
. V_25 = V_25 ,
. V_328 = 0 ,
. V_348 = V_315 -> V_341 == V_342 ,
. V_215 = 0 ,
} ;
int V_74 = 0 ;
int V_146 = 0 ;
int V_367 = 0 ;
struct V_368 V_369 ;
int V_138 ;
T_9 V_125 ;
T_9 V_16 ;
int V_370 = 0 ;
int V_371 ;
F_252 ( & V_369 , 0 ) ;
if ( V_315 -> V_318 ) {
V_125 = V_28 -> V_322 ;
V_16 = - 1 ;
} else {
V_125 = V_315 -> V_319 >> V_126 ;
V_16 = V_315 -> V_320 >> V_126 ;
V_370 = 1 ;
}
if ( V_315 -> V_341 == V_342 )
V_371 = V_372 ;
else
V_371 = V_373 ;
V_374:
if ( V_315 -> V_341 == V_342 )
F_253 ( V_28 , V_125 , V_16 ) ;
while ( ! V_146 && ! V_367 && ( V_125 <= V_16 ) &&
( V_138 = F_254 ( & V_369 , V_28 , & V_125 , V_371 ,
F_128 ( V_16 - V_125 , ( T_9 ) V_375 - 1 ) + 1 ) ) ) {
unsigned V_139 ;
V_370 = 1 ;
for ( V_139 = 0 ; V_139 < V_138 ; V_139 ++ ) {
struct V_128 * V_128 = V_369 . V_137 [ V_139 ] ;
if ( ! F_192 ( V_128 ) )
continue;
if ( ! V_315 -> V_318 && V_128 -> V_125 > V_16 ) {
V_146 = 1 ;
break;
}
F_70 ( & V_28 -> V_376 ) ;
if ( ! F_192 ( V_128 ) ) {
F_74 ( & V_28 -> V_376 ) ;
continue;
}
V_11 = (struct V_10 * ) V_128 -> V_50 ;
if ( F_41 ( ! V_11 ) ) {
F_74 ( & V_28 -> V_376 ) ;
continue;
}
if ( V_11 == V_366 ) {
F_74 ( & V_28 -> V_376 ) ;
continue;
}
V_74 = F_255 ( & V_11 -> V_17 ) ;
F_74 ( & V_28 -> V_376 ) ;
if ( ! V_74 )
continue;
V_366 = V_11 ;
V_74 = F_230 ( V_11 , V_172 , & V_324 ) ;
if ( ! V_74 ) {
F_256 ( V_11 ) ;
continue;
}
V_74 = F_248 ( V_11 , V_172 , V_315 , & V_324 ) ;
if ( V_74 ) {
V_146 = 1 ;
F_256 ( V_11 ) ;
break;
}
F_256 ( V_11 ) ;
V_367 = V_315 -> V_317 <= 0 ;
}
F_257 ( & V_369 ) ;
F_75 () ;
}
if ( ! V_370 && ! V_146 ) {
V_370 = 1 ;
V_125 = 0 ;
goto V_374;
}
F_232 ( & V_324 ) ;
return V_74 ;
}
static int F_258 ( struct V_24 * V_25 ,
struct V_44 * V_28 ,
struct V_314 * V_315 ,
T_14 V_377 , void * V_224 ,
void (* F_259)( void * ) )
{
struct V_26 * V_26 = V_28 -> V_29 ;
int V_74 = 0 ;
int V_146 = 0 ;
int V_95 = 0 ;
int V_367 = 0 ;
struct V_368 V_369 ;
int V_138 ;
T_9 V_125 ;
T_9 V_16 ;
int V_370 = 0 ;
int V_371 ;
if ( ! F_260 ( V_26 ) )
return 0 ;
F_252 ( & V_369 , 0 ) ;
if ( V_315 -> V_318 ) {
V_125 = V_28 -> V_322 ;
V_16 = - 1 ;
} else {
V_125 = V_315 -> V_319 >> V_126 ;
V_16 = V_315 -> V_320 >> V_126 ;
V_370 = 1 ;
}
if ( V_315 -> V_341 == V_342 )
V_371 = V_372 ;
else
V_371 = V_373 ;
V_374:
if ( V_315 -> V_341 == V_342 )
F_253 ( V_28 , V_125 , V_16 ) ;
while ( ! V_146 && ! V_367 && ( V_125 <= V_16 ) &&
( V_138 = F_254 ( & V_369 , V_28 , & V_125 , V_371 ,
F_128 ( V_16 - V_125 , ( T_9 ) V_375 - 1 ) + 1 ) ) ) {
unsigned V_139 ;
V_370 = 1 ;
for ( V_139 = 0 ; V_139 < V_138 ; V_139 ++ ) {
struct V_128 * V_128 = V_369 . V_137 [ V_139 ] ;
if ( ! F_239 ( V_128 ) ) {
F_259 ( V_224 ) ;
F_119 ( V_128 ) ;
}
if ( F_178 ( V_128 -> V_28 != V_28 ) ) {
F_117 ( V_128 ) ;
continue;
}
if ( ! V_315 -> V_318 && V_128 -> V_125 > V_16 ) {
V_146 = 1 ;
F_117 ( V_128 ) ;
continue;
}
if ( V_315 -> V_341 != V_378 ) {
if ( F_223 ( V_128 ) )
F_259 ( V_224 ) ;
F_261 ( V_128 ) ;
}
if ( F_223 ( V_128 ) ||
! F_104 ( V_128 ) ) {
F_117 ( V_128 ) ;
continue;
}
V_74 = (* V_377)( V_128 , V_315 , V_224 ) ;
if ( F_178 ( V_74 == V_379 ) ) {
F_117 ( V_128 ) ;
V_74 = 0 ;
}
if ( ! V_95 && V_74 < 0 )
V_95 = V_74 ;
V_367 = V_315 -> V_317 <= 0 ;
}
F_257 ( & V_369 ) ;
F_75 () ;
}
if ( ! V_370 && ! V_146 && ! V_95 ) {
V_370 = 1 ;
V_125 = 0 ;
goto V_374;
}
F_262 ( V_26 ) ;
return V_95 ;
}
static void F_263 ( struct V_323 * V_324 )
{
if ( V_324 -> V_41 ) {
int V_271 = V_188 ;
int V_74 ;
if ( V_324 -> V_348 )
V_271 = V_195 ;
V_74 = F_183 ( V_271 , V_324 -> V_41 , 0 , V_324 -> V_215 ) ;
F_72 ( V_74 < 0 ) ;
V_324 -> V_41 = NULL ;
}
}
static T_5 void F_232 ( void * V_224 )
{
struct V_323 * V_324 = V_224 ;
F_263 ( V_324 ) ;
}
int F_264 ( struct V_24 * V_25 , struct V_128 * V_128 ,
T_12 * V_288 ,
struct V_314 * V_315 )
{
int V_74 ;
struct V_323 V_324 = {
. V_41 = NULL ,
. V_25 = V_25 ,
. V_288 = V_288 ,
. V_328 = 0 ,
. V_348 = V_315 -> V_341 == V_342 ,
. V_215 = 0 ,
} ;
V_74 = F_224 ( V_128 , V_315 , & V_324 ) ;
F_263 ( & V_324 ) ;
return V_74 ;
}
int F_265 ( struct V_24 * V_25 , struct V_26 * V_26 ,
T_1 V_15 , T_1 V_16 , T_12 * V_288 ,
int V_380 )
{
int V_74 = 0 ;
struct V_44 * V_28 = V_26 -> V_129 ;
struct V_128 * V_128 ;
unsigned long V_138 = ( V_16 - V_15 + V_148 ) >>
V_126 ;
struct V_323 V_324 = {
. V_41 = NULL ,
. V_25 = V_25 ,
. V_288 = V_288 ,
. V_328 = 1 ,
. V_348 = V_380 == V_342 ,
. V_215 = 0 ,
} ;
struct V_314 V_381 = {
. V_341 = V_380 ,
. V_317 = V_138 * 2 ,
. V_319 = V_15 ,
. V_320 = V_16 + 1 ,
} ;
while ( V_15 <= V_16 ) {
V_128 = F_103 ( V_28 , V_15 >> V_126 ) ;
if ( F_104 ( V_128 ) )
V_74 = F_224 ( V_128 , & V_381 , & V_324 ) ;
else {
if ( V_25 -> V_46 && V_25 -> V_46 -> V_243 )
V_25 -> V_46 -> V_243 ( V_128 , V_15 ,
V_15 + V_148 - 1 ,
NULL , 1 ) ;
F_117 ( V_128 ) ;
}
F_105 ( V_128 ) ;
V_15 += V_148 ;
}
F_263 ( & V_324 ) ;
return V_74 ;
}
int F_266 ( struct V_24 * V_25 ,
struct V_44 * V_28 ,
T_12 * V_288 ,
struct V_314 * V_315 )
{
int V_74 = 0 ;
struct V_323 V_324 = {
. V_41 = NULL ,
. V_25 = V_25 ,
. V_288 = V_288 ,
. V_328 = 0 ,
. V_348 = V_315 -> V_341 == V_342 ,
. V_215 = 0 ,
} ;
V_74 = F_258 ( V_25 , V_28 , V_315 ,
F_224 , & V_324 ,
F_232 ) ;
F_263 ( & V_324 ) ;
return V_74 ;
}
int F_267 ( struct V_24 * V_25 ,
struct V_44 * V_28 ,
struct V_4 * V_137 , unsigned V_138 ,
T_12 V_288 )
{
struct V_41 * V_41 = NULL ;
unsigned V_382 ;
unsigned long V_215 = 0 ;
struct V_128 * V_383 [ 16 ] ;
struct V_128 * V_128 ;
struct V_210 * V_289 = NULL ;
int V_281 = 0 ;
for ( V_382 = 0 ; V_382 < V_138 ; V_382 ++ ) {
V_128 = F_11 ( V_137 -> V_71 , struct V_128 , V_384 ) ;
F_268 ( & V_128 -> V_7 ) ;
F_8 ( & V_128 -> V_384 ) ;
if ( F_269 ( V_128 , V_28 ,
V_128 -> V_125 , V_124 ) ) {
F_105 ( V_128 ) ;
continue;
}
V_383 [ V_281 ++ ] = V_128 ;
if ( V_281 < F_270 ( V_383 ) )
continue;
F_213 ( V_25 , V_383 , V_281 , V_288 , & V_289 ,
& V_41 , 0 , & V_215 , V_313 ) ;
V_281 = 0 ;
}
if ( V_281 )
F_213 ( V_25 , V_383 , V_281 , V_288 , & V_289 ,
& V_41 , 0 , & V_215 , V_313 ) ;
if ( V_289 )
F_159 ( V_289 ) ;
F_72 ( ! F_10 ( V_137 ) ) ;
if ( V_41 )
return F_183 ( V_313 , V_41 , 0 , V_215 ) ;
return 0 ;
}
int F_271 ( struct V_24 * V_25 ,
struct V_128 * V_128 , unsigned long V_56 )
{
struct V_1 * V_97 = NULL ;
T_1 V_15 = F_133 ( V_128 ) ;
T_1 V_16 = V_15 + V_148 - 1 ;
T_10 V_299 = V_128 -> V_28 -> V_29 -> V_33 -> V_300 ;
V_15 += F_207 ( V_56 , V_299 ) ;
if ( V_15 > V_16 )
return 0 ;
F_97 ( V_25 , V_15 , V_16 , 0 , & V_97 ) ;
F_261 ( V_128 ) ;
F_68 ( V_25 , V_15 , V_16 ,
V_123 | V_92 | V_101 |
V_121 ,
1 , 1 , & V_97 , V_124 ) ;
return 0 ;
}
static int F_272 ( struct V_212 * V_385 ,
struct V_24 * V_25 ,
struct V_128 * V_128 , T_3 V_49 )
{
T_1 V_15 = F_133 ( V_128 ) ;
T_1 V_16 = V_15 + V_148 - 1 ;
int V_74 = 1 ;
if ( F_122 ( V_25 , V_15 , V_16 ,
V_78 , 0 , NULL ) )
V_74 = 0 ;
else {
if ( ( V_49 & V_124 ) == V_124 )
V_49 = V_124 ;
V_74 = F_68 ( V_25 , V_15 , V_16 ,
~ ( V_123 | V_386 ) ,
0 , 0 , NULL , V_49 ) ;
if ( V_74 < 0 )
V_74 = 0 ;
else
V_74 = 1 ;
}
return V_74 ;
}
int F_273 ( struct V_212 * V_385 ,
struct V_24 * V_25 , struct V_128 * V_128 ,
T_3 V_49 )
{
struct V_210 * V_211 ;
T_1 V_15 = F_133 ( V_128 ) ;
T_1 V_16 = V_15 + V_148 - 1 ;
if ( ( V_49 & V_105 ) &&
V_128 -> V_28 -> V_29 -> V_259 > 16 * 1024 * 1024 ) {
T_1 V_21 ;
while ( V_15 <= V_16 ) {
V_21 = V_16 - V_15 + 1 ;
F_274 ( & V_385 -> V_48 ) ;
V_211 = F_157 ( V_385 , V_15 , V_21 ) ;
if ( ! V_211 ) {
F_275 ( & V_385 -> V_48 ) ;
break;
}
if ( F_160 ( V_387 , & V_211 -> V_7 ) ||
V_211 -> V_15 != V_15 ) {
F_275 ( & V_385 -> V_48 ) ;
F_159 ( V_211 ) ;
break;
}
if ( ! F_122 ( V_25 , V_211 -> V_15 ,
F_199 ( V_211 ) - 1 ,
V_123 | V_388 ,
0 , NULL ) ) {
F_276 ( V_385 , V_211 ) ;
F_159 ( V_211 ) ;
}
V_15 = F_199 ( V_211 ) ;
F_275 ( & V_385 -> V_48 ) ;
F_159 ( V_211 ) ;
}
}
return F_272 ( V_385 , V_25 , V_128 , V_49 ) ;
}
static struct V_210 * F_277 ( struct V_26 * V_26 ,
T_1 V_56 ,
T_1 V_159 ,
T_12 * V_288 )
{
T_1 V_389 = F_124 ( V_26 ) -> V_54 -> V_389 ;
struct V_210 * V_211 ;
T_1 V_21 ;
if ( V_56 >= V_159 )
return NULL ;
while ( 1 ) {
V_21 = V_159 - V_56 ;
if ( V_21 == 0 )
break;
V_21 = F_207 ( V_21 , V_389 ) ;
V_211 = V_288 ( V_26 , NULL , 0 , V_56 , V_21 , 0 ) ;
if ( F_200 ( V_211 ) )
return V_211 ;
if ( ! F_160 ( V_390 , & V_211 -> V_7 ) &&
V_211 -> V_216 != V_307 ) {
return V_211 ;
}
V_56 = F_199 ( V_211 ) ;
F_159 ( V_211 ) ;
if ( V_56 >= V_159 )
break;
}
return NULL ;
}
int F_278 ( struct V_26 * V_26 , struct V_391 * V_392 ,
T_15 V_15 , T_15 V_21 , T_12 * V_288 )
{
int V_74 = 0 ;
T_1 V_260 = V_15 ;
T_1 F_129 = V_15 + V_21 ;
T_16 V_7 = 0 ;
T_16 V_393 ;
T_1 V_159 ;
T_1 V_394 = 0 ;
T_1 V_395 = 0 ;
T_1 V_27 = F_17 ( V_26 ) ;
struct V_396 V_397 ;
struct V_210 * V_211 = NULL ;
struct V_1 * V_97 = NULL ;
struct V_398 * V_399 ;
struct V_199 * V_54 = F_124 ( V_26 ) -> V_54 ;
int V_16 = 0 ;
T_1 V_400 = 0 ;
T_1 V_401 = 0 ;
T_1 V_338 = 0 ;
if ( V_21 == 0 )
return - V_402 ;
V_399 = F_279 () ;
if ( ! V_399 )
return - V_36 ;
V_399 -> V_403 = 1 ;
V_15 = F_280 ( V_15 , F_124 ( V_26 ) -> V_54 -> V_389 ) ;
V_21 = F_281 ( F_129 , F_124 ( V_26 ) -> V_54 -> V_389 ) - V_15 ;
V_74 = F_282 ( NULL , V_54 , V_399 , F_19 ( V_26 ) , - 1 ,
0 ) ;
if ( V_74 < 0 ) {
F_283 ( V_399 ) ;
return V_74 ;
}
F_41 ( ! V_74 ) ;
V_399 -> V_404 [ 0 ] -- ;
F_284 ( V_399 -> V_405 [ 0 ] , & V_397 , V_399 -> V_404 [ 0 ] ) ;
V_393 = V_397 . type ;
if ( V_397 . V_406 != F_19 ( V_26 ) ||
V_393 != V_407 ) {
V_159 = ( T_1 ) - 1 ;
V_394 = V_27 ;
} else {
V_159 = V_397 . V_56 ;
V_394 = V_159 + 1 ;
}
F_285 ( V_399 ) ;
if ( V_159 < V_27 ) {
V_159 = ( T_1 ) - 1 ;
V_394 = V_27 ;
}
F_97 ( & F_124 ( V_26 ) -> V_151 , V_15 , V_15 + V_21 - 1 , 0 ,
& V_97 ) ;
V_211 = F_277 ( V_26 , V_15 , V_394 ,
V_288 ) ;
if ( ! V_211 )
goto V_107;
if ( F_286 ( V_211 ) ) {
V_74 = F_287 ( V_211 ) ;
goto V_107;
}
while ( ! V_16 ) {
T_1 V_408 = 0 ;
if ( V_211 -> V_15 >= F_129 || F_199 ( V_211 ) < V_260 )
break;
V_400 = F_129 ( V_211 -> V_15 , V_260 ) ;
if ( ! F_160 ( V_217 , & V_211 -> V_7 ) )
V_408 = V_400 - V_211 -> V_15 ;
V_338 = F_199 ( V_211 ) ;
V_401 = V_338 - V_400 ;
V_395 = 0 ;
V_7 = 0 ;
V_260 = F_199 ( V_211 ) ;
if ( V_260 >= F_129 )
V_16 = 1 ;
if ( V_211 -> V_216 == V_409 ) {
V_16 = 1 ;
V_7 |= V_410 ;
} else if ( V_211 -> V_216 == V_308 ) {
V_7 |= ( V_411 |
V_412 ) ;
} else if ( V_211 -> V_216 == V_413 ) {
V_7 |= ( V_414 |
V_415 ) ;
} else if ( V_392 -> V_416 ) {
T_1 V_417 = V_211 -> V_216 -
( V_211 -> V_15 - V_211 -> V_418 ) ;
V_395 = V_211 -> V_216 + V_408 ;
V_74 = F_288 ( NULL , V_54 -> V_172 ,
V_54 -> V_406 ,
F_19 ( V_26 ) , V_417 ) ;
if ( V_74 < 0 )
goto V_419;
if ( V_74 )
V_7 |= V_420 ;
V_74 = 0 ;
}
if ( F_160 ( V_217 , & V_211 -> V_7 ) )
V_7 |= V_421 ;
F_159 ( V_211 ) ;
V_211 = NULL ;
if ( ( V_400 >= V_159 ) || V_401 == ( T_1 ) - 1 ||
( V_159 == ( T_1 ) - 1 && V_27 <= V_338 ) ) {
V_7 |= V_410 ;
V_16 = 1 ;
}
V_211 = F_277 ( V_26 , V_260 , V_394 ,
V_288 ) ;
if ( F_286 ( V_211 ) ) {
V_74 = F_287 ( V_211 ) ;
goto V_107;
}
if ( ! V_211 ) {
V_7 |= V_410 ;
V_16 = 1 ;
}
V_74 = F_289 ( V_392 , V_400 , V_395 ,
V_401 , V_7 ) ;
if ( V_74 )
goto V_419;
}
V_419:
F_159 ( V_211 ) ;
V_107:
F_283 ( V_399 ) ;
F_100 ( & F_124 ( V_26 ) -> V_151 , V_15 , V_15 + V_21 - 1 ,
& V_97 , V_124 ) ;
return V_74 ;
}
static void F_290 ( struct V_10 * V_11 )
{
F_7 ( & V_11 -> V_14 ) ;
F_14 ( V_22 , V_11 ) ;
}
int F_291 ( struct V_10 * V_11 )
{
return ( F_13 ( & V_11 -> V_362 ) ||
F_160 ( V_346 , & V_11 -> V_345 ) ||
F_160 ( V_350 , & V_11 -> V_345 ) ) ;
}
static void F_292 ( struct V_10 * V_11 )
{
unsigned long V_125 ;
struct V_128 * V_128 ;
int V_422 = ! F_160 ( V_423 , & V_11 -> V_345 ) ;
F_72 ( F_291 ( V_11 ) ) ;
V_125 = F_148 ( V_11 -> V_15 , V_11 -> V_21 ) ;
if ( V_125 == 0 )
return;
do {
V_125 -- ;
V_128 = V_11 -> V_137 [ V_125 ] ;
if ( V_128 && V_422 ) {
F_70 ( & V_128 -> V_28 -> V_376 ) ;
if ( F_192 ( V_128 ) &&
V_128 -> V_50 == ( unsigned long ) V_11 ) {
F_72 ( F_160 ( V_350 , & V_11 -> V_345 ) ) ;
F_72 ( F_120 ( V_128 ) ) ;
F_72 ( F_223 ( V_128 ) ) ;
F_293 ( V_128 ) ;
F_195 ( V_128 , 0 ) ;
F_105 ( V_128 ) ;
}
F_74 ( & V_128 -> V_28 -> V_376 ) ;
}
if ( V_128 ) {
F_105 ( V_128 ) ;
}
} while ( V_125 != 0 );
}
static inline void F_294 ( struct V_10 * V_11 )
{
F_292 ( V_11 ) ;
F_290 ( V_11 ) ;
}
static struct V_10 *
F_295 ( struct V_32 * V_172 , T_1 V_15 ,
unsigned long V_21 , T_3 V_49 )
{
struct V_10 * V_11 = NULL ;
V_11 = F_296 ( V_22 , V_49 ) ;
if ( V_11 == NULL )
return NULL ;
V_11 -> V_15 = V_15 ;
V_11 -> V_21 = V_21 ;
V_11 -> V_172 = V_172 ;
V_11 -> V_345 = 0 ;
F_297 ( & V_11 -> V_48 ) ;
F_36 ( & V_11 -> V_424 , 0 ) ;
F_36 ( & V_11 -> V_425 , 0 ) ;
F_36 ( & V_11 -> V_426 , 0 ) ;
F_36 ( & V_11 -> V_427 , 0 ) ;
F_36 ( & V_11 -> V_428 , 0 ) ;
F_36 ( & V_11 -> V_429 , 0 ) ;
V_11 -> V_430 = 0 ;
F_37 ( & V_11 -> V_431 ) ;
F_37 ( & V_11 -> V_432 ) ;
F_3 ( & V_11 -> V_14 , & V_19 ) ;
F_32 ( & V_11 -> V_349 ) ;
F_36 ( & V_11 -> V_17 , 1 ) ;
F_36 ( & V_11 -> V_362 , 0 ) ;
F_298 ( V_433
> V_434 ) ;
F_72 ( V_21 > V_434 ) ;
return V_11 ;
}
struct V_10 * F_299 ( struct V_10 * V_435 )
{
unsigned long V_139 ;
struct V_128 * V_60 ;
struct V_10 * V_5 ;
unsigned long V_200 = F_148 ( V_435 -> V_15 , V_435 -> V_21 ) ;
V_5 = F_295 ( NULL , V_435 -> V_15 , V_435 -> V_21 , V_124 ) ;
if ( V_5 == NULL )
return NULL ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
V_60 = F_300 ( V_124 ) ;
if ( ! V_60 ) {
F_294 ( V_5 ) ;
return NULL ;
}
F_191 ( V_5 , V_60 ) ;
F_41 ( F_120 ( V_60 ) ) ;
F_134 ( V_60 ) ;
V_5 -> V_137 [ V_139 ] = V_60 ;
}
F_301 ( V_5 , V_435 , 0 , 0 , V_435 -> V_21 ) ;
F_236 ( V_436 , & V_5 -> V_345 ) ;
F_236 ( V_423 , & V_5 -> V_345 ) ;
return V_5 ;
}
struct V_10 * F_302 ( T_1 V_15 , unsigned long V_21 )
{
struct V_10 * V_11 ;
unsigned long V_200 = F_148 ( 0 , V_21 ) ;
unsigned long V_139 ;
V_11 = F_295 ( NULL , V_15 , V_21 , V_124 ) ;
if ( ! V_11 )
return NULL ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
V_11 -> V_137 [ V_139 ] = F_300 ( V_124 ) ;
if ( ! V_11 -> V_137 [ V_139 ] )
goto V_95;
}
F_303 ( V_11 ) ;
F_304 ( V_11 , 0 ) ;
F_236 ( V_423 , & V_11 -> V_345 ) ;
return V_11 ;
V_95:
for (; V_139 > 0 ; V_139 -- )
F_305 ( V_11 -> V_137 [ V_139 - 1 ] ) ;
F_290 ( V_11 ) ;
return NULL ;
}
static void F_306 ( struct V_10 * V_11 )
{
int V_17 ;
V_17 = F_13 ( & V_11 -> V_17 ) ;
if ( V_17 >= 2 && F_160 ( V_437 , & V_11 -> V_345 ) )
return;
F_70 ( & V_11 -> V_349 ) ;
if ( ! F_245 ( V_437 , & V_11 -> V_345 ) )
F_82 ( & V_11 -> V_17 ) ;
F_74 ( & V_11 -> V_349 ) ;
}
static void F_307 ( struct V_10 * V_11 ,
struct V_128 * V_438 )
{
unsigned long V_200 , V_139 ;
F_306 ( V_11 ) ;
V_200 = F_148 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
struct V_128 * V_60 = V_11 -> V_137 [ V_139 ] ;
if ( V_60 != V_438 )
F_308 ( V_60 ) ;
}
}
struct V_10 * F_309 ( struct V_32 * V_172 ,
T_1 V_15 )
{
struct V_10 * V_11 ;
F_310 () ;
V_11 = F_311 ( & V_172 -> V_439 ,
V_15 >> V_126 ) ;
if ( V_11 && F_255 ( & V_11 -> V_17 ) ) {
F_312 () ;
F_307 ( V_11 , NULL ) ;
return V_11 ;
}
F_312 () ;
return NULL ;
}
struct V_10 * F_313 ( struct V_32 * V_172 ,
T_1 V_15 , unsigned long V_21 )
{
struct V_10 * V_11 , * V_440 = NULL ;
int V_74 ;
V_11 = F_309 ( V_172 , V_15 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_302 ( V_15 , V_21 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_172 = V_172 ;
V_104:
V_74 = F_314 ( V_124 & ~ V_441 ) ;
if ( V_74 )
goto V_442;
F_70 ( & V_172 -> V_443 ) ;
V_74 = F_315 ( & V_172 -> V_439 ,
V_15 >> V_126 , V_11 ) ;
F_74 ( & V_172 -> V_443 ) ;
F_316 () ;
if ( V_74 == - V_84 ) {
V_440 = F_309 ( V_172 , V_15 ) ;
if ( V_440 )
goto V_442;
else
goto V_104;
}
F_306 ( V_11 ) ;
F_236 ( V_444 , & V_11 -> V_345 ) ;
F_82 ( & V_11 -> V_17 ) ;
return V_11 ;
V_442:
F_294 ( V_11 ) ;
return V_440 ;
}
struct V_10 * F_317 ( struct V_32 * V_172 ,
T_1 V_15 , unsigned long V_21 )
{
unsigned long V_200 = F_148 ( V_15 , V_21 ) ;
unsigned long V_139 ;
unsigned long V_125 = V_15 >> V_126 ;
struct V_10 * V_11 ;
struct V_10 * V_440 = NULL ;
struct V_128 * V_60 ;
struct V_44 * V_28 = V_172 -> V_202 -> V_129 ;
int V_242 = 1 ;
int V_74 ;
V_11 = F_309 ( V_172 , V_15 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_295 ( V_172 , V_15 , V_21 , V_124 ) ;
if ( ! V_11 )
return NULL ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ , V_125 ++ ) {
V_60 = F_318 ( V_28 , V_125 , V_124 ) ;
if ( ! V_60 )
goto V_442;
F_70 ( & V_28 -> V_376 ) ;
if ( F_192 ( V_60 ) ) {
V_440 = (struct V_10 * ) V_60 -> V_50 ;
if ( F_255 ( & V_440 -> V_17 ) ) {
F_74 ( & V_28 -> V_376 ) ;
F_117 ( V_60 ) ;
F_105 ( V_60 ) ;
F_307 ( V_440 , V_60 ) ;
goto V_442;
}
F_293 ( V_60 ) ;
F_41 ( F_120 ( V_60 ) ) ;
F_105 ( V_60 ) ;
}
F_191 ( V_11 , V_60 ) ;
F_74 ( & V_28 -> V_376 ) ;
F_41 ( F_120 ( V_60 ) ) ;
V_11 -> V_137 [ V_139 ] = V_60 ;
if ( ! F_202 ( V_60 ) )
V_242 = 0 ;
}
if ( V_242 )
F_236 ( V_436 , & V_11 -> V_345 ) ;
V_104:
V_74 = F_314 ( V_124 & ~ V_441 ) ;
if ( V_74 )
goto V_442;
F_70 ( & V_172 -> V_443 ) ;
V_74 = F_315 ( & V_172 -> V_439 ,
V_15 >> V_126 , V_11 ) ;
F_74 ( & V_172 -> V_443 ) ;
F_316 () ;
if ( V_74 == - V_84 ) {
V_440 = F_309 ( V_172 , V_15 ) ;
if ( V_440 )
goto V_442;
else
goto V_104;
}
F_306 ( V_11 ) ;
F_236 ( V_444 , & V_11 -> V_345 ) ;
F_319 ( V_11 -> V_137 [ 0 ] ) ;
for ( V_139 = 1 ; V_139 < V_200 ; V_139 ++ ) {
V_60 = V_11 -> V_137 [ V_139 ] ;
F_320 ( V_60 ) ;
F_117 ( V_60 ) ;
}
F_117 ( V_11 -> V_137 [ 0 ] ) ;
return V_11 ;
V_442:
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
if ( V_11 -> V_137 [ V_139 ] )
F_117 ( V_11 -> V_137 [ V_139 ] ) ;
}
F_41 ( ! F_40 ( & V_11 -> V_17 ) ) ;
F_294 ( V_11 ) ;
return V_440 ;
}
static inline void F_321 ( struct V_445 * V_6 )
{
struct V_10 * V_11 =
F_322 ( V_6 , struct V_10 , V_445 ) ;
F_290 ( V_11 ) ;
}
static int F_323 ( struct V_10 * V_11 )
{
F_41 ( F_13 ( & V_11 -> V_17 ) == 0 ) ;
if ( F_40 ( & V_11 -> V_17 ) ) {
if ( F_235 ( V_444 , & V_11 -> V_345 ) ) {
struct V_32 * V_172 = V_11 -> V_172 ;
F_74 ( & V_11 -> V_349 ) ;
F_70 ( & V_172 -> V_443 ) ;
F_324 ( & V_172 -> V_439 ,
V_11 -> V_15 >> V_126 ) ;
F_74 ( & V_172 -> V_443 ) ;
} else {
F_74 ( & V_11 -> V_349 ) ;
}
F_292 ( V_11 ) ;
F_325 ( & V_11 -> V_445 , F_321 ) ;
return 1 ;
}
F_74 ( & V_11 -> V_349 ) ;
return 0 ;
}
void F_256 ( struct V_10 * V_11 )
{
int V_17 ;
int V_446 ;
if ( ! V_11 )
return;
while ( 1 ) {
V_17 = F_13 ( & V_11 -> V_17 ) ;
if ( V_17 <= 3 )
break;
V_446 = F_326 ( & V_11 -> V_17 , V_17 , V_17 - 1 ) ;
if ( V_446 == V_17 )
return;
}
F_70 ( & V_11 -> V_349 ) ;
if ( F_13 ( & V_11 -> V_17 ) == 2 &&
F_160 ( V_423 , & V_11 -> V_345 ) )
F_71 ( & V_11 -> V_17 ) ;
if ( F_13 ( & V_11 -> V_17 ) == 2 &&
F_160 ( V_447 , & V_11 -> V_345 ) &&
! F_291 ( V_11 ) &&
F_235 ( V_437 , & V_11 -> V_345 ) )
F_71 ( & V_11 -> V_17 ) ;
F_323 ( V_11 ) ;
}
void F_327 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return;
F_70 ( & V_11 -> V_349 ) ;
F_236 ( V_447 , & V_11 -> V_345 ) ;
if ( F_13 ( & V_11 -> V_17 ) == 2 && ! F_291 ( V_11 ) &&
F_235 ( V_437 , & V_11 -> V_345 ) )
F_71 ( & V_11 -> V_17 ) ;
F_323 ( V_11 ) ;
}
void F_328 ( struct V_10 * V_11 )
{
unsigned long V_139 ;
unsigned long V_200 ;
struct V_128 * V_128 ;
V_200 = F_148 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
if ( ! F_120 ( V_128 ) )
continue;
F_119 ( V_128 ) ;
F_41 ( ! F_192 ( V_128 ) ) ;
F_104 ( V_128 ) ;
F_329 ( & V_128 -> V_28 -> V_448 ) ;
if ( ! F_120 ( V_128 ) ) {
F_330 ( & V_128 -> V_28 -> V_449 ,
F_331 ( V_128 ) ,
V_373 ) ;
}
F_332 ( & V_128 -> V_28 -> V_448 ) ;
F_227 ( V_128 ) ;
F_117 ( V_128 ) ;
}
F_41 ( F_13 ( & V_11 -> V_17 ) == 0 ) ;
}
int F_333 ( struct V_10 * V_11 )
{
unsigned long V_139 ;
unsigned long V_200 ;
int V_450 = 0 ;
F_306 ( V_11 ) ;
V_450 = F_245 ( V_350 , & V_11 -> V_345 ) ;
V_200 = F_148 ( V_11 -> V_15 , V_11 -> V_21 ) ;
F_41 ( F_13 ( & V_11 -> V_17 ) == 0 ) ;
F_41 ( ! F_160 ( V_437 , & V_11 -> V_345 ) ) ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ )
F_334 ( V_11 -> V_137 [ V_139 ] ) ;
return V_450 ;
}
int F_335 ( struct V_10 * V_11 )
{
unsigned long V_139 ;
struct V_128 * V_128 ;
unsigned long V_200 ;
F_241 ( V_436 , & V_11 -> V_345 ) ;
V_200 = F_148 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
if ( V_128 )
F_167 ( V_128 ) ;
}
return 0 ;
}
int F_303 ( struct V_10 * V_11 )
{
unsigned long V_139 ;
struct V_128 * V_128 ;
unsigned long V_200 ;
F_236 ( V_436 , & V_11 -> V_345 ) ;
V_200 = F_148 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_139 = 0 ; V_139 < V_200 ; V_139 ++ ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
F_134 ( V_128 ) ;
}
return 0 ;
}
int F_336 ( struct V_10 * V_11 )
{
return F_160 ( V_436 , & V_11 -> V_345 ) ;
}
int F_337 ( struct V_24 * V_25 ,
struct V_10 * V_11 , T_1 V_15 , int V_109 ,
T_12 * V_288 , int V_171 )
{
unsigned long V_139 ;
unsigned long V_451 ;
struct V_128 * V_128 ;
int V_95 ;
int V_74 = 0 ;
int V_452 = 0 ;
int V_453 = 1 ;
unsigned long V_200 ;
unsigned long V_454 = 0 ;
struct V_41 * V_41 = NULL ;
unsigned long V_215 = 0 ;
if ( F_160 ( V_436 , & V_11 -> V_345 ) )
return 0 ;
if ( V_15 ) {
F_41 ( V_15 < V_11 -> V_15 ) ;
V_451 = ( V_15 >> V_126 ) -
( V_11 -> V_15 >> V_126 ) ;
} else {
V_451 = 0 ;
}
V_200 = F_148 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_139 = V_451 ; V_139 < V_200 ; V_139 ++ ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
if ( V_109 == V_455 ) {
if ( ! F_239 ( V_128 ) )
goto V_456;
} else {
F_119 ( V_128 ) ;
}
V_452 ++ ;
if ( ! F_202 ( V_128 ) ) {
V_454 ++ ;
V_453 = 0 ;
}
}
if ( V_453 ) {
if ( V_451 == 0 )
F_236 ( V_436 , & V_11 -> V_345 ) ;
goto V_456;
}
F_241 ( V_457 , & V_11 -> V_345 ) ;
V_11 -> V_458 = 0 ;
F_36 ( & V_11 -> V_362 , V_454 ) ;
for ( V_139 = V_451 ; V_139 < V_200 ; V_139 ++ ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
if ( ! F_202 ( V_128 ) ) {
F_227 ( V_128 ) ;
V_95 = F_214 ( V_25 , V_128 ,
V_288 , & V_41 ,
V_171 , & V_215 ,
V_313 | V_363 ) ;
if ( V_95 )
V_74 = V_95 ;
} else {
F_117 ( V_128 ) ;
}
}
if ( V_41 ) {
V_95 = F_183 ( V_313 | V_363 , V_41 , V_171 ,
V_215 ) ;
if ( V_95 )
return V_95 ;
}
if ( V_74 || V_109 != V_459 )
return V_74 ;
for ( V_139 = V_451 ; V_139 < V_200 ; V_139 ++ ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
F_338 ( V_128 ) ;
if ( ! F_202 ( V_128 ) )
V_74 = - V_185 ;
}
return V_74 ;
V_456:
V_139 = V_451 ;
while ( V_452 > 0 ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
V_139 ++ ;
F_117 ( V_128 ) ;
V_452 -- ;
}
return V_74 ;
}
void F_339 ( struct V_10 * V_11 , void * V_460 ,
unsigned long V_15 ,
unsigned long V_21 )
{
T_10 V_291 ;
T_10 V_56 ;
struct V_128 * V_128 ;
char * V_461 ;
char * V_462 = ( char * ) V_460 ;
T_10 V_463 = V_11 -> V_15 & ( ( T_1 ) V_148 - 1 ) ;
unsigned long V_139 = ( V_463 + V_15 ) >> V_126 ;
F_41 ( V_15 > V_11 -> V_21 ) ;
F_41 ( V_15 + V_21 > V_11 -> V_15 + V_11 -> V_21 ) ;
V_56 = ( V_463 + V_15 ) & ( V_148 - 1 ) ;
while ( V_21 > 0 ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
V_291 = F_128 ( V_21 , ( V_148 - V_56 ) ) ;
V_461 = F_340 ( V_128 ) ;
memcpy ( V_462 , V_461 + V_56 , V_291 ) ;
V_462 += V_291 ;
V_21 -= V_291 ;
V_56 = 0 ;
V_139 ++ ;
}
}
int F_341 ( struct V_10 * V_11 , void T_17 * V_460 ,
unsigned long V_15 ,
unsigned long V_21 )
{
T_10 V_291 ;
T_10 V_56 ;
struct V_128 * V_128 ;
char * V_461 ;
char T_17 * V_462 = ( char T_17 * ) V_460 ;
T_10 V_463 = V_11 -> V_15 & ( ( T_1 ) V_148 - 1 ) ;
unsigned long V_139 = ( V_463 + V_15 ) >> V_126 ;
int V_74 = 0 ;
F_41 ( V_15 > V_11 -> V_21 ) ;
F_41 ( V_15 + V_21 > V_11 -> V_15 + V_11 -> V_21 ) ;
V_56 = ( V_463 + V_15 ) & ( V_148 - 1 ) ;
while ( V_21 > 0 ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
V_291 = F_128 ( V_21 , ( V_148 - V_56 ) ) ;
V_461 = F_340 ( V_128 ) ;
if ( F_342 ( V_462 , V_461 + V_56 , V_291 ) ) {
V_74 = - V_464 ;
break;
}
V_462 += V_291 ;
V_21 -= V_291 ;
V_56 = 0 ;
V_139 ++ ;
}
return V_74 ;
}
int F_343 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_465 , char * * V_385 ,
unsigned long * V_466 ,
unsigned long * V_467 )
{
T_10 V_56 = V_15 & ( V_148 - 1 ) ;
char * V_461 ;
struct V_128 * V_60 ;
T_10 V_463 = V_11 -> V_15 & ( ( T_1 ) V_148 - 1 ) ;
unsigned long V_139 = ( V_463 + V_15 ) >> V_126 ;
unsigned long V_468 = ( V_463 + V_15 + V_465 - 1 ) >>
V_126 ;
if ( V_139 != V_468 )
return - V_402 ;
if ( V_139 == 0 ) {
V_56 = V_463 ;
* V_466 = 0 ;
} else {
V_56 = 0 ;
* V_466 = ( ( T_1 ) V_139 << V_126 ) - V_463 ;
}
if ( V_15 + V_465 > V_11 -> V_21 ) {
F_58 ( 1 , V_20 L_28
L_29 ,
V_11 -> V_15 , V_11 -> V_21 , V_15 , V_465 ) ;
return - V_402 ;
}
V_60 = V_11 -> V_137 [ V_139 ] ;
V_461 = F_340 ( V_60 ) ;
* V_385 = V_461 + V_56 ;
* V_467 = V_148 - V_56 ;
return 0 ;
}
int F_344 ( struct V_10 * V_11 , const void * V_469 ,
unsigned long V_15 ,
unsigned long V_21 )
{
T_10 V_291 ;
T_10 V_56 ;
struct V_128 * V_128 ;
char * V_461 ;
char * V_470 = ( char * ) V_469 ;
T_10 V_463 = V_11 -> V_15 & ( ( T_1 ) V_148 - 1 ) ;
unsigned long V_139 = ( V_463 + V_15 ) >> V_126 ;
int V_74 = 0 ;
F_41 ( V_15 > V_11 -> V_21 ) ;
F_41 ( V_15 + V_21 > V_11 -> V_15 + V_11 -> V_21 ) ;
V_56 = ( V_463 + V_15 ) & ( V_148 - 1 ) ;
while ( V_21 > 0 ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
V_291 = F_128 ( V_21 , ( V_148 - V_56 ) ) ;
V_461 = F_340 ( V_128 ) ;
V_74 = memcmp ( V_470 , V_461 + V_56 , V_291 ) ;
if ( V_74 )
break;
V_470 += V_291 ;
V_21 -= V_291 ;
V_56 = 0 ;
V_139 ++ ;
}
return V_74 ;
}
void F_345 ( struct V_10 * V_11 , const void * V_471 ,
unsigned long V_15 , unsigned long V_21 )
{
T_10 V_291 ;
T_10 V_56 ;
struct V_128 * V_128 ;
char * V_461 ;
char * V_435 = ( char * ) V_471 ;
T_10 V_463 = V_11 -> V_15 & ( ( T_1 ) V_148 - 1 ) ;
unsigned long V_139 = ( V_463 + V_15 ) >> V_126 ;
F_41 ( V_15 > V_11 -> V_21 ) ;
F_41 ( V_15 + V_21 > V_11 -> V_15 + V_11 -> V_21 ) ;
V_56 = ( V_463 + V_15 ) & ( V_148 - 1 ) ;
while ( V_21 > 0 ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
F_41 ( ! F_202 ( V_128 ) ) ;
V_291 = F_128 ( V_21 , V_148 - V_56 ) ;
V_461 = F_340 ( V_128 ) ;
memcpy ( V_461 + V_56 , V_435 , V_291 ) ;
V_435 += V_291 ;
V_21 -= V_291 ;
V_56 = 0 ;
V_139 ++ ;
}
}
void F_346 ( struct V_10 * V_11 , char V_472 ,
unsigned long V_15 , unsigned long V_21 )
{
T_10 V_291 ;
T_10 V_56 ;
struct V_128 * V_128 ;
char * V_461 ;
T_10 V_463 = V_11 -> V_15 & ( ( T_1 ) V_148 - 1 ) ;
unsigned long V_139 = ( V_463 + V_15 ) >> V_126 ;
F_41 ( V_15 > V_11 -> V_21 ) ;
F_41 ( V_15 + V_21 > V_11 -> V_15 + V_11 -> V_21 ) ;
V_56 = ( V_463 + V_15 ) & ( V_148 - 1 ) ;
while ( V_21 > 0 ) {
V_128 = V_11 -> V_137 [ V_139 ] ;
F_41 ( ! F_202 ( V_128 ) ) ;
V_291 = F_128 ( V_21 , V_148 - V_56 ) ;
V_461 = F_340 ( V_128 ) ;
memset ( V_461 + V_56 , V_472 , V_291 ) ;
V_21 -= V_291 ;
V_56 = 0 ;
V_139 ++ ;
}
}
void F_301 ( struct V_10 * V_462 , struct V_10 * V_435 ,
unsigned long V_473 , unsigned long V_474 ,
unsigned long V_21 )
{
T_1 V_475 = V_462 -> V_21 ;
T_10 V_291 ;
T_10 V_56 ;
struct V_128 * V_128 ;
char * V_461 ;
T_10 V_463 = V_462 -> V_15 & ( ( T_1 ) V_148 - 1 ) ;
unsigned long V_139 = ( V_463 + V_473 ) >> V_126 ;
F_41 ( V_435 -> V_21 != V_475 ) ;
V_56 = ( V_463 + V_473 ) &
( V_148 - 1 ) ;
while ( V_21 > 0 ) {
V_128 = V_462 -> V_137 [ V_139 ] ;
F_41 ( ! F_202 ( V_128 ) ) ;
V_291 = F_128 ( V_21 , ( unsigned long ) ( V_148 - V_56 ) ) ;
V_461 = F_340 ( V_128 ) ;
F_339 ( V_435 , V_461 + V_56 , V_474 , V_291 ) ;
V_474 += V_291 ;
V_21 -= V_291 ;
V_56 = 0 ;
V_139 ++ ;
}
}
static inline bool F_347 ( unsigned long V_435 , unsigned long V_462 , unsigned long V_21 )
{
unsigned long V_476 = ( V_435 > V_462 ) ? V_435 - V_462 : V_462 - V_435 ;
return V_476 < V_21 ;
}
static void F_348 ( struct V_128 * V_477 , struct V_128 * V_478 ,
unsigned long V_479 , unsigned long V_480 ,
unsigned long V_21 )
{
char * V_481 = F_340 ( V_477 ) ;
char * V_482 ;
int V_483 = 0 ;
if ( V_477 != V_478 ) {
V_482 = F_340 ( V_478 ) ;
} else {
V_482 = V_481 ;
if ( F_347 ( V_480 , V_479 , V_21 ) )
V_483 = 1 ;
}
if ( V_483 )
memmove ( V_481 + V_479 , V_482 + V_480 , V_21 ) ;
else
memcpy ( V_481 + V_479 , V_482 + V_480 , V_21 ) ;
}
void F_349 ( struct V_10 * V_462 , unsigned long V_473 ,
unsigned long V_474 , unsigned long V_21 )
{
T_10 V_291 ;
T_10 V_484 ;
T_10 V_485 ;
T_10 V_463 = V_462 -> V_15 & ( ( T_1 ) V_148 - 1 ) ;
unsigned long V_486 ;
unsigned long V_487 ;
if ( V_474 + V_21 > V_462 -> V_21 ) {
F_15 ( V_20 L_30
L_31 , V_474 , V_21 , V_462 -> V_21 ) ;
F_72 ( 1 ) ;
}
if ( V_473 + V_21 > V_462 -> V_21 ) {
F_15 ( V_20 L_32
L_31 , V_473 , V_21 , V_462 -> V_21 ) ;
F_72 ( 1 ) ;
}
while ( V_21 > 0 ) {
V_484 = ( V_463 + V_473 ) &
( V_148 - 1 ) ;
V_485 = ( V_463 + V_474 ) &
( V_148 - 1 ) ;
V_486 = ( V_463 + V_473 ) >> V_126 ;
V_487 = ( V_463 + V_474 ) >> V_126 ;
V_291 = F_128 ( V_21 , ( unsigned long ) ( V_148 -
V_485 ) ) ;
V_291 = F_116 (unsigned long, cur,
(unsigned long)(PAGE_CACHE_SIZE - dst_off_in_page)) ;
F_348 ( V_462 -> V_137 [ V_486 ] , V_462 -> V_137 [ V_487 ] ,
V_484 , V_485 , V_291 ) ;
V_474 += V_291 ;
V_473 += V_291 ;
V_21 -= V_291 ;
}
}
void F_350 ( struct V_10 * V_462 , unsigned long V_473 ,
unsigned long V_474 , unsigned long V_21 )
{
T_10 V_291 ;
T_10 V_484 ;
T_10 V_485 ;
unsigned long V_488 = V_473 + V_21 - 1 ;
unsigned long V_489 = V_474 + V_21 - 1 ;
T_10 V_463 = V_462 -> V_15 & ( ( T_1 ) V_148 - 1 ) ;
unsigned long V_486 ;
unsigned long V_487 ;
if ( V_474 + V_21 > V_462 -> V_21 ) {
F_15 ( V_20 L_30
L_33 , V_474 , V_21 , V_462 -> V_21 ) ;
F_72 ( 1 ) ;
}
if ( V_473 + V_21 > V_462 -> V_21 ) {
F_15 ( V_20 L_32
L_33 , V_473 , V_21 , V_462 -> V_21 ) ;
F_72 ( 1 ) ;
}
if ( V_473 < V_474 ) {
F_349 ( V_462 , V_473 , V_474 , V_21 ) ;
return;
}
while ( V_21 > 0 ) {
V_486 = ( V_463 + V_488 ) >> V_126 ;
V_487 = ( V_463 + V_489 ) >> V_126 ;
V_484 = ( V_463 + V_488 ) &
( V_148 - 1 ) ;
V_485 = ( V_463 + V_489 ) &
( V_148 - 1 ) ;
V_291 = F_116 (unsigned long, len, src_off_in_page + 1 ) ;
V_291 = F_128 ( V_291 , V_484 + 1 ) ;
F_348 ( V_462 -> V_137 [ V_486 ] , V_462 -> V_137 [ V_487 ] ,
V_484 - V_291 + 1 ,
V_485 - V_291 + 1 , V_291 ) ;
V_488 -= V_291 ;
V_489 -= V_291 ;
V_21 -= V_291 ;
}
}
int F_351 ( struct V_128 * V_128 )
{
struct V_10 * V_11 ;
F_70 ( & V_128 -> V_28 -> V_376 ) ;
if ( ! F_192 ( V_128 ) ) {
F_74 ( & V_128 -> V_28 -> V_376 ) ;
return 1 ;
}
V_11 = (struct V_10 * ) V_128 -> V_50 ;
F_72 ( ! V_11 ) ;
F_70 ( & V_11 -> V_349 ) ;
if ( F_13 ( & V_11 -> V_17 ) != 1 || F_291 ( V_11 ) ) {
F_74 ( & V_11 -> V_349 ) ;
F_74 ( & V_128 -> V_28 -> V_376 ) ;
return 0 ;
}
F_74 ( & V_128 -> V_28 -> V_376 ) ;
if ( ! F_235 ( V_437 , & V_11 -> V_345 ) ) {
F_74 ( & V_11 -> V_349 ) ;
return 0 ;
}
return F_323 ( V_11 ) ;
}
