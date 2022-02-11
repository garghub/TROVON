static unsigned int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
return F_4 ( V_6 -> V_7 ) ;
}
static int F_5 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_7 ;
int V_10 ;
int V_11 ;
V_7 = F_6 ( & V_9 -> V_12 , NULL ) ;
if ( F_7 ( V_7 ) ) {
F_8 ( & V_9 -> V_12 , L_1 ) ;
return F_9 ( V_7 ) ;
}
if ( V_9 -> V_12 . V_13 )
V_10 = F_10 ( V_9 -> V_12 . V_13 , L_2 , 0 ) ;
else
V_10 = - V_14 ;
V_2 = F_11 ( V_9 , & V_15 , sizeof( struct V_5 ) ) ;
if ( F_7 ( V_2 ) )
return F_9 ( V_2 ) ;
V_4 = F_2 ( V_2 ) ;
V_6 = F_3 ( V_4 ) ;
V_6 -> V_7 = V_7 ;
V_6 -> V_10 = V_10 ;
F_12 ( V_9 ) ;
V_11 = F_13 ( V_6 -> V_7 ) ;
if ( V_11 )
goto V_16;
V_11 = F_14 ( V_2 ) ;
if ( V_11 )
goto V_17;
if ( F_15 ( V_6 -> V_10 ) ) {
V_11 = F_16 ( V_2 -> V_18 , V_6 -> V_10 ) ;
if ( V_11 ) {
F_8 ( & V_9 -> V_12 , L_3 ,
V_11 ) ;
goto V_19;
}
}
return 0 ;
V_19:
F_17 ( V_2 , 0 ) ;
V_17:
F_18 ( V_6 -> V_7 ) ;
V_16:
F_19 ( V_9 ) ;
return V_11 ;
}
static int F_20 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_21 ( V_9 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_22 ( V_9 ) ;
if ( F_15 ( V_6 -> V_10 ) )
F_23 ( V_2 -> V_18 ) ;
F_18 ( V_6 -> V_7 ) ;
return 0 ;
}
static int F_24 ( struct V_20 * V_12 )
{
struct V_1 * V_2 = F_25 ( V_12 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_11 ;
V_11 = F_26 ( V_2 ) ;
if ( V_11 )
return V_11 ;
F_27 ( V_6 -> V_7 ) ;
return 0 ;
}
static int F_28 ( struct V_20 * V_12 )
{
struct V_1 * V_2 = F_25 ( V_12 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_11 ;
V_11 = F_29 ( V_6 -> V_7 ) ;
if ( V_11 ) {
F_30 ( V_12 , L_4 ) ;
return V_11 ;
}
return F_31 ( V_2 ) ;
}
