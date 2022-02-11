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
if ( ! V_20 -> V_28 || ! V_17 -> V_29 ) {
F_3 ( & V_20 -> V_30 ) ;
F_3 ( & V_20 -> V_31 ) ;
F_3 ( & V_20 -> V_32 ) ;
V_23 = V_20 -> V_33 ;
for ( V_24 = 0 ; V_24 < V_20 -> V_34 /
V_22 -> V_35 . V_36 ; V_24 ++ ) {
struct V_9 * V_10 ;
V_10 = F_14 ( sizeof( * V_10 ) , V_37 ) ;
if ( ! V_10 ) {
V_25 = - V_38 ;
goto V_39;
}
V_10 -> V_40 = V_22 -> V_35 . V_36 ;
V_10 -> V_41 = V_23 ;
F_7 ( V_10 , & V_20 -> V_30 ) ;
V_23 += V_22 -> V_35 . V_36 ;
}
}
V_17 -> V_42 = F_15 ( V_20 -> V_34 ,
sizeof( struct V_43 * ) ,
V_37 ) ;
if ( ! V_17 -> V_42 )
return - V_38 ;
if ( ! F_16 ( V_20 -> V_44 , V_45 ) ) {
V_17 -> V_46 = 0 ;
V_17 -> V_47 = F_14 ( V_20 -> V_34 *
sizeof( T_1 ) , V_37 ) ;
if ( ! V_17 -> V_47 ) {
V_25 = - V_38 ;
goto V_39;
}
V_25 = F_17 ( V_17 , V_17 -> V_48 , & V_49 ,
V_22 -> V_50 -> V_51 ,
& V_17 -> V_52 ) ;
if ( V_25 ) {
F_18 ( V_22 ,
L_1 ,
V_25 ) ;
V_25 = 0 ;
}
}
F_19 ( & V_17 -> V_26 ) ;
if ( V_20 -> V_28 && V_17 -> V_52 ) {
T_2 V_53 ;
V_17 -> V_54 = V_20 -> V_34 / V_20 -> V_28 ;
V_53 = V_20 -> V_34 % V_20 -> V_28 ;
if ( V_53 && V_17 -> V_29 < V_53 )
V_17 -> V_54 ++ ;
} else {
V_17 -> V_54 = V_20 -> V_34 ;
}
F_20 ( & V_17 -> V_26 ) ;
V_39:
return V_25 ;
}
int F_21 ( struct V_16 * V_17 )
{
struct V_19 * V_20 = V_17 -> V_20 ;
struct V_9 * V_10 , * V_55 ;
if ( ! F_22 ( V_56 , & V_20 -> V_57 ) )
return 0 ;
if ( V_17 -> V_52 )
F_23 ( V_17 -> V_52 ) ;
F_24 ( V_17 -> V_47 ) ;
if ( ! V_20 -> V_58 ) {
if ( ! F_25 ( V_20 -> V_32 ) )
F_26 ( V_20 , & V_20 -> V_32 , V_17 ) ;
if ( ! F_25 ( V_20 -> V_31 ) )
F_26 ( V_20 , & V_20 -> V_31 , V_17 ) ;
F_27 (grp, gptr, &uctxt->tid_group_list.list,
list) {
F_6 ( & V_10 -> V_7 ) ;
F_24 ( V_10 ) ;
}
F_28 ( V_20 ) ;
}
F_24 ( V_17 -> V_42 ) ;
return 0 ;
}
static inline void F_29 ( struct V_21 * V_22 , T_1 V_59 )
{
if ( ( V_22 -> V_44 & V_60 ) && V_22 -> V_61 )
F_30 ( 0 , V_22 -> V_61 + ( V_59 * 8 ) ) ;
}
int F_31 ( struct V_14 * V_15 , struct V_62 * V_63 )
{
int V_25 = 0 , V_64 = 0 , V_65 ;
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_19 * V_20 = V_17 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_22 ;
unsigned V_66 , V_67 , V_68 = 0 , V_69 , V_70 ,
V_71 = 0 , V_72 , V_73 = 0 ;
unsigned long V_74 = V_63 -> V_74 ;
struct V_75 * * V_76 = NULL ;
T_1 * V_77 = NULL ;
struct V_78 * V_79 = NULL ;
V_66 = F_32 ( V_74 , V_63 -> V_80 ) ;
if ( ! V_66 )
return - V_81 ;
if ( V_66 > V_20 -> V_34 ) {
F_33 ( V_22 , L_2 ) ;
return - V_81 ;
}
if ( ! F_34 ( V_82 , ( void V_83 * ) V_74 ,
V_66 * V_84 ) ) {
F_33 ( V_22 , L_3 ,
( void * ) V_74 , V_66 ) ;
return - V_85 ;
}
V_79 = F_15 ( V_20 -> V_34 , sizeof( * V_79 ) ,
V_37 ) ;
if ( ! V_79 )
return - V_38 ;
V_76 = F_15 ( V_66 , sizeof( * V_76 ) , V_37 ) ;
if ( ! V_76 ) {
V_25 = - V_38 ;
goto V_86;
}
if ( ! F_35 ( V_22 , V_17 -> V_48 , V_17 -> V_87 , V_66 ) ) {
V_25 = - V_38 ;
goto V_86;
}
V_65 = F_36 ( V_17 -> V_48 , V_74 , V_66 , true , V_76 ) ;
if ( V_65 <= 0 ) {
V_25 = V_65 ;
goto V_86;
}
V_17 -> V_87 += V_66 ;
V_70 = F_37 ( V_76 , V_65 , V_79 ) ;
F_19 ( & V_17 -> V_26 ) ;
if ( V_17 -> V_88 + V_70 > V_17 -> V_54 )
V_69 = V_17 -> V_54 - V_17 -> V_88 ;
else
V_69 = V_70 ;
F_20 ( & V_17 -> V_26 ) ;
if ( ! V_69 )
goto V_86;
V_67 = V_69 / V_22 -> V_35 . V_36 ;
V_77 = F_15 ( V_69 , sizeof( * V_77 ) , V_37 ) ;
if ( ! V_77 ) {
V_25 = - V_38 ;
goto V_89;
}
V_71 = 0 ;
F_38 ( & V_20 -> V_90 ) ;
while ( V_67 && V_20 -> V_30 . V_8 ) {
struct V_9 * V_10 =
F_9 ( & V_20 -> V_30 ) ;
V_25 = F_39 ( V_15 , V_74 , V_10 , V_79 ,
V_68 , V_22 -> V_35 . V_36 ,
V_76 , V_77 , & V_71 , & V_72 ) ;
if ( V_25 <= 0 ) {
F_7 ( V_10 , & V_20 -> V_30 ) ;
F_40 ( V_91 ,
L_4 , V_25 ) ;
goto V_92;
}
F_7 ( V_10 , & V_20 -> V_32 ) ;
V_67 -- ;
V_68 += V_25 ;
V_73 += V_72 ;
}
while ( V_68 < V_69 ) {
struct V_9 * V_10 , * V_93 ;
if ( ! V_20 -> V_31 . V_8 || V_64 ) {
if ( ! V_20 -> V_30 . V_8 )
goto V_92;
V_10 = F_9 ( & V_20 -> V_30 ) ;
F_7 ( V_10 , & V_20 -> V_31 ) ;
V_64 = 0 ;
}
F_27 (grp, ptr, &uctxt->tid_used_list.list,
list) {
unsigned V_94 = F_41 ( unsigned , V_69 - V_68 ,
V_10 -> V_40 - V_10 -> V_95 ) ;
V_25 = F_39 ( V_15 , V_74 , V_10 , V_79 ,
V_68 , V_94 , V_76 , V_77 ,
& V_71 , & V_72 ) ;
if ( V_25 < 0 ) {
F_40 ( V_91 ,
L_5 ,
V_25 ) ;
V_25 = - V_85 ;
goto V_92;
} else if ( V_25 > 0 ) {
if ( V_10 -> V_95 == V_10 -> V_40 )
F_11 ( V_10 ,
& V_20 -> V_31 ,
& V_20 -> V_32 ) ;
V_68 += V_25 ;
V_73 += V_72 ;
V_64 = 0 ;
if ( V_68 >= V_69 )
break;
} else if ( F_42 ( V_25 == 0 ) ) {
V_64 = 1 ;
}
}
}
V_92:
F_43 ( & V_20 -> V_90 ) ;
V_89:
F_40 ( V_91 , L_6 , V_71 ,
V_73 , V_25 ) ;
if ( V_71 ) {
F_19 ( & V_17 -> V_26 ) ;
V_17 -> V_88 += V_71 ;
F_20 ( & V_17 -> V_26 ) ;
V_63 -> V_96 = V_71 ;
V_63 -> V_80 = V_73 * V_84 ;
if ( F_44 ( ( void V_83 * ) ( unsigned long ) V_63 -> V_77 ,
V_77 , sizeof( V_77 [ 0 ] ) * V_71 ) ) {
V_63 -> V_77 = ( unsigned long ) & V_77 ;
F_45 ( V_15 , V_63 ) ;
V_63 -> V_77 = 0 ;
V_25 = - V_85 ;
goto V_86;
}
}
if ( V_73 != V_65 ) {
F_46 ( V_17 -> V_48 , & V_76 [ V_73 ] ,
V_65 - V_73 ,
false ) ;
V_17 -> V_87 -= V_65 - V_73 ;
}
V_86:
F_24 ( V_79 ) ;
F_24 ( V_76 ) ;
F_24 ( V_77 ) ;
return V_25 > 0 ? 0 : V_25 ;
}
int F_45 ( struct V_14 * V_15 , struct V_62 * V_63 )
{
int V_25 = 0 ;
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_19 * V_20 = V_17 -> V_20 ;
T_1 * V_97 ;
unsigned V_71 ;
V_97 = F_15 ( V_63 -> V_96 , sizeof( * V_97 ) , V_37 ) ;
if ( ! V_97 )
return - V_38 ;
if ( F_47 ( V_97 , ( void V_83 * ) ( unsigned long )
V_63 -> V_77 , sizeof( V_97 [ 0 ] ) *
V_63 -> V_96 ) ) {
V_25 = - V_85 ;
goto V_39;
}
F_38 ( & V_20 -> V_90 ) ;
for ( V_71 = 0 ; V_71 < V_63 -> V_96 ; V_71 ++ ) {
V_25 = F_48 ( V_15 , V_97 [ V_71 ] , NULL ) ;
if ( V_25 ) {
F_40 ( V_91 , L_7 ,
V_25 ) ;
break;
}
}
F_19 ( & V_17 -> V_26 ) ;
V_17 -> V_88 -= V_71 ;
F_20 ( & V_17 -> V_26 ) ;
V_63 -> V_96 = V_71 ;
F_43 ( & V_20 -> V_90 ) ;
V_39:
F_24 ( V_97 ) ;
return V_25 ;
}
int F_49 ( struct V_14 * V_15 , struct V_62 * V_63 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_19 * V_20 = V_17 -> V_20 ;
unsigned long * V_98 = V_20 -> V_22 -> V_99 +
( ( ( V_20 -> V_100 - V_20 -> V_22 -> V_101 ) *
V_102 ) + V_17 -> V_29 ) ;
T_1 * V_103 ;
int V_25 = 0 ;
if ( ! V_17 -> V_47 )
return - V_81 ;
V_103 = F_15 ( V_20 -> V_34 , sizeof( * V_103 ) , V_37 ) ;
if ( ! V_103 )
return - V_85 ;
F_19 ( & V_17 -> V_27 ) ;
if ( V_17 -> V_46 ) {
memcpy ( V_103 , V_17 -> V_47 , sizeof( * V_103 ) *
V_17 -> V_46 ) ;
memset ( V_17 -> V_47 , 0 , sizeof( * V_17 -> V_47 ) *
V_17 -> V_46 ) ;
V_63 -> V_96 = V_17 -> V_46 ;
V_17 -> V_46 = 0 ;
F_50 ( V_104 , V_98 ) ;
} else {
V_63 -> V_96 = 0 ;
}
F_20 ( & V_17 -> V_27 ) ;
if ( V_63 -> V_96 ) {
if ( F_44 ( ( void V_83 * ) V_63 -> V_77 ,
V_103 , sizeof( * V_103 ) * V_63 -> V_96 ) )
V_25 = - V_85 ;
}
F_24 ( V_103 ) ;
return V_25 ;
}
static T_1 F_37 ( struct V_75 * * V_76 , unsigned V_66 ,
struct V_78 * V_7 )
{
unsigned V_105 , V_68 , V_106 = 0 , V_24 ;
unsigned long V_107 , V_108 ;
if ( ! V_66 )
return 0 ;
V_107 = F_51 ( V_76 [ 0 ] ) ;
for ( V_68 = 0 , V_105 = 1 , V_24 = 1 ; V_24 <= V_66 ; V_24 ++ ) {
V_108 = V_24 < V_66 ? F_51 ( V_76 [ V_24 ] ) : 0 ;
if ( V_108 != ++ V_107 ) {
while ( V_105 ) {
int V_109 = V_105 ;
T_1 V_110 = V_105 * V_84 ;
if ( V_110 > V_111 )
V_109 =
V_111 >>
V_112 ;
else if ( ! F_52 ( V_110 ) )
V_109 =
F_53 ( V_110 ) >>
V_112 ;
V_7 [ V_106 ] . V_113 = V_68 ;
V_7 [ V_106 ] . V_8 = V_109 ;
V_105 -= V_109 ;
V_68 += V_109 ;
V_106 ++ ;
}
V_68 = V_24 ;
V_105 = 1 ;
V_107 = V_108 ;
} else {
V_105 ++ ;
}
}
return V_106 ;
}
static int F_39 ( struct V_14 * V_15 , unsigned long V_74 ,
struct V_9 * V_10 ,
struct V_78 * V_114 ,
unsigned V_115 , T_2 V_8 , struct V_75 * * V_76 ,
T_1 * V_77 , unsigned * V_71 , unsigned * V_116 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_19 * V_20 = V_17 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_22 ;
T_2 V_113 ;
T_1 V_97 = 0 , V_1 , V_117 = 0 ;
int V_72 = 0 ;
if ( V_8 > V_10 -> V_40 )
return - V_81 ;
for ( V_113 = 0 ; V_113 < V_10 -> V_40 ; V_113 ++ ) {
if ( ! ( V_10 -> V_118 & ( 1 << V_113 ) ) ) {
V_117 = V_113 ;
break;
}
F_29 ( V_22 , V_10 -> V_41 + V_113 ) ;
}
V_113 = 0 ;
while ( V_113 < V_8 ) {
T_2 V_66 , V_68 , V_119 = V_115 + V_113 ;
int V_25 = 0 ;
if ( V_117 >= V_10 -> V_40 ) {
break;
} else if ( V_10 -> V_118 & ( 1 << V_117 ) ) {
F_29 ( V_22 , V_10 -> V_41 + V_117 ) ;
V_117 ++ ;
continue;
}
V_1 = V_10 -> V_41 + V_117 ;
V_66 = V_114 [ V_119 ] . V_8 ;
V_68 = V_114 [ V_119 ] . V_113 ;
V_25 = F_54 ( V_15 , V_74 + ( V_68 * V_84 ) ,
V_1 , V_10 , V_76 + V_68 ,
V_66 ) ;
if ( V_25 )
return V_25 ;
V_72 += V_66 ;
V_97 = F_1 ( V_1 - V_20 -> V_33 ) |
F_2 ( V_120 , V_66 ) ;
V_77 [ ( * V_71 ) ++ ] = V_97 ;
V_10 -> V_95 ++ ;
V_10 -> V_118 |= 1 << V_117 ++ ;
V_113 ++ ;
}
for (; V_117 < V_10 -> V_40 ; V_117 ++ )
F_29 ( V_22 , V_10 -> V_41 + V_117 ) ;
* V_116 = V_72 ;
return V_113 ;
}
static int F_54 ( struct V_14 * V_15 , unsigned long V_74 ,
T_1 V_1 , struct V_9 * V_10 ,
struct V_75 * * V_76 , unsigned V_66 )
{
int V_25 ;
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_19 * V_20 = V_17 -> V_20 ;
struct V_121 * V_122 ;
struct V_21 * V_22 = V_20 -> V_22 ;
T_3 V_123 ;
V_122 = F_14 ( sizeof( * V_122 ) + ( sizeof( struct V_75 * ) * V_66 ) ,
V_37 ) ;
if ( ! V_122 )
return - V_38 ;
V_123 = F_55 ( V_22 -> V_124 ,
F_56 ( F_57 ( V_76 [ 0 ] ) ) ,
V_66 * V_84 , V_125 ) ;
if ( F_58 ( & V_22 -> V_124 -> V_126 , V_123 ) ) {
F_33 ( V_22 , L_8 ,
V_123 ) ;
F_24 ( V_122 ) ;
return - V_85 ;
}
V_122 -> V_127 . V_128 = V_74 ;
V_122 -> V_127 . V_129 = V_66 * V_84 ;
V_122 -> V_123 = F_57 ( V_76 [ 0 ] ) ;
V_122 -> V_66 = V_66 ;
V_122 -> V_1 = V_1 ;
V_122 -> V_130 = V_123 ;
V_122 -> V_10 = V_10 ;
V_122 -> V_131 = false ;
memcpy ( V_122 -> V_76 , V_76 , sizeof( struct V_75 * ) * V_66 ) ;
if ( ! V_17 -> V_52 )
V_25 = F_59 ( V_17 , & V_122 -> V_127 ) ;
else
V_25 = F_60 ( V_17 -> V_52 , & V_122 -> V_127 ) ;
if ( V_25 ) {
F_40 ( V_91 , L_9 ,
V_122 -> V_1 , V_122 -> V_127 . V_128 , V_122 -> V_123 , V_25 ) ;
F_61 ( V_22 -> V_124 , V_123 , V_66 * V_84 ,
V_125 ) ;
F_24 ( V_122 ) ;
return - V_85 ;
}
F_62 ( V_22 , V_1 , V_132 , V_123 , F_63 ( V_66 ) + 1 ) ;
F_64 ( V_20 -> V_100 , V_17 -> V_29 , V_1 , V_66 ,
V_122 -> V_127 . V_128 , V_122 -> V_123 , V_123 ) ;
return 0 ;
}
static int F_48 ( struct V_14 * V_15 , T_1 V_97 ,
struct V_9 * * V_10 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_19 * V_20 = V_17 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_22 ;
struct V_121 * V_122 ;
T_4 V_133 = F_65 ( V_97 , V_4 ) ;
T_1 V_71 = F_65 ( V_97 , V_3 ) << 1 , V_1 ;
if ( V_71 >= V_20 -> V_34 ) {
F_33 ( V_22 , L_10 ,
V_71 , V_20 -> V_100 ) ;
return - V_81 ;
}
if ( V_133 == 0x3 )
return - V_81 ;
V_1 = V_71 + ( V_133 - 1 ) ;
V_122 = V_17 -> V_42 [ V_1 ] ;
if ( ! V_122 || V_122 -> V_1 != ( V_20 -> V_33 + V_1 ) )
return - V_134 ;
if ( V_10 )
* V_10 = V_122 -> V_10 ;
if ( ! V_17 -> V_52 )
F_66 ( V_17 , V_122 ) ;
else
F_67 ( V_17 -> V_52 , & V_122 -> V_127 ) ;
return 0 ;
}
static void F_68 ( struct V_16 * V_17 , struct V_121 * V_122 )
{
struct V_19 * V_20 = V_17 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_22 ;
F_69 ( V_20 -> V_100 , V_17 -> V_29 , V_122 -> V_1 ,
V_122 -> V_66 , V_122 -> V_127 . V_128 , V_122 -> V_123 ,
V_122 -> V_130 ) ;
F_62 ( V_22 , V_122 -> V_1 , V_135 , 0 , 0 ) ;
F_70 () ;
F_61 ( V_22 -> V_124 , V_122 -> V_130 , V_122 -> V_127 . V_129 ,
V_125 ) ;
F_46 ( V_17 -> V_48 , V_122 -> V_76 , V_122 -> V_66 , true ) ;
V_17 -> V_87 -= V_122 -> V_66 ;
V_122 -> V_10 -> V_95 -- ;
V_122 -> V_10 -> V_118 &= ~ ( 1 << ( V_122 -> V_1 - V_122 -> V_10 -> V_41 ) ) ;
if ( V_122 -> V_10 -> V_95 == V_122 -> V_10 -> V_40 - 1 )
F_11 ( V_122 -> V_10 , & V_20 -> V_32 ,
& V_20 -> V_31 ) ;
else if ( ! V_122 -> V_10 -> V_95 )
F_11 ( V_122 -> V_10 , & V_20 -> V_31 ,
& V_20 -> V_30 ) ;
F_24 ( V_122 ) ;
}
static void F_26 ( struct V_19 * V_20 ,
struct V_5 * V_6 ,
struct V_16 * V_17 )
{
struct V_9 * V_10 , * V_93 ;
int V_24 ;
F_27 (grp, ptr, &set->list, list) {
F_6 ( & V_10 -> V_7 ) ;
for ( V_24 = 0 ; V_24 < V_10 -> V_40 ; V_24 ++ ) {
if ( V_10 -> V_118 & ( 1 << V_24 ) ) {
T_2 V_1 = V_10 -> V_41 + V_24 ;
struct V_121 * V_122 ;
V_122 = V_17 -> V_42 [ V_1 -
V_20 -> V_33 ] ;
if ( ! V_122 || V_122 -> V_1 != V_1 )
continue;
F_66 ( V_17 , V_122 ) ;
}
}
}
}
static int F_71 ( void * V_136 , struct V_137 * V_138 )
{
struct V_16 * V_139 = V_136 ;
struct V_19 * V_20 = V_139 -> V_20 ;
struct V_121 * V_122 =
F_72 ( V_138 , struct V_121 , V_127 ) ;
if ( V_122 -> V_131 )
return 0 ;
F_73 ( V_20 -> V_100 , V_139 -> V_29 , V_122 -> V_127 . V_128 ,
V_122 -> V_1 , V_122 -> V_66 , V_122 -> V_130 ) ;
V_122 -> V_131 = true ;
F_19 ( & V_139 -> V_27 ) ;
if ( V_139 -> V_46 < V_20 -> V_34 ) {
V_139 -> V_47 [ V_139 -> V_46 ] =
F_1 ( V_122 -> V_1 - V_20 -> V_33 ) ;
V_139 -> V_47 [ V_139 -> V_46 ] |=
F_2 ( V_120 , V_122 -> V_66 ) ;
if ( ! V_139 -> V_46 ) {
unsigned long * V_98 ;
V_98 = V_20 -> V_22 -> V_99 +
( ( ( V_20 -> V_100 - V_20 -> V_22 -> V_101 ) *
V_102 ) + V_139 -> V_29 ) ;
F_74 ( V_104 , V_98 ) ;
}
V_139 -> V_46 ++ ;
}
F_20 ( & V_139 -> V_27 ) ;
return 0 ;
}
static int F_59 ( void * V_136 , struct V_137 * V_122 )
{
struct V_16 * V_139 = V_136 ;
struct V_121 * V_140 =
F_72 ( V_122 , struct V_121 , V_127 ) ;
T_1 V_41 = V_139 -> V_20 -> V_33 ;
V_139 -> V_42 [ V_140 -> V_1 - V_41 ] = V_140 ;
return 0 ;
}
static void F_66 ( struct V_16 * V_139 ,
struct V_121 * V_140 )
{
T_1 V_41 = V_139 -> V_20 -> V_33 ;
V_139 -> V_42 [ V_140 -> V_1 - V_41 ] = NULL ;
F_68 ( V_139 , V_140 ) ;
}
static void F_75 ( void * V_136 , struct V_137 * V_122 )
{
struct V_16 * V_139 = V_136 ;
struct V_121 * V_140 =
F_72 ( V_122 , struct V_121 , V_127 ) ;
F_66 ( V_139 , V_140 ) ;
}
