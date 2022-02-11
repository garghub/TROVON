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
V_12 = F_5 ( V_4 -> V_13 -> V_16 ) ;
F_6 ( V_7 , V_10 , V_4 -> V_17 ,
V_12 , NULL , V_4 -> V_13 -> V_18 ) ;
F_6 ( V_7 , V_11 , V_4 -> V_19 , V_12 , NULL , V_20 * 10 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_21 * V_22 ;
unsigned int V_23 ;
if ( V_4 -> V_24 == V_25 ) {
F_1 ( V_2 ) ;
return 0 ;
}
V_22 = V_4 -> V_15 ;
V_23 = F_8 ( V_7 , V_22 -> V_14 ) ;
return F_9 ( V_7 , V_23 , V_4 -> V_19 ,
F_5 ( V_22 -> V_16 ) , NULL ,
V_20 * 10 ) ;
}
static int F_10 ( struct V_1 * V_2 , int V_26 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_21 * V_22 ;
unsigned int V_23 ;
V_4 -> V_17 [ 0 ] = V_26 ;
if ( V_4 -> V_24 == V_25 ) {
F_1 ( V_2 ) ;
return 0 ;
}
V_22 = V_4 -> V_13 ;
V_23 = F_11 ( V_7 , V_22 -> V_14 ) ;
return F_9 ( V_7 , V_23 , V_4 -> V_17 ,
F_5 ( V_22 -> V_16 ) , NULL ,
V_20 * 10 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_12 ;
int V_27 ;
V_12 = F_5 ( V_4 -> V_13 -> V_16 ) ;
memset ( V_4 -> V_17 , 0 , V_12 ) ;
V_27 = F_10 ( V_2 , V_28 ) ;
if ( V_27 )
return V_27 ;
return F_10 ( V_2 , V_29 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_32 * V_33 ,
unsigned int * V_34 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_35 ;
int V_36 [ 2 ] ;
int V_37 ;
F_14 ( & V_4 -> V_38 ) ;
V_35 = F_15 ( V_33 -> V_39 ) ;
switch ( V_4 -> V_24 ) {
case V_40 :
if ( ! V_35 )
V_36 [ 0 ] = V_41 ;
else
V_36 [ 0 ] = V_42 ;
break;
case V_25 :
default:
V_36 [ 0 ] = V_43 ;
V_36 [ 1 ] = V_44 ;
V_4 -> V_17 [ 0 ] = V_45 ;
V_4 -> V_17 [ V_46 ] = V_35 ;
break;
}
for ( V_37 = 0 ; V_37 < V_33 -> V_37 ; V_37 ++ ) {
if ( F_7 ( V_2 ) )
break;
if ( V_4 -> V_24 == V_40 ) {
V_34 [ V_37 ] = V_4 -> V_19 [ V_36 [ 0 ] ] ;
continue;
}
V_34 [ V_37 ] = V_4 -> V_19 [ V_36 [ 0 ] ] + 256 *
V_4 -> V_19 [ V_36 [ 1 ] ] ;
}
F_16 ( & V_4 -> V_38 ) ;
return V_37 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_32 * V_33 ,
unsigned int * V_34 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_35 ;
int V_26 ;
int V_36 ;
int V_37 ;
F_14 ( & V_4 -> V_38 ) ;
V_35 = F_15 ( V_33 -> V_39 ) ;
switch ( V_4 -> V_24 ) {
case V_40 :
V_26 = V_29 ;
if ( ! V_35 )
V_36 = V_47 ;
else
V_36 = V_48 ;
break;
default:
V_26 = V_49 ;
V_36 = V_50 ;
V_4 -> V_17 [ V_46 ] = V_35 ;
break;
}
for ( V_37 = 0 ; V_37 < V_33 -> V_37 ; V_37 ++ ) {
V_4 -> V_17 [ V_36 ] = V_34 [ V_37 ] ;
if ( F_10 ( V_2 , V_26 ) )
break;
}
F_16 ( & V_4 -> V_38 ) ;
return V_37 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_32 * V_33 ,
unsigned int * V_34 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_35 ;
int V_36 ;
int V_37 ;
F_14 ( & V_4 -> V_38 ) ;
V_35 = F_15 ( V_33 -> V_39 ) ;
V_36 = V_50 - 1 ;
V_4 -> V_17 [ 0 ] = V_51 ;
for ( V_37 = 0 ; V_37 < V_33 -> V_37 ; V_37 ++ ) {
if ( F_7 ( V_2 ) )
break;
V_34 [ V_37 ] = V_4 -> V_19 [ V_36 + V_35 ] ;
}
F_16 ( & V_4 -> V_38 ) ;
return V_37 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_32 * V_33 ,
unsigned int * V_34 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_52 ;
int V_36 ;
int V_27 ;
F_14 ( & V_4 -> V_38 ) ;
V_52 = V_4 -> V_19 ;
if ( V_4 -> V_24 == V_25 ) {
V_36 = V_53 ;
V_4 -> V_17 [ 0 ] = V_54 ;
} else {
V_36 = V_55 ;
}
V_27 = F_7 ( V_2 ) ;
if ( ! V_27 ) {
if ( V_4 -> V_24 == V_40 )
V_34 [ 1 ] = ( ( ( V_52 [ V_36 ] >> 4 ) & 0x03 ) |
( ( V_52 [ V_36 ] << 2 ) & 0x04 ) |
( ( V_52 [ V_36 ] >> 3 ) & 0x18 ) ) ;
else
V_34 [ 1 ] = V_52 [ V_36 ] ;
V_27 = 2 ;
}
F_16 ( & V_4 -> V_38 ) ;
return V_27 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_32 * V_33 ,
unsigned int * V_34 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_52 = V_4 -> V_19 ;
unsigned char * V_56 = V_4 -> V_17 ;
int V_36 , V_26 ;
int V_57 = 0 ;
if ( V_4 -> V_24 == V_25 ) {
V_36 = V_58 ;
V_26 = V_59 ;
} else {
V_36 = V_60 ;
V_26 = V_29 ;
}
F_14 ( & V_4 -> V_38 ) ;
if ( F_21 ( V_31 , V_34 ) ) {
V_56 [ V_36 ] = V_31 -> V_61 ;
V_57 = F_10 ( V_2 , V_26 ) ;
if ( V_57 )
goto V_62;
}
if ( V_4 -> V_24 == V_25 ) {
V_56 [ 0 ] = V_63 ;
V_57 = F_7 ( V_2 ) ;
if ( V_57 )
goto V_62;
V_34 [ 1 ] = V_52 [ V_36 ] ;
} else {
V_34 [ 1 ] = V_31 -> V_61 ;
}
V_62:
F_16 ( & V_4 -> V_38 ) ;
return V_57 ? V_57 : V_33 -> V_37 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_32 * V_33 ,
unsigned int * V_34 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_35 ;
int V_36 [ 2 ] ;
int V_37 ;
F_14 ( & V_4 -> V_38 ) ;
V_35 = F_15 ( V_33 -> V_39 ) ;
switch ( V_4 -> V_24 ) {
case V_40 :
if ( ! V_35 )
V_36 [ 0 ] = V_64 ;
else
V_36 [ 0 ] = V_65 ;
break;
case V_25 :
default:
V_36 [ 0 ] = V_66 ;
V_36 [ 1 ] = V_66 ;
V_4 -> V_17 [ 0 ] = V_67 ;
break;
}
for ( V_37 = 0 ; V_37 < V_33 -> V_37 ; V_37 ++ ) {
if ( F_7 ( V_2 ) )
break;
if ( V_4 -> V_24 == V_40 )
V_34 [ V_37 ] = V_4 -> V_19 [ V_36 [ 0 ] ] ;
else
V_34 [ V_37 ] = V_4 -> V_19 [ V_36 [ 0 ] * ( V_35 + 1 ) + 1 ]
+ 256 * V_4 -> V_19 [ V_36 [ 1 ] * 2 + 2 ] ;
}
F_16 ( & V_4 -> V_38 ) ;
return V_37 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_32 * V_33 ,
unsigned int * V_34 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_35 = F_15 ( V_33 -> V_39 ) ;
int V_26 ;
int V_36 ;
int V_57 ;
F_14 ( & V_4 -> V_38 ) ;
switch ( V_34 [ 0 ] ) {
case V_68 :
if ( V_4 -> V_24 == V_40 ) {
if ( ! V_35 ) {
V_26 = V_69 ;
V_36 = V_64 ;
} else {
V_26 = V_70 ;
V_36 = V_65 ;
}
V_4 -> V_17 [ V_36 ] = 0x00 ;
} else {
V_26 = V_71 ;
}
V_57 = F_10 ( V_2 , V_26 ) ;
break;
default:
V_57 = - V_72 ;
break;
}
F_16 ( & V_4 -> V_38 ) ;
return V_57 ? V_57 : V_33 -> V_37 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_32 * V_33 ,
unsigned int * V_34 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_73 ;
unsigned long V_74 ;
int V_35 ;
int V_26 ;
int V_37 ;
F_14 ( & V_4 -> V_38 ) ;
V_35 = F_15 ( V_33 -> V_39 ) ;
if ( ! V_35 )
V_26 = V_75 ;
else
V_26 = V_76 ;
for ( V_37 = 0 ; V_37 < V_33 -> V_37 ; V_37 ++ ) {
V_73 = V_34 [ V_37 ] ;
if ( V_73 == 0 )
V_73 = 1 ;
if ( V_73 > 7450 )
V_73 = 7450 ;
V_74 = F_25 ( V_73 * 1000 / 115 ) ;
if ( ( ( V_74 + 1 ) * V_74 ) < V_73 * 1000 / 115 )
V_74 += 1 ;
V_4 -> V_17 [ 6 + V_35 ] = V_74 ;
if ( F_10 ( V_2 , V_26 ) )
break;
}
F_16 ( & V_4 -> V_38 ) ;
return V_37 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_32 * V_33 ,
unsigned int * V_34 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_56 ;
unsigned char * V_52 ;
int V_36 [ 2 ] ;
int V_37 ;
F_14 ( & V_4 -> V_38 ) ;
V_56 = V_4 -> V_17 ;
V_52 = V_4 -> V_19 ;
V_36 [ 0 ] = V_77 ;
V_36 [ 1 ] = V_78 ;
V_56 [ 0 ] = V_79 ;
for ( V_37 = 0 ; V_37 < V_33 -> V_37 ; V_37 ++ ) {
if ( F_7 ( V_2 ) )
break;
V_34 [ V_37 ] = V_52 [ V_36 [ 0 ] ] + 4 * V_52 [ V_36 [ 1 ] ] ;
}
F_16 ( & V_4 -> V_38 ) ;
return V_37 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_32 * V_33 ,
unsigned int * V_34 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_56 ;
int V_36 [ 2 ] ;
int V_26 ;
int V_37 ;
F_14 ( & V_4 -> V_38 ) ;
V_56 = V_4 -> V_17 ;
V_36 [ 0 ] = V_77 ;
V_36 [ 1 ] = V_78 ;
V_26 = V_80 ;
for ( V_37 = 0 ; V_37 < V_33 -> V_37 ; V_37 ++ ) {
V_56 [ V_36 [ 0 ] ] = ( unsigned char ) ( V_34 [ V_37 ] & 0x03 ) ;
V_56 [ V_36 [ 1 ] ] = ( unsigned char ) ( V_34 [ V_37 ] >> 2 ) & 0xff ;
if ( F_10 ( V_2 , V_26 ) )
break;
}
F_16 ( & V_4 -> V_38 ) ;
return V_37 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_81 * V_82 = F_29 ( V_2 ) ;
struct V_83 * V_84 = V_82 -> V_85 ;
struct V_21 * V_86 ;
int V_87 ;
if ( V_84 -> V_88 . V_89 != 2 )
return - V_90 ;
for ( V_87 = 0 ; V_87 < V_84 -> V_88 . V_89 ; V_87 ++ ) {
V_86 = & V_84 -> V_91 [ V_87 ] . V_88 ;
if ( F_30 ( V_86 ) ||
F_31 ( V_86 ) ) {
if ( ! V_4 -> V_15 )
V_4 -> V_15 = V_86 ;
continue;
}
if ( F_32 ( V_86 ) ||
F_33 ( V_86 ) ) {
if ( ! V_4 -> V_13 )
V_4 -> V_13 = V_86 ;
continue;
}
}
if ( ! V_4 -> V_15 || ! V_4 -> V_13 )
return - V_90 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_12 ;
V_12 = F_5 ( V_4 -> V_15 -> V_16 ) ;
V_4 -> V_19 = F_35 ( V_12 , V_92 ) ;
if ( ! V_4 -> V_19 )
return - V_93 ;
V_12 = F_5 ( V_4 -> V_13 -> V_16 ) ;
V_4 -> V_17 = F_35 ( V_12 , V_92 ) ;
if ( ! V_4 -> V_17 ) {
F_36 ( V_4 -> V_19 ) ;
return - V_93 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
const struct V_94 * V_95 = V_2 -> V_96 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_30 * V_31 ;
int V_97 ;
int V_57 ;
F_14 ( & V_4 -> V_38 ) ;
if ( V_4 -> V_24 == V_40 )
V_97 = 5 ;
else
V_97 = 6 ;
V_57 = F_38 ( V_2 , V_97 ) ;
if ( V_57 ) {
F_16 ( & V_4 -> V_38 ) ;
return V_57 ;
}
V_31 = & V_2 -> V_98 [ 0 ] ;
V_31 -> type = V_99 ;
V_31 -> V_100 = V_101 | V_102 ;
V_31 -> V_103 = V_95 -> V_104 ;
V_31 -> V_105 = V_95 -> V_106 ;
V_31 -> V_107 = V_95 -> V_108 ;
V_31 -> V_109 = F_13 ;
V_31 = & V_2 -> V_98 [ 1 ] ;
V_31 -> type = V_110 ;
V_31 -> V_100 = V_111 | V_102 ;
V_31 -> V_103 = V_95 -> V_112 ;
V_31 -> V_105 = 0x00ff ;
V_31 -> V_107 = V_95 -> V_108 ;
V_31 -> V_113 = F_17 ;
if ( V_4 -> V_24 == V_25 ) {
V_31 -> V_100 |= V_101 ;
V_31 -> V_109 = F_18 ;
}
V_31 = & V_2 -> V_98 [ 2 ] ;
V_31 -> type = V_114 ;
V_31 -> V_100 = V_101 ;
V_31 -> V_103 = V_95 -> V_115 ;
V_31 -> V_105 = 1 ;
V_31 -> V_107 = & V_116 ;
V_31 -> V_117 = F_19 ;
V_31 = & V_2 -> V_98 [ 3 ] ;
V_31 -> type = V_118 ;
V_31 -> V_100 = V_111 ;
V_31 -> V_103 = 8 ;
V_31 -> V_105 = 1 ;
V_31 -> V_107 = & V_116 ;
V_31 -> V_117 = F_20 ;
V_31 = & V_2 -> V_98 [ 4 ] ;
V_31 -> type = V_119 ;
V_31 -> V_100 = V_101 ;
V_31 -> V_103 = 2 ;
V_31 -> V_105 = V_95 -> V_120 ;
V_31 -> V_109 = F_22 ;
V_31 -> V_121 = F_23 ;
if ( V_4 -> V_24 == V_40 ) {
V_31 -> V_100 |= V_111 ;
V_31 -> V_113 = F_24 ;
}
if ( V_4 -> V_24 == V_25 ) {
V_31 = & V_2 -> V_98 [ 5 ] ;
V_31 -> type = V_122 ;
V_31 -> V_100 = V_101 | V_111 ;
V_31 -> V_103 = V_95 -> V_123 ;
V_31 -> V_105 = V_95 -> V_124 ;
V_31 -> V_109 = F_26 ;
V_31 -> V_113 = F_27 ;
}
F_16 ( & V_4 -> V_38 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
unsigned long V_125 )
{
struct V_81 * V_82 = F_29 ( V_2 ) ;
const struct V_94 * V_95 ;
struct V_3 * V_4 ;
int V_57 ;
V_95 = & V_126 [ V_125 ] ;
V_2 -> V_96 = V_95 ;
V_2 -> V_127 = V_95 -> V_128 ;
V_4 = F_40 ( V_2 , sizeof( * V_4 ) ) ;
if ( ! V_4 )
return - V_93 ;
V_4 -> V_24 = V_95 -> V_24 ;
V_57 = F_28 ( V_2 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_34 ( V_2 ) ;
if ( V_57 )
return V_57 ;
F_41 ( & V_4 -> V_38 , 8 ) ;
F_42 ( V_82 , V_4 ) ;
if ( V_4 -> V_24 == V_40 )
F_12 ( V_2 ) ;
return F_37 ( V_2 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_81 * V_82 = F_29 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 )
return;
F_14 ( & V_4 -> V_38 ) ;
F_42 ( V_82 , NULL ) ;
F_36 ( V_4 -> V_19 ) ;
F_36 ( V_4 -> V_17 ) ;
F_16 ( & V_4 -> V_38 ) ;
}
static int F_44 ( struct V_81 * V_82 ,
const struct V_129 * V_130 )
{
return F_45 ( V_82 , & V_131 , V_130 -> V_132 ) ;
}
