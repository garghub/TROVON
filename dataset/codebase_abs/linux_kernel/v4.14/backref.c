static int F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_5 * V_6 ,
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
static int F_10 ( const struct V_3 * V_4 ,
T_1 V_20 , T_1 V_7 ,
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
static inline int F_16 ( struct V_28 * V_29 )
{
return ( V_29 && V_29 -> V_30 > 1 ) ? V_31 : 0 ;
}
int T_2 F_17 ( void )
{
V_32 = F_18 ( L_1 ,
sizeof( struct V_33 ) ,
0 ,
V_34 ,
NULL ) ;
if ( ! V_32 )
return - V_15 ;
return 0 ;
}
void F_19 ( void )
{
F_20 ( V_32 ) ;
}
static void F_21 ( struct V_33 * V_35 )
{
F_22 ( V_32 , V_35 ) ;
}
static int F_23 ( struct V_33 * V_36 ,
struct V_33 * V_37 )
{
if ( V_36 -> V_38 < V_37 -> V_38 )
return - 1 ;
if ( V_36 -> V_38 > V_37 -> V_38 )
return 1 ;
if ( V_36 -> V_39 < V_37 -> V_39 )
return - 1 ;
if ( V_36 -> V_39 > V_37 -> V_39 )
return 1 ;
if ( V_36 -> V_40 . type < V_37 -> V_40 . type )
return - 1 ;
if ( V_36 -> V_40 . type > V_37 -> V_40 . type )
return 1 ;
if ( V_36 -> V_40 . V_18 < V_37 -> V_40 . V_18 )
return - 1 ;
if ( V_36 -> V_40 . V_18 > V_37 -> V_40 . V_18 )
return 1 ;
if ( V_36 -> V_40 . V_10 < V_37 -> V_40 . V_10 )
return - 1 ;
if ( V_36 -> V_40 . V_10 > V_37 -> V_40 . V_10 )
return 1 ;
if ( V_36 -> V_41 < V_37 -> V_41 )
return - 1 ;
if ( V_36 -> V_41 > V_37 -> V_41 )
return 1 ;
return 0 ;
}
void F_24 ( struct V_28 * V_29 , int V_42 , int V_43 )
{
if ( ( ! V_29 ) || ( V_42 == 0 && V_43 < 1 ) )
return;
if ( V_42 > 0 && V_43 < 1 )
V_29 -> V_30 -- ;
else if ( V_42 < 1 && V_43 > 0 )
V_29 -> V_30 ++ ;
}
static void F_25 ( const struct V_44 * V_45 ,
struct V_46 * V_46 ,
struct V_33 * V_47 ,
struct V_28 * V_29 )
{
struct V_48 * V_49 ;
struct V_50 * * V_51 ;
struct V_50 * V_41 = NULL ;
struct V_33 * V_35 ;
int V_52 ;
V_49 = & V_46 -> V_49 ;
V_51 = & V_49 -> V_50 ;
while ( * V_51 ) {
V_41 = * V_51 ;
V_35 = F_26 ( V_41 , struct V_33 , V_53 ) ;
V_52 = F_23 ( V_35 , V_47 ) ;
if ( V_52 < 0 ) {
V_51 = & ( * V_51 ) -> V_54 ;
} else if ( V_52 > 0 ) {
V_51 = & ( * V_51 ) -> V_55 ;
} else {
struct V_8 * V_9 = V_35 -> V_56 ;
while ( V_9 && V_9 -> V_16 )
V_9 = V_9 -> V_16 ;
if ( ! V_9 )
V_35 -> V_56 = V_47 -> V_56 ;
else
V_9 -> V_16 = V_47 -> V_56 ;
F_27 ( V_45 , V_35 , V_47 ,
V_46 -> V_57 ) ;
F_24 ( V_29 , V_35 -> V_57 ,
V_35 -> V_57 + V_47 -> V_57 ) ;
V_35 -> V_57 += V_47 -> V_57 ;
F_21 ( V_47 ) ;
return;
}
}
F_24 ( V_29 , 0 , V_47 -> V_57 ) ;
V_46 -> V_57 ++ ;
F_28 ( V_45 , V_47 , NULL , V_46 -> V_57 ) ;
F_29 ( & V_47 -> V_53 , V_41 , V_51 ) ;
F_30 ( & V_47 -> V_53 , V_49 ) ;
}
static void F_31 ( struct V_46 * V_46 )
{
struct V_33 * V_35 , * V_58 ;
F_32 (ref, next_ref, &preftree->root,
rbnode)
F_21 ( V_35 ) ;
V_46 -> V_49 = V_59 ;
V_46 -> V_57 = 0 ;
}
static int F_33 ( const struct V_44 * V_45 ,
struct V_46 * V_46 , T_1 V_39 ,
const struct V_1 * V_2 , int V_38 , T_1 V_41 ,
T_1 V_20 , int V_57 ,
struct V_28 * V_29 , T_3 V_60 )
{
struct V_33 * V_35 ;
if ( V_39 == V_61 )
return 0 ;
V_35 = F_34 ( V_32 , V_60 ) ;
if ( ! V_35 )
return - V_15 ;
V_35 -> V_39 = V_39 ;
if ( V_2 ) {
V_35 -> V_40 = * V_2 ;
if ( V_35 -> V_40 . type == V_26 &&
V_35 -> V_40 . V_10 >= V_62 )
V_35 -> V_40 . V_10 = 0 ;
} else {
memset ( & V_35 -> V_40 , 0 , sizeof( V_35 -> V_40 ) ) ;
}
V_35 -> V_56 = NULL ;
V_35 -> V_38 = V_38 ;
V_35 -> V_57 = V_57 ;
V_35 -> V_41 = V_41 ;
V_35 -> V_20 = V_20 ;
F_25 ( V_45 , V_46 , V_35 , V_29 ) ;
return F_16 ( V_29 ) ;
}
static int F_35 ( const struct V_44 * V_45 ,
struct V_63 * V_63 , int V_38 , T_1 V_41 ,
T_1 V_20 , int V_57 ,
struct V_28 * V_29 , T_3 V_60 )
{
return F_33 ( V_45 , & V_63 -> V_64 , 0 , NULL , V_38 ,
V_41 , V_20 , V_57 , V_29 , V_60 ) ;
}
static int F_36 ( const struct V_44 * V_45 ,
struct V_63 * V_63 , T_1 V_39 ,
const struct V_1 * V_2 , int V_38 ,
T_1 V_20 , int V_57 ,
struct V_28 * V_29 , T_3 V_60 )
{
struct V_46 * V_65 = & V_63 -> V_66 ;
if ( ! V_2 )
V_65 = & V_63 -> V_67 ;
return F_33 ( V_45 , V_65 , V_39 , V_2 , V_38 , 0 ,
V_20 , V_57 , V_29 , V_60 ) ;
}
static int F_37 ( struct V_68 * V_49 , struct V_69 * V_70 ,
struct V_71 * V_72 , struct V_33 * V_35 ,
int V_38 , T_1 V_73 , const T_1 * V_7 ,
T_1 V_74 )
{
int V_25 = 0 ;
int V_22 ;
struct V_3 * V_4 ;
struct V_1 V_2 ;
struct V_1 * V_40 = & V_35 -> V_40 ;
struct V_5 * V_6 ;
struct V_8 * V_9 = NULL , * V_75 = NULL ;
T_1 V_21 ;
T_1 V_20 = V_35 -> V_20 ;
T_1 V_57 = 0 ;
if ( V_38 != 0 ) {
V_4 = V_70 -> V_76 [ V_38 ] ;
V_25 = F_38 ( V_72 , V_4 -> V_77 , 0 , V_14 ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
if ( V_70 -> V_78 [ 0 ] >= F_11 ( V_70 -> V_76 [ 0 ] ) ) {
if ( V_73 == V_79 )
V_25 = F_39 ( V_49 , V_70 ) ;
else
V_25 = F_40 ( V_49 , V_70 , V_73 ) ;
}
while ( ! V_25 && V_57 < V_74 ) {
V_4 = V_70 -> V_76 [ 0 ] ;
V_22 = V_70 -> V_78 [ 0 ] ;
F_12 ( V_4 , & V_2 , V_22 ) ;
if ( V_2 . V_18 != V_40 -> V_18 ||
V_2 . type != V_26 )
break;
V_6 = F_13 ( V_4 , V_22 , struct V_5 ) ;
V_21 = F_15 ( V_4 , V_6 ) ;
if ( V_21 == V_20 ) {
V_9 = NULL ;
V_75 = NULL ;
V_57 ++ ;
if ( V_7 ) {
V_25 = F_1 ( & V_2 , V_4 , V_6 ,
* V_7 ,
& V_9 ) ;
if ( V_25 < 0 )
break;
}
if ( V_25 > 0 )
goto V_16;
V_25 = F_41 ( V_72 , V_4 -> V_77 ,
V_9 , ( void * * ) & V_75 , V_14 ) ;
if ( V_25 < 0 )
break;
if ( ! V_25 && V_7 ) {
while ( V_75 -> V_16 )
V_75 = V_75 -> V_16 ;
V_75 -> V_16 = V_9 ;
}
V_9 = NULL ;
}
V_16:
if ( V_73 == V_79 )
V_25 = F_42 ( V_49 , V_70 ) ;
else
V_25 = F_43 ( V_49 , V_70 , V_73 ) ;
}
if ( V_25 > 0 )
V_25 = 0 ;
else if ( V_25 < 0 )
F_8 ( V_9 ) ;
return V_25 ;
}
static int F_44 ( struct V_44 * V_45 ,
struct V_69 * V_70 , T_1 V_73 ,
struct V_33 * V_35 , struct V_71 * V_72 ,
const T_1 * V_7 , T_1 V_74 )
{
struct V_68 * V_49 ;
struct V_1 V_80 ;
struct V_3 * V_4 ;
int V_25 = 0 ;
int V_81 ;
int V_38 = V_35 -> V_38 ;
int V_82 ;
V_80 . V_18 = V_35 -> V_39 ;
V_80 . type = V_83 ;
V_80 . V_10 = ( T_1 ) - 1 ;
V_82 = F_45 ( & V_45 -> V_84 ) ;
V_49 = F_46 ( V_45 , & V_80 , false ) ;
if ( F_47 ( V_49 ) ) {
F_48 ( & V_45 -> V_84 , V_82 ) ;
V_25 = F_49 ( V_49 ) ;
goto V_85;
}
if ( F_50 ( V_45 ) ) {
F_48 ( & V_45 -> V_84 , V_82 ) ;
V_25 = - V_86 ;
goto V_85;
}
if ( V_70 -> V_87 )
V_81 = F_51 ( V_49 -> V_88 ) ;
else if ( V_73 == V_79 )
V_81 = F_51 ( V_49 -> V_89 ) ;
else
V_81 = F_52 ( V_49 , V_73 ) ;
if ( V_81 + 1 == V_38 ) {
F_48 ( & V_45 -> V_84 , V_82 ) ;
goto V_85;
}
V_70 -> V_90 = V_38 ;
if ( V_73 == V_79 )
V_25 = F_53 ( NULL , V_49 , & V_35 -> V_40 , V_70 ,
0 , 0 ) ;
else
V_25 = F_54 ( V_49 , & V_35 -> V_40 , V_70 ,
V_73 ) ;
F_48 ( & V_45 -> V_84 , V_82 ) ;
F_55 ( V_45 ,
L_2 ,
V_35 -> V_39 , V_38 , V_35 -> V_57 , V_25 ,
V_35 -> V_40 . V_18 , V_35 -> V_40 . type ,
V_35 -> V_40 . V_10 ) ;
if ( V_25 < 0 )
goto V_85;
V_4 = V_70 -> V_76 [ V_38 ] ;
while ( ! V_4 ) {
if ( F_56 ( ! V_38 ) ) {
V_25 = 1 ;
goto V_85;
}
V_38 -- ;
V_4 = V_70 -> V_76 [ V_38 ] ;
}
V_25 = F_37 ( V_49 , V_70 , V_72 , V_35 , V_38 , V_73 ,
V_7 , V_74 ) ;
V_85:
V_70 -> V_90 = 0 ;
F_57 ( V_70 ) ;
return V_25 ;
}
static struct V_8 *
F_58 ( struct V_91 * V_89 )
{
if ( ! V_89 )
return NULL ;
return (struct V_8 * ) ( V_92 ) V_89 -> V_93 ;
}
static int F_59 ( struct V_44 * V_45 ,
struct V_69 * V_70 , T_1 V_73 ,
struct V_63 * V_63 ,
const T_1 * V_7 , T_1 V_74 ,
struct V_28 * V_29 )
{
int V_94 ;
int V_25 = 0 ;
struct V_71 * V_72 ;
struct V_91 * V_89 ;
struct V_95 V_96 ;
struct V_50 * V_97 ;
V_72 = F_60 ( V_14 ) ;
if ( ! V_72 )
return - V_15 ;
while ( ( V_97 = F_61 ( & V_63 -> V_66 . V_49 ) ) ) {
struct V_33 * V_35 ;
V_35 = F_26 ( V_97 , struct V_33 , V_53 ) ;
if ( F_62 ( V_35 -> V_41 ,
L_3 ) ) {
V_25 = - V_98 ;
goto V_85;
}
F_63 ( & V_35 -> V_53 , & V_63 -> V_66 . V_49 ) ;
V_63 -> V_66 . V_57 -- ;
if ( V_35 -> V_57 == 0 ) {
F_21 ( V_35 ) ;
continue;
}
if ( V_29 && V_29 -> V_99 &&
V_35 -> V_39 != V_29 -> V_99 ) {
F_21 ( V_35 ) ;
V_25 = V_31 ;
goto V_85;
}
V_94 = F_44 ( V_45 , V_70 , V_73 , V_35 ,
V_72 , V_7 ,
V_74 ) ;
if ( V_94 == - V_86 ) {
F_25 ( V_45 , & V_63 -> V_64 , V_35 ,
NULL ) ;
continue;
} else if ( V_94 ) {
F_21 ( V_35 ) ;
V_25 = V_94 ;
goto V_85;
}
F_64 ( & V_96 ) ;
V_89 = F_65 ( V_72 , & V_96 ) ;
V_35 -> V_41 = V_89 ? V_89 -> V_100 : 0 ;
V_35 -> V_56 = F_58 ( V_89 ) ;
while ( ( V_89 = F_65 ( V_72 , & V_96 ) ) ) {
struct V_33 * V_101 ;
V_101 = F_34 ( V_32 ,
V_14 ) ;
if ( ! V_101 ) {
F_21 ( V_35 ) ;
V_25 = - V_15 ;
goto V_85;
}
memcpy ( V_101 , V_35 , sizeof( * V_35 ) ) ;
V_101 -> V_41 = V_89 -> V_100 ;
V_101 -> V_56 = F_58 ( V_89 ) ;
F_25 ( V_45 , & V_63 -> V_64 ,
V_101 , NULL ) ;
}
F_25 ( V_45 , & V_63 -> V_64 , V_35 , NULL ) ;
F_66 ( V_72 ) ;
F_67 () ;
}
V_85:
F_68 ( V_72 ) ;
return V_25 ;
}
static int F_69 ( struct V_44 * V_45 ,
struct V_63 * V_63 )
{
struct V_33 * V_35 ;
struct V_3 * V_4 ;
struct V_46 * V_65 = & V_63 -> V_67 ;
struct V_50 * V_89 ;
while ( ( V_89 = F_61 ( & V_65 -> V_49 ) ) ) {
V_35 = F_26 ( V_89 , struct V_33 , V_53 ) ;
F_63 ( V_89 , & V_65 -> V_49 ) ;
F_70 ( V_35 -> V_41 ) ;
F_70 ( V_35 -> V_40 . type ) ;
F_70 ( ! V_35 -> V_20 ) ;
V_4 = F_71 ( V_45 , V_35 -> V_20 , 0 ) ;
if ( F_47 ( V_4 ) ) {
F_21 ( V_35 ) ;
return F_49 ( V_4 ) ;
} else if ( ! F_72 ( V_4 ) ) {
F_21 ( V_35 ) ;
F_73 ( V_4 ) ;
return - V_102 ;
}
F_74 ( V_4 ) ;
if ( F_51 ( V_4 ) == 0 )
F_12 ( V_4 , & V_35 -> V_40 , 0 ) ;
else
F_75 ( V_4 , & V_35 -> V_40 , 0 ) ;
F_76 ( V_4 ) ;
F_73 ( V_4 ) ;
F_25 ( V_45 , & V_63 -> V_66 , V_35 , NULL ) ;
F_67 () ;
}
return 0 ;
}
static int F_77 ( const struct V_44 * V_45 ,
struct V_103 * V_104 , T_1 V_105 ,
struct V_63 * V_63 , T_1 * V_74 ,
struct V_28 * V_29 )
{
struct V_106 * V_89 ;
struct V_107 * V_108 = V_104 -> V_108 ;
struct V_1 V_2 ;
struct V_1 V_109 ;
struct V_1 * V_110 = NULL ;
int V_57 ;
int V_25 = 0 ;
if ( V_108 && V_108 -> V_111 ) {
F_78 ( & V_109 , & V_108 -> V_2 ) ;
V_110 = & V_109 ;
}
F_79 ( & V_104 -> V_112 ) ;
F_80 (node, &head->ref_list, list) {
if ( V_89 -> V_105 > V_105 )
continue;
switch ( V_89 -> V_113 ) {
case V_114 :
case V_115 :
F_56 ( 1 ) ;
continue;
case V_116 :
V_57 = V_89 -> V_117 ;
break;
case V_118 :
V_57 = V_89 -> V_117 * - 1 ;
break;
default:
F_70 ( 1 ) ;
}
* V_74 += V_57 ;
switch ( V_89 -> type ) {
case V_119 : {
struct V_120 * V_35 ;
V_35 = F_81 ( V_89 ) ;
V_25 = F_36 ( V_45 , V_63 , V_35 -> V_49 ,
& V_109 , V_35 -> V_38 + 1 ,
V_89 -> V_121 , V_57 , V_29 ,
V_122 ) ;
break;
}
case V_123 : {
struct V_120 * V_35 ;
V_35 = F_81 ( V_89 ) ;
V_25 = F_35 ( V_45 , V_63 , V_35 -> V_38 + 1 ,
V_35 -> V_41 , V_89 -> V_121 , V_57 ,
V_29 , V_122 ) ;
break;
}
case V_124 : {
struct V_125 * V_35 ;
V_35 = F_82 ( V_89 ) ;
V_2 . V_18 = V_35 -> V_18 ;
V_2 . type = V_26 ;
V_2 . V_10 = V_35 -> V_10 ;
if ( V_29 && V_29 -> V_17 && V_35 -> V_18 != V_29 -> V_17 ) {
V_25 = V_31 ;
goto V_85;
}
V_25 = F_36 ( V_45 , V_63 , V_35 -> V_49 ,
& V_2 , 0 , V_89 -> V_121 , V_57 , V_29 ,
V_122 ) ;
break;
}
case V_126 : {
struct V_125 * V_35 ;
V_35 = F_82 ( V_89 ) ;
V_25 = F_35 ( V_45 , V_63 , 0 , V_35 -> V_41 ,
V_89 -> V_121 , V_57 , V_29 ,
V_122 ) ;
break;
}
default:
F_56 ( 1 ) ;
}
if ( V_25 && ( V_25 != V_31 ) )
break;
}
if ( ! V_25 )
V_25 = F_16 ( V_29 ) ;
V_85:
F_83 ( & V_104 -> V_112 ) ;
return V_25 ;
}
static int F_84 ( const struct V_44 * V_45 ,
struct V_69 * V_70 , T_1 V_121 ,
int * V_127 , struct V_63 * V_63 ,
T_1 * V_74 , struct V_28 * V_29 )
{
int V_25 = 0 ;
int V_22 ;
struct V_3 * V_128 ;
struct V_1 V_2 ;
struct V_1 V_129 ;
unsigned long V_130 ;
unsigned long V_131 ;
struct V_132 * V_133 ;
T_1 V_134 ;
T_1 V_135 ;
V_128 = V_70 -> V_76 [ 0 ] ;
V_22 = V_70 -> V_78 [ 0 ] ;
V_135 = F_85 ( V_128 , V_22 ) ;
F_70 ( V_135 < sizeof( * V_133 ) ) ;
V_133 = F_13 ( V_128 , V_22 , struct V_132 ) ;
V_134 = F_86 ( V_128 , V_133 ) ;
* V_74 += F_87 ( V_128 , V_133 ) ;
F_12 ( V_128 , & V_129 , V_22 ) ;
V_130 = ( unsigned long ) ( V_133 + 1 ) ;
V_131 = ( unsigned long ) V_133 + V_135 ;
if ( V_129 . type == V_136 &&
V_134 & V_137 ) {
struct V_138 * V_139 ;
V_139 = (struct V_138 * ) V_130 ;
* V_127 = F_88 ( V_128 , V_139 ) ;
V_130 += sizeof( struct V_138 ) ;
F_70 ( V_130 > V_131 ) ;
} else if ( V_129 . type == V_140 ) {
* V_127 = V_129 . V_10 ;
} else {
F_70 ( ! ( V_134 & V_141 ) ) ;
}
while ( V_130 < V_131 ) {
struct V_142 * V_143 ;
T_1 V_10 ;
int type ;
V_143 = (struct V_142 * ) V_130 ;
type = F_89 ( V_128 , V_143 ,
V_144 ) ;
if ( type == V_145 )
return - V_98 ;
V_10 = F_90 ( V_128 , V_143 ) ;
switch ( type ) {
case V_123 :
V_25 = F_35 ( V_45 , V_63 ,
* V_127 + 1 , V_10 ,
V_121 , 1 , NULL , V_14 ) ;
break;
case V_126 : {
struct V_146 * V_147 ;
int V_57 ;
V_147 = (struct V_146 * ) ( V_143 + 1 ) ;
V_57 = F_91 ( V_128 , V_147 ) ;
V_25 = F_35 ( V_45 , V_63 , 0 , V_10 ,
V_121 , V_57 , V_29 , V_14 ) ;
break;
}
case V_119 :
V_25 = F_36 ( V_45 , V_63 , V_10 ,
NULL , * V_127 + 1 ,
V_121 , 1 , NULL , V_14 ) ;
break;
case V_124 : {
struct V_148 * V_149 ;
int V_57 ;
T_1 V_49 ;
V_149 = (struct V_148 * ) ( & V_143 -> V_10 ) ;
V_57 = F_92 ( V_128 , V_149 ) ;
V_2 . V_18 = F_93 ( V_128 ,
V_149 ) ;
V_2 . type = V_26 ;
V_2 . V_10 = F_94 ( V_128 , V_149 ) ;
if ( V_29 && V_29 -> V_17 && V_2 . V_18 != V_29 -> V_17 ) {
V_25 = V_31 ;
break;
}
V_49 = F_95 ( V_128 , V_149 ) ;
V_25 = F_36 ( V_45 , V_63 , V_49 ,
& V_2 , 0 , V_121 , V_57 ,
V_29 , V_14 ) ;
break;
}
default:
F_56 ( 1 ) ;
}
if ( V_25 )
return V_25 ;
V_130 += F_96 ( type ) ;
}
return 0 ;
}
static int F_97 ( struct V_44 * V_45 ,
struct V_69 * V_70 , T_1 V_121 ,
int V_127 , struct V_63 * V_63 ,
struct V_28 * V_29 )
{
struct V_68 * V_150 = V_45 -> V_150 ;
int V_25 ;
int V_22 ;
struct V_3 * V_128 ;
struct V_1 V_2 ;
while ( 1 ) {
V_25 = F_42 ( V_150 , V_70 ) ;
if ( V_25 < 0 )
break;
if ( V_25 ) {
V_25 = 0 ;
break;
}
V_22 = V_70 -> V_78 [ 0 ] ;
V_128 = V_70 -> V_76 [ 0 ] ;
F_12 ( V_128 , & V_2 , V_22 ) ;
if ( V_2 . V_18 != V_121 )
break;
if ( V_2 . type < V_119 )
continue;
if ( V_2 . type > V_126 )
break;
switch ( V_2 . type ) {
case V_123 :
V_25 = F_35 ( V_45 , V_63 ,
V_127 + 1 , V_2 . V_10 ,
V_121 , 1 , NULL , V_14 ) ;
break;
case V_126 : {
struct V_146 * V_147 ;
int V_57 ;
V_147 = F_13 ( V_128 , V_22 ,
struct V_146 ) ;
V_57 = F_91 ( V_128 , V_147 ) ;
V_25 = F_35 ( V_45 , V_63 , 0 ,
V_2 . V_10 , V_121 , V_57 ,
V_29 , V_14 ) ;
break;
}
case V_119 :
V_25 = F_36 ( V_45 , V_63 , V_2 . V_10 ,
NULL , V_127 + 1 , V_121 ,
1 , NULL , V_14 ) ;
break;
case V_124 : {
struct V_148 * V_149 ;
int V_57 ;
T_1 V_49 ;
V_149 = F_13 ( V_128 , V_22 ,
struct V_148 ) ;
V_57 = F_92 ( V_128 , V_149 ) ;
V_2 . V_18 = F_93 ( V_128 ,
V_149 ) ;
V_2 . type = V_26 ;
V_2 . V_10 = F_94 ( V_128 , V_149 ) ;
if ( V_29 && V_29 -> V_17 && V_2 . V_18 != V_29 -> V_17 ) {
V_25 = V_31 ;
break;
}
V_49 = F_95 ( V_128 , V_149 ) ;
V_25 = F_36 ( V_45 , V_63 , V_49 ,
& V_2 , 0 , V_121 , V_57 ,
V_29 , V_14 ) ;
break;
}
default:
F_56 ( 1 ) ;
}
if ( V_25 )
return V_25 ;
}
return V_25 ;
}
static void F_98 ( struct V_71 * V_151 )
{
struct V_91 * V_89 = NULL ;
struct V_8 * V_9 ;
struct V_95 V_96 ;
F_64 ( & V_96 ) ;
while ( ( V_89 = F_65 ( V_151 , & V_96 ) ) ) {
if ( ! V_89 -> V_93 )
continue;
V_9 = F_58 ( V_89 ) ;
F_8 ( V_9 ) ;
V_89 -> V_93 = 0 ;
}
F_68 ( V_151 ) ;
}
static int F_99 ( struct V_152 * V_153 ,
struct V_44 * V_45 , T_1 V_121 ,
T_1 V_73 , struct V_71 * * V_154 ,
const T_1 * V_7 )
{
int V_25 ;
* V_154 = F_60 ( V_14 ) ;
if ( ! * V_154 )
return - V_15 ;
V_25 = F_100 ( V_153 , V_45 , V_121 , V_73 ,
* V_154 , NULL , V_7 , NULL ) ;
if ( V_25 < 0 && V_25 != - V_86 ) {
F_98 ( * V_154 ) ;
return V_25 ;
}
return 0 ;
}
static int F_101 ( struct V_152 * V_153 ,
struct V_44 * V_45 , T_1 V_121 ,
T_1 V_73 , struct V_71 * * V_155 )
{
struct V_71 * V_156 ;
struct V_91 * V_89 = NULL ;
struct V_95 V_96 ;
int V_25 ;
V_156 = F_60 ( V_14 ) ;
if ( ! V_156 )
return - V_15 ;
* V_155 = F_60 ( V_14 ) ;
if ( ! * V_155 ) {
F_68 ( V_156 ) ;
return - V_15 ;
}
F_64 ( & V_96 ) ;
while ( 1 ) {
V_25 = F_100 ( V_153 , V_45 , V_121 , V_73 ,
V_156 , * V_155 , NULL , NULL ) ;
if ( V_25 < 0 && V_25 != - V_86 ) {
F_68 ( V_156 ) ;
F_68 ( * V_155 ) ;
return V_25 ;
}
V_89 = F_65 ( V_156 , & V_96 ) ;
if ( ! V_89 )
break;
V_121 = V_89 -> V_100 ;
F_67 () ;
}
F_68 ( V_156 ) ;
return 0 ;
}
int F_102 ( struct V_152 * V_153 ,
struct V_44 * V_45 , T_1 V_121 ,
T_1 V_73 , struct V_71 * * V_155 )
{
int V_25 ;
if ( ! V_153 )
F_103 ( & V_45 -> V_157 ) ;
V_25 = F_101 ( V_153 , V_45 , V_121 ,
V_73 , V_155 ) ;
if ( ! V_153 )
F_104 ( & V_45 -> V_157 ) ;
return V_25 ;
}
int F_105 ( struct V_68 * V_49 , T_1 V_17 , T_1 V_121 )
{
struct V_44 * V_45 = V_49 -> V_45 ;
struct V_152 * V_153 ;
struct V_71 * V_156 = NULL ;
struct V_71 * V_155 = NULL ;
struct V_95 V_96 ;
struct V_91 * V_89 ;
struct V_158 V_159 = F_106 ( V_159 ) ;
int V_25 = 0 ;
struct V_28 V_160 = {
. V_99 = V_49 -> V_18 ,
. V_17 = V_17 ,
. V_30 = 0 ,
} ;
V_156 = F_60 ( V_14 ) ;
V_155 = F_60 ( V_14 ) ;
if ( ! V_156 || ! V_155 ) {
F_68 ( V_156 ) ;
F_68 ( V_155 ) ;
return - V_15 ;
}
V_153 = F_107 ( V_49 ) ;
if ( F_47 ( V_153 ) ) {
V_153 = NULL ;
F_103 ( & V_45 -> V_157 ) ;
} else {
F_108 ( V_45 , & V_159 ) ;
}
F_64 ( & V_96 ) ;
while ( 1 ) {
V_25 = F_100 ( V_153 , V_45 , V_121 , V_159 . V_105 , V_156 ,
V_155 , NULL , & V_160 ) ;
if ( V_25 == V_31 ) {
V_25 = 1 ;
break;
}
if ( V_25 < 0 && V_25 != - V_86 )
break;
V_25 = 0 ;
V_89 = F_65 ( V_156 , & V_96 ) ;
if ( ! V_89 )
break;
V_121 = V_89 -> V_100 ;
F_67 () ;
}
if ( V_153 ) {
F_109 ( V_45 , & V_159 ) ;
F_110 ( V_153 ) ;
} else {
F_104 ( & V_45 -> V_157 ) ;
}
F_68 ( V_156 ) ;
F_68 ( V_155 ) ;
return V_25 ;
}
int F_111 ( struct V_68 * V_49 , T_1 V_161 ,
T_1 V_162 , struct V_69 * V_70 ,
struct V_163 * * V_164 ,
T_1 * V_165 )
{
int V_25 , V_22 ;
struct V_1 V_2 ;
struct V_1 V_129 ;
struct V_163 * V_166 ;
const struct V_3 * V_128 ;
unsigned long V_130 ;
V_2 . V_18 = V_161 ;
V_2 . type = V_167 ;
V_2 . V_10 = V_162 ;
V_25 = F_53 ( NULL , V_49 , & V_2 , V_70 , 0 , 0 ) ;
if ( V_25 < 0 )
return V_25 ;
while ( 1 ) {
V_128 = V_70 -> V_76 [ 0 ] ;
V_22 = V_70 -> V_78 [ 0 ] ;
if ( V_22 >= F_11 ( V_128 ) ) {
V_25 = F_39 ( V_49 , V_70 ) ;
if ( V_25 ) {
if ( V_25 >= 1 )
V_25 = - V_86 ;
break;
}
continue;
}
F_12 ( V_128 , & V_129 , V_22 ) ;
V_25 = - V_86 ;
if ( V_129 . V_18 != V_161 )
break;
if ( V_129 . type != V_167 )
break;
V_25 = 0 ;
V_130 = F_112 ( V_128 , V_70 -> V_78 [ 0 ] ) ;
V_166 = (struct V_163 * ) V_130 ;
* V_164 = V_166 ;
if ( V_165 )
* V_165 = V_129 . V_10 ;
break;
}
return V_25 ;
}
char * F_113 ( struct V_68 * V_168 , struct V_69 * V_70 ,
T_4 V_169 , unsigned long V_170 ,
struct V_3 * V_171 , T_1 V_41 ,
char * V_172 , T_4 V_173 )
{
int V_22 ;
T_1 V_174 ;
int V_25 ;
T_5 V_175 = ( ( T_5 ) V_173 ) - 1 ;
struct V_3 * V_4 = V_171 ;
struct V_1 V_129 ;
int V_176 = V_70 -> V_176 ;
struct V_177 * V_143 ;
if ( V_175 >= 0 )
V_172 [ V_175 ] = '\0' ;
V_70 -> V_176 = 1 ;
while ( 1 ) {
V_175 -= V_169 ;
if ( V_175 >= 0 )
F_114 ( V_4 , V_172 + V_175 ,
V_170 , V_169 ) ;
if ( V_4 != V_171 ) {
if ( ! V_70 -> V_178 )
F_115 ( V_4 ) ;
F_73 ( V_4 ) ;
}
V_25 = F_116 ( V_168 , V_70 , V_41 , 0 ,
V_179 , & V_129 ) ;
if ( V_25 > 0 )
V_25 = - V_86 ;
if ( V_25 )
break;
V_174 = V_129 . V_10 ;
if ( V_41 == V_174 )
break;
V_22 = V_70 -> V_78 [ 0 ] ;
V_4 = V_70 -> V_76 [ 0 ] ;
if ( V_4 != V_171 ) {
if ( ! V_70 -> V_178 )
F_117 ( V_4 , V_180 ) ;
V_70 -> V_76 [ 0 ] = NULL ;
V_70 -> V_181 [ 0 ] = 0 ;
}
F_57 ( V_70 ) ;
V_143 = F_13 ( V_4 , V_22 , struct V_177 ) ;
V_169 = F_118 ( V_4 , V_143 ) ;
V_170 = ( unsigned long ) ( V_143 + 1 ) ;
V_41 = V_174 ;
-- V_175 ;
if ( V_175 >= 0 )
V_172 [ V_175 ] = '/' ;
}
F_57 ( V_70 ) ;
V_70 -> V_176 = V_176 ;
if ( V_25 )
return F_119 ( V_25 ) ;
return V_172 + V_175 ;
}
int F_120 ( struct V_44 * V_45 , T_1 V_182 ,
struct V_69 * V_70 , struct V_1 * V_129 ,
T_1 * V_183 )
{
int V_25 ;
T_1 V_134 ;
T_1 V_173 = 0 ;
T_4 V_135 ;
const struct V_3 * V_4 ;
struct V_132 * V_133 ;
struct V_1 V_2 ;
if ( F_121 ( V_45 , V_184 ) )
V_2 . type = V_140 ;
else
V_2 . type = V_136 ;
V_2 . V_18 = V_182 ;
V_2 . V_10 = ( T_1 ) - 1 ;
V_25 = F_53 ( NULL , V_45 -> V_150 , & V_2 , V_70 , 0 , 0 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_122 ( V_45 -> V_150 , V_70 , 0 ) ;
if ( V_25 ) {
if ( V_25 > 0 )
V_25 = - V_86 ;
return V_25 ;
}
F_12 ( V_70 -> V_76 [ 0 ] , V_129 , V_70 -> V_78 [ 0 ] ) ;
if ( V_129 -> type == V_140 )
V_173 = V_45 -> V_185 ;
else if ( V_129 -> type == V_136 )
V_173 = V_129 -> V_10 ;
if ( V_129 -> V_18 > V_182 ||
V_129 -> V_18 + V_173 <= V_182 ) {
F_55 ( V_45 ,
L_4 , V_182 ) ;
return - V_86 ;
}
V_4 = V_70 -> V_76 [ 0 ] ;
V_135 = F_85 ( V_4 , V_70 -> V_78 [ 0 ] ) ;
F_70 ( V_135 < sizeof( * V_133 ) ) ;
V_133 = F_13 ( V_4 , V_70 -> V_78 [ 0 ] , struct V_132 ) ;
V_134 = F_86 ( V_4 , V_133 ) ;
F_55 ( V_45 ,
L_5 ,
V_182 , V_182 - V_129 -> V_18 , V_129 -> V_18 ,
V_129 -> V_10 , V_134 , V_135 ) ;
F_56 ( ! V_183 ) ;
if ( V_183 ) {
if ( V_134 & V_137 )
* V_183 = V_137 ;
else if ( V_134 & V_141 )
* V_183 = V_141 ;
else
F_70 ( 1 ) ;
return 0 ;
}
return - V_102 ;
}
static int F_123 ( unsigned long * V_130 ,
const struct V_3 * V_4 ,
const struct V_1 * V_2 ,
const struct V_132 * V_133 ,
T_4 V_135 ,
struct V_142 * * V_186 ,
int * V_187 )
{
unsigned long V_131 ;
T_1 V_134 ;
struct V_138 * V_139 ;
if ( ! * V_130 ) {
V_134 = F_86 ( V_4 , V_133 ) ;
if ( V_134 & V_137 ) {
if ( V_2 -> type == V_140 ) {
* V_186 =
(struct V_142 * ) ( V_133 + 1 ) ;
} else {
F_56 ( V_2 -> type != V_136 ) ;
V_139 = (struct V_138 * ) ( V_133 + 1 ) ;
* V_186 =
(struct V_142 * ) ( V_139 + 1 ) ;
}
} else {
* V_186 = (struct V_142 * ) ( V_133 + 1 ) ;
}
* V_130 = ( unsigned long ) * V_186 ;
if ( ( unsigned long ) ( * V_130 ) >= ( unsigned long ) V_133 + V_135 )
return - V_86 ;
}
V_131 = ( unsigned long ) V_133 + V_135 ;
* V_186 = (struct V_142 * ) ( * V_130 ) ;
* V_187 = F_89 ( V_4 , * V_186 ,
V_144 ) ;
if ( * V_187 == V_145 )
return - V_98 ;
* V_130 += F_96 ( * V_187 ) ;
F_56 ( * V_130 > V_131 ) ;
if ( * V_130 == V_131 )
return 1 ;
return 0 ;
}
int F_124 ( unsigned long * V_130 , struct V_3 * V_4 ,
struct V_1 * V_2 , struct V_132 * V_133 ,
T_4 V_135 , T_1 * V_188 , T_6 * V_189 )
{
int V_25 ;
int type ;
struct V_142 * V_190 ;
if ( * V_130 == ( unsigned long ) - 1 )
return 1 ;
while ( 1 ) {
V_25 = F_123 ( V_130 , V_4 , V_2 , V_133 , V_135 ,
& V_190 , & type ) ;
if ( V_25 < 0 )
return V_25 ;
if ( type == V_119 ||
type == V_123 )
break;
if ( V_25 == 1 )
return 1 ;
}
* V_188 = F_90 ( V_4 , V_190 ) ;
if ( V_2 -> type == V_136 ) {
struct V_138 * V_139 ;
V_139 = (struct V_138 * ) ( V_133 + 1 ) ;
* V_189 = F_88 ( V_4 , V_139 ) ;
} else {
ASSERT ( V_2 -> type == V_140 ) ;
* V_189 = ( T_6 ) V_2 -> V_10 ;
}
if ( V_25 == 1 )
* V_130 = ( unsigned long ) - 1 ;
return 0 ;
}
static int F_125 ( struct V_44 * V_45 ,
struct V_8 * V_56 ,
T_1 V_49 , T_1 V_191 ,
T_7 * V_192 , void * V_193 )
{
struct V_8 * V_9 ;
int V_25 = 0 ;
for ( V_9 = V_56 ; V_9 ; V_9 = V_9 -> V_16 ) {
F_55 ( V_45 ,
L_6 ,
V_191 , V_9 -> V_17 ,
V_9 -> V_10 , V_49 ) ;
V_25 = V_192 ( V_9 -> V_17 , V_9 -> V_10 , V_49 , V_193 ) ;
if ( V_25 ) {
F_55 ( V_45 ,
L_7 ,
V_191 , V_25 ) ;
break;
}
}
return V_25 ;
}
int F_126 ( struct V_44 * V_45 ,
T_1 V_191 , T_1 V_7 ,
int V_87 ,
T_7 * V_192 , void * V_193 )
{
int V_25 ;
struct V_152 * V_153 = NULL ;
struct V_71 * V_194 = NULL ;
struct V_71 * V_155 = NULL ;
struct V_91 * V_195 = NULL ;
struct V_91 * V_196 = NULL ;
struct V_158 V_197 = F_106 ( V_197 ) ;
struct V_95 V_198 ;
struct V_95 V_199 ;
F_55 ( V_45 , L_8 ,
V_191 ) ;
if ( ! V_87 ) {
V_153 = F_107 ( V_45 -> V_150 ) ;
if ( F_47 ( V_153 ) )
return F_49 ( V_153 ) ;
F_108 ( V_45 , & V_197 ) ;
} else {
F_103 ( & V_45 -> V_157 ) ;
}
V_25 = F_99 ( V_153 , V_45 , V_191 ,
V_197 . V_105 , & V_194 ,
& V_7 ) ;
if ( V_25 )
goto V_85;
F_64 ( & V_198 ) ;
while ( ! V_25 && ( V_195 = F_65 ( V_194 , & V_198 ) ) ) {
V_25 = F_101 ( V_153 , V_45 , V_195 -> V_100 ,
V_197 . V_105 , & V_155 ) ;
if ( V_25 )
break;
F_64 ( & V_199 ) ;
while ( ! V_25 && ( V_196 = F_65 ( V_155 , & V_199 ) ) ) {
F_55 ( V_45 ,
L_9 ,
V_196 -> V_100 , V_195 -> V_100 ,
V_195 -> V_93 ) ;
V_25 = F_125 ( V_45 ,
(struct V_8 * )
( V_92 ) V_195 -> V_93 ,
V_196 -> V_100 ,
V_191 ,
V_192 , V_193 ) ;
}
F_68 ( V_155 ) ;
}
F_98 ( V_194 ) ;
V_85:
if ( ! V_87 ) {
F_109 ( V_45 , & V_197 ) ;
F_110 ( V_153 ) ;
} else {
F_104 ( & V_45 -> V_157 ) ;
}
return V_25 ;
}
int F_127 ( T_1 V_182 , struct V_44 * V_45 ,
struct V_69 * V_70 ,
T_7 * V_192 , void * V_193 )
{
int V_25 ;
T_1 V_7 ;
T_1 V_134 = 0 ;
struct V_1 V_129 ;
int V_87 = V_70 -> V_87 ;
V_25 = F_120 ( V_45 , V_182 , V_70 , & V_129 , & V_134 ) ;
F_57 ( V_70 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_134 & V_137 )
return - V_98 ;
V_7 = V_182 - V_129 . V_18 ;
V_25 = F_126 ( V_45 , V_129 . V_18 ,
V_7 , V_87 ,
V_192 , V_193 ) ;
return V_25 ;
}
static int F_128 ( T_1 V_17 , struct V_68 * V_168 ,
struct V_69 * V_70 ,
T_8 * V_192 , void * V_193 )
{
int V_25 = 0 ;
int V_22 ;
T_4 V_200 ;
T_4 V_201 ;
T_4 V_169 ;
T_1 V_41 = 0 ;
int V_202 = 0 ;
struct V_3 * V_4 ;
struct V_203 * V_204 ;
struct V_177 * V_143 ;
struct V_1 V_129 ;
while ( ! V_25 ) {
V_25 = F_116 ( V_168 , V_70 , V_17 ,
V_41 ? V_41 + 1 : 0 , V_179 ,
& V_129 ) ;
if ( V_25 < 0 )
break;
if ( V_25 ) {
V_25 = V_202 ? 0 : - V_86 ;
break;
}
++ V_202 ;
V_41 = V_129 . V_10 ;
V_22 = V_70 -> V_78 [ 0 ] ;
V_4 = F_129 ( V_70 -> V_76 [ 0 ] ) ;
if ( ! V_4 ) {
V_25 = - V_15 ;
break;
}
F_130 ( V_4 ) ;
F_74 ( V_4 ) ;
F_117 ( V_4 , V_180 ) ;
F_57 ( V_70 ) ;
V_204 = F_131 ( V_22 ) ;
V_143 = F_13 ( V_4 , V_22 , struct V_177 ) ;
for ( V_200 = 0 ; V_200 < F_132 ( V_4 , V_204 ) ; V_200 += V_201 ) {
V_169 = F_118 ( V_4 , V_143 ) ;
F_55 ( V_168 -> V_45 ,
L_10 ,
V_200 , V_129 . V_18 , V_168 -> V_18 ) ;
V_25 = V_192 ( V_41 , V_169 ,
( unsigned long ) ( V_143 + 1 ) , V_4 , V_193 ) ;
if ( V_25 )
break;
V_201 = sizeof( * V_143 ) + V_169 ;
V_143 = (struct V_177 * ) ( ( char * ) V_143 + V_201 ) ;
}
F_115 ( V_4 ) ;
F_73 ( V_4 ) ;
}
F_57 ( V_70 ) ;
return V_25 ;
}
static int F_133 ( T_1 V_17 , struct V_68 * V_168 ,
struct V_69 * V_70 ,
T_8 * V_192 , void * V_193 )
{
int V_25 ;
int V_22 ;
T_1 V_10 = 0 ;
T_1 V_41 ;
int V_202 = 0 ;
struct V_3 * V_4 ;
struct V_163 * V_166 ;
T_4 V_135 ;
T_4 V_205 ;
unsigned long V_130 ;
while ( 1 ) {
V_25 = F_111 ( V_168 , V_17 , V_10 , V_70 , & V_166 ,
& V_10 ) ;
if ( V_25 < 0 )
break;
if ( V_25 ) {
V_25 = V_202 ? 0 : - V_86 ;
break;
}
++ V_202 ;
V_22 = V_70 -> V_78 [ 0 ] ;
V_4 = F_129 ( V_70 -> V_76 [ 0 ] ) ;
if ( ! V_4 ) {
V_25 = - V_15 ;
break;
}
F_130 ( V_4 ) ;
F_74 ( V_4 ) ;
F_117 ( V_4 , V_180 ) ;
F_57 ( V_70 ) ;
V_135 = F_85 ( V_4 , V_22 ) ;
V_130 = F_112 ( V_4 , V_22 ) ;
V_205 = 0 ;
while ( V_205 < V_135 ) {
T_4 V_169 ;
V_166 = (struct V_163 * ) ( V_130 + V_205 ) ;
V_41 = F_134 ( V_4 , V_166 ) ;
V_169 = F_135 ( V_4 , V_166 ) ;
V_25 = V_192 ( V_41 , V_169 ,
( unsigned long ) & V_166 -> V_206 , V_4 , V_193 ) ;
if ( V_25 )
break;
V_205 += F_135 ( V_4 , V_166 ) ;
V_205 += sizeof( * V_166 ) ;
}
F_115 ( V_4 ) ;
F_73 ( V_4 ) ;
V_10 ++ ;
}
F_57 ( V_70 ) ;
return V_25 ;
}
static int F_136 ( T_1 V_17 , struct V_68 * V_168 ,
struct V_69 * V_70 , T_8 * V_192 ,
void * V_193 )
{
int V_25 ;
int V_207 = 0 ;
V_25 = F_128 ( V_17 , V_168 , V_70 , V_192 , V_193 ) ;
if ( ! V_25 )
++ V_207 ;
else if ( V_25 != - V_86 )
return V_25 ;
V_25 = F_133 ( V_17 , V_168 , V_70 , V_192 , V_193 ) ;
if ( V_25 == - V_86 && V_207 )
return 0 ;
return V_25 ;
}
static int F_137 ( T_1 V_17 , T_4 V_169 , unsigned long V_170 ,
struct V_3 * V_4 , void * V_193 )
{
struct V_208 * V_209 = V_193 ;
char * V_210 ;
char * V_211 ;
int V_212 = V_209 -> V_210 -> V_213 ;
const int V_214 = sizeof( char * ) ;
T_4 V_175 ;
V_175 = V_209 -> V_210 -> V_175 > V_214 ?
V_209 -> V_210 -> V_175 - V_214 : 0 ;
V_211 = ( char * ) V_209 -> V_210 -> V_100 + ( V_212 + 1 ) * V_214 ;
V_210 = F_113 ( V_209 -> V_168 , V_209 -> V_69 , V_169 ,
V_170 , V_4 , V_17 , V_211 , V_175 ) ;
if ( F_47 ( V_210 ) )
return F_49 ( V_210 ) ;
if ( V_210 > V_211 ) {
V_209 -> V_210 -> V_100 [ V_212 ] = ( T_1 ) ( unsigned long ) V_210 ;
++ V_209 -> V_210 -> V_213 ;
V_209 -> V_210 -> V_175 = V_210 - V_211 ;
} else {
++ V_209 -> V_210 -> V_215 ;
V_209 -> V_210 -> V_216 += V_211 - V_210 ;
V_209 -> V_210 -> V_175 = 0 ;
}
return 0 ;
}
int F_138 ( T_1 V_17 , struct V_208 * V_209 )
{
return F_136 ( V_17 , V_209 -> V_168 , V_209 -> V_69 ,
F_137 , V_209 ) ;
}
struct V_217 * F_139 ( T_4 V_218 )
{
struct V_217 * V_219 ;
T_9 V_220 ;
V_220 = F_140 ( T_9 , V_218 , sizeof( * V_219 ) ) ;
V_219 = F_141 ( V_220 , V_221 ) ;
if ( ! V_219 )
return F_119 ( - V_15 ) ;
if ( V_218 >= sizeof( * V_219 ) ) {
V_219 -> V_175 = V_218 - sizeof( * V_219 ) ;
V_219 -> V_216 = 0 ;
} else {
V_219 -> V_216 = sizeof( * V_219 ) - V_218 ;
V_219 -> V_175 = 0 ;
}
V_219 -> V_213 = 0 ;
V_219 -> V_215 = 0 ;
return V_219 ;
}
struct V_208 * F_142 ( T_10 V_218 , struct V_68 * V_168 ,
struct V_69 * V_70 )
{
struct V_208 * V_222 ;
struct V_217 * V_210 ;
V_210 = F_139 ( V_218 ) ;
if ( F_47 ( V_210 ) )
return ( void * ) V_210 ;
V_222 = F_7 ( sizeof( * V_222 ) , V_221 ) ;
if ( ! V_222 ) {
F_143 ( V_210 ) ;
return F_119 ( - V_15 ) ;
}
V_222 -> V_69 = V_70 ;
V_222 -> V_210 = V_210 ;
V_222 -> V_168 = V_168 ;
return V_222 ;
}
void F_144 ( struct V_208 * V_209 )
{
if ( ! V_209 )
return;
F_143 ( V_209 -> V_210 ) ;
F_9 ( V_209 ) ;
}
