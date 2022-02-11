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
static int T_1
F_6 ( struct V_7 * V_8 )
{
T_2 T_3 * V_9 ;
V_9 = F_7 ( V_8 , 1 ) ;
if ( ! V_9 )
return - V_10 ;
F_8 ( V_9 + 3 , V_11 ) ;
F_9 ( V_9 ) ;
return 0 ;
}
static int T_1 F_10 ( struct V_12 * V_13 )
{
struct V_7 * V_8 = V_13 -> V_14 . V_15 ;
struct V_1 * V_2 ;
struct V_3 * V_4 = NULL ;
struct V_16 V_17 ;
int V_18 ;
int V_19 ;
struct V_7 * V_20 ;
if ( F_11 () )
return - V_21 ;
F_12 ( & V_13 -> V_14 , L_1 ) ;
V_19 = F_13 ( V_8 , 0 , & V_17 ) ;
if ( V_19 )
return V_19 ;
V_2 = F_14 ( & V_22 , & V_13 -> V_14 , L_2 ) ;
if ( ! V_2 )
return - V_23 ;
V_2 -> V_24 = V_17 . V_25 ;
V_2 -> V_26 = F_15 ( & V_17 ) ;
if ( ! F_16 ( V_2 -> V_24 , V_2 -> V_26 , V_27 ) ) {
F_17 ( V_28 L_3 , __FILE__ ) ;
V_19 = - V_29 ;
goto V_30;
}
V_18 = F_18 ( V_8 , 0 ) ;
if ( V_18 == V_31 ) {
F_17 ( V_28 L_4 , __FILE__ ) ;
V_19 = - V_29 ;
goto V_32;
}
V_2 -> V_33 = F_19 ( V_2 -> V_24 , V_2 -> V_26 ) ;
if ( ! V_2 -> V_33 ) {
F_17 ( V_28 L_5 , __FILE__ ) ;
V_19 = - V_23 ;
goto V_34;
}
V_4 = F_2 ( V_2 ) ;
V_20 = F_20 ( NULL , NULL , L_6 ) ;
if ( V_20 != NULL ) {
if ( ! F_13 ( V_20 , 0 , & V_17 ) )
V_4 -> V_35 = F_19 ( V_17 . V_25 +
V_36 , V_37 ) ;
else
F_21 ( L_7 , __FILE__ ) ;
if ( ! V_4 -> V_35 ) {
F_21 ( L_8 , __FILE__ ) ;
} else {
V_4 -> V_38 = 1 ;
}
}
if ( F_22 ( V_8 , L_9 , NULL ) ) {
V_4 -> V_39 = 1 ;
V_4 -> V_40 = 1 ;
}
if ( F_22 ( V_8 , L_10 , NULL ) )
V_4 -> V_39 = 1 ;
if ( F_22 ( V_8 , L_11 , NULL ) )
V_4 -> V_40 = 1 ;
V_4 -> V_41 = V_2 -> V_33 ;
V_4 -> V_33 = V_2 -> V_33 +
F_23 ( V_4 , F_24 ( V_4 , & V_4 -> V_41 -> V_42 ) ) ;
V_4 -> V_43 = F_24 ( V_4 , & V_4 -> V_41 -> V_43 ) ;
if ( F_25 ( V_8 , L_12 ) ) {
V_19 = F_6 ( V_8 ) ;
F_26 ( V_4 , L_13 ,
V_19 ? L_14 : L_15 ) ;
}
V_19 = F_27 ( V_2 , V_18 , 0 ) ;
if ( V_19 )
goto V_44;
return 0 ;
V_44:
if ( V_4 -> V_38 )
F_9 ( V_4 -> V_35 ) ;
F_9 ( V_2 -> V_33 ) ;
V_34:
F_28 ( V_18 ) ;
V_32:
F_29 ( V_2 -> V_24 , V_2 -> V_26 ) ;
V_30:
F_30 ( V_2 ) ;
return V_19 ;
}
static int F_31 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_32 ( & V_13 -> V_14 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_20 ;
struct V_16 V_17 ;
F_33 ( & V_13 -> V_14 , NULL ) ;
F_12 ( & V_13 -> V_14 , L_16 ) ;
F_34 ( V_2 ) ;
F_9 ( V_2 -> V_33 ) ;
F_28 ( V_2 -> V_18 ) ;
F_29 ( V_2 -> V_24 , V_2 -> V_26 ) ;
if ( V_4 -> V_38 ) {
V_20 = F_20 ( NULL , NULL , L_6 ) ;
if ( V_20 != NULL ) {
if ( ! F_13 ( V_20 , 0 , & V_17 ) )
if ( ! F_16 ( V_17 . V_25 ,
0x4 , V_27 ) )
F_35 ( V_4 , 1 ) ;
else
F_29 ( V_17 . V_25 , 0x4 ) ;
else
F_21 ( L_7 , __FILE__ ) ;
F_36 ( V_20 ) ;
}
F_9 ( V_4 -> V_35 ) ;
}
F_30 ( V_2 ) ;
return 0 ;
}
static void F_37 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_32 ( & V_13 -> V_14 ) ;
if ( V_2 -> V_45 -> V_46 )
V_2 -> V_45 -> V_46 ( V_2 ) ;
}
