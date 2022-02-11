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
static T_1 F_13 ( struct V_40 * V_41 ,
struct V_5 * V_6 , bool V_42 )
{
struct V_43 * V_43 = V_41 -> V_43 ;
struct V_44 * V_45 ;
T_1 V_46 = 0 ;
F_14 () ;
V_45 = F_15 ( F_16 ( V_43 ) , V_47 ) ;
if ( V_45 ) {
V_45 = F_17 ( V_45 , V_6 , V_42 ) ;
if ( V_45 )
V_46 = F_18 ( V_45 , V_43 -> V_48 -> V_49 ) ;
}
F_19 () ;
return V_46 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_42 )
{
struct V_3 * V_4 = V_6 -> V_50 ;
struct V_40 * V_41 = V_2 -> V_51 ;
unsigned long V_52 = 0 ;
struct V_53 * V_53 ;
T_2 V_54 = 0 ;
int V_55 ;
unsigned long long V_56 = 0 ;
V_55 = V_6 -> V_21 ;
V_53 = V_6 -> V_57 ;
if ( V_53 ) {
struct V_43 * V_43 = F_21 ( V_6 -> V_57 ) ;
V_54 = V_43 -> V_48 -> V_58 ;
V_52 = V_43 -> V_59 ;
V_56 = ( V_60 ) V_6 -> V_61 << V_37 ;
}
F_22 ( V_2 , 25 + sizeof( void * ) * 6 - 1 ) ;
F_8 ( V_2 ,
L_4 ,
V_6 -> V_19 ,
V_6 -> V_18 ,
V_55 & V_62 ? 'r' : '-' ,
V_55 & V_63 ? 'w' : '-' ,
V_55 & V_64 ? 'x' : '-' ,
V_55 & V_22 ? V_55 & V_65 ? 'S' : 's' : 'p' ,
V_56 ,
F_23 ( V_54 ) , F_24 ( V_54 ) , V_52 ) ;
if ( V_53 ) {
F_25 ( V_2 , ' ' ) ;
F_26 ( V_2 , V_53 , L_5 ) ;
} else if ( V_4 ) {
T_1 V_66 = F_13 ( V_41 , V_6 , V_42 ) ;
if ( V_66 != 0 ) {
F_25 ( V_2 , ' ' ) ;
if ( ! V_42 || ( V_6 -> V_19 <= V_4 -> V_38 &&
V_6 -> V_18 >= V_4 -> V_38 ) )
F_8 ( V_2 , L_6 ) ;
else
F_8 ( V_2 , L_7 , V_66 ) ;
}
}
F_27 ( V_2 , '\n' ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , void * V_67 , int V_42 )
{
struct V_9 * V_10 = V_67 ;
return F_20 ( V_2 , F_5 ( V_10 , struct V_5 , V_17 ) ,
V_42 ) ;
}
static int F_29 ( struct V_1 * V_2 , void * V_67 )
{
return F_28 ( V_2 , V_67 , 1 ) ;
}
static int F_30 ( struct V_1 * V_2 , void * V_67 )
{
return F_28 ( V_2 , V_67 , 0 ) ;
}
static void * F_31 ( struct V_1 * V_2 , V_60 * V_68 )
{
struct V_40 * V_41 = V_2 -> V_51 ;
struct V_3 * V_4 ;
struct V_9 * V_10 ;
V_60 V_69 = * V_68 ;
V_41 -> V_45 = F_32 ( V_41 -> V_43 ) ;
if ( ! V_41 -> V_45 )
return F_33 ( - V_70 ) ;
V_4 = V_41 -> V_4 ;
if ( ! V_4 || ! F_34 ( & V_4 -> V_71 ) )
return NULL ;
F_2 ( & V_4 -> V_15 ) ;
for ( V_10 = F_3 ( & V_4 -> V_16 ) ; V_10 ; V_10 = F_4 ( V_10 ) )
if ( V_69 -- == 0 )
return V_10 ;
F_9 ( & V_4 -> V_15 ) ;
F_35 ( V_4 ) ;
return NULL ;
}
static void F_36 ( struct V_1 * V_2 , void * V_72 )
{
struct V_40 * V_41 = V_2 -> V_51 ;
if ( ! F_37 ( V_72 ) ) {
F_9 ( & V_41 -> V_4 -> V_15 ) ;
F_35 ( V_41 -> V_4 ) ;
}
if ( V_41 -> V_45 ) {
F_38 ( V_41 -> V_45 ) ;
V_41 -> V_45 = NULL ;
}
}
static void * F_39 ( struct V_1 * V_2 , void * V_67 , V_60 * V_68 )
{
struct V_9 * V_10 = V_67 ;
( * V_68 ) ++ ;
return V_10 ? F_4 ( V_10 ) : NULL ;
}
static int F_40 ( struct V_43 * V_43 , struct V_53 * V_53 ,
const struct V_73 * V_74 )
{
struct V_40 * V_41 ;
V_41 = F_41 ( V_53 , V_74 , sizeof( * V_41 ) ) ;
if ( ! V_41 )
return - V_75 ;
V_41 -> V_43 = V_43 ;
V_41 -> V_4 = F_42 ( V_43 , V_76 ) ;
if ( F_43 ( V_41 -> V_4 ) ) {
int V_77 = F_44 ( V_41 -> V_4 ) ;
F_45 ( V_43 , V_53 ) ;
return V_77 ;
}
return 0 ;
}
static int F_46 ( struct V_43 * V_43 , struct V_53 * V_53 )
{
struct V_1 * V_78 = V_53 -> V_79 ;
struct V_40 * V_41 = V_78 -> V_51 ;
if ( V_41 -> V_4 )
F_47 ( V_41 -> V_4 ) ;
return F_45 ( V_43 , V_53 ) ;
}
static int F_48 ( struct V_43 * V_43 , struct V_53 * V_53 )
{
return F_40 ( V_43 , V_53 , & V_80 ) ;
}
static int F_49 ( struct V_43 * V_43 , struct V_53 * V_53 )
{
return F_40 ( V_43 , V_53 , & V_81 ) ;
}
