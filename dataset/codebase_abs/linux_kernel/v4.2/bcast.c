static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
F_3 ( & V_3 -> V_5 -> V_6 ) ;
}
static void F_4 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
F_5 ( & V_3 -> V_5 -> V_6 ) ;
}
void F_6 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
F_7 ( V_1 , & V_3 -> V_5 -> V_7 , & V_3 -> V_5 -> V_8 ) ;
}
T_1 F_8 ( void )
{
return V_9 ;
}
static T_2 F_9 ( struct V_10 * V_11 )
{
return ( T_2 ) ( unsigned long ) F_10 ( V_11 ) -> V_12 ;
}
static void F_11 ( struct V_10 * V_11 , T_2 V_13 )
{
F_10 ( V_11 ) -> V_12 = ( void * ) ( unsigned long ) V_13 ;
}
static void F_12 ( struct V_10 * V_11 )
{
F_11 ( V_11 , F_9 ( V_11 ) - 1 ) ;
}
void F_13 ( struct V_1 * V_1 , T_2 V_14 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
F_1 ( V_1 ) ;
F_14 ( & V_3 -> V_5 -> V_15 , V_14 ) ;
F_4 ( V_1 ) ;
}
void F_15 ( struct V_1 * V_1 , T_2 V_14 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
F_1 ( V_1 ) ;
F_16 ( & V_3 -> V_5 -> V_15 , V_14 ) ;
if ( ! V_3 -> V_5 -> V_15 . V_16 )
F_17 ( & V_3 -> V_5 -> V_17 ) ;
F_4 ( V_1 ) ;
}
static void F_18 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
struct V_18 * V_19 = V_3 -> V_19 ;
V_19 -> V_20 = F_19 ( V_19 -> V_21 - 1 ) ;
}
T_2 F_20 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
return V_3 -> V_19 -> V_20 ;
}
static void F_21 ( struct V_22 * V_23 , T_2 V_24 )
{
V_23 -> V_5 . V_25 = F_22 ( V_23 -> V_5 . V_25 , V_24 ) ?
V_24 : V_23 -> V_5 . V_25 ;
}
struct V_22 * F_23 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
return V_3 -> V_5 -> V_26 ;
}
static void F_24 ( struct V_2 * V_3 , T_2 V_27 , T_2 V_28 )
{
struct V_10 * V_29 ;
struct V_18 * V_19 = V_3 -> V_19 ;
F_25 (&bcl->transmq, skb) {
if ( F_26 ( F_27 ( V_29 ) , V_27 ) ) {
F_28 ( V_19 , V_29 , F_19 ( V_28 - V_27 ) ) ;
break;
}
}
}
void F_29 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
F_30 ( V_1 , & V_3 -> V_5 -> V_17 . V_30 ) ;
}
void F_31 ( struct V_22 * V_31 , T_2 V_32 )
{
struct V_10 * V_29 , * V_33 ;
unsigned int V_34 = 0 ;
struct V_1 * V_1 = V_31 -> V_1 ;
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
if ( F_32 ( ! V_31 -> V_5 . V_35 ) )
return;
F_1 ( V_1 ) ;
V_29 = F_33 ( & V_3 -> V_19 -> V_36 ) ;
if ( ! V_29 )
goto exit;
if ( V_32 == V_37 ) {
if ( V_3 -> V_5 -> V_15 . V_16 )
V_32 = V_3 -> V_19 -> V_20 ;
else
V_32 = V_3 -> V_19 -> V_21 ;
} else {
if ( F_34 ( V_32 , F_27 ( V_29 ) ) ||
F_34 ( V_3 -> V_19 -> V_20 , V_32 ) ||
F_22 ( V_32 , V_31 -> V_5 . V_32 ) )
goto exit;
}
F_25 (&tn->bcl->transmq, skb) {
if ( F_26 ( F_27 ( V_29 ) , V_31 -> V_5 . V_32 ) )
break;
}
F_35 (&tn->bcl->transmq, skb, tmp) {
if ( F_26 ( F_27 ( V_29 ) , V_32 ) )
break;
F_12 ( V_29 ) ;
F_18 ( V_1 ) ;
if ( F_9 ( V_29 ) == 0 ) {
F_36 ( V_29 , & V_3 -> V_19 -> V_36 ) ;
F_37 ( V_29 ) ;
V_34 = 1 ;
}
}
V_31 -> V_5 . V_32 = V_32 ;
if ( F_32 ( F_33 ( & V_3 -> V_19 -> V_38 ) ) ) {
F_38 ( V_3 -> V_19 ) ;
F_18 ( V_1 ) ;
}
if ( F_32 ( V_34 && ! F_39 ( & V_3 -> V_19 -> V_30 ) ) )
V_31 -> V_39 |= V_40 ;
exit:
F_4 ( V_1 ) ;
}
void F_40 ( struct V_22 * V_31 ,
T_2 V_25 )
{
struct V_10 * V_11 ;
struct V_1 * V_1 = V_31 -> V_1 ;
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
if ( F_22 ( V_25 , V_31 -> V_5 . V_41 ) )
return;
F_21 ( V_31 , V_25 ) ;
if ( V_31 -> V_5 . V_25 == V_31 -> V_5 . V_41 )
return;
if ( ( ++ V_31 -> V_5 . V_42 ) == 1 ) {
if ( V_31 -> V_5 . V_43 < ( V_44 / 2 ) )
return;
V_31 -> V_5 . V_42 ++ ;
}
if ( V_31 -> V_5 . V_42 & 0x1 )
return;
V_11 = F_41 ( V_45 ) ;
if ( V_11 ) {
struct V_46 * V_47 = F_42 ( V_11 ) ;
struct V_10 * V_29 = F_33 ( & V_31 -> V_5 . V_48 ) ;
T_2 V_28 = V_29 ? F_27 ( V_29 ) - 1 : V_31 -> V_5 . V_25 ;
F_43 ( V_3 -> V_49 , V_47 , V_50 , V_51 ,
V_45 , V_31 -> V_14 ) ;
F_44 ( V_47 , 1 ) ;
F_45 ( V_47 , V_3 -> V_52 ) ;
F_46 ( V_47 , V_31 -> V_5 . V_41 ) ;
F_47 ( V_47 , V_31 -> V_5 . V_41 ) ;
F_48 ( V_47 , V_28 ) ;
F_1 ( V_1 ) ;
F_49 ( V_1 , V_53 , V_11 , NULL ) ;
V_3 -> V_19 -> V_54 . V_55 ++ ;
F_4 ( V_1 ) ;
F_37 ( V_11 ) ;
V_31 -> V_5 . V_42 ++ ;
}
}
static void F_50 ( struct V_1 * V_1 , struct V_46 * V_47 )
{
struct V_22 * V_31 = F_51 ( V_1 , F_52 ( V_47 ) ) ;
if ( F_32 ( ! V_31 ) )
return;
F_53 ( V_31 ) ;
if ( V_31 -> V_5 . V_35 &&
( V_31 -> V_5 . V_41 != V_31 -> V_5 . V_25 ) &&
( V_31 -> V_5 . V_41 == F_54 ( V_47 ) ) )
V_31 -> V_5 . V_42 = 2 ;
F_55 ( V_31 ) ;
F_56 ( V_31 ) ;
}
int F_57 ( struct V_1 * V_1 , struct V_56 * V_57 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
struct V_18 * V_19 = V_3 -> V_19 ;
struct V_58 * V_5 = V_3 -> V_5 ;
int V_59 = 0 ;
int V_60 = 0 ;
struct V_10 * V_29 ;
struct V_56 V_7 ;
struct V_56 V_8 ;
V_29 = F_58 ( V_57 ) ;
if ( F_32 ( ! V_29 ) ) {
F_59 ( V_57 ) ;
return - V_61 ;
}
if ( F_60 ( V_5 ) ) {
F_1 ( V_1 ) ;
if ( F_60 ( V_5 -> V_15 . V_16 ) ) {
V_59 = F_61 ( V_1 , V_19 , V_57 ) ;
if ( F_60 ( ! V_59 ) ) {
T_2 V_62 = F_62 ( & V_19 -> V_36 ) ;
F_18 ( V_1 ) ;
V_19 -> V_54 . V_63 ++ ;
V_19 -> V_54 . V_64 += V_62 ;
}
V_60 = 1 ;
}
F_4 ( V_1 ) ;
}
if ( F_32 ( ! V_60 ) )
F_59 ( V_57 ) ;
if ( F_32 ( V_59 ) ) {
F_37 ( V_29 ) ;
return V_59 ;
}
F_63 ( & V_7 ) ;
F_64 ( & V_8 ) ;
F_65 ( & V_7 , V_29 ) ;
F_7 ( V_1 , & V_7 , & V_8 ) ;
return V_59 ;
}
static void F_66 ( struct V_22 * V_23 , T_2 V_24 )
{
struct V_2 * V_3 = F_2 ( V_23 -> V_1 , V_4 ) ;
F_21 ( V_23 , V_24 ) ;
V_23 -> V_5 . V_41 = V_24 ;
V_23 -> V_5 . V_42 = 0 ;
V_3 -> V_19 -> V_54 . V_65 ++ ;
if ( ( ( V_24 - V_3 -> V_49 ) % V_44 ) == 0 ) {
F_67 ( V_23 -> V_66 [ V_23 -> V_14 & 1 ] ,
V_51 , 0 , 0 , 0 , 0 ) ;
V_3 -> V_19 -> V_54 . V_67 ++ ;
}
}
void F_68 ( struct V_1 * V_1 , struct V_10 * V_11 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
struct V_18 * V_19 = V_3 -> V_19 ;
struct V_46 * V_47 = F_42 ( V_11 ) ;
struct V_22 * V_23 ;
T_2 V_68 ;
T_2 V_24 ;
int V_69 = 0 ;
int V_70 = 0 ;
struct V_10 * V_71 ;
struct V_56 * V_7 , * V_8 ;
if ( F_69 ( V_47 ) != V_3 -> V_52 )
goto exit;
V_23 = F_51 ( V_1 , F_70 ( V_47 ) ) ;
if ( F_32 ( ! V_23 ) )
goto exit;
F_53 ( V_23 ) ;
if ( F_32 ( ! V_23 -> V_5 . V_35 ) )
goto V_72;
if ( F_32 ( F_71 ( V_47 ) == V_50 ) ) {
if ( F_72 ( V_47 ) != V_51 )
goto V_72;
if ( F_52 ( V_47 ) == V_3 -> V_49 ) {
F_31 ( V_23 , F_73 ( V_47 ) ) ;
F_1 ( V_1 ) ;
V_19 -> V_54 . V_73 ++ ;
V_3 -> V_5 -> V_26 = V_23 ;
F_24 ( V_3 , F_54 ( V_47 ) ,
F_74 ( V_47 ) ) ;
F_4 ( V_1 ) ;
F_55 ( V_23 ) ;
} else {
F_55 ( V_23 ) ;
F_50 ( V_1 , V_47 ) ;
}
F_56 ( V_23 ) ;
goto exit;
}
V_24 = F_75 ( V_47 ) ;
V_68 = F_19 ( V_23 -> V_5 . V_41 + 1 ) ;
V_7 = & V_3 -> V_5 -> V_7 ;
V_8 = & V_3 -> V_5 -> V_8 ;
if ( F_60 ( V_24 == V_68 ) ) {
V_74:
if ( F_60 ( F_76 ( V_47 ) ) ) {
F_1 ( V_1 ) ;
F_66 ( V_23 , V_24 ) ;
F_3 ( & V_8 -> V_6 ) ;
F_65 ( V_7 , V_11 ) ;
F_5 ( & V_8 -> V_6 ) ;
V_23 -> V_39 |= V_75 ;
F_4 ( V_1 ) ;
F_55 ( V_23 ) ;
} else if ( F_71 ( V_47 ) == V_76 ) {
F_1 ( V_1 ) ;
F_66 ( V_23 , V_24 ) ;
V_19 -> V_54 . V_77 ++ ;
V_19 -> V_54 . V_78 += F_77 ( V_47 ) ;
V_70 = 0 ;
while ( F_78 ( V_11 , & V_71 , & V_70 ) ) {
F_3 ( & V_8 -> V_6 ) ;
F_65 ( V_7 , V_71 ) ;
F_5 ( & V_8 -> V_6 ) ;
}
V_23 -> V_39 |= V_75 ;
F_4 ( V_1 ) ;
F_55 ( V_23 ) ;
} else if ( F_71 ( V_47 ) == V_79 ) {
F_1 ( V_1 ) ;
F_66 ( V_23 , V_24 ) ;
F_79 ( & V_23 -> V_5 . V_80 , & V_11 ) ;
if ( F_32 ( ! V_11 && ! V_23 -> V_5 . V_80 ) ) {
F_4 ( V_1 ) ;
goto V_72;
}
V_19 -> V_54 . V_81 ++ ;
if ( V_11 ) {
V_19 -> V_54 . V_82 ++ ;
V_47 = F_42 ( V_11 ) ;
F_4 ( V_1 ) ;
goto V_74;
}
F_4 ( V_1 ) ;
F_55 ( V_23 ) ;
} else {
F_1 ( V_1 ) ;
F_66 ( V_23 , V_24 ) ;
F_4 ( V_1 ) ;
F_55 ( V_23 ) ;
F_37 ( V_11 ) ;
}
V_11 = NULL ;
F_53 ( V_23 ) ;
if ( F_32 ( ! F_80 ( V_23 ) ) )
goto V_72;
if ( V_23 -> V_5 . V_41 == V_23 -> V_5 . V_25 )
goto V_72;
if ( F_39 ( & V_23 -> V_5 . V_48 ) ) {
V_23 -> V_5 . V_42 = 1 ;
goto V_72;
}
V_47 = F_42 ( F_33 ( & V_23 -> V_5 . V_48 ) ) ;
V_24 = F_75 ( V_47 ) ;
V_68 = F_19 ( V_68 + 1 ) ;
if ( V_24 != V_68 )
goto V_72;
V_11 = F_81 ( & V_23 -> V_5 . V_48 ) ;
goto V_74;
}
if ( F_34 ( V_68 , V_24 ) ) {
V_69 = F_82 ( & V_23 -> V_5 . V_48 ,
V_11 ) ;
F_21 ( V_23 , V_24 ) ;
V_11 = NULL ;
}
F_1 ( V_1 ) ;
if ( V_69 )
V_19 -> V_54 . V_83 ++ ;
else
V_19 -> V_54 . V_84 ++ ;
F_4 ( V_1 ) ;
V_72:
F_55 ( V_23 ) ;
F_56 ( V_23 ) ;
exit:
F_37 ( V_11 ) ;
}
T_2 F_83 ( struct V_22 * V_31 )
{
return ( V_31 -> V_5 . V_35 &&
( F_20 ( V_31 -> V_1 ) != V_31 -> V_5 . V_32 ) ) ;
}
static int F_84 ( struct V_1 * V_1 , struct V_10 * V_11 ,
struct V_85 * V_86 ,
struct V_87 * V_88 )
{
int V_89 ;
struct V_46 * V_47 = F_42 ( V_11 ) ;
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
struct V_90 * V_91 = V_3 -> V_91 ;
struct V_58 * V_5 = V_3 -> V_5 ;
if ( F_60 ( ! F_85 ( F_42 ( V_11 ) ) ) ) {
F_11 ( V_11 , V_5 -> V_15 . V_16 ) ;
F_44 ( V_47 , 1 ) ;
F_45 ( V_47 , V_3 -> V_52 ) ;
V_3 -> V_19 -> V_54 . V_92 ++ ;
if ( F_86 ( ! V_5 -> V_15 . V_16 ) ) {
F_87 () ;
return 0 ;
}
}
V_91 -> V_93 = V_5 -> V_15 ;
for ( V_89 = 0 ; V_89 < V_53 ; V_89 ++ ) {
struct V_85 * V_94 = V_91 -> V_95 [ V_89 ] . V_96 ;
struct V_85 * V_97 = V_91 -> V_95 [ V_89 ] . V_98 ;
struct V_85 * V_99 [ 2 ] = { V_94 , V_97 } ;
struct V_85 * V_100 = V_99 [ F_88 ( V_47 ) ] ;
struct V_10 * V_101 ;
if ( ! V_94 )
break;
if ( ! V_100 )
V_100 = V_94 ;
F_89 ( & V_91 -> V_93 , & V_100 -> V_102 ,
& V_91 -> V_103 ) ;
if ( V_91 -> V_103 . V_16 == V_91 -> V_93 . V_16 )
continue;
if ( V_89 == 0 ) {
F_49 ( V_1 , V_100 -> V_104 , V_11 , & V_100 -> V_105 ) ;
} else {
V_101 = F_90 ( V_11 , V_106 ) ;
if ( ! V_101 )
break;
F_49 ( V_1 , V_100 -> V_104 , V_101 ,
& V_100 -> V_105 ) ;
F_37 ( V_101 ) ;
}
if ( V_91 -> V_103 . V_16 == 0 )
break;
V_91 -> V_93 = V_91 -> V_103 ;
}
return 0 ;
}
void F_91 ( struct V_1 * V_1 , struct V_107 * V_108 ,
T_2 V_23 , bool V_109 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
struct V_90 * V_91 = V_3 -> V_91 ;
struct V_110 * V_111 = V_91 -> V_112 ;
struct V_110 * V_113 ;
struct V_85 * V_100 ;
int V_114 ;
int V_115 ;
F_1 ( V_1 ) ;
if ( V_109 )
F_14 ( V_108 , V_23 ) ;
else
F_16 ( V_108 , V_23 ) ;
memset ( V_111 , 0 , sizeof( V_91 -> V_112 ) ) ;
F_92 () ;
for ( V_114 = 0 ; V_114 < V_53 ; V_114 ++ ) {
V_100 = F_93 ( V_3 -> V_116 [ V_114 ] ) ;
if ( ! V_100 || ! V_100 -> V_102 . V_16 )
continue;
if ( ! V_111 [ V_100 -> V_117 ] . V_96 )
V_111 [ V_100 -> V_117 ] . V_96 = V_100 ;
else
V_111 [ V_100 -> V_117 ] . V_98 = V_100 ;
}
F_94 () ;
V_113 = V_91 -> V_95 ;
memset ( V_91 -> V_95 , 0 , sizeof( V_91 -> V_95 ) ) ;
for ( V_115 = V_118 ; V_115 >= 0 ; V_115 -- ) {
if ( ! V_111 [ V_115 ] . V_96 )
continue;
V_113 -> V_96 = V_111 [ V_115 ] . V_96 ;
if ( V_111 [ V_115 ] . V_98 ) {
if ( F_95 ( & V_111 [ V_115 ] . V_96 -> V_102 ,
& V_111 [ V_115 ] . V_98 -> V_102 ) ) {
V_113 -> V_98 = V_111 [ V_115 ] . V_98 ;
} else {
V_113 ++ ;
V_113 -> V_96 = V_111 [ V_115 ] . V_98 ;
}
}
V_113 ++ ;
}
F_4 ( V_1 ) ;
}
static int F_96 ( struct V_10 * V_29 ,
struct V_119 * V_54 )
{
int V_120 ;
struct V_121 * V_122 ;
struct V_123 {
T_3 V_124 ;
T_3 V_125 ;
};
struct V_123 V_126 [] = {
{ V_127 , V_54 -> V_65 } ,
{ V_128 , V_54 -> V_81 } ,
{ V_129 , V_54 -> V_82 } ,
{ V_130 , V_54 -> V_77 } ,
{ V_131 , V_54 -> V_78 } ,
{ V_132 , V_54 -> V_92 } ,
{ V_133 , V_54 -> V_134 } ,
{ V_135 , V_54 -> V_136 } ,
{ V_137 , V_54 -> V_138 } ,
{ V_139 , V_54 -> V_140 } ,
{ V_141 , V_54 -> V_73 } ,
{ V_142 , V_54 -> V_83 } ,
{ V_143 , V_54 -> V_55 } ,
{ V_144 , V_54 -> V_67 } ,
{ V_145 , V_54 -> V_146 } ,
{ V_147 , V_54 -> V_84 } ,
{ V_148 , V_54 -> V_149 } ,
{ V_150 , V_54 -> V_151 } ,
{ V_152 , V_54 -> V_63 ?
( V_54 -> V_64 / V_54 -> V_63 ) : 0 }
} ;
V_122 = F_97 ( V_29 , V_153 ) ;
if ( ! V_122 )
return - V_154 ;
for ( V_120 = 0 ; V_120 < F_98 ( V_126 ) ; V_120 ++ )
if ( F_99 ( V_29 , V_126 [ V_120 ] . V_124 , V_126 [ V_120 ] . V_125 ) )
goto V_155;
F_100 ( V_29 , V_122 ) ;
return 0 ;
V_155:
F_101 ( V_29 , V_122 ) ;
return - V_154 ;
}
int F_102 ( struct V_1 * V_1 , struct V_156 * V_47 )
{
int V_157 ;
void * V_158 ;
struct V_121 * V_159 ;
struct V_121 * V_160 ;
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
struct V_18 * V_19 = V_3 -> V_19 ;
if ( ! V_19 )
return 0 ;
F_1 ( V_1 ) ;
V_158 = F_103 ( V_47 -> V_29 , V_47 -> V_161 , V_47 -> V_162 , & V_163 ,
V_164 , V_165 ) ;
if ( ! V_158 )
return - V_154 ;
V_159 = F_97 ( V_47 -> V_29 , V_166 ) ;
if ( ! V_159 )
goto V_155;
if ( F_104 ( V_47 -> V_29 , V_167 ) )
goto V_168;
if ( F_104 ( V_47 -> V_29 , V_169 ) )
goto V_168;
if ( F_105 ( V_47 -> V_29 , V_170 , V_19 -> V_171 ) )
goto V_168;
if ( F_99 ( V_47 -> V_29 , V_172 , V_19 -> V_173 ) )
goto V_168;
if ( F_99 ( V_47 -> V_29 , V_174 , V_19 -> V_21 ) )
goto V_168;
V_160 = F_97 ( V_47 -> V_29 , V_175 ) ;
if ( ! V_160 )
goto V_168;
if ( F_99 ( V_47 -> V_29 , V_176 , V_19 -> V_177 ) )
goto V_178;
F_100 ( V_47 -> V_29 , V_160 ) ;
V_157 = F_96 ( V_47 -> V_29 , & V_19 -> V_54 ) ;
if ( V_157 )
goto V_168;
F_4 ( V_1 ) ;
F_100 ( V_47 -> V_29 , V_159 ) ;
F_106 ( V_47 -> V_29 , V_158 ) ;
return 0 ;
V_178:
F_101 ( V_47 -> V_29 , V_160 ) ;
V_168:
F_101 ( V_47 -> V_29 , V_159 ) ;
V_155:
F_4 ( V_1 ) ;
F_107 ( V_47 -> V_29 , V_158 ) ;
return - V_154 ;
}
int F_108 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
struct V_18 * V_19 = V_3 -> V_19 ;
if ( ! V_19 )
return - V_179 ;
F_1 ( V_1 ) ;
memset ( & V_19 -> V_54 , 0 , sizeof( V_19 -> V_54 ) ) ;
F_4 ( V_1 ) ;
return 0 ;
}
int F_109 ( struct V_1 * V_1 , T_2 V_180 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
struct V_18 * V_19 = V_3 -> V_19 ;
if ( ! V_19 )
return - V_179 ;
if ( ( V_180 < V_44 ) || ( V_180 > V_181 ) )
return - V_182 ;
F_1 ( V_1 ) ;
F_110 ( V_19 , V_180 ) ;
F_4 ( V_1 ) ;
return 0 ;
}
int F_111 ( struct V_1 * V_1 , struct V_121 * V_159 [] )
{
int V_157 ;
T_2 V_183 ;
struct V_121 * V_184 [ V_185 + 1 ] ;
if ( ! V_159 [ V_175 ] )
return - V_182 ;
V_157 = F_112 ( V_159 [ V_175 ] , V_184 ) ;
if ( V_157 )
return V_157 ;
if ( ! V_184 [ V_176 ] )
return - V_186 ;
V_183 = F_113 ( V_184 [ V_176 ] ) ;
return F_109 ( V_1 , V_183 ) ;
}
int F_114 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
struct V_90 * V_91 ;
struct V_58 * V_5 ;
struct V_18 * V_19 ;
V_91 = F_115 ( sizeof( * V_91 ) , V_106 ) ;
if ( ! V_91 )
return - V_187 ;
V_5 = F_115 ( sizeof( * V_5 ) , V_106 ) ;
if ( ! V_5 ) {
F_116 ( V_91 ) ;
return - V_187 ;
}
V_19 = & V_5 -> V_17 ;
V_91 -> V_188 . V_189 = & V_91 -> V_189 ;
V_91 -> V_189 . V_190 = F_84 ;
sprintf ( V_91 -> V_189 . V_171 , L_1 ) ;
F_117 ( & V_5 -> V_6 ) ;
F_63 ( & V_19 -> V_36 ) ;
F_63 ( & V_19 -> V_38 ) ;
F_63 ( & V_19 -> V_48 ) ;
F_64 ( & V_19 -> V_30 ) ;
V_19 -> V_21 = 1 ;
F_117 ( & V_5 -> V_23 . V_6 ) ;
F_63 ( & V_5 -> V_7 ) ;
F_64 ( & V_5 -> V_8 ) ;
V_19 -> V_191 = & V_5 -> V_23 ;
V_19 -> V_191 -> V_1 = V_1 ;
V_19 -> V_192 = V_9 ;
F_110 ( V_19 , V_193 ) ;
V_19 -> V_194 = V_53 ;
F_118 ( V_3 -> V_116 [ V_53 ] , & V_91 -> V_188 ) ;
V_19 -> V_195 = V_196 ;
V_19 -> V_197 = (struct V_46 * ) & V_19 -> V_198 ;
F_119 ( V_19 -> V_197 , V_3 -> V_49 ) ;
F_120 ( V_19 -> V_171 , V_199 , V_200 ) ;
V_3 -> V_91 = V_91 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_19 = V_19 ;
return 0 ;
}
void F_121 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
F_1 ( V_1 ) ;
F_122 ( V_3 -> V_19 ) ;
F_4 ( V_1 ) ;
F_123 ( V_3 -> V_116 [ V_201 ] , NULL ) ;
F_124 () ;
F_116 ( V_3 -> V_91 ) ;
F_116 ( V_3 -> V_5 ) ;
}
static void F_14 ( struct V_107 * V_108 , T_2 V_23 )
{
int V_202 = V_22 ( V_23 ) ;
int V_203 = V_202 / V_204 ;
T_2 V_205 = ( 1 << ( V_202 % V_204 ) ) ;
if ( ( V_108 -> V_126 [ V_203 ] & V_205 ) == 0 ) {
V_108 -> V_16 ++ ;
V_108 -> V_126 [ V_203 ] |= V_205 ;
}
}
static void F_16 ( struct V_107 * V_108 , T_2 V_23 )
{
int V_202 = V_22 ( V_23 ) ;
int V_203 = V_202 / V_204 ;
T_2 V_205 = ( 1 << ( V_202 % V_204 ) ) ;
if ( ( V_108 -> V_126 [ V_203 ] & V_205 ) != 0 ) {
V_108 -> V_126 [ V_203 ] &= ~ V_205 ;
V_108 -> V_16 -- ;
}
}
static void F_89 ( struct V_107 * V_206 ,
struct V_107 * V_207 ,
struct V_107 * V_208 )
{
int V_209 = F_98 ( V_206 -> V_126 ) ;
int V_203 ;
int V_100 ;
T_2 V_126 ;
memset ( V_208 , 0 , sizeof( * V_208 ) ) ;
for ( V_203 = 0 ; V_203 < V_209 ; V_203 ++ ) {
V_126 = V_206 -> V_126 [ V_203 ] ^ ( V_206 -> V_126 [ V_203 ] & V_207 -> V_126 [ V_203 ] ) ;
V_208 -> V_126 [ V_203 ] = V_126 ;
if ( V_126 != 0 ) {
for ( V_100 = 0 ; V_100 < V_204 ; V_100 ++ ) {
if ( V_126 & ( 1 << V_100 ) )
V_208 -> V_16 ++ ;
}
}
}
}
