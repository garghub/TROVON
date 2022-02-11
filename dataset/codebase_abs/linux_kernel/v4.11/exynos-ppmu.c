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
int V_11 ;
T_1 V_12 ;
V_11 = F_5 ( V_10 -> V_13 , V_14 ,
V_15 |
V_16 |
V_17 |
V_18 |
V_19 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_10 -> V_13 , V_20 , & V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
V_12 &= ~ V_21 ;
V_11 = F_5 ( V_10 -> V_13 , V_20 , V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_7 = F_1 ( V_2 ) ;
int V_11 ;
T_1 V_12 , V_22 ;
if ( V_7 < 0 )
return V_7 ;
V_11 = F_6 ( V_10 -> V_13 , V_23 , & V_22 ) ;
if ( V_11 < 0 )
return V_11 ;
V_22 |= ( V_15 | ( V_24 << V_7 ) ) ;
V_11 = F_5 ( V_10 -> V_13 , V_23 , V_22 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_5 ( V_10 -> V_13 , F_8 ( V_7 ) ,
V_25 | V_26 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_10 -> V_13 , V_20 , & V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
V_12 &= ~ ( V_21
| V_27
| V_28 ) ;
V_12 |= ( V_24 << V_29 ) ;
V_12 |= ( V_24 << V_30 ) ;
V_12 |= ( V_24 << V_31 ) ;
V_11 = F_5 ( V_10 -> V_13 , V_20 , V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_7 = F_1 ( V_2 ) ;
unsigned int V_34 , V_35 ;
unsigned int V_36 , V_37 ;
unsigned int V_12 , V_38 ;
int V_11 ;
if ( V_7 < 0 )
return - V_8 ;
V_11 = F_6 ( V_10 -> V_13 , V_20 , & V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
V_12 &= ~ V_21 ;
V_11 = F_5 ( V_10 -> V_13 , V_20 , V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_10 -> V_13 , V_39 , & V_34 ) ;
if ( V_11 < 0 )
return V_11 ;
V_33 -> V_34 = V_34 ;
switch ( V_7 ) {
case V_40 :
case V_41 :
case V_42 :
V_11 = F_6 ( V_10 -> V_13 , F_10 ( V_7 ) , & V_35 ) ;
if ( V_11 < 0 )
return V_11 ;
V_33 -> V_35 = V_35 ;
break;
case V_43 :
V_11 = F_6 ( V_10 -> V_13 , V_44 , & V_36 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_10 -> V_13 , V_45 , & V_37 ) ;
if ( V_11 < 0 )
return V_11 ;
V_33 -> V_35 = ( ( V_36 << 8 ) | V_37 ) ;
break;
default:
return - V_8 ;
}
V_11 = F_6 ( V_10 -> V_13 , V_14 , & V_38 ) ;
if ( V_11 < 0 )
return V_11 ;
V_38 |= ( V_15 | ( V_24 << V_7 ) ) ;
V_11 = F_5 ( V_10 -> V_13 , V_14 , V_38 ) ;
if ( V_11 < 0 )
return V_11 ;
F_11 ( & V_2 -> V_46 , L_1 , V_2 -> V_5 -> V_6 ,
V_33 -> V_35 , V_33 -> V_34 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_11 ;
T_1 V_12 , V_47 ;
V_47 = ( V_15 | V_16 | V_17
| V_18 | V_19 ) ;
V_11 = F_5 ( V_10 -> V_13 , V_48 , V_47 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_5 ( V_10 -> V_13 , V_49 , V_47 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_5 ( V_10 -> V_13 , V_50 , V_47 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_5 ( V_10 -> V_13 , V_51 , V_47 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_5 ( V_10 -> V_13 , V_52 , 0x0 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_5 ( V_10 -> V_13 , V_53 , 0x0 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_5 ( V_10 -> V_13 , V_54 , 0x0 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_5 ( V_10 -> V_13 , V_55 , 0x0 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_5 ( V_10 -> V_13 , V_56 , 0x0 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_5 ( V_10 -> V_13 , V_57 , 0x0 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_5 ( V_10 -> V_13 , V_58 , 0x0 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_5 ( V_10 -> V_13 , V_59 , 0x0 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_5 ( V_10 -> V_13 , V_60 , 0x0 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_5 ( V_10 -> V_13 , V_61 , 0x0 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_5 ( V_10 -> V_13 , V_62 , 0x0 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_5 ( V_10 -> V_13 , V_63 , 0x0 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_5 ( V_10 -> V_13 , V_64 , 0x0 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_5 ( V_10 -> V_13 , V_65 , 0x0 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_10 -> V_13 , V_66 , & V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
V_12 &= ~ V_21 ;
V_11 = F_5 ( V_10 -> V_13 , V_66 , V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
unsigned int V_12 , V_22 ;
int V_7 = F_1 ( V_2 ) ;
int V_11 ;
V_11 = F_6 ( V_10 -> V_13 , V_67 , & V_22 ) ;
if ( V_11 < 0 )
return V_11 ;
V_22 |= ( V_15 | ( V_24 << V_7 ) ) ;
V_11 = F_5 ( V_10 -> V_13 , V_67 , V_22 ) ;
if ( V_11 < 0 )
return V_11 ;
switch ( V_7 ) {
case V_40 :
case V_41 :
case V_42 :
V_11 = F_5 ( V_10 -> V_13 , F_14 ( V_7 ) ,
V_68 | V_69 ) ;
if ( V_11 < 0 )
return V_11 ;
break;
case V_43 :
V_11 = F_5 ( V_10 -> V_13 , F_14 ( V_7 ) ,
V_70 ) ;
if ( V_11 < 0 )
return V_11 ;
break;
}
V_11 = F_6 ( V_10 -> V_13 , V_66 , & V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
V_12 &= ~ ( V_21
| V_27
| V_28
| V_71
| V_72 ) ;
V_12 |= ( V_24 << V_29 ) ;
V_12 |= ( V_24 << V_30 ) ;
V_12 |= ( V_24 << V_31 ) ;
V_12 |= ( V_73 << V_74 ) ;
V_11 = F_5 ( V_10 -> V_13 , V_66 , V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_7 = F_1 ( V_2 ) ;
int V_11 ;
unsigned int V_12 , V_38 ;
unsigned int V_75 , V_76 ;
unsigned int V_34 , V_77 ;
unsigned long V_35 = 0 ;
V_11 = F_6 ( V_10 -> V_13 , V_66 , & V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
V_12 &= ~ V_21 ;
V_11 = F_5 ( V_10 -> V_13 , V_66 , V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_10 -> V_13 , V_78 , & V_34 ) ;
if ( V_11 < 0 )
return V_11 ;
V_33 -> V_34 = V_34 ;
switch ( V_7 ) {
case V_40 :
case V_41 :
case V_42 :
V_11 = F_6 ( V_10 -> V_13 , F_16 ( V_7 ) , & V_77 ) ;
if ( V_11 < 0 )
return V_11 ;
V_35 = V_77 ;
break;
case V_43 :
V_11 = F_6 ( V_10 -> V_13 , V_79 ,
& V_75 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_10 -> V_13 , V_80 , & V_76 ) ;
if ( V_11 < 0 )
return V_11 ;
V_35 = ( ( V_81 ) ( ( V_75 & 0xff ) ) << 32 ) + ( V_81 ) V_76 ;
break;
}
V_33 -> V_35 = V_35 ;
V_11 = F_6 ( V_10 -> V_13 , V_50 , & V_38 ) ;
if ( V_11 < 0 )
return 0 ;
V_38 |= ( V_15 | ( V_24 << V_7 ) ) ;
V_11 = F_5 ( V_10 -> V_13 , V_50 , V_38 ) ;
if ( V_11 < 0 )
return V_11 ;
F_11 ( & V_2 -> V_46 , L_2 , V_2 -> V_5 -> V_6 ,
V_33 -> V_35 , V_33 -> V_34 ) ;
return 0 ;
}
static struct V_82 * F_17 ( struct V_83 * V_84 )
{
const struct V_85 * V_86 ;
V_86 = F_18 ( V_87 , V_84 ) ;
return (struct V_82 * ) V_86 -> V_88 ;
}
static int F_19 ( struct V_83 * V_84 ,
struct V_9 * V_10 )
{
struct V_89 * V_5 ;
struct V_82 * V_90 ;
struct V_91 * V_46 = V_10 -> V_46 ;
struct V_83 * V_92 , * V_93 ;
int V_3 , V_94 , V_77 ;
V_92 = F_20 ( V_84 , L_3 ) ;
if ( ! V_92 ) {
F_21 ( V_46 ,
L_4 ) ;
return - V_8 ;
}
V_90 = F_17 ( V_84 ) ;
V_77 = F_22 ( V_92 ) ;
V_5 = F_23 ( V_46 , sizeof( * V_5 ) * V_77 , V_95 ) ;
if ( ! V_5 )
return - V_96 ;
V_10 -> V_97 = V_77 ;
V_94 = 0 ;
F_24 (events_np, node) {
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
if ( ! V_4 [ V_3 ] . V_6 )
continue;
if ( ! F_25 ( V_93 -> V_6 , V_4 [ V_3 ] . V_6 ) )
break;
}
if ( V_3 == F_2 ( V_4 ) ) {
F_26 ( V_46 ,
L_5 ,
V_93 -> V_6 ) ;
continue;
}
V_5 [ V_94 ] . V_98 = V_90 ;
V_5 [ V_94 ] . V_99 = V_10 ;
F_27 ( V_93 , L_6 , & V_5 [ V_94 ] . V_6 ) ;
V_94 ++ ;
}
V_10 -> V_5 = V_5 ;
F_28 ( V_92 ) ;
return 0 ;
}
static int F_29 ( struct V_100 * V_101 ,
struct V_9 * V_10 )
{
struct V_91 * V_46 = V_10 -> V_46 ;
struct V_83 * V_84 = V_46 -> V_102 ;
struct V_103 * V_104 ;
void T_2 * V_105 ;
int V_11 = 0 ;
if ( ! V_84 ) {
F_21 ( V_46 , L_7 ) ;
return - V_8 ;
}
V_104 = F_30 ( V_101 , V_106 , 0 ) ;
V_105 = F_31 ( V_46 , V_104 ) ;
if ( F_32 ( V_105 ) )
return F_33 ( V_105 ) ;
V_107 . V_108 = F_34 ( V_104 ) - 4 ;
V_10 -> V_13 = F_35 ( V_46 , V_105 ,
& V_107 ) ;
if ( F_32 ( V_10 -> V_13 ) ) {
F_21 ( V_46 , L_8 ) ;
return F_33 ( V_10 -> V_13 ) ;
}
V_10 -> V_109 . V_110 = F_36 ( V_46 , L_9 ) ;
if ( F_32 ( V_10 -> V_109 . V_110 ) ) {
V_10 -> V_109 . V_110 = NULL ;
F_26 ( V_46 , L_10 ) ;
}
V_11 = F_19 ( V_84 , V_10 ) ;
if ( V_11 < 0 ) {
F_21 ( V_46 , L_11 ) ;
return V_11 ;
}
return 0 ;
}
static int F_37 ( struct V_100 * V_101 )
{
struct V_9 * V_10 ;
struct V_1 * * V_2 ;
struct V_89 * V_5 ;
int V_3 , V_11 = 0 , V_111 ;
V_10 = F_23 ( & V_101 -> V_46 , sizeof( * V_10 ) , V_95 ) ;
if ( ! V_10 )
return - V_96 ;
V_10 -> V_46 = & V_101 -> V_46 ;
V_11 = F_29 ( V_101 , V_10 ) ;
if ( V_11 < 0 ) {
F_21 ( & V_101 -> V_46 ,
L_12 ) ;
return V_11 ;
}
V_5 = V_10 -> V_5 ;
V_111 = sizeof( struct V_1 * ) * V_10 -> V_97 ;
V_10 -> V_2 = F_23 ( & V_101 -> V_46 , V_111 , V_95 ) ;
if ( ! V_10 -> V_2 ) {
F_21 ( & V_101 -> V_46 ,
L_13 ) ;
return - V_96 ;
}
V_2 = V_10 -> V_2 ;
F_38 ( V_101 , V_10 ) ;
for ( V_3 = 0 ; V_3 < V_10 -> V_97 ; V_3 ++ ) {
V_2 [ V_3 ] = F_39 ( & V_101 -> V_46 , & V_5 [ V_3 ] ) ;
if ( F_32 ( V_2 [ V_3 ] ) ) {
V_11 = F_33 ( V_2 [ V_3 ] ) ;
F_21 ( & V_101 -> V_46 ,
L_14 ) ;
return F_33 ( V_2 [ V_3 ] ) ;
}
F_40 ( L_15 ,
F_41 ( & V_101 -> V_46 ) , V_5 [ V_3 ] . V_6 ) ;
}
F_42 ( V_10 -> V_109 . V_110 ) ;
return 0 ;
}
static int F_43 ( struct V_100 * V_101 )
{
struct V_9 * V_10 = F_44 ( V_101 ) ;
F_45 ( V_10 -> V_109 . V_110 ) ;
return 0 ;
}
