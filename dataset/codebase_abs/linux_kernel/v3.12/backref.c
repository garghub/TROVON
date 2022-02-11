static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
T_1 V_7 ,
struct V_8 * * V_9 )
{
T_1 V_10 = 0 ;
struct V_8 * V_11 ;
if ( ! F_2 ( V_4 , V_6 ) &&
! F_3 ( V_4 , V_6 ) &&
! F_4 ( V_4 , V_6 ) ) {
T_1 V_12 ;
T_1 V_13 ;
V_12 = F_5 ( V_4 , V_6 ) ;
V_13 = F_6 ( V_4 , V_6 ) ;
if ( V_7 < V_12 ||
V_7 >= V_12 + V_13 )
return 1 ;
V_10 = V_7 - V_12 ;
}
V_11 = F_7 ( sizeof( * V_11 ) , V_14 ) ;
if ( ! V_11 )
return - V_15 ;
V_11 -> V_16 = * V_9 ;
V_11 -> V_17 = V_2 -> V_18 ;
V_11 -> V_10 = V_2 -> V_10 + V_10 ;
* V_9 = V_11 ;
return 0 ;
}
static int F_8 ( struct V_3 * V_4 , T_1 V_19 ,
T_1 V_7 ,
struct V_8 * * V_9 )
{
T_1 V_20 ;
struct V_1 V_2 ;
struct V_5 * V_6 ;
int V_21 ;
int V_22 ;
int V_23 ;
int V_24 ;
V_22 = F_9 ( V_4 ) ;
for ( V_21 = 0 ; V_21 < V_22 ; ++ V_21 ) {
F_10 ( V_4 , & V_2 , V_21 ) ;
if ( V_2 . type != V_25 )
continue;
V_6 = F_11 ( V_4 , V_21 , struct V_5 ) ;
V_23 = F_12 ( V_4 , V_6 ) ;
if ( V_23 == V_26 )
continue;
V_20 = F_13 ( V_4 , V_6 ) ;
if ( V_20 != V_19 )
continue;
V_24 = F_1 ( & V_2 , V_4 , V_6 , V_7 , V_9 ) ;
if ( V_24 < 0 )
return V_24 ;
}
return 0 ;
}
int T_2 F_14 ( void )
{
V_27 = F_15 ( L_1 ,
sizeof( struct V_28 ) ,
0 ,
V_29 | V_30 ,
NULL ) ;
if ( ! V_27 )
return - V_15 ;
return 0 ;
}
void F_16 ( void )
{
if ( V_27 )
F_17 ( V_27 ) ;
}
static int F_18 ( struct V_31 * V_32 , T_1 V_33 ,
struct V_1 * V_2 , int V_34 ,
T_1 V_35 , T_1 V_19 , int V_36 ,
T_3 V_37 )
{
struct V_28 * V_38 ;
V_38 = F_19 ( V_27 , V_37 ) ;
if ( ! V_38 )
return - V_15 ;
V_38 -> V_33 = V_33 ;
if ( V_2 )
V_38 -> V_39 = * V_2 ;
else
memset ( & V_38 -> V_39 , 0 , sizeof( V_38 -> V_39 ) ) ;
V_38 -> V_40 = NULL ;
V_38 -> V_34 = V_34 ;
V_38 -> V_36 = V_36 ;
V_38 -> V_35 = V_35 ;
V_38 -> V_19 = V_19 ;
F_20 ( & V_38 -> V_41 , V_32 ) ;
return 0 ;
}
static int F_21 ( struct V_42 * V_43 , struct V_44 * V_45 ,
struct V_46 * V_47 , int V_34 ,
struct V_1 * V_39 , T_1 V_48 ,
T_1 V_19 ,
const T_1 * V_7 )
{
int V_24 = 0 ;
int V_21 ;
struct V_3 * V_4 ;
struct V_1 V_2 ;
struct V_5 * V_6 ;
struct V_8 * V_9 = NULL , * V_49 = NULL ;
T_1 V_20 ;
if ( V_34 != 0 ) {
V_4 = V_45 -> V_50 [ V_34 ] ;
V_24 = F_22 ( V_47 , V_4 -> V_51 , 0 , V_14 ) ;
if ( V_24 < 0 )
return V_24 ;
return 0 ;
}
if ( V_45 -> V_52 [ 0 ] >= F_9 ( V_45 -> V_50 [ 0 ] ) )
V_24 = F_23 ( V_43 , V_45 , V_48 ) ;
while ( ! V_24 ) {
V_4 = V_45 -> V_50 [ 0 ] ;
V_21 = V_45 -> V_52 [ 0 ] ;
F_10 ( V_4 , & V_2 , V_21 ) ;
if ( V_2 . V_18 != V_39 -> V_18 ||
V_2 . type != V_25 )
break;
V_6 = F_11 ( V_4 , V_21 , struct V_5 ) ;
V_20 = F_13 ( V_4 , V_6 ) ;
if ( V_20 == V_19 ) {
V_9 = NULL ;
V_49 = NULL ;
if ( V_7 ) {
V_24 = F_1 ( & V_2 , V_4 , V_6 ,
* V_7 ,
& V_9 ) ;
if ( V_24 < 0 )
break;
}
if ( V_24 > 0 )
goto V_16;
V_24 = F_24 ( V_47 , V_4 -> V_51 ,
( V_53 ) V_9 ,
( T_1 * ) & V_49 , V_14 ) ;
if ( V_24 < 0 )
break;
if ( ! V_24 && V_7 ) {
while ( V_49 -> V_16 )
V_49 = V_49 -> V_16 ;
V_49 -> V_16 = V_9 ;
}
}
V_16:
V_24 = F_25 ( V_43 , V_45 , V_48 ) ;
}
if ( V_24 > 0 )
V_24 = 0 ;
return V_24 ;
}
static int F_26 ( struct V_54 * V_55 ,
struct V_44 * V_45 , T_1 V_48 ,
struct V_28 * V_38 ,
struct V_46 * V_47 ,
const T_1 * V_7 )
{
struct V_42 * V_43 ;
struct V_1 V_56 ;
struct V_3 * V_4 ;
int V_24 = 0 ;
int V_57 ;
int V_34 = V_38 -> V_34 ;
V_56 . V_18 = V_38 -> V_33 ;
V_56 . type = V_58 ;
V_56 . V_10 = ( T_1 ) - 1 ;
V_43 = F_27 ( V_55 , & V_56 ) ;
if ( F_28 ( V_43 ) ) {
V_24 = F_29 ( V_43 ) ;
goto V_59;
}
V_57 = F_30 ( V_43 , V_48 ) ;
if ( V_57 + 1 == V_34 )
goto V_59;
V_45 -> V_60 = V_34 ;
V_24 = F_31 ( V_43 , & V_38 -> V_39 , V_45 , V_48 ) ;
F_32 ( L_2
L_3 ,
V_38 -> V_33 , V_34 , V_38 -> V_36 , V_24 ,
V_38 -> V_39 . V_18 , V_38 -> V_39 . type ,
V_38 -> V_39 . V_10 ) ;
if ( V_24 < 0 )
goto V_59;
V_4 = V_45 -> V_50 [ V_34 ] ;
while ( ! V_4 ) {
if ( ! V_34 ) {
F_33 ( 1 ) ;
V_24 = 1 ;
goto V_59;
}
V_34 -- ;
V_4 = V_45 -> V_50 [ V_34 ] ;
}
V_24 = F_21 ( V_43 , V_45 , V_47 , V_34 , & V_38 -> V_39 ,
V_48 , V_38 -> V_19 ,
V_7 ) ;
V_59:
V_45 -> V_60 = 0 ;
F_34 ( V_45 ) ;
return V_24 ;
}
static int F_35 ( struct V_54 * V_55 ,
struct V_44 * V_45 , T_1 V_48 ,
struct V_31 * V_32 ,
const T_1 * V_7 )
{
int V_61 ;
int V_24 = 0 ;
struct V_28 * V_38 ;
struct V_28 * V_62 ;
struct V_28 * V_63 ;
struct V_46 * V_47 ;
struct V_64 * V_65 ;
struct V_66 V_67 ;
V_47 = F_36 ( V_14 ) ;
if ( ! V_47 )
return - V_15 ;
F_37 (ref, ref_safe, head, list) {
if ( V_38 -> V_35 )
continue;
if ( V_38 -> V_36 == 0 )
continue;
V_61 = F_26 ( V_55 , V_45 , V_48 , V_38 ,
V_47 , V_7 ) ;
if ( V_61 == - V_15 )
goto V_59;
if ( V_61 )
continue;
F_38 ( & V_67 ) ;
V_65 = F_39 ( V_47 , & V_67 ) ;
V_38 -> V_35 = V_65 ? V_65 -> V_68 : 0 ;
V_38 -> V_40 = V_65 ?
(struct V_8 * ) ( V_53 ) V_65 -> V_69 : NULL ;
while ( ( V_65 = F_39 ( V_47 , & V_67 ) ) ) {
V_63 = F_19 ( V_27 ,
V_14 ) ;
if ( ! V_63 ) {
V_24 = - V_15 ;
goto V_59;
}
memcpy ( V_63 , V_38 , sizeof( * V_38 ) ) ;
V_63 -> V_35 = V_65 -> V_68 ;
V_63 -> V_40 = (struct V_8 * )
( V_53 ) V_65 -> V_69 ;
F_40 ( & V_63 -> V_41 , & V_38 -> V_41 ) ;
}
F_41 ( V_47 ) ;
}
V_59:
F_42 ( V_47 ) ;
return V_24 ;
}
static inline int F_43 ( struct V_28 * V_70 ,
struct V_28 * V_71 )
{
if ( V_70 -> V_34 != V_71 -> V_34 )
return 0 ;
if ( V_70 -> V_33 != V_71 -> V_33 )
return 0 ;
if ( V_70 -> V_39 . type != V_71 -> V_39 . type )
return 0 ;
if ( V_70 -> V_39 . V_18 != V_71 -> V_39 . V_18 )
return 0 ;
if ( V_70 -> V_39 . V_10 != V_71 -> V_39 . V_10 )
return 0 ;
if ( V_70 -> V_35 != V_71 -> V_35 )
return 0 ;
return 1 ;
}
static int F_44 ( struct V_54 * V_55 ,
struct V_31 * V_32 )
{
struct V_31 * V_72 ;
struct V_3 * V_4 ;
F_45 (pos, head) {
struct V_28 * V_38 ;
V_38 = F_46 ( V_72 , struct V_28 , V_41 ) ;
if ( V_38 -> V_35 )
continue;
if ( V_38 -> V_39 . type )
continue;
F_47 ( ! V_38 -> V_19 ) ;
V_4 = F_48 ( V_55 -> V_73 , V_38 -> V_19 ,
V_55 -> V_73 -> V_74 , 0 ) ;
if ( ! V_4 || ! F_49 ( V_4 ) ) {
F_50 ( V_4 ) ;
return - V_75 ;
}
F_51 ( V_4 ) ;
if ( F_52 ( V_4 ) == 0 )
F_10 ( V_4 , & V_38 -> V_39 , 0 ) ;
else
F_53 ( V_4 , & V_38 -> V_39 , 0 ) ;
F_54 ( V_4 ) ;
F_50 ( V_4 ) ;
}
return 0 ;
}
static void F_55 ( struct V_31 * V_32 , int V_76 )
{
struct V_31 * V_77 ;
F_45 (pos1, head) {
struct V_31 * V_78 ;
struct V_31 * V_79 ;
struct V_28 * V_70 ;
V_70 = F_46 ( V_77 , struct V_28 , V_41 ) ;
for ( V_79 = V_77 -> V_16 , V_78 = V_79 -> V_16 ; V_79 != V_32 ;
V_79 = V_78 , V_78 = V_79 -> V_16 ) {
struct V_28 * V_71 ;
struct V_28 * V_80 ;
struct V_8 * V_9 ;
V_71 = F_46 ( V_79 , struct V_28 , V_41 ) ;
if ( V_76 == 1 ) {
if ( ! F_43 ( V_70 , V_71 ) )
continue;
if ( ! V_70 -> V_35 && V_71 -> V_35 ) {
V_80 = V_70 ;
V_70 = V_71 ;
V_71 = V_80 ;
}
} else {
if ( V_70 -> V_35 != V_71 -> V_35 )
continue;
}
V_9 = V_70 -> V_40 ;
while ( V_9 && V_9 -> V_16 )
V_9 = V_9 -> V_16 ;
if ( V_9 )
V_9 -> V_16 = V_71 -> V_40 ;
else
V_70 -> V_40 = V_71 -> V_40 ;
V_70 -> V_36 += V_71 -> V_36 ;
F_56 ( & V_71 -> V_41 ) ;
F_57 ( V_27 , V_71 ) ;
}
}
}
static int F_58 ( struct V_81 * V_32 , T_1 V_82 ,
struct V_31 * V_83 )
{
struct V_84 * V_85 = V_32 -> V_85 ;
struct V_86 * V_87 = & V_32 -> V_65 . V_86 ;
struct V_1 V_2 ;
struct V_1 V_88 = { 0 } ;
int V_89 ;
int V_24 = 0 ;
if ( V_85 && V_85 -> V_90 )
F_59 ( & V_88 , & V_85 -> V_2 ) ;
while ( ( V_87 = F_60 ( V_87 ) ) ) {
struct V_91 * V_65 ;
V_65 = F_61 ( V_87 , struct V_91 ,
V_86 ) ;
if ( V_65 -> V_92 != V_32 -> V_65 . V_92 )
break;
F_33 ( V_65 -> V_93 ) ;
if ( V_65 -> V_82 > V_82 )
continue;
switch ( V_65 -> V_94 ) {
case V_95 :
case V_96 :
F_33 ( 1 ) ;
continue;
case V_97 :
V_89 = 1 ;
break;
case V_98 :
V_89 = - 1 ;
break;
default:
F_47 ( 1 ) ;
}
switch ( V_65 -> type ) {
case V_99 : {
struct V_100 * V_38 ;
V_38 = F_62 ( V_65 ) ;
V_24 = F_18 ( V_83 , V_38 -> V_43 , & V_88 ,
V_38 -> V_34 + 1 , 0 , V_65 -> V_92 ,
V_65 -> V_101 * V_89 , V_102 ) ;
break;
}
case V_103 : {
struct V_100 * V_38 ;
V_38 = F_62 ( V_65 ) ;
V_24 = F_18 ( V_83 , V_38 -> V_43 , NULL ,
V_38 -> V_34 + 1 , V_38 -> V_35 ,
V_65 -> V_92 ,
V_65 -> V_101 * V_89 , V_102 ) ;
break;
}
case V_104 : {
struct V_105 * V_38 ;
V_38 = F_63 ( V_65 ) ;
V_2 . V_18 = V_38 -> V_18 ;
V_2 . type = V_25 ;
V_2 . V_10 = V_38 -> V_10 ;
V_24 = F_18 ( V_83 , V_38 -> V_43 , & V_2 , 0 , 0 ,
V_65 -> V_92 ,
V_65 -> V_101 * V_89 , V_102 ) ;
break;
}
case V_106 : {
struct V_105 * V_38 ;
V_38 = F_63 ( V_65 ) ;
V_2 . V_18 = V_38 -> V_18 ;
V_2 . type = V_25 ;
V_2 . V_10 = V_38 -> V_10 ;
V_24 = F_18 ( V_83 , V_38 -> V_43 , & V_2 , 0 ,
V_38 -> V_35 , V_65 -> V_92 ,
V_65 -> V_101 * V_89 , V_102 ) ;
break;
}
default:
F_33 ( 1 ) ;
}
if ( V_24 )
return V_24 ;
}
return 0 ;
}
static int F_64 ( struct V_54 * V_55 ,
struct V_44 * V_45 , T_1 V_92 ,
int * V_107 , struct V_31 * V_83 )
{
int V_24 = 0 ;
int V_21 ;
struct V_3 * V_108 ;
struct V_1 V_2 ;
struct V_1 V_109 ;
unsigned long V_110 ;
unsigned long V_111 ;
struct V_112 * V_113 ;
T_1 V_114 ;
T_1 V_115 ;
V_108 = V_45 -> V_50 [ 0 ] ;
V_21 = V_45 -> V_52 [ 0 ] ;
V_115 = F_65 ( V_108 , V_21 ) ;
F_47 ( V_115 < sizeof( * V_113 ) ) ;
V_113 = F_11 ( V_108 , V_21 , struct V_112 ) ;
V_114 = F_66 ( V_108 , V_113 ) ;
F_10 ( V_108 , & V_109 , V_21 ) ;
V_110 = ( unsigned long ) ( V_113 + 1 ) ;
V_111 = ( unsigned long ) V_113 + V_115 ;
if ( V_109 . type == V_116 &&
V_114 & V_117 ) {
struct V_118 * V_119 ;
V_119 = (struct V_118 * ) V_110 ;
* V_107 = F_67 ( V_108 , V_119 ) ;
V_110 += sizeof( struct V_118 ) ;
F_47 ( V_110 > V_111 ) ;
} else if ( V_109 . type == V_120 ) {
* V_107 = V_109 . V_10 ;
} else {
F_47 ( ! ( V_114 & V_121 ) ) ;
}
while ( V_110 < V_111 ) {
struct V_122 * V_123 ;
T_1 V_10 ;
int type ;
V_123 = (struct V_122 * ) V_110 ;
type = F_68 ( V_108 , V_123 ) ;
V_10 = F_69 ( V_108 , V_123 ) ;
switch ( type ) {
case V_103 :
V_24 = F_18 ( V_83 , 0 , NULL ,
* V_107 + 1 , V_10 ,
V_92 , 1 , V_14 ) ;
break;
case V_106 : {
struct V_124 * V_125 ;
int V_36 ;
V_125 = (struct V_124 * ) ( V_123 + 1 ) ;
V_36 = F_70 ( V_108 , V_125 ) ;
V_24 = F_18 ( V_83 , 0 , NULL , 0 , V_10 ,
V_92 , V_36 , V_14 ) ;
break;
}
case V_99 :
V_24 = F_18 ( V_83 , V_10 , NULL ,
* V_107 + 1 , 0 ,
V_92 , 1 , V_14 ) ;
break;
case V_104 : {
struct V_126 * V_127 ;
int V_36 ;
T_1 V_43 ;
V_127 = (struct V_126 * ) ( & V_123 -> V_10 ) ;
V_36 = F_71 ( V_108 , V_127 ) ;
V_2 . V_18 = F_72 ( V_108 ,
V_127 ) ;
V_2 . type = V_25 ;
V_2 . V_10 = F_73 ( V_108 , V_127 ) ;
V_43 = F_74 ( V_108 , V_127 ) ;
V_24 = F_18 ( V_83 , V_43 , & V_2 , 0 , 0 ,
V_92 , V_36 , V_14 ) ;
break;
}
default:
F_33 ( 1 ) ;
}
if ( V_24 )
return V_24 ;
V_110 += F_75 ( type ) ;
}
return 0 ;
}
static int F_76 ( struct V_54 * V_55 ,
struct V_44 * V_45 , T_1 V_92 ,
int V_107 , struct V_31 * V_83 )
{
struct V_42 * V_128 = V_55 -> V_128 ;
int V_24 ;
int V_21 ;
struct V_3 * V_108 ;
struct V_1 V_2 ;
while ( 1 ) {
V_24 = F_77 ( V_128 , V_45 ) ;
if ( V_24 < 0 )
break;
if ( V_24 ) {
V_24 = 0 ;
break;
}
V_21 = V_45 -> V_52 [ 0 ] ;
V_108 = V_45 -> V_50 [ 0 ] ;
F_10 ( V_108 , & V_2 , V_21 ) ;
if ( V_2 . V_18 != V_92 )
break;
if ( V_2 . type < V_99 )
continue;
if ( V_2 . type > V_106 )
break;
switch ( V_2 . type ) {
case V_103 :
V_24 = F_18 ( V_83 , 0 , NULL ,
V_107 + 1 , V_2 . V_10 ,
V_92 , 1 , V_14 ) ;
break;
case V_106 : {
struct V_124 * V_125 ;
int V_36 ;
V_125 = F_11 ( V_108 , V_21 ,
struct V_124 ) ;
V_36 = F_70 ( V_108 , V_125 ) ;
V_24 = F_18 ( V_83 , 0 , NULL , 0 , V_2 . V_10 ,
V_92 , V_36 , V_14 ) ;
break;
}
case V_99 :
V_24 = F_18 ( V_83 , V_2 . V_10 , NULL ,
V_107 + 1 , 0 ,
V_92 , 1 , V_14 ) ;
break;
case V_104 : {
struct V_126 * V_127 ;
int V_36 ;
T_1 V_43 ;
V_127 = F_11 ( V_108 , V_21 ,
struct V_126 ) ;
V_36 = F_71 ( V_108 , V_127 ) ;
V_2 . V_18 = F_72 ( V_108 ,
V_127 ) ;
V_2 . type = V_25 ;
V_2 . V_10 = F_73 ( V_108 , V_127 ) ;
V_43 = F_74 ( V_108 , V_127 ) ;
V_24 = F_18 ( V_83 , V_43 , & V_2 , 0 , 0 ,
V_92 , V_36 , V_14 ) ;
break;
}
default:
F_33 ( 1 ) ;
}
if ( V_24 )
return V_24 ;
}
return V_24 ;
}
static int F_78 ( struct V_129 * V_130 ,
struct V_54 * V_55 , T_1 V_92 ,
T_1 V_48 , struct V_46 * V_131 ,
struct V_46 * V_132 , const T_1 * V_7 )
{
struct V_1 V_2 ;
struct V_44 * V_45 ;
struct V_133 * V_134 = NULL ;
struct V_81 * V_32 ;
int V_107 = 0 ;
int V_24 ;
struct V_31 V_135 ;
struct V_31 V_83 ;
struct V_28 * V_38 ;
F_79 ( & V_83 ) ;
F_79 ( & V_135 ) ;
V_2 . V_18 = V_92 ;
V_2 . V_10 = ( T_1 ) - 1 ;
if ( F_80 ( V_55 , V_136 ) )
V_2 . type = V_120 ;
else
V_2 . type = V_116 ;
V_45 = F_81 () ;
if ( ! V_45 )
return - V_15 ;
if ( ! V_130 )
V_45 -> V_137 = 1 ;
V_138:
V_32 = NULL ;
V_24 = F_82 ( V_130 , V_55 -> V_128 , & V_2 , V_45 , 0 , 0 ) ;
if ( V_24 < 0 )
goto V_59;
F_47 ( V_24 == 0 ) ;
if ( V_130 ) {
V_134 = & V_130 -> V_139 -> V_134 ;
F_83 ( & V_134 -> V_140 ) ;
V_32 = F_84 ( V_130 , V_92 ) ;
if ( V_32 ) {
if ( ! F_85 ( & V_32 -> V_141 ) ) {
F_86 ( & V_32 -> V_65 . V_131 ) ;
F_87 ( & V_134 -> V_140 ) ;
F_34 ( V_45 ) ;
F_88 ( & V_32 -> V_141 ) ;
F_89 ( & V_32 -> V_141 ) ;
F_90 ( & V_32 -> V_65 ) ;
goto V_138;
}
V_24 = F_58 ( V_32 , V_48 ,
& V_135 ) ;
F_89 ( & V_32 -> V_141 ) ;
if ( V_24 ) {
F_87 ( & V_134 -> V_140 ) ;
goto V_59;
}
}
F_87 ( & V_134 -> V_140 ) ;
}
if ( V_45 -> V_52 [ 0 ] ) {
struct V_3 * V_108 ;
int V_21 ;
V_45 -> V_52 [ 0 ] -- ;
V_108 = V_45 -> V_50 [ 0 ] ;
V_21 = V_45 -> V_52 [ 0 ] ;
F_10 ( V_108 , & V_2 , V_21 ) ;
if ( V_2 . V_18 == V_92 &&
( V_2 . type == V_116 ||
V_2 . type == V_120 ) ) {
V_24 = F_64 ( V_55 , V_45 , V_92 ,
& V_107 , & V_83 ) ;
if ( V_24 )
goto V_59;
V_24 = F_76 ( V_55 , V_45 , V_92 ,
V_107 , & V_83 ) ;
if ( V_24 )
goto V_59;
}
}
F_34 ( V_45 ) ;
F_91 ( & V_135 , & V_83 ) ;
V_24 = F_44 ( V_55 , & V_83 ) ;
if ( V_24 )
goto V_59;
F_55 ( & V_83 , 1 ) ;
V_24 = F_35 ( V_55 , V_45 , V_48 , & V_83 ,
V_7 ) ;
if ( V_24 )
goto V_59;
F_55 ( & V_83 , 2 ) ;
while ( ! F_92 ( & V_83 ) ) {
V_38 = F_93 ( & V_83 , struct V_28 , V_41 ) ;
F_33 ( V_38 -> V_36 < 0 ) ;
if ( V_38 -> V_36 && V_38 -> V_33 && V_38 -> V_35 == 0 ) {
V_24 = F_22 ( V_132 , V_38 -> V_33 , 0 , V_14 ) ;
if ( V_24 < 0 )
goto V_59;
}
if ( V_38 -> V_36 && V_38 -> V_35 ) {
struct V_8 * V_9 = NULL ;
if ( V_7 && ! V_38 -> V_40 ) {
T_4 V_142 ;
struct V_3 * V_4 ;
V_142 = F_94 ( V_55 -> V_128 ,
V_107 ) ;
V_4 = F_48 ( V_55 -> V_128 ,
V_38 -> V_35 , V_142 , 0 ) ;
if ( ! V_4 || ! F_49 ( V_4 ) ) {
F_50 ( V_4 ) ;
V_24 = - V_75 ;
goto V_59;
}
V_24 = F_8 ( V_4 , V_92 ,
* V_7 , & V_9 ) ;
F_50 ( V_4 ) ;
if ( V_24 < 0 )
goto V_59;
V_38 -> V_40 = V_9 ;
}
V_24 = F_24 ( V_131 , V_38 -> V_35 ,
( V_53 ) V_38 -> V_40 ,
( T_1 * ) & V_9 , V_14 ) ;
if ( V_24 < 0 )
goto V_59;
if ( ! V_24 && V_7 ) {
F_47 ( ! V_9 ) ;
while ( V_9 -> V_16 )
V_9 = V_9 -> V_16 ;
V_9 -> V_16 = V_38 -> V_40 ;
}
}
F_56 ( & V_38 -> V_41 ) ;
F_57 ( V_27 , V_38 ) ;
}
V_59:
F_95 ( V_45 ) ;
while ( ! F_92 ( & V_83 ) ) {
V_38 = F_93 ( & V_83 , struct V_28 , V_41 ) ;
F_56 ( & V_38 -> V_41 ) ;
F_57 ( V_27 , V_38 ) ;
}
while ( ! F_92 ( & V_135 ) ) {
V_38 = F_93 ( & V_135 , struct V_28 ,
V_41 ) ;
F_56 ( & V_38 -> V_41 ) ;
F_57 ( V_27 , V_38 ) ;
}
return V_24 ;
}
static void F_96 ( struct V_46 * V_143 )
{
struct V_64 * V_65 = NULL ;
struct V_8 * V_9 ;
struct V_8 * V_144 ;
struct V_66 V_67 ;
F_38 ( & V_67 ) ;
while ( ( V_65 = F_39 ( V_143 , & V_67 ) ) ) {
if ( ! V_65 -> V_69 )
continue;
V_9 = (struct V_8 * ) ( V_53 ) V_65 -> V_69 ;
for (; V_9 ; V_9 = V_144 ) {
V_144 = V_9 -> V_16 ;
F_97 ( V_9 ) ;
}
V_65 -> V_69 = 0 ;
}
F_42 ( V_143 ) ;
}
static int F_98 ( struct V_129 * V_130 ,
struct V_54 * V_55 , T_1 V_92 ,
T_1 V_48 , struct V_46 * * V_145 ,
const T_1 * V_7 )
{
struct V_46 * V_146 ;
int V_24 ;
V_146 = F_36 ( V_14 ) ;
if ( ! V_146 )
return - V_15 ;
* V_145 = F_36 ( V_14 ) ;
if ( ! * V_145 ) {
F_42 ( V_146 ) ;
return - V_15 ;
}
V_24 = F_78 ( V_130 , V_55 , V_92 ,
V_48 , * V_145 , V_146 , V_7 ) ;
F_42 ( V_146 ) ;
if ( V_24 < 0 && V_24 != - V_147 ) {
F_96 ( * V_145 ) ;
return V_24 ;
}
return 0 ;
}
int F_99 ( struct V_129 * V_130 ,
struct V_54 * V_55 , T_1 V_92 ,
T_1 V_48 , struct V_46 * * V_132 )
{
struct V_46 * V_146 ;
struct V_64 * V_65 = NULL ;
struct V_66 V_67 ;
int V_24 ;
V_146 = F_36 ( V_14 ) ;
if ( ! V_146 )
return - V_15 ;
* V_132 = F_36 ( V_14 ) ;
if ( ! * V_132 ) {
F_42 ( V_146 ) ;
return - V_15 ;
}
F_38 ( & V_67 ) ;
while ( 1 ) {
V_24 = F_78 ( V_130 , V_55 , V_92 ,
V_48 , V_146 , * V_132 , NULL ) ;
if ( V_24 < 0 && V_24 != - V_147 ) {
F_42 ( V_146 ) ;
F_42 ( * V_132 ) ;
return V_24 ;
}
V_65 = F_39 ( V_146 , & V_67 ) ;
if ( ! V_65 )
break;
V_92 = V_65 -> V_68 ;
}
F_42 ( V_146 ) ;
return 0 ;
}
static int F_100 ( T_1 V_17 , T_1 V_148 , T_5 V_149 ,
struct V_42 * V_150 , struct V_44 * V_45 ,
struct V_1 * V_109 )
{
int V_24 ;
struct V_1 V_2 ;
struct V_3 * V_4 ;
V_2 . type = V_149 ;
V_2 . V_18 = V_17 ;
V_2 . V_10 = V_148 ;
V_24 = F_82 ( NULL , V_150 , & V_2 , V_45 , 0 , 0 ) ;
if ( V_24 < 0 )
return V_24 ;
V_4 = V_45 -> V_50 [ 0 ] ;
if ( V_24 && V_45 -> V_52 [ 0 ] >= F_9 ( V_4 ) ) {
V_24 = F_101 ( V_150 , V_45 ) ;
if ( V_24 )
return V_24 ;
V_4 = V_45 -> V_50 [ 0 ] ;
}
F_10 ( V_4 , V_109 , V_45 -> V_52 [ 0 ] ) ;
if ( V_109 -> type != V_2 . type || V_109 -> V_18 != V_2 . V_18 )
return 1 ;
return 0 ;
}
int F_102 ( T_1 V_17 , T_1 V_148 , struct V_42 * V_150 ,
struct V_44 * V_45 )
{
struct V_1 V_2 ;
return F_100 ( V_17 , V_148 , V_151 , V_150 , V_45 ,
& V_2 ) ;
}
static int F_103 ( T_1 V_17 , T_1 V_148 , struct V_42 * V_150 ,
struct V_44 * V_45 ,
struct V_1 * V_109 )
{
return F_100 ( V_17 , V_148 , V_152 , V_150 , V_45 ,
V_109 ) ;
}
int F_104 ( struct V_42 * V_43 , T_1 V_153 ,
T_1 V_154 , struct V_44 * V_45 ,
struct V_155 * * V_156 ,
T_1 * V_157 )
{
int V_24 , V_21 ;
struct V_1 V_2 ;
struct V_1 V_109 ;
struct V_155 * V_158 ;
struct V_3 * V_108 ;
unsigned long V_110 ;
V_2 . V_18 = V_153 ;
F_105 ( & V_2 , V_159 ) ;
V_2 . V_10 = V_154 ;
V_24 = F_82 ( NULL , V_43 , & V_2 , V_45 , 0 , 0 ) ;
if ( V_24 < 0 )
return V_24 ;
while ( 1 ) {
V_108 = V_45 -> V_50 [ 0 ] ;
V_21 = V_45 -> V_52 [ 0 ] ;
if ( V_21 >= F_9 ( V_108 ) ) {
V_24 = F_101 ( V_43 , V_45 ) ;
if ( V_24 ) {
if ( V_24 >= 1 )
V_24 = - V_147 ;
break;
}
continue;
}
F_10 ( V_108 , & V_109 , V_21 ) ;
V_24 = - V_147 ;
if ( V_109 . V_18 != V_153 )
break;
if ( F_106 ( & V_109 ) != V_159 )
break;
V_24 = 0 ;
V_110 = F_107 ( V_108 , V_45 -> V_52 [ 0 ] ) ;
V_158 = (struct V_155 * ) V_110 ;
* V_156 = V_158 ;
if ( V_157 )
* V_157 = V_109 . V_10 ;
break;
}
return V_24 ;
}
char * F_108 ( struct V_42 * V_150 , struct V_44 * V_45 ,
T_4 V_160 , unsigned long V_161 ,
struct V_3 * V_162 , T_1 V_35 ,
char * V_163 , T_4 V_164 )
{
int V_21 ;
T_1 V_165 ;
int V_24 ;
T_6 V_166 = ( ( T_6 ) V_164 ) - 1 ;
struct V_3 * V_4 = V_162 ;
struct V_1 V_109 ;
int V_167 = V_45 -> V_167 ;
struct V_168 * V_123 ;
if ( V_166 >= 0 )
V_163 [ V_166 ] = '\0' ;
V_45 -> V_167 = 1 ;
while ( 1 ) {
V_166 -= V_160 ;
if ( V_166 >= 0 )
F_109 ( V_4 , V_163 + V_166 ,
V_161 , V_160 ) ;
if ( V_4 != V_162 ) {
F_110 ( V_4 ) ;
F_50 ( V_4 ) ;
}
V_24 = F_103 ( V_35 , 0 , V_150 , V_45 , & V_109 ) ;
if ( V_24 > 0 )
V_24 = - V_147 ;
if ( V_24 )
break;
V_165 = V_109 . V_10 ;
if ( V_35 == V_165 )
break;
V_21 = V_45 -> V_52 [ 0 ] ;
V_4 = V_45 -> V_50 [ 0 ] ;
if ( V_4 != V_162 ) {
F_86 ( & V_4 -> V_131 ) ;
F_51 ( V_4 ) ;
F_111 ( V_4 , V_169 ) ;
}
F_34 ( V_45 ) ;
V_123 = F_11 ( V_4 , V_21 , struct V_168 ) ;
V_160 = F_112 ( V_4 , V_123 ) ;
V_161 = ( unsigned long ) ( V_123 + 1 ) ;
V_35 = V_165 ;
-- V_166 ;
if ( V_166 >= 0 )
V_163 [ V_166 ] = '/' ;
}
F_34 ( V_45 ) ;
V_45 -> V_167 = V_167 ;
if ( V_24 )
return F_113 ( V_24 ) ;
return V_163 + V_166 ;
}
int F_114 ( struct V_54 * V_55 , T_1 V_170 ,
struct V_44 * V_45 , struct V_1 * V_109 ,
T_1 * V_171 )
{
int V_24 ;
T_1 V_114 ;
T_1 V_164 = 0 ;
T_4 V_115 ;
struct V_3 * V_4 ;
struct V_112 * V_113 ;
struct V_1 V_2 ;
if ( F_80 ( V_55 , V_136 ) )
V_2 . type = V_120 ;
else
V_2 . type = V_116 ;
V_2 . V_18 = V_170 ;
V_2 . V_10 = ( T_1 ) - 1 ;
V_24 = F_82 ( NULL , V_55 -> V_128 , & V_2 , V_45 , 0 , 0 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_115 ( V_55 -> V_128 , V_45 ,
0 , V_116 ) ;
if ( V_24 < 0 )
return V_24 ;
F_10 ( V_45 -> V_50 [ 0 ] , V_109 , V_45 -> V_52 [ 0 ] ) ;
if ( V_109 -> type == V_120 )
V_164 = V_55 -> V_128 -> V_74 ;
else if ( V_109 -> type == V_116 )
V_164 = V_109 -> V_10 ;
if ( ( V_109 -> type != V_116 &&
V_109 -> type != V_120 ) ||
V_109 -> V_18 > V_170 ||
V_109 -> V_18 + V_164 <= V_170 ) {
F_32 ( L_4 , V_170 ) ;
return - V_147 ;
}
V_4 = V_45 -> V_50 [ 0 ] ;
V_115 = F_65 ( V_4 , V_45 -> V_52 [ 0 ] ) ;
F_47 ( V_115 < sizeof( * V_113 ) ) ;
V_113 = F_11 ( V_4 , V_45 -> V_52 [ 0 ] , struct V_112 ) ;
V_114 = F_66 ( V_4 , V_113 ) ;
F_32 ( L_5
L_6 ,
V_170 , V_170 - V_109 -> V_18 , V_109 -> V_18 ,
V_109 -> V_10 , V_114 , V_115 ) ;
F_33 ( ! V_171 ) ;
if ( V_171 ) {
if ( V_114 & V_117 )
* V_171 = V_117 ;
else if ( V_114 & V_121 )
* V_171 = V_121 ;
else
F_47 ( 1 ) ;
return 0 ;
}
return - V_75 ;
}
static int F_116 ( unsigned long * V_110 , struct V_3 * V_4 ,
struct V_112 * V_113 , T_4 V_115 ,
struct V_122 * * V_172 ,
int * V_173 )
{
unsigned long V_111 ;
T_1 V_114 ;
struct V_118 * V_119 ;
if ( ! * V_110 ) {
V_114 = F_66 ( V_4 , V_113 ) ;
if ( V_114 & V_117 ) {
V_119 = (struct V_118 * ) ( V_113 + 1 ) ;
* V_172 =
(struct V_122 * ) ( V_119 + 1 ) ;
} else {
* V_172 = (struct V_122 * ) ( V_113 + 1 ) ;
}
* V_110 = ( unsigned long ) * V_172 ;
if ( ( void * ) * V_110 >= ( void * ) V_113 + V_115 )
return - V_147 ;
}
V_111 = ( unsigned long ) V_113 + V_115 ;
* V_172 = (struct V_122 * ) * V_110 ;
* V_173 = F_68 ( V_4 , * V_172 ) ;
* V_110 += F_75 ( * V_173 ) ;
F_33 ( * V_110 > V_111 ) ;
if ( * V_110 == V_111 )
return 1 ;
return 0 ;
}
int F_117 ( unsigned long * V_110 , struct V_3 * V_4 ,
struct V_112 * V_113 , T_4 V_115 ,
T_1 * V_174 , T_5 * V_175 )
{
int V_24 ;
int type ;
struct V_118 * V_119 ;
struct V_122 * V_176 ;
if ( * V_110 == ( unsigned long ) - 1 )
return 1 ;
while ( 1 ) {
V_24 = F_116 ( V_110 , V_4 , V_113 , V_115 ,
& V_176 , & type ) ;
if ( V_24 < 0 )
return V_24 ;
if ( type == V_99 ||
type == V_103 )
break;
if ( V_24 == 1 )
return 1 ;
}
V_119 = (struct V_118 * ) ( V_113 + 1 ) ;
* V_174 = F_69 ( V_4 , V_176 ) ;
* V_175 = F_67 ( V_4 , V_119 ) ;
if ( V_24 == 1 )
* V_110 = ( unsigned long ) - 1 ;
return 0 ;
}
static int F_118 ( struct V_8 * V_40 ,
T_1 V_43 , T_1 V_177 ,
T_7 * V_178 , void * V_179 )
{
struct V_8 * V_9 ;
int V_24 = 0 ;
for ( V_9 = V_40 ; V_9 ; V_9 = V_9 -> V_16 ) {
F_32 ( L_7
L_8 , V_177 ,
V_9 -> V_17 , V_9 -> V_10 , V_43 ) ;
V_24 = V_178 ( V_9 -> V_17 , V_9 -> V_10 , V_43 , V_179 ) ;
if ( V_24 ) {
F_32 ( L_9 ,
V_177 , V_24 ) ;
break;
}
}
return V_24 ;
}
int F_119 ( struct V_54 * V_55 ,
T_1 V_177 , T_1 V_7 ,
int V_137 ,
T_7 * V_178 , void * V_179 )
{
int V_24 ;
struct V_129 * V_130 = NULL ;
struct V_46 * V_131 = NULL ;
struct V_46 * V_132 = NULL ;
struct V_64 * V_180 = NULL ;
struct V_64 * V_181 = NULL ;
struct V_182 V_183 = {} ;
struct V_66 V_184 ;
struct V_66 V_185 ;
F_32 ( L_10 ,
V_177 ) ;
if ( ! V_137 ) {
V_130 = F_120 ( V_55 -> V_128 ) ;
if ( F_28 ( V_130 ) )
return F_29 ( V_130 ) ;
F_121 ( V_55 , & V_183 ) ;
}
V_24 = F_98 ( V_130 , V_55 , V_177 ,
V_183 . V_82 , & V_131 ,
& V_7 ) ;
if ( V_24 )
goto V_59;
F_38 ( & V_184 ) ;
while ( ! V_24 && ( V_180 = F_39 ( V_131 , & V_184 ) ) ) {
V_24 = F_99 ( V_130 , V_55 , V_180 -> V_68 ,
V_183 . V_82 , & V_132 ) ;
if ( V_24 )
break;
F_38 ( & V_185 ) ;
while ( ! V_24 && ( V_181 = F_39 ( V_132 , & V_185 ) ) ) {
F_32 ( L_11
L_12 , V_181 -> V_68 , V_180 -> V_68 ,
V_180 -> V_69 ) ;
V_24 = F_118 ( (struct V_8 * )
( V_53 ) V_180 -> V_69 ,
V_181 -> V_68 ,
V_177 ,
V_178 , V_179 ) ;
}
F_42 ( V_132 ) ;
}
F_96 ( V_131 ) ;
V_59:
if ( ! V_137 ) {
F_122 ( V_55 , & V_183 ) ;
F_123 ( V_130 , V_55 -> V_128 ) ;
}
return V_24 ;
}
int F_124 ( T_1 V_170 , struct V_54 * V_55 ,
struct V_44 * V_45 ,
T_7 * V_178 , void * V_179 )
{
int V_24 ;
T_1 V_7 ;
T_1 V_114 = 0 ;
struct V_1 V_109 ;
int V_137 = V_45 -> V_137 ;
V_24 = F_114 ( V_55 , V_170 , V_45 , & V_109 , & V_114 ) ;
F_34 ( V_45 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_114 & V_117 )
return - V_186 ;
V_7 = V_170 - V_109 . V_18 ;
V_24 = F_119 ( V_55 , V_109 . V_18 ,
V_7 , V_137 ,
V_178 , V_179 ) ;
return V_24 ;
}
static int F_125 ( T_1 V_17 , struct V_42 * V_150 ,
struct V_44 * V_45 ,
T_8 * V_178 , void * V_179 )
{
int V_24 = 0 ;
int V_21 ;
T_4 V_187 ;
T_4 V_188 ;
T_4 V_160 ;
T_1 V_35 = 0 ;
int V_189 = 0 ;
struct V_3 * V_4 ;
struct V_190 * V_191 ;
struct V_168 * V_123 ;
struct V_1 V_109 ;
while ( ! V_24 ) {
V_45 -> V_167 = 1 ;
V_24 = F_103 ( V_17 , V_35 ? V_35 + 1 : 0 , V_150 , V_45 ,
& V_109 ) ;
if ( V_24 < 0 )
break;
if ( V_24 ) {
V_24 = V_189 ? 0 : - V_147 ;
break;
}
++ V_189 ;
V_35 = V_109 . V_10 ;
V_21 = V_45 -> V_52 [ 0 ] ;
V_4 = V_45 -> V_50 [ 0 ] ;
F_86 ( & V_4 -> V_131 ) ;
F_51 ( V_4 ) ;
F_111 ( V_4 , V_169 ) ;
F_34 ( V_45 ) ;
V_191 = F_126 ( V_4 , V_21 ) ;
V_123 = F_11 ( V_4 , V_21 , struct V_168 ) ;
for ( V_187 = 0 ; V_187 < F_127 ( V_4 , V_191 ) ; V_187 += V_188 ) {
V_160 = F_112 ( V_4 , V_123 ) ;
F_32 ( L_13
L_14 , V_187 , V_109 . V_18 ,
V_150 -> V_18 ) ;
V_24 = V_178 ( V_35 , V_160 ,
( unsigned long ) ( V_123 + 1 ) , V_4 , V_179 ) ;
if ( V_24 )
break;
V_188 = sizeof( * V_123 ) + V_160 ;
V_123 = (struct V_168 * ) ( ( char * ) V_123 + V_188 ) ;
}
F_110 ( V_4 ) ;
F_50 ( V_4 ) ;
}
F_34 ( V_45 ) ;
return V_24 ;
}
static int F_128 ( T_1 V_17 , struct V_42 * V_150 ,
struct V_44 * V_45 ,
T_8 * V_178 , void * V_179 )
{
int V_24 ;
int V_21 ;
T_1 V_10 = 0 ;
T_1 V_35 ;
int V_189 = 0 ;
struct V_3 * V_4 ;
struct V_155 * V_158 ;
struct V_3 * V_108 ;
T_4 V_115 ;
T_4 V_192 ;
unsigned long V_110 ;
while ( 1 ) {
V_24 = F_104 ( V_150 , V_17 , V_10 , V_45 , & V_158 ,
& V_10 ) ;
if ( V_24 < 0 )
break;
if ( V_24 ) {
V_24 = V_189 ? 0 : - V_147 ;
break;
}
++ V_189 ;
V_21 = V_45 -> V_52 [ 0 ] ;
V_4 = V_45 -> V_50 [ 0 ] ;
F_86 ( & V_4 -> V_131 ) ;
F_51 ( V_4 ) ;
F_111 ( V_4 , V_169 ) ;
F_34 ( V_45 ) ;
V_108 = V_45 -> V_50 [ 0 ] ;
V_115 = F_65 ( V_108 , V_45 -> V_52 [ 0 ] ) ;
V_110 = F_107 ( V_108 , V_45 -> V_52 [ 0 ] ) ;
V_192 = 0 ;
while ( V_192 < V_115 ) {
T_4 V_160 ;
V_158 = (struct V_155 * ) ( V_110 + V_192 ) ;
V_35 = F_129 ( V_4 , V_158 ) ;
V_160 = F_130 ( V_4 , V_158 ) ;
V_24 = V_178 ( V_35 , V_160 ,
( unsigned long ) & V_158 -> V_193 , V_4 , V_179 ) ;
if ( V_24 )
break;
V_192 += F_130 ( V_108 , V_158 ) ;
V_192 += sizeof( * V_158 ) ;
}
F_110 ( V_4 ) ;
F_50 ( V_4 ) ;
V_10 ++ ;
}
F_34 ( V_45 ) ;
return V_24 ;
}
static int F_131 ( T_1 V_17 , struct V_42 * V_150 ,
struct V_44 * V_45 , T_8 * V_178 ,
void * V_179 )
{
int V_24 ;
int V_194 = 0 ;
V_24 = F_125 ( V_17 , V_150 , V_45 , V_178 , V_179 ) ;
if ( ! V_24 )
++ V_194 ;
else if ( V_24 != - V_147 )
return V_24 ;
V_24 = F_128 ( V_17 , V_150 , V_45 , V_178 , V_179 ) ;
if ( V_24 == - V_147 && V_194 )
return 0 ;
return V_24 ;
}
static int F_132 ( T_1 V_17 , T_4 V_160 , unsigned long V_161 ,
struct V_3 * V_4 , void * V_179 )
{
struct V_195 * V_196 = V_179 ;
char * V_197 ;
char * V_198 ;
int V_199 = V_196 -> V_197 -> V_200 ;
const int V_201 = sizeof( char * ) ;
T_4 V_166 ;
V_166 = V_196 -> V_197 -> V_166 > V_201 ?
V_196 -> V_197 -> V_166 - V_201 : 0 ;
V_198 = ( char * ) V_196 -> V_197 -> V_68 + ( V_199 + 1 ) * V_201 ;
V_197 = F_108 ( V_196 -> V_150 , V_196 -> V_44 , V_160 ,
V_161 , V_4 , V_17 , V_198 , V_166 ) ;
if ( F_28 ( V_197 ) )
return F_29 ( V_197 ) ;
if ( V_197 > V_198 ) {
V_196 -> V_197 -> V_68 [ V_199 ] = ( T_1 ) ( unsigned long ) V_197 ;
++ V_196 -> V_197 -> V_200 ;
V_196 -> V_197 -> V_166 = V_197 - V_198 ;
} else {
++ V_196 -> V_197 -> V_202 ;
V_196 -> V_197 -> V_203 += V_198 - V_197 ;
V_196 -> V_197 -> V_166 = 0 ;
}
return 0 ;
}
int F_133 ( T_1 V_17 , struct V_195 * V_196 )
{
return F_131 ( V_17 , V_196 -> V_150 , V_196 -> V_44 ,
F_132 , V_196 ) ;
}
struct V_204 * F_134 ( T_4 V_205 )
{
struct V_204 * V_206 ;
T_9 V_207 ;
V_207 = F_135 ( T_9 , V_205 , sizeof( * V_206 ) ) ;
V_206 = F_136 ( V_207 ) ;
if ( ! V_206 )
return F_113 ( - V_15 ) ;
if ( V_205 >= sizeof( * V_206 ) ) {
V_206 -> V_166 = V_205 - sizeof( * V_206 ) ;
V_206 -> V_203 = 0 ;
} else {
V_206 -> V_203 = sizeof( * V_206 ) - V_205 ;
V_206 -> V_166 = 0 ;
}
V_206 -> V_200 = 0 ;
V_206 -> V_202 = 0 ;
return V_206 ;
}
struct V_195 * F_137 ( T_10 V_205 , struct V_42 * V_150 ,
struct V_44 * V_45 )
{
struct V_195 * V_208 ;
struct V_204 * V_197 ;
V_197 = F_134 ( V_205 ) ;
if ( F_28 ( V_197 ) )
return ( void * ) V_197 ;
V_208 = F_7 ( sizeof( * V_208 ) , V_14 ) ;
if ( ! V_208 ) {
F_97 ( V_197 ) ;
return F_113 ( - V_15 ) ;
}
V_208 -> V_44 = V_45 ;
V_208 -> V_197 = V_197 ;
V_208 -> V_150 = V_150 ;
return V_208 ;
}
void F_138 ( struct V_195 * V_196 )
{
if ( ! V_196 )
return;
F_139 ( V_196 -> V_197 ) ;
F_97 ( V_196 ) ;
}
