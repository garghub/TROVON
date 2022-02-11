static int F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
int V_3 = 0 ;
struct V_4 * V_5 = F_2 ( V_1 , V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
if ( V_6 == NULL )
return - V_7 ;
V_5 -> V_8 |= V_9 ;
V_5 -> V_10 |= V_11 ;
if ( V_6 -> V_12 & V_13 )
V_3 = 0 ;
else
V_3 = F_3 ( V_1 , V_6 ) ;
V_5 -> V_8 &= ~ V_9 ;
V_5 -> V_8 |= V_14 ;
V_5 -> V_10 |= V_11 | V_15 ;
return V_3 ;
}
int F_4 ( struct V_16 * V_16 , char * V_17 )
{
struct V_1 * V_1 = F_5 ( V_16 ) ;
T_2 V_18 , V_19 , V_20 = 0 ;
V_19 = F_6 ( V_1 -> V_21 + 1 , 8 ) ;
memset ( V_17 , 0 , V_19 ) ;
for ( V_18 = 0 ; V_18 < V_1 -> V_21 ; V_18 ++ ) {
if ( F_2 ( V_1 , V_18 ) -> V_10 ) {
const int V_22 = V_18 + 1 ;
V_17 [ V_22 / 8 ] |= ( 1 << ( V_22 % 8 ) ) ;
V_20 ++ ;
}
}
return V_20 ? V_19 : 0 ;
}
static int F_7 ( struct V_1 * V_1 , T_3 V_23 ,
T_3 V_24 ,
struct V_25 * V_26 ,
T_3 V_27 )
{
T_3 V_28 = 1 + ( V_1 -> V_21 / 8 ) ;
T_1 V_29 = 7 + 2 * V_28 ;
if ( V_27 < V_29 )
return - V_30 ;
V_26 -> V_31 = 7 + 2 * V_28 ;
V_26 -> V_32 = V_33 ;
V_26 -> V_34 = V_1 -> V_21 ;
V_26 -> V_35 = F_8 (
V_36
| 0x00
| V_37
| 0x00
| 0x00 ) ;
V_26 -> V_38 = 0 ;
V_26 -> V_39 = 0 ;
memset ( & V_26 -> V_40 . V_41 . V_42 [ 0 ] , 0 , V_28 ) ;
memset ( & V_26 -> V_40 . V_41 . V_42 [ V_28 ] , 0xff , V_28 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_1 , T_3 V_43 )
{
int V_3 ;
switch ( V_43 ) {
case V_44 :
case V_45 :
V_3 = 0 ;
break;
default:
V_3 = - V_46 ;
}
return V_3 ;
}
static int F_10 ( struct V_1 * V_1 , T_4 * V_47 ,
T_3 V_27 )
{
* V_47 = 0 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_1 , T_3 V_43 ,
T_1 V_48 , T_1 V_2 )
{
struct V_49 * V_50 = V_1 -> V_50 ;
if ( V_2 > V_1 -> V_21 )
return - V_51 ;
switch ( V_43 ) {
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
return 0 ;
case V_57 :
F_12 ( & V_1 -> V_58 ) ;
F_2 ( V_1 , V_2 ) -> V_8 |= V_59 ;
F_13 ( & V_1 -> V_58 ) ;
return 0 ;
case V_60 :
return F_1 ( V_1 , V_2 ) ;
case V_61 :
case V_62 :
F_14 ( V_50 , L_1 ,
V_2 , V_43 , V_48 ) ;
return - V_63 ;
default:
F_14 ( V_50 , L_2 ,
V_2 , V_43 , V_48 ) ;
return - V_46 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_1 , T_3 V_43 ,
T_1 V_48 , T_1 V_2 )
{
int V_3 = 0 ;
struct V_49 * V_50 = V_1 -> V_50 ;
if ( V_2 > V_1 -> V_21 )
return - V_51 ;
F_12 ( & V_1 -> V_58 ) ;
switch ( V_43 ) {
case V_57 :
case V_52 :
break;
case V_56 :
F_2 ( V_1 , V_2 ) -> V_10 &= ~ V_11 ;
break;
case V_55 :
F_2 ( V_1 , V_2 ) -> V_10 &= ~ V_64 ;
break;
case V_61 :
F_16 ( V_1 , V_2 ) ;
break;
case V_53 :
F_2 ( V_1 , V_2 ) -> V_10 &= ~ V_15 ;
break;
case V_62 :
case V_54 :
F_14 ( V_50 , L_3 ,
V_2 , V_43 , V_48 ) ;
V_3 = - V_63 ;
break;
default:
F_14 ( V_50 , L_4 ,
V_2 , V_43 , V_48 ) ;
V_3 = - V_46 ;
break;
}
F_13 ( & V_1 -> V_58 ) ;
return V_3 ;
}
static int F_17 ( struct V_1 * V_1 , T_3 V_2 ,
T_4 * V_17 , T_3 V_27 )
{
T_5 * V_47 = ( T_5 * ) V_17 ;
if ( V_2 > V_1 -> V_21 )
return - V_51 ;
F_12 ( & V_1 -> V_58 ) ;
V_47 [ 0 ] = F_8 ( F_2 ( V_1 , V_2 ) -> V_8 ) ;
V_47 [ 1 ] = F_8 ( F_2 ( V_1 , V_2 ) -> V_10 ) ;
F_13 ( & V_1 -> V_58 ) ;
return 0 ;
}
int F_18 ( struct V_16 * V_16 , T_3 V_65 , T_3 V_23 ,
T_3 V_24 , char * V_47 , T_3 V_27 )
{
int V_3 = - V_63 ;
struct V_1 * V_1 = F_5 ( V_16 ) ;
switch ( V_65 ) {
case V_66 :
V_3 = F_7 (
V_1 , V_23 , V_24 ,
(struct V_25 * ) V_47 , V_27 ) ;
break;
case V_67 :
V_3 = F_9 ( V_1 , V_23 ) ;
break;
case V_68 :
V_3 = F_10 ( V_1 , ( T_4 * ) V_47 , V_27 ) ;
break;
case V_69 :
V_3 = F_11 ( V_1 , V_23 , V_24 >> 8 ,
( V_24 & 0xff ) - 1 ) ;
break;
case V_70 :
V_3 = F_15 ( V_1 , V_23 , V_24 >> 8 ,
( V_24 & 0xff ) - 1 ) ;
break;
case V_71 :
V_3 = F_17 ( V_1 , V_24 - 1 ,
( T_4 * ) V_47 , V_27 ) ;
break;
case V_72 :
default:
F_14 ( V_1 -> V_50 , L_5
L_6 , V_73 , V_16 , V_1 , V_65 ,
V_23 , V_24 , V_47 , V_27 ) ;
V_3 = - V_63 ;
}
return V_3 ;
}
int F_19 ( struct V_16 * V_16 , unsigned V_2 )
{
struct V_1 * V_1 = F_5 ( V_16 ) ;
F_14 ( V_1 -> V_50 , L_7 ,
V_73 , V_16 , V_1 , V_2 ) ;
F_20 ( 1 ) ;
return - V_63 ;
}
static void F_21 ( struct V_4 * V_5 )
{
V_5 -> V_8 |= V_74 ;
}
int F_22 ( struct V_1 * V_1 )
{
int V_3 = - V_75 ;
T_2 V_76 , V_77 ;
V_76 = V_1 -> V_21 * sizeof( V_1 -> V_5 [ 0 ] ) ;
V_1 -> V_5 = F_23 ( V_76 , V_78 ) ;
if ( V_1 -> V_5 == NULL )
goto V_79;
for ( V_77 = 0 ; V_77 < V_1 -> V_21 ; V_77 ++ )
F_21 ( & V_1 -> V_5 [ V_77 ] ) ;
V_3 = 0 ;
V_79:
return V_3 ;
}
void F_24 ( struct V_1 * V_1 )
{
F_25 ( V_1 -> V_5 ) ;
}
