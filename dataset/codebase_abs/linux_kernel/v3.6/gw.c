static inline void F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
V_2 -> V_4 = V_3 -> V_4 ;
V_2 -> V_5 = V_3 -> V_5 ;
* ( V_6 * ) V_2 -> V_7 = * ( V_6 * ) V_3 -> V_7 ;
}
static int F_2 ( T_1 V_8 , T_1 V_9 , T_1 V_10 )
{
if ( V_8 > - 9 && V_8 < 8 &&
V_9 > - 9 && V_9 < 8 &&
V_10 > - 9 && V_10 < 8 )
return 0 ;
else
return - V_11 ;
}
static inline int F_3 ( int V_12 , int V_13 )
{
if ( V_12 < 0 )
return V_13 + V_12 ;
else
return V_12 ;
}
static void F_4 ( struct V_1 * V_14 , struct V_15 * V_16 )
{
int V_17 = F_3 ( V_16 -> V_18 , V_14 -> V_5 ) ;
int V_9 = F_3 ( V_16 -> V_19 , V_14 -> V_5 ) ;
int V_20 = F_3 ( V_16 -> V_21 , V_14 -> V_5 ) ;
T_2 V_22 = V_16 -> V_23 ;
int V_24 ;
if ( V_17 < 0 || V_9 < 0 || V_20 < 0 )
return;
if ( V_17 <= V_9 ) {
for ( V_24 = V_17 ; V_24 <= V_9 ; V_24 ++ )
V_22 ^= V_14 -> V_7 [ V_24 ] ;
} else {
for ( V_24 = V_17 ; V_24 >= V_9 ; V_24 -- )
V_22 ^= V_14 -> V_7 [ V_24 ] ;
}
V_14 -> V_7 [ V_20 ] = V_22 ;
}
static void F_5 ( struct V_1 * V_14 , struct V_15 * V_16 )
{
T_2 V_22 = V_16 -> V_23 ;
int V_24 ;
for ( V_24 = V_16 -> V_18 ; V_24 <= V_16 -> V_19 ; V_24 ++ )
V_22 ^= V_14 -> V_7 [ V_24 ] ;
V_14 -> V_7 [ V_16 -> V_21 ] = V_22 ;
}
static void F_6 ( struct V_1 * V_14 , struct V_15 * V_16 )
{
T_2 V_22 = V_16 -> V_23 ;
int V_24 ;
for ( V_24 = V_16 -> V_18 ; V_24 >= V_16 -> V_19 ; V_24 -- )
V_22 ^= V_14 -> V_7 [ V_24 ] ;
V_14 -> V_7 [ V_16 -> V_21 ] = V_22 ;
}
static void F_7 ( struct V_1 * V_14 , struct V_25 * V_26 )
{
int V_17 = F_3 ( V_26 -> V_18 , V_14 -> V_5 ) ;
int V_9 = F_3 ( V_26 -> V_19 , V_14 -> V_5 ) ;
int V_20 = F_3 ( V_26 -> V_21 , V_14 -> V_5 ) ;
T_2 V_27 = V_26 -> V_28 ;
int V_24 ;
if ( V_17 < 0 || V_9 < 0 || V_20 < 0 )
return;
if ( V_17 <= V_9 ) {
for ( V_24 = V_26 -> V_18 ; V_24 <= V_26 -> V_19 ; V_24 ++ )
V_27 = V_26 -> V_29 [ V_27 ^ V_14 -> V_7 [ V_24 ] ] ;
} else {
for ( V_24 = V_26 -> V_18 ; V_24 >= V_26 -> V_19 ; V_24 -- )
V_27 = V_26 -> V_29 [ V_27 ^ V_14 -> V_7 [ V_24 ] ] ;
}
switch ( V_26 -> V_30 ) {
case V_31 :
V_27 = V_26 -> V_29 [ V_27 ^ V_26 -> V_32 [ 0 ] ] ;
break;
case V_33 :
V_27 = V_26 -> V_29 [ V_27 ^ V_26 -> V_32 [ V_14 -> V_7 [ 1 ] & 0xF ] ] ;
break;
case V_34 :
V_27 = V_26 -> V_29 [ V_27 ^ ( V_14 -> V_4 & 0xFF ) ^
( V_14 -> V_4 >> 8 & 0xFF ) ] ;
break;
}
V_14 -> V_7 [ V_26 -> V_21 ] = V_27 ^ V_26 -> V_35 ;
}
static void F_8 ( struct V_1 * V_14 , struct V_25 * V_26 )
{
T_2 V_27 = V_26 -> V_28 ;
int V_24 ;
for ( V_24 = V_26 -> V_18 ; V_24 <= V_26 -> V_19 ; V_24 ++ )
V_27 = V_26 -> V_29 [ V_27 ^ V_14 -> V_7 [ V_24 ] ] ;
switch ( V_26 -> V_30 ) {
case V_31 :
V_27 = V_26 -> V_29 [ V_27 ^ V_26 -> V_32 [ 0 ] ] ;
break;
case V_33 :
V_27 = V_26 -> V_29 [ V_27 ^ V_26 -> V_32 [ V_14 -> V_7 [ 1 ] & 0xF ] ] ;
break;
case V_34 :
V_27 = V_26 -> V_29 [ V_27 ^ ( V_14 -> V_4 & 0xFF ) ^
( V_14 -> V_4 >> 8 & 0xFF ) ] ;
break;
}
V_14 -> V_7 [ V_26 -> V_21 ] = V_27 ^ V_26 -> V_35 ;
}
static void F_9 ( struct V_1 * V_14 , struct V_25 * V_26 )
{
T_2 V_27 = V_26 -> V_28 ;
int V_24 ;
for ( V_24 = V_26 -> V_18 ; V_24 >= V_26 -> V_19 ; V_24 -- )
V_27 = V_26 -> V_29 [ V_27 ^ V_14 -> V_7 [ V_24 ] ] ;
switch ( V_26 -> V_30 ) {
case V_31 :
V_27 = V_26 -> V_29 [ V_27 ^ V_26 -> V_32 [ 0 ] ] ;
break;
case V_33 :
V_27 = V_26 -> V_29 [ V_27 ^ V_26 -> V_32 [ V_14 -> V_7 [ 1 ] & 0xF ] ] ;
break;
case V_34 :
V_27 = V_26 -> V_29 [ V_27 ^ ( V_14 -> V_4 & 0xFF ) ^
( V_14 -> V_4 >> 8 & 0xFF ) ] ;
break;
}
V_14 -> V_7 [ V_26 -> V_21 ] = V_27 ^ V_26 -> V_35 ;
}
static void F_10 ( struct V_36 * V_37 , void * V_7 )
{
struct V_38 * V_39 = (struct V_38 * ) V_7 ;
struct V_1 * V_14 ;
struct V_36 * V_40 ;
int V_41 = 0 ;
if ( F_11 ( V_37 ) )
return;
if ( ! ( V_39 -> V_2 . V_42 -> V_43 & V_44 ) ) {
V_39 -> V_45 ++ ;
return;
}
if ( V_39 -> V_46 . V_47 [ 0 ] )
V_40 = F_12 ( V_37 , V_48 ) ;
else
V_40 = F_13 ( V_37 , V_48 ) ;
if ( ! V_40 ) {
V_39 -> V_45 ++ ;
return;
}
F_14 ( V_40 , 8 ) ;
V_40 -> V_42 = V_39 -> V_2 . V_42 ;
V_14 = (struct V_1 * ) V_40 -> V_7 ;
while ( V_41 < V_49 && V_39 -> V_46 . V_47 [ V_41 ] )
(* V_39 -> V_46 . V_47 [ V_41 ++ ])( V_14 , & V_39 -> V_46 ) ;
if ( V_41 ) {
if ( V_39 -> V_46 . V_50 . V_26 )
(* V_39 -> V_46 . V_50 . V_26 )( V_14 , & V_39 -> V_46 . V_51 . V_26 ) ;
if ( V_39 -> V_46 . V_50 . V_16 )
(* V_39 -> V_46 . V_50 . V_16 )( V_14 , & V_39 -> V_46 . V_51 . V_16 ) ;
}
if ( ! ( V_39 -> V_43 & V_52 ) )
V_40 -> V_53 . V_54 = 0 ;
if ( F_15 ( V_40 , V_39 -> V_43 & V_55 ) )
V_39 -> V_45 ++ ;
else
V_39 -> V_56 ++ ;
}
static inline int F_16 ( struct V_38 * V_39 )
{
return F_17 ( V_39 -> V_3 . V_42 , V_39 -> V_57 . V_58 . V_4 ,
V_39 -> V_57 . V_58 . V_59 , F_10 ,
V_39 , L_1 ) ;
}
static inline void F_18 ( struct V_38 * V_39 )
{
F_19 ( V_39 -> V_3 . V_42 , V_39 -> V_57 . V_58 . V_4 ,
V_39 -> V_57 . V_58 . V_59 , F_10 , V_39 ) ;
}
static int F_20 ( struct V_60 * V_61 ,
unsigned long V_62 , void * V_7 )
{
struct V_63 * V_42 = (struct V_63 * ) V_7 ;
if ( ! F_21 ( F_22 ( V_42 ) , & V_64 ) )
return V_65 ;
if ( V_42 -> type != V_66 )
return V_65 ;
if ( V_62 == V_67 ) {
struct V_38 * V_39 = NULL ;
struct V_68 * V_69 , * V_70 ;
F_23 () ;
F_24 (gwj, n, nx, &cgw_list, list) {
if ( V_39 -> V_3 . V_42 == V_42 || V_39 -> V_2 . V_42 == V_42 ) {
F_25 ( & V_39 -> V_71 ) ;
F_18 ( V_39 ) ;
F_26 ( V_39 ) ;
}
}
}
return V_65 ;
}
static int F_27 ( struct V_36 * V_37 , struct V_38 * V_39 , int type ,
T_3 V_72 , T_3 V_73 , int V_43 )
{
struct V_74 V_75 ;
struct V_76 * V_77 ;
struct V_78 * V_79 ;
V_79 = F_28 ( V_37 , V_72 , V_73 , type , sizeof( * V_77 ) , V_43 ) ;
if ( ! V_79 )
return - V_80 ;
V_77 = F_29 ( V_79 ) ;
V_77 -> V_81 = V_82 ;
V_77 -> V_83 = V_39 -> V_83 ;
V_77 -> V_43 = V_39 -> V_43 ;
if ( V_39 -> V_56 ) {
if ( F_30 ( V_37 , V_84 , V_39 -> V_56 ) < 0 )
goto V_85;
}
if ( V_39 -> V_45 ) {
if ( F_30 ( V_37 , V_86 , V_39 -> V_45 ) < 0 )
goto V_85;
}
if ( V_39 -> V_46 . V_87 . V_88 ) {
memcpy ( & V_75 . V_14 , & V_39 -> V_46 . V_89 . V_88 , sizeof( V_75 . V_14 ) ) ;
V_75 . V_87 = V_39 -> V_46 . V_87 . V_88 ;
if ( F_31 ( V_37 , V_90 , sizeof( V_75 ) , & V_75 ) < 0 )
goto V_85;
}
if ( V_39 -> V_46 . V_87 . V_91 ) {
memcpy ( & V_75 . V_14 , & V_39 -> V_46 . V_89 . V_91 , sizeof( V_75 . V_14 ) ) ;
V_75 . V_87 = V_39 -> V_46 . V_87 . V_91 ;
if ( F_31 ( V_37 , V_92 , sizeof( V_75 ) , & V_75 ) < 0 )
goto V_85;
}
if ( V_39 -> V_46 . V_87 . V_16 ) {
memcpy ( & V_75 . V_14 , & V_39 -> V_46 . V_89 . V_16 , sizeof( V_75 . V_14 ) ) ;
V_75 . V_87 = V_39 -> V_46 . V_87 . V_16 ;
if ( F_31 ( V_37 , V_93 , sizeof( V_75 ) , & V_75 ) < 0 )
goto V_85;
}
if ( V_39 -> V_46 . V_87 . V_94 ) {
memcpy ( & V_75 . V_14 , & V_39 -> V_46 . V_89 . V_94 , sizeof( V_75 . V_14 ) ) ;
V_75 . V_87 = V_39 -> V_46 . V_87 . V_94 ;
if ( F_31 ( V_37 , V_95 , sizeof( V_75 ) , & V_75 ) < 0 )
goto V_85;
}
if ( V_39 -> V_46 . V_50 . V_26 ) {
if ( F_31 ( V_37 , V_96 , V_97 ,
& V_39 -> V_46 . V_51 . V_26 ) < 0 )
goto V_85;
}
if ( V_39 -> V_46 . V_50 . V_16 ) {
if ( F_31 ( V_37 , V_98 , V_99 ,
& V_39 -> V_46 . V_51 . V_16 ) < 0 )
goto V_85;
}
if ( V_39 -> V_83 == V_100 ) {
if ( V_39 -> V_57 . V_58 . V_4 || V_39 -> V_57 . V_58 . V_59 ) {
if ( F_31 ( V_37 , V_101 , sizeof( struct V_102 ) ,
& V_39 -> V_57 . V_58 ) < 0 )
goto V_85;
}
if ( F_30 ( V_37 , V_103 , V_39 -> V_57 . V_104 ) < 0 )
goto V_85;
if ( F_30 ( V_37 , V_105 , V_39 -> V_57 . V_106 ) < 0 )
goto V_85;
}
return F_32 ( V_37 , V_79 ) ;
V_85:
F_33 ( V_37 , V_79 ) ;
return - V_80 ;
}
static int F_34 ( struct V_36 * V_37 , struct V_107 * V_108 )
{
struct V_38 * V_39 = NULL ;
struct V_68 * V_69 ;
int V_12 = 0 ;
int V_109 = V_108 -> args [ 0 ] ;
F_35 () ;
F_36 (gwj, n, &cgw_list, list) {
if ( V_12 < V_109 )
goto V_110;
if ( F_27 ( V_37 , V_39 , V_111 , F_37 ( V_108 -> V_37 ) . V_72 ,
V_108 -> V_79 -> V_112 , V_113 ) < 0 )
break;
V_110:
V_12 ++ ;
}
F_38 () ;
V_108 -> args [ 0 ] = V_12 ;
return V_37 -> V_114 ;
}
static int F_39 ( struct V_78 * V_79 , struct V_115 * V_46 ,
T_2 V_83 , void * V_116 )
{
struct V_117 * V_118 [ V_119 + 1 ] ;
struct V_74 V_75 ;
int V_41 = 0 ;
int V_120 = 0 ;
memset ( V_46 , 0 , sizeof( * V_46 ) ) ;
V_120 = F_40 ( V_79 , sizeof( struct V_76 ) , V_118 , V_119 ,
V_121 ) ;
if ( V_120 < 0 )
return V_120 ;
if ( V_118 [ V_90 ] ) {
F_41 ( & V_75 , V_118 [ V_90 ] , V_122 ) ;
F_1 ( & V_46 -> V_89 . V_88 , & V_75 . V_14 ) ;
V_46 -> V_87 . V_88 = V_75 . V_87 ;
if ( V_75 . V_87 & V_123 )
V_46 -> V_47 [ V_41 ++ ] = V_124 ;
if ( V_75 . V_87 & V_125 )
V_46 -> V_47 [ V_41 ++ ] = V_126 ;
if ( V_75 . V_87 & V_127 )
V_46 -> V_47 [ V_41 ++ ] = V_128 ;
}
if ( V_118 [ V_92 ] ) {
F_41 ( & V_75 , V_118 [ V_92 ] , V_122 ) ;
F_1 ( & V_46 -> V_89 . V_91 , & V_75 . V_14 ) ;
V_46 -> V_87 . V_91 = V_75 . V_87 ;
if ( V_75 . V_87 & V_123 )
V_46 -> V_47 [ V_41 ++ ] = V_129 ;
if ( V_75 . V_87 & V_125 )
V_46 -> V_47 [ V_41 ++ ] = V_130 ;
if ( V_75 . V_87 & V_127 )
V_46 -> V_47 [ V_41 ++ ] = V_131 ;
}
if ( V_118 [ V_93 ] ) {
F_41 ( & V_75 , V_118 [ V_93 ] , V_122 ) ;
F_1 ( & V_46 -> V_89 . V_16 , & V_75 . V_14 ) ;
V_46 -> V_87 . V_16 = V_75 . V_87 ;
if ( V_75 . V_87 & V_123 )
V_46 -> V_47 [ V_41 ++ ] = V_132 ;
if ( V_75 . V_87 & V_125 )
V_46 -> V_47 [ V_41 ++ ] = V_133 ;
if ( V_75 . V_87 & V_127 )
V_46 -> V_47 [ V_41 ++ ] = V_134 ;
}
if ( V_118 [ V_95 ] ) {
F_41 ( & V_75 , V_118 [ V_95 ] , V_122 ) ;
F_1 ( & V_46 -> V_89 . V_94 , & V_75 . V_14 ) ;
V_46 -> V_87 . V_94 = V_75 . V_87 ;
if ( V_75 . V_87 & V_123 )
V_46 -> V_47 [ V_41 ++ ] = V_135 ;
if ( V_75 . V_87 & V_125 )
V_46 -> V_47 [ V_41 ++ ] = V_136 ;
if ( V_75 . V_87 & V_127 )
V_46 -> V_47 [ V_41 ++ ] = V_137 ;
}
if ( V_41 ) {
if ( V_118 [ V_96 ] ) {
struct V_25 * V_138 = F_42 ( V_118 [ V_96 ] ) ;
V_120 = F_2 ( V_138 -> V_18 , V_138 -> V_19 ,
V_138 -> V_21 ) ;
if ( V_120 )
return V_120 ;
F_41 ( & V_46 -> V_51 . V_26 , V_118 [ V_96 ] ,
V_97 ) ;
if ( V_138 -> V_18 < 0 || V_138 -> V_19 < 0 ||
V_138 -> V_21 < 0 )
V_46 -> V_50 . V_26 = F_7 ;
else if ( V_138 -> V_18 <= V_138 -> V_19 )
V_46 -> V_50 . V_26 = F_8 ;
else
V_46 -> V_50 . V_26 = F_9 ;
}
if ( V_118 [ V_98 ] ) {
struct V_15 * V_138 = F_42 ( V_118 [ V_98 ] ) ;
V_120 = F_2 ( V_138 -> V_18 , V_138 -> V_19 ,
V_138 -> V_21 ) ;
if ( V_120 )
return V_120 ;
F_41 ( & V_46 -> V_51 . V_16 , V_118 [ V_98 ] ,
V_99 ) ;
if ( V_138 -> V_18 < 0 || V_138 -> V_19 < 0 ||
V_138 -> V_21 < 0 )
V_46 -> V_50 . V_16 = F_4 ;
else if ( V_138 -> V_18 <= V_138 -> V_19 )
V_46 -> V_50 . V_16 = F_5 ;
else
V_46 -> V_50 . V_16 = F_6 ;
}
}
if ( V_83 == V_100 ) {
struct V_139 * V_57 = (struct V_139 * ) V_116 ;
memset ( V_57 , 0 , sizeof( * V_57 ) ) ;
if ( V_118 [ V_101 ] )
F_41 ( & V_57 -> V_58 , V_118 [ V_101 ] ,
sizeof( struct V_102 ) ) ;
V_120 = - V_140 ;
if ( ! V_118 [ V_103 ] || ! V_118 [ V_105 ] )
return V_120 ;
V_57 -> V_104 = F_43 ( V_118 [ V_103 ] ) ;
V_57 -> V_106 = F_43 ( V_118 [ V_105 ] ) ;
if ( ! V_57 -> V_104 && ! V_57 -> V_106 )
return 0 ;
if ( ! V_57 -> V_104 || ! V_57 -> V_106 )
return V_120 ;
}
return 0 ;
}
static int F_44 ( struct V_36 * V_37 , struct V_78 * V_79 ,
void * V_141 )
{
struct V_76 * V_142 ;
struct V_38 * V_39 ;
int V_120 = 0 ;
if ( F_45 ( V_79 ) < sizeof( * V_142 ) )
return - V_11 ;
V_142 = F_29 ( V_79 ) ;
if ( V_142 -> V_81 != V_82 )
return - V_143 ;
if ( V_142 -> V_83 != V_100 )
return - V_11 ;
V_39 = F_46 ( V_144 , V_145 ) ;
if ( ! V_39 )
return - V_146 ;
V_39 -> V_56 = 0 ;
V_39 -> V_45 = 0 ;
V_39 -> V_43 = V_142 -> V_43 ;
V_39 -> V_83 = V_142 -> V_83 ;
V_120 = F_39 ( V_79 , & V_39 -> V_46 , V_100 , & V_39 -> V_57 ) ;
if ( V_120 < 0 )
goto V_147;
V_120 = - V_140 ;
if ( ! V_39 -> V_57 . V_104 || ! V_39 -> V_57 . V_106 )
goto V_147;
V_39 -> V_3 . V_42 = F_47 ( & V_64 , V_39 -> V_57 . V_104 ) ;
if ( ! V_39 -> V_3 . V_42 )
goto V_147;
if ( V_39 -> V_3 . V_42 -> type != V_66 || V_39 -> V_3 . V_42 -> V_148 )
goto V_149;
V_39 -> V_2 . V_42 = F_47 ( & V_64 , V_39 -> V_57 . V_106 ) ;
if ( ! V_39 -> V_2 . V_42 )
goto V_149;
if ( V_39 -> V_2 . V_42 -> type != V_66 || V_39 -> V_2 . V_42 -> V_148 )
goto V_150;
F_23 () ;
V_120 = F_16 ( V_39 ) ;
if ( ! V_120 )
F_48 ( & V_39 -> V_71 , & V_151 ) ;
V_150:
F_49 ( V_39 -> V_2 . V_42 ) ;
V_149:
F_49 ( V_39 -> V_3 . V_42 ) ;
V_147:
if ( V_120 )
F_50 ( V_144 , V_39 ) ;
return V_120 ;
}
static void F_51 ( void )
{
struct V_38 * V_39 = NULL ;
struct V_68 * V_69 , * V_70 ;
F_23 () ;
F_24 (gwj, n, nx, &cgw_list, list) {
F_25 ( & V_39 -> V_71 ) ;
F_18 ( V_39 ) ;
F_26 ( V_39 ) ;
}
}
static int F_52 ( struct V_36 * V_37 , struct V_78 * V_79 , void * V_141 )
{
struct V_38 * V_39 = NULL ;
struct V_68 * V_69 , * V_70 ;
struct V_76 * V_142 ;
struct V_115 V_46 ;
struct V_139 V_57 ;
int V_120 = 0 ;
if ( F_45 ( V_79 ) < sizeof( * V_142 ) )
return - V_11 ;
V_142 = F_29 ( V_79 ) ;
if ( V_142 -> V_81 != V_82 )
return - V_143 ;
if ( V_142 -> V_83 != V_100 )
return - V_11 ;
V_120 = F_39 ( V_79 , & V_46 , V_100 , & V_57 ) ;
if ( V_120 < 0 )
return V_120 ;
if ( ! V_57 . V_104 && ! V_57 . V_106 ) {
F_51 () ;
return 0 ;
}
V_120 = - V_11 ;
F_23 () ;
F_24 (gwj, n, nx, &cgw_list, list) {
if ( V_39 -> V_43 != V_142 -> V_43 )
continue;
if ( memcmp ( & V_39 -> V_46 , & V_46 , sizeof( V_46 ) ) )
continue;
if ( memcmp ( & V_39 -> V_57 , & V_57 , sizeof( V_57 ) ) )
continue;
F_25 ( & V_39 -> V_71 ) ;
F_18 ( V_39 ) ;
F_26 ( V_39 ) ;
V_120 = 0 ;
break;
}
return V_120 ;
}
static T_4 int F_53 ( void )
{
F_54 ( V_152 ) ;
V_144 = F_55 ( L_2 , sizeof( struct V_38 ) ,
0 , 0 , NULL ) ;
if ( ! V_144 )
return - V_146 ;
V_153 . V_154 = F_20 ;
F_56 ( & V_153 ) ;
if ( F_57 ( V_155 , V_156 , NULL , F_34 , NULL ) ) {
F_58 ( & V_153 ) ;
F_59 ( V_144 ) ;
return - V_157 ;
}
F_57 ( V_155 , V_111 , F_44 , NULL , NULL ) ;
F_57 ( V_155 , V_158 , F_52 , NULL , NULL ) ;
return 0 ;
}
static T_5 void F_60 ( void )
{
F_61 ( V_155 ) ;
F_58 ( & V_153 ) ;
F_62 () ;
F_51 () ;
F_63 () ;
F_64 () ;
F_59 ( V_144 ) ;
}
