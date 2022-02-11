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
static int F_14 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_41 )
{
struct V_3 * V_4 = V_6 -> V_42 ;
struct V_43 * V_44 = V_2 -> V_45 ;
unsigned long V_46 = 0 ;
struct V_47 * V_47 ;
T_1 V_48 = 0 ;
int V_49 , V_40 ;
unsigned long long V_50 = 0 ;
V_49 = V_6 -> V_21 ;
V_47 = V_6 -> V_51 ;
if ( V_47 ) {
struct V_52 * V_52 = V_6 -> V_51 -> V_53 . V_54 -> V_55 ;
V_48 = V_52 -> V_56 -> V_57 ;
V_46 = V_52 -> V_58 ;
V_50 = ( V_59 ) V_6 -> V_60 << V_37 ;
}
F_8 ( V_2 ,
L_5 ,
V_6 -> V_19 ,
V_6 -> V_18 ,
V_49 & V_61 ? 'r' : '-' ,
V_49 & V_62 ? 'w' : '-' ,
V_49 & V_63 ? 'x' : '-' ,
V_49 & V_22 ? V_49 & V_64 ? 'S' : 's' : 'p' ,
V_50 ,
F_15 ( V_48 ) , F_16 ( V_48 ) , V_46 , & V_40 ) ;
if ( V_47 ) {
F_13 ( V_2 , V_40 ) ;
F_17 ( V_2 , & V_47 -> V_53 , L_6 ) ;
} else if ( V_4 ) {
T_2 V_65 = F_18 ( V_44 -> V_66 , V_6 , V_41 ) ;
if ( V_65 != 0 ) {
F_13 ( V_2 , V_40 ) ;
if ( ! V_41 || ( V_6 -> V_19 <= V_4 -> V_38 &&
V_6 -> V_18 >= V_4 -> V_38 ) )
F_8 ( V_2 , L_7 ) ;
else
F_8 ( V_2 , L_8 , V_65 ) ;
}
}
F_19 ( V_2 , '\n' ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , void * V_67 , int V_41 )
{
struct V_9 * V_10 = V_67 ;
return F_14 ( V_2 , F_5 ( V_10 , struct V_5 , V_17 ) ,
V_41 ) ;
}
static int F_21 ( struct V_1 * V_2 , void * V_67 )
{
return F_20 ( V_2 , V_67 , 1 ) ;
}
static int F_22 ( struct V_1 * V_2 , void * V_67 )
{
return F_20 ( V_2 , V_67 , 0 ) ;
}
static void * F_23 ( struct V_1 * V_2 , V_59 * V_68 )
{
struct V_43 * V_44 = V_2 -> V_45 ;
struct V_3 * V_4 ;
struct V_9 * V_10 ;
V_59 V_69 = * V_68 ;
V_44 -> V_66 = F_24 ( V_44 -> V_70 , V_71 ) ;
if ( ! V_44 -> V_66 )
return F_25 ( - V_72 ) ;
V_4 = F_26 ( V_44 -> V_66 ) ;
if ( ! V_4 || F_27 ( V_4 ) ) {
F_28 ( V_44 -> V_66 ) ;
V_44 -> V_66 = NULL ;
return V_4 ;
}
F_2 ( & V_4 -> V_15 ) ;
for ( V_10 = F_3 ( & V_4 -> V_16 ) ; V_10 ; V_10 = F_4 ( V_10 ) )
if ( V_69 -- == 0 )
return V_10 ;
return NULL ;
}
static void F_29 ( struct V_1 * V_2 , void * V_73 )
{
struct V_43 * V_44 = V_2 -> V_45 ;
if ( V_44 -> V_66 ) {
struct V_3 * V_4 = V_44 -> V_66 -> V_4 ;
F_9 ( & V_4 -> V_15 ) ;
F_30 ( V_4 ) ;
F_28 ( V_44 -> V_66 ) ;
}
}
static void * F_31 ( struct V_1 * V_2 , void * V_67 , V_59 * V_68 )
{
struct V_9 * V_10 = V_67 ;
( * V_68 ) ++ ;
return V_10 ? F_4 ( V_10 ) : NULL ;
}
static int F_32 ( struct V_52 * V_52 , struct V_47 * V_47 ,
const struct V_74 * V_75 )
{
struct V_43 * V_44 ;
int V_76 = - V_77 ;
V_44 = F_33 ( sizeof( * V_44 ) , V_78 ) ;
if ( V_44 ) {
V_44 -> V_70 = F_34 ( V_52 ) ;
V_76 = F_35 ( V_47 , V_75 ) ;
if ( ! V_76 ) {
struct V_1 * V_2 = V_47 -> V_79 ;
V_2 -> V_45 = V_44 ;
} else {
F_36 ( V_44 ) ;
}
}
return V_76 ;
}
static int F_37 ( struct V_52 * V_52 , struct V_47 * V_47 )
{
return F_32 ( V_52 , V_47 , & V_80 ) ;
}
static int F_38 ( struct V_52 * V_52 , struct V_47 * V_47 )
{
return F_32 ( V_52 , V_47 , & V_81 ) ;
}
