static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 ;
F_2 ( V_6 , V_8 , 0x1 , 0x1 ) ;
if ( V_2 -> V_9 == V_10 )
V_7 = V_11 ;
else
V_7 = V_12 ;
return F_3 ( V_6 , V_7 , V_2 -> V_13 -> V_14 ) ;
}
static int F_4 ( struct V_5 * V_6 )
{
F_5 ( V_6 -> V_15 . V_16 , true ) ;
F_3 ( V_6 , V_17 , 0xffff ) ;
F_5 ( V_6 -> V_15 . V_16 , false ) ;
return 0 ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_18 * V_19 = F_7 ( V_6 ) ;
int V_20 ;
V_20 = F_8 ( V_19 , true , V_21 ,
V_22 ) ;
if ( V_20 < 0 )
return V_20 ;
F_9 ( V_6 -> V_15 . V_16 ) ;
return 0 ;
}
static int F_10 ( struct V_5 * V_6 )
{
struct V_18 * V_19 ;
struct V_16 * V_16 ;
int V_20 ;
V_19 = F_11 ( V_6 , V_21 ,
V_22 ) ;
if ( F_12 ( V_19 ) ) {
F_13 ( V_6 -> V_23 , L_1 ) ;
return F_14 ( V_19 ) ;
}
V_16 = F_15 ( V_19 , & V_24 ) ;
if ( F_12 ( V_16 ) ) {
V_20 = F_14 ( V_16 ) ;
goto V_25;
}
F_16 ( V_6 , V_19 ) ;
F_17 ( V_6 , V_16 ) ;
return 0 ;
V_25:
F_18 ( V_19 ) ;
return V_20 ;
}
static int F_19 ( struct V_5 * V_6 )
{
struct V_18 * V_19 = F_7 ( V_6 ) ;
F_20 ( V_6 ) ;
F_18 ( V_19 ) ;
return 0 ;
}
static int F_21 ( struct V_26 * V_27 )
{
return F_22 ( & V_27 -> V_23 ,
& V_28 , V_29 , F_23 ( V_29 ) ) ;
}
static int F_24 ( struct V_26 * V_27 )
{
F_25 ( & V_27 -> V_23 ) ;
return 0 ;
}
