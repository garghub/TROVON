void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
F_2 ( & V_4 -> V_6 ) ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
V_4 -> V_8 [ V_5 ] = 0 ;
V_4 -> V_9 [ V_5 ] = 0 ;
}
V_4 -> V_10 = 1 << V_2 -> V_11 . V_12 ;
V_4 -> V_13 = 0 ;
}
void F_3 ( struct V_1 * V_2 , struct V_14 * V_4 )
{
int V_5 ;
F_2 ( & V_4 -> V_6 ) ;
for ( V_5 = 0 ; V_5 < V_15 ; V_5 ++ ) {
V_4 -> V_8 [ V_5 ] = 0 ;
V_4 -> V_9 [ V_5 ] = 0 ;
}
V_4 -> V_10 = ( 1 << V_2 -> V_11 . V_16 ) - V_17 ;
V_4 -> V_13 = 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_18 ,
T_2 V_19 , int * V_20 , T_2 * V_21 )
{
T_3 V_22 ;
int V_23 ;
V_19 &= V_24 ;
V_22 = F_5 ( V_19 << 16 ) ;
switch ( V_2 -> V_11 . V_25 ) {
case V_26 : {
struct V_27 V_28 ;
T_1 V_29 [ 16 ] = { 0 } ;
V_28 . V_20 = * V_20 ;
memcpy ( & V_29 [ 10 ] , & V_22 , V_30 ) ;
V_29 [ 5 ] = V_18 ;
V_23 = F_6 ( V_2 , & V_28 , V_29 , 0 , V_31 ) ;
break;
}
case V_32 : {
struct V_33 V_34 = { { NULL } } ;
T_3 V_35 = F_5 ( V_24 << 16 ) ;
struct V_36 V_37 = {
. V_38 = V_39 ,
. V_40 = 0 ,
. V_41 = 1 ,
. V_42 = V_43 ,
. V_44 = V_45 ,
} ;
V_37 . V_18 = V_18 ;
V_37 . V_20 = * V_20 ;
F_7 ( & V_37 . V_46 ) ;
V_34 . V_47 = V_48 ;
memcpy ( V_34 . V_49 . V_50 , & V_22 , V_30 ) ;
memcpy ( V_34 . V_49 . V_51 , & V_35 , V_30 ) ;
F_8 ( & V_34 . V_46 , & V_37 . V_46 ) ;
V_23 = F_9 ( V_2 , & V_37 , V_21 ) ;
break;
}
default:
return - V_52 ;
}
if ( V_23 )
F_10 ( V_2 , L_1 ) ;
return V_23 ;
}
static void F_11 ( struct V_1 * V_2 , T_1 V_18 ,
T_2 V_19 , int V_20 , T_2 V_21 )
{
switch ( V_2 -> V_11 . V_25 ) {
case V_26 : {
struct V_27 V_28 ;
T_1 V_29 [ 16 ] = { 0 } ;
T_3 V_22 ;
V_28 . V_20 = V_20 ;
V_19 &= V_24 ;
V_22 = F_5 ( V_19 << 16 ) ;
memcpy ( & V_29 [ 10 ] , & V_22 , V_30 ) ;
V_29 [ 5 ] = V_18 ;
F_12 ( V_2 , & V_28 , V_29 , V_31 ) ;
break;
}
case V_32 : {
F_13 ( V_2 , V_21 ) ;
break;
}
default:
F_14 ( V_2 , L_2 ) ;
}
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_53 )
{
int V_23 = 0 ;
if ( V_53 < 0 || V_53 >= V_4 -> V_10 || ! V_4 -> V_8 [ V_53 ] ) {
F_10 ( V_2 , L_3 ) ;
V_23 = - V_52 ;
}
return V_23 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 V_19 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
if ( ( V_19 & V_24 ) ==
( V_24 & F_17 ( V_4 -> V_8 [ V_5 ] ) ) )
return V_5 ;
}
return - V_52 ;
}
int F_18 ( struct V_1 * V_2 , T_1 V_18 , T_2 V_19 , int * V_20 )
{
struct V_54 * V_55 = & F_19 ( V_2 ) -> V_18 [ V_18 ] ;
struct V_56 * V_57 ;
int V_53 = 0 ;
int V_23 = 0 ;
T_2 V_21 ;
F_20 ( V_2 , L_4 ,
( unsigned long long ) V_19 ) ;
V_53 = F_21 ( V_2 , V_18 , V_19 ) ;
if ( V_53 < 0 ) {
V_23 = V_53 ;
F_14 ( V_2 , L_5 ,
( unsigned long long ) V_19 ) ;
return V_23 ;
}
if ( V_2 -> V_11 . V_25 == V_58 ) {
* V_20 = V_55 -> V_59 + V_53 ;
return 0 ;
}
V_23 = F_22 ( V_2 , 1 , 1 , V_20 ) ;
F_20 ( V_2 , L_6 , * V_20 ) ;
if ( V_23 ) {
F_14 ( V_2 , L_7 ) ;
goto V_60;
}
V_23 = F_4 ( V_2 , V_18 , V_19 , V_20 , & V_21 ) ;
if ( V_23 )
goto V_61;
V_57 = F_23 ( sizeof *V_57 , V_62 ) ;
if ( ! V_57 ) {
V_23 = - V_63 ;
goto V_64;
}
V_57 -> V_19 = V_19 ;
V_57 -> V_21 = V_21 ;
V_23 = F_24 ( & V_55 -> V_65 , * V_20 , V_57 ) ;
if ( V_23 )
goto V_66;
return 0 ;
V_66:
F_25 ( V_57 ) ;
V_64:
F_11 ( V_2 , V_18 , V_19 , * V_20 , V_21 ) ;
V_61:
F_26 ( V_2 , * V_20 , 1 ) ;
V_60:
F_27 ( V_2 , V_18 , V_19 ) ;
return V_23 ;
}
void F_28 ( struct V_1 * V_2 , T_1 V_18 , T_2 V_19 , int V_20 )
{
struct V_54 * V_55 = & F_19 ( V_2 ) -> V_18 [ V_18 ] ;
struct V_56 * V_57 ;
F_20 ( V_2 , L_8 ,
( unsigned long long ) V_19 ) ;
F_27 ( V_2 , V_18 , V_19 ) ;
if ( V_2 -> V_11 . V_25 != V_58 ) {
V_57 = F_29 ( & V_55 -> V_65 , V_20 ) ;
if ( V_57 ) {
F_20 ( V_2 , L_9
L_10 , V_18 ,
( unsigned long long ) V_19 , V_20 ) ;
F_11 ( V_2 , V_18 , V_57 -> V_19 ,
V_20 , V_57 -> V_21 ) ;
F_26 ( V_2 , V_20 , 1 ) ;
F_30 ( & V_55 -> V_65 , V_20 ) ;
F_25 ( V_57 ) ;
}
}
}
static int F_31 ( struct V_1 * V_2 , T_1 V_18 ,
T_3 * V_8 )
{
struct V_67 * V_68 ;
T_4 V_69 ;
int V_23 ;
V_68 = F_32 ( V_2 ) ;
if ( F_33 ( V_68 ) )
return F_34 ( V_68 ) ;
memcpy ( V_68 -> V_70 , V_8 , V_71 ) ;
V_69 = V_72 << 8 | V_18 ;
V_23 = F_35 ( V_2 , V_68 -> V_73 , V_69 , 1 , V_74 ,
V_75 , V_76 ) ;
F_36 ( V_2 , V_68 ) ;
return V_23 ;
}
int F_37 ( struct V_1 * V_2 , T_1 V_18 , T_2 V_19 )
{
struct V_54 * V_55 = & F_19 ( V_2 ) -> V_18 [ V_18 ] ;
struct V_3 * V_4 = & V_55 -> V_77 ;
int V_5 , V_23 = 0 ;
int free = - 1 ;
F_20 ( V_2 , L_11 ,
( unsigned long long ) V_19 , V_18 ) ;
F_38 ( & V_4 -> V_6 ) ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
if ( free < 0 && ! V_4 -> V_8 [ V_5 ] ) {
free = V_5 ;
continue;
}
if ( V_19 == ( V_24 & F_17 ( V_4 -> V_8 [ V_5 ] ) ) ) {
V_23 = - V_78 ;
goto V_79;
}
}
F_20 ( V_2 , L_12 , free ) ;
if ( V_4 -> V_13 == V_4 -> V_10 ) {
V_23 = - V_80 ;
goto V_79;
}
V_4 -> V_8 [ free ] = F_5 ( V_19 | V_81 ) ;
V_23 = F_31 ( V_2 , V_18 , V_4 -> V_8 ) ;
if ( F_39 ( V_23 ) ) {
F_14 ( V_2 , L_5 ,
( unsigned long long ) V_19 ) ;
V_4 -> V_8 [ free ] = 0 ;
goto V_79;
}
V_23 = free ;
++ V_4 -> V_13 ;
V_79:
F_40 ( & V_4 -> V_6 ) ;
return V_23 ;
}
int F_21 ( struct V_1 * V_2 , T_1 V_18 , T_2 V_19 )
{
T_2 V_82 ;
int V_23 ;
if ( F_41 ( V_2 ) ) {
F_42 ( & V_82 , V_18 ) ;
V_23 = F_43 ( V_2 , V_19 , & V_82 , V_83 ,
V_84 , V_85 ,
V_86 , V_87 ) ;
if ( V_23 )
return V_23 ;
return F_44 ( & V_82 ) ;
}
return F_37 ( V_2 , V_18 , V_19 ) ;
}
void F_45 ( struct V_1 * V_2 , T_1 V_18 , T_2 V_19 )
{
struct V_54 * V_55 = & F_19 ( V_2 ) -> V_18 [ V_18 ] ;
struct V_3 * V_4 = & V_55 -> V_77 ;
int V_53 ;
V_53 = F_16 ( V_2 , V_4 , V_19 ) ;
F_38 ( & V_4 -> V_6 ) ;
if ( F_15 ( V_2 , V_4 , V_53 ) )
goto V_79;
V_4 -> V_8 [ V_53 ] = 0 ;
F_31 ( V_2 , V_18 , V_4 -> V_8 ) ;
-- V_4 -> V_13 ;
V_79:
F_40 ( & V_4 -> V_6 ) ;
}
void F_27 ( struct V_1 * V_2 , T_1 V_18 , T_2 V_19 )
{
T_2 V_82 ;
if ( F_41 ( V_2 ) ) {
F_42 ( & V_82 , V_18 ) ;
( void ) F_43 ( V_2 , V_19 , & V_82 , V_83 ,
V_84 , V_88 ,
V_86 , V_87 ) ;
return;
}
F_45 ( V_2 , V_18 , V_19 ) ;
return;
}
int F_46 ( struct V_1 * V_2 , T_1 V_18 , int V_20 , T_2 V_89 )
{
struct V_54 * V_55 = & F_19 ( V_2 ) -> V_18 [ V_18 ] ;
struct V_3 * V_4 = & V_55 -> V_77 ;
struct V_56 * V_57 ;
int V_53 = V_20 - V_55 -> V_59 ;
int V_23 = 0 ;
if ( V_2 -> V_11 . V_25 != V_58 ) {
V_57 = F_29 ( & V_55 -> V_65 , V_20 ) ;
if ( ! V_57 )
return - V_52 ;
F_11 ( V_2 , V_18 , V_57 -> V_19 ,
V_20 , V_57 -> V_21 ) ;
F_27 ( V_2 , V_18 , V_57 -> V_19 ) ;
V_57 -> V_19 = V_89 ;
V_57 -> V_21 = 0 ;
F_21 ( V_2 , V_18 , V_89 ) ;
V_23 = F_4 ( V_2 , V_18 , V_57 -> V_19 ,
& V_20 , & V_57 -> V_21 ) ;
return V_23 ;
}
F_38 ( & V_4 -> V_6 ) ;
V_23 = F_15 ( V_2 , V_4 , V_53 ) ;
if ( V_23 )
goto V_79;
V_4 -> V_8 [ V_53 ] = F_5 ( V_89 | V_81 ) ;
V_23 = F_31 ( V_2 , V_18 , V_4 -> V_8 ) ;
if ( F_39 ( V_23 ) ) {
F_14 ( V_2 , L_5 ,
( unsigned long long ) V_89 ) ;
V_4 -> V_8 [ V_53 ] = 0 ;
}
V_79:
F_40 ( & V_4 -> V_6 ) ;
return V_23 ;
}
static int F_47 ( struct V_1 * V_2 , T_1 V_18 ,
T_5 * V_8 )
{
struct V_67 * V_68 ;
T_4 V_69 ;
int V_23 ;
V_68 = F_32 ( V_2 ) ;
if ( F_33 ( V_68 ) )
return F_34 ( V_68 ) ;
memcpy ( V_68 -> V_70 , V_8 , V_90 ) ;
V_69 = V_91 << 8 | V_18 ;
V_23 = F_35 ( V_2 , V_68 -> V_73 , V_69 , 1 , V_74 ,
V_75 , V_87 ) ;
F_36 ( V_2 , V_68 ) ;
return V_23 ;
}
int F_48 ( struct V_1 * V_2 , T_1 V_18 , T_6 V_92 , int * V_93 )
{
struct V_14 * V_4 = & F_19 ( V_2 ) -> V_18 [ V_18 ] . V_94 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_15 ; ++ V_5 ) {
if ( V_4 -> V_9 [ V_5 ] &&
( V_92 == ( V_95 &
F_49 ( V_4 -> V_8 [ V_5 ] ) ) ) ) {
* V_93 = V_5 ;
return 0 ;
}
}
return - V_96 ;
}
static int F_50 ( struct V_1 * V_2 , T_1 V_18 , T_6 V_97 ,
int * V_53 )
{
struct V_14 * V_4 = & F_19 ( V_2 ) -> V_18 [ V_18 ] . V_94 ;
int V_5 , V_23 = 0 ;
int free = - 1 ;
F_38 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_13 == V_4 -> V_10 ) {
V_23 = - V_80 ;
goto V_79;
}
for ( V_5 = V_17 ; V_5 < V_15 ; V_5 ++ ) {
if ( free < 0 && ( V_4 -> V_9 [ V_5 ] == 0 ) ) {
free = V_5 ;
continue;
}
if ( V_4 -> V_9 [ V_5 ] &&
( V_97 == ( V_95 &
F_49 ( V_4 -> V_8 [ V_5 ] ) ) ) ) {
* V_53 = V_5 ;
++ V_4 -> V_9 [ V_5 ] ;
goto V_79;
}
}
if ( free < 0 ) {
V_23 = - V_63 ;
goto V_79;
}
V_4 -> V_9 [ free ] = 1 ;
V_4 -> V_8 [ free ] = F_51 ( V_97 | V_98 ) ;
V_23 = F_47 ( V_2 , V_18 , V_4 -> V_8 ) ;
if ( F_39 ( V_23 ) ) {
F_10 ( V_2 , L_13 , V_97 ) ;
V_4 -> V_9 [ free ] = 0 ;
V_4 -> V_8 [ free ] = 0 ;
goto V_79;
}
* V_53 = free ;
++ V_4 -> V_13 ;
V_79:
F_40 ( & V_4 -> V_6 ) ;
return V_23 ;
}
int F_52 ( struct V_1 * V_2 , T_1 V_18 , T_6 V_97 , int * V_53 )
{
T_2 V_82 ;
int V_23 ;
if ( F_41 ( V_2 ) ) {
F_42 ( & V_82 , V_18 ) ;
V_23 = F_43 ( V_2 , V_97 , & V_82 , V_99 ,
V_84 , V_85 ,
V_86 , V_87 ) ;
if ( ! V_23 )
* V_53 = F_44 ( & V_82 ) ;
return V_23 ;
}
return F_50 ( V_2 , V_18 , V_97 , V_53 ) ;
}
static void F_53 ( struct V_1 * V_2 , T_1 V_18 , int V_53 )
{
struct V_14 * V_4 = & F_19 ( V_2 ) -> V_18 [ V_18 ] . V_94 ;
if ( V_53 < V_17 ) {
F_10 ( V_2 , L_14 , V_53 ) ;
return;
}
F_38 ( & V_4 -> V_6 ) ;
if ( ! V_4 -> V_9 [ V_53 ] ) {
F_10 ( V_2 , L_15 , V_53 ) ;
goto V_79;
}
if ( -- V_4 -> V_9 [ V_53 ] ) {
F_20 ( V_2 , L_16
L_17 , V_53 ) ;
goto V_79;
}
V_4 -> V_8 [ V_53 ] = 0 ;
F_47 ( V_2 , V_18 , V_4 -> V_8 ) ;
-- V_4 -> V_13 ;
V_79:
F_40 ( & V_4 -> V_6 ) ;
}
void F_54 ( struct V_1 * V_2 , T_1 V_18 , int V_53 )
{
T_2 V_100 ;
int V_23 ;
if ( F_41 ( V_2 ) ) {
F_42 ( & V_100 , V_18 ) ;
V_23 = F_35 ( V_2 , V_100 , V_99 , V_84 ,
V_88 , V_86 ,
V_87 ) ;
if ( ! V_23 )
F_10 ( V_2 , L_18 ,
V_53 ) ;
return;
}
F_53 ( V_2 , V_18 , V_53 ) ;
}
int F_55 ( struct V_1 * V_2 , T_1 V_18 , T_5 * V_11 )
{
struct V_67 * V_101 , * V_102 ;
T_1 * V_103 , * V_104 ;
int V_23 ;
V_101 = F_32 ( V_2 ) ;
if ( F_33 ( V_101 ) )
return F_34 ( V_101 ) ;
V_102 = F_32 ( V_2 ) ;
if ( F_33 ( V_102 ) ) {
F_36 ( V_2 , V_101 ) ;
return F_34 ( V_102 ) ;
}
V_103 = V_101 -> V_70 ;
V_104 = V_102 -> V_70 ;
memset ( V_103 , 0 , 256 ) ;
memset ( V_104 , 0 , 256 ) ;
V_103 [ 0 ] = 1 ;
V_103 [ 1 ] = 1 ;
V_103 [ 2 ] = 1 ;
V_103 [ 3 ] = 1 ;
* ( V_105 * ) ( & V_103 [ 16 ] ) = F_56 ( 0x0015 ) ;
* ( T_5 * ) ( & V_103 [ 20 ] ) = F_51 ( V_18 ) ;
V_23 = F_57 ( V_2 , V_101 -> V_73 , V_102 -> V_73 , V_18 , 3 ,
V_106 , V_107 ,
V_76 ) ;
if ( ! V_23 )
* V_11 = * ( T_5 * ) ( V_104 + 84 ) ;
F_36 ( V_2 , V_101 ) ;
F_36 ( V_2 , V_102 ) ;
return V_23 ;
}
static int F_58 ( struct V_1 * V_2 , int V_108 , T_4 V_69 ,
T_1 V_109 , struct V_67 * V_110 )
{
struct F_19 * V_111 = F_19 ( V_2 ) ;
struct V_54 * V_112 ;
struct V_113 * V_114 = & V_111 -> V_115 . V_114 ;
struct V_116 * V_117 = & V_114 -> V_118 [ V_108 ] ;
struct V_119 * V_120 ;
struct V_121 * V_122 ;
int V_123 ;
int V_18 ;
int V_124 ;
T_4 V_125 ;
T_4 V_126 ;
T_6 V_127 , V_128 ;
int V_23 ;
int V_5 ;
T_5 V_129 ;
T_5 V_130 ;
T_5 V_131 ;
V_18 = V_69 & 0xff ;
V_125 = V_69 >> 8 ;
V_124 = V_109 ;
V_112 = & V_111 -> V_18 [ V_18 ] ;
if ( V_124 ) {
if ( V_108 != V_2 -> V_11 . V_132 &&
V_125 != V_133 ) {
F_10 ( V_2 , L_19 ,
V_108 ) ;
return - V_52 ;
}
switch ( V_125 ) {
case V_134 :
V_120 = V_110 -> V_70 ;
V_120 -> V_59 =
F_51 ( V_112 -> V_59 ) ;
V_120 -> V_135 = 0x7 ;
V_126 = F_49 ( V_120 -> V_126 ) >>
V_136 ;
V_120 -> V_126 = F_51 (
V_126 << V_136 |
V_112 -> V_59 ) ;
V_126 = F_49 ( V_120 -> V_137 ) >>
V_138 ;
V_120 -> V_137 = F_51 (
V_126 << V_138 |
V_112 -> V_59 ) ;
break;
case V_133 :
V_122 = V_110 -> V_70 ;
V_127 = F_59 ( V_122 -> V_127 ) ;
V_127 = F_60 ( int , V_127 , V_2 -> V_11 . V_139 [ V_18 ] ) ;
V_128 = V_117 -> V_127 [ V_18 ] ;
V_117 -> V_127 [ V_18 ] = V_127 ;
if ( V_127 > V_114 -> V_140 [ V_18 ] )
V_114 -> V_140 [ V_18 ] = V_127 ;
if ( V_127 < V_128 && V_128 ==
V_114 -> V_140 [ V_18 ] ) {
V_117 -> V_127 [ V_18 ] = V_127 ;
V_114 -> V_140 [ V_18 ] = V_127 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_141 ; V_5 ++ ) {
V_114 -> V_140 [ V_18 ] =
V_10 ( V_114 -> V_140 [ V_18 ] ,
V_114 -> V_118 [ V_5 ] . V_127 [ V_18 ] ) ;
}
}
V_122 -> V_127 = F_56 ( V_114 -> V_140 [ V_18 ] ) ;
break;
}
return F_35 ( V_2 , V_110 -> V_73 , V_69 , V_109 ,
V_74 , V_75 ,
V_76 ) ;
}
if ( V_2 -> V_142 & V_143 ) {
V_123 = ( * ( T_1 * ) V_110 -> V_70 ) & 0x40 ;
V_131 = ( ( T_5 * ) V_110 -> V_70 ) [ 2 ] ;
} else {
V_123 = ( ( T_1 * ) V_110 -> V_70 ) [ 3 ] & 0x1 ;
V_131 = ( ( T_5 * ) V_110 -> V_70 ) [ 1 ] ;
}
if ( V_108 != F_61 ( V_2 ) &&
( F_49 ( V_131 ) & V_144 ) )
return - V_52 ;
if ( F_41 ( V_2 ) &&
( F_49 ( V_131 ) & V_145 ) )
return - V_52 ;
V_129 = 0 ;
V_130 =
V_111 -> V_115 . V_114 . V_118 [ V_108 ] . V_146 [ V_18 ] ;
V_111 -> V_115 . V_114 . V_118 [ V_108 ] . V_146 [ V_18 ] = V_131 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_141 ; V_5 ++ )
V_129 |=
V_111 -> V_115 . V_114 . V_118 [ V_5 ] . V_146 [ V_18 ] ;
if ( V_108 != V_2 -> V_11 . V_132 )
memset ( V_110 -> V_70 , 0 , 256 ) ;
if ( V_2 -> V_142 & V_143 ) {
* ( T_1 * ) V_110 -> V_70 |= ! ! V_123 << 6 ;
( ( T_5 * ) V_110 -> V_70 ) [ 2 ] = V_129 ;
} else {
( ( T_1 * ) V_110 -> V_70 ) [ 3 ] |= ! ! V_123 ;
( ( T_5 * ) V_110 -> V_70 ) [ 1 ] = V_129 ;
}
V_23 = F_35 ( V_2 , V_110 -> V_73 , V_18 , V_124 , V_74 ,
V_75 , V_76 ) ;
if ( V_23 )
V_111 -> V_115 . V_114 . V_118 [ V_108 ] . V_146 [ V_18 ] =
V_130 ;
return V_23 ;
}
int F_62 ( struct V_1 * V_2 , int V_108 ,
struct V_147 * V_148 ,
struct V_67 * V_110 ,
struct V_67 * V_149 ,
struct V_150 * V_151 )
{
return F_58 ( V_2 , V_108 , V_148 -> V_125 ,
V_148 -> V_152 , V_110 ) ;
}
int F_63 ( struct V_1 * V_2 , T_1 V_18 , int V_153 )
{
struct V_67 * V_68 ;
int V_23 , V_154 , V_155 = 0 ;
if ( V_2 -> V_11 . V_156 [ V_18 ] == V_157 )
return 0 ;
V_68 = F_32 ( V_2 ) ;
if ( F_33 ( V_68 ) )
return F_34 ( V_68 ) ;
memset ( V_68 -> V_70 , 0 , 256 ) ;
( ( T_5 * ) V_68 -> V_70 ) [ 1 ] = V_2 -> V_11 . V_158 [ V_18 ] ;
if ( V_153 >= 0 && F_64 ( V_2 ) ) {
V_155 = 1 ;
( ( V_105 * ) V_68 -> V_70 ) [ 20 ] = F_56 ( V_153 ) ;
}
for ( V_154 = 8 ; V_154 >= 1 ; V_154 >>= 1 ) {
( ( T_5 * ) V_68 -> V_70 ) [ 0 ] = F_51 (
( 1 << V_159 ) |
( 1 << V_160 ) |
( V_155 << V_161 ) |
( V_2 -> V_11 . V_162 [ V_18 ] << V_163 ) |
( V_154 << V_164 ) ) ;
V_23 = F_35 ( V_2 , V_68 -> V_73 , V_18 , 0 , V_74 ,
V_75 , V_87 ) ;
if ( V_23 != - V_63 )
break;
}
F_36 ( V_2 , V_68 ) ;
return V_23 ;
}
int F_65 ( struct V_1 * V_2 , T_1 V_18 , int V_127 ,
T_1 V_165 , T_1 V_166 , T_1 V_167 , T_1 V_168 )
{
struct V_67 * V_68 ;
struct V_121 * V_169 ;
int V_23 ;
T_4 V_69 ;
V_68 = F_32 ( V_2 ) ;
if ( F_33 ( V_68 ) )
return F_34 ( V_68 ) ;
V_169 = V_68 -> V_70 ;
memset ( V_169 , 0 , sizeof *V_169 ) ;
V_169 -> V_142 = V_170 ;
V_169 -> V_127 = F_56 ( V_127 ) ;
V_169 -> V_165 = ( V_165 * ( ! V_166 ) ) << 7 ;
V_169 -> V_166 = V_166 ;
V_169 -> V_167 = ( V_167 * ( ! V_168 ) ) << 7 ;
V_169 -> V_168 = V_168 ;
V_69 = V_133 << 8 | V_18 ;
V_23 = F_35 ( V_2 , V_68 -> V_73 , V_69 , 1 , V_74 ,
V_75 , V_87 ) ;
F_36 ( V_2 , V_68 ) ;
return V_23 ;
}
int F_66 ( struct V_1 * V_2 , T_1 V_18 , T_4 V_59 ,
T_1 V_126 )
{
struct V_67 * V_68 ;
struct V_119 * V_169 ;
int V_23 ;
T_4 V_69 ;
T_4 V_171 = ( V_2 -> V_11 . V_142 & V_172 ) ?
V_173 : V_174 ;
if ( V_2 -> V_11 . V_25 != V_58 )
return 0 ;
V_68 = F_32 ( V_2 ) ;
if ( F_33 ( V_68 ) )
return F_34 ( V_68 ) ;
V_169 = V_68 -> V_70 ;
memset ( V_169 , 0 , sizeof *V_169 ) ;
V_169 -> V_59 = F_51 ( V_59 ) ;
V_169 -> V_135 = V_2 -> V_11 . V_12 ;
V_169 -> V_126 = F_51 ( V_126 << V_136 |
V_59 ) ;
V_169 -> V_137 = F_51 ( V_171 << V_138 |
V_59 ) ;
V_169 -> V_175 = 0 ;
V_169 -> V_176 = V_177 ;
V_169 -> V_178 = 0 ;
V_169 -> V_179 = V_180 ;
V_69 = V_134 << 8 | V_18 ;
V_23 = F_35 ( V_2 , V_68 -> V_73 , V_69 , 1 , V_74 ,
V_75 , V_87 ) ;
F_36 ( V_2 , V_68 ) ;
return V_23 ;
}
int F_67 ( struct V_1 * V_2 , T_1 V_18 , T_1 * V_181 )
{
struct V_67 * V_68 ;
struct V_182 * V_169 ;
int V_23 ;
T_4 V_69 ;
int V_5 ;
V_68 = F_32 ( V_2 ) ;
if ( F_33 ( V_68 ) )
return F_34 ( V_68 ) ;
V_169 = V_68 -> V_70 ;
memset ( V_169 , 0 , sizeof *V_169 ) ;
for ( V_5 = 0 ; V_5 < V_183 ; V_5 += 2 )
V_169 -> V_181 [ V_5 >> 1 ] = V_181 [ V_5 ] << 4 | V_181 [ V_5 + 1 ] ;
V_69 = V_184 << 8 | V_18 ;
V_23 = F_35 ( V_2 , V_68 -> V_73 , V_69 , 1 , V_74 ,
V_75 , V_76 ) ;
F_36 ( V_2 , V_68 ) ;
return V_23 ;
}
int F_68 ( struct V_1 * V_2 , T_1 V_18 , T_1 * V_185 ,
T_1 * V_186 , T_6 * V_187 )
{
struct V_67 * V_68 ;
struct V_188 * V_169 ;
int V_23 ;
T_4 V_69 ;
int V_5 ;
V_68 = F_32 ( V_2 ) ;
if ( F_33 ( V_68 ) )
return F_34 ( V_68 ) ;
V_169 = V_68 -> V_70 ;
memset ( V_169 , 0 , sizeof *V_169 ) ;
for ( V_5 = 0 ; V_5 < V_189 ; V_5 ++ ) {
struct V_190 * V_191 = & V_169 -> V_191 [ V_5 ] ;
T_6 V_192 = V_187 && V_187 [ V_5 ] ? V_187 [ V_5 ] :
V_193 ;
V_191 -> V_186 = F_69 ( V_186 [ V_5 ] ) ;
V_191 -> V_194 = F_69 ( V_185 [ V_5 ] ) ;
V_191 -> V_195 = F_69 ( V_196 ) ;
V_191 -> V_197 = F_69 ( V_192 ) ;
}
V_69 = V_198 << 8 | V_18 ;
V_23 = F_35 ( V_2 , V_68 -> V_73 , V_69 , 1 , V_74 ,
V_75 , V_76 ) ;
F_36 ( V_2 , V_68 ) ;
return V_23 ;
}
int F_70 ( struct V_1 * V_2 , int V_108 ,
struct V_147 * V_148 ,
struct V_67 * V_110 ,
struct V_67 * V_149 ,
struct V_150 * V_151 )
{
int V_23 = 0 ;
return V_23 ;
}
int F_71 ( struct V_1 * V_2 , T_1 V_18 ,
T_2 V_19 , T_2 V_199 , T_1 V_200 )
{
return F_35 ( V_2 , ( V_19 | ( V_199 << 63 ) ) , V_18 , V_200 ,
V_201 , V_75 ,
V_87 ) ;
}
int F_72 ( struct V_1 * V_2 , int V_108 ,
struct V_147 * V_148 ,
struct V_67 * V_110 ,
struct V_67 * V_149 ,
struct V_150 * V_151 )
{
int V_23 = 0 ;
return V_23 ;
}
int F_73 ( struct V_1 * V_2 , int V_108 ,
T_4 V_69 , struct V_67 * V_149 )
{
return F_57 ( V_2 , 0 , V_149 -> V_73 , V_69 , 0 ,
V_202 , V_75 ,
V_76 ) ;
}
int F_74 ( struct V_1 * V_2 , int V_108 ,
struct V_147 * V_148 ,
struct V_67 * V_110 ,
struct V_67 * V_149 ,
struct V_150 * V_151 )
{
if ( V_108 != V_2 -> V_11 . V_132 )
return 0 ;
return F_73 ( V_2 , V_108 ,
V_148 -> V_125 , V_149 ) ;
}
void F_75 ( struct V_1 * V_2 , T_2 * V_203 )
{
if ( ! F_41 ( V_2 ) ) {
* V_203 = 0 ;
return;
}
* V_203 = ( V_204 |
V_205 |
V_206 ) ;
if ( F_64 ( V_2 ) )
* V_203 |= V_207 ;
}
