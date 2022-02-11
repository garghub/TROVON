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
if ( V_58 == - V_14 )
goto V_56;
if ( V_58 )
continue;
F_30 ( & V_64 ) ;
V_62 = F_31 ( V_44 , & V_64 ) ;
V_34 -> V_31 = V_62 ? V_62 -> V_65 : 0 ;
V_34 -> V_37 = V_62 ?
(struct V_8 * ) ( V_49 ) V_62 -> V_66 : 0 ;
while ( ( V_62 = F_31 ( V_44 , & V_64 ) ) ) {
V_60 = F_4 ( sizeof( * V_60 ) , V_13 ) ;
if ( ! V_60 ) {
V_24 = - V_14 ;
goto V_56;
}
memcpy ( V_60 , V_34 , sizeof( * V_34 ) ) ;
V_60 -> V_31 = V_62 -> V_65 ;
V_60 -> V_37 = (struct V_8 * )
( V_49 ) V_62 -> V_66 ;
F_32 ( & V_60 -> V_38 , & V_34 -> V_38 ) ;
}
F_33 ( V_44 ) ;
}
V_56:
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
if ( ! V_4 || ! F_41 ( V_4 ) ) {
F_42 ( V_4 ) ;
return - V_72 ;
}
F_43 ( V_4 ) ;
if ( F_44 ( V_4 ) == 0 )
F_7 ( V_4 , & V_34 -> V_36 , 0 ) ;
else
F_45 ( V_4 , & V_34 -> V_36 , 0 ) ;
F_46 ( V_4 ) ;
F_42 ( V_4 ) ;
}
return 0 ;
}
static void F_47 ( struct V_27 * V_28 , int V_73 )
{
struct V_27 * V_74 ;
F_37 (pos1, head) {
struct V_27 * V_75 ;
struct V_27 * V_76 ;
struct V_33 * V_67 ;
V_67 = F_38 ( V_74 , struct V_33 , V_38 ) ;
for ( V_76 = V_74 -> V_15 , V_75 = V_76 -> V_15 ; V_76 != V_28 ;
V_76 = V_75 , V_75 = V_76 -> V_15 ) {
struct V_33 * V_68 ;
struct V_33 * V_77 ;
struct V_8 * V_9 ;
V_68 = F_38 ( V_76 , struct V_33 , V_38 ) ;
if ( V_73 == 1 ) {
if ( ! F_35 ( V_67 , V_68 ) )
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
while ( V_9 && V_9 -> V_15 )
V_9 = V_9 -> V_15 ;
if ( V_9 )
V_9 -> V_15 = V_68 -> V_37 ;
else
V_67 -> V_37 = V_68 -> V_37 ;
V_67 -> V_32 += V_68 -> V_32 ;
F_48 ( & V_68 -> V_38 ) ;
F_49 ( V_68 ) ;
}
}
}
static int F_50 ( struct V_78 * V_28 , T_1 V_79 ,
struct V_27 * V_80 )
{
struct V_81 * V_82 = V_28 -> V_82 ;
struct V_83 * V_84 = & V_28 -> V_62 . V_83 ;
struct V_1 V_2 ;
struct V_1 V_85 = { 0 } ;
int V_86 ;
int V_24 = 0 ;
if ( V_82 && V_82 -> V_87 )
F_51 ( & V_85 , & V_82 -> V_2 ) ;
while ( ( V_84 = F_52 ( V_84 ) ) ) {
struct V_88 * V_62 ;
V_62 = F_53 ( V_84 , struct V_88 ,
V_83 ) ;
if ( V_62 -> V_89 != V_28 -> V_62 . V_89 )
break;
F_25 ( V_62 -> V_90 ) ;
if ( V_62 -> V_79 > V_79 )
continue;
switch ( V_62 -> V_91 ) {
case V_92 :
case V_93 :
F_25 ( 1 ) ;
continue;
case V_94 :
V_86 = 1 ;
break;
case V_95 :
V_86 = - 1 ;
break;
default:
F_39 ( 1 ) ;
}
switch ( V_62 -> type ) {
case V_96 : {
struct V_97 * V_34 ;
V_34 = F_54 ( V_62 ) ;
V_24 = F_11 ( V_80 , V_34 -> V_40 , & V_85 ,
V_34 -> V_30 + 1 , 0 , V_62 -> V_89 ,
V_62 -> V_98 * V_86 ) ;
break;
}
case V_99 : {
struct V_97 * V_34 ;
V_34 = F_54 ( V_62 ) ;
V_24 = F_11 ( V_80 , V_34 -> V_40 , NULL ,
V_34 -> V_30 + 1 , V_34 -> V_31 ,
V_62 -> V_89 ,
V_62 -> V_98 * V_86 ) ;
break;
}
case V_100 : {
struct V_101 * V_34 ;
V_34 = F_55 ( V_62 ) ;
V_2 . V_17 = V_34 -> V_17 ;
V_2 . type = V_25 ;
V_2 . V_18 = V_34 -> V_18 ;
V_24 = F_11 ( V_80 , V_34 -> V_40 , & V_2 , 0 , 0 ,
V_62 -> V_89 ,
V_62 -> V_98 * V_86 ) ;
break;
}
case V_102 : {
struct V_101 * V_34 ;
V_34 = F_55 ( V_62 ) ;
V_2 . V_17 = V_34 -> V_17 ;
V_2 . type = V_25 ;
V_2 . V_18 = V_34 -> V_18 ;
V_24 = F_11 ( V_80 , V_34 -> V_40 , & V_2 , 0 ,
V_34 -> V_31 , V_62 -> V_89 ,
V_62 -> V_98 * V_86 ) ;
break;
}
default:
F_25 ( 1 ) ;
}
if ( V_24 )
return V_24 ;
}
return 0 ;
}
static int F_56 ( struct V_50 * V_51 ,
struct V_41 * V_42 , T_1 V_89 ,
int * V_103 , struct V_27 * V_80 )
{
int V_24 = 0 ;
int V_21 ;
struct V_3 * V_104 ;
struct V_1 V_2 ;
unsigned long V_105 ;
unsigned long V_106 ;
struct V_107 * V_108 ;
T_1 V_109 ;
T_1 V_110 ;
V_104 = V_42 -> V_46 [ 0 ] ;
V_21 = V_42 -> V_48 [ 0 ] ;
V_110 = F_57 ( V_104 , V_21 ) ;
F_39 ( V_110 < sizeof( * V_108 ) ) ;
V_108 = F_8 ( V_104 , V_21 , struct V_107 ) ;
V_109 = F_58 ( V_104 , V_108 ) ;
V_105 = ( unsigned long ) ( V_108 + 1 ) ;
V_106 = ( unsigned long ) V_108 + V_110 ;
if ( V_109 & V_111 ) {
struct V_112 * V_113 ;
V_113 = (struct V_112 * ) V_105 ;
* V_103 = F_59 ( V_104 , V_113 ) ;
V_105 += sizeof( struct V_112 ) ;
F_39 ( V_105 > V_106 ) ;
} else {
F_39 ( ! ( V_109 & V_114 ) ) ;
}
while ( V_105 < V_106 ) {
struct V_115 * V_116 ;
T_1 V_18 ;
int type ;
V_116 = (struct V_115 * ) V_105 ;
type = F_60 ( V_104 , V_116 ) ;
V_18 = F_61 ( V_104 , V_116 ) ;
switch ( type ) {
case V_99 :
V_24 = F_11 ( V_80 , 0 , NULL ,
* V_103 + 1 , V_18 ,
V_89 , 1 ) ;
break;
case V_102 : {
struct V_117 * V_118 ;
int V_32 ;
V_118 = (struct V_117 * ) ( V_116 + 1 ) ;
V_32 = F_62 ( V_104 , V_118 ) ;
V_24 = F_11 ( V_80 , 0 , NULL , 0 , V_18 ,
V_89 , V_32 ) ;
break;
}
case V_96 :
V_24 = F_11 ( V_80 , V_18 , NULL ,
* V_103 + 1 , 0 ,
V_89 , 1 ) ;
break;
case V_100 : {
struct V_119 * V_120 ;
int V_32 ;
T_1 V_40 ;
V_120 = (struct V_119 * ) ( & V_116 -> V_18 ) ;
V_32 = F_63 ( V_104 , V_120 ) ;
V_2 . V_17 = F_64 ( V_104 ,
V_120 ) ;
V_2 . type = V_25 ;
V_2 . V_18 = F_65 ( V_104 , V_120 ) ;
V_40 = F_66 ( V_104 , V_120 ) ;
V_24 = F_11 ( V_80 , V_40 , & V_2 , 0 , 0 ,
V_89 , V_32 ) ;
break;
}
default:
F_25 ( 1 ) ;
}
if ( V_24 )
return V_24 ;
V_105 += F_67 ( type ) ;
}
return 0 ;
}
static int F_68 ( struct V_50 * V_51 ,
struct V_41 * V_42 , T_1 V_89 ,
int V_103 , struct V_27 * V_80 )
{
struct V_39 * V_121 = V_51 -> V_121 ;
int V_24 ;
int V_21 ;
struct V_3 * V_104 ;
struct V_1 V_2 ;
while ( 1 ) {
V_24 = F_69 ( V_121 , V_42 ) ;
if ( V_24 < 0 )
break;
if ( V_24 ) {
V_24 = 0 ;
break;
}
V_21 = V_42 -> V_48 [ 0 ] ;
V_104 = V_42 -> V_46 [ 0 ] ;
F_7 ( V_104 , & V_2 , V_21 ) ;
if ( V_2 . V_17 != V_89 )
break;
if ( V_2 . type < V_96 )
continue;
if ( V_2 . type > V_102 )
break;
switch ( V_2 . type ) {
case V_99 :
V_24 = F_11 ( V_80 , 0 , NULL ,
V_103 + 1 , V_2 . V_18 ,
V_89 , 1 ) ;
break;
case V_102 : {
struct V_117 * V_118 ;
int V_32 ;
V_118 = F_8 ( V_104 , V_21 ,
struct V_117 ) ;
V_32 = F_62 ( V_104 , V_118 ) ;
V_24 = F_11 ( V_80 , 0 , NULL , 0 , V_2 . V_18 ,
V_89 , V_32 ) ;
break;
}
case V_96 :
V_24 = F_11 ( V_80 , V_2 . V_18 , NULL ,
V_103 + 1 , 0 ,
V_89 , 1 ) ;
break;
case V_100 : {
struct V_119 * V_120 ;
int V_32 ;
T_1 V_40 ;
V_120 = F_8 ( V_104 , V_21 ,
struct V_119 ) ;
V_32 = F_63 ( V_104 , V_120 ) ;
V_2 . V_17 = F_64 ( V_104 ,
V_120 ) ;
V_2 . type = V_25 ;
V_2 . V_18 = F_65 ( V_104 , V_120 ) ;
V_40 = F_66 ( V_104 , V_120 ) ;
V_24 = F_11 ( V_80 , V_40 , & V_2 , 0 , 0 ,
V_89 , V_32 ) ;
break;
}
default:
F_25 ( 1 ) ;
}
if ( V_24 )
return V_24 ;
}
return V_24 ;
}
static int F_70 ( struct V_122 * V_123 ,
struct V_50 * V_51 , T_1 V_89 ,
T_1 V_45 , struct V_43 * V_124 ,
struct V_43 * V_125 , const T_1 * V_7 )
{
struct V_1 V_2 ;
struct V_41 * V_42 ;
struct V_126 * V_127 = NULL ;
struct V_78 * V_28 ;
int V_103 = 0 ;
int V_24 ;
int V_52 = ( V_123 == V_128 ) ;
struct V_27 V_129 ;
struct V_27 V_80 ;
struct V_33 * V_34 ;
F_71 ( & V_80 ) ;
F_71 ( & V_129 ) ;
V_2 . V_17 = V_89 ;
V_2 . type = V_130 ;
V_2 . V_18 = ( T_1 ) - 1 ;
V_42 = F_18 () ;
if ( ! V_42 )
return - V_14 ;
V_42 -> V_52 = ! ! V_52 ;
V_131:
V_28 = NULL ;
V_24 = F_72 ( V_123 , V_51 -> V_121 , & V_2 , V_42 , 0 , 0 ) ;
if ( V_24 < 0 )
goto V_56;
F_39 ( V_24 == 0 ) ;
if ( V_123 != V_128 ) {
V_127 = & V_123 -> V_132 -> V_127 ;
F_73 ( & V_127 -> V_133 ) ;
V_28 = F_74 ( V_123 , V_89 ) ;
if ( V_28 ) {
if ( ! F_75 ( & V_28 -> V_134 ) ) {
F_76 ( & V_28 -> V_62 . V_124 ) ;
F_77 ( & V_127 -> V_133 ) ;
F_78 ( V_42 ) ;
F_79 ( & V_28 -> V_134 ) ;
F_80 ( & V_28 -> V_134 ) ;
F_81 ( & V_28 -> V_62 ) ;
goto V_131;
}
V_24 = F_50 ( V_28 , V_45 ,
& V_129 ) ;
F_80 ( & V_28 -> V_134 ) ;
if ( V_24 ) {
F_77 ( & V_127 -> V_133 ) ;
goto V_56;
}
}
F_77 ( & V_127 -> V_133 ) ;
}
if ( V_42 -> V_48 [ 0 ] ) {
struct V_3 * V_104 ;
int V_21 ;
V_42 -> V_48 [ 0 ] -- ;
V_104 = V_42 -> V_46 [ 0 ] ;
V_21 = V_42 -> V_48 [ 0 ] ;
F_7 ( V_104 , & V_2 , V_21 ) ;
if ( V_2 . V_17 == V_89 &&
V_2 . type == V_130 ) {
V_24 = F_56 ( V_51 , V_42 , V_89 ,
& V_103 , & V_80 ) ;
if ( V_24 )
goto V_56;
V_24 = F_68 ( V_51 , V_42 , V_89 ,
V_103 , & V_80 ) ;
if ( V_24 )
goto V_56;
}
}
F_78 ( V_42 ) ;
F_82 ( & V_129 , & V_80 ) ;
V_24 = F_36 ( V_51 , & V_80 ) ;
if ( V_24 )
goto V_56;
F_47 ( & V_80 , 1 ) ;
V_24 = F_27 ( V_51 , V_52 , V_45 ,
& V_80 , V_7 ) ;
if ( V_24 )
goto V_56;
F_47 ( & V_80 , 2 ) ;
while ( ! F_83 ( & V_80 ) ) {
V_34 = F_84 ( & V_80 , struct V_33 , V_38 ) ;
F_48 ( & V_34 -> V_38 ) ;
F_25 ( V_34 -> V_32 < 0 ) ;
if ( V_34 -> V_32 && V_34 -> V_29 && V_34 -> V_31 == 0 ) {
V_24 = F_14 ( V_125 , V_34 -> V_29 , 0 , V_13 ) ;
if ( V_24 < 0 )
goto V_56;
}
if ( V_34 -> V_32 && V_34 -> V_31 ) {
struct V_8 * V_9 = NULL ;
if ( V_7 && ! V_34 -> V_37 ) {
T_2 V_135 ;
struct V_3 * V_4 ;
V_135 = F_85 ( V_51 -> V_121 ,
V_103 ) ;
V_4 = F_40 ( V_51 -> V_121 ,
V_34 -> V_31 , V_135 , 0 ) ;
if ( ! V_4 || ! F_41 ( V_4 ) ) {
F_42 ( V_4 ) ;
V_24 = - V_72 ;
goto V_56;
}
V_24 = F_5 ( V_4 , V_89 ,
* V_7 , & V_9 ) ;
V_34 -> V_37 = V_9 ;
F_42 ( V_4 ) ;
}
V_24 = F_86 ( V_124 , V_34 -> V_31 ,
( V_49 ) V_34 -> V_37 ,
( T_1 * ) & V_9 , V_13 ) ;
if ( V_24 < 0 )
goto V_56;
if ( ! V_24 && V_7 ) {
F_39 ( ! V_9 ) ;
while ( V_9 -> V_15 )
V_9 = V_9 -> V_15 ;
V_9 -> V_15 = V_34 -> V_37 ;
}
}
F_49 ( V_34 ) ;
}
V_56:
F_26 ( V_42 ) ;
while ( ! F_83 ( & V_80 ) ) {
V_34 = F_84 ( & V_80 , struct V_33 , V_38 ) ;
F_48 ( & V_34 -> V_38 ) ;
F_49 ( V_34 ) ;
}
while ( ! F_83 ( & V_129 ) ) {
V_34 = F_84 ( & V_129 , struct V_33 ,
V_38 ) ;
F_48 ( & V_34 -> V_38 ) ;
F_49 ( V_34 ) ;
}
return V_24 ;
}
static void F_87 ( struct V_43 * V_136 )
{
struct V_61 * V_62 = NULL ;
struct V_8 * V_9 ;
struct V_8 * V_137 ;
struct V_63 V_64 ;
F_30 ( & V_64 ) ;
while ( ( V_62 = F_31 ( V_136 , & V_64 ) ) ) {
if ( ! V_62 -> V_66 )
continue;
V_9 = (struct V_8 * ) ( V_49 ) V_62 -> V_66 ;
for (; V_9 ; V_9 = V_137 ) {
V_137 = V_9 -> V_15 ;
F_49 ( V_9 ) ;
}
V_62 -> V_66 = 0 ;
}
F_34 ( V_136 ) ;
}
static int F_88 ( struct V_122 * V_123 ,
struct V_50 * V_51 , T_1 V_89 ,
T_1 V_45 , struct V_43 * * V_138 ,
const T_1 * V_7 )
{
struct V_43 * V_139 ;
int V_24 ;
V_139 = F_28 ( V_13 ) ;
if ( ! V_139 )
return - V_14 ;
* V_138 = F_28 ( V_13 ) ;
if ( ! * V_138 ) {
F_34 ( V_139 ) ;
return - V_14 ;
}
V_24 = F_70 ( V_123 , V_51 , V_89 ,
V_45 , * V_138 , V_139 , V_7 ) ;
F_34 ( V_139 ) ;
if ( V_24 < 0 && V_24 != - V_140 ) {
F_87 ( * V_138 ) ;
return V_24 ;
}
return 0 ;
}
int F_89 ( struct V_122 * V_123 ,
struct V_50 * V_51 , T_1 V_89 ,
T_1 V_45 , struct V_43 * * V_125 )
{
struct V_43 * V_139 ;
struct V_61 * V_62 = NULL ;
struct V_63 V_64 ;
int V_24 ;
V_139 = F_28 ( V_13 ) ;
if ( ! V_139 )
return - V_14 ;
* V_125 = F_28 ( V_13 ) ;
if ( ! * V_125 ) {
F_34 ( V_139 ) ;
return - V_14 ;
}
F_30 ( & V_64 ) ;
while ( 1 ) {
V_24 = F_70 ( V_123 , V_51 , V_89 ,
V_45 , V_139 , * V_125 , NULL ) ;
if ( V_24 < 0 && V_24 != - V_140 ) {
F_34 ( V_139 ) ;
F_34 ( * V_125 ) ;
return V_24 ;
}
V_62 = F_31 ( V_139 , & V_64 ) ;
if ( ! V_62 )
break;
V_89 = V_62 -> V_65 ;
}
F_34 ( V_139 ) ;
return 0 ;
}
static int F_90 ( T_1 V_16 , T_1 V_141 , T_3 V_142 ,
struct V_39 * V_143 , struct V_41 * V_42 ,
struct V_1 * V_144 )
{
int V_24 ;
struct V_1 V_2 ;
struct V_3 * V_4 ;
V_2 . type = V_142 ;
V_2 . V_17 = V_16 ;
V_2 . V_18 = V_141 ;
V_24 = F_72 ( NULL , V_143 , & V_2 , V_42 , 0 , 0 ) ;
if ( V_24 < 0 )
return V_24 ;
V_4 = V_42 -> V_46 [ 0 ] ;
if ( V_24 && V_42 -> V_48 [ 0 ] >= F_6 ( V_4 ) ) {
V_24 = F_91 ( V_143 , V_42 ) ;
if ( V_24 )
return V_24 ;
V_4 = V_42 -> V_46 [ 0 ] ;
}
F_7 ( V_4 , V_144 , V_42 -> V_48 [ 0 ] ) ;
if ( V_144 -> type != V_2 . type || V_144 -> V_17 != V_2 . V_17 )
return 1 ;
return 0 ;
}
int F_92 ( T_1 V_16 , T_1 V_141 , struct V_39 * V_143 ,
struct V_41 * V_42 )
{
struct V_1 V_2 ;
return F_90 ( V_16 , V_141 , V_145 , V_143 , V_42 ,
& V_2 ) ;
}
static int F_93 ( T_1 V_16 , T_1 V_141 , struct V_39 * V_143 ,
struct V_41 * V_42 ,
struct V_1 * V_144 )
{
return F_90 ( V_16 , V_141 , V_146 , V_143 , V_42 ,
V_144 ) ;
}
int F_94 ( struct V_39 * V_40 , T_1 V_147 ,
T_1 V_148 , struct V_41 * V_42 ,
struct V_149 * * V_150 ,
T_1 * V_151 )
{
int V_24 , V_21 ;
struct V_1 V_2 ;
struct V_1 V_144 ;
struct V_149 * V_152 ;
struct V_3 * V_104 ;
unsigned long V_105 ;
V_2 . V_17 = V_147 ;
F_95 ( & V_2 , V_153 ) ;
V_2 . V_18 = V_148 ;
V_24 = F_72 ( NULL , V_40 , & V_2 , V_42 , 0 , 0 ) ;
if ( V_24 < 0 )
return V_24 ;
while ( 1 ) {
V_104 = V_42 -> V_46 [ 0 ] ;
V_21 = V_42 -> V_48 [ 0 ] ;
if ( V_21 >= F_6 ( V_104 ) ) {
V_24 = F_91 ( V_40 , V_42 ) ;
if ( V_24 ) {
if ( V_24 >= 1 )
V_24 = - V_140 ;
break;
}
continue;
}
F_7 ( V_104 , & V_144 , V_21 ) ;
V_24 = - V_140 ;
if ( V_144 . V_17 != V_147 )
break;
if ( F_96 ( & V_144 ) != V_153 )
break;
V_24 = 0 ;
V_105 = F_97 ( V_104 , V_42 -> V_48 [ 0 ] ) ;
V_152 = (struct V_149 * ) V_105 ;
* V_150 = V_152 ;
if ( V_151 )
* V_151 = V_144 . V_18 ;
break;
}
return V_24 ;
}
char * F_98 ( struct V_39 * V_143 , struct V_41 * V_42 ,
T_2 V_154 , unsigned long V_155 ,
struct V_3 * V_156 , T_1 V_31 ,
char * V_157 , T_2 V_158 )
{
int V_21 ;
T_1 V_159 ;
int V_24 ;
T_4 V_160 = ( ( T_4 ) V_158 ) - 1 ;
struct V_3 * V_4 = V_156 ;
struct V_1 V_144 ;
int V_161 = V_42 -> V_161 ;
struct V_162 * V_116 ;
if ( V_160 >= 0 )
V_157 [ V_160 ] = '\0' ;
V_42 -> V_161 = 1 ;
while ( 1 ) {
V_160 -= V_154 ;
if ( V_160 >= 0 )
F_99 ( V_4 , V_157 + V_160 ,
V_155 , V_154 ) ;
if ( V_4 != V_156 ) {
F_100 ( V_4 ) ;
F_42 ( V_4 ) ;
}
V_24 = F_93 ( V_31 , 0 , V_143 , V_42 , & V_144 ) ;
if ( V_24 > 0 )
V_24 = - V_140 ;
if ( V_24 )
break;
V_159 = V_144 . V_18 ;
if ( V_31 == V_159 )
break;
V_21 = V_42 -> V_48 [ 0 ] ;
V_4 = V_42 -> V_46 [ 0 ] ;
if ( V_4 != V_156 ) {
F_76 ( & V_4 -> V_124 ) ;
F_43 ( V_4 ) ;
F_101 ( V_4 , V_163 ) ;
}
F_78 ( V_42 ) ;
V_116 = F_8 ( V_4 , V_21 , struct V_162 ) ;
V_154 = F_102 ( V_4 , V_116 ) ;
V_155 = ( unsigned long ) ( V_116 + 1 ) ;
V_31 = V_159 ;
-- V_160 ;
if ( V_160 >= 0 )
V_157 [ V_160 ] = '/' ;
}
F_78 ( V_42 ) ;
V_42 -> V_161 = V_161 ;
if ( V_24 )
return F_103 ( V_24 ) ;
return V_157 + V_160 ;
}
int F_104 ( struct V_50 * V_51 , T_1 V_164 ,
struct V_41 * V_42 , struct V_1 * V_144 ,
T_1 * V_165 )
{
int V_24 ;
T_1 V_109 ;
T_2 V_110 ;
struct V_3 * V_4 ;
struct V_107 * V_108 ;
struct V_1 V_2 ;
V_2 . type = V_130 ;
V_2 . V_17 = V_164 ;
V_2 . V_18 = ( T_1 ) - 1 ;
V_24 = F_72 ( NULL , V_51 -> V_121 , & V_2 , V_42 , 0 , 0 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_105 ( V_51 -> V_121 , V_42 ,
0 , V_130 ) ;
if ( V_24 < 0 )
return V_24 ;
F_7 ( V_42 -> V_46 [ 0 ] , V_144 , V_42 -> V_48 [ 0 ] ) ;
if ( V_144 -> type != V_130 ||
V_144 -> V_17 > V_164 ||
V_144 -> V_17 + V_144 -> V_18 <= V_164 ) {
F_24 ( L_3 ,
( unsigned long long ) V_164 ) ;
return - V_140 ;
}
V_4 = V_42 -> V_46 [ 0 ] ;
V_110 = F_57 ( V_4 , V_42 -> V_48 [ 0 ] ) ;
F_39 ( V_110 < sizeof( * V_108 ) ) ;
V_108 = F_8 ( V_4 , V_42 -> V_48 [ 0 ] , struct V_107 ) ;
V_109 = F_58 ( V_4 , V_108 ) ;
F_24 ( L_4
L_5 ,
( unsigned long long ) V_164 ,
( unsigned long long ) ( V_164 - V_144 -> V_17 ) ,
( unsigned long long ) V_144 -> V_17 ,
( unsigned long long ) V_144 -> V_18 ,
( unsigned long long ) V_109 , V_110 ) ;
F_25 ( ! V_165 ) ;
if ( V_165 ) {
if ( V_109 & V_111 )
* V_165 = V_111 ;
else if ( V_109 & V_114 )
* V_165 = V_114 ;
else
F_39 ( 1 ) ;
return 0 ;
}
return - V_72 ;
}
static int F_106 ( unsigned long * V_105 , struct V_3 * V_4 ,
struct V_107 * V_108 , T_2 V_110 ,
struct V_115 * * V_166 ,
int * V_167 )
{
unsigned long V_106 ;
T_1 V_109 ;
struct V_112 * V_113 ;
if ( ! * V_105 ) {
V_109 = F_58 ( V_4 , V_108 ) ;
if ( V_109 & V_111 ) {
V_113 = (struct V_112 * ) ( V_108 + 1 ) ;
* V_166 =
(struct V_115 * ) ( V_113 + 1 ) ;
} else {
* V_166 = (struct V_115 * ) ( V_108 + 1 ) ;
}
* V_105 = ( unsigned long ) * V_166 ;
if ( ( void * ) * V_105 >= ( void * ) V_108 + V_110 )
return - V_140 ;
}
V_106 = ( unsigned long ) V_108 + V_110 ;
* V_166 = (struct V_115 * ) * V_105 ;
* V_167 = F_60 ( V_4 , * V_166 ) ;
* V_105 += F_67 ( * V_167 ) ;
F_25 ( * V_105 > V_106 ) ;
if ( * V_105 == V_106 )
return 1 ;
return 0 ;
}
int F_107 ( unsigned long * V_105 , struct V_3 * V_4 ,
struct V_107 * V_108 , T_2 V_110 ,
T_1 * V_168 , T_3 * V_169 )
{
int V_24 ;
int type ;
struct V_112 * V_113 ;
struct V_115 * V_170 ;
if ( * V_105 == ( unsigned long ) - 1 )
return 1 ;
while ( 1 ) {
V_24 = F_106 ( V_105 , V_4 , V_108 , V_110 ,
& V_170 , & type ) ;
if ( V_24 < 0 )
return V_24 ;
if ( type == V_96 ||
type == V_99 )
break;
if ( V_24 == 1 )
return 1 ;
}
V_113 = (struct V_112 * ) ( V_108 + 1 ) ;
* V_168 = F_61 ( V_4 , V_170 ) ;
* V_169 = F_59 ( V_4 , V_113 ) ;
if ( V_24 == 1 )
* V_105 = ( unsigned long ) - 1 ;
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
struct V_122 * V_123 ;
struct V_43 * V_124 = NULL ;
struct V_43 * V_125 = NULL ;
struct V_61 * V_174 = NULL ;
struct V_61 * V_175 = NULL ;
struct V_176 V_177 = {} ;
struct V_63 V_178 ;
struct V_63 V_179 ;
F_24 ( L_9 ,
V_171 ) ;
if ( V_52 ) {
V_123 = V_128 ;
} else {
V_123 = F_110 ( V_51 -> V_121 ) ;
if ( F_20 ( V_123 ) )
return F_21 ( V_123 ) ;
F_111 ( V_51 , & V_177 ) ;
}
V_24 = F_88 ( V_123 , V_51 , V_171 ,
V_177 . V_79 , & V_124 ,
& V_7 ) ;
if ( V_24 )
goto V_56;
F_30 ( & V_178 ) ;
while ( ! V_24 && ( V_174 = F_31 ( V_124 , & V_178 ) ) ) {
V_24 = F_89 ( V_123 , V_51 , V_174 -> V_65 ,
V_177 . V_79 , & V_125 ) ;
if ( V_24 )
break;
F_30 ( & V_179 ) ;
while ( ! V_24 && ( V_175 = F_31 ( V_125 , & V_179 ) ) ) {
F_24 ( L_10
L_11 , V_175 -> V_65 , V_174 -> V_65 ,
( long long ) V_174 -> V_66 ) ;
V_24 = F_108 ( (struct V_8 * )
( V_49 ) V_174 -> V_66 ,
V_175 -> V_65 ,
V_171 ,
V_172 , V_173 ) ;
}
F_34 ( V_125 ) ;
}
F_87 ( V_124 ) ;
V_56:
if ( ! V_52 ) {
F_112 ( V_51 , & V_177 ) ;
F_113 ( V_123 , V_51 -> V_121 ) ;
}
return V_24 ;
}
int F_114 ( T_1 V_164 , struct V_50 * V_51 ,
struct V_41 * V_42 ,
T_5 * V_172 , void * V_173 )
{
int V_24 ;
T_1 V_7 ;
T_1 V_109 = 0 ;
struct V_1 V_144 ;
int V_52 = V_42 -> V_52 ;
V_24 = F_104 ( V_51 , V_164 , V_42 , & V_144 , & V_109 ) ;
F_78 ( V_42 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_109 & V_111 )
return - V_180 ;
V_7 = V_164 - V_144 . V_17 ;
V_24 = F_109 ( V_51 , V_144 . V_17 ,
V_7 , V_52 ,
V_172 , V_173 ) ;
return V_24 ;
}
static int F_115 ( T_1 V_16 , struct V_39 * V_143 ,
struct V_41 * V_42 ,
T_6 * V_172 , void * V_173 )
{
int V_24 = 0 ;
int V_21 ;
T_2 V_181 ;
T_2 V_182 ;
T_2 V_154 ;
T_1 V_31 = 0 ;
int V_183 = 0 ;
struct V_3 * V_4 ;
struct V_184 * V_185 ;
struct V_162 * V_116 ;
struct V_1 V_144 ;
while ( ! V_24 ) {
V_42 -> V_161 = 1 ;
V_24 = F_93 ( V_16 , V_31 ? V_31 + 1 : 0 , V_143 , V_42 ,
& V_144 ) ;
if ( V_24 < 0 )
break;
if ( V_24 ) {
V_24 = V_183 ? 0 : - V_140 ;
break;
}
++ V_183 ;
V_31 = V_144 . V_18 ;
V_21 = V_42 -> V_48 [ 0 ] ;
V_4 = V_42 -> V_46 [ 0 ] ;
F_76 ( & V_4 -> V_124 ) ;
F_43 ( V_4 ) ;
F_101 ( V_4 , V_163 ) ;
F_78 ( V_42 ) ;
V_185 = F_116 ( V_4 , V_21 ) ;
V_116 = F_8 ( V_4 , V_21 , struct V_162 ) ;
for ( V_181 = 0 ; V_181 < F_117 ( V_4 , V_185 ) ; V_181 += V_182 ) {
V_154 = F_102 ( V_4 , V_116 ) ;
F_24 ( L_12
L_13 , V_181 ,
( unsigned long long ) V_144 . V_17 ,
( unsigned long long ) V_143 -> V_17 ) ;
V_24 = V_172 ( V_31 , V_154 ,
( unsigned long ) ( V_116 + 1 ) , V_4 , V_173 ) ;
if ( V_24 )
break;
V_182 = sizeof( * V_116 ) + V_154 ;
V_116 = (struct V_162 * ) ( ( char * ) V_116 + V_182 ) ;
}
F_100 ( V_4 ) ;
F_42 ( V_4 ) ;
}
F_78 ( V_42 ) ;
return V_24 ;
}
static int F_118 ( T_1 V_16 , struct V_39 * V_143 ,
struct V_41 * V_42 ,
T_6 * V_172 , void * V_173 )
{
int V_24 ;
int V_21 ;
T_1 V_18 = 0 ;
T_1 V_31 ;
int V_183 = 0 ;
struct V_3 * V_4 ;
struct V_149 * V_152 ;
struct V_3 * V_104 ;
T_2 V_110 ;
T_2 V_186 ;
unsigned long V_105 ;
while ( 1 ) {
V_24 = F_94 ( V_143 , V_16 , V_18 , V_42 , & V_152 ,
& V_18 ) ;
if ( V_24 < 0 )
break;
if ( V_24 ) {
V_24 = V_183 ? 0 : - V_140 ;
break;
}
++ V_183 ;
V_21 = V_42 -> V_48 [ 0 ] ;
V_4 = V_42 -> V_46 [ 0 ] ;
F_76 ( & V_4 -> V_124 ) ;
F_43 ( V_4 ) ;
F_101 ( V_4 , V_163 ) ;
F_78 ( V_42 ) ;
V_104 = V_42 -> V_46 [ 0 ] ;
V_110 = F_57 ( V_104 , V_42 -> V_48 [ 0 ] ) ;
V_105 = F_97 ( V_104 , V_42 -> V_48 [ 0 ] ) ;
V_186 = 0 ;
while ( V_186 < V_110 ) {
T_2 V_154 ;
V_152 = (struct V_149 * ) ( V_105 + V_186 ) ;
V_31 = F_119 ( V_4 , V_152 ) ;
V_154 = F_120 ( V_4 , V_152 ) ;
V_24 = V_172 ( V_31 , V_154 ,
( unsigned long ) & V_152 -> V_187 , V_4 , V_173 ) ;
if ( V_24 )
break;
V_186 += F_120 ( V_104 , V_152 ) ;
V_186 += sizeof( * V_152 ) ;
}
F_100 ( V_4 ) ;
F_42 ( V_4 ) ;
V_18 ++ ;
}
F_78 ( V_42 ) ;
return V_24 ;
}
static int F_121 ( T_1 V_16 , struct V_39 * V_143 ,
struct V_41 * V_42 , T_6 * V_172 ,
void * V_173 )
{
int V_24 ;
int V_188 = 0 ;
V_24 = F_115 ( V_16 , V_143 , V_42 , V_172 , V_173 ) ;
if ( ! V_24 )
++ V_188 ;
else if ( V_24 != - V_140 )
return V_24 ;
V_24 = F_118 ( V_16 , V_143 , V_42 , V_172 , V_173 ) ;
if ( V_24 == - V_140 && V_188 )
return 0 ;
return V_24 ;
}
static int F_122 ( T_1 V_16 , T_2 V_154 , unsigned long V_155 ,
struct V_3 * V_4 , void * V_173 )
{
struct V_189 * V_190 = V_173 ;
char * V_191 ;
char * V_192 ;
int V_193 = V_190 -> V_191 -> V_194 ;
const int V_195 = sizeof( char * ) ;
T_2 V_160 ;
V_160 = V_190 -> V_191 -> V_160 > V_195 ?
V_190 -> V_191 -> V_160 - V_195 : 0 ;
V_192 = ( char * ) V_190 -> V_191 -> V_65 + ( V_193 + 1 ) * V_195 ;
V_191 = F_98 ( V_190 -> V_143 , V_190 -> V_41 , V_154 ,
V_155 , V_4 , V_16 , V_192 , V_160 ) ;
if ( F_20 ( V_191 ) )
return F_21 ( V_191 ) ;
if ( V_191 > V_192 ) {
V_190 -> V_191 -> V_65 [ V_193 ] = ( T_1 ) ( unsigned long ) V_191 ;
++ V_190 -> V_191 -> V_194 ;
V_190 -> V_191 -> V_160 = V_191 - V_192 ;
} else {
++ V_190 -> V_191 -> V_196 ;
V_190 -> V_191 -> V_197 += V_192 - V_191 ;
V_190 -> V_191 -> V_160 = 0 ;
}
return 0 ;
}
int F_123 ( T_1 V_16 , struct V_189 * V_190 )
{
return F_121 ( V_16 , V_190 -> V_143 , V_190 -> V_41 ,
F_122 , V_190 ) ;
}
struct V_198 * F_124 ( T_2 V_199 )
{
struct V_198 * V_200 ;
T_7 V_201 ;
V_201 = F_125 ( T_7 , V_199 , sizeof( * V_200 ) ) ;
V_200 = F_126 ( V_201 ) ;
if ( ! V_200 )
return F_103 ( - V_14 ) ;
if ( V_199 >= sizeof( * V_200 ) ) {
V_200 -> V_160 = V_199 - sizeof( * V_200 ) ;
V_200 -> V_197 = 0 ;
} else {
V_200 -> V_197 = sizeof( * V_200 ) - V_199 ;
V_200 -> V_160 = 0 ;
}
V_200 -> V_194 = 0 ;
V_200 -> V_196 = 0 ;
return V_200 ;
}
struct V_189 * F_127 ( T_8 V_199 , struct V_39 * V_143 ,
struct V_41 * V_42 )
{
struct V_189 * V_202 ;
struct V_198 * V_191 ;
V_191 = F_124 ( V_199 ) ;
if ( F_20 ( V_191 ) )
return ( void * ) V_191 ;
V_202 = F_4 ( sizeof( * V_202 ) , V_13 ) ;
if ( ! V_202 ) {
F_49 ( V_191 ) ;
return F_103 ( - V_14 ) ;
}
V_202 -> V_41 = V_42 ;
V_202 -> V_191 = V_191 ;
V_202 -> V_143 = V_143 ;
return V_202 ;
}
void F_128 ( struct V_189 * V_190 )
{
if ( ! V_190 )
return;
F_129 ( V_190 -> V_191 ) ;
F_49 ( V_190 ) ;
}
