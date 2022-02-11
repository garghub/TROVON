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
struct V_5 * V_6 )
{
struct V_3 * V_4 = V_6 -> V_42 ;
return V_6 -> V_19 <= V_4 -> V_38 &&
V_6 -> V_18 >= V_4 -> V_38 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_43 )
{
struct V_3 * V_4 = V_6 -> V_42 ;
struct V_40 * V_41 = V_2 -> V_44 ;
unsigned long V_45 = 0 ;
struct V_46 * V_46 ;
T_1 V_47 = 0 ;
int V_48 ;
unsigned long long V_49 = 0 ;
V_48 = V_6 -> V_21 ;
V_46 = V_6 -> V_50 ;
if ( V_46 ) {
struct V_51 * V_51 = F_15 ( V_6 -> V_50 ) ;
V_47 = V_51 -> V_52 -> V_53 ;
V_45 = V_51 -> V_54 ;
V_49 = ( V_55 ) V_6 -> V_56 << V_37 ;
}
F_16 ( V_2 , 25 + sizeof( void * ) * 6 - 1 ) ;
F_8 ( V_2 ,
L_4 ,
V_6 -> V_19 ,
V_6 -> V_18 ,
V_48 & V_57 ? 'r' : '-' ,
V_48 & V_58 ? 'w' : '-' ,
V_48 & V_59 ? 'x' : '-' ,
V_48 & V_22 ? V_48 & V_60 ? 'S' : 's' : 'p' ,
V_49 ,
F_17 ( V_47 ) , F_18 ( V_47 ) , V_45 ) ;
if ( V_46 ) {
F_19 ( V_2 , ' ' ) ;
F_20 ( V_2 , V_46 , L_5 ) ;
} else if ( V_4 && F_13 ( V_41 , V_6 ) ) {
F_19 ( V_2 , ' ' ) ;
F_8 ( V_2 , L_6 ) ;
}
F_21 ( V_2 , '\n' ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , void * V_61 , int V_43 )
{
struct V_9 * V_10 = V_61 ;
return F_14 ( V_2 , F_5 ( V_10 , struct V_5 , V_17 ) ,
V_43 ) ;
}
static int F_23 ( struct V_1 * V_2 , void * V_61 )
{
return F_22 ( V_2 , V_61 , 1 ) ;
}
static int F_24 ( struct V_1 * V_2 , void * V_61 )
{
return F_22 ( V_2 , V_61 , 0 ) ;
}
static void * F_25 ( struct V_1 * V_2 , V_55 * V_62 )
{
struct V_40 * V_41 = V_2 -> V_44 ;
struct V_3 * V_4 ;
struct V_9 * V_10 ;
V_55 V_63 = * V_62 ;
V_41 -> V_64 = F_26 ( V_41 -> V_51 ) ;
if ( ! V_41 -> V_64 )
return F_27 ( - V_65 ) ;
V_4 = V_41 -> V_4 ;
if ( ! V_4 || ! F_28 ( & V_4 -> V_66 ) )
return NULL ;
F_2 ( & V_4 -> V_15 ) ;
for ( V_10 = F_3 ( & V_4 -> V_16 ) ; V_10 ; V_10 = F_4 ( V_10 ) )
if ( V_63 -- == 0 )
return V_10 ;
F_9 ( & V_4 -> V_15 ) ;
F_29 ( V_4 ) ;
return NULL ;
}
static void F_30 ( struct V_1 * V_2 , void * V_67 )
{
struct V_40 * V_41 = V_2 -> V_44 ;
if ( ! F_31 ( V_67 ) ) {
F_9 ( & V_41 -> V_4 -> V_15 ) ;
F_29 ( V_41 -> V_4 ) ;
}
if ( V_41 -> V_64 ) {
F_32 ( V_41 -> V_64 ) ;
V_41 -> V_64 = NULL ;
}
}
static void * F_33 ( struct V_1 * V_2 , void * V_61 , V_55 * V_62 )
{
struct V_9 * V_10 = V_61 ;
( * V_62 ) ++ ;
return V_10 ? F_4 ( V_10 ) : NULL ;
}
static int F_34 ( struct V_51 * V_51 , struct V_46 * V_46 ,
const struct V_68 * V_69 )
{
struct V_40 * V_41 ;
V_41 = F_35 ( V_46 , V_69 , sizeof( * V_41 ) ) ;
if ( ! V_41 )
return - V_70 ;
V_41 -> V_51 = V_51 ;
V_41 -> V_4 = F_36 ( V_51 , V_71 ) ;
if ( F_37 ( V_41 -> V_4 ) ) {
int V_72 = F_38 ( V_41 -> V_4 ) ;
F_39 ( V_51 , V_46 ) ;
return V_72 ;
}
return 0 ;
}
static int F_40 ( struct V_51 * V_51 , struct V_46 * V_46 )
{
struct V_1 * V_73 = V_46 -> V_74 ;
struct V_40 * V_41 = V_73 -> V_44 ;
if ( V_41 -> V_4 )
F_41 ( V_41 -> V_4 ) ;
return F_39 ( V_51 , V_46 ) ;
}
static int F_42 ( struct V_51 * V_51 , struct V_46 * V_46 )
{
return F_34 ( V_51 , V_46 , & V_75 ) ;
}
static int F_43 ( struct V_51 * V_51 , struct V_46 * V_46 )
{
return F_34 ( V_51 , V_46 , & V_76 ) ;
}
