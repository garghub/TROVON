static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned int V_8 ;
unsigned int V_9 ;
unsigned char V_10 [ 1 ] ;
unsigned char V_11 [ 2 ] ;
V_8 = F_3 ( V_7 , 0x01 ) ;
V_9 = F_4 ( V_7 , 0x81 ) ;
V_10 [ 0 ] = V_12 ;
F_5 ( V_7 , V_8 , V_10 , 1 , NULL , V_4 -> V_13 -> V_14 ) ;
F_5 ( V_7 , V_9 , V_11 , 2 , NULL , V_15 * 10 ) ;
return ( int ) V_11 [ 1 ] ;
}
static void F_6 ( struct V_1 * V_2 , int V_16 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned int V_8 ;
unsigned int V_9 ;
unsigned char V_10 [ 1 ] ;
unsigned char V_11 [ 64 ] ;
int V_17 ;
V_8 = F_3 ( V_7 , 0x01 ) ;
V_9 = F_4 ( V_7 , 0x81 ) ;
V_10 [ 0 ] = V_18 ;
F_5 ( V_7 , V_8 , V_10 , 1 , NULL , V_4 -> V_13 -> V_14 ) ;
F_5 ( V_7 , V_9 , V_11 , 64 , & V_17 , V_15 * 10 ) ;
V_11 [ V_17 ] = '\0' ;
if ( V_16 & V_19 )
strncpy ( V_4 -> V_20 . V_21 , V_11 + 1 , 24 ) ;
else
strncpy ( V_4 -> V_20 . V_22 , V_11 + 25 , 24 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_23 ;
T_1 V_24 ;
unsigned int V_8 ;
unsigned int V_9 ;
T_2 V_25 ;
V_23 = V_4 -> V_13 -> V_26 ;
V_24 = V_4 -> V_27 -> V_26 ;
V_8 = F_3 ( V_7 , V_23 ) ;
V_9 = F_4 ( V_7 , V_24 ) ;
V_25 = F_8 ( V_4 -> V_13 -> V_28 ) ;
F_5 ( V_7 , V_8 , V_4 -> V_29 ,
V_25 , NULL , V_4 -> V_13 -> V_14 ) ;
F_5 ( V_7 , V_9 , V_4 -> V_30 , V_25 , NULL , V_15 * 10 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_31 * V_32 ;
unsigned int V_33 ;
if ( V_4 -> V_34 == V_35 ) {
F_7 ( V_2 ) ;
return 0 ;
}
V_32 = V_4 -> V_27 ;
V_33 = F_10 ( V_7 , V_32 -> V_26 ) ;
return F_11 ( V_7 , V_33 , V_4 -> V_30 ,
F_8 ( V_32 -> V_28 ) , NULL ,
V_15 * 10 ) ;
}
static int F_12 ( struct V_1 * V_2 , int V_36 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_31 * V_32 ;
unsigned int V_33 ;
V_4 -> V_29 [ 0 ] = V_36 ;
if ( V_4 -> V_34 == V_35 ) {
F_7 ( V_2 ) ;
return 0 ;
}
V_32 = V_4 -> V_13 ;
V_33 = F_13 ( V_7 , V_32 -> V_26 ) ;
return F_11 ( V_7 , V_33 , V_4 -> V_29 ,
F_8 ( V_32 -> V_28 ) , NULL ,
V_15 * 10 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_25 ;
int V_37 ;
V_25 = F_8 ( V_4 -> V_13 -> V_28 ) ;
memset ( V_4 -> V_29 , 0 , V_25 ) ;
V_37 = F_12 ( V_2 , V_38 ) ;
if ( V_37 )
return V_37 ;
return F_12 ( V_2 , V_39 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_42 * V_43 ,
unsigned int * V_44 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_45 ;
int V_46 [ 2 ] ;
int V_47 ;
F_16 ( & V_4 -> V_48 ) ;
V_45 = F_17 ( V_43 -> V_49 ) ;
switch ( V_4 -> V_34 ) {
case V_50 :
if ( ! V_45 )
V_46 [ 0 ] = V_51 ;
else
V_46 [ 0 ] = V_52 ;
break;
case V_35 :
default:
V_46 [ 0 ] = V_53 ;
V_46 [ 1 ] = V_54 ;
V_4 -> V_29 [ 0 ] = V_55 ;
V_4 -> V_29 [ V_56 ] = V_45 ;
break;
}
for ( V_47 = 0 ; V_47 < V_43 -> V_47 ; V_47 ++ ) {
if ( F_9 ( V_2 ) )
break;
if ( V_4 -> V_34 == V_50 ) {
V_44 [ V_47 ] = V_4 -> V_30 [ V_46 [ 0 ] ] ;
continue;
}
V_44 [ V_47 ] = V_4 -> V_30 [ V_46 [ 0 ] ] + 256 *
V_4 -> V_30 [ V_46 [ 1 ] ] ;
}
F_18 ( & V_4 -> V_48 ) ;
return V_47 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_42 * V_43 ,
unsigned int * V_44 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_45 ;
int V_36 ;
int V_46 ;
int V_47 ;
F_16 ( & V_4 -> V_48 ) ;
V_45 = F_17 ( V_43 -> V_49 ) ;
switch ( V_4 -> V_34 ) {
case V_50 :
V_36 = V_39 ;
if ( ! V_45 )
V_46 = V_57 ;
else
V_46 = V_58 ;
break;
default:
V_36 = V_59 ;
V_46 = V_60 ;
V_4 -> V_29 [ V_56 ] = V_45 ;
break;
}
for ( V_47 = 0 ; V_47 < V_43 -> V_47 ; V_47 ++ ) {
V_4 -> V_29 [ V_46 ] = V_44 [ V_47 ] ;
if ( F_12 ( V_2 , V_36 ) )
break;
}
F_18 ( & V_4 -> V_48 ) ;
return V_47 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_42 * V_43 ,
unsigned int * V_44 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_45 ;
int V_46 ;
int V_47 ;
F_16 ( & V_4 -> V_48 ) ;
V_45 = F_17 ( V_43 -> V_49 ) ;
V_46 = V_60 - 1 ;
V_4 -> V_29 [ 0 ] = V_61 ;
for ( V_47 = 0 ; V_47 < V_43 -> V_47 ; V_47 ++ ) {
if ( F_9 ( V_2 ) )
break;
V_44 [ V_47 ] = V_4 -> V_30 [ V_46 + V_45 ] ;
}
F_18 ( & V_4 -> V_48 ) ;
return V_47 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_42 * V_43 ,
unsigned int * V_44 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_62 ;
int V_46 ;
int V_37 ;
F_16 ( & V_4 -> V_48 ) ;
V_62 = V_4 -> V_30 ;
if ( V_4 -> V_34 == V_35 ) {
V_46 = V_63 ;
V_4 -> V_29 [ 0 ] = V_64 ;
} else {
V_46 = V_65 ;
}
V_37 = F_9 ( V_2 ) ;
if ( ! V_37 ) {
if ( V_4 -> V_34 == V_50 )
V_44 [ 1 ] = ( ( ( V_62 [ V_46 ] >> 4 ) & 0x03 ) |
( ( V_62 [ V_46 ] << 2 ) & 0x04 ) |
( ( V_62 [ V_46 ] >> 3 ) & 0x18 ) ) ;
else
V_44 [ 1 ] = V_62 [ V_46 ] ;
V_37 = 2 ;
}
F_18 ( & V_4 -> V_48 ) ;
return V_37 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_42 * V_43 ,
unsigned int * V_44 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_62 = V_4 -> V_30 ;
unsigned char * V_66 = V_4 -> V_29 ;
int V_46 , V_36 ;
int V_67 = 0 ;
if ( V_4 -> V_34 == V_35 ) {
V_46 = V_68 ;
V_36 = V_69 ;
} else {
V_46 = V_70 ;
V_36 = V_39 ;
}
F_16 ( & V_4 -> V_48 ) ;
if ( F_23 ( V_41 , V_44 ) ) {
V_66 [ V_46 ] = V_41 -> V_71 ;
V_67 = F_12 ( V_2 , V_36 ) ;
if ( V_67 )
goto V_72;
}
if ( V_4 -> V_34 == V_35 ) {
V_66 [ 0 ] = V_73 ;
V_67 = F_9 ( V_2 ) ;
if ( V_67 )
goto V_72;
V_44 [ 1 ] = V_62 [ V_46 ] ;
} else {
V_44 [ 1 ] = V_41 -> V_71 ;
}
V_72:
F_18 ( & V_4 -> V_48 ) ;
return V_67 ? V_67 : V_43 -> V_47 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_42 * V_43 ,
unsigned int * V_44 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_45 ;
int V_46 [ 2 ] ;
int V_47 ;
F_16 ( & V_4 -> V_48 ) ;
V_45 = F_17 ( V_43 -> V_49 ) ;
switch ( V_4 -> V_34 ) {
case V_50 :
if ( ! V_45 )
V_46 [ 0 ] = V_74 ;
else
V_46 [ 0 ] = V_75 ;
break;
case V_35 :
default:
V_46 [ 0 ] = V_76 ;
V_46 [ 1 ] = V_76 ;
V_4 -> V_29 [ 0 ] = V_77 ;
break;
}
for ( V_47 = 0 ; V_47 < V_43 -> V_47 ; V_47 ++ ) {
if ( F_9 ( V_2 ) )
break;
if ( V_4 -> V_34 == V_50 )
V_44 [ V_47 ] = V_4 -> V_30 [ V_46 [ 0 ] ] ;
else
V_44 [ V_47 ] = V_4 -> V_30 [ V_46 [ 0 ] * ( V_45 + 1 ) + 1 ]
+ 256 * V_4 -> V_30 [ V_46 [ 1 ] * 2 + 2 ] ;
}
F_18 ( & V_4 -> V_48 ) ;
return V_47 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_42 * V_43 ,
unsigned int * V_44 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_78 ;
int V_45 ;
int V_36 ;
int V_46 ;
int V_47 ;
V_78 = V_44 [ 0 ] ;
if ( V_78 != V_79 && V_78 != V_80 )
return - V_81 ;
F_16 ( & V_4 -> V_48 ) ;
V_45 = F_17 ( V_43 -> V_49 ) ;
if ( V_4 -> V_34 == V_50 ) {
if ( ! V_45 ) {
V_36 = V_82 ;
V_46 = V_74 ;
} else {
V_36 = V_83 ;
V_46 = V_75 ;
}
V_4 -> V_29 [ V_46 ] = 0x00 ;
} else {
V_36 = V_84 ;
}
for ( V_47 = 0 ; V_47 < V_43 -> V_47 ; V_47 ++ )
if ( F_12 ( V_2 , V_36 ) )
break;
F_18 ( & V_4 -> V_48 ) ;
return V_47 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_42 * V_43 ,
unsigned int * V_44 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_85 ;
unsigned long V_86 ;
int V_45 ;
int V_36 ;
int V_47 ;
F_16 ( & V_4 -> V_48 ) ;
V_45 = F_17 ( V_43 -> V_49 ) ;
if ( ! V_45 )
V_36 = V_87 ;
else
V_36 = V_88 ;
for ( V_47 = 0 ; V_47 < V_43 -> V_47 ; V_47 ++ ) {
V_85 = V_44 [ V_47 ] ;
if ( V_85 == 0 )
V_85 = 1 ;
if ( V_85 > 7450 )
V_85 = 7450 ;
V_86 = F_27 ( V_85 * 1000 / 115 ) ;
if ( ( ( V_86 + 1 ) * V_86 ) < V_85 * 1000 / 115 )
V_86 += 1 ;
V_4 -> V_29 [ 6 + V_45 ] = V_86 ;
if ( F_12 ( V_2 , V_36 ) )
break;
}
F_18 ( & V_4 -> V_48 ) ;
return V_47 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_42 * V_43 ,
unsigned int * V_44 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_66 ;
unsigned char * V_62 ;
int V_46 [ 2 ] ;
int V_47 ;
F_16 ( & V_4 -> V_48 ) ;
V_66 = V_4 -> V_29 ;
V_62 = V_4 -> V_30 ;
V_46 [ 0 ] = V_89 ;
V_46 [ 1 ] = V_90 ;
V_66 [ 0 ] = V_91 ;
for ( V_47 = 0 ; V_47 < V_43 -> V_47 ; V_47 ++ ) {
if ( F_9 ( V_2 ) )
break;
V_44 [ V_47 ] = V_62 [ V_46 [ 0 ] ] + 4 * V_62 [ V_46 [ 1 ] ] ;
}
F_18 ( & V_4 -> V_48 ) ;
return V_47 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_42 * V_43 ,
unsigned int * V_44 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_66 ;
int V_46 [ 2 ] ;
int V_36 ;
int V_47 ;
F_16 ( & V_4 -> V_48 ) ;
V_66 = V_4 -> V_29 ;
V_46 [ 0 ] = V_89 ;
V_46 [ 1 ] = V_90 ;
V_36 = V_92 ;
for ( V_47 = 0 ; V_47 < V_43 -> V_47 ; V_47 ++ ) {
V_66 [ V_46 [ 0 ] ] = ( unsigned char ) ( V_44 [ V_47 ] & 0x03 ) ;
V_66 [ V_46 [ 1 ] ] = ( unsigned char ) ( V_44 [ V_47 ] >> 2 ) & 0xff ;
if ( F_12 ( V_2 , V_36 ) )
break;
}
F_18 ( & V_4 -> V_48 ) ;
return V_47 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_93 * V_94 = F_31 ( V_2 ) ;
struct V_95 * V_96 = V_94 -> V_97 ;
struct V_31 * V_98 ;
int V_99 ;
if ( V_96 -> V_100 . V_101 != 2 )
return - V_102 ;
for ( V_99 = 0 ; V_99 < V_96 -> V_100 . V_101 ; V_99 ++ ) {
V_98 = & V_96 -> V_103 [ V_99 ] . V_100 ;
if ( F_32 ( V_98 ) ||
F_33 ( V_98 ) ) {
if ( ! V_4 -> V_27 )
V_4 -> V_27 = V_98 ;
continue;
}
if ( F_34 ( V_98 ) ||
F_35 ( V_98 ) ) {
if ( ! V_4 -> V_13 )
V_4 -> V_13 = V_98 ;
continue;
}
}
if ( ! V_4 -> V_27 || ! V_4 -> V_13 )
return - V_102 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_25 ;
V_25 = F_8 ( V_4 -> V_27 -> V_28 ) ;
V_4 -> V_30 = F_37 ( V_25 , V_104 ) ;
if ( ! V_4 -> V_30 )
return - V_105 ;
V_25 = F_8 ( V_4 -> V_13 -> V_28 ) ;
V_4 -> V_29 = F_37 ( V_25 , V_104 ) ;
if ( ! V_4 -> V_29 ) {
F_38 ( V_4 -> V_30 ) ;
return - V_105 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
const struct V_106 * V_107 = F_40 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_40 * V_41 ;
int V_108 ;
int V_67 ;
F_16 ( & V_4 -> V_48 ) ;
if ( V_4 -> V_34 == V_50 )
V_108 = 5 ;
else
V_108 = 6 ;
V_67 = F_41 ( V_2 , V_108 ) ;
if ( V_67 ) {
F_18 ( & V_4 -> V_48 ) ;
return V_67 ;
}
V_41 = & V_2 -> V_109 [ 0 ] ;
V_41 -> type = V_110 ;
V_41 -> V_111 = V_112 | V_113 ;
V_41 -> V_114 = V_107 -> V_115 ;
V_41 -> V_116 = V_107 -> V_117 ;
V_41 -> V_118 = V_107 -> V_119 ;
V_41 -> V_120 = F_15 ;
V_41 = & V_2 -> V_109 [ 1 ] ;
V_41 -> type = V_121 ;
V_41 -> V_111 = V_122 | V_113 ;
V_41 -> V_114 = V_107 -> V_123 ;
V_41 -> V_116 = 0x00ff ;
V_41 -> V_118 = V_107 -> V_119 ;
V_41 -> V_124 = F_19 ;
if ( V_4 -> V_34 == V_35 ) {
V_41 -> V_111 |= V_112 ;
V_41 -> V_120 = F_20 ;
}
V_41 = & V_2 -> V_109 [ 2 ] ;
V_41 -> type = V_125 ;
V_41 -> V_111 = V_112 ;
V_41 -> V_114 = V_107 -> V_126 ;
V_41 -> V_116 = 1 ;
V_41 -> V_118 = & V_127 ;
V_41 -> V_128 = F_21 ;
V_41 = & V_2 -> V_109 [ 3 ] ;
V_41 -> type = V_129 ;
V_41 -> V_111 = V_122 ;
V_41 -> V_114 = 8 ;
V_41 -> V_116 = 1 ;
V_41 -> V_118 = & V_127 ;
V_41 -> V_128 = F_22 ;
V_41 = & V_2 -> V_109 [ 4 ] ;
V_41 -> type = V_130 ;
V_41 -> V_111 = V_112 ;
V_41 -> V_114 = 2 ;
V_41 -> V_116 = V_107 -> V_131 ;
V_41 -> V_120 = F_24 ;
V_41 -> V_132 = F_25 ;
if ( V_4 -> V_34 == V_50 ) {
V_41 -> V_111 |= V_122 ;
V_41 -> V_124 = F_26 ;
}
if ( V_4 -> V_34 == V_35 ) {
V_41 = & V_2 -> V_109 [ 5 ] ;
V_41 -> type = V_133 ;
V_41 -> V_111 = V_112 | V_122 ;
V_41 -> V_114 = V_107 -> V_134 ;
V_41 -> V_116 = V_107 -> V_135 ;
V_41 -> V_120 = F_28 ;
V_41 -> V_124 = F_29 ;
}
F_18 ( & V_4 -> V_48 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
unsigned long V_136 )
{
struct V_93 * V_94 = F_31 ( V_2 ) ;
const struct V_106 * V_107 ;
struct V_3 * V_4 ;
int V_67 ;
V_107 = & V_137 [ V_136 ] ;
V_2 -> V_138 = V_107 ;
V_2 -> V_139 = V_107 -> V_140 ;
V_4 = F_43 ( V_2 , sizeof( * V_4 ) ) ;
if ( ! V_4 )
return - V_105 ;
V_4 -> V_34 = V_107 -> V_34 ;
V_67 = F_30 ( V_2 ) ;
if ( V_67 )
return V_67 ;
V_67 = F_36 ( V_2 ) ;
if ( V_67 )
return V_67 ;
F_44 ( & V_4 -> V_48 , 8 ) ;
F_45 ( V_94 , V_4 ) ;
if ( V_4 -> V_34 == V_35 ) {
F_6 ( V_2 , V_19 ) ;
F_46 ( & V_94 -> V_2 , L_1 , V_4 -> V_20 . V_21 ) ;
if ( F_1 ( V_2 ) ) {
F_6 ( V_2 , V_141 ) ;
F_46 ( & V_94 -> V_2 , L_1 , V_4 -> V_20 . V_22 ) ;
}
}
if ( V_4 -> V_34 == V_50 )
F_14 ( V_2 ) ;
return F_39 ( V_2 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_93 * V_94 = F_31 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 )
return;
F_16 ( & V_4 -> V_48 ) ;
F_45 ( V_94 , NULL ) ;
F_38 ( V_4 -> V_30 ) ;
F_38 ( V_4 -> V_29 ) ;
F_18 ( & V_4 -> V_48 ) ;
}
static int F_48 ( struct V_93 * V_94 ,
const struct V_142 * V_143 )
{
return F_49 ( V_94 , & V_144 , V_143 -> V_145 ) ;
}
