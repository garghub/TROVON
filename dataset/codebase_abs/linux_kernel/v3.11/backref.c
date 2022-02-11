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
static int F_14 ( struct V_27 * V_28 , T_1 V_29 ,
struct V_1 * V_2 , int V_30 ,
T_1 V_31 , T_1 V_19 , int V_32 )
{
struct V_33 * V_34 ;
V_34 = F_7 ( sizeof( * V_34 ) , V_35 ) ;
if ( ! V_34 )
return - V_15 ;
V_34 -> V_29 = V_29 ;
if ( V_2 )
V_34 -> V_36 = * V_2 ;
else
memset ( & V_34 -> V_36 , 0 , sizeof( V_34 -> V_36 ) ) ;
V_34 -> V_37 = NULL ;
V_34 -> V_30 = V_30 ;
V_34 -> V_32 = V_32 ;
V_34 -> V_31 = V_31 ;
V_34 -> V_19 = V_19 ;
F_15 ( & V_34 -> V_38 , V_28 ) ;
return 0 ;
}
static int F_16 ( struct V_39 * V_40 , struct V_41 * V_42 ,
struct V_43 * V_44 , int V_30 ,
struct V_1 * V_36 , T_1 V_45 ,
T_1 V_19 ,
const T_1 * V_7 )
{
int V_24 = 0 ;
int V_21 ;
struct V_3 * V_4 ;
struct V_1 V_2 ;
struct V_5 * V_6 ;
struct V_8 * V_9 = NULL , * V_46 = NULL ;
T_1 V_20 ;
if ( V_30 != 0 ) {
V_4 = V_42 -> V_47 [ V_30 ] ;
V_24 = F_17 ( V_44 , V_4 -> V_48 , 0 , V_14 ) ;
if ( V_24 < 0 )
return V_24 ;
return 0 ;
}
if ( V_42 -> V_49 [ 0 ] >= F_9 ( V_42 -> V_47 [ 0 ] ) )
V_24 = F_18 ( V_40 , V_42 , V_45 ) ;
while ( ! V_24 ) {
V_4 = V_42 -> V_47 [ 0 ] ;
V_21 = V_42 -> V_49 [ 0 ] ;
F_10 ( V_4 , & V_2 , V_21 ) ;
if ( V_2 . V_18 != V_36 -> V_18 ||
V_2 . type != V_25 )
break;
V_6 = F_11 ( V_4 , V_21 , struct V_5 ) ;
V_20 = F_13 ( V_4 , V_6 ) ;
if ( V_20 == V_19 ) {
V_9 = NULL ;
V_46 = NULL ;
if ( V_7 ) {
V_24 = F_1 ( & V_2 , V_4 , V_6 ,
* V_7 ,
& V_9 ) ;
if ( V_24 < 0 )
break;
}
if ( V_24 > 0 )
goto V_16;
V_24 = F_19 ( V_44 , V_4 -> V_48 ,
( V_50 ) V_9 ,
( T_1 * ) & V_46 , V_14 ) ;
if ( V_24 < 0 )
break;
if ( ! V_24 && V_7 ) {
while ( V_46 -> V_16 )
V_46 = V_46 -> V_16 ;
V_46 -> V_16 = V_9 ;
}
}
V_16:
V_24 = F_20 ( V_40 , V_42 , V_45 ) ;
}
if ( V_24 > 0 )
V_24 = 0 ;
return V_24 ;
}
static int F_21 ( struct V_51 * V_52 ,
struct V_41 * V_42 , T_1 V_45 ,
struct V_33 * V_34 ,
struct V_43 * V_44 ,
const T_1 * V_7 )
{
struct V_39 * V_40 ;
struct V_1 V_53 ;
struct V_3 * V_4 ;
int V_24 = 0 ;
int V_54 ;
int V_30 = V_34 -> V_30 ;
V_53 . V_18 = V_34 -> V_29 ;
V_53 . type = V_55 ;
V_53 . V_10 = ( T_1 ) - 1 ;
V_40 = F_22 ( V_52 , & V_53 ) ;
if ( F_23 ( V_40 ) ) {
V_24 = F_24 ( V_40 ) ;
goto V_56;
}
V_54 = F_25 ( V_40 , V_45 ) ;
if ( V_54 + 1 == V_30 )
goto V_56;
V_42 -> V_57 = V_30 ;
V_24 = F_26 ( V_40 , & V_34 -> V_36 , V_42 , V_45 ) ;
F_27 ( L_1
L_2 ,
( unsigned long long ) V_34 -> V_29 , V_30 , V_34 -> V_32 , V_24 ,
( unsigned long long ) V_34 -> V_36 . V_18 ,
V_34 -> V_36 . type ,
( unsigned long long ) V_34 -> V_36 . V_10 ) ;
if ( V_24 < 0 )
goto V_56;
V_4 = V_42 -> V_47 [ V_30 ] ;
while ( ! V_4 ) {
if ( ! V_30 ) {
F_28 ( 1 ) ;
V_24 = 1 ;
goto V_56;
}
V_30 -- ;
V_4 = V_42 -> V_47 [ V_30 ] ;
}
V_24 = F_16 ( V_40 , V_42 , V_44 , V_30 , & V_34 -> V_36 ,
V_45 , V_34 -> V_19 ,
V_7 ) ;
V_56:
V_42 -> V_57 = 0 ;
F_29 ( V_42 ) ;
return V_24 ;
}
static int F_30 ( struct V_51 * V_52 ,
struct V_41 * V_42 , T_1 V_45 ,
struct V_27 * V_28 ,
const T_1 * V_7 )
{
int V_58 ;
int V_24 = 0 ;
struct V_33 * V_34 ;
struct V_33 * V_59 ;
struct V_33 * V_60 ;
struct V_43 * V_44 ;
struct V_61 * V_62 ;
struct V_63 V_64 ;
V_44 = F_31 ( V_14 ) ;
if ( ! V_44 )
return - V_15 ;
F_32 (ref, ref_safe, head, list) {
if ( V_34 -> V_31 )
continue;
if ( V_34 -> V_32 == 0 )
continue;
V_58 = F_21 ( V_52 , V_42 , V_45 , V_34 ,
V_44 , V_7 ) ;
if ( V_58 == - V_15 )
goto V_56;
if ( V_58 )
continue;
F_33 ( & V_64 ) ;
V_62 = F_34 ( V_44 , & V_64 ) ;
V_34 -> V_31 = V_62 ? V_62 -> V_65 : 0 ;
V_34 -> V_37 = V_62 ?
(struct V_8 * ) ( V_50 ) V_62 -> V_66 : 0 ;
while ( ( V_62 = F_34 ( V_44 , & V_64 ) ) ) {
V_60 = F_7 ( sizeof( * V_60 ) , V_14 ) ;
if ( ! V_60 ) {
V_24 = - V_15 ;
goto V_56;
}
memcpy ( V_60 , V_34 , sizeof( * V_34 ) ) ;
V_60 -> V_31 = V_62 -> V_65 ;
V_60 -> V_37 = (struct V_8 * )
( V_50 ) V_62 -> V_66 ;
F_35 ( & V_60 -> V_38 , & V_34 -> V_38 ) ;
}
F_36 ( V_44 ) ;
}
V_56:
F_37 ( V_44 ) ;
return V_24 ;
}
static inline int F_38 ( struct V_33 * V_67 ,
struct V_33 * V_68 )
{
if ( V_67 -> V_30 != V_68 -> V_30 )
return 0 ;
if ( V_67 -> V_29 != V_68 -> V_29 )
return 0 ;
if ( V_67 -> V_36 . type != V_68 -> V_36 . type )
return 0 ;
if ( V_67 -> V_36 . V_18 != V_68 -> V_36 . V_18 )
return 0 ;
if ( V_67 -> V_36 . V_10 != V_68 -> V_36 . V_10 )
return 0 ;
if ( V_67 -> V_31 != V_68 -> V_31 )
return 0 ;
return 1 ;
}
static int F_39 ( struct V_51 * V_52 ,
struct V_27 * V_28 )
{
struct V_27 * V_69 ;
struct V_3 * V_4 ;
F_40 (pos, head) {
struct V_33 * V_34 ;
V_34 = F_41 ( V_69 , struct V_33 , V_38 ) ;
if ( V_34 -> V_31 )
continue;
if ( V_34 -> V_36 . type )
continue;
F_42 ( ! V_34 -> V_19 ) ;
V_4 = F_43 ( V_52 -> V_70 , V_34 -> V_19 ,
V_52 -> V_70 -> V_71 , 0 ) ;
if ( ! V_4 || ! F_44 ( V_4 ) ) {
F_45 ( V_4 ) ;
return - V_72 ;
}
F_46 ( V_4 ) ;
if ( F_47 ( V_4 ) == 0 )
F_10 ( V_4 , & V_34 -> V_36 , 0 ) ;
else
F_48 ( V_4 , & V_34 -> V_36 , 0 ) ;
F_49 ( V_4 ) ;
F_45 ( V_4 ) ;
}
return 0 ;
}
static void F_50 ( struct V_27 * V_28 , int V_73 )
{
struct V_27 * V_74 ;
F_40 (pos1, head) {
struct V_27 * V_75 ;
struct V_27 * V_76 ;
struct V_33 * V_67 ;
V_67 = F_41 ( V_74 , struct V_33 , V_38 ) ;
for ( V_76 = V_74 -> V_16 , V_75 = V_76 -> V_16 ; V_76 != V_28 ;
V_76 = V_75 , V_75 = V_76 -> V_16 ) {
struct V_33 * V_68 ;
struct V_33 * V_77 ;
struct V_8 * V_9 ;
V_68 = F_41 ( V_76 , struct V_33 , V_38 ) ;
if ( V_73 == 1 ) {
if ( ! F_38 ( V_67 , V_68 ) )
continue;
if ( ! V_67 -> V_31 && V_68 -> V_31 ) {
V_77 = V_67 ;
V_67 = V_68 ;
V_68 = V_77 ;
}
} else {
if ( V_67 -> V_31 != V_68 -> V_31 )
continue;
}
V_9 = V_67 -> V_37 ;
while ( V_9 && V_9 -> V_16 )
V_9 = V_9 -> V_16 ;
if ( V_9 )
V_9 -> V_16 = V_68 -> V_37 ;
else
V_67 -> V_37 = V_68 -> V_37 ;
V_67 -> V_32 += V_68 -> V_32 ;
F_51 ( & V_68 -> V_38 ) ;
F_52 ( V_68 ) ;
}
}
}
static int F_53 ( struct V_78 * V_28 , T_1 V_79 ,
struct V_27 * V_80 )
{
struct V_81 * V_82 = V_28 -> V_82 ;
struct V_83 * V_84 = & V_28 -> V_62 . V_83 ;
struct V_1 V_2 ;
struct V_1 V_85 = { 0 } ;
int V_86 ;
int V_24 = 0 ;
if ( V_82 && V_82 -> V_87 )
F_54 ( & V_85 , & V_82 -> V_2 ) ;
while ( ( V_84 = F_55 ( V_84 ) ) ) {
struct V_88 * V_62 ;
V_62 = F_56 ( V_84 , struct V_88 ,
V_83 ) ;
if ( V_62 -> V_89 != V_28 -> V_62 . V_89 )
break;
F_28 ( V_62 -> V_90 ) ;
if ( V_62 -> V_79 > V_79 )
continue;
switch ( V_62 -> V_91 ) {
case V_92 :
case V_93 :
F_28 ( 1 ) ;
continue;
case V_94 :
V_86 = 1 ;
break;
case V_95 :
V_86 = - 1 ;
break;
default:
F_42 ( 1 ) ;
}
switch ( V_62 -> type ) {
case V_96 : {
struct V_97 * V_34 ;
V_34 = F_57 ( V_62 ) ;
V_24 = F_14 ( V_80 , V_34 -> V_40 , & V_85 ,
V_34 -> V_30 + 1 , 0 , V_62 -> V_89 ,
V_62 -> V_98 * V_86 ) ;
break;
}
case V_99 : {
struct V_97 * V_34 ;
V_34 = F_57 ( V_62 ) ;
V_24 = F_14 ( V_80 , V_34 -> V_40 , NULL ,
V_34 -> V_30 + 1 , V_34 -> V_31 ,
V_62 -> V_89 ,
V_62 -> V_98 * V_86 ) ;
break;
}
case V_100 : {
struct V_101 * V_34 ;
V_34 = F_58 ( V_62 ) ;
V_2 . V_18 = V_34 -> V_18 ;
V_2 . type = V_25 ;
V_2 . V_10 = V_34 -> V_10 ;
V_24 = F_14 ( V_80 , V_34 -> V_40 , & V_2 , 0 , 0 ,
V_62 -> V_89 ,
V_62 -> V_98 * V_86 ) ;
break;
}
case V_102 : {
struct V_101 * V_34 ;
V_34 = F_58 ( V_62 ) ;
V_2 . V_18 = V_34 -> V_18 ;
V_2 . type = V_25 ;
V_2 . V_10 = V_34 -> V_10 ;
V_24 = F_14 ( V_80 , V_34 -> V_40 , & V_2 , 0 ,
V_34 -> V_31 , V_62 -> V_89 ,
V_62 -> V_98 * V_86 ) ;
break;
}
default:
F_28 ( 1 ) ;
}
if ( V_24 )
return V_24 ;
}
return 0 ;
}
static int F_59 ( struct V_51 * V_52 ,
struct V_41 * V_42 , T_1 V_89 ,
int * V_103 , struct V_27 * V_80 )
{
int V_24 = 0 ;
int V_21 ;
struct V_3 * V_104 ;
struct V_1 V_2 ;
struct V_1 V_105 ;
unsigned long V_106 ;
unsigned long V_107 ;
struct V_108 * V_109 ;
T_1 V_110 ;
T_1 V_111 ;
V_104 = V_42 -> V_47 [ 0 ] ;
V_21 = V_42 -> V_49 [ 0 ] ;
V_111 = F_60 ( V_104 , V_21 ) ;
F_42 ( V_111 < sizeof( * V_109 ) ) ;
V_109 = F_11 ( V_104 , V_21 , struct V_108 ) ;
V_110 = F_61 ( V_104 , V_109 ) ;
F_10 ( V_104 , & V_105 , V_21 ) ;
V_106 = ( unsigned long ) ( V_109 + 1 ) ;
V_107 = ( unsigned long ) V_109 + V_111 ;
if ( V_105 . type == V_112 &&
V_110 & V_113 ) {
struct V_114 * V_115 ;
V_115 = (struct V_114 * ) V_106 ;
* V_103 = F_62 ( V_104 , V_115 ) ;
V_106 += sizeof( struct V_114 ) ;
F_42 ( V_106 > V_107 ) ;
} else if ( V_105 . type == V_116 ) {
* V_103 = V_105 . V_10 ;
} else {
F_42 ( ! ( V_110 & V_117 ) ) ;
}
while ( V_106 < V_107 ) {
struct V_118 * V_119 ;
T_1 V_10 ;
int type ;
V_119 = (struct V_118 * ) V_106 ;
type = F_63 ( V_104 , V_119 ) ;
V_10 = F_64 ( V_104 , V_119 ) ;
switch ( type ) {
case V_99 :
V_24 = F_14 ( V_80 , 0 , NULL ,
* V_103 + 1 , V_10 ,
V_89 , 1 ) ;
break;
case V_102 : {
struct V_120 * V_121 ;
int V_32 ;
V_121 = (struct V_120 * ) ( V_119 + 1 ) ;
V_32 = F_65 ( V_104 , V_121 ) ;
V_24 = F_14 ( V_80 , 0 , NULL , 0 , V_10 ,
V_89 , V_32 ) ;
break;
}
case V_96 :
V_24 = F_14 ( V_80 , V_10 , NULL ,
* V_103 + 1 , 0 ,
V_89 , 1 ) ;
break;
case V_100 : {
struct V_122 * V_123 ;
int V_32 ;
T_1 V_40 ;
V_123 = (struct V_122 * ) ( & V_119 -> V_10 ) ;
V_32 = F_66 ( V_104 , V_123 ) ;
V_2 . V_18 = F_67 ( V_104 ,
V_123 ) ;
V_2 . type = V_25 ;
V_2 . V_10 = F_68 ( V_104 , V_123 ) ;
V_40 = F_69 ( V_104 , V_123 ) ;
V_24 = F_14 ( V_80 , V_40 , & V_2 , 0 , 0 ,
V_89 , V_32 ) ;
break;
}
default:
F_28 ( 1 ) ;
}
if ( V_24 )
return V_24 ;
V_106 += F_70 ( type ) ;
}
return 0 ;
}
static int F_71 ( struct V_51 * V_52 ,
struct V_41 * V_42 , T_1 V_89 ,
int V_103 , struct V_27 * V_80 )
{
struct V_39 * V_124 = V_52 -> V_124 ;
int V_24 ;
int V_21 ;
struct V_3 * V_104 ;
struct V_1 V_2 ;
while ( 1 ) {
V_24 = F_72 ( V_124 , V_42 ) ;
if ( V_24 < 0 )
break;
if ( V_24 ) {
V_24 = 0 ;
break;
}
V_21 = V_42 -> V_49 [ 0 ] ;
V_104 = V_42 -> V_47 [ 0 ] ;
F_10 ( V_104 , & V_2 , V_21 ) ;
if ( V_2 . V_18 != V_89 )
break;
if ( V_2 . type < V_96 )
continue;
if ( V_2 . type > V_102 )
break;
switch ( V_2 . type ) {
case V_99 :
V_24 = F_14 ( V_80 , 0 , NULL ,
V_103 + 1 , V_2 . V_10 ,
V_89 , 1 ) ;
break;
case V_102 : {
struct V_120 * V_121 ;
int V_32 ;
V_121 = F_11 ( V_104 , V_21 ,
struct V_120 ) ;
V_32 = F_65 ( V_104 , V_121 ) ;
V_24 = F_14 ( V_80 , 0 , NULL , 0 , V_2 . V_10 ,
V_89 , V_32 ) ;
break;
}
case V_96 :
V_24 = F_14 ( V_80 , V_2 . V_10 , NULL ,
V_103 + 1 , 0 ,
V_89 , 1 ) ;
break;
case V_100 : {
struct V_122 * V_123 ;
int V_32 ;
T_1 V_40 ;
V_123 = F_11 ( V_104 , V_21 ,
struct V_122 ) ;
V_32 = F_66 ( V_104 , V_123 ) ;
V_2 . V_18 = F_67 ( V_104 ,
V_123 ) ;
V_2 . type = V_25 ;
V_2 . V_10 = F_68 ( V_104 , V_123 ) ;
V_40 = F_69 ( V_104 , V_123 ) ;
V_24 = F_14 ( V_80 , V_40 , & V_2 , 0 , 0 ,
V_89 , V_32 ) ;
break;
}
default:
F_28 ( 1 ) ;
}
if ( V_24 )
return V_24 ;
}
return V_24 ;
}
static int F_73 ( struct V_125 * V_126 ,
struct V_51 * V_52 , T_1 V_89 ,
T_1 V_45 , struct V_43 * V_127 ,
struct V_43 * V_128 , const T_1 * V_7 )
{
struct V_1 V_2 ;
struct V_41 * V_42 ;
struct V_129 * V_130 = NULL ;
struct V_78 * V_28 ;
int V_103 = 0 ;
int V_24 ;
struct V_27 V_131 ;
struct V_27 V_80 ;
struct V_33 * V_34 ;
F_74 ( & V_80 ) ;
F_74 ( & V_131 ) ;
V_2 . V_18 = V_89 ;
V_2 . V_10 = ( T_1 ) - 1 ;
if ( F_75 ( V_52 , V_132 ) )
V_2 . type = V_116 ;
else
V_2 . type = V_112 ;
V_42 = F_76 () ;
if ( ! V_42 )
return - V_15 ;
if ( ! V_126 )
V_42 -> V_133 = 1 ;
V_134:
V_28 = NULL ;
V_24 = F_77 ( V_126 , V_52 -> V_124 , & V_2 , V_42 , 0 , 0 ) ;
if ( V_24 < 0 )
goto V_56;
F_42 ( V_24 == 0 ) ;
if ( V_126 ) {
V_130 = & V_126 -> V_135 -> V_130 ;
F_78 ( & V_130 -> V_136 ) ;
V_28 = F_79 ( V_126 , V_89 ) ;
if ( V_28 ) {
if ( ! F_80 ( & V_28 -> V_137 ) ) {
F_81 ( & V_28 -> V_62 . V_127 ) ;
F_82 ( & V_130 -> V_136 ) ;
F_29 ( V_42 ) ;
F_83 ( & V_28 -> V_137 ) ;
F_84 ( & V_28 -> V_137 ) ;
F_85 ( & V_28 -> V_62 ) ;
goto V_134;
}
V_24 = F_53 ( V_28 , V_45 ,
& V_131 ) ;
F_84 ( & V_28 -> V_137 ) ;
if ( V_24 ) {
F_82 ( & V_130 -> V_136 ) ;
goto V_56;
}
}
F_82 ( & V_130 -> V_136 ) ;
}
if ( V_42 -> V_49 [ 0 ] ) {
struct V_3 * V_104 ;
int V_21 ;
V_42 -> V_49 [ 0 ] -- ;
V_104 = V_42 -> V_47 [ 0 ] ;
V_21 = V_42 -> V_49 [ 0 ] ;
F_10 ( V_104 , & V_2 , V_21 ) ;
if ( V_2 . V_18 == V_89 &&
( V_2 . type == V_112 ||
V_2 . type == V_116 ) ) {
V_24 = F_59 ( V_52 , V_42 , V_89 ,
& V_103 , & V_80 ) ;
if ( V_24 )
goto V_56;
V_24 = F_71 ( V_52 , V_42 , V_89 ,
V_103 , & V_80 ) ;
if ( V_24 )
goto V_56;
}
}
F_29 ( V_42 ) ;
F_86 ( & V_131 , & V_80 ) ;
V_24 = F_39 ( V_52 , & V_80 ) ;
if ( V_24 )
goto V_56;
F_50 ( & V_80 , 1 ) ;
V_24 = F_30 ( V_52 , V_42 , V_45 , & V_80 ,
V_7 ) ;
if ( V_24 )
goto V_56;
F_50 ( & V_80 , 2 ) ;
while ( ! F_87 ( & V_80 ) ) {
V_34 = F_88 ( & V_80 , struct V_33 , V_38 ) ;
F_51 ( & V_34 -> V_38 ) ;
F_28 ( V_34 -> V_32 < 0 ) ;
if ( V_34 -> V_32 && V_34 -> V_29 && V_34 -> V_31 == 0 ) {
V_24 = F_17 ( V_128 , V_34 -> V_29 , 0 , V_14 ) ;
if ( V_24 < 0 )
goto V_56;
}
if ( V_34 -> V_32 && V_34 -> V_31 ) {
struct V_8 * V_9 = NULL ;
if ( V_7 && ! V_34 -> V_37 ) {
T_2 V_138 ;
struct V_3 * V_4 ;
V_138 = F_89 ( V_52 -> V_124 ,
V_103 ) ;
V_4 = F_43 ( V_52 -> V_124 ,
V_34 -> V_31 , V_138 , 0 ) ;
if ( ! V_4 || ! F_44 ( V_4 ) ) {
F_45 ( V_4 ) ;
V_24 = - V_72 ;
goto V_56;
}
V_24 = F_8 ( V_4 , V_89 ,
* V_7 , & V_9 ) ;
V_34 -> V_37 = V_9 ;
F_45 ( V_4 ) ;
}
V_24 = F_19 ( V_127 , V_34 -> V_31 ,
( V_50 ) V_34 -> V_37 ,
( T_1 * ) & V_9 , V_14 ) ;
if ( V_24 < 0 )
goto V_56;
if ( ! V_24 && V_7 ) {
F_42 ( ! V_9 ) ;
while ( V_9 -> V_16 )
V_9 = V_9 -> V_16 ;
V_9 -> V_16 = V_34 -> V_37 ;
}
}
F_52 ( V_34 ) ;
}
V_56:
F_90 ( V_42 ) ;
while ( ! F_87 ( & V_80 ) ) {
V_34 = F_88 ( & V_80 , struct V_33 , V_38 ) ;
F_51 ( & V_34 -> V_38 ) ;
F_52 ( V_34 ) ;
}
while ( ! F_87 ( & V_131 ) ) {
V_34 = F_88 ( & V_131 , struct V_33 ,
V_38 ) ;
F_51 ( & V_34 -> V_38 ) ;
F_52 ( V_34 ) ;
}
return V_24 ;
}
static void F_91 ( struct V_43 * V_139 )
{
struct V_61 * V_62 = NULL ;
struct V_8 * V_9 ;
struct V_8 * V_140 ;
struct V_63 V_64 ;
F_33 ( & V_64 ) ;
while ( ( V_62 = F_34 ( V_139 , & V_64 ) ) ) {
if ( ! V_62 -> V_66 )
continue;
V_9 = (struct V_8 * ) ( V_50 ) V_62 -> V_66 ;
for (; V_9 ; V_9 = V_140 ) {
V_140 = V_9 -> V_16 ;
F_52 ( V_9 ) ;
}
V_62 -> V_66 = 0 ;
}
F_37 ( V_139 ) ;
}
static int F_92 ( struct V_125 * V_126 ,
struct V_51 * V_52 , T_1 V_89 ,
T_1 V_45 , struct V_43 * * V_141 ,
const T_1 * V_7 )
{
struct V_43 * V_142 ;
int V_24 ;
V_142 = F_31 ( V_14 ) ;
if ( ! V_142 )
return - V_15 ;
* V_141 = F_31 ( V_14 ) ;
if ( ! * V_141 ) {
F_37 ( V_142 ) ;
return - V_15 ;
}
V_24 = F_73 ( V_126 , V_52 , V_89 ,
V_45 , * V_141 , V_142 , V_7 ) ;
F_37 ( V_142 ) ;
if ( V_24 < 0 && V_24 != - V_143 ) {
F_91 ( * V_141 ) ;
return V_24 ;
}
return 0 ;
}
int F_93 ( struct V_125 * V_126 ,
struct V_51 * V_52 , T_1 V_89 ,
T_1 V_45 , struct V_43 * * V_128 )
{
struct V_43 * V_142 ;
struct V_61 * V_62 = NULL ;
struct V_63 V_64 ;
int V_24 ;
V_142 = F_31 ( V_14 ) ;
if ( ! V_142 )
return - V_15 ;
* V_128 = F_31 ( V_14 ) ;
if ( ! * V_128 ) {
F_37 ( V_142 ) ;
return - V_15 ;
}
F_33 ( & V_64 ) ;
while ( 1 ) {
V_24 = F_73 ( V_126 , V_52 , V_89 ,
V_45 , V_142 , * V_128 , NULL ) ;
if ( V_24 < 0 && V_24 != - V_143 ) {
F_37 ( V_142 ) ;
F_37 ( * V_128 ) ;
return V_24 ;
}
V_62 = F_34 ( V_142 , & V_64 ) ;
if ( ! V_62 )
break;
V_89 = V_62 -> V_65 ;
}
F_37 ( V_142 ) ;
return 0 ;
}
static int F_94 ( T_1 V_17 , T_1 V_144 , T_3 V_145 ,
struct V_39 * V_146 , struct V_41 * V_42 ,
struct V_1 * V_105 )
{
int V_24 ;
struct V_1 V_2 ;
struct V_3 * V_4 ;
V_2 . type = V_145 ;
V_2 . V_18 = V_17 ;
V_2 . V_10 = V_144 ;
V_24 = F_77 ( NULL , V_146 , & V_2 , V_42 , 0 , 0 ) ;
if ( V_24 < 0 )
return V_24 ;
V_4 = V_42 -> V_47 [ 0 ] ;
if ( V_24 && V_42 -> V_49 [ 0 ] >= F_9 ( V_4 ) ) {
V_24 = F_95 ( V_146 , V_42 ) ;
if ( V_24 )
return V_24 ;
V_4 = V_42 -> V_47 [ 0 ] ;
}
F_10 ( V_4 , V_105 , V_42 -> V_49 [ 0 ] ) ;
if ( V_105 -> type != V_2 . type || V_105 -> V_18 != V_2 . V_18 )
return 1 ;
return 0 ;
}
int F_96 ( T_1 V_17 , T_1 V_144 , struct V_39 * V_146 ,
struct V_41 * V_42 )
{
struct V_1 V_2 ;
return F_94 ( V_17 , V_144 , V_147 , V_146 , V_42 ,
& V_2 ) ;
}
static int F_97 ( T_1 V_17 , T_1 V_144 , struct V_39 * V_146 ,
struct V_41 * V_42 ,
struct V_1 * V_105 )
{
return F_94 ( V_17 , V_144 , V_148 , V_146 , V_42 ,
V_105 ) ;
}
int F_98 ( struct V_39 * V_40 , T_1 V_149 ,
T_1 V_150 , struct V_41 * V_42 ,
struct V_151 * * V_152 ,
T_1 * V_153 )
{
int V_24 , V_21 ;
struct V_1 V_2 ;
struct V_1 V_105 ;
struct V_151 * V_154 ;
struct V_3 * V_104 ;
unsigned long V_106 ;
V_2 . V_18 = V_149 ;
F_99 ( & V_2 , V_155 ) ;
V_2 . V_10 = V_150 ;
V_24 = F_77 ( NULL , V_40 , & V_2 , V_42 , 0 , 0 ) ;
if ( V_24 < 0 )
return V_24 ;
while ( 1 ) {
V_104 = V_42 -> V_47 [ 0 ] ;
V_21 = V_42 -> V_49 [ 0 ] ;
if ( V_21 >= F_9 ( V_104 ) ) {
V_24 = F_95 ( V_40 , V_42 ) ;
if ( V_24 ) {
if ( V_24 >= 1 )
V_24 = - V_143 ;
break;
}
continue;
}
F_10 ( V_104 , & V_105 , V_21 ) ;
V_24 = - V_143 ;
if ( V_105 . V_18 != V_149 )
break;
if ( F_100 ( & V_105 ) != V_155 )
break;
V_24 = 0 ;
V_106 = F_101 ( V_104 , V_42 -> V_49 [ 0 ] ) ;
V_154 = (struct V_151 * ) V_106 ;
* V_152 = V_154 ;
if ( V_153 )
* V_153 = V_105 . V_10 ;
break;
}
return V_24 ;
}
char * F_102 ( struct V_39 * V_146 , struct V_41 * V_42 ,
T_2 V_156 , unsigned long V_157 ,
struct V_3 * V_158 , T_1 V_31 ,
char * V_159 , T_2 V_160 )
{
int V_21 ;
T_1 V_161 ;
int V_24 ;
T_4 V_162 = ( ( T_4 ) V_160 ) - 1 ;
struct V_3 * V_4 = V_158 ;
struct V_1 V_105 ;
int V_163 = V_42 -> V_163 ;
struct V_164 * V_119 ;
if ( V_162 >= 0 )
V_159 [ V_162 ] = '\0' ;
V_42 -> V_163 = 1 ;
while ( 1 ) {
V_162 -= V_156 ;
if ( V_162 >= 0 )
F_103 ( V_4 , V_159 + V_162 ,
V_157 , V_156 ) ;
if ( V_4 != V_158 ) {
F_104 ( V_4 ) ;
F_45 ( V_4 ) ;
}
V_24 = F_97 ( V_31 , 0 , V_146 , V_42 , & V_105 ) ;
if ( V_24 > 0 )
V_24 = - V_143 ;
if ( V_24 )
break;
V_161 = V_105 . V_10 ;
if ( V_31 == V_161 )
break;
V_21 = V_42 -> V_49 [ 0 ] ;
V_4 = V_42 -> V_47 [ 0 ] ;
if ( V_4 != V_158 ) {
F_81 ( & V_4 -> V_127 ) ;
F_46 ( V_4 ) ;
F_105 ( V_4 , V_165 ) ;
}
F_29 ( V_42 ) ;
V_119 = F_11 ( V_4 , V_21 , struct V_164 ) ;
V_156 = F_106 ( V_4 , V_119 ) ;
V_157 = ( unsigned long ) ( V_119 + 1 ) ;
V_31 = V_161 ;
-- V_162 ;
if ( V_162 >= 0 )
V_159 [ V_162 ] = '/' ;
}
F_29 ( V_42 ) ;
V_42 -> V_163 = V_163 ;
if ( V_24 )
return F_107 ( V_24 ) ;
return V_159 + V_162 ;
}
int F_108 ( struct V_51 * V_52 , T_1 V_166 ,
struct V_41 * V_42 , struct V_1 * V_105 ,
T_1 * V_167 )
{
int V_24 ;
T_1 V_110 ;
T_1 V_160 = 0 ;
T_2 V_111 ;
struct V_3 * V_4 ;
struct V_108 * V_109 ;
struct V_1 V_2 ;
if ( F_75 ( V_52 , V_132 ) )
V_2 . type = V_116 ;
else
V_2 . type = V_112 ;
V_2 . V_18 = V_166 ;
V_2 . V_10 = ( T_1 ) - 1 ;
V_24 = F_77 ( NULL , V_52 -> V_124 , & V_2 , V_42 , 0 , 0 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_109 ( V_52 -> V_124 , V_42 ,
0 , V_112 ) ;
if ( V_24 < 0 )
return V_24 ;
F_10 ( V_42 -> V_47 [ 0 ] , V_105 , V_42 -> V_49 [ 0 ] ) ;
if ( V_105 -> type == V_116 )
V_160 = V_52 -> V_124 -> V_71 ;
else if ( V_105 -> type == V_112 )
V_160 = V_105 -> V_10 ;
if ( ( V_105 -> type != V_112 &&
V_105 -> type != V_116 ) ||
V_105 -> V_18 > V_166 ||
V_105 -> V_18 + V_160 <= V_166 ) {
F_27 ( L_3 ,
( unsigned long long ) V_166 ) ;
return - V_143 ;
}
V_4 = V_42 -> V_47 [ 0 ] ;
V_111 = F_60 ( V_4 , V_42 -> V_49 [ 0 ] ) ;
F_42 ( V_111 < sizeof( * V_109 ) ) ;
V_109 = F_11 ( V_4 , V_42 -> V_49 [ 0 ] , struct V_108 ) ;
V_110 = F_61 ( V_4 , V_109 ) ;
F_27 ( L_4
L_5 ,
( unsigned long long ) V_166 ,
( unsigned long long ) ( V_166 - V_105 -> V_18 ) ,
( unsigned long long ) V_105 -> V_18 ,
( unsigned long long ) V_105 -> V_10 ,
( unsigned long long ) V_110 , V_111 ) ;
F_28 ( ! V_167 ) ;
if ( V_167 ) {
if ( V_110 & V_113 )
* V_167 = V_113 ;
else if ( V_110 & V_117 )
* V_167 = V_117 ;
else
F_42 ( 1 ) ;
return 0 ;
}
return - V_72 ;
}
static int F_110 ( unsigned long * V_106 , struct V_3 * V_4 ,
struct V_108 * V_109 , T_2 V_111 ,
struct V_118 * * V_168 ,
int * V_169 )
{
unsigned long V_107 ;
T_1 V_110 ;
struct V_114 * V_115 ;
if ( ! * V_106 ) {
V_110 = F_61 ( V_4 , V_109 ) ;
if ( V_110 & V_113 ) {
V_115 = (struct V_114 * ) ( V_109 + 1 ) ;
* V_168 =
(struct V_118 * ) ( V_115 + 1 ) ;
} else {
* V_168 = (struct V_118 * ) ( V_109 + 1 ) ;
}
* V_106 = ( unsigned long ) * V_168 ;
if ( ( void * ) * V_106 >= ( void * ) V_109 + V_111 )
return - V_143 ;
}
V_107 = ( unsigned long ) V_109 + V_111 ;
* V_168 = (struct V_118 * ) * V_106 ;
* V_169 = F_63 ( V_4 , * V_168 ) ;
* V_106 += F_70 ( * V_169 ) ;
F_28 ( * V_106 > V_107 ) ;
if ( * V_106 == V_107 )
return 1 ;
return 0 ;
}
int F_111 ( unsigned long * V_106 , struct V_3 * V_4 ,
struct V_108 * V_109 , T_2 V_111 ,
T_1 * V_170 , T_3 * V_171 )
{
int V_24 ;
int type ;
struct V_114 * V_115 ;
struct V_118 * V_172 ;
if ( * V_106 == ( unsigned long ) - 1 )
return 1 ;
while ( 1 ) {
V_24 = F_110 ( V_106 , V_4 , V_109 , V_111 ,
& V_172 , & type ) ;
if ( V_24 < 0 )
return V_24 ;
if ( type == V_96 ||
type == V_99 )
break;
if ( V_24 == 1 )
return 1 ;
}
V_115 = (struct V_114 * ) ( V_109 + 1 ) ;
* V_170 = F_64 ( V_4 , V_172 ) ;
* V_171 = F_62 ( V_4 , V_115 ) ;
if ( V_24 == 1 )
* V_106 = ( unsigned long ) - 1 ;
return 0 ;
}
static int F_112 ( struct V_8 * V_37 ,
T_1 V_40 , T_1 V_173 ,
T_5 * V_174 , void * V_175 )
{
struct V_8 * V_9 ;
int V_24 = 0 ;
for ( V_9 = V_37 ; V_9 ; V_9 = V_9 -> V_16 ) {
F_27 ( L_6
L_7 , V_173 ,
V_9 -> V_17 , V_9 -> V_10 , V_40 ) ;
V_24 = V_174 ( V_9 -> V_17 , V_9 -> V_10 , V_40 , V_175 ) ;
if ( V_24 ) {
F_27 ( L_8 ,
V_173 , V_24 ) ;
break;
}
}
return V_24 ;
}
int F_113 ( struct V_51 * V_52 ,
T_1 V_173 , T_1 V_7 ,
int V_133 ,
T_5 * V_174 , void * V_175 )
{
int V_24 ;
struct V_125 * V_126 = NULL ;
struct V_43 * V_127 = NULL ;
struct V_43 * V_128 = NULL ;
struct V_61 * V_176 = NULL ;
struct V_61 * V_177 = NULL ;
struct V_178 V_179 = {} ;
struct V_63 V_180 ;
struct V_63 V_181 ;
F_27 ( L_9 ,
V_173 ) ;
if ( ! V_133 ) {
V_126 = F_114 ( V_52 -> V_124 ) ;
if ( F_23 ( V_126 ) )
return F_24 ( V_126 ) ;
F_115 ( V_52 , & V_179 ) ;
}
V_24 = F_92 ( V_126 , V_52 , V_173 ,
V_179 . V_79 , & V_127 ,
& V_7 ) ;
if ( V_24 )
goto V_56;
F_33 ( & V_180 ) ;
while ( ! V_24 && ( V_176 = F_34 ( V_127 , & V_180 ) ) ) {
V_24 = F_93 ( V_126 , V_52 , V_176 -> V_65 ,
V_179 . V_79 , & V_128 ) ;
if ( V_24 )
break;
F_33 ( & V_181 ) ;
while ( ! V_24 && ( V_177 = F_34 ( V_128 , & V_181 ) ) ) {
F_27 ( L_10
L_11 , V_177 -> V_65 , V_176 -> V_65 ,
( long long ) V_176 -> V_66 ) ;
V_24 = F_112 ( (struct V_8 * )
( V_50 ) V_176 -> V_66 ,
V_177 -> V_65 ,
V_173 ,
V_174 , V_175 ) ;
}
F_37 ( V_128 ) ;
}
F_91 ( V_127 ) ;
V_56:
if ( ! V_133 ) {
F_116 ( V_52 , & V_179 ) ;
F_117 ( V_126 , V_52 -> V_124 ) ;
}
return V_24 ;
}
int F_118 ( T_1 V_166 , struct V_51 * V_52 ,
struct V_41 * V_42 ,
T_5 * V_174 , void * V_175 )
{
int V_24 ;
T_1 V_7 ;
T_1 V_110 = 0 ;
struct V_1 V_105 ;
int V_133 = V_42 -> V_133 ;
V_24 = F_108 ( V_52 , V_166 , V_42 , & V_105 , & V_110 ) ;
F_29 ( V_42 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_110 & V_113 )
return - V_182 ;
V_7 = V_166 - V_105 . V_18 ;
V_24 = F_113 ( V_52 , V_105 . V_18 ,
V_7 , V_133 ,
V_174 , V_175 ) ;
return V_24 ;
}
static int F_119 ( T_1 V_17 , struct V_39 * V_146 ,
struct V_41 * V_42 ,
T_6 * V_174 , void * V_175 )
{
int V_24 = 0 ;
int V_21 ;
T_2 V_183 ;
T_2 V_184 ;
T_2 V_156 ;
T_1 V_31 = 0 ;
int V_185 = 0 ;
struct V_3 * V_4 ;
struct V_186 * V_187 ;
struct V_164 * V_119 ;
struct V_1 V_105 ;
while ( ! V_24 ) {
V_42 -> V_163 = 1 ;
V_24 = F_97 ( V_17 , V_31 ? V_31 + 1 : 0 , V_146 , V_42 ,
& V_105 ) ;
if ( V_24 < 0 )
break;
if ( V_24 ) {
V_24 = V_185 ? 0 : - V_143 ;
break;
}
++ V_185 ;
V_31 = V_105 . V_10 ;
V_21 = V_42 -> V_49 [ 0 ] ;
V_4 = V_42 -> V_47 [ 0 ] ;
F_81 ( & V_4 -> V_127 ) ;
F_46 ( V_4 ) ;
F_105 ( V_4 , V_165 ) ;
F_29 ( V_42 ) ;
V_187 = F_120 ( V_4 , V_21 ) ;
V_119 = F_11 ( V_4 , V_21 , struct V_164 ) ;
for ( V_183 = 0 ; V_183 < F_121 ( V_4 , V_187 ) ; V_183 += V_184 ) {
V_156 = F_106 ( V_4 , V_119 ) ;
F_27 ( L_12
L_13 , V_183 ,
( unsigned long long ) V_105 . V_18 ,
( unsigned long long ) V_146 -> V_18 ) ;
V_24 = V_174 ( V_31 , V_156 ,
( unsigned long ) ( V_119 + 1 ) , V_4 , V_175 ) ;
if ( V_24 )
break;
V_184 = sizeof( * V_119 ) + V_156 ;
V_119 = (struct V_164 * ) ( ( char * ) V_119 + V_184 ) ;
}
F_104 ( V_4 ) ;
F_45 ( V_4 ) ;
}
F_29 ( V_42 ) ;
return V_24 ;
}
static int F_122 ( T_1 V_17 , struct V_39 * V_146 ,
struct V_41 * V_42 ,
T_6 * V_174 , void * V_175 )
{
int V_24 ;
int V_21 ;
T_1 V_10 = 0 ;
T_1 V_31 ;
int V_185 = 0 ;
struct V_3 * V_4 ;
struct V_151 * V_154 ;
struct V_3 * V_104 ;
T_2 V_111 ;
T_2 V_188 ;
unsigned long V_106 ;
while ( 1 ) {
V_24 = F_98 ( V_146 , V_17 , V_10 , V_42 , & V_154 ,
& V_10 ) ;
if ( V_24 < 0 )
break;
if ( V_24 ) {
V_24 = V_185 ? 0 : - V_143 ;
break;
}
++ V_185 ;
V_21 = V_42 -> V_49 [ 0 ] ;
V_4 = V_42 -> V_47 [ 0 ] ;
F_81 ( & V_4 -> V_127 ) ;
F_46 ( V_4 ) ;
F_105 ( V_4 , V_165 ) ;
F_29 ( V_42 ) ;
V_104 = V_42 -> V_47 [ 0 ] ;
V_111 = F_60 ( V_104 , V_42 -> V_49 [ 0 ] ) ;
V_106 = F_101 ( V_104 , V_42 -> V_49 [ 0 ] ) ;
V_188 = 0 ;
while ( V_188 < V_111 ) {
T_2 V_156 ;
V_154 = (struct V_151 * ) ( V_106 + V_188 ) ;
V_31 = F_123 ( V_4 , V_154 ) ;
V_156 = F_124 ( V_4 , V_154 ) ;
V_24 = V_174 ( V_31 , V_156 ,
( unsigned long ) & V_154 -> V_189 , V_4 , V_175 ) ;
if ( V_24 )
break;
V_188 += F_124 ( V_104 , V_154 ) ;
V_188 += sizeof( * V_154 ) ;
}
F_104 ( V_4 ) ;
F_45 ( V_4 ) ;
V_10 ++ ;
}
F_29 ( V_42 ) ;
return V_24 ;
}
static int F_125 ( T_1 V_17 , struct V_39 * V_146 ,
struct V_41 * V_42 , T_6 * V_174 ,
void * V_175 )
{
int V_24 ;
int V_190 = 0 ;
V_24 = F_119 ( V_17 , V_146 , V_42 , V_174 , V_175 ) ;
if ( ! V_24 )
++ V_190 ;
else if ( V_24 != - V_143 )
return V_24 ;
V_24 = F_122 ( V_17 , V_146 , V_42 , V_174 , V_175 ) ;
if ( V_24 == - V_143 && V_190 )
return 0 ;
return V_24 ;
}
static int F_126 ( T_1 V_17 , T_2 V_156 , unsigned long V_157 ,
struct V_3 * V_4 , void * V_175 )
{
struct V_191 * V_192 = V_175 ;
char * V_193 ;
char * V_194 ;
int V_195 = V_192 -> V_193 -> V_196 ;
const int V_197 = sizeof( char * ) ;
T_2 V_162 ;
V_162 = V_192 -> V_193 -> V_162 > V_197 ?
V_192 -> V_193 -> V_162 - V_197 : 0 ;
V_194 = ( char * ) V_192 -> V_193 -> V_65 + ( V_195 + 1 ) * V_197 ;
V_193 = F_102 ( V_192 -> V_146 , V_192 -> V_41 , V_156 ,
V_157 , V_4 , V_17 , V_194 , V_162 ) ;
if ( F_23 ( V_193 ) )
return F_24 ( V_193 ) ;
if ( V_193 > V_194 ) {
V_192 -> V_193 -> V_65 [ V_195 ] = ( T_1 ) ( unsigned long ) V_193 ;
++ V_192 -> V_193 -> V_196 ;
V_192 -> V_193 -> V_162 = V_193 - V_194 ;
} else {
++ V_192 -> V_193 -> V_198 ;
V_192 -> V_193 -> V_199 += V_194 - V_193 ;
V_192 -> V_193 -> V_162 = 0 ;
}
return 0 ;
}
int F_127 ( T_1 V_17 , struct V_191 * V_192 )
{
return F_125 ( V_17 , V_192 -> V_146 , V_192 -> V_41 ,
F_126 , V_192 ) ;
}
struct V_200 * F_128 ( T_2 V_201 )
{
struct V_200 * V_202 ;
T_7 V_203 ;
V_203 = F_129 ( T_7 , V_201 , sizeof( * V_202 ) ) ;
V_202 = F_130 ( V_203 ) ;
if ( ! V_202 )
return F_107 ( - V_15 ) ;
if ( V_201 >= sizeof( * V_202 ) ) {
V_202 -> V_162 = V_201 - sizeof( * V_202 ) ;
V_202 -> V_199 = 0 ;
} else {
V_202 -> V_199 = sizeof( * V_202 ) - V_201 ;
V_202 -> V_162 = 0 ;
}
V_202 -> V_196 = 0 ;
V_202 -> V_198 = 0 ;
return V_202 ;
}
struct V_191 * F_131 ( T_8 V_201 , struct V_39 * V_146 ,
struct V_41 * V_42 )
{
struct V_191 * V_204 ;
struct V_200 * V_193 ;
V_193 = F_128 ( V_201 ) ;
if ( F_23 ( V_193 ) )
return ( void * ) V_193 ;
V_204 = F_7 ( sizeof( * V_204 ) , V_14 ) ;
if ( ! V_204 ) {
F_52 ( V_193 ) ;
return F_107 ( - V_15 ) ;
}
V_204 -> V_41 = V_42 ;
V_204 -> V_193 = V_193 ;
V_204 -> V_146 = V_146 ;
return V_204 ;
}
void F_132 ( struct V_191 * V_192 )
{
if ( ! V_192 )
return;
F_133 ( V_192 -> V_193 ) ;
F_52 ( V_192 ) ;
}
