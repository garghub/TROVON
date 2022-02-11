static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
V_6 = F_2 ( F_3 ( V_2 ) ) ;
if ( V_6 == 0 ) {
V_5 = V_2 -> V_7 ;
if ( V_5 && V_5 -> V_8 )
V_6 = V_5 -> V_8 ( V_2 , V_3 ) ;
}
F_4 ( V_2 , L_1 , V_6 ) ;
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_6 = 0 ;
V_5 = V_2 -> V_7 ;
if ( V_5 && V_5 -> V_9 )
V_6 = V_5 -> V_9 ( V_2 ) ;
F_6 ( F_3 ( V_2 ) ) ;
F_4 ( V_2 , L_2 , V_6 ) ;
return V_6 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_6 = 0 ;
if ( F_8 ( V_2 ) ) {
if ( F_9 ( V_2 ) ) {
if ( V_3 . V_10 == V_11 ||
V_3 . V_10 == V_12 )
return 0 ;
F_10 ( V_2 ) ;
}
V_6 = F_1 ( V_2 , V_3 ) ;
}
return V_6 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
if ( F_8 ( V_2 ) ) {
F_12 ( V_2 -> V_13 ) ;
V_6 = F_5 ( V_2 ) ;
F_13 ( V_2 -> V_13 ) ;
}
if ( V_6 == 0 ) {
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
}
return V_6 ;
}
static int F_17 ( struct V_1 * V_2 )
{
if ( F_8 ( V_2 ) ) {
F_18 () ;
} else if ( F_19 ( V_2 ) ) {
F_20 () ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
return F_7 ( V_2 , V_14 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
return F_7 ( V_2 , V_15 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
return F_7 ( V_2 , V_16 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
F_4 ( V_2 , L_3 ) ;
if ( F_8 ( V_2 ) ) {
V_6 = F_1 ( V_2 , V_17 ) ;
if ( V_6 == - V_18 )
F_25 ( V_2 , F_26 (
F_27 ( V_19 / 10 ) ) ) ;
}
return V_6 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
F_4 ( V_2 , L_4 ) ;
if ( F_8 ( V_2 ) )
V_6 = F_5 ( V_2 ) ;
return V_6 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_6 ;
F_4 ( V_2 , L_5 ) ;
if ( F_8 ( V_2 ) )
V_6 = F_25 ( V_2 , 100 ) ;
else
V_6 = F_30 ( V_2 ) ;
return V_6 ;
}
int F_31 ( struct V_20 * V_21 )
{
int V_6 ;
V_6 = F_12 ( & V_21 -> V_22 ) ;
if ( V_6 < 0 && V_6 != - V_23 )
F_13 ( & V_21 -> V_22 ) ;
else
V_6 = 0 ;
return V_6 ;
}
void F_32 ( struct V_20 * V_21 )
{
F_13 ( & V_21 -> V_22 ) ;
}
void F_33 ( struct V_24 * V_25 )
{
F_12 ( & V_25 -> V_2 ) ;
}
void F_34 ( struct V_24 * V_25 )
{
F_13 ( & V_25 -> V_2 ) ;
}
int F_35 ( struct V_26 * V_27 )
{
int V_6 ;
V_6 = F_12 ( & V_27 -> V_28 ) ;
if ( V_6 < 0 && V_6 != - V_23 )
F_13 ( & V_27 -> V_28 ) ;
else
V_6 = 0 ;
return V_6 ;
}
void F_36 ( struct V_26 * V_27 )
{
F_13 ( & V_27 -> V_28 ) ;
}
