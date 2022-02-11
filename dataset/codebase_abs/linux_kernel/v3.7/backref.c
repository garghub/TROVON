static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
T_1 V_7 ,
struct V_8 * * V_9 )
{
T_1 V_10 ;
T_1 V_11 ;
struct V_8 * V_12 ;
V_10 = F_2 ( V_4 , V_6 ) ;
V_11 = F_3 ( V_4 , V_6 ) ;
if ( V_7 < V_10 ||
V_7 >= V_10 + V_11 )
return 1 ;
V_12 = F_4 ( sizeof( * V_12 ) , V_13 ) ;
if ( ! V_12 )
return - V_14 ;
V_12 -> V_15 = * V_9 ;
V_12 -> V_16 = V_2 -> V_17 ;
V_12 -> V_18 = V_2 -> V_18 + ( V_7 - V_10 ) ;
* V_9 = V_12 ;
return 0 ;
}
static int F_5 ( struct V_3 * V_4 , T_1 V_19 ,
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
V_22 = F_6 ( V_4 ) ;
for ( V_21 = 0 ; V_21 < V_22 ; ++ V_21 ) {
F_7 ( V_4 , & V_2 , V_21 ) ;
if ( V_2 . type != V_25 )
continue;
V_6 = F_8 ( V_4 , V_21 , struct V_5 ) ;
V_23 = F_9 ( V_4 , V_6 ) ;
if ( V_23 == V_26 )
continue;
V_20 = F_10 ( V_4 , V_6 ) ;
if ( V_20 != V_19 )
continue;
V_24 = F_1 ( & V_2 , V_4 , V_6 , V_7 , V_9 ) ;
if ( V_24 < 0 )
return V_24 ;
}
return 0 ;
}
static int F_11 ( struct V_27 * V_28 , T_1 V_29 ,
struct V_1 * V_2 , int V_30 ,
T_1 V_31 , T_1 V_19 , int V_32 )
{
struct V_33 * V_34 ;
V_34 = F_4 ( sizeof( * V_34 ) , V_35 ) ;
if ( ! V_34 )
return - V_14 ;
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
F_12 ( & V_34 -> V_38 , V_28 ) ;
return 0 ;
}
static int F_13 ( struct V_39 * V_40 , struct V_41 * V_42 ,
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
struct V_8 * V_9 = NULL ;
T_1 V_20 ;
if ( V_30 != 0 ) {
V_4 = V_42 -> V_46 [ V_30 ] ;
V_24 = F_14 ( V_44 , V_4 -> V_47 , 0 , V_13 ) ;
if ( V_24 < 0 )
return V_24 ;
return 0 ;
}
if ( V_42 -> V_48 [ 0 ] >= F_6 ( V_42 -> V_46 [ 0 ] ) )
V_24 = F_15 ( V_40 , V_42 , V_45 ) ;
while ( ! V_24 ) {
V_4 = V_42 -> V_46 [ 0 ] ;
V_21 = V_42 -> V_48 [ 0 ] ;
F_7 ( V_4 , & V_2 , V_21 ) ;
if ( V_2 . V_17 != V_36 -> V_17 ||
V_2 . type != V_25 )
break;
V_6 = F_8 ( V_4 , V_21 , struct V_5 ) ;
V_20 = F_10 ( V_4 , V_6 ) ;
if ( V_20 == V_19 ) {
V_9 = NULL ;
if ( V_7 ) {
V_24 = F_1 ( & V_2 , V_4 , V_6 ,
* V_7 ,
& V_9 ) ;
if ( V_24 < 0 )
break;
}
if ( ! V_24 ) {
V_24 = F_14 ( V_44 , V_4 -> V_47 ,
( V_49 ) V_9 , V_13 ) ;
if ( V_24 < 0 )
break;
if ( ! V_7 ) {
V_24 = F_15 ( V_40 , V_42 ,
V_45 ) ;
continue;
}
}
}
V_24 = F_16 ( V_40 , V_42 , V_45 ) ;
}
if ( V_24 > 0 )
V_24 = 0 ;
return V_24 ;
}
static int F_17 ( struct V_50 * V_51 ,
int V_52 ,
T_1 V_45 ,
struct V_33 * V_34 ,
struct V_43 * V_44 ,
const T_1 * V_7 )
{
struct V_41 * V_42 ;
struct V_39 * V_40 ;
struct V_1 V_53 ;
struct V_3 * V_4 ;
int V_24 = 0 ;
int V_54 ;
int V_30 = V_34 -> V_30 ;
V_42 = F_18 () ;
if ( ! V_42 )
return - V_14 ;
V_42 -> V_52 = ! ! V_52 ;
V_53 . V_17 = V_34 -> V_29 ;
V_53 . type = V_55 ;
V_53 . V_18 = ( T_1 ) - 1 ;
V_40 = F_19 ( V_51 , & V_53 ) ;
if ( F_20 ( V_40 ) ) {
V_24 = F_21 ( V_40 ) ;
goto V_56;
}
V_54 = F_22 ( V_40 , V_45 ) ;
if ( V_54 + 1 == V_30 )
goto V_56;
V_42 -> V_57 = V_30 ;
V_24 = F_23 ( V_40 , & V_34 -> V_36 , V_42 , V_45 ) ;
F_24 ( L_1
L_2 ,
( unsigned long long ) V_34 -> V_29 , V_30 , V_34 -> V_32 , V_24 ,
( unsigned long long ) V_34 -> V_36 . V_17 ,
V_34 -> V_36 . type ,
( unsigned long long ) V_34 -> V_36 . V_18 ) ;
if ( V_24 < 0 )
goto V_56;
V_4 = V_42 -> V_46 [ V_30 ] ;
while ( ! V_4 ) {
if ( ! V_30 ) {
F_25 ( 1 ) ;
V_24 = 1 ;
goto V_56;
}
V_30 -- ;
V_4 = V_42 -> V_46 [ V_30 ] ;
}
V_24 = F_13 ( V_40 , V_42 , V_44 , V_30 , & V_34 -> V_36 ,
V_45 , V_34 -> V_19 ,
V_7 ) ;
V_56:
F_26 ( V_42 ) ;
return V_24 ;
}
static int F_27 ( struct V_50 * V_51 ,
int V_52 , T_1 V_45 ,
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
V_44 = F_28 ( V_13 ) ;
if ( ! V_44 )
return - V_14 ;
F_29 (ref, ref_safe, head, list) {
if ( V_34 -> V_31 )
continue;
if ( V_34 -> V_32 == 0 )
continue;
V_58 = F_17 ( V_51 , V_52 ,
V_45 , V_34 , V_44 ,
V_7 ) ;
if ( V_58 ) {
if ( V_24 == 0 )
V_24 = V_58 ;
continue;
}
F_30 ( & V_64 ) ;
V_62 = F_31 ( V_44 , & V_64 ) ;
V_34 -> V_31 = V_62 ? V_62 -> V_65 : 0 ;
V_34 -> V_37 = V_62 ?
(struct V_8 * ) ( V_49 ) V_62 -> V_66 : 0 ;
while ( ( V_62 = F_31 ( V_44 , & V_64 ) ) ) {
V_60 = F_4 ( sizeof( * V_60 ) , V_13 ) ;
if ( ! V_60 ) {
V_24 = - V_14 ;
break;
}
memcpy ( V_60 , V_34 , sizeof( * V_34 ) ) ;
V_60 -> V_31 = V_62 -> V_65 ;
V_60 -> V_37 = (struct V_8 * )
( V_49 ) V_62 -> V_66 ;
F_32 ( & V_60 -> V_38 , & V_34 -> V_38 ) ;
}
F_33 ( V_44 ) ;
}
F_34 ( V_44 ) ;
return V_24 ;
}
static inline int F_35 ( struct V_33 * V_67 ,
struct V_33 * V_68 )
{
if ( V_67 -> V_30 != V_68 -> V_30 )
return 0 ;
if ( V_67 -> V_29 != V_68 -> V_29 )
return 0 ;
if ( V_67 -> V_36 . type != V_68 -> V_36 . type )
return 0 ;
if ( V_67 -> V_36 . V_17 != V_68 -> V_36 . V_17 )
return 0 ;
if ( V_67 -> V_36 . V_18 != V_68 -> V_36 . V_18 )
return 0 ;
if ( V_67 -> V_31 != V_68 -> V_31 )
return 0 ;
return 1 ;
}
static int F_36 ( struct V_50 * V_51 ,
struct V_27 * V_28 )
{
struct V_27 * V_69 ;
struct V_3 * V_4 ;
F_37 (pos, head) {
struct V_33 * V_34 ;
V_34 = F_38 ( V_69 , struct V_33 , V_38 ) ;
if ( V_34 -> V_31 )
continue;
if ( V_34 -> V_36 . type )
continue;
F_39 ( ! V_34 -> V_19 ) ;
V_4 = F_40 ( V_51 -> V_70 , V_34 -> V_19 ,
V_51 -> V_70 -> V_71 , 0 ) ;
F_39 ( ! V_4 ) ;
F_41 ( V_4 ) ;
if ( F_42 ( V_4 ) == 0 )
F_7 ( V_4 , & V_34 -> V_36 , 0 ) ;
else
F_43 ( V_4 , & V_34 -> V_36 , 0 ) ;
F_44 ( V_4 ) ;
F_45 ( V_4 ) ;
}
return 0 ;
}
static int F_46 ( struct V_27 * V_28 , int V_72 )
{
struct V_27 * V_73 ;
F_37 (pos1, head) {
struct V_27 * V_74 ;
struct V_27 * V_75 ;
struct V_33 * V_67 ;
V_67 = F_38 ( V_73 , struct V_33 , V_38 ) ;
for ( V_75 = V_73 -> V_15 , V_74 = V_75 -> V_15 ; V_75 != V_28 ;
V_75 = V_74 , V_74 = V_75 -> V_15 ) {
struct V_33 * V_68 ;
struct V_33 * V_76 ;
V_68 = F_38 ( V_75 , struct V_33 , V_38 ) ;
if ( V_72 == 1 ) {
if ( ! F_35 ( V_67 , V_68 ) )
continue;
if ( ! V_67 -> V_31 && V_68 -> V_31 ) {
V_76 = V_67 ;
V_67 = V_68 ;
V_68 = V_76 ;
}
V_67 -> V_32 += V_68 -> V_32 ;
} else {
if ( V_67 -> V_31 != V_68 -> V_31 )
continue;
V_67 -> V_32 += V_68 -> V_32 ;
}
F_47 ( & V_68 -> V_38 ) ;
F_48 ( V_68 ) ;
}
}
return 0 ;
}
static int F_49 ( struct V_77 * V_28 , T_1 V_78 ,
struct V_27 * V_79 )
{
struct V_80 * V_81 = V_28 -> V_81 ;
struct V_82 * V_83 = & V_28 -> V_62 . V_82 ;
struct V_1 V_2 ;
struct V_1 V_84 = { 0 } ;
int V_85 ;
int V_24 = 0 ;
if ( V_81 && V_81 -> V_86 )
F_50 ( & V_84 , & V_81 -> V_2 ) ;
while ( ( V_83 = F_51 ( V_83 ) ) ) {
struct V_87 * V_62 ;
V_62 = F_52 ( V_83 , struct V_87 ,
V_82 ) ;
if ( V_62 -> V_88 != V_28 -> V_62 . V_88 )
break;
F_25 ( V_62 -> V_89 ) ;
if ( V_62 -> V_78 > V_78 )
continue;
switch ( V_62 -> V_90 ) {
case V_91 :
case V_92 :
F_25 ( 1 ) ;
continue;
case V_93 :
V_85 = 1 ;
break;
case V_94 :
V_85 = - 1 ;
break;
default:
F_39 ( 1 ) ;
}
switch ( V_62 -> type ) {
case V_95 : {
struct V_96 * V_34 ;
V_34 = F_53 ( V_62 ) ;
V_24 = F_11 ( V_79 , V_34 -> V_40 , & V_84 ,
V_34 -> V_30 + 1 , 0 , V_62 -> V_88 ,
V_62 -> V_97 * V_85 ) ;
break;
}
case V_98 : {
struct V_96 * V_34 ;
V_34 = F_53 ( V_62 ) ;
V_24 = F_11 ( V_79 , V_34 -> V_40 , NULL ,
V_34 -> V_30 + 1 , V_34 -> V_31 ,
V_62 -> V_88 ,
V_62 -> V_97 * V_85 ) ;
break;
}
case V_99 : {
struct V_100 * V_34 ;
V_34 = F_54 ( V_62 ) ;
V_2 . V_17 = V_34 -> V_17 ;
V_2 . type = V_25 ;
V_2 . V_18 = V_34 -> V_18 ;
V_24 = F_11 ( V_79 , V_34 -> V_40 , & V_2 , 0 , 0 ,
V_62 -> V_88 ,
V_62 -> V_97 * V_85 ) ;
break;
}
case V_101 : {
struct V_100 * V_34 ;
V_34 = F_54 ( V_62 ) ;
V_2 . V_17 = V_34 -> V_17 ;
V_2 . type = V_25 ;
V_2 . V_18 = V_34 -> V_18 ;
V_24 = F_11 ( V_79 , V_34 -> V_40 , & V_2 , 0 ,
V_34 -> V_31 , V_62 -> V_88 ,
V_62 -> V_97 * V_85 ) ;
break;
}
default:
F_25 ( 1 ) ;
}
F_39 ( V_24 ) ;
}
return 0 ;
}
static int F_55 ( struct V_50 * V_51 ,
struct V_41 * V_42 , T_1 V_88 ,
int * V_102 , struct V_27 * V_79 )
{
int V_24 = 0 ;
int V_21 ;
struct V_3 * V_103 ;
struct V_1 V_2 ;
unsigned long V_104 ;
unsigned long V_105 ;
struct V_106 * V_107 ;
T_1 V_108 ;
T_1 V_109 ;
V_103 = V_42 -> V_46 [ 0 ] ;
V_21 = V_42 -> V_48 [ 0 ] ;
V_109 = F_56 ( V_103 , V_21 ) ;
F_39 ( V_109 < sizeof( * V_107 ) ) ;
V_107 = F_8 ( V_103 , V_21 , struct V_106 ) ;
V_108 = F_57 ( V_103 , V_107 ) ;
V_104 = ( unsigned long ) ( V_107 + 1 ) ;
V_105 = ( unsigned long ) V_107 + V_109 ;
if ( V_108 & V_110 ) {
struct V_111 * V_112 ;
V_112 = (struct V_111 * ) V_104 ;
* V_102 = F_58 ( V_103 , V_112 ) ;
V_104 += sizeof( struct V_111 ) ;
F_39 ( V_104 > V_105 ) ;
} else {
F_39 ( ! ( V_108 & V_113 ) ) ;
}
while ( V_104 < V_105 ) {
struct V_114 * V_115 ;
T_1 V_18 ;
int type ;
V_115 = (struct V_114 * ) V_104 ;
type = F_59 ( V_103 , V_115 ) ;
V_18 = F_60 ( V_103 , V_115 ) ;
switch ( type ) {
case V_98 :
V_24 = F_11 ( V_79 , 0 , NULL ,
* V_102 + 1 , V_18 ,
V_88 , 1 ) ;
break;
case V_101 : {
struct V_116 * V_117 ;
int V_32 ;
V_117 = (struct V_116 * ) ( V_115 + 1 ) ;
V_32 = F_61 ( V_103 , V_117 ) ;
V_24 = F_11 ( V_79 , 0 , NULL , 0 , V_18 ,
V_88 , V_32 ) ;
break;
}
case V_95 :
V_24 = F_11 ( V_79 , V_18 , NULL ,
* V_102 + 1 , 0 ,
V_88 , 1 ) ;
break;
case V_99 : {
struct V_118 * V_119 ;
int V_32 ;
T_1 V_40 ;
V_119 = (struct V_118 * ) ( & V_115 -> V_18 ) ;
V_32 = F_62 ( V_103 , V_119 ) ;
V_2 . V_17 = F_63 ( V_103 ,
V_119 ) ;
V_2 . type = V_25 ;
V_2 . V_18 = F_64 ( V_103 , V_119 ) ;
V_40 = F_65 ( V_103 , V_119 ) ;
V_24 = F_11 ( V_79 , V_40 , & V_2 , 0 , 0 ,
V_88 , V_32 ) ;
break;
}
default:
F_25 ( 1 ) ;
}
F_39 ( V_24 ) ;
V_104 += F_66 ( type ) ;
}
return 0 ;
}
static int F_67 ( struct V_50 * V_51 ,
struct V_41 * V_42 , T_1 V_88 ,
int V_102 , struct V_27 * V_79 )
{
struct V_39 * V_120 = V_51 -> V_120 ;
int V_24 ;
int V_21 ;
struct V_3 * V_103 ;
struct V_1 V_2 ;
while ( 1 ) {
V_24 = F_68 ( V_120 , V_42 ) ;
if ( V_24 < 0 )
break;
if ( V_24 ) {
V_24 = 0 ;
break;
}
V_21 = V_42 -> V_48 [ 0 ] ;
V_103 = V_42 -> V_46 [ 0 ] ;
F_7 ( V_103 , & V_2 , V_21 ) ;
if ( V_2 . V_17 != V_88 )
break;
if ( V_2 . type < V_95 )
continue;
if ( V_2 . type > V_101 )
break;
switch ( V_2 . type ) {
case V_98 :
V_24 = F_11 ( V_79 , 0 , NULL ,
V_102 + 1 , V_2 . V_18 ,
V_88 , 1 ) ;
break;
case V_101 : {
struct V_116 * V_117 ;
int V_32 ;
V_117 = F_8 ( V_103 , V_21 ,
struct V_116 ) ;
V_32 = F_61 ( V_103 , V_117 ) ;
V_24 = F_11 ( V_79 , 0 , NULL , 0 , V_2 . V_18 ,
V_88 , V_32 ) ;
break;
}
case V_95 :
V_24 = F_11 ( V_79 , V_2 . V_18 , NULL ,
V_102 + 1 , 0 ,
V_88 , 1 ) ;
break;
case V_99 : {
struct V_118 * V_119 ;
int V_32 ;
T_1 V_40 ;
V_119 = F_8 ( V_103 , V_21 ,
struct V_118 ) ;
V_32 = F_62 ( V_103 , V_119 ) ;
V_2 . V_17 = F_63 ( V_103 ,
V_119 ) ;
V_2 . type = V_25 ;
V_2 . V_18 = F_64 ( V_103 , V_119 ) ;
V_40 = F_65 ( V_103 , V_119 ) ;
V_24 = F_11 ( V_79 , V_40 , & V_2 , 0 , 0 ,
V_88 , V_32 ) ;
break;
}
default:
F_25 ( 1 ) ;
}
F_39 ( V_24 ) ;
}
return V_24 ;
}
static int F_69 ( struct V_121 * V_122 ,
struct V_50 * V_51 , T_1 V_88 ,
T_1 V_45 , struct V_43 * V_123 ,
struct V_43 * V_124 , const T_1 * V_7 )
{
struct V_1 V_2 ;
struct V_41 * V_42 ;
struct V_125 * V_126 = NULL ;
struct V_77 * V_28 ;
int V_102 = 0 ;
int V_24 ;
int V_52 = ( V_122 == V_127 ) ;
struct V_27 V_128 ;
struct V_27 V_79 ;
struct V_33 * V_34 ;
F_70 ( & V_79 ) ;
F_70 ( & V_128 ) ;
V_2 . V_17 = V_88 ;
V_2 . type = V_129 ;
V_2 . V_18 = ( T_1 ) - 1 ;
V_42 = F_18 () ;
if ( ! V_42 )
return - V_14 ;
V_42 -> V_52 = ! ! V_52 ;
V_130:
V_28 = NULL ;
V_24 = F_71 ( V_122 , V_51 -> V_120 , & V_2 , V_42 , 0 , 0 ) ;
if ( V_24 < 0 )
goto V_56;
F_39 ( V_24 == 0 ) ;
if ( V_122 != V_127 ) {
V_126 = & V_122 -> V_131 -> V_126 ;
F_72 ( & V_126 -> V_132 ) ;
V_28 = F_73 ( V_122 , V_88 ) ;
if ( V_28 ) {
if ( ! F_74 ( & V_28 -> V_133 ) ) {
F_75 ( & V_28 -> V_62 . V_123 ) ;
F_76 ( & V_126 -> V_132 ) ;
F_77 ( V_42 ) ;
F_78 ( & V_28 -> V_133 ) ;
F_79 ( & V_28 -> V_133 ) ;
F_80 ( & V_28 -> V_62 ) ;
goto V_130;
}
V_24 = F_49 ( V_28 , V_45 ,
& V_128 ) ;
F_79 ( & V_28 -> V_133 ) ;
if ( V_24 ) {
F_76 ( & V_126 -> V_132 ) ;
goto V_56;
}
}
F_76 ( & V_126 -> V_132 ) ;
}
if ( V_42 -> V_48 [ 0 ] ) {
struct V_3 * V_103 ;
int V_21 ;
V_42 -> V_48 [ 0 ] -- ;
V_103 = V_42 -> V_46 [ 0 ] ;
V_21 = V_42 -> V_48 [ 0 ] ;
F_7 ( V_103 , & V_2 , V_21 ) ;
if ( V_2 . V_17 == V_88 &&
V_2 . type == V_129 ) {
V_24 = F_55 ( V_51 , V_42 , V_88 ,
& V_102 , & V_79 ) ;
if ( V_24 )
goto V_56;
V_24 = F_67 ( V_51 , V_42 , V_88 ,
V_102 , & V_79 ) ;
if ( V_24 )
goto V_56;
}
}
F_77 ( V_42 ) ;
F_81 ( & V_128 , & V_79 ) ;
V_24 = F_36 ( V_51 , & V_79 ) ;
if ( V_24 )
goto V_56;
V_24 = F_46 ( & V_79 , 1 ) ;
if ( V_24 )
goto V_56;
V_24 = F_27 ( V_51 , V_52 , V_45 ,
& V_79 , V_7 ) ;
if ( V_24 )
goto V_56;
V_24 = F_46 ( & V_79 , 2 ) ;
if ( V_24 )
goto V_56;
while ( ! F_82 ( & V_79 ) ) {
V_34 = F_83 ( & V_79 , struct V_33 , V_38 ) ;
F_47 ( & V_34 -> V_38 ) ;
if ( V_34 -> V_32 < 0 )
F_25 ( 1 ) ;
if ( V_34 -> V_32 && V_34 -> V_29 && V_34 -> V_31 == 0 ) {
V_24 = F_14 ( V_124 , V_34 -> V_29 , 0 , V_13 ) ;
F_39 ( V_24 < 0 ) ;
}
if ( V_34 -> V_32 && V_34 -> V_31 ) {
struct V_8 * V_9 = NULL ;
if ( V_7 && ! V_34 -> V_37 ) {
T_2 V_134 ;
struct V_3 * V_4 ;
V_134 = F_84 ( V_51 -> V_120 ,
V_102 ) ;
V_4 = F_40 ( V_51 -> V_120 ,
V_34 -> V_31 , V_134 , 0 ) ;
F_39 ( ! V_4 ) ;
V_24 = F_5 ( V_4 , V_88 ,
* V_7 , & V_9 ) ;
V_34 -> V_37 = V_9 ;
F_45 ( V_4 ) ;
}
V_24 = F_85 ( V_123 , V_34 -> V_31 ,
( V_49 ) V_34 -> V_37 ,
( T_1 * ) & V_9 , V_13 ) ;
if ( ! V_24 && V_7 ) {
F_39 ( ! V_9 ) ;
while ( V_9 -> V_15 )
V_9 = V_9 -> V_15 ;
V_9 -> V_15 = V_34 -> V_37 ;
}
F_39 ( V_24 < 0 ) ;
}
F_48 ( V_34 ) ;
}
V_56:
F_26 ( V_42 ) ;
while ( ! F_82 ( & V_79 ) ) {
V_34 = F_83 ( & V_79 , struct V_33 , V_38 ) ;
F_47 ( & V_34 -> V_38 ) ;
F_48 ( V_34 ) ;
}
while ( ! F_82 ( & V_128 ) ) {
V_34 = F_83 ( & V_128 , struct V_33 ,
V_38 ) ;
F_47 ( & V_34 -> V_38 ) ;
F_48 ( V_34 ) ;
}
return V_24 ;
}
static void F_86 ( struct V_43 * V_135 )
{
struct V_61 * V_62 = NULL ;
struct V_8 * V_9 ;
struct V_8 * V_136 ;
struct V_63 V_64 ;
F_30 ( & V_64 ) ;
while ( ( V_62 = F_31 ( V_135 , & V_64 ) ) ) {
if ( ! V_62 -> V_66 )
continue;
V_9 = (struct V_8 * ) ( V_49 ) V_62 -> V_66 ;
for (; V_9 ; V_9 = V_136 ) {
V_136 = V_9 -> V_15 ;
F_48 ( V_9 ) ;
}
V_62 -> V_66 = 0 ;
}
F_34 ( V_135 ) ;
}
static int F_87 ( struct V_121 * V_122 ,
struct V_50 * V_51 , T_1 V_88 ,
T_1 V_45 , struct V_43 * * V_137 ,
const T_1 * V_7 )
{
struct V_43 * V_138 ;
int V_24 ;
V_138 = F_28 ( V_13 ) ;
if ( ! V_138 )
return - V_14 ;
* V_137 = F_28 ( V_13 ) ;
if ( ! * V_137 ) {
F_34 ( V_138 ) ;
return - V_14 ;
}
V_24 = F_69 ( V_122 , V_51 , V_88 ,
V_45 , * V_137 , V_138 , V_7 ) ;
F_34 ( V_138 ) ;
if ( V_24 < 0 && V_24 != - V_139 ) {
F_86 ( * V_137 ) ;
return V_24 ;
}
return 0 ;
}
int F_88 ( struct V_121 * V_122 ,
struct V_50 * V_51 , T_1 V_88 ,
T_1 V_45 , struct V_43 * * V_124 )
{
struct V_43 * V_138 ;
struct V_61 * V_62 = NULL ;
struct V_63 V_64 ;
int V_24 ;
V_138 = F_28 ( V_13 ) ;
if ( ! V_138 )
return - V_14 ;
* V_124 = F_28 ( V_13 ) ;
if ( ! * V_124 ) {
F_34 ( V_138 ) ;
return - V_14 ;
}
F_30 ( & V_64 ) ;
while ( 1 ) {
V_24 = F_69 ( V_122 , V_51 , V_88 ,
V_45 , V_138 , * V_124 , NULL ) ;
if ( V_24 < 0 && V_24 != - V_139 ) {
F_34 ( V_138 ) ;
F_34 ( * V_124 ) ;
return V_24 ;
}
V_62 = F_31 ( V_138 , & V_64 ) ;
if ( ! V_62 )
break;
V_88 = V_62 -> V_65 ;
}
F_34 ( V_138 ) ;
return 0 ;
}
static int F_89 ( T_1 V_16 , T_1 V_140 , T_3 V_141 ,
struct V_39 * V_142 , struct V_41 * V_42 ,
struct V_1 * V_143 )
{
int V_24 ;
struct V_1 V_2 ;
struct V_3 * V_4 ;
V_2 . type = V_141 ;
V_2 . V_17 = V_16 ;
V_2 . V_18 = V_140 ;
V_24 = F_71 ( NULL , V_142 , & V_2 , V_42 , 0 , 0 ) ;
if ( V_24 < 0 )
return V_24 ;
V_4 = V_42 -> V_46 [ 0 ] ;
if ( V_24 && V_42 -> V_48 [ 0 ] >= F_6 ( V_4 ) ) {
V_24 = F_90 ( V_142 , V_42 ) ;
if ( V_24 )
return V_24 ;
V_4 = V_42 -> V_46 [ 0 ] ;
}
F_7 ( V_4 , V_143 , V_42 -> V_48 [ 0 ] ) ;
if ( V_143 -> type != V_2 . type || V_143 -> V_17 != V_2 . V_17 )
return 1 ;
return 0 ;
}
int F_91 ( T_1 V_16 , T_1 V_140 , struct V_39 * V_142 ,
struct V_41 * V_42 )
{
struct V_1 V_2 ;
return F_89 ( V_16 , V_140 , V_144 , V_142 , V_42 ,
& V_2 ) ;
}
static int F_92 ( T_1 V_16 , T_1 V_140 , struct V_39 * V_142 ,
struct V_41 * V_42 ,
struct V_1 * V_143 )
{
return F_89 ( V_16 , V_140 , V_145 , V_142 , V_42 ,
V_143 ) ;
}
int F_93 ( struct V_39 * V_40 , T_1 V_146 ,
T_1 V_147 , struct V_41 * V_42 ,
struct V_148 * * V_149 ,
T_1 * V_150 )
{
int V_24 , V_21 ;
struct V_1 V_2 ;
struct V_1 V_143 ;
struct V_148 * V_151 ;
struct V_3 * V_103 ;
unsigned long V_104 ;
V_2 . V_17 = V_146 ;
F_94 ( & V_2 , V_152 ) ;
V_2 . V_18 = V_147 ;
V_24 = F_71 ( NULL , V_40 , & V_2 , V_42 , 0 , 0 ) ;
if ( V_24 < 0 )
return V_24 ;
while ( 1 ) {
V_103 = V_42 -> V_46 [ 0 ] ;
V_21 = V_42 -> V_48 [ 0 ] ;
if ( V_21 >= F_6 ( V_103 ) ) {
V_24 = F_90 ( V_40 , V_42 ) ;
if ( V_24 ) {
if ( V_24 >= 1 )
V_24 = - V_139 ;
break;
}
continue;
}
F_7 ( V_103 , & V_143 , V_21 ) ;
V_24 = - V_139 ;
if ( V_143 . V_17 != V_146 )
break;
if ( F_95 ( & V_143 ) != V_152 )
break;
V_24 = 0 ;
V_104 = F_96 ( V_103 , V_42 -> V_48 [ 0 ] ) ;
V_151 = (struct V_148 * ) V_104 ;
* V_149 = V_151 ;
if ( V_150 )
* V_150 = V_143 . V_18 ;
break;
}
return V_24 ;
}
char * F_97 ( struct V_39 * V_142 , struct V_41 * V_42 ,
T_2 V_153 , unsigned long V_154 ,
struct V_3 * V_155 , T_1 V_31 ,
char * V_156 , T_2 V_157 )
{
int V_21 ;
T_1 V_158 ;
int V_24 ;
T_4 V_159 = ( ( T_4 ) V_157 ) - 1 ;
struct V_3 * V_4 = V_155 ;
struct V_1 V_143 ;
int V_160 = V_42 -> V_160 ;
struct V_161 * V_115 ;
if ( V_159 >= 0 )
V_156 [ V_159 ] = '\0' ;
V_42 -> V_160 = 1 ;
while ( 1 ) {
V_159 -= V_153 ;
if ( V_159 >= 0 )
F_98 ( V_4 , V_156 + V_159 ,
V_154 , V_153 ) ;
if ( V_4 != V_155 ) {
F_99 ( V_4 ) ;
F_45 ( V_4 ) ;
}
V_24 = F_92 ( V_31 , 0 , V_142 , V_42 , & V_143 ) ;
if ( V_24 > 0 )
V_24 = - V_139 ;
if ( V_24 )
break;
V_158 = V_143 . V_18 ;
if ( V_31 == V_158 )
break;
V_21 = V_42 -> V_48 [ 0 ] ;
V_4 = V_42 -> V_46 [ 0 ] ;
if ( V_4 != V_155 ) {
F_75 ( & V_4 -> V_123 ) ;
F_41 ( V_4 ) ;
F_100 ( V_4 , V_162 ) ;
}
F_77 ( V_42 ) ;
V_115 = F_8 ( V_4 , V_21 , struct V_161 ) ;
V_153 = F_101 ( V_4 , V_115 ) ;
V_154 = ( unsigned long ) ( V_115 + 1 ) ;
V_31 = V_158 ;
-- V_159 ;
if ( V_159 >= 0 )
V_156 [ V_159 ] = '/' ;
}
F_77 ( V_42 ) ;
V_42 -> V_160 = V_160 ;
if ( V_24 )
return F_102 ( V_24 ) ;
return V_156 + V_159 ;
}
char * F_103 ( struct V_39 * V_142 ,
struct V_41 * V_42 ,
struct V_161 * V_115 ,
struct V_3 * V_155 , T_1 V_31 ,
char * V_156 , T_2 V_157 )
{
return F_97 ( V_142 , V_42 ,
F_101 ( V_155 , V_115 ) ,
( unsigned long ) ( V_115 + 1 ) ,
V_155 , V_31 , V_156 , V_157 ) ;
}
int F_104 ( struct V_50 * V_51 , T_1 V_163 ,
struct V_41 * V_42 , struct V_1 * V_143 ,
T_1 * V_164 )
{
int V_24 ;
T_1 V_108 ;
T_2 V_109 ;
struct V_3 * V_4 ;
struct V_106 * V_107 ;
struct V_1 V_2 ;
V_2 . type = V_129 ;
V_2 . V_17 = V_163 ;
V_2 . V_18 = ( T_1 ) - 1 ;
V_24 = F_71 ( NULL , V_51 -> V_120 , & V_2 , V_42 , 0 , 0 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_105 ( V_51 -> V_120 , V_42 ,
0 , V_129 ) ;
if ( V_24 < 0 )
return V_24 ;
F_7 ( V_42 -> V_46 [ 0 ] , V_143 , V_42 -> V_48 [ 0 ] ) ;
if ( V_143 -> type != V_129 ||
V_143 -> V_17 > V_163 ||
V_143 -> V_17 + V_143 -> V_18 <= V_163 ) {
F_24 ( L_3 ,
( unsigned long long ) V_163 ) ;
return - V_139 ;
}
V_4 = V_42 -> V_46 [ 0 ] ;
V_109 = F_56 ( V_4 , V_42 -> V_48 [ 0 ] ) ;
F_39 ( V_109 < sizeof( * V_107 ) ) ;
V_107 = F_8 ( V_4 , V_42 -> V_48 [ 0 ] , struct V_106 ) ;
V_108 = F_57 ( V_4 , V_107 ) ;
F_24 ( L_4
L_5 ,
( unsigned long long ) V_163 ,
( unsigned long long ) ( V_163 - V_143 -> V_17 ) ,
( unsigned long long ) V_143 -> V_17 ,
( unsigned long long ) V_143 -> V_18 ,
( unsigned long long ) V_108 , V_109 ) ;
F_25 ( ! V_164 ) ;
if ( V_164 ) {
if ( V_108 & V_110 )
* V_164 = V_110 ;
else if ( V_108 & V_113 )
* V_164 = V_113 ;
else
F_39 ( 1 ) ;
return 0 ;
}
return - V_165 ;
}
static int F_106 ( unsigned long * V_104 , struct V_3 * V_4 ,
struct V_106 * V_107 , T_2 V_109 ,
struct V_114 * * V_166 ,
int * V_167 )
{
unsigned long V_105 ;
T_1 V_108 ;
struct V_111 * V_112 ;
if ( ! * V_104 ) {
V_108 = F_57 ( V_4 , V_107 ) ;
if ( V_108 & V_110 ) {
V_112 = (struct V_111 * ) ( V_107 + 1 ) ;
* V_166 =
(struct V_114 * ) ( V_112 + 1 ) ;
} else {
* V_166 = (struct V_114 * ) ( V_107 + 1 ) ;
}
* V_104 = ( unsigned long ) * V_166 ;
if ( ( void * ) * V_104 >= ( void * ) V_107 + V_109 )
return - V_139 ;
}
V_105 = ( unsigned long ) V_107 + V_109 ;
* V_166 = (struct V_114 * ) * V_104 ;
* V_167 = F_59 ( V_4 , * V_166 ) ;
* V_104 += F_66 ( * V_167 ) ;
F_25 ( * V_104 > V_105 ) ;
if ( * V_104 == V_105 )
return 1 ;
return 0 ;
}
int F_107 ( unsigned long * V_104 , struct V_3 * V_4 ,
struct V_106 * V_107 , T_2 V_109 ,
T_1 * V_168 , T_3 * V_169 )
{
int V_24 ;
int type ;
struct V_111 * V_112 ;
struct V_114 * V_170 ;
if ( * V_104 == ( unsigned long ) - 1 )
return 1 ;
while ( 1 ) {
V_24 = F_106 ( V_104 , V_4 , V_107 , V_109 ,
& V_170 , & type ) ;
if ( V_24 < 0 )
return V_24 ;
if ( type == V_95 ||
type == V_98 )
break;
if ( V_24 == 1 )
return 1 ;
}
V_112 = (struct V_111 * ) ( V_107 + 1 ) ;
* V_168 = F_60 ( V_4 , V_170 ) ;
* V_169 = F_58 ( V_4 , V_112 ) ;
if ( V_24 == 1 )
* V_104 = ( unsigned long ) - 1 ;
return 0 ;
}
static int F_108 ( struct V_8 * V_37 ,
T_1 V_40 , T_1 V_171 ,
T_5 * V_172 , void * V_173 )
{
struct V_8 * V_9 ;
int V_24 = 0 ;
for ( V_9 = V_37 ; V_9 ; V_9 = V_9 -> V_15 ) {
F_24 ( L_6
L_7 , V_171 ,
V_9 -> V_16 , V_9 -> V_18 , V_40 ) ;
V_24 = V_172 ( V_9 -> V_16 , V_9 -> V_18 , V_40 , V_173 ) ;
if ( V_24 ) {
F_24 ( L_8 ,
V_171 , V_24 ) ;
break;
}
}
return V_24 ;
}
int F_109 ( struct V_50 * V_51 ,
T_1 V_171 , T_1 V_7 ,
int V_52 ,
T_5 * V_172 , void * V_173 )
{
int V_24 ;
struct V_27 V_174 = F_110 ( V_174 ) ;
struct V_27 V_175 = F_110 ( V_175 ) ;
struct V_121 * V_122 ;
struct V_43 * V_123 = NULL ;
struct V_43 * V_124 = NULL ;
struct V_61 * V_176 = NULL ;
struct V_61 * V_177 = NULL ;
struct V_178 V_179 = {} ;
struct V_63 V_180 ;
struct V_63 V_181 ;
F_24 ( L_9 ,
V_171 ) ;
if ( V_52 ) {
V_122 = V_127 ;
} else {
V_122 = F_111 ( V_51 -> V_120 ) ;
if ( F_20 ( V_122 ) )
return F_21 ( V_122 ) ;
F_112 ( V_51 , & V_179 ) ;
}
V_24 = F_87 ( V_122 , V_51 , V_171 ,
V_179 . V_78 , & V_123 ,
& V_7 ) ;
if ( V_24 )
goto V_56;
F_30 ( & V_180 ) ;
while ( ! V_24 && ( V_176 = F_31 ( V_123 , & V_180 ) ) ) {
V_24 = F_88 ( V_122 , V_51 , V_176 -> V_65 ,
V_179 . V_78 , & V_124 ) ;
if ( V_24 )
break;
F_30 ( & V_181 ) ;
while ( ! V_24 && ( V_177 = F_31 ( V_124 , & V_181 ) ) ) {
F_24 ( L_10
L_11 , V_177 -> V_65 , V_176 -> V_65 ,
( long long ) V_176 -> V_66 ) ;
V_24 = F_108 ( (struct V_8 * )
( V_49 ) V_176 -> V_66 ,
V_177 -> V_65 ,
V_171 ,
V_172 , V_173 ) ;
}
F_34 ( V_124 ) ;
V_124 = NULL ;
}
F_86 ( V_123 ) ;
F_34 ( V_124 ) ;
V_56:
if ( ! V_52 ) {
F_113 ( V_51 , & V_179 ) ;
F_114 ( V_122 , V_51 -> V_120 ) ;
}
return V_24 ;
}
int F_115 ( T_1 V_163 , struct V_50 * V_51 ,
struct V_41 * V_42 ,
T_5 * V_172 , void * V_173 )
{
int V_24 ;
T_1 V_7 ;
T_1 V_108 = 0 ;
struct V_1 V_143 ;
int V_52 = V_42 -> V_52 ;
V_24 = F_104 ( V_51 , V_163 , V_42 , & V_143 , & V_108 ) ;
F_77 ( V_42 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_108 & V_110 )
return - V_182 ;
V_7 = V_163 - V_143 . V_17 ;
V_24 = F_109 ( V_51 , V_143 . V_17 ,
V_7 , V_52 ,
V_172 , V_173 ) ;
return V_24 ;
}
static int F_116 ( T_1 V_16 , struct V_39 * V_142 ,
struct V_41 * V_42 ,
T_6 * V_172 , void * V_173 )
{
int V_24 = 0 ;
int V_21 ;
T_2 V_183 ;
T_2 V_184 ;
T_2 V_153 ;
T_1 V_31 = 0 ;
int V_185 = 0 ;
struct V_3 * V_4 ;
struct V_186 * V_187 ;
struct V_161 * V_115 ;
struct V_1 V_143 ;
while ( ! V_24 ) {
V_42 -> V_160 = 1 ;
V_24 = F_92 ( V_16 , V_31 ? V_31 + 1 : 0 , V_142 , V_42 ,
& V_143 ) ;
if ( V_24 < 0 )
break;
if ( V_24 ) {
V_24 = V_185 ? 0 : - V_139 ;
break;
}
++ V_185 ;
V_31 = V_143 . V_18 ;
V_21 = V_42 -> V_48 [ 0 ] ;
V_4 = V_42 -> V_46 [ 0 ] ;
F_75 ( & V_4 -> V_123 ) ;
F_41 ( V_4 ) ;
F_100 ( V_4 , V_162 ) ;
F_77 ( V_42 ) ;
V_187 = F_117 ( V_4 , V_21 ) ;
V_115 = F_8 ( V_4 , V_21 , struct V_161 ) ;
for ( V_183 = 0 ; V_183 < F_118 ( V_4 , V_187 ) ; V_183 += V_184 ) {
V_153 = F_101 ( V_4 , V_115 ) ;
F_24 ( L_12
L_13 , V_183 ,
( unsigned long long ) V_143 . V_17 ,
( unsigned long long ) V_142 -> V_17 ) ;
V_24 = V_172 ( V_31 , V_153 ,
( unsigned long ) ( V_115 + 1 ) , V_4 , V_173 ) ;
if ( V_24 )
break;
V_184 = sizeof( * V_115 ) + V_153 ;
V_115 = (struct V_161 * ) ( ( char * ) V_115 + V_184 ) ;
}
F_99 ( V_4 ) ;
F_45 ( V_4 ) ;
}
F_77 ( V_42 ) ;
return V_24 ;
}
static int F_119 ( T_1 V_16 , struct V_39 * V_142 ,
struct V_41 * V_42 ,
T_6 * V_172 , void * V_173 )
{
int V_24 ;
int V_21 ;
T_1 V_18 = 0 ;
T_1 V_31 ;
int V_185 = 0 ;
struct V_3 * V_4 ;
struct V_148 * V_151 ;
struct V_3 * V_103 ;
T_2 V_109 ;
T_2 V_188 ;
unsigned long V_104 ;
while ( 1 ) {
V_24 = F_93 ( V_142 , V_16 , V_18 , V_42 , & V_151 ,
& V_18 ) ;
if ( V_24 < 0 )
break;
if ( V_24 ) {
V_24 = V_185 ? 0 : - V_139 ;
break;
}
++ V_185 ;
V_21 = V_42 -> V_48 [ 0 ] ;
V_4 = V_42 -> V_46 [ 0 ] ;
F_75 ( & V_4 -> V_123 ) ;
F_41 ( V_4 ) ;
F_100 ( V_4 , V_162 ) ;
F_77 ( V_42 ) ;
V_103 = V_42 -> V_46 [ 0 ] ;
V_109 = F_56 ( V_103 , V_42 -> V_48 [ 0 ] ) ;
V_104 = F_96 ( V_103 , V_42 -> V_48 [ 0 ] ) ;
V_188 = 0 ;
while ( V_188 < V_109 ) {
T_2 V_153 ;
V_151 = (struct V_148 * ) ( V_104 + V_188 ) ;
V_31 = F_120 ( V_4 , V_151 ) ;
V_153 = F_121 ( V_4 , V_151 ) ;
V_24 = V_172 ( V_31 , V_153 ,
( unsigned long ) & V_151 -> V_189 , V_4 , V_173 ) ;
if ( V_24 )
break;
V_188 += F_121 ( V_103 , V_151 ) ;
V_188 += sizeof( * V_151 ) ;
}
F_99 ( V_4 ) ;
F_45 ( V_4 ) ;
V_18 ++ ;
}
F_77 ( V_42 ) ;
return V_24 ;
}
static int F_122 ( T_1 V_16 , struct V_39 * V_142 ,
struct V_41 * V_42 , T_6 * V_172 ,
void * V_173 )
{
int V_24 ;
int V_190 = 0 ;
V_24 = F_116 ( V_16 , V_142 , V_42 , V_172 , V_173 ) ;
if ( ! V_24 )
++ V_190 ;
else if ( V_24 != - V_139 )
return V_24 ;
V_24 = F_119 ( V_16 , V_142 , V_42 , V_172 , V_173 ) ;
if ( V_24 == - V_139 && V_190 )
return 0 ;
return V_24 ;
}
static int F_123 ( T_1 V_16 , T_2 V_153 , unsigned long V_154 ,
struct V_3 * V_4 , void * V_173 )
{
struct V_191 * V_192 = V_173 ;
char * V_193 ;
char * V_194 ;
int V_195 = V_192 -> V_193 -> V_196 ;
const int V_197 = sizeof( char * ) ;
T_2 V_159 ;
V_159 = V_192 -> V_193 -> V_159 > V_197 ?
V_192 -> V_193 -> V_159 - V_197 : 0 ;
V_194 = ( char * ) V_192 -> V_193 -> V_65 + ( V_195 + 1 ) * V_197 ;
V_193 = F_97 ( V_192 -> V_142 , V_192 -> V_41 , V_153 ,
V_154 , V_4 , V_16 , V_194 , V_159 ) ;
if ( F_20 ( V_193 ) )
return F_21 ( V_193 ) ;
if ( V_193 > V_194 ) {
V_192 -> V_193 -> V_65 [ V_195 ] = ( T_1 ) ( unsigned long ) V_193 ;
++ V_192 -> V_193 -> V_196 ;
V_192 -> V_193 -> V_159 = V_193 - V_194 ;
} else {
++ V_192 -> V_193 -> V_198 ;
V_192 -> V_193 -> V_199 += V_194 - V_193 ;
V_192 -> V_193 -> V_159 = 0 ;
}
return 0 ;
}
int F_124 ( T_1 V_16 , struct V_191 * V_192 )
{
return F_122 ( V_16 , V_192 -> V_142 , V_192 -> V_41 ,
F_123 , V_192 ) ;
}
struct V_200 * F_125 ( T_2 V_201 )
{
struct V_200 * V_202 ;
T_7 V_203 ;
V_203 = F_126 ( T_7 , V_201 , sizeof( * V_202 ) ) ;
V_202 = F_127 ( V_203 ) ;
if ( ! V_202 )
return F_102 ( - V_14 ) ;
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
struct V_191 * F_128 ( T_8 V_201 , struct V_39 * V_142 ,
struct V_41 * V_42 )
{
struct V_191 * V_204 ;
struct V_200 * V_193 ;
V_193 = F_125 ( V_201 ) ;
if ( F_20 ( V_193 ) )
return ( void * ) V_193 ;
V_204 = F_4 ( sizeof( * V_204 ) , V_13 ) ;
if ( ! V_204 ) {
F_48 ( V_193 ) ;
return F_102 ( - V_14 ) ;
}
V_204 -> V_41 = V_42 ;
V_204 -> V_193 = V_193 ;
V_204 -> V_142 = V_142 ;
return V_204 ;
}
void F_129 ( struct V_191 * V_192 )
{
if ( ! V_192 )
return;
F_130 ( V_192 -> V_193 ) ;
F_48 ( V_192 ) ;
}
