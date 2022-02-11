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
V_30 ,
NULL ) ;
if ( ! V_28 )
return - V_15 ;
return 0 ;
}
void F_18 ( void )
{
F_19 ( V_28 ) ;
}
static int F_20 ( struct V_31 * V_32 , T_1 V_33 ,
struct V_1 * V_2 , int V_34 ,
T_1 V_35 , T_1 V_20 , int V_36 ,
T_3 V_37 )
{
struct V_29 * V_38 ;
if ( V_33 == V_39 )
return 0 ;
V_38 = F_21 ( V_28 , V_37 ) ;
if ( ! V_38 )
return - V_15 ;
V_38 -> V_33 = V_33 ;
if ( V_2 ) {
V_38 -> V_40 = * V_2 ;
if ( V_38 -> V_40 . type == V_26 &&
V_38 -> V_40 . V_10 >= V_41 )
V_38 -> V_40 . V_10 = 0 ;
} else {
memset ( & V_38 -> V_40 , 0 , sizeof( V_38 -> V_40 ) ) ;
}
V_38 -> V_42 = NULL ;
V_38 -> V_34 = V_34 ;
V_38 -> V_36 = V_36 ;
V_38 -> V_35 = V_35 ;
V_38 -> V_20 = V_20 ;
F_22 ( & V_38 -> V_43 , V_32 ) ;
return 0 ;
}
static int F_23 ( struct V_44 * V_45 , struct V_46 * V_47 ,
struct V_48 * V_49 , struct V_29 * V_38 ,
int V_34 , T_1 V_50 , const T_1 * V_7 ,
T_1 V_51 )
{
int V_25 = 0 ;
int V_22 ;
struct V_3 * V_4 ;
struct V_1 V_2 ;
struct V_1 * V_40 = & V_38 -> V_40 ;
struct V_5 * V_6 ;
struct V_8 * V_9 = NULL , * V_52 = NULL ;
T_1 V_21 ;
T_1 V_20 = V_38 -> V_20 ;
T_1 V_36 = 0 ;
if ( V_34 != 0 ) {
V_4 = V_47 -> V_53 [ V_34 ] ;
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
while ( ! V_25 && V_36 < V_51 ) {
V_4 = V_47 -> V_53 [ 0 ] ;
V_22 = V_47 -> V_55 [ 0 ] ;
F_12 ( V_4 , & V_2 , V_22 ) ;
if ( V_2 . V_18 != V_40 -> V_18 ||
V_2 . type != V_26 )
break;
V_6 = F_13 ( V_4 , V_22 , struct V_5 ) ;
V_21 = F_15 ( V_4 , V_6 ) ;
if ( V_21 == V_20 ) {
V_9 = NULL ;
V_52 = NULL ;
V_36 ++ ;
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
struct V_29 * V_38 ,
struct V_48 * V_49 ,
const T_1 * V_7 , T_1 V_51 )
{
struct V_44 * V_45 ;
struct V_1 V_58 ;
struct V_3 * V_4 ;
int V_25 = 0 ;
int V_59 ;
int V_34 = V_38 -> V_34 ;
int V_60 ;
V_58 . V_18 = V_38 -> V_33 ;
V_58 . type = V_61 ;
V_58 . V_10 = ( T_1 ) - 1 ;
V_60 = F_31 ( & V_57 -> V_62 ) ;
V_45 = F_32 ( V_57 , & V_58 , false ) ;
if ( F_33 ( V_45 ) ) {
F_34 ( & V_57 -> V_62 , V_60 ) ;
V_25 = F_35 ( V_45 ) ;
goto V_63;
}
if ( F_36 ( V_57 ) ) {
F_34 ( & V_57 -> V_62 , V_60 ) ;
V_25 = - V_64 ;
goto V_63;
}
if ( V_47 -> V_65 )
V_59 = F_37 ( V_45 -> V_66 ) ;
else if ( V_50 == ( T_1 ) - 1 )
V_59 = F_37 ( V_45 -> V_67 ) ;
else
V_59 = F_38 ( V_45 , V_50 ) ;
if ( V_59 + 1 == V_34 ) {
F_34 ( & V_57 -> V_62 , V_60 ) ;
goto V_63;
}
V_47 -> V_68 = V_34 ;
if ( V_50 == ( T_1 ) - 1 )
V_25 = F_39 ( NULL , V_45 , & V_38 -> V_40 , V_47 ,
0 , 0 ) ;
else
V_25 = F_40 ( V_45 , & V_38 -> V_40 , V_47 ,
V_50 ) ;
F_34 ( & V_57 -> V_62 , V_60 ) ;
F_41 ( L_2
L_3 ,
V_38 -> V_33 , V_34 , V_38 -> V_36 , V_25 ,
V_38 -> V_40 . V_18 , V_38 -> V_40 . type ,
V_38 -> V_40 . V_10 ) ;
if ( V_25 < 0 )
goto V_63;
V_4 = V_47 -> V_53 [ V_34 ] ;
while ( ! V_4 ) {
if ( F_42 ( ! V_34 ) ) {
V_25 = 1 ;
goto V_63;
}
V_34 -- ;
V_4 = V_47 -> V_53 [ V_34 ] ;
}
V_25 = F_23 ( V_45 , V_47 , V_49 , V_38 , V_34 , V_50 ,
V_7 , V_51 ) ;
V_63:
V_47 -> V_68 = 0 ;
F_43 ( V_47 ) ;
return V_25 ;
}
static int F_44 ( struct V_56 * V_57 ,
struct V_46 * V_47 , T_1 V_50 ,
struct V_31 * V_32 ,
const T_1 * V_7 , T_1 V_51 ,
T_1 V_69 )
{
int V_70 ;
int V_25 = 0 ;
struct V_29 * V_38 ;
struct V_29 * V_71 ;
struct V_29 * V_72 ;
struct V_48 * V_49 ;
struct V_73 * V_67 ;
struct V_74 V_75 ;
V_49 = F_45 ( V_14 ) ;
if ( ! V_49 )
return - V_15 ;
F_46 (ref, ref_safe, head, list) {
if ( V_38 -> V_35 )
continue;
if ( V_38 -> V_36 == 0 )
continue;
if ( V_69 && V_38 -> V_33 != V_69 ) {
V_25 = V_76 ;
goto V_63;
}
V_70 = F_30 ( V_57 , V_47 , V_50 , V_38 ,
V_49 , V_7 ,
V_51 ) ;
if ( V_70 == - V_64 ) {
continue;
} else if ( V_70 ) {
V_25 = V_70 ;
goto V_63;
}
F_47 ( & V_75 ) ;
V_67 = F_48 ( V_49 , & V_75 ) ;
V_38 -> V_35 = V_67 ? V_67 -> V_77 : 0 ;
V_38 -> V_42 = V_67 ?
(struct V_8 * ) ( V_78 ) V_67 -> V_79 : NULL ;
while ( ( V_67 = F_48 ( V_49 , & V_75 ) ) ) {
V_72 = F_21 ( V_28 ,
V_14 ) ;
if ( ! V_72 ) {
V_25 = - V_15 ;
goto V_63;
}
memcpy ( V_72 , V_38 , sizeof( * V_38 ) ) ;
V_72 -> V_35 = V_67 -> V_77 ;
V_72 -> V_42 = (struct V_8 * )
( V_78 ) V_67 -> V_79 ;
F_49 ( & V_72 -> V_43 , & V_38 -> V_43 ) ;
}
F_50 ( V_49 ) ;
}
V_63:
F_51 ( V_49 ) ;
return V_25 ;
}
static inline int F_52 ( struct V_29 * V_80 ,
struct V_29 * V_81 )
{
if ( V_80 -> V_34 != V_81 -> V_34 )
return 0 ;
if ( V_80 -> V_33 != V_81 -> V_33 )
return 0 ;
if ( V_80 -> V_40 . type != V_81 -> V_40 . type )
return 0 ;
if ( V_80 -> V_40 . V_18 != V_81 -> V_40 . V_18 )
return 0 ;
if ( V_80 -> V_40 . V_10 != V_81 -> V_40 . V_10 )
return 0 ;
if ( V_80 -> V_35 != V_81 -> V_35 )
return 0 ;
return 1 ;
}
static int F_53 ( struct V_56 * V_57 ,
struct V_31 * V_32 )
{
struct V_29 * V_38 ;
struct V_3 * V_4 ;
F_54 (ref, head, list) {
if ( V_38 -> V_35 )
continue;
if ( V_38 -> V_40 . type )
continue;
F_55 ( ! V_38 -> V_20 ) ;
V_4 = F_56 ( V_57 -> V_82 , V_38 -> V_20 ,
0 ) ;
if ( F_33 ( V_4 ) ) {
return F_35 ( V_4 ) ;
} else if ( ! F_57 ( V_4 ) ) {
F_58 ( V_4 ) ;
return - V_83 ;
}
F_59 ( V_4 ) ;
if ( F_37 ( V_4 ) == 0 )
F_12 ( V_4 , & V_38 -> V_40 , 0 ) ;
else
F_60 ( V_4 , & V_38 -> V_40 , 0 ) ;
F_61 ( V_4 ) ;
F_58 ( V_4 ) ;
}
return 0 ;
}
static void F_62 ( struct V_31 * V_32 , int V_84 )
{
struct V_29 * V_85 ;
F_54 (pos1, head, list) {
struct V_29 * V_86 = V_85 , * V_87 ;
F_63 (pos2, tmp, head, list) {
struct V_29 * V_80 = V_85 , * V_81 = V_86 ;
struct V_8 * V_9 ;
if ( ! F_52 ( V_80 , V_81 ) )
continue;
if ( V_84 == 1 ) {
if ( ! V_80 -> V_35 && V_81 -> V_35 )
F_64 ( V_80 , V_81 ) ;
} else {
if ( V_80 -> V_35 != V_81 -> V_35 )
continue;
}
V_9 = V_80 -> V_42 ;
while ( V_9 && V_9 -> V_16 )
V_9 = V_9 -> V_16 ;
if ( V_9 )
V_9 -> V_16 = V_81 -> V_42 ;
else
V_80 -> V_42 = V_81 -> V_42 ;
V_80 -> V_36 += V_81 -> V_36 ;
F_65 ( & V_81 -> V_43 ) ;
F_66 ( V_28 , V_81 ) ;
F_67 () ;
}
}
}
static int F_68 ( struct V_88 * V_32 , T_1 V_89 ,
struct V_31 * V_90 , T_1 * V_51 ,
T_1 V_17 )
{
struct V_91 * V_67 ;
struct V_92 * V_93 = V_32 -> V_93 ;
struct V_1 V_2 ;
struct V_1 V_94 = { 0 } ;
int V_95 ;
int V_25 = 0 ;
if ( V_93 && V_93 -> V_96 )
F_69 ( & V_94 , & V_93 -> V_2 ) ;
F_70 ( & V_32 -> V_97 ) ;
F_54 (node, &head->ref_list, list) {
if ( V_67 -> V_89 > V_89 )
continue;
switch ( V_67 -> V_98 ) {
case V_99 :
case V_100 :
F_42 ( 1 ) ;
continue;
case V_101 :
V_95 = 1 ;
break;
case V_102 :
V_95 = - 1 ;
break;
default:
F_55 ( 1 ) ;
}
* V_51 += ( V_67 -> V_103 * V_95 ) ;
switch ( V_67 -> type ) {
case V_104 : {
struct V_105 * V_38 ;
V_38 = F_71 ( V_67 ) ;
V_25 = F_20 ( V_90 , V_38 -> V_45 , & V_94 ,
V_38 -> V_34 + 1 , 0 , V_67 -> V_106 ,
V_67 -> V_103 * V_95 , V_107 ) ;
break;
}
case V_108 : {
struct V_105 * V_38 ;
V_38 = F_71 ( V_67 ) ;
V_25 = F_20 ( V_90 , 0 , NULL ,
V_38 -> V_34 + 1 , V_38 -> V_35 ,
V_67 -> V_106 ,
V_67 -> V_103 * V_95 , V_107 ) ;
break;
}
case V_109 : {
struct V_110 * V_38 ;
V_38 = F_72 ( V_67 ) ;
V_2 . V_18 = V_38 -> V_18 ;
V_2 . type = V_26 ;
V_2 . V_10 = V_38 -> V_10 ;
if ( V_17 && V_38 -> V_18 != V_17 ) {
V_25 = V_76 ;
break;
}
V_25 = F_20 ( V_90 , V_38 -> V_45 , & V_2 , 0 , 0 ,
V_67 -> V_106 ,
V_67 -> V_103 * V_95 , V_107 ) ;
break;
}
case V_111 : {
struct V_110 * V_38 ;
V_38 = F_72 ( V_67 ) ;
V_25 = F_20 ( V_90 , 0 , NULL , 0 ,
V_38 -> V_35 , V_67 -> V_106 ,
V_67 -> V_103 * V_95 , V_107 ) ;
break;
}
default:
F_42 ( 1 ) ;
}
if ( V_25 )
break;
}
F_73 ( & V_32 -> V_97 ) ;
return V_25 ;
}
static int F_74 ( struct V_56 * V_57 ,
struct V_46 * V_47 , T_1 V_106 ,
int * V_112 , struct V_31 * V_90 ,
T_1 * V_51 , T_1 V_17 )
{
int V_25 = 0 ;
int V_22 ;
struct V_3 * V_113 ;
struct V_1 V_2 ;
struct V_1 V_114 ;
unsigned long V_115 ;
unsigned long V_116 ;
struct V_117 * V_118 ;
T_1 V_119 ;
T_1 V_120 ;
V_113 = V_47 -> V_53 [ 0 ] ;
V_22 = V_47 -> V_55 [ 0 ] ;
V_120 = F_75 ( V_113 , V_22 ) ;
F_55 ( V_120 < sizeof( * V_118 ) ) ;
V_118 = F_13 ( V_113 , V_22 , struct V_117 ) ;
V_119 = F_76 ( V_113 , V_118 ) ;
* V_51 += F_77 ( V_113 , V_118 ) ;
F_12 ( V_113 , & V_114 , V_22 ) ;
V_115 = ( unsigned long ) ( V_118 + 1 ) ;
V_116 = ( unsigned long ) V_118 + V_120 ;
if ( V_114 . type == V_121 &&
V_119 & V_122 ) {
struct V_123 * V_124 ;
V_124 = (struct V_123 * ) V_115 ;
* V_112 = F_78 ( V_113 , V_124 ) ;
V_115 += sizeof( struct V_123 ) ;
F_55 ( V_115 > V_116 ) ;
} else if ( V_114 . type == V_125 ) {
* V_112 = V_114 . V_10 ;
} else {
F_55 ( ! ( V_119 & V_126 ) ) ;
}
while ( V_115 < V_116 ) {
struct V_127 * V_128 ;
T_1 V_10 ;
int type ;
V_128 = (struct V_127 * ) V_115 ;
type = F_79 ( V_113 , V_128 ) ;
V_10 = F_80 ( V_113 , V_128 ) ;
switch ( type ) {
case V_108 :
V_25 = F_20 ( V_90 , 0 , NULL ,
* V_112 + 1 , V_10 ,
V_106 , 1 , V_14 ) ;
break;
case V_111 : {
struct V_129 * V_130 ;
int V_36 ;
V_130 = (struct V_129 * ) ( V_128 + 1 ) ;
V_36 = F_81 ( V_113 , V_130 ) ;
V_25 = F_20 ( V_90 , 0 , NULL , 0 , V_10 ,
V_106 , V_36 , V_14 ) ;
break;
}
case V_104 :
V_25 = F_20 ( V_90 , V_10 , NULL ,
* V_112 + 1 , 0 ,
V_106 , 1 , V_14 ) ;
break;
case V_109 : {
struct V_131 * V_132 ;
int V_36 ;
T_1 V_45 ;
V_132 = (struct V_131 * ) ( & V_128 -> V_10 ) ;
V_36 = F_82 ( V_113 , V_132 ) ;
V_2 . V_18 = F_83 ( V_113 ,
V_132 ) ;
V_2 . type = V_26 ;
V_2 . V_10 = F_84 ( V_113 , V_132 ) ;
if ( V_17 && V_2 . V_18 != V_17 ) {
V_25 = V_76 ;
break;
}
V_45 = F_85 ( V_113 , V_132 ) ;
V_25 = F_20 ( V_90 , V_45 , & V_2 , 0 , 0 ,
V_106 , V_36 , V_14 ) ;
break;
}
default:
F_42 ( 1 ) ;
}
if ( V_25 )
return V_25 ;
V_115 += F_86 ( type ) ;
}
return 0 ;
}
static int F_87 ( struct V_56 * V_57 ,
struct V_46 * V_47 , T_1 V_106 ,
int V_112 , struct V_31 * V_90 , T_1 V_17 )
{
struct V_44 * V_133 = V_57 -> V_133 ;
int V_25 ;
int V_22 ;
struct V_3 * V_113 ;
struct V_1 V_2 ;
while ( 1 ) {
V_25 = F_28 ( V_133 , V_47 ) ;
if ( V_25 < 0 )
break;
if ( V_25 ) {
V_25 = 0 ;
break;
}
V_22 = V_47 -> V_55 [ 0 ] ;
V_113 = V_47 -> V_53 [ 0 ] ;
F_12 ( V_113 , & V_2 , V_22 ) ;
if ( V_2 . V_18 != V_106 )
break;
if ( V_2 . type < V_104 )
continue;
if ( V_2 . type > V_111 )
break;
switch ( V_2 . type ) {
case V_108 :
V_25 = F_20 ( V_90 , 0 , NULL ,
V_112 + 1 , V_2 . V_10 ,
V_106 , 1 , V_14 ) ;
break;
case V_111 : {
struct V_129 * V_130 ;
int V_36 ;
V_130 = F_13 ( V_113 , V_22 ,
struct V_129 ) ;
V_36 = F_81 ( V_113 , V_130 ) ;
V_25 = F_20 ( V_90 , 0 , NULL , 0 , V_2 . V_10 ,
V_106 , V_36 , V_14 ) ;
break;
}
case V_104 :
V_25 = F_20 ( V_90 , V_2 . V_10 , NULL ,
V_112 + 1 , 0 ,
V_106 , 1 , V_14 ) ;
break;
case V_109 : {
struct V_131 * V_132 ;
int V_36 ;
T_1 V_45 ;
V_132 = F_13 ( V_113 , V_22 ,
struct V_131 ) ;
V_36 = F_82 ( V_113 , V_132 ) ;
V_2 . V_18 = F_83 ( V_113 ,
V_132 ) ;
V_2 . type = V_26 ;
V_2 . V_10 = F_84 ( V_113 , V_132 ) ;
if ( V_17 && V_2 . V_18 != V_17 ) {
V_25 = V_76 ;
break;
}
V_45 = F_85 ( V_113 , V_132 ) ;
V_25 = F_20 ( V_90 , V_45 , & V_2 , 0 , 0 ,
V_106 , V_36 , V_14 ) ;
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
static void F_88 ( struct V_48 * V_134 )
{
struct V_73 * V_67 = NULL ;
struct V_8 * V_9 ;
struct V_74 V_75 ;
F_47 ( & V_75 ) ;
while ( ( V_67 = F_48 ( V_134 , & V_75 ) ) ) {
if ( ! V_67 -> V_79 )
continue;
V_9 = (struct V_8 * ) ( V_78 ) V_67 -> V_79 ;
F_8 ( V_9 ) ;
V_67 -> V_79 = 0 ;
}
F_51 ( V_134 ) ;
}
static int F_89 ( struct V_135 * V_136 ,
struct V_56 * V_57 , T_1 V_106 ,
T_1 V_50 , struct V_48 * * V_137 ,
const T_1 * V_7 )
{
int V_25 ;
* V_137 = F_45 ( V_14 ) ;
if ( ! * V_137 )
return - V_15 ;
V_25 = F_90 ( V_136 , V_57 , V_106 ,
V_50 , * V_137 , NULL , V_7 , 0 , 0 ) ;
if ( V_25 < 0 && V_25 != - V_64 ) {
F_88 ( * V_137 ) ;
return V_25 ;
}
return 0 ;
}
static int F_91 ( struct V_135 * V_136 ,
struct V_56 * V_57 , T_1 V_106 ,
T_1 V_50 , struct V_48 * * V_138 )
{
struct V_48 * V_87 ;
struct V_73 * V_67 = NULL ;
struct V_74 V_75 ;
int V_25 ;
V_87 = F_45 ( V_14 ) ;
if ( ! V_87 )
return - V_15 ;
* V_138 = F_45 ( V_14 ) ;
if ( ! * V_138 ) {
F_51 ( V_87 ) ;
return - V_15 ;
}
F_47 ( & V_75 ) ;
while ( 1 ) {
V_25 = F_90 ( V_136 , V_57 , V_106 ,
V_50 , V_87 , * V_138 , NULL , 0 , 0 ) ;
if ( V_25 < 0 && V_25 != - V_64 ) {
F_51 ( V_87 ) ;
F_51 ( * V_138 ) ;
return V_25 ;
}
V_67 = F_48 ( V_87 , & V_75 ) ;
if ( ! V_67 )
break;
V_106 = V_67 -> V_77 ;
F_67 () ;
}
F_51 ( V_87 ) ;
return 0 ;
}
int F_92 ( struct V_135 * V_136 ,
struct V_56 * V_57 , T_1 V_106 ,
T_1 V_50 , struct V_48 * * V_138 )
{
int V_25 ;
if ( ! V_136 )
F_93 ( & V_57 -> V_139 ) ;
V_25 = F_91 ( V_136 , V_57 , V_106 , V_50 , V_138 ) ;
if ( ! V_136 )
F_94 ( & V_57 -> V_139 ) ;
return V_25 ;
}
int F_95 ( struct V_135 * V_136 ,
struct V_56 * V_57 , T_1 V_69 ,
T_1 V_17 , T_1 V_106 )
{
struct V_48 * V_87 = NULL ;
struct V_48 * V_138 = NULL ;
struct V_74 V_75 ;
struct V_73 * V_67 ;
struct V_140 V_141 = F_96 ( V_141 ) ;
int V_25 = 0 ;
V_87 = F_45 ( V_14 ) ;
V_138 = F_45 ( V_14 ) ;
if ( ! V_87 || ! V_138 ) {
F_51 ( V_87 ) ;
F_51 ( V_138 ) ;
return - V_15 ;
}
if ( V_136 )
F_97 ( V_57 , & V_141 ) ;
else
F_93 ( & V_57 -> V_139 ) ;
F_47 ( & V_75 ) ;
while ( 1 ) {
V_25 = F_90 ( V_136 , V_57 , V_106 , V_141 . V_89 , V_87 ,
V_138 , NULL , V_69 , V_17 ) ;
if ( V_25 == V_76 ) {
V_25 = 1 ;
break;
}
if ( V_25 < 0 && V_25 != - V_64 )
break;
V_25 = 0 ;
V_67 = F_48 ( V_87 , & V_75 ) ;
if ( ! V_67 )
break;
V_106 = V_67 -> V_77 ;
F_67 () ;
}
if ( V_136 )
F_98 ( V_57 , & V_141 ) ;
else
F_94 ( & V_57 -> V_139 ) ;
F_51 ( V_87 ) ;
F_51 ( V_138 ) ;
return V_25 ;
}
int F_99 ( struct V_44 * V_45 , T_1 V_142 ,
T_1 V_143 , struct V_46 * V_47 ,
struct V_144 * * V_145 ,
T_1 * V_146 )
{
int V_25 , V_22 ;
struct V_1 V_2 ;
struct V_1 V_114 ;
struct V_144 * V_147 ;
struct V_3 * V_113 ;
unsigned long V_115 ;
V_2 . V_18 = V_142 ;
V_2 . type = V_148 ;
V_2 . V_10 = V_143 ;
V_25 = F_39 ( NULL , V_45 , & V_2 , V_47 , 0 , 0 ) ;
if ( V_25 < 0 )
return V_25 ;
while ( 1 ) {
V_113 = V_47 -> V_53 [ 0 ] ;
V_22 = V_47 -> V_55 [ 0 ] ;
if ( V_22 >= F_11 ( V_113 ) ) {
V_25 = F_25 ( V_45 , V_47 ) ;
if ( V_25 ) {
if ( V_25 >= 1 )
V_25 = - V_64 ;
break;
}
continue;
}
F_12 ( V_113 , & V_114 , V_22 ) ;
V_25 = - V_64 ;
if ( V_114 . V_18 != V_142 )
break;
if ( V_114 . type != V_148 )
break;
V_25 = 0 ;
V_115 = F_100 ( V_113 , V_47 -> V_55 [ 0 ] ) ;
V_147 = (struct V_144 * ) V_115 ;
* V_145 = V_147 ;
if ( V_146 )
* V_146 = V_114 . V_10 ;
break;
}
return V_25 ;
}
char * F_101 ( struct V_44 * V_149 , struct V_46 * V_47 ,
T_4 V_150 , unsigned long V_151 ,
struct V_3 * V_152 , T_1 V_35 ,
char * V_153 , T_4 V_154 )
{
int V_22 ;
T_1 V_155 ;
int V_25 ;
T_5 V_156 = ( ( T_5 ) V_154 ) - 1 ;
struct V_3 * V_4 = V_152 ;
struct V_1 V_114 ;
int V_157 = V_47 -> V_157 ;
struct V_158 * V_128 ;
if ( V_156 >= 0 )
V_153 [ V_156 ] = '\0' ;
V_47 -> V_157 = 1 ;
while ( 1 ) {
V_156 -= V_150 ;
if ( V_156 >= 0 )
F_102 ( V_4 , V_153 + V_156 ,
V_151 , V_150 ) ;
if ( V_4 != V_152 ) {
if ( ! V_47 -> V_159 )
F_103 ( V_4 ) ;
F_58 ( V_4 ) ;
}
V_25 = F_104 ( V_149 , V_47 , V_35 , 0 ,
V_160 , & V_114 ) ;
if ( V_25 > 0 )
V_25 = - V_64 ;
if ( V_25 )
break;
V_155 = V_114 . V_10 ;
if ( V_35 == V_155 )
break;
V_22 = V_47 -> V_55 [ 0 ] ;
V_4 = V_47 -> V_53 [ 0 ] ;
if ( V_4 != V_152 ) {
if ( ! V_47 -> V_159 )
F_105 ( V_4 , V_161 ) ;
V_47 -> V_53 [ 0 ] = NULL ;
V_47 -> V_162 [ 0 ] = 0 ;
}
F_43 ( V_47 ) ;
V_128 = F_13 ( V_4 , V_22 , struct V_158 ) ;
V_150 = F_106 ( V_4 , V_128 ) ;
V_151 = ( unsigned long ) ( V_128 + 1 ) ;
V_35 = V_155 ;
-- V_156 ;
if ( V_156 >= 0 )
V_153 [ V_156 ] = '/' ;
}
F_43 ( V_47 ) ;
V_47 -> V_157 = V_157 ;
if ( V_25 )
return F_107 ( V_25 ) ;
return V_153 + V_156 ;
}
int F_108 ( struct V_56 * V_57 , T_1 V_163 ,
struct V_46 * V_47 , struct V_1 * V_114 ,
T_1 * V_164 )
{
int V_25 ;
T_1 V_119 ;
T_1 V_154 = 0 ;
T_4 V_120 ;
struct V_3 * V_4 ;
struct V_117 * V_118 ;
struct V_1 V_2 ;
if ( F_109 ( V_57 , V_165 ) )
V_2 . type = V_125 ;
else
V_2 . type = V_121 ;
V_2 . V_18 = V_163 ;
V_2 . V_10 = ( T_1 ) - 1 ;
V_25 = F_39 ( NULL , V_57 -> V_133 , & V_2 , V_47 , 0 , 0 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_110 ( V_57 -> V_133 , V_47 , 0 ) ;
if ( V_25 ) {
if ( V_25 > 0 )
V_25 = - V_64 ;
return V_25 ;
}
F_12 ( V_47 -> V_53 [ 0 ] , V_114 , V_47 -> V_55 [ 0 ] ) ;
if ( V_114 -> type == V_125 )
V_154 = V_57 -> V_133 -> V_166 ;
else if ( V_114 -> type == V_121 )
V_154 = V_114 -> V_10 ;
if ( V_114 -> V_18 > V_163 ||
V_114 -> V_18 + V_154 <= V_163 ) {
F_41 ( L_4 , V_163 ) ;
return - V_64 ;
}
V_4 = V_47 -> V_53 [ 0 ] ;
V_120 = F_75 ( V_4 , V_47 -> V_55 [ 0 ] ) ;
F_55 ( V_120 < sizeof( * V_118 ) ) ;
V_118 = F_13 ( V_4 , V_47 -> V_55 [ 0 ] , struct V_117 ) ;
V_119 = F_76 ( V_4 , V_118 ) ;
F_41 ( L_5
L_6 ,
V_163 , V_163 - V_114 -> V_18 , V_114 -> V_18 ,
V_114 -> V_10 , V_119 , V_120 ) ;
F_42 ( ! V_164 ) ;
if ( V_164 ) {
if ( V_119 & V_122 )
* V_164 = V_122 ;
else if ( V_119 & V_126 )
* V_164 = V_126 ;
else
F_55 ( 1 ) ;
return 0 ;
}
return - V_83 ;
}
static int F_111 ( unsigned long * V_115 , struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_117 * V_118 , T_4 V_120 ,
struct V_127 * * V_167 ,
int * V_168 )
{
unsigned long V_116 ;
T_1 V_119 ;
struct V_123 * V_124 ;
if ( ! * V_115 ) {
V_119 = F_76 ( V_4 , V_118 ) ;
if ( V_119 & V_122 ) {
if ( V_2 -> type == V_125 ) {
* V_167 =
(struct V_127 * ) ( V_118 + 1 ) ;
} else {
F_42 ( V_2 -> type != V_121 ) ;
V_124 = (struct V_123 * ) ( V_118 + 1 ) ;
* V_167 =
(struct V_127 * ) ( V_124 + 1 ) ;
}
} else {
* V_167 = (struct V_127 * ) ( V_118 + 1 ) ;
}
* V_115 = ( unsigned long ) * V_167 ;
if ( ( unsigned long ) ( * V_115 ) >= ( unsigned long ) V_118 + V_120 )
return - V_64 ;
}
V_116 = ( unsigned long ) V_118 + V_120 ;
* V_167 = (struct V_127 * ) ( * V_115 ) ;
* V_168 = F_79 ( V_4 , * V_167 ) ;
* V_115 += F_86 ( * V_168 ) ;
F_42 ( * V_115 > V_116 ) ;
if ( * V_115 == V_116 )
return 1 ;
return 0 ;
}
int F_112 ( unsigned long * V_115 , struct V_3 * V_4 ,
struct V_1 * V_2 , struct V_117 * V_118 ,
T_4 V_120 , T_1 * V_169 , T_6 * V_170 )
{
int V_25 ;
int type ;
struct V_127 * V_171 ;
if ( * V_115 == ( unsigned long ) - 1 )
return 1 ;
while ( 1 ) {
V_25 = F_111 ( V_115 , V_4 , V_2 , V_118 , V_120 ,
& V_171 , & type ) ;
if ( V_25 < 0 )
return V_25 ;
if ( type == V_104 ||
type == V_108 )
break;
if ( V_25 == 1 )
return 1 ;
}
* V_169 = F_80 ( V_4 , V_171 ) ;
if ( V_2 -> type == V_121 ) {
struct V_123 * V_124 ;
V_124 = (struct V_123 * ) ( V_118 + 1 ) ;
* V_170 = F_78 ( V_4 , V_124 ) ;
} else {
ASSERT ( V_2 -> type == V_125 ) ;
* V_170 = ( T_6 ) V_2 -> V_10 ;
}
if ( V_25 == 1 )
* V_115 = ( unsigned long ) - 1 ;
return 0 ;
}
static int F_113 ( struct V_8 * V_42 ,
T_1 V_45 , T_1 V_172 ,
T_7 * V_173 , void * V_174 )
{
struct V_8 * V_9 ;
int V_25 = 0 ;
for ( V_9 = V_42 ; V_9 ; V_9 = V_9 -> V_16 ) {
F_41 ( L_7
L_8 , V_172 ,
V_9 -> V_17 , V_9 -> V_10 , V_45 ) ;
V_25 = V_173 ( V_9 -> V_17 , V_9 -> V_10 , V_45 , V_174 ) ;
if ( V_25 ) {
F_41 ( L_9 ,
V_172 , V_25 ) ;
break;
}
}
return V_25 ;
}
int F_114 ( struct V_56 * V_57 ,
T_1 V_172 , T_1 V_7 ,
int V_65 ,
T_7 * V_173 , void * V_174 )
{
int V_25 ;
struct V_135 * V_136 = NULL ;
struct V_48 * V_175 = NULL ;
struct V_48 * V_138 = NULL ;
struct V_73 * V_176 = NULL ;
struct V_73 * V_177 = NULL ;
struct V_140 V_178 = F_96 ( V_178 ) ;
struct V_74 V_179 ;
struct V_74 V_180 ;
F_41 ( L_10 ,
V_172 ) ;
if ( ! V_65 ) {
V_136 = F_115 ( V_57 -> V_133 ) ;
if ( F_33 ( V_136 ) )
return F_35 ( V_136 ) ;
F_97 ( V_57 , & V_178 ) ;
} else {
F_93 ( & V_57 -> V_139 ) ;
}
V_25 = F_89 ( V_136 , V_57 , V_172 ,
V_178 . V_89 , & V_175 ,
& V_7 ) ;
if ( V_25 )
goto V_63;
F_47 ( & V_179 ) ;
while ( ! V_25 && ( V_176 = F_48 ( V_175 , & V_179 ) ) ) {
V_25 = F_91 ( V_136 , V_57 , V_176 -> V_77 ,
V_178 . V_89 , & V_138 ) ;
if ( V_25 )
break;
F_47 ( & V_180 ) ;
while ( ! V_25 && ( V_177 = F_48 ( V_138 , & V_180 ) ) ) {
F_41 ( L_11
L_12 , V_177 -> V_77 , V_176 -> V_77 ,
V_176 -> V_79 ) ;
V_25 = F_113 ( (struct V_8 * )
( V_78 ) V_176 -> V_79 ,
V_177 -> V_77 ,
V_172 ,
V_173 , V_174 ) ;
}
F_51 ( V_138 ) ;
}
F_88 ( V_175 ) ;
V_63:
if ( ! V_65 ) {
F_98 ( V_57 , & V_178 ) ;
F_116 ( V_136 , V_57 -> V_133 ) ;
} else {
F_94 ( & V_57 -> V_139 ) ;
}
return V_25 ;
}
int F_117 ( T_1 V_163 , struct V_56 * V_57 ,
struct V_46 * V_47 ,
T_7 * V_173 , void * V_174 )
{
int V_25 ;
T_1 V_7 ;
T_1 V_119 = 0 ;
struct V_1 V_114 ;
int V_65 = V_47 -> V_65 ;
V_25 = F_108 ( V_57 , V_163 , V_47 , & V_114 , & V_119 ) ;
F_43 ( V_47 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_119 & V_122 )
return - V_181 ;
V_7 = V_163 - V_114 . V_18 ;
V_25 = F_114 ( V_57 , V_114 . V_18 ,
V_7 , V_65 ,
V_173 , V_174 ) ;
return V_25 ;
}
static int F_118 ( T_1 V_17 , struct V_44 * V_149 ,
struct V_46 * V_47 ,
T_8 * V_173 , void * V_174 )
{
int V_25 = 0 ;
int V_22 ;
T_4 V_182 ;
T_4 V_183 ;
T_4 V_150 ;
T_1 V_35 = 0 ;
int V_184 = 0 ;
struct V_3 * V_4 ;
struct V_185 * V_186 ;
struct V_158 * V_128 ;
struct V_1 V_114 ;
while ( ! V_25 ) {
V_25 = F_104 ( V_149 , V_47 , V_17 ,
V_35 ? V_35 + 1 : 0 , V_160 ,
& V_114 ) ;
if ( V_25 < 0 )
break;
if ( V_25 ) {
V_25 = V_184 ? 0 : - V_64 ;
break;
}
++ V_184 ;
V_35 = V_114 . V_10 ;
V_22 = V_47 -> V_55 [ 0 ] ;
V_4 = F_119 ( V_47 -> V_53 [ 0 ] ) ;
if ( ! V_4 ) {
V_25 = - V_15 ;
break;
}
F_120 ( V_4 ) ;
F_59 ( V_4 ) ;
F_105 ( V_4 , V_161 ) ;
F_43 ( V_47 ) ;
V_186 = F_121 ( V_22 ) ;
V_128 = F_13 ( V_4 , V_22 , struct V_158 ) ;
for ( V_182 = 0 ; V_182 < F_122 ( V_4 , V_186 ) ; V_182 += V_183 ) {
V_150 = F_106 ( V_4 , V_128 ) ;
F_41 ( L_13
L_14 , V_182 , V_114 . V_18 ,
V_149 -> V_18 ) ;
V_25 = V_173 ( V_35 , V_150 ,
( unsigned long ) ( V_128 + 1 ) , V_4 , V_174 ) ;
if ( V_25 )
break;
V_183 = sizeof( * V_128 ) + V_150 ;
V_128 = (struct V_158 * ) ( ( char * ) V_128 + V_183 ) ;
}
F_103 ( V_4 ) ;
F_58 ( V_4 ) ;
}
F_43 ( V_47 ) ;
return V_25 ;
}
static int F_123 ( T_1 V_17 , struct V_44 * V_149 ,
struct V_46 * V_47 ,
T_8 * V_173 , void * V_174 )
{
int V_25 ;
int V_22 ;
T_1 V_10 = 0 ;
T_1 V_35 ;
int V_184 = 0 ;
struct V_3 * V_4 ;
struct V_144 * V_147 ;
T_4 V_120 ;
T_4 V_187 ;
unsigned long V_115 ;
while ( 1 ) {
V_25 = F_99 ( V_149 , V_17 , V_10 , V_47 , & V_147 ,
& V_10 ) ;
if ( V_25 < 0 )
break;
if ( V_25 ) {
V_25 = V_184 ? 0 : - V_64 ;
break;
}
++ V_184 ;
V_22 = V_47 -> V_55 [ 0 ] ;
V_4 = F_119 ( V_47 -> V_53 [ 0 ] ) ;
if ( ! V_4 ) {
V_25 = - V_15 ;
break;
}
F_120 ( V_4 ) ;
F_59 ( V_4 ) ;
F_105 ( V_4 , V_161 ) ;
F_43 ( V_47 ) ;
V_120 = F_75 ( V_4 , V_22 ) ;
V_115 = F_100 ( V_4 , V_22 ) ;
V_187 = 0 ;
while ( V_187 < V_120 ) {
T_4 V_150 ;
V_147 = (struct V_144 * ) ( V_115 + V_187 ) ;
V_35 = F_124 ( V_4 , V_147 ) ;
V_150 = F_125 ( V_4 , V_147 ) ;
V_25 = V_173 ( V_35 , V_150 ,
( unsigned long ) & V_147 -> V_188 , V_4 , V_174 ) ;
if ( V_25 )
break;
V_187 += F_125 ( V_4 , V_147 ) ;
V_187 += sizeof( * V_147 ) ;
}
F_103 ( V_4 ) ;
F_58 ( V_4 ) ;
V_10 ++ ;
}
F_43 ( V_47 ) ;
return V_25 ;
}
static int F_126 ( T_1 V_17 , struct V_44 * V_149 ,
struct V_46 * V_47 , T_8 * V_173 ,
void * V_174 )
{
int V_25 ;
int V_189 = 0 ;
V_25 = F_118 ( V_17 , V_149 , V_47 , V_173 , V_174 ) ;
if ( ! V_25 )
++ V_189 ;
else if ( V_25 != - V_64 )
return V_25 ;
V_25 = F_123 ( V_17 , V_149 , V_47 , V_173 , V_174 ) ;
if ( V_25 == - V_64 && V_189 )
return 0 ;
return V_25 ;
}
static int F_127 ( T_1 V_17 , T_4 V_150 , unsigned long V_151 ,
struct V_3 * V_4 , void * V_174 )
{
struct V_190 * V_191 = V_174 ;
char * V_192 ;
char * V_193 ;
int V_194 = V_191 -> V_192 -> V_195 ;
const int V_196 = sizeof( char * ) ;
T_4 V_156 ;
V_156 = V_191 -> V_192 -> V_156 > V_196 ?
V_191 -> V_192 -> V_156 - V_196 : 0 ;
V_193 = ( char * ) V_191 -> V_192 -> V_77 + ( V_194 + 1 ) * V_196 ;
V_192 = F_101 ( V_191 -> V_149 , V_191 -> V_46 , V_150 ,
V_151 , V_4 , V_17 , V_193 , V_156 ) ;
if ( F_33 ( V_192 ) )
return F_35 ( V_192 ) ;
if ( V_192 > V_193 ) {
V_191 -> V_192 -> V_77 [ V_194 ] = ( T_1 ) ( unsigned long ) V_192 ;
++ V_191 -> V_192 -> V_195 ;
V_191 -> V_192 -> V_156 = V_192 - V_193 ;
} else {
++ V_191 -> V_192 -> V_197 ;
V_191 -> V_192 -> V_198 += V_193 - V_192 ;
V_191 -> V_192 -> V_156 = 0 ;
}
return 0 ;
}
int F_128 ( T_1 V_17 , struct V_190 * V_191 )
{
return F_126 ( V_17 , V_191 -> V_149 , V_191 -> V_46 ,
F_127 , V_191 ) ;
}
struct V_199 * F_129 ( T_4 V_200 )
{
struct V_199 * V_201 ;
T_9 V_202 ;
V_202 = F_130 ( T_9 , V_200 , sizeof( * V_201 ) ) ;
V_201 = F_131 ( V_202 ) ;
if ( ! V_201 )
return F_107 ( - V_15 ) ;
if ( V_200 >= sizeof( * V_201 ) ) {
V_201 -> V_156 = V_200 - sizeof( * V_201 ) ;
V_201 -> V_198 = 0 ;
} else {
V_201 -> V_198 = sizeof( * V_201 ) - V_200 ;
V_201 -> V_156 = 0 ;
}
V_201 -> V_195 = 0 ;
V_201 -> V_197 = 0 ;
return V_201 ;
}
struct V_190 * F_132 ( T_10 V_200 , struct V_44 * V_149 ,
struct V_46 * V_47 )
{
struct V_190 * V_203 ;
struct V_199 * V_192 ;
V_192 = F_129 ( V_200 ) ;
if ( F_33 ( V_192 ) )
return ( void * ) V_192 ;
V_203 = F_7 ( sizeof( * V_203 ) , V_14 ) ;
if ( ! V_203 ) {
F_133 ( V_192 ) ;
return F_107 ( - V_15 ) ;
}
V_203 -> V_46 = V_47 ;
V_203 -> V_192 = V_192 ;
V_203 -> V_149 = V_149 ;
return V_203 ;
}
void F_134 ( struct V_190 * V_191 )
{
if ( ! V_191 )
return;
F_133 ( V_191 -> V_192 ) ;
F_9 ( V_191 ) ;
}
