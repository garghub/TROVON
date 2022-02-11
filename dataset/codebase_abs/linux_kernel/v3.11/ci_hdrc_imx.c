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
struct V_20 V_21 = {
. V_22 = L_6 ,
. V_23 = V_24 ,
. V_25 = V_26 |
V_27 |
V_28 ,
} ;
struct V_29 * V_30 ;
int V_12 ;
if ( F_7 ( V_17 -> V_5 . V_10 , L_1 , NULL )
&& ! V_1 )
return - V_31 ;
V_19 = F_9 ( & V_17 -> V_5 , sizeof( * V_19 ) , V_32 ) ;
if ( ! V_19 ) {
F_5 ( & V_17 -> V_5 , L_7 ) ;
return - V_33 ;
}
V_30 = F_10 ( V_17 , V_34 , 0 ) ;
if ( ! V_30 ) {
F_5 ( & V_17 -> V_5 , L_8 ) ;
return - V_35 ;
}
V_19 -> V_36 = F_11 ( & V_17 -> V_5 , NULL ) ;
if ( F_12 ( V_19 -> V_36 ) ) {
F_5 ( & V_17 -> V_5 ,
L_9 , F_13 ( V_19 -> V_36 ) ) ;
return F_13 ( V_19 -> V_36 ) ;
}
V_12 = F_14 ( V_19 -> V_36 ) ;
if ( V_12 ) {
F_5 ( & V_17 -> V_5 ,
L_10 , V_12 ) ;
return V_12 ;
}
V_19 -> V_37 = F_15 ( & V_17 -> V_5 , L_11 , 0 ) ;
if ( ! F_12 ( V_19 -> V_37 ) ) {
V_12 = F_16 ( V_19 -> V_37 ) ;
if ( V_12 ) {
F_5 ( & V_17 -> V_5 , L_12 , V_12 ) ;
goto V_38;
}
} else if ( F_13 ( V_19 -> V_37 ) == - V_31 ) {
V_12 = - V_31 ;
goto V_38;
}
V_19 -> V_39 = F_17 ( & V_17 -> V_5 , L_13 ) ;
if ( ! F_12 ( V_19 -> V_39 ) ) {
V_12 = F_18 ( V_19 -> V_39 ) ;
if ( V_12 ) {
F_5 ( & V_17 -> V_5 ,
L_14 ,
V_12 ) ;
goto V_38;
}
} else {
V_19 -> V_39 = NULL ;
}
V_21 . V_37 = V_19 -> V_37 ;
if ( ! V_17 -> V_5 . V_40 )
V_17 -> V_5 . V_40 = & V_17 -> V_5 . V_41 ;
if ( ! V_17 -> V_5 . V_41 )
V_17 -> V_5 . V_41 = F_19 ( 32 ) ;
if ( V_1 && V_1 -> V_42 ) {
V_12 = V_1 -> V_42 ( & V_17 -> V_5 ) ;
if ( V_12 ) {
F_5 ( & V_17 -> V_5 ,
L_15 , V_12 ) ;
goto V_43;
}
}
V_19 -> V_44 = F_20 ( & V_17 -> V_5 ,
V_17 -> V_29 , V_17 -> V_45 ,
& V_21 ) ;
if ( F_12 ( V_19 -> V_44 ) ) {
V_12 = F_13 ( V_19 -> V_44 ) ;
F_5 ( & V_17 -> V_5 ,
L_16 ,
V_12 ) ;
goto V_43;
}
if ( V_1 && V_1 -> V_46 ) {
V_12 = V_1 -> V_46 ( & V_17 -> V_5 ) ;
if ( V_12 ) {
F_5 ( & V_17 -> V_5 ,
L_17 , V_12 ) ;
goto V_47;
}
}
F_21 ( V_17 , V_19 ) ;
F_22 ( & V_17 -> V_5 ) ;
F_23 ( & V_17 -> V_5 ) ;
return 0 ;
V_47:
F_24 ( V_19 -> V_44 ) ;
V_43:
if ( V_19 -> V_39 )
F_25 ( V_19 -> V_39 ) ;
V_38:
F_26 ( V_19 -> V_36 ) ;
return V_12 ;
}
static int F_27 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_28 ( V_17 ) ;
F_29 ( & V_17 -> V_5 ) ;
F_24 ( V_19 -> V_44 ) ;
if ( V_19 -> V_39 )
F_25 ( V_19 -> V_39 ) ;
if ( V_19 -> V_37 ) {
F_30 ( V_19 -> V_37 ) ;
F_31 ( V_19 -> V_37 -> V_5 -> V_48 -> V_49 ) ;
}
F_26 ( V_19 -> V_36 ) ;
return 0 ;
}
