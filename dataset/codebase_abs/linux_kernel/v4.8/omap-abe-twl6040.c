static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
int V_14 , V_15 ;
int V_16 ;
V_14 = F_3 ( V_6 -> V_17 ) ;
if ( V_14 == V_18 )
V_15 = V_13 -> V_19 ;
else if ( V_14 == V_20 )
V_15 = 32768 ;
else
return - V_21 ;
V_16 = F_4 ( V_9 , V_14 , V_15 ,
V_22 ) ;
if ( V_16 ) {
F_5 ( V_23 L_1 ) ;
return V_16 ;
}
return V_16 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_24 = V_6 -> V_24 ;
int V_16 = 0 ;
V_16 = F_4 ( V_24 , V_25 ,
19200000 , V_22 ) ;
if ( V_16 < 0 ) {
F_5 ( V_23 L_2 ) ;
return V_16 ;
}
V_16 = F_4 ( V_24 , V_26 , 2400000 ,
V_27 ) ;
if ( V_16 < 0 ) {
F_5 ( V_23 L_3 ) ;
return V_16 ;
}
return 0 ;
}
static int F_7 ( struct V_5 * V_6 )
{
struct V_28 * V_17 = V_6 -> V_17 ;
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
int V_29 ;
int V_16 = 0 ;
V_29 = F_8 ( V_17 , V_30 ) ;
F_9 ( V_6 , F_10 ( V_29 ) ,
F_11 ( V_29 ) ) ;
if ( V_13 -> V_31 ) {
V_16 = F_12 ( V_6 -> V_11 , L_4 ,
V_32 , & V_33 ,
V_34 ,
F_13 ( V_34 ) ) ;
if ( V_16 )
return V_16 ;
F_14 ( V_17 , & V_33 , V_32 ) ;
}
return 0 ;
}
static int F_15 ( struct V_5 * V_6 )
{
struct V_35 * V_36 = & V_6 -> V_11 -> V_36 ;
return F_16 ( V_36 , V_37 ,
F_13 ( V_37 ) ) ;
}
static int F_17 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = V_39 -> V_42 . V_43 ;
struct V_10 * V_11 = & V_44 ;
struct V_40 * V_45 ;
struct V_12 * V_13 ;
int V_46 = 0 ;
int V_16 = 0 ;
if ( ! V_41 ) {
F_18 ( & V_39 -> V_42 , L_5 ) ;
return - V_47 ;
}
V_11 -> V_42 = & V_39 -> V_42 ;
V_13 = F_19 ( & V_39 -> V_42 , sizeof( struct V_12 ) , V_48 ) ;
if ( V_13 == NULL )
return - V_49 ;
if ( F_20 ( V_11 , L_6 ) ) {
F_18 ( & V_39 -> V_42 , L_7 ) ;
return - V_47 ;
}
V_16 = F_21 ( V_11 , L_8 ) ;
if ( V_16 ) {
F_18 ( & V_39 -> V_42 , L_9 ) ;
return V_16 ;
}
V_45 = F_22 ( V_41 , L_10 , 0 ) ;
if ( ! V_45 ) {
F_18 ( & V_39 -> V_42 , L_11 ) ;
return - V_21 ;
}
V_50 [ 0 ] . V_51 = V_45 ;
V_50 [ 0 ] . V_52 = V_45 ;
V_45 = F_22 ( V_41 , L_12 , 0 ) ;
if ( V_45 ) {
V_46 = 2 ;
V_50 [ 1 ] . V_51 = V_45 ;
V_50 [ 1 ] . V_52 = V_45 ;
} else {
V_46 = 1 ;
}
V_13 -> V_31 = F_23 ( V_41 , L_13 ) ;
F_24 ( V_41 , L_14 , & V_13 -> V_19 ) ;
if ( ! V_13 -> V_19 ) {
F_18 ( & V_39 -> V_42 , L_15 ) ;
return - V_21 ;
}
V_11 -> V_53 = 1 ;
if ( ! V_13 -> V_19 ) {
F_18 ( & V_39 -> V_42 , L_16 ) ;
return - V_47 ;
}
V_11 -> V_54 = V_50 ;
V_11 -> V_46 = V_46 ;
F_25 ( V_11 , V_13 ) ;
V_16 = F_26 ( V_11 ) ;
if ( V_16 )
F_18 ( & V_39 -> V_42 , L_17 ,
V_16 ) ;
return V_16 ;
}
static int F_27 ( struct V_38 * V_39 )
{
struct V_10 * V_11 = F_28 ( V_39 ) ;
F_29 ( V_11 ) ;
return 0 ;
}
static int T_1 F_30 ( void )
{
int V_16 ;
V_55 = F_31 ( L_18 , - 1 , NULL ,
0 ) ;
if ( F_32 ( V_55 ) ) {
F_33 ( L_19 , V_56 ) ;
return F_34 ( V_55 ) ;
}
V_16 = F_35 ( & V_57 ) ;
if ( V_16 ) {
F_33 ( L_20 , V_56 ) ;
F_36 ( V_55 ) ;
}
return V_16 ;
}
static void T_2 F_37 ( void )
{
F_38 ( & V_57 ) ;
F_36 ( V_55 ) ;
}
