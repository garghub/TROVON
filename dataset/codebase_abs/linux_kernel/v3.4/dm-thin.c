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
int V_30 = 1 ;
unsigned long V_31 ;
T_1 V_18 = F_11 ( V_8 , V_16 ) ;
struct V_12 * V_12 , * V_32 ;
F_16 ( V_18 > V_8 -> V_5 ) ;
F_17 ( & V_8 -> V_10 , V_31 ) ;
V_12 = F_13 ( V_8 -> V_14 + V_18 , V_16 ) ;
if ( V_12 ) {
F_18 ( & V_12 -> V_33 , V_28 ) ;
goto V_34;
}
F_19 ( & V_8 -> V_10 , V_31 ) ;
V_32 = F_20 ( V_8 -> V_11 , V_35 ) ;
F_17 ( & V_8 -> V_10 , V_31 ) ;
V_12 = F_13 ( V_8 -> V_14 + V_18 , V_16 ) ;
if ( V_12 ) {
F_21 ( V_32 , V_8 -> V_11 ) ;
F_18 ( & V_12 -> V_33 , V_28 ) ;
goto V_34;
}
V_12 = V_32 ;
V_12 -> V_8 = V_8 ;
memcpy ( & V_12 -> V_16 , V_16 , sizeof( V_12 -> V_16 ) ) ;
V_12 -> V_36 = V_28 ;
F_22 ( & V_12 -> V_33 ) ;
F_23 ( & V_12 -> V_37 , V_8 -> V_14 + V_18 ) ;
V_30 = 0 ;
V_34:
F_19 ( & V_8 -> V_10 , V_31 ) ;
* V_29 = V_12 ;
return V_30 ;
}
static void F_24 ( struct V_12 * V_12 , struct V_38 * V_39 )
{
struct V_3 * V_8 = V_12 -> V_8 ;
F_25 ( & V_12 -> V_37 ) ;
if ( V_39 ) {
F_18 ( V_39 , V_12 -> V_36 ) ;
F_26 ( V_39 , & V_12 -> V_33 ) ;
}
F_21 ( V_12 , V_8 -> V_11 ) ;
}
static void F_27 ( struct V_12 * V_12 , struct V_38 * V_33 )
{
unsigned long V_31 ;
struct V_3 * V_8 = V_12 -> V_8 ;
F_17 ( & V_8 -> V_10 , V_31 ) ;
F_24 ( V_12 , V_33 ) ;
F_19 ( & V_8 -> V_10 , V_31 ) ;
}
static void F_28 ( struct V_12 * V_12 , struct V_27 * V_27 )
{
F_16 ( V_12 -> V_36 != V_27 ) ;
F_16 ( ! F_29 ( & V_12 -> V_33 ) ) ;
F_24 ( V_12 , NULL ) ;
}
static void F_30 ( struct V_12 * V_12 , struct V_27 * V_27 )
{
unsigned long V_31 ;
struct V_3 * V_8 = V_12 -> V_8 ;
F_17 ( & V_8 -> V_10 , V_31 ) ;
F_28 ( V_12 , V_27 ) ;
F_19 ( & V_8 -> V_10 , V_31 ) ;
}
static void F_31 ( struct V_12 * V_12 , struct V_38 * V_39 )
{
struct V_3 * V_8 = V_12 -> V_8 ;
F_25 ( & V_12 -> V_37 ) ;
F_26 ( V_39 , & V_12 -> V_33 ) ;
F_21 ( V_12 , V_8 -> V_11 ) ;
}
static void F_32 ( struct V_12 * V_12 , struct V_38 * V_39 )
{
unsigned long V_31 ;
struct V_3 * V_8 = V_12 -> V_8 ;
F_17 ( & V_8 -> V_10 , V_31 ) ;
F_31 ( V_12 , V_39 ) ;
F_19 ( & V_8 -> V_10 , V_31 ) ;
}
static void F_33 ( struct V_12 * V_12 )
{
struct V_3 * V_8 = V_12 -> V_8 ;
struct V_38 V_33 ;
struct V_27 * V_27 ;
unsigned long V_31 ;
F_22 ( & V_33 ) ;
F_17 ( & V_8 -> V_10 , V_31 ) ;
F_24 ( V_12 , & V_33 ) ;
F_19 ( & V_8 -> V_10 , V_31 ) ;
while ( ( V_27 = F_34 ( & V_33 ) ) )
F_35 ( V_27 ) ;
}
static void F_36 ( struct V_40 * V_41 )
{
int V_4 ;
F_5 ( & V_41 -> V_10 ) ;
V_41 -> V_42 = 0 ;
V_41 -> V_43 = 0 ;
for ( V_4 = 0 ; V_4 < V_44 ; V_4 ++ ) {
V_41 -> V_45 [ V_4 ] . V_41 = V_41 ;
V_41 -> V_45 [ V_4 ] . V_46 = 0 ;
F_37 ( & V_41 -> V_45 [ V_4 ] . V_47 ) ;
}
}
static struct V_48 * F_38 ( struct V_40 * V_41 )
{
unsigned long V_31 ;
struct V_48 * V_49 ;
F_17 ( & V_41 -> V_10 , V_31 ) ;
V_49 = V_41 -> V_45 + V_41 -> V_42 ;
V_49 -> V_46 ++ ;
F_19 ( & V_41 -> V_10 , V_31 ) ;
return V_49 ;
}
static unsigned F_39 ( unsigned V_50 )
{
return ( V_50 + 1 ) % V_44 ;
}
static void F_40 ( struct V_40 * V_41 , struct V_51 * V_52 )
{
while ( ( V_41 -> V_43 != V_41 -> V_42 ) &&
! V_41 -> V_45 [ V_41 -> V_43 ] . V_46 ) {
F_41 ( & V_41 -> V_45 [ V_41 -> V_43 ] . V_47 , V_52 ) ;
V_41 -> V_43 = F_39 ( V_41 -> V_43 ) ;
}
if ( ( V_41 -> V_43 == V_41 -> V_42 ) && ! V_41 -> V_45 [ V_41 -> V_43 ] . V_46 )
F_41 ( & V_41 -> V_45 [ V_41 -> V_43 ] . V_47 , V_52 ) ;
}
static void F_42 ( struct V_48 * V_49 , struct V_51 * V_52 )
{
unsigned long V_31 ;
F_17 ( & V_49 -> V_41 -> V_10 , V_31 ) ;
F_16 ( ! V_49 -> V_46 ) ;
-- V_49 -> V_46 ;
F_40 ( V_49 -> V_41 , V_52 ) ;
F_19 ( & V_49 -> V_41 -> V_10 , V_31 ) ;
}
static int F_43 ( struct V_40 * V_41 , struct V_51 * V_53 )
{
int V_30 = 1 ;
unsigned long V_31 ;
unsigned V_54 ;
F_17 ( & V_41 -> V_10 , V_31 ) ;
if ( ( V_41 -> V_43 == V_41 -> V_42 ) &&
! V_41 -> V_45 [ V_41 -> V_42 ] . V_46 )
V_30 = 0 ;
else {
F_44 ( V_53 , & V_41 -> V_45 [ V_41 -> V_42 ] . V_47 ) ;
V_54 = F_39 ( V_41 -> V_42 ) ;
if ( ! V_41 -> V_45 [ V_54 ] . V_46 )
V_41 -> V_42 = V_54 ;
}
F_19 ( & V_41 -> V_10 , V_31 ) ;
return V_30 ;
}
static void F_45 ( struct V_55 * V_56 ,
T_4 V_57 , struct V_15 * V_16 )
{
V_16 -> V_22 = 0 ;
V_16 -> V_23 = F_46 ( V_56 ) ;
V_16 -> V_19 = V_57 ;
}
static void F_47 ( struct V_55 * V_56 , T_4 V_57 ,
struct V_15 * V_16 )
{
V_16 -> V_22 = 1 ;
V_16 -> V_23 = F_46 ( V_56 ) ;
V_16 -> V_19 = V_57 ;
}
static void F_48 ( void )
{
F_49 ( & V_58 . V_59 ) ;
F_37 ( & V_58 . V_60 ) ;
}
static void F_50 ( struct V_61 * V_61 )
{
F_16 ( ! F_51 ( & V_58 . V_59 ) ) ;
F_44 ( & V_61 -> V_37 , & V_58 . V_60 ) ;
}
static void F_52 ( struct V_61 * V_61 )
{
F_16 ( ! F_51 ( & V_58 . V_59 ) ) ;
F_53 ( & V_61 -> V_37 ) ;
}
static struct V_61 * F_54 ( struct V_62 * V_63 )
{
struct V_61 * V_61 = NULL , * V_26 ;
F_16 ( ! F_51 ( & V_58 . V_59 ) ) ;
F_55 (tmp, &dm_thin_pool_table.pools, list) {
if ( V_26 -> V_64 == V_63 ) {
V_61 = V_26 ;
break;
}
}
return V_61 ;
}
static struct V_61 * F_56 ( struct V_65 * V_66 )
{
struct V_61 * V_61 = NULL , * V_26 ;
F_16 ( ! F_51 ( & V_58 . V_59 ) ) ;
F_55 (tmp, &dm_thin_pool_table.pools, list) {
if ( V_26 -> V_66 == V_66 ) {
V_61 = V_26 ;
break;
}
}
return V_61 ;
}
static void F_57 ( struct V_67 * V_68 , struct V_38 * V_69 )
{
struct V_27 * V_27 ;
struct V_38 V_33 ;
F_22 ( & V_33 ) ;
F_26 ( & V_33 , V_69 ) ;
F_22 ( V_69 ) ;
while ( ( V_27 = F_34 ( & V_33 ) ) ) {
struct V_70 * V_71 = F_58 ( V_27 ) -> V_72 ;
if ( V_71 -> V_68 == V_68 )
F_59 ( V_27 , V_73 ) ;
else
F_18 ( V_69 , V_27 ) ;
}
}
static void F_60 ( struct V_67 * V_68 )
{
struct V_61 * V_61 = V_68 -> V_61 ;
unsigned long V_31 ;
F_17 ( & V_61 -> V_10 , V_31 ) ;
F_57 ( V_68 , & V_61 -> V_74 ) ;
F_57 ( V_68 , & V_61 -> V_75 ) ;
F_19 ( & V_61 -> V_10 , V_31 ) ;
}
static T_4 F_61 ( struct V_67 * V_68 , struct V_27 * V_27 )
{
return V_27 -> V_76 >> V_68 -> V_61 -> V_77 ;
}
static void F_62 ( struct V_67 * V_68 , struct V_27 * V_27 , T_4 V_19 )
{
struct V_61 * V_61 = V_68 -> V_61 ;
V_27 -> V_78 = V_68 -> V_79 -> V_80 ;
V_27 -> V_76 = ( V_19 << V_61 -> V_77 ) +
( V_27 -> V_76 & V_61 -> V_81 ) ;
}
static void F_63 ( struct V_67 * V_68 , struct V_27 * V_27 )
{
V_27 -> V_78 = V_68 -> V_82 -> V_80 ;
}
static void F_64 ( struct V_67 * V_68 , struct V_27 * V_27 )
{
struct V_61 * V_61 = V_68 -> V_61 ;
unsigned long V_31 ;
if ( V_27 -> V_83 & ( V_84 | V_85 ) ) {
F_17 ( & V_61 -> V_10 , V_31 ) ;
F_18 ( & V_61 -> V_86 , V_27 ) ;
F_19 ( & V_61 -> V_10 , V_31 ) ;
} else
F_65 ( V_27 ) ;
}
static void F_66 ( struct V_67 * V_68 , struct V_27 * V_27 )
{
F_63 ( V_68 , V_27 ) ;
F_64 ( V_68 , V_27 ) ;
}
static void F_67 ( struct V_67 * V_68 , struct V_27 * V_27 ,
T_4 V_19 )
{
F_62 ( V_68 , V_27 , V_19 ) ;
F_64 ( V_68 , V_27 ) ;
}
static void F_68 ( struct V_61 * V_61 )
{
F_69 ( V_61 -> V_87 , & V_61 -> V_88 ) ;
}
static void F_70 ( struct V_89 * V_90 )
{
struct V_61 * V_61 = V_90 -> V_68 -> V_61 ;
if ( V_90 -> V_91 && V_90 -> V_92 ) {
F_44 ( & V_90 -> V_37 , & V_61 -> V_93 ) ;
F_68 ( V_61 ) ;
}
}
static void F_71 ( int V_94 , unsigned long V_95 , void * V_96 )
{
unsigned long V_31 ;
struct V_89 * V_90 = V_96 ;
struct V_61 * V_61 = V_90 -> V_68 -> V_61 ;
V_90 -> V_97 = V_94 || V_95 ? - V_98 : 0 ;
F_17 ( & V_61 -> V_10 , V_31 ) ;
V_90 -> V_92 = 1 ;
F_70 ( V_90 ) ;
F_19 ( & V_61 -> V_10 , V_31 ) ;
}
static void F_72 ( struct V_27 * V_27 , int V_97 )
{
unsigned long V_31 ;
struct V_70 * V_71 = F_58 ( V_27 ) -> V_72 ;
struct V_89 * V_90 = V_71 -> V_99 ;
struct V_61 * V_61 = V_90 -> V_68 -> V_61 ;
V_90 -> V_97 = V_97 ;
F_17 ( & V_61 -> V_10 , V_31 ) ;
V_90 -> V_92 = 1 ;
F_70 ( V_90 ) ;
F_19 ( & V_61 -> V_10 , V_31 ) ;
}
static void F_73 ( struct V_67 * V_68 , struct V_12 * V_12 ,
T_4 V_100 )
{
struct V_61 * V_61 = V_68 -> V_61 ;
unsigned long V_31 ;
F_17 ( & V_61 -> V_10 , V_31 ) ;
F_27 ( V_12 , & V_61 -> V_74 ) ;
F_19 ( & V_68 -> V_61 -> V_10 , V_31 ) ;
F_68 ( V_61 ) ;
}
static void F_74 ( struct V_67 * V_68 , struct V_12 * V_12 )
{
struct V_38 V_33 ;
struct V_61 * V_61 = V_68 -> V_61 ;
unsigned long V_31 ;
F_22 ( & V_33 ) ;
F_17 ( & V_61 -> V_10 , V_31 ) ;
F_32 ( V_12 , & V_61 -> V_74 ) ;
F_19 ( & V_61 -> V_10 , V_31 ) ;
F_68 ( V_61 ) ;
}
static void F_75 ( struct V_89 * V_90 )
{
struct V_67 * V_68 = V_90 -> V_68 ;
struct V_27 * V_27 ;
int V_30 ;
V_27 = V_90 -> V_27 ;
if ( V_27 )
V_27 -> V_101 = V_90 -> V_102 ;
if ( V_90 -> V_97 ) {
F_33 ( V_90 -> V_12 ) ;
return;
}
V_30 = F_76 ( V_68 -> V_56 , V_90 -> V_103 , V_90 -> V_100 ) ;
if ( V_30 ) {
F_77 ( L_1 ) ;
F_33 ( V_90 -> V_12 ) ;
return;
}
if ( V_27 ) {
F_74 ( V_68 , V_90 -> V_12 ) ;
F_59 ( V_27 , 0 ) ;
} else
F_73 ( V_68 , V_90 -> V_12 , V_90 -> V_100 ) ;
F_53 ( & V_90 -> V_37 ) ;
F_21 ( V_90 , V_68 -> V_61 -> V_104 ) ;
}
static void F_78 ( struct V_89 * V_90 )
{
int V_30 ;
struct V_67 * V_68 = V_90 -> V_68 ;
V_30 = F_79 ( V_68 -> V_56 , V_90 -> V_103 ) ;
if ( V_30 )
F_77 ( L_2 ) ;
if ( V_90 -> V_105 )
F_67 ( V_68 , V_90 -> V_27 , V_90 -> V_100 ) ;
else
F_59 ( V_90 -> V_27 , 0 ) ;
F_74 ( V_68 , V_90 -> V_12 ) ;
F_74 ( V_68 , V_90 -> V_32 ) ;
F_21 ( V_90 , V_68 -> V_61 -> V_104 ) ;
}
static void F_80 ( struct V_61 * V_61 , struct V_51 * V_52 ,
void (* F_81)( struct V_89 * ) )
{
unsigned long V_31 ;
struct V_51 V_106 ;
struct V_89 * V_90 , * V_26 ;
F_37 ( & V_106 ) ;
F_17 ( & V_61 -> V_10 , V_31 ) ;
F_41 ( V_52 , & V_106 ) ;
F_19 ( & V_61 -> V_10 , V_31 ) ;
F_82 (m, tmp, &maps, list)
F_81 ( V_90 ) ;
}
static int F_83 ( struct V_61 * V_61 , struct V_27 * V_27 )
{
return ! ( V_27 -> V_76 & V_61 -> V_81 ) &&
( V_27 -> V_107 == ( V_61 -> V_108 << V_109 ) ) ;
}
static int F_84 ( struct V_61 * V_61 , struct V_27 * V_27 )
{
return ( F_85 ( V_27 ) == V_110 ) &&
F_83 ( V_61 , V_27 ) ;
}
static void F_86 ( struct V_27 * V_27 , T_5 * * V_111 ,
T_5 * F_81 )
{
* V_111 = V_27 -> V_101 ;
V_27 -> V_101 = F_81 ;
}
static int F_87 ( struct V_61 * V_61 )
{
if ( V_61 -> V_112 )
return 0 ;
V_61 -> V_112 = F_20 ( V_61 -> V_104 , V_113 ) ;
return V_61 -> V_112 ? 0 : - V_114 ;
}
static struct V_89 * F_88 ( struct V_61 * V_61 )
{
struct V_89 * V_30 = V_61 -> V_112 ;
F_16 ( ! V_61 -> V_112 ) ;
V_61 -> V_112 = NULL ;
return V_30 ;
}
static void F_89 ( struct V_67 * V_68 , T_4 V_103 ,
struct V_115 * V_116 , T_4 V_117 ,
T_4 V_118 ,
struct V_12 * V_12 , struct V_27 * V_27 )
{
int V_30 ;
struct V_61 * V_61 = V_68 -> V_61 ;
struct V_89 * V_90 = F_88 ( V_61 ) ;
F_37 ( & V_90 -> V_37 ) ;
V_90 -> V_91 = 0 ;
V_90 -> V_92 = 0 ;
V_90 -> V_68 = V_68 ;
V_90 -> V_103 = V_103 ;
V_90 -> V_100 = V_118 ;
V_90 -> V_12 = V_12 ;
V_90 -> V_97 = 0 ;
V_90 -> V_27 = NULL ;
if ( ! F_43 ( & V_61 -> V_119 , & V_90 -> V_37 ) )
V_90 -> V_91 = 1 ;
if ( F_84 ( V_61 , V_27 ) ) {
struct V_70 * V_71 = F_58 ( V_27 ) -> V_72 ;
V_71 -> V_99 = V_90 ;
V_90 -> V_27 = V_27 ;
F_86 ( V_27 , & V_90 -> V_102 , F_72 ) ;
F_67 ( V_68 , V_27 , V_118 ) ;
} else {
struct V_120 V_121 , V_122 ;
V_121 . V_80 = V_116 -> V_80 ;
V_121 . V_123 = V_117 * V_61 -> V_108 ;
V_121 . V_46 = V_61 -> V_108 ;
V_122 . V_80 = V_68 -> V_79 -> V_80 ;
V_122 . V_123 = V_118 * V_61 -> V_108 ;
V_122 . V_46 = V_61 -> V_108 ;
V_30 = F_90 ( V_61 -> V_124 , & V_121 , 1 , & V_122 ,
0 , F_71 , V_90 ) ;
if ( V_30 < 0 ) {
F_21 ( V_90 , V_61 -> V_104 ) ;
F_77 ( L_3 ) ;
F_33 ( V_12 ) ;
}
}
}
static void F_91 ( struct V_67 * V_68 , T_4 V_103 ,
T_4 V_117 , T_4 V_118 ,
struct V_12 * V_12 , struct V_27 * V_27 )
{
F_89 ( V_68 , V_103 , V_68 -> V_79 ,
V_117 , V_118 , V_12 , V_27 ) ;
}
static void F_92 ( struct V_67 * V_68 , T_4 V_103 ,
T_4 V_118 ,
struct V_12 * V_12 , struct V_27 * V_27 )
{
F_89 ( V_68 , V_103 , V_68 -> V_82 ,
V_103 , V_118 , V_12 , V_27 ) ;
}
static void F_93 ( struct V_67 * V_68 , T_4 V_103 ,
T_4 V_100 , struct V_12 * V_12 ,
struct V_27 * V_27 )
{
struct V_61 * V_61 = V_68 -> V_61 ;
struct V_89 * V_90 = F_88 ( V_61 ) ;
F_37 ( & V_90 -> V_37 ) ;
V_90 -> V_91 = 1 ;
V_90 -> V_92 = 0 ;
V_90 -> V_68 = V_68 ;
V_90 -> V_103 = V_103 ;
V_90 -> V_100 = V_100 ;
V_90 -> V_12 = V_12 ;
V_90 -> V_97 = 0 ;
V_90 -> V_27 = NULL ;
if ( ! V_61 -> V_125 . V_126 )
F_75 ( V_90 ) ;
else if ( F_84 ( V_61 , V_27 ) ) {
struct V_70 * V_71 = F_58 ( V_27 ) -> V_72 ;
V_71 -> V_99 = V_90 ;
V_90 -> V_27 = V_27 ;
F_86 ( V_27 , & V_90 -> V_102 , F_72 ) ;
F_67 ( V_68 , V_27 , V_100 ) ;
} else {
int V_30 ;
struct V_120 V_122 ;
V_122 . V_80 = V_68 -> V_79 -> V_80 ;
V_122 . V_123 = V_100 * V_61 -> V_108 ;
V_122 . V_46 = V_61 -> V_108 ;
V_30 = F_94 ( V_61 -> V_124 , 1 , & V_122 , 0 , F_71 , V_90 ) ;
if ( V_30 < 0 ) {
F_21 ( V_90 , V_61 -> V_104 ) ;
F_77 ( L_4 ) ;
F_33 ( V_12 ) ;
}
}
}
static int F_95 ( struct V_67 * V_68 , T_4 * V_127 )
{
int V_30 ;
T_4 V_128 ;
unsigned long V_31 ;
struct V_61 * V_61 = V_68 -> V_61 ;
V_30 = F_96 ( V_61 -> V_129 , & V_128 ) ;
if ( V_30 )
return V_30 ;
if ( V_128 <= V_61 -> V_130 && ! V_61 -> V_131 ) {
F_97 ( L_5 ,
F_98 ( V_61 -> V_64 ) ) ;
F_17 ( & V_61 -> V_10 , V_31 ) ;
V_61 -> V_131 = 1 ;
F_19 ( & V_61 -> V_10 , V_31 ) ;
F_99 ( V_61 -> V_132 -> V_133 ) ;
}
if ( ! V_128 ) {
if ( V_61 -> V_134 )
return - V_135 ;
else {
V_30 = F_100 ( V_61 -> V_129 ) ;
if ( V_30 ) {
F_77 ( L_6 ,
V_136 , V_30 ) ;
return V_30 ;
}
V_30 = F_96 ( V_61 -> V_129 , & V_128 ) ;
if ( V_30 )
return V_30 ;
if ( ! V_128 ) {
F_97 ( L_7 ,
F_98 ( V_61 -> V_64 ) ) ;
F_17 ( & V_61 -> V_10 , V_31 ) ;
V_61 -> V_134 = 1 ;
F_19 ( & V_61 -> V_10 , V_31 ) ;
return - V_135 ;
}
}
}
V_30 = F_101 ( V_61 -> V_129 , V_127 ) ;
if ( V_30 )
return V_30 ;
return 0 ;
}
static void F_102 ( struct V_27 * V_27 )
{
struct V_70 * V_71 = F_58 ( V_27 ) -> V_72 ;
struct V_67 * V_68 = V_71 -> V_68 ;
struct V_61 * V_61 = V_68 -> V_61 ;
unsigned long V_31 ;
F_17 ( & V_61 -> V_10 , V_31 ) ;
F_18 ( & V_61 -> V_75 , V_27 ) ;
F_19 ( & V_61 -> V_10 , V_31 ) ;
}
static void F_103 ( struct V_12 * V_12 )
{
struct V_27 * V_27 ;
struct V_38 V_33 ;
F_22 ( & V_33 ) ;
F_27 ( V_12 , & V_33 ) ;
while ( ( V_27 = F_34 ( & V_33 ) ) )
F_102 ( V_27 ) ;
}
static void F_104 ( struct V_67 * V_68 , struct V_27 * V_27 )
{
int V_30 ;
unsigned long V_31 ;
struct V_61 * V_61 = V_68 -> V_61 ;
struct V_12 * V_12 , * V_32 ;
struct V_15 V_16 , V_137 ;
T_4 V_19 = F_61 ( V_68 , V_27 ) ;
struct V_138 V_139 ;
struct V_89 * V_90 ;
F_47 ( V_68 -> V_56 , V_19 , & V_16 ) ;
if ( F_15 ( V_68 -> V_61 -> V_8 , & V_16 , V_27 , & V_12 ) )
return;
V_30 = F_105 ( V_68 -> V_56 , V_19 , 1 , & V_139 ) ;
switch ( V_30 ) {
case 0 :
F_45 ( V_68 -> V_56 , V_139 . V_19 , & V_137 ) ;
if ( F_15 ( V_68 -> V_61 -> V_8 , & V_137 , V_27 , & V_32 ) ) {
F_30 ( V_12 , V_27 ) ;
break;
}
if ( F_83 ( V_61 , V_27 ) ) {
V_90 = F_88 ( V_61 ) ;
V_90 -> V_68 = V_68 ;
V_90 -> V_105 = ( ! V_139 . V_140 ) & V_61 -> V_125 . V_141 ;
V_90 -> V_103 = V_19 ;
V_90 -> V_100 = V_139 . V_19 ;
V_90 -> V_12 = V_12 ;
V_90 -> V_32 = V_32 ;
V_90 -> V_97 = 0 ;
V_90 -> V_27 = V_27 ;
if ( ! F_43 ( & V_61 -> V_142 , & V_90 -> V_37 ) ) {
F_17 ( & V_61 -> V_10 , V_31 ) ;
F_44 ( & V_90 -> V_37 , & V_61 -> V_143 ) ;
F_19 ( & V_61 -> V_10 , V_31 ) ;
F_68 ( V_61 ) ;
}
} else {
T_6 V_144 = V_27 -> V_76 - ( V_19 << V_61 -> V_77 ) ;
unsigned V_145 = ( V_61 -> V_108 - V_144 ) << 9 ;
V_27 -> V_107 = F_2 ( V_27 -> V_107 , V_145 ) ;
F_30 ( V_12 , V_27 ) ;
F_30 ( V_32 , V_27 ) ;
F_67 ( V_68 , V_27 , V_139 . V_19 ) ;
}
break;
case - V_146 :
F_30 ( V_12 , V_27 ) ;
F_59 ( V_27 , 0 ) ;
break;
default:
F_77 ( L_8 , V_30 ) ;
F_30 ( V_12 , V_27 ) ;
F_35 ( V_27 ) ;
break;
}
}
static void F_106 ( struct V_67 * V_68 , struct V_27 * V_27 , T_4 V_19 ,
struct V_15 * V_16 ,
struct V_138 * V_139 ,
struct V_12 * V_12 )
{
int V_30 ;
T_4 V_100 ;
V_30 = F_95 ( V_68 , & V_100 ) ;
switch ( V_30 ) {
case 0 :
F_91 ( V_68 , V_19 , V_139 -> V_19 ,
V_100 , V_12 , V_27 ) ;
break;
case - V_135 :
F_103 ( V_12 ) ;
break;
default:
F_77 ( L_9 , V_136 , V_30 ) ;
F_33 ( V_12 ) ;
break;
}
}
static void F_107 ( struct V_67 * V_68 , struct V_27 * V_27 ,
T_4 V_19 ,
struct V_138 * V_139 )
{
struct V_12 * V_12 ;
struct V_61 * V_61 = V_68 -> V_61 ;
struct V_15 V_16 ;
F_45 ( V_68 -> V_56 , V_139 -> V_19 , & V_16 ) ;
if ( F_15 ( V_61 -> V_8 , & V_16 , V_27 , & V_12 ) )
return;
if ( F_85 ( V_27 ) == V_110 )
F_106 ( V_68 , V_27 , V_19 , & V_16 , V_139 , V_12 ) ;
else {
struct V_70 * V_71 = F_58 ( V_27 ) -> V_72 ;
V_71 -> V_147 = F_38 ( & V_61 -> V_119 ) ;
F_30 ( V_12 , V_27 ) ;
F_67 ( V_68 , V_27 , V_139 -> V_19 ) ;
}
}
static void F_108 ( struct V_67 * V_68 , struct V_27 * V_27 , T_4 V_19 ,
struct V_12 * V_12 )
{
int V_30 ;
T_4 V_100 ;
if ( ! V_27 -> V_107 ) {
F_30 ( V_12 , V_27 ) ;
F_67 ( V_68 , V_27 , 0 ) ;
return;
}
if ( F_85 ( V_27 ) == V_148 ) {
F_109 ( V_27 ) ;
F_30 ( V_12 , V_27 ) ;
F_59 ( V_27 , 0 ) ;
return;
}
V_30 = F_95 ( V_68 , & V_100 ) ;
switch ( V_30 ) {
case 0 :
if ( V_68 -> V_82 )
F_92 ( V_68 , V_19 , V_100 , V_12 , V_27 ) ;
else
F_93 ( V_68 , V_19 , V_100 , V_12 , V_27 ) ;
break;
case - V_135 :
F_103 ( V_12 ) ;
break;
default:
F_77 ( L_9 , V_136 , V_30 ) ;
F_33 ( V_12 ) ;
break;
}
}
static void F_110 ( struct V_67 * V_68 , struct V_27 * V_27 )
{
int V_30 ;
T_4 V_19 = F_61 ( V_68 , V_27 ) ;
struct V_12 * V_12 ;
struct V_15 V_16 ;
struct V_138 V_139 ;
F_47 ( V_68 -> V_56 , V_19 , & V_16 ) ;
if ( F_15 ( V_68 -> V_61 -> V_8 , & V_16 , V_27 , & V_12 ) )
return;
V_30 = F_105 ( V_68 -> V_56 , V_19 , 1 , & V_139 ) ;
switch ( V_30 ) {
case 0 :
F_30 ( V_12 , V_27 ) ;
if ( V_139 . V_140 )
F_107 ( V_68 , V_27 , V_19 , & V_139 ) ;
else
F_67 ( V_68 , V_27 , V_139 . V_19 ) ;
break;
case - V_146 :
if ( F_85 ( V_27 ) == V_148 && V_68 -> V_82 ) {
F_30 ( V_12 , V_27 ) ;
F_66 ( V_68 , V_27 ) ;
} else
F_108 ( V_68 , V_27 , V_19 , V_12 ) ;
break;
default:
F_77 ( L_10 , V_30 ) ;
F_30 ( V_12 , V_27 ) ;
F_35 ( V_27 ) ;
break;
}
}
static int F_111 ( struct V_61 * V_61 )
{
return V_149 < V_61 -> V_150 ||
V_149 > V_61 -> V_150 + V_151 ;
}
static void F_112 ( struct V_61 * V_61 )
{
unsigned long V_31 ;
struct V_27 * V_27 ;
struct V_38 V_33 ;
int V_30 ;
F_22 ( & V_33 ) ;
F_17 ( & V_61 -> V_10 , V_31 ) ;
F_26 ( & V_33 , & V_61 -> V_74 ) ;
F_22 ( & V_61 -> V_74 ) ;
F_19 ( & V_61 -> V_10 , V_31 ) ;
while ( ( V_27 = F_34 ( & V_33 ) ) ) {
struct V_70 * V_71 = F_58 ( V_27 ) -> V_72 ;
struct V_67 * V_68 = V_71 -> V_68 ;
if ( F_87 ( V_61 ) ) {
F_17 ( & V_61 -> V_10 , V_31 ) ;
F_26 ( & V_61 -> V_74 , & V_33 ) ;
F_19 ( & V_61 -> V_10 , V_31 ) ;
break;
}
if ( V_27 -> V_83 & V_152 )
F_104 ( V_68 , V_27 ) ;
else
F_110 ( V_68 , V_27 ) ;
}
F_22 ( & V_33 ) ;
F_17 ( & V_61 -> V_10 , V_31 ) ;
F_26 ( & V_33 , & V_61 -> V_86 ) ;
F_22 ( & V_61 -> V_86 ) ;
F_19 ( & V_61 -> V_10 , V_31 ) ;
if ( F_29 ( & V_33 ) && ! F_111 ( V_61 ) )
return;
V_30 = F_100 ( V_61 -> V_129 ) ;
if ( V_30 ) {
F_77 ( L_6 ,
V_136 , V_30 ) ;
while ( ( V_27 = F_34 ( & V_33 ) ) )
F_35 ( V_27 ) ;
return;
}
V_61 -> V_150 = V_149 ;
while ( ( V_27 = F_34 ( & V_33 ) ) )
F_65 ( V_27 ) ;
}
static void F_113 ( struct V_153 * V_154 )
{
struct V_61 * V_61 = F_114 ( V_154 , struct V_61 , V_88 ) ;
F_80 ( V_61 , & V_61 -> V_93 , F_75 ) ;
F_80 ( V_61 , & V_61 -> V_143 , F_78 ) ;
F_112 ( V_61 ) ;
}
static void F_115 ( struct V_153 * V_154 )
{
struct V_61 * V_61 = F_114 ( F_116 ( V_154 ) , struct V_61 , V_155 ) ;
F_68 ( V_61 ) ;
F_117 ( V_61 -> V_87 , & V_61 -> V_155 , V_151 ) ;
}
static void F_118 ( struct V_67 * V_68 , struct V_27 * V_27 )
{
unsigned long V_31 ;
struct V_61 * V_61 = V_68 -> V_61 ;
F_17 ( & V_61 -> V_10 , V_31 ) ;
F_18 ( & V_61 -> V_74 , V_27 ) ;
F_19 ( & V_61 -> V_10 , V_31 ) ;
F_68 ( V_61 ) ;
}
static struct V_70 * F_119 ( struct V_67 * V_68 , struct V_27 * V_27 )
{
struct V_61 * V_61 = V_68 -> V_61 ;
struct V_70 * V_71 = F_20 ( V_61 -> V_156 , V_35 ) ;
V_71 -> V_68 = V_68 ;
V_71 -> V_147 = NULL ;
V_71 -> V_157 = V_27 -> V_83 & V_152 ? NULL : F_38 ( & V_61 -> V_142 ) ;
V_71 -> V_99 = NULL ;
return V_71 ;
}
static int F_120 ( struct V_158 * V_132 , struct V_27 * V_27 ,
union V_159 * V_160 )
{
int V_30 ;
struct V_67 * V_68 = V_132 -> V_161 ;
T_4 V_19 = F_61 ( V_68 , V_27 ) ;
struct V_55 * V_56 = V_68 -> V_56 ;
struct V_138 V_127 ;
V_160 -> V_72 = F_119 ( V_68 , V_27 ) ;
if ( V_27 -> V_83 & ( V_152 | V_84 | V_85 ) ) {
F_118 ( V_68 , V_27 ) ;
return V_162 ;
}
V_30 = F_105 ( V_56 , V_19 , 0 , & V_127 ) ;
switch ( V_30 ) {
case 0 :
if ( F_121 ( V_127 . V_140 ) ) {
F_118 ( V_68 , V_27 ) ;
V_30 = V_162 ;
} else {
F_62 ( V_68 , V_27 , V_127 . V_19 ) ;
V_30 = V_163 ;
}
break;
case - V_146 :
case - V_164 :
F_118 ( V_68 , V_27 ) ;
V_30 = V_162 ;
break;
}
return V_30 ;
}
static int F_122 ( struct V_165 * V_166 , int V_167 )
{
int V_30 ;
unsigned long V_31 ;
struct V_168 * V_169 = F_114 ( V_166 , struct V_168 , V_170 ) ;
F_17 ( & V_169 -> V_61 -> V_10 , V_31 ) ;
V_30 = ! F_29 ( & V_169 -> V_61 -> V_75 ) ;
F_19 ( & V_169 -> V_61 -> V_10 , V_31 ) ;
if ( ! V_30 ) {
struct V_171 * V_172 = F_123 ( V_169 -> V_173 -> V_80 ) ;
V_30 = F_124 ( & V_172 -> V_174 , V_167 ) ;
}
return V_30 ;
}
static void F_125 ( struct V_61 * V_61 )
{
F_26 ( & V_61 -> V_74 , & V_61 -> V_75 ) ;
F_22 ( & V_61 -> V_75 ) ;
}
static int F_126 ( struct V_61 * V_61 , struct V_158 * V_132 )
{
struct V_168 * V_169 = V_132 -> V_161 ;
V_61 -> V_132 = V_132 ;
V_61 -> V_130 = V_169 -> V_130 ;
V_61 -> V_125 = V_169 -> V_125 ;
if ( V_169 -> V_125 . V_141 ) {
struct V_171 * V_172 = F_123 ( V_169 -> V_173 -> V_80 ) ;
if ( ! V_172 || ! F_127 ( V_172 ) ) {
char V_175 [ V_176 ] ;
F_97 ( L_11 ,
F_128 ( V_169 -> V_173 -> V_80 , V_175 ) ) ;
V_61 -> V_125 . V_141 = 0 ;
}
}
return 0 ;
}
static void F_129 ( struct V_61 * V_61 , struct V_158 * V_132 )
{
if ( V_61 -> V_132 == V_132 )
V_61 -> V_132 = NULL ;
}
static void F_130 ( struct V_177 * V_125 )
{
V_125 -> V_126 = 1 ;
V_125 -> V_178 = 1 ;
V_125 -> V_141 = 1 ;
}
static void F_131 ( struct V_61 * V_61 )
{
F_52 ( V_61 ) ;
if ( F_132 ( V_61 -> V_129 ) < 0 )
F_97 ( L_12 , V_136 ) ;
F_9 ( V_61 -> V_8 ) ;
F_133 ( V_61 -> V_124 ) ;
if ( V_61 -> V_87 )
F_134 ( V_61 -> V_87 ) ;
if ( V_61 -> V_112 )
F_21 ( V_61 -> V_112 , V_61 -> V_104 ) ;
F_10 ( V_61 -> V_104 ) ;
F_10 ( V_61 -> V_156 ) ;
F_7 ( V_61 ) ;
}
static struct V_61 * F_135 ( struct V_62 * V_64 ,
struct V_65 * V_179 ,
unsigned long V_180 , char * * error )
{
int V_30 ;
void * V_181 ;
struct V_61 * V_61 ;
struct V_182 * V_129 ;
V_129 = F_136 ( V_179 , V_180 ) ;
if ( F_137 ( V_129 ) ) {
* error = L_13 ;
return (struct V_61 * ) V_129 ;
}
V_61 = F_4 ( sizeof( * V_61 ) , V_9 ) ;
if ( ! V_61 ) {
* error = L_14 ;
V_181 = F_138 ( - V_114 ) ;
goto V_183;
}
V_61 -> V_129 = V_129 ;
V_61 -> V_108 = V_180 ;
V_61 -> V_77 = F_139 ( V_180 ) - 1 ;
V_61 -> V_81 = V_180 - 1 ;
V_61 -> V_130 = 0 ;
F_130 ( & V_61 -> V_125 ) ;
V_61 -> V_8 = F_3 ( V_184 ) ;
if ( ! V_61 -> V_8 ) {
* error = L_15 ;
V_181 = F_138 ( - V_114 ) ;
goto V_185;
}
V_61 -> V_124 = F_140 () ;
if ( F_137 ( V_61 -> V_124 ) ) {
V_30 = F_141 ( V_61 -> V_124 ) ;
* error = L_16 ;
V_181 = F_138 ( V_30 ) ;
goto V_186;
}
V_61 -> V_87 = F_142 ( L_17 V_187 , V_188 ) ;
if ( ! V_61 -> V_87 ) {
* error = L_18 ;
V_181 = F_138 ( - V_114 ) ;
goto V_189;
}
F_143 ( & V_61 -> V_88 , F_113 ) ;
F_144 ( & V_61 -> V_155 , F_115 ) ;
F_5 ( & V_61 -> V_10 ) ;
F_22 ( & V_61 -> V_74 ) ;
F_22 ( & V_61 -> V_86 ) ;
F_37 ( & V_61 -> V_93 ) ;
F_37 ( & V_61 -> V_143 ) ;
V_61 -> V_131 = 0 ;
V_61 -> V_134 = 0 ;
F_22 ( & V_61 -> V_75 ) ;
F_36 ( & V_61 -> V_119 ) ;
F_36 ( & V_61 -> V_142 ) ;
V_61 -> V_112 = NULL ;
V_61 -> V_104 =
F_6 ( V_190 , sizeof( struct V_89 ) ) ;
if ( ! V_61 -> V_104 ) {
* error = L_19 ;
V_181 = F_138 ( - V_114 ) ;
goto V_191;
}
V_61 -> V_156 =
F_6 ( V_192 , sizeof( struct V_70 ) ) ;
if ( ! V_61 -> V_156 ) {
* error = L_20 ;
V_181 = F_138 ( - V_114 ) ;
goto V_193;
}
V_61 -> V_194 = 1 ;
V_61 -> V_150 = V_149 ;
V_61 -> V_64 = V_64 ;
V_61 -> V_66 = V_179 ;
F_50 ( V_61 ) ;
return V_61 ;
V_193:
F_10 ( V_61 -> V_104 ) ;
V_191:
F_134 ( V_61 -> V_87 ) ;
V_189:
F_133 ( V_61 -> V_124 ) ;
V_186:
F_9 ( V_61 -> V_8 ) ;
V_185:
F_7 ( V_61 ) ;
V_183:
if ( F_132 ( V_129 ) )
F_97 ( L_12 , V_136 ) ;
return V_181 ;
}
static void F_145 ( struct V_61 * V_61 )
{
F_16 ( ! F_51 ( & V_58 . V_59 ) ) ;
V_61 -> V_194 ++ ;
}
static void F_146 ( struct V_61 * V_61 )
{
F_16 ( ! F_51 ( & V_58 . V_59 ) ) ;
F_16 ( ! V_61 -> V_194 ) ;
if ( ! -- V_61 -> V_194 )
F_131 ( V_61 ) ;
}
static struct V_61 * F_147 ( struct V_62 * V_64 ,
struct V_65 * V_179 ,
unsigned long V_180 , char * * error ,
int * V_195 )
{
struct V_61 * V_61 = F_56 ( V_179 ) ;
if ( V_61 ) {
if ( V_61 -> V_64 != V_64 )
return F_138 ( - V_196 ) ;
F_145 ( V_61 ) ;
} else {
V_61 = F_54 ( V_64 ) ;
if ( V_61 ) {
if ( V_61 -> V_66 != V_179 )
return F_138 ( - V_197 ) ;
F_145 ( V_61 ) ;
} else {
V_61 = F_135 ( V_64 , V_179 , V_180 , error ) ;
* V_195 = 1 ;
}
}
return V_61 ;
}
static void F_148 ( struct V_158 * V_132 )
{
struct V_168 * V_169 = V_132 -> V_161 ;
F_149 ( & V_58 . V_59 ) ;
F_129 ( V_169 -> V_61 , V_132 ) ;
F_146 ( V_169 -> V_61 ) ;
F_150 ( V_132 , V_169 -> V_179 ) ;
F_150 ( V_132 , V_169 -> V_173 ) ;
F_7 ( V_169 ) ;
F_151 ( & V_58 . V_59 ) ;
}
static int F_152 ( struct V_198 * V_199 , struct V_177 * V_125 ,
struct V_158 * V_132 )
{
int V_30 ;
unsigned V_200 ;
const char * V_201 ;
static struct V_202 V_203 [] = {
{ 0 , 3 , L_21 } ,
} ;
if ( ! V_199 -> V_200 )
return 0 ;
V_30 = F_153 ( V_203 , V_199 , & V_200 , & V_132 -> error ) ;
if ( V_30 )
return - V_197 ;
while ( V_200 && ! V_30 ) {
V_201 = F_154 ( V_199 ) ;
V_200 -- ;
if ( ! strcasecmp ( V_201 , L_22 ) ) {
V_125 -> V_126 = 0 ;
continue;
} else if ( ! strcasecmp ( V_201 , L_23 ) ) {
V_125 -> V_178 = 0 ;
continue;
} else if ( ! strcasecmp ( V_201 , L_24 ) ) {
V_125 -> V_141 = 0 ;
continue;
}
V_132 -> error = L_25 ;
V_30 = - V_197 ;
}
return V_30 ;
}
static int F_155 ( struct V_158 * V_132 , unsigned V_200 , char * * V_204 )
{
int V_30 , V_205 = 0 ;
struct V_168 * V_169 ;
struct V_61 * V_61 ;
struct V_177 V_125 ;
struct V_198 V_199 ;
struct V_115 * V_173 ;
unsigned long V_180 ;
T_4 V_130 ;
struct V_115 * V_179 ;
T_6 V_206 ;
char V_57 [ V_176 ] ;
F_149 ( & V_58 . V_59 ) ;
if ( V_200 < 4 ) {
V_132 -> error = L_26 ;
V_30 = - V_197 ;
goto V_207;
}
V_199 . V_200 = V_200 ;
V_199 . V_204 = V_204 ;
V_30 = F_156 ( V_132 , V_204 [ 0 ] , V_208 | V_209 , & V_179 ) ;
if ( V_30 ) {
V_132 -> error = L_27 ;
goto V_207;
}
V_206 = F_157 ( V_179 -> V_80 -> V_210 ) >> V_109 ;
if ( V_206 > V_211 )
F_97 ( L_28 ,
F_128 ( V_179 -> V_80 , V_57 ) , V_212 ) ;
V_30 = F_156 ( V_132 , V_204 [ 1 ] , V_208 | V_209 , & V_173 ) ;
if ( V_30 ) {
V_132 -> error = L_29 ;
goto V_213;
}
if ( F_158 ( V_204 [ 2 ] , 10 , & V_180 ) || ! V_180 ||
V_180 < V_214 ||
V_180 > V_215 ||
! F_159 ( V_180 ) ) {
V_132 -> error = L_30 ;
V_30 = - V_197 ;
goto V_34;
}
if ( F_160 ( V_204 [ 3 ] , 10 , ( unsigned long long * ) & V_130 ) ) {
V_132 -> error = L_31 ;
V_30 = - V_197 ;
goto V_34;
}
F_130 ( & V_125 ) ;
F_161 ( & V_199 , 4 ) ;
V_30 = F_152 ( & V_199 , & V_125 , V_132 ) ;
if ( V_30 )
goto V_34;
V_169 = F_162 ( sizeof( * V_169 ) , V_9 ) ;
if ( ! V_169 ) {
V_30 = - V_114 ;
goto V_34;
}
V_61 = F_147 ( F_163 ( V_132 -> V_133 ) , V_179 -> V_80 ,
V_180 , & V_132 -> error , & V_205 ) ;
if ( F_137 ( V_61 ) ) {
V_30 = F_141 ( V_61 ) ;
goto V_216;
}
if ( ! V_205 && V_125 . V_178 != V_61 -> V_125 . V_178 ) {
V_132 -> error = L_32 ;
V_30 = - V_197 ;
goto V_217;
}
V_169 -> V_61 = V_61 ;
V_169 -> V_132 = V_132 ;
V_169 -> V_179 = V_179 ;
V_169 -> V_173 = V_173 ;
V_169 -> V_130 = V_130 ;
V_169 -> V_125 = V_125 ;
V_132 -> V_218 = 1 ;
if ( V_125 . V_178 && V_125 . V_141 ) {
V_132 -> V_219 = 1 ;
V_132 -> V_220 = 1 ;
}
V_132 -> V_161 = V_169 ;
V_169 -> V_170 . V_221 = F_122 ;
F_164 ( V_132 -> V_133 , & V_169 -> V_170 ) ;
F_151 ( & V_58 . V_59 ) ;
return 0 ;
V_217:
F_146 ( V_61 ) ;
V_216:
F_7 ( V_169 ) ;
V_34:
F_150 ( V_132 , V_173 ) ;
V_213:
F_150 ( V_132 , V_179 ) ;
V_207:
F_151 ( & V_58 . V_59 ) ;
return V_30 ;
}
static int F_165 ( struct V_158 * V_132 , struct V_27 * V_27 ,
union V_159 * V_160 )
{
int V_30 ;
struct V_168 * V_169 = V_132 -> V_161 ;
struct V_61 * V_61 = V_169 -> V_61 ;
unsigned long V_31 ;
F_17 ( & V_61 -> V_10 , V_31 ) ;
V_27 -> V_78 = V_169 -> V_173 -> V_80 ;
V_30 = V_163 ;
F_19 ( & V_61 -> V_10 , V_31 ) ;
return V_30 ;
}
static int F_166 ( struct V_158 * V_132 )
{
int V_30 ;
struct V_168 * V_169 = V_132 -> V_161 ;
struct V_61 * V_61 = V_169 -> V_61 ;
T_4 V_222 , V_223 ;
V_30 = F_126 ( V_61 , V_132 ) ;
if ( V_30 )
return V_30 ;
V_222 = V_132 -> V_6 >> V_61 -> V_77 ;
V_30 = F_167 ( V_61 -> V_129 , & V_223 ) ;
if ( V_30 ) {
F_77 ( L_33 ) ;
return V_30 ;
}
if ( V_222 < V_223 ) {
F_77 ( L_34 ,
V_222 , V_223 ) ;
return - V_197 ;
} else if ( V_222 > V_223 ) {
V_30 = F_168 ( V_61 -> V_129 , V_222 ) ;
if ( V_30 ) {
F_77 ( L_35 ) ;
return V_30 ;
}
V_30 = F_100 ( V_61 -> V_129 ) ;
if ( V_30 ) {
F_77 ( L_6 ,
V_136 , V_30 ) ;
return V_30 ;
}
}
return 0 ;
}
static void F_169 ( struct V_158 * V_132 )
{
struct V_168 * V_169 = V_132 -> V_161 ;
struct V_61 * V_61 = V_169 -> V_61 ;
unsigned long V_31 ;
F_17 ( & V_61 -> V_10 , V_31 ) ;
V_61 -> V_131 = 0 ;
V_61 -> V_134 = 0 ;
F_125 ( V_61 ) ;
F_19 ( & V_61 -> V_10 , V_31 ) ;
F_115 ( & V_61 -> V_155 . V_53 ) ;
}
static void F_170 ( struct V_158 * V_132 )
{
int V_30 ;
struct V_168 * V_169 = V_132 -> V_161 ;
struct V_61 * V_61 = V_169 -> V_61 ;
F_171 ( & V_61 -> V_155 ) ;
F_172 ( V_61 -> V_87 ) ;
V_30 = F_100 ( V_61 -> V_129 ) ;
if ( V_30 < 0 ) {
F_77 ( L_6 ,
V_136 , V_30 ) ;
}
}
static int F_173 ( unsigned V_200 , unsigned V_224 )
{
if ( V_200 != V_224 ) {
F_97 ( L_36 ,
V_200 , V_224 ) ;
return - V_197 ;
}
return 0 ;
}
static int F_174 ( char * V_225 , T_7 * V_226 , int V_227 )
{
if ( ! F_160 ( V_225 , 10 , ( unsigned long long * ) V_226 ) &&
* V_226 <= V_228 )
return 0 ;
if ( V_227 )
F_97 ( L_37 , V_225 ) ;
return - V_197 ;
}
static int F_175 ( unsigned V_200 , char * * V_204 , struct V_61 * V_61 )
{
T_7 V_226 ;
int V_30 ;
V_30 = F_173 ( V_200 , 2 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_174 ( V_204 [ 1 ] , & V_226 , 1 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_176 ( V_61 -> V_129 , V_226 ) ;
if ( V_30 ) {
F_97 ( L_38 ,
V_204 [ 1 ] ) ;
return V_30 ;
}
return 0 ;
}
static int F_177 ( unsigned V_200 , char * * V_204 , struct V_61 * V_61 )
{
T_7 V_226 ;
T_7 V_229 ;
int V_30 ;
V_30 = F_173 ( V_200 , 3 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_174 ( V_204 [ 1 ] , & V_226 , 1 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_174 ( V_204 [ 2 ] , & V_229 , 1 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_178 ( V_61 -> V_129 , V_226 , V_229 ) ;
if ( V_30 ) {
F_97 ( L_39 ,
V_204 [ 1 ] , V_204 [ 2 ] ) ;
return V_30 ;
}
return 0 ;
}
static int F_179 ( unsigned V_200 , char * * V_204 , struct V_61 * V_61 )
{
T_7 V_226 ;
int V_30 ;
V_30 = F_173 ( V_200 , 2 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_174 ( V_204 [ 1 ] , & V_226 , 1 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_180 ( V_61 -> V_129 , V_226 ) ;
if ( V_30 )
F_97 ( L_40 , V_204 [ 1 ] ) ;
return V_30 ;
}
static int F_181 ( unsigned V_200 , char * * V_204 , struct V_61 * V_61 )
{
T_7 V_230 , V_231 ;
int V_30 ;
V_30 = F_173 ( V_200 , 3 ) ;
if ( V_30 )
return V_30 ;
if ( F_160 ( V_204 [ 1 ] , 10 , ( unsigned long long * ) & V_230 ) ) {
F_97 ( L_41 , V_204 [ 1 ] ) ;
return - V_197 ;
}
if ( F_160 ( V_204 [ 2 ] , 10 , ( unsigned long long * ) & V_231 ) ) {
F_97 ( L_42 , V_204 [ 2 ] ) ;
return - V_197 ;
}
V_30 = F_182 ( V_61 -> V_129 , V_230 , V_231 ) ;
if ( V_30 ) {
F_97 ( L_43 ,
V_204 [ 1 ] , V_204 [ 2 ] ) ;
return V_30 ;
}
return 0 ;
}
static int F_183 ( struct V_158 * V_132 , unsigned V_200 , char * * V_204 )
{
int V_30 = - V_197 ;
struct V_168 * V_169 = V_132 -> V_161 ;
struct V_61 * V_61 = V_169 -> V_61 ;
if ( ! strcasecmp ( V_204 [ 0 ] , L_44 ) )
V_30 = F_175 ( V_200 , V_204 , V_61 ) ;
else if ( ! strcasecmp ( V_204 [ 0 ] , L_45 ) )
V_30 = F_177 ( V_200 , V_204 , V_61 ) ;
else if ( ! strcasecmp ( V_204 [ 0 ] , L_46 ) )
V_30 = F_179 ( V_200 , V_204 , V_61 ) ;
else if ( ! strcasecmp ( V_204 [ 0 ] , L_47 ) )
V_30 = F_181 ( V_200 , V_204 , V_61 ) ;
else
F_97 ( L_48 , V_204 [ 0 ] ) ;
if ( ! V_30 ) {
V_30 = F_100 ( V_61 -> V_129 ) ;
if ( V_30 )
F_77 ( L_49 ,
V_204 [ 0 ] , V_30 ) ;
}
return V_30 ;
}
static int F_184 ( struct V_158 * V_132 , T_8 type ,
char * V_127 , unsigned V_232 )
{
int V_30 , V_46 ;
unsigned V_233 = 0 ;
T_3 V_234 ;
T_4 V_235 ;
T_4 V_236 ;
T_4 V_237 ;
T_4 V_238 ;
T_4 V_239 ;
char V_175 [ V_176 ] ;
char V_240 [ V_176 ] ;
struct V_168 * V_169 = V_132 -> V_161 ;
struct V_61 * V_61 = V_169 -> V_61 ;
switch ( type ) {
case V_241 :
V_30 = F_185 ( V_61 -> V_129 ,
& V_234 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_186 ( V_61 -> V_129 ,
& V_236 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_187 ( V_61 -> V_129 , & V_238 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_96 ( V_61 -> V_129 ,
& V_235 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_167 ( V_61 -> V_129 , & V_237 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_188 ( V_61 -> V_129 , & V_239 ) ;
if ( V_30 )
return V_30 ;
F_189 ( L_50 ,
( unsigned long long ) V_234 ,
( unsigned long long ) ( V_238 - V_236 ) ,
( unsigned long long ) V_238 ,
( unsigned long long ) ( V_237 - V_235 ) ,
( unsigned long long ) V_237 ) ;
if ( V_239 )
F_189 ( L_51 , V_239 ) ;
else
F_189 ( L_52 ) ;
break;
case V_242 :
F_189 ( L_53 ,
F_190 ( V_175 , V_169 -> V_179 -> V_80 -> V_243 ) ,
F_190 ( V_240 , V_169 -> V_173 -> V_80 -> V_243 ) ,
( unsigned long ) V_61 -> V_108 ,
( unsigned long long ) V_169 -> V_130 ) ;
V_46 = ! V_61 -> V_125 . V_126 + ! V_61 -> V_125 . V_178 +
! V_169 -> V_125 . V_141 ;
F_189 ( L_54 , V_46 ) ;
if ( ! V_61 -> V_125 . V_126 )
F_189 ( L_55 ) ;
if ( ! V_61 -> V_125 . V_178 )
F_189 ( L_56 ) ;
if ( ! V_169 -> V_125 . V_141 )
F_189 ( L_57 ) ;
break;
}
return 0 ;
}
static int F_191 ( struct V_158 * V_132 ,
T_9 F_81 , void * V_244 )
{
struct V_168 * V_169 = V_132 -> V_161 ;
return F_81 ( V_132 , V_169 -> V_173 , 0 , V_132 -> V_6 , V_244 ) ;
}
static int F_192 ( struct V_158 * V_132 , struct V_245 * V_246 ,
struct V_247 * V_248 , int V_249 )
{
struct V_168 * V_169 = V_132 -> V_161 ;
struct V_171 * V_172 = F_123 ( V_169 -> V_173 -> V_80 ) ;
if ( ! V_172 -> V_250 )
return V_249 ;
V_246 -> V_78 = V_169 -> V_173 -> V_80 ;
return F_2 ( V_249 , V_172 -> V_250 ( V_172 , V_246 , V_248 ) ) ;
}
static void F_193 ( struct V_61 * V_61 , struct V_251 * V_252 )
{
V_252 -> V_253 = V_61 -> V_108 ;
V_252 -> V_254 = V_61 -> V_108 << V_109 ;
V_252 -> V_255 = V_61 -> V_125 . V_126 ;
}
static void F_194 ( struct V_158 * V_132 , struct V_251 * V_252 )
{
struct V_168 * V_169 = V_132 -> V_161 ;
struct V_61 * V_61 = V_169 -> V_61 ;
F_195 ( V_252 , 0 ) ;
F_196 ( V_252 , V_61 -> V_108 << V_109 ) ;
if ( V_61 -> V_125 . V_178 )
F_193 ( V_61 , V_252 ) ;
}
static void F_197 ( struct V_158 * V_132 )
{
struct V_67 * V_68 = V_132 -> V_161 ;
F_149 ( & V_58 . V_59 ) ;
F_146 ( V_68 -> V_61 ) ;
F_198 ( V_68 -> V_56 ) ;
F_150 ( V_132 , V_68 -> V_79 ) ;
if ( V_68 -> V_82 )
F_150 ( V_132 , V_68 -> V_82 ) ;
F_7 ( V_68 ) ;
F_151 ( & V_58 . V_59 ) ;
}
static int F_199 ( struct V_158 * V_132 , unsigned V_200 , char * * V_204 )
{
int V_30 ;
struct V_67 * V_68 ;
struct V_115 * V_79 , * V_82 ;
struct V_62 * V_64 ;
F_149 ( & V_58 . V_59 ) ;
if ( V_200 != 2 && V_200 != 3 ) {
V_132 -> error = L_26 ;
V_30 = - V_197 ;
goto V_207;
}
V_68 = V_132 -> V_161 = F_162 ( sizeof( * V_68 ) , V_9 ) ;
if ( ! V_68 ) {
V_132 -> error = L_58 ;
V_30 = - V_114 ;
goto V_207;
}
if ( V_200 == 3 ) {
V_30 = F_156 ( V_132 , V_204 [ 2 ] , V_208 , & V_82 ) ;
if ( V_30 ) {
V_132 -> error = L_59 ;
goto V_256;
}
V_68 -> V_82 = V_82 ;
}
V_30 = F_156 ( V_132 , V_204 [ 0 ] , F_200 ( V_132 -> V_133 ) , & V_79 ) ;
if ( V_30 ) {
V_132 -> error = L_60 ;
goto V_257;
}
V_68 -> V_79 = V_79 ;
if ( F_174 ( V_204 [ 1 ] , ( unsigned long long * ) & V_68 -> V_226 , 0 ) ) {
V_132 -> error = L_61 ;
V_30 = - V_197 ;
goto V_258;
}
V_64 = F_201 ( V_68 -> V_79 -> V_80 -> V_243 ) ;
if ( ! V_64 ) {
V_132 -> error = L_62 ;
V_30 = - V_197 ;
goto V_258;
}
V_68 -> V_61 = F_54 ( V_64 ) ;
if ( ! V_68 -> V_61 ) {
V_132 -> error = L_63 ;
V_30 = - V_197 ;
goto V_259;
}
F_145 ( V_68 -> V_61 ) ;
V_30 = F_202 ( V_68 -> V_61 -> V_129 , V_68 -> V_226 , & V_68 -> V_56 ) ;
if ( V_30 ) {
V_132 -> error = L_64 ;
goto V_260;
}
V_132 -> V_261 = V_68 -> V_61 -> V_108 ;
V_132 -> V_218 = 1 ;
if ( V_68 -> V_61 -> V_125 . V_178 ) {
V_132 -> V_220 = 1 ;
V_132 -> V_219 = 1 ;
}
F_203 ( V_64 ) ;
F_151 ( & V_58 . V_59 ) ;
return 0 ;
V_260:
F_146 ( V_68 -> V_61 ) ;
V_259:
F_203 ( V_64 ) ;
V_258:
F_150 ( V_132 , V_68 -> V_79 ) ;
V_257:
if ( V_68 -> V_82 )
F_150 ( V_132 , V_68 -> V_82 ) ;
V_256:
F_7 ( V_68 ) ;
V_207:
F_151 ( & V_58 . V_59 ) ;
return V_30 ;
}
static int F_204 ( struct V_158 * V_132 , struct V_27 * V_27 ,
union V_159 * V_160 )
{
V_27 -> V_76 = F_205 ( V_132 , V_27 -> V_76 ) ;
return F_120 ( V_132 , V_27 , V_160 ) ;
}
static int F_206 ( struct V_158 * V_132 ,
struct V_27 * V_27 , int V_97 ,
union V_159 * V_160 )
{
unsigned long V_31 ;
struct V_70 * V_71 = V_160 -> V_72 ;
struct V_51 V_53 ;
struct V_89 * V_90 , * V_26 ;
struct V_61 * V_61 = V_71 -> V_68 -> V_61 ;
if ( V_71 -> V_147 ) {
F_37 ( & V_53 ) ;
F_42 ( V_71 -> V_147 , & V_53 ) ;
F_17 ( & V_61 -> V_10 , V_31 ) ;
F_82 (m, tmp, &work, list) {
F_53 ( & V_90 -> V_37 ) ;
V_90 -> V_91 = 1 ;
F_70 ( V_90 ) ;
}
F_19 ( & V_61 -> V_10 , V_31 ) ;
}
if ( V_71 -> V_157 ) {
F_37 ( & V_53 ) ;
F_42 ( V_71 -> V_157 , & V_53 ) ;
F_17 ( & V_61 -> V_10 , V_31 ) ;
F_82 (m, tmp, &work, list)
F_44 ( & V_90 -> V_37 , & V_61 -> V_143 ) ;
F_19 ( & V_61 -> V_10 , V_31 ) ;
}
F_21 ( V_71 , V_61 -> V_156 ) ;
return 0 ;
}
static void F_207 ( struct V_158 * V_132 )
{
if ( F_208 ( V_132 ) )
F_60 ( (struct V_67 * ) V_132 -> V_161 ) ;
}
static int F_209 ( struct V_158 * V_132 , T_8 type ,
char * V_127 , unsigned V_232 )
{
int V_30 ;
T_10 V_233 = 0 ;
T_4 V_262 , V_263 ;
char V_175 [ V_176 ] ;
struct V_67 * V_68 = V_132 -> V_161 ;
if ( ! V_68 -> V_56 )
F_189 ( L_52 ) ;
else {
switch ( type ) {
case V_241 :
V_30 = F_210 ( V_68 -> V_56 , & V_262 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_211 ( V_68 -> V_56 , & V_263 ) ;
if ( V_30 < 0 )
return V_30 ;
F_189 ( L_65 , V_262 * V_68 -> V_61 -> V_108 ) ;
if ( V_30 )
F_189 ( L_51 , ( ( V_263 + 1 ) *
V_68 -> V_61 -> V_108 ) - 1 ) ;
else
F_189 ( L_52 ) ;
break;
case V_242 :
F_189 ( L_66 ,
F_190 ( V_175 , V_68 -> V_79 -> V_80 -> V_243 ) ,
( unsigned long ) V_68 -> V_226 ) ;
if ( V_68 -> V_82 )
F_189 ( L_67 , F_190 ( V_175 , V_68 -> V_82 -> V_80 -> V_243 ) ) ;
break;
}
}
return 0 ;
}
static int F_212 ( struct V_158 * V_132 ,
T_9 F_81 , void * V_244 )
{
T_4 V_264 ;
struct V_67 * V_68 = V_132 -> V_161 ;
if ( ! V_68 -> V_61 -> V_132 )
return 0 ;
V_264 = V_68 -> V_61 -> V_132 -> V_6 >> V_68 -> V_61 -> V_77 ;
if ( V_264 )
return F_81 ( V_132 , V_68 -> V_79 , 0 , V_68 -> V_61 -> V_108 * V_264 , V_244 ) ;
return 0 ;
}
static void F_213 ( struct V_158 * V_132 , struct V_251 * V_252 )
{
struct V_67 * V_68 = V_132 -> V_161 ;
struct V_61 * V_61 = V_68 -> V_61 ;
F_195 ( V_252 , 0 ) ;
F_196 ( V_252 , V_61 -> V_108 << V_109 ) ;
F_193 ( V_61 , V_252 ) ;
}
static int T_11 F_214 ( void )
{
int V_30 ;
F_48 () ;
V_30 = F_215 ( & V_265 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_215 ( & V_266 ) ;
if ( V_30 )
F_216 ( & V_265 ) ;
return V_30 ;
}
static void F_217 ( void )
{
F_216 ( & V_265 ) ;
F_216 ( & V_266 ) ;
}
