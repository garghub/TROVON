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
struct V_1 * V_2 , unsigned * V_80 )
{
if ( V_25 -> V_46 && V_25 -> V_46 -> V_81 )
V_25 -> V_46 -> V_81 ( V_25 -> V_28 -> V_29 , V_2 , V_80 ) ;
}
static void F_56 ( struct V_24 * V_25 ,
struct V_1 * V_2 , unsigned * V_80 )
{
if ( V_25 -> V_46 && V_25 -> V_46 -> V_82 )
V_25 -> V_46 -> V_82 ( V_25 -> V_28 -> V_29 , V_2 , V_80 ) ;
}
static int F_57 ( struct V_24 * V_25 ,
struct V_1 * V_2 , T_1 V_15 , T_1 V_16 ,
struct V_3 * * * V_60 ,
struct V_3 * * V_61 ,
unsigned * V_80 )
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
unsigned * V_80 , int V_89 )
{
struct V_1 * V_13 ;
unsigned V_90 = * V_80 & ~ V_91 ;
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
unsigned V_80 , int V_89 , int V_96 ,
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
unsigned * V_80 )
{
unsigned V_112 = * V_80 & ~ V_91 ;
F_55 ( V_25 , V_2 , V_80 ) ;
if ( ( V_112 & V_92 ) && ! ( V_2 -> V_2 & V_92 ) ) {
T_1 V_93 = V_2 -> V_16 - V_2 -> V_15 + 1 ;
V_25 -> V_47 += V_93 ;
}
V_2 -> V_2 |= V_112 ;
}
static void F_84 ( struct V_1 * V_2 ,
struct V_1 * * V_113 ,
unsigned V_7 )
{
if ( V_113 && ! ( * V_113 ) ) {
if ( ! V_7 || ( V_2 -> V_2 & V_7 ) ) {
* V_113 = V_2 ;
F_82 ( & V_2 -> V_17 ) ;
}
}
}
static void F_85 ( struct V_1 * V_2 ,
struct V_1 * * V_113 )
{
return F_84 ( V_2 , V_113 ,
V_78 | V_79 ) ;
}
static int T_4
F_86 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned V_80 , unsigned V_114 ,
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
F_85 ( V_88 , V_97 ) ;
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
F_85 ( V_2 , V_97 ) ;
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
F_85 ( V_2 , V_97 ) ;
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
F_85 ( V_88 , V_97 ) ;
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
F_85 ( V_88 , V_97 ) ;
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
int F_87 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned V_80 , T_1 * V_115 ,
struct V_1 * * V_97 , T_3 V_49 )
{
return F_86 ( V_25 , V_15 , V_16 , V_80 , 0 , V_115 ,
V_97 , V_49 ) ;
}
int F_88 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned V_80 , unsigned V_118 ,
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
bool V_119 = true ;
F_69 ( V_25 , V_15 , V_16 ) ;
V_104:
if ( ! V_88 && ( V_49 & V_105 ) ) {
V_88 = F_33 ( V_49 ) ;
if ( ! V_88 && ! V_119 )
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
F_85 ( V_88 , V_97 ) ;
V_88 = NULL ;
goto V_107;
}
V_2 = F_44 ( V_57 , struct V_1 , V_3 ) ;
V_106:
V_116 = V_2 -> V_15 ;
V_99 = V_2 -> V_16 ;
if ( V_2 -> V_15 == V_15 && V_2 -> V_16 <= V_16 ) {
F_59 ( V_25 , V_2 , & V_80 ) ;
F_85 ( V_2 , V_97 ) ;
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
F_85 ( V_2 , V_97 ) ;
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
F_85 ( V_88 , V_97 ) ;
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
F_85 ( V_88 , V_97 ) ;
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
V_119 = false ;
goto V_104;
}
int F_89 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
T_3 V_49 )
{
return F_87 ( V_25 , V_15 , V_16 , V_92 , NULL ,
NULL , V_49 ) ;
}
int F_90 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned V_80 , T_3 V_49 )
{
return F_87 ( V_25 , V_15 , V_16 , V_80 , NULL ,
NULL , V_49 ) ;
}
int F_91 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned V_80 , T_3 V_49 )
{
int V_89 = 0 ;
if ( V_80 & V_120 )
V_89 = 1 ;
return F_68 ( V_25 , V_15 , V_16 , V_80 , V_89 , 0 , NULL , V_49 ) ;
}
int F_92 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
struct V_1 * * V_97 , T_3 V_49 )
{
return F_87 ( V_25 , V_15 , V_16 ,
V_101 | V_121 ,
NULL , V_97 , V_49 ) ;
}
int F_93 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
struct V_1 * * V_97 , T_3 V_49 )
{
return F_87 ( V_25 , V_15 , V_16 ,
V_101 | V_121 | V_122 ,
NULL , V_97 , V_49 ) ;
}
int F_94 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
T_3 V_49 )
{
return F_68 ( V_25 , V_15 , V_16 ,
V_92 | V_101 |
V_123 , 0 , 0 , NULL , V_49 ) ;
}
int F_95 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
T_3 V_49 )
{
return F_87 ( V_25 , V_15 , V_16 , V_124 , NULL ,
NULL , V_49 ) ;
}
int F_96 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
struct V_1 * * V_97 , T_3 V_49 )
{
return F_87 ( V_25 , V_15 , V_16 , V_121 , NULL ,
V_97 , V_49 ) ;
}
int F_97 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
struct V_1 * * V_97 , T_3 V_49 )
{
return F_68 ( V_25 , V_15 , V_16 , V_121 , 0 , 0 ,
V_97 , V_49 ) ;
}
int F_98 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned V_80 , struct V_1 * * V_97 )
{
int V_95 ;
T_1 V_115 ;
while ( 1 ) {
V_95 = F_86 ( V_25 , V_15 , V_16 , V_120 | V_80 ,
V_120 , & V_115 ,
V_97 , V_125 ) ;
if ( V_95 == - V_84 ) {
F_81 ( V_25 , V_115 , V_16 , V_120 ) ;
V_15 = V_115 ;
} else
break;
F_41 ( V_15 > V_16 ) ;
}
return V_95 ;
}
int F_99 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 )
{
return F_98 ( V_25 , V_15 , V_16 , 0 , NULL ) ;
}
int F_100 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 )
{
int V_95 ;
T_1 V_115 ;
V_95 = F_86 ( V_25 , V_15 , V_16 , V_120 , V_120 ,
& V_115 , NULL , V_125 ) ;
if ( V_95 == - V_84 ) {
if ( V_115 > V_15 )
F_68 ( V_25 , V_15 , V_115 - 1 ,
V_120 , 1 , 0 , NULL , V_125 ) ;
return 0 ;
}
return 1 ;
}
int F_101 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
struct V_1 * * V_98 , T_3 V_49 )
{
return F_68 ( V_25 , V_15 , V_16 , V_120 , 1 , 0 , V_98 ,
V_49 ) ;
}
int F_102 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 )
{
return F_68 ( V_25 , V_15 , V_16 , V_120 , 1 , 0 , NULL ,
V_125 ) ;
}
int F_103 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_126 = V_15 >> V_127 ;
unsigned long V_128 = V_16 >> V_127 ;
struct V_129 * V_129 ;
while ( V_126 <= V_128 ) {
V_129 = F_104 ( V_26 -> V_130 , V_126 ) ;
F_72 ( ! V_129 ) ;
F_105 ( V_129 ) ;
F_106 ( V_129 ) ;
V_126 ++ ;
}
return 0 ;
}
int F_107 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_126 = V_15 >> V_127 ;
unsigned long V_128 = V_16 >> V_127 ;
struct V_129 * V_129 ;
while ( V_126 <= V_128 ) {
V_129 = F_104 ( V_26 -> V_130 , V_126 ) ;
F_72 ( ! V_129 ) ;
F_108 ( V_129 ) ;
F_109 ( V_129 ) ;
F_106 ( V_129 ) ;
V_126 ++ ;
}
return 0 ;
}
static int F_110 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 )
{
unsigned long V_126 = V_15 >> V_127 ;
unsigned long V_128 = V_16 >> V_127 ;
struct V_129 * V_129 ;
while ( V_126 <= V_128 ) {
V_129 = F_104 ( V_25 -> V_28 , V_126 ) ;
F_72 ( ! V_129 ) ;
F_111 ( V_129 ) ;
F_106 ( V_129 ) ;
V_126 ++ ;
}
return 0 ;
}
static struct V_1 *
F_112 ( struct V_24 * V_25 ,
T_1 V_15 , unsigned V_80 )
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
int F_113 ( struct V_24 * V_25 , T_1 V_15 ,
T_1 * V_131 , T_1 * V_132 , unsigned V_80 ,
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
goto V_133;
V_70 = F_48 ( V_70 ) ;
}
F_39 ( * V_97 ) ;
* V_97 = NULL ;
goto V_107;
}
F_39 ( * V_97 ) ;
* V_97 = NULL ;
}
V_2 = F_112 ( V_25 , V_15 , V_80 ) ;
V_133:
if ( V_2 ) {
F_84 ( V_2 , V_97 , 0 ) ;
* V_131 = V_2 -> V_15 ;
* V_132 = V_2 -> V_16 ;
V_74 = 0 ;
}
V_107:
F_74 ( & V_25 -> V_48 ) ;
return V_74 ;
}
static T_5 T_1 F_114 ( struct V_24 * V_25 ,
T_1 * V_15 , T_1 * V_16 , T_1 V_134 ,
struct V_1 * * V_97 )
{
struct V_3 * V_57 ;
struct V_1 * V_2 ;
T_1 V_135 = * V_15 ;
T_1 V_83 = 0 ;
T_1 V_136 = 0 ;
F_70 ( & V_25 -> V_48 ) ;
V_57 = F_51 ( V_25 , V_135 ) ;
if ( ! V_57 ) {
if ( ! V_83 )
* V_16 = ( T_1 ) - 1 ;
goto V_107;
}
while ( 1 ) {
V_2 = F_44 ( V_57 , struct V_1 , V_3 ) ;
if ( V_83 && ( V_2 -> V_15 != V_135 ||
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
V_135 = V_2 -> V_16 + 1 ;
V_57 = F_48 ( V_57 ) ;
V_136 += V_2 -> V_16 - V_2 -> V_15 + 1 ;
if ( V_136 >= V_134 )
break;
if ( ! V_57 )
break;
}
V_107:
F_74 ( & V_25 -> V_48 ) ;
return V_83 ;
}
static T_5 void F_115 ( struct V_26 * V_26 ,
struct V_129 * V_137 ,
T_1 V_15 , T_1 V_16 )
{
int V_74 ;
struct V_129 * V_138 [ 16 ] ;
unsigned long V_126 = V_15 >> V_127 ;
unsigned long V_128 = V_16 >> V_127 ;
unsigned long V_139 = V_128 - V_126 + 1 ;
int V_140 ;
if ( V_126 == V_137 -> V_126 && V_128 == V_126 )
return;
while ( V_139 > 0 ) {
V_74 = F_116 ( V_26 -> V_130 , V_126 ,
F_117 (unsigned long, nr_pages,
ARRAY_SIZE(pages)) , V_138 ) ;
for ( V_140 = 0 ; V_140 < V_74 ; V_140 ++ ) {
if ( V_138 [ V_140 ] != V_137 )
F_118 ( V_138 [ V_140 ] ) ;
F_106 ( V_138 [ V_140 ] ) ;
}
V_139 -= V_74 ;
V_126 += V_74 ;
F_75 () ;
}
}
static T_5 int F_119 ( struct V_26 * V_26 ,
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
int V_74 ;
int V_140 ;
if ( V_126 == V_137 -> V_126 && V_126 == V_128 )
return 0 ;
V_145 = V_128 - V_126 + 1 ;
while ( V_145 > 0 ) {
V_74 = F_116 ( V_26 -> V_130 , V_126 ,
F_117 (unsigned long,
nrpages, ARRAY_SIZE(pages)) , V_138 ) ;
if ( V_74 == 0 ) {
V_74 = - V_146 ;
goto V_147;
}
for ( V_140 = 0 ; V_140 < V_74 ; V_140 ++ ) {
if ( V_138 [ V_140 ] != V_137 ) {
F_120 ( V_138 [ V_140 ] ) ;
if ( ! F_121 ( V_138 [ V_140 ] ) ||
V_138 [ V_140 ] -> V_28 != V_26 -> V_130 ) {
V_74 = - V_146 ;
F_118 ( V_138 [ V_140 ] ) ;
F_106 ( V_138 [ V_140 ] ) ;
goto V_147;
}
}
F_106 ( V_138 [ V_140 ] ) ;
V_144 ++ ;
}
V_145 -= V_74 ;
V_126 += V_74 ;
F_75 () ;
}
V_74 = 0 ;
V_147:
if ( V_74 && V_144 ) {
F_115 ( V_26 , V_137 ,
V_141 ,
( ( T_1 ) ( V_143 + V_144 - 1 ) ) <<
V_127 ) ;
}
return V_74 ;
}
STATIC T_1 F_122 ( struct V_26 * V_26 ,
struct V_24 * V_25 ,
struct V_129 * V_137 , T_1 * V_15 ,
T_1 * V_16 , T_1 V_134 )
{
T_1 V_141 ;
T_1 V_142 ;
T_1 V_83 ;
struct V_1 * V_97 = NULL ;
int V_74 ;
int V_148 = 0 ;
V_104:
V_141 = * V_15 ;
V_142 = 0 ;
V_83 = F_114 ( V_25 , & V_141 , & V_142 ,
V_134 , & V_97 ) ;
if ( ! V_83 || V_142 <= * V_15 ) {
* V_15 = V_141 ;
* V_16 = V_142 ;
F_39 ( V_97 ) ;
return 0 ;
}
if ( V_141 < * V_15 )
V_141 = * V_15 ;
if ( V_142 + 1 - V_141 > V_134 )
V_142 = V_141 + V_134 - 1 ;
V_74 = F_119 ( V_26 , V_137 ,
V_141 , V_142 ) ;
if ( V_74 == - V_146 ) {
F_39 ( V_97 ) ;
V_97 = NULL ;
if ( ! V_148 ) {
V_134 = V_149 ;
V_148 = 1 ;
goto V_104;
} else {
V_83 = 0 ;
goto V_150;
}
}
F_72 ( V_74 ) ;
F_98 ( V_25 , V_141 , V_142 , 0 , & V_97 ) ;
V_74 = F_123 ( V_25 , V_141 , V_142 ,
V_101 , 1 , V_97 ) ;
if ( ! V_74 ) {
F_101 ( V_25 , V_141 , V_142 ,
& V_97 , V_125 ) ;
F_115 ( V_26 , V_137 ,
V_141 , V_142 ) ;
F_75 () ;
goto V_104;
}
F_39 ( V_97 ) ;
* V_15 = V_141 ;
* V_16 = V_142 ;
V_150:
return V_83 ;
}
int F_124 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_16 ,
struct V_129 * V_137 ,
unsigned V_118 ,
unsigned long V_151 )
{
struct V_24 * V_25 = & F_125 ( V_26 ) -> V_152 ;
int V_74 ;
struct V_129 * V_138 [ 16 ] ;
unsigned long V_126 = V_15 >> V_127 ;
unsigned long V_128 = V_16 >> V_127 ;
unsigned long V_139 = V_128 - V_126 + 1 ;
int V_140 ;
F_68 ( V_25 , V_15 , V_16 , V_118 , 1 , 0 , NULL , V_125 ) ;
if ( V_151 == 0 )
return 0 ;
if ( ( V_151 & V_153 ) && V_139 > 0 )
F_126 ( V_26 -> V_130 , - V_154 ) ;
while ( V_139 > 0 ) {
V_74 = F_116 ( V_26 -> V_130 , V_126 ,
F_117 (unsigned long,
nr_pages, ARRAY_SIZE(pages)) , V_138 ) ;
for ( V_140 = 0 ; V_140 < V_74 ; V_140 ++ ) {
if ( V_151 & V_155 )
F_127 ( V_138 [ V_140 ] ) ;
if ( V_138 [ V_140 ] == V_137 ) {
F_106 ( V_138 [ V_140 ] ) ;
continue;
}
if ( V_151 & V_156 )
F_105 ( V_138 [ V_140 ] ) ;
if ( V_151 & V_157 )
F_111 ( V_138 [ V_140 ] ) ;
if ( V_151 & V_153 )
F_128 ( V_138 [ V_140 ] ) ;
if ( V_151 & V_158 )
F_129 ( V_138 [ V_140 ] ) ;
if ( V_151 & V_159 )
F_118 ( V_138 [ V_140 ] ) ;
F_106 ( V_138 [ V_140 ] ) ;
}
V_139 -= V_74 ;
V_126 += V_74 ;
F_75 () ;
}
return 0 ;
}
T_1 F_130 ( struct V_24 * V_25 ,
T_1 * V_15 , T_1 V_160 , T_1 V_134 ,
unsigned V_80 , int V_161 )
{
struct V_3 * V_57 ;
struct V_1 * V_2 ;
T_1 V_135 = * V_15 ;
T_1 V_136 = 0 ;
T_1 V_162 = 0 ;
int V_83 = 0 ;
if ( F_41 ( V_160 <= V_135 ) )
return 0 ;
F_70 ( & V_25 -> V_48 ) ;
if ( V_135 == 0 && V_80 == V_92 ) {
V_136 = V_25 -> V_47 ;
goto V_107;
}
V_57 = F_51 ( V_25 , V_135 ) ;
if ( ! V_57 )
goto V_107;
while ( 1 ) {
V_2 = F_44 ( V_57 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 > V_160 )
break;
if ( V_161 && V_83 && V_2 -> V_15 > V_162 + 1 )
break;
if ( V_2 -> V_16 >= V_135 && ( V_2 -> V_2 & V_80 ) == V_80 ) {
V_136 += F_131 ( V_160 , V_2 -> V_16 ) + 1 -
F_132 ( V_135 , V_2 -> V_15 ) ;
if ( V_136 >= V_134 )
break;
if ( ! V_83 ) {
* V_15 = F_132 ( V_135 , V_2 -> V_15 ) ;
V_83 = 1 ;
}
V_162 = V_2 -> V_16 ;
} else if ( V_161 && V_83 ) {
break;
}
V_57 = F_48 ( V_57 ) ;
if ( ! V_57 )
break;
}
V_107:
F_74 ( & V_25 -> V_48 ) ;
return V_136 ;
}
static int F_133 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_50 )
{
struct V_3 * V_57 ;
struct V_1 * V_2 ;
int V_74 = 0 ;
F_70 ( & V_25 -> V_48 ) ;
V_57 = F_51 ( V_25 , V_15 ) ;
if ( ! V_57 ) {
V_74 = - V_163 ;
goto V_107;
}
V_2 = F_44 ( V_57 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 != V_15 ) {
V_74 = - V_163 ;
goto V_107;
}
V_2 -> V_50 = V_50 ;
V_107:
F_74 ( & V_25 -> V_48 ) ;
return V_74 ;
}
int F_134 ( struct V_24 * V_25 , T_1 V_15 , T_1 * V_50 )
{
struct V_3 * V_57 ;
struct V_1 * V_2 ;
int V_74 = 0 ;
F_70 ( & V_25 -> V_48 ) ;
V_57 = F_51 ( V_25 , V_15 ) ;
if ( ! V_57 ) {
V_74 = - V_163 ;
goto V_107;
}
V_2 = F_44 ( V_57 , struct V_1 , V_3 ) ;
if ( V_2 -> V_15 != V_15 ) {
V_74 = - V_163 ;
goto V_107;
}
* V_50 = V_2 -> V_50 ;
V_107:
F_74 ( & V_25 -> V_48 ) ;
return V_74 ;
}
int F_123 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_16 ,
unsigned V_80 , int V_164 , struct V_1 * V_98 )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_57 ;
int V_165 = 0 ;
F_70 ( & V_25 -> V_48 ) ;
if ( V_98 && F_1 ( V_98 ) && V_98 -> V_15 <= V_15 &&
V_98 -> V_16 > V_15 )
V_57 = & V_98 -> V_3 ;
else
V_57 = F_51 ( V_25 , V_15 ) ;
while ( V_57 && V_15 <= V_16 ) {
V_2 = F_44 ( V_57 , struct V_1 , V_3 ) ;
if ( V_164 && V_2 -> V_15 > V_15 ) {
V_165 = 0 ;
break;
}
if ( V_2 -> V_15 > V_16 )
break;
if ( V_2 -> V_2 & V_80 ) {
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
V_57 = F_48 ( V_57 ) ;
if ( ! V_57 ) {
if ( V_164 )
V_165 = 0 ;
break;
}
}
F_74 ( & V_25 -> V_48 ) ;
return V_165 ;
}
static void F_135 ( struct V_24 * V_25 , struct V_129 * V_129 )
{
T_1 V_15 = F_136 ( V_129 ) ;
T_1 V_16 = V_15 + V_149 - 1 ;
if ( F_123 ( V_25 , V_15 , V_16 , V_121 , 1 , NULL ) )
F_137 ( V_129 ) ;
}
int F_138 ( struct V_26 * V_26 , struct V_166 * V_167 )
{
int V_74 ;
int V_95 = 0 ;
struct V_24 * V_168 = & F_125 ( V_26 ) -> V_169 ;
F_133 ( V_168 , V_167 -> V_15 , 0 ) ;
V_74 = F_91 ( V_168 , V_167 -> V_15 ,
V_167 -> V_15 + V_167 -> V_21 - 1 ,
V_120 | V_92 , V_125 ) ;
if ( V_74 )
V_95 = V_74 ;
V_74 = F_91 ( & F_125 ( V_26 ) -> V_152 , V_167 -> V_15 ,
V_167 -> V_15 + V_167 -> V_21 - 1 ,
V_170 , V_125 ) ;
if ( V_74 && ! V_95 )
V_95 = V_74 ;
F_139 ( V_167 ) ;
return V_95 ;
}
int F_140 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_171 , T_1 V_172 ,
struct V_129 * V_129 , unsigned int V_173 , int V_174 )
{
struct V_32 * V_175 = F_125 ( V_26 ) -> V_54 -> V_175 ;
struct V_41 * V_41 ;
struct V_176 * V_177 ;
T_1 V_178 = 0 ;
T_1 V_179 ;
struct V_180 * V_181 = NULL ;
struct V_182 * V_183 = & V_175 -> V_184 ;
int V_74 ;
ASSERT ( ! ( V_175 -> V_185 -> V_186 & V_187 ) ) ;
F_72 ( ! V_174 ) ;
if ( F_141 ( V_183 , V_172 , V_171 , V_174 ) )
return 0 ;
V_41 = F_142 ( V_125 , 1 ) ;
if ( ! V_41 )
return - V_154 ;
V_41 -> V_188 . V_189 = 0 ;
V_178 = V_171 ;
V_74 = F_143 ( V_175 , V_190 , V_172 ,
& V_178 , & V_181 , V_174 ) ;
if ( V_74 ) {
F_144 ( V_41 ) ;
return - V_154 ;
}
F_72 ( V_174 != V_181 -> V_174 ) ;
V_179 = V_181 -> V_191 [ V_174 - 1 ] . V_192 >> 9 ;
V_41 -> V_188 . V_193 = V_179 ;
V_177 = V_181 -> V_191 [ V_174 - 1 ] . V_177 ;
F_145 ( V_181 ) ;
if ( ! V_177 || ! V_177 -> V_194 || ! V_177 -> V_195 ) {
F_144 ( V_41 ) ;
return - V_154 ;
}
V_41 -> V_196 = V_177 -> V_194 ;
F_146 ( V_41 , V_129 , V_171 , V_173 ) ;
if ( F_147 ( V_197 , V_41 ) ) {
F_144 ( V_41 ) ;
F_148 ( V_177 , V_198 ) ;
return - V_154 ;
}
F_149 ( V_199
L_13 ,
F_19 ( V_26 ) , V_15 ,
F_150 ( V_177 -> V_200 ) , V_179 ) ;
F_144 ( V_41 ) ;
return 0 ;
}
int F_151 ( struct V_201 * V_54 , struct V_10 * V_11 ,
int V_174 )
{
T_1 V_15 = V_11 -> V_15 ;
unsigned long V_140 , V_202 = F_152 ( V_11 -> V_15 , V_11 -> V_21 ) ;
int V_74 = 0 ;
if ( V_54 -> V_175 -> V_185 -> V_186 & V_187 )
return - V_203 ;
for ( V_140 = 0 ; V_140 < V_202 ; V_140 ++ ) {
struct V_129 * V_60 = V_11 -> V_138 [ V_140 ] ;
V_74 = F_140 ( V_54 -> V_175 -> V_204 , V_15 ,
V_149 , V_15 , V_60 ,
V_15 - F_136 ( V_60 ) , V_174 ) ;
if ( V_74 )
break;
V_15 += V_149 ;
}
return V_74 ;
}
int F_153 ( struct V_26 * V_26 , T_1 V_15 , struct V_129 * V_129 ,
unsigned int V_173 )
{
T_1 V_50 ;
T_1 V_205 ;
struct V_166 * V_206 ;
struct V_32 * V_175 = F_125 ( V_26 ) -> V_54 -> V_175 ;
struct V_1 * V_2 ;
int V_207 ;
int V_74 ;
V_50 = 0 ;
V_74 = F_130 ( & F_125 ( V_26 ) -> V_169 , & V_50 ,
( T_1 ) - 1 , 1 , V_92 , 0 ) ;
if ( ! V_74 )
return 0 ;
V_74 = F_134 ( & F_125 ( V_26 ) -> V_169 , V_15 ,
& V_205 ) ;
if ( V_74 )
return 0 ;
V_206 = (struct V_166 * ) ( unsigned long ) V_205 ;
F_72 ( ! V_206 -> V_208 ) ;
if ( V_206 -> V_209 ) {
F_154 ( L_14 ,
V_206 -> V_15 ) ;
goto V_107;
}
if ( V_175 -> V_185 -> V_186 & V_187 )
goto V_107;
F_70 ( & F_125 ( V_26 ) -> V_152 . V_48 ) ;
V_2 = F_112 ( & F_125 ( V_26 ) -> V_152 ,
V_206 -> V_15 ,
V_120 ) ;
F_74 ( & F_125 ( V_26 ) -> V_152 . V_48 ) ;
if ( V_2 && V_2 -> V_15 <= V_206 -> V_15 &&
V_2 -> V_16 >= V_206 -> V_15 + V_206 -> V_21 - 1 ) {
V_207 = F_155 ( V_175 , V_206 -> V_172 ,
V_206 -> V_21 ) ;
if ( V_207 > 1 ) {
F_140 ( V_26 , V_15 , V_206 -> V_21 ,
V_206 -> V_172 , V_129 ,
V_173 , V_206 -> V_210 ) ;
}
}
V_107:
F_138 ( V_26 , V_206 ) ;
return 0 ;
}
void F_156 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_16 )
{
struct V_24 * V_168 = & F_125 ( V_26 ) -> V_169 ;
struct V_166 * V_206 ;
struct V_1 * V_2 , * V_13 ;
if ( F_157 ( & V_168 -> V_2 ) )
return;
F_70 ( & V_168 -> V_48 ) ;
V_2 = F_112 ( V_168 , V_15 , V_92 ) ;
while ( V_2 ) {
if ( V_2 -> V_15 > V_16 )
break;
ASSERT ( V_2 -> V_16 <= V_16 ) ;
V_13 = F_62 ( V_2 ) ;
V_206 = (struct V_166 * ) ( unsigned long ) V_2 -> V_50 ;
F_39 ( V_2 ) ;
F_139 ( V_206 ) ;
V_2 = V_13 ;
}
F_74 ( & V_168 -> V_48 ) ;
}
int F_158 ( struct V_26 * V_26 , T_1 V_15 , T_1 V_16 ,
struct V_166 * * V_211 )
{
struct V_166 * V_206 ;
T_1 V_50 ;
struct V_212 * V_213 ;
struct V_24 * V_168 = & F_125 ( V_26 ) -> V_169 ;
struct V_24 * V_25 = & F_125 ( V_26 ) -> V_152 ;
struct V_214 * V_215 = & F_125 ( V_26 ) -> V_216 ;
int V_74 ;
T_1 V_172 ;
V_74 = F_134 ( V_168 , V_15 , & V_50 ) ;
if ( V_74 ) {
V_206 = F_159 ( sizeof( * V_206 ) , V_125 ) ;
if ( ! V_206 )
return - V_36 ;
V_206 -> V_15 = V_15 ;
V_206 -> V_21 = V_16 - V_15 + 1 ;
V_206 -> V_208 = 0 ;
V_206 -> V_217 = 0 ;
V_206 -> V_209 = 0 ;
F_160 ( & V_215 -> V_48 ) ;
V_213 = F_161 ( V_215 , V_15 , V_206 -> V_21 ) ;
if ( ! V_213 ) {
F_162 ( & V_215 -> V_48 ) ;
F_139 ( V_206 ) ;
return - V_154 ;
}
if ( V_213 -> V_15 > V_15 || V_213 -> V_15 + V_213 -> V_21 <= V_15 ) {
F_163 ( V_213 ) ;
V_213 = NULL ;
}
F_162 ( & V_215 -> V_48 ) ;
if ( ! V_213 ) {
F_139 ( V_206 ) ;
return - V_154 ;
}
V_172 = V_15 - V_213 -> V_15 ;
V_172 = V_213 -> V_218 + V_172 ;
if ( F_164 ( V_219 , & V_213 -> V_7 ) ) {
V_172 = V_213 -> V_218 ;
V_206 -> V_217 = V_220 ;
F_165 ( & V_206 -> V_217 ,
V_213 -> V_221 ) ;
}
F_154 ( L_15 ,
V_172 , V_15 , V_206 -> V_21 ) ;
V_206 -> V_172 = V_172 ;
F_163 ( V_213 ) ;
V_74 = F_90 ( V_168 , V_15 , V_16 ,
V_120 | V_92 , V_125 ) ;
if ( V_74 >= 0 )
V_74 = F_133 ( V_168 , V_15 ,
( T_1 ) ( unsigned long ) V_206 ) ;
if ( V_74 >= 0 )
V_74 = F_90 ( V_25 , V_15 , V_16 , V_170 ,
V_125 ) ;
if ( V_74 < 0 ) {
F_139 ( V_206 ) ;
return V_74 ;
}
} else {
V_206 = (struct V_166 * ) ( unsigned long ) V_50 ;
F_154 ( L_16 ,
V_206 -> V_172 , V_206 -> V_15 , V_206 -> V_21 ,
V_206 -> V_209 ) ;
}
* V_211 = V_206 ;
return 0 ;
}
int F_166 ( struct V_26 * V_26 , struct V_41 * V_222 ,
struct V_166 * V_206 , int V_210 )
{
int V_207 ;
V_207 = F_155 ( F_125 ( V_26 ) -> V_54 -> V_175 ,
V_206 -> V_172 , V_206 -> V_21 ) ;
if ( V_207 == 1 ) {
F_154 ( L_17 ,
V_207 , V_206 -> V_208 , V_210 ) ;
return 0 ;
}
if ( V_222 -> V_223 > 1 ) {
F_72 ( V_206 -> V_209 ) ;
V_206 -> V_209 = 1 ;
V_206 -> V_208 = V_210 ;
} else {
if ( V_206 -> V_209 ) {
F_72 ( V_206 -> V_208 != V_210 ) ;
V_206 -> V_209 = 0 ;
V_206 -> V_208 = 0 ;
}
V_206 -> V_210 = V_210 ;
V_206 -> V_208 ++ ;
if ( V_206 -> V_208 == V_210 )
V_206 -> V_208 ++ ;
}
if ( V_206 -> V_208 > V_207 ) {
F_154 ( L_18 ,
V_207 , V_206 -> V_208 , V_210 ) ;
return 0 ;
}
return 1 ;
}
struct V_41 * F_167 ( struct V_26 * V_26 , struct V_41 * V_222 ,
struct V_166 * V_206 ,
struct V_129 * V_129 , int V_173 , int V_224 ,
T_6 * V_225 , void * V_226 )
{
struct V_41 * V_41 ;
struct V_40 * V_227 ;
struct V_40 * V_180 ;
V_41 = F_142 ( V_125 , 1 ) ;
if ( ! V_41 )
return NULL ;
V_41 -> V_228 = V_225 ;
V_41 -> V_188 . V_193 = V_206 -> V_172 >> 9 ;
V_41 -> V_196 = F_125 ( V_26 ) -> V_54 -> V_175 -> V_229 -> V_230 ;
V_41 -> V_188 . V_189 = 0 ;
V_41 -> V_231 = V_226 ;
V_227 = V_40 ( V_222 ) ;
if ( V_227 -> V_232 ) {
struct V_32 * V_175 = F_125 ( V_26 ) -> V_54 -> V_175 ;
T_7 V_233 = F_168 ( V_175 -> V_234 ) ;
V_180 = V_40 ( V_41 ) ;
V_180 -> V_232 = V_180 -> V_235 ;
V_224 *= V_233 ;
memcpy ( V_180 -> V_232 , V_227 -> V_232 + V_224 ,
V_233 ) ;
}
F_146 ( V_41 , V_129 , V_206 -> V_21 , V_173 ) ;
return V_41 ;
}
static int F_169 ( struct V_41 * V_222 , T_1 V_236 ,
struct V_129 * V_129 , T_1 V_15 , T_1 V_16 ,
int V_210 )
{
struct V_166 * V_206 ;
struct V_26 * V_26 = V_129 -> V_28 -> V_29 ;
struct V_24 * V_25 = & F_125 ( V_26 ) -> V_152 ;
struct V_41 * V_41 ;
int V_237 ;
int V_74 ;
F_72 ( V_222 -> V_238 & V_239 ) ;
V_74 = F_158 ( V_26 , V_15 , V_16 , & V_206 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_166 ( V_26 , V_222 , V_206 , V_210 ) ;
if ( ! V_74 ) {
F_138 ( V_26 , V_206 ) ;
return - V_154 ;
}
if ( V_222 -> V_223 > 1 )
V_237 = V_240 | V_241 ;
else
V_237 = V_240 ;
V_236 >>= V_26 -> V_33 -> V_242 ;
V_41 = F_167 ( V_26 , V_222 , V_206 , V_129 ,
V_15 - F_136 ( V_129 ) ,
( int ) V_236 , V_222 -> V_228 ,
NULL ) ;
if ( ! V_41 ) {
F_138 ( V_26 , V_206 ) ;
return - V_154 ;
}
F_154 ( L_19 ,
V_237 , V_206 -> V_208 , V_206 -> V_209 ) ;
V_74 = V_25 -> V_46 -> V_243 ( V_26 , V_237 , V_41 ,
V_206 -> V_208 ,
V_206 -> V_217 , 0 ) ;
if ( V_74 ) {
F_138 ( V_26 , V_206 ) ;
F_144 ( V_41 ) ;
}
return V_74 ;
}
int F_170 ( struct V_129 * V_129 , int V_95 , T_1 V_15 , T_1 V_16 )
{
int V_244 = ( V_95 == 0 ) ;
struct V_24 * V_25 ;
int V_74 = 0 ;
V_25 = & F_125 ( V_129 -> V_28 -> V_29 ) -> V_152 ;
if ( V_25 -> V_46 && V_25 -> V_46 -> V_245 ) {
V_74 = V_25 -> V_46 -> V_245 ( V_129 , V_15 ,
V_16 , NULL , V_244 ) ;
if ( V_74 )
V_244 = 0 ;
}
if ( ! V_244 ) {
F_171 ( V_129 ) ;
F_128 ( V_129 ) ;
V_74 = V_74 < 0 ? V_74 : - V_154 ;
F_126 ( V_129 -> V_28 , V_74 ) ;
}
return 0 ;
}
static void F_172 ( struct V_41 * V_41 , int V_95 )
{
struct V_246 * V_247 ;
T_1 V_15 ;
T_1 V_16 ;
int V_140 ;
F_173 (bvec, bio, i) {
struct V_129 * V_129 = V_247 -> V_248 ;
if ( V_247 -> V_249 || V_247 -> V_250 != V_149 ) {
if ( V_247 -> V_249 + V_247 -> V_250 != V_149 )
F_174 ( F_125 ( V_129 -> V_28 -> V_29 ) -> V_54 -> V_175 ,
L_20 ,
V_247 -> V_249 , V_247 -> V_250 ) ;
else
F_175 ( F_125 ( V_129 -> V_28 -> V_29 ) -> V_54 -> V_175 ,
L_21
L_22 ,
V_247 -> V_249 , V_247 -> V_250 ) ;
}
V_15 = F_136 ( V_129 ) ;
V_16 = V_15 + V_247 -> V_249 + V_247 -> V_250 - 1 ;
if ( F_170 ( V_129 , V_95 , V_15 , V_16 ) )
continue;
F_129 ( V_129 ) ;
}
F_144 ( V_41 ) ;
}
static void
F_176 ( struct V_24 * V_25 , T_1 V_15 , T_1 V_21 ,
int V_244 )
{
struct V_1 * V_98 = NULL ;
T_1 V_16 = V_15 + V_21 - 1 ;
if ( V_244 && V_25 -> V_251 )
F_96 ( V_25 , V_15 , V_16 , & V_98 , V_94 ) ;
F_101 ( V_25 , V_15 , V_16 , & V_98 , V_94 ) ;
}
static void F_177 ( struct V_41 * V_41 , int V_95 )
{
struct V_246 * V_247 ;
int V_244 = F_164 ( V_252 , & V_41 -> V_253 ) ;
struct V_40 * V_254 = V_40 ( V_41 ) ;
struct V_24 * V_25 ;
T_1 V_56 = 0 ;
T_1 V_15 ;
T_1 V_16 ;
T_1 V_21 ;
T_1 V_255 = 0 ;
T_1 V_256 = 0 ;
int V_257 ;
int V_74 ;
int V_140 ;
if ( V_95 )
V_244 = 0 ;
F_173 (bvec, bio, i) {
struct V_129 * V_129 = V_247 -> V_248 ;
struct V_26 * V_26 = V_129 -> V_28 -> V_29 ;
F_154 ( L_23
L_24 , ( T_1 ) V_41 -> V_188 . V_193 , V_95 ,
V_254 -> V_174 ) ;
V_25 = & F_125 ( V_26 ) -> V_152 ;
if ( V_247 -> V_249 || V_247 -> V_250 != V_149 ) {
if ( V_247 -> V_249 + V_247 -> V_250 != V_149 )
F_174 ( F_125 ( V_129 -> V_28 -> V_29 ) -> V_54 -> V_175 ,
L_25 ,
V_247 -> V_249 , V_247 -> V_250 ) ;
else
F_175 ( F_125 ( V_129 -> V_28 -> V_29 ) -> V_54 -> V_175 ,
L_26
L_22 ,
V_247 -> V_249 , V_247 -> V_250 ) ;
}
V_15 = F_136 ( V_129 ) ;
V_16 = V_15 + V_247 -> V_249 + V_247 -> V_250 - 1 ;
V_21 = V_247 -> V_250 ;
V_257 = V_254 -> V_174 ;
if ( F_178 ( V_244 && V_25 -> V_46 &&
V_25 -> V_46 -> V_258 ) ) {
V_74 = V_25 -> V_46 -> V_258 ( V_254 , V_56 ,
V_129 , V_15 , V_16 ,
V_257 ) ;
if ( V_74 )
V_244 = 0 ;
else
F_153 ( V_26 , V_15 , V_129 , 0 ) ;
}
if ( F_178 ( V_244 ) )
goto V_259;
if ( V_25 -> V_46 && V_25 -> V_46 -> V_260 ) {
V_74 = V_25 -> V_46 -> V_260 ( V_129 , V_257 ) ;
if ( ! V_74 && ! V_95 &&
F_164 ( V_252 , & V_41 -> V_253 ) )
V_244 = 1 ;
} else {
V_74 = F_169 ( V_41 , V_56 , V_129 , V_15 , V_16 ,
V_257 ) ;
if ( V_74 == 0 ) {
V_244 =
F_164 ( V_252 , & V_41 -> V_253 ) ;
if ( V_95 )
V_244 = 0 ;
V_56 += V_21 ;
continue;
}
}
V_259:
if ( F_178 ( V_244 ) ) {
T_8 V_261 = F_17 ( V_26 ) ;
T_9 V_128 = V_261 >> V_127 ;
unsigned V_262 ;
V_262 = V_261 & ( V_149 - 1 ) ;
if ( V_129 -> V_126 == V_128 && V_262 )
F_179 ( V_129 , V_262 , V_149 ) ;
F_137 ( V_129 ) ;
} else {
F_171 ( V_129 ) ;
F_128 ( V_129 ) ;
}
F_118 ( V_129 ) ;
V_56 += V_21 ;
if ( F_180 ( ! V_244 ) ) {
if ( V_256 ) {
F_176 ( V_25 ,
V_255 ,
V_256 , 1 ) ;
V_255 = 0 ;
V_256 = 0 ;
}
F_176 ( V_25 , V_15 ,
V_16 - V_15 + 1 , 0 ) ;
} else if ( ! V_256 ) {
V_255 = V_15 ;
V_256 = V_16 + 1 - V_15 ;
} else if ( V_255 + V_256 == V_15 ) {
V_256 += V_16 + 1 - V_15 ;
} else {
F_176 ( V_25 , V_255 ,
V_256 , V_244 ) ;
V_255 = V_15 ;
V_256 = V_16 + 1 - V_15 ;
}
}
if ( V_256 )
F_176 ( V_25 , V_255 , V_256 ,
V_244 ) ;
if ( V_254 -> V_263 )
V_254 -> V_263 ( V_254 , V_95 ) ;
F_144 ( V_41 ) ;
}
struct V_41 *
F_181 ( struct V_264 * V_194 , T_1 V_265 , int V_266 ,
T_3 V_267 )
{
struct V_40 * V_180 ;
struct V_41 * V_41 ;
V_41 = F_182 ( V_267 , V_266 , V_38 ) ;
if ( V_41 == NULL && ( V_268 -> V_7 & V_269 ) ) {
while ( ! V_41 && ( V_266 /= 2 ) ) {
V_41 = F_182 ( V_267 ,
V_266 , V_38 ) ;
}
}
if ( V_41 ) {
V_41 -> V_196 = V_194 ;
V_41 -> V_188 . V_193 = V_265 ;
V_180 = V_40 ( V_41 ) ;
V_180 -> V_232 = NULL ;
V_180 -> V_270 = NULL ;
V_180 -> V_263 = NULL ;
}
return V_41 ;
}
struct V_41 * F_183 ( struct V_41 * V_41 , T_3 V_271 )
{
struct V_40 * V_180 ;
struct V_41 * V_5 ;
V_5 = F_184 ( V_41 , V_271 , V_38 ) ;
if ( V_5 ) {
V_180 = V_40 ( V_5 ) ;
V_180 -> V_232 = NULL ;
V_180 -> V_270 = NULL ;
V_180 -> V_263 = NULL ;
}
return V_5 ;
}
struct V_41 * F_142 ( T_3 V_271 , unsigned int V_272 )
{
struct V_40 * V_180 ;
struct V_41 * V_41 ;
V_41 = F_182 ( V_271 , V_272 , V_38 ) ;
if ( V_41 ) {
V_180 = V_40 ( V_41 ) ;
V_180 -> V_232 = NULL ;
V_180 -> V_270 = NULL ;
V_180 -> V_263 = NULL ;
}
return V_41 ;
}
static int T_4 F_185 ( int V_273 , struct V_41 * V_41 ,
int V_174 , unsigned long V_217 )
{
int V_74 = 0 ;
struct V_246 * V_247 = V_41 -> V_274 + V_41 -> V_223 - 1 ;
struct V_129 * V_129 = V_247 -> V_248 ;
struct V_24 * V_25 = V_41 -> V_231 ;
T_1 V_15 ;
V_15 = F_136 ( V_129 ) + V_247 -> V_249 ;
V_41 -> V_231 = NULL ;
F_186 ( V_41 ) ;
if ( V_25 -> V_46 && V_25 -> V_46 -> V_243 )
V_74 = V_25 -> V_46 -> V_243 ( V_129 -> V_28 -> V_29 , V_273 , V_41 ,
V_174 , V_217 , V_15 ) ;
else
F_187 ( V_273 , V_41 ) ;
F_144 ( V_41 ) ;
return V_74 ;
}
static int F_188 ( int V_273 , struct V_24 * V_25 , struct V_129 * V_129 ,
unsigned long V_56 , T_10 V_275 , struct V_41 * V_41 ,
unsigned long V_217 )
{
int V_74 = 0 ;
if ( V_25 -> V_46 && V_25 -> V_46 -> V_276 )
V_74 = V_25 -> V_46 -> V_276 ( V_273 , V_129 , V_56 , V_275 , V_41 ,
V_217 ) ;
F_72 ( V_74 < 0 ) ;
return V_74 ;
}
static int F_189 ( int V_273 , struct V_24 * V_25 ,
struct V_129 * V_129 , T_11 V_179 ,
T_10 V_275 , unsigned long V_56 ,
struct V_264 * V_194 ,
struct V_41 * * V_277 ,
unsigned long V_278 ,
T_6 V_279 ,
int V_174 ,
unsigned long V_280 ,
unsigned long V_217 )
{
int V_74 = 0 ;
struct V_41 * V_41 ;
int V_281 ;
int V_161 = 0 ;
int V_282 = V_217 & V_220 ;
int V_283 = V_280 & V_220 ;
T_10 V_284 = F_117 ( T_10 , V_275 , V_149 ) ;
if ( V_277 && * V_277 ) {
V_41 = * V_277 ;
if ( V_283 )
V_161 = V_41 -> V_188 . V_193 == V_179 ;
else
V_161 = F_190 ( V_41 ) == V_179 ;
if ( V_280 != V_217 || ! V_161 ||
F_188 ( V_273 , V_25 , V_129 , V_56 , V_284 , V_41 , V_217 ) ||
F_146 ( V_41 , V_129 , V_284 , V_56 ) < V_284 ) {
V_74 = F_185 ( V_273 , V_41 , V_174 ,
V_280 ) ;
if ( V_74 < 0 ) {
* V_277 = NULL ;
return V_74 ;
}
V_41 = NULL ;
} else {
return 0 ;
}
}
if ( V_282 )
V_281 = V_285 ;
else
V_281 = F_191 ( V_194 ) ;
V_41 = F_181 ( V_194 , V_179 , V_281 , V_125 | V_286 ) ;
if ( ! V_41 )
return - V_36 ;
F_146 ( V_41 , V_129 , V_284 , V_56 ) ;
V_41 -> V_228 = V_279 ;
V_41 -> V_231 = V_25 ;
if ( V_277 )
* V_277 = V_41 ;
else
V_74 = F_185 ( V_273 , V_41 , V_174 , V_217 ) ;
return V_74 ;
}
static void F_192 ( struct V_10 * V_11 ,
struct V_129 * V_129 )
{
if ( ! F_193 ( V_129 ) ) {
F_194 ( V_129 ) ;
F_195 ( V_129 ) ;
F_196 ( V_129 , ( unsigned long ) V_11 ) ;
} else {
F_41 ( V_129 -> V_50 != ( unsigned long ) V_11 ) ;
}
}
void F_197 ( struct V_129 * V_129 )
{
if ( ! F_193 ( V_129 ) ) {
F_194 ( V_129 ) ;
F_195 ( V_129 ) ;
F_196 ( V_129 , V_287 ) ;
}
}
static struct V_212 *
F_198 ( struct V_26 * V_26 , struct V_129 * V_129 , T_10 V_173 ,
T_1 V_15 , T_1 V_21 , T_12 * V_288 ,
struct V_212 * * V_289 )
{
struct V_212 * V_213 ;
if ( V_289 && * V_289 ) {
V_213 = * V_289 ;
if ( F_199 ( V_213 ) && V_15 >= V_213 -> V_15 &&
V_15 < F_200 ( V_213 ) ) {
F_82 ( & V_213 -> V_17 ) ;
return V_213 ;
}
F_163 ( V_213 ) ;
* V_289 = NULL ;
}
V_213 = V_288 ( V_26 , V_129 , V_173 , V_15 , V_21 , 0 ) ;
if ( V_289 && ! F_201 ( V_213 ) ) {
F_72 ( * V_289 ) ;
F_82 ( & V_213 -> V_17 ) ;
* V_289 = V_213 ;
}
return V_213 ;
}
static int F_202 ( struct V_24 * V_25 ,
struct V_129 * V_129 ,
T_12 * V_288 ,
struct V_212 * * V_289 ,
struct V_41 * * V_41 , int V_174 ,
unsigned long * V_217 , int V_273 )
{
struct V_26 * V_26 = V_129 -> V_28 -> V_29 ;
T_1 V_15 = F_136 ( V_129 ) ;
T_1 V_290 = V_15 + V_149 - 1 ;
T_1 V_16 ;
T_1 V_291 = V_15 ;
T_1 V_292 ;
T_1 V_293 = F_17 ( V_26 ) ;
T_1 V_218 ;
T_1 V_294 ;
T_11 V_179 ;
struct V_212 * V_213 ;
struct V_264 * V_194 ;
int V_74 ;
int V_281 = 0 ;
int V_295 = * V_217 & V_296 ;
T_10 V_173 = 0 ;
T_10 V_297 ;
T_10 V_298 ;
T_10 V_299 = V_26 -> V_33 -> V_300 ;
unsigned long V_301 = * V_217 & V_296 ;
F_197 ( V_129 ) ;
V_16 = V_290 ;
if ( ! F_203 ( V_129 ) ) {
if ( F_204 ( V_129 ) == 0 ) {
F_72 ( V_299 != V_30 ) ;
F_102 ( V_25 , V_15 , V_16 ) ;
goto V_107;
}
}
if ( V_129 -> V_126 == V_293 >> V_127 ) {
char * V_302 ;
T_10 V_303 = V_293 & ( V_149 - 1 ) ;
if ( V_303 ) {
V_297 = V_149 - V_303 ;
V_302 = F_205 ( V_129 ) ;
memset ( V_302 + V_303 , 0 , V_297 ) ;
F_206 ( V_129 ) ;
F_207 ( V_302 ) ;
}
}
while ( V_291 <= V_16 ) {
unsigned long V_304 = ( V_293 >> V_127 ) + 1 ;
if ( V_291 >= V_293 ) {
char * V_302 ;
struct V_1 * V_98 = NULL ;
V_297 = V_149 - V_173 ;
V_302 = F_205 ( V_129 ) ;
memset ( V_302 + V_173 , 0 , V_297 ) ;
F_206 ( V_129 ) ;
F_207 ( V_302 ) ;
F_96 ( V_25 , V_291 , V_291 + V_297 - 1 ,
& V_98 , V_125 ) ;
if ( ! V_295 )
F_101 ( V_25 , V_291 ,
V_291 + V_297 - 1 ,
& V_98 , V_125 ) ;
break;
}
V_213 = F_198 ( V_26 , V_129 , V_173 , V_291 ,
V_16 - V_291 + 1 , V_288 , V_289 ) ;
if ( F_201 ( V_213 ) ) {
F_128 ( V_129 ) ;
if ( ! V_295 )
F_102 ( V_25 , V_291 , V_16 ) ;
break;
}
V_292 = V_291 - V_213 -> V_15 ;
F_72 ( F_200 ( V_213 ) <= V_291 ) ;
F_72 ( V_16 < V_291 ) ;
if ( F_164 ( V_219 , & V_213 -> V_7 ) ) {
V_301 |= V_220 ;
F_165 ( & V_301 ,
V_213 -> V_221 ) ;
}
V_297 = F_131 ( F_200 ( V_213 ) - V_291 , V_16 - V_291 + 1 ) ;
V_294 = F_131 ( F_200 ( V_213 ) - 1 , V_16 ) ;
V_297 = F_208 ( V_297 , V_299 ) ;
if ( V_301 & V_220 ) {
V_298 = V_213 -> V_305 ;
V_179 = V_213 -> V_218 >> 9 ;
} else {
V_179 = ( V_213 -> V_218 + V_292 ) >> 9 ;
V_298 = V_297 ;
}
V_194 = V_213 -> V_194 ;
V_218 = V_213 -> V_218 ;
if ( F_164 ( V_306 , & V_213 -> V_7 ) )
V_218 = V_307 ;
F_163 ( V_213 ) ;
V_213 = NULL ;
if ( V_218 == V_307 ) {
char * V_302 ;
struct V_1 * V_98 = NULL ;
V_302 = F_205 ( V_129 ) ;
memset ( V_302 + V_173 , 0 , V_297 ) ;
F_206 ( V_129 ) ;
F_207 ( V_302 ) ;
F_96 ( V_25 , V_291 , V_291 + V_297 - 1 ,
& V_98 , V_125 ) ;
F_101 ( V_25 , V_291 , V_291 + V_297 - 1 ,
& V_98 , V_125 ) ;
V_291 = V_291 + V_297 ;
V_173 += V_297 ;
continue;
}
if ( F_123 ( V_25 , V_291 , V_294 ,
V_121 , 1 , NULL ) ) {
F_135 ( V_25 , V_129 ) ;
if ( ! V_295 )
F_102 ( V_25 , V_291 , V_291 + V_297 - 1 ) ;
V_291 = V_291 + V_297 ;
V_173 += V_297 ;
continue;
}
if ( V_218 == V_308 ) {
F_128 ( V_129 ) ;
if ( ! V_295 )
F_102 ( V_25 , V_291 , V_291 + V_297 - 1 ) ;
V_291 = V_291 + V_297 ;
V_173 += V_297 ;
continue;
}
V_304 -= V_129 -> V_126 ;
V_74 = F_189 ( V_273 , V_25 , V_129 ,
V_179 , V_298 , V_173 ,
V_194 , V_41 , V_304 ,
F_177 , V_174 ,
* V_217 ,
V_301 ) ;
if ( ! V_74 ) {
V_281 ++ ;
* V_217 = V_301 ;
} else {
F_128 ( V_129 ) ;
if ( ! V_295 )
F_102 ( V_25 , V_291 , V_291 + V_297 - 1 ) ;
}
V_291 = V_291 + V_297 ;
V_173 += V_297 ;
}
V_107:
if ( ! V_281 ) {
if ( ! F_209 ( V_129 ) )
F_137 ( V_129 ) ;
F_118 ( V_129 ) ;
}
return 0 ;
}
static inline void F_210 ( struct V_24 * V_25 ,
struct V_129 * V_138 [] , int V_139 ,
T_1 V_15 , T_1 V_16 ,
T_12 * V_288 ,
struct V_212 * * V_289 ,
struct V_41 * * V_41 , int V_174 ,
unsigned long * V_217 , int V_273 )
{
struct V_26 * V_26 ;
struct V_309 * V_310 ;
int V_126 ;
V_26 = V_138 [ 0 ] -> V_28 -> V_29 ;
while ( 1 ) {
F_99 ( V_25 , V_15 , V_16 ) ;
V_310 = F_211 ( V_26 , V_15 ,
V_16 - V_15 + 1 ) ;
if ( ! V_310 )
break;
F_102 ( V_25 , V_15 , V_16 ) ;
F_212 ( V_26 , V_310 , 1 ) ;
F_213 ( V_310 ) ;
}
for ( V_126 = 0 ; V_126 < V_139 ; V_126 ++ ) {
F_202 ( V_25 , V_138 [ V_126 ] , V_288 , V_289 , V_41 ,
V_174 , V_217 , V_273 ) ;
F_106 ( V_138 [ V_126 ] ) ;
}
}
static void F_214 ( struct V_24 * V_25 ,
struct V_129 * V_138 [] ,
int V_139 , T_12 * V_288 ,
struct V_212 * * V_289 ,
struct V_41 * * V_41 , int V_174 ,
unsigned long * V_217 , int V_273 )
{
T_1 V_15 = 0 ;
T_1 V_16 = 0 ;
T_1 V_311 ;
int V_126 ;
int V_312 = 0 ;
for ( V_126 = 0 ; V_126 < V_139 ; V_126 ++ ) {
V_311 = F_136 ( V_138 [ V_126 ] ) ;
if ( ! V_16 ) {
V_15 = V_311 ;
V_16 = V_15 + V_149 - 1 ;
V_312 = V_126 ;
} else if ( V_16 + 1 == V_311 ) {
V_16 += V_149 ;
} else {
F_210 ( V_25 , & V_138 [ V_312 ] ,
V_126 - V_312 , V_15 ,
V_16 , V_288 , V_289 ,
V_41 , V_174 , V_217 ,
V_273 ) ;
V_15 = V_311 ;
V_16 = V_15 + V_149 - 1 ;
V_312 = V_126 ;
}
}
if ( V_16 )
F_210 ( V_25 , & V_138 [ V_312 ] ,
V_126 - V_312 , V_15 ,
V_16 , V_288 , V_289 , V_41 ,
V_174 , V_217 , V_273 ) ;
}
static int F_215 ( struct V_24 * V_25 ,
struct V_129 * V_129 ,
T_12 * V_288 ,
struct V_41 * * V_41 , int V_174 ,
unsigned long * V_217 , int V_273 )
{
struct V_26 * V_26 = V_129 -> V_28 -> V_29 ;
struct V_309 * V_310 ;
T_1 V_15 = F_136 ( V_129 ) ;
T_1 V_16 = V_15 + V_149 - 1 ;
int V_74 ;
while ( 1 ) {
F_99 ( V_25 , V_15 , V_16 ) ;
V_310 = F_216 ( V_26 , V_15 ) ;
if ( ! V_310 )
break;
F_102 ( V_25 , V_15 , V_16 ) ;
F_212 ( V_26 , V_310 , 1 ) ;
F_213 ( V_310 ) ;
}
V_74 = F_202 ( V_25 , V_129 , V_288 , NULL , V_41 , V_174 ,
V_217 , V_273 ) ;
return V_74 ;
}
int F_217 ( struct V_24 * V_25 , struct V_129 * V_129 ,
T_12 * V_288 , int V_174 )
{
struct V_41 * V_41 = NULL ;
unsigned long V_217 = 0 ;
int V_74 ;
V_74 = F_215 ( V_25 , V_129 , V_288 , & V_41 , V_174 ,
& V_217 , V_313 ) ;
if ( V_41 )
V_74 = F_185 ( V_313 , V_41 , V_174 , V_217 ) ;
return V_74 ;
}
int F_218 ( struct V_24 * V_25 , struct V_129 * V_129 ,
T_12 * V_288 , int V_174 )
{
struct V_41 * V_41 = NULL ;
unsigned long V_217 = V_296 ;
int V_74 ;
V_74 = F_202 ( V_25 , V_129 , V_288 , NULL , & V_41 , V_174 ,
& V_217 , V_313 ) ;
if ( V_41 )
V_74 = F_185 ( V_313 , V_41 , V_174 , V_217 ) ;
return V_74 ;
}
static T_5 void F_219 ( struct V_129 * V_129 ,
struct V_314 * V_315 ,
unsigned long V_316 )
{
V_315 -> V_317 -= V_316 ;
if ( V_315 -> V_318 || ( V_315 -> V_317 > 0 &&
V_315 -> V_319 == 0 && V_315 -> V_320 == V_321 ) )
V_129 -> V_28 -> V_322 = V_129 -> V_126 + V_316 ;
}
static T_13 int F_220 ( struct V_26 * V_26 ,
struct V_129 * V_129 , struct V_314 * V_315 ,
struct V_323 * V_324 ,
T_1 V_141 ,
unsigned long * V_316 )
{
struct V_24 * V_25 = V_324 -> V_25 ;
T_1 V_290 = V_141 + V_149 - 1 ;
T_1 V_325 ;
T_1 V_326 = 0 ;
T_1 V_142 = 0 ;
int V_74 ;
int V_327 = 0 ;
if ( V_324 -> V_328 || ! V_25 -> V_46 || ! V_25 -> V_46 -> V_329 )
return 0 ;
while ( V_142 < V_290 ) {
V_325 = F_122 ( V_26 , V_25 ,
V_129 ,
& V_141 ,
& V_142 ,
V_330 ) ;
if ( V_325 == 0 ) {
V_141 = V_142 + 1 ;
continue;
}
V_74 = V_25 -> V_46 -> V_329 ( V_26 , V_129 ,
V_141 ,
V_142 ,
& V_327 ,
V_316 ) ;
if ( V_74 ) {
F_128 ( V_129 ) ;
V_74 = V_74 < 0 ? V_74 : - V_154 ;
goto V_147;
}
V_326 += ( V_142 - V_141 +
V_149 ) >>
V_127 ;
V_141 = V_142 + 1 ;
}
if ( V_315 -> V_317 < V_326 ) {
int V_331 = 8192 ;
if ( V_326 < V_331 * 2 )
V_331 = V_326 ;
V_315 -> V_317 = F_117 ( T_1 , V_326 ,
V_331 ) ;
}
if ( V_327 ) {
V_315 -> V_317 -= * V_316 ;
return 1 ;
}
V_74 = 0 ;
V_147:
return V_74 ;
}
static T_13 int F_221 ( struct V_26 * V_26 ,
struct V_129 * V_129 ,
struct V_314 * V_315 ,
struct V_323 * V_324 ,
T_8 V_261 ,
unsigned long V_316 ,
int V_332 , int * V_333 )
{
struct V_24 * V_25 = V_324 -> V_25 ;
T_1 V_15 = F_136 ( V_129 ) ;
T_1 V_290 = V_15 + V_149 - 1 ;
T_1 V_16 ;
T_1 V_291 = V_15 ;
T_1 V_292 ;
T_1 V_218 ;
T_1 V_297 ;
T_11 V_179 ;
struct V_1 * V_97 = NULL ;
struct V_212 * V_213 ;
struct V_264 * V_194 ;
T_10 V_173 = 0 ;
T_10 V_299 ;
int V_74 = 0 ;
int V_281 = 0 ;
bool V_334 ;
if ( V_25 -> V_46 && V_25 -> V_46 -> V_335 ) {
V_74 = V_25 -> V_46 -> V_335 ( V_129 , V_15 ,
V_290 ) ;
if ( V_74 ) {
if ( V_74 == - V_336 )
V_315 -> V_337 ++ ;
else
F_222 ( V_315 , V_129 ) ;
F_219 ( V_129 , V_315 , V_316 ) ;
F_118 ( V_129 ) ;
V_74 = 1 ;
goto V_338;
}
}
F_219 ( V_129 , V_315 , V_316 + 1 ) ;
V_16 = V_290 ;
if ( V_261 <= V_15 ) {
if ( V_25 -> V_46 && V_25 -> V_46 -> V_245 )
V_25 -> V_46 -> V_245 ( V_129 , V_15 ,
V_290 , NULL , 1 ) ;
goto V_147;
}
V_299 = V_26 -> V_33 -> V_300 ;
while ( V_291 <= V_16 ) {
T_1 V_339 ;
if ( V_291 >= V_261 ) {
if ( V_25 -> V_46 && V_25 -> V_46 -> V_245 )
V_25 -> V_46 -> V_245 ( V_129 , V_291 ,
V_290 , NULL , 1 ) ;
break;
}
V_213 = V_324 -> V_288 ( V_26 , V_129 , V_173 , V_291 ,
V_16 - V_291 + 1 , 1 ) ;
if ( F_201 ( V_213 ) ) {
F_128 ( V_129 ) ;
V_74 = F_223 ( V_213 ) ;
break;
}
V_292 = V_291 - V_213 -> V_15 ;
V_339 = F_200 ( V_213 ) ;
F_72 ( V_339 <= V_291 ) ;
F_72 ( V_16 < V_291 ) ;
V_297 = F_131 ( V_339 - V_291 , V_16 - V_291 + 1 ) ;
V_297 = F_208 ( V_297 , V_299 ) ;
V_179 = ( V_213 -> V_218 + V_292 ) >> 9 ;
V_194 = V_213 -> V_194 ;
V_218 = V_213 -> V_218 ;
V_334 = F_164 ( V_219 , & V_213 -> V_7 ) ;
F_163 ( V_213 ) ;
V_213 = NULL ;
if ( V_334 || V_218 == V_307 ||
V_218 == V_308 ) {
if ( ! V_334 && V_25 -> V_46 &&
V_25 -> V_46 -> V_245 )
V_25 -> V_46 -> V_245 ( V_129 , V_291 ,
V_291 + V_297 - 1 ,
NULL , 1 ) ;
else if ( V_334 ) {
V_281 ++ ;
}
V_291 += V_297 ;
V_173 += V_297 ;
continue;
}
if ( V_25 -> V_46 && V_25 -> V_46 -> V_340 ) {
V_74 = V_25 -> V_46 -> V_340 ( V_129 , V_291 ,
V_291 + V_297 - 1 ) ;
} else {
V_74 = 0 ;
}
if ( V_74 ) {
F_128 ( V_129 ) ;
} else {
unsigned long V_341 = ( V_261 >> V_127 ) + 1 ;
F_110 ( V_25 , V_291 , V_291 + V_297 - 1 ) ;
if ( ! F_224 ( V_129 ) ) {
F_174 ( F_125 ( V_26 ) -> V_54 -> V_175 ,
L_27 ,
V_129 -> V_126 , V_291 , V_16 ) ;
}
V_74 = F_189 ( V_332 , V_25 , V_129 ,
V_179 , V_297 , V_173 ,
V_194 , & V_324 -> V_41 , V_341 ,
F_172 ,
0 , 0 , 0 ) ;
if ( V_74 )
F_128 ( V_129 ) ;
}
V_291 = V_291 + V_297 ;
V_173 += V_297 ;
V_281 ++ ;
}
V_147:
* V_333 = V_281 ;
V_338:
F_39 ( V_97 ) ;
return V_74 ;
}
static int F_225 ( struct V_129 * V_129 , struct V_314 * V_315 ,
void * V_226 )
{
struct V_26 * V_26 = V_129 -> V_28 -> V_29 ;
struct V_323 * V_324 = V_226 ;
T_1 V_15 = F_136 ( V_129 ) ;
T_1 V_290 = V_15 + V_149 - 1 ;
int V_74 ;
int V_281 = 0 ;
T_10 V_173 = 0 ;
T_8 V_261 = F_17 ( V_26 ) ;
unsigned long V_128 = V_261 >> V_127 ;
int V_332 ;
unsigned long V_316 = 0 ;
if ( V_315 -> V_342 == V_343 )
V_332 = V_197 ;
else
V_332 = V_190 ;
F_226 ( V_129 , V_26 , V_315 ) ;
F_41 ( ! F_227 ( V_129 ) ) ;
F_228 ( V_129 ) ;
V_173 = V_261 & ( V_149 - 1 ) ;
if ( V_129 -> V_126 > V_128 ||
( V_129 -> V_126 == V_128 && ! V_173 ) ) {
V_129 -> V_28 -> V_344 -> V_345 ( V_129 , 0 , V_149 ) ;
F_118 ( V_129 ) ;
return 0 ;
}
if ( V_129 -> V_126 == V_128 ) {
char * V_302 ;
V_302 = F_205 ( V_129 ) ;
memset ( V_302 + V_173 , 0 ,
V_149 - V_173 ) ;
F_207 ( V_302 ) ;
F_206 ( V_129 ) ;
}
V_173 = 0 ;
F_197 ( V_129 ) ;
V_74 = F_220 ( V_26 , V_129 , V_315 , V_324 , V_15 , & V_316 ) ;
if ( V_74 == 1 )
goto V_338;
if ( V_74 )
goto V_147;
V_74 = F_221 ( V_26 , V_129 , V_315 , V_324 ,
V_261 , V_316 , V_332 , & V_281 ) ;
if ( V_74 == 1 )
goto V_338;
V_147:
if ( V_281 == 0 ) {
F_111 ( V_129 ) ;
F_129 ( V_129 ) ;
}
if ( F_209 ( V_129 ) ) {
V_74 = V_74 < 0 ? V_74 : - V_154 ;
F_170 ( V_129 , V_74 , V_15 , V_290 ) ;
}
F_118 ( V_129 ) ;
return V_74 ;
V_338:
return 0 ;
}
void F_229 ( struct V_10 * V_11 )
{
F_230 ( & V_11 -> V_346 , V_347 ,
V_110 ) ;
}
static T_13 int
F_231 ( struct V_10 * V_11 ,
struct V_32 * V_175 ,
struct V_323 * V_324 )
{
unsigned long V_140 , V_202 ;
int V_348 = 0 ;
int V_74 = 0 ;
if ( ! F_232 ( V_11 ) ) {
V_348 = 1 ;
F_233 ( V_324 ) ;
F_234 ( V_11 ) ;
}
if ( F_164 ( V_347 , & V_11 -> V_346 ) ) {
F_235 ( V_11 ) ;
if ( ! V_324 -> V_349 )
return 0 ;
if ( ! V_348 ) {
F_233 ( V_324 ) ;
V_348 = 1 ;
}
while ( 1 ) {
F_229 ( V_11 ) ;
F_234 ( V_11 ) ;
if ( ! F_164 ( V_347 , & V_11 -> V_346 ) )
break;
F_235 ( V_11 ) ;
}
}
F_70 ( & V_11 -> V_350 ) ;
if ( F_236 ( V_351 , & V_11 -> V_346 ) ) {
F_237 ( V_347 , & V_11 -> V_346 ) ;
F_74 ( & V_11 -> V_350 ) ;
F_238 ( V_11 , V_352 ) ;
F_239 ( & V_175 -> V_353 ,
- V_11 -> V_21 ,
V_175 -> V_354 ) ;
V_74 = 1 ;
} else {
F_74 ( & V_11 -> V_350 ) ;
}
F_235 ( V_11 ) ;
if ( ! V_74 )
return V_74 ;
V_202 = F_152 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_140 = 0 ; V_140 < V_202 ; V_140 ++ ) {
struct V_129 * V_60 = V_11 -> V_138 [ V_140 ] ;
if ( ! F_240 ( V_60 ) ) {
if ( ! V_348 ) {
F_233 ( V_324 ) ;
V_348 = 1 ;
}
F_120 ( V_60 ) ;
}
}
return V_74 ;
}
static void F_241 ( struct V_10 * V_11 )
{
F_242 ( V_347 , & V_11 -> V_346 ) ;
F_243 () ;
F_244 ( & V_11 -> V_346 , V_347 ) ;
}
static void F_245 ( struct V_129 * V_129 )
{
struct V_10 * V_11 = (struct V_10 * ) V_129 -> V_50 ;
struct V_355 * V_356 = F_125 ( V_11 -> V_175 -> V_204 ) ;
F_128 ( V_129 ) ;
if ( F_246 ( V_357 , & V_11 -> V_346 ) )
return;
switch ( V_11 -> V_358 ) {
case - 1 :
F_237 ( V_359 , & V_356 -> V_360 ) ;
break;
case 0 :
F_237 ( V_361 , & V_356 -> V_360 ) ;
break;
case 1 :
F_237 ( V_362 , & V_356 -> V_360 ) ;
break;
default:
F_247 () ;
}
}
static void F_248 ( struct V_41 * V_41 , int V_95 )
{
struct V_246 * V_247 ;
struct V_10 * V_11 ;
int V_140 , V_147 ;
F_173 (bvec, bio, i) {
struct V_129 * V_129 = V_247 -> V_248 ;
V_11 = (struct V_10 * ) V_129 -> V_50 ;
F_72 ( ! V_11 ) ;
V_147 = F_40 ( & V_11 -> V_363 ) ;
if ( V_95 || F_164 ( V_357 , & V_11 -> V_346 ) ) {
F_171 ( V_129 ) ;
F_245 ( V_129 ) ;
}
F_129 ( V_129 ) ;
if ( ! V_147 )
continue;
F_241 ( V_11 ) ;
}
F_144 ( V_41 ) ;
}
static T_13 int F_249 ( struct V_10 * V_11 ,
struct V_32 * V_175 ,
struct V_314 * V_315 ,
struct V_323 * V_324 )
{
struct V_264 * V_194 = V_175 -> V_229 -> V_230 ;
struct V_24 * V_25 = & F_125 ( V_175 -> V_204 ) -> V_152 ;
T_1 V_56 = V_11 -> V_15 ;
unsigned long V_140 , V_202 ;
unsigned long V_217 = 0 ;
int V_273 = ( V_324 -> V_349 ? V_197 : V_190 ) | V_364 ;
int V_74 = 0 ;
F_242 ( V_357 , & V_11 -> V_346 ) ;
V_202 = F_152 ( V_11 -> V_15 , V_11 -> V_21 ) ;
F_36 ( & V_11 -> V_363 , V_202 ) ;
if ( F_250 ( V_11 ) == V_365 )
V_217 = V_366 ;
for ( V_140 = 0 ; V_140 < V_202 ; V_140 ++ ) {
struct V_129 * V_60 = V_11 -> V_138 [ V_140 ] ;
F_105 ( V_60 ) ;
F_111 ( V_60 ) ;
V_74 = F_189 ( V_273 , V_25 , V_60 , V_56 >> 9 ,
V_149 , 0 , V_194 , & V_324 -> V_41 ,
- 1 , F_248 ,
0 , V_324 -> V_217 , V_217 ) ;
V_324 -> V_217 = V_217 ;
if ( V_74 ) {
F_245 ( V_60 ) ;
F_129 ( V_60 ) ;
if ( F_251 ( V_202 - V_140 , & V_11 -> V_363 ) )
F_241 ( V_11 ) ;
V_74 = - V_154 ;
break;
}
V_56 += V_149 ;
F_219 ( V_60 , V_315 , 1 ) ;
F_118 ( V_60 ) ;
}
if ( F_180 ( V_74 ) ) {
for (; V_140 < V_202 ; V_140 ++ ) {
struct V_129 * V_60 = V_11 -> V_138 [ V_140 ] ;
F_105 ( V_60 ) ;
F_118 ( V_60 ) ;
}
}
return V_74 ;
}
int F_252 ( struct V_44 * V_28 ,
struct V_314 * V_315 )
{
struct V_24 * V_25 = & F_125 ( V_28 -> V_29 ) -> V_152 ;
struct V_32 * V_175 = F_125 ( V_28 -> V_29 ) -> V_54 -> V_175 ;
struct V_10 * V_11 , * V_367 = NULL ;
struct V_323 V_324 = {
. V_41 = NULL ,
. V_25 = V_25 ,
. V_328 = 0 ,
. V_349 = V_315 -> V_342 == V_343 ,
. V_217 = 0 ,
} ;
int V_74 = 0 ;
int V_147 = 0 ;
int V_368 = 0 ;
struct V_369 V_370 ;
int V_139 ;
T_9 V_126 ;
T_9 V_16 ;
int V_371 = 0 ;
int V_372 ;
F_253 ( & V_370 , 0 ) ;
if ( V_315 -> V_318 ) {
V_126 = V_28 -> V_322 ;
V_16 = - 1 ;
} else {
V_126 = V_315 -> V_319 >> V_127 ;
V_16 = V_315 -> V_320 >> V_127 ;
V_371 = 1 ;
}
if ( V_315 -> V_342 == V_343 )
V_372 = V_373 ;
else
V_372 = V_374 ;
V_375:
if ( V_315 -> V_342 == V_343 )
F_254 ( V_28 , V_126 , V_16 ) ;
while ( ! V_147 && ! V_368 && ( V_126 <= V_16 ) &&
( V_139 = F_255 ( & V_370 , V_28 , & V_126 , V_372 ,
F_131 ( V_16 - V_126 , ( T_9 ) V_376 - 1 ) + 1 ) ) ) {
unsigned V_140 ;
V_371 = 1 ;
for ( V_140 = 0 ; V_140 < V_139 ; V_140 ++ ) {
struct V_129 * V_129 = V_370 . V_138 [ V_140 ] ;
if ( ! F_193 ( V_129 ) )
continue;
if ( ! V_315 -> V_318 && V_129 -> V_126 > V_16 ) {
V_147 = 1 ;
break;
}
F_70 ( & V_28 -> V_377 ) ;
if ( ! F_193 ( V_129 ) ) {
F_74 ( & V_28 -> V_377 ) ;
continue;
}
V_11 = (struct V_10 * ) V_129 -> V_50 ;
if ( F_41 ( ! V_11 ) ) {
F_74 ( & V_28 -> V_377 ) ;
continue;
}
if ( V_11 == V_367 ) {
F_74 ( & V_28 -> V_377 ) ;
continue;
}
V_74 = F_256 ( & V_11 -> V_17 ) ;
F_74 ( & V_28 -> V_377 ) ;
if ( ! V_74 )
continue;
V_367 = V_11 ;
V_74 = F_231 ( V_11 , V_175 , & V_324 ) ;
if ( ! V_74 ) {
F_257 ( V_11 ) ;
continue;
}
V_74 = F_249 ( V_11 , V_175 , V_315 , & V_324 ) ;
if ( V_74 ) {
V_147 = 1 ;
F_257 ( V_11 ) ;
break;
}
F_257 ( V_11 ) ;
V_368 = V_315 -> V_317 <= 0 ;
}
F_258 ( & V_370 ) ;
F_75 () ;
}
if ( ! V_371 && ! V_147 ) {
V_371 = 1 ;
V_126 = 0 ;
goto V_375;
}
F_233 ( & V_324 ) ;
return V_74 ;
}
static int F_259 ( struct V_24 * V_25 ,
struct V_44 * V_28 ,
struct V_314 * V_315 ,
T_14 V_378 , void * V_226 ,
void (* F_260)( void * ) )
{
struct V_26 * V_26 = V_28 -> V_29 ;
int V_74 = 0 ;
int V_147 = 0 ;
int V_95 = 0 ;
int V_368 = 0 ;
struct V_369 V_370 ;
int V_139 ;
T_9 V_126 ;
T_9 V_16 ;
int V_371 = 0 ;
int V_372 ;
if ( ! F_261 ( V_26 ) )
return 0 ;
F_253 ( & V_370 , 0 ) ;
if ( V_315 -> V_318 ) {
V_126 = V_28 -> V_322 ;
V_16 = - 1 ;
} else {
V_126 = V_315 -> V_319 >> V_127 ;
V_16 = V_315 -> V_320 >> V_127 ;
V_371 = 1 ;
}
if ( V_315 -> V_342 == V_343 )
V_372 = V_373 ;
else
V_372 = V_374 ;
V_375:
if ( V_315 -> V_342 == V_343 )
F_254 ( V_28 , V_126 , V_16 ) ;
while ( ! V_147 && ! V_368 && ( V_126 <= V_16 ) &&
( V_139 = F_255 ( & V_370 , V_28 , & V_126 , V_372 ,
F_131 ( V_16 - V_126 , ( T_9 ) V_376 - 1 ) + 1 ) ) ) {
unsigned V_140 ;
V_371 = 1 ;
for ( V_140 = 0 ; V_140 < V_139 ; V_140 ++ ) {
struct V_129 * V_129 = V_370 . V_138 [ V_140 ] ;
if ( ! F_240 ( V_129 ) ) {
F_260 ( V_226 ) ;
F_120 ( V_129 ) ;
}
if ( F_180 ( V_129 -> V_28 != V_28 ) ) {
F_118 ( V_129 ) ;
continue;
}
if ( ! V_315 -> V_318 && V_129 -> V_126 > V_16 ) {
V_147 = 1 ;
F_118 ( V_129 ) ;
continue;
}
if ( V_315 -> V_342 != V_379 ) {
if ( F_224 ( V_129 ) )
F_260 ( V_226 ) ;
F_262 ( V_129 ) ;
}
if ( F_224 ( V_129 ) ||
! F_105 ( V_129 ) ) {
F_118 ( V_129 ) ;
continue;
}
V_74 = (* V_378)( V_129 , V_315 , V_226 ) ;
if ( F_180 ( V_74 == V_380 ) ) {
F_118 ( V_129 ) ;
V_74 = 0 ;
}
if ( ! V_95 && V_74 < 0 )
V_95 = V_74 ;
V_368 = V_315 -> V_317 <= 0 ;
}
F_258 ( & V_370 ) ;
F_75 () ;
}
if ( ! V_371 && ! V_147 && ! V_95 ) {
V_371 = 1 ;
V_126 = 0 ;
goto V_375;
}
F_263 ( V_26 ) ;
return V_95 ;
}
static void F_264 ( struct V_323 * V_324 )
{
if ( V_324 -> V_41 ) {
int V_273 = V_190 ;
int V_74 ;
if ( V_324 -> V_349 )
V_273 = V_197 ;
V_74 = F_185 ( V_273 , V_324 -> V_41 , 0 , V_324 -> V_217 ) ;
F_72 ( V_74 < 0 ) ;
V_324 -> V_41 = NULL ;
}
}
static T_5 void F_233 ( void * V_226 )
{
struct V_323 * V_324 = V_226 ;
F_264 ( V_324 ) ;
}
int F_265 ( struct V_24 * V_25 , struct V_129 * V_129 ,
T_12 * V_288 ,
struct V_314 * V_315 )
{
int V_74 ;
struct V_323 V_324 = {
. V_41 = NULL ,
. V_25 = V_25 ,
. V_288 = V_288 ,
. V_328 = 0 ,
. V_349 = V_315 -> V_342 == V_343 ,
. V_217 = 0 ,
} ;
V_74 = F_225 ( V_129 , V_315 , & V_324 ) ;
F_264 ( & V_324 ) ;
return V_74 ;
}
int F_266 ( struct V_24 * V_25 , struct V_26 * V_26 ,
T_1 V_15 , T_1 V_16 , T_12 * V_288 ,
int V_381 )
{
int V_74 = 0 ;
struct V_44 * V_28 = V_26 -> V_130 ;
struct V_129 * V_129 ;
unsigned long V_139 = ( V_16 - V_15 + V_149 ) >>
V_127 ;
struct V_323 V_324 = {
. V_41 = NULL ,
. V_25 = V_25 ,
. V_288 = V_288 ,
. V_328 = 1 ,
. V_349 = V_381 == V_343 ,
. V_217 = 0 ,
} ;
struct V_314 V_382 = {
. V_342 = V_381 ,
. V_317 = V_139 * 2 ,
. V_319 = V_15 ,
. V_320 = V_16 + 1 ,
} ;
while ( V_15 <= V_16 ) {
V_129 = F_104 ( V_28 , V_15 >> V_127 ) ;
if ( F_105 ( V_129 ) )
V_74 = F_225 ( V_129 , & V_382 , & V_324 ) ;
else {
if ( V_25 -> V_46 && V_25 -> V_46 -> V_245 )
V_25 -> V_46 -> V_245 ( V_129 , V_15 ,
V_15 + V_149 - 1 ,
NULL , 1 ) ;
F_118 ( V_129 ) ;
}
F_106 ( V_129 ) ;
V_15 += V_149 ;
}
F_264 ( & V_324 ) ;
return V_74 ;
}
int F_267 ( struct V_24 * V_25 ,
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
. V_349 = V_315 -> V_342 == V_343 ,
. V_217 = 0 ,
} ;
V_74 = F_259 ( V_25 , V_28 , V_315 ,
F_225 , & V_324 ,
F_233 ) ;
F_264 ( & V_324 ) ;
return V_74 ;
}
int F_268 ( struct V_24 * V_25 ,
struct V_44 * V_28 ,
struct V_4 * V_138 , unsigned V_139 ,
T_12 V_288 )
{
struct V_41 * V_41 = NULL ;
unsigned V_383 ;
unsigned long V_217 = 0 ;
struct V_129 * V_384 [ 16 ] ;
struct V_129 * V_129 ;
struct V_212 * V_289 = NULL ;
int V_281 = 0 ;
for ( V_383 = 0 ; V_383 < V_139 ; V_383 ++ ) {
V_129 = F_11 ( V_138 -> V_71 , struct V_129 , V_385 ) ;
F_269 ( & V_129 -> V_7 ) ;
F_8 ( & V_129 -> V_385 ) ;
if ( F_270 ( V_129 , V_28 ,
V_129 -> V_126 , V_125 ) ) {
F_106 ( V_129 ) ;
continue;
}
V_384 [ V_281 ++ ] = V_129 ;
if ( V_281 < F_271 ( V_384 ) )
continue;
F_214 ( V_25 , V_384 , V_281 , V_288 , & V_289 ,
& V_41 , 0 , & V_217 , V_313 ) ;
V_281 = 0 ;
}
if ( V_281 )
F_214 ( V_25 , V_384 , V_281 , V_288 , & V_289 ,
& V_41 , 0 , & V_217 , V_313 ) ;
if ( V_289 )
F_163 ( V_289 ) ;
F_72 ( ! F_10 ( V_138 ) ) ;
if ( V_41 )
return F_185 ( V_313 , V_41 , 0 , V_217 ) ;
return 0 ;
}
int F_272 ( struct V_24 * V_25 ,
struct V_129 * V_129 , unsigned long V_56 )
{
struct V_1 * V_97 = NULL ;
T_1 V_15 = F_136 ( V_129 ) ;
T_1 V_16 = V_15 + V_149 - 1 ;
T_10 V_299 = V_129 -> V_28 -> V_29 -> V_33 -> V_300 ;
V_15 += F_208 ( V_56 , V_299 ) ;
if ( V_15 > V_16 )
return 0 ;
F_98 ( V_25 , V_15 , V_16 , 0 , & V_97 ) ;
F_262 ( V_129 ) ;
F_68 ( V_25 , V_15 , V_16 ,
V_120 | V_92 | V_101 |
V_123 ,
1 , 1 , & V_97 , V_125 ) ;
return 0 ;
}
static int F_273 ( struct V_214 * V_386 ,
struct V_24 * V_25 ,
struct V_129 * V_129 , T_3 V_49 )
{
T_1 V_15 = F_136 ( V_129 ) ;
T_1 V_16 = V_15 + V_149 - 1 ;
int V_74 = 1 ;
if ( F_123 ( V_25 , V_15 , V_16 ,
V_78 , 0 , NULL ) )
V_74 = 0 ;
else {
if ( ( V_49 & V_125 ) == V_125 )
V_49 = V_125 ;
V_74 = F_68 ( V_25 , V_15 , V_16 ,
~ ( V_120 | V_387 ) ,
0 , 0 , NULL , V_49 ) ;
if ( V_74 < 0 )
V_74 = 0 ;
else
V_74 = 1 ;
}
return V_74 ;
}
int F_274 ( struct V_214 * V_386 ,
struct V_24 * V_25 , struct V_129 * V_129 ,
T_3 V_49 )
{
struct V_212 * V_213 ;
T_1 V_15 = F_136 ( V_129 ) ;
T_1 V_16 = V_15 + V_149 - 1 ;
if ( ( V_49 & V_105 ) &&
V_129 -> V_28 -> V_29 -> V_261 > 16 * 1024 * 1024 ) {
T_1 V_21 ;
while ( V_15 <= V_16 ) {
V_21 = V_16 - V_15 + 1 ;
F_275 ( & V_386 -> V_48 ) ;
V_213 = F_161 ( V_386 , V_15 , V_21 ) ;
if ( ! V_213 ) {
F_276 ( & V_386 -> V_48 ) ;
break;
}
if ( F_164 ( V_388 , & V_213 -> V_7 ) ||
V_213 -> V_15 != V_15 ) {
F_276 ( & V_386 -> V_48 ) ;
F_163 ( V_213 ) ;
break;
}
if ( ! F_123 ( V_25 , V_213 -> V_15 ,
F_200 ( V_213 ) - 1 ,
V_120 | V_389 ,
0 , NULL ) ) {
F_277 ( V_386 , V_213 ) ;
F_163 ( V_213 ) ;
}
V_15 = F_200 ( V_213 ) ;
F_276 ( & V_386 -> V_48 ) ;
F_163 ( V_213 ) ;
}
}
return F_273 ( V_386 , V_25 , V_129 , V_49 ) ;
}
static struct V_212 * F_278 ( struct V_26 * V_26 ,
T_1 V_56 ,
T_1 V_162 ,
T_12 * V_288 )
{
T_1 V_390 = F_125 ( V_26 ) -> V_54 -> V_390 ;
struct V_212 * V_213 ;
T_1 V_21 ;
if ( V_56 >= V_162 )
return NULL ;
while ( 1 ) {
V_21 = V_162 - V_56 ;
if ( V_21 == 0 )
break;
V_21 = F_208 ( V_21 , V_390 ) ;
V_213 = V_288 ( V_26 , NULL , 0 , V_56 , V_21 , 0 ) ;
if ( F_201 ( V_213 ) )
return V_213 ;
if ( ! F_164 ( V_391 , & V_213 -> V_7 ) &&
V_213 -> V_218 != V_307 ) {
return V_213 ;
}
V_56 = F_200 ( V_213 ) ;
F_163 ( V_213 ) ;
if ( V_56 >= V_162 )
break;
}
return NULL ;
}
int F_279 ( struct V_26 * V_26 , struct V_392 * V_393 ,
T_15 V_15 , T_15 V_21 , T_12 * V_288 )
{
int V_74 = 0 ;
T_1 V_262 = V_15 ;
T_1 F_132 = V_15 + V_21 ;
T_16 V_7 = 0 ;
T_16 V_394 ;
T_1 V_162 ;
T_1 V_395 = 0 ;
T_1 V_396 = 0 ;
T_1 V_27 = F_17 ( V_26 ) ;
struct V_397 V_398 ;
struct V_212 * V_213 = NULL ;
struct V_1 * V_97 = NULL ;
struct V_399 * V_400 ;
struct V_201 * V_54 = F_125 ( V_26 ) -> V_54 ;
int V_16 = 0 ;
T_1 V_401 = 0 ;
T_1 V_402 = 0 ;
T_1 V_339 = 0 ;
if ( V_21 == 0 )
return - V_403 ;
V_400 = F_280 () ;
if ( ! V_400 )
return - V_36 ;
V_400 -> V_404 = 1 ;
V_15 = F_281 ( V_15 , F_125 ( V_26 ) -> V_54 -> V_390 ) ;
V_21 = F_282 ( F_132 , F_125 ( V_26 ) -> V_54 -> V_390 ) - V_15 ;
V_74 = F_283 ( NULL , V_54 , V_400 , F_19 ( V_26 ) , - 1 ,
0 ) ;
if ( V_74 < 0 ) {
F_284 ( V_400 ) ;
return V_74 ;
}
F_41 ( ! V_74 ) ;
V_400 -> V_405 [ 0 ] -- ;
F_285 ( V_400 -> V_406 [ 0 ] , & V_398 , V_400 -> V_405 [ 0 ] ) ;
V_394 = V_398 . type ;
if ( V_398 . V_407 != F_19 ( V_26 ) ||
V_394 != V_408 ) {
V_162 = ( T_1 ) - 1 ;
V_395 = V_27 ;
} else {
V_162 = V_398 . V_56 ;
V_395 = V_162 + 1 ;
}
F_286 ( V_400 ) ;
if ( V_162 < V_27 ) {
V_162 = ( T_1 ) - 1 ;
V_395 = V_27 ;
}
F_98 ( & F_125 ( V_26 ) -> V_152 , V_15 , V_15 + V_21 - 1 , 0 ,
& V_97 ) ;
V_213 = F_278 ( V_26 , V_15 , V_395 ,
V_288 ) ;
if ( ! V_213 )
goto V_107;
if ( F_287 ( V_213 ) ) {
V_74 = F_288 ( V_213 ) ;
goto V_107;
}
while ( ! V_16 ) {
T_1 V_409 = 0 ;
if ( V_213 -> V_15 >= F_132 || F_200 ( V_213 ) < V_262 )
break;
V_401 = F_132 ( V_213 -> V_15 , V_262 ) ;
if ( ! F_164 ( V_219 , & V_213 -> V_7 ) )
V_409 = V_401 - V_213 -> V_15 ;
V_339 = F_200 ( V_213 ) ;
V_402 = V_339 - V_401 ;
V_396 = 0 ;
V_7 = 0 ;
V_262 = F_200 ( V_213 ) ;
if ( V_262 >= F_132 )
V_16 = 1 ;
if ( V_213 -> V_218 == V_410 ) {
V_16 = 1 ;
V_7 |= V_411 ;
} else if ( V_213 -> V_218 == V_308 ) {
V_7 |= ( V_412 |
V_413 ) ;
} else if ( V_213 -> V_218 == V_414 ) {
V_7 |= ( V_415 |
V_416 ) ;
} else if ( V_393 -> V_417 ) {
T_1 V_418 = V_213 -> V_218 -
( V_213 -> V_15 - V_213 -> V_419 ) ;
V_396 = V_213 -> V_218 + V_409 ;
V_74 = F_289 ( NULL , V_54 -> V_175 ,
V_54 -> V_407 ,
F_19 ( V_26 ) , V_418 ) ;
if ( V_74 < 0 )
goto V_420;
if ( V_74 )
V_7 |= V_421 ;
V_74 = 0 ;
}
if ( F_164 ( V_219 , & V_213 -> V_7 ) )
V_7 |= V_422 ;
if ( F_164 ( V_306 , & V_213 -> V_7 ) )
V_7 |= V_423 ;
F_163 ( V_213 ) ;
V_213 = NULL ;
if ( ( V_401 >= V_162 ) || V_402 == ( T_1 ) - 1 ||
( V_162 == ( T_1 ) - 1 && V_27 <= V_339 ) ) {
V_7 |= V_411 ;
V_16 = 1 ;
}
V_213 = F_278 ( V_26 , V_262 , V_395 ,
V_288 ) ;
if ( F_287 ( V_213 ) ) {
V_74 = F_288 ( V_213 ) ;
goto V_107;
}
if ( ! V_213 ) {
V_7 |= V_411 ;
V_16 = 1 ;
}
V_74 = F_290 ( V_393 , V_401 , V_396 ,
V_402 , V_7 ) ;
if ( V_74 ) {
if ( V_74 == 1 )
V_74 = 0 ;
goto V_420;
}
}
V_420:
F_163 ( V_213 ) ;
V_107:
F_284 ( V_400 ) ;
F_101 ( & F_125 ( V_26 ) -> V_152 , V_15 , V_15 + V_21 - 1 ,
& V_97 , V_125 ) ;
return V_74 ;
}
static void F_291 ( struct V_10 * V_11 )
{
F_7 ( & V_11 -> V_14 ) ;
F_14 ( V_22 , V_11 ) ;
}
int F_292 ( struct V_10 * V_11 )
{
return ( F_13 ( & V_11 -> V_363 ) ||
F_164 ( V_347 , & V_11 -> V_346 ) ||
F_164 ( V_351 , & V_11 -> V_346 ) ) ;
}
static void F_293 ( struct V_10 * V_11 )
{
unsigned long V_126 ;
struct V_129 * V_129 ;
int V_424 = ! F_164 ( V_425 , & V_11 -> V_346 ) ;
F_72 ( F_292 ( V_11 ) ) ;
V_126 = F_152 ( V_11 -> V_15 , V_11 -> V_21 ) ;
if ( V_126 == 0 )
return;
do {
V_126 -- ;
V_129 = V_11 -> V_138 [ V_126 ] ;
if ( ! V_129 )
continue;
if ( V_424 )
F_70 ( & V_129 -> V_28 -> V_377 ) ;
if ( F_193 ( V_129 ) &&
V_129 -> V_50 == ( unsigned long ) V_11 ) {
F_72 ( F_164 ( V_351 , & V_11 -> V_346 ) ) ;
F_72 ( F_121 ( V_129 ) ) ;
F_72 ( F_224 ( V_129 ) ) ;
F_294 ( V_129 ) ;
F_196 ( V_129 , 0 ) ;
F_106 ( V_129 ) ;
}
if ( V_424 )
F_74 ( & V_129 -> V_28 -> V_377 ) ;
F_106 ( V_129 ) ;
} while ( V_126 != 0 );
}
static inline void F_295 ( struct V_10 * V_11 )
{
F_293 ( V_11 ) ;
F_291 ( V_11 ) ;
}
static struct V_10 *
F_296 ( struct V_32 * V_175 , T_1 V_15 ,
unsigned long V_21 )
{
struct V_10 * V_11 = NULL ;
V_11 = F_297 ( V_22 , V_125 ) ;
if ( V_11 == NULL )
return NULL ;
V_11 -> V_15 = V_15 ;
V_11 -> V_21 = V_21 ;
V_11 -> V_175 = V_175 ;
V_11 -> V_346 = 0 ;
F_298 ( & V_11 -> V_48 ) ;
F_36 ( & V_11 -> V_426 , 0 ) ;
F_36 ( & V_11 -> V_427 , 0 ) ;
F_36 ( & V_11 -> V_428 , 0 ) ;
F_36 ( & V_11 -> V_429 , 0 ) ;
F_36 ( & V_11 -> V_430 , 0 ) ;
F_36 ( & V_11 -> V_431 , 0 ) ;
V_11 -> V_432 = 0 ;
F_37 ( & V_11 -> V_433 ) ;
F_37 ( & V_11 -> V_434 ) ;
F_3 ( & V_11 -> V_14 , & V_19 ) ;
F_32 ( & V_11 -> V_350 ) ;
F_36 ( & V_11 -> V_17 , 1 ) ;
F_36 ( & V_11 -> V_363 , 0 ) ;
F_299 ( V_435
> V_436 ) ;
F_72 ( V_21 > V_436 ) ;
return V_11 ;
}
struct V_10 * F_300 ( struct V_10 * V_437 )
{
unsigned long V_140 ;
struct V_129 * V_60 ;
struct V_10 * V_5 ;
unsigned long V_202 = F_152 ( V_437 -> V_15 , V_437 -> V_21 ) ;
V_5 = F_296 ( V_437 -> V_175 , V_437 -> V_15 , V_437 -> V_21 ) ;
if ( V_5 == NULL )
return NULL ;
for ( V_140 = 0 ; V_140 < V_202 ; V_140 ++ ) {
V_60 = F_301 ( V_125 ) ;
if ( ! V_60 ) {
F_295 ( V_5 ) ;
return NULL ;
}
F_192 ( V_5 , V_60 ) ;
F_41 ( F_121 ( V_60 ) ) ;
F_137 ( V_60 ) ;
V_5 -> V_138 [ V_140 ] = V_60 ;
}
F_302 ( V_5 , V_437 , 0 , 0 , V_437 -> V_21 ) ;
F_237 ( V_438 , & V_5 -> V_346 ) ;
F_237 ( V_425 , & V_5 -> V_346 ) ;
return V_5 ;
}
struct V_10 * F_303 ( struct V_32 * V_175 ,
T_1 V_15 )
{
struct V_10 * V_11 ;
unsigned long V_21 ;
unsigned long V_202 ;
unsigned long V_140 ;
if ( ! V_175 ) {
V_21 = 4096 ;
} else {
V_21 = V_175 -> V_439 -> V_440 ;
}
V_202 = F_152 ( 0 , V_21 ) ;
V_11 = F_296 ( V_175 , V_15 , V_21 ) ;
if ( ! V_11 )
return NULL ;
for ( V_140 = 0 ; V_140 < V_202 ; V_140 ++ ) {
V_11 -> V_138 [ V_140 ] = F_301 ( V_125 ) ;
if ( ! V_11 -> V_138 [ V_140 ] )
goto V_95;
}
F_304 ( V_11 ) ;
F_305 ( V_11 , 0 ) ;
F_237 ( V_425 , & V_11 -> V_346 ) ;
return V_11 ;
V_95:
for (; V_140 > 0 ; V_140 -- )
F_306 ( V_11 -> V_138 [ V_140 - 1 ] ) ;
F_291 ( V_11 ) ;
return NULL ;
}
static void F_307 ( struct V_10 * V_11 )
{
int V_17 ;
V_17 = F_13 ( & V_11 -> V_17 ) ;
if ( V_17 >= 2 && F_164 ( V_441 , & V_11 -> V_346 ) )
return;
F_70 ( & V_11 -> V_350 ) ;
if ( ! F_246 ( V_441 , & V_11 -> V_346 ) )
F_82 ( & V_11 -> V_17 ) ;
F_74 ( & V_11 -> V_350 ) ;
}
static void F_308 ( struct V_10 * V_11 ,
struct V_129 * V_442 )
{
unsigned long V_202 , V_140 ;
F_307 ( V_11 ) ;
V_202 = F_152 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_140 = 0 ; V_140 < V_202 ; V_140 ++ ) {
struct V_129 * V_60 = V_11 -> V_138 [ V_140 ] ;
if ( V_60 != V_442 )
F_309 ( V_60 ) ;
}
}
struct V_10 * F_310 ( struct V_32 * V_175 ,
T_1 V_15 )
{
struct V_10 * V_11 ;
F_311 () ;
V_11 = F_312 ( & V_175 -> V_443 ,
V_15 >> V_127 ) ;
if ( V_11 && F_256 ( & V_11 -> V_17 ) ) {
F_313 () ;
if ( F_164 ( V_444 , & V_11 -> V_346 ) ) {
F_70 ( & V_11 -> V_350 ) ;
F_74 ( & V_11 -> V_350 ) ;
}
F_308 ( V_11 , NULL ) ;
return V_11 ;
}
F_313 () ;
return NULL ;
}
struct V_10 * F_314 ( struct V_32 * V_175 ,
T_1 V_15 )
{
struct V_10 * V_11 , * V_445 = NULL ;
int V_74 ;
V_11 = F_310 ( V_175 , V_15 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_303 ( V_175 , V_15 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_175 = V_175 ;
V_104:
V_74 = F_315 ( V_125 & ~ V_446 ) ;
if ( V_74 )
goto V_447;
F_70 ( & V_175 -> V_448 ) ;
V_74 = F_316 ( & V_175 -> V_443 ,
V_15 >> V_127 , V_11 ) ;
F_74 ( & V_175 -> V_448 ) ;
F_317 () ;
if ( V_74 == - V_84 ) {
V_445 = F_310 ( V_175 , V_15 ) ;
if ( V_445 )
goto V_447;
else
goto V_104;
}
F_307 ( V_11 ) ;
F_237 ( V_449 , & V_11 -> V_346 ) ;
F_82 ( & V_11 -> V_17 ) ;
return V_11 ;
V_447:
F_295 ( V_11 ) ;
return V_445 ;
}
struct V_10 * F_318 ( struct V_32 * V_175 ,
T_1 V_15 )
{
unsigned long V_21 = V_175 -> V_439 -> V_440 ;
unsigned long V_202 = F_152 ( V_15 , V_21 ) ;
unsigned long V_140 ;
unsigned long V_126 = V_15 >> V_127 ;
struct V_10 * V_11 ;
struct V_10 * V_445 = NULL ;
struct V_129 * V_60 ;
struct V_44 * V_28 = V_175 -> V_204 -> V_130 ;
int V_244 = 1 ;
int V_74 ;
V_11 = F_310 ( V_175 , V_15 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_296 ( V_175 , V_15 , V_21 ) ;
if ( ! V_11 )
return NULL ;
for ( V_140 = 0 ; V_140 < V_202 ; V_140 ++ , V_126 ++ ) {
V_60 = F_319 ( V_28 , V_126 , V_125 ) ;
if ( ! V_60 )
goto V_447;
F_70 ( & V_28 -> V_377 ) ;
if ( F_193 ( V_60 ) ) {
V_445 = (struct V_10 * ) V_60 -> V_50 ;
if ( F_256 ( & V_445 -> V_17 ) ) {
F_74 ( & V_28 -> V_377 ) ;
F_118 ( V_60 ) ;
F_106 ( V_60 ) ;
F_308 ( V_445 , V_60 ) ;
goto V_447;
}
V_445 = NULL ;
F_294 ( V_60 ) ;
F_41 ( F_121 ( V_60 ) ) ;
F_106 ( V_60 ) ;
}
F_192 ( V_11 , V_60 ) ;
F_74 ( & V_28 -> V_377 ) ;
F_41 ( F_121 ( V_60 ) ) ;
V_11 -> V_138 [ V_140 ] = V_60 ;
if ( ! F_203 ( V_60 ) )
V_244 = 0 ;
}
if ( V_244 )
F_237 ( V_438 , & V_11 -> V_346 ) ;
V_104:
V_74 = F_315 ( V_125 & ~ V_446 ) ;
if ( V_74 )
goto V_447;
F_70 ( & V_175 -> V_448 ) ;
V_74 = F_316 ( & V_175 -> V_443 ,
V_15 >> V_127 , V_11 ) ;
F_74 ( & V_175 -> V_448 ) ;
F_317 () ;
if ( V_74 == - V_84 ) {
V_445 = F_310 ( V_175 , V_15 ) ;
if ( V_445 )
goto V_447;
else
goto V_104;
}
F_307 ( V_11 ) ;
F_237 ( V_449 , & V_11 -> V_346 ) ;
F_320 ( V_11 -> V_138 [ 0 ] ) ;
for ( V_140 = 1 ; V_140 < V_202 ; V_140 ++ ) {
V_60 = V_11 -> V_138 [ V_140 ] ;
F_321 ( V_60 ) ;
F_118 ( V_60 ) ;
}
F_118 ( V_11 -> V_138 [ 0 ] ) ;
return V_11 ;
V_447:
F_41 ( ! F_40 ( & V_11 -> V_17 ) ) ;
for ( V_140 = 0 ; V_140 < V_202 ; V_140 ++ ) {
if ( V_11 -> V_138 [ V_140 ] )
F_118 ( V_11 -> V_138 [ V_140 ] ) ;
}
F_295 ( V_11 ) ;
return V_445 ;
}
static inline void F_322 ( struct V_450 * V_6 )
{
struct V_10 * V_11 =
F_323 ( V_6 , struct V_10 , V_450 ) ;
F_291 ( V_11 ) ;
}
static int F_324 ( struct V_10 * V_11 )
{
F_41 ( F_13 ( & V_11 -> V_17 ) == 0 ) ;
if ( F_40 ( & V_11 -> V_17 ) ) {
if ( F_236 ( V_449 , & V_11 -> V_346 ) ) {
struct V_32 * V_175 = V_11 -> V_175 ;
F_74 ( & V_11 -> V_350 ) ;
F_70 ( & V_175 -> V_448 ) ;
F_325 ( & V_175 -> V_443 ,
V_11 -> V_15 >> V_127 ) ;
F_74 ( & V_175 -> V_448 ) ;
} else {
F_74 ( & V_11 -> V_350 ) ;
}
F_293 ( V_11 ) ;
#ifdef F_326
if ( F_180 ( F_164 ( V_425 , & V_11 -> V_346 ) ) ) {
F_291 ( V_11 ) ;
return 1 ;
}
#endif
F_327 ( & V_11 -> V_450 , F_322 ) ;
return 1 ;
}
F_74 ( & V_11 -> V_350 ) ;
return 0 ;
}
void F_257 ( struct V_10 * V_11 )
{
int V_17 ;
int V_451 ;
if ( ! V_11 )
return;
while ( 1 ) {
V_17 = F_13 ( & V_11 -> V_17 ) ;
if ( V_17 <= 3 )
break;
V_451 = F_328 ( & V_11 -> V_17 , V_17 , V_17 - 1 ) ;
if ( V_451 == V_17 )
return;
}
F_70 ( & V_11 -> V_350 ) ;
if ( F_13 ( & V_11 -> V_17 ) == 2 &&
F_164 ( V_425 , & V_11 -> V_346 ) )
F_71 ( & V_11 -> V_17 ) ;
if ( F_13 ( & V_11 -> V_17 ) == 2 &&
F_164 ( V_444 , & V_11 -> V_346 ) &&
! F_292 ( V_11 ) &&
F_236 ( V_441 , & V_11 -> V_346 ) )
F_71 ( & V_11 -> V_17 ) ;
F_324 ( V_11 ) ;
}
void F_329 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return;
F_70 ( & V_11 -> V_350 ) ;
F_237 ( V_444 , & V_11 -> V_346 ) ;
if ( F_13 ( & V_11 -> V_17 ) == 2 && ! F_292 ( V_11 ) &&
F_236 ( V_441 , & V_11 -> V_346 ) )
F_71 ( & V_11 -> V_17 ) ;
F_324 ( V_11 ) ;
}
void F_330 ( struct V_10 * V_11 )
{
unsigned long V_140 ;
unsigned long V_202 ;
struct V_129 * V_129 ;
V_202 = F_152 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_140 = 0 ; V_140 < V_202 ; V_140 ++ ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
if ( ! F_121 ( V_129 ) )
continue;
F_120 ( V_129 ) ;
F_41 ( ! F_193 ( V_129 ) ) ;
F_105 ( V_129 ) ;
F_331 ( & V_129 -> V_28 -> V_452 ) ;
if ( ! F_121 ( V_129 ) ) {
F_332 ( & V_129 -> V_28 -> V_453 ,
F_333 ( V_129 ) ,
V_374 ) ;
}
F_334 ( & V_129 -> V_28 -> V_452 ) ;
F_228 ( V_129 ) ;
F_118 ( V_129 ) ;
}
F_41 ( F_13 ( & V_11 -> V_17 ) == 0 ) ;
}
int F_335 ( struct V_10 * V_11 )
{
unsigned long V_140 ;
unsigned long V_202 ;
int V_454 = 0 ;
F_307 ( V_11 ) ;
V_454 = F_246 ( V_351 , & V_11 -> V_346 ) ;
V_202 = F_152 ( V_11 -> V_15 , V_11 -> V_21 ) ;
F_41 ( F_13 ( & V_11 -> V_17 ) == 0 ) ;
F_41 ( ! F_164 ( V_441 , & V_11 -> V_346 ) ) ;
for ( V_140 = 0 ; V_140 < V_202 ; V_140 ++ )
F_336 ( V_11 -> V_138 [ V_140 ] ) ;
return V_454 ;
}
int F_337 ( struct V_10 * V_11 )
{
unsigned long V_140 ;
struct V_129 * V_129 ;
unsigned long V_202 ;
F_242 ( V_438 , & V_11 -> V_346 ) ;
V_202 = F_152 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_140 = 0 ; V_140 < V_202 ; V_140 ++ ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
if ( V_129 )
F_171 ( V_129 ) ;
}
return 0 ;
}
int F_304 ( struct V_10 * V_11 )
{
unsigned long V_140 ;
struct V_129 * V_129 ;
unsigned long V_202 ;
F_237 ( V_438 , & V_11 -> V_346 ) ;
V_202 = F_152 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_140 = 0 ; V_140 < V_202 ; V_140 ++ ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
F_137 ( V_129 ) ;
}
return 0 ;
}
int F_338 ( struct V_10 * V_11 )
{
return F_164 ( V_438 , & V_11 -> V_346 ) ;
}
int F_339 ( struct V_24 * V_25 ,
struct V_10 * V_11 , T_1 V_15 , int V_109 ,
T_12 * V_288 , int V_174 )
{
unsigned long V_140 ;
unsigned long V_455 ;
struct V_129 * V_129 ;
int V_95 ;
int V_74 = 0 ;
int V_456 = 0 ;
int V_457 = 1 ;
unsigned long V_202 ;
unsigned long V_458 = 0 ;
struct V_41 * V_41 = NULL ;
unsigned long V_217 = 0 ;
if ( F_164 ( V_438 , & V_11 -> V_346 ) )
return 0 ;
if ( V_15 ) {
F_41 ( V_15 < V_11 -> V_15 ) ;
V_455 = ( V_15 >> V_127 ) -
( V_11 -> V_15 >> V_127 ) ;
} else {
V_455 = 0 ;
}
V_202 = F_152 ( V_11 -> V_15 , V_11 -> V_21 ) ;
for ( V_140 = V_455 ; V_140 < V_202 ; V_140 ++ ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
if ( V_109 == V_459 ) {
if ( ! F_240 ( V_129 ) )
goto V_460;
} else {
F_120 ( V_129 ) ;
}
V_456 ++ ;
if ( ! F_203 ( V_129 ) ) {
V_458 ++ ;
V_457 = 0 ;
}
}
if ( V_457 ) {
if ( V_455 == 0 )
F_237 ( V_438 , & V_11 -> V_346 ) ;
goto V_460;
}
F_242 ( V_461 , & V_11 -> V_346 ) ;
V_11 -> V_462 = 0 ;
F_36 ( & V_11 -> V_363 , V_458 ) ;
for ( V_140 = V_455 ; V_140 < V_202 ; V_140 ++ ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
if ( ! F_203 ( V_129 ) ) {
F_228 ( V_129 ) ;
V_95 = F_215 ( V_25 , V_129 ,
V_288 , & V_41 ,
V_174 , & V_217 ,
V_313 | V_364 ) ;
if ( V_95 )
V_74 = V_95 ;
} else {
F_118 ( V_129 ) ;
}
}
if ( V_41 ) {
V_95 = F_185 ( V_313 | V_364 , V_41 , V_174 ,
V_217 ) ;
if ( V_95 )
return V_95 ;
}
if ( V_74 || V_109 != V_463 )
return V_74 ;
for ( V_140 = V_455 ; V_140 < V_202 ; V_140 ++ ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
F_340 ( V_129 ) ;
if ( ! F_203 ( V_129 ) )
V_74 = - V_154 ;
}
return V_74 ;
V_460:
V_140 = V_455 ;
while ( V_456 > 0 ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
V_140 ++ ;
F_118 ( V_129 ) ;
V_456 -- ;
}
return V_74 ;
}
void F_341 ( struct V_10 * V_11 , void * V_464 ,
unsigned long V_15 ,
unsigned long V_21 )
{
T_10 V_291 ;
T_10 V_56 ;
struct V_129 * V_129 ;
char * V_465 ;
char * V_466 = ( char * ) V_464 ;
T_10 V_467 = V_11 -> V_15 & ( ( T_1 ) V_149 - 1 ) ;
unsigned long V_140 = ( V_467 + V_15 ) >> V_127 ;
F_41 ( V_15 > V_11 -> V_21 ) ;
F_41 ( V_15 + V_21 > V_11 -> V_15 + V_11 -> V_21 ) ;
V_56 = ( V_467 + V_15 ) & ( V_149 - 1 ) ;
while ( V_21 > 0 ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
V_291 = F_131 ( V_21 , ( V_149 - V_56 ) ) ;
V_465 = F_342 ( V_129 ) ;
memcpy ( V_466 , V_465 + V_56 , V_291 ) ;
V_466 += V_291 ;
V_21 -= V_291 ;
V_56 = 0 ;
V_140 ++ ;
}
}
int F_343 ( struct V_10 * V_11 , void T_17 * V_464 ,
unsigned long V_15 ,
unsigned long V_21 )
{
T_10 V_291 ;
T_10 V_56 ;
struct V_129 * V_129 ;
char * V_465 ;
char T_17 * V_466 = ( char T_17 * ) V_464 ;
T_10 V_467 = V_11 -> V_15 & ( ( T_1 ) V_149 - 1 ) ;
unsigned long V_140 = ( V_467 + V_15 ) >> V_127 ;
int V_74 = 0 ;
F_41 ( V_15 > V_11 -> V_21 ) ;
F_41 ( V_15 + V_21 > V_11 -> V_15 + V_11 -> V_21 ) ;
V_56 = ( V_467 + V_15 ) & ( V_149 - 1 ) ;
while ( V_21 > 0 ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
V_291 = F_131 ( V_21 , ( V_149 - V_56 ) ) ;
V_465 = F_342 ( V_129 ) ;
if ( F_344 ( V_466 , V_465 + V_56 , V_291 ) ) {
V_74 = - V_468 ;
break;
}
V_466 += V_291 ;
V_21 -= V_291 ;
V_56 = 0 ;
V_140 ++ ;
}
return V_74 ;
}
int F_345 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_469 , char * * V_386 ,
unsigned long * V_470 ,
unsigned long * V_471 )
{
T_10 V_56 = V_15 & ( V_149 - 1 ) ;
char * V_465 ;
struct V_129 * V_60 ;
T_10 V_467 = V_11 -> V_15 & ( ( T_1 ) V_149 - 1 ) ;
unsigned long V_140 = ( V_467 + V_15 ) >> V_127 ;
unsigned long V_472 = ( V_467 + V_15 + V_469 - 1 ) >>
V_127 ;
if ( V_140 != V_472 )
return - V_403 ;
if ( V_140 == 0 ) {
V_56 = V_467 ;
* V_470 = 0 ;
} else {
V_56 = 0 ;
* V_470 = ( ( T_1 ) V_140 << V_127 ) - V_467 ;
}
if ( V_15 + V_469 > V_11 -> V_21 ) {
F_58 ( 1 , V_20 L_28
L_29 ,
V_11 -> V_15 , V_11 -> V_21 , V_15 , V_469 ) ;
return - V_403 ;
}
V_60 = V_11 -> V_138 [ V_140 ] ;
V_465 = F_342 ( V_60 ) ;
* V_386 = V_465 + V_56 ;
* V_471 = V_149 - V_56 ;
return 0 ;
}
int F_346 ( struct V_10 * V_11 , const void * V_473 ,
unsigned long V_15 ,
unsigned long V_21 )
{
T_10 V_291 ;
T_10 V_56 ;
struct V_129 * V_129 ;
char * V_465 ;
char * V_474 = ( char * ) V_473 ;
T_10 V_467 = V_11 -> V_15 & ( ( T_1 ) V_149 - 1 ) ;
unsigned long V_140 = ( V_467 + V_15 ) >> V_127 ;
int V_74 = 0 ;
F_41 ( V_15 > V_11 -> V_21 ) ;
F_41 ( V_15 + V_21 > V_11 -> V_15 + V_11 -> V_21 ) ;
V_56 = ( V_467 + V_15 ) & ( V_149 - 1 ) ;
while ( V_21 > 0 ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
V_291 = F_131 ( V_21 , ( V_149 - V_56 ) ) ;
V_465 = F_342 ( V_129 ) ;
V_74 = memcmp ( V_474 , V_465 + V_56 , V_291 ) ;
if ( V_74 )
break;
V_474 += V_291 ;
V_21 -= V_291 ;
V_56 = 0 ;
V_140 ++ ;
}
return V_74 ;
}
void F_347 ( struct V_10 * V_11 , const void * V_475 ,
unsigned long V_15 , unsigned long V_21 )
{
T_10 V_291 ;
T_10 V_56 ;
struct V_129 * V_129 ;
char * V_465 ;
char * V_437 = ( char * ) V_475 ;
T_10 V_467 = V_11 -> V_15 & ( ( T_1 ) V_149 - 1 ) ;
unsigned long V_140 = ( V_467 + V_15 ) >> V_127 ;
F_41 ( V_15 > V_11 -> V_21 ) ;
F_41 ( V_15 + V_21 > V_11 -> V_15 + V_11 -> V_21 ) ;
V_56 = ( V_467 + V_15 ) & ( V_149 - 1 ) ;
while ( V_21 > 0 ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
F_41 ( ! F_203 ( V_129 ) ) ;
V_291 = F_131 ( V_21 , V_149 - V_56 ) ;
V_465 = F_342 ( V_129 ) ;
memcpy ( V_465 + V_56 , V_437 , V_291 ) ;
V_437 += V_291 ;
V_21 -= V_291 ;
V_56 = 0 ;
V_140 ++ ;
}
}
void F_348 ( struct V_10 * V_11 , char V_476 ,
unsigned long V_15 , unsigned long V_21 )
{
T_10 V_291 ;
T_10 V_56 ;
struct V_129 * V_129 ;
char * V_465 ;
T_10 V_467 = V_11 -> V_15 & ( ( T_1 ) V_149 - 1 ) ;
unsigned long V_140 = ( V_467 + V_15 ) >> V_127 ;
F_41 ( V_15 > V_11 -> V_21 ) ;
F_41 ( V_15 + V_21 > V_11 -> V_15 + V_11 -> V_21 ) ;
V_56 = ( V_467 + V_15 ) & ( V_149 - 1 ) ;
while ( V_21 > 0 ) {
V_129 = V_11 -> V_138 [ V_140 ] ;
F_41 ( ! F_203 ( V_129 ) ) ;
V_291 = F_131 ( V_21 , V_149 - V_56 ) ;
V_465 = F_342 ( V_129 ) ;
memset ( V_465 + V_56 , V_476 , V_291 ) ;
V_21 -= V_291 ;
V_56 = 0 ;
V_140 ++ ;
}
}
void F_302 ( struct V_10 * V_466 , struct V_10 * V_437 ,
unsigned long V_477 , unsigned long V_478 ,
unsigned long V_21 )
{
T_1 V_479 = V_466 -> V_21 ;
T_10 V_291 ;
T_10 V_56 ;
struct V_129 * V_129 ;
char * V_465 ;
T_10 V_467 = V_466 -> V_15 & ( ( T_1 ) V_149 - 1 ) ;
unsigned long V_140 = ( V_467 + V_477 ) >> V_127 ;
F_41 ( V_437 -> V_21 != V_479 ) ;
V_56 = ( V_467 + V_477 ) &
( V_149 - 1 ) ;
while ( V_21 > 0 ) {
V_129 = V_466 -> V_138 [ V_140 ] ;
F_41 ( ! F_203 ( V_129 ) ) ;
V_291 = F_131 ( V_21 , ( unsigned long ) ( V_149 - V_56 ) ) ;
V_465 = F_342 ( V_129 ) ;
F_341 ( V_437 , V_465 + V_56 , V_478 , V_291 ) ;
V_478 += V_291 ;
V_21 -= V_291 ;
V_56 = 0 ;
V_140 ++ ;
}
}
static inline bool F_349 ( unsigned long V_437 , unsigned long V_466 , unsigned long V_21 )
{
unsigned long V_480 = ( V_437 > V_466 ) ? V_437 - V_466 : V_466 - V_437 ;
return V_480 < V_21 ;
}
static void F_350 ( struct V_129 * V_481 , struct V_129 * V_482 ,
unsigned long V_483 , unsigned long V_484 ,
unsigned long V_21 )
{
char * V_485 = F_342 ( V_481 ) ;
char * V_486 ;
int V_487 = 0 ;
if ( V_481 != V_482 ) {
V_486 = F_342 ( V_482 ) ;
} else {
V_486 = V_485 ;
if ( F_349 ( V_484 , V_483 , V_21 ) )
V_487 = 1 ;
}
if ( V_487 )
memmove ( V_485 + V_483 , V_486 + V_484 , V_21 ) ;
else
memcpy ( V_485 + V_483 , V_486 + V_484 , V_21 ) ;
}
void F_351 ( struct V_10 * V_466 , unsigned long V_477 ,
unsigned long V_478 , unsigned long V_21 )
{
T_10 V_291 ;
T_10 V_488 ;
T_10 V_489 ;
T_10 V_467 = V_466 -> V_15 & ( ( T_1 ) V_149 - 1 ) ;
unsigned long V_490 ;
unsigned long V_491 ;
if ( V_478 + V_21 > V_466 -> V_21 ) {
F_15 ( V_20 L_30
L_31 , V_478 , V_21 , V_466 -> V_21 ) ;
F_72 ( 1 ) ;
}
if ( V_477 + V_21 > V_466 -> V_21 ) {
F_15 ( V_20 L_32
L_31 , V_477 , V_21 , V_466 -> V_21 ) ;
F_72 ( 1 ) ;
}
while ( V_21 > 0 ) {
V_488 = ( V_467 + V_477 ) &
( V_149 - 1 ) ;
V_489 = ( V_467 + V_478 ) &
( V_149 - 1 ) ;
V_490 = ( V_467 + V_477 ) >> V_127 ;
V_491 = ( V_467 + V_478 ) >> V_127 ;
V_291 = F_131 ( V_21 , ( unsigned long ) ( V_149 -
V_489 ) ) ;
V_291 = F_117 (unsigned long, cur,
(unsigned long)(PAGE_CACHE_SIZE - dst_off_in_page)) ;
F_350 ( V_466 -> V_138 [ V_490 ] , V_466 -> V_138 [ V_491 ] ,
V_488 , V_489 , V_291 ) ;
V_478 += V_291 ;
V_477 += V_291 ;
V_21 -= V_291 ;
}
}
void F_352 ( struct V_10 * V_466 , unsigned long V_477 ,
unsigned long V_478 , unsigned long V_21 )
{
T_10 V_291 ;
T_10 V_488 ;
T_10 V_489 ;
unsigned long V_492 = V_477 + V_21 - 1 ;
unsigned long V_493 = V_478 + V_21 - 1 ;
T_10 V_467 = V_466 -> V_15 & ( ( T_1 ) V_149 - 1 ) ;
unsigned long V_490 ;
unsigned long V_491 ;
if ( V_478 + V_21 > V_466 -> V_21 ) {
F_15 ( V_20 L_30
L_33 , V_478 , V_21 , V_466 -> V_21 ) ;
F_72 ( 1 ) ;
}
if ( V_477 + V_21 > V_466 -> V_21 ) {
F_15 ( V_20 L_32
L_33 , V_477 , V_21 , V_466 -> V_21 ) ;
F_72 ( 1 ) ;
}
if ( V_477 < V_478 ) {
F_351 ( V_466 , V_477 , V_478 , V_21 ) ;
return;
}
while ( V_21 > 0 ) {
V_490 = ( V_467 + V_492 ) >> V_127 ;
V_491 = ( V_467 + V_493 ) >> V_127 ;
V_488 = ( V_467 + V_492 ) &
( V_149 - 1 ) ;
V_489 = ( V_467 + V_493 ) &
( V_149 - 1 ) ;
V_291 = F_117 (unsigned long, len, src_off_in_page + 1 ) ;
V_291 = F_131 ( V_291 , V_488 + 1 ) ;
F_350 ( V_466 -> V_138 [ V_490 ] , V_466 -> V_138 [ V_491 ] ,
V_488 - V_291 + 1 ,
V_489 - V_291 + 1 , V_291 ) ;
V_492 -= V_291 ;
V_493 -= V_291 ;
V_21 -= V_291 ;
}
}
int F_353 ( struct V_129 * V_129 )
{
struct V_10 * V_11 ;
F_70 ( & V_129 -> V_28 -> V_377 ) ;
if ( ! F_193 ( V_129 ) ) {
F_74 ( & V_129 -> V_28 -> V_377 ) ;
return 1 ;
}
V_11 = (struct V_10 * ) V_129 -> V_50 ;
F_72 ( ! V_11 ) ;
F_70 ( & V_11 -> V_350 ) ;
if ( F_13 ( & V_11 -> V_17 ) != 1 || F_292 ( V_11 ) ) {
F_74 ( & V_11 -> V_350 ) ;
F_74 ( & V_129 -> V_28 -> V_377 ) ;
return 0 ;
}
F_74 ( & V_129 -> V_28 -> V_377 ) ;
if ( ! F_236 ( V_441 , & V_11 -> V_346 ) ) {
F_74 ( & V_11 -> V_350 ) ;
return 0 ;
}
return F_324 ( V_11 ) ;
}
