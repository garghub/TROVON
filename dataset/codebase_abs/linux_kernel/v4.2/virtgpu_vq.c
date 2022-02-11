void F_1 ( struct V_1 * V_2 ,
T_1 * V_3 )
{
int V_4 ;
F_2 ( V_5 ) ;
F_3 ( & V_2 -> V_6 ) ;
V_4 = F_4 ( & V_2 -> V_7 , NULL , 1 , 0 , V_8 ) ;
F_5 ( & V_2 -> V_6 ) ;
F_6 () ;
* V_3 = V_4 ;
}
void F_7 ( struct V_1 * V_2 , T_1 V_9 )
{
F_3 ( & V_2 -> V_6 ) ;
F_8 ( & V_2 -> V_7 , V_9 ) ;
F_5 ( & V_2 -> V_6 ) ;
}
void F_9 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 -> V_15 ;
struct V_1 * V_2 = V_13 -> V_16 ;
F_10 ( & V_2 -> V_17 . V_18 ) ;
}
void F_11 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 -> V_15 ;
struct V_1 * V_2 = V_13 -> V_16 ;
F_10 ( & V_2 -> V_19 . V_18 ) ;
}
int F_12 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
int V_22 , V_23 , V_24 = 0 ;
void * V_25 ;
F_13 ( & V_2 -> V_26 ) ;
F_14 ( & V_2 -> V_27 ) ;
V_24 += F_15 ( V_2 -> V_17 . V_11 ) ;
V_24 += F_15 ( V_2 -> V_19 . V_11 ) ;
V_23 = V_24 * V_28 ;
F_16 ( L_1 ,
V_24 , V_28 , V_23 / 1024 ) ;
V_2 -> V_29 = F_17 ( V_23 , V_5 ) ;
if ( ! V_2 -> V_29 )
return - V_30 ;
for ( V_22 = 0 , V_25 = V_2 -> V_29 ;
V_22 < V_24 ;
V_22 ++ , V_25 += V_28 ) {
V_21 = V_25 ;
F_18 ( & V_21 -> V_31 , & V_2 -> V_26 ) ;
}
return 0 ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
int V_22 , V_24 = 0 ;
V_24 += F_15 ( V_2 -> V_17 . V_11 ) ;
V_24 += F_15 ( V_2 -> V_19 . V_11 ) ;
F_3 ( & V_2 -> V_27 ) ;
for ( V_22 = 0 ; V_22 < V_24 ; V_22 ++ ) {
if ( F_20 ( F_21 ( & V_2 -> V_26 ) ) )
return;
V_21 = F_22 ( & V_2 -> V_26 ,
struct V_20 , V_31 ) ;
F_23 ( & V_21 -> V_31 ) ;
}
F_5 ( & V_2 -> V_27 ) ;
F_24 ( V_2 -> V_29 ) ;
}
static struct V_20 *
F_25 ( struct V_1 * V_2 ,
int V_23 , int V_32 , void * V_33 ,
T_2 V_34 )
{
struct V_20 * V_21 ;
F_3 ( & V_2 -> V_27 ) ;
F_26 ( F_21 ( & V_2 -> V_26 ) ) ;
V_21 = F_22 ( & V_2 -> V_26 ,
struct V_20 , V_31 ) ;
F_23 ( & V_21 -> V_31 ) ;
F_5 ( & V_2 -> V_27 ) ;
memset ( V_21 , 0 , V_28 ) ;
F_26 ( V_23 > V_35 ) ;
V_21 -> V_36 = ( void * ) V_21 + sizeof( * V_21 ) ;
V_21 -> V_23 = V_23 ;
V_21 -> V_34 = V_34 ;
V_21 -> V_32 = V_32 ;
if ( V_32 <= V_37 )
V_21 -> V_33 = ( void * ) V_21 -> V_36 + V_23 ;
else
V_21 -> V_33 = V_33 ;
F_26 ( ! V_21 -> V_33 ) ;
return V_21 ;
}
static void * F_27 ( struct V_1 * V_2 ,
struct V_20 * * V_38 ,
int V_23 )
{
struct V_20 * V_21 ;
V_21 = F_25 ( V_2 , V_23 ,
sizeof( struct V_39 ) ,
NULL , NULL ) ;
if ( F_28 ( V_21 ) ) {
* V_38 = NULL ;
return F_29 ( V_21 ) ;
}
* V_38 = V_21 ;
return V_21 -> V_36 ;
}
static struct V_40 *
F_30 ( struct V_1 * V_2 ,
struct V_20 * * V_38 )
{
struct V_20 * V_21 ;
V_21 = F_25
( V_2 , sizeof( struct V_40 ) ,
0 , NULL , NULL ) ;
if ( F_28 ( V_21 ) ) {
* V_38 = NULL ;
return F_29 ( V_21 ) ;
}
* V_38 = V_21 ;
return (struct V_40 * ) V_21 -> V_36 ;
}
static void * F_31 ( struct V_1 * V_2 ,
T_2 V_41 ,
struct V_20 * * V_38 ,
int V_42 , int V_32 ,
void * V_33 )
{
struct V_20 * V_21 ;
V_21 = F_25 ( V_2 , V_42 ,
V_32 , V_33 , V_41 ) ;
if ( F_28 ( V_21 ) ) {
* V_38 = NULL ;
return F_29 ( V_21 ) ;
}
* V_38 = V_21 ;
return (struct V_43 * ) V_21 -> V_36 ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
if ( V_21 -> V_32 > V_37 )
F_24 ( V_21 -> V_33 ) ;
F_24 ( V_21 -> V_44 ) ;
F_3 ( & V_2 -> V_27 ) ;
F_18 ( & V_21 -> V_31 , & V_2 -> V_26 ) ;
F_5 ( & V_2 -> V_27 ) ;
}
static void F_33 ( struct V_10 * V_11 , struct V_45 * V_46 )
{
struct V_20 * V_21 ;
unsigned int V_47 ;
int V_48 = 0 ;
while ( ( V_21 = F_34 ( V_11 , & V_47 ) ) ) {
F_35 ( & V_21 -> V_31 , V_46 ) ;
V_48 ++ ;
}
if ( V_48 == 0 )
F_36 ( L_2 ) ;
}
void F_37 ( struct V_49 * V_50 )
{
struct V_1 * V_2 =
F_38 ( V_50 , struct V_1 ,
V_17 . V_18 ) ;
struct V_45 V_46 ;
struct V_20 * V_51 , * V_52 ;
struct V_39 * V_53 ;
T_3 V_54 = 0 ;
F_13 ( & V_46 ) ;
F_3 ( & V_2 -> V_17 . V_55 ) ;
do {
F_39 ( V_2 -> V_17 . V_11 ) ;
F_33 ( V_2 -> V_17 . V_11 , & V_46 ) ;
} while ( ! F_40 ( V_2 -> V_17 . V_11 ) );
F_5 ( & V_2 -> V_17 . V_55 ) ;
F_41 (entry, tmp, &reclaim_list, list) {
V_53 = (struct V_39 * ) V_51 -> V_33 ;
if ( V_53 -> type != F_42 ( V_56 ) )
F_36 ( L_3 , F_43 ( V_53 -> type ) ) ;
if ( V_53 -> V_57 & F_42 ( V_58 ) ) {
T_3 V_59 = F_44 ( V_53 -> V_54 ) ;
if ( V_54 > V_59 ) {
F_45 ( L_4 ,
V_60 , V_54 , V_59 ) ;
} else {
V_54 = V_59 ;
}
}
if ( V_51 -> V_34 )
V_51 -> V_34 ( V_2 , V_51 ) ;
F_23 ( & V_51 -> V_31 ) ;
F_32 ( V_2 , V_51 ) ;
}
F_46 ( & V_2 -> V_17 . V_61 ) ;
if ( V_54 )
F_47 ( V_2 , V_54 ) ;
}
void F_48 ( struct V_49 * V_50 )
{
struct V_1 * V_2 =
F_38 ( V_50 , struct V_1 ,
V_19 . V_18 ) ;
struct V_45 V_46 ;
struct V_20 * V_51 , * V_52 ;
F_13 ( & V_46 ) ;
F_3 ( & V_2 -> V_19 . V_55 ) ;
do {
F_39 ( V_2 -> V_19 . V_11 ) ;
F_33 ( V_2 -> V_19 . V_11 , & V_46 ) ;
} while ( ! F_40 ( V_2 -> V_19 . V_11 ) );
F_5 ( & V_2 -> V_19 . V_55 ) ;
F_41 (entry, tmp, &reclaim_list, list) {
F_23 ( & V_51 -> V_31 ) ;
F_32 ( V_2 , V_51 ) ;
}
F_46 ( & V_2 -> V_19 . V_61 ) ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_10 * V_11 = V_2 -> V_17 . V_11 ;
struct V_62 * V_63 [ 3 ] , V_64 , V_65 , V_66 ;
int V_67 = 0 , V_68 = 0 ;
int V_69 ;
if ( ! V_2 -> V_70 )
return - V_71 ;
F_50 ( & V_64 , V_21 -> V_36 , V_21 -> V_23 ) ;
V_63 [ V_67 + V_68 ] = & V_64 ;
V_67 ++ ;
if ( V_21 -> V_72 ) {
F_50 ( & V_65 , V_21 -> V_44 , V_21 -> V_72 ) ;
V_63 [ V_67 + V_68 ] = & V_65 ;
V_67 ++ ;
}
if ( V_21 -> V_32 ) {
F_50 ( & V_66 , V_21 -> V_33 , V_21 -> V_32 ) ;
V_63 [ V_67 + V_68 ] = & V_66 ;
V_68 ++ ;
}
F_3 ( & V_2 -> V_17 . V_55 ) ;
V_73:
V_69 = F_51 ( V_11 , V_63 , V_67 , V_68 , V_21 , V_74 ) ;
if ( V_69 == - V_75 ) {
F_5 ( & V_2 -> V_17 . V_55 ) ;
F_52 ( V_2 -> V_17 . V_61 , V_11 -> V_76 ) ;
F_3 ( & V_2 -> V_17 . V_55 ) ;
goto V_73;
} else {
F_53 ( V_11 ) ;
}
F_5 ( & V_2 -> V_17 . V_55 ) ;
if ( ! V_69 )
V_69 = V_11 -> V_76 ;
return V_69 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_10 * V_11 = V_2 -> V_19 . V_11 ;
struct V_62 * V_63 [ 1 ] , V_77 ;
int V_69 ;
int V_67 ;
if ( ! V_2 -> V_70 )
return - V_71 ;
F_50 ( & V_77 , V_21 -> V_36 , V_21 -> V_23 ) ;
V_63 [ 0 ] = & V_77 ;
V_67 = 1 ;
F_3 ( & V_2 -> V_19 . V_55 ) ;
V_73:
V_69 = F_51 ( V_11 , V_63 , V_67 , 0 , V_21 , V_74 ) ;
if ( V_69 == - V_75 ) {
F_5 ( & V_2 -> V_19 . V_55 ) ;
F_52 ( V_2 -> V_19 . V_61 , V_11 -> V_76 ) ;
F_3 ( & V_2 -> V_19 . V_55 ) ;
goto V_73;
} else {
F_53 ( V_11 ) ;
}
F_5 ( & V_2 -> V_19 . V_55 ) ;
if ( ! V_69 )
V_69 = V_11 -> V_76 ;
return V_69 ;
}
void F_55 ( struct V_1 * V_2 ,
T_1 V_78 ,
T_1 V_79 ,
T_1 V_80 ,
T_1 V_81 )
{
struct V_82 * V_83 ;
struct V_20 * V_21 ;
V_83 = F_27 ( V_2 , & V_21 , sizeof( * V_83 ) ) ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_83 -> V_84 . type = F_42 ( V_85 ) ;
V_83 -> V_78 = F_42 ( V_78 ) ;
V_83 -> V_79 = F_42 ( V_79 ) ;
V_83 -> V_80 = F_42 ( V_80 ) ;
V_83 -> V_81 = F_42 ( V_81 ) ;
F_49 ( V_2 , V_21 ) ;
}
void F_56 ( struct V_1 * V_2 ,
T_1 V_78 )
{
struct V_86 * V_83 ;
struct V_20 * V_21 ;
V_83 = F_27 ( V_2 , & V_21 , sizeof( * V_83 ) ) ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_83 -> V_84 . type = F_42 ( V_87 ) ;
V_83 -> V_78 = F_42 ( V_78 ) ;
F_49 ( V_2 , V_21 ) ;
}
void F_57 ( struct V_1 * V_2 ,
T_1 V_78 )
{
struct V_88 * V_83 ;
struct V_20 * V_21 ;
V_83 = F_27 ( V_2 , & V_21 , sizeof( * V_83 ) ) ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_83 -> V_84 . type = F_42 ( V_89 ) ;
V_83 -> V_78 = F_42 ( V_78 ) ;
F_49 ( V_2 , V_21 ) ;
}
void F_58 ( struct V_1 * V_2 ,
T_1 V_90 , T_1 V_78 ,
T_1 V_80 , T_1 V_81 ,
T_1 V_91 , T_1 V_92 )
{
struct V_93 * V_83 ;
struct V_20 * V_21 ;
V_83 = F_27 ( V_2 , & V_21 , sizeof( * V_83 ) ) ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_83 -> V_84 . type = F_42 ( V_94 ) ;
V_83 -> V_78 = F_42 ( V_78 ) ;
V_83 -> V_90 = F_42 ( V_90 ) ;
V_83 -> V_95 . V_80 = F_42 ( V_80 ) ;
V_83 -> V_95 . V_81 = F_42 ( V_81 ) ;
V_83 -> V_95 . V_91 = F_42 ( V_91 ) ;
V_83 -> V_95 . V_92 = F_42 ( V_92 ) ;
F_49 ( V_2 , V_21 ) ;
}
void F_59 ( struct V_1 * V_2 ,
T_1 V_78 ,
T_1 V_91 , T_1 V_92 ,
T_1 V_80 , T_1 V_81 )
{
struct V_96 * V_83 ;
struct V_20 * V_21 ;
V_83 = F_27 ( V_2 , & V_21 , sizeof( * V_83 ) ) ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_83 -> V_84 . type = F_42 ( V_97 ) ;
V_83 -> V_78 = F_42 ( V_78 ) ;
V_83 -> V_95 . V_80 = F_42 ( V_80 ) ;
V_83 -> V_95 . V_81 = F_42 ( V_81 ) ;
V_83 -> V_95 . V_91 = F_42 ( V_91 ) ;
V_83 -> V_95 . V_92 = F_42 ( V_92 ) ;
F_49 ( V_2 , V_21 ) ;
}
void F_60 ( struct V_1 * V_2 ,
T_1 V_78 , T_4 V_98 ,
T_5 V_80 , T_5 V_81 ,
T_5 V_91 , T_5 V_92 ,
struct V_99 * * V_100 )
{
struct V_101 * V_83 ;
struct V_20 * V_21 ;
V_83 = F_27 ( V_2 , & V_21 , sizeof( * V_83 ) ) ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_83 -> V_84 . type = F_42 ( V_102 ) ;
V_83 -> V_78 = F_42 ( V_78 ) ;
V_83 -> V_98 = F_61 ( V_98 ) ;
V_83 -> V_95 . V_80 = V_80 ;
V_83 -> V_95 . V_81 = V_81 ;
V_83 -> V_95 . V_91 = V_91 ;
V_83 -> V_95 . V_92 = V_92 ;
if ( V_100 )
F_62 ( V_2 , & V_83 -> V_84 , V_100 ) ;
F_49 ( V_2 , V_21 ) ;
}
static void
F_63 ( struct V_1 * V_2 ,
T_1 V_78 ,
struct V_103 * V_104 ,
T_1 V_105 ,
struct V_99 * * V_100 )
{
struct V_106 * V_83 ;
struct V_20 * V_21 ;
V_83 = F_27 ( V_2 , & V_21 , sizeof( * V_83 ) ) ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_83 -> V_84 . type = F_42 ( V_107 ) ;
V_83 -> V_78 = F_42 ( V_78 ) ;
V_83 -> V_108 = F_42 ( V_105 ) ;
V_21 -> V_44 = V_104 ;
V_21 -> V_72 = sizeof( * V_104 ) * V_105 ;
if ( V_100 )
F_62 ( V_2 , & V_83 -> V_84 , V_100 ) ;
F_49 ( V_2 , V_21 ) ;
}
static void F_64 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_109 * V_53 =
(struct V_109 * ) V_21 -> V_33 ;
int V_22 ;
F_3 ( & V_2 -> V_110 ) ;
for ( V_22 = 0 ; V_22 < V_2 -> V_111 ; V_22 ++ ) {
V_2 -> V_112 [ V_22 ] . V_113 = V_53 -> V_114 [ V_22 ] ;
if ( V_53 -> V_114 [ V_22 ] . V_115 ) {
F_36 ( L_5 , V_22 ,
F_43 ( V_53 -> V_114 [ V_22 ] . V_95 . V_80 ) ,
F_43 ( V_53 -> V_114 [ V_22 ] . V_95 . V_81 ) ,
F_43 ( V_53 -> V_114 [ V_22 ] . V_95 . V_91 ) ,
F_43 ( V_53 -> V_114 [ V_22 ] . V_95 . V_92 ) ) ;
} else {
F_36 ( L_6 , V_22 ) ;
}
}
V_2 -> V_116 = false ;
F_5 ( & V_2 -> V_110 ) ;
F_46 ( & V_2 -> V_117 ) ;
if ( ! F_65 ( V_2 -> V_118 ) )
F_66 ( V_2 -> V_118 ) ;
}
int F_67 ( struct V_1 * V_2 )
{
struct V_39 * V_83 ;
struct V_20 * V_21 ;
void * V_33 ;
V_33 = F_17 ( sizeof( struct V_109 ) ,
V_5 ) ;
if ( ! V_33 )
return - V_30 ;
V_83 = F_31
( V_2 , & F_64 , & V_21 ,
sizeof( * V_83 ) , sizeof( struct V_109 ) ,
V_33 ) ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_2 -> V_116 = true ;
V_83 -> type = F_42 ( V_119 ) ;
F_49 ( V_2 , V_21 ) ;
return 0 ;
}
int F_68 ( struct V_1 * V_2 ,
struct V_120 * V_121 ,
T_1 V_78 ,
struct V_99 * * V_100 )
{
struct V_103 * V_104 ;
struct V_62 * V_122 ;
int V_123 ;
if ( ! V_121 -> V_124 ) {
int V_69 ;
V_69 = F_69 ( V_2 , V_121 ) ;
if ( V_69 )
return V_69 ;
}
V_104 = F_70 ( V_121 -> V_124 -> V_105 ,
sizeof( struct V_103 ) ,
V_5 ) ;
if ( ! V_104 ) {
F_45 ( L_7 ) ;
return - V_30 ;
}
F_71 (obj->pages->sgl, sg, obj->pages->nents, si) {
V_104 [ V_123 ] . V_125 = F_61 ( F_72 ( V_122 ) ) ;
V_104 [ V_123 ] . V_126 = F_42 ( V_122 -> V_126 ) ;
V_104 [ V_123 ] . V_127 = 0 ;
}
F_63 ( V_2 , V_78 ,
V_104 , V_121 -> V_124 -> V_105 ,
V_100 ) ;
V_121 -> V_128 = V_78 ;
return 0 ;
}
void F_73 ( struct V_1 * V_2 ,
struct V_129 * V_130 )
{
struct V_20 * V_21 ;
struct V_40 * V_131 ;
V_130 -> V_132 . V_133 . V_90 = F_42 ( V_130 -> V_134 ) ;
V_131 = F_30 ( V_2 , & V_21 ) ;
memcpy ( V_131 , & V_130 -> V_132 , sizeof( V_130 -> V_132 ) ) ;
F_54 ( V_2 , V_21 ) ;
}
