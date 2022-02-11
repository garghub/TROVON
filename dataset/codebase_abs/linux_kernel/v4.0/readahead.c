void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_2 -> V_5 = F_2 ( V_4 -> V_6 ) -> V_5 ;
V_2 -> V_7 = - 1 ;
}
static void F_3 ( struct V_3 * V_4 ,
struct V_8 * V_8 )
{
if ( F_4 ( V_8 ) ) {
if ( ! F_5 ( V_8 ) )
F_6 () ;
V_8 -> V_4 = V_4 ;
F_7 ( V_8 , 0 , V_9 ) ;
V_8 -> V_4 = NULL ;
F_8 ( V_8 ) ;
}
F_9 ( V_8 ) ;
}
static void F_10 ( struct V_3 * V_4 ,
struct V_10 * V_11 )
{
struct V_8 * V_12 ;
while ( ! F_11 ( V_11 ) ) {
V_12 = F_12 ( V_11 ) ;
F_13 ( & V_12 -> V_13 ) ;
F_3 ( V_4 , V_12 ) ;
}
}
int F_14 ( struct V_3 * V_4 , struct V_10 * V_11 ,
int (* F_15)( void * , struct V_8 * ) , void * V_14 )
{
struct V_8 * V_8 ;
int V_15 = 0 ;
while ( ! F_11 ( V_11 ) ) {
V_8 = F_12 ( V_11 ) ;
F_13 ( & V_8 -> V_13 ) ;
if ( F_16 ( V_8 , V_4 ,
V_8 -> V_16 , V_17 ) ) {
F_3 ( V_4 , V_8 ) ;
continue;
}
F_9 ( V_8 ) ;
V_15 = F_15 ( V_14 , V_8 ) ;
if ( F_17 ( V_15 ) ) {
F_10 ( V_4 , V_11 ) ;
break;
}
F_18 ( V_9 ) ;
}
return V_15 ;
}
static int F_19 ( struct V_3 * V_4 , struct V_18 * V_19 ,
struct V_10 * V_11 , unsigned V_20 )
{
struct V_21 V_22 ;
unsigned V_23 ;
int V_15 ;
F_20 ( & V_22 ) ;
if ( V_4 -> V_24 -> V_25 ) {
V_15 = V_4 -> V_24 -> V_25 ( V_19 , V_4 , V_11 , V_20 ) ;
F_21 ( V_11 ) ;
goto V_26;
}
for ( V_23 = 0 ; V_23 < V_20 ; V_23 ++ ) {
struct V_8 * V_8 = F_12 ( V_11 ) ;
F_13 ( & V_8 -> V_13 ) ;
if ( ! F_16 ( V_8 , V_4 ,
V_8 -> V_16 , V_17 ) ) {
V_4 -> V_24 -> V_27 ( V_19 , V_8 ) ;
}
F_9 ( V_8 ) ;
}
V_15 = 0 ;
V_26:
F_22 ( & V_22 ) ;
return V_15 ;
}
int F_23 ( struct V_3 * V_4 , struct V_18 * V_19 ,
T_1 V_28 , unsigned long V_29 ,
unsigned long V_30 )
{
struct V_31 * V_31 = V_4 -> V_6 ;
struct V_8 * V_8 ;
unsigned long V_32 ;
F_24 ( V_33 ) ;
int V_23 ;
int V_15 = 0 ;
T_2 V_34 = F_25 ( V_31 ) ;
if ( V_34 == 0 )
goto V_26;
V_32 = ( ( V_34 - 1 ) >> V_35 ) ;
for ( V_23 = 0 ; V_23 < V_29 ; V_23 ++ ) {
T_1 V_36 = V_28 + V_23 ;
if ( V_36 > V_32 )
break;
F_26 () ;
V_8 = F_27 ( & V_4 -> V_37 , V_36 ) ;
F_28 () ;
if ( V_8 && ! F_29 ( V_8 ) )
continue;
V_8 = F_30 ( V_4 ) ;
if ( ! V_8 )
break;
V_8 -> V_16 = V_36 ;
F_31 ( & V_8 -> V_13 , & V_33 ) ;
if ( V_23 == V_29 - V_30 )
F_32 ( V_8 ) ;
V_15 ++ ;
}
if ( V_15 )
F_19 ( V_4 , V_19 , & V_33 , V_15 ) ;
F_33 ( ! F_11 ( & V_33 ) ) ;
V_26:
return V_15 ;
}
int F_34 ( struct V_3 * V_4 , struct V_18 * V_19 ,
T_1 V_28 , unsigned long V_29 )
{
if ( F_17 ( ! V_4 -> V_24 -> V_27 && ! V_4 -> V_24 -> V_25 ) )
return - V_38 ;
V_29 = F_35 ( V_29 ) ;
while ( V_29 ) {
int V_39 ;
unsigned long V_40 = ( 2 * 1024 * 1024 ) / V_9 ;
if ( V_40 > V_29 )
V_40 = V_29 ;
V_39 = F_23 ( V_4 , V_19 ,
V_28 , V_40 , 0 ) ;
if ( V_39 < 0 )
return V_39 ;
V_28 += V_40 ;
V_29 -= V_40 ;
}
return 0 ;
}
unsigned long F_35 ( unsigned long V_41 )
{
return F_36 ( V_41 , V_42 ) ;
}
static unsigned long F_37 ( unsigned long V_43 , unsigned long V_44 )
{
unsigned long V_45 = F_38 ( V_43 ) ;
if ( V_45 <= V_44 / 32 )
V_45 = V_45 * 4 ;
else if ( V_45 <= V_44 / 4 )
V_45 = V_45 * 2 ;
else
V_45 = V_44 ;
return V_45 ;
}
static unsigned long F_39 ( struct V_1 * V_2 ,
unsigned long V_44 )
{
unsigned long V_46 = V_2 -> V_43 ;
unsigned long V_45 ;
if ( V_46 < V_44 / 16 )
V_45 = 4 * V_46 ;
else
V_45 = 2 * V_46 ;
return F_36 ( V_45 , V_44 ) ;
}
static T_1 F_40 ( struct V_3 * V_4 ,
T_1 V_28 , unsigned long V_44 )
{
T_1 V_47 ;
F_26 () ;
V_47 = F_41 ( V_4 , V_28 - 1 , V_44 ) ;
F_28 () ;
return V_28 - 1 - V_47 ;
}
static int F_42 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
T_1 V_28 ,
unsigned long V_48 ,
unsigned long V_44 )
{
T_1 V_43 ;
V_43 = F_40 ( V_4 , V_28 , V_44 ) ;
if ( V_43 <= V_48 )
return 0 ;
if ( V_43 >= V_28 )
V_43 *= 2 ;
V_2 -> V_49 = V_28 ;
V_2 -> V_43 = F_36 ( V_43 + V_48 , V_44 ) ;
V_2 -> V_50 = 1 ;
return 1 ;
}
static unsigned long
F_43 ( struct V_3 * V_4 ,
struct V_1 * V_2 , struct V_18 * V_19 ,
bool V_51 , T_1 V_28 ,
unsigned long V_48 )
{
unsigned long V_44 = F_35 ( V_2 -> V_5 ) ;
T_1 V_52 ;
if ( ! V_28 )
goto V_53;
if ( ( V_28 == ( V_2 -> V_49 + V_2 -> V_43 - V_2 -> V_50 ) ||
V_28 == ( V_2 -> V_49 + V_2 -> V_43 ) ) ) {
V_2 -> V_49 += V_2 -> V_43 ;
V_2 -> V_43 = F_39 ( V_2 , V_44 ) ;
V_2 -> V_50 = V_2 -> V_43 ;
goto V_54;
}
if ( V_51 ) {
T_1 V_49 ;
F_26 () ;
V_49 = F_44 ( V_4 , V_28 + 1 , V_44 ) ;
F_28 () ;
if ( ! V_49 || V_49 - V_28 > V_44 )
return 0 ;
V_2 -> V_49 = V_49 ;
V_2 -> V_43 = V_49 - V_28 ;
V_2 -> V_43 += V_48 ;
V_2 -> V_43 = F_39 ( V_2 , V_44 ) ;
V_2 -> V_50 = V_2 -> V_43 ;
goto V_54;
}
if ( V_48 > V_44 )
goto V_53;
V_52 = ( unsigned long long ) V_2 -> V_7 >> V_35 ;
if ( V_28 - V_52 <= 1UL )
goto V_53;
if ( F_42 ( V_4 , V_2 , V_28 , V_48 , V_44 ) )
goto V_54;
return F_23 ( V_4 , V_19 , V_28 , V_48 , 0 ) ;
V_53:
V_2 -> V_49 = V_28 ;
V_2 -> V_43 = F_37 ( V_48 , V_44 ) ;
V_2 -> V_50 = V_2 -> V_43 > V_48 ? V_2 -> V_43 - V_48 : V_2 -> V_43 ;
V_54:
if ( V_28 == V_2 -> V_49 && V_2 -> V_43 == V_2 -> V_50 ) {
V_2 -> V_50 = F_39 ( V_2 , V_44 ) ;
V_2 -> V_43 += V_2 -> V_50 ;
}
return F_45 ( V_2 , V_4 , V_19 ) ;
}
void F_46 ( struct V_3 * V_4 ,
struct V_1 * V_2 , struct V_18 * V_19 ,
T_1 V_28 , unsigned long V_48 )
{
if ( ! V_2 -> V_5 )
return;
if ( V_19 && ( V_19 -> V_55 & V_56 ) ) {
F_34 ( V_4 , V_19 , V_28 , V_48 ) ;
return;
}
F_43 ( V_4 , V_2 , V_19 , false , V_28 , V_48 ) ;
}
void
F_47 ( struct V_3 * V_4 ,
struct V_1 * V_2 , struct V_18 * V_19 ,
struct V_8 * V_8 , T_1 V_28 ,
unsigned long V_48 )
{
if ( ! V_2 -> V_5 )
return;
if ( F_48 ( V_8 ) )
return;
F_49 ( V_8 ) ;
if ( F_50 ( F_2 ( V_4 -> V_6 ) ) )
return;
F_43 ( V_4 , V_2 , V_19 , true , V_28 , V_48 ) ;
}
static T_3
F_51 ( struct V_3 * V_4 , struct V_18 * V_19 ,
T_1 V_16 , unsigned long V_41 )
{
if ( ! V_4 || ! V_4 -> V_24 )
return - V_38 ;
return F_34 ( V_4 , V_19 , V_16 , V_41 ) ;
}
