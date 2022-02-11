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
if ( ! V_33 )
goto V_47;
if ( F_87 ( V_8 , V_92 ) ) {
F_88 ( V_8 -> V_25 ,
L_4 , V_33 ) ;
F_89 ( 1 ) ;
}
V_33 = F_80 ( & V_8 -> V_25 -> V_93 ,
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
F_81 ( V_8 -> V_25 , L_5 ,
F_13 ( V_27 ) , V_80 , 0 ) ;
F_83 ( V_8 , V_78 , V_80 ) ;
}
return V_33 ;
}
static void F_90 ( struct V_7 * V_8 ,
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
static int F_91 ( struct V_7 * V_8 ,
struct V_94 * V_95 ,
struct V_17 * V_51 )
{
struct V_17 * V_96 , * V_48 ;
int V_97 ;
int V_98 = 0 , V_99 = 0 ;
struct V_100 * V_101 ;
char * V_102 ;
struct V_55 * V_103 ;
T_3 * V_104 ;
struct V_45 V_105 ;
int V_106 ;
int V_107 ;
int V_108 ;
int V_33 = 0 ;
F_18 ( ! V_95 -> V_44 [ 0 ] ) ;
V_101 = V_95 -> V_44 [ 0 ] ;
V_97 = F_92 ( V_8 , V_101 ) ;
F_8 ( & V_105 ) ;
V_48 = V_51 ;
V_107 = 0 ;
while ( V_99 + V_48 -> V_50 + sizeof( struct V_109 ) <=
V_97 ) {
V_98 += V_48 -> V_50 ;
V_99 += V_48 -> V_50 + sizeof( struct V_109 ) ;
F_32 ( & V_48 -> V_110 , & V_105 ) ;
V_107 ++ ;
V_96 = V_48 ;
V_48 = F_77 ( V_96 ) ;
if ( ! V_48 )
break;
if ( ! F_9 ( V_96 , V_48 ) )
break;
}
if ( ! V_107 ) {
V_33 = 0 ;
goto V_47;
}
F_93 ( V_95 ) ;
V_103 = F_94 ( V_107 , sizeof( struct V_55 ) , V_35 ) ;
if ( ! V_103 ) {
V_33 = - V_5 ;
goto V_47;
}
V_104 = F_94 ( V_107 , sizeof( T_3 ) , V_35 ) ;
if ( ! V_104 ) {
V_33 = - V_5 ;
goto error;
}
V_108 = 0 ;
F_95 (next, &head, tree_list) {
V_103 [ V_108 ] = V_48 -> V_20 ;
V_104 [ V_108 ] = V_48 -> V_50 ;
V_108 ++ ;
}
F_96 ( V_95 , NULL , 0 ) ;
F_97 ( V_8 , V_95 , V_103 , V_104 ,
V_98 , V_99 , V_107 ) ;
V_106 = V_95 -> V_111 [ 0 ] ;
F_98 (curr, next, &head, tree_list) {
V_102 = F_99 ( V_101 , V_106 , char ) ;
F_100 ( V_101 , & V_96 -> V_112 ,
( unsigned long ) V_102 ,
V_96 -> V_50 ) ;
V_106 ++ ;
F_82 ( V_8 , V_96 ) ;
F_101 ( & V_96 -> V_110 ) ;
F_72 ( V_96 ) ;
}
error:
F_73 ( V_104 ) ;
F_73 ( V_103 ) ;
V_47:
return V_33 ;
}
static int F_102 ( struct V_75 * V_76 ,
struct V_7 * V_8 ,
struct V_94 * V_95 ,
struct V_17 * V_59 )
{
struct V_100 * V_101 ;
char * V_113 ;
int V_33 ;
V_33 = F_103 ( V_76 , V_8 , V_95 , & V_59 -> V_20 ,
V_59 -> V_50 ) ;
if ( V_33 < 0 && V_33 != - V_37 )
return V_33 ;
V_101 = V_95 -> V_44 [ 0 ] ;
V_113 = F_99 ( V_101 , V_95 -> V_111 [ 0 ] , char ) ;
F_100 ( V_101 , V_59 -> V_112 , ( unsigned long ) V_113 ,
V_59 -> V_50 ) ;
F_104 ( V_101 ) ;
F_82 ( V_8 , V_59 ) ;
return 0 ;
}
static int F_105 ( struct V_75 * V_76 ,
struct V_94 * V_95 ,
struct V_7 * V_8 ,
struct V_2 * V_30 )
{
struct V_17 * V_96 , * V_56 ;
int V_33 = 0 ;
V_114:
F_43 ( & V_30 -> V_14 ) ;
V_96 = F_74 ( V_30 ) ;
if ( ! V_96 )
goto V_115;
V_33 = F_102 ( V_76 , V_8 , V_95 , V_96 ) ;
if ( V_33 < 0 ) {
F_106 ( V_95 ) ;
goto V_115;
}
V_56 = V_96 ;
V_96 = F_77 ( V_56 ) ;
if ( V_96 && F_9 ( V_56 , V_96 ) ) {
V_95 -> V_111 [ 0 ] ++ ;
F_91 ( V_8 , V_95 , V_96 ) ;
}
F_72 ( V_56 ) ;
F_104 ( V_95 -> V_44 [ 0 ] ) ;
F_106 ( V_95 ) ;
F_44 ( & V_30 -> V_14 ) ;
goto V_114;
V_115:
F_44 ( & V_30 -> V_14 ) ;
return V_33 ;
}
static int F_107 ( struct V_75 * V_76 ,
struct V_7 * V_8 ,
struct V_94 * V_95 ,
struct V_17 * V_51 )
{
struct V_17 * V_96 , * V_48 ;
struct V_100 * V_101 ;
struct V_55 V_20 ;
struct V_45 V_105 ;
int V_107 , V_108 , V_116 ;
int V_33 = 0 ;
F_18 ( ! V_95 -> V_44 [ 0 ] ) ;
V_101 = V_95 -> V_44 [ 0 ] ;
V_108 = V_95 -> V_111 [ 0 ] ;
V_116 = F_108 ( V_101 ) - 1 ;
if ( V_108 > V_116 )
return - V_117 ;
V_48 = V_51 ;
F_8 ( & V_105 ) ;
F_109 ( V_101 , & V_20 , V_108 ) ;
V_107 = 0 ;
while ( F_55 ( & V_48 -> V_20 , & V_20 ) == 0 ) {
F_32 ( & V_48 -> V_110 , & V_105 ) ;
V_107 ++ ;
V_96 = V_48 ;
V_48 = F_77 ( V_96 ) ;
if ( ! V_48 )
break;
if ( ! F_9 ( V_96 , V_48 ) )
break;
V_108 ++ ;
if ( V_108 > V_116 )
break;
F_109 ( V_101 , & V_20 , V_108 ) ;
}
if ( ! V_107 )
return 0 ;
V_33 = F_110 ( V_76 , V_8 , V_95 , V_95 -> V_111 [ 0 ] , V_107 ) ;
if ( V_33 )
goto V_47;
F_98 (curr, next, &head, tree_list) {
F_82 ( V_8 , V_96 ) ;
F_101 ( & V_96 -> V_110 ) ;
F_72 ( V_96 ) ;
}
V_47:
return V_33 ;
}
static int F_111 ( struct V_75 * V_76 ,
struct V_94 * V_95 ,
struct V_7 * V_8 ,
struct V_2 * V_30 )
{
struct V_17 * V_96 , * V_56 ;
int V_33 = 0 ;
V_114:
F_43 ( & V_30 -> V_14 ) ;
V_96 = F_76 ( V_30 ) ;
if ( ! V_96 )
goto V_118;
V_33 = F_112 ( V_76 , V_8 , & V_96 -> V_20 , V_95 , - 1 , 1 ) ;
if ( V_33 < 0 )
goto V_118;
else if ( V_33 > 0 ) {
V_56 = V_96 ;
V_96 = F_77 ( V_56 ) ;
F_72 ( V_56 ) ;
V_33 = 0 ;
F_106 ( V_95 ) ;
if ( V_96 ) {
F_44 ( & V_30 -> V_14 ) ;
goto V_114;
} else
goto V_118;
}
F_107 ( V_76 , V_8 , V_95 , V_96 ) ;
F_106 ( V_95 ) ;
F_44 ( & V_30 -> V_14 ) ;
goto V_114;
V_118:
F_106 ( V_95 ) ;
F_44 ( & V_30 -> V_14 ) ;
return V_33 ;
}
static void F_113 ( struct V_2 * V_6 )
{
struct V_24 * V_26 ;
if ( V_6 &&
F_29 ( V_119 , & V_6 -> V_41 ) ) {
F_18 ( ! V_6 -> V_8 ) ;
F_37 ( V_119 , & V_6 -> V_41 ) ;
V_6 -> V_49 -- ;
V_26 = V_6 -> V_8 -> V_25 -> V_26 ;
F_65 ( V_26 ) ;
}
}
static void F_114 ( struct V_2 * V_6 )
{
struct V_24 * V_26 ;
ASSERT ( V_6 -> V_8 ) ;
F_37 ( V_120 , & V_6 -> V_41 ) ;
V_6 -> V_49 -- ;
V_26 = V_6 -> V_8 -> V_25 -> V_26 ;
F_65 ( V_26 ) ;
}
static int F_115 ( struct V_75 * V_76 ,
struct V_7 * V_8 ,
struct V_94 * V_95 ,
struct V_2 * V_30 )
{
struct V_55 V_20 ;
struct V_121 * V_122 ;
struct V_100 * V_101 ;
int V_38 ;
int V_33 ;
V_20 . V_22 = V_30 -> V_9 ;
V_20 . type = V_123 ;
V_20 . V_23 = 0 ;
if ( F_29 ( V_120 , & V_30 -> V_41 ) )
V_38 = - 1 ;
else
V_38 = 1 ;
V_33 = F_116 ( V_76 , V_8 , V_95 , & V_20 , V_38 ) ;
if ( V_33 > 0 ) {
F_106 ( V_95 ) ;
return - V_117 ;
} else if ( V_33 < 0 ) {
return V_33 ;
}
V_101 = V_95 -> V_44 [ 0 ] ;
V_122 = F_99 ( V_101 , V_95 -> V_111 [ 0 ] ,
struct V_121 ) ;
F_100 ( V_101 , & V_30 -> V_122 , ( unsigned long ) V_122 ,
sizeof( struct V_121 ) ) ;
F_104 ( V_101 ) ;
if ( ! F_29 ( V_120 , & V_30 -> V_41 ) )
goto V_124;
V_95 -> V_111 [ 0 ] ++ ;
if ( V_95 -> V_111 [ 0 ] >= F_108 ( V_101 ) )
goto V_125;
V_34:
F_109 ( V_101 , & V_20 , V_95 -> V_111 [ 0 ] ) ;
if ( V_20 . V_22 != V_30 -> V_9 )
goto V_47;
if ( V_20 . type != V_126 &&
V_20 . type != V_127 )
goto V_47;
F_117 ( V_76 , V_8 , V_95 ) ;
V_47:
F_114 ( V_30 ) ;
V_124:
F_106 ( V_95 ) ;
V_128:
F_90 ( V_8 , V_30 ) ;
F_113 ( V_30 ) ;
return V_33 ;
V_125:
F_106 ( V_95 ) ;
V_20 . type = V_127 ;
V_20 . V_23 = - 1 ;
V_33 = F_112 ( V_76 , V_8 , & V_20 , V_95 , - 1 , 1 ) ;
if ( V_33 < 0 )
goto V_128;
ASSERT ( V_33 ) ;
V_33 = 0 ;
V_101 = V_95 -> V_44 [ 0 ] ;
V_95 -> V_111 [ 0 ] -- ;
goto V_34;
}
static inline int F_118 ( struct V_75 * V_76 ,
struct V_7 * V_8 ,
struct V_94 * V_95 ,
struct V_2 * V_30 )
{
int V_33 ;
F_43 ( & V_30 -> V_14 ) ;
if ( ! F_29 ( V_119 , & V_30 -> V_41 ) ) {
F_44 ( & V_30 -> V_14 ) ;
return 0 ;
}
V_33 = F_115 ( V_76 , V_8 , V_95 , V_30 ) ;
F_44 ( & V_30 -> V_14 ) ;
return V_33 ;
}
static inline int
F_119 ( struct V_75 * V_76 ,
struct V_94 * V_95 ,
struct V_2 * V_30 )
{
int V_33 ;
V_33 = F_105 ( V_76 , V_95 , V_30 -> V_8 , V_30 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_111 ( V_76 , V_95 , V_30 -> V_8 , V_30 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_118 ( V_76 , V_30 -> V_8 , V_95 , V_30 ) ;
return V_33 ;
}
static int F_120 ( struct V_75 * V_76 ,
struct V_7 * V_8 , int V_129 )
{
struct V_24 * V_26 ;
struct V_2 * V_130 , * V_58 ;
struct V_94 * V_95 ;
struct V_77 * V_81 ;
int V_33 = 0 ;
bool V_49 = ( V_129 > 0 ) ;
if ( V_76 -> V_131 )
return - V_132 ;
V_95 = F_121 () ;
if ( ! V_95 )
return - V_5 ;
V_95 -> V_133 = 1 ;
V_81 = V_76 -> V_81 ;
V_76 -> V_81 = & V_8 -> V_25 -> V_82 ;
V_26 = F_10 ( V_8 ) ;
V_130 = F_38 ( V_26 ) ;
while ( V_130 && ( ! V_49 || ( V_49 && V_129 -- ) ) ) {
V_33 = F_119 ( V_76 , V_95 ,
V_130 ) ;
if ( V_33 ) {
F_48 ( V_130 ) ;
V_130 = NULL ;
F_122 ( V_76 , V_8 , V_33 ) ;
break;
}
V_58 = V_130 ;
V_130 = F_40 ( V_130 ) ;
F_48 ( V_58 ) ;
}
if ( V_130 )
F_48 ( V_130 ) ;
F_123 ( V_95 ) ;
V_76 -> V_81 = V_81 ;
return V_33 ;
}
int F_124 ( struct V_75 * V_76 ,
struct V_7 * V_8 )
{
return F_120 ( V_76 , V_8 , - 1 ) ;
}
int F_125 ( struct V_75 * V_76 ,
struct V_7 * V_8 , int V_129 )
{
return F_120 ( V_76 , V_8 , V_129 ) ;
}
int F_126 ( struct V_75 * V_76 ,
struct V_27 * V_27 )
{
struct V_2 * V_6 = F_11 ( V_27 ) ;
struct V_94 * V_95 ;
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
V_95 = F_121 () ;
if ( ! V_95 ) {
F_48 ( V_6 ) ;
return - V_5 ;
}
V_95 -> V_133 = 1 ;
V_81 = V_76 -> V_81 ;
V_76 -> V_81 = & V_6 -> V_8 -> V_25 -> V_82 ;
V_33 = F_119 ( V_76 , V_95 , V_6 ) ;
F_48 ( V_6 ) ;
F_123 ( V_95 ) ;
V_76 -> V_81 = V_81 ;
return V_33 ;
}
int F_127 ( struct V_27 * V_27 )
{
struct V_75 * V_76 ;
struct V_2 * V_6 = F_11 ( V_27 ) ;
struct V_94 * V_95 ;
struct V_77 * V_81 ;
int V_33 ;
if ( ! V_6 )
return 0 ;
F_43 ( & V_6 -> V_14 ) ;
if ( ! F_29 ( V_119 , & V_6 -> V_41 ) ) {
F_44 ( & V_6 -> V_14 ) ;
F_48 ( V_6 ) ;
return 0 ;
}
F_44 ( & V_6 -> V_14 ) ;
V_76 = F_128 ( V_6 -> V_8 ) ;
if ( F_129 ( V_76 ) ) {
V_33 = F_130 ( V_76 ) ;
goto V_47;
}
V_95 = F_121 () ;
if ( ! V_95 ) {
V_33 = - V_5 ;
goto V_134;
}
V_95 -> V_133 = 1 ;
V_81 = V_76 -> V_81 ;
V_76 -> V_81 = & V_6 -> V_8 -> V_25 -> V_82 ;
F_43 ( & V_6 -> V_14 ) ;
if ( F_29 ( V_119 , & V_6 -> V_41 ) )
V_33 = F_115 ( V_76 , V_6 -> V_8 ,
V_95 , V_6 ) ;
else
V_33 = 0 ;
F_44 ( & V_6 -> V_14 ) ;
F_123 ( V_95 ) ;
V_76 -> V_81 = V_81 ;
V_134:
F_131 ( V_76 , V_6 -> V_8 ) ;
F_132 ( V_6 -> V_8 ) ;
V_47:
F_48 ( V_6 ) ;
return V_33 ;
}
void F_133 ( struct V_27 * V_27 )
{
struct V_2 * V_6 ;
V_6 = F_14 ( F_12 ( V_27 ) -> V_6 ) ;
if ( ! V_6 )
return;
F_12 ( V_27 ) -> V_6 = NULL ;
F_48 ( V_6 ) ;
}
static void F_134 ( struct V_135 * V_136 )
{
struct V_137 * V_138 ;
struct V_24 * V_26 ;
struct V_75 * V_76 ;
struct V_94 * V_95 ;
struct V_2 * V_6 = NULL ;
struct V_7 * V_8 ;
struct V_77 * V_81 ;
int V_139 = 0 ;
V_138 = F_135 ( V_136 , struct V_137 , V_136 ) ;
V_26 = V_138 -> V_26 ;
V_95 = F_121 () ;
if ( ! V_95 )
goto V_47;
V_34:
if ( F_46 ( & V_26 -> V_69 ) < V_72 / 2 )
goto V_140;
V_6 = F_49 ( V_26 ) ;
if ( ! V_6 )
goto V_140;
V_95 -> V_133 = 1 ;
V_8 = V_6 -> V_8 ;
V_76 = F_128 ( V_8 ) ;
if ( F_129 ( V_76 ) )
goto V_141;
V_81 = V_76 -> V_81 ;
V_76 -> V_81 = & V_8 -> V_25 -> V_82 ;
F_119 ( V_76 , V_95 , V_6 ) ;
V_76 -> V_81 = V_81 ;
F_131 ( V_76 , V_8 ) ;
F_136 ( V_8 ) ;
V_141:
F_106 ( V_95 ) ;
V_139 ++ ;
F_50 ( V_6 ) ;
if ( V_138 -> V_129 == 0 || V_139 < V_138 -> V_129 )
goto V_34;
V_140:
F_123 ( V_95 ) ;
V_47:
F_69 ( & V_26 -> V_74 ) ;
F_73 ( V_138 ) ;
}
static int F_137 ( struct V_24 * V_26 ,
struct V_142 * V_25 , int V_129 )
{
struct V_137 * V_138 ;
if ( F_46 ( & V_26 -> V_69 ) < V_72 )
return 0 ;
V_138 = F_52 ( sizeof( * V_138 ) , V_35 ) ;
if ( ! V_138 )
return - V_5 ;
V_138 -> V_26 = V_26 ;
F_138 ( & V_138 -> V_136 , V_143 ,
F_134 , NULL , NULL ) ;
V_138 -> V_129 = V_129 ;
F_139 ( V_25 -> V_144 , & V_138 -> V_136 ) ;
return 0 ;
}
void F_140 ( struct V_7 * V_8 )
{
struct V_24 * V_26 ;
V_26 = F_10 ( V_8 ) ;
F_89 ( F_38 ( V_26 ) ) ;
}
static int F_141 ( struct V_24 * V_26 , int V_70 )
{
int V_145 = F_46 ( & V_26 -> V_71 ) ;
if ( V_145 < V_70 || V_145 >= V_70 + V_73 )
return 1 ;
if ( F_46 ( & V_26 -> V_69 ) < V_72 )
return 1 ;
return 0 ;
}
void F_142 ( struct V_7 * V_8 )
{
struct V_24 * V_26 ;
struct V_142 * V_25 = V_8 -> V_25 ;
V_26 = F_10 ( V_8 ) ;
if ( F_46 ( & V_26 -> V_69 ) < V_72 )
return;
if ( F_46 ( & V_26 -> V_69 ) >= V_146 ) {
int V_70 ;
int V_33 ;
V_70 = F_46 ( & V_26 -> V_71 ) ;
V_33 = F_137 ( V_26 , V_25 , 0 ) ;
if ( V_33 )
return;
F_143 ( V_26 -> V_74 ,
F_141 ( V_26 , V_70 ) ) ;
return;
}
F_137 ( V_26 , V_25 , V_73 ) ;
}
int F_144 ( struct V_75 * V_76 ,
struct V_7 * V_8 , const char * V_147 ,
int V_148 , struct V_27 * V_149 ,
struct V_150 * V_151 , T_4 type ,
T_2 V_152 )
{
struct V_2 * V_6 ;
struct V_17 * V_59 ;
struct V_153 * V_154 ;
int V_33 ;
V_6 = F_21 ( V_149 ) ;
if ( F_129 ( V_6 ) )
return F_130 ( V_6 ) ;
V_59 = F_51 ( sizeof( * V_154 ) + V_148 ) ;
if ( ! V_59 ) {
V_33 = - V_5 ;
goto V_155;
}
V_59 -> V_20 . V_22 = F_13 ( V_149 ) ;
V_59 -> V_20 . type = V_21 ;
V_59 -> V_20 . V_23 = V_152 ;
V_154 = (struct V_153 * ) V_59 -> V_112 ;
V_154 -> V_156 = * V_151 ;
F_145 ( V_154 , V_76 -> V_157 ) ;
F_146 ( V_154 , 0 ) ;
F_147 ( V_154 , V_148 ) ;
F_148 ( V_154 , type ) ;
memcpy ( ( char * ) ( V_154 + 1 ) , V_147 , V_148 ) ;
V_33 = F_78 ( V_76 , V_8 , V_59 ) ;
F_18 ( V_33 ) ;
F_43 ( & V_6 -> V_14 ) ;
V_33 = F_63 ( V_6 , V_59 ) ;
if ( F_149 ( V_33 ) ) {
F_150 ( V_8 -> V_25 , L_6
L_7
L_8 ,
V_148 , V_147 , V_6 -> V_8 -> V_22 ,
V_6 -> V_9 , V_33 ) ;
F_60 () ;
}
F_44 ( & V_6 -> V_14 ) ;
V_155:
F_48 ( V_6 ) ;
return V_33 ;
}
static int F_151 ( struct V_7 * V_8 ,
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
int F_152 ( struct V_75 * V_76 ,
struct V_7 * V_8 , struct V_27 * V_149 ,
T_2 V_152 )
{
struct V_2 * V_30 ;
struct V_17 * V_51 ;
struct V_55 V_158 ;
int V_33 ;
V_30 = F_21 ( V_149 ) ;
if ( F_129 ( V_30 ) )
return F_130 ( V_30 ) ;
V_158 . V_22 = F_13 ( V_149 ) ;
V_158 . type = V_21 ;
V_158 . V_23 = V_152 ;
V_33 = F_151 ( V_8 , V_30 , & V_158 ) ;
if ( ! V_33 )
goto V_159;
V_51 = F_51 ( 0 ) ;
if ( ! V_51 ) {
V_33 = - V_5 ;
goto V_159;
}
V_51 -> V_20 = V_158 ;
V_33 = F_78 ( V_76 , V_8 , V_51 ) ;
F_18 ( V_33 ) ;
F_43 ( & V_30 -> V_14 ) ;
V_33 = F_64 ( V_30 , V_51 ) ;
if ( F_149 ( V_33 ) ) {
F_150 ( V_8 -> V_25 , L_9
L_10
L_8 ,
V_152 , V_30 -> V_8 -> V_22 , V_30 -> V_9 ,
V_33 ) ;
F_60 () ;
}
F_44 ( & V_30 -> V_14 ) ;
V_159:
F_48 ( V_30 ) ;
return V_33 ;
}
int F_153 ( struct V_27 * V_27 )
{
struct V_2 * V_6 = F_11 ( V_27 ) ;
if ( ! V_6 )
return - V_117 ;
if ( ! V_6 -> V_68 ) {
F_48 ( V_6 ) ;
return - V_160 ;
}
F_12 ( V_27 ) -> V_68 = V_6 -> V_68 ;
F_48 ( V_6 ) ;
return 0 ;
}
void F_154 ( struct V_27 * V_27 , struct V_45 * V_161 ,
struct V_45 * V_162 )
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
F_32 ( & V_51 -> V_163 , V_161 ) ;
V_51 = F_77 ( V_51 ) ;
}
V_51 = F_76 ( V_6 ) ;
while ( V_51 ) {
F_15 ( & V_51 -> V_10 ) ;
F_32 ( & V_51 -> V_163 , V_162 ) ;
V_51 = F_77 ( V_51 ) ;
}
F_44 ( & V_6 -> V_14 ) ;
F_35 ( & V_6 -> V_10 ) ;
}
void F_155 ( struct V_45 * V_161 ,
struct V_45 * V_162 )
{
struct V_17 * V_96 , * V_48 ;
F_98 (curr, next, ins_list, readdir_list) {
F_101 ( & V_96 -> V_163 ) ;
if ( F_45 ( & V_96 -> V_10 ) )
F_73 ( V_96 ) ;
}
F_98 (curr, next, del_list, readdir_list) {
F_101 ( & V_96 -> V_163 ) ;
if ( F_45 ( & V_96 -> V_10 ) )
F_73 ( V_96 ) ;
}
}
int F_156 ( struct V_45 * V_162 ,
T_2 V_152 )
{
struct V_17 * V_96 , * V_48 ;
int V_33 ;
if ( F_30 ( V_162 ) )
return 0 ;
F_98 (curr, next, del_list, readdir_list) {
if ( V_96 -> V_20 . V_23 > V_152 )
break;
F_101 ( & V_96 -> V_163 ) ;
V_33 = ( V_96 -> V_20 . V_23 == V_152 ) ;
if ( F_45 ( & V_96 -> V_10 ) )
F_73 ( V_96 ) ;
if ( V_33 )
return 1 ;
else
continue;
}
return 0 ;
}
int F_157 ( struct V_164 * V_165 ,
struct V_45 * V_161 , bool * V_166 )
{
struct V_153 * V_167 ;
struct V_17 * V_96 , * V_48 ;
struct V_55 V_156 ;
char * V_147 ;
int V_148 ;
int V_168 = 0 ;
unsigned char V_169 ;
if ( F_30 ( V_161 ) )
return 0 ;
F_98 (curr, next, ins_list, readdir_list) {
F_101 ( & V_96 -> V_163 ) ;
if ( V_96 -> V_20 . V_23 < V_165 -> V_170 ) {
if ( F_45 ( & V_96 -> V_10 ) )
F_73 ( V_96 ) ;
continue;
}
V_165 -> V_170 = V_96 -> V_20 . V_23 ;
V_167 = (struct V_153 * ) V_96 -> V_112 ;
V_147 = ( char * ) ( V_167 + 1 ) ;
V_148 = F_158 ( V_167 ) ;
V_169 = V_171 [ V_167 -> type ] ;
F_159 ( & V_156 , & V_167 -> V_156 ) ;
V_168 = ! F_160 ( V_165 , V_147 , V_148 ,
V_156 . V_22 , V_169 ) ;
if ( F_45 ( & V_96 -> V_10 ) )
F_73 ( V_96 ) ;
if ( V_168 )
return 1 ;
* V_166 = true ;
}
return 0 ;
}
static void F_161 ( struct V_75 * V_76 ,
struct V_121 * V_122 ,
struct V_27 * V_27 )
{
F_162 ( V_122 , F_163 ( V_27 ) ) ;
F_164 ( V_122 , F_165 ( V_27 ) ) ;
F_166 ( V_122 , F_12 ( V_27 ) -> V_172 ) ;
F_167 ( V_122 , V_27 -> V_173 ) ;
F_168 ( V_122 , V_27 -> V_174 ) ;
F_169 ( V_122 , F_170 ( V_27 ) ) ;
F_171 ( V_122 ,
F_12 ( V_27 ) -> V_175 ) ;
F_172 ( V_122 , V_27 -> V_176 ) ;
F_173 ( V_122 , V_76 -> V_157 ) ;
F_174 ( V_122 , V_27 -> V_177 ) ;
F_175 ( V_122 , F_12 ( V_27 ) -> V_41 ) ;
F_176 ( V_122 , 0 ) ;
F_177 ( & V_122 -> V_178 ,
V_27 -> V_179 . V_180 ) ;
F_178 ( & V_122 -> V_178 ,
V_27 -> V_179 . V_181 ) ;
F_177 ( & V_122 -> V_182 ,
V_27 -> V_183 . V_180 ) ;
F_178 ( & V_122 -> V_182 ,
V_27 -> V_183 . V_181 ) ;
F_177 ( & V_122 -> ctime ,
V_27 -> V_184 . V_180 ) ;
F_178 ( & V_122 -> ctime ,
V_27 -> V_184 . V_181 ) ;
F_177 ( & V_122 -> V_185 ,
F_12 ( V_27 ) -> V_186 . V_180 ) ;
F_178 ( & V_122 -> V_185 ,
F_12 ( V_27 ) -> V_186 . V_181 ) ;
}
int F_179 ( struct V_27 * V_27 , T_3 * V_187 )
{
struct V_2 * V_6 ;
struct V_121 * V_122 ;
V_6 = F_11 ( V_27 ) ;
if ( ! V_6 )
return - V_117 ;
F_43 ( & V_6 -> V_14 ) ;
if ( ! F_29 ( V_119 , & V_6 -> V_41 ) ) {
F_44 ( & V_6 -> V_14 ) ;
F_48 ( V_6 ) ;
return - V_117 ;
}
V_122 = & V_6 -> V_122 ;
F_180 ( V_27 , F_181 ( V_122 ) ) ;
F_182 ( V_27 , F_183 ( V_122 ) ) ;
F_184 ( V_27 , F_185 ( V_122 ) ) ;
V_27 -> V_173 = F_186 ( V_122 ) ;
F_187 ( V_27 , F_188 ( V_122 ) ) ;
F_189 ( V_27 , F_190 ( V_122 ) ) ;
F_12 ( V_27 ) -> V_175 = F_191 ( V_122 ) ;
F_12 ( V_27 ) -> V_188 = F_192 ( V_122 ) ;
V_27 -> V_176 = F_193 ( V_122 ) ;
V_27 -> V_177 = 0 ;
* V_187 = F_194 ( V_122 ) ;
F_12 ( V_27 ) -> V_41 = F_195 ( V_122 ) ;
V_27 -> V_179 . V_180 = F_196 ( & V_122 -> V_178 ) ;
V_27 -> V_179 . V_181 = F_197 ( & V_122 -> V_178 ) ;
V_27 -> V_183 . V_180 = F_196 ( & V_122 -> V_182 ) ;
V_27 -> V_183 . V_181 = F_197 ( & V_122 -> V_182 ) ;
V_27 -> V_184 . V_180 = F_196 ( & V_122 -> ctime ) ;
V_27 -> V_184 . V_181 = F_197 ( & V_122 -> ctime ) ;
F_12 ( V_27 ) -> V_186 . V_180 =
F_196 ( & V_122 -> V_185 ) ;
F_12 ( V_27 ) -> V_186 . V_181 =
F_197 ( & V_122 -> V_185 ) ;
V_27 -> V_189 = F_12 ( V_27 ) -> V_175 ;
F_12 ( V_27 ) -> V_68 = ( T_2 ) - 1 ;
F_44 ( & V_6 -> V_14 ) ;
F_48 ( V_6 ) ;
return 0 ;
}
int F_198 ( struct V_75 * V_76 ,
struct V_7 * V_8 , struct V_27 * V_27 )
{
struct V_2 * V_6 ;
int V_33 = 0 ;
V_6 = F_21 ( V_27 ) ;
if ( F_129 ( V_6 ) )
return F_130 ( V_6 ) ;
F_43 ( & V_6 -> V_14 ) ;
if ( F_29 ( V_119 , & V_6 -> V_41 ) ) {
F_161 ( V_76 , & V_6 -> V_122 , V_27 ) ;
goto V_155;
}
V_33 = F_84 ( V_76 , V_8 , V_27 ,
V_6 ) ;
if ( V_33 )
goto V_155;
F_161 ( V_76 , & V_6 -> V_122 , V_27 ) ;
F_33 ( V_119 , & V_6 -> V_41 ) ;
V_6 -> V_49 ++ ;
F_15 ( & V_8 -> V_25 -> V_26 -> V_69 ) ;
V_155:
F_44 ( & V_6 -> V_14 ) ;
F_48 ( V_6 ) ;
return V_33 ;
}
int F_199 ( struct V_27 * V_27 )
{
struct V_2 * V_6 ;
if ( F_12 ( V_27 ) -> V_8 -> V_25 -> V_190 )
return - V_87 ;
V_6 = F_21 ( V_27 ) ;
if ( F_129 ( V_6 ) )
return F_130 ( V_6 ) ;
F_43 ( & V_6 -> V_14 ) ;
if ( F_29 ( V_120 , & V_6 -> V_41 ) )
goto V_155;
F_33 ( V_120 , & V_6 -> V_41 ) ;
V_6 -> V_49 ++ ;
F_15 ( & F_12 ( V_27 ) -> V_8 -> V_25 -> V_26 -> V_69 ) ;
V_155:
F_44 ( & V_6 -> V_14 ) ;
F_48 ( V_6 ) ;
return 0 ;
}
static void F_200 ( struct V_2 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_17 * V_191 , * V_192 ;
F_43 ( & V_6 -> V_14 ) ;
V_191 = F_74 ( V_6 ) ;
while ( V_191 ) {
F_82 ( V_8 , V_191 ) ;
V_192 = V_191 ;
V_191 = F_77 ( V_192 ) ;
F_72 ( V_192 ) ;
}
V_191 = F_76 ( V_6 ) ;
while ( V_191 ) {
F_82 ( V_8 , V_191 ) ;
V_192 = V_191 ;
V_191 = F_77 ( V_192 ) ;
F_72 ( V_192 ) ;
}
if ( F_29 ( V_120 , & V_6 -> V_41 ) )
F_114 ( V_6 ) ;
if ( F_29 ( V_119 , & V_6 -> V_41 ) ) {
F_90 ( V_8 , V_6 ) ;
F_113 ( V_6 ) ;
}
F_44 ( & V_6 -> V_14 ) ;
}
void F_201 ( struct V_27 * V_27 )
{
struct V_2 * V_6 ;
V_6 = F_11 ( V_27 ) ;
if ( ! V_6 )
return;
F_200 ( V_6 ) ;
F_48 ( V_6 ) ;
}
void F_202 ( struct V_7 * V_8 )
{
T_2 V_9 = 0 ;
struct V_2 * V_193 [ 8 ] ;
int V_108 , V_194 ;
while ( 1 ) {
F_16 ( & V_8 -> V_31 ) ;
V_194 = F_203 ( & V_8 -> V_32 ,
( void * * ) V_193 , V_9 ,
F_204 ( V_193 ) ) ;
if ( ! V_194 ) {
F_19 ( & V_8 -> V_31 ) ;
break;
}
V_9 = V_193 [ V_194 - 1 ] -> V_9 + 1 ;
for ( V_108 = 0 ; V_108 < V_194 ; V_108 ++ )
F_15 ( & V_193 [ V_108 ] -> V_10 ) ;
F_19 ( & V_8 -> V_31 ) ;
for ( V_108 = 0 ; V_108 < V_194 ; V_108 ++ ) {
F_200 ( V_193 [ V_108 ] ) ;
F_48 ( V_193 [ V_108 ] ) ;
}
}
}
void F_205 ( struct V_7 * V_8 )
{
struct V_24 * V_26 ;
struct V_2 * V_130 , * V_58 ;
V_26 = F_10 ( V_8 ) ;
V_130 = F_38 ( V_26 ) ;
while ( V_130 ) {
F_200 ( V_130 ) ;
V_58 = V_130 ;
V_130 = F_40 ( V_130 ) ;
F_48 ( V_58 ) ;
}
}
