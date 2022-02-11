int F_1 ( const struct V_1 * V_2 )
{
if ( V_1 )
return - V_3 ;
V_1 = V_2 ;
return 0 ;
}
void F_2 ( const struct V_1 * V_2 )
{
V_1 = NULL ;
}
int F_3 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_8 * V_9 = V_5 -> V_10 ;
struct V_11 args ;
int V_12 ;
V_7 -> V_5 = V_5 ;
V_12 = F_4 ( V_9 , L_1 , L_2 ,
0 , & args ) ;
if ( V_12 ) {
F_5 ( V_5 , L_3 ,
V_12 ) ;
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
return V_12 ;
}
V_7 -> V_13 = args . args [ 0 ] ;
F_6 ( args . V_9 ) ;
if ( F_7 ( V_9 , L_4 , NULL ) )
V_7 -> V_14 = 1 ;
if ( F_7 ( V_9 , L_5 , NULL ) )
V_7 -> V_15 = 1 ;
return 0 ;
}
static int F_8 ( struct V_16 * V_17 )
{
struct V_18 * V_19 ;
struct V_16 * V_20 , * V_21 ;
struct V_8 * V_22 ;
struct V_23 * V_24 ;
struct V_25 * V_26 ;
struct V_27 * V_27 ;
int V_12 ;
if ( F_7 ( V_17 -> V_5 . V_10 , L_1 , NULL )
&& ! V_1 )
return - V_28 ;
V_19 = F_9 ( & V_17 -> V_5 , sizeof( * V_19 ) , V_29 ) ;
if ( ! V_19 ) {
F_5 ( & V_17 -> V_5 , L_6 ) ;
return - V_30 ;
}
V_24 = F_10 ( V_17 , V_31 , 0 ) ;
if ( ! V_24 ) {
F_5 ( & V_17 -> V_5 , L_7 ) ;
return - V_32 ;
}
V_27 = F_11 ( & V_17 -> V_5 ) ;
if ( F_12 ( V_27 ) )
F_13 ( & V_17 -> V_5 , L_8 ,
F_14 ( V_27 ) ) ;
V_19 -> V_33 = F_15 ( & V_17 -> V_5 , NULL ) ;
if ( F_12 ( V_19 -> V_33 ) ) {
F_5 ( & V_17 -> V_5 ,
L_9 , F_14 ( V_19 -> V_33 ) ) ;
return F_14 ( V_19 -> V_33 ) ;
}
V_12 = F_16 ( V_19 -> V_33 ) ;
if ( V_12 ) {
F_5 ( & V_17 -> V_5 ,
L_10 , V_12 ) ;
return V_12 ;
}
V_22 = F_17 ( V_17 -> V_5 . V_10 , L_11 , 0 ) ;
if ( V_22 ) {
V_19 -> V_22 = V_22 ;
V_21 = F_18 ( V_22 ) ;
if ( V_21 ) {
struct V_34 * V_35 ;
V_35 = F_19 ( V_21 ) ;
if ( V_35 &&
F_20 ( V_21 -> V_5 . V_36 -> V_37 ) ) {
F_21 ( V_35 ) ;
V_19 -> V_35 = V_35 ;
}
}
}
V_26 = F_22 ( & V_17 -> V_5 , L_12 ) ;
if ( ! F_12 ( V_26 ) ) {
V_12 = F_23 ( V_26 ) ;
if ( V_12 ) {
F_5 ( & V_17 -> V_5 ,
L_13 ,
V_12 ) ;
goto V_38;
}
V_19 -> V_26 = V_26 ;
} else {
V_26 = NULL ;
}
V_39 . V_35 = V_19 -> V_35 ;
if ( ! V_17 -> V_5 . V_40 )
V_17 -> V_5 . V_40 = & V_17 -> V_5 . V_41 ;
if ( ! V_17 -> V_5 . V_41 )
V_17 -> V_5 . V_41 = F_24 ( 32 ) ;
if ( V_1 && V_1 -> V_42 ) {
V_12 = V_1 -> V_42 ( & V_17 -> V_5 ) ;
if ( V_12 ) {
F_5 ( & V_17 -> V_5 ,
L_14 , V_12 ) ;
goto V_43;
}
}
V_20 = F_25 ( & V_17 -> V_5 ,
V_17 -> V_23 , V_17 -> V_44 ,
& V_39 ) ;
if ( F_12 ( V_20 ) ) {
V_12 = F_14 ( V_20 ) ;
F_5 ( & V_17 -> V_5 ,
L_15 ,
V_12 ) ;
goto V_43;
}
if ( V_1 && V_1 -> V_45 ) {
V_12 = V_1 -> V_45 ( & V_17 -> V_5 ) ;
if ( V_12 ) {
F_5 ( & V_17 -> V_5 ,
L_16 , V_12 ) ;
goto V_38;
}
}
V_19 -> V_46 = V_20 ;
F_26 ( V_17 , V_19 ) ;
F_27 ( & V_17 -> V_5 ) ;
F_28 ( & V_17 -> V_5 ) ;
return 0 ;
V_43:
if ( V_26 )
F_29 ( V_26 ) ;
V_38:
if ( V_22 )
F_6 ( V_22 ) ;
F_30 ( V_19 -> V_33 ) ;
return V_12 ;
}
static int F_31 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_32 ( V_17 ) ;
F_33 ( & V_17 -> V_5 ) ;
F_34 ( V_19 -> V_46 ) ;
if ( V_19 -> V_26 )
F_29 ( V_19 -> V_26 ) ;
if ( V_19 -> V_35 ) {
F_35 ( V_19 -> V_35 ) ;
F_36 ( V_19 -> V_35 -> V_5 -> V_36 -> V_37 ) ;
}
F_6 ( V_19 -> V_22 ) ;
F_30 ( V_19 -> V_33 ) ;
F_26 ( V_17 , NULL ) ;
return 0 ;
}
