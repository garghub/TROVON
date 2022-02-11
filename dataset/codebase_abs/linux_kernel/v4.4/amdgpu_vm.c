static unsigned F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 >> V_5 ;
}
static unsigned F_2 ( struct V_1 * V_2 )
{
return F_3 ( F_1 ( V_2 ) * 8 ) ;
}
struct V_6 * F_4 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_6 * V_11 ;
unsigned V_12 , V_13 ;
V_11 = F_5 ( V_8 -> V_14 + 2 ,
sizeof( struct V_6 ) ) ;
if ( ! V_11 ) {
return NULL ;
}
V_11 [ 0 ] . V_15 = V_8 -> V_16 ;
V_11 [ 0 ] . V_17 = V_18 ;
V_11 [ 0 ] . V_19 = V_18 ;
V_11 [ 0 ] . V_20 = 0 ;
V_11 [ 0 ] . V_21 . V_22 = & V_8 -> V_16 -> V_23 ;
V_11 [ 0 ] . V_21 . V_24 = true ;
F_6 ( & V_11 [ 0 ] . V_21 . V_10 , V_10 ) ;
for ( V_12 = 0 , V_13 = 1 ; V_12 <= V_8 -> V_14 ; V_12 ++ ) {
if ( ! V_8 -> V_25 [ V_12 ] . V_22 )
continue;
V_11 [ V_13 ] . V_15 = V_8 -> V_25 [ V_12 ] . V_22 ;
V_11 [ V_13 ] . V_17 = V_18 ;
V_11 [ V_13 ] . V_19 = V_18 ;
V_11 [ V_13 ] . V_20 = 0 ;
V_11 [ V_13 ] . V_21 . V_22 = & V_11 [ V_13 ] . V_15 -> V_23 ;
V_11 [ V_13 ] . V_21 . V_24 = true ;
F_6 ( & V_11 [ V_13 ++ ] . V_21 . V_10 , V_10 ) ;
}
return V_11 ;
}
int F_7 ( struct V_7 * V_8 , struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_30 * V_31 [ V_32 ] = {} ;
struct V_33 * V_34 = & V_8 -> V_35 [ V_27 -> V_13 ] ;
struct V_1 * V_2 = V_27 -> V_2 ;
unsigned V_36 [ 2 ] = {} ;
unsigned V_12 ;
if ( V_34 -> V_37 ) {
unsigned V_37 = V_34 -> V_37 ;
long V_38 ;
V_38 = F_8 ( & V_2 -> V_3 . V_35 [ V_37 ] . V_38 ) ;
if ( V_38 == ( long ) V_8 ) {
F_9 ( V_34 -> V_37 , V_27 -> V_13 ) ;
return 0 ;
}
}
V_34 -> V_39 = ~ 0ll ;
for ( V_12 = 1 ; V_12 < V_2 -> V_3 . V_40 ; ++ V_12 ) {
struct V_30 * V_30 = V_2 -> V_3 . V_35 [ V_12 ] . V_41 ;
struct V_26 * V_42 ;
if ( V_30 == NULL ) {
V_34 -> V_37 = V_12 ;
F_9 ( V_12 , V_27 -> V_13 ) ;
return 0 ;
}
V_42 = F_10 ( V_30 ) ;
if ( V_31 [ V_42 -> V_13 ] == NULL ||
F_11 ( V_31 [ V_42 -> V_13 ] , V_30 ) ) {
V_31 [ V_42 -> V_13 ] = V_30 ;
V_36 [ V_42 == V_27 ? 0 : 1 ] = V_12 ;
}
}
for ( V_12 = 0 ; V_12 < 2 ; ++ V_12 ) {
if ( V_36 [ V_12 ] ) {
struct V_30 * V_30 ;
V_30 = V_2 -> V_3 . V_35 [ V_36 [ V_12 ] ] . V_41 ;
V_34 -> V_37 = V_36 [ V_12 ] ;
F_9 ( V_36 [ V_12 ] , V_27 -> V_13 ) ;
return F_12 ( V_27 -> V_2 , V_29 , V_30 ) ;
}
}
F_13 () ;
return - V_43 ;
}
void F_14 ( struct V_26 * V_27 ,
struct V_7 * V_8 ,
struct V_30 * V_44 )
{
T_1 V_45 = F_15 ( V_8 -> V_16 ) ;
struct V_33 * V_34 = & V_8 -> V_35 [ V_27 -> V_13 ] ;
struct V_30 * V_46 = V_34 -> V_46 ;
bool V_47 ;
if ( ! V_46 )
V_47 = true ;
else if ( ! V_44 )
V_47 = false ;
else
V_47 = F_11 ( V_44 , V_46 ) ;
if ( V_45 != V_34 -> V_39 || V_47 ) {
F_16 ( V_45 , V_27 -> V_13 , V_34 -> V_37 ) ;
if ( V_47 ) {
V_34 -> V_46 = F_17 ( V_44 ) ;
F_18 ( V_46 ) ;
}
V_34 -> V_39 = V_45 ;
F_19 ( V_27 , V_34 -> V_37 , V_34 -> V_39 ) ;
}
}
void F_20 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_30 * V_30 )
{
struct V_26 * V_27 = F_10 ( V_30 ) ;
unsigned V_34 = V_8 -> V_35 [ V_27 -> V_13 ] . V_37 ;
F_18 ( V_2 -> V_3 . V_35 [ V_34 ] . V_41 ) ;
V_2 -> V_3 . V_35 [ V_34 ] . V_41 = F_17 ( V_30 ) ;
F_21 ( & V_2 -> V_3 . V_35 [ V_34 ] . V_38 , ( long ) V_8 ) ;
}
struct V_48 * F_22 ( struct V_7 * V_8 ,
struct V_49 * V_22 )
{
struct V_48 * V_50 ;
F_23 (bo_va, &bo->va, bo_list) {
if ( V_50 -> V_8 == V_8 ) {
return V_50 ;
}
}
return NULL ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_51 * V_52 ,
T_1 V_53 , T_1 V_54 ,
unsigned V_55 , T_2 V_56 ,
T_2 V_57 , T_2 V_58 )
{
F_25 ( V_53 , V_54 , V_55 , V_56 , V_57 ) ;
if ( ( V_57 & V_59 ) && ( V_57 == V_58 ) ) {
T_1 V_60 = V_2 -> V_61 . V_62 + ( V_54 >> 12 ) * 8 ;
F_26 ( V_2 , V_52 , V_53 , V_60 , V_55 ) ;
} else if ( ( V_57 & V_59 ) || ( V_55 < 3 ) ) {
F_27 ( V_2 , V_52 , V_53 , V_54 ,
V_55 , V_56 , V_57 ) ;
} else {
F_28 ( V_2 , V_52 , V_53 , V_54 ,
V_55 , V_56 , V_57 ) ;
}
}
int F_29 ( struct V_63 * V_64 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_64 -> V_65 ; V_12 ++ )
F_30 ( V_64 -> V_2 , & V_64 -> V_66 [ V_12 ] ) ;
F_31 ( V_64 -> V_66 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_49 * V_22 )
{
struct V_26 * V_27 = V_2 -> V_3 . V_67 ;
struct V_30 * V_30 = NULL ;
struct V_51 * V_52 ;
unsigned V_68 ;
T_1 V_54 ;
int V_69 ;
V_69 = F_33 ( V_22 -> V_23 . V_70 ) ;
if ( V_69 )
return V_69 ;
V_69 = F_34 ( & V_22 -> V_23 , & V_22 -> V_71 , true , false ) ;
if ( V_69 )
goto error;
V_54 = F_15 ( V_22 ) ;
V_68 = F_35 ( V_22 ) / 8 ;
V_52 = F_36 ( sizeof( struct V_51 ) , V_72 ) ;
if ( ! V_52 )
goto error;
V_69 = F_37 ( V_27 , NULL , V_68 * 2 + 64 , V_52 ) ;
if ( V_69 )
goto V_73;
V_52 -> V_74 = 0 ;
F_24 ( V_2 , V_52 , V_54 , 0 , V_68 , 0 , 0 , 0 ) ;
F_38 ( V_2 , V_52 ) ;
F_39 ( V_52 -> V_74 > 64 ) ;
V_69 = F_40 ( V_2 , V_27 , V_52 , 1 ,
& F_29 ,
V_75 ,
& V_30 ) ;
if ( ! V_69 )
F_41 ( V_22 , V_30 , true ) ;
F_18 ( V_30 ) ;
if ( V_76 )
return 0 ;
V_73:
F_30 ( V_2 , V_52 ) ;
F_31 ( V_52 ) ;
error:
return V_69 ;
}
T_1 F_42 ( struct V_1 * V_2 , T_1 V_54 )
{
T_1 V_77 ;
V_77 = V_2 -> V_61 . V_78 [ V_54 >> V_79 ] ;
V_77 |= V_54 & ( ~ V_80 ) ;
return V_77 ;
}
int F_43 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_26 * V_27 = V_2 -> V_3 . V_67 ;
struct V_49 * V_81 = V_8 -> V_16 ;
T_1 V_45 = F_15 ( V_81 ) ;
T_2 V_56 = V_82 * 8 ;
T_1 V_83 = ~ 0 , V_84 = ~ 0 ;
unsigned V_55 = 0 , V_85 , V_86 ;
struct V_51 * V_52 ;
struct V_30 * V_30 = NULL ;
int V_69 ;
V_86 = 64 ;
V_86 += V_8 -> V_14 * 6 ;
if ( V_86 > 0xfffff )
return - V_87 ;
V_52 = F_36 ( sizeof( struct V_51 ) , V_72 ) ;
if ( ! V_52 )
return - V_87 ;
V_69 = F_37 ( V_27 , NULL , V_86 * 4 , V_52 ) ;
if ( V_69 ) {
F_31 ( V_52 ) ;
return V_69 ;
}
V_52 -> V_74 = 0 ;
for ( V_85 = 0 ; V_85 <= V_8 -> V_14 ; ++ V_85 ) {
struct V_49 * V_22 = V_8 -> V_25 [ V_85 ] . V_22 ;
T_1 V_88 , V_89 ;
if ( V_22 == NULL )
continue;
V_89 = F_15 ( V_22 ) ;
if ( V_8 -> V_25 [ V_85 ] . V_54 == V_89 )
continue;
V_8 -> V_25 [ V_85 ] . V_54 = V_89 ;
V_88 = V_45 + V_85 * 8 ;
if ( ( ( V_83 + 8 * V_55 ) != V_88 ) ||
( ( V_84 + V_56 * V_55 ) != V_89 ) ) {
if ( V_55 ) {
F_24 ( V_2 , V_52 , V_83 ,
V_84 , V_55 , V_56 ,
V_90 , 0 ) ;
}
V_55 = 1 ;
V_83 = V_88 ;
V_84 = V_89 ;
} else {
++ V_55 ;
}
}
if ( V_55 )
F_24 ( V_2 , V_52 , V_83 , V_84 , V_55 ,
V_56 , V_90 , 0 ) ;
if ( V_52 -> V_74 != 0 ) {
F_38 ( V_2 , V_52 ) ;
F_44 ( V_2 , & V_52 -> V_29 , V_81 -> V_23 . V_70 , V_75 ) ;
F_39 ( V_52 -> V_74 > V_86 ) ;
V_69 = F_40 ( V_2 , V_27 , V_52 , 1 ,
& F_29 ,
V_75 ,
& V_30 ) ;
if ( V_69 )
goto V_73;
F_41 ( V_81 , V_30 , true ) ;
F_18 ( V_8 -> V_91 ) ;
V_8 -> V_91 = F_17 ( V_30 ) ;
F_18 ( V_30 ) ;
}
if ( ! V_76 || V_52 -> V_74 == 0 ) {
F_30 ( V_2 , V_52 ) ;
F_31 ( V_52 ) ;
}
return 0 ;
V_73:
F_30 ( V_2 , V_52 ) ;
F_31 ( V_52 ) ;
return V_69 ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_51 * V_52 ,
T_1 V_92 , T_1 V_93 ,
T_1 V_54 , T_2 V_57 ,
T_2 V_58 )
{
T_1 V_94 = V_95 ;
T_1 V_96 = 0x80 ;
T_1 V_97 = F_46 ( V_92 , V_96 ) ;
T_1 V_98 = V_93 & ~ ( V_96 - 1 ) ;
unsigned V_55 ;
if ( ( V_57 & V_59 ) || ! ( V_57 & V_90 ) ||
( V_97 >= V_98 ) ) {
V_55 = ( V_93 - V_92 ) / 8 ;
F_24 ( V_2 , V_52 , V_92 , V_54 , V_55 ,
V_99 , V_57 , V_58 ) ;
return;
}
if ( V_92 != V_97 ) {
V_55 = ( V_97 - V_92 ) / 8 ;
F_24 ( V_2 , V_52 , V_92 , V_54 , V_55 ,
V_99 , V_57 , V_58 ) ;
V_54 += V_99 * V_55 ;
}
V_55 = ( V_98 - V_97 ) / 8 ;
F_24 ( V_2 , V_52 , V_97 , V_54 , V_55 ,
V_99 , V_57 | V_94 ,
V_58 ) ;
if ( V_98 != V_93 ) {
V_54 += V_99 * V_55 ;
V_55 = ( V_93 - V_98 ) / 8 ;
F_24 ( V_2 , V_52 , V_98 , V_54 , V_55 ,
V_99 , V_57 , V_58 ) ;
}
}
static int F_47 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_51 * V_52 ,
T_1 V_100 , T_1 V_101 ,
T_1 V_102 , T_2 V_57 ,
T_2 V_58 )
{
T_1 V_103 = V_82 - 1 ;
T_1 V_104 = ~ 0 , V_105 = ~ 0 ;
void * V_38 = V_75 ;
unsigned V_55 = 0 ;
T_1 V_54 ;
if ( ! ( V_57 & V_90 ) )
V_38 = V_106 ;
for ( V_54 = V_100 ; V_54 < V_101 ; ) {
T_1 V_85 = V_54 >> V_5 ;
struct V_49 * V_89 = V_8 -> V_25 [ V_85 ] . V_22 ;
unsigned V_107 ;
T_1 V_108 ;
int V_69 ;
F_44 ( V_2 , & V_52 -> V_29 , V_89 -> V_23 . V_70 , V_38 ) ;
V_69 = F_33 ( V_89 -> V_23 . V_70 ) ;
if ( V_69 )
return V_69 ;
if ( ( V_54 & ~ V_103 ) == ( V_101 & ~ V_103 ) )
V_107 = V_101 - V_54 ;
else
V_107 = V_82 - ( V_54 & V_103 ) ;
V_108 = F_15 ( V_89 ) ;
V_108 += ( V_54 & V_103 ) * 8 ;
if ( ( V_104 + 8 * V_55 ) != V_108 ) {
if ( V_55 ) {
F_45 ( V_2 , V_52 , V_104 ,
V_104 + 8 * V_55 ,
V_105 , V_57 ,
V_58 ) ;
}
V_55 = V_107 ;
V_104 = V_108 ;
V_105 = V_102 ;
} else {
V_55 += V_107 ;
}
V_54 += V_107 ;
V_102 += V_107 * V_99 ;
}
if ( V_55 ) {
F_45 ( V_2 , V_52 , V_104 ,
V_104 + 8 * V_55 ,
V_105 , V_57 , V_58 ) ;
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_109 * V_110 ,
T_1 V_54 , T_2 V_58 ,
struct V_30 * * V_30 )
{
struct V_26 * V_27 = V_2 -> V_3 . V_67 ;
unsigned V_107 , V_111 , V_86 ;
T_2 V_57 = V_58 ;
struct V_51 * V_52 ;
struct V_30 * V_112 = NULL ;
int V_69 ;
if ( ! ( V_110 -> V_57 & V_113 ) )
V_57 &= ~ V_113 ;
if ( ! ( V_110 -> V_57 & V_114 ) )
V_57 &= ~ V_114 ;
F_49 ( V_110 ) ;
V_107 = V_110 -> V_115 . V_116 - V_110 -> V_115 . V_100 + 1 ;
V_111 = ( V_107 >> F_50 ( V_5 , 11 ) ) + 1 ;
V_86 = 64 ;
if ( ( V_57 & V_59 ) && ( V_57 == V_58 ) ) {
V_86 += V_111 * 7 ;
} else if ( V_57 & V_59 ) {
V_86 += V_111 * 4 ;
V_86 += V_107 * 2 ;
} else {
V_86 += V_111 * 10 ;
V_86 += 2 * 10 ;
}
if ( V_86 > 0xfffff )
return - V_87 ;
V_52 = F_36 ( sizeof( struct V_51 ) , V_72 ) ;
if ( ! V_52 )
return - V_87 ;
V_69 = F_37 ( V_27 , NULL , V_86 * 4 , V_52 ) ;
if ( V_69 ) {
F_31 ( V_52 ) ;
return V_69 ;
}
V_52 -> V_74 = 0 ;
V_69 = F_47 ( V_2 , V_8 , V_52 , V_110 -> V_115 . V_100 ,
V_110 -> V_115 . V_116 + 1 , V_54 + V_110 -> V_117 ,
V_57 , V_58 ) ;
if ( V_69 ) {
F_30 ( V_2 , V_52 ) ;
F_31 ( V_52 ) ;
return V_69 ;
}
F_38 ( V_2 , V_52 ) ;
F_39 ( V_52 -> V_74 > V_86 ) ;
V_69 = F_40 ( V_2 , V_27 , V_52 , 1 ,
& F_29 ,
V_75 ,
& V_112 ) ;
if ( V_69 )
goto V_73;
F_41 ( V_8 -> V_16 , V_112 , true ) ;
if ( V_30 ) {
F_18 ( * V_30 ) ;
* V_30 = F_17 ( V_112 ) ;
}
F_18 ( V_112 ) ;
if ( ! V_76 ) {
F_30 ( V_2 , V_52 ) ;
F_31 ( V_52 ) ;
}
return 0 ;
V_73:
F_30 ( V_2 , V_52 ) ;
F_31 ( V_52 ) ;
return V_69 ;
}
int F_51 ( struct V_1 * V_2 ,
struct V_48 * V_50 ,
struct V_118 * V_119 )
{
struct V_7 * V_8 = V_50 -> V_8 ;
struct V_109 * V_110 ;
T_2 V_57 ;
T_1 V_54 ;
int V_69 ;
if ( V_119 ) {
V_54 = ( V_120 ) V_119 -> V_100 << V_79 ;
if ( V_119 -> V_121 != V_122 )
V_54 += V_2 -> V_3 . V_123 ;
} else {
V_54 = 0 ;
}
V_57 = F_52 ( V_2 , V_50 -> V_22 -> V_23 . V_124 , V_119 ) ;
F_53 ( & V_8 -> V_125 ) ;
if ( ! F_54 ( & V_50 -> V_126 ) )
F_55 ( & V_50 -> V_127 , & V_50 -> V_128 ) ;
F_56 ( & V_8 -> V_125 ) ;
F_23 (mapping, &bo_va->invalids, list) {
V_69 = F_48 ( V_2 , V_8 , V_110 , V_54 ,
V_57 , & V_50 -> V_129 ) ;
if ( V_69 )
return V_69 ;
}
if ( F_57 () ) {
F_23 (mapping, &bo_va->valids, list)
F_58 ( V_110 ) ;
F_23 (mapping, &bo_va->invalids, list)
F_58 ( V_110 ) ;
}
F_53 ( & V_8 -> V_125 ) ;
F_55 ( & V_50 -> V_128 , & V_50 -> V_127 ) ;
F_59 ( & V_50 -> V_126 ) ;
if ( ! V_119 )
F_6 ( & V_50 -> V_126 , & V_8 -> V_130 ) ;
F_56 ( & V_8 -> V_125 ) ;
return 0 ;
}
int F_60 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_109 * V_110 ;
int V_69 ;
F_53 ( & V_8 -> V_131 ) ;
while ( ! F_54 ( & V_8 -> V_132 ) ) {
V_110 = F_61 ( & V_8 -> V_132 ,
struct V_109 , V_11 ) ;
F_62 ( & V_110 -> V_11 ) ;
F_56 ( & V_8 -> V_131 ) ;
V_69 = F_48 ( V_2 , V_8 , V_110 , 0 , 0 , NULL ) ;
F_31 ( V_110 ) ;
if ( V_69 )
return V_69 ;
F_53 ( & V_8 -> V_131 ) ;
}
F_56 ( & V_8 -> V_131 ) ;
return 0 ;
}
int F_63 ( struct V_1 * V_2 ,
struct V_7 * V_8 , struct V_28 * V_29 )
{
struct V_48 * V_50 = NULL ;
int V_69 = 0 ;
F_53 ( & V_8 -> V_125 ) ;
while ( ! F_54 ( & V_8 -> V_133 ) ) {
V_50 = F_61 ( & V_8 -> V_133 ,
struct V_48 , V_126 ) ;
F_56 ( & V_8 -> V_125 ) ;
F_64 ( & V_50 -> V_134 ) ;
V_69 = F_51 ( V_2 , V_50 , NULL ) ;
F_65 ( & V_50 -> V_134 ) ;
if ( V_69 )
return V_69 ;
F_53 ( & V_8 -> V_125 ) ;
}
F_56 ( & V_8 -> V_125 ) ;
if ( V_50 )
V_69 = F_12 ( V_2 , V_29 , V_50 -> V_129 ) ;
return V_69 ;
}
struct V_48 * F_66 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_49 * V_22 )
{
struct V_48 * V_50 ;
V_50 = F_36 ( sizeof( struct V_48 ) , V_72 ) ;
if ( V_50 == NULL ) {
return NULL ;
}
V_50 -> V_8 = V_8 ;
V_50 -> V_22 = V_22 ;
V_50 -> V_135 = 1 ;
F_67 ( & V_50 -> V_136 ) ;
F_67 ( & V_50 -> V_127 ) ;
F_67 ( & V_50 -> V_128 ) ;
F_67 ( & V_50 -> V_126 ) ;
F_68 ( & V_50 -> V_134 ) ;
F_69 ( & V_50 -> V_136 , & V_22 -> V_137 ) ;
return V_50 ;
}
int F_70 ( struct V_1 * V_2 ,
struct V_48 * V_50 ,
T_1 V_138 , T_1 V_117 ,
T_1 V_139 , T_2 V_57 )
{
struct V_109 * V_110 ;
struct V_7 * V_8 = V_50 -> V_8 ;
struct V_140 * V_115 ;
unsigned V_141 , V_85 ;
T_1 V_142 ;
int V_69 ;
if ( V_138 & V_143 || V_117 & V_143 ||
V_139 == 0 || V_139 & V_143 )
return - V_43 ;
V_142 = V_138 + V_139 ;
if ( ( V_138 >= V_142 ) || ( V_117 + V_139 > F_35 ( V_50 -> V_22 ) ) )
return - V_43 ;
V_141 = V_142 / V_99 ;
if ( V_141 > V_2 -> V_3 . V_4 ) {
F_71 ( V_2 -> V_144 , L_1 ,
V_141 , V_2 -> V_3 . V_4 ) ;
return - V_43 ;
}
V_138 /= V_99 ;
V_142 /= V_99 ;
F_53 ( & V_8 -> V_145 ) ;
V_115 = F_72 ( & V_8 -> V_137 , V_138 , V_142 - 1 ) ;
F_56 ( & V_8 -> V_145 ) ;
if ( V_115 ) {
struct V_109 * V_146 ;
V_146 = F_73 ( V_115 , struct V_109 , V_115 ) ;
F_71 ( V_2 -> V_144 , L_2
L_3 , V_50 -> V_22 , V_138 , V_142 ,
V_146 -> V_115 . V_100 , V_146 -> V_115 . V_116 + 1 ) ;
V_69 = - V_43 ;
goto error;
}
V_110 = F_74 ( sizeof( * V_110 ) , V_72 ) ;
if ( ! V_110 ) {
V_69 = - V_87 ;
goto error;
}
F_67 ( & V_110 -> V_11 ) ;
V_110 -> V_115 . V_100 = V_138 ;
V_110 -> V_115 . V_116 = V_142 - 1 ;
V_110 -> V_117 = V_117 ;
V_110 -> V_57 = V_57 ;
F_64 ( & V_50 -> V_134 ) ;
F_6 ( & V_110 -> V_11 , & V_50 -> V_128 ) ;
F_65 ( & V_50 -> V_134 ) ;
F_53 ( & V_8 -> V_145 ) ;
F_75 ( & V_110 -> V_115 , & V_8 -> V_137 ) ;
F_56 ( & V_8 -> V_145 ) ;
F_76 ( V_50 , V_110 ) ;
V_138 >>= V_5 ;
V_142 >>= V_5 ;
F_77 ( V_142 >= F_1 ( V_2 ) ) ;
if ( V_142 > V_8 -> V_14 )
V_8 -> V_14 = V_142 ;
for ( V_85 = V_138 ; V_85 <= V_142 ; ++ V_85 ) {
struct V_147 * V_70 = V_8 -> V_16 -> V_23 . V_70 ;
struct V_49 * V_89 ;
if ( V_8 -> V_25 [ V_85 ] . V_22 )
continue;
V_69 = F_78 ( V_2 , V_82 * 8 ,
V_99 , true ,
V_18 ,
V_148 ,
NULL , V_70 , & V_89 ) ;
if ( V_69 )
goto V_73;
V_89 -> V_149 = F_79 ( V_8 -> V_16 ) ;
V_69 = F_32 ( V_2 , V_89 ) ;
if ( V_69 ) {
F_80 ( & V_89 ) ;
goto V_73;
}
V_8 -> V_25 [ V_85 ] . V_54 = 0 ;
V_8 -> V_25 [ V_85 ] . V_22 = V_89 ;
}
return 0 ;
V_73:
F_62 ( & V_110 -> V_11 ) ;
F_53 ( & V_8 -> V_145 ) ;
F_81 ( & V_110 -> V_115 , & V_8 -> V_137 ) ;
F_56 ( & V_8 -> V_145 ) ;
F_82 ( V_50 , V_110 ) ;
F_31 ( V_110 ) ;
error:
return V_69 ;
}
int F_83 ( struct V_1 * V_2 ,
struct V_48 * V_50 ,
T_1 V_138 )
{
struct V_109 * V_110 ;
struct V_7 * V_8 = V_50 -> V_8 ;
bool V_150 = true ;
V_138 /= V_99 ;
F_64 ( & V_50 -> V_134 ) ;
F_23 (mapping, &bo_va->valids, list) {
if ( V_110 -> V_115 . V_100 == V_138 )
break;
}
if ( & V_110 -> V_11 == & V_50 -> V_127 ) {
V_150 = false ;
F_23 (mapping, &bo_va->invalids, list) {
if ( V_110 -> V_115 . V_100 == V_138 )
break;
}
if ( & V_110 -> V_11 == & V_50 -> V_128 ) {
F_65 ( & V_50 -> V_134 ) ;
return - V_151 ;
}
}
F_65 ( & V_50 -> V_134 ) ;
F_62 ( & V_110 -> V_11 ) ;
F_53 ( & V_8 -> V_145 ) ;
F_81 ( & V_110 -> V_115 , & V_8 -> V_137 ) ;
F_56 ( & V_8 -> V_145 ) ;
F_82 ( V_50 , V_110 ) ;
if ( V_150 ) {
F_53 ( & V_8 -> V_131 ) ;
F_6 ( & V_110 -> V_11 , & V_8 -> V_132 ) ;
F_56 ( & V_8 -> V_131 ) ;
} else {
F_31 ( V_110 ) ;
}
return 0 ;
}
void F_84 ( struct V_1 * V_2 ,
struct V_48 * V_50 )
{
struct V_109 * V_110 , * V_152 ;
struct V_7 * V_8 = V_50 -> V_8 ;
F_62 ( & V_50 -> V_136 ) ;
F_53 ( & V_8 -> V_125 ) ;
F_62 ( & V_50 -> V_126 ) ;
F_56 ( & V_8 -> V_125 ) ;
F_85 (mapping, next, &bo_va->valids, list) {
F_62 ( & V_110 -> V_11 ) ;
F_53 ( & V_8 -> V_145 ) ;
F_81 ( & V_110 -> V_115 , & V_8 -> V_137 ) ;
F_56 ( & V_8 -> V_145 ) ;
F_82 ( V_50 , V_110 ) ;
F_53 ( & V_8 -> V_131 ) ;
F_6 ( & V_110 -> V_11 , & V_8 -> V_132 ) ;
F_56 ( & V_8 -> V_131 ) ;
}
F_85 (mapping, next, &bo_va->invalids, list) {
F_62 ( & V_110 -> V_11 ) ;
F_53 ( & V_8 -> V_145 ) ;
F_81 ( & V_110 -> V_115 , & V_8 -> V_137 ) ;
F_56 ( & V_8 -> V_145 ) ;
F_31 ( V_110 ) ;
}
F_18 ( V_50 -> V_129 ) ;
F_86 ( & V_50 -> V_134 ) ;
F_31 ( V_50 ) ;
}
void F_87 ( struct V_1 * V_2 ,
struct V_49 * V_22 )
{
struct V_48 * V_50 ;
F_23 (bo_va, &bo->va, bo_list) {
F_53 ( & V_50 -> V_8 -> V_125 ) ;
if ( F_54 ( & V_50 -> V_126 ) )
F_6 ( & V_50 -> V_126 , & V_50 -> V_8 -> V_133 ) ;
F_56 ( & V_50 -> V_8 -> V_125 ) ;
}
}
int F_88 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
const unsigned V_153 = F_50 ( V_154 ,
V_82 * 8 ) ;
unsigned V_155 , V_156 , V_157 ;
int V_12 , V_69 ;
for ( V_12 = 0 ; V_12 < V_32 ; ++ V_12 ) {
V_8 -> V_35 [ V_12 ] . V_37 = 0 ;
V_8 -> V_35 [ V_12 ] . V_46 = NULL ;
}
V_8 -> V_137 = V_158 ;
F_89 ( & V_8 -> V_125 ) ;
F_67 ( & V_8 -> V_133 ) ;
F_67 ( & V_8 -> V_130 ) ;
F_67 ( & V_8 -> V_132 ) ;
F_89 ( & V_8 -> V_145 ) ;
F_89 ( & V_8 -> V_131 ) ;
V_155 = F_2 ( V_2 ) ;
V_156 = F_1 ( V_2 ) ;
V_157 = V_156 * sizeof( struct V_159 ) ;
V_8 -> V_25 = F_36 ( V_157 , V_72 ) ;
if ( V_8 -> V_25 == NULL ) {
F_90 ( L_4 ) ;
return - V_87 ;
}
V_8 -> V_91 = NULL ;
V_69 = F_78 ( V_2 , V_155 , V_153 , true ,
V_18 ,
V_148 ,
NULL , NULL , & V_8 -> V_16 ) ;
if ( V_69 )
return V_69 ;
V_69 = F_91 ( V_8 -> V_16 , false ) ;
if ( V_69 ) {
F_80 ( & V_8 -> V_16 ) ;
V_8 -> V_16 = NULL ;
return V_69 ;
}
V_69 = F_32 ( V_2 , V_8 -> V_16 ) ;
F_92 ( V_8 -> V_16 ) ;
if ( V_69 ) {
F_80 ( & V_8 -> V_16 ) ;
V_8 -> V_16 = NULL ;
return V_69 ;
}
return 0 ;
}
void F_93 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_109 * V_110 , * V_146 ;
int V_12 ;
if ( ! F_94 ( & V_8 -> V_137 ) ) {
F_71 ( V_2 -> V_144 , L_5 ) ;
}
F_95 (mapping, tmp, &vm->va, it.rb) {
F_62 ( & V_110 -> V_11 ) ;
F_81 ( & V_110 -> V_115 , & V_8 -> V_137 ) ;
F_31 ( V_110 ) ;
}
F_85 (mapping, tmp, &vm->freed, list) {
F_62 ( & V_110 -> V_11 ) ;
F_31 ( V_110 ) ;
}
for ( V_12 = 0 ; V_12 < F_1 ( V_2 ) ; V_12 ++ )
F_80 ( & V_8 -> V_25 [ V_12 ] . V_22 ) ;
F_31 ( V_8 -> V_25 ) ;
F_80 ( & V_8 -> V_16 ) ;
F_18 ( V_8 -> V_91 ) ;
for ( V_12 = 0 ; V_12 < V_32 ; ++ V_12 ) {
unsigned V_37 = V_8 -> V_35 [ V_12 ] . V_37 ;
F_96 ( & V_2 -> V_3 . V_35 [ V_37 ] . V_38 ,
( long ) V_8 , 0 ) ;
F_18 ( V_8 -> V_35 [ V_12 ] . V_46 ) ;
}
}
void F_97 ( struct V_1 * V_2 )
{
unsigned V_12 ;
for ( V_12 = 0 ; V_12 < V_160 ; ++ V_12 )
F_18 ( V_2 -> V_3 . V_35 [ V_12 ] . V_41 ) ;
}
