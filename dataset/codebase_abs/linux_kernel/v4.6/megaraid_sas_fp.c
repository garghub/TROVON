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
T_7 F_11 ( T_1 V_20 , struct V_8 * V_9 )
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
T_6 V_39 ;
struct V_8 * V_40 =
V_32 -> V_41 [ ( V_30 -> V_42 & 1 ) ] ;
struct V_43 * V_44 = & V_40 -> V_10 ;
if ( V_30 -> V_45 ) {
memcpy ( V_32 -> V_41 [ V_30 -> V_42 & 1 ] ,
V_32 -> V_46 [ V_30 -> V_42 & 1 ] ,
V_32 -> V_47 ) ;
V_44 -> V_48 =
F_16 ( sizeof( struct V_49 ) ) ;
} else {
V_35 = (struct V_34 * )
V_32 -> V_46 [ ( V_30 -> V_42 & 1 ) ] ;
V_37 = & V_35 -> V_10 ;
V_39 = ( T_6 ) F_17 ( V_37 -> V_50 ) ;
#if V_51
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ ) {
F_18 ( & V_30 -> V_52 -> V_53 , L_3
L_4 ,
V_30 -> V_54 , V_38 ,
V_35 -> V_10 . V_11 [ V_38 ] . V_12 . V_25 ,
V_35 -> V_10 . V_11 [ V_38 ] . V_12 . V_55 ,
V_35 -> V_10 . V_11 [ V_38 ] . V_12 . V_56 ) ;
}
#endif
memset ( V_40 , 0 , V_32 -> V_57 ) ;
V_44 -> V_48 = V_37 -> V_48 ;
V_44 -> V_50 = ( T_7 ) F_19 ( V_39 ) ;
V_44 -> V_58 = V_37 -> V_58 ;
for ( V_38 = 0 ; V_38 < V_59 + V_60 ; V_38 ++ )
V_44 -> V_27 [ V_38 ] =
( T_5 ) V_37 -> V_27 [ V_38 ] ;
for ( V_38 = ( V_59 + V_60 ) ;
V_38 < V_61 ; V_38 ++ )
V_44 -> V_27 [ V_38 ] = 0xff ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ ) {
V_44 -> V_11 [ V_38 ] = V_37 -> V_11 [ V_38 ] ;
#if V_51
F_18 ( & V_30 -> V_52 -> V_53 ,
L_5
L_6
L_7 , V_38 , V_38 ,
V_37 -> V_11 [ V_38 ] . V_12 . V_25 ,
V_37 -> V_11 [ V_38 ] . V_12 . V_55 ,
( T_1 ) V_37 -> V_11 [ V_38 ] . V_12 . V_62 ) ;
F_18 ( & V_30 -> V_52 -> V_53 ,
L_8
L_9
L_7 , V_38 , V_38 ,
V_44 -> V_11 [ V_38 ] . V_12 . V_25 ,
V_44 -> V_11 [ V_38 ] . V_12 . V_55 ,
( T_1 ) V_44 -> V_11 [ V_38 ] . V_12 . V_62 ) ;
F_18 ( & V_30 -> V_52 -> V_53 , L_10
L_11 , V_40 ,
V_44 , & V_37 -> V_11 [ V_38 ] . V_12 ,
& V_44 -> V_11 [ V_38 ] . V_12 ) ;
#endif
}
memcpy ( V_44 -> V_19 , V_37 -> V_19 ,
sizeof( struct V_63 ) * V_64 ) ;
memcpy ( V_44 -> V_23 , V_37 -> V_23 ,
sizeof( struct V_65 ) *
V_66 ) ;
}
}
T_5 F_20 ( struct V_29 * V_30 )
{
struct V_31 * V_32 ;
struct V_8 * V_40 ;
struct V_43 * V_44 ;
struct V_67 * V_68 ;
T_8 V_69 ;
struct V_6 * V_70 ;
T_6 V_50 , V_71 ;
T_6 V_7 ;
T_1 V_72 ;
F_15 ( V_30 ) ;
V_32 = V_30 -> V_33 ;
V_40 = V_32 -> V_41 [ ( V_30 -> V_42 & 1 ) ] ;
V_44 = & V_40 -> V_10 ;
V_68 = V_32 -> V_73 ;
V_69 = V_32 -> V_74 ;
if ( V_30 -> V_45 )
V_72 = sizeof( struct V_49 ) ;
else
V_72 =
( sizeof( struct V_36 ) - sizeof( struct V_75 ) +
( sizeof( struct V_75 ) * F_9 ( V_44 -> V_50 ) ) ) ;
if ( F_17 ( V_44 -> V_48 ) != V_72 ) {
F_21 ( & V_30 -> V_52 -> V_53 , L_12 ,
( unsigned int ) V_72 ) ;
F_21 ( & V_30 -> V_52 -> V_53 , L_13 ,
( unsigned int ) sizeof( struct V_75 ) ,
F_17 ( V_44 -> V_48 ) ) ;
return 0 ;
}
if ( V_30 -> V_76 )
F_22 ( V_40 , V_69 ) ;
F_23 ( V_40 , V_68 ) ;
V_71 = F_9 ( V_40 -> V_10 . V_50 ) ;
for ( V_50 = 0 ; V_50 < V_71 ; V_50 ++ ) {
V_7 = F_13 ( V_50 , V_40 ) ;
V_70 = F_5 ( V_7 , V_40 ) ;
F_24 ( ( T_1 * ) & V_70 -> V_77 ) ;
}
return 1 ;
}
T_1 F_25 ( T_1 V_7 , T_2 V_78 , T_2 * V_79 ,
struct V_8 * V_9 )
{
struct V_13 * V_80 = F_6 ( V_7 , V_9 ) ;
struct V_81 * V_82 ;
struct V_6 * V_70 = F_5 ( V_7 , V_9 ) ;
T_1 V_21 , V_83 ;
for ( V_21 = 0 ; V_21 < V_70 -> V_84 ; V_21 ++ , V_80 ++ ) {
for ( V_83 = 0 ; V_83 < F_17 ( V_80 -> V_85 . V_86 ) ; V_83 ++ ) {
V_82 = & V_80 -> V_85 . V_82 [ V_83 ] ;
if ( F_17 ( V_82 -> V_87 ) == 0 )
return V_88 ;
if ( F_26 ( V_82 -> V_89 ) <= V_78 && V_78 <=
F_26 ( V_82 -> V_90 ) && ( F_1 ( V_78 - F_26 ( V_82 -> V_89 ) ,
F_17 ( V_82 -> V_87 ) ) ) == 0 ) {
if ( V_79 != NULL ) {
T_2 V_91 , V_92 ;
V_91 = F_4 ( ( V_78 - F_26 ( V_82 -> V_89 ) ) , F_17 ( V_82 -> V_87 ) ) ;
V_92 = V_91 ;
V_91 = ( V_91 + F_26 ( V_82 -> V_93 ) ) << V_70 -> V_94 ;
* V_79 = V_91 ;
}
return V_21 ;
}
}
}
return V_88 ;
}
static int F_27 ( struct V_8 * V_9 ,
T_8 V_69 )
{
T_5 V_21 ;
T_1 V_95 ;
struct V_6 * V_70 ;
T_9 * V_96 ;
struct V_81 * V_82 ;
int V_50 ;
T_6 V_7 ;
for ( V_50 = 0 ; V_50 < V_61 ; V_50 ++ ) {
V_7 = F_13 ( V_50 , V_9 ) ;
if ( V_7 >= ( V_61 - 1 ) )
continue;
V_70 = F_5 ( V_7 , V_9 ) ;
F_18 ( & V_30 -> V_52 -> V_53 , L_14 ,
V_7 , V_70 -> V_84 ) ;
for ( V_21 = 0 ; V_21 < V_70 -> V_84 ; V_21 ++ )
F_18 ( & V_30 -> V_52 -> V_53 , L_15
L_16 , V_21 ,
F_17 ( V_9 -> V_10 . V_11 [ V_7 ] . V_14 [ V_21 ] .
V_85 . V_86 ) ) ;
for ( V_95 = 0 ; V_95 < V_97 ; V_95 ++ ) {
V_96 = & ( V_69 [ V_7 ] . V_96 [ V_95 ] ) ;
if ( V_96 -> V_98 == 0 )
break;
F_18 ( & V_30 -> V_52 -> V_53 , L_17
L_18 , V_95 ,
( unsigned int ) V_96 -> V_98 ,
( unsigned int ) V_96 -> V_87 ) ;
F_18 ( & V_30 -> V_52 -> V_53 , L_19
L_20 ,
( long unsigned int ) V_96 -> V_99 ,
( long unsigned int ) V_96 -> V_100 ) ;
F_18 ( & V_30 -> V_52 -> V_53 , L_21
L_22 ,
( long unsigned int ) V_96 -> V_101 ,
( long unsigned int ) V_96 -> V_102 ) ;
F_18 ( & V_30 -> V_52 -> V_53 , L_23
L_22 ,
( long unsigned int ) V_96 -> V_103 ,
( long unsigned int ) V_96 -> V_104 ) ;
F_18 ( & V_30 -> V_52 -> V_53 , L_24
L_22 ,
( long unsigned int ) V_96 -> V_105 ,
( long unsigned int ) V_96 -> V_106 ) ;
for ( V_21 = 0 ; V_21 < V_70 -> V_84 ; V_21 ++ ) {
if ( F_17 ( V_9 -> V_10 . V_11 [ V_7 ] . V_14 [ V_21 ] .
V_85 . V_86 ) >=
V_95 + 1 ) {
V_82 = & V_9 -> V_10 . V_11 [ V_7 ] .
V_14 [ V_21 ] . V_85 .
V_82 [ V_95 ] ;
F_18 ( & V_30 -> V_52 -> V_53 , L_15
L_25 , V_21 ,
V_95 , F_17 ( V_82 -> V_87 ) ) ;
F_18 ( & V_30 -> V_52 -> V_53 ,
L_26 ,
( long unsigned int ) F_26 ( V_82 -> V_93 ) ) ;
F_18 ( & V_30 -> V_52 -> V_53 ,
L_27 ,
( long unsigned int ) F_26 ( V_82 -> V_89 ) ,
( long unsigned int ) F_26 ( V_82 -> V_90 ) ) ;
}
}
}
}
return 0 ;
}
T_1 F_28 ( struct V_29 * V_30 ,
T_1 V_7 , T_2 V_78 , T_2 * V_79 , struct V_8 * V_9 )
{
struct V_31 * V_32 = V_30 -> V_33 ;
struct V_6 * V_70 = F_5 ( V_7 , V_9 ) ;
T_9 * V_96 ;
struct V_81 * V_82 ;
T_1 V_21 , V_107 ;
T_8 V_69 = V_32 -> V_74 ;
for ( V_107 = 0 ; V_107 < V_97 ; V_107 ++ ) {
V_96 = & ( V_69 [ V_7 ] . V_96 [ V_107 ] ) ;
if ( V_96 -> V_98 == 0 )
break;
if ( V_78 > V_96 -> V_104 )
continue;
for ( V_21 = 0 ; V_21 < V_70 -> V_84 ; V_21 ++ )
if ( F_17 ( V_9 -> V_10 . V_11 [ V_7 ] . V_14 [ V_21 ] .
V_85 . V_86 ) >= V_107 + 1 ) {
V_82 = & V_9 -> V_10 . V_11 [ V_7 ] .
V_14 [ V_21 ] .
V_85 . V_82 [ V_107 ] ;
if ( F_17 ( V_82 -> V_87 ) == 0 )
return V_88 ;
if ( F_26 ( V_82 -> V_89 ) <= V_78 &&
V_78 <= F_26 ( V_82 -> V_90 ) &&
( F_1 ( V_78 - F_26 ( V_82 -> V_89 ) ,
F_17 ( V_82 -> V_87 ) ) ) == 0 ) {
if ( V_79 != NULL ) {
T_2 V_91 ;
V_91 = F_4
( ( V_78 - F_26 ( V_82 -> V_89 ) ) ,
F_17 ( V_82 -> V_87 ) ) ;
V_91 = ( V_91 + F_26 ( V_82 -> V_93 ) )
<< V_70 -> V_94 ;
* V_79 = V_91 ;
}
return V_21 ;
}
}
}
return V_88 ;
}
static T_2 F_29 ( struct V_29 * V_30 ,
T_1 V_7 , T_2 V_108 , struct V_8 * V_9 )
{
struct V_31 * V_32 = V_30 -> V_33 ;
struct V_6 * V_70 = F_5 ( V_7 , V_9 ) ;
T_9 * V_96 ;
T_8 V_69 = V_32 -> V_74 ;
T_1 V_107 , V_109 , V_21 , V_110 ;
T_2 V_111 , V_112 , V_113 ;
for ( V_107 = 0 ; V_107 < V_97 ; V_107 ++ ) {
V_96 = & ( V_69 [ V_7 ] . V_96 [ V_107 ] ) ;
if ( V_96 -> V_98 == 0 )
break;
if ( V_108 > V_96 -> V_106 )
continue;
V_111 = V_108 - V_96 -> V_105 ;
V_109 = F_1 ( V_111 ,
V_96 -> V_98 ) ;
V_112 = F_4 ( V_111 ,
V_96 -> V_98 ) * V_96 -> V_87 ;
for ( V_21 = 0 , V_110 = 0 ; V_21 < V_70 -> V_84 ; V_21 ++ )
if ( F_17 ( V_9 -> V_10 . V_11 [ V_7 ] . V_14 [ V_21 ] .
V_85 . V_86 ) >= V_107 + 1 ) {
if ( V_109 >=
V_96 -> V_109 [ V_21 ] )
V_110 ++ ;
else
break;
}
#if V_114
F_30 ( & V_30 -> V_52 -> V_53 , L_28
L_29
L_30 , V_108 ,
( unsigned long long ) V_111 ,
( unsigned long long ) V_112 ,
( unsigned long long ) V_96 -> V_98 ,
V_110 ) ;
F_30 ( & V_30 -> V_52 -> V_53 , L_31
L_32 , V_108 ,
( unsigned long long ) V_96 -> V_103 +
( unsigned long long ) V_112 + ( V_110 - 1 ) ) ;
#endif
V_113 = ( V_96 -> V_103 + V_112 +
( V_110 - 1 ) ) ;
return V_113 ;
}
return - 1LLU ;
}
static T_2 F_31 ( struct V_29 * V_30 ,
T_1 V_7 , T_2 V_78 , struct V_8 * V_9 )
{
struct V_31 * V_32 = V_30 -> V_33 ;
struct V_6 * V_70 = F_5 ( V_7 , V_9 ) ;
T_9 * V_96 ;
struct V_81 * V_82 ;
T_8 V_69 = V_32 -> V_74 ;
T_1 V_21 , V_107 ;
T_2 V_108 ;
for ( V_107 = 0 ; V_107 < V_97 ; V_107 ++ ) {
V_96 = & ( V_69 [ V_7 ] . V_96 [ V_107 ] ) ;
if ( V_96 -> V_98 == 0 )
break;
if ( V_78 > V_96 -> V_104 )
continue;
for ( V_21 = 0 ; V_21 < V_70 -> V_84 ; V_21 ++ )
if ( F_17 ( V_9 -> V_10 . V_11 [ V_7 ] . V_14 [ V_21 ] .
V_85 . V_86 ) >= V_107 + 1 ) {
V_82 = & V_9 -> V_10 . V_11 [ V_7 ] .
V_14 [ V_21 ] . V_85 . V_82 [ V_107 ] ;
if ( F_26 ( V_82 -> V_89 ) <= V_78 &&
V_78 <= F_26 ( V_82 -> V_90 ) &&
F_1 ( ( V_78 - F_26 ( V_82 -> V_89 ) ) ,
F_17 ( V_82 -> V_87 ) ) == 0 ) {
V_108 = F_4
( ( ( V_78 - V_96 -> V_103 )
- F_26 ( V_82 -> V_89 ) ) ,
F_17 ( V_82 -> V_87 ) ) ;
V_108 *= V_96 -> V_98 ;
V_108 += V_96 -> V_105 ;
V_108 += V_96 -> V_109 [ V_21 ] ;
return V_108 ;
}
}
}
F_21 ( & V_30 -> V_52 -> V_53 , L_33
L_34 ,
V_7 , ( long unsigned int ) V_78 ) ;
return - 1 ;
}
static T_1 F_32 ( struct V_29 * V_30 ,
T_1 V_7 , T_2 V_108 , struct V_8 * V_9 )
{
struct V_31 * V_32 = V_30 -> V_33 ;
struct V_6 * V_70 = F_5 ( V_7 , V_9 ) ;
T_9 * V_96 ;
T_8 V_69 = V_32 -> V_74 ;
T_1 V_107 , V_109 , V_21 , V_110 , V_113 ;
for ( V_107 = 0 ; V_107 < V_97 ; V_107 ++ ) {
V_96 = & ( V_69 [ V_7 ] . V_96 [ V_107 ] ) ;
if ( V_96 -> V_98 == 0 )
break;
if ( V_108 > V_96 -> V_106 )
continue;
V_109 = ( V_115 ) F_1
( ( V_108 - V_96 -> V_105 ) ,
V_96 -> V_98 ) ;
for ( V_21 = 0 , V_110 = 0 ; V_21 < V_70 -> V_84 ; V_21 ++ )
if ( F_17 ( V_9 -> V_10 . V_11 [ V_7 ] . V_14 [ V_21 ] .
V_85 . V_86 ) >= V_107 + 1 ) {
if ( V_109 >=
V_96 -> V_109 [ V_21 ] )
V_110 =
V_96 -> V_109 [ V_21 ] ;
else
break;
}
#if V_114
F_30 ( & V_30 -> V_52 -> V_53 , L_35
L_36 , V_7 ,
( long unsigned int ) V_108 , ( V_109 - V_110 ) ) ;
#endif
V_113 = ( V_109 - V_110 ) ;
return V_113 ;
}
F_21 ( & V_30 -> V_52 -> V_53 , L_37
L_38 ,
V_7 , ( long unsigned int ) V_108 ) ;
return - 1 ;
}
T_5 F_33 ( struct V_29 * V_30 , T_1 V_7 , T_5 V_21 , T_2 V_116 ,
struct V_8 * V_9 )
{
struct V_6 * V_70 = F_5 ( V_7 , V_9 ) ;
T_1 V_18 = 0 ;
switch ( V_70 -> V_117 ) {
case 0 :
case 5 :
case 6 :
V_18 = F_1 ( V_116 , F_34 ( V_9 , V_7 , V_21 ) ) ;
break;
case 1 :
V_18 = F_32 ( V_30 , V_7 , V_116 , V_9 ) ;
if ( V_18 != - 1U )
V_18 *= 2 ;
break;
}
return V_18 ;
}
static T_5 F_35 ( struct V_29 * V_30 , T_1 V_7 ,
T_2 V_118 , T_6 V_119 , struct V_120 * V_121 ,
struct V_122 * V_123 ,
struct V_8 * V_9 )
{
struct V_6 * V_70 = F_5 ( V_7 , V_9 ) ;
T_1 V_20 , V_124 ;
T_5 V_125 , V_21 ;
T_2 V_78 ;
T_5 V_113 = TRUE ;
T_2 * V_126 = & V_121 -> V_126 ;
T_7 * V_127 = & V_121 -> V_128 ;
T_1 V_129 , V_130 , V_131 , V_18 ;
struct V_31 * V_32 ;
V_32 = V_30 -> V_33 ;
V_78 = V_121 -> V_132 ;
V_21 = V_121 -> V_133 ;
if ( V_70 -> V_117 == 6 ) {
V_129 = F_32 ( V_30 , V_7 , V_118 , V_9 ) ;
if ( V_129 == - 1U )
return FALSE ;
V_130 = F_1 ( V_78 , F_34 ( V_9 , V_7 , V_21 ) ) ;
V_131 = F_34 ( V_9 , V_7 , V_21 ) - 1 - V_130 ;
V_18 = V_131 + 1 + V_129 ;
if ( V_18 >= F_34 ( V_9 , V_7 , V_21 ) )
V_18 -= F_34 ( V_9 , V_7 , V_21 ) ;
V_125 = ( T_5 ) V_18 ;
} else
V_125 = F_33 ( V_30 , V_7 , V_21 , V_118 , V_9 ) ;
if ( V_125 == 0xFF )
return FALSE ;
V_124 = F_10 ( V_7 , V_21 , V_9 ) ;
V_20 = F_8 ( V_124 , V_125 , V_9 ) ;
if ( V_20 != V_134 )
* V_127 = F_11 ( V_20 , V_9 ) ;
else {
* V_127 = F_19 ( V_134 ) ;
if ( ( V_70 -> V_117 >= 5 ) &&
( ( V_32 -> V_135 == V_136 ) ||
( ( V_32 -> V_135 == V_137 ) &&
( V_70 -> V_138 != V_139 ) ) ) )
V_123 -> V_140 = V_141 ;
else if ( V_70 -> V_117 == 1 ) {
V_20 = F_8 ( V_124 , V_125 + 1 , V_9 ) ;
if ( V_20 != V_134 )
* V_127 = F_11 ( V_20 , V_9 ) ;
}
}
* V_126 += V_119 + F_26 ( F_14 ( V_7 , V_21 , V_9 ) -> V_142 ) ;
V_123 -> V_143 = ( V_21 << V_144 ) |
V_125 ;
V_121 -> V_145 = V_123 -> V_143 ;
return V_113 ;
}
T_5 F_36 ( struct V_29 * V_30 , T_1 V_7 , T_2 V_118 ,
T_6 V_119 , struct V_120 * V_121 ,
struct V_122 * V_123 ,
struct V_8 * V_9 )
{
struct V_6 * V_70 = F_5 ( V_7 , V_9 ) ;
T_1 V_20 , V_124 ;
T_5 V_125 , V_21 ;
T_2 V_78 ;
T_5 V_113 = TRUE ;
T_2 * V_126 = & V_121 -> V_126 ;
T_7 * V_127 = & V_121 -> V_128 ;
struct V_31 * V_32 ;
V_32 = V_30 -> V_33 ;
V_78 = F_4 ( V_118 , V_70 -> V_146 ) ;
if ( V_70 -> V_117 == 6 ) {
T_1 V_129 = F_1 ( V_118 , V_70 -> V_146 ) ;
T_1 V_130 , V_131 , V_18 ;
if ( V_70 -> V_62 == 0 )
return FALSE ;
V_130 = F_1 ( V_78 , V_70 -> V_62 ) ;
V_131 = V_70 -> V_62 - 1 - V_130 ;
V_18 = V_131 + 1 + V_129 ;
if ( V_18 >= V_70 -> V_62 )
V_18 -= V_70 -> V_62 ;
V_125 = ( T_5 ) V_18 ;
} else {
if ( V_70 -> V_147 == 0 )
return FALSE ;
V_125 = F_7 ( V_7 , F_1 ( V_118 ,
V_70 -> V_147 ) ,
V_9 ) ;
}
if ( V_70 -> V_84 == 1 ) {
V_21 = 0 ;
* V_126 = V_78 << V_70 -> V_94 ;
} else {
V_21 = ( T_5 ) F_25 ( V_7 , V_78 , V_126 , V_9 ) ;
if ( V_21 == V_88 )
return FALSE ;
}
V_124 = F_10 ( V_7 , V_21 , V_9 ) ;
V_20 = F_8 ( V_124 , V_125 , V_9 ) ;
if ( V_20 != V_134 )
* V_127 = F_11 ( V_20 , V_9 ) ;
else {
* V_127 = F_19 ( V_134 ) ;
if ( ( V_70 -> V_117 >= 5 ) &&
( ( V_32 -> V_135 == V_136 ) ||
( ( V_32 -> V_135 == V_137 ) &&
( V_70 -> V_138 != V_139 ) ) ) )
V_123 -> V_140 = V_141 ;
else if ( V_70 -> V_117 == 1 ) {
V_20 = F_8 ( V_124 , V_125 + 1 , V_9 ) ;
if ( V_20 != V_134 )
* V_127 = F_11 ( V_20 , V_9 ) ;
}
}
* V_126 += V_119 + F_26 ( F_14 ( V_7 , V_21 , V_9 ) -> V_142 ) ;
V_123 -> V_143 = ( V_21 << V_144 ) |
V_125 ;
V_121 -> V_145 = V_123 -> V_143 ;
return V_113 ;
}
T_5
F_37 ( struct V_29 * V_30 ,
struct V_120 * V_121 ,
struct V_122 * V_123 ,
struct V_8 * V_9 , T_5 * * V_148 )
{
struct V_31 * V_32 ;
struct V_6 * V_70 ;
T_1 V_7 , V_149 , V_150 ;
T_2 V_151 , V_152 , V_153 , V_132 , V_154 ;
T_2 V_155 ;
T_1 V_156 ;
T_5 V_157 , V_158 ;
T_6 V_159 , V_160 ;
T_2 V_161 ;
T_1 V_162 , V_26 ;
T_5 V_163 ;
T_5 V_113 = 0 ;
T_5 V_164 = V_88 ;
T_2 * V_126 = & V_121 -> V_126 ;
V_161 = V_121 -> V_161 ;
V_162 = V_121 -> V_162 ;
V_26 = V_121 -> V_26 ;
V_163 = V_121 -> V_163 ;
V_121 -> V_165 = 0 ;
V_121 -> V_133 = V_88 ;
V_32 = V_30 -> V_33 ;
V_7 = F_13 ( V_26 , V_9 ) ;
V_70 = F_5 ( V_7 , V_9 ) ;
if ( V_70 -> V_146 == 0 ) {
if ( F_14 ( V_7 , 0 , V_9 ) -> V_166 == 0 )
return FALSE ;
else if ( V_30 -> V_76 ) {
V_121 -> V_165 = 1 ;
} else {
F_30 ( & V_30 -> V_52 -> V_53 ,
L_39
L_40
L_41 ,
F_14 ( V_7 , 0 , V_9 ) -> V_166 ) ;
return FALSE ;
}
}
V_149 = 1 << V_70 -> V_94 ;
V_150 = V_149 - 1 ;
V_154 = V_161 >> V_70 -> V_94 ;
V_159 = ( T_6 ) ( V_161 & V_150 ) ;
V_151 = V_161 + V_162 - 1 ;
V_160 = ( T_6 ) ( V_151 & V_150 ) ;
V_152 = V_151 >> V_70 -> V_94 ;
V_157 = ( T_5 ) ( V_152 - V_154 + 1 ) ;
if ( V_121 -> V_165 ) {
V_132 = F_29 ( V_30 , V_7 , V_154 , V_9 ) ;
V_153 = F_29 ( V_30 , V_7 , V_152 , V_9 ) ;
if ( V_132 == - 1ULL || V_153 == - 1ULL ) {
F_30 ( & V_30 -> V_52 -> V_53 , L_42
L_43 ,
V_167 , __LINE__ ) ;
return FALSE ;
}
if ( V_70 -> V_84 == 1 ) {
V_164 = 0 ;
* V_126 = V_132 << V_70 -> V_94 ;
} else
V_164 = ( T_5 ) F_28 ( V_30 ,
V_7 , V_132 , V_126 , V_9 ) ;
if ( V_164 == V_88 ) {
F_30 ( & V_30 -> V_52 -> V_53 , L_44
L_45
L_46 , V_167 , __LINE__ ,
( unsigned long long ) V_132 ,
( unsigned long long ) V_154 ,
( unsigned long long ) V_152 ) ;
return FALSE ;
}
V_121 -> V_133 = V_164 ;
V_121 -> V_132 = V_132 ;
#if V_114
F_18 ( & V_30 -> V_52 -> V_53 , L_47
L_48
L_49 , V_167 , __LINE__ ,
( unsigned long long ) V_132 ,
( unsigned long long ) V_154 ,
( unsigned long long ) V_152 , V_164 ) ;
F_18 ( & V_30 -> V_52 -> V_53 , L_50
L_51 , ( unsigned long long ) V_132 ,
( unsigned long long ) V_153 , V_164 ) ;
#endif
} else {
V_132 = F_4 ( V_154 , V_70 -> V_146 ) ;
V_153 = F_4 ( V_152 , V_70 -> V_146 ) ;
}
V_158 = ( T_5 ) ( V_153 - V_132 + 1 ) ;
V_155 = V_132 << V_70 -> V_94 ;
V_156 = V_149 ;
V_121 -> V_168 = V_70 -> V_77 . V_169 ;
if ( V_70 -> V_77 . V_170 ) {
if ( V_163 )
V_121 -> V_171 = ( V_70 -> V_77 . V_172 &&
( ( V_157 == 1 ) ||
V_70 -> V_77 .
V_173 ) ) ;
else
V_121 -> V_171 = ( V_70 -> V_77 . V_174 &&
( ( V_157 == 1 ) ||
V_70 -> V_77 .
V_175 ) ) ;
} else
V_121 -> V_171 = FALSE ;
if ( V_158 == 1 ) {
if ( V_157 == 1 ) {
V_155 += V_159 ;
V_156 = V_162 ;
}
} else if ( V_121 -> V_165 == 0 ) {
if ( V_154 == ( V_132 + 1 ) * V_70 -> V_146 - 1 ) {
V_155 += V_159 ;
V_156 = V_149 - V_159 ;
}
if ( V_158 > 2 )
V_156 += ( V_158 - 2 ) << V_70 -> V_94 ;
if ( V_152 == V_153 * V_70 -> V_146 )
V_156 += V_160 + 1 ;
else
V_156 += V_149 ;
} else {
if ( V_154 == ( F_31 ( V_30 , V_7 , V_132 , V_9 ) +
F_38 ( V_9 , V_7 , V_164 ) - 1 ) ) {
V_155 += V_159 ;
V_156 = V_149 - V_159 ;
}
if ( V_158 > 2 )
V_156 += ( V_158 - 2 ) << V_70 -> V_94 ;
if ( V_152 == F_31 ( V_30 , V_7 , V_153 , V_9 ) )
V_156 += V_160 + 1 ;
else
V_156 += V_149 ;
}
V_123 -> V_176 =
F_19 ( V_70 -> V_177 ?
V_70 -> V_177 :
V_9 -> V_10 . V_58 ) ;
if ( V_32 -> V_135 == V_137 )
V_123 -> V_140 = ( V_163 ) ?
V_70 -> V_138 : V_70 -> V_178 ;
else
V_123 -> V_140 = ( V_163 ) ?
V_179 : V_70 -> V_178 ;
V_123 -> V_180 = V_70 -> V_25 ;
V_123 -> V_181 = F_39 ( V_155 ) ;
V_123 -> V_182 = F_16 ( V_156 ) ;
V_123 -> V_183 = V_70 -> V_55 ;
* V_148 = V_70 -> V_184 ;
if ( V_121 -> V_171 ) {
V_113 = V_121 -> V_165 ?
F_35 ( V_30 , V_7 ,
V_154 , V_159 ,
V_121 , V_123 , V_9 ) :
F_36 ( V_30 , V_7 , V_154 ,
V_159 , V_121 ,
V_123 , V_9 ) ;
if ( V_121 -> V_128 == F_19 ( V_134 ) )
V_121 -> V_171 = FALSE ;
return V_113 ;
} else if ( V_163 ) {
V_115 V_185 ;
for ( V_185 = 0 ; V_185 < V_157 ; V_185 ++ ) {
V_113 = V_121 -> V_165 ?
F_35 ( V_30 , V_7 ,
V_154 + V_185 ,
V_159 , V_121 ,
V_123 , V_9 ) :
F_36 ( V_30 , V_7 ,
V_154 + V_185 , V_159 ,
V_121 , V_123 , V_9 ) ;
if ( ! V_113 )
return TRUE ;
}
}
#if V_114
if ( V_121 -> V_165 )
F_32 ( V_30 , V_7 , V_154 , V_9 ) ;
#endif
return TRUE ;
}
void F_22 ( struct V_8 * V_9 ,
T_8 V_69 )
{
T_5 V_21 , V_186 ;
T_1 V_95 , V_187 ;
T_2 V_188 ;
struct V_6 * V_70 ;
T_9 * V_96 , * V_189 ;
struct V_81 * V_82 ;
int V_50 ;
T_6 V_7 ;
for ( V_50 = 0 ; V_50 < V_61 ; V_50 ++ ) {
V_7 = F_13 ( V_50 , V_9 ) ;
if ( V_7 >= ( V_61 - 1 ) )
continue;
V_70 = F_5 ( V_7 , V_9 ) ;
for ( V_95 = 0 ; V_95 < V_97 ; V_95 ++ ) {
for ( V_21 = 0 ; V_21 < V_70 -> V_84 ; V_21 ++ ) {
if ( F_17 ( V_9 -> V_10 . V_11 [ V_7 ] . V_14 [ V_21 ] .
V_85 . V_86 ) <
V_95 + 1 )
continue;
V_96 = & ( V_69 [ V_7 ] . V_96 [ V_95 ] ) ;
V_82 = & V_9 -> V_10 . V_11 [ V_7 ] .
V_14 [ V_21 ] . V_85 .
V_82 [ V_95 ] ;
V_96 -> V_87 = F_17 ( V_82 -> V_87 ) ;
for ( V_186 = 0 , V_187 = 0 ;
V_186 < V_70 -> V_84 ; V_186 ++ ) {
if ( F_17 ( V_9 -> V_10 . V_11 [ V_7 ] .
V_14 [ V_186 ] .
V_85 .
V_86 ) >= V_95 + 1 ) {
V_96 -> V_109 [ V_186 ] =
V_187 ;
V_187 +=
F_14
( V_7 , V_186 , V_9 ) -> V_166 ;
}
}
V_96 -> V_98 = V_187 ;
V_188 = F_4 ( ( ( F_26 ( V_82 -> V_90 ) -
F_26 ( V_82 -> V_89 ) ) + F_17 ( V_82 -> V_87 ) ) ,
F_17 ( V_82 -> V_87 ) ) ;
if ( V_95 == 0 ) {
V_96 -> V_99 = 0 ;
V_96 -> V_100 =
( ( V_188 << V_70 -> V_94 )
* V_187 ) - 1 ;
V_96 -> V_101 = 0 ;
V_96 -> V_102 = V_188 - 1 ;
V_96 -> V_105 = 0 ;
V_96 -> V_106 =
( V_188 * V_187 ) - 1 ;
V_96 -> V_103 = 0 ;
V_96 -> V_104 =
( V_188 * F_17 ( V_82 -> V_87 ) ) - 1 ;
} else {
V_189 = & ( V_69 [ V_7 ] .
V_96 [ V_95 - 1 ] ) ;
V_96 -> V_99 =
V_189 -> V_100 + 1 ;
V_96 -> V_100 =
V_96 -> V_99 +
( ( V_188 << V_70 -> V_94 )
* V_187 ) - 1 ;
V_96 -> V_101 =
V_189 -> V_102 + 1 ;
V_96 -> V_102 =
V_96 -> V_101 + V_188 - 1 ;
V_96 -> V_105 =
V_189 -> V_106 + 1 ;
V_96 -> V_106 =
V_96 -> V_105 +
( V_188 * V_187 ) - 1 ;
V_96 -> V_103 =
V_189 -> V_104 + 1 ;
V_96 -> V_104 =
V_96 -> V_103 +
( V_188 * F_17 ( V_82 -> V_87 ) ) - 1 ;
}
break;
}
if ( V_21 == V_70 -> V_84 )
break;
}
}
#if V_114
F_27 ( V_9 , V_69 ) ;
#endif
}
void F_23 ( struct V_8 * V_40 ,
struct V_67 * V_68 )
{
int V_50 ;
T_6 V_7 ;
struct V_6 * V_70 ;
if ( V_190 > 128 || V_190 < 1 )
V_190 = V_191 ;
for ( V_50 = 0 ; V_50 < V_61 ; V_50 ++ ) {
V_7 = F_13 ( V_50 , V_40 ) ;
if ( V_7 >= V_61 ) {
V_68 [ V_50 ] . V_192 = 0 ;
continue;
}
V_70 = F_5 ( V_7 , V_40 ) ;
if ( ( V_70 -> V_117 != 1 ) ||
( V_70 -> V_193 != V_194 ) ) {
V_68 [ V_50 ] . V_192 = 0 ;
continue;
}
V_68 [ V_50 ] . V_192 = 1 ;
}
}
T_5 F_40 ( struct V_29 * V_30 ,
struct V_67 * V_68 , struct V_120 * V_121 )
{
struct V_31 * V_32 ;
struct V_6 * V_70 ;
struct V_8 * V_40 ;
T_6 V_195 , V_196 , V_7 ;
T_2 V_197 , V_198 ;
T_5 V_199 , V_200 , V_201 , V_21 , V_18 ;
T_1 V_124 , V_202 ;
T_2 V_203 = V_121 -> V_161 ;
T_1 V_186 = V_121 -> V_162 ;
V_21 = ( ( V_121 -> V_145 & V_204 )
>> V_144 ) ;
V_18 = ( V_121 -> V_145 & V_205 ) ;
V_32 = V_30 -> V_33 ;
V_40 = V_32 -> V_41 [ ( V_30 -> V_42 & 1 ) ] ;
V_7 = F_13 ( V_121 -> V_26 , V_40 ) ;
V_70 = F_5 ( V_7 , V_40 ) ;
V_202 = V_30 -> V_76 ?
F_34 ( V_40 , V_7 , V_21 ) : V_70 -> V_62 ;
V_124 = F_10 ( V_7 , V_21 , V_40 ) ;
V_200 = F_8 ( V_124 , V_18 , V_40 ) ;
V_201 = F_8 ( V_124 , ( V_18 + 1 ) >= V_202 ?
( V_18 + 1 - V_202 ) : V_18 + 1 , V_40 ) ;
V_195 = F_41 ( & V_68 -> V_206 [ V_200 ] ) ;
V_196 = F_41 ( & V_68 -> V_206 [ V_201 ] ) ;
V_197 = F_42 ( V_203 , V_68 -> V_207 [ V_200 ] ) ;
V_198 = F_42 ( V_203 , V_68 -> V_207 [ V_201 ] ) ;
V_199 = ( V_197 <= V_198 ? V_18 : V_18 ^ 1 ) ;
if ( ( V_199 == V_18 && V_195 > V_196 + V_190 ) ||
( V_199 != V_18 && V_196 > V_195 + V_190 ) )
V_199 ^= 1 ;
V_121 -> V_208 = ( V_199 == V_18 ) ? V_200 : V_201 ;
V_68 -> V_207 [ V_121 -> V_208 ] = V_203 + V_186 - 1 ;
V_121 -> V_145 = ( V_21 << V_144 ) | V_199 ;
#if V_114
if ( V_18 != V_199 )
F_18 ( & V_30 -> V_52 -> V_53 , L_52
L_53
L_54 ,
V_21 , V_18 , V_199 , V_121 -> V_145 ) ;
#endif
return V_121 -> V_208 ;
}
T_7 F_43 ( struct V_29 * V_30 ,
struct V_67 * V_68 , struct V_120 * V_121 )
{
T_5 V_209 ;
T_7 V_128 ;
struct V_31 * V_32 ;
struct V_8 * V_40 ;
V_32 = V_30 -> V_33 ;
V_40 = V_32 -> V_41 [ ( V_30 -> V_42 & 1 ) ] ;
V_209 = F_40 ( V_30 , V_68 , V_121 ) ;
V_128 = F_11 ( V_209 , V_40 ) ;
F_44 ( & V_68 -> V_206 [ V_209 ] ) ;
return V_128 ;
}
