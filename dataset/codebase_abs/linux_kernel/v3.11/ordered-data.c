static T_1 F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 + V_2 -> V_4 < V_2 -> V_3 )
return ( T_1 ) - 1 ;
return V_2 -> V_3 + V_2 -> V_4 ;
}
static struct V_5 * F_2 ( struct V_6 * V_7 , T_1 V_3 ,
struct V_5 * V_8 )
{
struct V_5 * * V_9 = & V_7 -> V_5 ;
struct V_5 * V_10 = NULL ;
struct V_1 * V_2 ;
while ( * V_9 ) {
V_10 = * V_9 ;
V_2 = F_3 ( V_10 , struct V_1 , V_5 ) ;
if ( V_3 < V_2 -> V_3 )
V_9 = & ( * V_9 ) -> V_11 ;
else if ( V_3 >= F_1 ( V_2 ) )
V_9 = & ( * V_9 ) -> V_12 ;
else
return V_10 ;
}
F_4 ( V_8 , V_10 , V_9 ) ;
F_5 ( V_8 , V_7 ) ;
return NULL ;
}
static void F_6 ( struct V_13 * V_13 , int V_14 ,
T_1 V_15 )
{
struct V_16 * V_17 = F_7 ( V_13 -> V_18 ) ;
F_8 ( V_17 , V_14 , L_1
L_2 , ( unsigned long long ) V_15 ) ;
}
static struct V_5 * F_9 ( struct V_6 * V_7 , T_1 V_3 ,
struct V_5 * * V_19 )
{
struct V_5 * V_20 = V_7 -> V_5 ;
struct V_5 * V_21 = NULL ;
struct V_5 * V_22 ;
struct V_1 * V_2 ;
struct V_1 * V_23 = NULL ;
while ( V_20 ) {
V_2 = F_3 ( V_20 , struct V_1 , V_5 ) ;
V_21 = V_20 ;
V_23 = V_2 ;
if ( V_3 < V_2 -> V_3 )
V_20 = V_20 -> V_11 ;
else if ( V_3 >= F_1 ( V_2 ) )
V_20 = V_20 -> V_12 ;
else
return V_20 ;
}
if ( ! V_19 )
return NULL ;
while ( V_21 && V_3 >= F_1 ( V_23 ) ) {
V_22 = F_10 ( V_21 ) ;
if ( ! V_22 )
break;
V_23 = F_3 ( V_22 , struct V_1 ,
V_5 ) ;
if ( V_3 < F_1 ( V_23 ) )
break;
V_21 = V_22 ;
}
if ( V_21 )
V_23 = F_3 ( V_21 , struct V_1 ,
V_5 ) ;
while ( V_21 && V_3 < F_1 ( V_23 ) ) {
V_22 = F_11 ( V_21 ) ;
if ( ! V_22 )
break;
V_23 = F_3 ( V_22 , struct V_1 ,
V_5 ) ;
V_21 = V_22 ;
}
* V_19 = V_21 ;
return NULL ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_3 < V_2 -> V_3 ||
V_2 -> V_3 + V_2 -> V_4 <= V_3 )
return 0 ;
return 1 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
if ( V_3 + V_4 <= V_2 -> V_3 ||
V_2 -> V_3 + V_2 -> V_4 <= V_3 )
return 0 ;
return 1 ;
}
static inline struct V_5 * F_14 ( struct V_24 * V_25 ,
T_1 V_3 )
{
struct V_6 * V_7 = & V_25 -> V_25 ;
struct V_5 * V_21 = NULL ;
struct V_5 * V_26 ;
struct V_1 * V_2 ;
if ( V_25 -> V_27 ) {
V_2 = F_3 ( V_25 -> V_27 , struct V_1 ,
V_5 ) ;
if ( F_12 ( V_2 , V_3 ) )
return V_25 -> V_27 ;
}
V_26 = F_9 ( V_7 , V_3 , & V_21 ) ;
if ( ! V_26 )
V_26 = V_21 ;
if ( V_26 )
V_25 -> V_27 = V_26 ;
return V_26 ;
}
static int F_15 ( struct V_13 * V_13 , T_1 V_3 ,
T_1 V_28 , T_1 V_4 , T_1 V_29 ,
int type , int V_30 , int V_31 )
{
struct V_32 * V_7 = F_16 ( V_13 ) -> V_7 ;
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
V_2 = F_17 ( V_34 , V_35 ) ;
if ( ! V_2 )
return - V_36 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_4 = V_4 ;
if ( ! ( F_16 ( V_13 ) -> V_37 & V_38 ) &&
! ( type == V_39 ) )
V_2 -> V_40 = V_29 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_41 = V_4 ;
V_2 -> V_13 = F_18 ( V_13 ) ;
V_2 -> V_31 = V_31 ;
if ( type != V_42 && type != V_43 )
F_19 ( type , & V_2 -> V_37 ) ;
if ( V_30 )
F_19 ( V_44 , & V_2 -> V_37 ) ;
F_20 ( & V_2 -> V_45 , 1 ) ;
F_21 ( & V_2 -> V_46 ) ;
F_22 ( & V_2 -> V_47 ) ;
F_22 ( & V_2 -> V_48 ) ;
F_22 ( & V_2 -> V_49 ) ;
F_23 ( & V_2 -> V_50 ) ;
F_22 ( & V_2 -> V_51 ) ;
F_24 ( V_13 , V_2 ) ;
F_25 ( & V_25 -> V_52 ) ;
V_8 = F_2 ( & V_25 -> V_25 , V_3 ,
& V_2 -> V_5 ) ;
if ( V_8 )
F_6 ( V_13 , - V_53 , V_3 ) ;
F_26 ( & V_25 -> V_52 ) ;
F_27 ( & V_7 -> V_54 ) ;
F_28 ( & V_2 -> V_48 ,
& V_7 -> V_55 ) ;
V_7 -> V_56 ++ ;
if ( V_7 -> V_56 == 1 ) {
F_27 ( & V_7 -> V_17 -> V_57 ) ;
F_29 ( ! F_30 ( & V_7 -> V_58 ) ) ;
F_28 ( & V_7 -> V_58 ,
& V_7 -> V_17 -> V_59 ) ;
F_31 ( & V_7 -> V_17 -> V_57 ) ;
}
F_31 ( & V_7 -> V_54 ) ;
return 0 ;
}
int F_32 ( struct V_13 * V_13 , T_1 V_3 ,
T_1 V_28 , T_1 V_4 , T_1 V_29 , int type )
{
return F_15 ( V_13 , V_3 , V_28 , V_4 ,
V_29 , type , 0 ,
V_60 ) ;
}
int F_33 ( struct V_13 * V_13 , T_1 V_3 ,
T_1 V_28 , T_1 V_4 , T_1 V_29 , int type )
{
return F_15 ( V_13 , V_3 , V_28 , V_4 ,
V_29 , type , 1 ,
V_60 ) ;
}
int F_34 ( struct V_13 * V_13 , T_1 V_3 ,
T_1 V_28 , T_1 V_4 , T_1 V_29 ,
int type , int V_31 )
{
return F_15 ( V_13 , V_3 , V_28 , V_4 ,
V_29 , type , 0 ,
V_31 ) ;
}
void F_35 ( struct V_13 * V_13 ,
struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_24 * V_25 ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
F_25 ( & V_25 -> V_52 ) ;
F_28 ( & V_62 -> V_47 , & V_2 -> V_47 ) ;
F_36 ( V_2 -> V_40 < V_62 -> V_4 ) ;
V_2 -> V_40 -= V_62 -> V_4 ;
if ( V_2 -> V_40 == 0 )
F_37 ( & V_2 -> V_46 ) ;
F_26 ( & V_25 -> V_52 ) ;
}
int F_38 ( struct V_13 * V_13 ,
struct V_1 * * V_63 ,
T_1 * V_3 , T_1 V_64 , int V_65 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
int V_26 ;
unsigned long V_37 ;
T_1 V_66 ;
T_1 V_67 ;
T_1 V_68 ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
F_39 ( & V_25 -> V_52 , V_37 ) ;
V_8 = F_14 ( V_25 , * V_3 ) ;
if ( ! V_8 ) {
V_26 = 1 ;
goto V_69;
}
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( ! F_12 ( V_2 , * V_3 ) ) {
V_26 = 1 ;
goto V_69;
}
V_67 = F_40 ( * V_3 , V_2 -> V_3 ) ;
V_66 = F_41 ( * V_3 + V_64 , V_2 -> V_3 +
V_2 -> V_4 ) ;
* V_3 = V_66 ;
if ( V_67 > V_66 ) {
F_42 ( V_70 L_3 ,
( unsigned long long ) V_67 ,
( unsigned long long ) V_66 ) ;
}
V_68 = V_66 - V_67 ;
if ( V_68 > V_2 -> V_41 ) {
F_42 ( V_70 L_4 ,
( unsigned long long ) V_2 -> V_41 ,
( unsigned long long ) V_68 ) ;
}
V_2 -> V_41 -= V_68 ;
if ( ! V_65 )
F_19 ( V_71 , & V_2 -> V_37 ) ;
if ( V_2 -> V_41 == 0 )
V_26 = F_43 ( V_42 , & V_2 -> V_37 ) ;
else
V_26 = 1 ;
V_69:
if ( ! V_26 && V_63 && V_2 ) {
* V_63 = V_2 ;
F_44 ( & V_2 -> V_45 ) ;
}
F_45 ( & V_25 -> V_52 , V_37 ) ;
return V_26 == 0 ;
}
int F_46 ( struct V_13 * V_13 ,
struct V_1 * * V_63 ,
T_1 V_3 , T_1 V_64 , int V_65 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
unsigned long V_37 ;
int V_26 ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
F_39 ( & V_25 -> V_52 , V_37 ) ;
if ( V_63 && * V_63 ) {
V_2 = * V_63 ;
goto V_72;
}
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 ) {
V_26 = 1 ;
goto V_69;
}
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
V_72:
if ( ! F_12 ( V_2 , V_3 ) ) {
V_26 = 1 ;
goto V_69;
}
if ( V_64 > V_2 -> V_41 ) {
F_42 ( V_70 L_4 ,
( unsigned long long ) V_2 -> V_41 ,
( unsigned long long ) V_64 ) ;
}
V_2 -> V_41 -= V_64 ;
if ( ! V_65 )
F_19 ( V_71 , & V_2 -> V_37 ) ;
if ( V_2 -> V_41 == 0 )
V_26 = F_43 ( V_42 , & V_2 -> V_37 ) ;
else
V_26 = 1 ;
V_69:
if ( ! V_26 && V_63 && V_2 ) {
* V_63 = V_2 ;
F_44 ( & V_2 -> V_45 ) ;
}
F_45 ( & V_25 -> V_52 , V_37 ) ;
return V_26 == 0 ;
}
void F_47 ( struct V_32 * log , struct V_13 * V_13 )
{
struct V_24 * V_25 ;
struct V_1 * V_73 ;
struct V_5 * V_20 ;
int V_74 = log -> V_75 % 2 ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
F_25 ( & V_25 -> V_52 ) ;
for ( V_20 = F_48 ( & V_25 -> V_25 ) ; V_20 ; V_20 = F_10 ( V_20 ) ) {
V_73 = F_3 ( V_20 , struct V_1 , V_5 ) ;
F_27 ( & log -> V_76 [ V_74 ] ) ;
if ( F_30 ( & V_73 -> V_51 ) ) {
F_28 ( & V_73 -> V_51 , & log -> V_77 [ V_74 ] ) ;
F_44 ( & V_73 -> V_45 ) ;
}
F_31 ( & log -> V_76 [ V_74 ] ) ;
}
F_26 ( & V_25 -> V_52 ) ;
}
void F_49 ( struct V_32 * log , T_1 V_78 )
{
struct V_1 * V_73 ;
int V_74 = V_78 % 2 ;
F_25 ( & log -> V_76 [ V_74 ] ) ;
while ( ! F_30 ( & log -> V_77 [ V_74 ] ) ) {
V_73 = F_50 ( & log -> V_77 [ V_74 ] ,
struct V_1 ,
V_51 ) ;
F_51 ( & V_73 -> V_51 ) ;
F_26 ( & log -> V_76 [ V_74 ] ) ;
F_52 ( V_73 -> V_46 , F_53 ( V_42 ,
& V_73 -> V_37 ) ) ;
F_54 ( V_73 ) ;
F_25 ( & log -> V_76 [ V_74 ] ) ;
}
F_26 ( & log -> V_76 [ V_74 ] ) ;
}
void F_55 ( struct V_32 * log , T_1 V_78 )
{
struct V_1 * V_73 ;
int V_74 = V_78 % 2 ;
F_25 ( & log -> V_76 [ V_74 ] ) ;
while ( ! F_30 ( & log -> V_77 [ V_74 ] ) ) {
V_73 = F_50 ( & log -> V_77 [ V_74 ] ,
struct V_1 ,
V_51 ) ;
F_51 ( & V_73 -> V_51 ) ;
F_26 ( & log -> V_76 [ V_74 ] ) ;
F_54 ( V_73 ) ;
F_25 ( & log -> V_76 [ V_74 ] ) ;
}
F_26 ( & log -> V_76 [ V_74 ] ) ;
}
void F_54 ( struct V_1 * V_2 )
{
struct V_79 * V_80 ;
struct V_61 * V_62 ;
F_56 ( V_2 -> V_13 , V_2 ) ;
if ( F_57 ( & V_2 -> V_45 ) ) {
if ( V_2 -> V_13 )
F_58 ( V_2 -> V_13 ) ;
while ( ! F_30 ( & V_2 -> V_47 ) ) {
V_80 = V_2 -> V_47 . V_81 ;
V_62 = F_59 ( V_80 , struct V_61 , V_47 ) ;
F_60 ( & V_62 -> V_47 ) ;
F_61 ( V_62 ) ;
}
F_62 ( V_34 , V_2 ) ;
}
}
void F_63 ( struct V_13 * V_13 ,
struct V_1 * V_2 )
{
struct V_24 * V_25 ;
struct V_32 * V_7 = F_16 ( V_13 ) -> V_7 ;
struct V_5 * V_8 ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
F_25 ( & V_25 -> V_52 ) ;
V_8 = & V_2 -> V_5 ;
F_64 ( V_8 , & V_25 -> V_25 ) ;
V_25 -> V_27 = NULL ;
F_19 ( V_43 , & V_2 -> V_37 ) ;
F_26 ( & V_25 -> V_52 ) ;
F_27 ( & V_7 -> V_54 ) ;
F_51 ( & V_2 -> V_48 ) ;
V_7 -> V_56 -- ;
F_65 ( V_13 , V_2 ) ;
if ( F_66 ( & V_25 -> V_25 ) &&
! F_67 ( V_13 -> V_82 , V_83 ) ) {
F_51 ( & F_16 ( V_13 ) -> V_84 ) ;
}
if ( ! V_7 -> V_56 ) {
F_27 ( & V_7 -> V_17 -> V_57 ) ;
F_29 ( F_30 ( & V_7 -> V_58 ) ) ;
F_51 ( & V_7 -> V_58 ) ;
F_31 ( & V_7 -> V_17 -> V_57 ) ;
}
F_31 ( & V_7 -> V_54 ) ;
F_37 ( & V_2 -> V_46 ) ;
}
static void F_68 ( struct V_85 * V_86 )
{
struct V_1 * V_73 ;
V_73 = F_69 ( V_86 , struct V_1 , V_87 ) ;
F_70 ( V_73 -> V_13 , V_73 , 1 ) ;
F_71 ( & V_73 -> V_50 ) ;
}
void F_72 ( struct V_32 * V_7 , int V_88 )
{
struct V_79 V_89 , V_90 ;
struct V_1 * V_73 , * V_81 ;
struct V_13 * V_13 ;
F_22 ( & V_89 ) ;
F_22 ( & V_90 ) ;
F_73 ( & V_7 -> V_17 -> V_91 ) ;
F_27 ( & V_7 -> V_54 ) ;
F_74 ( & V_7 -> V_55 , & V_89 ) ;
while ( ! F_30 ( & V_89 ) ) {
V_73 = F_50 ( & V_89 , struct V_1 ,
V_48 ) ;
F_75 ( & V_73 -> V_48 ,
& V_7 -> V_55 ) ;
V_13 = F_18 ( V_73 -> V_13 ) ;
if ( ! V_13 ) {
F_76 ( & V_7 -> V_54 ) ;
continue;
}
F_44 ( & V_73 -> V_45 ) ;
F_31 ( & V_7 -> V_54 ) ;
V_73 -> V_87 . V_92 = F_68 ;
F_28 ( & V_73 -> V_49 , & V_90 ) ;
F_77 ( & V_7 -> V_17 -> V_93 ,
& V_73 -> V_87 ) ;
F_78 () ;
F_27 ( & V_7 -> V_54 ) ;
}
F_31 ( & V_7 -> V_54 ) ;
F_79 (ordered, next, &works, work_list) {
F_51 ( & V_73 -> V_49 ) ;
F_80 ( & V_73 -> V_50 ) ;
V_13 = V_73 -> V_13 ;
F_54 ( V_73 ) ;
if ( V_88 )
F_58 ( V_13 ) ;
else
F_81 ( V_13 ) ;
F_78 () ;
}
F_82 ( & V_7 -> V_17 -> V_91 ) ;
}
void F_83 ( struct V_16 * V_17 ,
int V_88 )
{
struct V_32 * V_7 ;
struct V_79 V_89 ;
F_22 ( & V_89 ) ;
F_27 ( & V_17 -> V_57 ) ;
F_74 ( & V_17 -> V_59 , & V_89 ) ;
while ( ! F_30 ( & V_89 ) ) {
V_7 = F_50 ( & V_89 , struct V_32 ,
V_58 ) ;
V_7 = F_84 ( V_7 ) ;
F_29 ( ! V_7 ) ;
F_75 ( & V_7 -> V_58 ,
& V_17 -> V_59 ) ;
F_31 ( & V_17 -> V_57 ) ;
F_72 ( V_7 , V_88 ) ;
F_85 ( V_7 ) ;
F_27 ( & V_17 -> V_57 ) ;
}
F_31 ( & V_17 -> V_57 ) ;
}
int F_86 ( struct V_94 * V_95 ,
struct V_32 * V_7 , int V_46 )
{
struct V_96 * V_96 ;
struct V_13 * V_13 ;
struct V_97 * V_98 = V_95 -> V_99 ;
struct V_79 V_89 ;
struct V_79 V_90 ;
struct V_100 * V_86 , * V_81 ;
int V_26 = 0 ;
F_22 ( & V_89 ) ;
F_22 ( & V_90 ) ;
F_73 ( & V_7 -> V_17 -> V_91 ) ;
F_27 ( & V_7 -> V_17 -> V_57 ) ;
F_74 ( & V_98 -> V_84 , & V_89 ) ;
while ( ! F_30 ( & V_89 ) ) {
V_96 = F_59 ( V_89 . V_81 , struct V_96 ,
V_84 ) ;
V_13 = & V_96 -> V_101 ;
F_51 ( & V_96 -> V_84 ) ;
V_13 = F_18 ( V_13 ) ;
if ( ! V_13 )
continue;
if ( ! V_46 )
F_28 ( & F_16 ( V_13 ) -> V_84 ,
& V_98 -> V_84 ) ;
F_31 ( & V_7 -> V_17 -> V_57 ) ;
V_86 = F_87 ( V_13 , V_46 , 1 ) ;
if ( ! V_86 ) {
F_27 ( & V_7 -> V_17 -> V_57 ) ;
if ( F_30 ( & F_16 ( V_13 ) -> V_84 ) )
F_28 ( & V_96 -> V_84 ,
& V_89 ) ;
F_88 ( & V_89 ,
& V_98 -> V_84 ) ;
F_31 ( & V_7 -> V_17 -> V_57 ) ;
V_26 = - V_36 ;
goto V_69;
}
F_28 ( & V_86 -> V_47 , & V_90 ) ;
F_77 ( & V_7 -> V_17 -> V_93 ,
& V_86 -> V_86 ) ;
F_78 () ;
F_27 ( & V_7 -> V_17 -> V_57 ) ;
}
F_31 ( & V_7 -> V_17 -> V_57 ) ;
V_69:
F_79 (work, next, &works, list) {
F_51 ( & V_86 -> V_47 ) ;
F_89 ( V_86 ) ;
}
F_82 ( & V_7 -> V_17 -> V_91 ) ;
return V_26 ;
}
void F_70 ( struct V_13 * V_13 ,
struct V_1 * V_2 ,
int V_46 )
{
T_1 V_28 = V_2 -> V_3 ;
T_1 V_102 = V_28 + V_2 -> V_4 - 1 ;
F_90 ( V_13 , V_2 ) ;
if ( ! F_53 ( V_44 , & V_2 -> V_37 ) )
F_91 ( V_13 -> V_82 , V_28 , V_102 ) ;
if ( V_46 ) {
F_52 ( V_2 -> V_46 , F_53 ( V_43 ,
& V_2 -> V_37 ) ) ;
}
}
void F_92 ( struct V_13 * V_13 , T_1 V_28 , T_1 V_4 )
{
T_1 V_102 ;
T_1 V_103 ;
struct V_1 * V_73 ;
if ( V_28 + V_4 < V_28 ) {
V_103 = F_93 ( V_104 ) ;
} else {
V_103 = V_28 + V_4 - 1 ;
if ( V_103 > F_93 ( V_104 ) )
V_103 = F_93 ( V_104 ) ;
}
F_91 ( V_13 -> V_82 , V_28 , V_103 ) ;
if ( F_53 ( V_105 ,
& F_16 ( V_13 ) -> V_106 ) )
F_91 ( V_13 -> V_82 , V_28 , V_103 ) ;
F_94 ( V_13 -> V_82 , V_28 , V_103 ) ;
V_102 = V_103 ;
while ( 1 ) {
V_73 = F_95 ( V_13 , V_102 ) ;
if ( ! V_73 )
break;
if ( V_73 -> V_3 > V_103 ) {
F_54 ( V_73 ) ;
break;
}
if ( V_73 -> V_3 + V_73 -> V_4 < V_28 ) {
F_54 ( V_73 ) ;
break;
}
F_70 ( V_13 , V_73 , 1 ) ;
V_102 = V_73 -> V_3 ;
F_54 ( V_73 ) ;
if ( V_102 == 0 || V_102 == V_28 )
break;
V_102 -- ;
}
}
struct V_1 * F_96 ( struct V_13 * V_13 ,
T_1 V_3 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
F_25 ( & V_25 -> V_52 ) ;
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 )
goto V_69;
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( ! F_12 ( V_2 , V_3 ) )
V_2 = NULL ;
if ( V_2 )
F_44 ( & V_2 -> V_45 ) ;
V_69:
F_26 ( & V_25 -> V_52 ) ;
return V_2 ;
}
struct V_1 * F_97 ( struct V_13 * V_13 ,
T_1 V_3 ,
T_1 V_4 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
F_25 ( & V_25 -> V_52 ) ;
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 ) {
V_8 = F_14 ( V_25 , V_3 + V_4 ) ;
if ( ! V_8 )
goto V_69;
}
while ( 1 ) {
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( F_13 ( V_2 , V_3 , V_4 ) )
break;
if ( V_2 -> V_3 >= V_3 + V_4 ) {
V_2 = NULL ;
break;
}
V_2 = NULL ;
V_8 = F_10 ( V_8 ) ;
if ( ! V_8 )
break;
}
V_69:
if ( V_2 )
F_44 ( & V_2 -> V_45 ) ;
F_26 ( & V_25 -> V_52 ) ;
return V_2 ;
}
struct V_1 *
F_95 ( struct V_13 * V_13 , T_1 V_3 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
F_25 ( & V_25 -> V_52 ) ;
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 )
goto V_69;
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
F_44 ( & V_2 -> V_45 ) ;
V_69:
F_26 ( & V_25 -> V_52 ) ;
return V_2 ;
}
int F_98 ( struct V_13 * V_13 , T_1 V_15 ,
struct V_1 * V_73 )
{
struct V_24 * V_25 = & F_16 ( V_13 ) -> V_33 ;
T_1 V_107 ;
T_1 V_108 ;
T_1 V_109 = F_99 ( V_13 ) ;
struct V_5 * V_8 ;
struct V_5 * V_21 = NULL ;
struct V_1 * V_22 ;
int V_26 = 1 ;
if ( V_73 )
V_15 = F_1 ( V_73 ) ;
else
V_15 = F_100 ( V_15 , F_16 ( V_13 ) -> V_7 -> V_110 ) ;
F_25 ( & V_25 -> V_52 ) ;
V_107 = F_16 ( V_13 ) -> V_107 ;
if ( V_107 > V_109 ) {
F_16 ( V_13 ) -> V_107 = V_109 ;
V_26 = 0 ;
goto V_69;
}
if ( V_107 == V_109 )
goto V_69;
if ( V_15 <= V_107 &&
( ! V_73 || V_73 -> V_111 <= V_107 ) )
goto V_69;
if ( V_73 ) {
V_8 = F_11 ( & V_73 -> V_5 ) ;
} else {
V_21 = F_14 ( V_25 , V_15 ) ;
if ( V_21 ) {
V_22 = F_3 ( V_21 , struct V_1 ,
V_5 ) ;
F_29 ( F_12 ( V_22 , V_15 ) ) ;
}
V_8 = V_21 ;
}
for (; V_8 ; V_8 = F_11 ( V_8 ) ) {
V_22 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( F_53 ( V_112 , & V_22 -> V_37 ) )
continue;
if ( V_22 -> V_3 + V_22 -> V_4 <= V_107 )
break;
if ( V_22 -> V_3 >= V_109 )
break;
if ( F_1 ( V_22 ) > V_107 ) {
if ( V_22 -> V_111 < V_15 )
V_22 -> V_111 = V_15 ;
if ( V_73 &&
V_73 -> V_111 >
V_22 -> V_111 )
V_22 -> V_111 =
V_73 -> V_111 ;
goto V_69;
}
}
V_108 = F_101 ( T_1 , V_15 , V_109 ) ;
if ( V_73 && V_73 -> V_111 > V_108 )
V_108 = F_101 ( T_1 , V_73 -> V_111 , V_109 ) ;
F_16 ( V_13 ) -> V_107 = V_108 ;
V_26 = 0 ;
V_69:
if ( V_73 )
F_19 ( V_112 , & V_73 -> V_37 ) ;
F_26 ( & V_25 -> V_52 ) ;
return V_26 ;
}
int F_102 ( struct V_13 * V_13 , T_1 V_15 , T_1 V_113 ,
T_2 * V_62 , int V_4 )
{
struct V_61 * V_114 ;
struct V_1 * V_73 ;
struct V_24 * V_25 = & F_16 ( V_13 ) -> V_33 ;
unsigned long V_115 ;
unsigned long V_116 ;
T_2 V_110 = F_16 ( V_13 ) -> V_7 -> V_110 ;
int V_74 = 0 ;
V_73 = F_96 ( V_13 , V_15 ) ;
if ( ! V_73 )
return 0 ;
F_25 ( & V_25 -> V_52 ) ;
F_103 (ordered_sum, &ordered->list, list) {
if ( V_113 >= V_114 -> V_117 &&
V_113 < V_114 -> V_117 + V_114 -> V_4 ) {
V_116 = ( V_113 - V_114 -> V_117 ) >>
V_13 -> V_18 -> V_118 ;
V_115 = V_114 -> V_4 >>
V_13 -> V_18 -> V_118 ;
V_115 = F_101 ( int , V_4 - V_74 , V_115 - V_116 ) ;
memcpy ( V_62 + V_74 , V_114 -> V_119 + V_116 ,
V_115 ) ;
V_74 += ( int ) V_115 ;
if ( V_74 == V_4 )
goto V_69;
V_113 += V_115 * V_110 ;
}
}
V_69:
F_26 ( & V_25 -> V_52 ) ;
F_54 ( V_73 ) ;
return V_74 ;
}
void F_104 ( struct V_94 * V_95 ,
struct V_32 * V_7 , struct V_13 * V_13 )
{
struct V_97 * V_98 = V_95 -> V_99 ;
T_1 V_120 ;
V_120 = F_40 ( F_16 ( V_13 ) -> V_121 , F_16 ( V_13 ) -> V_122 ) ;
if ( V_120 < V_7 -> V_17 -> V_123 )
return;
F_27 ( & V_7 -> V_17 -> V_57 ) ;
if ( F_30 ( & F_16 ( V_13 ) -> V_84 ) ) {
F_28 ( & F_16 ( V_13 ) -> V_84 ,
& V_98 -> V_84 ) ;
}
F_31 ( & V_7 -> V_17 -> V_57 ) ;
}
int T_3 F_105 ( void )
{
V_34 = F_106 ( L_5 ,
sizeof( struct V_1 ) , 0 ,
V_124 | V_125 ,
NULL ) ;
if ( ! V_34 )
return - V_36 ;
return 0 ;
}
void F_107 ( void )
{
if ( V_34 )
F_108 ( V_34 ) ;
}
