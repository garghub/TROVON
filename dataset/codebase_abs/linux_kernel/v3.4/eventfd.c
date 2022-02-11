int F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned long V_4 ;
if ( V_3 < 0 )
return - V_5 ;
F_2 ( & V_2 -> V_6 . V_7 , V_4 ) ;
if ( V_8 - V_2 -> V_9 < V_3 )
V_3 = ( int ) ( V_8 - V_2 -> V_9 ) ;
V_2 -> V_9 += V_3 ;
if ( F_3 ( & V_2 -> V_6 ) )
F_4 ( & V_2 -> V_6 , V_10 ) ;
F_5 ( & V_2 -> V_6 . V_7 , V_4 ) ;
return V_3 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
}
static void F_8 ( struct V_11 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 , struct V_1 , V_11 ) ;
F_6 ( V_2 ) ;
}
struct V_1 * F_10 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_11 ) ;
return V_2 ;
}
void F_12 ( struct V_1 * V_2 )
{
F_13 ( & V_2 -> V_11 , F_8 ) ;
}
static int F_14 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_14 ;
F_15 ( & V_2 -> V_6 , V_15 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
static unsigned int F_16 ( struct V_13 * V_13 , T_1 * V_16 )
{
struct V_1 * V_2 = V_13 -> V_14 ;
unsigned int V_17 = 0 ;
unsigned long V_4 ;
F_17 ( V_13 , & V_2 -> V_6 , V_16 ) ;
F_2 ( & V_2 -> V_6 . V_7 , V_4 ) ;
if ( V_2 -> V_9 > 0 )
V_17 |= V_10 ;
if ( V_2 -> V_9 == V_8 )
V_17 |= V_18 ;
if ( V_8 - 1 > V_2 -> V_9 )
V_17 |= V_19 ;
F_5 ( & V_2 -> V_6 . V_7 , V_4 ) ;
return V_17 ;
}
static void F_18 ( struct V_1 * V_2 , T_2 * V_20 )
{
* V_20 = ( V_2 -> V_4 & V_21 ) ? 1 : V_2 -> V_9 ;
V_2 -> V_9 -= * V_20 ;
}
int F_19 ( struct V_1 * V_2 , T_3 * V_16 ,
T_2 * V_20 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_6 . V_7 , V_4 ) ;
F_18 ( V_2 , V_20 ) ;
F_20 ( & V_2 -> V_6 , V_16 ) ;
if ( * V_20 != 0 && F_3 ( & V_2 -> V_6 ) )
F_4 ( & V_2 -> V_6 , V_19 ) ;
F_5 ( & V_2 -> V_6 . V_7 , V_4 ) ;
return * V_20 != 0 ? 0 : - V_22 ;
}
T_4 F_21 ( struct V_1 * V_2 , int V_23 , T_2 * V_20 )
{
T_4 V_24 ;
F_22 ( V_16 , V_25 ) ;
F_23 ( & V_2 -> V_6 . V_7 ) ;
* V_20 = 0 ;
V_24 = - V_22 ;
if ( V_2 -> V_9 > 0 )
V_24 = 0 ;
else if ( ! V_23 ) {
F_24 ( & V_2 -> V_6 , & V_16 ) ;
for (; ; ) {
F_25 ( V_26 ) ;
if ( V_2 -> V_9 > 0 ) {
V_24 = 0 ;
break;
}
if ( F_26 ( V_25 ) ) {
V_24 = - V_27 ;
break;
}
F_27 ( & V_2 -> V_6 . V_7 ) ;
F_28 () ;
F_23 ( & V_2 -> V_6 . V_7 ) ;
}
F_20 ( & V_2 -> V_6 , & V_16 ) ;
F_29 ( V_28 ) ;
}
if ( F_30 ( V_24 == 0 ) ) {
F_18 ( V_2 , V_20 ) ;
if ( F_3 ( & V_2 -> V_6 ) )
F_4 ( & V_2 -> V_6 , V_19 ) ;
}
F_27 ( & V_2 -> V_6 . V_7 ) ;
return V_24 ;
}
static T_4 F_31 ( struct V_13 * V_13 , char T_5 * V_29 , T_6 V_9 ,
T_7 * V_30 )
{
struct V_1 * V_2 = V_13 -> V_14 ;
T_4 V_24 ;
T_2 V_20 ;
if ( V_9 < sizeof( V_20 ) )
return - V_5 ;
V_24 = F_21 ( V_2 , V_13 -> V_31 & V_32 , & V_20 ) ;
if ( V_24 < 0 )
return V_24 ;
return F_32 ( V_20 , ( T_2 T_5 * ) V_29 ) ? - V_33 : sizeof( V_20 ) ;
}
static T_4 F_33 ( struct V_13 * V_13 , const char T_5 * V_29 , T_6 V_9 ,
T_7 * V_30 )
{
struct V_1 * V_2 = V_13 -> V_14 ;
T_4 V_24 ;
T_2 V_34 ;
F_22 ( V_16 , V_25 ) ;
if ( V_9 < sizeof( V_34 ) )
return - V_5 ;
if ( F_34 ( & V_34 , V_29 , sizeof( V_34 ) ) )
return - V_33 ;
if ( V_34 == V_8 )
return - V_5 ;
F_23 ( & V_2 -> V_6 . V_7 ) ;
V_24 = - V_22 ;
if ( V_8 - V_2 -> V_9 > V_34 )
V_24 = sizeof( V_34 ) ;
else if ( ! ( V_13 -> V_31 & V_32 ) ) {
F_24 ( & V_2 -> V_6 , & V_16 ) ;
for ( V_24 = 0 ; ; ) {
F_25 ( V_26 ) ;
if ( V_8 - V_2 -> V_9 > V_34 ) {
V_24 = sizeof( V_34 ) ;
break;
}
if ( F_26 ( V_25 ) ) {
V_24 = - V_27 ;
break;
}
F_27 ( & V_2 -> V_6 . V_7 ) ;
F_28 () ;
F_23 ( & V_2 -> V_6 . V_7 ) ;
}
F_20 ( & V_2 -> V_6 , & V_16 ) ;
F_29 ( V_28 ) ;
}
if ( F_30 ( V_24 > 0 ) ) {
V_2 -> V_9 += V_34 ;
if ( F_3 ( & V_2 -> V_6 ) )
F_4 ( & V_2 -> V_6 , V_10 ) ;
}
F_27 ( & V_2 -> V_6 . V_7 ) ;
return V_24 ;
}
struct V_13 * F_35 ( int V_35 )
{
struct V_13 * V_13 ;
V_13 = F_36 ( V_35 ) ;
if ( ! V_13 )
return F_37 ( - V_36 ) ;
if ( V_13 -> V_37 != & V_38 ) {
F_38 ( V_13 ) ;
return F_37 ( - V_5 ) ;
}
return V_13 ;
}
struct V_1 * F_39 ( int V_35 )
{
struct V_13 * V_13 ;
struct V_1 * V_2 ;
V_13 = F_35 ( V_35 ) ;
if ( F_40 ( V_13 ) )
return (struct V_1 * ) V_13 ;
V_2 = F_10 ( V_13 -> V_14 ) ;
F_38 ( V_13 ) ;
return V_2 ;
}
struct V_1 * F_41 ( struct V_13 * V_13 )
{
if ( V_13 -> V_37 != & V_38 )
return F_37 ( - V_5 ) ;
return F_10 ( V_13 -> V_14 ) ;
}
struct V_13 * F_42 ( unsigned int V_9 , int V_4 )
{
struct V_13 * V_13 ;
struct V_1 * V_2 ;
F_43 ( V_39 != V_40 ) ;
F_43 ( V_41 != V_32 ) ;
if ( V_4 & ~ V_42 )
return F_37 ( - V_5 ) ;
V_2 = F_44 ( sizeof( * V_2 ) , V_43 ) ;
if ( ! V_2 )
return F_37 ( - V_44 ) ;
F_45 ( & V_2 -> V_11 ) ;
F_46 ( & V_2 -> V_6 ) ;
V_2 -> V_9 = V_9 ;
V_2 -> V_4 = V_4 ;
V_13 = F_47 ( L_1 , & V_38 , V_2 ,
V_45 | ( V_4 & V_46 ) ) ;
if ( F_40 ( V_13 ) )
F_6 ( V_2 ) ;
return V_13 ;
}
