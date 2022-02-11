static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
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
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_1 * V_5 , int V_6 )
{
int V_7 ;
T_1 V_13 [ V_14 ] ;
struct V_8 V_9 = {
. V_3 = V_3 ,
. V_10 = 0 ,
. V_5 = & V_13 [ 0 ] ,
. V_6 = V_6 + 1
} ;
if ( 1 + V_6 > sizeof( V_13 ) ) {
F_5 ( V_15
L_3 ,
V_16 , V_4 , V_6 ) ;
return - V_17 ;
}
V_13 [ 0 ] = V_4 ;
memcpy ( & V_13 [ 1 ] , V_5 , V_6 ) ;
V_7 = F_2 ( V_2 , & V_9 , 1 ) ;
if ( V_7 != 1 ) {
F_3 ( L_4 ,
V_12 , V_4 , V_7 ) ;
return - 1 ;
}
return 0 ;
}
static int F_6 ( struct V_18 * V_19 )
{
int V_20 ;
unsigned long V_21 = V_22 + F_7 ( 1 ) ;
for (; ; ) {
V_20 = F_8 ( V_23 ) ;
if ( ( V_20 & V_24 ) == 0 )
break;
if ( F_9 ( V_22 , V_21 ) )
break;
F_10 ( 1 ) ;
}
F_11 ( V_23 , V_25 ) ;
return V_20 & 0xff ;
}
static int F_12 ( struct V_26 * V_27 , int V_28 ,
T_1 V_29 , T_1 V_30 , int V_3 , T_1 V_31 )
{
struct V_32 * V_33 = V_27 -> V_31 ;
struct V_34 * V_35 = V_33 -> V_36 ;
struct V_18 * V_19 = V_35 -> V_19 ;
T_1 V_37 ;
int V_20 ;
int V_7 ;
if ( 0 != V_28 )
return - V_17 ;
if ( V_33 -> V_38 != V_29 ) {
V_7 = F_1 ( V_33 -> V_2 , V_33 -> V_39 ,
0 , & V_37 , 1 ) ;
if ( V_7 != 0 )
return V_7 ;
V_37 &= ~ 0x0c ;
V_37 |= V_29 ;
V_7 = F_4 ( V_33 -> V_2 , V_33 -> V_39 ,
0 , & V_37 , 1 ) ;
if ( V_7 != 0 )
return V_7 ;
}
V_33 -> V_38 = V_29 ;
F_13 ( & V_19 -> V_40 ) ;
F_14 ( V_41 , V_42 ) ;
F_14 ( V_23 , V_25 |
V_43 | ( 0xff & V_3 ) ) ;
F_15 ( V_23 , V_43 ) ;
F_14 ( V_23 , V_25 |
V_44 | ( 0xff & ( V_3 >> 8 ) ) ) ;
F_15 ( V_23 , V_44 ) ;
if ( V_30 ) {
F_14 ( V_41 , V_42 | V_45 ) ;
} else
F_14 ( V_23 , V_25 | V_31 ) ;
F_15 ( V_23 ,
( V_33 -> V_39 == 0x40 ) ? V_46 : V_47 ) ;
F_15 ( V_23 , ( V_30 ) ? V_48 : V_49 ) ;
V_20 = F_6 ( V_19 ) ;
F_16 ( & V_19 -> V_40 ) ;
if ( ! V_30 )
if ( V_20 < 0 )
return - V_50 ;
F_3 ( L_5 , V_12 ,
( V_30 ) ? L_6 : L_7 , V_33 -> V_39 , V_3 ,
( V_29 == V_51 ) ? L_8 : L_9 ,
( V_30 ) ? V_20 : V_31 ) ;
if ( V_30 )
return V_20 ;
return 0 ;
}
int F_17 ( struct V_26 * V_27 ,
int V_28 , int V_3 )
{
return F_12 ( V_27 , V_28 , 0 , V_52 , V_3 , 0 ) ;
}
int F_18 ( struct V_26 * V_27 ,
int V_28 , int V_3 , T_1 V_31 )
{
return F_12 ( V_27 , V_28 , 0 , 0 , V_3 , V_31 ) ;
}
int F_19 ( struct V_26 * V_27 , int V_28 ,
T_1 V_3 )
{
return F_12 ( V_27 , V_28 , V_51 ,
V_52 , V_3 , 0 ) ;
}
int F_20 ( struct V_26 * V_27 , int V_28 ,
T_1 V_3 , T_1 V_31 )
{
return F_12 ( V_27 , V_28 , V_51 , 0 , V_3 , V_31 ) ;
}
int F_21 ( struct V_26 * V_27 , int V_28 )
{
struct V_32 * V_33 = V_27 -> V_31 ;
T_1 V_5 = 0x80 ;
int V_7 ;
if ( 0 != V_28 )
return - V_17 ;
F_10 ( 500 ) ;
V_7 = F_4 ( V_33 -> V_2 , V_33 -> V_39 ,
0 , & V_5 , 1 ) ;
if ( V_7 != 0 )
return V_7 ;
F_10 ( 500 ) ;
V_5 = 0x00 ;
V_7 = F_4 ( V_33 -> V_2 , V_33 -> V_39 ,
0 , & V_5 , 1 ) ;
F_22 ( 1000 ) ;
F_23 ( & V_33 -> V_53 , 0 ) ;
return 0 ;
}
int F_24 ( struct V_26 * V_27 , int V_28 )
{
return 0 ;
}
static int F_25 ( struct V_26 * V_27 , T_1 V_54 )
{
struct V_32 * V_33 = V_27 -> V_31 ;
int V_7 ;
if ( V_54 == V_33 -> V_55 )
return 0 ;
F_3 ( L_10 ,
V_12 , V_33 -> V_39 , V_54 ) ;
V_7 = F_4 ( V_33 -> V_2 , V_33 -> V_39 ,
0x1b , & V_54 , 1 ) ;
if ( V_7 != 0 )
return V_7 ;
V_33 -> V_55 = V_54 ;
return 0 ;
}
int F_26 ( struct V_26 * V_27 , int V_28 )
{
struct V_32 * V_33 = V_27 -> V_31 ;
T_1 V_5 ;
if ( 0 != V_28 )
return - V_17 ;
F_1 ( V_33 -> V_2 , V_33 -> V_39 ,
0 , & V_5 , 1 ) ;
V_5 |= 0x60 ;
return F_4 ( V_33 -> V_2 , V_33 -> V_39 ,
0 , & V_5 , 1 ) ;
}
static void F_27 ( struct V_56 * V_57 )
{
struct V_32 * V_33 =
F_28 ( V_57 , struct V_32 , V_57 ) ;
T_1 V_5 [ 33 ] ;
int V_7 ;
F_29 ( & V_33 -> V_53 , 0 ) ;
if ( F_9 ( V_22 , V_33 -> V_58 )
|| ! V_33 -> V_59 ) {
V_7 = F_1 ( V_33 -> V_2 , V_33 -> V_39 ,
0 , & V_5 [ 0 ] , 33 ) ;
V_33 -> V_58 = V_22
+ F_7 ( 1000 ) ;
if ( V_7 != 0 )
return;
F_3 ( L_11
L_12
L_13 , V_12 ,
V_33 -> V_39 , 0 , V_5 [ 0 ] ,
V_5 [ 0 ] ) ;
if ( V_5 [ 0 ] & 1 )
V_33 -> V_59 = V_60 |
V_61 ;
else
V_33 -> V_59 = 0 ;
}
}
int F_30 ( struct V_18 * V_19 , T_2 V_62 )
{
struct V_34 * V_35 = NULL ;
struct V_32 * V_33 = NULL ;
F_3 ( L_14 , V_12 ) ;
if ( 0 == ( V_62 & ( V_63 | V_64 ) ) )
return 0 ;
if ( V_62 & V_63 ) {
V_35 = & V_19 -> V_65 ;
V_33 = V_35 -> V_66 ;
F_31 ( & V_33 -> V_57 ) ;
F_3 ( L_15 , V_12 ) ;
}
if ( V_62 & V_64 ) {
V_35 = & V_19 -> V_67 ;
V_33 = V_35 -> V_66 ;
F_31 ( & V_33 -> V_57 ) ;
F_3 ( L_16 , V_12 ) ;
}
return 1 ;
}
int F_32 ( struct V_26 * V_27 ,
int V_28 , int V_68 )
{
struct V_32 * V_33 = V_27 -> V_31 ;
if ( 0 != V_28 )
return - V_17 ;
F_25 ( V_27 , V_68 ? ( V_69 | F_33 () )
: V_69 ) ;
return V_33 -> V_59 ;
}
int F_34 ( struct V_34 * V_35 )
{
struct V_32 * V_33 ;
T_1 V_70 [ 34 ] = {
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
F_33 () | V_69 ,
0x05 ,
0x00 ,
0x04 ,
0x00 ,
0x33 ,
0x31 ,
} ;
int V_7 ;
F_3 ( L_17 , V_12 ) ;
V_33 = F_35 ( sizeof( struct V_32 ) , V_71 ) ;
if ( ! V_33 ) {
F_3 ( L_18 , V_12 ) ;
V_7 = - V_72 ;
goto V_73;
}
V_35 -> V_66 = V_33 ;
switch ( V_35 -> V_74 ) {
case 1 :
V_33 -> V_39 = 0x40 ;
break;
case 2 :
V_33 -> V_39 = 0x41 ;
break;
}
V_33 -> V_2 = & V_35 -> V_19 -> V_75 [ 0 ] . V_2 ;
V_33 -> V_53 . V_76 = V_77 ;
V_33 -> V_53 . V_78 = F_17 ;
V_33 -> V_53 . V_79 = F_18 ;
V_33 -> V_53 . V_80 = F_19 ;
V_33 -> V_53 . V_81 = F_20 ;
V_33 -> V_53 . V_82 = F_21 ;
V_33 -> V_53 . V_83 = F_24 ;
V_33 -> V_53 . V_84 = F_26 ;
V_33 -> V_53 . V_85 = F_32 ;
V_33 -> V_53 . V_31 = V_33 ;
V_33 -> V_36 = V_35 ;
V_33 -> V_55 = F_33 () | V_69 ;
V_7 = F_4 ( V_33 -> V_2 , V_33 -> V_39 ,
0 , & V_70 [ 0 ] , 34 ) ;
V_7 |= F_4 ( V_33 -> V_2 , V_33 -> V_39 ,
0x1f , & V_70 [ 0x18 ] , 1 ) ;
V_7 |= F_4 ( V_33 -> V_2 , V_33 -> V_39 ,
0x18 , & V_70 [ 0x18 ] , 1 ) ;
if ( 0 != V_7 )
goto V_73;
V_7 = F_36 ( & V_35 -> V_86 . V_87 ,
& V_33 -> V_53 ,
0 ,
1 ) ;
if ( 0 != V_7 )
goto V_73;
F_37 ( & V_33 -> V_57 , F_27 ) ;
F_31 ( & V_33 -> V_57 ) ;
F_3 ( L_19 , V_12 ) ;
return 0 ;
V_73:
F_3 ( L_20 , V_12 , V_7 ) ;
F_38 ( V_33 ) ;
return V_7 ;
}
void F_39 ( struct V_34 * V_35 )
{
struct V_32 * V_33 ;
if ( NULL == V_35 )
return;
V_33 = (struct V_32 * ) V_35 -> V_66 ;
if ( NULL == V_33 )
return;
if ( NULL == V_33 -> V_53 . V_31 )
return;
F_40 ( & V_33 -> V_53 ) ;
F_38 ( V_33 ) ;
}
