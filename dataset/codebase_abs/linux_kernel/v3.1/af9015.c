static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
#define F_2 63
#define F_3 8
#define F_4 2
int V_5 , V_6 ;
T_1 V_7 [ F_2 ] ;
T_1 V_8 = 1 ;
T_1 V_9 = F_3 ;
static T_1 V_10 ;
if ( F_5 ( & V_11 ) < 0 )
return - V_12 ;
V_7 [ 0 ] = V_4 -> V_13 ;
V_7 [ 1 ] = V_10 ++ ;
V_7 [ 2 ] = V_4 -> V_14 ;
V_7 [ 3 ] = V_4 -> V_15 >> 8 ;
V_7 [ 4 ] = V_4 -> V_15 & 0xff ;
V_7 [ 5 ] = V_4 -> V_16 ;
V_7 [ 6 ] = V_4 -> V_17 ;
V_7 [ 7 ] = V_4 -> V_18 ;
switch ( V_4 -> V_13 ) {
case V_19 :
case V_20 :
case V_21 :
V_8 = 0 ;
break;
case V_22 :
V_8 = 0 ;
V_7 [ 2 ] |= 0x01 ;
case V_23 :
V_7 [ 0 ] = V_24 ;
break;
case V_25 :
if ( ( ( V_4 -> V_15 & 0xff00 ) == 0xff00 ) ||
( ( V_4 -> V_15 & 0xff00 ) == 0xae00 ) )
V_7 [ 0 ] = V_26 ;
case V_26 :
case V_27 :
case V_28 :
case V_29 :
break;
default:
F_6 ( L_1 , V_4 -> V_13 ) ;
V_6 = - 1 ;
goto V_30;
}
if ( ( V_8 && ( V_4 -> V_18 > F_2 - F_3 ) ) ||
( ! V_8 && ( V_4 -> V_18 > F_2 - F_4 ) ) ) {
F_6 ( L_2 , V_4 -> V_13 , V_4 -> V_18 ) ;
V_6 = - V_31 ;
goto V_30;
}
if ( V_8 ) {
memcpy ( & V_7 [ F_3 ] , V_4 -> V_32 , V_4 -> V_18 ) ;
V_9 += V_4 -> V_18 ;
}
F_7 ( L_3 ) ;
F_8 ( V_7 , V_9 , F_7 ) ;
V_6 = F_9 ( V_2 , F_10 ( V_2 , 0x02 ) , V_7 , V_9 ,
& V_5 , V_33 ) ;
if ( V_6 )
F_6 ( L_4 , V_6 , V_9 , V_5 ) ;
else
if ( V_5 != V_9 )
V_6 = - 1 ;
if ( V_6 )
goto V_30;
if ( V_4 -> V_13 == V_28 || V_4 -> V_13 == V_21 )
goto V_34;
V_9 = F_4 ;
if ( ! V_8 )
V_9 += V_4 -> V_18 ;
V_6 = F_9 ( V_2 , F_11 ( V_2 , 0x81 ) , V_7 , V_9 ,
& V_5 , V_33 ) ;
if ( V_6 ) {
F_6 ( L_5 , V_6 ) ;
V_6 = - 1 ;
goto V_30;
}
F_7 ( L_6 ) ;
F_8 ( V_7 , V_5 , F_7 ) ;
if ( V_7 [ 1 ] ) {
F_6 ( L_7 , V_7 [ 1 ] ) ;
V_6 = - 1 ;
goto V_30;
}
if ( ! V_8 )
memcpy ( V_4 -> V_32 , & V_7 [ F_4 ] , V_4 -> V_18 ) ;
V_30:
V_34:
F_12 ( & V_11 ) ;
return V_6 ;
}
static int F_13 ( struct V_35 * V_36 , struct V_3 * V_4 )
{
return F_1 ( V_36 -> V_2 , V_4 ) ;
}
static int F_14 ( struct V_35 * V_36 , T_2 V_15 , T_1 * V_37 ,
T_1 V_38 )
{
struct V_3 V_4 = { V_25 , V_39 , V_15 , 0 , 0 , V_38 ,
V_37 } ;
return F_13 ( V_36 , & V_4 ) ;
}
static int F_15 ( struct V_35 * V_36 , T_2 V_15 , T_1 V_37 )
{
return F_14 ( V_36 , V_15 , & V_37 , 1 ) ;
}
static int F_16 ( struct V_35 * V_36 , T_2 V_15 , T_1 * V_37 , T_1 V_38 )
{
struct V_3 V_4 = { V_20 , V_39 , V_15 , 0 , 0 , V_38 ,
V_37 } ;
return F_13 ( V_36 , & V_4 ) ;
}
static int F_17 ( struct V_35 * V_36 , T_2 V_15 , T_1 * V_37 )
{
return F_16 ( V_36 , V_15 , V_37 , 1 ) ;
}
static int F_18 ( struct V_35 * V_36 , T_1 V_15 , T_2 V_40 ,
T_1 V_37 )
{
struct V_3 V_4 = { V_23 , V_15 , V_40 , 1 , 1 , 1 , & V_37 } ;
if ( V_15 == V_41 [ 0 ] . V_42 ||
V_15 == V_41 [ 1 ] . V_42 )
V_4 . V_17 = 3 ;
return F_13 ( V_36 , & V_4 ) ;
}
static int F_19 ( struct V_35 * V_36 , T_1 V_15 , T_2 V_40 ,
T_1 * V_37 )
{
struct V_3 V_4 = { V_22 , V_15 , V_40 , 0 , 1 , 1 , V_37 } ;
if ( V_15 == V_41 [ 0 ] . V_42 ||
V_15 == V_41 [ 1 ] . V_42 )
V_4 . V_17 = 3 ;
return F_13 ( V_36 , & V_4 ) ;
}
static int F_20 ( struct V_43 * V_44 , struct V_45 V_46 [] ,
int V_47 )
{
struct V_35 * V_36 = F_21 ( V_44 ) ;
int V_6 = 0 , V_48 = 0 ;
T_2 V_15 ;
T_1 V_49 ( V_16 ) , V_17 ;
struct V_3 V_4 ;
if ( F_5 ( & V_36 -> V_50 ) < 0 )
return - V_12 ;
while ( V_48 < V_47 ) {
if ( V_46 [ V_48 ] . V_15 == V_41 [ 0 ] . V_42 ||
V_46 [ V_48 ] . V_15 == V_41 [ 1 ] . V_42 ) {
V_15 = V_46 [ V_48 ] . V_7 [ 0 ] << 8 ;
V_15 += V_46 [ V_48 ] . V_7 [ 1 ] ;
V_16 = V_46 [ V_48 ] . V_7 [ 2 ] ;
V_17 = 3 ;
} else {
V_15 = V_46 [ V_48 ] . V_7 [ 0 ] ;
V_17 = 1 ;
}
if ( V_47 > V_48 + 1 && ( V_46 [ V_48 + 1 ] . V_51 & V_52 ) ) {
if ( V_46 [ V_48 ] . V_38 > 3 || V_46 [ V_48 + 1 ] . V_38 > 61 ) {
V_6 = - V_53 ;
goto error;
}
if ( V_46 [ V_48 ] . V_15 ==
V_41 [ 0 ] . V_42 )
V_4 . V_13 = V_20 ;
else
V_4 . V_13 = V_22 ;
V_4 . V_14 = V_46 [ V_48 ] . V_15 ;
V_4 . V_15 = V_15 ;
V_4 . V_16 = V_16 ;
V_4 . V_17 = V_17 ;
V_4 . V_18 = V_46 [ V_48 + 1 ] . V_38 ;
V_4 . V_32 = & V_46 [ V_48 + 1 ] . V_7 [ 0 ] ;
V_6 = F_13 ( V_36 , & V_4 ) ;
V_48 += 2 ;
} else if ( V_46 [ V_48 ] . V_51 & V_52 ) {
if ( V_46 [ V_48 ] . V_38 > 61 ) {
V_6 = - V_53 ;
goto error;
}
if ( V_46 [ V_48 ] . V_15 ==
V_41 [ 0 ] . V_42 ) {
V_6 = - V_31 ;
goto error;
}
V_4 . V_13 = V_22 ;
V_4 . V_14 = V_46 [ V_48 ] . V_15 ;
V_4 . V_15 = V_15 ;
V_4 . V_16 = V_16 ;
V_4 . V_17 = V_17 ;
V_4 . V_18 = V_46 [ V_48 ] . V_38 ;
V_4 . V_32 = & V_46 [ V_48 ] . V_7 [ 0 ] ;
V_6 = F_13 ( V_36 , & V_4 ) ;
V_48 += 1 ;
} else {
if ( V_46 [ V_48 ] . V_38 > 21 ) {
V_6 = - V_53 ;
goto error;
}
if ( V_46 [ V_48 ] . V_15 ==
V_41 [ 0 ] . V_42 )
V_4 . V_13 = V_25 ;
else
V_4 . V_13 = V_23 ;
V_4 . V_14 = V_46 [ V_48 ] . V_15 ;
V_4 . V_15 = V_15 ;
V_4 . V_16 = V_16 ;
V_4 . V_17 = V_17 ;
V_4 . V_18 = V_46 [ V_48 ] . V_38 - V_17 ;
V_4 . V_32 = & V_46 [ V_48 ] . V_7 [ V_17 ] ;
V_6 = F_13 ( V_36 , & V_4 ) ;
V_48 += 1 ;
}
if ( V_6 )
goto error;
}
V_6 = V_48 ;
error:
F_12 ( & V_36 -> V_50 ) ;
return V_6 ;
}
static T_3 F_22 ( struct V_43 * V_54 )
{
return V_55 ;
}
static int F_23 ( struct V_35 * V_36 , T_2 V_15 , T_1 V_56 , T_1 V_57 )
{
int V_6 ;
T_1 V_37 , V_58 = 0x01 ;
V_6 = F_17 ( V_36 , V_15 , & V_37 ) ;
if ( V_6 )
return V_6 ;
V_58 <<= V_56 ;
if ( V_57 ) {
V_37 |= V_58 ;
} else {
V_58 ^= 0xff ;
V_37 &= V_58 ;
}
return F_15 ( V_36 , V_15 , V_37 ) ;
}
static int F_24 ( struct V_35 * V_36 , T_2 V_15 , T_1 V_56 )
{
return F_23 ( V_36 , V_15 , V_56 , 1 ) ;
}
static int F_25 ( struct V_35 * V_36 , T_2 V_15 , T_1 V_56 )
{
return F_23 ( V_36 , V_15 , V_56 , 0 ) ;
}
static int F_26 ( struct V_35 * V_36 )
{
int V_6 ;
T_2 V_59 ;
T_1 V_60 ;
F_27 ( L_8 , V_61 , V_36 -> V_2 -> V_62 ) ;
#define F_28 188
#define F_29 87
#define F_30 (TS_PACKET_SIZE*TS_USB20_PACKET_COUNT)
#define F_31 5
#define F_32 (TS_PACKET_SIZE*TS_USB11_PACKET_COUNT)
#define F_33 512
#define F_34 64
if ( V_36 -> V_2 -> V_62 == V_63 ) {
V_59 = F_32 / 4 ;
V_60 = F_34 / 4 ;
} else {
V_59 = F_30 / 4 ;
V_60 = F_33 / 4 ;
}
V_6 = F_24 ( V_36 , 0xd507 , 2 ) ;
if ( V_6 )
goto error;
V_6 = F_24 ( V_36 , 0xd50b , 1 ) ;
if ( V_6 )
goto error;
V_6 = F_25 ( V_36 , 0xdd11 , 5 ) ;
if ( V_6 )
goto error;
V_6 = F_25 ( V_36 , 0xdd11 , 6 ) ;
if ( V_6 )
goto error;
V_6 = F_24 ( V_36 , 0xdd11 , 5 ) ;
if ( V_6 )
goto error;
if ( V_64 . V_65 ) {
V_6 = F_24 ( V_36 , 0xdd11 , 6 ) ;
if ( V_6 )
goto error;
}
V_6 = F_25 ( V_36 , 0xdd13 , 5 ) ;
if ( V_6 )
goto error;
if ( V_64 . V_65 ) {
V_6 = F_25 ( V_36 , 0xdd13 , 6 ) ;
if ( V_6 )
goto error;
}
V_6 = F_15 ( V_36 , 0xdd88 , V_59 & 0xff ) ;
if ( V_6 )
goto error;
V_6 = F_15 ( V_36 , 0xdd89 , V_59 >> 8 ) ;
if ( V_6 )
goto error;
V_6 = F_15 ( V_36 , 0xdd8a , V_59 & 0xff ) ;
if ( V_6 )
goto error;
V_6 = F_15 ( V_36 , 0xdd8b , V_59 >> 8 ) ;
if ( V_6 )
goto error;
V_6 = F_15 ( V_36 , 0xdd0c , V_60 ) ;
if ( V_6 )
goto error;
V_6 = F_15 ( V_36 , 0xdd0d , V_60 ) ;
if ( V_6 )
goto error;
V_6 = F_25 ( V_36 , 0xd507 , 2 ) ;
if ( V_6 )
goto error;
if ( V_64 . V_65 ) {
V_6 = F_25 ( V_36 , 0xd50b , 1 ) ;
if ( V_6 )
goto error;
}
if ( V_64 . V_65 )
V_6 = F_24 ( V_36 , 0xd50b , 0 ) ;
else
V_6 = F_25 ( V_36 , 0xd50b , 0 ) ;
error:
if ( V_6 )
F_6 ( L_9 , V_6 ) ;
return V_6 ;
}
static int F_35 ( struct V_35 * V_36 )
{
int V_6 ;
T_1 V_66 [ 4 ] ;
T_1 V_37 , V_48 ;
struct V_3 V_4 = { V_27 , 0 , 0x5100 , 0 , 0 , sizeof( V_66 ) ,
V_66 } ;
F_27 ( L_10 , V_61 ) ;
V_66 [ 0 ] = V_64 . V_67 >> 8 ;
V_66 [ 1 ] = V_64 . V_67 & 0xff ;
V_66 [ 2 ] = V_64 . V_68 >> 8 ;
V_66 [ 3 ] = V_64 . V_68 & 0xff ;
F_36 ( 100 ) ;
V_6 = F_19 ( V_36 ,
V_41 [ 1 ] . V_42 , 0x98be , & V_37 ) ;
if ( V_6 )
goto error;
else
F_27 ( L_11 , V_61 , V_37 ) ;
if ( V_37 == 0x0c )
goto exit;
V_6 = F_15 ( V_36 , 0xd416 , 0x04 ) ;
if ( V_6 )
goto error;
F_36 ( 50 ) ;
V_6 = F_13 ( V_36 , & V_4 ) ;
if ( V_6 )
F_6 ( L_12 , V_6 ) ;
F_27 ( L_13 , V_61 ) ;
V_6 = F_15 ( V_36 , 0xd416 , 0x14 ) ;
if ( V_6 )
goto error;
V_6 = F_18 ( V_36 , V_41 [ 1 ] . V_42 ,
0xe205 , 1 ) ;
F_27 ( L_14 , V_61 , V_6 ) ;
if ( V_6 )
goto error;
for ( V_48 = 0 ; V_48 < 15 ; V_48 ++ ) {
F_36 ( 100 ) ;
V_6 = F_19 ( V_36 ,
V_41 [ 1 ] . V_42 , 0x98be , & V_37 ) ;
F_27 ( L_15 ,
V_61 , V_6 , V_37 ) ;
if ( V_6 )
goto error;
if ( V_37 == 0x0c || V_37 == 0x04 )
break;
}
if ( V_37 == 0x04 ) {
F_6 ( L_16 ) ;
V_6 = - 1 ;
} else if ( V_37 != 0x0c ) {
F_6 ( L_17 ) ;
V_6 = - 1 ;
}
error:
exit:
return V_6 ;
}
static int F_37 ( struct V_1 * V_2 )
{
static const unsigned int V_69 = 256 ;
unsigned int V_40 ;
int V_6 ;
T_1 V_37 , * V_70 ;
struct V_3 V_4 = { V_22 , V_71 , 0 , 0 , 1 , 1 , & V_37 } ;
V_70 = F_38 ( V_69 , V_72 ) ;
if ( V_70 == NULL )
return - V_73 ;
for ( V_40 = 0 ; V_40 < V_69 ; V_40 ++ ) {
V_4 . V_15 = V_40 ;
V_6 = F_1 ( V_2 , & V_4 ) ;
if ( V_6 )
goto free;
V_70 [ V_40 ] = V_37 ;
}
if ( V_74 & 0x01 )
F_39 ( L_18 , V_75 , V_70 ,
V_69 ) ;
F_40 ( V_69 % 4 ) ;
V_64 . V_76 = 0 ;
for ( V_40 = 0 ; V_40 < V_69 / sizeof( T_3 ) ; V_40 ++ ) {
V_64 . V_76 *= V_77 ;
V_64 . V_76 += F_41 ( ( ( T_3 * ) V_70 ) [ V_40 ] ) ;
}
F_27 ( L_19 , V_61 , V_64 . V_76 ) ;
V_6 = 0 ;
free:
F_42 ( V_70 ) ;
return V_6 ;
}
static int F_43 ( struct V_35 * V_36 )
{
int V_6 ;
F_27 ( L_10 , V_61 ) ;
V_6 = F_15 ( V_36 , 0x98e9 , 0xff ) ;
if ( V_6 )
goto error;
V_6 = F_26 ( V_36 ) ;
if ( V_6 )
goto error;
error:
return V_6 ;
}
static int F_44 ( struct V_78 * V_44 , int V_79 )
{
int V_6 ;
F_27 ( L_20 , V_61 , V_79 ) ;
if ( V_79 )
V_6 = F_24 ( V_44 -> V_80 , 0xd503 , 0 ) ;
else
V_6 = F_25 ( V_44 -> V_80 , 0xd503 , 0 ) ;
return V_6 ;
}
static int F_45 ( struct V_78 * V_44 , int V_81 , T_2 V_82 ,
int V_79 )
{
int V_6 ;
T_1 V_83 ;
F_27 ( L_21 ,
V_61 , V_81 , V_82 , V_79 ) ;
V_6 = F_15 ( V_44 -> V_80 , 0xd505 , ( V_82 & 0xff ) ) ;
if ( V_6 )
goto error;
V_6 = F_15 ( V_44 -> V_80 , 0xd506 , ( V_82 >> 8 ) ) ;
if ( V_6 )
goto error;
V_83 = ( ( V_81 & 0x1f ) | ( 1 << 5 ) ) ;
V_6 = F_15 ( V_44 -> V_80 , 0xd504 , V_83 ) ;
error:
return V_6 ;
}
static int F_46 ( struct V_1 * V_2 ,
const struct V_84 * V_85 )
{
int V_48 , V_38 , V_86 , V_6 ;
struct V_3 V_4 = { V_28 , 0 , 0 , 0 , 0 , 0 , NULL } ;
T_2 V_87 = 0 ;
F_27 ( L_10 , V_61 ) ;
for ( V_48 = 0 ; V_48 < V_85 -> V_88 ; V_48 ++ )
V_87 += V_85 -> V_32 [ V_48 ] ;
V_64 . V_67 = V_85 -> V_88 ;
V_64 . V_68 = V_87 ;
#define F_47 0x5100
#define F_48 55
for ( V_86 = V_85 -> V_88 ; V_86 > 0 ; V_86 -= F_48 ) {
V_38 = V_86 ;
if ( V_38 > F_48 )
V_38 = F_48 ;
V_4 . V_18 = V_38 ;
V_4 . V_32 = ( T_1 * ) & V_85 -> V_32 [ V_85 -> V_88 - V_86 ] ;
V_4 . V_15 = F_47 + V_85 -> V_88 - V_86 ;
V_6 = F_1 ( V_2 , & V_4 ) ;
if ( V_6 ) {
F_6 ( L_22 , V_6 ) ;
goto error;
}
}
V_4 . V_13 = V_29 ;
V_6 = F_1 ( V_2 , & V_4 ) ;
if ( V_6 ) {
F_6 ( L_23 , V_6 ) ;
goto error;
}
error:
return V_6 ;
}
static char * F_49 ( unsigned int V_89 ,
const struct V_90 * V_91 )
{
for (; V_91 -> V_92 ; V_91 ++ )
if ( V_91 -> V_89 == V_89 )
return V_91 -> V_92 ;
return NULL ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_93 * V_94 )
{
T_2 V_95 = F_51 ( V_2 -> V_96 . V_97 ) ;
T_2 V_82 = F_51 ( V_2 -> V_96 . V_98 ) ;
V_94 -> V_99 . V_100 . V_92 = F_49 (
V_101 , V_102 ) ;
if ( ! V_94 -> V_99 . V_100 . V_92 )
V_94 -> V_99 . V_100 . V_92 = F_49 (
V_64 . V_76 , V_103 ) ;
if ( ! V_94 -> V_99 . V_100 . V_92 )
V_94 -> V_99 . V_100 . V_92 = F_49 (
( V_95 << 16 ) + V_82 , V_104 ) ;
if ( ! V_94 -> V_99 . V_100 . V_92 && V_95 == V_105 ) {
char V_106 [ 10 ] ;
memset ( V_106 , 0 , sizeof( V_106 ) ) ;
F_52 ( V_2 , V_2 -> V_96 . V_107 ,
V_106 , sizeof( V_106 ) ) ;
if ( ! strcmp ( L_24 , V_106 ) ) {
V_94 -> V_99 . V_100 . V_92 = F_49 (
V_108 ,
V_102 ) ;
}
}
if ( ! V_94 -> V_99 . V_100 . V_92 )
V_94 -> V_99 . V_100 . V_92 = V_109 ;
return;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_6 ;
T_1 V_37 , V_48 , V_110 = 0 ;
struct V_3 V_4 = { V_22 , V_71 , 0 , 0 , 1 , 1 , & V_37 } ;
V_4 . V_15 = V_111 ;
for ( V_48 = 0 ; V_48 < 4 ; V_48 ++ ) {
V_6 = F_1 ( V_2 , & V_4 ) ;
if ( ! V_6 )
break;
}
if ( V_6 )
goto error;
V_6 = F_37 ( V_2 ) ;
if ( V_6 )
goto error;
F_27 ( L_25 , V_61 , V_37 ) ;
for ( V_48 = 0 ; V_48 < V_112 ; V_48 ++ ) {
if ( V_37 == V_113 )
V_114 [ V_48 ] . V_99 . V_100 . V_92 = NULL ;
else
F_50 ( V_2 , & V_114 [ V_48 ] ) ;
}
V_4 . V_15 = V_115 ;
V_6 = F_1 ( V_2 , & V_4 ) ;
if ( V_6 )
goto error;
V_64 . V_65 = V_37 ;
F_27 ( L_26 , V_61 , V_64 . V_65 ) ;
for ( V_48 = 0 ; V_48 < V_112 ; V_48 ++ ) {
if ( V_2 -> V_62 == V_63 ) {
V_114 [ V_48 ] . V_54 [ 0 ] . V_116 . V_117 . V_118 . V_119
= F_32 ;
V_64 . V_65 = 0 ;
} else {
V_114 [ V_48 ] . V_54 [ 0 ] . V_116 . V_117 . V_118 . V_119
= F_30 ;
}
}
if ( V_64 . V_65 ) {
V_4 . V_15 = V_120 ;
V_6 = F_1 ( V_2 , & V_4 ) ;
if ( V_6 )
goto error;
V_41 [ 1 ] . V_42 = V_37 ;
for ( V_48 = 0 ; V_48 < V_112 ; V_48 ++ )
V_114 [ V_48 ] . V_121 = 2 ;
} else {
for ( V_48 = 0 ; V_48 < V_112 ; V_48 ++ )
V_114 [ V_48 ] . V_121 = 1 ;
}
for ( V_48 = 0 ; V_48 < V_114 [ 0 ] . V_121 ; V_48 ++ ) {
if ( V_48 == 1 )
V_110 = V_122 ;
V_4 . V_15 = V_123 + V_110 ;
V_6 = F_1 ( V_2 , & V_4 ) ;
if ( V_6 )
goto error;
switch ( V_37 ) {
case 0 :
V_41 [ V_48 ] . V_124 = 28800 ;
break;
case 1 :
V_41 [ V_48 ] . V_124 = 20480 ;
break;
case 2 :
V_41 [ V_48 ] . V_124 = 28000 ;
break;
case 3 :
V_41 [ V_48 ] . V_124 = 25000 ;
break;
} ;
F_27 ( L_27 , V_61 , V_48 ,
V_37 , V_41 [ V_48 ] . V_124 ) ;
V_4 . V_15 = V_125 + V_110 ;
V_6 = F_1 ( V_2 , & V_4 ) ;
if ( V_6 )
goto error;
V_41 [ V_48 ] . V_126 = V_37 << 8 ;
V_4 . V_15 = V_127 + V_110 ;
V_6 = F_1 ( V_2 , & V_4 ) ;
if ( V_6 )
goto error;
V_41 [ V_48 ] . V_126 += V_37 ;
F_27 ( L_28 , V_61 , V_48 ,
V_41 [ 0 ] . V_126 ) ;
V_4 . V_15 = V_128 + V_110 ;
V_6 = F_1 ( V_2 , & V_4 ) ;
if ( V_6 )
goto error;
V_64 . V_129 [ V_48 ] = V_37 << 8 ;
V_4 . V_15 = V_130 + V_110 ;
V_6 = F_1 ( V_2 , & V_4 ) ;
if ( V_6 )
goto error;
V_64 . V_129 [ V_48 ] += V_37 ;
F_27 ( L_29 , V_61 , V_48 ,
V_64 . V_129 [ V_48 ] ) ;
V_4 . V_15 = V_131 + V_110 ;
V_6 = F_1 ( V_2 , & V_4 ) ;
if ( V_6 )
goto error;
switch ( V_37 ) {
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
V_41 [ V_48 ] . V_140 = 1 ;
break;
case V_141 :
case V_142 :
case V_143 :
case V_144 :
V_41 [ V_48 ] . V_140 = 0 ;
break;
case V_145 :
V_41 [ V_48 ] . V_146 [ 1 ] = V_147 ;
V_41 [ V_48 ] . V_140 = 1 ;
break;
default:
F_54 ( L_30 , V_37 ) ;
return - V_148 ;
} ;
V_41 [ V_48 ] . V_149 = V_37 ;
F_27 ( L_31 , V_61 , V_48 , V_37 ) ;
}
error:
if ( V_6 )
F_6 ( L_32 , V_6 ) ;
if ( F_51 ( V_2 -> V_96 . V_97 ) == V_150 &&
( ( F_51 ( V_2 -> V_96 . V_98 ) ==
V_151 ) ||
( F_51 ( V_2 -> V_96 . V_98 ) ==
V_152 ) ) ) {
F_27 ( L_33 , V_61 ) ;
V_64 . V_65 = 0 ;
for ( V_48 = 0 ; V_48 < V_112 ; V_48 ++ )
V_114 [ V_48 ] . V_121 = 1 ;
V_41 [ 0 ] . V_126 = 4570 ;
}
return V_6 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_93 * V_94 ,
struct V_153 * * V_154 ,
int * V_155 )
{
int V_6 ;
T_1 V_156 ;
struct V_3 V_4 = { V_19 , 0 , 0 , 0 , 0 , 1 , & V_156 } ;
V_6 = F_1 ( V_2 , & V_4 ) ;
if ( V_6 )
return V_6 ;
F_27 ( L_34 , V_61 , V_156 ) ;
if ( V_156 == 0x02 )
* V_155 = 0 ;
else
* V_155 = 1 ;
return V_6 ;
}
static int F_56 ( struct V_35 * V_36 )
{
struct V_157 * V_158 = V_36 -> V_158 ;
int V_6 ;
T_1 V_7 [ 17 ] ;
V_6 = F_16 ( V_36 , 0x98d9 , V_7 , sizeof( V_7 ) ) ;
if ( V_6 )
goto error;
if ( V_7 [ 1 ] || V_7 [ 2 ] || V_7 [ 3 ] )
return V_6 ;
if ( ( V_158 -> V_159 != V_7 [ 6 ] || V_7 [ 0 ] ) &&
! memcmp ( & V_7 [ 12 ] , V_158 -> V_160 , 4 ) ) {
F_57 ( L_35 , V_61 ) ;
F_58 ( V_36 -> V_161 , V_158 -> V_162 , 0 ) ;
V_158 -> V_159 = V_7 [ 6 ] ;
return V_6 ;
}
if ( V_7 [ 16 ] != 0xff && V_7 [ 0 ] != 0x01 ) {
F_57 ( L_36 , V_61 ,
V_7 [ 12 ] , V_7 [ 13 ] , V_7 [ 14 ] , V_7 [ 15 ] ) ;
V_6 = F_15 ( V_36 , 0x98e9 , 0xff ) ;
if ( V_6 )
goto error;
memcpy ( V_158 -> V_160 , & V_7 [ 12 ] , 4 ) ;
if ( V_7 [ 14 ] == ( T_1 ) ~ V_7 [ 15 ] ) {
if ( V_7 [ 12 ] == ( T_1 ) ~ V_7 [ 13 ] ) {
V_158 -> V_162 = V_7 [ 12 ] << 8 | V_7 [ 14 ] ;
} else {
V_158 -> V_162 = V_7 [ 12 ] << 16 |
V_7 [ 13 ] << 8 | V_7 [ 14 ] ;
}
} else {
V_158 -> V_162 = V_7 [ 12 ] << 24 | V_7 [ 13 ] << 16 |
V_7 [ 14 ] << 8 | V_7 [ 15 ] ;
}
F_58 ( V_36 -> V_161 , V_158 -> V_162 , 0 ) ;
} else {
F_57 ( L_37 , V_61 ) ;
V_158 -> V_160 [ 2 ] = V_158 -> V_160 [ 3 ] ;
}
V_158 -> V_159 = V_7 [ 6 ] ;
error:
if ( V_6 )
F_6 ( L_38 , V_61 , V_6 ) ;
return V_6 ;
}
static int F_59 ( struct V_78 * V_44 )
{
int V_6 ;
if ( V_44 -> V_89 == 1 ) {
if ( V_64 . V_65 ) {
V_6 = F_35 ( V_44 -> V_80 ) ;
if ( V_6 ) {
F_6 ( L_39 \
L_40 ) ;
V_64 . V_65 = 0 ;
return - V_148 ;
}
} else {
return - V_148 ;
}
}
V_44 -> V_163 = F_60 ( V_164 , & V_41 [ V_44 -> V_89 ] ,
& V_44 -> V_80 -> V_165 ) ;
return V_44 -> V_163 == NULL ? - V_148 : 0 ;
}
static int F_61 ( struct V_78 * V_44 )
{
int V_6 ;
F_27 ( L_10 , V_61 ) ;
switch ( V_41 [ V_44 -> V_89 ] . V_149 ) {
case V_133 :
case V_136 :
V_6 = F_60 ( V_166 , V_44 -> V_163 , & V_44 -> V_80 -> V_165 ,
& V_167 ,
V_64 . V_129 [ V_44 -> V_89 ] )
== NULL ? - V_148 : 0 ;
break;
case V_134 :
case V_138 :
V_6 = F_60 ( V_168 , V_44 -> V_163 , & V_44 -> V_80 -> V_165 ,
& V_169 ) == NULL ? - V_148 : 0 ;
break;
case V_137 :
V_6 = F_60 ( V_170 , V_44 -> V_163 , 0xc0 ,
& V_44 -> V_80 -> V_165 ,
& V_171 ) == NULL ? - V_148 : 0 ;
break;
case V_139 :
V_6 = F_60 ( V_172 , V_44 -> V_163 ,
& V_44 -> V_80 -> V_165 ,
& V_173 ) == NULL ? - V_148 : 0 ;
break;
case V_141 :
V_6 = F_60 ( V_174 , V_44 -> V_163 ,
& V_44 -> V_80 -> V_165 ,
& V_175 ) == NULL ? - V_148 : 0 ;
break;
case V_142 :
case V_143 :
V_6 = F_60 ( V_174 , V_44 -> V_163 ,
& V_44 -> V_80 -> V_165 ,
& V_176 ) == NULL ? - V_148 : 0 ;
break;
case V_132 :
V_6 = F_60 ( V_177 , V_44 -> V_163 , 0xc0 ,
& V_44 -> V_80 -> V_165 ,
V_178 ) == NULL ? - V_148 : 0 ;
break;
case V_145 :
V_6 = F_60 ( V_179 , V_44 -> V_163 ,
& V_44 -> V_80 -> V_165 ,
& V_180 ) == NULL ? - V_148 : 0 ;
break;
case V_144 :
V_6 = F_60 ( V_181 , V_44 -> V_163 ,
& V_44 -> V_80 -> V_165 ,
0xc0 , & V_182 ) == NULL ? - V_148 : 0 ;
break;
case V_135 :
default:
V_6 = - V_148 ;
F_6 ( L_41 ,
V_41 [ V_44 -> V_89 ] . V_149 ) ;
}
return V_6 ;
}
static int F_62 ( struct V_183 * V_184 ,
const struct V_185 * V_89 )
{
int V_6 = 0 ;
struct V_35 * V_36 = NULL ;
struct V_1 * V_2 = F_63 ( V_184 ) ;
T_1 V_48 ;
F_27 ( L_42 , V_61 ,
V_184 -> V_186 -> V_154 . V_187 ) ;
if ( V_184 -> V_186 -> V_154 . V_187 == 0 ) {
V_6 = F_53 ( V_2 ) ;
if ( V_6 )
return V_6 ;
for ( V_48 = 0 ; V_48 < V_112 ; V_48 ++ ) {
V_6 = F_64 ( V_184 , & V_114 [ V_48 ] ,
V_188 , & V_36 , V_189 ) ;
if ( ! V_6 )
break;
if ( V_6 != - V_148 )
return V_6 ;
}
if ( V_6 )
return V_6 ;
if ( V_36 )
V_6 = F_43 ( V_36 ) ;
}
return V_6 ;
}
static int T_4 F_65 ( void )
{
int V_6 ;
V_6 = F_66 ( & V_190 ) ;
if ( V_6 )
F_6 ( L_43 , V_6 ) ;
return V_6 ;
}
static void T_5 F_67 ( void )
{
F_68 ( & V_190 ) ;
}
