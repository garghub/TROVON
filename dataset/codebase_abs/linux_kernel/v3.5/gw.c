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
static int F_27 ( struct V_36 * V_37 , struct V_38 * V_39 )
{
struct V_72 V_73 ;
struct V_74 * V_75 ;
struct V_76 * V_77 = F_28 ( V_37 , 0 , 0 , 0 , sizeof( * V_75 ) , 0 ) ;
if ( ! V_77 )
return - V_78 ;
V_75 = F_29 ( V_77 ) ;
V_75 -> V_79 = V_80 ;
V_75 -> V_81 = V_39 -> V_81 ;
V_75 -> V_43 = V_39 -> V_43 ;
if ( V_39 -> V_56 ) {
if ( F_30 ( V_37 , V_82 , V_39 -> V_56 ) < 0 )
goto V_83;
else
V_77 -> V_84 += V_85 + F_31 ( sizeof( V_86 ) ) ;
}
if ( V_39 -> V_45 ) {
if ( F_30 ( V_37 , V_87 , V_39 -> V_45 ) < 0 )
goto V_83;
else
V_77 -> V_84 += V_85 + F_31 ( sizeof( V_86 ) ) ;
}
if ( V_39 -> V_46 . V_88 . V_89 ) {
memcpy ( & V_73 . V_14 , & V_39 -> V_46 . V_90 . V_89 , sizeof( V_73 . V_14 ) ) ;
V_73 . V_88 = V_39 -> V_46 . V_88 . V_89 ;
if ( F_32 ( V_37 , V_91 , sizeof( V_73 ) , & V_73 ) < 0 )
goto V_83;
else
V_77 -> V_84 += V_85 + F_31 ( sizeof( V_73 ) ) ;
}
if ( V_39 -> V_46 . V_88 . V_92 ) {
memcpy ( & V_73 . V_14 , & V_39 -> V_46 . V_90 . V_92 , sizeof( V_73 . V_14 ) ) ;
V_73 . V_88 = V_39 -> V_46 . V_88 . V_92 ;
if ( F_32 ( V_37 , V_93 , sizeof( V_73 ) , & V_73 ) < 0 )
goto V_83;
else
V_77 -> V_84 += V_85 + F_31 ( sizeof( V_73 ) ) ;
}
if ( V_39 -> V_46 . V_88 . V_16 ) {
memcpy ( & V_73 . V_14 , & V_39 -> V_46 . V_90 . V_16 , sizeof( V_73 . V_14 ) ) ;
V_73 . V_88 = V_39 -> V_46 . V_88 . V_16 ;
if ( F_32 ( V_37 , V_94 , sizeof( V_73 ) , & V_73 ) < 0 )
goto V_83;
else
V_77 -> V_84 += V_85 + F_31 ( sizeof( V_73 ) ) ;
}
if ( V_39 -> V_46 . V_88 . V_95 ) {
memcpy ( & V_73 . V_14 , & V_39 -> V_46 . V_90 . V_95 , sizeof( V_73 . V_14 ) ) ;
V_73 . V_88 = V_39 -> V_46 . V_88 . V_95 ;
if ( F_32 ( V_37 , V_96 , sizeof( V_73 ) , & V_73 ) < 0 )
goto V_83;
else
V_77 -> V_84 += V_85 + F_31 ( sizeof( V_73 ) ) ;
}
if ( V_39 -> V_46 . V_50 . V_26 ) {
if ( F_32 ( V_37 , V_97 , V_98 ,
& V_39 -> V_46 . V_51 . V_26 ) < 0 )
goto V_83;
else
V_77 -> V_84 += V_85 + \
F_31 ( V_98 ) ;
}
if ( V_39 -> V_46 . V_50 . V_16 ) {
if ( F_32 ( V_37 , V_99 , V_100 ,
& V_39 -> V_46 . V_51 . V_16 ) < 0 )
goto V_83;
else
V_77 -> V_84 += V_85 + \
F_31 ( V_100 ) ;
}
if ( V_39 -> V_81 == V_101 ) {
if ( V_39 -> V_57 . V_58 . V_4 || V_39 -> V_57 . V_58 . V_59 ) {
if ( F_32 ( V_37 , V_102 , sizeof( struct V_103 ) ,
& V_39 -> V_57 . V_58 ) < 0 )
goto V_83;
else
V_77 -> V_84 += V_85 +
F_31 ( sizeof( struct V_103 ) ) ;
}
if ( F_30 ( V_37 , V_104 , V_39 -> V_57 . V_105 ) < 0 )
goto V_83;
else
V_77 -> V_84 += V_85 + F_31 ( sizeof( V_86 ) ) ;
if ( F_30 ( V_37 , V_106 , V_39 -> V_57 . V_107 ) < 0 )
goto V_83;
else
V_77 -> V_84 += V_85 + F_31 ( sizeof( V_86 ) ) ;
}
return V_37 -> V_108 ;
V_83:
F_33 ( V_37 , V_77 ) ;
return - V_78 ;
}
static int F_34 ( struct V_36 * V_37 , struct V_109 * V_110 )
{
struct V_38 * V_39 = NULL ;
struct V_68 * V_69 ;
int V_12 = 0 ;
int V_111 = V_110 -> args [ 0 ] ;
F_35 () ;
F_36 (gwj, n, &cgw_list, list) {
if ( V_12 < V_111 )
goto V_112;
if ( F_27 ( V_37 , V_39 ) < 0 )
break;
V_112:
V_12 ++ ;
}
F_37 () ;
V_110 -> args [ 0 ] = V_12 ;
return V_37 -> V_108 ;
}
static int F_38 ( struct V_76 * V_77 , struct V_113 * V_46 ,
T_2 V_81 , void * V_114 )
{
struct V_115 * V_116 [ V_117 + 1 ] ;
struct V_72 V_73 ;
int V_41 = 0 ;
int V_118 = 0 ;
memset ( V_46 , 0 , sizeof( * V_46 ) ) ;
V_118 = F_39 ( V_77 , sizeof( struct V_74 ) , V_116 , V_117 , NULL ) ;
if ( V_118 < 0 )
return V_118 ;
if ( V_116 [ V_91 ] &&
F_40 ( V_116 [ V_91 ] ) == V_119 ) {
F_41 ( & V_73 , V_116 [ V_91 ] , V_119 ) ;
F_1 ( & V_46 -> V_90 . V_89 , & V_73 . V_14 ) ;
V_46 -> V_88 . V_89 = V_73 . V_88 ;
if ( V_73 . V_88 & V_120 )
V_46 -> V_47 [ V_41 ++ ] = V_121 ;
if ( V_73 . V_88 & V_122 )
V_46 -> V_47 [ V_41 ++ ] = V_123 ;
if ( V_73 . V_88 & V_124 )
V_46 -> V_47 [ V_41 ++ ] = V_125 ;
}
if ( V_116 [ V_93 ] &&
F_40 ( V_116 [ V_93 ] ) == V_119 ) {
F_41 ( & V_73 , V_116 [ V_93 ] , V_119 ) ;
F_1 ( & V_46 -> V_90 . V_92 , & V_73 . V_14 ) ;
V_46 -> V_88 . V_92 = V_73 . V_88 ;
if ( V_73 . V_88 & V_120 )
V_46 -> V_47 [ V_41 ++ ] = V_126 ;
if ( V_73 . V_88 & V_122 )
V_46 -> V_47 [ V_41 ++ ] = V_127 ;
if ( V_73 . V_88 & V_124 )
V_46 -> V_47 [ V_41 ++ ] = V_128 ;
}
if ( V_116 [ V_94 ] &&
F_40 ( V_116 [ V_94 ] ) == V_119 ) {
F_41 ( & V_73 , V_116 [ V_94 ] , V_119 ) ;
F_1 ( & V_46 -> V_90 . V_16 , & V_73 . V_14 ) ;
V_46 -> V_88 . V_16 = V_73 . V_88 ;
if ( V_73 . V_88 & V_120 )
V_46 -> V_47 [ V_41 ++ ] = V_129 ;
if ( V_73 . V_88 & V_122 )
V_46 -> V_47 [ V_41 ++ ] = V_130 ;
if ( V_73 . V_88 & V_124 )
V_46 -> V_47 [ V_41 ++ ] = V_131 ;
}
if ( V_116 [ V_96 ] &&
F_40 ( V_116 [ V_96 ] ) == V_119 ) {
F_41 ( & V_73 , V_116 [ V_96 ] , V_119 ) ;
F_1 ( & V_46 -> V_90 . V_95 , & V_73 . V_14 ) ;
V_46 -> V_88 . V_95 = V_73 . V_88 ;
if ( V_73 . V_88 & V_120 )
V_46 -> V_47 [ V_41 ++ ] = V_132 ;
if ( V_73 . V_88 & V_122 )
V_46 -> V_47 [ V_41 ++ ] = V_133 ;
if ( V_73 . V_88 & V_124 )
V_46 -> V_47 [ V_41 ++ ] = V_134 ;
}
if ( V_41 ) {
if ( V_116 [ V_97 ] &&
F_40 ( V_116 [ V_97 ] ) == V_98 ) {
struct V_25 * V_135 = (struct V_25 * )\
F_42 ( V_116 [ V_97 ] ) ;
V_118 = F_2 ( V_135 -> V_18 , V_135 -> V_19 ,
V_135 -> V_21 ) ;
if ( V_118 )
return V_118 ;
F_41 ( & V_46 -> V_51 . V_26 , V_116 [ V_97 ] ,
V_98 ) ;
if ( V_135 -> V_18 < 0 || V_135 -> V_19 < 0 ||
V_135 -> V_21 < 0 )
V_46 -> V_50 . V_26 = F_7 ;
else if ( V_135 -> V_18 <= V_135 -> V_19 )
V_46 -> V_50 . V_26 = F_8 ;
else
V_46 -> V_50 . V_26 = F_9 ;
}
if ( V_116 [ V_99 ] &&
F_40 ( V_116 [ V_99 ] ) == V_100 ) {
struct V_15 * V_135 = (struct V_15 * )\
F_42 ( V_116 [ V_99 ] ) ;
V_118 = F_2 ( V_135 -> V_18 , V_135 -> V_19 ,
V_135 -> V_21 ) ;
if ( V_118 )
return V_118 ;
F_41 ( & V_46 -> V_51 . V_16 , V_116 [ V_99 ] ,
V_100 ) ;
if ( V_135 -> V_18 < 0 || V_135 -> V_19 < 0 ||
V_135 -> V_21 < 0 )
V_46 -> V_50 . V_16 = F_4 ;
else if ( V_135 -> V_18 <= V_135 -> V_19 )
V_46 -> V_50 . V_16 = F_5 ;
else
V_46 -> V_50 . V_16 = F_6 ;
}
}
if ( V_81 == V_101 ) {
struct V_136 * V_57 = (struct V_136 * ) V_114 ;
memset ( V_57 , 0 , sizeof( * V_57 ) ) ;
if ( V_116 [ V_102 ] &&
F_40 ( V_116 [ V_102 ] ) == sizeof( struct V_103 ) )
F_41 ( & V_57 -> V_58 , V_116 [ V_102 ] ,
sizeof( struct V_103 ) ) ;
V_118 = - V_137 ;
if ( ! V_116 [ V_104 ] || ! V_116 [ V_106 ] )
return V_118 ;
if ( F_40 ( V_116 [ V_104 ] ) == sizeof( V_86 ) )
F_41 ( & V_57 -> V_105 , V_116 [ V_104 ] ,
sizeof( V_86 ) ) ;
if ( F_40 ( V_116 [ V_106 ] ) == sizeof( V_86 ) )
F_41 ( & V_57 -> V_107 , V_116 [ V_106 ] ,
sizeof( V_86 ) ) ;
if ( ! V_57 -> V_105 && ! V_57 -> V_107 )
return 0 ;
if ( ! V_57 -> V_105 || ! V_57 -> V_107 )
return V_118 ;
}
return 0 ;
}
static int F_43 ( struct V_36 * V_37 , struct V_76 * V_77 ,
void * V_138 )
{
struct V_74 * V_139 ;
struct V_38 * V_39 ;
int V_118 = 0 ;
if ( V_84 ( V_77 ) < sizeof( * V_139 ) )
return - V_11 ;
V_139 = F_29 ( V_77 ) ;
if ( V_139 -> V_79 != V_80 )
return - V_140 ;
if ( V_139 -> V_81 != V_101 )
return - V_11 ;
V_39 = F_44 ( V_141 , V_142 ) ;
if ( ! V_39 )
return - V_143 ;
V_39 -> V_56 = 0 ;
V_39 -> V_45 = 0 ;
V_39 -> V_43 = V_139 -> V_43 ;
V_39 -> V_81 = V_139 -> V_81 ;
V_118 = F_38 ( V_77 , & V_39 -> V_46 , V_101 , & V_39 -> V_57 ) ;
if ( V_118 < 0 )
goto V_144;
V_118 = - V_137 ;
if ( ! V_39 -> V_57 . V_105 || ! V_39 -> V_57 . V_107 )
goto V_144;
V_39 -> V_3 . V_42 = F_45 ( & V_64 , V_39 -> V_57 . V_105 ) ;
if ( ! V_39 -> V_3 . V_42 )
goto V_144;
if ( V_39 -> V_3 . V_42 -> type != V_66 || V_39 -> V_3 . V_42 -> V_145 )
goto V_146;
V_39 -> V_2 . V_42 = F_45 ( & V_64 , V_39 -> V_57 . V_107 ) ;
if ( ! V_39 -> V_2 . V_42 )
goto V_146;
if ( V_39 -> V_2 . V_42 -> type != V_66 || V_39 -> V_2 . V_42 -> V_145 )
goto V_147;
F_23 () ;
V_118 = F_16 ( V_39 ) ;
if ( ! V_118 )
F_46 ( & V_39 -> V_71 , & V_148 ) ;
V_147:
F_47 ( V_39 -> V_2 . V_42 ) ;
V_146:
F_47 ( V_39 -> V_3 . V_42 ) ;
V_144:
if ( V_118 )
F_48 ( V_141 , V_39 ) ;
return V_118 ;
}
static void F_49 ( void )
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
static int F_50 ( struct V_36 * V_37 , struct V_76 * V_77 , void * V_138 )
{
struct V_38 * V_39 = NULL ;
struct V_68 * V_69 , * V_70 ;
struct V_74 * V_139 ;
struct V_113 V_46 ;
struct V_136 V_57 ;
int V_118 = 0 ;
if ( V_84 ( V_77 ) < sizeof( * V_139 ) )
return - V_11 ;
V_139 = F_29 ( V_77 ) ;
if ( V_139 -> V_79 != V_80 )
return - V_140 ;
if ( V_139 -> V_81 != V_101 )
return - V_11 ;
V_118 = F_38 ( V_77 , & V_46 , V_101 , & V_57 ) ;
if ( V_118 < 0 )
return V_118 ;
if ( ! V_57 . V_105 && ! V_57 . V_107 ) {
F_49 () ;
return 0 ;
}
V_118 = - V_11 ;
F_23 () ;
F_24 (gwj, n, nx, &cgw_list, list) {
if ( V_39 -> V_43 != V_139 -> V_43 )
continue;
if ( memcmp ( & V_39 -> V_46 , & V_46 , sizeof( V_46 ) ) )
continue;
if ( memcmp ( & V_39 -> V_57 , & V_57 , sizeof( V_57 ) ) )
continue;
F_25 ( & V_39 -> V_71 ) ;
F_18 ( V_39 ) ;
F_26 ( V_39 ) ;
V_118 = 0 ;
break;
}
return V_118 ;
}
static T_3 int F_51 ( void )
{
F_52 ( V_149 ) ;
V_141 = F_53 ( L_2 , sizeof( struct V_38 ) ,
0 , 0 , NULL ) ;
if ( ! V_141 )
return - V_143 ;
V_150 . V_151 = F_20 ;
F_54 ( & V_150 ) ;
if ( F_55 ( V_152 , V_153 , NULL , F_34 , NULL ) ) {
F_56 ( & V_150 ) ;
F_57 ( V_141 ) ;
return - V_154 ;
}
F_55 ( V_152 , V_155 , F_43 , NULL , NULL ) ;
F_55 ( V_152 , V_156 , F_50 , NULL , NULL ) ;
return 0 ;
}
static T_4 void F_58 ( void )
{
F_59 ( V_152 ) ;
F_56 ( & V_150 ) ;
F_60 () ;
F_49 () ;
F_61 () ;
F_62 () ;
F_57 ( V_141 ) ;
}
