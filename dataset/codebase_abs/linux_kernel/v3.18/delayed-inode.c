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
V_6 -> V_11 = 0 ;
V_6 -> V_12 = 0 ;
V_6 -> V_13 = V_14 ;
V_6 -> V_15 = V_14 ;
F_7 ( & V_6 -> V_16 ) ;
V_6 -> V_17 = 0 ;
F_8 ( & V_6 -> V_18 ) ;
F_8 ( & V_6 -> V_19 ) ;
V_6 -> V_20 = 0 ;
memset ( & V_6 -> V_21 , 0 , sizeof( V_6 -> V_21 ) ) ;
}
static inline int F_9 (
struct V_22 * V_23 ,
struct V_22 * V_24 )
{
if ( V_23 -> V_25 . type == V_26 &&
V_23 -> V_25 . V_27 == V_24 -> V_25 . V_27 &&
V_23 -> V_25 . type == V_24 -> V_25 . type &&
V_23 -> V_25 . V_28 + 1 == V_24 -> V_25 . V_28 )
return 1 ;
return 0 ;
}
static inline struct V_29 * F_10 (
struct V_7 * V_8 )
{
return V_8 -> V_30 -> V_31 ;
}
static struct V_2 * F_11 ( struct V_32 * V_32 )
{
struct V_33 * V_33 = F_12 ( V_32 ) ;
struct V_7 * V_8 = V_33 -> V_8 ;
T_2 V_34 = F_13 ( V_32 ) ;
struct V_2 * V_35 ;
V_35 = F_14 ( V_33 -> V_6 ) ;
if ( V_35 ) {
F_15 ( & V_35 -> V_10 ) ;
return V_35 ;
}
F_16 ( & V_8 -> V_36 ) ;
V_35 = F_17 ( & V_8 -> V_37 , V_34 ) ;
if ( V_35 ) {
if ( V_33 -> V_6 ) {
F_15 ( & V_35 -> V_10 ) ;
F_18 ( V_33 -> V_6 != V_35 ) ;
F_19 ( & V_8 -> V_36 ) ;
return V_35 ;
}
V_33 -> V_6 = V_35 ;
F_20 ( 2 , & V_35 -> V_10 ) ;
F_19 ( & V_8 -> V_36 ) ;
return V_35 ;
}
F_19 ( & V_8 -> V_36 ) ;
return NULL ;
}
static struct V_2 * F_21 (
struct V_32 * V_32 )
{
struct V_2 * V_35 ;
struct V_33 * V_33 = F_12 ( V_32 ) ;
struct V_7 * V_8 = V_33 -> V_8 ;
T_2 V_34 = F_13 ( V_32 ) ;
int V_38 ;
V_39:
V_35 = F_11 ( V_32 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_22 ( V_1 , V_40 ) ;
if ( ! V_35 )
return F_23 ( - V_5 ) ;
F_5 ( V_35 , V_8 , V_34 ) ;
F_20 ( 2 , & V_35 -> V_10 ) ;
V_38 = F_24 ( V_40 & ~ V_41 ) ;
if ( V_38 ) {
F_25 ( V_1 , V_35 ) ;
return F_23 ( V_38 ) ;
}
F_16 ( & V_8 -> V_36 ) ;
V_38 = F_26 ( & V_8 -> V_37 , V_34 , V_35 ) ;
if ( V_38 == - V_42 ) {
F_19 ( & V_8 -> V_36 ) ;
F_25 ( V_1 , V_35 ) ;
F_27 () ;
goto V_39;
}
V_33 -> V_6 = V_35 ;
F_19 ( & V_8 -> V_36 ) ;
F_27 () ;
return V_35 ;
}
static void F_28 ( struct V_29 * V_8 ,
struct V_2 * V_35 ,
int V_43 )
{
F_16 ( & V_8 -> V_44 ) ;
if ( F_29 ( V_45 , & V_35 -> V_12 ) ) {
if ( ! F_30 ( & V_35 -> V_19 ) )
F_31 ( & V_35 -> V_19 , & V_8 -> V_46 ) ;
else if ( V_43 )
F_32 ( & V_35 -> V_19 , & V_8 -> V_46 ) ;
} else {
F_32 ( & V_35 -> V_18 , & V_8 -> V_47 ) ;
F_32 ( & V_35 -> V_19 , & V_8 -> V_46 ) ;
F_15 ( & V_35 -> V_10 ) ;
V_8 -> V_48 ++ ;
F_33 ( V_45 , & V_35 -> V_12 ) ;
}
F_19 ( & V_8 -> V_44 ) ;
}
static void F_34 ( struct V_29 * V_8 ,
struct V_2 * V_35 )
{
F_16 ( & V_8 -> V_44 ) ;
if ( F_29 ( V_45 , & V_35 -> V_12 ) ) {
V_8 -> V_48 -- ;
F_35 ( & V_35 -> V_10 ) ;
F_36 ( & V_35 -> V_18 ) ;
if ( ! F_30 ( & V_35 -> V_19 ) )
F_36 ( & V_35 -> V_19 ) ;
F_37 ( V_45 , & V_35 -> V_12 ) ;
}
F_19 ( & V_8 -> V_44 ) ;
}
static struct V_2 * F_38 (
struct V_29 * V_31 )
{
struct V_49 * V_50 ;
struct V_2 * V_35 = NULL ;
F_16 ( & V_31 -> V_44 ) ;
if ( F_30 ( & V_31 -> V_47 ) )
goto V_51;
V_50 = V_31 -> V_47 . V_52 ;
V_35 = F_39 ( V_50 , struct V_2 , V_18 ) ;
F_15 ( & V_35 -> V_10 ) ;
V_51:
F_19 ( & V_31 -> V_44 ) ;
return V_35 ;
}
static struct V_2 * F_40 (
struct V_2 * V_35 )
{
struct V_29 * V_31 ;
struct V_49 * V_50 ;
struct V_2 * V_52 = NULL ;
V_31 = V_35 -> V_8 -> V_30 -> V_31 ;
F_16 ( & V_31 -> V_44 ) ;
if ( ! F_29 ( V_45 , & V_35 -> V_12 ) ) {
if ( F_30 ( & V_31 -> V_47 ) )
goto V_51;
V_50 = V_31 -> V_47 . V_52 ;
} else if ( F_41 ( & V_35 -> V_18 , & V_31 -> V_47 ) )
goto V_51;
else
V_50 = V_35 -> V_18 . V_52 ;
V_52 = F_39 ( V_50 , struct V_2 , V_18 ) ;
F_15 ( & V_52 -> V_10 ) ;
V_51:
F_19 ( & V_31 -> V_44 ) ;
return V_52 ;
}
static void F_42 (
struct V_2 * V_6 ,
int V_43 )
{
struct V_29 * V_31 ;
if ( ! V_6 )
return;
V_31 = V_6 -> V_8 -> V_30 -> V_31 ;
F_43 ( & V_6 -> V_16 ) ;
if ( V_6 -> V_11 )
F_28 ( V_31 , V_6 , V_43 ) ;
else
F_34 ( V_31 , V_6 ) ;
F_44 ( & V_6 -> V_16 ) ;
if ( F_45 ( & V_6 -> V_10 ) ) {
bool free = false ;
struct V_7 * V_8 = V_6 -> V_8 ;
F_16 ( & V_8 -> V_36 ) ;
if ( F_46 ( & V_6 -> V_10 ) == 0 ) {
F_47 ( & V_8 -> V_37 ,
V_6 -> V_9 ) ;
free = true ;
}
F_19 ( & V_8 -> V_36 ) ;
if ( free )
F_25 ( V_1 , V_6 ) ;
}
}
static inline void F_48 ( struct V_2 * V_35 )
{
F_42 ( V_35 , 0 ) ;
}
static struct V_2 * F_49 (
struct V_29 * V_31 )
{
struct V_49 * V_50 ;
struct V_2 * V_35 = NULL ;
F_16 ( & V_31 -> V_44 ) ;
if ( F_30 ( & V_31 -> V_46 ) )
goto V_51;
V_50 = V_31 -> V_46 . V_52 ;
F_36 ( V_50 ) ;
V_35 = F_39 ( V_50 , struct V_2 , V_19 ) ;
F_15 ( & V_35 -> V_10 ) ;
V_51:
F_19 ( & V_31 -> V_44 ) ;
return V_35 ;
}
static inline void F_50 (
struct V_2 * V_35 )
{
F_42 ( V_35 , 1 ) ;
}
static struct V_22 * F_51 ( T_3 V_53 )
{
struct V_22 * V_54 ;
V_54 = F_52 ( sizeof( * V_54 ) + V_53 , V_40 ) ;
if ( V_54 ) {
V_54 -> V_53 = V_53 ;
V_54 -> V_55 = 0 ;
V_54 -> V_20 = 0 ;
V_54 -> V_6 = NULL ;
F_6 ( & V_54 -> V_10 , 1 ) ;
}
return V_54 ;
}
static struct V_22 * F_53 (
struct V_56 * V_8 ,
struct V_57 * V_25 ,
struct V_22 * * V_58 ,
struct V_22 * * V_52 )
{
struct V_59 * V_35 , * V_60 = NULL ;
struct V_22 * V_61 = NULL ;
int V_38 = 0 ;
V_35 = V_8 -> V_59 ;
while ( V_35 ) {
V_61 = F_54 ( V_35 , struct V_22 ,
V_59 ) ;
V_60 = V_35 ;
V_38 = F_55 ( & V_61 -> V_25 , V_25 ) ;
if ( V_38 < 0 )
V_35 = V_35 -> V_62 ;
else if ( V_38 > 0 )
V_35 = V_35 -> V_63 ;
else
return V_61 ;
}
if ( V_58 ) {
if ( ! V_60 )
* V_58 = NULL ;
else if ( V_38 < 0 )
* V_58 = V_61 ;
else if ( ( V_35 = F_56 ( V_60 ) ) != NULL ) {
* V_58 = F_54 ( V_35 , struct V_22 ,
V_59 ) ;
} else
* V_58 = NULL ;
}
if ( V_52 ) {
if ( ! V_60 )
* V_52 = NULL ;
else if ( V_38 > 0 )
* V_52 = V_61 ;
else if ( ( V_35 = F_57 ( V_60 ) ) != NULL ) {
* V_52 = F_54 ( V_35 , struct V_22 ,
V_59 ) ;
} else
* V_52 = NULL ;
}
return NULL ;
}
static struct V_22 * F_58 (
struct V_2 * V_6 ,
struct V_57 * V_25 )
{
struct V_22 * V_54 ;
V_54 = F_53 ( & V_6 -> V_13 , V_25 ,
NULL , NULL ) ;
return V_54 ;
}
static int F_59 ( struct V_2 * V_6 ,
struct V_22 * V_64 ,
int V_65 )
{
struct V_59 * * V_50 , * V_35 ;
struct V_59 * V_66 = NULL ;
struct V_56 * V_8 ;
struct V_22 * V_54 ;
int V_67 ;
if ( V_65 == V_68 )
V_8 = & V_6 -> V_13 ;
else if ( V_65 == V_69 )
V_8 = & V_6 -> V_15 ;
else
F_60 () ;
V_50 = & V_8 -> V_59 ;
V_35 = & V_64 -> V_59 ;
while ( * V_50 ) {
V_66 = * V_50 ;
V_54 = F_54 ( V_66 , struct V_22 ,
V_59 ) ;
V_67 = F_55 ( & V_54 -> V_25 , & V_64 -> V_25 ) ;
if ( V_67 < 0 )
V_50 = & ( * V_50 ) -> V_62 ;
else if ( V_67 > 0 )
V_50 = & ( * V_50 ) -> V_63 ;
else
return - V_42 ;
}
F_61 ( V_35 , V_66 , V_50 ) ;
F_62 ( V_35 , V_8 ) ;
V_64 -> V_6 = V_6 ;
V_64 -> V_55 = V_65 ;
if ( V_64 -> V_25 . type == V_26 &&
V_65 == V_68 &&
V_64 -> V_25 . V_28 >= V_6 -> V_17 )
V_6 -> V_17 = V_64 -> V_25 . V_28 + 1 ;
V_6 -> V_11 ++ ;
F_15 ( & V_6 -> V_8 -> V_30 -> V_31 -> V_70 ) ;
return 0 ;
}
static int F_63 ( struct V_2 * V_35 ,
struct V_22 * V_54 )
{
return F_59 ( V_35 , V_54 ,
V_68 ) ;
}
static int F_64 ( struct V_2 * V_35 ,
struct V_22 * V_54 )
{
return F_59 ( V_35 , V_54 ,
V_69 ) ;
}
static void F_65 ( struct V_29 * V_31 )
{
int V_71 = F_66 ( & V_31 -> V_72 ) ;
if ( ( F_67 ( & V_31 -> V_70 ) <
V_73 || V_71 % V_74 == 0 ) &&
F_68 ( & V_31 -> V_75 ) )
F_69 ( & V_31 -> V_75 ) ;
}
static void F_70 ( struct V_22 * V_61 )
{
struct V_56 * V_8 ;
struct V_29 * V_31 ;
V_31 = V_61 -> V_6 -> V_8 -> V_30 -> V_31 ;
F_18 ( ! V_31 ) ;
F_18 ( V_61 -> V_55 != V_69 &&
V_61 -> V_55 != V_68 ) ;
if ( V_61 -> V_55 == V_68 )
V_8 = & V_61 -> V_6 -> V_13 ;
else
V_8 = & V_61 -> V_6 -> V_15 ;
F_71 ( & V_61 -> V_59 , V_8 ) ;
V_61 -> V_6 -> V_11 -- ;
F_65 ( V_31 ) ;
}
static void F_72 ( struct V_22 * V_54 )
{
if ( V_54 ) {
F_70 ( V_54 ) ;
if ( F_45 ( & V_54 -> V_10 ) )
F_73 ( V_54 ) ;
}
}
static struct V_22 * F_74 (
struct V_2 * V_6 )
{
struct V_59 * V_50 ;
struct V_22 * V_54 = NULL ;
V_50 = F_75 ( & V_6 -> V_13 ) ;
if ( V_50 )
V_54 = F_54 ( V_50 , struct V_22 , V_59 ) ;
return V_54 ;
}
static struct V_22 * F_76 (
struct V_2 * V_6 )
{
struct V_59 * V_50 ;
struct V_22 * V_54 = NULL ;
V_50 = F_75 ( & V_6 -> V_15 ) ;
if ( V_50 )
V_54 = F_54 ( V_50 , struct V_22 , V_59 ) ;
return V_54 ;
}
static struct V_22 * F_77 (
struct V_22 * V_54 )
{
struct V_59 * V_50 ;
struct V_22 * V_52 = NULL ;
V_50 = F_57 ( & V_54 -> V_59 ) ;
if ( V_50 )
V_52 = F_54 ( V_50 , struct V_22 , V_59 ) ;
return V_52 ;
}
static int F_78 ( struct V_76 * V_77 ,
struct V_7 * V_8 ,
struct V_22 * V_54 )
{
struct V_78 * V_79 ;
struct V_78 * V_80 ;
T_2 V_81 ;
int V_38 ;
if ( ! V_77 -> V_20 )
return 0 ;
V_79 = V_77 -> V_82 ;
V_80 = & V_8 -> V_30 -> V_83 ;
V_81 = F_79 ( V_8 , 1 ) ;
V_38 = F_80 ( V_79 , V_80 , V_81 ) ;
if ( ! V_38 ) {
F_81 ( V_8 -> V_30 , L_2 ,
V_54 -> V_25 . V_27 ,
V_81 , 1 ) ;
V_54 -> V_20 = V_81 ;
}
return V_38 ;
}
static void F_82 ( struct V_7 * V_8 ,
struct V_22 * V_54 )
{
struct V_78 * V_84 ;
if ( ! V_54 -> V_20 )
return;
V_84 = & V_8 -> V_30 -> V_83 ;
F_81 ( V_8 -> V_30 , L_2 ,
V_54 -> V_25 . V_27 , V_54 -> V_20 ,
0 ) ;
F_83 ( V_8 , V_84 ,
V_54 -> V_20 ) ;
}
static int F_84 (
struct V_76 * V_77 ,
struct V_7 * V_8 ,
struct V_32 * V_32 ,
struct V_2 * V_35 )
{
struct V_78 * V_79 ;
struct V_78 * V_80 ;
T_2 V_81 ;
int V_38 ;
bool V_85 = false ;
V_79 = V_77 -> V_82 ;
V_80 = & V_8 -> V_30 -> V_83 ;
V_81 = F_79 ( V_8 , 1 ) ;
if ( ! V_79 || ( ! V_77 -> V_20 &&
V_79 -> type != V_86 ) ) {
V_38 = F_85 ( V_8 , V_80 , V_81 ,
V_87 ) ;
if ( V_38 == - V_88 )
V_38 = - V_89 ;
if ( ! V_38 ) {
V_35 -> V_20 = V_81 ;
F_81 ( V_8 -> V_30 ,
L_3 ,
F_13 ( V_32 ) ,
V_81 , 1 ) ;
}
return V_38 ;
} else if ( V_79 -> type == V_86 ) {
F_16 ( & F_12 ( V_32 ) -> V_44 ) ;
if ( F_86 ( V_90 ,
& F_12 ( V_32 ) -> V_91 ) ) {
F_19 ( & F_12 ( V_32 ) -> V_44 ) ;
V_85 = true ;
goto V_92;
}
F_19 ( & F_12 ( V_32 ) -> V_44 ) ;
V_38 = F_85 ( V_8 , V_80 , V_81 ,
V_87 ) ;
if ( ! V_38 )
goto V_51;
V_38 = F_80 ( V_79 , V_80 , V_81 ) ;
if ( ! F_87 ( V_38 ) )
goto V_51;
V_38 = F_80 ( & V_8 -> V_30 -> V_93 ,
V_80 , V_81 ) ;
goto V_51;
}
V_92:
V_38 = F_80 ( V_79 , V_80 , V_81 ) ;
V_51:
if ( ! V_38 ) {
F_81 ( V_8 -> V_30 , L_3 ,
F_13 ( V_32 ) , V_81 , 1 ) ;
V_35 -> V_20 = V_81 ;
}
if ( V_85 ) {
F_81 ( V_8 -> V_30 , L_4 ,
F_13 ( V_32 ) , V_81 , 0 ) ;
F_83 ( V_8 , V_79 , V_81 ) ;
}
return V_38 ;
}
static void F_88 ( struct V_7 * V_8 ,
struct V_2 * V_35 )
{
struct V_78 * V_84 ;
if ( ! V_35 -> V_20 )
return;
V_84 = & V_8 -> V_30 -> V_83 ;
F_81 ( V_8 -> V_30 , L_3 ,
V_35 -> V_9 , V_35 -> V_20 , 0 ) ;
F_83 ( V_8 , V_84 ,
V_35 -> V_20 ) ;
V_35 -> V_20 = 0 ;
}
static int F_89 ( struct V_7 * V_8 ,
struct V_94 * V_95 ,
struct V_22 * V_54 )
{
struct V_22 * V_96 , * V_52 ;
int V_97 ;
int V_98 = 0 , V_99 = 0 ;
struct V_100 * V_101 ;
char * V_102 ;
struct V_57 * V_103 ;
T_3 * V_104 ;
struct V_49 V_105 ;
int V_106 ;
int V_107 ;
int V_108 ;
int V_38 = 0 ;
F_18 ( ! V_95 -> V_48 [ 0 ] ) ;
V_101 = V_95 -> V_48 [ 0 ] ;
V_97 = F_90 ( V_8 , V_101 ) ;
F_8 ( & V_105 ) ;
V_52 = V_54 ;
V_107 = 0 ;
while ( V_99 + V_52 -> V_53 + sizeof( struct V_109 ) <=
V_97 ) {
V_98 += V_52 -> V_53 ;
V_99 += V_52 -> V_53 + sizeof( struct V_109 ) ;
F_32 ( & V_52 -> V_110 , & V_105 ) ;
V_107 ++ ;
V_96 = V_52 ;
V_52 = F_77 ( V_96 ) ;
if ( ! V_52 )
break;
if ( ! F_9 ( V_96 , V_52 ) )
break;
}
if ( ! V_107 ) {
V_38 = 0 ;
goto V_51;
}
F_91 ( V_95 ) ;
V_103 = F_92 ( V_107 , sizeof( struct V_57 ) , V_40 ) ;
if ( ! V_103 ) {
V_38 = - V_5 ;
goto V_51;
}
V_104 = F_92 ( V_107 , sizeof( T_3 ) , V_40 ) ;
if ( ! V_104 ) {
V_38 = - V_5 ;
goto error;
}
V_108 = 0 ;
F_93 (next, &head, tree_list) {
V_103 [ V_108 ] = V_52 -> V_25 ;
V_104 [ V_108 ] = V_52 -> V_53 ;
V_108 ++ ;
}
F_94 ( V_95 , NULL , 0 ) ;
F_95 ( V_8 , V_95 , V_103 , V_104 ,
V_98 , V_99 , V_107 ) ;
V_106 = V_95 -> V_111 [ 0 ] ;
F_96 (curr, next, &head, tree_list) {
V_102 = F_97 ( V_101 , V_106 , char ) ;
F_98 ( V_101 , & V_96 -> V_112 ,
( unsigned long ) V_102 ,
V_96 -> V_53 ) ;
V_106 ++ ;
F_82 ( V_8 , V_96 ) ;
F_99 ( & V_96 -> V_110 ) ;
F_72 ( V_96 ) ;
}
error:
F_73 ( V_104 ) ;
F_73 ( V_103 ) ;
V_51:
return V_38 ;
}
static int F_100 ( struct V_76 * V_77 ,
struct V_7 * V_8 ,
struct V_94 * V_95 ,
struct V_22 * V_61 )
{
struct V_100 * V_101 ;
char * V_113 ;
int V_38 ;
V_38 = F_101 ( V_77 , V_8 , V_95 , & V_61 -> V_25 ,
V_61 -> V_53 ) ;
if ( V_38 < 0 && V_38 != - V_42 )
return V_38 ;
V_101 = V_95 -> V_48 [ 0 ] ;
V_113 = F_97 ( V_101 , V_95 -> V_111 [ 0 ] , char ) ;
F_98 ( V_101 , V_61 -> V_112 , ( unsigned long ) V_113 ,
V_61 -> V_53 ) ;
F_102 ( V_101 ) ;
F_82 ( V_8 , V_61 ) ;
return 0 ;
}
static int F_103 ( struct V_76 * V_77 ,
struct V_94 * V_95 ,
struct V_7 * V_8 ,
struct V_2 * V_35 )
{
struct V_22 * V_96 , * V_58 ;
int V_38 = 0 ;
V_114:
F_43 ( & V_35 -> V_16 ) ;
V_96 = F_74 ( V_35 ) ;
if ( ! V_96 )
goto V_115;
V_38 = F_100 ( V_77 , V_8 , V_95 , V_96 ) ;
if ( V_38 < 0 ) {
F_104 ( V_95 ) ;
goto V_115;
}
V_58 = V_96 ;
V_96 = F_77 ( V_58 ) ;
if ( V_96 && F_9 ( V_58 , V_96 ) ) {
V_95 -> V_111 [ 0 ] ++ ;
F_89 ( V_8 , V_95 , V_96 ) ;
}
F_72 ( V_58 ) ;
F_102 ( V_95 -> V_48 [ 0 ] ) ;
F_104 ( V_95 ) ;
F_44 ( & V_35 -> V_16 ) ;
goto V_114;
V_115:
F_44 ( & V_35 -> V_16 ) ;
return V_38 ;
}
static int F_105 ( struct V_76 * V_77 ,
struct V_7 * V_8 ,
struct V_94 * V_95 ,
struct V_22 * V_54 )
{
struct V_22 * V_96 , * V_52 ;
struct V_100 * V_101 ;
struct V_57 V_25 ;
struct V_49 V_105 ;
int V_107 , V_108 , V_116 ;
int V_38 = 0 ;
F_18 ( ! V_95 -> V_48 [ 0 ] ) ;
V_101 = V_95 -> V_48 [ 0 ] ;
V_108 = V_95 -> V_111 [ 0 ] ;
V_116 = F_106 ( V_101 ) - 1 ;
if ( V_108 > V_116 )
return - V_117 ;
V_52 = V_54 ;
F_8 ( & V_105 ) ;
F_107 ( V_101 , & V_25 , V_108 ) ;
V_107 = 0 ;
while ( F_55 ( & V_52 -> V_25 , & V_25 ) == 0 ) {
F_32 ( & V_52 -> V_110 , & V_105 ) ;
V_107 ++ ;
V_96 = V_52 ;
V_52 = F_77 ( V_96 ) ;
if ( ! V_52 )
break;
if ( ! F_9 ( V_96 , V_52 ) )
break;
V_108 ++ ;
if ( V_108 > V_116 )
break;
F_107 ( V_101 , & V_25 , V_108 ) ;
}
if ( ! V_107 )
return 0 ;
V_38 = F_108 ( V_77 , V_8 , V_95 , V_95 -> V_111 [ 0 ] , V_107 ) ;
if ( V_38 )
goto V_51;
F_96 (curr, next, &head, tree_list) {
F_82 ( V_8 , V_96 ) ;
F_99 ( & V_96 -> V_110 ) ;
F_72 ( V_96 ) ;
}
V_51:
return V_38 ;
}
static int F_109 ( struct V_76 * V_77 ,
struct V_94 * V_95 ,
struct V_7 * V_8 ,
struct V_2 * V_35 )
{
struct V_22 * V_96 , * V_58 ;
int V_38 = 0 ;
V_114:
F_43 ( & V_35 -> V_16 ) ;
V_96 = F_76 ( V_35 ) ;
if ( ! V_96 )
goto V_118;
V_38 = F_110 ( V_77 , V_8 , & V_96 -> V_25 , V_95 , - 1 , 1 ) ;
if ( V_38 < 0 )
goto V_118;
else if ( V_38 > 0 ) {
V_58 = V_96 ;
V_96 = F_77 ( V_58 ) ;
F_72 ( V_58 ) ;
V_38 = 0 ;
F_104 ( V_95 ) ;
if ( V_96 ) {
F_44 ( & V_35 -> V_16 ) ;
goto V_114;
} else
goto V_118;
}
F_105 ( V_77 , V_8 , V_95 , V_96 ) ;
F_104 ( V_95 ) ;
F_44 ( & V_35 -> V_16 ) ;
goto V_114;
V_118:
F_104 ( V_95 ) ;
F_44 ( & V_35 -> V_16 ) ;
return V_38 ;
}
static void F_111 ( struct V_2 * V_6 )
{
struct V_29 * V_31 ;
if ( V_6 &&
F_29 ( V_119 , & V_6 -> V_12 ) ) {
F_18 ( ! V_6 -> V_8 ) ;
F_37 ( V_119 , & V_6 -> V_12 ) ;
V_6 -> V_11 -- ;
V_31 = V_6 -> V_8 -> V_30 -> V_31 ;
F_65 ( V_31 ) ;
}
}
static void F_112 ( struct V_2 * V_6 )
{
struct V_29 * V_31 ;
ASSERT ( V_6 -> V_8 ) ;
F_37 ( V_120 , & V_6 -> V_12 ) ;
V_6 -> V_11 -- ;
V_31 = V_6 -> V_8 -> V_30 -> V_31 ;
F_65 ( V_31 ) ;
}
static int F_113 ( struct V_76 * V_77 ,
struct V_7 * V_8 ,
struct V_94 * V_95 ,
struct V_2 * V_35 )
{
struct V_57 V_25 ;
struct V_121 * V_21 ;
struct V_100 * V_101 ;
int V_43 ;
int V_38 ;
V_25 . V_27 = V_35 -> V_9 ;
V_25 . type = V_122 ;
V_25 . V_28 = 0 ;
if ( F_29 ( V_120 , & V_35 -> V_12 ) )
V_43 = - 1 ;
else
V_43 = 1 ;
V_38 = F_114 ( V_77 , V_8 , V_95 , & V_25 , V_43 ) ;
if ( V_38 > 0 ) {
F_104 ( V_95 ) ;
return - V_117 ;
} else if ( V_38 < 0 ) {
return V_38 ;
}
V_101 = V_95 -> V_48 [ 0 ] ;
V_21 = F_97 ( V_101 , V_95 -> V_111 [ 0 ] ,
struct V_121 ) ;
F_98 ( V_101 , & V_35 -> V_21 , ( unsigned long ) V_21 ,
sizeof( struct V_121 ) ) ;
F_102 ( V_101 ) ;
if ( ! F_29 ( V_120 , & V_35 -> V_12 ) )
goto V_123;
V_95 -> V_111 [ 0 ] ++ ;
if ( V_95 -> V_111 [ 0 ] >= F_106 ( V_101 ) )
goto V_124;
V_39:
F_107 ( V_101 , & V_25 , V_95 -> V_111 [ 0 ] ) ;
if ( V_25 . V_27 != V_35 -> V_9 )
goto V_51;
if ( V_25 . type != V_125 &&
V_25 . type != V_126 )
goto V_51;
F_115 ( V_77 , V_8 , V_95 ) ;
V_51:
F_112 ( V_35 ) ;
V_123:
F_104 ( V_95 ) ;
V_127:
F_88 ( V_8 , V_35 ) ;
F_111 ( V_35 ) ;
return V_38 ;
V_124:
F_104 ( V_95 ) ;
V_25 . type = V_126 ;
V_25 . V_28 = - 1 ;
V_38 = F_110 ( V_77 , V_8 , & V_25 , V_95 , - 1 , 1 ) ;
if ( V_38 < 0 )
goto V_127;
ASSERT ( V_38 ) ;
V_38 = 0 ;
V_101 = V_95 -> V_48 [ 0 ] ;
V_95 -> V_111 [ 0 ] -- ;
goto V_39;
}
static inline int F_116 ( struct V_76 * V_77 ,
struct V_7 * V_8 ,
struct V_94 * V_95 ,
struct V_2 * V_35 )
{
int V_38 ;
F_43 ( & V_35 -> V_16 ) ;
if ( ! F_29 ( V_119 , & V_35 -> V_12 ) ) {
F_44 ( & V_35 -> V_16 ) ;
return 0 ;
}
V_38 = F_113 ( V_77 , V_8 , V_95 , V_35 ) ;
F_44 ( & V_35 -> V_16 ) ;
return V_38 ;
}
static inline int
F_117 ( struct V_76 * V_77 ,
struct V_94 * V_95 ,
struct V_2 * V_35 )
{
int V_38 ;
V_38 = F_103 ( V_77 , V_95 , V_35 -> V_8 , V_35 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_109 ( V_77 , V_95 , V_35 -> V_8 , V_35 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_116 ( V_77 , V_35 -> V_8 , V_95 , V_35 ) ;
return V_38 ;
}
static int F_118 ( struct V_76 * V_77 ,
struct V_7 * V_8 , int V_128 )
{
struct V_29 * V_31 ;
struct V_2 * V_129 , * V_60 ;
struct V_94 * V_95 ;
struct V_78 * V_82 ;
int V_38 = 0 ;
bool V_11 = ( V_128 > 0 ) ;
if ( V_77 -> V_130 )
return - V_131 ;
V_95 = F_119 () ;
if ( ! V_95 )
return - V_5 ;
V_95 -> V_132 = 1 ;
V_82 = V_77 -> V_82 ;
V_77 -> V_82 = & V_8 -> V_30 -> V_83 ;
V_31 = F_10 ( V_8 ) ;
V_129 = F_38 ( V_31 ) ;
while ( V_129 && ( ! V_11 || ( V_11 && V_128 -- ) ) ) {
V_38 = F_117 ( V_77 , V_95 ,
V_129 ) ;
if ( V_38 ) {
F_48 ( V_129 ) ;
V_129 = NULL ;
F_120 ( V_77 , V_8 , V_38 ) ;
break;
}
V_60 = V_129 ;
V_129 = F_40 ( V_129 ) ;
F_48 ( V_60 ) ;
}
if ( V_129 )
F_48 ( V_129 ) ;
F_121 ( V_95 ) ;
V_77 -> V_82 = V_82 ;
return V_38 ;
}
int F_122 ( struct V_76 * V_77 ,
struct V_7 * V_8 )
{
return F_118 ( V_77 , V_8 , - 1 ) ;
}
int F_123 ( struct V_76 * V_77 ,
struct V_7 * V_8 , int V_128 )
{
return F_118 ( V_77 , V_8 , V_128 ) ;
}
int F_124 ( struct V_76 * V_77 ,
struct V_32 * V_32 )
{
struct V_2 * V_6 = F_11 ( V_32 ) ;
struct V_94 * V_95 ;
struct V_78 * V_82 ;
int V_38 ;
if ( ! V_6 )
return 0 ;
F_43 ( & V_6 -> V_16 ) ;
if ( ! V_6 -> V_11 ) {
F_44 ( & V_6 -> V_16 ) ;
F_48 ( V_6 ) ;
return 0 ;
}
F_44 ( & V_6 -> V_16 ) ;
V_95 = F_119 () ;
if ( ! V_95 ) {
F_48 ( V_6 ) ;
return - V_5 ;
}
V_95 -> V_132 = 1 ;
V_82 = V_77 -> V_82 ;
V_77 -> V_82 = & V_6 -> V_8 -> V_30 -> V_83 ;
V_38 = F_117 ( V_77 , V_95 , V_6 ) ;
F_48 ( V_6 ) ;
F_121 ( V_95 ) ;
V_77 -> V_82 = V_82 ;
return V_38 ;
}
int F_125 ( struct V_32 * V_32 )
{
struct V_76 * V_77 ;
struct V_2 * V_6 = F_11 ( V_32 ) ;
struct V_94 * V_95 ;
struct V_78 * V_82 ;
int V_38 ;
if ( ! V_6 )
return 0 ;
F_43 ( & V_6 -> V_16 ) ;
if ( ! F_29 ( V_119 , & V_6 -> V_12 ) ) {
F_44 ( & V_6 -> V_16 ) ;
F_48 ( V_6 ) ;
return 0 ;
}
F_44 ( & V_6 -> V_16 ) ;
V_77 = F_126 ( V_6 -> V_8 ) ;
if ( F_127 ( V_77 ) ) {
V_38 = F_128 ( V_77 ) ;
goto V_51;
}
V_95 = F_119 () ;
if ( ! V_95 ) {
V_38 = - V_5 ;
goto V_133;
}
V_95 -> V_132 = 1 ;
V_82 = V_77 -> V_82 ;
V_77 -> V_82 = & V_6 -> V_8 -> V_30 -> V_83 ;
F_43 ( & V_6 -> V_16 ) ;
if ( F_29 ( V_119 , & V_6 -> V_12 ) )
V_38 = F_113 ( V_77 , V_6 -> V_8 ,
V_95 , V_6 ) ;
else
V_38 = 0 ;
F_44 ( & V_6 -> V_16 ) ;
F_121 ( V_95 ) ;
V_77 -> V_82 = V_82 ;
V_133:
F_129 ( V_77 , V_6 -> V_8 ) ;
F_130 ( V_6 -> V_8 ) ;
V_51:
F_48 ( V_6 ) ;
return V_38 ;
}
void F_131 ( struct V_32 * V_32 )
{
struct V_2 * V_6 ;
V_6 = F_14 ( F_12 ( V_32 ) -> V_6 ) ;
if ( ! V_6 )
return;
F_12 ( V_32 ) -> V_6 = NULL ;
F_48 ( V_6 ) ;
}
static void F_132 ( struct V_134 * V_135 )
{
struct V_136 * V_137 ;
struct V_29 * V_31 ;
struct V_76 * V_77 ;
struct V_94 * V_95 ;
struct V_2 * V_6 = NULL ;
struct V_7 * V_8 ;
struct V_78 * V_82 ;
int V_138 = 0 ;
V_137 = F_133 ( V_135 , struct V_136 , V_135 ) ;
V_31 = V_137 -> V_31 ;
V_95 = F_119 () ;
if ( ! V_95 )
goto V_51;
V_39:
if ( F_46 ( & V_31 -> V_70 ) < V_73 / 2 )
goto V_139;
V_6 = F_49 ( V_31 ) ;
if ( ! V_6 )
goto V_139;
V_95 -> V_132 = 1 ;
V_8 = V_6 -> V_8 ;
V_77 = F_126 ( V_8 ) ;
if ( F_127 ( V_77 ) )
goto V_140;
V_82 = V_77 -> V_82 ;
V_77 -> V_82 = & V_8 -> V_30 -> V_83 ;
F_117 ( V_77 , V_95 , V_6 ) ;
V_77 -> V_82 = V_82 ;
F_129 ( V_77 , V_8 ) ;
F_134 ( V_8 ) ;
V_140:
F_104 ( V_95 ) ;
V_138 ++ ;
F_50 ( V_6 ) ;
if ( V_137 -> V_128 == 0 || V_138 < V_137 -> V_128 )
goto V_39;
V_139:
F_121 ( V_95 ) ;
V_51:
F_69 ( & V_31 -> V_75 ) ;
F_73 ( V_137 ) ;
}
static int F_135 ( struct V_29 * V_31 ,
struct V_7 * V_8 , int V_128 )
{
struct V_136 * V_137 ;
if ( F_46 ( & V_31 -> V_70 ) < V_73 )
return 0 ;
V_137 = F_52 ( sizeof( * V_137 ) , V_40 ) ;
if ( ! V_137 )
return - V_5 ;
V_137 -> V_31 = V_31 ;
F_136 ( & V_137 -> V_135 , V_141 ,
F_132 , NULL , NULL ) ;
V_137 -> V_128 = V_128 ;
F_137 ( V_8 -> V_30 -> V_142 , & V_137 -> V_135 ) ;
return 0 ;
}
void F_138 ( struct V_7 * V_8 )
{
struct V_29 * V_31 ;
V_31 = F_10 ( V_8 ) ;
F_87 ( F_38 ( V_31 ) ) ;
}
static int F_139 ( struct V_29 * V_31 , int V_71 )
{
int V_143 = F_46 ( & V_31 -> V_72 ) ;
if ( V_143 < V_71 || V_143 >= V_71 + V_74 )
return 1 ;
if ( F_46 ( & V_31 -> V_70 ) < V_73 )
return 1 ;
return 0 ;
}
void F_140 ( struct V_7 * V_8 )
{
struct V_29 * V_31 ;
V_31 = F_10 ( V_8 ) ;
if ( F_46 ( & V_31 -> V_70 ) < V_73 )
return;
if ( F_46 ( & V_31 -> V_70 ) >= V_144 ) {
int V_71 ;
int V_38 ;
V_71 = F_46 ( & V_31 -> V_72 ) ;
V_38 = F_135 ( V_31 , V_8 , 0 ) ;
if ( V_38 )
return;
F_141 ( V_31 -> V_75 ,
F_139 ( V_31 , V_71 ) ) ;
return;
}
F_135 ( V_31 , V_8 , V_74 ) ;
}
int F_142 ( struct V_76 * V_77 ,
struct V_7 * V_8 , const char * V_145 ,
int V_146 , struct V_32 * V_147 ,
struct V_148 * V_149 , T_4 type ,
T_2 V_150 )
{
struct V_2 * V_6 ;
struct V_22 * V_61 ;
struct V_151 * V_152 ;
int V_38 ;
V_6 = F_21 ( V_147 ) ;
if ( F_127 ( V_6 ) )
return F_128 ( V_6 ) ;
V_61 = F_51 ( sizeof( * V_152 ) + V_146 ) ;
if ( ! V_61 ) {
V_38 = - V_5 ;
goto V_153;
}
V_61 -> V_25 . V_27 = F_13 ( V_147 ) ;
V_61 -> V_25 . type = V_26 ;
V_61 -> V_25 . V_28 = V_150 ;
V_152 = (struct V_151 * ) V_61 -> V_112 ;
V_152 -> V_154 = * V_149 ;
F_143 ( V_152 , V_77 -> V_155 ) ;
F_144 ( V_152 , 0 ) ;
F_145 ( V_152 , V_146 ) ;
F_146 ( V_152 , type ) ;
memcpy ( ( char * ) ( V_152 + 1 ) , V_145 , V_146 ) ;
V_38 = F_78 ( V_77 , V_8 , V_61 ) ;
F_18 ( V_38 ) ;
F_43 ( & V_6 -> V_16 ) ;
V_38 = F_63 ( V_6 , V_61 ) ;
if ( F_147 ( V_38 ) ) {
F_148 ( V_8 -> V_30 , L_5
L_6
L_7 ,
V_146 , V_145 , V_6 -> V_8 -> V_27 ,
V_6 -> V_9 , V_38 ) ;
F_60 () ;
}
F_44 ( & V_6 -> V_16 ) ;
V_153:
F_48 ( V_6 ) ;
return V_38 ;
}
static int F_149 ( struct V_7 * V_8 ,
struct V_2 * V_35 ,
struct V_57 * V_25 )
{
struct V_22 * V_54 ;
F_43 ( & V_35 -> V_16 ) ;
V_54 = F_58 ( V_35 , V_25 ) ;
if ( ! V_54 ) {
F_44 ( & V_35 -> V_16 ) ;
return 1 ;
}
F_82 ( V_8 , V_54 ) ;
F_72 ( V_54 ) ;
F_44 ( & V_35 -> V_16 ) ;
return 0 ;
}
int F_150 ( struct V_76 * V_77 ,
struct V_7 * V_8 , struct V_32 * V_147 ,
T_2 V_150 )
{
struct V_2 * V_35 ;
struct V_22 * V_54 ;
struct V_57 V_156 ;
int V_38 ;
V_35 = F_21 ( V_147 ) ;
if ( F_127 ( V_35 ) )
return F_128 ( V_35 ) ;
V_156 . V_27 = F_13 ( V_147 ) ;
V_156 . type = V_26 ;
V_156 . V_28 = V_150 ;
V_38 = F_149 ( V_8 , V_35 , & V_156 ) ;
if ( ! V_38 )
goto V_157;
V_54 = F_51 ( 0 ) ;
if ( ! V_54 ) {
V_38 = - V_5 ;
goto V_157;
}
V_54 -> V_25 = V_156 ;
V_38 = F_78 ( V_77 , V_8 , V_54 ) ;
F_18 ( V_38 ) ;
F_43 ( & V_35 -> V_16 ) ;
V_38 = F_64 ( V_35 , V_54 ) ;
if ( F_147 ( V_38 ) ) {
F_148 ( V_8 -> V_30 , L_8
L_9
L_7 ,
V_150 , V_35 -> V_8 -> V_27 , V_35 -> V_9 ,
V_38 ) ;
F_60 () ;
}
F_44 ( & V_35 -> V_16 ) ;
V_157:
F_48 ( V_35 ) ;
return V_38 ;
}
int F_151 ( struct V_32 * V_32 )
{
struct V_2 * V_6 = F_11 ( V_32 ) ;
if ( ! V_6 )
return - V_117 ;
if ( ! V_6 -> V_17 ) {
F_48 ( V_6 ) ;
return - V_158 ;
}
F_12 ( V_32 ) -> V_17 = V_6 -> V_17 ;
F_48 ( V_6 ) ;
return 0 ;
}
void F_152 ( struct V_32 * V_32 , struct V_49 * V_159 ,
struct V_49 * V_160 )
{
struct V_2 * V_6 ;
struct V_22 * V_54 ;
V_6 = F_11 ( V_32 ) ;
if ( ! V_6 )
return;
F_43 ( & V_6 -> V_16 ) ;
V_54 = F_74 ( V_6 ) ;
while ( V_54 ) {
F_15 ( & V_54 -> V_10 ) ;
F_32 ( & V_54 -> V_161 , V_159 ) ;
V_54 = F_77 ( V_54 ) ;
}
V_54 = F_76 ( V_6 ) ;
while ( V_54 ) {
F_15 ( & V_54 -> V_10 ) ;
F_32 ( & V_54 -> V_161 , V_160 ) ;
V_54 = F_77 ( V_54 ) ;
}
F_44 ( & V_6 -> V_16 ) ;
F_35 ( & V_6 -> V_10 ) ;
}
void F_153 ( struct V_49 * V_159 ,
struct V_49 * V_160 )
{
struct V_22 * V_96 , * V_52 ;
F_96 (curr, next, ins_list, readdir_list) {
F_99 ( & V_96 -> V_161 ) ;
if ( F_45 ( & V_96 -> V_10 ) )
F_73 ( V_96 ) ;
}
F_96 (curr, next, del_list, readdir_list) {
F_99 ( & V_96 -> V_161 ) ;
if ( F_45 ( & V_96 -> V_10 ) )
F_73 ( V_96 ) ;
}
}
int F_154 ( struct V_49 * V_160 ,
T_2 V_150 )
{
struct V_22 * V_96 , * V_52 ;
int V_38 ;
if ( F_30 ( V_160 ) )
return 0 ;
F_96 (curr, next, del_list, readdir_list) {
if ( V_96 -> V_25 . V_28 > V_150 )
break;
F_99 ( & V_96 -> V_161 ) ;
V_38 = ( V_96 -> V_25 . V_28 == V_150 ) ;
if ( F_45 ( & V_96 -> V_10 ) )
F_73 ( V_96 ) ;
if ( V_38 )
return 1 ;
else
continue;
}
return 0 ;
}
int F_155 ( struct V_162 * V_163 ,
struct V_49 * V_159 )
{
struct V_151 * V_164 ;
struct V_22 * V_96 , * V_52 ;
struct V_57 V_154 ;
char * V_145 ;
int V_146 ;
int V_165 = 0 ;
unsigned char V_166 ;
if ( F_30 ( V_159 ) )
return 0 ;
F_96 (curr, next, ins_list, readdir_list) {
F_99 ( & V_96 -> V_161 ) ;
if ( V_96 -> V_25 . V_28 < V_163 -> V_167 ) {
if ( F_45 ( & V_96 -> V_10 ) )
F_73 ( V_96 ) ;
continue;
}
V_163 -> V_167 = V_96 -> V_25 . V_28 ;
V_164 = (struct V_151 * ) V_96 -> V_112 ;
V_145 = ( char * ) ( V_164 + 1 ) ;
V_146 = F_156 ( V_164 ) ;
V_166 = V_168 [ V_164 -> type ] ;
F_157 ( & V_154 , & V_164 -> V_154 ) ;
V_165 = ! F_158 ( V_163 , V_145 , V_146 ,
V_154 . V_27 , V_166 ) ;
if ( F_45 ( & V_96 -> V_10 ) )
F_73 ( V_96 ) ;
if ( V_165 )
return 1 ;
}
return 0 ;
}
static void F_159 ( struct V_76 * V_77 ,
struct V_121 * V_21 ,
struct V_32 * V_32 )
{
F_160 ( V_21 , F_161 ( V_32 ) ) ;
F_162 ( V_21 , F_163 ( V_32 ) ) ;
F_164 ( V_21 , F_12 ( V_32 ) -> V_169 ) ;
F_165 ( V_21 , V_32 -> V_170 ) ;
F_166 ( V_21 , V_32 -> V_171 ) ;
F_167 ( V_21 , F_168 ( V_32 ) ) ;
F_169 ( V_21 ,
F_12 ( V_32 ) -> V_172 ) ;
F_170 ( V_21 , V_32 -> V_173 ) ;
F_171 ( V_21 , V_77 -> V_155 ) ;
F_172 ( V_21 , V_32 -> V_174 ) ;
F_173 ( V_21 , F_12 ( V_32 ) -> V_12 ) ;
F_174 ( V_21 , 0 ) ;
F_175 ( F_176 ( V_21 ) ,
V_32 -> V_175 . V_176 ) ;
F_177 ( F_176 ( V_21 ) ,
V_32 -> V_175 . V_177 ) ;
F_175 ( F_178 ( V_21 ) ,
V_32 -> V_178 . V_176 ) ;
F_177 ( F_178 ( V_21 ) ,
V_32 -> V_178 . V_177 ) ;
F_175 ( F_179 ( V_21 ) ,
V_32 -> V_179 . V_176 ) ;
F_177 ( F_179 ( V_21 ) ,
V_32 -> V_179 . V_177 ) ;
}
int F_180 ( struct V_32 * V_32 , T_3 * V_180 )
{
struct V_2 * V_6 ;
struct V_121 * V_21 ;
struct V_181 * V_182 ;
V_6 = F_11 ( V_32 ) ;
if ( ! V_6 )
return - V_117 ;
F_43 ( & V_6 -> V_16 ) ;
if ( ! F_29 ( V_119 , & V_6 -> V_12 ) ) {
F_44 ( & V_6 -> V_16 ) ;
F_48 ( V_6 ) ;
return - V_117 ;
}
V_21 = & V_6 -> V_21 ;
F_181 ( V_32 , F_182 ( V_21 ) ) ;
F_183 ( V_32 , F_184 ( V_21 ) ) ;
F_185 ( V_32 , F_186 ( V_21 ) ) ;
V_32 -> V_170 = F_187 ( V_21 ) ;
F_188 ( V_32 , F_189 ( V_21 ) ) ;
F_190 ( V_32 , F_191 ( V_21 ) ) ;
F_12 ( V_32 ) -> V_172 = F_192 ( V_21 ) ;
V_32 -> V_173 = F_193 ( V_21 ) ;
V_32 -> V_174 = 0 ;
* V_180 = F_194 ( V_21 ) ;
F_12 ( V_32 ) -> V_12 = F_195 ( V_21 ) ;
V_182 = F_176 ( V_21 ) ;
V_32 -> V_175 . V_176 = F_196 ( V_182 ) ;
V_32 -> V_175 . V_177 = F_197 ( V_182 ) ;
V_182 = F_178 ( V_21 ) ;
V_32 -> V_178 . V_176 = F_196 ( V_182 ) ;
V_32 -> V_178 . V_177 = F_197 ( V_182 ) ;
V_182 = F_179 ( V_21 ) ;
V_32 -> V_179 . V_176 = F_196 ( V_182 ) ;
V_32 -> V_179 . V_177 = F_197 ( V_182 ) ;
V_32 -> V_183 = F_12 ( V_32 ) -> V_172 ;
F_12 ( V_32 ) -> V_17 = ( T_2 ) - 1 ;
F_44 ( & V_6 -> V_16 ) ;
F_48 ( V_6 ) ;
return 0 ;
}
int F_198 ( struct V_76 * V_77 ,
struct V_7 * V_8 , struct V_32 * V_32 )
{
struct V_2 * V_6 ;
int V_38 = 0 ;
V_6 = F_21 ( V_32 ) ;
if ( F_127 ( V_6 ) )
return F_128 ( V_6 ) ;
F_43 ( & V_6 -> V_16 ) ;
if ( F_29 ( V_119 , & V_6 -> V_12 ) ) {
F_159 ( V_77 , & V_6 -> V_21 , V_32 ) ;
goto V_153;
}
V_38 = F_84 ( V_77 , V_8 , V_32 ,
V_6 ) ;
if ( V_38 )
goto V_153;
F_159 ( V_77 , & V_6 -> V_21 , V_32 ) ;
F_33 ( V_119 , & V_6 -> V_12 ) ;
V_6 -> V_11 ++ ;
F_15 ( & V_8 -> V_30 -> V_31 -> V_70 ) ;
V_153:
F_44 ( & V_6 -> V_16 ) ;
F_48 ( V_6 ) ;
return V_38 ;
}
int F_199 ( struct V_32 * V_32 )
{
struct V_2 * V_6 ;
V_6 = F_21 ( V_32 ) ;
if ( F_127 ( V_6 ) )
return F_128 ( V_6 ) ;
F_43 ( & V_6 -> V_16 ) ;
if ( F_29 ( V_120 , & V_6 -> V_12 ) )
goto V_153;
F_33 ( V_120 , & V_6 -> V_12 ) ;
V_6 -> V_11 ++ ;
F_15 ( & F_12 ( V_32 ) -> V_8 -> V_30 -> V_31 -> V_70 ) ;
V_153:
F_44 ( & V_6 -> V_16 ) ;
F_48 ( V_6 ) ;
return 0 ;
}
static void F_200 ( struct V_2 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_22 * V_184 , * V_185 ;
F_43 ( & V_6 -> V_16 ) ;
V_184 = F_74 ( V_6 ) ;
while ( V_184 ) {
F_82 ( V_8 , V_184 ) ;
V_185 = V_184 ;
V_184 = F_77 ( V_185 ) ;
F_72 ( V_185 ) ;
}
V_184 = F_76 ( V_6 ) ;
while ( V_184 ) {
F_82 ( V_8 , V_184 ) ;
V_185 = V_184 ;
V_184 = F_77 ( V_185 ) ;
F_72 ( V_185 ) ;
}
if ( F_29 ( V_120 , & V_6 -> V_12 ) )
F_112 ( V_6 ) ;
if ( F_29 ( V_119 , & V_6 -> V_12 ) ) {
F_88 ( V_8 , V_6 ) ;
F_111 ( V_6 ) ;
}
F_44 ( & V_6 -> V_16 ) ;
}
void F_201 ( struct V_32 * V_32 )
{
struct V_2 * V_6 ;
V_6 = F_11 ( V_32 ) ;
if ( ! V_6 )
return;
F_200 ( V_6 ) ;
F_48 ( V_6 ) ;
}
void F_202 ( struct V_7 * V_8 )
{
T_2 V_9 = 0 ;
struct V_2 * V_186 [ 8 ] ;
int V_108 , V_187 ;
while ( 1 ) {
F_16 ( & V_8 -> V_36 ) ;
V_187 = F_203 ( & V_8 -> V_37 ,
( void * * ) V_186 , V_9 ,
F_204 ( V_186 ) ) ;
if ( ! V_187 ) {
F_19 ( & V_8 -> V_36 ) ;
break;
}
V_9 = V_186 [ V_187 - 1 ] -> V_9 + 1 ;
for ( V_108 = 0 ; V_108 < V_187 ; V_108 ++ )
F_15 ( & V_186 [ V_108 ] -> V_10 ) ;
F_19 ( & V_8 -> V_36 ) ;
for ( V_108 = 0 ; V_108 < V_187 ; V_108 ++ ) {
F_200 ( V_186 [ V_108 ] ) ;
F_48 ( V_186 [ V_108 ] ) ;
}
}
}
void F_205 ( struct V_7 * V_8 )
{
struct V_29 * V_31 ;
struct V_2 * V_129 , * V_60 ;
V_31 = F_10 ( V_8 ) ;
V_129 = F_38 ( V_31 ) ;
while ( V_129 ) {
F_200 ( V_129 ) ;
V_60 = V_129 ;
V_129 = F_40 ( V_129 ) ;
F_48 ( V_60 ) ;
}
}
