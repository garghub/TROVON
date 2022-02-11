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
if ( V_2 ) {
V_39 -> V_41 = * V_2 ;
if ( V_39 -> V_41 . type == V_26 &&
V_39 -> V_41 . V_10 >= V_42 )
V_39 -> V_41 . V_10 = 0 ;
} else {
memset ( & V_39 -> V_41 , 0 , sizeof( V_39 -> V_41 ) ) ;
}
V_39 -> V_43 = NULL ;
V_39 -> V_35 = V_35 ;
V_39 -> V_37 = V_37 ;
V_39 -> V_36 = V_36 ;
V_39 -> V_20 = V_20 ;
F_22 ( & V_39 -> V_44 , V_33 ) ;
return 0 ;
}
static int F_23 ( struct V_45 * V_46 , struct V_47 * V_48 ,
struct V_49 * V_50 , struct V_29 * V_39 ,
int V_35 , T_1 V_51 , const T_1 * V_7 ,
T_1 V_52 )
{
int V_25 = 0 ;
int V_22 ;
struct V_3 * V_4 ;
struct V_1 V_2 ;
struct V_1 * V_41 = & V_39 -> V_41 ;
struct V_5 * V_6 ;
struct V_8 * V_9 = NULL , * V_53 = NULL ;
T_1 V_21 ;
T_1 V_20 = V_39 -> V_20 ;
T_1 V_37 = 0 ;
if ( V_35 != 0 ) {
V_4 = V_48 -> V_54 [ V_35 ] ;
V_25 = F_24 ( V_50 , V_4 -> V_55 , 0 , V_14 ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
if ( V_48 -> V_56 [ 0 ] >= F_11 ( V_48 -> V_54 [ 0 ] ) ) {
if ( V_51 == ( T_1 ) - 1 )
V_25 = F_25 ( V_46 , V_48 ) ;
else
V_25 = F_26 ( V_46 , V_48 , V_51 ) ;
}
while ( ! V_25 && V_37 < V_52 ) {
V_4 = V_48 -> V_54 [ 0 ] ;
V_22 = V_48 -> V_56 [ 0 ] ;
F_12 ( V_4 , & V_2 , V_22 ) ;
if ( V_2 . V_18 != V_41 -> V_18 ||
V_2 . type != V_26 )
break;
V_6 = F_13 ( V_4 , V_22 , struct V_5 ) ;
V_21 = F_15 ( V_4 , V_6 ) ;
if ( V_21 == V_20 ) {
V_9 = NULL ;
V_53 = NULL ;
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
V_25 = F_27 ( V_50 , V_4 -> V_55 ,
V_9 , ( void * * ) & V_53 , V_14 ) ;
if ( V_25 < 0 )
break;
if ( ! V_25 && V_7 ) {
while ( V_53 -> V_16 )
V_53 = V_53 -> V_16 ;
V_53 -> V_16 = V_9 ;
}
V_9 = NULL ;
}
V_16:
if ( V_51 == ( T_1 ) - 1 )
V_25 = F_28 ( V_46 , V_48 ) ;
else
V_25 = F_29 ( V_46 , V_48 , V_51 ) ;
}
if ( V_25 > 0 )
V_25 = 0 ;
else if ( V_25 < 0 )
F_8 ( V_9 ) ;
return V_25 ;
}
static int F_30 ( struct V_57 * V_58 ,
struct V_47 * V_48 , T_1 V_51 ,
struct V_29 * V_39 ,
struct V_49 * V_50 ,
const T_1 * V_7 , T_1 V_52 )
{
struct V_45 * V_46 ;
struct V_1 V_59 ;
struct V_3 * V_4 ;
int V_25 = 0 ;
int V_60 ;
int V_35 = V_39 -> V_35 ;
int V_61 ;
V_59 . V_18 = V_39 -> V_34 ;
V_59 . type = V_62 ;
V_59 . V_10 = ( T_1 ) - 1 ;
V_61 = F_31 ( & V_58 -> V_63 ) ;
V_46 = F_32 ( V_58 , & V_59 , false ) ;
if ( F_33 ( V_46 ) ) {
F_34 ( & V_58 -> V_63 , V_61 ) ;
V_25 = F_35 ( V_46 ) ;
goto V_64;
}
if ( F_36 ( V_46 ) ) {
F_34 ( & V_58 -> V_63 , V_61 ) ;
V_25 = - V_65 ;
goto V_64;
}
if ( V_48 -> V_66 )
V_60 = F_37 ( V_46 -> V_67 ) ;
else if ( V_51 == ( T_1 ) - 1 )
V_60 = F_37 ( V_46 -> V_68 ) ;
else
V_60 = F_38 ( V_46 , V_51 ) ;
if ( V_60 + 1 == V_35 ) {
F_34 ( & V_58 -> V_63 , V_61 ) ;
goto V_64;
}
V_48 -> V_69 = V_35 ;
if ( V_51 == ( T_1 ) - 1 )
V_25 = F_39 ( NULL , V_46 , & V_39 -> V_41 , V_48 ,
0 , 0 ) ;
else
V_25 = F_40 ( V_46 , & V_39 -> V_41 , V_48 ,
V_51 ) ;
F_34 ( & V_58 -> V_63 , V_61 ) ;
F_41 ( L_2
L_3 ,
V_39 -> V_34 , V_35 , V_39 -> V_37 , V_25 ,
V_39 -> V_41 . V_18 , V_39 -> V_41 . type ,
V_39 -> V_41 . V_10 ) ;
if ( V_25 < 0 )
goto V_64;
V_4 = V_48 -> V_54 [ V_35 ] ;
while ( ! V_4 ) {
if ( F_42 ( ! V_35 ) ) {
V_25 = 1 ;
goto V_64;
}
V_35 -- ;
V_4 = V_48 -> V_54 [ V_35 ] ;
}
V_25 = F_23 ( V_46 , V_48 , V_50 , V_39 , V_35 , V_51 ,
V_7 , V_52 ) ;
V_64:
V_48 -> V_69 = 0 ;
F_43 ( V_48 ) ;
return V_25 ;
}
static int F_44 ( struct V_57 * V_58 ,
struct V_47 * V_48 , T_1 V_51 ,
struct V_32 * V_33 ,
const T_1 * V_7 , T_1 V_52 ,
T_1 V_70 )
{
int V_71 ;
int V_25 = 0 ;
struct V_29 * V_39 ;
struct V_29 * V_72 ;
struct V_29 * V_73 ;
struct V_49 * V_50 ;
struct V_74 * V_68 ;
struct V_75 V_76 ;
V_50 = F_45 ( V_14 ) ;
if ( ! V_50 )
return - V_15 ;
F_46 (ref, ref_safe, head, list) {
if ( V_39 -> V_36 )
continue;
if ( V_39 -> V_37 == 0 )
continue;
if ( V_70 && V_39 -> V_34 != V_70 ) {
V_25 = V_77 ;
goto V_64;
}
V_71 = F_30 ( V_58 , V_48 , V_51 , V_39 ,
V_50 , V_7 ,
V_52 ) ;
if ( V_71 == - V_65 ) {
continue;
} else if ( V_71 ) {
V_25 = V_71 ;
goto V_64;
}
F_47 ( & V_76 ) ;
V_68 = F_48 ( V_50 , & V_76 ) ;
V_39 -> V_36 = V_68 ? V_68 -> V_78 : 0 ;
V_39 -> V_43 = V_68 ?
(struct V_8 * ) ( V_79 ) V_68 -> V_80 : NULL ;
while ( ( V_68 = F_48 ( V_50 , & V_76 ) ) ) {
V_73 = F_21 ( V_28 ,
V_14 ) ;
if ( ! V_73 ) {
V_25 = - V_15 ;
goto V_64;
}
memcpy ( V_73 , V_39 , sizeof( * V_39 ) ) ;
V_73 -> V_36 = V_68 -> V_78 ;
V_73 -> V_43 = (struct V_8 * )
( V_79 ) V_68 -> V_80 ;
F_49 ( & V_73 -> V_44 , & V_39 -> V_44 ) ;
}
F_50 ( V_50 ) ;
}
V_64:
F_51 ( V_50 ) ;
return V_25 ;
}
static inline int F_52 ( struct V_29 * V_81 ,
struct V_29 * V_82 )
{
if ( V_81 -> V_35 != V_82 -> V_35 )
return 0 ;
if ( V_81 -> V_34 != V_82 -> V_34 )
return 0 ;
if ( V_81 -> V_41 . type != V_82 -> V_41 . type )
return 0 ;
if ( V_81 -> V_41 . V_18 != V_82 -> V_41 . V_18 )
return 0 ;
if ( V_81 -> V_41 . V_10 != V_82 -> V_41 . V_10 )
return 0 ;
if ( V_81 -> V_36 != V_82 -> V_36 )
return 0 ;
return 1 ;
}
static int F_53 ( struct V_57 * V_58 ,
struct V_32 * V_33 )
{
struct V_32 * V_83 ;
struct V_3 * V_4 ;
F_54 (pos, head) {
struct V_29 * V_39 ;
V_39 = F_55 ( V_83 , struct V_29 , V_44 ) ;
if ( V_39 -> V_36 )
continue;
if ( V_39 -> V_41 . type )
continue;
F_56 ( ! V_39 -> V_20 ) ;
V_4 = F_57 ( V_58 -> V_84 , V_39 -> V_20 ,
0 ) ;
if ( F_33 ( V_4 ) ) {
return F_35 ( V_4 ) ;
} else if ( ! F_58 ( V_4 ) ) {
F_59 ( V_4 ) ;
return - V_85 ;
}
F_60 ( V_4 ) ;
if ( F_37 ( V_4 ) == 0 )
F_12 ( V_4 , & V_39 -> V_41 , 0 ) ;
else
F_61 ( V_4 , & V_39 -> V_41 , 0 ) ;
F_62 ( V_4 ) ;
F_59 ( V_4 ) ;
}
return 0 ;
}
static void F_63 ( struct V_32 * V_33 , int V_86 )
{
struct V_32 * V_87 ;
F_54 (pos1, head) {
struct V_32 * V_88 ;
struct V_32 * V_89 ;
struct V_29 * V_81 ;
V_81 = F_55 ( V_87 , struct V_29 , V_44 ) ;
for ( V_89 = V_87 -> V_16 , V_88 = V_89 -> V_16 ; V_89 != V_33 ;
V_89 = V_88 , V_88 = V_89 -> V_16 ) {
struct V_29 * V_82 ;
struct V_29 * V_90 ;
struct V_8 * V_9 ;
V_82 = F_55 ( V_89 , struct V_29 , V_44 ) ;
if ( ! F_52 ( V_81 , V_82 ) )
continue;
if ( V_86 == 1 ) {
if ( ! V_81 -> V_36 && V_82 -> V_36 ) {
V_90 = V_81 ;
V_81 = V_82 ;
V_82 = V_90 ;
}
} else {
if ( V_81 -> V_36 != V_82 -> V_36 )
continue;
}
V_9 = V_81 -> V_43 ;
while ( V_9 && V_9 -> V_16 )
V_9 = V_9 -> V_16 ;
if ( V_9 )
V_9 -> V_16 = V_82 -> V_43 ;
else
V_81 -> V_43 = V_82 -> V_43 ;
V_81 -> V_37 += V_82 -> V_37 ;
F_64 ( & V_82 -> V_44 ) ;
F_65 ( V_28 , V_82 ) ;
}
}
}
static int F_66 ( struct V_91 * V_33 , T_1 V_92 ,
struct V_32 * V_93 , T_1 * V_52 ,
T_1 V_17 )
{
struct V_94 * V_68 ;
struct V_95 * V_96 = V_33 -> V_96 ;
struct V_1 V_2 ;
struct V_1 V_97 = { 0 } ;
int V_98 ;
int V_25 = 0 ;
if ( V_96 && V_96 -> V_99 )
F_67 ( & V_97 , & V_96 -> V_2 ) ;
F_68 ( & V_33 -> V_100 ) ;
F_69 (node, &head->ref_list, list) {
if ( V_68 -> V_92 > V_92 )
continue;
switch ( V_68 -> V_101 ) {
case V_102 :
case V_103 :
F_42 ( 1 ) ;
continue;
case V_104 :
V_98 = 1 ;
break;
case V_105 :
V_98 = - 1 ;
break;
default:
F_56 ( 1 ) ;
}
* V_52 += ( V_68 -> V_106 * V_98 ) ;
switch ( V_68 -> type ) {
case V_107 : {
struct V_108 * V_39 ;
V_39 = F_70 ( V_68 ) ;
V_25 = F_20 ( V_93 , V_39 -> V_46 , & V_97 ,
V_39 -> V_35 + 1 , 0 , V_68 -> V_109 ,
V_68 -> V_106 * V_98 , V_110 ) ;
break;
}
case V_111 : {
struct V_108 * V_39 ;
V_39 = F_70 ( V_68 ) ;
V_25 = F_20 ( V_93 , 0 , NULL ,
V_39 -> V_35 + 1 , V_39 -> V_36 ,
V_68 -> V_109 ,
V_68 -> V_106 * V_98 , V_110 ) ;
break;
}
case V_112 : {
struct V_113 * V_39 ;
V_39 = F_71 ( V_68 ) ;
V_2 . V_18 = V_39 -> V_18 ;
V_2 . type = V_26 ;
V_2 . V_10 = V_39 -> V_10 ;
if ( V_17 && V_39 -> V_18 != V_17 ) {
V_25 = V_77 ;
break;
}
V_25 = F_20 ( V_93 , V_39 -> V_46 , & V_2 , 0 , 0 ,
V_68 -> V_109 ,
V_68 -> V_106 * V_98 , V_110 ) ;
break;
}
case V_114 : {
struct V_113 * V_39 ;
V_39 = F_71 ( V_68 ) ;
V_25 = F_20 ( V_93 , 0 , NULL , 0 ,
V_39 -> V_36 , V_68 -> V_109 ,
V_68 -> V_106 * V_98 , V_110 ) ;
break;
}
default:
F_42 ( 1 ) ;
}
if ( V_25 )
break;
}
F_72 ( & V_33 -> V_100 ) ;
return V_25 ;
}
static int F_73 ( struct V_57 * V_58 ,
struct V_47 * V_48 , T_1 V_109 ,
int * V_115 , struct V_32 * V_93 ,
T_1 * V_52 , T_1 V_17 )
{
int V_25 = 0 ;
int V_22 ;
struct V_3 * V_116 ;
struct V_1 V_2 ;
struct V_1 V_117 ;
unsigned long V_118 ;
unsigned long V_119 ;
struct V_120 * V_121 ;
T_1 V_122 ;
T_1 V_123 ;
V_116 = V_48 -> V_54 [ 0 ] ;
V_22 = V_48 -> V_56 [ 0 ] ;
V_123 = F_74 ( V_116 , V_22 ) ;
F_56 ( V_123 < sizeof( * V_121 ) ) ;
V_121 = F_13 ( V_116 , V_22 , struct V_120 ) ;
V_122 = F_75 ( V_116 , V_121 ) ;
* V_52 += F_76 ( V_116 , V_121 ) ;
F_12 ( V_116 , & V_117 , V_22 ) ;
V_118 = ( unsigned long ) ( V_121 + 1 ) ;
V_119 = ( unsigned long ) V_121 + V_123 ;
if ( V_117 . type == V_124 &&
V_122 & V_125 ) {
struct V_126 * V_127 ;
V_127 = (struct V_126 * ) V_118 ;
* V_115 = F_77 ( V_116 , V_127 ) ;
V_118 += sizeof( struct V_126 ) ;
F_56 ( V_118 > V_119 ) ;
} else if ( V_117 . type == V_128 ) {
* V_115 = V_117 . V_10 ;
} else {
F_56 ( ! ( V_122 & V_129 ) ) ;
}
while ( V_118 < V_119 ) {
struct V_130 * V_131 ;
T_1 V_10 ;
int type ;
V_131 = (struct V_130 * ) V_118 ;
type = F_78 ( V_116 , V_131 ) ;
V_10 = F_79 ( V_116 , V_131 ) ;
switch ( type ) {
case V_111 :
V_25 = F_20 ( V_93 , 0 , NULL ,
* V_115 + 1 , V_10 ,
V_109 , 1 , V_14 ) ;
break;
case V_114 : {
struct V_132 * V_133 ;
int V_37 ;
V_133 = (struct V_132 * ) ( V_131 + 1 ) ;
V_37 = F_80 ( V_116 , V_133 ) ;
V_25 = F_20 ( V_93 , 0 , NULL , 0 , V_10 ,
V_109 , V_37 , V_14 ) ;
break;
}
case V_107 :
V_25 = F_20 ( V_93 , V_10 , NULL ,
* V_115 + 1 , 0 ,
V_109 , 1 , V_14 ) ;
break;
case V_112 : {
struct V_134 * V_135 ;
int V_37 ;
T_1 V_46 ;
V_135 = (struct V_134 * ) ( & V_131 -> V_10 ) ;
V_37 = F_81 ( V_116 , V_135 ) ;
V_2 . V_18 = F_82 ( V_116 ,
V_135 ) ;
V_2 . type = V_26 ;
V_2 . V_10 = F_83 ( V_116 , V_135 ) ;
if ( V_17 && V_2 . V_18 != V_17 ) {
V_25 = V_77 ;
break;
}
V_46 = F_84 ( V_116 , V_135 ) ;
V_25 = F_20 ( V_93 , V_46 , & V_2 , 0 , 0 ,
V_109 , V_37 , V_14 ) ;
break;
}
default:
F_42 ( 1 ) ;
}
if ( V_25 )
return V_25 ;
V_118 += F_85 ( type ) ;
}
return 0 ;
}
static int F_86 ( struct V_57 * V_58 ,
struct V_47 * V_48 , T_1 V_109 ,
int V_115 , struct V_32 * V_93 , T_1 V_17 )
{
struct V_45 * V_136 = V_58 -> V_136 ;
int V_25 ;
int V_22 ;
struct V_3 * V_116 ;
struct V_1 V_2 ;
while ( 1 ) {
V_25 = F_28 ( V_136 , V_48 ) ;
if ( V_25 < 0 )
break;
if ( V_25 ) {
V_25 = 0 ;
break;
}
V_22 = V_48 -> V_56 [ 0 ] ;
V_116 = V_48 -> V_54 [ 0 ] ;
F_12 ( V_116 , & V_2 , V_22 ) ;
if ( V_2 . V_18 != V_109 )
break;
if ( V_2 . type < V_107 )
continue;
if ( V_2 . type > V_114 )
break;
switch ( V_2 . type ) {
case V_111 :
V_25 = F_20 ( V_93 , 0 , NULL ,
V_115 + 1 , V_2 . V_10 ,
V_109 , 1 , V_14 ) ;
break;
case V_114 : {
struct V_132 * V_133 ;
int V_37 ;
V_133 = F_13 ( V_116 , V_22 ,
struct V_132 ) ;
V_37 = F_80 ( V_116 , V_133 ) ;
V_25 = F_20 ( V_93 , 0 , NULL , 0 , V_2 . V_10 ,
V_109 , V_37 , V_14 ) ;
break;
}
case V_107 :
V_25 = F_20 ( V_93 , V_2 . V_10 , NULL ,
V_115 + 1 , 0 ,
V_109 , 1 , V_14 ) ;
break;
case V_112 : {
struct V_134 * V_135 ;
int V_37 ;
T_1 V_46 ;
V_135 = F_13 ( V_116 , V_22 ,
struct V_134 ) ;
V_37 = F_81 ( V_116 , V_135 ) ;
V_2 . V_18 = F_82 ( V_116 ,
V_135 ) ;
V_2 . type = V_26 ;
V_2 . V_10 = F_83 ( V_116 , V_135 ) ;
if ( V_17 && V_2 . V_18 != V_17 ) {
V_25 = V_77 ;
break;
}
V_46 = F_84 ( V_116 , V_135 ) ;
V_25 = F_20 ( V_93 , V_46 , & V_2 , 0 , 0 ,
V_109 , V_37 , V_14 ) ;
break;
}
default:
F_42 ( 1 ) ;
}
if ( V_25 )
return V_25 ;
}
return V_25 ;
}
static void F_87 ( struct V_49 * V_137 )
{
struct V_74 * V_68 = NULL ;
struct V_8 * V_9 ;
struct V_75 V_76 ;
F_47 ( & V_76 ) ;
while ( ( V_68 = F_48 ( V_137 , & V_76 ) ) ) {
if ( ! V_68 -> V_80 )
continue;
V_9 = (struct V_8 * ) ( V_79 ) V_68 -> V_80 ;
F_8 ( V_9 ) ;
V_68 -> V_80 = 0 ;
}
F_51 ( V_137 ) ;
}
static int F_88 ( struct V_138 * V_139 ,
struct V_57 * V_58 , T_1 V_109 ,
T_1 V_51 , struct V_49 * * V_140 ,
const T_1 * V_7 )
{
int V_25 ;
* V_140 = F_45 ( V_14 ) ;
if ( ! * V_140 )
return - V_15 ;
V_25 = F_89 ( V_139 , V_58 , V_109 ,
V_51 , * V_140 , NULL , V_7 , 0 , 0 ) ;
if ( V_25 < 0 && V_25 != - V_65 ) {
F_87 ( * V_140 ) ;
return V_25 ;
}
return 0 ;
}
static int F_90 ( struct V_138 * V_139 ,
struct V_57 * V_58 , T_1 V_109 ,
T_1 V_51 , struct V_49 * * V_141 )
{
struct V_49 * V_142 ;
struct V_74 * V_68 = NULL ;
struct V_75 V_76 ;
int V_25 ;
V_142 = F_45 ( V_14 ) ;
if ( ! V_142 )
return - V_15 ;
* V_141 = F_45 ( V_14 ) ;
if ( ! * V_141 ) {
F_51 ( V_142 ) ;
return - V_15 ;
}
F_47 ( & V_76 ) ;
while ( 1 ) {
V_25 = F_89 ( V_139 , V_58 , V_109 ,
V_51 , V_142 , * V_141 , NULL , 0 , 0 ) ;
if ( V_25 < 0 && V_25 != - V_65 ) {
F_51 ( V_142 ) ;
F_51 ( * V_141 ) ;
return V_25 ;
}
V_68 = F_48 ( V_142 , & V_76 ) ;
if ( ! V_68 )
break;
V_109 = V_68 -> V_78 ;
F_91 () ;
}
F_51 ( V_142 ) ;
return 0 ;
}
int F_92 ( struct V_138 * V_139 ,
struct V_57 * V_58 , T_1 V_109 ,
T_1 V_51 , struct V_49 * * V_141 )
{
int V_25 ;
if ( ! V_139 )
F_93 ( & V_58 -> V_143 ) ;
V_25 = F_90 ( V_139 , V_58 , V_109 , V_51 , V_141 ) ;
if ( ! V_139 )
F_94 ( & V_58 -> V_143 ) ;
return V_25 ;
}
int F_95 ( struct V_138 * V_139 ,
struct V_57 * V_58 , T_1 V_70 ,
T_1 V_17 , T_1 V_109 )
{
struct V_49 * V_142 = NULL ;
struct V_49 * V_141 = NULL ;
struct V_75 V_76 ;
struct V_74 * V_68 ;
struct V_144 V_145 = F_96 ( V_145 ) ;
int V_25 = 0 ;
V_142 = F_45 ( V_14 ) ;
V_141 = F_45 ( V_14 ) ;
if ( ! V_142 || ! V_141 ) {
F_51 ( V_142 ) ;
F_51 ( V_141 ) ;
return - V_15 ;
}
if ( V_139 )
F_97 ( V_58 , & V_145 ) ;
else
F_93 ( & V_58 -> V_143 ) ;
F_47 ( & V_76 ) ;
while ( 1 ) {
V_25 = F_89 ( V_139 , V_58 , V_109 , V_145 . V_92 , V_142 ,
V_141 , NULL , V_70 , V_17 ) ;
if ( V_25 == V_77 ) {
V_25 = 1 ;
break;
}
if ( V_25 < 0 && V_25 != - V_65 )
break;
V_25 = 0 ;
V_68 = F_48 ( V_142 , & V_76 ) ;
if ( ! V_68 )
break;
V_109 = V_68 -> V_78 ;
F_91 () ;
}
if ( V_139 )
F_98 ( V_58 , & V_145 ) ;
else
F_94 ( & V_58 -> V_143 ) ;
F_51 ( V_142 ) ;
F_51 ( V_141 ) ;
return V_25 ;
}
int F_99 ( struct V_45 * V_46 , T_1 V_146 ,
T_1 V_147 , struct V_47 * V_48 ,
struct V_148 * * V_149 ,
T_1 * V_150 )
{
int V_25 , V_22 ;
struct V_1 V_2 ;
struct V_1 V_117 ;
struct V_148 * V_151 ;
struct V_3 * V_116 ;
unsigned long V_118 ;
V_2 . V_18 = V_146 ;
V_2 . type = V_152 ;
V_2 . V_10 = V_147 ;
V_25 = F_39 ( NULL , V_46 , & V_2 , V_48 , 0 , 0 ) ;
if ( V_25 < 0 )
return V_25 ;
while ( 1 ) {
V_116 = V_48 -> V_54 [ 0 ] ;
V_22 = V_48 -> V_56 [ 0 ] ;
if ( V_22 >= F_11 ( V_116 ) ) {
V_25 = F_25 ( V_46 , V_48 ) ;
if ( V_25 ) {
if ( V_25 >= 1 )
V_25 = - V_65 ;
break;
}
continue;
}
F_12 ( V_116 , & V_117 , V_22 ) ;
V_25 = - V_65 ;
if ( V_117 . V_18 != V_146 )
break;
if ( V_117 . type != V_152 )
break;
V_25 = 0 ;
V_118 = F_100 ( V_116 , V_48 -> V_56 [ 0 ] ) ;
V_151 = (struct V_148 * ) V_118 ;
* V_149 = V_151 ;
if ( V_150 )
* V_150 = V_117 . V_10 ;
break;
}
return V_25 ;
}
char * F_101 ( struct V_45 * V_153 , struct V_47 * V_48 ,
T_4 V_154 , unsigned long V_155 ,
struct V_3 * V_156 , T_1 V_36 ,
char * V_157 , T_4 V_158 )
{
int V_22 ;
T_1 V_159 ;
int V_25 ;
T_5 V_160 = ( ( T_5 ) V_158 ) - 1 ;
struct V_3 * V_4 = V_156 ;
struct V_1 V_117 ;
int V_161 = V_48 -> V_161 ;
struct V_162 * V_131 ;
if ( V_160 >= 0 )
V_157 [ V_160 ] = '\0' ;
V_48 -> V_161 = 1 ;
while ( 1 ) {
V_160 -= V_154 ;
if ( V_160 >= 0 )
F_102 ( V_4 , V_157 + V_160 ,
V_155 , V_154 ) ;
if ( V_4 != V_156 ) {
F_103 ( V_4 ) ;
F_59 ( V_4 ) ;
}
V_25 = F_104 ( V_153 , V_48 , V_36 , 0 ,
V_163 , & V_117 ) ;
if ( V_25 > 0 )
V_25 = - V_65 ;
if ( V_25 )
break;
V_159 = V_117 . V_10 ;
if ( V_36 == V_159 )
break;
V_22 = V_48 -> V_56 [ 0 ] ;
V_4 = V_48 -> V_54 [ 0 ] ;
if ( V_4 != V_156 ) {
F_105 ( & V_4 -> V_164 ) ;
F_60 ( V_4 ) ;
F_106 ( V_4 , V_165 ) ;
}
F_43 ( V_48 ) ;
V_131 = F_13 ( V_4 , V_22 , struct V_162 ) ;
V_154 = F_107 ( V_4 , V_131 ) ;
V_155 = ( unsigned long ) ( V_131 + 1 ) ;
V_36 = V_159 ;
-- V_160 ;
if ( V_160 >= 0 )
V_157 [ V_160 ] = '/' ;
}
F_43 ( V_48 ) ;
V_48 -> V_161 = V_161 ;
if ( V_25 )
return F_108 ( V_25 ) ;
return V_157 + V_160 ;
}
int F_109 ( struct V_57 * V_58 , T_1 V_166 ,
struct V_47 * V_48 , struct V_1 * V_117 ,
T_1 * V_167 )
{
int V_25 ;
T_1 V_122 ;
T_1 V_158 = 0 ;
T_4 V_123 ;
struct V_3 * V_4 ;
struct V_120 * V_121 ;
struct V_1 V_2 ;
if ( F_110 ( V_58 , V_168 ) )
V_2 . type = V_128 ;
else
V_2 . type = V_124 ;
V_2 . V_18 = V_166 ;
V_2 . V_10 = ( T_1 ) - 1 ;
V_25 = F_39 ( NULL , V_58 -> V_136 , & V_2 , V_48 , 0 , 0 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_111 ( V_58 -> V_136 , V_48 , 0 ) ;
if ( V_25 ) {
if ( V_25 > 0 )
V_25 = - V_65 ;
return V_25 ;
}
F_12 ( V_48 -> V_54 [ 0 ] , V_117 , V_48 -> V_56 [ 0 ] ) ;
if ( V_117 -> type == V_128 )
V_158 = V_58 -> V_136 -> V_169 ;
else if ( V_117 -> type == V_124 )
V_158 = V_117 -> V_10 ;
if ( V_117 -> V_18 > V_166 ||
V_117 -> V_18 + V_158 <= V_166 ) {
F_41 ( L_4 , V_166 ) ;
return - V_65 ;
}
V_4 = V_48 -> V_54 [ 0 ] ;
V_123 = F_74 ( V_4 , V_48 -> V_56 [ 0 ] ) ;
F_56 ( V_123 < sizeof( * V_121 ) ) ;
V_121 = F_13 ( V_4 , V_48 -> V_56 [ 0 ] , struct V_120 ) ;
V_122 = F_75 ( V_4 , V_121 ) ;
F_41 ( L_5
L_6 ,
V_166 , V_166 - V_117 -> V_18 , V_117 -> V_18 ,
V_117 -> V_10 , V_122 , V_123 ) ;
F_42 ( ! V_167 ) ;
if ( V_167 ) {
if ( V_122 & V_125 )
* V_167 = V_125 ;
else if ( V_122 & V_129 )
* V_167 = V_129 ;
else
F_56 ( 1 ) ;
return 0 ;
}
return - V_85 ;
}
static int F_112 ( unsigned long * V_118 , struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_120 * V_121 , T_4 V_123 ,
struct V_130 * * V_170 ,
int * V_171 )
{
unsigned long V_119 ;
T_1 V_122 ;
struct V_126 * V_127 ;
if ( ! * V_118 ) {
V_122 = F_75 ( V_4 , V_121 ) ;
if ( V_122 & V_125 ) {
if ( V_2 -> type == V_128 ) {
* V_170 =
(struct V_130 * ) ( V_121 + 1 ) ;
} else {
F_42 ( V_2 -> type != V_124 ) ;
V_127 = (struct V_126 * ) ( V_121 + 1 ) ;
* V_170 =
(struct V_130 * ) ( V_127 + 1 ) ;
}
} else {
* V_170 = (struct V_130 * ) ( V_121 + 1 ) ;
}
* V_118 = ( unsigned long ) * V_170 ;
if ( ( unsigned long ) ( * V_118 ) >= ( unsigned long ) V_121 + V_123 )
return - V_65 ;
}
V_119 = ( unsigned long ) V_121 + V_123 ;
* V_170 = (struct V_130 * ) ( * V_118 ) ;
* V_171 = F_78 ( V_4 , * V_170 ) ;
* V_118 += F_85 ( * V_171 ) ;
F_42 ( * V_118 > V_119 ) ;
if ( * V_118 == V_119 )
return 1 ;
return 0 ;
}
int F_113 ( unsigned long * V_118 , struct V_3 * V_4 ,
struct V_1 * V_2 , struct V_120 * V_121 ,
T_4 V_123 , T_1 * V_172 , T_6 * V_173 )
{
int V_25 ;
int type ;
struct V_130 * V_174 ;
if ( * V_118 == ( unsigned long ) - 1 )
return 1 ;
while ( 1 ) {
V_25 = F_112 ( V_118 , V_4 , V_2 , V_121 , V_123 ,
& V_174 , & type ) ;
if ( V_25 < 0 )
return V_25 ;
if ( type == V_107 ||
type == V_111 )
break;
if ( V_25 == 1 )
return 1 ;
}
* V_172 = F_79 ( V_4 , V_174 ) ;
if ( V_2 -> type == V_124 ) {
struct V_126 * V_127 ;
V_127 = (struct V_126 * ) ( V_121 + 1 ) ;
* V_173 = F_77 ( V_4 , V_127 ) ;
} else {
ASSERT ( V_2 -> type == V_128 ) ;
* V_173 = ( T_6 ) V_2 -> V_10 ;
}
if ( V_25 == 1 )
* V_118 = ( unsigned long ) - 1 ;
return 0 ;
}
static int F_114 ( struct V_8 * V_43 ,
T_1 V_46 , T_1 V_175 ,
T_7 * V_176 , void * V_177 )
{
struct V_8 * V_9 ;
int V_25 = 0 ;
for ( V_9 = V_43 ; V_9 ; V_9 = V_9 -> V_16 ) {
F_41 ( L_7
L_8 , V_175 ,
V_9 -> V_17 , V_9 -> V_10 , V_46 ) ;
V_25 = V_176 ( V_9 -> V_17 , V_9 -> V_10 , V_46 , V_177 ) ;
if ( V_25 ) {
F_41 ( L_9 ,
V_175 , V_25 ) ;
break;
}
}
return V_25 ;
}
int F_115 ( struct V_57 * V_58 ,
T_1 V_175 , T_1 V_7 ,
int V_66 ,
T_7 * V_176 , void * V_177 )
{
int V_25 ;
struct V_138 * V_139 = NULL ;
struct V_49 * V_164 = NULL ;
struct V_49 * V_141 = NULL ;
struct V_74 * V_178 = NULL ;
struct V_74 * V_179 = NULL ;
struct V_144 V_180 = F_96 ( V_180 ) ;
struct V_75 V_181 ;
struct V_75 V_182 ;
F_41 ( L_10 ,
V_175 ) ;
if ( ! V_66 ) {
V_139 = F_116 ( V_58 -> V_136 ) ;
if ( F_33 ( V_139 ) )
return F_35 ( V_139 ) ;
F_97 ( V_58 , & V_180 ) ;
} else {
F_93 ( & V_58 -> V_143 ) ;
}
V_25 = F_88 ( V_139 , V_58 , V_175 ,
V_180 . V_92 , & V_164 ,
& V_7 ) ;
if ( V_25 )
goto V_64;
F_47 ( & V_181 ) ;
while ( ! V_25 && ( V_178 = F_48 ( V_164 , & V_181 ) ) ) {
V_25 = F_90 ( V_139 , V_58 , V_178 -> V_78 ,
V_180 . V_92 , & V_141 ) ;
if ( V_25 )
break;
F_47 ( & V_182 ) ;
while ( ! V_25 && ( V_179 = F_48 ( V_141 , & V_182 ) ) ) {
F_41 ( L_11
L_12 , V_179 -> V_78 , V_178 -> V_78 ,
V_178 -> V_80 ) ;
V_25 = F_114 ( (struct V_8 * )
( V_79 ) V_178 -> V_80 ,
V_179 -> V_78 ,
V_175 ,
V_176 , V_177 ) ;
}
F_51 ( V_141 ) ;
}
F_87 ( V_164 ) ;
V_64:
if ( ! V_66 ) {
F_98 ( V_58 , & V_180 ) ;
F_117 ( V_139 , V_58 -> V_136 ) ;
} else {
F_94 ( & V_58 -> V_143 ) ;
}
return V_25 ;
}
int F_118 ( T_1 V_166 , struct V_57 * V_58 ,
struct V_47 * V_48 ,
T_7 * V_176 , void * V_177 )
{
int V_25 ;
T_1 V_7 ;
T_1 V_122 = 0 ;
struct V_1 V_117 ;
int V_66 = V_48 -> V_66 ;
V_25 = F_109 ( V_58 , V_166 , V_48 , & V_117 , & V_122 ) ;
F_43 ( V_48 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_122 & V_125 )
return - V_183 ;
V_7 = V_166 - V_117 . V_18 ;
V_25 = F_115 ( V_58 , V_117 . V_18 ,
V_7 , V_66 ,
V_176 , V_177 ) ;
return V_25 ;
}
static int F_119 ( T_1 V_17 , struct V_45 * V_153 ,
struct V_47 * V_48 ,
T_8 * V_176 , void * V_177 )
{
int V_25 = 0 ;
int V_22 ;
T_4 V_184 ;
T_4 V_185 ;
T_4 V_154 ;
T_1 V_36 = 0 ;
int V_186 = 0 ;
struct V_3 * V_4 ;
struct V_187 * V_188 ;
struct V_162 * V_131 ;
struct V_1 V_117 ;
while ( ! V_25 ) {
V_25 = F_104 ( V_153 , V_48 , V_17 ,
V_36 ? V_36 + 1 : 0 , V_163 ,
& V_117 ) ;
if ( V_25 < 0 )
break;
if ( V_25 ) {
V_25 = V_186 ? 0 : - V_65 ;
break;
}
++ V_186 ;
V_36 = V_117 . V_10 ;
V_22 = V_48 -> V_56 [ 0 ] ;
V_4 = F_120 ( V_48 -> V_54 [ 0 ] ) ;
if ( ! V_4 ) {
V_25 = - V_15 ;
break;
}
F_121 ( V_4 ) ;
F_60 ( V_4 ) ;
F_106 ( V_4 , V_165 ) ;
F_43 ( V_48 ) ;
V_188 = F_122 ( V_22 ) ;
V_131 = F_13 ( V_4 , V_22 , struct V_162 ) ;
for ( V_184 = 0 ; V_184 < F_123 ( V_4 , V_188 ) ; V_184 += V_185 ) {
V_154 = F_107 ( V_4 , V_131 ) ;
F_41 ( L_13
L_14 , V_184 , V_117 . V_18 ,
V_153 -> V_18 ) ;
V_25 = V_176 ( V_36 , V_154 ,
( unsigned long ) ( V_131 + 1 ) , V_4 , V_177 ) ;
if ( V_25 )
break;
V_185 = sizeof( * V_131 ) + V_154 ;
V_131 = (struct V_162 * ) ( ( char * ) V_131 + V_185 ) ;
}
F_103 ( V_4 ) ;
F_59 ( V_4 ) ;
}
F_43 ( V_48 ) ;
return V_25 ;
}
static int F_124 ( T_1 V_17 , struct V_45 * V_153 ,
struct V_47 * V_48 ,
T_8 * V_176 , void * V_177 )
{
int V_25 ;
int V_22 ;
T_1 V_10 = 0 ;
T_1 V_36 ;
int V_186 = 0 ;
struct V_3 * V_4 ;
struct V_148 * V_151 ;
T_4 V_123 ;
T_4 V_189 ;
unsigned long V_118 ;
while ( 1 ) {
V_25 = F_99 ( V_153 , V_17 , V_10 , V_48 , & V_151 ,
& V_10 ) ;
if ( V_25 < 0 )
break;
if ( V_25 ) {
V_25 = V_186 ? 0 : - V_65 ;
break;
}
++ V_186 ;
V_22 = V_48 -> V_56 [ 0 ] ;
V_4 = F_120 ( V_48 -> V_54 [ 0 ] ) ;
if ( ! V_4 ) {
V_25 = - V_15 ;
break;
}
F_121 ( V_4 ) ;
F_60 ( V_4 ) ;
F_106 ( V_4 , V_165 ) ;
F_43 ( V_48 ) ;
V_123 = F_74 ( V_4 , V_22 ) ;
V_118 = F_100 ( V_4 , V_22 ) ;
V_189 = 0 ;
while ( V_189 < V_123 ) {
T_4 V_154 ;
V_151 = (struct V_148 * ) ( V_118 + V_189 ) ;
V_36 = F_125 ( V_4 , V_151 ) ;
V_154 = F_126 ( V_4 , V_151 ) ;
V_25 = V_176 ( V_36 , V_154 ,
( unsigned long ) & V_151 -> V_190 , V_4 , V_177 ) ;
if ( V_25 )
break;
V_189 += F_126 ( V_4 , V_151 ) ;
V_189 += sizeof( * V_151 ) ;
}
F_103 ( V_4 ) ;
F_59 ( V_4 ) ;
V_10 ++ ;
}
F_43 ( V_48 ) ;
return V_25 ;
}
static int F_127 ( T_1 V_17 , struct V_45 * V_153 ,
struct V_47 * V_48 , T_8 * V_176 ,
void * V_177 )
{
int V_25 ;
int V_191 = 0 ;
V_25 = F_119 ( V_17 , V_153 , V_48 , V_176 , V_177 ) ;
if ( ! V_25 )
++ V_191 ;
else if ( V_25 != - V_65 )
return V_25 ;
V_25 = F_124 ( V_17 , V_153 , V_48 , V_176 , V_177 ) ;
if ( V_25 == - V_65 && V_191 )
return 0 ;
return V_25 ;
}
static int F_128 ( T_1 V_17 , T_4 V_154 , unsigned long V_155 ,
struct V_3 * V_4 , void * V_177 )
{
struct V_192 * V_193 = V_177 ;
char * V_194 ;
char * V_195 ;
int V_196 = V_193 -> V_194 -> V_197 ;
const int V_198 = sizeof( char * ) ;
T_4 V_160 ;
V_160 = V_193 -> V_194 -> V_160 > V_198 ?
V_193 -> V_194 -> V_160 - V_198 : 0 ;
V_195 = ( char * ) V_193 -> V_194 -> V_78 + ( V_196 + 1 ) * V_198 ;
V_194 = F_101 ( V_193 -> V_153 , V_193 -> V_47 , V_154 ,
V_155 , V_4 , V_17 , V_195 , V_160 ) ;
if ( F_33 ( V_194 ) )
return F_35 ( V_194 ) ;
if ( V_194 > V_195 ) {
V_193 -> V_194 -> V_78 [ V_196 ] = ( T_1 ) ( unsigned long ) V_194 ;
++ V_193 -> V_194 -> V_197 ;
V_193 -> V_194 -> V_160 = V_194 - V_195 ;
} else {
++ V_193 -> V_194 -> V_199 ;
V_193 -> V_194 -> V_200 += V_195 - V_194 ;
V_193 -> V_194 -> V_160 = 0 ;
}
return 0 ;
}
int F_129 ( T_1 V_17 , struct V_192 * V_193 )
{
return F_127 ( V_17 , V_193 -> V_153 , V_193 -> V_47 ,
F_128 , V_193 ) ;
}
struct V_201 * F_130 ( T_4 V_202 )
{
struct V_201 * V_203 ;
T_9 V_204 ;
V_204 = F_131 ( T_9 , V_202 , sizeof( * V_203 ) ) ;
V_203 = F_132 ( V_204 ) ;
if ( ! V_203 )
return F_108 ( - V_15 ) ;
if ( V_202 >= sizeof( * V_203 ) ) {
V_203 -> V_160 = V_202 - sizeof( * V_203 ) ;
V_203 -> V_200 = 0 ;
} else {
V_203 -> V_200 = sizeof( * V_203 ) - V_202 ;
V_203 -> V_160 = 0 ;
}
V_203 -> V_197 = 0 ;
V_203 -> V_199 = 0 ;
return V_203 ;
}
struct V_192 * F_133 ( T_10 V_202 , struct V_45 * V_153 ,
struct V_47 * V_48 )
{
struct V_192 * V_205 ;
struct V_201 * V_194 ;
V_194 = F_130 ( V_202 ) ;
if ( F_33 ( V_194 ) )
return ( void * ) V_194 ;
V_205 = F_7 ( sizeof( * V_205 ) , V_14 ) ;
if ( ! V_205 ) {
F_9 ( V_194 ) ;
return F_108 ( - V_15 ) ;
}
V_205 -> V_47 = V_48 ;
V_205 -> V_194 = V_194 ;
V_205 -> V_153 = V_153 ;
return V_205 ;
}
void F_134 ( struct V_192 * V_193 )
{
if ( ! V_193 )
return;
F_135 ( V_193 -> V_194 ) ;
F_9 ( V_193 ) ;
}
