static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 )
{
return F_2 ( V_6 ) ? : - V_7 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 )
{
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 )
{
struct V_8 {
T_1 V_5 ;
T_2 V_9 ;
} * V_10 ;
int V_11 ;
V_10 = F_5 ( V_5 , struct V_8 , V_5 ) ;
if ( F_6 ( V_4 -> V_12 && V_10 -> V_9 == V_4 -> V_13 ) )
return 0 ;
V_11 = F_7 ( V_2 , V_4 -> V_14 , V_10 -> V_9 ) ;
if ( F_8 ( V_11 != 0 ) ) {
F_9 ( L_1 ,
( unsigned ) V_10 -> V_9 ) ;
return V_11 ;
}
V_4 -> V_13 = V_10 -> V_9 ;
V_4 -> V_12 = true ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_3 * V_15 )
{
if ( * V_15 == V_16 )
return 0 ;
if ( F_8 ( ( ! V_4 -> V_17 ||
* V_15 != V_4 -> V_18 ) ) ) {
int V_19 ;
int V_11 = F_11 ( V_2 , V_4 -> V_14 ,
* V_15 , & V_19 ) ;
if ( F_8 ( V_11 != 0 ) ) {
F_9 ( L_2
L_3 ,
( unsigned int ) * V_15 ,
( unsigned long ) V_15 ) ;
return V_11 ;
}
V_4 -> V_18 = * V_15 ;
V_4 -> V_17 = true ;
* V_15 = V_19 ;
V_4 -> V_20 = V_19 ;
} else
* V_15 = V_4 -> V_20 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 )
{
struct V_21 {
T_1 V_5 ;
T_4 V_22 ;
} * V_10 ;
int V_11 ;
V_11 = F_4 ( V_2 , V_4 , V_5 ) ;
if ( F_8 ( V_11 != 0 ) )
return V_11 ;
V_10 = F_5 ( V_5 , struct V_21 , V_5 ) ;
V_11 = F_10 ( V_2 , V_4 , & V_10 -> V_22 . V_23 . V_15 ) ;
return V_11 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 )
{
struct V_21 {
T_1 V_5 ;
T_5 V_22 ;
} * V_10 ;
int V_11 ;
V_10 = F_5 ( V_5 , struct V_21 , V_5 ) ;
V_11 = F_10 ( V_2 , V_4 , & V_10 -> V_22 . V_24 . V_15 ) ;
if ( F_8 ( V_11 != 0 ) )
return V_11 ;
return F_10 ( V_2 , V_4 , & V_10 -> V_22 . V_25 . V_15 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 )
{
struct V_21 {
T_1 V_5 ;
T_6 V_22 ;
} * V_10 ;
int V_11 ;
V_10 = F_5 ( V_5 , struct V_21 , V_5 ) ;
V_11 = F_10 ( V_2 , V_4 , & V_10 -> V_22 . V_24 . V_15 ) ;
if ( F_8 ( V_11 != 0 ) )
return V_11 ;
return F_10 ( V_2 , V_4 , & V_10 -> V_22 . V_25 . V_15 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 )
{
struct V_21 {
T_1 V_5 ;
T_7 V_22 ;
} * V_10 ;
V_10 = F_5 ( V_5 , struct V_21 , V_5 ) ;
return F_10 ( V_2 , V_4 , & V_10 -> V_22 . V_26 . V_15 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 )
{
struct V_21 {
T_1 V_5 ;
T_8 V_22 ;
} * V_10 ;
V_10 = F_5 ( V_5 , struct V_21 , V_5 ) ;
return F_10 ( V_2 , V_4 , & V_10 -> V_22 . V_15 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_9 * V_27 ,
struct V_28 * * V_29 )
{
struct V_28 * V_30 = NULL ;
struct V_31 * V_32 ;
T_3 V_33 = V_27 -> V_34 ;
struct V_35 * V_36 ;
T_3 V_37 ;
struct V_38 * V_39 ;
int V_11 ;
V_11 = F_18 ( V_4 -> V_14 , V_33 , & V_30 ) ;
if ( F_8 ( V_11 != 0 ) ) {
F_9 ( L_4 ) ;
return - V_7 ;
}
V_32 = & V_30 -> V_40 ;
if ( F_8 ( V_4 -> V_41 >= V_42 ) ) {
F_9 ( L_5
L_6 ) ;
V_11 = - V_7 ;
goto V_43;
}
V_36 = & V_4 -> V_44 [ V_4 -> V_41 ++ ] ;
V_36 -> V_45 = V_27 ;
V_37 = F_19 ( V_32 , V_4 -> V_46 ) ;
if ( F_8 ( V_37 >= V_47 ) ) {
F_9 ( L_7
L_8 ) ;
V_11 = - V_7 ;
goto V_43;
}
V_36 -> V_48 = V_37 ;
if ( F_8 ( V_37 == V_4 -> V_46 ) ) {
V_39 = & V_4 -> V_49 [ V_37 ] ;
V_39 -> V_32 = F_20 ( V_32 ) ;
V_39 -> V_50 = ( void * ) V_2 ;
F_21 ( & V_39 -> V_51 , & V_4 -> V_52 ) ;
++ V_4 -> V_46 ;
}
* V_29 = V_30 ;
return 0 ;
V_43:
F_22 ( & V_30 ) ;
V_29 = NULL ;
return V_11 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 )
{
struct V_28 * V_30 ;
struct V_53 {
T_1 V_5 ;
T_10 V_54 ;
} * V_10 ;
int V_11 ;
V_10 = F_5 ( V_5 , struct V_53 , V_5 ) ;
V_11 = F_4 ( V_2 , V_4 , V_5 ) ;
if ( F_8 ( V_11 != 0 ) )
return V_11 ;
V_11 = F_17 ( V_2 , V_4 ,
& V_10 -> V_54 . V_55 ,
& V_30 ) ;
if ( F_8 ( V_11 != 0 ) )
return V_11 ;
F_22 ( & V_30 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 )
{
struct V_28 * V_30 ;
struct V_53 {
T_1 V_5 ;
T_11 V_54 ;
} * V_10 ;
int V_11 ;
V_10 = F_5 ( V_5 , struct V_53 , V_5 ) ;
V_11 = F_4 ( V_2 , V_4 , V_5 ) ;
if ( F_8 ( V_11 != 0 ) )
return V_11 ;
V_11 = F_17 ( V_2 , V_4 ,
& V_10 -> V_54 . V_55 ,
& V_30 ) ;
if ( F_8 ( V_11 != 0 ) )
return V_11 ;
F_22 ( & V_30 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 )
{
struct V_28 * V_30 = NULL ;
struct V_31 * V_32 ;
struct V_56 * V_57 = NULL ;
struct V_58 {
T_1 V_5 ;
T_12 V_59 ;
} * V_10 ;
int V_11 ;
V_10 = F_5 ( V_5 , struct V_58 , V_5 ) ;
V_11 = F_17 ( V_2 , V_4 ,
& V_10 -> V_59 . V_60 . V_27 ,
& V_30 ) ;
if ( F_8 ( V_11 != 0 ) )
return V_11 ;
V_32 = & V_30 -> V_40 ;
V_11 = F_26 ( V_2 , V_4 -> V_14 ,
V_10 -> V_59 . V_61 . V_15 , & V_57 ) ;
if ( V_11 ) {
F_9 ( L_9 ) ;
goto V_43;
}
V_10 -> V_59 . V_61 . V_15 = V_57 -> V_62 . V_63 ;
F_27 ( V_57 , V_4 -> V_14 , V_32 , V_5 ) ;
F_28 ( & V_57 ) ;
V_43:
F_22 ( & V_30 ) ;
return V_11 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 )
{
struct V_64 {
T_1 V_5 ;
T_13 V_22 ;
} * V_10 ;
T_14 * V_65 = ( T_14 * ) (
( unsigned long ) V_5 + sizeof( * V_10 ) ) ;
T_15 * V_66 ;
T_3 V_67 ;
T_3 V_68 ;
int V_11 ;
V_11 = F_4 ( V_2 , V_4 , V_5 ) ;
if ( F_8 ( V_11 != 0 ) )
return V_11 ;
V_10 = F_5 ( V_5 , struct V_64 , V_5 ) ;
V_68 = ( V_5 -> V_69 - sizeof( V_10 -> V_22 ) ) / sizeof( * V_65 ) ;
if ( F_8 ( V_10 -> V_22 . V_70 > V_68 ) ) {
F_9 ( L_10 ) ;
return - V_7 ;
}
for ( V_67 = 0 ; V_67 < V_10 -> V_22 . V_70 ; ++ V_67 , ++ V_65 ) {
V_11 = F_10 ( V_2 , V_4 ,
& V_65 -> V_71 . V_72 ) ;
if ( F_8 ( V_11 != 0 ) )
return V_11 ;
}
V_68 = ( V_5 -> V_69 - sizeof( V_10 -> V_22 ) -
V_10 -> V_22 . V_70 * sizeof( * V_65 ) ) / sizeof( * V_66 ) ;
if ( F_8 ( V_10 -> V_22 . V_73 > V_68 ) ) {
F_9 ( L_11 ) ;
return - V_7 ;
}
V_66 = ( T_15 * ) V_65 ;
for ( V_67 = 0 ; V_67 < V_10 -> V_22 . V_73 ; ++ V_67 , ++ V_66 ) {
V_11 = F_10 ( V_2 , V_4 ,
& V_66 -> V_74 . V_72 ) ;
if ( F_8 ( V_11 != 0 ) )
return V_11 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 )
{
struct V_75 {
T_1 V_5 ;
T_16 V_76 ;
};
T_17 * V_77 = ( T_17 * )
( ( unsigned long ) V_5 + V_5 -> V_69 + sizeof( V_5 ) ) ;
T_17 * V_78 = ( T_17 * )
( ( unsigned long ) V_5 + sizeof( struct V_75 ) ) ;
int V_11 ;
V_11 = F_4 ( V_2 , V_4 , V_5 ) ;
if ( F_8 ( V_11 != 0 ) )
return V_11 ;
for (; V_78 < V_77 ; ++ V_78 ) {
if ( F_6 ( V_78 -> V_79 != V_80 ) )
continue;
V_11 = F_10 ( V_2 , V_4 ,
& V_78 -> V_81 ) ;
if ( F_8 ( V_11 != 0 ) )
return V_11 ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_82 , T_3 * V_69 )
{
T_3 V_83 ;
T_3 V_84 = * V_69 ;
T_1 * V_5 = ( T_1 * ) V_82 ;
int V_11 ;
V_83 = ( ( T_3 * ) V_82 ) [ 0 ] ;
if ( V_83 == V_85 ) {
* V_69 = 5 << 2 ;
return 0 ;
}
V_83 = F_32 ( V_5 -> V_63 ) ;
* V_69 = F_32 ( V_5 -> V_69 ) + sizeof( T_1 ) ;
V_83 -= V_86 ;
if ( F_8 ( * V_69 > V_84 ) )
goto V_87;
if ( F_8 ( V_83 >= V_88 - V_86 ) )
goto V_87;
V_11 = V_89 [ V_83 ] ( V_2 , V_4 , V_5 ) ;
if ( F_8 ( V_11 != 0 ) )
goto V_87;
return 0 ;
V_87:
F_9 ( L_12 ,
V_83 + V_86 ) ;
return - V_7 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_82 , T_3 V_69 )
{
T_18 V_90 = V_69 ;
int V_11 ;
while ( V_90 > 0 ) {
V_69 = V_90 ;
V_11 = F_31 ( V_2 , V_4 , V_82 , & V_69 ) ;
if ( F_8 ( V_11 != 0 ) )
return V_11 ;
V_82 = ( void * ) ( ( unsigned long ) V_82 + V_69 ) ;
V_90 -= V_69 ;
}
if ( F_8 ( V_90 != 0 ) ) {
F_9 ( L_13 ) ;
return - V_7 ;
}
return 0 ;
}
static void F_34 ( struct V_3 * V_4 )
{
V_4 -> V_41 = 0 ;
}
static void F_35 ( struct V_3 * V_4 )
{
T_3 V_67 ;
struct V_35 * V_36 ;
struct V_38 * V_91 ;
struct V_31 * V_32 ;
for ( V_67 = 0 ; V_67 < V_4 -> V_41 ; ++ V_67 ) {
V_36 = & V_4 -> V_44 [ V_67 ] ;
V_91 = & V_4 -> V_49 [ V_36 -> V_48 ] ;
V_32 = V_91 -> V_32 ;
if ( V_32 -> V_92 . V_93 == V_94 ) {
V_36 -> V_45 -> V_95 += V_32 -> V_95 ;
V_36 -> V_45 -> V_34 = V_96 ;
} else
V_36 -> V_45 -> V_34 = V_32 -> V_92 . V_97 ;
}
F_34 ( V_4 ) ;
}
static void F_36 ( struct V_3 * V_4 )
{
struct V_38 * V_98 , * V_99 ;
F_37 (entry, next, &sw_context->validate_nodes,
head) {
F_38 ( & V_98 -> V_51 ) ;
F_39 ( V_98 -> V_32 ) ;
F_40 ( & V_98 -> V_32 ) ;
V_4 -> V_46 -- ;
}
F_41 ( V_4 -> V_46 != 0 ) ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
int V_11 ;
V_11 = F_43 ( V_32 , & V_100 , true , false , false ) ;
if ( F_6 ( V_11 == 0 || V_11 == - V_101 ) )
return V_11 ;
F_44 ( L_14 ) ;
V_11 = F_43 ( V_32 , & V_102 , true , false , false ) ;
return V_11 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_38 * V_98 ;
int V_11 ;
F_46 (entry, &sw_context->validate_nodes, head) {
V_11 = F_42 ( V_2 , V_98 -> V_32 ) ;
if ( F_8 ( V_11 != 0 ) )
return V_11 ;
}
return 0 ;
}
int F_47 ( struct V_103 * V_104 , void * V_105 ,
struct V_106 * V_107 )
{
struct V_1 * V_2 = F_48 ( V_104 ) ;
struct V_108 * V_109 = (struct V_108 * ) V_105 ;
struct V_110 V_111 ;
struct V_110 T_19 * V_112 ;
int V_11 ;
void * V_113 ;
void * V_10 ;
T_3 V_114 ;
struct V_3 * V_4 = & V_2 -> V_115 ;
struct V_116 * V_117 = V_116 ( V_107 -> V_118 ) ;
V_11 = F_49 ( & V_117 -> V_119 , true ) ;
if ( F_8 ( V_11 != 0 ) )
return V_11 ;
V_11 = F_50 ( & V_2 -> V_120 ) ;
if ( F_8 ( V_11 != 0 ) ) {
V_11 = - V_101 ;
goto V_121;
}
V_10 = F_51 ( V_2 , V_109 -> V_122 ) ;
if ( F_8 ( V_10 == NULL ) ) {
F_9 ( L_15 ) ;
V_11 = - V_123 ;
goto V_124;
}
V_113 = ( void T_19 * ) ( unsigned long ) V_109 -> V_125 ;
V_11 = F_52 ( V_10 , V_113 , V_109 -> V_122 ) ;
if ( F_8 ( V_11 != 0 ) ) {
V_11 = - V_126 ;
F_9 ( L_16 ) ;
goto V_127;
}
V_4 -> V_14 = F_53 ( V_107 ) -> V_14 ;
V_4 -> V_12 = false ;
V_4 -> V_17 = false ;
V_4 -> V_41 = 0 ;
V_4 -> V_46 = 0 ;
F_54 ( & V_4 -> V_52 ) ;
V_11 = F_33 ( V_2 , V_4 , V_10 , V_109 -> V_122 ) ;
if ( F_8 ( V_11 != 0 ) )
goto V_87;
V_11 = F_55 ( & V_4 -> V_52 ) ;
if ( F_8 ( V_11 != 0 ) )
goto V_87;
V_11 = F_45 ( V_2 , V_4 ) ;
if ( F_8 ( V_11 != 0 ) )
goto V_87;
F_35 ( V_4 ) ;
if ( V_109 -> V_128 ) {
V_11 = F_56 ( V_2 , & V_2 -> V_129 . V_130 ,
V_109 -> V_128 ) ;
if ( F_8 ( V_11 != 0 ) )
goto V_87;
}
F_57 ( V_2 , V_109 -> V_122 ) ;
V_11 = F_58 ( V_2 , & V_114 ) ;
F_59 ( & V_4 -> V_52 ,
( void * ) ( unsigned long ) V_114 ) ;
F_36 ( V_4 ) ;
F_60 ( & V_2 -> V_120 ) ;
if ( V_11 != 0 )
F_9 ( L_17 ) ;
V_111 . error = V_11 ;
V_111 . V_131 = ( V_132 ) V_114 ;
V_111 . V_133 = 0 ;
V_112 = (struct V_110 T_19 * )
( unsigned long ) V_109 -> V_111 ;
V_11 = F_61 ( V_112 , & V_111 , sizeof( V_111 ) ) ;
F_62 ( V_2 ) ;
F_63 ( & V_117 -> V_119 ) ;
return 0 ;
V_87:
F_34 ( V_4 ) ;
F_64 ( & V_4 -> V_52 ) ;
F_36 ( V_4 ) ;
V_127:
F_57 ( V_2 , 0 ) ;
V_124:
F_60 ( & V_2 -> V_120 ) ;
V_121:
F_63 ( & V_117 -> V_119 ) ;
return V_11 ;
}
