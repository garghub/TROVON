static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
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
F_9 ( L_2
L_3 ,
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
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_2 * V_10 ;
int V_11 , V_12 , V_13 ;
V_13 = ( ( ( V_5 - 1 ) | 3 ) + 1 ) / 4 ;
V_10 = F_11 ( V_13 * sizeof( T_2 ) , V_14 ) ;
if ( ! V_10 ) {
F_4 ( & V_2 -> V_15 , L_1 ,
V_16 ) ;
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
F_9 ( L_4
L_3 ,
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
static unsigned int F_15 ( unsigned int V_24 ) {
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
F_4 ( & V_2 -> V_15 , L_5 , V_16 ) ;
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
& V_26 -> V_33 -> V_34 , & V_24 ) ;
F_25 ( V_26 , V_24 , V_24 ) ;
}
else {
unsigned int V_35 ;
V_35 = 0 ;
F_24 ( V_2 , & V_35 , & V_24 ) ;
}
}
static void F_24 ( struct V_1 * V_2 ,
unsigned int * V_36 , unsigned int * V_37 )
{
unsigned int V_35 , V_38 [ 4 ] ;
unsigned int V_24 ;
unsigned int V_39 ;
F_1 ( V_2 , V_40 , & V_24 , 4 ) ;
F_9 ( L_6 , V_16 , V_24 ) ;
* V_37 = V_24 ;
V_35 = * V_36 ;
F_1 ( V_2 , V_41 , & V_39 , 2 ) ;
V_35 &= ~ V_42 ;
switch ( V_39 & V_43 ) {
case V_44 :
F_9 ( L_7 , V_16 ) ;
V_35 |= V_45 ;
break;
case V_46 :
F_9 ( L_8 , V_16 ) ;
V_35 |= V_47 ;
break;
case V_48 :
F_9 ( L_9 , V_16 ) ;
V_35 |= V_49 ;
break;
case V_50 :
F_9 ( L_10 , V_16 ) ;
V_35 |= V_51 ;
break;
case V_52 :
F_9 ( L_11 ,
V_16 ) ;
V_35 |= V_51 ;
V_39 &= ~ V_43 ;
V_39 |= V_50 ;
F_10 ( V_2 , V_53 , & V_39 , 2 ) ;
break;
default:
F_9 ( L_12 , V_16 ) ;
V_35 |= V_51 ;
V_39 &= ~ V_43 ;
V_39 |= V_50 ;
F_10 ( V_2 , V_53 , & V_39 , 2 ) ;
break;
}
switch ( V_39 & V_54 ) {
case V_55 :
F_9 ( L_13 , V_16 ) ;
V_35 &= ~ V_56 ;
break;
case V_57 :
F_9 ( L_14 , V_16 ) ;
V_35 |= ( V_56 | V_58 ) ;
break;
case V_59 :
F_9 ( L_15 , V_16 ) ;
V_35 &= ~ V_58 ;
V_35 |= V_56 ;
break;
case V_60 :
F_9 ( L_16 , V_16 ) ;
V_35 |= ( V_56 | V_58 | V_61 ) ;
break;
case V_62 :
F_9 ( L_17 , V_16 ) ;
V_35 &= ~ V_58 ;
V_35 |= ( V_56 | V_61 ) ;
break;
default:
F_9 ( L_18 , V_16 ) ;
V_35 &= ~ V_56 ;
V_39 &= ~ V_54 ;
F_10 ( V_2 , V_53 , & V_39 , 2 ) ;
break;
}
V_35 &= ~ V_63 ;
switch ( V_39 & V_64 ) {
case V_65 :
F_9 ( L_19 , V_16 ) ;
break;
case V_66 :
F_9 ( L_20 ,
V_16 ) ;
V_39 &= ~ V_64 ;
F_10 ( V_2 , V_53 , & V_39 , 2 ) ;
break;
case V_67 :
F_9 ( L_21 , V_16 ) ;
V_35 |= V_63 ;
break;
default:
F_9 ( L_22 ,
V_16 ) ;
V_39 &= ~ V_64 ;
F_10 ( V_2 , V_53 , & V_39 , 2 ) ;
break;
}
F_1 ( V_2 , V_68 , V_38 , 16 ) ;
if ( V_38 [ 0 ] & 0x0008 ) {
F_9 ( L_23 , V_16 ) ;
V_35 |= V_69 ;
} else {
F_9 ( L_24 , V_16 ) ;
V_35 &= ~ V_69 ;
}
* V_36 = V_35 ;
}
static void F_18 ( struct V_25 * V_26 ,
struct V_1 * V_2 , struct V_70 * V_71 )
{
T_3 V_24 ;
V_24 = V_26 -> V_33 -> V_72 ;
V_24 = F_15 ( V_24 ) ;
F_9 ( L_25 , V_16 , V_24 ) ;
if ( F_10 ( V_2 , V_73 , & V_24 ,
sizeof( V_24 ) ) ) {
F_26 ( & V_2 -> V_15 , L_26 , V_24 ) ;
if ( V_71 )
V_24 = V_71 -> V_72 ;
else
V_24 = 9600 ;
}
F_25 ( V_26 , V_24 , V_24 ) ;
}
static void F_27 ( struct V_25 * V_26 ,
struct V_1 * V_2 , struct V_70 * V_71 )
{
unsigned int V_35 , V_74 ;
unsigned int V_39 ;
unsigned int V_38 [ 4 ] ;
F_9 ( L_27 , V_16 , V_2 -> V_75 ) ;
if ( ! V_26 )
return;
V_35 = V_26 -> V_33 -> V_34 ;
V_74 = V_71 -> V_34 ;
if ( V_26 -> V_33 -> V_72 != V_71 -> V_72 )
F_18 ( V_26 , V_2 , V_71 ) ;
if ( ( V_35 & V_42 ) != ( V_74 & V_42 ) ) {
F_1 ( V_2 , V_41 , & V_39 , 2 ) ;
V_39 &= ~ V_43 ;
switch ( V_35 & V_42 ) {
case V_45 :
V_39 |= V_44 ;
F_9 ( L_7 , V_16 ) ;
break;
case V_47 :
V_39 |= V_46 ;
F_9 ( L_8 , V_16 ) ;
break;
case V_49 :
V_39 |= V_48 ;
F_9 ( L_9 , V_16 ) ;
break;
case V_51 :
V_39 |= V_50 ;
F_9 ( L_10 , V_16 ) ;
break;
default:
F_9 ( L_28
L_29
L_30 ) ;
V_39 |= V_50 ;
break;
}
if ( F_10 ( V_2 , V_53 , & V_39 , 2 ) )
F_9 ( L_31
L_32 ) ;
}
if ( ( V_35 & ( V_56 | V_58 | V_61 ) ) !=
( V_74 & ( V_56 | V_58 | V_61 ) ) ) {
F_1 ( V_2 , V_41 , & V_39 , 2 ) ;
V_39 &= ~ V_54 ;
if ( V_35 & V_56 ) {
if ( V_35 & V_61 ) {
if ( V_35 & V_58 ) {
V_39 |= V_60 ;
F_9 ( L_16 , V_16 ) ;
} else {
V_39 |= V_62 ;
F_9 ( L_17 , V_16 ) ;
}
} else {
if ( V_35 & V_58 ) {
V_39 |= V_57 ;
F_9 ( L_14 , V_16 ) ;
} else {
V_39 |= V_59 ;
F_9 ( L_15 , V_16 ) ;
}
}
}
if ( F_10 ( V_2 , V_53 , & V_39 , 2 ) )
F_9 ( L_33 ) ;
}
if ( ( V_35 & V_63 ) != ( V_74 & V_63 ) ) {
F_1 ( V_2 , V_41 , & V_39 , 2 ) ;
V_39 &= ~ V_64 ;
if ( V_35 & V_63 ) {
V_39 |= V_67 ;
F_9 ( L_21 , V_16 ) ;
} else {
V_39 |= V_65 ;
F_9 ( L_19 , V_16 ) ;
}
if ( F_10 ( V_2 , V_53 , & V_39 , 2 ) )
F_9 ( L_34
L_32 ) ;
}
if ( ( V_35 & V_69 ) != ( V_74 & V_69 ) ) {
F_1 ( V_2 , V_68 , V_38 , 16 ) ;
F_9 ( L_35 ,
V_16 , V_38 [ 0 ] , V_38 [ 1 ] ,
V_38 [ 2 ] , V_38 [ 3 ] ) ;
if ( V_35 & V_69 ) {
V_38 [ 0 ] &= ~ 0x7B ;
V_38 [ 0 ] |= 0x09 ;
V_38 [ 1 ] = 0x80 ;
F_9 ( L_23 , V_16 ) ;
} else {
V_38 [ 0 ] &= ~ 0x7B ;
V_38 [ 0 ] |= 0x01 ;
V_38 [ 1 ] |= 0x40 ;
F_9 ( L_24 , V_16 ) ;
}
F_9 ( L_36 ,
V_16 , V_38 [ 0 ] , V_38 [ 1 ] ,
V_38 [ 2 ] , V_38 [ 3 ] ) ;
F_10 ( V_2 , V_76 , V_38 , 16 ) ;
}
}
static int F_28 ( struct V_25 * V_26 ,
unsigned int V_77 , unsigned int V_78 )
{
struct V_1 * V_2 = V_26 -> V_32 ;
return F_29 ( V_2 , V_77 , V_78 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
unsigned int V_77 , unsigned int V_78 )
{
unsigned int V_79 = 0 ;
if ( V_77 & V_80 ) {
V_79 |= V_81 ;
V_79 |= V_82 ;
}
if ( V_77 & V_83 ) {
V_79 |= V_84 ;
V_79 |= V_85 ;
}
if ( V_78 & V_80 ) {
V_79 &= ~ V_81 ;
V_79 |= V_82 ;
}
if ( V_78 & V_83 ) {
V_79 &= ~ V_84 ;
V_79 |= V_85 ;
}
F_9 ( L_37 , V_16 , V_79 ) ;
return F_10 ( V_2 , V_86 , & V_79 , 2 ) ;
}
static void F_30 ( struct V_1 * V_87 , int V_88 )
{
if ( V_88 )
F_29 ( V_87 , V_83 | V_80 , 0 ) ;
else
F_29 ( V_87 , 0 , V_83 | V_80 ) ;
}
static int F_31 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_32 ;
unsigned int V_79 ;
int V_11 ;
F_1 ( V_2 , V_89 , & V_79 , 1 ) ;
V_11 = ( ( V_79 & V_84 ) ? V_83 : 0 )
| ( ( V_79 & V_81 ) ? V_80 : 0 )
| ( ( V_79 & V_90 ) ? V_91 : 0 )
| ( ( V_79 & V_92 ) ? V_93 : 0 )
| ( ( V_79 & V_94 ) ? V_95 : 0 )
| ( ( V_79 & V_96 ) ? V_97 : 0 ) ;
F_9 ( L_38 , V_16 , V_79 ) ;
return V_11 ;
}
static void F_32 ( struct V_25 * V_26 , int V_98 )
{
struct V_1 * V_2 = V_26 -> V_32 ;
unsigned int V_99 ;
if ( V_98 == 0 )
V_99 = V_100 ;
else
V_99 = V_101 ;
F_9 ( L_39 , V_16 ,
V_99 == V_100 ? L_40 : L_41 ) ;
F_10 ( V_2 , V_102 , & V_99 , 2 ) ;
}
static int F_33 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
int V_12 ;
F_34 ( V_7 -> V_15 ) ;
for ( V_12 = 0 ; V_12 < V_7 -> V_103 ; V_12 ++ ) {
V_9 = F_35 ( sizeof( * V_9 ) , V_14 ) ;
if ( ! V_9 )
return - V_17 ;
memset ( V_9 , 0x00 , sizeof( * V_9 ) ) ;
V_9 -> V_19 =
V_7 -> V_104 -> V_105 -> V_106 . V_19 ;
F_36 ( V_7 -> V_2 [ V_12 ] , V_9 ) ;
}
return 0 ;
}
static void F_37 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_103 ; V_12 ++ ) {
V_9 = F_2 ( V_7 -> V_2 [ V_12 ] ) ;
F_8 ( V_9 ) ;
F_36 ( V_7 -> V_2 [ V_12 ] , NULL ) ;
}
}
