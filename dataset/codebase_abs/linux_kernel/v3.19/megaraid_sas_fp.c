T_1 F_1 ( T_2 V_1 , T_1 V_2 )
{
T_2 V_3 ;
T_1 V_4 ;
if ( ! V_2 )
F_2 ( V_5 L_1 ) ;
V_3 = V_1 ;
V_4 = F_3 ( V_3 , V_2 ) ;
return V_4 ;
}
T_2 F_4 ( T_3 V_1 , T_4 V_2 )
{
T_1 V_4 ;
T_2 V_3 ;
if ( ! V_2 )
F_2 ( V_5 L_2 ) ;
V_3 = V_1 ;
V_4 = F_3 ( V_3 , V_2 ) ;
return V_3 ;
}
struct V_6 * F_5 ( T_1 V_7 , struct V_8 * V_9 )
{
return & V_9 -> V_10 . V_11 [ V_7 ] . V_12 ;
}
static struct V_13 * F_6 ( T_1 V_7 ,
struct V_8
* V_9 )
{
return & V_9 -> V_10 . V_11 [ V_7 ] . V_14 [ 0 ] ;
}
static T_5 F_7 ( T_1 V_7 , T_1 V_15 , struct V_8 * V_9 )
{
return V_9 -> V_10 . V_11 [ V_7 ] . V_16 [ V_15 ] ;
}
T_6 F_8 ( T_1 V_17 , T_1 V_18 , struct V_8 * V_9 )
{
return F_9 ( V_9 -> V_10 . V_19 [ V_17 ] . V_20 [ V_18 ] ) ;
}
T_6 F_10 ( T_1 V_7 , T_1 V_21 , struct V_8 * V_9 )
{
return F_9 ( V_9 -> V_10 . V_11 [ V_7 ] . V_14 [ V_21 ] . V_21 . V_22 ) ;
}
T_6 F_11 ( T_1 V_20 , struct V_8 * V_9 )
{
return V_9 -> V_10 . V_23 [ V_20 ] . V_24 ;
}
T_6 F_12 ( T_1 V_7 , struct V_8 * V_9 )
{
return F_9 ( V_9 -> V_10 . V_11 [ V_7 ] . V_12 . V_25 ) ;
}
T_5 F_13 ( T_1 V_26 , struct V_8 * V_9 )
{
return V_9 -> V_10 . V_27 [ V_26 ] ;
}
static struct V_28 * F_14 ( T_1 V_7 , T_1 V_21 ,
struct V_8 * V_9 )
{
return & V_9 -> V_10 . V_11 [ V_7 ] . V_14 [ V_21 ] . V_21 ;
}
void F_15 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_33 ;
struct V_34 * V_35 = NULL ;
struct V_36 * V_37 = NULL ;
int V_38 ;
struct V_8 * V_39 =
V_32 -> V_40 [ ( V_30 -> V_41 & 1 ) ] ;
struct V_42 * V_43 = & V_39 -> V_10 ;
if ( V_30 -> V_44 ) {
memcpy ( V_32 -> V_40 [ V_30 -> V_41 & 1 ] ,
V_32 -> V_45 [ V_30 -> V_41 & 1 ] ,
V_32 -> V_46 ) ;
V_43 -> V_47 =
F_16 ( sizeof( struct V_48 ) ) ;
} else {
V_35 = (struct V_34 * )
V_32 -> V_45 [ ( V_30 -> V_41 & 1 ) ] ;
V_37 = & V_35 -> V_10 ;
#if V_49
for ( V_38 = 0 ; V_38 < F_9 ( V_37 -> V_50 ) ; V_38 ++ ) {
F_17 ( & V_30 -> V_51 -> V_52 , L_3
L_4 ,
V_30 -> V_53 , V_38 ,
V_35 -> V_10 . V_11 [ V_38 ] . V_12 . V_25 ,
V_35 -> V_10 . V_11 [ V_38 ] . V_12 . V_54 ,
V_35 -> V_10 . V_11 [ V_38 ] . V_12 . V_55 ) ;
}
#endif
memset ( V_39 , 0 , V_32 -> V_56 ) ;
V_43 -> V_47 = V_37 -> V_47 ;
V_43 -> V_50 = ( V_57 ) V_37 -> V_50 ;
V_43 -> V_58 = V_37 -> V_58 ;
for ( V_38 = 0 ; V_38 < V_59 + V_60 ; V_38 ++ )
V_43 -> V_27 [ V_38 ] =
( T_5 ) V_37 -> V_27 [ V_38 ] ;
for ( V_38 = 0 ; V_38 < F_9 ( V_43 -> V_50 ) ; V_38 ++ ) {
V_43 -> V_11 [ V_38 ] = V_37 -> V_11 [ V_38 ] ;
#if V_49
F_17 ( & V_30 -> V_51 -> V_52 ,
L_5
L_6
L_7 , V_38 , V_38 ,
V_37 -> V_11 [ V_38 ] . V_12 . V_25 ,
V_37 -> V_11 [ V_38 ] . V_12 . V_54 ,
( T_1 ) V_37 -> V_11 [ V_38 ] . V_12 . V_61 ) ;
F_17 ( & V_30 -> V_51 -> V_52 ,
L_8
L_9
L_7 , V_38 , V_38 ,
V_43 -> V_11 [ V_38 ] . V_12 . V_25 ,
V_43 -> V_11 [ V_38 ] . V_12 . V_54 ,
( T_1 ) V_43 -> V_11 [ V_38 ] . V_12 . V_61 ) ;
F_17 ( & V_30 -> V_51 -> V_52 , L_10
L_11 , V_39 ,
V_43 , & V_37 -> V_11 [ V_38 ] . V_12 ,
& V_43 -> V_11 [ V_38 ] . V_12 ) ;
#endif
}
memcpy ( V_43 -> V_19 , V_37 -> V_19 ,
sizeof( struct V_62 ) * V_63 ) ;
memcpy ( V_43 -> V_23 , V_37 -> V_23 ,
sizeof( struct V_64 ) *
V_65 ) ;
}
}
T_5 F_18 ( struct V_29 * V_30 )
{
struct V_31 * V_32 ;
struct V_8 * V_39 ;
struct V_42 * V_43 ;
struct V_66 * V_67 ;
T_7 V_68 ;
struct V_6 * V_69 ;
int V_50 , V_70 ;
T_6 V_7 ;
T_1 V_71 ;
F_15 ( V_30 ) ;
V_32 = V_30 -> V_33 ;
V_39 = V_32 -> V_40 [ ( V_30 -> V_41 & 1 ) ] ;
V_43 = & V_39 -> V_10 ;
V_67 = V_32 -> V_72 ;
V_68 = V_32 -> V_73 ;
if ( V_30 -> V_44 )
V_71 = sizeof( struct V_48 ) ;
else
V_71 =
( sizeof( struct V_36 ) - sizeof( struct V_74 ) +
( sizeof( struct V_74 ) * F_9 ( V_43 -> V_50 ) ) ) ;
if ( F_19 ( V_43 -> V_47 ) != V_71 ) {
F_20 ( & V_30 -> V_51 -> V_52 , L_12 ,
( unsigned int ) V_71 ) ;
F_20 ( & V_30 -> V_51 -> V_52 , L_13 ,
( unsigned int ) sizeof( struct V_74 ) ,
F_19 ( V_43 -> V_47 ) ) ;
return 0 ;
}
if ( V_30 -> V_75 )
F_21 ( V_39 , V_68 ) ;
F_22 ( V_39 , V_67 ) ;
V_70 = F_9 ( V_39 -> V_10 . V_50 ) ;
for ( V_50 = 0 ; V_50 < V_70 ; V_50 ++ ) {
V_7 = F_13 ( V_50 , V_39 ) ;
V_69 = F_5 ( V_7 , V_39 ) ;
F_23 ( ( T_1 * ) & V_69 -> V_76 ) ;
}
return 1 ;
}
T_1 F_24 ( T_1 V_7 , T_2 V_77 , T_2 * V_78 ,
struct V_8 * V_9 )
{
struct V_13 * V_79 = F_6 ( V_7 , V_9 ) ;
struct V_80 * V_81 ;
struct V_6 * V_69 = F_5 ( V_7 , V_9 ) ;
T_1 V_21 , V_82 ;
for ( V_21 = 0 ; V_21 < V_69 -> V_83 ; V_21 ++ , V_79 ++ ) {
for ( V_82 = 0 ; V_82 < F_19 ( V_79 -> V_84 . V_85 ) ; V_82 ++ ) {
V_81 = & V_79 -> V_84 . V_81 [ V_82 ] ;
if ( F_19 ( V_81 -> V_86 ) == 0 )
return V_87 ;
if ( F_25 ( V_81 -> V_88 ) <= V_77 && V_77 <=
F_25 ( V_81 -> V_89 ) && ( F_1 ( V_77 - F_25 ( V_81 -> V_88 ) ,
F_19 ( V_81 -> V_86 ) ) ) == 0 ) {
if ( V_78 != NULL ) {
T_2 V_90 , V_91 ;
V_90 = F_4 ( ( V_77 - F_25 ( V_81 -> V_88 ) ) , F_19 ( V_81 -> V_86 ) ) ;
V_91 = V_90 ;
V_90 = ( V_90 + F_25 ( V_81 -> V_92 ) ) << V_69 -> V_93 ;
* V_78 = V_90 ;
}
return V_21 ;
}
}
}
return V_87 ;
}
static int F_26 ( struct V_8 * V_9 ,
T_7 V_68 )
{
T_5 V_21 ;
T_1 V_94 ;
struct V_6 * V_69 ;
T_8 * V_95 ;
struct V_80 * V_81 ;
int V_50 ;
T_6 V_7 ;
for ( V_50 = 0 ; V_50 < V_96 ; V_50 ++ ) {
V_7 = F_13 ( V_50 , V_9 ) ;
if ( V_7 >= V_96 )
continue;
V_69 = F_5 ( V_7 , V_9 ) ;
F_17 ( & V_30 -> V_51 -> V_52 , L_14 ,
V_7 , V_69 -> V_83 ) ;
for ( V_21 = 0 ; V_21 < V_69 -> V_83 ; V_21 ++ )
F_17 ( & V_30 -> V_51 -> V_52 , L_15
L_16 , V_21 ,
F_19 ( V_9 -> V_10 . V_11 [ V_7 ] . V_14 [ V_21 ] .
V_84 . V_85 ) ) ;
for ( V_94 = 0 ; V_94 < V_97 ; V_94 ++ ) {
V_95 = & ( V_68 [ V_7 ] . V_95 [ V_94 ] ) ;
if ( V_95 -> V_98 == 0 )
break;
F_17 ( & V_30 -> V_51 -> V_52 , L_17
L_18 , V_94 ,
( unsigned int ) V_95 -> V_98 ,
( unsigned int ) V_95 -> V_86 ) ;
F_17 ( & V_30 -> V_51 -> V_52 , L_19
L_20 ,
( long unsigned int ) V_95 -> V_99 ,
( long unsigned int ) V_95 -> V_100 ) ;
F_17 ( & V_30 -> V_51 -> V_52 , L_21
L_22 ,
( long unsigned int ) V_95 -> V_101 ,
( long unsigned int ) V_95 -> V_102 ) ;
F_17 ( & V_30 -> V_51 -> V_52 , L_23
L_22 ,
( long unsigned int ) V_95 -> V_103 ,
( long unsigned int ) V_95 -> V_104 ) ;
F_17 ( & V_30 -> V_51 -> V_52 , L_24
L_22 ,
( long unsigned int ) V_95 -> V_105 ,
( long unsigned int ) V_95 -> V_106 ) ;
for ( V_21 = 0 ; V_21 < V_69 -> V_83 ; V_21 ++ ) {
if ( F_19 ( V_9 -> V_10 . V_11 [ V_7 ] . V_14 [ V_21 ] .
V_84 . V_85 ) >=
V_94 + 1 ) {
V_81 = & V_9 -> V_10 . V_11 [ V_7 ] .
V_14 [ V_21 ] . V_84 .
V_81 [ V_94 ] ;
F_17 ( & V_30 -> V_51 -> V_52 , L_15
L_25 , V_21 ,
V_94 , F_19 ( V_81 -> V_86 ) ) ;
F_17 ( & V_30 -> V_51 -> V_52 ,
L_26 ,
( long unsigned int ) F_25 ( V_81 -> V_92 ) ) ;
F_17 ( & V_30 -> V_51 -> V_52 ,
L_27 ,
( long unsigned int ) F_25 ( V_81 -> V_88 ) ,
( long unsigned int ) F_25 ( V_81 -> V_89 ) ) ;
}
}
}
}
return 0 ;
}
T_1 F_27 ( struct V_29 * V_30 ,
T_1 V_7 , T_2 V_77 , T_2 * V_78 , struct V_8 * V_9 )
{
struct V_31 * V_32 = V_30 -> V_33 ;
struct V_6 * V_69 = F_5 ( V_7 , V_9 ) ;
T_8 * V_95 ;
struct V_80 * V_81 ;
T_1 V_21 , V_107 ;
T_7 V_68 = V_32 -> V_73 ;
for ( V_107 = 0 ; V_107 < V_97 ; V_107 ++ ) {
V_95 = & ( V_68 [ V_7 ] . V_95 [ V_107 ] ) ;
if ( V_95 -> V_98 == 0 )
break;
if ( V_77 > V_95 -> V_104 )
continue;
for ( V_21 = 0 ; V_21 < V_69 -> V_83 ; V_21 ++ )
if ( F_19 ( V_9 -> V_10 . V_11 [ V_7 ] . V_14 [ V_21 ] .
V_84 . V_85 ) >= V_107 + 1 ) {
V_81 = & V_9 -> V_10 . V_11 [ V_7 ] .
V_14 [ V_21 ] .
V_84 . V_81 [ V_107 ] ;
if ( F_19 ( V_81 -> V_86 ) == 0 )
return V_87 ;
if ( F_25 ( V_81 -> V_88 ) <= V_77 &&
V_77 <= F_25 ( V_81 -> V_89 ) &&
( F_1 ( V_77 - F_25 ( V_81 -> V_88 ) ,
F_19 ( V_81 -> V_86 ) ) ) == 0 ) {
if ( V_78 != NULL ) {
T_2 V_90 ;
V_90 = F_4
( ( V_77 - F_25 ( V_81 -> V_88 ) ) ,
F_19 ( V_81 -> V_86 ) ) ;
V_90 = ( V_90 + F_25 ( V_81 -> V_92 ) )
<< V_69 -> V_93 ;
* V_78 = V_90 ;
}
return V_21 ;
}
}
}
return V_87 ;
}
static T_2 F_28 ( struct V_29 * V_30 ,
T_1 V_7 , T_2 V_108 , struct V_8 * V_9 )
{
struct V_31 * V_32 = V_30 -> V_33 ;
struct V_6 * V_69 = F_5 ( V_7 , V_9 ) ;
T_8 * V_95 ;
T_7 V_68 = V_32 -> V_73 ;
T_1 V_107 , V_109 , V_21 , V_110 ;
T_2 V_111 , V_112 , V_113 ;
for ( V_107 = 0 ; V_107 < V_97 ; V_107 ++ ) {
V_95 = & ( V_68 [ V_7 ] . V_95 [ V_107 ] ) ;
if ( V_95 -> V_98 == 0 )
break;
if ( V_108 > V_95 -> V_106 )
continue;
V_111 = V_108 - V_95 -> V_105 ;
V_109 = F_1 ( V_111 ,
V_95 -> V_98 ) ;
V_112 = F_4 ( V_111 ,
V_95 -> V_98 ) * V_95 -> V_86 ;
for ( V_21 = 0 , V_110 = 0 ; V_21 < V_69 -> V_83 ; V_21 ++ )
if ( F_19 ( V_9 -> V_10 . V_11 [ V_7 ] . V_14 [ V_21 ] .
V_84 . V_85 ) >= V_107 + 1 ) {
if ( V_109 >=
V_95 -> V_109 [ V_21 ] )
V_110 ++ ;
else
break;
}
#if V_114
F_29 ( & V_30 -> V_51 -> V_52 , L_28
L_29
L_30 , V_108 ,
( unsigned long long ) V_111 ,
( unsigned long long ) V_112 ,
( unsigned long long ) V_95 -> V_98 ,
V_110 ) ;
F_29 ( & V_30 -> V_51 -> V_52 , L_31
L_32 , V_108 ,
( unsigned long long ) V_95 -> V_103 +
( unsigned long long ) V_112 + ( V_110 - 1 ) ) ;
#endif
V_113 = ( V_95 -> V_103 + V_112 +
( V_110 - 1 ) ) ;
return V_113 ;
}
return - 1LLU ;
}
static T_2 F_30 ( struct V_29 * V_30 ,
T_1 V_7 , T_2 V_77 , struct V_8 * V_9 )
{
struct V_31 * V_32 = V_30 -> V_33 ;
struct V_6 * V_69 = F_5 ( V_7 , V_9 ) ;
T_8 * V_95 ;
struct V_80 * V_81 ;
T_7 V_68 = V_32 -> V_73 ;
T_1 V_21 , V_107 ;
T_2 V_108 ;
for ( V_107 = 0 ; V_107 < V_97 ; V_107 ++ ) {
V_95 = & ( V_68 [ V_7 ] . V_95 [ V_107 ] ) ;
if ( V_95 -> V_98 == 0 )
break;
if ( V_77 > V_95 -> V_104 )
continue;
for ( V_21 = 0 ; V_21 < V_69 -> V_83 ; V_21 ++ )
if ( F_19 ( V_9 -> V_10 . V_11 [ V_7 ] . V_14 [ V_21 ] .
V_84 . V_85 ) >= V_107 + 1 ) {
V_81 = & V_9 -> V_10 . V_11 [ V_7 ] .
V_14 [ V_21 ] . V_84 . V_81 [ V_107 ] ;
if ( F_25 ( V_81 -> V_88 ) <= V_77 &&
V_77 <= F_25 ( V_81 -> V_89 ) &&
F_1 ( ( V_77 - F_25 ( V_81 -> V_88 ) ) ,
F_19 ( V_81 -> V_86 ) ) == 0 ) {
V_108 = F_4
( ( ( V_77 - V_95 -> V_103 )
- F_25 ( V_81 -> V_88 ) ) ,
F_19 ( V_81 -> V_86 ) ) ;
V_108 *= V_95 -> V_98 ;
V_108 += V_95 -> V_105 ;
V_108 += V_95 -> V_109 [ V_21 ] ;
return V_108 ;
}
}
}
F_20 ( & V_30 -> V_51 -> V_52 , L_33
L_34 ,
V_7 , ( long unsigned int ) V_77 ) ;
return - 1 ;
}
static T_1 F_31 ( struct V_29 * V_30 ,
T_1 V_7 , T_2 V_108 , struct V_8 * V_9 )
{
struct V_31 * V_32 = V_30 -> V_33 ;
struct V_6 * V_69 = F_5 ( V_7 , V_9 ) ;
T_8 * V_95 ;
T_7 V_68 = V_32 -> V_73 ;
T_1 V_107 , V_109 , V_21 , V_110 , V_113 ;
for ( V_107 = 0 ; V_107 < V_97 ; V_107 ++ ) {
V_95 = & ( V_68 [ V_7 ] . V_95 [ V_107 ] ) ;
if ( V_95 -> V_98 == 0 )
break;
if ( V_108 > V_95 -> V_106 )
continue;
V_109 = ( V_115 ) F_1
( ( V_108 - V_95 -> V_105 ) ,
V_95 -> V_98 ) ;
for ( V_21 = 0 , V_110 = 0 ; V_21 < V_69 -> V_83 ; V_21 ++ )
if ( F_19 ( V_9 -> V_10 . V_11 [ V_7 ] . V_14 [ V_21 ] .
V_84 . V_85 ) >= V_107 + 1 ) {
if ( V_109 >=
V_95 -> V_109 [ V_21 ] )
V_110 =
V_95 -> V_109 [ V_21 ] ;
else
break;
}
#if V_114
F_29 ( & V_30 -> V_51 -> V_52 , L_35
L_36 , V_7 ,
( long unsigned int ) V_108 , ( V_109 - V_110 ) ) ;
#endif
V_113 = ( V_109 - V_110 ) ;
return V_113 ;
}
F_20 ( & V_30 -> V_51 -> V_52 , L_37
L_38 ,
V_7 , ( long unsigned int ) V_108 ) ;
return - 1 ;
}
T_5 F_32 ( struct V_29 * V_30 , T_1 V_7 , T_5 V_21 , T_2 V_116 ,
struct V_8 * V_9 )
{
struct V_6 * V_69 = F_5 ( V_7 , V_9 ) ;
T_1 V_18 = 0 ;
switch ( V_69 -> V_117 ) {
case 0 :
case 5 :
case 6 :
V_18 = F_1 ( V_116 , F_33 ( V_9 , V_7 , V_21 ) ) ;
break;
case 1 :
V_18 = F_31 ( V_30 , V_7 , V_116 , V_9 ) ;
if ( V_18 != - 1U )
V_18 *= 2 ;
break;
}
return V_18 ;
}
static T_5 F_34 ( struct V_29 * V_30 , T_1 V_7 ,
T_2 V_118 , T_6 V_119 , struct V_120 * V_121 ,
struct V_122 * V_123 ,
struct V_8 * V_9 )
{
struct V_6 * V_69 = F_5 ( V_7 , V_9 ) ;
T_1 V_20 , V_124 ;
T_5 V_125 , V_21 ;
T_2 V_77 ;
T_5 V_113 = TRUE ;
T_5 V_126 = 0 ;
T_2 * V_127 = & V_121 -> V_127 ;
T_6 * V_128 = & V_121 -> V_129 ;
T_1 V_130 , V_131 , V_132 , V_18 ;
if ( ( V_30 -> V_51 -> V_133 == V_134 ||
V_30 -> V_51 -> V_133 == V_135 ) )
V_126 = 1 ;
V_77 = V_121 -> V_136 ;
V_21 = V_121 -> V_137 ;
if ( V_69 -> V_117 == 6 ) {
V_130 = F_31 ( V_30 , V_7 , V_118 , V_9 ) ;
if ( V_130 == - 1U )
return FALSE ;
V_131 = F_1 ( V_77 , F_33 ( V_9 , V_7 , V_21 ) ) ;
V_132 = F_33 ( V_9 , V_7 , V_21 ) - 1 - V_131 ;
V_18 = V_132 + 1 + V_130 ;
if ( V_18 >= F_33 ( V_9 , V_7 , V_21 ) )
V_18 -= F_33 ( V_9 , V_7 , V_21 ) ;
V_125 = ( T_5 ) V_18 ;
} else
V_125 = F_32 ( V_30 , V_7 , V_21 , V_118 , V_9 ) ;
if ( V_125 == 0xFF )
return FALSE ;
V_124 = F_10 ( V_7 , V_21 , V_9 ) ;
V_20 = F_8 ( V_124 , V_125 , V_9 ) ;
if ( V_20 != V_138 )
* V_128 = F_11 ( V_20 , V_9 ) ;
else {
* V_128 = V_138 ;
if ( ( V_69 -> V_117 >= 5 ) &&
( ! V_126 || ( V_126 &&
( V_69 -> V_139 != V_140 ) ) ) )
V_123 -> V_141 = V_142 ;
else if ( V_69 -> V_117 == 1 ) {
V_20 = F_8 ( V_124 , V_125 + 1 , V_9 ) ;
if ( V_20 != V_138 )
* V_128 = F_11 ( V_20 , V_9 ) ;
}
}
* V_127 += V_119 + F_25 ( F_14 ( V_7 , V_21 , V_9 ) -> V_143 ) ;
V_123 -> V_144 = ( V_21 << V_145 ) |
V_125 ;
V_121 -> V_146 = V_123 -> V_144 ;
return V_113 ;
}
T_5 F_35 ( struct V_29 * V_30 , T_1 V_7 , T_2 V_118 ,
T_6 V_119 , struct V_120 * V_121 ,
struct V_122 * V_123 ,
struct V_8 * V_9 )
{
struct V_6 * V_69 = F_5 ( V_7 , V_9 ) ;
T_1 V_20 , V_124 ;
T_5 V_125 , V_21 ;
T_2 V_77 ;
T_5 V_113 = TRUE ;
T_5 V_126 = 0 ;
T_2 * V_127 = & V_121 -> V_127 ;
T_6 * V_128 = & V_121 -> V_129 ;
if ( ( V_30 -> V_51 -> V_133 == V_134 ||
V_30 -> V_51 -> V_133 == V_135 ) )
V_126 = 1 ;
V_77 = F_4 ( V_118 , V_69 -> V_147 ) ;
if ( V_69 -> V_117 == 6 ) {
T_1 V_130 = F_1 ( V_118 , V_69 -> V_147 ) ;
T_1 V_131 , V_132 , V_18 ;
if ( V_69 -> V_61 == 0 )
return FALSE ;
V_131 = F_1 ( V_77 , V_69 -> V_61 ) ;
V_132 = V_69 -> V_61 - 1 - V_131 ;
V_18 = V_132 + 1 + V_130 ;
if ( V_18 >= V_69 -> V_61 )
V_18 -= V_69 -> V_61 ;
V_125 = ( T_5 ) V_18 ;
} else {
if ( V_69 -> V_148 == 0 )
return FALSE ;
V_125 = F_7 ( V_7 , F_1 ( V_118 ,
V_69 -> V_148 ) ,
V_9 ) ;
}
if ( V_69 -> V_83 == 1 ) {
V_21 = 0 ;
* V_127 = V_77 << V_69 -> V_93 ;
} else {
V_21 = ( T_5 ) F_24 ( V_7 , V_77 , V_127 , V_9 ) ;
if ( V_21 == V_87 )
return FALSE ;
}
V_124 = F_10 ( V_7 , V_21 , V_9 ) ;
V_20 = F_8 ( V_124 , V_125 , V_9 ) ;
if ( V_20 != V_138 )
* V_128 = F_11 ( V_20 , V_9 ) ;
else {
* V_128 = V_138 ;
if ( ( V_69 -> V_117 >= 5 ) &&
( ! V_126 || ( V_126 &&
( V_69 -> V_139 != V_140 ) ) ) )
V_123 -> V_141 = V_142 ;
else if ( V_69 -> V_117 == 1 ) {
V_20 = F_8 ( V_124 , V_125 + 1 , V_9 ) ;
if ( V_20 != V_138 )
* V_128 = F_11 ( V_20 , V_9 ) ;
}
}
* V_127 += V_119 + F_25 ( F_14 ( V_7 , V_21 , V_9 ) -> V_143 ) ;
V_123 -> V_144 = ( V_21 << V_145 ) |
V_125 ;
V_121 -> V_146 = V_123 -> V_144 ;
return V_113 ;
}
T_5
F_36 ( struct V_29 * V_30 ,
struct V_120 * V_121 ,
struct V_122 * V_123 ,
struct V_8 * V_9 , T_5 * * V_149 )
{
struct V_6 * V_69 ;
T_1 V_7 , V_150 , V_151 ;
T_2 V_152 , V_153 , V_154 , V_136 , V_155 ;
T_2 V_156 ;
T_1 V_157 ;
T_5 V_158 , V_159 ;
T_6 V_160 , V_161 ;
T_2 V_162 ;
T_1 V_163 , V_26 ;
T_5 V_164 ;
T_5 V_113 = 0 ;
T_5 V_165 = V_87 ;
T_2 * V_127 = & V_121 -> V_127 ;
V_162 = V_121 -> V_162 ;
V_163 = V_121 -> V_163 ;
V_26 = V_121 -> V_26 ;
V_164 = V_121 -> V_164 ;
V_121 -> V_166 = 0 ;
V_121 -> V_137 = V_87 ;
V_7 = F_13 ( V_26 , V_9 ) ;
V_69 = F_5 ( V_7 , V_9 ) ;
if ( V_69 -> V_147 == 0 ) {
if ( F_14 ( V_7 , 0 , V_9 ) -> V_167 == 0 )
return FALSE ;
else if ( V_30 -> V_75 ) {
V_121 -> V_166 = 1 ;
} else {
F_29 ( & V_30 -> V_51 -> V_52 ,
L_39
L_40
L_41 ,
F_14 ( V_7 , 0 , V_9 ) -> V_167 ) ;
return FALSE ;
}
}
V_150 = 1 << V_69 -> V_93 ;
V_151 = V_150 - 1 ;
V_155 = V_162 >> V_69 -> V_93 ;
V_160 = ( T_6 ) ( V_162 & V_151 ) ;
V_152 = V_162 + V_163 - 1 ;
V_161 = ( T_6 ) ( V_152 & V_151 ) ;
V_153 = V_152 >> V_69 -> V_93 ;
V_158 = ( T_5 ) ( V_153 - V_155 + 1 ) ;
if ( V_121 -> V_166 ) {
V_136 = F_28 ( V_30 , V_7 , V_155 , V_9 ) ;
V_154 = F_28 ( V_30 , V_7 , V_153 , V_9 ) ;
if ( V_136 == - 1ULL || V_154 == - 1ULL ) {
F_29 ( & V_30 -> V_51 -> V_52 , L_42
L_43 ,
V_168 , __LINE__ ) ;
return FALSE ;
}
if ( V_69 -> V_83 == 1 ) {
V_165 = 0 ;
* V_127 = V_136 << V_69 -> V_93 ;
} else
V_165 = ( T_5 ) F_27 ( V_30 ,
V_7 , V_136 , V_127 , V_9 ) ;
if ( V_165 == V_87 ) {
F_29 ( & V_30 -> V_51 -> V_52 , L_44
L_45
L_46 , V_168 , __LINE__ ,
( unsigned long long ) V_136 ,
( unsigned long long ) V_155 ,
( unsigned long long ) V_153 ) ;
return FALSE ;
}
V_121 -> V_137 = V_165 ;
V_121 -> V_136 = V_136 ;
#if V_114
F_17 ( & V_30 -> V_51 -> V_52 , L_47
L_48
L_49 , V_168 , __LINE__ ,
( unsigned long long ) V_136 ,
( unsigned long long ) V_155 ,
( unsigned long long ) V_153 , V_165 ) ;
F_17 ( & V_30 -> V_51 -> V_52 , L_50
L_51 , ( unsigned long long ) V_136 ,
( unsigned long long ) V_154 , V_165 ) ;
#endif
} else {
V_136 = F_4 ( V_155 , V_69 -> V_147 ) ;
V_154 = F_4 ( V_153 , V_69 -> V_147 ) ;
}
V_159 = ( T_5 ) ( V_154 - V_136 + 1 ) ;
V_156 = V_136 << V_69 -> V_93 ;
V_157 = V_150 ;
if ( V_69 -> V_76 . V_169 ) {
if ( V_164 )
V_121 -> V_170 = ( V_69 -> V_76 . V_171 &&
( ( V_158 == 1 ) ||
V_69 -> V_76 .
V_172 ) ) ;
else
V_121 -> V_170 = ( V_69 -> V_76 . V_173 &&
( ( V_158 == 1 ) ||
V_69 -> V_76 .
V_174 ) ) ;
} else
V_121 -> V_170 = FALSE ;
if ( V_159 == 1 ) {
if ( V_158 == 1 ) {
V_156 += V_160 ;
V_157 = V_163 ;
}
} else if ( V_121 -> V_166 == 0 ) {
if ( V_155 == ( V_136 + 1 ) * V_69 -> V_147 - 1 ) {
V_156 += V_160 ;
V_157 = V_150 - V_160 ;
}
if ( V_159 > 2 )
V_157 += ( V_159 - 2 ) << V_69 -> V_93 ;
if ( V_153 == V_154 * V_69 -> V_147 )
V_157 += V_161 + 1 ;
else
V_157 += V_150 ;
} else {
if ( V_155 == ( F_30 ( V_30 , V_7 , V_136 , V_9 ) +
F_37 ( V_9 , V_7 , V_165 ) - 1 ) ) {
V_156 += V_160 ;
V_157 = V_150 - V_160 ;
}
if ( V_159 > 2 )
V_157 += ( V_159 - 2 ) << V_69 -> V_93 ;
if ( V_153 == F_30 ( V_30 , V_7 , V_154 , V_9 ) )
V_157 += V_161 + 1 ;
else
V_157 += V_150 ;
}
V_123 -> V_175 =
F_38 ( V_69 -> V_176 ?
V_69 -> V_176 :
V_9 -> V_10 . V_58 ) ;
if ( ( V_30 -> V_51 -> V_133 == V_134 ) ||
( V_30 -> V_51 -> V_133 == V_135 ) )
V_123 -> V_141 = ( V_164 ) ?
V_69 -> V_139 : V_69 -> V_177 ;
else
V_123 -> V_141 = ( V_164 ) ?
V_178 : V_69 -> V_177 ;
V_123 -> V_179 = V_69 -> V_25 ;
V_123 -> V_180 = F_39 ( V_156 ) ;
V_123 -> V_181 = F_16 ( V_157 ) ;
V_123 -> V_182 = V_69 -> V_54 ;
* V_149 = V_69 -> V_183 ;
if ( V_121 -> V_170 ) {
V_113 = V_121 -> V_166 ?
F_34 ( V_30 , V_7 ,
V_155 , V_160 ,
V_121 , V_123 , V_9 ) :
F_35 ( V_30 , V_7 , V_155 ,
V_160 , V_121 ,
V_123 , V_9 ) ;
if ( V_121 -> V_129 == V_138 )
V_121 -> V_170 = FALSE ;
return V_113 ;
} else if ( V_164 ) {
V_115 V_184 ;
for ( V_184 = 0 ; V_184 < V_158 ; V_184 ++ ) {
V_113 = V_121 -> V_166 ?
F_34 ( V_30 , V_7 ,
V_155 + V_184 ,
V_160 , V_121 ,
V_123 , V_9 ) :
F_35 ( V_30 , V_7 ,
V_155 + V_184 , V_160 ,
V_121 , V_123 , V_9 ) ;
if ( ! V_113 )
return TRUE ;
}
}
#if V_114
if ( V_121 -> V_166 )
F_31 ( V_30 , V_7 , V_155 , V_9 ) ;
#endif
return TRUE ;
}
void F_21 ( struct V_8 * V_9 ,
T_7 V_68 )
{
T_5 V_21 , V_185 ;
T_1 V_94 , V_186 ;
T_2 V_187 ;
struct V_6 * V_69 ;
T_8 * V_95 , * V_188 ;
struct V_80 * V_81 ;
int V_50 ;
T_6 V_7 ;
for ( V_50 = 0 ; V_50 < V_96 ; V_50 ++ ) {
V_7 = F_13 ( V_50 , V_9 ) ;
if ( V_7 >= V_96 )
continue;
V_69 = F_5 ( V_7 , V_9 ) ;
for ( V_94 = 0 ; V_94 < V_97 ; V_94 ++ ) {
for ( V_21 = 0 ; V_21 < V_69 -> V_83 ; V_21 ++ ) {
if ( F_19 ( V_9 -> V_10 . V_11 [ V_7 ] . V_14 [ V_21 ] .
V_84 . V_85 ) <
V_94 + 1 )
continue;
V_95 = & ( V_68 [ V_7 ] . V_95 [ V_94 ] ) ;
V_81 = & V_9 -> V_10 . V_11 [ V_7 ] .
V_14 [ V_21 ] . V_84 .
V_81 [ V_94 ] ;
V_95 -> V_86 = F_19 ( V_81 -> V_86 ) ;
for ( V_185 = 0 , V_186 = 0 ;
V_185 < V_69 -> V_83 ; V_185 ++ ) {
if ( F_19 ( V_9 -> V_10 . V_11 [ V_7 ] .
V_14 [ V_185 ] .
V_84 .
V_85 ) >= V_94 + 1 ) {
V_95 -> V_109 [ V_185 ] =
V_186 ;
V_186 +=
F_14
( V_7 , V_185 , V_9 ) -> V_167 ;
F_2 ( V_189 L_52
L_53 ,
V_185 , F_14
( V_7 , V_185 , V_9 ) -> V_167 ) ;
}
}
V_95 -> V_98 = V_186 ;
V_187 = F_4 ( ( ( F_25 ( V_81 -> V_89 ) -
F_25 ( V_81 -> V_88 ) ) + F_19 ( V_81 -> V_86 ) ) ,
F_19 ( V_81 -> V_86 ) ) ;
if ( V_94 == 0 ) {
V_95 -> V_99 = 0 ;
V_95 -> V_100 =
( ( V_187 << V_69 -> V_93 )
* V_186 ) - 1 ;
V_95 -> V_101 = 0 ;
V_95 -> V_102 = V_187 - 1 ;
V_95 -> V_105 = 0 ;
V_95 -> V_106 =
( V_187 * V_186 ) - 1 ;
V_95 -> V_103 = 0 ;
V_95 -> V_104 =
( V_187 * F_19 ( V_81 -> V_86 ) ) - 1 ;
} else {
V_188 = & ( V_68 [ V_7 ] .
V_95 [ V_94 - 1 ] ) ;
V_95 -> V_99 =
V_188 -> V_100 + 1 ;
V_95 -> V_100 =
V_95 -> V_99 +
( ( V_187 << V_69 -> V_93 )
* V_186 ) - 1 ;
V_95 -> V_101 =
V_188 -> V_102 + 1 ;
V_95 -> V_102 =
V_95 -> V_101 + V_187 - 1 ;
V_95 -> V_105 =
V_188 -> V_106 + 1 ;
V_95 -> V_106 =
V_95 -> V_105 +
( V_187 * V_186 ) - 1 ;
V_95 -> V_103 =
V_188 -> V_104 + 1 ;
V_95 -> V_104 =
V_95 -> V_103 +
( V_187 * F_19 ( V_81 -> V_86 ) ) - 1 ;
}
break;
}
if ( V_21 == V_69 -> V_83 )
break;
}
}
#if V_114
F_26 ( V_9 , V_68 ) ;
#endif
}
void F_22 ( struct V_8 * V_39 ,
struct V_66 * V_67 )
{
int V_50 ;
T_6 V_7 ;
struct V_6 * V_69 ;
if ( V_190 > 128 || V_190 < 1 )
V_190 = V_191 ;
for ( V_50 = 0 ; V_50 < V_96 ; V_50 ++ ) {
V_7 = F_13 ( V_50 , V_39 ) ;
if ( V_7 >= V_96 ) {
V_67 [ V_50 ] . V_192 = 0 ;
continue;
}
V_69 = F_5 ( V_7 , V_39 ) ;
if ( ( V_69 -> V_117 != 1 ) ||
( V_69 -> V_193 != V_194 ) ) {
V_67 [ V_50 ] . V_192 = 0 ;
continue;
}
V_67 [ V_50 ] . V_192 = 1 ;
}
}
T_5 F_40 ( struct V_29 * V_30 ,
struct V_66 * V_67 , struct V_120 * V_121 )
{
struct V_31 * V_32 ;
struct V_6 * V_69 ;
struct V_8 * V_39 ;
T_6 V_195 , V_196 , V_7 ;
T_2 V_197 , V_198 ;
T_5 V_199 , V_200 , V_201 , V_21 , V_18 ;
T_1 V_124 , V_202 ;
T_2 V_203 = V_121 -> V_162 ;
T_1 V_185 = V_121 -> V_163 ;
V_21 = ( ( V_121 -> V_146 & V_204 )
>> V_145 ) ;
V_18 = ( V_121 -> V_146 & V_205 ) ;
V_32 = V_30 -> V_33 ;
V_39 = V_32 -> V_40 [ ( V_30 -> V_41 & 1 ) ] ;
V_7 = F_13 ( V_121 -> V_26 , V_39 ) ;
V_69 = F_5 ( V_7 , V_39 ) ;
V_202 = V_30 -> V_75 ?
F_33 ( V_39 , V_7 , V_21 ) : V_69 -> V_61 ;
V_124 = F_10 ( V_7 , V_21 , V_39 ) ;
V_200 = F_8 ( V_124 , V_18 , V_39 ) ;
V_201 = F_8 ( V_124 , ( V_18 + 1 ) >= V_202 ?
( V_18 + 1 - V_202 ) : V_18 + 1 , V_39 ) ;
V_195 = F_41 ( & V_67 -> V_206 [ V_200 ] ) ;
V_196 = F_41 ( & V_67 -> V_206 [ V_201 ] ) ;
V_197 = F_42 ( V_203 , V_67 -> V_207 [ V_200 ] ) ;
V_198 = F_42 ( V_203 , V_67 -> V_207 [ V_201 ] ) ;
V_199 = ( V_197 <= V_198 ? V_18 : V_18 ^ 1 ) ;
if ( ( V_199 == V_18 && V_195 > V_196 + V_190 ) ||
( V_199 != V_18 && V_196 > V_195 + V_190 ) )
V_199 ^= 1 ;
V_121 -> V_208 = ( V_199 == V_18 ) ? V_200 : V_201 ;
V_67 -> V_207 [ V_121 -> V_208 ] = V_203 + V_185 - 1 ;
V_121 -> V_146 = ( V_21 << V_145 ) | V_199 ;
#if V_114
if ( V_18 != V_199 )
F_17 ( & V_30 -> V_51 -> V_52 , L_54
L_55
L_56 ,
V_21 , V_18 , V_199 , V_121 -> V_146 ) ;
#endif
return V_121 -> V_208 ;
}
T_6 F_43 ( struct V_29 * V_30 ,
struct V_66 * V_67 , struct V_120 * V_121 )
{
T_5 V_209 ;
T_6 V_129 ;
struct V_31 * V_32 ;
struct V_8 * V_39 ;
V_32 = V_30 -> V_33 ;
V_39 = V_32 -> V_40 [ ( V_30 -> V_41 & 1 ) ] ;
V_209 = F_40 ( V_30 , V_67 , V_121 ) ;
V_129 = F_11 ( V_209 , V_39 ) ;
F_44 ( & V_67 -> V_206 [ V_209 ] ) ;
return V_129 ;
}
