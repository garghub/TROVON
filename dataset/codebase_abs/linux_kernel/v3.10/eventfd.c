T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_5 . V_6 , V_4 ) ;
if ( V_7 - V_2 -> V_8 < V_3 )
V_3 = V_7 - V_2 -> V_8 ;
V_2 -> V_8 += V_3 ;
if ( F_3 ( & V_2 -> V_5 ) )
F_4 ( & V_2 -> V_5 , V_9 ) ;
F_5 ( & V_2 -> V_5 . V_6 , V_4 ) ;
return V_3 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
}
static void F_8 ( struct V_10 * V_10 )
{
struct V_1 * V_2 = F_9 ( V_10 , struct V_1 , V_10 ) ;
F_6 ( V_2 ) ;
}
struct V_1 * F_10 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_10 ) ;
return V_2 ;
}
void F_12 ( struct V_1 * V_2 )
{
F_13 ( & V_2 -> V_10 , F_8 ) ;
}
static int F_14 ( struct V_11 * V_11 , struct V_12 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_13 ;
F_15 ( & V_2 -> V_5 , V_14 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
static unsigned int F_16 ( struct V_12 * V_12 , T_2 * V_15 )
{
struct V_1 * V_2 = V_12 -> V_13 ;
unsigned int V_16 = 0 ;
unsigned long V_4 ;
F_17 ( V_12 , & V_2 -> V_5 , V_15 ) ;
F_2 ( & V_2 -> V_5 . V_6 , V_4 ) ;
if ( V_2 -> V_8 > 0 )
V_16 |= V_9 ;
if ( V_2 -> V_8 == V_7 )
V_16 |= V_17 ;
if ( V_7 - 1 > V_2 -> V_8 )
V_16 |= V_18 ;
F_5 ( & V_2 -> V_5 . V_6 , V_4 ) ;
return V_16 ;
}
static void F_18 ( struct V_1 * V_2 , T_1 * V_19 )
{
* V_19 = ( V_2 -> V_4 & V_20 ) ? 1 : V_2 -> V_8 ;
V_2 -> V_8 -= * V_19 ;
}
int F_19 ( struct V_1 * V_2 , T_3 * V_15 ,
T_1 * V_19 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_5 . V_6 , V_4 ) ;
F_18 ( V_2 , V_19 ) ;
F_20 ( & V_2 -> V_5 , V_15 ) ;
if ( * V_19 != 0 && F_3 ( & V_2 -> V_5 ) )
F_4 ( & V_2 -> V_5 , V_18 ) ;
F_5 ( & V_2 -> V_5 . V_6 , V_4 ) ;
return * V_19 != 0 ? 0 : - V_21 ;
}
T_4 F_21 ( struct V_1 * V_2 , int V_22 , T_1 * V_19 )
{
T_4 V_23 ;
F_22 ( V_15 , V_24 ) ;
F_23 ( & V_2 -> V_5 . V_6 ) ;
* V_19 = 0 ;
V_23 = - V_21 ;
if ( V_2 -> V_8 > 0 )
V_23 = 0 ;
else if ( ! V_22 ) {
F_24 ( & V_2 -> V_5 , & V_15 ) ;
for (; ; ) {
F_25 ( V_25 ) ;
if ( V_2 -> V_8 > 0 ) {
V_23 = 0 ;
break;
}
if ( F_26 ( V_24 ) ) {
V_23 = - V_26 ;
break;
}
F_27 ( & V_2 -> V_5 . V_6 ) ;
F_28 () ;
F_23 ( & V_2 -> V_5 . V_6 ) ;
}
F_20 ( & V_2 -> V_5 , & V_15 ) ;
F_29 ( V_27 ) ;
}
if ( F_30 ( V_23 == 0 ) ) {
F_18 ( V_2 , V_19 ) ;
if ( F_3 ( & V_2 -> V_5 ) )
F_4 ( & V_2 -> V_5 , V_18 ) ;
}
F_27 ( & V_2 -> V_5 . V_6 ) ;
return V_23 ;
}
static T_4 F_31 ( struct V_12 * V_12 , char T_5 * V_28 , T_6 V_8 ,
T_7 * V_29 )
{
struct V_1 * V_2 = V_12 -> V_13 ;
T_4 V_23 ;
T_1 V_19 ;
if ( V_8 < sizeof( V_19 ) )
return - V_30 ;
V_23 = F_21 ( V_2 , V_12 -> V_31 & V_32 , & V_19 ) ;
if ( V_23 < 0 )
return V_23 ;
return F_32 ( V_19 , ( T_1 T_5 * ) V_28 ) ? - V_33 : sizeof( V_19 ) ;
}
static T_4 F_33 ( struct V_12 * V_12 , const char T_5 * V_28 , T_6 V_8 ,
T_7 * V_29 )
{
struct V_1 * V_2 = V_12 -> V_13 ;
T_4 V_23 ;
T_1 V_34 ;
F_22 ( V_15 , V_24 ) ;
if ( V_8 < sizeof( V_34 ) )
return - V_30 ;
if ( F_34 ( & V_34 , V_28 , sizeof( V_34 ) ) )
return - V_33 ;
if ( V_34 == V_7 )
return - V_30 ;
F_23 ( & V_2 -> V_5 . V_6 ) ;
V_23 = - V_21 ;
if ( V_7 - V_2 -> V_8 > V_34 )
V_23 = sizeof( V_34 ) ;
else if ( ! ( V_12 -> V_31 & V_32 ) ) {
F_24 ( & V_2 -> V_5 , & V_15 ) ;
for ( V_23 = 0 ; ; ) {
F_25 ( V_25 ) ;
if ( V_7 - V_2 -> V_8 > V_34 ) {
V_23 = sizeof( V_34 ) ;
break;
}
if ( F_26 ( V_24 ) ) {
V_23 = - V_26 ;
break;
}
F_27 ( & V_2 -> V_5 . V_6 ) ;
F_28 () ;
F_23 ( & V_2 -> V_5 . V_6 ) ;
}
F_20 ( & V_2 -> V_5 , & V_15 ) ;
F_29 ( V_27 ) ;
}
if ( F_30 ( V_23 > 0 ) ) {
V_2 -> V_8 += V_34 ;
if ( F_3 ( & V_2 -> V_5 ) )
F_4 ( & V_2 -> V_5 , V_9 ) ;
}
F_27 ( & V_2 -> V_5 . V_6 ) ;
return V_23 ;
}
static int F_35 ( struct V_35 * V_36 , struct V_12 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_13 ;
int V_38 ;
F_23 ( & V_2 -> V_5 . V_6 ) ;
V_38 = F_36 ( V_36 , L_1 ,
( unsigned long long ) V_2 -> V_8 ) ;
F_27 ( & V_2 -> V_5 . V_6 ) ;
return V_38 ;
}
struct V_12 * F_37 ( int V_39 )
{
struct V_12 * V_12 ;
V_12 = F_38 ( V_39 ) ;
if ( ! V_12 )
return F_39 ( - V_40 ) ;
if ( V_12 -> V_41 != & V_42 ) {
F_40 ( V_12 ) ;
return F_39 ( - V_30 ) ;
}
return V_12 ;
}
struct V_1 * F_41 ( int V_39 )
{
struct V_12 * V_12 ;
struct V_1 * V_2 ;
V_12 = F_37 ( V_39 ) ;
if ( F_42 ( V_12 ) )
return (struct V_1 * ) V_12 ;
V_2 = F_10 ( V_12 -> V_13 ) ;
F_40 ( V_12 ) ;
return V_2 ;
}
struct V_1 * F_43 ( struct V_12 * V_12 )
{
if ( V_12 -> V_41 != & V_42 )
return F_39 ( - V_30 ) ;
return F_10 ( V_12 -> V_13 ) ;
}
struct V_12 * F_44 ( unsigned int V_8 , int V_4 )
{
struct V_12 * V_12 ;
struct V_1 * V_2 ;
F_45 ( V_43 != V_44 ) ;
F_45 ( V_45 != V_32 ) ;
if ( V_4 & ~ V_46 )
return F_39 ( - V_30 ) ;
V_2 = F_46 ( sizeof( * V_2 ) , V_47 ) ;
if ( ! V_2 )
return F_39 ( - V_48 ) ;
F_47 ( & V_2 -> V_10 ) ;
F_48 ( & V_2 -> V_5 ) ;
V_2 -> V_8 = V_8 ;
V_2 -> V_4 = V_4 ;
V_12 = F_49 ( L_2 , & V_42 , V_2 ,
V_49 | ( V_4 & V_50 ) ) ;
if ( F_42 ( V_12 ) )
F_6 ( V_2 ) ;
return V_12 ;
}
