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
V_26 -> V_32 = 0x29 ;
V_26 -> V_33 = V_1 -> V_21 ;
V_26 -> V_34 = F_8 (
V_35
| 0x00
| V_36
| 0x00
| 0x00 ) ;
V_26 -> V_37 = 0 ;
V_26 -> V_38 = 0 ;
memset ( & V_26 -> V_39 . V_40 . V_41 [ 0 ] , 0 , V_28 ) ;
memset ( & V_26 -> V_39 . V_40 . V_41 [ V_28 ] , 0xff , V_28 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_1 , T_3 V_42 )
{
int V_3 ;
switch ( V_42 ) {
case V_43 :
case V_44 :
V_3 = 0 ;
break;
default:
V_3 = - V_45 ;
}
return V_3 ;
}
static int F_10 ( struct V_1 * V_1 , T_4 * V_46 ,
T_3 V_27 )
{
* V_46 = 0 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_1 , T_3 V_42 ,
T_1 V_47 , T_1 V_2 )
{
struct V_48 * V_49 = V_1 -> V_49 ;
if ( V_2 > V_1 -> V_21 )
return - V_50 ;
switch ( V_42 ) {
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
return 0 ;
case V_56 :
F_12 ( & V_1 -> V_57 ) ;
F_2 ( V_1 , V_2 ) -> V_8 |= V_58 ;
F_13 ( & V_1 -> V_57 ) ;
return 0 ;
case V_59 :
return F_1 ( V_1 , V_2 ) ;
case V_60 :
case V_61 :
F_14 ( V_49 , L_1 ,
V_2 , V_42 , V_47 ) ;
return - V_62 ;
default:
F_14 ( V_49 , L_2 ,
V_2 , V_42 , V_47 ) ;
return - V_45 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_1 , T_3 V_42 ,
T_1 V_47 , T_1 V_2 )
{
int V_3 = 0 ;
struct V_48 * V_49 = V_1 -> V_49 ;
if ( V_2 > V_1 -> V_21 )
return - V_50 ;
F_12 ( & V_1 -> V_57 ) ;
switch ( V_42 ) {
case V_56 :
case V_51 :
break;
case V_55 :
F_2 ( V_1 , V_2 ) -> V_10 &= ~ V_11 ;
break;
case V_54 :
F_2 ( V_1 , V_2 ) -> V_10 &= ~ V_63 ;
break;
case V_60 :
F_16 ( V_1 , V_2 ) ;
break;
case V_52 :
F_2 ( V_1 , V_2 ) -> V_10 &= ~ V_15 ;
break;
case V_61 :
case V_53 :
F_14 ( V_49 , L_3 ,
V_2 , V_42 , V_47 ) ;
V_3 = - V_62 ;
break;
default:
F_14 ( V_49 , L_4 ,
V_2 , V_42 , V_47 ) ;
V_3 = - V_45 ;
break;
}
F_13 ( & V_1 -> V_57 ) ;
return V_3 ;
}
static int F_17 ( struct V_1 * V_1 , T_3 V_2 ,
T_4 * V_17 , T_3 V_27 )
{
T_5 * V_46 = ( T_5 * ) V_17 ;
if ( V_2 > V_1 -> V_21 )
return - V_50 ;
F_12 ( & V_1 -> V_57 ) ;
V_46 [ 0 ] = F_8 ( F_2 ( V_1 , V_2 ) -> V_8 ) ;
V_46 [ 1 ] = F_8 ( F_2 ( V_1 , V_2 ) -> V_10 ) ;
F_13 ( & V_1 -> V_57 ) ;
return 0 ;
}
int F_18 ( struct V_16 * V_16 , T_3 V_64 , T_3 V_23 ,
T_3 V_24 , char * V_46 , T_3 V_27 )
{
int V_3 = - V_62 ;
struct V_1 * V_1 = F_5 ( V_16 ) ;
switch ( V_64 ) {
case V_65 :
V_3 = F_7 (
V_1 , V_23 , V_24 ,
(struct V_25 * ) V_46 , V_27 ) ;
break;
case V_66 :
V_3 = F_9 ( V_1 , V_23 ) ;
break;
case V_67 :
V_3 = F_10 ( V_1 , ( T_4 * ) V_46 , V_27 ) ;
break;
case V_68 :
V_3 = F_11 ( V_1 , V_23 , V_24 >> 8 ,
( V_24 & 0xff ) - 1 ) ;
break;
case V_69 :
V_3 = F_15 ( V_1 , V_23 , V_24 >> 8 ,
( V_24 & 0xff ) - 1 ) ;
break;
case V_70 :
V_3 = F_17 ( V_1 , V_24 - 1 ,
( T_4 * ) V_46 , V_27 ) ;
break;
case V_71 :
default:
F_14 ( V_1 -> V_49 , L_5
L_6 , V_72 , V_16 , V_1 , V_64 ,
V_23 , V_24 , V_46 , V_27 ) ;
V_3 = - V_62 ;
}
return V_3 ;
}
int F_19 ( struct V_16 * V_16 , unsigned V_2 )
{
struct V_1 * V_1 = F_5 ( V_16 ) ;
F_14 ( V_1 -> V_49 , L_7 ,
V_72 , V_16 , V_1 , V_2 ) ;
F_20 ( 1 ) ;
return - V_62 ;
}
static void F_21 ( struct V_4 * V_5 )
{
V_5 -> V_8 |= V_73 ;
}
int F_22 ( struct V_1 * V_1 )
{
int V_3 = - V_74 ;
T_2 V_75 , V_76 ;
V_75 = V_1 -> V_21 * sizeof( V_1 -> V_5 [ 0 ] ) ;
V_1 -> V_5 = F_23 ( V_75 , V_77 ) ;
if ( V_1 -> V_5 == NULL )
goto V_78;
for ( V_76 = 0 ; V_76 < V_1 -> V_21 ; V_76 ++ )
F_21 ( & V_1 -> V_5 [ V_76 ] ) ;
V_3 = 0 ;
V_78:
return V_3 ;
}
void F_24 ( struct V_1 * V_1 )
{
F_25 ( V_1 -> V_5 ) ;
}
