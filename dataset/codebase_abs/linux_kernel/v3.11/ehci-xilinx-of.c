static int F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_2 -> V_4 . V_5 , L_1 , V_3 ) ;
if ( V_2 -> V_6 ) {
F_2 ( V_2 -> V_4 . V_5 ,
L_2 ) ;
F_2 ( V_2 -> V_4 . V_5 ,
L_3 ) ;
} else {
F_2 ( V_2 -> V_4 . V_5 ,
L_4 ) ;
F_2 ( V_2 -> V_4 . V_5 ,
L_5
L_6 ) ;
F_2 ( V_2 -> V_4 . V_5 ,
L_7
L_8 ) ;
}
return 0 ;
}
static int F_3 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 . V_12 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
struct V_15 V_16 ;
int V_17 ;
int V_18 ;
int * V_19 ;
if ( F_4 () )
return - V_20 ;
F_5 ( & V_8 -> V_11 , L_9 ) ;
V_18 = F_6 ( V_10 , 0 , & V_16 ) ;
if ( V_18 )
return V_18 ;
V_2 = F_7 ( & V_21 , & V_8 -> V_11 ,
L_10 ) ;
if ( ! V_2 )
return - V_22 ;
V_2 -> V_23 = V_16 . V_24 ;
V_2 -> V_25 = F_8 ( & V_16 ) ;
V_17 = F_9 ( V_10 , 0 ) ;
if ( ! V_17 ) {
F_10 ( V_26 L_11 , __FILE__ ) ;
V_18 = - V_27 ;
goto V_28;
}
V_2 -> V_29 = F_11 ( & V_8 -> V_11 , & V_16 ) ;
if ( F_12 ( V_2 -> V_29 ) ) {
V_18 = F_13 ( V_2 -> V_29 ) ;
goto V_28;
}
V_14 = F_14 ( V_2 ) ;
V_14 -> V_30 = 1 ;
V_14 -> V_31 = 1 ;
V_19 = ( int * ) F_15 ( V_10 , L_12 , NULL ) ;
if ( V_19 && ( * V_19 == 1 ) ) {
F_16 ( V_14 , L_13 ) ;
V_2 -> V_6 = 1 ;
} else {
F_16 ( V_14 ,
L_14 ) ;
V_2 -> V_6 = 0 ;
}
V_14 -> V_32 = V_2 -> V_29 + 0x100 ;
V_18 = F_17 ( V_2 , V_17 , 0 ) ;
if ( V_18 == 0 )
return 0 ;
V_28:
F_18 ( V_2 ) ;
return V_18 ;
}
static int F_19 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_20 ( V_8 ) ;
F_5 ( & V_8 -> V_11 , L_15 ) ;
F_21 ( V_2 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
static void F_22 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_20 ( V_8 ) ;
if ( V_2 -> V_33 -> V_34 )
V_2 -> V_33 -> V_34 ( V_2 ) ;
}
