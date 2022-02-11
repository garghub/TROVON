static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = NULL ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 )
V_4 = F_3 ( V_3 ) ;
return V_4 ;
}
static int F_4 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = NULL ;
int V_9 = 0 ;
V_8 = F_5 ( V_6 ) ;
if ( ! V_8 ) {
V_9 = - V_10 ;
goto V_11;
}
V_9 = F_6 ( V_8 ) ;
if ( V_9 < 0 )
goto V_11;
V_9 = F_7 ( V_8 ) ;
if ( V_9 < 0 )
goto V_11;
V_11:
if ( V_9 < 0 )
F_8 ( V_8 ) ;
return V_9 ;
}
static int F_9 ( struct V_5 * V_6 )
{
int V_9 = 0 ;
struct V_7 * V_8 = F_10 ( V_6 ) ;
V_9 = F_11 ( V_8 ) ;
if ( V_9 < 0 )
goto V_11;
F_8 ( V_8 ) ;
F_12 ( V_8 ) ;
V_11:
return V_9 ;
}
static int F_13 ( struct V_12 * V_13 , struct V_5 * V_6 )
{
struct V_7 * V_8 = F_10 ( V_6 ) ;
return F_14 ( V_8 , V_13 ) ;
}
static int F_15 ( struct V_5 * V_6 , int V_14 )
{
struct V_7 * V_8 = F_10 ( V_6 ) ;
int V_9 = F_16 ( V_8 , V_14 + V_15 ) ;
if ( V_9 < 0 )
goto V_11;
V_6 -> V_16 = V_14 ;
V_11:
return V_9 ;
}
static int F_17 ( struct V_5 * V_6 ,
T_1 V_17 )
{
struct V_7 * V_8 = F_10 ( V_6 ) ;
struct V_18 * V_19 = F_18 ( V_8 ) ;
bool V_20 = false ;
if ( V_19 -> V_21 & V_22 ) {
V_20 = V_17 & V_22 ;
if ( V_19 -> V_20 != V_20 ) {
V_19 -> V_20 = V_20 ;
if ( F_19 ( V_6 ) ) {
F_9 ( V_6 ) ;
F_4 ( V_6 ) ;
}
}
}
return 0 ;
}
static int F_20 ( struct V_5 * V_6 , void * V_23 )
{
struct V_7 * V_8 = F_10 ( V_6 ) ;
int V_9 = 0 ;
V_9 = F_21 ( V_6 , V_23 ) ;
if ( V_9 < 0 )
goto V_11;
V_9 = F_22 ( V_8 , V_6 ) ;
if ( V_9 < 0 )
goto V_11;
V_11:
return V_9 ;
}
static void F_23 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_10 ( V_6 ) ;
int V_9 = 0 ;
V_9 = F_24 ( V_8 , V_6 -> V_24 ) ;
if ( V_9 < 0 )
goto V_11;
if ( F_25 ( V_6 ) ) {
V_9 = F_26 ( V_8 , V_6 ) ;
if ( V_9 < 0 )
goto V_11;
}
V_11: ;
}
static int F_27 ( struct V_2 * V_3 ,
const struct V_25 * V_26 )
{
struct V_1 * V_1 = NULL ;
struct V_27 * V_28 = NULL ;
int V_9 = 0 ;
V_9 = F_28 ( V_3 ) ;
if ( V_9 < 0 )
goto V_11;
V_1 = F_1 ( V_3 ) ;
V_28 = F_29 ( V_1 , V_3 ,
& V_29 , & V_30 ) ;
if ( ! V_28 ) {
V_9 = - V_10 ;
goto V_11;
}
V_9 = F_30 ( V_28 ) ;
if ( V_9 < 0 )
goto V_11;
V_11:
if ( V_9 < 0 ) {
if ( V_28 )
F_31 ( V_28 ) ;
}
return V_9 ;
}
static void F_32 ( struct V_2 * V_3 )
{
struct V_27 * V_28 = F_33 ( V_3 ) ;
F_34 ( V_28 ) ;
F_31 ( V_28 ) ;
}
static int F_35 ( struct V_2 * V_3 , T_2 V_31 )
{
struct V_27 * V_28 = F_33 ( V_3 ) ;
return F_36 ( V_28 , & V_31 ) ;
}
static int F_37 ( struct V_2 * V_3 )
{
struct V_27 * V_28 = F_33 ( V_3 ) ;
T_2 V_31 = V_32 ;
return F_36 ( V_28 , & V_31 ) ;
}
