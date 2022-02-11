static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 , struct V_6 * V_7 ,
struct V_8 * V_9 , struct V_8 * * V_10 )
{
struct V_1 * V_11 ;
V_11 = F_2 ( V_12 , V_13 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_7 = * V_7 ;
F_3 ( & V_11 -> V_14 ) ;
V_11 -> V_5 = V_5 ;
F_4 ( & V_11 -> V_8 , V_9 , V_10 ) ;
F_5 ( & V_11 -> V_8 , & V_5 -> V_15 ) ;
F_6 ( & V_5 -> V_16 ) ;
F_6 ( & V_3 -> V_17 ) ;
return V_11 ;
}
static void F_7 ( struct V_2 * V_3 ,
struct V_4 * V_5 , struct V_1 * V_11 )
{
F_8 ( & V_11 -> V_8 , & V_5 -> V_15 ) ;
F_9 ( & V_5 -> V_16 ) ;
F_9 ( & V_3 -> V_17 ) ;
if ( V_5 -> V_18 == V_11 )
V_5 -> V_18 = NULL ;
F_10 ( V_12 , V_11 ) ;
}
static void F_11 ( struct V_2 * V_3 ,
struct V_4 * V_5 , struct V_1 * V_11 )
{
F_12 ( & V_3 -> V_19 ) ;
F_13 ( V_3 , F_14 ( & V_11 -> V_14 ) ) ;
F_15 ( & V_11 -> V_14 ) ;
F_16 ( & V_3 -> V_19 ) ;
F_7 ( V_3 , V_5 , V_11 ) ;
}
static struct V_4 * F_17 ( struct V_20 * V_20 )
{
struct V_2 * V_3 = F_18 ( V_20 ) ;
struct V_4 * V_5 ;
T_1 V_21 = V_20 -> V_22 ;
F_19 ( & V_3 -> V_23 ) ;
V_5 = F_20 ( & V_3 -> V_24 , V_21 ) ;
if ( ! V_5 ) {
V_5 = F_21 ( V_25 , V_26 ) ;
F_22 ( & V_3 -> V_24 , V_21 , V_5 ) ;
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
V_5 -> V_21 = V_21 ;
V_5 -> V_15 = V_27 ;
V_5 -> V_18 = NULL ;
F_23 ( & V_5 -> V_28 ) ;
F_3 ( & V_5 -> V_14 ) ;
F_24 ( & V_5 -> V_16 , 0 ) ;
F_6 ( & V_3 -> V_29 ) ;
} else {
F_9 ( & V_3 -> V_30 ) ;
F_15 ( & V_5 -> V_14 ) ;
}
F_25 ( & V_3 -> V_23 ) ;
F_26 ( V_20 ) -> V_4 = V_5 ;
return V_5 ;
}
static struct V_1 * F_27 ( struct V_2 * V_3 ,
struct V_4 * V_5 , unsigned int V_31 )
{
struct V_8 * V_32 = V_5 -> V_15 . V_8 ;
struct V_1 * V_11 = V_5 -> V_18 ;
if ( V_11 ) {
struct V_6 * V_33 = & V_11 -> V_7 ;
if ( V_33 -> V_31 <= V_31 && V_33 -> V_31 + V_33 -> V_34 > V_31 ) {
F_28 ( V_3 ) ;
return V_11 ;
}
}
while ( V_32 ) {
V_11 = F_29 ( V_32 , struct V_1 , V_8 ) ;
if ( V_31 < V_11 -> V_7 . V_31 ) {
V_32 = V_32 -> V_35 ;
} else if ( V_31 >= V_11 -> V_7 . V_31 + V_11 -> V_7 . V_34 ) {
V_32 = V_32 -> V_36 ;
} else {
F_30 ( V_3 ) ;
return V_11 ;
}
}
return NULL ;
}
static struct V_1 * F_31 ( struct V_2 * V_3 ,
struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_8 * * V_10 = & V_5 -> V_15 . V_8 ;
struct V_1 * V_11 ;
V_11 = F_1 ( V_3 , V_5 , V_7 , NULL , V_10 ) ;
if ( ! V_11 )
return NULL ;
V_5 -> V_37 = V_11 -> V_7 ;
V_5 -> V_18 = V_11 ;
return V_11 ;
}
static unsigned int F_32 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_8 * V_32 , * V_38 ;
struct V_1 * V_11 ;
unsigned int V_39 = F_33 ( & V_5 -> V_16 ) ;
V_32 = F_34 ( & V_5 -> V_15 ) ;
while ( V_32 ) {
V_38 = F_35 ( V_32 ) ;
V_11 = F_29 ( V_32 , struct V_1 , V_8 ) ;
F_11 ( V_3 , V_5 , V_11 ) ;
V_32 = V_38 ;
}
return V_39 - F_33 ( & V_5 -> V_16 ) ;
}
static void F_36 ( struct V_20 * V_20 ,
T_2 V_31 , unsigned int V_34 )
{
struct V_6 * V_37 = & F_26 ( V_20 ) -> V_4 -> V_37 ;
if ( V_31 < V_37 -> V_31 + V_37 -> V_34 && V_31 + V_34 > V_37 -> V_31 ) {
V_37 -> V_34 = 0 ;
F_37 ( V_20 ) ;
}
}
bool F_38 ( struct V_20 * V_20 , struct V_40 * V_41 )
{
struct V_2 * V_3 = F_18 ( V_20 ) ;
struct V_4 * V_5 ;
struct V_1 * V_11 ;
struct V_6 V_7 ;
if ( ! F_39 ( V_20 ) ) {
if ( V_41 && V_41 -> V_34 ) {
V_41 -> V_34 = 0 ;
return true ;
}
return false ;
}
V_5 = F_17 ( V_20 ) ;
if ( ! V_41 || ! V_41 -> V_34 )
return false ;
F_40 ( & V_7 , V_41 ) ;
F_41 ( & V_5 -> V_28 ) ;
if ( F_33 ( & V_5 -> V_16 ) )
goto V_42;
V_11 = F_31 ( V_3 , V_5 , & V_7 ) ;
if ( V_11 ) {
F_12 ( & V_3 -> V_19 ) ;
F_42 ( & V_11 -> V_14 , & V_3 -> V_43 ) ;
F_16 ( & V_3 -> V_19 ) ;
}
V_42:
F_43 ( & V_5 -> V_28 ) ;
return false ;
}
static bool F_44 ( struct V_20 * V_20 , T_2 V_44 ,
struct V_6 * V_7 )
{
struct V_2 * V_3 = F_18 ( V_20 ) ;
struct V_4 * V_5 = F_26 ( V_20 ) -> V_4 ;
struct V_1 * V_11 ;
bool V_45 = false ;
F_13 ( V_3 , ! V_5 ) ;
F_45 ( V_20 , V_44 ) ;
F_46 ( & V_5 -> V_28 ) ;
if ( V_5 -> V_37 . V_31 <= V_44 &&
V_5 -> V_37 . V_31 + V_5 -> V_37 . V_34 > V_44 ) {
* V_7 = V_5 -> V_37 ;
V_45 = true ;
F_47 ( V_3 ) ;
goto V_42;
}
V_11 = F_27 ( V_3 , V_5 , V_44 ) ;
if ( V_11 ) {
* V_7 = V_11 -> V_7 ;
F_12 ( & V_3 -> V_19 ) ;
if ( ! F_14 ( & V_11 -> V_14 ) ) {
F_48 ( & V_11 -> V_14 , & V_3 -> V_43 ) ;
V_5 -> V_18 = V_11 ;
}
F_16 ( & V_3 -> V_19 ) ;
V_45 = true ;
}
V_42:
F_49 ( V_3 ) ;
F_50 ( & V_5 -> V_28 ) ;
F_51 ( V_20 , V_44 , V_7 ) ;
return V_45 ;
}
static struct V_1 * F_52 ( struct V_4 * V_5 ,
unsigned int V_31 ,
struct V_1 * * V_46 ,
struct V_1 * * V_47 ,
struct V_8 * * * V_48 ,
struct V_8 * * V_49 )
{
struct V_8 * * V_50 = & V_5 -> V_15 . V_8 ;
struct V_8 * V_9 = NULL , * V_51 ;
struct V_1 * V_11 = V_5 -> V_18 ;
* V_48 = NULL ;
* V_49 = NULL ;
* V_46 = NULL ;
* V_47 = NULL ;
if ( F_53 ( & V_5 -> V_15 ) )
return NULL ;
if ( V_11 ) {
struct V_6 * V_33 = & V_11 -> V_7 ;
if ( V_33 -> V_31 <= V_31 && V_33 -> V_31 + V_33 -> V_34 > V_31 )
goto V_52;
}
while ( * V_50 ) {
V_9 = * V_50 ;
V_11 = F_29 ( * V_50 , struct V_1 , V_8 ) ;
if ( V_31 < V_11 -> V_7 . V_31 )
V_50 = & ( * V_50 ) -> V_35 ;
else if ( V_31 >= V_11 -> V_7 . V_31 + V_11 -> V_7 . V_34 )
V_50 = & ( * V_50 ) -> V_36 ;
else
goto V_52;
}
* V_48 = V_50 ;
* V_49 = V_9 ;
V_11 = F_29 ( V_9 , struct V_1 , V_8 ) ;
V_51 = V_9 ;
if ( V_9 && V_31 > V_11 -> V_7 . V_31 )
V_51 = F_35 ( V_9 ) ;
* V_47 = V_51 ?
F_29 ( V_51 , struct V_1 , V_8 ) : NULL ;
V_51 = V_9 ;
if ( V_9 && V_31 < V_11 -> V_7 . V_31 )
V_51 = F_54 ( V_9 ) ;
* V_46 = V_51 ?
F_29 ( V_51 , struct V_1 , V_8 ) : NULL ;
return NULL ;
V_52:
if ( V_31 == V_11 -> V_7 . V_31 ) {
V_51 = F_54 ( & V_11 -> V_8 ) ;
* V_46 = V_51 ?
F_29 ( V_51 , struct V_1 , V_8 ) : NULL ;
}
if ( V_31 == V_11 -> V_7 . V_31 + V_11 -> V_7 . V_34 - 1 ) {
V_51 = F_35 ( & V_11 -> V_8 ) ;
* V_47 = V_51 ?
F_29 ( V_51 , struct V_1 , V_8 ) : NULL ;
}
return V_11 ;
}
static struct V_1 * F_55 ( struct V_20 * V_20 ,
struct V_4 * V_5 , struct V_6 * V_7 ,
struct V_1 * V_46 ,
struct V_1 * V_47 )
{
struct V_2 * V_3 = F_18 ( V_20 ) ;
struct V_1 * V_11 = NULL ;
if ( V_46 && F_56 ( V_7 , & V_46 -> V_7 ) ) {
V_46 -> V_7 . V_34 += V_7 -> V_34 ;
V_7 = & V_46 -> V_7 ;
V_11 = V_46 ;
}
if ( V_47 && F_57 ( V_7 , & V_47 -> V_7 ) ) {
if ( V_11 )
F_11 ( V_3 , V_5 , V_46 ) ;
V_47 -> V_7 . V_31 = V_7 -> V_31 ;
V_47 -> V_7 . V_53 = V_7 -> V_53 ;
V_47 -> V_7 . V_34 += V_7 -> V_34 ;
V_11 = V_47 ;
}
if ( ! V_11 )
return NULL ;
F_58 ( V_20 , V_5 , V_11 ) ;
F_12 ( & V_3 -> V_19 ) ;
if ( ! F_14 ( & V_11 -> V_14 ) ) {
F_48 ( & V_11 -> V_14 , & V_3 -> V_43 ) ;
V_5 -> V_18 = V_11 ;
}
F_16 ( & V_3 -> V_19 ) ;
return V_11 ;
}
static struct V_1 * F_59 ( struct V_20 * V_20 ,
struct V_4 * V_5 , struct V_6 * V_7 ,
struct V_8 * * V_48 ,
struct V_8 * V_49 )
{
struct V_2 * V_3 = F_18 ( V_20 ) ;
struct V_8 * * V_10 = & V_5 -> V_15 . V_8 ;
struct V_8 * V_9 = NULL ;
struct V_1 * V_11 = NULL ;
if ( V_48 && V_49 ) {
V_9 = V_49 ;
V_10 = V_48 ;
goto V_54;
}
while ( * V_10 ) {
V_9 = * V_10 ;
V_11 = F_29 ( V_9 , struct V_1 , V_8 ) ;
if ( V_7 -> V_31 < V_11 -> V_7 . V_31 )
V_10 = & ( * V_10 ) -> V_35 ;
else if ( V_7 -> V_31 >= V_11 -> V_7 . V_31 + V_11 -> V_7 . V_34 )
V_10 = & ( * V_10 ) -> V_36 ;
else
F_13 ( V_3 , 1 ) ;
}
V_54:
V_11 = F_1 ( V_3 , V_5 , V_7 , V_9 , V_10 ) ;
if ( ! V_11 )
return NULL ;
F_58 ( V_20 , V_5 , V_11 ) ;
F_12 ( & V_3 -> V_19 ) ;
F_42 ( & V_11 -> V_14 , & V_3 -> V_43 ) ;
V_5 -> V_18 = V_11 ;
F_16 ( & V_3 -> V_19 ) ;
return V_11 ;
}
static unsigned int F_60 ( struct V_20 * V_20 ,
T_2 V_31 , T_3 V_55 , unsigned int V_34 )
{
struct V_2 * V_3 = F_18 ( V_20 ) ;
struct V_4 * V_5 = F_26 ( V_20 ) -> V_4 ;
struct V_1 * V_11 = NULL , * V_56 = NULL ;
struct V_1 * V_57 = NULL , * V_58 = NULL ;
struct V_6 V_7 , V_59 , V_60 ;
struct V_8 * * V_48 = NULL , * V_49 = NULL ;
unsigned int V_61 = V_31 + V_34 ;
unsigned int V_62 = ( unsigned int ) V_31 ;
if ( ! V_5 )
return false ;
F_61 ( V_20 , V_31 , V_55 , V_34 ) ;
F_41 ( & V_5 -> V_28 ) ;
if ( F_62 ( V_20 , V_63 ) ) {
F_43 ( & V_5 -> V_28 ) ;
return false ;
}
V_60 = V_5 -> V_37 ;
V_59 . V_34 = 0 ;
F_36 ( V_20 , V_31 , V_34 ) ;
V_11 = F_52 ( V_5 , V_31 , & V_57 , & V_58 ,
& V_48 , & V_49 ) ;
if ( ! V_11 )
V_11 = V_58 ;
while ( V_11 && V_11 -> V_7 . V_31 < V_61 ) {
unsigned int V_64 ;
int V_65 = 0 ;
V_58 = V_56 = NULL ;
V_59 = V_11 -> V_7 ;
V_64 = V_59 . V_31 + V_59 . V_34 ;
F_13 ( V_3 , V_62 >= V_64 ) ;
if ( V_62 > V_59 . V_31 && V_62 - V_59 . V_31 >= V_66 ) {
V_11 -> V_7 . V_34 = V_62 - V_11 -> V_7 . V_31 ;
V_57 = V_11 ;
V_65 = 1 ;
}
if ( V_61 < V_64 && V_64 - V_61 >= V_66 ) {
if ( V_65 ) {
F_63 ( & V_7 , V_61 ,
V_61 - V_59 . V_31 + V_59 . V_53 ,
V_64 - V_61 ) ;
V_56 = F_59 ( V_20 , V_5 , & V_7 ,
NULL , NULL ) ;
V_58 = V_56 ;
} else {
V_11 -> V_7 . V_31 = V_61 ;
V_11 -> V_7 . V_53 += V_61 - V_59 . V_31 ;
V_11 -> V_7 . V_34 -= V_61 - V_59 . V_31 ;
V_58 = V_11 ;
}
V_65 ++ ;
}
if ( ! V_58 ) {
struct V_8 * V_32 = F_35 ( & V_11 -> V_8 ) ;
V_58 = V_32 ?
F_29 ( V_32 , struct V_1 , V_8 )
: NULL ;
}
if ( V_65 )
F_58 ( V_20 , V_5 , V_11 ) ;
else
F_11 ( V_3 , V_5 , V_11 ) ;
if ( V_65 != 1 ) {
V_48 = NULL ;
V_49 = NULL ;
}
V_11 = V_58 ;
}
if ( V_55 ) {
F_63 ( & V_7 , V_31 , V_55 , V_34 ) ;
if ( ! F_55 ( V_20 , V_5 , & V_7 , V_57 , V_58 ) )
F_59 ( V_20 , V_5 , & V_7 ,
V_48 , V_49 ) ;
if ( V_59 . V_34 >= 1 &&
V_60 . V_34 < V_66 &&
V_5 -> V_37 . V_34 < V_66 ) {
F_36 ( V_20 , 0 , V_67 ) ;
F_64 ( V_20 , V_63 ) ;
}
}
if ( F_62 ( V_20 , V_63 ) )
F_32 ( V_3 , V_5 ) ;
F_43 ( & V_5 -> V_28 ) ;
return ! F_65 ( & V_60 , & V_5 -> V_37 ) ;
}
unsigned int F_66 ( struct V_2 * V_3 , int V_68 )
{
struct V_4 * V_5 , * V_38 ;
struct V_1 * V_11 ;
unsigned int V_16 = 0 , V_69 = 0 ;
int V_70 ;
if ( ! F_67 ( V_3 , V_71 ) )
return 0 ;
if ( ! F_33 ( & V_3 -> V_30 ) )
goto V_72;
if ( ! F_68 ( & V_3 -> V_23 ) )
goto V_42;
F_69 (et, next, &sbi->zombie_list, list) {
if ( F_33 ( & V_5 -> V_16 ) ) {
F_41 ( & V_5 -> V_28 ) ;
V_16 += F_32 ( V_3 , V_5 ) ;
F_43 ( & V_5 -> V_28 ) ;
}
F_13 ( V_3 , F_33 ( & V_5 -> V_16 ) ) ;
F_15 ( & V_5 -> V_14 ) ;
F_70 ( & V_3 -> V_24 , V_5 -> V_21 ) ;
F_10 ( V_25 , V_5 ) ;
F_9 ( & V_3 -> V_29 ) ;
F_9 ( & V_3 -> V_30 ) ;
V_69 ++ ;
if ( V_16 + V_69 >= V_68 )
goto V_73;
F_71 () ;
}
F_25 ( & V_3 -> V_23 ) ;
V_72:
if ( ! F_68 ( & V_3 -> V_23 ) )
goto V_42;
V_70 = V_68 - ( V_16 + V_69 ) ;
F_12 ( & V_3 -> V_19 ) ;
for (; V_70 > 0 ; V_70 -- ) {
if ( F_14 ( & V_3 -> V_43 ) )
break;
V_11 = F_72 ( & V_3 -> V_43 ,
struct V_1 , V_14 ) ;
V_5 = V_11 -> V_5 ;
if ( ! F_73 ( & V_5 -> V_28 ) ) {
F_48 ( & V_11 -> V_14 , & V_3 -> V_43 ) ;
continue;
}
F_15 ( & V_11 -> V_14 ) ;
F_16 ( & V_3 -> V_19 ) ;
F_7 ( V_3 , V_5 , V_11 ) ;
F_43 ( & V_5 -> V_28 ) ;
V_16 ++ ;
F_12 ( & V_3 -> V_19 ) ;
}
F_16 ( & V_3 -> V_19 ) ;
V_73:
F_25 ( & V_3 -> V_23 ) ;
V_42:
F_74 ( V_3 , V_16 , V_69 ) ;
return V_16 + V_69 ;
}
unsigned int F_75 ( struct V_20 * V_20 )
{
struct V_2 * V_3 = F_18 ( V_20 ) ;
struct V_4 * V_5 = F_26 ( V_20 ) -> V_4 ;
unsigned int V_16 = 0 ;
if ( ! V_5 || ! F_33 ( & V_5 -> V_16 ) )
return 0 ;
F_41 ( & V_5 -> V_28 ) ;
V_16 = F_32 ( V_3 , V_5 ) ;
F_43 ( & V_5 -> V_28 ) ;
return V_16 ;
}
void F_76 ( struct V_20 * V_20 )
{
struct V_2 * V_3 = F_18 ( V_20 ) ;
struct V_4 * V_5 = F_26 ( V_20 ) -> V_4 ;
F_64 ( V_20 , V_63 ) ;
F_41 ( & V_5 -> V_28 ) ;
F_32 ( V_3 , V_5 ) ;
F_36 ( V_20 , 0 , V_67 ) ;
F_43 ( & V_5 -> V_28 ) ;
}
void F_77 ( struct V_20 * V_20 )
{
struct V_2 * V_3 = F_18 ( V_20 ) ;
struct V_4 * V_5 = F_26 ( V_20 ) -> V_4 ;
unsigned int V_16 = 0 ;
if ( ! V_5 )
return;
if ( V_20 -> V_74 && ! F_78 ( V_20 ) &&
F_33 ( & V_5 -> V_16 ) ) {
F_19 ( & V_3 -> V_23 ) ;
F_42 ( & V_5 -> V_14 , & V_3 -> V_75 ) ;
F_6 ( & V_3 -> V_30 ) ;
F_25 ( & V_3 -> V_23 ) ;
return;
}
V_16 = F_75 ( V_20 ) ;
F_19 ( & V_3 -> V_23 ) ;
F_13 ( V_3 , F_33 ( & V_5 -> V_16 ) ) ;
F_70 ( & V_3 -> V_24 , V_20 -> V_22 ) ;
F_10 ( V_25 , V_5 ) ;
F_9 ( & V_3 -> V_29 ) ;
F_25 ( & V_3 -> V_23 ) ;
F_26 ( V_20 ) -> V_4 = NULL ;
F_79 ( V_20 , V_16 ) ;
}
bool F_80 ( struct V_20 * V_20 , T_2 V_44 ,
struct V_6 * V_7 )
{
if ( ! F_39 ( V_20 ) )
return false ;
return F_44 ( V_20 , V_44 , V_7 ) ;
}
void F_81 ( struct V_76 * V_77 )
{
T_2 V_31 ;
T_3 V_55 ;
if ( ! F_39 ( V_77 -> V_20 ) )
return;
if ( V_77 -> V_78 == V_79 )
V_55 = V_80 ;
else
V_55 = V_77 -> V_78 ;
V_31 = F_82 ( F_83 ( V_77 -> V_81 ) , V_77 -> V_20 ) +
V_77 -> V_82 ;
F_60 ( V_77 -> V_20 , V_31 , V_55 , 1 ) ;
}
void F_84 ( struct V_76 * V_77 ,
T_2 V_31 , T_3 V_55 , unsigned int V_34 )
{
if ( ! F_39 ( V_77 -> V_20 ) )
return;
F_60 ( V_77 -> V_20 , V_31 , V_55 , V_34 ) ;
}
void F_85 ( struct V_2 * V_3 )
{
F_86 ( & V_3 -> V_24 , V_83 ) ;
F_87 ( & V_3 -> V_23 ) ;
F_3 ( & V_3 -> V_43 ) ;
F_88 ( & V_3 -> V_19 ) ;
F_24 ( & V_3 -> V_29 , 0 ) ;
F_3 ( & V_3 -> V_75 ) ;
F_24 ( & V_3 -> V_30 , 0 ) ;
F_24 ( & V_3 -> V_17 , 0 ) ;
}
int T_4 F_89 ( void )
{
V_25 = F_90 ( L_1 ,
sizeof( struct V_4 ) ) ;
if ( ! V_25 )
return - V_84 ;
V_12 = F_90 ( L_2 ,
sizeof( struct V_1 ) ) ;
if ( ! V_12 ) {
F_91 ( V_25 ) ;
return - V_84 ;
}
return 0 ;
}
void F_92 ( void )
{
F_91 ( V_12 ) ;
F_91 ( V_25 ) ;
}
