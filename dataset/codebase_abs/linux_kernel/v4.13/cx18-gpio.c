static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_2 -> V_4 & 0xffff ;
T_1 V_5 = V_2 -> V_6 & 0xffff ;
T_1 V_7 = V_2 -> V_4 >> 16 ;
T_1 V_8 = V_2 -> V_6 >> 16 ;
F_2 ( V_2 , V_3 << 16 ,
V_9 , ~ V_3 , V_3 ) ;
F_2 ( V_2 , ( V_3 << 16 ) | V_5 ,
V_10 , V_5 , V_3 ) ;
F_2 ( V_2 , V_7 << 16 ,
V_11 , ~ V_7 , V_7 ) ;
F_2 ( V_2 , ( V_7 << 16 ) | V_8 ,
V_12 , V_8 , V_7 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_13 , T_1 V_14 )
{
if ( V_13 == 0 )
return;
F_4 ( & V_2 -> V_15 ) ;
V_2 -> V_6 = ( V_2 -> V_6 & ~ V_13 ) | ( V_14 & V_13 ) ;
F_1 ( V_2 ) ;
F_5 ( & V_2 -> V_15 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_16 , T_1 V_17 ,
unsigned int V_18 ,
unsigned int V_19 )
{
T_1 V_13 ;
V_13 = V_16 | V_17 ;
if ( V_13 == 0 )
return;
F_3 ( V_2 , V_13 , ~ V_16 ) ;
F_7 ( F_8 ( V_18 ) ) ;
F_3 ( V_2 , V_13 , ~ V_17 ) ;
F_7 ( F_8 ( V_19 ) ) ;
}
static int F_9 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
F_4 ( & V_2 -> V_15 ) ;
F_11 ( V_21 , L_1 ,
V_2 -> V_4 , V_2 -> V_6 ) ;
F_5 ( & V_2 -> V_15 ) ;
return 0 ;
}
static int F_12 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
F_3 ( V_2 , V_2 -> V_22 -> V_23 . V_13 ,
V_2 -> V_22 -> V_23 . V_24 ) ;
return 0 ;
}
static int F_13 ( struct V_20 * V_21 , T_2 V_25 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
T_1 V_14 ;
switch ( V_2 -> V_22 -> V_26 [ V_2 -> V_27 ] . V_28 ) {
case 1 :
V_14 = V_2 -> V_22 -> V_23 . V_29 ;
break;
case 0 :
V_14 = V_2 -> V_22 -> V_23 . V_30 ;
break;
default:
V_14 = V_2 -> V_22 -> V_23 . V_30 ;
break;
}
F_3 ( V_2 , V_2 -> V_22 -> V_23 . V_13 , V_14 ) ;
return 0 ;
}
static int F_14 ( struct V_20 * V_21 ,
T_1 V_31 , T_1 V_32 , T_1 V_33 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
T_1 V_14 ;
switch ( V_31 ) {
case 0 :
V_14 = V_2 -> V_22 -> V_23 . V_30 ;
break;
case 1 :
V_14 = V_2 -> V_22 -> V_23 . V_29 ;
break;
case 2 :
V_14 = V_2 -> V_22 -> V_23 . V_24 ;
break;
default:
return - V_34 ;
}
F_3 ( V_2 , V_2 -> V_22 -> V_23 . V_13 , V_14 ) ;
return 0 ;
}
static int F_15 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
F_4 ( & V_2 -> V_15 ) ;
F_11 ( V_21 , L_1 ,
V_2 -> V_4 , V_2 -> V_6 ) ;
F_5 ( & V_2 -> V_15 ) ;
return 0 ;
}
static int F_16 ( struct V_20 * V_21 , T_1 V_35 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
const struct V_36 * V_37 ;
V_37 = & V_2 -> V_22 -> V_38 ;
switch ( V_35 ) {
case V_39 :
F_6 ( V_2 , V_37 -> V_40 , V_37 -> V_41 ,
V_37 -> V_42 , V_37 -> V_43 ) ;
break;
case V_44 :
F_6 ( V_2 , V_37 -> V_45 , 0 ,
V_37 -> V_42 , V_37 -> V_43 ) ;
break;
case V_46 :
if ( V_2 -> V_22 -> V_47 [ 0 ] . V_30 == V_48 )
F_6 ( V_2 , ( 1 << V_2 -> V_22 -> V_49 ) , 0 ,
1 , 1 ) ;
break;
}
return 0 ;
}
void F_17 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_15 ) ;
V_2 -> V_4 = V_2 -> V_22 -> V_50 . V_51 ;
V_2 -> V_6 = V_2 -> V_22 -> V_50 . V_52 ;
if ( V_2 -> V_22 -> V_47 [ 0 ] . V_30 == V_48 ) {
V_2 -> V_4 |= 1 << V_2 -> V_22 -> V_49 ;
V_2 -> V_6 |= 1 << V_2 -> V_22 -> V_49 ;
}
if ( V_2 -> V_4 == 0 ) {
F_5 ( & V_2 -> V_15 ) ;
return;
}
F_18 ( L_2 ,
F_19 ( V_2 , V_9 ) ,
F_19 ( V_2 , V_11 ) ,
F_19 ( V_2 , V_10 ) ,
F_19 ( V_2 , V_12 ) ) ;
F_1 ( V_2 ) ;
F_5 ( & V_2 -> V_15 ) ;
}
int F_20 ( struct V_1 * V_2 , T_1 V_53 )
{
struct V_20 * V_21 ;
const struct V_54 * V_55 ;
char * V_56 ;
switch ( V_53 ) {
case V_57 :
V_21 = & V_2 -> V_58 ;
V_55 = & V_59 ;
V_56 = L_3 ;
break;
case V_60 :
V_21 = & V_2 -> V_61 ;
V_55 = & V_62 ;
V_56 = L_4 ;
break;
default:
return - V_34 ;
}
F_21 ( V_21 , V_55 ) ;
F_22 ( V_21 , V_2 ) ;
snprintf ( V_21 -> V_63 , sizeof( V_21 -> V_63 ) , L_5 , V_2 -> V_64 . V_63 , V_56 ) ;
V_21 -> V_65 = V_53 ;
return F_23 ( & V_2 -> V_64 , V_21 ) ;
}
void F_24 ( void * V_14 )
{
struct V_1 * V_2 = F_25 ( (struct V_66 * ) V_14 ) ;
if ( V_2 -> V_22 -> V_38 . V_45 == 0 )
return;
F_18 ( L_6 ) ;
F_26 ( & V_2 -> V_61 ,
V_67 , V_68 , V_44 ) ;
}
int F_27 ( void * V_69 , int V_70 , int V_71 , int V_72 )
{
struct V_73 * V_74 = V_69 ;
struct V_75 * V_76 = V_74 -> V_14 ;
struct V_1 * V_2 = V_76 -> V_2 ;
if ( V_71 != V_77 ||
V_2 -> V_22 -> V_47 [ 0 ] . V_30 != V_48 )
return 0 ;
F_18 ( L_7 ) ;
return F_26 ( & V_2 -> V_61 ,
V_67 , V_68 , V_46 ) ;
}
