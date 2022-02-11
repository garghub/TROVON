static inline T_1 F_1 ( T_1 V_1 )
{
T_1 V_2 = V_1 & ~ 0x1 ;
return F_2 ( V_3 , V_2 >> 1 ) |
F_2 ( V_4 , 1 << ( V_1 - V_2 ) ) ;
}
static inline void F_3 ( struct V_5 * V_6 )
{
F_4 ( & V_6 -> V_7 ) ;
V_6 -> V_8 = 0 ;
}
static inline void F_5 ( struct V_9 * V_10 ,
struct V_5 * V_6 )
{
F_6 ( & V_10 -> V_7 ) ;
V_6 -> V_8 -- ;
}
static inline void F_7 ( struct V_9 * V_10 ,
struct V_5 * V_6 )
{
F_8 ( & V_10 -> V_7 , & V_6 -> V_7 ) ;
V_6 -> V_8 ++ ;
}
static inline struct V_9 * F_9 ( struct V_5 * V_6 )
{
struct V_9 * V_10 =
F_10 ( & V_6 -> V_7 , struct V_9 , V_7 ) ;
F_6 ( & V_10 -> V_7 ) ;
V_6 -> V_8 -- ;
return V_10 ;
}
static inline void F_11 ( struct V_9 * V_11 ,
struct V_5 * V_12 ,
struct V_5 * V_13 )
{
F_5 ( V_11 , V_12 ) ;
F_7 ( V_11 , V_13 ) ;
}
int F_12 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_19 * V_20 = V_17 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_22 ;
unsigned V_23 ;
int V_24 , V_25 = 0 ;
F_13 ( & V_17 -> V_26 ) ;
F_13 ( & V_17 -> V_27 ) ;
V_17 -> V_28 = V_29 ;
if ( ! V_20 -> V_30 || ! V_17 -> V_31 ) {
F_3 ( & V_20 -> V_32 ) ;
F_3 ( & V_20 -> V_33 ) ;
F_3 ( & V_20 -> V_34 ) ;
V_23 = V_20 -> V_35 ;
for ( V_24 = 0 ; V_24 < V_20 -> V_36 /
V_22 -> V_37 . V_38 ; V_24 ++ ) {
struct V_9 * V_10 ;
V_10 = F_14 ( sizeof( * V_10 ) , V_39 ) ;
if ( ! V_10 ) {
V_25 = - V_40 ;
goto V_41;
}
V_10 -> V_42 = V_22 -> V_37 . V_38 ;
V_10 -> V_43 = V_23 ;
F_7 ( V_10 , & V_20 -> V_32 ) ;
V_23 += V_22 -> V_37 . V_38 ;
}
}
V_17 -> V_44 = F_15 ( V_20 -> V_36 ,
sizeof( struct V_45 * ) ,
V_39 ) ;
if ( ! V_17 -> V_44 )
return - V_40 ;
if ( ! F_16 ( V_46 ) ) {
V_17 -> V_47 = 0 ;
V_17 -> V_48 = F_14 ( V_20 -> V_36 *
sizeof( T_1 ) , V_39 ) ;
if ( ! V_17 -> V_48 ) {
V_25 = - V_40 ;
goto V_41;
}
V_25 = F_17 ( & V_17 -> V_28 , & V_49 ) ;
if ( V_25 ) {
F_18 ( V_22 ,
L_1 ,
V_25 ) ;
F_19 ( V_46 ) ;
V_25 = 0 ;
}
}
F_20 ( & V_17 -> V_26 ) ;
if ( V_20 -> V_30 && ! F_16 ( V_46 ) ) {
T_2 V_50 ;
V_17 -> V_51 = V_20 -> V_36 / V_20 -> V_30 ;
V_50 = V_20 -> V_36 % V_20 -> V_30 ;
if ( V_50 && V_17 -> V_31 < V_50 )
V_17 -> V_51 ++ ;
} else {
V_17 -> V_51 = V_20 -> V_36 ;
}
F_21 ( & V_17 -> V_26 ) ;
V_41:
return V_25 ;
}
int F_22 ( struct V_16 * V_17 )
{
struct V_19 * V_20 = V_17 -> V_20 ;
struct V_9 * V_10 , * V_52 ;
if ( ! F_23 ( V_53 , & V_20 -> V_54 ) )
return 0 ;
if ( ! F_16 ( V_46 ) )
F_24 ( & V_17 -> V_28 ) ;
F_25 ( V_17 -> V_48 ) ;
if ( ! V_20 -> V_55 ) {
if ( ! F_26 ( V_20 -> V_34 ) )
F_27 ( V_20 , & V_20 -> V_34 ,
& V_17 -> V_28 ) ;
if ( ! F_26 ( V_20 -> V_33 ) )
F_27 ( V_20 , & V_20 -> V_33 ,
& V_17 -> V_28 ) ;
F_28 (grp, gptr, &uctxt->tid_group_list.list,
list) {
F_6 ( & V_10 -> V_7 ) ;
F_25 ( V_10 ) ;
}
F_29 ( V_20 ) ;
}
F_25 ( V_17 -> V_44 ) ;
return 0 ;
}
static inline void F_30 ( struct V_21 * V_22 , T_1 V_56 )
{
if ( ( V_22 -> V_57 & V_58 ) && V_22 -> V_59 )
F_31 ( 0 , V_22 -> V_59 + ( V_56 * 8 ) ) ;
}
int F_32 ( struct V_14 * V_15 , struct V_60 * V_61 )
{
int V_25 = 0 , V_62 = 0 , V_63 ;
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_19 * V_20 = V_17 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_22 ;
unsigned V_64 , V_65 , V_66 = 0 , V_67 , V_68 ,
V_69 = 0 , V_70 , V_71 = 0 ;
unsigned long V_72 = V_61 -> V_72 ;
struct V_73 * * V_74 = NULL ;
T_1 * V_75 = NULL ;
struct V_76 * V_77 = NULL ;
V_64 = F_33 ( V_72 , V_61 -> V_78 ) ;
if ( ! V_64 )
return - V_79 ;
if ( V_64 > V_20 -> V_36 ) {
F_34 ( V_22 , L_2 ) ;
return - V_79 ;
}
if ( ! F_35 ( V_80 , ( void V_81 * ) V_72 ,
V_64 * V_82 ) ) {
F_34 ( V_22 , L_3 ,
( void * ) V_72 , V_64 ) ;
return - V_83 ;
}
V_77 = F_15 ( V_20 -> V_36 , sizeof( * V_77 ) ,
V_39 ) ;
if ( ! V_77 )
return - V_40 ;
V_74 = F_15 ( V_64 , sizeof( * V_74 ) , V_39 ) ;
if ( ! V_74 ) {
V_25 = - V_40 ;
goto V_84;
}
if ( ! F_36 ( V_22 , V_17 -> V_85 , V_64 ) ) {
V_25 = - V_40 ;
goto V_84;
}
V_63 = F_37 ( V_72 , V_64 , true , V_74 ) ;
if ( V_63 <= 0 ) {
V_25 = V_63 ;
goto V_84;
}
V_17 -> V_85 += V_64 ;
V_68 = F_38 ( V_74 , V_63 , V_77 ) ;
F_20 ( & V_17 -> V_26 ) ;
if ( V_17 -> V_86 + V_68 > V_17 -> V_51 )
V_67 = V_17 -> V_51 - V_17 -> V_86 ;
else
V_67 = V_68 ;
F_21 ( & V_17 -> V_26 ) ;
if ( ! V_67 )
goto V_84;
V_65 = V_67 / V_22 -> V_37 . V_38 ;
V_75 = F_15 ( V_67 , sizeof( * V_75 ) , V_39 ) ;
if ( ! V_75 ) {
V_25 = - V_40 ;
goto V_87;
}
V_69 = 0 ;
F_39 ( & V_20 -> V_88 ) ;
while ( V_65 && V_20 -> V_32 . V_8 ) {
struct V_9 * V_10 =
F_9 ( & V_20 -> V_32 ) ;
V_25 = F_40 ( V_15 , V_72 , V_10 , V_77 ,
V_66 , V_22 -> V_37 . V_38 ,
V_74 , V_75 , & V_69 , & V_70 ) ;
if ( V_25 <= 0 ) {
F_7 ( V_10 , & V_20 -> V_32 ) ;
F_41 ( V_89 ,
L_4 , V_25 ) ;
goto V_90;
}
F_7 ( V_10 , & V_20 -> V_34 ) ;
V_65 -- ;
V_66 += V_25 ;
V_71 += V_70 ;
}
while ( V_66 < V_67 ) {
struct V_9 * V_10 , * V_91 ;
if ( ! V_20 -> V_33 . V_8 || V_62 ) {
if ( ! V_20 -> V_32 . V_8 )
goto V_90;
V_10 = F_9 ( & V_20 -> V_32 ) ;
F_7 ( V_10 , & V_20 -> V_33 ) ;
V_62 = 0 ;
}
F_28 (grp, ptr, &uctxt->tid_used_list.list,
list) {
unsigned V_92 = F_42 ( unsigned , V_67 - V_66 ,
V_10 -> V_42 - V_10 -> V_93 ) ;
V_25 = F_40 ( V_15 , V_72 , V_10 , V_77 ,
V_66 , V_92 , V_74 , V_75 ,
& V_69 , & V_70 ) ;
if ( V_25 < 0 ) {
F_41 ( V_89 ,
L_5 ,
V_25 ) ;
V_25 = - V_83 ;
goto V_90;
} else if ( V_25 > 0 ) {
if ( V_10 -> V_93 == V_10 -> V_42 )
F_11 ( V_10 ,
& V_20 -> V_33 ,
& V_20 -> V_34 ) ;
V_66 += V_25 ;
V_71 += V_70 ;
V_62 = 0 ;
if ( V_66 >= V_67 )
break;
} else if ( F_43 ( V_25 == 0 ) ) {
V_62 = 1 ;
}
}
}
V_90:
F_44 ( & V_20 -> V_88 ) ;
V_87:
F_41 ( V_89 , L_6 , V_69 ,
V_71 , V_25 ) ;
if ( V_69 ) {
F_20 ( & V_17 -> V_26 ) ;
V_17 -> V_86 += V_69 ;
F_21 ( & V_17 -> V_26 ) ;
V_61 -> V_94 = V_69 ;
V_61 -> V_78 = V_71 * V_82 ;
if ( F_45 ( ( void V_81 * ) ( unsigned long ) V_61 -> V_75 ,
V_75 , sizeof( V_75 [ 0 ] ) * V_69 ) ) {
V_61 -> V_75 = ( unsigned long ) & V_75 ;
F_46 ( V_15 , V_61 ) ;
V_61 -> V_75 = 0 ;
V_25 = - V_83 ;
goto V_84;
}
}
if ( V_71 != V_63 ) {
F_47 ( V_95 -> V_96 , & V_74 [ V_71 ] ,
V_63 - V_71 ,
false ) ;
V_17 -> V_85 -= V_63 - V_71 ;
}
V_84:
F_25 ( V_77 ) ;
F_25 ( V_74 ) ;
F_25 ( V_75 ) ;
return V_25 > 0 ? 0 : V_25 ;
}
int F_46 ( struct V_14 * V_15 , struct V_60 * V_61 )
{
int V_25 = 0 ;
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_19 * V_20 = V_17 -> V_20 ;
T_1 * V_97 ;
unsigned V_69 ;
V_97 = F_15 ( V_61 -> V_94 , sizeof( * V_97 ) , V_39 ) ;
if ( ! V_97 )
return - V_40 ;
if ( F_48 ( V_97 , ( void V_81 * ) ( unsigned long )
V_61 -> V_75 , sizeof( V_97 [ 0 ] ) *
V_61 -> V_94 ) ) {
V_25 = - V_83 ;
goto V_41;
}
F_39 ( & V_20 -> V_88 ) ;
for ( V_69 = 0 ; V_69 < V_61 -> V_94 ; V_69 ++ ) {
V_25 = F_49 ( V_15 , V_97 [ V_69 ] , NULL ) ;
if ( V_25 ) {
F_41 ( V_89 , L_7 ,
V_25 ) ;
break;
}
}
F_20 ( & V_17 -> V_26 ) ;
V_17 -> V_86 -= V_69 ;
F_21 ( & V_17 -> V_26 ) ;
V_61 -> V_94 = V_69 ;
F_44 ( & V_20 -> V_88 ) ;
V_41:
F_25 ( V_97 ) ;
return V_25 ;
}
int F_50 ( struct V_14 * V_15 , struct V_60 * V_61 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_19 * V_20 = V_17 -> V_20 ;
unsigned long * V_98 = V_20 -> V_22 -> V_99 +
( ( ( V_20 -> V_100 - V_20 -> V_22 -> V_101 ) *
V_102 ) + V_17 -> V_31 ) ;
T_1 * V_103 ;
int V_25 = 0 ;
if ( ! V_17 -> V_48 )
return - V_79 ;
V_103 = F_15 ( V_20 -> V_36 , sizeof( * V_103 ) , V_39 ) ;
if ( ! V_103 )
return - V_83 ;
F_20 ( & V_17 -> V_27 ) ;
if ( V_17 -> V_47 ) {
memcpy ( V_103 , V_17 -> V_48 , sizeof( * V_103 ) *
V_17 -> V_47 ) ;
memset ( V_17 -> V_48 , 0 , sizeof( * V_17 -> V_48 ) *
V_17 -> V_47 ) ;
V_61 -> V_94 = V_17 -> V_47 ;
V_17 -> V_47 = 0 ;
F_51 ( V_104 , V_98 ) ;
} else {
V_61 -> V_94 = 0 ;
}
F_21 ( & V_17 -> V_27 ) ;
if ( V_61 -> V_94 ) {
if ( F_45 ( ( void V_81 * ) V_61 -> V_75 ,
V_103 , sizeof( * V_103 ) * V_61 -> V_94 ) )
V_25 = - V_83 ;
}
F_25 ( V_103 ) ;
return V_25 ;
}
static T_1 F_38 ( struct V_73 * * V_74 , unsigned V_64 ,
struct V_76 * V_7 )
{
unsigned V_105 , V_66 , V_106 = 0 , V_24 ;
unsigned long V_107 , V_108 ;
if ( ! V_64 )
return 0 ;
V_107 = F_52 ( V_74 [ 0 ] ) ;
for ( V_66 = 0 , V_105 = 1 , V_24 = 1 ; V_24 <= V_64 ; V_24 ++ ) {
V_108 = V_24 < V_64 ? F_52 ( V_74 [ V_24 ] ) : 0 ;
if ( V_108 != ++ V_107 ) {
while ( V_105 ) {
int V_109 = V_105 ;
T_1 V_110 = V_105 * V_82 ;
if ( V_110 > V_111 )
V_109 =
V_111 >>
V_112 ;
else if ( ! F_53 ( V_110 ) )
V_109 =
F_54 ( V_110 ) >>
V_112 ;
V_7 [ V_106 ] . V_113 = V_66 ;
V_7 [ V_106 ] . V_8 = V_109 ;
V_105 -= V_109 ;
V_66 += V_109 ;
V_106 ++ ;
}
V_66 = V_24 ;
V_105 = 1 ;
V_107 = V_108 ;
} else {
V_105 ++ ;
}
}
return V_106 ;
}
static int F_40 ( struct V_14 * V_15 , unsigned long V_72 ,
struct V_9 * V_10 ,
struct V_76 * V_114 ,
unsigned V_115 , T_2 V_8 , struct V_73 * * V_74 ,
T_1 * V_75 , unsigned * V_69 , unsigned * V_116 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_19 * V_20 = V_17 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_22 ;
T_2 V_113 ;
T_1 V_97 = 0 , V_1 , V_117 = 0 ;
int V_70 = 0 ;
if ( V_8 > V_10 -> V_42 )
return - V_79 ;
for ( V_113 = 0 ; V_113 < V_10 -> V_42 ; V_113 ++ ) {
if ( ! ( V_10 -> V_118 & ( 1 << V_113 ) ) ) {
V_117 = V_113 ;
break;
}
F_30 ( V_22 , V_10 -> V_43 + V_113 ) ;
}
V_113 = 0 ;
while ( V_113 < V_8 ) {
T_2 V_64 , V_66 , V_119 = V_115 + V_113 ;
int V_25 = 0 ;
if ( V_117 >= V_10 -> V_42 ) {
break;
} else if ( V_10 -> V_118 & ( 1 << V_117 ) ) {
F_30 ( V_22 , V_10 -> V_43 + V_117 ) ;
V_117 ++ ;
continue;
}
V_1 = V_10 -> V_43 + V_117 ;
V_64 = V_114 [ V_119 ] . V_8 ;
V_66 = V_114 [ V_119 ] . V_113 ;
V_25 = F_55 ( V_15 , V_72 + ( V_66 * V_82 ) ,
V_1 , V_10 , V_74 + V_66 ,
V_64 ) ;
if ( V_25 )
return V_25 ;
V_70 += V_64 ;
V_97 = F_1 ( V_1 - V_20 -> V_35 ) |
F_2 ( V_120 , V_64 ) ;
V_75 [ ( * V_69 ) ++ ] = V_97 ;
V_10 -> V_93 ++ ;
V_10 -> V_118 |= 1 << V_117 ++ ;
V_113 ++ ;
}
for (; V_117 < V_10 -> V_42 ; V_117 ++ )
F_30 ( V_22 , V_10 -> V_43 + V_117 ) ;
* V_116 = V_70 ;
return V_113 ;
}
static int F_55 ( struct V_14 * V_15 , unsigned long V_72 ,
T_1 V_1 , struct V_9 * V_10 ,
struct V_73 * * V_74 , unsigned V_64 )
{
int V_25 ;
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_19 * V_20 = V_17 -> V_20 ;
struct V_121 * V_122 ;
struct V_21 * V_22 = V_20 -> V_22 ;
struct V_123 * V_124 = & V_17 -> V_28 ;
T_3 V_125 ;
V_122 = F_14 ( sizeof( * V_122 ) + ( sizeof( struct V_73 * ) * V_64 ) ,
V_39 ) ;
if ( ! V_122 )
return - V_40 ;
V_125 = F_56 ( V_22 -> V_126 ,
F_57 ( F_58 ( V_74 [ 0 ] ) ) ,
V_64 * V_82 , V_127 ) ;
if ( F_59 ( & V_22 -> V_126 -> V_128 , V_125 ) ) {
F_34 ( V_22 , L_8 ,
V_125 ) ;
F_25 ( V_122 ) ;
return - V_83 ;
}
V_122 -> V_129 . V_130 = V_72 ;
V_122 -> V_129 . V_131 = V_64 * V_82 ;
V_122 -> V_125 = F_58 ( V_74 [ 0 ] ) ;
V_122 -> V_64 = V_64 ;
V_122 -> V_1 = V_1 ;
V_122 -> V_132 = V_125 ;
V_122 -> V_10 = V_10 ;
V_122 -> V_133 = false ;
memcpy ( V_122 -> V_74 , V_74 , sizeof( struct V_73 * ) * V_64 ) ;
if ( F_16 ( V_46 ) )
V_25 = F_60 ( V_124 , & V_122 -> V_129 ) ;
else
V_25 = F_61 ( V_124 , & V_122 -> V_129 ) ;
if ( V_25 ) {
F_41 ( V_89 , L_9 ,
V_122 -> V_1 , V_122 -> V_129 . V_130 , V_122 -> V_125 , V_25 ) ;
F_62 ( V_22 -> V_126 , V_125 , V_64 * V_82 ,
V_127 ) ;
F_25 ( V_122 ) ;
return - V_83 ;
}
F_63 ( V_22 , V_1 , V_134 , V_125 , F_64 ( V_64 ) + 1 ) ;
F_65 ( V_20 -> V_100 , V_17 -> V_31 , V_1 , V_64 ,
V_122 -> V_129 . V_130 , V_122 -> V_125 , V_125 ) ;
return 0 ;
}
static int F_49 ( struct V_14 * V_15 , T_1 V_97 ,
struct V_9 * * V_10 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_19 * V_20 = V_17 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_22 ;
struct V_121 * V_122 ;
T_4 V_135 = F_66 ( V_97 , V_4 ) ;
T_1 V_69 = F_66 ( V_97 , V_3 ) << 1 , V_1 ;
if ( V_69 >= V_20 -> V_36 ) {
F_34 ( V_22 , L_10 ,
V_69 , V_20 -> V_100 ) ;
return - V_79 ;
}
if ( V_135 == 0x3 )
return - V_79 ;
V_1 = V_69 + ( V_135 - 1 ) ;
V_122 = V_17 -> V_44 [ V_1 ] ;
if ( ! V_122 || V_122 -> V_1 != ( V_20 -> V_35 + V_1 ) )
return - V_136 ;
if ( F_16 ( V_46 ) )
F_67 ( & V_17 -> V_28 , & V_122 -> V_129 , NULL ) ;
else
F_68 ( & V_17 -> V_28 , & V_122 -> V_129 ) ;
if ( V_10 )
* V_10 = V_122 -> V_10 ;
F_69 ( V_17 , V_17 -> V_31 , V_122 ) ;
return 0 ;
}
static void F_69 ( struct V_16 * V_17 , T_2 V_31 ,
struct V_121 * V_122 )
{
struct V_19 * V_20 = V_17 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_22 ;
F_70 ( V_20 -> V_100 , V_17 -> V_31 , V_122 -> V_1 ,
V_122 -> V_64 , V_122 -> V_129 . V_130 , V_122 -> V_125 ,
V_122 -> V_132 ) ;
F_63 ( V_22 , V_122 -> V_1 , V_137 , 0 , 0 ) ;
F_71 () ;
F_62 ( V_22 -> V_126 , V_122 -> V_132 , V_122 -> V_129 . V_131 ,
V_127 ) ;
F_47 ( V_95 -> V_96 , V_122 -> V_74 , V_122 -> V_64 , true ) ;
V_17 -> V_85 -= V_122 -> V_64 ;
V_122 -> V_10 -> V_93 -- ;
V_122 -> V_10 -> V_118 &= ~ ( 1 << ( V_122 -> V_1 - V_122 -> V_10 -> V_43 ) ) ;
if ( V_122 -> V_10 -> V_93 == V_122 -> V_10 -> V_42 - 1 )
F_11 ( V_122 -> V_10 , & V_20 -> V_34 ,
& V_20 -> V_33 ) ;
else if ( ! V_122 -> V_10 -> V_93 )
F_11 ( V_122 -> V_10 , & V_20 -> V_33 ,
& V_20 -> V_32 ) ;
F_25 ( V_122 ) ;
}
static void F_27 ( struct V_19 * V_20 ,
struct V_5 * V_6 , struct V_123 * V_124 )
{
struct V_9 * V_10 , * V_91 ;
struct V_16 * V_17 = F_72 ( V_124 , struct V_16 ,
V_28 ) ;
int V_24 ;
F_28 (grp, ptr, &set->list, list) {
F_6 ( & V_10 -> V_7 ) ;
for ( V_24 = 0 ; V_24 < V_10 -> V_42 ; V_24 ++ ) {
if ( V_10 -> V_118 & ( 1 << V_24 ) ) {
T_2 V_1 = V_10 -> V_43 + V_24 ;
struct V_121 * V_122 ;
V_122 = V_17 -> V_44 [ V_1 -
V_20 -> V_35 ] ;
if ( ! V_122 || V_122 -> V_1 != V_1 )
continue;
if ( F_16 ( V_46 ) )
F_67 ( & V_17 -> V_28 ,
& V_122 -> V_129 , NULL ) ;
else
F_68 ( & V_17 -> V_28 ,
& V_122 -> V_129 ) ;
F_69 ( V_17 , - 1 , V_122 ) ;
}
}
}
}
static int F_73 ( struct V_123 * V_124 , struct V_138 * V_139 )
{
struct V_16 * V_140 =
F_72 ( V_124 , struct V_16 , V_28 ) ;
struct V_19 * V_20 = V_140 -> V_20 ;
struct V_121 * V_122 =
F_72 ( V_139 , struct V_121 , V_129 ) ;
if ( V_122 -> V_133 )
return 0 ;
F_74 ( V_20 -> V_100 , V_140 -> V_31 , V_122 -> V_129 . V_130 ,
V_122 -> V_1 , V_122 -> V_64 , V_122 -> V_132 ) ;
V_122 -> V_133 = true ;
F_20 ( & V_140 -> V_27 ) ;
if ( V_140 -> V_47 < V_20 -> V_36 ) {
V_140 -> V_48 [ V_140 -> V_47 ] =
F_1 ( V_122 -> V_1 - V_20 -> V_35 ) ;
V_140 -> V_48 [ V_140 -> V_47 ] |=
F_2 ( V_120 , V_122 -> V_64 ) ;
if ( ! V_140 -> V_47 ) {
unsigned long * V_98 ;
V_98 = V_20 -> V_22 -> V_99 +
( ( ( V_20 -> V_100 - V_20 -> V_22 -> V_101 ) *
V_102 ) + V_140 -> V_31 ) ;
F_75 ( V_104 , V_98 ) ;
}
V_140 -> V_47 ++ ;
}
F_21 ( & V_140 -> V_27 ) ;
return 0 ;
}
static int F_60 ( struct V_123 * V_124 , struct V_138 * V_122 )
{
struct V_16 * V_140 =
F_72 ( V_124 , struct V_16 , V_28 ) ;
struct V_121 * V_141 =
F_72 ( V_122 , struct V_121 , V_129 ) ;
T_1 V_43 = V_140 -> V_20 -> V_35 ;
V_140 -> V_44 [ V_141 -> V_1 - V_43 ] = V_141 ;
return 0 ;
}
static void F_67 ( struct V_123 * V_124 , struct V_138 * V_122 ,
struct V_142 * V_96 )
{
struct V_16 * V_140 =
F_72 ( V_124 , struct V_16 , V_28 ) ;
struct V_121 * V_141 =
F_72 ( V_122 , struct V_121 , V_129 ) ;
T_1 V_43 = V_140 -> V_20 -> V_35 ;
V_140 -> V_44 [ V_141 -> V_1 - V_43 ] = NULL ;
}
