static T_1 F_1 ( const struct V_1 * V_2 ,
T_2 V_3 , T_2 V_4 , T_2 * V_5 )
{
T_1 V_6 , V_7 ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) {
V_7 = F_2 ( V_2 , V_3 + V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
V_5 [ V_6 ] = V_7 ;
}
return V_6 ;
}
static T_1 F_3 ( const struct V_1 * V_2 , T_2 V_3 ,
T_2 V_4 , T_2 * V_5 )
{
T_2 V_8 [ 255 ] ;
T_1 V_9 ;
int V_10 = 0 ;
F_4 ( & V_2 -> V_11 , L_1 , V_4 ) ;
V_9 = F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
if ( V_9 < 0 )
return V_9 ;
do {
if ( ++ V_10 > V_12 ) {
F_5 ( & V_2 -> V_11 ,
L_2 ) ;
return - V_13 ;
}
memcpy ( V_8 , V_5 , V_4 ) ;
V_9 = F_1 ( V_2 , V_3 , V_4 ,
V_5 ) ;
if ( V_9 < 0 )
return V_9 ;
} while ( memcmp ( V_8 , V_5 , V_4 ) );
return V_4 ;
}
static T_1 F_6 ( const struct V_1 * V_2 , T_2 V_3 ,
T_2 V_4 , const T_2 * V_5 )
{
T_2 V_14 [ 255 ] ;
int V_10 = 0 ;
F_4 ( & V_2 -> V_11 , L_3 , V_4 ) ;
do {
T_1 V_6 , V_9 ;
if ( ++ V_10 > V_12 ) {
F_5 ( & V_2 -> V_11 ,
L_4 ) ;
return - V_13 ;
}
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) {
V_9 = F_7 ( V_2 , V_3 + V_6 ,
V_5 [ V_6 ] ) ;
if ( V_9 < 0 )
return V_9 ;
}
V_9 = F_1 ( V_2 , V_3 , V_4 ,
V_14 ) ;
if ( V_9 < 0 )
return V_9 ;
} while ( memcmp ( V_14 , V_5 , V_4 ) );
return V_4 ;
}
static T_1 F_8 ( const struct V_1 * V_2 ,
T_2 V_3 , T_2 V_4 , const T_2 * V_5 )
{
T_2 V_15 = 0 ;
if ( V_4 <= V_16 )
return F_9 ( V_2 ,
V_3 , V_4 , V_5 ) ;
while ( V_15 < V_4 ) {
T_1 V_17 = F_9 ( V_2 ,
V_3 + V_15 ,
F_10 ( V_16 , V_4 - V_15 ) ,
V_5 + V_15 ) ;
if ( V_17 < 0 )
return V_17 ;
V_15 += V_16 ;
}
return V_4 ;
}
static T_1 F_11 ( const struct V_1 * V_2 ,
T_2 V_3 , T_2 V_4 , T_2 * V_5 )
{
T_2 V_15 = 0 ;
if ( V_4 <= V_16 )
return F_12 ( V_2 ,
V_3 , V_4 , V_5 ) ;
while ( V_15 < V_4 ) {
T_1 V_17 = F_12 ( V_2 ,
V_3 + V_15 ,
F_10 ( V_16 , V_4 - V_15 ) ,
V_5 + V_15 ) ;
if ( V_17 < 0 )
return V_17 ;
V_15 += V_16 ;
}
return V_4 ;
}
static void F_13 ( struct V_18 * V_19 )
{
struct V_20 * V_20 ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
int V_23 , V_24 ;
V_20 = F_14 ( V_19 , struct V_20 , V_19 ) ;
V_2 = V_20 -> V_2 ;
V_22 = & V_20 -> V_25 -> V_26 ;
F_15 ( V_22 ) ;
V_23 = F_2 ( V_2 , V_27 ) ;
if ( V_23 < 0 )
goto V_28;
if ( V_23 & V_29 ) {
V_23 &= ~ V_29 ;
F_7 ( V_2 , V_27 , V_23 ) ;
V_24 = F_2 ( V_2 , V_30 ) ;
if ( V_24 < 0 )
goto V_28;
V_24 &= ~ V_31 ;
F_7 ( V_2 , V_30 , V_24 ) ;
F_16 ( V_20 -> V_25 , 1 , V_32 | V_33 ) ;
}
V_28:
if ( F_17 ( V_34 , & V_20 -> V_35 ) )
F_18 ( V_2 -> V_36 ) ;
F_19 ( V_22 ) ;
}
static T_3 F_20 ( int V_36 , void * V_37 )
{
struct V_1 * V_2 = V_37 ;
struct V_20 * V_20 = F_21 ( V_2 ) ;
F_22 ( V_36 ) ;
F_23 ( & V_20 -> V_19 ) ;
return V_38 ;
}
static int F_24 ( struct V_39 * V_11 , struct V_40 * V_41 )
{
struct V_20 * V_20 = F_25 ( V_11 ) ;
int V_42 ;
V_42 = V_20 -> V_43 ( V_20 -> V_2 ,
V_20 -> V_44 , 7 , V_20 -> V_45 ) ;
if ( V_42 != 7 ) {
F_5 ( V_11 , L_5 , L_6 , V_42 ) ;
return - V_13 ;
}
F_4 ( V_11 , L_7 , L_6 , V_20 -> V_45 ) ;
V_41 -> V_46 = F_26 ( V_20 -> V_45 [ V_47 ] & 0x7f ) ;
V_41 -> V_48 = F_26 ( V_20 -> V_45 [ V_49 ] & 0x7f ) ;
V_42 = V_20 -> V_45 [ V_50 ] & 0x3f ;
V_41 -> V_51 = F_26 ( V_42 ) ;
V_41 -> V_52 = F_26 ( V_20 -> V_45 [ V_53 ] & 0x07 ) - 1 ;
V_41 -> V_54 = F_26 ( V_20 -> V_45 [ V_55 ] & 0x3f ) ;
V_42 = V_20 -> V_45 [ V_56 ] & 0x1f ;
V_41 -> V_57 = F_26 ( V_42 ) - 1 ;
V_41 -> V_58 = F_26 ( V_20 -> V_45 [ V_59 ] ) + 100 ;
F_4 ( V_11 , L_8
L_9 ,
L_6 , V_41 -> V_46 , V_41 -> V_48 ,
V_41 -> V_51 , V_41 -> V_54 ,
V_41 -> V_57 , V_41 -> V_58 , V_41 -> V_52 ) ;
return F_27 ( V_41 ) ;
}
static int F_28 ( struct V_39 * V_11 , struct V_40 * V_41 )
{
struct V_20 * V_20 = F_25 ( V_11 ) ;
int V_60 ;
int V_42 ;
T_2 * V_61 = V_20 -> V_45 ;
F_4 ( V_11 , L_8
L_9 ,
L_10 , V_41 -> V_46 , V_41 -> V_48 ,
V_41 -> V_51 , V_41 -> V_54 ,
V_41 -> V_57 , V_41 -> V_58 , V_41 -> V_52 ) ;
V_61 [ V_47 ] = F_29 ( V_41 -> V_46 ) ;
V_61 [ V_49 ] = F_29 ( V_41 -> V_48 ) ;
V_61 [ V_50 ] = F_29 ( V_41 -> V_51 ) ;
V_61 [ V_53 ] = F_29 ( V_41 -> V_52 + 1 ) ;
V_61 [ V_55 ] = F_29 ( V_41 -> V_54 ) ;
V_61 [ V_56 ] = F_29 ( V_41 -> V_57 + 1 ) ;
V_42 = V_41 -> V_58 - 100 ;
V_61 [ V_59 ] = F_29 ( V_42 ) ;
switch ( V_20 -> type ) {
case V_62 :
case V_63 :
case V_64 :
V_61 [ V_56 ] |= V_65 ;
break;
case V_66 :
V_61 [ V_50 ] |= V_67
| V_68 ;
break;
case V_69 :
V_61 [ V_47 ] |= V_70 ;
V_61 [ V_53 ] |= V_71 ;
break;
default:
break;
}
F_4 ( V_11 , L_7 , L_10 , V_61 ) ;
V_60 = V_20 -> V_72 ( V_20 -> V_2 ,
V_20 -> V_44 , 7 , V_61 ) ;
if ( V_60 < 0 ) {
F_5 ( V_11 , L_5 , L_10 , V_60 ) ;
return V_60 ;
}
return 0 ;
}
static int F_30 ( struct V_39 * V_11 , struct V_73 * V_41 )
{
struct V_1 * V_2 = F_31 ( V_11 ) ;
struct V_20 * V_20 = F_21 ( V_2 ) ;
int V_9 ;
if ( ! F_17 ( V_34 , & V_20 -> V_35 ) )
return - V_74 ;
V_9 = V_20 -> V_43 ( V_2 ,
V_75 , 9 , V_20 -> V_45 ) ;
if ( V_9 != 9 ) {
F_5 ( V_11 , L_5 , L_11 , V_9 ) ;
return - V_13 ;
}
F_4 ( V_11 , L_12 ,
L_11 ,
V_20 -> V_45 [ 0 ] , V_20 -> V_45 [ 1 ] ,
V_20 -> V_45 [ 2 ] , V_20 -> V_45 [ 3 ] ,
V_20 -> V_45 [ 4 ] , V_20 -> V_45 [ 5 ] ,
V_20 -> V_45 [ 6 ] , V_20 -> V_45 [ 7 ] ,
V_20 -> V_45 [ 8 ] ) ;
V_41 -> time . V_46 = F_26 ( V_20 -> V_45 [ 0 ] & 0x7f ) ;
V_41 -> time . V_48 = F_26 ( V_20 -> V_45 [ 1 ] & 0x7f ) ;
V_41 -> time . V_51 = F_26 ( V_20 -> V_45 [ 2 ] & 0x3f ) ;
V_41 -> time . V_54 = F_26 ( V_20 -> V_45 [ 3 ] & 0x3f ) ;
V_41 -> time . V_57 = - 1 ;
V_41 -> time . V_58 = - 1 ;
V_41 -> time . V_52 = - 1 ;
V_41 -> time . V_76 = - 1 ;
V_41 -> time . V_77 = - 1 ;
V_41 -> V_78 = ! ! ( V_20 -> V_45 [ 7 ] & V_31 ) ;
V_41 -> V_79 = ! ! ( V_20 -> V_45 [ 8 ] & V_29 ) ;
F_4 ( V_11 , L_8
L_13 ,
L_11 , V_41 -> time . V_46 , V_41 -> time . V_48 ,
V_41 -> time . V_51 , V_41 -> time . V_54 ,
V_41 -> V_78 , V_41 -> V_79 ) ;
return 0 ;
}
static int F_32 ( struct V_39 * V_11 , struct V_73 * V_41 )
{
struct V_1 * V_2 = F_31 ( V_11 ) ;
struct V_20 * V_20 = F_21 ( V_2 ) ;
unsigned char * V_61 = V_20 -> V_45 ;
T_2 V_24 , V_80 ;
int V_9 ;
if ( ! F_17 ( V_34 , & V_20 -> V_35 ) )
return - V_74 ;
F_4 ( V_11 , L_8
L_13 ,
L_14 , V_41 -> time . V_46 , V_41 -> time . V_48 ,
V_41 -> time . V_51 , V_41 -> time . V_54 ,
V_41 -> V_78 , V_41 -> V_79 ) ;
V_9 = V_20 -> V_43 ( V_2 ,
V_75 , 9 , V_61 ) ;
if ( V_9 != 9 ) {
F_5 ( V_11 , L_5 , L_15 , V_9 ) ;
return - V_13 ;
}
V_24 = V_20 -> V_45 [ 7 ] ;
V_80 = V_20 -> V_45 [ 8 ] ;
F_4 ( V_11 , L_12 ,
L_16 ,
V_20 -> V_45 [ 0 ] , V_20 -> V_45 [ 1 ] ,
V_20 -> V_45 [ 2 ] , V_20 -> V_45 [ 3 ] ,
V_20 -> V_45 [ 4 ] , V_20 -> V_45 [ 5 ] ,
V_20 -> V_45 [ 6 ] , V_24 , V_80 ) ;
V_61 [ 0 ] = F_29 ( V_41 -> time . V_46 ) ;
V_61 [ 1 ] = F_29 ( V_41 -> time . V_48 ) ;
V_61 [ 2 ] = F_29 ( V_41 -> time . V_51 ) ;
V_61 [ 3 ] = F_29 ( V_41 -> time . V_54 ) ;
V_61 [ 4 ] = 0 ;
V_61 [ 5 ] = 0 ;
V_61 [ 6 ] = 0 ;
V_61 [ 7 ] = V_24 & ~ ( V_31 | V_81 ) ;
if ( V_41 -> V_78 ) {
F_4 ( V_11 , L_17 ) ;
V_61 [ 7 ] |= V_31 ;
}
V_61 [ 8 ] = V_80 & ~ ( V_29 | V_82 ) ;
V_9 = V_20 -> V_72 ( V_2 ,
V_75 , 9 , V_61 ) ;
if ( V_9 < 0 ) {
F_5 ( V_11 , L_18 ) ;
return V_9 ;
}
return 0 ;
}
static int F_33 ( struct V_39 * V_11 , unsigned int V_78 )
{
struct V_1 * V_2 = F_31 ( V_11 ) ;
struct V_20 * V_20 = F_21 ( V_2 ) ;
int V_9 ;
if ( ! F_17 ( V_34 , & V_20 -> V_35 ) )
return - V_83 ;
V_9 = F_2 ( V_2 , V_30 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_78 )
V_9 |= V_31 ;
else
V_9 &= ~ V_31 ;
V_9 = F_7 ( V_2 , V_30 , V_9 ) ;
if ( V_9 < 0 )
return V_9 ;
return 0 ;
}
static T_4
F_34 ( struct V_84 * V_85 , struct V_86 * V_87 ,
struct V_88 * V_89 ,
char * V_61 , T_5 V_90 , T_6 V_91 )
{
struct V_1 * V_2 ;
struct V_20 * V_20 ;
int V_60 ;
V_2 = F_35 ( V_87 ) ;
V_20 = F_21 ( V_2 ) ;
if ( F_36 ( V_90 >= V_20 -> V_92 -> V_93 ) )
return 0 ;
if ( ( V_90 + V_91 ) > V_20 -> V_92 -> V_93 )
V_91 = V_20 -> V_92 -> V_93 - V_90 ;
if ( F_36 ( ! V_91 ) )
return V_91 ;
V_60 = V_20 -> V_43 ( V_2 , V_20 -> V_94 + V_90 ,
V_91 , V_61 ) ;
if ( V_60 < 0 )
F_5 ( & V_2 -> V_11 , L_5 , L_19 , V_60 ) ;
return V_60 ;
}
static T_4
F_37 ( struct V_84 * V_85 , struct V_86 * V_87 ,
struct V_88 * V_89 ,
char * V_61 , T_5 V_90 , T_6 V_91 )
{
struct V_1 * V_2 ;
struct V_20 * V_20 ;
int V_60 ;
V_2 = F_35 ( V_87 ) ;
V_20 = F_21 ( V_2 ) ;
if ( F_36 ( V_90 >= V_20 -> V_92 -> V_93 ) )
return - V_95 ;
if ( ( V_90 + V_91 ) > V_20 -> V_92 -> V_93 )
V_91 = V_20 -> V_92 -> V_93 - V_90 ;
if ( F_36 ( ! V_91 ) )
return V_91 ;
V_60 = V_20 -> V_72 ( V_2 , V_20 -> V_94 + V_90 ,
V_91 , V_61 ) ;
if ( V_60 < 0 ) {
F_5 ( & V_2 -> V_11 , L_5 , L_20 , V_60 ) ;
return V_60 ;
}
return V_91 ;
}
static int F_38 ( struct V_1 * V_2 ,
const struct V_96 * V_97 )
{
struct V_20 * V_20 ;
int V_98 = - V_99 ;
int V_42 ;
const struct V_100 * V_101 = & V_102 [ V_97 -> V_103 ] ;
struct V_104 * V_105 = F_39 ( V_2 -> V_11 . V_106 ) ;
int V_107 = false ;
unsigned char * V_61 ;
struct V_108 * V_109 = V_2 -> V_11 . V_110 ;
static const int V_111 [] = {
[ V_62 ] = 0 ,
[ V_63 ] = V_112 ,
[ V_64 ] = V_113 ,
} ;
if ( ! F_40 ( V_105 , V_114 )
&& ! F_40 ( V_105 , V_115 ) )
return - V_13 ;
V_20 = F_41 ( & V_2 -> V_11 , sizeof( struct V_20 ) , V_116 ) ;
if ( ! V_20 )
return - V_117 ;
F_42 ( V_2 , V_20 ) ;
V_20 -> V_2 = V_2 ;
V_20 -> type = V_97 -> V_103 ;
if ( V_109 && V_109 -> V_118 && V_101 -> V_119 )
F_7 ( V_2 , V_101 -> V_119 ,
V_120 | V_109 -> V_118 ) ;
V_61 = V_20 -> V_45 ;
if ( F_40 ( V_105 , V_115 ) ) {
V_20 -> V_43 = F_11 ;
V_20 -> V_72 = F_8 ;
} else {
V_20 -> V_43 = F_3 ;
V_20 -> V_72 = F_6 ;
}
switch ( V_20 -> type ) {
case V_62 :
case V_63 :
case V_64 :
V_42 = V_20 -> V_43 ( V_20 -> V_2 ,
V_30 , 2 , V_61 ) ;
if ( V_42 != 2 ) {
F_4 ( & V_2 -> V_11 , L_21 , V_42 ) ;
V_98 = - V_13 ;
goto exit;
}
if ( V_20 -> V_45 [ 0 ] & V_121 )
V_20 -> V_45 [ 0 ] &= ~ V_121 ;
if ( V_20 -> V_2 -> V_36 > 0 && V_101 -> V_122 ) {
F_43 ( & V_20 -> V_19 , F_13 ) ;
V_20 -> V_45 [ 0 ] |= V_123
| V_111 [ V_20 -> type ] ;
V_20 -> V_45 [ 0 ] &= ~ ( V_81 | V_31 ) ;
V_107 = true ;
}
F_7 ( V_2 , V_30 ,
V_20 -> V_45 [ 0 ] ) ;
if ( V_20 -> V_45 [ 1 ] & V_124 ) {
F_7 ( V_2 , V_27 ,
V_20 -> V_45 [ 1 ] & ~ V_124 ) ;
F_44 ( & V_2 -> V_11 , L_22 ) ;
}
break;
case V_125 :
V_42 = F_12 ( V_20 -> V_2 ,
V_126 << 4 | 0x08 , 2 , V_61 ) ;
if ( V_42 != 2 ) {
F_4 ( & V_2 -> V_11 , L_21 , V_42 ) ;
V_98 = - V_13 ;
goto exit;
}
if ( ! ( V_20 -> V_45 [ 1 ] & V_127 ) ) {
V_20 -> V_45 [ 1 ] |= V_127 ;
F_7 ( V_2 ,
V_128 << 4 | 0x08 ,
V_20 -> V_45 [ 1 ] ) ;
F_44 ( & V_2 -> V_11 ,
L_23 ) ;
}
if ( V_20 -> V_45 [ 1 ] & V_129 ) {
V_20 -> V_45 [ 1 ] &= ~ V_129 ;
F_7 ( V_2 ,
V_128 << 4 | 0x08 ,
V_20 -> V_45 [ 1 ] ) ;
F_44 ( & V_2 -> V_11 , L_24 ) ;
}
if ( V_20 -> V_45 [ 1 ] & V_130 ) {
V_20 -> V_45 [ 1 ] &= ~ V_130 ;
F_7 ( V_2 ,
V_128 << 4 | 0x08 ,
V_20 -> V_45 [ 1 ] ) ;
F_44 ( & V_2 -> V_11 , L_25 ) ;
}
if ( ! ( V_20 -> V_45 [ 0 ] & V_131 ) ) {
T_2 V_132 ;
F_7 ( V_2 ,
V_126 << 4 | 0x08 ,
V_20 -> V_45 [ 0 ] |
V_131 ) ;
V_42 = F_12 ( V_20 -> V_2 ,
V_126 << 4 | 0x08 , 2 , V_61 ) ;
if ( V_42 != 2 ) {
F_4 ( & V_2 -> V_11 , L_21 , V_42 ) ;
V_98 = - V_13 ;
goto exit;
}
V_132 = F_26 ( V_20 -> V_45 [ V_50 ] ) ;
if ( V_132 == 12 )
V_132 = 0 ;
if ( V_20 -> V_45 [ V_50 ] & V_133 )
V_132 += 12 ;
F_7 ( V_2 ,
V_50 << 4 | 0x08 ,
V_132 ) ;
}
break;
case V_134 :
V_20 -> V_44 = 1 ;
break;
default:
break;
}
V_135:
V_42 = V_20 -> V_43 ( V_20 -> V_2 , V_20 -> V_44 , 8 , V_61 ) ;
if ( V_42 != 8 ) {
F_4 ( & V_2 -> V_11 , L_21 , V_42 ) ;
V_98 = - V_13 ;
goto exit;
}
V_42 = V_20 -> V_45 [ V_47 ] ;
switch ( V_20 -> type ) {
case V_136 :
case V_137 :
if ( V_42 & V_138 ) {
F_7 ( V_2 , V_47 , 0 ) ;
F_44 ( & V_2 -> V_11 , L_22 ) ;
goto V_135;
}
break;
case V_139 :
if ( V_42 & V_138 )
F_7 ( V_2 , V_47 , 0 ) ;
if ( V_20 -> V_45 [ V_140 ] & V_141 ) {
F_7 ( V_2 , V_140 ,
V_20 -> V_45 [ V_140 ]
& ~ V_141 ) ;
F_44 ( & V_2 -> V_11 , L_22 ) ;
goto V_135;
}
break;
case V_66 :
if ( V_42 & V_142 )
F_7 ( V_2 , V_47 , 0 ) ;
V_42 = F_2 ( V_2 , V_143 ) ;
if ( V_42 < 0 ) {
F_4 ( & V_2 -> V_11 , L_21 , V_42 ) ;
V_98 = - V_13 ;
goto exit;
}
if ( V_42 & V_144 ) {
F_7 ( V_2 , V_143 , 0 ) ;
F_44 ( & V_2 -> V_11 , L_22 ) ;
}
break;
case V_69 :
if ( ! ( V_20 -> V_45 [ V_53 ] & V_71 ) ) {
F_7 ( V_2 , V_53 ,
V_20 -> V_45 [ V_53 ]
| V_71 ) ;
}
if ( ! ( V_42 & V_70 ) ) {
F_7 ( V_2 , V_47 ,
V_70 ) ;
F_44 ( & V_2 -> V_11 , L_22 ) ;
goto V_135;
}
break;
default:
break;
}
V_42 = V_20 -> V_45 [ V_50 ] ;
switch ( V_20 -> type ) {
case V_66 :
case V_137 :
break;
case V_125 :
break;
default:
if ( ! ( V_42 & V_145 ) )
break;
V_42 = F_26 ( V_42 & 0x1f ) ;
if ( V_42 == 12 )
V_42 = 0 ;
if ( V_20 -> V_45 [ V_50 ] & V_133 )
V_42 += 12 ;
F_7 ( V_2 ,
V_20 -> V_44 + V_50 ,
F_29 ( V_42 ) ) ;
}
V_20 -> V_25 = F_45 ( & V_2 -> V_11 , V_2 -> V_146 ,
& V_147 , V_148 ) ;
if ( F_46 ( V_20 -> V_25 ) ) {
V_98 = F_47 ( V_20 -> V_25 ) ;
F_5 ( & V_2 -> V_11 ,
L_26 ) ;
goto exit;
}
if ( V_107 ) {
V_98 = F_48 ( V_2 -> V_36 , F_20 , V_149 ,
V_20 -> V_25 -> V_146 , V_2 ) ;
if ( V_98 ) {
F_5 ( & V_2 -> V_11 ,
L_27 ) ;
goto exit;
}
F_49 ( & V_2 -> V_11 , 1 ) ;
F_50 ( V_34 , & V_20 -> V_35 ) ;
F_4 ( & V_2 -> V_11 , L_28 , V_2 -> V_36 ) ;
}
if ( V_101 -> V_150 ) {
V_20 -> V_92 = F_41 ( & V_2 -> V_11 ,
sizeof( struct V_88 ) ,
V_116 ) ;
if ( ! V_20 -> V_92 ) {
V_98 = - V_117 ;
goto exit;
}
V_20 -> V_92 -> V_89 . V_146 = L_29 ;
V_20 -> V_92 -> V_89 . V_151 = V_152 | V_153 ;
F_51 ( V_20 -> V_92 ) ;
V_20 -> V_92 -> V_154 = F_34 ;
V_20 -> V_92 -> V_155 = F_37 ;
V_20 -> V_92 -> V_93 = V_101 -> V_150 ;
V_20 -> V_94 = V_101 -> V_94 ;
V_98 = F_52 ( & V_2 -> V_11 . V_87 , V_20 -> V_92 ) ;
if ( V_98 )
goto exit;
F_50 ( V_156 , & V_20 -> V_35 ) ;
F_53 ( & V_2 -> V_11 , L_30 , V_20 -> V_92 -> V_93 ) ;
}
return 0 ;
exit:
return V_98 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_20 * V_20 = F_21 ( V_2 ) ;
if ( F_55 ( V_34 , & V_20 -> V_35 ) ) {
F_56 ( V_2 -> V_36 , V_2 ) ;
F_57 ( & V_20 -> V_19 ) ;
}
if ( F_55 ( V_156 , & V_20 -> V_35 ) )
F_58 ( & V_2 -> V_11 . V_87 , V_20 -> V_92 ) ;
return 0 ;
}
