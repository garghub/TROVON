static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_5 ( V_4 , V_3 -> V_6 * 1000 ) ;
return 0 ;
}
static int F_4 ( struct V_2 * V_3 )
{
return 0 ;
}
static int F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_7 ( V_4 , 0 ) ;
return 0 ;
}
static int F_6 ( struct V_2 * V_3 ,
unsigned int V_8 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_9 = V_4 -> V_10 ;
if ( V_8 < 1 || V_8 > V_9 / 1000 ) {
F_7 ( L_1 ,
V_9 / 1000 , V_8 ) ;
return - V_11 ;
}
V_3 -> V_6 = V_8 ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_7 ( V_4 , 1 ) ;
return 0 ;
}
static void F_9 ( unsigned long V_12 )
{
struct V_1 * V_4 = (struct V_1 * ) V_12 ;
T_1 V_13 = F_10 ( V_4 -> V_3 . V_6 * 1000 , V_4 -> V_10 ) ;
if ( ! F_11 ( & V_4 -> V_14 ) ) {
V_4 -> V_5 ( V_4 , V_13 ) ;
F_12 ( & V_4 -> V_15 , V_16 + V_17 ) ;
} else {
F_13 ( L_2 ) ;
}
}
static int F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_15 ( & V_4 -> V_14 , V_3 -> V_6 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_14 ( V_3 ) ;
F_9 ( ( unsigned long ) V_4 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_18 ( & V_4 -> V_15 ) ;
V_4 -> V_7 ( V_4 , 0 ) ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 ,
unsigned int V_8 )
{
if ( V_8 < 1 || V_8 > V_18 ) {
F_7 ( L_1 ,
V_18 , V_8 ) ;
return - V_11 ;
}
V_3 -> V_6 = V_8 ;
return 0 ;
}
static int F_20 ( struct V_19 * V_20 )
{
int V_21 ;
bool V_22 ;
struct V_1 * V_4 = F_21 ( & V_20 -> V_23 ) ;
if ( ! V_4 )
return - V_24 ;
V_22 = V_4 -> V_10 < V_25 * 1000 ;
if ( V_22 ) {
V_4 -> V_3 . V_26 = & V_27 ;
F_22 ( & V_4 -> V_15 , F_9 ,
( long unsigned int ) V_4 ) ;
} else {
V_4 -> V_3 . V_26 = & V_28 ;
}
V_4 -> V_3 . V_29 = & V_30 ;
V_4 -> V_3 . V_6 = V_31 ;
V_4 -> V_3 . V_32 = & V_20 -> V_23 ;
V_21 = V_4 -> V_3 . V_26 -> V_33 ( & V_4 -> V_3 , V_6 ) ;
if ( V_21 )
goto V_34;
F_23 ( & V_4 -> V_3 , V_35 ) ;
F_24 ( & V_4 -> V_3 , 64 ) ;
F_25 ( & V_4 -> V_3 ) ;
V_21 = F_26 ( & V_4 -> V_3 ) ;
if ( V_21 )
goto V_34;
F_27 ( & V_20 -> V_23 , L_3 ,
V_6 , V_35 ? L_4 : L_5 ,
V_22 ? L_6 : L_5 ) ;
return 0 ;
V_34:
if ( V_22 )
F_18 ( & V_4 -> V_15 ) ;
return V_21 ;
}
static int F_28 ( struct V_19 * V_20 )
{
struct V_1 * V_4 = F_21 ( & V_20 -> V_23 ) ;
if ( ! V_4 )
return - V_24 ;
F_29 ( & V_4 -> V_3 ) ;
return 0 ;
}
