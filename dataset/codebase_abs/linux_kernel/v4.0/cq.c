static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_11 ;
struct V_12 V_13 ;
struct V_14 * V_15 ;
int V_16 ;
V_11 = sizeof *V_8 + sizeof *V_10 ;
V_15 = F_2 ( V_11 , V_17 ) ;
if ( ! V_15 )
return - V_18 ;
F_3 ( V_15 , V_19 , 0 ) ;
V_8 = (struct V_7 * ) F_4 ( V_15 , V_11 ) ;
memset ( V_8 , 0 , V_11 ) ;
V_8 -> V_20 = F_5 (
F_6 ( V_21 ) |
F_7 ( 1 ) |
V_22 ) ;
V_8 -> V_23 = F_5 ( F_8 ( V_11 , 16 ) ) ;
V_8 -> V_24 = ( unsigned long ) & V_13 ;
V_10 = V_8 -> V_10 ;
V_10 -> V_25 . V_4 . V_26 = V_27 ;
V_10 -> V_25 . V_4 . V_28 = V_29 ;
V_10 -> V_25 . V_4 . V_30 = F_5 ( V_4 -> V_31 ) ;
F_9 ( & V_13 ) ;
V_16 = F_10 ( V_2 , V_15 ) ;
if ( ! V_16 ) {
V_16 = F_11 ( V_2 , & V_13 , 0 , 0 , V_32 ) ;
}
F_12 ( V_4 -> V_33 ) ;
F_13 ( & ( V_2 -> V_34 . V_35 -> V_36 ) ,
V_4 -> V_37 , V_4 -> V_38 ,
F_14 ( V_4 , V_39 ) ) ;
F_15 ( V_2 , V_4 -> V_31 , V_6 ) ;
return V_16 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_11 ;
int V_40 = ( V_6 != & V_2 -> V_6 ) ;
struct V_12 V_13 ;
int V_16 ;
struct V_14 * V_15 ;
V_4 -> V_31 = F_17 ( V_2 , V_6 ) ;
if ( ! V_4 -> V_31 ) {
V_16 = - V_18 ;
goto V_41;
}
if ( ! V_40 ) {
V_4 -> V_33 = F_18 ( V_4 -> V_37 , V_17 ) ;
if ( ! V_4 -> V_33 ) {
V_16 = - V_18 ;
goto V_42;
}
}
V_4 -> V_38 = F_19 ( & V_2 -> V_34 . V_35 -> V_36 , V_4 -> V_37 ,
& V_4 -> V_43 , V_17 ) ;
if ( ! V_4 -> V_38 ) {
V_16 = - V_18 ;
goto V_44;
}
F_20 ( V_4 , V_39 , V_4 -> V_43 ) ;
memset ( V_4 -> V_38 , 0 , V_4 -> V_37 ) ;
V_11 = sizeof *V_8 + sizeof *V_10 ;
V_15 = F_2 ( V_11 , V_17 ) ;
if ( ! V_15 ) {
V_16 = - V_18 ;
goto V_45;
}
F_3 ( V_15 , V_19 , 0 ) ;
V_8 = (struct V_7 * ) F_4 ( V_15 , V_11 ) ;
memset ( V_8 , 0 , V_11 ) ;
V_8 -> V_20 = F_5 (
F_6 ( V_21 ) |
F_7 ( 1 ) |
V_22 ) ;
V_8 -> V_23 = F_5 ( F_8 ( V_11 , 16 ) ) ;
V_8 -> V_24 = ( unsigned long ) & V_13 ;
V_10 = V_8 -> V_10 ;
V_10 -> V_25 . V_4 . V_26 = V_27 ;
V_10 -> V_25 . V_4 . V_28 = V_46 ;
V_10 -> V_25 . V_4 . V_30 = F_5 ( V_4 -> V_31 ) ;
V_10 -> V_25 . V_4 . V_47 = F_5 (
F_21 ( 0 ) |
F_22 ( 1 ) |
V_48 |
F_23 (
V_2 -> V_34 . V_49 [ V_4 -> V_50 ] ) ) ;
V_10 -> V_25 . V_4 . V_51 = F_24 (
V_52 |
F_25 ( 2 ) |
F_26 ( 0 ) |
V_53 |
F_27 ( 1 ) ) ;
V_10 -> V_25 . V_4 . V_54 = F_24 ( V_4 -> V_55 ) ;
V_10 -> V_25 . V_4 . V_56 = F_28 ( V_4 -> V_43 ) ;
F_9 ( & V_13 ) ;
V_16 = F_10 ( V_2 , V_15 ) ;
if ( V_16 )
goto V_45;
F_29 ( L_1 , V_32 , & V_13 ) ;
V_16 = F_11 ( V_2 , & V_13 , 0 , 0 , V_32 ) ;
if ( V_16 )
goto V_45;
V_4 -> V_57 = 1 ;
V_4 -> V_58 = V_2 -> V_34 . V_59 ;
V_4 -> V_2 = V_2 ;
if ( V_40 ) {
V_4 -> V_60 = ( V_61 ) F_30 ( V_2 -> V_34 . V_35 , 2 ) +
( V_4 -> V_31 << V_2 -> V_62 ) ;
V_4 -> V_60 &= V_63 ;
}
return 0 ;
V_45:
F_13 ( & V_2 -> V_34 . V_35 -> V_36 , V_4 -> V_37 , V_4 -> V_38 ,
F_14 ( V_4 , V_39 ) ) ;
V_44:
F_12 ( V_4 -> V_33 ) ;
V_42:
F_15 ( V_2 , V_4 -> V_31 , V_6 ) ;
V_41:
return V_16 ;
}
static void F_31 ( struct V_64 * V_65 , struct V_3 * V_4 )
{
struct V_66 V_67 ;
F_29 ( L_2 , V_32 ,
V_65 , V_4 , V_4 -> V_68 , V_4 -> V_69 ) ;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
V_67 . V_70 = F_5 ( F_32 ( V_71 ) |
F_33 ( V_72 ) |
F_34 ( 0 ) |
F_35 ( 1 ) |
F_36 ( V_65 -> V_73 . V_74 ) ) ;
V_67 . V_75 = F_28 ( F_37 ( ( V_61 ) V_4 -> V_57 ) ) ;
V_4 -> V_33 [ V_4 -> V_69 ] = V_67 ;
F_38 ( V_4 ) ;
}
int F_39 ( struct V_64 * V_65 , struct V_3 * V_4 , int V_76 )
{
int V_77 = 0 ;
int V_78 = V_65 -> V_79 . V_78 - V_76 ;
F_40 ( V_78 < 0 ) ;
F_29 ( L_3 , V_32 ,
V_65 , V_4 , V_65 -> V_79 . V_78 , V_76 ) ;
while ( V_78 -- ) {
F_31 ( V_65 , V_4 ) ;
V_77 ++ ;
}
return V_77 ;
}
static void F_41 ( struct V_64 * V_65 , struct V_3 * V_4 ,
struct V_80 * V_81 )
{
struct V_66 V_67 ;
F_29 ( L_2 , V_32 ,
V_65 , V_4 , V_4 -> V_68 , V_4 -> V_69 ) ;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
V_67 . V_70 = F_5 ( F_32 ( V_71 ) |
F_33 ( V_81 -> V_82 ) |
F_34 ( 1 ) |
F_35 ( 1 ) |
F_36 ( V_65 -> V_73 . V_74 ) ) ;
F_42 ( & V_67 ) = V_81 -> V_83 ;
V_67 . V_75 = F_28 ( F_37 ( ( V_61 ) V_4 -> V_57 ) ) ;
V_4 -> V_33 [ V_4 -> V_69 ] = V_67 ;
F_38 ( V_4 ) ;
}
int F_43 ( struct V_84 * V_85 )
{
int V_77 = 0 ;
struct V_64 * V_65 = & V_85 -> V_65 ;
struct V_86 * V_87 = F_44 ( V_85 -> V_88 . V_89 ) ;
struct V_3 * V_4 = & V_87 -> V_4 ;
int V_83 ;
struct V_80 * V_90 ;
if ( V_65 -> V_73 . V_91 == - 1 )
V_65 -> V_73 . V_91 = V_65 -> V_73 . V_92 ;
V_83 = V_65 -> V_73 . V_91 ;
F_40 ( V_83 >= V_65 -> V_73 . V_55 ) ;
while ( V_83 != V_65 -> V_73 . V_93 ) {
V_90 = & V_65 -> V_73 . V_94 [ V_83 ] ;
F_40 ( V_90 -> V_77 ) ;
V_90 -> V_77 = 1 ;
F_41 ( V_65 , V_4 , V_90 ) ;
if ( V_65 -> V_73 . V_95 == V_90 ) {
F_40 ( V_90 -> V_82 != V_96 ) ;
F_45 ( V_65 ) ;
}
V_77 ++ ;
if ( ++ V_83 == V_65 -> V_73 . V_55 )
V_83 = 0 ;
}
V_65 -> V_73 . V_91 += V_77 ;
if ( V_65 -> V_73 . V_91 >= V_65 -> V_73 . V_55 )
V_65 -> V_73 . V_91 -= V_65 -> V_73 . V_55 ;
return V_77 ;
}
static void F_46 ( struct V_64 * V_65 , struct V_3 * V_4 )
{
struct V_80 * V_90 ;
int V_92 ;
if ( V_65 -> V_73 . V_91 == - 1 )
V_65 -> V_73 . V_91 = V_65 -> V_73 . V_92 ;
V_92 = V_65 -> V_73 . V_91 ;
F_40 ( V_92 > V_65 -> V_73 . V_55 ) ;
while ( V_92 != V_65 -> V_73 . V_93 ) {
V_90 = & V_65 -> V_73 . V_94 [ V_92 ] ;
if ( ! V_90 -> V_97 ) {
if ( ++ V_92 == V_65 -> V_73 . V_55 )
V_92 = 0 ;
} else if ( V_90 -> V_98 ) {
F_40 ( V_90 -> V_77 ) ;
F_29 ( L_4 ,
V_32 , V_92 , V_4 -> V_69 ) ;
V_90 -> V_67 . V_70 |= F_47 ( F_35 ( 1 ) ) ;
V_4 -> V_33 [ V_4 -> V_69 ] = V_90 -> V_67 ;
F_38 ( V_4 ) ;
V_90 -> V_77 = 1 ;
if ( ++ V_92 == V_65 -> V_73 . V_55 )
V_92 = 0 ;
V_65 -> V_73 . V_91 = V_92 ;
} else
break;
}
}
static void F_48 ( struct V_64 * V_65 , struct V_66 * V_99 ,
struct V_66 * V_100 )
{
V_100 -> V_25 . V_101 . V_92 = V_65 -> V_73 . V_95 -> V_83 ;
V_100 -> V_102 = F_47 ( V_65 -> V_73 . V_95 -> V_103 ) ;
V_100 -> V_70 = F_47 ( F_36 ( F_49 ( V_99 ) ) |
F_35 ( F_50 ( V_99 ) ) |
F_33 ( V_96 ) |
F_34 ( 1 ) ) ;
V_100 -> V_75 = V_99 -> V_75 ;
}
static void F_45 ( struct V_64 * V_65 )
{
T_1 V_104 = V_65 -> V_73 . V_95 - V_65 -> V_73 . V_94 + 1 ;
if ( V_104 == V_65 -> V_73 . V_55 )
V_104 = 0 ;
while ( V_104 != V_65 -> V_73 . V_93 ) {
V_65 -> V_73 . V_95 = & V_65 -> V_73 . V_94 [ V_104 ] ;
if ( V_65 -> V_73 . V_95 -> V_82 == V_96 )
return;
if ( ++ V_104 == V_65 -> V_73 . V_55 )
V_104 = 0 ;
}
V_65 -> V_73 . V_95 = NULL ;
}
void F_51 ( struct V_86 * V_87 )
{
struct V_66 * V_99 , * V_81 , V_100 ;
struct V_84 * V_85 ;
struct V_80 * V_90 ;
int V_16 ;
F_29 ( L_5 , V_32 , V_87 -> V_4 . V_31 ) ;
V_16 = F_52 ( & V_87 -> V_4 , & V_99 ) ;
while ( ! V_16 ) {
V_85 = F_53 ( V_87 -> V_105 , F_49 ( V_99 ) ) ;
if ( V_85 == NULL )
goto V_106;
if ( F_54 ( V_99 ) == V_107 )
goto V_106;
if ( F_54 ( V_99 ) == V_108 ) {
if ( F_55 ( V_99 ) == 1 )
goto V_106;
if ( F_56 ( V_99 ) == 1 )
goto V_106;
if ( ! V_85 -> V_65 . V_73 . V_95 -> V_97 ) {
F_45 ( & V_85 -> V_65 ) ;
goto V_106;
}
F_48 ( & V_85 -> V_65 , V_99 , & V_100 ) ;
V_99 = & V_100 ;
F_45 ( & V_85 -> V_65 ) ;
}
if ( F_57 ( V_99 ) ) {
V_90 = & V_85 -> V_65 . V_73 . V_94 [ F_42 ( V_99 ) ] ;
V_90 -> V_67 = * V_99 ;
V_90 -> V_98 = 1 ;
F_46 ( & V_85 -> V_65 , & V_87 -> V_4 ) ;
} else {
V_81 = & V_87 -> V_4 . V_33 [ V_87 -> V_4 . V_69 ] ;
* V_81 = * V_99 ;
V_81 -> V_70 |= F_5 ( F_35 ( 1 ) ) ;
F_38 ( & V_87 -> V_4 ) ;
}
V_106:
F_58 ( & V_87 -> V_4 ) ;
V_16 = F_52 ( & V_87 -> V_4 , & V_99 ) ;
}
}
static int F_59 ( struct V_66 * V_67 , struct V_64 * V_65 )
{
if ( F_54 ( V_67 ) == V_107 )
return 0 ;
if ( ( F_54 ( V_67 ) == V_109 ) && F_60 ( V_67 ) )
return 0 ;
if ( ( F_54 ( V_67 ) == V_108 ) && F_57 ( V_67 ) )
return 0 ;
if ( F_61 ( V_67 ) && F_60 ( V_67 ) && F_62 ( V_65 ) )
return 0 ;
return 1 ;
}
void F_63 ( struct V_3 * V_4 , struct V_64 * V_65 , int * V_76 )
{
struct V_66 * V_67 ;
T_1 V_110 ;
* V_76 = 0 ;
F_29 ( L_6 , V_32 , * V_76 ) ;
V_110 = V_4 -> V_68 ;
while ( V_110 != V_4 -> V_69 ) {
V_67 = & V_4 -> V_33 [ V_110 ] ;
if ( F_60 ( V_67 ) && ( F_54 ( V_67 ) != V_108 ) &&
( F_49 ( V_67 ) == V_65 -> V_73 . V_74 ) && F_59 ( V_67 , V_65 ) )
( * V_76 ) ++ ;
if ( ++ V_110 == V_4 -> V_55 )
V_110 = 0 ;
}
F_29 ( L_7 , V_32 , V_4 , * V_76 ) ;
}
static int F_64 ( struct V_64 * V_65 , struct V_3 * V_4 , struct V_66 * V_67 ,
T_2 * V_111 , V_61 * V_24 , T_1 * V_112 )
{
int V_16 = 0 ;
struct V_66 * V_99 , V_100 ;
* V_111 = 0 ;
* V_112 = 0 ;
V_16 = F_65 ( V_4 , & V_99 ) ;
if ( V_16 )
return V_16 ;
F_29 ( L_8
L_9 ,
V_32 , F_66 ( V_99 ) , F_49 ( V_99 ) ,
F_67 ( V_99 ) , F_55 ( V_99 ) , F_68 ( V_99 ) ,
F_54 ( V_99 ) , F_69 ( V_99 ) , F_70 ( V_99 ) ,
F_71 ( V_99 ) ) ;
if ( V_65 == NULL ) {
V_16 = - V_113 ;
goto V_114;
}
if ( V_65 -> V_77 && ! F_50 ( V_99 ) ) {
V_16 = - V_113 ;
goto V_114;
}
if ( F_54 ( V_99 ) == V_107 ) {
V_16 = - V_113 ;
goto V_114;
}
if ( F_60 ( V_99 ) && ( F_54 ( V_99 ) == V_108 ) ) {
if ( F_55 ( V_99 ) == 1 ) {
if ( F_68 ( V_99 ) )
F_72 ( V_65 ) ;
V_16 = - V_113 ;
goto V_114;
}
if ( F_56 ( V_99 ) == 1 ) {
if ( F_68 ( V_99 ) )
F_72 ( V_65 ) ;
V_16 = - V_113 ;
goto V_114;
}
if ( ! V_65 -> V_73 . V_95 -> V_97 ) {
F_45 ( V_65 ) ;
V_16 = - V_113 ;
goto V_114;
}
F_48 ( V_65 , V_99 , & V_100 ) ;
V_99 = & V_100 ;
F_45 ( V_65 ) ;
}
if ( F_68 ( V_99 ) || F_73 ( V_65 ) ) {
* V_111 = ( F_68 ( V_99 ) == V_71 ) ;
F_72 ( V_65 ) ;
}
if ( F_60 ( V_99 ) ) {
if ( F_62 ( V_65 ) ) {
F_72 ( V_65 ) ;
V_16 = - V_113 ;
goto V_114;
}
if ( F_74 ( ( F_75 ( V_99 ) != ( V_65 -> V_79 . V_115 ) ) ) ) {
F_72 ( V_65 ) ;
V_99 -> V_70 |= F_47 ( F_32 ( V_116 ) ) ;
goto V_117;
}
goto V_117;
}
if ( ! F_50 ( V_99 ) && ( F_42 ( V_99 ) != V_65 -> V_73 . V_92 ) ) {
struct V_80 * V_90 ;
F_29 ( L_10 ,
V_32 , F_42 ( V_99 ) ) ;
V_90 = & V_65 -> V_73 . V_94 [ F_42 ( V_99 ) ] ;
V_90 -> V_67 = * V_99 ;
V_90 -> V_98 = 1 ;
V_16 = - V_113 ;
goto V_118;
}
V_117:
* V_67 = * V_99 ;
if ( F_57 ( V_99 ) ) {
int V_83 = F_42 ( V_99 ) ;
F_40 ( V_83 >= V_65 -> V_73 . V_55 ) ;
if ( V_83 < V_65 -> V_73 . V_92 )
V_65 -> V_73 . V_78 -= V_65 -> V_73 . V_55 + V_83 - V_65 -> V_73 . V_92 ;
else
V_65 -> V_73 . V_78 -= V_83 - V_65 -> V_73 . V_92 ;
F_40 ( V_65 -> V_73 . V_78 <= 0 && V_65 -> V_73 . V_78 >= V_65 -> V_73 . V_55 ) ;
V_65 -> V_73 . V_92 = ( V_119 ) V_83 ;
F_29 ( L_11 , V_32 , V_65 -> V_73 . V_92 ) ;
* V_24 = V_65 -> V_73 . V_94 [ V_65 -> V_73 . V_92 ] . V_120 ;
if ( V_121 )
F_76 ( V_65 , V_99 ) ;
F_77 ( V_65 ) ;
} else {
F_29 ( L_12 , V_32 , V_65 -> V_79 . V_92 ) ;
* V_24 = V_65 -> V_79 . V_122 [ V_65 -> V_79 . V_92 ] . V_120 ;
F_40 ( F_62 ( V_65 ) ) ;
if ( V_121 )
F_76 ( V_65 , V_99 ) ;
F_78 ( V_65 ) ;
goto V_114;
}
V_118:
F_46 ( V_65 , V_4 ) ;
V_114:
if ( F_50 ( V_99 ) ) {
F_29 ( L_13 ,
V_32 , V_4 , V_4 -> V_31 , V_4 -> V_68 ) ;
F_79 ( V_4 ) ;
} else {
F_29 ( L_14 ,
V_32 , V_4 , V_4 -> V_31 , V_4 -> V_92 ) ;
F_58 ( V_4 ) ;
}
return V_16 ;
}
static int F_80 ( struct V_86 * V_87 , struct V_123 * V_124 )
{
struct V_84 * V_85 = NULL ;
struct V_66 V_125 ( V_67 ) , * V_126 ;
struct V_64 * V_65 ;
T_1 V_112 = 0 ;
T_2 V_111 ;
V_61 V_24 = 0 ;
int V_16 ;
V_16 = F_65 ( & V_87 -> V_4 , & V_126 ) ;
if ( V_16 )
return V_16 ;
V_85 = F_53 ( V_87 -> V_105 , F_49 ( V_126 ) ) ;
if ( ! V_85 )
V_65 = NULL ;
else {
F_81 ( & V_85 -> V_127 ) ;
V_65 = & ( V_85 -> V_65 ) ;
}
V_16 = F_64 ( V_65 , & ( V_87 -> V_4 ) , & V_67 , & V_111 , & V_24 , & V_112 ) ;
if ( V_16 )
goto V_128;
V_124 -> V_120 = V_24 ;
V_124 -> V_129 = & V_85 -> V_88 ;
V_124 -> V_130 = F_68 ( & V_67 ) ;
V_124 -> V_131 = 0 ;
F_29 ( L_15
L_16 , V_32 , F_49 ( & V_67 ) ,
F_55 ( & V_67 ) , F_54 ( & V_67 ) , F_68 ( & V_67 ) , F_69 ( & V_67 ) ,
F_70 ( & V_67 ) , F_71 ( & V_67 ) , ( unsigned long long ) V_24 ) ;
if ( F_55 ( & V_67 ) == 0 ) {
if ( ! F_68 ( & V_67 ) )
V_124 -> V_132 = F_69 ( & V_67 ) ;
else
V_124 -> V_132 = 0 ;
V_124 -> V_82 = V_133 ;
if ( F_54 ( & V_67 ) == V_134 ||
F_54 ( & V_67 ) == V_135 ) {
V_124 -> V_136 . V_137 = F_56 ( & V_67 ) ;
V_124 -> V_131 |= V_138 ;
}
} else {
switch ( F_54 ( & V_67 ) ) {
case V_109 :
V_124 -> V_82 = V_139 ;
break;
case V_96 :
V_124 -> V_82 = V_140 ;
V_124 -> V_132 = F_69 ( & V_67 ) ;
break;
case V_134 :
case V_135 :
V_124 -> V_82 = V_141 ;
V_124 -> V_131 |= V_138 ;
break;
case V_72 :
case V_142 :
V_124 -> V_82 = V_141 ;
break;
case V_143 :
V_124 -> V_82 = V_144 ;
break;
case V_145 :
V_124 -> V_82 = V_146 ;
break;
case V_147 :
V_124 -> V_82 = V_148 ;
break;
default:
F_82 (KERN_ERR MOD L_17
L_18 ,
CQE_OPCODE(&cqe), CQE_QPID(&cqe)) ;
V_16 = - V_149 ;
goto V_128;
}
}
if ( V_111 )
V_124 -> V_150 = V_151 ;
else {
switch ( F_68 ( & V_67 ) ) {
case V_152 :
V_124 -> V_150 = V_153 ;
break;
case V_154 :
V_124 -> V_150 = V_155 ;
break;
case V_156 :
V_124 -> V_150 = V_157 ;
break;
case V_158 :
case V_159 :
V_124 -> V_150 = V_155 ;
break;
case V_160 :
V_124 -> V_150 = V_161 ;
break;
case V_162 :
V_124 -> V_150 = V_163 ;
break;
case V_164 :
case V_165 :
V_124 -> V_150 = V_166 ;
break;
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_116 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
V_124 -> V_150 = V_180 ;
break;
case V_71 :
V_124 -> V_150 = V_151 ;
break;
default:
F_82 (KERN_ERR MOD
L_19 ,
CQE_STATUS(&cqe), CQE_QPID(&cqe)) ;
V_16 = - V_149 ;
}
}
V_128:
if ( V_65 )
F_83 ( & V_85 -> V_127 ) ;
return V_16 ;
}
int F_84 ( struct V_181 * V_182 , int V_183 , struct V_123 * V_124 )
{
struct V_86 * V_87 ;
unsigned long V_184 ;
int V_185 ;
int V_186 = 0 ;
V_87 = F_44 ( V_182 ) ;
F_85 ( & V_87 -> V_127 , V_184 ) ;
for ( V_185 = 0 ; V_185 < V_183 ; ++ V_185 ) {
do {
V_186 = F_80 ( V_87 , V_124 + V_185 ) ;
} while ( V_186 == - V_113 );
if ( V_186 )
break;
}
F_86 ( & V_87 -> V_127 , V_184 ) ;
return ! V_186 || V_186 == - V_187 ? V_185 : V_186 ;
}
int F_87 ( struct V_181 * V_181 )
{
struct V_86 * V_87 ;
struct V_188 * V_189 ;
F_29 ( L_20 , V_32 , V_181 ) ;
V_87 = F_44 ( V_181 ) ;
F_88 ( V_87 -> V_105 , & V_87 -> V_105 -> V_190 , V_87 -> V_4 . V_31 ) ;
F_89 ( & V_87 -> V_191 ) ;
F_90 ( V_87 -> V_192 , ! F_91 ( & V_87 -> V_191 ) ) ;
V_189 = V_181 -> V_193 ? F_92 ( V_181 -> V_193 -> V_194 )
: NULL ;
F_1 ( & V_87 -> V_105 -> V_2 , & V_87 -> V_4 ,
V_189 ? & V_189 -> V_6 : & V_87 -> V_4 . V_2 -> V_6 ) ;
F_12 ( V_87 ) ;
return 0 ;
}
struct V_181 * F_93 ( struct V_195 * V_196 , int V_197 ,
int V_50 , struct V_198 * V_199 ,
struct V_200 * V_201 )
{
struct V_202 * V_105 ;
struct V_86 * V_87 ;
struct V_203 V_204 ;
struct V_188 * V_189 = NULL ;
int V_16 ;
T_3 V_37 , V_205 ;
struct V_206 * V_207 , * V_208 ;
F_29 ( L_21 , V_32 , V_196 , V_197 ) ;
V_105 = F_94 ( V_196 ) ;
if ( V_50 >= V_105 -> V_2 . V_34 . V_209 )
return F_95 ( - V_149 ) ;
V_87 = F_18 ( sizeof( * V_87 ) , V_17 ) ;
if ( ! V_87 )
return F_95 ( - V_18 ) ;
if ( V_199 )
V_189 = F_92 ( V_199 ) ;
V_197 ++ ;
V_197 ++ ;
V_197 = F_96 ( V_197 , 16 ) ;
V_205 = F_97 ( V_197 * 2 , V_105 -> V_2 . V_210 . V_211 ) ;
if ( V_205 < 64 )
V_205 = 64 ;
V_37 = V_205 * sizeof * V_87 -> V_4 . V_38 ;
if ( V_189 )
V_37 = F_96 ( V_37 , V_212 ) ;
V_87 -> V_4 . V_55 = V_205 ;
V_87 -> V_4 . V_37 = V_37 ;
V_87 -> V_4 . V_50 = V_50 ;
V_16 = F_16 ( & V_105 -> V_2 , & V_87 -> V_4 ,
V_189 ? & V_189 -> V_6 : & V_105 -> V_2 . V_6 ) ;
if ( V_16 )
goto V_41;
V_87 -> V_105 = V_105 ;
V_87 -> V_4 . V_55 -- ;
V_87 -> V_182 . V_67 = V_197 - 2 ;
F_98 ( & V_87 -> V_127 ) ;
F_98 ( & V_87 -> V_213 ) ;
F_99 ( & V_87 -> V_191 , 1 ) ;
F_100 ( & V_87 -> V_192 ) ;
V_16 = F_101 ( V_105 , & V_105 -> V_190 , V_87 , V_87 -> V_4 . V_31 ) ;
if ( V_16 )
goto V_42;
if ( V_189 ) {
V_207 = F_102 ( sizeof *V_207 , V_17 ) ;
if ( ! V_207 )
goto V_44;
V_208 = F_102 ( sizeof *V_208 , V_17 ) ;
if ( ! V_208 )
goto V_45;
V_204 . V_214 = V_105 -> V_2 . V_215 ;
V_204 . V_31 = V_87 -> V_4 . V_31 ;
V_204 . V_55 = V_87 -> V_4 . V_55 ;
V_204 . V_37 = V_87 -> V_4 . V_37 ;
F_81 ( & V_189 -> V_216 ) ;
V_204 . V_217 = V_189 -> V_217 ;
V_189 -> V_217 += V_212 ;
V_204 . V_218 = V_189 -> V_217 ;
V_189 -> V_217 += V_212 ;
F_83 ( & V_189 -> V_216 ) ;
V_16 = F_103 ( V_201 , & V_204 ,
sizeof( V_204 ) - sizeof( V_204 . V_219 ) ) ;
if ( V_16 )
goto V_220;
V_207 -> V_217 = V_204 . V_217 ;
V_207 -> V_221 = F_104 ( V_87 -> V_4 . V_38 ) ;
V_207 -> V_102 = V_87 -> V_4 . V_37 ;
F_105 ( V_189 , V_207 ) ;
V_208 -> V_217 = V_204 . V_218 ;
V_208 -> V_221 = V_87 -> V_4 . V_60 ;
V_208 -> V_102 = V_212 ;
F_105 ( V_189 , V_208 ) ;
}
F_29 ( L_22 ,
V_32 , V_87 -> V_4 . V_31 , V_87 , V_87 -> V_4 . V_55 ,
V_87 -> V_4 . V_37 ,
( unsigned long long ) V_87 -> V_4 . V_43 ) ;
return & V_87 -> V_182 ;
V_220:
F_12 ( V_208 ) ;
V_45:
F_12 ( V_207 ) ;
V_44:
F_88 ( V_105 , & V_105 -> V_190 , V_87 -> V_4 . V_31 ) ;
V_42:
F_1 ( & V_87 -> V_105 -> V_2 , & V_87 -> V_4 ,
V_189 ? & V_189 -> V_6 : & V_105 -> V_2 . V_6 ) ;
V_41:
F_12 ( V_87 ) ;
return F_95 ( V_16 ) ;
}
int F_106 ( struct V_181 * V_4 , int V_67 , struct V_200 * V_201 )
{
return - V_222 ;
}
int F_107 ( struct V_181 * V_182 , enum V_223 V_184 )
{
struct V_86 * V_87 ;
int V_16 ;
unsigned long V_224 ;
V_87 = F_44 ( V_182 ) ;
F_85 ( & V_87 -> V_127 , V_224 ) ;
V_16 = F_108 ( & V_87 -> V_4 ,
( V_184 & V_225 ) == V_226 ) ;
F_86 ( & V_87 -> V_127 , V_224 ) ;
if ( V_16 && ! ( V_184 & V_227 ) )
V_16 = 0 ;
return V_16 ;
}
