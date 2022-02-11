static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
int V_6 = V_2 -> V_7 . V_6 ;
int V_8 = V_2 -> V_7 . V_9 ;
if ( V_2 -> V_7 . V_10 != V_11 )
V_6 = 0 ;
if ( V_2 -> V_7 . V_12 != V_11 )
V_6 = 0 ;
if ( V_4 -> V_13 )
V_6 = V_4 -> V_13 ( V_4 -> V_5 , V_6 ) ;
if ( V_6 == 0 ) {
F_3 ( V_4 -> V_14 , 0 , V_4 -> V_15 ) ;
F_4 ( V_4 -> V_14 ) ;
} else {
int V_16 ;
if ( V_4 -> V_17 ) {
V_16 = V_4 -> V_17 [ V_6 ] ;
V_8 = V_4 -> V_17 [ V_8 ] ;
} else {
V_16 = V_6 ;
}
V_16 = V_4 -> V_18 +
( V_16 * ( V_4 -> V_15 - V_4 -> V_18 ) / V_8 ) ;
F_3 ( V_4 -> V_14 , V_16 , V_4 -> V_15 ) ;
F_5 ( V_4 -> V_14 ) ;
}
if ( V_4 -> V_19 )
V_4 -> V_19 ( V_4 -> V_5 , V_6 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
return V_2 -> V_7 . V_6 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
return ! V_4 -> V_22 || V_4 -> V_22 ( V_4 -> V_5 , V_21 ) ;
}
static int F_8 ( struct V_23 * V_5 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = V_5 -> V_28 ;
struct V_29 * V_30 ;
int V_31 ;
T_1 V_32 ;
int V_33 ;
if ( ! V_27 )
return - V_34 ;
memset ( V_25 , 0 , sizeof( * V_25 ) ) ;
V_30 = F_9 ( V_27 , L_1 , & V_31 ) ;
if ( ! V_30 )
return - V_35 ;
V_25 -> V_9 = V_31 / sizeof( T_1 ) ;
if ( V_25 -> V_9 > 0 ) {
T_2 V_36 = sizeof( * V_25 -> V_17 ) * V_25 -> V_9 ;
V_25 -> V_17 = F_10 ( V_5 , V_36 , V_37 ) ;
if ( ! V_25 -> V_17 )
return - V_38 ;
V_33 = F_11 ( V_27 , L_1 ,
V_25 -> V_17 ,
V_25 -> V_9 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_12 ( V_27 , L_2 ,
& V_32 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_32 >= V_25 -> V_9 ) {
F_13 ( V_5 , L_3 ,
V_32 , V_25 -> V_9 - 1 ) ;
V_32 = V_25 -> V_9 - 1 ;
}
V_25 -> V_39 = V_32 ;
V_25 -> V_9 -- ;
}
return 0 ;
}
static int F_8 ( struct V_23 * V_5 ,
struct V_24 * V_25 )
{
return - V_34 ;
}
static int F_14 ( struct V_40 * V_41 )
{
struct V_24 * V_25 = V_41 -> V_5 . V_42 ;
struct V_24 V_43 ;
struct V_44 V_7 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
unsigned int V_8 ;
int V_33 ;
if ( ! V_25 ) {
V_33 = F_8 ( & V_41 -> V_5 , & V_43 ) ;
if ( V_33 < 0 ) {
F_15 ( & V_41 -> V_5 , L_4 ) ;
return V_33 ;
}
V_25 = & V_43 ;
}
if ( V_25 -> V_45 ) {
V_33 = V_25 -> V_45 ( & V_41 -> V_5 ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_4 = F_10 ( & V_41 -> V_5 , sizeof( * V_4 ) , V_37 ) ;
if ( ! V_4 ) {
F_15 ( & V_41 -> V_5 , L_5 ) ;
V_33 = - V_38 ;
goto V_46;
}
if ( V_25 -> V_17 ) {
V_8 = V_25 -> V_17 [ V_25 -> V_9 ] ;
V_4 -> V_17 = V_25 -> V_17 ;
} else
V_8 = V_25 -> V_9 ;
V_4 -> V_13 = V_25 -> V_13 ;
V_4 -> V_19 = V_25 -> V_19 ;
V_4 -> V_22 = V_25 -> V_22 ;
V_4 -> exit = V_25 -> exit ;
V_4 -> V_5 = & V_41 -> V_5 ;
V_4 -> V_14 = F_16 ( & V_41 -> V_5 , NULL ) ;
if ( F_17 ( V_4 -> V_14 ) ) {
F_15 ( & V_41 -> V_5 , L_6 ) ;
V_4 -> V_14 = F_18 ( V_25 -> V_47 , L_7 ) ;
if ( F_17 ( V_4 -> V_14 ) ) {
F_15 ( & V_41 -> V_5 , L_8 ) ;
V_33 = F_19 ( V_4 -> V_14 ) ;
goto V_46;
}
}
F_20 ( & V_41 -> V_5 , L_9 ) ;
if ( V_25 -> V_48 > 0 )
F_21 ( V_4 -> V_14 , V_25 -> V_48 ) ;
V_4 -> V_15 = F_22 ( V_4 -> V_14 ) ;
V_4 -> V_18 = V_25 -> V_18 * ( V_4 -> V_15 / V_8 ) ;
memset ( & V_7 , 0 , sizeof( struct V_44 ) ) ;
V_7 . type = V_49 ;
V_7 . V_9 = V_25 -> V_9 ;
V_2 = F_23 ( F_24 ( & V_41 -> V_5 ) , & V_41 -> V_5 , V_4 ,
& V_50 , & V_7 ) ;
if ( F_17 ( V_2 ) ) {
F_15 ( & V_41 -> V_5 , L_10 ) ;
V_33 = F_19 ( V_2 ) ;
goto V_51;
}
V_2 -> V_7 . V_6 = V_25 -> V_39 ;
F_25 ( V_2 ) ;
F_26 ( V_41 , V_2 ) ;
return 0 ;
V_51:
F_27 ( V_4 -> V_14 ) ;
V_46:
if ( V_25 -> exit )
V_25 -> exit ( & V_41 -> V_5 ) ;
return V_33 ;
}
static int F_28 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_29 ( V_41 ) ;
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
F_30 ( V_2 ) ;
F_3 ( V_4 -> V_14 , 0 , V_4 -> V_15 ) ;
F_4 ( V_4 -> V_14 ) ;
F_27 ( V_4 -> V_14 ) ;
if ( V_4 -> exit )
V_4 -> exit ( & V_41 -> V_5 ) ;
return 0 ;
}
static int F_31 ( struct V_23 * V_5 )
{
struct V_1 * V_2 = F_2 ( V_5 ) ;
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
if ( V_4 -> V_13 )
V_4 -> V_13 ( V_4 -> V_5 , 0 ) ;
F_3 ( V_4 -> V_14 , 0 , V_4 -> V_15 ) ;
F_4 ( V_4 -> V_14 ) ;
if ( V_4 -> V_19 )
V_4 -> V_19 ( V_4 -> V_5 , 0 ) ;
return 0 ;
}
static int F_32 ( struct V_23 * V_5 )
{
struct V_1 * V_2 = F_2 ( V_5 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
