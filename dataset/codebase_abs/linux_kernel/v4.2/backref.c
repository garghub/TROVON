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
if ( V_47 -> V_55 [ 0 ] >= F_11 ( V_47 -> V_53 [ 0 ] ) ) {
if ( V_50 == ( T_1 ) - 1 )
V_25 = F_25 ( V_45 , V_47 ) ;
else
V_25 = F_26 ( V_45 , V_47 , V_50 ) ;
}
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
V_25 = F_27 ( V_49 , V_4 -> V_54 ,
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
if ( V_50 == ( T_1 ) - 1 )
V_25 = F_28 ( V_45 , V_47 ) ;
else
V_25 = F_29 ( V_45 , V_47 , V_50 ) ;
}
if ( V_25 > 0 )
V_25 = 0 ;
else if ( V_25 < 0 )
F_8 ( V_9 ) ;
return V_25 ;
}
static int F_30 ( struct V_56 * V_57 ,
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
V_60 = F_31 ( & V_57 -> V_62 ) ;
V_45 = F_32 ( V_57 , & V_58 ) ;
if ( F_33 ( V_45 ) ) {
F_34 ( & V_57 -> V_62 , V_60 ) ;
V_25 = F_35 ( V_45 ) ;
goto V_63;
}
if ( V_47 -> V_64 )
V_59 = F_36 ( V_45 -> V_65 ) ;
else if ( V_50 == ( T_1 ) - 1 )
V_59 = F_36 ( V_45 -> V_66 ) ;
else
V_59 = F_37 ( V_45 , V_50 ) ;
if ( V_59 + 1 == V_35 ) {
F_34 ( & V_57 -> V_62 , V_60 ) ;
goto V_63;
}
V_47 -> V_67 = V_35 ;
if ( V_50 == ( T_1 ) - 1 )
V_25 = F_38 ( NULL , V_45 , & V_39 -> V_41 , V_47 ,
0 , 0 ) ;
else
V_25 = F_39 ( V_45 , & V_39 -> V_41 , V_47 ,
V_50 ) ;
F_34 ( & V_57 -> V_62 , V_60 ) ;
F_40 ( L_2
L_3 ,
V_39 -> V_34 , V_35 , V_39 -> V_37 , V_25 ,
V_39 -> V_41 . V_18 , V_39 -> V_41 . type ,
V_39 -> V_41 . V_10 ) ;
if ( V_25 < 0 )
goto V_63;
V_4 = V_47 -> V_53 [ V_35 ] ;
while ( ! V_4 ) {
if ( F_41 ( ! V_35 ) ) {
V_25 = 1 ;
goto V_63;
}
V_35 -- ;
V_4 = V_47 -> V_53 [ V_35 ] ;
}
V_25 = F_23 ( V_45 , V_47 , V_49 , V_39 , V_35 , V_50 ,
V_7 , V_51 ) ;
V_63:
V_47 -> V_67 = 0 ;
F_42 ( V_47 ) ;
return V_25 ;
}
static int F_43 ( struct V_56 * V_57 ,
struct V_46 * V_47 , T_1 V_50 ,
struct V_32 * V_33 ,
const T_1 * V_7 , T_1 V_51 ,
T_1 V_68 )
{
int V_69 ;
int V_25 = 0 ;
struct V_29 * V_39 ;
struct V_29 * V_70 ;
struct V_29 * V_71 ;
struct V_48 * V_49 ;
struct V_72 * V_66 ;
struct V_73 V_74 ;
V_49 = F_44 ( V_14 ) ;
if ( ! V_49 )
return - V_15 ;
F_45 (ref, ref_safe, head, list) {
if ( V_39 -> V_36 )
continue;
if ( V_39 -> V_37 == 0 )
continue;
if ( V_68 && V_39 -> V_34 != V_68 ) {
V_25 = V_75 ;
goto V_63;
}
V_69 = F_30 ( V_57 , V_47 , V_50 , V_39 ,
V_49 , V_7 ,
V_51 ) ;
if ( V_69 == - V_76 ) {
continue;
} else if ( V_69 ) {
V_25 = V_69 ;
goto V_63;
}
F_46 ( & V_74 ) ;
V_66 = F_47 ( V_49 , & V_74 ) ;
V_39 -> V_36 = V_66 ? V_66 -> V_77 : 0 ;
V_39 -> V_42 = V_66 ?
(struct V_8 * ) ( V_78 ) V_66 -> V_79 : NULL ;
while ( ( V_66 = F_47 ( V_49 , & V_74 ) ) ) {
V_71 = F_21 ( V_28 ,
V_14 ) ;
if ( ! V_71 ) {
V_25 = - V_15 ;
goto V_63;
}
memcpy ( V_71 , V_39 , sizeof( * V_39 ) ) ;
V_71 -> V_36 = V_66 -> V_77 ;
V_71 -> V_42 = (struct V_8 * )
( V_78 ) V_66 -> V_79 ;
F_48 ( & V_71 -> V_43 , & V_39 -> V_43 ) ;
}
F_49 ( V_49 ) ;
}
V_63:
F_50 ( V_49 ) ;
return V_25 ;
}
static inline int F_51 ( struct V_29 * V_80 ,
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
static int F_52 ( struct V_56 * V_57 ,
struct V_32 * V_33 )
{
struct V_32 * V_82 ;
struct V_3 * V_4 ;
F_53 (pos, head) {
struct V_29 * V_39 ;
V_39 = F_54 ( V_82 , struct V_29 , V_43 ) ;
if ( V_39 -> V_36 )
continue;
if ( V_39 -> V_41 . type )
continue;
F_55 ( ! V_39 -> V_20 ) ;
V_4 = F_56 ( V_57 -> V_83 , V_39 -> V_20 ,
0 ) ;
if ( F_33 ( V_4 ) ) {
return F_35 ( V_4 ) ;
} else if ( ! F_57 ( V_4 ) ) {
F_58 ( V_4 ) ;
return - V_84 ;
}
F_59 ( V_4 ) ;
if ( F_36 ( V_4 ) == 0 )
F_12 ( V_4 , & V_39 -> V_41 , 0 ) ;
else
F_60 ( V_4 , & V_39 -> V_41 , 0 ) ;
F_61 ( V_4 ) ;
F_58 ( V_4 ) ;
}
return 0 ;
}
static void F_62 ( struct V_32 * V_33 , int V_85 )
{
struct V_32 * V_86 ;
F_53 (pos1, head) {
struct V_32 * V_87 ;
struct V_32 * V_88 ;
struct V_29 * V_80 ;
V_80 = F_54 ( V_86 , struct V_29 , V_43 ) ;
for ( V_88 = V_86 -> V_16 , V_87 = V_88 -> V_16 ; V_88 != V_33 ;
V_88 = V_87 , V_87 = V_88 -> V_16 ) {
struct V_29 * V_81 ;
struct V_29 * V_89 ;
struct V_8 * V_9 ;
V_81 = F_54 ( V_88 , struct V_29 , V_43 ) ;
if ( ! F_51 ( V_80 , V_81 ) )
continue;
if ( V_85 == 1 ) {
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
F_63 ( & V_81 -> V_43 ) ;
F_64 ( V_28 , V_81 ) ;
}
}
}
static int F_65 ( struct V_90 * V_33 , T_1 V_91 ,
struct V_32 * V_92 , T_1 * V_51 ,
T_1 V_17 )
{
struct V_93 * V_66 ;
struct V_94 * V_95 = V_33 -> V_95 ;
struct V_1 V_2 ;
struct V_1 V_96 = { 0 } ;
int V_97 ;
int V_25 = 0 ;
if ( V_95 && V_95 -> V_98 )
F_66 ( & V_96 , & V_95 -> V_2 ) ;
F_67 ( & V_33 -> V_99 ) ;
F_68 (node, &head->ref_list, list) {
if ( V_66 -> V_91 > V_91 )
continue;
switch ( V_66 -> V_100 ) {
case V_101 :
case V_102 :
F_41 ( 1 ) ;
continue;
case V_103 :
V_97 = 1 ;
break;
case V_104 :
V_97 = - 1 ;
break;
default:
F_55 ( 1 ) ;
}
* V_51 += ( V_66 -> V_105 * V_97 ) ;
switch ( V_66 -> type ) {
case V_106 : {
struct V_107 * V_39 ;
V_39 = F_69 ( V_66 ) ;
V_25 = F_20 ( V_92 , V_39 -> V_45 , & V_96 ,
V_39 -> V_35 + 1 , 0 , V_66 -> V_108 ,
V_66 -> V_105 * V_97 , V_109 ) ;
break;
}
case V_110 : {
struct V_107 * V_39 ;
V_39 = F_69 ( V_66 ) ;
V_25 = F_20 ( V_92 , V_39 -> V_45 , NULL ,
V_39 -> V_35 + 1 , V_39 -> V_36 ,
V_66 -> V_108 ,
V_66 -> V_105 * V_97 , V_109 ) ;
break;
}
case V_111 : {
struct V_112 * V_39 ;
V_39 = F_70 ( V_66 ) ;
V_2 . V_18 = V_39 -> V_18 ;
V_2 . type = V_26 ;
V_2 . V_10 = V_39 -> V_10 ;
if ( V_17 && V_39 -> V_18 != V_17 ) {
V_25 = V_75 ;
break;
}
V_25 = F_20 ( V_92 , V_39 -> V_45 , & V_2 , 0 , 0 ,
V_66 -> V_108 ,
V_66 -> V_105 * V_97 , V_109 ) ;
break;
}
case V_113 : {
struct V_112 * V_39 ;
V_39 = F_70 ( V_66 ) ;
V_2 . V_18 = V_39 -> V_18 ;
V_2 . type = V_26 ;
V_2 . V_10 = V_39 -> V_10 ;
V_25 = F_20 ( V_92 , V_39 -> V_45 , & V_2 , 0 ,
V_39 -> V_36 , V_66 -> V_108 ,
V_66 -> V_105 * V_97 , V_109 ) ;
break;
}
default:
F_41 ( 1 ) ;
}
if ( V_25 )
break;
}
F_71 ( & V_33 -> V_99 ) ;
return V_25 ;
}
static int F_72 ( struct V_56 * V_57 ,
struct V_46 * V_47 , T_1 V_108 ,
int * V_114 , struct V_32 * V_92 ,
T_1 * V_51 , T_1 V_17 )
{
int V_25 = 0 ;
int V_22 ;
struct V_3 * V_115 ;
struct V_1 V_2 ;
struct V_1 V_116 ;
unsigned long V_117 ;
unsigned long V_118 ;
struct V_119 * V_120 ;
T_1 V_121 ;
T_1 V_122 ;
V_115 = V_47 -> V_53 [ 0 ] ;
V_22 = V_47 -> V_55 [ 0 ] ;
V_122 = F_73 ( V_115 , V_22 ) ;
F_55 ( V_122 < sizeof( * V_120 ) ) ;
V_120 = F_13 ( V_115 , V_22 , struct V_119 ) ;
V_121 = F_74 ( V_115 , V_120 ) ;
* V_51 += F_75 ( V_115 , V_120 ) ;
F_12 ( V_115 , & V_116 , V_22 ) ;
V_117 = ( unsigned long ) ( V_120 + 1 ) ;
V_118 = ( unsigned long ) V_120 + V_122 ;
if ( V_116 . type == V_123 &&
V_121 & V_124 ) {
struct V_125 * V_126 ;
V_126 = (struct V_125 * ) V_117 ;
* V_114 = F_76 ( V_115 , V_126 ) ;
V_117 += sizeof( struct V_125 ) ;
F_55 ( V_117 > V_118 ) ;
} else if ( V_116 . type == V_127 ) {
* V_114 = V_116 . V_10 ;
} else {
F_55 ( ! ( V_121 & V_128 ) ) ;
}
while ( V_117 < V_118 ) {
struct V_129 * V_130 ;
T_1 V_10 ;
int type ;
V_130 = (struct V_129 * ) V_117 ;
type = F_77 ( V_115 , V_130 ) ;
V_10 = F_78 ( V_115 , V_130 ) ;
switch ( type ) {
case V_110 :
V_25 = F_20 ( V_92 , 0 , NULL ,
* V_114 + 1 , V_10 ,
V_108 , 1 , V_14 ) ;
break;
case V_113 : {
struct V_131 * V_132 ;
int V_37 ;
V_132 = (struct V_131 * ) ( V_130 + 1 ) ;
V_37 = F_79 ( V_115 , V_132 ) ;
V_25 = F_20 ( V_92 , 0 , NULL , 0 , V_10 ,
V_108 , V_37 , V_14 ) ;
break;
}
case V_106 :
V_25 = F_20 ( V_92 , V_10 , NULL ,
* V_114 + 1 , 0 ,
V_108 , 1 , V_14 ) ;
break;
case V_111 : {
struct V_133 * V_134 ;
int V_37 ;
T_1 V_45 ;
V_134 = (struct V_133 * ) ( & V_130 -> V_10 ) ;
V_37 = F_80 ( V_115 , V_134 ) ;
V_2 . V_18 = F_81 ( V_115 ,
V_134 ) ;
V_2 . type = V_26 ;
V_2 . V_10 = F_82 ( V_115 , V_134 ) ;
if ( V_17 && V_2 . V_18 != V_17 ) {
V_25 = V_75 ;
break;
}
V_45 = F_83 ( V_115 , V_134 ) ;
V_25 = F_20 ( V_92 , V_45 , & V_2 , 0 , 0 ,
V_108 , V_37 , V_14 ) ;
break;
}
default:
F_41 ( 1 ) ;
}
if ( V_25 )
return V_25 ;
V_117 += F_84 ( type ) ;
}
return 0 ;
}
static int F_85 ( struct V_56 * V_57 ,
struct V_46 * V_47 , T_1 V_108 ,
int V_114 , struct V_32 * V_92 , T_1 V_17 )
{
struct V_44 * V_135 = V_57 -> V_135 ;
int V_25 ;
int V_22 ;
struct V_3 * V_115 ;
struct V_1 V_2 ;
while ( 1 ) {
V_25 = F_28 ( V_135 , V_47 ) ;
if ( V_25 < 0 )
break;
if ( V_25 ) {
V_25 = 0 ;
break;
}
V_22 = V_47 -> V_55 [ 0 ] ;
V_115 = V_47 -> V_53 [ 0 ] ;
F_12 ( V_115 , & V_2 , V_22 ) ;
if ( V_2 . V_18 != V_108 )
break;
if ( V_2 . type < V_106 )
continue;
if ( V_2 . type > V_113 )
break;
switch ( V_2 . type ) {
case V_110 :
V_25 = F_20 ( V_92 , 0 , NULL ,
V_114 + 1 , V_2 . V_10 ,
V_108 , 1 , V_14 ) ;
break;
case V_113 : {
struct V_131 * V_132 ;
int V_37 ;
V_132 = F_13 ( V_115 , V_22 ,
struct V_131 ) ;
V_37 = F_79 ( V_115 , V_132 ) ;
V_25 = F_20 ( V_92 , 0 , NULL , 0 , V_2 . V_10 ,
V_108 , V_37 , V_14 ) ;
break;
}
case V_106 :
V_25 = F_20 ( V_92 , V_2 . V_10 , NULL ,
V_114 + 1 , 0 ,
V_108 , 1 , V_14 ) ;
break;
case V_111 : {
struct V_133 * V_134 ;
int V_37 ;
T_1 V_45 ;
V_134 = F_13 ( V_115 , V_22 ,
struct V_133 ) ;
V_37 = F_80 ( V_115 , V_134 ) ;
V_2 . V_18 = F_81 ( V_115 ,
V_134 ) ;
V_2 . type = V_26 ;
V_2 . V_10 = F_82 ( V_115 , V_134 ) ;
if ( V_17 && V_2 . V_18 != V_17 ) {
V_25 = V_75 ;
break;
}
V_45 = F_83 ( V_115 , V_134 ) ;
V_25 = F_20 ( V_92 , V_45 , & V_2 , 0 , 0 ,
V_108 , V_37 , V_14 ) ;
break;
}
default:
F_41 ( 1 ) ;
}
if ( V_25 )
return V_25 ;
}
return V_25 ;
}
static void F_86 ( struct V_48 * V_136 )
{
struct V_72 * V_66 = NULL ;
struct V_8 * V_9 ;
struct V_73 V_74 ;
F_46 ( & V_74 ) ;
while ( ( V_66 = F_47 ( V_136 , & V_74 ) ) ) {
if ( ! V_66 -> V_79 )
continue;
V_9 = (struct V_8 * ) ( V_78 ) V_66 -> V_79 ;
F_8 ( V_9 ) ;
V_66 -> V_79 = 0 ;
}
F_50 ( V_136 ) ;
}
static int F_87 ( struct V_137 * V_138 ,
struct V_56 * V_57 , T_1 V_108 ,
T_1 V_50 , struct V_48 * * V_139 ,
const T_1 * V_7 )
{
int V_25 ;
* V_139 = F_44 ( V_14 ) ;
if ( ! * V_139 )
return - V_15 ;
V_25 = F_88 ( V_138 , V_57 , V_108 ,
V_50 , * V_139 , NULL , V_7 , 0 , 0 ) ;
if ( V_25 < 0 && V_25 != - V_76 ) {
F_86 ( * V_139 ) ;
return V_25 ;
}
return 0 ;
}
static int F_89 ( struct V_137 * V_138 ,
struct V_56 * V_57 , T_1 V_108 ,
T_1 V_50 , struct V_48 * * V_140 )
{
struct V_48 * V_141 ;
struct V_72 * V_66 = NULL ;
struct V_73 V_74 ;
int V_25 ;
V_141 = F_44 ( V_14 ) ;
if ( ! V_141 )
return - V_15 ;
* V_140 = F_44 ( V_14 ) ;
if ( ! * V_140 ) {
F_50 ( V_141 ) ;
return - V_15 ;
}
F_46 ( & V_74 ) ;
while ( 1 ) {
V_25 = F_88 ( V_138 , V_57 , V_108 ,
V_50 , V_141 , * V_140 , NULL , 0 , 0 ) ;
if ( V_25 < 0 && V_25 != - V_76 ) {
F_50 ( V_141 ) ;
F_50 ( * V_140 ) ;
return V_25 ;
}
V_66 = F_47 ( V_141 , & V_74 ) ;
if ( ! V_66 )
break;
V_108 = V_66 -> V_77 ;
F_90 () ;
}
F_50 ( V_141 ) ;
return 0 ;
}
int F_91 ( struct V_137 * V_138 ,
struct V_56 * V_57 , T_1 V_108 ,
T_1 V_50 , struct V_48 * * V_140 )
{
int V_25 ;
if ( ! V_138 )
F_92 ( & V_57 -> V_142 ) ;
V_25 = F_89 ( V_138 , V_57 , V_108 , V_50 , V_140 ) ;
if ( ! V_138 )
F_93 ( & V_57 -> V_142 ) ;
return V_25 ;
}
int F_94 ( struct V_137 * V_138 ,
struct V_56 * V_57 , T_1 V_68 ,
T_1 V_17 , T_1 V_108 )
{
struct V_48 * V_141 = NULL ;
struct V_48 * V_140 = NULL ;
struct V_73 V_74 ;
struct V_72 * V_66 ;
struct V_143 V_144 = F_95 ( V_144 ) ;
int V_25 = 0 ;
V_141 = F_44 ( V_14 ) ;
V_140 = F_44 ( V_14 ) ;
if ( ! V_141 || ! V_140 ) {
F_50 ( V_141 ) ;
F_50 ( V_140 ) ;
return - V_15 ;
}
if ( V_138 )
F_96 ( V_57 , & V_144 ) ;
else
F_92 ( & V_57 -> V_142 ) ;
F_46 ( & V_74 ) ;
while ( 1 ) {
V_25 = F_88 ( V_138 , V_57 , V_108 , V_144 . V_91 , V_141 ,
V_140 , NULL , V_68 , V_17 ) ;
if ( V_25 == V_75 ) {
V_25 = 1 ;
break;
}
if ( V_25 < 0 && V_25 != - V_76 )
break;
V_25 = 0 ;
V_66 = F_47 ( V_141 , & V_74 ) ;
if ( ! V_66 )
break;
V_108 = V_66 -> V_77 ;
F_90 () ;
}
if ( V_138 )
F_97 ( V_57 , & V_144 ) ;
else
F_93 ( & V_57 -> V_142 ) ;
F_50 ( V_141 ) ;
F_50 ( V_140 ) ;
return V_25 ;
}
int F_98 ( struct V_44 * V_45 , T_1 V_145 ,
T_1 V_146 , struct V_46 * V_47 ,
struct V_147 * * V_148 ,
T_1 * V_149 )
{
int V_25 , V_22 ;
struct V_1 V_2 ;
struct V_1 V_116 ;
struct V_147 * V_150 ;
struct V_3 * V_115 ;
unsigned long V_117 ;
V_2 . V_18 = V_145 ;
V_2 . type = V_151 ;
V_2 . V_10 = V_146 ;
V_25 = F_38 ( NULL , V_45 , & V_2 , V_47 , 0 , 0 ) ;
if ( V_25 < 0 )
return V_25 ;
while ( 1 ) {
V_115 = V_47 -> V_53 [ 0 ] ;
V_22 = V_47 -> V_55 [ 0 ] ;
if ( V_22 >= F_11 ( V_115 ) ) {
V_25 = F_25 ( V_45 , V_47 ) ;
if ( V_25 ) {
if ( V_25 >= 1 )
V_25 = - V_76 ;
break;
}
continue;
}
F_12 ( V_115 , & V_116 , V_22 ) ;
V_25 = - V_76 ;
if ( V_116 . V_18 != V_145 )
break;
if ( V_116 . type != V_151 )
break;
V_25 = 0 ;
V_117 = F_99 ( V_115 , V_47 -> V_55 [ 0 ] ) ;
V_150 = (struct V_147 * ) V_117 ;
* V_148 = V_150 ;
if ( V_149 )
* V_149 = V_116 . V_10 ;
break;
}
return V_25 ;
}
char * F_100 ( struct V_44 * V_152 , struct V_46 * V_47 ,
T_4 V_153 , unsigned long V_154 ,
struct V_3 * V_155 , T_1 V_36 ,
char * V_156 , T_4 V_157 )
{
int V_22 ;
T_1 V_158 ;
int V_25 ;
T_5 V_159 = ( ( T_5 ) V_157 ) - 1 ;
struct V_3 * V_4 = V_155 ;
struct V_1 V_116 ;
int V_160 = V_47 -> V_160 ;
struct V_161 * V_130 ;
if ( V_159 >= 0 )
V_156 [ V_159 ] = '\0' ;
V_47 -> V_160 = 1 ;
while ( 1 ) {
V_159 -= V_153 ;
if ( V_159 >= 0 )
F_101 ( V_4 , V_156 + V_159 ,
V_154 , V_153 ) ;
if ( V_4 != V_155 ) {
F_102 ( V_4 ) ;
F_58 ( V_4 ) ;
}
V_25 = F_103 ( V_152 , V_47 , V_36 , 0 ,
V_162 , & V_116 ) ;
if ( V_25 > 0 )
V_25 = - V_76 ;
if ( V_25 )
break;
V_158 = V_116 . V_10 ;
if ( V_36 == V_158 )
break;
V_22 = V_47 -> V_55 [ 0 ] ;
V_4 = V_47 -> V_53 [ 0 ] ;
if ( V_4 != V_155 ) {
F_104 ( & V_4 -> V_163 ) ;
F_59 ( V_4 ) ;
F_105 ( V_4 , V_164 ) ;
}
F_42 ( V_47 ) ;
V_130 = F_13 ( V_4 , V_22 , struct V_161 ) ;
V_153 = F_106 ( V_4 , V_130 ) ;
V_154 = ( unsigned long ) ( V_130 + 1 ) ;
V_36 = V_158 ;
-- V_159 ;
if ( V_159 >= 0 )
V_156 [ V_159 ] = '/' ;
}
F_42 ( V_47 ) ;
V_47 -> V_160 = V_160 ;
if ( V_25 )
return F_107 ( V_25 ) ;
return V_156 + V_159 ;
}
int F_108 ( struct V_56 * V_57 , T_1 V_165 ,
struct V_46 * V_47 , struct V_1 * V_116 ,
T_1 * V_166 )
{
int V_25 ;
T_1 V_121 ;
T_1 V_157 = 0 ;
T_4 V_122 ;
struct V_3 * V_4 ;
struct V_119 * V_120 ;
struct V_1 V_2 ;
if ( F_109 ( V_57 , V_167 ) )
V_2 . type = V_127 ;
else
V_2 . type = V_123 ;
V_2 . V_18 = V_165 ;
V_2 . V_10 = ( T_1 ) - 1 ;
V_25 = F_38 ( NULL , V_57 -> V_135 , & V_2 , V_47 , 0 , 0 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_110 ( V_57 -> V_135 , V_47 , 0 ) ;
if ( V_25 ) {
if ( V_25 > 0 )
V_25 = - V_76 ;
return V_25 ;
}
F_12 ( V_47 -> V_53 [ 0 ] , V_116 , V_47 -> V_55 [ 0 ] ) ;
if ( V_116 -> type == V_127 )
V_157 = V_57 -> V_135 -> V_168 ;
else if ( V_116 -> type == V_123 )
V_157 = V_116 -> V_10 ;
if ( V_116 -> V_18 > V_165 ||
V_116 -> V_18 + V_157 <= V_165 ) {
F_40 ( L_4 , V_165 ) ;
return - V_76 ;
}
V_4 = V_47 -> V_53 [ 0 ] ;
V_122 = F_73 ( V_4 , V_47 -> V_55 [ 0 ] ) ;
F_55 ( V_122 < sizeof( * V_120 ) ) ;
V_120 = F_13 ( V_4 , V_47 -> V_55 [ 0 ] , struct V_119 ) ;
V_121 = F_74 ( V_4 , V_120 ) ;
F_40 ( L_5
L_6 ,
V_165 , V_165 - V_116 -> V_18 , V_116 -> V_18 ,
V_116 -> V_10 , V_121 , V_122 ) ;
F_41 ( ! V_166 ) ;
if ( V_166 ) {
if ( V_121 & V_124 )
* V_166 = V_124 ;
else if ( V_121 & V_128 )
* V_166 = V_128 ;
else
F_55 ( 1 ) ;
return 0 ;
}
return - V_84 ;
}
static int F_111 ( unsigned long * V_117 , struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_119 * V_120 , T_4 V_122 ,
struct V_129 * * V_169 ,
int * V_170 )
{
unsigned long V_118 ;
T_1 V_121 ;
struct V_125 * V_126 ;
if ( ! * V_117 ) {
V_121 = F_74 ( V_4 , V_120 ) ;
if ( V_121 & V_124 ) {
if ( V_2 -> type == V_127 ) {
* V_169 =
(struct V_129 * ) ( V_120 + 1 ) ;
} else {
F_41 ( V_2 -> type != V_123 ) ;
V_126 = (struct V_125 * ) ( V_120 + 1 ) ;
* V_169 =
(struct V_129 * ) ( V_126 + 1 ) ;
}
} else {
* V_169 = (struct V_129 * ) ( V_120 + 1 ) ;
}
* V_117 = ( unsigned long ) * V_169 ;
if ( ( unsigned long ) ( * V_117 ) >= ( unsigned long ) V_120 + V_122 )
return - V_76 ;
}
V_118 = ( unsigned long ) V_120 + V_122 ;
* V_169 = (struct V_129 * ) ( * V_117 ) ;
* V_170 = F_77 ( V_4 , * V_169 ) ;
* V_117 += F_84 ( * V_170 ) ;
F_41 ( * V_117 > V_118 ) ;
if ( * V_117 == V_118 )
return 1 ;
return 0 ;
}
int F_112 ( unsigned long * V_117 , struct V_3 * V_4 ,
struct V_1 * V_2 , struct V_119 * V_120 ,
T_4 V_122 , T_1 * V_171 , T_6 * V_172 )
{
int V_25 ;
int type ;
struct V_129 * V_173 ;
if ( * V_117 == ( unsigned long ) - 1 )
return 1 ;
while ( 1 ) {
V_25 = F_111 ( V_117 , V_4 , V_2 , V_120 , V_122 ,
& V_173 , & type ) ;
if ( V_25 < 0 )
return V_25 ;
if ( type == V_106 ||
type == V_110 )
break;
if ( V_25 == 1 )
return 1 ;
}
* V_171 = F_78 ( V_4 , V_173 ) ;
if ( V_2 -> type == V_123 ) {
struct V_125 * V_126 ;
V_126 = (struct V_125 * ) ( V_120 + 1 ) ;
* V_172 = F_76 ( V_4 , V_126 ) ;
} else {
ASSERT ( V_2 -> type == V_127 ) ;
* V_172 = ( T_6 ) V_2 -> V_10 ;
}
if ( V_25 == 1 )
* V_117 = ( unsigned long ) - 1 ;
return 0 ;
}
static int F_113 ( struct V_8 * V_42 ,
T_1 V_45 , T_1 V_174 ,
T_7 * V_175 , void * V_176 )
{
struct V_8 * V_9 ;
int V_25 = 0 ;
for ( V_9 = V_42 ; V_9 ; V_9 = V_9 -> V_16 ) {
F_40 ( L_7
L_8 , V_174 ,
V_9 -> V_17 , V_9 -> V_10 , V_45 ) ;
V_25 = V_175 ( V_9 -> V_17 , V_9 -> V_10 , V_45 , V_176 ) ;
if ( V_25 ) {
F_40 ( L_9 ,
V_174 , V_25 ) ;
break;
}
}
return V_25 ;
}
int F_114 ( struct V_56 * V_57 ,
T_1 V_174 , T_1 V_7 ,
int V_64 ,
T_7 * V_175 , void * V_176 )
{
int V_25 ;
struct V_137 * V_138 = NULL ;
struct V_48 * V_163 = NULL ;
struct V_48 * V_140 = NULL ;
struct V_72 * V_177 = NULL ;
struct V_72 * V_178 = NULL ;
struct V_143 V_179 = F_95 ( V_179 ) ;
struct V_73 V_180 ;
struct V_73 V_181 ;
F_40 ( L_10 ,
V_174 ) ;
if ( ! V_64 ) {
V_138 = F_115 ( V_57 -> V_135 ) ;
if ( F_33 ( V_138 ) )
return F_35 ( V_138 ) ;
F_96 ( V_57 , & V_179 ) ;
} else {
F_92 ( & V_57 -> V_142 ) ;
}
V_25 = F_87 ( V_138 , V_57 , V_174 ,
V_179 . V_91 , & V_163 ,
& V_7 ) ;
if ( V_25 )
goto V_63;
F_46 ( & V_180 ) ;
while ( ! V_25 && ( V_177 = F_47 ( V_163 , & V_180 ) ) ) {
V_25 = F_89 ( V_138 , V_57 , V_177 -> V_77 ,
V_179 . V_91 , & V_140 ) ;
if ( V_25 )
break;
F_46 ( & V_181 ) ;
while ( ! V_25 && ( V_178 = F_47 ( V_140 , & V_181 ) ) ) {
F_40 ( L_11
L_12 , V_178 -> V_77 , V_177 -> V_77 ,
V_177 -> V_79 ) ;
V_25 = F_113 ( (struct V_8 * )
( V_78 ) V_177 -> V_79 ,
V_178 -> V_77 ,
V_174 ,
V_175 , V_176 ) ;
}
F_50 ( V_140 ) ;
}
F_86 ( V_163 ) ;
V_63:
if ( ! V_64 ) {
F_97 ( V_57 , & V_179 ) ;
F_116 ( V_138 , V_57 -> V_135 ) ;
} else {
F_93 ( & V_57 -> V_142 ) ;
}
return V_25 ;
}
int F_117 ( T_1 V_165 , struct V_56 * V_57 ,
struct V_46 * V_47 ,
T_7 * V_175 , void * V_176 )
{
int V_25 ;
T_1 V_7 ;
T_1 V_121 = 0 ;
struct V_1 V_116 ;
int V_64 = V_47 -> V_64 ;
V_25 = F_108 ( V_57 , V_165 , V_47 , & V_116 , & V_121 ) ;
F_42 ( V_47 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_121 & V_124 )
return - V_182 ;
V_7 = V_165 - V_116 . V_18 ;
V_25 = F_114 ( V_57 , V_116 . V_18 ,
V_7 , V_64 ,
V_175 , V_176 ) ;
return V_25 ;
}
static int F_118 ( T_1 V_17 , struct V_44 * V_152 ,
struct V_46 * V_47 ,
T_8 * V_175 , void * V_176 )
{
int V_25 = 0 ;
int V_22 ;
T_4 V_183 ;
T_4 V_184 ;
T_4 V_153 ;
T_1 V_36 = 0 ;
int V_185 = 0 ;
struct V_3 * V_4 ;
struct V_186 * V_187 ;
struct V_161 * V_130 ;
struct V_1 V_116 ;
while ( ! V_25 ) {
V_25 = F_103 ( V_152 , V_47 , V_17 ,
V_36 ? V_36 + 1 : 0 , V_162 ,
& V_116 ) ;
if ( V_25 < 0 )
break;
if ( V_25 ) {
V_25 = V_185 ? 0 : - V_76 ;
break;
}
++ V_185 ;
V_36 = V_116 . V_10 ;
V_22 = V_47 -> V_55 [ 0 ] ;
V_4 = F_119 ( V_47 -> V_53 [ 0 ] ) ;
if ( ! V_4 ) {
V_25 = - V_15 ;
break;
}
F_120 ( V_4 ) ;
F_59 ( V_4 ) ;
F_105 ( V_4 , V_164 ) ;
F_42 ( V_47 ) ;
V_187 = F_121 ( V_22 ) ;
V_130 = F_13 ( V_4 , V_22 , struct V_161 ) ;
for ( V_183 = 0 ; V_183 < F_122 ( V_4 , V_187 ) ; V_183 += V_184 ) {
V_153 = F_106 ( V_4 , V_130 ) ;
F_40 ( L_13
L_14 , V_183 , V_116 . V_18 ,
V_152 -> V_18 ) ;
V_25 = V_175 ( V_36 , V_153 ,
( unsigned long ) ( V_130 + 1 ) , V_4 , V_176 ) ;
if ( V_25 )
break;
V_184 = sizeof( * V_130 ) + V_153 ;
V_130 = (struct V_161 * ) ( ( char * ) V_130 + V_184 ) ;
}
F_102 ( V_4 ) ;
F_58 ( V_4 ) ;
}
F_42 ( V_47 ) ;
return V_25 ;
}
static int F_123 ( T_1 V_17 , struct V_44 * V_152 ,
struct V_46 * V_47 ,
T_8 * V_175 , void * V_176 )
{
int V_25 ;
int V_22 ;
T_1 V_10 = 0 ;
T_1 V_36 ;
int V_185 = 0 ;
struct V_3 * V_4 ;
struct V_147 * V_150 ;
struct V_3 * V_115 ;
T_4 V_122 ;
T_4 V_188 ;
unsigned long V_117 ;
while ( 1 ) {
V_25 = F_98 ( V_152 , V_17 , V_10 , V_47 , & V_150 ,
& V_10 ) ;
if ( V_25 < 0 )
break;
if ( V_25 ) {
V_25 = V_185 ? 0 : - V_76 ;
break;
}
++ V_185 ;
V_22 = V_47 -> V_55 [ 0 ] ;
V_4 = F_119 ( V_47 -> V_53 [ 0 ] ) ;
if ( ! V_4 ) {
V_25 = - V_15 ;
break;
}
F_120 ( V_4 ) ;
F_59 ( V_4 ) ;
F_105 ( V_4 , V_164 ) ;
F_42 ( V_47 ) ;
V_115 = V_47 -> V_53 [ 0 ] ;
V_122 = F_73 ( V_115 , V_22 ) ;
V_117 = F_99 ( V_115 , V_22 ) ;
V_188 = 0 ;
while ( V_188 < V_122 ) {
T_4 V_153 ;
V_150 = (struct V_147 * ) ( V_117 + V_188 ) ;
V_36 = F_124 ( V_4 , V_150 ) ;
V_153 = F_125 ( V_4 , V_150 ) ;
V_25 = V_175 ( V_36 , V_153 ,
( unsigned long ) & V_150 -> V_189 , V_4 , V_176 ) ;
if ( V_25 )
break;
V_188 += F_125 ( V_115 , V_150 ) ;
V_188 += sizeof( * V_150 ) ;
}
F_102 ( V_4 ) ;
F_58 ( V_4 ) ;
V_10 ++ ;
}
F_42 ( V_47 ) ;
return V_25 ;
}
static int F_126 ( T_1 V_17 , struct V_44 * V_152 ,
struct V_46 * V_47 , T_8 * V_175 ,
void * V_176 )
{
int V_25 ;
int V_190 = 0 ;
V_25 = F_118 ( V_17 , V_152 , V_47 , V_175 , V_176 ) ;
if ( ! V_25 )
++ V_190 ;
else if ( V_25 != - V_76 )
return V_25 ;
V_25 = F_123 ( V_17 , V_152 , V_47 , V_175 , V_176 ) ;
if ( V_25 == - V_76 && V_190 )
return 0 ;
return V_25 ;
}
static int F_127 ( T_1 V_17 , T_4 V_153 , unsigned long V_154 ,
struct V_3 * V_4 , void * V_176 )
{
struct V_191 * V_192 = V_176 ;
char * V_193 ;
char * V_194 ;
int V_195 = V_192 -> V_193 -> V_196 ;
const int V_197 = sizeof( char * ) ;
T_4 V_159 ;
V_159 = V_192 -> V_193 -> V_159 > V_197 ?
V_192 -> V_193 -> V_159 - V_197 : 0 ;
V_194 = ( char * ) V_192 -> V_193 -> V_77 + ( V_195 + 1 ) * V_197 ;
V_193 = F_100 ( V_192 -> V_152 , V_192 -> V_46 , V_153 ,
V_154 , V_4 , V_17 , V_194 , V_159 ) ;
if ( F_33 ( V_193 ) )
return F_35 ( V_193 ) ;
if ( V_193 > V_194 ) {
V_192 -> V_193 -> V_77 [ V_195 ] = ( T_1 ) ( unsigned long ) V_193 ;
++ V_192 -> V_193 -> V_196 ;
V_192 -> V_193 -> V_159 = V_193 - V_194 ;
} else {
++ V_192 -> V_193 -> V_198 ;
V_192 -> V_193 -> V_199 += V_194 - V_193 ;
V_192 -> V_193 -> V_159 = 0 ;
}
return 0 ;
}
int F_128 ( T_1 V_17 , struct V_191 * V_192 )
{
return F_126 ( V_17 , V_192 -> V_152 , V_192 -> V_46 ,
F_127 , V_192 ) ;
}
struct V_200 * F_129 ( T_4 V_201 )
{
struct V_200 * V_202 ;
T_9 V_203 ;
V_203 = F_130 ( T_9 , V_201 , sizeof( * V_202 ) ) ;
V_202 = F_131 ( V_203 ) ;
if ( ! V_202 )
return F_107 ( - V_15 ) ;
if ( V_201 >= sizeof( * V_202 ) ) {
V_202 -> V_159 = V_201 - sizeof( * V_202 ) ;
V_202 -> V_199 = 0 ;
} else {
V_202 -> V_199 = sizeof( * V_202 ) - V_201 ;
V_202 -> V_159 = 0 ;
}
V_202 -> V_196 = 0 ;
V_202 -> V_198 = 0 ;
return V_202 ;
}
struct V_191 * F_132 ( T_10 V_201 , struct V_44 * V_152 ,
struct V_46 * V_47 )
{
struct V_191 * V_204 ;
struct V_200 * V_193 ;
V_193 = F_129 ( V_201 ) ;
if ( F_33 ( V_193 ) )
return ( void * ) V_193 ;
V_204 = F_7 ( sizeof( * V_204 ) , V_14 ) ;
if ( ! V_204 ) {
F_9 ( V_193 ) ;
return F_107 ( - V_15 ) ;
}
V_204 -> V_46 = V_47 ;
V_204 -> V_193 = V_193 ;
V_204 -> V_152 = V_152 ;
return V_204 ;
}
void F_133 ( struct V_191 * V_192 )
{
if ( ! V_192 )
return;
F_134 ( V_192 -> V_193 ) ;
F_9 ( V_192 ) ;
}
