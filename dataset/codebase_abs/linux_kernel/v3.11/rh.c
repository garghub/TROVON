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
T_2 V_18 , V_19 ;
unsigned long * V_20 = ( unsigned long * ) V_17 ;
V_19 = V_1 -> V_21 + 1 ;
V_19 = ( V_19 + 8 - 1 ) / 8 ;
for ( V_18 = 0 ; V_18 < V_1 -> V_21 ; V_18 ++ )
if ( F_2 ( V_1 , V_18 ) -> V_10 )
F_6 ( V_18 + 1 , V_20 ) ;
else
F_7 ( V_18 + 1 , V_20 ) ;
return V_19 ;
}
static int F_8 ( struct V_1 * V_1 , T_3 V_22 ,
T_3 V_23 ,
struct V_24 * V_25 ,
T_3 V_26 )
{
T_3 V_27 = 1 + ( V_1 -> V_21 / 8 ) ;
T_1 V_28 = 7 + 2 * V_27 ;
if ( V_26 < V_28 )
return - V_29 ;
V_25 -> V_30 = 7 + 2 * V_27 ;
V_25 -> V_31 = 0x29 ;
V_25 -> V_32 = V_1 -> V_21 ;
V_25 -> V_33 = F_9 (
0x00
| 0x00
| 0x10
| 0x00
| 0x00 ) ;
V_25 -> V_34 = 0 ;
V_25 -> V_35 = 0 ;
memset ( & V_25 -> V_36 . V_37 . V_38 [ 0 ] , 0 , V_27 ) ;
memset ( & V_25 -> V_36 . V_37 . V_38 [ V_27 ] , 0xff , V_27 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_1 , T_3 V_39 )
{
int V_3 ;
switch ( V_39 ) {
case V_40 :
case V_41 :
V_3 = 0 ;
break;
default:
V_3 = - V_42 ;
}
return V_3 ;
}
static int F_11 ( struct V_1 * V_1 , T_4 * V_20 ,
T_3 V_26 )
{
* V_20 = 0 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_1 , T_3 V_39 ,
T_1 V_43 , T_1 V_2 )
{
struct V_44 * V_45 = V_1 -> V_45 ;
if ( V_2 > V_1 -> V_21 )
return - V_46 ;
switch ( V_39 ) {
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
return 0 ;
case V_52 :
F_13 ( & V_1 -> V_53 ) ;
F_2 ( V_1 , V_2 ) -> V_8 |= V_54 ;
F_14 ( & V_1 -> V_53 ) ;
return 0 ;
case V_55 :
return F_1 ( V_1 , V_2 ) ;
case V_56 :
case V_57 :
F_15 ( V_45 , L_1 ,
V_2 , V_39 , V_43 ) ;
return - V_58 ;
default:
F_15 ( V_45 , L_2 ,
V_2 , V_39 , V_43 ) ;
return - V_42 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_1 , T_3 V_39 ,
T_1 V_43 , T_1 V_2 )
{
int V_3 = 0 ;
struct V_44 * V_45 = V_1 -> V_45 ;
if ( V_2 > V_1 -> V_21 )
return - V_46 ;
F_13 ( & V_1 -> V_53 ) ;
switch ( V_39 ) {
case V_52 :
case V_47 :
break;
case V_51 :
F_2 ( V_1 , V_2 ) -> V_10 &= ~ V_11 ;
break;
case V_50 :
F_2 ( V_1 , V_2 ) -> V_10 &= ~ V_59 ;
break;
case V_56 :
F_17 ( V_1 , V_2 ) ;
break;
case V_48 :
F_2 ( V_1 , V_2 ) -> V_10 &= ~ V_15 ;
break;
case V_57 :
case V_49 :
F_15 ( V_45 , L_3 ,
V_2 , V_39 , V_43 ) ;
V_3 = - V_58 ;
break;
default:
F_15 ( V_45 , L_4 ,
V_2 , V_39 , V_43 ) ;
V_3 = - V_42 ;
break;
}
F_14 ( & V_1 -> V_53 ) ;
return V_3 ;
}
static int F_18 ( struct V_1 * V_1 , T_3 V_2 ,
T_4 * V_17 , T_3 V_26 )
{
T_5 * V_20 = ( T_5 * ) V_17 ;
if ( V_2 > V_1 -> V_21 )
return - V_46 ;
F_13 ( & V_1 -> V_53 ) ;
V_20 [ 0 ] = F_9 ( F_2 ( V_1 , V_2 ) -> V_8 ) ;
V_20 [ 1 ] = F_9 ( F_2 ( V_1 , V_2 ) -> V_10 ) ;
F_14 ( & V_1 -> V_53 ) ;
return 0 ;
}
int F_19 ( struct V_16 * V_16 , T_3 V_60 , T_3 V_22 ,
T_3 V_23 , char * V_20 , T_3 V_26 )
{
int V_3 = - V_58 ;
struct V_1 * V_1 = F_5 ( V_16 ) ;
switch ( V_60 ) {
case V_61 :
V_3 = F_8 (
V_1 , V_22 , V_23 ,
(struct V_24 * ) V_20 , V_26 ) ;
break;
case V_62 :
V_3 = F_10 ( V_1 , V_22 ) ;
break;
case V_63 :
V_3 = F_11 ( V_1 , ( T_4 * ) V_20 , V_26 ) ;
break;
case V_64 :
V_3 = F_12 ( V_1 , V_22 , V_23 >> 8 ,
( V_23 & 0xff ) - 1 ) ;
break;
case V_65 :
V_3 = F_16 ( V_1 , V_22 , V_23 >> 8 ,
( V_23 & 0xff ) - 1 ) ;
break;
case V_66 :
V_3 = F_18 ( V_1 , V_23 - 1 ,
( T_4 * ) V_20 , V_26 ) ;
break;
case V_67 :
default:
F_15 ( V_1 -> V_45 , L_5
L_6 , V_68 , V_16 , V_1 , V_60 ,
V_22 , V_23 , V_20 , V_26 ) ;
V_3 = - V_58 ;
}
return V_3 ;
}
int F_20 ( struct V_16 * V_16 , unsigned V_2 )
{
struct V_1 * V_1 = F_5 ( V_16 ) ;
F_15 ( V_1 -> V_45 , L_7 ,
V_68 , V_16 , V_1 , V_2 ) ;
F_21 ( 1 ) ;
return - V_58 ;
}
static void F_22 ( struct V_4 * V_5 )
{
V_5 -> V_8 |= V_69 ;
}
int F_23 ( struct V_1 * V_1 )
{
int V_3 = - V_70 ;
T_2 V_71 , V_72 ;
V_71 = V_1 -> V_21 * sizeof( V_1 -> V_5 [ 0 ] ) ;
V_1 -> V_5 = F_24 ( V_71 , V_73 ) ;
if ( V_1 -> V_5 == NULL )
goto V_74;
for ( V_72 = 0 ; V_72 < V_1 -> V_21 ; V_72 ++ )
F_22 ( & V_1 -> V_5 [ V_72 ] ) ;
V_3 = 0 ;
V_74:
return V_3 ;
}
void F_25 ( struct V_1 * V_1 )
{
F_26 ( V_1 -> V_5 ) ;
}
