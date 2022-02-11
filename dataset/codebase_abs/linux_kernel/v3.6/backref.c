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
( unsigned long ) V_9 , V_13 ) ;
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
static int F_17 ( struct V_49 * V_50 ,
int V_51 ,
T_1 V_45 ,
struct V_33 * V_34 ,
struct V_43 * V_44 ,
const T_1 * V_7 )
{
struct V_41 * V_42 ;
struct V_39 * V_40 ;
struct V_1 V_52 ;
struct V_3 * V_4 ;
int V_24 = 0 ;
int V_53 ;
int V_30 = V_34 -> V_30 ;
V_42 = F_18 () ;
if ( ! V_42 )
return - V_14 ;
V_42 -> V_51 = ! ! V_51 ;
V_52 . V_17 = V_34 -> V_29 ;
V_52 . type = V_54 ;
V_52 . V_18 = ( T_1 ) - 1 ;
V_40 = F_19 ( V_50 , & V_52 ) ;
if ( F_20 ( V_40 ) ) {
V_24 = F_21 ( V_40 ) ;
goto V_55;
}
F_22 () ;
V_53 = F_23 ( V_40 -> V_56 ) ;
F_24 () ;
if ( V_53 + 1 == V_30 )
goto V_55;
V_42 -> V_57 = V_30 ;
V_24 = F_25 ( V_40 , & V_34 -> V_36 , V_42 , V_45 ) ;
F_26 ( L_1
L_2 ,
( unsigned long long ) V_34 -> V_29 , V_30 , V_34 -> V_32 , V_24 ,
( unsigned long long ) V_34 -> V_36 . V_17 ,
V_34 -> V_36 . type ,
( unsigned long long ) V_34 -> V_36 . V_18 ) ;
if ( V_24 < 0 )
goto V_55;
V_4 = V_42 -> V_46 [ V_30 ] ;
while ( ! V_4 ) {
if ( ! V_30 ) {
F_27 ( 1 ) ;
V_24 = 1 ;
goto V_55;
}
V_30 -- ;
V_4 = V_42 -> V_46 [ V_30 ] ;
}
V_24 = F_13 ( V_40 , V_42 , V_44 , V_30 , & V_34 -> V_36 ,
V_45 , V_34 -> V_19 ,
V_7 ) ;
V_55:
F_28 ( V_42 ) ;
return V_24 ;
}
static int F_29 ( struct V_49 * V_50 ,
int V_51 , T_1 V_45 ,
struct V_27 * V_28 ,
const T_1 * V_7 )
{
int V_58 ;
int V_24 = 0 ;
struct V_33 * V_34 ;
struct V_33 * V_59 ;
struct V_33 * V_60 ;
struct V_43 * V_44 ;
struct V_61 * V_56 ;
struct V_62 V_63 ;
V_44 = F_30 ( V_13 ) ;
if ( ! V_44 )
return - V_14 ;
F_31 (ref, ref_safe, head, list) {
if ( V_34 -> V_31 )
continue;
if ( V_34 -> V_32 == 0 )
continue;
V_58 = F_17 ( V_50 , V_51 ,
V_45 , V_34 , V_44 ,
V_7 ) ;
if ( V_58 ) {
if ( V_24 == 0 )
V_24 = V_58 ;
continue;
}
F_32 ( & V_63 ) ;
V_56 = F_33 ( V_44 , & V_63 ) ;
V_34 -> V_31 = V_56 ? V_56 -> V_64 : 0 ;
V_34 -> V_37 =
V_56 ? (struct V_8 * ) V_56 -> V_65 : 0 ;
while ( ( V_56 = F_33 ( V_44 , & V_63 ) ) ) {
V_60 = F_4 ( sizeof( * V_60 ) , V_13 ) ;
if ( ! V_60 ) {
V_24 = - V_14 ;
break;
}
memcpy ( V_60 , V_34 , sizeof( * V_34 ) ) ;
V_60 -> V_31 = V_56 -> V_64 ;
V_60 -> V_37 =
(struct V_8 * ) V_56 -> V_65 ;
F_34 ( & V_60 -> V_38 , & V_34 -> V_38 ) ;
}
F_35 ( V_44 ) ;
}
F_36 ( V_44 ) ;
return V_24 ;
}
static inline int F_37 ( struct V_33 * V_66 ,
struct V_33 * V_67 )
{
if ( V_66 -> V_30 != V_67 -> V_30 )
return 0 ;
if ( V_66 -> V_29 != V_67 -> V_29 )
return 0 ;
if ( V_66 -> V_36 . type != V_67 -> V_36 . type )
return 0 ;
if ( V_66 -> V_36 . V_17 != V_67 -> V_36 . V_17 )
return 0 ;
if ( V_66 -> V_36 . V_18 != V_67 -> V_36 . V_18 )
return 0 ;
if ( V_66 -> V_31 != V_67 -> V_31 )
return 0 ;
return 1 ;
}
static int F_38 ( struct V_49 * V_50 ,
struct V_27 * V_28 )
{
struct V_27 * V_68 ;
struct V_3 * V_4 ;
F_39 (pos, head) {
struct V_33 * V_34 ;
V_34 = F_40 ( V_68 , struct V_33 , V_38 ) ;
if ( V_34 -> V_31 )
continue;
if ( V_34 -> V_36 . type )
continue;
F_41 ( ! V_34 -> V_19 ) ;
V_4 = F_42 ( V_50 -> V_69 , V_34 -> V_19 ,
V_50 -> V_69 -> V_70 , 0 ) ;
F_41 ( ! V_4 ) ;
F_43 ( V_4 ) ;
if ( F_23 ( V_4 ) == 0 )
F_7 ( V_4 , & V_34 -> V_36 , 0 ) ;
else
F_44 ( V_4 , & V_34 -> V_36 , 0 ) ;
F_45 ( V_4 ) ;
F_46 ( V_4 ) ;
}
return 0 ;
}
static int F_47 ( struct V_27 * V_28 , int V_71 )
{
struct V_27 * V_72 ;
F_39 (pos1, head) {
struct V_27 * V_73 ;
struct V_27 * V_74 ;
struct V_33 * V_66 ;
V_66 = F_40 ( V_72 , struct V_33 , V_38 ) ;
for ( V_74 = V_72 -> V_15 , V_73 = V_74 -> V_15 ; V_74 != V_28 ;
V_74 = V_73 , V_73 = V_74 -> V_15 ) {
struct V_33 * V_67 ;
struct V_33 * V_75 ;
V_67 = F_40 ( V_74 , struct V_33 , V_38 ) ;
if ( V_71 == 1 ) {
if ( ! F_37 ( V_66 , V_67 ) )
continue;
if ( ! V_66 -> V_31 && V_67 -> V_31 ) {
V_75 = V_66 ;
V_66 = V_67 ;
V_67 = V_75 ;
}
V_66 -> V_32 += V_67 -> V_32 ;
} else {
if ( V_66 -> V_31 != V_67 -> V_31 )
continue;
V_66 -> V_32 += V_67 -> V_32 ;
}
F_48 ( & V_67 -> V_38 ) ;
F_49 ( V_67 ) ;
}
}
return 0 ;
}
static int F_50 ( struct V_76 * V_28 , T_1 V_77 ,
struct V_27 * V_78 )
{
struct V_79 * V_80 = V_28 -> V_80 ;
struct V_81 * V_82 = & V_28 -> V_56 . V_81 ;
struct V_1 V_2 ;
struct V_1 V_83 = { 0 } ;
int V_84 ;
int V_24 = 0 ;
if ( V_80 && V_80 -> V_85 )
F_51 ( & V_83 , & V_80 -> V_2 ) ;
while ( ( V_82 = F_52 ( V_82 ) ) ) {
struct V_86 * V_56 ;
V_56 = F_53 ( V_82 , struct V_86 ,
V_81 ) ;
if ( V_56 -> V_87 != V_28 -> V_56 . V_87 )
break;
F_27 ( V_56 -> V_88 ) ;
if ( V_56 -> V_77 > V_77 )
continue;
switch ( V_56 -> V_89 ) {
case V_90 :
case V_91 :
F_27 ( 1 ) ;
continue;
case V_92 :
V_84 = 1 ;
break;
case V_93 :
V_84 = - 1 ;
break;
default:
F_41 ( 1 ) ;
}
switch ( V_56 -> type ) {
case V_94 : {
struct V_95 * V_34 ;
V_34 = F_54 ( V_56 ) ;
V_24 = F_11 ( V_78 , V_34 -> V_40 , & V_83 ,
V_34 -> V_30 + 1 , 0 , V_56 -> V_87 ,
V_56 -> V_96 * V_84 ) ;
break;
}
case V_97 : {
struct V_95 * V_34 ;
V_34 = F_54 ( V_56 ) ;
V_24 = F_11 ( V_78 , V_34 -> V_40 , NULL ,
V_34 -> V_30 + 1 , V_34 -> V_31 ,
V_56 -> V_87 ,
V_56 -> V_96 * V_84 ) ;
break;
}
case V_98 : {
struct V_99 * V_34 ;
V_34 = F_55 ( V_56 ) ;
V_2 . V_17 = V_34 -> V_17 ;
V_2 . type = V_25 ;
V_2 . V_18 = V_34 -> V_18 ;
V_24 = F_11 ( V_78 , V_34 -> V_40 , & V_2 , 0 , 0 ,
V_56 -> V_87 ,
V_56 -> V_96 * V_84 ) ;
break;
}
case V_100 : {
struct V_99 * V_34 ;
V_34 = F_55 ( V_56 ) ;
V_2 . V_17 = V_34 -> V_17 ;
V_2 . type = V_25 ;
V_2 . V_18 = V_34 -> V_18 ;
V_24 = F_11 ( V_78 , V_34 -> V_40 , & V_2 , 0 ,
V_34 -> V_31 , V_56 -> V_87 ,
V_56 -> V_96 * V_84 ) ;
break;
}
default:
F_27 ( 1 ) ;
}
F_41 ( V_24 ) ;
}
return 0 ;
}
static int F_56 ( struct V_49 * V_50 ,
struct V_41 * V_42 , T_1 V_87 ,
int * V_101 , struct V_27 * V_78 )
{
int V_24 = 0 ;
int V_21 ;
struct V_3 * V_102 ;
struct V_1 V_2 ;
unsigned long V_103 ;
unsigned long V_104 ;
struct V_105 * V_106 ;
T_1 V_107 ;
T_1 V_108 ;
V_102 = V_42 -> V_46 [ 0 ] ;
V_21 = V_42 -> V_48 [ 0 ] ;
V_108 = F_57 ( V_102 , V_21 ) ;
F_41 ( V_108 < sizeof( * V_106 ) ) ;
V_106 = F_8 ( V_102 , V_21 , struct V_105 ) ;
V_107 = F_58 ( V_102 , V_106 ) ;
V_103 = ( unsigned long ) ( V_106 + 1 ) ;
V_104 = ( unsigned long ) V_106 + V_108 ;
if ( V_107 & V_109 ) {
struct V_110 * V_111 ;
V_111 = (struct V_110 * ) V_103 ;
* V_101 = F_59 ( V_102 , V_111 ) ;
V_103 += sizeof( struct V_110 ) ;
F_41 ( V_103 > V_104 ) ;
} else {
F_41 ( ! ( V_107 & V_112 ) ) ;
}
while ( V_103 < V_104 ) {
struct V_113 * V_114 ;
T_1 V_18 ;
int type ;
V_114 = (struct V_113 * ) V_103 ;
type = F_60 ( V_102 , V_114 ) ;
V_18 = F_61 ( V_102 , V_114 ) ;
switch ( type ) {
case V_97 :
V_24 = F_11 ( V_78 , 0 , NULL ,
* V_101 + 1 , V_18 ,
V_87 , 1 ) ;
break;
case V_100 : {
struct V_115 * V_116 ;
int V_32 ;
V_116 = (struct V_115 * ) ( V_114 + 1 ) ;
V_32 = F_62 ( V_102 , V_116 ) ;
V_24 = F_11 ( V_78 , 0 , NULL , 0 , V_18 ,
V_87 , V_32 ) ;
break;
}
case V_94 :
V_24 = F_11 ( V_78 , V_18 , NULL ,
* V_101 + 1 , 0 ,
V_87 , 1 ) ;
break;
case V_98 : {
struct V_117 * V_118 ;
int V_32 ;
T_1 V_40 ;
V_118 = (struct V_117 * ) ( & V_114 -> V_18 ) ;
V_32 = F_63 ( V_102 , V_118 ) ;
V_2 . V_17 = F_64 ( V_102 ,
V_118 ) ;
V_2 . type = V_25 ;
V_2 . V_18 = F_65 ( V_102 , V_118 ) ;
V_40 = F_66 ( V_102 , V_118 ) ;
V_24 = F_11 ( V_78 , V_40 , & V_2 , 0 , 0 ,
V_87 , V_32 ) ;
break;
}
default:
F_27 ( 1 ) ;
}
F_41 ( V_24 ) ;
V_103 += F_67 ( type ) ;
}
return 0 ;
}
static int F_68 ( struct V_49 * V_50 ,
struct V_41 * V_42 , T_1 V_87 ,
int V_101 , struct V_27 * V_78 )
{
struct V_39 * V_119 = V_50 -> V_119 ;
int V_24 ;
int V_21 ;
struct V_3 * V_102 ;
struct V_1 V_2 ;
while ( 1 ) {
V_24 = F_69 ( V_119 , V_42 ) ;
if ( V_24 < 0 )
break;
if ( V_24 ) {
V_24 = 0 ;
break;
}
V_21 = V_42 -> V_48 [ 0 ] ;
V_102 = V_42 -> V_46 [ 0 ] ;
F_7 ( V_102 , & V_2 , V_21 ) ;
if ( V_2 . V_17 != V_87 )
break;
if ( V_2 . type < V_94 )
continue;
if ( V_2 . type > V_100 )
break;
switch ( V_2 . type ) {
case V_97 :
V_24 = F_11 ( V_78 , 0 , NULL ,
V_101 + 1 , V_2 . V_18 ,
V_87 , 1 ) ;
break;
case V_100 : {
struct V_115 * V_116 ;
int V_32 ;
V_116 = F_8 ( V_102 , V_21 ,
struct V_115 ) ;
V_32 = F_62 ( V_102 , V_116 ) ;
V_24 = F_11 ( V_78 , 0 , NULL , 0 , V_2 . V_18 ,
V_87 , V_32 ) ;
break;
}
case V_94 :
V_24 = F_11 ( V_78 , V_2 . V_18 , NULL ,
V_101 + 1 , 0 ,
V_87 , 1 ) ;
break;
case V_98 : {
struct V_117 * V_118 ;
int V_32 ;
T_1 V_40 ;
V_118 = F_8 ( V_102 , V_21 ,
struct V_117 ) ;
V_32 = F_63 ( V_102 , V_118 ) ;
V_2 . V_17 = F_64 ( V_102 ,
V_118 ) ;
V_2 . type = V_25 ;
V_2 . V_18 = F_65 ( V_102 , V_118 ) ;
V_40 = F_66 ( V_102 , V_118 ) ;
V_24 = F_11 ( V_78 , V_40 , & V_2 , 0 , 0 ,
V_87 , V_32 ) ;
break;
}
default:
F_27 ( 1 ) ;
}
F_41 ( V_24 ) ;
}
return V_24 ;
}
static int F_70 ( struct V_120 * V_121 ,
struct V_49 * V_50 , T_1 V_87 ,
T_1 V_45 , struct V_43 * V_122 ,
struct V_43 * V_123 , const T_1 * V_7 )
{
struct V_1 V_2 ;
struct V_41 * V_42 ;
struct V_124 * V_125 = NULL ;
struct V_76 * V_28 ;
int V_101 = 0 ;
int V_24 ;
int V_51 = ( V_121 == V_126 ) ;
struct V_27 V_127 ;
struct V_27 V_78 ;
struct V_33 * V_34 ;
F_71 ( & V_78 ) ;
F_71 ( & V_127 ) ;
V_2 . V_17 = V_87 ;
V_2 . type = V_128 ;
V_2 . V_18 = ( T_1 ) - 1 ;
V_42 = F_18 () ;
if ( ! V_42 )
return - V_14 ;
V_42 -> V_51 = ! ! V_51 ;
V_129:
V_28 = NULL ;
V_24 = F_72 ( V_121 , V_50 -> V_119 , & V_2 , V_42 , 0 , 0 ) ;
if ( V_24 < 0 )
goto V_55;
F_41 ( V_24 == 0 ) ;
if ( V_121 != V_126 ) {
V_125 = & V_121 -> V_130 -> V_125 ;
F_73 ( & V_125 -> V_131 ) ;
V_28 = F_74 ( V_121 , V_87 ) ;
if ( V_28 ) {
if ( ! F_75 ( & V_28 -> V_132 ) ) {
F_76 ( & V_28 -> V_56 . V_122 ) ;
F_77 ( & V_125 -> V_131 ) ;
F_78 ( V_42 ) ;
F_79 ( & V_28 -> V_132 ) ;
F_80 ( & V_28 -> V_132 ) ;
F_81 ( & V_28 -> V_56 ) ;
goto V_129;
}
V_24 = F_50 ( V_28 , V_45 ,
& V_127 ) ;
F_80 ( & V_28 -> V_132 ) ;
if ( V_24 ) {
F_77 ( & V_125 -> V_131 ) ;
goto V_55;
}
}
F_77 ( & V_125 -> V_131 ) ;
}
if ( V_42 -> V_48 [ 0 ] ) {
struct V_3 * V_102 ;
int V_21 ;
V_42 -> V_48 [ 0 ] -- ;
V_102 = V_42 -> V_46 [ 0 ] ;
V_21 = V_42 -> V_48 [ 0 ] ;
F_7 ( V_102 , & V_2 , V_21 ) ;
if ( V_2 . V_17 == V_87 &&
V_2 . type == V_128 ) {
V_24 = F_56 ( V_50 , V_42 , V_87 ,
& V_101 , & V_78 ) ;
if ( V_24 )
goto V_55;
V_24 = F_68 ( V_50 , V_42 , V_87 ,
V_101 , & V_78 ) ;
if ( V_24 )
goto V_55;
}
}
F_78 ( V_42 ) ;
F_82 ( & V_127 , & V_78 ) ;
V_24 = F_38 ( V_50 , & V_78 ) ;
if ( V_24 )
goto V_55;
V_24 = F_47 ( & V_78 , 1 ) ;
if ( V_24 )
goto V_55;
V_24 = F_29 ( V_50 , V_51 , V_45 ,
& V_78 , V_7 ) ;
if ( V_24 )
goto V_55;
V_24 = F_47 ( & V_78 , 2 ) ;
if ( V_24 )
goto V_55;
while ( ! F_83 ( & V_78 ) ) {
V_34 = F_84 ( & V_78 , struct V_33 , V_38 ) ;
F_48 ( & V_34 -> V_38 ) ;
if ( V_34 -> V_32 < 0 )
F_27 ( 1 ) ;
if ( V_34 -> V_32 && V_34 -> V_29 && V_34 -> V_31 == 0 ) {
V_24 = F_14 ( V_123 , V_34 -> V_29 , 0 , V_13 ) ;
F_41 ( V_24 < 0 ) ;
}
if ( V_34 -> V_32 && V_34 -> V_31 ) {
struct V_8 * V_9 = NULL ;
if ( V_7 && ! V_34 -> V_37 ) {
T_2 V_133 ;
struct V_3 * V_4 ;
V_133 = F_85 ( V_50 -> V_119 ,
V_101 ) ;
V_4 = F_42 ( V_50 -> V_119 ,
V_34 -> V_31 , V_133 , 0 ) ;
F_41 ( ! V_4 ) ;
V_24 = F_5 ( V_4 , V_87 ,
* V_7 , & V_9 ) ;
V_34 -> V_37 = V_9 ;
F_46 ( V_4 ) ;
}
V_24 = F_86 ( V_122 , V_34 -> V_31 ,
( unsigned long ) V_34 -> V_37 ,
( unsigned long * ) & V_9 , V_13 ) ;
if ( ! V_24 && V_7 ) {
F_41 ( ! V_9 ) ;
while ( V_9 -> V_15 )
V_9 = V_9 -> V_15 ;
V_9 -> V_15 = V_34 -> V_37 ;
}
F_41 ( V_24 < 0 ) ;
}
F_49 ( V_34 ) ;
}
V_55:
F_28 ( V_42 ) ;
while ( ! F_83 ( & V_78 ) ) {
V_34 = F_84 ( & V_78 , struct V_33 , V_38 ) ;
F_48 ( & V_34 -> V_38 ) ;
F_49 ( V_34 ) ;
}
while ( ! F_83 ( & V_127 ) ) {
V_34 = F_84 ( & V_127 , struct V_33 ,
V_38 ) ;
F_48 ( & V_34 -> V_38 ) ;
F_49 ( V_34 ) ;
}
return V_24 ;
}
static void F_87 ( struct V_43 * V_134 )
{
struct V_61 * V_56 = NULL ;
struct V_8 * V_9 ;
struct V_8 * V_135 ;
struct V_62 V_63 ;
F_32 ( & V_63 ) ;
while ( ( V_56 = F_33 ( V_134 , & V_63 ) ) ) {
if ( ! V_56 -> V_65 )
continue;
V_9 = (struct V_8 * ) V_56 -> V_65 ;
for (; V_9 ; V_9 = V_135 ) {
V_135 = V_9 -> V_15 ;
F_49 ( V_9 ) ;
}
V_56 -> V_65 = 0 ;
}
F_36 ( V_134 ) ;
}
static int F_88 ( struct V_120 * V_121 ,
struct V_49 * V_50 , T_1 V_87 ,
T_1 V_45 , struct V_43 * * V_136 ,
const T_1 * V_7 )
{
struct V_43 * V_137 ;
int V_24 ;
V_137 = F_30 ( V_13 ) ;
if ( ! V_137 )
return - V_14 ;
* V_136 = F_30 ( V_13 ) ;
if ( ! * V_136 ) {
F_36 ( V_137 ) ;
return - V_14 ;
}
V_24 = F_70 ( V_121 , V_50 , V_87 ,
V_45 , * V_136 , V_137 , V_7 ) ;
F_36 ( V_137 ) ;
if ( V_24 < 0 && V_24 != - V_138 ) {
F_87 ( * V_136 ) ;
return V_24 ;
}
return 0 ;
}
int F_89 ( struct V_120 * V_121 ,
struct V_49 * V_50 , T_1 V_87 ,
T_1 V_45 , struct V_43 * * V_123 )
{
struct V_43 * V_137 ;
struct V_61 * V_56 = NULL ;
struct V_62 V_63 ;
int V_24 ;
V_137 = F_30 ( V_13 ) ;
if ( ! V_137 )
return - V_14 ;
* V_123 = F_30 ( V_13 ) ;
if ( ! * V_123 ) {
F_36 ( V_137 ) ;
return - V_14 ;
}
F_32 ( & V_63 ) ;
while ( 1 ) {
V_24 = F_70 ( V_121 , V_50 , V_87 ,
V_45 , V_137 , * V_123 , NULL ) ;
if ( V_24 < 0 && V_24 != - V_138 ) {
F_36 ( V_137 ) ;
F_36 ( * V_123 ) ;
return V_24 ;
}
V_56 = F_33 ( V_137 , & V_63 ) ;
if ( ! V_56 )
break;
V_87 = V_56 -> V_64 ;
}
F_36 ( V_137 ) ;
return 0 ;
}
static int F_90 ( T_1 V_16 , T_1 V_139 , T_3 V_140 ,
struct V_39 * V_141 , struct V_41 * V_42 ,
struct V_1 * V_142 )
{
int V_24 ;
struct V_1 V_2 ;
struct V_3 * V_4 ;
V_2 . type = V_140 ;
V_2 . V_17 = V_16 ;
V_2 . V_18 = V_139 ;
V_24 = F_72 ( NULL , V_141 , & V_2 , V_42 , 0 , 0 ) ;
if ( V_24 < 0 )
return V_24 ;
V_4 = V_42 -> V_46 [ 0 ] ;
if ( V_24 && V_42 -> V_48 [ 0 ] >= F_6 ( V_4 ) ) {
V_24 = F_91 ( V_141 , V_42 ) ;
if ( V_24 )
return V_24 ;
V_4 = V_42 -> V_46 [ 0 ] ;
}
F_7 ( V_4 , V_142 , V_42 -> V_48 [ 0 ] ) ;
if ( V_142 -> type != V_2 . type || V_142 -> V_17 != V_2 . V_17 )
return 1 ;
return 0 ;
}
int F_92 ( T_1 V_16 , T_1 V_139 , struct V_39 * V_141 ,
struct V_41 * V_42 )
{
struct V_1 V_2 ;
return F_90 ( V_16 , V_139 , V_143 , V_141 , V_42 ,
& V_2 ) ;
}
static int F_93 ( T_1 V_16 , T_1 V_139 , struct V_39 * V_141 ,
struct V_41 * V_42 ,
struct V_1 * V_142 )
{
return F_90 ( V_16 , V_139 , V_144 , V_141 , V_42 ,
V_142 ) ;
}
char * F_94 ( struct V_39 * V_141 , struct V_41 * V_42 ,
struct V_145 * V_114 ,
struct V_3 * V_146 , T_1 V_31 ,
char * V_147 , T_2 V_148 )
{
T_2 V_149 ;
int V_21 ;
T_1 V_150 ;
int V_24 ;
T_4 V_151 = V_148 - 1 ;
struct V_3 * V_4 = V_146 ;
struct V_1 V_142 ;
int V_152 = V_42 -> V_152 ;
if ( V_151 >= 0 )
V_147 [ V_151 ] = '\0' ;
V_42 -> V_152 = 1 ;
while ( 1 ) {
V_149 = F_95 ( V_4 , V_114 ) ;
V_151 -= V_149 ;
if ( V_151 >= 0 )
F_96 ( V_4 , V_147 + V_151 ,
( unsigned long ) ( V_114 + 1 ) , V_149 ) ;
if ( V_4 != V_146 ) {
F_97 ( V_4 ) ;
F_46 ( V_4 ) ;
}
V_24 = F_93 ( V_31 , 0 , V_141 , V_42 , & V_142 ) ;
if ( V_24 > 0 )
V_24 = - V_138 ;
if ( V_24 )
break;
V_150 = V_142 . V_18 ;
if ( V_31 == V_150 )
break;
V_21 = V_42 -> V_48 [ 0 ] ;
V_4 = V_42 -> V_46 [ 0 ] ;
if ( V_4 != V_146 ) {
F_76 ( & V_4 -> V_122 ) ;
F_43 ( V_4 ) ;
F_98 ( V_4 , V_153 ) ;
}
F_78 ( V_42 ) ;
V_114 = F_8 ( V_4 , V_21 , struct V_145 ) ;
V_31 = V_150 ;
-- V_151 ;
if ( V_151 >= 0 )
V_147 [ V_151 ] = '/' ;
}
F_78 ( V_42 ) ;
V_42 -> V_152 = V_152 ;
if ( V_24 )
return F_99 ( V_24 ) ;
return V_147 + V_151 ;
}
int F_100 ( struct V_49 * V_50 , T_1 V_154 ,
struct V_41 * V_42 , struct V_1 * V_142 )
{
int V_24 ;
T_1 V_107 ;
T_2 V_108 ;
struct V_3 * V_4 ;
struct V_105 * V_106 ;
struct V_1 V_2 ;
V_2 . type = V_128 ;
V_2 . V_17 = V_154 ;
V_2 . V_18 = ( T_1 ) - 1 ;
V_24 = F_72 ( NULL , V_50 -> V_119 , & V_2 , V_42 , 0 , 0 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_101 ( V_50 -> V_119 , V_42 ,
0 , V_128 ) ;
if ( V_24 < 0 )
return V_24 ;
F_7 ( V_42 -> V_46 [ 0 ] , V_142 , V_42 -> V_48 [ 0 ] ) ;
if ( V_142 -> type != V_128 ||
V_142 -> V_17 > V_154 ||
V_142 -> V_17 + V_142 -> V_18 <= V_154 ) {
F_26 ( L_3 ,
( unsigned long long ) V_154 ) ;
return - V_138 ;
}
V_4 = V_42 -> V_46 [ 0 ] ;
V_108 = F_57 ( V_4 , V_42 -> V_48 [ 0 ] ) ;
F_41 ( V_108 < sizeof( * V_106 ) ) ;
V_106 = F_8 ( V_4 , V_42 -> V_48 [ 0 ] , struct V_105 ) ;
V_107 = F_58 ( V_4 , V_106 ) ;
F_26 ( L_4
L_5 ,
( unsigned long long ) V_154 ,
( unsigned long long ) ( V_154 - V_142 -> V_17 ) ,
( unsigned long long ) V_142 -> V_17 ,
( unsigned long long ) V_142 -> V_18 ,
( unsigned long long ) V_107 , V_108 ) ;
if ( V_107 & V_109 )
return V_109 ;
if ( V_107 & V_112 )
return V_112 ;
return - V_155 ;
}
static int F_102 ( unsigned long * V_103 , struct V_3 * V_4 ,
struct V_105 * V_106 , T_2 V_108 ,
struct V_113 * * V_156 ,
int * V_157 )
{
unsigned long V_104 ;
T_1 V_107 ;
struct V_110 * V_111 ;
if ( ! * V_103 ) {
V_107 = F_58 ( V_4 , V_106 ) ;
if ( V_107 & V_109 ) {
V_111 = (struct V_110 * ) ( V_106 + 1 ) ;
* V_156 =
(struct V_113 * ) ( V_111 + 1 ) ;
} else {
* V_156 = (struct V_113 * ) ( V_106 + 1 ) ;
}
* V_103 = ( unsigned long ) * V_156 ;
if ( ( void * ) * V_103 >= ( void * ) V_106 + V_108 )
return - V_138 ;
}
V_104 = ( unsigned long ) V_106 + V_108 ;
* V_156 = (struct V_113 * ) * V_103 ;
* V_157 = F_60 ( V_4 , * V_156 ) ;
* V_103 += F_67 ( * V_157 ) ;
F_27 ( * V_103 > V_104 ) ;
if ( * V_103 == V_104 )
return 1 ;
return 0 ;
}
int F_103 ( unsigned long * V_103 , struct V_3 * V_4 ,
struct V_105 * V_106 , T_2 V_108 ,
T_1 * V_158 , T_3 * V_159 )
{
int V_24 ;
int type ;
struct V_110 * V_111 ;
struct V_113 * V_160 ;
if ( * V_103 == ( unsigned long ) - 1 )
return 1 ;
while ( 1 ) {
V_24 = F_102 ( V_103 , V_4 , V_106 , V_108 ,
& V_160 , & type ) ;
if ( V_24 < 0 )
return V_24 ;
if ( type == V_94 ||
type == V_97 )
break;
if ( V_24 == 1 )
return 1 ;
}
V_111 = (struct V_110 * ) ( V_106 + 1 ) ;
* V_158 = F_61 ( V_4 , V_160 ) ;
* V_159 = F_59 ( V_4 , V_111 ) ;
if ( V_24 == 1 )
* V_103 = ( unsigned long ) - 1 ;
return 0 ;
}
static int F_104 ( struct V_8 * V_37 ,
T_1 V_40 , T_1 V_161 ,
T_5 * V_162 , void * V_163 )
{
struct V_8 * V_9 ;
int V_24 = 0 ;
for ( V_9 = V_37 ; V_9 ; V_9 = V_9 -> V_15 ) {
F_26 ( L_6
L_7 , V_161 ,
V_9 -> V_16 , V_9 -> V_18 , V_40 ) ;
V_24 = V_162 ( V_9 -> V_16 , V_9 -> V_18 , V_40 , V_163 ) ;
if ( V_24 ) {
F_26 ( L_8 ,
V_161 , V_24 ) ;
break;
}
}
return V_24 ;
}
int F_105 ( struct V_49 * V_50 ,
T_1 V_161 , T_1 V_7 ,
int V_51 ,
T_5 * V_162 , void * V_163 )
{
int V_24 ;
struct V_27 V_164 = F_106 ( V_164 ) ;
struct V_27 V_165 = F_106 ( V_165 ) ;
struct V_120 * V_121 ;
struct V_43 * V_122 = NULL ;
struct V_43 * V_123 = NULL ;
struct V_61 * V_166 = NULL ;
struct V_61 * V_167 = NULL ;
struct V_168 V_169 = {} ;
struct V_62 V_170 ;
struct V_62 V_171 ;
F_26 ( L_9 ,
V_161 ) ;
if ( V_51 ) {
V_121 = V_126 ;
} else {
V_121 = F_107 ( V_50 -> V_119 ) ;
if ( F_20 ( V_121 ) )
return F_21 ( V_121 ) ;
F_108 ( V_50 , & V_169 ) ;
}
V_24 = F_88 ( V_121 , V_50 , V_161 ,
V_169 . V_77 , & V_122 ,
& V_7 ) ;
if ( V_24 )
goto V_55;
F_32 ( & V_170 ) ;
while ( ! V_24 && ( V_166 = F_33 ( V_122 , & V_170 ) ) ) {
V_24 = F_89 ( V_121 , V_50 , V_166 -> V_64 ,
V_169 . V_77 , & V_123 ) ;
if ( V_24 )
break;
F_32 ( & V_171 ) ;
while ( ! V_24 && ( V_167 = F_33 ( V_123 , & V_171 ) ) ) {
F_26 ( L_10
L_11 , V_167 -> V_64 , V_166 -> V_64 ,
V_166 -> V_65 ) ;
V_24 = F_104 (
(struct V_8 * ) V_166 -> V_65 ,
V_167 -> V_64 , V_161 ,
V_162 , V_163 ) ;
}
F_36 ( V_123 ) ;
V_123 = NULL ;
}
F_87 ( V_122 ) ;
F_36 ( V_123 ) ;
V_55:
if ( ! V_51 ) {
F_109 ( V_50 , & V_169 ) ;
F_110 ( V_121 , V_50 -> V_119 ) ;
}
return V_24 ;
}
int F_111 ( T_1 V_154 , struct V_49 * V_50 ,
struct V_41 * V_42 ,
T_5 * V_162 , void * V_163 )
{
int V_24 ;
T_1 V_7 ;
struct V_1 V_142 ;
int V_51 = V_42 -> V_51 ;
V_24 = F_100 ( V_50 , V_154 , V_42 ,
& V_142 ) ;
F_78 ( V_42 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_24 & V_109 )
return - V_172 ;
V_7 = V_154 - V_142 . V_17 ;
V_24 = F_105 ( V_50 , V_142 . V_17 ,
V_7 , V_51 ,
V_162 , V_163 ) ;
return V_24 ;
}
static int F_112 ( T_1 V_16 , struct V_39 * V_141 ,
struct V_41 * V_42 ,
T_6 * V_162 , void * V_163 )
{
int V_24 = 0 ;
int V_21 ;
T_2 V_173 ;
T_2 V_149 ;
T_2 V_174 ;
T_1 V_31 = 0 ;
int V_175 = 0 ;
struct V_3 * V_4 ;
struct V_176 * V_177 ;
struct V_145 * V_114 ;
struct V_1 V_142 ;
while ( ! V_24 ) {
V_42 -> V_152 = 1 ;
V_24 = F_93 ( V_16 , V_31 ? V_31 + 1 : 0 , V_141 , V_42 ,
& V_142 ) ;
if ( V_24 < 0 )
break;
if ( V_24 ) {
V_24 = V_175 ? 0 : - V_138 ;
break;
}
++ V_175 ;
V_31 = V_142 . V_18 ;
V_21 = V_42 -> V_48 [ 0 ] ;
V_4 = V_42 -> V_46 [ 0 ] ;
F_76 ( & V_4 -> V_122 ) ;
F_43 ( V_4 ) ;
F_98 ( V_4 , V_153 ) ;
F_78 ( V_42 ) ;
V_177 = F_113 ( V_4 , V_21 ) ;
V_114 = F_8 ( V_4 , V_21 , struct V_145 ) ;
for ( V_173 = 0 ; V_173 < F_114 ( V_4 , V_177 ) ; V_173 += V_149 ) {
V_174 = F_95 ( V_4 , V_114 ) ;
F_26 ( L_12
L_13 , V_173 ,
( unsigned long long ) V_142 . V_17 ,
( unsigned long long ) V_141 -> V_17 ) ;
V_24 = V_162 ( V_31 , V_114 , V_4 , V_163 ) ;
if ( V_24 )
break;
V_149 = sizeof( * V_114 ) + V_174 ;
V_114 = (struct V_145 * ) ( ( char * ) V_114 + V_149 ) ;
}
F_97 ( V_4 ) ;
F_46 ( V_4 ) ;
}
F_78 ( V_42 ) ;
return V_24 ;
}
static int F_115 ( T_1 V_16 , struct V_145 * V_114 ,
struct V_3 * V_4 , void * V_163 )
{
struct V_178 * V_179 = V_163 ;
char * V_180 ;
char * V_181 ;
int V_182 = V_179 -> V_180 -> V_183 ;
const int V_184 = sizeof( char * ) ;
T_2 V_151 ;
V_151 = V_179 -> V_180 -> V_151 > V_184 ?
V_179 -> V_180 -> V_151 - V_184 : 0 ;
V_181 = ( char * ) V_179 -> V_180 -> V_64 + ( V_182 + 1 ) * V_184 ;
V_180 = F_94 ( V_179 -> V_141 , V_179 -> V_41 , V_114 , V_4 ,
V_16 , V_181 , V_151 ) ;
if ( F_20 ( V_180 ) )
return F_21 ( V_180 ) ;
if ( V_180 > V_181 ) {
F_26 ( L_14 , V_180 ) ;
V_179 -> V_180 -> V_64 [ V_182 ] = ( T_1 ) ( unsigned long ) V_180 ;
++ V_179 -> V_180 -> V_183 ;
V_179 -> V_180 -> V_151 = V_180 - V_181 ;
} else {
F_26 ( L_15
L_16 ,
( unsigned long ) ( V_181 - V_180 ) , V_181 ) ;
++ V_179 -> V_180 -> V_185 ;
V_179 -> V_180 -> V_186 += V_181 - V_180 ;
V_179 -> V_180 -> V_151 = 0 ;
}
return 0 ;
}
int F_116 ( T_1 V_16 , struct V_178 * V_179 )
{
return F_112 ( V_16 , V_179 -> V_141 , V_179 -> V_41 ,
F_115 , V_179 ) ;
}
struct V_187 * F_117 ( T_2 V_188 )
{
struct V_187 * V_189 ;
T_7 V_190 ;
V_190 = F_118 ( T_7 , V_188 , sizeof( * V_189 ) ) ;
V_189 = F_4 ( V_190 , V_13 ) ;
if ( ! V_189 )
return F_99 ( - V_14 ) ;
if ( V_188 >= sizeof( * V_189 ) ) {
V_189 -> V_151 = V_188 - sizeof( * V_189 ) ;
V_189 -> V_186 = 0 ;
} else {
V_189 -> V_186 = sizeof( * V_189 ) - V_188 ;
V_189 -> V_151 = 0 ;
}
V_189 -> V_183 = 0 ;
V_189 -> V_185 = 0 ;
return V_189 ;
}
struct V_178 * F_119 ( T_8 V_188 , struct V_39 * V_141 ,
struct V_41 * V_42 )
{
struct V_178 * V_191 ;
struct V_187 * V_180 ;
V_180 = F_117 ( V_188 ) ;
if ( F_20 ( V_180 ) )
return ( void * ) V_180 ;
V_191 = F_4 ( sizeof( * V_191 ) , V_13 ) ;
if ( ! V_191 ) {
F_49 ( V_180 ) ;
return F_99 ( - V_14 ) ;
}
V_191 -> V_41 = V_42 ;
V_191 -> V_180 = V_180 ;
V_191 -> V_141 = V_141 ;
return V_191 ;
}
void F_120 ( struct V_178 * V_179 )
{
if ( ! V_179 )
return;
F_49 ( V_179 -> V_180 ) ;
F_49 ( V_179 ) ;
}
