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
V_2 -> V_29 = V_29 ;
V_2 -> V_36 = V_4 ;
V_2 -> V_13 = F_18 ( V_13 ) ;
V_2 -> V_31 = V_31 ;
if ( type != V_37 && type != V_38 )
F_19 ( type , & V_2 -> V_39 ) ;
if ( V_30 )
F_19 ( V_40 , & V_2 -> V_39 ) ;
F_20 ( & V_2 -> V_41 , 1 ) ;
F_21 ( & V_2 -> V_42 ) ;
F_22 ( & V_2 -> V_43 ) ;
F_22 ( & V_2 -> V_44 ) ;
F_22 ( & V_2 -> V_45 ) ;
F_23 ( & V_2 -> V_46 ) ;
F_24 ( V_13 , V_2 ) ;
F_25 ( & V_25 -> V_47 ) ;
V_8 = F_2 ( & V_25 -> V_25 , V_3 ,
& V_2 -> V_5 ) ;
if ( V_8 )
F_6 ( V_13 , - V_48 , V_3 ) ;
F_26 ( & V_25 -> V_47 ) ;
F_27 ( & F_16 ( V_13 ) -> V_7 -> V_17 -> V_49 ) ;
F_28 ( & V_2 -> V_44 ,
& F_16 ( V_13 ) -> V_7 -> V_17 -> V_50 ) ;
F_29 ( & F_16 ( V_13 ) -> V_7 -> V_17 -> V_49 ) ;
return 0 ;
}
int F_30 ( struct V_13 * V_13 , T_1 V_3 ,
T_1 V_28 , T_1 V_4 , T_1 V_29 , int type )
{
return F_15 ( V_13 , V_3 , V_28 , V_4 ,
V_29 , type , 0 ,
V_51 ) ;
}
int F_31 ( struct V_13 * V_13 , T_1 V_3 ,
T_1 V_28 , T_1 V_4 , T_1 V_29 , int type )
{
return F_15 ( V_13 , V_3 , V_28 , V_4 ,
V_29 , type , 1 ,
V_51 ) ;
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
struct V_52 * V_53 )
{
struct V_24 * V_25 ;
V_25 = & F_16 ( V_13 ) -> V_32 ;
F_25 ( & V_25 -> V_47 ) ;
F_28 ( & V_53 -> V_43 , & V_2 -> V_43 ) ;
F_26 ( & V_25 -> V_47 ) ;
}
int F_34 ( struct V_13 * V_13 ,
struct V_1 * * V_54 ,
T_1 * V_3 , T_1 V_55 , int V_56 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
int V_26 ;
unsigned long V_39 ;
T_1 V_57 ;
T_1 V_58 ;
T_1 V_59 ;
V_25 = & F_16 ( V_13 ) -> V_32 ;
F_35 ( & V_25 -> V_47 , V_39 ) ;
V_8 = F_14 ( V_25 , * V_3 ) ;
if ( ! V_8 ) {
V_26 = 1 ;
goto V_60;
}
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( ! F_12 ( V_2 , * V_3 ) ) {
V_26 = 1 ;
goto V_60;
}
V_58 = F_36 ( * V_3 , V_2 -> V_3 ) ;
V_57 = F_37 ( * V_3 + V_55 , V_2 -> V_3 +
V_2 -> V_4 ) ;
* V_3 = V_57 ;
if ( V_58 > V_57 ) {
F_38 ( V_61 L_3 ,
( unsigned long long ) V_58 ,
( unsigned long long ) V_57 ) ;
}
V_59 = V_57 - V_58 ;
if ( V_59 > V_2 -> V_36 ) {
F_38 ( V_61 L_4 ,
( unsigned long long ) V_2 -> V_36 ,
( unsigned long long ) V_59 ) ;
}
V_2 -> V_36 -= V_59 ;
if ( ! V_56 )
F_19 ( V_62 , & V_2 -> V_39 ) ;
if ( V_2 -> V_36 == 0 )
V_26 = F_39 ( V_37 , & V_2 -> V_39 ) ;
else
V_26 = 1 ;
V_60:
if ( ! V_26 && V_54 && V_2 ) {
* V_54 = V_2 ;
F_40 ( & V_2 -> V_41 ) ;
}
F_41 ( & V_25 -> V_47 , V_39 ) ;
return V_26 == 0 ;
}
int F_42 ( struct V_13 * V_13 ,
struct V_1 * * V_54 ,
T_1 V_3 , T_1 V_55 , int V_56 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
unsigned long V_39 ;
int V_26 ;
V_25 = & F_16 ( V_13 ) -> V_32 ;
F_35 ( & V_25 -> V_47 , V_39 ) ;
if ( V_54 && * V_54 ) {
V_2 = * V_54 ;
goto V_63;
}
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 ) {
V_26 = 1 ;
goto V_60;
}
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
V_63:
if ( ! F_12 ( V_2 , V_3 ) ) {
V_26 = 1 ;
goto V_60;
}
if ( V_55 > V_2 -> V_36 ) {
F_38 ( V_61 L_4 ,
( unsigned long long ) V_2 -> V_36 ,
( unsigned long long ) V_55 ) ;
}
V_2 -> V_36 -= V_55 ;
if ( ! V_56 )
F_19 ( V_62 , & V_2 -> V_39 ) ;
if ( V_2 -> V_36 == 0 )
V_26 = F_39 ( V_37 , & V_2 -> V_39 ) ;
else
V_26 = 1 ;
V_60:
if ( ! V_26 && V_54 && V_2 ) {
* V_54 = V_2 ;
F_40 ( & V_2 -> V_41 ) ;
}
F_41 ( & V_25 -> V_47 , V_39 ) ;
return V_26 == 0 ;
}
void F_43 ( struct V_1 * V_2 )
{
struct V_64 * V_65 ;
struct V_52 * V_53 ;
F_44 ( V_2 -> V_13 , V_2 ) ;
if ( F_45 ( & V_2 -> V_41 ) ) {
if ( V_2 -> V_13 )
F_46 ( V_2 -> V_13 ) ;
while ( ! F_47 ( & V_2 -> V_43 ) ) {
V_65 = V_2 -> V_43 . V_66 ;
V_53 = F_48 ( V_65 , struct V_52 , V_43 ) ;
F_49 ( & V_53 -> V_43 ) ;
F_50 ( V_53 ) ;
}
F_51 ( V_33 , V_2 ) ;
}
}
void F_52 ( struct V_13 * V_13 ,
struct V_1 * V_2 )
{
struct V_24 * V_25 ;
struct V_67 * V_7 = F_16 ( V_13 ) -> V_7 ;
struct V_5 * V_8 ;
V_25 = & F_16 ( V_13 ) -> V_32 ;
F_25 ( & V_25 -> V_47 ) ;
V_8 = & V_2 -> V_5 ;
F_53 ( V_8 , & V_25 -> V_25 ) ;
V_25 -> V_27 = NULL ;
F_19 ( V_38 , & V_2 -> V_39 ) ;
F_26 ( & V_25 -> V_47 ) ;
F_27 ( & V_7 -> V_17 -> V_49 ) ;
F_54 ( & V_2 -> V_44 ) ;
F_55 ( V_13 , V_2 ) ;
if ( F_56 ( & V_25 -> V_25 ) &&
! F_57 ( V_13 -> V_68 , V_69 ) ) {
F_54 ( & F_16 ( V_13 ) -> V_70 ) ;
}
F_29 ( & V_7 -> V_17 -> V_49 ) ;
F_58 ( & V_2 -> V_42 ) ;
}
static void F_59 ( struct V_71 * V_72 )
{
struct V_1 * V_73 ;
V_73 = F_60 ( V_72 , struct V_1 , V_74 ) ;
F_61 ( V_73 -> V_13 , V_73 , 1 ) ;
F_62 ( & V_73 -> V_46 ) ;
}
void F_63 ( struct V_67 * V_7 , int V_75 )
{
struct V_64 V_76 , V_77 ;
struct V_64 * V_65 ;
struct V_1 * V_73 , * V_66 ;
struct V_13 * V_13 ;
F_22 ( & V_76 ) ;
F_22 ( & V_77 ) ;
F_27 ( & V_7 -> V_17 -> V_49 ) ;
F_64 ( & V_7 -> V_17 -> V_50 , & V_76 ) ;
while ( ! F_47 ( & V_76 ) ) {
V_65 = V_76 . V_66 ;
V_73 = F_48 ( V_65 , struct V_1 ,
V_44 ) ;
F_54 ( & V_73 -> V_44 ) ;
F_40 ( & V_73 -> V_41 ) ;
V_13 = F_18 ( V_73 -> V_13 ) ;
F_29 ( & V_7 -> V_17 -> V_49 ) ;
if ( V_13 ) {
V_73 -> V_74 . V_78 = F_59 ;
F_28 ( & V_73 -> V_45 , & V_77 ) ;
F_65 ( & V_7 -> V_17 -> V_79 ,
& V_73 -> V_74 ) ;
} else {
F_43 ( V_73 ) ;
}
F_66 () ;
F_27 ( & V_7 -> V_17 -> V_49 ) ;
}
F_29 ( & V_7 -> V_17 -> V_49 ) ;
F_67 (ordered, next, &works, work_list) {
F_54 ( & V_73 -> V_45 ) ;
F_68 ( & V_73 -> V_46 ) ;
V_13 = V_73 -> V_13 ;
F_43 ( V_73 ) ;
if ( V_75 )
F_46 ( V_13 ) ;
else
F_69 ( V_13 ) ;
F_66 () ;
}
}
int F_70 ( struct V_67 * V_7 , int V_42 )
{
struct V_80 * V_80 ;
struct V_13 * V_13 ;
struct V_64 V_76 ;
struct V_64 V_77 ;
struct V_81 * V_72 , * V_66 ;
int V_26 = 0 ;
F_22 ( & V_76 ) ;
F_22 ( & V_77 ) ;
F_71 ( & V_7 -> V_17 -> V_82 ) ;
F_27 ( & V_7 -> V_17 -> V_49 ) ;
V_83:
F_64 ( & V_7 -> V_17 -> V_70 , & V_76 ) ;
while ( ! F_47 ( & V_76 ) ) {
V_80 = F_48 ( V_76 . V_66 , struct V_80 ,
V_70 ) ;
V_13 = & V_80 -> V_84 ;
F_54 ( & V_80 -> V_70 ) ;
V_13 = F_18 ( V_13 ) ;
if ( ! V_42 && V_13 ) {
F_28 ( & F_16 ( V_13 ) -> V_70 ,
& V_7 -> V_17 -> V_70 ) ;
}
if ( ! V_13 )
continue;
F_29 ( & V_7 -> V_17 -> V_49 ) ;
V_72 = F_72 ( V_13 , V_42 , 1 ) ;
if ( ! V_72 ) {
if ( F_47 ( & F_16 ( V_13 ) -> V_70 ) )
F_28 ( & V_80 -> V_70 ,
& V_76 ) ;
F_27 ( & V_7 -> V_17 -> V_49 ) ;
F_73 ( & V_76 ,
& V_7 -> V_17 -> V_70 ) ;
F_29 ( & V_7 -> V_17 -> V_49 ) ;
V_26 = - V_35 ;
goto V_60;
}
F_28 ( & V_72 -> V_43 , & V_77 ) ;
F_65 ( & V_7 -> V_17 -> V_79 ,
& V_72 -> V_72 ) ;
F_66 () ;
F_27 ( & V_7 -> V_17 -> V_49 ) ;
}
if ( V_42 && ! F_47 ( & V_7 -> V_17 -> V_70 ) )
goto V_83;
F_29 ( & V_7 -> V_17 -> V_49 ) ;
V_60:
F_67 (work, next, &works, list) {
F_54 ( & V_72 -> V_43 ) ;
F_74 ( V_72 ) ;
}
F_75 ( & V_7 -> V_17 -> V_82 ) ;
return V_26 ;
}
void F_61 ( struct V_13 * V_13 ,
struct V_1 * V_2 ,
int V_42 )
{
T_1 V_28 = V_2 -> V_3 ;
T_1 V_85 = V_28 + V_2 -> V_4 - 1 ;
F_76 ( V_13 , V_2 ) ;
if ( ! F_77 ( V_40 , & V_2 -> V_39 ) )
F_78 ( V_13 -> V_68 , V_28 , V_85 ) ;
if ( V_42 ) {
F_79 ( V_2 -> V_42 , F_77 ( V_38 ,
& V_2 -> V_39 ) ) ;
}
}
void F_80 ( struct V_13 * V_13 , T_1 V_28 , T_1 V_4 )
{
T_1 V_85 ;
T_1 V_86 ;
struct V_1 * V_73 ;
if ( V_28 + V_4 < V_28 ) {
V_86 = F_81 ( V_87 ) ;
} else {
V_86 = V_28 + V_4 - 1 ;
if ( V_86 > F_81 ( V_87 ) )
V_86 = F_81 ( V_87 ) ;
}
F_78 ( V_13 -> V_68 , V_28 , V_86 ) ;
if ( F_77 ( V_88 ,
& F_16 ( V_13 ) -> V_89 ) )
F_78 ( V_13 -> V_68 , V_28 , V_86 ) ;
F_82 ( V_13 -> V_68 , V_28 , V_86 ) ;
V_85 = V_86 ;
while ( 1 ) {
V_73 = F_83 ( V_13 , V_85 ) ;
if ( ! V_73 )
break;
if ( V_73 -> V_3 > V_86 ) {
F_43 ( V_73 ) ;
break;
}
if ( V_73 -> V_3 + V_73 -> V_4 < V_28 ) {
F_43 ( V_73 ) ;
break;
}
F_61 ( V_13 , V_73 , 1 ) ;
V_85 = V_73 -> V_3 ;
F_43 ( V_73 ) ;
if ( V_85 == 0 || V_85 == V_28 )
break;
V_85 -- ;
}
}
struct V_1 * F_84 ( struct V_13 * V_13 ,
T_1 V_3 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
V_25 = & F_16 ( V_13 ) -> V_32 ;
F_25 ( & V_25 -> V_47 ) ;
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 )
goto V_60;
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( ! F_12 ( V_2 , V_3 ) )
V_2 = NULL ;
if ( V_2 )
F_40 ( & V_2 -> V_41 ) ;
V_60:
F_26 ( & V_25 -> V_47 ) ;
return V_2 ;
}
struct V_1 * F_85 ( struct V_13 * V_13 ,
T_1 V_3 ,
T_1 V_4 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
V_25 = & F_16 ( V_13 ) -> V_32 ;
F_25 ( & V_25 -> V_47 ) ;
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 ) {
V_8 = F_14 ( V_25 , V_3 + V_4 ) ;
if ( ! V_8 )
goto V_60;
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
V_60:
if ( V_2 )
F_40 ( & V_2 -> V_41 ) ;
F_26 ( & V_25 -> V_47 ) ;
return V_2 ;
}
struct V_1 *
F_83 ( struct V_13 * V_13 , T_1 V_3 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
V_25 = & F_16 ( V_13 ) -> V_32 ;
F_25 ( & V_25 -> V_47 ) ;
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 )
goto V_60;
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
F_40 ( & V_2 -> V_41 ) ;
V_60:
F_26 ( & V_25 -> V_47 ) ;
return V_2 ;
}
int F_86 ( struct V_13 * V_13 , T_1 V_15 ,
struct V_1 * V_73 )
{
struct V_24 * V_25 = & F_16 ( V_13 ) -> V_32 ;
T_1 V_90 ;
T_1 V_91 ;
T_1 V_92 = F_87 ( V_13 ) ;
struct V_5 * V_8 ;
struct V_5 * V_21 = NULL ;
struct V_1 * V_22 ;
int V_26 = 1 ;
if ( V_73 )
V_15 = F_1 ( V_73 ) ;
else
V_15 = F_88 ( V_15 , F_16 ( V_13 ) -> V_7 -> V_93 ) ;
F_25 ( & V_25 -> V_47 ) ;
V_90 = F_16 ( V_13 ) -> V_90 ;
if ( V_90 > V_92 ) {
F_16 ( V_13 ) -> V_90 = V_92 ;
V_26 = 0 ;
goto V_60;
}
if ( V_90 == V_92 )
goto V_60;
if ( V_15 <= V_90 &&
( ! V_73 || V_73 -> V_94 <= V_90 ) )
goto V_60;
if ( V_73 ) {
V_8 = F_11 ( & V_73 -> V_5 ) ;
} else {
V_21 = F_14 ( V_25 , V_15 ) ;
if ( V_21 ) {
V_22 = F_3 ( V_21 , struct V_1 ,
V_5 ) ;
F_89 ( F_12 ( V_22 , V_15 ) ) ;
}
V_8 = V_21 ;
}
for (; V_8 ; V_8 = F_11 ( V_8 ) ) {
V_22 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( F_77 ( V_95 , & V_22 -> V_39 ) )
continue;
if ( V_22 -> V_3 + V_22 -> V_4 <= V_90 )
break;
if ( V_22 -> V_3 >= V_92 )
break;
if ( F_1 ( V_22 ) > V_90 ) {
if ( V_22 -> V_94 < V_15 )
V_22 -> V_94 = V_15 ;
if ( V_73 &&
V_73 -> V_94 >
V_22 -> V_94 )
V_22 -> V_94 =
V_73 -> V_94 ;
goto V_60;
}
}
V_91 = F_90 ( T_1 , V_15 , V_92 ) ;
if ( V_73 && V_73 -> V_94 > V_91 )
V_91 = F_90 ( T_1 , V_73 -> V_94 , V_92 ) ;
F_16 ( V_13 ) -> V_90 = V_91 ;
V_26 = 0 ;
V_60:
if ( V_73 )
F_19 ( V_95 , & V_73 -> V_39 ) ;
F_26 ( & V_25 -> V_47 ) ;
return V_26 ;
}
int F_91 ( struct V_13 * V_13 , T_1 V_15 , T_1 V_96 ,
T_2 * V_53 )
{
struct V_52 * V_97 ;
struct V_98 * V_99 ;
struct V_1 * V_73 ;
struct V_24 * V_25 = & F_16 ( V_13 ) -> V_32 ;
unsigned long V_100 ;
unsigned long V_101 ;
T_2 V_93 = F_16 ( V_13 ) -> V_7 -> V_93 ;
int V_26 = 1 ;
V_73 = F_84 ( V_13 , V_15 ) ;
if ( ! V_73 )
return 1 ;
F_25 ( & V_25 -> V_47 ) ;
F_92 (ordered_sum, &ordered->list, list) {
if ( V_96 >= V_97 -> V_102 ) {
V_100 = V_97 -> V_4 / V_93 ;
V_99 = V_97 -> V_103 ;
for ( V_101 = 0 ; V_101 < V_100 ; V_101 ++ ) {
if ( V_99 [ V_101 ] . V_102 == V_96 ) {
* V_53 = V_99 [ V_101 ] . V_53 ;
V_26 = 0 ;
goto V_60;
}
}
}
}
V_60:
F_26 ( & V_25 -> V_47 ) ;
F_43 ( V_73 ) ;
return V_26 ;
}
void F_93 ( struct V_104 * V_105 ,
struct V_67 * V_7 , struct V_13 * V_13 )
{
T_1 V_106 ;
V_106 = F_36 ( F_16 ( V_13 ) -> V_107 , F_16 ( V_13 ) -> V_108 ) ;
if ( V_106 < V_7 -> V_17 -> V_109 )
return;
F_27 ( & V_7 -> V_17 -> V_49 ) ;
if ( F_47 ( & F_16 ( V_13 ) -> V_70 ) ) {
F_28 ( & F_16 ( V_13 ) -> V_70 ,
& V_7 -> V_17 -> V_70 ) ;
}
F_29 ( & V_7 -> V_17 -> V_49 ) ;
}
int T_3 F_94 ( void )
{
V_33 = F_95 ( L_5 ,
sizeof( struct V_1 ) , 0 ,
V_110 | V_111 ,
NULL ) ;
if ( ! V_33 )
return - V_35 ;
return 0 ;
}
void F_96 ( void )
{
if ( V_33 )
F_97 ( V_33 ) ;
}
