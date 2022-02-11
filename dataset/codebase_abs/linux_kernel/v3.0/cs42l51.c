static int F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_4 + 1 ;
struct V_5 * V_5 = V_2 -> V_6 ;
T_2 V_7 ;
V_7 = F_2 ( V_5 ,
V_8 | 0x80 , V_9 , V_3 ) ;
if ( V_7 != V_9 ) {
F_3 ( & V_5 -> V_10 ,
L_1 ,
V_5 -> V_11 , V_7 , V_9 ) ;
return - V_12 ;
}
return 0 ;
}
static int F_4 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = F_5 ( V_14 ) ;
unsigned long V_17 = F_6 ( V_2 , V_18 ) & 3 ;
switch ( V_17 ) {
default:
case 0 :
V_16 -> V_17 . integer . V_17 [ 0 ] = 0 ;
break;
case 1 :
case 2 :
V_16 -> V_17 . integer . V_17 [ 0 ] = 1 ;
break;
case 3 :
V_16 -> V_17 . integer . V_17 [ 0 ] = 2 ;
break;
}
return 0 ;
}
static int F_7 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = F_5 ( V_14 ) ;
unsigned char V_19 ;
switch ( V_16 -> V_17 . integer . V_17 [ 0 ] ) {
default:
case 0 :
V_19 = V_20 ;
break;
case 1 :
V_19 = V_21 ;
break;
case 2 :
V_19 = V_22 ;
break;
}
F_8 ( V_2 , V_18 , V_19 ) ;
return 1 ;
}
static int F_9 ( struct V_23 * V_24 ,
struct V_13 * V_14 , int V_25 )
{
unsigned long V_17 ;
V_17 = F_6 ( V_24 -> V_2 , V_26 ) ;
V_17 &= ~ V_27 ;
switch ( V_25 ) {
case V_28 :
V_17 |= V_27 ;
break;
default:
case V_29 :
break;
}
F_10 ( V_24 -> V_2 , V_26 ,
V_27 , V_17 ) ;
return 0 ;
}
static int F_11 ( struct V_30 * V_31 ,
unsigned int V_32 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
struct V_33 * V_34 = F_12 ( V_2 ) ;
int V_35 = 0 ;
switch ( V_32 & V_36 ) {
case V_37 :
case V_38 :
case V_39 :
V_34 -> V_40 = V_32 & V_36 ;
break;
default:
F_3 ( V_2 -> V_10 , L_2 ) ;
V_35 = - V_41 ;
}
switch ( V_32 & V_42 ) {
case V_43 :
V_34 -> V_44 = V_45 ;
break;
case V_46 :
V_34 -> V_44 = V_47 ;
break;
default:
V_35 = - V_41 ;
break;
}
return V_35 ;
}
static int F_13 ( struct V_30 * V_31 ,
int V_48 , unsigned int V_49 , int V_50 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
struct V_33 * V_34 = F_12 ( V_2 ) ;
V_34 -> V_51 = V_49 ;
return 0 ;
}
static int F_14 ( struct V_52 * V_53 ,
struct V_54 * V_55 ,
struct V_30 * V_56 )
{
struct V_57 * V_58 = V_53 -> V_59 ;
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_33 * V_34 = F_12 ( V_2 ) ;
int V_35 ;
unsigned int V_60 ;
unsigned int V_61 ;
unsigned int V_62 ;
struct V_63 * V_64 = NULL ;
int V_65 = 0 ;
int V_66 , V_67 , V_68 ;
switch ( V_34 -> V_44 ) {
case V_45 :
return - V_41 ;
case V_69 :
V_64 = V_70 ;
V_65 = F_15 ( V_70 ) ;
break;
case V_47 :
V_64 = V_71 ;
V_65 = F_15 ( V_71 ) ;
break;
}
V_61 = F_16 ( V_55 ) ;
V_62 = V_34 -> V_51 / V_61 ;
for ( V_60 = 0 ; V_60 < V_65 ; V_60 ++ ) {
if ( V_64 [ V_60 ] . V_62 == V_62 )
break;
}
if ( V_60 == V_65 ) {
F_3 ( V_2 -> V_10 , L_3 ) ;
return - V_41 ;
}
V_66 = F_6 ( V_2 , V_72 ) ;
V_67 = F_6 ( V_2 , V_73 ) ;
V_66 &= ~ ( V_74 | V_75
| F_17 ( 7 ) ) ;
V_67 &= ~ ( F_18 ( 3 )
| V_76 ) ;
switch ( V_34 -> V_44 ) {
case V_45 :
V_66 |= V_74 ;
V_67 |= F_18 ( V_64 [ V_60 ] . V_77 ) ;
break;
case V_69 :
V_67 |= F_18 ( V_64 [ V_60 ] . V_77 ) ;
break;
case V_47 :
V_67 |= V_78 ;
break;
}
switch ( V_34 -> V_40 ) {
case V_37 :
V_66 |= V_75 ;
V_66 |= F_17 ( V_79 ) ;
break;
case V_38 :
V_66 |= F_17 ( V_80 ) ;
break;
case V_39 :
switch ( F_19 ( V_55 ) ) {
case V_81 :
case V_82 :
V_68 = V_83 ;
break;
case V_84 :
case V_85 :
V_68 = V_86 ;
break;
case V_87 :
case V_88 :
V_68 = V_89 ;
break;
case V_90 :
case V_91 :
V_68 = V_92 ;
break;
default:
F_3 ( V_2 -> V_10 , L_4 ) ;
return - V_41 ;
}
V_66 |= F_17 ( V_68 ) ;
break;
default:
F_3 ( V_2 -> V_10 , L_4 ) ;
return - V_41 ;
}
if ( V_64 [ V_60 ] . V_51 )
V_67 |= V_76 ;
V_35 = F_8 ( V_2 , V_72 , V_66 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_8 ( V_2 , V_73 , V_67 ) ;
if ( V_35 < 0 )
return V_35 ;
return 0 ;
}
static int F_20 ( struct V_30 * V_56 , int V_93 )
{
struct V_1 * V_2 = V_56 -> V_2 ;
int V_94 ;
int V_95 = V_96 | V_97 ;
V_94 = F_6 ( V_2 , V_98 ) ;
if ( V_93 )
V_94 |= V_95 ;
else
V_94 &= ~ V_95 ;
return F_8 ( V_2 , V_98 , V_94 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = F_12 ( V_2 ) ;
struct V_99 * V_100 = & V_2 -> V_100 ;
int V_35 , V_94 ;
V_2 -> V_6 = V_34 -> V_6 ;
V_35 = F_1 ( V_2 ) ;
if ( V_35 < 0 ) {
F_3 ( V_2 -> V_10 , L_5 ) ;
return V_35 ;
}
V_35 = F_22 ( V_2 , 8 , 8 , V_34 -> V_101 ) ;
if ( V_35 < 0 ) {
F_3 ( V_2 -> V_10 , L_6 , V_35 ) ;
return V_35 ;
}
V_94 = F_23 ( 1 )
| V_102 | F_24 ( 0 ) ;
V_35 = F_8 ( V_2 , V_103 , V_94 ) ;
if ( V_35 < 0 )
return V_35 ;
F_25 ( V_2 , V_104 ,
F_15 ( V_104 ) ) ;
F_26 ( V_100 , V_105 ,
F_15 ( V_105 ) ) ;
F_27 ( V_100 , V_106 ,
F_15 ( V_106 ) ) ;
return 0 ;
}
static int F_28 ( struct V_5 * V_5 ,
const struct V_107 * V_108 )
{
struct V_33 * V_34 ;
int V_35 ;
V_35 = F_29 ( V_5 , V_109 ) ;
if ( V_35 < 0 ) {
F_3 ( & V_5 -> V_10 , L_7 ) ;
goto error;
}
if ( ( V_35 != F_30 ( V_110 , V_111 ) ) &&
( V_35 != F_30 ( V_110 , V_112 ) ) ) {
F_3 ( & V_5 -> V_10 , L_8 ) ;
V_35 = - V_113 ;
goto error;
}
F_31 ( & V_5 -> V_10 , L_9 ,
V_35 & 7 ) ;
V_34 = F_32 ( sizeof( struct V_33 ) , V_114 ) ;
if ( ! V_34 ) {
F_3 ( & V_5 -> V_10 , L_10 ) ;
return - V_115 ;
}
F_33 ( V_5 , V_34 ) ;
V_34 -> V_6 = V_5 ;
V_34 -> V_101 = V_116 ;
V_35 = F_34 ( & V_5 -> V_10 ,
& V_117 , & V_118 , 1 ) ;
if ( V_35 < 0 )
F_35 ( V_34 ) ;
error:
return V_35 ;
}
static int F_36 ( struct V_5 * V_119 )
{
struct V_33 * V_34 = F_37 ( V_119 ) ;
F_38 ( & V_119 -> V_10 ) ;
F_35 ( V_34 ) ;
return 0 ;
}
static int T_3 F_39 ( void )
{
int V_35 ;
V_35 = F_40 ( & V_120 ) ;
if ( V_35 != 0 ) {
F_41 ( V_121 L_11 , V_122 ) ;
return V_35 ;
}
return 0 ;
}
static void T_4 F_42 ( void )
{
F_43 ( & V_120 ) ;
}
