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
static void F_86 ( struct V_48 * V_138 )
{
struct V_71 * V_72 = NULL ;
struct V_8 * V_9 ;
struct V_73 V_74 ;
F_43 ( & V_74 ) ;
while ( ( V_72 = F_44 ( V_138 , & V_74 ) ) ) {
if ( ! V_72 -> V_77 )
continue;
V_9 = (struct V_8 * ) ( V_56 ) V_72 -> V_77 ;
F_8 ( V_9 ) ;
V_72 -> V_77 = 0 ;
}
F_47 ( V_138 ) ;
}
static int F_87 ( struct V_139 * V_140 ,
struct V_57 * V_58 , T_1 V_110 ,
T_1 V_50 , struct V_48 * * V_141 ,
const T_1 * V_7 )
{
int V_25 ;
* V_141 = F_41 ( V_14 ) ;
if ( ! * V_141 )
return - V_15 ;
V_25 = F_88 ( V_140 , V_58 , V_110 ,
V_50 , * V_141 , NULL , V_7 ) ;
if ( V_25 < 0 && V_25 != - V_75 ) {
F_86 ( * V_141 ) ;
return V_25 ;
}
return 0 ;
}
static int F_89 ( struct V_139 * V_140 ,
struct V_57 * V_58 , T_1 V_110 ,
T_1 V_50 , struct V_48 * * V_142 )
{
struct V_48 * V_143 ;
struct V_71 * V_72 = NULL ;
struct V_73 V_74 ;
int V_25 ;
V_143 = F_41 ( V_14 ) ;
if ( ! V_143 )
return - V_15 ;
* V_142 = F_41 ( V_14 ) ;
if ( ! * V_142 ) {
F_47 ( V_143 ) ;
return - V_15 ;
}
F_43 ( & V_74 ) ;
while ( 1 ) {
V_25 = F_88 ( V_140 , V_58 , V_110 ,
V_50 , V_143 , * V_142 , NULL ) ;
if ( V_25 < 0 && V_25 != - V_75 ) {
F_47 ( V_143 ) ;
F_47 ( * V_142 ) ;
return V_25 ;
}
V_72 = F_44 ( V_143 , & V_74 ) ;
if ( ! V_72 )
break;
V_110 = V_72 -> V_76 ;
F_90 () ;
}
F_47 ( V_143 ) ;
return 0 ;
}
int F_91 ( struct V_139 * V_140 ,
struct V_57 * V_58 , T_1 V_110 ,
T_1 V_50 , struct V_48 * * V_142 )
{
int V_25 ;
if ( ! V_140 )
F_92 ( & V_58 -> V_144 ) ;
V_25 = F_89 ( V_140 , V_58 , V_110 , V_50 , V_142 ) ;
if ( ! V_140 )
F_93 ( & V_58 -> V_144 ) ;
return V_25 ;
}
int F_94 ( T_1 V_17 , T_1 V_145 , struct V_44 * V_146 ,
struct V_46 * V_47 )
{
struct V_1 V_2 ;
return F_95 ( V_146 , V_47 , V_17 , V_145 ,
V_147 , & V_2 ) ;
}
static int F_96 ( T_1 V_17 , T_1 V_145 , struct V_44 * V_146 ,
struct V_46 * V_47 ,
struct V_1 * V_118 )
{
return F_95 ( V_146 , V_47 , V_17 , V_145 ,
V_148 , V_118 ) ;
}
int F_97 ( struct V_44 * V_45 , T_1 V_149 ,
T_1 V_150 , struct V_46 * V_47 ,
struct V_151 * * V_152 ,
T_1 * V_153 )
{
int V_25 , V_22 ;
struct V_1 V_2 ;
struct V_1 V_118 ;
struct V_151 * V_154 ;
struct V_3 * V_117 ;
unsigned long V_119 ;
V_2 . V_18 = V_149 ;
F_98 ( & V_2 , V_155 ) ;
V_2 . V_10 = V_150 ;
V_25 = F_99 ( NULL , V_45 , & V_2 , V_47 , 0 , 0 ) ;
if ( V_25 < 0 )
return V_25 ;
while ( 1 ) {
V_117 = V_47 -> V_53 [ 0 ] ;
V_22 = V_47 -> V_55 [ 0 ] ;
if ( V_22 >= F_11 ( V_117 ) ) {
V_25 = F_100 ( V_45 , V_47 ) ;
if ( V_25 ) {
if ( V_25 >= 1 )
V_25 = - V_75 ;
break;
}
continue;
}
F_12 ( V_117 , & V_118 , V_22 ) ;
V_25 = - V_75 ;
if ( V_118 . V_18 != V_149 )
break;
if ( F_101 ( & V_118 ) != V_155 )
break;
V_25 = 0 ;
V_119 = F_102 ( V_117 , V_47 -> V_55 [ 0 ] ) ;
V_154 = (struct V_151 * ) V_119 ;
* V_152 = V_154 ;
if ( V_153 )
* V_153 = V_118 . V_10 ;
break;
}
return V_25 ;
}
char * F_103 ( struct V_44 * V_146 , struct V_46 * V_47 ,
T_4 V_156 , unsigned long V_157 ,
struct V_3 * V_158 , T_1 V_36 ,
char * V_159 , T_4 V_160 )
{
int V_22 ;
T_1 V_161 ;
int V_25 ;
T_5 V_162 = ( ( T_5 ) V_160 ) - 1 ;
struct V_3 * V_4 = V_158 ;
struct V_1 V_118 ;
int V_163 = V_47 -> V_163 ;
struct V_164 * V_132 ;
if ( V_162 >= 0 )
V_159 [ V_162 ] = '\0' ;
V_47 -> V_163 = 1 ;
while ( 1 ) {
V_162 -= V_156 ;
if ( V_162 >= 0 )
F_104 ( V_4 , V_159 + V_162 ,
V_157 , V_156 ) ;
if ( V_4 != V_158 ) {
F_105 ( V_4 ) ;
F_55 ( V_4 ) ;
}
V_25 = F_96 ( V_36 , 0 , V_146 , V_47 , & V_118 ) ;
if ( V_25 > 0 )
V_25 = - V_75 ;
if ( V_25 )
break;
V_161 = V_118 . V_10 ;
if ( V_36 == V_161 )
break;
V_22 = V_47 -> V_55 [ 0 ] ;
V_4 = V_47 -> V_53 [ 0 ] ;
if ( V_4 != V_158 ) {
F_106 ( & V_4 -> V_165 ) ;
F_56 ( V_4 ) ;
F_107 ( V_4 , V_166 ) ;
}
F_39 ( V_47 ) ;
V_132 = F_13 ( V_4 , V_22 , struct V_164 ) ;
V_156 = F_108 ( V_4 , V_132 ) ;
V_157 = ( unsigned long ) ( V_132 + 1 ) ;
V_36 = V_161 ;
-- V_162 ;
if ( V_162 >= 0 )
V_159 [ V_162 ] = '/' ;
}
F_39 ( V_47 ) ;
V_47 -> V_163 = V_163 ;
if ( V_25 )
return F_109 ( V_25 ) ;
return V_159 + V_162 ;
}
int F_110 ( struct V_57 * V_58 , T_1 V_167 ,
struct V_46 * V_47 , struct V_1 * V_118 ,
T_1 * V_168 )
{
int V_25 ;
T_1 V_123 ;
T_1 V_160 = 0 ;
T_4 V_124 ;
struct V_3 * V_4 ;
struct V_121 * V_122 ;
struct V_1 V_2 ;
if ( F_111 ( V_58 , V_169 ) )
V_2 . type = V_129 ;
else
V_2 . type = V_125 ;
V_2 . V_18 = V_167 ;
V_2 . V_10 = ( T_1 ) - 1 ;
V_25 = F_99 ( NULL , V_58 -> V_137 , & V_2 , V_47 , 0 , 0 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_112 ( V_58 -> V_137 , V_47 , 0 ) ;
if ( V_25 ) {
if ( V_25 > 0 )
V_25 = - V_75 ;
return V_25 ;
}
F_12 ( V_47 -> V_53 [ 0 ] , V_118 , V_47 -> V_55 [ 0 ] ) ;
if ( V_118 -> type == V_129 )
V_160 = V_58 -> V_137 -> V_82 ;
else if ( V_118 -> type == V_125 )
V_160 = V_118 -> V_10 ;
if ( V_118 -> V_18 > V_167 ||
V_118 -> V_18 + V_160 <= V_167 ) {
F_37 ( L_4 , V_167 ) ;
return - V_75 ;
}
V_4 = V_47 -> V_53 [ 0 ] ;
V_124 = F_72 ( V_4 , V_47 -> V_55 [ 0 ] ) ;
F_52 ( V_124 < sizeof( * V_122 ) ) ;
V_122 = F_13 ( V_4 , V_47 -> V_55 [ 0 ] , struct V_121 ) ;
V_123 = F_73 ( V_4 , V_122 ) ;
F_37 ( L_5
L_6 ,
V_167 , V_167 - V_118 -> V_18 , V_118 -> V_18 ,
V_118 -> V_10 , V_123 , V_124 ) ;
F_38 ( ! V_168 ) ;
if ( V_168 ) {
if ( V_123 & V_126 )
* V_168 = V_126 ;
else if ( V_123 & V_130 )
* V_168 = V_130 ;
else
F_52 ( 1 ) ;
return 0 ;
}
return - V_83 ;
}
static int F_113 ( unsigned long * V_119 , struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_121 * V_122 , T_4 V_124 ,
struct V_131 * * V_170 ,
int * V_171 )
{
unsigned long V_120 ;
T_1 V_123 ;
struct V_127 * V_128 ;
if ( ! * V_119 ) {
V_123 = F_73 ( V_4 , V_122 ) ;
if ( V_123 & V_126 ) {
if ( V_2 -> type == V_129 ) {
* V_170 =
(struct V_131 * ) ( V_122 + 1 ) ;
} else {
F_38 ( V_2 -> type != V_125 ) ;
V_128 = (struct V_127 * ) ( V_122 + 1 ) ;
* V_170 =
(struct V_131 * ) ( V_128 + 1 ) ;
}
} else {
* V_170 = (struct V_131 * ) ( V_122 + 1 ) ;
}
* V_119 = ( unsigned long ) * V_170 ;
if ( ( unsigned long ) ( * V_119 ) >= ( unsigned long ) V_122 + V_124 )
return - V_75 ;
}
V_120 = ( unsigned long ) V_122 + V_124 ;
* V_170 = (struct V_131 * ) ( * V_119 ) ;
* V_171 = F_76 ( V_4 , * V_170 ) ;
* V_119 += F_83 ( * V_171 ) ;
F_38 ( * V_119 > V_120 ) ;
if ( * V_119 == V_120 )
return 1 ;
return 0 ;
}
int F_114 ( unsigned long * V_119 , struct V_3 * V_4 ,
struct V_1 * V_2 , struct V_121 * V_122 ,
T_4 V_124 , T_1 * V_172 , T_6 * V_173 )
{
int V_25 ;
int type ;
struct V_127 * V_128 ;
struct V_131 * V_174 ;
if ( * V_119 == ( unsigned long ) - 1 )
return 1 ;
while ( 1 ) {
V_25 = F_113 ( V_119 , V_4 , V_2 , V_122 , V_124 ,
& V_174 , & type ) ;
if ( V_25 < 0 )
return V_25 ;
if ( type == V_108 ||
type == V_112 )
break;
if ( V_25 == 1 )
return 1 ;
}
V_128 = (struct V_127 * ) ( V_122 + 1 ) ;
* V_172 = F_77 ( V_4 , V_174 ) ;
* V_173 = F_75 ( V_4 , V_128 ) ;
if ( V_25 == 1 )
* V_119 = ( unsigned long ) - 1 ;
return 0 ;
}
static int F_115 ( struct V_8 * V_42 ,
T_1 V_45 , T_1 V_175 ,
T_7 * V_176 , void * V_177 )
{
struct V_8 * V_9 ;
int V_25 = 0 ;
for ( V_9 = V_42 ; V_9 ; V_9 = V_9 -> V_16 ) {
F_37 ( L_7
L_8 , V_175 ,
V_9 -> V_17 , V_9 -> V_10 , V_45 ) ;
V_25 = V_176 ( V_9 -> V_17 , V_9 -> V_10 , V_45 , V_177 ) ;
if ( V_25 ) {
F_37 ( L_9 ,
V_175 , V_25 ) ;
break;
}
}
return V_25 ;
}
int F_116 ( struct V_57 * V_58 ,
T_1 V_175 , T_1 V_7 ,
int V_65 ,
T_7 * V_176 , void * V_177 )
{
int V_25 ;
struct V_139 * V_140 = NULL ;
struct V_48 * V_165 = NULL ;
struct V_48 * V_142 = NULL ;
struct V_71 * V_178 = NULL ;
struct V_71 * V_179 = NULL ;
struct V_180 V_181 = {} ;
struct V_73 V_182 ;
struct V_73 V_183 ;
F_37 ( L_10 ,
V_175 ) ;
if ( ! V_65 ) {
V_140 = F_117 ( V_58 -> V_137 ) ;
if ( F_31 ( V_140 ) )
return F_33 ( V_140 ) ;
F_118 ( V_58 , & V_181 ) ;
} else {
F_92 ( & V_58 -> V_144 ) ;
}
V_25 = F_87 ( V_140 , V_58 , V_175 ,
V_181 . V_90 , & V_165 ,
& V_7 ) ;
if ( V_25 )
goto V_64;
F_43 ( & V_182 ) ;
while ( ! V_25 && ( V_178 = F_44 ( V_165 , & V_182 ) ) ) {
V_25 = F_89 ( V_140 , V_58 , V_178 -> V_76 ,
V_181 . V_90 , & V_142 ) ;
if ( V_25 )
break;
F_43 ( & V_183 ) ;
while ( ! V_25 && ( V_179 = F_44 ( V_142 , & V_183 ) ) ) {
F_37 ( L_11
L_12 , V_179 -> V_76 , V_178 -> V_76 ,
V_178 -> V_77 ) ;
V_25 = F_115 ( (struct V_8 * )
( V_56 ) V_178 -> V_77 ,
V_179 -> V_76 ,
V_175 ,
V_176 , V_177 ) ;
}
F_47 ( V_142 ) ;
}
F_86 ( V_165 ) ;
V_64:
if ( ! V_65 ) {
F_119 ( V_58 , & V_181 ) ;
F_120 ( V_140 , V_58 -> V_137 ) ;
} else {
F_93 ( & V_58 -> V_144 ) ;
}
return V_25 ;
}
int F_121 ( T_1 V_167 , struct V_57 * V_58 ,
struct V_46 * V_47 ,
T_7 * V_176 , void * V_177 )
{
int V_25 ;
T_1 V_7 ;
T_1 V_123 = 0 ;
struct V_1 V_118 ;
int V_65 = V_47 -> V_65 ;
V_25 = F_110 ( V_58 , V_167 , V_47 , & V_118 , & V_123 ) ;
F_39 ( V_47 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_123 & V_126 )
return - V_184 ;
V_7 = V_167 - V_118 . V_18 ;
V_25 = F_116 ( V_58 , V_118 . V_18 ,
V_7 , V_65 ,
V_176 , V_177 ) ;
return V_25 ;
}
static int F_122 ( T_1 V_17 , struct V_44 * V_146 ,
struct V_46 * V_47 ,
T_8 * V_176 , void * V_177 )
{
int V_25 = 0 ;
int V_22 ;
T_4 V_185 ;
T_4 V_186 ;
T_4 V_156 ;
T_1 V_36 = 0 ;
int V_187 = 0 ;
struct V_3 * V_4 ;
struct V_188 * V_189 ;
struct V_164 * V_132 ;
struct V_1 V_118 ;
while ( ! V_25 ) {
V_25 = F_96 ( V_17 , V_36 ? V_36 + 1 : 0 , V_146 , V_47 ,
& V_118 ) ;
if ( V_25 < 0 )
break;
if ( V_25 ) {
V_25 = V_187 ? 0 : - V_75 ;
break;
}
++ V_187 ;
V_36 = V_118 . V_10 ;
V_22 = V_47 -> V_55 [ 0 ] ;
V_4 = F_123 ( V_47 -> V_53 [ 0 ] ) ;
if ( ! V_4 ) {
V_25 = - V_15 ;
break;
}
F_124 ( V_4 ) ;
F_56 ( V_4 ) ;
F_107 ( V_4 , V_166 ) ;
F_39 ( V_47 ) ;
V_189 = F_125 ( V_22 ) ;
V_132 = F_13 ( V_4 , V_22 , struct V_164 ) ;
for ( V_185 = 0 ; V_185 < F_126 ( V_4 , V_189 ) ; V_185 += V_186 ) {
V_156 = F_108 ( V_4 , V_132 ) ;
F_37 ( L_13
L_14 , V_185 , V_118 . V_18 ,
V_146 -> V_18 ) ;
V_25 = V_176 ( V_36 , V_156 ,
( unsigned long ) ( V_132 + 1 ) , V_4 , V_177 ) ;
if ( V_25 )
break;
V_186 = sizeof( * V_132 ) + V_156 ;
V_132 = (struct V_164 * ) ( ( char * ) V_132 + V_186 ) ;
}
F_105 ( V_4 ) ;
F_55 ( V_4 ) ;
}
F_39 ( V_47 ) ;
return V_25 ;
}
static int F_127 ( T_1 V_17 , struct V_44 * V_146 ,
struct V_46 * V_47 ,
T_8 * V_176 , void * V_177 )
{
int V_25 ;
int V_22 ;
T_1 V_10 = 0 ;
T_1 V_36 ;
int V_187 = 0 ;
struct V_3 * V_4 ;
struct V_151 * V_154 ;
struct V_3 * V_117 ;
T_4 V_124 ;
T_4 V_190 ;
unsigned long V_119 ;
while ( 1 ) {
V_25 = F_97 ( V_146 , V_17 , V_10 , V_47 , & V_154 ,
& V_10 ) ;
if ( V_25 < 0 )
break;
if ( V_25 ) {
V_25 = V_187 ? 0 : - V_75 ;
break;
}
++ V_187 ;
V_22 = V_47 -> V_55 [ 0 ] ;
V_4 = F_123 ( V_47 -> V_53 [ 0 ] ) ;
if ( ! V_4 ) {
V_25 = - V_15 ;
break;
}
F_124 ( V_4 ) ;
F_56 ( V_4 ) ;
F_107 ( V_4 , V_166 ) ;
F_39 ( V_47 ) ;
V_117 = V_47 -> V_53 [ 0 ] ;
V_124 = F_72 ( V_117 , V_22 ) ;
V_119 = F_102 ( V_117 , V_22 ) ;
V_190 = 0 ;
while ( V_190 < V_124 ) {
T_4 V_156 ;
V_154 = (struct V_151 * ) ( V_119 + V_190 ) ;
V_36 = F_128 ( V_4 , V_154 ) ;
V_156 = F_129 ( V_4 , V_154 ) ;
V_25 = V_176 ( V_36 , V_156 ,
( unsigned long ) & V_154 -> V_191 , V_4 , V_177 ) ;
if ( V_25 )
break;
V_190 += F_129 ( V_117 , V_154 ) ;
V_190 += sizeof( * V_154 ) ;
}
F_105 ( V_4 ) ;
F_55 ( V_4 ) ;
V_10 ++ ;
}
F_39 ( V_47 ) ;
return V_25 ;
}
static int F_130 ( T_1 V_17 , struct V_44 * V_146 ,
struct V_46 * V_47 , T_8 * V_176 ,
void * V_177 )
{
int V_25 ;
int V_192 = 0 ;
V_25 = F_122 ( V_17 , V_146 , V_47 , V_176 , V_177 ) ;
if ( ! V_25 )
++ V_192 ;
else if ( V_25 != - V_75 )
return V_25 ;
V_25 = F_127 ( V_17 , V_146 , V_47 , V_176 , V_177 ) ;
if ( V_25 == - V_75 && V_192 )
return 0 ;
return V_25 ;
}
static int F_131 ( T_1 V_17 , T_4 V_156 , unsigned long V_157 ,
struct V_3 * V_4 , void * V_177 )
{
struct V_193 * V_194 = V_177 ;
char * V_195 ;
char * V_196 ;
int V_197 = V_194 -> V_195 -> V_198 ;
const int V_199 = sizeof( char * ) ;
T_4 V_162 ;
V_162 = V_194 -> V_195 -> V_162 > V_199 ?
V_194 -> V_195 -> V_162 - V_199 : 0 ;
V_196 = ( char * ) V_194 -> V_195 -> V_76 + ( V_197 + 1 ) * V_199 ;
V_195 = F_103 ( V_194 -> V_146 , V_194 -> V_46 , V_156 ,
V_157 , V_4 , V_17 , V_196 , V_162 ) ;
if ( F_31 ( V_195 ) )
return F_33 ( V_195 ) ;
if ( V_195 > V_196 ) {
V_194 -> V_195 -> V_76 [ V_197 ] = ( T_1 ) ( unsigned long ) V_195 ;
++ V_194 -> V_195 -> V_198 ;
V_194 -> V_195 -> V_162 = V_195 - V_196 ;
} else {
++ V_194 -> V_195 -> V_200 ;
V_194 -> V_195 -> V_201 += V_196 - V_195 ;
V_194 -> V_195 -> V_162 = 0 ;
}
return 0 ;
}
int F_132 ( T_1 V_17 , struct V_193 * V_194 )
{
return F_130 ( V_17 , V_194 -> V_146 , V_194 -> V_46 ,
F_131 , V_194 ) ;
}
struct V_202 * F_133 ( T_4 V_203 )
{
struct V_202 * V_204 ;
T_9 V_205 ;
V_205 = F_134 ( T_9 , V_203 , sizeof( * V_204 ) ) ;
V_204 = F_135 ( V_205 ) ;
if ( ! V_204 )
return F_109 ( - V_15 ) ;
if ( V_203 >= sizeof( * V_204 ) ) {
V_204 -> V_162 = V_203 - sizeof( * V_204 ) ;
V_204 -> V_201 = 0 ;
} else {
V_204 -> V_201 = sizeof( * V_204 ) - V_203 ;
V_204 -> V_162 = 0 ;
}
V_204 -> V_198 = 0 ;
V_204 -> V_200 = 0 ;
return V_204 ;
}
struct V_193 * F_136 ( T_10 V_203 , struct V_44 * V_146 ,
struct V_46 * V_47 )
{
struct V_193 * V_206 ;
struct V_202 * V_195 ;
V_195 = F_133 ( V_203 ) ;
if ( F_31 ( V_195 ) )
return ( void * ) V_195 ;
V_206 = F_7 ( sizeof( * V_206 ) , V_14 ) ;
if ( ! V_206 ) {
F_9 ( V_195 ) ;
return F_109 ( - V_15 ) ;
}
V_206 -> V_46 = V_47 ;
V_206 -> V_195 = V_195 ;
V_206 -> V_146 = V_146 ;
return V_206 ;
}
void F_137 ( struct V_193 * V_194 )
{
if ( ! V_194 )
return;
F_138 ( V_194 -> V_195 ) ;
F_9 ( V_194 ) ;
}
