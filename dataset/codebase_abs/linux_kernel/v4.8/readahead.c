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
if ( F_16 ( V_8 , V_4 , V_8 -> V_16 ,
F_17 ( V_4 ) ) ) {
F_3 ( V_4 , V_8 ) ;
continue;
}
F_9 ( V_8 ) ;
V_15 = F_15 ( V_14 , V_8 ) ;
if ( F_18 ( V_15 ) ) {
F_10 ( V_4 , V_11 ) ;
break;
}
F_19 ( V_9 ) ;
}
return V_15 ;
}
static int F_20 ( struct V_3 * V_4 , struct V_17 * V_18 ,
struct V_10 * V_11 , unsigned int V_19 , T_1 V_20 )
{
struct V_21 V_22 ;
unsigned V_23 ;
int V_15 ;
F_21 ( & V_22 ) ;
if ( V_4 -> V_24 -> V_25 ) {
V_15 = V_4 -> V_24 -> V_25 ( V_18 , V_4 , V_11 , V_19 ) ;
F_22 ( V_11 ) ;
goto V_26;
}
for ( V_23 = 0 ; V_23 < V_19 ; V_23 ++ ) {
struct V_8 * V_8 = F_12 ( V_11 ) ;
F_13 ( & V_8 -> V_13 ) ;
if ( ! F_16 ( V_8 , V_4 , V_8 -> V_16 , V_20 ) )
V_4 -> V_24 -> V_27 ( V_18 , V_8 ) ;
F_9 ( V_8 ) ;
}
V_15 = 0 ;
V_26:
F_23 ( & V_22 ) ;
return V_15 ;
}
int F_24 ( struct V_3 * V_4 , struct V_17 * V_18 ,
T_2 V_28 , unsigned long V_29 ,
unsigned long V_30 )
{
struct V_31 * V_31 = V_4 -> V_6 ;
struct V_8 * V_8 ;
unsigned long V_32 ;
F_25 ( V_33 ) ;
int V_23 ;
int V_15 = 0 ;
T_3 V_34 = F_26 ( V_31 ) ;
T_1 V_35 = F_17 ( V_4 ) ;
if ( V_34 == 0 )
goto V_26;
V_32 = ( ( V_34 - 1 ) >> V_36 ) ;
for ( V_23 = 0 ; V_23 < V_29 ; V_23 ++ ) {
T_2 V_37 = V_28 + V_23 ;
if ( V_37 > V_32 )
break;
F_27 () ;
V_8 = F_28 ( & V_4 -> V_38 , V_37 ) ;
F_29 () ;
if ( V_8 && ! F_30 ( V_8 ) )
continue;
V_8 = F_31 ( V_35 ) ;
if ( ! V_8 )
break;
V_8 -> V_16 = V_37 ;
F_32 ( & V_8 -> V_13 , & V_33 ) ;
if ( V_23 == V_29 - V_30 )
F_33 ( V_8 ) ;
V_15 ++ ;
}
if ( V_15 )
F_20 ( V_4 , V_18 , & V_33 , V_15 , V_35 ) ;
F_34 ( ! F_11 ( & V_33 ) ) ;
V_26:
return V_15 ;
}
int F_35 ( struct V_3 * V_4 , struct V_17 * V_18 ,
T_2 V_28 , unsigned long V_29 )
{
if ( F_18 ( ! V_4 -> V_24 -> V_27 && ! V_4 -> V_24 -> V_25 ) )
return - V_39 ;
V_29 = F_36 ( V_29 , F_2 ( V_4 -> V_6 ) -> V_5 ) ;
while ( V_29 ) {
int V_40 ;
unsigned long V_41 = ( 2 * 1024 * 1024 ) / V_9 ;
if ( V_41 > V_29 )
V_41 = V_29 ;
V_40 = F_24 ( V_4 , V_18 ,
V_28 , V_41 , 0 ) ;
if ( V_40 < 0 )
return V_40 ;
V_28 += V_41 ;
V_29 -= V_41 ;
}
return 0 ;
}
static unsigned long F_37 ( unsigned long V_42 , unsigned long V_43 )
{
unsigned long V_44 = F_38 ( V_42 ) ;
if ( V_44 <= V_43 / 32 )
V_44 = V_44 * 4 ;
else if ( V_44 <= V_43 / 4 )
V_44 = V_44 * 2 ;
else
V_44 = V_43 ;
return V_44 ;
}
static unsigned long F_39 ( struct V_1 * V_2 ,
unsigned long V_43 )
{
unsigned long V_45 = V_2 -> V_42 ;
unsigned long V_44 ;
if ( V_45 < V_43 / 16 )
V_44 = 4 * V_45 ;
else
V_44 = 2 * V_45 ;
return F_36 ( V_44 , V_43 ) ;
}
static T_2 F_40 ( struct V_3 * V_4 ,
T_2 V_28 , unsigned long V_43 )
{
T_2 V_46 ;
F_27 () ;
V_46 = F_41 ( V_4 , V_28 - 1 , V_43 ) ;
F_29 () ;
return V_28 - 1 - V_46 ;
}
static int F_42 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
T_2 V_28 ,
unsigned long V_47 ,
unsigned long V_43 )
{
T_2 V_42 ;
V_42 = F_40 ( V_4 , V_28 , V_43 ) ;
if ( V_42 <= V_47 )
return 0 ;
if ( V_42 >= V_28 )
V_42 *= 2 ;
V_2 -> V_48 = V_28 ;
V_2 -> V_42 = F_36 ( V_42 + V_47 , V_43 ) ;
V_2 -> V_49 = 1 ;
return 1 ;
}
static unsigned long
F_43 ( struct V_3 * V_4 ,
struct V_1 * V_2 , struct V_17 * V_18 ,
bool V_50 , T_2 V_28 ,
unsigned long V_47 )
{
unsigned long V_43 = V_2 -> V_5 ;
T_2 V_51 ;
if ( ! V_28 )
goto V_52;
if ( ( V_28 == ( V_2 -> V_48 + V_2 -> V_42 - V_2 -> V_49 ) ||
V_28 == ( V_2 -> V_48 + V_2 -> V_42 ) ) ) {
V_2 -> V_48 += V_2 -> V_42 ;
V_2 -> V_42 = F_39 ( V_2 , V_43 ) ;
V_2 -> V_49 = V_2 -> V_42 ;
goto V_53;
}
if ( V_50 ) {
T_2 V_48 ;
F_27 () ;
V_48 = F_44 ( V_4 , V_28 + 1 , V_43 ) ;
F_29 () ;
if ( ! V_48 || V_48 - V_28 > V_43 )
return 0 ;
V_2 -> V_48 = V_48 ;
V_2 -> V_42 = V_48 - V_28 ;
V_2 -> V_42 += V_47 ;
V_2 -> V_42 = F_39 ( V_2 , V_43 ) ;
V_2 -> V_49 = V_2 -> V_42 ;
goto V_53;
}
if ( V_47 > V_43 )
goto V_52;
V_51 = ( unsigned long long ) V_2 -> V_7 >> V_36 ;
if ( V_28 - V_51 <= 1UL )
goto V_52;
if ( F_42 ( V_4 , V_2 , V_28 , V_47 , V_43 ) )
goto V_53;
return F_24 ( V_4 , V_18 , V_28 , V_47 , 0 ) ;
V_52:
V_2 -> V_48 = V_28 ;
V_2 -> V_42 = F_37 ( V_47 , V_43 ) ;
V_2 -> V_49 = V_2 -> V_42 > V_47 ? V_2 -> V_42 - V_47 : V_2 -> V_42 ;
V_53:
if ( V_28 == V_2 -> V_48 && V_2 -> V_42 == V_2 -> V_49 ) {
V_2 -> V_49 = F_39 ( V_2 , V_43 ) ;
V_2 -> V_42 += V_2 -> V_49 ;
}
return F_45 ( V_2 , V_4 , V_18 ) ;
}
void F_46 ( struct V_3 * V_4 ,
struct V_1 * V_2 , struct V_17 * V_18 ,
T_2 V_28 , unsigned long V_47 )
{
if ( ! V_2 -> V_5 )
return;
if ( V_18 && ( V_18 -> V_54 & V_55 ) ) {
F_35 ( V_4 , V_18 , V_28 , V_47 ) ;
return;
}
F_43 ( V_4 , V_2 , V_18 , false , V_28 , V_47 ) ;
}
void
F_47 ( struct V_3 * V_4 ,
struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_8 * V_8 , T_2 V_28 ,
unsigned long V_47 )
{
if ( ! V_2 -> V_5 )
return;
if ( F_48 ( V_8 ) )
return;
F_49 ( V_8 ) ;
if ( F_50 ( V_4 -> V_6 ) )
return;
F_43 ( V_4 , V_2 , V_18 , true , V_28 , V_47 ) ;
}
static T_4
F_51 ( struct V_3 * V_4 , struct V_17 * V_18 ,
T_2 V_16 , unsigned long V_56 )
{
if ( ! V_4 || ! V_4 -> V_24 )
return - V_39 ;
if ( F_52 ( V_4 ) )
return 0 ;
return F_35 ( V_4 , V_18 , V_16 , V_56 ) ;
}
