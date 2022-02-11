int T_1 F_1 ( void )
{
V_1 = F_2 ( L_1 ,
sizeof( struct V_2 ) ,
0 ,
V_3 ,
NULL ) ;
if ( ! V_1 )
return - V_4 ;
return 0 ;
}
void F_3 ( void )
{
F_4 ( V_1 ) ;
}
static inline void F_5 (
struct V_2 * V_5 ,
struct V_6 * V_7 , T_2 V_8 )
{
V_5 -> V_7 = V_7 ;
V_5 -> V_8 = V_8 ;
F_6 ( & V_5 -> V_9 , 0 ) ;
V_5 -> V_10 = V_11 ;
V_5 -> V_12 = V_11 ;
F_7 ( & V_5 -> V_13 ) ;
F_8 ( & V_5 -> V_14 ) ;
F_8 ( & V_5 -> V_15 ) ;
}
static inline int F_9 (
struct V_16 * V_17 ,
struct V_16 * V_18 )
{
if ( V_17 -> V_19 . type == V_20 &&
V_17 -> V_19 . V_21 == V_18 -> V_19 . V_21 &&
V_17 -> V_19 . type == V_18 -> V_19 . type &&
V_17 -> V_19 . V_22 + 1 == V_18 -> V_19 . V_22 )
return 1 ;
return 0 ;
}
static struct V_2 * F_10 (
struct V_23 * V_23 )
{
struct V_6 * V_7 = V_23 -> V_7 ;
T_2 V_24 = F_11 ( V_23 ) ;
struct V_2 * V_25 ;
V_25 = F_12 ( V_23 -> V_5 ) ;
if ( V_25 ) {
F_13 ( & V_25 -> V_9 ) ;
return V_25 ;
}
F_14 ( & V_7 -> V_26 ) ;
V_25 = F_15 ( & V_7 -> V_27 , V_24 ) ;
if ( V_25 ) {
if ( V_23 -> V_5 ) {
F_13 ( & V_25 -> V_9 ) ;
F_16 ( V_23 -> V_5 != V_25 ) ;
F_17 ( & V_7 -> V_26 ) ;
return V_25 ;
}
V_23 -> V_5 = V_25 ;
F_18 ( 2 , & V_25 -> V_9 ) ;
F_17 ( & V_7 -> V_26 ) ;
return V_25 ;
}
F_17 ( & V_7 -> V_26 ) ;
return NULL ;
}
static struct V_2 * F_19 (
struct V_23 * V_23 )
{
struct V_2 * V_25 ;
struct V_6 * V_7 = V_23 -> V_7 ;
T_2 V_24 = F_11 ( V_23 ) ;
int V_28 ;
V_29:
V_25 = F_10 ( V_23 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_20 ( V_1 , V_30 ) ;
if ( ! V_25 )
return F_21 ( - V_4 ) ;
F_5 ( V_25 , V_7 , V_24 ) ;
F_6 ( & V_25 -> V_9 , 2 ) ;
V_28 = F_22 ( V_30 ) ;
if ( V_28 ) {
F_23 ( V_1 , V_25 ) ;
return F_21 ( V_28 ) ;
}
F_14 ( & V_7 -> V_26 ) ;
V_28 = F_24 ( & V_7 -> V_27 , V_24 , V_25 ) ;
if ( V_28 == - V_31 ) {
F_17 ( & V_7 -> V_26 ) ;
F_23 ( V_1 , V_25 ) ;
F_25 () ;
goto V_29;
}
V_23 -> V_5 = V_25 ;
F_17 ( & V_7 -> V_26 ) ;
F_25 () ;
return V_25 ;
}
static void F_26 ( struct V_32 * V_7 ,
struct V_2 * V_25 ,
int V_33 )
{
F_14 ( & V_7 -> V_34 ) ;
if ( F_27 ( V_35 , & V_25 -> V_36 ) ) {
if ( ! F_28 ( & V_25 -> V_15 ) )
F_29 ( & V_25 -> V_15 , & V_7 -> V_37 ) ;
else if ( V_33 )
F_30 ( & V_25 -> V_15 , & V_7 -> V_37 ) ;
} else {
F_30 ( & V_25 -> V_14 , & V_7 -> V_38 ) ;
F_30 ( & V_25 -> V_15 , & V_7 -> V_37 ) ;
F_13 ( & V_25 -> V_9 ) ;
V_7 -> V_39 ++ ;
F_31 ( V_35 , & V_25 -> V_36 ) ;
}
F_17 ( & V_7 -> V_34 ) ;
}
static void F_32 ( struct V_32 * V_7 ,
struct V_2 * V_25 )
{
F_14 ( & V_7 -> V_34 ) ;
if ( F_27 ( V_35 , & V_25 -> V_36 ) ) {
V_7 -> V_39 -- ;
F_33 ( & V_25 -> V_9 ) ;
F_34 ( & V_25 -> V_14 ) ;
if ( ! F_28 ( & V_25 -> V_15 ) )
F_34 ( & V_25 -> V_15 ) ;
F_35 ( V_35 , & V_25 -> V_36 ) ;
}
F_17 ( & V_7 -> V_34 ) ;
}
static struct V_2 * F_36 (
struct V_32 * V_40 )
{
struct V_41 * V_42 ;
struct V_2 * V_25 = NULL ;
F_14 ( & V_40 -> V_34 ) ;
if ( F_28 ( & V_40 -> V_38 ) )
goto V_43;
V_42 = V_40 -> V_38 . V_44 ;
V_25 = F_37 ( V_42 , struct V_2 , V_14 ) ;
F_13 ( & V_25 -> V_9 ) ;
V_43:
F_17 ( & V_40 -> V_34 ) ;
return V_25 ;
}
static struct V_2 * F_38 (
struct V_2 * V_25 )
{
struct V_32 * V_40 ;
struct V_41 * V_42 ;
struct V_2 * V_44 = NULL ;
V_40 = V_25 -> V_7 -> V_45 -> V_40 ;
F_14 ( & V_40 -> V_34 ) ;
if ( ! F_27 ( V_35 , & V_25 -> V_36 ) ) {
if ( F_28 ( & V_40 -> V_38 ) )
goto V_43;
V_42 = V_40 -> V_38 . V_44 ;
} else if ( F_39 ( & V_25 -> V_14 , & V_40 -> V_38 ) )
goto V_43;
else
V_42 = V_25 -> V_14 . V_44 ;
V_44 = F_37 ( V_42 , struct V_2 , V_14 ) ;
F_13 ( & V_44 -> V_9 ) ;
V_43:
F_17 ( & V_40 -> V_34 ) ;
return V_44 ;
}
static void F_40 (
struct V_2 * V_5 ,
int V_33 )
{
struct V_32 * V_40 ;
if ( ! V_5 )
return;
V_40 = V_5 -> V_7 -> V_45 -> V_40 ;
F_41 ( & V_5 -> V_13 ) ;
if ( V_5 -> V_46 )
F_26 ( V_40 , V_5 , V_33 ) ;
else
F_32 ( V_40 , V_5 ) ;
F_42 ( & V_5 -> V_13 ) ;
if ( F_43 ( & V_5 -> V_9 ) ) {
bool free = false ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_14 ( & V_7 -> V_26 ) ;
if ( F_44 ( & V_5 -> V_9 ) == 0 ) {
F_45 ( & V_7 -> V_27 ,
V_5 -> V_8 ) ;
free = true ;
}
F_17 ( & V_7 -> V_26 ) ;
if ( free )
F_23 ( V_1 , V_5 ) ;
}
}
static inline void F_46 ( struct V_2 * V_25 )
{
F_40 ( V_25 , 0 ) ;
}
static struct V_2 * F_47 (
struct V_32 * V_40 )
{
struct V_41 * V_42 ;
struct V_2 * V_25 = NULL ;
F_14 ( & V_40 -> V_34 ) ;
if ( F_28 ( & V_40 -> V_37 ) )
goto V_43;
V_42 = V_40 -> V_37 . V_44 ;
F_34 ( V_42 ) ;
V_25 = F_37 ( V_42 , struct V_2 , V_15 ) ;
F_13 ( & V_25 -> V_9 ) ;
V_43:
F_17 ( & V_40 -> V_34 ) ;
return V_25 ;
}
static inline void F_48 (
struct V_2 * V_25 )
{
F_40 ( V_25 , 1 ) ;
}
static struct V_16 * F_49 ( T_3 V_47 )
{
struct V_16 * V_48 ;
V_48 = F_50 ( sizeof( * V_48 ) + V_47 , V_30 ) ;
if ( V_48 ) {
V_48 -> V_47 = V_47 ;
V_48 -> V_49 = 0 ;
V_48 -> V_50 = 0 ;
V_48 -> V_5 = NULL ;
F_6 ( & V_48 -> V_9 , 1 ) ;
}
return V_48 ;
}
static struct V_16 * F_51 (
struct V_51 * V_7 ,
struct V_52 * V_19 ,
struct V_16 * * V_53 ,
struct V_16 * * V_44 )
{
struct V_54 * V_25 , * V_55 = NULL ;
struct V_16 * V_56 = NULL ;
int V_28 = 0 ;
V_25 = V_7 -> V_54 ;
while ( V_25 ) {
V_56 = F_52 ( V_25 , struct V_16 ,
V_54 ) ;
V_55 = V_25 ;
V_28 = F_53 ( & V_56 -> V_19 , V_19 ) ;
if ( V_28 < 0 )
V_25 = V_25 -> V_57 ;
else if ( V_28 > 0 )
V_25 = V_25 -> V_58 ;
else
return V_56 ;
}
if ( V_53 ) {
if ( ! V_55 )
* V_53 = NULL ;
else if ( V_28 < 0 )
* V_53 = V_56 ;
else if ( ( V_25 = F_54 ( V_55 ) ) != NULL ) {
* V_53 = F_52 ( V_25 , struct V_16 ,
V_54 ) ;
} else
* V_53 = NULL ;
}
if ( V_44 ) {
if ( ! V_55 )
* V_44 = NULL ;
else if ( V_28 > 0 )
* V_44 = V_56 ;
else if ( ( V_25 = F_55 ( V_55 ) ) != NULL ) {
* V_44 = F_52 ( V_25 , struct V_16 ,
V_54 ) ;
} else
* V_44 = NULL ;
}
return NULL ;
}
static struct V_16 * F_56 (
struct V_2 * V_5 ,
struct V_52 * V_19 )
{
return F_51 ( & V_5 -> V_10 , V_19 ,
NULL , NULL ) ;
}
static int F_57 ( struct V_2 * V_5 ,
struct V_16 * V_59 ,
int V_60 )
{
struct V_54 * * V_42 , * V_25 ;
struct V_54 * V_61 = NULL ;
struct V_51 * V_7 ;
struct V_16 * V_48 ;
int V_62 ;
if ( V_60 == V_63 )
V_7 = & V_5 -> V_10 ;
else if ( V_60 == V_64 )
V_7 = & V_5 -> V_12 ;
else
F_58 () ;
V_42 = & V_7 -> V_54 ;
V_25 = & V_59 -> V_54 ;
while ( * V_42 ) {
V_61 = * V_42 ;
V_48 = F_52 ( V_61 , struct V_16 ,
V_54 ) ;
V_62 = F_53 ( & V_48 -> V_19 , & V_59 -> V_19 ) ;
if ( V_62 < 0 )
V_42 = & ( * V_42 ) -> V_57 ;
else if ( V_62 > 0 )
V_42 = & ( * V_42 ) -> V_58 ;
else
return - V_31 ;
}
F_59 ( V_25 , V_61 , V_42 ) ;
F_60 ( V_25 , V_7 ) ;
V_59 -> V_5 = V_5 ;
V_59 -> V_49 = V_60 ;
if ( V_59 -> V_19 . type == V_20 &&
V_60 == V_63 &&
V_59 -> V_19 . V_22 >= V_5 -> V_65 )
V_5 -> V_65 = V_59 -> V_19 . V_22 + 1 ;
V_5 -> V_46 ++ ;
F_61 ( & V_5 -> V_7 -> V_45 -> V_40 -> V_66 ) ;
return 0 ;
}
static int F_62 ( struct V_2 * V_25 ,
struct V_16 * V_48 )
{
return F_57 ( V_25 , V_48 ,
V_63 ) ;
}
static int F_63 ( struct V_2 * V_25 ,
struct V_16 * V_48 )
{
return F_57 ( V_25 , V_48 ,
V_64 ) ;
}
static void F_64 ( struct V_32 * V_40 )
{
int V_67 = F_65 ( & V_40 -> V_68 ) ;
if ( ( F_66 ( & V_40 -> V_66 ) <
V_69 || V_67 % V_70 == 0 ) &&
F_67 ( & V_40 -> V_71 ) )
F_68 ( & V_40 -> V_71 ) ;
}
static void F_69 ( struct V_16 * V_56 )
{
struct V_51 * V_7 ;
struct V_32 * V_40 ;
V_40 = V_56 -> V_5 -> V_7 -> V_45 -> V_40 ;
F_16 ( ! V_40 ) ;
F_16 ( V_56 -> V_49 != V_64 &&
V_56 -> V_49 != V_63 ) ;
if ( V_56 -> V_49 == V_63 )
V_7 = & V_56 -> V_5 -> V_10 ;
else
V_7 = & V_56 -> V_5 -> V_12 ;
F_70 ( & V_56 -> V_54 , V_7 ) ;
V_56 -> V_5 -> V_46 -- ;
F_64 ( V_40 ) ;
}
static void F_71 ( struct V_16 * V_48 )
{
if ( V_48 ) {
F_69 ( V_48 ) ;
if ( F_43 ( & V_48 -> V_9 ) )
F_72 ( V_48 ) ;
}
}
static struct V_16 * F_73 (
struct V_2 * V_5 )
{
struct V_54 * V_42 ;
struct V_16 * V_48 = NULL ;
V_42 = F_74 ( & V_5 -> V_10 ) ;
if ( V_42 )
V_48 = F_52 ( V_42 , struct V_16 , V_54 ) ;
return V_48 ;
}
static struct V_16 * F_75 (
struct V_2 * V_5 )
{
struct V_54 * V_42 ;
struct V_16 * V_48 = NULL ;
V_42 = F_74 ( & V_5 -> V_12 ) ;
if ( V_42 )
V_48 = F_52 ( V_42 , struct V_16 , V_54 ) ;
return V_48 ;
}
static struct V_16 * F_76 (
struct V_16 * V_48 )
{
struct V_54 * V_42 ;
struct V_16 * V_44 = NULL ;
V_42 = F_55 ( & V_48 -> V_54 ) ;
if ( V_42 )
V_44 = F_52 ( V_42 , struct V_16 , V_54 ) ;
return V_44 ;
}
static int F_77 ( struct V_72 * V_73 ,
struct V_74 * V_45 ,
struct V_16 * V_48 )
{
struct V_75 * V_76 ;
struct V_75 * V_77 ;
T_2 V_78 ;
int V_28 ;
if ( ! V_73 -> V_50 )
return 0 ;
V_76 = V_73 -> V_79 ;
V_77 = & V_45 -> V_80 ;
V_78 = F_78 ( V_45 , 1 ) ;
V_28 = F_79 ( V_76 , V_77 , V_78 , 1 ) ;
if ( ! V_28 ) {
F_80 ( V_45 , L_2 ,
V_48 -> V_19 . V_21 ,
V_78 , 1 ) ;
V_48 -> V_50 = V_78 ;
}
return V_28 ;
}
static void F_81 ( struct V_74 * V_45 ,
struct V_16 * V_48 )
{
struct V_75 * V_81 ;
if ( ! V_48 -> V_50 )
return;
V_81 = & V_45 -> V_80 ;
F_80 ( V_45 , L_2 ,
V_48 -> V_19 . V_21 , V_48 -> V_50 ,
0 ) ;
F_82 ( V_45 , V_81 ,
V_48 -> V_50 ) ;
}
static int F_83 (
struct V_72 * V_73 ,
struct V_6 * V_7 ,
struct V_23 * V_82 ,
struct V_2 * V_25 )
{
struct V_74 * V_45 = V_7 -> V_45 ;
struct V_75 * V_76 ;
struct V_75 * V_77 ;
T_2 V_78 ;
int V_28 ;
bool V_83 = false ;
V_76 = V_73 -> V_79 ;
V_77 = & V_45 -> V_80 ;
V_78 = F_78 ( V_45 , 1 ) ;
if ( V_76 && V_76 -> type == V_84 ) {
F_14 ( & V_82 -> V_34 ) ;
if ( F_84 ( V_85 ,
& V_82 -> V_86 ) )
V_83 = true ;
else
V_76 = NULL ;
F_17 ( & V_82 -> V_34 ) ;
}
if ( ! V_76 || ( ! V_73 -> V_50 &&
V_76 -> type != V_84 ) ) {
V_28 = F_85 ( V_7 , V_77 , V_78 ,
V_87 ) ;
if ( V_28 == - V_88 )
V_28 = - V_89 ;
if ( ! V_28 ) {
V_25 -> V_50 = V_78 ;
F_80 ( V_45 ,
L_3 ,
F_11 ( V_82 ) ,
V_78 , 1 ) ;
}
return V_28 ;
}
V_28 = F_79 ( V_76 , V_77 , V_78 , 1 ) ;
if ( ! V_28 ) {
F_80 ( V_45 , L_3 ,
F_11 ( V_82 ) , V_78 , 1 ) ;
V_25 -> V_50 = V_78 ;
}
if ( V_83 ) {
F_80 ( V_45 , L_4 ,
F_11 ( V_82 ) , V_78 , 0 ) ;
F_82 ( V_45 , V_76 , V_78 ) ;
}
return V_28 ;
}
static void F_86 ( struct V_74 * V_45 ,
struct V_2 * V_25 )
{
struct V_75 * V_81 ;
if ( ! V_25 -> V_50 )
return;
V_81 = & V_45 -> V_80 ;
F_80 ( V_45 , L_3 ,
V_25 -> V_8 , V_25 -> V_50 , 0 ) ;
F_82 ( V_45 , V_81 ,
V_25 -> V_50 ) ;
V_25 -> V_50 = 0 ;
}
static int F_87 ( struct V_6 * V_7 ,
struct V_90 * V_91 ,
struct V_16 * V_48 )
{
struct V_74 * V_45 = V_7 -> V_45 ;
struct V_16 * V_92 , * V_44 ;
int V_93 ;
int V_94 = 0 , V_95 = 0 ;
struct V_96 * V_97 ;
char * V_98 ;
struct V_52 * V_99 ;
T_3 * V_100 ;
struct V_41 V_101 ;
int V_102 ;
int V_103 ;
int V_104 ;
int V_28 = 0 ;
F_16 ( ! V_91 -> V_39 [ 0 ] ) ;
V_97 = V_91 -> V_39 [ 0 ] ;
V_93 = F_88 ( V_45 , V_97 ) ;
F_8 ( & V_101 ) ;
V_44 = V_48 ;
V_103 = 0 ;
while ( V_95 + V_44 -> V_47 + sizeof( struct V_105 ) <=
V_93 ) {
V_94 += V_44 -> V_47 ;
V_95 += V_44 -> V_47 + sizeof( struct V_105 ) ;
F_30 ( & V_44 -> V_106 , & V_101 ) ;
V_103 ++ ;
V_92 = V_44 ;
V_44 = F_76 ( V_92 ) ;
if ( ! V_44 )
break;
if ( ! F_9 ( V_92 , V_44 ) )
break;
}
if ( ! V_103 ) {
V_28 = 0 ;
goto V_43;
}
F_89 ( V_91 ) ;
V_99 = F_90 ( V_103 , sizeof( struct V_52 ) , V_30 ) ;
if ( ! V_99 ) {
V_28 = - V_4 ;
goto V_43;
}
V_100 = F_90 ( V_103 , sizeof( T_3 ) , V_30 ) ;
if ( ! V_100 ) {
V_28 = - V_4 ;
goto error;
}
V_104 = 0 ;
F_91 (next, &head, tree_list) {
V_99 [ V_104 ] = V_44 -> V_19 ;
V_100 [ V_104 ] = V_44 -> V_47 ;
V_104 ++ ;
}
F_92 ( V_91 , NULL , 0 ) ;
F_93 ( V_7 , V_91 , V_99 , V_100 ,
V_94 , V_95 , V_103 ) ;
V_102 = V_91 -> V_107 [ 0 ] ;
F_94 (curr, next, &head, tree_list) {
V_98 = F_95 ( V_97 , V_102 , char ) ;
F_96 ( V_97 , & V_92 -> V_108 ,
( unsigned long ) V_98 ,
V_92 -> V_47 ) ;
V_102 ++ ;
F_81 ( V_45 , V_92 ) ;
F_97 ( & V_92 -> V_106 ) ;
F_71 ( V_92 ) ;
}
error:
F_72 ( V_100 ) ;
F_72 ( V_99 ) ;
V_43:
return V_28 ;
}
static int F_98 ( struct V_72 * V_73 ,
struct V_6 * V_7 ,
struct V_90 * V_91 ,
struct V_16 * V_56 )
{
struct V_74 * V_45 = V_7 -> V_45 ;
struct V_96 * V_97 ;
char * V_109 ;
int V_28 ;
V_28 = F_99 ( V_73 , V_7 , V_91 , & V_56 -> V_19 ,
V_56 -> V_47 ) ;
if ( V_28 < 0 && V_28 != - V_31 )
return V_28 ;
V_97 = V_91 -> V_39 [ 0 ] ;
V_109 = F_95 ( V_97 , V_91 -> V_107 [ 0 ] , char ) ;
F_96 ( V_97 , V_56 -> V_108 , ( unsigned long ) V_109 ,
V_56 -> V_47 ) ;
F_100 ( V_97 ) ;
F_81 ( V_45 , V_56 ) ;
return 0 ;
}
static int F_101 ( struct V_72 * V_73 ,
struct V_90 * V_91 ,
struct V_6 * V_7 ,
struct V_2 * V_25 )
{
struct V_16 * V_92 , * V_53 ;
int V_28 = 0 ;
V_110:
F_41 ( & V_25 -> V_13 ) ;
V_92 = F_73 ( V_25 ) ;
if ( ! V_92 )
goto V_111;
V_28 = F_98 ( V_73 , V_7 , V_91 , V_92 ) ;
if ( V_28 < 0 ) {
F_102 ( V_91 ) ;
goto V_111;
}
V_53 = V_92 ;
V_92 = F_76 ( V_53 ) ;
if ( V_92 && F_9 ( V_53 , V_92 ) ) {
V_91 -> V_107 [ 0 ] ++ ;
F_87 ( V_7 , V_91 , V_92 ) ;
}
F_71 ( V_53 ) ;
F_100 ( V_91 -> V_39 [ 0 ] ) ;
F_102 ( V_91 ) ;
F_42 ( & V_25 -> V_13 ) ;
goto V_110;
V_111:
F_42 ( & V_25 -> V_13 ) ;
return V_28 ;
}
static int F_103 ( struct V_72 * V_73 ,
struct V_6 * V_7 ,
struct V_90 * V_91 ,
struct V_16 * V_48 )
{
struct V_74 * V_45 = V_7 -> V_45 ;
struct V_16 * V_92 , * V_44 ;
struct V_96 * V_97 ;
struct V_52 V_19 ;
struct V_41 V_101 ;
int V_103 , V_104 , V_112 ;
int V_28 = 0 ;
F_16 ( ! V_91 -> V_39 [ 0 ] ) ;
V_97 = V_91 -> V_39 [ 0 ] ;
V_104 = V_91 -> V_107 [ 0 ] ;
V_112 = F_104 ( V_97 ) - 1 ;
if ( V_104 > V_112 )
return - V_113 ;
V_44 = V_48 ;
F_8 ( & V_101 ) ;
F_105 ( V_97 , & V_19 , V_104 ) ;
V_103 = 0 ;
while ( F_53 ( & V_44 -> V_19 , & V_19 ) == 0 ) {
F_30 ( & V_44 -> V_106 , & V_101 ) ;
V_103 ++ ;
V_92 = V_44 ;
V_44 = F_76 ( V_92 ) ;
if ( ! V_44 )
break;
if ( ! F_9 ( V_92 , V_44 ) )
break;
V_104 ++ ;
if ( V_104 > V_112 )
break;
F_105 ( V_97 , & V_19 , V_104 ) ;
}
if ( ! V_103 )
return 0 ;
V_28 = F_106 ( V_73 , V_7 , V_91 , V_91 -> V_107 [ 0 ] , V_103 ) ;
if ( V_28 )
goto V_43;
F_94 (curr, next, &head, tree_list) {
F_81 ( V_45 , V_92 ) ;
F_97 ( & V_92 -> V_106 ) ;
F_71 ( V_92 ) ;
}
V_43:
return V_28 ;
}
static int F_107 ( struct V_72 * V_73 ,
struct V_90 * V_91 ,
struct V_6 * V_7 ,
struct V_2 * V_25 )
{
struct V_16 * V_92 , * V_53 ;
int V_28 = 0 ;
V_110:
F_41 ( & V_25 -> V_13 ) ;
V_92 = F_75 ( V_25 ) ;
if ( ! V_92 )
goto V_114;
V_28 = F_108 ( V_73 , V_7 , & V_92 -> V_19 , V_91 , - 1 , 1 ) ;
if ( V_28 < 0 )
goto V_114;
else if ( V_28 > 0 ) {
V_53 = V_92 ;
V_92 = F_76 ( V_53 ) ;
F_71 ( V_53 ) ;
V_28 = 0 ;
F_102 ( V_91 ) ;
if ( V_92 ) {
F_42 ( & V_25 -> V_13 ) ;
goto V_110;
} else
goto V_114;
}
F_103 ( V_73 , V_7 , V_91 , V_92 ) ;
F_102 ( V_91 ) ;
F_42 ( & V_25 -> V_13 ) ;
goto V_110;
V_114:
F_102 ( V_91 ) ;
F_42 ( & V_25 -> V_13 ) ;
return V_28 ;
}
static void F_109 ( struct V_2 * V_5 )
{
struct V_32 * V_40 ;
if ( V_5 &&
F_27 ( V_115 , & V_5 -> V_36 ) ) {
F_16 ( ! V_5 -> V_7 ) ;
F_35 ( V_115 , & V_5 -> V_36 ) ;
V_5 -> V_46 -- ;
V_40 = V_5 -> V_7 -> V_45 -> V_40 ;
F_64 ( V_40 ) ;
}
}
static void F_110 ( struct V_2 * V_5 )
{
struct V_32 * V_40 ;
ASSERT ( V_5 -> V_7 ) ;
F_35 ( V_116 , & V_5 -> V_36 ) ;
V_5 -> V_46 -- ;
V_40 = V_5 -> V_7 -> V_45 -> V_40 ;
F_64 ( V_40 ) ;
}
static int F_111 ( struct V_72 * V_73 ,
struct V_6 * V_7 ,
struct V_90 * V_91 ,
struct V_2 * V_25 )
{
struct V_74 * V_45 = V_7 -> V_45 ;
struct V_52 V_19 ;
struct V_117 * V_118 ;
struct V_96 * V_97 ;
int V_33 ;
int V_28 ;
V_19 . V_21 = V_25 -> V_8 ;
V_19 . type = V_119 ;
V_19 . V_22 = 0 ;
if ( F_27 ( V_116 , & V_25 -> V_36 ) )
V_33 = - 1 ;
else
V_33 = 1 ;
V_28 = F_112 ( V_73 , V_7 , V_91 , & V_19 , V_33 ) ;
if ( V_28 > 0 ) {
F_102 ( V_91 ) ;
return - V_113 ;
} else if ( V_28 < 0 ) {
return V_28 ;
}
V_97 = V_91 -> V_39 [ 0 ] ;
V_118 = F_95 ( V_97 , V_91 -> V_107 [ 0 ] ,
struct V_117 ) ;
F_96 ( V_97 , & V_25 -> V_118 , ( unsigned long ) V_118 ,
sizeof( struct V_117 ) ) ;
F_100 ( V_97 ) ;
if ( ! F_27 ( V_116 , & V_25 -> V_36 ) )
goto V_120;
V_91 -> V_107 [ 0 ] ++ ;
if ( V_91 -> V_107 [ 0 ] >= F_104 ( V_97 ) )
goto V_121;
V_29:
F_105 ( V_97 , & V_19 , V_91 -> V_107 [ 0 ] ) ;
if ( V_19 . V_21 != V_25 -> V_8 )
goto V_43;
if ( V_19 . type != V_122 &&
V_19 . type != V_123 )
goto V_43;
F_113 ( V_73 , V_7 , V_91 ) ;
V_43:
F_110 ( V_25 ) ;
V_120:
F_102 ( V_91 ) ;
V_124:
F_86 ( V_45 , V_25 ) ;
F_109 ( V_25 ) ;
return V_28 ;
V_121:
F_102 ( V_91 ) ;
V_19 . type = V_123 ;
V_19 . V_22 = - 1 ;
V_28 = F_108 ( V_73 , V_7 , & V_19 , V_91 , - 1 , 1 ) ;
if ( V_28 < 0 )
goto V_124;
ASSERT ( V_28 ) ;
V_28 = 0 ;
V_97 = V_91 -> V_39 [ 0 ] ;
V_91 -> V_107 [ 0 ] -- ;
goto V_29;
}
static inline int F_114 ( struct V_72 * V_73 ,
struct V_6 * V_7 ,
struct V_90 * V_91 ,
struct V_2 * V_25 )
{
int V_28 ;
F_41 ( & V_25 -> V_13 ) ;
if ( ! F_27 ( V_115 , & V_25 -> V_36 ) ) {
F_42 ( & V_25 -> V_13 ) ;
return 0 ;
}
V_28 = F_111 ( V_73 , V_7 , V_91 , V_25 ) ;
F_42 ( & V_25 -> V_13 ) ;
return V_28 ;
}
static inline int
F_115 ( struct V_72 * V_73 ,
struct V_90 * V_91 ,
struct V_2 * V_25 )
{
int V_28 ;
V_28 = F_101 ( V_73 , V_91 , V_25 -> V_7 , V_25 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_107 ( V_73 , V_91 , V_25 -> V_7 , V_25 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_114 ( V_73 , V_25 -> V_7 , V_91 , V_25 ) ;
return V_28 ;
}
static int F_116 ( struct V_72 * V_73 ,
struct V_74 * V_45 , int V_125 )
{
struct V_32 * V_40 ;
struct V_2 * V_126 , * V_55 ;
struct V_90 * V_91 ;
struct V_75 * V_79 ;
int V_28 = 0 ;
bool V_46 = ( V_125 > 0 ) ;
if ( V_73 -> V_127 )
return - V_128 ;
V_91 = F_117 () ;
if ( ! V_91 )
return - V_4 ;
V_91 -> V_129 = 1 ;
V_79 = V_73 -> V_79 ;
V_73 -> V_79 = & V_45 -> V_80 ;
V_40 = V_45 -> V_40 ;
V_126 = F_36 ( V_40 ) ;
while ( V_126 && ( ! V_46 || ( V_46 && V_125 -- ) ) ) {
V_28 = F_115 ( V_73 , V_91 ,
V_126 ) ;
if ( V_28 ) {
F_46 ( V_126 ) ;
V_126 = NULL ;
F_118 ( V_73 , V_28 ) ;
break;
}
V_55 = V_126 ;
V_126 = F_38 ( V_126 ) ;
F_46 ( V_55 ) ;
}
if ( V_126 )
F_46 ( V_126 ) ;
F_119 ( V_91 ) ;
V_73 -> V_79 = V_79 ;
return V_28 ;
}
int F_120 ( struct V_72 * V_73 ,
struct V_74 * V_45 )
{
return F_116 ( V_73 , V_45 , - 1 ) ;
}
int F_121 ( struct V_72 * V_73 ,
struct V_74 * V_45 , int V_125 )
{
return F_116 ( V_73 , V_45 , V_125 ) ;
}
int F_122 ( struct V_72 * V_73 ,
struct V_23 * V_82 )
{
struct V_2 * V_5 = F_10 ( V_82 ) ;
struct V_90 * V_91 ;
struct V_75 * V_79 ;
int V_28 ;
if ( ! V_5 )
return 0 ;
F_41 ( & V_5 -> V_13 ) ;
if ( ! V_5 -> V_46 ) {
F_42 ( & V_5 -> V_13 ) ;
F_46 ( V_5 ) ;
return 0 ;
}
F_42 ( & V_5 -> V_13 ) ;
V_91 = F_117 () ;
if ( ! V_91 ) {
F_46 ( V_5 ) ;
return - V_4 ;
}
V_91 -> V_129 = 1 ;
V_79 = V_73 -> V_79 ;
V_73 -> V_79 = & V_5 -> V_7 -> V_45 -> V_80 ;
V_28 = F_115 ( V_73 , V_91 , V_5 ) ;
F_46 ( V_5 ) ;
F_119 ( V_91 ) ;
V_73 -> V_79 = V_79 ;
return V_28 ;
}
int F_123 ( struct V_23 * V_82 )
{
struct V_74 * V_45 = F_124 ( V_82 -> V_130 . V_131 ) ;
struct V_72 * V_73 ;
struct V_2 * V_5 = F_10 ( V_82 ) ;
struct V_90 * V_91 ;
struct V_75 * V_79 ;
int V_28 ;
if ( ! V_5 )
return 0 ;
F_41 ( & V_5 -> V_13 ) ;
if ( ! F_27 ( V_115 , & V_5 -> V_36 ) ) {
F_42 ( & V_5 -> V_13 ) ;
F_46 ( V_5 ) ;
return 0 ;
}
F_42 ( & V_5 -> V_13 ) ;
V_73 = F_125 ( V_5 -> V_7 ) ;
if ( F_126 ( V_73 ) ) {
V_28 = F_127 ( V_73 ) ;
goto V_43;
}
V_91 = F_117 () ;
if ( ! V_91 ) {
V_28 = - V_4 ;
goto V_132;
}
V_91 -> V_129 = 1 ;
V_79 = V_73 -> V_79 ;
V_73 -> V_79 = & V_45 -> V_80 ;
F_41 ( & V_5 -> V_13 ) ;
if ( F_27 ( V_115 , & V_5 -> V_36 ) )
V_28 = F_111 ( V_73 , V_5 -> V_7 ,
V_91 , V_5 ) ;
else
V_28 = 0 ;
F_42 ( & V_5 -> V_13 ) ;
F_119 ( V_91 ) ;
V_73 -> V_79 = V_79 ;
V_132:
F_128 ( V_73 ) ;
F_129 ( V_45 ) ;
V_43:
F_46 ( V_5 ) ;
return V_28 ;
}
void F_130 ( struct V_23 * V_82 )
{
struct V_2 * V_5 ;
V_5 = F_12 ( V_82 -> V_5 ) ;
if ( ! V_5 )
return;
V_82 -> V_5 = NULL ;
F_46 ( V_5 ) ;
}
static void F_131 ( struct V_133 * V_134 )
{
struct V_135 * V_136 ;
struct V_32 * V_40 ;
struct V_72 * V_73 ;
struct V_90 * V_91 ;
struct V_2 * V_5 = NULL ;
struct V_6 * V_7 ;
struct V_75 * V_79 ;
int V_137 = 0 ;
V_136 = F_132 ( V_134 , struct V_135 , V_134 ) ;
V_40 = V_136 -> V_40 ;
V_91 = F_117 () ;
if ( ! V_91 )
goto V_43;
V_29:
if ( F_133 ( & V_40 -> V_66 ) < V_69 / 2 )
goto V_138;
V_5 = F_47 ( V_40 ) ;
if ( ! V_5 )
goto V_138;
V_91 -> V_129 = 1 ;
V_7 = V_5 -> V_7 ;
V_73 = F_125 ( V_7 ) ;
if ( F_126 ( V_73 ) )
goto V_139;
V_79 = V_73 -> V_79 ;
V_73 -> V_79 = & V_7 -> V_45 -> V_80 ;
F_115 ( V_73 , V_91 , V_5 ) ;
V_73 -> V_79 = V_79 ;
F_128 ( V_73 ) ;
F_134 ( V_7 -> V_45 ) ;
V_139:
F_102 ( V_91 ) ;
V_137 ++ ;
F_48 ( V_5 ) ;
if ( ( V_136 -> V_125 == 0 && V_137 < V_140 ) ||
V_137 < V_136 -> V_125 )
goto V_29;
V_138:
F_119 ( V_91 ) ;
V_43:
F_68 ( & V_40 -> V_71 ) ;
F_72 ( V_136 ) ;
}
static int F_135 ( struct V_32 * V_40 ,
struct V_74 * V_45 , int V_125 )
{
struct V_135 * V_136 ;
if ( F_133 ( & V_40 -> V_66 ) < V_69 ||
F_136 ( V_45 -> V_141 ) )
return 0 ;
V_136 = F_50 ( sizeof( * V_136 ) , V_30 ) ;
if ( ! V_136 )
return - V_4 ;
V_136 -> V_40 = V_40 ;
F_137 ( & V_136 -> V_134 , V_142 ,
F_131 , NULL , NULL ) ;
V_136 -> V_125 = V_125 ;
F_138 ( V_45 -> V_141 , & V_136 -> V_134 ) ;
return 0 ;
}
void F_139 ( struct V_74 * V_45 )
{
F_140 ( F_36 ( V_45 -> V_40 ) ) ;
}
static int F_141 ( struct V_32 * V_40 , int V_67 )
{
int V_143 = F_133 ( & V_40 -> V_68 ) ;
if ( V_143 < V_67 || V_143 >= V_67 + V_70 )
return 1 ;
if ( F_133 ( & V_40 -> V_66 ) < V_69 )
return 1 ;
return 0 ;
}
void F_142 ( struct V_74 * V_45 )
{
struct V_32 * V_40 = V_45 -> V_40 ;
if ( F_133 ( & V_40 -> V_66 ) < V_69 )
return;
if ( F_133 ( & V_40 -> V_66 ) >= V_140 ) {
int V_67 ;
int V_28 ;
V_67 = F_133 ( & V_40 -> V_68 ) ;
V_28 = F_135 ( V_40 , V_45 , 0 ) ;
if ( V_28 )
return;
F_143 ( V_40 -> V_71 ,
F_141 ( V_40 , V_67 ) ) ;
return;
}
F_135 ( V_40 , V_45 , V_70 ) ;
}
int F_144 ( struct V_72 * V_73 ,
struct V_74 * V_45 ,
const char * V_144 , int V_145 ,
struct V_23 * V_146 ,
struct V_147 * V_148 , T_4 type ,
T_2 V_149 )
{
struct V_2 * V_5 ;
struct V_16 * V_56 ;
struct V_150 * V_151 ;
int V_28 ;
V_5 = F_19 ( V_146 ) ;
if ( F_126 ( V_5 ) )
return F_127 ( V_5 ) ;
V_56 = F_49 ( sizeof( * V_151 ) + V_145 ) ;
if ( ! V_56 ) {
V_28 = - V_4 ;
goto V_152;
}
V_56 -> V_19 . V_21 = F_11 ( V_146 ) ;
V_56 -> V_19 . type = V_20 ;
V_56 -> V_19 . V_22 = V_149 ;
V_151 = (struct V_150 * ) V_56 -> V_108 ;
V_151 -> V_153 = * V_148 ;
F_145 ( V_151 , V_73 -> V_154 ) ;
F_146 ( V_151 , 0 ) ;
F_147 ( V_151 , V_145 ) ;
F_148 ( V_151 , type ) ;
memcpy ( ( char * ) ( V_151 + 1 ) , V_144 , V_145 ) ;
V_28 = F_77 ( V_73 , V_45 , V_56 ) ;
F_16 ( V_28 ) ;
F_41 ( & V_5 -> V_13 ) ;
V_28 = F_62 ( V_5 , V_56 ) ;
if ( F_149 ( V_28 ) ) {
F_150 ( V_45 ,
L_5 ,
V_145 , V_144 , V_5 -> V_7 -> V_21 ,
V_5 -> V_8 , V_28 ) ;
F_58 () ;
}
F_42 ( & V_5 -> V_13 ) ;
V_152:
F_46 ( V_5 ) ;
return V_28 ;
}
static int F_151 ( struct V_74 * V_45 ,
struct V_2 * V_25 ,
struct V_52 * V_19 )
{
struct V_16 * V_48 ;
F_41 ( & V_25 -> V_13 ) ;
V_48 = F_56 ( V_25 , V_19 ) ;
if ( ! V_48 ) {
F_42 ( & V_25 -> V_13 ) ;
return 1 ;
}
F_81 ( V_45 , V_48 ) ;
F_71 ( V_48 ) ;
F_42 ( & V_25 -> V_13 ) ;
return 0 ;
}
int F_152 ( struct V_72 * V_73 ,
struct V_74 * V_45 ,
struct V_23 * V_146 , T_2 V_149 )
{
struct V_2 * V_25 ;
struct V_16 * V_48 ;
struct V_52 V_155 ;
int V_28 ;
V_25 = F_19 ( V_146 ) ;
if ( F_126 ( V_25 ) )
return F_127 ( V_25 ) ;
V_155 . V_21 = F_11 ( V_146 ) ;
V_155 . type = V_20 ;
V_155 . V_22 = V_149 ;
V_28 = F_151 ( V_45 , V_25 , & V_155 ) ;
if ( ! V_28 )
goto V_156;
V_48 = F_49 ( 0 ) ;
if ( ! V_48 ) {
V_28 = - V_4 ;
goto V_156;
}
V_48 -> V_19 = V_155 ;
V_28 = F_77 ( V_73 , V_45 , V_48 ) ;
F_16 ( V_28 ) ;
F_41 ( & V_25 -> V_13 ) ;
V_28 = F_63 ( V_25 , V_48 ) ;
if ( F_149 ( V_28 ) ) {
F_150 ( V_45 ,
L_6 ,
V_149 , V_25 -> V_7 -> V_21 , V_25 -> V_8 , V_28 ) ;
F_58 () ;
}
F_42 ( & V_25 -> V_13 ) ;
V_156:
F_46 ( V_25 ) ;
return V_28 ;
}
int F_153 ( struct V_23 * V_82 )
{
struct V_2 * V_5 = F_10 ( V_82 ) ;
if ( ! V_5 )
return - V_113 ;
if ( ! V_5 -> V_65 ) {
F_46 ( V_5 ) ;
return - V_157 ;
}
V_82 -> V_65 = V_5 -> V_65 ;
F_46 ( V_5 ) ;
return 0 ;
}
bool F_154 ( struct V_82 * V_82 ,
struct V_41 * V_158 ,
struct V_41 * V_159 )
{
struct V_2 * V_5 ;
struct V_16 * V_48 ;
V_5 = F_10 ( F_155 ( V_82 ) ) ;
if ( ! V_5 )
return false ;
F_156 ( V_82 ) ;
V_26 ( V_82 ) ;
F_41 ( & V_5 -> V_13 ) ;
V_48 = F_73 ( V_5 ) ;
while ( V_48 ) {
F_13 ( & V_48 -> V_9 ) ;
F_30 ( & V_48 -> V_160 , V_158 ) ;
V_48 = F_76 ( V_48 ) ;
}
V_48 = F_75 ( V_5 ) ;
while ( V_48 ) {
F_13 ( & V_48 -> V_9 ) ;
F_30 ( & V_48 -> V_160 , V_159 ) ;
V_48 = F_76 ( V_48 ) ;
}
F_42 ( & V_5 -> V_13 ) ;
F_33 ( & V_5 -> V_9 ) ;
return true ;
}
void F_157 ( struct V_82 * V_82 ,
struct V_41 * V_158 ,
struct V_41 * V_159 )
{
struct V_16 * V_92 , * V_44 ;
F_94 (curr, next, ins_list, readdir_list) {
F_97 ( & V_92 -> V_160 ) ;
if ( F_43 ( & V_92 -> V_9 ) )
F_72 ( V_92 ) ;
}
F_94 (curr, next, del_list, readdir_list) {
F_97 ( & V_92 -> V_160 ) ;
if ( F_43 ( & V_92 -> V_9 ) )
F_72 ( V_92 ) ;
}
F_158 ( & V_82 -> V_161 ) ;
}
int F_159 ( struct V_41 * V_159 ,
T_2 V_149 )
{
struct V_16 * V_92 , * V_44 ;
int V_28 ;
if ( F_28 ( V_159 ) )
return 0 ;
F_94 (curr, next, del_list, readdir_list) {
if ( V_92 -> V_19 . V_22 > V_149 )
break;
F_97 ( & V_92 -> V_160 ) ;
V_28 = ( V_92 -> V_19 . V_22 == V_149 ) ;
if ( F_43 ( & V_92 -> V_9 ) )
F_72 ( V_92 ) ;
if ( V_28 )
return 1 ;
else
continue;
}
return 0 ;
}
int F_160 ( struct V_162 * V_163 ,
struct V_41 * V_158 )
{
struct V_150 * V_164 ;
struct V_16 * V_92 , * V_44 ;
struct V_52 V_153 ;
char * V_144 ;
int V_145 ;
int V_165 = 0 ;
unsigned char V_166 ;
if ( F_28 ( V_158 ) )
return 0 ;
F_94 (curr, next, ins_list, readdir_list) {
F_97 ( & V_92 -> V_160 ) ;
if ( V_92 -> V_19 . V_22 < V_163 -> V_167 ) {
if ( F_43 ( & V_92 -> V_9 ) )
F_72 ( V_92 ) ;
continue;
}
V_163 -> V_167 = V_92 -> V_19 . V_22 ;
V_164 = (struct V_150 * ) V_92 -> V_108 ;
V_144 = ( char * ) ( V_164 + 1 ) ;
V_145 = F_161 ( V_164 ) ;
V_166 = V_168 [ V_164 -> type ] ;
F_162 ( & V_153 , & V_164 -> V_153 ) ;
V_165 = ! F_163 ( V_163 , V_144 , V_145 ,
V_153 . V_21 , V_166 ) ;
if ( F_43 ( & V_92 -> V_9 ) )
F_72 ( V_92 ) ;
if ( V_165 )
return 1 ;
}
return 0 ;
}
static void F_164 ( struct V_72 * V_73 ,
struct V_117 * V_118 ,
struct V_82 * V_82 )
{
F_165 ( V_118 , F_166 ( V_82 ) ) ;
F_167 ( V_118 , F_168 ( V_82 ) ) ;
F_169 ( V_118 , F_155 ( V_82 ) -> V_169 ) ;
F_170 ( V_118 , V_82 -> V_170 ) ;
F_171 ( V_118 , V_82 -> V_171 ) ;
F_172 ( V_118 , F_173 ( V_82 ) ) ;
F_174 ( V_118 ,
F_155 ( V_82 ) -> V_172 ) ;
F_175 ( V_118 , V_82 -> V_173 ) ;
F_176 ( V_118 , V_73 -> V_154 ) ;
F_177 ( V_118 , V_82 -> V_174 ) ;
F_178 ( V_118 , F_155 ( V_82 ) -> V_36 ) ;
F_179 ( V_118 , 0 ) ;
F_180 ( & V_118 -> V_175 ,
V_82 -> V_176 . V_177 ) ;
F_181 ( & V_118 -> V_175 ,
V_82 -> V_176 . V_178 ) ;
F_180 ( & V_118 -> V_179 ,
V_82 -> V_180 . V_177 ) ;
F_181 ( & V_118 -> V_179 ,
V_82 -> V_180 . V_178 ) ;
F_180 ( & V_118 -> ctime ,
V_82 -> V_181 . V_177 ) ;
F_181 ( & V_118 -> ctime ,
V_82 -> V_181 . V_178 ) ;
F_180 ( & V_118 -> V_182 ,
F_155 ( V_82 ) -> V_183 . V_177 ) ;
F_181 ( & V_118 -> V_182 ,
F_155 ( V_82 ) -> V_183 . V_178 ) ;
}
int F_182 ( struct V_82 * V_82 , T_3 * V_184 )
{
struct V_2 * V_5 ;
struct V_117 * V_118 ;
V_5 = F_10 ( F_155 ( V_82 ) ) ;
if ( ! V_5 )
return - V_113 ;
F_41 ( & V_5 -> V_13 ) ;
if ( ! F_27 ( V_115 , & V_5 -> V_36 ) ) {
F_42 ( & V_5 -> V_13 ) ;
F_46 ( V_5 ) ;
return - V_113 ;
}
V_118 = & V_5 -> V_118 ;
F_183 ( V_82 , F_184 ( V_118 ) ) ;
F_185 ( V_82 , F_186 ( V_118 ) ) ;
F_187 ( F_155 ( V_82 ) , F_188 ( V_118 ) ) ;
V_82 -> V_170 = F_189 ( V_118 ) ;
F_190 ( V_82 , F_191 ( V_118 ) ) ;
F_192 ( V_82 , F_193 ( V_118 ) ) ;
F_155 ( V_82 ) -> V_172 = F_194 ( V_118 ) ;
F_155 ( V_82 ) -> V_185 = F_195 ( V_118 ) ;
V_82 -> V_173 = F_196 ( V_118 ) ;
V_82 -> V_174 = 0 ;
* V_184 = F_197 ( V_118 ) ;
F_155 ( V_82 ) -> V_36 = F_198 ( V_118 ) ;
V_82 -> V_176 . V_177 = F_199 ( & V_118 -> V_175 ) ;
V_82 -> V_176 . V_178 = F_200 ( & V_118 -> V_175 ) ;
V_82 -> V_180 . V_177 = F_199 ( & V_118 -> V_179 ) ;
V_82 -> V_180 . V_178 = F_200 ( & V_118 -> V_179 ) ;
V_82 -> V_181 . V_177 = F_199 ( & V_118 -> ctime ) ;
V_82 -> V_181 . V_178 = F_200 ( & V_118 -> ctime ) ;
F_155 ( V_82 ) -> V_183 . V_177 =
F_199 ( & V_118 -> V_182 ) ;
F_155 ( V_82 ) -> V_183 . V_178 =
F_200 ( & V_118 -> V_182 ) ;
V_82 -> V_186 = F_155 ( V_82 ) -> V_172 ;
F_155 ( V_82 ) -> V_65 = ( T_2 ) - 1 ;
F_42 ( & V_5 -> V_13 ) ;
F_46 ( V_5 ) ;
return 0 ;
}
int F_201 ( struct V_72 * V_73 ,
struct V_6 * V_7 , struct V_82 * V_82 )
{
struct V_2 * V_5 ;
int V_28 = 0 ;
V_5 = F_19 ( F_155 ( V_82 ) ) ;
if ( F_126 ( V_5 ) )
return F_127 ( V_5 ) ;
F_41 ( & V_5 -> V_13 ) ;
if ( F_27 ( V_115 , & V_5 -> V_36 ) ) {
F_164 ( V_73 , & V_5 -> V_118 , V_82 ) ;
goto V_152;
}
V_28 = F_83 ( V_73 , V_7 , F_155 ( V_82 ) ,
V_5 ) ;
if ( V_28 )
goto V_152;
F_164 ( V_73 , & V_5 -> V_118 , V_82 ) ;
F_31 ( V_115 , & V_5 -> V_36 ) ;
V_5 -> V_46 ++ ;
F_61 ( & V_7 -> V_45 -> V_40 -> V_66 ) ;
V_152:
F_42 ( & V_5 -> V_13 ) ;
F_46 ( V_5 ) ;
return V_28 ;
}
int F_202 ( struct V_23 * V_82 )
{
struct V_74 * V_45 = F_124 ( V_82 -> V_130 . V_131 ) ;
struct V_2 * V_5 ;
if ( F_27 ( V_187 , & V_45 -> V_36 ) )
return - V_88 ;
V_5 = F_19 ( V_82 ) ;
if ( F_126 ( V_5 ) )
return F_127 ( V_5 ) ;
F_41 ( & V_5 -> V_13 ) ;
if ( F_27 ( V_116 , & V_5 -> V_36 ) )
goto V_152;
F_31 ( V_116 , & V_5 -> V_36 ) ;
V_5 -> V_46 ++ ;
F_61 ( & V_45 -> V_40 -> V_66 ) ;
V_152:
F_42 ( & V_5 -> V_13 ) ;
F_46 ( V_5 ) ;
return 0 ;
}
static void F_203 ( struct V_2 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_74 * V_45 = V_7 -> V_45 ;
struct V_16 * V_188 , * V_189 ;
F_41 ( & V_5 -> V_13 ) ;
V_188 = F_73 ( V_5 ) ;
while ( V_188 ) {
F_81 ( V_45 , V_188 ) ;
V_189 = V_188 ;
V_188 = F_76 ( V_189 ) ;
F_71 ( V_189 ) ;
}
V_188 = F_75 ( V_5 ) ;
while ( V_188 ) {
F_81 ( V_45 , V_188 ) ;
V_189 = V_188 ;
V_188 = F_76 ( V_189 ) ;
F_71 ( V_189 ) ;
}
if ( F_27 ( V_116 , & V_5 -> V_36 ) )
F_110 ( V_5 ) ;
if ( F_27 ( V_115 , & V_5 -> V_36 ) ) {
F_86 ( V_45 , V_5 ) ;
F_109 ( V_5 ) ;
}
F_42 ( & V_5 -> V_13 ) ;
}
void F_204 ( struct V_23 * V_82 )
{
struct V_2 * V_5 ;
V_5 = F_10 ( V_82 ) ;
if ( ! V_5 )
return;
F_203 ( V_5 ) ;
F_46 ( V_5 ) ;
}
void F_205 ( struct V_6 * V_7 )
{
T_2 V_8 = 0 ;
struct V_2 * V_190 [ 8 ] ;
int V_104 , V_191 ;
while ( 1 ) {
F_14 ( & V_7 -> V_26 ) ;
V_191 = F_206 ( & V_7 -> V_27 ,
( void * * ) V_190 , V_8 ,
F_207 ( V_190 ) ) ;
if ( ! V_191 ) {
F_17 ( & V_7 -> V_26 ) ;
break;
}
V_8 = V_190 [ V_191 - 1 ] -> V_8 + 1 ;
for ( V_104 = 0 ; V_104 < V_191 ; V_104 ++ )
F_13 ( & V_190 [ V_104 ] -> V_9 ) ;
F_17 ( & V_7 -> V_26 ) ;
for ( V_104 = 0 ; V_104 < V_191 ; V_104 ++ ) {
F_203 ( V_190 [ V_104 ] ) ;
F_46 ( V_190 [ V_104 ] ) ;
}
}
}
void F_208 ( struct V_74 * V_45 )
{
struct V_2 * V_126 , * V_55 ;
V_126 = F_36 ( V_45 -> V_40 ) ;
while ( V_126 ) {
F_203 ( V_126 ) ;
V_55 = V_126 ;
V_126 = F_38 ( V_126 ) ;
F_46 ( V_55 ) ;
}
}
