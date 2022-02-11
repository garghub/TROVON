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
V_2 -> V_27 = F_13 ( & V_18 ) ;
if ( ! F_14 ( V_2 -> V_25 , V_2 -> V_27 , V_28 ) ) {
F_15 ( V_29 L_11 , __FILE__ ) ;
V_20 = - V_30 ;
goto V_31;
}
V_19 = F_16 ( V_14 , 0 ) ;
if ( ! V_19 ) {
F_15 ( V_29 L_12 , __FILE__ ) ;
V_20 = - V_30 ;
goto V_32;
}
V_2 -> V_33 = F_17 ( V_2 -> V_25 , V_2 -> V_27 ) ;
if ( ! V_2 -> V_33 ) {
F_15 ( V_29 L_13 , __FILE__ ) ;
V_20 = - V_24 ;
goto V_34;
}
V_4 = F_2 ( V_2 ) ;
V_4 -> V_35 = 1 ;
V_4 -> V_36 = 1 ;
V_21 = ( int * ) F_18 ( V_14 , L_14 , NULL ) ;
if ( V_21 && ( * V_21 == 1 ) ) {
F_19 ( V_4 , L_15 ) ;
V_2 -> V_10 = 1 ;
} else {
F_19 ( V_4 ,
L_16 ) ;
V_2 -> V_10 = 0 ;
}
V_4 -> V_37 = V_2 -> V_33 + 0x100 ;
V_4 -> V_33 = V_2 -> V_33 + 0x100 +
F_20 ( V_4 , F_21 ( V_4 , & V_4 -> V_37 -> V_38 ) ) ;
V_4 -> V_39 = F_21 ( V_4 , & V_4 -> V_37 -> V_39 ) ;
V_20 = F_22 ( V_2 , V_19 , 0 ) ;
if ( V_20 == 0 )
return 0 ;
F_23 ( V_2 -> V_33 ) ;
V_34:
V_32:
F_24 ( V_2 -> V_25 , V_2 -> V_27 ) ;
V_31:
F_25 ( V_2 ) ;
return V_20 ;
}
static int F_26 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_27 ( & V_12 -> V_15 ) ;
F_28 ( & V_12 -> V_15 , NULL ) ;
F_10 ( & V_12 -> V_15 , L_17 ) ;
F_29 ( V_2 ) ;
F_23 ( V_2 -> V_33 ) ;
F_24 ( V_2 -> V_25 , V_2 -> V_27 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
static int F_30 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_27 ( & V_12 -> V_15 ) ;
if ( V_2 -> V_40 -> V_41 )
V_2 -> V_40 -> V_41 ( V_2 ) ;
return 0 ;
}
