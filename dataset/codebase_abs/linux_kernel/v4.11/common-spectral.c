static T_1 F_1 ( T_2 V_1 )
{
if ( V_1 == 128 )
V_1 = 0 ;
return ( T_1 ) V_1 ;
}
static void F_2 ( struct V_2 * V_3 ,
struct V_4 * V_4 )
{
int V_5 ;
if ( ! V_3 -> V_6 )
return;
V_5 = F_3 ( V_4 -> V_5 ) +
sizeof( * V_4 ) ;
F_4 ( V_3 -> V_6 , V_4 , V_5 ) ;
}
static int
F_5 ( T_2 * V_7 , int V_8 )
{
struct V_9 * V_10 ;
T_2 * V_11 ;
T_3 V_12 ;
T_2 V_13 ;
T_2 V_14 ;
if ( V_8 < V_15 - 1 )
return - 1 ;
V_10 = (struct V_9 * ) ( V_7 -
sizeof( struct V_9 ) + 1 ) ;
V_11 = V_7 - V_15 + 1 ;
V_13 = F_6 ( V_10 -> V_16 ,
V_17 ) ;
V_12 = F_7 ( V_10 -> V_16 ) ;
V_14 = V_10 -> V_14 & 0xf ;
if ( V_8 < V_15 && V_13 < 1 )
return - 1 ;
if ( V_11 [ V_13 ] != ( V_12 >> V_14 ) )
return - 1 ;
else
return 0 ;
}
static int
F_8 ( T_2 * V_7 , int V_8 )
{
struct V_18 * V_10 ;
T_2 * V_11 ;
T_3 V_19 , V_20 ;
T_2 V_21 , V_22 ;
T_2 V_14 ;
int V_23 = V_24 / 2 ;
if ( V_8 < V_25 - 1 )
return - 1 ;
V_10 = (struct V_18 * ) ( V_7 -
sizeof( struct V_18 ) + 1 ) ;
V_11 = V_7 - V_25 + 1 ;
V_19 = F_7 ( V_10 -> V_26 ) ;
V_21 = F_6 ( V_10 -> V_26 ,
V_24 ) ;
V_20 = F_7 ( V_10 -> V_27 ) ;
V_22 = F_6 ( V_10 -> V_27 ,
V_24 ) ;
V_14 = V_10 -> V_14 & 0xf ;
if ( V_8 < V_25 &&
( ( V_22 < 1 ) || ( V_21 < 1 ) ) )
return - 1 ;
if ( ( V_22 - V_23 > 0 ) &&
( V_11 [ V_22 ] == ( V_20 >> V_14 ) ) )
V_22 -= V_23 ;
if ( ( V_21 - V_23 > 0 ) &&
( V_11 [ V_21 - V_23 ] == ( V_19 >> V_14 ) ) )
V_21 -= V_23 ;
if ( ( V_11 [ V_22 + V_23 ] != ( V_20 >> V_14 ) ) ||
( V_11 [ V_21 ] != ( V_19 >> V_14 ) ) )
return - 1 ;
else
return 0 ;
}
static int
F_9 ( struct V_28 * V_29 ,
struct V_2 * V_3 ,
T_2 * V_30 ,
T_4 V_31 , T_3 V_32 , int V_33 )
{
struct V_34 V_35 ;
struct V_36 * V_37 = F_10 ( V_3 -> V_38 ) ;
struct V_39 * V_38 = V_3 -> V_38 ;
struct V_9 * V_10 ;
struct V_4 * V_40 ;
int V_41 = 0 ;
int V_42 = 0 ;
int V_23 = V_17 / 2 ;
T_3 V_43 , V_44 , V_5 ;
T_2 V_13 , V_45 , V_14 ;
V_5 = sizeof( V_35 ) - sizeof( struct V_4 ) ;
V_35 . V_40 . type = V_46 ;
V_35 . V_40 . V_5 = F_11 ( V_5 ) ;
V_35 . V_32 = F_11 ( V_32 ) ;
V_35 . V_47 = F_1 ( V_29 -> V_48 [ 0 ] ) ;
V_35 . V_49 = V_38 -> V_49 ;
V_10 = (struct V_9 * ) ( V_30 +
V_17 ) ;
V_43 = F_7 ( V_10 -> V_16 ) ;
V_35 . V_12 = F_11 ( V_43 ) ;
V_13 = F_6 ( V_10 -> V_16 ,
V_17 ) ;
V_35 . V_13 = V_13 ;
V_45 = F_12 ( V_10 -> V_16 ) ;
V_35 . V_50 = V_45 ;
V_14 = V_10 -> V_14 & 0xf ;
V_35 . V_14 = V_14 ;
V_35 . V_31 = F_13 ( V_31 ) ;
memcpy ( V_35 . V_51 , V_30 , V_17 ) ;
F_14 ( V_37 , V_52 , L_1
L_2 ,
V_43 >> V_14 ,
V_13 ) ;
if ( V_35 . V_51 [ V_13 ] != ( V_43 >> V_14 ) ) {
F_14 ( V_37 , V_52 , L_3 ) ;
V_42 = - 1 ;
}
V_35 . V_51 [ V_23 ] = ( V_35 . V_51 [ V_23 + 1 ] +
V_35 . V_51 [ V_23 - 1 ] ) / 2 ;
if ( V_13 == V_23 ) {
V_44 = 0 ;
for ( V_41 = 0 ; V_41 < V_23 ; V_41 ++ ) {
if ( V_35 . V_51 [ V_41 ] > V_44 ) {
V_44 = V_35 . V_51 [ V_41 ] ;
V_35 . V_13 = V_41 ;
}
}
V_43 = V_44 << V_14 ;
V_35 . V_12 = F_11 ( V_43 ) ;
F_14 ( V_37 , V_52 ,
L_4 ,
V_44 , V_35 . V_13 ) ;
} else
for ( V_41 = 0 ; V_41 < V_17 ; V_41 ++ ) {
if ( V_35 . V_51 [ V_41 ] == ( V_43 >> V_14 ) )
F_14 ( V_37 , V_52 ,
L_5 ,
V_35 . V_51 [ V_41 ] , V_41 ) ;
if ( V_35 . V_51 [ V_41 ] > ( V_43 >> V_14 ) ) {
F_14 ( V_37 , V_52 ,
L_6 ,
V_41 , V_35 . V_51 [ V_41 ] ) ;
V_42 = - 1 ;
}
}
if ( V_42 < 0 )
return V_42 ;
V_40 = (struct V_4 * ) & V_35 ;
F_2 ( V_3 , V_40 ) ;
return 0 ;
}
static int
F_15 ( struct V_28 * V_29 ,
struct V_2 * V_3 ,
T_2 * V_30 ,
T_4 V_31 , T_3 V_32 , int V_33 )
{
struct V_53 V_54 ;
struct V_36 * V_37 = F_10 ( V_3 -> V_38 ) ;
struct V_39 * V_38 = V_3 -> V_38 ;
struct V_55 * V_56 = V_38 -> V_56 ;
struct V_18 * V_10 ;
struct V_4 * V_40 ;
int V_23 = V_24 / 2 ;
int V_41 = 0 ;
int V_42 = 0 ;
T_5 V_57 ;
T_3 V_19 , V_20 , V_44 , V_5 ;
T_1 V_58 , V_59 ;
T_2 V_21 , V_22 ;
T_2 V_60 , V_61 , V_14 ;
if ( V_56 )
V_57 = F_16 ( V_38 , V_38 -> V_62 ,
V_56 -> V_63 [ 3 ] . V_64 ) ;
else
V_57 = V_65 ;
V_5 = sizeof( V_54 ) - sizeof( struct V_4 ) ;
V_54 . V_40 . type = V_66 ;
V_54 . V_40 . V_5 = F_11 ( V_5 ) ;
V_54 . V_32 = F_11 ( V_32 ) ;
V_54 . V_67 = V_33 ;
if ( V_33 == V_68 ) {
V_58 = F_1 ( V_29 -> V_48 [ 0 ] ) ;
V_59 = F_1 ( V_29 -> V_69 [ 0 ] ) ;
V_54 . V_70 = V_38 -> V_49 ;
V_54 . V_71 = V_57 ;
} else {
V_58 = F_1 ( V_29 -> V_69 [ 0 ] ) ;
V_59 = F_1 ( V_29 -> V_48 [ 0 ] ) ;
V_54 . V_70 = V_57 ;
V_54 . V_71 = V_38 -> V_49 ;
}
V_54 . V_58 = V_58 ;
V_54 . V_59 = V_59 ;
V_10 = (struct V_18 * ) ( V_30 +
V_24 ) ;
V_19 = F_7 ( V_10 -> V_26 ) ;
V_54 . V_72 = F_11 ( V_19 ) ;
V_20 = F_7 ( V_10 -> V_27 ) ;
V_54 . V_73 = F_11 ( V_20 ) ;
V_21 = F_6 ( V_10 -> V_26 ,
V_24 ) ;
V_54 . V_21 = V_21 ;
V_22 = F_6 ( V_10 -> V_27 ,
V_24 ) ;
V_54 . V_22 = V_22 ;
V_60 = F_12 ( V_10 -> V_26 ) ;
V_54 . V_74 = V_60 ;
V_61 = F_12 ( V_10 -> V_27 ) ;
V_54 . V_75 = V_61 ;
V_14 = V_10 -> V_14 & 0xf ;
V_54 . V_14 = V_14 ;
V_54 . V_31 = F_13 ( V_31 ) ;
memcpy ( V_54 . V_51 , V_30 , V_24 ) ;
F_14 ( V_37 , V_52 , L_7
L_8
L_9 ,
V_19 >> V_14 ,
V_21 ,
V_20 >> V_14 ,
V_22 ) ;
if ( ( V_22 - V_23 > 0 ) &&
( V_54 . V_51 [ V_22 ] == ( V_20 >> V_14 ) ) ) {
V_22 -= V_23 ;
V_54 . V_22 = V_22 ;
}
if ( ( V_21 - V_23 > 0 ) &&
( V_54 . V_51 [ V_21 - V_23 ] ==
( V_19 >> V_14 ) ) ) {
V_21 -= V_23 ;
V_54 . V_21 = V_21 ;
}
if ( ( V_54 . V_51 [ V_22 + V_23 ]
!= ( V_20 >> V_14 ) ) ||
( V_54 . V_51 [ V_21 ]
!= ( V_19 >> V_14 ) ) ) {
F_14 ( V_37 , V_52 , L_3 ) ;
V_42 = - 1 ;
}
V_54 . V_51 [ V_23 ] = ( V_54 . V_51 [ V_23 + 1 ] +
V_54 . V_51 [ V_23 - 1 ] ) / 2 ;
if ( V_21 == V_23 ) {
V_44 = 0 ;
for ( V_41 = 0 ; V_41 < V_23 ; V_41 ++ ) {
if ( V_54 . V_51 [ V_41 ] > V_44 ) {
V_44 = V_54 . V_51 [ V_41 ] ;
V_54 . V_21 = V_41 ;
}
}
V_19 = V_44 << V_14 ;
V_54 . V_72 = F_11 ( V_19 ) ;
F_14 ( V_37 , V_52 ,
L_4 ,
V_44 , V_54 . V_21 ) ;
} else
for ( V_41 = 0 ; V_41 < V_23 ; V_41 ++ ) {
if ( V_54 . V_51 [ V_41 ] == ( V_19 >> V_14 ) )
F_14 ( V_37 , V_52 ,
L_10 ,
V_54 . V_51 [ V_41 ] , V_41 ) ;
if ( V_54 . V_51 [ V_41 ] > ( V_19 >> V_14 ) ) {
F_14 ( V_37 , V_52 ,
L_11 ,
V_41 , V_54 . V_51 [ V_41 ] ) ;
V_42 = - 1 ;
}
}
if ( V_22 == V_23 ) {
V_44 = 0 ;
for ( V_41 = V_23 ; V_41 < V_24 ; V_41 ++ ) {
if ( V_54 . V_51 [ V_41 ] > V_44 ) {
V_44 = V_54 . V_51 [ V_41 ] ;
V_54 . V_22 = V_41 ;
}
}
V_20 = V_44 << V_14 ;
V_54 . V_73 = F_11 ( V_20 ) ;
F_14 ( V_37 , V_52 ,
L_12 ,
V_44 , V_41 ) ;
} else
for ( V_41 = V_23 ; V_41 < V_24 ; V_41 ++ ) {
if ( V_54 . V_51 [ V_41 ] == ( V_20 >> V_14 ) )
F_14 ( V_37 , V_52 ,
L_13 ,
V_54 . V_51 [ V_41 ] , V_41 ) ;
if ( V_54 . V_51 [ V_41 ] > ( V_20 >> V_14 ) ) {
F_14 ( V_37 , V_52 ,
L_14 ,
V_41 , V_54 . V_51 [ V_41 ] ) ;
V_42 = - 1 ;
}
}
if ( V_42 < 0 )
return V_42 ;
V_40 = (struct V_4 * ) & V_54 ;
F_2 ( V_3 , V_40 ) ;
return 0 ;
}
static inline void
F_17 ( T_2 * V_76 , T_2 * V_77 , int V_78 , int V_79 )
{
switch ( V_79 - V_78 ) {
case - 1 :
memcpy ( & V_77 [ 1 ] , V_76 ,
V_78 - 1 ) ;
break;
case 0 :
memcpy ( V_77 , V_76 , V_78 ) ;
break;
case 1 :
memcpy ( & V_77 [ 1 ] , V_76 , 30 ) ;
V_77 [ 31 ] = V_76 [ 31 ] ;
memcpy ( & V_77 [ 32 ] , & V_76 [ 33 ] ,
V_78 - 32 ) ;
break;
case 2 :
memcpy ( V_77 , V_76 , 30 ) ;
V_77 [ 30 ] = V_76 [ 31 ] ;
memcpy ( & V_77 [ 31 ] , & V_76 [ 33 ] ,
V_78 - 31 ) ;
break;
default:
break;
}
}
static int
F_18 ( struct V_2 * V_3 )
{
int V_41 = 0 ;
int V_42 = 0 ;
struct V_80 * V_81 = V_3 -> V_6 ;
F_19 (i)
V_42 += F_20 ( * F_21 ( V_81 -> V_82 , V_41 ) ) ;
V_41 = F_22 () ;
if ( V_42 == V_41 )
return 1 ;
else
return 0 ;
}
int F_23 ( struct V_2 * V_3 , struct V_83 * V_84 ,
struct V_28 * V_29 , T_4 V_31 )
{
T_2 V_30 [ V_85 ] = { 0 } ;
struct V_39 * V_38 = V_3 -> V_38 ;
struct V_36 * V_37 = F_10 ( V_3 -> V_38 ) ;
T_2 V_86 , * V_87 = ( T_2 * ) V_84 ;
struct V_88 * V_89 ;
int V_90 = V_29 -> V_91 ;
int V_41 ;
int V_92 = 0 ;
T_2 * V_93 ;
int V_79 = 0 ;
int V_42 = 0 ;
T_3 V_94 , V_78 , V_32 = V_38 -> V_62 -> V_95 -> V_96 ;
enum V_97 V_33 ;
T_6 * V_98 ;
T_7 * V_99 ;
if ( V_29 -> V_100 != V_101 &&
V_29 -> V_100 != V_102 &&
V_29 -> V_100 != V_103 )
return 0 ;
V_89 = ( (struct V_88 * ) & V_87 [ V_90 ] ) - 1 ;
if ( ! ( V_89 -> V_104 & V_105 ) )
return 0 ;
if ( ! V_3 -> V_6 )
return 1 ;
V_42 = F_18 ( V_3 ) ;
if ( V_42 == 1 ) {
F_14 ( V_37 , V_52 , L_15
L_16 ) ;
return 1 ;
}
V_33 = F_24 ( & V_37 -> V_106 -> V_107 . V_108 ) ;
if ( ( V_33 == V_109 ) ||
( V_33 == V_68 ) ) {
V_94 = V_110 ;
V_78 = V_25 ;
V_86 = V_24 ;
V_98 = & F_8 ;
V_99 = & F_15 ;
} else {
V_94 = V_111 ;
V_78 = V_15 ;
V_86 = V_17 ;
V_98 = F_5 ;
V_99 = & F_9 ;
}
F_14 ( V_37 , V_52 , L_17
L_18 ,
V_89 -> V_104 ,
V_90 ,
V_94 ) ;
V_93 = V_87 ;
for ( V_41 = 0 ; V_41 < V_90 - 2 ; V_41 ++ ) {
V_79 ++ ;
if ( V_90 <= V_94 + 2 ) {
V_79 = V_90 - sizeof( struct V_88 ) ;
V_92 = 1 ;
}
if ( V_87 [ V_41 ] <= 0x7 && V_79 >= V_78 - 1 ) {
if ( ( V_79 > V_78 + 2 ) ||
( ( V_79 > V_78 ) &&
( V_93 [ 31 ] != V_93 [ 32 ] ) ) )
break;
if ( ! V_98 ( & V_87 [ V_41 ] , V_41 ) ) {
F_14 ( V_37 , V_52 ,
L_19 , V_41 ) ;
V_92 = 1 ;
}
else if ( ( V_93 [ 31 ] == V_93 [ 32 ] ) &&
( V_79 >= V_78 ) &&
( V_79 < V_78 + 2 ) &&
( V_87 [ V_41 + 1 ] <= 0x7 ) )
continue;
else if ( ( V_79 == V_78 - 1 ) &&
( V_87 [ V_41 + 1 ] <= 0x7 ) )
continue;
V_92 = 1 ;
}
if ( V_92 ) {
F_14 ( V_37 , V_52 , L_20 ,
V_79 ) ;
if ( V_79 != V_78 && V_90 <= V_94 + 2 ) {
F_17 ( V_93 ,
V_30 , V_78 ,
V_79 ) ;
V_99 ( V_29 , V_3 , V_30 ,
V_31 , V_32 , V_33 ) ;
memset ( V_30 , 0 , V_85 ) ;
F_25 ( V_30 , V_86 ) ;
}
if ( V_79 == V_78 ) {
V_42 = V_99 ( V_29 , V_3 , V_93 ,
V_31 , V_32 , V_33 ) ;
F_25 ( V_93 , V_86 ) ;
}
if ( V_90 <= V_94 + 2 )
break;
V_93 = & V_87 [ V_41 + 1 ] ;
if ( V_42 == 0 ) {
V_41 += V_86 - 2 ;
V_79 = V_86 - 2 ;
}
V_92 = 0 ;
}
}
V_41 -= V_86 - 2 ;
if ( V_90 - V_41 != sizeof( struct V_88 ) )
F_14 ( V_37 , V_52 , L_21
L_22 ,
V_90 - V_41 ) ;
return 1 ;
}
static T_8 F_26 ( struct V_112 * V_112 , char T_9 * V_113 ,
T_10 V_114 , T_11 * V_115 )
{
struct V_2 * V_3 = V_112 -> V_116 ;
char * V_117 = L_23 ;
unsigned int V_90 ;
switch ( V_3 -> V_118 ) {
case V_119 :
V_117 = L_24 ;
break;
case V_120 :
V_117 = L_25 ;
break;
case V_121 :
V_117 = L_26 ;
break;
case V_122 :
V_117 = L_27 ;
break;
}
V_90 = strlen ( V_117 ) ;
return F_27 ( V_113 , V_114 , V_115 , V_117 , V_90 ) ;
}
void F_28 ( struct V_36 * V_37 ,
struct V_2 * V_3 )
{
struct V_39 * V_38 = V_3 -> V_38 ;
T_12 V_123 ;
if ( F_29 ( V_124 ) )
return;
if ( ! F_30 ( V_38 ) -> V_125 ) {
F_31 ( V_37 , L_28 ) ;
return;
}
F_32 ( V_37 ) -> F_33 ( V_37 ) ;
V_123 = F_34 ( V_38 ) ;
F_35 ( V_38 , V_123 |
V_126 |
V_127 ) ;
F_36 ( V_37 , V_3 , V_3 -> V_118 ) ;
F_30 ( V_38 ) -> V_125 ( V_38 ) ;
F_32 ( V_37 ) -> F_37 ( V_37 ) ;
}
int F_36 ( struct V_36 * V_37 ,
struct V_2 * V_3 ,
enum V_118 V_118 )
{
struct V_39 * V_38 = V_3 -> V_38 ;
if ( ! F_30 ( V_38 ) -> V_125 ) {
F_31 ( V_37 , L_28 ) ;
return - 1 ;
}
switch ( V_118 ) {
case V_119 :
V_3 -> V_128 . V_129 = 0 ;
break;
case V_120 :
V_3 -> V_128 . V_130 = 1 ;
V_3 -> V_128 . V_129 = 1 ;
break;
case V_121 :
case V_122 :
V_3 -> V_128 . V_130 = 0 ;
V_3 -> V_128 . V_129 = 1 ;
break;
default:
return - 1 ;
}
F_32 ( V_37 ) -> F_33 ( V_37 ) ;
F_30 ( V_38 ) -> F_38 ( V_38 , & V_3 -> V_128 ) ;
F_32 ( V_37 ) -> F_37 ( V_37 ) ;
V_3 -> V_118 = V_118 ;
return 0 ;
}
static T_8 F_39 ( struct V_112 * V_112 ,
const char T_9 * V_113 ,
T_10 V_114 , T_11 * V_115 )
{
struct V_2 * V_3 = V_112 -> V_116 ;
struct V_36 * V_37 = F_10 ( V_3 -> V_38 ) ;
char V_82 [ 32 ] ;
T_8 V_90 ;
if ( F_29 ( V_124 ) )
return - V_131 ;
V_90 = F_40 ( V_114 , sizeof( V_82 ) - 1 ) ;
if ( F_41 ( V_82 , V_113 , V_90 ) )
return - V_132 ;
V_82 [ V_90 ] = '\0' ;
if ( strncmp ( L_29 , V_82 , 7 ) == 0 ) {
F_28 ( V_37 , V_3 ) ;
} else if ( strncmp ( L_25 , V_82 , 10 ) == 0 ) {
F_36 ( V_37 , V_3 , V_120 ) ;
F_14 ( V_37 , V_133 , L_30 ) ;
} else if ( strncmp ( L_26 , V_82 , 8 ) == 0 ) {
F_36 ( V_37 , V_3 , V_121 ) ;
F_14 ( V_37 , V_133 , L_31 ) ;
} else if ( strncmp ( L_27 , V_82 , 6 ) == 0 ) {
F_36 ( V_37 , V_3 , V_122 ) ;
F_14 ( V_37 , V_133 , L_32 ) ;
} else if ( strncmp ( L_24 , V_82 , 7 ) == 0 ) {
F_36 ( V_37 , V_3 , V_119 ) ;
F_14 ( V_37 , V_133 , L_33 ) ;
} else {
return - V_134 ;
}
return V_114 ;
}
static T_8 F_42 ( struct V_112 * V_112 ,
char T_9 * V_113 ,
T_10 V_114 , T_11 * V_115 )
{
struct V_2 * V_3 = V_112 -> V_116 ;
char V_82 [ 32 ] ;
unsigned int V_90 ;
V_90 = sprintf ( V_82 , L_34 , V_3 -> V_128 . V_135 ) ;
return F_27 ( V_113 , V_114 , V_115 , V_82 , V_90 ) ;
}
static T_8 F_43 ( struct V_112 * V_112 ,
const char T_9 * V_113 ,
T_10 V_114 , T_11 * V_115 )
{
struct V_2 * V_3 = V_112 -> V_116 ;
unsigned long V_136 ;
char V_82 [ 32 ] ;
T_8 V_90 ;
V_90 = F_40 ( V_114 , sizeof( V_82 ) - 1 ) ;
if ( F_41 ( V_82 , V_113 , V_90 ) )
return - V_132 ;
V_82 [ V_90 ] = '\0' ;
if ( F_44 ( V_82 , 0 , & V_136 ) )
return - V_134 ;
if ( V_136 > 1 )
return - V_134 ;
V_3 -> V_128 . V_135 = V_136 ;
return V_114 ;
}
static T_8 F_45 ( struct V_112 * V_112 ,
char T_9 * V_113 ,
T_10 V_114 , T_11 * V_115 )
{
struct V_2 * V_3 = V_112 -> V_116 ;
char V_82 [ 32 ] ;
unsigned int V_90 ;
V_90 = sprintf ( V_82 , L_34 , V_3 -> V_128 . V_114 ) ;
return F_27 ( V_113 , V_114 , V_115 , V_82 , V_90 ) ;
}
static T_8 F_46 ( struct V_112 * V_112 ,
const char T_9 * V_113 ,
T_10 V_114 , T_11 * V_115 )
{
struct V_2 * V_3 = V_112 -> V_116 ;
unsigned long V_136 ;
char V_82 [ 32 ] ;
T_8 V_90 ;
V_90 = F_40 ( V_114 , sizeof( V_82 ) - 1 ) ;
if ( F_41 ( V_82 , V_113 , V_90 ) )
return - V_132 ;
V_82 [ V_90 ] = '\0' ;
if ( F_44 ( V_82 , 0 , & V_136 ) )
return - V_134 ;
if ( V_136 > 255 )
return - V_134 ;
V_3 -> V_128 . V_114 = V_136 ;
return V_114 ;
}
static T_8 F_47 ( struct V_112 * V_112 ,
char T_9 * V_113 ,
T_10 V_114 , T_11 * V_115 )
{
struct V_2 * V_3 = V_112 -> V_116 ;
char V_82 [ 32 ] ;
unsigned int V_90 ;
V_90 = sprintf ( V_82 , L_34 , V_3 -> V_128 . V_137 ) ;
return F_27 ( V_113 , V_114 , V_115 , V_82 , V_90 ) ;
}
static T_8 F_48 ( struct V_112 * V_112 ,
const char T_9 * V_113 ,
T_10 V_114 , T_11 * V_115 )
{
struct V_2 * V_3 = V_112 -> V_116 ;
unsigned long V_136 ;
char V_82 [ 32 ] ;
T_8 V_90 ;
V_90 = F_40 ( V_114 , sizeof( V_82 ) - 1 ) ;
if ( F_41 ( V_82 , V_113 , V_90 ) )
return - V_132 ;
V_82 [ V_90 ] = '\0' ;
if ( F_44 ( V_82 , 0 , & V_136 ) )
return - V_134 ;
if ( V_136 > 255 )
return - V_134 ;
V_3 -> V_128 . V_137 = V_136 ;
return V_114 ;
}
static T_8 F_49 ( struct V_112 * V_112 ,
char T_9 * V_113 ,
T_10 V_114 , T_11 * V_115 )
{
struct V_2 * V_3 = V_112 -> V_116 ;
char V_82 [ 32 ] ;
unsigned int V_90 ;
V_90 = sprintf ( V_82 , L_34 , V_3 -> V_128 . V_138 ) ;
return F_27 ( V_113 , V_114 , V_115 , V_82 , V_90 ) ;
}
static T_8 F_50 ( struct V_112 * V_112 ,
const char T_9 * V_113 ,
T_10 V_114 , T_11 * V_115 )
{
struct V_2 * V_3 = V_112 -> V_116 ;
unsigned long V_136 ;
char V_82 [ 32 ] ;
T_8 V_90 ;
V_90 = F_40 ( V_114 , sizeof( V_82 ) - 1 ) ;
if ( F_41 ( V_82 , V_113 , V_90 ) )
return - V_132 ;
V_82 [ V_90 ] = '\0' ;
if ( F_44 ( V_82 , 0 , & V_136 ) )
return - V_134 ;
if ( V_136 > 15 )
return - V_134 ;
V_3 -> V_128 . V_138 = V_136 ;
return V_114 ;
}
static struct V_139 * F_51 ( const char * V_140 ,
struct V_139 * V_141 ,
T_13 V_117 ,
struct V_142 * V_82 ,
int * V_143 )
{
struct V_139 * V_144 ;
V_144 = F_52 ( V_140 , V_117 , V_141 , V_82 ,
& V_145 ) ;
* V_143 = 1 ;
return V_144 ;
}
static int F_53 ( struct V_139 * V_139 )
{
F_54 ( V_139 ) ;
return 0 ;
}
void F_55 ( struct V_2 * V_3 )
{
if ( V_3 -> V_6 ) {
F_56 ( V_3 -> V_6 ) ;
V_3 -> V_6 = NULL ;
}
}
void F_57 ( struct V_2 * V_3 ,
struct V_139 * V_146 )
{
V_3 -> V_6 = F_58 ( L_35 ,
V_146 ,
1024 , 256 , & V_147 ,
NULL ) ;
if ( ! V_3 -> V_6 )
return;
F_52 ( L_36 ,
V_148 | V_149 ,
V_146 , V_3 ,
& V_150 ) ;
F_52 ( L_37 ,
V_148 | V_149 ,
V_146 , V_3 ,
& V_151 ) ;
F_52 ( L_38 ,
V_148 | V_149 ,
V_146 , V_3 ,
& V_152 ) ;
F_52 ( L_39 ,
V_148 | V_149 ,
V_146 , V_3 ,
& V_153 ) ;
F_52 ( L_40 ,
V_148 | V_149 ,
V_146 , V_3 ,
& V_154 ) ;
}
