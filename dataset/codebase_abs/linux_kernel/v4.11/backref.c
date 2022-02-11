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
if ( V_72 == ( T_1 ) - 1 )
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
if ( V_72 == ( T_1 ) - 1 )
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
static int F_43 ( struct V_78 * V_79 ,
struct V_68 * V_69 , T_1 V_72 ,
struct V_54 * V_60 ,
struct V_70 * V_71 ,
const T_1 * V_37 , T_1 V_73 )
{
struct V_66 * V_67 ;
struct V_31 V_80 ;
struct V_33 * V_34 ;
int V_21 = 0 ;
int V_81 ;
int V_58 = V_60 -> V_58 ;
int V_82 ;
V_80 . V_44 = V_60 -> V_13 ;
V_80 . type = V_83 ;
V_80 . V_15 = ( T_1 ) - 1 ;
V_82 = F_44 ( & V_79 -> V_84 ) ;
V_67 = F_45 ( V_79 , & V_80 , false ) ;
if ( F_46 ( V_67 ) ) {
F_47 ( & V_79 -> V_84 , V_82 ) ;
V_21 = F_48 ( V_67 ) ;
goto V_85;
}
if ( F_49 ( V_79 ) ) {
F_47 ( & V_79 -> V_84 , V_82 ) ;
V_21 = - V_86 ;
goto V_85;
}
if ( V_69 -> V_87 )
V_81 = F_50 ( V_67 -> V_88 ) ;
else if ( V_72 == ( T_1 ) - 1 )
V_81 = F_50 ( V_67 -> V_8 ) ;
else
V_81 = F_51 ( V_67 , V_72 ) ;
if ( V_81 + 1 == V_58 ) {
F_47 ( & V_79 -> V_84 , V_82 ) ;
goto V_85;
}
V_69 -> V_89 = V_58 ;
if ( V_72 == ( T_1 ) - 1 )
V_21 = F_52 ( NULL , V_67 , & V_60 -> V_62 , V_69 ,
0 , 0 ) ;
else
V_21 = F_53 ( V_67 , & V_60 -> V_62 , V_69 ,
V_72 ) ;
F_47 ( & V_79 -> V_84 , V_82 ) ;
F_54 ( V_79 ,
L_2 ,
V_60 -> V_13 , V_58 , V_60 -> V_27 , V_21 ,
V_60 -> V_62 . V_44 , V_60 -> V_62 . type ,
V_60 -> V_62 . V_15 ) ;
if ( V_21 < 0 )
goto V_85;
V_34 = V_69 -> V_75 [ V_58 ] ;
while ( ! V_34 ) {
if ( F_55 ( ! V_58 ) ) {
V_21 = 1 ;
goto V_85;
}
V_58 -- ;
V_34 = V_69 -> V_75 [ V_58 ] ;
}
V_21 = F_36 ( V_67 , V_69 , V_71 , V_60 , V_58 , V_72 ,
V_37 , V_73 ) ;
V_85:
V_69 -> V_89 = 0 ;
F_56 ( V_69 ) ;
return V_21 ;
}
static int F_57 ( struct V_78 * V_79 ,
struct V_68 * V_69 , T_1 V_72 ,
struct V_56 * V_57 ,
const T_1 * V_37 , T_1 V_73 ,
T_1 V_90 )
{
int V_91 ;
int V_21 = 0 ;
struct V_54 * V_60 ;
struct V_54 * V_92 ;
struct V_54 * V_93 ;
struct V_70 * V_71 ;
struct V_94 * V_8 ;
struct V_95 V_96 ;
V_71 = F_58 ( V_3 ) ;
if ( ! V_71 )
return - V_29 ;
F_59 (ref, ref_safe, head, list) {
if ( V_60 -> V_16 )
continue;
if ( V_60 -> V_27 == 0 )
continue;
if ( V_90 && V_60 -> V_13 != V_90 ) {
V_21 = V_97 ;
goto V_85;
}
V_91 = F_43 ( V_79 , V_69 , V_72 , V_60 ,
V_71 , V_37 ,
V_73 ) ;
if ( V_91 == - V_86 ) {
continue;
} else if ( V_91 ) {
V_21 = V_91 ;
goto V_85;
}
F_60 ( & V_96 ) ;
V_8 = F_61 ( V_71 , & V_96 ) ;
V_60 -> V_16 = V_8 ? V_8 -> V_98 : 0 ;
V_60 -> V_64 = V_8 ?
(struct V_38 * ) ( V_99 ) V_8 -> V_100 : NULL ;
while ( ( V_8 = F_61 ( V_71 , & V_96 ) ) ) {
V_93 = F_34 ( V_53 ,
V_3 ) ;
if ( ! V_93 ) {
V_21 = - V_29 ;
goto V_85;
}
memcpy ( V_93 , V_60 , sizeof( * V_60 ) ) ;
V_93 -> V_16 = V_8 -> V_98 ;
V_93 -> V_64 = (struct V_38 * )
( V_99 ) V_8 -> V_100 ;
F_62 ( & V_93 -> V_65 , & V_60 -> V_65 ) ;
}
F_63 ( V_71 ) ;
}
V_85:
F_64 ( V_71 ) ;
return V_21 ;
}
static inline int F_65 ( struct V_54 * V_101 ,
struct V_54 * V_102 )
{
if ( V_101 -> V_58 != V_102 -> V_58 )
return 0 ;
if ( V_101 -> V_13 != V_102 -> V_13 )
return 0 ;
if ( V_101 -> V_62 . type != V_102 -> V_62 . type )
return 0 ;
if ( V_101 -> V_62 . V_44 != V_102 -> V_62 . V_44 )
return 0 ;
if ( V_101 -> V_62 . V_15 != V_102 -> V_62 . V_15 )
return 0 ;
if ( V_101 -> V_16 != V_102 -> V_16 )
return 0 ;
return 1 ;
}
static int F_66 ( struct V_78 * V_79 ,
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
V_34 = F_69 ( V_79 , V_60 -> V_46 , 0 ) ;
if ( F_46 ( V_34 ) ) {
return F_48 ( V_34 ) ;
} else if ( ! F_70 ( V_34 ) ) {
F_71 ( V_34 ) ;
return - V_103 ;
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
static void F_75 ( struct V_56 * V_57 , int V_104 )
{
struct V_54 * V_105 ;
F_67 (pos1, head, list) {
struct V_54 * V_106 = V_105 , * V_107 ;
F_76 (pos2, tmp, head, list) {
struct V_54 * V_101 = V_105 , * V_102 = V_106 ;
struct V_38 * V_39 ;
if ( ! F_65 ( V_101 , V_102 ) )
continue;
if ( V_104 == 1 ) {
if ( ! V_101 -> V_16 && V_102 -> V_16 )
F_77 ( V_101 , V_102 ) ;
} else {
if ( V_101 -> V_16 != V_102 -> V_16 )
continue;
}
V_39 = V_101 -> V_64 ;
while ( V_39 && V_39 -> V_10 )
V_39 = V_39 -> V_10 ;
if ( V_39 )
V_39 -> V_10 = V_102 -> V_64 ;
else
V_101 -> V_64 = V_102 -> V_64 ;
V_101 -> V_27 += V_102 -> V_27 ;
F_78 ( & V_102 -> V_65 ) ;
F_79 ( V_53 , V_102 ) ;
F_80 () ;
}
}
}
static int F_81 ( struct V_108 * V_57 , T_1 V_109 ,
struct V_56 * V_110 , T_1 * V_73 ,
T_1 V_43 )
{
struct V_111 * V_8 ;
struct V_112 * V_113 = V_57 -> V_113 ;
struct V_31 V_32 ;
struct V_31 V_114 = { 0 } ;
int V_115 ;
int V_21 = 0 ;
if ( V_113 && V_113 -> V_116 )
F_82 ( & V_114 , & V_113 -> V_32 ) ;
F_83 ( & V_57 -> V_117 ) ;
F_67 (node, &head->ref_list, list) {
if ( V_8 -> V_109 > V_109 )
continue;
switch ( V_8 -> V_118 ) {
case V_119 :
case V_120 :
F_55 ( 1 ) ;
continue;
case V_121 :
V_115 = 1 ;
break;
case V_122 :
V_115 = - 1 ;
break;
default:
F_68 ( 1 ) ;
}
* V_73 += ( V_8 -> V_30 * V_115 ) ;
switch ( V_8 -> type ) {
case V_123 : {
struct V_124 * V_60 ;
V_60 = F_84 ( V_8 ) ;
V_21 = F_33 ( V_110 , V_60 -> V_67 , & V_114 ,
V_60 -> V_58 + 1 , 0 , V_8 -> V_125 ,
V_8 -> V_30 * V_115 , V_126 ) ;
break;
}
case V_127 : {
struct V_124 * V_60 ;
V_60 = F_84 ( V_8 ) ;
V_21 = F_33 ( V_110 , 0 , NULL ,
V_60 -> V_58 + 1 , V_60 -> V_16 ,
V_8 -> V_125 ,
V_8 -> V_30 * V_115 , V_126 ) ;
break;
}
case V_128 : {
struct V_129 * V_60 ;
V_60 = F_85 ( V_8 ) ;
V_32 . V_44 = V_60 -> V_44 ;
V_32 . type = V_51 ;
V_32 . V_15 = V_60 -> V_15 ;
if ( V_43 && V_60 -> V_44 != V_43 ) {
V_21 = V_97 ;
break;
}
V_21 = F_33 ( V_110 , V_60 -> V_67 , & V_32 , 0 , 0 ,
V_8 -> V_125 ,
V_8 -> V_30 * V_115 , V_126 ) ;
break;
}
case V_130 : {
struct V_129 * V_60 ;
V_60 = F_85 ( V_8 ) ;
V_21 = F_33 ( V_110 , 0 , NULL , 0 ,
V_60 -> V_16 , V_8 -> V_125 ,
V_8 -> V_30 * V_115 , V_126 ) ;
break;
}
default:
F_55 ( 1 ) ;
}
if ( V_21 )
break;
}
F_86 ( & V_57 -> V_117 ) ;
return V_21 ;
}
static int F_87 ( struct V_68 * V_69 , T_1 V_125 ,
int * V_131 , struct V_56 * V_110 ,
struct V_1 * V_2 ,
T_1 * V_73 , T_1 V_43 )
{
int V_21 = 0 ;
int V_48 ;
struct V_33 * V_132 ;
struct V_31 V_32 ;
struct V_31 V_133 ;
unsigned long V_134 ;
unsigned long V_135 ;
struct V_136 * V_137 ;
T_1 V_138 ;
T_1 V_139 ;
V_132 = V_69 -> V_75 [ 0 ] ;
V_48 = V_69 -> V_77 [ 0 ] ;
V_139 = F_88 ( V_132 , V_48 ) ;
F_68 ( V_139 < sizeof( * V_137 ) ) ;
V_137 = F_26 ( V_132 , V_48 , struct V_136 ) ;
V_138 = F_89 ( V_132 , V_137 ) ;
* V_73 += F_90 ( V_132 , V_137 ) ;
F_25 ( V_132 , & V_133 , V_48 ) ;
V_134 = ( unsigned long ) ( V_137 + 1 ) ;
V_135 = ( unsigned long ) V_137 + V_139 ;
if ( V_133 . type == V_140 &&
V_138 & V_141 ) {
struct V_142 * V_143 ;
V_143 = (struct V_142 * ) V_134 ;
* V_131 = F_91 ( V_132 , V_143 ) ;
V_134 += sizeof( struct V_142 ) ;
F_68 ( V_134 > V_135 ) ;
} else if ( V_133 . type == V_144 ) {
* V_131 = V_133 . V_15 ;
} else {
F_68 ( ! ( V_138 & V_145 ) ) ;
}
while ( V_134 < V_135 ) {
struct V_146 * V_147 ;
T_1 V_15 ;
int type ;
V_147 = (struct V_146 * ) V_134 ;
type = F_92 ( V_132 , V_147 ) ;
V_15 = F_93 ( V_132 , V_147 ) ;
switch ( type ) {
case V_127 :
V_21 = F_33 ( V_110 , 0 , NULL ,
* V_131 + 1 , V_15 ,
V_125 , 1 , V_3 ) ;
break;
case V_130 : {
struct V_148 * V_149 ;
int V_27 ;
V_149 = (struct V_148 * ) ( V_147 + 1 ) ;
V_27 = F_94 ( V_132 , V_149 ) ;
V_21 = F_33 ( V_110 , 0 , NULL , 0 , V_15 ,
V_125 , V_27 , V_3 ) ;
if ( V_2 ) {
if ( ! V_21 )
V_21 = F_15 ( V_2 , 0 , 0 , 0 ,
V_125 , V_27 ) ;
if ( ! V_21 && V_2 -> V_6 > 1 )
V_21 = V_97 ;
}
break;
}
case V_123 :
V_21 = F_33 ( V_110 , V_15 , NULL ,
* V_131 + 1 , 0 ,
V_125 , 1 , V_3 ) ;
break;
case V_128 : {
struct V_150 * V_151 ;
int V_27 ;
T_1 V_67 ;
V_151 = (struct V_150 * ) ( & V_147 -> V_15 ) ;
V_27 = F_95 ( V_132 , V_151 ) ;
V_32 . V_44 = F_96 ( V_132 ,
V_151 ) ;
V_32 . type = V_51 ;
V_32 . V_15 = F_97 ( V_132 , V_151 ) ;
if ( V_43 && V_32 . V_44 != V_43 ) {
V_21 = V_97 ;
break;
}
V_67 = F_98 ( V_132 , V_151 ) ;
V_21 = F_33 ( V_110 , V_67 , & V_32 , 0 , 0 ,
V_125 , V_27 , V_3 ) ;
if ( V_2 ) {
if ( ! V_21 )
V_21 = F_15 ( V_2 , V_67 ,
V_32 . V_44 ,
V_32 . V_15 , 0 ,
V_27 ) ;
if ( ! V_21 && V_2 -> V_6 > 1 )
V_21 = V_97 ;
}
break;
}
default:
F_55 ( 1 ) ;
}
if ( V_21 )
return V_21 ;
V_134 += F_99 ( type ) ;
}
return 0 ;
}
static int F_100 ( struct V_78 * V_79 ,
struct V_68 * V_69 , T_1 V_125 ,
int V_131 , struct V_56 * V_110 ,
struct V_1 * V_2 , T_1 V_43 )
{
struct V_66 * V_152 = V_79 -> V_152 ;
int V_21 ;
int V_48 ;
struct V_33 * V_132 ;
struct V_31 V_32 ;
while ( 1 ) {
V_21 = F_41 ( V_152 , V_69 ) ;
if ( V_21 < 0 )
break;
if ( V_21 ) {
V_21 = 0 ;
break;
}
V_48 = V_69 -> V_77 [ 0 ] ;
V_132 = V_69 -> V_75 [ 0 ] ;
F_25 ( V_132 , & V_32 , V_48 ) ;
if ( V_32 . V_44 != V_125 )
break;
if ( V_32 . type < V_123 )
continue;
if ( V_32 . type > V_130 )
break;
switch ( V_32 . type ) {
case V_127 :
V_21 = F_33 ( V_110 , 0 , NULL ,
V_131 + 1 , V_32 . V_15 ,
V_125 , 1 , V_3 ) ;
break;
case V_130 : {
struct V_148 * V_149 ;
int V_27 ;
V_149 = F_26 ( V_132 , V_48 ,
struct V_148 ) ;
V_27 = F_94 ( V_132 , V_149 ) ;
V_21 = F_33 ( V_110 , 0 , NULL , 0 , V_32 . V_15 ,
V_125 , V_27 , V_3 ) ;
if ( V_2 ) {
if ( ! V_21 )
V_21 = F_15 ( V_2 , 0 , 0 , 0 ,
V_125 , V_27 ) ;
if ( ! V_21 && V_2 -> V_6 > 1 )
V_21 = V_97 ;
}
break;
}
case V_123 :
V_21 = F_33 ( V_110 , V_32 . V_15 , NULL ,
V_131 + 1 , 0 ,
V_125 , 1 , V_3 ) ;
break;
case V_128 : {
struct V_150 * V_151 ;
int V_27 ;
T_1 V_67 ;
V_151 = F_26 ( V_132 , V_48 ,
struct V_150 ) ;
V_27 = F_95 ( V_132 , V_151 ) ;
V_32 . V_44 = F_96 ( V_132 ,
V_151 ) ;
V_32 . type = V_51 ;
V_32 . V_15 = F_97 ( V_132 , V_151 ) ;
if ( V_43 && V_32 . V_44 != V_43 ) {
V_21 = V_97 ;
break;
}
V_67 = F_98 ( V_132 , V_151 ) ;
V_21 = F_33 ( V_110 , V_67 , & V_32 , 0 , 0 ,
V_125 , V_27 , V_3 ) ;
if ( V_2 ) {
if ( ! V_21 )
V_21 = F_15 ( V_2 , V_67 ,
V_32 . V_44 ,
V_32 . V_15 , 0 ,
V_27 ) ;
if ( ! V_21 && V_2 -> V_6 > 1 )
V_21 = V_97 ;
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
static void F_101 ( struct V_70 * V_153 )
{
struct V_94 * V_8 = NULL ;
struct V_38 * V_39 ;
struct V_95 V_96 ;
F_60 ( & V_96 ) ;
while ( ( V_8 = F_61 ( V_153 , & V_96 ) ) ) {
if ( ! V_8 -> V_100 )
continue;
V_39 = (struct V_38 * ) ( V_99 ) V_8 -> V_100 ;
F_22 ( V_39 ) ;
V_8 -> V_100 = 0 ;
}
F_64 ( V_153 ) ;
}
static int F_102 ( struct V_154 * V_155 ,
struct V_78 * V_79 , T_1 V_125 ,
T_1 V_72 , struct V_70 * * V_156 ,
const T_1 * V_37 )
{
int V_21 ;
* V_156 = F_58 ( V_3 ) ;
if ( ! * V_156 )
return - V_29 ;
V_21 = F_103 ( V_155 , V_79 , V_125 , V_72 ,
* V_156 , NULL , V_37 , 0 , 0 , 0 ) ;
if ( V_21 < 0 && V_21 != - V_86 ) {
F_101 ( * V_156 ) ;
return V_21 ;
}
return 0 ;
}
static int F_104 ( struct V_154 * V_155 ,
struct V_78 * V_79 , T_1 V_125 ,
T_1 V_72 , struct V_70 * * V_157 )
{
struct V_70 * V_107 ;
struct V_94 * V_8 = NULL ;
struct V_95 V_96 ;
int V_21 ;
V_107 = F_58 ( V_3 ) ;
if ( ! V_107 )
return - V_29 ;
* V_157 = F_58 ( V_3 ) ;
if ( ! * V_157 ) {
F_64 ( V_107 ) ;
return - V_29 ;
}
F_60 ( & V_96 ) ;
while ( 1 ) {
V_21 = F_103 ( V_155 , V_79 , V_125 , V_72 ,
V_107 , * V_157 , NULL , 0 , 0 , 0 ) ;
if ( V_21 < 0 && V_21 != - V_86 ) {
F_64 ( V_107 ) ;
F_64 ( * V_157 ) ;
return V_21 ;
}
V_8 = F_61 ( V_107 , & V_96 ) ;
if ( ! V_8 )
break;
V_125 = V_8 -> V_98 ;
F_80 () ;
}
F_64 ( V_107 ) ;
return 0 ;
}
int F_105 ( struct V_154 * V_155 ,
struct V_78 * V_79 , T_1 V_125 ,
T_1 V_72 , struct V_70 * * V_157 )
{
int V_21 ;
if ( ! V_155 )
F_106 ( & V_79 -> V_158 ) ;
V_21 = F_104 ( V_155 , V_79 , V_125 , V_72 , V_157 ) ;
if ( ! V_155 )
F_107 ( & V_79 -> V_158 ) ;
return V_21 ;
}
int F_108 ( struct V_154 * V_155 ,
struct V_78 * V_79 , T_1 V_90 ,
T_1 V_43 , T_1 V_125 )
{
struct V_70 * V_107 = NULL ;
struct V_70 * V_157 = NULL ;
struct V_95 V_96 ;
struct V_94 * V_8 ;
struct V_159 V_160 = F_109 ( V_160 ) ;
int V_21 = 0 ;
V_107 = F_58 ( V_3 ) ;
V_157 = F_58 ( V_3 ) ;
if ( ! V_107 || ! V_157 ) {
F_64 ( V_107 ) ;
F_64 ( V_157 ) ;
return - V_29 ;
}
if ( V_155 )
F_110 ( V_79 , & V_160 ) ;
else
F_106 ( & V_79 -> V_158 ) ;
F_60 ( & V_96 ) ;
while ( 1 ) {
V_21 = F_103 ( V_155 , V_79 , V_125 , V_160 . V_109 , V_107 ,
V_157 , NULL , V_90 , V_43 , 1 ) ;
if ( V_21 == V_97 ) {
V_21 = 1 ;
break;
}
if ( V_21 < 0 && V_21 != - V_86 )
break;
V_21 = 0 ;
V_8 = F_61 ( V_107 , & V_96 ) ;
if ( ! V_8 )
break;
V_125 = V_8 -> V_98 ;
F_80 () ;
}
if ( V_155 )
F_111 ( V_79 , & V_160 ) ;
else
F_107 ( & V_79 -> V_158 ) ;
F_64 ( V_107 ) ;
F_64 ( V_157 ) ;
return V_21 ;
}
int F_112 ( struct V_66 * V_67 , T_1 V_161 ,
T_1 V_162 , struct V_68 * V_69 ,
struct V_163 * * V_164 ,
T_1 * V_165 )
{
int V_21 , V_48 ;
struct V_31 V_32 ;
struct V_31 V_133 ;
struct V_163 * V_166 ;
struct V_33 * V_132 ;
unsigned long V_134 ;
V_32 . V_44 = V_161 ;
V_32 . type = V_167 ;
V_32 . V_15 = V_162 ;
V_21 = F_52 ( NULL , V_67 , & V_32 , V_69 , 0 , 0 ) ;
if ( V_21 < 0 )
return V_21 ;
while ( 1 ) {
V_132 = V_69 -> V_75 [ 0 ] ;
V_48 = V_69 -> V_77 [ 0 ] ;
if ( V_48 >= F_24 ( V_132 ) ) {
V_21 = F_38 ( V_67 , V_69 ) ;
if ( V_21 ) {
if ( V_21 >= 1 )
V_21 = - V_86 ;
break;
}
continue;
}
F_25 ( V_132 , & V_133 , V_48 ) ;
V_21 = - V_86 ;
if ( V_133 . V_44 != V_161 )
break;
if ( V_133 . type != V_167 )
break;
V_21 = 0 ;
V_134 = F_113 ( V_132 , V_69 -> V_77 [ 0 ] ) ;
V_166 = (struct V_163 * ) V_134 ;
* V_164 = V_166 ;
if ( V_165 )
* V_165 = V_133 . V_15 ;
break;
}
return V_21 ;
}
char * F_114 ( struct V_66 * V_168 , struct V_68 * V_69 ,
T_4 V_169 , unsigned long V_170 ,
struct V_33 * V_171 , T_1 V_16 ,
char * V_172 , T_4 V_173 )
{
int V_48 ;
T_1 V_174 ;
int V_21 ;
T_5 V_175 = ( ( T_5 ) V_173 ) - 1 ;
struct V_33 * V_34 = V_171 ;
struct V_31 V_133 ;
int V_176 = V_69 -> V_176 ;
struct V_177 * V_147 ;
if ( V_175 >= 0 )
V_172 [ V_175 ] = '\0' ;
V_69 -> V_176 = 1 ;
while ( 1 ) {
V_175 -= V_169 ;
if ( V_175 >= 0 )
F_115 ( V_34 , V_172 + V_175 ,
V_170 , V_169 ) ;
if ( V_34 != V_171 ) {
if ( ! V_69 -> V_178 )
F_116 ( V_34 ) ;
F_71 ( V_34 ) ;
}
V_21 = F_117 ( V_168 , V_69 , V_16 , 0 ,
V_179 , & V_133 ) ;
if ( V_21 > 0 )
V_21 = - V_86 ;
if ( V_21 )
break;
V_174 = V_133 . V_15 ;
if ( V_16 == V_174 )
break;
V_48 = V_69 -> V_77 [ 0 ] ;
V_34 = V_69 -> V_75 [ 0 ] ;
if ( V_34 != V_171 ) {
if ( ! V_69 -> V_178 )
F_118 ( V_34 , V_180 ) ;
V_69 -> V_75 [ 0 ] = NULL ;
V_69 -> V_181 [ 0 ] = 0 ;
}
F_56 ( V_69 ) ;
V_147 = F_26 ( V_34 , V_48 , struct V_177 ) ;
V_169 = F_119 ( V_34 , V_147 ) ;
V_170 = ( unsigned long ) ( V_147 + 1 ) ;
V_16 = V_174 ;
-- V_175 ;
if ( V_175 >= 0 )
V_172 [ V_175 ] = '/' ;
}
F_56 ( V_69 ) ;
V_69 -> V_176 = V_176 ;
if ( V_21 )
return F_120 ( V_21 ) ;
return V_172 + V_175 ;
}
int F_121 ( struct V_78 * V_79 , T_1 V_182 ,
struct V_68 * V_69 , struct V_31 * V_133 ,
T_1 * V_183 )
{
int V_21 ;
T_1 V_138 ;
T_1 V_173 = 0 ;
T_4 V_139 ;
struct V_33 * V_34 ;
struct V_136 * V_137 ;
struct V_31 V_32 ;
if ( F_122 ( V_79 , V_184 ) )
V_32 . type = V_144 ;
else
V_32 . type = V_140 ;
V_32 . V_44 = V_182 ;
V_32 . V_15 = ( T_1 ) - 1 ;
V_21 = F_52 ( NULL , V_79 -> V_152 , & V_32 , V_69 , 0 , 0 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_123 ( V_79 -> V_152 , V_69 , 0 ) ;
if ( V_21 ) {
if ( V_21 > 0 )
V_21 = - V_86 ;
return V_21 ;
}
F_25 ( V_69 -> V_75 [ 0 ] , V_133 , V_69 -> V_77 [ 0 ] ) ;
if ( V_133 -> type == V_144 )
V_173 = V_79 -> V_185 ;
else if ( V_133 -> type == V_140 )
V_173 = V_133 -> V_15 ;
if ( V_133 -> V_44 > V_182 ||
V_133 -> V_44 + V_173 <= V_182 ) {
F_54 ( V_79 ,
L_3 , V_182 ) ;
return - V_86 ;
}
V_34 = V_69 -> V_75 [ 0 ] ;
V_139 = F_88 ( V_34 , V_69 -> V_77 [ 0 ] ) ;
F_68 ( V_139 < sizeof( * V_137 ) ) ;
V_137 = F_26 ( V_34 , V_69 -> V_77 [ 0 ] , struct V_136 ) ;
V_138 = F_89 ( V_34 , V_137 ) ;
F_54 ( V_79 ,
L_4 ,
V_182 , V_182 - V_133 -> V_44 , V_133 -> V_44 ,
V_133 -> V_15 , V_138 , V_139 ) ;
F_55 ( ! V_183 ) ;
if ( V_183 ) {
if ( V_138 & V_141 )
* V_183 = V_141 ;
else if ( V_138 & V_145 )
* V_183 = V_145 ;
else
F_68 ( 1 ) ;
return 0 ;
}
return - V_103 ;
}
static int F_124 ( unsigned long * V_134 , struct V_33 * V_34 ,
struct V_31 * V_32 ,
struct V_136 * V_137 , T_4 V_139 ,
struct V_146 * * V_186 ,
int * V_187 )
{
unsigned long V_135 ;
T_1 V_138 ;
struct V_142 * V_143 ;
if ( ! * V_134 ) {
V_138 = F_89 ( V_34 , V_137 ) ;
if ( V_138 & V_141 ) {
if ( V_32 -> type == V_144 ) {
* V_186 =
(struct V_146 * ) ( V_137 + 1 ) ;
} else {
F_55 ( V_32 -> type != V_140 ) ;
V_143 = (struct V_142 * ) ( V_137 + 1 ) ;
* V_186 =
(struct V_146 * ) ( V_143 + 1 ) ;
}
} else {
* V_186 = (struct V_146 * ) ( V_137 + 1 ) ;
}
* V_134 = ( unsigned long ) * V_186 ;
if ( ( unsigned long ) ( * V_134 ) >= ( unsigned long ) V_137 + V_139 )
return - V_86 ;
}
V_135 = ( unsigned long ) V_137 + V_139 ;
* V_186 = (struct V_146 * ) ( * V_134 ) ;
* V_187 = F_92 ( V_34 , * V_186 ) ;
* V_134 += F_99 ( * V_187 ) ;
F_55 ( * V_134 > V_135 ) ;
if ( * V_134 == V_135 )
return 1 ;
return 0 ;
}
int F_125 ( unsigned long * V_134 , struct V_33 * V_34 ,
struct V_31 * V_32 , struct V_136 * V_137 ,
T_4 V_139 , T_1 * V_188 , T_6 * V_189 )
{
int V_21 ;
int type ;
struct V_146 * V_190 ;
if ( * V_134 == ( unsigned long ) - 1 )
return 1 ;
while ( 1 ) {
V_21 = F_124 ( V_134 , V_34 , V_32 , V_137 , V_139 ,
& V_190 , & type ) ;
if ( V_21 < 0 )
return V_21 ;
if ( type == V_123 ||
type == V_127 )
break;
if ( V_21 == 1 )
return 1 ;
}
* V_188 = F_93 ( V_34 , V_190 ) ;
if ( V_32 -> type == V_140 ) {
struct V_142 * V_143 ;
V_143 = (struct V_142 * ) ( V_137 + 1 ) ;
* V_189 = F_91 ( V_34 , V_143 ) ;
} else {
ASSERT ( V_32 -> type == V_144 ) ;
* V_189 = ( T_6 ) V_32 -> V_15 ;
}
if ( V_21 == 1 )
* V_134 = ( unsigned long ) - 1 ;
return 0 ;
}
static int F_126 ( struct V_78 * V_79 ,
struct V_38 * V_64 ,
T_1 V_67 , T_1 V_191 ,
T_7 * V_192 , void * V_193 )
{
struct V_38 * V_39 ;
int V_21 = 0 ;
for ( V_39 = V_64 ; V_39 ; V_39 = V_39 -> V_10 ) {
F_54 ( V_79 ,
L_5 ,
V_191 , V_39 -> V_43 ,
V_39 -> V_15 , V_67 ) ;
V_21 = V_192 ( V_39 -> V_43 , V_39 -> V_15 , V_67 , V_193 ) ;
if ( V_21 ) {
F_54 ( V_79 ,
L_6 ,
V_191 , V_21 ) ;
break;
}
}
return V_21 ;
}
int F_127 ( struct V_78 * V_79 ,
T_1 V_191 , T_1 V_37 ,
int V_87 ,
T_7 * V_192 , void * V_193 )
{
int V_21 ;
struct V_154 * V_155 = NULL ;
struct V_70 * V_194 = NULL ;
struct V_70 * V_157 = NULL ;
struct V_94 * V_7 = NULL ;
struct V_94 * V_195 = NULL ;
struct V_159 V_196 = F_109 ( V_196 ) ;
struct V_95 V_197 ;
struct V_95 V_198 ;
F_54 ( V_79 , L_7 ,
V_191 ) ;
if ( ! V_87 ) {
V_155 = F_128 ( V_79 -> V_152 ) ;
if ( F_46 ( V_155 ) )
return F_48 ( V_155 ) ;
F_110 ( V_79 , & V_196 ) ;
} else {
F_106 ( & V_79 -> V_158 ) ;
}
V_21 = F_102 ( V_155 , V_79 , V_191 ,
V_196 . V_109 , & V_194 ,
& V_37 ) ;
if ( V_21 )
goto V_85;
F_60 ( & V_197 ) ;
while ( ! V_21 && ( V_7 = F_61 ( V_194 , & V_197 ) ) ) {
V_21 = F_104 ( V_155 , V_79 , V_7 -> V_98 ,
V_196 . V_109 , & V_157 ) ;
if ( V_21 )
break;
F_60 ( & V_198 ) ;
while ( ! V_21 && ( V_195 = F_61 ( V_157 , & V_198 ) ) ) {
F_54 ( V_79 ,
L_8 ,
V_195 -> V_98 , V_7 -> V_98 ,
V_7 -> V_100 ) ;
V_21 = F_126 ( V_79 ,
(struct V_38 * )
( V_99 ) V_7 -> V_100 ,
V_195 -> V_98 ,
V_191 ,
V_192 , V_193 ) ;
}
F_64 ( V_157 ) ;
}
F_101 ( V_194 ) ;
V_85:
if ( ! V_87 ) {
F_111 ( V_79 , & V_196 ) ;
F_129 ( V_155 ) ;
} else {
F_107 ( & V_79 -> V_158 ) ;
}
return V_21 ;
}
int F_130 ( T_1 V_182 , struct V_78 * V_79 ,
struct V_68 * V_69 ,
T_7 * V_192 , void * V_193 )
{
int V_21 ;
T_1 V_37 ;
T_1 V_138 = 0 ;
struct V_31 V_133 ;
int V_87 = V_69 -> V_87 ;
V_21 = F_121 ( V_79 , V_182 , V_69 , & V_133 , & V_138 ) ;
F_56 ( V_69 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_138 & V_141 )
return - V_199 ;
V_37 = V_182 - V_133 . V_44 ;
V_21 = F_127 ( V_79 , V_133 . V_44 ,
V_37 , V_87 ,
V_192 , V_193 ) ;
return V_21 ;
}
static int F_131 ( T_1 V_43 , struct V_66 * V_168 ,
struct V_68 * V_69 ,
T_8 * V_192 , void * V_193 )
{
int V_21 = 0 ;
int V_48 ;
T_4 V_19 ;
T_4 V_200 ;
T_4 V_169 ;
T_1 V_16 = 0 ;
int V_201 = 0 ;
struct V_33 * V_34 ;
struct V_202 * V_203 ;
struct V_177 * V_147 ;
struct V_31 V_133 ;
while ( ! V_21 ) {
V_21 = F_117 ( V_168 , V_69 , V_43 ,
V_16 ? V_16 + 1 : 0 , V_179 ,
& V_133 ) ;
if ( V_21 < 0 )
break;
if ( V_21 ) {
V_21 = V_201 ? 0 : - V_86 ;
break;
}
++ V_201 ;
V_16 = V_133 . V_15 ;
V_48 = V_69 -> V_77 [ 0 ] ;
V_34 = F_132 ( V_69 -> V_75 [ 0 ] ) ;
if ( ! V_34 ) {
V_21 = - V_29 ;
break;
}
F_133 ( V_34 ) ;
F_72 ( V_34 ) ;
F_118 ( V_34 , V_180 ) ;
F_56 ( V_69 ) ;
V_203 = F_134 ( V_48 ) ;
V_147 = F_26 ( V_34 , V_48 , struct V_177 ) ;
for ( V_19 = 0 ; V_19 < F_135 ( V_34 , V_203 ) ; V_19 += V_200 ) {
V_169 = F_119 ( V_34 , V_147 ) ;
F_54 ( V_168 -> V_79 ,
L_9 ,
V_19 , V_133 . V_44 , V_168 -> V_44 ) ;
V_21 = V_192 ( V_16 , V_169 ,
( unsigned long ) ( V_147 + 1 ) , V_34 , V_193 ) ;
if ( V_21 )
break;
V_200 = sizeof( * V_147 ) + V_169 ;
V_147 = (struct V_177 * ) ( ( char * ) V_147 + V_200 ) ;
}
F_116 ( V_34 ) ;
F_71 ( V_34 ) ;
}
F_56 ( V_69 ) ;
return V_21 ;
}
static int F_136 ( T_1 V_43 , struct V_66 * V_168 ,
struct V_68 * V_69 ,
T_8 * V_192 , void * V_193 )
{
int V_21 ;
int V_48 ;
T_1 V_15 = 0 ;
T_1 V_16 ;
int V_201 = 0 ;
struct V_33 * V_34 ;
struct V_163 * V_166 ;
T_4 V_139 ;
T_4 V_204 ;
unsigned long V_134 ;
while ( 1 ) {
V_21 = F_112 ( V_168 , V_43 , V_15 , V_69 , & V_166 ,
& V_15 ) ;
if ( V_21 < 0 )
break;
if ( V_21 ) {
V_21 = V_201 ? 0 : - V_86 ;
break;
}
++ V_201 ;
V_48 = V_69 -> V_77 [ 0 ] ;
V_34 = F_132 ( V_69 -> V_75 [ 0 ] ) ;
if ( ! V_34 ) {
V_21 = - V_29 ;
break;
}
F_133 ( V_34 ) ;
F_72 ( V_34 ) ;
F_118 ( V_34 , V_180 ) ;
F_56 ( V_69 ) ;
V_139 = F_88 ( V_34 , V_48 ) ;
V_134 = F_113 ( V_34 , V_48 ) ;
V_204 = 0 ;
while ( V_204 < V_139 ) {
T_4 V_169 ;
V_166 = (struct V_163 * ) ( V_134 + V_204 ) ;
V_16 = F_137 ( V_34 , V_166 ) ;
V_169 = F_138 ( V_34 , V_166 ) ;
V_21 = V_192 ( V_16 , V_169 ,
( unsigned long ) & V_166 -> V_205 , V_34 , V_193 ) ;
if ( V_21 )
break;
V_204 += F_138 ( V_34 , V_166 ) ;
V_204 += sizeof( * V_166 ) ;
}
F_116 ( V_34 ) ;
F_71 ( V_34 ) ;
V_15 ++ ;
}
F_56 ( V_69 ) ;
return V_21 ;
}
static int F_139 ( T_1 V_43 , struct V_66 * V_168 ,
struct V_68 * V_69 , T_8 * V_192 ,
void * V_193 )
{
int V_21 ;
int V_206 = 0 ;
V_21 = F_131 ( V_43 , V_168 , V_69 , V_192 , V_193 ) ;
if ( ! V_21 )
++ V_206 ;
else if ( V_21 != - V_86 )
return V_21 ;
V_21 = F_136 ( V_43 , V_168 , V_69 , V_192 , V_193 ) ;
if ( V_21 == - V_86 && V_206 )
return 0 ;
return V_21 ;
}
static int F_140 ( T_1 V_43 , T_4 V_169 , unsigned long V_170 ,
struct V_33 * V_34 , void * V_193 )
{
struct V_207 * V_208 = V_193 ;
char * V_209 ;
char * V_210 ;
int V_211 = V_208 -> V_209 -> V_212 ;
const int V_213 = sizeof( char * ) ;
T_4 V_175 ;
V_175 = V_208 -> V_209 -> V_175 > V_213 ?
V_208 -> V_209 -> V_175 - V_213 : 0 ;
V_210 = ( char * ) V_208 -> V_209 -> V_98 + ( V_211 + 1 ) * V_213 ;
V_209 = F_114 ( V_208 -> V_168 , V_208 -> V_68 , V_169 ,
V_170 , V_34 , V_43 , V_210 , V_175 ) ;
if ( F_46 ( V_209 ) )
return F_48 ( V_209 ) ;
if ( V_209 > V_210 ) {
V_208 -> V_209 -> V_98 [ V_211 ] = ( T_1 ) ( unsigned long ) V_209 ;
++ V_208 -> V_209 -> V_212 ;
V_208 -> V_209 -> V_175 = V_209 - V_210 ;
} else {
++ V_208 -> V_209 -> V_214 ;
V_208 -> V_209 -> V_215 += V_210 - V_209 ;
V_208 -> V_209 -> V_175 = 0 ;
}
return 0 ;
}
int F_141 ( T_1 V_43 , struct V_207 * V_208 )
{
return F_139 ( V_43 , V_208 -> V_168 , V_208 -> V_68 ,
F_140 , V_208 ) ;
}
struct V_216 * F_142 ( T_4 V_217 )
{
struct V_216 * V_218 ;
T_9 V_219 ;
V_219 = F_143 ( T_9 , V_217 , sizeof( * V_218 ) ) ;
V_218 = F_144 ( V_219 ) ;
if ( ! V_218 )
return F_120 ( - V_29 ) ;
if ( V_217 >= sizeof( * V_218 ) ) {
V_218 -> V_175 = V_217 - sizeof( * V_218 ) ;
V_218 -> V_215 = 0 ;
} else {
V_218 -> V_215 = sizeof( * V_218 ) - V_217 ;
V_218 -> V_175 = 0 ;
}
V_218 -> V_212 = 0 ;
V_218 -> V_214 = 0 ;
return V_218 ;
}
struct V_207 * F_145 ( T_10 V_217 , struct V_66 * V_168 ,
struct V_68 * V_69 )
{
struct V_207 * V_220 ;
struct V_216 * V_209 ;
V_209 = F_142 ( V_217 ) ;
if ( F_46 ( V_209 ) )
return ( void * ) V_209 ;
V_220 = F_2 ( sizeof( * V_220 ) , V_3 ) ;
if ( ! V_220 ) {
F_146 ( V_209 ) ;
return F_120 ( - V_29 ) ;
}
V_220 -> V_68 = V_69 ;
V_220 -> V_209 = V_209 ;
V_220 -> V_168 = V_168 ;
return V_220 ;
}
void F_147 ( struct V_207 * V_208 )
{
if ( ! V_208 )
return;
F_146 ( V_208 -> V_209 ) ;
F_7 ( V_208 ) ;
}
