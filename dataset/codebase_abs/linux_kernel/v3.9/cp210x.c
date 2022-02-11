static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
T_2 * V_10 ;
int V_11 , V_12 , V_13 ;
V_13 = ( ( ( V_5 - 1 ) | 3 ) + 1 ) / 4 ;
V_10 = F_3 ( V_13 , sizeof( T_2 ) , V_14 ) ;
if ( ! V_10 ) {
F_4 ( & V_2 -> V_15 , L_1 , V_16 ) ;
return - V_17 ;
}
V_11 = F_5 ( V_7 -> V_15 , F_6 ( V_7 -> V_15 , 0 ) ,
V_3 , V_18 , 0x0000 ,
V_9 -> V_19 , V_10 , V_5 ,
V_20 ) ;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ )
V_4 [ V_12 ] = F_7 ( V_10 [ V_12 ] ) ;
F_8 ( V_10 ) ;
if ( V_11 != V_5 ) {
F_9 ( & V_2 -> V_15 , L_2 ,
V_16 , V_3 , V_5 , V_11 ) ;
if ( V_11 > 0 )
V_11 = - V_21 ;
return V_11 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
T_2 * V_10 ;
int V_11 , V_12 , V_13 ;
V_13 = ( ( ( V_5 - 1 ) | 3 ) + 1 ) / 4 ;
V_10 = F_11 ( V_13 * sizeof( T_2 ) , V_14 ) ;
if ( ! V_10 ) {
F_4 ( & V_2 -> V_15 , L_1 , V_16 ) ;
return - V_17 ;
}
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ )
V_10 [ V_12 ] = F_12 ( V_4 [ V_12 ] ) ;
if ( V_5 > 2 ) {
V_11 = F_5 ( V_7 -> V_15 ,
F_13 ( V_7 -> V_15 , 0 ) ,
V_3 , V_22 , 0x0000 ,
V_9 -> V_19 , V_10 , V_5 ,
V_23 ) ;
} else {
V_11 = F_5 ( V_7 -> V_15 ,
F_13 ( V_7 -> V_15 , 0 ) ,
V_3 , V_22 , V_4 [ 0 ] ,
V_9 -> V_19 , NULL , 0 ,
V_23 ) ;
}
F_8 ( V_10 ) ;
if ( ( V_5 > 2 && V_11 != V_5 ) || V_11 < 0 ) {
F_9 ( & V_2 -> V_15 , L_3 ,
V_16 , V_3 , V_5 , V_11 ) ;
if ( V_11 > 0 )
V_11 = - V_21 ;
return V_11 ;
}
return 0 ;
}
static inline int F_14 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 )
{
return F_10 ( V_2 , V_3 , & V_4 , 2 ) ;
}
static unsigned int F_15 ( unsigned int V_24 )
{
if ( V_24 <= 300 )
V_24 = 300 ;
else if ( V_24 <= 600 ) V_24 = 600 ;
else if ( V_24 <= 1200 ) V_24 = 1200 ;
else if ( V_24 <= 1800 ) V_24 = 1800 ;
else if ( V_24 <= 2400 ) V_24 = 2400 ;
else if ( V_24 <= 4000 ) V_24 = 4000 ;
else if ( V_24 <= 4803 ) V_24 = 4800 ;
else if ( V_24 <= 7207 ) V_24 = 7200 ;
else if ( V_24 <= 9612 ) V_24 = 9600 ;
else if ( V_24 <= 14428 ) V_24 = 14400 ;
else if ( V_24 <= 16062 ) V_24 = 16000 ;
else if ( V_24 <= 19250 ) V_24 = 19200 ;
else if ( V_24 <= 28912 ) V_24 = 28800 ;
else if ( V_24 <= 38601 ) V_24 = 38400 ;
else if ( V_24 <= 51558 ) V_24 = 51200 ;
else if ( V_24 <= 56280 ) V_24 = 56000 ;
else if ( V_24 <= 58053 ) V_24 = 57600 ;
else if ( V_24 <= 64111 ) V_24 = 64000 ;
else if ( V_24 <= 77608 ) V_24 = 76800 ;
else if ( V_24 <= 117028 ) V_24 = 115200 ;
else if ( V_24 <= 129347 ) V_24 = 128000 ;
else if ( V_24 <= 156868 ) V_24 = 153600 ;
else if ( V_24 <= 237832 ) V_24 = 230400 ;
else if ( V_24 <= 254234 ) V_24 = 250000 ;
else if ( V_24 <= 273066 ) V_24 = 256000 ;
else if ( V_24 <= 491520 ) V_24 = 460800 ;
else if ( V_24 <= 567138 ) V_24 = 500000 ;
else if ( V_24 <= 670254 ) V_24 = 576000 ;
else if ( V_24 < 1000000 )
V_24 = 921600 ;
else if ( V_24 > 2000000 )
V_24 = 2000000 ;
return V_24 ;
}
static int F_16 ( struct V_25 * V_26 , struct V_1 * V_2 )
{
int V_11 ;
V_11 = F_14 ( V_2 , V_27 ,
V_28 ) ;
if ( V_11 ) {
F_4 ( & V_2 -> V_15 , L_4 , V_16 ) ;
return V_11 ;
}
F_17 ( V_26 , V_2 ) ;
if ( V_26 )
F_18 ( V_26 , V_2 , NULL ) ;
return F_19 ( V_26 , V_2 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
F_22 ( & V_2 -> V_7 -> V_29 ) ;
if ( ! V_2 -> V_7 -> V_30 )
F_14 ( V_2 , V_27 , V_31 ) ;
F_23 ( & V_2 -> V_7 -> V_29 ) ;
}
static void F_17 ( struct V_25 * V_26 ,
struct V_1 * V_2 )
{
unsigned int V_24 ;
if ( V_26 ) {
F_24 ( V_26 -> V_32 ,
& V_26 -> V_33 . V_34 , & V_24 ) ;
F_25 ( V_26 , V_24 , V_24 ) ;
} else {
unsigned int V_35 ;
V_35 = 0 ;
F_24 ( V_2 , & V_35 , & V_24 ) ;
}
}
static void F_24 ( struct V_1 * V_2 ,
unsigned int * V_36 , unsigned int * V_37 )
{
struct V_38 * V_15 = & V_2 -> V_15 ;
unsigned int V_35 , V_39 [ 4 ] ;
unsigned int V_24 ;
unsigned int V_40 ;
F_1 ( V_2 , V_41 , & V_24 , 4 ) ;
F_9 ( V_15 , L_5 , V_16 , V_24 ) ;
* V_37 = V_24 ;
V_35 = * V_36 ;
F_1 ( V_2 , V_42 , & V_40 , 2 ) ;
V_35 &= ~ V_43 ;
switch ( V_40 & V_44 ) {
case V_45 :
F_9 ( V_15 , L_6 , V_16 ) ;
V_35 |= V_46 ;
break;
case V_47 :
F_9 ( V_15 , L_7 , V_16 ) ;
V_35 |= V_48 ;
break;
case V_49 :
F_9 ( V_15 , L_8 , V_16 ) ;
V_35 |= V_50 ;
break;
case V_51 :
F_9 ( V_15 , L_9 , V_16 ) ;
V_35 |= V_52 ;
break;
case V_53 :
F_9 ( V_15 , L_10 , V_16 ) ;
V_35 |= V_52 ;
V_40 &= ~ V_44 ;
V_40 |= V_51 ;
F_10 ( V_2 , V_54 , & V_40 , 2 ) ;
break;
default:
F_9 ( V_15 , L_11 , V_16 ) ;
V_35 |= V_52 ;
V_40 &= ~ V_44 ;
V_40 |= V_51 ;
F_10 ( V_2 , V_54 , & V_40 , 2 ) ;
break;
}
switch ( V_40 & V_55 ) {
case V_56 :
F_9 ( V_15 , L_12 , V_16 ) ;
V_35 &= ~ V_57 ;
break;
case V_58 :
F_9 ( V_15 , L_13 , V_16 ) ;
V_35 |= ( V_57 | V_59 ) ;
break;
case V_60 :
F_9 ( V_15 , L_14 , V_16 ) ;
V_35 &= ~ V_59 ;
V_35 |= V_57 ;
break;
case V_61 :
F_9 ( V_15 , L_15 , V_16 ) ;
V_35 |= ( V_57 | V_59 | V_62 ) ;
break;
case V_63 :
F_9 ( V_15 , L_16 , V_16 ) ;
V_35 &= ~ V_59 ;
V_35 |= ( V_57 | V_62 ) ;
break;
default:
F_9 ( V_15 , L_17 , V_16 ) ;
V_35 &= ~ V_57 ;
V_40 &= ~ V_55 ;
F_10 ( V_2 , V_54 , & V_40 , 2 ) ;
break;
}
V_35 &= ~ V_64 ;
switch ( V_40 & V_65 ) {
case V_66 :
F_9 ( V_15 , L_18 , V_16 ) ;
break;
case V_67 :
F_9 ( V_15 , L_19 , V_16 ) ;
V_40 &= ~ V_65 ;
F_10 ( V_2 , V_54 , & V_40 , 2 ) ;
break;
case V_68 :
F_9 ( V_15 , L_20 , V_16 ) ;
V_35 |= V_64 ;
break;
default:
F_9 ( V_15 , L_21 , V_16 ) ;
V_40 &= ~ V_65 ;
F_10 ( V_2 , V_54 , & V_40 , 2 ) ;
break;
}
F_1 ( V_2 , V_69 , V_39 , 16 ) ;
if ( V_39 [ 0 ] & 0x0008 ) {
F_9 ( V_15 , L_22 , V_16 ) ;
V_35 |= V_70 ;
} else {
F_9 ( V_15 , L_23 , V_16 ) ;
V_35 &= ~ V_70 ;
}
* V_36 = V_35 ;
}
static void F_18 ( struct V_25 * V_26 ,
struct V_1 * V_2 , struct V_71 * V_72 )
{
T_3 V_24 ;
V_24 = V_26 -> V_33 . V_73 ;
V_24 = F_15 ( V_24 ) ;
F_9 ( & V_2 -> V_15 , L_24 , V_16 , V_24 ) ;
if ( F_10 ( V_2 , V_74 , & V_24 ,
sizeof( V_24 ) ) ) {
F_26 ( & V_2 -> V_15 , L_25 , V_24 ) ;
if ( V_72 )
V_24 = V_72 -> V_73 ;
else
V_24 = 9600 ;
}
F_25 ( V_26 , V_24 , V_24 ) ;
}
static void F_27 ( struct V_25 * V_26 ,
struct V_1 * V_2 , struct V_71 * V_72 )
{
struct V_38 * V_15 = & V_2 -> V_15 ;
unsigned int V_35 , V_75 ;
unsigned int V_40 ;
unsigned int V_39 [ 4 ] ;
F_9 ( V_15 , L_26 , V_16 , V_2 -> V_76 ) ;
if ( ! V_26 )
return;
V_35 = V_26 -> V_33 . V_34 ;
V_75 = V_72 -> V_34 ;
if ( V_26 -> V_33 . V_73 != V_72 -> V_73 )
F_18 ( V_26 , V_2 , V_72 ) ;
if ( ( V_35 & V_43 ) != ( V_75 & V_43 ) ) {
F_1 ( V_2 , V_42 , & V_40 , 2 ) ;
V_40 &= ~ V_44 ;
switch ( V_35 & V_43 ) {
case V_46 :
V_40 |= V_45 ;
F_9 ( V_15 , L_6 , V_16 ) ;
break;
case V_48 :
V_40 |= V_47 ;
F_9 ( V_15 , L_7 , V_16 ) ;
break;
case V_50 :
V_40 |= V_49 ;
F_9 ( V_15 , L_8 , V_16 ) ;
break;
case V_52 :
V_40 |= V_51 ;
F_9 ( V_15 , L_9 , V_16 ) ;
break;
default:
F_9 ( V_15 , L_27 ) ;
V_40 |= V_51 ;
break;
}
if ( F_10 ( V_2 , V_54 , & V_40 , 2 ) )
F_9 ( V_15 , L_28 ) ;
}
if ( ( V_35 & ( V_57 | V_59 | V_62 ) ) !=
( V_75 & ( V_57 | V_59 | V_62 ) ) ) {
F_1 ( V_2 , V_42 , & V_40 , 2 ) ;
V_40 &= ~ V_55 ;
if ( V_35 & V_57 ) {
if ( V_35 & V_62 ) {
if ( V_35 & V_59 ) {
V_40 |= V_61 ;
F_9 ( V_15 , L_15 , V_16 ) ;
} else {
V_40 |= V_63 ;
F_9 ( V_15 , L_16 , V_16 ) ;
}
} else {
if ( V_35 & V_59 ) {
V_40 |= V_58 ;
F_9 ( V_15 , L_13 , V_16 ) ;
} else {
V_40 |= V_60 ;
F_9 ( V_15 , L_14 , V_16 ) ;
}
}
}
if ( F_10 ( V_2 , V_54 , & V_40 , 2 ) )
F_9 ( V_15 , L_29 ) ;
}
if ( ( V_35 & V_64 ) != ( V_75 & V_64 ) ) {
F_1 ( V_2 , V_42 , & V_40 , 2 ) ;
V_40 &= ~ V_65 ;
if ( V_35 & V_64 ) {
V_40 |= V_68 ;
F_9 ( V_15 , L_20 , V_16 ) ;
} else {
V_40 |= V_66 ;
F_9 ( V_15 , L_18 , V_16 ) ;
}
if ( F_10 ( V_2 , V_54 , & V_40 , 2 ) )
F_9 ( V_15 , L_30 ) ;
}
if ( ( V_35 & V_70 ) != ( V_75 & V_70 ) ) {
F_1 ( V_2 , V_69 , V_39 , 16 ) ;
F_9 ( V_15 , L_31 ,
V_16 , V_39 [ 0 ] , V_39 [ 1 ] ,
V_39 [ 2 ] , V_39 [ 3 ] ) ;
if ( V_35 & V_70 ) {
V_39 [ 0 ] &= ~ 0x7B ;
V_39 [ 0 ] |= 0x09 ;
V_39 [ 1 ] = 0x80 ;
F_9 ( V_15 , L_22 , V_16 ) ;
} else {
V_39 [ 0 ] &= ~ 0x7B ;
V_39 [ 0 ] |= 0x01 ;
V_39 [ 1 ] |= 0x40 ;
F_9 ( V_15 , L_23 , V_16 ) ;
}
F_9 ( V_15 , L_32 ,
V_16 , V_39 [ 0 ] , V_39 [ 1 ] ,
V_39 [ 2 ] , V_39 [ 3 ] ) ;
F_10 ( V_2 , V_77 , V_39 , 16 ) ;
}
}
static int F_28 ( struct V_25 * V_26 ,
unsigned int V_78 , unsigned int V_79 )
{
struct V_1 * V_2 = V_26 -> V_32 ;
return F_29 ( V_2 , V_78 , V_79 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
unsigned int V_78 , unsigned int V_79 )
{
unsigned int V_80 = 0 ;
if ( V_78 & V_81 ) {
V_80 |= V_82 ;
V_80 |= V_83 ;
}
if ( V_78 & V_84 ) {
V_80 |= V_85 ;
V_80 |= V_86 ;
}
if ( V_79 & V_81 ) {
V_80 &= ~ V_82 ;
V_80 |= V_83 ;
}
if ( V_79 & V_84 ) {
V_80 &= ~ V_85 ;
V_80 |= V_86 ;
}
F_9 ( & V_2 -> V_15 , L_33 , V_16 , V_80 ) ;
return F_10 ( V_2 , V_87 , & V_80 , 2 ) ;
}
static void F_30 ( struct V_1 * V_88 , int V_89 )
{
if ( V_89 )
F_29 ( V_88 , V_84 | V_81 , 0 ) ;
else
F_29 ( V_88 , 0 , V_84 | V_81 ) ;
}
static int F_31 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_32 ;
unsigned int V_80 ;
int V_11 ;
F_1 ( V_2 , V_90 , & V_80 , 1 ) ;
V_11 = ( ( V_80 & V_85 ) ? V_84 : 0 )
| ( ( V_80 & V_82 ) ? V_81 : 0 )
| ( ( V_80 & V_91 ) ? V_92 : 0 )
| ( ( V_80 & V_93 ) ? V_94 : 0 )
| ( ( V_80 & V_95 ) ? V_96 : 0 )
| ( ( V_80 & V_97 ) ? V_98 : 0 ) ;
F_9 ( & V_2 -> V_15 , L_34 , V_16 , V_80 ) ;
return V_11 ;
}
static void F_32 ( struct V_25 * V_26 , int V_99 )
{
struct V_1 * V_2 = V_26 -> V_32 ;
unsigned int V_100 ;
if ( V_99 == 0 )
V_100 = V_101 ;
else
V_100 = V_102 ;
F_9 ( & V_2 -> V_15 , L_35 , V_16 ,
V_100 == V_101 ? L_36 : L_37 ) ;
F_10 ( V_2 , V_103 , & V_100 , 2 ) ;
}
static int F_33 ( struct V_6 * V_7 )
{
struct V_104 * V_105 ;
struct V_8 * V_9 ;
F_34 ( V_7 -> V_15 ) ;
V_9 = F_35 ( sizeof( * V_9 ) , V_14 ) ;
if ( ! V_9 )
return - V_17 ;
V_105 = V_7 -> V_106 -> V_105 ;
V_9 -> V_19 = V_105 -> V_107 . V_19 ;
F_36 ( V_7 , V_9 ) ;
return 0 ;
}
static void F_37 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
V_9 = F_2 ( V_7 ) ;
F_8 ( V_9 ) ;
}
