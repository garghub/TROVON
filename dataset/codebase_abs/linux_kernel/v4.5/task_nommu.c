void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
unsigned long V_11 = 0 , V_12 = 0 , V_13 = 0 , V_14 ;
F_2 ( & V_4 -> V_15 ) ;
for ( V_10 = F_3 ( & V_4 -> V_16 ) ; V_10 ; V_10 = F_4 ( V_10 ) ) {
V_6 = F_5 ( V_10 , struct V_5 , V_17 ) ;
V_11 += F_6 ( V_6 ) ;
V_8 = V_6 -> V_7 ;
if ( V_8 ) {
V_14 = F_6 ( V_8 ) ;
V_14 += V_8 -> V_18 - V_8 -> V_19 ;
} else {
V_14 = V_6 -> V_18 - V_6 -> V_19 ;
}
if ( F_7 ( & V_4 -> V_20 ) > 1 ||
V_6 -> V_21 & V_22 ) {
V_12 += V_14 ;
} else {
V_11 += V_14 ;
if ( V_8 )
V_13 = V_8 -> V_18 - V_6 -> V_18 ;
}
}
if ( F_7 ( & V_4 -> V_20 ) > 1 )
V_12 += F_6 ( V_4 ) ;
else
V_11 += F_6 ( V_4 ) ;
if ( V_23 -> V_24 && V_23 -> V_24 -> V_25 > 1 )
V_12 += F_6 ( V_23 -> V_24 ) ;
else
V_11 += F_6 ( V_23 -> V_24 ) ;
if ( V_23 -> V_26 && F_7 ( & V_23 -> V_26 -> V_27 ) > 1 )
V_12 += F_6 ( V_23 -> V_26 ) ;
else
V_11 += F_6 ( V_23 -> V_26 ) ;
if ( V_23 -> V_28 && F_7 ( & V_23 -> V_28 -> V_27 ) > 1 )
V_12 += F_6 ( V_23 -> V_28 ) ;
else
V_11 += F_6 ( V_23 -> V_28 ) ;
V_11 += F_6 ( V_23 ) ;
F_8 ( V_2 ,
L_1
L_2
L_3 ,
V_11 , V_13 , V_12 ) ;
F_9 ( & V_4 -> V_15 ) ;
}
unsigned long F_10 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_9 * V_10 ;
unsigned long V_29 = 0 ;
F_2 ( & V_4 -> V_15 ) ;
for ( V_10 = F_3 ( & V_4 -> V_16 ) ; V_10 ; V_10 = F_4 ( V_10 ) ) {
V_6 = F_5 ( V_10 , struct V_5 , V_17 ) ;
V_29 += V_6 -> V_18 - V_6 -> V_19 ;
}
F_9 ( & V_4 -> V_15 ) ;
return V_29 ;
}
unsigned long F_11 ( struct V_3 * V_4 ,
unsigned long * V_30 , unsigned long * V_31 ,
unsigned long * V_32 , unsigned long * V_33 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
unsigned long V_14 = F_6 ( V_4 ) ;
F_2 ( & V_4 -> V_15 ) ;
for ( V_10 = F_3 ( & V_4 -> V_16 ) ; V_10 ; V_10 = F_4 ( V_10 ) ) {
V_6 = F_5 ( V_10 , struct V_5 , V_17 ) ;
V_14 += F_6 ( V_6 ) ;
V_8 = V_6 -> V_7 ;
if ( V_8 ) {
V_14 += F_6 ( V_8 ) ;
V_14 += V_8 -> V_18 - V_8 -> V_19 ;
}
}
* V_31 = ( F_12 ( V_4 -> V_34 ) - ( V_4 -> V_35 & V_36 ) )
>> V_37 ;
* V_32 = ( F_12 ( V_4 -> V_38 ) - ( V_4 -> V_39 & V_36 ) )
>> V_37 ;
F_9 ( & V_4 -> V_15 ) ;
V_14 >>= V_37 ;
V_14 += * V_31 + * V_32 ;
* V_33 = V_14 ;
return V_14 ;
}
static int F_13 ( struct V_40 * V_41 ,
struct V_5 * V_6 , int V_42 )
{
struct V_3 * V_4 = V_6 -> V_43 ;
int V_44 = 0 ;
if ( V_42 ) {
V_44 = V_6 -> V_19 <= V_4 -> V_38 &&
V_6 -> V_18 >= V_4 -> V_38 ;
} else {
struct V_45 * V_45 = V_41 -> V_45 ;
struct V_46 * V_47 ;
F_14 () ;
V_47 = F_15 ( F_16 ( V_45 ) , V_48 ) ;
if ( V_47 )
V_44 = F_17 ( V_6 , V_47 ) ;
F_18 () ;
}
return V_44 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_42 )
{
struct V_3 * V_4 = V_6 -> V_43 ;
struct V_40 * V_41 = V_2 -> V_49 ;
unsigned long V_50 = 0 ;
struct V_51 * V_51 ;
T_1 V_52 = 0 ;
int V_53 ;
unsigned long long V_54 = 0 ;
V_53 = V_6 -> V_21 ;
V_51 = V_6 -> V_55 ;
if ( V_51 ) {
struct V_45 * V_45 = F_20 ( V_6 -> V_55 ) ;
V_52 = V_45 -> V_56 -> V_57 ;
V_50 = V_45 -> V_58 ;
V_54 = ( V_59 ) V_6 -> V_60 << V_37 ;
}
F_21 ( V_2 , 25 + sizeof( void * ) * 6 - 1 ) ;
F_8 ( V_2 ,
L_4 ,
V_6 -> V_19 ,
V_6 -> V_18 ,
V_53 & V_61 ? 'r' : '-' ,
V_53 & V_62 ? 'w' : '-' ,
V_53 & V_63 ? 'x' : '-' ,
V_53 & V_22 ? V_53 & V_64 ? 'S' : 's' : 'p' ,
V_54 ,
F_22 ( V_52 ) , F_23 ( V_52 ) , V_50 ) ;
if ( V_51 ) {
F_24 ( V_2 , ' ' ) ;
F_25 ( V_2 , V_51 , L_5 ) ;
} else if ( V_4 && F_13 ( V_41 , V_6 , V_42 ) ) {
F_24 ( V_2 , ' ' ) ;
F_8 ( V_2 , L_6 ) ;
}
F_26 ( V_2 , '\n' ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , void * V_65 , int V_42 )
{
struct V_9 * V_10 = V_65 ;
return F_19 ( V_2 , F_5 ( V_10 , struct V_5 , V_17 ) ,
V_42 ) ;
}
static int F_28 ( struct V_1 * V_2 , void * V_65 )
{
return F_27 ( V_2 , V_65 , 1 ) ;
}
static int F_29 ( struct V_1 * V_2 , void * V_65 )
{
return F_27 ( V_2 , V_65 , 0 ) ;
}
static void * F_30 ( struct V_1 * V_2 , V_59 * V_66 )
{
struct V_40 * V_41 = V_2 -> V_49 ;
struct V_3 * V_4 ;
struct V_9 * V_10 ;
V_59 V_67 = * V_66 ;
V_41 -> V_47 = F_31 ( V_41 -> V_45 ) ;
if ( ! V_41 -> V_47 )
return F_32 ( - V_68 ) ;
V_4 = V_41 -> V_4 ;
if ( ! V_4 || ! F_33 ( & V_4 -> V_69 ) )
return NULL ;
F_2 ( & V_4 -> V_15 ) ;
for ( V_10 = F_3 ( & V_4 -> V_16 ) ; V_10 ; V_10 = F_4 ( V_10 ) )
if ( V_67 -- == 0 )
return V_10 ;
F_9 ( & V_4 -> V_15 ) ;
F_34 ( V_4 ) ;
return NULL ;
}
static void F_35 ( struct V_1 * V_2 , void * V_70 )
{
struct V_40 * V_41 = V_2 -> V_49 ;
if ( ! F_36 ( V_70 ) ) {
F_9 ( & V_41 -> V_4 -> V_15 ) ;
F_34 ( V_41 -> V_4 ) ;
}
if ( V_41 -> V_47 ) {
F_37 ( V_41 -> V_47 ) ;
V_41 -> V_47 = NULL ;
}
}
static void * F_38 ( struct V_1 * V_2 , void * V_65 , V_59 * V_66 )
{
struct V_9 * V_10 = V_65 ;
( * V_66 ) ++ ;
return V_10 ? F_4 ( V_10 ) : NULL ;
}
static int F_39 ( struct V_45 * V_45 , struct V_51 * V_51 ,
const struct V_71 * V_72 )
{
struct V_40 * V_41 ;
V_41 = F_40 ( V_51 , V_72 , sizeof( * V_41 ) ) ;
if ( ! V_41 )
return - V_73 ;
V_41 -> V_45 = V_45 ;
V_41 -> V_4 = F_41 ( V_45 , V_74 ) ;
if ( F_42 ( V_41 -> V_4 ) ) {
int V_75 = F_43 ( V_41 -> V_4 ) ;
F_44 ( V_45 , V_51 ) ;
return V_75 ;
}
return 0 ;
}
static int F_45 ( struct V_45 * V_45 , struct V_51 * V_51 )
{
struct V_1 * V_76 = V_51 -> V_77 ;
struct V_40 * V_41 = V_76 -> V_49 ;
if ( V_41 -> V_4 )
F_46 ( V_41 -> V_4 ) ;
return F_44 ( V_45 , V_51 ) ;
}
static int F_47 ( struct V_45 * V_45 , struct V_51 * V_51 )
{
return F_39 ( V_45 , V_51 , & V_78 ) ;
}
static int F_48 ( struct V_45 * V_45 , struct V_51 * V_51 )
{
return F_39 ( V_45 , V_51 , & V_79 ) ;
}
