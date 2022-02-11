static inline T_1 F_1 ( T_1 V_1 )
{
return ( V_1 >> V_2 ) & V_3 ;
}
static inline T_1 F_2 ( T_1 V_1 )
{
return ( V_1 >> V_4 ) & V_5 ;
}
static int F_3 ( struct V_6 * V_7 , char * V_8 ,
unsigned V_9 , T_2 V_10 )
{
T_1 V_11 [ 2 ] ;
struct V_12 V_13 [ 2 ] ;
struct V_14 V_15 ;
int V_16 ;
F_4 ( & V_15 ) ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
V_13 [ 0 ] . V_17 = V_11 ;
V_13 [ 0 ] . V_18 = sizeof( V_11 ) ;
F_5 ( & V_13 [ 0 ] , & V_15 ) ;
V_13 [ 1 ] . V_19 = V_8 ;
V_13 [ 1 ] . V_18 = V_10 ;
F_5 ( & V_13 [ 1 ] , & V_15 ) ;
V_11 [ 0 ] = V_20 ;
V_11 [ 1 ] = V_9 ;
F_6 ( & V_7 -> V_21 ) ;
V_16 = F_7 ( V_7 -> V_22 , & V_15 ) ;
F_8 ( & V_7 -> V_21 ) ;
return V_16 ? V_16 : V_10 ;
}
static int F_9 ( struct V_6 * V_7 , char * V_8 ,
unsigned V_9 , T_2 V_10 )
{
T_1 V_11 [ 2 ] ;
struct V_12 V_13 [ 2 ] ;
struct V_14 V_15 ;
int V_16 ;
F_4 ( & V_15 ) ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
V_13 [ 0 ] . V_17 = V_11 ;
V_13 [ 0 ] . V_18 = sizeof( V_11 ) ;
F_5 ( & V_13 [ 0 ] , & V_15 ) ;
V_13 [ 1 ] . V_17 = V_8 ;
V_13 [ 1 ] . V_18 = V_10 ;
F_5 ( & V_13 [ 1 ] , & V_15 ) ;
V_11 [ 0 ] = V_23 ;
V_11 [ 1 ] = V_9 ;
F_6 ( & V_7 -> V_21 ) ;
V_16 = F_7 ( V_7 -> V_22 , & V_15 ) ;
F_8 ( & V_7 -> V_21 ) ;
return V_16 ? V_16 : V_10 ;
}
static inline int F_10 ( struct V_6 * V_7 , T_1 V_24 , T_1 * V_8 )
{
return ( F_3 ( V_7 , V_8 , V_24 , 1 ) != 1 ) ;
}
static inline int F_11 ( struct V_6 * V_7 , T_1 V_24 , T_1 V_1 )
{
char V_8 = V_1 ;
return ( F_9 ( V_7 , & V_8 , V_24 , 1 ) != 1 ) ;
}
static int F_12 ( struct V_6 * V_7 )
{
return F_11 ( V_7 , V_25 , 0 ) ;
}
static int F_13 ( struct V_6 * V_7 )
{
return F_11 ( V_7 , V_25 , 1 ) ;
}
static int F_14 ( struct V_6 * V_7 )
{
int V_16 ;
V_16 = F_12 ( V_7 ) ;
if ( V_16 )
return V_16 ;
F_15 ( V_26 ) ;
return F_13 ( V_7 ) ;
}
static T_3 F_16 ( struct V_27 * V_28 , struct V_29 * V_30 ,
struct V_31 * V_32 , char * V_8 , T_4 V_33 , T_2 V_10 )
{
struct V_34 * V_35 ;
struct V_6 * V_36 ;
V_35 = F_17 ( V_30 , struct V_34 , V_30 ) ;
V_36 = F_18 ( V_35 ) ;
if ( F_19 ( V_33 > V_37 ) )
return 0 ;
if ( ( V_33 + V_10 ) > V_37 )
V_10 = V_37 - V_33 ;
if ( F_19 ( ! V_10 ) )
return V_10 ;
return F_3 ( V_36 , V_8 , V_33 , V_10 ) ;
}
static T_3 F_20 ( struct V_27 * V_28 , struct V_29 * V_30 ,
struct V_31 * V_32 , char * V_8 , T_4 V_33 , T_2 V_10 )
{
struct V_34 * V_35 ;
struct V_6 * V_36 ;
V_35 = F_17 ( V_30 , struct V_34 , V_30 ) ;
V_36 = F_18 ( V_35 ) ;
if ( F_19 ( V_33 >= V_37 ) )
return - V_38 ;
if ( ( V_33 + V_10 ) > V_37 )
V_10 = V_37 - V_33 ;
if ( F_19 ( ! V_10 ) )
return V_10 ;
return F_9 ( V_36 , V_8 , V_33 , V_10 ) ;
}
static int F_21 ( struct V_39 * V_22 )
{
struct V_6 * V_7 ;
struct V_40 * V_41 ;
T_1 V_42 [ 2 ] ;
int V_16 ;
V_41 = V_22 -> V_35 . V_43 ;
V_7 = F_22 ( sizeof( * V_7 ) , V_44 ) ;
if ( ! V_7 )
return - V_45 ;
F_23 ( & V_7 -> V_21 ) ;
V_7 -> V_41 = V_41 ;
V_7 -> V_22 = F_24 ( V_22 ) ;
F_25 ( V_22 , V_7 ) ;
V_22 -> V_46 = V_47 ;
V_22 -> V_48 = 8 ;
V_16 = F_26 ( V_22 ) ;
if ( V_16 ) {
F_27 ( & V_22 -> V_35 , L_1 , V_16 ) ;
goto V_49;
}
V_16 = F_3 ( V_7 , V_42 , V_50 , sizeof( V_42 ) ) ;
if ( V_16 < 0 ) {
F_27 ( & V_22 -> V_35 , L_2 ,
V_16 ) ;
goto V_49;
}
switch ( V_42 [ 0 ] ) {
case V_51 :
break;
default:
F_27 ( & V_22 -> V_35 , L_3 , V_42 [ 0 ] ) ;
V_16 = - V_52 ;
goto V_49;
}
V_16 = F_14 ( V_7 ) ;
if ( V_16 )
goto V_49;
V_16 = F_28 ( & V_22 -> V_35 . V_30 , & V_53 ) ;
if ( V_16 ) {
F_27 ( & V_22 -> V_35 , L_4 ,
V_16 ) ;
goto V_49;
}
F_29 ( & V_22 -> V_35 , L_5
L_6 , V_42 [ 0 ] ,
F_1 ( V_42 [ 1 ] ) , F_2 ( V_42 [ 1 ] ) ) ;
return 0 ;
V_49:
F_25 ( V_22 , NULL ) ;
F_30 ( V_7 ) ;
return V_16 ;
}
static int F_31 ( struct V_39 * V_22 )
{
struct V_54 * V_36 ;
V_36 = F_32 ( V_22 ) ;
F_33 ( & V_22 -> V_35 . V_30 , & V_53 ) ;
F_25 ( V_22 , NULL ) ;
F_30 ( V_36 ) ;
return 0 ;
}
static int T_5 F_34 ( void )
{
F_35 ( V_55 L_7 V_56 L_8 ) ;
return F_36 ( & V_57 ) ;
}
static void T_6 F_37 ( void )
{
F_38 ( & V_57 ) ;
}
