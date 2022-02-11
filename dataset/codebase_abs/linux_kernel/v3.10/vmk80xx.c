static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_5 ;
unsigned int V_6 ;
unsigned char V_7 [ 1 ] ;
unsigned char V_8 [ 2 ] ;
V_5 = F_2 ( V_4 , 0x01 ) ;
V_6 = F_3 ( V_4 , 0x81 ) ;
V_7 [ 0 ] = V_9 ;
F_4 ( V_4 , V_5 , V_7 , 1 , NULL , V_2 -> V_10 -> V_11 ) ;
F_4 ( V_4 , V_6 , V_8 , 2 , NULL , V_12 * 10 ) ;
return ( int ) V_8 [ 1 ] ;
}
static void F_5 ( struct V_1 * V_2 , int V_13 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_5 ;
unsigned int V_6 ;
unsigned char V_7 [ 1 ] ;
unsigned char V_8 [ 64 ] ;
int V_14 ;
V_5 = F_2 ( V_4 , 0x01 ) ;
V_6 = F_3 ( V_4 , 0x81 ) ;
V_7 [ 0 ] = V_15 ;
F_4 ( V_4 , V_5 , V_7 , 1 , NULL , V_2 -> V_10 -> V_11 ) ;
F_4 ( V_4 , V_6 , V_8 , 64 , & V_14 , V_12 * 10 ) ;
V_8 [ V_14 ] = '\0' ;
if ( V_13 & V_16 )
strncpy ( V_2 -> V_17 . V_18 , V_8 + 1 , 24 ) ;
else
strncpy ( V_2 -> V_17 . V_19 , V_8 + 25 , 24 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_20 ;
T_1 V_21 ;
unsigned int V_5 ;
unsigned int V_6 ;
T_2 V_22 ;
V_20 = V_2 -> V_10 -> V_23 ;
V_21 = V_2 -> V_24 -> V_23 ;
V_5 = F_2 ( V_4 , V_20 ) ;
V_6 = F_3 ( V_4 , V_21 ) ;
V_22 = F_7 ( V_2 -> V_10 -> V_25 ) ;
F_4 ( V_4 , V_5 , V_2 -> V_26 ,
V_22 , NULL , V_2 -> V_10 -> V_11 ) ;
F_4 ( V_4 , V_6 , V_2 -> V_27 , V_22 , NULL , V_12 * 10 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_28 * V_29 ;
unsigned int V_30 ;
if ( ! V_2 -> V_31 )
return - V_32 ;
if ( V_2 -> V_33 == V_34 ) {
F_6 ( V_2 ) ;
return 0 ;
}
V_4 = V_2 -> V_4 ;
V_29 = V_2 -> V_24 ;
V_30 = F_9 ( V_4 , V_29 -> V_23 ) ;
return F_10 ( V_4 , V_30 , V_2 -> V_27 ,
F_7 ( V_29 -> V_25 ) , NULL ,
V_12 * 10 ) ;
}
static int F_11 ( struct V_1 * V_2 , int V_35 )
{
struct V_3 * V_4 ;
struct V_28 * V_29 ;
unsigned int V_30 ;
if ( ! V_2 -> V_31 )
return - V_32 ;
V_2 -> V_26 [ 0 ] = V_35 ;
if ( V_2 -> V_33 == V_34 ) {
F_6 ( V_2 ) ;
return 0 ;
}
V_4 = V_2 -> V_4 ;
V_29 = V_2 -> V_10 ;
V_30 = F_12 ( V_4 , V_29 -> V_23 ) ;
return F_10 ( V_4 , V_30 , V_2 -> V_26 ,
F_7 ( V_29 -> V_25 ) , NULL ,
V_12 * 10 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
T_2 V_22 ;
int V_36 ;
V_22 = F_7 ( V_2 -> V_10 -> V_25 ) ;
memset ( V_2 -> V_26 , 0 , V_22 ) ;
V_36 = F_11 ( V_2 , V_37 ) ;
if ( V_36 )
return V_36 ;
return F_11 ( V_2 , V_38 ) ;
}
static int F_14 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
struct V_43 * V_44 ,
unsigned int * V_45 )
{
struct V_1 * V_2 = V_40 -> V_46 ;
int V_47 ;
int V_48 [ 2 ] ;
int V_49 ;
F_15 ( & V_2 -> V_50 ) ;
V_47 = F_16 ( V_44 -> V_51 ) ;
switch ( V_2 -> V_33 ) {
case V_52 :
if ( ! V_47 )
V_48 [ 0 ] = V_53 ;
else
V_48 [ 0 ] = V_54 ;
break;
case V_34 :
default:
V_48 [ 0 ] = V_55 ;
V_48 [ 1 ] = V_56 ;
V_2 -> V_26 [ 0 ] = V_57 ;
V_2 -> V_26 [ V_58 ] = V_47 ;
break;
}
for ( V_49 = 0 ; V_49 < V_44 -> V_49 ; V_49 ++ ) {
if ( F_8 ( V_2 ) )
break;
if ( V_2 -> V_33 == V_52 ) {
V_45 [ V_49 ] = V_2 -> V_27 [ V_48 [ 0 ] ] ;
continue;
}
V_45 [ V_49 ] = V_2 -> V_27 [ V_48 [ 0 ] ] + 256 *
V_2 -> V_27 [ V_48 [ 1 ] ] ;
}
F_17 ( & V_2 -> V_50 ) ;
return V_49 ;
}
static int F_18 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
struct V_43 * V_44 ,
unsigned int * V_45 )
{
struct V_1 * V_2 = V_40 -> V_46 ;
int V_47 ;
int V_35 ;
int V_48 ;
int V_49 ;
F_15 ( & V_2 -> V_50 ) ;
V_47 = F_16 ( V_44 -> V_51 ) ;
switch ( V_2 -> V_33 ) {
case V_52 :
V_35 = V_38 ;
if ( ! V_47 )
V_48 = V_59 ;
else
V_48 = V_60 ;
break;
default:
V_35 = V_61 ;
V_48 = V_62 ;
V_2 -> V_26 [ V_58 ] = V_47 ;
break;
}
for ( V_49 = 0 ; V_49 < V_44 -> V_49 ; V_49 ++ ) {
V_2 -> V_26 [ V_48 ] = V_45 [ V_49 ] ;
if ( F_11 ( V_2 , V_35 ) )
break;
}
F_17 ( & V_2 -> V_50 ) ;
return V_49 ;
}
static int F_19 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
struct V_43 * V_44 ,
unsigned int * V_45 )
{
struct V_1 * V_2 = V_40 -> V_46 ;
int V_47 ;
int V_48 ;
int V_49 ;
F_15 ( & V_2 -> V_50 ) ;
V_47 = F_16 ( V_44 -> V_51 ) ;
V_48 = V_62 - 1 ;
V_2 -> V_26 [ 0 ] = V_63 ;
for ( V_49 = 0 ; V_49 < V_44 -> V_49 ; V_49 ++ ) {
if ( F_8 ( V_2 ) )
break;
V_45 [ V_49 ] = V_2 -> V_27 [ V_48 + V_47 ] ;
}
F_17 ( & V_2 -> V_50 ) ;
return V_49 ;
}
static int F_20 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
struct V_43 * V_44 ,
unsigned int * V_45 )
{
struct V_1 * V_2 = V_40 -> V_46 ;
unsigned char * V_64 ;
int V_48 ;
int V_36 ;
F_15 ( & V_2 -> V_50 ) ;
V_64 = V_2 -> V_27 ;
if ( V_2 -> V_33 == V_34 ) {
V_48 = V_65 ;
V_2 -> V_26 [ 0 ] = V_66 ;
} else {
V_48 = V_67 ;
}
V_36 = F_8 ( V_2 ) ;
if ( ! V_36 ) {
if ( V_2 -> V_33 == V_52 )
V_45 [ 1 ] = ( ( ( V_64 [ V_48 ] >> 4 ) & 0x03 ) |
( ( V_64 [ V_48 ] << 2 ) & 0x04 ) |
( ( V_64 [ V_48 ] >> 3 ) & 0x18 ) ) ;
else
V_45 [ 1 ] = V_64 [ V_48 ] ;
V_36 = 2 ;
}
F_17 ( & V_2 -> V_50 ) ;
return V_36 ;
}
static int F_21 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
struct V_43 * V_44 ,
unsigned int * V_45 )
{
struct V_1 * V_2 = V_40 -> V_46 ;
unsigned char * V_64 , * V_68 ;
int V_48 , V_35 ;
int V_36 ;
if ( V_2 -> V_33 == V_34 ) {
V_48 = V_69 ;
V_35 = V_70 ;
} else {
V_48 = V_71 ;
V_35 = V_38 ;
}
F_15 ( & V_2 -> V_50 ) ;
V_64 = V_2 -> V_27 ;
V_68 = V_2 -> V_26 ;
if ( V_45 [ 0 ] ) {
V_68 [ V_48 ] &= ~ V_45 [ 0 ] ;
V_68 [ V_48 ] |= ( V_45 [ 0 ] & V_45 [ 1 ] ) ;
V_36 = F_11 ( V_2 , V_35 ) ;
if ( V_36 )
goto V_72;
}
if ( V_2 -> V_33 == V_34 ) {
V_68 [ 0 ] = V_73 ;
V_36 = F_8 ( V_2 ) ;
if ( ! V_36 ) {
V_45 [ 1 ] = V_64 [ V_48 ] ;
V_36 = 2 ;
}
} else {
V_45 [ 1 ] = V_68 [ V_48 ] ;
V_36 = 2 ;
}
V_72:
F_17 ( & V_2 -> V_50 ) ;
return V_36 ;
}
static int F_22 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
struct V_43 * V_44 ,
unsigned int * V_45 )
{
struct V_1 * V_2 = V_40 -> V_46 ;
int V_47 ;
int V_48 [ 2 ] ;
int V_49 ;
F_15 ( & V_2 -> V_50 ) ;
V_47 = F_16 ( V_44 -> V_51 ) ;
switch ( V_2 -> V_33 ) {
case V_52 :
if ( ! V_47 )
V_48 [ 0 ] = V_74 ;
else
V_48 [ 0 ] = V_75 ;
break;
case V_34 :
default:
V_48 [ 0 ] = V_76 ;
V_48 [ 1 ] = V_76 ;
V_2 -> V_26 [ 0 ] = V_77 ;
break;
}
for ( V_49 = 0 ; V_49 < V_44 -> V_49 ; V_49 ++ ) {
if ( F_8 ( V_2 ) )
break;
if ( V_2 -> V_33 == V_52 )
V_45 [ V_49 ] = V_2 -> V_27 [ V_48 [ 0 ] ] ;
else
V_45 [ V_49 ] = V_2 -> V_27 [ V_48 [ 0 ] * ( V_47 + 1 ) + 1 ]
+ 256 * V_2 -> V_27 [ V_48 [ 1 ] * 2 + 2 ] ;
}
F_17 ( & V_2 -> V_50 ) ;
return V_49 ;
}
static int F_23 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
struct V_43 * V_44 ,
unsigned int * V_45 )
{
struct V_1 * V_2 = V_40 -> V_46 ;
unsigned int V_78 ;
int V_47 ;
int V_35 ;
int V_48 ;
int V_49 ;
V_78 = V_45 [ 0 ] ;
if ( V_78 != V_79 && V_78 != V_80 )
return - V_81 ;
F_15 ( & V_2 -> V_50 ) ;
V_47 = F_16 ( V_44 -> V_51 ) ;
if ( V_2 -> V_33 == V_52 ) {
if ( ! V_47 ) {
V_35 = V_82 ;
V_48 = V_74 ;
} else {
V_35 = V_83 ;
V_48 = V_75 ;
}
V_2 -> V_26 [ V_48 ] = 0x00 ;
} else {
V_35 = V_84 ;
}
for ( V_49 = 0 ; V_49 < V_44 -> V_49 ; V_49 ++ )
if ( F_11 ( V_2 , V_35 ) )
break;
F_17 ( & V_2 -> V_50 ) ;
return V_49 ;
}
static int F_24 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
struct V_43 * V_44 ,
unsigned int * V_45 )
{
struct V_1 * V_2 = V_40 -> V_46 ;
unsigned long V_85 ;
unsigned long V_86 ;
int V_47 ;
int V_35 ;
int V_49 ;
F_15 ( & V_2 -> V_50 ) ;
V_47 = F_16 ( V_44 -> V_51 ) ;
if ( ! V_47 )
V_35 = V_87 ;
else
V_35 = V_88 ;
for ( V_49 = 0 ; V_49 < V_44 -> V_49 ; V_49 ++ ) {
V_85 = V_45 [ V_49 ] ;
if ( V_85 == 0 )
V_85 = 1 ;
if ( V_85 > 7450 )
V_85 = 7450 ;
V_86 = F_25 ( V_85 * 1000 / 115 ) ;
if ( ( ( V_86 + 1 ) * V_86 ) < V_85 * 1000 / 115 )
V_86 += 1 ;
V_2 -> V_26 [ 6 + V_47 ] = V_86 ;
if ( F_11 ( V_2 , V_35 ) )
break;
}
F_17 ( & V_2 -> V_50 ) ;
return V_49 ;
}
static int F_26 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
struct V_43 * V_44 ,
unsigned int * V_45 )
{
struct V_1 * V_2 = V_40 -> V_46 ;
unsigned char * V_68 ;
unsigned char * V_64 ;
int V_48 [ 2 ] ;
int V_49 ;
F_15 ( & V_2 -> V_50 ) ;
V_68 = V_2 -> V_26 ;
V_64 = V_2 -> V_27 ;
V_48 [ 0 ] = V_89 ;
V_48 [ 1 ] = V_90 ;
V_68 [ 0 ] = V_91 ;
for ( V_49 = 0 ; V_49 < V_44 -> V_49 ; V_49 ++ ) {
if ( F_8 ( V_2 ) )
break;
V_45 [ V_49 ] = V_64 [ V_48 [ 0 ] ] + 4 * V_64 [ V_48 [ 1 ] ] ;
}
F_17 ( & V_2 -> V_50 ) ;
return V_49 ;
}
static int F_27 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
struct V_43 * V_44 ,
unsigned int * V_45 )
{
struct V_1 * V_2 = V_40 -> V_46 ;
unsigned char * V_68 ;
int V_48 [ 2 ] ;
int V_35 ;
int V_49 ;
F_15 ( & V_2 -> V_50 ) ;
V_68 = V_2 -> V_26 ;
V_48 [ 0 ] = V_89 ;
V_48 [ 1 ] = V_90 ;
V_35 = V_92 ;
for ( V_49 = 0 ; V_49 < V_44 -> V_49 ; V_49 ++ ) {
V_68 [ V_48 [ 0 ] ] = ( unsigned char ) ( V_45 [ V_49 ] & 0x03 ) ;
V_68 [ V_48 [ 1 ] ] = ( unsigned char ) ( V_45 [ V_49 ] >> 2 ) & 0xff ;
if ( F_11 ( V_2 , V_35 ) )
break;
}
F_17 ( & V_2 -> V_50 ) ;
return V_49 ;
}
static int F_28 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_46 ;
struct V_93 * V_31 = V_2 -> V_31 ;
struct V_94 * V_95 = V_31 -> V_96 ;
struct V_28 * V_97 ;
int V_98 ;
if ( V_95 -> V_99 . V_100 != 2 )
return - V_32 ;
for ( V_98 = 0 ; V_98 < V_95 -> V_99 . V_100 ; V_98 ++ ) {
V_97 = & V_95 -> V_101 [ V_98 ] . V_99 ;
if ( F_29 ( V_97 ) ||
F_30 ( V_97 ) ) {
if ( ! V_2 -> V_24 )
V_2 -> V_24 = V_97 ;
continue;
}
if ( F_31 ( V_97 ) ||
F_32 ( V_97 ) ) {
if ( ! V_2 -> V_10 )
V_2 -> V_10 = V_97 ;
continue;
}
}
if ( ! V_2 -> V_24 || ! V_2 -> V_10 )
return - V_32 ;
return 0 ;
}
static int F_33 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_46 ;
T_2 V_22 ;
V_22 = F_7 ( V_2 -> V_24 -> V_25 ) ;
V_2 -> V_27 = F_34 ( V_22 , V_102 ) ;
if ( ! V_2 -> V_27 )
return - V_103 ;
V_22 = F_7 ( V_2 -> V_10 -> V_25 ) ;
V_2 -> V_26 = F_34 ( V_22 , V_102 ) ;
if ( ! V_2 -> V_26 ) {
F_35 ( V_2 -> V_27 ) ;
return - V_103 ;
}
return 0 ;
}
static int F_36 ( struct V_39 * V_40 )
{
const struct V_104 * V_105 = F_37 ( V_40 ) ;
struct V_1 * V_2 = V_40 -> V_46 ;
struct V_41 * V_42 ;
int V_106 ;
int V_107 ;
F_15 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_33 == V_52 )
V_106 = 5 ;
else
V_106 = 6 ;
V_107 = F_38 ( V_40 , V_106 ) ;
if ( V_107 ) {
F_17 ( & V_2 -> V_50 ) ;
return V_107 ;
}
V_42 = & V_40 -> V_108 [ 0 ] ;
V_42 -> type = V_109 ;
V_42 -> V_110 = V_111 | V_112 ;
V_42 -> V_113 = V_105 -> V_114 ;
V_42 -> V_115 = V_105 -> V_116 ;
V_42 -> V_117 = V_105 -> V_118 ;
V_42 -> V_119 = F_14 ;
V_42 = & V_40 -> V_108 [ 1 ] ;
V_42 -> type = V_120 ;
V_42 -> V_110 = V_121 | V_112 ;
V_42 -> V_113 = V_105 -> V_122 ;
V_42 -> V_115 = 0x00ff ;
V_42 -> V_117 = V_105 -> V_118 ;
V_42 -> V_123 = F_18 ;
if ( V_2 -> V_33 == V_34 ) {
V_42 -> V_110 |= V_111 ;
V_42 -> V_119 = F_19 ;
}
V_42 = & V_40 -> V_108 [ 2 ] ;
V_42 -> type = V_124 ;
V_42 -> V_110 = V_111 ;
V_42 -> V_113 = V_105 -> V_125 ;
V_42 -> V_115 = 1 ;
V_42 -> V_117 = & V_126 ;
V_42 -> V_127 = F_20 ;
V_42 = & V_40 -> V_108 [ 3 ] ;
V_42 -> type = V_128 ;
V_42 -> V_110 = V_121 ;
V_42 -> V_113 = 8 ;
V_42 -> V_115 = 1 ;
V_42 -> V_117 = & V_126 ;
V_42 -> V_127 = F_21 ;
V_42 = & V_40 -> V_108 [ 4 ] ;
V_42 -> type = V_129 ;
V_42 -> V_110 = V_111 ;
V_42 -> V_113 = 2 ;
V_42 -> V_115 = V_105 -> V_130 ;
V_42 -> V_119 = F_22 ;
V_42 -> V_131 = F_23 ;
if ( V_2 -> V_33 == V_52 ) {
V_42 -> V_110 |= V_121 ;
V_42 -> V_123 = F_24 ;
}
if ( V_2 -> V_33 == V_34 ) {
V_42 = & V_40 -> V_108 [ 5 ] ;
V_42 -> type = V_132 ;
V_42 -> V_110 = V_111 | V_121 ;
V_42 -> V_113 = V_105 -> V_133 ;
V_42 -> V_115 = V_105 -> V_134 ;
V_42 -> V_119 = F_26 ;
V_42 -> V_123 = F_27 ;
}
F_17 ( & V_2 -> V_50 ) ;
return 0 ;
}
static int F_39 ( struct V_39 * V_40 ,
unsigned long V_135 )
{
struct V_93 * V_31 = F_40 ( V_40 ) ;
const struct V_104 * V_105 ;
struct V_1 * V_2 ;
int V_107 ;
V_105 = & V_136 [ V_135 ] ;
V_40 -> V_137 = V_105 ;
V_40 -> V_138 = V_105 -> V_139 ;
V_2 = F_34 ( sizeof( * V_2 ) , V_102 ) ;
if ( ! V_2 )
return - V_103 ;
V_40 -> V_46 = V_2 ;
V_2 -> V_4 = F_41 ( V_31 ) ;
V_2 -> V_31 = V_31 ;
V_2 -> V_33 = V_105 -> V_33 ;
V_107 = F_28 ( V_40 ) ;
if ( V_107 )
return V_107 ;
V_107 = F_33 ( V_40 ) ;
if ( V_107 )
return V_107 ;
F_42 ( & V_2 -> V_50 , 8 ) ;
F_43 ( V_31 , V_2 ) ;
if ( V_2 -> V_33 == V_34 ) {
F_5 ( V_2 , V_16 ) ;
F_44 ( & V_31 -> V_40 , L_1 , V_2 -> V_17 . V_18 ) ;
if ( F_1 ( V_2 ) ) {
F_5 ( V_2 , V_140 ) ;
F_44 ( & V_31 -> V_40 , L_1 , V_2 -> V_17 . V_19 ) ;
}
}
if ( V_2 -> V_33 == V_52 )
F_13 ( V_2 ) ;
return F_36 ( V_40 ) ;
}
static void F_45 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_46 ;
if ( ! V_2 )
return;
F_15 ( & V_2 -> V_50 ) ;
F_43 ( V_2 -> V_31 , NULL ) ;
F_35 ( V_2 -> V_27 ) ;
F_35 ( V_2 -> V_26 ) ;
F_17 ( & V_2 -> V_50 ) ;
}
static int F_46 ( struct V_93 * V_31 ,
const struct V_141 * V_142 )
{
return F_47 ( V_31 , & V_143 , V_142 -> V_144 ) ;
}
