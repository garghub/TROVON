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
if ( V_4 -> V_5 . integer . V_5 [ 0 ] == V_6 )
return 0 ;
if ( V_4 -> V_5 . integer . V_5 [ 0 ] ) {
F_4 ( L_1 ) ;
F_5 ( & V_8 -> V_9 , L_2 ) ;
F_6 ( & V_8 -> V_9 , L_3 ) ;
} else {
F_4 ( L_4 ) ;
F_6 ( & V_8 -> V_9 , L_2 ) ;
F_5 ( & V_8 -> V_9 , L_3 ) ;
}
F_7 ( & V_8 -> V_9 ) ;
V_6 = V_4 -> V_5 . integer . V_5 [ 0 ] ;
return 0 ;
}
static void F_8 ( struct V_7 * V_8 )
{
F_5 ( & V_8 -> V_9 , L_5 ) ;
F_5 ( & V_8 -> V_9 , L_6 ) ;
F_5 ( & V_8 -> V_9 , L_7 ) ;
F_5 ( & V_8 -> V_9 , L_8 ) ;
F_5 ( & V_8 -> V_9 , L_9 ) ;
F_5 ( & V_8 -> V_9 , L_10 ) ;
if ( V_6 ) {
F_5 ( & V_8 -> V_9 , L_2 ) ;
F_6 ( & V_8 -> V_9 , L_3 ) ;
} else {
F_6 ( & V_8 -> V_9 , L_2 ) ;
F_5 ( & V_8 -> V_9 , L_3 ) ;
}
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 . integer . V_5 [ 0 ] = V_10 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_4 -> V_5 . integer . V_5 [ 0 ] == V_10 )
return 0 ;
F_8 ( V_8 ) ;
switch ( V_4 -> V_5 . integer . V_5 [ 0 ] ) {
case 0 :
F_4 ( L_11 ) ;
F_6 ( & V_8 -> V_9 , L_9 ) ;
F_6 ( & V_8 -> V_9 , L_10 ) ;
F_11 ( V_8 , V_11 , 0x66 , 0 ) ;
break;
case 1 :
F_4 ( L_12 ) ;
F_6 ( & V_8 -> V_9 , L_2 ) ;
F_6 ( & V_8 -> V_9 , L_3 ) ;
F_11 ( V_8 , V_11 , 0x66 , 0x22 ) ;
break;
case 2 :
F_4 ( L_13 ) ;
F_6 ( & V_8 -> V_9 , L_5 ) ;
F_6 ( & V_8 -> V_9 , L_6 ) ;
F_11 ( V_8 , V_11 , 0x66 , 0x44 ) ;
break;
case 3 :
F_4 ( L_14 ) ;
F_6 ( & V_8 -> V_9 , L_7 ) ;
F_6 ( & V_8 -> V_9 , L_8 ) ;
F_11 ( V_8 , V_11 , 0x66 , 0x66 ) ;
break;
}
F_7 ( & V_8 -> V_9 ) ;
V_10 = V_4 -> V_5 . integer . V_5 [ 0 ] ;
return 0 ;
}
static void F_12 ( unsigned int V_12 )
{
struct V_13 V_14 ;
V_14 . V_15 = & V_15 ;
V_14 . V_16 = V_12 ;
F_13 ( & V_14 ) ;
}
static int F_14 ( struct V_17 * V_18 )
{
struct V_7 * V_8 = V_18 -> V_8 ;
struct V_19 * V_9 = & V_8 -> V_9 ;
int V_20 ;
F_15 ( V_9 , V_21 , F_16 ( V_21 ) ) ;
F_17 ( V_9 , V_22 , F_16 ( V_22 ) ) ;
F_5 ( V_9 , L_2 ) ;
F_5 ( V_9 , L_15 ) ;
V_20 = F_18 ( V_8 , V_23 ,
F_16 ( V_23 ) ) ;
if ( V_20 ) {
F_19 ( L_16 , V_20 ) ;
return V_20 ;
}
F_6 ( V_9 , L_2 ) ;
F_6 ( V_9 , L_7 ) ;
F_6 ( V_9 , L_8 ) ;
V_10 = 3 ;
V_6 = 0 ;
F_6 ( V_9 , L_17 ) ;
F_6 ( V_9 , L_18 ) ;
V_20 = F_20 ( V_8 , L_19 ,
V_24 | V_25 |
V_26 , & V_15 ) ;
if ( V_20 ) {
F_19 ( L_20 ) ;
return V_20 ;
}
V_20 = F_21 ( & V_15 ,
F_16 ( V_27 ) , V_27 ) ;
if ( V_20 ) {
F_19 ( L_21 ) ;
return V_20 ;
}
V_20 = F_22 ( & V_15 ,
F_16 ( V_28 ) , V_28 ) ;
if ( V_20 ) {
F_19 ( L_22 ) ;
return V_20 ;
}
F_12 ( V_29 ) ;
return V_20 ;
}
static T_1 F_23 ( int V_30 , void * V_31 )
{
struct V_32 * V_33 = (struct V_32 * ) V_31 ;
F_24 ( & V_33 -> V_34 ,
( ( void * ) ( V_33 -> V_35 ) ) ,
sizeof( V_36 ) ) ;
return V_37 ;
}
static T_1 F_25 ( int V_30 , void * V_38 )
{
struct V_32 * V_39 = (struct V_32 * ) V_38 ;
if ( V_15 . V_8 == NULL )
return V_40 ;
F_12 ( V_39 -> V_34 ) ;
return V_40 ;
}
static int F_26 ( struct V_41 * V_42 )
{
int V_20 = 0 , V_30 ;
struct V_32 * V_39 ;
struct V_43 * V_44 ;
F_4 ( L_23 ) ;
V_30 = F_27 ( V_42 , 0 ) ;
V_39 = F_28 ( & V_42 -> V_31 , sizeof( * V_39 ) , V_45 ) ;
if ( ! V_39 ) {
F_19 ( L_24 ) ;
return - V_46 ;
}
V_44 = F_29 (
V_42 , V_47 , L_25 ) ;
if ( ! V_44 ) {
F_19 ( L_26 ) ;
return - V_48 ;
}
V_39 -> V_35 = F_30 ( & V_42 -> V_31 , V_44 -> V_49 ,
F_31 ( V_44 ) ) ;
if ( ! V_39 -> V_35 ) {
F_19 ( L_27 ) ;
return - V_46 ;
}
V_20 = F_32 ( & V_42 -> V_31 , V_30 ,
F_23 ,
F_25 ,
V_50 , V_42 -> V_31 . V_51 -> V_52 , V_39 ) ;
if ( V_20 ) {
F_19 ( L_28 ) ;
return V_20 ;
}
V_53 . V_31 = & V_42 -> V_31 ;
V_20 = F_33 ( & V_53 ) ;
if ( V_20 ) {
F_4 ( L_29 , V_20 ) ;
return V_20 ;
}
F_34 ( V_42 , V_39 ) ;
F_4 ( L_30 ) ;
return 0 ;
}
static int F_35 ( struct V_41 * V_42 )
{
F_4 ( L_31 ) ;
F_36 ( & V_53 ) ;
return 0 ;
}
