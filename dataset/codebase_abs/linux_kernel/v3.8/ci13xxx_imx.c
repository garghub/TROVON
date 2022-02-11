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
return 0 ;
}
static int F_8 ( struct V_15 * V_16 )
{
struct V_17 * V_18 ;
struct V_15 * V_19 , * V_20 ;
struct V_8 * V_21 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
struct V_26 * V_26 ;
int V_12 ;
if ( F_7 ( V_16 -> V_5 . V_10 , L_1 , NULL )
&& ! V_1 )
return - V_27 ;
V_18 = F_9 ( & V_16 -> V_5 , sizeof( * V_18 ) , V_28 ) ;
if ( ! V_18 ) {
F_5 ( & V_16 -> V_5 , L_5 ) ;
return - V_29 ;
}
V_23 = F_10 ( V_16 , V_30 , 0 ) ;
if ( ! V_23 ) {
F_5 ( & V_16 -> V_5 , L_6 ) ;
return - V_31 ;
}
V_26 = F_11 ( & V_16 -> V_5 ) ;
if ( F_12 ( V_26 ) )
F_13 ( & V_16 -> V_5 , L_7 ,
F_14 ( V_26 ) ) ;
V_18 -> V_32 = F_15 ( & V_16 -> V_5 , NULL ) ;
if ( F_12 ( V_18 -> V_32 ) ) {
F_5 ( & V_16 -> V_5 ,
L_8 , F_14 ( V_18 -> V_32 ) ) ;
return F_14 ( V_18 -> V_32 ) ;
}
V_12 = F_16 ( V_18 -> V_32 ) ;
if ( V_12 ) {
F_5 ( & V_16 -> V_5 ,
L_9 , V_12 ) ;
return V_12 ;
}
V_21 = F_17 ( V_16 -> V_5 . V_10 , L_10 , 0 ) ;
if ( V_21 ) {
V_18 -> V_21 = V_21 ;
V_20 = F_18 ( V_21 ) ;
if ( V_20 ) {
struct V_33 * V_34 ;
V_34 = F_19 ( V_20 ) ;
if ( V_34 &&
F_20 ( V_20 -> V_5 . V_35 -> V_36 ) ) {
F_21 ( V_34 ) ;
V_18 -> V_34 = V_34 ;
}
}
}
V_25 = F_22 ( & V_16 -> V_5 , L_11 ) ;
if ( ! F_12 ( V_25 ) ) {
V_12 = F_23 ( V_25 ) ;
if ( V_12 ) {
F_5 ( & V_16 -> V_5 ,
L_12 ,
V_12 ) ;
goto V_37;
}
V_18 -> V_25 = V_25 ;
} else {
V_25 = NULL ;
}
V_38 . V_34 = V_18 -> V_34 ;
if ( ! V_16 -> V_5 . V_39 ) {
V_16 -> V_5 . V_39 = F_9 ( & V_16 -> V_5 ,
sizeof( * V_16 -> V_5 . V_39 ) , V_28 ) ;
if ( ! V_16 -> V_5 . V_39 ) {
V_12 = - V_29 ;
F_5 ( & V_16 -> V_5 , L_13 ) ;
goto V_40;
}
* V_16 -> V_5 . V_39 = F_24 ( 32 ) ;
F_25 ( & V_16 -> V_5 , * V_16 -> V_5 . V_39 ) ;
}
if ( V_1 && V_1 -> V_41 ) {
V_12 = V_1 -> V_41 ( & V_16 -> V_5 ) ;
if ( V_12 ) {
F_5 ( & V_16 -> V_5 ,
L_14 , V_12 ) ;
goto V_40;
}
}
V_19 = F_26 ( & V_16 -> V_5 ,
V_16 -> V_22 , V_16 -> V_42 ,
& V_38 ) ;
if ( F_12 ( V_19 ) ) {
V_12 = F_14 ( V_19 ) ;
F_5 ( & V_16 -> V_5 ,
L_15 ,
V_12 ) ;
goto V_40;
}
V_18 -> V_43 = V_19 ;
F_27 ( V_16 , V_18 ) ;
F_28 ( & V_16 -> V_5 ) ;
F_29 ( & V_16 -> V_5 ) ;
return 0 ;
V_40:
if ( V_25 )
F_30 ( V_25 ) ;
V_37:
if ( V_21 )
F_6 ( V_21 ) ;
F_31 ( V_18 -> V_32 ) ;
return V_12 ;
}
static int F_32 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_33 ( V_16 ) ;
F_34 ( & V_16 -> V_5 ) ;
F_35 ( V_18 -> V_43 ) ;
if ( V_18 -> V_25 )
F_30 ( V_18 -> V_25 ) ;
if ( V_18 -> V_34 ) {
F_36 ( V_18 -> V_34 ) ;
F_37 ( V_18 -> V_34 -> V_5 -> V_35 -> V_36 ) ;
}
F_6 ( V_18 -> V_21 ) ;
F_31 ( V_18 -> V_32 ) ;
F_27 ( V_16 , NULL ) ;
return 0 ;
}
