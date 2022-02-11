static int
F_1 ( struct V_1 * V_2 )
{
T_1 T_2 * V_3 ;
V_3 = F_2 ( V_2 , 1 ) ;
if ( ! V_3 )
return - V_4 ;
F_3 ( V_3 + 3 , V_5 ) ;
F_4 ( V_3 ) ;
return 0 ;
}
static int F_5 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_8 . V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 = NULL ;
struct V_14 V_15 ;
int V_16 ;
int V_17 ;
struct V_1 * V_18 ;
if ( F_6 () )
return - V_19 ;
F_7 ( & V_7 -> V_8 , L_1 ) ;
V_17 = F_8 ( V_2 , 0 , & V_15 ) ;
if ( V_17 )
return V_17 ;
V_11 = F_9 ( & V_20 , & V_7 -> V_8 , L_2 ) ;
if ( ! V_11 )
return - V_21 ;
V_11 -> V_22 = V_15 . V_23 ;
V_11 -> V_24 = F_10 ( & V_15 ) ;
V_16 = F_11 ( V_2 , 0 ) ;
if ( V_16 == V_25 ) {
F_12 ( V_26 L_3 , __FILE__ ) ;
V_17 = - V_27 ;
goto V_28;
}
V_11 -> V_29 = F_13 ( & V_7 -> V_8 , & V_15 ) ;
if ( F_14 ( V_11 -> V_29 ) ) {
V_17 = F_15 ( V_11 -> V_29 ) ;
goto V_30;
}
V_13 = F_16 ( V_11 ) ;
V_18 = F_17 ( NULL , NULL , L_4 ) ;
if ( V_18 != NULL ) {
if ( ! F_8 ( V_18 , 0 , & V_15 ) )
V_13 -> V_31 =
F_18 ( & V_7 -> V_8 ,
V_15 . V_23 + V_32 ,
V_33 ) ;
else
F_19 ( L_5 , __FILE__ ) ;
if ( ! V_13 -> V_31 ) {
F_19 ( L_6 , __FILE__ ) ;
} else {
V_13 -> V_34 = 1 ;
}
}
if ( F_20 ( V_2 , L_7 , NULL ) ) {
V_13 -> V_35 = 1 ;
V_13 -> V_36 = 1 ;
}
if ( F_20 ( V_2 , L_8 , NULL ) )
V_13 -> V_35 = 1 ;
if ( F_20 ( V_2 , L_9 , NULL ) )
V_13 -> V_36 = 1 ;
V_13 -> V_37 = V_11 -> V_29 ;
if ( F_21 ( V_2 , L_10 ) ) {
V_17 = F_1 ( V_2 ) ;
F_22 ( V_13 , L_11 ,
V_17 ? L_12 : L_13 ) ;
}
V_17 = F_23 ( V_11 , V_16 , 0 ) ;
if ( V_17 )
goto V_30;
return 0 ;
V_30:
F_24 ( V_16 ) ;
V_28:
F_25 ( V_11 ) ;
return V_17 ;
}
static int F_26 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_27 ( V_7 ) ;
struct V_12 * V_13 = F_16 ( V_11 ) ;
struct V_1 * V_18 ;
struct V_14 V_15 ;
F_7 ( & V_7 -> V_8 , L_14 ) ;
F_28 ( V_11 ) ;
F_24 ( V_11 -> V_16 ) ;
if ( V_13 -> V_34 ) {
V_18 = F_17 ( NULL , NULL , L_4 ) ;
if ( V_18 != NULL ) {
if ( ! F_8 ( V_18 , 0 , & V_15 ) )
if ( ! F_29 ( V_15 . V_23 ,
0x4 , V_38 ) )
F_30 ( V_13 , 1 ) ;
else
F_31 ( V_15 . V_23 , 0x4 ) ;
else
F_19 ( L_5 , __FILE__ ) ;
F_32 ( V_18 ) ;
}
}
F_25 ( V_11 ) ;
return 0 ;
}
static void F_33 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_27 ( V_7 ) ;
if ( V_11 -> V_39 -> V_40 )
V_11 -> V_39 -> V_40 ( V_11 ) ;
}
