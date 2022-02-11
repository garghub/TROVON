static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_7 args ;
struct V_1 * V_8 ;
int V_9 ;
if ( ! F_2 ( V_5 , L_1 , NULL ) )
return NULL ;
V_8 = F_3 ( V_3 , sizeof( * V_8 ) , V_10 ) ;
if ( ! V_8 )
return F_4 ( - V_11 ) ;
V_9 = F_5 ( V_5 , L_1 , L_2 ,
0 , & args ) ;
if ( V_9 ) {
F_6 ( V_3 , L_3 ,
V_9 ) ;
return F_4 ( V_9 ) ;
}
V_8 -> V_12 = args . args [ 0 ] ;
F_7 ( args . V_5 ) ;
if ( F_8 ( V_5 , L_4 , NULL ) )
V_8 -> V_13 = 1 ;
if ( F_8 ( V_5 , L_5 , NULL ) )
V_8 -> V_14 = 1 ;
return V_8 ;
}
static int F_9 ( struct V_15 * V_16 )
{
struct V_17 * V_8 ;
struct V_18 V_19 = {
. V_20 = F_10 ( & V_16 -> V_3 ) ,
. V_21 = V_22 ,
. V_23 = V_24 |
V_25 ,
} ;
int V_9 ;
const struct V_26 * V_27 =
F_11 ( V_28 , & V_16 -> V_3 ) ;
const struct V_29 * V_30 = V_27 -> V_8 ;
V_8 = F_3 ( & V_16 -> V_3 , sizeof( * V_8 ) , V_10 ) ;
if ( ! V_8 ) {
F_6 ( & V_16 -> V_3 , L_6 ) ;
return - V_11 ;
}
V_8 -> V_31 = F_1 ( & V_16 -> V_3 ) ;
if ( F_12 ( V_8 -> V_31 ) )
return F_13 ( V_8 -> V_31 ) ;
V_8 -> V_32 = F_14 ( & V_16 -> V_3 , NULL ) ;
if ( F_12 ( V_8 -> V_32 ) ) {
F_6 ( & V_16 -> V_3 ,
L_7 , F_13 ( V_8 -> V_32 ) ) ;
return F_13 ( V_8 -> V_32 ) ;
}
V_9 = F_15 ( V_8 -> V_32 ) ;
if ( V_9 ) {
F_6 ( & V_16 -> V_3 ,
L_8 , V_9 ) ;
return V_9 ;
}
V_8 -> V_33 = F_16 ( & V_16 -> V_3 , L_9 , 0 ) ;
if ( F_12 ( V_8 -> V_33 ) ) {
V_9 = F_13 ( V_8 -> V_33 ) ;
goto V_34;
}
V_19 . V_33 = V_8 -> V_33 ;
if ( V_30 -> V_23 & V_35 )
V_19 . V_23 |= V_36 ;
V_9 = F_17 ( & V_16 -> V_3 , F_18 ( 32 ) ) ;
if ( V_9 )
goto V_34;
if ( V_8 -> V_31 ) {
V_9 = F_19 ( V_8 -> V_31 ) ;
if ( V_9 ) {
F_6 ( & V_16 -> V_3 , L_10 ,
V_9 ) ;
goto V_34;
}
}
V_8 -> V_37 = F_20 ( & V_16 -> V_3 ,
V_16 -> V_38 , V_16 -> V_39 ,
& V_19 ) ;
if ( F_12 ( V_8 -> V_37 ) ) {
V_9 = F_13 ( V_8 -> V_37 ) ;
F_6 ( & V_16 -> V_3 ,
L_11 ,
V_9 ) ;
goto V_34;
}
if ( V_8 -> V_31 ) {
V_9 = F_21 ( V_8 -> V_31 ) ;
if ( V_9 ) {
F_6 ( & V_16 -> V_3 , L_12 ,
V_9 ) ;
goto V_40;
}
}
F_22 ( V_16 , V_8 ) ;
F_23 ( & V_16 -> V_3 ) ;
F_24 ( & V_16 -> V_3 ) ;
return 0 ;
V_40:
F_25 ( V_8 -> V_37 ) ;
V_34:
F_26 ( V_8 -> V_32 ) ;
return V_9 ;
}
static int F_27 ( struct V_15 * V_16 )
{
struct V_17 * V_8 = F_28 ( V_16 ) ;
F_29 ( & V_16 -> V_3 ) ;
F_25 ( V_8 -> V_37 ) ;
F_26 ( V_8 -> V_32 ) ;
return 0 ;
}
