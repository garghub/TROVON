static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
F_2 ( & V_4 -> V_7 ) ;
F_3 ( & V_4 -> V_8 , V_2 -> V_9 ) ;
if ( V_2 -> V_10 )
F_4 ( & V_2 -> V_11 ) ;
F_5 ( & V_4 -> V_7 ) ;
if ( V_2 -> V_12 & V_13 )
V_6 = & V_4 -> V_14 -> V_15 ;
else
V_6 = & V_4 -> V_14 -> V_16 ;
V_6 -> V_17 -> free ( V_6 , V_2 ) ;
F_6 ( V_2 ) ;
F_7 ( V_4 ) ;
}
static struct V_18 * F_8 ( struct V_19
* V_20 , enum V_21 V_22 )
{
return NULL ;
}
static void F_9 ( struct V_19 * V_20 ,
struct V_18 * V_23 ,
enum V_21 V_22 )
{
}
static void F_10 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
F_1 ( V_2 ) ;
}
static void * F_11 ( struct V_24 * V_25 , unsigned long V_27 )
{
return NULL ;
}
static void * F_12 ( struct V_24 * V_25 , unsigned long V_27 )
{
return NULL ;
}
static int F_13 ( struct V_24 * V_25 , struct V_28 * V_29 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
T_1 V_30 = V_29 -> V_31 - V_29 -> V_32 ;
return F_14 ( V_29 , V_29 -> V_32 , V_2 -> V_33 >> V_34 ,
V_30 , V_29 -> V_35 ) ;
}
struct V_1 * F_15 ( struct V_36 * V_10 , T_1 V_30 , T_2 V_12 )
{
struct V_3 * V_4 = V_10 -> V_4 ;
struct V_5 * V_6 = NULL ;
struct V_1 * V_2 ;
void * V_37 ;
int V_38 ;
if ( ! ( V_12 & V_39 ) ) {
F_16 ( V_4 -> V_40 . V_41 ,
L_1 ) ;
return F_17 ( - V_42 ) ;
}
if ( ( V_12 & ~ ( V_39 | V_13 ) ) ) {
F_16 ( V_4 -> V_40 . V_41 , L_2 , V_12 ) ;
return F_17 ( - V_42 ) ;
}
if ( ! F_18 ( V_4 ) )
return F_17 ( - V_42 ) ;
if ( ! V_4 -> V_14 ) {
V_37 = F_17 ( - V_42 ) ;
goto V_43;
}
V_2 = F_19 ( sizeof( * V_2 ) , V_44 ) ;
if ( ! V_2 ) {
V_37 = F_17 ( - V_45 ) ;
goto V_43;
}
V_2 -> V_12 = V_12 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_10 = V_10 ;
if ( V_12 & V_13 )
V_6 = & V_4 -> V_14 -> V_15 ;
else
V_6 = & V_4 -> V_14 -> V_16 ;
V_38 = V_6 -> V_17 -> V_46 ( V_6 , V_2 , V_30 ) ;
if ( V_38 ) {
V_37 = F_17 ( V_38 ) ;
goto V_47;
}
F_2 ( & V_4 -> V_7 ) ;
V_2 -> V_9 = F_20 ( & V_4 -> V_8 , V_2 , 1 , 0 , V_44 ) ;
F_5 ( & V_4 -> V_7 ) ;
if ( V_2 -> V_9 < 0 ) {
V_37 = F_17 ( V_2 -> V_9 ) ;
goto V_48;
}
if ( V_12 & V_13 ) {
F_21 ( V_49 ) ;
V_49 . V_17 = & V_50 ;
V_49 . V_30 = V_2 -> V_30 ;
V_49 . V_12 = V_51 ;
V_49 . V_26 = V_2 ;
V_2 -> V_25 = F_22 ( & V_49 ) ;
if ( F_23 ( V_2 -> V_25 ) ) {
V_37 = F_24 ( V_2 -> V_25 ) ;
goto V_52;
}
}
F_2 ( & V_4 -> V_7 ) ;
F_25 ( & V_2 -> V_11 , & V_10 -> V_53 ) ;
F_5 ( & V_4 -> V_7 ) ;
return V_2 ;
V_52:
F_2 ( & V_4 -> V_7 ) ;
F_3 ( & V_4 -> V_8 , V_2 -> V_9 ) ;
F_5 ( & V_4 -> V_7 ) ;
V_48:
V_6 -> V_17 -> free ( V_6 , V_2 ) ;
V_47:
F_6 ( V_2 ) ;
V_43:
F_7 ( V_4 ) ;
return V_37 ;
}
int F_26 ( struct V_1 * V_2 )
{
T_2 V_54 = V_39 | V_13 ;
int V_55 ;
if ( ( V_2 -> V_12 & V_54 ) != V_54 )
return - V_42 ;
V_55 = F_27 ( V_2 -> V_25 , V_56 ) ;
if ( V_55 >= 0 )
F_28 ( V_2 -> V_25 ) ;
return V_55 ;
}
void F_29 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 & V_13 )
F_30 ( V_2 -> V_25 ) ;
else
F_1 ( V_2 ) ;
}
int F_31 ( struct V_1 * V_2 , void * V_57 , T_3 * V_58 )
{
if ( ( char * ) V_57 < ( char * ) V_2 -> V_59 )
return - V_42 ;
if ( ( char * ) V_57 >= ( ( char * ) V_2 -> V_59 + V_2 -> V_30 ) )
return - V_42 ;
return F_32 (
V_2 , ( unsigned long ) V_57 - ( unsigned long ) V_2 -> V_59 , V_58 ) ;
}
int F_33 ( struct V_1 * V_2 , T_3 V_58 , void * * V_57 )
{
if ( V_58 < V_2 -> V_33 )
return - V_42 ;
if ( V_58 >= ( V_2 -> V_33 + V_2 -> V_30 ) )
return - V_42 ;
if ( V_57 ) {
void * V_60 = F_34 ( V_2 , V_58 - V_2 -> V_33 ) ;
if ( F_23 ( V_60 ) )
return F_35 ( V_60 ) ;
* V_57 = V_60 ;
}
return 0 ;
}
void * F_34 ( struct V_1 * V_2 , T_1 V_61 )
{
if ( V_61 >= V_2 -> V_30 )
return F_17 ( - V_42 ) ;
return ( char * ) V_2 -> V_59 + V_61 ;
}
int F_32 ( struct V_1 * V_2 , T_1 V_61 , T_3 * V_58 )
{
if ( V_61 >= V_2 -> V_30 )
return - V_42 ;
if ( V_58 )
* V_58 = V_2 -> V_33 + V_61 ;
return 0 ;
}
struct V_1 * F_36 ( struct V_36 * V_10 , int V_9 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
if ( ! V_10 )
return F_17 ( - V_42 ) ;
V_4 = V_10 -> V_4 ;
F_2 ( & V_4 -> V_7 ) ;
V_2 = F_37 ( & V_4 -> V_8 , V_9 ) ;
if ( ! V_2 || V_2 -> V_10 != V_10 )
V_2 = F_17 ( - V_42 ) ;
else if ( V_2 -> V_12 & V_13 )
F_28 ( V_2 -> V_25 ) ;
F_5 ( & V_4 -> V_7 ) ;
return V_2 ;
}
int F_38 ( struct V_1 * V_2 )
{
return V_2 -> V_9 ;
}
void F_39 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 & V_13 )
F_30 ( V_2 -> V_25 ) ;
}
