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
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 ;
V_25 = & F_16 ( V_13 ) -> V_32 ;
V_2 = F_17 ( V_33 , V_34 ) ;
if ( ! V_2 )
return - V_35 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_4 = V_4 ;
if ( ! ( F_16 ( V_13 ) -> V_36 & V_37 ) &&
! ( type == V_38 ) )
V_2 -> V_39 = V_29 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_40 = V_4 ;
V_2 -> V_13 = F_18 ( V_13 ) ;
V_2 -> V_31 = V_31 ;
if ( type != V_41 && type != V_42 )
F_19 ( type , & V_2 -> V_36 ) ;
if ( V_30 )
F_19 ( V_43 , & V_2 -> V_36 ) ;
F_20 ( & V_2 -> V_44 , 1 ) ;
F_21 ( & V_2 -> V_45 ) ;
F_22 ( & V_2 -> V_46 ) ;
F_22 ( & V_2 -> V_47 ) ;
F_22 ( & V_2 -> V_48 ) ;
F_23 ( & V_2 -> V_49 ) ;
F_22 ( & V_2 -> V_50 ) ;
F_24 ( V_13 , V_2 ) ;
F_25 ( & V_25 -> V_51 ) ;
V_8 = F_2 ( & V_25 -> V_25 , V_3 ,
& V_2 -> V_5 ) ;
if ( V_8 )
F_6 ( V_13 , - V_52 , V_3 ) ;
F_26 ( & V_25 -> V_51 ) ;
F_27 ( & F_16 ( V_13 ) -> V_7 -> V_17 -> V_53 ) ;
F_28 ( & V_2 -> V_47 ,
& F_16 ( V_13 ) -> V_7 -> V_17 -> V_54 ) ;
F_29 ( & F_16 ( V_13 ) -> V_7 -> V_17 -> V_53 ) ;
return 0 ;
}
int F_30 ( struct V_13 * V_13 , T_1 V_3 ,
T_1 V_28 , T_1 V_4 , T_1 V_29 , int type )
{
return F_15 ( V_13 , V_3 , V_28 , V_4 ,
V_29 , type , 0 ,
V_55 ) ;
}
int F_31 ( struct V_13 * V_13 , T_1 V_3 ,
T_1 V_28 , T_1 V_4 , T_1 V_29 , int type )
{
return F_15 ( V_13 , V_3 , V_28 , V_4 ,
V_29 , type , 1 ,
V_55 ) ;
}
int F_32 ( struct V_13 * V_13 , T_1 V_3 ,
T_1 V_28 , T_1 V_4 , T_1 V_29 ,
int type , int V_31 )
{
return F_15 ( V_13 , V_3 , V_28 , V_4 ,
V_29 , type , 0 ,
V_31 ) ;
}
void F_33 ( struct V_13 * V_13 ,
struct V_1 * V_2 ,
struct V_56 * V_57 )
{
struct V_24 * V_25 ;
V_25 = & F_16 ( V_13 ) -> V_32 ;
F_25 ( & V_25 -> V_51 ) ;
F_28 ( & V_57 -> V_46 , & V_2 -> V_46 ) ;
F_34 ( V_2 -> V_39 < V_57 -> V_4 ) ;
V_2 -> V_39 -= V_57 -> V_4 ;
if ( V_2 -> V_39 == 0 )
F_35 ( & V_2 -> V_45 ) ;
F_26 ( & V_25 -> V_51 ) ;
}
int F_36 ( struct V_13 * V_13 ,
struct V_1 * * V_58 ,
T_1 * V_3 , T_1 V_59 , int V_60 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
int V_26 ;
unsigned long V_36 ;
T_1 V_61 ;
T_1 V_62 ;
T_1 V_63 ;
V_25 = & F_16 ( V_13 ) -> V_32 ;
F_37 ( & V_25 -> V_51 , V_36 ) ;
V_8 = F_14 ( V_25 , * V_3 ) ;
if ( ! V_8 ) {
V_26 = 1 ;
goto V_64;
}
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( ! F_12 ( V_2 , * V_3 ) ) {
V_26 = 1 ;
goto V_64;
}
V_62 = F_38 ( * V_3 , V_2 -> V_3 ) ;
V_61 = F_39 ( * V_3 + V_59 , V_2 -> V_3 +
V_2 -> V_4 ) ;
* V_3 = V_61 ;
if ( V_62 > V_61 ) {
F_40 ( V_65 L_3 ,
( unsigned long long ) V_62 ,
( unsigned long long ) V_61 ) ;
}
V_63 = V_61 - V_62 ;
if ( V_63 > V_2 -> V_40 ) {
F_40 ( V_65 L_4 ,
( unsigned long long ) V_2 -> V_40 ,
( unsigned long long ) V_63 ) ;
}
V_2 -> V_40 -= V_63 ;
if ( ! V_60 )
F_19 ( V_66 , & V_2 -> V_36 ) ;
if ( V_2 -> V_40 == 0 )
V_26 = F_41 ( V_41 , & V_2 -> V_36 ) ;
else
V_26 = 1 ;
V_64:
if ( ! V_26 && V_58 && V_2 ) {
* V_58 = V_2 ;
F_42 ( & V_2 -> V_44 ) ;
}
F_43 ( & V_25 -> V_51 , V_36 ) ;
return V_26 == 0 ;
}
int F_44 ( struct V_13 * V_13 ,
struct V_1 * * V_58 ,
T_1 V_3 , T_1 V_59 , int V_60 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
unsigned long V_36 ;
int V_26 ;
V_25 = & F_16 ( V_13 ) -> V_32 ;
F_37 ( & V_25 -> V_51 , V_36 ) ;
if ( V_58 && * V_58 ) {
V_2 = * V_58 ;
goto V_67;
}
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 ) {
V_26 = 1 ;
goto V_64;
}
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
V_67:
if ( ! F_12 ( V_2 , V_3 ) ) {
V_26 = 1 ;
goto V_64;
}
if ( V_59 > V_2 -> V_40 ) {
F_40 ( V_65 L_4 ,
( unsigned long long ) V_2 -> V_40 ,
( unsigned long long ) V_59 ) ;
}
V_2 -> V_40 -= V_59 ;
if ( ! V_60 )
F_19 ( V_66 , & V_2 -> V_36 ) ;
if ( V_2 -> V_40 == 0 )
V_26 = F_41 ( V_41 , & V_2 -> V_36 ) ;
else
V_26 = 1 ;
V_64:
if ( ! V_26 && V_58 && V_2 ) {
* V_58 = V_2 ;
F_42 ( & V_2 -> V_44 ) ;
}
F_43 ( & V_25 -> V_51 , V_36 ) ;
return V_26 == 0 ;
}
void F_45 ( struct V_68 * log , struct V_13 * V_13 )
{
struct V_24 * V_25 ;
struct V_1 * V_69 ;
struct V_5 * V_20 ;
int V_70 = log -> V_71 % 2 ;
V_25 = & F_16 ( V_13 ) -> V_32 ;
F_25 ( & V_25 -> V_51 ) ;
for ( V_20 = F_46 ( & V_25 -> V_25 ) ; V_20 ; V_20 = F_10 ( V_20 ) ) {
V_69 = F_3 ( V_20 , struct V_1 , V_5 ) ;
F_27 ( & log -> V_72 [ V_70 ] ) ;
if ( F_47 ( & V_69 -> V_50 ) ) {
F_28 ( & V_69 -> V_50 , & log -> V_73 [ V_70 ] ) ;
F_42 ( & V_69 -> V_44 ) ;
}
F_29 ( & log -> V_72 [ V_70 ] ) ;
}
F_26 ( & V_25 -> V_51 ) ;
}
void F_48 ( struct V_68 * log , T_1 V_74 )
{
struct V_1 * V_69 ;
int V_70 = V_74 % 2 ;
F_25 ( & log -> V_72 [ V_70 ] ) ;
while ( ! F_47 ( & log -> V_73 [ V_70 ] ) ) {
V_69 = F_49 ( & log -> V_73 [ V_70 ] ,
struct V_1 ,
V_50 ) ;
F_50 ( & V_69 -> V_50 ) ;
F_26 ( & log -> V_72 [ V_70 ] ) ;
F_51 ( V_69 -> V_45 , F_52 ( V_41 ,
& V_69 -> V_36 ) ) ;
F_53 ( V_69 ) ;
F_25 ( & log -> V_72 [ V_70 ] ) ;
}
F_26 ( & log -> V_72 [ V_70 ] ) ;
}
void F_54 ( struct V_68 * log , T_1 V_74 )
{
struct V_1 * V_69 ;
int V_70 = V_74 % 2 ;
F_25 ( & log -> V_72 [ V_70 ] ) ;
while ( ! F_47 ( & log -> V_73 [ V_70 ] ) ) {
V_69 = F_49 ( & log -> V_73 [ V_70 ] ,
struct V_1 ,
V_50 ) ;
F_50 ( & V_69 -> V_50 ) ;
F_26 ( & log -> V_72 [ V_70 ] ) ;
F_53 ( V_69 ) ;
F_25 ( & log -> V_72 [ V_70 ] ) ;
}
F_26 ( & log -> V_72 [ V_70 ] ) ;
}
void F_53 ( struct V_1 * V_2 )
{
struct V_75 * V_76 ;
struct V_56 * V_57 ;
F_55 ( V_2 -> V_13 , V_2 ) ;
if ( F_56 ( & V_2 -> V_44 ) ) {
if ( V_2 -> V_13 )
F_57 ( V_2 -> V_13 ) ;
while ( ! F_47 ( & V_2 -> V_46 ) ) {
V_76 = V_2 -> V_46 . V_77 ;
V_57 = F_58 ( V_76 , struct V_56 , V_46 ) ;
F_59 ( & V_57 -> V_46 ) ;
F_60 ( V_57 ) ;
}
F_61 ( V_33 , V_2 ) ;
}
}
void F_62 ( struct V_13 * V_13 ,
struct V_1 * V_2 )
{
struct V_24 * V_25 ;
struct V_68 * V_7 = F_16 ( V_13 ) -> V_7 ;
struct V_5 * V_8 ;
V_25 = & F_16 ( V_13 ) -> V_32 ;
F_25 ( & V_25 -> V_51 ) ;
V_8 = & V_2 -> V_5 ;
F_63 ( V_8 , & V_25 -> V_25 ) ;
V_25 -> V_27 = NULL ;
F_19 ( V_42 , & V_2 -> V_36 ) ;
F_26 ( & V_25 -> V_51 ) ;
F_27 ( & V_7 -> V_17 -> V_53 ) ;
F_50 ( & V_2 -> V_47 ) ;
F_64 ( V_13 , V_2 ) ;
if ( F_65 ( & V_25 -> V_25 ) &&
! F_66 ( V_13 -> V_78 , V_79 ) ) {
F_50 ( & F_16 ( V_13 ) -> V_80 ) ;
}
F_29 ( & V_7 -> V_17 -> V_53 ) ;
F_35 ( & V_2 -> V_45 ) ;
}
static void F_67 ( struct V_81 * V_82 )
{
struct V_1 * V_69 ;
V_69 = F_68 ( V_82 , struct V_1 , V_83 ) ;
F_69 ( V_69 -> V_13 , V_69 , 1 ) ;
F_70 ( & V_69 -> V_49 ) ;
}
void F_71 ( struct V_68 * V_7 , int V_84 )
{
struct V_75 V_85 , V_86 ;
struct V_75 * V_76 ;
struct V_1 * V_69 , * V_77 ;
struct V_13 * V_13 ;
F_22 ( & V_85 ) ;
F_22 ( & V_86 ) ;
F_72 ( & V_7 -> V_17 -> V_87 ) ;
F_27 ( & V_7 -> V_17 -> V_53 ) ;
F_73 ( & V_7 -> V_17 -> V_54 , & V_85 ) ;
while ( ! F_47 ( & V_85 ) ) {
V_76 = V_85 . V_77 ;
V_69 = F_58 ( V_76 , struct V_1 ,
V_47 ) ;
F_50 ( & V_69 -> V_47 ) ;
F_42 ( & V_69 -> V_44 ) ;
V_13 = F_18 ( V_69 -> V_13 ) ;
F_29 ( & V_7 -> V_17 -> V_53 ) ;
if ( V_13 ) {
V_69 -> V_83 . V_88 = F_67 ;
F_28 ( & V_69 -> V_48 , & V_86 ) ;
F_74 ( & V_7 -> V_17 -> V_89 ,
& V_69 -> V_83 ) ;
} else {
F_53 ( V_69 ) ;
}
F_75 () ;
F_27 ( & V_7 -> V_17 -> V_53 ) ;
}
F_29 ( & V_7 -> V_17 -> V_53 ) ;
F_76 (ordered, next, &works, work_list) {
F_50 ( & V_69 -> V_48 ) ;
F_77 ( & V_69 -> V_49 ) ;
V_13 = V_69 -> V_13 ;
F_53 ( V_69 ) ;
if ( V_84 )
F_57 ( V_13 ) ;
else
F_78 ( V_13 ) ;
F_75 () ;
}
F_79 ( & V_7 -> V_17 -> V_87 ) ;
}
int F_80 ( struct V_90 * V_91 ,
struct V_68 * V_7 , int V_45 )
{
struct V_92 * V_92 ;
struct V_13 * V_13 ;
struct V_93 * V_94 = V_91 -> V_95 ;
struct V_75 V_85 ;
struct V_75 V_86 ;
struct V_96 * V_82 , * V_77 ;
int V_26 = 0 ;
F_22 ( & V_85 ) ;
F_22 ( & V_86 ) ;
F_72 ( & V_7 -> V_17 -> V_87 ) ;
F_27 ( & V_7 -> V_17 -> V_53 ) ;
F_73 ( & V_94 -> V_80 , & V_85 ) ;
while ( ! F_47 ( & V_85 ) ) {
V_92 = F_58 ( V_85 . V_77 , struct V_92 ,
V_80 ) ;
V_13 = & V_92 -> V_97 ;
F_50 ( & V_92 -> V_80 ) ;
V_13 = F_18 ( V_13 ) ;
if ( ! V_13 )
continue;
if ( ! V_45 )
F_28 ( & F_16 ( V_13 ) -> V_80 ,
& V_94 -> V_80 ) ;
F_29 ( & V_7 -> V_17 -> V_53 ) ;
V_82 = F_81 ( V_13 , V_45 , 1 ) ;
if ( ! V_82 ) {
F_27 ( & V_7 -> V_17 -> V_53 ) ;
if ( F_47 ( & F_16 ( V_13 ) -> V_80 ) )
F_28 ( & V_92 -> V_80 ,
& V_85 ) ;
F_82 ( & V_85 ,
& V_94 -> V_80 ) ;
F_29 ( & V_7 -> V_17 -> V_53 ) ;
V_26 = - V_35 ;
goto V_64;
}
F_28 ( & V_82 -> V_46 , & V_86 ) ;
F_74 ( & V_7 -> V_17 -> V_89 ,
& V_82 -> V_82 ) ;
F_75 () ;
F_27 ( & V_7 -> V_17 -> V_53 ) ;
}
F_29 ( & V_7 -> V_17 -> V_53 ) ;
V_64:
F_76 (work, next, &works, list) {
F_50 ( & V_82 -> V_46 ) ;
F_83 ( V_82 ) ;
}
F_79 ( & V_7 -> V_17 -> V_87 ) ;
return V_26 ;
}
void F_69 ( struct V_13 * V_13 ,
struct V_1 * V_2 ,
int V_45 )
{
T_1 V_28 = V_2 -> V_3 ;
T_1 V_98 = V_28 + V_2 -> V_4 - 1 ;
F_84 ( V_13 , V_2 ) ;
if ( ! F_52 ( V_43 , & V_2 -> V_36 ) )
F_85 ( V_13 -> V_78 , V_28 , V_98 ) ;
if ( V_45 ) {
F_51 ( V_2 -> V_45 , F_52 ( V_42 ,
& V_2 -> V_36 ) ) ;
}
}
void F_86 ( struct V_13 * V_13 , T_1 V_28 , T_1 V_4 )
{
T_1 V_98 ;
T_1 V_99 ;
struct V_1 * V_69 ;
if ( V_28 + V_4 < V_28 ) {
V_99 = F_87 ( V_100 ) ;
} else {
V_99 = V_28 + V_4 - 1 ;
if ( V_99 > F_87 ( V_100 ) )
V_99 = F_87 ( V_100 ) ;
}
F_85 ( V_13 -> V_78 , V_28 , V_99 ) ;
if ( F_52 ( V_101 ,
& F_16 ( V_13 ) -> V_102 ) )
F_85 ( V_13 -> V_78 , V_28 , V_99 ) ;
F_88 ( V_13 -> V_78 , V_28 , V_99 ) ;
V_98 = V_99 ;
while ( 1 ) {
V_69 = F_89 ( V_13 , V_98 ) ;
if ( ! V_69 )
break;
if ( V_69 -> V_3 > V_99 ) {
F_53 ( V_69 ) ;
break;
}
if ( V_69 -> V_3 + V_69 -> V_4 < V_28 ) {
F_53 ( V_69 ) ;
break;
}
F_69 ( V_13 , V_69 , 1 ) ;
V_98 = V_69 -> V_3 ;
F_53 ( V_69 ) ;
if ( V_98 == 0 || V_98 == V_28 )
break;
V_98 -- ;
}
}
struct V_1 * F_90 ( struct V_13 * V_13 ,
T_1 V_3 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
V_25 = & F_16 ( V_13 ) -> V_32 ;
F_25 ( & V_25 -> V_51 ) ;
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 )
goto V_64;
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( ! F_12 ( V_2 , V_3 ) )
V_2 = NULL ;
if ( V_2 )
F_42 ( & V_2 -> V_44 ) ;
V_64:
F_26 ( & V_25 -> V_51 ) ;
return V_2 ;
}
struct V_1 * F_91 ( struct V_13 * V_13 ,
T_1 V_3 ,
T_1 V_4 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
V_25 = & F_16 ( V_13 ) -> V_32 ;
F_25 ( & V_25 -> V_51 ) ;
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 ) {
V_8 = F_14 ( V_25 , V_3 + V_4 ) ;
if ( ! V_8 )
goto V_64;
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
V_64:
if ( V_2 )
F_42 ( & V_2 -> V_44 ) ;
F_26 ( & V_25 -> V_51 ) ;
return V_2 ;
}
struct V_1 *
F_89 ( struct V_13 * V_13 , T_1 V_3 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
V_25 = & F_16 ( V_13 ) -> V_32 ;
F_25 ( & V_25 -> V_51 ) ;
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 )
goto V_64;
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
F_42 ( & V_2 -> V_44 ) ;
V_64:
F_26 ( & V_25 -> V_51 ) ;
return V_2 ;
}
int F_92 ( struct V_13 * V_13 , T_1 V_15 ,
struct V_1 * V_69 )
{
struct V_24 * V_25 = & F_16 ( V_13 ) -> V_32 ;
T_1 V_103 ;
T_1 V_104 ;
T_1 V_105 = F_93 ( V_13 ) ;
struct V_5 * V_8 ;
struct V_5 * V_21 = NULL ;
struct V_1 * V_22 ;
int V_26 = 1 ;
if ( V_69 )
V_15 = F_1 ( V_69 ) ;
else
V_15 = F_94 ( V_15 , F_16 ( V_13 ) -> V_7 -> V_106 ) ;
F_25 ( & V_25 -> V_51 ) ;
V_103 = F_16 ( V_13 ) -> V_103 ;
if ( V_103 > V_105 ) {
F_16 ( V_13 ) -> V_103 = V_105 ;
V_26 = 0 ;
goto V_64;
}
if ( V_103 == V_105 )
goto V_64;
if ( V_15 <= V_103 &&
( ! V_69 || V_69 -> V_107 <= V_103 ) )
goto V_64;
if ( V_69 ) {
V_8 = F_11 ( & V_69 -> V_5 ) ;
} else {
V_21 = F_14 ( V_25 , V_15 ) ;
if ( V_21 ) {
V_22 = F_3 ( V_21 , struct V_1 ,
V_5 ) ;
F_95 ( F_12 ( V_22 , V_15 ) ) ;
}
V_8 = V_21 ;
}
for (; V_8 ; V_8 = F_11 ( V_8 ) ) {
V_22 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( F_52 ( V_108 , & V_22 -> V_36 ) )
continue;
if ( V_22 -> V_3 + V_22 -> V_4 <= V_103 )
break;
if ( V_22 -> V_3 >= V_105 )
break;
if ( F_1 ( V_22 ) > V_103 ) {
if ( V_22 -> V_107 < V_15 )
V_22 -> V_107 = V_15 ;
if ( V_69 &&
V_69 -> V_107 >
V_22 -> V_107 )
V_22 -> V_107 =
V_69 -> V_107 ;
goto V_64;
}
}
V_104 = F_96 ( T_1 , V_15 , V_105 ) ;
if ( V_69 && V_69 -> V_107 > V_104 )
V_104 = F_96 ( T_1 , V_69 -> V_107 , V_105 ) ;
F_16 ( V_13 ) -> V_103 = V_104 ;
V_26 = 0 ;
V_64:
if ( V_69 )
F_19 ( V_108 , & V_69 -> V_36 ) ;
F_26 ( & V_25 -> V_51 ) ;
return V_26 ;
}
int F_97 ( struct V_13 * V_13 , T_1 V_15 , T_1 V_109 ,
T_2 * V_57 , int V_4 )
{
struct V_56 * V_110 ;
struct V_111 * V_112 ;
struct V_1 * V_69 ;
struct V_24 * V_25 = & F_16 ( V_13 ) -> V_32 ;
unsigned long V_113 ;
unsigned long V_114 ;
T_2 V_106 = F_16 ( V_13 ) -> V_7 -> V_106 ;
int V_70 = 0 ;
V_69 = F_90 ( V_13 , V_15 ) ;
if ( ! V_69 )
return 0 ;
F_25 ( & V_25 -> V_51 ) ;
F_98 (ordered_sum, &ordered->list, list) {
if ( V_109 >= V_110 -> V_115 &&
V_109 < V_110 -> V_115 + V_110 -> V_4 ) {
V_114 = ( V_109 - V_110 -> V_115 ) >>
V_13 -> V_18 -> V_116 ;
V_112 = V_110 -> V_117 + V_114 ;
V_113 = V_110 -> V_4 >>
V_13 -> V_18 -> V_116 ;
for (; V_114 < V_113 ; V_114 ++ ) {
if ( V_112 [ V_114 ] . V_115 == V_109 ) {
V_57 [ V_70 ] = V_112 [ V_114 ] . V_57 ;
V_70 ++ ;
if ( V_70 == V_4 )
goto V_64;
V_109 += V_106 ;
}
}
}
}
V_64:
F_26 ( & V_25 -> V_51 ) ;
F_53 ( V_69 ) ;
return V_70 ;
}
void F_99 ( struct V_90 * V_91 ,
struct V_68 * V_7 , struct V_13 * V_13 )
{
struct V_93 * V_94 = V_91 -> V_95 ;
T_1 V_118 ;
V_118 = F_38 ( F_16 ( V_13 ) -> V_119 , F_16 ( V_13 ) -> V_120 ) ;
if ( V_118 < V_7 -> V_17 -> V_121 )
return;
F_27 ( & V_7 -> V_17 -> V_53 ) ;
if ( F_47 ( & F_16 ( V_13 ) -> V_80 ) ) {
F_28 ( & F_16 ( V_13 ) -> V_80 ,
& V_94 -> V_80 ) ;
}
F_29 ( & V_7 -> V_17 -> V_53 ) ;
}
int T_3 F_100 ( void )
{
V_33 = F_101 ( L_5 ,
sizeof( struct V_1 ) , 0 ,
V_122 | V_123 ,
NULL ) ;
if ( ! V_33 )
return - V_35 ;
return 0 ;
}
void F_102 ( void )
{
if ( V_33 )
F_103 ( V_33 ) ;
}
