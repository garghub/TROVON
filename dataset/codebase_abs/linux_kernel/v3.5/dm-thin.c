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
V_8 -> V_11 = F_6 ( V_1 , V_12 ) ;
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
static struct V_24 * F_13 ( struct V_7 * V_25 ,
struct V_15 * V_16 )
{
struct V_24 * V_26 ;
struct V_27 * V_28 ;
F_14 (cell, tmp, bucket, list)
if ( F_12 ( & V_26 -> V_16 , V_16 ) )
return V_26 ;
return NULL ;
}
static int F_15 ( struct V_3 * V_8 , struct V_15 * V_16 ,
struct V_29 * V_30 , struct V_24 * * V_31 )
{
int V_32 = 1 ;
unsigned long V_33 ;
T_1 V_18 = F_11 ( V_8 , V_16 ) ;
struct V_24 * V_26 , * V_34 ;
F_16 ( V_18 > V_8 -> V_5 ) ;
F_17 ( & V_8 -> V_10 , V_33 ) ;
V_26 = F_13 ( V_8 -> V_14 + V_18 , V_16 ) ;
if ( V_26 ) {
F_18 ( & V_26 -> V_35 , V_30 ) ;
goto V_36;
}
F_19 ( & V_8 -> V_10 , V_33 ) ;
V_34 = F_20 ( V_8 -> V_11 , V_37 ) ;
F_17 ( & V_8 -> V_10 , V_33 ) ;
V_26 = F_13 ( V_8 -> V_14 + V_18 , V_16 ) ;
if ( V_26 ) {
F_21 ( V_34 , V_8 -> V_11 ) ;
F_18 ( & V_26 -> V_35 , V_30 ) ;
goto V_36;
}
V_26 = V_34 ;
V_26 -> V_8 = V_8 ;
memcpy ( & V_26 -> V_16 , V_16 , sizeof( V_26 -> V_16 ) ) ;
V_26 -> V_38 = V_30 ;
F_22 ( & V_26 -> V_35 ) ;
F_23 ( & V_26 -> V_39 , V_8 -> V_14 + V_18 ) ;
V_32 = 0 ;
V_36:
F_19 ( & V_8 -> V_10 , V_33 ) ;
* V_31 = V_26 ;
return V_32 ;
}
static void F_24 ( struct V_24 * V_26 , struct V_40 * V_41 )
{
struct V_3 * V_8 = V_26 -> V_8 ;
F_25 ( & V_26 -> V_39 ) ;
if ( V_41 ) {
F_18 ( V_41 , V_26 -> V_38 ) ;
F_26 ( V_41 , & V_26 -> V_35 ) ;
}
F_21 ( V_26 , V_8 -> V_11 ) ;
}
static void F_27 ( struct V_24 * V_26 , struct V_40 * V_35 )
{
unsigned long V_33 ;
struct V_3 * V_8 = V_26 -> V_8 ;
F_17 ( & V_8 -> V_10 , V_33 ) ;
F_24 ( V_26 , V_35 ) ;
F_19 ( & V_8 -> V_10 , V_33 ) ;
}
static void F_28 ( struct V_24 * V_26 , struct V_29 * V_29 )
{
F_16 ( V_26 -> V_38 != V_29 ) ;
F_16 ( ! F_29 ( & V_26 -> V_35 ) ) ;
F_24 ( V_26 , NULL ) ;
}
static void F_30 ( struct V_24 * V_26 , struct V_29 * V_29 )
{
unsigned long V_33 ;
struct V_3 * V_8 = V_26 -> V_8 ;
F_17 ( & V_8 -> V_10 , V_33 ) ;
F_28 ( V_26 , V_29 ) ;
F_19 ( & V_8 -> V_10 , V_33 ) ;
}
static void F_31 ( struct V_24 * V_26 ,
struct V_40 * V_41 )
{
struct V_3 * V_8 = V_26 -> V_8 ;
F_25 ( & V_26 -> V_39 ) ;
F_26 ( V_41 , & V_26 -> V_35 ) ;
F_21 ( V_26 , V_8 -> V_11 ) ;
}
static void F_32 ( struct V_24 * V_26 ,
struct V_40 * V_41 )
{
unsigned long V_33 ;
struct V_3 * V_8 = V_26 -> V_8 ;
F_17 ( & V_8 -> V_10 , V_33 ) ;
F_31 ( V_26 , V_41 ) ;
F_19 ( & V_8 -> V_10 , V_33 ) ;
}
static void F_33 ( struct V_24 * V_26 )
{
struct V_3 * V_8 = V_26 -> V_8 ;
struct V_40 V_35 ;
struct V_29 * V_29 ;
unsigned long V_33 ;
F_22 ( & V_35 ) ;
F_17 ( & V_8 -> V_10 , V_33 ) ;
F_24 ( V_26 , & V_35 ) ;
F_19 ( & V_8 -> V_10 , V_33 ) ;
while ( ( V_29 = F_34 ( & V_35 ) ) )
F_35 ( V_29 ) ;
}
static void F_36 ( struct V_42 * V_43 )
{
int V_4 ;
F_5 ( & V_43 -> V_10 ) ;
V_43 -> V_44 = 0 ;
V_43 -> V_45 = 0 ;
for ( V_4 = 0 ; V_4 < V_46 ; V_4 ++ ) {
V_43 -> V_47 [ V_4 ] . V_43 = V_43 ;
V_43 -> V_47 [ V_4 ] . V_48 = 0 ;
F_37 ( & V_43 -> V_47 [ V_4 ] . V_49 ) ;
}
}
static struct V_50 * F_38 ( struct V_42 * V_43 )
{
unsigned long V_33 ;
struct V_50 * V_51 ;
F_17 ( & V_43 -> V_10 , V_33 ) ;
V_51 = V_43 -> V_47 + V_43 -> V_44 ;
V_51 -> V_48 ++ ;
F_19 ( & V_43 -> V_10 , V_33 ) ;
return V_51 ;
}
static unsigned F_39 ( unsigned V_52 )
{
return ( V_52 + 1 ) % V_46 ;
}
static void F_40 ( struct V_42 * V_43 , struct V_53 * V_54 )
{
while ( ( V_43 -> V_45 != V_43 -> V_44 ) &&
! V_43 -> V_47 [ V_43 -> V_45 ] . V_48 ) {
F_41 ( & V_43 -> V_47 [ V_43 -> V_45 ] . V_49 , V_54 ) ;
V_43 -> V_45 = F_39 ( V_43 -> V_45 ) ;
}
if ( ( V_43 -> V_45 == V_43 -> V_44 ) && ! V_43 -> V_47 [ V_43 -> V_45 ] . V_48 )
F_41 ( & V_43 -> V_47 [ V_43 -> V_45 ] . V_49 , V_54 ) ;
}
static void F_42 ( struct V_50 * V_51 , struct V_53 * V_54 )
{
unsigned long V_33 ;
F_17 ( & V_51 -> V_43 -> V_10 , V_33 ) ;
F_16 ( ! V_51 -> V_48 ) ;
-- V_51 -> V_48 ;
F_40 ( V_51 -> V_43 , V_54 ) ;
F_19 ( & V_51 -> V_43 -> V_10 , V_33 ) ;
}
static int F_43 ( struct V_42 * V_43 , struct V_53 * V_55 )
{
int V_32 = 1 ;
unsigned long V_33 ;
unsigned V_56 ;
F_17 ( & V_43 -> V_10 , V_33 ) ;
if ( ( V_43 -> V_45 == V_43 -> V_44 ) &&
! V_43 -> V_47 [ V_43 -> V_44 ] . V_48 )
V_32 = 0 ;
else {
F_44 ( V_55 , & V_43 -> V_47 [ V_43 -> V_44 ] . V_49 ) ;
V_56 = F_39 ( V_43 -> V_44 ) ;
if ( ! V_43 -> V_47 [ V_56 ] . V_48 )
V_43 -> V_44 = V_56 ;
}
F_19 ( & V_43 -> V_10 , V_33 ) ;
return V_32 ;
}
static void F_45 ( struct V_57 * V_58 ,
T_4 V_59 , struct V_15 * V_16 )
{
V_16 -> V_22 = 0 ;
V_16 -> V_23 = F_46 ( V_58 ) ;
V_16 -> V_19 = V_59 ;
}
static void F_47 ( struct V_57 * V_58 , T_4 V_59 ,
struct V_15 * V_16 )
{
V_16 -> V_22 = 1 ;
V_16 -> V_23 = F_46 ( V_58 ) ;
V_16 -> V_19 = V_59 ;
}
static void F_48 ( void )
{
F_49 ( & V_60 . V_61 ) ;
F_37 ( & V_60 . V_62 ) ;
}
static void F_50 ( struct V_63 * V_63 )
{
F_16 ( ! F_51 ( & V_60 . V_61 ) ) ;
F_44 ( & V_63 -> V_39 , & V_60 . V_62 ) ;
}
static void F_52 ( struct V_63 * V_63 )
{
F_16 ( ! F_51 ( & V_60 . V_61 ) ) ;
F_53 ( & V_63 -> V_39 ) ;
}
static struct V_63 * F_54 ( struct V_64 * V_65 )
{
struct V_63 * V_63 = NULL , * V_28 ;
F_16 ( ! F_51 ( & V_60 . V_61 ) ) ;
F_55 (tmp, &dm_thin_pool_table.pools, list) {
if ( V_28 -> V_66 == V_65 ) {
V_63 = V_28 ;
break;
}
}
return V_63 ;
}
static struct V_63 * F_56 ( struct V_67 * V_68 )
{
struct V_63 * V_63 = NULL , * V_28 ;
F_16 ( ! F_51 ( & V_60 . V_61 ) ) ;
F_55 (tmp, &dm_thin_pool_table.pools, list) {
if ( V_28 -> V_68 == V_68 ) {
V_63 = V_28 ;
break;
}
}
return V_63 ;
}
static void F_57 ( struct V_69 * V_70 , struct V_40 * V_71 )
{
struct V_29 * V_29 ;
struct V_40 V_35 ;
F_22 ( & V_35 ) ;
F_26 ( & V_35 , V_71 ) ;
F_22 ( V_71 ) ;
while ( ( V_29 = F_34 ( & V_35 ) ) ) {
struct V_72 * V_73 = F_58 ( V_29 ) -> V_74 ;
if ( V_73 -> V_70 == V_70 )
F_59 ( V_29 , V_75 ) ;
else
F_18 ( V_71 , V_29 ) ;
}
}
static void F_60 ( struct V_69 * V_70 )
{
struct V_63 * V_63 = V_70 -> V_63 ;
unsigned long V_33 ;
F_17 ( & V_63 -> V_10 , V_33 ) ;
F_57 ( V_70 , & V_63 -> V_76 ) ;
F_57 ( V_70 , & V_63 -> V_77 ) ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
}
static T_4 F_61 ( struct V_69 * V_70 , struct V_29 * V_29 )
{
return V_29 -> V_78 >> V_70 -> V_63 -> V_79 ;
}
static void F_62 ( struct V_69 * V_70 , struct V_29 * V_29 , T_4 V_19 )
{
struct V_63 * V_63 = V_70 -> V_63 ;
V_29 -> V_80 = V_70 -> V_81 -> V_82 ;
V_29 -> V_78 = ( V_19 << V_63 -> V_79 ) +
( V_29 -> V_78 & V_63 -> V_83 ) ;
}
static void F_63 ( struct V_69 * V_70 , struct V_29 * V_29 )
{
V_29 -> V_80 = V_70 -> V_84 -> V_82 ;
}
static void F_64 ( struct V_69 * V_70 , struct V_29 * V_29 )
{
struct V_63 * V_63 = V_70 -> V_63 ;
unsigned long V_33 ;
if ( V_29 -> V_85 & ( V_86 | V_87 ) ) {
F_17 ( & V_63 -> V_10 , V_33 ) ;
F_18 ( & V_63 -> V_88 , V_29 ) ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
} else
F_65 ( V_29 ) ;
}
static void F_66 ( struct V_69 * V_70 , struct V_29 * V_29 )
{
F_63 ( V_70 , V_29 ) ;
F_64 ( V_70 , V_29 ) ;
}
static void F_67 ( struct V_69 * V_70 , struct V_29 * V_29 ,
T_4 V_19 )
{
F_62 ( V_70 , V_29 , V_19 ) ;
F_64 ( V_70 , V_29 ) ;
}
static void F_68 ( struct V_63 * V_63 )
{
F_69 ( V_63 -> V_89 , & V_63 -> V_90 ) ;
}
static void F_70 ( struct V_91 * V_92 )
{
struct V_63 * V_63 = V_92 -> V_70 -> V_63 ;
if ( V_92 -> V_93 && V_92 -> V_94 ) {
F_44 ( & V_92 -> V_39 , & V_63 -> V_95 ) ;
F_68 ( V_63 ) ;
}
}
static void F_71 ( int V_96 , unsigned long V_97 , void * V_98 )
{
unsigned long V_33 ;
struct V_91 * V_92 = V_98 ;
struct V_63 * V_63 = V_92 -> V_70 -> V_63 ;
V_92 -> V_99 = V_96 || V_97 ? - V_100 : 0 ;
F_17 ( & V_63 -> V_10 , V_33 ) ;
V_92 -> V_94 = 1 ;
F_70 ( V_92 ) ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
}
static void F_72 ( struct V_29 * V_29 , int V_99 )
{
unsigned long V_33 ;
struct V_72 * V_73 = F_58 ( V_29 ) -> V_74 ;
struct V_91 * V_92 = V_73 -> V_101 ;
struct V_63 * V_63 = V_92 -> V_70 -> V_63 ;
V_92 -> V_99 = V_99 ;
F_17 ( & V_63 -> V_10 , V_33 ) ;
V_92 -> V_94 = 1 ;
F_70 ( V_92 ) ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
}
static void F_73 ( struct V_69 * V_70 , struct V_24 * V_26 ,
T_4 V_102 )
{
struct V_63 * V_63 = V_70 -> V_63 ;
unsigned long V_33 ;
F_17 ( & V_63 -> V_10 , V_33 ) ;
F_27 ( V_26 , & V_63 -> V_76 ) ;
F_19 ( & V_70 -> V_63 -> V_10 , V_33 ) ;
F_68 ( V_63 ) ;
}
static void F_74 ( struct V_69 * V_70 , struct V_24 * V_26 )
{
struct V_40 V_35 ;
struct V_63 * V_63 = V_70 -> V_63 ;
unsigned long V_33 ;
F_22 ( & V_35 ) ;
F_17 ( & V_63 -> V_10 , V_33 ) ;
F_32 ( V_26 , & V_63 -> V_76 ) ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
F_68 ( V_63 ) ;
}
static void F_75 ( struct V_91 * V_92 )
{
struct V_69 * V_70 = V_92 -> V_70 ;
struct V_29 * V_29 ;
int V_32 ;
V_29 = V_92 -> V_29 ;
if ( V_29 )
V_29 -> V_103 = V_92 -> V_104 ;
if ( V_92 -> V_99 ) {
F_33 ( V_92 -> V_26 ) ;
return;
}
V_32 = F_76 ( V_70 -> V_58 , V_92 -> V_105 , V_92 -> V_102 ) ;
if ( V_32 ) {
F_77 ( L_1 ) ;
F_33 ( V_92 -> V_26 ) ;
return;
}
if ( V_29 ) {
F_74 ( V_70 , V_92 -> V_26 ) ;
F_59 ( V_29 , 0 ) ;
} else
F_73 ( V_70 , V_92 -> V_26 , V_92 -> V_102 ) ;
F_53 ( & V_92 -> V_39 ) ;
F_21 ( V_92 , V_70 -> V_63 -> V_106 ) ;
}
static void F_78 ( struct V_91 * V_92 )
{
int V_32 ;
struct V_69 * V_70 = V_92 -> V_70 ;
V_32 = F_79 ( V_70 -> V_58 , V_92 -> V_105 ) ;
if ( V_32 )
F_77 ( L_2 ) ;
if ( V_92 -> V_107 )
F_67 ( V_70 , V_92 -> V_29 , V_92 -> V_102 ) ;
else
F_59 ( V_92 -> V_29 , 0 ) ;
F_74 ( V_70 , V_92 -> V_26 ) ;
F_74 ( V_70 , V_92 -> V_34 ) ;
F_21 ( V_92 , V_70 -> V_63 -> V_106 ) ;
}
static void F_80 ( struct V_63 * V_63 , struct V_53 * V_54 ,
void (* F_81)( struct V_91 * ) )
{
unsigned long V_33 ;
struct V_53 V_108 ;
struct V_91 * V_92 , * V_28 ;
F_37 ( & V_108 ) ;
F_17 ( & V_63 -> V_10 , V_33 ) ;
F_41 ( V_54 , & V_108 ) ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
F_82 (m, tmp, &maps, list)
F_81 ( V_92 ) ;
}
static int F_83 ( struct V_63 * V_63 , struct V_29 * V_29 )
{
return ! ( V_29 -> V_78 & V_63 -> V_83 ) &&
( V_29 -> V_109 == ( V_63 -> V_110 << V_111 ) ) ;
}
static int F_84 ( struct V_63 * V_63 , struct V_29 * V_29 )
{
return ( F_85 ( V_29 ) == V_112 ) &&
F_83 ( V_63 , V_29 ) ;
}
static void F_86 ( struct V_29 * V_29 , T_5 * * V_113 ,
T_5 * F_81 )
{
* V_113 = V_29 -> V_103 ;
V_29 -> V_103 = F_81 ;
}
static int F_87 ( struct V_63 * V_63 )
{
if ( V_63 -> V_114 )
return 0 ;
V_63 -> V_114 = F_20 ( V_63 -> V_106 , V_115 ) ;
return V_63 -> V_114 ? 0 : - V_116 ;
}
static struct V_91 * F_88 ( struct V_63 * V_63 )
{
struct V_91 * V_32 = V_63 -> V_114 ;
F_16 ( ! V_63 -> V_114 ) ;
V_63 -> V_114 = NULL ;
return V_32 ;
}
static void F_89 ( struct V_69 * V_70 , T_4 V_105 ,
struct V_117 * V_118 , T_4 V_119 ,
T_4 V_120 ,
struct V_24 * V_26 , struct V_29 * V_29 )
{
int V_32 ;
struct V_63 * V_63 = V_70 -> V_63 ;
struct V_91 * V_92 = F_88 ( V_63 ) ;
F_37 ( & V_92 -> V_39 ) ;
V_92 -> V_93 = 0 ;
V_92 -> V_94 = 0 ;
V_92 -> V_70 = V_70 ;
V_92 -> V_105 = V_105 ;
V_92 -> V_102 = V_120 ;
V_92 -> V_26 = V_26 ;
V_92 -> V_99 = 0 ;
V_92 -> V_29 = NULL ;
if ( ! F_43 ( & V_63 -> V_121 , & V_92 -> V_39 ) )
V_92 -> V_93 = 1 ;
if ( F_84 ( V_63 , V_29 ) ) {
struct V_72 * V_73 = F_58 ( V_29 ) -> V_74 ;
V_73 -> V_101 = V_92 ;
V_92 -> V_29 = V_29 ;
F_86 ( V_29 , & V_92 -> V_104 , F_72 ) ;
F_67 ( V_70 , V_29 , V_120 ) ;
} else {
struct V_122 V_123 , V_124 ;
V_123 . V_82 = V_118 -> V_82 ;
V_123 . V_125 = V_119 * V_63 -> V_110 ;
V_123 . V_48 = V_63 -> V_110 ;
V_124 . V_82 = V_70 -> V_81 -> V_82 ;
V_124 . V_125 = V_120 * V_63 -> V_110 ;
V_124 . V_48 = V_63 -> V_110 ;
V_32 = F_90 ( V_63 -> V_126 , & V_123 , 1 , & V_124 ,
0 , F_71 , V_92 ) ;
if ( V_32 < 0 ) {
F_21 ( V_92 , V_63 -> V_106 ) ;
F_77 ( L_3 ) ;
F_33 ( V_26 ) ;
}
}
}
static void F_91 ( struct V_69 * V_70 , T_4 V_105 ,
T_4 V_119 , T_4 V_120 ,
struct V_24 * V_26 , struct V_29 * V_29 )
{
F_89 ( V_70 , V_105 , V_70 -> V_81 ,
V_119 , V_120 , V_26 , V_29 ) ;
}
static void F_92 ( struct V_69 * V_70 , T_4 V_105 ,
T_4 V_120 ,
struct V_24 * V_26 , struct V_29 * V_29 )
{
F_89 ( V_70 , V_105 , V_70 -> V_84 ,
V_105 , V_120 , V_26 , V_29 ) ;
}
static void F_93 ( struct V_69 * V_70 , T_4 V_105 ,
T_4 V_102 , struct V_24 * V_26 ,
struct V_29 * V_29 )
{
struct V_63 * V_63 = V_70 -> V_63 ;
struct V_91 * V_92 = F_88 ( V_63 ) ;
F_37 ( & V_92 -> V_39 ) ;
V_92 -> V_93 = 1 ;
V_92 -> V_94 = 0 ;
V_92 -> V_70 = V_70 ;
V_92 -> V_105 = V_105 ;
V_92 -> V_102 = V_102 ;
V_92 -> V_26 = V_26 ;
V_92 -> V_99 = 0 ;
V_92 -> V_29 = NULL ;
if ( ! V_63 -> V_127 . V_128 )
F_75 ( V_92 ) ;
else if ( F_84 ( V_63 , V_29 ) ) {
struct V_72 * V_73 = F_58 ( V_29 ) -> V_74 ;
V_73 -> V_101 = V_92 ;
V_92 -> V_29 = V_29 ;
F_86 ( V_29 , & V_92 -> V_104 , F_72 ) ;
F_67 ( V_70 , V_29 , V_102 ) ;
} else {
int V_32 ;
struct V_122 V_124 ;
V_124 . V_82 = V_70 -> V_81 -> V_82 ;
V_124 . V_125 = V_102 * V_63 -> V_110 ;
V_124 . V_48 = V_63 -> V_110 ;
V_32 = F_94 ( V_63 -> V_126 , 1 , & V_124 , 0 , F_71 , V_92 ) ;
if ( V_32 < 0 ) {
F_21 ( V_92 , V_63 -> V_106 ) ;
F_77 ( L_4 ) ;
F_33 ( V_26 ) ;
}
}
}
static int F_95 ( struct V_69 * V_70 , T_4 * V_129 )
{
int V_32 ;
T_4 V_130 ;
unsigned long V_33 ;
struct V_63 * V_63 = V_70 -> V_63 ;
V_32 = F_96 ( V_63 -> V_131 , & V_130 ) ;
if ( V_32 )
return V_32 ;
if ( V_130 <= V_63 -> V_132 && ! V_63 -> V_133 ) {
F_97 ( L_5 ,
F_98 ( V_63 -> V_66 ) ) ;
F_17 ( & V_63 -> V_10 , V_33 ) ;
V_63 -> V_133 = 1 ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
F_99 ( V_63 -> V_134 -> V_135 ) ;
}
if ( ! V_130 ) {
if ( V_63 -> V_136 )
return - V_137 ;
else {
V_32 = F_100 ( V_63 -> V_131 ) ;
if ( V_32 ) {
F_77 ( L_6 ,
V_138 , V_32 ) ;
return V_32 ;
}
V_32 = F_96 ( V_63 -> V_131 , & V_130 ) ;
if ( V_32 )
return V_32 ;
if ( ! V_130 ) {
F_97 ( L_7 ,
F_98 ( V_63 -> V_66 ) ) ;
F_17 ( & V_63 -> V_10 , V_33 ) ;
V_63 -> V_136 = 1 ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
return - V_137 ;
}
}
}
V_32 = F_101 ( V_63 -> V_131 , V_129 ) ;
if ( V_32 )
return V_32 ;
return 0 ;
}
static void F_102 ( struct V_29 * V_29 )
{
struct V_72 * V_73 = F_58 ( V_29 ) -> V_74 ;
struct V_69 * V_70 = V_73 -> V_70 ;
struct V_63 * V_63 = V_70 -> V_63 ;
unsigned long V_33 ;
F_17 ( & V_63 -> V_10 , V_33 ) ;
F_18 ( & V_63 -> V_77 , V_29 ) ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
}
static void F_103 ( struct V_24 * V_26 )
{
struct V_29 * V_29 ;
struct V_40 V_35 ;
F_22 ( & V_35 ) ;
F_27 ( V_26 , & V_35 ) ;
while ( ( V_29 = F_34 ( & V_35 ) ) )
F_102 ( V_29 ) ;
}
static void F_104 ( struct V_69 * V_70 , struct V_29 * V_29 )
{
int V_32 ;
unsigned long V_33 ;
struct V_63 * V_63 = V_70 -> V_63 ;
struct V_24 * V_26 , * V_34 ;
struct V_15 V_16 , V_139 ;
T_4 V_19 = F_61 ( V_70 , V_29 ) ;
struct V_140 V_141 ;
struct V_91 * V_92 ;
F_47 ( V_70 -> V_58 , V_19 , & V_16 ) ;
if ( F_15 ( V_70 -> V_63 -> V_8 , & V_16 , V_29 , & V_26 ) )
return;
V_32 = F_105 ( V_70 -> V_58 , V_19 , 1 , & V_141 ) ;
switch ( V_32 ) {
case 0 :
F_45 ( V_70 -> V_58 , V_141 . V_19 , & V_139 ) ;
if ( F_15 ( V_70 -> V_63 -> V_8 , & V_139 , V_29 , & V_34 ) ) {
F_30 ( V_26 , V_29 ) ;
break;
}
if ( F_83 ( V_63 , V_29 ) ) {
V_92 = F_88 ( V_63 ) ;
V_92 -> V_70 = V_70 ;
V_92 -> V_107 = ( ! V_141 . V_142 ) & V_63 -> V_127 . V_143 ;
V_92 -> V_105 = V_19 ;
V_92 -> V_102 = V_141 . V_19 ;
V_92 -> V_26 = V_26 ;
V_92 -> V_34 = V_34 ;
V_92 -> V_99 = 0 ;
V_92 -> V_29 = V_29 ;
if ( ! F_43 ( & V_63 -> V_144 , & V_92 -> V_39 ) ) {
F_17 ( & V_63 -> V_10 , V_33 ) ;
F_44 ( & V_92 -> V_39 , & V_63 -> V_145 ) ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
F_68 ( V_63 ) ;
}
} else {
T_6 V_146 = V_29 -> V_78 - ( V_19 << V_63 -> V_79 ) ;
unsigned V_147 = ( V_63 -> V_110 - V_146 ) << 9 ;
V_29 -> V_109 = F_2 ( V_29 -> V_109 , V_147 ) ;
F_30 ( V_26 , V_29 ) ;
F_30 ( V_34 , V_29 ) ;
if ( ( ! V_141 . V_142 ) && V_63 -> V_127 . V_143 )
F_67 ( V_70 , V_29 , V_141 . V_19 ) ;
else
F_59 ( V_29 , 0 ) ;
}
break;
case - V_148 :
F_30 ( V_26 , V_29 ) ;
F_59 ( V_29 , 0 ) ;
break;
default:
F_77 ( L_8 , V_32 ) ;
F_30 ( V_26 , V_29 ) ;
F_35 ( V_29 ) ;
break;
}
}
static void F_106 ( struct V_69 * V_70 , struct V_29 * V_29 , T_4 V_19 ,
struct V_15 * V_16 ,
struct V_140 * V_141 ,
struct V_24 * V_26 )
{
int V_32 ;
T_4 V_102 ;
V_32 = F_95 ( V_70 , & V_102 ) ;
switch ( V_32 ) {
case 0 :
F_91 ( V_70 , V_19 , V_141 -> V_19 ,
V_102 , V_26 , V_29 ) ;
break;
case - V_137 :
F_103 ( V_26 ) ;
break;
default:
F_77 ( L_9 , V_138 , V_32 ) ;
F_33 ( V_26 ) ;
break;
}
}
static void F_107 ( struct V_69 * V_70 , struct V_29 * V_29 ,
T_4 V_19 ,
struct V_140 * V_141 )
{
struct V_24 * V_26 ;
struct V_63 * V_63 = V_70 -> V_63 ;
struct V_15 V_16 ;
F_45 ( V_70 -> V_58 , V_141 -> V_19 , & V_16 ) ;
if ( F_15 ( V_63 -> V_8 , & V_16 , V_29 , & V_26 ) )
return;
if ( F_85 ( V_29 ) == V_112 )
F_106 ( V_70 , V_29 , V_19 , & V_16 , V_141 , V_26 ) ;
else {
struct V_72 * V_73 = F_58 ( V_29 ) -> V_74 ;
V_73 -> V_149 = F_38 ( & V_63 -> V_121 ) ;
F_30 ( V_26 , V_29 ) ;
F_67 ( V_70 , V_29 , V_141 -> V_19 ) ;
}
}
static void F_108 ( struct V_69 * V_70 , struct V_29 * V_29 , T_4 V_19 ,
struct V_24 * V_26 )
{
int V_32 ;
T_4 V_102 ;
if ( ! V_29 -> V_109 ) {
F_30 ( V_26 , V_29 ) ;
F_67 ( V_70 , V_29 , 0 ) ;
return;
}
if ( F_85 ( V_29 ) == V_150 ) {
F_109 ( V_29 ) ;
F_30 ( V_26 , V_29 ) ;
F_59 ( V_29 , 0 ) ;
return;
}
V_32 = F_95 ( V_70 , & V_102 ) ;
switch ( V_32 ) {
case 0 :
if ( V_70 -> V_84 )
F_92 ( V_70 , V_19 , V_102 , V_26 , V_29 ) ;
else
F_93 ( V_70 , V_19 , V_102 , V_26 , V_29 ) ;
break;
case - V_137 :
F_103 ( V_26 ) ;
break;
default:
F_77 ( L_9 , V_138 , V_32 ) ;
F_33 ( V_26 ) ;
break;
}
}
static void F_110 ( struct V_69 * V_70 , struct V_29 * V_29 )
{
int V_32 ;
T_4 V_19 = F_61 ( V_70 , V_29 ) ;
struct V_24 * V_26 ;
struct V_15 V_16 ;
struct V_140 V_141 ;
F_47 ( V_70 -> V_58 , V_19 , & V_16 ) ;
if ( F_15 ( V_70 -> V_63 -> V_8 , & V_16 , V_29 , & V_26 ) )
return;
V_32 = F_105 ( V_70 -> V_58 , V_19 , 1 , & V_141 ) ;
switch ( V_32 ) {
case 0 :
F_30 ( V_26 , V_29 ) ;
if ( V_141 . V_142 )
F_107 ( V_70 , V_29 , V_19 , & V_141 ) ;
else
F_67 ( V_70 , V_29 , V_141 . V_19 ) ;
break;
case - V_148 :
if ( F_85 ( V_29 ) == V_150 && V_70 -> V_84 ) {
F_30 ( V_26 , V_29 ) ;
F_66 ( V_70 , V_29 ) ;
} else
F_108 ( V_70 , V_29 , V_19 , V_26 ) ;
break;
default:
F_77 ( L_10 , V_32 ) ;
F_30 ( V_26 , V_29 ) ;
F_35 ( V_29 ) ;
break;
}
}
static int F_111 ( struct V_63 * V_63 )
{
return V_151 < V_63 -> V_152 ||
V_151 > V_63 -> V_152 + V_153 ;
}
static void F_112 ( struct V_63 * V_63 )
{
unsigned long V_33 ;
struct V_29 * V_29 ;
struct V_40 V_35 ;
int V_32 ;
F_22 ( & V_35 ) ;
F_17 ( & V_63 -> V_10 , V_33 ) ;
F_26 ( & V_35 , & V_63 -> V_76 ) ;
F_22 ( & V_63 -> V_76 ) ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
while ( ( V_29 = F_34 ( & V_35 ) ) ) {
struct V_72 * V_73 = F_58 ( V_29 ) -> V_74 ;
struct V_69 * V_70 = V_73 -> V_70 ;
if ( F_87 ( V_63 ) ) {
F_17 ( & V_63 -> V_10 , V_33 ) ;
F_26 ( & V_63 -> V_76 , & V_35 ) ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
break;
}
if ( V_29 -> V_85 & V_154 )
F_104 ( V_70 , V_29 ) ;
else
F_110 ( V_70 , V_29 ) ;
}
F_22 ( & V_35 ) ;
F_17 ( & V_63 -> V_10 , V_33 ) ;
F_26 ( & V_35 , & V_63 -> V_88 ) ;
F_22 ( & V_63 -> V_88 ) ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
if ( F_29 ( & V_35 ) && ! F_111 ( V_63 ) )
return;
V_32 = F_100 ( V_63 -> V_131 ) ;
if ( V_32 ) {
F_77 ( L_6 ,
V_138 , V_32 ) ;
while ( ( V_29 = F_34 ( & V_35 ) ) )
F_35 ( V_29 ) ;
return;
}
V_63 -> V_152 = V_151 ;
while ( ( V_29 = F_34 ( & V_35 ) ) )
F_65 ( V_29 ) ;
}
static void F_113 ( struct V_155 * V_156 )
{
struct V_63 * V_63 = F_114 ( V_156 , struct V_63 , V_90 ) ;
F_80 ( V_63 , & V_63 -> V_95 , F_75 ) ;
F_80 ( V_63 , & V_63 -> V_145 , F_78 ) ;
F_112 ( V_63 ) ;
}
static void F_115 ( struct V_155 * V_156 )
{
struct V_63 * V_63 = F_114 ( F_116 ( V_156 ) , struct V_63 , V_157 ) ;
F_68 ( V_63 ) ;
F_117 ( V_63 -> V_89 , & V_63 -> V_157 , V_153 ) ;
}
static void F_118 ( struct V_69 * V_70 , struct V_29 * V_29 )
{
unsigned long V_33 ;
struct V_63 * V_63 = V_70 -> V_63 ;
F_17 ( & V_63 -> V_10 , V_33 ) ;
F_18 ( & V_63 -> V_76 , V_29 ) ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
F_68 ( V_63 ) ;
}
static struct V_72 * F_119 ( struct V_69 * V_70 , struct V_29 * V_29 )
{
struct V_63 * V_63 = V_70 -> V_63 ;
struct V_72 * V_73 = F_20 ( V_63 -> V_158 , V_37 ) ;
V_73 -> V_70 = V_70 ;
V_73 -> V_149 = NULL ;
V_73 -> V_159 = V_29 -> V_85 & V_154 ? NULL : F_38 ( & V_63 -> V_144 ) ;
V_73 -> V_101 = NULL ;
return V_73 ;
}
static int F_120 ( struct V_160 * V_134 , struct V_29 * V_29 ,
union V_161 * V_162 )
{
int V_32 ;
struct V_69 * V_70 = V_134 -> V_163 ;
T_4 V_19 = F_61 ( V_70 , V_29 ) ;
struct V_57 * V_58 = V_70 -> V_58 ;
struct V_140 V_129 ;
V_162 -> V_74 = F_119 ( V_70 , V_29 ) ;
if ( V_29 -> V_85 & ( V_154 | V_86 | V_87 ) ) {
F_118 ( V_70 , V_29 ) ;
return V_164 ;
}
V_32 = F_105 ( V_58 , V_19 , 0 , & V_129 ) ;
switch ( V_32 ) {
case 0 :
if ( F_121 ( V_129 . V_142 ) ) {
F_118 ( V_70 , V_29 ) ;
V_32 = V_164 ;
} else {
F_62 ( V_70 , V_29 , V_129 . V_19 ) ;
V_32 = V_165 ;
}
break;
case - V_148 :
case - V_166 :
F_118 ( V_70 , V_29 ) ;
V_32 = V_164 ;
break;
}
return V_32 ;
}
static int F_122 ( struct V_167 * V_168 , int V_169 )
{
int V_32 ;
unsigned long V_33 ;
struct V_170 * V_171 = F_114 ( V_168 , struct V_170 , V_172 ) ;
F_17 ( & V_171 -> V_63 -> V_10 , V_33 ) ;
V_32 = ! F_29 ( & V_171 -> V_63 -> V_77 ) ;
F_19 ( & V_171 -> V_63 -> V_10 , V_33 ) ;
if ( ! V_32 ) {
struct V_173 * V_174 = F_123 ( V_171 -> V_175 -> V_82 ) ;
V_32 = F_124 ( & V_174 -> V_176 , V_169 ) ;
}
return V_32 ;
}
static void F_125 ( struct V_63 * V_63 )
{
F_26 ( & V_63 -> V_76 , & V_63 -> V_77 ) ;
F_22 ( & V_63 -> V_77 ) ;
}
static int F_126 ( struct V_63 * V_63 , struct V_160 * V_134 )
{
struct V_170 * V_171 = V_134 -> V_163 ;
V_63 -> V_134 = V_134 ;
V_63 -> V_132 = V_171 -> V_132 ;
V_63 -> V_127 = V_171 -> V_127 ;
if ( V_171 -> V_127 . V_143 ) {
struct V_173 * V_174 = F_123 ( V_171 -> V_175 -> V_82 ) ;
if ( ! V_174 || ! F_127 ( V_174 ) ) {
char V_177 [ V_178 ] ;
F_97 ( L_11 ,
F_128 ( V_171 -> V_175 -> V_82 , V_177 ) ) ;
V_63 -> V_127 . V_143 = 0 ;
}
}
return 0 ;
}
static void F_129 ( struct V_63 * V_63 , struct V_160 * V_134 )
{
if ( V_63 -> V_134 == V_134 )
V_63 -> V_134 = NULL ;
}
static void F_130 ( struct V_179 * V_127 )
{
V_127 -> V_128 = 1 ;
V_127 -> V_180 = 1 ;
V_127 -> V_143 = 1 ;
}
static void F_131 ( struct V_63 * V_63 )
{
F_52 ( V_63 ) ;
if ( F_132 ( V_63 -> V_131 ) < 0 )
F_97 ( L_12 , V_138 ) ;
F_9 ( V_63 -> V_8 ) ;
F_133 ( V_63 -> V_126 ) ;
if ( V_63 -> V_89 )
F_134 ( V_63 -> V_89 ) ;
if ( V_63 -> V_114 )
F_21 ( V_63 -> V_114 , V_63 -> V_106 ) ;
F_10 ( V_63 -> V_106 ) ;
F_10 ( V_63 -> V_158 ) ;
F_7 ( V_63 ) ;
}
static struct V_63 * F_135 ( struct V_64 * V_66 ,
struct V_67 * V_181 ,
unsigned long V_182 , char * * error )
{
int V_32 ;
void * V_183 ;
struct V_63 * V_63 ;
struct V_184 * V_131 ;
V_131 = F_136 ( V_181 , V_182 ) ;
if ( F_137 ( V_131 ) ) {
* error = L_13 ;
return (struct V_63 * ) V_131 ;
}
V_63 = F_4 ( sizeof( * V_63 ) , V_9 ) ;
if ( ! V_63 ) {
* error = L_14 ;
V_183 = F_138 ( - V_116 ) ;
goto V_185;
}
V_63 -> V_131 = V_131 ;
V_63 -> V_110 = V_182 ;
V_63 -> V_79 = F_139 ( V_182 ) - 1 ;
V_63 -> V_83 = V_182 - 1 ;
V_63 -> V_132 = 0 ;
F_130 ( & V_63 -> V_127 ) ;
V_63 -> V_8 = F_3 ( V_186 ) ;
if ( ! V_63 -> V_8 ) {
* error = L_15 ;
V_183 = F_138 ( - V_116 ) ;
goto V_187;
}
V_63 -> V_126 = F_140 () ;
if ( F_137 ( V_63 -> V_126 ) ) {
V_32 = F_141 ( V_63 -> V_126 ) ;
* error = L_16 ;
V_183 = F_138 ( V_32 ) ;
goto V_188;
}
V_63 -> V_89 = F_142 ( L_17 V_189 , V_190 ) ;
if ( ! V_63 -> V_89 ) {
* error = L_18 ;
V_183 = F_138 ( - V_116 ) ;
goto V_191;
}
F_143 ( & V_63 -> V_90 , F_113 ) ;
F_144 ( & V_63 -> V_157 , F_115 ) ;
F_5 ( & V_63 -> V_10 ) ;
F_22 ( & V_63 -> V_76 ) ;
F_22 ( & V_63 -> V_88 ) ;
F_37 ( & V_63 -> V_95 ) ;
F_37 ( & V_63 -> V_145 ) ;
V_63 -> V_133 = 0 ;
V_63 -> V_136 = 0 ;
F_22 ( & V_63 -> V_77 ) ;
F_36 ( & V_63 -> V_121 ) ;
F_36 ( & V_63 -> V_144 ) ;
V_63 -> V_114 = NULL ;
V_63 -> V_106 = F_6 ( V_192 ,
V_193 ) ;
if ( ! V_63 -> V_106 ) {
* error = L_19 ;
V_183 = F_138 ( - V_116 ) ;
goto V_194;
}
V_63 -> V_158 = F_6 ( V_195 ,
V_196 ) ;
if ( ! V_63 -> V_158 ) {
* error = L_20 ;
V_183 = F_138 ( - V_116 ) ;
goto V_197;
}
V_63 -> V_198 = 1 ;
V_63 -> V_152 = V_151 ;
V_63 -> V_66 = V_66 ;
V_63 -> V_68 = V_181 ;
F_50 ( V_63 ) ;
return V_63 ;
V_197:
F_10 ( V_63 -> V_106 ) ;
V_194:
F_134 ( V_63 -> V_89 ) ;
V_191:
F_133 ( V_63 -> V_126 ) ;
V_188:
F_9 ( V_63 -> V_8 ) ;
V_187:
F_7 ( V_63 ) ;
V_185:
if ( F_132 ( V_131 ) )
F_97 ( L_12 , V_138 ) ;
return V_183 ;
}
static void F_145 ( struct V_63 * V_63 )
{
F_16 ( ! F_51 ( & V_60 . V_61 ) ) ;
V_63 -> V_198 ++ ;
}
static void F_146 ( struct V_63 * V_63 )
{
F_16 ( ! F_51 ( & V_60 . V_61 ) ) ;
F_16 ( ! V_63 -> V_198 ) ;
if ( ! -- V_63 -> V_198 )
F_131 ( V_63 ) ;
}
static struct V_63 * F_147 ( struct V_64 * V_66 ,
struct V_67 * V_181 ,
unsigned long V_182 , char * * error ,
int * V_199 )
{
struct V_63 * V_63 = F_56 ( V_181 ) ;
if ( V_63 ) {
if ( V_63 -> V_66 != V_66 )
return F_138 ( - V_200 ) ;
F_145 ( V_63 ) ;
} else {
V_63 = F_54 ( V_66 ) ;
if ( V_63 ) {
if ( V_63 -> V_68 != V_181 )
return F_138 ( - V_201 ) ;
F_145 ( V_63 ) ;
} else {
V_63 = F_135 ( V_66 , V_181 , V_182 , error ) ;
* V_199 = 1 ;
}
}
return V_63 ;
}
static void F_148 ( struct V_160 * V_134 )
{
struct V_170 * V_171 = V_134 -> V_163 ;
F_149 ( & V_60 . V_61 ) ;
F_129 ( V_171 -> V_63 , V_134 ) ;
F_146 ( V_171 -> V_63 ) ;
F_150 ( V_134 , V_171 -> V_181 ) ;
F_150 ( V_134 , V_171 -> V_175 ) ;
F_7 ( V_171 ) ;
F_151 ( & V_60 . V_61 ) ;
}
static int F_152 ( struct V_202 * V_203 , struct V_179 * V_127 ,
struct V_160 * V_134 )
{
int V_32 ;
unsigned V_204 ;
const char * V_205 ;
static struct V_206 V_207 [] = {
{ 0 , 3 , L_21 } ,
} ;
if ( ! V_203 -> V_204 )
return 0 ;
V_32 = F_153 ( V_207 , V_203 , & V_204 , & V_134 -> error ) ;
if ( V_32 )
return - V_201 ;
while ( V_204 && ! V_32 ) {
V_205 = F_154 ( V_203 ) ;
V_204 -- ;
if ( ! strcasecmp ( V_205 , L_22 ) ) {
V_127 -> V_128 = 0 ;
continue;
} else if ( ! strcasecmp ( V_205 , L_23 ) ) {
V_127 -> V_180 = 0 ;
continue;
} else if ( ! strcasecmp ( V_205 , L_24 ) ) {
V_127 -> V_143 = 0 ;
continue;
}
V_134 -> error = L_25 ;
V_32 = - V_201 ;
}
return V_32 ;
}
static int F_155 ( struct V_160 * V_134 , unsigned V_204 , char * * V_208 )
{
int V_32 , V_209 = 0 ;
struct V_170 * V_171 ;
struct V_63 * V_63 ;
struct V_179 V_127 ;
struct V_202 V_203 ;
struct V_117 * V_175 ;
unsigned long V_182 ;
T_4 V_132 ;
struct V_117 * V_181 ;
T_6 V_210 ;
char V_59 [ V_178 ] ;
F_149 ( & V_60 . V_61 ) ;
if ( V_204 < 4 ) {
V_134 -> error = L_26 ;
V_32 = - V_201 ;
goto V_211;
}
V_203 . V_204 = V_204 ;
V_203 . V_208 = V_208 ;
V_32 = F_156 ( V_134 , V_208 [ 0 ] , V_212 | V_213 , & V_181 ) ;
if ( V_32 ) {
V_134 -> error = L_27 ;
goto V_211;
}
V_210 = F_157 ( V_181 -> V_82 -> V_214 ) >> V_111 ;
if ( V_210 > V_215 )
F_97 ( L_28 ,
F_128 ( V_181 -> V_82 , V_59 ) , V_216 ) ;
V_32 = F_156 ( V_134 , V_208 [ 1 ] , V_212 | V_213 , & V_175 ) ;
if ( V_32 ) {
V_134 -> error = L_29 ;
goto V_217;
}
if ( F_158 ( V_208 [ 2 ] , 10 , & V_182 ) || ! V_182 ||
V_182 < V_218 ||
V_182 > V_219 ||
! F_159 ( V_182 ) ) {
V_134 -> error = L_30 ;
V_32 = - V_201 ;
goto V_36;
}
if ( F_160 ( V_208 [ 3 ] , 10 , ( unsigned long long * ) & V_132 ) ) {
V_134 -> error = L_31 ;
V_32 = - V_201 ;
goto V_36;
}
F_130 ( & V_127 ) ;
F_161 ( & V_203 , 4 ) ;
V_32 = F_152 ( & V_203 , & V_127 , V_134 ) ;
if ( V_32 )
goto V_36;
V_171 = F_162 ( sizeof( * V_171 ) , V_9 ) ;
if ( ! V_171 ) {
V_32 = - V_116 ;
goto V_36;
}
V_63 = F_147 ( F_163 ( V_134 -> V_135 ) , V_181 -> V_82 ,
V_182 , & V_134 -> error , & V_209 ) ;
if ( F_137 ( V_63 ) ) {
V_32 = F_141 ( V_63 ) ;
goto V_220;
}
if ( ! V_209 && V_127 . V_180 != V_63 -> V_127 . V_180 ) {
V_134 -> error = L_32 ;
V_32 = - V_201 ;
goto V_221;
}
V_171 -> V_63 = V_63 ;
V_171 -> V_134 = V_134 ;
V_171 -> V_181 = V_181 ;
V_171 -> V_175 = V_175 ;
V_171 -> V_132 = V_132 ;
V_171 -> V_127 = V_127 ;
V_134 -> V_222 = 1 ;
if ( V_127 . V_180 && V_127 . V_143 ) {
V_134 -> V_223 = 1 ;
V_134 -> V_224 = 1 ;
}
V_134 -> V_163 = V_171 ;
V_171 -> V_172 . V_225 = F_122 ;
F_164 ( V_134 -> V_135 , & V_171 -> V_172 ) ;
F_151 ( & V_60 . V_61 ) ;
return 0 ;
V_221:
F_146 ( V_63 ) ;
V_220:
F_7 ( V_171 ) ;
V_36:
F_150 ( V_134 , V_175 ) ;
V_217:
F_150 ( V_134 , V_181 ) ;
V_211:
F_151 ( & V_60 . V_61 ) ;
return V_32 ;
}
static int F_165 ( struct V_160 * V_134 , struct V_29 * V_29 ,
union V_161 * V_162 )
{
int V_32 ;
struct V_170 * V_171 = V_134 -> V_163 ;
struct V_63 * V_63 = V_171 -> V_63 ;
unsigned long V_33 ;
F_17 ( & V_63 -> V_10 , V_33 ) ;
V_29 -> V_80 = V_171 -> V_175 -> V_82 ;
V_32 = V_165 ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
return V_32 ;
}
static int F_166 ( struct V_160 * V_134 )
{
int V_32 ;
struct V_170 * V_171 = V_134 -> V_163 ;
struct V_63 * V_63 = V_171 -> V_63 ;
T_4 V_226 , V_227 ;
V_32 = F_126 ( V_63 , V_134 ) ;
if ( V_32 )
return V_32 ;
V_226 = V_134 -> V_6 >> V_63 -> V_79 ;
V_32 = F_167 ( V_63 -> V_131 , & V_227 ) ;
if ( V_32 ) {
F_77 ( L_33 ) ;
return V_32 ;
}
if ( V_226 < V_227 ) {
F_77 ( L_34 ,
V_226 , V_227 ) ;
return - V_201 ;
} else if ( V_226 > V_227 ) {
V_32 = F_168 ( V_63 -> V_131 , V_226 ) ;
if ( V_32 ) {
F_77 ( L_35 ) ;
return V_32 ;
}
V_32 = F_100 ( V_63 -> V_131 ) ;
if ( V_32 ) {
F_77 ( L_6 ,
V_138 , V_32 ) ;
return V_32 ;
}
}
return 0 ;
}
static void F_169 ( struct V_160 * V_134 )
{
struct V_170 * V_171 = V_134 -> V_163 ;
struct V_63 * V_63 = V_171 -> V_63 ;
unsigned long V_33 ;
F_17 ( & V_63 -> V_10 , V_33 ) ;
V_63 -> V_133 = 0 ;
V_63 -> V_136 = 0 ;
F_125 ( V_63 ) ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
F_115 ( & V_63 -> V_157 . V_55 ) ;
}
static void F_170 ( struct V_160 * V_134 )
{
int V_32 ;
struct V_170 * V_171 = V_134 -> V_163 ;
struct V_63 * V_63 = V_171 -> V_63 ;
F_171 ( & V_63 -> V_157 ) ;
F_172 ( V_63 -> V_89 ) ;
V_32 = F_100 ( V_63 -> V_131 ) ;
if ( V_32 < 0 ) {
F_77 ( L_6 ,
V_138 , V_32 ) ;
}
}
static int F_173 ( unsigned V_204 , unsigned V_228 )
{
if ( V_204 != V_228 ) {
F_97 ( L_36 ,
V_204 , V_228 ) ;
return - V_201 ;
}
return 0 ;
}
static int F_174 ( char * V_229 , T_7 * V_230 , int V_231 )
{
if ( ! F_160 ( V_229 , 10 , ( unsigned long long * ) V_230 ) &&
* V_230 <= V_232 )
return 0 ;
if ( V_231 )
F_97 ( L_37 , V_229 ) ;
return - V_201 ;
}
static int F_175 ( unsigned V_204 , char * * V_208 , struct V_63 * V_63 )
{
T_7 V_230 ;
int V_32 ;
V_32 = F_173 ( V_204 , 2 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_174 ( V_208 [ 1 ] , & V_230 , 1 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_176 ( V_63 -> V_131 , V_230 ) ;
if ( V_32 ) {
F_97 ( L_38 ,
V_208 [ 1 ] ) ;
return V_32 ;
}
return 0 ;
}
static int F_177 ( unsigned V_204 , char * * V_208 , struct V_63 * V_63 )
{
T_7 V_230 ;
T_7 V_233 ;
int V_32 ;
V_32 = F_173 ( V_204 , 3 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_174 ( V_208 [ 1 ] , & V_230 , 1 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_174 ( V_208 [ 2 ] , & V_233 , 1 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_178 ( V_63 -> V_131 , V_230 , V_233 ) ;
if ( V_32 ) {
F_97 ( L_39 ,
V_208 [ 1 ] , V_208 [ 2 ] ) ;
return V_32 ;
}
return 0 ;
}
static int F_179 ( unsigned V_204 , char * * V_208 , struct V_63 * V_63 )
{
T_7 V_230 ;
int V_32 ;
V_32 = F_173 ( V_204 , 2 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_174 ( V_208 [ 1 ] , & V_230 , 1 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_180 ( V_63 -> V_131 , V_230 ) ;
if ( V_32 )
F_97 ( L_40 , V_208 [ 1 ] ) ;
return V_32 ;
}
static int F_181 ( unsigned V_204 , char * * V_208 , struct V_63 * V_63 )
{
T_7 V_234 , V_235 ;
int V_32 ;
V_32 = F_173 ( V_204 , 3 ) ;
if ( V_32 )
return V_32 ;
if ( F_160 ( V_208 [ 1 ] , 10 , ( unsigned long long * ) & V_234 ) ) {
F_97 ( L_41 , V_208 [ 1 ] ) ;
return - V_201 ;
}
if ( F_160 ( V_208 [ 2 ] , 10 , ( unsigned long long * ) & V_235 ) ) {
F_97 ( L_42 , V_208 [ 2 ] ) ;
return - V_201 ;
}
V_32 = F_182 ( V_63 -> V_131 , V_234 , V_235 ) ;
if ( V_32 ) {
F_97 ( L_43 ,
V_208 [ 1 ] , V_208 [ 2 ] ) ;
return V_32 ;
}
return 0 ;
}
static int F_183 ( unsigned V_204 , char * * V_208 , struct V_63 * V_63 )
{
int V_32 ;
V_32 = F_173 ( V_204 , 1 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_100 ( V_63 -> V_131 ) ;
if ( V_32 ) {
F_77 ( L_6 ,
V_138 , V_32 ) ;
return V_32 ;
}
V_32 = F_184 ( V_63 -> V_131 ) ;
if ( V_32 )
F_97 ( L_44 ) ;
return V_32 ;
}
static int F_185 ( unsigned V_204 , char * * V_208 , struct V_63 * V_63 )
{
int V_32 ;
V_32 = F_173 ( V_204 , 1 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_186 ( V_63 -> V_131 ) ;
if ( V_32 )
F_97 ( L_45 ) ;
return V_32 ;
}
static int F_187 ( struct V_160 * V_134 , unsigned V_204 , char * * V_208 )
{
int V_32 = - V_201 ;
struct V_170 * V_171 = V_134 -> V_163 ;
struct V_63 * V_63 = V_171 -> V_63 ;
if ( ! strcasecmp ( V_208 [ 0 ] , L_46 ) )
V_32 = F_175 ( V_204 , V_208 , V_63 ) ;
else if ( ! strcasecmp ( V_208 [ 0 ] , L_47 ) )
V_32 = F_177 ( V_204 , V_208 , V_63 ) ;
else if ( ! strcasecmp ( V_208 [ 0 ] , L_48 ) )
V_32 = F_179 ( V_204 , V_208 , V_63 ) ;
else if ( ! strcasecmp ( V_208 [ 0 ] , L_49 ) )
V_32 = F_181 ( V_204 , V_208 , V_63 ) ;
else if ( ! strcasecmp ( V_208 [ 0 ] , L_50 ) )
V_32 = F_183 ( V_204 , V_208 , V_63 ) ;
else if ( ! strcasecmp ( V_208 [ 0 ] , L_51 ) )
V_32 = F_185 ( V_204 , V_208 , V_63 ) ;
else
F_97 ( L_52 , V_208 [ 0 ] ) ;
if ( ! V_32 ) {
V_32 = F_100 ( V_63 -> V_131 ) ;
if ( V_32 )
F_77 ( L_53 ,
V_208 [ 0 ] , V_32 ) ;
}
return V_32 ;
}
static int F_188 ( struct V_160 * V_134 , T_8 type ,
char * V_129 , unsigned V_236 )
{
int V_32 , V_48 ;
unsigned V_237 = 0 ;
T_3 V_238 ;
T_4 V_239 ;
T_4 V_240 ;
T_4 V_241 ;
T_4 V_242 ;
T_4 V_243 ;
char V_177 [ V_178 ] ;
char V_244 [ V_178 ] ;
struct V_170 * V_171 = V_134 -> V_163 ;
struct V_63 * V_63 = V_171 -> V_63 ;
switch ( type ) {
case V_245 :
V_32 = F_189 ( V_63 -> V_131 ,
& V_238 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_190 ( V_63 -> V_131 ,
& V_240 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_191 ( V_63 -> V_131 , & V_242 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_96 ( V_63 -> V_131 ,
& V_239 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_167 ( V_63 -> V_131 , & V_241 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_192 ( V_63 -> V_131 , & V_243 ) ;
if ( V_32 )
return V_32 ;
F_193 ( L_54 ,
( unsigned long long ) V_238 ,
( unsigned long long ) ( V_242 - V_240 ) ,
( unsigned long long ) V_242 ,
( unsigned long long ) ( V_241 - V_239 ) ,
( unsigned long long ) V_241 ) ;
if ( V_243 )
F_193 ( L_55 , V_243 ) ;
else
F_193 ( L_56 ) ;
break;
case V_246 :
F_193 ( L_57 ,
F_194 ( V_177 , V_171 -> V_181 -> V_82 -> V_247 ) ,
F_194 ( V_244 , V_171 -> V_175 -> V_82 -> V_247 ) ,
( unsigned long ) V_63 -> V_110 ,
( unsigned long long ) V_171 -> V_132 ) ;
V_48 = ! V_63 -> V_127 . V_128 + ! V_63 -> V_127 . V_180 +
! V_171 -> V_127 . V_143 ;
F_193 ( L_58 , V_48 ) ;
if ( ! V_63 -> V_127 . V_128 )
F_193 ( L_59 ) ;
if ( ! V_63 -> V_127 . V_180 )
F_193 ( L_60 ) ;
if ( ! V_171 -> V_127 . V_143 )
F_193 ( L_61 ) ;
break;
}
return 0 ;
}
static int F_195 ( struct V_160 * V_134 ,
T_9 F_81 , void * V_248 )
{
struct V_170 * V_171 = V_134 -> V_163 ;
return F_81 ( V_134 , V_171 -> V_175 , 0 , V_134 -> V_6 , V_248 ) ;
}
static int F_196 ( struct V_160 * V_134 , struct V_249 * V_250 ,
struct V_251 * V_252 , int V_253 )
{
struct V_170 * V_171 = V_134 -> V_163 ;
struct V_173 * V_174 = F_123 ( V_171 -> V_175 -> V_82 ) ;
if ( ! V_174 -> V_254 )
return V_253 ;
V_250 -> V_80 = V_171 -> V_175 -> V_82 ;
return F_2 ( V_253 , V_174 -> V_254 ( V_174 , V_250 , V_252 ) ) ;
}
static void F_197 ( struct V_63 * V_63 , struct V_255 * V_256 )
{
V_256 -> V_257 = V_63 -> V_110 ;
V_256 -> V_258 = V_63 -> V_110 << V_111 ;
V_256 -> V_259 = V_63 -> V_127 . V_128 ;
}
static void F_198 ( struct V_160 * V_134 , struct V_255 * V_256 )
{
struct V_170 * V_171 = V_134 -> V_163 ;
struct V_63 * V_63 = V_171 -> V_63 ;
F_199 ( V_256 , 0 ) ;
F_200 ( V_256 , V_63 -> V_110 << V_111 ) ;
if ( V_63 -> V_127 . V_180 )
F_197 ( V_63 , V_256 ) ;
}
static void F_201 ( struct V_160 * V_134 )
{
struct V_69 * V_70 = V_134 -> V_163 ;
F_149 ( & V_60 . V_61 ) ;
F_146 ( V_70 -> V_63 ) ;
F_202 ( V_70 -> V_58 ) ;
F_150 ( V_134 , V_70 -> V_81 ) ;
if ( V_70 -> V_84 )
F_150 ( V_134 , V_70 -> V_84 ) ;
F_7 ( V_70 ) ;
F_151 ( & V_60 . V_61 ) ;
}
static int F_203 ( struct V_160 * V_134 , unsigned V_204 , char * * V_208 )
{
int V_32 ;
struct V_69 * V_70 ;
struct V_117 * V_81 , * V_84 ;
struct V_64 * V_66 ;
F_149 ( & V_60 . V_61 ) ;
if ( V_204 != 2 && V_204 != 3 ) {
V_134 -> error = L_26 ;
V_32 = - V_201 ;
goto V_211;
}
V_70 = V_134 -> V_163 = F_162 ( sizeof( * V_70 ) , V_9 ) ;
if ( ! V_70 ) {
V_134 -> error = L_62 ;
V_32 = - V_116 ;
goto V_211;
}
if ( V_204 == 3 ) {
V_32 = F_156 ( V_134 , V_208 [ 2 ] , V_212 , & V_84 ) ;
if ( V_32 ) {
V_134 -> error = L_63 ;
goto V_260;
}
V_70 -> V_84 = V_84 ;
}
V_32 = F_156 ( V_134 , V_208 [ 0 ] , F_204 ( V_134 -> V_135 ) , & V_81 ) ;
if ( V_32 ) {
V_134 -> error = L_64 ;
goto V_261;
}
V_70 -> V_81 = V_81 ;
if ( F_174 ( V_208 [ 1 ] , ( unsigned long long * ) & V_70 -> V_230 , 0 ) ) {
V_134 -> error = L_65 ;
V_32 = - V_201 ;
goto V_262;
}
V_66 = F_205 ( V_70 -> V_81 -> V_82 -> V_247 ) ;
if ( ! V_66 ) {
V_134 -> error = L_66 ;
V_32 = - V_201 ;
goto V_262;
}
V_70 -> V_63 = F_54 ( V_66 ) ;
if ( ! V_70 -> V_63 ) {
V_134 -> error = L_67 ;
V_32 = - V_201 ;
goto V_263;
}
F_145 ( V_70 -> V_63 ) ;
V_32 = F_206 ( V_70 -> V_63 -> V_131 , V_70 -> V_230 , & V_70 -> V_58 ) ;
if ( V_32 ) {
V_134 -> error = L_68 ;
goto V_264;
}
V_134 -> V_265 = V_70 -> V_63 -> V_110 ;
V_134 -> V_222 = 1 ;
if ( V_70 -> V_63 -> V_127 . V_180 ) {
V_134 -> V_224 = 1 ;
V_134 -> V_223 = 1 ;
V_134 -> V_266 = 1 ;
}
F_207 ( V_66 ) ;
F_151 ( & V_60 . V_61 ) ;
return 0 ;
V_264:
F_146 ( V_70 -> V_63 ) ;
V_263:
F_207 ( V_66 ) ;
V_262:
F_150 ( V_134 , V_70 -> V_81 ) ;
V_261:
if ( V_70 -> V_84 )
F_150 ( V_134 , V_70 -> V_84 ) ;
V_260:
F_7 ( V_70 ) ;
V_211:
F_151 ( & V_60 . V_61 ) ;
return V_32 ;
}
static int F_208 ( struct V_160 * V_134 , struct V_29 * V_29 ,
union V_161 * V_162 )
{
V_29 -> V_78 = F_209 ( V_134 , V_29 -> V_78 ) ;
return F_120 ( V_134 , V_29 , V_162 ) ;
}
static int F_210 ( struct V_160 * V_134 ,
struct V_29 * V_29 , int V_99 ,
union V_161 * V_162 )
{
unsigned long V_33 ;
struct V_72 * V_73 = V_162 -> V_74 ;
struct V_53 V_55 ;
struct V_91 * V_92 , * V_28 ;
struct V_63 * V_63 = V_73 -> V_70 -> V_63 ;
if ( V_73 -> V_149 ) {
F_37 ( & V_55 ) ;
F_42 ( V_73 -> V_149 , & V_55 ) ;
F_17 ( & V_63 -> V_10 , V_33 ) ;
F_82 (m, tmp, &work, list) {
F_53 ( & V_92 -> V_39 ) ;
V_92 -> V_93 = 1 ;
F_70 ( V_92 ) ;
}
F_19 ( & V_63 -> V_10 , V_33 ) ;
}
if ( V_73 -> V_159 ) {
F_37 ( & V_55 ) ;
F_42 ( V_73 -> V_159 , & V_55 ) ;
F_17 ( & V_63 -> V_10 , V_33 ) ;
F_82 (m, tmp, &work, list)
F_44 ( & V_92 -> V_39 , & V_63 -> V_145 ) ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
}
F_21 ( V_73 , V_63 -> V_158 ) ;
return 0 ;
}
static void F_211 ( struct V_160 * V_134 )
{
if ( F_212 ( V_134 ) )
F_60 ( (struct V_69 * ) V_134 -> V_163 ) ;
}
static int F_213 ( struct V_160 * V_134 , T_8 type ,
char * V_129 , unsigned V_236 )
{
int V_32 ;
T_10 V_237 = 0 ;
T_4 V_267 , V_268 ;
char V_177 [ V_178 ] ;
struct V_69 * V_70 = V_134 -> V_163 ;
if ( ! V_70 -> V_58 )
F_193 ( L_56 ) ;
else {
switch ( type ) {
case V_245 :
V_32 = F_214 ( V_70 -> V_58 , & V_267 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_215 ( V_70 -> V_58 , & V_268 ) ;
if ( V_32 < 0 )
return V_32 ;
F_193 ( L_69 , V_267 * V_70 -> V_63 -> V_110 ) ;
if ( V_32 )
F_193 ( L_55 , ( ( V_268 + 1 ) *
V_70 -> V_63 -> V_110 ) - 1 ) ;
else
F_193 ( L_56 ) ;
break;
case V_246 :
F_193 ( L_70 ,
F_194 ( V_177 , V_70 -> V_81 -> V_82 -> V_247 ) ,
( unsigned long ) V_70 -> V_230 ) ;
if ( V_70 -> V_84 )
F_193 ( L_71 , F_194 ( V_177 , V_70 -> V_84 -> V_82 -> V_247 ) ) ;
break;
}
}
return 0 ;
}
static int F_216 ( struct V_160 * V_134 ,
T_9 F_81 , void * V_248 )
{
T_4 V_269 ;
struct V_69 * V_70 = V_134 -> V_163 ;
if ( ! V_70 -> V_63 -> V_134 )
return 0 ;
V_269 = V_70 -> V_63 -> V_134 -> V_6 >> V_70 -> V_63 -> V_79 ;
if ( V_269 )
return F_81 ( V_134 , V_70 -> V_81 , 0 , V_70 -> V_63 -> V_110 * V_269 , V_248 ) ;
return 0 ;
}
static void F_217 ( struct V_160 * V_134 , struct V_255 * V_256 )
{
struct V_69 * V_70 = V_134 -> V_163 ;
struct V_63 * V_63 = V_70 -> V_63 ;
F_199 ( V_256 , 0 ) ;
F_200 ( V_256 , V_63 -> V_110 << V_111 ) ;
F_197 ( V_63 , V_256 ) ;
}
static int T_11 F_218 ( void )
{
int V_32 ;
F_48 () ;
V_32 = F_219 ( & V_270 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_219 ( & V_271 ) ;
if ( V_32 )
goto V_272;
V_32 = - V_116 ;
V_12 = F_220 ( V_24 , 0 ) ;
if ( ! V_12 )
goto V_273;
V_193 = F_220 ( V_91 , 0 ) ;
if ( ! V_193 )
goto V_274;
V_196 = F_220 ( V_72 , 0 ) ;
if ( ! V_196 )
goto V_275;
return 0 ;
V_275:
F_221 ( V_193 ) ;
V_274:
F_221 ( V_12 ) ;
V_273:
F_222 ( & V_271 ) ;
V_272:
F_222 ( & V_270 ) ;
return V_32 ;
}
static void F_223 ( void )
{
F_222 ( & V_270 ) ;
F_222 ( & V_271 ) ;
F_221 ( V_12 ) ;
F_221 ( V_193 ) ;
F_221 ( V_196 ) ;
}
