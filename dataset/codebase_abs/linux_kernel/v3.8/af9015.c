static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
#define F_2 63
#define F_3 8
#define F_4 2
struct V_5 * V_6 = F_5 ( V_2 ) ;
int V_7 , V_8 , V_9 ;
T_1 V_10 [ F_2 ] ;
T_1 V_11 = 1 ;
V_10 [ 0 ] = V_4 -> V_12 ;
V_10 [ 1 ] = V_6 -> V_13 ++ ;
V_10 [ 2 ] = V_4 -> V_14 ;
V_10 [ 3 ] = V_4 -> V_15 >> 8 ;
V_10 [ 4 ] = V_4 -> V_15 & 0xff ;
V_10 [ 5 ] = V_4 -> V_16 ;
V_10 [ 6 ] = V_4 -> V_17 ;
V_10 [ 7 ] = V_4 -> V_18 ;
switch ( V_4 -> V_12 ) {
case V_19 :
case V_20 :
case V_21 :
V_11 = 0 ;
break;
case V_22 :
V_11 = 0 ;
V_10 [ 2 ] |= 0x01 ;
case V_23 :
V_10 [ 0 ] = V_24 ;
break;
case V_25 :
if ( ( ( V_4 -> V_15 & 0xff00 ) == 0xff00 ) ||
( ( V_4 -> V_15 & 0xff00 ) == 0xae00 ) )
V_10 [ 0 ] = V_26 ;
case V_26 :
case V_27 :
case V_28 :
case V_29 :
break;
default:
F_6 ( & V_2 -> V_30 -> V_31 , L_1 ,
V_32 , V_4 -> V_12 ) ;
V_7 = - V_33 ;
goto error;
}
if ( ( V_11 && ( V_4 -> V_18 > F_2 - F_3 ) ) ||
( ! V_11 && ( V_4 -> V_18 > F_2 - F_4 ) ) ) {
F_6 ( & V_2 -> V_30 -> V_31 , L_2 ,
V_32 , V_4 -> V_12 , V_4 -> V_18 ) ;
V_7 = - V_34 ;
goto error;
}
V_8 = F_3 ;
V_9 = F_4 ;
if ( V_11 ) {
V_8 += V_4 -> V_18 ;
memcpy ( & V_10 [ F_3 ] , V_4 -> V_35 , V_4 -> V_18 ) ;
} else {
V_9 += V_4 -> V_18 ;
}
if ( V_4 -> V_12 == V_28 || V_4 -> V_12 == V_21 )
V_9 = 0 ;
V_7 = F_7 ( V_2 , V_10 , V_8 , V_10 , V_9 ) ;
if ( V_7 )
goto error;
if ( V_9 && V_10 [ 1 ] ) {
F_6 ( & V_2 -> V_30 -> V_31 , L_3 ,
V_32 , V_10 [ 1 ] ) ;
V_7 = - V_33 ;
goto error;
}
if ( ! V_11 )
memcpy ( V_4 -> V_35 , & V_10 [ F_4 ] , V_4 -> V_18 ) ;
error:
return V_7 ;
}
static int F_8 ( struct V_1 * V_2 , T_2 V_15 , T_1 * V_36 ,
T_1 V_37 )
{
struct V_3 V_4 = { V_25 , V_38 , V_15 , 0 , 0 , V_37 ,
V_36 } ;
return F_1 ( V_2 , & V_4 ) ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_15 , T_1 * V_36 , T_1 V_37 )
{
struct V_3 V_4 = { V_20 , V_38 , V_15 , 0 , 0 , V_37 ,
V_36 } ;
return F_1 ( V_2 , & V_4 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_15 , T_1 V_36 )
{
return F_8 ( V_2 , V_15 , & V_36 , 1 ) ;
}
static int F_11 ( struct V_1 * V_2 , T_2 V_15 , T_1 * V_36 )
{
return F_9 ( V_2 , V_15 , V_36 , 1 ) ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_15 , T_2 V_39 ,
T_1 V_36 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
struct V_3 V_4 = { V_23 , V_15 , V_39 , 1 , 1 , 1 , & V_36 } ;
if ( V_15 == V_6 -> V_40 [ 0 ] . V_14 ||
V_15 == V_6 -> V_40 [ 1 ] . V_14 )
V_4 . V_17 = 3 ;
return F_1 ( V_2 , & V_4 ) ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_15 , T_2 V_39 ,
T_1 * V_36 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
struct V_3 V_4 = { V_22 , V_15 , V_39 , 0 , 1 , 1 , V_36 } ;
if ( V_15 == V_6 -> V_40 [ 0 ] . V_14 ||
V_15 == V_6 -> V_40 [ 1 ] . V_14 )
V_4 . V_17 = 3 ;
return F_1 ( V_2 , & V_4 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_2 V_15 , T_1 V_41 , T_1 V_42 )
{
int V_7 ;
T_1 V_36 , V_43 = 0x01 ;
V_7 = F_11 ( V_2 , V_15 , & V_36 ) ;
if ( V_7 )
return V_7 ;
V_43 <<= V_41 ;
if ( V_42 ) {
V_36 |= V_43 ;
} else {
V_43 ^= 0xff ;
V_36 &= V_43 ;
}
return F_10 ( V_2 , V_15 , V_36 ) ;
}
static int F_15 ( struct V_1 * V_2 , T_2 V_15 , T_1 V_41 )
{
return F_14 ( V_2 , V_15 , V_41 , 1 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_2 V_15 , T_1 V_41 )
{
return F_14 ( V_2 , V_15 , V_41 , 0 ) ;
}
static int F_17 ( struct V_44 * V_45 , struct V_46 V_47 [] ,
int V_48 )
{
struct V_1 * V_2 = F_18 ( V_45 ) ;
struct V_5 * V_6 = F_5 ( V_2 ) ;
int V_7 = 0 , V_49 = 0 ;
T_2 V_15 ;
T_1 V_50 ( V_16 ) , V_17 ;
struct V_3 V_4 ;
if ( F_19 ( & V_2 -> V_51 ) < 0 )
return - V_52 ;
while ( V_49 < V_48 ) {
if ( V_47 [ V_49 ] . V_15 == V_6 -> V_40 [ 0 ] . V_14 ||
V_47 [ V_49 ] . V_15 == V_6 -> V_40 [ 1 ] . V_14 ) {
V_15 = V_47 [ V_49 ] . V_10 [ 0 ] << 8 ;
V_15 += V_47 [ V_49 ] . V_10 [ 1 ] ;
V_16 = V_47 [ V_49 ] . V_10 [ 2 ] ;
V_17 = 3 ;
} else {
V_15 = V_47 [ V_49 ] . V_10 [ 0 ] ;
V_17 = 1 ;
}
if ( V_48 > V_49 + 1 && ( V_47 [ V_49 + 1 ] . V_53 & V_54 ) ) {
if ( V_47 [ V_49 ] . V_37 > 3 || V_47 [ V_49 + 1 ] . V_37 > 61 ) {
V_7 = - V_55 ;
goto error;
}
if ( V_47 [ V_49 ] . V_15 == V_6 -> V_40 [ 0 ] . V_14 )
V_4 . V_12 = V_20 ;
else
V_4 . V_12 = V_22 ;
V_4 . V_14 = V_47 [ V_49 ] . V_15 ;
V_4 . V_15 = V_15 ;
V_4 . V_16 = V_16 ;
V_4 . V_17 = V_17 ;
V_4 . V_18 = V_47 [ V_49 + 1 ] . V_37 ;
V_4 . V_35 = & V_47 [ V_49 + 1 ] . V_10 [ 0 ] ;
V_7 = F_1 ( V_2 , & V_4 ) ;
V_49 += 2 ;
} else if ( V_47 [ V_49 ] . V_53 & V_54 ) {
if ( V_47 [ V_49 ] . V_37 > 61 ) {
V_7 = - V_55 ;
goto error;
}
if ( V_47 [ V_49 ] . V_15 == V_6 -> V_40 [ 0 ] . V_14 ) {
V_7 = - V_34 ;
goto error;
}
V_4 . V_12 = V_22 ;
V_4 . V_14 = V_47 [ V_49 ] . V_15 ;
V_4 . V_15 = V_15 ;
V_4 . V_16 = V_16 ;
V_4 . V_17 = V_17 ;
V_4 . V_18 = V_47 [ V_49 ] . V_37 ;
V_4 . V_35 = & V_47 [ V_49 ] . V_10 [ 0 ] ;
V_7 = F_1 ( V_2 , & V_4 ) ;
V_49 += 1 ;
} else {
if ( V_47 [ V_49 ] . V_37 > 21 ) {
V_7 = - V_55 ;
goto error;
}
if ( V_47 [ V_49 ] . V_15 == V_6 -> V_40 [ 0 ] . V_14 )
V_4 . V_12 = V_25 ;
else
V_4 . V_12 = V_23 ;
V_4 . V_14 = V_47 [ V_49 ] . V_15 ;
V_4 . V_15 = V_15 ;
V_4 . V_16 = V_16 ;
V_4 . V_17 = V_17 ;
V_4 . V_18 = V_47 [ V_49 ] . V_37 - V_17 ;
V_4 . V_35 = & V_47 [ V_49 ] . V_10 [ V_17 ] ;
V_7 = F_1 ( V_2 , & V_4 ) ;
V_49 += 1 ;
}
if ( V_7 )
goto error;
}
V_7 = V_49 ;
error:
F_20 ( & V_2 -> V_51 ) ;
return V_7 ;
}
static T_3 F_21 ( struct V_44 * V_56 )
{
return V_57 ;
}
static int F_22 ( struct V_1 * V_2 , const char * * V_58 )
{
int V_7 ;
T_1 V_59 ;
struct V_3 V_4 = { V_19 , 0 , 0 , 0 , 0 , 1 , & V_59 } ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
return V_7 ;
F_23 ( & V_2 -> V_30 -> V_31 , L_4 , V_60 , V_59 ) ;
if ( V_59 == 0x02 )
V_7 = V_61 ;
else
V_7 = V_62 ;
return V_7 ;
}
static int F_24 ( struct V_1 * V_2 ,
const struct V_63 * V_64 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
int V_49 , V_37 , V_65 , V_7 ;
struct V_3 V_4 = { V_28 , 0 , 0 , 0 , 0 , 0 , NULL } ;
T_2 V_66 = 0 ;
F_23 ( & V_2 -> V_30 -> V_31 , L_5 , V_60 ) ;
for ( V_49 = 0 ; V_49 < V_64 -> V_67 ; V_49 ++ )
V_66 += V_64 -> V_35 [ V_49 ] ;
V_6 -> V_68 = V_64 -> V_67 ;
V_6 -> V_69 = V_66 ;
#define F_25 0x5100
#define F_26 55
for ( V_65 = V_64 -> V_67 ; V_65 > 0 ; V_65 -= F_26 ) {
V_37 = V_65 ;
if ( V_37 > F_26 )
V_37 = F_26 ;
V_4 . V_18 = V_37 ;
V_4 . V_35 = ( T_1 * ) & V_64 -> V_35 [ V_64 -> V_67 - V_65 ] ;
V_4 . V_15 = F_25 + V_64 -> V_67 - V_65 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 ) {
F_6 ( & V_2 -> V_30 -> V_31 ,
L_6 ,
V_32 , V_7 ) ;
goto error;
}
}
V_4 . V_12 = V_29 ;
V_4 . V_18 = 0 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 ) {
F_6 ( & V_2 -> V_30 -> V_31 , L_7 ,
V_32 , V_7 ) ;
goto error;
}
error:
return V_7 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
int V_7 , V_49 ;
static const unsigned int V_70 = 256 ;
T_1 V_10 [ V_70 ] ;
struct V_3 V_4 = { V_22 , V_71 , 0 , 0 , 1 , 1 , NULL } ;
for ( V_49 = 0 ; V_49 < V_70 ; V_49 ++ ) {
V_4 . V_15 = V_49 ;
V_4 . V_35 = & V_10 [ V_49 ] ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 < 0 )
goto V_72;
}
for ( V_49 = 0 ; V_49 < V_70 / sizeof( T_3 ) ; V_49 ++ ) {
V_6 -> V_73 *= V_74 ;
V_6 -> V_73 += F_28 ( ( ( T_3 * ) V_10 ) [ V_49 ] ) ;
}
for ( V_49 = 0 ; V_49 < V_70 ; V_49 += 16 )
F_23 ( & V_2 -> V_30 -> V_31 , L_8 , V_60 , 16 , V_10 + V_49 ) ;
F_23 ( & V_2 -> V_30 -> V_31 , L_9 ,
V_60 , V_6 -> V_73 ) ;
return 0 ;
V_72:
F_6 ( & V_2 -> V_30 -> V_31 , L_10 , V_32 , V_7 ) ;
return V_7 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
int V_7 ;
T_1 V_36 , V_49 , V_75 = 0 ;
struct V_3 V_4 = { V_22 , V_71 , 0 , 0 , 1 , 1 , & V_36 } ;
F_23 ( & V_2 -> V_30 -> V_31 , L_5 , V_60 ) ;
V_4 . V_15 = V_76 ;
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( ! V_7 )
break;
}
if ( V_7 )
goto error;
V_7 = F_27 ( V_2 ) ;
if ( V_7 )
goto error;
V_6 -> V_77 = V_36 ;
F_23 ( & V_2 -> V_30 -> V_31 , L_11 , V_60 , V_36 ) ;
V_4 . V_15 = V_78 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto error;
V_6 -> V_79 = V_36 ;
F_23 ( & V_2 -> V_30 -> V_31 , L_12 , V_60 , V_6 -> V_79 ) ;
if ( V_2 -> V_30 -> V_80 == V_81 )
V_6 -> V_79 = 0 ;
if ( V_6 -> V_79 ) {
V_4 . V_15 = V_82 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto error;
V_6 -> V_40 [ 1 ] . V_14 = V_36 ;
}
for ( V_49 = 0 ; V_49 < V_6 -> V_79 + 1 ; V_49 ++ ) {
if ( V_49 == 1 )
V_75 = V_83 ;
V_4 . V_15 = V_84 + V_75 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto error;
switch ( V_36 ) {
case 0 :
V_6 -> V_40 [ V_49 ] . clock = 28800000 ;
break;
case 1 :
V_6 -> V_40 [ V_49 ] . clock = 20480000 ;
break;
case 2 :
V_6 -> V_40 [ V_49 ] . clock = 28000000 ;
break;
case 3 :
V_6 -> V_40 [ V_49 ] . clock = 25000000 ;
break;
}
F_23 ( & V_2 -> V_30 -> V_31 , L_13 ,
V_60 , V_49 , V_36 ,
V_6 -> V_40 [ V_49 ] . clock ) ;
V_4 . V_15 = V_85 + V_75 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto error;
V_6 -> V_40 [ V_49 ] . V_86 = V_36 << 8 ;
V_4 . V_15 = V_87 + V_75 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto error;
V_6 -> V_40 [ V_49 ] . V_86 += V_36 ;
V_6 -> V_40 [ V_49 ] . V_86 *= 1000 ;
F_23 ( & V_2 -> V_30 -> V_31 , L_14 , V_60 ,
V_49 , V_6 -> V_40 [ V_49 ] . V_86 ) ;
V_4 . V_15 = V_88 + V_75 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto error;
V_6 -> V_89 [ V_49 ] = V_36 << 8 ;
V_4 . V_15 = V_90 + V_75 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto error;
V_6 -> V_89 [ V_49 ] += V_36 ;
F_23 ( & V_2 -> V_30 -> V_31 , L_15 , V_60 , V_49 ,
V_6 -> V_89 [ V_49 ] ) ;
V_4 . V_15 = V_91 + V_75 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto error;
switch ( V_36 ) {
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
V_6 -> V_40 [ V_49 ] . V_100 = 1 ;
break;
case V_101 :
case V_102 :
case V_103 :
case V_104 :
V_6 -> V_40 [ V_49 ] . V_100 = 0 ;
break;
case V_105 :
V_6 -> V_40 [ V_49 ] . V_106 [ 1 ] = V_107 ;
V_6 -> V_40 [ V_49 ] . V_100 = 1 ;
break;
default:
F_6 ( & V_2 -> V_30 -> V_31 , L_16 \
L_17 ,
V_32 , V_36 ) ;
return - V_108 ;
}
V_6 -> V_40 [ V_49 ] . V_109 = V_36 ;
F_23 ( & V_2 -> V_30 -> V_31 , L_18 ,
V_60 , V_49 , V_36 ) ;
}
error:
if ( V_7 )
F_6 ( & V_2 -> V_30 -> V_31 , L_19 ,
V_32 , V_7 ) ;
if ( F_30 ( V_2 -> V_30 -> V_110 . V_111 ) == V_112 &&
( ( F_30 ( V_2 -> V_30 -> V_110 . V_113 ) ==
V_114 ) ||
( F_30 ( V_2 -> V_30 -> V_110 . V_113 ) ==
V_115 ) ) ) {
F_23 ( & V_2 -> V_30 -> V_31 ,
L_20 ,
V_60 ) ;
V_6 -> V_79 = 0 ;
V_6 -> V_40 [ 0 ] . V_86 = 4570000 ;
}
return V_7 ;
}
static int F_31 ( struct V_116 * V_117 , T_1 * V_118 ,
struct V_119 * V_120 )
{
struct V_1 * V_2 = F_32 ( V_117 ) ;
F_23 ( & V_2 -> V_30 -> V_31 , L_21 , V_60 , F_33 ( V_117 ) -> V_121 ) ;
if ( V_2 -> V_30 -> V_80 == V_81 )
V_120 -> V_122 . V_123 . V_124 = V_125 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
return V_6 -> V_79 + 1 ;
}
static int F_35 ( struct V_116 * V_117 )
{
int V_7 ;
struct V_5 * V_6 = F_36 ( V_117 ) ;
if ( F_19 ( & V_6 -> V_126 ) )
return - V_52 ;
V_7 = V_6 -> V_127 [ F_33 ( V_117 ) -> V_121 ] ( V_117 ) ;
F_20 ( & V_6 -> V_126 ) ;
return V_7 ;
}
static int F_37 ( struct V_116 * V_117 ,
T_4 * V_128 )
{
int V_7 ;
struct V_5 * V_6 = F_36 ( V_117 ) ;
if ( F_19 ( & V_6 -> V_126 ) )
return - V_52 ;
V_7 = V_6 -> V_129 [ F_33 ( V_117 ) -> V_121 ] ( V_117 , V_128 ) ;
F_20 ( & V_6 -> V_126 ) ;
return V_7 ;
}
static int F_38 ( struct V_116 * V_117 )
{
int V_7 ;
struct V_5 * V_6 = F_36 ( V_117 ) ;
if ( F_19 ( & V_6 -> V_126 ) )
return - V_52 ;
V_7 = V_6 -> V_130 [ F_33 ( V_117 ) -> V_121 ] ( V_117 ) ;
F_20 ( & V_6 -> V_126 ) ;
return V_7 ;
}
static int F_39 ( struct V_116 * V_117 )
{
int V_7 ;
struct V_5 * V_6 = F_36 ( V_117 ) ;
if ( F_19 ( & V_6 -> V_126 ) )
return - V_52 ;
V_7 = V_6 -> V_131 [ F_33 ( V_117 ) -> V_121 ] ( V_117 ) ;
F_20 ( & V_6 -> V_126 ) ;
return V_7 ;
}
static int F_40 ( struct V_116 * V_117 )
{
int V_7 ;
struct V_5 * V_6 = F_36 ( V_117 ) ;
if ( F_19 ( & V_6 -> V_126 ) )
return - V_52 ;
V_7 = V_6 -> V_132 [ F_33 ( V_117 ) -> V_121 ] ( V_117 ) ;
F_20 ( & V_6 -> V_126 ) ;
return V_7 ;
}
static int F_41 ( struct V_116 * V_117 )
{
int V_7 ;
struct V_5 * V_6 = F_36 ( V_117 ) ;
if ( F_19 ( & V_6 -> V_126 ) )
return - V_52 ;
V_7 = V_6 -> V_133 [ F_33 ( V_117 ) -> V_121 ] ( V_117 ) ;
F_20 ( & V_6 -> V_126 ) ;
return V_7 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
int V_7 ;
T_1 V_134 [ 4 ] ;
T_1 V_36 , V_49 ;
struct V_3 V_4 = { V_27 , 0 , 0x5100 , 0 , 0 , sizeof( V_134 ) ,
V_134 } ;
F_23 ( & V_2 -> V_30 -> V_31 , L_5 , V_60 ) ;
V_134 [ 0 ] = V_6 -> V_68 >> 8 ;
V_134 [ 1 ] = V_6 -> V_68 & 0xff ;
V_134 [ 2 ] = V_6 -> V_69 >> 8 ;
V_134 [ 3 ] = V_6 -> V_69 & 0xff ;
F_43 ( 100 ) ;
V_7 = F_13 ( V_2 , V_6 -> V_40 [ 1 ] . V_14 ,
0x98be , & V_36 ) ;
if ( V_7 )
goto error;
else
F_23 ( & V_2 -> V_30 -> V_31 , L_22 ,
V_60 , V_36 ) ;
if ( V_36 == 0x0c )
goto exit;
V_7 = F_10 ( V_2 , 0xd416 , 0x04 ) ;
if ( V_7 )
goto error;
F_43 ( 50 ) ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
F_6 ( & V_2 -> V_30 -> V_31 , L_23 ,
V_32 , V_7 ) ;
F_23 ( & V_2 -> V_30 -> V_31 , L_24 , V_60 ) ;
V_7 = F_10 ( V_2 , 0xd416 , 0x14 ) ;
if ( V_7 )
goto error;
V_7 = F_12 ( V_2 , V_6 -> V_40 [ 1 ] . V_14 ,
0xe205 , 1 ) ;
F_23 ( & V_2 -> V_30 -> V_31 , L_25 ,
V_60 , V_7 ) ;
if ( V_7 )
goto error;
for ( V_49 = 0 ; V_49 < 15 ; V_49 ++ ) {
F_43 ( 100 ) ;
V_7 = F_13 ( V_2 , V_6 -> V_40 [ 1 ] . V_14 ,
0x98be , & V_36 ) ;
F_23 ( & V_2 -> V_30 -> V_31 , L_26 \
L_27 , V_60 , V_7 , V_36 ) ;
if ( V_7 )
goto error;
if ( V_36 == 0x0c || V_36 == 0x04 )
break;
}
if ( V_36 == 0x04 ) {
F_6 ( & V_2 -> V_30 -> V_31 , L_28 ,
V_32 ) ;
V_7 = - V_135 ;
} else if ( V_36 != 0x0c ) {
F_6 ( & V_2 -> V_30 -> V_31 , L_29 ,
V_32 ) ;
V_7 = - V_135 ;
}
error:
exit:
return V_7 ;
}
static int F_44 ( struct V_136 * V_45 )
{
int V_7 ;
struct V_5 * V_6 = F_45 ( V_45 ) ;
if ( V_45 -> V_121 == 0 ) {
V_6 -> V_40 [ 0 ] . V_137 = V_138 ;
memcpy ( V_6 -> V_40 [ 0 ] . V_139 , L_30 , 4 ) ;
V_6 -> V_40 [ 0 ] . V_106 [ 0 ] = V_140 ;
V_6 -> V_40 [ 0 ] . V_106 [ 3 ] = V_141 ;
} else if ( V_45 -> V_121 == 1 ) {
V_6 -> V_40 [ 1 ] . V_137 = V_142 ;
memcpy ( V_6 -> V_40 [ 1 ] . V_139 , L_30 , 4 ) ;
V_6 -> V_40 [ 1 ] . V_106 [ 0 ] = V_141 ;
V_6 -> V_40 [ 1 ] . V_106 [ 1 ] = V_107 ;
if ( V_6 -> V_79 ) {
V_7 = F_42 ( F_46 ( V_45 ) ) ;
if ( V_7 ) {
F_6 ( & F_46 ( V_45 ) -> V_30 -> V_31 ,
L_31 \
L_32 \
L_33 , V_32 ) ;
V_6 -> V_79 = 0 ;
return - V_108 ;
}
} else {
return - V_108 ;
}
}
V_45 -> V_117 [ 0 ] = F_47 ( V_143 ,
& V_6 -> V_40 [ V_45 -> V_121 ] , & F_46 ( V_45 ) -> V_144 ) ;
if ( V_45 -> V_117 [ 0 ] ) {
V_6 -> V_127 [ V_45 -> V_121 ] =
V_45 -> V_117 [ 0 ] -> V_145 . V_127 ;
V_45 -> V_117 [ 0 ] -> V_145 . V_127 =
F_35 ;
V_6 -> V_129 [ V_45 -> V_121 ] =
V_45 -> V_117 [ 0 ] -> V_145 . V_129 ;
V_45 -> V_117 [ 0 ] -> V_145 . V_129 =
F_37 ;
V_6 -> V_130 [ V_45 -> V_121 ] = V_45 -> V_117 [ 0 ] -> V_145 . V_130 ;
V_45 -> V_117 [ 0 ] -> V_145 . V_130 = F_38 ;
V_6 -> V_131 [ V_45 -> V_121 ] = V_45 -> V_117 [ 0 ] -> V_145 . V_131 ;
V_45 -> V_117 [ 0 ] -> V_145 . V_131 = F_39 ;
}
return V_45 -> V_117 [ 0 ] == NULL ? - V_108 : 0 ;
}
static int F_48 ( struct V_136 * V_45 )
{
struct V_1 * V_2 = F_46 ( V_45 ) ;
struct V_5 * V_6 = F_5 ( V_2 ) ;
int V_7 ;
F_23 ( & V_2 -> V_30 -> V_31 , L_5 , V_60 ) ;
switch ( V_6 -> V_40 [ V_45 -> V_121 ] . V_109 ) {
case V_93 :
case V_96 :
V_7 = F_47 ( V_146 , V_45 -> V_117 [ 0 ] ,
& F_46 ( V_45 ) -> V_144 , & V_147 ,
V_6 -> V_89 [ V_45 -> V_121 ] )
== NULL ? - V_108 : 0 ;
break;
case V_94 :
case V_98 :
V_7 = F_47 ( V_148 , V_45 -> V_117 [ 0 ] ,
& F_46 ( V_45 ) -> V_144 ,
& V_149 ) == NULL ? - V_108 : 0 ;
break;
case V_97 :
V_7 = F_47 ( V_150 , V_45 -> V_117 [ 0 ] , 0xc0 ,
& F_46 ( V_45 ) -> V_144 ,
& V_151 ) == NULL ? - V_108 : 0 ;
break;
case V_99 :
V_7 = F_47 ( V_152 , V_45 -> V_117 [ 0 ] ,
& F_46 ( V_45 ) -> V_144 ,
& V_153 ) == NULL ? - V_108 : 0 ;
break;
case V_101 :
V_7 = F_47 ( V_154 , V_45 -> V_117 [ 0 ] ,
& F_46 ( V_45 ) -> V_144 ,
& V_155 ) == NULL ? - V_108 : 0 ;
break;
case V_102 :
case V_103 :
V_7 = F_47 ( V_154 , V_45 -> V_117 [ 0 ] ,
& F_46 ( V_45 ) -> V_144 ,
& V_156 ) == NULL ? - V_108 : 0 ;
break;
case V_92 :
V_7 = F_47 ( V_157 , V_45 -> V_117 [ 0 ] , 0xc0 ,
& F_46 ( V_45 ) -> V_144 ,
V_158 ) == NULL ? - V_108 : 0 ;
break;
case V_105 :
V_7 = F_47 ( V_159 , V_45 -> V_117 [ 0 ] ,
& F_46 ( V_45 ) -> V_144 ,
& V_160 ) == NULL ? - V_108 : 0 ;
break;
case V_104 :
V_7 = F_47 ( V_161 , V_45 -> V_117 [ 0 ] ,
& F_46 ( V_45 ) -> V_144 ,
0xc0 , & V_162 ) == NULL ? - V_108 : 0 ;
break;
case V_95 :
default:
F_6 ( & V_2 -> V_30 -> V_31 , L_34 ,
V_32 ,
V_6 -> V_40 [ V_45 -> V_121 ] . V_109 ) ;
V_7 = - V_108 ;
}
if ( V_45 -> V_117 [ 0 ] -> V_145 . V_163 . V_130 ) {
V_6 -> V_132 [ V_45 -> V_121 ] =
V_45 -> V_117 [ 0 ] -> V_145 . V_163 . V_130 ;
V_45 -> V_117 [ 0 ] -> V_145 . V_163 . V_130 = F_40 ;
}
if ( V_45 -> V_117 [ 0 ] -> V_145 . V_163 . V_131 ) {
V_6 -> V_133 [ V_45 -> V_121 ] =
V_45 -> V_117 [ 0 ] -> V_145 . V_163 . V_131 ;
V_45 -> V_117 [ 0 ] -> V_145 . V_163 . V_131 = F_41 ;
}
return V_7 ;
}
static int F_49 ( struct V_136 * V_45 , int V_164 )
{
struct V_1 * V_2 = F_46 ( V_45 ) ;
int V_7 ;
F_23 ( & V_2 -> V_30 -> V_31 , L_35 , V_60 , V_164 ) ;
if ( V_164 )
V_7 = F_15 ( V_2 , 0xd503 , 0 ) ;
else
V_7 = F_16 ( V_2 , 0xd503 , 0 ) ;
return V_7 ;
}
static int F_50 ( struct V_136 * V_45 , int V_165 , T_2 V_166 ,
int V_164 )
{
struct V_1 * V_2 = F_46 ( V_45 ) ;
int V_7 ;
T_1 V_167 ;
F_23 ( & V_2 -> V_30 -> V_31 , L_36 ,
V_60 , V_165 , V_166 , V_164 ) ;
V_7 = F_10 ( V_2 , 0xd505 , ( V_166 & 0xff ) ) ;
if ( V_7 )
goto error;
V_7 = F_10 ( V_2 , 0xd506 , ( V_166 >> 8 ) ) ;
if ( V_7 )
goto error;
V_167 = ( ( V_165 & 0x1f ) | ( 1 << 5 ) ) ;
V_7 = F_10 ( V_2 , 0xd504 , V_167 ) ;
error:
return V_7 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
int V_7 ;
T_2 V_168 ;
T_1 V_169 ;
F_23 ( & V_2 -> V_30 -> V_31 , L_37 , V_60 , V_2 -> V_30 -> V_80 ) ;
if ( V_2 -> V_30 -> V_80 == V_81 ) {
V_168 = V_125 / 4 ;
V_169 = V_170 / 4 ;
} else {
V_168 = V_171 / 4 ;
V_169 = V_172 / 4 ;
}
V_7 = F_15 ( V_2 , 0xd507 , 2 ) ;
if ( V_7 )
goto error;
V_7 = F_15 ( V_2 , 0xd50b , 1 ) ;
if ( V_7 )
goto error;
V_7 = F_16 ( V_2 , 0xdd11 , 5 ) ;
if ( V_7 )
goto error;
V_7 = F_16 ( V_2 , 0xdd11 , 6 ) ;
if ( V_7 )
goto error;
V_7 = F_15 ( V_2 , 0xdd11 , 5 ) ;
if ( V_7 )
goto error;
if ( V_6 -> V_79 ) {
V_7 = F_15 ( V_2 , 0xdd11 , 6 ) ;
if ( V_7 )
goto error;
}
V_7 = F_16 ( V_2 , 0xdd13 , 5 ) ;
if ( V_7 )
goto error;
if ( V_6 -> V_79 ) {
V_7 = F_16 ( V_2 , 0xdd13 , 6 ) ;
if ( V_7 )
goto error;
}
V_7 = F_10 ( V_2 , 0xdd88 , V_168 & 0xff ) ;
if ( V_7 )
goto error;
V_7 = F_10 ( V_2 , 0xdd89 , V_168 >> 8 ) ;
if ( V_7 )
goto error;
V_7 = F_10 ( V_2 , 0xdd8a , V_168 & 0xff ) ;
if ( V_7 )
goto error;
V_7 = F_10 ( V_2 , 0xdd8b , V_168 >> 8 ) ;
if ( V_7 )
goto error;
V_7 = F_10 ( V_2 , 0xdd0c , V_169 ) ;
if ( V_7 )
goto error;
V_7 = F_10 ( V_2 , 0xdd0d , V_169 ) ;
if ( V_7 )
goto error;
V_7 = F_16 ( V_2 , 0xd507 , 2 ) ;
if ( V_7 )
goto error;
if ( V_6 -> V_79 ) {
V_7 = F_16 ( V_2 , 0xd50b , 1 ) ;
if ( V_7 )
goto error;
}
if ( V_6 -> V_79 )
V_7 = F_15 ( V_2 , 0xd50b , 0 ) ;
else
V_7 = F_16 ( V_2 , 0xd50b , 0 ) ;
error:
if ( V_7 )
F_6 ( & V_2 -> V_30 -> V_31 , L_38 ,
V_32 , V_7 ) ;
return V_7 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
int V_7 ;
F_23 ( & V_2 -> V_30 -> V_31 , L_5 , V_60 ) ;
F_53 ( & V_6 -> V_126 ) ;
V_7 = F_10 ( V_2 , 0x98e9 , 0xff ) ;
if ( V_7 )
goto error;
V_7 = F_51 ( V_2 ) ;
if ( V_7 )
goto error;
error:
return V_7 ;
}
static char * F_54 ( unsigned int V_121 ,
const struct V_173 * V_174 )
{
for (; V_174 -> V_175 ; V_174 ++ )
if ( V_174 -> V_121 == V_121 )
return V_174 -> V_175 ;
return NULL ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
int V_7 ;
T_1 V_10 [ 17 ] ;
V_7 = F_9 ( V_2 , 0x98d9 , V_10 , sizeof( V_10 ) ) ;
if ( V_7 )
goto error;
if ( V_10 [ 1 ] || V_10 [ 2 ] || V_10 [ 3 ] ) {
F_23 ( & V_2 -> V_30 -> V_31 , L_39 , V_60 ) ;
return V_7 ;
}
if ( ( V_6 -> V_176 != V_10 [ 6 ] || V_10 [ 0 ] ) &&
! memcmp ( & V_10 [ 12 ] , V_6 -> V_177 , 4 ) ) {
F_23 ( & V_2 -> V_30 -> V_31 , L_40 , V_60 ) ;
F_56 ( V_2 -> V_178 , V_6 -> V_179 , 0 ) ;
V_6 -> V_176 = V_10 [ 6 ] ;
return V_7 ;
}
if ( V_10 [ 16 ] != 0xff && V_10 [ 0 ] != 0x01 ) {
F_23 ( & V_2 -> V_30 -> V_31 , L_41 ,
V_60 , 4 , V_10 + 12 ) ;
V_7 = F_10 ( V_2 , 0x98e9 , 0xff ) ;
if ( V_7 )
goto error;
memcpy ( V_6 -> V_177 , & V_10 [ 12 ] , 4 ) ;
if ( V_10 [ 14 ] == ( T_1 ) ~ V_10 [ 15 ] ) {
if ( V_10 [ 12 ] == ( T_1 ) ~ V_10 [ 13 ] ) {
V_6 -> V_179 = V_10 [ 12 ] << 8 | V_10 [ 14 ] ;
} else {
V_6 -> V_179 = V_10 [ 12 ] << 16 |
V_10 [ 13 ] << 8 | V_10 [ 14 ] ;
}
} else {
V_6 -> V_179 = V_10 [ 12 ] << 24 | V_10 [ 13 ] << 16 |
V_10 [ 14 ] << 8 | V_10 [ 15 ] ;
}
F_56 ( V_2 -> V_178 , V_6 -> V_179 , 0 ) ;
} else {
F_23 ( & V_2 -> V_30 -> V_31 , L_42 , V_60 ) ;
V_6 -> V_177 [ 2 ] = V_6 -> V_177 [ 3 ] ;
}
V_6 -> V_176 = V_10 [ 6 ] ;
V_6 -> V_180 = false ;
error:
if ( V_7 ) {
F_57 ( & V_2 -> V_30 -> V_31 , L_43 ,
V_32 , V_7 ) ;
if ( ! V_6 -> V_180 )
V_7 = 0 ;
V_6 -> V_180 = true ;
}
return V_7 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_181 * V_182 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
T_2 V_183 = F_30 ( V_2 -> V_30 -> V_110 . V_111 ) ;
if ( V_6 -> V_77 == V_184 )
return 0 ;
if ( ! V_182 -> V_185 )
V_182 -> V_185 = F_54 ( V_186 ,
V_187 ) ;
if ( ! V_182 -> V_185 )
V_182 -> V_185 = F_54 ( V_6 -> V_73 ,
V_188 ) ;
if ( ! V_182 -> V_185 && V_183 == V_189 ) {
char V_190 [ 10 ] ;
memset ( V_190 , 0 , sizeof( V_190 ) ) ;
F_59 ( V_2 -> V_30 , V_2 -> V_30 -> V_110 . V_191 ,
V_190 , sizeof( V_190 ) ) ;
if ( ! strcmp ( L_44 , V_190 ) ) {
V_182 -> V_185 = F_54 (
V_192 ,
V_187 ) ;
}
}
if ( ! V_182 -> V_185 )
V_182 -> V_185 = V_193 ;
V_182 -> V_194 = V_195 ;
V_182 -> V_196 = F_55 ;
V_182 -> V_197 = 500 ;
return 0 ;
}
