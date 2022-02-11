static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_3 , 0 , 0x20 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = F_2 ( V_3 , 0x20 , 0x20 ) ;
if ( ! V_4 )
V_4 = F_2 ( V_5 , 0 , 0x05 ) ;
return V_4 ;
}
static int F_4 ( T_1 V_6 , T_1 V_7 , T_1 * V_8 , T_1 * V_9 )
{
int V_4 ;
T_1 V_10 ;
T_2 V_11 ;
V_10 = V_12 + V_6 ;
if ( V_7 == V_13 )
V_10 += 4 ;
V_4 = F_5 ( V_10 , & V_11 ) ;
if ( V_4 )
return V_4 ;
* V_8 = ( V_11 & 0xFF ) << 3 ;
* V_8 |= ( V_11 >> 8 ) & 0x07 ;
* V_8 &= 0x3FF ;
V_11 >>= 16 ;
* V_9 = ( V_11 & 0xFF ) << 3 ;
* V_9 |= ( V_11 >> 8 ) & 0x07 ;
* V_9 &= 0x3FF ;
return 0 ;
}
static int F_6 ( T_3 V_6 , T_3 V_14 )
{
int V_15 ;
T_1 V_7 , V_16 ;
T_1 V_17 [ 4 ] ;
T_4 V_18 [ 4 ] ;
V_7 = V_19 + V_6 ;
V_16 = V_20 ;
for ( V_15 = 0 ; V_15 <= 3 ; V_15 ++ ) {
V_17 [ V_15 ] = V_7 ++ ;
V_18 [ V_15 ] = V_14 | ( V_16 + V_15 ) ;
}
return F_7 ( V_17 , V_18 , 4 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
T_1 * V_21 , T_1 * V_22 , T_1 * V_23 )
{
int V_4 ;
T_1 V_24 , V_25 , V_26 ;
V_4 = F_6 ( V_2 -> V_27 , V_28 ) ;
if ( V_4 )
goto V_29;
F_9 ( V_30 ) ;
V_4 = F_4 ( V_2 -> V_27 , V_20 , V_21 , & V_24 ) ;
if ( V_4 )
goto V_29;
V_4 = F_6 ( V_2 -> V_27 , V_31 ) ;
if ( V_4 )
goto V_29;
F_9 ( V_30 ) ;
V_4 = F_4 ( V_2 -> V_27 , V_13 , V_22 , & V_25 ) ;
if ( V_4 )
goto V_29;
V_4 = F_6 ( V_2 -> V_27 , V_32 ) ;
if ( V_4 )
goto V_29;
F_9 ( V_30 ) ;
V_4 = F_4 ( V_2 -> V_27 , V_20 , V_23 , & V_26 ) ;
if ( V_4 )
goto V_29;
return 0 ;
V_29:
F_10 ( V_2 -> V_33 , L_1 ) ;
return V_4 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_4 , V_15 ;
T_1 V_7 ;
T_1 V_17 [ 5 ] ;
T_4 V_18 [ 5 ] ;
V_4 = F_2 ( V_3 , 0x00 , 0x02 ) ;
if ( V_4 )
goto V_29;
V_7 = V_19 + V_2 -> V_27 ;
for ( V_15 = 0 ; V_15 <= 3 ; V_15 ++ ) {
V_17 [ V_15 ] = V_7 ++ ;
V_18 [ V_15 ] = 0x2A ;
}
V_17 [ V_15 ] = V_7 ++ ;
V_18 [ V_15 ] = 0 ;
V_4 = F_7 ( V_17 , V_18 , 5 ) ;
if ( V_4 )
goto V_29;
F_9 ( V_30 ) ;
for ( V_15 = 0 ; V_15 <= 3 ; V_15 ++ ) {
V_17 [ V_15 ] = V_7 ++ ;
V_18 [ V_15 ] = 0x4A ;
}
V_17 [ V_15 ] = V_7 ++ ;
V_18 [ V_15 ] = 0 ;
V_4 = F_7 ( V_17 , V_18 , 5 ) ;
if ( V_4 )
goto V_29;
F_9 ( V_30 ) ;
V_4 = F_12 ( V_7 + 2 , 0x8A8A8A8A ) ;
if ( V_4 )
goto V_29;
F_9 ( V_30 ) ;
return 0 ;
V_29:
F_10 ( V_2 -> V_33 , L_2 , V_34 ) ;
return V_4 ;
}
static int F_13 ( struct V_1 * V_2 ,
T_1 * V_21 , T_1 * V_22 , T_1 * V_23 )
{
int V_4 ;
T_1 V_10 ;
T_1 V_17 [ 4 ] ;
T_4 V_18 [ 4 ] ;
V_10 = V_12 + V_2 -> V_27 ;
V_17 [ 0 ] = V_10 + 4 ;
V_17 [ 1 ] = V_10 + 5 ;
V_17 [ 2 ] = V_10 + 16 ;
V_17 [ 3 ] = V_10 + 17 ;
V_4 = F_14 ( V_17 , V_18 , 4 ) ;
if ( V_4 )
goto V_29;
* V_21 = V_18 [ 0 ] << 3 ;
* V_21 |= V_18 [ 1 ] & 0x7 ;
* V_21 &= 0x3FF ;
* V_22 = V_18 [ 2 ] << 3 ;
* V_22 |= V_18 [ 3 ] & 0x7 ;
* V_22 &= 0x3FF ;
V_17 [ 0 ] = V_10 + 28 ;
V_17 [ 1 ] = V_10 + 29 ;
V_4 = F_14 ( V_17 , V_18 , 4 ) ;
if ( V_4 )
goto V_29;
* V_23 = V_18 [ 0 ] << 3 ;
* V_23 |= V_18 [ 1 ] & 0x7 ;
* V_23 &= 0x3FF ;
return 0 ;
V_29:
F_10 ( V_2 -> V_33 , L_2 , V_34 ) ;
return V_4 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_4 , V_15 ;
T_1 V_7 ;
T_1 V_17 [ 5 ] ;
T_4 V_18 [ 5 ] ;
V_7 = V_19 + V_2 -> V_27 ;
for ( V_15 = 0 ; V_15 <= 4 ; V_15 ++ ) {
V_17 [ V_15 ] = V_7 ++ ;
V_18 [ V_15 ] = 0 ;
}
V_4 = F_7 ( V_17 , V_18 , 5 ) ;
if ( V_4 )
goto V_29;
for ( V_15 = 0 ; V_15 <= 4 ; V_15 ++ ) {
V_17 [ V_15 ] = V_7 ++ ;
V_18 [ V_15 ] = 0 ;
}
V_4 = F_7 ( V_17 , V_18 , 5 ) ;
if ( V_4 )
goto V_29;
V_4 = F_12 ( V_7 + 2 , 0x00000000 ) ;
if ( V_4 )
goto V_29;
V_4 = F_2 ( V_3 , 0x02 , 0x02 ) ;
if ( V_4 )
goto V_29;
return 0 ;
V_29:
F_10 ( V_2 -> V_33 , L_2 , V_34 ) ;
return V_4 ;
}
static void F_16 ( struct V_35 * V_36 ,
unsigned int V_21 , unsigned int V_22 , unsigned int V_23 )
{
if ( V_23 > V_37 ) {
F_17 ( V_36 , V_38 , 1 ) ;
F_18 ( V_36 , V_39 , V_21 ) ;
F_18 ( V_36 , V_40 , V_22 ) ;
} else {
F_17 ( V_36 , V_38 , 0 ) ;
}
F_18 ( V_36 , V_41 , V_23 ) ;
F_19 ( V_36 ) ;
}
static T_5 F_20 ( int V_42 , void * V_43 )
{
struct V_1 * V_2 = V_43 ;
T_1 V_21 , V_22 , V_23 ;
if ( V_2 -> V_44 ( V_2 ) )
goto V_45;
do {
if ( V_2 -> V_46 ( V_2 , & V_21 , & V_22 , & V_23 ) )
break;
F_16 ( V_2 -> V_36 , V_21 , V_22 , V_23 ) ;
} while ( V_23 > V_37 );
V_2 -> V_47 ( V_2 ) ;
V_45:
return V_48 ;
}
static int T_6 F_21 ( T_3 * V_49 , T_3 * V_50 )
{
int V_4 ;
T_4 V_51 ;
V_4 = F_22 ( V_52 , & V_51 ) ;
if ( V_4 )
return V_4 ;
* V_49 = V_51 & 0x7 ;
* V_50 = ( V_51 >> 3 ) & 0x7 ;
return 0 ;
}
static int T_6 F_23 ( struct V_1 * V_2 )
{
int V_53 = 0 ;
int V_4 , V_54 ;
T_4 V_55 ;
for ( V_54 = 0 ; V_54 < V_56 ; V_54 ++ ) {
V_4 = F_22 ( V_19 + V_54 , & V_55 ) ;
if ( V_4 )
return V_4 ;
if ( V_55 == V_57 ) {
V_53 = V_54 ;
break;
}
}
if ( V_2 -> V_49 == V_58 ) {
if ( V_53 > V_56 - 18 )
return - V_59 ;
} else {
if ( V_53 > V_56 - 4 )
return - V_59 ;
}
return V_53 ;
}
static int T_6 F_24 ( T_3 V_6 )
{
T_1 V_7 ;
int V_60 , V_15 ;
V_7 = V_19 + V_6 ;
for ( V_15 = 0 ; V_15 <= 3 ; V_15 ++ ) {
V_60 = F_25 ( V_7 ++ , V_20 + V_15 ) ;
if ( V_60 )
return V_60 ;
}
return F_25 ( V_7 ++ , V_57 ) ;
}
static int T_6 F_26 ( struct V_1 * V_2 )
{
int V_4 , V_16 ;
T_4 V_61 , V_62 ;
V_4 = F_21 ( & V_2 -> V_49 , & V_2 -> V_50 ) ;
if ( V_4 ) {
F_10 ( V_2 -> V_33 , L_3 ) ;
return V_4 ;
}
switch ( V_2 -> V_49 ) {
case V_63 :
case V_64 :
V_2 -> V_44 = F_1 ;
V_2 -> V_46 = F_8 ;
V_2 -> V_47 = F_3 ;
break;
case V_58 :
V_2 -> V_44 = F_11 ;
V_2 -> V_46 = F_13 ;
V_2 -> V_47 = F_15 ;
break;
default:
F_10 ( V_2 -> V_33 ,
L_4 , V_2 -> V_49 ) ;
return - V_65 ;
}
V_16 = F_23 ( V_2 ) ;
if ( V_16 < 0 ) {
F_10 ( V_2 -> V_33 , L_5 ) ;
return V_16 ;
}
V_2 -> V_27 = V_16 ;
if ( V_2 -> V_49 == V_58 ) {
V_61 = 0xE0 | V_66 ;
V_62 = 0x5 ;
} else {
V_61 = 0xE0 | V_67 ;
V_62 = 0x0 ;
V_4 = F_24 ( V_2 -> V_27 ) ;
if ( V_4 )
return V_4 ;
}
V_4 = F_2 ( V_5 , V_61 , 0xE7 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_2 ( V_3 , V_62 , 0x03 ) ;
if ( V_4 )
return V_4 ;
return 0 ;
}
static int T_6 F_27 ( struct V_68 * V_69 )
{
struct V_1 * V_2 ;
struct V_35 * V_36 ;
int V_4 ;
int V_42 ;
V_42 = F_28 ( V_69 , 0 ) ;
if ( V_42 < 0 ) {
F_10 ( & V_69 -> V_33 , L_6 ) ;
return - V_70 ;
}
V_2 = F_29 ( sizeof( struct V_1 ) , V_71 ) ;
V_36 = F_30 () ;
if ( ! V_2 || ! V_36 ) {
F_10 ( & V_69 -> V_33 , L_7 ) ;
V_4 = - V_72 ;
goto V_73;
}
V_2 -> V_33 = & V_69 -> V_33 ;
V_2 -> V_36 = V_36 ;
V_2 -> V_42 = V_42 ;
snprintf ( V_2 -> V_74 , sizeof( V_2 -> V_74 ) ,
L_8 , F_31 ( V_2 -> V_33 ) ) ;
V_4 = F_26 ( V_2 ) ;
if ( V_4 ) {
F_10 ( & V_69 -> V_33 , L_9 ) ;
goto V_73;
}
V_36 -> V_75 = L_10 ;
V_36 -> V_74 = V_2 -> V_74 ;
V_36 -> V_33 . V_76 = V_2 -> V_33 ;
V_36 -> V_77 . V_49 = V_2 -> V_49 ;
V_36 -> V_77 . V_78 = V_2 -> V_50 ;
V_36 -> V_79 [ 0 ] = F_32 ( V_80 ) | F_32 ( V_81 ) ;
V_36 -> V_82 [ F_33 ( V_38 ) ] = F_32 ( V_38 ) ;
F_34 ( V_2 -> V_36 , V_39 ,
V_83 , V_84 , V_85 , 0 ) ;
F_34 ( V_2 -> V_36 , V_40 ,
V_86 , V_87 , V_88 , 0 ) ;
F_34 ( V_2 -> V_36 , V_41 ,
V_89 , V_90 , 0 , 0 ) ;
V_4 = F_35 ( V_2 -> V_42 , NULL , F_20 ,
0 , L_11 , V_2 ) ;
if ( V_4 ) {
F_10 ( V_2 -> V_33 , L_12 ) ;
goto V_73;
}
V_4 = F_36 ( V_2 -> V_36 ) ;
if ( V_4 ) {
F_10 ( V_2 -> V_33 , L_13 ) ;
goto V_91;
}
F_37 ( V_69 , V_2 ) ;
return 0 ;
V_91:
F_38 ( V_2 -> V_42 , V_2 ) ;
V_73:
F_39 ( V_36 ) ;
F_40 ( V_2 ) ;
return V_4 ;
}
static int T_7 F_41 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_42 ( V_69 ) ;
F_38 ( V_2 -> V_42 , V_2 ) ;
F_43 ( V_2 -> V_36 ) ;
F_40 ( V_2 ) ;
F_37 ( V_69 , NULL ) ;
return 0 ;
}
