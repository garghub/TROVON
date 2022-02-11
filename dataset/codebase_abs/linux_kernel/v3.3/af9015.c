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
if ( V_15 == V_41 [ 0 ] . V_14 ||
V_15 == V_41 [ 1 ] . V_14 )
V_4 . V_17 = 3 ;
return F_13 ( V_36 , & V_4 ) ;
}
static int F_19 ( struct V_35 * V_36 , T_1 V_15 , T_2 V_40 ,
T_1 * V_37 )
{
struct V_3 V_4 = { V_22 , V_15 , V_40 , 0 , 1 , 1 , V_37 } ;
if ( V_15 == V_41 [ 0 ] . V_14 ||
V_15 == V_41 [ 1 ] . V_14 )
V_4 . V_17 = 3 ;
return F_13 ( V_36 , & V_4 ) ;
}
static int F_20 ( struct V_42 * V_43 , struct V_44 V_45 [] ,
int V_46 )
{
struct V_35 * V_36 = F_21 ( V_43 ) ;
int V_6 = 0 , V_47 = 0 ;
T_2 V_15 ;
T_1 V_48 ( V_16 ) , V_17 ;
struct V_3 V_4 ;
if ( F_5 ( & V_36 -> V_49 ) < 0 )
return - V_12 ;
while ( V_47 < V_46 ) {
if ( V_45 [ V_47 ] . V_15 == V_41 [ 0 ] . V_14 ||
V_45 [ V_47 ] . V_15 == V_41 [ 1 ] . V_14 ) {
V_15 = V_45 [ V_47 ] . V_7 [ 0 ] << 8 ;
V_15 += V_45 [ V_47 ] . V_7 [ 1 ] ;
V_16 = V_45 [ V_47 ] . V_7 [ 2 ] ;
V_17 = 3 ;
} else {
V_15 = V_45 [ V_47 ] . V_7 [ 0 ] ;
V_17 = 1 ;
}
if ( V_46 > V_47 + 1 && ( V_45 [ V_47 + 1 ] . V_50 & V_51 ) ) {
if ( V_45 [ V_47 ] . V_38 > 3 || V_45 [ V_47 + 1 ] . V_38 > 61 ) {
V_6 = - V_52 ;
goto error;
}
if ( V_45 [ V_47 ] . V_15 == V_41 [ 0 ] . V_14 )
V_4 . V_13 = V_20 ;
else
V_4 . V_13 = V_22 ;
V_4 . V_14 = V_45 [ V_47 ] . V_15 ;
V_4 . V_15 = V_15 ;
V_4 . V_16 = V_16 ;
V_4 . V_17 = V_17 ;
V_4 . V_18 = V_45 [ V_47 + 1 ] . V_38 ;
V_4 . V_32 = & V_45 [ V_47 + 1 ] . V_7 [ 0 ] ;
V_6 = F_13 ( V_36 , & V_4 ) ;
V_47 += 2 ;
} else if ( V_45 [ V_47 ] . V_50 & V_51 ) {
if ( V_45 [ V_47 ] . V_38 > 61 ) {
V_6 = - V_52 ;
goto error;
}
if ( V_45 [ V_47 ] . V_15 ==
V_41 [ 0 ] . V_14 ) {
V_6 = - V_31 ;
goto error;
}
V_4 . V_13 = V_22 ;
V_4 . V_14 = V_45 [ V_47 ] . V_15 ;
V_4 . V_15 = V_15 ;
V_4 . V_16 = V_16 ;
V_4 . V_17 = V_17 ;
V_4 . V_18 = V_45 [ V_47 ] . V_38 ;
V_4 . V_32 = & V_45 [ V_47 ] . V_7 [ 0 ] ;
V_6 = F_13 ( V_36 , & V_4 ) ;
V_47 += 1 ;
} else {
if ( V_45 [ V_47 ] . V_38 > 21 ) {
V_6 = - V_52 ;
goto error;
}
if ( V_45 [ V_47 ] . V_15 == V_41 [ 0 ] . V_14 )
V_4 . V_13 = V_25 ;
else
V_4 . V_13 = V_23 ;
V_4 . V_14 = V_45 [ V_47 ] . V_15 ;
V_4 . V_15 = V_15 ;
V_4 . V_16 = V_16 ;
V_4 . V_17 = V_17 ;
V_4 . V_18 = V_45 [ V_47 ] . V_38 - V_17 ;
V_4 . V_32 = & V_45 [ V_47 ] . V_7 [ V_17 ] ;
V_6 = F_13 ( V_36 , & V_4 ) ;
V_47 += 1 ;
}
if ( V_6 )
goto error;
}
V_6 = V_47 ;
error:
F_12 ( & V_36 -> V_49 ) ;
return V_6 ;
}
static T_3 F_22 ( struct V_42 * V_53 )
{
return V_54 ;
}
static int F_23 ( struct V_35 * V_36 , T_2 V_15 , T_1 V_55 , T_1 V_56 )
{
int V_6 ;
T_1 V_37 , V_57 = 0x01 ;
V_6 = F_17 ( V_36 , V_15 , & V_37 ) ;
if ( V_6 )
return V_6 ;
V_57 <<= V_55 ;
if ( V_56 ) {
V_37 |= V_57 ;
} else {
V_57 ^= 0xff ;
V_37 &= V_57 ;
}
return F_15 ( V_36 , V_15 , V_37 ) ;
}
static int F_24 ( struct V_35 * V_36 , T_2 V_15 , T_1 V_55 )
{
return F_23 ( V_36 , V_15 , V_55 , 1 ) ;
}
static int F_25 ( struct V_35 * V_36 , T_2 V_15 , T_1 V_55 )
{
return F_23 ( V_36 , V_15 , V_55 , 0 ) ;
}
static int F_26 ( struct V_35 * V_36 )
{
int V_6 ;
T_2 V_58 ;
T_1 V_59 ;
F_27 ( L_8 , V_60 , V_36 -> V_2 -> V_61 ) ;
#define F_28 188
#define F_29 87
#define F_30 (TS_PACKET_SIZE*TS_USB20_PACKET_COUNT)
#define F_31 5
#define F_32 (TS_PACKET_SIZE*TS_USB11_PACKET_COUNT)
#define F_33 512
#define F_34 64
if ( V_36 -> V_2 -> V_61 == V_62 ) {
V_58 = F_32 / 4 ;
V_59 = F_34 / 4 ;
} else {
V_58 = F_30 / 4 ;
V_59 = F_33 / 4 ;
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
if ( V_63 . V_64 ) {
V_6 = F_24 ( V_36 , 0xdd11 , 6 ) ;
if ( V_6 )
goto error;
}
V_6 = F_25 ( V_36 , 0xdd13 , 5 ) ;
if ( V_6 )
goto error;
if ( V_63 . V_64 ) {
V_6 = F_25 ( V_36 , 0xdd13 , 6 ) ;
if ( V_6 )
goto error;
}
V_6 = F_15 ( V_36 , 0xdd88 , V_58 & 0xff ) ;
if ( V_6 )
goto error;
V_6 = F_15 ( V_36 , 0xdd89 , V_58 >> 8 ) ;
if ( V_6 )
goto error;
V_6 = F_15 ( V_36 , 0xdd8a , V_58 & 0xff ) ;
if ( V_6 )
goto error;
V_6 = F_15 ( V_36 , 0xdd8b , V_58 >> 8 ) ;
if ( V_6 )
goto error;
V_6 = F_15 ( V_36 , 0xdd0c , V_59 ) ;
if ( V_6 )
goto error;
V_6 = F_15 ( V_36 , 0xdd0d , V_59 ) ;
if ( V_6 )
goto error;
V_6 = F_25 ( V_36 , 0xd507 , 2 ) ;
if ( V_6 )
goto error;
if ( V_63 . V_64 ) {
V_6 = F_25 ( V_36 , 0xd50b , 1 ) ;
if ( V_6 )
goto error;
}
if ( V_63 . V_64 )
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
T_1 V_65 [ 4 ] ;
T_1 V_37 , V_47 ;
struct V_3 V_4 = { V_27 , 0 , 0x5100 , 0 , 0 , sizeof( V_65 ) ,
V_65 } ;
F_27 ( L_10 , V_60 ) ;
V_65 [ 0 ] = V_63 . V_66 >> 8 ;
V_65 [ 1 ] = V_63 . V_66 & 0xff ;
V_65 [ 2 ] = V_63 . V_67 >> 8 ;
V_65 [ 3 ] = V_63 . V_67 & 0xff ;
F_36 ( 100 ) ;
V_6 = F_19 ( V_36 ,
V_41 [ 1 ] . V_14 , 0x98be , & V_37 ) ;
if ( V_6 )
goto error;
else
F_27 ( L_11 , V_60 , V_37 ) ;
if ( V_37 == 0x0c )
goto exit;
V_6 = F_15 ( V_36 , 0xd416 , 0x04 ) ;
if ( V_6 )
goto error;
F_36 ( 50 ) ;
V_6 = F_13 ( V_36 , & V_4 ) ;
if ( V_6 )
F_6 ( L_12 , V_6 ) ;
F_27 ( L_13 , V_60 ) ;
V_6 = F_15 ( V_36 , 0xd416 , 0x14 ) ;
if ( V_6 )
goto error;
V_6 = F_18 ( V_36 , V_41 [ 1 ] . V_14 ,
0xe205 , 1 ) ;
F_27 ( L_14 , V_60 , V_6 ) ;
if ( V_6 )
goto error;
for ( V_47 = 0 ; V_47 < 15 ; V_47 ++ ) {
F_36 ( 100 ) ;
V_6 = F_19 ( V_36 ,
V_41 [ 1 ] . V_14 , 0x98be , & V_37 ) ;
F_27 ( L_15 ,
V_60 , V_6 , V_37 ) ;
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
static const unsigned int V_68 = 256 ;
unsigned int V_40 ;
int V_6 ;
T_1 V_37 , * V_69 ;
struct V_3 V_4 = { V_22 , V_70 , 0 , 0 , 1 , 1 , & V_37 } ;
V_69 = F_38 ( V_68 , V_71 ) ;
if ( V_69 == NULL )
return - V_72 ;
for ( V_40 = 0 ; V_40 < V_68 ; V_40 ++ ) {
V_4 . V_15 = V_40 ;
V_6 = F_1 ( V_2 , & V_4 ) ;
if ( V_6 )
goto free;
V_69 [ V_40 ] = V_37 ;
}
if ( V_73 & 0x01 )
F_39 ( L_18 , V_74 , V_69 ,
V_68 ) ;
F_40 ( V_68 % 4 ) ;
V_63 . V_75 = 0 ;
for ( V_40 = 0 ; V_40 < V_68 / sizeof( T_3 ) ; V_40 ++ ) {
V_63 . V_75 *= V_76 ;
V_63 . V_75 += F_41 ( ( ( T_3 * ) V_69 ) [ V_40 ] ) ;
}
F_27 ( L_19 , V_60 , V_63 . V_75 ) ;
V_6 = 0 ;
free:
F_42 ( V_69 ) ;
return V_6 ;
}
static int F_43 ( struct V_35 * V_36 )
{
int V_6 ;
F_27 ( L_10 , V_60 ) ;
V_6 = F_15 ( V_36 , 0x98e9 , 0xff ) ;
if ( V_6 )
goto error;
V_6 = F_26 ( V_36 ) ;
if ( V_6 )
goto error;
error:
return V_6 ;
}
static int F_44 ( struct V_77 * V_43 , int V_78 )
{
int V_6 ;
F_27 ( L_20 , V_60 , V_78 ) ;
if ( V_78 )
V_6 = F_24 ( V_43 -> V_79 , 0xd503 , 0 ) ;
else
V_6 = F_25 ( V_43 -> V_79 , 0xd503 , 0 ) ;
return V_6 ;
}
static int F_45 ( struct V_77 * V_43 , int V_80 , T_2 V_81 ,
int V_78 )
{
int V_6 ;
T_1 V_82 ;
F_27 ( L_21 ,
V_60 , V_80 , V_81 , V_78 ) ;
V_6 = F_15 ( V_43 -> V_79 , 0xd505 , ( V_81 & 0xff ) ) ;
if ( V_6 )
goto error;
V_6 = F_15 ( V_43 -> V_79 , 0xd506 , ( V_81 >> 8 ) ) ;
if ( V_6 )
goto error;
V_82 = ( ( V_80 & 0x1f ) | ( 1 << 5 ) ) ;
V_6 = F_15 ( V_43 -> V_79 , 0xd504 , V_82 ) ;
error:
return V_6 ;
}
static int F_46 ( struct V_1 * V_2 ,
const struct V_83 * V_84 )
{
int V_47 , V_38 , V_85 , V_6 ;
struct V_3 V_4 = { V_28 , 0 , 0 , 0 , 0 , 0 , NULL } ;
T_2 V_86 = 0 ;
F_27 ( L_10 , V_60 ) ;
for ( V_47 = 0 ; V_47 < V_84 -> V_87 ; V_47 ++ )
V_86 += V_84 -> V_32 [ V_47 ] ;
V_63 . V_66 = V_84 -> V_87 ;
V_63 . V_67 = V_86 ;
#define F_47 0x5100
#define F_48 55
for ( V_85 = V_84 -> V_87 ; V_85 > 0 ; V_85 -= F_48 ) {
V_38 = V_85 ;
if ( V_38 > F_48 )
V_38 = F_48 ;
V_4 . V_18 = V_38 ;
V_4 . V_32 = ( T_1 * ) & V_84 -> V_32 [ V_84 -> V_87 - V_85 ] ;
V_4 . V_15 = F_47 + V_84 -> V_87 - V_85 ;
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
static char * F_49 ( unsigned int V_88 ,
const struct V_89 * V_90 )
{
for (; V_90 -> V_91 ; V_90 ++ )
if ( V_90 -> V_88 == V_88 )
return V_90 -> V_91 ;
return NULL ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_92 * V_93 )
{
T_2 V_94 = F_51 ( V_2 -> V_95 . V_96 ) ;
T_2 V_81 = F_51 ( V_2 -> V_95 . V_97 ) ;
V_93 -> V_98 . V_99 . V_91 = F_49 (
V_100 , V_101 ) ;
if ( ! V_93 -> V_98 . V_99 . V_91 )
V_93 -> V_98 . V_99 . V_91 = F_49 (
V_63 . V_75 , V_102 ) ;
if ( ! V_93 -> V_98 . V_99 . V_91 )
V_93 -> V_98 . V_99 . V_91 = F_49 (
( V_94 << 16 ) + V_81 , V_103 ) ;
if ( ! V_93 -> V_98 . V_99 . V_91 && V_94 == V_104 ) {
char V_105 [ 10 ] ;
memset ( V_105 , 0 , sizeof( V_105 ) ) ;
F_52 ( V_2 , V_2 -> V_95 . V_106 ,
V_105 , sizeof( V_105 ) ) ;
if ( ! strcmp ( L_24 , V_105 ) ) {
V_93 -> V_98 . V_99 . V_91 = F_49 (
V_107 ,
V_101 ) ;
}
}
if ( ! V_93 -> V_98 . V_99 . V_91 )
V_93 -> V_98 . V_99 . V_91 = V_108 ;
return;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_6 ;
T_1 V_37 , V_47 , V_109 = 0 ;
struct V_3 V_4 = { V_22 , V_70 , 0 , 0 , 1 , 1 , & V_37 } ;
V_4 . V_15 = V_110 ;
for ( V_47 = 0 ; V_47 < 4 ; V_47 ++ ) {
V_6 = F_1 ( V_2 , & V_4 ) ;
if ( ! V_6 )
break;
}
if ( V_6 )
goto error;
V_6 = F_37 ( V_2 ) ;
if ( V_6 )
goto error;
F_27 ( L_25 , V_60 , V_37 ) ;
for ( V_47 = 0 ; V_47 < V_111 ; V_47 ++ ) {
if ( V_37 == V_112 )
V_113 [ V_47 ] . V_98 . V_99 . V_91 = NULL ;
else
F_50 ( V_2 , & V_113 [ V_47 ] ) ;
}
V_4 . V_15 = V_114 ;
V_6 = F_1 ( V_2 , & V_4 ) ;
if ( V_6 )
goto error;
V_63 . V_64 = V_37 ;
F_27 ( L_26 , V_60 , V_63 . V_64 ) ;
for ( V_47 = 0 ; V_47 < V_111 ; V_47 ++ ) {
if ( V_2 -> V_61 == V_62 ) {
V_113 [ V_47 ] . V_53 [ 0 ] . V_115 [ 0 ] . V_116 . V_117 . V_118 . V_119
= F_32 ;
V_63 . V_64 = 0 ;
} else {
V_113 [ V_47 ] . V_53 [ 0 ] . V_115 [ 0 ] . V_116 . V_117 . V_118 . V_119
= F_30 ;
}
}
if ( V_63 . V_64 ) {
V_4 . V_15 = V_120 ;
V_6 = F_1 ( V_2 , & V_4 ) ;
if ( V_6 )
goto error;
V_41 [ 1 ] . V_14 = V_37 ;
for ( V_47 = 0 ; V_47 < V_111 ; V_47 ++ )
V_113 [ V_47 ] . V_121 = 2 ;
} else {
for ( V_47 = 0 ; V_47 < V_111 ; V_47 ++ )
V_113 [ V_47 ] . V_121 = 1 ;
}
for ( V_47 = 0 ; V_47 < V_113 [ 0 ] . V_121 ; V_47 ++ ) {
if ( V_47 == 1 )
V_109 = V_122 ;
V_4 . V_15 = V_123 + V_109 ;
V_6 = F_1 ( V_2 , & V_4 ) ;
if ( V_6 )
goto error;
switch ( V_37 ) {
case 0 :
V_41 [ V_47 ] . clock = 28800000 ;
break;
case 1 :
V_41 [ V_47 ] . clock = 20480000 ;
break;
case 2 :
V_41 [ V_47 ] . clock = 28000000 ;
break;
case 3 :
V_41 [ V_47 ] . clock = 25000000 ;
break;
} ;
F_27 ( L_27 , V_60 , V_47 ,
V_37 , V_41 [ V_47 ] . clock ) ;
V_4 . V_15 = V_124 + V_109 ;
V_6 = F_1 ( V_2 , & V_4 ) ;
if ( V_6 )
goto error;
V_41 [ V_47 ] . V_125 = V_37 << 8 ;
V_4 . V_15 = V_126 + V_109 ;
V_6 = F_1 ( V_2 , & V_4 ) ;
if ( V_6 )
goto error;
V_41 [ V_47 ] . V_125 += V_37 ;
V_41 [ V_47 ] . V_125 *= 1000 ;
F_27 ( L_28 , V_60 , V_47 ,
V_41 [ 0 ] . V_125 ) ;
V_4 . V_15 = V_127 + V_109 ;
V_6 = F_1 ( V_2 , & V_4 ) ;
if ( V_6 )
goto error;
V_63 . V_128 [ V_47 ] = V_37 << 8 ;
V_4 . V_15 = V_129 + V_109 ;
V_6 = F_1 ( V_2 , & V_4 ) ;
if ( V_6 )
goto error;
V_63 . V_128 [ V_47 ] += V_37 ;
F_27 ( L_29 , V_60 , V_47 ,
V_63 . V_128 [ V_47 ] ) ;
V_4 . V_15 = V_130 + V_109 ;
V_6 = F_1 ( V_2 , & V_4 ) ;
if ( V_6 )
goto error;
switch ( V_37 ) {
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
V_41 [ V_47 ] . V_139 = 1 ;
break;
case V_140 :
case V_141 :
case V_142 :
case V_143 :
V_41 [ V_47 ] . V_139 = 0 ;
break;
case V_144 :
V_41 [ V_47 ] . V_145 [ 1 ] = V_146 ;
V_41 [ V_47 ] . V_139 = 1 ;
break;
default:
F_54 ( L_30 , V_37 ) ;
return - V_147 ;
} ;
V_41 [ V_47 ] . V_148 = V_37 ;
F_27 ( L_31 , V_60 , V_47 , V_37 ) ;
}
error:
if ( V_6 )
F_6 ( L_32 , V_6 ) ;
if ( F_51 ( V_2 -> V_95 . V_96 ) == V_149 &&
( ( F_51 ( V_2 -> V_95 . V_97 ) ==
V_150 ) ||
( F_51 ( V_2 -> V_95 . V_97 ) ==
V_151 ) ) ) {
F_27 ( L_33 , V_60 ) ;
V_63 . V_64 = 0 ;
for ( V_47 = 0 ; V_47 < V_111 ; V_47 ++ )
V_113 [ V_47 ] . V_121 = 1 ;
V_41 [ 0 ] . V_125 = 4570000 ;
}
return V_6 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_92 * V_93 ,
struct V_152 * * V_153 ,
int * V_154 )
{
int V_6 ;
T_1 V_155 ;
struct V_3 V_4 = { V_19 , 0 , 0 , 0 , 0 , 1 , & V_155 } ;
V_6 = F_1 ( V_2 , & V_4 ) ;
if ( V_6 )
return V_6 ;
F_27 ( L_34 , V_60 , V_155 ) ;
if ( V_155 == 0x02 )
* V_154 = 0 ;
else
* V_154 = 1 ;
return V_6 ;
}
static int F_56 ( struct V_35 * V_36 )
{
struct V_156 * V_157 = V_36 -> V_157 ;
int V_6 ;
T_1 V_7 [ 17 ] ;
V_6 = F_16 ( V_36 , 0x98d9 , V_7 , sizeof( V_7 ) ) ;
if ( V_6 )
goto error;
if ( V_7 [ 1 ] || V_7 [ 2 ] || V_7 [ 3 ] )
return V_6 ;
if ( ( V_157 -> V_158 != V_7 [ 6 ] || V_7 [ 0 ] ) &&
! memcmp ( & V_7 [ 12 ] , V_157 -> V_159 , 4 ) ) {
F_57 ( L_35 , V_60 ) ;
F_58 ( V_36 -> V_160 , V_157 -> V_161 , 0 ) ;
V_157 -> V_158 = V_7 [ 6 ] ;
return V_6 ;
}
if ( V_7 [ 16 ] != 0xff && V_7 [ 0 ] != 0x01 ) {
F_57 ( L_36 , V_60 ,
V_7 [ 12 ] , V_7 [ 13 ] , V_7 [ 14 ] , V_7 [ 15 ] ) ;
V_6 = F_15 ( V_36 , 0x98e9 , 0xff ) ;
if ( V_6 )
goto error;
memcpy ( V_157 -> V_159 , & V_7 [ 12 ] , 4 ) ;
if ( V_7 [ 14 ] == ( T_1 ) ~ V_7 [ 15 ] ) {
if ( V_7 [ 12 ] == ( T_1 ) ~ V_7 [ 13 ] ) {
V_157 -> V_161 = V_7 [ 12 ] << 8 | V_7 [ 14 ] ;
} else {
V_157 -> V_161 = V_7 [ 12 ] << 16 |
V_7 [ 13 ] << 8 | V_7 [ 14 ] ;
}
} else {
V_157 -> V_161 = V_7 [ 12 ] << 24 | V_7 [ 13 ] << 16 |
V_7 [ 14 ] << 8 | V_7 [ 15 ] ;
}
F_58 ( V_36 -> V_160 , V_157 -> V_161 , 0 ) ;
} else {
F_57 ( L_37 , V_60 ) ;
V_157 -> V_159 [ 2 ] = V_157 -> V_159 [ 3 ] ;
}
V_157 -> V_158 = V_7 [ 6 ] ;
error:
if ( V_6 )
F_6 ( L_38 , V_60 , V_6 ) ;
return V_6 ;
}
static int F_59 ( struct V_162 * V_115 )
{
int V_6 ;
struct V_77 * V_43 = V_115 -> V_163 -> V_157 ;
struct V_156 * V_157 = V_43 -> V_79 -> V_157 ;
if ( F_5 ( & V_43 -> V_79 -> V_164 ) )
return - V_12 ;
V_6 = V_157 -> V_165 [ V_43 -> V_88 ] ( V_115 ) ;
F_12 ( & V_43 -> V_79 -> V_164 ) ;
return V_6 ;
}
static int F_60 ( struct V_162 * V_115 ,
T_4 * V_166 )
{
int V_6 ;
struct V_77 * V_43 = V_115 -> V_163 -> V_157 ;
struct V_156 * V_157 = V_43 -> V_79 -> V_157 ;
if ( F_5 ( & V_43 -> V_79 -> V_164 ) )
return - V_12 ;
V_6 = V_157 -> V_167 [ V_43 -> V_88 ] ( V_115 , V_166 ) ;
F_12 ( & V_43 -> V_79 -> V_164 ) ;
return V_6 ;
}
static int F_61 ( struct V_162 * V_115 )
{
int V_6 ;
struct V_77 * V_43 = V_115 -> V_163 -> V_157 ;
struct V_156 * V_157 = V_43 -> V_79 -> V_157 ;
if ( F_5 ( & V_43 -> V_79 -> V_164 ) )
return - V_12 ;
V_6 = V_157 -> V_168 [ V_43 -> V_88 ] ( V_115 ) ;
F_12 ( & V_43 -> V_79 -> V_164 ) ;
return V_6 ;
}
static int F_62 ( struct V_162 * V_115 )
{
int V_6 ;
struct V_77 * V_43 = V_115 -> V_163 -> V_157 ;
struct V_156 * V_157 = V_43 -> V_79 -> V_157 ;
if ( F_5 ( & V_43 -> V_79 -> V_164 ) )
return - V_12 ;
V_6 = V_157 -> V_169 [ V_43 -> V_88 ] ( V_115 ) ;
F_12 ( & V_43 -> V_79 -> V_164 ) ;
return V_6 ;
}
static int F_63 ( struct V_77 * V_43 )
{
int V_6 ;
struct V_156 * V_170 = V_43 -> V_79 -> V_157 ;
if ( V_43 -> V_88 == 1 ) {
if ( V_63 . V_64 ) {
V_6 = F_35 ( V_43 -> V_79 ) ;
if ( V_6 ) {
F_6 ( L_39 \
L_40 ) ;
V_63 . V_64 = 0 ;
return - V_147 ;
}
} else {
return - V_147 ;
}
}
V_43 -> V_171 [ 0 ] . V_115 = F_64 ( V_172 , & V_41 [ V_43 -> V_88 ] ,
& V_43 -> V_79 -> V_173 ) ;
if ( V_43 -> V_171 [ 0 ] . V_115 ) {
V_170 -> V_165 [ V_43 -> V_88 ] =
V_43 -> V_171 [ 0 ] . V_115 -> V_174 . V_165 ;
V_43 -> V_171 [ 0 ] . V_115 -> V_174 . V_165 =
F_59 ;
V_170 -> V_167 [ V_43 -> V_88 ] =
V_43 -> V_171 [ 0 ] . V_115 -> V_174 . V_167 ;
V_43 -> V_171 [ 0 ] . V_115 -> V_174 . V_167 =
F_60 ;
V_170 -> V_168 [ V_43 -> V_88 ] = V_43 -> V_171 [ 0 ] . V_115 -> V_174 . V_168 ;
V_43 -> V_171 [ 0 ] . V_115 -> V_174 . V_168 = F_61 ;
V_170 -> V_169 [ V_43 -> V_88 ] = V_43 -> V_171 [ 0 ] . V_115 -> V_174 . V_169 ;
V_43 -> V_171 [ 0 ] . V_115 -> V_174 . V_169 = F_62 ;
}
return V_43 -> V_171 [ 0 ] . V_115 == NULL ? - V_147 : 0 ;
}
static int F_65 ( struct V_77 * V_43 )
{
int V_6 ;
F_27 ( L_10 , V_60 ) ;
switch ( V_41 [ V_43 -> V_88 ] . V_148 ) {
case V_132 :
case V_135 :
V_6 = F_64 ( V_175 , V_43 -> V_171 [ 0 ] . V_115 , & V_43 -> V_79 -> V_173 ,
& V_176 ,
V_63 . V_128 [ V_43 -> V_88 ] )
== NULL ? - V_147 : 0 ;
break;
case V_133 :
case V_137 :
V_6 = F_64 ( V_177 , V_43 -> V_171 [ 0 ] . V_115 , & V_43 -> V_79 -> V_173 ,
& V_178 ) == NULL ? - V_147 : 0 ;
break;
case V_136 :
V_6 = F_64 ( V_179 , V_43 -> V_171 [ 0 ] . V_115 , 0xc0 ,
& V_43 -> V_79 -> V_173 ,
& V_180 ) == NULL ? - V_147 : 0 ;
break;
case V_138 :
V_6 = F_64 ( V_181 , V_43 -> V_171 [ 0 ] . V_115 ,
& V_43 -> V_79 -> V_173 ,
& V_182 ) == NULL ? - V_147 : 0 ;
break;
case V_140 :
V_6 = F_64 ( V_183 , V_43 -> V_171 [ 0 ] . V_115 ,
& V_43 -> V_79 -> V_173 ,
& V_184 ) == NULL ? - V_147 : 0 ;
break;
case V_141 :
case V_142 :
V_6 = F_64 ( V_183 , V_43 -> V_171 [ 0 ] . V_115 ,
& V_43 -> V_79 -> V_173 ,
& V_185 ) == NULL ? - V_147 : 0 ;
break;
case V_131 :
V_6 = F_64 ( V_186 , V_43 -> V_171 [ 0 ] . V_115 , 0xc0 ,
& V_43 -> V_79 -> V_173 ,
V_187 ) == NULL ? - V_147 : 0 ;
break;
case V_144 :
V_6 = F_64 ( V_188 , V_43 -> V_171 [ 0 ] . V_115 ,
& V_43 -> V_79 -> V_173 ,
& V_189 ) == NULL ? - V_147 : 0 ;
break;
case V_143 :
V_6 = F_64 ( V_190 , V_43 -> V_171 [ 0 ] . V_115 ,
& V_43 -> V_79 -> V_173 ,
0xc0 , & V_191 ) == NULL ? - V_147 : 0 ;
break;
case V_134 :
default:
V_6 = - V_147 ;
F_6 ( L_41 ,
V_41 [ V_43 -> V_88 ] . V_148 ) ;
}
return V_6 ;
}
static int F_66 ( struct V_192 * V_193 ,
const struct V_194 * V_88 )
{
int V_6 = 0 ;
struct V_35 * V_36 = NULL ;
struct V_1 * V_2 = F_67 ( V_193 ) ;
T_1 V_47 ;
F_27 ( L_42 , V_60 ,
V_193 -> V_195 -> V_153 . V_196 ) ;
if ( V_193 -> V_195 -> V_153 . V_196 == 0 ) {
V_6 = F_53 ( V_2 ) ;
if ( V_6 )
return V_6 ;
for ( V_47 = 0 ; V_47 < V_111 ; V_47 ++ ) {
V_6 = F_68 ( V_193 , & V_113 [ V_47 ] ,
V_197 , & V_36 , V_198 ) ;
if ( ! V_6 )
break;
if ( V_6 != - V_147 )
return V_6 ;
}
if ( V_6 )
return V_6 ;
if ( V_36 )
V_6 = F_43 ( V_36 ) ;
}
return V_6 ;
}
