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
static void F_29 ( struct V_18 * V_19 , struct V_30 * V_31 )
{
int V_32 [ V_33 + 1 ] = { 0 ,} ;
int V_34 , V_35 ;
struct V_10 * V_29 , * V_36 ;
F_30 (&bcl->wakeupq, skb, tmp) {
V_34 = F_10 ( V_29 ) -> V_37 ;
V_35 = V_19 -> V_38 + V_19 -> V_39 [ V_34 ] . V_40 ;
V_32 [ V_34 ] += F_10 ( V_29 ) -> V_41 ;
if ( ( V_32 [ V_34 ] + V_19 -> V_39 [ V_34 ] . V_42 ) >= V_35 )
continue;
F_31 ( V_29 , & V_19 -> V_43 ) ;
F_32 ( V_31 , V_29 ) ;
}
}
void F_33 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
struct V_18 * V_19 = V_3 -> V_19 ;
struct V_30 V_31 ;
F_34 ( & V_31 ) ;
F_29 ( V_19 , & V_31 ) ;
F_35 ( V_1 , & V_31 ) ;
}
void F_36 ( struct V_22 * V_44 , T_2 V_45 )
{
struct V_10 * V_29 , * V_36 ;
unsigned int V_46 = 0 ;
struct V_1 * V_1 = V_44 -> V_1 ;
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
if ( F_37 ( ! V_44 -> V_5 . V_47 ) )
return;
F_1 ( V_1 ) ;
V_29 = F_38 ( & V_3 -> V_19 -> V_48 ) ;
if ( ! V_29 )
goto exit;
if ( V_45 == V_49 ) {
if ( V_3 -> V_5 -> V_15 . V_16 )
V_45 = V_3 -> V_19 -> V_20 ;
else
V_45 = V_3 -> V_19 -> V_21 ;
} else {
if ( F_39 ( V_45 , F_27 ( V_29 ) ) ||
F_39 ( V_3 -> V_19 -> V_20 , V_45 ) ||
F_22 ( V_45 , V_44 -> V_5 . V_45 ) )
goto exit;
}
F_25 (&tn->bcl->transmq, skb) {
if ( F_26 ( F_27 ( V_29 ) , V_44 -> V_5 . V_45 ) )
break;
}
F_40 (&tn->bcl->transmq, skb, tmp) {
if ( F_26 ( F_27 ( V_29 ) , V_45 ) )
break;
F_12 ( V_29 ) ;
F_18 ( V_1 ) ;
if ( F_9 ( V_29 ) == 0 ) {
F_41 ( V_29 , & V_3 -> V_19 -> V_48 ) ;
F_42 ( V_29 ) ;
V_46 = 1 ;
}
}
V_44 -> V_5 . V_45 = V_45 ;
if ( F_37 ( F_38 ( & V_3 -> V_19 -> V_50 ) ) ) {
F_43 ( V_3 -> V_19 ) ;
F_18 ( V_1 ) ;
}
if ( F_37 ( V_46 && ! F_44 ( & V_3 -> V_19 -> V_43 ) ) )
V_44 -> V_51 |= V_52 ;
exit:
F_4 ( V_1 ) ;
}
void F_45 ( struct V_22 * V_44 ,
T_2 V_25 )
{
struct V_10 * V_11 ;
struct V_1 * V_1 = V_44 -> V_1 ;
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
if ( F_22 ( V_25 , V_44 -> V_5 . V_53 ) )
return;
F_21 ( V_44 , V_25 ) ;
if ( V_44 -> V_5 . V_25 == V_44 -> V_5 . V_53 )
return;
if ( ( ++ V_44 -> V_5 . V_54 ) == 1 ) {
if ( V_44 -> V_5 . V_55 < ( V_56 / 2 ) )
return;
V_44 -> V_5 . V_54 ++ ;
}
if ( V_44 -> V_5 . V_54 & 0x1 )
return;
V_11 = F_46 ( V_57 ) ;
if ( V_11 ) {
struct V_58 * V_59 = F_47 ( V_11 ) ;
struct V_10 * V_29 = F_38 ( & V_44 -> V_5 . V_60 ) ;
T_2 V_28 = V_29 ? F_27 ( V_29 ) - 1 : V_44 -> V_5 . V_25 ;
F_48 ( V_3 -> V_61 , V_59 , V_62 , V_63 ,
V_57 , V_44 -> V_14 ) ;
F_49 ( V_59 , 1 ) ;
F_50 ( V_59 , V_3 -> V_64 ) ;
F_51 ( V_59 , V_44 -> V_5 . V_53 ) ;
F_52 ( V_59 , V_44 -> V_5 . V_53 ) ;
F_53 ( V_59 , V_28 ) ;
F_1 ( V_1 ) ;
F_54 ( V_1 , V_65 , V_11 , NULL ) ;
V_3 -> V_19 -> V_66 . V_67 ++ ;
F_4 ( V_1 ) ;
F_42 ( V_11 ) ;
V_44 -> V_5 . V_54 ++ ;
}
}
void F_55 ( struct V_22 * V_68 , struct V_58 * V_69 )
{
T_3 V_70 = F_56 ( V_69 ) ;
int V_71 = F_57 ( V_69 ) ;
if ( F_37 ( F_58 ( V_69 ) != V_72 ) )
return;
if ( V_71 == V_63 ) {
F_45 ( V_68 , V_70 ) ;
return;
}
if ( F_59 ( V_68 ) )
return;
if ( ( V_71 != V_73 ) && ( V_71 != V_74 ) )
return;
V_68 -> V_5 . V_25 = V_70 ;
V_68 -> V_5 . V_53 = V_70 ;
V_68 -> V_5 . V_54 = 0 ;
}
static void F_60 ( struct V_1 * V_1 , struct V_58 * V_59 )
{
struct V_22 * V_44 = F_61 ( V_1 , F_62 ( V_59 ) ) ;
if ( F_37 ( ! V_44 ) )
return;
F_63 ( V_44 ) ;
if ( V_44 -> V_5 . V_47 &&
( V_44 -> V_5 . V_53 != V_44 -> V_5 . V_25 ) &&
( V_44 -> V_5 . V_53 == F_64 ( V_59 ) ) )
V_44 -> V_5 . V_54 = 2 ;
F_65 ( V_44 ) ;
F_66 ( V_44 ) ;
}
int F_67 ( struct V_1 * V_1 , struct V_30 * V_75 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
struct V_18 * V_19 = V_3 -> V_19 ;
struct V_76 * V_5 = V_3 -> V_5 ;
int V_77 = 0 ;
int V_78 = 0 ;
struct V_10 * V_29 ;
struct V_30 V_7 ;
struct V_30 V_8 ;
V_29 = F_68 ( V_75 ) ;
if ( F_37 ( ! V_29 ) )
return - V_79 ;
if ( F_69 ( V_5 ) ) {
F_1 ( V_1 ) ;
if ( F_69 ( V_5 -> V_15 . V_16 ) ) {
V_77 = F_70 ( V_1 , V_19 , V_75 ) ;
if ( F_69 ( ! V_77 ) ) {
T_2 V_42 = F_71 ( & V_19 -> V_48 ) ;
F_18 ( V_1 ) ;
V_19 -> V_66 . V_80 ++ ;
V_19 -> V_66 . V_81 += V_42 ;
}
V_78 = 1 ;
}
F_4 ( V_1 ) ;
}
if ( F_37 ( ! V_78 ) )
F_72 ( V_75 ) ;
if ( F_37 ( V_77 ) ) {
F_42 ( V_29 ) ;
return V_77 ;
}
F_73 ( & V_7 ) ;
F_34 ( & V_8 ) ;
F_74 ( & V_7 , V_29 ) ;
F_7 ( V_1 , & V_7 , & V_8 ) ;
return V_77 ;
}
static void F_75 ( struct V_22 * V_23 , T_2 V_24 )
{
struct V_2 * V_3 = F_2 ( V_23 -> V_1 , V_4 ) ;
F_21 ( V_23 , V_24 ) ;
V_23 -> V_5 . V_53 = V_24 ;
V_23 -> V_5 . V_54 = 0 ;
V_3 -> V_19 -> V_66 . V_82 ++ ;
if ( ( ( V_24 - V_3 -> V_61 ) % V_56 ) == 0 ) {
F_76 ( F_77 ( V_23 , V_23 -> V_14 ) ,
V_63 , 0 , 0 , 0 , 0 ) ;
V_3 -> V_19 -> V_66 . V_83 ++ ;
}
}
void F_78 ( struct V_1 * V_1 , struct V_10 * V_11 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
struct V_18 * V_19 = V_3 -> V_19 ;
struct V_58 * V_59 = F_47 ( V_11 ) ;
struct V_22 * V_23 ;
T_2 V_84 ;
T_2 V_24 ;
int V_85 = 0 ;
int V_86 = 0 ;
struct V_10 * V_87 ;
struct V_30 * V_7 , * V_8 ;
if ( F_79 ( V_59 ) != V_3 -> V_64 )
goto exit;
V_23 = F_61 ( V_1 , F_80 ( V_59 ) ) ;
if ( F_37 ( ! V_23 ) )
goto exit;
F_63 ( V_23 ) ;
if ( F_37 ( ! V_23 -> V_5 . V_47 ) )
goto V_88;
if ( F_37 ( F_58 ( V_59 ) == V_62 ) ) {
if ( F_57 ( V_59 ) != V_63 )
goto V_88;
if ( F_62 ( V_59 ) == V_3 -> V_61 ) {
F_36 ( V_23 , F_81 ( V_59 ) ) ;
F_1 ( V_1 ) ;
V_19 -> V_66 . V_89 ++ ;
V_3 -> V_5 -> V_26 = V_23 ;
F_24 ( V_3 , F_64 ( V_59 ) ,
F_82 ( V_59 ) ) ;
F_4 ( V_1 ) ;
F_65 ( V_23 ) ;
} else {
F_65 ( V_23 ) ;
F_60 ( V_1 , V_59 ) ;
}
F_66 ( V_23 ) ;
goto exit;
}
V_24 = F_83 ( V_59 ) ;
V_84 = F_19 ( V_23 -> V_5 . V_53 + 1 ) ;
V_7 = & V_3 -> V_5 -> V_7 ;
V_8 = & V_3 -> V_5 -> V_8 ;
if ( F_69 ( V_24 == V_84 ) ) {
V_90:
if ( F_69 ( F_84 ( V_59 ) ) ) {
F_1 ( V_1 ) ;
F_75 ( V_23 , V_24 ) ;
F_3 ( & V_8 -> V_6 ) ;
F_74 ( V_7 , V_11 ) ;
F_5 ( & V_8 -> V_6 ) ;
V_23 -> V_51 |= V_91 ;
F_4 ( V_1 ) ;
F_65 ( V_23 ) ;
} else if ( F_58 ( V_59 ) == V_92 ) {
F_1 ( V_1 ) ;
F_75 ( V_23 , V_24 ) ;
V_19 -> V_66 . V_93 ++ ;
V_19 -> V_66 . V_94 += F_85 ( V_59 ) ;
V_86 = 0 ;
while ( F_86 ( V_11 , & V_87 , & V_86 ) ) {
F_3 ( & V_8 -> V_6 ) ;
F_74 ( V_7 , V_87 ) ;
F_5 ( & V_8 -> V_6 ) ;
}
V_23 -> V_51 |= V_91 ;
F_4 ( V_1 ) ;
F_65 ( V_23 ) ;
} else if ( F_58 ( V_59 ) == V_95 ) {
F_1 ( V_1 ) ;
F_75 ( V_23 , V_24 ) ;
F_87 ( & V_23 -> V_5 . V_96 , & V_11 ) ;
if ( F_37 ( ! V_11 && ! V_23 -> V_5 . V_96 ) ) {
F_4 ( V_1 ) ;
goto V_88;
}
V_19 -> V_66 . V_97 ++ ;
if ( V_11 ) {
V_19 -> V_66 . V_98 ++ ;
V_59 = F_47 ( V_11 ) ;
F_4 ( V_1 ) ;
goto V_90;
}
F_4 ( V_1 ) ;
F_65 ( V_23 ) ;
} else {
F_1 ( V_1 ) ;
F_75 ( V_23 , V_24 ) ;
F_4 ( V_1 ) ;
F_65 ( V_23 ) ;
F_42 ( V_11 ) ;
}
V_11 = NULL ;
F_63 ( V_23 ) ;
if ( F_37 ( ! F_59 ( V_23 ) ) )
goto V_88;
if ( V_23 -> V_5 . V_53 == V_23 -> V_5 . V_25 )
goto V_88;
if ( F_44 ( & V_23 -> V_5 . V_60 ) ) {
V_23 -> V_5 . V_54 = 1 ;
goto V_88;
}
V_59 = F_47 ( F_38 ( & V_23 -> V_5 . V_60 ) ) ;
V_24 = F_83 ( V_59 ) ;
V_84 = F_19 ( V_84 + 1 ) ;
if ( V_24 != V_84 )
goto V_88;
V_11 = F_88 ( & V_23 -> V_5 . V_60 ) ;
goto V_90;
}
if ( F_39 ( V_84 , V_24 ) ) {
V_85 = F_89 ( & V_23 -> V_5 . V_60 ,
V_11 ) ;
F_21 ( V_23 , V_24 ) ;
V_11 = NULL ;
}
F_1 ( V_1 ) ;
if ( V_85 )
V_19 -> V_66 . V_99 ++ ;
else
V_19 -> V_66 . V_100 ++ ;
F_4 ( V_1 ) ;
V_88:
F_65 ( V_23 ) ;
F_66 ( V_23 ) ;
exit:
F_42 ( V_11 ) ;
}
T_2 F_90 ( struct V_22 * V_44 )
{
return ( V_44 -> V_5 . V_47 &&
( F_20 ( V_44 -> V_1 ) != V_44 -> V_5 . V_45 ) ) ;
}
static int F_91 ( struct V_1 * V_1 , struct V_10 * V_11 ,
struct V_101 * V_102 ,
struct V_103 * V_104 )
{
int V_105 ;
struct V_58 * V_59 = F_47 ( V_11 ) ;
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
struct V_106 * V_107 = V_3 -> V_107 ;
struct V_76 * V_5 = V_3 -> V_5 ;
if ( F_69 ( ! F_92 ( F_47 ( V_11 ) ) ) ) {
F_11 ( V_11 , V_5 -> V_15 . V_16 ) ;
F_49 ( V_59 , 1 ) ;
F_50 ( V_59 , V_3 -> V_64 ) ;
V_3 -> V_19 -> V_66 . V_108 ++ ;
if ( F_93 ( ! V_5 -> V_15 . V_16 ) ) {
F_94 () ;
return 0 ;
}
}
V_107 -> V_109 = V_5 -> V_15 ;
for ( V_105 = 0 ; V_105 < V_65 ; V_105 ++ ) {
struct V_101 * V_110 = V_107 -> V_111 [ V_105 ] . V_112 ;
struct V_101 * V_113 = V_107 -> V_111 [ V_105 ] . V_114 ;
struct V_101 * V_115 [ 2 ] = { V_110 , V_113 } ;
struct V_101 * V_116 = V_115 [ F_95 ( V_59 ) ] ;
struct V_10 * V_117 ;
if ( ! V_110 )
break;
if ( ! V_116 )
V_116 = V_110 ;
F_96 ( & V_107 -> V_109 , & V_116 -> V_118 ,
& V_107 -> V_119 ) ;
if ( V_107 -> V_119 . V_16 == V_107 -> V_109 . V_16 )
continue;
if ( V_105 == 0 ) {
F_54 ( V_1 , V_116 -> V_120 , V_11 , & V_116 -> V_121 ) ;
} else {
V_117 = F_97 ( V_11 , V_122 ) ;
if ( ! V_117 )
break;
F_54 ( V_1 , V_116 -> V_120 , V_117 ,
& V_116 -> V_121 ) ;
F_42 ( V_117 ) ;
}
if ( V_107 -> V_119 . V_16 == 0 )
break;
V_107 -> V_109 = V_107 -> V_119 ;
}
return 0 ;
}
void F_98 ( struct V_1 * V_1 , struct V_123 * V_124 ,
T_2 V_23 , bool V_125 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
struct V_106 * V_107 = V_3 -> V_107 ;
struct V_126 * V_127 = V_107 -> V_128 ;
struct V_126 * V_129 ;
struct V_101 * V_116 ;
int V_130 ;
int V_131 ;
F_1 ( V_1 ) ;
if ( V_125 )
F_14 ( V_124 , V_23 ) ;
else
F_16 ( V_124 , V_23 ) ;
memset ( V_127 , 0 , sizeof( V_107 -> V_128 ) ) ;
F_99 () ;
for ( V_130 = 0 ; V_130 < V_65 ; V_130 ++ ) {
V_116 = F_100 ( V_3 -> V_132 [ V_130 ] ) ;
if ( ! V_116 || ! V_116 -> V_118 . V_16 )
continue;
if ( ! V_127 [ V_116 -> V_133 ] . V_112 )
V_127 [ V_116 -> V_133 ] . V_112 = V_116 ;
else
V_127 [ V_116 -> V_133 ] . V_114 = V_116 ;
}
F_101 () ;
V_129 = V_107 -> V_111 ;
memset ( V_107 -> V_111 , 0 , sizeof( V_107 -> V_111 ) ) ;
for ( V_131 = V_134 ; V_131 >= 0 ; V_131 -- ) {
if ( ! V_127 [ V_131 ] . V_112 )
continue;
V_129 -> V_112 = V_127 [ V_131 ] . V_112 ;
if ( V_127 [ V_131 ] . V_114 ) {
if ( F_102 ( & V_127 [ V_131 ] . V_112 -> V_118 ,
& V_127 [ V_131 ] . V_114 -> V_118 ) ) {
V_129 -> V_114 = V_127 [ V_131 ] . V_114 ;
} else {
V_129 ++ ;
V_129 -> V_112 = V_127 [ V_131 ] . V_114 ;
}
}
V_129 ++ ;
}
F_4 ( V_1 ) ;
}
static int F_103 ( struct V_10 * V_29 ,
struct V_135 * V_66 )
{
int V_136 ;
struct V_137 * V_138 ;
struct V_139 {
T_4 V_140 ;
T_4 V_141 ;
};
struct V_139 V_142 [] = {
{ V_143 , V_66 -> V_82 } ,
{ V_144 , V_66 -> V_97 } ,
{ V_145 , V_66 -> V_98 } ,
{ V_146 , V_66 -> V_93 } ,
{ V_147 , V_66 -> V_94 } ,
{ V_148 , V_66 -> V_108 } ,
{ V_149 , V_66 -> V_150 } ,
{ V_151 , V_66 -> V_152 } ,
{ V_153 , V_66 -> V_154 } ,
{ V_155 , V_66 -> V_156 } ,
{ V_157 , V_66 -> V_89 } ,
{ V_158 , V_66 -> V_99 } ,
{ V_159 , V_66 -> V_67 } ,
{ V_160 , V_66 -> V_83 } ,
{ V_161 , V_66 -> V_162 } ,
{ V_163 , V_66 -> V_100 } ,
{ V_164 , V_66 -> V_165 } ,
{ V_166 , V_66 -> V_167 } ,
{ V_168 , V_66 -> V_80 ?
( V_66 -> V_81 / V_66 -> V_80 ) : 0 }
} ;
V_138 = F_104 ( V_29 , V_169 ) ;
if ( ! V_138 )
return - V_170 ;
for ( V_136 = 0 ; V_136 < F_105 ( V_142 ) ; V_136 ++ )
if ( F_106 ( V_29 , V_142 [ V_136 ] . V_140 , V_142 [ V_136 ] . V_141 ) )
goto V_171;
F_107 ( V_29 , V_138 ) ;
return 0 ;
V_171:
F_108 ( V_29 , V_138 ) ;
return - V_170 ;
}
int F_109 ( struct V_1 * V_1 , struct V_172 * V_59 )
{
int V_173 ;
void * V_69 ;
struct V_137 * V_174 ;
struct V_137 * V_175 ;
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
struct V_18 * V_19 = V_3 -> V_19 ;
if ( ! V_19 )
return 0 ;
F_1 ( V_1 ) ;
V_69 = F_110 ( V_59 -> V_29 , V_59 -> V_176 , V_59 -> V_177 , & V_178 ,
V_179 , V_180 ) ;
if ( ! V_69 )
return - V_170 ;
V_174 = F_104 ( V_59 -> V_29 , V_181 ) ;
if ( ! V_174 )
goto V_171;
if ( F_111 ( V_59 -> V_29 , V_182 ) )
goto V_183;
if ( F_111 ( V_59 -> V_29 , V_184 ) )
goto V_183;
if ( F_112 ( V_59 -> V_29 , V_185 , V_19 -> V_186 ) )
goto V_183;
if ( F_106 ( V_59 -> V_29 , V_187 , V_19 -> V_188 ) )
goto V_183;
if ( F_106 ( V_59 -> V_29 , V_189 , V_19 -> V_21 ) )
goto V_183;
V_175 = F_104 ( V_59 -> V_29 , V_190 ) ;
if ( ! V_175 )
goto V_183;
if ( F_106 ( V_59 -> V_29 , V_191 , V_19 -> V_38 ) )
goto V_192;
F_107 ( V_59 -> V_29 , V_175 ) ;
V_173 = F_103 ( V_59 -> V_29 , & V_19 -> V_66 ) ;
if ( V_173 )
goto V_183;
F_4 ( V_1 ) ;
F_107 ( V_59 -> V_29 , V_174 ) ;
F_113 ( V_59 -> V_29 , V_69 ) ;
return 0 ;
V_192:
F_108 ( V_59 -> V_29 , V_175 ) ;
V_183:
F_108 ( V_59 -> V_29 , V_174 ) ;
V_171:
F_4 ( V_1 ) ;
F_114 ( V_59 -> V_29 , V_69 ) ;
return - V_170 ;
}
int F_115 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
struct V_18 * V_19 = V_3 -> V_19 ;
if ( ! V_19 )
return - V_193 ;
F_1 ( V_1 ) ;
memset ( & V_19 -> V_66 , 0 , sizeof( V_19 -> V_66 ) ) ;
F_4 ( V_1 ) ;
return 0 ;
}
int F_116 ( struct V_1 * V_1 , T_2 V_40 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
struct V_18 * V_19 = V_3 -> V_19 ;
if ( ! V_19 )
return - V_193 ;
if ( V_40 < V_194 )
V_40 = V_194 ;
if ( V_40 > V_195 )
return - V_196 ;
F_1 ( V_1 ) ;
F_117 ( V_19 , V_40 ) ;
F_4 ( V_1 ) ;
return 0 ;
}
int F_118 ( struct V_1 * V_1 , struct V_137 * V_174 [] )
{
int V_173 ;
T_2 V_197 ;
struct V_137 * V_198 [ V_199 + 1 ] ;
if ( ! V_174 [ V_190 ] )
return - V_196 ;
V_173 = F_119 ( V_174 [ V_190 ] , V_198 ) ;
if ( V_173 )
return V_173 ;
if ( ! V_198 [ V_191 ] )
return - V_200 ;
V_197 = F_120 ( V_198 [ V_191 ] ) ;
return F_116 ( V_1 , V_197 ) ;
}
int F_121 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
struct V_106 * V_107 ;
struct V_76 * V_5 ;
struct V_18 * V_19 ;
V_107 = F_122 ( sizeof( * V_107 ) , V_122 ) ;
if ( ! V_107 )
return - V_201 ;
V_5 = F_122 ( sizeof( * V_5 ) , V_122 ) ;
if ( ! V_5 ) {
F_123 ( V_107 ) ;
return - V_201 ;
}
V_19 = & V_5 -> V_17 ;
V_107 -> V_202 . V_203 = & V_107 -> V_203 ;
V_107 -> V_203 . V_204 = F_91 ;
sprintf ( V_107 -> V_203 . V_186 , L_1 ) ;
F_124 ( & V_5 -> V_6 ) ;
F_73 ( & V_19 -> V_48 ) ;
F_73 ( & V_19 -> V_50 ) ;
F_73 ( & V_19 -> V_60 ) ;
F_34 ( & V_19 -> V_43 ) ;
V_19 -> V_21 = 1 ;
F_124 ( & V_5 -> V_23 . V_6 ) ;
F_73 ( & V_5 -> V_7 ) ;
F_34 ( & V_5 -> V_8 ) ;
V_19 -> V_205 = & V_5 -> V_23 ;
V_19 -> V_205 -> V_1 = V_1 ;
V_19 -> V_206 = V_9 ;
F_117 ( V_19 , V_207 ) ;
V_19 -> V_208 = V_65 ;
F_125 ( V_3 -> V_132 [ V_65 ] , & V_107 -> V_202 ) ;
V_19 -> V_209 = (struct V_58 * ) & V_19 -> V_210 ;
F_126 ( V_19 -> V_209 , V_3 -> V_61 ) ;
F_127 ( V_19 -> V_186 , V_211 , V_212 ) ;
V_3 -> V_107 = V_107 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_19 = V_19 ;
return 0 ;
}
void F_128 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
F_1 ( V_1 ) ;
F_129 ( V_3 -> V_19 ) ;
F_4 ( V_1 ) ;
F_130 ( V_3 -> V_132 [ V_213 ] , NULL ) ;
F_131 () ;
F_123 ( V_3 -> V_107 ) ;
F_123 ( V_3 -> V_5 ) ;
}
static void F_14 ( struct V_123 * V_124 , T_2 V_23 )
{
int V_68 = V_22 ( V_23 ) ;
int V_214 = V_68 / V_215 ;
T_2 V_216 = ( 1 << ( V_68 % V_215 ) ) ;
if ( ( V_124 -> V_142 [ V_214 ] & V_216 ) == 0 ) {
V_124 -> V_16 ++ ;
V_124 -> V_142 [ V_214 ] |= V_216 ;
}
}
static void F_16 ( struct V_123 * V_124 , T_2 V_23 )
{
int V_68 = V_22 ( V_23 ) ;
int V_214 = V_68 / V_215 ;
T_2 V_216 = ( 1 << ( V_68 % V_215 ) ) ;
if ( ( V_124 -> V_142 [ V_214 ] & V_216 ) != 0 ) {
V_124 -> V_142 [ V_214 ] &= ~ V_216 ;
V_124 -> V_16 -- ;
}
}
static void F_96 ( struct V_123 * V_217 ,
struct V_123 * V_218 ,
struct V_123 * V_219 )
{
int V_220 = F_105 ( V_217 -> V_142 ) ;
int V_214 ;
int V_116 ;
T_2 V_142 ;
memset ( V_219 , 0 , sizeof( * V_219 ) ) ;
for ( V_214 = 0 ; V_214 < V_220 ; V_214 ++ ) {
V_142 = V_217 -> V_142 [ V_214 ] ^ ( V_217 -> V_142 [ V_214 ] & V_218 -> V_142 [ V_214 ] ) ;
V_219 -> V_142 [ V_214 ] = V_142 ;
if ( V_142 != 0 ) {
for ( V_116 = 0 ; V_116 < V_215 ; V_116 ++ ) {
if ( V_142 & ( 1 << V_116 ) )
V_219 -> V_16 ++ ;
}
}
}
}
