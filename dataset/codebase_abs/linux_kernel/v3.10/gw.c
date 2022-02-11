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
#define F_11 ( V_37 ) ((skb)->csum_start)
F_12 ( V_37 -> V_42 != V_43 ) ;
if ( F_11 ( V_37 ) >= V_44 ) {
V_39 -> V_45 ++ ;
return;
}
if ( ! ( V_39 -> V_2 . V_46 -> V_47 & V_48 ) ) {
V_39 -> V_49 ++ ;
return;
}
if ( ! ( V_39 -> V_47 & V_50 ) &&
F_13 ( V_37 ) -> V_51 == V_39 -> V_2 . V_46 -> V_51 )
return;
if ( V_39 -> V_52 . V_53 [ 0 ] )
V_40 = F_14 ( V_37 , V_54 ) ;
else
V_40 = F_15 ( V_37 , V_54 ) ;
if ( ! V_40 ) {
V_39 -> V_49 ++ ;
return;
}
F_11 ( V_40 ) = F_11 ( V_37 ) + 1 ;
V_40 -> V_46 = V_39 -> V_2 . V_46 ;
V_14 = (struct V_1 * ) V_40 -> V_7 ;
while ( V_41 < V_55 && V_39 -> V_52 . V_53 [ V_41 ] )
(* V_39 -> V_52 . V_53 [ V_41 ++ ])( V_14 , & V_39 -> V_52 ) ;
if ( V_41 ) {
if ( V_39 -> V_52 . V_56 . V_26 )
(* V_39 -> V_52 . V_56 . V_26 )( V_14 , & V_39 -> V_52 . V_57 . V_26 ) ;
if ( V_39 -> V_52 . V_56 . V_16 )
(* V_39 -> V_52 . V_56 . V_16 )( V_14 , & V_39 -> V_52 . V_57 . V_16 ) ;
}
if ( ! ( V_39 -> V_47 & V_58 ) )
V_40 -> V_59 . V_60 = 0 ;
if ( F_16 ( V_40 , V_39 -> V_47 & V_61 ) )
V_39 -> V_49 ++ ;
else
V_39 -> V_62 ++ ;
}
static inline int F_17 ( struct V_38 * V_39 )
{
return F_18 ( V_39 -> V_3 . V_46 , V_39 -> V_63 . V_64 . V_4 ,
V_39 -> V_63 . V_64 . V_65 , F_10 ,
V_39 , L_1 ) ;
}
static inline void F_19 ( struct V_38 * V_39 )
{
F_20 ( V_39 -> V_3 . V_46 , V_39 -> V_63 . V_64 . V_4 ,
V_39 -> V_63 . V_64 . V_65 , F_10 , V_39 ) ;
}
static int F_21 ( struct V_66 * V_67 ,
unsigned long V_68 , void * V_7 )
{
struct V_69 * V_46 = (struct V_69 * ) V_7 ;
if ( ! F_22 ( F_23 ( V_46 ) , & V_70 ) )
return V_71 ;
if ( V_46 -> type != V_72 )
return V_71 ;
if ( V_68 == V_73 ) {
struct V_38 * V_39 = NULL ;
struct V_74 * V_75 ;
F_24 () ;
F_25 (gwj, nx, &cgw_list, list) {
if ( V_39 -> V_3 . V_46 == V_46 || V_39 -> V_2 . V_46 == V_46 ) {
F_26 ( & V_39 -> V_76 ) ;
F_19 ( V_39 ) ;
F_27 ( V_77 , V_39 ) ;
}
}
}
return V_71 ;
}
static int F_28 ( struct V_36 * V_37 , struct V_38 * V_39 , int type ,
T_3 V_78 , T_3 V_79 , int V_47 )
{
struct V_80 V_81 ;
struct V_82 * V_83 ;
struct V_84 * V_85 ;
V_85 = F_29 ( V_37 , V_78 , V_79 , type , sizeof( * V_83 ) , V_47 ) ;
if ( ! V_85 )
return - V_86 ;
V_83 = F_30 ( V_85 ) ;
V_83 -> V_87 = V_88 ;
V_83 -> V_89 = V_39 -> V_89 ;
V_83 -> V_47 = V_39 -> V_47 ;
if ( V_39 -> V_62 ) {
if ( F_31 ( V_37 , V_90 , V_39 -> V_62 ) < 0 )
goto V_91;
}
if ( V_39 -> V_49 ) {
if ( F_31 ( V_37 , V_92 , V_39 -> V_49 ) < 0 )
goto V_91;
}
if ( V_39 -> V_45 ) {
if ( F_31 ( V_37 , V_93 , V_39 -> V_45 ) < 0 )
goto V_91;
}
if ( V_39 -> V_52 . V_94 . V_95 ) {
memcpy ( & V_81 . V_14 , & V_39 -> V_52 . V_96 . V_95 , sizeof( V_81 . V_14 ) ) ;
V_81 . V_94 = V_39 -> V_52 . V_94 . V_95 ;
if ( F_32 ( V_37 , V_97 , sizeof( V_81 ) , & V_81 ) < 0 )
goto V_91;
}
if ( V_39 -> V_52 . V_94 . V_98 ) {
memcpy ( & V_81 . V_14 , & V_39 -> V_52 . V_96 . V_98 , sizeof( V_81 . V_14 ) ) ;
V_81 . V_94 = V_39 -> V_52 . V_94 . V_98 ;
if ( F_32 ( V_37 , V_99 , sizeof( V_81 ) , & V_81 ) < 0 )
goto V_91;
}
if ( V_39 -> V_52 . V_94 . V_16 ) {
memcpy ( & V_81 . V_14 , & V_39 -> V_52 . V_96 . V_16 , sizeof( V_81 . V_14 ) ) ;
V_81 . V_94 = V_39 -> V_52 . V_94 . V_16 ;
if ( F_32 ( V_37 , V_100 , sizeof( V_81 ) , & V_81 ) < 0 )
goto V_91;
}
if ( V_39 -> V_52 . V_94 . V_101 ) {
memcpy ( & V_81 . V_14 , & V_39 -> V_52 . V_96 . V_101 , sizeof( V_81 . V_14 ) ) ;
V_81 . V_94 = V_39 -> V_52 . V_94 . V_101 ;
if ( F_32 ( V_37 , V_102 , sizeof( V_81 ) , & V_81 ) < 0 )
goto V_91;
}
if ( V_39 -> V_52 . V_56 . V_26 ) {
if ( F_32 ( V_37 , V_103 , V_104 ,
& V_39 -> V_52 . V_57 . V_26 ) < 0 )
goto V_91;
}
if ( V_39 -> V_52 . V_56 . V_16 ) {
if ( F_32 ( V_37 , V_105 , V_106 ,
& V_39 -> V_52 . V_57 . V_16 ) < 0 )
goto V_91;
}
if ( V_39 -> V_89 == V_107 ) {
if ( V_39 -> V_63 . V_64 . V_4 || V_39 -> V_63 . V_64 . V_65 ) {
if ( F_32 ( V_37 , V_108 , sizeof( struct V_109 ) ,
& V_39 -> V_63 . V_64 ) < 0 )
goto V_91;
}
if ( F_31 ( V_37 , V_110 , V_39 -> V_63 . V_111 ) < 0 )
goto V_91;
if ( F_31 ( V_37 , V_112 , V_39 -> V_63 . V_113 ) < 0 )
goto V_91;
}
return F_33 ( V_37 , V_85 ) ;
V_91:
F_34 ( V_37 , V_85 ) ;
return - V_86 ;
}
static int F_35 ( struct V_36 * V_37 , struct V_114 * V_115 )
{
struct V_38 * V_39 = NULL ;
int V_12 = 0 ;
int V_116 = V_115 -> args [ 0 ] ;
F_36 () ;
F_37 (gwj, &cgw_list, list) {
if ( V_12 < V_116 )
goto V_117;
if ( F_28 ( V_37 , V_39 , V_118 , F_38 ( V_115 -> V_37 ) . V_119 ,
V_115 -> V_85 -> V_120 , V_121 ) < 0 )
break;
V_117:
V_12 ++ ;
}
F_39 () ;
V_115 -> args [ 0 ] = V_12 ;
return V_37 -> V_122 ;
}
static int F_40 ( struct V_84 * V_85 , struct V_123 * V_52 ,
T_2 V_89 , void * V_124 )
{
struct V_125 * V_126 [ V_127 + 1 ] ;
struct V_80 V_81 ;
int V_41 = 0 ;
int V_128 = 0 ;
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
V_128 = F_41 ( V_85 , sizeof( struct V_82 ) , V_126 , V_127 ,
V_129 ) ;
if ( V_128 < 0 )
return V_128 ;
if ( V_126 [ V_97 ] ) {
F_42 ( & V_81 , V_126 [ V_97 ] , V_130 ) ;
F_1 ( & V_52 -> V_96 . V_95 , & V_81 . V_14 ) ;
V_52 -> V_94 . V_95 = V_81 . V_94 ;
if ( V_81 . V_94 & V_131 )
V_52 -> V_53 [ V_41 ++ ] = V_132 ;
if ( V_81 . V_94 & V_133 )
V_52 -> V_53 [ V_41 ++ ] = V_134 ;
if ( V_81 . V_94 & V_135 )
V_52 -> V_53 [ V_41 ++ ] = V_136 ;
}
if ( V_126 [ V_99 ] ) {
F_42 ( & V_81 , V_126 [ V_99 ] , V_130 ) ;
F_1 ( & V_52 -> V_96 . V_98 , & V_81 . V_14 ) ;
V_52 -> V_94 . V_98 = V_81 . V_94 ;
if ( V_81 . V_94 & V_131 )
V_52 -> V_53 [ V_41 ++ ] = V_137 ;
if ( V_81 . V_94 & V_133 )
V_52 -> V_53 [ V_41 ++ ] = V_138 ;
if ( V_81 . V_94 & V_135 )
V_52 -> V_53 [ V_41 ++ ] = V_139 ;
}
if ( V_126 [ V_100 ] ) {
F_42 ( & V_81 , V_126 [ V_100 ] , V_130 ) ;
F_1 ( & V_52 -> V_96 . V_16 , & V_81 . V_14 ) ;
V_52 -> V_94 . V_16 = V_81 . V_94 ;
if ( V_81 . V_94 & V_131 )
V_52 -> V_53 [ V_41 ++ ] = V_140 ;
if ( V_81 . V_94 & V_133 )
V_52 -> V_53 [ V_41 ++ ] = V_141 ;
if ( V_81 . V_94 & V_135 )
V_52 -> V_53 [ V_41 ++ ] = V_142 ;
}
if ( V_126 [ V_102 ] ) {
F_42 ( & V_81 , V_126 [ V_102 ] , V_130 ) ;
F_1 ( & V_52 -> V_96 . V_101 , & V_81 . V_14 ) ;
V_52 -> V_94 . V_101 = V_81 . V_94 ;
if ( V_81 . V_94 & V_131 )
V_52 -> V_53 [ V_41 ++ ] = V_143 ;
if ( V_81 . V_94 & V_133 )
V_52 -> V_53 [ V_41 ++ ] = V_144 ;
if ( V_81 . V_94 & V_135 )
V_52 -> V_53 [ V_41 ++ ] = V_145 ;
}
if ( V_41 ) {
if ( V_126 [ V_103 ] ) {
struct V_25 * V_146 = F_43 ( V_126 [ V_103 ] ) ;
V_128 = F_2 ( V_146 -> V_18 , V_146 -> V_19 ,
V_146 -> V_21 ) ;
if ( V_128 )
return V_128 ;
F_42 ( & V_52 -> V_57 . V_26 , V_126 [ V_103 ] ,
V_104 ) ;
if ( V_146 -> V_18 < 0 || V_146 -> V_19 < 0 ||
V_146 -> V_21 < 0 )
V_52 -> V_56 . V_26 = F_7 ;
else if ( V_146 -> V_18 <= V_146 -> V_19 )
V_52 -> V_56 . V_26 = F_8 ;
else
V_52 -> V_56 . V_26 = F_9 ;
}
if ( V_126 [ V_105 ] ) {
struct V_15 * V_146 = F_43 ( V_126 [ V_105 ] ) ;
V_128 = F_2 ( V_146 -> V_18 , V_146 -> V_19 ,
V_146 -> V_21 ) ;
if ( V_128 )
return V_128 ;
F_42 ( & V_52 -> V_57 . V_16 , V_126 [ V_105 ] ,
V_106 ) ;
if ( V_146 -> V_18 < 0 || V_146 -> V_19 < 0 ||
V_146 -> V_21 < 0 )
V_52 -> V_56 . V_16 = F_4 ;
else if ( V_146 -> V_18 <= V_146 -> V_19 )
V_52 -> V_56 . V_16 = F_5 ;
else
V_52 -> V_56 . V_16 = F_6 ;
}
}
if ( V_89 == V_107 ) {
struct V_147 * V_63 = (struct V_147 * ) V_124 ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
if ( V_126 [ V_108 ] )
F_42 ( & V_63 -> V_64 , V_126 [ V_108 ] ,
sizeof( struct V_109 ) ) ;
V_128 = - V_148 ;
if ( ! V_126 [ V_110 ] || ! V_126 [ V_112 ] )
return V_128 ;
V_63 -> V_111 = F_44 ( V_126 [ V_110 ] ) ;
V_63 -> V_113 = F_44 ( V_126 [ V_112 ] ) ;
if ( ! V_63 -> V_111 && ! V_63 -> V_113 )
return 0 ;
if ( ! V_63 -> V_111 || ! V_63 -> V_113 )
return V_128 ;
}
return 0 ;
}
static int F_45 ( struct V_36 * V_37 , struct V_84 * V_85 )
{
struct V_82 * V_149 ;
struct V_38 * V_39 ;
int V_128 = 0 ;
if ( ! F_46 ( V_150 ) )
return - V_151 ;
if ( F_47 ( V_85 ) < sizeof( * V_149 ) )
return - V_11 ;
V_149 = F_30 ( V_85 ) ;
if ( V_149 -> V_87 != V_88 )
return - V_152 ;
if ( V_149 -> V_89 != V_107 )
return - V_11 ;
V_39 = F_48 ( V_77 , V_153 ) ;
if ( ! V_39 )
return - V_154 ;
V_39 -> V_62 = 0 ;
V_39 -> V_49 = 0 ;
V_39 -> V_45 = 0 ;
V_39 -> V_47 = V_149 -> V_47 ;
V_39 -> V_89 = V_149 -> V_89 ;
V_128 = F_40 ( V_85 , & V_39 -> V_52 , V_107 , & V_39 -> V_63 ) ;
if ( V_128 < 0 )
goto V_155;
V_128 = - V_148 ;
if ( ! V_39 -> V_63 . V_111 || ! V_39 -> V_63 . V_113 )
goto V_155;
V_39 -> V_3 . V_46 = F_49 ( & V_70 , V_39 -> V_63 . V_111 ) ;
if ( ! V_39 -> V_3 . V_46 )
goto V_155;
if ( V_39 -> V_3 . V_46 -> type != V_72 || V_39 -> V_3 . V_46 -> V_156 )
goto V_157;
V_39 -> V_2 . V_46 = F_49 ( & V_70 , V_39 -> V_63 . V_113 ) ;
if ( ! V_39 -> V_2 . V_46 )
goto V_157;
if ( V_39 -> V_2 . V_46 -> type != V_72 || V_39 -> V_2 . V_46 -> V_156 )
goto V_158;
F_24 () ;
V_128 = F_17 ( V_39 ) ;
if ( ! V_128 )
F_50 ( & V_39 -> V_76 , & V_159 ) ;
V_158:
F_51 ( V_39 -> V_2 . V_46 ) ;
V_157:
F_51 ( V_39 -> V_3 . V_46 ) ;
V_155:
if ( V_128 )
F_27 ( V_77 , V_39 ) ;
return V_128 ;
}
static void F_52 ( void )
{
struct V_38 * V_39 = NULL ;
struct V_74 * V_75 ;
F_24 () ;
F_25 (gwj, nx, &cgw_list, list) {
F_26 ( & V_39 -> V_76 ) ;
F_19 ( V_39 ) ;
F_27 ( V_77 , V_39 ) ;
}
}
static int F_53 ( struct V_36 * V_37 , struct V_84 * V_85 )
{
struct V_38 * V_39 = NULL ;
struct V_74 * V_75 ;
struct V_82 * V_149 ;
struct V_123 V_52 ;
struct V_147 V_63 ;
int V_128 = 0 ;
if ( ! F_46 ( V_150 ) )
return - V_151 ;
if ( F_47 ( V_85 ) < sizeof( * V_149 ) )
return - V_11 ;
V_149 = F_30 ( V_85 ) ;
if ( V_149 -> V_87 != V_88 )
return - V_152 ;
if ( V_149 -> V_89 != V_107 )
return - V_11 ;
V_128 = F_40 ( V_85 , & V_52 , V_107 , & V_63 ) ;
if ( V_128 < 0 )
return V_128 ;
if ( ! V_63 . V_111 && ! V_63 . V_113 ) {
F_52 () ;
return 0 ;
}
V_128 = - V_11 ;
F_24 () ;
F_25 (gwj, nx, &cgw_list, list) {
if ( V_39 -> V_47 != V_149 -> V_47 )
continue;
if ( memcmp ( & V_39 -> V_52 , & V_52 , sizeof( V_52 ) ) )
continue;
if ( memcmp ( & V_39 -> V_63 , & V_63 , sizeof( V_63 ) ) )
continue;
F_26 ( & V_39 -> V_76 ) ;
F_19 ( V_39 ) ;
F_27 ( V_77 , V_39 ) ;
V_128 = 0 ;
break;
}
return V_128 ;
}
static T_4 int F_54 ( void )
{
V_44 = F_55 (unsigned int, max_hops, CGW_MIN_HOPS, CGW_MAX_HOPS) ;
F_56 ( L_2 V_160 L_3 ,
V_44 ) ;
V_77 = F_57 ( L_4 , sizeof( struct V_38 ) ,
0 , 0 , NULL ) ;
if ( ! V_77 )
return - V_154 ;
V_161 . V_162 = F_21 ;
F_58 ( & V_161 ) ;
if ( F_59 ( V_163 , V_164 , NULL , F_35 , NULL ) ) {
F_60 ( & V_161 ) ;
F_61 ( V_77 ) ;
return - V_165 ;
}
F_59 ( V_163 , V_118 , F_45 , NULL , NULL ) ;
F_59 ( V_163 , V_166 , F_53 , NULL , NULL ) ;
return 0 ;
}
static T_5 void F_62 ( void )
{
F_63 ( V_163 ) ;
F_60 ( & V_161 ) ;
F_64 () ;
F_52 () ;
F_65 () ;
F_66 () ;
F_61 ( V_77 ) ;
}
