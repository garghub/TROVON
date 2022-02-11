static unsigned int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
return F_4 ( V_6 -> V_7 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_8 )
{
T_1 V_9 ;
V_9 = F_6 ( V_2 , V_10 ) ;
V_9 &= ~ ( V_11 | V_12 ) ;
if ( V_8 == V_13 )
V_9 |= V_12 ;
else if ( V_8 == V_14 )
V_9 |= V_11 ;
F_7 ( V_2 , V_9 , V_10 ) ;
}
static int F_8 ( struct V_15 * V_16 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_7 ;
int V_17 ;
int V_18 ;
V_7 = F_9 ( & V_16 -> V_19 , NULL ) ;
if ( F_10 ( V_7 ) ) {
F_11 ( & V_16 -> V_19 , L_1 ) ;
return F_12 ( V_7 ) ;
}
if ( V_16 -> V_19 . V_20 )
V_17 = F_13 ( V_16 -> V_19 . V_20 , L_2 , 0 ) ;
else
V_17 = - V_21 ;
V_2 = F_14 ( V_16 , & V_22 , sizeof( struct V_5 ) ) ;
if ( F_10 ( V_2 ) )
return F_12 ( V_2 ) ;
V_4 = F_2 ( V_2 ) ;
V_6 = F_3 ( V_4 ) ;
V_6 -> V_7 = V_7 ;
V_6 -> V_17 = V_17 ;
F_15 ( V_16 ) ;
V_18 = F_16 ( V_6 -> V_7 ) ;
if ( V_18 )
goto V_23;
V_18 = F_17 ( V_2 ) ;
if ( V_18 )
goto V_24;
if ( F_18 ( V_6 -> V_17 ) ) {
V_18 = F_19 ( V_2 -> V_25 , V_6 -> V_17 , 0 ) ;
if ( V_18 ) {
F_11 ( & V_16 -> V_19 , L_3 ,
V_18 ) ;
goto V_26;
}
F_20 ( V_2 -> V_25 ) ;
}
return 0 ;
V_26:
F_21 ( V_2 , 0 ) ;
V_24:
F_22 ( V_6 -> V_7 ) ;
V_23:
F_23 ( V_16 ) ;
return V_18 ;
}
static int F_24 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_25 ( V_16 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_26 ( V_16 ) ;
if ( F_18 ( V_6 -> V_17 ) )
F_27 ( V_2 -> V_25 ) ;
F_22 ( V_6 -> V_7 ) ;
return 0 ;
}
static int F_28 ( struct V_27 * V_19 )
{
struct V_1 * V_2 = F_29 ( V_19 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_18 ;
V_18 = F_30 ( V_2 ) ;
if ( V_18 )
return V_18 ;
F_31 ( V_6 -> V_7 ) ;
return 0 ;
}
static int F_32 ( struct V_27 * V_19 )
{
struct V_1 * V_2 = F_29 ( V_19 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_18 ;
V_18 = F_33 ( V_6 -> V_7 ) ;
if ( V_18 ) {
F_34 ( V_19 , L_4 ) ;
return V_18 ;
}
return F_35 ( V_2 ) ;
}
