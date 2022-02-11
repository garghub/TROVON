int F_1 ( struct V_1 * V_2 , void * V_3 ,
T_1 V_4 , T_1 V_5 ,
T_1 V_6 , T_1 V_7 )
{
int V_8 = 0 ;
struct V_1 * V_9 = (struct V_1 * ) V_2 ;
struct V_10 * V_11 = NULL ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
T_2 V_16 ;
bool V_17 ;
struct V_18 * V_19 = V_9 -> V_19 ;
T_2 * V_20 = NULL ;
bool V_21 = false ;
T_3 V_22 = 0 ;
V_17 = ( V_4 == 0 ) ;
if ( ! V_3 || ! V_9 )
return - V_23 ;
if ( V_17 && F_2 ( V_9 -> V_24 ) )
return - V_25 ;
V_16 = V_9 -> V_26 ;
if ( V_16 != V_27 ) {
if ( V_16 & V_28 )
return - V_29 ;
if ( ( V_16 & V_30 ) &&
F_3 ( V_9 -> V_24 ) )
return - V_31 ;
F_4 ( 0 ) ;
}
V_15 = F_5 () ;
F_6 ( V_15 , & V_13 ) ;
if ( ! V_13 )
return - V_23 ;
if ( V_9 -> V_32 == V_33 && V_9 -> V_34 > 1 && V_3 ) {
if ( ! ( V_3 < ( void * ) V_35 ) ) {
V_20 = V_3 ;
goto V_36;
}
V_20 = F_7 ( V_5 , V_37 ) ;
if ( V_20 == NULL )
return - V_38 ;
if ( F_3 ( V_9 -> V_24 ) ) {
V_8 = F_8 ( V_20 , V_3 ,
V_5 ) ;
if ( V_8 ) {
F_9 ( V_20 ) ;
V_20 = NULL ;
return - V_23 ;
}
}
}
V_36:
F_10 ( & V_19 -> V_39 ) ;
F_11 ( V_13 -> V_40 , V_41 ) ;
if ( V_9 -> V_32 == V_33 ) {
if ( F_3 ( V_9 -> V_24 ) ) {
if ( V_4 > F_12 (
V_9 -> V_19 -> V_42 ) ) {
V_8 = - V_43 ;
goto V_44;
}
}
}
if ( F_13 ( & V_9 -> V_45 ) ) {
V_8 = - V_46 ;
goto V_44;
}
V_11 = F_14 ( & V_9 -> V_45 ,
struct V_10 , V_47 ) ;
F_15 ( & V_11 -> V_47 ) ;
V_11 -> V_48 = V_11 -> V_20 =
V_3 ;
if ( V_9 -> V_32 == V_33 && V_9 -> V_34 > 1 )
V_11 -> V_20 = V_20 ;
F_4 ( V_19 -> V_49 != 0 ) ;
V_11 -> V_50 = V_6 / V_19 -> V_49 ;
V_11 -> V_4 = V_4 ;
V_11 -> V_5 = V_5 ;
V_11 -> V_51 = V_7 ;
V_11 -> V_8 = ( V_17 ? V_52 :
V_53 ) ;
F_16 ( & V_11 -> V_47 , & V_9 -> V_54 ) ;
V_9 -> V_55 ++ ;
F_4 ( V_9 -> V_55 <= V_9 -> V_56 ) ;
if ( V_17 )
V_9 -> V_26 |= V_30 ;
F_4 ( V_9 -> V_32 == V_33 ) ;
F_17 ( V_19 -> V_42 , V_9 ,
( F_2 ( V_9 -> V_24 ) ? V_57 :
V_58 ) , & V_22 ) ;
V_21 = true ;
V_44:
F_18 ( V_13 -> V_40 , V_41 ) ;
F_19 ( & V_19 -> V_39 ) ;
if ( V_22 != 0 )
F_20 ( V_13 , V_22 ) ;
if ( V_21 )
F_21 ( V_19 -> V_42 ) ;
return V_8 ;
}
int F_22 ( struct V_1 * V_2 )
{
struct V_1 * V_9 = (struct V_1 * ) V_2 ;
T_1 V_34 = - 1 ;
T_4 V_24 ;
struct V_10 * V_59 , * V_60 ;
struct V_18 * V_19 = NULL ;
if ( ! V_9 || ! V_9 -> V_19 )
return - V_23 ;
V_34 = V_9 -> V_34 ;
V_24 = V_9 -> V_24 ;
V_19 = V_9 -> V_19 ;
F_10 ( & V_19 -> V_39 ) ;
V_9 -> V_26 |= V_28 ;
if ( F_13 ( & V_9 -> V_54 ) ) {
F_19 ( & V_19 -> V_39 ) ;
return 0 ;
}
if ( V_9 -> V_32 == V_33 ) {
if ( F_2 ( V_9 -> V_24 ) ) {
F_23 ( V_19 -> V_42 , V_34 ) ;
} else {
V_19 -> V_61 &= ~ ( 1 << V_34 ) ;
}
}
F_24 (chirp, tmp, &pchnl->io_requests, link) {
F_15 ( & V_59 -> V_47 ) ;
V_59 -> V_4 = 0 ;
V_59 -> V_8 |= V_62 ;
F_16 ( & V_59 -> V_47 , & V_9 -> V_63 ) ;
V_9 -> V_64 ++ ;
V_9 -> V_55 -- ;
F_4 ( V_9 -> V_55 >= 0 ) ;
}
F_19 ( & V_19 -> V_39 ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 )
{
int V_8 ;
struct V_1 * V_9 = (struct V_1 * ) V_2 ;
if ( ! V_9 )
return - V_23 ;
V_8 = F_22 ( V_2 ) ;
if ( V_8 )
return V_8 ;
F_4 ( ( V_9 -> V_26 & V_28 ) ) ;
V_9 -> V_19 -> V_65 [ V_9 -> V_34 ] = NULL ;
F_10 ( & V_9 -> V_19 -> V_39 ) ;
V_9 -> V_19 -> V_66 -= 1 ;
F_19 ( & V_9 -> V_19 -> V_39 ) ;
if ( V_9 -> V_67 ) {
F_26 ( V_9 -> V_67 ) ;
F_9 ( V_9 -> V_67 ) ;
V_9 -> V_67 = NULL ;
}
if ( V_9 -> V_68 ) {
F_27 ( V_9 -> V_68 ) ;
F_9 ( V_9 -> V_68 ) ;
V_9 -> V_68 = NULL ;
}
F_28 ( & V_9 -> V_63 ) ;
V_9 -> V_64 = 0 ;
F_28 ( & V_9 -> V_54 ) ;
V_9 -> V_55 = 0 ;
F_28 ( & V_9 -> V_45 ) ;
F_9 ( V_9 ) ;
return V_8 ;
}
int F_29 ( struct V_18 * * V_69 ,
struct V_14 * V_70 ,
const struct V_71 * V_72 )
{
int V_8 = 0 ;
struct V_18 * V_19 = NULL ;
T_2 V_73 ;
F_30 ( V_69 != NULL ) ;
F_30 ( V_72 != NULL ) ;
F_30 ( V_72 -> V_73 > 0 ) ;
F_30 ( V_72 -> V_73 <= V_74 ) ;
F_30 ( V_72 -> V_49 != 0 ) ;
V_19 = F_31 ( sizeof( struct V_18 ) , V_37 ) ;
if ( V_19 ) {
F_4 ( V_72 -> V_73 == V_74 ) ;
V_73 = V_74 + V_74 * V_33 ;
V_19 -> V_65 = F_31 ( sizeof( struct V_1 * )
* V_73 , V_37 ) ;
if ( V_19 -> V_65 ) {
V_19 -> type = V_75 ;
V_19 -> V_49 = V_72 -> V_49 ;
V_19 -> V_73 = V_73 ;
V_19 -> V_66 = 0 ;
V_19 -> V_61 = 0 ;
V_19 -> V_76 = 0 ;
V_19 -> V_15 = V_70 ;
F_32 ( & V_19 -> V_39 ) ;
} else {
V_8 = - V_38 ;
}
} else {
V_8 = - V_38 ;
}
if ( V_8 ) {
F_33 ( V_19 ) ;
* V_69 = NULL ;
} else {
* V_69 = V_19 ;
}
return V_8 ;
}
int F_33 ( struct V_18 * V_77 )
{
int V_8 = 0 ;
struct V_18 * V_19 = V_77 ;
T_1 V_34 ;
if ( V_77 ) {
for ( V_34 = 0 ; V_34 < V_19 -> V_73 ;
V_34 ++ ) {
V_8 =
F_25 ( V_19 -> V_65
[ V_34 ] ) ;
if ( V_8 )
F_34 ( V_78 , L_1 ,
V_79 , V_8 ) ;
}
F_9 ( V_19 -> V_65 ) ;
F_35 ( V_19 -> V_15 , NULL ) ;
F_9 ( V_77 ) ;
} else {
V_8 = - V_23 ;
}
return V_8 ;
}
int F_36 ( struct V_1 * V_2 , T_1 V_80 )
{
int V_8 = 0 ;
struct V_1 * V_9 = (struct V_1 * ) V_2 ;
T_4 V_24 = - 1 ;
struct V_18 * V_19 ;
struct V_81 V_82 ;
if ( V_9 ) {
if ( ( V_80 == V_83 )
&& F_3 ( V_9 -> V_24 ) ) {
V_8 = - V_43 ;
} else {
V_24 = V_9 -> V_24 ;
V_19 = V_9 -> V_19 ;
}
} else {
V_8 = - V_23 ;
}
if ( ! V_8 ) {
if ( F_3 ( V_24 )
&& ( V_9 -> V_32 == V_33 ) ) {
while ( ! F_13 ( & V_9 -> V_54 ) && ! V_8 ) {
V_8 = F_37 ( V_2 ,
V_80 , & V_82 ) ;
if ( V_8 )
continue;
if ( V_82 . V_8 & V_84 )
V_8 = - V_85 ;
}
} else {
V_8 = F_22 ( V_2 ) ;
V_9 -> V_26 &= ~ V_28 ;
}
}
F_38 ( V_8 || F_13 ( & V_9 -> V_54 ) ) ;
return V_8 ;
}
int F_39 ( struct V_1 * V_2 ,
struct V_86 * V_87 )
{
int V_8 = 0 ;
struct V_1 * V_9 = (struct V_1 * ) V_2 ;
if ( V_87 != NULL ) {
if ( V_9 ) {
V_87 -> V_18 = V_9 -> V_19 ;
V_87 -> V_88 = V_9 -> V_89 ;
V_87 -> V_90 = V_9 -> V_34 ;
V_87 -> V_91 = V_9 -> V_24 ;
V_87 -> V_92 = V_9 -> V_93 ;
V_87 -> V_94 = V_9 -> V_94 ;
V_87 -> V_68 = V_9 -> V_68 ;
V_87 -> V_64 = V_9 -> V_64 ;
V_87 -> V_55 = V_9 -> V_55 ;
V_87 -> V_26 = V_9 -> V_26 ;
} else {
V_8 = - V_23 ;
}
} else {
V_8 = - V_23 ;
}
return V_8 ;
}
int F_37 ( struct V_1 * V_2 , T_1 V_80 ,
struct V_81 * V_95 )
{
int V_8 = 0 ;
struct V_1 * V_9 = (struct V_1 * ) V_2 ;
struct V_10 * V_11 ;
int V_96 ;
bool V_97 = true ;
struct V_81 V_98 = { NULL , 0 , 0 , 0 , 0 } ;
T_2 * V_20 = NULL ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
if ( ! V_95 || ! V_9 ) {
V_8 = - V_23 ;
} else if ( V_80 == V_83 ) {
if ( F_13 ( & V_9 -> V_63 ) )
V_8 = - V_99 ;
}
V_15 = F_5 () ;
F_6 ( V_15 , & V_13 ) ;
if ( ! V_13 )
V_8 = - V_23 ;
if ( V_8 )
goto V_100;
V_98 . V_8 = V_53 ;
if ( V_80 !=
V_83 && F_13 ( & V_9 -> V_63 ) ) {
if ( V_80 == V_101 )
V_80 = V_102 ;
V_96 = F_40 ( V_9 -> V_68 , V_80 ) ;
if ( V_96 == - V_103 ) {
V_98 . V_8 |= V_84 ;
V_97 = false ;
} else if ( V_96 == - V_25 ) {
if ( F_13 ( & V_9 -> V_63 ) ) {
V_98 . V_8 |= V_62 ;
V_97 = false ;
}
}
}
F_10 ( & V_9 -> V_19 -> V_39 ) ;
F_11 ( V_13 -> V_40 , V_41 ) ;
if ( V_97 ) {
F_4 ( ! F_13 ( & V_9 -> V_63 ) ) ;
V_11 = F_14 ( & V_9 -> V_63 ,
struct V_10 , V_47 ) ;
F_15 ( & V_11 -> V_47 ) ;
V_9 -> V_64 -- ;
V_20 = V_11 -> V_20 ;
V_98 . V_104 = V_11 -> V_48 ;
V_98 . V_4 = V_11 -> V_4 ;
V_98 . V_5 = V_11 -> V_5 ;
V_98 . V_51 = V_11 -> V_51 ;
V_98 . V_8 |= V_11 -> V_8 ;
F_16 ( & V_11 -> V_47 ,
& V_9 -> V_45 ) ;
} else {
V_98 . V_104 = NULL ;
V_98 . V_4 = 0 ;
V_98 . V_51 = 0 ;
V_98 . V_5 = 0 ;
}
if ( ! F_13 ( & V_9 -> V_63 ) ) {
F_41 ( V_9 -> V_68 ) ;
} else {
F_27 ( V_9 -> V_68 ) ;
}
F_18 ( V_13 -> V_40 , V_41 ) ;
F_19 ( & V_9 -> V_19 -> V_39 ) ;
if ( V_97
&& ( V_9 -> V_32 == V_33 && V_9 -> V_34 > 1 ) ) {
if ( ! ( V_98 . V_104 < ( void * ) V_35 ) )
goto V_36;
if ( ! V_20 || ! V_98 . V_104 ) {
V_8 = - V_23 ;
goto V_36;
}
if ( ! F_2 ( V_9 -> V_24 ) )
goto V_105;
V_8 = F_42 ( V_98 . V_104 , V_20 , V_98 . V_4 ) ;
if ( V_8 ) {
if ( V_106 -> V_107 & V_108 )
V_8 = 0 ;
}
if ( V_8 )
V_8 = - V_23 ;
V_105:
F_9 ( V_20 ) ;
}
V_36:
* V_95 = V_98 ;
V_100:
return V_8 ;
}
int F_43 ( struct V_18 * V_77 , T_1 V_109 ,
struct V_110 * V_111 )
{
struct V_18 * V_19 = (struct V_18 * ) V_77 ;
if ( ! V_111 || ! V_77 )
return - V_23 ;
if ( V_109 > V_74 )
return - V_112 ;
V_111 -> V_2 = V_19 -> V_65 [ V_109 ] ;
V_111 -> V_66 = V_19 -> V_66 ;
V_111 -> type = V_19 -> type ;
V_111 -> V_73 = V_19 -> V_73 ;
return 0 ;
}
int F_44 ( struct V_1 * V_2 , T_1 V_80 ,
bool V_113 )
{
T_4 V_24 ;
struct V_18 * V_19 ;
int V_8 = 0 ;
F_30 ( V_2 ) ;
V_24 = V_2 -> V_24 ;
V_19 = V_2 -> V_19 ;
if ( F_3 ( V_24 ) && ! V_113 ) {
V_8 = F_36 ( V_2 , V_80 ) ;
} else {
V_8 = F_22 ( V_2 ) ;
V_2 -> V_93 = 0 ;
V_2 -> V_26 &= ~ V_28 ;
}
return V_8 ;
}
int F_45 ( struct V_1 * * V_114 ,
struct V_18 * V_77 , T_4 V_24 ,
T_1 V_109 , const struct V_115 * V_116 )
{
int V_8 = 0 ;
struct V_18 * V_19 = V_77 ;
struct V_1 * V_9 = NULL ;
struct V_117 * V_68 = NULL ;
F_30 ( V_114 != NULL ) ;
F_30 ( V_116 != NULL ) ;
F_30 ( V_77 != NULL ) ;
* V_114 = NULL ;
if ( ! V_116 -> V_118 )
return - V_43 ;
if ( ! V_77 )
return - V_23 ;
if ( V_109 != V_119 ) {
if ( V_109 >= V_19 -> V_73 )
return - V_112 ;
if ( V_19 -> V_65 [ V_109 ] != NULL )
return - V_120 ;
} else {
V_8 = F_46 ( V_19 , & V_109 ) ;
if ( V_8 )
return V_8 ;
}
F_4 ( V_109 < V_19 -> V_73 ) ;
V_9 = F_31 ( sizeof( struct V_1 ) , V_37 ) ;
if ( ! V_9 )
return - V_38 ;
V_9 -> V_26 = V_28 ;
V_8 = F_47 ( & V_9 -> V_45 ,
V_116 -> V_118 ) ;
if ( V_8 )
goto V_121;
F_48 ( & V_9 -> V_54 ) ;
F_48 ( & V_9 -> V_63 ) ;
V_9 -> V_56 = V_116 -> V_118 ;
V_9 -> V_64 = 0 ;
V_9 -> V_55 = 0 ;
V_68 = F_31 ( sizeof( struct V_117 ) , V_37 ) ;
if ( ! V_68 ) {
V_8 = - V_38 ;
goto V_121;
}
F_49 ( V_68 ) ;
V_9 -> V_67 = F_7 ( sizeof( struct V_122 ) , V_37 ) ;
if ( ! V_9 -> V_67 ) {
V_8 = - V_38 ;
goto V_121;
}
F_50 ( V_9 -> V_67 ) ;
V_9 -> V_19 = V_19 ;
V_9 -> V_34 = V_109 ;
V_9 -> V_24 = V_24 ;
V_9 -> V_89 = V_68 ;
V_9 -> V_68 = V_68 ;
V_9 -> V_94 = V_106 -> V_123 ;
V_9 -> V_124 = 0 ;
V_9 -> V_93 = 0 ;
V_9 -> V_32 = V_33 ;
V_19 -> V_65 [ V_9 -> V_34 ] = V_9 ;
F_10 ( & V_19 -> V_39 ) ;
V_19 -> V_66 ++ ;
F_19 ( & V_19 -> V_39 ) ;
V_9 -> V_26 = V_27 ;
* V_114 = V_9 ;
return V_8 ;
V_121:
F_28 ( & V_9 -> V_63 ) ;
F_28 ( & V_9 -> V_54 ) ;
F_28 ( & V_9 -> V_45 ) ;
F_9 ( V_68 ) ;
if ( V_9 -> V_67 ) {
F_26 ( V_9 -> V_67 ) ;
F_9 ( V_9 -> V_67 ) ;
V_9 -> V_67 = NULL ;
}
F_9 ( V_9 ) ;
return V_8 ;
}
int F_51 ( struct V_1 * V_2 ,
T_1 V_125 , T_1 V_126 ,
struct V_127 * V_128 )
{
int V_8 = 0 ;
F_4 ( ! ( V_125 & ~ ( V_129 | V_130 ) ) ) ;
if ( V_125 )
V_8 = F_52 ( V_2 -> V_67 , V_128 ,
V_125 , V_126 ) ;
else
V_8 = F_53 ( V_2 -> V_67 , V_128 ) ;
return V_8 ;
}
static int F_47 ( struct V_131 * V_132 , T_1 V_133 )
{
struct V_10 * V_59 ;
T_1 V_134 ;
F_48 ( V_132 ) ;
for ( V_134 = 0 ; V_134 < V_133 ; V_134 ++ ) {
V_59 = F_31 ( sizeof( struct V_10 ) , V_37 ) ;
if ( ! V_59 )
break;
F_16 ( & V_59 -> V_47 , V_132 ) ;
}
if ( V_134 != V_133 ) {
F_28 ( V_132 ) ;
return - V_38 ;
}
return 0 ;
}
static void F_28 ( struct V_131 * V_135 )
{
struct V_10 * V_59 , * V_60 ;
F_30 ( V_135 != NULL ) ;
F_24 (chirp, tmp, chirp_list, link) {
F_15 ( & V_59 -> V_47 ) ;
F_9 ( V_59 ) ;
}
}
static int F_46 ( struct V_18 * V_19 ,
T_1 * V_114 )
{
int V_8 = - V_136 ;
T_1 V_134 ;
F_30 ( V_19 ) ;
for ( V_134 = 0 ; V_134 < V_19 -> V_73 ; V_134 ++ ) {
if ( V_19 -> V_65 [ V_134 ] == NULL ) {
V_8 = 0 ;
* V_114 = V_134 ;
break;
}
}
return V_8 ;
}
