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
if ( V_33 == V_39 )
return 0 ;
V_38 = F_19 ( V_27 , V_37 ) ;
if ( ! V_38 )
return - V_15 ;
V_38 -> V_33 = V_33 ;
if ( V_2 )
V_38 -> V_40 = * V_2 ;
else
memset ( & V_38 -> V_40 , 0 , sizeof( V_38 -> V_40 ) ) ;
V_38 -> V_41 = NULL ;
V_38 -> V_34 = V_34 ;
V_38 -> V_36 = V_36 ;
V_38 -> V_35 = V_35 ;
V_38 -> V_19 = V_19 ;
F_20 ( & V_38 -> V_42 , V_32 ) ;
return 0 ;
}
static int F_21 ( struct V_43 * V_44 , struct V_45 * V_46 ,
struct V_47 * V_48 , int V_34 ,
struct V_1 * V_40 , T_1 V_49 ,
T_1 V_19 ,
const T_1 * V_7 )
{
int V_24 = 0 ;
int V_21 ;
struct V_3 * V_4 ;
struct V_1 V_2 ;
struct V_5 * V_6 ;
struct V_8 * V_9 = NULL , * V_50 = NULL ;
T_1 V_20 ;
if ( V_34 != 0 ) {
V_4 = V_46 -> V_51 [ V_34 ] ;
V_24 = F_22 ( V_48 , V_4 -> V_52 , 0 , V_14 ) ;
if ( V_24 < 0 )
return V_24 ;
return 0 ;
}
if ( V_46 -> V_53 [ 0 ] >= F_9 ( V_46 -> V_51 [ 0 ] ) )
V_24 = F_23 ( V_44 , V_46 , V_49 ) ;
while ( ! V_24 ) {
V_4 = V_46 -> V_51 [ 0 ] ;
V_21 = V_46 -> V_53 [ 0 ] ;
F_10 ( V_4 , & V_2 , V_21 ) ;
if ( V_2 . V_18 != V_40 -> V_18 ||
V_2 . type != V_25 )
break;
V_6 = F_11 ( V_4 , V_21 , struct V_5 ) ;
V_20 = F_13 ( V_4 , V_6 ) ;
if ( V_20 == V_19 ) {
V_9 = NULL ;
V_50 = NULL ;
if ( V_7 ) {
V_24 = F_1 ( & V_2 , V_4 , V_6 ,
* V_7 ,
& V_9 ) ;
if ( V_24 < 0 )
break;
}
if ( V_24 > 0 )
goto V_16;
V_24 = F_24 ( V_48 , V_4 -> V_52 ,
( V_54 ) V_9 ,
( T_1 * ) & V_50 , V_14 ) ;
if ( V_24 < 0 )
break;
if ( ! V_24 && V_7 ) {
while ( V_50 -> V_16 )
V_50 = V_50 -> V_16 ;
V_50 -> V_16 = V_9 ;
}
}
V_16:
V_24 = F_25 ( V_44 , V_46 , V_49 ) ;
}
if ( V_24 > 0 )
V_24 = 0 ;
return V_24 ;
}
static int F_26 ( struct V_55 * V_56 ,
struct V_45 * V_46 , T_1 V_49 ,
struct V_28 * V_38 ,
struct V_47 * V_48 ,
const T_1 * V_7 )
{
struct V_43 * V_44 ;
struct V_1 V_57 ;
struct V_3 * V_4 ;
int V_24 = 0 ;
int V_58 ;
int V_34 = V_38 -> V_34 ;
V_57 . V_18 = V_38 -> V_33 ;
V_57 . type = V_59 ;
V_57 . V_10 = ( T_1 ) - 1 ;
V_44 = F_27 ( V_56 , & V_57 ) ;
if ( F_28 ( V_44 ) ) {
V_24 = F_29 ( V_44 ) ;
goto V_60;
}
V_58 = F_30 ( V_44 , V_49 ) ;
if ( V_58 + 1 == V_34 )
goto V_60;
V_46 -> V_61 = V_34 ;
V_24 = F_31 ( V_44 , & V_38 -> V_40 , V_46 , V_49 ) ;
F_32 ( L_2
L_3 ,
V_38 -> V_33 , V_34 , V_38 -> V_36 , V_24 ,
V_38 -> V_40 . V_18 , V_38 -> V_40 . type ,
V_38 -> V_40 . V_10 ) ;
if ( V_24 < 0 )
goto V_60;
V_4 = V_46 -> V_51 [ V_34 ] ;
while ( ! V_4 ) {
if ( F_33 ( ! V_34 ) ) {
V_24 = 1 ;
goto V_60;
}
V_34 -- ;
V_4 = V_46 -> V_51 [ V_34 ] ;
}
V_24 = F_21 ( V_44 , V_46 , V_48 , V_34 , & V_38 -> V_40 ,
V_49 , V_38 -> V_19 ,
V_7 ) ;
V_60:
V_46 -> V_61 = 0 ;
F_34 ( V_46 ) ;
return V_24 ;
}
static int F_35 ( struct V_55 * V_56 ,
struct V_45 * V_46 , T_1 V_49 ,
struct V_31 * V_32 ,
const T_1 * V_7 )
{
int V_62 ;
int V_24 = 0 ;
struct V_28 * V_38 ;
struct V_28 * V_63 ;
struct V_28 * V_64 ;
struct V_47 * V_48 ;
struct V_65 * V_66 ;
struct V_67 V_68 ;
V_48 = F_36 ( V_14 ) ;
if ( ! V_48 )
return - V_15 ;
F_37 (ref, ref_safe, head, list) {
if ( V_38 -> V_35 )
continue;
if ( V_38 -> V_36 == 0 )
continue;
V_62 = F_26 ( V_56 , V_46 , V_49 , V_38 ,
V_48 , V_7 ) ;
if ( V_62 == - V_15 )
goto V_60;
if ( V_62 )
continue;
F_38 ( & V_68 ) ;
V_66 = F_39 ( V_48 , & V_68 ) ;
V_38 -> V_35 = V_66 ? V_66 -> V_69 : 0 ;
V_38 -> V_41 = V_66 ?
(struct V_8 * ) ( V_54 ) V_66 -> V_70 : NULL ;
while ( ( V_66 = F_39 ( V_48 , & V_68 ) ) ) {
V_64 = F_19 ( V_27 ,
V_14 ) ;
if ( ! V_64 ) {
V_24 = - V_15 ;
goto V_60;
}
memcpy ( V_64 , V_38 , sizeof( * V_38 ) ) ;
V_64 -> V_35 = V_66 -> V_69 ;
V_64 -> V_41 = (struct V_8 * )
( V_54 ) V_66 -> V_70 ;
F_40 ( & V_64 -> V_42 , & V_38 -> V_42 ) ;
}
F_41 ( V_48 ) ;
}
V_60:
F_42 ( V_48 ) ;
return V_24 ;
}
static inline int F_43 ( struct V_28 * V_71 ,
struct V_28 * V_72 )
{
if ( V_71 -> V_34 != V_72 -> V_34 )
return 0 ;
if ( V_71 -> V_33 != V_72 -> V_33 )
return 0 ;
if ( V_71 -> V_40 . type != V_72 -> V_40 . type )
return 0 ;
if ( V_71 -> V_40 . V_18 != V_72 -> V_40 . V_18 )
return 0 ;
if ( V_71 -> V_40 . V_10 != V_72 -> V_40 . V_10 )
return 0 ;
if ( V_71 -> V_35 != V_72 -> V_35 )
return 0 ;
return 1 ;
}
static int F_44 ( struct V_55 * V_56 ,
struct V_31 * V_32 )
{
struct V_31 * V_73 ;
struct V_3 * V_4 ;
F_45 (pos, head) {
struct V_28 * V_38 ;
V_38 = F_46 ( V_73 , struct V_28 , V_42 ) ;
if ( V_38 -> V_35 )
continue;
if ( V_38 -> V_40 . type )
continue;
F_47 ( ! V_38 -> V_19 ) ;
V_4 = F_48 ( V_56 -> V_74 , V_38 -> V_19 ,
V_56 -> V_74 -> V_75 , 0 ) ;
if ( ! V_4 || ! F_49 ( V_4 ) ) {
F_50 ( V_4 ) ;
return - V_76 ;
}
F_51 ( V_4 ) ;
if ( F_52 ( V_4 ) == 0 )
F_10 ( V_4 , & V_38 -> V_40 , 0 ) ;
else
F_53 ( V_4 , & V_38 -> V_40 , 0 ) ;
F_54 ( V_4 ) ;
F_50 ( V_4 ) ;
}
return 0 ;
}
static void F_55 ( struct V_31 * V_32 , int V_77 )
{
struct V_31 * V_78 ;
F_45 (pos1, head) {
struct V_31 * V_79 ;
struct V_31 * V_80 ;
struct V_28 * V_71 ;
V_71 = F_46 ( V_78 , struct V_28 , V_42 ) ;
for ( V_80 = V_78 -> V_16 , V_79 = V_80 -> V_16 ; V_80 != V_32 ;
V_80 = V_79 , V_79 = V_80 -> V_16 ) {
struct V_28 * V_72 ;
struct V_28 * V_81 ;
struct V_8 * V_9 ;
V_72 = F_46 ( V_80 , struct V_28 , V_42 ) ;
if ( V_77 == 1 ) {
if ( ! F_43 ( V_71 , V_72 ) )
continue;
if ( ! V_71 -> V_35 && V_72 -> V_35 ) {
V_81 = V_71 ;
V_71 = V_72 ;
V_72 = V_81 ;
}
} else {
if ( V_71 -> V_35 != V_72 -> V_35 )
continue;
}
V_9 = V_71 -> V_41 ;
while ( V_9 && V_9 -> V_16 )
V_9 = V_9 -> V_16 ;
if ( V_9 )
V_9 -> V_16 = V_72 -> V_41 ;
else
V_71 -> V_41 = V_72 -> V_41 ;
V_71 -> V_36 += V_72 -> V_36 ;
F_56 ( & V_72 -> V_42 ) ;
F_57 ( V_27 , V_72 ) ;
}
}
}
static int F_58 ( struct V_82 * V_32 , T_1 V_83 ,
struct V_31 * V_84 )
{
struct V_85 * V_86 = V_32 -> V_86 ;
struct V_87 * V_88 = & V_32 -> V_66 . V_87 ;
struct V_1 V_2 ;
struct V_1 V_89 = { 0 } ;
int V_90 ;
int V_24 = 0 ;
if ( V_86 && V_86 -> V_91 )
F_59 ( & V_89 , & V_86 -> V_2 ) ;
while ( ( V_88 = F_60 ( V_88 ) ) ) {
struct V_92 * V_66 ;
V_66 = F_61 ( V_88 , struct V_92 ,
V_87 ) ;
if ( V_66 -> V_93 != V_32 -> V_66 . V_93 )
break;
F_33 ( V_66 -> V_94 ) ;
if ( V_66 -> V_83 > V_83 )
continue;
switch ( V_66 -> V_95 ) {
case V_96 :
case V_97 :
F_33 ( 1 ) ;
continue;
case V_98 :
V_90 = 1 ;
break;
case V_99 :
V_90 = - 1 ;
break;
default:
F_47 ( 1 ) ;
}
switch ( V_66 -> type ) {
case V_100 : {
struct V_101 * V_38 ;
V_38 = F_62 ( V_66 ) ;
V_24 = F_18 ( V_84 , V_38 -> V_44 , & V_89 ,
V_38 -> V_34 + 1 , 0 , V_66 -> V_93 ,
V_66 -> V_102 * V_90 , V_103 ) ;
break;
}
case V_104 : {
struct V_101 * V_38 ;
V_38 = F_62 ( V_66 ) ;
V_24 = F_18 ( V_84 , V_38 -> V_44 , NULL ,
V_38 -> V_34 + 1 , V_38 -> V_35 ,
V_66 -> V_93 ,
V_66 -> V_102 * V_90 , V_103 ) ;
break;
}
case V_105 : {
struct V_106 * V_38 ;
V_38 = F_63 ( V_66 ) ;
V_2 . V_18 = V_38 -> V_18 ;
V_2 . type = V_25 ;
V_2 . V_10 = V_38 -> V_10 ;
V_24 = F_18 ( V_84 , V_38 -> V_44 , & V_2 , 0 , 0 ,
V_66 -> V_93 ,
V_66 -> V_102 * V_90 , V_103 ) ;
break;
}
case V_107 : {
struct V_106 * V_38 ;
V_38 = F_63 ( V_66 ) ;
V_2 . V_18 = V_38 -> V_18 ;
V_2 . type = V_25 ;
V_2 . V_10 = V_38 -> V_10 ;
V_24 = F_18 ( V_84 , V_38 -> V_44 , & V_2 , 0 ,
V_38 -> V_35 , V_66 -> V_93 ,
V_66 -> V_102 * V_90 , V_103 ) ;
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
static int F_64 ( struct V_55 * V_56 ,
struct V_45 * V_46 , T_1 V_93 ,
int * V_108 , struct V_31 * V_84 )
{
int V_24 = 0 ;
int V_21 ;
struct V_3 * V_109 ;
struct V_1 V_2 ;
struct V_1 V_110 ;
unsigned long V_111 ;
unsigned long V_112 ;
struct V_113 * V_114 ;
T_1 V_115 ;
T_1 V_116 ;
V_109 = V_46 -> V_51 [ 0 ] ;
V_21 = V_46 -> V_53 [ 0 ] ;
V_116 = F_65 ( V_109 , V_21 ) ;
F_47 ( V_116 < sizeof( * V_114 ) ) ;
V_114 = F_11 ( V_109 , V_21 , struct V_113 ) ;
V_115 = F_66 ( V_109 , V_114 ) ;
F_10 ( V_109 , & V_110 , V_21 ) ;
V_111 = ( unsigned long ) ( V_114 + 1 ) ;
V_112 = ( unsigned long ) V_114 + V_116 ;
if ( V_110 . type == V_117 &&
V_115 & V_118 ) {
struct V_119 * V_120 ;
V_120 = (struct V_119 * ) V_111 ;
* V_108 = F_67 ( V_109 , V_120 ) ;
V_111 += sizeof( struct V_119 ) ;
F_47 ( V_111 > V_112 ) ;
} else if ( V_110 . type == V_121 ) {
* V_108 = V_110 . V_10 ;
} else {
F_47 ( ! ( V_115 & V_122 ) ) ;
}
while ( V_111 < V_112 ) {
struct V_123 * V_124 ;
T_1 V_10 ;
int type ;
V_124 = (struct V_123 * ) V_111 ;
type = F_68 ( V_109 , V_124 ) ;
V_10 = F_69 ( V_109 , V_124 ) ;
switch ( type ) {
case V_104 :
V_24 = F_18 ( V_84 , 0 , NULL ,
* V_108 + 1 , V_10 ,
V_93 , 1 , V_14 ) ;
break;
case V_107 : {
struct V_125 * V_126 ;
int V_36 ;
V_126 = (struct V_125 * ) ( V_124 + 1 ) ;
V_36 = F_70 ( V_109 , V_126 ) ;
V_24 = F_18 ( V_84 , 0 , NULL , 0 , V_10 ,
V_93 , V_36 , V_14 ) ;
break;
}
case V_100 :
V_24 = F_18 ( V_84 , V_10 , NULL ,
* V_108 + 1 , 0 ,
V_93 , 1 , V_14 ) ;
break;
case V_105 : {
struct V_127 * V_128 ;
int V_36 ;
T_1 V_44 ;
V_128 = (struct V_127 * ) ( & V_124 -> V_10 ) ;
V_36 = F_71 ( V_109 , V_128 ) ;
V_2 . V_18 = F_72 ( V_109 ,
V_128 ) ;
V_2 . type = V_25 ;
V_2 . V_10 = F_73 ( V_109 , V_128 ) ;
V_44 = F_74 ( V_109 , V_128 ) ;
V_24 = F_18 ( V_84 , V_44 , & V_2 , 0 , 0 ,
V_93 , V_36 , V_14 ) ;
break;
}
default:
F_33 ( 1 ) ;
}
if ( V_24 )
return V_24 ;
V_111 += F_75 ( type ) ;
}
return 0 ;
}
static int F_76 ( struct V_55 * V_56 ,
struct V_45 * V_46 , T_1 V_93 ,
int V_108 , struct V_31 * V_84 )
{
struct V_43 * V_129 = V_56 -> V_129 ;
int V_24 ;
int V_21 ;
struct V_3 * V_109 ;
struct V_1 V_2 ;
while ( 1 ) {
V_24 = F_77 ( V_129 , V_46 ) ;
if ( V_24 < 0 )
break;
if ( V_24 ) {
V_24 = 0 ;
break;
}
V_21 = V_46 -> V_53 [ 0 ] ;
V_109 = V_46 -> V_51 [ 0 ] ;
F_10 ( V_109 , & V_2 , V_21 ) ;
if ( V_2 . V_18 != V_93 )
break;
if ( V_2 . type < V_100 )
continue;
if ( V_2 . type > V_107 )
break;
switch ( V_2 . type ) {
case V_104 :
V_24 = F_18 ( V_84 , 0 , NULL ,
V_108 + 1 , V_2 . V_10 ,
V_93 , 1 , V_14 ) ;
break;
case V_107 : {
struct V_125 * V_126 ;
int V_36 ;
V_126 = F_11 ( V_109 , V_21 ,
struct V_125 ) ;
V_36 = F_70 ( V_109 , V_126 ) ;
V_24 = F_18 ( V_84 , 0 , NULL , 0 , V_2 . V_10 ,
V_93 , V_36 , V_14 ) ;
break;
}
case V_100 :
V_24 = F_18 ( V_84 , V_2 . V_10 , NULL ,
V_108 + 1 , 0 ,
V_93 , 1 , V_14 ) ;
break;
case V_105 : {
struct V_127 * V_128 ;
int V_36 ;
T_1 V_44 ;
V_128 = F_11 ( V_109 , V_21 ,
struct V_127 ) ;
V_36 = F_71 ( V_109 , V_128 ) ;
V_2 . V_18 = F_72 ( V_109 ,
V_128 ) ;
V_2 . type = V_25 ;
V_2 . V_10 = F_73 ( V_109 , V_128 ) ;
V_44 = F_74 ( V_109 , V_128 ) ;
V_24 = F_18 ( V_84 , V_44 , & V_2 , 0 , 0 ,
V_93 , V_36 , V_14 ) ;
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
static int F_78 ( struct V_130 * V_131 ,
struct V_55 * V_56 , T_1 V_93 ,
T_1 V_49 , struct V_47 * V_132 ,
struct V_47 * V_133 , const T_1 * V_7 )
{
struct V_1 V_2 ;
struct V_45 * V_46 ;
struct V_134 * V_135 = NULL ;
struct V_82 * V_32 ;
int V_108 = 0 ;
int V_24 ;
struct V_31 V_136 ;
struct V_31 V_84 ;
struct V_28 * V_38 ;
F_79 ( & V_84 ) ;
F_79 ( & V_136 ) ;
V_2 . V_18 = V_93 ;
V_2 . V_10 = ( T_1 ) - 1 ;
if ( F_80 ( V_56 , V_137 ) )
V_2 . type = V_121 ;
else
V_2 . type = V_117 ;
V_46 = F_81 () ;
if ( ! V_46 )
return - V_15 ;
if ( ! V_131 )
V_46 -> V_138 = 1 ;
V_139:
V_32 = NULL ;
V_24 = F_82 ( V_131 , V_56 -> V_129 , & V_2 , V_46 , 0 , 0 ) ;
if ( V_24 < 0 )
goto V_60;
F_47 ( V_24 == 0 ) ;
if ( V_131 ) {
V_135 = & V_131 -> V_140 -> V_135 ;
F_83 ( & V_135 -> V_141 ) ;
V_32 = F_84 ( V_131 , V_93 ) ;
if ( V_32 ) {
if ( ! F_85 ( & V_32 -> V_142 ) ) {
F_86 ( & V_32 -> V_66 . V_132 ) ;
F_87 ( & V_135 -> V_141 ) ;
F_34 ( V_46 ) ;
F_88 ( & V_32 -> V_142 ) ;
F_89 ( & V_32 -> V_142 ) ;
F_90 ( & V_32 -> V_66 ) ;
goto V_139;
}
V_24 = F_58 ( V_32 , V_49 ,
& V_136 ) ;
F_89 ( & V_32 -> V_142 ) ;
if ( V_24 ) {
F_87 ( & V_135 -> V_141 ) ;
goto V_60;
}
}
F_87 ( & V_135 -> V_141 ) ;
}
if ( V_46 -> V_53 [ 0 ] ) {
struct V_3 * V_109 ;
int V_21 ;
V_46 -> V_53 [ 0 ] -- ;
V_109 = V_46 -> V_51 [ 0 ] ;
V_21 = V_46 -> V_53 [ 0 ] ;
F_10 ( V_109 , & V_2 , V_21 ) ;
if ( V_2 . V_18 == V_93 &&
( V_2 . type == V_117 ||
V_2 . type == V_121 ) ) {
V_24 = F_64 ( V_56 , V_46 , V_93 ,
& V_108 , & V_84 ) ;
if ( V_24 )
goto V_60;
V_24 = F_76 ( V_56 , V_46 , V_93 ,
V_108 , & V_84 ) ;
if ( V_24 )
goto V_60;
}
}
F_34 ( V_46 ) ;
F_91 ( & V_136 , & V_84 ) ;
V_24 = F_44 ( V_56 , & V_84 ) ;
if ( V_24 )
goto V_60;
F_55 ( & V_84 , 1 ) ;
V_24 = F_35 ( V_56 , V_46 , V_49 , & V_84 ,
V_7 ) ;
if ( V_24 )
goto V_60;
F_55 ( & V_84 , 2 ) ;
while ( ! F_92 ( & V_84 ) ) {
V_38 = F_93 ( & V_84 , struct V_28 , V_42 ) ;
F_33 ( V_38 -> V_36 < 0 ) ;
if ( V_38 -> V_36 && V_38 -> V_33 && V_38 -> V_35 == 0 ) {
V_24 = F_22 ( V_133 , V_38 -> V_33 , 0 , V_14 ) ;
if ( V_24 < 0 )
goto V_60;
}
if ( V_38 -> V_36 && V_38 -> V_35 ) {
struct V_8 * V_9 = NULL ;
if ( V_7 && ! V_38 -> V_41 ) {
T_4 V_143 ;
struct V_3 * V_4 ;
V_143 = F_94 ( V_56 -> V_129 ,
V_108 ) ;
V_4 = F_48 ( V_56 -> V_129 ,
V_38 -> V_35 , V_143 , 0 ) ;
if ( ! V_4 || ! F_49 ( V_4 ) ) {
F_50 ( V_4 ) ;
V_24 = - V_76 ;
goto V_60;
}
V_24 = F_8 ( V_4 , V_93 ,
* V_7 , & V_9 ) ;
F_50 ( V_4 ) ;
if ( V_24 < 0 )
goto V_60;
V_38 -> V_41 = V_9 ;
}
V_24 = F_24 ( V_132 , V_38 -> V_35 ,
( V_54 ) V_38 -> V_41 ,
( T_1 * ) & V_9 , V_14 ) ;
if ( V_24 < 0 )
goto V_60;
if ( ! V_24 && V_7 ) {
F_47 ( ! V_9 ) ;
while ( V_9 -> V_16 )
V_9 = V_9 -> V_16 ;
V_9 -> V_16 = V_38 -> V_41 ;
}
}
F_56 ( & V_38 -> V_42 ) ;
F_57 ( V_27 , V_38 ) ;
}
V_60:
F_95 ( V_46 ) ;
while ( ! F_92 ( & V_84 ) ) {
V_38 = F_93 ( & V_84 , struct V_28 , V_42 ) ;
F_56 ( & V_38 -> V_42 ) ;
F_57 ( V_27 , V_38 ) ;
}
while ( ! F_92 ( & V_136 ) ) {
V_38 = F_93 ( & V_136 , struct V_28 ,
V_42 ) ;
F_56 ( & V_38 -> V_42 ) ;
F_57 ( V_27 , V_38 ) ;
}
return V_24 ;
}
static void F_96 ( struct V_47 * V_144 )
{
struct V_65 * V_66 = NULL ;
struct V_8 * V_9 ;
struct V_8 * V_145 ;
struct V_67 V_68 ;
F_38 ( & V_68 ) ;
while ( ( V_66 = F_39 ( V_144 , & V_68 ) ) ) {
if ( ! V_66 -> V_70 )
continue;
V_9 = (struct V_8 * ) ( V_54 ) V_66 -> V_70 ;
for (; V_9 ; V_9 = V_145 ) {
V_145 = V_9 -> V_16 ;
F_97 ( V_9 ) ;
}
V_66 -> V_70 = 0 ;
}
F_42 ( V_144 ) ;
}
static int F_98 ( struct V_130 * V_131 ,
struct V_55 * V_56 , T_1 V_93 ,
T_1 V_49 , struct V_47 * * V_146 ,
const T_1 * V_7 )
{
struct V_47 * V_147 ;
int V_24 ;
V_147 = F_36 ( V_14 ) ;
if ( ! V_147 )
return - V_15 ;
* V_146 = F_36 ( V_14 ) ;
if ( ! * V_146 ) {
F_42 ( V_147 ) ;
return - V_15 ;
}
V_24 = F_78 ( V_131 , V_56 , V_93 ,
V_49 , * V_146 , V_147 , V_7 ) ;
F_42 ( V_147 ) ;
if ( V_24 < 0 && V_24 != - V_148 ) {
F_96 ( * V_146 ) ;
return V_24 ;
}
return 0 ;
}
int F_99 ( struct V_130 * V_131 ,
struct V_55 * V_56 , T_1 V_93 ,
T_1 V_49 , struct V_47 * * V_133 )
{
struct V_47 * V_147 ;
struct V_65 * V_66 = NULL ;
struct V_67 V_68 ;
int V_24 ;
V_147 = F_36 ( V_14 ) ;
if ( ! V_147 )
return - V_15 ;
* V_133 = F_36 ( V_14 ) ;
if ( ! * V_133 ) {
F_42 ( V_147 ) ;
return - V_15 ;
}
F_38 ( & V_68 ) ;
while ( 1 ) {
V_24 = F_78 ( V_131 , V_56 , V_93 ,
V_49 , V_147 , * V_133 , NULL ) ;
if ( V_24 < 0 && V_24 != - V_148 ) {
F_42 ( V_147 ) ;
F_42 ( * V_133 ) ;
return V_24 ;
}
V_66 = F_39 ( V_147 , & V_68 ) ;
if ( ! V_66 )
break;
V_93 = V_66 -> V_69 ;
}
F_42 ( V_147 ) ;
return 0 ;
}
static int F_100 ( T_1 V_17 , T_1 V_149 , T_5 V_150 ,
struct V_43 * V_151 , struct V_45 * V_46 ,
struct V_1 * V_110 )
{
int V_24 ;
struct V_1 V_2 ;
struct V_3 * V_4 ;
V_2 . type = V_150 ;
V_2 . V_18 = V_17 ;
V_2 . V_10 = V_149 ;
V_24 = F_82 ( NULL , V_151 , & V_2 , V_46 , 0 , 0 ) ;
if ( V_24 < 0 )
return V_24 ;
V_4 = V_46 -> V_51 [ 0 ] ;
if ( V_24 && V_46 -> V_53 [ 0 ] >= F_9 ( V_4 ) ) {
V_24 = F_101 ( V_151 , V_46 ) ;
if ( V_24 )
return V_24 ;
V_4 = V_46 -> V_51 [ 0 ] ;
}
F_10 ( V_4 , V_110 , V_46 -> V_53 [ 0 ] ) ;
if ( V_110 -> type != V_2 . type || V_110 -> V_18 != V_2 . V_18 )
return 1 ;
return 0 ;
}
int F_102 ( T_1 V_17 , T_1 V_149 , struct V_43 * V_151 ,
struct V_45 * V_46 )
{
struct V_1 V_2 ;
return F_100 ( V_17 , V_149 , V_152 , V_151 , V_46 ,
& V_2 ) ;
}
static int F_103 ( T_1 V_17 , T_1 V_149 , struct V_43 * V_151 ,
struct V_45 * V_46 ,
struct V_1 * V_110 )
{
return F_100 ( V_17 , V_149 , V_153 , V_151 , V_46 ,
V_110 ) ;
}
int F_104 ( struct V_43 * V_44 , T_1 V_154 ,
T_1 V_155 , struct V_45 * V_46 ,
struct V_156 * * V_157 ,
T_1 * V_158 )
{
int V_24 , V_21 ;
struct V_1 V_2 ;
struct V_1 V_110 ;
struct V_156 * V_159 ;
struct V_3 * V_109 ;
unsigned long V_111 ;
V_2 . V_18 = V_154 ;
F_105 ( & V_2 , V_160 ) ;
V_2 . V_10 = V_155 ;
V_24 = F_82 ( NULL , V_44 , & V_2 , V_46 , 0 , 0 ) ;
if ( V_24 < 0 )
return V_24 ;
while ( 1 ) {
V_109 = V_46 -> V_51 [ 0 ] ;
V_21 = V_46 -> V_53 [ 0 ] ;
if ( V_21 >= F_9 ( V_109 ) ) {
V_24 = F_101 ( V_44 , V_46 ) ;
if ( V_24 ) {
if ( V_24 >= 1 )
V_24 = - V_148 ;
break;
}
continue;
}
F_10 ( V_109 , & V_110 , V_21 ) ;
V_24 = - V_148 ;
if ( V_110 . V_18 != V_154 )
break;
if ( F_106 ( & V_110 ) != V_160 )
break;
V_24 = 0 ;
V_111 = F_107 ( V_109 , V_46 -> V_53 [ 0 ] ) ;
V_159 = (struct V_156 * ) V_111 ;
* V_157 = V_159 ;
if ( V_158 )
* V_158 = V_110 . V_10 ;
break;
}
return V_24 ;
}
char * F_108 ( struct V_43 * V_151 , struct V_45 * V_46 ,
T_4 V_161 , unsigned long V_162 ,
struct V_3 * V_163 , T_1 V_35 ,
char * V_164 , T_4 V_165 )
{
int V_21 ;
T_1 V_166 ;
int V_24 ;
T_6 V_167 = ( ( T_6 ) V_165 ) - 1 ;
struct V_3 * V_4 = V_163 ;
struct V_1 V_110 ;
int V_168 = V_46 -> V_168 ;
struct V_169 * V_124 ;
if ( V_167 >= 0 )
V_164 [ V_167 ] = '\0' ;
V_46 -> V_168 = 1 ;
while ( 1 ) {
V_167 -= V_161 ;
if ( V_167 >= 0 )
F_109 ( V_4 , V_164 + V_167 ,
V_162 , V_161 ) ;
if ( V_4 != V_163 ) {
F_110 ( V_4 ) ;
F_50 ( V_4 ) ;
}
V_24 = F_103 ( V_35 , 0 , V_151 , V_46 , & V_110 ) ;
if ( V_24 > 0 )
V_24 = - V_148 ;
if ( V_24 )
break;
V_166 = V_110 . V_10 ;
if ( V_35 == V_166 )
break;
V_21 = V_46 -> V_53 [ 0 ] ;
V_4 = V_46 -> V_51 [ 0 ] ;
if ( V_4 != V_163 ) {
F_86 ( & V_4 -> V_132 ) ;
F_51 ( V_4 ) ;
F_111 ( V_4 , V_170 ) ;
}
F_34 ( V_46 ) ;
V_124 = F_11 ( V_4 , V_21 , struct V_169 ) ;
V_161 = F_112 ( V_4 , V_124 ) ;
V_162 = ( unsigned long ) ( V_124 + 1 ) ;
V_35 = V_166 ;
-- V_167 ;
if ( V_167 >= 0 )
V_164 [ V_167 ] = '/' ;
}
F_34 ( V_46 ) ;
V_46 -> V_168 = V_168 ;
if ( V_24 )
return F_113 ( V_24 ) ;
return V_164 + V_167 ;
}
int F_114 ( struct V_55 * V_56 , T_1 V_171 ,
struct V_45 * V_46 , struct V_1 * V_110 ,
T_1 * V_172 )
{
int V_24 ;
T_1 V_115 ;
T_1 V_165 = 0 ;
T_4 V_116 ;
struct V_3 * V_4 ;
struct V_113 * V_114 ;
struct V_1 V_2 ;
if ( F_80 ( V_56 , V_137 ) )
V_2 . type = V_121 ;
else
V_2 . type = V_117 ;
V_2 . V_18 = V_171 ;
V_2 . V_10 = ( T_1 ) - 1 ;
V_24 = F_82 ( NULL , V_56 -> V_129 , & V_2 , V_46 , 0 , 0 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_115 ( V_56 -> V_129 , V_46 ,
0 , V_117 ) ;
if ( V_24 < 0 )
return V_24 ;
F_10 ( V_46 -> V_51 [ 0 ] , V_110 , V_46 -> V_53 [ 0 ] ) ;
if ( V_110 -> type == V_121 )
V_165 = V_56 -> V_129 -> V_75 ;
else if ( V_110 -> type == V_117 )
V_165 = V_110 -> V_10 ;
if ( ( V_110 -> type != V_117 &&
V_110 -> type != V_121 ) ||
V_110 -> V_18 > V_171 ||
V_110 -> V_18 + V_165 <= V_171 ) {
F_32 ( L_4 , V_171 ) ;
return - V_148 ;
}
V_4 = V_46 -> V_51 [ 0 ] ;
V_116 = F_65 ( V_4 , V_46 -> V_53 [ 0 ] ) ;
F_47 ( V_116 < sizeof( * V_114 ) ) ;
V_114 = F_11 ( V_4 , V_46 -> V_53 [ 0 ] , struct V_113 ) ;
V_115 = F_66 ( V_4 , V_114 ) ;
F_32 ( L_5
L_6 ,
V_171 , V_171 - V_110 -> V_18 , V_110 -> V_18 ,
V_110 -> V_10 , V_115 , V_116 ) ;
F_33 ( ! V_172 ) ;
if ( V_172 ) {
if ( V_115 & V_118 )
* V_172 = V_118 ;
else if ( V_115 & V_122 )
* V_172 = V_122 ;
else
F_47 ( 1 ) ;
return 0 ;
}
return - V_76 ;
}
static int F_116 ( unsigned long * V_111 , struct V_3 * V_4 ,
struct V_113 * V_114 , T_4 V_116 ,
struct V_123 * * V_173 ,
int * V_174 )
{
unsigned long V_112 ;
T_1 V_115 ;
struct V_119 * V_120 ;
if ( ! * V_111 ) {
V_115 = F_66 ( V_4 , V_114 ) ;
if ( V_115 & V_118 ) {
V_120 = (struct V_119 * ) ( V_114 + 1 ) ;
* V_173 =
(struct V_123 * ) ( V_120 + 1 ) ;
} else {
* V_173 = (struct V_123 * ) ( V_114 + 1 ) ;
}
* V_111 = ( unsigned long ) * V_173 ;
if ( ( void * ) * V_111 >= ( void * ) V_114 + V_116 )
return - V_148 ;
}
V_112 = ( unsigned long ) V_114 + V_116 ;
* V_173 = (struct V_123 * ) * V_111 ;
* V_174 = F_68 ( V_4 , * V_173 ) ;
* V_111 += F_75 ( * V_174 ) ;
F_33 ( * V_111 > V_112 ) ;
if ( * V_111 == V_112 )
return 1 ;
return 0 ;
}
int F_117 ( unsigned long * V_111 , struct V_3 * V_4 ,
struct V_113 * V_114 , T_4 V_116 ,
T_1 * V_175 , T_5 * V_176 )
{
int V_24 ;
int type ;
struct V_119 * V_120 ;
struct V_123 * V_177 ;
if ( * V_111 == ( unsigned long ) - 1 )
return 1 ;
while ( 1 ) {
V_24 = F_116 ( V_111 , V_4 , V_114 , V_116 ,
& V_177 , & type ) ;
if ( V_24 < 0 )
return V_24 ;
if ( type == V_100 ||
type == V_104 )
break;
if ( V_24 == 1 )
return 1 ;
}
V_120 = (struct V_119 * ) ( V_114 + 1 ) ;
* V_175 = F_69 ( V_4 , V_177 ) ;
* V_176 = F_67 ( V_4 , V_120 ) ;
if ( V_24 == 1 )
* V_111 = ( unsigned long ) - 1 ;
return 0 ;
}
static int F_118 ( struct V_8 * V_41 ,
T_1 V_44 , T_1 V_178 ,
T_7 * V_179 , void * V_180 )
{
struct V_8 * V_9 ;
int V_24 = 0 ;
for ( V_9 = V_41 ; V_9 ; V_9 = V_9 -> V_16 ) {
F_32 ( L_7
L_8 , V_178 ,
V_9 -> V_17 , V_9 -> V_10 , V_44 ) ;
V_24 = V_179 ( V_9 -> V_17 , V_9 -> V_10 , V_44 , V_180 ) ;
if ( V_24 ) {
F_32 ( L_9 ,
V_178 , V_24 ) ;
break;
}
}
return V_24 ;
}
int F_119 ( struct V_55 * V_56 ,
T_1 V_178 , T_1 V_7 ,
int V_138 ,
T_7 * V_179 , void * V_180 )
{
int V_24 ;
struct V_130 * V_131 = NULL ;
struct V_47 * V_132 = NULL ;
struct V_47 * V_133 = NULL ;
struct V_65 * V_181 = NULL ;
struct V_65 * V_182 = NULL ;
struct V_183 V_184 = {} ;
struct V_67 V_185 ;
struct V_67 V_186 ;
F_32 ( L_10 ,
V_178 ) ;
if ( ! V_138 ) {
V_131 = F_120 ( V_56 -> V_129 ) ;
if ( F_28 ( V_131 ) )
return F_29 ( V_131 ) ;
F_121 ( V_56 , & V_184 ) ;
}
V_24 = F_98 ( V_131 , V_56 , V_178 ,
V_184 . V_83 , & V_132 ,
& V_7 ) ;
if ( V_24 )
goto V_60;
F_38 ( & V_185 ) ;
while ( ! V_24 && ( V_181 = F_39 ( V_132 , & V_185 ) ) ) {
V_24 = F_99 ( V_131 , V_56 , V_181 -> V_69 ,
V_184 . V_83 , & V_133 ) ;
if ( V_24 )
break;
F_38 ( & V_186 ) ;
while ( ! V_24 && ( V_182 = F_39 ( V_133 , & V_186 ) ) ) {
F_32 ( L_11
L_12 , V_182 -> V_69 , V_181 -> V_69 ,
V_181 -> V_70 ) ;
V_24 = F_118 ( (struct V_8 * )
( V_54 ) V_181 -> V_70 ,
V_182 -> V_69 ,
V_178 ,
V_179 , V_180 ) ;
}
F_42 ( V_133 ) ;
}
F_96 ( V_132 ) ;
V_60:
if ( ! V_138 ) {
F_122 ( V_56 , & V_184 ) ;
F_123 ( V_131 , V_56 -> V_129 ) ;
}
return V_24 ;
}
int F_124 ( T_1 V_171 , struct V_55 * V_56 ,
struct V_45 * V_46 ,
T_7 * V_179 , void * V_180 )
{
int V_24 ;
T_1 V_7 ;
T_1 V_115 = 0 ;
struct V_1 V_110 ;
int V_138 = V_46 -> V_138 ;
V_24 = F_114 ( V_56 , V_171 , V_46 , & V_110 , & V_115 ) ;
F_34 ( V_46 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_115 & V_118 )
return - V_187 ;
V_7 = V_171 - V_110 . V_18 ;
V_24 = F_119 ( V_56 , V_110 . V_18 ,
V_7 , V_138 ,
V_179 , V_180 ) ;
return V_24 ;
}
static int F_125 ( T_1 V_17 , struct V_43 * V_151 ,
struct V_45 * V_46 ,
T_8 * V_179 , void * V_180 )
{
int V_24 = 0 ;
int V_21 ;
T_4 V_188 ;
T_4 V_189 ;
T_4 V_161 ;
T_1 V_35 = 0 ;
int V_190 = 0 ;
struct V_3 * V_4 ;
struct V_191 * V_192 ;
struct V_169 * V_124 ;
struct V_1 V_110 ;
while ( ! V_24 ) {
V_46 -> V_168 = 1 ;
V_24 = F_103 ( V_17 , V_35 ? V_35 + 1 : 0 , V_151 , V_46 ,
& V_110 ) ;
if ( V_24 < 0 )
break;
if ( V_24 ) {
V_24 = V_190 ? 0 : - V_148 ;
break;
}
++ V_190 ;
V_35 = V_110 . V_10 ;
V_21 = V_46 -> V_53 [ 0 ] ;
V_4 = V_46 -> V_51 [ 0 ] ;
F_86 ( & V_4 -> V_132 ) ;
F_51 ( V_4 ) ;
F_111 ( V_4 , V_170 ) ;
F_34 ( V_46 ) ;
V_192 = F_126 ( V_21 ) ;
V_124 = F_11 ( V_4 , V_21 , struct V_169 ) ;
for ( V_188 = 0 ; V_188 < F_127 ( V_4 , V_192 ) ; V_188 += V_189 ) {
V_161 = F_112 ( V_4 , V_124 ) ;
F_32 ( L_13
L_14 , V_188 , V_110 . V_18 ,
V_151 -> V_18 ) ;
V_24 = V_179 ( V_35 , V_161 ,
( unsigned long ) ( V_124 + 1 ) , V_4 , V_180 ) ;
if ( V_24 )
break;
V_189 = sizeof( * V_124 ) + V_161 ;
V_124 = (struct V_169 * ) ( ( char * ) V_124 + V_189 ) ;
}
F_110 ( V_4 ) ;
F_50 ( V_4 ) ;
}
F_34 ( V_46 ) ;
return V_24 ;
}
static int F_128 ( T_1 V_17 , struct V_43 * V_151 ,
struct V_45 * V_46 ,
T_8 * V_179 , void * V_180 )
{
int V_24 ;
int V_21 ;
T_1 V_10 = 0 ;
T_1 V_35 ;
int V_190 = 0 ;
struct V_3 * V_4 ;
struct V_156 * V_159 ;
struct V_3 * V_109 ;
T_4 V_116 ;
T_4 V_193 ;
unsigned long V_111 ;
while ( 1 ) {
V_24 = F_104 ( V_151 , V_17 , V_10 , V_46 , & V_159 ,
& V_10 ) ;
if ( V_24 < 0 )
break;
if ( V_24 ) {
V_24 = V_190 ? 0 : - V_148 ;
break;
}
++ V_190 ;
V_21 = V_46 -> V_53 [ 0 ] ;
V_4 = V_46 -> V_51 [ 0 ] ;
F_86 ( & V_4 -> V_132 ) ;
F_51 ( V_4 ) ;
F_111 ( V_4 , V_170 ) ;
F_34 ( V_46 ) ;
V_109 = V_46 -> V_51 [ 0 ] ;
V_116 = F_65 ( V_109 , V_46 -> V_53 [ 0 ] ) ;
V_111 = F_107 ( V_109 , V_46 -> V_53 [ 0 ] ) ;
V_193 = 0 ;
while ( V_193 < V_116 ) {
T_4 V_161 ;
V_159 = (struct V_156 * ) ( V_111 + V_193 ) ;
V_35 = F_129 ( V_4 , V_159 ) ;
V_161 = F_130 ( V_4 , V_159 ) ;
V_24 = V_179 ( V_35 , V_161 ,
( unsigned long ) & V_159 -> V_194 , V_4 , V_180 ) ;
if ( V_24 )
break;
V_193 += F_130 ( V_109 , V_159 ) ;
V_193 += sizeof( * V_159 ) ;
}
F_110 ( V_4 ) ;
F_50 ( V_4 ) ;
V_10 ++ ;
}
F_34 ( V_46 ) ;
return V_24 ;
}
static int F_131 ( T_1 V_17 , struct V_43 * V_151 ,
struct V_45 * V_46 , T_8 * V_179 ,
void * V_180 )
{
int V_24 ;
int V_195 = 0 ;
V_24 = F_125 ( V_17 , V_151 , V_46 , V_179 , V_180 ) ;
if ( ! V_24 )
++ V_195 ;
else if ( V_24 != - V_148 )
return V_24 ;
V_24 = F_128 ( V_17 , V_151 , V_46 , V_179 , V_180 ) ;
if ( V_24 == - V_148 && V_195 )
return 0 ;
return V_24 ;
}
static int F_132 ( T_1 V_17 , T_4 V_161 , unsigned long V_162 ,
struct V_3 * V_4 , void * V_180 )
{
struct V_196 * V_197 = V_180 ;
char * V_198 ;
char * V_199 ;
int V_200 = V_197 -> V_198 -> V_201 ;
const int V_202 = sizeof( char * ) ;
T_4 V_167 ;
V_167 = V_197 -> V_198 -> V_167 > V_202 ?
V_197 -> V_198 -> V_167 - V_202 : 0 ;
V_199 = ( char * ) V_197 -> V_198 -> V_69 + ( V_200 + 1 ) * V_202 ;
V_198 = F_108 ( V_197 -> V_151 , V_197 -> V_45 , V_161 ,
V_162 , V_4 , V_17 , V_199 , V_167 ) ;
if ( F_28 ( V_198 ) )
return F_29 ( V_198 ) ;
if ( V_198 > V_199 ) {
V_197 -> V_198 -> V_69 [ V_200 ] = ( T_1 ) ( unsigned long ) V_198 ;
++ V_197 -> V_198 -> V_201 ;
V_197 -> V_198 -> V_167 = V_198 - V_199 ;
} else {
++ V_197 -> V_198 -> V_203 ;
V_197 -> V_198 -> V_204 += V_199 - V_198 ;
V_197 -> V_198 -> V_167 = 0 ;
}
return 0 ;
}
int F_133 ( T_1 V_17 , struct V_196 * V_197 )
{
return F_131 ( V_17 , V_197 -> V_151 , V_197 -> V_45 ,
F_132 , V_197 ) ;
}
struct V_205 * F_134 ( T_4 V_206 )
{
struct V_205 * V_207 ;
T_9 V_208 ;
V_208 = F_135 ( T_9 , V_206 , sizeof( * V_207 ) ) ;
V_207 = F_136 ( V_208 ) ;
if ( ! V_207 )
return F_113 ( - V_15 ) ;
if ( V_206 >= sizeof( * V_207 ) ) {
V_207 -> V_167 = V_206 - sizeof( * V_207 ) ;
V_207 -> V_204 = 0 ;
} else {
V_207 -> V_204 = sizeof( * V_207 ) - V_206 ;
V_207 -> V_167 = 0 ;
}
V_207 -> V_201 = 0 ;
V_207 -> V_203 = 0 ;
return V_207 ;
}
struct V_196 * F_137 ( T_10 V_206 , struct V_43 * V_151 ,
struct V_45 * V_46 )
{
struct V_196 * V_209 ;
struct V_205 * V_198 ;
V_198 = F_134 ( V_206 ) ;
if ( F_28 ( V_198 ) )
return ( void * ) V_198 ;
V_209 = F_7 ( sizeof( * V_209 ) , V_14 ) ;
if ( ! V_209 ) {
F_97 ( V_198 ) ;
return F_113 ( - V_15 ) ;
}
V_209 -> V_45 = V_46 ;
V_209 -> V_198 = V_198 ;
V_209 -> V_151 = V_151 ;
return V_209 ;
}
void F_138 ( struct V_196 * V_197 )
{
if ( ! V_197 )
return;
F_139 ( V_197 -> V_198 ) ;
F_97 ( V_197 ) ;
}
