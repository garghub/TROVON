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
}
V_15 = F_4 () ;
F_5 ( V_15 , & V_13 ) ;
if ( ! V_13 )
return - V_23 ;
if ( V_9 -> V_32 == V_33 && V_9 -> V_34 > 1 && V_3 ) {
if ( ! ( V_3 < ( void * ) V_35 ) ) {
V_20 = V_3 ;
goto V_36;
}
V_20 = F_6 ( V_5 , V_37 ) ;
if ( V_20 == NULL )
return - V_38 ;
if ( F_3 ( V_9 -> V_24 ) ) {
V_8 = F_7 ( V_20 , V_3 ,
V_5 ) ;
if ( V_8 ) {
F_8 ( V_20 ) ;
V_20 = NULL ;
return - V_23 ;
}
}
}
V_36:
F_9 ( & V_19 -> V_39 ) ;
F_10 ( V_13 -> V_40 , V_41 ) ;
if ( V_9 -> V_32 == V_33 ) {
if ( F_3 ( V_9 -> V_24 ) ) {
if ( V_4 > F_11 (
V_9 -> V_19 -> V_42 ) ) {
V_8 = - V_43 ;
goto V_44;
}
}
}
if ( F_12 ( & V_9 -> V_45 ) ) {
V_8 = - V_46 ;
goto V_44;
}
V_11 = F_13 ( & V_9 -> V_45 ,
struct V_10 , V_47 ) ;
F_14 ( & V_11 -> V_47 ) ;
V_11 -> V_48 = V_11 -> V_20 =
V_3 ;
if ( V_9 -> V_32 == V_33 && V_9 -> V_34 > 1 )
V_11 -> V_20 = V_20 ;
V_11 -> V_49 = V_6 / V_19 -> V_50 ;
V_11 -> V_4 = V_4 ;
V_11 -> V_5 = V_5 ;
V_11 -> V_51 = V_7 ;
V_11 -> V_8 = ( V_17 ? V_52 :
V_53 ) ;
F_15 ( & V_11 -> V_47 , & V_9 -> V_54 ) ;
V_9 -> V_55 ++ ;
if ( V_17 )
V_9 -> V_26 |= V_30 ;
F_16 ( V_19 -> V_42 , V_9 ,
( F_2 ( V_9 -> V_24 ) ? V_56 :
V_57 ) , & V_22 ) ;
V_21 = true ;
V_44:
F_17 ( V_13 -> V_40 , V_41 ) ;
F_18 ( & V_19 -> V_39 ) ;
if ( V_22 != 0 )
F_19 ( V_13 , V_22 ) ;
if ( V_21 )
F_20 ( V_19 -> V_42 ) ;
return V_8 ;
}
int F_21 ( struct V_1 * V_2 )
{
struct V_1 * V_9 = (struct V_1 * ) V_2 ;
T_1 V_34 = - 1 ;
T_4 V_24 ;
struct V_10 * V_58 , * V_59 ;
struct V_18 * V_19 = NULL ;
if ( ! V_9 || ! V_9 -> V_19 )
return - V_23 ;
V_34 = V_9 -> V_34 ;
V_24 = V_9 -> V_24 ;
V_19 = V_9 -> V_19 ;
F_9 ( & V_19 -> V_39 ) ;
V_9 -> V_26 |= V_28 ;
if ( F_12 ( & V_9 -> V_54 ) ) {
F_18 ( & V_19 -> V_39 ) ;
return 0 ;
}
if ( V_9 -> V_32 == V_33 ) {
if ( F_2 ( V_9 -> V_24 ) ) {
F_22 ( V_19 -> V_42 , V_34 ) ;
} else {
V_19 -> V_60 &= ~ ( 1 << V_34 ) ;
}
}
F_23 (chirp, tmp, &pchnl->io_requests, link) {
F_14 ( & V_58 -> V_47 ) ;
V_58 -> V_4 = 0 ;
V_58 -> V_8 |= V_61 ;
F_15 ( & V_58 -> V_47 , & V_9 -> V_62 ) ;
V_9 -> V_63 ++ ;
V_9 -> V_55 -- ;
}
F_18 ( & V_19 -> V_39 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 )
{
int V_8 ;
struct V_1 * V_9 = (struct V_1 * ) V_2 ;
if ( ! V_9 )
return - V_23 ;
V_8 = F_21 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_9 -> V_19 -> V_64 [ V_9 -> V_34 ] = NULL ;
F_9 ( & V_9 -> V_19 -> V_39 ) ;
V_9 -> V_19 -> V_65 -= 1 ;
F_18 ( & V_9 -> V_19 -> V_39 ) ;
if ( V_9 -> V_66 ) {
F_25 ( V_9 -> V_66 ) ;
F_8 ( V_9 -> V_66 ) ;
V_9 -> V_66 = NULL ;
}
if ( V_9 -> V_67 ) {
F_26 ( V_9 -> V_67 ) ;
F_8 ( V_9 -> V_67 ) ;
V_9 -> V_67 = NULL ;
}
F_27 ( & V_9 -> V_62 ) ;
V_9 -> V_63 = 0 ;
F_27 ( & V_9 -> V_54 ) ;
V_9 -> V_55 = 0 ;
F_27 ( & V_9 -> V_45 ) ;
F_8 ( V_9 ) ;
return V_8 ;
}
int F_28 ( struct V_18 * * V_68 ,
struct V_14 * V_69 ,
const struct V_70 * V_71 )
{
int V_8 = 0 ;
struct V_18 * V_19 = NULL ;
T_2 V_72 ;
V_19 = F_29 ( sizeof( struct V_18 ) , V_37 ) ;
if ( V_19 ) {
V_72 = V_73 + V_73 * V_33 ;
V_19 -> V_64 = F_29 ( sizeof( struct V_1 * )
* V_72 , V_37 ) ;
if ( V_19 -> V_64 ) {
V_19 -> type = V_74 ;
V_19 -> V_50 = V_71 -> V_50 ;
V_19 -> V_72 = V_72 ;
V_19 -> V_65 = 0 ;
V_19 -> V_60 = 0 ;
V_19 -> V_75 = 0 ;
V_19 -> V_15 = V_69 ;
F_30 ( & V_19 -> V_39 ) ;
} else {
V_8 = - V_38 ;
}
} else {
V_8 = - V_38 ;
}
if ( V_8 ) {
F_31 ( V_19 ) ;
* V_68 = NULL ;
} else {
* V_68 = V_19 ;
}
return V_8 ;
}
int F_31 ( struct V_18 * V_76 )
{
int V_8 = 0 ;
struct V_18 * V_19 = V_76 ;
T_1 V_34 ;
if ( V_76 ) {
for ( V_34 = 0 ; V_34 < V_19 -> V_72 ;
V_34 ++ ) {
V_8 =
F_24 ( V_19 -> V_64
[ V_34 ] ) ;
if ( V_8 )
F_32 ( V_77 , L_1 ,
V_78 , V_8 ) ;
}
F_8 ( V_19 -> V_64 ) ;
F_33 ( V_19 -> V_15 , NULL ) ;
F_8 ( V_76 ) ;
} else {
V_8 = - V_23 ;
}
return V_8 ;
}
int F_34 ( struct V_1 * V_2 , T_1 V_79 )
{
int V_8 = 0 ;
struct V_1 * V_9 = (struct V_1 * ) V_2 ;
T_4 V_24 = - 1 ;
struct V_18 * V_19 ;
struct V_80 V_81 ;
if ( V_9 ) {
if ( ( V_79 == V_82 )
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
while ( ! F_12 ( & V_9 -> V_54 ) && ! V_8 ) {
V_8 = F_35 ( V_2 ,
V_79 , & V_81 ) ;
if ( V_8 )
continue;
if ( V_81 . V_8 & V_83 )
V_8 = - V_84 ;
}
} else {
V_8 = F_21 ( V_2 ) ;
V_9 -> V_26 &= ~ V_28 ;
}
}
return V_8 ;
}
int F_36 ( struct V_1 * V_2 ,
struct V_85 * V_86 )
{
int V_8 = 0 ;
struct V_1 * V_9 = (struct V_1 * ) V_2 ;
if ( V_86 != NULL ) {
if ( V_9 ) {
V_86 -> V_18 = V_9 -> V_19 ;
V_86 -> V_87 = V_9 -> V_88 ;
V_86 -> V_89 = V_9 -> V_34 ;
V_86 -> V_90 = V_9 -> V_24 ;
V_86 -> V_91 = V_9 -> V_92 ;
V_86 -> V_93 = V_9 -> V_93 ;
V_86 -> V_67 = V_9 -> V_67 ;
V_86 -> V_63 = V_9 -> V_63 ;
V_86 -> V_55 = V_9 -> V_55 ;
V_86 -> V_26 = V_9 -> V_26 ;
} else {
V_8 = - V_23 ;
}
} else {
V_8 = - V_23 ;
}
return V_8 ;
}
int F_35 ( struct V_1 * V_2 , T_1 V_79 ,
struct V_80 * V_94 )
{
int V_8 = 0 ;
struct V_1 * V_9 = (struct V_1 * ) V_2 ;
struct V_10 * V_11 ;
int V_95 ;
bool V_96 = true ;
struct V_80 V_97 = { NULL , 0 , 0 , 0 , 0 } ;
T_2 * V_20 = NULL ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
if ( ! V_94 || ! V_9 ) {
V_8 = - V_23 ;
} else if ( V_79 == V_82 ) {
if ( F_12 ( & V_9 -> V_62 ) )
V_8 = - V_98 ;
}
V_15 = F_4 () ;
F_5 ( V_15 , & V_13 ) ;
if ( ! V_13 )
V_8 = - V_23 ;
if ( V_8 )
goto V_99;
V_97 . V_8 = V_53 ;
if ( V_79 !=
V_82 && F_12 ( & V_9 -> V_62 ) ) {
if ( V_79 == V_100 )
V_79 = V_101 ;
V_95 = F_37 ( V_9 -> V_67 , V_79 ) ;
if ( V_95 == - V_102 ) {
V_97 . V_8 |= V_83 ;
V_96 = false ;
} else if ( V_95 == - V_25 ) {
if ( F_12 ( & V_9 -> V_62 ) ) {
V_97 . V_8 |= V_61 ;
V_96 = false ;
}
}
}
F_9 ( & V_9 -> V_19 -> V_39 ) ;
F_10 ( V_13 -> V_40 , V_41 ) ;
if ( V_96 ) {
V_11 = F_13 ( & V_9 -> V_62 ,
struct V_10 , V_47 ) ;
F_14 ( & V_11 -> V_47 ) ;
V_9 -> V_63 -- ;
V_20 = V_11 -> V_20 ;
V_97 . V_103 = V_11 -> V_48 ;
V_97 . V_4 = V_11 -> V_4 ;
V_97 . V_5 = V_11 -> V_5 ;
V_97 . V_51 = V_11 -> V_51 ;
V_97 . V_8 |= V_11 -> V_8 ;
F_15 ( & V_11 -> V_47 ,
& V_9 -> V_45 ) ;
} else {
V_97 . V_103 = NULL ;
V_97 . V_4 = 0 ;
V_97 . V_51 = 0 ;
V_97 . V_5 = 0 ;
}
if ( ! F_12 ( & V_9 -> V_62 ) ) {
F_38 ( V_9 -> V_67 ) ;
} else {
F_26 ( V_9 -> V_67 ) ;
}
F_17 ( V_13 -> V_40 , V_41 ) ;
F_18 ( & V_9 -> V_19 -> V_39 ) ;
if ( V_96
&& ( V_9 -> V_32 == V_33 && V_9 -> V_34 > 1 ) ) {
if ( ! ( V_97 . V_103 < ( void * ) V_35 ) )
goto V_36;
if ( ! V_20 || ! V_97 . V_103 ) {
V_8 = - V_23 ;
goto V_36;
}
if ( ! F_2 ( V_9 -> V_24 ) )
goto V_104;
V_8 = F_39 ( V_97 . V_103 , V_20 , V_97 . V_4 ) ;
if ( V_8 ) {
if ( V_105 -> V_106 & V_107 )
V_8 = 0 ;
}
if ( V_8 )
V_8 = - V_23 ;
V_104:
F_8 ( V_20 ) ;
}
V_36:
* V_94 = V_97 ;
V_99:
return V_8 ;
}
int F_40 ( struct V_18 * V_76 , T_1 V_108 ,
struct V_109 * V_110 )
{
struct V_18 * V_19 = (struct V_18 * ) V_76 ;
if ( ! V_110 || ! V_76 )
return - V_23 ;
if ( V_108 > V_73 )
return - V_111 ;
V_110 -> V_2 = V_19 -> V_64 [ V_108 ] ;
V_110 -> V_65 = V_19 -> V_65 ;
V_110 -> type = V_19 -> type ;
V_110 -> V_72 = V_19 -> V_72 ;
return 0 ;
}
int F_41 ( struct V_1 * V_2 , T_1 V_79 ,
bool V_112 )
{
T_4 V_24 ;
struct V_18 * V_19 ;
int V_8 = 0 ;
V_24 = V_2 -> V_24 ;
V_19 = V_2 -> V_19 ;
if ( F_3 ( V_24 ) && ! V_112 ) {
V_8 = F_34 ( V_2 , V_79 ) ;
} else {
V_8 = F_21 ( V_2 ) ;
V_2 -> V_92 = 0 ;
V_2 -> V_26 &= ~ V_28 ;
}
return V_8 ;
}
int F_42 ( struct V_1 * * V_113 ,
struct V_18 * V_76 , T_4 V_24 ,
T_1 V_108 , const struct V_114 * V_115 )
{
int V_8 = 0 ;
struct V_18 * V_19 = V_76 ;
struct V_1 * V_9 = NULL ;
struct V_116 * V_67 = NULL ;
* V_113 = NULL ;
if ( ! V_115 -> V_117 )
return - V_43 ;
if ( ! V_76 )
return - V_23 ;
if ( V_108 != V_118 ) {
if ( V_108 >= V_19 -> V_72 )
return - V_111 ;
if ( V_19 -> V_64 [ V_108 ] != NULL )
return - V_119 ;
} else {
V_8 = F_43 ( V_19 , & V_108 ) ;
if ( V_8 )
return V_8 ;
}
V_9 = F_29 ( sizeof( struct V_1 ) , V_37 ) ;
if ( ! V_9 )
return - V_38 ;
V_9 -> V_26 = V_28 ;
V_8 = F_44 ( & V_9 -> V_45 ,
V_115 -> V_117 ) ;
if ( V_8 )
goto V_120;
F_45 ( & V_9 -> V_54 ) ;
F_45 ( & V_9 -> V_62 ) ;
V_9 -> V_121 = V_115 -> V_117 ;
V_9 -> V_63 = 0 ;
V_9 -> V_55 = 0 ;
V_67 = F_29 ( sizeof( struct V_116 ) , V_37 ) ;
if ( ! V_67 ) {
V_8 = - V_38 ;
goto V_120;
}
F_46 ( V_67 ) ;
V_9 -> V_66 = F_6 ( sizeof( struct V_122 ) , V_37 ) ;
if ( ! V_9 -> V_66 ) {
V_8 = - V_38 ;
goto V_120;
}
F_47 ( V_9 -> V_66 ) ;
V_9 -> V_19 = V_19 ;
V_9 -> V_34 = V_108 ;
V_9 -> V_24 = V_24 ;
V_9 -> V_88 = V_67 ;
V_9 -> V_67 = V_67 ;
V_9 -> V_93 = V_105 -> V_123 ;
V_9 -> V_124 = 0 ;
V_9 -> V_92 = 0 ;
V_9 -> V_32 = V_33 ;
V_19 -> V_64 [ V_9 -> V_34 ] = V_9 ;
F_9 ( & V_19 -> V_39 ) ;
V_19 -> V_65 ++ ;
F_18 ( & V_19 -> V_39 ) ;
V_9 -> V_26 = V_27 ;
* V_113 = V_9 ;
return V_8 ;
V_120:
F_27 ( & V_9 -> V_62 ) ;
F_27 ( & V_9 -> V_54 ) ;
F_27 ( & V_9 -> V_45 ) ;
F_8 ( V_67 ) ;
if ( V_9 -> V_66 ) {
F_25 ( V_9 -> V_66 ) ;
F_8 ( V_9 -> V_66 ) ;
V_9 -> V_66 = NULL ;
}
F_8 ( V_9 ) ;
return V_8 ;
}
int F_48 ( struct V_1 * V_2 ,
T_1 V_125 , T_1 V_126 ,
struct V_127 * V_128 )
{
int V_8 = 0 ;
if ( V_125 )
V_8 = F_49 ( V_2 -> V_66 , V_128 ,
V_125 , V_126 ) ;
else
V_8 = F_50 ( V_2 -> V_66 , V_128 ) ;
return V_8 ;
}
static int F_44 ( struct V_129 * V_130 , T_1 V_131 )
{
struct V_10 * V_58 ;
T_1 V_132 ;
F_45 ( V_130 ) ;
for ( V_132 = 0 ; V_132 < V_131 ; V_132 ++ ) {
V_58 = F_29 ( sizeof( struct V_10 ) , V_37 ) ;
if ( ! V_58 )
break;
F_15 ( & V_58 -> V_47 , V_130 ) ;
}
if ( V_132 != V_131 ) {
F_27 ( V_130 ) ;
return - V_38 ;
}
return 0 ;
}
static void F_27 ( struct V_129 * V_133 )
{
struct V_10 * V_58 , * V_59 ;
F_23 (chirp, tmp, chirp_list, link) {
F_14 ( & V_58 -> V_47 ) ;
F_8 ( V_58 ) ;
}
}
static int F_43 ( struct V_18 * V_19 ,
T_1 * V_113 )
{
int V_8 = - V_134 ;
T_1 V_132 ;
for ( V_132 = 0 ; V_132 < V_19 -> V_72 ; V_132 ++ ) {
if ( V_19 -> V_64 [ V_132 ] == NULL ) {
V_8 = 0 ;
* V_113 = V_132 ;
break;
}
}
return V_8 ;
}
