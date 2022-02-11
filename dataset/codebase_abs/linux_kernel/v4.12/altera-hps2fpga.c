static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
return F_2 ( V_4 -> V_5 ) ;
}
static int F_3 ( struct V_3 * V_4 ,
bool V_6 )
{
unsigned long V_7 ;
int V_8 ;
if ( V_6 )
V_8 = F_4 ( V_4 -> V_5 ) ;
else
V_8 = F_5 ( V_4 -> V_5 ) ;
if ( V_8 )
return V_8 ;
if ( V_4 -> V_9 ) {
F_6 ( & V_10 , V_7 ) ;
V_11 |= V_12 ;
if ( V_6 )
V_11 |= V_4 -> V_9 ;
else
V_11 &= ~ V_4 -> V_9 ;
V_8 = F_7 ( V_4 -> V_13 , V_14 ,
V_11 ) ;
F_8 ( & V_10 , V_7 ) ;
}
return V_8 ;
}
static int F_9 ( struct V_1 * V_2 , bool V_6 )
{
return F_3 ( V_2 -> V_4 , V_6 ) ;
}
static int F_10 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = & V_16 -> V_18 ;
struct V_3 * V_4 ;
const struct V_19 * V_20 ;
T_1 V_6 ;
int V_8 ;
V_20 = F_11 ( V_21 , V_18 ) ;
V_4 = (struct V_3 * ) V_20 -> V_22 ;
V_4 -> V_5 = F_12 ( V_18 -> V_23 , 0 ) ;
if ( F_13 ( V_4 -> V_5 ) ) {
F_14 ( V_18 , L_1 , V_4 -> V_24 ) ;
return F_15 ( V_4 -> V_5 ) ;
}
if ( V_4 -> V_9 ) {
V_4 -> V_13 = F_16 ( L_2 ) ;
if ( F_13 ( V_4 -> V_13 ) ) {
F_14 ( V_18 , L_3 ) ;
return F_15 ( V_4 -> V_13 ) ;
}
}
V_4 -> V_25 = F_17 ( V_18 , NULL ) ;
if ( F_13 ( V_4 -> V_25 ) ) {
F_14 ( V_18 , L_4 ) ;
return F_15 ( V_4 -> V_25 ) ;
}
V_8 = F_18 ( V_4 -> V_25 ) ;
if ( V_8 ) {
F_14 ( V_18 , L_5 ) ;
return - V_26 ;
}
F_19 ( & V_10 ) ;
if ( ! F_20 ( V_18 -> V_23 , L_6 , & V_6 ) ) {
if ( V_6 > 1 ) {
F_21 ( V_18 , L_7 , V_6 ) ;
} else {
F_22 ( V_18 , L_8 ,
( V_6 ? L_9 : L_10 ) ) ;
V_8 = F_3 ( V_4 , V_6 ) ;
if ( V_8 )
goto V_27;
}
}
V_8 = F_23 ( V_18 , V_4 -> V_24 , & V_28 ,
V_4 ) ;
V_27:
if ( V_8 )
F_24 ( V_4 -> V_25 ) ;
return V_8 ;
}
static int F_25 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_26 ( V_16 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_27 ( & V_16 -> V_18 ) ;
F_24 ( V_4 -> V_25 ) ;
return 0 ;
}
