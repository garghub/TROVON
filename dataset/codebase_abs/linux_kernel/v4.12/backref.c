static struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( sizeof( * V_2 ) , V_3 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_4 = V_5 ;
V_2 -> V_6 = 0 ;
return V_2 ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
while ( ( V_10 = F_4 ( & V_2 -> V_4 ) ) != NULL ) {
V_8 = F_5 ( V_10 , struct V_7 , V_9 ) ;
F_6 ( V_10 , & V_2 -> V_4 ) ;
F_7 ( V_8 ) ;
}
V_2 -> V_4 = V_5 ;
V_2 -> V_6 = 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_3 ( V_2 ) ;
F_7 ( V_2 ) ;
}
static int F_9 ( struct V_7 * V_11 , struct V_7 * V_12 )
{
if ( V_11 -> V_13 < V_12 -> V_13 )
return - 1 ;
else if ( V_11 -> V_13 > V_12 -> V_13 )
return 1 ;
if ( V_11 -> V_14 < V_12 -> V_14 )
return - 1 ;
else if ( V_11 -> V_14 > V_12 -> V_14 )
return 1 ;
if ( V_11 -> V_15 < V_12 -> V_15 )
return - 1 ;
else if ( V_11 -> V_15 > V_12 -> V_15 )
return 1 ;
if ( V_11 -> V_16 < V_12 -> V_16 )
return - 1 ;
else if ( V_11 -> V_16 > V_12 -> V_16 )
return 1 ;
return 0 ;
}
static struct V_7 * F_10 ( struct V_1 * V_2 ,
struct V_9 * * * V_17 ,
struct V_9 * * V_18 ,
T_1 V_13 , T_1 V_14 ,
T_1 V_15 , T_1 V_16 )
{
struct V_7 * V_19 = NULL ;
struct V_7 V_20 ;
int V_21 ;
V_20 . V_13 = V_13 ;
V_20 . V_14 = V_14 ;
V_20 . V_15 = V_15 ;
V_20 . V_16 = V_16 ;
* V_17 = & V_2 -> V_4 . V_9 ;
while ( * * V_17 ) {
* V_18 = * * V_17 ;
V_19 = F_5 ( * V_18 , struct V_7 , V_9 ) ;
V_21 = F_9 ( V_19 , & V_20 ) ;
if ( V_21 > 0 )
* V_17 = & ( * * V_17 ) -> V_22 ;
else if ( V_21 < 0 )
* V_17 = & ( * * V_17 ) -> V_23 ;
else
return V_19 ;
}
return NULL ;
}
static int F_11 ( struct V_1 * V_2 , struct V_9 * * V_17 ,
struct V_9 * V_18 , struct V_7 * V_24 )
{
struct V_9 * * V_25 = NULL ;
struct V_9 * V_16 = NULL ;
struct V_7 * V_19 = NULL ;
if ( ! V_17 ) {
V_19 = F_10 ( V_2 , & V_25 , & V_16 , V_24 -> V_13 ,
V_24 -> V_14 , V_24 -> V_15 ,
V_24 -> V_16 ) ;
if ( V_19 )
return - V_26 ;
} else {
V_25 = V_17 ;
V_16 = V_18 ;
}
F_12 ( & V_24 -> V_9 , V_16 , V_25 ) ;
F_13 ( & V_24 -> V_9 , & V_2 -> V_4 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
F_6 ( & V_8 -> V_9 , & V_2 -> V_4 ) ;
F_7 ( V_8 ) ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_13 , T_1 V_14 ,
T_1 V_15 , T_1 V_16 , int V_27 )
{
struct V_7 * V_8 = NULL ;
struct V_9 * * V_17 = NULL ;
struct V_9 * V_18 = NULL ;
int V_28 ;
int V_21 ;
if ( ! V_27 )
return 0 ;
V_8 = F_10 ( V_2 , & V_17 , & V_18 , V_13 ,
V_14 , V_15 , V_16 ) ;
if ( V_8 == NULL ) {
V_8 = F_2 ( sizeof( * V_8 ) , V_3 ) ;
if ( ! V_8 )
return - V_29 ;
V_8 -> V_13 = V_13 ;
V_8 -> V_14 = V_14 ;
V_8 -> V_15 = V_15 ;
V_8 -> V_16 = V_16 ;
V_8 -> V_30 = V_27 ;
V_21 = F_11 ( V_2 , V_17 , V_18 , V_8 ) ;
ASSERT ( ! V_21 ) ;
if ( V_21 ) {
F_7 ( V_8 ) ;
return V_21 ;
}
V_2 -> V_6 += V_8 -> V_30 > 0 ? 1 : 0 ;
return 0 ;
}
V_28 = V_8 -> V_30 ;
V_8 -> V_30 += V_27 ;
if ( V_8 -> V_30 > 0 )
V_2 -> V_6 += V_28 > 0 ? 0 : 1 ;
else if ( V_8 -> V_30 <= 0 )
V_2 -> V_6 += V_28 > 0 ? - 1 : 0 ;
if ( ! V_8 -> V_30 )
F_14 ( V_2 , V_8 ) ;
return 0 ;
}
static int F_16 ( struct V_31 * V_32 , struct V_33 * V_34 ,
struct V_35 * V_36 ,
T_1 V_37 ,
struct V_38 * * V_39 )
{
T_1 V_15 = 0 ;
struct V_38 * V_40 ;
if ( ! F_17 ( V_34 , V_36 ) &&
! F_18 ( V_34 , V_36 ) &&
! F_19 ( V_34 , V_36 ) ) {
T_1 V_41 ;
T_1 V_42 ;
V_41 = F_20 ( V_34 , V_36 ) ;
V_42 = F_21 ( V_34 , V_36 ) ;
if ( V_37 < V_41 ||
V_37 >= V_41 + V_42 )
return 1 ;
V_15 = V_37 - V_41 ;
}
V_40 = F_2 ( sizeof( * V_40 ) , V_3 ) ;
if ( ! V_40 )
return - V_29 ;
V_40 -> V_10 = * V_39 ;
V_40 -> V_43 = V_32 -> V_44 ;
V_40 -> V_15 = V_32 -> V_15 + V_15 ;
* V_39 = V_40 ;
return 0 ;
}
static void F_22 ( struct V_38 * V_39 )
{
struct V_38 * V_45 ;
for (; V_39 ; V_39 = V_45 ) {
V_45 = V_39 -> V_10 ;
F_7 ( V_39 ) ;
}
}
static int F_23 ( struct V_33 * V_34 , T_1 V_46 ,
T_1 V_37 ,
struct V_38 * * V_39 )
{
T_1 V_47 ;
struct V_31 V_32 ;
struct V_35 * V_36 ;
int V_48 ;
int V_49 ;
int V_50 ;
int V_21 ;
V_49 = F_24 ( V_34 ) ;
for ( V_48 = 0 ; V_48 < V_49 ; ++ V_48 ) {
F_25 ( V_34 , & V_32 , V_48 ) ;
if ( V_32 . type != V_51 )
continue;
V_36 = F_26 ( V_34 , V_48 , struct V_35 ) ;
V_50 = F_27 ( V_34 , V_36 ) ;
if ( V_50 == V_52 )
continue;
V_47 = F_28 ( V_34 , V_36 ) ;
if ( V_47 != V_46 )
continue;
V_21 = F_16 ( & V_32 , V_34 , V_36 , V_37 , V_39 ) ;
if ( V_21 < 0 )
return V_21 ;
}
return 0 ;
}
int T_2 F_29 ( void )
{
V_53 = F_30 ( L_1 ,
sizeof( struct V_54 ) ,
0 ,
V_55 ,
NULL ) ;
if ( ! V_53 )
return - V_29 ;
return 0 ;
}
void F_31 ( void )
{
F_32 ( V_53 ) ;
}
static int F_33 ( struct V_56 * V_57 , T_1 V_13 ,
struct V_31 * V_32 , int V_58 ,
T_1 V_16 , T_1 V_46 , int V_27 ,
T_3 V_59 )
{
struct V_54 * V_60 ;
if ( V_13 == V_61 )
return 0 ;
V_60 = F_34 ( V_53 , V_59 ) ;
if ( ! V_60 )
return - V_29 ;
V_60 -> V_13 = V_13 ;
if ( V_32 ) {
V_60 -> V_62 = * V_32 ;
if ( V_60 -> V_62 . type == V_51 &&
V_60 -> V_62 . V_15 >= V_63 )
V_60 -> V_62 . V_15 = 0 ;
} else {
memset ( & V_60 -> V_62 , 0 , sizeof( V_60 -> V_62 ) ) ;
}
V_60 -> V_64 = NULL ;
V_60 -> V_58 = V_58 ;
V_60 -> V_27 = V_27 ;
V_60 -> V_16 = V_16 ;
V_60 -> V_46 = V_46 ;
F_35 ( & V_60 -> V_65 , V_57 ) ;
return 0 ;
}
static int F_36 ( struct V_66 * V_67 , struct V_68 * V_69 ,
struct V_70 * V_71 , struct V_54 * V_60 ,
int V_58 , T_1 V_72 , const T_1 * V_37 ,
T_1 V_73 )
{
int V_21 = 0 ;
int V_48 ;
struct V_33 * V_34 ;
struct V_31 V_32 ;
struct V_31 * V_62 = & V_60 -> V_62 ;
struct V_35 * V_36 ;
struct V_38 * V_39 = NULL , * V_74 = NULL ;
T_1 V_47 ;
T_1 V_46 = V_60 -> V_46 ;
T_1 V_27 = 0 ;
if ( V_58 != 0 ) {
V_34 = V_69 -> V_75 [ V_58 ] ;
V_21 = F_37 ( V_71 , V_34 -> V_76 , 0 , V_3 ) ;
if ( V_21 < 0 )
return V_21 ;
return 0 ;
}
if ( V_69 -> V_77 [ 0 ] >= F_24 ( V_69 -> V_75 [ 0 ] ) ) {
if ( V_72 == V_78 )
V_21 = F_38 ( V_67 , V_69 ) ;
else
V_21 = F_39 ( V_67 , V_69 , V_72 ) ;
}
while ( ! V_21 && V_27 < V_73 ) {
V_34 = V_69 -> V_75 [ 0 ] ;
V_48 = V_69 -> V_77 [ 0 ] ;
F_25 ( V_34 , & V_32 , V_48 ) ;
if ( V_32 . V_44 != V_62 -> V_44 ||
V_32 . type != V_51 )
break;
V_36 = F_26 ( V_34 , V_48 , struct V_35 ) ;
V_47 = F_28 ( V_34 , V_36 ) ;
if ( V_47 == V_46 ) {
V_39 = NULL ;
V_74 = NULL ;
V_27 ++ ;
if ( V_37 ) {
V_21 = F_16 ( & V_32 , V_34 , V_36 ,
* V_37 ,
& V_39 ) ;
if ( V_21 < 0 )
break;
}
if ( V_21 > 0 )
goto V_10;
V_21 = F_40 ( V_71 , V_34 -> V_76 ,
V_39 , ( void * * ) & V_74 , V_3 ) ;
if ( V_21 < 0 )
break;
if ( ! V_21 && V_37 ) {
while ( V_74 -> V_10 )
V_74 = V_74 -> V_10 ;
V_74 -> V_10 = V_39 ;
}
V_39 = NULL ;
}
V_10:
if ( V_72 == V_78 )
V_21 = F_41 ( V_67 , V_69 ) ;
else
V_21 = F_42 ( V_67 , V_69 , V_72 ) ;
}
if ( V_21 > 0 )
V_21 = 0 ;
else if ( V_21 < 0 )
F_22 ( V_39 ) ;
return V_21 ;
}
static int F_43 ( struct V_79 * V_80 ,
struct V_68 * V_69 , T_1 V_72 ,
struct V_54 * V_60 ,
struct V_70 * V_71 ,
const T_1 * V_37 , T_1 V_73 )
{
struct V_66 * V_67 ;
struct V_31 V_81 ;
struct V_33 * V_34 ;
int V_21 = 0 ;
int V_82 ;
int V_58 = V_60 -> V_58 ;
int V_83 ;
V_81 . V_44 = V_60 -> V_13 ;
V_81 . type = V_84 ;
V_81 . V_15 = ( T_1 ) - 1 ;
V_83 = F_44 ( & V_80 -> V_85 ) ;
V_67 = F_45 ( V_80 , & V_81 , false ) ;
if ( F_46 ( V_67 ) ) {
F_47 ( & V_80 -> V_85 , V_83 ) ;
V_21 = F_48 ( V_67 ) ;
goto V_86;
}
if ( F_49 ( V_80 ) ) {
F_47 ( & V_80 -> V_85 , V_83 ) ;
V_21 = - V_87 ;
goto V_86;
}
if ( V_69 -> V_88 )
V_82 = F_50 ( V_67 -> V_89 ) ;
else if ( V_72 == V_78 )
V_82 = F_50 ( V_67 -> V_8 ) ;
else
V_82 = F_51 ( V_67 , V_72 ) ;
if ( V_82 + 1 == V_58 ) {
F_47 ( & V_80 -> V_85 , V_83 ) ;
goto V_86;
}
V_69 -> V_90 = V_58 ;
if ( V_72 == V_78 )
V_21 = F_52 ( NULL , V_67 , & V_60 -> V_62 , V_69 ,
0 , 0 ) ;
else
V_21 = F_53 ( V_67 , & V_60 -> V_62 , V_69 ,
V_72 ) ;
F_47 ( & V_80 -> V_85 , V_83 ) ;
F_54 ( V_80 ,
L_2 ,
V_60 -> V_13 , V_58 , V_60 -> V_27 , V_21 ,
V_60 -> V_62 . V_44 , V_60 -> V_62 . type ,
V_60 -> V_62 . V_15 ) ;
if ( V_21 < 0 )
goto V_86;
V_34 = V_69 -> V_75 [ V_58 ] ;
while ( ! V_34 ) {
if ( F_55 ( ! V_58 ) ) {
V_21 = 1 ;
goto V_86;
}
V_58 -- ;
V_34 = V_69 -> V_75 [ V_58 ] ;
}
V_21 = F_36 ( V_67 , V_69 , V_71 , V_60 , V_58 , V_72 ,
V_37 , V_73 ) ;
V_86:
V_69 -> V_90 = 0 ;
F_56 ( V_69 ) ;
return V_21 ;
}
static int F_57 ( struct V_79 * V_80 ,
struct V_68 * V_69 , T_1 V_72 ,
struct V_56 * V_57 ,
const T_1 * V_37 , T_1 V_73 ,
T_1 V_91 )
{
int V_92 ;
int V_21 = 0 ;
struct V_54 * V_60 ;
struct V_54 * V_93 ;
struct V_54 * V_94 ;
struct V_70 * V_71 ;
struct V_95 * V_8 ;
struct V_96 V_97 ;
V_71 = F_58 ( V_3 ) ;
if ( ! V_71 )
return - V_29 ;
F_59 (ref, ref_safe, head, list) {
if ( V_60 -> V_16 )
continue;
if ( V_60 -> V_27 == 0 )
continue;
if ( V_91 && V_60 -> V_13 != V_91 ) {
V_21 = V_98 ;
goto V_86;
}
V_92 = F_43 ( V_80 , V_69 , V_72 , V_60 ,
V_71 , V_37 ,
V_73 ) ;
if ( V_92 == - V_87 ) {
continue;
} else if ( V_92 ) {
V_21 = V_92 ;
goto V_86;
}
F_60 ( & V_97 ) ;
V_8 = F_61 ( V_71 , & V_97 ) ;
V_60 -> V_16 = V_8 ? V_8 -> V_99 : 0 ;
V_60 -> V_64 = V_8 ?
(struct V_38 * ) ( V_100 ) V_8 -> V_101 : NULL ;
while ( ( V_8 = F_61 ( V_71 , & V_97 ) ) ) {
V_94 = F_34 ( V_53 ,
V_3 ) ;
if ( ! V_94 ) {
V_21 = - V_29 ;
goto V_86;
}
memcpy ( V_94 , V_60 , sizeof( * V_60 ) ) ;
V_94 -> V_16 = V_8 -> V_99 ;
V_94 -> V_64 = (struct V_38 * )
( V_100 ) V_8 -> V_101 ;
F_62 ( & V_94 -> V_65 , & V_60 -> V_65 ) ;
}
F_63 ( V_71 ) ;
}
V_86:
F_64 ( V_71 ) ;
return V_21 ;
}
static inline int F_65 ( struct V_54 * V_102 ,
struct V_54 * V_103 )
{
if ( V_102 -> V_58 != V_103 -> V_58 )
return 0 ;
if ( V_102 -> V_13 != V_103 -> V_13 )
return 0 ;
if ( V_102 -> V_62 . type != V_103 -> V_62 . type )
return 0 ;
if ( V_102 -> V_62 . V_44 != V_103 -> V_62 . V_44 )
return 0 ;
if ( V_102 -> V_62 . V_15 != V_103 -> V_62 . V_15 )
return 0 ;
if ( V_102 -> V_16 != V_103 -> V_16 )
return 0 ;
return 1 ;
}
static int F_66 ( struct V_79 * V_80 ,
struct V_56 * V_57 )
{
struct V_54 * V_60 ;
struct V_33 * V_34 ;
F_67 (ref, head, list) {
if ( V_60 -> V_16 )
continue;
if ( V_60 -> V_62 . type )
continue;
F_68 ( ! V_60 -> V_46 ) ;
V_34 = F_69 ( V_80 , V_60 -> V_46 , 0 ) ;
if ( F_46 ( V_34 ) ) {
return F_48 ( V_34 ) ;
} else if ( ! F_70 ( V_34 ) ) {
F_71 ( V_34 ) ;
return - V_104 ;
}
F_72 ( V_34 ) ;
if ( F_50 ( V_34 ) == 0 )
F_25 ( V_34 , & V_60 -> V_62 , 0 ) ;
else
F_73 ( V_34 , & V_60 -> V_62 , 0 ) ;
F_74 ( V_34 ) ;
F_71 ( V_34 ) ;
}
return 0 ;
}
static void F_75 ( struct V_56 * V_57 , enum V_105 V_106 )
{
struct V_54 * V_107 ;
F_67 (pos1, head, list) {
struct V_54 * V_108 = V_107 , * V_109 ;
F_76 (pos2, tmp, head, list) {
struct V_54 * V_102 = V_107 , * V_103 = V_108 ;
struct V_38 * V_39 ;
if ( ! F_65 ( V_102 , V_103 ) )
continue;
if ( V_106 == V_110 ) {
if ( ! V_102 -> V_16 && V_103 -> V_16 )
F_77 ( V_102 , V_103 ) ;
} else {
if ( V_102 -> V_16 != V_103 -> V_16 )
continue;
}
V_39 = V_102 -> V_64 ;
while ( V_39 && V_39 -> V_10 )
V_39 = V_39 -> V_10 ;
if ( V_39 )
V_39 -> V_10 = V_103 -> V_64 ;
else
V_102 -> V_64 = V_103 -> V_64 ;
V_102 -> V_27 += V_103 -> V_27 ;
F_78 ( & V_103 -> V_65 ) ;
F_79 ( V_53 , V_103 ) ;
F_80 () ;
}
}
}
static int F_81 ( struct V_111 * V_57 , T_1 V_112 ,
struct V_56 * V_113 , T_1 * V_73 ,
T_1 V_43 )
{
struct V_114 * V_8 ;
struct V_115 * V_116 = V_57 -> V_116 ;
struct V_31 V_32 ;
struct V_31 V_117 = { 0 } ;
int V_118 ;
int V_21 = 0 ;
if ( V_116 && V_116 -> V_119 )
F_82 ( & V_117 , & V_116 -> V_32 ) ;
F_83 ( & V_57 -> V_120 ) ;
F_67 (node, &head->ref_list, list) {
if ( V_8 -> V_112 > V_112 )
continue;
switch ( V_8 -> V_121 ) {
case V_122 :
case V_123 :
F_55 ( 1 ) ;
continue;
case V_124 :
V_118 = 1 ;
break;
case V_125 :
V_118 = - 1 ;
break;
default:
F_68 ( 1 ) ;
}
* V_73 += ( V_8 -> V_30 * V_118 ) ;
switch ( V_8 -> type ) {
case V_126 : {
struct V_127 * V_60 ;
V_60 = F_84 ( V_8 ) ;
V_21 = F_33 ( V_113 , V_60 -> V_67 , & V_117 ,
V_60 -> V_58 + 1 , 0 , V_8 -> V_128 ,
V_8 -> V_30 * V_118 , V_129 ) ;
break;
}
case V_130 : {
struct V_127 * V_60 ;
V_60 = F_84 ( V_8 ) ;
V_21 = F_33 ( V_113 , 0 , NULL ,
V_60 -> V_58 + 1 , V_60 -> V_16 ,
V_8 -> V_128 ,
V_8 -> V_30 * V_118 , V_129 ) ;
break;
}
case V_131 : {
struct V_132 * V_60 ;
V_60 = F_85 ( V_8 ) ;
V_32 . V_44 = V_60 -> V_44 ;
V_32 . type = V_51 ;
V_32 . V_15 = V_60 -> V_15 ;
if ( V_43 && V_60 -> V_44 != V_43 ) {
V_21 = V_98 ;
break;
}
V_21 = F_33 ( V_113 , V_60 -> V_67 , & V_32 , 0 , 0 ,
V_8 -> V_128 ,
V_8 -> V_30 * V_118 , V_129 ) ;
break;
}
case V_133 : {
struct V_132 * V_60 ;
V_60 = F_85 ( V_8 ) ;
V_21 = F_33 ( V_113 , 0 , NULL , 0 ,
V_60 -> V_16 , V_8 -> V_128 ,
V_8 -> V_30 * V_118 , V_129 ) ;
break;
}
default:
F_55 ( 1 ) ;
}
if ( V_21 )
break;
}
F_86 ( & V_57 -> V_120 ) ;
return V_21 ;
}
static int F_87 ( struct V_68 * V_69 , T_1 V_128 ,
int * V_134 , struct V_56 * V_113 ,
struct V_1 * V_2 ,
T_1 * V_73 , T_1 V_43 )
{
int V_21 = 0 ;
int V_48 ;
struct V_33 * V_135 ;
struct V_31 V_32 ;
struct V_31 V_136 ;
unsigned long V_137 ;
unsigned long V_138 ;
struct V_139 * V_140 ;
T_1 V_141 ;
T_1 V_142 ;
V_135 = V_69 -> V_75 [ 0 ] ;
V_48 = V_69 -> V_77 [ 0 ] ;
V_142 = F_88 ( V_135 , V_48 ) ;
F_68 ( V_142 < sizeof( * V_140 ) ) ;
V_140 = F_26 ( V_135 , V_48 , struct V_139 ) ;
V_141 = F_89 ( V_135 , V_140 ) ;
* V_73 += F_90 ( V_135 , V_140 ) ;
F_25 ( V_135 , & V_136 , V_48 ) ;
V_137 = ( unsigned long ) ( V_140 + 1 ) ;
V_138 = ( unsigned long ) V_140 + V_142 ;
if ( V_136 . type == V_143 &&
V_141 & V_144 ) {
struct V_145 * V_146 ;
V_146 = (struct V_145 * ) V_137 ;
* V_134 = F_91 ( V_135 , V_146 ) ;
V_137 += sizeof( struct V_145 ) ;
F_68 ( V_137 > V_138 ) ;
} else if ( V_136 . type == V_147 ) {
* V_134 = V_136 . V_15 ;
} else {
F_68 ( ! ( V_141 & V_148 ) ) ;
}
while ( V_137 < V_138 ) {
struct V_149 * V_150 ;
T_1 V_15 ;
int type ;
V_150 = (struct V_149 * ) V_137 ;
type = F_92 ( V_135 , V_150 ) ;
V_15 = F_93 ( V_135 , V_150 ) ;
switch ( type ) {
case V_130 :
V_21 = F_33 ( V_113 , 0 , NULL ,
* V_134 + 1 , V_15 ,
V_128 , 1 , V_3 ) ;
break;
case V_133 : {
struct V_151 * V_152 ;
int V_27 ;
V_152 = (struct V_151 * ) ( V_150 + 1 ) ;
V_27 = F_94 ( V_135 , V_152 ) ;
V_21 = F_33 ( V_113 , 0 , NULL , 0 , V_15 ,
V_128 , V_27 , V_3 ) ;
if ( V_2 ) {
if ( ! V_21 )
V_21 = F_15 ( V_2 , 0 , 0 , 0 ,
V_128 , V_27 ) ;
if ( ! V_21 && V_2 -> V_6 > 1 )
V_21 = V_98 ;
}
break;
}
case V_126 :
V_21 = F_33 ( V_113 , V_15 , NULL ,
* V_134 + 1 , 0 ,
V_128 , 1 , V_3 ) ;
break;
case V_131 : {
struct V_153 * V_154 ;
int V_27 ;
T_1 V_67 ;
V_154 = (struct V_153 * ) ( & V_150 -> V_15 ) ;
V_27 = F_95 ( V_135 , V_154 ) ;
V_32 . V_44 = F_96 ( V_135 ,
V_154 ) ;
V_32 . type = V_51 ;
V_32 . V_15 = F_97 ( V_135 , V_154 ) ;
if ( V_43 && V_32 . V_44 != V_43 ) {
V_21 = V_98 ;
break;
}
V_67 = F_98 ( V_135 , V_154 ) ;
V_21 = F_33 ( V_113 , V_67 , & V_32 , 0 , 0 ,
V_128 , V_27 , V_3 ) ;
if ( V_2 ) {
if ( ! V_21 )
V_21 = F_15 ( V_2 , V_67 ,
V_32 . V_44 ,
V_32 . V_15 , 0 ,
V_27 ) ;
if ( ! V_21 && V_2 -> V_6 > 1 )
V_21 = V_98 ;
}
break;
}
default:
F_55 ( 1 ) ;
}
if ( V_21 )
return V_21 ;
V_137 += F_99 ( type ) ;
}
return 0 ;
}
static int F_100 ( struct V_79 * V_80 ,
struct V_68 * V_69 , T_1 V_128 ,
int V_134 , struct V_56 * V_113 ,
struct V_1 * V_2 , T_1 V_43 )
{
struct V_66 * V_155 = V_80 -> V_155 ;
int V_21 ;
int V_48 ;
struct V_33 * V_135 ;
struct V_31 V_32 ;
while ( 1 ) {
V_21 = F_41 ( V_155 , V_69 ) ;
if ( V_21 < 0 )
break;
if ( V_21 ) {
V_21 = 0 ;
break;
}
V_48 = V_69 -> V_77 [ 0 ] ;
V_135 = V_69 -> V_75 [ 0 ] ;
F_25 ( V_135 , & V_32 , V_48 ) ;
if ( V_32 . V_44 != V_128 )
break;
if ( V_32 . type < V_126 )
continue;
if ( V_32 . type > V_133 )
break;
switch ( V_32 . type ) {
case V_130 :
V_21 = F_33 ( V_113 , 0 , NULL ,
V_134 + 1 , V_32 . V_15 ,
V_128 , 1 , V_3 ) ;
break;
case V_133 : {
struct V_151 * V_152 ;
int V_27 ;
V_152 = F_26 ( V_135 , V_48 ,
struct V_151 ) ;
V_27 = F_94 ( V_135 , V_152 ) ;
V_21 = F_33 ( V_113 , 0 , NULL , 0 , V_32 . V_15 ,
V_128 , V_27 , V_3 ) ;
if ( V_2 ) {
if ( ! V_21 )
V_21 = F_15 ( V_2 , 0 , 0 , 0 ,
V_128 , V_27 ) ;
if ( ! V_21 && V_2 -> V_6 > 1 )
V_21 = V_98 ;
}
break;
}
case V_126 :
V_21 = F_33 ( V_113 , V_32 . V_15 , NULL ,
V_134 + 1 , 0 ,
V_128 , 1 , V_3 ) ;
break;
case V_131 : {
struct V_153 * V_154 ;
int V_27 ;
T_1 V_67 ;
V_154 = F_26 ( V_135 , V_48 ,
struct V_153 ) ;
V_27 = F_95 ( V_135 , V_154 ) ;
V_32 . V_44 = F_96 ( V_135 ,
V_154 ) ;
V_32 . type = V_51 ;
V_32 . V_15 = F_97 ( V_135 , V_154 ) ;
if ( V_43 && V_32 . V_44 != V_43 ) {
V_21 = V_98 ;
break;
}
V_67 = F_98 ( V_135 , V_154 ) ;
V_21 = F_33 ( V_113 , V_67 , & V_32 , 0 , 0 ,
V_128 , V_27 , V_3 ) ;
if ( V_2 ) {
if ( ! V_21 )
V_21 = F_15 ( V_2 , V_67 ,
V_32 . V_44 ,
V_32 . V_15 , 0 ,
V_27 ) ;
if ( ! V_21 && V_2 -> V_6 > 1 )
V_21 = V_98 ;
}
break;
}
default:
F_55 ( 1 ) ;
}
if ( V_21 )
return V_21 ;
}
return V_21 ;
}
static void F_101 ( struct V_70 * V_156 )
{
struct V_95 * V_8 = NULL ;
struct V_38 * V_39 ;
struct V_96 V_97 ;
F_60 ( & V_97 ) ;
while ( ( V_8 = F_61 ( V_156 , & V_97 ) ) ) {
if ( ! V_8 -> V_101 )
continue;
V_39 = (struct V_38 * ) ( V_100 ) V_8 -> V_101 ;
F_22 ( V_39 ) ;
V_8 -> V_101 = 0 ;
}
F_64 ( V_156 ) ;
}
static int F_102 ( struct V_157 * V_158 ,
struct V_79 * V_80 , T_1 V_128 ,
T_1 V_72 , struct V_70 * * V_159 ,
const T_1 * V_37 )
{
int V_21 ;
* V_159 = F_58 ( V_3 ) ;
if ( ! * V_159 )
return - V_29 ;
V_21 = F_103 ( V_158 , V_80 , V_128 , V_72 ,
* V_159 , NULL , V_37 , 0 , 0 , 0 ) ;
if ( V_21 < 0 && V_21 != - V_87 ) {
F_101 ( * V_159 ) ;
return V_21 ;
}
return 0 ;
}
static int F_104 ( struct V_157 * V_158 ,
struct V_79 * V_80 , T_1 V_128 ,
T_1 V_72 , struct V_70 * * V_160 )
{
struct V_70 * V_109 ;
struct V_95 * V_8 = NULL ;
struct V_96 V_97 ;
int V_21 ;
V_109 = F_58 ( V_3 ) ;
if ( ! V_109 )
return - V_29 ;
* V_160 = F_58 ( V_3 ) ;
if ( ! * V_160 ) {
F_64 ( V_109 ) ;
return - V_29 ;
}
F_60 ( & V_97 ) ;
while ( 1 ) {
V_21 = F_103 ( V_158 , V_80 , V_128 , V_72 ,
V_109 , * V_160 , NULL , 0 , 0 , 0 ) ;
if ( V_21 < 0 && V_21 != - V_87 ) {
F_64 ( V_109 ) ;
F_64 ( * V_160 ) ;
return V_21 ;
}
V_8 = F_61 ( V_109 , & V_97 ) ;
if ( ! V_8 )
break;
V_128 = V_8 -> V_99 ;
F_80 () ;
}
F_64 ( V_109 ) ;
return 0 ;
}
int F_105 ( struct V_157 * V_158 ,
struct V_79 * V_80 , T_1 V_128 ,
T_1 V_72 , struct V_70 * * V_160 )
{
int V_21 ;
if ( ! V_158 )
F_106 ( & V_80 -> V_161 ) ;
V_21 = F_104 ( V_158 , V_80 , V_128 , V_72 , V_160 ) ;
if ( ! V_158 )
F_107 ( & V_80 -> V_161 ) ;
return V_21 ;
}
int F_108 ( struct V_157 * V_158 ,
struct V_79 * V_80 , T_1 V_91 ,
T_1 V_43 , T_1 V_128 )
{
struct V_70 * V_109 = NULL ;
struct V_70 * V_160 = NULL ;
struct V_96 V_97 ;
struct V_95 * V_8 ;
struct V_162 V_163 = F_109 ( V_163 ) ;
int V_21 = 0 ;
V_109 = F_58 ( V_3 ) ;
V_160 = F_58 ( V_3 ) ;
if ( ! V_109 || ! V_160 ) {
F_64 ( V_109 ) ;
F_64 ( V_160 ) ;
return - V_29 ;
}
if ( V_158 )
F_110 ( V_80 , & V_163 ) ;
else
F_106 ( & V_80 -> V_161 ) ;
F_60 ( & V_97 ) ;
while ( 1 ) {
V_21 = F_103 ( V_158 , V_80 , V_128 , V_163 . V_112 , V_109 ,
V_160 , NULL , V_91 , V_43 , 1 ) ;
if ( V_21 == V_98 ) {
V_21 = 1 ;
break;
}
if ( V_21 < 0 && V_21 != - V_87 )
break;
V_21 = 0 ;
V_8 = F_61 ( V_109 , & V_97 ) ;
if ( ! V_8 )
break;
V_128 = V_8 -> V_99 ;
F_80 () ;
}
if ( V_158 )
F_111 ( V_80 , & V_163 ) ;
else
F_107 ( & V_80 -> V_161 ) ;
F_64 ( V_109 ) ;
F_64 ( V_160 ) ;
return V_21 ;
}
int F_112 ( struct V_66 * V_67 , T_1 V_164 ,
T_1 V_165 , struct V_68 * V_69 ,
struct V_166 * * V_167 ,
T_1 * V_168 )
{
int V_21 , V_48 ;
struct V_31 V_32 ;
struct V_31 V_136 ;
struct V_166 * V_169 ;
struct V_33 * V_135 ;
unsigned long V_137 ;
V_32 . V_44 = V_164 ;
V_32 . type = V_170 ;
V_32 . V_15 = V_165 ;
V_21 = F_52 ( NULL , V_67 , & V_32 , V_69 , 0 , 0 ) ;
if ( V_21 < 0 )
return V_21 ;
while ( 1 ) {
V_135 = V_69 -> V_75 [ 0 ] ;
V_48 = V_69 -> V_77 [ 0 ] ;
if ( V_48 >= F_24 ( V_135 ) ) {
V_21 = F_38 ( V_67 , V_69 ) ;
if ( V_21 ) {
if ( V_21 >= 1 )
V_21 = - V_87 ;
break;
}
continue;
}
F_25 ( V_135 , & V_136 , V_48 ) ;
V_21 = - V_87 ;
if ( V_136 . V_44 != V_164 )
break;
if ( V_136 . type != V_170 )
break;
V_21 = 0 ;
V_137 = F_113 ( V_135 , V_69 -> V_77 [ 0 ] ) ;
V_169 = (struct V_166 * ) V_137 ;
* V_167 = V_169 ;
if ( V_168 )
* V_168 = V_136 . V_15 ;
break;
}
return V_21 ;
}
char * F_114 ( struct V_66 * V_171 , struct V_68 * V_69 ,
T_4 V_172 , unsigned long V_173 ,
struct V_33 * V_174 , T_1 V_16 ,
char * V_175 , T_4 V_176 )
{
int V_48 ;
T_1 V_177 ;
int V_21 ;
T_5 V_178 = ( ( T_5 ) V_176 ) - 1 ;
struct V_33 * V_34 = V_174 ;
struct V_31 V_136 ;
int V_179 = V_69 -> V_179 ;
struct V_180 * V_150 ;
if ( V_178 >= 0 )
V_175 [ V_178 ] = '\0' ;
V_69 -> V_179 = 1 ;
while ( 1 ) {
V_178 -= V_172 ;
if ( V_178 >= 0 )
F_115 ( V_34 , V_175 + V_178 ,
V_173 , V_172 ) ;
if ( V_34 != V_174 ) {
if ( ! V_69 -> V_181 )
F_116 ( V_34 ) ;
F_71 ( V_34 ) ;
}
V_21 = F_117 ( V_171 , V_69 , V_16 , 0 ,
V_182 , & V_136 ) ;
if ( V_21 > 0 )
V_21 = - V_87 ;
if ( V_21 )
break;
V_177 = V_136 . V_15 ;
if ( V_16 == V_177 )
break;
V_48 = V_69 -> V_77 [ 0 ] ;
V_34 = V_69 -> V_75 [ 0 ] ;
if ( V_34 != V_174 ) {
if ( ! V_69 -> V_181 )
F_118 ( V_34 , V_183 ) ;
V_69 -> V_75 [ 0 ] = NULL ;
V_69 -> V_184 [ 0 ] = 0 ;
}
F_56 ( V_69 ) ;
V_150 = F_26 ( V_34 , V_48 , struct V_180 ) ;
V_172 = F_119 ( V_34 , V_150 ) ;
V_173 = ( unsigned long ) ( V_150 + 1 ) ;
V_16 = V_177 ;
-- V_178 ;
if ( V_178 >= 0 )
V_175 [ V_178 ] = '/' ;
}
F_56 ( V_69 ) ;
V_69 -> V_179 = V_179 ;
if ( V_21 )
return F_120 ( V_21 ) ;
return V_175 + V_178 ;
}
int F_121 ( struct V_79 * V_80 , T_1 V_185 ,
struct V_68 * V_69 , struct V_31 * V_136 ,
T_1 * V_186 )
{
int V_21 ;
T_1 V_141 ;
T_1 V_176 = 0 ;
T_4 V_142 ;
struct V_33 * V_34 ;
struct V_139 * V_140 ;
struct V_31 V_32 ;
if ( F_122 ( V_80 , V_187 ) )
V_32 . type = V_147 ;
else
V_32 . type = V_143 ;
V_32 . V_44 = V_185 ;
V_32 . V_15 = ( T_1 ) - 1 ;
V_21 = F_52 ( NULL , V_80 -> V_155 , & V_32 , V_69 , 0 , 0 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_123 ( V_80 -> V_155 , V_69 , 0 ) ;
if ( V_21 ) {
if ( V_21 > 0 )
V_21 = - V_87 ;
return V_21 ;
}
F_25 ( V_69 -> V_75 [ 0 ] , V_136 , V_69 -> V_77 [ 0 ] ) ;
if ( V_136 -> type == V_147 )
V_176 = V_80 -> V_188 ;
else if ( V_136 -> type == V_143 )
V_176 = V_136 -> V_15 ;
if ( V_136 -> V_44 > V_185 ||
V_136 -> V_44 + V_176 <= V_185 ) {
F_54 ( V_80 ,
L_3 , V_185 ) ;
return - V_87 ;
}
V_34 = V_69 -> V_75 [ 0 ] ;
V_142 = F_88 ( V_34 , V_69 -> V_77 [ 0 ] ) ;
F_68 ( V_142 < sizeof( * V_140 ) ) ;
V_140 = F_26 ( V_34 , V_69 -> V_77 [ 0 ] , struct V_139 ) ;
V_141 = F_89 ( V_34 , V_140 ) ;
F_54 ( V_80 ,
L_4 ,
V_185 , V_185 - V_136 -> V_44 , V_136 -> V_44 ,
V_136 -> V_15 , V_141 , V_142 ) ;
F_55 ( ! V_186 ) ;
if ( V_186 ) {
if ( V_141 & V_144 )
* V_186 = V_144 ;
else if ( V_141 & V_148 )
* V_186 = V_148 ;
else
F_68 ( 1 ) ;
return 0 ;
}
return - V_104 ;
}
static int F_124 ( unsigned long * V_137 , struct V_33 * V_34 ,
struct V_31 * V_32 ,
struct V_139 * V_140 , T_4 V_142 ,
struct V_149 * * V_189 ,
int * V_190 )
{
unsigned long V_138 ;
T_1 V_141 ;
struct V_145 * V_146 ;
if ( ! * V_137 ) {
V_141 = F_89 ( V_34 , V_140 ) ;
if ( V_141 & V_144 ) {
if ( V_32 -> type == V_147 ) {
* V_189 =
(struct V_149 * ) ( V_140 + 1 ) ;
} else {
F_55 ( V_32 -> type != V_143 ) ;
V_146 = (struct V_145 * ) ( V_140 + 1 ) ;
* V_189 =
(struct V_149 * ) ( V_146 + 1 ) ;
}
} else {
* V_189 = (struct V_149 * ) ( V_140 + 1 ) ;
}
* V_137 = ( unsigned long ) * V_189 ;
if ( ( unsigned long ) ( * V_137 ) >= ( unsigned long ) V_140 + V_142 )
return - V_87 ;
}
V_138 = ( unsigned long ) V_140 + V_142 ;
* V_189 = (struct V_149 * ) ( * V_137 ) ;
* V_190 = F_92 ( V_34 , * V_189 ) ;
* V_137 += F_99 ( * V_190 ) ;
F_55 ( * V_137 > V_138 ) ;
if ( * V_137 == V_138 )
return 1 ;
return 0 ;
}
int F_125 ( unsigned long * V_137 , struct V_33 * V_34 ,
struct V_31 * V_32 , struct V_139 * V_140 ,
T_4 V_142 , T_1 * V_191 , T_6 * V_192 )
{
int V_21 ;
int type ;
struct V_149 * V_193 ;
if ( * V_137 == ( unsigned long ) - 1 )
return 1 ;
while ( 1 ) {
V_21 = F_124 ( V_137 , V_34 , V_32 , V_140 , V_142 ,
& V_193 , & type ) ;
if ( V_21 < 0 )
return V_21 ;
if ( type == V_126 ||
type == V_130 )
break;
if ( V_21 == 1 )
return 1 ;
}
* V_191 = F_93 ( V_34 , V_193 ) ;
if ( V_32 -> type == V_143 ) {
struct V_145 * V_146 ;
V_146 = (struct V_145 * ) ( V_140 + 1 ) ;
* V_192 = F_91 ( V_34 , V_146 ) ;
} else {
ASSERT ( V_32 -> type == V_147 ) ;
* V_192 = ( T_6 ) V_32 -> V_15 ;
}
if ( V_21 == 1 )
* V_137 = ( unsigned long ) - 1 ;
return 0 ;
}
static int F_126 ( struct V_79 * V_80 ,
struct V_38 * V_64 ,
T_1 V_67 , T_1 V_194 ,
T_7 * V_195 , void * V_196 )
{
struct V_38 * V_39 ;
int V_21 = 0 ;
for ( V_39 = V_64 ; V_39 ; V_39 = V_39 -> V_10 ) {
F_54 ( V_80 ,
L_5 ,
V_194 , V_39 -> V_43 ,
V_39 -> V_15 , V_67 ) ;
V_21 = V_195 ( V_39 -> V_43 , V_39 -> V_15 , V_67 , V_196 ) ;
if ( V_21 ) {
F_54 ( V_80 ,
L_6 ,
V_194 , V_21 ) ;
break;
}
}
return V_21 ;
}
int F_127 ( struct V_79 * V_80 ,
T_1 V_194 , T_1 V_37 ,
int V_88 ,
T_7 * V_195 , void * V_196 )
{
int V_21 ;
struct V_157 * V_158 = NULL ;
struct V_70 * V_197 = NULL ;
struct V_70 * V_160 = NULL ;
struct V_95 * V_7 = NULL ;
struct V_95 * V_198 = NULL ;
struct V_162 V_199 = F_109 ( V_199 ) ;
struct V_96 V_200 ;
struct V_96 V_201 ;
F_54 ( V_80 , L_7 ,
V_194 ) ;
if ( ! V_88 ) {
V_158 = F_128 ( V_80 -> V_155 ) ;
if ( F_46 ( V_158 ) )
return F_48 ( V_158 ) ;
F_110 ( V_80 , & V_199 ) ;
} else {
F_106 ( & V_80 -> V_161 ) ;
}
V_21 = F_102 ( V_158 , V_80 , V_194 ,
V_199 . V_112 , & V_197 ,
& V_37 ) ;
if ( V_21 )
goto V_86;
F_60 ( & V_200 ) ;
while ( ! V_21 && ( V_7 = F_61 ( V_197 , & V_200 ) ) ) {
V_21 = F_104 ( V_158 , V_80 , V_7 -> V_99 ,
V_199 . V_112 , & V_160 ) ;
if ( V_21 )
break;
F_60 ( & V_201 ) ;
while ( ! V_21 && ( V_198 = F_61 ( V_160 , & V_201 ) ) ) {
F_54 ( V_80 ,
L_8 ,
V_198 -> V_99 , V_7 -> V_99 ,
V_7 -> V_101 ) ;
V_21 = F_126 ( V_80 ,
(struct V_38 * )
( V_100 ) V_7 -> V_101 ,
V_198 -> V_99 ,
V_194 ,
V_195 , V_196 ) ;
}
F_64 ( V_160 ) ;
}
F_101 ( V_197 ) ;
V_86:
if ( ! V_88 ) {
F_111 ( V_80 , & V_199 ) ;
F_129 ( V_158 ) ;
} else {
F_107 ( & V_80 -> V_161 ) ;
}
return V_21 ;
}
int F_130 ( T_1 V_185 , struct V_79 * V_80 ,
struct V_68 * V_69 ,
T_7 * V_195 , void * V_196 )
{
int V_21 ;
T_1 V_37 ;
T_1 V_141 = 0 ;
struct V_31 V_136 ;
int V_88 = V_69 -> V_88 ;
V_21 = F_121 ( V_80 , V_185 , V_69 , & V_136 , & V_141 ) ;
F_56 ( V_69 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_141 & V_144 )
return - V_202 ;
V_37 = V_185 - V_136 . V_44 ;
V_21 = F_127 ( V_80 , V_136 . V_44 ,
V_37 , V_88 ,
V_195 , V_196 ) ;
return V_21 ;
}
static int F_131 ( T_1 V_43 , struct V_66 * V_171 ,
struct V_68 * V_69 ,
T_8 * V_195 , void * V_196 )
{
int V_21 = 0 ;
int V_48 ;
T_4 V_19 ;
T_4 V_203 ;
T_4 V_172 ;
T_1 V_16 = 0 ;
int V_204 = 0 ;
struct V_33 * V_34 ;
struct V_205 * V_206 ;
struct V_180 * V_150 ;
struct V_31 V_136 ;
while ( ! V_21 ) {
V_21 = F_117 ( V_171 , V_69 , V_43 ,
V_16 ? V_16 + 1 : 0 , V_182 ,
& V_136 ) ;
if ( V_21 < 0 )
break;
if ( V_21 ) {
V_21 = V_204 ? 0 : - V_87 ;
break;
}
++ V_204 ;
V_16 = V_136 . V_15 ;
V_48 = V_69 -> V_77 [ 0 ] ;
V_34 = F_132 ( V_69 -> V_75 [ 0 ] ) ;
if ( ! V_34 ) {
V_21 = - V_29 ;
break;
}
F_133 ( V_34 ) ;
F_72 ( V_34 ) ;
F_118 ( V_34 , V_183 ) ;
F_56 ( V_69 ) ;
V_206 = F_134 ( V_48 ) ;
V_150 = F_26 ( V_34 , V_48 , struct V_180 ) ;
for ( V_19 = 0 ; V_19 < F_135 ( V_34 , V_206 ) ; V_19 += V_203 ) {
V_172 = F_119 ( V_34 , V_150 ) ;
F_54 ( V_171 -> V_80 ,
L_9 ,
V_19 , V_136 . V_44 , V_171 -> V_44 ) ;
V_21 = V_195 ( V_16 , V_172 ,
( unsigned long ) ( V_150 + 1 ) , V_34 , V_196 ) ;
if ( V_21 )
break;
V_203 = sizeof( * V_150 ) + V_172 ;
V_150 = (struct V_180 * ) ( ( char * ) V_150 + V_203 ) ;
}
F_116 ( V_34 ) ;
F_71 ( V_34 ) ;
}
F_56 ( V_69 ) ;
return V_21 ;
}
static int F_136 ( T_1 V_43 , struct V_66 * V_171 ,
struct V_68 * V_69 ,
T_8 * V_195 , void * V_196 )
{
int V_21 ;
int V_48 ;
T_1 V_15 = 0 ;
T_1 V_16 ;
int V_204 = 0 ;
struct V_33 * V_34 ;
struct V_166 * V_169 ;
T_4 V_142 ;
T_4 V_207 ;
unsigned long V_137 ;
while ( 1 ) {
V_21 = F_112 ( V_171 , V_43 , V_15 , V_69 , & V_169 ,
& V_15 ) ;
if ( V_21 < 0 )
break;
if ( V_21 ) {
V_21 = V_204 ? 0 : - V_87 ;
break;
}
++ V_204 ;
V_48 = V_69 -> V_77 [ 0 ] ;
V_34 = F_132 ( V_69 -> V_75 [ 0 ] ) ;
if ( ! V_34 ) {
V_21 = - V_29 ;
break;
}
F_133 ( V_34 ) ;
F_72 ( V_34 ) ;
F_118 ( V_34 , V_183 ) ;
F_56 ( V_69 ) ;
V_142 = F_88 ( V_34 , V_48 ) ;
V_137 = F_113 ( V_34 , V_48 ) ;
V_207 = 0 ;
while ( V_207 < V_142 ) {
T_4 V_172 ;
V_169 = (struct V_166 * ) ( V_137 + V_207 ) ;
V_16 = F_137 ( V_34 , V_169 ) ;
V_172 = F_138 ( V_34 , V_169 ) ;
V_21 = V_195 ( V_16 , V_172 ,
( unsigned long ) & V_169 -> V_208 , V_34 , V_196 ) ;
if ( V_21 )
break;
V_207 += F_138 ( V_34 , V_169 ) ;
V_207 += sizeof( * V_169 ) ;
}
F_116 ( V_34 ) ;
F_71 ( V_34 ) ;
V_15 ++ ;
}
F_56 ( V_69 ) ;
return V_21 ;
}
static int F_139 ( T_1 V_43 , struct V_66 * V_171 ,
struct V_68 * V_69 , T_8 * V_195 ,
void * V_196 )
{
int V_21 ;
int V_209 = 0 ;
V_21 = F_131 ( V_43 , V_171 , V_69 , V_195 , V_196 ) ;
if ( ! V_21 )
++ V_209 ;
else if ( V_21 != - V_87 )
return V_21 ;
V_21 = F_136 ( V_43 , V_171 , V_69 , V_195 , V_196 ) ;
if ( V_21 == - V_87 && V_209 )
return 0 ;
return V_21 ;
}
static int F_140 ( T_1 V_43 , T_4 V_172 , unsigned long V_173 ,
struct V_33 * V_34 , void * V_196 )
{
struct V_210 * V_211 = V_196 ;
char * V_212 ;
char * V_213 ;
int V_214 = V_211 -> V_212 -> V_215 ;
const int V_216 = sizeof( char * ) ;
T_4 V_178 ;
V_178 = V_211 -> V_212 -> V_178 > V_216 ?
V_211 -> V_212 -> V_178 - V_216 : 0 ;
V_213 = ( char * ) V_211 -> V_212 -> V_99 + ( V_214 + 1 ) * V_216 ;
V_212 = F_114 ( V_211 -> V_171 , V_211 -> V_68 , V_172 ,
V_173 , V_34 , V_43 , V_213 , V_178 ) ;
if ( F_46 ( V_212 ) )
return F_48 ( V_212 ) ;
if ( V_212 > V_213 ) {
V_211 -> V_212 -> V_99 [ V_214 ] = ( T_1 ) ( unsigned long ) V_212 ;
++ V_211 -> V_212 -> V_215 ;
V_211 -> V_212 -> V_178 = V_212 - V_213 ;
} else {
++ V_211 -> V_212 -> V_217 ;
V_211 -> V_212 -> V_218 += V_213 - V_212 ;
V_211 -> V_212 -> V_178 = 0 ;
}
return 0 ;
}
int F_141 ( T_1 V_43 , struct V_210 * V_211 )
{
return F_139 ( V_43 , V_211 -> V_171 , V_211 -> V_68 ,
F_140 , V_211 ) ;
}
struct V_219 * F_142 ( T_4 V_220 )
{
struct V_219 * V_221 ;
T_9 V_222 ;
V_222 = F_143 ( T_9 , V_220 , sizeof( * V_221 ) ) ;
V_221 = F_144 ( V_222 ) ;
if ( ! V_221 )
return F_120 ( - V_29 ) ;
if ( V_220 >= sizeof( * V_221 ) ) {
V_221 -> V_178 = V_220 - sizeof( * V_221 ) ;
V_221 -> V_218 = 0 ;
} else {
V_221 -> V_218 = sizeof( * V_221 ) - V_220 ;
V_221 -> V_178 = 0 ;
}
V_221 -> V_215 = 0 ;
V_221 -> V_217 = 0 ;
return V_221 ;
}
struct V_210 * F_145 ( T_10 V_220 , struct V_66 * V_171 ,
struct V_68 * V_69 )
{
struct V_210 * V_223 ;
struct V_219 * V_212 ;
V_212 = F_142 ( V_220 ) ;
if ( F_46 ( V_212 ) )
return ( void * ) V_212 ;
V_223 = F_2 ( sizeof( * V_223 ) , V_3 ) ;
if ( ! V_223 ) {
F_146 ( V_212 ) ;
return F_120 ( - V_29 ) ;
}
V_223 -> V_68 = V_69 ;
V_223 -> V_212 = V_212 ;
V_223 -> V_171 = V_171 ;
return V_223 ;
}
void F_147 ( struct V_210 * V_211 )
{
if ( ! V_211 )
return;
F_146 ( V_211 -> V_212 ) ;
F_7 ( V_211 ) ;
}
