static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
if ( ! strcmp ( V_2 -> V_5 -> V_6 , V_4 [ V_3 ] . V_6 ) )
return V_4 [ V_3 ] . V_7 ;
return - V_8 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_11 ;
F_5 ( V_12 |
V_13 |
V_14 |
V_15 |
V_16 ,
V_10 -> V_17 . V_18 + V_19 ) ;
V_11 = F_6 ( V_10 -> V_17 . V_18 + V_20 ) ;
V_11 &= ~ V_21 ;
F_5 ( V_11 , V_10 -> V_17 . V_18 + V_20 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_7 = F_1 ( V_2 ) ;
T_1 V_11 , V_22 ;
if ( V_7 < 0 )
return V_7 ;
V_22 = F_6 ( V_10 -> V_17 . V_18 + V_23 ) ;
V_22 |= ( V_12 | ( V_24 << V_7 ) ) ;
F_5 ( V_22 , V_10 -> V_17 . V_18 + V_23 ) ;
F_5 ( V_25 | V_26 ,
V_10 -> V_17 . V_18 + F_8 ( V_7 ) ) ;
V_11 = F_6 ( V_10 -> V_17 . V_18 + V_20 ) ;
V_11 &= ~ ( V_21
| V_27
| V_28 ) ;
V_11 |= ( V_24 << V_29 ) ;
V_11 |= ( V_24 << V_30 ) ;
V_11 |= ( V_24 << V_31 ) ;
F_5 ( V_11 , V_10 -> V_17 . V_18 + V_20 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_7 = F_1 ( V_2 ) ;
T_1 V_11 , V_34 ;
if ( V_7 < 0 )
return - V_8 ;
V_11 = F_6 ( V_10 -> V_17 . V_18 + V_20 ) ;
V_11 &= ~ V_21 ;
F_5 ( V_11 , V_10 -> V_17 . V_18 + V_20 ) ;
V_33 -> V_35 = F_6 ( V_10 -> V_17 . V_18 + V_36 ) ;
switch ( V_7 ) {
case V_37 :
case V_38 :
case V_39 :
V_33 -> V_40
= F_6 ( V_10 -> V_17 . V_18 + F_10 ( V_7 ) ) ;
break;
case V_41 :
V_33 -> V_40 =
( ( F_6 ( V_10 -> V_17 . V_18 + V_42 ) << 8 )
| F_6 ( V_10 -> V_17 . V_18 + V_43 ) ) ;
break;
default:
return - V_8 ;
}
V_34 = F_6 ( V_10 -> V_17 . V_18 + V_19 ) ;
V_34 |= ( V_12 | ( V_24 << V_7 ) ) ;
F_5 ( V_34 , V_10 -> V_17 . V_18 + V_19 ) ;
F_11 ( & V_2 -> V_44 , L_1 , V_2 -> V_5 -> V_6 ,
V_33 -> V_40 , V_33 -> V_35 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_11 , V_45 ;
V_45 = ( V_12 | V_13 | V_14
| V_15 | V_16 ) ;
F_5 ( V_45 , V_10 -> V_17 . V_18 + V_46 ) ;
F_5 ( V_45 , V_10 -> V_17 . V_18 + V_47 ) ;
F_5 ( V_45 , V_10 -> V_17 . V_18 + V_48 ) ;
F_5 ( V_45 , V_10 -> V_17 . V_18 + V_49 ) ;
F_5 ( 0x0 , V_10 -> V_17 . V_18 + V_50 ) ;
F_5 ( 0x0 , V_10 -> V_17 . V_18 + V_51 ) ;
F_5 ( 0x0 , V_10 -> V_17 . V_18 + V_52 ) ;
F_5 ( 0x0 , V_10 -> V_17 . V_18 + V_53 ) ;
F_5 ( 0x0 , V_10 -> V_17 . V_18 + V_54 ) ;
F_5 ( 0x0 , V_10 -> V_17 . V_18 + V_55 ) ;
F_5 ( 0x0 , V_10 -> V_17 . V_18 + V_56 ) ;
F_5 ( 0x0 , V_10 -> V_17 . V_18 + V_57 ) ;
F_5 ( 0x0 , V_10 -> V_17 . V_18 + V_58 ) ;
F_5 ( 0x0 , V_10 -> V_17 . V_18 + V_59 ) ;
F_5 ( 0x0 , V_10 -> V_17 . V_18 + V_60 ) ;
F_5 ( 0x0 , V_10 -> V_17 . V_18 + V_61 ) ;
F_5 ( 0x0 , V_10 -> V_17 . V_18 + V_62 ) ;
F_5 ( 0x0 , V_10 -> V_17 . V_18 + V_63 ) ;
V_11 = F_6 ( V_10 -> V_17 . V_18 + V_64 ) ;
V_11 &= ~ V_21 ;
F_5 ( V_11 , V_10 -> V_17 . V_18 + V_64 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_7 = F_1 ( V_2 ) ;
T_1 V_11 , V_22 ;
V_22 = F_6 ( V_10 -> V_17 . V_18 + V_65 ) ;
V_22 |= ( V_12 | ( V_24 << V_7 ) ) ;
F_5 ( V_22 , V_10 -> V_17 . V_18 + V_65 ) ;
switch ( V_7 ) {
case V_37 :
case V_38 :
case V_39 :
F_5 ( V_66 | V_67 ,
V_10 -> V_17 . V_18 + F_14 ( V_7 ) ) ;
break;
case V_41 :
F_5 ( V_68 ,
V_10 -> V_17 . V_18 + F_14 ( V_7 ) ) ;
break;
}
V_11 = F_6 ( V_10 -> V_17 . V_18 + V_64 ) ;
V_11 &= ~ ( V_21
| V_27
| V_28
| V_69
| V_70 ) ;
V_11 |= ( V_24 << V_29 ) ;
V_11 |= ( V_24 << V_30 ) ;
V_11 |= ( V_24 << V_31 ) ;
V_11 |= ( V_71 << V_72 ) ;
F_5 ( V_11 , V_10 -> V_17 . V_18 + V_64 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_7 = F_1 ( V_2 ) ;
T_1 V_11 , V_34 ;
T_1 V_73 , V_74 ;
T_2 V_40 = 0 ;
V_11 = F_6 ( V_10 -> V_17 . V_18 + V_64 ) ;
V_11 &= ~ V_21 ;
F_5 ( V_11 , V_10 -> V_17 . V_18 + V_64 ) ;
V_33 -> V_35 = F_6 ( V_10 -> V_17 . V_18 + V_75 ) ;
switch ( V_7 ) {
case V_37 :
case V_38 :
case V_39 :
V_40 = F_6 ( V_10 -> V_17 . V_18 + F_16 ( V_7 ) ) ;
break;
case V_41 :
V_73 = F_6 ( V_10 -> V_17 . V_18 + V_76 ) ;
V_74 = F_6 ( V_10 -> V_17 . V_18 + V_77 ) ;
V_40 = ( ( T_2 ) ( ( V_73 & 0xff ) ) << 32 )
+ ( T_2 ) V_74 ;
break;
}
V_33 -> V_40 = V_40 ;
V_34 = F_6 ( V_10 -> V_17 . V_18 + V_48 ) ;
V_34 |= ( V_12 | ( V_24 << V_7 ) ) ;
F_5 ( V_34 , V_10 -> V_17 . V_18 + V_48 ) ;
F_11 ( & V_2 -> V_44 , L_2 , V_2 -> V_5 -> V_6 ,
V_33 -> V_40 , V_33 -> V_35 ) ;
return 0 ;
}
static struct V_78 * F_17 ( struct V_79 * V_80 )
{
const struct V_81 * V_82 ;
V_82 = F_18 ( V_83 , V_80 ) ;
return (struct V_78 * ) V_82 -> V_84 ;
}
static int F_19 ( struct V_79 * V_80 ,
struct V_9 * V_10 )
{
struct V_85 * V_5 ;
struct V_78 * V_86 ;
struct V_87 * V_44 = V_10 -> V_44 ;
struct V_79 * V_88 , * V_89 ;
int V_3 , V_90 , V_91 ;
V_88 = F_20 ( V_80 , L_3 ) ;
if ( ! V_88 ) {
F_21 ( V_44 ,
L_4 ) ;
return - V_8 ;
}
V_86 = F_17 ( V_80 ) ;
V_91 = F_22 ( V_88 ) ;
V_5 = F_23 ( V_44 , sizeof( * V_5 ) * V_91 , V_92 ) ;
if ( ! V_5 )
return - V_93 ;
V_10 -> V_94 = V_91 ;
V_90 = 0 ;
F_24 (events_np, node) {
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
if ( ! V_4 [ V_3 ] . V_6 )
continue;
if ( ! F_25 ( V_89 -> V_6 , V_4 [ V_3 ] . V_6 ) )
break;
}
if ( V_3 == F_2 ( V_4 ) ) {
F_26 ( V_44 ,
L_5 ,
V_89 -> V_6 ) ;
continue;
}
V_5 [ V_90 ] . V_95 = V_86 ;
V_5 [ V_90 ] . V_96 = V_10 ;
F_27 ( V_89 , L_6 , & V_5 [ V_90 ] . V_6 ) ;
V_90 ++ ;
}
V_10 -> V_5 = V_5 ;
F_28 ( V_88 ) ;
return 0 ;
}
static int F_29 ( struct V_9 * V_10 )
{
struct V_87 * V_44 = V_10 -> V_44 ;
struct V_79 * V_80 = V_44 -> V_97 ;
int V_98 = 0 ;
if ( ! V_80 ) {
F_21 ( V_44 , L_7 ) ;
return - V_8 ;
}
V_10 -> V_17 . V_18 = F_30 ( V_80 , 0 ) ;
if ( F_31 ( V_10 -> V_17 . V_18 ) ) {
F_21 ( V_44 , L_8 ) ;
return - V_93 ;
}
V_10 -> V_17 . V_99 = F_32 ( V_44 , L_9 ) ;
if ( F_33 ( V_10 -> V_17 . V_99 ) ) {
V_10 -> V_17 . V_99 = NULL ;
F_26 ( V_44 , L_10 ) ;
}
V_98 = F_19 ( V_80 , V_10 ) ;
if ( V_98 < 0 ) {
F_21 ( V_44 , L_11 ) ;
goto V_100;
}
return 0 ;
V_100:
F_34 ( V_10 -> V_17 . V_18 ) ;
return V_98 ;
}
static int F_35 ( struct V_101 * V_102 )
{
struct V_9 * V_10 ;
struct V_1 * * V_2 ;
struct V_85 * V_5 ;
int V_3 , V_98 = 0 , V_103 ;
V_10 = F_23 ( & V_102 -> V_44 , sizeof( * V_10 ) , V_92 ) ;
if ( ! V_10 )
return - V_93 ;
V_10 -> V_44 = & V_102 -> V_44 ;
V_98 = F_29 ( V_10 ) ;
if ( V_98 < 0 ) {
F_21 ( & V_102 -> V_44 ,
L_12 ) ;
return V_98 ;
}
V_5 = V_10 -> V_5 ;
V_103 = sizeof( struct V_1 * ) * V_10 -> V_94 ;
V_10 -> V_2 = F_23 ( & V_102 -> V_44 , V_103 , V_92 ) ;
if ( ! V_10 -> V_2 ) {
F_21 ( & V_102 -> V_44 ,
L_13 ) ;
V_98 = - V_93 ;
goto V_100;
}
V_2 = V_10 -> V_2 ;
F_36 ( V_102 , V_10 ) ;
for ( V_3 = 0 ; V_3 < V_10 -> V_94 ; V_3 ++ ) {
V_2 [ V_3 ] = F_37 ( & V_102 -> V_44 , & V_5 [ V_3 ] ) ;
if ( F_33 ( V_2 [ V_3 ] ) ) {
V_98 = F_38 ( V_2 [ V_3 ] ) ;
F_21 ( & V_102 -> V_44 ,
L_14 ) ;
goto V_100;
}
}
F_39 ( V_10 -> V_17 . V_99 ) ;
return 0 ;
V_100:
F_34 ( V_10 -> V_17 . V_18 ) ;
return V_98 ;
}
static int F_40 ( struct V_101 * V_102 )
{
struct V_9 * V_10 = F_41 ( V_102 ) ;
F_42 ( V_10 -> V_17 . V_99 ) ;
F_34 ( V_10 -> V_17 . V_18 ) ;
return 0 ;
}
