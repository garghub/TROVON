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
static void F_8 ( unsigned long V_12 )
{
struct V_1 * V_4 = (struct V_1 * ) V_12 ;
T_1 V_13 = F_9 ( V_4 -> V_3 . V_6 * 1000 , V_4 -> V_10 ) ;
if ( ! F_10 ( & V_4 -> V_14 ) ) {
V_4 -> V_5 ( V_4 , V_13 ) ;
F_11 ( & V_4 -> V_15 , V_16 + V_17 ) ;
} else {
F_12 ( L_2 ) ;
}
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_14 ( & V_4 -> V_14 , V_3 -> V_6 ) ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_13 ( V_3 ) ;
F_8 ( ( unsigned long ) V_4 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_17 ( & V_4 -> V_15 ) ;
V_4 -> V_7 ( V_4 , 0 ) ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 ,
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
static int F_19 ( struct V_19 * V_20 ,
unsigned long V_21 , void * V_22 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( V_20 , struct V_1 , V_23 ) ;
if ( V_21 == V_24 || V_21 == V_25 )
V_4 -> V_3 . V_26 -> V_27 ( & V_4 -> V_3 ) ;
return V_28 ;
}
static int F_20 ( struct V_29 * V_30 )
{
int V_31 ;
bool V_32 ;
struct V_1 * V_4 = F_21 ( & V_30 -> V_33 ) ;
if ( ! V_4 )
return - V_34 ;
V_32 = V_4 -> V_10 < V_35 * 1000 ;
if ( V_32 ) {
V_4 -> V_3 . V_26 = & V_36 ;
F_22 ( & V_4 -> V_15 , F_8 ,
( long unsigned int ) V_4 ) ;
} else {
V_4 -> V_3 . V_26 = & V_37 ;
}
V_4 -> V_3 . V_38 = & V_39 ;
V_4 -> V_3 . V_6 = V_40 ;
V_31 = V_4 -> V_3 . V_26 -> V_41 ( & V_4 -> V_3 , V_6 ) ;
if ( V_31 )
goto V_42;
F_23 ( & V_4 -> V_3 , V_43 ) ;
V_4 -> V_23 . V_44 = & F_19 ;
V_31 = F_24 ( & V_4 -> V_23 ) ;
if ( V_31 )
goto V_42;
V_31 = F_25 ( & V_4 -> V_3 ) ;
if ( V_31 )
goto V_45;
F_26 ( & V_30 -> V_33 , L_3 ,
V_6 , V_43 ? L_4 : L_5 ,
V_32 ? L_6 : L_5 ) ;
return 0 ;
V_45:
F_27 ( & V_4 -> V_23 ) ;
V_42:
if ( V_32 )
F_17 ( & V_4 -> V_15 ) ;
return V_31 ;
}
static int F_28 ( struct V_29 * V_30 )
{
struct V_1 * V_4 = F_21 ( & V_30 -> V_33 ) ;
if ( ! V_4 )
return - V_34 ;
F_29 ( & V_4 -> V_3 ) ;
F_27 ( & V_4 -> V_23 ) ;
return 0 ;
}
