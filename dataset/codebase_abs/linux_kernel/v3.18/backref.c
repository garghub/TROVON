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
V_9 , ( void * * ) & V_52 , V_14 ) ;
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
static int F_28 ( struct V_56 * V_57 ,
struct V_46 * V_47 , T_1 V_50 ,
struct V_29 * V_39 ,
struct V_48 * V_49 ,
const T_1 * V_7 , T_1 V_51 )
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
if ( V_47 -> V_64 )
V_59 = F_34 ( V_45 -> V_65 ) ;
else
V_59 = F_35 ( V_45 , V_50 ) ;
if ( V_59 + 1 == V_35 ) {
F_32 ( & V_57 -> V_62 , V_60 ) ;
goto V_63;
}
V_47 -> V_66 = V_35 ;
V_25 = F_36 ( V_45 , & V_39 -> V_41 , V_47 , V_50 ) ;
F_32 ( & V_57 -> V_62 , V_60 ) ;
F_37 ( L_2
L_3 ,
V_39 -> V_34 , V_35 , V_39 -> V_37 , V_25 ,
V_39 -> V_41 . V_18 , V_39 -> V_41 . type ,
V_39 -> V_41 . V_10 ) ;
if ( V_25 < 0 )
goto V_63;
V_4 = V_47 -> V_53 [ V_35 ] ;
while ( ! V_4 ) {
if ( F_38 ( ! V_35 ) ) {
V_25 = 1 ;
goto V_63;
}
V_35 -- ;
V_4 = V_47 -> V_53 [ V_35 ] ;
}
V_25 = F_23 ( V_45 , V_47 , V_49 , V_39 , V_35 , V_50 ,
V_7 , V_51 ) ;
V_63:
V_47 -> V_66 = 0 ;
F_39 ( V_47 ) ;
return V_25 ;
}
static int F_40 ( struct V_56 * V_57 ,
struct V_46 * V_47 , T_1 V_50 ,
struct V_32 * V_33 ,
const T_1 * V_7 , T_1 V_51 ,
T_1 V_67 )
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
if ( V_67 && V_39 -> V_34 != V_67 ) {
V_25 = V_75 ;
goto V_63;
}
V_68 = F_28 ( V_57 , V_47 , V_50 , V_39 ,
V_49 , V_7 ,
V_51 ) ;
if ( V_68 == - V_76 ) {
continue;
} else if ( V_68 ) {
V_25 = V_68 ;
goto V_63;
}
F_43 ( & V_74 ) ;
V_72 = F_44 ( V_49 , & V_74 ) ;
V_39 -> V_36 = V_72 ? V_72 -> V_77 : 0 ;
V_39 -> V_42 = V_72 ?
(struct V_8 * ) ( V_78 ) V_72 -> V_79 : NULL ;
while ( ( V_72 = F_44 ( V_49 , & V_74 ) ) ) {
V_70 = F_21 ( V_28 ,
V_14 ) ;
if ( ! V_70 ) {
V_25 = - V_15 ;
goto V_63;
}
memcpy ( V_70 , V_39 , sizeof( * V_39 ) ) ;
V_70 -> V_36 = V_72 -> V_77 ;
V_70 -> V_42 = (struct V_8 * )
( V_78 ) V_72 -> V_79 ;
F_45 ( & V_70 -> V_43 , & V_39 -> V_43 ) ;
}
F_46 ( V_49 ) ;
}
V_63:
F_47 ( V_49 ) ;
return V_25 ;
}
static inline int F_48 ( struct V_29 * V_80 ,
struct V_29 * V_81 )
{
if ( V_80 -> V_35 != V_81 -> V_35 )
return 0 ;
if ( V_80 -> V_34 != V_81 -> V_34 )
return 0 ;
if ( V_80 -> V_41 . type != V_81 -> V_41 . type )
return 0 ;
if ( V_80 -> V_41 . V_18 != V_81 -> V_41 . V_18 )
return 0 ;
if ( V_80 -> V_41 . V_10 != V_81 -> V_41 . V_10 )
return 0 ;
if ( V_80 -> V_36 != V_81 -> V_36 )
return 0 ;
return 1 ;
}
static int F_49 ( struct V_56 * V_57 ,
struct V_32 * V_33 )
{
struct V_32 * V_82 ;
struct V_3 * V_4 ;
F_50 (pos, head) {
struct V_29 * V_39 ;
V_39 = F_51 ( V_82 , struct V_29 , V_43 ) ;
if ( V_39 -> V_36 )
continue;
if ( V_39 -> V_41 . type )
continue;
F_52 ( ! V_39 -> V_20 ) ;
V_4 = F_53 ( V_57 -> V_83 , V_39 -> V_20 ,
0 ) ;
if ( ! V_4 || ! F_54 ( V_4 ) ) {
F_55 ( V_4 ) ;
return - V_84 ;
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
static void F_59 ( struct V_32 * V_33 , int V_85 )
{
struct V_32 * V_86 ;
F_50 (pos1, head) {
struct V_32 * V_87 ;
struct V_32 * V_88 ;
struct V_29 * V_80 ;
V_80 = F_51 ( V_86 , struct V_29 , V_43 ) ;
for ( V_88 = V_86 -> V_16 , V_87 = V_88 -> V_16 ; V_88 != V_33 ;
V_88 = V_87 , V_87 = V_88 -> V_16 ) {
struct V_29 * V_81 ;
struct V_29 * V_89 ;
struct V_8 * V_9 ;
V_81 = F_51 ( V_88 , struct V_29 , V_43 ) ;
if ( V_85 == 1 ) {
if ( ! F_48 ( V_80 , V_81 ) )
continue;
if ( ! V_80 -> V_36 && V_81 -> V_36 ) {
V_89 = V_80 ;
V_80 = V_81 ;
V_81 = V_89 ;
}
} else {
if ( V_80 -> V_36 != V_81 -> V_36 )
continue;
}
V_9 = V_80 -> V_42 ;
while ( V_9 && V_9 -> V_16 )
V_9 = V_9 -> V_16 ;
if ( V_9 )
V_9 -> V_16 = V_81 -> V_42 ;
else
V_80 -> V_42 = V_81 -> V_42 ;
V_80 -> V_37 += V_81 -> V_37 ;
F_60 ( & V_81 -> V_43 ) ;
F_61 ( V_28 , V_81 ) ;
}
}
}
static int F_62 ( struct V_90 * V_33 , T_1 V_91 ,
struct V_32 * V_92 , T_1 * V_51 ,
T_1 V_17 )
{
struct V_93 * V_94 = V_33 -> V_94 ;
struct V_95 * V_96 = & V_33 -> V_72 . V_95 ;
struct V_1 V_2 ;
struct V_1 V_97 = { 0 } ;
int V_98 ;
int V_25 = 0 ;
if ( V_94 && V_94 -> V_99 )
F_63 ( & V_97 , & V_94 -> V_2 ) ;
F_64 ( & V_33 -> V_100 ) ;
V_96 = F_65 ( & V_33 -> V_101 ) ;
while ( V_96 ) {
struct V_102 * V_72 ;
V_72 = F_66 ( V_96 , struct V_102 ,
V_95 ) ;
V_96 = F_67 ( V_96 ) ;
if ( V_72 -> V_91 > V_91 )
continue;
switch ( V_72 -> V_103 ) {
case V_104 :
case V_105 :
F_38 ( 1 ) ;
continue;
case V_106 :
V_98 = 1 ;
break;
case V_107 :
V_98 = - 1 ;
break;
default:
F_52 ( 1 ) ;
}
* V_51 += ( V_72 -> V_108 * V_98 ) ;
switch ( V_72 -> type ) {
case V_109 : {
struct V_110 * V_39 ;
V_39 = F_68 ( V_72 ) ;
V_25 = F_20 ( V_92 , V_39 -> V_45 , & V_97 ,
V_39 -> V_35 + 1 , 0 , V_72 -> V_111 ,
V_72 -> V_108 * V_98 , V_112 ) ;
break;
}
case V_113 : {
struct V_110 * V_39 ;
V_39 = F_68 ( V_72 ) ;
V_25 = F_20 ( V_92 , V_39 -> V_45 , NULL ,
V_39 -> V_35 + 1 , V_39 -> V_36 ,
V_72 -> V_111 ,
V_72 -> V_108 * V_98 , V_112 ) ;
break;
}
case V_114 : {
struct V_115 * V_39 ;
V_39 = F_69 ( V_72 ) ;
V_2 . V_18 = V_39 -> V_18 ;
V_2 . type = V_26 ;
V_2 . V_10 = V_39 -> V_10 ;
if ( V_17 && V_39 -> V_18 != V_17 ) {
V_25 = V_75 ;
break;
}
V_25 = F_20 ( V_92 , V_39 -> V_45 , & V_2 , 0 , 0 ,
V_72 -> V_111 ,
V_72 -> V_108 * V_98 , V_112 ) ;
break;
}
case V_116 : {
struct V_115 * V_39 ;
V_39 = F_69 ( V_72 ) ;
V_2 . V_18 = V_39 -> V_18 ;
V_2 . type = V_26 ;
V_2 . V_10 = V_39 -> V_10 ;
V_25 = F_20 ( V_92 , V_39 -> V_45 , & V_2 , 0 ,
V_39 -> V_36 , V_72 -> V_111 ,
V_72 -> V_108 * V_98 , V_112 ) ;
break;
}
default:
F_38 ( 1 ) ;
}
if ( V_25 )
break;
}
F_70 ( & V_33 -> V_100 ) ;
return V_25 ;
}
static int F_71 ( struct V_56 * V_57 ,
struct V_46 * V_47 , T_1 V_111 ,
int * V_117 , struct V_32 * V_92 ,
T_1 * V_51 , T_1 V_17 )
{
int V_25 = 0 ;
int V_22 ;
struct V_3 * V_118 ;
struct V_1 V_2 ;
struct V_1 V_119 ;
unsigned long V_120 ;
unsigned long V_121 ;
struct V_122 * V_123 ;
T_1 V_124 ;
T_1 V_125 ;
V_118 = V_47 -> V_53 [ 0 ] ;
V_22 = V_47 -> V_55 [ 0 ] ;
V_125 = F_72 ( V_118 , V_22 ) ;
F_52 ( V_125 < sizeof( * V_123 ) ) ;
V_123 = F_13 ( V_118 , V_22 , struct V_122 ) ;
V_124 = F_73 ( V_118 , V_123 ) ;
* V_51 += F_74 ( V_118 , V_123 ) ;
F_12 ( V_118 , & V_119 , V_22 ) ;
V_120 = ( unsigned long ) ( V_123 + 1 ) ;
V_121 = ( unsigned long ) V_123 + V_125 ;
if ( V_119 . type == V_126 &&
V_124 & V_127 ) {
struct V_128 * V_129 ;
V_129 = (struct V_128 * ) V_120 ;
* V_117 = F_75 ( V_118 , V_129 ) ;
V_120 += sizeof( struct V_128 ) ;
F_52 ( V_120 > V_121 ) ;
} else if ( V_119 . type == V_130 ) {
* V_117 = V_119 . V_10 ;
} else {
F_52 ( ! ( V_124 & V_131 ) ) ;
}
while ( V_120 < V_121 ) {
struct V_132 * V_133 ;
T_1 V_10 ;
int type ;
V_133 = (struct V_132 * ) V_120 ;
type = F_76 ( V_118 , V_133 ) ;
V_10 = F_77 ( V_118 , V_133 ) ;
switch ( type ) {
case V_113 :
V_25 = F_20 ( V_92 , 0 , NULL ,
* V_117 + 1 , V_10 ,
V_111 , 1 , V_14 ) ;
break;
case V_116 : {
struct V_134 * V_135 ;
int V_37 ;
V_135 = (struct V_134 * ) ( V_133 + 1 ) ;
V_37 = F_78 ( V_118 , V_135 ) ;
V_25 = F_20 ( V_92 , 0 , NULL , 0 , V_10 ,
V_111 , V_37 , V_14 ) ;
break;
}
case V_109 :
V_25 = F_20 ( V_92 , V_10 , NULL ,
* V_117 + 1 , 0 ,
V_111 , 1 , V_14 ) ;
break;
case V_114 : {
struct V_136 * V_137 ;
int V_37 ;
T_1 V_45 ;
V_137 = (struct V_136 * ) ( & V_133 -> V_10 ) ;
V_37 = F_79 ( V_118 , V_137 ) ;
V_2 . V_18 = F_80 ( V_118 ,
V_137 ) ;
V_2 . type = V_26 ;
V_2 . V_10 = F_81 ( V_118 , V_137 ) ;
if ( V_17 && V_2 . V_18 != V_17 ) {
V_25 = V_75 ;
break;
}
V_45 = F_82 ( V_118 , V_137 ) ;
V_25 = F_20 ( V_92 , V_45 , & V_2 , 0 , 0 ,
V_111 , V_37 , V_14 ) ;
break;
}
default:
F_38 ( 1 ) ;
}
if ( V_25 )
return V_25 ;
V_120 += F_83 ( type ) ;
}
return 0 ;
}
static int F_84 ( struct V_56 * V_57 ,
struct V_46 * V_47 , T_1 V_111 ,
int V_117 , struct V_32 * V_92 , T_1 V_17 )
{
struct V_44 * V_138 = V_57 -> V_138 ;
int V_25 ;
int V_22 ;
struct V_3 * V_118 ;
struct V_1 V_2 ;
while ( 1 ) {
V_25 = F_85 ( V_138 , V_47 ) ;
if ( V_25 < 0 )
break;
if ( V_25 ) {
V_25 = 0 ;
break;
}
V_22 = V_47 -> V_55 [ 0 ] ;
V_118 = V_47 -> V_53 [ 0 ] ;
F_12 ( V_118 , & V_2 , V_22 ) ;
if ( V_2 . V_18 != V_111 )
break;
if ( V_2 . type < V_109 )
continue;
if ( V_2 . type > V_116 )
break;
switch ( V_2 . type ) {
case V_113 :
V_25 = F_20 ( V_92 , 0 , NULL ,
V_117 + 1 , V_2 . V_10 ,
V_111 , 1 , V_14 ) ;
break;
case V_116 : {
struct V_134 * V_135 ;
int V_37 ;
V_135 = F_13 ( V_118 , V_22 ,
struct V_134 ) ;
V_37 = F_78 ( V_118 , V_135 ) ;
V_25 = F_20 ( V_92 , 0 , NULL , 0 , V_2 . V_10 ,
V_111 , V_37 , V_14 ) ;
break;
}
case V_109 :
V_25 = F_20 ( V_92 , V_2 . V_10 , NULL ,
V_117 + 1 , 0 ,
V_111 , 1 , V_14 ) ;
break;
case V_114 : {
struct V_136 * V_137 ;
int V_37 ;
T_1 V_45 ;
V_137 = F_13 ( V_118 , V_22 ,
struct V_136 ) ;
V_37 = F_79 ( V_118 , V_137 ) ;
V_2 . V_18 = F_80 ( V_118 ,
V_137 ) ;
V_2 . type = V_26 ;
V_2 . V_10 = F_81 ( V_118 , V_137 ) ;
if ( V_17 && V_2 . V_18 != V_17 ) {
V_25 = V_75 ;
break;
}
V_45 = F_82 ( V_118 , V_137 ) ;
V_25 = F_20 ( V_92 , V_45 , & V_2 , 0 , 0 ,
V_111 , V_37 , V_14 ) ;
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
static void F_86 ( struct V_48 * V_139 )
{
struct V_71 * V_72 = NULL ;
struct V_8 * V_9 ;
struct V_73 V_74 ;
F_43 ( & V_74 ) ;
while ( ( V_72 = F_44 ( V_139 , & V_74 ) ) ) {
if ( ! V_72 -> V_79 )
continue;
V_9 = (struct V_8 * ) ( V_78 ) V_72 -> V_79 ;
F_8 ( V_9 ) ;
V_72 -> V_79 = 0 ;
}
F_47 ( V_139 ) ;
}
static int F_87 ( struct V_140 * V_141 ,
struct V_56 * V_57 , T_1 V_111 ,
T_1 V_50 , struct V_48 * * V_142 ,
const T_1 * V_7 )
{
int V_25 ;
* V_142 = F_41 ( V_14 ) ;
if ( ! * V_142 )
return - V_15 ;
V_25 = F_88 ( V_141 , V_57 , V_111 ,
V_50 , * V_142 , NULL , V_7 , 0 , 0 ) ;
if ( V_25 < 0 && V_25 != - V_76 ) {
F_86 ( * V_142 ) ;
return V_25 ;
}
return 0 ;
}
static int F_89 ( struct V_140 * V_141 ,
struct V_56 * V_57 , T_1 V_111 ,
T_1 V_50 , struct V_48 * * V_143 )
{
struct V_48 * V_144 ;
struct V_71 * V_72 = NULL ;
struct V_73 V_74 ;
int V_25 ;
V_144 = F_41 ( V_14 ) ;
if ( ! V_144 )
return - V_15 ;
* V_143 = F_41 ( V_14 ) ;
if ( ! * V_143 ) {
F_47 ( V_144 ) ;
return - V_15 ;
}
F_43 ( & V_74 ) ;
while ( 1 ) {
V_25 = F_88 ( V_141 , V_57 , V_111 ,
V_50 , V_144 , * V_143 , NULL , 0 , 0 ) ;
if ( V_25 < 0 && V_25 != - V_76 ) {
F_47 ( V_144 ) ;
F_47 ( * V_143 ) ;
return V_25 ;
}
V_72 = F_44 ( V_144 , & V_74 ) ;
if ( ! V_72 )
break;
V_111 = V_72 -> V_77 ;
F_90 () ;
}
F_47 ( V_144 ) ;
return 0 ;
}
int F_91 ( struct V_140 * V_141 ,
struct V_56 * V_57 , T_1 V_111 ,
T_1 V_50 , struct V_48 * * V_143 )
{
int V_25 ;
if ( ! V_141 )
F_92 ( & V_57 -> V_145 ) ;
V_25 = F_89 ( V_141 , V_57 , V_111 , V_50 , V_143 ) ;
if ( ! V_141 )
F_93 ( & V_57 -> V_145 ) ;
return V_25 ;
}
int F_94 ( struct V_140 * V_141 ,
struct V_56 * V_57 , T_1 V_67 ,
T_1 V_17 , T_1 V_111 )
{
struct V_48 * V_144 = NULL ;
struct V_48 * V_143 = NULL ;
struct V_73 V_74 ;
struct V_71 * V_72 ;
struct V_146 V_147 = {} ;
int V_25 = 0 ;
V_144 = F_41 ( V_14 ) ;
V_143 = F_41 ( V_14 ) ;
if ( ! V_144 || ! V_143 ) {
F_47 ( V_144 ) ;
F_47 ( V_143 ) ;
return - V_15 ;
}
if ( V_141 )
F_95 ( V_57 , & V_147 ) ;
else
F_92 ( & V_57 -> V_145 ) ;
F_43 ( & V_74 ) ;
while ( 1 ) {
V_25 = F_88 ( V_141 , V_57 , V_111 , V_147 . V_91 , V_144 ,
V_143 , NULL , V_67 , V_17 ) ;
if ( V_25 == V_75 ) {
V_25 = 1 ;
break;
}
if ( V_25 < 0 && V_25 != - V_76 )
break;
V_72 = F_44 ( V_144 , & V_74 ) ;
if ( ! V_72 )
break;
V_111 = V_72 -> V_77 ;
F_90 () ;
}
if ( V_141 )
F_96 ( V_57 , & V_147 ) ;
else
F_93 ( & V_57 -> V_145 ) ;
F_47 ( V_144 ) ;
F_47 ( V_143 ) ;
return V_25 ;
}
int F_97 ( T_1 V_17 , T_1 V_148 , struct V_44 * V_149 ,
struct V_46 * V_47 )
{
struct V_1 V_2 ;
return F_98 ( V_149 , V_47 , V_17 , V_148 ,
V_150 , & V_2 ) ;
}
static int F_99 ( T_1 V_17 , T_1 V_148 , struct V_44 * V_149 ,
struct V_46 * V_47 ,
struct V_1 * V_119 )
{
return F_98 ( V_149 , V_47 , V_17 , V_148 ,
V_151 , V_119 ) ;
}
int F_100 ( struct V_44 * V_45 , T_1 V_152 ,
T_1 V_153 , struct V_46 * V_47 ,
struct V_154 * * V_155 ,
T_1 * V_156 )
{
int V_25 , V_22 ;
struct V_1 V_2 ;
struct V_1 V_119 ;
struct V_154 * V_157 ;
struct V_3 * V_118 ;
unsigned long V_120 ;
V_2 . V_18 = V_152 ;
V_2 . type = V_158 ;
V_2 . V_10 = V_153 ;
V_25 = F_101 ( NULL , V_45 , & V_2 , V_47 , 0 , 0 ) ;
if ( V_25 < 0 )
return V_25 ;
while ( 1 ) {
V_118 = V_47 -> V_53 [ 0 ] ;
V_22 = V_47 -> V_55 [ 0 ] ;
if ( V_22 >= F_11 ( V_118 ) ) {
V_25 = F_102 ( V_45 , V_47 ) ;
if ( V_25 ) {
if ( V_25 >= 1 )
V_25 = - V_76 ;
break;
}
continue;
}
F_12 ( V_118 , & V_119 , V_22 ) ;
V_25 = - V_76 ;
if ( V_119 . V_18 != V_152 )
break;
if ( V_119 . type != V_158 )
break;
V_25 = 0 ;
V_120 = F_103 ( V_118 , V_47 -> V_55 [ 0 ] ) ;
V_157 = (struct V_154 * ) V_120 ;
* V_155 = V_157 ;
if ( V_156 )
* V_156 = V_119 . V_10 ;
break;
}
return V_25 ;
}
char * F_104 ( struct V_44 * V_149 , struct V_46 * V_47 ,
T_4 V_159 , unsigned long V_160 ,
struct V_3 * V_161 , T_1 V_36 ,
char * V_162 , T_4 V_163 )
{
int V_22 ;
T_1 V_164 ;
int V_25 ;
T_5 V_165 = ( ( T_5 ) V_163 ) - 1 ;
struct V_3 * V_4 = V_161 ;
struct V_1 V_119 ;
int V_166 = V_47 -> V_166 ;
struct V_167 * V_133 ;
if ( V_165 >= 0 )
V_162 [ V_165 ] = '\0' ;
V_47 -> V_166 = 1 ;
while ( 1 ) {
V_165 -= V_159 ;
if ( V_165 >= 0 )
F_105 ( V_4 , V_162 + V_165 ,
V_160 , V_159 ) ;
if ( V_4 != V_161 ) {
F_106 ( V_4 ) ;
F_55 ( V_4 ) ;
}
V_25 = F_99 ( V_36 , 0 , V_149 , V_47 , & V_119 ) ;
if ( V_25 > 0 )
V_25 = - V_76 ;
if ( V_25 )
break;
V_164 = V_119 . V_10 ;
if ( V_36 == V_164 )
break;
V_22 = V_47 -> V_55 [ 0 ] ;
V_4 = V_47 -> V_53 [ 0 ] ;
if ( V_4 != V_161 ) {
F_107 ( & V_4 -> V_168 ) ;
F_56 ( V_4 ) ;
F_108 ( V_4 , V_169 ) ;
}
F_39 ( V_47 ) ;
V_133 = F_13 ( V_4 , V_22 , struct V_167 ) ;
V_159 = F_109 ( V_4 , V_133 ) ;
V_160 = ( unsigned long ) ( V_133 + 1 ) ;
V_36 = V_164 ;
-- V_165 ;
if ( V_165 >= 0 )
V_162 [ V_165 ] = '/' ;
}
F_39 ( V_47 ) ;
V_47 -> V_166 = V_166 ;
if ( V_25 )
return F_110 ( V_25 ) ;
return V_162 + V_165 ;
}
int F_111 ( struct V_56 * V_57 , T_1 V_170 ,
struct V_46 * V_47 , struct V_1 * V_119 ,
T_1 * V_171 )
{
int V_25 ;
T_1 V_124 ;
T_1 V_163 = 0 ;
T_4 V_125 ;
struct V_3 * V_4 ;
struct V_122 * V_123 ;
struct V_1 V_2 ;
if ( F_112 ( V_57 , V_172 ) )
V_2 . type = V_130 ;
else
V_2 . type = V_126 ;
V_2 . V_18 = V_170 ;
V_2 . V_10 = ( T_1 ) - 1 ;
V_25 = F_101 ( NULL , V_57 -> V_138 , & V_2 , V_47 , 0 , 0 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_113 ( V_57 -> V_138 , V_47 , 0 ) ;
if ( V_25 ) {
if ( V_25 > 0 )
V_25 = - V_76 ;
return V_25 ;
}
F_12 ( V_47 -> V_53 [ 0 ] , V_119 , V_47 -> V_55 [ 0 ] ) ;
if ( V_119 -> type == V_130 )
V_163 = V_57 -> V_138 -> V_173 ;
else if ( V_119 -> type == V_126 )
V_163 = V_119 -> V_10 ;
if ( V_119 -> V_18 > V_170 ||
V_119 -> V_18 + V_163 <= V_170 ) {
F_37 ( L_4 , V_170 ) ;
return - V_76 ;
}
V_4 = V_47 -> V_53 [ 0 ] ;
V_125 = F_72 ( V_4 , V_47 -> V_55 [ 0 ] ) ;
F_52 ( V_125 < sizeof( * V_123 ) ) ;
V_123 = F_13 ( V_4 , V_47 -> V_55 [ 0 ] , struct V_122 ) ;
V_124 = F_73 ( V_4 , V_123 ) ;
F_37 ( L_5
L_6 ,
V_170 , V_170 - V_119 -> V_18 , V_119 -> V_18 ,
V_119 -> V_10 , V_124 , V_125 ) ;
F_38 ( ! V_171 ) ;
if ( V_171 ) {
if ( V_124 & V_127 )
* V_171 = V_127 ;
else if ( V_124 & V_131 )
* V_171 = V_131 ;
else
F_52 ( 1 ) ;
return 0 ;
}
return - V_84 ;
}
static int F_114 ( unsigned long * V_120 , struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_122 * V_123 , T_4 V_125 ,
struct V_132 * * V_174 ,
int * V_175 )
{
unsigned long V_121 ;
T_1 V_124 ;
struct V_128 * V_129 ;
if ( ! * V_120 ) {
V_124 = F_73 ( V_4 , V_123 ) ;
if ( V_124 & V_127 ) {
if ( V_2 -> type == V_130 ) {
* V_174 =
(struct V_132 * ) ( V_123 + 1 ) ;
} else {
F_38 ( V_2 -> type != V_126 ) ;
V_129 = (struct V_128 * ) ( V_123 + 1 ) ;
* V_174 =
(struct V_132 * ) ( V_129 + 1 ) ;
}
} else {
* V_174 = (struct V_132 * ) ( V_123 + 1 ) ;
}
* V_120 = ( unsigned long ) * V_174 ;
if ( ( unsigned long ) ( * V_120 ) >= ( unsigned long ) V_123 + V_125 )
return - V_76 ;
}
V_121 = ( unsigned long ) V_123 + V_125 ;
* V_174 = (struct V_132 * ) ( * V_120 ) ;
* V_175 = F_76 ( V_4 , * V_174 ) ;
* V_120 += F_83 ( * V_175 ) ;
F_38 ( * V_120 > V_121 ) ;
if ( * V_120 == V_121 )
return 1 ;
return 0 ;
}
int F_115 ( unsigned long * V_120 , struct V_3 * V_4 ,
struct V_1 * V_2 , struct V_122 * V_123 ,
T_4 V_125 , T_1 * V_176 , T_6 * V_177 )
{
int V_25 ;
int type ;
struct V_128 * V_129 ;
struct V_132 * V_178 ;
if ( * V_120 == ( unsigned long ) - 1 )
return 1 ;
while ( 1 ) {
V_25 = F_114 ( V_120 , V_4 , V_2 , V_123 , V_125 ,
& V_178 , & type ) ;
if ( V_25 < 0 )
return V_25 ;
if ( type == V_109 ||
type == V_113 )
break;
if ( V_25 == 1 )
return 1 ;
}
V_129 = (struct V_128 * ) ( V_123 + 1 ) ;
* V_176 = F_77 ( V_4 , V_178 ) ;
* V_177 = F_75 ( V_4 , V_129 ) ;
if ( V_25 == 1 )
* V_120 = ( unsigned long ) - 1 ;
return 0 ;
}
static int F_116 ( struct V_8 * V_42 ,
T_1 V_45 , T_1 V_179 ,
T_7 * V_180 , void * V_181 )
{
struct V_8 * V_9 ;
int V_25 = 0 ;
for ( V_9 = V_42 ; V_9 ; V_9 = V_9 -> V_16 ) {
F_37 ( L_7
L_8 , V_179 ,
V_9 -> V_17 , V_9 -> V_10 , V_45 ) ;
V_25 = V_180 ( V_9 -> V_17 , V_9 -> V_10 , V_45 , V_181 ) ;
if ( V_25 ) {
F_37 ( L_9 ,
V_179 , V_25 ) ;
break;
}
}
return V_25 ;
}
int F_117 ( struct V_56 * V_57 ,
T_1 V_179 , T_1 V_7 ,
int V_64 ,
T_7 * V_180 , void * V_181 )
{
int V_25 ;
struct V_140 * V_141 = NULL ;
struct V_48 * V_168 = NULL ;
struct V_48 * V_143 = NULL ;
struct V_71 * V_182 = NULL ;
struct V_71 * V_183 = NULL ;
struct V_146 V_184 = {} ;
struct V_73 V_185 ;
struct V_73 V_186 ;
F_37 ( L_10 ,
V_179 ) ;
if ( ! V_64 ) {
V_141 = F_118 ( V_57 -> V_138 ) ;
if ( F_31 ( V_141 ) )
return F_33 ( V_141 ) ;
F_95 ( V_57 , & V_184 ) ;
} else {
F_92 ( & V_57 -> V_145 ) ;
}
V_25 = F_87 ( V_141 , V_57 , V_179 ,
V_184 . V_91 , & V_168 ,
& V_7 ) ;
if ( V_25 )
goto V_63;
F_43 ( & V_185 ) ;
while ( ! V_25 && ( V_182 = F_44 ( V_168 , & V_185 ) ) ) {
V_25 = F_89 ( V_141 , V_57 , V_182 -> V_77 ,
V_184 . V_91 , & V_143 ) ;
if ( V_25 )
break;
F_43 ( & V_186 ) ;
while ( ! V_25 && ( V_183 = F_44 ( V_143 , & V_186 ) ) ) {
F_37 ( L_11
L_12 , V_183 -> V_77 , V_182 -> V_77 ,
V_182 -> V_79 ) ;
V_25 = F_116 ( (struct V_8 * )
( V_78 ) V_182 -> V_79 ,
V_183 -> V_77 ,
V_179 ,
V_180 , V_181 ) ;
}
F_47 ( V_143 ) ;
}
F_86 ( V_168 ) ;
V_63:
if ( ! V_64 ) {
F_96 ( V_57 , & V_184 ) ;
F_119 ( V_141 , V_57 -> V_138 ) ;
} else {
F_93 ( & V_57 -> V_145 ) ;
}
return V_25 ;
}
int F_120 ( T_1 V_170 , struct V_56 * V_57 ,
struct V_46 * V_47 ,
T_7 * V_180 , void * V_181 )
{
int V_25 ;
T_1 V_7 ;
T_1 V_124 = 0 ;
struct V_1 V_119 ;
int V_64 = V_47 -> V_64 ;
V_25 = F_111 ( V_57 , V_170 , V_47 , & V_119 , & V_124 ) ;
F_39 ( V_47 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_124 & V_127 )
return - V_187 ;
V_7 = V_170 - V_119 . V_18 ;
V_25 = F_117 ( V_57 , V_119 . V_18 ,
V_7 , V_64 ,
V_180 , V_181 ) ;
return V_25 ;
}
static int F_121 ( T_1 V_17 , struct V_44 * V_149 ,
struct V_46 * V_47 ,
T_8 * V_180 , void * V_181 )
{
int V_25 = 0 ;
int V_22 ;
T_4 V_188 ;
T_4 V_189 ;
T_4 V_159 ;
T_1 V_36 = 0 ;
int V_190 = 0 ;
struct V_3 * V_4 ;
struct V_191 * V_192 ;
struct V_167 * V_133 ;
struct V_1 V_119 ;
while ( ! V_25 ) {
V_25 = F_99 ( V_17 , V_36 ? V_36 + 1 : 0 , V_149 , V_47 ,
& V_119 ) ;
if ( V_25 < 0 )
break;
if ( V_25 ) {
V_25 = V_190 ? 0 : - V_76 ;
break;
}
++ V_190 ;
V_36 = V_119 . V_10 ;
V_22 = V_47 -> V_55 [ 0 ] ;
V_4 = F_122 ( V_47 -> V_53 [ 0 ] ) ;
if ( ! V_4 ) {
V_25 = - V_15 ;
break;
}
F_123 ( V_4 ) ;
F_56 ( V_4 ) ;
F_108 ( V_4 , V_169 ) ;
F_39 ( V_47 ) ;
V_192 = F_124 ( V_22 ) ;
V_133 = F_13 ( V_4 , V_22 , struct V_167 ) ;
for ( V_188 = 0 ; V_188 < F_125 ( V_4 , V_192 ) ; V_188 += V_189 ) {
V_159 = F_109 ( V_4 , V_133 ) ;
F_37 ( L_13
L_14 , V_188 , V_119 . V_18 ,
V_149 -> V_18 ) ;
V_25 = V_180 ( V_36 , V_159 ,
( unsigned long ) ( V_133 + 1 ) , V_4 , V_181 ) ;
if ( V_25 )
break;
V_189 = sizeof( * V_133 ) + V_159 ;
V_133 = (struct V_167 * ) ( ( char * ) V_133 + V_189 ) ;
}
F_106 ( V_4 ) ;
F_55 ( V_4 ) ;
}
F_39 ( V_47 ) ;
return V_25 ;
}
static int F_126 ( T_1 V_17 , struct V_44 * V_149 ,
struct V_46 * V_47 ,
T_8 * V_180 , void * V_181 )
{
int V_25 ;
int V_22 ;
T_1 V_10 = 0 ;
T_1 V_36 ;
int V_190 = 0 ;
struct V_3 * V_4 ;
struct V_154 * V_157 ;
struct V_3 * V_118 ;
T_4 V_125 ;
T_4 V_193 ;
unsigned long V_120 ;
while ( 1 ) {
V_25 = F_100 ( V_149 , V_17 , V_10 , V_47 , & V_157 ,
& V_10 ) ;
if ( V_25 < 0 )
break;
if ( V_25 ) {
V_25 = V_190 ? 0 : - V_76 ;
break;
}
++ V_190 ;
V_22 = V_47 -> V_55 [ 0 ] ;
V_4 = F_122 ( V_47 -> V_53 [ 0 ] ) ;
if ( ! V_4 ) {
V_25 = - V_15 ;
break;
}
F_123 ( V_4 ) ;
F_56 ( V_4 ) ;
F_108 ( V_4 , V_169 ) ;
F_39 ( V_47 ) ;
V_118 = V_47 -> V_53 [ 0 ] ;
V_125 = F_72 ( V_118 , V_22 ) ;
V_120 = F_103 ( V_118 , V_22 ) ;
V_193 = 0 ;
while ( V_193 < V_125 ) {
T_4 V_159 ;
V_157 = (struct V_154 * ) ( V_120 + V_193 ) ;
V_36 = F_127 ( V_4 , V_157 ) ;
V_159 = F_128 ( V_4 , V_157 ) ;
V_25 = V_180 ( V_36 , V_159 ,
( unsigned long ) & V_157 -> V_194 , V_4 , V_181 ) ;
if ( V_25 )
break;
V_193 += F_128 ( V_118 , V_157 ) ;
V_193 += sizeof( * V_157 ) ;
}
F_106 ( V_4 ) ;
F_55 ( V_4 ) ;
V_10 ++ ;
}
F_39 ( V_47 ) ;
return V_25 ;
}
static int F_129 ( T_1 V_17 , struct V_44 * V_149 ,
struct V_46 * V_47 , T_8 * V_180 ,
void * V_181 )
{
int V_25 ;
int V_195 = 0 ;
V_25 = F_121 ( V_17 , V_149 , V_47 , V_180 , V_181 ) ;
if ( ! V_25 )
++ V_195 ;
else if ( V_25 != - V_76 )
return V_25 ;
V_25 = F_126 ( V_17 , V_149 , V_47 , V_180 , V_181 ) ;
if ( V_25 == - V_76 && V_195 )
return 0 ;
return V_25 ;
}
static int F_130 ( T_1 V_17 , T_4 V_159 , unsigned long V_160 ,
struct V_3 * V_4 , void * V_181 )
{
struct V_196 * V_197 = V_181 ;
char * V_198 ;
char * V_199 ;
int V_200 = V_197 -> V_198 -> V_201 ;
const int V_202 = sizeof( char * ) ;
T_4 V_165 ;
V_165 = V_197 -> V_198 -> V_165 > V_202 ?
V_197 -> V_198 -> V_165 - V_202 : 0 ;
V_199 = ( char * ) V_197 -> V_198 -> V_77 + ( V_200 + 1 ) * V_202 ;
V_198 = F_104 ( V_197 -> V_149 , V_197 -> V_46 , V_159 ,
V_160 , V_4 , V_17 , V_199 , V_165 ) ;
if ( F_31 ( V_198 ) )
return F_33 ( V_198 ) ;
if ( V_198 > V_199 ) {
V_197 -> V_198 -> V_77 [ V_200 ] = ( T_1 ) ( unsigned long ) V_198 ;
++ V_197 -> V_198 -> V_201 ;
V_197 -> V_198 -> V_165 = V_198 - V_199 ;
} else {
++ V_197 -> V_198 -> V_203 ;
V_197 -> V_198 -> V_204 += V_199 - V_198 ;
V_197 -> V_198 -> V_165 = 0 ;
}
return 0 ;
}
int F_131 ( T_1 V_17 , struct V_196 * V_197 )
{
return F_129 ( V_17 , V_197 -> V_149 , V_197 -> V_46 ,
F_130 , V_197 ) ;
}
struct V_205 * F_132 ( T_4 V_206 )
{
struct V_205 * V_207 ;
T_9 V_208 ;
V_208 = F_133 ( T_9 , V_206 , sizeof( * V_207 ) ) ;
V_207 = F_134 ( V_208 ) ;
if ( ! V_207 )
return F_110 ( - V_15 ) ;
if ( V_206 >= sizeof( * V_207 ) ) {
V_207 -> V_165 = V_206 - sizeof( * V_207 ) ;
V_207 -> V_204 = 0 ;
} else {
V_207 -> V_204 = sizeof( * V_207 ) - V_206 ;
V_207 -> V_165 = 0 ;
}
V_207 -> V_201 = 0 ;
V_207 -> V_203 = 0 ;
return V_207 ;
}
struct V_196 * F_135 ( T_10 V_206 , struct V_44 * V_149 ,
struct V_46 * V_47 )
{
struct V_196 * V_209 ;
struct V_205 * V_198 ;
V_198 = F_132 ( V_206 ) ;
if ( F_31 ( V_198 ) )
return ( void * ) V_198 ;
V_209 = F_7 ( sizeof( * V_209 ) , V_14 ) ;
if ( ! V_209 ) {
F_9 ( V_198 ) ;
return F_110 ( - V_15 ) ;
}
V_209 -> V_46 = V_47 ;
V_209 -> V_198 = V_198 ;
V_209 -> V_149 = V_149 ;
return V_209 ;
}
void F_136 ( struct V_196 * V_197 )
{
if ( ! V_197 )
return;
F_137 ( V_197 -> V_198 ) ;
F_9 ( V_197 ) ;
}
