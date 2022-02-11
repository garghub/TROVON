static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) F_2 ( V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 ,
struct V_4 * V_5 , int V_6 )
{
return F_4 ( V_3 , V_5 -> V_7 ,
V_6 , & V_5 -> V_8 ) ;
}
static void F_5 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
F_6 ( V_5 -> V_8 ) ;
F_7 ( V_3 ) ;
F_8 ( V_5 -> V_8 ) ;
}
static void F_9 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
F_8 ( V_5 -> V_8 ) ;
}
int F_10 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
int V_9 ;
V_9 = F_11 ( V_3 , V_5 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_3 ( V_3 , V_5 , 1 ) ;
if ( V_9 < 0 )
F_12 ( V_3 , V_5 ) ;
return V_9 ;
}
void F_13 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_10 * V_11 ;
void * V_12 ;
V_12 = F_14 ( V_5 -> V_8 -> V_13 , V_14 ) ;
V_11 = F_15 ( V_3 , V_5 -> V_7 ,
V_5 -> V_8 , V_12 ) ;
V_11 -> V_15 = F_16 ( V_16 ) ;
V_11 -> V_17 = F_16 ( V_18 ) ;
V_11 -> V_19 = F_16 ( 0 ) ;
F_17 ( V_12 , V_14 ) ;
F_18 ( V_3 , V_5 ) ;
F_5 ( V_3 , V_5 ) ;
}
void F_19 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
F_9 ( V_3 , V_5 ) ;
F_12 ( V_3 , V_5 ) ;
}
static void F_20 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_10 * V_11 ;
void * V_12 ;
V_12 = F_14 ( V_5 -> V_8 -> V_13 , V_14 ) ;
V_11 = F_15 ( V_3 , V_5 -> V_7 ,
V_5 -> V_8 , V_12 ) ;
V_11 -> V_15 = F_16 ( V_16 ) ;
V_11 -> V_17 = F_16 ( V_16 ) ;
V_11 -> V_19 = F_16 ( 0 ) ;
F_17 ( V_12 , V_14 ) ;
F_5 ( V_3 , V_5 ) ;
F_21 ( V_3 , V_5 ) ;
}
int F_22 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
int V_9 ;
V_9 = F_3 ( V_3 , V_5 , 0 ) ;
F_23 ( V_9 == - V_20 ) ;
return V_9 ;
}
void F_24 ( struct V_2 * V_3 , struct V_4 * V_5 ,
T_1 V_21 )
{
struct V_10 * V_11 ;
void * V_12 ;
V_12 = F_14 ( V_5 -> V_8 -> V_13 , V_14 ) ;
V_11 = F_15 ( V_3 , V_5 -> V_7 ,
V_5 -> V_8 , V_12 ) ;
V_11 -> V_15 = F_16 ( F_25 ( V_3 ) ) ;
V_11 -> V_19 = F_16 ( V_21 ) ;
F_17 ( V_12 , V_14 ) ;
F_5 ( V_3 , V_5 ) ;
}
int F_26 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_10 * V_11 ;
T_2 V_22 ;
T_1 V_21 ;
void * V_12 ;
int V_9 ;
V_9 = F_3 ( V_3 , V_5 , 0 ) ;
if ( V_9 < 0 ) {
F_23 ( V_9 == - V_20 ) ;
return V_9 ;
}
V_12 = F_14 ( V_5 -> V_8 -> V_13 , V_14 ) ;
V_11 = F_15 ( V_3 , V_5 -> V_7 ,
V_5 -> V_8 , V_12 ) ;
V_22 = F_27 ( V_11 -> V_15 ) ;
V_21 = F_27 ( V_11 -> V_19 ) ;
F_17 ( V_12 , V_14 ) ;
if ( V_21 == 0 ) {
V_9 = F_28 ( V_3 , V_5 ) ;
if ( V_9 < 0 ) {
F_9 ( V_3 , V_5 ) ;
return V_9 ;
}
}
return 0 ;
}
void F_29 ( struct V_2 * V_3 , struct V_4 * V_5 ,
int V_23 )
{
struct V_10 * V_11 ;
T_2 V_22 , V_24 ;
T_1 V_21 ;
void * V_12 ;
V_12 = F_14 ( V_5 -> V_8 -> V_13 , V_14 ) ;
V_11 = F_15 ( V_3 , V_5 -> V_7 ,
V_5 -> V_8 , V_12 ) ;
V_24 = V_22 = F_27 ( V_11 -> V_15 ) ;
if ( ! V_23 ) {
V_24 = F_25 ( V_3 ) ;
F_23 ( V_22 > V_24 ) ;
}
V_11 -> V_17 = F_16 ( V_24 ) ;
V_21 = F_27 ( V_11 -> V_19 ) ;
F_17 ( V_12 , V_14 ) ;
if ( V_21 == 0 )
F_20 ( V_3 , V_5 ) ;
else
F_5 ( V_3 , V_5 ) ;
}
void F_30 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_10 * V_11 ;
T_2 V_22 ;
T_1 V_21 ;
void * V_12 ;
V_12 = F_14 ( V_5 -> V_8 -> V_13 , V_14 ) ;
V_11 = F_15 ( V_3 , V_5 -> V_7 ,
V_5 -> V_8 , V_12 ) ;
V_22 = F_27 ( V_11 -> V_15 ) ;
V_21 = F_27 ( V_11 -> V_19 ) ;
F_17 ( V_12 , V_14 ) ;
if ( V_22 == F_25 ( V_3 ) && V_21 == 0 )
F_31 ( V_3 , V_5 ) ;
F_9 ( V_3 , V_5 ) ;
}
int F_32 ( struct V_2 * V_3 ,
struct V_4 * V_25 ,
struct V_4 * V_26 )
{
int V_9 ;
V_9 = F_26 ( V_3 , V_25 ) ;
if ( ! V_9 ) {
V_9 = F_10 ( V_3 , V_26 ) ;
if ( V_9 < 0 )
F_30 ( V_3 , V_25 ) ;
}
return V_9 ;
}
void F_33 ( struct V_2 * V_3 ,
struct V_4 * V_25 ,
struct V_4 * V_26 , int V_23 )
{
F_29 ( V_3 , V_25 , V_23 ) ;
F_13 ( V_3 , V_26 ) ;
}
void F_34 ( struct V_2 * V_3 ,
struct V_4 * V_25 ,
struct V_4 * V_26 )
{
F_30 ( V_3 , V_25 ) ;
F_19 ( V_3 , V_26 ) ;
}
int F_35 ( struct V_2 * V_3 , T_2 V_27 )
{
struct V_4 V_5 ;
int V_9 ;
V_5 . V_7 = V_27 ;
V_9 = F_3 ( V_3 , & V_5 , 0 ) ;
if ( V_9 == 0 )
F_5 ( V_3 , & V_5 ) ;
return V_9 ;
}
int F_36 ( struct V_2 * V_3 , T_2 * V_28 , T_3 V_29 )
{
return F_37 ( V_3 , V_28 , V_29 ) ;
}
int F_38 ( struct V_2 * V_3 , T_2 V_27 , T_1 V_21 )
{
struct V_30 * V_31 ;
struct V_10 * V_11 ;
void * V_12 ;
int V_9 ;
V_9 = F_4 ( V_3 , V_27 , 0 , & V_31 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( ! F_39 ( V_31 ) ) {
V_9 = F_40 ( V_3 , V_31 ) ;
if ( V_9 ) {
F_8 ( V_31 ) ;
return V_9 ;
}
}
V_12 = F_14 ( V_31 -> V_13 , V_14 ) ;
V_11 = F_15 ( V_3 , V_27 , V_31 , V_12 ) ;
if ( F_41 ( V_11 -> V_19 == F_16 ( 0 ) ) ) {
F_42 ( V_32 L_1 , V_33 ,
( unsigned long long ) V_27 ,
( unsigned long long ) F_27 ( V_11 -> V_15 ) ,
( unsigned long long ) F_27 ( V_11 -> V_17 ) ) ;
F_17 ( V_12 , V_14 ) ;
F_8 ( V_31 ) ;
return - V_34 ;
}
F_23 ( V_21 == 0 ) ;
V_11 -> V_19 = F_16 ( V_21 ) ;
F_17 ( V_12 , V_14 ) ;
F_6 ( V_31 ) ;
F_7 ( V_3 ) ;
F_8 ( V_31 ) ;
return 0 ;
}
int F_43 ( struct V_2 * V_3 , T_2 V_27 , T_1 * V_35 )
{
struct V_30 * V_31 , * V_36 ;
struct V_10 * V_11 ;
T_1 V_21 ;
void * V_12 ;
int V_9 ;
V_9 = F_4 ( V_3 , V_27 , 0 , & V_31 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( ! F_44 () && F_39 ( V_31 ) ) {
V_36 = F_45 ( V_3 , V_31 ) ;
if ( V_36 ) {
F_23 ( ! F_46 ( V_36 ) ) ;
F_8 ( V_31 ) ;
V_31 = V_36 ;
}
}
V_12 = F_14 ( V_31 -> V_13 , V_14 ) ;
V_11 = F_15 ( V_3 , V_27 , V_31 , V_12 ) ;
V_21 = F_27 ( V_11 -> V_19 ) ;
if ( V_21 == 0 ) {
V_9 = - V_20 ;
goto V_37;
}
* V_35 = V_21 ;
V_37:
F_17 ( V_12 , V_14 ) ;
F_8 ( V_31 ) ;
return V_9 ;
}
T_4 F_47 ( struct V_2 * V_3 , void * V_38 , unsigned V_39 ,
T_3 V_40 )
{
struct V_30 * V_31 ;
struct V_10 * V_11 ;
struct V_41 * V_42 = V_38 ;
T_2 V_43 , V_44 ;
void * V_12 ;
unsigned long V_45 = F_2 ( V_3 ) -> V_46 ;
int V_47 , V_48 , V_49 , V_9 ;
for ( V_47 = 0 ; V_47 < V_40 ; V_47 += V_49 ) {
V_9 = F_4 ( V_3 , V_42 -> V_50 ,
0 , & V_31 ) ;
if ( V_9 < 0 )
return V_9 ;
V_12 = F_14 ( V_31 -> V_13 , V_14 ) ;
V_43 = V_42 -> V_50 ;
F_48 ( V_43 , V_45 ) ;
V_43 *= V_45 ;
V_44 = V_43 + V_45 - 1 ;
for ( V_48 = V_47 , V_49 = 0 ;
V_48 < V_40 && V_42 -> V_50 >= V_43 &&
V_42 -> V_50 <= V_44 ;
V_48 ++ , V_49 ++ , V_42 = ( void * ) V_42 + V_39 ) {
V_11 = F_15 (
V_3 , V_42 -> V_50 , V_31 , V_12 ) ;
V_42 -> V_51 = F_27 ( V_11 -> V_15 ) ;
V_42 -> V_52 = F_27 ( V_11 -> V_17 ) ;
V_42 -> V_53 = F_27 ( V_11 -> V_19 ) ;
}
F_17 ( V_12 , V_14 ) ;
F_8 ( V_31 ) ;
}
return V_40 ;
}
int F_49 ( struct V_54 * V_55 , T_3 V_56 ,
struct V_57 * V_58 , struct V_2 * * V_59 )
{
static struct V_60 V_61 ;
struct V_2 * V_3 ;
struct V_1 * V_62 ;
int V_63 ;
V_3 = F_50 ( V_55 , NULL , V_64 ) ;
if ( F_41 ( ! V_3 ) )
return - V_65 ;
if ( ! ( V_3 -> V_66 & V_67 ) )
goto V_37;
V_63 = F_51 ( V_3 , V_68 , sizeof( * V_62 ) ) ;
if ( V_63 )
goto V_69;
V_63 = F_52 ( V_3 , V_56 ) ;
if ( V_63 )
goto V_69;
V_62 = F_1 ( V_3 ) ;
F_53 ( & V_62 -> V_70 . V_71 , & V_61 ) ;
F_54 ( V_3 , & V_62 -> V_72 ) ;
F_55 ( V_3 , & V_62 -> V_73 ) ;
V_63 = F_56 ( V_3 , V_58 ) ;
if ( V_63 )
goto V_69;
F_57 ( V_3 ) ;
V_37:
* V_59 = V_3 ;
return 0 ;
V_69:
F_58 ( V_3 ) ;
return V_63 ;
}
