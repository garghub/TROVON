static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , int V_5 )
{
int V_6 ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_12 V_13 [] = {
{
. V_14 = V_8 -> V_14 ,
. V_15 = 0 ,
. V_4 = & V_3 ,
. V_5 = 1
} , {
. V_14 = V_8 -> V_14 ,
. V_15 = V_16 ,
. V_4 = V_4 ,
. V_5 = V_5
}
} ;
V_6 = F_2 ( V_10 , V_13 , 2 ) ;
if ( V_6 != 2 ) {
F_3 ( & V_8 -> V_17 , L_1 ,
V_3 , V_6 ) ;
if ( V_6 < 0 )
return V_6 ;
else
return - V_18 ;
}
F_4 ( & V_2 -> V_8 -> V_17 , L_2 ,
V_8 -> V_14 , V_3 , V_4 [ 0 ] ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , int V_5 )
{
int V_6 ;
T_1 V_19 [ 35 ] ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_12 V_13 = {
. V_14 = V_8 -> V_14 ,
. V_15 = 0 ,
. V_4 = & V_19 [ 0 ] ,
. V_5 = V_5 + 1
} ;
if ( ( V_5 + 1 ) > sizeof( V_19 ) ) {
F_3 ( & V_8 -> V_17 , L_3 ,
V_3 , V_5 ) ;
return - V_20 ;
}
V_19 [ 0 ] = V_3 ;
memcpy ( & V_19 [ 1 ] , V_4 , V_5 ) ;
V_6 = F_2 ( V_10 , & V_13 , 1 ) ;
if ( V_6 != 1 ) {
F_3 ( & V_8 -> V_17 , L_4 ,
V_3 , V_6 ) ;
if ( V_6 < 0 )
return V_6 ;
else
return - V_18 ;
}
F_4 ( & V_2 -> V_8 -> V_17 , L_5 ,
V_8 -> V_14 , V_3 , V_5 , V_4 ) ;
return 0 ;
}
static int F_6 ( struct V_21 * V_22 , int V_23 , T_1 V_24 ,
T_1 V_25 , int V_14 , T_1 V_26 )
{
struct V_1 * V_2 = V_22 -> V_26 ;
T_1 V_27 ;
int V_28 , V_6 ;
int (* F_7)( void * , T_1 , int , T_1 , int * ) = V_2 -> V_29 ;
if ( V_23 != 0 )
return - V_20 ;
if ( V_2 -> V_30 != V_24 ) {
V_6 = F_1 ( V_2 , 0x00 , & V_27 , 1 ) ;
if ( V_6 )
return V_6 ;
V_27 &= ~ ( V_31 | V_32 ) ;
V_27 |= V_24 ;
V_6 = F_5 ( V_2 , 0x00 , & V_27 , 1 ) ;
if ( V_6 )
return V_6 ;
}
V_2 -> V_30 = V_24 ;
if ( F_7 ) {
V_6 = F_7 ( V_2 -> V_33 , V_25 , V_14 , V_26 , & V_28 ) ;
} else {
F_3 ( & V_2 -> V_8 -> V_17 , L_6 ) ;
return - V_20 ;
}
if ( V_6 )
return V_6 ;
F_4 ( & V_2 -> V_8 -> V_17 , L_7 ,
( V_25 ) ? L_8 : L_9 , V_23 , V_14 ,
( V_24 == V_34 ) ? L_10 : L_11 ,
( V_25 ) ? V_28 : V_26 ) ;
if ( V_25 )
return V_28 ;
else
return 0 ;
}
int F_8 ( struct V_21 * V_22 ,
int V_23 , int V_14 )
{
return F_6 ( V_22 , V_23 , V_34 ,
V_35 , V_14 , 0 ) ;
}
int F_9 ( struct V_21 * V_22 ,
int V_23 , int V_14 , T_1 V_26 )
{
return F_6 ( V_22 , V_23 , V_34 ,
V_36 , V_14 , V_26 ) ;
}
int F_10 ( struct V_21 * V_22 ,
int V_23 , T_1 V_14 )
{
return F_6 ( V_22 , V_23 , V_37 ,
V_35 , V_14 , 0 ) ;
}
int F_11 ( struct V_21 * V_22 ,
int V_23 , T_1 V_14 , T_1 V_26 )
{
return F_6 ( V_22 , V_23 , V_37 ,
V_36 , V_14 , V_26 ) ;
}
int F_12 ( struct V_21 * V_22 , int V_23 )
{
struct V_1 * V_2 = V_22 -> V_26 ;
T_1 V_4 ;
int V_6 ;
F_4 ( & V_2 -> V_8 -> V_17 , L_12 , V_23 ) ;
if ( V_23 != 0 )
return - V_20 ;
V_4 = V_38 ;
V_6 = F_5 ( V_2 , 0x00 , & V_4 , 1 ) ;
if ( V_6 )
return V_6 ;
F_13 ( 500 , 600 ) ;
V_4 = 0x00 ;
V_6 = F_5 ( V_2 , 0x00 , & V_4 , 1 ) ;
if ( V_6 )
return V_6 ;
F_14 ( 1000 ) ;
return 0 ;
}
int F_15 ( struct V_21 * V_22 , int V_23 )
{
struct V_1 * V_2 = V_22 -> V_26 ;
F_4 ( & V_2 -> V_8 -> V_17 , L_13 , V_23 ) ;
return 0 ;
}
int F_16 ( struct V_21 * V_22 , int V_23 )
{
struct V_1 * V_2 = V_22 -> V_26 ;
T_1 V_4 ;
F_4 ( & V_2 -> V_8 -> V_17 , L_13 , V_23 ) ;
if ( V_23 != 0 )
return - V_20 ;
F_1 ( V_2 , 0x00 , & V_4 , 1 ) ;
V_4 |= ( V_39 | V_40 ) ;
return F_5 ( V_2 , 0 , & V_4 , 1 ) ;
}
int F_17 ( struct V_21 * V_22 ,
int V_23 , int V_41 )
{
struct V_1 * V_2 = V_22 -> V_26 ;
T_1 V_4 [ 2 ] ;
int V_6 ;
F_4 ( & V_2 -> V_8 -> V_17 , L_14 , V_23 , V_41 ) ;
if ( F_18 ( V_42 , V_2 -> V_43 ) ) {
V_6 = F_1 ( V_2 , 0x00 , V_4 , 1 ) ;
V_2 -> V_43 = V_42 + F_19 ( 1000 ) ;
if ( V_6 )
return 0 ;
if ( V_4 [ 0 ] & V_44 )
V_2 -> V_45 = V_46 |
V_47 ;
else
V_2 -> V_45 = 0 ;
}
return V_2 -> V_45 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
T_1 V_4 ;
T_1 V_48 [ 34 ] = {
0x00 ,
0x00 ,
0x00 ,
0x00 ,
0x00 ,
0x44 ,
0x00 ,
0x00 ,
0x00 ,
0x00 ,
0x00 ,
0x00 ,
0x00 ,
0x00 ,
0x44 ,
0x00 ,
0x00 ,
0x00 ,
0x00 ,
0x00 ,
0x00 ,
0x00 ,
0x00 ,
0x02 ,
0x01 ,
0x00 ,
0x00 ,
0x00 ,
0x05 ,
0x00 ,
0x04 ,
0x00 ,
0x22 ,
0x00 ,
} ;
F_4 ( & V_2 -> V_8 -> V_17 , L_15 ) ;
V_2 -> V_49 . V_50 = V_51 ;
V_2 -> V_49 . V_52 = F_8 ;
V_2 -> V_49 . V_53 = F_9 ;
V_2 -> V_49 . V_54 = F_10 ;
V_2 -> V_49 . V_55 = F_11 ;
V_2 -> V_49 . V_56 = F_12 ;
V_2 -> V_49 . V_57 = F_15 ;
V_2 -> V_49 . V_58 = F_16 ;
V_2 -> V_49 . V_59 = F_17 ;
V_2 -> V_49 . V_26 = V_2 ;
V_2 -> V_30 = 0 ;
V_6 = F_5 ( V_2 , 0x00 , & V_48 [ 0 ] , 34 ) ;
if ( V_6 )
goto V_60;
V_4 = 1 ;
V_6 = F_5 ( V_2 , 0x1f , & V_4 , 1 ) ;
if ( V_6 )
goto V_60;
V_6 = F_5 ( V_2 , 0x18 , & V_4 , 1 ) ;
if ( V_6 )
goto V_60;
V_6 = F_21 ( V_2 -> V_61 , & V_2 -> V_49 , 0 , 1 ) ;
if ( V_6 )
goto V_60;
return 0 ;
V_60:
F_4 ( & V_2 -> V_8 -> V_17 , L_16 , V_6 ) ;
return V_6 ;
}
static int F_22 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
F_4 ( & V_8 -> V_17 , L_15 ) ;
if ( V_8 == NULL )
return 0 ;
V_2 = F_23 ( V_8 ) ;
if ( V_2 == NULL )
return 0 ;
if ( V_2 -> V_49 . V_26 == NULL )
return 0 ;
F_24 ( & V_2 -> V_49 ) ;
return 0 ;
}
static int F_25 ( struct V_7 * V_8 ,
const struct V_62 * V_63 )
{
struct V_64 * V_65 = V_8 -> V_17 . V_66 ;
struct V_1 * V_2 ;
int V_6 ;
F_4 ( & V_8 -> V_17 , L_15 ) ;
V_2 = F_26 ( sizeof( struct V_1 ) , V_67 ) ;
if ( ! V_2 ) {
V_6 = - V_68 ;
F_3 ( & V_8 -> V_17 , L_17 ) ;
goto V_60;
}
V_2 -> V_8 = V_8 ;
V_2 -> V_61 = V_65 -> V_61 ;
V_2 -> V_33 = V_65 -> V_33 ;
V_2 -> V_29 = V_65 -> V_29 ;
F_27 ( V_8 , V_2 ) ;
V_6 = F_20 ( V_2 ) ;
if ( V_6 )
goto V_60;
F_28 ( & V_2 -> V_8 -> V_17 , L_18 ) ;
return 0 ;
V_60:
F_4 ( & V_8 -> V_17 , L_16 , V_6 ) ;
F_29 ( V_2 ) ;
return V_6 ;
}
static int F_30 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_23 ( V_8 ) ;
F_4 ( & V_8 -> V_17 , L_15 ) ;
F_22 ( V_8 ) ;
if ( V_2 != NULL )
F_29 ( V_2 ) ;
return 0 ;
}
