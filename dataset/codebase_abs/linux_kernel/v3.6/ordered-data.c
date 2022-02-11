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
V_2 = F_17 ( sizeof( * V_2 ) , V_33 ) ;
if ( ! V_2 )
return - V_34 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_35 = V_4 ;
V_2 -> V_13 = F_18 ( V_13 ) ;
V_2 -> V_31 = V_31 ;
if ( type != V_36 && type != V_37 )
F_19 ( type , & V_2 -> V_38 ) ;
if ( V_30 )
F_19 ( V_39 , & V_2 -> V_38 ) ;
F_20 ( & V_2 -> V_40 , 1 ) ;
F_21 ( & V_2 -> V_41 ) ;
F_22 ( & V_2 -> V_42 ) ;
F_22 ( & V_2 -> V_43 ) ;
F_23 ( V_13 , V_2 ) ;
F_24 ( & V_25 -> V_44 ) ;
V_8 = F_2 ( & V_25 -> V_25 , V_3 ,
& V_2 -> V_5 ) ;
if ( V_8 )
F_6 ( V_13 , - V_45 , V_3 ) ;
F_25 ( & V_25 -> V_44 ) ;
F_26 ( & F_16 ( V_13 ) -> V_7 -> V_17 -> V_46 ) ;
F_27 ( & V_2 -> V_43 ,
& F_16 ( V_13 ) -> V_7 -> V_17 -> V_47 ) ;
F_28 ( & F_16 ( V_13 ) -> V_7 -> V_17 -> V_46 ) ;
return 0 ;
}
int F_29 ( struct V_13 * V_13 , T_1 V_3 ,
T_1 V_28 , T_1 V_4 , T_1 V_29 , int type )
{
return F_15 ( V_13 , V_3 , V_28 , V_4 ,
V_29 , type , 0 ,
V_48 ) ;
}
int F_30 ( struct V_13 * V_13 , T_1 V_3 ,
T_1 V_28 , T_1 V_4 , T_1 V_29 , int type )
{
return F_15 ( V_13 , V_3 , V_28 , V_4 ,
V_29 , type , 1 ,
V_48 ) ;
}
int F_31 ( struct V_13 * V_13 , T_1 V_3 ,
T_1 V_28 , T_1 V_4 , T_1 V_29 ,
int type , int V_31 )
{
return F_15 ( V_13 , V_3 , V_28 , V_4 ,
V_29 , type , 0 ,
V_31 ) ;
}
void F_32 ( struct V_13 * V_13 ,
struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_24 * V_25 ;
V_25 = & F_16 ( V_13 ) -> V_32 ;
F_24 ( & V_25 -> V_44 ) ;
F_27 ( & V_50 -> V_42 , & V_2 -> V_42 ) ;
F_25 ( & V_25 -> V_44 ) ;
}
int F_33 ( struct V_13 * V_13 ,
struct V_1 * * V_51 ,
T_1 * V_3 , T_1 V_52 , int V_53 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
int V_26 ;
unsigned long V_38 ;
T_1 V_54 ;
T_1 V_55 ;
T_1 V_56 ;
V_25 = & F_16 ( V_13 ) -> V_32 ;
F_34 ( & V_25 -> V_44 , V_38 ) ;
V_8 = F_14 ( V_25 , * V_3 ) ;
if ( ! V_8 ) {
V_26 = 1 ;
goto V_57;
}
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( ! F_12 ( V_2 , * V_3 ) ) {
V_26 = 1 ;
goto V_57;
}
V_55 = F_35 ( * V_3 , V_2 -> V_3 ) ;
V_54 = F_36 ( * V_3 + V_52 , V_2 -> V_3 +
V_2 -> V_4 ) ;
* V_3 = V_54 ;
if ( V_55 > V_54 ) {
F_37 ( V_58 L_3 ,
( unsigned long long ) V_55 ,
( unsigned long long ) V_54 ) ;
}
V_56 = V_54 - V_55 ;
if ( V_56 > V_2 -> V_35 ) {
F_37 ( V_58 L_4 ,
( unsigned long long ) V_2 -> V_35 ,
( unsigned long long ) V_56 ) ;
}
V_2 -> V_35 -= V_56 ;
if ( ! V_53 )
F_19 ( V_59 , & V_2 -> V_38 ) ;
if ( V_2 -> V_35 == 0 )
V_26 = F_38 ( V_36 , & V_2 -> V_38 ) ;
else
V_26 = 1 ;
V_57:
if ( ! V_26 && V_51 && V_2 ) {
* V_51 = V_2 ;
F_39 ( & V_2 -> V_40 ) ;
}
F_40 ( & V_25 -> V_44 , V_38 ) ;
return V_26 == 0 ;
}
int F_41 ( struct V_13 * V_13 ,
struct V_1 * * V_51 ,
T_1 V_3 , T_1 V_52 , int V_53 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
unsigned long V_38 ;
int V_26 ;
V_25 = & F_16 ( V_13 ) -> V_32 ;
F_34 ( & V_25 -> V_44 , V_38 ) ;
if ( V_51 && * V_51 ) {
V_2 = * V_51 ;
goto V_60;
}
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 ) {
V_26 = 1 ;
goto V_57;
}
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
V_60:
if ( ! F_12 ( V_2 , V_3 ) ) {
V_26 = 1 ;
goto V_57;
}
if ( V_52 > V_2 -> V_35 ) {
F_37 ( V_58 L_4 ,
( unsigned long long ) V_2 -> V_35 ,
( unsigned long long ) V_52 ) ;
}
V_2 -> V_35 -= V_52 ;
if ( ! V_53 )
F_19 ( V_59 , & V_2 -> V_38 ) ;
if ( V_2 -> V_35 == 0 )
V_26 = F_38 ( V_36 , & V_2 -> V_38 ) ;
else
V_26 = 1 ;
V_57:
if ( ! V_26 && V_51 && V_2 ) {
* V_51 = V_2 ;
F_39 ( & V_2 -> V_40 ) ;
}
F_40 ( & V_25 -> V_44 , V_38 ) ;
return V_26 == 0 ;
}
void F_42 ( struct V_1 * V_2 )
{
struct V_61 * V_62 ;
struct V_49 * V_50 ;
F_43 ( V_2 -> V_13 , V_2 ) ;
if ( F_44 ( & V_2 -> V_40 ) ) {
if ( V_2 -> V_13 )
F_45 ( V_2 -> V_13 ) ;
while ( ! F_46 ( & V_2 -> V_42 ) ) {
V_62 = V_2 -> V_42 . V_63 ;
V_50 = F_47 ( V_62 , struct V_49 , V_42 ) ;
F_48 ( & V_50 -> V_42 ) ;
F_49 ( V_50 ) ;
}
F_49 ( V_2 ) ;
}
}
void F_50 ( struct V_13 * V_13 ,
struct V_1 * V_2 )
{
struct V_24 * V_25 ;
struct V_64 * V_7 = F_16 ( V_13 ) -> V_7 ;
struct V_5 * V_8 ;
V_25 = & F_16 ( V_13 ) -> V_32 ;
F_24 ( & V_25 -> V_44 ) ;
V_8 = & V_2 -> V_5 ;
F_51 ( V_8 , & V_25 -> V_25 ) ;
V_25 -> V_27 = NULL ;
F_19 ( V_37 , & V_2 -> V_38 ) ;
F_25 ( & V_25 -> V_44 ) ;
F_26 ( & V_7 -> V_17 -> V_46 ) ;
F_52 ( & V_2 -> V_43 ) ;
F_53 ( V_13 , V_2 ) ;
if ( F_54 ( & V_25 -> V_25 ) &&
! F_55 ( V_13 -> V_65 , V_66 ) ) {
F_52 ( & F_16 ( V_13 ) -> V_67 ) ;
}
F_28 ( & V_7 -> V_17 -> V_46 ) ;
F_56 ( & V_2 -> V_41 ) ;
}
void F_57 ( struct V_64 * V_7 ,
int V_68 , int V_69 )
{
struct V_61 V_70 ;
struct V_61 * V_62 ;
struct V_1 * V_71 ;
struct V_13 * V_13 ;
F_22 ( & V_70 ) ;
F_26 ( & V_7 -> V_17 -> V_46 ) ;
F_58 ( & V_7 -> V_17 -> V_47 , & V_70 ) ;
while ( ! F_46 ( & V_70 ) ) {
V_62 = V_70 . V_63 ;
V_71 = F_47 ( V_62 , struct V_1 ,
V_43 ) ;
if ( V_68 &&
! F_59 ( V_72 , & V_71 -> V_38 ) &&
! F_59 ( V_73 , & V_71 -> V_38 ) ) {
F_60 ( & V_71 -> V_43 ,
& V_7 -> V_17 -> V_47 ) ;
F_61 ( & V_7 -> V_17 -> V_46 ) ;
continue;
}
F_52 ( & V_71 -> V_43 ) ;
F_39 ( & V_71 -> V_40 ) ;
V_13 = F_18 ( V_71 -> V_13 ) ;
F_28 ( & V_7 -> V_17 -> V_46 ) ;
if ( V_13 ) {
F_62 ( V_13 , V_71 , 1 ) ;
F_42 ( V_71 ) ;
if ( V_69 )
F_45 ( V_13 ) ;
else
F_63 ( V_13 ) ;
} else {
F_42 ( V_71 ) ;
}
F_26 ( & V_7 -> V_17 -> V_46 ) ;
}
F_28 ( & V_7 -> V_17 -> V_46 ) ;
}
void F_64 ( struct V_64 * V_7 , int V_41 )
{
struct V_74 * V_74 ;
struct V_13 * V_13 ;
struct V_61 V_70 ;
F_22 ( & V_70 ) ;
F_65 ( & V_7 -> V_17 -> V_75 ) ;
F_26 ( & V_7 -> V_17 -> V_46 ) ;
V_76:
F_58 ( & V_7 -> V_17 -> V_67 , & V_70 ) ;
while ( ! F_46 ( & V_70 ) ) {
V_74 = F_47 ( V_70 . V_63 , struct V_74 ,
V_67 ) ;
V_13 = & V_74 -> V_77 ;
F_52 ( & V_74 -> V_67 ) ;
V_13 = F_18 ( V_13 ) ;
if ( ! V_41 && V_13 ) {
F_27 ( & F_16 ( V_13 ) -> V_67 ,
& V_7 -> V_17 -> V_67 ) ;
}
F_28 ( & V_7 -> V_17 -> V_46 ) ;
if ( V_13 ) {
if ( V_41 )
F_66 ( V_13 , 0 , ( T_1 ) - 1 ) ;
else
F_67 ( V_13 -> V_65 ) ;
F_45 ( V_13 ) ;
}
F_68 () ;
F_26 ( & V_7 -> V_17 -> V_46 ) ;
}
if ( V_41 && ! F_46 ( & V_7 -> V_17 -> V_67 ) )
goto V_76;
F_28 ( & V_7 -> V_17 -> V_46 ) ;
F_69 ( & V_7 -> V_17 -> V_75 ) ;
}
void F_62 ( struct V_13 * V_13 ,
struct V_1 * V_2 ,
int V_41 )
{
T_1 V_28 = V_2 -> V_3 ;
T_1 V_78 = V_28 + V_2 -> V_4 - 1 ;
F_70 ( V_13 , V_2 ) ;
if ( ! F_59 ( V_39 , & V_2 -> V_38 ) )
F_71 ( V_13 -> V_65 , V_28 , V_78 ) ;
if ( V_41 ) {
F_72 ( V_2 -> V_41 , F_59 ( V_37 ,
& V_2 -> V_38 ) ) ;
}
}
void F_66 ( struct V_13 * V_13 , T_1 V_28 , T_1 V_4 )
{
T_1 V_78 ;
T_1 V_79 ;
struct V_1 * V_71 ;
int V_80 ;
if ( V_28 + V_4 < V_28 ) {
V_79 = F_73 ( V_81 ) ;
} else {
V_79 = V_28 + V_4 - 1 ;
if ( V_79 > F_73 ( V_81 ) )
V_79 = F_73 ( V_81 ) ;
}
F_71 ( V_13 -> V_65 , V_28 , V_79 ) ;
if ( F_59 ( V_82 ,
& F_16 ( V_13 ) -> V_83 ) )
F_71 ( V_13 -> V_65 , V_28 , V_79 ) ;
F_74 ( V_13 -> V_65 , V_28 , V_79 ) ;
V_78 = V_79 ;
V_80 = 0 ;
while ( 1 ) {
V_71 = F_75 ( V_13 , V_78 ) ;
if ( ! V_71 )
break;
if ( V_71 -> V_3 > V_79 ) {
F_42 ( V_71 ) ;
break;
}
if ( V_71 -> V_3 + V_71 -> V_4 < V_28 ) {
F_42 ( V_71 ) ;
break;
}
V_80 ++ ;
F_62 ( V_13 , V_71 , 1 ) ;
V_78 = V_71 -> V_3 ;
F_42 ( V_71 ) ;
if ( V_78 == 0 || V_78 == V_28 )
break;
V_78 -- ;
}
}
struct V_1 * F_76 ( struct V_13 * V_13 ,
T_1 V_3 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
V_25 = & F_16 ( V_13 ) -> V_32 ;
F_24 ( & V_25 -> V_44 ) ;
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 )
goto V_57;
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( ! F_12 ( V_2 , V_3 ) )
V_2 = NULL ;
if ( V_2 )
F_39 ( & V_2 -> V_40 ) ;
V_57:
F_25 ( & V_25 -> V_44 ) ;
return V_2 ;
}
struct V_1 * F_77 ( struct V_13 * V_13 ,
T_1 V_3 ,
T_1 V_4 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
V_25 = & F_16 ( V_13 ) -> V_32 ;
F_24 ( & V_25 -> V_44 ) ;
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 ) {
V_8 = F_14 ( V_25 , V_3 + V_4 ) ;
if ( ! V_8 )
goto V_57;
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
V_57:
if ( V_2 )
F_39 ( & V_2 -> V_40 ) ;
F_25 ( & V_25 -> V_44 ) ;
return V_2 ;
}
struct V_1 *
F_75 ( struct V_13 * V_13 , T_1 V_3 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
V_25 = & F_16 ( V_13 ) -> V_32 ;
F_24 ( & V_25 -> V_44 ) ;
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 )
goto V_57;
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
F_39 ( & V_2 -> V_40 ) ;
V_57:
F_25 ( & V_25 -> V_44 ) ;
return V_2 ;
}
int F_78 ( struct V_13 * V_13 , T_1 V_15 ,
struct V_1 * V_71 )
{
struct V_24 * V_25 = & F_16 ( V_13 ) -> V_32 ;
T_1 V_84 ;
T_1 V_85 ;
T_1 V_86 ;
T_1 V_87 = F_79 ( V_13 ) ;
struct V_5 * V_8 ;
struct V_5 * V_21 = NULL ;
struct V_1 * V_22 ;
int V_26 = 1 ;
if ( V_71 )
V_15 = F_1 ( V_71 ) ;
else
V_15 = F_80 ( V_15 , F_16 ( V_13 ) -> V_7 -> V_88 ) ;
F_24 ( & V_25 -> V_44 ) ;
V_84 = F_16 ( V_13 ) -> V_84 ;
if ( V_84 > V_87 ) {
F_16 ( V_13 ) -> V_84 = V_87 ;
V_26 = 0 ;
goto V_57;
}
if ( V_84 == V_87 || V_15 <= V_84 ) {
goto V_57;
}
if ( V_71 ) {
V_8 = F_11 ( & V_71 -> V_5 ) ;
} else {
V_21 = F_14 ( V_25 , V_15 ) ;
if ( V_21 ) {
V_22 = F_3 ( V_21 , struct V_1 ,
V_5 ) ;
F_81 ( F_12 ( V_22 , V_15 ) ) ;
}
V_8 = V_21 ;
}
for (; V_8 ; V_8 = F_11 ( V_8 ) ) {
V_22 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( F_59 ( V_89 , & V_22 -> V_38 ) )
continue;
if ( V_22 -> V_3 + V_22 -> V_4 <= V_84 )
break;
if ( V_22 -> V_3 >= V_87 )
break;
if ( V_22 -> V_3 >= V_84 )
goto V_57;
}
V_85 = F_82 ( T_1 , V_15 , V_87 ) ;
if ( V_71 ) {
V_8 = F_10 ( & V_71 -> V_5 ) ;
} else {
if ( V_21 )
V_8 = F_10 ( V_21 ) ;
else
V_8 = F_83 ( & V_25 -> V_25 ) ;
}
V_86 = V_87 ;
for (; V_8 ; V_8 = F_10 ( V_8 ) ) {
V_22 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( F_59 ( V_89 , & V_22 -> V_38 ) )
continue;
if ( V_22 -> V_3 > V_15 ) {
V_86 = V_22 -> V_3 ;
break;
}
}
if ( V_86 > V_15 )
V_85 = F_82 ( T_1 , V_86 , V_87 ) ;
F_16 ( V_13 ) -> V_84 = V_85 ;
V_26 = 0 ;
V_57:
if ( V_71 )
F_19 ( V_89 , & V_71 -> V_38 ) ;
F_25 ( & V_25 -> V_44 ) ;
return V_26 ;
}
int F_84 ( struct V_13 * V_13 , T_1 V_15 , T_1 V_90 ,
T_2 * V_50 )
{
struct V_49 * V_91 ;
struct V_92 * V_93 ;
struct V_1 * V_71 ;
struct V_24 * V_25 = & F_16 ( V_13 ) -> V_32 ;
unsigned long V_94 ;
unsigned long V_95 ;
T_2 V_88 = F_16 ( V_13 ) -> V_7 -> V_88 ;
int V_26 = 1 ;
V_71 = F_76 ( V_13 , V_15 ) ;
if ( ! V_71 )
return 1 ;
F_24 ( & V_25 -> V_44 ) ;
F_85 (ordered_sum, &ordered->list, list) {
if ( V_90 >= V_91 -> V_96 ) {
V_94 = V_91 -> V_4 / V_88 ;
V_93 = V_91 -> V_97 ;
for ( V_95 = 0 ; V_95 < V_94 ; V_95 ++ ) {
if ( V_93 [ V_95 ] . V_96 == V_90 ) {
* V_50 = V_93 [ V_95 ] . V_50 ;
V_26 = 0 ;
goto V_57;
}
}
}
}
V_57:
F_25 ( & V_25 -> V_44 ) ;
F_42 ( V_71 ) ;
return V_26 ;
}
void F_86 ( struct V_98 * V_99 ,
struct V_64 * V_7 , struct V_13 * V_13 )
{
T_1 V_100 ;
V_100 = F_35 ( F_16 ( V_13 ) -> V_101 , F_16 ( V_13 ) -> V_102 ) ;
if ( V_100 < V_7 -> V_17 -> V_103 )
return;
if ( V_99 && V_7 -> V_17 -> V_104 -> V_105 ) {
F_66 ( V_13 , 0 , ( T_1 ) - 1 ) ;
return;
}
F_26 ( & V_7 -> V_17 -> V_46 ) ;
if ( F_46 ( & F_16 ( V_13 ) -> V_67 ) ) {
F_27 ( & F_16 ( V_13 ) -> V_67 ,
& V_7 -> V_17 -> V_67 ) ;
}
F_28 ( & V_7 -> V_17 -> V_46 ) ;
}
