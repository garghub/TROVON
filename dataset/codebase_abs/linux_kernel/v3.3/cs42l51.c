static int F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_4 + 1 ;
struct V_5 * V_5 = F_2 ( V_2 -> V_6 ) ;
T_2 V_7 ;
V_7 = F_3 ( V_5 ,
V_8 | 0x80 , V_9 , V_3 ) ;
if ( V_7 != V_9 ) {
F_4 ( & V_5 -> V_6 ,
L_1 ,
V_5 -> V_10 , V_7 , V_9 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_5 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
struct V_1 * V_2 = F_6 ( V_13 ) ;
unsigned long V_16 = F_7 ( V_2 , V_17 ) & 3 ;
switch ( V_16 ) {
default:
case 0 :
V_15 -> V_16 . integer . V_16 [ 0 ] = 0 ;
break;
case 1 :
case 2 :
V_15 -> V_16 . integer . V_16 [ 0 ] = 1 ;
break;
case 3 :
V_15 -> V_16 . integer . V_16 [ 0 ] = 2 ;
break;
}
return 0 ;
}
static int F_8 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
struct V_1 * V_2 = F_6 ( V_13 ) ;
unsigned char V_18 ;
switch ( V_15 -> V_16 . integer . V_16 [ 0 ] ) {
default:
case 0 :
V_18 = V_19 ;
break;
case 1 :
V_18 = V_20 ;
break;
case 2 :
V_18 = V_21 ;
break;
}
F_9 ( V_2 , V_17 , V_18 ) ;
return 1 ;
}
static int F_10 ( struct V_22 * V_23 ,
struct V_12 * V_13 , int V_24 )
{
switch ( V_24 ) {
case V_25 :
F_11 ( V_23 -> V_2 , V_26 ,
V_27 ,
V_27 ) ;
break;
default:
case V_28 :
F_11 ( V_23 -> V_2 , V_26 ,
V_27 , 0 ) ;
break;
}
return 0 ;
}
static int F_12 ( struct V_29 * V_30 ,
unsigned int V_31 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_32 * V_33 = F_13 ( V_2 ) ;
switch ( V_31 & V_34 ) {
case V_35 :
case V_36 :
case V_37 :
V_33 -> V_38 = V_31 & V_34 ;
break;
default:
F_4 ( V_2 -> V_6 , L_2 ) ;
return - V_39 ;
}
switch ( V_31 & V_40 ) {
case V_41 :
V_33 -> V_42 = V_43 ;
break;
case V_44 :
V_33 -> V_42 = V_45 ;
break;
default:
F_4 ( V_2 -> V_6 , L_3 ) ;
return - V_39 ;
}
return 0 ;
}
static int F_14 ( struct V_29 * V_30 ,
int V_46 , unsigned int V_47 , int V_48 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_32 * V_33 = F_13 ( V_2 ) ;
V_33 -> V_49 = V_47 ;
return 0 ;
}
static int F_15 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
struct V_29 * V_54 )
{
struct V_55 * V_56 = V_51 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_32 * V_33 = F_13 ( V_2 ) ;
int V_58 ;
unsigned int V_59 ;
unsigned int V_60 ;
unsigned int V_61 ;
struct V_62 * V_63 = NULL ;
int V_64 = 0 ;
int V_65 , V_66 , V_67 ;
switch ( V_33 -> V_42 ) {
case V_43 :
return - V_39 ;
case V_68 :
V_63 = V_69 ;
V_64 = F_16 ( V_69 ) ;
break;
case V_45 :
V_63 = V_70 ;
V_64 = F_16 ( V_70 ) ;
break;
}
V_60 = F_17 ( V_53 ) ;
V_61 = V_33 -> V_49 / V_60 ;
for ( V_59 = 0 ; V_59 < V_64 ; V_59 ++ ) {
if ( V_63 [ V_59 ] . V_61 == V_61 )
break;
}
if ( V_59 == V_64 ) {
F_4 ( V_2 -> V_6 , L_4 ) ;
return - V_39 ;
}
V_65 = F_7 ( V_2 , V_71 ) ;
V_66 = F_7 ( V_2 , V_72 ) ;
V_65 &= ~ ( V_73 | V_74
| F_18 ( 7 ) ) ;
V_66 &= ~ ( F_19 ( 3 )
| V_75 ) ;
switch ( V_33 -> V_42 ) {
case V_43 :
V_65 |= V_73 ;
V_66 |= F_19 ( V_63 [ V_59 ] . V_76 ) ;
break;
case V_68 :
V_66 |= F_19 ( V_63 [ V_59 ] . V_76 ) ;
break;
case V_45 :
V_66 |= V_77 ;
break;
}
switch ( V_33 -> V_38 ) {
case V_35 :
V_65 |= V_74 ;
V_65 |= F_18 ( V_78 ) ;
break;
case V_36 :
V_65 |= F_18 ( V_79 ) ;
break;
case V_37 :
switch ( F_20 ( V_53 ) ) {
case V_80 :
case V_81 :
V_67 = V_82 ;
break;
case V_83 :
case V_84 :
V_67 = V_85 ;
break;
case V_86 :
case V_87 :
V_67 = V_88 ;
break;
case V_89 :
case V_90 :
V_67 = V_91 ;
break;
default:
F_4 ( V_2 -> V_6 , L_5 ) ;
return - V_39 ;
}
V_65 |= F_18 ( V_67 ) ;
break;
default:
F_4 ( V_2 -> V_6 , L_5 ) ;
return - V_39 ;
}
if ( V_63 [ V_59 ] . V_49 )
V_66 |= V_75 ;
V_58 = F_9 ( V_2 , V_71 , V_65 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_9 ( V_2 , V_72 , V_66 ) ;
if ( V_58 < 0 )
return V_58 ;
return 0 ;
}
static int F_21 ( struct V_29 * V_54 , int V_92 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
int V_93 ;
int V_94 = V_95 | V_96 ;
V_93 = F_7 ( V_2 , V_97 ) ;
if ( V_92 )
V_93 |= V_94 ;
else
V_93 &= ~ V_94 ;
return F_9 ( V_2 , V_97 , V_93 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_13 ( V_2 ) ;
int V_58 , V_93 ;
V_58 = F_1 ( V_2 ) ;
if ( V_58 < 0 ) {
F_4 ( V_2 -> V_6 , L_6 ) ;
return V_58 ;
}
V_58 = F_23 ( V_2 , 8 , 8 , V_33 -> V_98 ) ;
if ( V_58 < 0 ) {
F_4 ( V_2 -> V_6 , L_7 , V_58 ) ;
return V_58 ;
}
V_93 = F_24 ( 1 )
| V_99 | F_25 ( 0 ) ;
V_58 = F_9 ( V_2 , V_100 , V_93 ) ;
if ( V_58 < 0 )
return V_58 ;
return 0 ;
}
static int F_26 ( struct V_5 * V_5 ,
const struct V_101 * V_102 )
{
struct V_32 * V_33 ;
int V_58 ;
V_58 = F_27 ( V_5 , V_103 ) ;
if ( V_58 < 0 ) {
F_4 ( & V_5 -> V_6 , L_8 ) ;
goto error;
}
if ( ( V_58 != F_28 ( V_104 , V_105 ) ) &&
( V_58 != F_28 ( V_104 , V_106 ) ) ) {
F_4 ( & V_5 -> V_6 , L_9 ) ;
V_58 = - V_107 ;
goto error;
}
F_29 ( & V_5 -> V_6 , L_10 ,
V_58 & 7 ) ;
V_33 = F_30 ( & V_5 -> V_6 , sizeof( struct V_32 ) ,
V_108 ) ;
if ( ! V_33 ) {
F_4 ( & V_5 -> V_6 , L_11 ) ;
return - V_109 ;
}
F_31 ( V_5 , V_33 ) ;
V_33 -> V_98 = V_110 ;
V_58 = F_32 ( & V_5 -> V_6 ,
& V_111 , & V_112 , 1 ) ;
error:
return V_58 ;
}
static int F_33 ( struct V_5 * V_113 )
{
F_34 ( & V_113 -> V_6 ) ;
return 0 ;
}
static int T_3 F_35 ( void )
{
int V_58 ;
V_58 = F_36 ( & V_114 ) ;
if ( V_58 != 0 ) {
F_37 ( V_115 L_12 , V_116 ) ;
return V_58 ;
}
return 0 ;
}
static void T_4 F_38 ( void )
{
F_39 ( & V_114 ) ;
}
