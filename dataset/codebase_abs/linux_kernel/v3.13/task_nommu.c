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
static int F_13 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_40 )
{
struct V_3 * V_4 = V_6 -> V_41 ;
struct V_42 * V_43 = V_2 -> V_44 ;
unsigned long V_45 = 0 ;
struct V_46 * V_46 ;
T_1 V_47 = 0 ;
int V_48 ;
unsigned long long V_49 = 0 ;
V_48 = V_6 -> V_21 ;
V_46 = V_6 -> V_50 ;
if ( V_46 ) {
struct V_51 * V_51 = F_14 ( V_6 -> V_50 ) ;
V_47 = V_51 -> V_52 -> V_53 ;
V_45 = V_51 -> V_54 ;
V_49 = ( V_55 ) V_6 -> V_56 << V_37 ;
}
F_15 ( V_2 , 25 + sizeof( void * ) * 6 - 1 ) ;
F_8 ( V_2 ,
L_4 ,
V_6 -> V_19 ,
V_6 -> V_18 ,
V_48 & V_57 ? 'r' : '-' ,
V_48 & V_58 ? 'w' : '-' ,
V_48 & V_59 ? 'x' : '-' ,
V_48 & V_22 ? V_48 & V_60 ? 'S' : 's' : 'p' ,
V_49 ,
F_16 ( V_47 ) , F_17 ( V_47 ) , V_45 ) ;
if ( V_46 ) {
F_18 ( V_2 , ' ' ) ;
F_19 ( V_2 , & V_46 -> V_61 , L_5 ) ;
} else if ( V_4 ) {
T_2 V_62 = F_20 ( V_43 -> V_63 , V_6 , V_40 ) ;
if ( V_62 != 0 ) {
F_18 ( V_2 , ' ' ) ;
if ( ! V_40 || ( V_6 -> V_19 <= V_4 -> V_38 &&
V_6 -> V_18 >= V_4 -> V_38 ) )
F_8 ( V_2 , L_6 ) ;
else
F_8 ( V_2 , L_7 , V_62 ) ;
}
}
F_21 ( V_2 , '\n' ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , void * V_64 , int V_40 )
{
struct V_9 * V_10 = V_64 ;
return F_13 ( V_2 , F_5 ( V_10 , struct V_5 , V_17 ) ,
V_40 ) ;
}
static int F_23 ( struct V_1 * V_2 , void * V_64 )
{
return F_22 ( V_2 , V_64 , 1 ) ;
}
static int F_24 ( struct V_1 * V_2 , void * V_64 )
{
return F_22 ( V_2 , V_64 , 0 ) ;
}
static void * F_25 ( struct V_1 * V_2 , V_55 * V_65 )
{
struct V_42 * V_43 = V_2 -> V_44 ;
struct V_3 * V_4 ;
struct V_9 * V_10 ;
V_55 V_66 = * V_65 ;
V_43 -> V_63 = F_26 ( V_43 -> V_67 , V_68 ) ;
if ( ! V_43 -> V_63 )
return F_27 ( - V_69 ) ;
V_4 = F_28 ( V_43 -> V_63 , V_70 ) ;
if ( ! V_4 || F_29 ( V_4 ) ) {
F_30 ( V_43 -> V_63 ) ;
V_43 -> V_63 = NULL ;
return V_4 ;
}
F_2 ( & V_4 -> V_15 ) ;
for ( V_10 = F_3 ( & V_4 -> V_16 ) ; V_10 ; V_10 = F_4 ( V_10 ) )
if ( V_66 -- == 0 )
return V_10 ;
return NULL ;
}
static void F_31 ( struct V_1 * V_2 , void * V_71 )
{
struct V_42 * V_43 = V_2 -> V_44 ;
if ( V_43 -> V_63 ) {
struct V_3 * V_4 = V_43 -> V_63 -> V_4 ;
F_9 ( & V_4 -> V_15 ) ;
F_32 ( V_4 ) ;
F_30 ( V_43 -> V_63 ) ;
}
}
static void * F_33 ( struct V_1 * V_2 , void * V_64 , V_55 * V_65 )
{
struct V_9 * V_10 = V_64 ;
( * V_65 ) ++ ;
return V_10 ? F_4 ( V_10 ) : NULL ;
}
static int F_34 ( struct V_51 * V_51 , struct V_46 * V_46 ,
const struct V_72 * V_73 )
{
struct V_42 * V_43 ;
int V_74 = - V_75 ;
V_43 = F_35 ( sizeof( * V_43 ) , V_76 ) ;
if ( V_43 ) {
V_43 -> V_67 = F_36 ( V_51 ) ;
V_74 = F_37 ( V_46 , V_73 ) ;
if ( ! V_74 ) {
struct V_1 * V_2 = V_46 -> V_77 ;
V_2 -> V_44 = V_43 ;
} else {
F_38 ( V_43 ) ;
}
}
return V_74 ;
}
static int F_39 ( struct V_51 * V_51 , struct V_46 * V_46 )
{
return F_34 ( V_51 , V_46 , & V_78 ) ;
}
static int F_40 ( struct V_51 * V_51 , struct V_46 * V_46 )
{
return F_34 ( V_51 , V_46 , & V_79 ) ;
}
