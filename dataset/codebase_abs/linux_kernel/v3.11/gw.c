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
if ( V_39 -> V_52 . V_95 . V_96 ) {
memcpy ( & V_82 . V_14 , & V_39 -> V_52 . V_97 . V_96 , sizeof( V_82 . V_14 ) ) ;
V_82 . V_95 = V_39 -> V_52 . V_95 . V_96 ;
if ( F_33 ( V_37 , V_98 , sizeof( V_82 ) , & V_82 ) < 0 )
goto V_92;
}
if ( V_39 -> V_52 . V_95 . V_99 ) {
memcpy ( & V_82 . V_14 , & V_39 -> V_52 . V_97 . V_99 , sizeof( V_82 . V_14 ) ) ;
V_82 . V_95 = V_39 -> V_52 . V_95 . V_99 ;
if ( F_33 ( V_37 , V_100 , sizeof( V_82 ) , & V_82 ) < 0 )
goto V_92;
}
if ( V_39 -> V_52 . V_95 . V_16 ) {
memcpy ( & V_82 . V_14 , & V_39 -> V_52 . V_97 . V_16 , sizeof( V_82 . V_14 ) ) ;
V_82 . V_95 = V_39 -> V_52 . V_95 . V_16 ;
if ( F_33 ( V_37 , V_101 , sizeof( V_82 ) , & V_82 ) < 0 )
goto V_92;
}
if ( V_39 -> V_52 . V_95 . V_102 ) {
memcpy ( & V_82 . V_14 , & V_39 -> V_52 . V_97 . V_102 , sizeof( V_82 . V_14 ) ) ;
V_82 . V_95 = V_39 -> V_52 . V_95 . V_102 ;
if ( F_33 ( V_37 , V_103 , sizeof( V_82 ) , & V_82 ) < 0 )
goto V_92;
}
if ( V_39 -> V_52 . V_56 . V_26 ) {
if ( F_33 ( V_37 , V_104 , V_105 ,
& V_39 -> V_52 . V_57 . V_26 ) < 0 )
goto V_92;
}
if ( V_39 -> V_52 . V_56 . V_16 ) {
if ( F_33 ( V_37 , V_106 , V_107 ,
& V_39 -> V_52 . V_57 . V_16 ) < 0 )
goto V_92;
}
if ( V_39 -> V_90 == V_108 ) {
if ( V_39 -> V_63 . V_64 . V_4 || V_39 -> V_63 . V_64 . V_65 ) {
if ( F_33 ( V_37 , V_109 , sizeof( struct V_110 ) ,
& V_39 -> V_63 . V_64 ) < 0 )
goto V_92;
}
if ( F_32 ( V_37 , V_111 , V_39 -> V_63 . V_112 ) < 0 )
goto V_92;
if ( F_32 ( V_37 , V_113 , V_39 -> V_63 . V_114 ) < 0 )
goto V_92;
}
return F_34 ( V_37 , V_86 ) ;
V_92:
F_35 ( V_37 , V_86 ) ;
return - V_87 ;
}
static int F_36 ( struct V_36 * V_37 , struct V_115 * V_116 )
{
struct V_38 * V_39 = NULL ;
int V_12 = 0 ;
int V_117 = V_116 -> args [ 0 ] ;
F_37 () ;
F_38 (gwj, &cgw_list, list) {
if ( V_12 < V_117 )
goto V_118;
if ( F_29 ( V_37 , V_39 , V_119 , F_39 ( V_116 -> V_37 ) . V_120 ,
V_116 -> V_86 -> V_121 , V_122 ) < 0 )
break;
V_118:
V_12 ++ ;
}
F_40 () ;
V_116 -> args [ 0 ] = V_12 ;
return V_37 -> V_123 ;
}
static int F_41 ( struct V_85 * V_86 , struct V_124 * V_52 ,
T_2 V_90 , void * V_125 )
{
struct V_126 * V_127 [ V_128 + 1 ] ;
struct V_81 V_82 ;
int V_41 = 0 ;
int V_129 = 0 ;
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
V_129 = F_42 ( V_86 , sizeof( struct V_83 ) , V_127 , V_128 ,
V_130 ) ;
if ( V_129 < 0 )
return V_129 ;
if ( V_127 [ V_98 ] ) {
F_43 ( & V_82 , V_127 [ V_98 ] , V_131 ) ;
F_1 ( & V_52 -> V_97 . V_96 , & V_82 . V_14 ) ;
V_52 -> V_95 . V_96 = V_82 . V_95 ;
if ( V_82 . V_95 & V_132 )
V_52 -> V_53 [ V_41 ++ ] = V_133 ;
if ( V_82 . V_95 & V_134 )
V_52 -> V_53 [ V_41 ++ ] = V_135 ;
if ( V_82 . V_95 & V_136 )
V_52 -> V_53 [ V_41 ++ ] = V_137 ;
}
if ( V_127 [ V_100 ] ) {
F_43 ( & V_82 , V_127 [ V_100 ] , V_131 ) ;
F_1 ( & V_52 -> V_97 . V_99 , & V_82 . V_14 ) ;
V_52 -> V_95 . V_99 = V_82 . V_95 ;
if ( V_82 . V_95 & V_132 )
V_52 -> V_53 [ V_41 ++ ] = V_138 ;
if ( V_82 . V_95 & V_134 )
V_52 -> V_53 [ V_41 ++ ] = V_139 ;
if ( V_82 . V_95 & V_136 )
V_52 -> V_53 [ V_41 ++ ] = V_140 ;
}
if ( V_127 [ V_101 ] ) {
F_43 ( & V_82 , V_127 [ V_101 ] , V_131 ) ;
F_1 ( & V_52 -> V_97 . V_16 , & V_82 . V_14 ) ;
V_52 -> V_95 . V_16 = V_82 . V_95 ;
if ( V_82 . V_95 & V_132 )
V_52 -> V_53 [ V_41 ++ ] = V_141 ;
if ( V_82 . V_95 & V_134 )
V_52 -> V_53 [ V_41 ++ ] = V_142 ;
if ( V_82 . V_95 & V_136 )
V_52 -> V_53 [ V_41 ++ ] = V_143 ;
}
if ( V_127 [ V_103 ] ) {
F_43 ( & V_82 , V_127 [ V_103 ] , V_131 ) ;
F_1 ( & V_52 -> V_97 . V_102 , & V_82 . V_14 ) ;
V_52 -> V_95 . V_102 = V_82 . V_95 ;
if ( V_82 . V_95 & V_132 )
V_52 -> V_53 [ V_41 ++ ] = V_144 ;
if ( V_82 . V_95 & V_134 )
V_52 -> V_53 [ V_41 ++ ] = V_145 ;
if ( V_82 . V_95 & V_136 )
V_52 -> V_53 [ V_41 ++ ] = V_146 ;
}
if ( V_41 ) {
if ( V_127 [ V_104 ] ) {
struct V_25 * V_147 = F_44 ( V_127 [ V_104 ] ) ;
V_129 = F_2 ( V_147 -> V_18 , V_147 -> V_19 ,
V_147 -> V_21 ) ;
if ( V_129 )
return V_129 ;
F_43 ( & V_52 -> V_57 . V_26 , V_127 [ V_104 ] ,
V_105 ) ;
if ( V_147 -> V_18 < 0 || V_147 -> V_19 < 0 ||
V_147 -> V_21 < 0 )
V_52 -> V_56 . V_26 = F_7 ;
else if ( V_147 -> V_18 <= V_147 -> V_19 )
V_52 -> V_56 . V_26 = F_8 ;
else
V_52 -> V_56 . V_26 = F_9 ;
}
if ( V_127 [ V_106 ] ) {
struct V_15 * V_147 = F_44 ( V_127 [ V_106 ] ) ;
V_129 = F_2 ( V_147 -> V_18 , V_147 -> V_19 ,
V_147 -> V_21 ) ;
if ( V_129 )
return V_129 ;
F_43 ( & V_52 -> V_57 . V_16 , V_127 [ V_106 ] ,
V_107 ) ;
if ( V_147 -> V_18 < 0 || V_147 -> V_19 < 0 ||
V_147 -> V_21 < 0 )
V_52 -> V_56 . V_16 = F_4 ;
else if ( V_147 -> V_18 <= V_147 -> V_19 )
V_52 -> V_56 . V_16 = F_5 ;
else
V_52 -> V_56 . V_16 = F_6 ;
}
}
if ( V_90 == V_108 ) {
struct V_148 * V_63 = (struct V_148 * ) V_125 ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
if ( V_127 [ V_109 ] )
F_43 ( & V_63 -> V_64 , V_127 [ V_109 ] ,
sizeof( struct V_110 ) ) ;
V_129 = - V_149 ;
if ( ! V_127 [ V_111 ] || ! V_127 [ V_113 ] )
return V_129 ;
V_63 -> V_112 = F_45 ( V_127 [ V_111 ] ) ;
V_63 -> V_114 = F_45 ( V_127 [ V_113 ] ) ;
if ( ! V_63 -> V_112 && ! V_63 -> V_114 )
return 0 ;
if ( ! V_63 -> V_112 || ! V_63 -> V_114 )
return V_129 ;
}
return 0 ;
}
static int F_46 ( struct V_36 * V_37 , struct V_85 * V_86 )
{
struct V_83 * V_150 ;
struct V_38 * V_39 ;
int V_129 = 0 ;
if ( ! F_47 ( V_151 ) )
return - V_152 ;
if ( F_48 ( V_86 ) < sizeof( * V_150 ) )
return - V_11 ;
V_150 = F_31 ( V_86 ) ;
if ( V_150 -> V_88 != V_89 )
return - V_153 ;
if ( V_150 -> V_90 != V_108 )
return - V_11 ;
V_39 = F_49 ( V_78 , V_154 ) ;
if ( ! V_39 )
return - V_155 ;
V_39 -> V_62 = 0 ;
V_39 -> V_49 = 0 ;
V_39 -> V_45 = 0 ;
V_39 -> V_47 = V_150 -> V_47 ;
V_39 -> V_90 = V_150 -> V_90 ;
V_129 = F_41 ( V_86 , & V_39 -> V_52 , V_108 , & V_39 -> V_63 ) ;
if ( V_129 < 0 )
goto V_156;
V_129 = - V_149 ;
if ( ! V_39 -> V_63 . V_112 || ! V_39 -> V_63 . V_114 )
goto V_156;
V_39 -> V_3 . V_46 = F_50 ( & V_71 , V_39 -> V_63 . V_112 ) ;
if ( ! V_39 -> V_3 . V_46 )
goto V_156;
if ( V_39 -> V_3 . V_46 -> type != V_73 || V_39 -> V_3 . V_46 -> V_157 )
goto V_158;
V_39 -> V_2 . V_46 = F_50 ( & V_71 , V_39 -> V_63 . V_114 ) ;
if ( ! V_39 -> V_2 . V_46 )
goto V_158;
if ( V_39 -> V_2 . V_46 -> type != V_73 || V_39 -> V_2 . V_46 -> V_157 )
goto V_159;
F_25 () ;
V_129 = F_17 ( V_39 ) ;
if ( ! V_129 )
F_51 ( & V_39 -> V_77 , & V_160 ) ;
V_159:
F_52 ( V_39 -> V_2 . V_46 ) ;
V_158:
F_52 ( V_39 -> V_3 . V_46 ) ;
V_156:
if ( V_129 )
F_28 ( V_78 , V_39 ) ;
return V_129 ;
}
static void F_53 ( void )
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
static int F_54 ( struct V_36 * V_37 , struct V_85 * V_86 )
{
struct V_38 * V_39 = NULL ;
struct V_75 * V_76 ;
struct V_83 * V_150 ;
struct V_124 V_52 ;
struct V_148 V_63 ;
int V_129 = 0 ;
if ( ! F_47 ( V_151 ) )
return - V_152 ;
if ( F_48 ( V_86 ) < sizeof( * V_150 ) )
return - V_11 ;
V_150 = F_31 ( V_86 ) ;
if ( V_150 -> V_88 != V_89 )
return - V_153 ;
if ( V_150 -> V_90 != V_108 )
return - V_11 ;
V_129 = F_41 ( V_86 , & V_52 , V_108 , & V_63 ) ;
if ( V_129 < 0 )
return V_129 ;
if ( ! V_63 . V_112 && ! V_63 . V_114 ) {
F_53 () ;
return 0 ;
}
V_129 = - V_11 ;
F_25 () ;
F_26 (gwj, nx, &cgw_list, list) {
if ( V_39 -> V_47 != V_150 -> V_47 )
continue;
if ( memcmp ( & V_39 -> V_52 , & V_52 , sizeof( V_52 ) ) )
continue;
if ( memcmp ( & V_39 -> V_63 , & V_63 , sizeof( V_63 ) ) )
continue;
F_27 ( & V_39 -> V_77 ) ;
F_19 ( V_39 ) ;
F_28 ( V_78 , V_39 ) ;
V_129 = 0 ;
break;
}
return V_129 ;
}
static T_4 int F_55 ( void )
{
V_44 = F_56 (unsigned int, max_hops, CGW_MIN_HOPS, CGW_MAX_HOPS) ;
F_57 ( L_2 V_161 L_3 ,
V_44 ) ;
V_78 = F_58 ( L_4 , sizeof( struct V_38 ) ,
0 , 0 , NULL ) ;
if ( ! V_78 )
return - V_155 ;
V_162 . V_163 = F_21 ;
F_59 ( & V_162 ) ;
if ( F_60 ( V_164 , V_165 , NULL , F_36 , NULL ) ) {
F_61 ( & V_162 ) ;
F_62 ( V_78 ) ;
return - V_166 ;
}
F_60 ( V_164 , V_119 , F_46 , NULL , NULL ) ;
F_60 ( V_164 , V_167 , F_54 , NULL , NULL ) ;
return 0 ;
}
static T_5 void F_63 ( void )
{
F_64 ( V_164 ) ;
F_61 ( & V_162 ) ;
F_65 () ;
F_53 () ;
F_66 () ;
F_67 () ;
F_62 ( V_78 ) ;
}
