static void F_1 ( struct V_1 * V_1 , bool V_2 )
{
if ( V_1 -> V_3 -> V_4 )
F_2 ( V_1 -> V_5 ,
V_1 -> V_3 -> V_4 ,
V_1 -> V_3 -> V_6 ,
V_1 -> V_7 ) ;
F_2 ( V_1 -> V_5 ,
V_1 -> V_3 -> V_8 ,
V_1 -> V_3 -> V_9 ,
V_2 ? 0 : V_1 -> V_3 -> V_9 ) ;
}
static void F_3 ( struct V_1 * V_1 , unsigned int V_10 )
{
unsigned long V_11 = V_1 -> V_11 ;
F_4 ( V_10 * V_11 , V_1 -> V_12 + V_13 ) ;
F_4 ( 1 , V_1 -> V_12 + V_14 ) ;
}
static int F_5 ( struct V_15 * V_16 )
{
struct V_1 * V_1 = F_6 ( V_16 ) ;
F_4 ( 1 , V_1 -> V_12 + V_17 ) ;
return 0 ;
}
static int F_7 ( struct V_15 * V_16 )
{
struct V_1 * V_1 = F_6 ( V_16 ) ;
F_4 ( 0 , V_1 -> V_12 + V_17 ) ;
return 0 ;
}
static int F_8 ( struct V_15 * V_16 ,
unsigned int V_10 )
{
struct V_1 * V_1 = F_6 ( V_16 ) ;
V_16 -> V_10 = V_10 ;
F_3 ( V_1 , V_10 ) ;
return 0 ;
}
static int F_9 ( struct V_15 * V_16 )
{
struct V_1 * V_1 = F_6 ( V_16 ) ;
F_3 ( V_1 , V_16 -> V_10 ) ;
return 0 ;
}
static int F_10 ( struct V_18 * V_19 )
{
const struct V_20 * V_21 ;
struct V_22 * V_23 = V_19 -> V_24 . V_25 ;
struct V_1 * V_1 ;
struct V_5 * V_5 ;
struct V_26 * V_27 ;
struct V_28 * V_28 ;
void T_1 * V_12 ;
T_2 V_29 ;
int V_30 ;
V_30 = F_11 ( V_23 , L_1 , & V_29 ) ;
if ( V_30 ) {
F_12 ( & V_19 -> V_24 , L_2 ) ;
return - V_31 ;
}
if ( V_29 != V_32 )
return - V_33 ;
V_1 = F_13 ( & V_19 -> V_24 , sizeof( * V_1 ) , V_34 ) ;
if ( ! V_1 )
return - V_35 ;
V_21 = F_14 ( V_36 , & V_19 -> V_24 ) ;
if ( ! V_21 ) {
F_12 ( & V_19 -> V_24 , L_3 ) ;
return - V_33 ;
}
V_1 -> V_3 = (struct V_37 * ) V_21 -> V_38 ;
V_27 = F_15 ( V_19 , V_39 , 0 ) ;
V_12 = F_16 ( & V_19 -> V_24 , V_27 ) ;
if ( F_17 ( V_12 ) )
return F_18 ( V_12 ) ;
V_5 = F_19 ( V_23 , L_4 ) ;
if ( F_17 ( V_5 ) ) {
F_12 ( & V_19 -> V_24 , L_5 ) ;
return F_18 ( V_5 ) ;
}
V_28 = F_20 ( & V_19 -> V_24 , NULL ) ;
if ( F_17 ( V_28 ) ) {
F_12 ( & V_19 -> V_24 , L_6 ) ;
return F_18 ( V_28 ) ;
}
V_1 -> V_24 = & V_19 -> V_24 ;
V_1 -> V_12 = V_12 ;
V_1 -> V_28 = V_28 ;
V_1 -> V_5 = V_5 ;
V_1 -> V_7 = F_21 ( V_23 , L_7 ) ;
V_1 -> V_11 = F_22 ( V_1 -> V_28 ) ;
if ( ! V_1 -> V_11 ) {
F_12 ( & V_19 -> V_24 , L_8 ) ;
return - V_31 ;
}
V_40 . V_41 = 0xFFFFFFFF / V_1 -> V_11 ;
V_40 . V_42 = & V_19 -> V_24 ;
V_30 = F_23 ( V_28 ) ;
if ( V_30 ) {
F_12 ( & V_19 -> V_24 , L_9 ) ;
return V_30 ;
}
F_24 ( & V_40 , V_1 ) ;
F_25 ( & V_40 , V_43 ) ;
V_30 = F_26 ( & V_40 , 0 , & V_19 -> V_24 ) ;
if ( V_30 ) {
F_12 ( & V_19 -> V_24 , L_10 ) ;
F_27 ( V_28 ) ;
return V_30 ;
}
V_30 = F_28 ( & V_40 ) ;
if ( V_30 ) {
F_12 ( & V_19 -> V_24 , L_11 ) ;
F_27 ( V_28 ) ;
return V_30 ;
}
F_1 ( V_1 , true ) ;
F_29 ( & V_19 -> V_24 , L_12 ,
V_1 -> V_7 ? L_13 : L_14 ) ;
return V_30 ;
}
static int F_30 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = F_6 ( & V_40 ) ;
F_1 ( V_1 , false ) ;
F_31 ( & V_40 ) ;
F_27 ( V_1 -> V_28 ) ;
return 0 ;
}
static int F_32 ( struct V_44 * V_24 )
{
struct V_1 * V_1 = F_6 ( & V_40 ) ;
if ( F_33 ( & V_40 ) )
F_7 ( & V_40 ) ;
F_1 ( V_1 , false ) ;
F_34 ( V_1 -> V_28 ) ;
return 0 ;
}
static int F_35 ( struct V_44 * V_24 )
{
struct V_1 * V_1 = F_6 ( & V_40 ) ;
int V_30 ;
V_30 = F_36 ( V_1 -> V_28 ) ;
if ( V_30 ) {
F_12 ( V_24 , L_15 ) ;
F_31 ( & V_40 ) ;
F_37 ( V_1 -> V_28 ) ;
return V_30 ;
}
F_1 ( V_1 , true ) ;
if ( F_33 ( & V_40 ) ) {
F_3 ( V_1 , V_40 . V_10 ) ;
F_5 ( & V_40 ) ;
}
return 0 ;
}
