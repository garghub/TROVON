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
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_18 * V_19 = V_15 -> V_19 ;
T_1 V_20 ;
T_1 V_21 ;
struct V_9 * V_10 , * V_22 ;
F_3 ( & V_17 -> V_23 ) ;
F_3 ( & V_17 -> V_24 ) ;
F_3 ( & V_17 -> V_25 ) ;
V_20 = V_17 -> V_26 ;
for ( V_21 = 0 ; V_21 < V_17 -> V_27 /
V_19 -> V_28 . V_29 ; V_21 ++ ) {
V_10 = F_13 ( sizeof( * V_10 ) , V_30 ) ;
if ( ! V_10 )
goto V_31;
V_10 -> V_32 = V_19 -> V_28 . V_29 ;
V_10 -> V_33 = V_20 ;
F_7 ( V_10 , & V_17 -> V_23 ) ;
V_20 += V_19 -> V_28 . V_29 ;
}
return 0 ;
V_31:
F_14 (grp, gptr, &uctxt->tid_group_list.list,
list) {
F_6 ( & V_10 -> V_7 ) ;
F_15 ( V_10 ) ;
}
return - V_34 ;
}
int F_16 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_19 ;
int V_35 = 0 ;
F_17 ( & V_15 -> V_36 ) ;
F_17 ( & V_15 -> V_37 ) ;
V_15 -> V_38 = F_18 ( V_17 -> V_27 ,
sizeof( struct V_39 * ) ,
V_30 ) ;
if ( ! V_15 -> V_38 )
return - V_34 ;
if ( ! F_19 ( V_17 -> V_40 , V_41 ) ) {
V_15 -> V_42 = 0 ;
V_15 -> V_43 = F_18 ( V_17 -> V_27 ,
sizeof( * V_15 -> V_43 ) ,
V_30 ) ;
if ( ! V_15 -> V_43 ) {
F_15 ( V_15 -> V_38 ) ;
V_15 -> V_38 = NULL ;
return - V_34 ;
}
V_35 = F_20 ( V_15 , V_15 -> V_44 , & V_45 ,
V_19 -> V_46 -> V_47 ,
& V_15 -> V_48 ) ;
if ( V_35 ) {
F_21 ( V_19 ,
L_1 ,
V_35 ) ;
V_35 = 0 ;
}
}
F_22 ( & V_15 -> V_36 ) ;
if ( V_17 -> V_49 && V_15 -> V_48 ) {
T_2 V_50 ;
V_15 -> V_51 = V_17 -> V_27 / V_17 -> V_49 ;
V_50 = V_17 -> V_27 % V_17 -> V_49 ;
if ( V_50 && V_15 -> V_52 < V_50 )
V_15 -> V_51 ++ ;
} else {
V_15 -> V_51 = V_17 -> V_27 ;
}
F_23 ( & V_15 -> V_36 ) ;
return V_35 ;
}
void F_24 ( struct V_16 * V_17 )
{
struct V_9 * V_10 , * V_22 ;
F_14 (grp, gptr, &uctxt->tid_group_list.list,
list) {
F_6 ( & V_10 -> V_7 ) ;
F_15 ( V_10 ) ;
}
F_25 ( V_17 ) ;
}
void F_26 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
if ( V_15 -> V_48 ) {
F_27 ( V_15 -> V_48 ) ;
} else {
if ( ! F_28 ( V_17 -> V_25 ) )
F_29 ( V_17 , & V_17 -> V_25 , V_15 ) ;
if ( ! F_28 ( V_17 -> V_24 ) )
F_29 ( V_17 , & V_17 -> V_24 , V_15 ) ;
}
F_15 ( V_15 -> V_43 ) ;
V_15 -> V_43 = NULL ;
F_15 ( V_15 -> V_38 ) ;
V_15 -> V_38 = NULL ;
}
static inline void F_30 ( struct V_18 * V_19 , T_1 V_53 )
{
if ( ( V_19 -> V_40 & V_54 ) && V_19 -> V_55 )
F_31 ( 0 , V_19 -> V_55 + ( V_53 * 8 ) ) ;
}
int F_32 ( struct V_14 * V_15 ,
struct V_56 * V_57 )
{
int V_35 = 0 , V_58 = 0 , V_59 ;
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_19 ;
unsigned V_60 , V_61 , V_62 = 0 , V_63 , V_64 ,
V_65 = 0 , V_66 , V_67 = 0 ;
unsigned long V_68 = V_57 -> V_68 ;
struct V_69 * * V_70 = NULL ;
T_1 * V_71 = NULL ;
struct V_72 * V_73 = NULL ;
V_60 = F_33 ( V_68 , V_57 -> V_74 ) ;
if ( ! V_60 )
return - V_75 ;
if ( V_60 > V_17 -> V_27 ) {
F_34 ( V_19 , L_2 ) ;
return - V_75 ;
}
if ( ! F_35 ( V_76 , ( void V_77 * ) V_68 ,
V_60 * V_78 ) ) {
F_34 ( V_19 , L_3 ,
( void * ) V_68 , V_60 ) ;
return - V_79 ;
}
V_73 = F_18 ( V_17 -> V_27 , sizeof( * V_73 ) ,
V_30 ) ;
if ( ! V_73 )
return - V_34 ;
V_70 = F_18 ( V_60 , sizeof( * V_70 ) , V_30 ) ;
if ( ! V_70 ) {
V_35 = - V_34 ;
goto V_80;
}
if ( ! F_36 ( V_19 , V_15 -> V_44 , V_15 -> V_81 , V_60 ) ) {
V_35 = - V_34 ;
goto V_80;
}
V_59 = F_37 ( V_15 -> V_44 , V_68 , V_60 , true , V_70 ) ;
if ( V_59 <= 0 ) {
V_35 = V_59 ;
goto V_80;
}
V_15 -> V_81 += V_60 ;
V_64 = F_38 ( V_70 , V_59 , V_73 ) ;
F_22 ( & V_15 -> V_36 ) ;
if ( V_15 -> V_82 + V_64 > V_15 -> V_51 )
V_63 = V_15 -> V_51 - V_15 -> V_82 ;
else
V_63 = V_64 ;
F_23 ( & V_15 -> V_36 ) ;
if ( ! V_63 )
goto V_80;
V_61 = V_63 / V_19 -> V_28 . V_29 ;
V_71 = F_18 ( V_63 , sizeof( * V_71 ) , V_30 ) ;
if ( ! V_71 ) {
V_35 = - V_34 ;
goto V_83;
}
V_65 = 0 ;
F_39 ( & V_17 -> V_84 ) ;
while ( V_61 && V_17 -> V_23 . V_8 ) {
struct V_9 * V_10 =
F_9 ( & V_17 -> V_23 ) ;
V_35 = F_40 ( V_15 , V_68 , V_10 , V_73 ,
V_62 , V_19 -> V_28 . V_29 ,
V_70 , V_71 , & V_65 , & V_66 ) ;
if ( V_35 <= 0 ) {
F_7 ( V_10 , & V_17 -> V_23 ) ;
F_41 ( V_85 ,
L_4 , V_35 ) ;
goto V_86;
}
F_7 ( V_10 , & V_17 -> V_25 ) ;
V_61 -- ;
V_62 += V_35 ;
V_67 += V_66 ;
}
while ( V_62 < V_63 ) {
struct V_9 * V_10 , * V_87 ;
if ( ! V_17 -> V_24 . V_8 || V_58 ) {
if ( ! V_17 -> V_23 . V_8 )
goto V_86;
V_10 = F_9 ( & V_17 -> V_23 ) ;
F_7 ( V_10 , & V_17 -> V_24 ) ;
V_58 = 0 ;
}
F_14 (grp, ptr, &uctxt->tid_used_list.list,
list) {
unsigned V_88 = F_42 ( unsigned , V_63 - V_62 ,
V_10 -> V_32 - V_10 -> V_89 ) ;
V_35 = F_40 ( V_15 , V_68 , V_10 , V_73 ,
V_62 , V_88 , V_70 , V_71 ,
& V_65 , & V_66 ) ;
if ( V_35 < 0 ) {
F_41 ( V_85 ,
L_5 ,
V_35 ) ;
V_35 = - V_79 ;
goto V_86;
} else if ( V_35 > 0 ) {
if ( V_10 -> V_89 == V_10 -> V_32 )
F_11 ( V_10 ,
& V_17 -> V_24 ,
& V_17 -> V_25 ) ;
V_62 += V_35 ;
V_67 += V_66 ;
V_58 = 0 ;
if ( V_62 >= V_63 )
break;
} else if ( F_43 ( V_35 == 0 ) ) {
V_58 = 1 ;
}
}
}
V_86:
F_44 ( & V_17 -> V_84 ) ;
V_83:
F_41 ( V_85 , L_6 , V_65 ,
V_67 , V_35 ) ;
if ( V_65 ) {
F_22 ( & V_15 -> V_36 ) ;
V_15 -> V_82 += V_65 ;
F_23 ( & V_15 -> V_36 ) ;
V_57 -> V_90 = V_65 ;
V_57 -> V_74 = V_67 * V_78 ;
if ( F_45 ( ( void V_77 * ) ( unsigned long ) V_57 -> V_71 ,
V_71 , sizeof( V_71 [ 0 ] ) * V_65 ) ) {
V_57 -> V_71 = ( unsigned long ) & V_71 ;
F_46 ( V_15 , V_57 ) ;
V_57 -> V_71 = 0 ;
V_35 = - V_79 ;
goto V_80;
}
}
if ( V_67 != V_59 ) {
F_47 ( V_15 -> V_44 , & V_70 [ V_67 ] ,
V_59 - V_67 ,
false ) ;
V_15 -> V_81 -= V_59 - V_67 ;
}
V_80:
F_15 ( V_73 ) ;
F_15 ( V_70 ) ;
F_15 ( V_71 ) ;
return V_35 > 0 ? 0 : V_35 ;
}
int F_46 ( struct V_14 * V_15 ,
struct V_56 * V_57 )
{
int V_35 = 0 ;
struct V_16 * V_17 = V_15 -> V_17 ;
T_1 * V_91 ;
unsigned V_65 ;
if ( F_48 ( V_57 -> V_90 > V_15 -> V_82 ) )
return - V_75 ;
V_91 = F_49 ( ( void V_77 * ) ( unsigned long ) V_57 -> V_71 ,
sizeof( V_91 [ 0 ] ) * V_57 -> V_90 ) ;
if ( F_50 ( V_91 ) )
return F_51 ( V_91 ) ;
F_39 ( & V_17 -> V_84 ) ;
for ( V_65 = 0 ; V_65 < V_57 -> V_90 ; V_65 ++ ) {
V_35 = F_52 ( V_15 , V_91 [ V_65 ] , NULL ) ;
if ( V_35 ) {
F_41 ( V_85 , L_7 ,
V_35 ) ;
break;
}
}
F_22 ( & V_15 -> V_36 ) ;
V_15 -> V_82 -= V_65 ;
F_23 ( & V_15 -> V_36 ) ;
V_57 -> V_90 = V_65 ;
F_44 ( & V_17 -> V_84 ) ;
F_15 ( V_91 ) ;
return V_35 ;
}
int F_53 ( struct V_14 * V_15 ,
struct V_56 * V_57 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
unsigned long * V_92 = V_17 -> V_19 -> V_93 +
( ( ( V_17 -> V_94 - V_17 -> V_19 -> V_95 ) *
V_96 ) + V_15 -> V_52 ) ;
T_1 * V_97 ;
int V_35 = 0 ;
if ( ! V_15 -> V_43 )
return - V_75 ;
V_97 = F_18 ( V_17 -> V_27 , sizeof( * V_97 ) , V_30 ) ;
if ( ! V_97 )
return - V_79 ;
F_22 ( & V_15 -> V_37 ) ;
if ( V_15 -> V_42 ) {
memcpy ( V_97 , V_15 -> V_43 , sizeof( * V_97 ) *
V_15 -> V_42 ) ;
memset ( V_15 -> V_43 , 0 , sizeof( * V_15 -> V_43 ) *
V_15 -> V_42 ) ;
V_57 -> V_90 = V_15 -> V_42 ;
V_15 -> V_42 = 0 ;
F_54 ( V_98 , V_92 ) ;
} else {
V_57 -> V_90 = 0 ;
}
F_23 ( & V_15 -> V_37 ) ;
if ( V_57 -> V_90 ) {
if ( F_45 ( ( void V_77 * ) V_57 -> V_71 ,
V_97 , sizeof( * V_97 ) * V_57 -> V_90 ) )
V_35 = - V_79 ;
}
F_15 ( V_97 ) ;
return V_35 ;
}
static T_1 F_38 ( struct V_69 * * V_70 , unsigned V_60 ,
struct V_72 * V_7 )
{
unsigned V_99 , V_62 , V_100 = 0 , V_21 ;
unsigned long V_101 , V_102 ;
if ( ! V_60 )
return 0 ;
V_101 = F_55 ( V_70 [ 0 ] ) ;
for ( V_62 = 0 , V_99 = 1 , V_21 = 1 ; V_21 <= V_60 ; V_21 ++ ) {
V_102 = V_21 < V_60 ? F_55 ( V_70 [ V_21 ] ) : 0 ;
if ( V_102 != ++ V_101 ) {
while ( V_99 ) {
int V_103 = V_99 ;
T_1 V_104 = V_99 * V_78 ;
if ( V_104 > V_105 )
V_103 =
V_105 >>
V_106 ;
else if ( ! F_56 ( V_104 ) )
V_103 =
F_57 ( V_104 ) >>
V_106 ;
V_7 [ V_100 ] . V_107 = V_62 ;
V_7 [ V_100 ] . V_8 = V_103 ;
V_99 -= V_103 ;
V_62 += V_103 ;
V_100 ++ ;
}
V_62 = V_21 ;
V_99 = 1 ;
V_101 = V_102 ;
} else {
V_99 ++ ;
}
}
return V_100 ;
}
static int F_40 ( struct V_14 * V_15 , unsigned long V_68 ,
struct V_9 * V_10 ,
struct V_72 * V_108 ,
unsigned V_109 , T_2 V_8 , struct V_69 * * V_70 ,
T_1 * V_71 , unsigned * V_65 , unsigned * V_110 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_19 ;
T_2 V_107 ;
T_1 V_91 = 0 , V_1 , V_111 = 0 ;
int V_66 = 0 ;
if ( V_8 > V_10 -> V_32 )
return - V_75 ;
for ( V_107 = 0 ; V_107 < V_10 -> V_32 ; V_107 ++ ) {
if ( ! ( V_10 -> V_112 & ( 1 << V_107 ) ) ) {
V_111 = V_107 ;
break;
}
F_30 ( V_19 , V_10 -> V_33 + V_107 ) ;
}
V_107 = 0 ;
while ( V_107 < V_8 ) {
T_2 V_60 , V_62 , V_113 = V_109 + V_107 ;
int V_35 = 0 ;
if ( V_111 >= V_10 -> V_32 ) {
break;
} else if ( V_10 -> V_112 & ( 1 << V_111 ) ) {
F_30 ( V_19 , V_10 -> V_33 + V_111 ) ;
V_111 ++ ;
continue;
}
V_1 = V_10 -> V_33 + V_111 ;
V_60 = V_108 [ V_113 ] . V_8 ;
V_62 = V_108 [ V_113 ] . V_107 ;
V_35 = F_58 ( V_15 , V_68 + ( V_62 * V_78 ) ,
V_1 , V_10 , V_70 + V_62 ,
V_60 ) ;
if ( V_35 )
return V_35 ;
V_66 += V_60 ;
V_91 = F_1 ( V_1 - V_17 -> V_26 ) |
F_2 ( V_114 , V_60 ) ;
V_71 [ ( * V_65 ) ++ ] = V_91 ;
V_10 -> V_89 ++ ;
V_10 -> V_112 |= 1 << V_111 ++ ;
V_107 ++ ;
}
for (; V_111 < V_10 -> V_32 ; V_111 ++ )
F_30 ( V_19 , V_10 -> V_33 + V_111 ) ;
* V_110 = V_66 ;
return V_107 ;
}
static int F_58 ( struct V_14 * V_15 , unsigned long V_68 ,
T_1 V_1 , struct V_9 * V_10 ,
struct V_69 * * V_70 , unsigned V_60 )
{
int V_35 ;
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_115 * V_116 ;
struct V_18 * V_19 = V_17 -> V_19 ;
T_3 V_117 ;
V_116 = F_13 ( sizeof( * V_116 ) + ( sizeof( struct V_69 * ) * V_60 ) ,
V_30 ) ;
if ( ! V_116 )
return - V_34 ;
V_117 = F_59 ( V_19 -> V_118 ,
F_60 ( F_61 ( V_70 [ 0 ] ) ) ,
V_60 * V_78 , V_119 ) ;
if ( F_62 ( & V_19 -> V_118 -> V_120 , V_117 ) ) {
F_34 ( V_19 , L_8 ,
V_117 ) ;
F_15 ( V_116 ) ;
return - V_79 ;
}
V_116 -> V_121 . V_122 = V_68 ;
V_116 -> V_121 . V_123 = V_60 * V_78 ;
V_116 -> V_117 = F_61 ( V_70 [ 0 ] ) ;
V_116 -> V_60 = V_60 ;
V_116 -> V_1 = V_1 ;
V_116 -> V_124 = V_117 ;
V_116 -> V_10 = V_10 ;
V_116 -> V_125 = false ;
memcpy ( V_116 -> V_70 , V_70 , sizeof( struct V_69 * ) * V_60 ) ;
if ( ! V_15 -> V_48 )
V_35 = F_63 ( V_15 , & V_116 -> V_121 ) ;
else
V_35 = F_64 ( V_15 -> V_48 , & V_116 -> V_121 ) ;
if ( V_35 ) {
F_41 ( V_85 , L_9 ,
V_116 -> V_1 , V_116 -> V_121 . V_122 , V_116 -> V_117 , V_35 ) ;
F_65 ( V_19 -> V_118 , V_117 , V_60 * V_78 ,
V_119 ) ;
F_15 ( V_116 ) ;
return - V_79 ;
}
F_66 ( V_19 , V_1 , V_126 , V_117 , F_67 ( V_60 ) + 1 ) ;
F_68 ( V_17 -> V_94 , V_15 -> V_52 , V_1 , V_60 ,
V_116 -> V_121 . V_122 , V_116 -> V_117 , V_117 ) ;
return 0 ;
}
static int F_52 ( struct V_14 * V_15 , T_1 V_91 ,
struct V_9 * * V_10 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_115 * V_116 ;
T_4 V_127 = F_69 ( V_91 , V_4 ) ;
T_1 V_65 = F_69 ( V_91 , V_3 ) << 1 , V_1 ;
if ( V_65 >= V_17 -> V_27 ) {
F_34 ( V_19 , L_10 ,
V_65 , V_17 -> V_94 ) ;
return - V_75 ;
}
if ( V_127 == 0x3 )
return - V_75 ;
V_1 = V_65 + ( V_127 - 1 ) ;
V_116 = V_15 -> V_38 [ V_1 ] ;
if ( ! V_116 || V_116 -> V_1 != ( V_17 -> V_26 + V_1 ) )
return - V_128 ;
if ( V_10 )
* V_10 = V_116 -> V_10 ;
if ( ! V_15 -> V_48 )
F_70 ( V_15 , V_116 ) ;
else
F_71 ( V_15 -> V_48 , & V_116 -> V_121 ) ;
return 0 ;
}
static void F_72 ( struct V_14 * V_15 , struct V_115 * V_116 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_19 ;
F_73 ( V_17 -> V_94 , V_15 -> V_52 , V_116 -> V_1 ,
V_116 -> V_60 , V_116 -> V_121 . V_122 , V_116 -> V_117 ,
V_116 -> V_124 ) ;
F_66 ( V_19 , V_116 -> V_1 , V_129 , 0 , 0 ) ;
F_74 () ;
F_65 ( V_19 -> V_118 , V_116 -> V_124 , V_116 -> V_121 . V_123 ,
V_119 ) ;
F_47 ( V_15 -> V_44 , V_116 -> V_70 , V_116 -> V_60 , true ) ;
V_15 -> V_81 -= V_116 -> V_60 ;
V_116 -> V_10 -> V_89 -- ;
V_116 -> V_10 -> V_112 &= ~ ( 1 << ( V_116 -> V_1 - V_116 -> V_10 -> V_33 ) ) ;
if ( V_116 -> V_10 -> V_89 == V_116 -> V_10 -> V_32 - 1 )
F_11 ( V_116 -> V_10 , & V_17 -> V_25 ,
& V_17 -> V_24 ) ;
else if ( ! V_116 -> V_10 -> V_89 )
F_11 ( V_116 -> V_10 , & V_17 -> V_24 ,
& V_17 -> V_23 ) ;
F_15 ( V_116 ) ;
}
static void F_29 ( struct V_16 * V_17 ,
struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_9 * V_10 , * V_87 ;
int V_21 ;
F_14 (grp, ptr, &set->list, list) {
F_6 ( & V_10 -> V_7 ) ;
for ( V_21 = 0 ; V_21 < V_10 -> V_32 ; V_21 ++ ) {
if ( V_10 -> V_112 & ( 1 << V_21 ) ) {
T_2 V_1 = V_10 -> V_33 + V_21 ;
struct V_115 * V_116 ;
V_116 = V_15 -> V_38 [ V_1 -
V_17 -> V_26 ] ;
if ( ! V_116 || V_116 -> V_1 != V_1 )
continue;
F_70 ( V_15 , V_116 ) ;
}
}
}
}
static int F_75 ( void * V_130 , struct V_131 * V_132 )
{
struct V_14 * V_133 = V_130 ;
struct V_16 * V_17 = V_133 -> V_17 ;
struct V_115 * V_116 =
F_76 ( V_132 , struct V_115 , V_121 ) ;
if ( V_116 -> V_125 )
return 0 ;
F_77 ( V_17 -> V_94 , V_133 -> V_52 , V_116 -> V_121 . V_122 ,
V_116 -> V_1 , V_116 -> V_60 , V_116 -> V_124 ) ;
V_116 -> V_125 = true ;
F_22 ( & V_133 -> V_37 ) ;
if ( V_133 -> V_42 < V_17 -> V_27 ) {
V_133 -> V_43 [ V_133 -> V_42 ] =
F_1 ( V_116 -> V_1 - V_17 -> V_26 ) ;
V_133 -> V_43 [ V_133 -> V_42 ] |=
F_2 ( V_114 , V_116 -> V_60 ) ;
if ( ! V_133 -> V_42 ) {
unsigned long * V_92 ;
V_92 = V_17 -> V_19 -> V_93 +
( ( ( V_17 -> V_94 - V_17 -> V_19 -> V_95 ) *
V_96 ) + V_133 -> V_52 ) ;
F_78 ( V_98 , V_92 ) ;
}
V_133 -> V_42 ++ ;
}
F_23 ( & V_133 -> V_37 ) ;
return 0 ;
}
static int F_63 ( void * V_130 , struct V_131 * V_116 )
{
struct V_14 * V_133 = V_130 ;
struct V_115 * V_134 =
F_76 ( V_116 , struct V_115 , V_121 ) ;
T_1 V_33 = V_133 -> V_17 -> V_26 ;
V_133 -> V_38 [ V_134 -> V_1 - V_33 ] = V_134 ;
return 0 ;
}
static void F_70 ( struct V_14 * V_133 ,
struct V_115 * V_134 )
{
T_1 V_33 = V_133 -> V_17 -> V_26 ;
V_133 -> V_38 [ V_134 -> V_1 - V_33 ] = NULL ;
F_72 ( V_133 , V_134 ) ;
}
static void F_79 ( void * V_130 , struct V_131 * V_116 )
{
struct V_14 * V_133 = V_130 ;
struct V_115 * V_134 =
F_76 ( V_116 , struct V_115 , V_121 ) ;
F_70 ( V_133 , V_134 ) ;
}
