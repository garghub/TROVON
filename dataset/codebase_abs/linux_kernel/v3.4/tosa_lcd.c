static int F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
T_2 V_5 [ 1 ] ;
struct V_6 V_7 ;
struct V_8 V_9 = {
. V_10 = 1 ,
. V_11 = 1 ,
. V_12 = V_5 ,
} ;
V_5 [ 0 ] = ( ( V_3 & 0x07 ) << 5 ) | ( V_4 & 0x1f ) ;
F_2 ( & V_7 ) ;
F_3 ( & V_9 , & V_7 ) ;
return F_4 ( V_2 , & V_7 ) ;
}
int F_5 ( struct V_1 * V_2 , int V_13 )
{
return F_1 ( V_2 , V_14 , V_13 ? 0x01 : 0x00 ) ;
}
static void F_6 ( struct V_15 * V_4 )
{
F_7 ( V_16 , 0 ) ;
F_8 ( 60 ) ;
F_1 ( V_4 -> V_2 , V_17 , 0x00 ) ;
F_1 ( V_4 -> V_2 , V_18 , 0x02 ) ;
}
static void F_9 ( struct V_15 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_19 = V_20 | V_21 | V_22 ;
if ( V_4 -> V_23 )
V_19 |= V_24 ;
F_1 ( V_2 , V_25 , V_19 ) ;
F_1 ( V_2 , V_26 , 0x4 ) ;
F_8 ( 50 ) ;
F_1 ( V_2 , V_26 , 0x0 ) ;
if ( ! V_4 -> V_27 ) {
struct V_28 * V_29 = F_10 ( 0 ) ;
struct V_30 V_31 = {
. type = L_1 ,
. V_32 = V_33 ,
. V_34 = V_4 -> V_2 ,
} ;
V_4 -> V_27 = F_11 ( V_29 , & V_31 ) ;
}
}
static void F_12 ( struct V_15 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_1 ( V_2 , V_26 , 0x4 ) ;
F_8 ( 50 ) ;
F_1 ( V_2 , V_26 , 0x6 ) ;
F_8 ( 50 ) ;
F_7 ( V_16 , 1 ) ;
F_8 ( 100 ) ;
}
int F_13 ( struct V_35 * V_36 , int V_37 )
{
struct V_15 * V_4 = F_14 ( V_36 ) ;
if ( F_15 ( V_37 ) && ! F_15 ( V_4 -> V_38 ) )
F_9 ( V_4 ) ;
if ( ! F_15 ( V_37 ) && F_15 ( V_4 -> V_38 ) )
F_12 ( V_4 ) ;
V_4 -> V_38 = V_37 ;
return 0 ;
}
static int F_16 ( struct V_35 * V_36 )
{
struct V_15 * V_4 = F_14 ( V_36 ) ;
return V_4 -> V_38 ;
}
static int F_17 ( struct V_35 * V_36 , struct V_39 * V_40 )
{
struct V_15 * V_4 = F_14 ( V_36 ) ;
if ( V_40 -> V_41 == 320 || V_40 -> V_42 == 320 )
V_4 -> V_23 = false ;
else
V_4 -> V_23 = true ;
if ( F_15 ( V_4 -> V_38 ) )
F_9 ( V_4 ) ;
return 0 ;
}
static int T_3 F_18 ( struct V_1 * V_2 )
{
int V_43 ;
struct V_15 * V_4 ;
V_4 = F_19 ( sizeof( struct V_15 ) , V_44 ) ;
if ( ! V_4 )
return - V_45 ;
V_4 -> V_23 = true ;
V_2 -> V_46 = 8 ;
V_43 = F_20 ( V_2 ) ;
if ( V_43 < 0 )
goto V_47;
V_4 -> V_2 = V_2 ;
F_21 ( & V_2 -> V_48 , V_4 ) ;
V_43 = F_22 ( V_16 , L_2 ) ;
if ( V_43 < 0 )
goto V_49;
F_8 ( 60 ) ;
V_43 = F_23 ( V_16 , 0 ) ;
if ( V_43 < 0 )
goto V_50;
F_8 ( 60 ) ;
F_6 ( V_4 ) ;
F_9 ( V_4 ) ;
V_4 -> V_36 = F_24 ( L_3 , & V_2 -> V_48 , V_4 ,
& V_51 ) ;
if ( F_25 ( V_4 -> V_36 ) ) {
V_43 = F_26 ( V_4 -> V_36 ) ;
V_4 -> V_36 = NULL ;
goto V_52;
}
return 0 ;
V_52:
F_12 ( V_4 ) ;
V_50:
F_27 ( V_16 ) ;
V_49:
F_21 ( & V_2 -> V_48 , NULL ) ;
V_47:
F_28 ( V_4 ) ;
return V_43 ;
}
static int T_4 F_29 ( struct V_1 * V_2 )
{
struct V_15 * V_4 = F_30 ( & V_2 -> V_48 ) ;
F_31 ( V_4 -> V_36 ) ;
if ( V_4 -> V_27 )
F_32 ( V_4 -> V_27 ) ;
F_12 ( V_4 ) ;
F_27 ( V_16 ) ;
F_21 ( & V_2 -> V_48 , NULL ) ;
F_28 ( V_4 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , T_5 V_53 )
{
struct V_15 * V_4 = F_30 ( & V_2 -> V_48 ) ;
F_12 ( V_4 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_15 * V_4 = F_30 ( & V_2 -> V_48 ) ;
F_6 ( V_4 ) ;
if ( F_15 ( V_4 -> V_38 ) )
F_9 ( V_4 ) ;
else
F_12 ( V_4 ) ;
return 0 ;
}
