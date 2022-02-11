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
static void F_13 ( struct V_1 * V_2 , int V_40 )
{
V_40 = 25 + sizeof( void * ) * 6 - V_40 ;
if ( V_40 < 1 )
V_40 = 1 ;
F_8 ( V_2 , L_4 , V_40 , ' ' ) ;
}
static int F_14 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_3 * V_4 = V_6 -> V_41 ;
unsigned long V_42 = 0 ;
struct V_43 * V_43 ;
T_1 V_44 = 0 ;
int V_45 , V_40 ;
unsigned long long V_46 = 0 ;
V_45 = V_6 -> V_21 ;
V_43 = V_6 -> V_47 ;
if ( V_43 ) {
struct V_48 * V_48 = V_6 -> V_47 -> V_49 . V_50 -> V_51 ;
V_44 = V_48 -> V_52 -> V_53 ;
V_42 = V_48 -> V_54 ;
V_46 = ( V_55 ) V_6 -> V_56 << V_37 ;
}
F_8 ( V_2 ,
L_5 ,
V_6 -> V_19 ,
V_6 -> V_18 ,
V_45 & V_57 ? 'r' : '-' ,
V_45 & V_58 ? 'w' : '-' ,
V_45 & V_59 ? 'x' : '-' ,
V_45 & V_22 ? V_45 & V_60 ? 'S' : 's' : 'p' ,
V_46 ,
F_15 ( V_44 ) , F_16 ( V_44 ) , V_42 , & V_40 ) ;
if ( V_43 ) {
F_13 ( V_2 , V_40 ) ;
F_17 ( V_2 , & V_43 -> V_49 , L_6 ) ;
} else if ( V_4 ) {
if ( V_6 -> V_19 <= V_4 -> V_38 &&
V_6 -> V_18 >= V_4 -> V_38 ) {
F_13 ( V_2 , V_40 ) ;
F_18 ( V_2 , L_7 ) ;
}
}
F_19 ( V_2 , '\n' ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , void * V_61 )
{
struct V_9 * V_10 = V_61 ;
return F_14 ( V_2 , F_5 ( V_10 , struct V_5 , V_17 ) ) ;
}
static void * F_21 ( struct V_1 * V_2 , V_55 * V_62 )
{
struct V_63 * V_64 = V_2 -> V_65 ;
struct V_3 * V_4 ;
struct V_9 * V_10 ;
V_55 V_66 = * V_62 ;
V_64 -> V_67 = F_22 ( V_64 -> V_68 , V_69 ) ;
if ( ! V_64 -> V_67 )
return F_23 ( - V_70 ) ;
V_4 = F_24 ( V_64 -> V_67 ) ;
if ( ! V_4 || F_25 ( V_4 ) ) {
F_26 ( V_64 -> V_67 ) ;
V_64 -> V_67 = NULL ;
return V_4 ;
}
F_2 ( & V_4 -> V_15 ) ;
for ( V_10 = F_3 ( & V_4 -> V_16 ) ; V_10 ; V_10 = F_4 ( V_10 ) )
if ( V_66 -- == 0 )
return V_10 ;
return NULL ;
}
static void F_27 ( struct V_1 * V_2 , void * V_71 )
{
struct V_63 * V_64 = V_2 -> V_65 ;
if ( V_64 -> V_67 ) {
struct V_3 * V_4 = V_64 -> V_67 -> V_4 ;
F_9 ( & V_4 -> V_15 ) ;
F_28 ( V_4 ) ;
F_26 ( V_64 -> V_67 ) ;
}
}
static void * F_29 ( struct V_1 * V_2 , void * V_61 , V_55 * V_62 )
{
struct V_9 * V_10 = V_61 ;
( * V_62 ) ++ ;
return V_10 ? F_4 ( V_10 ) : NULL ;
}
static int F_30 ( struct V_48 * V_48 , struct V_43 * V_43 )
{
struct V_63 * V_64 ;
int V_72 = - V_73 ;
V_64 = F_31 ( sizeof( * V_64 ) , V_74 ) ;
if ( V_64 ) {
V_64 -> V_68 = F_32 ( V_48 ) ;
V_72 = F_33 ( V_43 , & V_75 ) ;
if ( ! V_72 ) {
struct V_1 * V_2 = V_43 -> V_76 ;
V_2 -> V_65 = V_64 ;
} else {
F_34 ( V_64 ) ;
}
}
return V_72 ;
}
