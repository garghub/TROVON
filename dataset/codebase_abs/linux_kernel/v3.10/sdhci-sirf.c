static unsigned int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
return F_3 ( V_6 -> V_7 ) ;
}
static int F_4 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_10 * V_10 ;
int V_11 ;
V_10 = F_5 ( & V_9 -> V_12 ) ;
if ( F_6 ( V_10 ) ) {
F_7 ( & V_9 -> V_12 , L_1 ) ;
return F_8 ( V_10 ) ;
}
V_6 = F_9 ( & V_9 -> V_12 , sizeof( struct V_5 ) ,
V_13 ) ;
if ( ! V_6 ) {
F_7 ( & V_9 -> V_12 , L_2 ) ;
return - V_14 ;
}
V_6 -> V_7 = F_10 ( & V_9 -> V_12 , NULL ) ;
if ( F_6 ( V_6 -> V_7 ) ) {
F_7 ( & V_9 -> V_12 , L_3 ) ;
return F_8 ( V_6 -> V_7 ) ;
}
if ( V_9 -> V_12 . V_15 ) {
V_6 -> V_16 = F_11 ( V_9 -> V_12 . V_15 ,
L_4 , 0 ) ;
} else {
V_6 -> V_16 = - V_17 ;
}
V_2 = F_12 ( V_9 , & V_18 ) ;
if ( F_6 ( V_2 ) ) {
V_11 = F_8 ( V_2 ) ;
goto V_19;
}
V_4 = F_2 ( V_2 ) ;
V_4 -> V_6 = V_6 ;
F_13 ( V_9 ) ;
F_14 ( V_6 -> V_7 ) ;
V_11 = F_15 ( V_2 ) ;
if ( V_11 )
goto V_20;
if ( F_16 ( V_6 -> V_16 ) ) {
V_11 = F_17 ( V_2 -> V_21 , V_6 -> V_16 ) ;
if ( V_11 ) {
F_7 ( & V_9 -> V_12 , L_5 ,
V_11 ) ;
goto V_22;
}
}
return 0 ;
V_22:
F_18 ( V_2 , 0 ) ;
V_20:
F_19 ( V_6 -> V_7 ) ;
F_20 ( V_9 ) ;
V_19:
return V_11 ;
}
static int F_21 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_22 ( V_9 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
F_23 ( V_9 ) ;
if ( F_16 ( V_6 -> V_16 ) )
F_24 ( V_2 -> V_21 ) ;
F_19 ( V_6 -> V_7 ) ;
return 0 ;
}
static int F_25 ( struct V_23 * V_12 )
{
struct V_1 * V_2 = F_26 ( V_12 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_11 ;
V_11 = F_27 ( V_2 ) ;
if ( V_11 )
return V_11 ;
F_28 ( V_6 -> V_7 ) ;
return 0 ;
}
static int F_29 ( struct V_23 * V_12 )
{
struct V_1 * V_2 = F_26 ( V_12 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_11 ;
V_11 = F_30 ( V_6 -> V_7 ) ;
if ( V_11 ) {
F_31 ( V_12 , L_6 ) ;
return V_11 ;
}
return F_32 ( V_2 ) ;
}
