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
F_14 ( V_2 , V_27 , V_29 ) ;
}
static void F_17 ( struct V_25 * V_26 ,
struct V_1 * V_2 )
{
unsigned int V_24 ;
if ( V_26 ) {
F_22 ( V_26 -> V_30 ,
& V_26 -> V_31 . V_32 , & V_24 ) ;
F_23 ( V_26 , V_24 , V_24 ) ;
} else {
unsigned int V_33 ;
V_33 = 0 ;
F_22 ( V_2 , & V_33 , & V_24 ) ;
}
}
static void F_22 ( struct V_1 * V_2 ,
unsigned int * V_34 , unsigned int * V_35 )
{
struct V_36 * V_15 = & V_2 -> V_15 ;
unsigned int V_33 , V_37 [ 4 ] ;
unsigned int V_24 ;
unsigned int V_38 ;
F_1 ( V_2 , V_39 , & V_24 , 4 ) ;
F_9 ( V_15 , L_5 , V_16 , V_24 ) ;
* V_35 = V_24 ;
V_33 = * V_34 ;
F_1 ( V_2 , V_40 , & V_38 , 2 ) ;
V_33 &= ~ V_41 ;
switch ( V_38 & V_42 ) {
case V_43 :
F_9 ( V_15 , L_6 , V_16 ) ;
V_33 |= V_44 ;
break;
case V_45 :
F_9 ( V_15 , L_7 , V_16 ) ;
V_33 |= V_46 ;
break;
case V_47 :
F_9 ( V_15 , L_8 , V_16 ) ;
V_33 |= V_48 ;
break;
case V_49 :
F_9 ( V_15 , L_9 , V_16 ) ;
V_33 |= V_50 ;
break;
case V_51 :
F_9 ( V_15 , L_10 , V_16 ) ;
V_33 |= V_50 ;
V_38 &= ~ V_42 ;
V_38 |= V_49 ;
F_10 ( V_2 , V_52 , & V_38 , 2 ) ;
break;
default:
F_9 ( V_15 , L_11 , V_16 ) ;
V_33 |= V_50 ;
V_38 &= ~ V_42 ;
V_38 |= V_49 ;
F_10 ( V_2 , V_52 , & V_38 , 2 ) ;
break;
}
switch ( V_38 & V_53 ) {
case V_54 :
F_9 ( V_15 , L_12 , V_16 ) ;
V_33 &= ~ V_55 ;
break;
case V_56 :
F_9 ( V_15 , L_13 , V_16 ) ;
V_33 |= ( V_55 | V_57 ) ;
break;
case V_58 :
F_9 ( V_15 , L_14 , V_16 ) ;
V_33 &= ~ V_57 ;
V_33 |= V_55 ;
break;
case V_59 :
F_9 ( V_15 , L_15 , V_16 ) ;
V_33 |= ( V_55 | V_57 | V_60 ) ;
break;
case V_61 :
F_9 ( V_15 , L_16 , V_16 ) ;
V_33 &= ~ V_57 ;
V_33 |= ( V_55 | V_60 ) ;
break;
default:
F_9 ( V_15 , L_17 , V_16 ) ;
V_33 &= ~ V_55 ;
V_38 &= ~ V_53 ;
F_10 ( V_2 , V_52 , & V_38 , 2 ) ;
break;
}
V_33 &= ~ V_62 ;
switch ( V_38 & V_63 ) {
case V_64 :
F_9 ( V_15 , L_18 , V_16 ) ;
break;
case V_65 :
F_9 ( V_15 , L_19 , V_16 ) ;
V_38 &= ~ V_63 ;
F_10 ( V_2 , V_52 , & V_38 , 2 ) ;
break;
case V_66 :
F_9 ( V_15 , L_20 , V_16 ) ;
V_33 |= V_62 ;
break;
default:
F_9 ( V_15 , L_21 , V_16 ) ;
V_38 &= ~ V_63 ;
F_10 ( V_2 , V_52 , & V_38 , 2 ) ;
break;
}
F_1 ( V_2 , V_67 , V_37 , 16 ) ;
if ( V_37 [ 0 ] & 0x0008 ) {
F_9 ( V_15 , L_22 , V_16 ) ;
V_33 |= V_68 ;
} else {
F_9 ( V_15 , L_23 , V_16 ) ;
V_33 &= ~ V_68 ;
}
* V_34 = V_33 ;
}
static void F_18 ( struct V_25 * V_26 ,
struct V_1 * V_2 , struct V_69 * V_70 )
{
T_3 V_24 ;
V_24 = V_26 -> V_31 . V_71 ;
V_24 = F_15 ( V_24 ) ;
F_9 ( & V_2 -> V_15 , L_24 , V_16 , V_24 ) ;
if ( F_10 ( V_2 , V_72 , & V_24 ,
sizeof( V_24 ) ) ) {
F_24 ( & V_2 -> V_15 , L_25 , V_24 ) ;
if ( V_70 )
V_24 = V_70 -> V_71 ;
else
V_24 = 9600 ;
}
F_23 ( V_26 , V_24 , V_24 ) ;
}
static void F_25 ( struct V_25 * V_26 ,
struct V_1 * V_2 , struct V_69 * V_70 )
{
struct V_36 * V_15 = & V_2 -> V_15 ;
unsigned int V_33 , V_73 ;
unsigned int V_38 ;
unsigned int V_37 [ 4 ] ;
V_33 = V_26 -> V_31 . V_32 ;
V_73 = V_70 -> V_32 ;
if ( V_26 -> V_31 . V_71 != V_70 -> V_71 )
F_18 ( V_26 , V_2 , V_70 ) ;
if ( ( V_33 & V_41 ) != ( V_73 & V_41 ) ) {
F_1 ( V_2 , V_40 , & V_38 , 2 ) ;
V_38 &= ~ V_42 ;
switch ( V_33 & V_41 ) {
case V_44 :
V_38 |= V_43 ;
F_9 ( V_15 , L_6 , V_16 ) ;
break;
case V_46 :
V_38 |= V_45 ;
F_9 ( V_15 , L_7 , V_16 ) ;
break;
case V_48 :
V_38 |= V_47 ;
F_9 ( V_15 , L_8 , V_16 ) ;
break;
case V_50 :
V_38 |= V_49 ;
F_9 ( V_15 , L_9 , V_16 ) ;
break;
default:
F_9 ( V_15 , L_26 ) ;
V_38 |= V_49 ;
break;
}
if ( F_10 ( V_2 , V_52 , & V_38 , 2 ) )
F_9 ( V_15 , L_27 ) ;
}
if ( ( V_33 & ( V_55 | V_57 | V_60 ) ) !=
( V_73 & ( V_55 | V_57 | V_60 ) ) ) {
F_1 ( V_2 , V_40 , & V_38 , 2 ) ;
V_38 &= ~ V_53 ;
if ( V_33 & V_55 ) {
if ( V_33 & V_60 ) {
if ( V_33 & V_57 ) {
V_38 |= V_59 ;
F_9 ( V_15 , L_15 , V_16 ) ;
} else {
V_38 |= V_61 ;
F_9 ( V_15 , L_16 , V_16 ) ;
}
} else {
if ( V_33 & V_57 ) {
V_38 |= V_56 ;
F_9 ( V_15 , L_13 , V_16 ) ;
} else {
V_38 |= V_58 ;
F_9 ( V_15 , L_14 , V_16 ) ;
}
}
}
if ( F_10 ( V_2 , V_52 , & V_38 , 2 ) )
F_9 ( V_15 , L_28 ) ;
}
if ( ( V_33 & V_62 ) != ( V_73 & V_62 ) ) {
F_1 ( V_2 , V_40 , & V_38 , 2 ) ;
V_38 &= ~ V_63 ;
if ( V_33 & V_62 ) {
V_38 |= V_66 ;
F_9 ( V_15 , L_20 , V_16 ) ;
} else {
V_38 |= V_64 ;
F_9 ( V_15 , L_18 , V_16 ) ;
}
if ( F_10 ( V_2 , V_52 , & V_38 , 2 ) )
F_9 ( V_15 , L_29 ) ;
}
if ( ( V_33 & V_68 ) != ( V_73 & V_68 ) ) {
F_1 ( V_2 , V_67 , V_37 , 16 ) ;
F_9 ( V_15 , L_30 ,
V_16 , V_37 [ 0 ] , V_37 [ 1 ] ,
V_37 [ 2 ] , V_37 [ 3 ] ) ;
if ( V_33 & V_68 ) {
V_37 [ 0 ] &= ~ 0x7B ;
V_37 [ 0 ] |= 0x09 ;
V_37 [ 1 ] = 0x80 ;
F_9 ( V_15 , L_22 , V_16 ) ;
} else {
V_37 [ 0 ] &= ~ 0x7B ;
V_37 [ 0 ] |= 0x01 ;
V_37 [ 1 ] |= 0x40 ;
F_9 ( V_15 , L_23 , V_16 ) ;
}
F_9 ( V_15 , L_31 ,
V_16 , V_37 [ 0 ] , V_37 [ 1 ] ,
V_37 [ 2 ] , V_37 [ 3 ] ) ;
F_10 ( V_2 , V_74 , V_37 , 16 ) ;
}
}
static int F_26 ( struct V_25 * V_26 ,
unsigned int V_75 , unsigned int V_76 )
{
struct V_1 * V_2 = V_26 -> V_30 ;
return F_27 ( V_2 , V_75 , V_76 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
unsigned int V_75 , unsigned int V_76 )
{
unsigned int V_77 = 0 ;
if ( V_75 & V_78 ) {
V_77 |= V_79 ;
V_77 |= V_80 ;
}
if ( V_75 & V_81 ) {
V_77 |= V_82 ;
V_77 |= V_83 ;
}
if ( V_76 & V_78 ) {
V_77 &= ~ V_79 ;
V_77 |= V_80 ;
}
if ( V_76 & V_81 ) {
V_77 &= ~ V_82 ;
V_77 |= V_83 ;
}
F_9 ( & V_2 -> V_15 , L_32 , V_16 , V_77 ) ;
return F_10 ( V_2 , V_84 , & V_77 , 2 ) ;
}
static void F_28 ( struct V_1 * V_85 , int V_86 )
{
if ( V_86 )
F_27 ( V_85 , V_81 | V_78 , 0 ) ;
else
F_27 ( V_85 , 0 , V_81 | V_78 ) ;
}
static int F_29 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_30 ;
unsigned int V_77 ;
int V_11 ;
F_1 ( V_2 , V_87 , & V_77 , 1 ) ;
V_11 = ( ( V_77 & V_82 ) ? V_81 : 0 )
| ( ( V_77 & V_79 ) ? V_78 : 0 )
| ( ( V_77 & V_88 ) ? V_89 : 0 )
| ( ( V_77 & V_90 ) ? V_91 : 0 )
| ( ( V_77 & V_92 ) ? V_93 : 0 )
| ( ( V_77 & V_94 ) ? V_95 : 0 ) ;
F_9 ( & V_2 -> V_15 , L_33 , V_16 , V_77 ) ;
return V_11 ;
}
static void F_30 ( struct V_25 * V_26 , int V_96 )
{
struct V_1 * V_2 = V_26 -> V_30 ;
unsigned int V_97 ;
if ( V_96 == 0 )
V_97 = V_98 ;
else
V_97 = V_99 ;
F_9 ( & V_2 -> V_15 , L_34 , V_16 ,
V_97 == V_98 ? L_35 : L_36 ) ;
F_10 ( V_2 , V_100 , & V_97 , 2 ) ;
}
static int F_31 ( struct V_6 * V_7 )
{
struct V_101 * V_102 ;
struct V_8 * V_9 ;
F_32 ( V_7 -> V_15 ) ;
V_9 = F_33 ( sizeof( * V_9 ) , V_14 ) ;
if ( ! V_9 )
return - V_17 ;
V_102 = V_7 -> V_103 -> V_102 ;
V_9 -> V_19 = V_102 -> V_104 . V_19 ;
F_34 ( V_7 , V_9 ) ;
return 0 ;
}
static void F_35 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
V_9 = F_2 ( V_7 ) ;
F_8 ( V_9 ) ;
}
