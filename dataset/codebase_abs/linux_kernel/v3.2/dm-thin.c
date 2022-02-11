static T_1 F_1 ( unsigned V_1 )
{
T_1 V_2 = 128 ;
V_1 /= 4 ;
V_1 = F_2 ( V_1 , 8192u ) ;
while ( V_2 < V_1 )
V_2 <<= 1 ;
return V_2 ;
}
static struct V_3 * F_3 ( unsigned V_1 )
{
unsigned V_4 ;
T_1 V_5 = F_1 ( V_1 ) ;
T_2 V_6 = sizeof( struct V_3 ) +
( sizeof( struct V_7 ) * V_5 ) ;
struct V_3 * V_8 = F_4 ( V_6 , V_9 ) ;
if ( ! V_8 )
return NULL ;
F_5 ( & V_8 -> V_10 ) ;
V_8 -> V_11 = F_6 ( V_1 ,
sizeof( struct V_12 ) ) ;
if ( ! V_8 -> V_11 ) {
F_7 ( V_8 ) ;
return NULL ;
}
V_8 -> V_5 = V_5 ;
V_8 -> V_13 = V_5 - 1 ;
V_8 -> V_14 = (struct V_7 * ) ( V_8 + 1 ) ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ )
F_8 ( V_8 -> V_14 + V_4 ) ;
return V_8 ;
}
static void F_9 ( struct V_3 * V_8 )
{
F_10 ( V_8 -> V_11 ) ;
F_7 ( V_8 ) ;
}
static T_1 F_11 ( struct V_3 * V_8 , struct V_15 * V_16 )
{
const unsigned long V_17 = 4294967291UL ;
T_3 V_18 = V_16 -> V_19 * V_17 ;
return ( T_1 ) ( V_18 & V_8 -> V_13 ) ;
}
static int F_12 ( struct V_15 * V_20 , struct V_15 * V_21 )
{
return ( V_20 -> V_22 == V_21 -> V_22 ) &&
( V_20 -> V_23 == V_21 -> V_23 ) &&
( V_20 -> V_19 == V_21 -> V_19 ) ;
}
static struct V_12 * F_13 ( struct V_7 * V_24 ,
struct V_15 * V_16 )
{
struct V_12 * V_12 ;
struct V_25 * V_26 ;
F_14 (cell, tmp, bucket, list)
if ( F_12 ( & V_12 -> V_16 , V_16 ) )
return V_12 ;
return NULL ;
}
static int F_15 ( struct V_3 * V_8 , struct V_15 * V_16 ,
struct V_27 * V_28 , struct V_12 * * V_29 )
{
int V_30 ;
unsigned long V_31 ;
T_1 V_18 = F_11 ( V_8 , V_16 ) ;
struct V_12 * V_32 ( V_12 ) , * V_33 = NULL ;
F_16 ( V_18 > V_8 -> V_5 ) ;
F_17 ( & V_8 -> V_10 , V_31 ) ;
V_12 = F_13 ( V_8 -> V_14 + V_18 , V_16 ) ;
if ( ! V_12 ) {
F_18 ( & V_8 -> V_10 , V_31 ) ;
V_33 = F_19 ( V_8 -> V_11 , V_34 ) ;
F_17 ( & V_8 -> V_10 , V_31 ) ;
V_12 = F_13 ( V_8 -> V_14 + V_18 , V_16 ) ;
if ( ! V_12 ) {
V_12 = V_33 ;
V_33 = NULL ;
V_12 -> V_8 = V_8 ;
memcpy ( & V_12 -> V_16 , V_16 , sizeof( V_12 -> V_16 ) ) ;
V_12 -> V_35 = 0 ;
F_20 ( & V_12 -> V_36 ) ;
F_21 ( & V_12 -> V_37 , V_8 -> V_14 + V_18 ) ;
}
}
V_30 = V_12 -> V_35 ++ ;
F_22 ( & V_12 -> V_36 , V_28 ) ;
F_18 ( & V_8 -> V_10 , V_31 ) ;
if ( V_33 )
F_23 ( V_33 , V_8 -> V_11 ) ;
* V_29 = V_12 ;
return V_30 ;
}
static void F_24 ( struct V_12 * V_12 , struct V_38 * V_39 )
{
struct V_3 * V_8 = V_12 -> V_8 ;
F_25 ( & V_12 -> V_37 ) ;
if ( V_39 )
F_26 ( V_39 , & V_12 -> V_36 ) ;
F_23 ( V_12 , V_8 -> V_11 ) ;
}
static void F_27 ( struct V_12 * V_12 , struct V_38 * V_36 )
{
unsigned long V_31 ;
struct V_3 * V_8 = V_12 -> V_8 ;
F_17 ( & V_8 -> V_10 , V_31 ) ;
F_24 ( V_12 , V_36 ) ;
F_18 ( & V_8 -> V_10 , V_31 ) ;
}
static void F_28 ( struct V_12 * V_12 , struct V_27 * V_27 )
{
struct V_3 * V_8 = V_12 -> V_8 ;
struct V_38 V_36 ;
struct V_27 * V_40 ;
unsigned long V_31 ;
F_20 ( & V_36 ) ;
F_17 ( & V_8 -> V_10 , V_31 ) ;
F_24 ( V_12 , & V_36 ) ;
F_18 ( & V_8 -> V_10 , V_31 ) ;
V_40 = F_29 ( & V_36 ) ;
F_16 ( V_40 != V_27 ) ;
F_16 ( ! F_30 ( & V_36 ) ) ;
}
static void F_31 ( struct V_12 * V_12 )
{
struct V_3 * V_8 = V_12 -> V_8 ;
struct V_38 V_36 ;
struct V_27 * V_27 ;
unsigned long V_31 ;
F_20 ( & V_36 ) ;
F_17 ( & V_8 -> V_10 , V_31 ) ;
F_24 ( V_12 , & V_36 ) ;
F_18 ( & V_8 -> V_10 , V_31 ) ;
while ( ( V_27 = F_29 ( & V_36 ) ) )
F_32 ( V_27 ) ;
}
static void F_33 ( struct V_41 * V_42 )
{
int V_4 ;
F_5 ( & V_42 -> V_10 ) ;
V_42 -> V_43 = 0 ;
V_42 -> V_44 = 0 ;
for ( V_4 = 0 ; V_4 < V_45 ; V_4 ++ ) {
V_42 -> V_46 [ V_4 ] . V_42 = V_42 ;
V_42 -> V_46 [ V_4 ] . V_35 = 0 ;
F_34 ( & V_42 -> V_46 [ V_4 ] . V_47 ) ;
}
}
static struct V_48 * F_35 ( struct V_41 * V_42 )
{
unsigned long V_31 ;
struct V_48 * V_49 ;
F_17 ( & V_42 -> V_10 , V_31 ) ;
V_49 = V_42 -> V_46 + V_42 -> V_43 ;
V_49 -> V_35 ++ ;
F_18 ( & V_42 -> V_10 , V_31 ) ;
return V_49 ;
}
static unsigned F_36 ( unsigned V_50 )
{
return ( V_50 + 1 ) % V_45 ;
}
static void F_37 ( struct V_41 * V_42 , struct V_51 * V_52 )
{
while ( ( V_42 -> V_44 != V_42 -> V_43 ) &&
! V_42 -> V_46 [ V_42 -> V_44 ] . V_35 ) {
F_38 ( & V_42 -> V_46 [ V_42 -> V_44 ] . V_47 , V_52 ) ;
V_42 -> V_44 = F_36 ( V_42 -> V_44 ) ;
}
if ( ( V_42 -> V_44 == V_42 -> V_43 ) && ! V_42 -> V_46 [ V_42 -> V_44 ] . V_35 )
F_38 ( & V_42 -> V_46 [ V_42 -> V_44 ] . V_47 , V_52 ) ;
}
static void F_39 ( struct V_48 * V_49 , struct V_51 * V_52 )
{
unsigned long V_31 ;
F_17 ( & V_49 -> V_42 -> V_10 , V_31 ) ;
F_16 ( ! V_49 -> V_35 ) ;
-- V_49 -> V_35 ;
F_37 ( V_49 -> V_42 , V_52 ) ;
F_18 ( & V_49 -> V_42 -> V_10 , V_31 ) ;
}
static int F_40 ( struct V_41 * V_42 , struct V_51 * V_53 )
{
int V_30 = 1 ;
unsigned long V_31 ;
unsigned V_54 ;
F_17 ( & V_42 -> V_10 , V_31 ) ;
if ( ( V_42 -> V_44 == V_42 -> V_43 ) &&
! V_42 -> V_46 [ V_42 -> V_43 ] . V_35 )
V_30 = 0 ;
else {
F_41 ( V_53 , & V_42 -> V_46 [ V_42 -> V_43 ] . V_47 ) ;
V_54 = F_36 ( V_42 -> V_43 ) ;
if ( ! V_42 -> V_46 [ V_54 ] . V_35 )
V_42 -> V_43 = V_54 ;
}
F_18 ( & V_42 -> V_10 , V_31 ) ;
return V_30 ;
}
static void F_42 ( struct V_55 * V_56 ,
T_4 V_40 , struct V_15 * V_16 )
{
V_16 -> V_22 = 0 ;
V_16 -> V_23 = F_43 ( V_56 ) ;
V_16 -> V_19 = V_40 ;
}
static void F_44 ( struct V_55 * V_56 , T_4 V_40 ,
struct V_15 * V_16 )
{
V_16 -> V_22 = 1 ;
V_16 -> V_23 = F_43 ( V_56 ) ;
V_16 -> V_19 = V_40 ;
}
static void F_45 ( void )
{
F_46 ( & V_57 . V_58 ) ;
F_34 ( & V_57 . V_59 ) ;
}
static void F_47 ( struct V_60 * V_60 )
{
F_16 ( ! F_48 ( & V_57 . V_58 ) ) ;
F_41 ( & V_60 -> V_37 , & V_57 . V_59 ) ;
}
static void F_49 ( struct V_60 * V_60 )
{
F_16 ( ! F_48 ( & V_57 . V_58 ) ) ;
F_50 ( & V_60 -> V_37 ) ;
}
static struct V_60 * F_51 ( struct V_61 * V_62 )
{
struct V_60 * V_60 = NULL , * V_26 ;
F_16 ( ! F_48 ( & V_57 . V_58 ) ) ;
F_52 (tmp, &dm_thin_pool_table.pools, list) {
if ( V_26 -> V_63 == V_62 ) {
V_60 = V_26 ;
break;
}
}
return V_60 ;
}
static struct V_60 * F_53 ( struct V_64 * V_65 )
{
struct V_60 * V_60 = NULL , * V_26 ;
F_16 ( ! F_48 ( & V_57 . V_58 ) ) ;
F_52 (tmp, &dm_thin_pool_table.pools, list) {
if ( V_26 -> V_65 == V_65 ) {
V_60 = V_26 ;
break;
}
}
return V_60 ;
}
static void F_54 ( struct V_66 * V_67 , struct V_38 * V_68 )
{
struct V_27 * V_27 ;
struct V_38 V_36 ;
F_20 ( & V_36 ) ;
F_26 ( & V_36 , V_68 ) ;
F_20 ( V_68 ) ;
while ( ( V_27 = F_29 ( & V_36 ) ) ) {
if ( F_55 ( V_27 ) -> V_69 == V_67 )
F_56 ( V_27 , V_70 ) ;
else
F_22 ( V_68 , V_27 ) ;
}
}
static void F_57 ( struct V_66 * V_67 )
{
struct V_60 * V_60 = V_67 -> V_60 ;
unsigned long V_31 ;
F_17 ( & V_60 -> V_10 , V_31 ) ;
F_54 ( V_67 , & V_60 -> V_71 ) ;
F_54 ( V_67 , & V_60 -> V_72 ) ;
F_18 ( & V_60 -> V_10 , V_31 ) ;
}
static T_4 F_58 ( struct V_66 * V_67 , struct V_27 * V_27 )
{
return V_27 -> V_73 >> V_67 -> V_60 -> V_74 ;
}
static void F_59 ( struct V_66 * V_67 , struct V_27 * V_27 , T_4 V_19 )
{
struct V_60 * V_60 = V_67 -> V_60 ;
V_27 -> V_75 = V_67 -> V_76 -> V_77 ;
V_27 -> V_73 = ( V_19 << V_60 -> V_74 ) +
( V_27 -> V_73 & V_60 -> V_78 ) ;
}
static void F_60 ( struct V_66 * V_67 , struct V_27 * V_27 ,
T_4 V_19 )
{
struct V_60 * V_60 = V_67 -> V_60 ;
unsigned long V_31 ;
F_59 ( V_67 , V_27 , V_19 ) ;
if ( V_27 -> V_79 & ( V_80 | V_81 ) ) {
F_17 ( & V_60 -> V_10 , V_31 ) ;
F_22 ( & V_60 -> V_82 , V_27 ) ;
F_18 ( & V_60 -> V_10 , V_31 ) ;
} else
F_61 ( V_27 ) ;
}
static void F_62 ( struct V_60 * V_60 )
{
F_63 ( V_60 -> V_83 , & V_60 -> V_84 ) ;
}
static void F_64 ( struct V_85 * V_86 )
{
struct V_60 * V_60 = V_86 -> V_67 -> V_60 ;
if ( F_65 ( & V_86 -> V_37 ) && V_86 -> V_87 ) {
F_41 ( & V_86 -> V_37 , & V_60 -> V_88 ) ;
F_62 ( V_60 ) ;
}
}
static void F_66 ( int V_89 , unsigned long V_90 , void * V_91 )
{
unsigned long V_31 ;
struct V_85 * V_86 = V_91 ;
struct V_60 * V_60 = V_86 -> V_67 -> V_60 ;
V_86 -> V_92 = V_89 || V_90 ? - V_93 : 0 ;
F_17 ( & V_60 -> V_10 , V_31 ) ;
V_86 -> V_87 = 1 ;
F_64 ( V_86 ) ;
F_18 ( & V_60 -> V_10 , V_31 ) ;
}
static void F_67 ( struct V_27 * V_27 , int V_92 )
{
unsigned long V_31 ;
struct V_85 * V_86 = F_55 ( V_27 ) -> V_69 ;
struct V_60 * V_60 = V_86 -> V_67 -> V_60 ;
V_86 -> V_92 = V_92 ;
F_17 ( & V_60 -> V_10 , V_31 ) ;
V_86 -> V_87 = 1 ;
F_64 ( V_86 ) ;
F_18 ( & V_60 -> V_10 , V_31 ) ;
}
static void F_68 ( struct V_27 * V_27 , int V_92 )
{
struct V_51 V_94 ;
struct V_85 * V_86 , * V_26 ;
struct V_95 * V_96 = F_55 ( V_27 ) -> V_69 ;
unsigned long V_31 ;
struct V_60 * V_60 = V_96 -> V_67 -> V_60 ;
V_27 -> V_97 = V_96 -> V_98 ;
F_56 ( V_27 , V_92 ) ;
F_34 ( & V_94 ) ;
F_39 ( V_96 -> V_49 , & V_94 ) ;
F_17 ( & V_60 -> V_10 , V_31 ) ;
F_69 (m, tmp, &mappings, list) {
F_50 ( & V_86 -> V_37 ) ;
F_34 ( & V_86 -> V_37 ) ;
F_64 ( V_86 ) ;
}
F_18 ( & V_60 -> V_10 , V_31 ) ;
F_23 ( V_96 , V_60 -> V_99 ) ;
}
static void F_70 ( struct V_66 * V_67 , struct V_12 * V_12 ,
T_4 V_100 )
{
struct V_60 * V_60 = V_67 -> V_60 ;
unsigned long V_31 ;
F_17 ( & V_60 -> V_10 , V_31 ) ;
F_27 ( V_12 , & V_60 -> V_71 ) ;
F_18 ( & V_67 -> V_60 -> V_10 , V_31 ) ;
F_62 ( V_60 ) ;
}
static void F_71 ( struct V_66 * V_67 , struct V_12 * V_12 ,
struct V_27 * V_101 )
{
struct V_38 V_36 ;
struct V_27 * V_27 ;
struct V_60 * V_60 = V_67 -> V_60 ;
unsigned long V_31 ;
F_20 ( & V_36 ) ;
F_27 ( V_12 , & V_36 ) ;
F_17 ( & V_60 -> V_10 , V_31 ) ;
while ( ( V_27 = F_29 ( & V_36 ) ) )
if ( V_27 != V_101 )
F_22 ( & V_60 -> V_71 , V_27 ) ;
F_18 ( & V_60 -> V_10 , V_31 ) ;
F_62 ( V_60 ) ;
}
static void F_72 ( struct V_85 * V_86 )
{
struct V_66 * V_67 = V_86 -> V_67 ;
struct V_27 * V_27 ;
int V_30 ;
V_27 = V_86 -> V_27 ;
if ( V_27 )
V_27 -> V_97 = V_86 -> V_98 ;
if ( V_86 -> V_92 ) {
F_31 ( V_86 -> V_12 ) ;
return;
}
V_30 = F_73 ( V_67 -> V_56 , V_86 -> V_102 , V_86 -> V_100 ) ;
if ( V_30 ) {
F_74 ( L_1 ) ;
F_31 ( V_86 -> V_12 ) ;
return;
}
if ( V_27 ) {
F_71 ( V_67 , V_86 -> V_12 , V_27 ) ;
F_56 ( V_27 , 0 ) ;
} else
F_70 ( V_67 , V_86 -> V_12 , V_86 -> V_100 ) ;
F_50 ( & V_86 -> V_37 ) ;
F_23 ( V_86 , V_67 -> V_60 -> V_103 ) ;
}
static void F_75 ( struct V_60 * V_60 )
{
unsigned long V_31 ;
struct V_51 V_104 ;
struct V_85 * V_86 , * V_26 ;
F_34 ( & V_104 ) ;
F_17 ( & V_60 -> V_10 , V_31 ) ;
F_38 ( & V_60 -> V_88 , & V_104 ) ;
F_18 ( & V_60 -> V_10 , V_31 ) ;
F_69 (m, tmp, &maps, list)
F_72 ( V_86 ) ;
}
static int F_76 ( struct V_60 * V_60 , struct V_27 * V_27 )
{
return ( ( F_77 ( V_27 ) == V_105 ) &&
! ( V_27 -> V_73 & V_60 -> V_78 ) ) &&
( V_27 -> V_106 == ( V_60 -> V_107 << V_108 ) ) ;
}
static void F_78 ( struct V_27 * V_27 , T_5 * * V_109 ,
T_5 * V_110 )
{
* V_109 = V_27 -> V_97 ;
V_27 -> V_97 = V_110 ;
}
static int F_79 ( struct V_60 * V_60 )
{
if ( V_60 -> V_111 )
return 0 ;
V_60 -> V_111 = F_19 ( V_60 -> V_103 , V_112 ) ;
return V_60 -> V_111 ? 0 : - V_113 ;
}
static struct V_85 * F_80 ( struct V_60 * V_60 )
{
struct V_85 * V_30 = V_60 -> V_111 ;
F_16 ( ! V_60 -> V_111 ) ;
V_60 -> V_111 = NULL ;
return V_30 ;
}
static void F_81 ( struct V_66 * V_67 , T_4 V_102 ,
T_4 V_114 , T_4 V_115 ,
struct V_12 * V_12 , struct V_27 * V_27 )
{
int V_30 ;
struct V_60 * V_60 = V_67 -> V_60 ;
struct V_85 * V_86 = F_80 ( V_60 ) ;
F_34 ( & V_86 -> V_37 ) ;
V_86 -> V_87 = 0 ;
V_86 -> V_67 = V_67 ;
V_86 -> V_102 = V_102 ;
V_86 -> V_100 = V_115 ;
V_86 -> V_12 = V_12 ;
V_86 -> V_92 = 0 ;
V_86 -> V_27 = NULL ;
F_40 ( & V_60 -> V_42 , & V_86 -> V_37 ) ;
if ( F_76 ( V_60 , V_27 ) ) {
V_86 -> V_27 = V_27 ;
F_78 ( V_27 , & V_86 -> V_98 , F_67 ) ;
F_55 ( V_27 ) -> V_69 = V_86 ;
F_60 ( V_67 , V_27 , V_115 ) ;
} else {
struct V_116 V_117 , V_118 ;
V_117 . V_77 = V_67 -> V_76 -> V_77 ;
V_117 . V_119 = V_114 * V_60 -> V_107 ;
V_117 . V_35 = V_60 -> V_107 ;
V_118 . V_77 = V_67 -> V_76 -> V_77 ;
V_118 . V_119 = V_115 * V_60 -> V_107 ;
V_118 . V_35 = V_60 -> V_107 ;
V_30 = F_82 ( V_60 -> V_120 , & V_117 , 1 , & V_118 ,
0 , F_66 , V_86 ) ;
if ( V_30 < 0 ) {
F_23 ( V_86 , V_60 -> V_103 ) ;
F_74 ( L_2 ) ;
F_31 ( V_12 ) ;
}
}
}
static void F_83 ( struct V_66 * V_67 , T_4 V_102 ,
T_4 V_100 , struct V_12 * V_12 ,
struct V_27 * V_27 )
{
struct V_60 * V_60 = V_67 -> V_60 ;
struct V_85 * V_86 = F_80 ( V_60 ) ;
F_34 ( & V_86 -> V_37 ) ;
V_86 -> V_87 = 0 ;
V_86 -> V_67 = V_67 ;
V_86 -> V_102 = V_102 ;
V_86 -> V_100 = V_100 ;
V_86 -> V_12 = V_12 ;
V_86 -> V_92 = 0 ;
V_86 -> V_27 = NULL ;
if ( ! V_60 -> V_121 )
F_72 ( V_86 ) ;
else if ( F_76 ( V_60 , V_27 ) ) {
V_86 -> V_27 = V_27 ;
F_78 ( V_27 , & V_86 -> V_98 , F_67 ) ;
F_55 ( V_27 ) -> V_69 = V_86 ;
F_60 ( V_67 , V_27 , V_100 ) ;
} else {
int V_30 ;
struct V_116 V_118 ;
V_118 . V_77 = V_67 -> V_76 -> V_77 ;
V_118 . V_119 = V_100 * V_60 -> V_107 ;
V_118 . V_35 = V_60 -> V_107 ;
V_30 = F_84 ( V_60 -> V_120 , 1 , & V_118 , 0 , F_66 , V_86 ) ;
if ( V_30 < 0 ) {
F_23 ( V_86 , V_60 -> V_103 ) ;
F_74 ( L_3 ) ;
F_31 ( V_12 ) ;
}
}
}
static int F_85 ( struct V_66 * V_67 , T_4 * V_122 )
{
int V_30 ;
T_4 V_123 ;
unsigned long V_31 ;
struct V_60 * V_60 = V_67 -> V_60 ;
V_30 = F_86 ( V_60 -> V_124 , & V_123 ) ;
if ( V_30 )
return V_30 ;
if ( V_123 <= V_60 -> V_125 && ! V_60 -> V_126 ) {
F_87 ( L_4 ,
F_88 ( V_60 -> V_63 ) ) ;
F_17 ( & V_60 -> V_10 , V_31 ) ;
V_60 -> V_126 = 1 ;
F_18 ( & V_60 -> V_10 , V_31 ) ;
F_89 ( V_60 -> V_127 -> V_128 ) ;
}
if ( ! V_123 ) {
if ( V_60 -> V_129 )
return - V_130 ;
else {
V_30 = F_90 ( V_60 -> V_124 ) ;
if ( V_30 ) {
F_74 ( L_5 ,
V_131 , V_30 ) ;
return V_30 ;
}
V_30 = F_86 ( V_60 -> V_124 , & V_123 ) ;
if ( V_30 )
return V_30 ;
if ( ! V_123 ) {
F_87 ( L_6 ,
F_88 ( V_60 -> V_63 ) ) ;
F_17 ( & V_60 -> V_10 , V_31 ) ;
V_60 -> V_129 = 1 ;
F_18 ( & V_60 -> V_10 , V_31 ) ;
return - V_130 ;
}
}
}
V_30 = F_91 ( V_60 -> V_124 , V_122 ) ;
if ( V_30 )
return V_30 ;
return 0 ;
}
static void F_92 ( struct V_27 * V_27 )
{
struct V_66 * V_67 = F_55 ( V_27 ) -> V_69 ;
struct V_60 * V_60 = V_67 -> V_60 ;
unsigned long V_31 ;
F_17 ( & V_60 -> V_10 , V_31 ) ;
F_22 ( & V_60 -> V_72 , V_27 ) ;
F_18 ( & V_60 -> V_10 , V_31 ) ;
}
static void F_93 ( struct V_12 * V_12 )
{
struct V_27 * V_27 ;
struct V_38 V_36 ;
F_20 ( & V_36 ) ;
F_27 ( V_12 , & V_36 ) ;
while ( ( V_27 = F_29 ( & V_36 ) ) )
F_92 ( V_27 ) ;
}
static void F_94 ( struct V_66 * V_67 , struct V_27 * V_27 , T_4 V_19 ,
struct V_15 * V_16 ,
struct V_132 * V_133 ,
struct V_12 * V_12 )
{
int V_30 ;
T_4 V_100 ;
V_30 = F_85 ( V_67 , & V_100 ) ;
switch ( V_30 ) {
case 0 :
F_81 ( V_67 , V_19 , V_133 -> V_19 ,
V_100 , V_12 , V_27 ) ;
break;
case - V_130 :
F_93 ( V_12 ) ;
break;
default:
F_74 ( L_7 , V_131 , V_30 ) ;
F_31 ( V_12 ) ;
break;
}
}
static void F_95 ( struct V_66 * V_67 , struct V_27 * V_27 ,
T_4 V_19 ,
struct V_132 * V_133 )
{
struct V_12 * V_12 ;
struct V_60 * V_60 = V_67 -> V_60 ;
struct V_15 V_16 ;
F_42 ( V_67 -> V_56 , V_133 -> V_19 , & V_16 ) ;
if ( F_15 ( V_60 -> V_8 , & V_16 , V_27 , & V_12 ) )
return;
if ( F_77 ( V_27 ) == V_105 )
F_94 ( V_67 , V_27 , V_19 , & V_16 , V_133 , V_12 ) ;
else {
struct V_95 * V_96 ;
V_96 = F_19 ( V_60 -> V_99 , V_34 ) ;
V_96 -> V_67 = V_67 ;
V_96 -> V_49 = F_35 ( & V_60 -> V_42 ) ;
F_78 ( V_27 , & V_96 -> V_98 , F_68 ) ;
F_55 ( V_27 ) -> V_69 = V_96 ;
F_28 ( V_12 , V_27 ) ;
F_60 ( V_67 , V_27 , V_133 -> V_19 ) ;
}
}
static void F_96 ( struct V_66 * V_67 , struct V_27 * V_27 , T_4 V_19 ,
struct V_12 * V_12 )
{
int V_30 ;
T_4 V_100 ;
if ( ! V_27 -> V_106 ) {
F_28 ( V_12 , V_27 ) ;
F_60 ( V_67 , V_27 , 0 ) ;
return;
}
if ( F_77 ( V_27 ) == V_134 ) {
F_97 ( V_27 ) ;
F_28 ( V_12 , V_27 ) ;
F_56 ( V_27 , 0 ) ;
return;
}
V_30 = F_85 ( V_67 , & V_100 ) ;
switch ( V_30 ) {
case 0 :
F_83 ( V_67 , V_19 , V_100 , V_12 , V_27 ) ;
break;
case - V_130 :
F_93 ( V_12 ) ;
break;
default:
F_74 ( L_7 , V_131 , V_30 ) ;
F_31 ( V_12 ) ;
break;
}
}
static void F_98 ( struct V_66 * V_67 , struct V_27 * V_27 )
{
int V_30 ;
T_4 V_19 = F_58 ( V_67 , V_27 ) ;
struct V_12 * V_12 ;
struct V_15 V_16 ;
struct V_132 V_133 ;
F_44 ( V_67 -> V_56 , V_19 , & V_16 ) ;
if ( F_15 ( V_67 -> V_60 -> V_8 , & V_16 , V_27 , & V_12 ) )
return;
V_30 = F_99 ( V_67 -> V_56 , V_19 , 1 , & V_133 ) ;
switch ( V_30 ) {
case 0 :
F_28 ( V_12 , V_27 ) ;
if ( V_133 . V_135 )
F_95 ( V_67 , V_27 , V_19 , & V_133 ) ;
else
F_60 ( V_67 , V_27 , V_133 . V_19 ) ;
break;
case - V_136 :
F_96 ( V_67 , V_27 , V_19 , V_12 ) ;
break;
default:
F_74 ( L_8 , V_30 ) ;
F_32 ( V_27 ) ;
break;
}
}
static void F_100 ( struct V_60 * V_60 )
{
unsigned long V_31 ;
struct V_27 * V_27 ;
struct V_38 V_36 ;
int V_30 ;
F_20 ( & V_36 ) ;
F_17 ( & V_60 -> V_10 , V_31 ) ;
F_26 ( & V_36 , & V_60 -> V_71 ) ;
F_20 ( & V_60 -> V_71 ) ;
F_18 ( & V_60 -> V_10 , V_31 ) ;
while ( ( V_27 = F_29 ( & V_36 ) ) ) {
struct V_66 * V_67 = F_55 ( V_27 ) -> V_69 ;
if ( F_79 ( V_60 ) ) {
F_17 ( & V_60 -> V_10 , V_31 ) ;
F_26 ( & V_60 -> V_71 , & V_36 ) ;
F_18 ( & V_60 -> V_10 , V_31 ) ;
break;
}
F_98 ( V_67 , V_27 ) ;
}
F_20 ( & V_36 ) ;
F_17 ( & V_60 -> V_10 , V_31 ) ;
F_26 ( & V_36 , & V_60 -> V_82 ) ;
F_20 ( & V_60 -> V_82 ) ;
F_18 ( & V_60 -> V_10 , V_31 ) ;
if ( F_30 ( & V_36 ) )
return;
V_30 = F_90 ( V_60 -> V_124 ) ;
if ( V_30 ) {
F_74 ( L_5 ,
V_131 , V_30 ) ;
while ( ( V_27 = F_29 ( & V_36 ) ) )
F_32 ( V_27 ) ;
return;
}
while ( ( V_27 = F_29 ( & V_36 ) ) )
F_61 ( V_27 ) ;
}
static void F_101 ( struct V_137 * V_138 )
{
struct V_60 * V_60 = F_102 ( V_138 , struct V_60 , V_84 ) ;
F_75 ( V_60 ) ;
F_100 ( V_60 ) ;
}
static void F_103 ( struct V_66 * V_67 , struct V_27 * V_27 )
{
unsigned long V_31 ;
struct V_60 * V_60 = V_67 -> V_60 ;
F_17 ( & V_60 -> V_10 , V_31 ) ;
F_22 ( & V_60 -> V_71 , V_27 ) ;
F_18 ( & V_60 -> V_10 , V_31 ) ;
F_62 ( V_60 ) ;
}
static int F_104 ( struct V_139 * V_127 , struct V_27 * V_27 ,
union V_140 * V_141 )
{
int V_30 ;
struct V_66 * V_67 = V_127 -> V_142 ;
T_4 V_19 = F_58 ( V_67 , V_27 ) ;
struct V_55 * V_56 = V_67 -> V_56 ;
struct V_132 V_122 ;
V_141 -> V_69 = V_67 ;
if ( V_27 -> V_79 & ( V_80 | V_81 ) ) {
F_103 ( V_67 , V_27 ) ;
return V_143 ;
}
V_30 = F_99 ( V_56 , V_19 , 0 , & V_122 ) ;
switch ( V_30 ) {
case 0 :
if ( F_105 ( V_122 . V_135 ) ) {
F_103 ( V_67 , V_27 ) ;
V_30 = V_143 ;
} else {
F_59 ( V_67 , V_27 , V_122 . V_19 ) ;
V_30 = V_144 ;
}
break;
case - V_136 :
case - V_145 :
F_103 ( V_67 , V_27 ) ;
V_30 = V_143 ;
break;
}
return V_30 ;
}
static int F_106 ( struct V_146 * V_147 , int V_148 )
{
int V_30 ;
unsigned long V_31 ;
struct V_149 * V_150 = F_102 ( V_147 , struct V_149 , V_151 ) ;
F_17 ( & V_150 -> V_60 -> V_10 , V_31 ) ;
V_30 = ! F_30 ( & V_150 -> V_60 -> V_72 ) ;
F_18 ( & V_150 -> V_60 -> V_10 , V_31 ) ;
if ( ! V_30 ) {
struct V_152 * V_153 = F_107 ( V_150 -> V_154 -> V_77 ) ;
V_30 = F_108 ( & V_153 -> V_155 , V_148 ) ;
}
return V_30 ;
}
static void F_109 ( struct V_60 * V_60 )
{
F_26 ( & V_60 -> V_71 , & V_60 -> V_72 ) ;
F_20 ( & V_60 -> V_72 ) ;
}
static int F_110 ( struct V_60 * V_60 , struct V_139 * V_127 )
{
struct V_149 * V_150 = V_127 -> V_142 ;
V_60 -> V_127 = V_127 ;
V_60 -> V_125 = V_150 -> V_125 ;
V_60 -> V_121 = V_150 -> V_121 ;
return 0 ;
}
static void F_111 ( struct V_60 * V_60 , struct V_139 * V_127 )
{
if ( V_60 -> V_127 == V_127 )
V_60 -> V_127 = NULL ;
}
static void F_112 ( struct V_60 * V_60 )
{
F_49 ( V_60 ) ;
if ( F_113 ( V_60 -> V_124 ) < 0 )
F_87 ( L_9 , V_131 ) ;
F_9 ( V_60 -> V_8 ) ;
F_114 ( V_60 -> V_120 ) ;
if ( V_60 -> V_83 )
F_115 ( V_60 -> V_83 ) ;
if ( V_60 -> V_111 )
F_23 ( V_60 -> V_111 , V_60 -> V_103 ) ;
F_10 ( V_60 -> V_103 ) ;
F_10 ( V_60 -> V_99 ) ;
F_7 ( V_60 ) ;
}
static struct V_60 * F_116 ( struct V_61 * V_63 ,
struct V_64 * V_156 ,
unsigned long V_157 , char * * error )
{
int V_30 ;
void * V_158 ;
struct V_60 * V_60 ;
struct V_159 * V_124 ;
V_124 = F_117 ( V_156 , V_157 ) ;
if ( F_118 ( V_124 ) ) {
* error = L_10 ;
return (struct V_60 * ) V_124 ;
}
V_60 = F_4 ( sizeof( * V_60 ) , V_9 ) ;
if ( ! V_60 ) {
* error = L_11 ;
V_158 = F_119 ( - V_113 ) ;
goto V_160;
}
V_60 -> V_124 = V_124 ;
V_60 -> V_107 = V_157 ;
V_60 -> V_74 = F_120 ( V_157 ) - 1 ;
V_60 -> V_78 = V_157 - 1 ;
V_60 -> V_125 = 0 ;
V_60 -> V_121 = 1 ;
V_60 -> V_8 = F_3 ( V_161 ) ;
if ( ! V_60 -> V_8 ) {
* error = L_12 ;
V_158 = F_119 ( - V_113 ) ;
goto V_162;
}
V_60 -> V_120 = F_121 () ;
if ( F_118 ( V_60 -> V_120 ) ) {
V_30 = F_122 ( V_60 -> V_120 ) ;
* error = L_13 ;
V_158 = F_119 ( V_30 ) ;
goto V_163;
}
V_60 -> V_83 = F_123 ( L_14 V_164 , V_165 ) ;
if ( ! V_60 -> V_83 ) {
* error = L_15 ;
V_158 = F_119 ( - V_113 ) ;
goto V_166;
}
F_124 ( & V_60 -> V_84 , F_101 ) ;
F_5 ( & V_60 -> V_10 ) ;
F_20 ( & V_60 -> V_71 ) ;
F_20 ( & V_60 -> V_82 ) ;
F_34 ( & V_60 -> V_88 ) ;
V_60 -> V_126 = 0 ;
V_60 -> V_129 = 0 ;
F_20 ( & V_60 -> V_72 ) ;
F_33 ( & V_60 -> V_42 ) ;
V_60 -> V_111 = NULL ;
V_60 -> V_103 =
F_6 ( V_167 , sizeof( struct V_85 ) ) ;
if ( ! V_60 -> V_103 ) {
* error = L_16 ;
V_158 = F_119 ( - V_113 ) ;
goto V_168;
}
V_60 -> V_99 =
F_6 ( V_169 , sizeof( struct V_95 ) ) ;
if ( ! V_60 -> V_99 ) {
* error = L_17 ;
V_158 = F_119 ( - V_113 ) ;
goto V_170;
}
V_60 -> V_171 = 1 ;
V_60 -> V_63 = V_63 ;
V_60 -> V_65 = V_156 ;
F_47 ( V_60 ) ;
return V_60 ;
V_170:
F_10 ( V_60 -> V_103 ) ;
V_168:
F_115 ( V_60 -> V_83 ) ;
V_166:
F_114 ( V_60 -> V_120 ) ;
V_163:
F_9 ( V_60 -> V_8 ) ;
V_162:
F_7 ( V_60 ) ;
V_160:
if ( F_113 ( V_124 ) )
F_87 ( L_9 , V_131 ) ;
return V_158 ;
}
static void F_125 ( struct V_60 * V_60 )
{
F_16 ( ! F_48 ( & V_57 . V_58 ) ) ;
V_60 -> V_171 ++ ;
}
static void F_126 ( struct V_60 * V_60 )
{
F_16 ( ! F_48 ( & V_57 . V_58 ) ) ;
F_16 ( ! V_60 -> V_171 ) ;
if ( ! -- V_60 -> V_171 )
F_112 ( V_60 ) ;
}
static struct V_60 * F_127 ( struct V_61 * V_63 ,
struct V_64 * V_156 ,
unsigned long V_157 , char * * error )
{
struct V_60 * V_60 = F_53 ( V_156 ) ;
if ( V_60 ) {
if ( V_60 -> V_63 != V_63 )
return F_119 ( - V_172 ) ;
F_125 ( V_60 ) ;
} else {
V_60 = F_51 ( V_63 ) ;
if ( V_60 ) {
if ( V_60 -> V_65 != V_156 )
return F_119 ( - V_173 ) ;
F_125 ( V_60 ) ;
} else
V_60 = F_116 ( V_63 , V_156 , V_157 , error ) ;
}
return V_60 ;
}
static void F_128 ( struct V_139 * V_127 )
{
struct V_149 * V_150 = V_127 -> V_142 ;
F_129 ( & V_57 . V_58 ) ;
F_111 ( V_150 -> V_60 , V_127 ) ;
F_126 ( V_150 -> V_60 ) ;
F_130 ( V_127 , V_150 -> V_156 ) ;
F_130 ( V_127 , V_150 -> V_154 ) ;
F_7 ( V_150 ) ;
F_131 ( & V_57 . V_58 ) ;
}
static int F_132 ( struct V_174 * V_175 , struct V_176 * V_177 ,
struct V_139 * V_127 )
{
int V_30 ;
unsigned V_178 ;
const char * V_179 ;
static struct V_180 V_181 [] = {
{ 0 , 1 , L_18 } ,
} ;
if ( ! V_175 -> V_178 )
return 0 ;
V_30 = F_133 ( V_181 , V_175 , & V_178 , & V_127 -> error ) ;
if ( V_30 )
return - V_173 ;
while ( V_178 && ! V_30 ) {
V_179 = F_134 ( V_175 ) ;
V_178 -- ;
if ( ! strcasecmp ( V_179 , L_19 ) ) {
V_177 -> V_121 = 0 ;
continue;
}
V_127 -> error = L_20 ;
V_30 = - V_173 ;
}
return V_30 ;
}
static int F_135 ( struct V_139 * V_127 , unsigned V_178 , char * * V_182 )
{
int V_30 ;
struct V_149 * V_150 ;
struct V_60 * V_60 ;
struct V_176 V_177 ;
struct V_174 V_175 ;
struct V_183 * V_154 ;
unsigned long V_157 ;
T_4 V_125 ;
struct V_183 * V_156 ;
T_6 V_184 ;
F_129 ( & V_57 . V_58 ) ;
if ( V_178 < 4 ) {
V_127 -> error = L_21 ;
V_30 = - V_173 ;
goto V_185;
}
V_175 . V_178 = V_178 ;
V_175 . V_182 = V_182 ;
V_30 = F_136 ( V_127 , V_182 [ 0 ] , V_186 | V_187 , & V_156 ) ;
if ( V_30 ) {
V_127 -> error = L_22 ;
goto V_185;
}
V_184 = F_137 ( V_156 -> V_77 -> V_188 ) >> V_108 ;
if ( V_184 > V_189 ) {
V_127 -> error = L_23 ;
V_30 = - V_173 ;
goto V_190;
}
V_30 = F_136 ( V_127 , V_182 [ 1 ] , V_186 | V_187 , & V_154 ) ;
if ( V_30 ) {
V_127 -> error = L_24 ;
goto V_190;
}
if ( F_138 ( V_182 [ 2 ] , 10 , & V_157 ) || ! V_157 ||
V_157 < V_191 ||
V_157 > V_192 ||
! F_139 ( V_157 ) ) {
V_127 -> error = L_25 ;
V_30 = - V_173 ;
goto V_193;
}
if ( F_140 ( V_182 [ 3 ] , 10 , ( unsigned long long * ) & V_125 ) ) {
V_127 -> error = L_26 ;
V_30 = - V_173 ;
goto V_193;
}
memset ( & V_177 , 0 , sizeof( V_177 ) ) ;
V_177 . V_121 = 1 ;
F_141 ( & V_175 , 4 ) ;
V_30 = F_132 ( & V_175 , & V_177 , V_127 ) ;
if ( V_30 )
goto V_193;
V_150 = F_142 ( sizeof( * V_150 ) , V_9 ) ;
if ( ! V_150 ) {
V_30 = - V_113 ;
goto V_193;
}
V_60 = F_127 ( F_143 ( V_127 -> V_128 ) , V_156 -> V_77 ,
V_157 , & V_127 -> error ) ;
if ( F_118 ( V_60 ) ) {
V_30 = F_122 ( V_60 ) ;
goto V_194;
}
V_150 -> V_60 = V_60 ;
V_150 -> V_127 = V_127 ;
V_150 -> V_156 = V_156 ;
V_150 -> V_154 = V_154 ;
V_150 -> V_125 = V_125 ;
V_150 -> V_121 = V_177 . V_121 ;
V_127 -> V_195 = 1 ;
V_127 -> V_196 = 0 ;
V_127 -> V_142 = V_150 ;
V_150 -> V_151 . V_197 = F_106 ;
F_144 ( V_127 -> V_128 , & V_150 -> V_151 ) ;
F_131 ( & V_57 . V_58 ) ;
return 0 ;
V_194:
F_7 ( V_150 ) ;
V_193:
F_130 ( V_127 , V_154 ) ;
V_190:
F_130 ( V_127 , V_156 ) ;
V_185:
F_131 ( & V_57 . V_58 ) ;
return V_30 ;
}
static int F_145 ( struct V_139 * V_127 , struct V_27 * V_27 ,
union V_140 * V_141 )
{
int V_30 ;
struct V_149 * V_150 = V_127 -> V_142 ;
struct V_60 * V_60 = V_150 -> V_60 ;
unsigned long V_31 ;
F_17 ( & V_60 -> V_10 , V_31 ) ;
V_27 -> V_75 = V_150 -> V_154 -> V_77 ;
V_30 = V_144 ;
F_18 ( & V_60 -> V_10 , V_31 ) ;
return V_30 ;
}
static int F_146 ( struct V_139 * V_127 )
{
int V_30 ;
struct V_149 * V_150 = V_127 -> V_142 ;
struct V_60 * V_60 = V_150 -> V_60 ;
T_4 V_198 , V_199 ;
V_30 = F_110 ( V_60 , V_127 ) ;
if ( V_30 )
return V_30 ;
V_198 = V_127 -> V_6 >> V_60 -> V_74 ;
V_30 = F_147 ( V_60 -> V_124 , & V_199 ) ;
if ( V_30 ) {
F_74 ( L_27 ) ;
return V_30 ;
}
if ( V_198 < V_199 ) {
F_74 ( L_28 ,
V_198 , V_199 ) ;
return - V_173 ;
} else if ( V_198 > V_199 ) {
V_30 = F_148 ( V_60 -> V_124 , V_198 ) ;
if ( V_30 ) {
F_74 ( L_29 ) ;
return V_30 ;
}
V_30 = F_90 ( V_60 -> V_124 ) ;
if ( V_30 ) {
F_74 ( L_5 ,
V_131 , V_30 ) ;
return V_30 ;
}
}
return 0 ;
}
static void F_149 ( struct V_139 * V_127 )
{
struct V_149 * V_150 = V_127 -> V_142 ;
struct V_60 * V_60 = V_150 -> V_60 ;
unsigned long V_31 ;
F_17 ( & V_60 -> V_10 , V_31 ) ;
V_60 -> V_126 = 0 ;
V_60 -> V_129 = 0 ;
F_109 ( V_60 ) ;
F_18 ( & V_60 -> V_10 , V_31 ) ;
F_62 ( V_60 ) ;
}
static void F_150 ( struct V_139 * V_127 )
{
int V_30 ;
struct V_149 * V_150 = V_127 -> V_142 ;
struct V_60 * V_60 = V_150 -> V_60 ;
F_151 ( V_60 -> V_83 ) ;
V_30 = F_90 ( V_60 -> V_124 ) ;
if ( V_30 < 0 ) {
F_74 ( L_5 ,
V_131 , V_30 ) ;
}
}
static int F_152 ( unsigned V_178 , unsigned V_200 )
{
if ( V_178 != V_200 ) {
F_87 ( L_30 ,
V_178 , V_200 ) ;
return - V_173 ;
}
return 0 ;
}
static int F_153 ( char * V_201 , T_7 * V_202 , int V_203 )
{
if ( ! F_140 ( V_201 , 10 , ( unsigned long long * ) V_202 ) &&
* V_202 <= V_204 )
return 0 ;
if ( V_203 )
F_87 ( L_31 , V_201 ) ;
return - V_173 ;
}
static int F_154 ( unsigned V_178 , char * * V_182 , struct V_60 * V_60 )
{
T_7 V_202 ;
int V_30 ;
V_30 = F_152 ( V_178 , 2 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_153 ( V_182 [ 1 ] , & V_202 , 1 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_155 ( V_60 -> V_124 , V_202 ) ;
if ( V_30 ) {
F_87 ( L_32 ,
V_182 [ 1 ] ) ;
return V_30 ;
}
return 0 ;
}
static int F_156 ( unsigned V_178 , char * * V_182 , struct V_60 * V_60 )
{
T_7 V_202 ;
T_7 V_205 ;
int V_30 ;
V_30 = F_152 ( V_178 , 3 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_153 ( V_182 [ 1 ] , & V_202 , 1 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_153 ( V_182 [ 2 ] , & V_205 , 1 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_157 ( V_60 -> V_124 , V_202 , V_205 ) ;
if ( V_30 ) {
F_87 ( L_33 ,
V_182 [ 1 ] , V_182 [ 2 ] ) ;
return V_30 ;
}
return 0 ;
}
static int F_158 ( unsigned V_178 , char * * V_182 , struct V_60 * V_60 )
{
T_7 V_202 ;
int V_30 ;
V_30 = F_152 ( V_178 , 2 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_153 ( V_182 [ 1 ] , & V_202 , 1 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_159 ( V_60 -> V_124 , V_202 ) ;
if ( V_30 )
F_87 ( L_34 , V_182 [ 1 ] ) ;
return V_30 ;
}
static int F_160 ( unsigned V_178 , char * * V_182 , struct V_60 * V_60 )
{
T_7 V_206 , V_207 ;
int V_30 ;
V_30 = F_152 ( V_178 , 3 ) ;
if ( V_30 )
return V_30 ;
if ( F_140 ( V_182 [ 1 ] , 10 , ( unsigned long long * ) & V_206 ) ) {
F_87 ( L_35 , V_182 [ 1 ] ) ;
return - V_173 ;
}
if ( F_140 ( V_182 [ 2 ] , 10 , ( unsigned long long * ) & V_207 ) ) {
F_87 ( L_36 , V_182 [ 2 ] ) ;
return - V_173 ;
}
V_30 = F_161 ( V_60 -> V_124 , V_206 , V_207 ) ;
if ( V_30 ) {
F_87 ( L_37 ,
V_182 [ 1 ] , V_182 [ 2 ] ) ;
return V_30 ;
}
return 0 ;
}
static int F_162 ( struct V_139 * V_127 , unsigned V_178 , char * * V_182 )
{
int V_30 = - V_173 ;
struct V_149 * V_150 = V_127 -> V_142 ;
struct V_60 * V_60 = V_150 -> V_60 ;
if ( ! strcasecmp ( V_182 [ 0 ] , L_38 ) )
V_30 = F_154 ( V_178 , V_182 , V_60 ) ;
else if ( ! strcasecmp ( V_182 [ 0 ] , L_39 ) )
V_30 = F_156 ( V_178 , V_182 , V_60 ) ;
else if ( ! strcasecmp ( V_182 [ 0 ] , L_40 ) )
V_30 = F_158 ( V_178 , V_182 , V_60 ) ;
else if ( ! strcasecmp ( V_182 [ 0 ] , L_41 ) )
V_30 = F_160 ( V_178 , V_182 , V_60 ) ;
else
F_87 ( L_42 , V_182 [ 0 ] ) ;
if ( ! V_30 ) {
V_30 = F_90 ( V_60 -> V_124 ) ;
if ( V_30 )
F_74 ( L_43 ,
V_182 [ 0 ] , V_30 ) ;
}
return V_30 ;
}
static int F_163 ( struct V_139 * V_127 , T_8 type ,
char * V_122 , unsigned V_208 )
{
int V_30 ;
unsigned V_209 = 0 ;
T_3 V_210 ;
T_4 V_211 ;
T_4 V_212 ;
T_4 V_213 ;
T_4 V_214 ;
T_4 V_215 ;
char V_216 [ V_217 ] ;
char V_218 [ V_217 ] ;
struct V_149 * V_150 = V_127 -> V_142 ;
struct V_60 * V_60 = V_150 -> V_60 ;
switch ( type ) {
case V_219 :
V_30 = F_164 ( V_60 -> V_124 ,
& V_210 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_165 ( V_60 -> V_124 ,
& V_212 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_166 ( V_60 -> V_124 , & V_214 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_86 ( V_60 -> V_124 ,
& V_211 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_147 ( V_60 -> V_124 , & V_213 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_167 ( V_60 -> V_124 , & V_215 ) ;
if ( V_30 )
return V_30 ;
F_168 ( L_44 ,
( unsigned long long ) V_210 ,
( unsigned long long ) ( V_214 - V_212 ) ,
( unsigned long long ) V_214 ,
( unsigned long long ) ( V_213 - V_211 ) ,
( unsigned long long ) V_213 ) ;
if ( V_215 )
F_168 ( L_45 , V_215 ) ;
else
F_168 ( L_46 ) ;
break;
case V_220 :
F_168 ( L_47 ,
F_169 ( V_216 , V_150 -> V_156 -> V_77 -> V_221 ) ,
F_169 ( V_218 , V_150 -> V_154 -> V_77 -> V_221 ) ,
( unsigned long ) V_60 -> V_107 ,
( unsigned long long ) V_150 -> V_125 ) ;
F_168 ( L_48 , ! V_60 -> V_121 ) ;
if ( ! V_60 -> V_121 )
F_168 ( L_49 ) ;
break;
}
return 0 ;
}
static int F_170 ( struct V_139 * V_127 ,
T_9 V_110 , void * V_222 )
{
struct V_149 * V_150 = V_127 -> V_142 ;
return V_110 ( V_127 , V_150 -> V_154 , 0 , V_127 -> V_6 , V_222 ) ;
}
static int F_171 ( struct V_139 * V_127 , struct V_223 * V_224 ,
struct V_225 * V_226 , int V_227 )
{
struct V_149 * V_150 = V_127 -> V_142 ;
struct V_152 * V_153 = F_107 ( V_150 -> V_154 -> V_77 ) ;
if ( ! V_153 -> V_228 )
return V_227 ;
V_224 -> V_75 = V_150 -> V_154 -> V_77 ;
return F_2 ( V_227 , V_153 -> V_228 ( V_153 , V_224 , V_226 ) ) ;
}
static void F_172 ( struct V_139 * V_127 , struct V_229 * V_230 )
{
struct V_149 * V_150 = V_127 -> V_142 ;
struct V_60 * V_60 = V_150 -> V_60 ;
F_173 ( V_230 , 0 ) ;
F_174 ( V_230 , V_60 -> V_107 << V_108 ) ;
}
static void F_175 ( struct V_139 * V_127 )
{
struct V_66 * V_67 = V_127 -> V_142 ;
F_129 ( & V_57 . V_58 ) ;
F_126 ( V_67 -> V_60 ) ;
F_176 ( V_67 -> V_56 ) ;
F_130 ( V_127 , V_67 -> V_76 ) ;
F_7 ( V_67 ) ;
F_131 ( & V_57 . V_58 ) ;
}
static int F_177 ( struct V_139 * V_127 , unsigned V_178 , char * * V_182 )
{
int V_30 ;
struct V_66 * V_67 ;
struct V_183 * V_76 ;
struct V_61 * V_63 ;
F_129 ( & V_57 . V_58 ) ;
if ( V_178 != 2 ) {
V_127 -> error = L_21 ;
V_30 = - V_173 ;
goto V_185;
}
V_67 = V_127 -> V_142 = F_142 ( sizeof( * V_67 ) , V_9 ) ;
if ( ! V_67 ) {
V_127 -> error = L_50 ;
V_30 = - V_113 ;
goto V_185;
}
V_30 = F_136 ( V_127 , V_182 [ 0 ] , F_178 ( V_127 -> V_128 ) , & V_76 ) ;
if ( V_30 ) {
V_127 -> error = L_51 ;
goto V_231;
}
V_67 -> V_76 = V_76 ;
if ( F_153 ( V_182 [ 1 ] , ( unsigned long long * ) & V_67 -> V_202 , 0 ) ) {
V_127 -> error = L_52 ;
V_30 = - V_173 ;
goto V_232;
}
V_63 = F_179 ( V_67 -> V_76 -> V_77 -> V_221 ) ;
if ( ! V_63 ) {
V_127 -> error = L_53 ;
V_30 = - V_173 ;
goto V_232;
}
V_67 -> V_60 = F_51 ( V_63 ) ;
if ( ! V_67 -> V_60 ) {
V_127 -> error = L_54 ;
V_30 = - V_173 ;
goto V_233;
}
F_125 ( V_67 -> V_60 ) ;
V_30 = F_180 ( V_67 -> V_60 -> V_124 , V_67 -> V_202 , & V_67 -> V_56 ) ;
if ( V_30 ) {
V_127 -> error = L_55 ;
goto V_234;
}
V_127 -> V_235 = V_67 -> V_60 -> V_107 ;
V_127 -> V_195 = 1 ;
V_127 -> V_196 = 0 ;
V_127 -> V_236 = 0 ;
F_181 ( V_63 ) ;
F_131 ( & V_57 . V_58 ) ;
return 0 ;
V_234:
F_126 ( V_67 -> V_60 ) ;
V_233:
F_181 ( V_63 ) ;
V_232:
F_130 ( V_127 , V_67 -> V_76 ) ;
V_231:
F_7 ( V_67 ) ;
V_185:
F_131 ( & V_57 . V_58 ) ;
return V_30 ;
}
static int F_182 ( struct V_139 * V_127 , struct V_27 * V_27 ,
union V_140 * V_141 )
{
V_27 -> V_73 -= V_127 -> V_237 ;
return F_104 ( V_127 , V_27 , V_141 ) ;
}
static void F_183 ( struct V_139 * V_127 )
{
if ( F_184 ( V_127 ) )
F_57 ( (struct V_66 * ) V_127 -> V_142 ) ;
}
static int F_185 ( struct V_139 * V_127 , T_8 type ,
char * V_122 , unsigned V_208 )
{
int V_30 ;
T_10 V_209 = 0 ;
T_4 V_238 , V_239 ;
char V_216 [ V_217 ] ;
struct V_66 * V_67 = V_127 -> V_142 ;
if ( ! V_67 -> V_56 )
F_168 ( L_46 ) ;
else {
switch ( type ) {
case V_219 :
V_30 = F_186 ( V_67 -> V_56 , & V_238 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_187 ( V_67 -> V_56 , & V_239 ) ;
if ( V_30 < 0 )
return V_30 ;
F_168 ( L_56 , V_238 * V_67 -> V_60 -> V_107 ) ;
if ( V_30 )
F_168 ( L_45 , ( ( V_239 + 1 ) *
V_67 -> V_60 -> V_107 ) - 1 ) ;
else
F_168 ( L_46 ) ;
break;
case V_220 :
F_168 ( L_57 ,
F_169 ( V_216 , V_67 -> V_76 -> V_77 -> V_221 ) ,
( unsigned long ) V_67 -> V_202 ) ;
break;
}
}
return 0 ;
}
static int F_188 ( struct V_139 * V_127 ,
T_9 V_110 , void * V_222 )
{
T_4 V_240 ;
struct V_66 * V_67 = V_127 -> V_142 ;
if ( ! V_67 -> V_60 -> V_127 )
return 0 ;
V_240 = V_67 -> V_60 -> V_127 -> V_6 >> V_67 -> V_60 -> V_74 ;
if ( V_240 )
return V_110 ( V_127 , V_67 -> V_76 , 0 , V_67 -> V_60 -> V_107 * V_240 , V_222 ) ;
return 0 ;
}
static void F_189 ( struct V_139 * V_127 , struct V_229 * V_230 )
{
struct V_66 * V_67 = V_127 -> V_142 ;
F_173 ( V_230 , 0 ) ;
F_174 ( V_230 , V_67 -> V_60 -> V_107 << V_108 ) ;
}
static int T_11 F_190 ( void )
{
int V_30 ;
F_45 () ;
V_30 = F_191 ( & V_241 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_191 ( & V_242 ) ;
if ( V_30 )
F_192 ( & V_241 ) ;
return V_30 ;
}
static void F_193 ( void )
{
F_192 ( & V_241 ) ;
F_192 ( & V_242 ) ;
}
