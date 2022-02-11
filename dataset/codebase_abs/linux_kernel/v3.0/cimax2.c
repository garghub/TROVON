int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_1 * V_5 , int V_6 )
{
int V_7 ;
struct V_8 V_9 [] = {
{
. V_3 = V_3 ,
. V_10 = 0 ,
. V_5 = & V_4 ,
. V_6 = 1
} , {
. V_3 = V_3 ,
. V_10 = V_11 ,
. V_5 = V_5 ,
. V_6 = V_6
}
} ;
V_7 = F_2 ( V_2 , V_9 , 2 ) ;
if ( V_7 != 2 ) {
F_3 ( L_1 ,
V_12 , V_4 , V_7 ) ;
return - 1 ;
}
F_3 ( L_2 ,
V_12 , V_3 , V_4 , V_5 [ 0 ] ) ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_1 * V_5 , int V_6 )
{
int V_7 ;
T_1 V_13 [ V_6 + 1 ] ;
struct V_8 V_9 = {
. V_3 = V_3 ,
. V_10 = 0 ,
. V_5 = & V_13 [ 0 ] ,
. V_6 = V_6 + 1
} ;
V_13 [ 0 ] = V_4 ;
memcpy ( & V_13 [ 1 ] , V_5 , V_6 ) ;
V_7 = F_2 ( V_2 , & V_9 , 1 ) ;
if ( V_7 != 1 ) {
F_3 ( L_3 ,
V_12 , V_4 , V_7 ) ;
return - 1 ;
}
return 0 ;
}
int F_5 ( struct V_14 * V_15 )
{
int V_16 ;
unsigned long V_17 = V_18 + F_6 ( 1 ) ;
for (; ; ) {
V_16 = F_7 ( V_19 ) ;
if ( ( V_16 & V_20 ) == 0 )
break;
if ( F_8 ( V_18 , V_17 ) )
break;
F_9 ( 1 ) ;
}
F_10 ( V_19 , V_21 ) ;
return V_16 & 0xff ;
}
int F_11 ( struct V_22 * V_23 , int V_24 ,
T_1 V_25 , T_1 V_26 , int V_3 , T_1 V_27 )
{
struct V_28 * V_29 = V_23 -> V_27 ;
struct V_30 * V_31 = V_29 -> V_32 ;
struct V_14 * V_15 = V_31 -> V_15 ;
T_1 V_33 ;
int V_16 ;
int V_7 ;
if ( 0 != V_24 )
return - V_34 ;
if ( V_29 -> V_35 != V_25 ) {
V_7 = F_1 ( V_29 -> V_2 , V_29 -> V_36 ,
0 , & V_33 , 1 ) ;
if ( V_7 != 0 )
return V_7 ;
V_33 &= ~ 0x0c ;
V_33 |= V_25 ;
V_7 = F_4 ( V_29 -> V_2 , V_29 -> V_36 ,
0 , & V_33 , 1 ) ;
if ( V_7 != 0 )
return V_7 ;
} ;
V_29 -> V_35 = V_25 ;
F_12 ( & V_15 -> V_37 ) ;
F_13 ( V_38 , V_39 ) ;
F_13 ( V_19 , V_21 |
V_40 | ( 0xff & V_3 ) ) ;
F_14 ( V_19 , V_40 ) ;
F_13 ( V_19 , V_21 |
V_41 | ( 0xff & ( V_3 >> 8 ) ) ) ;
F_14 ( V_19 , V_41 ) ;
if ( V_26 ) {
F_13 ( V_38 , V_39 | V_42 ) ;
} else
F_13 ( V_19 , V_21 | V_27 ) ;
F_14 ( V_19 ,
( V_29 -> V_36 == 0x40 ) ? V_43 : V_44 ) ;
F_14 ( V_19 , ( V_26 ) ? V_45 : V_46 ) ;
V_16 = F_5 ( V_15 ) ;
F_15 ( & V_15 -> V_37 ) ;
if ( ! V_26 )
if ( V_16 < 0 )
return - V_47 ;
F_3 ( L_4 , V_12 ,
( V_26 ) ? L_5 : L_6 , V_29 -> V_36 , V_3 ,
( V_25 == V_48 ) ? L_7 : L_8 ,
( V_26 ) ? V_16 : V_27 ) ;
if ( V_26 )
return V_16 ;
return 0 ;
}
int F_16 ( struct V_22 * V_23 ,
int V_24 , int V_3 )
{
return F_11 ( V_23 , V_24 , 0 , V_49 , V_3 , 0 ) ;
}
int F_17 ( struct V_22 * V_23 ,
int V_24 , int V_3 , T_1 V_27 )
{
return F_11 ( V_23 , V_24 , 0 , 0 , V_3 , V_27 ) ;
}
int F_18 ( struct V_22 * V_23 , int V_24 , T_1 V_3 )
{
return F_11 ( V_23 , V_24 , V_48 ,
V_49 , V_3 , 0 ) ;
}
int F_19 ( struct V_22 * V_23 , int V_24 ,
T_1 V_3 , T_1 V_27 )
{
return F_11 ( V_23 , V_24 , V_48 , 0 , V_3 , V_27 ) ;
}
int F_20 ( struct V_22 * V_23 , int V_24 )
{
struct V_28 * V_29 = V_23 -> V_27 ;
T_1 V_5 = 0x80 ;
int V_7 ;
if ( 0 != V_24 )
return - V_34 ;
F_9 ( 500 ) ;
V_7 = F_4 ( V_29 -> V_2 , V_29 -> V_36 ,
0 , & V_5 , 1 ) ;
if ( V_7 != 0 )
return V_7 ;
F_9 ( 500 ) ;
V_5 = 0x00 ;
V_7 = F_4 ( V_29 -> V_2 , V_29 -> V_36 ,
0 , & V_5 , 1 ) ;
F_21 ( 1000 ) ;
F_22 ( & V_29 -> V_50 , 0 ) ;
return 0 ;
}
int F_23 ( struct V_22 * V_23 , int V_24 )
{
return 0 ;
}
int F_24 ( struct V_22 * V_23 , T_1 V_51 )
{
struct V_28 * V_29 = V_23 -> V_27 ;
int V_7 ;
if ( V_51 == V_29 -> V_52 )
return 0 ;
F_3 ( L_9 ,
V_12 , V_29 -> V_36 , V_51 ) ;
V_7 = F_4 ( V_29 -> V_2 , V_29 -> V_36 ,
0x1b , & V_51 , 1 ) ;
if ( V_7 != 0 )
return V_7 ;
V_29 -> V_52 = V_51 ;
return 0 ;
}
int F_25 ( struct V_22 * V_23 , int V_24 )
{
struct V_28 * V_29 = V_23 -> V_27 ;
T_1 V_5 ;
if ( 0 != V_24 )
return - V_34 ;
F_1 ( V_29 -> V_2 , V_29 -> V_36 ,
0 , & V_5 , 1 ) ;
V_5 |= 0x60 ;
return F_4 ( V_29 -> V_2 , V_29 -> V_36 ,
0 , & V_5 , 1 ) ;
}
static void F_26 ( struct V_53 * V_54 )
{
struct V_28 * V_29 =
F_27 ( V_54 , struct V_28 , V_54 ) ;
T_1 V_5 [ 33 ] ;
int V_7 ;
F_28 ( & V_29 -> V_50 , 0 ) ;
if ( F_8 ( V_18 , V_29 -> V_55 )
|| ! V_29 -> V_56 ) {
V_7 = F_1 ( V_29 -> V_2 , V_29 -> V_36 ,
0 , & V_5 [ 0 ] , 33 ) ;
V_29 -> V_55 = V_18
+ F_6 ( 1000 ) ;
if ( V_7 != 0 )
return;
F_3 ( L_10
L_11
L_12 , V_12 ,
V_29 -> V_36 , 0 , V_5 [ 0 ] ,
V_5 [ 0 ] ) ;
if ( V_5 [ 0 ] & 1 )
V_29 -> V_56 = V_57 |
V_58 ;
else
V_29 -> V_56 = 0 ;
}
}
int F_29 ( struct V_14 * V_15 , T_2 V_59 )
{
struct V_30 * V_31 = NULL ;
struct V_28 * V_29 = NULL ;
F_3 ( L_13 , V_12 ) ;
if ( 0 == ( V_59 & ( V_60 | V_61 ) ) )
return 0 ;
if ( V_59 & V_60 ) {
V_31 = & V_15 -> V_62 ;
V_29 = V_31 -> V_63 ;
F_30 ( & V_29 -> V_54 ) ;
F_3 ( L_14 , V_12 ) ;
}
if ( V_59 & V_61 ) {
V_31 = & V_15 -> V_64 ;
V_29 = V_31 -> V_63 ;
F_30 ( & V_29 -> V_54 ) ;
F_3 ( L_15 , V_12 ) ;
}
return 1 ;
}
int F_31 ( struct V_22 * V_23 , int V_24 , int V_65 )
{
struct V_28 * V_29 = V_23 -> V_27 ;
if ( 0 != V_24 )
return - V_34 ;
F_24 ( V_23 , V_65 ? ( V_66 | F_32 () )
: V_66 ) ;
return V_29 -> V_56 ;
}
int F_33 ( struct V_30 * V_31 )
{
struct V_28 * V_29 ;
T_1 V_67 [ 34 ] = {
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
F_32 () | V_66 ,
0x05 ,
0x00 ,
0x04 ,
0x00 ,
0x33 ,
0x31 ,
} ;
int V_7 ;
F_3 ( L_16 , V_12 ) ;
V_29 = F_34 ( sizeof( struct V_28 ) , V_68 ) ;
if ( ! V_29 ) {
F_3 ( L_17 , V_12 ) ;
V_7 = - V_69 ;
goto V_70;
}
V_31 -> V_63 = V_29 ;
switch ( V_31 -> V_71 ) {
case 1 :
V_29 -> V_36 = 0x40 ;
break;
case 2 :
V_29 -> V_36 = 0x41 ;
break;
}
V_29 -> V_2 = & V_31 -> V_15 -> V_72 [ 0 ] . V_2 ;
V_29 -> V_50 . V_73 = V_74 ;
V_29 -> V_50 . V_75 = F_16 ;
V_29 -> V_50 . V_76 = F_17 ;
V_29 -> V_50 . V_77 = F_18 ;
V_29 -> V_50 . V_78 = F_19 ;
V_29 -> V_50 . V_79 = F_20 ;
V_29 -> V_50 . V_80 = F_23 ;
V_29 -> V_50 . V_81 = F_25 ;
V_29 -> V_50 . V_82 = F_31 ;
V_29 -> V_50 . V_27 = V_29 ;
V_29 -> V_32 = V_31 ;
V_29 -> V_52 = F_32 () | V_66 ;
V_7 = F_4 ( V_29 -> V_2 , V_29 -> V_36 ,
0 , & V_67 [ 0 ] , 34 ) ;
V_7 |= F_4 ( V_29 -> V_2 , V_29 -> V_36 ,
0x1f , & V_67 [ 0x18 ] , 1 ) ;
V_7 |= F_4 ( V_29 -> V_2 , V_29 -> V_36 ,
0x18 , & V_67 [ 0x18 ] , 1 ) ;
if ( 0 != V_7 )
goto V_70;
V_7 = F_35 ( & V_31 -> V_83 . V_84 ,
& V_29 -> V_50 ,
0 ,
1 ) ;
if ( 0 != V_7 )
goto V_70;
F_36 ( & V_29 -> V_54 , F_26 ) ;
F_30 ( & V_29 -> V_54 ) ;
F_3 ( L_18 , V_12 ) ;
return 0 ;
V_70:
F_3 ( L_19 , V_12 , V_7 ) ;
F_37 ( V_29 ) ;
return V_7 ;
}
void F_38 ( struct V_30 * V_31 )
{
struct V_28 * V_29 ;
if ( NULL == V_31 )
return;
V_29 = (struct V_28 * ) V_31 -> V_63 ;
if ( NULL == V_29 )
return;
if ( NULL == V_29 -> V_50 . V_27 )
return;
F_39 ( & V_29 -> V_50 ) ;
F_37 ( V_29 ) ;
}
