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
struct V_29 * V_39 ;
struct V_3 * V_4 ;
F_54 (ref, head, list) {
if ( V_39 -> V_36 )
continue;
if ( V_39 -> V_41 . type )
continue;
F_55 ( ! V_39 -> V_20 ) ;
V_4 = F_56 ( V_58 -> V_83 , V_39 -> V_20 ,
0 ) ;
if ( F_33 ( V_4 ) ) {
return F_35 ( V_4 ) ;
} else if ( ! F_57 ( V_4 ) ) {
F_58 ( V_4 ) ;
return - V_84 ;
}
F_59 ( V_4 ) ;
if ( F_37 ( V_4 ) == 0 )
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
struct V_29 * V_86 ;
F_54 (pos1, head, list) {
struct V_29 * V_87 = V_86 , * V_88 ;
F_63 (pos2, tmp, head, list) {
struct V_29 * V_81 = V_86 , * V_82 = V_87 ;
struct V_8 * V_9 ;
if ( ! F_52 ( V_81 , V_82 ) )
continue;
if ( V_85 == 1 ) {
if ( ! V_81 -> V_36 && V_82 -> V_36 )
F_64 ( V_81 , V_82 ) ;
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
F_65 ( & V_82 -> V_44 ) ;
F_66 ( V_28 , V_82 ) ;
}
}
}
static int F_67 ( struct V_89 * V_33 , T_1 V_90 ,
struct V_32 * V_91 , T_1 * V_52 ,
T_1 V_17 )
{
struct V_92 * V_68 ;
struct V_93 * V_94 = V_33 -> V_94 ;
struct V_1 V_2 ;
struct V_1 V_95 = { 0 } ;
int V_96 ;
int V_25 = 0 ;
if ( V_94 && V_94 -> V_97 )
F_68 ( & V_95 , & V_94 -> V_2 ) ;
F_69 ( & V_33 -> V_98 ) ;
F_54 (node, &head->ref_list, list) {
if ( V_68 -> V_90 > V_90 )
continue;
switch ( V_68 -> V_99 ) {
case V_100 :
case V_101 :
F_42 ( 1 ) ;
continue;
case V_102 :
V_96 = 1 ;
break;
case V_103 :
V_96 = - 1 ;
break;
default:
F_55 ( 1 ) ;
}
* V_52 += ( V_68 -> V_104 * V_96 ) ;
switch ( V_68 -> type ) {
case V_105 : {
struct V_106 * V_39 ;
V_39 = F_70 ( V_68 ) ;
V_25 = F_20 ( V_91 , V_39 -> V_46 , & V_95 ,
V_39 -> V_35 + 1 , 0 , V_68 -> V_107 ,
V_68 -> V_104 * V_96 , V_108 ) ;
break;
}
case V_109 : {
struct V_106 * V_39 ;
V_39 = F_70 ( V_68 ) ;
V_25 = F_20 ( V_91 , 0 , NULL ,
V_39 -> V_35 + 1 , V_39 -> V_36 ,
V_68 -> V_107 ,
V_68 -> V_104 * V_96 , V_108 ) ;
break;
}
case V_110 : {
struct V_111 * V_39 ;
V_39 = F_71 ( V_68 ) ;
V_2 . V_18 = V_39 -> V_18 ;
V_2 . type = V_26 ;
V_2 . V_10 = V_39 -> V_10 ;
if ( V_17 && V_39 -> V_18 != V_17 ) {
V_25 = V_77 ;
break;
}
V_25 = F_20 ( V_91 , V_39 -> V_46 , & V_2 , 0 , 0 ,
V_68 -> V_107 ,
V_68 -> V_104 * V_96 , V_108 ) ;
break;
}
case V_112 : {
struct V_111 * V_39 ;
V_39 = F_71 ( V_68 ) ;
V_25 = F_20 ( V_91 , 0 , NULL , 0 ,
V_39 -> V_36 , V_68 -> V_107 ,
V_68 -> V_104 * V_96 , V_108 ) ;
break;
}
default:
F_42 ( 1 ) ;
}
if ( V_25 )
break;
}
F_72 ( & V_33 -> V_98 ) ;
return V_25 ;
}
static int F_73 ( struct V_57 * V_58 ,
struct V_47 * V_48 , T_1 V_107 ,
int * V_113 , struct V_32 * V_91 ,
T_1 * V_52 , T_1 V_17 )
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
V_114 = V_48 -> V_54 [ 0 ] ;
V_22 = V_48 -> V_56 [ 0 ] ;
V_121 = F_74 ( V_114 , V_22 ) ;
F_55 ( V_121 < sizeof( * V_119 ) ) ;
V_119 = F_13 ( V_114 , V_22 , struct V_118 ) ;
V_120 = F_75 ( V_114 , V_119 ) ;
* V_52 += F_76 ( V_114 , V_119 ) ;
F_12 ( V_114 , & V_115 , V_22 ) ;
V_116 = ( unsigned long ) ( V_119 + 1 ) ;
V_117 = ( unsigned long ) V_119 + V_121 ;
if ( V_115 . type == V_122 &&
V_120 & V_123 ) {
struct V_124 * V_125 ;
V_125 = (struct V_124 * ) V_116 ;
* V_113 = F_77 ( V_114 , V_125 ) ;
V_116 += sizeof( struct V_124 ) ;
F_55 ( V_116 > V_117 ) ;
} else if ( V_115 . type == V_126 ) {
* V_113 = V_115 . V_10 ;
} else {
F_55 ( ! ( V_120 & V_127 ) ) ;
}
while ( V_116 < V_117 ) {
struct V_128 * V_129 ;
T_1 V_10 ;
int type ;
V_129 = (struct V_128 * ) V_116 ;
type = F_78 ( V_114 , V_129 ) ;
V_10 = F_79 ( V_114 , V_129 ) ;
switch ( type ) {
case V_109 :
V_25 = F_20 ( V_91 , 0 , NULL ,
* V_113 + 1 , V_10 ,
V_107 , 1 , V_14 ) ;
break;
case V_112 : {
struct V_130 * V_131 ;
int V_37 ;
V_131 = (struct V_130 * ) ( V_129 + 1 ) ;
V_37 = F_80 ( V_114 , V_131 ) ;
V_25 = F_20 ( V_91 , 0 , NULL , 0 , V_10 ,
V_107 , V_37 , V_14 ) ;
break;
}
case V_105 :
V_25 = F_20 ( V_91 , V_10 , NULL ,
* V_113 + 1 , 0 ,
V_107 , 1 , V_14 ) ;
break;
case V_110 : {
struct V_132 * V_133 ;
int V_37 ;
T_1 V_46 ;
V_133 = (struct V_132 * ) ( & V_129 -> V_10 ) ;
V_37 = F_81 ( V_114 , V_133 ) ;
V_2 . V_18 = F_82 ( V_114 ,
V_133 ) ;
V_2 . type = V_26 ;
V_2 . V_10 = F_83 ( V_114 , V_133 ) ;
if ( V_17 && V_2 . V_18 != V_17 ) {
V_25 = V_77 ;
break;
}
V_46 = F_84 ( V_114 , V_133 ) ;
V_25 = F_20 ( V_91 , V_46 , & V_2 , 0 , 0 ,
V_107 , V_37 , V_14 ) ;
break;
}
default:
F_42 ( 1 ) ;
}
if ( V_25 )
return V_25 ;
V_116 += F_85 ( type ) ;
}
return 0 ;
}
static int F_86 ( struct V_57 * V_58 ,
struct V_47 * V_48 , T_1 V_107 ,
int V_113 , struct V_32 * V_91 , T_1 V_17 )
{
struct V_45 * V_134 = V_58 -> V_134 ;
int V_25 ;
int V_22 ;
struct V_3 * V_114 ;
struct V_1 V_2 ;
while ( 1 ) {
V_25 = F_28 ( V_134 , V_48 ) ;
if ( V_25 < 0 )
break;
if ( V_25 ) {
V_25 = 0 ;
break;
}
V_22 = V_48 -> V_56 [ 0 ] ;
V_114 = V_48 -> V_54 [ 0 ] ;
F_12 ( V_114 , & V_2 , V_22 ) ;
if ( V_2 . V_18 != V_107 )
break;
if ( V_2 . type < V_105 )
continue;
if ( V_2 . type > V_112 )
break;
switch ( V_2 . type ) {
case V_109 :
V_25 = F_20 ( V_91 , 0 , NULL ,
V_113 + 1 , V_2 . V_10 ,
V_107 , 1 , V_14 ) ;
break;
case V_112 : {
struct V_130 * V_131 ;
int V_37 ;
V_131 = F_13 ( V_114 , V_22 ,
struct V_130 ) ;
V_37 = F_80 ( V_114 , V_131 ) ;
V_25 = F_20 ( V_91 , 0 , NULL , 0 , V_2 . V_10 ,
V_107 , V_37 , V_14 ) ;
break;
}
case V_105 :
V_25 = F_20 ( V_91 , V_2 . V_10 , NULL ,
V_113 + 1 , 0 ,
V_107 , 1 , V_14 ) ;
break;
case V_110 : {
struct V_132 * V_133 ;
int V_37 ;
T_1 V_46 ;
V_133 = F_13 ( V_114 , V_22 ,
struct V_132 ) ;
V_37 = F_81 ( V_114 , V_133 ) ;
V_2 . V_18 = F_82 ( V_114 ,
V_133 ) ;
V_2 . type = V_26 ;
V_2 . V_10 = F_83 ( V_114 , V_133 ) ;
if ( V_17 && V_2 . V_18 != V_17 ) {
V_25 = V_77 ;
break;
}
V_46 = F_84 ( V_114 , V_133 ) ;
V_25 = F_20 ( V_91 , V_46 , & V_2 , 0 , 0 ,
V_107 , V_37 , V_14 ) ;
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
static void F_87 ( struct V_49 * V_135 )
{
struct V_74 * V_68 = NULL ;
struct V_8 * V_9 ;
struct V_75 V_76 ;
F_47 ( & V_76 ) ;
while ( ( V_68 = F_48 ( V_135 , & V_76 ) ) ) {
if ( ! V_68 -> V_80 )
continue;
V_9 = (struct V_8 * ) ( V_79 ) V_68 -> V_80 ;
F_8 ( V_9 ) ;
V_68 -> V_80 = 0 ;
}
F_51 ( V_135 ) ;
}
static int F_88 ( struct V_136 * V_137 ,
struct V_57 * V_58 , T_1 V_107 ,
T_1 V_51 , struct V_49 * * V_138 ,
const T_1 * V_7 )
{
int V_25 ;
* V_138 = F_45 ( V_14 ) ;
if ( ! * V_138 )
return - V_15 ;
V_25 = F_89 ( V_137 , V_58 , V_107 ,
V_51 , * V_138 , NULL , V_7 , 0 , 0 ) ;
if ( V_25 < 0 && V_25 != - V_65 ) {
F_87 ( * V_138 ) ;
return V_25 ;
}
return 0 ;
}
static int F_90 ( struct V_136 * V_137 ,
struct V_57 * V_58 , T_1 V_107 ,
T_1 V_51 , struct V_49 * * V_139 )
{
struct V_49 * V_88 ;
struct V_74 * V_68 = NULL ;
struct V_75 V_76 ;
int V_25 ;
V_88 = F_45 ( V_14 ) ;
if ( ! V_88 )
return - V_15 ;
* V_139 = F_45 ( V_14 ) ;
if ( ! * V_139 ) {
F_51 ( V_88 ) ;
return - V_15 ;
}
F_47 ( & V_76 ) ;
while ( 1 ) {
V_25 = F_89 ( V_137 , V_58 , V_107 ,
V_51 , V_88 , * V_139 , NULL , 0 , 0 ) ;
if ( V_25 < 0 && V_25 != - V_65 ) {
F_51 ( V_88 ) ;
F_51 ( * V_139 ) ;
return V_25 ;
}
V_68 = F_48 ( V_88 , & V_76 ) ;
if ( ! V_68 )
break;
V_107 = V_68 -> V_78 ;
F_91 () ;
}
F_51 ( V_88 ) ;
return 0 ;
}
int F_92 ( struct V_136 * V_137 ,
struct V_57 * V_58 , T_1 V_107 ,
T_1 V_51 , struct V_49 * * V_139 )
{
int V_25 ;
if ( ! V_137 )
F_93 ( & V_58 -> V_140 ) ;
V_25 = F_90 ( V_137 , V_58 , V_107 , V_51 , V_139 ) ;
if ( ! V_137 )
F_94 ( & V_58 -> V_140 ) ;
return V_25 ;
}
int F_95 ( struct V_136 * V_137 ,
struct V_57 * V_58 , T_1 V_70 ,
T_1 V_17 , T_1 V_107 )
{
struct V_49 * V_88 = NULL ;
struct V_49 * V_139 = NULL ;
struct V_75 V_76 ;
struct V_74 * V_68 ;
struct V_141 V_142 = F_96 ( V_142 ) ;
int V_25 = 0 ;
V_88 = F_45 ( V_14 ) ;
V_139 = F_45 ( V_14 ) ;
if ( ! V_88 || ! V_139 ) {
F_51 ( V_88 ) ;
F_51 ( V_139 ) ;
return - V_15 ;
}
if ( V_137 )
F_97 ( V_58 , & V_142 ) ;
else
F_93 ( & V_58 -> V_140 ) ;
F_47 ( & V_76 ) ;
while ( 1 ) {
V_25 = F_89 ( V_137 , V_58 , V_107 , V_142 . V_90 , V_88 ,
V_139 , NULL , V_70 , V_17 ) ;
if ( V_25 == V_77 ) {
V_25 = 1 ;
break;
}
if ( V_25 < 0 && V_25 != - V_65 )
break;
V_25 = 0 ;
V_68 = F_48 ( V_88 , & V_76 ) ;
if ( ! V_68 )
break;
V_107 = V_68 -> V_78 ;
F_91 () ;
}
if ( V_137 )
F_98 ( V_58 , & V_142 ) ;
else
F_94 ( & V_58 -> V_140 ) ;
F_51 ( V_88 ) ;
F_51 ( V_139 ) ;
return V_25 ;
}
int F_99 ( struct V_45 * V_46 , T_1 V_143 ,
T_1 V_144 , struct V_47 * V_48 ,
struct V_145 * * V_146 ,
T_1 * V_147 )
{
int V_25 , V_22 ;
struct V_1 V_2 ;
struct V_1 V_115 ;
struct V_145 * V_148 ;
struct V_3 * V_114 ;
unsigned long V_116 ;
V_2 . V_18 = V_143 ;
V_2 . type = V_149 ;
V_2 . V_10 = V_144 ;
V_25 = F_39 ( NULL , V_46 , & V_2 , V_48 , 0 , 0 ) ;
if ( V_25 < 0 )
return V_25 ;
while ( 1 ) {
V_114 = V_48 -> V_54 [ 0 ] ;
V_22 = V_48 -> V_56 [ 0 ] ;
if ( V_22 >= F_11 ( V_114 ) ) {
V_25 = F_25 ( V_46 , V_48 ) ;
if ( V_25 ) {
if ( V_25 >= 1 )
V_25 = - V_65 ;
break;
}
continue;
}
F_12 ( V_114 , & V_115 , V_22 ) ;
V_25 = - V_65 ;
if ( V_115 . V_18 != V_143 )
break;
if ( V_115 . type != V_149 )
break;
V_25 = 0 ;
V_116 = F_100 ( V_114 , V_48 -> V_56 [ 0 ] ) ;
V_148 = (struct V_145 * ) V_116 ;
* V_146 = V_148 ;
if ( V_147 )
* V_147 = V_115 . V_10 ;
break;
}
return V_25 ;
}
char * F_101 ( struct V_45 * V_150 , struct V_47 * V_48 ,
T_4 V_151 , unsigned long V_152 ,
struct V_3 * V_153 , T_1 V_36 ,
char * V_154 , T_4 V_155 )
{
int V_22 ;
T_1 V_156 ;
int V_25 ;
T_5 V_157 = ( ( T_5 ) V_155 ) - 1 ;
struct V_3 * V_4 = V_153 ;
struct V_1 V_115 ;
int V_158 = V_48 -> V_158 ;
struct V_159 * V_129 ;
if ( V_157 >= 0 )
V_154 [ V_157 ] = '\0' ;
V_48 -> V_158 = 1 ;
while ( 1 ) {
V_157 -= V_151 ;
if ( V_157 >= 0 )
F_102 ( V_4 , V_154 + V_157 ,
V_152 , V_151 ) ;
if ( V_4 != V_153 ) {
if ( ! V_48 -> V_160 )
F_103 ( V_4 ) ;
F_58 ( V_4 ) ;
}
V_25 = F_104 ( V_150 , V_48 , V_36 , 0 ,
V_161 , & V_115 ) ;
if ( V_25 > 0 )
V_25 = - V_65 ;
if ( V_25 )
break;
V_156 = V_115 . V_10 ;
if ( V_36 == V_156 )
break;
V_22 = V_48 -> V_56 [ 0 ] ;
V_4 = V_48 -> V_54 [ 0 ] ;
if ( V_4 != V_153 ) {
if ( ! V_48 -> V_160 )
F_105 ( V_4 , V_162 ) ;
V_48 -> V_54 [ 0 ] = NULL ;
V_48 -> V_163 [ 0 ] = 0 ;
}
F_43 ( V_48 ) ;
V_129 = F_13 ( V_4 , V_22 , struct V_159 ) ;
V_151 = F_106 ( V_4 , V_129 ) ;
V_152 = ( unsigned long ) ( V_129 + 1 ) ;
V_36 = V_156 ;
-- V_157 ;
if ( V_157 >= 0 )
V_154 [ V_157 ] = '/' ;
}
F_43 ( V_48 ) ;
V_48 -> V_158 = V_158 ;
if ( V_25 )
return F_107 ( V_25 ) ;
return V_154 + V_157 ;
}
int F_108 ( struct V_57 * V_58 , T_1 V_164 ,
struct V_47 * V_48 , struct V_1 * V_115 ,
T_1 * V_165 )
{
int V_25 ;
T_1 V_120 ;
T_1 V_155 = 0 ;
T_4 V_121 ;
struct V_3 * V_4 ;
struct V_118 * V_119 ;
struct V_1 V_2 ;
if ( F_109 ( V_58 , V_166 ) )
V_2 . type = V_126 ;
else
V_2 . type = V_122 ;
V_2 . V_18 = V_164 ;
V_2 . V_10 = ( T_1 ) - 1 ;
V_25 = F_39 ( NULL , V_58 -> V_134 , & V_2 , V_48 , 0 , 0 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_110 ( V_58 -> V_134 , V_48 , 0 ) ;
if ( V_25 ) {
if ( V_25 > 0 )
V_25 = - V_65 ;
return V_25 ;
}
F_12 ( V_48 -> V_54 [ 0 ] , V_115 , V_48 -> V_56 [ 0 ] ) ;
if ( V_115 -> type == V_126 )
V_155 = V_58 -> V_134 -> V_167 ;
else if ( V_115 -> type == V_122 )
V_155 = V_115 -> V_10 ;
if ( V_115 -> V_18 > V_164 ||
V_115 -> V_18 + V_155 <= V_164 ) {
F_41 ( L_4 , V_164 ) ;
return - V_65 ;
}
V_4 = V_48 -> V_54 [ 0 ] ;
V_121 = F_74 ( V_4 , V_48 -> V_56 [ 0 ] ) ;
F_55 ( V_121 < sizeof( * V_119 ) ) ;
V_119 = F_13 ( V_4 , V_48 -> V_56 [ 0 ] , struct V_118 ) ;
V_120 = F_75 ( V_4 , V_119 ) ;
F_41 ( L_5
L_6 ,
V_164 , V_164 - V_115 -> V_18 , V_115 -> V_18 ,
V_115 -> V_10 , V_120 , V_121 ) ;
F_42 ( ! V_165 ) ;
if ( V_165 ) {
if ( V_120 & V_123 )
* V_165 = V_123 ;
else if ( V_120 & V_127 )
* V_165 = V_127 ;
else
F_55 ( 1 ) ;
return 0 ;
}
return - V_84 ;
}
static int F_111 ( unsigned long * V_116 , struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_118 * V_119 , T_4 V_121 ,
struct V_128 * * V_168 ,
int * V_169 )
{
unsigned long V_117 ;
T_1 V_120 ;
struct V_124 * V_125 ;
if ( ! * V_116 ) {
V_120 = F_75 ( V_4 , V_119 ) ;
if ( V_120 & V_123 ) {
if ( V_2 -> type == V_126 ) {
* V_168 =
(struct V_128 * ) ( V_119 + 1 ) ;
} else {
F_42 ( V_2 -> type != V_122 ) ;
V_125 = (struct V_124 * ) ( V_119 + 1 ) ;
* V_168 =
(struct V_128 * ) ( V_125 + 1 ) ;
}
} else {
* V_168 = (struct V_128 * ) ( V_119 + 1 ) ;
}
* V_116 = ( unsigned long ) * V_168 ;
if ( ( unsigned long ) ( * V_116 ) >= ( unsigned long ) V_119 + V_121 )
return - V_65 ;
}
V_117 = ( unsigned long ) V_119 + V_121 ;
* V_168 = (struct V_128 * ) ( * V_116 ) ;
* V_169 = F_78 ( V_4 , * V_168 ) ;
* V_116 += F_85 ( * V_169 ) ;
F_42 ( * V_116 > V_117 ) ;
if ( * V_116 == V_117 )
return 1 ;
return 0 ;
}
int F_112 ( unsigned long * V_116 , struct V_3 * V_4 ,
struct V_1 * V_2 , struct V_118 * V_119 ,
T_4 V_121 , T_1 * V_170 , T_6 * V_171 )
{
int V_25 ;
int type ;
struct V_128 * V_172 ;
if ( * V_116 == ( unsigned long ) - 1 )
return 1 ;
while ( 1 ) {
V_25 = F_111 ( V_116 , V_4 , V_2 , V_119 , V_121 ,
& V_172 , & type ) ;
if ( V_25 < 0 )
return V_25 ;
if ( type == V_105 ||
type == V_109 )
break;
if ( V_25 == 1 )
return 1 ;
}
* V_170 = F_79 ( V_4 , V_172 ) ;
if ( V_2 -> type == V_122 ) {
struct V_124 * V_125 ;
V_125 = (struct V_124 * ) ( V_119 + 1 ) ;
* V_171 = F_77 ( V_4 , V_125 ) ;
} else {
ASSERT ( V_2 -> type == V_126 ) ;
* V_171 = ( T_6 ) V_2 -> V_10 ;
}
if ( V_25 == 1 )
* V_116 = ( unsigned long ) - 1 ;
return 0 ;
}
static int F_113 ( struct V_8 * V_43 ,
T_1 V_46 , T_1 V_173 ,
T_7 * V_174 , void * V_175 )
{
struct V_8 * V_9 ;
int V_25 = 0 ;
for ( V_9 = V_43 ; V_9 ; V_9 = V_9 -> V_16 ) {
F_41 ( L_7
L_8 , V_173 ,
V_9 -> V_17 , V_9 -> V_10 , V_46 ) ;
V_25 = V_174 ( V_9 -> V_17 , V_9 -> V_10 , V_46 , V_175 ) ;
if ( V_25 ) {
F_41 ( L_9 ,
V_173 , V_25 ) ;
break;
}
}
return V_25 ;
}
int F_114 ( struct V_57 * V_58 ,
T_1 V_173 , T_1 V_7 ,
int V_66 ,
T_7 * V_174 , void * V_175 )
{
int V_25 ;
struct V_136 * V_137 = NULL ;
struct V_49 * V_176 = NULL ;
struct V_49 * V_139 = NULL ;
struct V_74 * V_177 = NULL ;
struct V_74 * V_178 = NULL ;
struct V_141 V_179 = F_96 ( V_179 ) ;
struct V_75 V_180 ;
struct V_75 V_181 ;
F_41 ( L_10 ,
V_173 ) ;
if ( ! V_66 ) {
V_137 = F_115 ( V_58 -> V_134 ) ;
if ( F_33 ( V_137 ) )
return F_35 ( V_137 ) ;
F_97 ( V_58 , & V_179 ) ;
} else {
F_93 ( & V_58 -> V_140 ) ;
}
V_25 = F_88 ( V_137 , V_58 , V_173 ,
V_179 . V_90 , & V_176 ,
& V_7 ) ;
if ( V_25 )
goto V_64;
F_47 ( & V_180 ) ;
while ( ! V_25 && ( V_177 = F_48 ( V_176 , & V_180 ) ) ) {
V_25 = F_90 ( V_137 , V_58 , V_177 -> V_78 ,
V_179 . V_90 , & V_139 ) ;
if ( V_25 )
break;
F_47 ( & V_181 ) ;
while ( ! V_25 && ( V_178 = F_48 ( V_139 , & V_181 ) ) ) {
F_41 ( L_11
L_12 , V_178 -> V_78 , V_177 -> V_78 ,
V_177 -> V_80 ) ;
V_25 = F_113 ( (struct V_8 * )
( V_79 ) V_177 -> V_80 ,
V_178 -> V_78 ,
V_173 ,
V_174 , V_175 ) ;
}
F_51 ( V_139 ) ;
}
F_87 ( V_176 ) ;
V_64:
if ( ! V_66 ) {
F_98 ( V_58 , & V_179 ) ;
F_116 ( V_137 , V_58 -> V_134 ) ;
} else {
F_94 ( & V_58 -> V_140 ) ;
}
return V_25 ;
}
int F_117 ( T_1 V_164 , struct V_57 * V_58 ,
struct V_47 * V_48 ,
T_7 * V_174 , void * V_175 )
{
int V_25 ;
T_1 V_7 ;
T_1 V_120 = 0 ;
struct V_1 V_115 ;
int V_66 = V_48 -> V_66 ;
V_25 = F_108 ( V_58 , V_164 , V_48 , & V_115 , & V_120 ) ;
F_43 ( V_48 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_120 & V_123 )
return - V_182 ;
V_7 = V_164 - V_115 . V_18 ;
V_25 = F_114 ( V_58 , V_115 . V_18 ,
V_7 , V_66 ,
V_174 , V_175 ) ;
return V_25 ;
}
static int F_118 ( T_1 V_17 , struct V_45 * V_150 ,
struct V_47 * V_48 ,
T_8 * V_174 , void * V_175 )
{
int V_25 = 0 ;
int V_22 ;
T_4 V_183 ;
T_4 V_184 ;
T_4 V_151 ;
T_1 V_36 = 0 ;
int V_185 = 0 ;
struct V_3 * V_4 ;
struct V_186 * V_187 ;
struct V_159 * V_129 ;
struct V_1 V_115 ;
while ( ! V_25 ) {
V_25 = F_104 ( V_150 , V_48 , V_17 ,
V_36 ? V_36 + 1 : 0 , V_161 ,
& V_115 ) ;
if ( V_25 < 0 )
break;
if ( V_25 ) {
V_25 = V_185 ? 0 : - V_65 ;
break;
}
++ V_185 ;
V_36 = V_115 . V_10 ;
V_22 = V_48 -> V_56 [ 0 ] ;
V_4 = F_119 ( V_48 -> V_54 [ 0 ] ) ;
if ( ! V_4 ) {
V_25 = - V_15 ;
break;
}
F_120 ( V_4 ) ;
F_59 ( V_4 ) ;
F_105 ( V_4 , V_162 ) ;
F_43 ( V_48 ) ;
V_187 = F_121 ( V_22 ) ;
V_129 = F_13 ( V_4 , V_22 , struct V_159 ) ;
for ( V_183 = 0 ; V_183 < F_122 ( V_4 , V_187 ) ; V_183 += V_184 ) {
V_151 = F_106 ( V_4 , V_129 ) ;
F_41 ( L_13
L_14 , V_183 , V_115 . V_18 ,
V_150 -> V_18 ) ;
V_25 = V_174 ( V_36 , V_151 ,
( unsigned long ) ( V_129 + 1 ) , V_4 , V_175 ) ;
if ( V_25 )
break;
V_184 = sizeof( * V_129 ) + V_151 ;
V_129 = (struct V_159 * ) ( ( char * ) V_129 + V_184 ) ;
}
F_103 ( V_4 ) ;
F_58 ( V_4 ) ;
}
F_43 ( V_48 ) ;
return V_25 ;
}
static int F_123 ( T_1 V_17 , struct V_45 * V_150 ,
struct V_47 * V_48 ,
T_8 * V_174 , void * V_175 )
{
int V_25 ;
int V_22 ;
T_1 V_10 = 0 ;
T_1 V_36 ;
int V_185 = 0 ;
struct V_3 * V_4 ;
struct V_145 * V_148 ;
T_4 V_121 ;
T_4 V_188 ;
unsigned long V_116 ;
while ( 1 ) {
V_25 = F_99 ( V_150 , V_17 , V_10 , V_48 , & V_148 ,
& V_10 ) ;
if ( V_25 < 0 )
break;
if ( V_25 ) {
V_25 = V_185 ? 0 : - V_65 ;
break;
}
++ V_185 ;
V_22 = V_48 -> V_56 [ 0 ] ;
V_4 = F_119 ( V_48 -> V_54 [ 0 ] ) ;
if ( ! V_4 ) {
V_25 = - V_15 ;
break;
}
F_120 ( V_4 ) ;
F_59 ( V_4 ) ;
F_105 ( V_4 , V_162 ) ;
F_43 ( V_48 ) ;
V_121 = F_74 ( V_4 , V_22 ) ;
V_116 = F_100 ( V_4 , V_22 ) ;
V_188 = 0 ;
while ( V_188 < V_121 ) {
T_4 V_151 ;
V_148 = (struct V_145 * ) ( V_116 + V_188 ) ;
V_36 = F_124 ( V_4 , V_148 ) ;
V_151 = F_125 ( V_4 , V_148 ) ;
V_25 = V_174 ( V_36 , V_151 ,
( unsigned long ) & V_148 -> V_189 , V_4 , V_175 ) ;
if ( V_25 )
break;
V_188 += F_125 ( V_4 , V_148 ) ;
V_188 += sizeof( * V_148 ) ;
}
F_103 ( V_4 ) ;
F_58 ( V_4 ) ;
V_10 ++ ;
}
F_43 ( V_48 ) ;
return V_25 ;
}
static int F_126 ( T_1 V_17 , struct V_45 * V_150 ,
struct V_47 * V_48 , T_8 * V_174 ,
void * V_175 )
{
int V_25 ;
int V_190 = 0 ;
V_25 = F_118 ( V_17 , V_150 , V_48 , V_174 , V_175 ) ;
if ( ! V_25 )
++ V_190 ;
else if ( V_25 != - V_65 )
return V_25 ;
V_25 = F_123 ( V_17 , V_150 , V_48 , V_174 , V_175 ) ;
if ( V_25 == - V_65 && V_190 )
return 0 ;
return V_25 ;
}
static int F_127 ( T_1 V_17 , T_4 V_151 , unsigned long V_152 ,
struct V_3 * V_4 , void * V_175 )
{
struct V_191 * V_192 = V_175 ;
char * V_193 ;
char * V_194 ;
int V_195 = V_192 -> V_193 -> V_196 ;
const int V_197 = sizeof( char * ) ;
T_4 V_157 ;
V_157 = V_192 -> V_193 -> V_157 > V_197 ?
V_192 -> V_193 -> V_157 - V_197 : 0 ;
V_194 = ( char * ) V_192 -> V_193 -> V_78 + ( V_195 + 1 ) * V_197 ;
V_193 = F_101 ( V_192 -> V_150 , V_192 -> V_47 , V_151 ,
V_152 , V_4 , V_17 , V_194 , V_157 ) ;
if ( F_33 ( V_193 ) )
return F_35 ( V_193 ) ;
if ( V_193 > V_194 ) {
V_192 -> V_193 -> V_78 [ V_195 ] = ( T_1 ) ( unsigned long ) V_193 ;
++ V_192 -> V_193 -> V_196 ;
V_192 -> V_193 -> V_157 = V_193 - V_194 ;
} else {
++ V_192 -> V_193 -> V_198 ;
V_192 -> V_193 -> V_199 += V_194 - V_193 ;
V_192 -> V_193 -> V_157 = 0 ;
}
return 0 ;
}
int F_128 ( T_1 V_17 , struct V_191 * V_192 )
{
return F_126 ( V_17 , V_192 -> V_150 , V_192 -> V_47 ,
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
V_202 -> V_157 = V_201 - sizeof( * V_202 ) ;
V_202 -> V_199 = 0 ;
} else {
V_202 -> V_199 = sizeof( * V_202 ) - V_201 ;
V_202 -> V_157 = 0 ;
}
V_202 -> V_196 = 0 ;
V_202 -> V_198 = 0 ;
return V_202 ;
}
struct V_191 * F_132 ( T_10 V_201 , struct V_45 * V_150 ,
struct V_47 * V_48 )
{
struct V_191 * V_204 ;
struct V_200 * V_193 ;
V_193 = F_129 ( V_201 ) ;
if ( F_33 ( V_193 ) )
return ( void * ) V_193 ;
V_204 = F_7 ( sizeof( * V_204 ) , V_14 ) ;
if ( ! V_204 ) {
F_133 ( V_193 ) ;
return F_107 ( - V_15 ) ;
}
V_204 -> V_47 = V_48 ;
V_204 -> V_193 = V_193 ;
V_204 -> V_150 = V_150 ;
return V_204 ;
}
void F_134 ( struct V_191 * V_192 )
{
if ( ! V_192 )
return;
F_133 ( V_192 -> V_193 ) ;
F_9 ( V_192 ) ;
}
