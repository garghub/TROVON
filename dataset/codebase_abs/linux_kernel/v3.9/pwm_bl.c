static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = V_2 -> V_6 . V_5 ;
int V_7 = V_2 -> V_6 . V_8 ;
if ( V_2 -> V_6 . V_9 != V_10 ||
V_2 -> V_6 . V_11 != V_10 ||
V_2 -> V_6 . V_12 & V_13 )
V_5 = 0 ;
if ( V_4 -> V_14 )
V_5 = V_4 -> V_14 ( V_4 -> V_15 , V_5 ) ;
if ( V_5 == 0 ) {
F_3 ( V_4 -> V_16 , 0 , V_4 -> V_17 ) ;
F_4 ( V_4 -> V_16 ) ;
} else {
int V_18 ;
if ( V_4 -> V_19 ) {
V_18 = V_4 -> V_19 [ V_5 ] ;
V_7 = V_4 -> V_19 [ V_7 ] ;
} else {
V_18 = V_5 ;
}
V_18 = V_4 -> V_20 +
( V_18 * ( V_4 -> V_17 - V_4 -> V_20 ) / V_7 ) ;
F_3 ( V_4 -> V_16 , V_18 , V_4 -> V_17 ) ;
F_5 ( V_4 -> V_16 ) ;
}
if ( V_4 -> V_21 )
V_4 -> V_21 ( V_4 -> V_15 , V_5 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
return V_2 -> V_6 . V_5 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return ! V_4 -> V_24 || V_4 -> V_24 ( V_4 -> V_15 , V_23 ) ;
}
static int F_8 ( struct V_25 * V_15 ,
struct V_26 * V_27 )
{
struct V_28 * V_29 = V_15 -> V_30 ;
struct V_31 * V_32 ;
int V_33 ;
T_1 V_34 ;
int V_35 ;
if ( ! V_29 )
return - V_36 ;
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
V_32 = F_9 ( V_29 , L_1 , & V_33 ) ;
if ( ! V_32 )
return - V_37 ;
V_27 -> V_8 = V_33 / sizeof( T_1 ) ;
if ( V_27 -> V_8 > 0 ) {
T_2 V_38 = sizeof( * V_27 -> V_19 ) * V_27 -> V_8 ;
V_27 -> V_19 = F_10 ( V_15 , V_38 , V_39 ) ;
if ( ! V_27 -> V_19 )
return - V_40 ;
V_35 = F_11 ( V_29 , L_1 ,
V_27 -> V_19 ,
V_27 -> V_8 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_12 ( V_29 , L_2 ,
& V_34 ) ;
if ( V_35 < 0 )
return V_35 ;
V_27 -> V_41 = V_34 ;
V_27 -> V_8 -- ;
}
return 0 ;
}
static int F_8 ( struct V_25 * V_15 ,
struct V_26 * V_27 )
{
return - V_36 ;
}
static int F_13 ( struct V_42 * V_43 )
{
struct V_26 * V_27 = V_43 -> V_15 . V_44 ;
struct V_26 V_45 ;
struct V_46 V_6 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
unsigned int V_7 ;
int V_35 ;
if ( ! V_27 ) {
V_35 = F_8 ( & V_43 -> V_15 , & V_45 ) ;
if ( V_35 < 0 ) {
F_14 ( & V_43 -> V_15 , L_3 ) ;
return V_35 ;
}
V_27 = & V_45 ;
}
if ( V_27 -> V_47 ) {
V_35 = V_27 -> V_47 ( & V_43 -> V_15 ) ;
if ( V_35 < 0 )
return V_35 ;
}
V_4 = F_10 ( & V_43 -> V_15 , sizeof( * V_4 ) , V_39 ) ;
if ( ! V_4 ) {
F_14 ( & V_43 -> V_15 , L_4 ) ;
V_35 = - V_40 ;
goto V_48;
}
if ( V_27 -> V_19 ) {
V_7 = V_27 -> V_19 [ V_27 -> V_8 ] ;
V_4 -> V_19 = V_27 -> V_19 ;
} else
V_7 = V_27 -> V_8 ;
V_4 -> V_14 = V_27 -> V_14 ;
V_4 -> V_21 = V_27 -> V_21 ;
V_4 -> V_24 = V_27 -> V_24 ;
V_4 -> exit = V_27 -> exit ;
V_4 -> V_15 = & V_43 -> V_15 ;
V_4 -> V_16 = F_15 ( & V_43 -> V_15 , NULL ) ;
if ( F_16 ( V_4 -> V_16 ) ) {
F_14 ( & V_43 -> V_15 , L_5 ) ;
V_4 -> V_16 = F_17 ( V_27 -> V_49 , L_6 ) ;
if ( F_16 ( V_4 -> V_16 ) ) {
F_14 ( & V_43 -> V_15 , L_7 ) ;
V_35 = F_18 ( V_4 -> V_16 ) ;
goto V_48;
}
}
F_19 ( & V_43 -> V_15 , L_8 ) ;
if ( V_27 -> V_50 > 0 )
F_20 ( V_4 -> V_16 , V_27 -> V_50 ) ;
V_4 -> V_17 = F_21 ( V_4 -> V_16 ) ;
V_4 -> V_20 = V_27 -> V_20 * ( V_4 -> V_17 / V_7 ) ;
memset ( & V_6 , 0 , sizeof( struct V_46 ) ) ;
V_6 . type = V_51 ;
V_6 . V_8 = V_27 -> V_8 ;
V_2 = F_22 ( F_23 ( & V_43 -> V_15 ) , & V_43 -> V_15 , V_4 ,
& V_52 , & V_6 ) ;
if ( F_16 ( V_2 ) ) {
F_14 ( & V_43 -> V_15 , L_9 ) ;
V_35 = F_18 ( V_2 ) ;
goto V_48;
}
if ( V_27 -> V_41 > V_27 -> V_8 ) {
F_24 ( & V_43 -> V_15 ,
L_10 ,
V_27 -> V_41 , V_27 -> V_8 ) ;
V_27 -> V_41 = V_27 -> V_8 ;
}
V_2 -> V_6 . V_5 = V_27 -> V_41 ;
F_25 ( V_2 ) ;
F_26 ( V_43 , V_2 ) ;
return 0 ;
V_48:
if ( V_27 -> exit )
V_27 -> exit ( & V_43 -> V_15 ) ;
return V_35 ;
}
static int F_27 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_28 ( V_43 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_29 ( V_2 ) ;
F_3 ( V_4 -> V_16 , 0 , V_4 -> V_17 ) ;
F_4 ( V_4 -> V_16 ) ;
if ( V_4 -> exit )
V_4 -> exit ( & V_43 -> V_15 ) ;
return 0 ;
}
static int F_30 ( struct V_25 * V_15 )
{
struct V_1 * V_2 = F_31 ( V_15 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_14 )
V_4 -> V_14 ( V_4 -> V_15 , 0 ) ;
F_3 ( V_4 -> V_16 , 0 , V_4 -> V_17 ) ;
F_4 ( V_4 -> V_16 ) ;
if ( V_4 -> V_21 )
V_4 -> V_21 ( V_4 -> V_15 , 0 ) ;
return 0 ;
}
static int F_32 ( struct V_25 * V_15 )
{
struct V_1 * V_2 = F_31 ( V_15 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
