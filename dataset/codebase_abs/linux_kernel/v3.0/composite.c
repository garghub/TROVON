int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = - V_6 ;
F_2 ( V_2 -> V_7 , L_1 ,
V_4 -> V_8 , V_4 ,
V_2 -> V_9 , V_2 ) ;
if ( ! V_4 -> V_10 || ! V_4 -> V_11 )
goto V_12;
V_4 -> V_2 = V_2 ;
F_3 ( & V_4 -> V_13 , & V_2 -> V_14 ) ;
if ( V_4 -> V_15 ) {
V_5 = V_4 -> V_15 ( V_2 , V_4 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_4 -> V_13 ) ;
V_4 -> V_2 = NULL ;
}
} else
V_5 = 0 ;
if ( ! V_2 -> V_16 && V_4 -> V_17 )
V_2 -> V_16 = true ;
if ( ! V_2 -> V_18 && V_4 -> V_19 )
V_2 -> V_18 = true ;
V_12:
if ( V_5 )
F_2 ( V_2 -> V_7 , L_2 ,
V_4 -> V_8 , V_4 , V_5 ) ;
return V_5 ;
}
int F_5 ( struct V_3 * V_4 )
{
struct V_20 * V_7 = V_4 -> V_2 -> V_7 ;
unsigned long V_21 ;
int V_22 = 0 ;
F_6 ( & V_7 -> V_23 , V_21 ) ;
if ( V_7 -> V_24 == 0 )
V_22 = F_7 ( V_7 -> V_25 ) ;
if ( V_22 == 0 )
V_7 -> V_24 ++ ;
F_8 ( & V_7 -> V_23 , V_21 ) ;
return V_22 ;
}
int F_9 ( struct V_3 * V_4 )
{
struct V_20 * V_7 = V_4 -> V_2 -> V_7 ;
int V_22 = 0 ;
F_10 ( & V_7 -> V_23 ) ;
if ( F_11 ( V_7 -> V_24 == 0 ) )
V_22 = - V_6 ;
else {
V_7 -> V_24 -- ;
if ( V_7 -> V_24 == 0 )
V_22 = F_12 ( V_7 -> V_25 ) ;
}
F_13 ( & V_7 -> V_23 ) ;
return V_22 ;
}
int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned V_26 = V_2 -> V_27 ;
if ( V_26 < V_28 ) {
V_2 -> V_29 [ V_26 ] = V_4 ;
V_2 -> V_27 = V_26 + 1 ;
return V_26 ;
}
return - V_30 ;
}
static int F_15 ( struct V_1 * V_2 ,
enum V_31 V_32 , void * V_33 , T_1 type )
{
struct V_34 * V_35 = V_33 ;
void * V_36 = V_33 + V_37 ;
int V_38 = V_39 - V_37 ;
struct V_3 * V_40 ;
int V_22 ;
V_35 = V_33 ;
V_35 -> V_41 = V_37 ;
V_35 -> V_42 = type ;
V_35 -> V_43 = V_2 -> V_27 ;
V_35 -> V_44 = V_2 -> V_44 ;
V_35 -> V_45 = V_2 -> V_45 ;
V_35 -> V_46 = V_47 | V_2 -> V_46 ;
V_35 -> V_48 = V_2 -> V_48 ? : ( V_49 / 2 ) ;
if ( V_2 -> V_17 ) {
V_22 = F_16 ( V_36 , V_38 ,
V_2 -> V_17 ) ;
if ( V_22 < 0 )
return V_22 ;
V_38 -= V_22 ;
V_36 += V_22 ;
}
F_17 (f, &config->functions, list) {
struct V_50 * * V_17 ;
if ( V_32 == V_51 )
V_17 = V_40 -> V_19 ;
else
V_17 = V_40 -> V_17 ;
if ( ! V_17 )
continue;
V_22 = F_16 ( V_36 , V_38 ,
( const struct V_50 * * ) V_17 ) ;
if ( V_22 < 0 )
return V_22 ;
V_38 -= V_22 ;
V_36 += V_22 ;
}
V_38 = V_36 - V_33 ;
V_35 -> V_52 = F_18 ( V_38 ) ;
return V_38 ;
}
static int F_19 ( struct V_20 * V_7 , unsigned V_53 )
{
struct V_54 * V_25 = V_7 -> V_25 ;
struct V_1 * V_35 ;
T_1 type = V_53 >> 8 ;
enum V_31 V_32 = V_55 ;
if ( F_20 ( V_25 ) ) {
int V_56 = 0 ;
if ( V_25 -> V_32 == V_51 )
V_56 = 1 ;
if ( type == V_57 )
V_56 = ! V_56 ;
if ( V_56 )
V_32 = V_51 ;
}
V_53 &= 0xff ;
F_17 (c, &cdev->configs, list) {
if ( V_32 == V_51 ) {
if ( ! V_35 -> V_18 )
continue;
} else {
if ( ! V_35 -> V_16 )
continue;
}
if ( V_53 == 0 )
return F_15 ( V_35 , V_32 , V_7 -> V_58 -> V_33 , type ) ;
V_53 -- ;
}
return - V_6 ;
}
static int F_21 ( struct V_20 * V_7 , unsigned type )
{
struct V_54 * V_25 = V_7 -> V_25 ;
struct V_1 * V_35 ;
unsigned V_59 = 0 ;
int V_56 = 0 ;
if ( F_20 ( V_25 ) ) {
if ( V_25 -> V_32 == V_51 )
V_56 = 1 ;
if ( type == V_60 )
V_56 = ! V_56 ;
}
F_17 (c, &cdev->configs, list) {
if ( V_56 ) {
if ( ! V_35 -> V_18 )
continue;
} else {
if ( ! V_35 -> V_16 )
continue;
}
V_59 ++ ;
}
return V_59 ;
}
static void F_22 ( struct V_20 * V_7 )
{
struct V_61 * V_62 = V_7 -> V_58 -> V_33 ;
V_62 -> V_41 = sizeof( * V_62 ) ;
V_62 -> V_42 = V_60 ;
V_62 -> V_63 = V_7 -> V_64 . V_63 ;
V_62 -> V_65 = V_7 -> V_64 . V_65 ;
V_62 -> V_66 = V_7 -> V_64 . V_66 ;
V_62 -> V_67 = V_7 -> V_64 . V_67 ;
V_62 -> V_68 = V_7 -> V_64 . V_68 ;
V_62 -> V_69 = F_21 ( V_7 , V_60 ) ;
V_62 -> V_70 = 0 ;
}
static void F_23 ( struct V_20 * V_7 )
{
struct V_3 * V_40 ;
F_2 ( V_7 , L_3 ) ;
F_17 (f, &cdev->config->functions, list) {
if ( V_40 -> V_11 )
V_40 -> V_11 ( V_40 ) ;
F_24 ( V_40 -> V_71 , 32 ) ;
}
V_7 -> V_2 = NULL ;
}
static int F_25 ( struct V_20 * V_7 ,
const struct V_72 * V_73 , unsigned V_74 )
{
struct V_54 * V_25 = V_7 -> V_25 ;
struct V_1 * V_35 = NULL ;
int V_75 = - V_6 ;
unsigned V_76 = F_26 ( V_25 ) ? 8 : 100 ;
int V_77 ;
if ( V_7 -> V_2 )
F_23 ( V_7 ) ;
if ( V_74 ) {
F_17 (c, &cdev->configs, list) {
if ( V_35 -> V_44 == V_74 ) {
V_75 = 0 ;
break;
}
}
if ( V_75 < 0 )
goto V_12;
} else
V_75 = 0 ;
F_27 (cdev, L_4 ,
({ char *speed;
switch (gadget->speed) {
case USB_SPEED_LOW: speed = L_5; break;
case USB_SPEED_FULL: speed = L_6; break;
case USB_SPEED_HIGH: speed = L_7; break;
default: speed = L_8; break;
} ; speed; }), number, c ? c->label : L_9 ) ;
if ( ! V_35 )
goto V_12;
V_7 -> V_2 = V_35 ;
for ( V_77 = 0 ; V_77 < V_28 ; V_77 ++ ) {
struct V_3 * V_40 = V_35 -> V_29 [ V_77 ] ;
struct V_50 * * V_17 ;
if ( ! V_40 )
break;
if ( V_25 -> V_32 == V_51 )
V_17 = V_40 -> V_19 ;
else
V_17 = V_40 -> V_17 ;
for (; * V_17 ; ++ V_17 ) {
struct V_78 * V_79 ;
int V_80 ;
if ( ( * V_17 ) -> V_42 != V_81 )
continue;
V_79 = (struct V_78 * ) * V_17 ;
V_80 = ( ( V_79 -> V_82 & 0x80 ) >> 3 )
| ( V_79 -> V_82 & 0x0f ) ;
F_28 ( V_80 , V_40 -> V_71 ) ;
}
V_75 = V_40 -> V_10 ( V_40 , V_77 , 0 ) ;
if ( V_75 < 0 ) {
F_2 ( V_7 , L_10 ,
V_77 , V_40 -> V_8 , V_40 , V_75 ) ;
F_23 ( V_7 ) ;
goto V_12;
}
if ( V_75 == V_83 ) {
F_2 ( V_7 ,
L_11 ,
V_84 , V_77 , V_40 -> V_8 ) ;
V_7 -> V_85 ++ ;
F_2 ( V_7 , L_12 ,
V_7 -> V_85 ) ;
}
}
V_76 = V_35 -> V_48 ? ( 2 * V_35 -> V_48 ) : V_49 ;
V_12:
F_29 ( V_25 , V_76 ) ;
if ( V_75 >= 0 && V_7 -> V_85 )
V_75 = V_83 ;
return V_75 ;
}
int F_30 ( struct V_20 * V_7 ,
struct V_1 * V_2 ,
int (* V_15)( struct V_1 * ) )
{
int V_22 = - V_6 ;
struct V_1 * V_35 ;
F_2 ( V_7 , L_13 ,
V_2 -> V_44 ,
V_2 -> V_9 , V_2 ) ;
if ( ! V_2 -> V_44 || ! V_15 )
goto V_12;
F_17 (c, &cdev->configs, list) {
if ( V_35 -> V_44 == V_2 -> V_44 ) {
V_22 = - V_86 ;
goto V_12;
}
}
V_2 -> V_7 = V_7 ;
F_3 ( & V_2 -> V_13 , & V_7 -> V_87 ) ;
F_31 ( & V_2 -> V_14 ) ;
V_2 -> V_27 = 0 ;
V_22 = V_15 ( V_2 ) ;
if ( V_22 < 0 ) {
F_4 ( & V_2 -> V_13 ) ;
V_2 -> V_7 = NULL ;
} else {
unsigned V_88 ;
F_2 ( V_7 , L_14 ,
V_2 -> V_44 , V_2 ,
V_2 -> V_18 ? L_15 : L_16 ,
V_2 -> V_16
? ( F_20 ( V_7 -> V_25 )
? L_17
: L_18 )
: L_16 ) ;
for ( V_88 = 0 ; V_88 < V_28 ; V_88 ++ ) {
struct V_3 * V_40 = V_2 -> V_29 [ V_88 ] ;
if ( ! V_40 )
continue;
F_2 ( V_7 , L_19 ,
V_88 , V_40 -> V_8 , V_40 ) ;
}
}
F_32 ( V_7 -> V_25 ) ;
V_12:
if ( V_22 )
F_2 ( V_7 , L_20 , V_2 -> V_9 ,
V_2 -> V_44 , V_22 ) ;
return V_22 ;
}
static void F_33 ( struct V_89 * * V_90 , T_2 * V_33 )
{
const struct V_89 * V_91 ;
T_3 V_92 ;
T_2 * V_77 ;
while ( * V_90 ) {
V_91 = * V_90 ;
V_92 = F_18 ( V_91 -> V_92 ) ;
for ( V_77 = V_33 ; * V_77 && V_77 < & V_33 [ 126 ] ; V_77 ++ ) {
if ( * V_77 == V_92 )
goto V_93;
}
* V_77 ++ = V_92 ;
V_93:
V_90 ++ ;
}
}
static int F_34 (
struct V_89 * * V_90 ,
void * V_33 ,
T_3 V_92 ,
int V_26
)
{
struct V_89 * V_91 ;
int V_5 ;
while ( * V_90 ) {
V_91 = * V_90 ++ ;
if ( V_91 -> V_92 != V_92 )
continue;
V_5 = F_35 ( V_91 , V_26 , V_33 ) ;
if ( V_5 > 0 )
return V_5 ;
}
return - V_6 ;
}
static int F_36 ( struct V_20 * V_7 ,
void * V_33 , T_3 V_92 , int V_26 )
{
struct V_1 * V_35 ;
struct V_3 * V_40 ;
int V_38 ;
const char * V_94 ;
if ( V_26 == 0 ) {
struct V_95 * V_91 = V_33 ;
struct V_89 * * V_90 ;
memset ( V_91 , 0 , 256 ) ;
V_91 -> V_42 = V_96 ;
V_90 = V_97 -> V_98 ;
if ( V_90 )
F_33 ( V_90 , V_91 -> V_99 ) ;
F_17 (c, &cdev->configs, list) {
V_90 = V_35 -> V_98 ;
if ( V_90 )
F_33 ( V_90 , V_91 -> V_99 ) ;
F_17 (f, &c->functions, list) {
V_90 = V_40 -> V_98 ;
if ( V_90 )
F_33 ( V_90 , V_91 -> V_99 ) ;
}
}
for ( V_38 = 0 ; V_38 <= 126 && V_91 -> V_99 [ V_38 ] ; V_38 ++ )
continue;
if ( ! V_38 )
return - V_6 ;
V_91 -> V_41 = 2 * ( V_38 + 1 ) ;
return V_91 -> V_41 ;
}
if ( V_7 -> V_100 == V_26 )
V_94 = V_101 ? : V_97 -> V_101 ? :
V_102 ;
else if ( V_7 -> V_103 == V_26 )
V_94 = V_104 ? : V_97 -> V_104 ;
else if ( V_7 -> V_105 == V_26 )
V_94 = V_106 ;
else
V_94 = NULL ;
if ( V_94 ) {
struct V_89 V_98 = {
. V_92 = V_92 ,
. V_98 = & (struct V_107 ) { 0xff , V_94 }
} ;
return F_35 ( & V_98 , 0xff , V_33 ) ;
}
if ( V_97 -> V_98 ) {
V_38 = F_34 ( V_97 -> V_98 , V_33 , V_92 , V_26 ) ;
if ( V_38 > 0 )
return V_38 ;
}
F_17 (c, &cdev->configs, list) {
if ( V_35 -> V_98 ) {
V_38 = F_34 ( V_35 -> V_98 , V_33 , V_92 , V_26 ) ;
if ( V_38 > 0 )
return V_38 ;
}
F_17 (f, &c->functions, list) {
if ( ! V_40 -> V_98 )
continue;
V_38 = F_34 ( V_40 -> V_98 , V_33 , V_92 , V_26 ) ;
if ( V_38 > 0 )
return V_38 ;
}
}
return - V_6 ;
}
int F_37 ( struct V_20 * V_7 )
{
if ( V_7 -> V_108 < 254 ) {
V_7 -> V_108 ++ ;
return V_7 -> V_108 ;
}
return - V_30 ;
}
int F_38 ( struct V_20 * V_7 , struct V_107 * V_94 )
{
int V_36 = V_7 -> V_108 ;
for (; V_94 -> V_91 ; ++ V_94 ) {
if ( F_39 ( V_36 >= 254 ) )
return - V_30 ;
V_94 -> V_26 = ++ V_36 ;
}
V_7 -> V_108 = V_36 ;
return 0 ;
}
int F_40 ( struct V_20 * V_35 , unsigned V_109 )
{
unsigned V_36 = V_35 -> V_108 ;
if ( F_39 ( V_109 > 254 || ( unsigned ) V_36 + V_109 > 254 ) )
return - V_30 ;
V_35 -> V_108 += V_109 ;
return V_36 + 1 ;
}
static void F_41 ( struct V_110 * V_79 , struct V_111 * V_58 )
{
if ( V_58 -> V_22 || V_58 -> V_112 != V_58 -> V_113 )
F_2 ( (struct V_20 * ) V_79 -> V_114 ,
L_21 ,
V_58 -> V_22 , V_58 -> V_112 , V_58 -> V_113 ) ;
}
static int
F_42 ( struct V_54 * V_25 , const struct V_72 * V_73 )
{
struct V_20 * V_7 = F_43 ( V_25 ) ;
struct V_111 * V_58 = V_7 -> V_58 ;
int V_5 = - V_115 ;
T_3 V_116 = F_44 ( V_73 -> V_117 ) ;
T_1 V_118 = V_116 & 0xFF ;
T_3 V_53 = F_44 ( V_73 -> V_119 ) ;
T_3 V_120 = F_44 ( V_73 -> V_121 ) ;
struct V_3 * V_40 = NULL ;
T_1 V_122 ;
V_58 -> V_123 = 0 ;
V_58 -> V_124 = F_41 ;
V_58 -> V_113 = 0 ;
V_25 -> V_125 -> V_114 = V_7 ;
switch ( V_73 -> V_126 ) {
case V_127 :
if ( V_73 -> V_128 != V_129 )
goto V_130;
switch ( V_53 >> 8 ) {
case V_131 :
V_7 -> V_64 . V_69 =
F_21 ( V_7 , V_131 ) ;
V_5 = F_45 ( V_120 , ( T_3 ) sizeof V_7 -> V_64 ) ;
memcpy ( V_58 -> V_33 , & V_7 -> V_64 , V_5 ) ;
break;
case V_60 :
if ( ! F_20 ( V_25 ) )
break;
F_22 ( V_7 ) ;
V_5 = F_46 ( int , V_120 ,
sizeof( struct V_61 ) ) ;
break;
case V_57 :
if ( ! F_20 ( V_25 ) )
break;
case V_132 :
V_5 = F_19 ( V_7 , V_53 ) ;
if ( V_5 >= 0 )
V_5 = F_45 ( V_120 , ( T_3 ) V_5 ) ;
break;
case V_96 :
V_5 = F_36 ( V_7 , V_58 -> V_33 ,
V_116 , V_53 & 0xff ) ;
if ( V_5 >= 0 )
V_5 = F_45 ( V_120 , ( T_3 ) V_5 ) ;
break;
}
break;
case V_133 :
if ( V_73 -> V_128 != 0 )
goto V_130;
if ( F_26 ( V_25 ) ) {
if ( V_25 -> V_134 )
F_2 ( V_7 , L_22 ) ;
else if ( V_25 -> V_135 )
F_2 ( V_7 , L_23 ) ;
else
F_47 ( V_7 , L_24 ) ;
}
F_10 ( & V_7 -> V_23 ) ;
V_5 = F_25 ( V_7 , V_73 , V_53 ) ;
F_13 ( & V_7 -> V_23 ) ;
break;
case V_136 :
if ( V_73 -> V_128 != V_129 )
goto V_130;
if ( V_7 -> V_2 )
* ( T_1 * ) V_58 -> V_33 = V_7 -> V_2 -> V_44 ;
else
* ( T_1 * ) V_58 -> V_33 = 0 ;
V_5 = F_45 ( V_120 , ( T_3 ) 1 ) ;
break;
case V_137 :
if ( V_73 -> V_128 != V_138 )
goto V_130;
if ( ! V_7 -> V_2 || V_118 >= V_28 )
break;
V_40 = V_7 -> V_2 -> V_29 [ V_118 ] ;
if ( ! V_40 )
break;
if ( V_53 && ! V_40 -> V_10 )
break;
V_5 = V_40 -> V_10 ( V_40 , V_116 , V_53 ) ;
if ( V_5 == V_83 ) {
F_2 ( V_7 ,
L_11 ,
V_84 , V_118 , V_40 -> V_8 ) ;
V_7 -> V_85 ++ ;
F_2 ( V_7 , L_12 ,
V_7 -> V_85 ) ;
}
break;
case V_139 :
if ( V_73 -> V_128 != ( V_129 | V_138 ) )
goto V_130;
if ( ! V_7 -> V_2 || V_118 >= V_28 )
break;
V_40 = V_7 -> V_2 -> V_29 [ V_118 ] ;
if ( ! V_40 )
break;
V_5 = V_40 -> V_140 ? V_40 -> V_140 ( V_40 , V_116 ) : 0 ;
if ( V_5 < 0 )
break;
* ( ( T_1 * ) V_58 -> V_33 ) = V_5 ;
V_5 = F_45 ( V_120 , ( T_3 ) 1 ) ;
break;
default:
V_130:
F_47 ( V_7 ,
L_25 ,
V_73 -> V_128 , V_73 -> V_126 ,
V_53 , V_116 , V_120 ) ;
switch ( V_73 -> V_128 & V_141 ) {
case V_138 :
if ( ! V_7 -> V_2 || V_118 >= V_28 )
break;
V_40 = V_7 -> V_2 -> V_29 [ V_118 ] ;
break;
case V_142 :
V_122 = ( ( V_116 & 0x80 ) >> 3 ) | ( V_116 & 0x0f ) ;
F_17 (f, &cdev->config->functions, list) {
if ( F_48 ( V_122 , V_40 -> V_71 ) )
break;
}
if ( & V_40 -> V_13 == & V_7 -> V_2 -> V_14 )
V_40 = NULL ;
break;
}
if ( V_40 && V_40 -> V_143 )
V_5 = V_40 -> V_143 ( V_40 , V_73 ) ;
else {
struct V_1 * V_35 ;
V_35 = V_7 -> V_2 ;
if ( V_35 && V_35 -> V_143 )
V_5 = V_35 -> V_143 ( V_35 , V_73 ) ;
}
goto V_12;
}
if ( V_5 >= 0 && V_5 != V_83 ) {
V_58 -> V_113 = V_5 ;
V_58 -> V_123 = V_5 < V_120 ;
V_5 = F_49 ( V_25 -> V_125 , V_58 , V_144 ) ;
if ( V_5 < 0 ) {
F_2 ( V_7 , L_26 , V_5 ) ;
V_58 -> V_22 = 0 ;
F_41 ( V_25 -> V_125 , V_58 ) ;
}
} else if ( V_5 == V_83 && V_120 != 0 ) {
F_50 ( V_7 ,
L_27 ,
V_84 ) ;
}
V_12:
return V_5 ;
}
static void F_51 ( struct V_54 * V_25 )
{
struct V_20 * V_7 = F_43 ( V_25 ) ;
unsigned long V_21 ;
F_6 ( & V_7 -> V_23 , V_21 ) ;
if ( V_7 -> V_2 )
F_23 ( V_7 ) ;
if ( V_97 -> V_145 )
V_97 -> V_145 ( V_7 ) ;
F_8 ( & V_7 -> V_23 , V_21 ) ;
}
static T_4 F_52 ( struct V_146 * V_147 ,
struct V_148 * V_149 ,
char * V_33 )
{
struct V_54 * V_25 = F_53 ( V_147 ) ;
struct V_20 * V_7 = F_43 ( V_25 ) ;
return sprintf ( V_33 , L_28 , V_7 -> V_150 ) ;
}
static void
F_54 ( struct V_54 * V_25 )
{
struct V_20 * V_7 = F_43 ( V_25 ) ;
F_11 ( V_7 -> V_2 ) ;
while ( ! F_55 ( & V_7 -> V_87 ) ) {
struct V_1 * V_35 ;
V_35 = F_56 ( & V_7 -> V_87 ,
struct V_1 , V_13 ) ;
while ( ! F_55 ( & V_35 -> V_14 ) ) {
struct V_3 * V_40 ;
V_40 = F_56 ( & V_35 -> V_14 ,
struct V_3 , V_13 ) ;
F_4 ( & V_40 -> V_13 ) ;
if ( V_40 -> V_151 ) {
F_2 ( V_7 , L_29 ,
V_40 -> V_8 , V_40 ) ;
V_40 -> V_151 ( V_35 , V_40 ) ;
}
}
F_4 ( & V_35 -> V_13 ) ;
if ( V_35 -> V_151 ) {
F_2 ( V_7 , L_30 , V_35 -> V_9 , V_35 ) ;
V_35 -> V_151 ( V_35 ) ;
}
}
if ( V_97 -> V_151 )
V_97 -> V_151 ( V_7 ) ;
if ( V_7 -> V_58 ) {
F_57 ( V_7 -> V_58 -> V_33 ) ;
F_58 ( V_25 -> V_125 , V_7 -> V_58 ) ;
}
F_59 ( & V_25 -> V_147 , & V_152 ) ;
F_57 ( V_7 ) ;
F_60 ( V_25 , NULL ) ;
V_97 = NULL ;
}
static T_1 F_61 ( struct V_20 * V_7 , T_1 * V_64 )
{
if ( ! * V_64 ) {
int V_153 = F_37 ( V_7 ) ;
if ( F_39 ( V_153 < 0 ) )
F_62 ( V_7 , L_31 ) ;
else
* V_64 = V_153 ;
}
return * V_64 ;
}
static int F_63 ( struct V_54 * V_25 )
{
struct V_20 * V_7 ;
int V_22 = - V_154 ;
V_7 = F_64 ( sizeof *V_7 , V_155 ) ;
if ( ! V_7 )
return V_22 ;
F_65 ( & V_7 -> V_23 ) ;
V_7 -> V_25 = V_25 ;
F_60 ( V_25 , V_7 ) ;
F_31 ( & V_7 -> V_87 ) ;
V_7 -> V_58 = F_66 ( V_25 -> V_125 , V_155 ) ;
if ( ! V_7 -> V_58 )
goto V_156;
V_7 -> V_58 -> V_33 = F_67 ( V_39 , V_155 ) ;
if ( ! V_7 -> V_58 -> V_33 )
goto V_156;
V_7 -> V_58 -> V_124 = F_41 ;
V_25 -> V_125 -> V_114 = V_7 ;
V_7 -> V_157 = V_39 ;
V_7 -> V_158 = V_97 ;
if ( V_49 <= V_159 )
F_68 ( V_25 ) ;
F_32 ( V_7 -> V_25 ) ;
V_22 = F_69 ( V_7 ) ;
if ( V_22 < 0 )
goto V_156;
V_7 -> V_64 = * V_97 -> V_147 ;
V_7 -> V_64 . V_68 = V_25 -> V_125 -> V_160 ;
if ( V_161 )
V_7 -> V_64 . V_161 = F_18 ( V_161 ) ;
if ( V_162 )
V_7 -> V_64 . V_162 = F_18 ( V_162 ) ;
if ( V_163 )
V_7 -> V_64 . V_163 = F_18 ( V_163 ) ;
if ( V_101 || ! V_7 -> V_64 . V_101 ) {
if ( ! V_101 && ! V_97 -> V_101 &&
! * V_102 )
snprintf ( V_102 ,
sizeof V_102 ,
L_32 ,
F_70 () -> V_164 ,
F_70 () -> V_165 ,
V_25 -> V_8 ) ;
V_7 -> V_100 =
F_61 ( V_7 , & V_7 -> V_64 . V_101 ) ;
}
if ( V_104 || ( ! V_7 -> V_64 . V_104 && V_97 -> V_104 ) )
V_7 -> V_103 =
F_61 ( V_7 , & V_7 -> V_64 . V_104 ) ;
if ( V_106 )
V_7 -> V_105 =
F_61 ( V_7 , & V_7 -> V_64 . V_106 ) ;
if ( V_97 -> V_166 && ! V_7 -> V_64 . V_106 )
F_62 ( V_7 , L_33 ) ;
V_22 = F_71 ( & V_25 -> V_147 , & V_152 ) ;
if ( V_22 )
goto V_156;
F_27 ( V_7 , L_34 , V_97 -> V_8 ) ;
return 0 ;
V_156:
F_54 ( V_25 ) ;
return V_22 ;
}
static void
F_72 ( struct V_54 * V_25 )
{
struct V_20 * V_7 = F_43 ( V_25 ) ;
struct V_3 * V_40 ;
F_2 ( V_7 , L_35 ) ;
if ( V_7 -> V_2 ) {
F_17 (f, &cdev->config->functions, list) {
if ( V_40 -> V_167 )
V_40 -> V_167 ( V_40 ) ;
}
}
if ( V_97 -> V_167 )
V_97 -> V_167 ( V_7 ) ;
V_7 -> V_150 = 1 ;
F_29 ( V_25 , 2 ) ;
}
static void
F_73 ( struct V_54 * V_25 )
{
struct V_20 * V_7 = F_43 ( V_25 ) ;
struct V_3 * V_40 ;
T_1 V_168 ;
F_2 ( V_7 , L_36 ) ;
if ( V_97 -> V_169 )
V_97 -> V_169 ( V_7 ) ;
if ( V_7 -> V_2 ) {
F_17 (f, &cdev->config->functions, list) {
if ( V_40 -> V_169 )
V_40 -> V_169 ( V_40 ) ;
}
V_168 = V_7 -> V_2 -> V_48 ;
F_29 ( V_25 , V_168 ?
( 2 * V_168 ) : V_49 ) ;
}
V_7 -> V_150 = 0 ;
}
int F_74 ( struct V_170 * V_158 ,
int (* V_15)( struct V_20 * V_7 ) )
{
if ( ! V_158 || ! V_158 -> V_147 || ! V_15 || V_97 )
return - V_6 ;
if ( ! V_158 -> V_8 )
V_158 -> V_8 = L_37 ;
if ( ! V_158 -> V_104 )
V_158 -> V_104 = V_158 -> V_8 ;
V_171 . V_4 = ( char * ) V_158 -> V_8 ;
V_171 . V_158 . V_8 = V_158 -> V_8 ;
V_97 = V_158 ;
F_69 = V_15 ;
return F_75 ( & V_171 , F_63 ) ;
}
void F_76 ( struct V_170 * V_158 )
{
if ( V_97 != V_158 )
return;
F_77 ( & V_171 ) ;
}
void F_78 ( struct V_20 * V_7 )
{
int V_5 ;
struct V_111 * V_58 = V_7 -> V_58 ;
unsigned long V_21 ;
F_2 ( V_7 , L_38 , V_84 ) ;
F_6 ( & V_7 -> V_23 , V_21 ) ;
if ( V_7 -> V_85 == 0 ) {
F_50 ( V_7 , L_39 , V_84 ) ;
} else if ( -- V_7 -> V_85 == 0 ) {
F_2 ( V_7 , L_40 , V_84 ) ;
V_58 -> V_113 = 0 ;
V_5 = F_49 ( V_7 -> V_25 -> V_125 , V_58 , V_144 ) ;
if ( V_5 < 0 ) {
F_2 ( V_7 , L_26 , V_5 ) ;
V_58 -> V_22 = 0 ;
F_41 ( V_7 -> V_25 -> V_125 , V_58 ) ;
}
}
F_8 ( & V_7 -> V_23 , V_21 ) ;
}
