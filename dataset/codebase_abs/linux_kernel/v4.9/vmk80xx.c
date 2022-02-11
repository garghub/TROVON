static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_8 ;
T_1 V_9 ;
unsigned int V_10 ;
unsigned int V_11 ;
T_2 V_12 ;
V_8 = V_4 -> V_13 -> V_14 ;
V_9 = V_4 -> V_15 -> V_14 ;
V_10 = F_3 ( V_7 , V_8 ) ;
V_11 = F_4 ( V_7 , V_9 ) ;
V_12 = F_5 ( V_4 -> V_13 ) ;
F_6 ( V_7 , V_10 , V_4 -> V_16 ,
V_12 , NULL , V_4 -> V_13 -> V_17 ) ;
F_6 ( V_7 , V_11 , V_4 -> V_18 , V_12 , NULL , V_19 * 10 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_20 * V_21 ;
unsigned int V_22 ;
if ( V_4 -> V_23 == V_24 ) {
F_1 ( V_2 ) ;
return 0 ;
}
V_21 = V_4 -> V_15 ;
V_22 = F_8 ( V_7 , V_21 -> V_14 ) ;
return F_9 ( V_7 , V_22 , V_4 -> V_18 ,
F_5 ( V_21 ) , NULL ,
V_19 * 10 ) ;
}
static int F_10 ( struct V_1 * V_2 , int V_25 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_20 * V_21 ;
unsigned int V_22 ;
V_4 -> V_16 [ 0 ] = V_25 ;
if ( V_4 -> V_23 == V_24 ) {
F_1 ( V_2 ) ;
return 0 ;
}
V_21 = V_4 -> V_13 ;
V_22 = F_11 ( V_7 , V_21 -> V_14 ) ;
return F_9 ( V_7 , V_22 , V_4 -> V_16 ,
F_5 ( V_21 ) , NULL ,
V_19 * 10 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_12 ;
int V_26 ;
V_12 = F_5 ( V_4 -> V_13 ) ;
memset ( V_4 -> V_16 , 0 , V_12 ) ;
V_26 = F_10 ( V_2 , V_27 ) ;
if ( V_26 )
return V_26 ;
return F_10 ( V_2 , V_28 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
struct V_31 * V_32 ,
unsigned int * V_33 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_34 ;
int V_35 [ 2 ] ;
int V_36 ;
F_14 ( & V_4 -> V_37 ) ;
V_34 = F_15 ( V_32 -> V_38 ) ;
switch ( V_4 -> V_23 ) {
case V_39 :
if ( ! V_34 )
V_35 [ 0 ] = V_40 ;
else
V_35 [ 0 ] = V_41 ;
break;
case V_24 :
default:
V_35 [ 0 ] = V_42 ;
V_35 [ 1 ] = V_43 ;
V_4 -> V_16 [ 0 ] = V_44 ;
V_4 -> V_16 [ V_45 ] = V_34 ;
break;
}
for ( V_36 = 0 ; V_36 < V_32 -> V_36 ; V_36 ++ ) {
if ( F_7 ( V_2 ) )
break;
if ( V_4 -> V_23 == V_39 ) {
V_33 [ V_36 ] = V_4 -> V_18 [ V_35 [ 0 ] ] ;
continue;
}
V_33 [ V_36 ] = V_4 -> V_18 [ V_35 [ 0 ] ] + 256 *
V_4 -> V_18 [ V_35 [ 1 ] ] ;
}
F_16 ( & V_4 -> V_37 ) ;
return V_36 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
struct V_31 * V_32 ,
unsigned int * V_33 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_34 ;
int V_25 ;
int V_35 ;
int V_36 ;
F_14 ( & V_4 -> V_37 ) ;
V_34 = F_15 ( V_32 -> V_38 ) ;
switch ( V_4 -> V_23 ) {
case V_39 :
V_25 = V_28 ;
if ( ! V_34 )
V_35 = V_46 ;
else
V_35 = V_47 ;
break;
default:
V_25 = V_48 ;
V_35 = V_49 ;
V_4 -> V_16 [ V_45 ] = V_34 ;
break;
}
for ( V_36 = 0 ; V_36 < V_32 -> V_36 ; V_36 ++ ) {
V_4 -> V_16 [ V_35 ] = V_33 [ V_36 ] ;
if ( F_10 ( V_2 , V_25 ) )
break;
}
F_16 ( & V_4 -> V_37 ) ;
return V_36 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
struct V_31 * V_32 ,
unsigned int * V_33 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_34 ;
int V_35 ;
int V_36 ;
F_14 ( & V_4 -> V_37 ) ;
V_34 = F_15 ( V_32 -> V_38 ) ;
V_35 = V_49 - 1 ;
V_4 -> V_16 [ 0 ] = V_50 ;
for ( V_36 = 0 ; V_36 < V_32 -> V_36 ; V_36 ++ ) {
if ( F_7 ( V_2 ) )
break;
V_33 [ V_36 ] = V_4 -> V_18 [ V_35 + V_34 ] ;
}
F_16 ( & V_4 -> V_37 ) ;
return V_36 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
struct V_31 * V_32 ,
unsigned int * V_33 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_51 ;
int V_35 ;
int V_26 ;
F_14 ( & V_4 -> V_37 ) ;
V_51 = V_4 -> V_18 ;
if ( V_4 -> V_23 == V_24 ) {
V_35 = V_52 ;
V_4 -> V_16 [ 0 ] = V_53 ;
} else {
V_35 = V_54 ;
}
V_26 = F_7 ( V_2 ) ;
if ( ! V_26 ) {
if ( V_4 -> V_23 == V_39 )
V_33 [ 1 ] = ( ( ( V_51 [ V_35 ] >> 4 ) & 0x03 ) |
( ( V_51 [ V_35 ] << 2 ) & 0x04 ) |
( ( V_51 [ V_35 ] >> 3 ) & 0x18 ) ) ;
else
V_33 [ 1 ] = V_51 [ V_35 ] ;
V_26 = 2 ;
}
F_16 ( & V_4 -> V_37 ) ;
return V_26 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
struct V_31 * V_32 ,
unsigned int * V_33 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_51 = V_4 -> V_18 ;
unsigned char * V_55 = V_4 -> V_16 ;
int V_35 , V_25 ;
int V_56 = 0 ;
if ( V_4 -> V_23 == V_24 ) {
V_35 = V_57 ;
V_25 = V_58 ;
} else {
V_35 = V_59 ;
V_25 = V_28 ;
}
F_14 ( & V_4 -> V_37 ) ;
if ( F_21 ( V_30 , V_33 ) ) {
V_55 [ V_35 ] = V_30 -> V_60 ;
V_56 = F_10 ( V_2 , V_25 ) ;
if ( V_56 )
goto V_61;
}
if ( V_4 -> V_23 == V_24 ) {
V_55 [ 0 ] = V_62 ;
V_56 = F_7 ( V_2 ) ;
if ( V_56 )
goto V_61;
V_33 [ 1 ] = V_51 [ V_35 ] ;
} else {
V_33 [ 1 ] = V_30 -> V_60 ;
}
V_61:
F_16 ( & V_4 -> V_37 ) ;
return V_56 ? V_56 : V_32 -> V_36 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
struct V_31 * V_32 ,
unsigned int * V_33 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_34 ;
int V_35 [ 2 ] ;
int V_36 ;
F_14 ( & V_4 -> V_37 ) ;
V_34 = F_15 ( V_32 -> V_38 ) ;
switch ( V_4 -> V_23 ) {
case V_39 :
if ( ! V_34 )
V_35 [ 0 ] = V_63 ;
else
V_35 [ 0 ] = V_64 ;
break;
case V_24 :
default:
V_35 [ 0 ] = V_65 ;
V_35 [ 1 ] = V_65 ;
V_4 -> V_16 [ 0 ] = V_66 ;
break;
}
for ( V_36 = 0 ; V_36 < V_32 -> V_36 ; V_36 ++ ) {
if ( F_7 ( V_2 ) )
break;
if ( V_4 -> V_23 == V_39 )
V_33 [ V_36 ] = V_4 -> V_18 [ V_35 [ 0 ] ] ;
else
V_33 [ V_36 ] = V_4 -> V_18 [ V_35 [ 0 ] * ( V_34 + 1 ) + 1 ]
+ 256 * V_4 -> V_18 [ V_35 [ 1 ] * 2 + 2 ] ;
}
F_16 ( & V_4 -> V_37 ) ;
return V_36 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
struct V_31 * V_32 ,
unsigned int * V_33 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_34 = F_15 ( V_32 -> V_38 ) ;
int V_25 ;
int V_35 ;
int V_56 ;
F_14 ( & V_4 -> V_37 ) ;
switch ( V_33 [ 0 ] ) {
case V_67 :
if ( V_4 -> V_23 == V_39 ) {
if ( ! V_34 ) {
V_25 = V_68 ;
V_35 = V_63 ;
} else {
V_25 = V_69 ;
V_35 = V_64 ;
}
V_4 -> V_16 [ V_35 ] = 0x00 ;
} else {
V_25 = V_70 ;
}
V_56 = F_10 ( V_2 , V_25 ) ;
break;
default:
V_56 = - V_71 ;
break;
}
F_16 ( & V_4 -> V_37 ) ;
return V_56 ? V_56 : V_32 -> V_36 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
struct V_31 * V_32 ,
unsigned int * V_33 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_72 ;
unsigned long V_73 ;
int V_34 ;
int V_25 ;
int V_36 ;
F_14 ( & V_4 -> V_37 ) ;
V_34 = F_15 ( V_32 -> V_38 ) ;
if ( ! V_34 )
V_25 = V_74 ;
else
V_25 = V_75 ;
for ( V_36 = 0 ; V_36 < V_32 -> V_36 ; V_36 ++ ) {
V_72 = V_33 [ V_36 ] ;
if ( V_72 == 0 )
V_72 = 1 ;
if ( V_72 > 7450 )
V_72 = 7450 ;
V_73 = F_25 ( V_72 * 1000 / 115 ) ;
if ( ( ( V_73 + 1 ) * V_73 ) < V_72 * 1000 / 115 )
V_73 += 1 ;
V_4 -> V_16 [ 6 + V_34 ] = V_73 ;
if ( F_10 ( V_2 , V_25 ) )
break;
}
F_16 ( & V_4 -> V_37 ) ;
return V_36 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
struct V_31 * V_32 ,
unsigned int * V_33 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_55 ;
unsigned char * V_51 ;
int V_35 [ 2 ] ;
int V_36 ;
F_14 ( & V_4 -> V_37 ) ;
V_55 = V_4 -> V_16 ;
V_51 = V_4 -> V_18 ;
V_35 [ 0 ] = V_76 ;
V_35 [ 1 ] = V_77 ;
V_55 [ 0 ] = V_78 ;
for ( V_36 = 0 ; V_36 < V_32 -> V_36 ; V_36 ++ ) {
if ( F_7 ( V_2 ) )
break;
V_33 [ V_36 ] = V_51 [ V_35 [ 0 ] ] + 4 * V_51 [ V_35 [ 1 ] ] ;
}
F_16 ( & V_4 -> V_37 ) ;
return V_36 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
struct V_31 * V_32 ,
unsigned int * V_33 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_55 ;
int V_35 [ 2 ] ;
int V_25 ;
int V_36 ;
F_14 ( & V_4 -> V_37 ) ;
V_55 = V_4 -> V_16 ;
V_35 [ 0 ] = V_76 ;
V_35 [ 1 ] = V_77 ;
V_25 = V_79 ;
for ( V_36 = 0 ; V_36 < V_32 -> V_36 ; V_36 ++ ) {
V_55 [ V_35 [ 0 ] ] = ( unsigned char ) ( V_33 [ V_36 ] & 0x03 ) ;
V_55 [ V_35 [ 1 ] ] = ( unsigned char ) ( V_33 [ V_36 ] >> 2 ) & 0xff ;
if ( F_10 ( V_2 , V_25 ) )
break;
}
F_16 ( & V_4 -> V_37 ) ;
return V_36 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_80 * V_81 = F_29 ( V_2 ) ;
struct V_82 * V_83 = V_81 -> V_84 ;
struct V_20 * V_85 ;
int V_86 ;
if ( V_83 -> V_87 . V_88 != 2 )
return - V_89 ;
for ( V_86 = 0 ; V_86 < V_83 -> V_87 . V_88 ; V_86 ++ ) {
V_85 = & V_83 -> V_90 [ V_86 ] . V_87 ;
if ( F_30 ( V_85 ) ||
F_31 ( V_85 ) ) {
if ( ! V_4 -> V_15 )
V_4 -> V_15 = V_85 ;
continue;
}
if ( F_32 ( V_85 ) ||
F_33 ( V_85 ) ) {
if ( ! V_4 -> V_13 )
V_4 -> V_13 = V_85 ;
continue;
}
}
if ( ! V_4 -> V_15 || ! V_4 -> V_13 )
return - V_89 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_12 ;
V_12 = F_5 ( V_4 -> V_15 ) ;
V_4 -> V_18 = F_35 ( V_12 , V_91 ) ;
if ( ! V_4 -> V_18 )
return - V_92 ;
V_12 = F_5 ( V_4 -> V_13 ) ;
V_4 -> V_16 = F_35 ( V_12 , V_91 ) ;
if ( ! V_4 -> V_16 ) {
F_36 ( V_4 -> V_18 ) ;
return - V_92 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
const struct V_93 * V_94 = V_2 -> V_95 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_29 * V_30 ;
int V_96 ;
int V_56 ;
F_14 ( & V_4 -> V_37 ) ;
if ( V_4 -> V_23 == V_39 )
V_96 = 5 ;
else
V_96 = 6 ;
V_56 = F_38 ( V_2 , V_96 ) ;
if ( V_56 ) {
F_16 ( & V_4 -> V_37 ) ;
return V_56 ;
}
V_30 = & V_2 -> V_97 [ 0 ] ;
V_30 -> type = V_98 ;
V_30 -> V_99 = V_100 | V_101 ;
V_30 -> V_102 = V_94 -> V_103 ;
V_30 -> V_104 = V_94 -> V_105 ;
V_30 -> V_106 = V_94 -> V_107 ;
V_30 -> V_108 = F_13 ;
V_30 = & V_2 -> V_97 [ 1 ] ;
V_30 -> type = V_109 ;
V_30 -> V_99 = V_110 | V_101 ;
V_30 -> V_102 = V_94 -> V_111 ;
V_30 -> V_104 = 0x00ff ;
V_30 -> V_106 = V_94 -> V_107 ;
V_30 -> V_112 = F_17 ;
if ( V_4 -> V_23 == V_24 ) {
V_30 -> V_99 |= V_100 ;
V_30 -> V_108 = F_18 ;
}
V_30 = & V_2 -> V_97 [ 2 ] ;
V_30 -> type = V_113 ;
V_30 -> V_99 = V_100 ;
V_30 -> V_102 = V_94 -> V_114 ;
V_30 -> V_104 = 1 ;
V_30 -> V_106 = & V_115 ;
V_30 -> V_116 = F_19 ;
V_30 = & V_2 -> V_97 [ 3 ] ;
V_30 -> type = V_117 ;
V_30 -> V_99 = V_110 ;
V_30 -> V_102 = 8 ;
V_30 -> V_104 = 1 ;
V_30 -> V_106 = & V_115 ;
V_30 -> V_116 = F_20 ;
V_30 = & V_2 -> V_97 [ 4 ] ;
V_30 -> type = V_118 ;
V_30 -> V_99 = V_100 ;
V_30 -> V_102 = 2 ;
V_30 -> V_104 = V_94 -> V_119 ;
V_30 -> V_108 = F_22 ;
V_30 -> V_120 = F_23 ;
if ( V_4 -> V_23 == V_39 ) {
V_30 -> V_99 |= V_110 ;
V_30 -> V_112 = F_24 ;
}
if ( V_4 -> V_23 == V_24 ) {
V_30 = & V_2 -> V_97 [ 5 ] ;
V_30 -> type = V_121 ;
V_30 -> V_99 = V_100 | V_110 ;
V_30 -> V_102 = V_94 -> V_122 ;
V_30 -> V_104 = V_94 -> V_123 ;
V_30 -> V_108 = F_26 ;
V_30 -> V_112 = F_27 ;
}
F_16 ( & V_4 -> V_37 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
unsigned long V_124 )
{
struct V_80 * V_81 = F_29 ( V_2 ) ;
const struct V_93 * V_94 = NULL ;
struct V_3 * V_4 ;
int V_56 ;
if ( V_124 < F_40 ( V_125 ) )
V_94 = & V_125 [ V_124 ] ;
if ( ! V_94 )
return - V_89 ;
V_2 -> V_95 = V_94 ;
V_2 -> V_126 = V_94 -> V_127 ;
V_4 = F_41 ( V_2 , sizeof( * V_4 ) ) ;
if ( ! V_4 )
return - V_92 ;
V_4 -> V_23 = V_94 -> V_23 ;
V_56 = F_28 ( V_2 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_34 ( V_2 ) ;
if ( V_56 )
return V_56 ;
F_42 ( & V_4 -> V_37 , 8 ) ;
F_43 ( V_81 , V_4 ) ;
if ( V_4 -> V_23 == V_39 )
F_12 ( V_2 ) ;
return F_37 ( V_2 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_80 * V_81 = F_29 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 )
return;
F_14 ( & V_4 -> V_37 ) ;
F_43 ( V_81 , NULL ) ;
F_36 ( V_4 -> V_18 ) ;
F_36 ( V_4 -> V_16 ) ;
F_16 ( & V_4 -> V_37 ) ;
}
static int F_45 ( struct V_80 * V_81 ,
const struct V_128 * V_129 )
{
return F_46 ( V_81 , & V_130 , V_129 -> V_131 ) ;
}
