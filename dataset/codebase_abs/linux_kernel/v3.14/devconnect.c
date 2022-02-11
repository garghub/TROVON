static void F_1 ( struct V_1 * V_1 )
{
F_2 ( V_1 ) ;
}
static struct V_1 * F_3 ( struct V_2 * V_2 )
{
struct V_1 * V_1 ;
V_1 = F_4 ( sizeof( * V_1 ) , V_3 ) ;
if ( V_1 == NULL )
goto V_4;
V_1 -> V_2 = V_2 ;
F_5 ( & V_1 -> V_5 , V_6 ) ;
return V_1 ;
V_4:
F_1 ( V_1 ) ;
return NULL ;
}
static void F_6 ( struct V_2 * V_2 )
{
unsigned V_7 ;
struct V_1 * V_8 ;
struct V_9 * V_10 ;
V_10 = & V_2 -> V_10 ;
V_7 = 0 ;
F_7 (dev_itr, &wusbhc->cack_list, cack_node) {
V_10 -> V_11 [ V_7 ] . V_12 = V_8 -> V_13 ;
V_10 -> V_11 [ V_7 ] . V_14 = V_8 -> V_15 ;
if ( ++ V_7 >= V_16 )
break;
}
V_10 -> V_17 . V_18 = sizeof( V_10 -> V_17 )
+ V_7 * sizeof( V_10 -> V_11 [ 0 ] ) ;
}
static struct V_1 * F_8 ( struct V_2 * V_2 ,
struct V_19 * V_20 ,
const char * V_21 , T_1 V_22 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_1 * V_1 ;
int V_25 = F_9 ( V_20 ) ;
T_1 V_26 ;
int V_27 ;
F_7 (wusb_dev, &wusbhc->cack_list, cack_node)
if ( ! memcmp ( & V_1 -> V_13 , & V_20 -> V_12 ,
sizeof( V_1 -> V_13 ) ) )
return V_1 ;
V_1 = F_3 ( V_2 ) ;
if ( V_1 == NULL )
return NULL ;
F_10 ( V_1 ) ;
V_1 -> V_13 = V_20 -> V_12 ;
V_1 -> V_22 = V_22 ;
F_11 ( V_1 -> V_28 . V_29 , V_30 ) ;
if ( 1 && V_25 == 0 )
V_25 = 1 ;
if ( V_25 ) {
V_26 = ( V_22 + 2 ) | V_31 ;
F_12 ( V_24 , L_1
L_2 , V_26 , V_22 ) ;
V_27 = F_13 ( V_2 , V_1 , V_26 ) ;
if ( V_27 < 0 )
return NULL ;
}
V_1 -> V_32 = V_33 ;
F_14 ( & V_1 -> V_34 , & V_2 -> V_35 ) ;
V_2 -> V_36 ++ ;
F_6 ( V_2 ) ;
return V_1 ;
}
static void F_15 ( struct V_2 * V_2 , struct V_1 * V_1 )
{
F_16 ( & V_1 -> V_34 ) ;
V_2 -> V_36 -- ;
F_6 ( V_2 ) ;
}
static
void F_17 ( struct V_2 * V_2 , struct V_1 * V_1 )
{
F_15 ( V_2 , V_1 ) ;
if ( V_2 -> V_36 )
F_18 ( V_2 , 0 , 0 , & V_2 -> V_10 . V_17 ) ;
else
F_19 ( V_2 , & V_2 -> V_10 . V_17 ) ;
}
static void V_6 ( struct V_37 * V_38 )
{
struct V_1 * V_1 = F_20 ( V_38 , struct V_1 ,
V_5 ) ;
struct V_2 * V_2 = V_1 -> V_2 ;
F_21 ( & V_2 -> V_39 ) ;
F_17 ( V_2 , V_1 ) ;
F_22 ( & V_2 -> V_39 ) ;
F_23 ( V_1 ) ;
}
static
void F_24 ( struct V_2 * V_2 , struct V_19 * V_20 ,
const char * V_21 )
{
int V_27 ;
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_1 * V_1 ;
struct V_40 * V_41 ;
unsigned V_42 , V_43 ;
F_21 ( & V_2 -> V_39 ) ;
for ( V_42 = 0 ; V_42 < V_2 -> V_44 ; V_42 ++ ) {
V_41 = F_25 ( V_2 , V_42 ) ;
if ( V_41 -> V_1
&& memcmp ( & V_20 -> V_12 , & V_41 -> V_1 -> V_13 , sizeof( V_20 -> V_12 ) ) == 0 )
goto V_45;
}
for ( V_42 = 0 ; V_42 < V_2 -> V_44 ; V_42 ++ ) {
V_41 = F_25 ( V_2 , V_42 ) ;
if ( ( V_41 -> V_46 & V_47 )
&& ! ( V_41 -> V_46 & V_48 ) )
break;
}
if ( V_42 >= V_2 -> V_44 ) {
F_26 ( V_24 , L_3
L_4 ,
V_2 -> V_44 , V_21 ) ;
goto V_45;
}
V_43 = V_42 + 2 ;
V_2 -> V_49 ( V_2 , V_42 , 0 , NULL , 0 ) ;
V_1 = F_8 ( V_2 , V_20 , V_21 , V_42 ) ;
if ( V_1 == NULL )
goto V_45;
V_27 = F_18 ( V_2 , 0 , 0 , & V_2 -> V_10 . V_17 ) ;
if ( V_27 < 0 )
goto V_45;
F_27 ( 3 ) ;
V_41 -> V_1 = V_1 ;
V_41 -> V_46 |= V_48 ;
V_41 -> V_50 |= V_51 ;
V_45:
F_22 ( & V_2 -> V_39 ) ;
return;
}
static void F_28 ( struct V_2 * V_2 ,
struct V_40 * V_41 )
{
struct V_1 * V_1 = V_41 -> V_1 ;
V_41 -> V_46 &= ~ ( V_48 | V_52
| V_53 | V_54
| V_55 | V_56 ) ;
V_41 -> V_50 |= V_51 | V_57 ;
if ( V_1 ) {
F_29 ( V_2 -> V_24 , L_5 , V_1 -> V_22 ) ;
if ( ! F_30 ( & V_1 -> V_34 ) )
F_16 ( & V_1 -> V_34 ) ;
F_23 ( V_1 ) ;
}
V_41 -> V_1 = NULL ;
if ( V_2 -> V_58 )
F_31 ( V_2 ) ;
}
static void F_32 ( struct V_2 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
unsigned V_7 ;
struct V_1 * V_1 ;
struct V_40 * V_40 ;
struct V_59 * V_60 = & V_2 -> V_61 ;
unsigned V_62 , V_63 ;
V_63 = V_60 -> V_17 . V_18 - sizeof( V_60 -> V_17 ) ;
V_62 = 0 ;
for ( V_7 = 0 ;
V_62 < V_16 && V_7 < V_2 -> V_44 ;
V_7 ++ ) {
unsigned V_64 = F_33 ( V_2 -> V_65 ) ;
V_40 = F_25 ( V_2 , V_7 ) ;
V_1 = V_40 -> V_1 ;
if ( V_1 == NULL )
continue;
if ( V_1 -> V_66 == NULL )
continue;
if ( F_34 ( V_33 , V_1 -> V_32 + V_64 ) ) {
F_26 ( V_24 , L_6 ,
V_1 -> V_15 ) ;
F_28 ( V_2 , V_40 ) ;
} else if ( F_34 ( V_33 , V_1 -> V_32 + V_64 / 3 ) ) {
V_60 -> V_14 [ V_62 ++ ] = V_1 -> V_15 ;
}
}
if ( V_62 & 0x1 )
V_60 -> V_14 [ V_62 ++ ] = 0x7f ;
V_60 -> V_17 . V_18 = sizeof( V_60 -> V_17 ) +
V_62 * sizeof( V_60 -> V_14 [ 0 ] ) ;
if ( V_62 > 0 )
F_18 ( V_2 , 10 , 5 , & V_60 -> V_17 ) ;
else if ( V_63 != 0 )
F_19 ( V_2 , & V_60 -> V_17 ) ;
}
static void F_35 ( struct V_37 * V_67 )
{
struct V_68 * V_69 = F_36 ( V_67 ) ;
struct V_2 * V_2 = F_20 ( V_69 , struct V_2 , V_70 ) ;
F_21 ( & V_2 -> V_39 ) ;
F_32 ( V_2 ) ;
F_22 ( & V_2 -> V_39 ) ;
F_37 ( V_71 , & V_2 -> V_70 ,
F_33 ( V_2 -> V_65 / 2 ) ) ;
}
static struct V_1 * F_38 ( struct V_2 * V_2 , T_1 V_15 )
{
int V_72 ;
if ( V_15 == 0xff )
return NULL ;
if ( V_15 > 0 ) {
int V_41 = ( V_15 & ~ 0x80 ) - 2 ;
if ( V_41 < 0 || V_41 >= V_2 -> V_44 )
return NULL ;
return F_25 ( V_2 , V_41 ) -> V_1 ;
}
for ( V_72 = 0 ; V_72 < V_2 -> V_44 ; V_72 ++ ) {
struct V_1 * V_1 = F_25 ( V_2 , V_72 ) -> V_1 ;
if ( V_1 && V_1 -> V_15 == V_15 )
return V_1 ;
}
return NULL ;
}
static void F_39 ( struct V_2 * V_2 , T_1 V_73 )
{
struct V_1 * V_1 ;
F_21 ( & V_2 -> V_39 ) ;
V_1 = F_38 ( V_2 , V_73 ) ;
if ( V_1 == NULL ) {
F_29 ( V_2 -> V_24 , L_7 ,
V_73 ) ;
} else {
V_1 -> V_32 = V_33 ;
F_32 ( V_2 ) ;
}
F_22 ( & V_2 -> V_39 ) ;
}
static void F_40 ( struct V_2 * V_2 ,
struct V_74 * V_75 ,
T_2 V_76 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_19 * V_20 ;
char V_21 [ V_77 ] ;
static const char * V_78 [] = {
L_8 ,
L_9 ,
L_10 ,
L_11
} ;
if ( V_76 < sizeof( * V_20 ) ) {
F_26 ( V_24 , L_12 ,
V_76 , sizeof( * V_20 ) ) ;
return;
}
V_20 = F_20 ( V_75 , struct V_19 , V_17 ) ;
F_41 ( V_21 , sizeof( V_21 ) , & V_20 -> V_12 ) ;
F_12 ( V_24 , L_13 ,
V_21 ,
F_42 ( V_20 ) ,
V_78 [ F_43 ( V_20 ) ] ,
F_9 ( V_20 ) ? L_14 : L_15 ) ;
F_24 ( V_2 , V_20 , V_21 ) ;
}
static void F_44 ( struct V_2 * V_2 , T_1 V_73 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_1 * V_1 ;
F_21 ( & V_2 -> V_39 ) ;
V_1 = F_38 ( V_2 , V_73 ) ;
if ( V_1 == NULL ) {
F_29 ( V_24 , L_16 ,
V_73 ) ;
} else {
F_12 ( V_24 , L_17 ,
V_1 -> V_15 ) ;
F_28 ( V_2 , F_25 ( V_2 ,
V_1 -> V_22 ) ) ;
}
F_22 ( & V_2 -> V_39 ) ;
}
void F_45 ( struct V_2 * V_2 , T_1 V_73 ,
struct V_74 * V_75 , T_2 V_76 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
if ( V_76 < sizeof( struct V_74 ) ) {
F_26 ( V_24 , L_18 ,
( int ) V_76 , ( int ) sizeof( struct V_74 ) ) ;
return;
}
switch ( V_75 -> V_79 ) {
case V_80 :
F_40 ( V_2 , V_75 , V_76 ) ;
break;
case V_81 :
F_39 ( V_2 , V_73 ) ;
break;
case V_82 :
F_44 ( V_2 , V_73 ) ;
break;
case V_83 :
case V_84 :
case V_85 :
break;
case V_86 :
break;
default:
F_46 ( V_24 , L_19 ,
V_75 -> V_79 , ( int ) V_76 , V_73 ) ;
}
}
void F_47 ( struct V_2 * V_2 , T_1 V_22 )
{
int V_27 ;
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_1 * V_1 ;
struct V_87 * V_60 ;
V_1 = F_25 ( V_2 , V_22 ) -> V_1 ;
if ( V_1 == NULL ) {
F_29 ( V_24 , L_20 ,
V_22 ) ;
return;
}
F_28 ( V_2 , F_25 ( V_2 , V_22 ) ) ;
V_60 = F_4 ( sizeof( * V_60 ) , V_3 ) ;
if ( V_60 == NULL )
return;
V_60 -> V_17 . V_18 = sizeof( * V_60 ) ;
V_60 -> V_17 . V_88 = V_89 ;
V_60 -> V_14 = V_1 -> V_15 ;
V_27 = F_18 ( V_2 , 0 , 0 , & V_60 -> V_17 ) ;
if ( V_27 < 0 )
F_26 ( V_24 , L_21 , V_27 ) ;
else {
F_27 ( 7 * 4 ) ;
F_19 ( V_2 , & V_60 -> V_17 ) ;
}
F_2 ( V_60 ) ;
}
static int F_48 ( struct V_90 * V_66 ,
struct V_1 * V_1 ,
struct V_91 * V_92 , T_2 V_93 )
{
T_3 V_27 ;
struct V_23 * V_24 = & V_66 -> V_24 ;
void * V_94 , * V_95 ;
V_94 = ( void * ) V_92 + sizeof( * V_92 ) ;
V_95 = V_94 + V_93 - sizeof( * V_92 ) ;
while ( V_94 < V_95 ) {
struct V_96 * V_97 = V_94 ;
T_2 V_98 ;
T_1 V_99 ;
if ( V_95 - V_94 < sizeof( * V_97 ) ) {
F_26 ( V_24 , L_22
L_23 ,
( int ) ( V_94 - ( void * ) V_92 ) , V_95 - V_94 ) ;
V_27 = - V_100 ;
goto V_101;
}
V_98 = V_97 -> V_18 ;
V_99 = V_97 -> V_102 ;
if ( V_98 == 0 )
break;
if ( V_98 > V_95 - V_94 ) {
F_26 ( V_24 , L_24
L_25
L_26 ,
( int ) ( V_94 - ( void * ) V_92 ) ,
V_99 , V_98 , V_95 - V_94 ) ;
V_27 = - V_103 ;
goto V_101;
}
switch ( V_99 ) {
case V_104 :
if ( V_98 != sizeof( * V_1 -> V_105 ) )
F_26 ( V_24 , L_27
L_28
L_29 , V_98 ,
sizeof( * V_1 -> V_105 ) ) ;
else
V_1 -> V_105 = V_94 ;
break;
default:
F_26 ( V_24 , L_30
L_31 , V_99 ,
V_98 , ( int ) ( V_94 - ( void * ) V_92 ) ) ;
}
V_94 += V_98 ;
}
V_27 = 0 ;
V_101:
return V_27 ;
}
static int F_49 ( struct V_90 * V_66 ,
struct V_1 * V_1 )
{
T_3 V_27 ;
struct V_23 * V_24 = & V_66 -> V_24 ;
struct V_91 * V_92 ;
T_2 V_106 = 32 , V_93 = 4 ;
V_92 = F_50 ( V_106 , V_3 ) ;
if ( V_92 == NULL )
return - V_107 ;
V_27 = F_51 ( V_66 , V_108 , 0 , V_92 , V_93 ) ;
if ( V_27 < 4 ) {
F_26 ( V_24 , L_32 ,
V_27 ) ;
goto V_109;
}
V_93 = F_52 ( V_92 -> V_110 ) ;
if ( V_93 >= V_106 ) {
F_2 ( V_92 ) ;
V_106 = V_93 ;
V_92 = F_50 ( V_106 , V_3 ) ;
if ( V_92 == NULL )
return - V_107 ;
}
V_27 = F_51 ( V_66 , V_108 , 0 , V_92 , V_93 ) ;
if ( V_27 < 0 || V_27 != V_93 ) {
F_26 ( V_24 , L_33
L_34 , V_93 , V_27 ) ;
goto V_109;
}
if ( V_27 < sizeof( * V_92 )
|| F_52 ( V_92 -> V_110 ) != V_93 ) {
F_26 ( V_24 , L_33
L_34 , V_93 , V_27 ) ;
goto V_109;
}
V_27 = F_48 ( V_66 , V_1 , V_92 , V_27 ) ;
if ( V_27 < 0 )
goto V_111;
V_1 -> V_92 = V_92 ;
return 0 ;
V_111:
V_109:
F_2 ( V_92 ) ;
V_1 -> V_105 = NULL ;
return V_27 ;
}
static void F_53 ( struct V_1 * V_1 )
{
F_2 ( V_1 -> V_92 ) ;
V_1 -> V_105 = NULL ;
}
static void F_54 ( struct V_90 * V_66 )
{
int V_27 = 0 ;
struct V_1 * V_1 ;
struct V_2 * V_2 ;
struct V_23 * V_24 = & V_66 -> V_24 ;
T_1 V_22 ;
if ( V_66 -> V_112 == 0 || V_66 -> V_43 == 1 )
return;
F_55 ( V_66 , V_113 ) ;
V_2 = F_56 ( V_66 ) ;
if ( V_2 == NULL )
goto V_114;
F_21 ( & V_2 -> V_39 ) ;
V_1 = F_57 ( V_2 , V_66 ) ;
V_22 = F_58 ( V_66 -> V_115 ) ;
F_22 ( & V_2 -> V_39 ) ;
if ( V_1 == NULL )
goto V_114;
V_1 -> V_66 = F_59 ( V_66 ) ;
V_66 -> V_1 = F_60 ( V_1 ) ;
V_27 = F_61 ( V_2 , V_66 , V_1 ) ;
if ( V_27 < 0 ) {
F_26 ( V_24 , L_35 , V_27 ) ;
goto V_116;
}
V_27 = F_49 ( V_66 , V_1 ) ;
if ( V_27 < 0 ) {
F_26 ( V_24 , L_36 , V_27 ) ;
goto V_117;
}
V_27 = F_62 ( V_2 , V_66 , V_1 ) ;
if ( V_27 < 0 )
goto V_118;
V_119:
F_23 ( V_1 ) ;
F_63 ( V_2 ) ;
V_114:
return;
F_64 ( V_1 ) ;
V_118:
F_53 ( V_1 ) ;
V_117:
F_65 ( V_1 ) ;
V_116:
F_21 ( & V_2 -> V_39 ) ;
F_28 ( V_2 , F_25 ( V_2 , V_22 ) ) ;
F_22 ( & V_2 -> V_39 ) ;
goto V_119;
}
static void F_66 ( struct V_90 * V_66 )
{
struct V_1 * V_1 = V_66 -> V_1 ;
if ( V_66 -> V_112 == 0 || V_66 -> V_43 == 1 )
return;
F_64 ( V_1 ) ;
F_53 ( V_1 ) ;
F_65 ( V_1 ) ;
V_1 -> V_66 = NULL ;
V_66 -> V_1 = NULL ;
F_23 ( V_1 ) ;
F_67 ( V_66 ) ;
}
int F_68 ( struct V_120 * V_121 , unsigned long V_122 ,
void * V_123 )
{
int V_27 = V_124 ;
switch ( V_122 ) {
case V_125 :
F_54 ( V_123 ) ;
break;
case V_126 :
F_66 ( V_123 ) ;
break;
case V_127 :
case V_128 :
break;
default:
F_69 ( 1 ) ;
V_27 = V_129 ;
}
return V_27 ;
}
struct V_1 * F_57 ( struct V_2 * V_2 ,
struct V_90 * V_66 )
{
struct V_1 * V_1 ;
T_1 V_22 ;
V_22 = F_58 ( V_66 -> V_115 ) ;
F_70 ( V_22 > V_2 -> V_44 ) ;
V_1 = F_25 ( V_2 , V_22 ) -> V_1 ;
if ( V_1 != NULL )
F_60 ( V_1 ) ;
return V_1 ;
}
void F_71 ( struct V_130 * V_131 )
{
struct V_1 * V_1 = F_20 ( V_131 , struct V_1 , V_132 ) ;
F_16 ( & V_1 -> V_34 ) ;
F_1 ( V_1 ) ;
}
int F_72 ( struct V_2 * V_2 )
{
V_2 -> V_61 . V_17 . V_88 = V_133 ;
V_2 -> V_61 . V_17 . V_18 = sizeof( V_2 -> V_61 . V_17 ) ;
F_73 ( & V_2 -> V_70 , F_35 ) ;
V_2 -> V_10 . V_17 . V_88 = V_134 ;
V_2 -> V_10 . V_17 . V_18 = sizeof( V_2 -> V_10 . V_17 ) ;
F_74 ( & V_2 -> V_35 ) ;
return 0 ;
}
void F_75 ( struct V_2 * V_2 )
{
}
int F_76 ( struct V_2 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_135 * V_136 ;
int V_27 ;
V_136 = F_4 ( sizeof( * V_136 ) , V_3 ) ;
if ( V_136 == NULL )
return - V_107 ;
V_136 -> V_17 . V_18 = sizeof( * V_136 ) ;
V_136 -> V_17 . V_88 = V_137 ;
V_136 -> V_138 = F_77 ( ( V_2 -> V_139 -> V_140 << 3 ) | V_141 ) ;
V_136 -> V_142 = V_2 -> V_143 ;
V_27 = F_18 ( V_2 , 0 , 0 , & V_136 -> V_17 ) ;
if ( V_27 < 0 ) {
F_26 ( V_24 , L_37 , V_27 ) ;
goto V_144;
}
V_2 -> V_135 = V_136 ;
F_37 ( V_71 , & V_2 -> V_70 ,
F_33 ( V_2 -> V_65 / 2 ) ) ;
return 0 ;
V_144:
F_2 ( V_136 ) ;
return V_27 ;
}
void F_78 ( struct V_2 * V_2 )
{
int V_145 ;
F_21 ( & V_2 -> V_39 ) ;
for ( V_145 = 0 ; V_145 < V_2 -> V_44 ; V_145 ++ ) {
if ( V_2 -> V_41 [ V_145 ] . V_1 )
F_28 ( V_2 , & V_2 -> V_41 [ V_145 ] ) ;
}
F_22 ( & V_2 -> V_39 ) ;
F_79 ( & V_2 -> V_70 ) ;
F_19 ( V_2 , & V_2 -> V_135 -> V_17 ) ;
F_2 ( V_2 -> V_135 ) ;
V_2 -> V_135 = NULL ;
}
int F_13 ( struct V_2 * V_2 , struct V_1 * V_1 , T_1 V_15 )
{
int V_27 ;
V_1 -> V_15 = V_15 ;
V_27 = V_2 -> V_146 ( V_2 , V_1 ) ;
if ( V_27 < 0 )
F_26 ( V_2 -> V_24 , L_38
L_39 , V_1 -> V_22 ) ;
else
F_12 ( V_2 -> V_24 , L_40 ,
V_1 -> V_22 ,
( V_15 & V_31 ) ? L_41 : L_42 ,
V_1 -> V_15 ) ;
return V_27 ;
}
