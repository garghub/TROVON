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
int V_35 , T_1 V_50 , const T_1 * V_7 ,
T_1 V_51 )
{
int V_25 = 0 ;
int V_22 ;
struct V_3 * V_4 ;
struct V_1 V_2 ;
struct V_1 * V_41 = & V_39 -> V_41 ;
struct V_5 * V_6 ;
struct V_8 * V_9 = NULL , * V_52 = NULL ;
T_1 V_21 ;
T_1 V_20 = V_39 -> V_20 ;
T_1 V_37 = 0 ;
if ( V_35 != 0 ) {
V_4 = V_47 -> V_53 [ V_35 ] ;
V_25 = F_24 ( V_49 , V_4 -> V_54 , 0 , V_14 ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
if ( V_47 -> V_55 [ 0 ] >= F_11 ( V_47 -> V_53 [ 0 ] ) )
V_25 = F_25 ( V_45 , V_47 , V_50 ) ;
while ( ! V_25 && V_37 < V_51 ) {
V_4 = V_47 -> V_53 [ 0 ] ;
V_22 = V_47 -> V_55 [ 0 ] ;
F_12 ( V_4 , & V_2 , V_22 ) ;
if ( V_2 . V_18 != V_41 -> V_18 ||
V_2 . type != V_26 )
break;
V_6 = F_13 ( V_4 , V_22 , struct V_5 ) ;
V_21 = F_15 ( V_4 , V_6 ) ;
if ( V_21 == V_20 ) {
V_9 = NULL ;
V_52 = NULL ;
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
V_25 = F_26 ( V_49 , V_4 -> V_54 ,
( V_56 ) V_9 ,
( T_1 * ) & V_52 , V_14 ) ;
if ( V_25 < 0 )
break;
if ( ! V_25 && V_7 ) {
while ( V_52 -> V_16 )
V_52 = V_52 -> V_16 ;
V_52 -> V_16 = V_9 ;
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
static int F_28 ( struct V_57 * V_58 ,
struct V_46 * V_47 , T_1 V_50 ,
struct V_29 * V_39 ,
struct V_48 * V_49 ,
const T_1 * V_7 , T_1 V_51 )
{
struct V_44 * V_45 ;
struct V_1 V_59 ;
struct V_3 * V_4 ;
int V_25 = 0 ;
int V_60 ;
int V_35 = V_39 -> V_35 ;
int V_61 ;
V_59 . V_18 = V_39 -> V_34 ;
V_59 . type = V_62 ;
V_59 . V_10 = ( T_1 ) - 1 ;
V_61 = F_29 ( & V_58 -> V_63 ) ;
V_45 = F_30 ( V_58 , & V_59 ) ;
if ( F_31 ( V_45 ) ) {
F_32 ( & V_58 -> V_63 , V_61 ) ;
V_25 = F_33 ( V_45 ) ;
goto V_64;
}
if ( V_47 -> V_65 )
V_60 = F_34 ( V_45 -> V_66 ) ;
else
V_60 = F_35 ( V_45 , V_50 ) ;
if ( V_60 + 1 == V_35 ) {
F_32 ( & V_58 -> V_63 , V_61 ) ;
goto V_64;
}
V_47 -> V_67 = V_35 ;
V_25 = F_36 ( V_45 , & V_39 -> V_41 , V_47 , V_50 ) ;
F_32 ( & V_58 -> V_63 , V_61 ) ;
F_37 ( L_2
L_3 ,
V_39 -> V_34 , V_35 , V_39 -> V_37 , V_25 ,
V_39 -> V_41 . V_18 , V_39 -> V_41 . type ,
V_39 -> V_41 . V_10 ) ;
if ( V_25 < 0 )
goto V_64;
V_4 = V_47 -> V_53 [ V_35 ] ;
while ( ! V_4 ) {
if ( F_38 ( ! V_35 ) ) {
V_25 = 1 ;
goto V_64;
}
V_35 -- ;
V_4 = V_47 -> V_53 [ V_35 ] ;
}
V_25 = F_23 ( V_45 , V_47 , V_49 , V_39 , V_35 , V_50 ,
V_7 , V_51 ) ;
V_64:
V_47 -> V_67 = 0 ;
F_39 ( V_47 ) ;
return V_25 ;
}
static int F_40 ( struct V_57 * V_58 ,
struct V_46 * V_47 , T_1 V_50 ,
struct V_32 * V_33 ,
const T_1 * V_7 , T_1 V_51 )
{
int V_68 ;
int V_25 = 0 ;
struct V_29 * V_39 ;
struct V_29 * V_69 ;
struct V_29 * V_70 ;
struct V_48 * V_49 ;
struct V_71 * V_72 ;
struct V_73 V_74 ;
V_49 = F_41 ( V_14 ) ;
if ( ! V_49 )
return - V_15 ;
F_42 (ref, ref_safe, head, list) {
if ( V_39 -> V_36 )
continue;
if ( V_39 -> V_37 == 0 )
continue;
V_68 = F_28 ( V_58 , V_47 , V_50 , V_39 ,
V_49 , V_7 ,
V_51 ) ;
if ( V_68 == - V_75 ) {
continue;
} else if ( V_68 ) {
V_25 = V_68 ;
goto V_64;
}
F_43 ( & V_74 ) ;
V_72 = F_44 ( V_49 , & V_74 ) ;
V_39 -> V_36 = V_72 ? V_72 -> V_76 : 0 ;
V_39 -> V_42 = V_72 ?
(struct V_8 * ) ( V_56 ) V_72 -> V_77 : NULL ;
while ( ( V_72 = F_44 ( V_49 , & V_74 ) ) ) {
V_70 = F_21 ( V_28 ,
V_14 ) ;
if ( ! V_70 ) {
V_25 = - V_15 ;
goto V_64;
}
memcpy ( V_70 , V_39 , sizeof( * V_39 ) ) ;
V_70 -> V_36 = V_72 -> V_76 ;
V_70 -> V_42 = (struct V_8 * )
( V_56 ) V_72 -> V_77 ;
F_45 ( & V_70 -> V_43 , & V_39 -> V_43 ) ;
}
F_46 ( V_49 ) ;
}
V_64:
F_47 ( V_49 ) ;
return V_25 ;
}
static inline int F_48 ( struct V_29 * V_78 ,
struct V_29 * V_79 )
{
if ( V_78 -> V_35 != V_79 -> V_35 )
return 0 ;
if ( V_78 -> V_34 != V_79 -> V_34 )
return 0 ;
if ( V_78 -> V_41 . type != V_79 -> V_41 . type )
return 0 ;
if ( V_78 -> V_41 . V_18 != V_79 -> V_41 . V_18 )
return 0 ;
if ( V_78 -> V_41 . V_10 != V_79 -> V_41 . V_10 )
return 0 ;
if ( V_78 -> V_36 != V_79 -> V_36 )
return 0 ;
return 1 ;
}
static int F_49 ( struct V_57 * V_58 ,
struct V_32 * V_33 )
{
struct V_32 * V_80 ;
struct V_3 * V_4 ;
F_50 (pos, head) {
struct V_29 * V_39 ;
V_39 = F_51 ( V_80 , struct V_29 , V_43 ) ;
if ( V_39 -> V_36 )
continue;
if ( V_39 -> V_41 . type )
continue;
F_52 ( ! V_39 -> V_20 ) ;
V_4 = F_53 ( V_58 -> V_81 , V_39 -> V_20 ,
V_58 -> V_81 -> V_82 , 0 ) ;
if ( ! V_4 || ! F_54 ( V_4 ) ) {
F_55 ( V_4 ) ;
return - V_83 ;
}
F_56 ( V_4 ) ;
if ( F_34 ( V_4 ) == 0 )
F_12 ( V_4 , & V_39 -> V_41 , 0 ) ;
else
F_57 ( V_4 , & V_39 -> V_41 , 0 ) ;
F_58 ( V_4 ) ;
F_55 ( V_4 ) ;
}
return 0 ;
}
static void F_59 ( struct V_32 * V_33 , int V_84 )
{
struct V_32 * V_85 ;
F_50 (pos1, head) {
struct V_32 * V_86 ;
struct V_32 * V_87 ;
struct V_29 * V_78 ;
V_78 = F_51 ( V_85 , struct V_29 , V_43 ) ;
for ( V_87 = V_85 -> V_16 , V_86 = V_87 -> V_16 ; V_87 != V_33 ;
V_87 = V_86 , V_86 = V_87 -> V_16 ) {
struct V_29 * V_79 ;
struct V_29 * V_88 ;
struct V_8 * V_9 ;
V_79 = F_51 ( V_87 , struct V_29 , V_43 ) ;
if ( V_84 == 1 ) {
if ( ! F_48 ( V_78 , V_79 ) )
continue;
if ( ! V_78 -> V_36 && V_79 -> V_36 ) {
V_88 = V_78 ;
V_78 = V_79 ;
V_79 = V_88 ;
}
} else {
if ( V_78 -> V_36 != V_79 -> V_36 )
continue;
}
V_9 = V_78 -> V_42 ;
while ( V_9 && V_9 -> V_16 )
V_9 = V_9 -> V_16 ;
if ( V_9 )
V_9 -> V_16 = V_79 -> V_42 ;
else
V_78 -> V_42 = V_79 -> V_42 ;
V_78 -> V_37 += V_79 -> V_37 ;
F_60 ( & V_79 -> V_43 ) ;
F_61 ( V_28 , V_79 ) ;
}
}
}
static int F_62 ( struct V_89 * V_33 , T_1 V_90 ,
struct V_32 * V_91 , T_1 * V_51 )
{
struct V_92 * V_93 = V_33 -> V_93 ;
struct V_94 * V_95 = & V_33 -> V_72 . V_94 ;
struct V_1 V_2 ;
struct V_1 V_96 = { 0 } ;
int V_97 ;
int V_25 = 0 ;
if ( V_93 && V_93 -> V_98 )
F_63 ( & V_96 , & V_93 -> V_2 ) ;
F_64 ( & V_33 -> V_99 ) ;
V_95 = F_65 ( & V_33 -> V_100 ) ;
while ( V_95 ) {
struct V_101 * V_72 ;
V_72 = F_66 ( V_95 , struct V_101 ,
V_94 ) ;
V_95 = F_67 ( V_95 ) ;
if ( V_72 -> V_90 > V_90 )
continue;
switch ( V_72 -> V_102 ) {
case V_103 :
case V_104 :
F_38 ( 1 ) ;
continue;
case V_105 :
V_97 = 1 ;
break;
case V_106 :
V_97 = - 1 ;
break;
default:
F_52 ( 1 ) ;
}
* V_51 += ( V_72 -> V_107 * V_97 ) ;
switch ( V_72 -> type ) {
case V_108 : {
struct V_109 * V_39 ;
V_39 = F_68 ( V_72 ) ;
V_25 = F_20 ( V_91 , V_39 -> V_45 , & V_96 ,
V_39 -> V_35 + 1 , 0 , V_72 -> V_110 ,
V_72 -> V_107 * V_97 , V_111 ) ;
break;
}
case V_112 : {
struct V_109 * V_39 ;
V_39 = F_68 ( V_72 ) ;
V_25 = F_20 ( V_91 , V_39 -> V_45 , NULL ,
V_39 -> V_35 + 1 , V_39 -> V_36 ,
V_72 -> V_110 ,
V_72 -> V_107 * V_97 , V_111 ) ;
break;
}
case V_113 : {
struct V_114 * V_39 ;
V_39 = F_69 ( V_72 ) ;
V_2 . V_18 = V_39 -> V_18 ;
V_2 . type = V_26 ;
V_2 . V_10 = V_39 -> V_10 ;
V_25 = F_20 ( V_91 , V_39 -> V_45 , & V_2 , 0 , 0 ,
V_72 -> V_110 ,
V_72 -> V_107 * V_97 , V_111 ) ;
break;
}
case V_115 : {
struct V_114 * V_39 ;
V_39 = F_69 ( V_72 ) ;
V_2 . V_18 = V_39 -> V_18 ;
V_2 . type = V_26 ;
V_2 . V_10 = V_39 -> V_10 ;
V_25 = F_20 ( V_91 , V_39 -> V_45 , & V_2 , 0 ,
V_39 -> V_36 , V_72 -> V_110 ,
V_72 -> V_107 * V_97 , V_111 ) ;
break;
}
default:
F_38 ( 1 ) ;
}
if ( V_25 )
break;
}
F_70 ( & V_33 -> V_99 ) ;
return V_25 ;
}
static int F_71 ( struct V_57 * V_58 ,
struct V_46 * V_47 , T_1 V_110 ,
int * V_116 , struct V_32 * V_91 ,
T_1 * V_51 )
{
int V_25 = 0 ;
int V_22 ;
struct V_3 * V_117 ;
struct V_1 V_2 ;
struct V_1 V_118 ;
unsigned long V_119 ;
unsigned long V_120 ;
struct V_121 * V_122 ;
T_1 V_123 ;
T_1 V_124 ;
V_117 = V_47 -> V_53 [ 0 ] ;
V_22 = V_47 -> V_55 [ 0 ] ;
V_124 = F_72 ( V_117 , V_22 ) ;
F_52 ( V_124 < sizeof( * V_122 ) ) ;
V_122 = F_13 ( V_117 , V_22 , struct V_121 ) ;
V_123 = F_73 ( V_117 , V_122 ) ;
* V_51 += F_74 ( V_117 , V_122 ) ;
F_12 ( V_117 , & V_118 , V_22 ) ;
V_119 = ( unsigned long ) ( V_122 + 1 ) ;
V_120 = ( unsigned long ) V_122 + V_124 ;
if ( V_118 . type == V_125 &&
V_123 & V_126 ) {
struct V_127 * V_128 ;
V_128 = (struct V_127 * ) V_119 ;
* V_116 = F_75 ( V_117 , V_128 ) ;
V_119 += sizeof( struct V_127 ) ;
F_52 ( V_119 > V_120 ) ;
} else if ( V_118 . type == V_129 ) {
* V_116 = V_118 . V_10 ;
} else {
F_52 ( ! ( V_123 & V_130 ) ) ;
}
while ( V_119 < V_120 ) {
struct V_131 * V_132 ;
T_1 V_10 ;
int type ;
V_132 = (struct V_131 * ) V_119 ;
type = F_76 ( V_117 , V_132 ) ;
V_10 = F_77 ( V_117 , V_132 ) ;
switch ( type ) {
case V_112 :
V_25 = F_20 ( V_91 , 0 , NULL ,
* V_116 + 1 , V_10 ,
V_110 , 1 , V_14 ) ;
break;
case V_115 : {
struct V_133 * V_134 ;
int V_37 ;
V_134 = (struct V_133 * ) ( V_132 + 1 ) ;
V_37 = F_78 ( V_117 , V_134 ) ;
V_25 = F_20 ( V_91 , 0 , NULL , 0 , V_10 ,
V_110 , V_37 , V_14 ) ;
break;
}
case V_108 :
V_25 = F_20 ( V_91 , V_10 , NULL ,
* V_116 + 1 , 0 ,
V_110 , 1 , V_14 ) ;
break;
case V_113 : {
struct V_135 * V_136 ;
int V_37 ;
T_1 V_45 ;
V_136 = (struct V_135 * ) ( & V_132 -> V_10 ) ;
V_37 = F_79 ( V_117 , V_136 ) ;
V_2 . V_18 = F_80 ( V_117 ,
V_136 ) ;
V_2 . type = V_26 ;
V_2 . V_10 = F_81 ( V_117 , V_136 ) ;
V_45 = F_82 ( V_117 , V_136 ) ;
V_25 = F_20 ( V_91 , V_45 , & V_2 , 0 , 0 ,
V_110 , V_37 , V_14 ) ;
break;
}
default:
F_38 ( 1 ) ;
}
if ( V_25 )
return V_25 ;
V_119 += F_83 ( type ) ;
}
return 0 ;
}
static int F_84 ( struct V_57 * V_58 ,
struct V_46 * V_47 , T_1 V_110 ,
int V_116 , struct V_32 * V_91 )
{
struct V_44 * V_137 = V_58 -> V_137 ;
int V_25 ;
int V_22 ;
struct V_3 * V_117 ;
struct V_1 V_2 ;
while ( 1 ) {
V_25 = F_85 ( V_137 , V_47 ) ;
if ( V_25 < 0 )
break;
if ( V_25 ) {
V_25 = 0 ;
break;
}
V_22 = V_47 -> V_55 [ 0 ] ;
V_117 = V_47 -> V_53 [ 0 ] ;
F_12 ( V_117 , & V_2 , V_22 ) ;
if ( V_2 . V_18 != V_110 )
break;
if ( V_2 . type < V_108 )
continue;
if ( V_2 . type > V_115 )
break;
switch ( V_2 . type ) {
case V_112 :
V_25 = F_20 ( V_91 , 0 , NULL ,
V_116 + 1 , V_2 . V_10 ,
V_110 , 1 , V_14 ) ;
break;
case V_115 : {
struct V_133 * V_134 ;
int V_37 ;
V_134 = F_13 ( V_117 , V_22 ,
struct V_133 ) ;
V_37 = F_78 ( V_117 , V_134 ) ;
V_25 = F_20 ( V_91 , 0 , NULL , 0 , V_2 . V_10 ,
V_110 , V_37 , V_14 ) ;
break;
}
case V_108 :
V_25 = F_20 ( V_91 , V_2 . V_10 , NULL ,
V_116 + 1 , 0 ,
V_110 , 1 , V_14 ) ;
break;
case V_113 : {
struct V_135 * V_136 ;
int V_37 ;
T_1 V_45 ;
V_136 = F_13 ( V_117 , V_22 ,
struct V_135 ) ;
V_37 = F_79 ( V_117 , V_136 ) ;
V_2 . V_18 = F_80 ( V_117 ,
V_136 ) ;
V_2 . type = V_26 ;
V_2 . V_10 = F_81 ( V_117 , V_136 ) ;
V_45 = F_82 ( V_117 , V_136 ) ;
V_25 = F_20 ( V_91 , V_45 , & V_2 , 0 , 0 ,
V_110 , V_37 , V_14 ) ;
break;
}
default:
F_38 ( 1 ) ;
}
if ( V_25 )
return V_25 ;
}
return V_25 ;
}
static int F_86 ( struct V_138 * V_139 ,
struct V_57 * V_58 , T_1 V_110 ,
T_1 V_50 , struct V_48 * V_140 ,
struct V_48 * V_141 , const T_1 * V_7 )
{
struct V_1 V_2 ;
struct V_46 * V_47 ;
struct V_142 * V_143 = NULL ;
struct V_89 * V_33 ;
int V_116 = 0 ;
int V_25 ;
struct V_32 V_144 ;
struct V_32 V_91 ;
struct V_29 * V_39 ;
struct V_8 * V_9 = NULL ;
T_1 V_51 = 0 ;
F_87 ( & V_91 ) ;
F_87 ( & V_144 ) ;
V_2 . V_18 = V_110 ;
V_2 . V_10 = ( T_1 ) - 1 ;
if ( F_88 ( V_58 , V_145 ) )
V_2 . type = V_129 ;
else
V_2 . type = V_125 ;
V_47 = F_89 () ;
if ( ! V_47 )
return - V_15 ;
if ( ! V_139 ) {
V_47 -> V_65 = 1 ;
V_47 -> V_146 = 1 ;
}
V_147:
V_33 = NULL ;
V_25 = F_90 ( V_139 , V_58 -> V_137 , & V_2 , V_47 , 0 , 0 ) ;
if ( V_25 < 0 )
goto V_64;
F_52 ( V_25 == 0 ) ;
if ( V_139 ) {
V_143 = & V_139 -> V_148 -> V_143 ;
F_64 ( & V_143 -> V_99 ) ;
V_33 = F_91 ( V_139 , V_110 ) ;
if ( V_33 ) {
if ( ! F_92 ( & V_33 -> V_149 ) ) {
F_93 ( & V_33 -> V_72 . V_140 ) ;
F_70 ( & V_143 -> V_99 ) ;
F_39 ( V_47 ) ;
F_94 ( & V_33 -> V_149 ) ;
F_95 ( & V_33 -> V_149 ) ;
F_96 ( & V_33 -> V_72 ) ;
goto V_147;
}
F_70 ( & V_143 -> V_99 ) ;
V_25 = F_62 ( V_33 , V_50 ,
& V_144 , & V_51 ) ;
F_95 ( & V_33 -> V_149 ) ;
if ( V_25 )
goto V_64;
} else {
F_70 ( & V_143 -> V_99 ) ;
}
}
if ( V_47 -> V_55 [ 0 ] ) {
struct V_3 * V_117 ;
int V_22 ;
V_47 -> V_55 [ 0 ] -- ;
V_117 = V_47 -> V_53 [ 0 ] ;
V_22 = V_47 -> V_55 [ 0 ] ;
F_12 ( V_117 , & V_2 , V_22 ) ;
if ( V_2 . V_18 == V_110 &&
( V_2 . type == V_125 ||
V_2 . type == V_129 ) ) {
V_25 = F_71 ( V_58 , V_47 , V_110 ,
& V_116 , & V_91 ,
& V_51 ) ;
if ( V_25 )
goto V_64;
V_25 = F_84 ( V_58 , V_47 , V_110 ,
V_116 , & V_91 ) ;
if ( V_25 )
goto V_64;
}
}
F_39 ( V_47 ) ;
F_97 ( & V_144 , & V_91 ) ;
V_25 = F_49 ( V_58 , & V_91 ) ;
if ( V_25 )
goto V_64;
F_59 ( & V_91 , 1 ) ;
V_25 = F_40 ( V_58 , V_47 , V_50 , & V_91 ,
V_7 , V_51 ) ;
if ( V_25 )
goto V_64;
F_59 ( & V_91 , 2 ) ;
while ( ! F_98 ( & V_91 ) ) {
V_39 = F_99 ( & V_91 , struct V_29 , V_43 ) ;
F_38 ( V_39 -> V_37 < 0 ) ;
if ( V_141 && V_39 -> V_37 && V_39 -> V_34 && V_39 -> V_36 == 0 ) {
V_25 = F_24 ( V_141 , V_39 -> V_34 , 0 , V_14 ) ;
if ( V_25 < 0 )
goto V_64;
}
if ( V_39 -> V_37 && V_39 -> V_36 ) {
if ( V_7 && ! V_39 -> V_42 ) {
T_4 V_150 ;
struct V_3 * V_4 ;
V_150 = F_100 ( V_58 -> V_137 ,
V_116 ) ;
V_4 = F_53 ( V_58 -> V_137 ,
V_39 -> V_36 , V_150 , 0 ) ;
if ( ! V_4 || ! F_54 ( V_4 ) ) {
F_55 ( V_4 ) ;
V_25 = - V_83 ;
goto V_64;
}
V_25 = F_10 ( V_4 , V_110 ,
* V_7 , & V_9 ) ;
F_55 ( V_4 ) ;
if ( V_25 < 0 )
goto V_64;
V_39 -> V_42 = V_9 ;
}
V_25 = F_26 ( V_140 , V_39 -> V_36 ,
( V_56 ) V_39 -> V_42 ,
( T_1 * ) & V_9 , V_14 ) ;
if ( V_25 < 0 )
goto V_64;
if ( ! V_25 && V_7 ) {
F_52 ( ! V_9 ) ;
while ( V_9 -> V_16 )
V_9 = V_9 -> V_16 ;
V_9 -> V_16 = V_39 -> V_42 ;
}
V_9 = NULL ;
}
F_60 ( & V_39 -> V_43 ) ;
F_61 ( V_28 , V_39 ) ;
}
V_64:
F_101 ( V_47 ) ;
while ( ! F_98 ( & V_91 ) ) {
V_39 = F_99 ( & V_91 , struct V_29 , V_43 ) ;
F_60 ( & V_39 -> V_43 ) ;
F_61 ( V_28 , V_39 ) ;
}
while ( ! F_98 ( & V_144 ) ) {
V_39 = F_99 ( & V_144 , struct V_29 ,
V_43 ) ;
F_60 ( & V_39 -> V_43 ) ;
F_61 ( V_28 , V_39 ) ;
}
if ( V_25 < 0 )
F_8 ( V_9 ) ;
return V_25 ;
}
static void F_102 ( struct V_48 * V_151 )
{
struct V_71 * V_72 = NULL ;
struct V_8 * V_9 ;
struct V_73 V_74 ;
F_43 ( & V_74 ) ;
while ( ( V_72 = F_44 ( V_151 , & V_74 ) ) ) {
if ( ! V_72 -> V_77 )
continue;
V_9 = (struct V_8 * ) ( V_56 ) V_72 -> V_77 ;
F_8 ( V_9 ) ;
V_72 -> V_77 = 0 ;
}
F_47 ( V_151 ) ;
}
static int F_103 ( struct V_138 * V_139 ,
struct V_57 * V_58 , T_1 V_110 ,
T_1 V_50 , struct V_48 * * V_152 ,
const T_1 * V_7 )
{
int V_25 ;
* V_152 = F_41 ( V_14 ) ;
if ( ! * V_152 )
return - V_15 ;
V_25 = F_86 ( V_139 , V_58 , V_110 ,
V_50 , * V_152 , NULL , V_7 ) ;
if ( V_25 < 0 && V_25 != - V_75 ) {
F_102 ( * V_152 ) ;
return V_25 ;
}
return 0 ;
}
static int F_104 ( struct V_138 * V_139 ,
struct V_57 * V_58 , T_1 V_110 ,
T_1 V_50 , struct V_48 * * V_141 )
{
struct V_48 * V_153 ;
struct V_71 * V_72 = NULL ;
struct V_73 V_74 ;
int V_25 ;
V_153 = F_41 ( V_14 ) ;
if ( ! V_153 )
return - V_15 ;
* V_141 = F_41 ( V_14 ) ;
if ( ! * V_141 ) {
F_47 ( V_153 ) ;
return - V_15 ;
}
F_43 ( & V_74 ) ;
while ( 1 ) {
V_25 = F_86 ( V_139 , V_58 , V_110 ,
V_50 , V_153 , * V_141 , NULL ) ;
if ( V_25 < 0 && V_25 != - V_75 ) {
F_47 ( V_153 ) ;
F_47 ( * V_141 ) ;
return V_25 ;
}
V_72 = F_44 ( V_153 , & V_74 ) ;
if ( ! V_72 )
break;
V_110 = V_72 -> V_76 ;
F_105 () ;
}
F_47 ( V_153 ) ;
return 0 ;
}
int F_106 ( struct V_138 * V_139 ,
struct V_57 * V_58 , T_1 V_110 ,
T_1 V_50 , struct V_48 * * V_141 )
{
int V_25 ;
if ( ! V_139 )
F_107 ( & V_58 -> V_154 ) ;
V_25 = F_104 ( V_139 , V_58 , V_110 , V_50 , V_141 ) ;
if ( ! V_139 )
F_108 ( & V_58 -> V_154 ) ;
return V_25 ;
}
int F_109 ( T_1 V_17 , T_1 V_155 , struct V_44 * V_156 ,
struct V_46 * V_47 )
{
struct V_1 V_2 ;
return F_110 ( V_156 , V_47 , V_17 , V_155 ,
V_157 , & V_2 ) ;
}
static int F_111 ( T_1 V_17 , T_1 V_155 , struct V_44 * V_156 ,
struct V_46 * V_47 ,
struct V_1 * V_118 )
{
return F_110 ( V_156 , V_47 , V_17 , V_155 ,
V_158 , V_118 ) ;
}
int F_112 ( struct V_44 * V_45 , T_1 V_159 ,
T_1 V_160 , struct V_46 * V_47 ,
struct V_161 * * V_162 ,
T_1 * V_163 )
{
int V_25 , V_22 ;
struct V_1 V_2 ;
struct V_1 V_118 ;
struct V_161 * V_164 ;
struct V_3 * V_117 ;
unsigned long V_119 ;
V_2 . V_18 = V_159 ;
F_113 ( & V_2 , V_165 ) ;
V_2 . V_10 = V_160 ;
V_25 = F_90 ( NULL , V_45 , & V_2 , V_47 , 0 , 0 ) ;
if ( V_25 < 0 )
return V_25 ;
while ( 1 ) {
V_117 = V_47 -> V_53 [ 0 ] ;
V_22 = V_47 -> V_55 [ 0 ] ;
if ( V_22 >= F_11 ( V_117 ) ) {
V_25 = F_114 ( V_45 , V_47 ) ;
if ( V_25 ) {
if ( V_25 >= 1 )
V_25 = - V_75 ;
break;
}
continue;
}
F_12 ( V_117 , & V_118 , V_22 ) ;
V_25 = - V_75 ;
if ( V_118 . V_18 != V_159 )
break;
if ( F_115 ( & V_118 ) != V_165 )
break;
V_25 = 0 ;
V_119 = F_116 ( V_117 , V_47 -> V_55 [ 0 ] ) ;
V_164 = (struct V_161 * ) V_119 ;
* V_162 = V_164 ;
if ( V_163 )
* V_163 = V_118 . V_10 ;
break;
}
return V_25 ;
}
char * F_117 ( struct V_44 * V_156 , struct V_46 * V_47 ,
T_4 V_166 , unsigned long V_167 ,
struct V_3 * V_168 , T_1 V_36 ,
char * V_169 , T_4 V_170 )
{
int V_22 ;
T_1 V_171 ;
int V_25 ;
T_5 V_172 = ( ( T_5 ) V_170 ) - 1 ;
struct V_3 * V_4 = V_168 ;
struct V_1 V_118 ;
int V_173 = V_47 -> V_173 ;
struct V_174 * V_132 ;
if ( V_172 >= 0 )
V_169 [ V_172 ] = '\0' ;
V_47 -> V_173 = 1 ;
while ( 1 ) {
V_172 -= V_166 ;
if ( V_172 >= 0 )
F_118 ( V_4 , V_169 + V_172 ,
V_167 , V_166 ) ;
if ( V_4 != V_168 ) {
F_119 ( V_4 ) ;
F_55 ( V_4 ) ;
}
V_25 = F_111 ( V_36 , 0 , V_156 , V_47 , & V_118 ) ;
if ( V_25 > 0 )
V_25 = - V_75 ;
if ( V_25 )
break;
V_171 = V_118 . V_10 ;
if ( V_36 == V_171 )
break;
V_22 = V_47 -> V_55 [ 0 ] ;
V_4 = V_47 -> V_53 [ 0 ] ;
if ( V_4 != V_168 ) {
F_93 ( & V_4 -> V_140 ) ;
F_56 ( V_4 ) ;
F_120 ( V_4 , V_175 ) ;
}
F_39 ( V_47 ) ;
V_132 = F_13 ( V_4 , V_22 , struct V_174 ) ;
V_166 = F_121 ( V_4 , V_132 ) ;
V_167 = ( unsigned long ) ( V_132 + 1 ) ;
V_36 = V_171 ;
-- V_172 ;
if ( V_172 >= 0 )
V_169 [ V_172 ] = '/' ;
}
F_39 ( V_47 ) ;
V_47 -> V_173 = V_173 ;
if ( V_25 )
return F_122 ( V_25 ) ;
return V_169 + V_172 ;
}
int F_123 ( struct V_57 * V_58 , T_1 V_176 ,
struct V_46 * V_47 , struct V_1 * V_118 ,
T_1 * V_177 )
{
int V_25 ;
T_1 V_123 ;
T_1 V_170 = 0 ;
T_4 V_124 ;
struct V_3 * V_4 ;
struct V_121 * V_122 ;
struct V_1 V_2 ;
if ( F_88 ( V_58 , V_145 ) )
V_2 . type = V_129 ;
else
V_2 . type = V_125 ;
V_2 . V_18 = V_176 ;
V_2 . V_10 = ( T_1 ) - 1 ;
V_25 = F_90 ( NULL , V_58 -> V_137 , & V_2 , V_47 , 0 , 0 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_124 ( V_58 -> V_137 , V_47 , 0 ) ;
if ( V_25 ) {
if ( V_25 > 0 )
V_25 = - V_75 ;
return V_25 ;
}
F_12 ( V_47 -> V_53 [ 0 ] , V_118 , V_47 -> V_55 [ 0 ] ) ;
if ( V_118 -> type == V_129 )
V_170 = V_58 -> V_137 -> V_82 ;
else if ( V_118 -> type == V_125 )
V_170 = V_118 -> V_10 ;
if ( V_118 -> V_18 > V_176 ||
V_118 -> V_18 + V_170 <= V_176 ) {
F_37 ( L_4 , V_176 ) ;
return - V_75 ;
}
V_4 = V_47 -> V_53 [ 0 ] ;
V_124 = F_72 ( V_4 , V_47 -> V_55 [ 0 ] ) ;
F_52 ( V_124 < sizeof( * V_122 ) ) ;
V_122 = F_13 ( V_4 , V_47 -> V_55 [ 0 ] , struct V_121 ) ;
V_123 = F_73 ( V_4 , V_122 ) ;
F_37 ( L_5
L_6 ,
V_176 , V_176 - V_118 -> V_18 , V_118 -> V_18 ,
V_118 -> V_10 , V_123 , V_124 ) ;
F_38 ( ! V_177 ) ;
if ( V_177 ) {
if ( V_123 & V_126 )
* V_177 = V_126 ;
else if ( V_123 & V_130 )
* V_177 = V_130 ;
else
F_52 ( 1 ) ;
return 0 ;
}
return - V_83 ;
}
static int F_125 ( unsigned long * V_119 , struct V_3 * V_4 ,
struct V_121 * V_122 , T_4 V_124 ,
struct V_131 * * V_178 ,
int * V_179 )
{
unsigned long V_120 ;
T_1 V_123 ;
struct V_127 * V_128 ;
if ( ! * V_119 ) {
V_123 = F_73 ( V_4 , V_122 ) ;
if ( V_123 & V_126 ) {
V_128 = (struct V_127 * ) ( V_122 + 1 ) ;
* V_178 =
(struct V_131 * ) ( V_128 + 1 ) ;
} else {
* V_178 = (struct V_131 * ) ( V_122 + 1 ) ;
}
* V_119 = ( unsigned long ) * V_178 ;
if ( ( void * ) * V_119 >= ( void * ) V_122 + V_124 )
return - V_75 ;
}
V_120 = ( unsigned long ) V_122 + V_124 ;
* V_178 = (struct V_131 * ) * V_119 ;
* V_179 = F_76 ( V_4 , * V_178 ) ;
* V_119 += F_83 ( * V_179 ) ;
F_38 ( * V_119 > V_120 ) ;
if ( * V_119 == V_120 )
return 1 ;
return 0 ;
}
int F_126 ( unsigned long * V_119 , struct V_3 * V_4 ,
struct V_121 * V_122 , T_4 V_124 ,
T_1 * V_180 , T_6 * V_181 )
{
int V_25 ;
int type ;
struct V_127 * V_128 ;
struct V_131 * V_182 ;
if ( * V_119 == ( unsigned long ) - 1 )
return 1 ;
while ( 1 ) {
V_25 = F_125 ( V_119 , V_4 , V_122 , V_124 ,
& V_182 , & type ) ;
if ( V_25 < 0 )
return V_25 ;
if ( type == V_108 ||
type == V_112 )
break;
if ( V_25 == 1 )
return 1 ;
}
V_128 = (struct V_127 * ) ( V_122 + 1 ) ;
* V_180 = F_77 ( V_4 , V_182 ) ;
* V_181 = F_75 ( V_4 , V_128 ) ;
if ( V_25 == 1 )
* V_119 = ( unsigned long ) - 1 ;
return 0 ;
}
static int F_127 ( struct V_8 * V_42 ,
T_1 V_45 , T_1 V_183 ,
T_7 * V_184 , void * V_185 )
{
struct V_8 * V_9 ;
int V_25 = 0 ;
for ( V_9 = V_42 ; V_9 ; V_9 = V_9 -> V_16 ) {
F_37 ( L_7
L_8 , V_183 ,
V_9 -> V_17 , V_9 -> V_10 , V_45 ) ;
V_25 = V_184 ( V_9 -> V_17 , V_9 -> V_10 , V_45 , V_185 ) ;
if ( V_25 ) {
F_37 ( L_9 ,
V_183 , V_25 ) ;
break;
}
}
return V_25 ;
}
int F_128 ( struct V_57 * V_58 ,
T_1 V_183 , T_1 V_7 ,
int V_65 ,
T_7 * V_184 , void * V_185 )
{
int V_25 ;
struct V_138 * V_139 = NULL ;
struct V_48 * V_140 = NULL ;
struct V_48 * V_141 = NULL ;
struct V_71 * V_186 = NULL ;
struct V_71 * V_187 = NULL ;
struct V_188 V_189 = {} ;
struct V_73 V_190 ;
struct V_73 V_191 ;
F_37 ( L_10 ,
V_183 ) ;
if ( ! V_65 ) {
V_139 = F_129 ( V_58 -> V_137 ) ;
if ( F_31 ( V_139 ) )
return F_33 ( V_139 ) ;
F_130 ( V_58 , & V_189 ) ;
} else {
F_107 ( & V_58 -> V_154 ) ;
}
V_25 = F_103 ( V_139 , V_58 , V_183 ,
V_189 . V_90 , & V_140 ,
& V_7 ) ;
if ( V_25 )
goto V_64;
F_43 ( & V_190 ) ;
while ( ! V_25 && ( V_186 = F_44 ( V_140 , & V_190 ) ) ) {
V_25 = F_104 ( V_139 , V_58 , V_186 -> V_76 ,
V_189 . V_90 , & V_141 ) ;
if ( V_25 )
break;
F_43 ( & V_191 ) ;
while ( ! V_25 && ( V_187 = F_44 ( V_141 , & V_191 ) ) ) {
F_37 ( L_11
L_12 , V_187 -> V_76 , V_186 -> V_76 ,
V_186 -> V_77 ) ;
V_25 = F_127 ( (struct V_8 * )
( V_56 ) V_186 -> V_77 ,
V_187 -> V_76 ,
V_183 ,
V_184 , V_185 ) ;
}
F_47 ( V_141 ) ;
}
F_102 ( V_140 ) ;
V_64:
if ( ! V_65 ) {
F_131 ( V_58 , & V_189 ) ;
F_132 ( V_139 , V_58 -> V_137 ) ;
} else {
F_108 ( & V_58 -> V_154 ) ;
}
return V_25 ;
}
int F_133 ( T_1 V_176 , struct V_57 * V_58 ,
struct V_46 * V_47 ,
T_7 * V_184 , void * V_185 )
{
int V_25 ;
T_1 V_7 ;
T_1 V_123 = 0 ;
struct V_1 V_118 ;
int V_65 = V_47 -> V_65 ;
V_25 = F_123 ( V_58 , V_176 , V_47 , & V_118 , & V_123 ) ;
F_39 ( V_47 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_123 & V_126 )
return - V_192 ;
V_7 = V_176 - V_118 . V_18 ;
V_25 = F_128 ( V_58 , V_118 . V_18 ,
V_7 , V_65 ,
V_184 , V_185 ) ;
return V_25 ;
}
static int F_134 ( T_1 V_17 , struct V_44 * V_156 ,
struct V_46 * V_47 ,
T_8 * V_184 , void * V_185 )
{
int V_25 = 0 ;
int V_22 ;
T_4 V_193 ;
T_4 V_194 ;
T_4 V_166 ;
T_1 V_36 = 0 ;
int V_195 = 0 ;
struct V_3 * V_4 ;
struct V_196 * V_197 ;
struct V_174 * V_132 ;
struct V_1 V_118 ;
while ( ! V_25 ) {
V_25 = F_111 ( V_17 , V_36 ? V_36 + 1 : 0 , V_156 , V_47 ,
& V_118 ) ;
if ( V_25 < 0 )
break;
if ( V_25 ) {
V_25 = V_195 ? 0 : - V_75 ;
break;
}
++ V_195 ;
V_36 = V_118 . V_10 ;
V_22 = V_47 -> V_55 [ 0 ] ;
V_4 = F_135 ( V_47 -> V_53 [ 0 ] ) ;
if ( ! V_4 ) {
V_25 = - V_15 ;
break;
}
F_136 ( V_4 ) ;
F_56 ( V_4 ) ;
F_120 ( V_4 , V_175 ) ;
F_39 ( V_47 ) ;
V_197 = F_137 ( V_22 ) ;
V_132 = F_13 ( V_4 , V_22 , struct V_174 ) ;
for ( V_193 = 0 ; V_193 < F_138 ( V_4 , V_197 ) ; V_193 += V_194 ) {
V_166 = F_121 ( V_4 , V_132 ) ;
F_37 ( L_13
L_14 , V_193 , V_118 . V_18 ,
V_156 -> V_18 ) ;
V_25 = V_184 ( V_36 , V_166 ,
( unsigned long ) ( V_132 + 1 ) , V_4 , V_185 ) ;
if ( V_25 )
break;
V_194 = sizeof( * V_132 ) + V_166 ;
V_132 = (struct V_174 * ) ( ( char * ) V_132 + V_194 ) ;
}
F_119 ( V_4 ) ;
F_55 ( V_4 ) ;
}
F_39 ( V_47 ) ;
return V_25 ;
}
static int F_139 ( T_1 V_17 , struct V_44 * V_156 ,
struct V_46 * V_47 ,
T_8 * V_184 , void * V_185 )
{
int V_25 ;
int V_22 ;
T_1 V_10 = 0 ;
T_1 V_36 ;
int V_195 = 0 ;
struct V_3 * V_4 ;
struct V_161 * V_164 ;
struct V_3 * V_117 ;
T_4 V_124 ;
T_4 V_198 ;
unsigned long V_119 ;
while ( 1 ) {
V_25 = F_112 ( V_156 , V_17 , V_10 , V_47 , & V_164 ,
& V_10 ) ;
if ( V_25 < 0 )
break;
if ( V_25 ) {
V_25 = V_195 ? 0 : - V_75 ;
break;
}
++ V_195 ;
V_22 = V_47 -> V_55 [ 0 ] ;
V_4 = F_135 ( V_47 -> V_53 [ 0 ] ) ;
if ( ! V_4 ) {
V_25 = - V_15 ;
break;
}
F_136 ( V_4 ) ;
F_56 ( V_4 ) ;
F_120 ( V_4 , V_175 ) ;
F_39 ( V_47 ) ;
V_117 = V_47 -> V_53 [ 0 ] ;
V_124 = F_72 ( V_117 , V_22 ) ;
V_119 = F_116 ( V_117 , V_22 ) ;
V_198 = 0 ;
while ( V_198 < V_124 ) {
T_4 V_166 ;
V_164 = (struct V_161 * ) ( V_119 + V_198 ) ;
V_36 = F_140 ( V_4 , V_164 ) ;
V_166 = F_141 ( V_4 , V_164 ) ;
V_25 = V_184 ( V_36 , V_166 ,
( unsigned long ) & V_164 -> V_199 , V_4 , V_185 ) ;
if ( V_25 )
break;
V_198 += F_141 ( V_117 , V_164 ) ;
V_198 += sizeof( * V_164 ) ;
}
F_119 ( V_4 ) ;
F_55 ( V_4 ) ;
V_10 ++ ;
}
F_39 ( V_47 ) ;
return V_25 ;
}
static int F_142 ( T_1 V_17 , struct V_44 * V_156 ,
struct V_46 * V_47 , T_8 * V_184 ,
void * V_185 )
{
int V_25 ;
int V_200 = 0 ;
V_25 = F_134 ( V_17 , V_156 , V_47 , V_184 , V_185 ) ;
if ( ! V_25 )
++ V_200 ;
else if ( V_25 != - V_75 )
return V_25 ;
V_25 = F_139 ( V_17 , V_156 , V_47 , V_184 , V_185 ) ;
if ( V_25 == - V_75 && V_200 )
return 0 ;
return V_25 ;
}
static int F_143 ( T_1 V_17 , T_4 V_166 , unsigned long V_167 ,
struct V_3 * V_4 , void * V_185 )
{
struct V_201 * V_202 = V_185 ;
char * V_203 ;
char * V_204 ;
int V_205 = V_202 -> V_203 -> V_206 ;
const int V_207 = sizeof( char * ) ;
T_4 V_172 ;
V_172 = V_202 -> V_203 -> V_172 > V_207 ?
V_202 -> V_203 -> V_172 - V_207 : 0 ;
V_204 = ( char * ) V_202 -> V_203 -> V_76 + ( V_205 + 1 ) * V_207 ;
V_203 = F_117 ( V_202 -> V_156 , V_202 -> V_46 , V_166 ,
V_167 , V_4 , V_17 , V_204 , V_172 ) ;
if ( F_31 ( V_203 ) )
return F_33 ( V_203 ) ;
if ( V_203 > V_204 ) {
V_202 -> V_203 -> V_76 [ V_205 ] = ( T_1 ) ( unsigned long ) V_203 ;
++ V_202 -> V_203 -> V_206 ;
V_202 -> V_203 -> V_172 = V_203 - V_204 ;
} else {
++ V_202 -> V_203 -> V_208 ;
V_202 -> V_203 -> V_209 += V_204 - V_203 ;
V_202 -> V_203 -> V_172 = 0 ;
}
return 0 ;
}
int F_144 ( T_1 V_17 , struct V_201 * V_202 )
{
return F_142 ( V_17 , V_202 -> V_156 , V_202 -> V_46 ,
F_143 , V_202 ) ;
}
struct V_210 * F_145 ( T_4 V_211 )
{
struct V_210 * V_212 ;
T_9 V_213 ;
V_213 = F_146 ( T_9 , V_211 , sizeof( * V_212 ) ) ;
V_212 = F_147 ( V_213 ) ;
if ( ! V_212 )
return F_122 ( - V_15 ) ;
if ( V_211 >= sizeof( * V_212 ) ) {
V_212 -> V_172 = V_211 - sizeof( * V_212 ) ;
V_212 -> V_209 = 0 ;
} else {
V_212 -> V_209 = sizeof( * V_212 ) - V_211 ;
V_212 -> V_172 = 0 ;
}
V_212 -> V_206 = 0 ;
V_212 -> V_208 = 0 ;
return V_212 ;
}
struct V_201 * F_148 ( T_10 V_211 , struct V_44 * V_156 ,
struct V_46 * V_47 )
{
struct V_201 * V_214 ;
struct V_210 * V_203 ;
V_203 = F_145 ( V_211 ) ;
if ( F_31 ( V_203 ) )
return ( void * ) V_203 ;
V_214 = F_7 ( sizeof( * V_214 ) , V_14 ) ;
if ( ! V_214 ) {
F_9 ( V_203 ) ;
return F_122 ( - V_15 ) ;
}
V_214 -> V_46 = V_47 ;
V_214 -> V_203 = V_203 ;
V_214 -> V_156 = V_156 ;
return V_214 ;
}
void F_149 ( struct V_201 * V_202 )
{
if ( ! V_202 )
return;
F_150 ( V_202 -> V_203 ) ;
F_9 ( V_202 ) ;
}
