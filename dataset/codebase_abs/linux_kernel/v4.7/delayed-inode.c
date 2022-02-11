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
V_33 = F_24 ( V_35 ) ;
if ( V_33 ) {
F_25 ( V_1 , V_30 ) ;
return F_23 ( V_33 ) ;
}
F_16 ( & V_8 -> V_31 ) ;
V_33 = F_26 ( & V_8 -> V_32 , V_29 , V_30 ) ;
if ( V_33 == - V_36 ) {
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
int V_37 )
{
F_16 ( & V_8 -> V_38 ) ;
if ( F_29 ( V_39 , & V_30 -> V_40 ) ) {
if ( ! F_30 ( & V_30 -> V_16 ) )
F_31 ( & V_30 -> V_16 , & V_8 -> V_41 ) ;
else if ( V_37 )
F_32 ( & V_30 -> V_16 , & V_8 -> V_41 ) ;
} else {
F_32 ( & V_30 -> V_15 , & V_8 -> V_42 ) ;
F_32 ( & V_30 -> V_16 , & V_8 -> V_41 ) ;
F_15 ( & V_30 -> V_10 ) ;
V_8 -> V_43 ++ ;
F_33 ( V_39 , & V_30 -> V_40 ) ;
}
F_19 ( & V_8 -> V_38 ) ;
}
static void F_34 ( struct V_24 * V_8 ,
struct V_2 * V_30 )
{
F_16 ( & V_8 -> V_38 ) ;
if ( F_29 ( V_39 , & V_30 -> V_40 ) ) {
V_8 -> V_43 -- ;
F_35 ( & V_30 -> V_10 ) ;
F_36 ( & V_30 -> V_15 ) ;
if ( ! F_30 ( & V_30 -> V_16 ) )
F_36 ( & V_30 -> V_16 ) ;
F_37 ( V_39 , & V_30 -> V_40 ) ;
}
F_19 ( & V_8 -> V_38 ) ;
}
static struct V_2 * F_38 (
struct V_24 * V_26 )
{
struct V_44 * V_45 ;
struct V_2 * V_30 = NULL ;
F_16 ( & V_26 -> V_38 ) ;
if ( F_30 ( & V_26 -> V_42 ) )
goto V_46;
V_45 = V_26 -> V_42 . V_47 ;
V_30 = F_39 ( V_45 , struct V_2 , V_15 ) ;
F_15 ( & V_30 -> V_10 ) ;
V_46:
F_19 ( & V_26 -> V_38 ) ;
return V_30 ;
}
static struct V_2 * F_40 (
struct V_2 * V_30 )
{
struct V_24 * V_26 ;
struct V_44 * V_45 ;
struct V_2 * V_47 = NULL ;
V_26 = V_30 -> V_8 -> V_25 -> V_26 ;
F_16 ( & V_26 -> V_38 ) ;
if ( ! F_29 ( V_39 , & V_30 -> V_40 ) ) {
if ( F_30 ( & V_26 -> V_42 ) )
goto V_46;
V_45 = V_26 -> V_42 . V_47 ;
} else if ( F_41 ( & V_30 -> V_15 , & V_26 -> V_42 ) )
goto V_46;
else
V_45 = V_30 -> V_15 . V_47 ;
V_47 = F_39 ( V_45 , struct V_2 , V_15 ) ;
F_15 ( & V_47 -> V_10 ) ;
V_46:
F_19 ( & V_26 -> V_38 ) ;
return V_47 ;
}
static void F_42 (
struct V_2 * V_6 ,
int V_37 )
{
struct V_24 * V_26 ;
if ( ! V_6 )
return;
V_26 = V_6 -> V_8 -> V_25 -> V_26 ;
F_43 ( & V_6 -> V_14 ) ;
if ( V_6 -> V_48 )
F_28 ( V_26 , V_6 , V_37 ) ;
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
struct V_44 * V_45 ;
struct V_2 * V_30 = NULL ;
F_16 ( & V_26 -> V_38 ) ;
if ( F_30 ( & V_26 -> V_41 ) )
goto V_46;
V_45 = V_26 -> V_41 . V_47 ;
F_36 ( V_45 ) ;
V_30 = F_39 ( V_45 , struct V_2 , V_16 ) ;
F_15 ( & V_30 -> V_10 ) ;
V_46:
F_19 ( & V_26 -> V_38 ) ;
return V_30 ;
}
static inline void F_50 (
struct V_2 * V_30 )
{
F_42 ( V_30 , 1 ) ;
}
static struct V_17 * F_51 ( T_3 V_49 )
{
struct V_17 * V_50 ;
V_50 = F_52 ( sizeof( * V_50 ) + V_49 , V_35 ) ;
if ( V_50 ) {
V_50 -> V_49 = V_49 ;
V_50 -> V_51 = 0 ;
V_50 -> V_52 = 0 ;
V_50 -> V_6 = NULL ;
F_6 ( & V_50 -> V_10 , 1 ) ;
}
return V_50 ;
}
static struct V_17 * F_53 (
struct V_53 * V_8 ,
struct V_54 * V_20 ,
struct V_17 * * V_55 ,
struct V_17 * * V_47 )
{
struct V_56 * V_30 , * V_57 = NULL ;
struct V_17 * V_58 = NULL ;
int V_33 = 0 ;
V_30 = V_8 -> V_56 ;
while ( V_30 ) {
V_58 = F_54 ( V_30 , struct V_17 ,
V_56 ) ;
V_57 = V_30 ;
V_33 = F_55 ( & V_58 -> V_20 , V_20 ) ;
if ( V_33 < 0 )
V_30 = V_30 -> V_59 ;
else if ( V_33 > 0 )
V_30 = V_30 -> V_60 ;
else
return V_58 ;
}
if ( V_55 ) {
if ( ! V_57 )
* V_55 = NULL ;
else if ( V_33 < 0 )
* V_55 = V_58 ;
else if ( ( V_30 = F_56 ( V_57 ) ) != NULL ) {
* V_55 = F_54 ( V_30 , struct V_17 ,
V_56 ) ;
} else
* V_55 = NULL ;
}
if ( V_47 ) {
if ( ! V_57 )
* V_47 = NULL ;
else if ( V_33 > 0 )
* V_47 = V_58 ;
else if ( ( V_30 = F_57 ( V_57 ) ) != NULL ) {
* V_47 = F_54 ( V_30 , struct V_17 ,
V_56 ) ;
} else
* V_47 = NULL ;
}
return NULL ;
}
static struct V_17 * F_58 (
struct V_2 * V_6 ,
struct V_54 * V_20 )
{
struct V_17 * V_50 ;
V_50 = F_53 ( & V_6 -> V_11 , V_20 ,
NULL , NULL ) ;
return V_50 ;
}
static int F_59 ( struct V_2 * V_6 ,
struct V_17 * V_61 ,
int V_62 )
{
struct V_56 * * V_45 , * V_30 ;
struct V_56 * V_63 = NULL ;
struct V_53 * V_8 ;
struct V_17 * V_50 ;
int V_64 ;
if ( V_62 == V_65 )
V_8 = & V_6 -> V_11 ;
else if ( V_62 == V_66 )
V_8 = & V_6 -> V_13 ;
else
F_60 () ;
V_45 = & V_8 -> V_56 ;
V_30 = & V_61 -> V_56 ;
while ( * V_45 ) {
V_63 = * V_45 ;
V_50 = F_54 ( V_63 , struct V_17 ,
V_56 ) ;
V_64 = F_55 ( & V_50 -> V_20 , & V_61 -> V_20 ) ;
if ( V_64 < 0 )
V_45 = & ( * V_45 ) -> V_59 ;
else if ( V_64 > 0 )
V_45 = & ( * V_45 ) -> V_60 ;
else
return - V_36 ;
}
F_61 ( V_30 , V_63 , V_45 ) ;
F_62 ( V_30 , V_8 ) ;
V_61 -> V_6 = V_6 ;
V_61 -> V_51 = V_62 ;
if ( V_61 -> V_20 . type == V_21 &&
V_62 == V_65 &&
V_61 -> V_20 . V_23 >= V_6 -> V_67 )
V_6 -> V_67 = V_61 -> V_20 . V_23 + 1 ;
V_6 -> V_48 ++ ;
F_15 ( & V_6 -> V_8 -> V_25 -> V_26 -> V_68 ) ;
return 0 ;
}
static int F_63 ( struct V_2 * V_30 ,
struct V_17 * V_50 )
{
return F_59 ( V_30 , V_50 ,
V_65 ) ;
}
static int F_64 ( struct V_2 * V_30 ,
struct V_17 * V_50 )
{
return F_59 ( V_30 , V_50 ,
V_66 ) ;
}
static void F_65 ( struct V_24 * V_26 )
{
int V_69 = F_66 ( & V_26 -> V_70 ) ;
if ( ( F_67 ( & V_26 -> V_68 ) <
V_71 || V_69 % V_72 == 0 ) &&
F_68 ( & V_26 -> V_73 ) )
F_69 ( & V_26 -> V_73 ) ;
}
static void F_70 ( struct V_17 * V_58 )
{
struct V_53 * V_8 ;
struct V_24 * V_26 ;
V_26 = V_58 -> V_6 -> V_8 -> V_25 -> V_26 ;
F_18 ( ! V_26 ) ;
F_18 ( V_58 -> V_51 != V_66 &&
V_58 -> V_51 != V_65 ) ;
if ( V_58 -> V_51 == V_65 )
V_8 = & V_58 -> V_6 -> V_11 ;
else
V_8 = & V_58 -> V_6 -> V_13 ;
F_71 ( & V_58 -> V_56 , V_8 ) ;
V_58 -> V_6 -> V_48 -- ;
F_65 ( V_26 ) ;
}
static void F_72 ( struct V_17 * V_50 )
{
if ( V_50 ) {
F_70 ( V_50 ) ;
if ( F_45 ( & V_50 -> V_10 ) )
F_73 ( V_50 ) ;
}
}
static struct V_17 * F_74 (
struct V_2 * V_6 )
{
struct V_56 * V_45 ;
struct V_17 * V_50 = NULL ;
V_45 = F_75 ( & V_6 -> V_11 ) ;
if ( V_45 )
V_50 = F_54 ( V_45 , struct V_17 , V_56 ) ;
return V_50 ;
}
static struct V_17 * F_76 (
struct V_2 * V_6 )
{
struct V_56 * V_45 ;
struct V_17 * V_50 = NULL ;
V_45 = F_75 ( & V_6 -> V_13 ) ;
if ( V_45 )
V_50 = F_54 ( V_45 , struct V_17 , V_56 ) ;
return V_50 ;
}
static struct V_17 * F_77 (
struct V_17 * V_50 )
{
struct V_56 * V_45 ;
struct V_17 * V_47 = NULL ;
V_45 = F_57 ( & V_50 -> V_56 ) ;
if ( V_45 )
V_47 = F_54 ( V_45 , struct V_17 , V_56 ) ;
return V_47 ;
}
static int F_78 ( struct V_74 * V_75 ,
struct V_7 * V_8 ,
struct V_17 * V_50 )
{
struct V_76 * V_77 ;
struct V_76 * V_78 ;
T_2 V_79 ;
int V_33 ;
if ( ! V_75 -> V_52 )
return 0 ;
V_77 = V_75 -> V_80 ;
V_78 = & V_8 -> V_25 -> V_81 ;
V_79 = F_79 ( V_8 , 1 ) ;
V_33 = F_80 ( V_77 , V_78 , V_79 ) ;
if ( ! V_33 ) {
F_81 ( V_8 -> V_25 , L_2 ,
V_50 -> V_20 . V_22 ,
V_79 , 1 ) ;
V_50 -> V_52 = V_79 ;
}
return V_33 ;
}
static void F_82 ( struct V_7 * V_8 ,
struct V_17 * V_50 )
{
struct V_76 * V_82 ;
if ( ! V_50 -> V_52 )
return;
V_82 = & V_8 -> V_25 -> V_81 ;
F_81 ( V_8 -> V_25 , L_2 ,
V_50 -> V_20 . V_22 , V_50 -> V_52 ,
0 ) ;
F_83 ( V_8 , V_82 ,
V_50 -> V_52 ) ;
}
static int F_84 (
struct V_74 * V_75 ,
struct V_7 * V_8 ,
struct V_27 * V_27 ,
struct V_2 * V_30 )
{
struct V_76 * V_77 ;
struct V_76 * V_78 ;
T_2 V_79 ;
int V_33 ;
bool V_83 = false ;
V_77 = V_75 -> V_80 ;
V_78 = & V_8 -> V_25 -> V_81 ;
V_79 = F_79 ( V_8 , 1 ) ;
if ( ! V_77 || ( ! V_75 -> V_52 &&
V_77 -> type != V_84 ) ) {
V_33 = F_85 ( V_8 , V_78 , V_79 ,
V_85 ) ;
if ( V_33 == - V_86 )
V_33 = - V_87 ;
if ( ! V_33 ) {
V_30 -> V_52 = V_79 ;
F_81 ( V_8 -> V_25 ,
L_3 ,
F_13 ( V_27 ) ,
V_79 , 1 ) ;
}
return V_33 ;
} else if ( V_77 -> type == V_84 ) {
F_16 ( & F_12 ( V_27 ) -> V_38 ) ;
if ( F_86 ( V_88 ,
& F_12 ( V_27 ) -> V_89 ) ) {
F_19 ( & F_12 ( V_27 ) -> V_38 ) ;
V_83 = true ;
goto V_90;
}
F_19 ( & F_12 ( V_27 ) -> V_38 ) ;
V_33 = F_85 ( V_8 , V_78 , V_79 ,
V_85 ) ;
if ( ! V_33 )
goto V_46;
V_33 = F_80 ( V_77 , V_78 , V_79 ) ;
if ( ! V_33 )
goto V_46;
if ( F_87 ( V_8 , V_91 ) ) {
F_88 ( V_8 -> V_25 ,
L_4 , V_33 ) ;
F_89 ( 1 ) ;
}
V_33 = F_80 ( & V_8 -> V_25 -> V_92 ,
V_78 , V_79 ) ;
goto V_46;
}
V_90:
V_33 = F_80 ( V_77 , V_78 , V_79 ) ;
V_46:
if ( ! V_33 ) {
F_81 ( V_8 -> V_25 , L_3 ,
F_13 ( V_27 ) , V_79 , 1 ) ;
V_30 -> V_52 = V_79 ;
}
if ( V_83 ) {
F_81 ( V_8 -> V_25 , L_5 ,
F_13 ( V_27 ) , V_79 , 0 ) ;
F_83 ( V_8 , V_77 , V_79 ) ;
}
return V_33 ;
}
static void F_90 ( struct V_7 * V_8 ,
struct V_2 * V_30 )
{
struct V_76 * V_82 ;
if ( ! V_30 -> V_52 )
return;
V_82 = & V_8 -> V_25 -> V_81 ;
F_81 ( V_8 -> V_25 , L_3 ,
V_30 -> V_9 , V_30 -> V_52 , 0 ) ;
F_83 ( V_8 , V_82 ,
V_30 -> V_52 ) ;
V_30 -> V_52 = 0 ;
}
static int F_91 ( struct V_7 * V_8 ,
struct V_93 * V_94 ,
struct V_17 * V_50 )
{
struct V_17 * V_95 , * V_47 ;
int V_96 ;
int V_97 = 0 , V_98 = 0 ;
struct V_99 * V_100 ;
char * V_101 ;
struct V_54 * V_102 ;
T_3 * V_103 ;
struct V_44 V_104 ;
int V_105 ;
int V_106 ;
int V_107 ;
int V_33 = 0 ;
F_18 ( ! V_94 -> V_43 [ 0 ] ) ;
V_100 = V_94 -> V_43 [ 0 ] ;
V_96 = F_92 ( V_8 , V_100 ) ;
F_8 ( & V_104 ) ;
V_47 = V_50 ;
V_106 = 0 ;
while ( V_98 + V_47 -> V_49 + sizeof( struct V_108 ) <=
V_96 ) {
V_97 += V_47 -> V_49 ;
V_98 += V_47 -> V_49 + sizeof( struct V_108 ) ;
F_32 ( & V_47 -> V_109 , & V_104 ) ;
V_106 ++ ;
V_95 = V_47 ;
V_47 = F_77 ( V_95 ) ;
if ( ! V_47 )
break;
if ( ! F_9 ( V_95 , V_47 ) )
break;
}
if ( ! V_106 ) {
V_33 = 0 ;
goto V_46;
}
F_93 ( V_94 ) ;
V_102 = F_94 ( V_106 , sizeof( struct V_54 ) , V_35 ) ;
if ( ! V_102 ) {
V_33 = - V_5 ;
goto V_46;
}
V_103 = F_94 ( V_106 , sizeof( T_3 ) , V_35 ) ;
if ( ! V_103 ) {
V_33 = - V_5 ;
goto error;
}
V_107 = 0 ;
F_95 (next, &head, tree_list) {
V_102 [ V_107 ] = V_47 -> V_20 ;
V_103 [ V_107 ] = V_47 -> V_49 ;
V_107 ++ ;
}
F_96 ( V_94 , NULL , 0 ) ;
F_97 ( V_8 , V_94 , V_102 , V_103 ,
V_97 , V_98 , V_106 ) ;
V_105 = V_94 -> V_110 [ 0 ] ;
F_98 (curr, next, &head, tree_list) {
V_101 = F_99 ( V_100 , V_105 , char ) ;
F_100 ( V_100 , & V_95 -> V_111 ,
( unsigned long ) V_101 ,
V_95 -> V_49 ) ;
V_105 ++ ;
F_82 ( V_8 , V_95 ) ;
F_101 ( & V_95 -> V_109 ) ;
F_72 ( V_95 ) ;
}
error:
F_73 ( V_103 ) ;
F_73 ( V_102 ) ;
V_46:
return V_33 ;
}
static int F_102 ( struct V_74 * V_75 ,
struct V_7 * V_8 ,
struct V_93 * V_94 ,
struct V_17 * V_58 )
{
struct V_99 * V_100 ;
char * V_112 ;
int V_33 ;
V_33 = F_103 ( V_75 , V_8 , V_94 , & V_58 -> V_20 ,
V_58 -> V_49 ) ;
if ( V_33 < 0 && V_33 != - V_36 )
return V_33 ;
V_100 = V_94 -> V_43 [ 0 ] ;
V_112 = F_99 ( V_100 , V_94 -> V_110 [ 0 ] , char ) ;
F_100 ( V_100 , V_58 -> V_111 , ( unsigned long ) V_112 ,
V_58 -> V_49 ) ;
F_104 ( V_100 ) ;
F_82 ( V_8 , V_58 ) ;
return 0 ;
}
static int F_105 ( struct V_74 * V_75 ,
struct V_93 * V_94 ,
struct V_7 * V_8 ,
struct V_2 * V_30 )
{
struct V_17 * V_95 , * V_55 ;
int V_33 = 0 ;
V_113:
F_43 ( & V_30 -> V_14 ) ;
V_95 = F_74 ( V_30 ) ;
if ( ! V_95 )
goto V_114;
V_33 = F_102 ( V_75 , V_8 , V_94 , V_95 ) ;
if ( V_33 < 0 ) {
F_106 ( V_94 ) ;
goto V_114;
}
V_55 = V_95 ;
V_95 = F_77 ( V_55 ) ;
if ( V_95 && F_9 ( V_55 , V_95 ) ) {
V_94 -> V_110 [ 0 ] ++ ;
F_91 ( V_8 , V_94 , V_95 ) ;
}
F_72 ( V_55 ) ;
F_104 ( V_94 -> V_43 [ 0 ] ) ;
F_106 ( V_94 ) ;
F_44 ( & V_30 -> V_14 ) ;
goto V_113;
V_114:
F_44 ( & V_30 -> V_14 ) ;
return V_33 ;
}
static int F_107 ( struct V_74 * V_75 ,
struct V_7 * V_8 ,
struct V_93 * V_94 ,
struct V_17 * V_50 )
{
struct V_17 * V_95 , * V_47 ;
struct V_99 * V_100 ;
struct V_54 V_20 ;
struct V_44 V_104 ;
int V_106 , V_107 , V_115 ;
int V_33 = 0 ;
F_18 ( ! V_94 -> V_43 [ 0 ] ) ;
V_100 = V_94 -> V_43 [ 0 ] ;
V_107 = V_94 -> V_110 [ 0 ] ;
V_115 = F_108 ( V_100 ) - 1 ;
if ( V_107 > V_115 )
return - V_116 ;
V_47 = V_50 ;
F_8 ( & V_104 ) ;
F_109 ( V_100 , & V_20 , V_107 ) ;
V_106 = 0 ;
while ( F_55 ( & V_47 -> V_20 , & V_20 ) == 0 ) {
F_32 ( & V_47 -> V_109 , & V_104 ) ;
V_106 ++ ;
V_95 = V_47 ;
V_47 = F_77 ( V_95 ) ;
if ( ! V_47 )
break;
if ( ! F_9 ( V_95 , V_47 ) )
break;
V_107 ++ ;
if ( V_107 > V_115 )
break;
F_109 ( V_100 , & V_20 , V_107 ) ;
}
if ( ! V_106 )
return 0 ;
V_33 = F_110 ( V_75 , V_8 , V_94 , V_94 -> V_110 [ 0 ] , V_106 ) ;
if ( V_33 )
goto V_46;
F_98 (curr, next, &head, tree_list) {
F_82 ( V_8 , V_95 ) ;
F_101 ( & V_95 -> V_109 ) ;
F_72 ( V_95 ) ;
}
V_46:
return V_33 ;
}
static int F_111 ( struct V_74 * V_75 ,
struct V_93 * V_94 ,
struct V_7 * V_8 ,
struct V_2 * V_30 )
{
struct V_17 * V_95 , * V_55 ;
int V_33 = 0 ;
V_113:
F_43 ( & V_30 -> V_14 ) ;
V_95 = F_76 ( V_30 ) ;
if ( ! V_95 )
goto V_117;
V_33 = F_112 ( V_75 , V_8 , & V_95 -> V_20 , V_94 , - 1 , 1 ) ;
if ( V_33 < 0 )
goto V_117;
else if ( V_33 > 0 ) {
V_55 = V_95 ;
V_95 = F_77 ( V_55 ) ;
F_72 ( V_55 ) ;
V_33 = 0 ;
F_106 ( V_94 ) ;
if ( V_95 ) {
F_44 ( & V_30 -> V_14 ) ;
goto V_113;
} else
goto V_117;
}
F_107 ( V_75 , V_8 , V_94 , V_95 ) ;
F_106 ( V_94 ) ;
F_44 ( & V_30 -> V_14 ) ;
goto V_113;
V_117:
F_106 ( V_94 ) ;
F_44 ( & V_30 -> V_14 ) ;
return V_33 ;
}
static void F_113 ( struct V_2 * V_6 )
{
struct V_24 * V_26 ;
if ( V_6 &&
F_29 ( V_118 , & V_6 -> V_40 ) ) {
F_18 ( ! V_6 -> V_8 ) ;
F_37 ( V_118 , & V_6 -> V_40 ) ;
V_6 -> V_48 -- ;
V_26 = V_6 -> V_8 -> V_25 -> V_26 ;
F_65 ( V_26 ) ;
}
}
static void F_114 ( struct V_2 * V_6 )
{
struct V_24 * V_26 ;
ASSERT ( V_6 -> V_8 ) ;
F_37 ( V_119 , & V_6 -> V_40 ) ;
V_6 -> V_48 -- ;
V_26 = V_6 -> V_8 -> V_25 -> V_26 ;
F_65 ( V_26 ) ;
}
static int F_115 ( struct V_74 * V_75 ,
struct V_7 * V_8 ,
struct V_93 * V_94 ,
struct V_2 * V_30 )
{
struct V_54 V_20 ;
struct V_120 * V_121 ;
struct V_99 * V_100 ;
int V_37 ;
int V_33 ;
V_20 . V_22 = V_30 -> V_9 ;
V_20 . type = V_122 ;
V_20 . V_23 = 0 ;
if ( F_29 ( V_119 , & V_30 -> V_40 ) )
V_37 = - 1 ;
else
V_37 = 1 ;
V_33 = F_116 ( V_75 , V_8 , V_94 , & V_20 , V_37 ) ;
if ( V_33 > 0 ) {
F_106 ( V_94 ) ;
return - V_116 ;
} else if ( V_33 < 0 ) {
return V_33 ;
}
V_100 = V_94 -> V_43 [ 0 ] ;
V_121 = F_99 ( V_100 , V_94 -> V_110 [ 0 ] ,
struct V_120 ) ;
F_100 ( V_100 , & V_30 -> V_121 , ( unsigned long ) V_121 ,
sizeof( struct V_120 ) ) ;
F_104 ( V_100 ) ;
if ( ! F_29 ( V_119 , & V_30 -> V_40 ) )
goto V_123;
V_94 -> V_110 [ 0 ] ++ ;
if ( V_94 -> V_110 [ 0 ] >= F_108 ( V_100 ) )
goto V_124;
V_34:
F_109 ( V_100 , & V_20 , V_94 -> V_110 [ 0 ] ) ;
if ( V_20 . V_22 != V_30 -> V_9 )
goto V_46;
if ( V_20 . type != V_125 &&
V_20 . type != V_126 )
goto V_46;
F_117 ( V_75 , V_8 , V_94 ) ;
V_46:
F_114 ( V_30 ) ;
V_123:
F_106 ( V_94 ) ;
V_127:
F_90 ( V_8 , V_30 ) ;
F_113 ( V_30 ) ;
return V_33 ;
V_124:
F_106 ( V_94 ) ;
V_20 . type = V_126 ;
V_20 . V_23 = - 1 ;
V_33 = F_112 ( V_75 , V_8 , & V_20 , V_94 , - 1 , 1 ) ;
if ( V_33 < 0 )
goto V_127;
ASSERT ( V_33 ) ;
V_33 = 0 ;
V_100 = V_94 -> V_43 [ 0 ] ;
V_94 -> V_110 [ 0 ] -- ;
goto V_34;
}
static inline int F_118 ( struct V_74 * V_75 ,
struct V_7 * V_8 ,
struct V_93 * V_94 ,
struct V_2 * V_30 )
{
int V_33 ;
F_43 ( & V_30 -> V_14 ) ;
if ( ! F_29 ( V_118 , & V_30 -> V_40 ) ) {
F_44 ( & V_30 -> V_14 ) ;
return 0 ;
}
V_33 = F_115 ( V_75 , V_8 , V_94 , V_30 ) ;
F_44 ( & V_30 -> V_14 ) ;
return V_33 ;
}
static inline int
F_119 ( struct V_74 * V_75 ,
struct V_93 * V_94 ,
struct V_2 * V_30 )
{
int V_33 ;
V_33 = F_105 ( V_75 , V_94 , V_30 -> V_8 , V_30 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_111 ( V_75 , V_94 , V_30 -> V_8 , V_30 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_118 ( V_75 , V_30 -> V_8 , V_94 , V_30 ) ;
return V_33 ;
}
static int F_120 ( struct V_74 * V_75 ,
struct V_7 * V_8 , int V_128 )
{
struct V_24 * V_26 ;
struct V_2 * V_129 , * V_57 ;
struct V_93 * V_94 ;
struct V_76 * V_80 ;
int V_33 = 0 ;
bool V_48 = ( V_128 > 0 ) ;
if ( V_75 -> V_130 )
return - V_131 ;
V_94 = F_121 () ;
if ( ! V_94 )
return - V_5 ;
V_94 -> V_132 = 1 ;
V_80 = V_75 -> V_80 ;
V_75 -> V_80 = & V_8 -> V_25 -> V_81 ;
V_26 = F_10 ( V_8 ) ;
V_129 = F_38 ( V_26 ) ;
while ( V_129 && ( ! V_48 || ( V_48 && V_128 -- ) ) ) {
V_33 = F_119 ( V_75 , V_94 ,
V_129 ) ;
if ( V_33 ) {
F_48 ( V_129 ) ;
V_129 = NULL ;
F_122 ( V_75 , V_8 , V_33 ) ;
break;
}
V_57 = V_129 ;
V_129 = F_40 ( V_129 ) ;
F_48 ( V_57 ) ;
}
if ( V_129 )
F_48 ( V_129 ) ;
F_123 ( V_94 ) ;
V_75 -> V_80 = V_80 ;
return V_33 ;
}
int F_124 ( struct V_74 * V_75 ,
struct V_7 * V_8 )
{
return F_120 ( V_75 , V_8 , - 1 ) ;
}
int F_125 ( struct V_74 * V_75 ,
struct V_7 * V_8 , int V_128 )
{
return F_120 ( V_75 , V_8 , V_128 ) ;
}
int F_126 ( struct V_74 * V_75 ,
struct V_27 * V_27 )
{
struct V_2 * V_6 = F_11 ( V_27 ) ;
struct V_93 * V_94 ;
struct V_76 * V_80 ;
int V_33 ;
if ( ! V_6 )
return 0 ;
F_43 ( & V_6 -> V_14 ) ;
if ( ! V_6 -> V_48 ) {
F_44 ( & V_6 -> V_14 ) ;
F_48 ( V_6 ) ;
return 0 ;
}
F_44 ( & V_6 -> V_14 ) ;
V_94 = F_121 () ;
if ( ! V_94 ) {
F_48 ( V_6 ) ;
return - V_5 ;
}
V_94 -> V_132 = 1 ;
V_80 = V_75 -> V_80 ;
V_75 -> V_80 = & V_6 -> V_8 -> V_25 -> V_81 ;
V_33 = F_119 ( V_75 , V_94 , V_6 ) ;
F_48 ( V_6 ) ;
F_123 ( V_94 ) ;
V_75 -> V_80 = V_80 ;
return V_33 ;
}
int F_127 ( struct V_27 * V_27 )
{
struct V_74 * V_75 ;
struct V_2 * V_6 = F_11 ( V_27 ) ;
struct V_93 * V_94 ;
struct V_76 * V_80 ;
int V_33 ;
if ( ! V_6 )
return 0 ;
F_43 ( & V_6 -> V_14 ) ;
if ( ! F_29 ( V_118 , & V_6 -> V_40 ) ) {
F_44 ( & V_6 -> V_14 ) ;
F_48 ( V_6 ) ;
return 0 ;
}
F_44 ( & V_6 -> V_14 ) ;
V_75 = F_128 ( V_6 -> V_8 ) ;
if ( F_129 ( V_75 ) ) {
V_33 = F_130 ( V_75 ) ;
goto V_46;
}
V_94 = F_121 () ;
if ( ! V_94 ) {
V_33 = - V_5 ;
goto V_133;
}
V_94 -> V_132 = 1 ;
V_80 = V_75 -> V_80 ;
V_75 -> V_80 = & V_6 -> V_8 -> V_25 -> V_81 ;
F_43 ( & V_6 -> V_14 ) ;
if ( F_29 ( V_118 , & V_6 -> V_40 ) )
V_33 = F_115 ( V_75 , V_6 -> V_8 ,
V_94 , V_6 ) ;
else
V_33 = 0 ;
F_44 ( & V_6 -> V_14 ) ;
F_123 ( V_94 ) ;
V_75 -> V_80 = V_80 ;
V_133:
F_131 ( V_75 , V_6 -> V_8 ) ;
F_132 ( V_6 -> V_8 ) ;
V_46:
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
static void F_134 ( struct V_134 * V_135 )
{
struct V_136 * V_137 ;
struct V_24 * V_26 ;
struct V_74 * V_75 ;
struct V_93 * V_94 ;
struct V_2 * V_6 = NULL ;
struct V_7 * V_8 ;
struct V_76 * V_80 ;
int V_138 = 0 ;
V_137 = F_135 ( V_135 , struct V_136 , V_135 ) ;
V_26 = V_137 -> V_26 ;
V_94 = F_121 () ;
if ( ! V_94 )
goto V_46;
V_34:
if ( F_46 ( & V_26 -> V_68 ) < V_71 / 2 )
goto V_139;
V_6 = F_49 ( V_26 ) ;
if ( ! V_6 )
goto V_139;
V_94 -> V_132 = 1 ;
V_8 = V_6 -> V_8 ;
V_75 = F_128 ( V_8 ) ;
if ( F_129 ( V_75 ) )
goto V_140;
V_80 = V_75 -> V_80 ;
V_75 -> V_80 = & V_8 -> V_25 -> V_81 ;
F_119 ( V_75 , V_94 , V_6 ) ;
V_75 -> V_80 = V_80 ;
F_131 ( V_75 , V_8 ) ;
F_136 ( V_8 ) ;
V_140:
F_106 ( V_94 ) ;
V_138 ++ ;
F_50 ( V_6 ) ;
if ( V_137 -> V_128 == 0 || V_138 < V_137 -> V_128 )
goto V_34;
V_139:
F_123 ( V_94 ) ;
V_46:
F_69 ( & V_26 -> V_73 ) ;
F_73 ( V_137 ) ;
}
static int F_137 ( struct V_24 * V_26 ,
struct V_141 * V_25 , int V_128 )
{
struct V_136 * V_137 ;
if ( F_46 ( & V_26 -> V_68 ) < V_71 )
return 0 ;
V_137 = F_52 ( sizeof( * V_137 ) , V_35 ) ;
if ( ! V_137 )
return - V_5 ;
V_137 -> V_26 = V_26 ;
F_138 ( & V_137 -> V_135 , V_142 ,
F_134 , NULL , NULL ) ;
V_137 -> V_128 = V_128 ;
F_139 ( V_25 -> V_143 , & V_137 -> V_135 ) ;
return 0 ;
}
void F_140 ( struct V_7 * V_8 )
{
struct V_24 * V_26 ;
V_26 = F_10 ( V_8 ) ;
F_89 ( F_38 ( V_26 ) ) ;
}
static int F_141 ( struct V_24 * V_26 , int V_69 )
{
int V_144 = F_46 ( & V_26 -> V_70 ) ;
if ( V_144 < V_69 || V_144 >= V_69 + V_72 )
return 1 ;
if ( F_46 ( & V_26 -> V_68 ) < V_71 )
return 1 ;
return 0 ;
}
void F_142 ( struct V_7 * V_8 )
{
struct V_24 * V_26 ;
struct V_141 * V_25 = V_8 -> V_25 ;
V_26 = F_10 ( V_8 ) ;
if ( F_46 ( & V_26 -> V_68 ) < V_71 )
return;
if ( F_46 ( & V_26 -> V_68 ) >= V_145 ) {
int V_69 ;
int V_33 ;
V_69 = F_46 ( & V_26 -> V_70 ) ;
V_33 = F_137 ( V_26 , V_25 , 0 ) ;
if ( V_33 )
return;
F_143 ( V_26 -> V_73 ,
F_141 ( V_26 , V_69 ) ) ;
return;
}
F_137 ( V_26 , V_25 , V_72 ) ;
}
int F_144 ( struct V_74 * V_75 ,
struct V_7 * V_8 , const char * V_146 ,
int V_147 , struct V_27 * V_148 ,
struct V_149 * V_150 , T_4 type ,
T_2 V_151 )
{
struct V_2 * V_6 ;
struct V_17 * V_58 ;
struct V_152 * V_153 ;
int V_33 ;
V_6 = F_21 ( V_148 ) ;
if ( F_129 ( V_6 ) )
return F_130 ( V_6 ) ;
V_58 = F_51 ( sizeof( * V_153 ) + V_147 ) ;
if ( ! V_58 ) {
V_33 = - V_5 ;
goto V_154;
}
V_58 -> V_20 . V_22 = F_13 ( V_148 ) ;
V_58 -> V_20 . type = V_21 ;
V_58 -> V_20 . V_23 = V_151 ;
V_153 = (struct V_152 * ) V_58 -> V_111 ;
V_153 -> V_155 = * V_150 ;
F_145 ( V_153 , V_75 -> V_156 ) ;
F_146 ( V_153 , 0 ) ;
F_147 ( V_153 , V_147 ) ;
F_148 ( V_153 , type ) ;
memcpy ( ( char * ) ( V_153 + 1 ) , V_146 , V_147 ) ;
V_33 = F_78 ( V_75 , V_8 , V_58 ) ;
F_18 ( V_33 ) ;
F_43 ( & V_6 -> V_14 ) ;
V_33 = F_63 ( V_6 , V_58 ) ;
if ( F_149 ( V_33 ) ) {
F_150 ( V_8 -> V_25 , L_6
L_7
L_8 ,
V_147 , V_146 , V_6 -> V_8 -> V_22 ,
V_6 -> V_9 , V_33 ) ;
F_60 () ;
}
F_44 ( & V_6 -> V_14 ) ;
V_154:
F_48 ( V_6 ) ;
return V_33 ;
}
static int F_151 ( struct V_7 * V_8 ,
struct V_2 * V_30 ,
struct V_54 * V_20 )
{
struct V_17 * V_50 ;
F_43 ( & V_30 -> V_14 ) ;
V_50 = F_58 ( V_30 , V_20 ) ;
if ( ! V_50 ) {
F_44 ( & V_30 -> V_14 ) ;
return 1 ;
}
F_82 ( V_8 , V_50 ) ;
F_72 ( V_50 ) ;
F_44 ( & V_30 -> V_14 ) ;
return 0 ;
}
int F_152 ( struct V_74 * V_75 ,
struct V_7 * V_8 , struct V_27 * V_148 ,
T_2 V_151 )
{
struct V_2 * V_30 ;
struct V_17 * V_50 ;
struct V_54 V_157 ;
int V_33 ;
V_30 = F_21 ( V_148 ) ;
if ( F_129 ( V_30 ) )
return F_130 ( V_30 ) ;
V_157 . V_22 = F_13 ( V_148 ) ;
V_157 . type = V_21 ;
V_157 . V_23 = V_151 ;
V_33 = F_151 ( V_8 , V_30 , & V_157 ) ;
if ( ! V_33 )
goto V_158;
V_50 = F_51 ( 0 ) ;
if ( ! V_50 ) {
V_33 = - V_5 ;
goto V_158;
}
V_50 -> V_20 = V_157 ;
V_33 = F_78 ( V_75 , V_8 , V_50 ) ;
F_18 ( V_33 ) ;
F_43 ( & V_30 -> V_14 ) ;
V_33 = F_64 ( V_30 , V_50 ) ;
if ( F_149 ( V_33 ) ) {
F_150 ( V_8 -> V_25 , L_9
L_10
L_8 ,
V_151 , V_30 -> V_8 -> V_22 , V_30 -> V_9 ,
V_33 ) ;
F_60 () ;
}
F_44 ( & V_30 -> V_14 ) ;
V_158:
F_48 ( V_30 ) ;
return V_33 ;
}
int F_153 ( struct V_27 * V_27 )
{
struct V_2 * V_6 = F_11 ( V_27 ) ;
if ( ! V_6 )
return - V_116 ;
if ( ! V_6 -> V_67 ) {
F_48 ( V_6 ) ;
return - V_159 ;
}
F_12 ( V_27 ) -> V_67 = V_6 -> V_67 ;
F_48 ( V_6 ) ;
return 0 ;
}
bool F_154 ( struct V_27 * V_27 ,
struct V_44 * V_160 ,
struct V_44 * V_161 )
{
struct V_2 * V_6 ;
struct V_17 * V_50 ;
V_6 = F_11 ( V_27 ) ;
if ( ! V_6 )
return false ;
F_155 ( V_27 ) ;
V_31 ( V_27 ) ;
F_43 ( & V_6 -> V_14 ) ;
V_50 = F_74 ( V_6 ) ;
while ( V_50 ) {
F_15 ( & V_50 -> V_10 ) ;
F_32 ( & V_50 -> V_162 , V_160 ) ;
V_50 = F_77 ( V_50 ) ;
}
V_50 = F_76 ( V_6 ) ;
while ( V_50 ) {
F_15 ( & V_50 -> V_10 ) ;
F_32 ( & V_50 -> V_162 , V_161 ) ;
V_50 = F_77 ( V_50 ) ;
}
F_44 ( & V_6 -> V_14 ) ;
F_35 ( & V_6 -> V_10 ) ;
return true ;
}
void F_156 ( struct V_27 * V_27 ,
struct V_44 * V_160 ,
struct V_44 * V_161 )
{
struct V_17 * V_95 , * V_47 ;
F_98 (curr, next, ins_list, readdir_list) {
F_101 ( & V_95 -> V_162 ) ;
if ( F_45 ( & V_95 -> V_10 ) )
F_73 ( V_95 ) ;
}
F_98 (curr, next, del_list, readdir_list) {
F_101 ( & V_95 -> V_162 ) ;
if ( F_45 ( & V_95 -> V_10 ) )
F_73 ( V_95 ) ;
}
F_157 ( & V_27 -> V_163 ) ;
}
int F_158 ( struct V_44 * V_161 ,
T_2 V_151 )
{
struct V_17 * V_95 , * V_47 ;
int V_33 ;
if ( F_30 ( V_161 ) )
return 0 ;
F_98 (curr, next, del_list, readdir_list) {
if ( V_95 -> V_20 . V_23 > V_151 )
break;
F_101 ( & V_95 -> V_162 ) ;
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
int F_159 ( struct V_164 * V_165 ,
struct V_44 * V_160 , bool * V_166 )
{
struct V_152 * V_167 ;
struct V_17 * V_95 , * V_47 ;
struct V_54 V_155 ;
char * V_146 ;
int V_147 ;
int V_168 = 0 ;
unsigned char V_169 ;
if ( F_30 ( V_160 ) )
return 0 ;
F_98 (curr, next, ins_list, readdir_list) {
F_101 ( & V_95 -> V_162 ) ;
if ( V_95 -> V_20 . V_23 < V_165 -> V_170 ) {
if ( F_45 ( & V_95 -> V_10 ) )
F_73 ( V_95 ) ;
continue;
}
V_165 -> V_170 = V_95 -> V_20 . V_23 ;
V_167 = (struct V_152 * ) V_95 -> V_111 ;
V_146 = ( char * ) ( V_167 + 1 ) ;
V_147 = F_160 ( V_167 ) ;
V_169 = V_171 [ V_167 -> type ] ;
F_161 ( & V_155 , & V_167 -> V_155 ) ;
V_168 = ! F_162 ( V_165 , V_146 , V_147 ,
V_155 . V_22 , V_169 ) ;
if ( F_45 ( & V_95 -> V_10 ) )
F_73 ( V_95 ) ;
if ( V_168 )
return 1 ;
* V_166 = true ;
}
return 0 ;
}
static void F_163 ( struct V_74 * V_75 ,
struct V_120 * V_121 ,
struct V_27 * V_27 )
{
F_164 ( V_121 , F_165 ( V_27 ) ) ;
F_166 ( V_121 , F_167 ( V_27 ) ) ;
F_168 ( V_121 , F_12 ( V_27 ) -> V_172 ) ;
F_169 ( V_121 , V_27 -> V_173 ) ;
F_170 ( V_121 , V_27 -> V_174 ) ;
F_171 ( V_121 , F_172 ( V_27 ) ) ;
F_173 ( V_121 ,
F_12 ( V_27 ) -> V_175 ) ;
F_174 ( V_121 , V_27 -> V_176 ) ;
F_175 ( V_121 , V_75 -> V_156 ) ;
F_176 ( V_121 , V_27 -> V_177 ) ;
F_177 ( V_121 , F_12 ( V_27 ) -> V_40 ) ;
F_178 ( V_121 , 0 ) ;
F_179 ( & V_121 -> V_178 ,
V_27 -> V_179 . V_180 ) ;
F_180 ( & V_121 -> V_178 ,
V_27 -> V_179 . V_181 ) ;
F_179 ( & V_121 -> V_182 ,
V_27 -> V_183 . V_180 ) ;
F_180 ( & V_121 -> V_182 ,
V_27 -> V_183 . V_181 ) ;
F_179 ( & V_121 -> ctime ,
V_27 -> V_184 . V_180 ) ;
F_180 ( & V_121 -> ctime ,
V_27 -> V_184 . V_181 ) ;
F_179 ( & V_121 -> V_185 ,
F_12 ( V_27 ) -> V_186 . V_180 ) ;
F_180 ( & V_121 -> V_185 ,
F_12 ( V_27 ) -> V_186 . V_181 ) ;
}
int F_181 ( struct V_27 * V_27 , T_3 * V_187 )
{
struct V_2 * V_6 ;
struct V_120 * V_121 ;
V_6 = F_11 ( V_27 ) ;
if ( ! V_6 )
return - V_116 ;
F_43 ( & V_6 -> V_14 ) ;
if ( ! F_29 ( V_118 , & V_6 -> V_40 ) ) {
F_44 ( & V_6 -> V_14 ) ;
F_48 ( V_6 ) ;
return - V_116 ;
}
V_121 = & V_6 -> V_121 ;
F_182 ( V_27 , F_183 ( V_121 ) ) ;
F_184 ( V_27 , F_185 ( V_121 ) ) ;
F_186 ( V_27 , F_187 ( V_121 ) ) ;
V_27 -> V_173 = F_188 ( V_121 ) ;
F_189 ( V_27 , F_190 ( V_121 ) ) ;
F_191 ( V_27 , F_192 ( V_121 ) ) ;
F_12 ( V_27 ) -> V_175 = F_193 ( V_121 ) ;
F_12 ( V_27 ) -> V_188 = F_194 ( V_121 ) ;
V_27 -> V_176 = F_195 ( V_121 ) ;
V_27 -> V_177 = 0 ;
* V_187 = F_196 ( V_121 ) ;
F_12 ( V_27 ) -> V_40 = F_197 ( V_121 ) ;
V_27 -> V_179 . V_180 = F_198 ( & V_121 -> V_178 ) ;
V_27 -> V_179 . V_181 = F_199 ( & V_121 -> V_178 ) ;
V_27 -> V_183 . V_180 = F_198 ( & V_121 -> V_182 ) ;
V_27 -> V_183 . V_181 = F_199 ( & V_121 -> V_182 ) ;
V_27 -> V_184 . V_180 = F_198 ( & V_121 -> ctime ) ;
V_27 -> V_184 . V_181 = F_199 ( & V_121 -> ctime ) ;
F_12 ( V_27 ) -> V_186 . V_180 =
F_198 ( & V_121 -> V_185 ) ;
F_12 ( V_27 ) -> V_186 . V_181 =
F_199 ( & V_121 -> V_185 ) ;
V_27 -> V_189 = F_12 ( V_27 ) -> V_175 ;
F_12 ( V_27 ) -> V_67 = ( T_2 ) - 1 ;
F_44 ( & V_6 -> V_14 ) ;
F_48 ( V_6 ) ;
return 0 ;
}
int F_200 ( struct V_74 * V_75 ,
struct V_7 * V_8 , struct V_27 * V_27 )
{
struct V_2 * V_6 ;
int V_33 = 0 ;
V_6 = F_21 ( V_27 ) ;
if ( F_129 ( V_6 ) )
return F_130 ( V_6 ) ;
F_43 ( & V_6 -> V_14 ) ;
if ( F_29 ( V_118 , & V_6 -> V_40 ) ) {
F_163 ( V_75 , & V_6 -> V_121 , V_27 ) ;
goto V_154;
}
V_33 = F_84 ( V_75 , V_8 , V_27 ,
V_6 ) ;
if ( V_33 )
goto V_154;
F_163 ( V_75 , & V_6 -> V_121 , V_27 ) ;
F_33 ( V_118 , & V_6 -> V_40 ) ;
V_6 -> V_48 ++ ;
F_15 ( & V_8 -> V_25 -> V_26 -> V_68 ) ;
V_154:
F_44 ( & V_6 -> V_14 ) ;
F_48 ( V_6 ) ;
return V_33 ;
}
int F_201 ( struct V_27 * V_27 )
{
struct V_2 * V_6 ;
if ( F_12 ( V_27 ) -> V_8 -> V_25 -> V_190 )
return - V_86 ;
V_6 = F_21 ( V_27 ) ;
if ( F_129 ( V_6 ) )
return F_130 ( V_6 ) ;
F_43 ( & V_6 -> V_14 ) ;
if ( F_29 ( V_119 , & V_6 -> V_40 ) )
goto V_154;
F_33 ( V_119 , & V_6 -> V_40 ) ;
V_6 -> V_48 ++ ;
F_15 ( & F_12 ( V_27 ) -> V_8 -> V_25 -> V_26 -> V_68 ) ;
V_154:
F_44 ( & V_6 -> V_14 ) ;
F_48 ( V_6 ) ;
return 0 ;
}
static void F_202 ( struct V_2 * V_6 )
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
if ( F_29 ( V_119 , & V_6 -> V_40 ) )
F_114 ( V_6 ) ;
if ( F_29 ( V_118 , & V_6 -> V_40 ) ) {
F_90 ( V_8 , V_6 ) ;
F_113 ( V_6 ) ;
}
F_44 ( & V_6 -> V_14 ) ;
}
void F_203 ( struct V_27 * V_27 )
{
struct V_2 * V_6 ;
V_6 = F_11 ( V_27 ) ;
if ( ! V_6 )
return;
F_202 ( V_6 ) ;
F_48 ( V_6 ) ;
}
void F_204 ( struct V_7 * V_8 )
{
T_2 V_9 = 0 ;
struct V_2 * V_193 [ 8 ] ;
int V_107 , V_194 ;
while ( 1 ) {
F_16 ( & V_8 -> V_31 ) ;
V_194 = F_205 ( & V_8 -> V_32 ,
( void * * ) V_193 , V_9 ,
F_206 ( V_193 ) ) ;
if ( ! V_194 ) {
F_19 ( & V_8 -> V_31 ) ;
break;
}
V_9 = V_193 [ V_194 - 1 ] -> V_9 + 1 ;
for ( V_107 = 0 ; V_107 < V_194 ; V_107 ++ )
F_15 ( & V_193 [ V_107 ] -> V_10 ) ;
F_19 ( & V_8 -> V_31 ) ;
for ( V_107 = 0 ; V_107 < V_194 ; V_107 ++ ) {
F_202 ( V_193 [ V_107 ] ) ;
F_48 ( V_193 [ V_107 ] ) ;
}
}
}
void F_207 ( struct V_7 * V_8 )
{
struct V_24 * V_26 ;
struct V_2 * V_129 , * V_57 ;
V_26 = F_10 ( V_8 ) ;
V_129 = F_38 ( V_26 ) ;
while ( V_129 ) {
F_202 ( V_129 ) ;
V_57 = V_129 ;
V_129 = F_40 ( V_129 ) ;
F_48 ( V_57 ) ;
}
}
