static struct V_1 *
F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
int V_5 , V_6 ;
struct V_1 * V_7 ;
T_2 V_8 = 0 ;
T_3 V_9 ;
V_7 = F_2 ( sizeof( struct V_1 ) , V_10 ) ;
if ( ! V_7 ) {
F_3 ( V_3 , L_1 ) ;
return NULL ;
}
if ( V_3 -> V_11 == V_12 )
V_6 = V_13 ;
else
V_6 = V_14 ;
if ( V_6 >= V_15 && V_6 <= V_16 )
V_8 |= V_17 ;
V_8 |= F_4 ( V_3 -> V_18 . V_19 ) <<
V_20 ;
V_9 = F_5 ( V_21 [ V_6 ] . V_22 ,
V_8 ) ;
for ( V_5 = 0 ; V_5 < V_23 ; V_5 ++ )
V_7 -> V_24 [ V_5 ] . V_9 = V_9 ;
V_7 -> V_25 . V_26 =
F_4 ( V_3 -> V_18 . V_19 ) ;
V_7 -> V_25 . V_27 =
V_3 -> V_18 . V_19 &
~ F_4 ( V_3 -> V_18 . V_19 ) ;
if ( ! V_7 -> V_25 . V_27 ) {
V_7 -> V_25 . V_27 = V_28 ;
} else if ( F_6 ( V_3 -> V_18 . V_19 ) == 2 ) {
V_7 -> V_25 . V_27 =
V_3 -> V_18 . V_19 ;
}
V_7 -> V_29 . V_30 = V_31 ;
V_7 -> V_29 . V_32 =
F_7 ( V_33 ) ;
V_7 -> V_4 = V_4 ;
return V_7 ;
}
int
F_8 ( struct V_2 * V_3 , struct V_34 * V_35 ,
const T_1 * V_36 , T_1 * V_37 )
{
int V_38 ;
T_1 V_4 ;
struct V_1 * V_7 ;
unsigned long V_39 ;
if ( V_37 )
* V_37 = V_40 ;
V_38 = F_9 ( V_3 , V_35 , V_36 , 0 , NULL , & V_4 ) ;
if ( V_38 ) {
F_3 ( V_3 , L_2 , V_36 ) ;
return V_38 ;
}
if ( V_37 )
* V_37 = V_4 ;
F_10 ( & V_3 -> V_41 , V_39 ) ;
V_3 -> V_42 [ V_4 ] . V_43 |= V_44 ;
F_11 ( & V_3 -> V_41 , V_39 ) ;
V_7 = F_1 ( V_3 , V_4 ) ;
if ( ! V_7 ) {
F_3 ( V_3 ,
L_3 ,
V_36 ) ;
return - V_45 ;
}
V_38 = F_12 ( V_3 , V_35 , V_7 , V_46 , true ) ;
if ( V_38 )
F_3 ( V_3 , L_4 , V_38 ) ;
F_10 ( & V_3 -> V_41 , V_39 ) ;
V_3 -> V_42 [ V_4 ] . V_47 = V_7 ;
F_11 ( & V_3 -> V_41 , V_39 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 ,
struct V_34 * V_35 ,
bool V_48 )
{
int V_5 , V_49 = 0 ;
T_1 V_50 [ sizeof( struct V_51 ) +
sizeof( struct V_52 ) * V_53 ] ;
struct V_51 * V_54 = (struct V_51 * ) V_50 ;
T_4 V_55 = sizeof( struct V_51 ) ;
struct V_56 V_57 = {
. V_58 = V_35 -> V_59 ,
. V_60 = V_54 ,
. V_39 = V_46 ,
} ;
F_14 () ;
memset ( V_54 , 0 , V_55 +
( sizeof( struct V_52 ) * V_53 ) ) ;
for ( V_5 = 0 ; V_5 < V_53 ; V_5 ++ ) {
V_54 -> V_61 [ V_5 ] . V_62 = V_5 ;
if ( V_35 -> V_63 [ V_5 ] . V_64 ) {
V_54 -> V_61 [ V_5 ] . V_65 = V_5 ;
V_49 = 1 ;
} else {
V_54 -> V_61 [ V_5 ] . V_65 = V_66 ;
}
V_54 -> V_61 [ V_5 ] . V_64 = V_35 -> V_63 [ V_5 ] . V_64 ;
memcpy ( & V_54 -> V_61 [ V_5 ] . V_61 [ 3 ] , V_35 -> V_63 [ V_5 ] . V_61 ,
V_35 -> V_63 [ V_5 ] . V_64 ) ;
}
V_54 -> V_67 = V_68 ;
V_54 -> V_69 = V_53 ;
V_55 += sizeof( struct V_52 ) * V_53 ;
V_57 . V_70 = V_55 ;
if ( V_49 || V_48 )
return F_15 ( V_3 , & V_57 ) ;
else
return 0 ;
}
int F_16 ( struct V_2 * V_3 ,
struct V_34 * V_35 )
{
F_17 ( & V_3 -> V_71 ) ;
return F_13 ( V_3 , V_35 , false ) ;
}
int F_18 ( struct V_2 * V_3 ,
struct V_34 * V_35 ,
struct V_72 * V_73 )
{
int V_38 ;
F_17 ( & V_3 -> V_71 ) ;
F_19 ( V_3 , L_5 ,
V_73 -> V_74 ) ;
memset ( & V_35 -> V_63 [ V_73 -> V_74 ] , 0 , sizeof( V_35 -> V_63 [ 0 ] ) ) ;
if ( F_20 ( V_3 ) ) {
F_19 ( V_3 ,
L_6 ) ;
return 0 ;
}
V_38 = F_13 ( V_3 , V_35 , 1 ) ;
F_19 ( V_3 , L_7 ,
V_73 -> V_74 , V_38 ) ;
return V_38 ;
}
int F_21 ( struct V_2 * V_3 ,
struct V_34 * V_35 ,
struct V_72 * V_73 )
{
int V_38 ;
F_17 ( & V_3 -> V_71 ) ;
if ( V_73 -> V_75 != V_76 &&
V_73 -> V_75 != V_77 ) {
F_19 ( V_3 , L_8 , V_73 -> V_75 ) ;
return - V_78 ;
}
V_73 -> V_39 &= ~ V_79 ;
V_73 -> V_80 = V_81 ;
V_3 -> V_42 [ V_35 -> V_82 ] . V_83 . V_84 = V_73 -> V_84 ;
V_35 -> V_63 [ V_73 -> V_74 ] . V_64 = V_73 -> V_75 ;
memcpy ( & V_35 -> V_63 [ V_73 -> V_74 ] . V_61 , & V_73 -> V_61 ,
V_73 -> V_75 ) ;
V_38 = F_13 ( V_3 , V_35 , false ) ;
F_19 ( V_3 , L_9 ,
V_73 -> V_75 , V_73 -> V_74 , V_38 ) ;
return V_38 ;
}
static int F_22 ( struct V_2 * V_3 ,
struct V_34 * V_35 ,
struct V_72 * V_73 ,
T_1 V_4 )
{
unsigned long V_39 ;
T_5 V_85 = 0 ;
struct V_86 V_87 ;
F_17 ( & V_3 -> V_71 ) ;
V_73 -> V_39 &= ~ V_79 ;
V_85 |= ( V_88 | V_89 ) ;
V_85 |= F_7 ( V_73 -> V_74 << V_90 ) ;
V_85 &= ~ V_91 ;
if ( V_73 -> V_75 == V_76 )
V_85 |= V_92 ;
if ( V_4 == V_35 -> V_93 )
V_85 |= V_94 ;
F_10 ( & V_3 -> V_41 , V_39 ) ;
V_3 -> V_42 [ V_4 ] . V_83 . V_84 = V_73 -> V_84 ;
V_3 -> V_42 [ V_4 ] . V_83 . V_75 = V_73 -> V_75 ;
V_3 -> V_42 [ V_4 ] . V_83 . V_74 = V_73 -> V_74 ;
memcpy ( V_3 -> V_42 [ V_4 ] . V_83 . V_61 ,
V_73 -> V_61 , V_73 -> V_75 ) ;
memcpy ( & V_3 -> V_42 [ V_4 ] . V_95 . V_61 . V_61 [ 3 ] ,
V_73 -> V_61 , V_73 -> V_75 ) ;
if ( ( V_3 -> V_42 [ V_4 ] . V_95 . V_61 . V_85 & V_96 )
== V_97 )
V_3 -> V_42 [ V_4 ] . V_95 . V_61 . V_65 =
F_23 ( V_3 ) ;
F_24 ( V_3 -> V_42 [ V_4 ] . V_95 . V_61 . V_65 == V_66 ,
L_10 ) ;
V_3 -> V_42 [ V_4 ] . V_95 . V_61 . V_85 = V_85 ;
V_3 -> V_42 [ V_4 ] . V_95 . V_95 . V_98 = V_99 ;
V_3 -> V_42 [ V_4 ] . V_95 . V_100 = V_101 ;
memcpy ( & V_87 , & V_3 -> V_42 [ V_4 ] . V_95 ,
sizeof( struct V_86 ) ) ;
F_11 ( & V_3 -> V_41 , V_39 ) ;
return F_25 ( V_3 , & V_87 , V_46 ) ;
}
static int F_26 ( struct V_2 * V_3 ,
struct V_34 * V_35 ,
struct V_72 * V_73 ,
T_1 V_4 )
{
unsigned long V_39 ;
T_5 V_85 = 0 ;
struct V_86 V_87 ;
F_17 ( & V_3 -> V_71 ) ;
V_85 |= ( V_102 | V_89 ) ;
V_85 |= F_7 ( V_73 -> V_74 << V_90 ) ;
V_85 &= ~ V_91 ;
if ( V_4 == V_35 -> V_93 )
V_85 |= V_94 ;
V_73 -> V_39 |= V_79 ;
F_10 ( & V_3 -> V_41 , V_39 ) ;
V_3 -> V_42 [ V_4 ] . V_83 . V_84 = V_73 -> V_84 ;
V_3 -> V_42 [ V_4 ] . V_83 . V_75 = V_73 -> V_75 ;
memcpy ( V_3 -> V_42 [ V_4 ] . V_83 . V_61 , V_73 -> V_61 ,
V_73 -> V_75 ) ;
memcpy ( V_3 -> V_42 [ V_4 ] . V_95 . V_61 . V_61 , V_73 -> V_61 ,
V_73 -> V_75 ) ;
if ( ( V_3 -> V_42 [ V_4 ] . V_95 . V_61 . V_85 & V_96 )
== V_97 )
V_3 -> V_42 [ V_4 ] . V_95 . V_61 . V_65 =
F_23 ( V_3 ) ;
F_24 ( V_3 -> V_42 [ V_4 ] . V_95 . V_61 . V_65 == V_66 ,
L_10 ) ;
V_3 -> V_42 [ V_4 ] . V_95 . V_61 . V_85 = V_85 ;
V_3 -> V_42 [ V_4 ] . V_95 . V_95 . V_98 = V_99 ;
V_3 -> V_42 [ V_4 ] . V_95 . V_100 = V_101 ;
memcpy ( & V_87 , & V_3 -> V_42 [ V_4 ] . V_95 ,
sizeof( struct V_86 ) ) ;
F_11 ( & V_3 -> V_41 , V_39 ) ;
return F_25 ( V_3 , & V_87 , V_46 ) ;
}
static int F_27 ( struct V_2 * V_3 ,
struct V_34 * V_35 ,
struct V_72 * V_73 ,
T_1 V_4 )
{
unsigned long V_39 ;
int V_38 = 0 ;
T_5 V_85 = 0 ;
V_85 |= ( V_103 | V_89 ) ;
V_85 |= F_7 ( V_73 -> V_74 << V_90 ) ;
V_85 &= ~ V_91 ;
if ( V_4 == V_35 -> V_93 )
V_85 |= V_94 ;
V_73 -> V_39 |= V_79 ;
V_73 -> V_39 |= V_104 ;
F_10 ( & V_3 -> V_41 , V_39 ) ;
V_3 -> V_42 [ V_4 ] . V_83 . V_84 = V_73 -> V_84 ;
V_3 -> V_42 [ V_4 ] . V_83 . V_75 = 16 ;
if ( ( V_3 -> V_42 [ V_4 ] . V_95 . V_61 . V_85 & V_96 )
== V_97 )
V_3 -> V_42 [ V_4 ] . V_95 . V_61 . V_65 =
F_23 ( V_3 ) ;
F_24 ( V_3 -> V_42 [ V_4 ] . V_95 . V_61 . V_65 == V_66 ,
L_10 ) ;
V_3 -> V_42 [ V_4 ] . V_95 . V_61 . V_85 = V_85 ;
memcpy ( V_3 -> V_42 [ V_4 ] . V_83 . V_61 , V_73 -> V_61 , 16 ) ;
memcpy ( V_3 -> V_42 [ V_4 ] . V_95 . V_61 . V_61 , V_73 -> V_61 , 16 ) ;
F_11 ( & V_3 -> V_41 , V_39 ) ;
return V_38 ;
}
void F_28 ( struct V_2 * V_3 ,
struct V_34 * V_35 ,
struct V_72 * V_73 ,
struct V_105 * V_95 , T_2 V_106 , T_6 * V_107 )
{
T_1 V_4 ;
unsigned long V_39 ;
int V_5 ;
if ( F_29 ( V_3 ) ) {
return;
}
V_4 = F_30 ( V_3 , V_35 , V_95 ) ;
if ( V_4 == V_40 )
return;
F_10 ( & V_3 -> V_41 , V_39 ) ;
V_3 -> V_42 [ V_4 ] . V_95 . V_61 . V_108 = ( T_1 ) V_106 ;
for ( V_5 = 0 ; V_5 < 5 ; V_5 ++ )
V_3 -> V_42 [ V_4 ] . V_95 . V_61 . V_109 [ V_5 ] =
F_7 ( V_107 [ V_5 ] ) ;
V_3 -> V_42 [ V_4 ] . V_95 . V_95 . V_98 = V_99 ;
V_3 -> V_42 [ V_4 ] . V_95 . V_100 = V_101 ;
F_25 ( V_3 , & V_3 -> V_42 [ V_4 ] . V_95 , V_110 ) ;
F_11 ( & V_3 -> V_41 , V_39 ) ;
}
int F_31 ( struct V_2 * V_3 ,
struct V_34 * V_35 ,
struct V_72 * V_73 ,
T_1 V_4 )
{
unsigned long V_39 ;
T_6 V_85 ;
T_1 V_74 ;
struct V_86 V_87 ;
F_17 ( & V_3 -> V_71 ) ;
V_35 -> V_111 -- ;
F_10 ( & V_3 -> V_41 , V_39 ) ;
V_85 = F_32 ( V_3 -> V_42 [ V_4 ] . V_95 . V_61 . V_85 ) ;
V_74 = ( V_85 >> V_90 ) & 0x3 ;
F_19 ( V_3 , L_11 ,
V_73 -> V_74 , V_4 ) ;
if ( V_73 -> V_74 != V_74 ) {
F_11 ( & V_3 -> V_41 , V_39 ) ;
return 0 ;
}
if ( V_3 -> V_42 [ V_4 ] . V_95 . V_61 . V_65 == V_66 ) {
F_33 ( V_3 , L_12 ,
V_73 -> V_74 , V_85 ) ;
F_11 ( & V_3 -> V_41 , V_39 ) ;
return 0 ;
}
if ( ! F_34 ( V_3 -> V_42 [ V_4 ] . V_95 . V_61 . V_65 ,
& V_3 -> V_112 ) )
F_3 ( V_3 , L_13 ,
V_3 -> V_42 [ V_4 ] . V_95 . V_61 . V_65 ) ;
memset ( & V_3 -> V_42 [ V_4 ] . V_83 , 0 ,
sizeof( struct V_113 ) ) ;
memset ( & V_3 -> V_42 [ V_4 ] . V_95 . V_61 , 0 ,
sizeof( struct V_114 ) ) ;
V_3 -> V_42 [ V_4 ] . V_95 . V_61 . V_85 =
V_97 | V_91 ;
V_3 -> V_42 [ V_4 ] . V_95 . V_61 . V_65 = V_66 ;
V_3 -> V_42 [ V_4 ] . V_95 . V_95 . V_98 = V_99 ;
V_3 -> V_42 [ V_4 ] . V_95 . V_100 = V_101 ;
if ( F_20 ( V_3 ) ) {
F_19 ( V_3 ,
L_14 ) ;
F_11 ( & V_3 -> V_41 , V_39 ) ;
return 0 ;
}
memcpy ( & V_87 , & V_3 -> V_42 [ V_4 ] . V_95 ,
sizeof( struct V_86 ) ) ;
F_11 ( & V_3 -> V_41 , V_39 ) ;
return F_25 ( V_3 , & V_87 , V_46 ) ;
}
int F_35 ( struct V_2 * V_3 , struct V_34 * V_35 ,
struct V_72 * V_73 , T_1 V_4 )
{
int V_38 ;
F_17 ( & V_3 -> V_71 ) ;
V_35 -> V_111 ++ ;
V_73 -> V_80 = V_115 ;
switch ( V_73 -> V_84 ) {
case V_116 :
V_38 = F_26 ( V_3 , V_35 ,
V_73 , V_4 ) ;
break;
case V_117 :
V_38 = F_27 ( V_3 , V_35 ,
V_73 , V_4 ) ;
break;
case V_118 :
case V_119 :
V_38 = F_22 ( V_3 , V_35 ,
V_73 , V_4 ) ;
break;
default:
F_3 ( V_3 ,
L_15 , V_120 ,
V_73 -> V_84 ) ;
V_38 = - V_78 ;
}
F_19 ( V_3 ,
L_16 ,
V_73 -> V_84 , V_73 -> V_75 , V_73 -> V_74 ,
V_4 , V_38 ) ;
return V_38 ;
}
int F_36 ( struct V_2 * V_3 ,
struct V_34 * V_35 )
{
struct V_1 * V_7 ;
unsigned long V_39 ;
T_1 V_4 ;
F_10 ( & V_3 -> V_41 , V_39 ) ;
V_4 = F_37 ( V_3 , V_35 , V_121 ,
false , NULL ) ;
if ( V_4 == V_40 ) {
F_3 ( V_3 , L_17 ) ;
F_11 ( & V_3 -> V_41 , V_39 ) ;
return - V_78 ;
}
V_3 -> V_42 [ V_4 ] . V_43 |= V_122 ;
V_3 -> V_42 [ V_4 ] . V_43 |= V_123 ;
F_11 ( & V_3 -> V_41 , V_39 ) ;
V_7 = F_1 ( V_3 , V_4 ) ;
if ( ! V_7 ) {
F_3 ( V_3 ,
L_18 ) ;
return - V_45 ;
}
F_10 ( & V_3 -> V_41 , V_39 ) ;
V_3 -> V_42 [ V_4 ] . V_47 = V_7 ;
F_11 ( & V_3 -> V_41 , V_39 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 ,
struct V_34 * V_35 )
{
unsigned long V_39 ;
struct V_1 * V_7 ;
T_1 V_4 = V_35 -> V_93 ;
V_7 = F_1 ( V_3 , V_4 ) ;
if ( ! V_7 ) {
F_3 ( V_3 ,
L_18 ) ;
return - V_45 ;
}
F_10 ( & V_3 -> V_41 , V_39 ) ;
if ( V_3 -> V_42 [ V_4 ] . V_47 )
F_39 ( V_3 -> V_42 [ V_4 ] . V_47 ) ;
else
F_40 ( V_3 ,
L_19 ) ;
V_3 -> V_42 [ V_4 ] . V_47 = V_7 ;
F_11 ( & V_3 -> V_41 , V_39 ) ;
return 0 ;
}
int F_41 ( struct V_2 * V_3 )
{
struct V_34 * V_35 ;
int V_38 = 0 ;
F_42 (priv, ctx) {
V_38 = F_38 ( V_3 , V_35 ) ;
if ( V_38 )
break;
}
return V_38 ;
}
int F_43 ( struct V_2 * V_3 , int V_4 , int V_124 )
{
unsigned long V_39 ;
struct V_86 V_87 ;
F_17 ( & V_3 -> V_71 ) ;
F_10 ( & V_3 -> V_41 , V_39 ) ;
V_3 -> V_42 [ V_4 ] . V_95 . V_95 . V_98 = V_125 ;
V_3 -> V_42 [ V_4 ] . V_95 . V_126 &= F_7 ( ~ ( 1 << V_124 ) ) ;
V_3 -> V_42 [ V_4 ] . V_95 . V_100 = V_101 ;
memcpy ( & V_87 , & V_3 -> V_42 [ V_4 ] . V_95 ,
sizeof( struct V_86 ) ) ;
F_11 ( & V_3 -> V_41 , V_39 ) ;
return F_25 ( V_3 , & V_87 , V_46 ) ;
}
int F_44 ( struct V_2 * V_3 , struct V_105 * V_95 ,
int V_124 , T_6 V_127 )
{
unsigned long V_39 ;
int V_4 ;
struct V_86 V_87 ;
F_17 ( & V_3 -> V_71 ) ;
V_4 = F_45 ( V_95 ) ;
if ( V_4 == V_40 )
return - V_128 ;
F_10 ( & V_3 -> V_41 , V_39 ) ;
V_3 -> V_42 [ V_4 ] . V_95 . V_129 = 0 ;
V_3 -> V_42 [ V_4 ] . V_95 . V_95 . V_98 = V_130 ;
V_3 -> V_42 [ V_4 ] . V_95 . V_131 = ( T_1 ) V_124 ;
V_3 -> V_42 [ V_4 ] . V_95 . V_132 = F_7 ( V_127 ) ;
V_3 -> V_42 [ V_4 ] . V_95 . V_100 = V_101 ;
memcpy ( & V_87 , & V_3 -> V_42 [ V_4 ] . V_95 ,
sizeof( struct V_86 ) ) ;
F_11 ( & V_3 -> V_41 , V_39 ) ;
return F_25 ( V_3 , & V_87 , V_46 ) ;
}
int F_46 ( struct V_2 * V_3 , struct V_105 * V_95 ,
int V_124 )
{
unsigned long V_39 ;
int V_4 ;
struct V_86 V_87 ;
F_17 ( & V_3 -> V_71 ) ;
V_4 = F_45 ( V_95 ) ;
if ( V_4 == V_40 ) {
F_3 ( V_3 , L_20 , V_124 ) ;
return - V_128 ;
}
F_10 ( & V_3 -> V_41 , V_39 ) ;
V_3 -> V_42 [ V_4 ] . V_95 . V_129 = 0 ;
V_3 -> V_42 [ V_4 ] . V_95 . V_95 . V_98 = V_133 ;
V_3 -> V_42 [ V_4 ] . V_95 . V_134 = ( T_1 ) V_124 ;
V_3 -> V_42 [ V_4 ] . V_95 . V_100 = V_101 ;
memcpy ( & V_87 , & V_3 -> V_42 [ V_4 ] . V_95 ,
sizeof( struct V_86 ) ) ;
F_11 ( & V_3 -> V_41 , V_39 ) ;
return F_25 ( V_3 , & V_87 , V_46 ) ;
}
void
F_47 ( struct V_2 * V_3 , int V_4 , int V_135 )
{
unsigned long V_39 ;
F_10 ( & V_3 -> V_41 , V_39 ) ;
V_3 -> V_42 [ V_4 ] . V_95 . V_136 |= V_137 ;
V_3 -> V_42 [ V_4 ] . V_95 . V_129 = V_137 ;
V_3 -> V_42 [ V_4 ] . V_95 . V_95 . V_98 =
V_138 ;
V_3 -> V_42 [ V_4 ] . V_95 . V_139 = F_7 ( V_135 ) ;
V_3 -> V_42 [ V_4 ] . V_95 . V_100 = V_101 ;
F_25 ( V_3 ,
& V_3 -> V_42 [ V_4 ] . V_95 , V_110 ) ;
F_11 ( & V_3 -> V_41 , V_39 ) ;
}
