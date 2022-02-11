void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_2 -> V_5 = V_4 -> V_6 -> V_5 ;
V_2 -> V_7 = - 1 ;
}
static void F_2 ( struct V_3 * V_4 ,
struct V_8 * V_8 )
{
if ( F_3 ( V_8 ) ) {
if ( ! F_4 ( V_8 ) )
F_5 () ;
V_8 -> V_4 = V_4 ;
F_6 ( V_8 , 0 ) ;
V_8 -> V_4 = NULL ;
F_7 ( V_8 ) ;
}
F_8 ( V_8 ) ;
}
static void F_9 ( struct V_3 * V_4 ,
struct V_9 * V_10 )
{
struct V_8 * V_11 ;
while ( ! F_10 ( V_10 ) ) {
V_11 = F_11 ( V_10 ) ;
F_12 ( & V_11 -> V_12 ) ;
F_2 ( V_4 , V_11 ) ;
}
}
int F_13 ( struct V_3 * V_4 , struct V_9 * V_10 ,
int (* F_14)( void * , struct V_8 * ) , void * V_13 )
{
struct V_8 * V_8 ;
int V_14 = 0 ;
while ( ! F_10 ( V_10 ) ) {
V_8 = F_11 ( V_10 ) ;
F_12 ( & V_8 -> V_12 ) ;
if ( F_15 ( V_8 , V_4 ,
V_8 -> V_15 , V_16 ) ) {
F_2 ( V_4 , V_8 ) ;
continue;
}
F_8 ( V_8 ) ;
V_14 = F_14 ( V_13 , V_8 ) ;
if ( F_16 ( V_14 ) ) {
F_9 ( V_4 , V_10 ) ;
break;
}
F_17 ( V_17 ) ;
}
return V_14 ;
}
static int F_18 ( struct V_3 * V_4 , struct V_18 * V_19 ,
struct V_9 * V_10 , unsigned V_20 )
{
struct V_21 V_22 ;
unsigned V_23 ;
int V_14 ;
F_19 ( & V_22 ) ;
if ( V_4 -> V_24 -> V_25 ) {
V_14 = V_4 -> V_24 -> V_25 ( V_19 , V_4 , V_10 , V_20 ) ;
F_20 ( V_10 ) ;
goto V_26;
}
for ( V_23 = 0 ; V_23 < V_20 ; V_23 ++ ) {
struct V_8 * V_8 = F_11 ( V_10 ) ;
F_12 ( & V_8 -> V_12 ) ;
if ( ! F_15 ( V_8 , V_4 ,
V_8 -> V_15 , V_16 ) ) {
V_4 -> V_24 -> V_27 ( V_19 , V_8 ) ;
}
F_8 ( V_8 ) ;
}
V_14 = 0 ;
V_26:
F_21 ( & V_22 ) ;
return V_14 ;
}
static int
F_22 ( struct V_3 * V_4 , struct V_18 * V_19 ,
T_1 V_28 , unsigned long V_29 ,
unsigned long V_30 )
{
struct V_31 * V_31 = V_4 -> V_32 ;
struct V_8 * V_8 ;
unsigned long V_33 ;
F_23 ( V_34 ) ;
int V_23 ;
int V_14 = 0 ;
T_2 V_35 = F_24 ( V_31 ) ;
if ( V_35 == 0 )
goto V_26;
V_33 = ( ( V_35 - 1 ) >> V_36 ) ;
for ( V_23 = 0 ; V_23 < V_29 ; V_23 ++ ) {
T_1 V_37 = V_28 + V_23 ;
if ( V_37 > V_33 )
break;
F_25 () ;
V_8 = F_26 ( & V_4 -> V_38 , V_37 ) ;
F_27 () ;
if ( V_8 )
continue;
V_8 = F_28 ( V_4 ) ;
if ( ! V_8 )
break;
V_8 -> V_15 = V_37 ;
F_29 ( & V_8 -> V_12 , & V_34 ) ;
if ( V_23 == V_29 - V_30 )
F_30 ( V_8 ) ;
V_14 ++ ;
}
if ( V_14 )
F_18 ( V_4 , V_19 , & V_34 , V_14 ) ;
F_31 ( ! F_10 ( & V_34 ) ) ;
V_26:
return V_14 ;
}
int F_32 ( struct V_3 * V_4 , struct V_18 * V_19 ,
T_1 V_28 , unsigned long V_29 )
{
int V_14 = 0 ;
if ( F_16 ( ! V_4 -> V_24 -> V_27 && ! V_4 -> V_24 -> V_25 ) )
return - V_39 ;
V_29 = F_33 ( V_29 ) ;
while ( V_29 ) {
int V_40 ;
unsigned long V_41 = ( 2 * 1024 * 1024 ) / V_17 ;
if ( V_41 > V_29 )
V_41 = V_29 ;
V_40 = F_22 ( V_4 , V_19 ,
V_28 , V_41 , 0 ) ;
if ( V_40 < 0 ) {
V_14 = V_40 ;
break;
}
V_14 += V_40 ;
V_28 += V_41 ;
V_29 -= V_41 ;
}
return V_14 ;
}
unsigned long F_33 ( unsigned long V_42 )
{
return F_34 ( V_42 , ( F_35 ( F_36 () , V_43 )
+ F_35 ( F_36 () , V_44 ) ) / 2 ) ;
}
unsigned long F_37 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_18 * V_19 )
{
int V_45 ;
V_45 = F_22 ( V_4 , V_19 ,
V_2 -> V_46 , V_2 -> V_47 , V_2 -> V_48 ) ;
return V_45 ;
}
static unsigned long F_38 ( unsigned long V_47 , unsigned long V_49 )
{
unsigned long V_50 = F_39 ( V_47 ) ;
if ( V_50 <= V_49 / 32 )
V_50 = V_50 * 4 ;
else if ( V_50 <= V_49 / 4 )
V_50 = V_50 * 2 ;
else
V_50 = V_49 ;
return V_50 ;
}
static unsigned long F_40 ( struct V_1 * V_2 ,
unsigned long V_49 )
{
unsigned long V_51 = V_2 -> V_47 ;
unsigned long V_50 ;
if ( V_51 < V_49 / 16 )
V_50 = 4 * V_51 ;
else
V_50 = 2 * V_51 ;
return F_34 ( V_50 , V_49 ) ;
}
static T_1 F_41 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
T_1 V_28 , unsigned long V_49 )
{
T_1 V_52 ;
F_25 () ;
V_52 = F_42 ( & V_4 -> V_38 , V_28 - 1 , V_49 ) ;
F_27 () ;
return V_28 - 1 - V_52 ;
}
static int F_43 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
T_1 V_28 ,
unsigned long V_53 ,
unsigned long V_49 )
{
T_1 V_47 ;
V_47 = F_41 ( V_4 , V_2 , V_28 , V_49 ) ;
if ( ! V_47 )
return 0 ;
if ( V_47 >= V_28 )
V_47 *= 2 ;
V_2 -> V_46 = V_28 ;
V_2 -> V_47 = F_38 ( V_47 + V_53 , V_49 ) ;
V_2 -> V_48 = V_2 -> V_47 ;
return 1 ;
}
static unsigned long
F_44 ( struct V_3 * V_4 ,
struct V_1 * V_2 , struct V_18 * V_19 ,
bool V_54 , T_1 V_28 ,
unsigned long V_53 )
{
unsigned long V_49 = F_33 ( V_2 -> V_5 ) ;
if ( ! V_28 )
goto V_55;
if ( ( V_28 == ( V_2 -> V_46 + V_2 -> V_47 - V_2 -> V_48 ) ||
V_28 == ( V_2 -> V_46 + V_2 -> V_47 ) ) ) {
V_2 -> V_46 += V_2 -> V_47 ;
V_2 -> V_47 = F_40 ( V_2 , V_49 ) ;
V_2 -> V_48 = V_2 -> V_47 ;
goto V_56;
}
if ( V_54 ) {
T_1 V_46 ;
F_25 () ;
V_46 = F_45 ( & V_4 -> V_38 , V_28 + 1 , V_49 ) ;
F_27 () ;
if ( ! V_46 || V_46 - V_28 > V_49 )
return 0 ;
V_2 -> V_46 = V_46 ;
V_2 -> V_47 = V_46 - V_28 ;
V_2 -> V_47 += V_53 ;
V_2 -> V_47 = F_40 ( V_2 , V_49 ) ;
V_2 -> V_48 = V_2 -> V_47 ;
goto V_56;
}
if ( V_53 > V_49 )
goto V_55;
if ( V_28 - ( V_2 -> V_7 >> V_36 ) <= 1UL )
goto V_55;
if ( F_43 ( V_4 , V_2 , V_28 , V_53 , V_49 ) )
goto V_56;
return F_22 ( V_4 , V_19 , V_28 , V_53 , 0 ) ;
V_55:
V_2 -> V_46 = V_28 ;
V_2 -> V_47 = F_38 ( V_53 , V_49 ) ;
V_2 -> V_48 = V_2 -> V_47 > V_53 ? V_2 -> V_47 - V_53 : V_2 -> V_47 ;
V_56:
if ( V_28 == V_2 -> V_46 && V_2 -> V_47 == V_2 -> V_48 ) {
V_2 -> V_48 = F_40 ( V_2 , V_49 ) ;
V_2 -> V_47 += V_2 -> V_48 ;
}
return F_37 ( V_2 , V_4 , V_19 ) ;
}
void F_46 ( struct V_3 * V_4 ,
struct V_1 * V_2 , struct V_18 * V_19 ,
T_1 V_28 , unsigned long V_53 )
{
if ( ! V_2 -> V_5 )
return;
if ( V_19 && ( V_19 -> V_57 & V_58 ) ) {
F_32 ( V_4 , V_19 , V_28 , V_53 ) ;
return;
}
F_44 ( V_4 , V_2 , V_19 , false , V_28 , V_53 ) ;
}
void
F_47 ( struct V_3 * V_4 ,
struct V_1 * V_2 , struct V_18 * V_19 ,
struct V_8 * V_8 , T_1 V_28 ,
unsigned long V_53 )
{
if ( ! V_2 -> V_5 )
return;
if ( F_48 ( V_8 ) )
return;
F_49 ( V_8 ) ;
if ( F_50 ( V_4 -> V_6 ) )
return;
F_44 ( V_4 , V_2 , V_19 , true , V_28 , V_53 ) ;
}
static T_3
F_51 ( struct V_3 * V_4 , struct V_18 * V_19 ,
T_1 V_15 , unsigned long V_42 )
{
if ( ! V_4 || ! V_4 -> V_24 || ! V_4 -> V_24 -> V_27 )
return - V_39 ;
F_32 ( V_4 , V_19 , V_15 , V_42 ) ;
return 0 ;
}
T_4 (F_52)( int V_59 , T_2 V_28 , T_5 V_60 )
{
T_3 V_14 ;
struct V_18 * V_18 ;
V_14 = - V_61 ;
V_18 = F_53 ( V_59 ) ;
if ( V_18 ) {
if ( V_18 -> V_57 & V_62 ) {
struct V_3 * V_4 = V_18 -> V_63 ;
T_1 V_46 = V_28 >> V_36 ;
T_1 V_64 = ( V_28 + V_60 - 1 ) >> V_36 ;
unsigned long V_65 = V_64 - V_46 + 1 ;
V_14 = F_51 ( V_4 , V_18 , V_46 , V_65 ) ;
}
F_54 ( V_18 ) ;
}
return V_14 ;
}
T_6 long F_55 ( long V_59 , T_2 V_28 , long V_60 )
{
return F_56 ( ( int ) V_59 , V_28 , ( T_5 ) V_60 ) ;
}
