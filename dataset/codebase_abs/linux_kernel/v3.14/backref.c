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
static void F_8 ( struct V_8 * V_9 )
{
struct V_8 * V_19 ;
for (; V_9 ; V_9 = V_19 ) {
V_19 = V_9 -> V_16 ;
F_9 ( V_9 ) ;
}
}
static int F_10 ( struct V_3 * V_4 , T_1 V_20 ,
T_1 V_7 ,
struct V_8 * * V_9 )
{
T_1 V_21 ;
struct V_1 V_2 ;
struct V_5 * V_6 ;
int V_22 ;
int V_23 ;
int V_24 ;
int V_25 ;
V_23 = F_11 ( V_4 ) ;
for ( V_22 = 0 ; V_22 < V_23 ; ++ V_22 ) {
F_12 ( V_4 , & V_2 , V_22 ) ;
if ( V_2 . type != V_26 )
continue;
V_6 = F_13 ( V_4 , V_22 , struct V_5 ) ;
V_24 = F_14 ( V_4 , V_6 ) ;
if ( V_24 == V_27 )
continue;
V_21 = F_15 ( V_4 , V_6 ) ;
if ( V_21 != V_20 )
continue;
V_25 = F_1 ( & V_2 , V_4 , V_6 , V_7 , V_9 ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
int T_2 F_16 ( void )
{
V_28 = F_17 ( L_1 ,
sizeof( struct V_29 ) ,
0 ,
V_30 | V_31 ,
NULL ) ;
if ( ! V_28 )
return - V_15 ;
return 0 ;
}
void F_18 ( void )
{
if ( V_28 )
F_19 ( V_28 ) ;
}
static int F_20 ( struct V_32 * V_33 , T_1 V_34 ,
struct V_1 * V_2 , int V_35 ,
T_1 V_36 , T_1 V_20 , int V_37 ,
T_3 V_38 )
{
struct V_29 * V_39 ;
if ( V_34 == V_40 )
return 0 ;
V_39 = F_21 ( V_28 , V_38 ) ;
if ( ! V_39 )
return - V_15 ;
V_39 -> V_34 = V_34 ;
if ( V_2 )
V_39 -> V_41 = * V_2 ;
else
memset ( & V_39 -> V_41 , 0 , sizeof( V_39 -> V_41 ) ) ;
V_39 -> V_42 = NULL ;
V_39 -> V_35 = V_35 ;
V_39 -> V_37 = V_37 ;
V_39 -> V_36 = V_36 ;
V_39 -> V_20 = V_20 ;
F_22 ( & V_39 -> V_43 , V_33 ) ;
return 0 ;
}
static int F_23 ( struct V_44 * V_45 , struct V_46 * V_47 ,
struct V_48 * V_49 , struct V_29 * V_39 ,
int V_35 , T_1 V_50 , const T_1 * V_7 )
{
int V_25 = 0 ;
int V_22 ;
struct V_3 * V_4 ;
struct V_1 V_2 ;
struct V_1 * V_41 = & V_39 -> V_41 ;
struct V_5 * V_6 ;
struct V_8 * V_9 = NULL , * V_51 = NULL ;
T_1 V_21 ;
T_1 V_20 = V_39 -> V_20 ;
T_1 V_37 = 0 ;
if ( V_35 != 0 ) {
V_4 = V_47 -> V_52 [ V_35 ] ;
V_25 = F_24 ( V_49 , V_4 -> V_53 , 0 , V_14 ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
if ( V_47 -> V_54 [ 0 ] >= F_11 ( V_47 -> V_52 [ 0 ] ) )
V_25 = F_25 ( V_45 , V_47 , V_50 ) ;
while ( ! V_25 && V_37 < V_39 -> V_37 ) {
V_4 = V_47 -> V_52 [ 0 ] ;
V_22 = V_47 -> V_54 [ 0 ] ;
F_12 ( V_4 , & V_2 , V_22 ) ;
if ( V_2 . V_18 != V_41 -> V_18 ||
V_2 . type != V_26 )
break;
V_6 = F_13 ( V_4 , V_22 , struct V_5 ) ;
V_21 = F_15 ( V_4 , V_6 ) ;
if ( V_21 == V_20 ) {
V_9 = NULL ;
V_51 = NULL ;
V_37 ++ ;
if ( V_7 ) {
V_25 = F_1 ( & V_2 , V_4 , V_6 ,
* V_7 ,
& V_9 ) ;
if ( V_25 < 0 )
break;
}
if ( V_25 > 0 )
goto V_16;
V_25 = F_26 ( V_49 , V_4 -> V_53 ,
( V_55 ) V_9 ,
( T_1 * ) & V_51 , V_14 ) ;
if ( V_25 < 0 )
break;
if ( ! V_25 && V_7 ) {
while ( V_51 -> V_16 )
V_51 = V_51 -> V_16 ;
V_51 -> V_16 = V_9 ;
}
V_9 = NULL ;
}
V_16:
V_25 = F_27 ( V_45 , V_47 , V_50 ) ;
}
if ( V_25 > 0 )
V_25 = 0 ;
else if ( V_25 < 0 )
F_8 ( V_9 ) ;
return V_25 ;
}
static int F_28 ( struct V_56 * V_57 ,
struct V_46 * V_47 , T_1 V_50 ,
struct V_29 * V_39 ,
struct V_48 * V_49 ,
const T_1 * V_7 )
{
struct V_44 * V_45 ;
struct V_1 V_58 ;
struct V_3 * V_4 ;
int V_25 = 0 ;
int V_59 ;
int V_35 = V_39 -> V_35 ;
int V_60 ;
V_58 . V_18 = V_39 -> V_34 ;
V_58 . type = V_61 ;
V_58 . V_10 = ( T_1 ) - 1 ;
V_60 = F_29 ( & V_57 -> V_62 ) ;
V_45 = F_30 ( V_57 , & V_58 ) ;
if ( F_31 ( V_45 ) ) {
F_32 ( & V_57 -> V_62 , V_60 ) ;
V_25 = F_33 ( V_45 ) ;
goto V_63;
}
V_59 = F_34 ( V_45 , V_50 ) ;
if ( V_59 + 1 == V_35 ) {
F_32 ( & V_57 -> V_62 , V_60 ) ;
goto V_63;
}
V_47 -> V_64 = V_35 ;
V_25 = F_35 ( V_45 , & V_39 -> V_41 , V_47 , V_50 ) ;
F_32 ( & V_57 -> V_62 , V_60 ) ;
F_36 ( L_2
L_3 ,
V_39 -> V_34 , V_35 , V_39 -> V_37 , V_25 ,
V_39 -> V_41 . V_18 , V_39 -> V_41 . type ,
V_39 -> V_41 . V_10 ) ;
if ( V_25 < 0 )
goto V_63;
V_4 = V_47 -> V_52 [ V_35 ] ;
while ( ! V_4 ) {
if ( F_37 ( ! V_35 ) ) {
V_25 = 1 ;
goto V_63;
}
V_35 -- ;
V_4 = V_47 -> V_52 [ V_35 ] ;
}
V_25 = F_23 ( V_45 , V_47 , V_49 , V_39 , V_35 , V_50 ,
V_7 ) ;
V_63:
V_47 -> V_64 = 0 ;
F_38 ( V_47 ) ;
return V_25 ;
}
static int F_39 ( struct V_56 * V_57 ,
struct V_46 * V_47 , T_1 V_50 ,
struct V_32 * V_33 ,
const T_1 * V_7 )
{
int V_65 ;
int V_25 = 0 ;
struct V_29 * V_39 ;
struct V_29 * V_66 ;
struct V_29 * V_67 ;
struct V_48 * V_49 ;
struct V_68 * V_69 ;
struct V_70 V_71 ;
V_49 = F_40 ( V_14 ) ;
if ( ! V_49 )
return - V_15 ;
F_41 (ref, ref_safe, head, list) {
if ( V_39 -> V_36 )
continue;
if ( V_39 -> V_37 == 0 )
continue;
V_65 = F_28 ( V_57 , V_47 , V_50 , V_39 ,
V_49 , V_7 ) ;
if ( V_65 == - V_72 ) {
continue;
} else if ( V_65 ) {
V_25 = V_65 ;
goto V_63;
}
F_42 ( & V_71 ) ;
V_69 = F_43 ( V_49 , & V_71 ) ;
V_39 -> V_36 = V_69 ? V_69 -> V_73 : 0 ;
V_39 -> V_42 = V_69 ?
(struct V_8 * ) ( V_55 ) V_69 -> V_74 : NULL ;
while ( ( V_69 = F_43 ( V_49 , & V_71 ) ) ) {
V_67 = F_21 ( V_28 ,
V_14 ) ;
if ( ! V_67 ) {
V_25 = - V_15 ;
goto V_63;
}
memcpy ( V_67 , V_39 , sizeof( * V_39 ) ) ;
V_67 -> V_36 = V_69 -> V_73 ;
V_67 -> V_42 = (struct V_8 * )
( V_55 ) V_69 -> V_74 ;
F_44 ( & V_67 -> V_43 , & V_39 -> V_43 ) ;
}
F_45 ( V_49 ) ;
}
V_63:
F_46 ( V_49 ) ;
return V_25 ;
}
static inline int F_47 ( struct V_29 * V_75 ,
struct V_29 * V_76 )
{
if ( V_75 -> V_35 != V_76 -> V_35 )
return 0 ;
if ( V_75 -> V_34 != V_76 -> V_34 )
return 0 ;
if ( V_75 -> V_41 . type != V_76 -> V_41 . type )
return 0 ;
if ( V_75 -> V_41 . V_18 != V_76 -> V_41 . V_18 )
return 0 ;
if ( V_75 -> V_41 . V_10 != V_76 -> V_41 . V_10 )
return 0 ;
if ( V_75 -> V_36 != V_76 -> V_36 )
return 0 ;
return 1 ;
}
static int F_48 ( struct V_56 * V_57 ,
struct V_32 * V_33 )
{
struct V_32 * V_77 ;
struct V_3 * V_4 ;
F_49 (pos, head) {
struct V_29 * V_39 ;
V_39 = F_50 ( V_77 , struct V_29 , V_43 ) ;
if ( V_39 -> V_36 )
continue;
if ( V_39 -> V_41 . type )
continue;
F_51 ( ! V_39 -> V_20 ) ;
V_4 = F_52 ( V_57 -> V_78 , V_39 -> V_20 ,
V_57 -> V_78 -> V_79 , 0 ) ;
if ( ! V_4 || ! F_53 ( V_4 ) ) {
F_54 ( V_4 ) ;
return - V_80 ;
}
F_55 ( V_4 ) ;
if ( F_56 ( V_4 ) == 0 )
F_12 ( V_4 , & V_39 -> V_41 , 0 ) ;
else
F_57 ( V_4 , & V_39 -> V_41 , 0 ) ;
F_58 ( V_4 ) ;
F_54 ( V_4 ) ;
}
return 0 ;
}
static void F_59 ( struct V_32 * V_33 , int V_81 )
{
struct V_32 * V_82 ;
F_49 (pos1, head) {
struct V_32 * V_83 ;
struct V_32 * V_84 ;
struct V_29 * V_75 ;
V_75 = F_50 ( V_82 , struct V_29 , V_43 ) ;
for ( V_84 = V_82 -> V_16 , V_83 = V_84 -> V_16 ; V_84 != V_33 ;
V_84 = V_83 , V_83 = V_84 -> V_16 ) {
struct V_29 * V_76 ;
struct V_29 * V_85 ;
struct V_8 * V_9 ;
V_76 = F_50 ( V_84 , struct V_29 , V_43 ) ;
if ( V_81 == 1 ) {
if ( ! F_47 ( V_75 , V_76 ) )
continue;
if ( ! V_75 -> V_36 && V_76 -> V_36 ) {
V_85 = V_75 ;
V_75 = V_76 ;
V_76 = V_85 ;
}
} else {
if ( V_75 -> V_36 != V_76 -> V_36 )
continue;
}
V_9 = V_75 -> V_42 ;
while ( V_9 && V_9 -> V_16 )
V_9 = V_9 -> V_16 ;
if ( V_9 )
V_9 -> V_16 = V_76 -> V_42 ;
else
V_75 -> V_42 = V_76 -> V_42 ;
V_75 -> V_37 += V_76 -> V_37 ;
F_60 ( & V_76 -> V_43 ) ;
F_61 ( V_28 , V_76 ) ;
}
}
}
static int F_62 ( struct V_86 * V_33 , T_1 V_87 ,
struct V_32 * V_88 )
{
struct V_89 * V_90 = V_33 -> V_90 ;
struct V_91 * V_92 = & V_33 -> V_69 . V_91 ;
struct V_1 V_2 ;
struct V_1 V_93 = { 0 } ;
int V_94 ;
int V_25 = 0 ;
if ( V_90 && V_90 -> V_95 )
F_63 ( & V_93 , & V_90 -> V_2 ) ;
F_64 ( & V_33 -> V_96 ) ;
V_92 = F_65 ( & V_33 -> V_97 ) ;
while ( V_92 ) {
struct V_98 * V_69 ;
V_69 = F_66 ( V_92 , struct V_98 ,
V_91 ) ;
V_92 = F_67 ( V_92 ) ;
if ( V_69 -> V_87 > V_87 )
continue;
switch ( V_69 -> V_99 ) {
case V_100 :
case V_101 :
F_37 ( 1 ) ;
continue;
case V_102 :
V_94 = 1 ;
break;
case V_103 :
V_94 = - 1 ;
break;
default:
F_51 ( 1 ) ;
}
switch ( V_69 -> type ) {
case V_104 : {
struct V_105 * V_39 ;
V_39 = F_68 ( V_69 ) ;
V_25 = F_20 ( V_88 , V_39 -> V_45 , & V_93 ,
V_39 -> V_35 + 1 , 0 , V_69 -> V_106 ,
V_69 -> V_107 * V_94 , V_108 ) ;
break;
}
case V_109 : {
struct V_105 * V_39 ;
V_39 = F_68 ( V_69 ) ;
V_25 = F_20 ( V_88 , V_39 -> V_45 , NULL ,
V_39 -> V_35 + 1 , V_39 -> V_36 ,
V_69 -> V_106 ,
V_69 -> V_107 * V_94 , V_108 ) ;
break;
}
case V_110 : {
struct V_111 * V_39 ;
V_39 = F_69 ( V_69 ) ;
V_2 . V_18 = V_39 -> V_18 ;
V_2 . type = V_26 ;
V_2 . V_10 = V_39 -> V_10 ;
V_25 = F_20 ( V_88 , V_39 -> V_45 , & V_2 , 0 , 0 ,
V_69 -> V_106 ,
V_69 -> V_107 * V_94 , V_108 ) ;
break;
}
case V_112 : {
struct V_111 * V_39 ;
V_39 = F_69 ( V_69 ) ;
V_2 . V_18 = V_39 -> V_18 ;
V_2 . type = V_26 ;
V_2 . V_10 = V_39 -> V_10 ;
V_25 = F_20 ( V_88 , V_39 -> V_45 , & V_2 , 0 ,
V_39 -> V_36 , V_69 -> V_106 ,
V_69 -> V_107 * V_94 , V_108 ) ;
break;
}
default:
F_37 ( 1 ) ;
}
if ( V_25 )
break;
}
F_70 ( & V_33 -> V_96 ) ;
return V_25 ;
}
static int F_71 ( struct V_56 * V_57 ,
struct V_46 * V_47 , T_1 V_106 ,
int * V_113 , struct V_32 * V_88 )
{
int V_25 = 0 ;
int V_22 ;
struct V_3 * V_114 ;
struct V_1 V_2 ;
struct V_1 V_115 ;
unsigned long V_116 ;
unsigned long V_117 ;
struct V_118 * V_119 ;
T_1 V_120 ;
T_1 V_121 ;
V_114 = V_47 -> V_52 [ 0 ] ;
V_22 = V_47 -> V_54 [ 0 ] ;
V_121 = F_72 ( V_114 , V_22 ) ;
F_51 ( V_121 < sizeof( * V_119 ) ) ;
V_119 = F_13 ( V_114 , V_22 , struct V_118 ) ;
V_120 = F_73 ( V_114 , V_119 ) ;
F_12 ( V_114 , & V_115 , V_22 ) ;
V_116 = ( unsigned long ) ( V_119 + 1 ) ;
V_117 = ( unsigned long ) V_119 + V_121 ;
if ( V_115 . type == V_122 &&
V_120 & V_123 ) {
struct V_124 * V_125 ;
V_125 = (struct V_124 * ) V_116 ;
* V_113 = F_74 ( V_114 , V_125 ) ;
V_116 += sizeof( struct V_124 ) ;
F_51 ( V_116 > V_117 ) ;
} else if ( V_115 . type == V_126 ) {
* V_113 = V_115 . V_10 ;
} else {
F_51 ( ! ( V_120 & V_127 ) ) ;
}
while ( V_116 < V_117 ) {
struct V_128 * V_129 ;
T_1 V_10 ;
int type ;
V_129 = (struct V_128 * ) V_116 ;
type = F_75 ( V_114 , V_129 ) ;
V_10 = F_76 ( V_114 , V_129 ) ;
switch ( type ) {
case V_109 :
V_25 = F_20 ( V_88 , 0 , NULL ,
* V_113 + 1 , V_10 ,
V_106 , 1 , V_14 ) ;
break;
case V_112 : {
struct V_130 * V_131 ;
int V_37 ;
V_131 = (struct V_130 * ) ( V_129 + 1 ) ;
V_37 = F_77 ( V_114 , V_131 ) ;
V_25 = F_20 ( V_88 , 0 , NULL , 0 , V_10 ,
V_106 , V_37 , V_14 ) ;
break;
}
case V_104 :
V_25 = F_20 ( V_88 , V_10 , NULL ,
* V_113 + 1 , 0 ,
V_106 , 1 , V_14 ) ;
break;
case V_110 : {
struct V_132 * V_133 ;
int V_37 ;
T_1 V_45 ;
V_133 = (struct V_132 * ) ( & V_129 -> V_10 ) ;
V_37 = F_78 ( V_114 , V_133 ) ;
V_2 . V_18 = F_79 ( V_114 ,
V_133 ) ;
V_2 . type = V_26 ;
V_2 . V_10 = F_80 ( V_114 , V_133 ) ;
V_45 = F_81 ( V_114 , V_133 ) ;
V_25 = F_20 ( V_88 , V_45 , & V_2 , 0 , 0 ,
V_106 , V_37 , V_14 ) ;
break;
}
default:
F_37 ( 1 ) ;
}
if ( V_25 )
return V_25 ;
V_116 += F_82 ( type ) ;
}
return 0 ;
}
static int F_83 ( struct V_56 * V_57 ,
struct V_46 * V_47 , T_1 V_106 ,
int V_113 , struct V_32 * V_88 )
{
struct V_44 * V_134 = V_57 -> V_134 ;
int V_25 ;
int V_22 ;
struct V_3 * V_114 ;
struct V_1 V_2 ;
while ( 1 ) {
V_25 = F_84 ( V_134 , V_47 ) ;
if ( V_25 < 0 )
break;
if ( V_25 ) {
V_25 = 0 ;
break;
}
V_22 = V_47 -> V_54 [ 0 ] ;
V_114 = V_47 -> V_52 [ 0 ] ;
F_12 ( V_114 , & V_2 , V_22 ) ;
if ( V_2 . V_18 != V_106 )
break;
if ( V_2 . type < V_104 )
continue;
if ( V_2 . type > V_112 )
break;
switch ( V_2 . type ) {
case V_109 :
V_25 = F_20 ( V_88 , 0 , NULL ,
V_113 + 1 , V_2 . V_10 ,
V_106 , 1 , V_14 ) ;
break;
case V_112 : {
struct V_130 * V_131 ;
int V_37 ;
V_131 = F_13 ( V_114 , V_22 ,
struct V_130 ) ;
V_37 = F_77 ( V_114 , V_131 ) ;
V_25 = F_20 ( V_88 , 0 , NULL , 0 , V_2 . V_10 ,
V_106 , V_37 , V_14 ) ;
break;
}
case V_104 :
V_25 = F_20 ( V_88 , V_2 . V_10 , NULL ,
V_113 + 1 , 0 ,
V_106 , 1 , V_14 ) ;
break;
case V_110 : {
struct V_132 * V_133 ;
int V_37 ;
T_1 V_45 ;
V_133 = F_13 ( V_114 , V_22 ,
struct V_132 ) ;
V_37 = F_78 ( V_114 , V_133 ) ;
V_2 . V_18 = F_79 ( V_114 ,
V_133 ) ;
V_2 . type = V_26 ;
V_2 . V_10 = F_80 ( V_114 , V_133 ) ;
V_45 = F_81 ( V_114 , V_133 ) ;
V_25 = F_20 ( V_88 , V_45 , & V_2 , 0 , 0 ,
V_106 , V_37 , V_14 ) ;
break;
}
default:
F_37 ( 1 ) ;
}
if ( V_25 )
return V_25 ;
}
return V_25 ;
}
static int F_85 ( struct V_135 * V_136 ,
struct V_56 * V_57 , T_1 V_106 ,
T_1 V_50 , struct V_48 * V_137 ,
struct V_48 * V_138 , const T_1 * V_7 )
{
struct V_1 V_2 ;
struct V_46 * V_47 ;
struct V_139 * V_140 = NULL ;
struct V_86 * V_33 ;
int V_113 = 0 ;
int V_25 ;
struct V_32 V_141 ;
struct V_32 V_88 ;
struct V_29 * V_39 ;
struct V_8 * V_9 = NULL ;
F_86 ( & V_88 ) ;
F_86 ( & V_141 ) ;
V_2 . V_18 = V_106 ;
V_2 . V_10 = ( T_1 ) - 1 ;
if ( F_87 ( V_57 , V_142 ) )
V_2 . type = V_126 ;
else
V_2 . type = V_122 ;
V_47 = F_88 () ;
if ( ! V_47 )
return - V_15 ;
if ( ! V_136 )
V_47 -> V_143 = 1 ;
V_144:
V_33 = NULL ;
V_25 = F_89 ( V_136 , V_57 -> V_134 , & V_2 , V_47 , 0 , 0 ) ;
if ( V_25 < 0 )
goto V_63;
F_51 ( V_25 == 0 ) ;
if ( V_136 ) {
V_140 = & V_136 -> V_145 -> V_140 ;
F_64 ( & V_140 -> V_96 ) ;
V_33 = F_90 ( V_136 , V_106 ) ;
if ( V_33 ) {
if ( ! F_91 ( & V_33 -> V_146 ) ) {
F_92 ( & V_33 -> V_69 . V_137 ) ;
F_70 ( & V_140 -> V_96 ) ;
F_38 ( V_47 ) ;
F_93 ( & V_33 -> V_146 ) ;
F_94 ( & V_33 -> V_146 ) ;
F_95 ( & V_33 -> V_69 ) ;
goto V_144;
}
F_70 ( & V_140 -> V_96 ) ;
V_25 = F_62 ( V_33 , V_50 ,
& V_141 ) ;
F_94 ( & V_33 -> V_146 ) ;
if ( V_25 )
goto V_63;
} else {
F_70 ( & V_140 -> V_96 ) ;
}
}
if ( V_47 -> V_54 [ 0 ] ) {
struct V_3 * V_114 ;
int V_22 ;
V_47 -> V_54 [ 0 ] -- ;
V_114 = V_47 -> V_52 [ 0 ] ;
V_22 = V_47 -> V_54 [ 0 ] ;
F_12 ( V_114 , & V_2 , V_22 ) ;
if ( V_2 . V_18 == V_106 &&
( V_2 . type == V_122 ||
V_2 . type == V_126 ) ) {
V_25 = F_71 ( V_57 , V_47 , V_106 ,
& V_113 , & V_88 ) ;
if ( V_25 )
goto V_63;
V_25 = F_83 ( V_57 , V_47 , V_106 ,
V_113 , & V_88 ) ;
if ( V_25 )
goto V_63;
}
}
F_38 ( V_47 ) ;
F_96 ( & V_141 , & V_88 ) ;
V_25 = F_48 ( V_57 , & V_88 ) ;
if ( V_25 )
goto V_63;
F_59 ( & V_88 , 1 ) ;
V_25 = F_39 ( V_57 , V_47 , V_50 , & V_88 ,
V_7 ) ;
if ( V_25 )
goto V_63;
F_59 ( & V_88 , 2 ) ;
while ( ! F_97 ( & V_88 ) ) {
V_39 = F_98 ( & V_88 , struct V_29 , V_43 ) ;
F_37 ( V_39 -> V_37 < 0 ) ;
if ( V_39 -> V_37 && V_39 -> V_34 && V_39 -> V_36 == 0 ) {
V_25 = F_24 ( V_138 , V_39 -> V_34 , 0 , V_14 ) ;
if ( V_25 < 0 )
goto V_63;
}
if ( V_39 -> V_37 && V_39 -> V_36 ) {
if ( V_7 && ! V_39 -> V_42 ) {
T_4 V_147 ;
struct V_3 * V_4 ;
V_147 = F_99 ( V_57 -> V_134 ,
V_113 ) ;
V_4 = F_52 ( V_57 -> V_134 ,
V_39 -> V_36 , V_147 , 0 ) ;
if ( ! V_4 || ! F_53 ( V_4 ) ) {
F_54 ( V_4 ) ;
V_25 = - V_80 ;
goto V_63;
}
V_25 = F_10 ( V_4 , V_106 ,
* V_7 , & V_9 ) ;
F_54 ( V_4 ) ;
if ( V_25 < 0 )
goto V_63;
V_39 -> V_42 = V_9 ;
}
V_25 = F_26 ( V_137 , V_39 -> V_36 ,
( V_55 ) V_39 -> V_42 ,
( T_1 * ) & V_9 , V_14 ) ;
if ( V_25 < 0 )
goto V_63;
if ( ! V_25 && V_7 ) {
F_51 ( ! V_9 ) ;
while ( V_9 -> V_16 )
V_9 = V_9 -> V_16 ;
V_9 -> V_16 = V_39 -> V_42 ;
}
V_9 = NULL ;
}
F_60 ( & V_39 -> V_43 ) ;
F_61 ( V_28 , V_39 ) ;
}
V_63:
F_100 ( V_47 ) ;
while ( ! F_97 ( & V_88 ) ) {
V_39 = F_98 ( & V_88 , struct V_29 , V_43 ) ;
F_60 ( & V_39 -> V_43 ) ;
F_61 ( V_28 , V_39 ) ;
}
while ( ! F_97 ( & V_141 ) ) {
V_39 = F_98 ( & V_141 , struct V_29 ,
V_43 ) ;
F_60 ( & V_39 -> V_43 ) ;
F_61 ( V_28 , V_39 ) ;
}
if ( V_25 < 0 )
F_8 ( V_9 ) ;
return V_25 ;
}
static void F_101 ( struct V_48 * V_148 )
{
struct V_68 * V_69 = NULL ;
struct V_8 * V_9 ;
struct V_70 V_71 ;
F_42 ( & V_71 ) ;
while ( ( V_69 = F_43 ( V_148 , & V_71 ) ) ) {
if ( ! V_69 -> V_74 )
continue;
V_9 = (struct V_8 * ) ( V_55 ) V_69 -> V_74 ;
F_8 ( V_9 ) ;
V_69 -> V_74 = 0 ;
}
F_46 ( V_148 ) ;
}
static int F_102 ( struct V_135 * V_136 ,
struct V_56 * V_57 , T_1 V_106 ,
T_1 V_50 , struct V_48 * * V_149 ,
const T_1 * V_7 )
{
struct V_48 * V_150 ;
int V_25 ;
V_150 = F_40 ( V_14 ) ;
if ( ! V_150 )
return - V_15 ;
* V_149 = F_40 ( V_14 ) ;
if ( ! * V_149 ) {
F_46 ( V_150 ) ;
return - V_15 ;
}
V_25 = F_85 ( V_136 , V_57 , V_106 ,
V_50 , * V_149 , V_150 , V_7 ) ;
F_46 ( V_150 ) ;
if ( V_25 < 0 && V_25 != - V_72 ) {
F_101 ( * V_149 ) ;
return V_25 ;
}
return 0 ;
}
int F_103 ( struct V_135 * V_136 ,
struct V_56 * V_57 , T_1 V_106 ,
T_1 V_50 , struct V_48 * * V_138 )
{
struct V_48 * V_150 ;
struct V_68 * V_69 = NULL ;
struct V_70 V_71 ;
int V_25 ;
V_150 = F_40 ( V_14 ) ;
if ( ! V_150 )
return - V_15 ;
* V_138 = F_40 ( V_14 ) ;
if ( ! * V_138 ) {
F_46 ( V_150 ) ;
return - V_15 ;
}
F_42 ( & V_71 ) ;
while ( 1 ) {
V_25 = F_85 ( V_136 , V_57 , V_106 ,
V_50 , V_150 , * V_138 , NULL ) ;
if ( V_25 < 0 && V_25 != - V_72 ) {
F_46 ( V_150 ) ;
F_46 ( * V_138 ) ;
return V_25 ;
}
V_69 = F_43 ( V_150 , & V_71 ) ;
if ( ! V_69 )
break;
V_106 = V_69 -> V_73 ;
F_104 () ;
}
F_46 ( V_150 ) ;
return 0 ;
}
int F_105 ( T_1 V_17 , T_1 V_151 , struct V_44 * V_152 ,
struct V_46 * V_47 )
{
struct V_1 V_2 ;
return F_106 ( V_152 , V_47 , V_17 , V_151 ,
V_153 , & V_2 ) ;
}
static int F_107 ( T_1 V_17 , T_1 V_151 , struct V_44 * V_152 ,
struct V_46 * V_47 ,
struct V_1 * V_115 )
{
return F_106 ( V_152 , V_47 , V_17 , V_151 ,
V_154 , V_115 ) ;
}
int F_108 ( struct V_44 * V_45 , T_1 V_155 ,
T_1 V_156 , struct V_46 * V_47 ,
struct V_157 * * V_158 ,
T_1 * V_159 )
{
int V_25 , V_22 ;
struct V_1 V_2 ;
struct V_1 V_115 ;
struct V_157 * V_160 ;
struct V_3 * V_114 ;
unsigned long V_116 ;
V_2 . V_18 = V_155 ;
F_109 ( & V_2 , V_161 ) ;
V_2 . V_10 = V_156 ;
V_25 = F_89 ( NULL , V_45 , & V_2 , V_47 , 0 , 0 ) ;
if ( V_25 < 0 )
return V_25 ;
while ( 1 ) {
V_114 = V_47 -> V_52 [ 0 ] ;
V_22 = V_47 -> V_54 [ 0 ] ;
if ( V_22 >= F_11 ( V_114 ) ) {
V_25 = F_110 ( V_45 , V_47 ) ;
if ( V_25 ) {
if ( V_25 >= 1 )
V_25 = - V_72 ;
break;
}
continue;
}
F_12 ( V_114 , & V_115 , V_22 ) ;
V_25 = - V_72 ;
if ( V_115 . V_18 != V_155 )
break;
if ( F_111 ( & V_115 ) != V_161 )
break;
V_25 = 0 ;
V_116 = F_112 ( V_114 , V_47 -> V_54 [ 0 ] ) ;
V_160 = (struct V_157 * ) V_116 ;
* V_158 = V_160 ;
if ( V_159 )
* V_159 = V_115 . V_10 ;
break;
}
return V_25 ;
}
char * F_113 ( struct V_44 * V_152 , struct V_46 * V_47 ,
T_4 V_162 , unsigned long V_163 ,
struct V_3 * V_164 , T_1 V_36 ,
char * V_165 , T_4 V_166 )
{
int V_22 ;
T_1 V_167 ;
int V_25 ;
T_5 V_168 = ( ( T_5 ) V_166 ) - 1 ;
struct V_3 * V_4 = V_164 ;
struct V_1 V_115 ;
int V_169 = V_47 -> V_169 ;
struct V_170 * V_129 ;
if ( V_168 >= 0 )
V_165 [ V_168 ] = '\0' ;
V_47 -> V_169 = 1 ;
while ( 1 ) {
V_168 -= V_162 ;
if ( V_168 >= 0 )
F_114 ( V_4 , V_165 + V_168 ,
V_163 , V_162 ) ;
if ( V_4 != V_164 ) {
F_115 ( V_4 ) ;
F_54 ( V_4 ) ;
}
V_25 = F_107 ( V_36 , 0 , V_152 , V_47 , & V_115 ) ;
if ( V_25 > 0 )
V_25 = - V_72 ;
if ( V_25 )
break;
V_167 = V_115 . V_10 ;
if ( V_36 == V_167 )
break;
V_22 = V_47 -> V_54 [ 0 ] ;
V_4 = V_47 -> V_52 [ 0 ] ;
if ( V_4 != V_164 ) {
F_92 ( & V_4 -> V_137 ) ;
F_55 ( V_4 ) ;
F_116 ( V_4 , V_171 ) ;
}
F_38 ( V_47 ) ;
V_129 = F_13 ( V_4 , V_22 , struct V_170 ) ;
V_162 = F_117 ( V_4 , V_129 ) ;
V_163 = ( unsigned long ) ( V_129 + 1 ) ;
V_36 = V_167 ;
-- V_168 ;
if ( V_168 >= 0 )
V_165 [ V_168 ] = '/' ;
}
F_38 ( V_47 ) ;
V_47 -> V_169 = V_169 ;
if ( V_25 )
return F_118 ( V_25 ) ;
return V_165 + V_168 ;
}
int F_119 ( struct V_56 * V_57 , T_1 V_172 ,
struct V_46 * V_47 , struct V_1 * V_115 ,
T_1 * V_173 )
{
int V_25 ;
T_1 V_120 ;
T_1 V_166 = 0 ;
T_4 V_121 ;
struct V_3 * V_4 ;
struct V_118 * V_119 ;
struct V_1 V_2 ;
if ( F_87 ( V_57 , V_142 ) )
V_2 . type = V_126 ;
else
V_2 . type = V_122 ;
V_2 . V_18 = V_172 ;
V_2 . V_10 = ( T_1 ) - 1 ;
V_25 = F_89 ( NULL , V_57 -> V_134 , & V_2 , V_47 , 0 , 0 ) ;
if ( V_25 < 0 )
return V_25 ;
while ( 1 ) {
T_4 V_23 ;
if ( V_47 -> V_54 [ 0 ] == 0 ) {
F_120 ( V_47 ) ;
V_25 = F_121 ( V_57 -> V_134 , V_47 ) ;
if ( V_25 != 0 ) {
if ( V_25 > 0 ) {
F_36 ( L_4
L_5 , V_172 ) ;
V_25 = - V_72 ;
}
return V_25 ;
}
} else {
V_47 -> V_54 [ 0 ] -- ;
}
V_23 = F_11 ( V_47 -> V_52 [ 0 ] ) ;
if ( V_23 == 0 ) {
F_36 ( L_6 ,
V_172 ) ;
return - V_72 ;
}
if ( V_47 -> V_54 [ 0 ] == V_23 )
V_47 -> V_54 [ 0 ] -- ;
F_12 ( V_47 -> V_52 [ 0 ] , V_115 ,
V_47 -> V_54 [ 0 ] ) ;
if ( V_115 -> type == V_122 ||
V_115 -> type == V_126 )
break;
}
if ( V_115 -> type == V_126 )
V_166 = V_57 -> V_134 -> V_79 ;
else if ( V_115 -> type == V_122 )
V_166 = V_115 -> V_10 ;
if ( V_115 -> V_18 > V_172 ||
V_115 -> V_18 + V_166 <= V_172 ) {
F_36 ( L_6 , V_172 ) ;
return - V_72 ;
}
V_4 = V_47 -> V_52 [ 0 ] ;
V_121 = F_72 ( V_4 , V_47 -> V_54 [ 0 ] ) ;
F_51 ( V_121 < sizeof( * V_119 ) ) ;
V_119 = F_13 ( V_4 , V_47 -> V_54 [ 0 ] , struct V_118 ) ;
V_120 = F_73 ( V_4 , V_119 ) ;
F_36 ( L_7
L_8 ,
V_172 , V_172 - V_115 -> V_18 , V_115 -> V_18 ,
V_115 -> V_10 , V_120 , V_121 ) ;
F_37 ( ! V_173 ) ;
if ( V_173 ) {
if ( V_120 & V_123 )
* V_173 = V_123 ;
else if ( V_120 & V_127 )
* V_173 = V_127 ;
else
F_51 ( 1 ) ;
return 0 ;
}
return - V_80 ;
}
static int F_122 ( unsigned long * V_116 , struct V_3 * V_4 ,
struct V_118 * V_119 , T_4 V_121 ,
struct V_128 * * V_174 ,
int * V_175 )
{
unsigned long V_117 ;
T_1 V_120 ;
struct V_124 * V_125 ;
if ( ! * V_116 ) {
V_120 = F_73 ( V_4 , V_119 ) ;
if ( V_120 & V_123 ) {
V_125 = (struct V_124 * ) ( V_119 + 1 ) ;
* V_174 =
(struct V_128 * ) ( V_125 + 1 ) ;
} else {
* V_174 = (struct V_128 * ) ( V_119 + 1 ) ;
}
* V_116 = ( unsigned long ) * V_174 ;
if ( ( void * ) * V_116 >= ( void * ) V_119 + V_121 )
return - V_72 ;
}
V_117 = ( unsigned long ) V_119 + V_121 ;
* V_174 = (struct V_128 * ) * V_116 ;
* V_175 = F_75 ( V_4 , * V_174 ) ;
* V_116 += F_82 ( * V_175 ) ;
F_37 ( * V_116 > V_117 ) ;
if ( * V_116 == V_117 )
return 1 ;
return 0 ;
}
int F_123 ( unsigned long * V_116 , struct V_3 * V_4 ,
struct V_118 * V_119 , T_4 V_121 ,
T_1 * V_176 , T_6 * V_177 )
{
int V_25 ;
int type ;
struct V_124 * V_125 ;
struct V_128 * V_178 ;
if ( * V_116 == ( unsigned long ) - 1 )
return 1 ;
while ( 1 ) {
V_25 = F_122 ( V_116 , V_4 , V_119 , V_121 ,
& V_178 , & type ) ;
if ( V_25 < 0 )
return V_25 ;
if ( type == V_104 ||
type == V_109 )
break;
if ( V_25 == 1 )
return 1 ;
}
V_125 = (struct V_124 * ) ( V_119 + 1 ) ;
* V_176 = F_76 ( V_4 , V_178 ) ;
* V_177 = F_74 ( V_4 , V_125 ) ;
if ( V_25 == 1 )
* V_116 = ( unsigned long ) - 1 ;
return 0 ;
}
static int F_124 ( struct V_8 * V_42 ,
T_1 V_45 , T_1 V_179 ,
T_7 * V_180 , void * V_181 )
{
struct V_8 * V_9 ;
int V_25 = 0 ;
for ( V_9 = V_42 ; V_9 ; V_9 = V_9 -> V_16 ) {
F_36 ( L_9
L_10 , V_179 ,
V_9 -> V_17 , V_9 -> V_10 , V_45 ) ;
V_25 = V_180 ( V_9 -> V_17 , V_9 -> V_10 , V_45 , V_181 ) ;
if ( V_25 ) {
F_36 ( L_11 ,
V_179 , V_25 ) ;
break;
}
}
return V_25 ;
}
int F_125 ( struct V_56 * V_57 ,
T_1 V_179 , T_1 V_7 ,
int V_143 ,
T_7 * V_180 , void * V_181 )
{
int V_25 ;
struct V_135 * V_136 = NULL ;
struct V_48 * V_137 = NULL ;
struct V_48 * V_138 = NULL ;
struct V_68 * V_182 = NULL ;
struct V_68 * V_183 = NULL ;
struct V_184 V_185 = {} ;
struct V_70 V_186 ;
struct V_70 V_187 ;
F_36 ( L_12 ,
V_179 ) ;
if ( ! V_143 ) {
V_136 = F_126 ( V_57 -> V_134 ) ;
if ( F_31 ( V_136 ) )
return F_33 ( V_136 ) ;
F_127 ( V_57 , & V_185 ) ;
}
V_25 = F_102 ( V_136 , V_57 , V_179 ,
V_185 . V_87 , & V_137 ,
& V_7 ) ;
if ( V_25 )
goto V_63;
F_42 ( & V_186 ) ;
while ( ! V_25 && ( V_182 = F_43 ( V_137 , & V_186 ) ) ) {
V_25 = F_103 ( V_136 , V_57 , V_182 -> V_73 ,
V_185 . V_87 , & V_138 ) ;
if ( V_25 )
break;
F_42 ( & V_187 ) ;
while ( ! V_25 && ( V_183 = F_43 ( V_138 , & V_187 ) ) ) {
F_36 ( L_13
L_14 , V_183 -> V_73 , V_182 -> V_73 ,
V_182 -> V_74 ) ;
V_25 = F_124 ( (struct V_8 * )
( V_55 ) V_182 -> V_74 ,
V_183 -> V_73 ,
V_179 ,
V_180 , V_181 ) ;
}
F_46 ( V_138 ) ;
}
F_101 ( V_137 ) ;
V_63:
if ( ! V_143 ) {
F_128 ( V_57 , & V_185 ) ;
F_129 ( V_136 , V_57 -> V_134 ) ;
}
return V_25 ;
}
int F_130 ( T_1 V_172 , struct V_56 * V_57 ,
struct V_46 * V_47 ,
T_7 * V_180 , void * V_181 )
{
int V_25 ;
T_1 V_7 ;
T_1 V_120 = 0 ;
struct V_1 V_115 ;
int V_143 = V_47 -> V_143 ;
V_25 = F_119 ( V_57 , V_172 , V_47 , & V_115 , & V_120 ) ;
F_38 ( V_47 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_120 & V_123 )
return - V_188 ;
V_7 = V_172 - V_115 . V_18 ;
V_25 = F_125 ( V_57 , V_115 . V_18 ,
V_7 , V_143 ,
V_180 , V_181 ) ;
return V_25 ;
}
static int F_131 ( T_1 V_17 , struct V_44 * V_152 ,
struct V_46 * V_47 ,
T_8 * V_180 , void * V_181 )
{
int V_25 = 0 ;
int V_22 ;
T_4 V_189 ;
T_4 V_190 ;
T_4 V_162 ;
T_1 V_36 = 0 ;
int V_191 = 0 ;
struct V_3 * V_4 ;
struct V_192 * V_193 ;
struct V_170 * V_129 ;
struct V_1 V_115 ;
while ( ! V_25 ) {
V_25 = F_107 ( V_17 , V_36 ? V_36 + 1 : 0 , V_152 , V_47 ,
& V_115 ) ;
if ( V_25 < 0 )
break;
if ( V_25 ) {
V_25 = V_191 ? 0 : - V_72 ;
break;
}
++ V_191 ;
V_36 = V_115 . V_10 ;
V_22 = V_47 -> V_54 [ 0 ] ;
V_4 = F_132 ( V_47 -> V_52 [ 0 ] ) ;
if ( ! V_4 ) {
V_25 = - V_15 ;
break;
}
F_133 ( V_4 ) ;
F_55 ( V_4 ) ;
F_116 ( V_4 , V_171 ) ;
F_38 ( V_47 ) ;
V_193 = F_134 ( V_22 ) ;
V_129 = F_13 ( V_4 , V_22 , struct V_170 ) ;
for ( V_189 = 0 ; V_189 < F_135 ( V_4 , V_193 ) ; V_189 += V_190 ) {
V_162 = F_117 ( V_4 , V_129 ) ;
F_36 ( L_15
L_16 , V_189 , V_115 . V_18 ,
V_152 -> V_18 ) ;
V_25 = V_180 ( V_36 , V_162 ,
( unsigned long ) ( V_129 + 1 ) , V_4 , V_181 ) ;
if ( V_25 )
break;
V_190 = sizeof( * V_129 ) + V_162 ;
V_129 = (struct V_170 * ) ( ( char * ) V_129 + V_190 ) ;
}
F_115 ( V_4 ) ;
F_54 ( V_4 ) ;
}
F_38 ( V_47 ) ;
return V_25 ;
}
static int F_136 ( T_1 V_17 , struct V_44 * V_152 ,
struct V_46 * V_47 ,
T_8 * V_180 , void * V_181 )
{
int V_25 ;
int V_22 ;
T_1 V_10 = 0 ;
T_1 V_36 ;
int V_191 = 0 ;
struct V_3 * V_4 ;
struct V_157 * V_160 ;
struct V_3 * V_114 ;
T_4 V_121 ;
T_4 V_194 ;
unsigned long V_116 ;
while ( 1 ) {
V_25 = F_108 ( V_152 , V_17 , V_10 , V_47 , & V_160 ,
& V_10 ) ;
if ( V_25 < 0 )
break;
if ( V_25 ) {
V_25 = V_191 ? 0 : - V_72 ;
break;
}
++ V_191 ;
V_22 = V_47 -> V_54 [ 0 ] ;
V_4 = F_132 ( V_47 -> V_52 [ 0 ] ) ;
if ( ! V_4 ) {
V_25 = - V_15 ;
break;
}
F_133 ( V_4 ) ;
F_55 ( V_4 ) ;
F_116 ( V_4 , V_171 ) ;
F_38 ( V_47 ) ;
V_114 = V_47 -> V_52 [ 0 ] ;
V_121 = F_72 ( V_114 , V_22 ) ;
V_116 = F_112 ( V_114 , V_22 ) ;
V_194 = 0 ;
while ( V_194 < V_121 ) {
T_4 V_162 ;
V_160 = (struct V_157 * ) ( V_116 + V_194 ) ;
V_36 = F_137 ( V_4 , V_160 ) ;
V_162 = F_138 ( V_4 , V_160 ) ;
V_25 = V_180 ( V_36 , V_162 ,
( unsigned long ) & V_160 -> V_195 , V_4 , V_181 ) ;
if ( V_25 )
break;
V_194 += F_138 ( V_114 , V_160 ) ;
V_194 += sizeof( * V_160 ) ;
}
F_115 ( V_4 ) ;
F_54 ( V_4 ) ;
V_10 ++ ;
}
F_38 ( V_47 ) ;
return V_25 ;
}
static int F_139 ( T_1 V_17 , struct V_44 * V_152 ,
struct V_46 * V_47 , T_8 * V_180 ,
void * V_181 )
{
int V_25 ;
int V_196 = 0 ;
V_25 = F_131 ( V_17 , V_152 , V_47 , V_180 , V_181 ) ;
if ( ! V_25 )
++ V_196 ;
else if ( V_25 != - V_72 )
return V_25 ;
V_25 = F_136 ( V_17 , V_152 , V_47 , V_180 , V_181 ) ;
if ( V_25 == - V_72 && V_196 )
return 0 ;
return V_25 ;
}
static int F_140 ( T_1 V_17 , T_4 V_162 , unsigned long V_163 ,
struct V_3 * V_4 , void * V_181 )
{
struct V_197 * V_198 = V_181 ;
char * V_199 ;
char * V_200 ;
int V_201 = V_198 -> V_199 -> V_202 ;
const int V_203 = sizeof( char * ) ;
T_4 V_168 ;
V_168 = V_198 -> V_199 -> V_168 > V_203 ?
V_198 -> V_199 -> V_168 - V_203 : 0 ;
V_200 = ( char * ) V_198 -> V_199 -> V_73 + ( V_201 + 1 ) * V_203 ;
V_199 = F_113 ( V_198 -> V_152 , V_198 -> V_46 , V_162 ,
V_163 , V_4 , V_17 , V_200 , V_168 ) ;
if ( F_31 ( V_199 ) )
return F_33 ( V_199 ) ;
if ( V_199 > V_200 ) {
V_198 -> V_199 -> V_73 [ V_201 ] = ( T_1 ) ( unsigned long ) V_199 ;
++ V_198 -> V_199 -> V_202 ;
V_198 -> V_199 -> V_168 = V_199 - V_200 ;
} else {
++ V_198 -> V_199 -> V_204 ;
V_198 -> V_199 -> V_205 += V_200 - V_199 ;
V_198 -> V_199 -> V_168 = 0 ;
}
return 0 ;
}
int F_141 ( T_1 V_17 , struct V_197 * V_198 )
{
return F_139 ( V_17 , V_198 -> V_152 , V_198 -> V_46 ,
F_140 , V_198 ) ;
}
struct V_206 * F_142 ( T_4 V_207 )
{
struct V_206 * V_208 ;
T_9 V_209 ;
V_209 = F_143 ( T_9 , V_207 , sizeof( * V_208 ) ) ;
V_208 = F_144 ( V_209 ) ;
if ( ! V_208 )
return F_118 ( - V_15 ) ;
if ( V_207 >= sizeof( * V_208 ) ) {
V_208 -> V_168 = V_207 - sizeof( * V_208 ) ;
V_208 -> V_205 = 0 ;
} else {
V_208 -> V_205 = sizeof( * V_208 ) - V_207 ;
V_208 -> V_168 = 0 ;
}
V_208 -> V_202 = 0 ;
V_208 -> V_204 = 0 ;
return V_208 ;
}
struct V_197 * F_145 ( T_10 V_207 , struct V_44 * V_152 ,
struct V_46 * V_47 )
{
struct V_197 * V_210 ;
struct V_206 * V_199 ;
V_199 = F_142 ( V_207 ) ;
if ( F_31 ( V_199 ) )
return ( void * ) V_199 ;
V_210 = F_7 ( sizeof( * V_210 ) , V_14 ) ;
if ( ! V_210 ) {
F_9 ( V_199 ) ;
return F_118 ( - V_15 ) ;
}
V_210 -> V_46 = V_47 ;
V_210 -> V_199 = V_199 ;
V_210 -> V_152 = V_152 ;
return V_210 ;
}
void F_146 ( struct V_197 * V_198 )
{
if ( ! V_198 )
return;
F_147 ( V_198 -> V_199 ) ;
F_9 ( V_198 ) ;
}
