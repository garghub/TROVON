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
#define F_3 64
#define F_4 4
#define F_5 3
#define F_6 2
#define F_7 2000
int V_9 , V_10 , V_11 ;
T_2 V_1 [ F_3 ] ;
static T_2 V_12 ;
T_1 V_4 , V_13 ;
if ( V_8 -> V_14 > ( F_3 - F_4 - F_6 ) ||
V_8 -> V_15 > ( F_3 - F_5 - F_6 ) ) {
F_8 ( L_1 , V_16 ,
V_8 -> V_14 , V_8 -> V_15 ) ;
return - V_17 ;
}
if ( F_9 ( & V_18 ) < 0 )
return - V_19 ;
V_1 [ 0 ] = F_4 + V_8 -> V_14 + F_6 - 1 ;
V_1 [ 1 ] = V_8 -> V_20 ;
V_1 [ 2 ] = V_8 -> V_21 ;
V_1 [ 3 ] = V_12 ++ ;
if ( V_8 -> V_14 )
memcpy ( & V_1 [ 4 ] , V_8 -> V_22 , V_8 -> V_14 ) ;
V_4 = F_1 ( V_1 , V_1 [ 0 ] - 1 ) ;
V_1 [ V_1 [ 0 ] - 1 ] = ( V_4 >> 8 ) ;
V_1 [ V_1 [ 0 ] - 0 ] = ( V_4 & 0xff ) ;
V_10 = F_4 + V_8 -> V_14 + F_6 ;
V_9 = F_10 ( V_6 , F_11 ( V_6 , 0x02 ) , V_1 , V_10 ,
& V_11 , F_7 ) ;
if ( V_9 < 0 )
F_12 ( L_2 , V_9 , V_10 , V_11 ) ;
else
if ( V_11 != V_10 )
V_9 = - V_23 ;
if ( V_9 < 0 )
goto V_24;
if ( V_8 -> V_21 == V_25 )
goto V_26;
V_10 = F_5 + V_8 -> V_15 + F_6 ;
V_9 = F_10 ( V_6 , F_13 ( V_6 , 0x81 ) , V_1 , V_10 ,
& V_11 , F_7 ) ;
if ( V_9 < 0 ) {
F_12 ( L_3 , V_9 ) ;
V_9 = - V_23 ;
goto V_24;
}
if ( V_11 != V_10 ) {
F_12 ( L_4 , V_11 , V_10 ) ;
V_9 = - V_23 ;
goto V_24;
}
V_4 = F_1 ( V_1 , V_11 - 2 ) ;
V_13 = ( V_1 [ V_11 - 2 ] << 8 ) | V_1 [ V_11 - 1 ] ;
if ( V_13 != V_4 ) {
F_12 ( L_5 ,
V_16 , V_8 -> V_21 , V_13 , V_4 ) ;
V_9 = - V_23 ;
goto V_24;
}
if ( V_1 [ 2 ] ) {
F_8 ( L_6 , V_16 ,
V_8 -> V_21 , V_1 [ 2 ] ) ;
V_9 = - V_23 ;
goto V_24;
}
if ( V_8 -> V_15 )
memcpy ( V_8 -> V_27 , & V_1 [ F_5 ] , V_8 -> V_15 ) ;
V_24:
V_26:
F_14 ( & V_18 ) ;
return V_9 ;
}
static int F_15 ( struct V_28 * V_29 , T_4 V_30 , T_2 * V_31 , int V_2 )
{
T_2 V_22 [ 6 + V_2 ] ;
T_2 V_20 = ( V_30 >> 16 ) & 0xff ;
struct V_7 V_8 = { V_32 , V_20 , sizeof( V_22 ) , V_22 , 0 , NULL } ;
V_22 [ 0 ] = V_2 ;
V_22 [ 1 ] = 2 ;
V_22 [ 2 ] = 0 ;
V_22 [ 3 ] = 0 ;
V_22 [ 4 ] = ( V_30 >> 8 ) & 0xff ;
V_22 [ 5 ] = ( V_30 >> 0 ) & 0xff ;
memcpy ( & V_22 [ 6 ] , V_31 , V_2 ) ;
return F_2 ( V_29 -> V_6 , & V_8 ) ;
}
static int F_16 ( struct V_28 * V_29 , T_4 V_30 , T_2 * V_31 , int V_2 )
{
T_2 V_22 [] = { V_2 , 2 , 0 , 0 , ( V_30 >> 8 ) & 0xff , V_30 & 0xff } ;
T_2 V_20 = ( V_30 >> 16 ) & 0xff ;
struct V_7 V_8 = { V_33 , V_20 , sizeof( V_22 ) , V_22 , V_2 , V_31 } ;
return F_2 ( V_29 -> V_6 , & V_8 ) ;
}
static int F_17 ( struct V_28 * V_29 , T_4 V_30 , T_2 V_31 )
{
return F_15 ( V_29 , V_30 , & V_31 , 1 ) ;
}
static int F_18 ( struct V_28 * V_29 , T_4 V_30 , T_2 * V_31 )
{
return F_16 ( V_29 , V_30 , V_31 , 1 ) ;
}
static int F_19 ( struct V_28 * V_29 , T_4 V_30 , T_2 V_31 ,
T_2 V_34 )
{
int V_9 ;
T_2 V_35 ;
if ( V_34 != 0xff ) {
V_9 = F_16 ( V_29 , V_30 , & V_35 , 1 ) ;
if ( V_9 )
return V_9 ;
V_31 &= V_34 ;
V_35 &= ~ V_34 ;
V_31 |= V_35 ;
}
return F_15 ( V_29 , V_30 , & V_31 , 1 ) ;
}
static int F_20 ( struct V_36 * V_37 ,
struct V_38 V_39 [] , int V_40 )
{
struct V_28 * V_29 = F_21 ( V_37 ) ;
struct V_41 * V_41 = V_29 -> V_42 ;
int V_9 ;
if ( F_9 ( & V_29 -> V_43 ) < 0 )
return - V_19 ;
if ( V_40 == 2 && ! ( V_39 [ 0 ] . V_44 & V_45 ) &&
( V_39 [ 1 ] . V_44 & V_45 ) ) {
if ( V_39 [ 0 ] . V_2 > 40 || V_39 [ 1 ] . V_2 > 40 ) {
V_9 = - V_46 ;
} else if ( V_39 [ 0 ] . V_47 == V_41 -> V_48 [ 0 ] . V_49 ) {
T_4 V_30 = V_39 [ 0 ] . V_1 [ 0 ] << 16 | V_39 [ 0 ] . V_1 [ 1 ] << 8 |
V_39 [ 0 ] . V_1 [ 2 ] ;
V_9 = F_16 ( V_29 , V_30 , & V_39 [ 1 ] . V_1 [ 0 ] ,
V_39 [ 1 ] . V_2 ) ;
} else {
T_2 V_1 [ 5 + V_39 [ 0 ] . V_2 ] ;
struct V_7 V_8 = { V_50 , 0 , sizeof( V_1 ) ,
V_1 , V_39 [ 1 ] . V_2 , V_39 [ 1 ] . V_1 } ;
V_1 [ 0 ] = V_39 [ 1 ] . V_2 ;
V_1 [ 1 ] = V_39 [ 0 ] . V_47 << 1 ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
memcpy ( & V_1 [ 5 ] , V_39 [ 0 ] . V_1 , V_39 [ 0 ] . V_2 ) ;
V_9 = F_2 ( V_29 -> V_6 , & V_8 ) ;
}
} else if ( V_40 == 1 && ! ( V_39 [ 0 ] . V_44 & V_45 ) ) {
if ( V_39 [ 0 ] . V_2 > 40 ) {
V_9 = - V_46 ;
} else if ( V_39 [ 0 ] . V_47 == V_41 -> V_48 [ 0 ] . V_49 ) {
T_4 V_30 = V_39 [ 0 ] . V_1 [ 0 ] << 16 | V_39 [ 0 ] . V_1 [ 1 ] << 8 |
V_39 [ 0 ] . V_1 [ 2 ] ;
V_9 = F_15 ( V_29 , V_30 , & V_39 [ 0 ] . V_1 [ 3 ] ,
V_39 [ 0 ] . V_2 - 3 ) ;
} else {
T_2 V_1 [ 5 + V_39 [ 0 ] . V_2 ] ;
struct V_7 V_8 = { V_51 , 0 , sizeof( V_1 ) , V_1 ,
0 , NULL } ;
V_1 [ 0 ] = V_39 [ 0 ] . V_2 ;
V_1 [ 1 ] = V_39 [ 0 ] . V_47 << 1 ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
memcpy ( & V_1 [ 5 ] , V_39 [ 0 ] . V_1 , V_39 [ 0 ] . V_2 ) ;
V_9 = F_2 ( V_29 -> V_6 , & V_8 ) ;
}
} else {
V_9 = - V_46 ;
}
F_14 ( & V_29 -> V_43 ) ;
if ( V_9 < 0 )
return V_9 ;
else
return V_40 ;
}
static T_4 F_22 ( struct V_36 * V_52 )
{
return V_53 ;
}
static int F_23 ( struct V_28 * V_29 )
{
unsigned int V_54 ;
unsigned char V_55 [ 4 ] ;
int V_9 ;
struct V_7 V_8 = { V_56 , 0 , 0 , NULL , 4 , V_55 } ;
V_9 = F_2 ( V_29 -> V_6 , & V_8 ) ;
if ( V_9 < 0 )
goto F_12;
if ( ( V_55 [ 2 ] + V_55 [ 3 ] ) == 0xff ) {
if ( ( V_55 [ 0 ] + V_55 [ 1 ] ) == 0xff ) {
V_54 = V_55 [ 0 ] << 8 | V_55 [ 2 ] ;
} else {
V_54 = V_55 [ 0 ] << 16 | V_55 [ 1 ] << 8 | V_55 [ 2 ] ;
}
} else {
V_54 = V_55 [ 0 ] << 24 | V_55 [ 1 ] << 16 | V_55 [ 2 ] << 8 | V_55 [ 3 ] ;
}
F_24 ( V_29 -> V_57 , V_54 , 0 ) ;
F_12:
return 0 ;
}
static int F_25 ( struct V_28 * V_29 )
{
struct V_41 * V_41 = V_29 -> V_42 ;
int V_9 , V_3 ;
T_1 V_58 = 87 * 188 / 4 ;
T_2 V_59 = 512 / 4 ;
struct V_60 V_61 [] = {
{ 0x80f99d , 0x01 , 0x01 } ,
{ 0x80f9a4 , 0x01 , 0x01 } ,
{ 0x00dd11 , 0x00 , 0x20 } ,
{ 0x00dd11 , 0x00 , 0x40 } ,
{ 0x00dd13 , 0x00 , 0x20 } ,
{ 0x00dd13 , 0x00 , 0x40 } ,
{ 0x00dd11 , 0x20 , 0x20 } ,
{ 0x00dd88 , ( V_58 >> 0 ) & 0xff , 0xff } ,
{ 0x00dd89 , ( V_58 >> 8 ) & 0xff , 0xff } ,
{ 0x00dd0c , V_59 , 0xff } ,
{ 0x00dd11 , V_41 -> V_62 << 6 , 0x40 } ,
{ 0x00dd8a , ( V_58 >> 0 ) & 0xff , 0xff } ,
{ 0x00dd8b , ( V_58 >> 8 ) & 0xff , 0xff } ,
{ 0x00dd0d , V_59 , 0xff } ,
{ 0x80f9a3 , 0x00 , 0x01 } ,
{ 0x80f9cd , 0x00 , 0x01 } ,
{ 0x80f99d , 0x00 , 0x01 } ,
{ 0x80f9a4 , 0x00 , 0x01 } ,
} ;
F_8 ( L_7 ,
V_16 , V_29 -> V_6 -> V_63 , V_58 , V_59 ) ;
for ( V_3 = 0 ; V_3 < F_26 ( V_61 ) ; V_3 ++ ) {
V_9 = F_19 ( V_29 , V_61 [ V_3 ] . V_30 , V_61 [ V_3 ] . V_31 ,
V_61 [ V_3 ] . V_34 ) ;
if ( V_9 < 0 )
goto F_12;
}
return 0 ;
F_12:
F_8 ( L_8 , V_16 , V_9 ) ;
return V_9 ;
}
static int F_27 ( struct V_5 * V_6 ,
struct V_64 * V_65 ,
struct V_66 * * V_67 ,
int * V_68 )
{
int V_9 ;
T_2 V_22 [ 1 ] = { 1 } ;
T_2 V_27 [ 4 ] ;
struct V_7 V_8 = { V_69 , 0 , sizeof( V_22 ) , V_22 ,
sizeof( V_27 ) , V_27 } ;
V_9 = F_2 ( V_6 , & V_8 ) ;
if ( V_9 < 0 )
goto F_12;
F_8 ( L_9 , V_16 ,
V_27 [ 0 ] , V_27 [ 1 ] , V_27 [ 2 ] , V_27 [ 3 ] ) ;
if ( V_27 [ 0 ] || V_27 [ 1 ] || V_27 [ 2 ] || V_27 [ 3 ] )
* V_68 = 0 ;
else
* V_68 = 1 ;
return 0 ;
F_12:
F_8 ( L_8 , V_16 , V_9 ) ;
return V_9 ;
}
static int F_28 ( struct V_5 * V_6 ,
const struct V_70 * V_71 )
{
int V_9 , V_3 , V_72 , V_2 ;
T_2 V_22 [ 1 ] ;
T_2 V_27 [ 4 ] ;
struct V_7 V_8 = { 0 , 0 , 0 , NULL , 0 , NULL } ;
struct V_7 V_73 = { V_25 , 0 , 0 , V_22 , 0 , NULL } ;
struct V_7 V_74 = { V_69 , 0 , 1 , V_22 , 4 , V_27 } ;
T_2 V_75 ;
T_1 V_76 , V_77 , V_78 ;
#define F_29 58
#define F_30 7
for ( V_3 = V_71 -> V_79 ; V_3 > F_30 ; ) {
V_75 = V_71 -> V_80 [ V_71 -> V_79 - V_3 + 0 ] ;
V_76 = V_71 -> V_80 [ V_71 -> V_79 - V_3 + 1 ] << 8 ;
V_76 |= V_71 -> V_80 [ V_71 -> V_79 - V_3 + 2 ] << 0 ;
V_77 = V_71 -> V_80 [ V_71 -> V_79 - V_3 + 3 ] << 8 ;
V_77 |= V_71 -> V_80 [ V_71 -> V_79 - V_3 + 4 ] << 0 ;
V_78 = V_71 -> V_80 [ V_71 -> V_79 - V_3 + 5 ] << 8 ;
V_78 |= V_71 -> V_80 [ V_71 -> V_79 - V_3 + 6 ] << 0 ;
F_8 ( L_10 ,
V_16 , V_75 , V_76 , V_77 ,
V_78 ) ;
if ( ( ( V_75 != 1 ) && ( V_75 != 2 ) ) ||
( V_77 > V_3 ) ) {
F_8 ( L_11 , V_16 ) ;
break;
}
V_8 . V_21 = V_81 ;
V_9 = F_2 ( V_6 , & V_8 ) ;
if ( V_9 < 0 )
goto F_12;
for ( V_72 = F_30 + V_77 ; V_72 > 0 ; V_72 -= F_29 ) {
V_2 = V_72 ;
if ( V_2 > F_29 )
V_2 = F_29 ;
V_73 . V_14 = V_2 ;
V_73 . V_22 = ( T_2 * ) & V_71 -> V_80 [ V_71 -> V_79 - V_3 +
F_30 + V_77 - V_72 ] ;
V_9 = F_2 ( V_6 , & V_73 ) ;
if ( V_9 < 0 )
goto F_12;
}
V_8 . V_21 = V_82 ;
V_9 = F_2 ( V_6 , & V_8 ) ;
if ( V_9 < 0 )
goto F_12;
V_3 -= V_77 + F_30 ;
F_8 ( L_12 , V_16 , V_71 -> V_79 - V_3 ) ;
}
V_8 . V_21 = V_83 ;
V_9 = F_2 ( V_6 , & V_8 ) ;
if ( V_9 < 0 )
goto F_12;
V_22 [ 0 ] = 1 ;
V_9 = F_2 ( V_6 , & V_74 ) ;
if ( V_9 < 0 )
goto F_12;
if ( ! ( V_27 [ 0 ] || V_27 [ 1 ] || V_27 [ 2 ] || V_27 [ 3 ] ) ) {
F_31 ( L_13 ) ;
V_9 = - V_84 ;
goto F_12;
}
F_31 ( L_14 , V_27 [ 0 ] , V_27 [ 1 ] , V_27 [ 2 ] ,
V_27 [ 3 ] ) ;
return 0 ;
F_12:
F_8 ( L_8 , V_16 , V_9 ) ;
return V_9 ;
}
static int F_32 ( struct V_5 * V_6 ,
const struct V_70 * V_71 )
{
int V_9 , V_3 , V_85 ;
T_2 V_22 [ 1 ] ;
T_2 V_27 [ 4 ] ;
struct V_7 V_8 = { 0 , 0 , 0 , NULL , 0 , NULL } ;
struct V_7 V_73 = { V_86 , 0 , 0 , NULL , 0 , NULL } ;
struct V_7 V_74 = { V_69 , 0 , 1 , V_22 , 4 , V_27 } ;
#define F_30 7
for ( V_3 = F_30 , V_85 = 0 ; V_3 <= V_71 -> V_79 ; V_3 ++ ) {
if ( V_3 == V_71 -> V_79 ||
( V_71 -> V_80 [ V_3 + 0 ] == 0x03 &&
( V_71 -> V_80 [ V_3 + 1 ] == 0x00 ||
V_71 -> V_80 [ V_3 + 1 ] == 0x01 ) &&
V_71 -> V_80 [ V_3 + 2 ] == 0x00 ) ) {
V_73 . V_14 = V_3 - V_85 ;
V_73 . V_22 = ( T_2 * ) & V_71 -> V_80 [ V_85 ] ;
V_85 = V_3 ;
V_9 = F_2 ( V_6 , & V_73 ) ;
if ( V_9 < 0 )
goto F_12;
F_8 ( L_15 , V_16 , V_3 ) ;
}
}
V_8 . V_21 = V_83 ;
V_9 = F_2 ( V_6 , & V_8 ) ;
if ( V_9 < 0 )
goto F_12;
V_22 [ 0 ] = 1 ;
V_9 = F_2 ( V_6 , & V_74 ) ;
if ( V_9 < 0 )
goto F_12;
if ( ! ( V_27 [ 0 ] || V_27 [ 1 ] || V_27 [ 2 ] || V_27 [ 3 ] ) ) {
F_31 ( L_13 ) ;
V_9 = - V_84 ;
goto F_12;
}
F_31 ( L_14 , V_27 [ 0 ] , V_27 [ 1 ] , V_27 [ 2 ] ,
V_27 [ 3 ] ) ;
return 0 ;
F_12:
F_8 ( L_8 , V_16 , V_9 ) ;
return V_9 ;
}
static int F_33 ( struct V_28 * V_29 , T_2 V_87 [ 6 ] )
{
struct V_41 * V_41 = V_29 -> V_42 ;
int V_9 , V_3 , V_88 = 0 ;
T_2 V_35 ;
T_1 V_89 ;
V_9 = F_18 ( V_29 , V_90 , & V_35 ) ;
if ( V_9 < 0 )
goto F_12;
V_41 -> V_62 = V_35 ;
F_8 ( L_16 , V_16 , V_41 -> V_62 ) ;
for ( V_3 = 0 ; V_3 < V_91 [ 0 ] . V_92 ; V_3 ++ ) {
V_9 = F_18 ( V_29 , V_93 + V_88 , & V_35 ) ;
if ( V_9 < 0 )
goto F_12;
V_41 -> V_48 [ V_3 ] . V_94 = V_35 ;
F_8 ( L_17 , V_16 , V_3 , V_35 ) ;
switch ( V_35 ) {
case V_95 :
case V_96 :
case V_97 :
case V_98 :
V_41 -> V_48 [ V_3 ] . V_99 = 1 ;
break;
default:
F_34 ( L_18 ,
V_35 ) ;
} ;
V_9 = F_18 ( V_29 , V_100 + V_88 , & V_35 ) ;
if ( V_9 < 0 )
goto F_12;
V_89 = V_35 ;
V_9 = F_18 ( V_29 , V_101 + V_88 , & V_35 ) ;
if ( V_9 < 0 )
goto F_12;
V_89 |= V_35 << 8 ;
F_8 ( L_19 , V_16 , V_3 , V_89 ) ;
V_88 = 0x10 ;
}
V_9 = F_18 ( V_29 , 0x00d800 , & V_35 ) ;
if ( V_9 < 0 )
goto F_12;
V_35 = ( V_35 >> 0 ) & 0x0f ;
for ( V_3 = 0 ; V_3 < V_91 [ 0 ] . V_92 ; V_3 ++ )
V_41 -> V_48 [ V_3 ] . clock = V_102 [ V_35 ] ;
V_9 = F_18 ( V_29 , V_103 , & V_35 ) ;
if ( V_9 < 0 )
goto F_12;
F_8 ( L_20 , V_16 , V_35 ) ;
if ( V_35 == 5 ) {
V_9 = F_18 ( V_29 , V_104 , & V_35 ) ;
if ( V_9 < 0 )
goto F_12;
F_8 ( L_21 , V_16 , V_35 ) ;
switch ( V_35 ) {
case 0 :
default:
V_29 -> V_65 . V_105 . V_106 . V_107 = V_108 ;
V_29 -> V_65 . V_105 . V_106 . V_109 = V_108 ;
break;
case 1 :
V_29 -> V_65 . V_105 . V_106 . V_107 = V_110 ;
V_29 -> V_65 . V_105 . V_106 . V_109 = V_110 ;
break;
}
V_29 -> V_65 . V_105 . V_106 . V_111 = F_23 ;
}
return 0 ;
F_12:
F_8 ( L_8 , V_16 , V_9 ) ;
return V_9 ;
}
static int F_35 ( struct V_28 * V_29 , T_2 V_87 [ 6 ] )
{
struct V_41 * V_41 = V_29 -> V_42 ;
int V_9 , V_3 ;
T_2 V_35 ;
V_41 -> V_62 = false ;
V_9 = F_18 ( V_29 , 0x00d800 , & V_35 ) ;
if ( V_9 < 0 )
goto F_12;
V_35 = ( V_35 >> 0 ) & 0x0f ;
for ( V_3 = 0 ; V_3 < V_91 [ 0 ] . V_92 ; V_3 ++ )
V_41 -> V_48 [ V_3 ] . clock = V_112 [ V_35 ] ;
return 0 ;
F_12:
F_8 ( L_8 , V_16 , V_9 ) ;
return V_9 ;
}
static int F_36 ( struct V_28 * V_29 ,
int V_21 , int V_113 )
{
int V_9 ;
switch ( V_21 ) {
case V_114 :
V_9 = F_19 ( V_29 , 0xd8eb , 1 , 1 ) ;
if ( V_9 < 0 )
goto F_12;
V_9 = F_19 ( V_29 , 0xd8ec , 1 , 1 ) ;
if ( V_9 < 0 )
goto F_12;
V_9 = F_19 ( V_29 , 0xd8ed , 1 , 1 ) ;
if ( V_9 < 0 )
goto F_12;
V_9 = F_19 ( V_29 , 0xd8d0 , 1 , 1 ) ;
if ( V_9 < 0 )
goto F_12;
V_9 = F_19 ( V_29 , 0xd8d1 , 1 , 1 ) ;
if ( V_9 < 0 )
goto F_12;
F_37 ( 10000 , 50000 ) ;
break;
case V_115 :
V_9 = F_17 ( V_29 , 0xd8e9 , 1 ) ;
if ( V_9 < 0 )
goto F_12;
V_9 = F_17 ( V_29 , 0xd8e8 , 1 ) ;
if ( V_9 < 0 )
goto F_12;
V_9 = F_17 ( V_29 , 0xd8e7 , 1 ) ;
if ( V_9 < 0 )
goto F_12;
F_37 ( 10000 , 20000 ) ;
V_9 = F_17 ( V_29 , 0xd8e7 , 0 ) ;
if ( V_9 < 0 )
goto F_12;
F_37 ( 10000 , 20000 ) ;
break;
default:
V_9 = - V_17 ;
goto F_12;
}
return 0 ;
F_12:
F_8 ( L_8 , V_16 , V_9 ) ;
return V_9 ;
}
static int F_38 ( struct V_28 * V_29 , int V_21 , int V_113 )
{
struct V_41 * V_41 = V_29 -> V_42 ;
switch ( V_41 -> V_48 [ 0 ] . V_94 ) {
case V_96 :
return F_36 ( V_29 , V_21 , V_113 ) ;
default:
break;
}
return - V_84 ;
}
static int F_39 ( void * V_116 , int V_117 ,
int V_21 , int V_113 )
{
struct V_36 * V_37 = V_116 ;
struct V_28 * V_29 = F_21 ( V_37 ) ;
switch ( V_117 ) {
case V_118 :
return F_38 ( V_29 , V_21 , V_113 ) ;
default:
break;
}
return - V_17 ;
}
static int F_40 ( struct V_119 * V_37 )
{
struct V_41 * V_41 = V_37 -> V_120 -> V_42 ;
int V_9 ;
if ( ! V_41 -> V_48 [ V_37 -> V_121 ] . V_94 ) {
V_9 = - V_84 ;
goto F_12;
}
if ( V_37 -> V_121 == 0 ) {
V_41 -> V_48 [ 0 ] . V_122 = V_123 ;
V_41 -> V_48 [ 1 ] . V_122 = V_124 ;
V_9 = F_17 ( V_37 -> V_120 , 0x00417f ,
V_41 -> V_48 [ 1 ] . V_49 ) ;
if ( V_9 < 0 )
goto F_12;
V_9 = F_17 ( V_37 -> V_120 , 0x00d81a ,
V_41 -> V_62 ) ;
if ( V_9 < 0 )
goto F_12;
}
V_37 -> V_125 [ 0 ] . V_126 = F_41 ( V_127 ,
& V_41 -> V_48 [ V_37 -> V_121 ] , & V_37 -> V_120 -> V_128 ) ;
if ( V_37 -> V_125 [ 0 ] . V_126 == NULL ) {
V_9 = - V_84 ;
goto F_12;
}
V_37 -> V_125 [ 0 ] . V_126 -> V_129 . V_130 = NULL ;
V_37 -> V_125 [ 0 ] . V_126 -> V_131 = F_39 ;
return 0 ;
F_12:
F_8 ( L_8 , V_16 , V_9 ) ;
return V_9 ;
}
static int F_42 ( struct V_119 * V_37 )
{
struct V_41 * V_41 = V_37 -> V_120 -> V_42 ;
int V_9 ;
struct V_132 * V_126 ;
switch ( V_41 -> V_48 [ V_37 -> V_121 ] . V_94 ) {
case V_95 :
V_9 = F_19 ( V_37 -> V_120 , 0x00d8ec , 0x01 , 0x01 ) ;
if ( V_9 < 0 )
goto F_12;
V_9 = F_19 ( V_37 -> V_120 , 0x00d8ed , 0x01 , 0x01 ) ;
if ( V_9 < 0 )
goto F_12;
V_9 = F_19 ( V_37 -> V_120 , 0x00d8e8 , 0x01 , 0x01 ) ;
if ( V_9 < 0 )
goto F_12;
V_9 = F_19 ( V_37 -> V_120 , 0x00d8e9 , 0x01 , 0x01 ) ;
if ( V_9 < 0 )
goto F_12;
V_9 = F_19 ( V_37 -> V_120 , 0x00d8e7 , 0x00 , 0x01 ) ;
if ( V_9 < 0 )
goto F_12;
F_37 ( 2000 , 20000 ) ;
V_9 = F_19 ( V_37 -> V_120 , 0x00d8e7 , 0x01 , 0x01 ) ;
if ( V_9 < 0 )
goto F_12;
V_9 = F_19 ( V_37 -> V_120 , 0x00d8eb , 0x01 , 0x01 ) ;
if ( V_9 < 0 )
goto F_12;
V_126 = F_41 ( V_133 , V_37 -> V_125 [ 0 ] . V_126 ,
& V_37 -> V_120 -> V_128 , & V_134 ) ;
break;
case V_96 :
V_126 = F_41 ( V_135 , V_37 -> V_125 [ 0 ] . V_126 ,
& V_37 -> V_120 -> V_128 , & V_136 ) ;
break;
case V_97 :
V_9 = F_17 ( V_37 -> V_120 , 0x00d8e0 , 1 ) ;
if ( V_9 < 0 )
goto F_12;
V_9 = F_17 ( V_37 -> V_120 , 0x00d8e1 , 1 ) ;
if ( V_9 < 0 )
goto F_12;
V_9 = F_17 ( V_37 -> V_120 , 0x00d8df , 0 ) ;
if ( V_9 < 0 )
goto F_12;
F_43 ( 30 ) ;
V_9 = F_17 ( V_37 -> V_120 , 0x00d8df , 1 ) ;
if ( V_9 < 0 )
goto F_12;
F_43 ( 300 ) ;
V_9 = F_17 ( V_37 -> V_120 , 0x00d8c0 , 1 ) ;
if ( V_9 < 0 )
goto F_12;
V_9 = F_17 ( V_37 -> V_120 , 0x00d8c1 , 1 ) ;
if ( V_9 < 0 )
goto F_12;
V_9 = F_17 ( V_37 -> V_120 , 0x00d8bf , 0 ) ;
if ( V_9 < 0 )
goto F_12;
V_9 = F_17 ( V_37 -> V_120 , 0x00d8b4 , 1 ) ;
if ( V_9 < 0 )
goto F_12;
V_9 = F_17 ( V_37 -> V_120 , 0x00d8b5 , 1 ) ;
if ( V_9 < 0 )
goto F_12;
V_9 = F_17 ( V_37 -> V_120 , 0x00d8b3 , 1 ) ;
if ( V_9 < 0 )
goto F_12;
V_126 = F_41 ( V_137 , V_37 -> V_125 [ 0 ] . V_126 ,
& V_37 -> V_120 -> V_128 , 0x60 , & V_138 ) ;
break;
case V_98 :
V_126 = F_41 ( V_139 , V_37 -> V_125 [ 0 ] . V_126 ,
& V_37 -> V_120 -> V_128 , & V_140 ) ;
break;
default:
V_126 = NULL ;
}
if ( V_126 == NULL ) {
V_9 = - V_84 ;
goto F_12;
}
return 0 ;
F_12:
F_8 ( L_8 , V_16 , V_9 ) ;
return V_9 ;
}
static int F_44 ( struct V_141 * V_142 ,
const struct V_143 * V_121 )
{
int V_9 , V_3 ;
struct V_28 * V_29 = NULL ;
struct V_5 * V_6 ;
bool V_144 ;
F_8 ( L_22 , V_16 ,
V_142 -> V_145 -> V_67 . V_146 ) ;
if ( V_142 -> V_145 -> V_67 . V_146 != 0 )
return 0 ;
V_6 = F_45 ( V_142 ) ;
for ( V_3 = 0 , V_144 = false ; V_3 < F_26 ( V_147 ) - 1 ; V_3 ++ ) {
if ( V_147 [ V_3 ] . V_148 ==
F_46 ( V_6 -> V_149 . V_148 ) &&
V_147 [ V_3 ] . V_150 ==
F_46 ( V_6 -> V_149 . V_150 ) ) {
V_144 = true ;
break;
}
}
if ( ! V_144 ) {
F_8 ( L_23 , V_16 ,
F_46 ( V_6 -> V_149 . V_148 ) ,
F_46 ( V_6 -> V_149 . V_150 ) ) ;
V_91 [ 0 ] . V_151 [ 0 ] . V_152 [ 0 ] -> V_148 =
F_46 ( V_6 -> V_149 . V_148 ) ;
V_91 [ 0 ] . V_151 [ 0 ] . V_152 [ 0 ] -> V_150 =
F_46 ( V_6 -> V_149 . V_150 ) ;
}
for ( V_3 = 0 ; V_3 < V_153 ; V_3 ++ ) {
V_9 = F_47 ( V_142 , & V_91 [ V_3 ] ,
V_154 , & V_29 , V_155 ) ;
if ( V_9 == - V_84 )
continue;
else
break;
}
if ( V_9 < 0 )
goto F_12;
if ( V_29 ) {
V_9 = F_25 ( V_29 ) ;
if ( V_9 < 0 )
goto F_12;
}
return 0 ;
F_12:
F_8 ( L_8 , V_16 , V_9 ) ;
return V_9 ;
}
