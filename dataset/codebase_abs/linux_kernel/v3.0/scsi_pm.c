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
if ( F_8 ( V_2 ) )
V_6 = F_1 ( V_2 , V_3 ) ;
return V_6 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
if ( F_8 ( V_2 ) )
V_6 = F_5 ( V_2 ) ;
if ( V_6 == 0 ) {
F_10 ( V_2 ) ;
F_11 ( V_2 ) ;
F_12 ( V_2 ) ;
}
return V_6 ;
}
static int F_13 ( struct V_1 * V_2 )
{
return F_7 ( V_2 , V_10 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
return F_7 ( V_2 , V_11 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
return F_7 ( V_2 , V_12 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
F_4 ( V_2 , L_3 ) ;
if ( F_8 ( V_2 ) ) {
V_6 = F_1 ( V_2 , V_13 ) ;
if ( V_6 == - V_14 )
F_17 ( V_2 , F_18 (
F_19 ( V_15 / 10 ) ) ) ;
}
return V_6 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
F_4 ( V_2 , L_4 ) ;
if ( F_8 ( V_2 ) )
V_6 = F_5 ( V_2 ) ;
return V_6 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_6 ;
F_4 ( V_2 , L_5 ) ;
if ( F_8 ( V_2 ) )
V_6 = F_17 ( V_2 , 100 ) ;
else
V_6 = F_22 ( V_2 ) ;
return V_6 ;
}
int F_23 ( struct V_16 * V_17 )
{
int V_6 ;
V_6 = F_24 ( & V_17 -> V_18 ) ;
if ( V_6 < 0 )
F_25 ( & V_17 -> V_18 ) ;
else if ( V_6 > 0 )
V_6 = 0 ;
return V_6 ;
}
void F_26 ( struct V_16 * V_17 )
{
F_25 ( & V_17 -> V_18 ) ;
}
void F_27 ( struct V_19 * V_20 )
{
F_24 ( & V_20 -> V_2 ) ;
}
void F_28 ( struct V_19 * V_20 )
{
F_25 ( & V_20 -> V_2 ) ;
}
int F_29 ( struct V_21 * V_22 )
{
int V_6 ;
V_6 = F_24 ( & V_22 -> V_23 ) ;
if ( V_6 < 0 )
F_25 ( & V_22 -> V_23 ) ;
else if ( V_6 > 0 )
V_6 = 0 ;
return V_6 ;
}
void F_30 ( struct V_21 * V_22 )
{
F_25 ( & V_22 -> V_23 ) ;
}
