static int F_1 ( int V_1 , T_1 V_2 , T_2 * V_3 ,
unsigned V_4 , T_3 * V_5 )
{
int V_6 = - V_7 ;
T_1 V_8 = 4 ;
T_4 * V_9 ;
int V_10 , V_11 ;
T_5 * V_12 ;
struct V_13 * V_14 ;
struct V_15 V_16 ;
const struct V_15 * V_17 ;
if ( ! V_5 ) return - V_18 ;
V_12 = ( T_5 * ) V_5 -> V_3 ;
if ( ! V_12 ) return - V_18 ;
if ( V_4 && V_19 > 1 ) {
F_2 ( L_1 , V_2 , V_4 ) ;
for ( V_10 = 0 ; V_10 < V_4 ; V_10 += 16 ) {
F_2 ( L_2 , V_10 ,
F_3 ( & V_3 [ V_10 ] ) ,
F_3 ( & V_3 [ V_10 + 4 ] ) ,
F_3 ( & V_3 [ V_10 + 8 ] ) ,
F_3 ( & V_3 [ V_10 + 12 ] ) ) ;
}
}
V_9 = ( T_4 * ) & V_12 [ 1 ] ;
V_12 -> V_20 = F_4 ( 16 ) ;
V_14 = V_21 [ V_1 ] . V_22 ;
V_17 = F_5 ( V_14 , & V_16 ) ;
switch ( V_2 ) {
case V_23 :
F_2 ( L_3 , V_24 ) ;
V_8 = sizeof( V_25 ) ;
V_11 = V_8 / sizeof( T_1 ) ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
V_9 [ V_10 ] = F_4 ( V_25 [ V_10 ] ) ;
V_6 = 0 ;
break;
case V_26 :
F_2 ( L_4 , V_24 ) ;
* V_9 = F_4 ( 0 ) ;
V_6 = 0 ;
break;
case V_27 :
F_2 ( L_5 , V_24 ) ;
* V_9 = F_4 ( V_21 [ V_1 ] . V_28 ) ;
V_6 = 0 ;
break;
case V_29 :
F_2 ( L_6 , V_24 ) ;
* V_9 = F_4 ( V_21 [ V_1 ] . V_28 ) ;
V_6 = 0 ;
break;
case V_30 :
F_2 ( L_7 , V_24 ) ;
if ( V_21 [ V_1 ] . V_22 ) {
* V_9 = F_4 (
V_21 [ V_1 ] . V_22 -> V_31 ) ;
V_6 = 0 ;
}
break;
case V_32 :
if ( V_19 > 1 )
F_2 ( L_8 , V_24 ) ;
if ( V_21 [ V_1 ] . V_33
== V_34 )
* V_9 = F_4 ( 0 ) ;
else
* V_9 = F_4 (
V_21 [ V_1 ] . V_35 ) ;
V_6 = 0 ;
break;
case V_36 :
F_2 ( L_9 , V_24 ) ;
if ( V_21 [ V_1 ] . V_22 ) {
* V_9 = F_4 (
V_21 [ V_1 ] . V_22 -> V_31 ) ;
V_6 = 0 ;
}
break;
case V_37 :
F_2 ( L_10 , V_24 ) ;
if ( V_21 [ V_1 ] . V_22 ) {
* V_9 = F_4 (
V_21 [ V_1 ] . V_22 -> V_31 ) ;
V_6 = 0 ;
}
break;
case V_38 :
F_2 ( L_11 , V_24 ) ;
* V_9 = F_4 (
V_21 [ V_1 ] . V_39 ) ;
V_6 = 0 ;
break;
case V_40 :
F_2 ( L_12 , V_24 ) ;
if ( V_21 [ V_1 ] . V_41 ) {
V_8 = strlen ( V_21 [ V_1 ] .
V_41 ) ;
memcpy ( V_9 ,
V_21 [ V_1 ] . V_41 ,
V_8 ) ;
} else {
V_9 [ 0 ] = 0 ;
}
V_6 = 0 ;
break;
case V_42 :
F_2 ( L_13 , V_24 ) ;
* V_9 = V_43 ;
V_6 = 0 ;
break;
case V_44 :
F_2 ( L_14 , V_24 ) ;
* V_9 = F_4 ( * V_21 [ V_1 ] . V_45 ) ;
V_6 = 0 ;
break;
case V_46 :
F_2 ( L_15 , V_24 ) ;
* V_9 = F_4 ( V_47 ) ;
V_6 = 0 ;
break;
case V_48 :
if ( V_19 > 1 )
F_2 ( L_16 , V_24 ) ;
* V_9 = F_4 ( V_21 [ V_1 ]
. V_33 ) ;
V_6 = 0 ;
break;
case V_49 :
F_2 ( L_17 , V_24 ) ;
* V_9 = F_4 ( 0 ) ;
V_6 = 0 ;
break;
case V_50 :
F_2 ( L_18 , V_24 ) ;
* V_9 = F_4 (
V_51
| V_52 ) ;
V_6 = 0 ;
break;
case V_53 :
if ( V_19 > 1 )
F_2 ( L_19 , V_24 ) ;
if ( V_17 ) {
* V_9 = F_4 ( V_17 -> V_54
- V_17 -> V_55 - V_17 -> V_56 ) ;
V_6 = 0 ;
}
break;
case V_57 :
if ( V_19 > 1 )
F_2 ( L_20 , V_24 ) ;
if ( V_17 ) {
* V_9 = F_4 ( V_17 -> V_58
- V_17 -> V_59 - V_17 -> V_60 ) ;
V_6 = 0 ;
}
break;
case V_61 :
if ( V_19 > 1 )
F_2 ( L_21 , V_24 ) ;
if ( V_17 ) {
* V_9 = F_4 ( V_17 -> V_55 ) ;
V_6 = 0 ;
}
break;
case V_62 :
if ( V_19 > 1 )
F_2 ( L_22 , V_24 ) ;
if ( V_17 ) {
* V_9 = F_4 ( V_17 -> V_59 ) ;
V_6 = 0 ;
}
break;
case V_63 :
F_2 ( L_23 , V_24 ) ;
if ( V_17 ) {
* V_9 = F_4 ( V_17 -> V_60 ) ;
V_6 = 0 ;
}
break;
case V_64 :
F_2 ( L_24 , V_24 ) ;
if ( V_21 [ V_1 ] . V_22 ) {
V_8 = V_65 ;
memcpy ( V_9 ,
V_21 [ V_1 ] . V_66 ,
V_8 ) ;
V_6 = 0 ;
}
break;
case V_67 :
F_2 ( L_25 , V_24 ) ;
if ( V_21 [ V_1 ] . V_22 ) {
V_8 = V_65 ;
memcpy ( V_9 ,
V_21 [ V_1 ] . V_66 ,
V_8 ) ;
V_6 = 0 ;
}
break;
case V_68 :
F_2 ( L_26 , V_24 ) ;
* V_9 = F_4 ( 0xE0000000 ) ;
V_6 = 0 ;
break;
case V_69 :
F_2 ( L_27 , V_24 ) ;
* V_9 = F_4 ( 1 ) ;
V_6 = 0 ;
break;
case V_70 :
F_2 ( L_28 , V_24 ) ;
* V_9 = F_4 ( 0 ) ;
V_6 = 0 ;
break;
case V_71 :
F_2 ( L_29 , V_24 ) ;
if ( V_17 ) {
* V_9 = F_4 ( V_17 -> V_72 ) ;
V_6 = 0 ;
}
break;
case V_73 :
F_2 ( L_30 , V_24 ) ;
* V_9 = F_4 ( 0 ) ;
V_6 = 0 ;
break;
case V_74 :
F_2 ( L_31 , V_24 ) ;
* V_9 = F_4 ( 0 ) ;
V_6 = 0 ;
break;
default:
F_6 ( L_32 ,
V_24 , V_2 ) ;
}
if ( V_6 < 0 )
V_8 = 0 ;
V_12 -> V_75 = F_4 ( V_8 ) ;
V_5 -> V_8 = V_8 + sizeof( * V_12 ) ;
V_12 -> V_76 = F_4 ( V_5 -> V_8 ) ;
return V_6 ;
}
static int F_7 ( T_2 V_1 , T_1 V_2 , T_2 * V_3 , T_1 V_4 ,
T_3 * V_5 )
{
T_6 * V_12 ;
int V_10 , V_6 = - V_7 ;
struct V_77 * V_78 ;
if ( ! V_5 )
return - V_18 ;
V_12 = ( T_6 * ) V_5 -> V_3 ;
if ( ! V_12 )
return - V_18 ;
if ( V_4 && V_19 > 1 ) {
F_2 ( L_33 , V_2 , V_4 ) ;
for ( V_10 = 0 ; V_10 < V_4 ; V_10 += 16 ) {
F_2 ( L_2 , V_10 ,
F_3 ( & V_3 [ V_10 ] ) ,
F_3 ( & V_3 [ V_10 + 4 ] ) ,
F_3 ( & V_3 [ V_10 + 8 ] ) ,
F_3 ( & V_3 [ V_10 + 12 ] ) ) ;
}
}
V_78 = & V_21 [ V_1 ] ;
switch ( V_2 ) {
case V_44 :
* V_78 -> V_45 = ( V_79 ) F_3 ( V_3 ) ;
F_2 ( L_34 ,
V_24 , * V_78 -> V_45 ) ;
V_6 = 0 ;
if ( * V_78 -> V_45 ) {
V_78 -> V_80 = V_81 ;
F_8 ( V_78 -> V_22 ) ;
if ( F_9 ( V_78 -> V_22 ) )
F_10 ( V_78 -> V_22 ) ;
} else {
V_78 -> V_80 = V_82 ;
F_11 ( V_78 -> V_22 ) ;
F_12 ( V_78 -> V_22 ) ;
}
break;
case V_68 :
F_2 ( L_26 , V_24 ) ;
V_6 = 0 ;
break;
default:
F_6 ( L_35 ,
V_24 , V_2 , V_4 ) ;
}
return V_6 ;
}
static int F_13 ( int V_1 , T_7 * V_3 )
{
T_8 * V_12 ;
T_3 * V_5 ;
struct V_77 * V_78 = V_21 + V_1 ;
if ( ! V_78 -> V_22 )
return - V_7 ;
V_5 = F_14 ( V_1 , sizeof( T_8 ) ) ;
if ( ! V_5 )
return - V_18 ;
V_12 = ( T_8 * ) V_5 -> V_3 ;
V_12 -> V_83 = F_4 ( V_84 ) ;
V_12 -> V_76 = F_4 ( 52 ) ;
V_12 -> V_85 = V_3 -> V_85 ;
V_12 -> V_86 = F_4 ( V_87 ) ;
V_12 -> V_88 = F_4 ( V_89 ) ;
V_12 -> V_90 = F_4 ( V_91 ) ;
V_12 -> V_92 = F_4 ( V_93 ) ;
V_12 -> V_94 = F_4 ( V_95 ) ;
V_12 -> V_96 = F_4 ( 1 ) ;
V_12 -> V_97 = F_4 (
V_78 -> V_22 -> V_31
+ sizeof( struct V_98 )
+ sizeof( struct V_99 )
+ 22 ) ;
V_12 -> V_100 = F_4 ( 0 ) ;
V_12 -> V_101 = F_4 ( 0 ) ;
V_12 -> V_102 = F_4 ( 0 ) ;
V_78 -> V_103 ( V_78 -> V_104 ) ;
return 0 ;
}
static int F_15 ( int V_1 , T_9 * V_3 )
{
T_5 * V_12 ;
T_3 * V_5 ;
struct V_77 * V_78 = V_21 + V_1 ;
if ( ! V_78 -> V_22 )
return - V_7 ;
V_5 = F_14 ( V_1 ,
sizeof( V_25 ) + sizeof( T_5 ) ) ;
if ( ! V_5 )
return - V_18 ;
V_12 = ( T_5 * ) V_5 -> V_3 ;
V_12 -> V_83 = F_4 ( V_105 ) ;
V_12 -> V_85 = V_3 -> V_85 ;
if ( F_1 ( V_1 , F_16 ( V_3 -> V_2 ) ,
F_16 ( V_3 -> V_20 )
+ 8 + ( T_2 * ) V_3 ,
F_16 ( V_3 -> V_75 ) ,
V_5 ) ) {
V_12 -> V_86 = F_4 ( V_106 ) ;
V_12 -> V_76 = F_4 ( sizeof *V_12 ) ;
V_12 -> V_75 = F_4 ( 0 ) ;
V_12 -> V_20 = F_4 ( 0 ) ;
} else
V_12 -> V_86 = F_4 ( V_87 ) ;
V_78 -> V_103 ( V_78 -> V_104 ) ;
return 0 ;
}
static int F_17 ( int V_1 , T_10 * V_3 )
{
T_1 V_107 , V_108 ;
T_6 * V_12 ;
T_3 * V_5 ;
struct V_77 * V_78 = V_21 + V_1 ;
V_5 = F_14 ( V_1 , sizeof( T_6 ) ) ;
if ( ! V_5 )
return - V_18 ;
V_12 = ( T_6 * ) V_5 -> V_3 ;
V_107 = F_16 ( V_3 -> V_75 ) ;
V_108 = F_16 ( V_3 -> V_20 ) ;
#ifdef F_18
F_2 ( L_36 , V_24 , V_107 ) ;
F_2 ( L_37 , V_24 , V_108 ) ;
F_2 ( L_38 , V_24 ) ;
for ( V_10 = 0 ; V_10 < V_107 ; V_10 ++ ) {
F_2 ( L_39 , * ( ( ( T_2 * ) V_3 ) + V_10 + 8 + V_108 ) ) ;
}
F_2 ( L_40 ) ;
#endif
V_12 -> V_83 = F_4 ( V_109 ) ;
V_12 -> V_76 = F_4 ( 16 ) ;
V_12 -> V_85 = V_3 -> V_85 ;
if ( F_7 ( V_1 , F_16 ( V_3 -> V_2 ) ,
( ( T_2 * ) V_3 ) + 8 + V_108 , V_107 , V_5 ) )
V_12 -> V_86 = F_4 ( V_106 ) ;
else
V_12 -> V_86 = F_4 ( V_87 ) ;
V_78 -> V_103 ( V_78 -> V_104 ) ;
return 0 ;
}
static int F_19 ( int V_1 , T_11 * V_3 )
{
T_12 * V_12 ;
T_3 * V_5 ;
struct V_77 * V_78 = V_21 + V_1 ;
V_5 = F_14 ( V_1 , sizeof( T_12 ) ) ;
if ( ! V_5 )
return - V_18 ;
V_12 = ( T_12 * ) V_5 -> V_3 ;
V_12 -> V_83 = F_4 ( V_110 ) ;
V_12 -> V_76 = F_4 ( 16 ) ;
V_12 -> V_86 = F_4 ( V_87 ) ;
V_12 -> V_111 = F_4 ( 1 ) ;
V_78 -> V_103 ( V_78 -> V_104 ) ;
return 0 ;
}
static int F_20 ( int V_1 ,
T_13 * V_3 )
{
T_14 * V_12 ;
T_3 * V_5 ;
struct V_77 * V_78 = V_21 + V_1 ;
V_5 = F_14 ( V_1 , sizeof( T_14 ) ) ;
if ( ! V_5 )
return - V_18 ;
V_12 = ( T_14 * ) V_5 -> V_3 ;
V_12 -> V_83 = F_4 ( V_112 ) ;
V_12 -> V_76 = F_4 ( 16 ) ;
V_12 -> V_85 = V_3 -> V_85 ;
V_12 -> V_86 = F_4 ( V_87 ) ;
V_78 -> V_103 ( V_78 -> V_104 ) ;
return 0 ;
}
static int F_21 ( int V_1 , T_1 V_113 )
{
T_15 * V_12 ;
T_3 * V_5 ;
struct V_77 * V_78 = V_21 + V_1 ;
if ( V_78 -> V_80 == V_114 )
return - V_7 ;
V_5 = F_14 ( V_1 ,
sizeof( T_15 ) ) ;
if ( ! V_5 )
return - V_18 ;
V_12 = ( T_15 * ) V_5 -> V_3 ;
V_12 -> V_83 = F_4 ( V_115 ) ;
V_12 -> V_76 = F_4 ( 20 ) ;
V_12 -> V_86 = F_4 ( V_113 ) ;
V_12 -> V_116 = F_4 ( 0 ) ;
V_12 -> V_117 = F_4 ( 0 ) ;
V_78 -> V_103 ( V_78 -> V_104 ) ;
return 0 ;
}
int F_22 ( int V_1 )
{
V_21 [ V_1 ] . V_33
= V_118 ;
return F_21 ( V_1 ,
V_119 ) ;
}
int F_23 ( int V_1 )
{
V_21 [ V_1 ] . V_33
= V_34 ;
return F_21 ( V_1 ,
V_120 ) ;
}
void F_24 ( int V_1 )
{
T_2 * V_3 ;
T_1 V_8 ;
if ( V_1 >= V_121 )
return;
V_21 [ V_1 ] . V_80 = V_114 ;
while ( ( V_3 = F_25 ( V_1 , & V_8 ) ) )
F_26 ( V_1 , V_3 ) ;
}
void F_27 ( int V_1 , const T_2 * V_122 )
{
V_21 [ V_1 ] . V_66 = V_122 ;
}
int F_28 ( T_2 V_1 , T_2 * V_3 )
{
T_1 V_123 , V_124 ;
T_4 * V_125 ;
struct V_77 * V_78 ;
if ( ! V_3 )
return - V_18 ;
V_125 = ( T_4 * ) V_3 ;
V_123 = F_3 ( V_125 ++ ) ;
V_124 = F_3 ( V_125 ++ ) ;
if ( V_1 >= V_121 )
return - V_7 ;
V_78 = & V_21 [ V_1 ] ;
switch ( V_123 ) {
case V_126 :
F_2 ( L_41 ,
V_24 ) ;
V_78 -> V_80 = V_82 ;
return F_13 ( V_1 ,
( T_7 * ) V_3 ) ;
case V_127 :
F_2 ( L_42 ,
V_24 ) ;
V_78 -> V_80 = V_114 ;
if ( V_78 -> V_22 ) {
F_11 ( V_78 -> V_22 ) ;
F_12 ( V_78 -> V_22 ) ;
}
return 0 ;
case V_128 :
return F_15 ( V_1 ,
( T_9 * ) V_3 ) ;
case V_129 :
return F_17 ( V_1 ,
( T_10 * ) V_3 ) ;
case V_130 :
F_2 ( L_43 ,
V_24 ) ;
return F_19 ( V_1 ,
( T_11 * ) V_3 ) ;
case V_131 :
if ( V_19 > 1 )
F_2 ( L_44 ,
V_24 ) ;
return F_20 ( V_1 ,
( T_13 * )
V_3 ) ;
default:
F_6 ( L_45 ,
V_24 , V_123 , V_124 ) ;
F_29 ( V_24 , V_132 ,
V_3 , V_124 ) ;
break;
}
return - V_7 ;
}
int F_30 ( void (* V_103)( void * V_104 ) , void * V_104 )
{
T_2 V_10 ;
if ( ! V_103 )
return - V_133 ;
for ( V_10 = 0 ; V_10 < V_121 ; V_10 ++ ) {
if ( ! V_21 [ V_10 ] . V_134 ) {
V_21 [ V_10 ] . V_134 = 1 ;
V_21 [ V_10 ] . V_103 = V_103 ;
V_21 [ V_10 ] . V_104 = V_104 ;
F_2 ( L_46 , V_24 , V_10 ) ;
return V_10 ;
}
}
F_2 ( L_47 ) ;
return - V_135 ;
}
void F_31 ( int V_1 )
{
F_2 ( L_48 , V_24 ) ;
if ( V_1 >= V_121 ) return;
V_21 [ V_1 ] . V_134 = 0 ;
}
int F_32 ( T_2 V_1 , struct V_13 * V_22 , V_79 * V_136 )
{
F_2 ( L_48 , V_24 ) ;
if ( ! V_22 )
return - V_133 ;
if ( V_1 >= V_121 ) return - 1 ;
V_21 [ V_1 ] . V_22 = V_22 ;
V_21 [ V_1 ] . V_45 = V_136 ;
return 0 ;
}
int F_33 ( T_2 V_1 , T_1 V_39 , const char * V_41 )
{
F_2 ( L_48 , V_24 ) ;
if ( ! V_41 ) return - 1 ;
if ( V_1 >= V_121 ) return - 1 ;
V_21 [ V_1 ] . V_39 = V_39 ;
V_21 [ V_1 ] . V_41 = V_41 ;
return 0 ;
}
int F_34 ( T_2 V_1 , T_1 V_28 , T_1 V_35 )
{
F_2 ( L_49 , V_24 , V_28 , V_35 ) ;
if ( V_1 >= V_121 ) return - 1 ;
V_21 [ V_1 ] . V_28 = V_28 ;
V_21 [ V_1 ] . V_35 = V_35 ;
return 0 ;
}
void F_35 ( struct V_137 * V_138 )
{
struct V_99 * V_139 ;
if ( ! V_138 )
return;
V_139 = ( void * ) F_36 ( V_138 , sizeof( * V_139 ) ) ;
memset ( V_139 , 0 , sizeof *V_139 ) ;
V_139 -> V_83 = F_4 ( V_140 ) ;
V_139 -> V_76 = F_4 ( V_138 -> V_141 ) ;
V_139 -> V_142 = F_4 ( 36 ) ;
V_139 -> V_143 = F_4 ( V_138 -> V_141 - sizeof( * V_139 ) ) ;
}
void F_26 ( int V_1 , T_2 * V_3 )
{
T_3 * V_5 ;
struct V_144 * V_145 , * V_125 ;
F_37 (act, tmp,
&(rndis_per_dev_params[configNr].resp_queue))
{
V_5 = F_38 ( V_145 , T_3 , V_146 ) ;
if ( V_5 && V_5 -> V_3 == V_3 ) {
F_39 ( & V_5 -> V_146 ) ;
F_40 ( V_5 ) ;
}
}
}
T_2 * F_25 ( int V_1 , T_1 * V_8 )
{
T_3 * V_5 ;
struct V_144 * V_145 , * V_125 ;
if ( ! V_8 ) return NULL ;
F_37 (act, tmp,
&(rndis_per_dev_params[configNr].resp_queue))
{
V_5 = F_38 ( V_145 , T_3 , V_146 ) ;
if ( ! V_5 -> V_147 ) {
V_5 -> V_147 = 1 ;
* V_8 = V_5 -> V_8 ;
return V_5 -> V_3 ;
}
}
return NULL ;
}
static T_3 * F_14 ( int V_1 , T_1 V_8 )
{
T_3 * V_5 ;
V_5 = F_41 ( sizeof( T_3 ) + V_8 , V_148 ) ;
if ( ! V_5 ) return NULL ;
V_5 -> V_3 = ( T_2 * ) ( V_5 + 1 ) ;
V_5 -> V_8 = V_8 ;
V_5 -> V_147 = 0 ;
F_42 ( & V_5 -> V_146 ,
& ( V_21 [ V_1 ] . V_149 ) ) ;
return V_5 ;
}
int F_43 ( struct V_150 * V_151 ,
struct V_137 * V_138 ,
struct V_152 * V_146 )
{
T_4 * V_125 = ( void * ) V_138 -> V_153 ;
if ( F_4 ( V_140 )
!= F_44 ( V_125 ++ ) ) {
F_45 ( V_138 ) ;
return - V_133 ;
}
V_125 ++ ;
if ( ! F_46 ( V_138 , F_3 ( V_125 ++ ) + 8 ) ) {
F_45 ( V_138 ) ;
return - V_154 ;
}
F_47 ( V_138 , F_3 ( V_125 ++ ) ) ;
F_48 ( V_146 , V_138 ) ;
return 0 ;
}
static int F_49 ( struct V_155 * V_156 , void * V_104 )
{
V_77 * V_157 = V_156 -> V_158 ;
F_50 (m,
L_50
L_51
L_52
L_53
L_54
L_55
L_56
L_57 ,
param->confignr, (param->used) ? L_58 : L_59 ,
({ char *s = L_60;
switch (param->state) {
case RNDIS_UNINITIALIZED:
s = L_61; break;
case RNDIS_INITIALIZED:
s = L_62; break;
case RNDIS_DATA_INITIALIZED:
s = L_63; break;
}; s; }),
param->medium,
(param->media_state) ? 0 : param->speed*100 ,
(param->media_state) ? L_64 : L_65 ,
param->vendorID, param->vendorDescr) ;
return 0 ;
}
static T_16 F_51 ( struct V_159 * V_159 , const char T_17 * V_160 ,
T_18 V_11 , T_19 * V_161 )
{
V_77 * V_162 = F_52 ( F_53 ( V_159 ) ) -> V_153 ;
T_1 V_35 = 0 ;
int V_10 , V_163 = 0 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
char V_164 ;
if ( F_54 ( V_164 , V_160 ) )
return - V_165 ;
switch ( V_164 ) {
case '0' :
case '1' :
case '2' :
case '3' :
case '4' :
case '5' :
case '6' :
case '7' :
case '8' :
case '9' :
V_163 = 1 ;
V_35 = V_35 * 10 + V_164 - '0' ;
break;
case 'C' :
case 'c' :
F_22 ( V_162 -> V_166 ) ;
break;
case 'D' :
case 'd' :
F_23 ( V_162 -> V_166 ) ;
break;
default:
if ( V_163 ) V_162 -> V_35 = V_35 ;
else F_2 ( L_66 , V_164 ) ;
break;
}
V_160 ++ ;
}
return V_11 ;
}
static int F_55 ( struct V_167 * V_167 , struct V_159 * V_159 )
{
return F_56 ( V_159 , F_49 , F_52 ( V_167 ) -> V_153 ) ;
}
int F_57 ( void )
{
T_2 V_10 ;
for ( V_10 = 0 ; V_10 < V_121 ; V_10 ++ ) {
#ifdef F_58
char V_168 [ 20 ] ;
sprintf ( V_168 , V_169 , V_10 ) ;
V_170 [ V_10 ] = F_59 ( V_168 , 0660 , NULL ,
& V_171 ,
( void * ) ( V_21 + V_10 ) ) ;
if ( ! V_170 [ V_10 ] ) {
F_2 ( L_67 , V_24 ) ;
while ( V_10 ) {
sprintf ( V_168 , V_169 , -- V_10 ) ;
F_60 ( V_168 , NULL ) ;
}
F_2 ( L_40 ) ;
return - V_172 ;
}
#endif
V_21 [ V_10 ] . V_166 = V_10 ;
V_21 [ V_10 ] . V_134 = 0 ;
V_21 [ V_10 ] . V_80 = V_114 ;
V_21 [ V_10 ] . V_33
= V_34 ;
F_61 ( & ( V_21 [ V_10 ] . V_149 ) ) ;
}
return 0 ;
}
void F_62 ( void )
{
#ifdef F_58
T_2 V_10 ;
char V_168 [ 20 ] ;
for ( V_10 = 0 ; V_10 < V_121 ; V_10 ++ ) {
sprintf ( V_168 , V_169 , V_10 ) ;
F_60 ( V_168 , NULL ) ;
}
#endif
}
