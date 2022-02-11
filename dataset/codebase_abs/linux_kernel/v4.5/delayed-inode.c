int T_1 F_1 ( void )
{
V_1 = F_2 ( L_1 ,
sizeof( struct V_2 ) ,
0 ,
V_3 | V_4 ,
NULL ) ;
if ( ! V_1 )
return - V_5 ;
return 0 ;
}
void F_3 ( void )
{
if ( V_1 )
F_4 ( V_1 ) ;
}
static inline void F_5 (
struct V_2 * V_6 ,
struct V_7 * V_8 , T_2 V_9 )
{
V_6 -> V_8 = V_8 ;
V_6 -> V_9 = V_9 ;
F_6 ( & V_6 -> V_10 , 0 ) ;
V_6 -> V_11 = V_12 ;
V_6 -> V_13 = V_12 ;
F_7 ( & V_6 -> V_14 ) ;
F_8 ( & V_6 -> V_15 ) ;
F_8 ( & V_6 -> V_16 ) ;
}
static inline int F_9 (
struct V_17 * V_18 ,
struct V_17 * V_19 )
{
if ( V_18 -> V_20 . type == V_21 &&
V_18 -> V_20 . V_22 == V_19 -> V_20 . V_22 &&
V_18 -> V_20 . type == V_19 -> V_20 . type &&
V_18 -> V_20 . V_23 + 1 == V_19 -> V_20 . V_23 )
return 1 ;
return 0 ;
}
static inline struct V_24 * F_10 (
struct V_7 * V_8 )
{
return V_8 -> V_25 -> V_26 ;
}
static struct V_2 * F_11 ( struct V_27 * V_27 )
{
struct V_28 * V_28 = F_12 ( V_27 ) ;
struct V_7 * V_8 = V_28 -> V_8 ;
T_2 V_29 = F_13 ( V_27 ) ;
struct V_2 * V_30 ;
V_30 = F_14 ( V_28 -> V_6 ) ;
if ( V_30 ) {
F_15 ( & V_30 -> V_10 ) ;
return V_30 ;
}
F_16 ( & V_8 -> V_31 ) ;
V_30 = F_17 ( & V_8 -> V_32 , V_29 ) ;
if ( V_30 ) {
if ( V_28 -> V_6 ) {
F_15 ( & V_30 -> V_10 ) ;
F_18 ( V_28 -> V_6 != V_30 ) ;
F_19 ( & V_8 -> V_31 ) ;
return V_30 ;
}
V_28 -> V_6 = V_30 ;
F_20 ( 2 , & V_30 -> V_10 ) ;
F_19 ( & V_8 -> V_31 ) ;
return V_30 ;
}
F_19 ( & V_8 -> V_31 ) ;
return NULL ;
}
static struct V_2 * F_21 (
struct V_27 * V_27 )
{
struct V_2 * V_30 ;
struct V_28 * V_28 = F_12 ( V_27 ) ;
struct V_7 * V_8 = V_28 -> V_8 ;
T_2 V_29 = F_13 ( V_27 ) ;
int V_33 ;
V_34:
V_30 = F_11 ( V_27 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_22 ( V_1 , V_35 ) ;
if ( ! V_30 )
return F_23 ( - V_5 ) ;
F_5 ( V_30 , V_8 , V_29 ) ;
F_20 ( 2 , & V_30 -> V_10 ) ;
V_33 = F_24 ( V_35 & ~ V_36 ) ;
if ( V_33 ) {
F_25 ( V_1 , V_30 ) ;
return F_23 ( V_33 ) ;
}
F_16 ( & V_8 -> V_31 ) ;
V_33 = F_26 ( & V_8 -> V_32 , V_29 , V_30 ) ;
if ( V_33 == - V_37 ) {
F_19 ( & V_8 -> V_31 ) ;
F_25 ( V_1 , V_30 ) ;
F_27 () ;
goto V_34;
}
V_28 -> V_6 = V_30 ;
F_19 ( & V_8 -> V_31 ) ;
F_27 () ;
return V_30 ;
}
static void F_28 ( struct V_24 * V_8 ,
struct V_2 * V_30 ,
int V_38 )
{
F_16 ( & V_8 -> V_39 ) ;
if ( F_29 ( V_40 , & V_30 -> V_41 ) ) {
if ( ! F_30 ( & V_30 -> V_16 ) )
F_31 ( & V_30 -> V_16 , & V_8 -> V_42 ) ;
else if ( V_38 )
F_32 ( & V_30 -> V_16 , & V_8 -> V_42 ) ;
} else {
F_32 ( & V_30 -> V_15 , & V_8 -> V_43 ) ;
F_32 ( & V_30 -> V_16 , & V_8 -> V_42 ) ;
F_15 ( & V_30 -> V_10 ) ;
V_8 -> V_44 ++ ;
F_33 ( V_40 , & V_30 -> V_41 ) ;
}
F_19 ( & V_8 -> V_39 ) ;
}
static void F_34 ( struct V_24 * V_8 ,
struct V_2 * V_30 )
{
F_16 ( & V_8 -> V_39 ) ;
if ( F_29 ( V_40 , & V_30 -> V_41 ) ) {
V_8 -> V_44 -- ;
F_35 ( & V_30 -> V_10 ) ;
F_36 ( & V_30 -> V_15 ) ;
if ( ! F_30 ( & V_30 -> V_16 ) )
F_36 ( & V_30 -> V_16 ) ;
F_37 ( V_40 , & V_30 -> V_41 ) ;
}
F_19 ( & V_8 -> V_39 ) ;
}
static struct V_2 * F_38 (
struct V_24 * V_26 )
{
struct V_45 * V_46 ;
struct V_2 * V_30 = NULL ;
F_16 ( & V_26 -> V_39 ) ;
if ( F_30 ( & V_26 -> V_43 ) )
goto V_47;
V_46 = V_26 -> V_43 . V_48 ;
V_30 = F_39 ( V_46 , struct V_2 , V_15 ) ;
F_15 ( & V_30 -> V_10 ) ;
V_47:
F_19 ( & V_26 -> V_39 ) ;
return V_30 ;
}
static struct V_2 * F_40 (
struct V_2 * V_30 )
{
struct V_24 * V_26 ;
struct V_45 * V_46 ;
struct V_2 * V_48 = NULL ;
V_26 = V_30 -> V_8 -> V_25 -> V_26 ;
F_16 ( & V_26 -> V_39 ) ;
if ( ! F_29 ( V_40 , & V_30 -> V_41 ) ) {
if ( F_30 ( & V_26 -> V_43 ) )
goto V_47;
V_46 = V_26 -> V_43 . V_48 ;
} else if ( F_41 ( & V_30 -> V_15 , & V_26 -> V_43 ) )
goto V_47;
else
V_46 = V_30 -> V_15 . V_48 ;
V_48 = F_39 ( V_46 , struct V_2 , V_15 ) ;
F_15 ( & V_48 -> V_10 ) ;
V_47:
F_19 ( & V_26 -> V_39 ) ;
return V_48 ;
}
static void F_42 (
struct V_2 * V_6 ,
int V_38 )
{
struct V_24 * V_26 ;
if ( ! V_6 )
return;
V_26 = V_6 -> V_8 -> V_25 -> V_26 ;
F_43 ( & V_6 -> V_14 ) ;
if ( V_6 -> V_49 )
F_28 ( V_26 , V_6 , V_38 ) ;
else
F_34 ( V_26 , V_6 ) ;
F_44 ( & V_6 -> V_14 ) ;
if ( F_45 ( & V_6 -> V_10 ) ) {
bool free = false ;
struct V_7 * V_8 = V_6 -> V_8 ;
F_16 ( & V_8 -> V_31 ) ;
if ( F_46 ( & V_6 -> V_10 ) == 0 ) {
F_47 ( & V_8 -> V_32 ,
V_6 -> V_9 ) ;
free = true ;
}
F_19 ( & V_8 -> V_31 ) ;
if ( free )
F_25 ( V_1 , V_6 ) ;
}
}
static inline void F_48 ( struct V_2 * V_30 )
{
F_42 ( V_30 , 0 ) ;
}
static struct V_2 * F_49 (
struct V_24 * V_26 )
{
struct V_45 * V_46 ;
struct V_2 * V_30 = NULL ;
F_16 ( & V_26 -> V_39 ) ;
if ( F_30 ( & V_26 -> V_42 ) )
goto V_47;
V_46 = V_26 -> V_42 . V_48 ;
F_36 ( V_46 ) ;
V_30 = F_39 ( V_46 , struct V_2 , V_16 ) ;
F_15 ( & V_30 -> V_10 ) ;
V_47:
F_19 ( & V_26 -> V_39 ) ;
return V_30 ;
}
static inline void F_50 (
struct V_2 * V_30 )
{
F_42 ( V_30 , 1 ) ;
}
static struct V_17 * F_51 ( T_3 V_50 )
{
struct V_17 * V_51 ;
V_51 = F_52 ( sizeof( * V_51 ) + V_50 , V_35 ) ;
if ( V_51 ) {
V_51 -> V_50 = V_50 ;
V_51 -> V_52 = 0 ;
V_51 -> V_53 = 0 ;
V_51 -> V_6 = NULL ;
F_6 ( & V_51 -> V_10 , 1 ) ;
}
return V_51 ;
}
static struct V_17 * F_53 (
struct V_54 * V_8 ,
struct V_55 * V_20 ,
struct V_17 * * V_56 ,
struct V_17 * * V_48 )
{
struct V_57 * V_30 , * V_58 = NULL ;
struct V_17 * V_59 = NULL ;
int V_33 = 0 ;
V_30 = V_8 -> V_57 ;
while ( V_30 ) {
V_59 = F_54 ( V_30 , struct V_17 ,
V_57 ) ;
V_58 = V_30 ;
V_33 = F_55 ( & V_59 -> V_20 , V_20 ) ;
if ( V_33 < 0 )
V_30 = V_30 -> V_60 ;
else if ( V_33 > 0 )
V_30 = V_30 -> V_61 ;
else
return V_59 ;
}
if ( V_56 ) {
if ( ! V_58 )
* V_56 = NULL ;
else if ( V_33 < 0 )
* V_56 = V_59 ;
else if ( ( V_30 = F_56 ( V_58 ) ) != NULL ) {
* V_56 = F_54 ( V_30 , struct V_17 ,
V_57 ) ;
} else
* V_56 = NULL ;
}
if ( V_48 ) {
if ( ! V_58 )
* V_48 = NULL ;
else if ( V_33 > 0 )
* V_48 = V_59 ;
else if ( ( V_30 = F_57 ( V_58 ) ) != NULL ) {
* V_48 = F_54 ( V_30 , struct V_17 ,
V_57 ) ;
} else
* V_48 = NULL ;
}
return NULL ;
}
static struct V_17 * F_58 (
struct V_2 * V_6 ,
struct V_55 * V_20 )
{
struct V_17 * V_51 ;
V_51 = F_53 ( & V_6 -> V_11 , V_20 ,
NULL , NULL ) ;
return V_51 ;
}
static int F_59 ( struct V_2 * V_6 ,
struct V_17 * V_62 ,
int V_63 )
{
struct V_57 * * V_46 , * V_30 ;
struct V_57 * V_64 = NULL ;
struct V_54 * V_8 ;
struct V_17 * V_51 ;
int V_65 ;
if ( V_63 == V_66 )
V_8 = & V_6 -> V_11 ;
else if ( V_63 == V_67 )
V_8 = & V_6 -> V_13 ;
else
F_60 () ;
V_46 = & V_8 -> V_57 ;
V_30 = & V_62 -> V_57 ;
while ( * V_46 ) {
V_64 = * V_46 ;
V_51 = F_54 ( V_64 , struct V_17 ,
V_57 ) ;
V_65 = F_55 ( & V_51 -> V_20 , & V_62 -> V_20 ) ;
if ( V_65 < 0 )
V_46 = & ( * V_46 ) -> V_60 ;
else if ( V_65 > 0 )
V_46 = & ( * V_46 ) -> V_61 ;
else
return - V_37 ;
}
F_61 ( V_30 , V_64 , V_46 ) ;
F_62 ( V_30 , V_8 ) ;
V_62 -> V_6 = V_6 ;
V_62 -> V_52 = V_63 ;
if ( V_62 -> V_20 . type == V_21 &&
V_63 == V_66 &&
V_62 -> V_20 . V_23 >= V_6 -> V_68 )
V_6 -> V_68 = V_62 -> V_20 . V_23 + 1 ;
V_6 -> V_49 ++ ;
F_15 ( & V_6 -> V_8 -> V_25 -> V_26 -> V_69 ) ;
return 0 ;
}
static int F_63 ( struct V_2 * V_30 ,
struct V_17 * V_51 )
{
return F_59 ( V_30 , V_51 ,
V_66 ) ;
}
static int F_64 ( struct V_2 * V_30 ,
struct V_17 * V_51 )
{
return F_59 ( V_30 , V_51 ,
V_67 ) ;
}
static void F_65 ( struct V_24 * V_26 )
{
int V_70 = F_66 ( & V_26 -> V_71 ) ;
if ( ( F_67 ( & V_26 -> V_69 ) <
V_72 || V_70 % V_73 == 0 ) &&
F_68 ( & V_26 -> V_74 ) )
F_69 ( & V_26 -> V_74 ) ;
}
static void F_70 ( struct V_17 * V_59 )
{
struct V_54 * V_8 ;
struct V_24 * V_26 ;
V_26 = V_59 -> V_6 -> V_8 -> V_25 -> V_26 ;
F_18 ( ! V_26 ) ;
F_18 ( V_59 -> V_52 != V_67 &&
V_59 -> V_52 != V_66 ) ;
if ( V_59 -> V_52 == V_66 )
V_8 = & V_59 -> V_6 -> V_11 ;
else
V_8 = & V_59 -> V_6 -> V_13 ;
F_71 ( & V_59 -> V_57 , V_8 ) ;
V_59 -> V_6 -> V_49 -- ;
F_65 ( V_26 ) ;
}
static void F_72 ( struct V_17 * V_51 )
{
if ( V_51 ) {
F_70 ( V_51 ) ;
if ( F_45 ( & V_51 -> V_10 ) )
F_73 ( V_51 ) ;
}
}
static struct V_17 * F_74 (
struct V_2 * V_6 )
{
struct V_57 * V_46 ;
struct V_17 * V_51 = NULL ;
V_46 = F_75 ( & V_6 -> V_11 ) ;
if ( V_46 )
V_51 = F_54 ( V_46 , struct V_17 , V_57 ) ;
return V_51 ;
}
static struct V_17 * F_76 (
struct V_2 * V_6 )
{
struct V_57 * V_46 ;
struct V_17 * V_51 = NULL ;
V_46 = F_75 ( & V_6 -> V_13 ) ;
if ( V_46 )
V_51 = F_54 ( V_46 , struct V_17 , V_57 ) ;
return V_51 ;
}
static struct V_17 * F_77 (
struct V_17 * V_51 )
{
struct V_57 * V_46 ;
struct V_17 * V_48 = NULL ;
V_46 = F_57 ( & V_51 -> V_57 ) ;
if ( V_46 )
V_48 = F_54 ( V_46 , struct V_17 , V_57 ) ;
return V_48 ;
}
static int F_78 ( struct V_75 * V_76 ,
struct V_7 * V_8 ,
struct V_17 * V_51 )
{
struct V_77 * V_78 ;
struct V_77 * V_79 ;
T_2 V_80 ;
int V_33 ;
if ( ! V_76 -> V_53 )
return 0 ;
V_78 = V_76 -> V_81 ;
V_79 = & V_8 -> V_25 -> V_82 ;
V_80 = F_79 ( V_8 , 1 ) ;
V_33 = F_80 ( V_78 , V_79 , V_80 ) ;
if ( ! V_33 ) {
F_81 ( V_8 -> V_25 , L_2 ,
V_51 -> V_20 . V_22 ,
V_80 , 1 ) ;
V_51 -> V_53 = V_80 ;
}
return V_33 ;
}
static void F_82 ( struct V_7 * V_8 ,
struct V_17 * V_51 )
{
struct V_77 * V_83 ;
if ( ! V_51 -> V_53 )
return;
V_83 = & V_8 -> V_25 -> V_82 ;
F_81 ( V_8 -> V_25 , L_2 ,
V_51 -> V_20 . V_22 , V_51 -> V_53 ,
0 ) ;
F_83 ( V_8 , V_83 ,
V_51 -> V_53 ) ;
}
static int F_84 (
struct V_75 * V_76 ,
struct V_7 * V_8 ,
struct V_27 * V_27 ,
struct V_2 * V_30 )
{
struct V_77 * V_78 ;
struct V_77 * V_79 ;
T_2 V_80 ;
int V_33 ;
bool V_84 = false ;
V_78 = V_76 -> V_81 ;
V_79 = & V_8 -> V_25 -> V_82 ;
V_80 = F_79 ( V_8 , 1 ) ;
if ( ! V_78 || ( ! V_76 -> V_53 &&
V_78 -> type != V_85 ) ) {
V_33 = F_85 ( V_8 , V_79 , V_80 ,
V_86 ) ;
if ( V_33 == - V_87 )
V_33 = - V_88 ;
if ( ! V_33 ) {
V_30 -> V_53 = V_80 ;
F_81 ( V_8 -> V_25 ,
L_3 ,
F_13 ( V_27 ) ,
V_80 , 1 ) ;
}
return V_33 ;
} else if ( V_78 -> type == V_85 ) {
F_16 ( & F_12 ( V_27 ) -> V_39 ) ;
if ( F_86 ( V_89 ,
& F_12 ( V_27 ) -> V_90 ) ) {
F_19 ( & F_12 ( V_27 ) -> V_39 ) ;
V_84 = true ;
goto V_91;
}
F_19 ( & F_12 ( V_27 ) -> V_39 ) ;
V_33 = F_85 ( V_8 , V_79 , V_80 ,
V_86 ) ;
if ( ! V_33 )
goto V_47;
V_33 = F_80 ( V_78 , V_79 , V_80 ) ;
if ( ! F_87 ( V_33 ) )
goto V_47;
V_33 = F_80 ( & V_8 -> V_25 -> V_92 ,
V_79 , V_80 ) ;
goto V_47;
}
V_91:
V_33 = F_80 ( V_78 , V_79 , V_80 ) ;
V_47:
if ( ! V_33 ) {
F_81 ( V_8 -> V_25 , L_3 ,
F_13 ( V_27 ) , V_80 , 1 ) ;
V_30 -> V_53 = V_80 ;
}
if ( V_84 ) {
F_81 ( V_8 -> V_25 , L_4 ,
F_13 ( V_27 ) , V_80 , 0 ) ;
F_83 ( V_8 , V_78 , V_80 ) ;
}
return V_33 ;
}
static void F_88 ( struct V_7 * V_8 ,
struct V_2 * V_30 )
{
struct V_77 * V_83 ;
if ( ! V_30 -> V_53 )
return;
V_83 = & V_8 -> V_25 -> V_82 ;
F_81 ( V_8 -> V_25 , L_3 ,
V_30 -> V_9 , V_30 -> V_53 , 0 ) ;
F_83 ( V_8 , V_83 ,
V_30 -> V_53 ) ;
V_30 -> V_53 = 0 ;
}
static int F_89 ( struct V_7 * V_8 ,
struct V_93 * V_94 ,
struct V_17 * V_51 )
{
struct V_17 * V_95 , * V_48 ;
int V_96 ;
int V_97 = 0 , V_98 = 0 ;
struct V_99 * V_100 ;
char * V_101 ;
struct V_55 * V_102 ;
T_3 * V_103 ;
struct V_45 V_104 ;
int V_105 ;
int V_106 ;
int V_107 ;
int V_33 = 0 ;
F_18 ( ! V_94 -> V_44 [ 0 ] ) ;
V_100 = V_94 -> V_44 [ 0 ] ;
V_96 = F_90 ( V_8 , V_100 ) ;
F_8 ( & V_104 ) ;
V_48 = V_51 ;
V_106 = 0 ;
while ( V_98 + V_48 -> V_50 + sizeof( struct V_108 ) <=
V_96 ) {
V_97 += V_48 -> V_50 ;
V_98 += V_48 -> V_50 + sizeof( struct V_108 ) ;
F_32 ( & V_48 -> V_109 , & V_104 ) ;
V_106 ++ ;
V_95 = V_48 ;
V_48 = F_77 ( V_95 ) ;
if ( ! V_48 )
break;
if ( ! F_9 ( V_95 , V_48 ) )
break;
}
if ( ! V_106 ) {
V_33 = 0 ;
goto V_47;
}
F_91 ( V_94 ) ;
V_102 = F_92 ( V_106 , sizeof( struct V_55 ) , V_35 ) ;
if ( ! V_102 ) {
V_33 = - V_5 ;
goto V_47;
}
V_103 = F_92 ( V_106 , sizeof( T_3 ) , V_35 ) ;
if ( ! V_103 ) {
V_33 = - V_5 ;
goto error;
}
V_107 = 0 ;
F_93 (next, &head, tree_list) {
V_102 [ V_107 ] = V_48 -> V_20 ;
V_103 [ V_107 ] = V_48 -> V_50 ;
V_107 ++ ;
}
F_94 ( V_94 , NULL , 0 ) ;
F_95 ( V_8 , V_94 , V_102 , V_103 ,
V_97 , V_98 , V_106 ) ;
V_105 = V_94 -> V_110 [ 0 ] ;
F_96 (curr, next, &head, tree_list) {
V_101 = F_97 ( V_100 , V_105 , char ) ;
F_98 ( V_100 , & V_95 -> V_111 ,
( unsigned long ) V_101 ,
V_95 -> V_50 ) ;
V_105 ++ ;
F_82 ( V_8 , V_95 ) ;
F_99 ( & V_95 -> V_109 ) ;
F_72 ( V_95 ) ;
}
error:
F_73 ( V_103 ) ;
F_73 ( V_102 ) ;
V_47:
return V_33 ;
}
static int F_100 ( struct V_75 * V_76 ,
struct V_7 * V_8 ,
struct V_93 * V_94 ,
struct V_17 * V_59 )
{
struct V_99 * V_100 ;
char * V_112 ;
int V_33 ;
V_33 = F_101 ( V_76 , V_8 , V_94 , & V_59 -> V_20 ,
V_59 -> V_50 ) ;
if ( V_33 < 0 && V_33 != - V_37 )
return V_33 ;
V_100 = V_94 -> V_44 [ 0 ] ;
V_112 = F_97 ( V_100 , V_94 -> V_110 [ 0 ] , char ) ;
F_98 ( V_100 , V_59 -> V_111 , ( unsigned long ) V_112 ,
V_59 -> V_50 ) ;
F_102 ( V_100 ) ;
F_82 ( V_8 , V_59 ) ;
return 0 ;
}
static int F_103 ( struct V_75 * V_76 ,
struct V_93 * V_94 ,
struct V_7 * V_8 ,
struct V_2 * V_30 )
{
struct V_17 * V_95 , * V_56 ;
int V_33 = 0 ;
V_113:
F_43 ( & V_30 -> V_14 ) ;
V_95 = F_74 ( V_30 ) ;
if ( ! V_95 )
goto V_114;
V_33 = F_100 ( V_76 , V_8 , V_94 , V_95 ) ;
if ( V_33 < 0 ) {
F_104 ( V_94 ) ;
goto V_114;
}
V_56 = V_95 ;
V_95 = F_77 ( V_56 ) ;
if ( V_95 && F_9 ( V_56 , V_95 ) ) {
V_94 -> V_110 [ 0 ] ++ ;
F_89 ( V_8 , V_94 , V_95 ) ;
}
F_72 ( V_56 ) ;
F_102 ( V_94 -> V_44 [ 0 ] ) ;
F_104 ( V_94 ) ;
F_44 ( & V_30 -> V_14 ) ;
goto V_113;
V_114:
F_44 ( & V_30 -> V_14 ) ;
return V_33 ;
}
static int F_105 ( struct V_75 * V_76 ,
struct V_7 * V_8 ,
struct V_93 * V_94 ,
struct V_17 * V_51 )
{
struct V_17 * V_95 , * V_48 ;
struct V_99 * V_100 ;
struct V_55 V_20 ;
struct V_45 V_104 ;
int V_106 , V_107 , V_115 ;
int V_33 = 0 ;
F_18 ( ! V_94 -> V_44 [ 0 ] ) ;
V_100 = V_94 -> V_44 [ 0 ] ;
V_107 = V_94 -> V_110 [ 0 ] ;
V_115 = F_106 ( V_100 ) - 1 ;
if ( V_107 > V_115 )
return - V_116 ;
V_48 = V_51 ;
F_8 ( & V_104 ) ;
F_107 ( V_100 , & V_20 , V_107 ) ;
V_106 = 0 ;
while ( F_55 ( & V_48 -> V_20 , & V_20 ) == 0 ) {
F_32 ( & V_48 -> V_109 , & V_104 ) ;
V_106 ++ ;
V_95 = V_48 ;
V_48 = F_77 ( V_95 ) ;
if ( ! V_48 )
break;
if ( ! F_9 ( V_95 , V_48 ) )
break;
V_107 ++ ;
if ( V_107 > V_115 )
break;
F_107 ( V_100 , & V_20 , V_107 ) ;
}
if ( ! V_106 )
return 0 ;
V_33 = F_108 ( V_76 , V_8 , V_94 , V_94 -> V_110 [ 0 ] , V_106 ) ;
if ( V_33 )
goto V_47;
F_96 (curr, next, &head, tree_list) {
F_82 ( V_8 , V_95 ) ;
F_99 ( & V_95 -> V_109 ) ;
F_72 ( V_95 ) ;
}
V_47:
return V_33 ;
}
static int F_109 ( struct V_75 * V_76 ,
struct V_93 * V_94 ,
struct V_7 * V_8 ,
struct V_2 * V_30 )
{
struct V_17 * V_95 , * V_56 ;
int V_33 = 0 ;
V_113:
F_43 ( & V_30 -> V_14 ) ;
V_95 = F_76 ( V_30 ) ;
if ( ! V_95 )
goto V_117;
V_33 = F_110 ( V_76 , V_8 , & V_95 -> V_20 , V_94 , - 1 , 1 ) ;
if ( V_33 < 0 )
goto V_117;
else if ( V_33 > 0 ) {
V_56 = V_95 ;
V_95 = F_77 ( V_56 ) ;
F_72 ( V_56 ) ;
V_33 = 0 ;
F_104 ( V_94 ) ;
if ( V_95 ) {
F_44 ( & V_30 -> V_14 ) ;
goto V_113;
} else
goto V_117;
}
F_105 ( V_76 , V_8 , V_94 , V_95 ) ;
F_104 ( V_94 ) ;
F_44 ( & V_30 -> V_14 ) ;
goto V_113;
V_117:
F_104 ( V_94 ) ;
F_44 ( & V_30 -> V_14 ) ;
return V_33 ;
}
static void F_111 ( struct V_2 * V_6 )
{
struct V_24 * V_26 ;
if ( V_6 &&
F_29 ( V_118 , & V_6 -> V_41 ) ) {
F_18 ( ! V_6 -> V_8 ) ;
F_37 ( V_118 , & V_6 -> V_41 ) ;
V_6 -> V_49 -- ;
V_26 = V_6 -> V_8 -> V_25 -> V_26 ;
F_65 ( V_26 ) ;
}
}
static void F_112 ( struct V_2 * V_6 )
{
struct V_24 * V_26 ;
ASSERT ( V_6 -> V_8 ) ;
F_37 ( V_119 , & V_6 -> V_41 ) ;
V_6 -> V_49 -- ;
V_26 = V_6 -> V_8 -> V_25 -> V_26 ;
F_65 ( V_26 ) ;
}
static int F_113 ( struct V_75 * V_76 ,
struct V_7 * V_8 ,
struct V_93 * V_94 ,
struct V_2 * V_30 )
{
struct V_55 V_20 ;
struct V_120 * V_121 ;
struct V_99 * V_100 ;
int V_38 ;
int V_33 ;
V_20 . V_22 = V_30 -> V_9 ;
V_20 . type = V_122 ;
V_20 . V_23 = 0 ;
if ( F_29 ( V_119 , & V_30 -> V_41 ) )
V_38 = - 1 ;
else
V_38 = 1 ;
V_33 = F_114 ( V_76 , V_8 , V_94 , & V_20 , V_38 ) ;
if ( V_33 > 0 ) {
F_104 ( V_94 ) ;
return - V_116 ;
} else if ( V_33 < 0 ) {
return V_33 ;
}
V_100 = V_94 -> V_44 [ 0 ] ;
V_121 = F_97 ( V_100 , V_94 -> V_110 [ 0 ] ,
struct V_120 ) ;
F_98 ( V_100 , & V_30 -> V_121 , ( unsigned long ) V_121 ,
sizeof( struct V_120 ) ) ;
F_102 ( V_100 ) ;
if ( ! F_29 ( V_119 , & V_30 -> V_41 ) )
goto V_123;
V_94 -> V_110 [ 0 ] ++ ;
if ( V_94 -> V_110 [ 0 ] >= F_106 ( V_100 ) )
goto V_124;
V_34:
F_107 ( V_100 , & V_20 , V_94 -> V_110 [ 0 ] ) ;
if ( V_20 . V_22 != V_30 -> V_9 )
goto V_47;
if ( V_20 . type != V_125 &&
V_20 . type != V_126 )
goto V_47;
F_115 ( V_76 , V_8 , V_94 ) ;
V_47:
F_112 ( V_30 ) ;
V_123:
F_104 ( V_94 ) ;
V_127:
F_88 ( V_8 , V_30 ) ;
F_111 ( V_30 ) ;
return V_33 ;
V_124:
F_104 ( V_94 ) ;
V_20 . type = V_126 ;
V_20 . V_23 = - 1 ;
V_33 = F_110 ( V_76 , V_8 , & V_20 , V_94 , - 1 , 1 ) ;
if ( V_33 < 0 )
goto V_127;
ASSERT ( V_33 ) ;
V_33 = 0 ;
V_100 = V_94 -> V_44 [ 0 ] ;
V_94 -> V_110 [ 0 ] -- ;
goto V_34;
}
static inline int F_116 ( struct V_75 * V_76 ,
struct V_7 * V_8 ,
struct V_93 * V_94 ,
struct V_2 * V_30 )
{
int V_33 ;
F_43 ( & V_30 -> V_14 ) ;
if ( ! F_29 ( V_118 , & V_30 -> V_41 ) ) {
F_44 ( & V_30 -> V_14 ) ;
return 0 ;
}
V_33 = F_113 ( V_76 , V_8 , V_94 , V_30 ) ;
F_44 ( & V_30 -> V_14 ) ;
return V_33 ;
}
static inline int
F_117 ( struct V_75 * V_76 ,
struct V_93 * V_94 ,
struct V_2 * V_30 )
{
int V_33 ;
V_33 = F_103 ( V_76 , V_94 , V_30 -> V_8 , V_30 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_109 ( V_76 , V_94 , V_30 -> V_8 , V_30 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_116 ( V_76 , V_30 -> V_8 , V_94 , V_30 ) ;
return V_33 ;
}
static int F_118 ( struct V_75 * V_76 ,
struct V_7 * V_8 , int V_128 )
{
struct V_24 * V_26 ;
struct V_2 * V_129 , * V_58 ;
struct V_93 * V_94 ;
struct V_77 * V_81 ;
int V_33 = 0 ;
bool V_49 = ( V_128 > 0 ) ;
if ( V_76 -> V_130 )
return - V_131 ;
V_94 = F_119 () ;
if ( ! V_94 )
return - V_5 ;
V_94 -> V_132 = 1 ;
V_81 = V_76 -> V_81 ;
V_76 -> V_81 = & V_8 -> V_25 -> V_82 ;
V_26 = F_10 ( V_8 ) ;
V_129 = F_38 ( V_26 ) ;
while ( V_129 && ( ! V_49 || ( V_49 && V_128 -- ) ) ) {
V_33 = F_117 ( V_76 , V_94 ,
V_129 ) ;
if ( V_33 ) {
F_48 ( V_129 ) ;
V_129 = NULL ;
F_120 ( V_76 , V_8 , V_33 ) ;
break;
}
V_58 = V_129 ;
V_129 = F_40 ( V_129 ) ;
F_48 ( V_58 ) ;
}
if ( V_129 )
F_48 ( V_129 ) ;
F_121 ( V_94 ) ;
V_76 -> V_81 = V_81 ;
return V_33 ;
}
int F_122 ( struct V_75 * V_76 ,
struct V_7 * V_8 )
{
return F_118 ( V_76 , V_8 , - 1 ) ;
}
int F_123 ( struct V_75 * V_76 ,
struct V_7 * V_8 , int V_128 )
{
return F_118 ( V_76 , V_8 , V_128 ) ;
}
int F_124 ( struct V_75 * V_76 ,
struct V_27 * V_27 )
{
struct V_2 * V_6 = F_11 ( V_27 ) ;
struct V_93 * V_94 ;
struct V_77 * V_81 ;
int V_33 ;
if ( ! V_6 )
return 0 ;
F_43 ( & V_6 -> V_14 ) ;
if ( ! V_6 -> V_49 ) {
F_44 ( & V_6 -> V_14 ) ;
F_48 ( V_6 ) ;
return 0 ;
}
F_44 ( & V_6 -> V_14 ) ;
V_94 = F_119 () ;
if ( ! V_94 ) {
F_48 ( V_6 ) ;
return - V_5 ;
}
V_94 -> V_132 = 1 ;
V_81 = V_76 -> V_81 ;
V_76 -> V_81 = & V_6 -> V_8 -> V_25 -> V_82 ;
V_33 = F_117 ( V_76 , V_94 , V_6 ) ;
F_48 ( V_6 ) ;
F_121 ( V_94 ) ;
V_76 -> V_81 = V_81 ;
return V_33 ;
}
int F_125 ( struct V_27 * V_27 )
{
struct V_75 * V_76 ;
struct V_2 * V_6 = F_11 ( V_27 ) ;
struct V_93 * V_94 ;
struct V_77 * V_81 ;
int V_33 ;
if ( ! V_6 )
return 0 ;
F_43 ( & V_6 -> V_14 ) ;
if ( ! F_29 ( V_118 , & V_6 -> V_41 ) ) {
F_44 ( & V_6 -> V_14 ) ;
F_48 ( V_6 ) ;
return 0 ;
}
F_44 ( & V_6 -> V_14 ) ;
V_76 = F_126 ( V_6 -> V_8 ) ;
if ( F_127 ( V_76 ) ) {
V_33 = F_128 ( V_76 ) ;
goto V_47;
}
V_94 = F_119 () ;
if ( ! V_94 ) {
V_33 = - V_5 ;
goto V_133;
}
V_94 -> V_132 = 1 ;
V_81 = V_76 -> V_81 ;
V_76 -> V_81 = & V_6 -> V_8 -> V_25 -> V_82 ;
F_43 ( & V_6 -> V_14 ) ;
if ( F_29 ( V_118 , & V_6 -> V_41 ) )
V_33 = F_113 ( V_76 , V_6 -> V_8 ,
V_94 , V_6 ) ;
else
V_33 = 0 ;
F_44 ( & V_6 -> V_14 ) ;
F_121 ( V_94 ) ;
V_76 -> V_81 = V_81 ;
V_133:
F_129 ( V_76 , V_6 -> V_8 ) ;
F_130 ( V_6 -> V_8 ) ;
V_47:
F_48 ( V_6 ) ;
return V_33 ;
}
void F_131 ( struct V_27 * V_27 )
{
struct V_2 * V_6 ;
V_6 = F_14 ( F_12 ( V_27 ) -> V_6 ) ;
if ( ! V_6 )
return;
F_12 ( V_27 ) -> V_6 = NULL ;
F_48 ( V_6 ) ;
}
static void F_132 ( struct V_134 * V_135 )
{
struct V_136 * V_137 ;
struct V_24 * V_26 ;
struct V_75 * V_76 ;
struct V_93 * V_94 ;
struct V_2 * V_6 = NULL ;
struct V_7 * V_8 ;
struct V_77 * V_81 ;
int V_138 = 0 ;
V_137 = F_133 ( V_135 , struct V_136 , V_135 ) ;
V_26 = V_137 -> V_26 ;
V_94 = F_119 () ;
if ( ! V_94 )
goto V_47;
V_34:
if ( F_46 ( & V_26 -> V_69 ) < V_72 / 2 )
goto V_139;
V_6 = F_49 ( V_26 ) ;
if ( ! V_6 )
goto V_139;
V_94 -> V_132 = 1 ;
V_8 = V_6 -> V_8 ;
V_76 = F_126 ( V_8 ) ;
if ( F_127 ( V_76 ) )
goto V_140;
V_81 = V_76 -> V_81 ;
V_76 -> V_81 = & V_8 -> V_25 -> V_82 ;
F_117 ( V_76 , V_94 , V_6 ) ;
V_76 -> V_81 = V_81 ;
F_129 ( V_76 , V_8 ) ;
F_134 ( V_8 ) ;
V_140:
F_104 ( V_94 ) ;
V_138 ++ ;
F_50 ( V_6 ) ;
if ( V_137 -> V_128 == 0 || V_138 < V_137 -> V_128 )
goto V_34;
V_139:
F_121 ( V_94 ) ;
V_47:
F_69 ( & V_26 -> V_74 ) ;
F_73 ( V_137 ) ;
}
static int F_135 ( struct V_24 * V_26 ,
struct V_141 * V_25 , int V_128 )
{
struct V_136 * V_137 ;
if ( F_46 ( & V_26 -> V_69 ) < V_72 )
return 0 ;
V_137 = F_52 ( sizeof( * V_137 ) , V_35 ) ;
if ( ! V_137 )
return - V_5 ;
V_137 -> V_26 = V_26 ;
F_136 ( & V_137 -> V_135 , V_142 ,
F_132 , NULL , NULL ) ;
V_137 -> V_128 = V_128 ;
F_137 ( V_25 -> V_143 , & V_137 -> V_135 ) ;
return 0 ;
}
void F_138 ( struct V_7 * V_8 )
{
struct V_24 * V_26 ;
V_26 = F_10 ( V_8 ) ;
F_87 ( F_38 ( V_26 ) ) ;
}
static int F_139 ( struct V_24 * V_26 , int V_70 )
{
int V_144 = F_46 ( & V_26 -> V_71 ) ;
if ( V_144 < V_70 || V_144 >= V_70 + V_73 )
return 1 ;
if ( F_46 ( & V_26 -> V_69 ) < V_72 )
return 1 ;
return 0 ;
}
void F_140 ( struct V_7 * V_8 )
{
struct V_24 * V_26 ;
struct V_141 * V_25 = V_8 -> V_25 ;
V_26 = F_10 ( V_8 ) ;
if ( F_46 ( & V_26 -> V_69 ) < V_72 )
return;
if ( F_46 ( & V_26 -> V_69 ) >= V_145 ) {
int V_70 ;
int V_33 ;
V_70 = F_46 ( & V_26 -> V_71 ) ;
V_33 = F_135 ( V_26 , V_25 , 0 ) ;
if ( V_33 )
return;
F_141 ( V_26 -> V_74 ,
F_139 ( V_26 , V_70 ) ) ;
return;
}
F_135 ( V_26 , V_25 , V_73 ) ;
}
int F_142 ( struct V_75 * V_76 ,
struct V_7 * V_8 , const char * V_146 ,
int V_147 , struct V_27 * V_148 ,
struct V_149 * V_150 , T_4 type ,
T_2 V_151 )
{
struct V_2 * V_6 ;
struct V_17 * V_59 ;
struct V_152 * V_153 ;
int V_33 ;
V_6 = F_21 ( V_148 ) ;
if ( F_127 ( V_6 ) )
return F_128 ( V_6 ) ;
V_59 = F_51 ( sizeof( * V_153 ) + V_147 ) ;
if ( ! V_59 ) {
V_33 = - V_5 ;
goto V_154;
}
V_59 -> V_20 . V_22 = F_13 ( V_148 ) ;
V_59 -> V_20 . type = V_21 ;
V_59 -> V_20 . V_23 = V_151 ;
V_153 = (struct V_152 * ) V_59 -> V_111 ;
V_153 -> V_155 = * V_150 ;
F_143 ( V_153 , V_76 -> V_156 ) ;
F_144 ( V_153 , 0 ) ;
F_145 ( V_153 , V_147 ) ;
F_146 ( V_153 , type ) ;
memcpy ( ( char * ) ( V_153 + 1 ) , V_146 , V_147 ) ;
V_33 = F_78 ( V_76 , V_8 , V_59 ) ;
F_18 ( V_33 ) ;
F_43 ( & V_6 -> V_14 ) ;
V_33 = F_63 ( V_6 , V_59 ) ;
if ( F_147 ( V_33 ) ) {
F_148 ( V_8 -> V_25 , L_5
L_6
L_7 ,
V_147 , V_146 , V_6 -> V_8 -> V_22 ,
V_6 -> V_9 , V_33 ) ;
F_60 () ;
}
F_44 ( & V_6 -> V_14 ) ;
V_154:
F_48 ( V_6 ) ;
return V_33 ;
}
static int F_149 ( struct V_7 * V_8 ,
struct V_2 * V_30 ,
struct V_55 * V_20 )
{
struct V_17 * V_51 ;
F_43 ( & V_30 -> V_14 ) ;
V_51 = F_58 ( V_30 , V_20 ) ;
if ( ! V_51 ) {
F_44 ( & V_30 -> V_14 ) ;
return 1 ;
}
F_82 ( V_8 , V_51 ) ;
F_72 ( V_51 ) ;
F_44 ( & V_30 -> V_14 ) ;
return 0 ;
}
int F_150 ( struct V_75 * V_76 ,
struct V_7 * V_8 , struct V_27 * V_148 ,
T_2 V_151 )
{
struct V_2 * V_30 ;
struct V_17 * V_51 ;
struct V_55 V_157 ;
int V_33 ;
V_30 = F_21 ( V_148 ) ;
if ( F_127 ( V_30 ) )
return F_128 ( V_30 ) ;
V_157 . V_22 = F_13 ( V_148 ) ;
V_157 . type = V_21 ;
V_157 . V_23 = V_151 ;
V_33 = F_149 ( V_8 , V_30 , & V_157 ) ;
if ( ! V_33 )
goto V_158;
V_51 = F_51 ( 0 ) ;
if ( ! V_51 ) {
V_33 = - V_5 ;
goto V_158;
}
V_51 -> V_20 = V_157 ;
V_33 = F_78 ( V_76 , V_8 , V_51 ) ;
F_18 ( V_33 ) ;
F_43 ( & V_30 -> V_14 ) ;
V_33 = F_64 ( V_30 , V_51 ) ;
if ( F_147 ( V_33 ) ) {
F_148 ( V_8 -> V_25 , L_8
L_9
L_7 ,
V_151 , V_30 -> V_8 -> V_22 , V_30 -> V_9 ,
V_33 ) ;
F_60 () ;
}
F_44 ( & V_30 -> V_14 ) ;
V_158:
F_48 ( V_30 ) ;
return V_33 ;
}
int F_151 ( struct V_27 * V_27 )
{
struct V_2 * V_6 = F_11 ( V_27 ) ;
if ( ! V_6 )
return - V_116 ;
if ( ! V_6 -> V_68 ) {
F_48 ( V_6 ) ;
return - V_159 ;
}
F_12 ( V_27 ) -> V_68 = V_6 -> V_68 ;
F_48 ( V_6 ) ;
return 0 ;
}
void F_152 ( struct V_27 * V_27 , struct V_45 * V_160 ,
struct V_45 * V_161 )
{
struct V_2 * V_6 ;
struct V_17 * V_51 ;
V_6 = F_11 ( V_27 ) ;
if ( ! V_6 )
return;
F_43 ( & V_6 -> V_14 ) ;
V_51 = F_74 ( V_6 ) ;
while ( V_51 ) {
F_15 ( & V_51 -> V_10 ) ;
F_32 ( & V_51 -> V_162 , V_160 ) ;
V_51 = F_77 ( V_51 ) ;
}
V_51 = F_76 ( V_6 ) ;
while ( V_51 ) {
F_15 ( & V_51 -> V_10 ) ;
F_32 ( & V_51 -> V_162 , V_161 ) ;
V_51 = F_77 ( V_51 ) ;
}
F_44 ( & V_6 -> V_14 ) ;
F_35 ( & V_6 -> V_10 ) ;
}
void F_153 ( struct V_45 * V_160 ,
struct V_45 * V_161 )
{
struct V_17 * V_95 , * V_48 ;
F_96 (curr, next, ins_list, readdir_list) {
F_99 ( & V_95 -> V_162 ) ;
if ( F_45 ( & V_95 -> V_10 ) )
F_73 ( V_95 ) ;
}
F_96 (curr, next, del_list, readdir_list) {
F_99 ( & V_95 -> V_162 ) ;
if ( F_45 ( & V_95 -> V_10 ) )
F_73 ( V_95 ) ;
}
}
int F_154 ( struct V_45 * V_161 ,
T_2 V_151 )
{
struct V_17 * V_95 , * V_48 ;
int V_33 ;
if ( F_30 ( V_161 ) )
return 0 ;
F_96 (curr, next, del_list, readdir_list) {
if ( V_95 -> V_20 . V_23 > V_151 )
break;
F_99 ( & V_95 -> V_162 ) ;
V_33 = ( V_95 -> V_20 . V_23 == V_151 ) ;
if ( F_45 ( & V_95 -> V_10 ) )
F_73 ( V_95 ) ;
if ( V_33 )
return 1 ;
else
continue;
}
return 0 ;
}
int F_155 ( struct V_163 * V_164 ,
struct V_45 * V_160 , bool * V_165 )
{
struct V_152 * V_166 ;
struct V_17 * V_95 , * V_48 ;
struct V_55 V_155 ;
char * V_146 ;
int V_147 ;
int V_167 = 0 ;
unsigned char V_168 ;
if ( F_30 ( V_160 ) )
return 0 ;
F_96 (curr, next, ins_list, readdir_list) {
F_99 ( & V_95 -> V_162 ) ;
if ( V_95 -> V_20 . V_23 < V_164 -> V_169 ) {
if ( F_45 ( & V_95 -> V_10 ) )
F_73 ( V_95 ) ;
continue;
}
V_164 -> V_169 = V_95 -> V_20 . V_23 ;
V_166 = (struct V_152 * ) V_95 -> V_111 ;
V_146 = ( char * ) ( V_166 + 1 ) ;
V_147 = F_156 ( V_166 ) ;
V_168 = V_170 [ V_166 -> type ] ;
F_157 ( & V_155 , & V_166 -> V_155 ) ;
V_167 = ! F_158 ( V_164 , V_146 , V_147 ,
V_155 . V_22 , V_168 ) ;
if ( F_45 ( & V_95 -> V_10 ) )
F_73 ( V_95 ) ;
if ( V_167 )
return 1 ;
* V_165 = true ;
}
return 0 ;
}
static void F_159 ( struct V_75 * V_76 ,
struct V_120 * V_121 ,
struct V_27 * V_27 )
{
F_160 ( V_121 , F_161 ( V_27 ) ) ;
F_162 ( V_121 , F_163 ( V_27 ) ) ;
F_164 ( V_121 , F_12 ( V_27 ) -> V_171 ) ;
F_165 ( V_121 , V_27 -> V_172 ) ;
F_166 ( V_121 , V_27 -> V_173 ) ;
F_167 ( V_121 , F_168 ( V_27 ) ) ;
F_169 ( V_121 ,
F_12 ( V_27 ) -> V_174 ) ;
F_170 ( V_121 , V_27 -> V_175 ) ;
F_171 ( V_121 , V_76 -> V_156 ) ;
F_172 ( V_121 , V_27 -> V_176 ) ;
F_173 ( V_121 , F_12 ( V_27 ) -> V_41 ) ;
F_174 ( V_121 , 0 ) ;
F_175 ( & V_121 -> V_177 ,
V_27 -> V_178 . V_179 ) ;
F_176 ( & V_121 -> V_177 ,
V_27 -> V_178 . V_180 ) ;
F_175 ( & V_121 -> V_181 ,
V_27 -> V_182 . V_179 ) ;
F_176 ( & V_121 -> V_181 ,
V_27 -> V_182 . V_180 ) ;
F_175 ( & V_121 -> ctime ,
V_27 -> V_183 . V_179 ) ;
F_176 ( & V_121 -> ctime ,
V_27 -> V_183 . V_180 ) ;
F_175 ( & V_121 -> V_184 ,
F_12 ( V_27 ) -> V_185 . V_179 ) ;
F_176 ( & V_121 -> V_184 ,
F_12 ( V_27 ) -> V_185 . V_180 ) ;
}
int F_177 ( struct V_27 * V_27 , T_3 * V_186 )
{
struct V_2 * V_6 ;
struct V_120 * V_121 ;
V_6 = F_11 ( V_27 ) ;
if ( ! V_6 )
return - V_116 ;
F_43 ( & V_6 -> V_14 ) ;
if ( ! F_29 ( V_118 , & V_6 -> V_41 ) ) {
F_44 ( & V_6 -> V_14 ) ;
F_48 ( V_6 ) ;
return - V_116 ;
}
V_121 = & V_6 -> V_121 ;
F_178 ( V_27 , F_179 ( V_121 ) ) ;
F_180 ( V_27 , F_181 ( V_121 ) ) ;
F_182 ( V_27 , F_183 ( V_121 ) ) ;
V_27 -> V_172 = F_184 ( V_121 ) ;
F_185 ( V_27 , F_186 ( V_121 ) ) ;
F_187 ( V_27 , F_188 ( V_121 ) ) ;
F_12 ( V_27 ) -> V_174 = F_189 ( V_121 ) ;
F_12 ( V_27 ) -> V_187 = F_190 ( V_121 ) ;
V_27 -> V_175 = F_191 ( V_121 ) ;
V_27 -> V_176 = 0 ;
* V_186 = F_192 ( V_121 ) ;
F_12 ( V_27 ) -> V_41 = F_193 ( V_121 ) ;
V_27 -> V_178 . V_179 = F_194 ( & V_121 -> V_177 ) ;
V_27 -> V_178 . V_180 = F_195 ( & V_121 -> V_177 ) ;
V_27 -> V_182 . V_179 = F_194 ( & V_121 -> V_181 ) ;
V_27 -> V_182 . V_180 = F_195 ( & V_121 -> V_181 ) ;
V_27 -> V_183 . V_179 = F_194 ( & V_121 -> ctime ) ;
V_27 -> V_183 . V_180 = F_195 ( & V_121 -> ctime ) ;
F_12 ( V_27 ) -> V_185 . V_179 =
F_194 ( & V_121 -> V_184 ) ;
F_12 ( V_27 ) -> V_185 . V_180 =
F_195 ( & V_121 -> V_184 ) ;
V_27 -> V_188 = F_12 ( V_27 ) -> V_174 ;
F_12 ( V_27 ) -> V_68 = ( T_2 ) - 1 ;
F_44 ( & V_6 -> V_14 ) ;
F_48 ( V_6 ) ;
return 0 ;
}
int F_196 ( struct V_75 * V_76 ,
struct V_7 * V_8 , struct V_27 * V_27 )
{
struct V_2 * V_6 ;
int V_33 = 0 ;
V_6 = F_21 ( V_27 ) ;
if ( F_127 ( V_6 ) )
return F_128 ( V_6 ) ;
F_43 ( & V_6 -> V_14 ) ;
if ( F_29 ( V_118 , & V_6 -> V_41 ) ) {
F_159 ( V_76 , & V_6 -> V_121 , V_27 ) ;
goto V_154;
}
V_33 = F_84 ( V_76 , V_8 , V_27 ,
V_6 ) ;
if ( V_33 )
goto V_154;
F_159 ( V_76 , & V_6 -> V_121 , V_27 ) ;
F_33 ( V_118 , & V_6 -> V_41 ) ;
V_6 -> V_49 ++ ;
F_15 ( & V_8 -> V_25 -> V_26 -> V_69 ) ;
V_154:
F_44 ( & V_6 -> V_14 ) ;
F_48 ( V_6 ) ;
return V_33 ;
}
int F_197 ( struct V_27 * V_27 )
{
struct V_2 * V_6 ;
if ( F_12 ( V_27 ) -> V_8 -> V_25 -> V_189 )
return - V_87 ;
V_6 = F_21 ( V_27 ) ;
if ( F_127 ( V_6 ) )
return F_128 ( V_6 ) ;
F_43 ( & V_6 -> V_14 ) ;
if ( F_29 ( V_119 , & V_6 -> V_41 ) )
goto V_154;
F_33 ( V_119 , & V_6 -> V_41 ) ;
V_6 -> V_49 ++ ;
F_15 ( & F_12 ( V_27 ) -> V_8 -> V_25 -> V_26 -> V_69 ) ;
V_154:
F_44 ( & V_6 -> V_14 ) ;
F_48 ( V_6 ) ;
return 0 ;
}
static void F_198 ( struct V_2 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_17 * V_190 , * V_191 ;
F_43 ( & V_6 -> V_14 ) ;
V_190 = F_74 ( V_6 ) ;
while ( V_190 ) {
F_82 ( V_8 , V_190 ) ;
V_191 = V_190 ;
V_190 = F_77 ( V_191 ) ;
F_72 ( V_191 ) ;
}
V_190 = F_76 ( V_6 ) ;
while ( V_190 ) {
F_82 ( V_8 , V_190 ) ;
V_191 = V_190 ;
V_190 = F_77 ( V_191 ) ;
F_72 ( V_191 ) ;
}
if ( F_29 ( V_119 , & V_6 -> V_41 ) )
F_112 ( V_6 ) ;
if ( F_29 ( V_118 , & V_6 -> V_41 ) ) {
F_88 ( V_8 , V_6 ) ;
F_111 ( V_6 ) ;
}
F_44 ( & V_6 -> V_14 ) ;
}
void F_199 ( struct V_27 * V_27 )
{
struct V_2 * V_6 ;
V_6 = F_11 ( V_27 ) ;
if ( ! V_6 )
return;
F_198 ( V_6 ) ;
F_48 ( V_6 ) ;
}
void F_200 ( struct V_7 * V_8 )
{
T_2 V_9 = 0 ;
struct V_2 * V_192 [ 8 ] ;
int V_107 , V_193 ;
while ( 1 ) {
F_16 ( & V_8 -> V_31 ) ;
V_193 = F_201 ( & V_8 -> V_32 ,
( void * * ) V_192 , V_9 ,
F_202 ( V_192 ) ) ;
if ( ! V_193 ) {
F_19 ( & V_8 -> V_31 ) ;
break;
}
V_9 = V_192 [ V_193 - 1 ] -> V_9 + 1 ;
for ( V_107 = 0 ; V_107 < V_193 ; V_107 ++ )
F_15 ( & V_192 [ V_107 ] -> V_10 ) ;
F_19 ( & V_8 -> V_31 ) ;
for ( V_107 = 0 ; V_107 < V_193 ; V_107 ++ ) {
F_198 ( V_192 [ V_107 ] ) ;
F_48 ( V_192 [ V_107 ] ) ;
}
}
}
void F_203 ( struct V_7 * V_8 )
{
struct V_24 * V_26 ;
struct V_2 * V_129 , * V_58 ;
V_26 = F_10 ( V_8 ) ;
V_129 = F_38 ( V_26 ) ;
while ( V_129 ) {
F_198 ( V_129 ) ;
V_58 = V_129 ;
V_129 = F_40 ( V_129 ) ;
F_48 ( V_58 ) ;
}
}
