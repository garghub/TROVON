static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
#define F_2 8
#define F_3 2
struct V_5 * V_6 = F_4 ( V_2 ) ;
int V_7 , V_8 , V_9 ;
T_1 V_10 = 1 ;
F_5 ( & V_2 -> V_11 ) ;
V_6 -> V_12 [ 0 ] = V_4 -> V_13 ;
V_6 -> V_12 [ 1 ] = V_6 -> V_14 ++ ;
V_6 -> V_12 [ 2 ] = V_4 -> V_15 ;
V_6 -> V_12 [ 3 ] = V_4 -> V_16 >> 8 ;
V_6 -> V_12 [ 4 ] = V_4 -> V_16 & 0xff ;
V_6 -> V_12 [ 5 ] = V_4 -> V_17 ;
V_6 -> V_12 [ 6 ] = V_4 -> V_18 ;
V_6 -> V_12 [ 7 ] = V_4 -> V_19 ;
switch ( V_4 -> V_13 ) {
case V_20 :
case V_21 :
case V_22 :
V_10 = 0 ;
break;
case V_23 :
V_10 = 0 ;
V_6 -> V_12 [ 2 ] |= 0x01 ;
case V_24 :
V_6 -> V_12 [ 0 ] = V_25 ;
break;
case V_26 :
if ( ( ( V_4 -> V_16 & 0xff00 ) == 0xff00 ) ||
( ( V_4 -> V_16 & 0xff00 ) == 0xae00 ) )
V_6 -> V_12 [ 0 ] = V_27 ;
case V_27 :
case V_28 :
case V_29 :
case V_30 :
break;
default:
F_6 ( & V_2 -> V_31 -> V_32 , L_1 ,
V_33 , V_4 -> V_13 ) ;
V_7 = - V_34 ;
goto error;
}
if ( ( V_10 && ( V_4 -> V_19 > V_35 - F_2 ) ) ||
( ! V_10 && ( V_4 -> V_19 > V_35 - F_3 ) ) ) {
F_6 ( & V_2 -> V_31 -> V_32 , L_2 ,
V_33 , V_4 -> V_13 , V_4 -> V_19 ) ;
V_7 = - V_36 ;
goto error;
}
V_8 = F_2 ;
V_9 = F_3 ;
if ( V_10 ) {
V_8 += V_4 -> V_19 ;
memcpy ( & V_6 -> V_12 [ F_2 ] , V_4 -> V_37 , V_4 -> V_19 ) ;
} else {
V_9 += V_4 -> V_19 ;
}
if ( V_4 -> V_13 == V_29 || V_4 -> V_13 == V_22 )
V_9 = 0 ;
V_7 = F_7 ( V_2 ,
V_6 -> V_12 , V_8 , V_6 -> V_12 , V_9 ) ;
if ( V_7 )
goto error;
if ( V_9 && V_6 -> V_12 [ 1 ] ) {
F_6 ( & V_2 -> V_31 -> V_32 , L_3 ,
V_33 , V_6 -> V_12 [ 1 ] ) ;
V_7 = - V_34 ;
goto error;
}
if ( ! V_10 )
memcpy ( V_4 -> V_37 , & V_6 -> V_12 [ F_3 ] , V_4 -> V_19 ) ;
error:
F_8 ( & V_2 -> V_11 ) ;
return V_7 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_16 , T_1 * V_38 ,
T_1 V_39 )
{
struct V_3 V_4 = { V_26 , V_40 , V_16 , 0 , 0 , V_39 ,
V_38 } ;
return F_1 ( V_2 , & V_4 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_16 , T_1 * V_38 , T_1 V_39 )
{
struct V_3 V_4 = { V_21 , V_40 , V_16 , 0 , 0 , V_39 ,
V_38 } ;
return F_1 ( V_2 , & V_4 ) ;
}
static int F_11 ( struct V_1 * V_2 , T_2 V_16 , T_1 V_38 )
{
return F_9 ( V_2 , V_16 , & V_38 , 1 ) ;
}
static int F_12 ( struct V_1 * V_2 , T_2 V_16 , T_1 * V_38 )
{
return F_10 ( V_2 , V_16 , V_38 , 1 ) ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_16 , T_2 V_41 ,
T_1 V_38 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
struct V_3 V_4 = { V_24 , V_16 , V_41 , 1 , 1 , 1 , & V_38 } ;
if ( V_16 == V_6 -> V_42 [ 0 ] . V_15 ||
V_16 == V_6 -> V_42 [ 1 ] . V_15 )
V_4 . V_18 = 3 ;
return F_1 ( V_2 , & V_4 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_16 , T_2 V_41 ,
T_1 * V_38 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
struct V_3 V_4 = { V_23 , V_16 , V_41 , 0 , 1 , 1 , V_38 } ;
if ( V_16 == V_6 -> V_42 [ 0 ] . V_15 ||
V_16 == V_6 -> V_42 [ 1 ] . V_15 )
V_4 . V_18 = 3 ;
return F_1 ( V_2 , & V_4 ) ;
}
static int F_15 ( struct V_1 * V_2 , T_2 V_16 , T_1 V_43 , T_1 V_44 )
{
int V_7 ;
T_1 V_38 , V_45 = 0x01 ;
V_7 = F_12 ( V_2 , V_16 , & V_38 ) ;
if ( V_7 )
return V_7 ;
V_45 <<= V_43 ;
if ( V_44 ) {
V_38 |= V_45 ;
} else {
V_45 ^= 0xff ;
V_38 &= V_45 ;
}
return F_11 ( V_2 , V_16 , V_38 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_2 V_16 , T_1 V_43 )
{
return F_15 ( V_2 , V_16 , V_43 , 1 ) ;
}
static int F_17 ( struct V_1 * V_2 , T_2 V_16 , T_1 V_43 )
{
return F_15 ( V_2 , V_16 , V_43 , 0 ) ;
}
static int F_18 ( struct V_46 * V_47 , struct V_48 V_49 [] ,
int V_50 )
{
struct V_1 * V_2 = F_19 ( V_47 ) ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
int V_7 = 0 , V_51 = 0 ;
T_2 V_16 ;
T_1 V_52 ( V_17 ) , V_18 ;
struct V_3 V_4 ;
if ( F_20 ( & V_2 -> V_53 ) < 0 )
return - V_54 ;
while ( V_51 < V_50 ) {
if ( V_49 [ V_51 ] . V_16 == V_6 -> V_42 [ 0 ] . V_15 ||
V_49 [ V_51 ] . V_16 == V_6 -> V_42 [ 1 ] . V_15 ) {
V_16 = V_49 [ V_51 ] . V_12 [ 0 ] << 8 ;
V_16 += V_49 [ V_51 ] . V_12 [ 1 ] ;
V_17 = V_49 [ V_51 ] . V_12 [ 2 ] ;
V_18 = 3 ;
} else {
V_16 = V_49 [ V_51 ] . V_12 [ 0 ] ;
V_18 = 1 ;
}
if ( V_50 > V_51 + 1 && ( V_49 [ V_51 + 1 ] . V_55 & V_56 ) ) {
if ( V_49 [ V_51 ] . V_39 > 3 || V_49 [ V_51 + 1 ] . V_39 > 61 ) {
V_7 = - V_57 ;
goto error;
}
if ( V_49 [ V_51 ] . V_16 == V_6 -> V_42 [ 0 ] . V_15 )
V_4 . V_13 = V_21 ;
else
V_4 . V_13 = V_23 ;
V_4 . V_15 = V_49 [ V_51 ] . V_16 ;
V_4 . V_16 = V_16 ;
V_4 . V_17 = V_17 ;
V_4 . V_18 = V_18 ;
V_4 . V_19 = V_49 [ V_51 + 1 ] . V_39 ;
V_4 . V_37 = & V_49 [ V_51 + 1 ] . V_12 [ 0 ] ;
V_7 = F_1 ( V_2 , & V_4 ) ;
V_51 += 2 ;
} else if ( V_49 [ V_51 ] . V_55 & V_56 ) {
if ( V_49 [ V_51 ] . V_39 > 61 ) {
V_7 = - V_57 ;
goto error;
}
if ( V_49 [ V_51 ] . V_16 == V_6 -> V_42 [ 0 ] . V_15 ) {
V_7 = - V_36 ;
goto error;
}
V_4 . V_13 = V_23 ;
V_4 . V_15 = V_49 [ V_51 ] . V_16 ;
V_4 . V_16 = V_16 ;
V_4 . V_17 = V_17 ;
V_4 . V_18 = V_18 ;
V_4 . V_19 = V_49 [ V_51 ] . V_39 ;
V_4 . V_37 = & V_49 [ V_51 ] . V_12 [ 0 ] ;
V_7 = F_1 ( V_2 , & V_4 ) ;
V_51 += 1 ;
} else {
if ( V_49 [ V_51 ] . V_39 > 21 ) {
V_7 = - V_57 ;
goto error;
}
if ( V_49 [ V_51 ] . V_16 == V_6 -> V_42 [ 0 ] . V_15 )
V_4 . V_13 = V_26 ;
else
V_4 . V_13 = V_24 ;
V_4 . V_15 = V_49 [ V_51 ] . V_16 ;
V_4 . V_16 = V_16 ;
V_4 . V_17 = V_17 ;
V_4 . V_18 = V_18 ;
V_4 . V_19 = V_49 [ V_51 ] . V_39 - V_18 ;
V_4 . V_37 = & V_49 [ V_51 ] . V_12 [ V_18 ] ;
V_7 = F_1 ( V_2 , & V_4 ) ;
V_51 += 1 ;
}
if ( V_7 )
goto error;
}
V_7 = V_51 ;
error:
F_8 ( & V_2 -> V_53 ) ;
return V_7 ;
}
static T_3 F_21 ( struct V_46 * V_58 )
{
return V_59 ;
}
static int F_22 ( struct V_1 * V_2 , const char * * V_60 )
{
int V_7 ;
T_1 V_61 ;
struct V_3 V_4 = { V_20 , 0 , 0 , 0 , 0 , 1 , & V_61 } ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
return V_7 ;
F_23 ( & V_2 -> V_31 -> V_32 , L_4 , V_62 , V_61 ) ;
if ( V_61 == 0x02 )
V_7 = V_63 ;
else
V_7 = V_64 ;
return V_7 ;
}
static int F_24 ( struct V_1 * V_2 ,
const struct V_65 * V_66 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
int V_51 , V_39 , V_67 , V_7 ;
struct V_3 V_4 = { V_29 , 0 , 0 , 0 , 0 , 0 , NULL } ;
T_2 V_68 = 0 ;
F_23 ( & V_2 -> V_31 -> V_32 , L_5 , V_62 ) ;
for ( V_51 = 0 ; V_51 < V_66 -> V_69 ; V_51 ++ )
V_68 += V_66 -> V_37 [ V_51 ] ;
V_6 -> V_70 = V_66 -> V_69 ;
V_6 -> V_71 = V_68 ;
#define F_25 0x5100
#define F_26 55
for ( V_67 = V_66 -> V_69 ; V_67 > 0 ; V_67 -= F_26 ) {
V_39 = V_67 ;
if ( V_39 > F_26 )
V_39 = F_26 ;
V_4 . V_19 = V_39 ;
V_4 . V_37 = ( T_1 * ) & V_66 -> V_37 [ V_66 -> V_69 - V_67 ] ;
V_4 . V_16 = F_25 + V_66 -> V_69 - V_67 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 ) {
F_6 ( & V_2 -> V_31 -> V_32 ,
L_6 ,
V_33 , V_7 ) ;
goto error;
}
}
V_4 . V_13 = V_30 ;
V_4 . V_19 = 0 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 ) {
F_6 ( & V_2 -> V_31 -> V_32 , L_7 ,
V_33 , V_7 ) ;
goto error;
}
error:
return V_7 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
int V_7 , V_51 ;
T_1 V_12 [ V_72 ] ;
struct V_3 V_4 = { V_23 , V_73 , 0 , 0 , 1 , 1 , NULL } ;
for ( V_51 = 0 ; V_51 < V_72 ; V_51 ++ ) {
V_4 . V_16 = V_51 ;
V_4 . V_37 = & V_12 [ V_51 ] ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 < 0 )
goto V_74;
}
for ( V_51 = 0 ; V_51 < V_72 / sizeof( T_3 ) ; V_51 ++ ) {
V_6 -> V_75 *= V_76 ;
V_6 -> V_75 += F_28 ( ( ( V_77 * ) V_12 ) [ V_51 ] ) ;
}
for ( V_51 = 0 ; V_51 < V_72 ; V_51 += 16 )
F_23 ( & V_2 -> V_31 -> V_32 , L_8 , V_62 , 16 , V_12 + V_51 ) ;
F_23 ( & V_2 -> V_31 -> V_32 , L_9 ,
V_62 , V_6 -> V_75 ) ;
return 0 ;
V_74:
F_6 ( & V_2 -> V_31 -> V_32 , L_10 , V_33 , V_7 ) ;
return V_7 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
int V_7 ;
T_1 V_38 , V_51 , V_78 = 0 ;
struct V_3 V_4 = { V_23 , V_73 , 0 , 0 , 1 , 1 , & V_38 } ;
F_23 ( & V_2 -> V_31 -> V_32 , L_5 , V_62 ) ;
V_4 . V_16 = V_79 ;
for ( V_51 = 0 ; V_51 < 4 ; V_51 ++ ) {
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( ! V_7 )
break;
}
if ( V_7 )
goto error;
V_7 = F_27 ( V_2 ) ;
if ( V_7 )
goto error;
V_6 -> V_80 = V_38 ;
F_23 ( & V_2 -> V_31 -> V_32 , L_11 , V_62 , V_38 ) ;
V_4 . V_16 = V_81 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto error;
V_6 -> V_82 = V_38 ;
F_23 ( & V_2 -> V_31 -> V_32 , L_12 , V_62 , V_6 -> V_82 ) ;
if ( V_2 -> V_31 -> V_83 == V_84 )
V_6 -> V_82 = 0 ;
if ( V_6 -> V_82 ) {
V_4 . V_16 = V_85 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto error;
V_6 -> V_42 [ 1 ] . V_15 = V_38 ;
}
for ( V_51 = 0 ; V_51 < V_6 -> V_82 + 1 ; V_51 ++ ) {
if ( V_51 == 1 )
V_78 = V_86 ;
V_4 . V_16 = V_87 + V_78 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto error;
switch ( V_38 ) {
case 0 :
V_6 -> V_42 [ V_51 ] . clock = 28800000 ;
break;
case 1 :
V_6 -> V_42 [ V_51 ] . clock = 20480000 ;
break;
case 2 :
V_6 -> V_42 [ V_51 ] . clock = 28000000 ;
break;
case 3 :
V_6 -> V_42 [ V_51 ] . clock = 25000000 ;
break;
}
F_23 ( & V_2 -> V_31 -> V_32 , L_13 ,
V_62 , V_51 , V_38 ,
V_6 -> V_42 [ V_51 ] . clock ) ;
V_4 . V_16 = V_88 + V_78 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto error;
V_6 -> V_42 [ V_51 ] . V_89 = V_38 << 8 ;
V_4 . V_16 = V_90 + V_78 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto error;
V_6 -> V_42 [ V_51 ] . V_89 += V_38 ;
V_6 -> V_42 [ V_51 ] . V_89 *= 1000 ;
F_23 ( & V_2 -> V_31 -> V_32 , L_14 , V_62 ,
V_51 , V_6 -> V_42 [ V_51 ] . V_89 ) ;
V_4 . V_16 = V_91 + V_78 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto error;
V_6 -> V_92 [ V_51 ] = V_38 << 8 ;
V_4 . V_16 = V_93 + V_78 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto error;
V_6 -> V_92 [ V_51 ] += V_38 ;
F_23 ( & V_2 -> V_31 -> V_32 , L_15 , V_62 , V_51 ,
V_6 -> V_92 [ V_51 ] ) ;
V_4 . V_16 = V_94 + V_78 ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
goto error;
switch ( V_38 ) {
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
V_6 -> V_42 [ V_51 ] . V_103 = 1 ;
break;
case V_104 :
case V_105 :
case V_106 :
case V_107 :
V_6 -> V_42 [ V_51 ] . V_103 = 0 ;
break;
case V_108 :
V_6 -> V_42 [ V_51 ] . V_109 [ 1 ] = V_110 ;
V_6 -> V_42 [ V_51 ] . V_103 = 1 ;
break;
default:
F_6 ( & V_2 -> V_31 -> V_32 , L_16 \
L_17 ,
V_33 , V_38 ) ;
return - V_111 ;
}
V_6 -> V_42 [ V_51 ] . V_112 = V_38 ;
F_23 ( & V_2 -> V_31 -> V_32 , L_18 ,
V_62 , V_51 , V_38 ) ;
}
error:
if ( V_7 )
F_6 ( & V_2 -> V_31 -> V_32 , L_19 ,
V_33 , V_7 ) ;
if ( F_30 ( V_2 -> V_31 -> V_113 . V_114 ) == V_115 &&
( ( F_30 ( V_2 -> V_31 -> V_113 . V_116 ) ==
V_117 ) ||
( F_30 ( V_2 -> V_31 -> V_113 . V_116 ) ==
V_118 ) ) ) {
F_23 ( & V_2 -> V_31 -> V_32 ,
L_20 ,
V_62 ) ;
V_6 -> V_82 = 0 ;
V_6 -> V_42 [ 0 ] . V_89 = 4570000 ;
}
return V_7 ;
}
static int F_31 ( struct V_119 * V_120 , T_1 * V_121 ,
struct V_122 * V_123 )
{
struct V_1 * V_2 = F_32 ( V_120 ) ;
F_23 ( & V_2 -> V_31 -> V_32 , L_21 , V_62 , F_33 ( V_120 ) -> V_124 ) ;
if ( V_2 -> V_31 -> V_83 == V_84 )
V_123 -> V_125 . V_126 . V_127 = V_128 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
return V_6 -> V_82 + 1 ;
}
static int F_35 ( struct V_119 * V_120 )
{
int V_7 ;
struct V_5 * V_6 = F_36 ( V_120 ) ;
if ( F_20 ( & V_6 -> V_129 ) )
return - V_54 ;
V_7 = V_6 -> V_130 [ F_33 ( V_120 ) -> V_124 ] ( V_120 ) ;
F_8 ( & V_6 -> V_129 ) ;
return V_7 ;
}
static int F_37 ( struct V_119 * V_120 ,
enum V_131 * V_132 )
{
int V_7 ;
struct V_5 * V_6 = F_36 ( V_120 ) ;
if ( F_20 ( & V_6 -> V_129 ) )
return - V_54 ;
V_7 = V_6 -> V_133 [ F_33 ( V_120 ) -> V_124 ] ( V_120 , V_132 ) ;
F_8 ( & V_6 -> V_129 ) ;
return V_7 ;
}
static int F_38 ( struct V_119 * V_120 )
{
int V_7 ;
struct V_5 * V_6 = F_36 ( V_120 ) ;
if ( F_20 ( & V_6 -> V_129 ) )
return - V_54 ;
V_7 = V_6 -> V_134 [ F_33 ( V_120 ) -> V_124 ] ( V_120 ) ;
F_8 ( & V_6 -> V_129 ) ;
return V_7 ;
}
static int F_39 ( struct V_119 * V_120 )
{
int V_7 ;
struct V_5 * V_6 = F_36 ( V_120 ) ;
if ( F_20 ( & V_6 -> V_129 ) )
return - V_54 ;
V_7 = V_6 -> V_135 [ F_33 ( V_120 ) -> V_124 ] ( V_120 ) ;
F_8 ( & V_6 -> V_129 ) ;
return V_7 ;
}
static int F_40 ( struct V_119 * V_120 )
{
int V_7 ;
struct V_5 * V_6 = F_36 ( V_120 ) ;
if ( F_20 ( & V_6 -> V_129 ) )
return - V_54 ;
V_7 = V_6 -> V_136 [ F_33 ( V_120 ) -> V_124 ] ( V_120 ) ;
F_8 ( & V_6 -> V_129 ) ;
return V_7 ;
}
static int F_41 ( struct V_119 * V_120 )
{
int V_7 ;
struct V_5 * V_6 = F_36 ( V_120 ) ;
if ( F_20 ( & V_6 -> V_129 ) )
return - V_54 ;
V_7 = V_6 -> V_137 [ F_33 ( V_120 ) -> V_124 ] ( V_120 ) ;
F_8 ( & V_6 -> V_129 ) ;
return V_7 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
int V_7 ;
T_1 V_138 [ 4 ] ;
T_1 V_38 , V_51 ;
struct V_3 V_4 = { V_28 , 0 , 0x5100 , 0 , 0 , sizeof( V_138 ) ,
V_138 } ;
F_23 ( & V_2 -> V_31 -> V_32 , L_5 , V_62 ) ;
V_138 [ 0 ] = V_6 -> V_70 >> 8 ;
V_138 [ 1 ] = V_6 -> V_70 & 0xff ;
V_138 [ 2 ] = V_6 -> V_71 >> 8 ;
V_138 [ 3 ] = V_6 -> V_71 & 0xff ;
F_43 ( 100 ) ;
V_7 = F_14 ( V_2 , V_6 -> V_42 [ 1 ] . V_15 ,
0x98be , & V_38 ) ;
if ( V_7 )
goto error;
else
F_23 ( & V_2 -> V_31 -> V_32 , L_22 ,
V_62 , V_38 ) ;
if ( V_38 == 0x0c )
goto exit;
V_7 = F_11 ( V_2 , 0xd416 , 0x04 ) ;
if ( V_7 )
goto error;
F_43 ( 50 ) ;
V_7 = F_1 ( V_2 , & V_4 ) ;
if ( V_7 )
F_6 ( & V_2 -> V_31 -> V_32 , L_23 ,
V_33 , V_7 ) ;
F_23 ( & V_2 -> V_31 -> V_32 , L_24 , V_62 ) ;
V_7 = F_11 ( V_2 , 0xd416 , 0x14 ) ;
if ( V_7 )
goto error;
V_7 = F_13 ( V_2 , V_6 -> V_42 [ 1 ] . V_15 ,
0xe205 , 1 ) ;
F_23 ( & V_2 -> V_31 -> V_32 , L_25 ,
V_62 , V_7 ) ;
if ( V_7 )
goto error;
for ( V_51 = 0 ; V_51 < 15 ; V_51 ++ ) {
F_43 ( 100 ) ;
V_7 = F_14 ( V_2 , V_6 -> V_42 [ 1 ] . V_15 ,
0x98be , & V_38 ) ;
F_23 ( & V_2 -> V_31 -> V_32 , L_26 \
L_27 , V_62 , V_7 , V_38 ) ;
if ( V_7 )
goto error;
if ( V_38 == 0x0c || V_38 == 0x04 )
break;
}
if ( V_38 == 0x04 ) {
F_6 ( & V_2 -> V_31 -> V_32 , L_28 ,
V_33 ) ;
V_7 = - V_139 ;
} else if ( V_38 != 0x0c ) {
F_6 ( & V_2 -> V_31 -> V_32 , L_29 ,
V_33 ) ;
V_7 = - V_139 ;
}
error:
exit:
return V_7 ;
}
static int F_44 ( struct V_140 * V_47 )
{
int V_7 ;
struct V_5 * V_6 = F_45 ( V_47 ) ;
if ( V_47 -> V_124 == 0 ) {
V_6 -> V_42 [ 0 ] . V_141 = V_142 ;
memcpy ( V_6 -> V_42 [ 0 ] . V_143 , L_30 , 4 ) ;
V_6 -> V_42 [ 0 ] . V_109 [ 0 ] = V_144 ;
V_6 -> V_42 [ 0 ] . V_109 [ 3 ] = V_145 ;
} else if ( V_47 -> V_124 == 1 ) {
V_6 -> V_42 [ 1 ] . V_141 = V_146 ;
memcpy ( V_6 -> V_42 [ 1 ] . V_143 , L_30 , 4 ) ;
V_6 -> V_42 [ 1 ] . V_109 [ 0 ] = V_145 ;
V_6 -> V_42 [ 1 ] . V_109 [ 1 ] = V_110 ;
if ( V_6 -> V_82 ) {
V_7 = F_42 ( F_46 ( V_47 ) ) ;
if ( V_7 ) {
F_6 ( & F_46 ( V_47 ) -> V_31 -> V_32 ,
L_31 \
L_32 \
L_33 , V_33 ) ;
V_6 -> V_82 = 0 ;
return - V_111 ;
}
} else {
return - V_111 ;
}
}
V_47 -> V_120 [ 0 ] = F_47 ( V_147 ,
& V_6 -> V_42 [ V_47 -> V_124 ] , & F_46 ( V_47 ) -> V_148 ) ;
if ( V_47 -> V_120 [ 0 ] ) {
V_6 -> V_130 [ V_47 -> V_124 ] =
V_47 -> V_120 [ 0 ] -> V_149 . V_130 ;
V_47 -> V_120 [ 0 ] -> V_149 . V_130 =
F_35 ;
V_6 -> V_133 [ V_47 -> V_124 ] =
V_47 -> V_120 [ 0 ] -> V_149 . V_133 ;
V_47 -> V_120 [ 0 ] -> V_149 . V_133 =
F_37 ;
V_6 -> V_134 [ V_47 -> V_124 ] = V_47 -> V_120 [ 0 ] -> V_149 . V_134 ;
V_47 -> V_120 [ 0 ] -> V_149 . V_134 = F_38 ;
V_6 -> V_135 [ V_47 -> V_124 ] = V_47 -> V_120 [ 0 ] -> V_149 . V_135 ;
V_47 -> V_120 [ 0 ] -> V_149 . V_135 = F_39 ;
}
return V_47 -> V_120 [ 0 ] == NULL ? - V_111 : 0 ;
}
static int F_48 ( struct V_140 * V_47 )
{
struct V_1 * V_2 = F_46 ( V_47 ) ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
int V_7 ;
F_23 ( & V_2 -> V_31 -> V_32 , L_5 , V_62 ) ;
switch ( V_6 -> V_42 [ V_47 -> V_124 ] . V_112 ) {
case V_96 :
case V_99 :
V_7 = F_47 ( V_150 , V_47 -> V_120 [ 0 ] ,
& F_46 ( V_47 ) -> V_148 , & V_151 ,
V_6 -> V_92 [ V_47 -> V_124 ] )
== NULL ? - V_111 : 0 ;
break;
case V_97 :
case V_101 :
V_7 = F_47 ( V_152 , V_47 -> V_120 [ 0 ] ,
& F_46 ( V_47 ) -> V_148 ,
& V_153 ) == NULL ? - V_111 : 0 ;
break;
case V_100 :
V_7 = F_47 ( V_154 , V_47 -> V_120 [ 0 ] , 0xc0 ,
& F_46 ( V_47 ) -> V_148 ,
& V_155 ) == NULL ? - V_111 : 0 ;
break;
case V_102 :
V_7 = F_47 ( V_156 , V_47 -> V_120 [ 0 ] ,
& F_46 ( V_47 ) -> V_148 ,
& V_157 ) == NULL ? - V_111 : 0 ;
break;
case V_104 :
V_7 = F_47 ( V_158 , V_47 -> V_120 [ 0 ] ,
& F_46 ( V_47 ) -> V_148 ,
& V_159 ) == NULL ? - V_111 : 0 ;
break;
case V_105 :
case V_106 :
V_7 = F_47 ( V_158 , V_47 -> V_120 [ 0 ] ,
& F_46 ( V_47 ) -> V_148 ,
& V_160 ) == NULL ? - V_111 : 0 ;
break;
case V_95 :
V_7 = F_47 ( V_161 , V_47 -> V_120 [ 0 ] , 0xc0 ,
& F_46 ( V_47 ) -> V_148 ,
V_162 ) == NULL ? - V_111 : 0 ;
break;
case V_108 :
V_7 = F_47 ( V_163 , V_47 -> V_120 [ 0 ] ,
& F_46 ( V_47 ) -> V_148 ,
& V_164 ) == NULL ? - V_111 : 0 ;
break;
case V_107 :
V_7 = F_47 ( V_165 , V_47 -> V_120 [ 0 ] ,
& F_46 ( V_47 ) -> V_148 ,
0xc0 , & V_166 ) == NULL ? - V_111 : 0 ;
break;
case V_98 :
default:
F_6 ( & V_2 -> V_31 -> V_32 , L_34 ,
V_33 ,
V_6 -> V_42 [ V_47 -> V_124 ] . V_112 ) ;
V_7 = - V_111 ;
}
if ( V_47 -> V_120 [ 0 ] -> V_149 . V_167 . V_134 ) {
V_6 -> V_136 [ V_47 -> V_124 ] =
V_47 -> V_120 [ 0 ] -> V_149 . V_167 . V_134 ;
V_47 -> V_120 [ 0 ] -> V_149 . V_167 . V_134 = F_40 ;
}
if ( V_47 -> V_120 [ 0 ] -> V_149 . V_167 . V_135 ) {
V_6 -> V_137 [ V_47 -> V_124 ] =
V_47 -> V_120 [ 0 ] -> V_149 . V_167 . V_135 ;
V_47 -> V_120 [ 0 ] -> V_149 . V_167 . V_135 = F_41 ;
}
return V_7 ;
}
static int F_49 ( struct V_140 * V_47 , int V_168 )
{
struct V_1 * V_2 = F_46 ( V_47 ) ;
int V_7 ;
F_23 ( & V_2 -> V_31 -> V_32 , L_35 , V_62 , V_168 ) ;
if ( V_168 )
V_7 = F_16 ( V_2 , 0xd503 , 0 ) ;
else
V_7 = F_17 ( V_2 , 0xd503 , 0 ) ;
return V_7 ;
}
static int F_50 ( struct V_140 * V_47 , int V_169 , T_2 V_170 ,
int V_168 )
{
struct V_1 * V_2 = F_46 ( V_47 ) ;
int V_7 ;
T_1 V_171 ;
F_23 ( & V_2 -> V_31 -> V_32 , L_36 ,
V_62 , V_169 , V_170 , V_168 ) ;
V_7 = F_11 ( V_2 , 0xd505 , ( V_170 & 0xff ) ) ;
if ( V_7 )
goto error;
V_7 = F_11 ( V_2 , 0xd506 , ( V_170 >> 8 ) ) ;
if ( V_7 )
goto error;
V_171 = ( ( V_169 & 0x1f ) | ( 1 << 5 ) ) ;
V_7 = F_11 ( V_2 , 0xd504 , V_171 ) ;
error:
return V_7 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
int V_7 ;
T_2 V_172 ;
T_1 V_173 ;
F_23 ( & V_2 -> V_31 -> V_32 , L_37 , V_62 , V_2 -> V_31 -> V_83 ) ;
if ( V_2 -> V_31 -> V_83 == V_84 ) {
V_172 = V_128 / 4 ;
V_173 = V_174 / 4 ;
} else {
V_172 = V_175 / 4 ;
V_173 = V_176 / 4 ;
}
V_7 = F_16 ( V_2 , 0xd507 , 2 ) ;
if ( V_7 )
goto error;
V_7 = F_16 ( V_2 , 0xd50b , 1 ) ;
if ( V_7 )
goto error;
V_7 = F_17 ( V_2 , 0xdd11 , 5 ) ;
if ( V_7 )
goto error;
V_7 = F_17 ( V_2 , 0xdd11 , 6 ) ;
if ( V_7 )
goto error;
V_7 = F_16 ( V_2 , 0xdd11 , 5 ) ;
if ( V_7 )
goto error;
if ( V_6 -> V_82 ) {
V_7 = F_16 ( V_2 , 0xdd11 , 6 ) ;
if ( V_7 )
goto error;
}
V_7 = F_17 ( V_2 , 0xdd13 , 5 ) ;
if ( V_7 )
goto error;
if ( V_6 -> V_82 ) {
V_7 = F_17 ( V_2 , 0xdd13 , 6 ) ;
if ( V_7 )
goto error;
}
V_7 = F_11 ( V_2 , 0xdd88 , V_172 & 0xff ) ;
if ( V_7 )
goto error;
V_7 = F_11 ( V_2 , 0xdd89 , V_172 >> 8 ) ;
if ( V_7 )
goto error;
V_7 = F_11 ( V_2 , 0xdd8a , V_172 & 0xff ) ;
if ( V_7 )
goto error;
V_7 = F_11 ( V_2 , 0xdd8b , V_172 >> 8 ) ;
if ( V_7 )
goto error;
V_7 = F_11 ( V_2 , 0xdd0c , V_173 ) ;
if ( V_7 )
goto error;
V_7 = F_11 ( V_2 , 0xdd0d , V_173 ) ;
if ( V_7 )
goto error;
V_7 = F_17 ( V_2 , 0xd507 , 2 ) ;
if ( V_7 )
goto error;
if ( V_6 -> V_82 ) {
V_7 = F_17 ( V_2 , 0xd50b , 1 ) ;
if ( V_7 )
goto error;
}
if ( V_6 -> V_82 )
V_7 = F_16 ( V_2 , 0xd50b , 0 ) ;
else
V_7 = F_17 ( V_2 , 0xd50b , 0 ) ;
error:
if ( V_7 )
F_6 ( & V_2 -> V_31 -> V_32 , L_38 ,
V_33 , V_7 ) ;
return V_7 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
int V_7 ;
F_23 ( & V_2 -> V_31 -> V_32 , L_5 , V_62 ) ;
F_53 ( & V_6 -> V_129 ) ;
V_7 = F_11 ( V_2 , 0x98e9 , 0xff ) ;
if ( V_7 )
goto error;
V_7 = F_51 ( V_2 ) ;
if ( V_7 )
goto error;
error:
return V_7 ;
}
static char * F_54 ( unsigned int V_124 ,
const struct V_177 * V_178 )
{
for (; V_178 -> V_179 ; V_178 ++ )
if ( V_178 -> V_124 == V_124 )
return V_178 -> V_179 ;
return NULL ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
int V_7 ;
T_1 V_12 [ 17 ] ;
V_7 = F_10 ( V_2 , 0x98d9 , V_12 , sizeof( V_12 ) ) ;
if ( V_7 )
goto error;
if ( V_12 [ 1 ] || V_12 [ 2 ] || V_12 [ 3 ] ) {
F_23 ( & V_2 -> V_31 -> V_32 , L_39 , V_62 ) ;
return V_7 ;
}
if ( ( V_6 -> V_180 != V_12 [ 6 ] || V_12 [ 0 ] ) &&
! memcmp ( & V_12 [ 12 ] , V_6 -> V_181 , 4 ) ) {
F_23 ( & V_2 -> V_31 -> V_32 , L_40 , V_62 ) ;
V_180 ( V_2 -> V_182 ) ;
V_6 -> V_180 = V_12 [ 6 ] ;
return V_7 ;
}
if ( V_12 [ 16 ] != 0xff && V_12 [ 0 ] != 0x01 ) {
F_23 ( & V_2 -> V_31 -> V_32 , L_41 ,
V_62 , 4 , V_12 + 12 ) ;
V_7 = F_11 ( V_2 , 0x98e9 , 0xff ) ;
if ( V_7 )
goto error;
memcpy ( V_6 -> V_181 , & V_12 [ 12 ] , 4 ) ;
if ( V_12 [ 14 ] == ( T_1 ) ~ V_12 [ 15 ] ) {
if ( V_12 [ 12 ] == ( T_1 ) ~ V_12 [ 13 ] ) {
V_6 -> V_183 = F_56 ( V_12 [ 12 ] ,
V_12 [ 14 ] ) ;
} else {
V_6 -> V_183 = F_57 ( V_12 [ 12 ] << 8 |
V_12 [ 13 ] ,
V_12 [ 14 ] ) ;
}
} else {
V_6 -> V_183 = F_58 ( V_12 [ 12 ] << 24 |
V_12 [ 13 ] << 16 |
V_12 [ 14 ] << 8 |
V_12 [ 15 ] ) ;
}
F_59 ( V_2 -> V_182 , V_184 , V_6 -> V_183 , 0 ) ;
} else {
F_23 ( & V_2 -> V_31 -> V_32 , L_42 , V_62 ) ;
V_6 -> V_181 [ 2 ] = V_6 -> V_181 [ 3 ] ;
}
V_6 -> V_180 = V_12 [ 6 ] ;
V_6 -> V_185 = false ;
error:
if ( V_7 ) {
F_60 ( & V_2 -> V_31 -> V_32 , L_43 ,
V_33 , V_7 ) ;
if ( ! V_6 -> V_185 )
V_7 = 0 ;
V_6 -> V_185 = true ;
}
return V_7 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_186 * V_187 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
T_2 V_188 = F_30 ( V_2 -> V_31 -> V_113 . V_114 ) ;
if ( V_6 -> V_80 == V_189 )
return 0 ;
if ( ! V_187 -> V_190 )
V_187 -> V_190 = F_54 ( V_191 ,
V_192 ) ;
if ( ! V_187 -> V_190 )
V_187 -> V_190 = F_54 ( V_6 -> V_75 ,
V_193 ) ;
if ( ! V_187 -> V_190 && V_188 == V_194 ) {
char V_195 [ 10 ] ;
memset ( V_195 , 0 , sizeof( V_195 ) ) ;
F_62 ( V_2 -> V_31 , V_2 -> V_31 -> V_113 . V_196 ,
V_195 , sizeof( V_195 ) ) ;
if ( ! strcmp ( L_44 , V_195 ) ) {
V_187 -> V_190 = F_54 (
V_197 ,
V_192 ) ;
}
}
if ( ! V_187 -> V_190 )
V_187 -> V_190 = V_198 ;
V_187 -> V_199 = V_200 ;
V_187 -> V_201 = F_55 ;
V_187 -> V_202 = 500 ;
return 0 ;
}
static int F_63 ( struct V_203 * V_204 ,
const struct V_205 * V_124 )
{
struct V_206 * V_31 = F_64 ( V_204 ) ;
char V_195 [ sizeof( L_45 ) ] ;
memset ( V_195 , 0 , sizeof( V_195 ) ) ;
F_62 ( V_31 , V_31 -> V_113 . V_196 ,
V_195 , sizeof( V_195 ) ) ;
if ( ( F_30 ( V_31 -> V_113 . V_114 ) == V_207 ) &&
( F_30 ( V_31 -> V_113 . V_116 ) == 0x0099 ) ) {
if ( ! strcmp ( L_45 , V_195 ) ) {
F_23 ( & V_31 -> V_32 , L_46 , V_62 ) ;
return - V_111 ;
}
}
return F_65 ( V_204 , V_124 ) ;
}
