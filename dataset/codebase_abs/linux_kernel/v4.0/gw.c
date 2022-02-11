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
V_40 -> V_60 . V_61 = 0 ;
if ( F_16 ( V_40 , V_39 -> V_47 & V_62 ) )
V_39 -> V_49 ++ ;
else
V_39 -> V_63 ++ ;
}
static inline int F_17 ( struct V_38 * V_39 )
{
return F_18 ( V_39 -> V_3 . V_46 , V_39 -> V_64 . V_65 . V_4 ,
V_39 -> V_64 . V_65 . V_66 , F_10 ,
V_39 , L_1 ) ;
}
static inline void F_19 ( struct V_38 * V_39 )
{
F_20 ( V_39 -> V_3 . V_46 , V_39 -> V_64 . V_65 . V_4 ,
V_39 -> V_64 . V_65 . V_66 , F_10 , V_39 ) ;
}
static int F_21 ( struct V_67 * V_68 ,
unsigned long V_69 , void * V_70 )
{
struct V_71 * V_46 = F_22 ( V_70 ) ;
if ( ! F_23 ( F_24 ( V_46 ) , & V_72 ) )
return V_73 ;
if ( V_46 -> type != V_74 )
return V_73 ;
if ( V_69 == V_75 ) {
struct V_38 * V_39 = NULL ;
struct V_76 * V_77 ;
F_25 () ;
F_26 (gwj, nx, &cgw_list, list) {
if ( V_39 -> V_3 . V_46 == V_46 || V_39 -> V_2 . V_46 == V_46 ) {
F_27 ( & V_39 -> V_78 ) ;
F_19 ( V_39 ) ;
F_28 ( V_79 , V_39 ) ;
}
}
}
return V_73 ;
}
static int F_29 ( struct V_36 * V_37 , struct V_38 * V_39 , int type ,
T_3 V_80 , T_3 V_81 , int V_47 )
{
struct V_82 V_83 ;
struct V_84 * V_85 ;
struct V_86 * V_87 ;
V_87 = F_30 ( V_37 , V_80 , V_81 , type , sizeof( * V_85 ) , V_47 ) ;
if ( ! V_87 )
return - V_88 ;
V_85 = F_31 ( V_87 ) ;
V_85 -> V_89 = V_90 ;
V_85 -> V_91 = V_39 -> V_91 ;
V_85 -> V_47 = V_39 -> V_47 ;
if ( V_39 -> V_63 ) {
if ( F_32 ( V_37 , V_92 , V_39 -> V_63 ) < 0 )
goto V_93;
}
if ( V_39 -> V_49 ) {
if ( F_32 ( V_37 , V_94 , V_39 -> V_49 ) < 0 )
goto V_93;
}
if ( V_39 -> V_45 ) {
if ( F_32 ( V_37 , V_95 , V_39 -> V_45 ) < 0 )
goto V_93;
}
if ( V_39 -> V_55 ) {
if ( F_33 ( V_37 , V_96 , V_39 -> V_55 ) < 0 )
goto V_93;
}
if ( V_39 -> V_52 . V_97 . V_98 ) {
memcpy ( & V_83 . V_14 , & V_39 -> V_52 . V_99 . V_98 , sizeof( V_83 . V_14 ) ) ;
V_83 . V_97 = V_39 -> V_52 . V_97 . V_98 ;
if ( F_34 ( V_37 , V_100 , sizeof( V_83 ) , & V_83 ) < 0 )
goto V_93;
}
if ( V_39 -> V_52 . V_97 . V_101 ) {
memcpy ( & V_83 . V_14 , & V_39 -> V_52 . V_99 . V_101 , sizeof( V_83 . V_14 ) ) ;
V_83 . V_97 = V_39 -> V_52 . V_97 . V_101 ;
if ( F_34 ( V_37 , V_102 , sizeof( V_83 ) , & V_83 ) < 0 )
goto V_93;
}
if ( V_39 -> V_52 . V_97 . V_16 ) {
memcpy ( & V_83 . V_14 , & V_39 -> V_52 . V_99 . V_16 , sizeof( V_83 . V_14 ) ) ;
V_83 . V_97 = V_39 -> V_52 . V_97 . V_16 ;
if ( F_34 ( V_37 , V_103 , sizeof( V_83 ) , & V_83 ) < 0 )
goto V_93;
}
if ( V_39 -> V_52 . V_97 . V_104 ) {
memcpy ( & V_83 . V_14 , & V_39 -> V_52 . V_99 . V_104 , sizeof( V_83 . V_14 ) ) ;
V_83 . V_97 = V_39 -> V_52 . V_97 . V_104 ;
if ( F_34 ( V_37 , V_105 , sizeof( V_83 ) , & V_83 ) < 0 )
goto V_93;
}
if ( V_39 -> V_52 . V_57 . V_26 ) {
if ( F_34 ( V_37 , V_106 , V_107 ,
& V_39 -> V_52 . V_58 . V_26 ) < 0 )
goto V_93;
}
if ( V_39 -> V_52 . V_57 . V_16 ) {
if ( F_34 ( V_37 , V_108 , V_109 ,
& V_39 -> V_52 . V_58 . V_16 ) < 0 )
goto V_93;
}
if ( V_39 -> V_91 == V_110 ) {
if ( V_39 -> V_64 . V_65 . V_4 || V_39 -> V_64 . V_65 . V_66 ) {
if ( F_34 ( V_37 , V_111 , sizeof( struct V_112 ) ,
& V_39 -> V_64 . V_65 ) < 0 )
goto V_93;
}
if ( F_32 ( V_37 , V_113 , V_39 -> V_64 . V_114 ) < 0 )
goto V_93;
if ( F_32 ( V_37 , V_115 , V_39 -> V_64 . V_116 ) < 0 )
goto V_93;
}
F_35 ( V_37 , V_87 ) ;
return 0 ;
V_93:
F_36 ( V_37 , V_87 ) ;
return - V_88 ;
}
static int F_37 ( struct V_36 * V_37 , struct V_117 * V_118 )
{
struct V_38 * V_39 = NULL ;
int V_12 = 0 ;
int V_119 = V_118 -> args [ 0 ] ;
F_38 () ;
F_39 (gwj, &cgw_list, list) {
if ( V_12 < V_119 )
goto V_120;
if ( F_29 ( V_37 , V_39 , V_121 , F_40 ( V_118 -> V_37 ) . V_122 ,
V_118 -> V_87 -> V_123 , V_124 ) < 0 )
break;
V_120:
V_12 ++ ;
}
F_41 () ;
V_118 -> args [ 0 ] = V_12 ;
return V_37 -> V_125 ;
}
static int F_42 ( struct V_86 * V_87 , struct V_126 * V_52 ,
T_2 V_91 , void * V_127 , T_2 * V_128 )
{
struct V_129 * V_130 [ V_131 + 1 ] ;
struct V_82 V_83 ;
int V_41 = 0 ;
int V_132 = 0 ;
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
V_132 = F_43 ( V_87 , sizeof( struct V_84 ) , V_130 , V_131 ,
V_133 ) ;
if ( V_132 < 0 )
return V_132 ;
if ( V_130 [ V_96 ] ) {
* V_128 = F_44 ( V_130 [ V_96 ] ) ;
if ( * V_128 < 1 || * V_128 > V_44 )
return - V_11 ;
}
if ( V_130 [ V_100 ] ) {
F_45 ( & V_83 , V_130 [ V_100 ] , V_134 ) ;
F_1 ( & V_52 -> V_99 . V_98 , & V_83 . V_14 ) ;
V_52 -> V_97 . V_98 = V_83 . V_97 ;
if ( V_83 . V_97 & V_135 )
V_52 -> V_53 [ V_41 ++ ] = V_136 ;
if ( V_83 . V_97 & V_137 )
V_52 -> V_53 [ V_41 ++ ] = V_138 ;
if ( V_83 . V_97 & V_139 )
V_52 -> V_53 [ V_41 ++ ] = V_140 ;
}
if ( V_130 [ V_102 ] ) {
F_45 ( & V_83 , V_130 [ V_102 ] , V_134 ) ;
F_1 ( & V_52 -> V_99 . V_101 , & V_83 . V_14 ) ;
V_52 -> V_97 . V_101 = V_83 . V_97 ;
if ( V_83 . V_97 & V_135 )
V_52 -> V_53 [ V_41 ++ ] = V_141 ;
if ( V_83 . V_97 & V_137 )
V_52 -> V_53 [ V_41 ++ ] = V_142 ;
if ( V_83 . V_97 & V_139 )
V_52 -> V_53 [ V_41 ++ ] = V_143 ;
}
if ( V_130 [ V_103 ] ) {
F_45 ( & V_83 , V_130 [ V_103 ] , V_134 ) ;
F_1 ( & V_52 -> V_99 . V_16 , & V_83 . V_14 ) ;
V_52 -> V_97 . V_16 = V_83 . V_97 ;
if ( V_83 . V_97 & V_135 )
V_52 -> V_53 [ V_41 ++ ] = V_144 ;
if ( V_83 . V_97 & V_137 )
V_52 -> V_53 [ V_41 ++ ] = V_145 ;
if ( V_83 . V_97 & V_139 )
V_52 -> V_53 [ V_41 ++ ] = V_146 ;
}
if ( V_130 [ V_105 ] ) {
F_45 ( & V_83 , V_130 [ V_105 ] , V_134 ) ;
F_1 ( & V_52 -> V_99 . V_104 , & V_83 . V_14 ) ;
V_52 -> V_97 . V_104 = V_83 . V_97 ;
if ( V_83 . V_97 & V_135 )
V_52 -> V_53 [ V_41 ++ ] = V_147 ;
if ( V_83 . V_97 & V_137 )
V_52 -> V_53 [ V_41 ++ ] = V_148 ;
if ( V_83 . V_97 & V_139 )
V_52 -> V_53 [ V_41 ++ ] = V_149 ;
}
if ( V_41 ) {
if ( V_130 [ V_106 ] ) {
struct V_25 * V_150 = F_46 ( V_130 [ V_106 ] ) ;
V_132 = F_2 ( V_150 -> V_18 , V_150 -> V_19 ,
V_150 -> V_21 ) ;
if ( V_132 )
return V_132 ;
F_45 ( & V_52 -> V_58 . V_26 , V_130 [ V_106 ] ,
V_107 ) ;
if ( V_150 -> V_18 < 0 || V_150 -> V_19 < 0 ||
V_150 -> V_21 < 0 )
V_52 -> V_57 . V_26 = F_7 ;
else if ( V_150 -> V_18 <= V_150 -> V_19 )
V_52 -> V_57 . V_26 = F_8 ;
else
V_52 -> V_57 . V_26 = F_9 ;
}
if ( V_130 [ V_108 ] ) {
struct V_15 * V_150 = F_46 ( V_130 [ V_108 ] ) ;
V_132 = F_2 ( V_150 -> V_18 , V_150 -> V_19 ,
V_150 -> V_21 ) ;
if ( V_132 )
return V_132 ;
F_45 ( & V_52 -> V_58 . V_16 , V_130 [ V_108 ] ,
V_109 ) ;
if ( V_150 -> V_18 < 0 || V_150 -> V_19 < 0 ||
V_150 -> V_21 < 0 )
V_52 -> V_57 . V_16 = F_4 ;
else if ( V_150 -> V_18 <= V_150 -> V_19 )
V_52 -> V_57 . V_16 = F_5 ;
else
V_52 -> V_57 . V_16 = F_6 ;
}
}
if ( V_91 == V_110 ) {
struct V_151 * V_64 = (struct V_151 * ) V_127 ;
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
if ( V_130 [ V_111 ] )
F_45 ( & V_64 -> V_65 , V_130 [ V_111 ] ,
sizeof( struct V_112 ) ) ;
V_132 = - V_152 ;
if ( ! V_130 [ V_113 ] || ! V_130 [ V_115 ] )
return V_132 ;
V_64 -> V_114 = F_47 ( V_130 [ V_113 ] ) ;
V_64 -> V_116 = F_47 ( V_130 [ V_115 ] ) ;
if ( ! V_64 -> V_114 && ! V_64 -> V_116 )
return 0 ;
if ( ! V_64 -> V_114 || ! V_64 -> V_116 )
return V_132 ;
}
return 0 ;
}
static int F_48 ( struct V_36 * V_37 , struct V_86 * V_87 )
{
struct V_84 * V_153 ;
struct V_38 * V_39 ;
T_2 V_128 = 0 ;
int V_132 = 0 ;
if ( ! F_49 ( V_37 , V_154 ) )
return - V_155 ;
if ( F_50 ( V_87 ) < sizeof( * V_153 ) )
return - V_11 ;
V_153 = F_31 ( V_87 ) ;
if ( V_153 -> V_89 != V_90 )
return - V_156 ;
if ( V_153 -> V_91 != V_110 )
return - V_11 ;
V_39 = F_51 ( V_79 , V_157 ) ;
if ( ! V_39 )
return - V_158 ;
V_39 -> V_63 = 0 ;
V_39 -> V_49 = 0 ;
V_39 -> V_45 = 0 ;
V_39 -> V_47 = V_153 -> V_47 ;
V_39 -> V_91 = V_153 -> V_91 ;
V_132 = F_42 ( V_87 , & V_39 -> V_52 , V_110 , & V_39 -> V_64 ,
& V_128 ) ;
if ( V_132 < 0 )
goto V_159;
V_132 = - V_152 ;
if ( ! V_39 -> V_64 . V_114 || ! V_39 -> V_64 . V_116 )
goto V_159;
V_39 -> V_3 . V_46 = F_52 ( & V_72 , V_39 -> V_64 . V_114 ) ;
if ( ! V_39 -> V_3 . V_46 )
goto V_159;
if ( V_39 -> V_3 . V_46 -> type != V_74 )
goto V_159;
V_39 -> V_2 . V_46 = F_52 ( & V_72 , V_39 -> V_64 . V_116 ) ;
if ( ! V_39 -> V_2 . V_46 )
goto V_159;
if ( V_39 -> V_2 . V_46 -> type != V_74 )
goto V_159;
V_39 -> V_55 = V_128 ;
F_25 () ;
V_132 = F_17 ( V_39 ) ;
if ( ! V_132 )
F_53 ( & V_39 -> V_78 , & V_160 ) ;
V_159:
if ( V_132 )
F_28 ( V_79 , V_39 ) ;
return V_132 ;
}
static void F_54 ( void )
{
struct V_38 * V_39 = NULL ;
struct V_76 * V_77 ;
F_25 () ;
F_26 (gwj, nx, &cgw_list, list) {
F_27 ( & V_39 -> V_78 ) ;
F_19 ( V_39 ) ;
F_28 ( V_79 , V_39 ) ;
}
}
static int F_55 ( struct V_36 * V_37 , struct V_86 * V_87 )
{
struct V_38 * V_39 = NULL ;
struct V_76 * V_77 ;
struct V_84 * V_153 ;
struct V_126 V_52 ;
struct V_151 V_64 ;
T_2 V_128 = 0 ;
int V_132 = 0 ;
if ( ! F_49 ( V_37 , V_154 ) )
return - V_155 ;
if ( F_50 ( V_87 ) < sizeof( * V_153 ) )
return - V_11 ;
V_153 = F_31 ( V_87 ) ;
if ( V_153 -> V_89 != V_90 )
return - V_156 ;
if ( V_153 -> V_91 != V_110 )
return - V_11 ;
V_132 = F_42 ( V_87 , & V_52 , V_110 , & V_64 , & V_128 ) ;
if ( V_132 < 0 )
return V_132 ;
if ( ! V_64 . V_114 && ! V_64 . V_116 ) {
F_54 () ;
return 0 ;
}
V_132 = - V_11 ;
F_25 () ;
F_26 (gwj, nx, &cgw_list, list) {
if ( V_39 -> V_47 != V_153 -> V_47 )
continue;
if ( V_39 -> V_55 != V_128 )
continue;
if ( memcmp ( & V_39 -> V_52 , & V_52 , sizeof( V_52 ) ) )
continue;
if ( memcmp ( & V_39 -> V_64 , & V_64 , sizeof( V_64 ) ) )
continue;
F_27 ( & V_39 -> V_78 ) ;
F_19 ( V_39 ) ;
F_28 ( V_79 , V_39 ) ;
V_132 = 0 ;
break;
}
return V_132 ;
}
static T_4 int F_56 ( void )
{
V_44 = F_57 (unsigned int, max_hops, CGW_MIN_HOPS, CGW_MAX_HOPS) ;
F_58 ( L_2 V_161 L_3 ,
V_44 ) ;
V_79 = F_59 ( L_4 , sizeof( struct V_38 ) ,
0 , 0 , NULL ) ;
if ( ! V_79 )
return - V_158 ;
V_162 . V_163 = F_21 ;
F_60 ( & V_162 ) ;
if ( F_61 ( V_164 , V_165 , NULL , F_37 , NULL ) ) {
F_62 ( & V_162 ) ;
F_63 ( V_79 ) ;
return - V_166 ;
}
F_61 ( V_164 , V_121 , F_48 , NULL , NULL ) ;
F_61 ( V_164 , V_167 , F_55 , NULL , NULL ) ;
return 0 ;
}
static T_5 void F_64 ( void )
{
F_65 ( V_164 ) ;
F_62 ( & V_162 ) ;
F_66 () ;
F_54 () ;
F_67 () ;
F_68 () ;
F_63 ( V_79 ) ;
}
