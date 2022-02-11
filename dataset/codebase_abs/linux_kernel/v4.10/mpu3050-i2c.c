static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
F_5 ( V_4 -> V_5 ) ;
F_6 ( V_4 -> V_5 ) ;
return 0 ;
}
static int F_7 ( struct V_6 * V_7 ,
const struct V_8 * V_9 )
{
struct V_10 * V_10 ;
const char * V_11 ;
struct V_4 * V_4 ;
int V_12 ;
if ( ! F_8 ( V_7 -> V_13 ,
V_14 ) )
return - V_15 ;
if ( V_9 )
V_11 = V_9 -> V_11 ;
else
return - V_16 ;
V_10 = F_9 ( V_7 , & V_17 ) ;
if ( F_10 ( V_10 ) ) {
F_11 ( & V_7 -> V_5 , L_1 ,
( int ) F_12 ( V_10 ) ) ;
return F_12 ( V_10 ) ;
}
V_12 = F_13 ( & V_7 -> V_5 , V_10 , V_7 -> V_18 , V_11 ) ;
if ( V_12 )
return V_12 ;
V_4 = F_14 ( F_15 ( & V_7 -> V_5 ) ) ;
V_4 -> V_19 = F_16 ( V_7 -> V_13 , & V_7 -> V_5 ,
1 , 0 , V_20 | V_21 ,
F_1 ,
F_4 ) ;
if ( ! V_4 -> V_19 )
F_11 ( & V_7 -> V_5 , L_2 ) ;
else {
V_4 -> V_19 -> V_22 = V_4 ;
V_12 = F_17 ( V_4 -> V_19 , 0 , 0 , 0 ) ;
if ( V_12 )
F_11 ( & V_7 -> V_5 , L_3 ) ;
}
return 0 ;
}
static int F_18 ( struct V_6 * V_7 )
{
struct V_23 * V_24 = F_15 ( & V_7 -> V_5 ) ;
struct V_4 * V_4 = F_14 ( V_24 ) ;
if ( V_4 -> V_19 )
F_19 ( V_4 -> V_19 ) ;
return F_20 ( & V_7 -> V_5 ) ;
}
