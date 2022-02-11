static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 . integer . V_5 [ 0 ] = V_6 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_9 * V_10 = & V_8 -> V_10 ;
if ( V_4 -> V_5 . integer . V_5 [ 0 ] == V_6 )
return 0 ;
F_4 ( V_10 ) ;
if ( V_4 -> V_5 . integer . V_5 [ 0 ] ) {
F_5 ( L_1 ) ;
F_6 ( V_10 , L_2 ) ;
F_7 ( V_10 , L_3 ) ;
} else {
F_5 ( L_4 ) ;
F_7 ( V_10 , L_2 ) ;
F_6 ( V_10 , L_3 ) ;
}
F_8 ( V_10 ) ;
F_9 ( V_10 ) ;
V_6 = V_4 -> V_5 . integer . V_5 [ 0 ] ;
return 0 ;
}
static void F_10 ( struct V_9 * V_10 )
{
F_6 ( V_10 , L_5 ) ;
F_6 ( V_10 , L_6 ) ;
F_6 ( V_10 , L_7 ) ;
F_6 ( V_10 , L_8 ) ;
F_6 ( V_10 , L_9 ) ;
F_6 ( V_10 , L_10 ) ;
if ( V_6 ) {
F_6 ( V_10 , L_2 ) ;
F_7 ( V_10 , L_3 ) ;
} else {
F_7 ( V_10 , L_2 ) ;
F_6 ( V_10 , L_3 ) ;
}
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 . integer . V_5 [ 0 ] = V_11 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_9 * V_10 = & V_8 -> V_10 ;
if ( V_4 -> V_5 . integer . V_5 [ 0 ] == V_11 )
return 0 ;
F_4 ( V_10 ) ;
F_10 ( V_10 ) ;
switch ( V_4 -> V_5 . integer . V_5 [ 0 ] ) {
case 0 :
F_5 ( L_11 ) ;
F_7 ( V_10 , L_9 ) ;
F_7 ( V_10 , L_10 ) ;
F_13 ( V_12 , V_13 , 0x66 , 0 ) ;
break;
case 1 :
F_5 ( L_12 ) ;
F_7 ( V_10 , L_2 ) ;
F_7 ( V_10 , L_3 ) ;
F_13 ( V_12 , V_13 , 0x66 , 0x22 ) ;
break;
case 2 :
F_5 ( L_13 ) ;
F_7 ( V_10 , L_5 ) ;
F_7 ( V_10 , L_6 ) ;
F_13 ( V_12 , V_13 , 0x66 , 0x44 ) ;
break;
case 3 :
F_5 ( L_14 ) ;
F_7 ( V_10 , L_7 ) ;
F_7 ( V_10 , L_8 ) ;
F_13 ( V_12 , V_13 , 0x66 , 0x66 ) ;
break;
}
F_8 ( V_10 ) ;
F_9 ( V_10 ) ;
V_11 = V_4 -> V_5 . integer . V_5 [ 0 ] ;
return 0 ;
}
static void F_14 ( unsigned int V_14 )
{
struct V_15 V_16 ;
if ( ! V_12 )
return;
V_16 . V_17 = & V_17 ;
V_16 . V_18 = V_14 ;
F_15 ( V_12 , & V_16 ) ;
}
static int F_16 ( struct V_19 * V_20 )
{
struct V_9 * V_10 = & V_20 -> V_8 -> V_10 ;
int V_21 ;
F_17 ( V_10 , L_2 ) ;
F_17 ( V_10 , L_7 ) ;
F_17 ( V_10 , L_8 ) ;
V_11 = 3 ;
V_6 = 0 ;
F_17 ( V_10 , L_15 ) ;
F_17 ( V_10 , L_16 ) ;
V_21 = F_18 ( V_20 -> V_8 ,
L_17 , V_22 |
V_23 | V_24 , & V_17 ,
V_25 , F_19 ( V_25 ) ) ;
if ( V_21 ) {
F_20 ( L_18 ) ;
return V_21 ;
}
V_21 = F_21 ( & V_17 ,
F_19 ( V_26 ) , V_26 ) ;
if ( V_21 ) {
F_20 ( L_19 ) ;
return V_21 ;
}
V_12 = V_20 -> V_27 ;
F_14 ( V_28 ) ;
return V_21 ;
}
static T_1 F_22 ( int V_29 , void * V_30 )
{
struct V_31 * V_32 = (struct V_31 * ) V_30 ;
F_23 ( & V_32 -> V_33 ,
( ( void * ) ( V_32 -> V_34 ) ) ,
sizeof( V_35 ) ) ;
return V_36 ;
}
static T_1 F_24 ( int V_29 , void * V_37 )
{
struct V_31 * V_38 = (struct V_31 * ) V_37 ;
F_14 ( V_38 -> V_33 ) ;
return V_39 ;
}
static int F_25 ( struct V_40 * V_41 )
{
int V_21 = 0 , V_29 ;
struct V_31 * V_38 ;
struct V_42 * V_43 ;
F_5 ( L_20 ) ;
V_29 = F_26 ( V_41 , 0 ) ;
V_38 = F_27 ( & V_41 -> V_30 , sizeof( * V_38 ) , V_44 ) ;
if ( ! V_38 ) {
F_20 ( L_21 ) ;
return - V_45 ;
}
V_43 = F_28 (
V_41 , V_46 , L_22 ) ;
if ( ! V_43 ) {
F_20 ( L_23 ) ;
return - V_47 ;
}
V_38 -> V_34 = F_29 ( & V_41 -> V_30 , V_43 -> V_48 ,
F_30 ( V_43 ) ) ;
if ( ! V_38 -> V_34 ) {
F_20 ( L_24 ) ;
return - V_45 ;
}
V_21 = F_31 ( & V_41 -> V_30 , V_29 ,
F_22 ,
F_24 ,
V_49 , V_41 -> V_30 . V_50 -> V_51 , V_38 ) ;
if ( V_21 ) {
F_20 ( L_25 ) ;
return V_21 ;
}
V_52 . V_30 = & V_41 -> V_30 ;
V_21 = F_32 ( & V_41 -> V_30 , & V_52 ) ;
if ( V_21 ) {
F_5 ( L_26 , V_21 ) ;
return V_21 ;
}
F_33 ( V_41 , V_38 ) ;
F_5 ( L_27 ) ;
return 0 ;
}
