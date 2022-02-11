static T_1 F_1 ( const T_2 * V_1 , T_3 V_2 )
{
T_3 V_3 ;
T_1 V_4 = 0 ;
for ( V_3 = 1 ; V_3 < V_2 ; V_3 ++ ) {
if ( V_3 % 2 )
V_4 += V_1 [ V_3 ] << 8 ;
else
V_4 += V_1 [ V_3 ] ;
}
V_4 = ~ V_4 ;
return V_4 ;
}
static int F_2 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
#define F_3 4
#define F_4 3
#define F_5 2
#define F_6 2000
struct V_9 * V_9 = F_7 ( V_6 ) ;
int V_10 , V_11 , V_12 ;
T_1 V_4 , V_13 ;
F_8 ( & V_6 -> V_14 ) ;
if ( V_8 -> V_11 > ( V_15 - F_3 - F_5 ) ||
V_8 -> V_12 > ( V_15 - F_4 - F_5 ) ) {
F_9 ( & V_6 -> V_16 -> V_17 , L_1 ,
V_18 , V_8 -> V_11 , V_8 -> V_12 ) ;
V_10 = - V_19 ;
goto exit;
}
V_9 -> V_1 [ 0 ] = F_3 + V_8 -> V_11 + F_5 - 1 ;
V_9 -> V_1 [ 1 ] = V_8 -> V_20 ;
V_9 -> V_1 [ 2 ] = V_8 -> V_21 ;
V_9 -> V_1 [ 3 ] = V_9 -> V_22 ++ ;
memcpy ( & V_9 -> V_1 [ F_3 ] , V_8 -> V_23 , V_8 -> V_11 ) ;
V_11 = F_3 + V_8 -> V_11 + F_5 ;
V_12 = F_4 + V_8 -> V_12 + F_5 ;
V_4 = F_1 ( V_9 -> V_1 , V_9 -> V_1 [ 0 ] - 1 ) ;
V_9 -> V_1 [ V_9 -> V_1 [ 0 ] - 1 ] = ( V_4 >> 8 ) ;
V_9 -> V_1 [ V_9 -> V_1 [ 0 ] - 0 ] = ( V_4 & 0xff ) ;
if ( V_8 -> V_21 == V_24 )
V_12 = 0 ;
V_10 = F_10 ( V_6 ,
V_9 -> V_1 , V_11 , V_9 -> V_1 , V_12 ) ;
if ( V_10 )
goto exit;
if ( V_8 -> V_21 == V_24 )
goto exit;
V_4 = F_1 ( V_9 -> V_1 , V_12 - 2 ) ;
V_13 = ( V_9 -> V_1 [ V_12 - 2 ] << 8 ) | V_9 -> V_1 [ V_12 - 1 ] ;
if ( V_13 != V_4 ) {
F_9 ( & V_6 -> V_16 -> V_17 ,
L_2 ,
V_18 , V_8 -> V_21 , V_13 ,
V_4 ) ;
V_10 = - V_25 ;
goto exit;
}
if ( V_9 -> V_1 [ 2 ] ) {
if ( V_8 -> V_21 == V_26 || V_9 -> V_1 [ 2 ] == 1 ) {
V_10 = 1 ;
goto exit;
}
F_11 ( & V_6 -> V_16 -> V_17 , L_3 ,
V_27 , V_8 -> V_21 , V_9 -> V_1 [ 2 ] ) ;
V_10 = - V_25 ;
goto exit;
}
if ( V_8 -> V_12 )
memcpy ( V_8 -> V_28 , & V_9 -> V_1 [ F_4 ] , V_8 -> V_12 ) ;
exit:
F_12 ( & V_6 -> V_14 ) ;
if ( V_10 < 0 )
F_11 ( & V_6 -> V_16 -> V_17 , L_4 , V_27 , V_10 ) ;
return V_10 ;
}
static int F_13 ( struct V_5 * V_6 , T_4 V_29 , T_2 * V_30 , int V_2 )
{
T_2 V_23 [ V_31 ] ;
T_2 V_20 = ( V_29 >> 16 ) & 0xff ;
struct V_7 V_8 = { V_32 , V_20 , 6 + V_2 , V_23 , 0 , NULL } ;
if ( 6 + V_2 > sizeof( V_23 ) ) {
F_14 ( & V_6 -> V_16 -> V_17 , L_5 ,
V_18 , V_2 ) ;
return - V_33 ;
}
V_23 [ 0 ] = V_2 ;
V_23 [ 1 ] = 2 ;
V_23 [ 2 ] = 0 ;
V_23 [ 3 ] = 0 ;
V_23 [ 4 ] = ( V_29 >> 8 ) & 0xff ;
V_23 [ 5 ] = ( V_29 >> 0 ) & 0xff ;
memcpy ( & V_23 [ 6 ] , V_30 , V_2 ) ;
return F_2 ( V_6 , & V_8 ) ;
}
static int F_15 ( struct V_5 * V_6 , T_4 V_29 , T_2 * V_30 , int V_2 )
{
T_2 V_23 [] = { V_2 , 2 , 0 , 0 , ( V_29 >> 8 ) & 0xff , V_29 & 0xff } ;
T_2 V_20 = ( V_29 >> 16 ) & 0xff ;
struct V_7 V_8 = { V_34 , V_20 , sizeof( V_23 ) , V_23 , V_2 , V_30 } ;
return F_2 ( V_6 , & V_8 ) ;
}
static int F_16 ( struct V_5 * V_6 , T_4 V_29 , T_2 V_30 )
{
return F_13 ( V_6 , V_29 , & V_30 , 1 ) ;
}
static int F_17 ( struct V_5 * V_6 , T_4 V_29 , T_2 * V_30 )
{
return F_15 ( V_6 , V_29 , V_30 , 1 ) ;
}
static int F_18 ( struct V_5 * V_6 , T_4 V_29 , T_2 V_30 ,
T_2 V_35 )
{
int V_10 ;
T_2 V_36 ;
if ( V_35 != 0xff ) {
V_10 = F_15 ( V_6 , V_29 , & V_36 , 1 ) ;
if ( V_10 )
return V_10 ;
V_30 &= V_35 ;
V_36 &= ~ V_35 ;
V_30 |= V_36 ;
}
return F_13 ( V_6 , V_29 , & V_30 , 1 ) ;
}
static int F_19 ( struct V_37 * V_38 ,
struct V_39 V_40 [] , int V_41 )
{
struct V_5 * V_6 = F_20 ( V_38 ) ;
struct V_9 * V_9 = F_7 ( V_6 ) ;
int V_10 ;
if ( F_21 ( & V_6 -> V_42 ) < 0 )
return - V_43 ;
if ( V_41 == 2 && ! ( V_40 [ 0 ] . V_44 & V_45 ) &&
( V_40 [ 1 ] . V_44 & V_45 ) ) {
if ( V_40 [ 0 ] . V_2 > 40 || V_40 [ 1 ] . V_2 > 40 ) {
V_10 = - V_33 ;
} else if ( ( V_40 [ 0 ] . V_46 == V_9 -> V_47 [ 0 ] . V_48 ) ||
( V_40 [ 0 ] . V_46 == V_9 -> V_47 [ 1 ] . V_48 ) ) {
T_4 V_29 = V_40 [ 0 ] . V_1 [ 0 ] << 16 | V_40 [ 0 ] . V_1 [ 1 ] << 8 |
V_40 [ 0 ] . V_1 [ 2 ] ;
if ( V_40 [ 0 ] . V_46 == V_9 -> V_47 [ 1 ] . V_48 )
V_29 |= 0x100000 ;
V_10 = F_15 ( V_6 , V_29 , & V_40 [ 1 ] . V_1 [ 0 ] ,
V_40 [ 1 ] . V_2 ) ;
} else {
T_2 V_1 [ V_31 ] ;
struct V_7 V_8 = { V_49 , 0 , 5 + V_40 [ 0 ] . V_2 ,
V_1 , V_40 [ 1 ] . V_2 , V_40 [ 1 ] . V_1 } ;
if ( 5 + V_40 [ 0 ] . V_2 > sizeof( V_1 ) ) {
F_14 ( & V_6 -> V_16 -> V_17 ,
L_6 ,
V_18 , V_40 [ 0 ] . V_2 ) ;
V_10 = - V_33 ;
goto V_50;
}
V_8 . V_20 |= ( ( V_40 [ 0 ] . V_46 & 0x80 ) >> 3 ) ;
V_1 [ 0 ] = V_40 [ 1 ] . V_2 ;
V_1 [ 1 ] = V_40 [ 0 ] . V_46 << 1 ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
memcpy ( & V_1 [ 5 ] , V_40 [ 0 ] . V_1 , V_40 [ 0 ] . V_2 ) ;
V_10 = F_2 ( V_6 , & V_8 ) ;
}
} else if ( V_41 == 1 && ! ( V_40 [ 0 ] . V_44 & V_45 ) ) {
if ( V_40 [ 0 ] . V_2 > 40 ) {
V_10 = - V_33 ;
} else if ( ( V_40 [ 0 ] . V_46 == V_9 -> V_47 [ 0 ] . V_48 ) ||
( V_40 [ 0 ] . V_46 == V_9 -> V_47 [ 1 ] . V_48 ) ) {
T_4 V_29 = V_40 [ 0 ] . V_1 [ 0 ] << 16 | V_40 [ 0 ] . V_1 [ 1 ] << 8 |
V_40 [ 0 ] . V_1 [ 2 ] ;
if ( V_40 [ 0 ] . V_46 == V_9 -> V_47 [ 1 ] . V_48 )
V_29 |= 0x100000 ;
V_10 = F_13 ( V_6 , V_29 , & V_40 [ 0 ] . V_1 [ 3 ] ,
V_40 [ 0 ] . V_2 - 3 ) ;
} else {
T_2 V_1 [ V_31 ] ;
struct V_7 V_8 = { V_51 , 0 , 5 + V_40 [ 0 ] . V_2 ,
V_1 , 0 , NULL } ;
if ( 5 + V_40 [ 0 ] . V_2 > sizeof( V_1 ) ) {
F_14 ( & V_6 -> V_16 -> V_17 ,
L_6 ,
V_18 , V_40 [ 0 ] . V_2 ) ;
V_10 = - V_33 ;
goto V_50;
}
V_8 . V_20 |= ( ( V_40 [ 0 ] . V_46 & 0x80 ) >> 3 ) ;
V_1 [ 0 ] = V_40 [ 0 ] . V_2 ;
V_1 [ 1 ] = V_40 [ 0 ] . V_46 << 1 ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
memcpy ( & V_1 [ 5 ] , V_40 [ 0 ] . V_1 , V_40 [ 0 ] . V_2 ) ;
V_10 = F_2 ( V_6 , & V_8 ) ;
}
} else if ( V_41 == 1 && ( V_40 [ 0 ] . V_44 & V_45 ) ) {
if ( V_40 [ 0 ] . V_2 > 40 ) {
V_10 = - V_33 ;
} else {
T_2 V_1 [ 5 ] ;
struct V_7 V_8 = { V_49 , 0 , sizeof( V_1 ) ,
V_1 , V_40 [ 0 ] . V_2 , V_40 [ 0 ] . V_1 } ;
V_8 . V_20 |= ( ( V_40 [ 0 ] . V_46 & 0x80 ) >> 3 ) ;
V_1 [ 0 ] = V_40 [ 0 ] . V_2 ;
V_1 [ 1 ] = V_40 [ 0 ] . V_46 << 1 ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
V_10 = F_2 ( V_6 , & V_8 ) ;
}
} else {
V_10 = - V_33 ;
}
V_50:
F_12 ( & V_6 -> V_42 ) ;
if ( V_10 < 0 )
return V_10 ;
else
return V_41 ;
}
static T_4 F_22 ( struct V_37 * V_52 )
{
return V_53 ;
}
static int F_23 ( struct V_5 * V_6 , const char * * V_54 )
{
struct V_9 * V_9 = F_7 ( V_6 ) ;
int V_10 ;
T_2 V_23 [ 1 ] = { 1 } ;
T_2 V_28 [ 4 ] ;
struct V_7 V_8 = { V_55 , 0 , sizeof( V_23 ) , V_23 ,
sizeof( V_28 ) , V_28 } ;
V_10 = F_15 ( V_6 , 0x1222 , V_28 , 3 ) ;
if ( V_10 < 0 )
goto V_56;
V_9 -> V_57 = V_28 [ 0 ] ;
V_9 -> V_58 = V_28 [ 2 ] << 8 | V_28 [ 1 ] << 0 ;
V_10 = F_17 ( V_6 , 0x384f , & V_9 -> V_59 ) ;
if ( V_10 < 0 )
goto V_56;
F_24 ( & V_6 -> V_16 -> V_17 ,
L_7 ,
V_18 , V_9 -> V_59 ,
V_9 -> V_57 , V_9 -> V_58 ) ;
if ( V_9 -> V_58 == 0x9135 ) {
if ( V_9 -> V_57 == 0x02 )
* V_54 = V_60 ;
else
* V_54 = V_61 ;
V_9 -> V_62 = V_63 ;
} else {
* V_54 = V_64 ;
V_9 -> V_62 = V_65 ;
}
V_10 = F_2 ( V_6 , & V_8 ) ;
if ( V_10 < 0 )
goto V_56;
F_11 ( & V_6 -> V_16 -> V_17 , L_8 , V_27 , 4 , V_28 ) ;
if ( V_28 [ 0 ] || V_28 [ 1 ] || V_28 [ 2 ] || V_28 [ 3 ] )
V_10 = V_66 ;
else
V_10 = V_67 ;
return V_10 ;
V_56:
F_11 ( & V_6 -> V_16 -> V_17 , L_4 , V_27 , V_10 ) ;
return V_10 ;
}
static int F_25 ( struct V_5 * V_6 ,
const struct V_68 * V_69 )
{
int V_10 , V_3 , V_70 , V_2 ;
T_2 V_23 [ 1 ] ;
struct V_7 V_8 = { 0 , 0 , 0 , NULL , 0 , NULL } ;
struct V_7 V_71 = { V_24 , 0 , 0 , V_23 , 0 , NULL } ;
T_2 V_72 ;
T_1 V_73 , V_74 , V_75 ;
#define F_26 58
#define F_27 7
for ( V_3 = V_69 -> V_76 ; V_3 > F_27 ; ) {
V_72 = V_69 -> V_77 [ V_69 -> V_76 - V_3 + 0 ] ;
V_73 = V_69 -> V_77 [ V_69 -> V_76 - V_3 + 1 ] << 8 ;
V_73 |= V_69 -> V_77 [ V_69 -> V_76 - V_3 + 2 ] << 0 ;
V_74 = V_69 -> V_77 [ V_69 -> V_76 - V_3 + 3 ] << 8 ;
V_74 |= V_69 -> V_77 [ V_69 -> V_76 - V_3 + 4 ] << 0 ;
V_75 = V_69 -> V_77 [ V_69 -> V_76 - V_3 + 5 ] << 8 ;
V_75 |= V_69 -> V_77 [ V_69 -> V_76 - V_3 + 6 ] << 0 ;
F_11 ( & V_6 -> V_16 -> V_17 ,
L_9 ,
V_27 , V_72 , V_73 , V_74 ,
V_75 ) ;
if ( ( ( V_72 != 1 ) && ( V_72 != 2 ) ) ||
( V_74 > V_3 ) ) {
F_11 ( & V_6 -> V_16 -> V_17 , L_10 , V_27 ) ;
break;
}
V_8 . V_21 = V_78 ;
V_10 = F_2 ( V_6 , & V_8 ) ;
if ( V_10 < 0 )
goto V_56;
for ( V_70 = F_27 + V_74 ; V_70 > 0 ; V_70 -= F_26 ) {
V_2 = V_70 ;
if ( V_2 > F_26 )
V_2 = F_26 ;
V_71 . V_11 = V_2 ;
V_71 . V_23 = ( T_2 * ) & V_69 -> V_77 [ V_69 -> V_76 - V_3 +
F_27 + V_74 - V_70 ] ;
V_10 = F_2 ( V_6 , & V_71 ) ;
if ( V_10 < 0 )
goto V_56;
}
V_8 . V_21 = V_79 ;
V_10 = F_2 ( V_6 , & V_8 ) ;
if ( V_10 < 0 )
goto V_56;
V_3 -= V_74 + F_27 ;
F_11 ( & V_6 -> V_16 -> V_17 , L_11 ,
V_27 , V_69 -> V_76 - V_3 ) ;
}
if ( V_3 )
F_14 ( & V_6 -> V_16 -> V_17 , L_10 , V_18 ) ;
return 0 ;
V_56:
F_11 ( & V_6 -> V_16 -> V_17 , L_4 , V_27 , V_10 ) ;
return V_10 ;
}
static int F_28 ( struct V_5 * V_6 ,
const struct V_68 * V_69 )
{
int V_10 , V_3 , V_80 ;
struct V_7 V_71 = { V_81 , 0 , 0 , NULL , 0 , NULL } ;
#define F_27 7
for ( V_3 = F_27 , V_80 = 0 ; V_3 <= V_69 -> V_76 ; V_3 ++ ) {
if ( V_3 == V_69 -> V_76 ||
( V_69 -> V_77 [ V_3 + 0 ] == 0x03 &&
( V_69 -> V_77 [ V_3 + 1 ] == 0x00 ||
V_69 -> V_77 [ V_3 + 1 ] == 0x01 ) &&
V_69 -> V_77 [ V_3 + 2 ] == 0x00 ) ) {
V_71 . V_11 = V_3 - V_80 ;
V_71 . V_23 = ( T_2 * ) & V_69 -> V_77 [ V_80 ] ;
V_80 = V_3 ;
V_10 = F_2 ( V_6 , & V_71 ) ;
if ( V_10 < 0 )
goto V_56;
F_11 ( & V_6 -> V_16 -> V_17 , L_12 ,
V_27 , V_3 ) ;
}
}
return 0 ;
V_56:
F_11 ( & V_6 -> V_16 -> V_17 , L_4 , V_27 , V_10 ) ;
return V_10 ;
}
static int F_29 ( struct V_5 * V_6 ,
const struct V_68 * V_69 )
{
struct V_9 * V_9 = F_7 ( V_6 ) ;
int V_10 ;
T_2 V_23 [ 1 ] ;
T_2 V_28 [ 4 ] ;
T_2 V_36 ;
struct V_7 V_8 = { 0 , 0 , 0 , NULL , 0 , NULL } ;
struct V_7 V_82 = { V_55 , 0 , 1 , V_23 , 4 , V_28 } ;
F_11 ( & V_6 -> V_16 -> V_17 , L_13 , V_27 ) ;
V_10 = F_17 ( V_6 , V_9 -> V_62 + V_83 , & V_36 ) ;
if ( V_10 < 0 )
goto V_56;
if ( V_36 == 1 || V_36 == 3 ) {
V_10 = F_18 ( V_6 , 0x00d8b0 , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_56;
V_10 = F_18 ( V_6 , 0x00d8b1 , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_56;
V_10 = F_18 ( V_6 , 0x00d8af , 0x00 , 0x01 ) ;
if ( V_10 < 0 )
goto V_56;
F_30 ( 10000 , 50000 ) ;
V_10 = F_18 ( V_6 , 0x00d8af , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_56;
V_10 = F_17 ( V_6 ,
V_9 -> V_62 + V_84 ,
& V_36 ) ;
if ( V_10 < 0 )
goto V_56;
if ( V_9 -> V_58 == 0x9135 ) {
V_10 = F_16 ( V_6 , 0x004bfb , V_36 ) ;
if ( V_10 < 0 )
goto V_56;
} else {
V_10 = F_16 ( V_6 , 0x00417f , V_36 ) ;
if ( V_10 < 0 )
goto V_56;
V_10 = F_18 ( V_6 , 0x00d81a , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_56;
}
}
if ( V_69 -> V_77 [ 0 ] == 0x01 )
V_10 = F_25 ( V_6 , V_69 ) ;
else
V_10 = F_28 ( V_6 , V_69 ) ;
if ( V_10 < 0 )
goto V_56;
V_8 . V_21 = V_85 ;
V_10 = F_2 ( V_6 , & V_8 ) ;
if ( V_10 < 0 )
goto V_56;
V_23 [ 0 ] = 1 ;
V_10 = F_2 ( V_6 , & V_82 ) ;
if ( V_10 < 0 )
goto V_56;
if ( ! ( V_28 [ 0 ] || V_28 [ 1 ] || V_28 [ 2 ] || V_28 [ 3 ] ) ) {
F_9 ( & V_6 -> V_16 -> V_17 , L_14 ,
V_18 ) ;
V_10 = - V_86 ;
goto V_56;
}
F_24 ( & V_6 -> V_16 -> V_17 , L_15 ,
V_18 , V_28 [ 0 ] , V_28 [ 1 ] , V_28 [ 2 ] , V_28 [ 3 ] ) ;
return 0 ;
V_56:
F_11 ( & V_6 -> V_16 -> V_17 , L_4 , V_27 , V_10 ) ;
return V_10 ;
}
static int F_31 ( struct V_5 * V_6 )
{
struct V_9 * V_9 = F_7 ( V_6 ) ;
int V_10 , V_3 ;
T_2 V_36 ;
T_1 V_87 , V_46 ;
V_9 -> V_47 [ 0 ] . V_48 = 0x38 ;
V_9 -> V_47 [ 0 ] . V_88 = V_89 ;
V_9 -> V_47 [ 1 ] . V_88 = V_89 ;
V_9 -> V_47 [ 0 ] . V_90 = V_91 ;
V_9 -> V_47 [ 1 ] . V_90 = V_92 ;
if ( V_9 -> V_58 == 0x9135 ) {
if ( V_9 -> V_57 == 0x02 ) {
V_9 -> V_47 [ 0 ] . V_93 = V_94 ;
V_9 -> V_47 [ 1 ] . V_93 = V_94 ;
V_87 = 0x00461d ;
} else {
V_9 -> V_47 [ 0 ] . V_93 = V_95 ;
V_9 -> V_47 [ 1 ] . V_93 = V_95 ;
V_87 = 0x00461b ;
}
V_10 = F_17 ( V_6 , V_87 , & V_36 ) ;
if ( V_10 < 0 )
goto V_56;
if ( V_36 == 0x00 ) {
F_11 ( & V_6 -> V_16 -> V_17 , L_16 , V_27 ) ;
goto V_96;
}
}
V_10 = F_17 ( V_6 , V_9 -> V_62 + V_83 , & V_36 ) ;
if ( V_10 < 0 )
goto V_56;
if ( V_36 == 1 || V_36 == 3 )
V_9 -> V_97 = true ;
F_11 ( & V_6 -> V_16 -> V_17 , L_17 , V_27 ,
V_36 , V_9 -> V_97 ) ;
if ( V_9 -> V_97 ) {
V_10 = F_17 ( V_6 ,
V_9 -> V_62 + V_84 ,
& V_36 ) ;
if ( V_10 < 0 )
goto V_56;
V_9 -> V_47 [ 1 ] . V_48 = V_36 ;
F_11 ( & V_6 -> V_16 -> V_17 , L_18 ,
V_27 , V_36 ) ;
}
V_46 = V_9 -> V_62 ;
for ( V_3 = 0 ; V_3 < V_9 -> V_97 + 1 ; V_3 ++ ) {
V_10 = F_17 ( V_6 , V_46 + V_98 , & V_36 ) ;
if ( V_10 < 0 )
goto V_56;
if ( V_36 == 0x00 )
F_11 ( & V_6 -> V_16 -> V_17 ,
L_19 ,
V_27 , V_3 ) ;
else
V_9 -> V_47 [ V_3 ] . V_93 = V_36 ;
F_11 ( & V_6 -> V_16 -> V_17 , L_20 ,
V_27 , V_3 , V_9 -> V_47 [ V_3 ] . V_93 ) ;
switch ( V_9 -> V_47 [ V_3 ] . V_93 ) {
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
V_9 -> V_47 [ V_3 ] . V_105 = 1 ;
break;
case V_95 :
case V_106 :
case V_107 :
case V_94 :
case V_108 :
case V_109 :
break;
default:
F_14 ( & V_6 -> V_16 -> V_17 ,
L_21 ,
V_18 , V_36 ) ;
}
if ( V_3 == 1 )
switch ( V_9 -> V_47 [ V_3 ] . V_93 ) {
case V_104 :
case V_95 :
case V_106 :
case V_107 :
case V_94 :
case V_108 :
case V_109 :
case V_101 :
break;
default:
V_9 -> V_97 = false ;
F_24 ( & V_6 -> V_16 -> V_17 ,
L_22 ,
V_18 ) ;
}
V_10 = F_17 ( V_6 , V_46 + V_110 , & V_36 ) ;
if ( V_10 < 0 )
goto V_56;
V_87 = V_36 ;
V_10 = F_17 ( V_6 , V_46 + V_111 , & V_36 ) ;
if ( V_10 < 0 )
goto V_56;
V_87 |= V_36 << 8 ;
F_11 ( & V_6 -> V_16 -> V_17 , L_23 , V_27 , V_3 , V_87 ) ;
V_46 += 0x10 ;
}
V_96:
V_10 = F_17 ( V_6 , 0x00d800 , & V_36 ) ;
if ( V_10 < 0 )
goto V_56;
V_36 = ( V_36 >> 0 ) & 0x0f ;
for ( V_3 = 0 ; V_3 < F_32 ( V_9 -> V_47 ) ; V_3 ++ ) {
if ( V_9 -> V_58 == 0x9135 )
V_9 -> V_47 [ V_3 ] . clock = V_112 [ V_36 ] ;
else
V_9 -> V_47 [ V_3 ] . clock = V_113 [ V_36 ] ;
}
return 0 ;
V_56:
F_11 ( & V_6 -> V_16 -> V_17 , L_4 , V_27 , V_10 ) ;
return V_10 ;
}
static int F_33 ( struct V_5 * V_6 ,
int V_21 , int V_114 )
{
int V_10 ;
T_2 V_30 ;
F_11 ( & V_6 -> V_16 -> V_17 , L_24 , V_27 , V_21 , V_114 ) ;
switch ( V_21 ) {
case V_115 :
if ( V_114 )
V_30 = 0x00 ;
else
V_30 = 0x01 ;
V_10 = F_18 ( V_6 , 0x00d8e7 , V_30 , 0x01 ) ;
if ( V_10 < 0 )
goto V_56;
break;
case V_116 :
if ( V_114 )
V_30 = 0x01 ;
else
V_30 = 0x00 ;
V_10 = F_18 ( V_6 , 0x00d8eb , V_30 , 0x01 ) ;
if ( V_10 < 0 )
goto V_56;
break;
}
return 0 ;
V_56:
F_11 ( & V_6 -> V_16 -> V_17 , L_4 , V_27 , V_10 ) ;
return V_10 ;
}
static int F_34 ( struct V_5 * V_6 ,
int V_21 , int V_114 )
{
int V_10 ;
switch ( V_21 ) {
case V_117 :
V_10 = F_18 ( V_6 , 0xd8eb , 1 , 1 ) ;
if ( V_10 < 0 )
goto V_56;
V_10 = F_18 ( V_6 , 0xd8ec , 1 , 1 ) ;
if ( V_10 < 0 )
goto V_56;
V_10 = F_18 ( V_6 , 0xd8ed , 1 , 1 ) ;
if ( V_10 < 0 )
goto V_56;
V_10 = F_18 ( V_6 , 0xd8d0 , 1 , 1 ) ;
if ( V_10 < 0 )
goto V_56;
V_10 = F_18 ( V_6 , 0xd8d1 , 1 , 1 ) ;
if ( V_10 < 0 )
goto V_56;
F_30 ( 10000 , 50000 ) ;
break;
case V_118 :
V_10 = F_16 ( V_6 , 0xd8e9 , 1 ) ;
if ( V_10 < 0 )
goto V_56;
V_10 = F_16 ( V_6 , 0xd8e8 , 1 ) ;
if ( V_10 < 0 )
goto V_56;
V_10 = F_16 ( V_6 , 0xd8e7 , 1 ) ;
if ( V_10 < 0 )
goto V_56;
F_30 ( 10000 , 20000 ) ;
V_10 = F_16 ( V_6 , 0xd8e7 , 0 ) ;
if ( V_10 < 0 )
goto V_56;
F_30 ( 10000 , 20000 ) ;
break;
default:
V_10 = - V_19 ;
goto V_56;
}
return 0 ;
V_56:
F_11 ( & V_6 -> V_16 -> V_17 , L_4 , V_27 , V_10 ) ;
return V_10 ;
}
static int F_35 ( struct V_5 * V_6 , int V_21 , int V_114 )
{
struct V_9 * V_9 = F_7 ( V_6 ) ;
switch ( V_9 -> V_47 [ 0 ] . V_93 ) {
case V_100 :
return F_34 ( V_6 , V_21 , V_114 ) ;
case V_99 :
return F_33 ( V_6 , V_21 , V_114 ) ;
default:
break;
}
return 0 ;
}
static int F_36 ( void * V_119 , int V_120 ,
int V_21 , int V_114 )
{
struct V_37 * V_38 = V_119 ;
struct V_5 * V_6 = F_20 ( V_38 ) ;
F_11 ( & V_6 -> V_16 -> V_17 , L_25 ,
V_27 , V_120 , V_21 , V_114 ) ;
switch ( V_120 ) {
case V_121 :
return F_35 ( V_6 , V_21 , V_114 ) ;
default:
break;
}
return 0 ;
}
static int F_37 ( struct V_5 * V_6 )
{
struct V_9 * V_9 = F_7 ( V_6 ) ;
if ( V_6 -> V_16 -> V_122 == V_123 )
return 1 ;
else
return V_9 -> V_97 + 1 ;
}
static int F_38 ( struct V_124 * V_38 )
{
struct V_9 * V_9 = F_39 ( V_38 ) ;
struct V_5 * V_6 = F_40 ( V_38 ) ;
int V_10 ;
F_11 ( & V_6 -> V_16 -> V_17 , L_13 , V_27 ) ;
if ( ! V_9 -> V_47 [ V_38 -> V_125 ] . V_93 ) {
V_10 = - V_86 ;
goto V_56;
}
V_38 -> V_126 [ 0 ] = F_41 ( V_127 , & V_9 -> V_47 [ V_38 -> V_125 ] ,
& V_6 -> V_128 ) ;
if ( V_38 -> V_126 [ 0 ] == NULL ) {
V_10 = - V_86 ;
goto V_56;
}
V_38 -> V_126 [ 0 ] -> V_129 . V_130 = NULL ;
V_38 -> V_126 [ 0 ] -> V_131 = F_36 ;
return 0 ;
V_56:
F_11 ( & V_6 -> V_16 -> V_17 , L_4 , V_27 , V_10 ) ;
return V_10 ;
}
static int F_42 ( struct V_124 * V_38 )
{
struct V_9 * V_9 = F_39 ( V_38 ) ;
struct V_5 * V_6 = F_40 ( V_38 ) ;
int V_10 ;
struct V_132 * V_126 ;
struct V_39 V_40 [ 1 ] ;
T_2 V_133 ;
F_11 ( & V_6 -> V_16 -> V_17 , L_13 , V_27 ) ;
switch ( V_9 -> V_47 [ V_38 -> V_125 ] . V_93 ) {
case V_99 :
V_10 = F_18 ( V_6 , 0x00d8ec , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_56;
V_10 = F_18 ( V_6 , 0x00d8ed , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_56;
V_10 = F_18 ( V_6 , 0x00d8e8 , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_56;
V_10 = F_18 ( V_6 , 0x00d8e9 , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_56;
V_126 = F_41 ( V_134 , V_38 -> V_126 [ 0 ] ,
& V_6 -> V_128 , & V_135 ) ;
break;
case V_100 :
V_126 = F_41 ( V_136 , V_38 -> V_126 [ 0 ] ,
& V_6 -> V_128 , & V_137 ) ;
break;
case V_101 :
if ( V_38 -> V_125 == 0 ) {
V_10 = F_16 ( V_6 , 0x00d8e0 , 1 ) ;
if ( V_10 < 0 )
goto V_56;
V_10 = F_16 ( V_6 , 0x00d8e1 , 1 ) ;
if ( V_10 < 0 )
goto V_56;
V_10 = F_16 ( V_6 , 0x00d8df , 0 ) ;
if ( V_10 < 0 )
goto V_56;
F_43 ( 30 ) ;
V_10 = F_16 ( V_6 , 0x00d8df , 1 ) ;
if ( V_10 < 0 )
goto V_56;
F_43 ( 300 ) ;
V_10 = F_16 ( V_6 , 0x00d8c0 , 1 ) ;
if ( V_10 < 0 )
goto V_56;
V_10 = F_16 ( V_6 , 0x00d8c1 , 1 ) ;
if ( V_10 < 0 )
goto V_56;
V_10 = F_16 ( V_6 , 0x00d8bf , 0 ) ;
if ( V_10 < 0 )
goto V_56;
V_10 = F_16 ( V_6 , 0x00d8b4 , 1 ) ;
if ( V_10 < 0 )
goto V_56;
V_10 = F_16 ( V_6 , 0x00d8b5 , 1 ) ;
if ( V_10 < 0 )
goto V_56;
V_10 = F_16 ( V_6 , 0x00d8b3 , 1 ) ;
if ( V_10 < 0 )
goto V_56;
V_133 = 0x60 ;
} else {
V_133 = 0x60 | 0x80 ;
}
V_126 = F_41 ( V_138 , V_38 -> V_126 [ 0 ] , & V_6 -> V_128 ,
V_133 , & V_139 [ V_38 -> V_125 ] ) ;
break;
case V_102 :
V_126 = F_41 ( V_140 , V_38 -> V_126 [ 0 ] ,
& V_6 -> V_128 , & V_141 ) ;
break;
case V_103 :
V_10 = F_18 ( V_6 , 0xd8eb , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_56;
V_10 = F_18 ( V_6 , 0xd8ec , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_56;
V_10 = F_18 ( V_6 , 0xd8ed , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_56;
F_30 ( 10000 , 50000 ) ;
V_126 = F_41 ( V_142 , V_38 -> V_126 [ 0 ] ,
& V_6 -> V_128 , & V_143 ) ;
break;
case V_104 :
if ( V_38 -> V_125 == 0 ) {
V_10 = F_18 ( V_6 , 0xd8eb , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_56;
V_10 = F_18 ( V_6 , 0xd8ec , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_56;
V_10 = F_18 ( V_6 , 0xd8ed , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_56;
} else {
V_40 [ 0 ] . V_46 = 0x63 ;
V_40 [ 0 ] . V_44 = 0 ;
V_40 [ 0 ] . V_2 = 2 ;
V_40 [ 0 ] . V_1 = L_26 ;
V_10 = F_44 ( & V_6 -> V_128 , V_40 , 1 ) ;
if ( V_10 < 0 )
goto V_56;
}
F_30 ( 10000 , 50000 ) ;
V_126 = F_41 ( V_144 , V_38 -> V_126 [ 0 ] , & V_6 -> V_128 ,
& V_145 [ V_38 -> V_125 ] ) ;
break;
case V_95 :
case V_106 :
case V_107 :
case V_94 :
case V_108 :
case V_109 :
V_126 = F_41 ( V_146 , V_38 -> V_126 [ 0 ] , & V_6 -> V_128 ,
V_9 -> V_47 [ V_38 -> V_125 ] . V_48 ,
V_9 -> V_47 [ 0 ] . V_93 ) ;
break;
default:
V_126 = NULL ;
}
if ( V_126 == NULL ) {
V_10 = - V_86 ;
goto V_56;
}
return 0 ;
V_56:
F_11 ( & V_6 -> V_16 -> V_17 , L_4 , V_27 , V_10 ) ;
return V_10 ;
}
static int F_45 ( struct V_5 * V_6 )
{
struct V_9 * V_9 = F_7 ( V_6 ) ;
int V_10 , V_3 ;
T_1 V_147 = ( V_6 -> V_16 -> V_122 == V_123 ? 5 : 87 ) * 188 / 4 ;
T_2 V_148 = ( V_6 -> V_16 -> V_122 == V_123 ? 64 : 512 ) / 4 ;
struct V_149 V_150 [] = {
{ 0x80f99d , 0x01 , 0x01 } ,
{ 0x80f9a4 , 0x01 , 0x01 } ,
{ 0x00dd11 , 0x00 , 0x20 } ,
{ 0x00dd11 , 0x00 , 0x40 } ,
{ 0x00dd13 , 0x00 , 0x20 } ,
{ 0x00dd13 , 0x00 , 0x40 } ,
{ 0x00dd11 , 0x20 , 0x20 } ,
{ 0x00dd88 , ( V_147 >> 0 ) & 0xff , 0xff } ,
{ 0x00dd89 , ( V_147 >> 8 ) & 0xff , 0xff } ,
{ 0x00dd0c , V_148 , 0xff } ,
{ 0x00dd11 , V_9 -> V_97 << 6 , 0x40 } ,
{ 0x00dd8a , ( V_147 >> 0 ) & 0xff , 0xff } ,
{ 0x00dd8b , ( V_147 >> 8 ) & 0xff , 0xff } ,
{ 0x00dd0d , V_148 , 0xff } ,
{ 0x80f9a3 , V_9 -> V_97 , 0x01 } ,
{ 0x80f9cd , V_9 -> V_97 , 0x01 } ,
{ 0x80f99d , 0x00 , 0x01 } ,
{ 0x80f9a4 , 0x00 , 0x01 } ,
} ;
F_11 ( & V_6 -> V_16 -> V_17 ,
L_27 ,
V_27 , V_6 -> V_16 -> V_122 , V_147 , V_148 ) ;
for ( V_3 = 0 ; V_3 < F_32 ( V_150 ) ; V_3 ++ ) {
V_10 = F_18 ( V_6 , V_150 [ V_3 ] . V_29 , V_150 [ V_3 ] . V_30 ,
V_150 [ V_3 ] . V_35 ) ;
if ( V_10 < 0 )
goto V_56;
}
return 0 ;
V_56:
F_11 ( & V_6 -> V_16 -> V_17 , L_4 , V_27 , V_10 ) ;
return V_10 ;
}
static int F_46 ( struct V_5 * V_6 )
{
int V_10 ;
T_4 V_151 ;
T_2 V_1 [ 4 ] ;
struct V_7 V_8 = { V_26 , 0 , 0 , NULL , 4 , V_1 } ;
V_10 = F_2 ( V_6 , & V_8 ) ;
if ( V_10 == 1 )
return 0 ;
else if ( V_10 < 0 )
goto V_56;
if ( ( V_1 [ 2 ] + V_1 [ 3 ] ) == 0xff ) {
if ( ( V_1 [ 0 ] + V_1 [ 1 ] ) == 0xff ) {
V_151 = V_1 [ 0 ] << 8 | V_1 [ 2 ] ;
} else {
V_151 = V_1 [ 0 ] << 16 | V_1 [ 1 ] << 8 | V_1 [ 2 ] ;
}
} else {
V_151 = V_1 [ 0 ] << 24 | V_1 [ 1 ] << 16 | V_1 [ 2 ] << 8 | V_1 [ 3 ] ;
}
F_11 ( & V_6 -> V_16 -> V_17 , L_28 , V_27 , 4 , V_1 ) ;
F_47 ( V_6 -> V_152 , V_151 , 0 ) ;
return 0 ;
V_56:
F_11 ( & V_6 -> V_16 -> V_17 , L_4 , V_27 , V_10 ) ;
return V_10 ;
}
static int F_48 ( struct V_5 * V_6 , struct V_153 * V_154 )
{
struct V_9 * V_9 = F_7 ( V_6 ) ;
int V_10 ;
T_2 V_36 ;
V_10 = F_17 ( V_6 , V_9 -> V_62 + V_155 , & V_36 ) ;
if ( V_10 < 0 )
goto V_56;
F_11 ( & V_6 -> V_16 -> V_17 , L_29 , V_27 , V_36 ) ;
if ( V_36 == 5 ) {
V_10 = F_17 ( V_6 , V_9 -> V_62 + V_156 ,
& V_36 ) ;
if ( V_10 < 0 )
goto V_56;
F_11 ( & V_6 -> V_16 -> V_17 , L_30 , V_27 , V_36 ) ;
switch ( V_36 ) {
case 0 :
default:
V_154 -> V_157 = V_158 ;
break;
case 1 :
V_154 -> V_157 = V_159 ;
break;
}
V_154 -> V_160 = F_46 ;
V_154 -> V_161 = 500 ;
if ( ! V_154 -> V_162 )
V_154 -> V_162 = V_163 ;
}
return 0 ;
V_56:
F_11 ( & V_6 -> V_16 -> V_17 , L_4 , V_27 , V_10 ) ;
return V_10 ;
}
static int F_49 ( struct V_132 * V_126 , T_2 * V_164 ,
struct V_165 * V_166 )
{
struct V_5 * V_6 = F_50 ( V_126 ) ;
F_11 ( & V_6 -> V_16 -> V_17 , L_31 , V_27 , F_51 ( V_126 ) -> V_125 ) ;
if ( V_6 -> V_16 -> V_122 == V_123 )
V_166 -> V_167 . V_168 . V_169 = 5 * 188 ;
return 0 ;
}
static int F_52 ( struct V_124 * V_38 , int V_170 )
{
struct V_5 * V_6 = F_40 ( V_38 ) ;
int V_10 ;
F_11 ( & V_6 -> V_16 -> V_17 , L_32 , V_27 , V_170 ) ;
V_10 = F_18 ( V_6 , 0x80f993 , V_170 , 0x01 ) ;
if ( V_10 < 0 )
goto V_56;
return 0 ;
V_56:
F_11 ( & V_6 -> V_16 -> V_17 , L_4 , V_27 , V_10 ) ;
return V_10 ;
}
static int F_53 ( struct V_124 * V_38 , int V_171 , T_1 V_172 ,
int V_170 )
{
struct V_5 * V_6 = F_40 ( V_38 ) ;
int V_10 ;
T_2 V_23 [ 2 ] = { ( V_172 >> 0 ) & 0xff , ( V_172 >> 8 ) & 0xff } ;
F_11 ( & V_6 -> V_16 -> V_17 , L_33 ,
V_27 , V_171 , V_172 , V_170 ) ;
V_10 = F_13 ( V_6 , 0x80f996 , V_23 , 2 ) ;
if ( V_10 < 0 )
goto V_56;
V_10 = F_16 ( V_6 , 0x80f994 , V_170 ) ;
if ( V_10 < 0 )
goto V_56;
V_10 = F_16 ( V_6 , 0x80f995 , V_171 ) ;
if ( V_10 < 0 )
goto V_56;
return 0 ;
V_56:
F_11 ( & V_6 -> V_16 -> V_17 , L_4 , V_27 , V_10 ) ;
return V_10 ;
}
static int F_54 ( struct V_173 * V_174 ,
const struct V_175 * V_125 )
{
struct V_176 * V_16 = F_55 ( V_174 ) ;
char V_177 [ sizeof( L_34 ) ] ;
memset ( V_177 , 0 , sizeof( V_177 ) ) ;
F_56 ( V_16 , V_16 -> V_178 . V_179 ,
V_177 , sizeof( V_177 ) ) ;
if ( ( F_57 ( V_16 -> V_178 . V_180 ) == V_181 ) &&
( F_57 ( V_16 -> V_178 . V_182 ) == 0x0099 ) ) {
if ( ! strcmp ( L_34 , V_177 ) ) {
F_11 ( & V_16 -> V_17 , L_35 , V_27 ) ;
return - V_86 ;
}
}
return F_58 ( V_174 , V_125 ) ;
}
