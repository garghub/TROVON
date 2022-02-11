static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
F_3 ( & V_3 -> V_5 -> V_6 ) ;
}
static void F_4 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
struct V_7 * V_8 = NULL ;
if ( F_5 ( ! V_3 -> V_5 -> V_9 ) ) {
F_6 ( & V_3 -> V_5 -> V_6 ) ;
return;
}
if ( V_3 -> V_5 -> V_9 & V_10 ) {
V_3 -> V_5 -> V_9 &= ~ V_10 ;
V_8 = F_7 ( V_1 ) ;
}
F_6 ( & V_3 -> V_5 -> V_6 ) ;
if ( V_8 )
F_8 ( V_8 ) ;
}
void F_9 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
F_10 ( V_1 , & V_3 -> V_5 -> V_11 , & V_3 -> V_5 -> V_12 ) ;
}
T_1 F_11 ( void )
{
return V_13 ;
}
void F_12 ( struct V_1 * V_1 , unsigned int V_9 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
V_3 -> V_5 -> V_9 |= V_9 ;
}
static T_2 F_13 ( struct V_14 * V_15 )
{
return ( T_2 ) ( unsigned long ) F_14 ( V_15 ) -> V_16 ;
}
static void F_15 ( struct V_14 * V_15 , T_2 V_17 )
{
F_14 ( V_15 ) -> V_16 = ( void * ) ( unsigned long ) V_17 ;
}
static void F_16 ( struct V_14 * V_15 )
{
F_15 ( V_15 , F_13 ( V_15 ) - 1 ) ;
}
void F_17 ( struct V_1 * V_1 , T_2 V_18 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
F_1 ( V_1 ) ;
F_18 ( & V_3 -> V_5 -> V_19 , V_18 ) ;
F_4 ( V_1 ) ;
}
void F_19 ( struct V_1 * V_1 , T_2 V_18 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
F_1 ( V_1 ) ;
F_20 ( & V_3 -> V_5 -> V_19 , V_18 ) ;
F_4 ( V_1 ) ;
}
static void F_21 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
struct V_20 * V_21 = V_3 -> V_21 ;
if ( V_21 -> V_22 )
V_21 -> V_23 = F_22 ( F_23 ( V_21 -> V_22 ) - 1 ) ;
else
V_21 -> V_23 = F_22 ( V_21 -> V_24 - 1 ) ;
}
T_2 F_24 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
return V_3 -> V_21 -> V_23 ;
}
static void F_25 ( struct V_7 * V_8 , T_2 V_25 )
{
V_8 -> V_5 . V_26 = F_26 ( V_8 -> V_5 . V_26 , V_25 ) ?
V_25 : V_8 -> V_5 . V_26 ;
}
struct V_7 * F_7 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
return V_3 -> V_5 -> V_27 ;
}
static void F_27 ( struct V_2 * V_3 , T_2 V_28 , T_2 V_29 )
{
struct V_14 * V_30 ;
struct V_20 * V_21 = V_3 -> V_21 ;
F_28 (&bcl->outqueue, skb) {
if ( F_29 ( F_23 ( V_30 ) , V_28 ) ) {
F_30 ( V_21 , V_30 , F_22 ( V_29 - V_28 ) ) ;
break;
}
}
}
void F_31 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
F_32 ( V_1 , & V_3 -> V_5 -> V_31 . V_32 ) ;
}
void F_33 ( struct V_7 * V_33 , T_2 V_34 )
{
struct V_14 * V_30 , * V_35 ;
struct V_14 * V_36 ;
unsigned int V_37 = 0 ;
struct V_1 * V_1 = V_33 -> V_1 ;
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
F_1 ( V_1 ) ;
V_30 = F_34 ( & V_3 -> V_21 -> V_38 ) ;
if ( ! V_30 )
goto exit;
if ( V_34 == V_39 ) {
if ( V_3 -> V_5 -> V_19 . V_40 )
V_34 = V_3 -> V_21 -> V_23 ;
else
V_34 = V_3 -> V_21 -> V_24 ;
} else {
if ( F_35 ( V_34 , F_23 ( V_30 ) ) ||
F_35 ( V_3 -> V_21 -> V_23 , V_34 ) ||
F_26 ( V_34 , V_33 -> V_5 . V_34 ) )
goto exit;
}
F_28 (&tn->bcl->outqueue, skb) {
if ( F_29 ( F_23 ( V_30 ) , V_33 -> V_5 . V_34 ) )
break;
}
F_36 (&tn->bcl->outqueue, skb, tmp) {
if ( F_29 ( F_23 ( V_30 ) , V_34 ) )
break;
V_36 = F_37 ( & V_3 -> V_21 -> V_38 , V_30 ) ;
if ( V_30 != V_3 -> V_21 -> V_22 ) {
F_16 ( V_30 ) ;
} else {
F_15 ( V_30 , 0 ) ;
V_3 -> V_21 -> V_22 = V_36 ;
F_21 ( V_1 ) ;
}
if ( F_13 ( V_30 ) == 0 ) {
F_38 ( V_30 , & V_3 -> V_21 -> V_38 ) ;
F_39 ( V_30 ) ;
V_37 = 1 ;
}
}
V_33 -> V_5 . V_34 = V_34 ;
if ( F_40 ( V_3 -> V_21 -> V_22 ) ) {
F_41 ( V_3 -> V_21 ) ;
F_21 ( V_1 ) ;
}
if ( F_40 ( V_37 && ! F_42 ( & V_3 -> V_21 -> V_32 ) ) )
V_33 -> V_41 |= V_42 ;
exit:
F_4 ( V_1 ) ;
}
void F_43 ( struct V_7 * V_33 ,
T_2 V_26 )
{
struct V_14 * V_15 ;
struct V_1 * V_1 = V_33 -> V_1 ;
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
if ( F_26 ( V_26 , V_33 -> V_5 . V_43 ) )
return;
F_25 ( V_33 , V_26 ) ;
if ( V_33 -> V_5 . V_26 == V_33 -> V_5 . V_43 )
return;
if ( ( ++ V_33 -> V_5 . V_44 ) == 1 ) {
if ( V_33 -> V_5 . V_45 < ( V_46 / 2 ) )
return;
V_33 -> V_5 . V_44 ++ ;
}
if ( V_33 -> V_5 . V_44 & 0x1 )
return;
V_15 = F_44 ( V_47 ) ;
if ( V_15 ) {
struct V_48 * V_49 = F_45 ( V_15 ) ;
struct V_14 * V_30 = F_34 ( & V_33 -> V_5 . V_50 ) ;
T_2 V_29 = V_30 ? F_23 ( V_30 ) - 1 : V_33 -> V_5 . V_26 ;
F_46 ( V_3 -> V_51 , V_49 , V_52 , V_53 ,
V_47 , V_33 -> V_18 ) ;
F_47 ( V_49 , 1 ) ;
F_48 ( V_49 , V_3 -> V_54 ) ;
F_49 ( V_49 , V_33 -> V_5 . V_43 ) ;
F_50 ( V_49 , V_33 -> V_5 . V_43 ) ;
F_51 ( V_49 , V_29 ) ;
F_1 ( V_1 ) ;
F_52 ( V_1 , V_55 , V_15 , NULL ) ;
V_3 -> V_21 -> V_56 . V_57 ++ ;
F_4 ( V_1 ) ;
F_39 ( V_15 ) ;
V_33 -> V_5 . V_44 ++ ;
}
}
static void F_53 ( struct V_1 * V_1 , struct V_48 * V_49 )
{
struct V_7 * V_33 = F_54 ( V_1 , F_55 ( V_49 ) ) ;
if ( F_40 ( ! V_33 ) )
return;
F_56 ( V_33 ) ;
if ( V_33 -> V_5 . V_58 &&
( V_33 -> V_5 . V_43 != V_33 -> V_5 . V_26 ) &&
( V_33 -> V_5 . V_43 == F_57 ( V_49 ) ) )
V_33 -> V_5 . V_44 = 2 ;
F_58 ( V_33 ) ;
}
int F_59 ( struct V_1 * V_1 , struct V_59 * V_60 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_61 * V_5 = V_3 -> V_5 ;
int V_62 = 0 ;
int V_63 = 0 ;
struct V_14 * V_30 ;
struct V_59 V_11 ;
struct V_59 V_12 ;
V_30 = F_60 ( V_60 ) ;
if ( F_40 ( ! V_30 ) ) {
F_61 ( V_60 ) ;
return - V_64 ;
}
if ( F_5 ( V_5 ) ) {
F_1 ( V_1 ) ;
if ( F_5 ( V_5 -> V_19 . V_40 ) ) {
V_62 = F_62 ( V_1 , V_21 , V_60 ) ;
if ( F_5 ( ! V_62 ) ) {
T_2 V_65 = F_63 ( & V_21 -> V_38 ) ;
F_21 ( V_1 ) ;
V_21 -> V_56 . V_66 ++ ;
V_21 -> V_56 . V_67 += V_65 ;
}
V_63 = 1 ;
}
F_4 ( V_1 ) ;
}
if ( F_40 ( ! V_63 ) )
F_61 ( V_60 ) ;
if ( F_40 ( V_62 ) ) {
F_39 ( V_30 ) ;
return V_62 ;
}
F_64 ( & V_11 ) ;
F_65 ( & V_12 ) ;
F_66 ( & V_11 , V_30 ) ;
F_10 ( V_1 , & V_11 , & V_12 ) ;
return V_62 ;
}
static void F_67 ( struct V_7 * V_8 , T_2 V_25 )
{
struct V_2 * V_3 = F_2 ( V_8 -> V_1 , V_4 ) ;
F_25 ( V_8 , V_25 ) ;
V_8 -> V_5 . V_43 = V_25 ;
V_8 -> V_5 . V_44 = 0 ;
V_3 -> V_21 -> V_56 . V_68 ++ ;
if ( ( ( V_25 - V_3 -> V_51 ) % V_46 ) == 0 ) {
F_68 ( V_8 -> V_69 [ V_8 -> V_18 & 1 ] ,
V_53 , 0 , 0 , 0 , 0 , 0 ) ;
V_3 -> V_21 -> V_56 . V_70 ++ ;
}
}
void F_69 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_48 * V_49 = F_45 ( V_15 ) ;
struct V_7 * V_8 ;
T_2 V_71 ;
T_2 V_25 ;
int V_72 = 0 ;
int V_73 = 0 ;
struct V_14 * V_74 ;
struct V_59 * V_11 , * V_12 ;
if ( F_70 ( V_49 ) != V_3 -> V_54 )
goto exit;
V_8 = F_54 ( V_1 , F_71 ( V_49 ) ) ;
if ( F_40 ( ! V_8 ) )
goto exit;
F_56 ( V_8 ) ;
if ( F_40 ( ! V_8 -> V_5 . V_58 ) )
goto V_75;
if ( F_40 ( F_72 ( V_49 ) == V_52 ) ) {
if ( F_73 ( V_49 ) != V_53 )
goto V_75;
if ( F_55 ( V_49 ) == V_3 -> V_51 ) {
F_33 ( V_8 , F_74 ( V_49 ) ) ;
F_58 ( V_8 ) ;
F_1 ( V_1 ) ;
V_21 -> V_56 . V_76 ++ ;
V_3 -> V_5 -> V_27 = V_8 ;
F_27 ( V_3 , F_57 ( V_49 ) ,
F_75 ( V_49 ) ) ;
F_4 ( V_1 ) ;
} else {
F_58 ( V_8 ) ;
F_53 ( V_1 , V_49 ) ;
}
goto exit;
}
V_25 = F_76 ( V_49 ) ;
V_71 = F_22 ( V_8 -> V_5 . V_43 + 1 ) ;
V_11 = & V_3 -> V_5 -> V_11 ;
V_12 = & V_3 -> V_5 -> V_12 ;
if ( F_5 ( V_25 == V_71 ) ) {
V_77:
if ( F_5 ( F_77 ( V_49 ) ) ) {
F_1 ( V_1 ) ;
F_67 ( V_8 , V_25 ) ;
F_3 ( & V_12 -> V_6 ) ;
F_66 ( V_11 , V_15 ) ;
F_6 ( & V_12 -> V_6 ) ;
V_8 -> V_41 |= V_78 ;
F_4 ( V_1 ) ;
F_58 ( V_8 ) ;
} else if ( F_72 ( V_49 ) == V_79 ) {
F_1 ( V_1 ) ;
F_67 ( V_8 , V_25 ) ;
V_21 -> V_56 . V_80 ++ ;
V_21 -> V_56 . V_81 += F_78 ( V_49 ) ;
V_73 = 0 ;
while ( F_79 ( V_15 , & V_74 , & V_73 ) ) {
F_3 ( & V_12 -> V_6 ) ;
F_66 ( V_11 , V_74 ) ;
F_6 ( & V_12 -> V_6 ) ;
}
V_8 -> V_41 |= V_78 ;
F_4 ( V_1 ) ;
F_58 ( V_8 ) ;
} else if ( F_72 ( V_49 ) == V_82 ) {
F_80 ( & V_8 -> V_5 . V_83 , & V_15 ) ;
if ( F_40 ( ! V_15 && ! V_8 -> V_5 . V_83 ) )
goto V_75;
F_1 ( V_1 ) ;
F_67 ( V_8 , V_25 ) ;
V_21 -> V_56 . V_84 ++ ;
if ( V_15 ) {
V_21 -> V_56 . V_85 ++ ;
V_49 = F_45 ( V_15 ) ;
F_4 ( V_1 ) ;
goto V_77;
}
F_4 ( V_1 ) ;
F_58 ( V_8 ) ;
} else {
F_1 ( V_1 ) ;
F_67 ( V_8 , V_25 ) ;
F_4 ( V_1 ) ;
F_58 ( V_8 ) ;
F_39 ( V_15 ) ;
}
V_15 = NULL ;
F_56 ( V_8 ) ;
if ( F_40 ( ! F_81 ( V_8 ) ) )
goto V_75;
if ( V_8 -> V_5 . V_43 == V_8 -> V_5 . V_26 )
goto V_75;
if ( F_42 ( & V_8 -> V_5 . V_50 ) ) {
V_8 -> V_5 . V_44 = 1 ;
goto V_75;
}
V_49 = F_45 ( F_34 ( & V_8 -> V_5 . V_50 ) ) ;
V_25 = F_76 ( V_49 ) ;
V_71 = F_22 ( V_71 + 1 ) ;
if ( V_25 != V_71 )
goto V_75;
V_15 = F_82 ( & V_8 -> V_5 . V_50 ) ;
goto V_77;
}
if ( F_35 ( V_71 , V_25 ) ) {
V_72 = F_83 ( & V_8 -> V_5 . V_50 ,
V_15 ) ;
F_25 ( V_8 , V_25 ) ;
V_15 = NULL ;
}
F_1 ( V_1 ) ;
if ( V_72 )
V_21 -> V_56 . V_86 ++ ;
else
V_21 -> V_56 . V_87 ++ ;
F_4 ( V_1 ) ;
V_75:
F_58 ( V_8 ) ;
exit:
F_39 ( V_15 ) ;
}
T_2 F_84 ( struct V_7 * V_33 )
{
return ( V_33 -> V_5 . V_58 &&
( F_24 ( V_33 -> V_1 ) != V_33 -> V_5 . V_34 ) ) ;
}
static int F_85 ( struct V_1 * V_1 , struct V_14 * V_15 ,
struct V_88 * V_89 ,
struct V_90 * V_91 )
{
int V_92 ;
struct V_48 * V_49 = F_45 ( V_15 ) ;
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
struct V_93 * V_94 = V_3 -> V_94 ;
struct V_61 * V_5 = V_3 -> V_5 ;
if ( F_5 ( ! F_86 ( F_45 ( V_15 ) ) ) ) {
F_15 ( V_15 , V_5 -> V_19 . V_40 ) ;
F_47 ( V_49 , 1 ) ;
F_48 ( V_49 , V_3 -> V_54 ) ;
V_3 -> V_21 -> V_56 . V_95 ++ ;
if ( F_87 ( ! V_5 -> V_19 . V_40 ) ) {
F_88 () ;
return 0 ;
}
}
V_94 -> V_96 = V_5 -> V_19 ;
for ( V_92 = 0 ; V_92 < V_55 ; V_92 ++ ) {
struct V_88 * V_97 = V_94 -> V_98 [ V_92 ] . V_99 ;
struct V_88 * V_100 = V_94 -> V_98 [ V_92 ] . V_101 ;
struct V_88 * V_102 [ 2 ] = { V_97 , V_100 } ;
struct V_88 * V_103 = V_102 [ F_89 ( V_49 ) ] ;
struct V_14 * V_104 ;
if ( ! V_97 )
break;
if ( ! V_103 )
V_103 = V_97 ;
F_90 ( & V_94 -> V_96 , & V_103 -> V_105 ,
& V_94 -> V_106 ) ;
if ( V_94 -> V_106 . V_40 == V_94 -> V_96 . V_40 )
continue;
if ( V_92 == 0 ) {
F_52 ( V_1 , V_103 -> V_107 , V_15 , & V_103 -> V_108 ) ;
} else {
V_104 = F_91 ( V_15 , V_109 ) ;
if ( ! V_104 )
break;
F_52 ( V_1 , V_103 -> V_107 , V_104 ,
& V_103 -> V_108 ) ;
F_39 ( V_104 ) ;
}
if ( V_94 -> V_106 . V_40 == 0 )
break;
V_94 -> V_96 = V_94 -> V_106 ;
}
return 0 ;
}
void F_92 ( struct V_1 * V_1 , struct V_110 * V_111 ,
T_2 V_8 , bool V_112 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
struct V_93 * V_94 = V_3 -> V_94 ;
struct V_113 * V_114 = V_94 -> V_115 ;
struct V_113 * V_116 ;
struct V_88 * V_103 ;
int V_117 ;
int V_118 ;
F_1 ( V_1 ) ;
if ( V_112 )
F_18 ( V_111 , V_8 ) ;
else
F_20 ( V_111 , V_8 ) ;
memset ( V_114 , 0 , sizeof( V_94 -> V_115 ) ) ;
F_93 () ;
for ( V_117 = 0 ; V_117 < V_55 ; V_117 ++ ) {
V_103 = F_94 ( V_3 -> V_119 [ V_117 ] ) ;
if ( ! V_103 || ! V_103 -> V_105 . V_40 )
continue;
if ( ! V_114 [ V_103 -> V_120 ] . V_99 )
V_114 [ V_103 -> V_120 ] . V_99 = V_103 ;
else
V_114 [ V_103 -> V_120 ] . V_101 = V_103 ;
}
F_95 () ;
V_116 = V_94 -> V_98 ;
memset ( V_94 -> V_98 , 0 , sizeof( V_94 -> V_98 ) ) ;
for ( V_118 = V_121 ; V_118 >= 0 ; V_118 -- ) {
if ( ! V_114 [ V_118 ] . V_99 )
continue;
V_116 -> V_99 = V_114 [ V_118 ] . V_99 ;
if ( V_114 [ V_118 ] . V_101 ) {
if ( F_96 ( & V_114 [ V_118 ] . V_99 -> V_105 ,
& V_114 [ V_118 ] . V_101 -> V_105 ) ) {
V_116 -> V_101 = V_114 [ V_118 ] . V_101 ;
} else {
V_116 ++ ;
V_116 -> V_99 = V_114 [ V_118 ] . V_101 ;
}
}
V_116 ++ ;
}
F_4 ( V_1 ) ;
}
static int F_97 ( struct V_14 * V_30 ,
struct V_122 * V_56 )
{
int V_123 ;
struct V_124 * V_125 ;
struct V_126 {
T_3 V_127 ;
T_3 V_128 ;
};
struct V_126 V_129 [] = {
{ V_130 , V_56 -> V_68 } ,
{ V_131 , V_56 -> V_84 } ,
{ V_132 , V_56 -> V_85 } ,
{ V_133 , V_56 -> V_80 } ,
{ V_134 , V_56 -> V_81 } ,
{ V_135 , V_56 -> V_95 } ,
{ V_136 , V_56 -> V_137 } ,
{ V_138 , V_56 -> V_139 } ,
{ V_140 , V_56 -> V_141 } ,
{ V_142 , V_56 -> V_143 } ,
{ V_144 , V_56 -> V_76 } ,
{ V_145 , V_56 -> V_86 } ,
{ V_146 , V_56 -> V_57 } ,
{ V_147 , V_56 -> V_70 } ,
{ V_148 , V_56 -> V_149 } ,
{ V_150 , V_56 -> V_87 } ,
{ V_151 , V_56 -> V_152 } ,
{ V_153 , V_56 -> V_154 } ,
{ V_155 , V_56 -> V_66 ?
( V_56 -> V_67 / V_56 -> V_66 ) : 0 }
} ;
V_125 = F_98 ( V_30 , V_156 ) ;
if ( ! V_125 )
return - V_157 ;
for ( V_123 = 0 ; V_123 < F_99 ( V_129 ) ; V_123 ++ )
if ( F_100 ( V_30 , V_129 [ V_123 ] . V_127 , V_129 [ V_123 ] . V_128 ) )
goto V_158;
F_101 ( V_30 , V_125 ) ;
return 0 ;
V_158:
F_102 ( V_30 , V_125 ) ;
return - V_157 ;
}
int F_103 ( struct V_1 * V_1 , struct V_159 * V_49 )
{
int V_160 ;
void * V_161 ;
struct V_124 * V_162 ;
struct V_124 * V_163 ;
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
struct V_20 * V_21 = V_3 -> V_21 ;
if ( ! V_21 )
return 0 ;
F_1 ( V_1 ) ;
V_161 = F_104 ( V_49 -> V_30 , V_49 -> V_164 , V_49 -> V_165 , & V_166 ,
V_167 , V_168 ) ;
if ( ! V_161 )
return - V_157 ;
V_162 = F_98 ( V_49 -> V_30 , V_169 ) ;
if ( ! V_162 )
goto V_158;
if ( F_105 ( V_49 -> V_30 , V_170 ) )
goto V_171;
if ( F_105 ( V_49 -> V_30 , V_172 ) )
goto V_171;
if ( F_106 ( V_49 -> V_30 , V_173 , V_21 -> V_174 ) )
goto V_171;
if ( F_100 ( V_49 -> V_30 , V_175 , V_21 -> V_176 ) )
goto V_171;
if ( F_100 ( V_49 -> V_30 , V_177 , V_21 -> V_24 ) )
goto V_171;
V_163 = F_98 ( V_49 -> V_30 , V_178 ) ;
if ( ! V_163 )
goto V_171;
if ( F_100 ( V_49 -> V_30 , V_179 , V_21 -> V_180 [ 0 ] ) )
goto V_181;
F_101 ( V_49 -> V_30 , V_163 ) ;
V_160 = F_97 ( V_49 -> V_30 , & V_21 -> V_56 ) ;
if ( V_160 )
goto V_171;
F_4 ( V_1 ) ;
F_101 ( V_49 -> V_30 , V_162 ) ;
F_107 ( V_49 -> V_30 , V_161 ) ;
return 0 ;
V_181:
F_102 ( V_49 -> V_30 , V_163 ) ;
V_171:
F_102 ( V_49 -> V_30 , V_162 ) ;
V_158:
F_4 ( V_1 ) ;
F_108 ( V_49 -> V_30 , V_161 ) ;
return - V_157 ;
}
int F_109 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
struct V_20 * V_21 = V_3 -> V_21 ;
if ( ! V_21 )
return - V_182 ;
F_1 ( V_1 ) ;
memset ( & V_21 -> V_56 , 0 , sizeof( V_21 -> V_56 ) ) ;
F_4 ( V_1 ) ;
return 0 ;
}
int F_110 ( struct V_1 * V_1 , T_2 V_183 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
struct V_20 * V_21 = V_3 -> V_21 ;
if ( ! V_21 )
return - V_182 ;
if ( ( V_183 < V_46 ) || ( V_183 > V_184 ) )
return - V_185 ;
F_1 ( V_1 ) ;
F_111 ( V_21 , V_183 ) ;
F_4 ( V_1 ) ;
return 0 ;
}
int F_112 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
struct V_93 * V_94 ;
struct V_61 * V_5 ;
struct V_20 * V_21 ;
V_94 = F_113 ( sizeof( * V_94 ) , V_109 ) ;
if ( ! V_94 )
return - V_186 ;
V_5 = F_113 ( sizeof( * V_5 ) , V_109 ) ;
if ( ! V_5 ) {
F_114 ( V_94 ) ;
return - V_186 ;
}
V_21 = & V_5 -> V_31 ;
V_94 -> V_187 . V_188 = & V_94 -> V_188 ;
V_94 -> V_188 . V_189 = F_85 ;
sprintf ( V_94 -> V_188 . V_174 , L_1 ) ;
F_115 ( & V_5 -> V_6 ) ;
F_64 ( & V_21 -> V_38 ) ;
F_64 ( & V_21 -> V_50 ) ;
F_65 ( & V_21 -> V_32 ) ;
V_21 -> V_24 = 1 ;
F_115 ( & V_5 -> V_8 . V_6 ) ;
F_64 ( & V_5 -> V_11 ) ;
F_65 ( & V_5 -> V_12 ) ;
V_21 -> V_190 = & V_5 -> V_8 ;
V_21 -> V_190 -> V_1 = V_1 ;
V_21 -> V_191 = V_13 ;
F_111 ( V_21 , V_192 ) ;
V_21 -> V_193 = V_55 ;
F_116 ( V_3 -> V_119 [ V_55 ] , & V_94 -> V_187 ) ;
V_21 -> V_194 = V_195 ;
V_21 -> V_196 = (struct V_48 * ) & V_21 -> V_197 ;
F_117 ( V_21 -> V_196 , V_3 -> V_51 ) ;
F_118 ( V_21 -> V_174 , V_198 , V_199 ) ;
V_3 -> V_94 = V_94 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_21 = V_21 ;
return 0 ;
}
void F_119 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
F_1 ( V_1 ) ;
F_120 ( V_3 -> V_21 ) ;
F_4 ( V_1 ) ;
F_121 ( V_3 -> V_119 [ V_200 ] , NULL ) ;
F_122 () ;
F_114 ( V_3 -> V_94 ) ;
F_114 ( V_3 -> V_5 ) ;
}
static void F_18 ( struct V_110 * V_111 , T_2 V_8 )
{
int V_201 = V_7 ( V_8 ) ;
int V_202 = V_201 / V_203 ;
T_2 V_204 = ( 1 << ( V_201 % V_203 ) ) ;
if ( ( V_111 -> V_129 [ V_202 ] & V_204 ) == 0 ) {
V_111 -> V_40 ++ ;
V_111 -> V_129 [ V_202 ] |= V_204 ;
}
}
static void F_20 ( struct V_110 * V_111 , T_2 V_8 )
{
int V_201 = V_7 ( V_8 ) ;
int V_202 = V_201 / V_203 ;
T_2 V_204 = ( 1 << ( V_201 % V_203 ) ) ;
if ( ( V_111 -> V_129 [ V_202 ] & V_204 ) != 0 ) {
V_111 -> V_129 [ V_202 ] &= ~ V_204 ;
V_111 -> V_40 -- ;
}
}
static void F_90 ( struct V_110 * V_205 ,
struct V_110 * V_206 ,
struct V_110 * V_207 )
{
int V_208 = F_99 ( V_205 -> V_129 ) ;
int V_202 ;
int V_103 ;
T_2 V_129 ;
memset ( V_207 , 0 , sizeof( * V_207 ) ) ;
for ( V_202 = 0 ; V_202 < V_208 ; V_202 ++ ) {
V_129 = V_205 -> V_129 [ V_202 ] ^ ( V_205 -> V_129 [ V_202 ] & V_206 -> V_129 [ V_202 ] ) ;
V_207 -> V_129 [ V_202 ] = V_129 ;
if ( V_129 != 0 ) {
for ( V_103 = 0 ; V_103 < V_203 ; V_103 ++ ) {
if ( V_129 & ( 1 << V_103 ) )
V_207 -> V_40 ++ ;
}
}
}
}
