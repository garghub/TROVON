static struct V_1 * F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
if ( V_2 ) {
if ( V_2 -> V_3 <= V_3 &&
V_2 -> V_3 + V_2 -> V_4 > V_3 ) {
return V_2 ;
}
}
return NULL ;
}
static struct V_1 * F_2 ( struct V_5 * V_6 ,
unsigned int V_3 )
{
struct V_7 * V_8 = V_6 -> V_7 ;
struct V_1 * V_9 ;
while ( V_8 ) {
V_9 = V_1 ( V_8 , struct V_1 , V_7 ) ;
if ( V_3 < V_9 -> V_3 )
V_8 = V_8 -> V_10 ;
else if ( V_3 >= V_9 -> V_3 + V_9 -> V_4 )
V_8 = V_8 -> V_11 ;
else
return V_9 ;
}
return NULL ;
}
struct V_1 * F_3 ( struct V_5 * V_6 ,
struct V_1 * V_2 , unsigned int V_3 )
{
struct V_1 * V_9 ;
V_9 = F_1 ( V_2 , V_3 ) ;
if ( ! V_9 )
return F_2 ( V_6 , V_3 ) ;
return V_9 ;
}
struct V_7 * * F_4 ( struct V_12 * V_13 ,
struct V_5 * V_6 , struct V_7 * * V_14 ,
unsigned int V_3 )
{
struct V_7 * * V_15 = & V_6 -> V_7 ;
struct V_1 * V_9 ;
while ( * V_15 ) {
* V_14 = * V_15 ;
V_9 = V_1 ( * V_14 , struct V_1 , V_7 ) ;
if ( V_3 < V_9 -> V_3 )
V_15 = & ( * V_15 ) -> V_10 ;
else if ( V_3 >= V_9 -> V_3 + V_9 -> V_4 )
V_15 = & ( * V_15 ) -> V_11 ;
else
F_5 ( V_13 , 1 ) ;
}
return V_15 ;
}
struct V_1 * F_6 ( struct V_5 * V_6 ,
struct V_1 * V_2 ,
unsigned int V_3 ,
struct V_1 * * V_16 ,
struct V_1 * * V_17 ,
struct V_7 * * * V_18 ,
struct V_7 * * V_19 ,
bool V_20 )
{
struct V_7 * * V_21 = & V_6 -> V_7 ;
struct V_7 * V_14 = NULL , * V_22 ;
struct V_1 * V_9 = V_2 ;
* V_18 = NULL ;
* V_19 = NULL ;
* V_16 = NULL ;
* V_17 = NULL ;
if ( F_7 ( V_6 ) )
return NULL ;
if ( V_9 ) {
if ( V_9 -> V_3 <= V_3 && V_9 -> V_3 + V_9 -> V_4 > V_3 )
goto V_23;
}
while ( * V_21 ) {
V_14 = * V_21 ;
V_9 = V_1 ( * V_21 , struct V_1 , V_7 ) ;
if ( V_3 < V_9 -> V_3 )
V_21 = & ( * V_21 ) -> V_10 ;
else if ( V_3 >= V_9 -> V_3 + V_9 -> V_4 )
V_21 = & ( * V_21 ) -> V_11 ;
else
goto V_23;
}
* V_18 = V_21 ;
* V_19 = V_14 ;
V_9 = V_1 ( V_14 , struct V_1 , V_7 ) ;
V_22 = V_14 ;
if ( V_14 && V_3 > V_9 -> V_3 )
V_22 = F_8 ( V_14 ) ;
* V_17 = F_9 ( V_22 , struct V_1 , V_7 ) ;
V_22 = V_14 ;
if ( V_14 && V_3 < V_9 -> V_3 )
V_22 = F_10 ( V_14 ) ;
* V_16 = F_9 ( V_22 , struct V_1 , V_7 ) ;
return NULL ;
V_23:
if ( V_3 == V_9 -> V_3 || V_20 ) {
V_22 = F_10 ( & V_9 -> V_7 ) ;
* V_16 = F_9 ( V_22 , struct V_1 , V_7 ) ;
}
if ( V_3 == V_9 -> V_3 + V_9 -> V_4 - 1 || V_20 ) {
V_22 = F_8 ( & V_9 -> V_7 ) ;
* V_17 = F_9 ( V_22 , struct V_1 , V_7 ) ;
}
return V_9 ;
}
bool F_11 ( struct V_12 * V_13 ,
struct V_5 * V_6 )
{
#ifdef F_12
struct V_7 * V_24 = F_13 ( V_6 ) , * V_25 ;
struct V_1 * V_26 , * V_27 ;
if ( ! V_24 )
return true ;
while ( V_24 ) {
V_25 = F_8 ( V_24 ) ;
if ( ! V_25 )
return true ;
V_26 = V_1 ( V_24 , struct V_1 , V_7 ) ;
V_27 = V_1 ( V_25 , struct V_1 , V_7 ) ;
if ( V_26 -> V_3 + V_26 -> V_4 > V_27 -> V_3 ) {
F_14 ( V_13 -> V_28 , V_29 , L_1
L_2 ,
V_26 -> V_3 , V_26 -> V_4 ,
V_27 -> V_3 , V_27 -> V_4 ) ;
return false ;
}
V_24 = V_25 ;
}
#endif
return true ;
}
static struct V_30 * F_15 ( struct V_12 * V_13 ,
struct V_31 * V_32 , struct V_33 * V_34 ,
struct V_7 * V_14 , struct V_7 * * V_15 )
{
struct V_30 * V_35 ;
V_35 = F_16 ( V_36 , V_37 ) ;
if ( ! V_35 )
return NULL ;
V_35 -> V_34 = * V_34 ;
F_17 ( & V_35 -> V_38 ) ;
V_35 -> V_32 = V_32 ;
F_18 ( & V_35 -> V_7 , V_14 , V_15 ) ;
F_19 ( & V_35 -> V_7 , & V_32 -> V_6 ) ;
F_20 ( & V_32 -> V_39 ) ;
F_20 ( & V_13 -> V_40 ) ;
return V_35 ;
}
static void F_21 ( struct V_12 * V_13 ,
struct V_31 * V_32 , struct V_30 * V_35 )
{
F_22 ( & V_35 -> V_7 , & V_32 -> V_6 ) ;
F_23 ( & V_32 -> V_39 ) ;
F_23 ( & V_13 -> V_40 ) ;
if ( V_32 -> V_41 == V_35 )
V_32 -> V_41 = NULL ;
F_24 ( V_36 , V_35 ) ;
}
static void F_25 ( struct V_12 * V_13 ,
struct V_31 * V_32 , struct V_30 * V_35 )
{
F_26 ( & V_13 -> V_42 ) ;
F_5 ( V_13 , F_27 ( & V_35 -> V_38 ) ) ;
F_28 ( & V_35 -> V_38 ) ;
F_29 ( & V_13 -> V_42 ) ;
F_21 ( V_13 , V_32 , V_35 ) ;
}
static struct V_31 * F_30 ( struct V_43 * V_43 )
{
struct V_12 * V_13 = F_31 ( V_43 ) ;
struct V_31 * V_32 ;
T_1 V_44 = V_43 -> V_45 ;
F_32 ( & V_13 -> V_46 ) ;
V_32 = F_33 ( & V_13 -> V_47 , V_44 ) ;
if ( ! V_32 ) {
V_32 = F_34 ( V_48 , V_49 ) ;
F_35 ( & V_13 -> V_47 , V_44 , V_32 ) ;
memset ( V_32 , 0 , sizeof( struct V_31 ) ) ;
V_32 -> V_44 = V_44 ;
V_32 -> V_6 = V_50 ;
V_32 -> V_41 = NULL ;
F_36 ( & V_32 -> V_51 ) ;
F_17 ( & V_32 -> V_38 ) ;
F_37 ( & V_32 -> V_39 , 0 ) ;
F_20 ( & V_13 -> V_52 ) ;
} else {
F_23 ( & V_13 -> V_53 ) ;
F_28 ( & V_32 -> V_38 ) ;
}
F_38 ( & V_13 -> V_46 ) ;
F_39 ( V_43 ) -> V_31 = V_32 ;
return V_32 ;
}
static struct V_30 * F_40 ( struct V_12 * V_13 ,
struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_7 * * V_15 = & V_32 -> V_6 . V_7 ;
struct V_30 * V_35 ;
V_35 = F_15 ( V_13 , V_32 , V_34 , NULL , V_15 ) ;
if ( ! V_35 )
return NULL ;
V_32 -> V_54 = V_35 -> V_34 ;
V_32 -> V_41 = V_35 ;
return V_35 ;
}
static unsigned int F_41 ( struct V_12 * V_13 ,
struct V_31 * V_32 )
{
struct V_7 * V_8 , * V_25 ;
struct V_30 * V_35 ;
unsigned int V_55 = F_42 ( & V_32 -> V_39 ) ;
V_8 = F_13 ( & V_32 -> V_6 ) ;
while ( V_8 ) {
V_25 = F_8 ( V_8 ) ;
V_35 = V_1 ( V_8 , struct V_30 , V_7 ) ;
F_25 ( V_13 , V_32 , V_35 ) ;
V_8 = V_25 ;
}
return V_55 - F_42 ( & V_32 -> V_39 ) ;
}
static void F_43 ( struct V_43 * V_43 ,
T_2 V_56 , unsigned int V_4 )
{
struct V_33 * V_54 = & F_39 ( V_43 ) -> V_31 -> V_54 ;
if ( V_56 < V_54 -> V_56 + V_54 -> V_4 && V_56 + V_4 > V_54 -> V_56 ) {
V_54 -> V_4 = 0 ;
F_44 ( V_43 , true ) ;
}
}
static bool F_45 ( struct V_43 * V_43 , struct V_57 * V_58 )
{
struct V_12 * V_13 = F_31 ( V_43 ) ;
struct V_31 * V_32 ;
struct V_30 * V_35 ;
struct V_33 V_34 ;
if ( ! F_46 ( V_43 ) ) {
if ( V_58 && V_58 -> V_4 ) {
V_58 -> V_4 = 0 ;
return true ;
}
return false ;
}
V_32 = F_30 ( V_43 ) ;
if ( ! V_58 || ! V_58 -> V_4 )
return false ;
F_47 ( & V_34 , V_58 ) ;
F_48 ( & V_32 -> V_51 ) ;
if ( F_42 ( & V_32 -> V_39 ) )
goto V_59;
V_35 = F_40 ( V_13 , V_32 , & V_34 ) ;
if ( V_35 ) {
F_26 ( & V_13 -> V_42 ) ;
F_49 ( & V_35 -> V_38 , & V_13 -> V_60 ) ;
F_29 ( & V_13 -> V_42 ) ;
}
V_59:
F_50 ( & V_32 -> V_51 ) ;
return false ;
}
bool F_51 ( struct V_43 * V_43 , struct V_57 * V_58 )
{
bool V_61 = F_45 ( V_43 , V_58 ) ;
if ( ! F_39 ( V_43 ) -> V_31 )
F_52 ( V_43 , V_62 ) ;
return V_61 ;
}
static bool F_53 ( struct V_43 * V_43 , T_2 V_63 ,
struct V_33 * V_34 )
{
struct V_12 * V_13 = F_31 ( V_43 ) ;
struct V_31 * V_32 = F_39 ( V_43 ) -> V_31 ;
struct V_30 * V_35 ;
bool V_61 = false ;
F_5 ( V_13 , ! V_32 ) ;
F_54 ( V_43 , V_63 ) ;
F_55 ( & V_32 -> V_51 ) ;
if ( V_32 -> V_54 . V_56 <= V_63 &&
V_32 -> V_54 . V_56 + V_32 -> V_54 . V_4 > V_63 ) {
* V_34 = V_32 -> V_54 ;
V_61 = true ;
F_56 ( V_13 ) ;
goto V_59;
}
V_35 = (struct V_30 * ) F_3 ( & V_32 -> V_6 ,
(struct V_1 * ) V_32 -> V_41 , V_63 ) ;
if ( ! V_35 )
goto V_59;
if ( V_35 == V_32 -> V_41 )
F_57 ( V_13 ) ;
else
F_58 ( V_13 ) ;
* V_34 = V_35 -> V_34 ;
F_26 ( & V_13 -> V_42 ) ;
if ( ! F_27 ( & V_35 -> V_38 ) ) {
F_59 ( & V_35 -> V_38 , & V_13 -> V_60 ) ;
V_32 -> V_41 = V_35 ;
}
F_29 ( & V_13 -> V_42 ) ;
V_61 = true ;
V_59:
F_60 ( V_13 ) ;
F_61 ( & V_32 -> V_51 ) ;
F_62 ( V_43 , V_63 , V_34 ) ;
return V_61 ;
}
static struct V_30 * F_63 ( struct V_43 * V_43 ,
struct V_31 * V_32 , struct V_33 * V_34 ,
struct V_30 * V_64 ,
struct V_30 * V_65 )
{
struct V_12 * V_13 = F_31 ( V_43 ) ;
struct V_30 * V_35 = NULL ;
if ( V_64 && F_64 ( V_34 , & V_64 -> V_34 ) ) {
V_64 -> V_34 . V_4 += V_34 -> V_4 ;
V_34 = & V_64 -> V_34 ;
V_35 = V_64 ;
}
if ( V_65 && F_65 ( V_34 , & V_65 -> V_34 ) ) {
V_65 -> V_34 . V_56 = V_34 -> V_56 ;
V_65 -> V_34 . V_66 = V_34 -> V_66 ;
V_65 -> V_34 . V_4 += V_34 -> V_4 ;
if ( V_35 )
F_25 ( V_13 , V_32 , V_64 ) ;
V_35 = V_65 ;
}
if ( ! V_35 )
return NULL ;
F_66 ( V_43 , V_32 , V_35 ) ;
F_26 ( & V_13 -> V_42 ) ;
if ( ! F_27 ( & V_35 -> V_38 ) ) {
F_59 ( & V_35 -> V_38 , & V_13 -> V_60 ) ;
V_32 -> V_41 = V_35 ;
}
F_29 ( & V_13 -> V_42 ) ;
return V_35 ;
}
static struct V_30 * F_67 ( struct V_43 * V_43 ,
struct V_31 * V_32 , struct V_33 * V_34 ,
struct V_7 * * V_18 ,
struct V_7 * V_19 )
{
struct V_12 * V_13 = F_31 ( V_43 ) ;
struct V_7 * * V_15 = & V_32 -> V_6 . V_7 ;
struct V_7 * V_14 = NULL ;
struct V_30 * V_35 = NULL ;
if ( V_18 && V_19 ) {
V_14 = V_19 ;
V_15 = V_18 ;
goto V_67;
}
V_15 = F_4 ( V_13 , & V_32 -> V_6 , & V_14 , V_34 -> V_56 ) ;
V_67:
V_35 = F_15 ( V_13 , V_32 , V_34 , V_14 , V_15 ) ;
if ( ! V_35 )
return NULL ;
F_66 ( V_43 , V_32 , V_35 ) ;
F_26 ( & V_13 -> V_42 ) ;
F_49 ( & V_35 -> V_38 , & V_13 -> V_60 ) ;
V_32 -> V_41 = V_35 ;
F_29 ( & V_13 -> V_42 ) ;
return V_35 ;
}
static void F_68 ( struct V_43 * V_43 ,
T_2 V_56 , T_3 V_68 , unsigned int V_4 )
{
struct V_12 * V_13 = F_31 ( V_43 ) ;
struct V_31 * V_32 = F_39 ( V_43 ) -> V_31 ;
struct V_30 * V_35 = NULL , * V_69 = NULL ;
struct V_30 * V_70 = NULL , * V_71 = NULL ;
struct V_33 V_34 , V_72 , V_73 ;
struct V_7 * * V_18 = NULL , * V_19 = NULL ;
unsigned int V_74 = V_56 + V_4 ;
unsigned int V_75 = ( unsigned int ) V_56 ;
if ( ! V_32 )
return;
F_69 ( V_43 , V_56 , V_68 , V_4 ) ;
F_48 ( & V_32 -> V_51 ) ;
if ( F_70 ( V_43 , V_62 ) ) {
F_50 ( & V_32 -> V_51 ) ;
return;
}
V_73 = V_32 -> V_54 ;
V_72 . V_4 = 0 ;
F_43 ( V_43 , V_56 , V_4 ) ;
V_35 = (struct V_30 * ) F_6 ( & V_32 -> V_6 ,
(struct V_1 * ) V_32 -> V_41 , V_56 ,
(struct V_1 * * ) & V_70 ,
(struct V_1 * * ) & V_71 ,
& V_18 , & V_19 , false ) ;
if ( ! V_35 )
V_35 = V_71 ;
while ( V_35 && V_35 -> V_34 . V_56 < V_74 ) {
unsigned int V_76 ;
int V_77 = 0 ;
V_71 = V_69 = NULL ;
V_72 = V_35 -> V_34 ;
V_76 = V_72 . V_56 + V_72 . V_4 ;
F_5 ( V_13 , V_75 >= V_76 ) ;
if ( V_75 > V_72 . V_56 && V_75 - V_72 . V_56 >= V_78 ) {
V_35 -> V_34 . V_4 = V_75 - V_35 -> V_34 . V_56 ;
V_70 = V_35 ;
V_77 = 1 ;
}
if ( V_74 < V_76 && V_76 - V_74 >= V_78 ) {
if ( V_77 ) {
F_71 ( & V_34 , V_74 ,
V_74 - V_72 . V_56 + V_72 . V_66 ,
V_76 - V_74 ) ;
V_69 = F_67 ( V_43 , V_32 , & V_34 ,
NULL , NULL ) ;
V_71 = V_69 ;
} else {
V_35 -> V_34 . V_56 = V_74 ;
V_35 -> V_34 . V_66 += V_74 - V_72 . V_56 ;
V_35 -> V_34 . V_4 -= V_74 - V_72 . V_56 ;
V_71 = V_35 ;
}
V_77 ++ ;
}
if ( ! V_71 ) {
struct V_7 * V_8 = F_8 ( & V_35 -> V_7 ) ;
V_71 = F_9 ( V_8 , struct V_30 ,
V_7 ) ;
}
if ( V_77 )
F_66 ( V_43 , V_32 , V_35 ) ;
else
F_25 ( V_13 , V_32 , V_35 ) ;
if ( V_77 != 1 ) {
V_18 = NULL ;
V_19 = NULL ;
}
V_35 = V_71 ;
}
if ( V_68 ) {
F_71 ( & V_34 , V_56 , V_68 , V_4 ) ;
if ( ! F_63 ( V_43 , V_32 , & V_34 , V_70 , V_71 ) )
F_67 ( V_43 , V_32 , & V_34 ,
V_18 , V_19 ) ;
if ( V_72 . V_4 >= 1 &&
V_73 . V_4 < V_78 &&
V_32 -> V_54 . V_4 < V_78 ) {
F_43 ( V_43 , 0 , V_79 ) ;
F_52 ( V_43 , V_62 ) ;
}
}
if ( F_70 ( V_43 , V_62 ) )
F_41 ( V_13 , V_32 ) ;
F_50 ( & V_32 -> V_51 ) ;
}
unsigned int F_72 ( struct V_12 * V_13 , int V_80 )
{
struct V_31 * V_32 , * V_25 ;
struct V_30 * V_35 ;
unsigned int V_39 = 0 , V_81 = 0 ;
int V_82 ;
if ( ! F_73 ( V_13 , V_83 ) )
return 0 ;
if ( ! F_42 ( & V_13 -> V_53 ) )
goto V_84;
if ( ! F_74 ( & V_13 -> V_46 ) )
goto V_59;
F_75 (et, next, &sbi->zombie_list, list) {
if ( F_42 ( & V_32 -> V_39 ) ) {
F_48 ( & V_32 -> V_51 ) ;
V_39 += F_41 ( V_13 , V_32 ) ;
F_50 ( & V_32 -> V_51 ) ;
}
F_5 ( V_13 , F_42 ( & V_32 -> V_39 ) ) ;
F_28 ( & V_32 -> V_38 ) ;
F_76 ( & V_13 -> V_47 , V_32 -> V_44 ) ;
F_24 ( V_48 , V_32 ) ;
F_23 ( & V_13 -> V_52 ) ;
F_23 ( & V_13 -> V_53 ) ;
V_81 ++ ;
if ( V_39 + V_81 >= V_80 )
goto V_85;
F_77 () ;
}
F_38 ( & V_13 -> V_46 ) ;
V_84:
if ( ! F_74 ( & V_13 -> V_46 ) )
goto V_59;
V_82 = V_80 - ( V_39 + V_81 ) ;
F_26 ( & V_13 -> V_42 ) ;
for (; V_82 > 0 ; V_82 -- ) {
if ( F_27 ( & V_13 -> V_60 ) )
break;
V_35 = F_78 ( & V_13 -> V_60 ,
struct V_30 , V_38 ) ;
V_32 = V_35 -> V_32 ;
if ( ! F_79 ( & V_32 -> V_51 ) ) {
F_59 ( & V_35 -> V_38 , & V_13 -> V_60 ) ;
continue;
}
F_28 ( & V_35 -> V_38 ) ;
F_29 ( & V_13 -> V_42 ) ;
F_21 ( V_13 , V_32 , V_35 ) ;
F_50 ( & V_32 -> V_51 ) ;
V_39 ++ ;
F_26 ( & V_13 -> V_42 ) ;
}
F_29 ( & V_13 -> V_42 ) ;
V_85:
F_38 ( & V_13 -> V_46 ) ;
V_59:
F_80 ( V_13 , V_39 , V_81 ) ;
return V_39 + V_81 ;
}
unsigned int F_81 ( struct V_43 * V_43 )
{
struct V_12 * V_13 = F_31 ( V_43 ) ;
struct V_31 * V_32 = F_39 ( V_43 ) -> V_31 ;
unsigned int V_39 = 0 ;
if ( ! V_32 || ! F_42 ( & V_32 -> V_39 ) )
return 0 ;
F_48 ( & V_32 -> V_51 ) ;
V_39 = F_41 ( V_13 , V_32 ) ;
F_50 ( & V_32 -> V_51 ) ;
return V_39 ;
}
void F_82 ( struct V_43 * V_43 )
{
struct V_12 * V_13 = F_31 ( V_43 ) ;
struct V_31 * V_32 = F_39 ( V_43 ) -> V_31 ;
F_52 ( V_43 , V_62 ) ;
F_48 ( & V_32 -> V_51 ) ;
F_41 ( V_13 , V_32 ) ;
F_43 ( V_43 , 0 , V_79 ) ;
F_50 ( & V_32 -> V_51 ) ;
}
void F_83 ( struct V_43 * V_43 )
{
struct V_12 * V_13 = F_31 ( V_43 ) ;
struct V_31 * V_32 = F_39 ( V_43 ) -> V_31 ;
unsigned int V_39 = 0 ;
if ( ! V_32 )
return;
if ( V_43 -> V_86 && ! F_84 ( V_43 ) &&
F_42 ( & V_32 -> V_39 ) ) {
F_32 ( & V_13 -> V_46 ) ;
F_49 ( & V_32 -> V_38 , & V_13 -> V_87 ) ;
F_20 ( & V_13 -> V_53 ) ;
F_38 ( & V_13 -> V_46 ) ;
return;
}
V_39 = F_81 ( V_43 ) ;
F_32 ( & V_13 -> V_46 ) ;
F_5 ( V_13 , F_42 ( & V_32 -> V_39 ) ) ;
F_76 ( & V_13 -> V_47 , V_43 -> V_45 ) ;
F_24 ( V_48 , V_32 ) ;
F_23 ( & V_13 -> V_52 ) ;
F_38 ( & V_13 -> V_46 ) ;
F_39 ( V_43 ) -> V_31 = NULL ;
F_85 ( V_43 , V_39 ) ;
}
bool F_86 ( struct V_43 * V_43 , T_2 V_63 ,
struct V_33 * V_34 )
{
if ( ! F_46 ( V_43 ) )
return false ;
return F_53 ( V_43 , V_63 , V_34 ) ;
}
void F_87 ( struct V_88 * V_89 )
{
T_2 V_56 ;
T_3 V_68 ;
if ( ! F_46 ( V_89 -> V_43 ) )
return;
if ( V_89 -> V_90 == V_91 )
V_68 = V_92 ;
else
V_68 = V_89 -> V_90 ;
V_56 = F_88 ( F_89 ( V_89 -> V_93 ) , V_89 -> V_43 ) +
V_89 -> V_94 ;
F_68 ( V_89 -> V_43 , V_56 , V_68 , 1 ) ;
}
void F_90 ( struct V_88 * V_89 ,
T_2 V_56 , T_3 V_68 , unsigned int V_4 )
{
if ( ! F_46 ( V_89 -> V_43 ) )
return;
F_68 ( V_89 -> V_43 , V_56 , V_68 , V_4 ) ;
}
void F_91 ( struct V_12 * V_13 )
{
F_92 ( & V_13 -> V_47 , V_95 ) ;
F_93 ( & V_13 -> V_46 ) ;
F_17 ( & V_13 -> V_60 ) ;
F_94 ( & V_13 -> V_42 ) ;
F_37 ( & V_13 -> V_52 , 0 ) ;
F_17 ( & V_13 -> V_87 ) ;
F_37 ( & V_13 -> V_53 , 0 ) ;
F_37 ( & V_13 -> V_40 , 0 ) ;
}
int T_4 F_95 ( void )
{
V_48 = F_96 ( L_3 ,
sizeof( struct V_31 ) ) ;
if ( ! V_48 )
return - V_96 ;
V_36 = F_96 ( L_4 ,
sizeof( struct V_30 ) ) ;
if ( ! V_36 ) {
F_97 ( V_48 ) ;
return - V_96 ;
}
return 0 ;
}
void F_98 ( void )
{
F_97 ( V_36 ) ;
F_97 ( V_48 ) ;
}
