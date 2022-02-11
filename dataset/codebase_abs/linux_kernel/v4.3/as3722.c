static int F_1 ( struct V_1 * V_1 )
{
T_1 V_2 ;
int V_3 ;
V_3 = F_2 ( V_1 , V_4 , & V_2 ) ;
if ( V_3 < 0 ) {
F_3 ( V_1 -> V_5 , L_1 , V_3 ) ;
return V_3 ;
}
if ( V_2 != V_6 ) {
F_3 ( V_1 -> V_5 , L_2 , V_2 ) ;
return - V_7 ;
}
V_3 = F_2 ( V_1 , V_8 , & V_2 ) ;
if ( V_3 < 0 ) {
F_3 ( V_1 -> V_5 , L_3 , V_3 ) ;
return V_3 ;
}
F_4 ( V_1 -> V_5 , L_4 , V_2 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_1 )
{
int V_3 ;
T_1 V_2 = 0 ;
if ( V_1 -> V_9 )
V_2 |= V_10 ;
if ( V_1 -> V_11 )
V_2 |= V_12 ;
V_3 = F_6 ( V_1 , V_13 ,
V_10 | V_12 , V_2 ) ;
if ( V_3 < 0 )
F_3 ( V_1 -> V_5 , L_5 , V_3 ) ;
return V_3 ;
}
static int F_7 ( struct V_14 * V_15 ,
struct V_1 * V_1 )
{
struct V_16 * V_17 = V_15 -> V_5 . V_18 ;
struct V_19 * V_19 ;
if ( ! V_17 ) {
F_3 ( & V_15 -> V_5 , L_6 ) ;
return - V_20 ;
}
V_19 = F_8 ( V_15 -> V_21 ) ;
if ( ! V_19 ) {
F_3 ( & V_15 -> V_5 , L_7 , V_15 -> V_21 ) ;
return - V_20 ;
}
V_1 -> V_9 = F_9 ( V_17 ,
L_8 ) ;
V_1 -> V_11 = F_9 ( V_17 ,
L_9 ) ;
V_1 -> V_22 = F_10 ( V_19 ) ;
F_11 ( & V_15 -> V_5 , L_10 , V_1 -> V_22 ) ;
return 0 ;
}
static int F_12 ( struct V_14 * V_15 ,
const struct V_23 * V_24 )
{
struct V_1 * V_1 ;
unsigned long V_22 ;
int V_3 ;
V_1 = F_13 ( & V_15 -> V_5 , sizeof( struct V_1 ) , V_25 ) ;
if ( ! V_1 )
return - V_26 ;
V_1 -> V_5 = & V_15 -> V_5 ;
V_1 -> V_27 = V_15 -> V_21 ;
F_14 ( V_15 , V_1 ) ;
V_3 = F_7 ( V_15 , V_1 ) ;
if ( V_3 < 0 )
return V_3 ;
V_1 -> V_28 = F_15 ( V_15 , & V_29 ) ;
if ( F_16 ( V_1 -> V_28 ) ) {
V_3 = F_17 ( V_1 -> V_28 ) ;
F_3 ( & V_15 -> V_5 , L_11 , V_3 ) ;
return V_3 ;
}
V_3 = F_1 ( V_1 ) ;
if ( V_3 < 0 )
return V_3 ;
V_22 = V_1 -> V_22 | V_30 ;
V_3 = F_18 ( V_1 -> V_28 , V_1 -> V_27 ,
V_22 , - 1 , & V_31 ,
& V_1 -> V_19 ) ;
if ( V_3 < 0 ) {
F_3 ( V_1 -> V_5 , L_12 , V_3 ) ;
return V_3 ;
}
V_3 = F_5 ( V_1 ) ;
if ( V_3 < 0 )
goto V_32;
V_3 = F_19 ( & V_15 -> V_5 , - 1 , V_33 ,
F_20 ( V_33 ) , NULL , 0 ,
F_21 ( V_1 -> V_19 ) ) ;
if ( V_3 ) {
F_3 ( V_1 -> V_5 , L_13 , V_3 ) ;
goto V_32;
}
F_11 ( V_1 -> V_5 , L_14 ) ;
return 0 ;
V_32:
F_22 ( V_1 -> V_27 , V_1 -> V_19 ) ;
return V_3 ;
}
static int F_23 ( struct V_14 * V_15 )
{
struct V_1 * V_1 = F_24 ( V_15 ) ;
F_25 ( V_1 -> V_5 ) ;
F_22 ( V_1 -> V_27 , V_1 -> V_19 ) ;
return 0 ;
}
