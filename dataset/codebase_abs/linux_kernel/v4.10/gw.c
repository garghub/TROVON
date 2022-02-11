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
if ( V_39 -> V_55 && F_11 ( V_40 ) == 1 )
F_11 ( V_40 ) = V_44 - V_39 -> V_55 + 1 ;
V_40 -> V_46 = V_39 -> V_2 . V_46 ;
V_14 = (struct V_1 * ) V_40 -> V_7 ;
while ( V_41 < V_56 && V_39 -> V_52 . V_53 [ V_41 ] )
(* V_39 -> V_52 . V_53 [ V_41 ++ ])( V_14 , & V_39 -> V_52 ) ;
if ( V_41 ) {
if ( V_39 -> V_52 . V_57 . V_26 )
(* V_39 -> V_52 . V_57 . V_26 )( V_14 , & V_39 -> V_52 . V_58 . V_26 ) ;
if ( V_39 -> V_52 . V_57 . V_16 )
(* V_39 -> V_52 . V_57 . V_16 )( V_14 , & V_39 -> V_52 . V_58 . V_16 ) ;
}
if ( ! ( V_39 -> V_47 & V_59 ) )
V_40 -> V_60 = 0 ;
if ( F_16 ( V_40 , V_39 -> V_47 & V_61 ) )
V_39 -> V_49 ++ ;
else
V_39 -> V_62 ++ ;
}
static inline int F_17 ( struct V_38 * V_39 )
{
return F_18 ( V_39 -> V_3 . V_46 , V_39 -> V_63 . V_64 . V_4 ,
V_39 -> V_63 . V_64 . V_65 , F_10 ,
V_39 , L_1 , NULL ) ;
}
static inline void F_19 ( struct V_38 * V_39 )
{
F_20 ( V_39 -> V_3 . V_46 , V_39 -> V_63 . V_64 . V_4 ,
V_39 -> V_63 . V_64 . V_65 , F_10 , V_39 ) ;
}
static int F_21 ( struct V_66 * V_67 ,
unsigned long V_68 , void * V_69 )
{
struct V_70 * V_46 = F_22 ( V_69 ) ;
if ( ! F_23 ( F_24 ( V_46 ) , & V_71 ) )
return V_72 ;
if ( V_46 -> type != V_73 )
return V_72 ;
if ( V_68 == V_74 ) {
struct V_38 * V_39 = NULL ;
struct V_75 * V_76 ;
F_25 () ;
F_26 (gwj, nx, &cgw_list, list) {
if ( V_39 -> V_3 . V_46 == V_46 || V_39 -> V_2 . V_46 == V_46 ) {
F_27 ( & V_39 -> V_77 ) ;
F_19 ( V_39 ) ;
F_28 ( V_78 , V_39 ) ;
}
}
}
return V_72 ;
}
static int F_29 ( struct V_36 * V_37 , struct V_38 * V_39 , int type ,
T_3 V_79 , T_3 V_80 , int V_47 )
{
struct V_81 V_82 ;
struct V_83 * V_84 ;
struct V_85 * V_86 ;
V_86 = F_30 ( V_37 , V_79 , V_80 , type , sizeof( * V_84 ) , V_47 ) ;
if ( ! V_86 )
return - V_87 ;
V_84 = F_31 ( V_86 ) ;
V_84 -> V_88 = V_89 ;
V_84 -> V_90 = V_39 -> V_90 ;
V_84 -> V_47 = V_39 -> V_47 ;
if ( V_39 -> V_62 ) {
if ( F_32 ( V_37 , V_91 , V_39 -> V_62 ) < 0 )
goto V_92;
}
if ( V_39 -> V_49 ) {
if ( F_32 ( V_37 , V_93 , V_39 -> V_49 ) < 0 )
goto V_92;
}
if ( V_39 -> V_45 ) {
if ( F_32 ( V_37 , V_94 , V_39 -> V_45 ) < 0 )
goto V_92;
}
if ( V_39 -> V_55 ) {
if ( F_33 ( V_37 , V_95 , V_39 -> V_55 ) < 0 )
goto V_92;
}
if ( V_39 -> V_52 . V_96 . V_97 ) {
memcpy ( & V_82 . V_14 , & V_39 -> V_52 . V_98 . V_97 , sizeof( V_82 . V_14 ) ) ;
V_82 . V_96 = V_39 -> V_52 . V_96 . V_97 ;
if ( F_34 ( V_37 , V_99 , sizeof( V_82 ) , & V_82 ) < 0 )
goto V_92;
}
if ( V_39 -> V_52 . V_96 . V_100 ) {
memcpy ( & V_82 . V_14 , & V_39 -> V_52 . V_98 . V_100 , sizeof( V_82 . V_14 ) ) ;
V_82 . V_96 = V_39 -> V_52 . V_96 . V_100 ;
if ( F_34 ( V_37 , V_101 , sizeof( V_82 ) , & V_82 ) < 0 )
goto V_92;
}
if ( V_39 -> V_52 . V_96 . V_16 ) {
memcpy ( & V_82 . V_14 , & V_39 -> V_52 . V_98 . V_16 , sizeof( V_82 . V_14 ) ) ;
V_82 . V_96 = V_39 -> V_52 . V_96 . V_16 ;
if ( F_34 ( V_37 , V_102 , sizeof( V_82 ) , & V_82 ) < 0 )
goto V_92;
}
if ( V_39 -> V_52 . V_96 . V_103 ) {
memcpy ( & V_82 . V_14 , & V_39 -> V_52 . V_98 . V_103 , sizeof( V_82 . V_14 ) ) ;
V_82 . V_96 = V_39 -> V_52 . V_96 . V_103 ;
if ( F_34 ( V_37 , V_104 , sizeof( V_82 ) , & V_82 ) < 0 )
goto V_92;
}
if ( V_39 -> V_52 . V_105 ) {
if ( F_32 ( V_37 , V_106 , V_39 -> V_52 . V_105 ) < 0 )
goto V_92;
}
if ( V_39 -> V_52 . V_57 . V_26 ) {
if ( F_34 ( V_37 , V_107 , V_108 ,
& V_39 -> V_52 . V_58 . V_26 ) < 0 )
goto V_92;
}
if ( V_39 -> V_52 . V_57 . V_16 ) {
if ( F_34 ( V_37 , V_109 , V_110 ,
& V_39 -> V_52 . V_58 . V_16 ) < 0 )
goto V_92;
}
if ( V_39 -> V_90 == V_111 ) {
if ( V_39 -> V_63 . V_64 . V_4 || V_39 -> V_63 . V_64 . V_65 ) {
if ( F_34 ( V_37 , V_112 , sizeof( struct V_113 ) ,
& V_39 -> V_63 . V_64 ) < 0 )
goto V_92;
}
if ( F_32 ( V_37 , V_114 , V_39 -> V_63 . V_115 ) < 0 )
goto V_92;
if ( F_32 ( V_37 , V_116 , V_39 -> V_63 . V_117 ) < 0 )
goto V_92;
}
F_35 ( V_37 , V_86 ) ;
return 0 ;
V_92:
F_36 ( V_37 , V_86 ) ;
return - V_87 ;
}
static int F_37 ( struct V_36 * V_37 , struct V_118 * V_119 )
{
struct V_38 * V_39 = NULL ;
int V_12 = 0 ;
int V_120 = V_119 -> args [ 0 ] ;
F_38 () ;
F_39 (gwj, &cgw_list, list) {
if ( V_12 < V_120 )
goto V_121;
if ( F_29 ( V_37 , V_39 , V_122 , F_40 ( V_119 -> V_37 ) . V_123 ,
V_119 -> V_86 -> V_124 , V_125 ) < 0 )
break;
V_121:
V_12 ++ ;
}
F_41 () ;
V_119 -> args [ 0 ] = V_12 ;
return V_37 -> V_126 ;
}
static int F_42 ( struct V_85 * V_86 , struct V_127 * V_52 ,
T_2 V_90 , void * V_128 , T_2 * V_129 )
{
struct V_130 * V_131 [ V_132 + 1 ] ;
struct V_81 V_82 ;
int V_41 = 0 ;
int V_133 = 0 ;
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
V_133 = F_43 ( V_86 , sizeof( struct V_83 ) , V_131 , V_132 ,
V_134 ) ;
if ( V_133 < 0 )
return V_133 ;
if ( V_131 [ V_95 ] ) {
* V_129 = F_44 ( V_131 [ V_95 ] ) ;
if ( * V_129 < 1 || * V_129 > V_44 )
return - V_11 ;
}
if ( V_131 [ V_99 ] ) {
F_45 ( & V_82 , V_131 [ V_99 ] , V_135 ) ;
F_1 ( & V_52 -> V_98 . V_97 , & V_82 . V_14 ) ;
V_52 -> V_96 . V_97 = V_82 . V_96 ;
if ( V_82 . V_96 & V_136 )
V_52 -> V_53 [ V_41 ++ ] = V_137 ;
if ( V_82 . V_96 & V_138 )
V_52 -> V_53 [ V_41 ++ ] = V_139 ;
if ( V_82 . V_96 & V_140 )
V_52 -> V_53 [ V_41 ++ ] = V_141 ;
}
if ( V_131 [ V_101 ] ) {
F_45 ( & V_82 , V_131 [ V_101 ] , V_135 ) ;
F_1 ( & V_52 -> V_98 . V_100 , & V_82 . V_14 ) ;
V_52 -> V_96 . V_100 = V_82 . V_96 ;
if ( V_82 . V_96 & V_136 )
V_52 -> V_53 [ V_41 ++ ] = V_142 ;
if ( V_82 . V_96 & V_138 )
V_52 -> V_53 [ V_41 ++ ] = V_143 ;
if ( V_82 . V_96 & V_140 )
V_52 -> V_53 [ V_41 ++ ] = V_144 ;
}
if ( V_131 [ V_102 ] ) {
F_45 ( & V_82 , V_131 [ V_102 ] , V_135 ) ;
F_1 ( & V_52 -> V_98 . V_16 , & V_82 . V_14 ) ;
V_52 -> V_96 . V_16 = V_82 . V_96 ;
if ( V_82 . V_96 & V_136 )
V_52 -> V_53 [ V_41 ++ ] = V_145 ;
if ( V_82 . V_96 & V_138 )
V_52 -> V_53 [ V_41 ++ ] = V_146 ;
if ( V_82 . V_96 & V_140 )
V_52 -> V_53 [ V_41 ++ ] = V_147 ;
}
if ( V_131 [ V_104 ] ) {
F_45 ( & V_82 , V_131 [ V_104 ] , V_135 ) ;
F_1 ( & V_52 -> V_98 . V_103 , & V_82 . V_14 ) ;
V_52 -> V_96 . V_103 = V_82 . V_96 ;
if ( V_82 . V_96 & V_136 )
V_52 -> V_53 [ V_41 ++ ] = V_148 ;
if ( V_82 . V_96 & V_138 )
V_52 -> V_53 [ V_41 ++ ] = V_149 ;
if ( V_82 . V_96 & V_140 )
V_52 -> V_53 [ V_41 ++ ] = V_150 ;
}
if ( V_41 ) {
if ( V_131 [ V_107 ] ) {
struct V_25 * V_151 = F_46 ( V_131 [ V_107 ] ) ;
V_133 = F_2 ( V_151 -> V_18 , V_151 -> V_19 ,
V_151 -> V_21 ) ;
if ( V_133 )
return V_133 ;
F_45 ( & V_52 -> V_58 . V_26 , V_131 [ V_107 ] ,
V_108 ) ;
if ( V_151 -> V_18 < 0 || V_151 -> V_19 < 0 ||
V_151 -> V_21 < 0 )
V_52 -> V_57 . V_26 = F_7 ;
else if ( V_151 -> V_18 <= V_151 -> V_19 )
V_52 -> V_57 . V_26 = F_8 ;
else
V_52 -> V_57 . V_26 = F_9 ;
}
if ( V_131 [ V_109 ] ) {
struct V_15 * V_151 = F_46 ( V_131 [ V_109 ] ) ;
V_133 = F_2 ( V_151 -> V_18 , V_151 -> V_19 ,
V_151 -> V_21 ) ;
if ( V_133 )
return V_133 ;
F_45 ( & V_52 -> V_58 . V_16 , V_131 [ V_109 ] ,
V_110 ) ;
if ( V_151 -> V_18 < 0 || V_151 -> V_19 < 0 ||
V_151 -> V_21 < 0 )
V_52 -> V_57 . V_16 = F_4 ;
else if ( V_151 -> V_18 <= V_151 -> V_19 )
V_52 -> V_57 . V_16 = F_5 ;
else
V_52 -> V_57 . V_16 = F_6 ;
}
if ( V_131 [ V_106 ] ) {
F_45 ( & V_52 -> V_105 , V_131 [ V_106 ] , sizeof( T_3 ) ) ;
}
}
if ( V_90 == V_111 ) {
struct V_152 * V_63 = (struct V_152 * ) V_128 ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
if ( V_131 [ V_112 ] )
F_45 ( & V_63 -> V_64 , V_131 [ V_112 ] ,
sizeof( struct V_113 ) ) ;
V_133 = - V_153 ;
if ( ! V_131 [ V_114 ] || ! V_131 [ V_116 ] )
return V_133 ;
V_63 -> V_115 = F_47 ( V_131 [ V_114 ] ) ;
V_63 -> V_117 = F_47 ( V_131 [ V_116 ] ) ;
if ( ! V_63 -> V_115 && ! V_63 -> V_117 )
return 0 ;
if ( ! V_63 -> V_115 || ! V_63 -> V_117 )
return V_133 ;
}
return 0 ;
}
static int F_48 ( struct V_36 * V_37 , struct V_85 * V_86 )
{
struct V_83 * V_154 ;
struct V_38 * V_39 ;
struct V_127 V_52 ;
struct V_152 V_63 ;
T_2 V_129 = 0 ;
int V_133 = 0 ;
if ( ! F_49 ( V_37 , V_155 ) )
return - V_156 ;
if ( F_50 ( V_86 ) < sizeof( * V_154 ) )
return - V_11 ;
V_154 = F_31 ( V_86 ) ;
if ( V_154 -> V_88 != V_89 )
return - V_157 ;
if ( V_154 -> V_90 != V_111 )
return - V_11 ;
V_133 = F_42 ( V_86 , & V_52 , V_111 , & V_63 , & V_129 ) ;
if ( V_133 < 0 )
return V_133 ;
if ( V_52 . V_105 ) {
F_25 () ;
F_51 (gwj, &cgw_list, list) {
if ( V_39 -> V_52 . V_105 != V_52 . V_105 )
continue;
if ( memcmp ( & V_39 -> V_63 , & V_63 , sizeof( V_63 ) ) )
return - V_11 ;
F_52 () ;
memcpy ( & V_39 -> V_52 , & V_52 , sizeof( V_52 ) ) ;
F_53 () ;
return 0 ;
}
}
if ( ! V_63 . V_115 || ! V_63 . V_117 )
return - V_153 ;
V_39 = F_54 ( V_78 , V_158 ) ;
if ( ! V_39 )
return - V_159 ;
V_39 -> V_62 = 0 ;
V_39 -> V_49 = 0 ;
V_39 -> V_45 = 0 ;
V_39 -> V_47 = V_154 -> V_47 ;
V_39 -> V_90 = V_154 -> V_90 ;
V_39 -> V_55 = V_129 ;
memcpy ( & V_39 -> V_52 , & V_52 , sizeof( V_52 ) ) ;
memcpy ( & V_39 -> V_63 , & V_63 , sizeof( V_63 ) ) ;
V_133 = - V_153 ;
V_39 -> V_3 . V_46 = F_55 ( & V_71 , V_39 -> V_63 . V_115 ) ;
if ( ! V_39 -> V_3 . V_46 )
goto V_160;
if ( V_39 -> V_3 . V_46 -> type != V_73 )
goto V_160;
V_39 -> V_2 . V_46 = F_55 ( & V_71 , V_39 -> V_63 . V_117 ) ;
if ( ! V_39 -> V_2 . V_46 )
goto V_160;
if ( V_39 -> V_2 . V_46 -> type != V_73 )
goto V_160;
F_25 () ;
V_133 = F_17 ( V_39 ) ;
if ( ! V_133 )
F_56 ( & V_39 -> V_77 , & V_161 ) ;
V_160:
if ( V_133 )
F_28 ( V_78 , V_39 ) ;
return V_133 ;
}
static void F_57 ( void )
{
struct V_38 * V_39 = NULL ;
struct V_75 * V_76 ;
F_25 () ;
F_26 (gwj, nx, &cgw_list, list) {
F_27 ( & V_39 -> V_77 ) ;
F_19 ( V_39 ) ;
F_28 ( V_78 , V_39 ) ;
}
}
static int F_58 ( struct V_36 * V_37 , struct V_85 * V_86 )
{
struct V_38 * V_39 = NULL ;
struct V_75 * V_76 ;
struct V_83 * V_154 ;
struct V_127 V_52 ;
struct V_152 V_63 ;
T_2 V_129 = 0 ;
int V_133 = 0 ;
if ( ! F_49 ( V_37 , V_155 ) )
return - V_156 ;
if ( F_50 ( V_86 ) < sizeof( * V_154 ) )
return - V_11 ;
V_154 = F_31 ( V_86 ) ;
if ( V_154 -> V_88 != V_89 )
return - V_157 ;
if ( V_154 -> V_90 != V_111 )
return - V_11 ;
V_133 = F_42 ( V_86 , & V_52 , V_111 , & V_63 , & V_129 ) ;
if ( V_133 < 0 )
return V_133 ;
if ( ! V_63 . V_115 && ! V_63 . V_117 ) {
F_57 () ;
return 0 ;
}
V_133 = - V_11 ;
F_25 () ;
F_26 (gwj, nx, &cgw_list, list) {
if ( V_39 -> V_47 != V_154 -> V_47 )
continue;
if ( V_39 -> V_55 != V_129 )
continue;
if ( V_39 -> V_52 . V_105 || V_52 . V_105 ) {
if ( V_39 -> V_52 . V_105 != V_52 . V_105 )
continue;
} else {
if ( memcmp ( & V_39 -> V_52 , & V_52 , sizeof( V_52 ) ) )
continue;
}
if ( memcmp ( & V_39 -> V_63 , & V_63 , sizeof( V_63 ) ) )
continue;
F_27 ( & V_39 -> V_77 ) ;
F_19 ( V_39 ) ;
F_28 ( V_78 , V_39 ) ;
V_133 = 0 ;
break;
}
return V_133 ;
}
static T_4 int F_59 ( void )
{
V_44 = F_60 (unsigned int, max_hops, CGW_MIN_HOPS, CGW_MAX_HOPS) ;
F_61 ( L_2 V_162 L_3 ,
V_44 ) ;
V_78 = F_62 ( L_4 , sizeof( struct V_38 ) ,
0 , 0 , NULL ) ;
if ( ! V_78 )
return - V_159 ;
V_163 . V_164 = F_21 ;
F_63 ( & V_163 ) ;
if ( F_64 ( V_165 , V_166 , NULL , F_37 , NULL ) ) {
F_65 ( & V_163 ) ;
F_66 ( V_78 ) ;
return - V_167 ;
}
F_64 ( V_165 , V_122 , F_48 , NULL , NULL ) ;
F_64 ( V_165 , V_168 , F_58 , NULL , NULL ) ;
return 0 ;
}
static T_5 void F_67 ( void )
{
F_68 ( V_165 ) ;
F_65 ( & V_163 ) ;
F_69 () ;
F_57 () ;
F_70 () ;
F_71 () ;
F_66 ( V_78 ) ;
}
