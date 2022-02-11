static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 , T_1 V_6 ,
T_1 V_7 , T_1 V_8 , void * V_9 , int V_10 , int V_11 )
{
struct V_12 * V_13 = V_5 -> V_14 ;
int V_15 = 5000 ;
if ( V_11 ) {
return F_4 ( V_13 -> V_16 ,
F_5 ( V_13 -> V_16 , 0 ) , V_6 ,
V_17 | V_18 | V_19 ,
V_7 , V_8 , V_9 , V_10 , V_15 ) ;
} else {
return F_4 ( V_13 -> V_16 ,
F_6 ( V_13 -> V_16 , 0 ) , V_6 ,
V_17 | V_18 ,
V_7 , V_8 , V_9 , V_10 , V_15 ) ;
}
}
static int F_7 ( struct V_20 * V_21 , T_2 V_22 , T_2 V_7 )
{
struct V_4 * V_5 = F_8 ( V_21 -> V_23 ) ;
struct V_12 * V_13 ;
int V_24 ;
int V_25 = V_21 -> V_26 << 1 ;
T_2 * V_27 ;
if ( V_5 == NULL )
return - V_28 ;
if ( V_5 -> V_29 == V_30 )
return - V_31 ;
V_27 = F_9 ( 16 , V_32 ) ;
if ( V_27 == NULL )
return - V_33 ;
V_13 = V_5 -> V_14 ;
if ( F_10 ( & V_13 -> V_34 ) != 0 ) {
F_11 ( & V_21 -> V_35 , L_1 ) ;
F_12 ( V_27 ) ;
return - V_36 ;
}
V_24 = F_3 ( V_5 , 0x55 , V_25 ,
( V_22 << 8 | V_7 ) ,
V_27 ,
16 , 1 ) ;
F_13 ( & V_13 -> V_34 ) ;
F_12 ( V_27 ) ;
return V_24 ;
}
static int F_14 ( struct V_20 * V_21 , T_1 V_26 , T_1 V_37 )
{
struct V_4 * V_5 = F_8 ( V_21 -> V_23 ) ;
struct V_12 * V_13 ;
int V_24 ;
T_2 * V_27 ;
struct V_1 * V_38 = F_15 ( V_21 ) ;
if ( V_5 == NULL )
return - V_28 ;
if ( V_5 -> V_29 == V_30 )
return - V_31 ;
V_27 = F_9 ( 16 , V_32 ) ;
if ( V_27 == NULL )
return - V_33 ;
memset ( V_27 , 0xcd , 6 ) ;
V_13 = V_5 -> V_14 ;
if ( F_10 ( & V_13 -> V_34 ) != 0 ) {
F_11 ( & V_21 -> V_35 , L_1 ) ;
F_12 ( V_27 ) ;
return - V_36 ;
}
V_24 = F_3 ( V_5 , 0x57 , V_26 , V_37 , V_27 , 16 , 1 ) ;
F_13 ( & V_13 -> V_34 ) ;
if ( V_24 < 0 ) {
F_12 ( V_27 ) ;
return V_24 ;
}
if ( V_27 [ 0 ] == 0 ) {
unsigned int V_39 , V_40 ;
V_39 = ( V_27 [ 4 ] << 8 ) + V_27 [ 5 ] ;
V_40 = ( V_27 [ 2 ] << 8 ) + V_27 [ 3 ] ;
F_12 ( V_27 ) ;
if ( V_40 != V_37 ) {
F_11 ( & V_21 -> V_35 , L_2 ,
V_40 , V_37 ) ;
return - V_41 ;
}
if ( V_39 != V_26 ) {
F_11 ( & V_21 -> V_35 , L_3 ,
V_39 , V_26 ) ;
return - V_41 ;
}
} else {
F_12 ( V_27 ) ;
return - V_41 ;
}
if ( V_26 == 0x12b )
V_38 -> V_42 = V_37 ;
return 0 ;
}
static int F_16 ( struct V_20 * V_21 , T_1 V_26 , T_1 * V_37 )
{
struct V_4 * V_5 = F_8 ( V_21 -> V_23 ) ;
struct V_12 * V_13 ;
int V_24 ;
T_2 * V_27 ;
if ( V_5 == NULL )
return - V_28 ;
if ( V_5 -> V_29 == V_30 )
return - V_31 ;
V_27 = F_9 ( 16 , V_32 ) ;
if ( V_27 == NULL )
return - V_33 ;
memset ( V_27 , 0xcd , 6 ) ;
V_13 = V_5 -> V_14 ;
if ( F_10 ( & V_13 -> V_34 ) != 0 ) {
F_11 ( & V_21 -> V_35 , L_1 ) ;
F_12 ( V_27 ) ;
return - V_36 ;
}
V_24 = F_3 ( V_5 , 0x58 , V_26 , 0 , V_27 , 16 , 1 ) ;
F_13 ( & V_13 -> V_34 ) ;
if ( V_24 < 0 ) {
F_12 ( V_27 ) ;
return V_24 ;
}
* V_37 = ( V_27 [ 0 ] << 8 ) | V_27 [ 1 ] ;
F_12 ( V_27 ) ;
return 0 ;
}
static int F_17 ( struct V_20 * V_21 , T_2 * V_43 )
{
int V_44 ;
for ( V_44 = 0 ; ! ( ( V_43 [ V_44 ] == 0x00 ) && ( V_43 [ V_44 + 1 ] == 0x00 ) ) ; V_44 += 2 ) {
if ( F_7 ( V_21 , V_43 [ V_44 ] , V_43 [ V_44 + 1 ] ) < 0 ) {
F_11 ( & V_21 -> V_35 , L_4 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_18 ( struct V_20 * V_21 , T_1 * V_43 )
{
int V_44 ;
for ( V_44 = 0 ; ! ( ( V_43 [ V_44 ] == 0x00 ) && ( V_43 [ V_44 + 1 ] == 0x00 ) ) ; V_44 += 2 ) {
if ( F_14 ( V_21 , V_43 [ V_44 ] , V_43 [ V_44 + 1 ] ) < 0 ) {
F_11 ( & V_21 -> V_35 , L_5 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_19 ( struct V_2 * V_3 , T_3 V_45 , T_3 V_46 ,
T_3 V_47 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
struct V_20 * V_21 = F_20 ( V_3 ) ;
int V_49 ;
V_49 = ( V_48 -> V_50 == V_51 ) ? 0x01 : 0x00 ;
if ( V_45 == 0 ) {
F_14 ( V_21 , 0x20 , 0x020 | V_49 ) ;
F_14 ( V_21 , 0x21 , 0x662 ) ;
F_14 ( V_21 , 0x140 , 0x060 ) ;
} else if ( V_45 == 1 ) {
F_14 ( V_21 , 0x20 , 0x040 | V_49 ) ;
F_14 ( V_21 , 0x21 , 0x666 ) ;
F_14 ( V_21 , 0x140 , 0x060 ) ;
} else {
return - V_52 ;
}
V_48 -> V_45 = V_45 ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 , T_4 V_53 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
struct V_20 * V_21 = F_20 ( V_3 ) ;
T_1 V_54 ;
V_54 = ( V_48 -> V_45 == 1 ) ? 0x040 : 0x020 ;
if ( V_53 & V_55 ) {
F_18 ( V_21 , V_56 ) ;
F_18 ( V_21 , V_57 ) ;
F_14 ( V_21 , 0x20 , V_54 ) ;
} else {
F_18 ( V_21 , V_56 ) ;
F_14 ( V_21 , 0x20 , V_54 | 1 ) ;
}
V_48 -> V_50 = V_53 ;
return 0 ;
}
static int F_22 ( struct V_58 * V_59 )
{
struct V_1 * V_48 = F_2 ( V_59 -> V_60 , struct V_1 , V_61 ) ;
struct V_20 * V_21 = F_20 ( & V_48 -> V_3 ) ;
T_1 V_62 ;
switch ( V_59 -> V_63 ) {
case V_64 :
F_16 ( V_21 , V_65 , & V_62 ) ;
F_14 ( V_21 , V_65 ,
V_59 -> V_37 | ( V_62 & ~ 0xff ) ) ;
F_16 ( V_21 , V_66 , & V_62 ) ;
F_14 ( V_21 , V_66 ,
V_59 -> V_37 | ( V_62 & ~ 0xff ) ) ;
F_14 ( V_21 , 0x140 , 0x60 ) ;
break;
case V_67 :
F_16 ( V_21 , V_68 , & V_62 ) ;
F_14 ( V_21 , V_68 ,
V_59 -> V_37 | ( V_62 & ~ 0x3f ) ) ;
F_16 ( V_21 , V_69 , & V_62 ) ;
F_14 ( V_21 , V_69 ,
V_59 -> V_37 | ( V_62 & ~ 0x3f ) ) ;
F_14 ( V_21 , 0x140 , 0x60 ) ;
break;
case V_70 :
F_14 ( V_21 , V_71 , V_59 -> V_37 ) ;
break;
case V_72 :
F_14 ( V_21 , V_73 , V_59 -> V_37 ) ;
break;
default:
return - V_52 ;
}
return 0 ;
}
static int F_23 ( struct V_2 * V_3 ,
struct V_74 * V_75 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
struct V_20 * V_21 = F_20 ( V_3 ) ;
if ( V_75 -> V_76 < 640 ) {
F_14 ( V_21 , 0x12b , V_48 -> V_42 | 0x400 ) ;
F_14 ( V_21 , 0x140 , 0x060 ) ;
} else {
F_14 ( V_21 , 0x12b , V_48 -> V_42 & ~ 0x400 ) ;
F_14 ( V_21 , 0x140 , 0x060 ) ;
}
return 0 ;
}
static int F_24 ( struct V_2 * V_3 , T_3 V_45 , T_3 V_46 ,
T_3 V_47 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
switch ( V_45 ) {
case 0 :
F_7 ( V_48 -> V_77 , 0x08 , 0x02 ) ;
break;
case 1 :
F_7 ( V_48 -> V_77 , 0x08 , 0x04 ) ;
break;
case 2 :
F_7 ( V_48 -> V_77 , 0x08 , 0x05 ) ;
break;
default:
return - V_52 ;
}
V_48 -> V_78 = V_45 ;
return 0 ;
}
static int F_25 ( struct V_2 * V_3 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
F_26 ( V_3 , L_6 , V_48 -> V_50 == V_51 ? L_7 :
V_48 -> V_50 == V_79 ? L_8 :
V_48 -> V_50 == V_80 ? L_9 :
L_10 ) ;
F_26 ( V_3 , L_11 , V_48 -> V_45 == 0 ? L_12 :
V_48 -> V_45 == 1 ? L_13 :
L_14 ) ;
F_26 ( V_3 , L_15 , V_48 -> V_78 == 0 ? L_16 :
V_48 -> V_78 == 1 ? L_17 :
V_48 -> V_78 == 2 ? L_18 :
L_14 ) ;
return F_27 ( V_3 ) ;
}
static int F_28 ( struct V_20 * V_21 ,
const struct V_81 * V_63 )
{
struct V_20 * V_77 ;
struct V_82 * V_23 = V_21 -> V_23 ;
struct V_1 * V_48 ;
struct V_2 * V_3 ;
T_2 * V_83 ;
struct V_4 * V_5 = F_8 ( V_23 ) ;
struct V_12 * V_13 = V_5 -> V_14 ;
V_77 = F_29 ( V_23 , V_84 >> 1 ) ;
if ( V_77 == NULL )
return - V_33 ;
V_48 = F_9 ( sizeof( struct V_1 ) , V_32 ) ;
if ( V_48 == NULL ) {
F_30 ( V_77 ) ;
return - V_33 ;
}
V_3 = & V_48 -> V_3 ;
F_31 ( V_3 , V_21 , & V_85 ) ;
F_26 ( V_3 , L_19 ,
L_20 , V_21 -> V_26 , V_21 -> V_23 -> V_86 ) ;
F_32 ( & V_48 -> V_61 , 4 ) ;
F_33 ( & V_48 -> V_61 , & V_87 ,
V_64 , - 128 , 127 , 1 , 0 ) ;
F_33 ( & V_48 -> V_61 , & V_87 ,
V_67 , 0 , 0x3f , 1 , 0x32 ) ;
F_33 ( & V_48 -> V_61 , & V_87 ,
V_70 , 0 , 4094 , 1 , 2070 ) ;
F_33 ( & V_48 -> V_61 , & V_87 ,
V_72 , - 512 , 511 , 1 , 0 ) ;
V_3 -> V_88 = & V_48 -> V_61 ;
if ( V_48 -> V_61 . error ) {
int V_89 = V_48 -> V_61 . error ;
F_34 ( & V_48 -> V_61 ) ;
F_12 ( V_48 ) ;
return V_89 ;
}
V_48 -> V_50 = V_51 ;
V_48 -> V_90 = 50 ;
V_48 -> V_91 = 50 ;
V_48 -> V_92 = 50 ;
V_48 -> V_93 = 0 ;
V_48 -> V_77 = V_77 ;
if ( F_17 ( V_77 , V_94 ) < 0 ) {
F_35 ( & V_21 -> V_35 , L_21 ) ;
goto V_95;
}
if ( F_17 ( V_21 , V_96 ) < 0 ) {
F_35 ( & V_21 -> V_35 , L_22 ) ;
goto V_95;
}
if ( F_18 ( V_21 , V_56 ) < 0 ) {
F_35 ( & V_21 -> V_35 , L_22 ) ;
goto V_95;
}
F_14 ( V_21 , 0x20 , 0x020 | 1 ) ;
F_14 ( V_21 , 0x21 , 0x662 ) ;
F_14 ( V_21 , 0x140 , 0x060 ) ;
V_48 -> V_78 = 0 ;
F_7 ( V_21 , 0x08 , 0x02 ) ;
if ( F_10 ( & V_13 -> V_34 ) == 0 ) {
V_83 = F_9 ( 16 , V_32 ) ;
if ( V_83 != NULL ) {
int V_24 ;
V_24 = F_3 ( V_5 , 0x41 , 0 , 0 ,
V_83 , 16 , 1 ) ;
if ( V_24 > 0 ) {
T_2 V_97 ;
V_83 [ 0 ] = 0 ;
V_97 = 1 << 5 ;
V_83 [ 0 ] &= ~ V_97 ;
V_83 [ 1 ] |= V_97 ;
F_3 ( V_5 , 0x40 , 0 ,
( V_83 [ 1 ] << 8 )
+ V_83 [ 1 ] ,
V_83 , 16 , 0 ) ;
}
F_12 ( V_83 ) ;
}
F_13 ( & V_13 -> V_34 ) ;
}
F_26 ( V_3 , L_23 ) ;
return 0 ;
V_95:
F_30 ( V_77 ) ;
F_34 ( & V_48 -> V_61 ) ;
F_12 ( V_48 ) ;
return - V_98 ;
}
static int F_36 ( struct V_20 * V_21 )
{
struct V_1 * V_48 = F_1 ( F_15 ( V_21 ) ) ;
F_37 ( & V_48 -> V_3 ) ;
F_34 ( & V_48 -> V_61 ) ;
F_12 ( V_48 ) ;
return 0 ;
}
