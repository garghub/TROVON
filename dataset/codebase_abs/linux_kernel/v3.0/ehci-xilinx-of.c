static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
V_5 = F_3 ( V_4 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 ) ;
if ( V_5 )
return V_5 ;
V_4 -> V_6 = 0x20 ;
return F_5 ( V_4 ) ;
}
static int F_6 ( struct V_1 * V_2 , int V_7 )
{
F_7 ( V_2 -> V_8 . V_9 , L_1 , V_7 ) ;
if ( V_2 -> V_10 ) {
F_7 ( V_2 -> V_8 . V_9 ,
L_2 ) ;
F_7 ( V_2 -> V_8 . V_9 ,
L_3 ) ;
} else {
F_7 ( V_2 -> V_8 . V_9 ,
L_4 ) ;
F_7 ( V_2 -> V_8 . V_9 ,
L_5
L_6 ) ;
F_7 ( V_2 -> V_8 . V_9 ,
L_7
L_8 ) ;
}
return 0 ;
}
static int T_1 F_8 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 . V_16 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_17 V_18 ;
int V_19 ;
int V_20 ;
int * V_21 ;
if ( F_9 () )
return - V_22 ;
F_10 ( & V_12 -> V_15 , L_9 ) ;
V_20 = F_11 ( V_14 , 0 , & V_18 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_12 ( & V_23 , & V_12 -> V_15 ,
L_10 ) ;
if ( ! V_2 )
return - V_24 ;
V_2 -> V_25 = V_18 . V_26 ;
V_2 -> V_27 = V_18 . V_28 - V_18 . V_26 + 1 ;
if ( ! F_13 ( V_2 -> V_25 , V_2 -> V_27 , V_29 ) ) {
F_14 ( V_30 L_11 , __FILE__ ) ;
V_20 = - V_31 ;
goto V_32;
}
V_19 = F_15 ( V_14 , 0 ) ;
if ( V_19 == V_33 ) {
F_14 ( V_30 L_12 , __FILE__ ) ;
V_20 = - V_31 ;
goto V_34;
}
V_2 -> V_35 = F_16 ( V_2 -> V_25 , V_2 -> V_27 ) ;
if ( ! V_2 -> V_35 ) {
F_14 ( V_30 L_13 , __FILE__ ) ;
V_20 = - V_24 ;
goto V_36;
}
V_4 = F_2 ( V_2 ) ;
V_4 -> V_37 = 1 ;
V_4 -> V_38 = 1 ;
V_21 = ( int * ) F_17 ( V_14 , L_14 , NULL ) ;
if ( V_21 && ( * V_21 == 1 ) ) {
F_18 ( V_4 , L_15 ) ;
V_2 -> V_10 = 1 ;
} else {
F_18 ( V_4 ,
L_16 ) ;
V_2 -> V_10 = 0 ;
}
V_4 -> V_39 = V_2 -> V_35 + 0x100 ;
V_4 -> V_35 = V_2 -> V_35 + 0x100 +
F_19 ( V_4 , F_20 ( V_4 , & V_4 -> V_39 -> V_40 ) ) ;
V_4 -> V_41 = F_20 ( V_4 , & V_4 -> V_39 -> V_41 ) ;
V_20 = F_21 ( V_2 , V_19 , 0 ) ;
if ( V_20 == 0 )
return 0 ;
F_22 ( V_2 -> V_35 ) ;
V_36:
V_34:
F_23 ( V_2 -> V_25 , V_2 -> V_27 ) ;
V_32:
F_24 ( V_2 ) ;
return V_20 ;
}
static int F_25 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_26 ( & V_12 -> V_15 ) ;
F_27 ( & V_12 -> V_15 , NULL ) ;
F_10 ( & V_12 -> V_15 , L_17 ) ;
F_28 ( V_2 ) ;
F_22 ( V_2 -> V_35 ) ;
F_23 ( V_2 -> V_25 , V_2 -> V_27 ) ;
F_24 ( V_2 ) ;
return 0 ;
}
static int F_29 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_26 ( & V_12 -> V_15 ) ;
if ( V_2 -> V_42 -> V_43 )
V_2 -> V_42 -> V_43 ( V_2 ) ;
return 0 ;
}
