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
F_5 ( L_3 ,
V_15 , V_4 , V_6 ) ;
return - V_16 ;
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
static int F_6 ( struct V_17 * V_18 )
{
int V_19 ;
unsigned long V_20 = V_21 + F_7 ( 1 ) ;
for (; ; ) {
V_19 = F_8 ( V_22 ) ;
if ( ( V_19 & V_23 ) == 0 )
break;
if ( F_9 ( V_21 , V_20 ) )
break;
F_10 ( 1 ) ;
}
F_11 ( V_22 , V_24 ) ;
return V_19 & 0xff ;
}
static int F_12 ( struct V_25 * V_26 , int V_27 ,
T_1 V_28 , T_1 V_29 , int V_3 , T_1 V_30 )
{
struct V_31 * V_32 = V_26 -> V_30 ;
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_17 * V_18 = V_34 -> V_18 ;
T_1 V_36 ;
int V_19 ;
int V_7 ;
if ( 0 != V_27 )
return - V_16 ;
if ( V_32 -> V_37 != V_28 ) {
V_7 = F_1 ( V_32 -> V_2 , V_32 -> V_38 ,
0 , & V_36 , 1 ) ;
if ( V_7 != 0 )
return V_7 ;
V_36 &= ~ 0x0c ;
V_36 |= V_28 ;
V_7 = F_4 ( V_32 -> V_2 , V_32 -> V_38 ,
0 , & V_36 , 1 ) ;
if ( V_7 != 0 )
return V_7 ;
}
V_32 -> V_37 = V_28 ;
F_13 ( & V_18 -> V_39 ) ;
F_14 ( V_40 , V_41 ) ;
F_14 ( V_22 , V_24 |
V_42 | ( 0xff & V_3 ) ) ;
F_15 ( V_22 , V_42 ) ;
F_14 ( V_22 , V_24 |
V_43 | ( 0xff & ( V_3 >> 8 ) ) ) ;
F_15 ( V_22 , V_43 ) ;
if ( V_29 ) {
F_14 ( V_40 , V_41 | V_44 ) ;
} else
F_14 ( V_22 , V_24 | V_30 ) ;
F_15 ( V_22 ,
( V_32 -> V_38 == 0x40 ) ? V_45 : V_46 ) ;
F_15 ( V_22 , ( V_29 ) ? V_47 : V_48 ) ;
V_19 = F_6 ( V_18 ) ;
F_16 ( & V_18 -> V_39 ) ;
if ( ! V_29 )
if ( V_19 < 0 )
return - V_49 ;
F_3 ( L_5 , V_12 ,
( V_29 ) ? L_6 : L_7 , V_32 -> V_38 , V_3 ,
( V_28 == V_50 ) ? L_8 : L_9 ,
( V_29 ) ? V_19 : V_30 ) ;
if ( V_29 )
return V_19 ;
return 0 ;
}
int F_17 ( struct V_25 * V_26 ,
int V_27 , int V_3 )
{
return F_12 ( V_26 , V_27 , 0 , V_51 , V_3 , 0 ) ;
}
int F_18 ( struct V_25 * V_26 ,
int V_27 , int V_3 , T_1 V_30 )
{
return F_12 ( V_26 , V_27 , 0 , 0 , V_3 , V_30 ) ;
}
int F_19 ( struct V_25 * V_26 , int V_27 ,
T_1 V_3 )
{
return F_12 ( V_26 , V_27 , V_50 ,
V_51 , V_3 , 0 ) ;
}
int F_20 ( struct V_25 * V_26 , int V_27 ,
T_1 V_3 , T_1 V_30 )
{
return F_12 ( V_26 , V_27 , V_50 , 0 , V_3 , V_30 ) ;
}
int F_21 ( struct V_25 * V_26 , int V_27 )
{
struct V_31 * V_32 = V_26 -> V_30 ;
T_1 V_5 = 0x80 ;
int V_7 ;
if ( 0 != V_27 )
return - V_16 ;
F_10 ( 500 ) ;
V_7 = F_4 ( V_32 -> V_2 , V_32 -> V_38 ,
0 , & V_5 , 1 ) ;
if ( V_7 != 0 )
return V_7 ;
F_10 ( 500 ) ;
V_5 = 0x00 ;
V_7 = F_4 ( V_32 -> V_2 , V_32 -> V_38 ,
0 , & V_5 , 1 ) ;
F_22 ( 1000 ) ;
F_23 ( & V_32 -> V_52 , 0 ) ;
return 0 ;
}
int F_24 ( struct V_25 * V_26 , int V_27 )
{
return 0 ;
}
static int F_25 ( struct V_25 * V_26 , T_1 V_53 )
{
struct V_31 * V_32 = V_26 -> V_30 ;
int V_7 ;
if ( V_53 == V_32 -> V_54 )
return 0 ;
F_3 ( L_10 ,
V_12 , V_32 -> V_38 , V_53 ) ;
V_7 = F_4 ( V_32 -> V_2 , V_32 -> V_38 ,
0x1b , & V_53 , 1 ) ;
if ( V_7 != 0 )
return V_7 ;
V_32 -> V_54 = V_53 ;
return 0 ;
}
int F_26 ( struct V_25 * V_26 , int V_27 )
{
struct V_31 * V_32 = V_26 -> V_30 ;
T_1 V_5 ;
if ( 0 != V_27 )
return - V_16 ;
F_1 ( V_32 -> V_2 , V_32 -> V_38 ,
0 , & V_5 , 1 ) ;
V_5 |= 0x60 ;
return F_4 ( V_32 -> V_2 , V_32 -> V_38 ,
0 , & V_5 , 1 ) ;
}
static void F_27 ( struct V_55 * V_56 )
{
struct V_31 * V_32 =
F_28 ( V_56 , struct V_31 , V_56 ) ;
T_1 V_5 [ 33 ] ;
int V_7 ;
F_29 ( & V_32 -> V_52 , 0 ) ;
if ( F_9 ( V_21 , V_32 -> V_57 )
|| ! V_32 -> V_58 ) {
V_7 = F_1 ( V_32 -> V_2 , V_32 -> V_38 ,
0 , & V_5 [ 0 ] , 33 ) ;
V_32 -> V_57 = V_21
+ F_7 ( 1000 ) ;
if ( V_7 != 0 )
return;
F_3 ( L_11 ,
V_12 , V_32 -> V_38 , 0 , V_5 [ 0 ] , V_5 [ 0 ] ) ;
if ( V_5 [ 0 ] & 1 )
V_32 -> V_58 = V_59 |
V_60 ;
else
V_32 -> V_58 = 0 ;
}
}
int F_30 ( struct V_17 * V_18 , T_2 V_61 )
{
struct V_33 * V_34 = NULL ;
struct V_31 * V_32 = NULL ;
F_3 ( L_12 , V_12 ) ;
if ( 0 == ( V_61 & ( V_62 | V_63 ) ) )
return 0 ;
if ( V_61 & V_62 ) {
V_34 = & V_18 -> V_64 ;
V_32 = V_34 -> V_65 ;
F_31 ( & V_32 -> V_56 ) ;
F_3 ( L_13 , V_12 ) ;
}
if ( V_61 & V_63 ) {
V_34 = & V_18 -> V_66 ;
V_32 = V_34 -> V_65 ;
F_31 ( & V_32 -> V_56 ) ;
F_3 ( L_14 , V_12 ) ;
}
return 1 ;
}
int F_32 ( struct V_25 * V_26 ,
int V_27 , int V_67 )
{
struct V_31 * V_32 = V_26 -> V_30 ;
if ( 0 != V_27 )
return - V_16 ;
F_25 ( V_26 , V_67 ? ( V_68 | F_33 () )
: V_68 ) ;
return V_32 -> V_58 ;
}
int F_34 ( struct V_33 * V_34 )
{
struct V_31 * V_32 ;
T_1 V_69 [ 34 ] = {
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
F_33 () | V_68 ,
0x05 ,
0x00 ,
0x04 ,
0x00 ,
0x33 ,
0x31 ,
} ;
int V_7 ;
F_3 ( L_15 , V_12 ) ;
V_32 = F_35 ( sizeof( struct V_31 ) , V_70 ) ;
if ( ! V_32 ) {
F_3 ( L_16 , V_12 ) ;
V_7 = - V_71 ;
goto V_72;
}
V_34 -> V_65 = V_32 ;
switch ( V_34 -> V_73 ) {
case 1 :
V_32 -> V_38 = 0x40 ;
break;
case 2 :
V_32 -> V_38 = 0x41 ;
break;
}
V_32 -> V_2 = & V_34 -> V_18 -> V_74 [ 0 ] . V_2 ;
V_32 -> V_52 . V_75 = V_76 ;
V_32 -> V_52 . V_77 = F_17 ;
V_32 -> V_52 . V_78 = F_18 ;
V_32 -> V_52 . V_79 = F_19 ;
V_32 -> V_52 . V_80 = F_20 ;
V_32 -> V_52 . V_81 = F_21 ;
V_32 -> V_52 . V_82 = F_24 ;
V_32 -> V_52 . V_83 = F_26 ;
V_32 -> V_52 . V_84 = F_32 ;
V_32 -> V_52 . V_30 = V_32 ;
V_32 -> V_35 = V_34 ;
V_32 -> V_54 = F_33 () | V_68 ;
V_7 = F_4 ( V_32 -> V_2 , V_32 -> V_38 ,
0 , & V_69 [ 0 ] , 34 ) ;
V_7 |= F_4 ( V_32 -> V_2 , V_32 -> V_38 ,
0x1f , & V_69 [ 0x18 ] , 1 ) ;
V_7 |= F_4 ( V_32 -> V_2 , V_32 -> V_38 ,
0x18 , & V_69 [ 0x18 ] , 1 ) ;
if ( 0 != V_7 )
goto V_72;
V_7 = F_36 ( & V_34 -> V_85 . V_86 ,
& V_32 -> V_52 ,
0 ,
1 ) ;
if ( 0 != V_7 )
goto V_72;
F_37 ( & V_32 -> V_56 , F_27 ) ;
F_31 ( & V_32 -> V_56 ) ;
F_3 ( L_17 , V_12 ) ;
return 0 ;
V_72:
F_3 ( L_18 , V_12 , V_7 ) ;
F_38 ( V_32 ) ;
return V_7 ;
}
void F_39 ( struct V_33 * V_34 )
{
struct V_31 * V_32 ;
if ( NULL == V_34 )
return;
V_32 = (struct V_31 * ) V_34 -> V_65 ;
if ( NULL == V_32 )
return;
if ( NULL == V_32 -> V_52 . V_30 )
return;
F_40 ( & V_32 -> V_52 ) ;
F_38 ( V_32 ) ;
}
