static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_7 ) ;
if ( V_3 & V_8 ) {
F_3 ( V_6 -> V_9 ) ;
F_4 ( V_6 -> V_9 , true ) ;
}
return 0 ;
}
static bool F_5 ( struct V_10 * V_11 , unsigned int V_12 )
{
switch ( V_12 ) {
case V_13 ... V_14 :
case V_15 ... V_16 :
case V_17 :
return true ;
}
return false ;
}
static bool F_6 ( struct V_10 * V_11 , unsigned int V_12 )
{
switch ( V_12 ) {
case V_18 ... V_14 :
case V_15 ... V_16 :
return true ;
}
return false ;
}
static bool F_7 ( struct V_10 * V_11 , unsigned int V_12 )
{
switch ( V_12 ) {
case V_13 :
case V_19 :
return true ;
}
return false ;
}
static bool F_8 ( struct V_10 * V_11 , unsigned int V_12 )
{
switch ( V_12 ) {
case V_13 :
return true ;
}
return false ;
}
static int F_9 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_27 ;
struct V_5 * V_6 = F_10 ( V_27 ) ;
T_1 V_28 ;
T_1 V_29 = 0 ;
T_1 V_30 = 0 ;
T_1 V_31 = 0 ;
unsigned long V_32 ;
int V_33 ;
F_11 ( V_27 -> V_11 , L_1 ,
F_12 ( V_23 ) ,
F_13 ( V_23 ) ) ;
if ( F_13 ( V_23 ) == 2 )
V_30 |= V_34 ;
switch ( V_6 -> V_35 & V_36 ) {
case V_37 :
V_28 = 0 ;
break;
case V_38 :
V_28 = V_39 ;
break;
default:
return - V_40 ;
}
V_29 |= V_28 ;
if ( V_28 ) {
if ( F_14 ( V_23 ) * F_13 ( V_23 ) > 48 )
V_30 |= V_41 ;
else
V_30 |= V_42 ;
}
switch ( V_6 -> V_35 & V_43 ) {
case V_44 :
V_29 |= V_45 ;
V_30 |= V_46 ;
break;
case V_47 :
V_29 |= V_48 ;
break;
case V_49 :
if ( F_14 ( V_23 ) != 16 ) {
F_15 ( V_27 -> V_11 ,
L_2 ) ;
return - V_40 ;
}
V_29 |= V_45 | V_48 | V_50 | V_51 ;
V_30 |= V_46 ;
break;
case V_52 :
if ( F_14 ( V_23 ) != 16 ) {
F_15 ( V_27 -> V_11 ,
L_3 ) ;
return - V_40 ;
}
V_29 |= V_48 | V_50 | V_51 ;
break;
default:
return - V_40 ;
}
switch ( V_6 -> V_35 & V_53 ) {
case V_54 :
break;
case V_55 :
switch ( V_6 -> V_35 & V_43 ) {
case V_49 :
case V_52 :
return - V_40 ;
}
V_29 ^= V_48 ;
break;
case V_56 :
switch ( V_6 -> V_35 & V_43 ) {
case V_49 :
case V_52 :
return - V_40 ;
}
V_29 ^= V_48 ;
case V_57 :
V_29 ^= V_58 ;
V_30 ^= V_59 ;
break;
default:
return - V_40 ;
}
F_11 ( V_27 -> V_11 , L_4 , V_29 ) ;
V_33 = F_16 ( V_6 -> V_9 , V_60 , V_29 ) ;
if ( V_33 ) {
F_15 ( V_27 -> V_11 , L_5 , V_33 ) ;
return V_33 ;
}
F_11 ( V_27 -> V_11 , L_6 , V_30 ) ;
V_33 = F_16 ( V_6 -> V_9 , V_61 , V_30 ) ;
if ( V_33 ) {
F_15 ( V_27 -> V_11 , L_7 , V_33 ) ;
return V_33 ;
}
if ( F_12 ( V_23 ) == 8000 || F_12 ( V_23 ) == 16000 ) {
if ( V_28 ) {
switch ( V_6 -> V_62 ) {
case 12000000 :
V_31 = V_63 ;
break;
case 13000000 :
V_31 = V_64 ;
break;
case 19200000 :
V_31 = V_65 ;
break;
default:
break;
}
if ( V_31 && F_12 ( V_23 ) == 16000 )
V_31 |= V_66 ;
}
}
V_32 = F_17 ( 65536ULL * 96 * F_12 ( V_23 ) ,
V_6 -> V_62 ) ;
if ( ! V_31 ) {
if ( F_12 ( V_23 ) > 24000 )
V_31 |= V_66 ;
if ( ! V_28 )
V_32 |= 1 ;
}
V_31 |= V_6 -> V_67 ;
F_11 ( V_27 -> V_11 , L_8 , V_31 ) ;
V_33 = F_16 ( V_6 -> V_9 ,
V_68 , V_31 ) ;
if ( V_33 ) {
F_15 ( V_27 -> V_11 , L_9 , V_33 ) ;
return V_33 ;
}
F_11 ( V_27 -> V_11 , L_10 , V_32 ) ;
V_33 = F_16 ( V_6 -> V_9 ,
V_69 , V_32 >> 8 ) ;
if ( V_33 ) {
F_15 ( V_27 -> V_11 , L_11 , V_33 ) ;
return V_33 ;
}
V_33 = F_16 ( V_6 -> V_9 ,
V_70 , V_32 & 0xff ) ;
if ( V_33 ) {
F_15 ( V_27 -> V_11 , L_12 , V_33 ) ;
return V_33 ;
}
if ( ! V_28 ) {
F_11 ( V_27 -> V_11 , L_13 ) ;
V_33 = F_18 ( V_6 -> V_9 , V_69 ,
V_71 , V_71 ) ;
if ( V_33 ) {
F_15 ( V_27 -> V_11 , L_14 , V_33 ) ;
return V_33 ;
}
}
return 0 ;
}
static int F_19 ( struct V_24 * V_25 , unsigned int V_35 )
{
struct V_26 * V_27 = V_25 -> V_27 ;
struct V_5 * V_6 = F_10 ( V_27 ) ;
switch ( V_35 & V_36 ) {
case V_38 :
case V_37 :
V_6 -> V_35 = V_35 ;
return 0 ;
default:
return - V_40 ;
}
}
static int F_20 ( struct V_26 * V_27 ,
enum V_72 V_73 )
{
struct V_5 * V_6 = F_21 ( V_27 -> V_11 ) ;
int V_33 ;
switch ( V_73 ) {
case V_74 :
case V_75 :
break;
case V_76 :
V_33 = F_18 ( V_6 -> V_9 , V_16 ,
V_77 , V_77 ) ;
if ( V_33 ) {
F_15 ( V_27 -> V_11 , L_15 , V_33 ) ;
return V_33 ;
}
break;
case V_78 :
V_33 = F_18 ( V_6 -> V_9 , V_16 ,
V_77 , 0 ) ;
if ( V_33 ) {
F_15 ( V_27 -> V_11 , L_16 ,
V_33 ) ;
return V_33 ;
}
break;
}
return 0 ;
}
static int F_22 ( struct V_10 * V_11 )
{
struct V_5 * V_6 = F_21 ( V_11 ) ;
int V_33 ;
V_33 = F_18 ( V_6 -> V_9 , V_68 ,
V_79 , V_80 ) ;
if ( V_33 ) {
F_15 ( V_11 , L_17 , V_33 ) ;
return V_33 ;
}
F_23 ( V_6 -> V_81 ) ;
return 0 ;
}
static int F_24 ( struct V_10 * V_11 )
{
struct V_5 * V_6 = F_21 ( V_11 ) ;
int V_33 ;
V_33 = F_25 ( V_6 -> V_81 ) ;
if ( V_33 ) {
F_15 ( V_11 , L_18 , V_33 ) ;
return V_33 ;
}
F_4 ( V_6 -> V_9 , false ) ;
V_33 = F_26 ( V_6 -> V_9 ) ;
if ( V_33 ) {
F_15 ( V_11 , L_19 , V_33 ) ;
return V_33 ;
}
V_33 = F_18 ( V_6 -> V_9 , V_68 ,
V_79 , V_6 -> V_67 ) ;
if ( V_33 ) {
F_15 ( V_11 , L_20 , V_33 ) ;
return V_33 ;
}
return 0 ;
}
static int F_27 ( struct V_82 * V_83 ,
const struct V_84 * V_85 )
{
struct V_10 * V_11 = & V_83 -> V_11 ;
struct V_5 * V_6 ;
int V_33 ;
struct V_86 * V_87 ;
unsigned long V_88 ;
int V_89 ;
int V_90 ;
V_6 = F_28 ( V_11 , sizeof( struct V_5 ) , V_91 ) ;
if ( ! V_6 )
return - V_92 ;
V_6 -> V_81 = F_29 ( V_11 , L_21 ) ;
if ( F_30 ( V_6 -> V_81 ) ) {
V_33 = F_31 ( V_6 -> V_81 ) ;
if ( V_33 != - V_93 )
F_15 ( V_11 , L_22 , V_33 ) ;
return V_33 ;
}
V_6 -> V_7 . V_94 = F_1 ;
V_33 = F_32 ( V_6 -> V_81 , & V_6 -> V_7 ) ;
if ( V_33 )
F_15 ( V_11 , L_23 , V_33 ) ;
V_33 = F_25 ( V_6 -> V_81 ) ;
if ( V_33 != 0 ) {
F_15 ( V_11 , L_18 , V_33 ) ;
return V_33 ;
}
V_6 -> V_9 = F_33 ( V_83 , & V_95 ) ;
if ( F_30 ( V_6 -> V_9 ) ) {
V_33 = F_31 ( V_6 -> V_9 ) ;
goto V_96;
}
F_34 ( V_11 , V_6 ) ;
V_87 = F_35 ( V_11 , L_24 ) ;
if ( F_30 ( V_87 ) ) {
V_33 = F_31 ( V_87 ) ;
if ( V_33 != - V_93 )
F_15 ( V_11 , L_25 , V_33 ) ;
goto V_96;
}
V_88 = F_36 ( V_87 ) ;
F_37 ( V_87 ) ;
if ( V_88 > 60000000 || V_88 < 10000000 ) {
F_15 ( V_11 , L_26 ,
V_88 ) ;
V_33 = - V_40 ;
goto V_96;
}
if ( V_88 >= 40000000 )
V_6 -> V_67 = 3 ;
else if ( V_88 >= 20000000 )
V_6 -> V_67 = 2 ;
else
V_6 -> V_67 = 1 ;
V_6 -> V_62 = V_88 >> ( V_6 -> V_67 - 1 ) ;
V_6 -> V_67 <<= V_97 ;
F_11 ( V_11 , L_27 , V_88 , V_6 -> V_62 ) ;
F_38 ( V_6 -> V_9 , true ) ;
for ( V_89 = 0 ; V_89 < V_95 . V_98 ; ++ V_89 ) {
V_33 = F_16 ( V_6 -> V_9 ,
V_95 . V_99 [ V_89 ] . V_12 ,
V_95 . V_99 [ V_89 ] . V_100 ) ;
if ( V_33 ) {
F_15 ( V_11 , L_28 ,
V_95 . V_99 [ V_89 ] . V_12 , V_33 ) ;
goto V_96;
}
}
F_38 ( V_6 -> V_9 , false ) ;
V_33 = F_39 ( V_6 -> V_9 , V_13 , & V_90 ) ;
if ( V_33 ) {
F_15 ( V_11 , L_29 , V_33 ) ;
goto V_96;
}
F_40 ( V_11 ) ;
F_41 ( V_11 ) ;
F_42 ( V_11 ) ;
V_33 = F_43 ( V_11 , & V_101 ,
& V_102 , 1 ) ;
if ( V_33 ) {
F_15 ( V_11 , L_30 , V_33 ) ;
goto V_103;
}
return 0 ;
V_103:
F_44 ( V_11 ) ;
V_96:
F_23 ( V_6 -> V_81 ) ;
return V_33 ;
}
static int F_45 ( struct V_82 * V_83 )
{
struct V_10 * V_11 = & V_83 -> V_11 ;
struct V_5 * V_6 = F_21 ( V_11 ) ;
F_46 ( V_11 ) ;
F_44 ( V_11 ) ;
F_23 ( V_6 -> V_81 ) ;
return 0 ;
}
