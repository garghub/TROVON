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
T_5 V_78 = V_29 -> V_79 ;
if ( V_70 -> V_63 -> V_80 < 0 )
( void ) F_62 ( V_78 , V_70 -> V_63 -> V_81 ) ;
else
V_78 >>= V_70 -> V_63 -> V_80 ;
return V_78 ;
}
static void F_63 ( struct V_69 * V_70 , struct V_29 * V_29 , T_4 V_19 )
{
struct V_63 * V_63 = V_70 -> V_63 ;
T_5 V_79 = V_29 -> V_79 ;
V_29 -> V_82 = V_70 -> V_83 -> V_84 ;
if ( V_70 -> V_63 -> V_80 < 0 )
V_29 -> V_79 = ( V_19 * V_63 -> V_81 ) +
F_62 ( V_79 , V_63 -> V_81 ) ;
else
V_29 -> V_79 = ( V_19 << V_63 -> V_80 ) |
( V_79 & ( V_63 -> V_81 - 1 ) ) ;
}
static void F_64 ( struct V_69 * V_70 , struct V_29 * V_29 )
{
V_29 -> V_82 = V_70 -> V_85 -> V_84 ;
}
static int F_65 ( struct V_69 * V_70 , struct V_29 * V_29 )
{
return ( V_29 -> V_86 & ( V_87 | V_88 ) ) &&
F_66 ( V_70 -> V_58 ) ;
}
static void F_67 ( struct V_69 * V_70 , struct V_29 * V_29 )
{
struct V_63 * V_63 = V_70 -> V_63 ;
unsigned long V_33 ;
if ( ! F_65 ( V_70 , V_29 ) ) {
F_68 ( V_29 ) ;
return;
}
if ( F_69 ( V_70 -> V_58 ) ) {
F_35 ( V_29 ) ;
return;
}
F_17 ( & V_63 -> V_10 , V_33 ) ;
F_18 ( & V_63 -> V_89 , V_29 ) ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
}
static void F_70 ( struct V_69 * V_70 , struct V_29 * V_29 )
{
F_64 ( V_70 , V_29 ) ;
F_67 ( V_70 , V_29 ) ;
}
static void F_71 ( struct V_69 * V_70 , struct V_29 * V_29 ,
T_4 V_19 )
{
F_63 ( V_70 , V_29 , V_19 ) ;
F_67 ( V_70 , V_29 ) ;
}
static void F_72 ( struct V_63 * V_63 )
{
F_73 ( V_63 -> V_90 , & V_63 -> V_91 ) ;
}
static void F_74 ( struct V_92 * V_93 )
{
struct V_63 * V_63 = V_93 -> V_70 -> V_63 ;
if ( V_93 -> V_94 && V_93 -> V_95 ) {
F_44 ( & V_93 -> V_39 , & V_63 -> V_96 ) ;
F_72 ( V_63 ) ;
}
}
static void F_75 ( int V_97 , unsigned long V_98 , void * V_99 )
{
unsigned long V_33 ;
struct V_92 * V_93 = V_99 ;
struct V_63 * V_63 = V_93 -> V_70 -> V_63 ;
V_93 -> V_100 = V_97 || V_98 ? - V_101 : 0 ;
F_17 ( & V_63 -> V_10 , V_33 ) ;
V_93 -> V_95 = 1 ;
F_74 ( V_93 ) ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
}
static void F_76 ( struct V_29 * V_29 , int V_100 )
{
unsigned long V_33 ;
struct V_72 * V_73 = F_58 ( V_29 ) -> V_74 ;
struct V_92 * V_93 = V_73 -> V_102 ;
struct V_63 * V_63 = V_93 -> V_70 -> V_63 ;
V_93 -> V_100 = V_100 ;
F_17 ( & V_63 -> V_10 , V_33 ) ;
V_93 -> V_95 = 1 ;
F_74 ( V_93 ) ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
}
static void F_77 ( struct V_69 * V_70 , struct V_24 * V_26 ,
T_4 V_103 )
{
struct V_63 * V_63 = V_70 -> V_63 ;
unsigned long V_33 ;
F_17 ( & V_63 -> V_10 , V_33 ) ;
F_27 ( V_26 , & V_63 -> V_76 ) ;
F_19 ( & V_70 -> V_63 -> V_10 , V_33 ) ;
F_72 ( V_63 ) ;
}
static void F_78 ( struct V_69 * V_70 , struct V_24 * V_26 )
{
struct V_40 V_35 ;
struct V_63 * V_63 = V_70 -> V_63 ;
unsigned long V_33 ;
F_22 ( & V_35 ) ;
F_17 ( & V_63 -> V_10 , V_33 ) ;
F_32 ( V_26 , & V_63 -> V_76 ) ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
F_72 ( V_63 ) ;
}
static void F_79 ( struct V_92 * V_93 )
{
if ( V_93 -> V_29 )
V_93 -> V_29 -> V_104 = V_93 -> V_105 ;
F_33 ( V_93 -> V_26 ) ;
F_53 ( & V_93 -> V_39 ) ;
F_21 ( V_93 , V_93 -> V_70 -> V_63 -> V_106 ) ;
}
static void F_80 ( struct V_92 * V_93 )
{
struct V_69 * V_70 = V_93 -> V_70 ;
struct V_29 * V_29 ;
int V_32 ;
V_29 = V_93 -> V_29 ;
if ( V_29 )
V_29 -> V_104 = V_93 -> V_105 ;
if ( V_93 -> V_100 ) {
F_33 ( V_93 -> V_26 ) ;
goto V_36;
}
V_32 = F_81 ( V_70 -> V_58 , V_93 -> V_107 , V_93 -> V_103 ) ;
if ( V_32 ) {
F_82 ( L_1 ) ;
F_33 ( V_93 -> V_26 ) ;
goto V_36;
}
if ( V_29 ) {
F_78 ( V_70 , V_93 -> V_26 ) ;
F_59 ( V_29 , 0 ) ;
} else
F_77 ( V_70 , V_93 -> V_26 , V_93 -> V_103 ) ;
V_36:
F_53 ( & V_93 -> V_39 ) ;
F_21 ( V_93 , V_70 -> V_63 -> V_106 ) ;
}
static void F_83 ( struct V_92 * V_93 )
{
struct V_69 * V_70 = V_93 -> V_70 ;
F_35 ( V_93 -> V_29 ) ;
F_78 ( V_70 , V_93 -> V_26 ) ;
F_78 ( V_70 , V_93 -> V_34 ) ;
F_21 ( V_93 , V_70 -> V_63 -> V_106 ) ;
}
static void F_84 ( struct V_92 * V_93 )
{
struct V_69 * V_70 = V_93 -> V_70 ;
if ( V_93 -> V_108 )
F_71 ( V_70 , V_93 -> V_29 , V_93 -> V_103 ) ;
else
F_59 ( V_93 -> V_29 , 0 ) ;
F_78 ( V_70 , V_93 -> V_26 ) ;
F_78 ( V_70 , V_93 -> V_34 ) ;
F_21 ( V_93 , V_70 -> V_63 -> V_106 ) ;
}
static void F_85 ( struct V_92 * V_93 )
{
int V_32 ;
struct V_69 * V_70 = V_93 -> V_70 ;
V_32 = F_86 ( V_70 -> V_58 , V_93 -> V_107 ) ;
if ( V_32 )
F_82 ( L_2 ) ;
F_84 ( V_93 ) ;
}
static void F_87 ( struct V_63 * V_63 , struct V_53 * V_54 ,
T_6 * V_109 )
{
unsigned long V_33 ;
struct V_53 V_110 ;
struct V_92 * V_93 , * V_28 ;
F_37 ( & V_110 ) ;
F_17 ( & V_63 -> V_10 , V_33 ) ;
F_41 ( V_54 , & V_110 ) ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
F_88 ( V_93 , V_28 , & V_110 , V_39 )
( * V_109 ) ( V_93 ) ;
}
static int F_89 ( struct V_63 * V_63 , struct V_29 * V_29 )
{
return V_29 -> V_111 == ( V_63 -> V_81 << V_112 ) ;
}
static int F_90 ( struct V_63 * V_63 , struct V_29 * V_29 )
{
return ( F_91 ( V_29 ) == V_113 ) &&
F_89 ( V_63 , V_29 ) ;
}
static void F_92 ( struct V_29 * V_29 , T_7 * * V_114 ,
T_7 * V_109 )
{
* V_114 = V_29 -> V_104 ;
V_29 -> V_104 = V_109 ;
}
static int F_93 ( struct V_63 * V_63 )
{
if ( V_63 -> V_115 )
return 0 ;
V_63 -> V_115 = F_20 ( V_63 -> V_106 , V_116 ) ;
return V_63 -> V_115 ? 0 : - V_117 ;
}
static struct V_92 * F_94 ( struct V_63 * V_63 )
{
struct V_92 * V_32 = V_63 -> V_115 ;
F_16 ( ! V_63 -> V_115 ) ;
V_63 -> V_115 = NULL ;
return V_32 ;
}
static void F_95 ( struct V_69 * V_70 , T_4 V_107 ,
struct V_118 * V_119 , T_4 V_120 ,
T_4 V_121 ,
struct V_24 * V_26 , struct V_29 * V_29 )
{
int V_32 ;
struct V_63 * V_63 = V_70 -> V_63 ;
struct V_92 * V_93 = F_94 ( V_63 ) ;
F_37 ( & V_93 -> V_39 ) ;
V_93 -> V_94 = 0 ;
V_93 -> V_95 = 0 ;
V_93 -> V_70 = V_70 ;
V_93 -> V_107 = V_107 ;
V_93 -> V_103 = V_121 ;
V_93 -> V_26 = V_26 ;
V_93 -> V_100 = 0 ;
V_93 -> V_29 = NULL ;
if ( ! F_43 ( & V_63 -> V_122 , & V_93 -> V_39 ) )
V_93 -> V_94 = 1 ;
if ( F_90 ( V_63 , V_29 ) ) {
struct V_72 * V_73 = F_58 ( V_29 ) -> V_74 ;
V_73 -> V_102 = V_93 ;
V_93 -> V_29 = V_29 ;
F_92 ( V_29 , & V_93 -> V_105 , F_76 ) ;
F_71 ( V_70 , V_29 , V_121 ) ;
} else {
struct V_123 V_124 , V_125 ;
V_124 . V_84 = V_119 -> V_84 ;
V_124 . V_126 = V_120 * V_63 -> V_81 ;
V_124 . V_48 = V_63 -> V_81 ;
V_125 . V_84 = V_70 -> V_83 -> V_84 ;
V_125 . V_126 = V_121 * V_63 -> V_81 ;
V_125 . V_48 = V_63 -> V_81 ;
V_32 = F_96 ( V_63 -> V_127 , & V_124 , 1 , & V_125 ,
0 , F_75 , V_93 ) ;
if ( V_32 < 0 ) {
F_21 ( V_93 , V_63 -> V_106 ) ;
F_82 ( L_3 ) ;
F_33 ( V_26 ) ;
}
}
}
static void F_97 ( struct V_69 * V_70 , T_4 V_107 ,
T_4 V_120 , T_4 V_121 ,
struct V_24 * V_26 , struct V_29 * V_29 )
{
F_95 ( V_70 , V_107 , V_70 -> V_83 ,
V_120 , V_121 , V_26 , V_29 ) ;
}
static void F_98 ( struct V_69 * V_70 , T_4 V_107 ,
T_4 V_121 ,
struct V_24 * V_26 , struct V_29 * V_29 )
{
F_95 ( V_70 , V_107 , V_70 -> V_85 ,
V_107 , V_121 , V_26 , V_29 ) ;
}
static void F_99 ( struct V_69 * V_70 , T_4 V_107 ,
T_4 V_103 , struct V_24 * V_26 ,
struct V_29 * V_29 )
{
struct V_63 * V_63 = V_70 -> V_63 ;
struct V_92 * V_93 = F_94 ( V_63 ) ;
F_37 ( & V_93 -> V_39 ) ;
V_93 -> V_94 = 1 ;
V_93 -> V_95 = 0 ;
V_93 -> V_70 = V_70 ;
V_93 -> V_107 = V_107 ;
V_93 -> V_103 = V_103 ;
V_93 -> V_26 = V_26 ;
V_93 -> V_100 = 0 ;
V_93 -> V_29 = NULL ;
if ( ! V_63 -> V_128 . V_129 )
F_80 ( V_93 ) ;
else if ( F_90 ( V_63 , V_29 ) ) {
struct V_72 * V_73 = F_58 ( V_29 ) -> V_74 ;
V_73 -> V_102 = V_93 ;
V_93 -> V_29 = V_29 ;
F_92 ( V_29 , & V_93 -> V_105 , F_76 ) ;
F_71 ( V_70 , V_29 , V_103 ) ;
} else {
int V_32 ;
struct V_123 V_125 ;
V_125 . V_84 = V_70 -> V_83 -> V_84 ;
V_125 . V_126 = V_103 * V_63 -> V_81 ;
V_125 . V_48 = V_63 -> V_81 ;
V_32 = F_100 ( V_63 -> V_127 , 1 , & V_125 , 0 , F_75 , V_93 ) ;
if ( V_32 < 0 ) {
F_21 ( V_93 , V_63 -> V_106 ) ;
F_82 ( L_4 ) ;
F_33 ( V_26 ) ;
}
}
}
static int F_101 ( struct V_63 * V_63 )
{
int V_32 ;
V_32 = F_102 ( V_63 -> V_130 ) ;
if ( V_32 )
F_82 ( L_5 , V_32 ) ;
return V_32 ;
}
static int F_103 ( struct V_63 * V_63 )
{
int V_32 ;
if ( F_104 ( V_63 ) != V_131 )
return - V_132 ;
V_32 = F_101 ( V_63 ) ;
if ( V_32 )
F_105 ( V_63 , V_133 ) ;
return V_32 ;
}
static int F_106 ( struct V_69 * V_70 , T_4 * V_134 )
{
int V_32 ;
T_4 V_135 ;
unsigned long V_33 ;
struct V_63 * V_63 = V_70 -> V_63 ;
V_32 = F_107 ( V_63 -> V_130 , & V_135 ) ;
if ( V_32 )
return V_32 ;
if ( V_135 <= V_63 -> V_136 && ! V_63 -> V_137 ) {
F_108 ( L_6 ,
F_109 ( V_63 -> V_66 ) ) ;
F_17 ( & V_63 -> V_10 , V_33 ) ;
V_63 -> V_137 = 1 ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
F_110 ( V_63 -> V_138 -> V_139 ) ;
}
if ( ! V_135 ) {
if ( V_63 -> V_140 )
return - V_141 ;
else {
( void ) F_103 ( V_63 ) ;
V_32 = F_107 ( V_63 -> V_130 , & V_135 ) ;
if ( V_32 )
return V_32 ;
if ( ! V_135 ) {
F_108 ( L_7 ,
F_109 ( V_63 -> V_66 ) ) ;
F_17 ( & V_63 -> V_10 , V_33 ) ;
V_63 -> V_140 = 1 ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
return - V_141 ;
}
}
}
V_32 = F_111 ( V_63 -> V_130 , V_134 ) ;
if ( V_32 )
return V_32 ;
return 0 ;
}
static void F_112 ( struct V_29 * V_29 )
{
struct V_72 * V_73 = F_58 ( V_29 ) -> V_74 ;
struct V_69 * V_70 = V_73 -> V_70 ;
struct V_63 * V_63 = V_70 -> V_63 ;
unsigned long V_33 ;
F_17 ( & V_63 -> V_10 , V_33 ) ;
F_18 ( & V_63 -> V_77 , V_29 ) ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
}
static void F_113 ( struct V_24 * V_26 )
{
struct V_29 * V_29 ;
struct V_40 V_35 ;
F_22 ( & V_35 ) ;
F_27 ( V_26 , & V_35 ) ;
while ( ( V_29 = F_34 ( & V_35 ) ) )
F_112 ( V_29 ) ;
}
static void F_114 ( struct V_69 * V_70 , struct V_29 * V_29 )
{
int V_32 ;
unsigned long V_33 ;
struct V_63 * V_63 = V_70 -> V_63 ;
struct V_24 * V_26 , * V_34 ;
struct V_15 V_16 , V_142 ;
T_4 V_19 = F_61 ( V_70 , V_29 ) ;
struct V_143 V_144 ;
struct V_92 * V_93 ;
F_47 ( V_70 -> V_58 , V_19 , & V_16 ) ;
if ( F_15 ( V_70 -> V_63 -> V_8 , & V_16 , V_29 , & V_26 ) )
return;
V_32 = F_115 ( V_70 -> V_58 , V_19 , 1 , & V_144 ) ;
switch ( V_32 ) {
case 0 :
F_45 ( V_70 -> V_58 , V_144 . V_19 , & V_142 ) ;
if ( F_15 ( V_70 -> V_63 -> V_8 , & V_142 , V_29 , & V_34 ) ) {
F_30 ( V_26 , V_29 ) ;
break;
}
if ( F_89 ( V_63 , V_29 ) ) {
V_93 = F_94 ( V_63 ) ;
V_93 -> V_70 = V_70 ;
V_93 -> V_108 = ( ! V_144 . V_145 ) && V_63 -> V_128 . V_146 ;
V_93 -> V_107 = V_19 ;
V_93 -> V_103 = V_144 . V_19 ;
V_93 -> V_26 = V_26 ;
V_93 -> V_34 = V_34 ;
V_93 -> V_100 = 0 ;
V_93 -> V_29 = V_29 ;
if ( ! F_43 ( & V_63 -> V_147 , & V_93 -> V_39 ) ) {
F_17 ( & V_63 -> V_10 , V_33 ) ;
F_44 ( & V_93 -> V_39 , & V_63 -> V_148 ) ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
F_72 ( V_63 ) ;
}
} else {
F_30 ( V_26 , V_29 ) ;
F_30 ( V_34 , V_29 ) ;
if ( ( ! V_144 . V_145 ) && V_63 -> V_128 . V_146 )
F_71 ( V_70 , V_29 , V_144 . V_19 ) ;
else
F_59 ( V_29 , 0 ) ;
}
break;
case - V_149 :
F_30 ( V_26 , V_29 ) ;
F_59 ( V_29 , 0 ) ;
break;
default:
F_82 ( L_8 , V_32 ) ;
F_30 ( V_26 , V_29 ) ;
F_35 ( V_29 ) ;
break;
}
}
static void F_116 ( struct V_69 * V_70 , struct V_29 * V_29 , T_4 V_19 ,
struct V_15 * V_16 ,
struct V_143 * V_144 ,
struct V_24 * V_26 )
{
int V_32 ;
T_4 V_103 ;
V_32 = F_106 ( V_70 , & V_103 ) ;
switch ( V_32 ) {
case 0 :
F_97 ( V_70 , V_19 , V_144 -> V_19 ,
V_103 , V_26 , V_29 ) ;
break;
case - V_141 :
F_113 ( V_26 ) ;
break;
default:
F_82 ( L_9 , V_150 , V_32 ) ;
F_33 ( V_26 ) ;
break;
}
}
static void F_117 ( struct V_69 * V_70 , struct V_29 * V_29 ,
T_4 V_19 ,
struct V_143 * V_144 )
{
struct V_24 * V_26 ;
struct V_63 * V_63 = V_70 -> V_63 ;
struct V_15 V_16 ;
F_45 ( V_70 -> V_58 , V_144 -> V_19 , & V_16 ) ;
if ( F_15 ( V_63 -> V_8 , & V_16 , V_29 , & V_26 ) )
return;
if ( F_91 ( V_29 ) == V_113 && V_29 -> V_111 )
F_116 ( V_70 , V_29 , V_19 , & V_16 , V_144 , V_26 ) ;
else {
struct V_72 * V_73 = F_58 ( V_29 ) -> V_74 ;
V_73 -> V_151 = F_38 ( & V_63 -> V_122 ) ;
F_30 ( V_26 , V_29 ) ;
F_71 ( V_70 , V_29 , V_144 -> V_19 ) ;
}
}
static void F_118 ( struct V_69 * V_70 , struct V_29 * V_29 , T_4 V_19 ,
struct V_24 * V_26 )
{
int V_32 ;
T_4 V_103 ;
if ( ! V_29 -> V_111 ) {
F_30 ( V_26 , V_29 ) ;
F_71 ( V_70 , V_29 , 0 ) ;
return;
}
if ( F_91 ( V_29 ) == V_152 ) {
F_119 ( V_29 ) ;
F_30 ( V_26 , V_29 ) ;
F_59 ( V_29 , 0 ) ;
return;
}
V_32 = F_106 ( V_70 , & V_103 ) ;
switch ( V_32 ) {
case 0 :
if ( V_70 -> V_85 )
F_98 ( V_70 , V_19 , V_103 , V_26 , V_29 ) ;
else
F_99 ( V_70 , V_19 , V_103 , V_26 , V_29 ) ;
break;
case - V_141 :
F_113 ( V_26 ) ;
break;
default:
F_82 ( L_9 , V_150 , V_32 ) ;
F_105 ( V_70 -> V_63 , V_133 ) ;
F_33 ( V_26 ) ;
break;
}
}
static void F_120 ( struct V_69 * V_70 , struct V_29 * V_29 )
{
int V_32 ;
T_4 V_19 = F_61 ( V_70 , V_29 ) ;
struct V_24 * V_26 ;
struct V_15 V_16 ;
struct V_143 V_144 ;
F_47 ( V_70 -> V_58 , V_19 , & V_16 ) ;
if ( F_15 ( V_70 -> V_63 -> V_8 , & V_16 , V_29 , & V_26 ) )
return;
V_32 = F_115 ( V_70 -> V_58 , V_19 , 1 , & V_144 ) ;
switch ( V_32 ) {
case 0 :
F_30 ( V_26 , V_29 ) ;
if ( V_144 . V_145 )
F_117 ( V_70 , V_29 , V_19 , & V_144 ) ;
else
F_71 ( V_70 , V_29 , V_144 . V_19 ) ;
break;
case - V_149 :
if ( F_91 ( V_29 ) == V_152 && V_70 -> V_85 ) {
F_30 ( V_26 , V_29 ) ;
F_70 ( V_70 , V_29 ) ;
} else
F_118 ( V_70 , V_29 , V_19 , V_26 ) ;
break;
default:
F_82 ( L_10 , V_32 ) ;
F_30 ( V_26 , V_29 ) ;
F_35 ( V_29 ) ;
break;
}
}
static void F_121 ( struct V_69 * V_70 , struct V_29 * V_29 )
{
int V_32 ;
int V_153 = F_91 ( V_29 ) ;
T_4 V_19 = F_61 ( V_70 , V_29 ) ;
struct V_143 V_144 ;
V_32 = F_115 ( V_70 -> V_58 , V_19 , 1 , & V_144 ) ;
switch ( V_32 ) {
case 0 :
if ( V_144 . V_145 && ( V_153 == V_113 ) && V_29 -> V_111 )
F_35 ( V_29 ) ;
else
F_71 ( V_70 , V_29 , V_144 . V_19 ) ;
break;
case - V_149 :
if ( V_153 != V_152 ) {
F_35 ( V_29 ) ;
break;
}
if ( V_70 -> V_85 ) {
F_70 ( V_70 , V_29 ) ;
break;
}
F_119 ( V_29 ) ;
F_59 ( V_29 , 0 ) ;
break;
default:
F_82 ( L_10 , V_32 ) ;
F_35 ( V_29 ) ;
break;
}
}
static void F_122 ( struct V_69 * V_70 , struct V_29 * V_29 )
{
F_35 ( V_29 ) ;
}
static int F_123 ( struct V_63 * V_63 )
{
return V_154 < V_63 -> V_155 ||
V_154 > V_63 -> V_155 + V_156 ;
}
static void F_124 ( struct V_63 * V_63 )
{
unsigned long V_33 ;
struct V_29 * V_29 ;
struct V_40 V_35 ;
F_22 ( & V_35 ) ;
F_17 ( & V_63 -> V_10 , V_33 ) ;
F_26 ( & V_35 , & V_63 -> V_76 ) ;
F_22 ( & V_63 -> V_76 ) ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
while ( ( V_29 = F_34 ( & V_35 ) ) ) {
struct V_72 * V_73 = F_58 ( V_29 ) -> V_74 ;
struct V_69 * V_70 = V_73 -> V_70 ;
if ( F_93 ( V_63 ) ) {
F_17 ( & V_63 -> V_10 , V_33 ) ;
F_26 ( & V_63 -> V_76 , & V_35 ) ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
break;
}
if ( V_29 -> V_86 & V_157 )
V_63 -> F_114 ( V_70 , V_29 ) ;
else
V_63 -> F_120 ( V_70 , V_29 ) ;
}
F_22 ( & V_35 ) ;
F_17 ( & V_63 -> V_10 , V_33 ) ;
F_26 ( & V_35 , & V_63 -> V_89 ) ;
F_22 ( & V_63 -> V_89 ) ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
if ( F_29 ( & V_35 ) && ! F_123 ( V_63 ) )
return;
if ( F_103 ( V_63 ) ) {
while ( ( V_29 = F_34 ( & V_35 ) ) )
F_35 ( V_29 ) ;
return;
}
V_63 -> V_155 = V_154 ;
while ( ( V_29 = F_34 ( & V_35 ) ) )
F_68 ( V_29 ) ;
}
static void F_125 ( struct V_158 * V_159 )
{
struct V_63 * V_63 = F_126 ( V_159 , struct V_63 , V_91 ) ;
F_87 ( V_63 , & V_63 -> V_96 , & V_63 -> F_80 ) ;
F_87 ( V_63 , & V_63 -> V_148 , & V_63 -> F_85 ) ;
F_124 ( V_63 ) ;
}
static void F_127 ( struct V_158 * V_159 )
{
struct V_63 * V_63 = F_126 ( F_128 ( V_159 ) , struct V_63 , V_160 ) ;
F_72 ( V_63 ) ;
F_129 ( V_63 -> V_90 , & V_63 -> V_160 , V_156 ) ;
}
static enum V_161 F_104 ( struct V_63 * V_63 )
{
return V_63 -> V_128 . V_162 ;
}
static void F_105 ( struct V_63 * V_63 , enum V_161 V_162 )
{
int V_32 ;
V_63 -> V_128 . V_162 = V_162 ;
switch ( V_162 ) {
case V_163 :
F_82 ( L_11 ) ;
V_63 -> F_120 = F_122 ;
V_63 -> F_114 = F_122 ;
V_63 -> F_80 = F_79 ;
V_63 -> F_85 = F_83 ;
break;
case V_133 :
F_82 ( L_12 ) ;
V_32 = F_130 ( V_63 -> V_130 ) ;
if ( V_32 ) {
F_82 ( L_13 ) ;
F_105 ( V_63 , V_163 ) ;
} else {
F_131 ( V_63 -> V_130 ) ;
V_63 -> F_120 = F_121 ;
V_63 -> F_114 = F_114 ;
V_63 -> F_80 = F_79 ;
V_63 -> F_85 = F_84 ;
}
break;
case V_131 :
V_63 -> F_120 = F_120 ;
V_63 -> F_114 = F_114 ;
V_63 -> F_80 = F_80 ;
V_63 -> F_85 = F_85 ;
break;
}
}
static void F_132 ( struct V_69 * V_70 , struct V_29 * V_29 )
{
unsigned long V_33 ;
struct V_63 * V_63 = V_70 -> V_63 ;
F_17 ( & V_63 -> V_10 , V_33 ) ;
F_18 ( & V_63 -> V_76 , V_29 ) ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
F_72 ( V_63 ) ;
}
static struct V_72 * F_133 ( struct V_69 * V_70 , struct V_29 * V_29 )
{
struct V_63 * V_63 = V_70 -> V_63 ;
struct V_72 * V_73 = F_20 ( V_63 -> V_164 , V_37 ) ;
V_73 -> V_70 = V_70 ;
V_73 -> V_151 = NULL ;
V_73 -> V_165 = V_29 -> V_86 & V_157 ? NULL : F_38 ( & V_63 -> V_147 ) ;
V_73 -> V_102 = NULL ;
return V_73 ;
}
static int F_134 ( struct V_166 * V_138 , struct V_29 * V_29 ,
union V_167 * V_168 )
{
int V_32 ;
struct V_69 * V_70 = V_138 -> V_169 ;
T_4 V_19 = F_61 ( V_70 , V_29 ) ;
struct V_57 * V_58 = V_70 -> V_58 ;
struct V_143 V_134 ;
V_168 -> V_74 = F_133 ( V_70 , V_29 ) ;
if ( F_104 ( V_70 -> V_63 ) == V_163 ) {
F_35 ( V_29 ) ;
return V_170 ;
}
if ( V_29 -> V_86 & ( V_157 | V_87 | V_88 ) ) {
F_132 ( V_70 , V_29 ) ;
return V_170 ;
}
V_32 = F_115 ( V_58 , V_19 , 0 , & V_134 ) ;
switch ( V_32 ) {
case 0 :
if ( F_135 ( V_134 . V_145 ) ) {
F_132 ( V_70 , V_29 ) ;
V_32 = V_170 ;
} else {
F_63 ( V_70 , V_29 , V_134 . V_19 ) ;
V_32 = V_171 ;
}
break;
case - V_149 :
if ( F_104 ( V_70 -> V_63 ) == V_133 ) {
F_35 ( V_29 ) ;
V_32 = V_170 ;
break;
}
case - V_172 :
F_132 ( V_70 , V_29 ) ;
V_32 = V_170 ;
break;
default:
F_35 ( V_29 ) ;
V_32 = V_170 ;
break;
}
return V_32 ;
}
static int F_136 ( struct V_173 * V_174 , int V_175 )
{
int V_32 ;
unsigned long V_33 ;
struct V_176 * V_177 = F_126 ( V_174 , struct V_176 , V_178 ) ;
F_17 ( & V_177 -> V_63 -> V_10 , V_33 ) ;
V_32 = ! F_29 ( & V_177 -> V_63 -> V_77 ) ;
F_19 ( & V_177 -> V_63 -> V_10 , V_33 ) ;
if ( ! V_32 ) {
struct V_179 * V_180 = F_137 ( V_177 -> V_181 -> V_84 ) ;
V_32 = F_138 ( & V_180 -> V_182 , V_175 ) ;
}
return V_32 ;
}
static void F_139 ( struct V_63 * V_63 )
{
F_26 ( & V_63 -> V_76 , & V_63 -> V_77 ) ;
F_22 ( & V_63 -> V_77 ) ;
}
static bool F_140 ( struct V_176 * V_177 )
{
struct V_179 * V_180 = F_137 ( V_177 -> V_181 -> V_84 ) ;
return V_180 && F_141 ( V_180 ) ;
}
static void F_142 ( struct V_176 * V_177 )
{
struct V_63 * V_63 = V_177 -> V_63 ;
struct V_67 * V_183 = V_177 -> V_181 -> V_84 ;
struct V_184 * V_185 = & F_137 ( V_183 ) -> V_186 ;
T_5 V_187 = V_63 -> V_81 << V_112 ;
const char * V_188 = NULL ;
char V_189 [ V_190 ] ;
if ( ! V_177 -> V_191 . V_146 )
return;
if ( ! F_140 ( V_177 ) )
V_188 = L_14 ;
else if ( V_185 -> V_192 < V_63 -> V_81 )
V_188 = L_15 ;
else if ( V_185 -> V_193 > V_187 )
V_188 = L_16 ;
else if ( V_187 & ( V_185 -> V_193 - 1 ) )
V_188 = L_17 ;
if ( V_188 ) {
F_108 ( L_18 , F_143 ( V_183 , V_189 ) , V_188 ) ;
V_177 -> V_191 . V_146 = false ;
}
}
static int F_144 ( struct V_63 * V_63 , struct V_166 * V_138 )
{
struct V_176 * V_177 = V_138 -> V_169 ;
enum V_161 V_194 = V_63 -> V_128 . V_162 ;
enum V_161 V_195 = V_177 -> V_191 . V_162 ;
if ( V_194 > V_195 )
V_195 = V_194 ;
V_63 -> V_138 = V_138 ;
V_63 -> V_136 = V_177 -> V_136 ;
V_63 -> V_128 = V_177 -> V_191 ;
F_105 ( V_63 , V_195 ) ;
return 0 ;
}
static void F_145 ( struct V_63 * V_63 , struct V_166 * V_138 )
{
if ( V_63 -> V_138 == V_138 )
V_63 -> V_138 = NULL ;
}
static void F_146 ( struct V_196 * V_128 )
{
V_128 -> V_162 = V_131 ;
V_128 -> V_129 = true ;
V_128 -> V_197 = true ;
V_128 -> V_146 = true ;
}
static void F_147 ( struct V_63 * V_63 )
{
F_52 ( V_63 ) ;
if ( F_148 ( V_63 -> V_130 ) < 0 )
F_108 ( L_19 , V_150 ) ;
F_9 ( V_63 -> V_8 ) ;
F_149 ( V_63 -> V_127 ) ;
if ( V_63 -> V_90 )
F_150 ( V_63 -> V_90 ) ;
if ( V_63 -> V_115 )
F_21 ( V_63 -> V_115 , V_63 -> V_106 ) ;
F_10 ( V_63 -> V_106 ) ;
F_10 ( V_63 -> V_164 ) ;
F_7 ( V_63 ) ;
}
static struct V_63 * F_151 ( struct V_64 * V_66 ,
struct V_67 * V_198 ,
unsigned long V_187 ,
int V_199 , char * * error )
{
int V_32 ;
void * V_200 ;
struct V_63 * V_63 ;
struct V_201 * V_130 ;
bool V_202 = V_199 ? false : true ;
V_130 = F_152 ( V_198 , V_187 , V_202 ) ;
if ( F_153 ( V_130 ) ) {
* error = L_20 ;
return (struct V_63 * ) V_130 ;
}
V_63 = F_4 ( sizeof( * V_63 ) , V_9 ) ;
if ( ! V_63 ) {
* error = L_21 ;
V_200 = F_154 ( - V_117 ) ;
goto V_203;
}
V_63 -> V_130 = V_130 ;
V_63 -> V_81 = V_187 ;
if ( V_187 & ( V_187 - 1 ) )
V_63 -> V_80 = - 1 ;
else
V_63 -> V_80 = F_155 ( V_187 ) ;
V_63 -> V_136 = 0 ;
F_146 ( & V_63 -> V_128 ) ;
V_63 -> V_8 = F_3 ( V_204 ) ;
if ( ! V_63 -> V_8 ) {
* error = L_22 ;
V_200 = F_154 ( - V_117 ) ;
goto V_205;
}
V_63 -> V_127 = F_156 () ;
if ( F_153 ( V_63 -> V_127 ) ) {
V_32 = F_157 ( V_63 -> V_127 ) ;
* error = L_23 ;
V_200 = F_154 ( V_32 ) ;
goto V_206;
}
V_63 -> V_90 = F_158 ( L_24 V_207 , V_208 ) ;
if ( ! V_63 -> V_90 ) {
* error = L_25 ;
V_200 = F_154 ( - V_117 ) ;
goto V_209;
}
F_159 ( & V_63 -> V_91 , F_125 ) ;
F_160 ( & V_63 -> V_160 , F_127 ) ;
F_5 ( & V_63 -> V_10 ) ;
F_22 ( & V_63 -> V_76 ) ;
F_22 ( & V_63 -> V_89 ) ;
F_37 ( & V_63 -> V_96 ) ;
F_37 ( & V_63 -> V_148 ) ;
V_63 -> V_137 = 0 ;
V_63 -> V_140 = 0 ;
F_22 ( & V_63 -> V_77 ) ;
F_36 ( & V_63 -> V_122 ) ;
F_36 ( & V_63 -> V_147 ) ;
V_63 -> V_115 = NULL ;
V_63 -> V_106 = F_6 ( V_210 ,
V_211 ) ;
if ( ! V_63 -> V_106 ) {
* error = L_26 ;
V_200 = F_154 ( - V_117 ) ;
goto V_212;
}
V_63 -> V_164 = F_6 ( V_213 ,
V_214 ) ;
if ( ! V_63 -> V_164 ) {
* error = L_27 ;
V_200 = F_154 ( - V_117 ) ;
goto V_215;
}
V_63 -> V_216 = 1 ;
V_63 -> V_155 = V_154 ;
V_63 -> V_66 = V_66 ;
V_63 -> V_68 = V_198 ;
F_50 ( V_63 ) ;
return V_63 ;
V_215:
F_10 ( V_63 -> V_106 ) ;
V_212:
F_150 ( V_63 -> V_90 ) ;
V_209:
F_149 ( V_63 -> V_127 ) ;
V_206:
F_9 ( V_63 -> V_8 ) ;
V_205:
F_7 ( V_63 ) ;
V_203:
if ( F_148 ( V_130 ) )
F_108 ( L_19 , V_150 ) ;
return V_200 ;
}
static void F_161 ( struct V_63 * V_63 )
{
F_16 ( ! F_51 ( & V_60 . V_61 ) ) ;
V_63 -> V_216 ++ ;
}
static void F_162 ( struct V_63 * V_63 )
{
F_16 ( ! F_51 ( & V_60 . V_61 ) ) ;
F_16 ( ! V_63 -> V_216 ) ;
if ( ! -- V_63 -> V_216 )
F_147 ( V_63 ) ;
}
static struct V_63 * F_163 ( struct V_64 * V_66 ,
struct V_67 * V_198 ,
unsigned long V_187 , int V_199 ,
char * * error , int * V_217 )
{
struct V_63 * V_63 = F_56 ( V_198 ) ;
if ( V_63 ) {
if ( V_63 -> V_66 != V_66 ) {
* error = L_28 ;
return F_154 ( - V_218 ) ;
}
F_161 ( V_63 ) ;
} else {
V_63 = F_54 ( V_66 ) ;
if ( V_63 ) {
if ( V_63 -> V_68 != V_198 ) {
* error = L_29 ;
return F_154 ( - V_132 ) ;
}
F_161 ( V_63 ) ;
} else {
V_63 = F_151 ( V_66 , V_198 , V_187 , V_199 , error ) ;
* V_217 = 1 ;
}
}
return V_63 ;
}
static void F_164 ( struct V_166 * V_138 )
{
struct V_176 * V_177 = V_138 -> V_169 ;
F_165 ( & V_60 . V_61 ) ;
F_145 ( V_177 -> V_63 , V_138 ) ;
F_162 ( V_177 -> V_63 ) ;
F_166 ( V_138 , V_177 -> V_198 ) ;
F_166 ( V_138 , V_177 -> V_181 ) ;
F_7 ( V_177 ) ;
F_167 ( & V_60 . V_61 ) ;
}
static int F_168 ( struct V_219 * V_220 , struct V_196 * V_128 ,
struct V_166 * V_138 )
{
int V_32 ;
unsigned V_221 ;
const char * V_222 ;
static struct V_223 V_224 [] = {
{ 0 , 3 , L_30 } ,
} ;
if ( ! V_220 -> V_221 )
return 0 ;
V_32 = F_169 ( V_224 , V_220 , & V_221 , & V_138 -> error ) ;
if ( V_32 )
return - V_132 ;
while ( V_221 && ! V_32 ) {
V_222 = F_170 ( V_220 ) ;
V_221 -- ;
if ( ! strcasecmp ( V_222 , L_31 ) )
V_128 -> V_129 = false ;
else if ( ! strcasecmp ( V_222 , L_32 ) )
V_128 -> V_197 = false ;
else if ( ! strcasecmp ( V_222 , L_33 ) )
V_128 -> V_146 = false ;
else if ( ! strcasecmp ( V_222 , L_34 ) )
V_128 -> V_162 = V_133 ;
else {
V_138 -> error = L_35 ;
V_32 = - V_132 ;
break;
}
}
return V_32 ;
}
static int F_171 ( struct V_166 * V_138 , unsigned V_221 , char * * V_225 )
{
int V_32 , V_226 = 0 ;
struct V_176 * V_177 ;
struct V_63 * V_63 ;
struct V_196 V_128 ;
struct V_219 V_220 ;
struct V_118 * V_181 ;
unsigned long V_187 ;
T_4 V_136 ;
struct V_118 * V_198 ;
T_5 V_227 ;
char V_59 [ V_190 ] ;
F_165 ( & V_60 . V_61 ) ;
if ( V_221 < 4 ) {
V_138 -> error = L_36 ;
V_32 = - V_132 ;
goto V_228;
}
V_220 . V_221 = V_221 ;
V_220 . V_225 = V_225 ;
V_32 = F_172 ( V_138 , V_225 [ 0 ] , V_229 | V_230 , & V_198 ) ;
if ( V_32 ) {
V_138 -> error = L_37 ;
goto V_228;
}
V_227 = F_173 ( V_198 -> V_84 -> V_231 ) >> V_112 ;
if ( V_227 > V_232 )
F_108 ( L_38 ,
F_143 ( V_198 -> V_84 , V_59 ) , V_233 ) ;
V_32 = F_172 ( V_138 , V_225 [ 1 ] , V_229 | V_230 , & V_181 ) ;
if ( V_32 ) {
V_138 -> error = L_39 ;
goto V_234;
}
if ( F_174 ( V_225 [ 2 ] , 10 , & V_187 ) || ! V_187 ||
V_187 < V_235 ||
V_187 > V_236 ||
V_187 & ( V_235 - 1 ) ) {
V_138 -> error = L_40 ;
V_32 = - V_132 ;
goto V_36;
}
if ( F_175 ( V_225 [ 3 ] , 10 , ( unsigned long long * ) & V_136 ) ) {
V_138 -> error = L_41 ;
V_32 = - V_132 ;
goto V_36;
}
F_146 ( & V_128 ) ;
F_176 ( & V_220 , 4 ) ;
V_32 = F_168 ( & V_220 , & V_128 , V_138 ) ;
if ( V_32 )
goto V_36;
V_177 = F_177 ( sizeof( * V_177 ) , V_9 ) ;
if ( ! V_177 ) {
V_32 = - V_117 ;
goto V_36;
}
V_63 = F_163 ( F_178 ( V_138 -> V_139 ) , V_198 -> V_84 ,
V_187 , V_128 . V_162 == V_133 , & V_138 -> error , & V_226 ) ;
if ( F_153 ( V_63 ) ) {
V_32 = F_157 ( V_63 ) ;
goto V_237;
}
if ( ! V_226 && V_128 . V_197 != V_63 -> V_128 . V_197 ) {
V_138 -> error = L_42 ;
V_32 = - V_132 ;
goto V_238;
}
if ( V_128 . V_197 && ! F_179 ( V_187 ) ) {
V_138 -> error = L_43 ;
V_32 = - V_132 ;
goto V_238;
}
V_177 -> V_63 = V_63 ;
V_177 -> V_138 = V_138 ;
V_177 -> V_198 = V_198 ;
V_177 -> V_181 = V_181 ;
V_177 -> V_136 = V_136 ;
V_177 -> V_191 = V_177 -> V_239 = V_128 ;
V_138 -> V_240 = 1 ;
if ( V_128 . V_197 && V_128 . V_146 ) {
V_138 -> V_241 = 1 ;
V_138 -> V_242 = true ;
V_138 -> V_243 = true ;
}
V_138 -> V_169 = V_177 ;
V_177 -> V_178 . V_244 = F_136 ;
F_180 ( V_138 -> V_139 , & V_177 -> V_178 ) ;
F_167 ( & V_60 . V_61 ) ;
return 0 ;
V_238:
F_162 ( V_63 ) ;
V_237:
F_7 ( V_177 ) ;
V_36:
F_166 ( V_138 , V_181 ) ;
V_234:
F_166 ( V_138 , V_198 ) ;
V_228:
F_167 ( & V_60 . V_61 ) ;
return V_32 ;
}
static int F_181 ( struct V_166 * V_138 , struct V_29 * V_29 ,
union V_167 * V_168 )
{
int V_32 ;
struct V_176 * V_177 = V_138 -> V_169 ;
struct V_63 * V_63 = V_177 -> V_63 ;
unsigned long V_33 ;
F_17 ( & V_63 -> V_10 , V_33 ) ;
V_29 -> V_82 = V_177 -> V_181 -> V_84 ;
V_32 = V_171 ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
return V_32 ;
}
static int F_182 ( struct V_166 * V_138 )
{
int V_32 ;
struct V_176 * V_177 = V_138 -> V_169 ;
struct V_63 * V_63 = V_177 -> V_63 ;
T_5 V_245 = V_138 -> V_6 ;
T_4 V_246 ;
V_32 = F_144 ( V_63 , V_138 ) ;
if ( V_32 )
return V_32 ;
( void ) F_62 ( V_245 , V_63 -> V_81 ) ;
V_32 = F_183 ( V_63 -> V_130 , & V_246 ) ;
if ( V_32 ) {
F_82 ( L_44 ) ;
return V_32 ;
}
if ( V_245 < V_246 ) {
F_82 ( L_45 ,
( unsigned long long ) V_245 , V_246 ) ;
return - V_132 ;
} else if ( V_245 > V_246 ) {
V_32 = F_184 ( V_63 -> V_130 , V_245 ) ;
if ( V_32 ) {
F_82 ( L_46 ) ;
F_105 ( V_63 , V_133 ) ;
return V_32 ;
}
( void ) F_103 ( V_63 ) ;
}
return 0 ;
}
static void F_185 ( struct V_166 * V_138 )
{
struct V_176 * V_177 = V_138 -> V_169 ;
struct V_63 * V_63 = V_177 -> V_63 ;
unsigned long V_33 ;
F_17 ( & V_63 -> V_10 , V_33 ) ;
V_63 -> V_137 = 0 ;
V_63 -> V_140 = 0 ;
F_139 ( V_63 ) ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
F_127 ( & V_63 -> V_160 . V_55 ) ;
}
static void F_186 ( struct V_166 * V_138 )
{
struct V_176 * V_177 = V_138 -> V_169 ;
struct V_63 * V_63 = V_177 -> V_63 ;
F_187 ( & V_63 -> V_160 ) ;
F_188 ( V_63 -> V_90 ) ;
( void ) F_103 ( V_63 ) ;
}
static int F_189 ( unsigned V_221 , unsigned V_247 )
{
if ( V_221 != V_247 ) {
F_108 ( L_47 ,
V_221 , V_247 ) ;
return - V_132 ;
}
return 0 ;
}
static int F_190 ( char * V_248 , T_8 * V_249 , int V_250 )
{
if ( ! F_175 ( V_248 , 10 , ( unsigned long long * ) V_249 ) &&
* V_249 <= V_251 )
return 0 ;
if ( V_250 )
F_108 ( L_48 , V_248 ) ;
return - V_132 ;
}
static int F_191 ( unsigned V_221 , char * * V_225 , struct V_63 * V_63 )
{
T_8 V_249 ;
int V_32 ;
V_32 = F_189 ( V_221 , 2 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_190 ( V_225 [ 1 ] , & V_249 , 1 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_192 ( V_63 -> V_130 , V_249 ) ;
if ( V_32 ) {
F_108 ( L_49 ,
V_225 [ 1 ] ) ;
return V_32 ;
}
return 0 ;
}
static int F_193 ( unsigned V_221 , char * * V_225 , struct V_63 * V_63 )
{
T_8 V_249 ;
T_8 V_252 ;
int V_32 ;
V_32 = F_189 ( V_221 , 3 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_190 ( V_225 [ 1 ] , & V_249 , 1 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_190 ( V_225 [ 2 ] , & V_252 , 1 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_194 ( V_63 -> V_130 , V_249 , V_252 ) ;
if ( V_32 ) {
F_108 ( L_50 ,
V_225 [ 1 ] , V_225 [ 2 ] ) ;
return V_32 ;
}
return 0 ;
}
static int F_195 ( unsigned V_221 , char * * V_225 , struct V_63 * V_63 )
{
T_8 V_249 ;
int V_32 ;
V_32 = F_189 ( V_221 , 2 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_190 ( V_225 [ 1 ] , & V_249 , 1 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_196 ( V_63 -> V_130 , V_249 ) ;
if ( V_32 )
F_108 ( L_51 , V_225 [ 1 ] ) ;
return V_32 ;
}
static int F_197 ( unsigned V_221 , char * * V_225 , struct V_63 * V_63 )
{
T_8 V_253 , V_254 ;
int V_32 ;
V_32 = F_189 ( V_221 , 3 ) ;
if ( V_32 )
return V_32 ;
if ( F_175 ( V_225 [ 1 ] , 10 , ( unsigned long long * ) & V_253 ) ) {
F_108 ( L_52 , V_225 [ 1 ] ) ;
return - V_132 ;
}
if ( F_175 ( V_225 [ 2 ] , 10 , ( unsigned long long * ) & V_254 ) ) {
F_108 ( L_53 , V_225 [ 2 ] ) ;
return - V_132 ;
}
V_32 = F_198 ( V_63 -> V_130 , V_253 , V_254 ) ;
if ( V_32 ) {
F_108 ( L_54 ,
V_225 [ 1 ] , V_225 [ 2 ] ) ;
return V_32 ;
}
return 0 ;
}
static int F_199 ( unsigned V_221 , char * * V_225 , struct V_63 * V_63 )
{
int V_32 ;
V_32 = F_189 ( V_221 , 1 ) ;
if ( V_32 )
return V_32 ;
( void ) F_103 ( V_63 ) ;
V_32 = F_200 ( V_63 -> V_130 ) ;
if ( V_32 )
F_108 ( L_55 ) ;
return V_32 ;
}
static int F_201 ( unsigned V_221 , char * * V_225 , struct V_63 * V_63 )
{
int V_32 ;
V_32 = F_189 ( V_221 , 1 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_202 ( V_63 -> V_130 ) ;
if ( V_32 )
F_108 ( L_56 ) ;
return V_32 ;
}
static int F_203 ( struct V_166 * V_138 , unsigned V_221 , char * * V_225 )
{
int V_32 = - V_132 ;
struct V_176 * V_177 = V_138 -> V_169 ;
struct V_63 * V_63 = V_177 -> V_63 ;
if ( ! strcasecmp ( V_225 [ 0 ] , L_57 ) )
V_32 = F_191 ( V_221 , V_225 , V_63 ) ;
else if ( ! strcasecmp ( V_225 [ 0 ] , L_58 ) )
V_32 = F_193 ( V_221 , V_225 , V_63 ) ;
else if ( ! strcasecmp ( V_225 [ 0 ] , L_59 ) )
V_32 = F_195 ( V_221 , V_225 , V_63 ) ;
else if ( ! strcasecmp ( V_225 [ 0 ] , L_60 ) )
V_32 = F_197 ( V_221 , V_225 , V_63 ) ;
else if ( ! strcasecmp ( V_225 [ 0 ] , L_61 ) )
V_32 = F_199 ( V_221 , V_225 , V_63 ) ;
else if ( ! strcasecmp ( V_225 [ 0 ] , L_62 ) )
V_32 = F_201 ( V_221 , V_225 , V_63 ) ;
else
F_108 ( L_63 , V_225 [ 0 ] ) ;
if ( ! V_32 )
( void ) F_103 ( V_63 ) ;
return V_32 ;
}
static void F_204 ( struct V_196 * V_128 , char * V_134 ,
unsigned V_255 , unsigned V_256 )
{
unsigned V_48 = ! V_128 -> V_129 + ! V_128 -> V_197 +
! V_128 -> V_146 + ( V_128 -> V_162 == V_133 ) ;
F_205 ( L_64 , V_48 ) ;
if ( ! V_128 -> V_129 )
F_205 ( L_65 ) ;
if ( ! V_128 -> V_197 )
F_205 ( L_66 ) ;
if ( ! V_128 -> V_146 )
F_205 ( L_67 ) ;
if ( V_128 -> V_162 == V_133 )
F_205 ( L_68 ) ;
}
static int F_206 ( struct V_166 * V_138 , T_9 type ,
unsigned V_257 , char * V_134 , unsigned V_256 )
{
int V_32 ;
unsigned V_255 = 0 ;
T_3 V_258 ;
T_4 V_259 ;
T_4 V_260 ;
T_4 V_261 ;
T_4 V_262 ;
T_4 V_263 ;
char V_189 [ V_190 ] ;
char V_264 [ V_190 ] ;
struct V_176 * V_177 = V_138 -> V_169 ;
struct V_63 * V_63 = V_177 -> V_63 ;
switch ( type ) {
case V_265 :
if ( F_104 ( V_63 ) == V_163 ) {
F_205 ( L_69 ) ;
break;
}
if ( ! ( V_257 & V_266 ) && ! F_207 ( V_138 ) )
( void ) F_103 ( V_63 ) ;
V_32 = F_208 ( V_63 -> V_130 ,
& V_258 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_209 ( V_63 -> V_130 ,
& V_260 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_210 ( V_63 -> V_130 , & V_262 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_107 ( V_63 -> V_130 ,
& V_259 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_183 ( V_63 -> V_130 , & V_261 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_211 ( V_63 -> V_130 , & V_263 ) ;
if ( V_32 )
return V_32 ;
F_205 ( L_70 ,
( unsigned long long ) V_258 ,
( unsigned long long ) ( V_262 - V_260 ) ,
( unsigned long long ) V_262 ,
( unsigned long long ) ( V_261 - V_259 ) ,
( unsigned long long ) V_261 ) ;
if ( V_263 )
F_205 ( L_71 , V_263 ) ;
else
F_205 ( L_72 ) ;
if ( V_63 -> V_128 . V_162 == V_133 )
F_205 ( L_73 ) ;
else
F_205 ( L_74 ) ;
if ( V_63 -> V_128 . V_197 && V_63 -> V_128 . V_146 )
F_205 ( L_75 ) ;
else
F_205 ( L_33 ) ;
break;
case V_267 :
F_205 ( L_76 ,
F_212 ( V_189 , V_177 -> V_198 -> V_84 -> V_268 ) ,
F_212 ( V_264 , V_177 -> V_181 -> V_84 -> V_268 ) ,
( unsigned long ) V_63 -> V_81 ,
( unsigned long long ) V_177 -> V_136 ) ;
F_204 ( & V_177 -> V_239 , V_134 , V_255 , V_256 ) ;
break;
}
return 0 ;
}
static int F_213 ( struct V_166 * V_138 ,
T_10 V_109 , void * V_269 )
{
struct V_176 * V_177 = V_138 -> V_169 ;
return V_109 ( V_138 , V_177 -> V_181 , 0 , V_138 -> V_6 , V_269 ) ;
}
static int F_214 ( struct V_166 * V_138 , struct V_270 * V_271 ,
struct V_272 * V_273 , int V_274 )
{
struct V_176 * V_177 = V_138 -> V_169 ;
struct V_179 * V_180 = F_137 ( V_177 -> V_181 -> V_84 ) ;
if ( ! V_180 -> V_275 )
return V_274 ;
V_271 -> V_82 = V_177 -> V_181 -> V_84 ;
return F_2 ( V_274 , V_180 -> V_275 ( V_180 , V_271 , V_273 ) ) ;
}
static void F_215 ( struct V_176 * V_177 , struct V_184 * V_186 )
{
struct V_63 * V_63 = V_177 -> V_63 ;
struct V_184 * V_185 ;
V_186 -> V_192 = V_63 -> V_81 ;
if ( V_177 -> V_191 . V_146 ) {
V_185 = & F_137 ( V_177 -> V_181 -> V_84 ) -> V_186 ;
V_186 -> V_193 = V_185 -> V_193 ;
} else
V_186 -> V_193 = V_63 -> V_81 << V_112 ;
}
static void F_216 ( struct V_166 * V_138 , struct V_184 * V_186 )
{
struct V_176 * V_177 = V_138 -> V_169 ;
struct V_63 * V_63 = V_177 -> V_63 ;
F_217 ( V_186 , 0 ) ;
F_218 ( V_186 , V_63 -> V_81 << V_112 ) ;
if ( ! V_177 -> V_191 . V_197 )
return;
F_142 ( V_177 ) ;
F_215 ( V_177 , V_186 ) ;
}
static void F_219 ( struct V_166 * V_138 )
{
struct V_69 * V_70 = V_138 -> V_169 ;
F_165 ( & V_60 . V_61 ) ;
F_162 ( V_70 -> V_63 ) ;
F_220 ( V_70 -> V_58 ) ;
F_166 ( V_138 , V_70 -> V_83 ) ;
if ( V_70 -> V_85 )
F_166 ( V_138 , V_70 -> V_85 ) ;
F_7 ( V_70 ) ;
F_167 ( & V_60 . V_61 ) ;
}
static int F_221 ( struct V_166 * V_138 , unsigned V_221 , char * * V_225 )
{
int V_32 ;
struct V_69 * V_70 ;
struct V_118 * V_83 , * V_85 ;
struct V_64 * V_66 ;
F_165 ( & V_60 . V_61 ) ;
if ( V_221 != 2 && V_221 != 3 ) {
V_138 -> error = L_36 ;
V_32 = - V_132 ;
goto V_228;
}
V_70 = V_138 -> V_169 = F_177 ( sizeof( * V_70 ) , V_9 ) ;
if ( ! V_70 ) {
V_138 -> error = L_77 ;
V_32 = - V_117 ;
goto V_228;
}
if ( V_221 == 3 ) {
V_32 = F_172 ( V_138 , V_225 [ 2 ] , V_229 , & V_85 ) ;
if ( V_32 ) {
V_138 -> error = L_78 ;
goto V_276;
}
V_70 -> V_85 = V_85 ;
}
V_32 = F_172 ( V_138 , V_225 [ 0 ] , F_222 ( V_138 -> V_139 ) , & V_83 ) ;
if ( V_32 ) {
V_138 -> error = L_79 ;
goto V_277;
}
V_70 -> V_83 = V_83 ;
if ( F_190 ( V_225 [ 1 ] , ( unsigned long long * ) & V_70 -> V_249 , 0 ) ) {
V_138 -> error = L_80 ;
V_32 = - V_132 ;
goto V_278;
}
V_66 = F_223 ( V_70 -> V_83 -> V_84 -> V_268 ) ;
if ( ! V_66 ) {
V_138 -> error = L_81 ;
V_32 = - V_132 ;
goto V_278;
}
V_70 -> V_63 = F_54 ( V_66 ) ;
if ( ! V_70 -> V_63 ) {
V_138 -> error = L_82 ;
V_32 = - V_132 ;
goto V_279;
}
F_161 ( V_70 -> V_63 ) ;
if ( F_104 ( V_70 -> V_63 ) == V_163 ) {
V_138 -> error = L_83 ;
goto V_280;
}
V_32 = F_224 ( V_70 -> V_63 -> V_130 , V_70 -> V_249 , & V_70 -> V_58 ) ;
if ( V_32 ) {
V_138 -> error = L_84 ;
goto V_280;
}
V_32 = F_225 ( V_138 , V_70 -> V_63 -> V_81 ) ;
if ( V_32 )
goto V_280;
V_138 -> V_240 = 1 ;
V_138 -> V_281 = true ;
if ( V_70 -> V_63 -> V_128 . V_197 ) {
V_138 -> V_242 = true ;
V_138 -> V_241 = 1 ;
V_138 -> V_243 = true ;
V_138 -> V_282 = true ;
}
F_226 ( V_66 ) ;
F_167 ( & V_60 . V_61 ) ;
return 0 ;
V_280:
F_162 ( V_70 -> V_63 ) ;
V_279:
F_226 ( V_66 ) ;
V_278:
F_166 ( V_138 , V_70 -> V_83 ) ;
V_277:
if ( V_70 -> V_85 )
F_166 ( V_138 , V_70 -> V_85 ) ;
V_276:
F_7 ( V_70 ) ;
V_228:
F_167 ( & V_60 . V_61 ) ;
return V_32 ;
}
static int F_227 ( struct V_166 * V_138 , struct V_29 * V_29 ,
union V_167 * V_168 )
{
V_29 -> V_79 = F_228 ( V_138 , V_29 -> V_79 ) ;
return F_134 ( V_138 , V_29 , V_168 ) ;
}
static int F_229 ( struct V_166 * V_138 ,
struct V_29 * V_29 , int V_100 ,
union V_167 * V_168 )
{
unsigned long V_33 ;
struct V_72 * V_73 = V_168 -> V_74 ;
struct V_53 V_55 ;
struct V_92 * V_93 , * V_28 ;
struct V_63 * V_63 = V_73 -> V_70 -> V_63 ;
if ( V_73 -> V_151 ) {
F_37 ( & V_55 ) ;
F_42 ( V_73 -> V_151 , & V_55 ) ;
F_17 ( & V_63 -> V_10 , V_33 ) ;
F_88 (m, tmp, &work, list) {
F_53 ( & V_93 -> V_39 ) ;
V_93 -> V_94 = 1 ;
F_74 ( V_93 ) ;
}
F_19 ( & V_63 -> V_10 , V_33 ) ;
}
if ( V_73 -> V_165 ) {
F_37 ( & V_55 ) ;
F_42 ( V_73 -> V_165 , & V_55 ) ;
F_17 ( & V_63 -> V_10 , V_33 ) ;
F_88 (m, tmp, &work, list)
F_44 ( & V_93 -> V_39 , & V_63 -> V_148 ) ;
F_19 ( & V_63 -> V_10 , V_33 ) ;
}
F_21 ( V_73 , V_63 -> V_164 ) ;
return 0 ;
}
static void F_230 ( struct V_166 * V_138 )
{
if ( F_231 ( V_138 ) )
F_60 ( (struct V_69 * ) V_138 -> V_169 ) ;
}
static int F_232 ( struct V_166 * V_138 , T_9 type ,
unsigned V_257 , char * V_134 , unsigned V_256 )
{
int V_32 ;
T_11 V_255 = 0 ;
T_4 V_283 , V_284 ;
char V_189 [ V_190 ] ;
struct V_69 * V_70 = V_138 -> V_169 ;
if ( F_104 ( V_70 -> V_63 ) == V_163 ) {
F_205 ( L_69 ) ;
return 0 ;
}
if ( ! V_70 -> V_58 )
F_205 ( L_85 ) ;
else {
switch ( type ) {
case V_265 :
V_32 = F_233 ( V_70 -> V_58 , & V_283 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_234 ( V_70 -> V_58 , & V_284 ) ;
if ( V_32 < 0 )
return V_32 ;
F_205 ( L_71 , V_283 * V_70 -> V_63 -> V_81 ) ;
if ( V_32 )
F_205 ( L_86 , ( ( V_284 + 1 ) *
V_70 -> V_63 -> V_81 ) - 1 ) ;
else
F_205 ( L_85 ) ;
break;
case V_267 :
F_205 ( L_87 ,
F_212 ( V_189 , V_70 -> V_83 -> V_84 -> V_268 ) ,
( unsigned long ) V_70 -> V_249 ) ;
if ( V_70 -> V_85 )
F_205 ( L_88 , F_212 ( V_189 , V_70 -> V_85 -> V_84 -> V_268 ) ) ;
break;
}
}
return 0 ;
}
static int F_235 ( struct V_166 * V_138 ,
T_10 V_109 , void * V_269 )
{
T_5 V_285 ;
struct V_69 * V_70 = V_138 -> V_169 ;
struct V_63 * V_63 = V_70 -> V_63 ;
if ( ! V_63 -> V_138 )
return 0 ;
V_285 = V_63 -> V_138 -> V_6 ;
( void ) F_62 ( V_285 , V_63 -> V_81 ) ;
if ( V_285 )
return V_109 ( V_138 , V_70 -> V_83 , 0 , V_63 -> V_81 * V_285 , V_269 ) ;
return 0 ;
}
static void F_236 ( struct V_166 * V_138 , struct V_184 * V_186 )
{
struct V_69 * V_70 = V_138 -> V_169 ;
* V_186 = F_137 ( V_70 -> V_83 -> V_84 ) -> V_186 ;
}
static int T_12 F_237 ( void )
{
int V_32 ;
F_48 () ;
V_32 = F_238 ( & V_286 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_238 ( & V_287 ) ;
if ( V_32 )
goto V_288;
V_32 = - V_117 ;
V_12 = F_239 ( V_24 , 0 ) ;
if ( ! V_12 )
goto V_289;
V_211 = F_239 ( V_92 , 0 ) ;
if ( ! V_211 )
goto V_290;
V_214 = F_239 ( V_72 , 0 ) ;
if ( ! V_214 )
goto V_291;
return 0 ;
V_291:
F_240 ( V_211 ) ;
V_290:
F_240 ( V_12 ) ;
V_289:
F_241 ( & V_287 ) ;
V_288:
F_241 ( & V_286 ) ;
return V_32 ;
}
static void F_242 ( void )
{
F_241 ( & V_286 ) ;
F_241 ( & V_287 ) ;
F_240 ( V_12 ) ;
F_240 ( V_211 ) ;
F_240 ( V_214 ) ;
}
