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
V_6 -> V_13 = 0 ;
V_6 -> V_14 = V_15 ;
V_6 -> V_16 = V_15 ;
F_7 ( & V_6 -> V_17 ) ;
V_6 -> V_18 = 0 ;
F_8 ( & V_6 -> V_19 ) ;
F_8 ( & V_6 -> V_20 ) ;
V_6 -> V_21 = 0 ;
memset ( & V_6 -> V_22 , 0 , sizeof( V_6 -> V_22 ) ) ;
}
static inline int F_9 (
struct V_23 * V_24 ,
struct V_23 * V_25 )
{
if ( V_24 -> V_26 . type == V_27 &&
V_24 -> V_26 . V_28 == V_25 -> V_26 . V_28 &&
V_24 -> V_26 . type == V_25 -> V_26 . type &&
V_24 -> V_26 . V_29 + 1 == V_25 -> V_26 . V_29 )
return 1 ;
return 0 ;
}
static inline struct V_30 * F_10 (
struct V_7 * V_8 )
{
return V_8 -> V_31 -> V_32 ;
}
static struct V_2 * F_11 ( struct V_33 * V_33 )
{
struct V_34 * V_34 = F_12 ( V_33 ) ;
struct V_7 * V_8 = V_34 -> V_8 ;
T_2 V_35 = F_13 ( V_33 ) ;
struct V_2 * V_36 ;
V_36 = F_14 ( V_34 -> V_6 ) ;
if ( V_36 ) {
F_15 ( & V_36 -> V_10 ) ;
return V_36 ;
}
F_16 ( & V_8 -> V_37 ) ;
V_36 = F_17 ( & V_8 -> V_38 , V_35 ) ;
if ( V_36 ) {
if ( V_34 -> V_6 ) {
F_15 ( & V_36 -> V_10 ) ;
F_18 ( V_34 -> V_6 != V_36 ) ;
F_19 ( & V_8 -> V_37 ) ;
return V_36 ;
}
V_34 -> V_6 = V_36 ;
F_15 ( & V_36 -> V_10 ) ;
F_15 ( & V_36 -> V_10 ) ;
F_19 ( & V_8 -> V_37 ) ;
return V_36 ;
}
F_19 ( & V_8 -> V_37 ) ;
return NULL ;
}
static struct V_2 * F_20 (
struct V_33 * V_33 )
{
struct V_2 * V_36 ;
struct V_34 * V_34 = F_12 ( V_33 ) ;
struct V_7 * V_8 = V_34 -> V_8 ;
T_2 V_35 = F_13 ( V_33 ) ;
int V_39 ;
V_40:
V_36 = F_11 ( V_33 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_21 ( V_1 , V_41 ) ;
if ( ! V_36 )
return F_22 ( - V_5 ) ;
F_5 ( V_36 , V_8 , V_35 ) ;
F_15 ( & V_36 -> V_10 ) ;
F_15 ( & V_36 -> V_10 ) ;
V_39 = F_23 ( V_41 & ~ V_42 ) ;
if ( V_39 ) {
F_24 ( V_1 , V_36 ) ;
return F_22 ( V_39 ) ;
}
F_16 ( & V_8 -> V_37 ) ;
V_39 = F_25 ( & V_8 -> V_38 , V_35 , V_36 ) ;
if ( V_39 == - V_43 ) {
F_24 ( V_1 , V_36 ) ;
F_19 ( & V_8 -> V_37 ) ;
F_26 () ;
goto V_40;
}
V_34 -> V_6 = V_36 ;
F_19 ( & V_8 -> V_37 ) ;
F_26 () ;
return V_36 ;
}
static void F_27 ( struct V_30 * V_8 ,
struct V_2 * V_36 ,
int V_44 )
{
F_16 ( & V_8 -> V_45 ) ;
if ( V_36 -> V_12 ) {
if ( ! F_28 ( & V_36 -> V_20 ) )
F_29 ( & V_36 -> V_20 , & V_8 -> V_46 ) ;
else if ( V_44 )
F_30 ( & V_36 -> V_20 , & V_8 -> V_46 ) ;
} else {
F_30 ( & V_36 -> V_19 , & V_8 -> V_47 ) ;
F_30 ( & V_36 -> V_20 , & V_8 -> V_46 ) ;
F_15 ( & V_36 -> V_10 ) ;
V_8 -> V_48 ++ ;
V_36 -> V_12 = 1 ;
}
F_19 ( & V_8 -> V_45 ) ;
}
static void F_31 ( struct V_30 * V_8 ,
struct V_2 * V_36 )
{
F_16 ( & V_8 -> V_45 ) ;
if ( V_36 -> V_12 ) {
V_8 -> V_48 -- ;
F_32 ( & V_36 -> V_10 ) ;
F_33 ( & V_36 -> V_19 ) ;
if ( ! F_28 ( & V_36 -> V_20 ) )
F_33 ( & V_36 -> V_20 ) ;
V_36 -> V_12 = 0 ;
}
F_19 ( & V_8 -> V_45 ) ;
}
static struct V_2 * F_34 (
struct V_30 * V_32 )
{
struct V_49 * V_50 ;
struct V_2 * V_36 = NULL ;
F_16 ( & V_32 -> V_45 ) ;
if ( F_28 ( & V_32 -> V_47 ) )
goto V_51;
V_50 = V_32 -> V_47 . V_52 ;
V_36 = F_35 ( V_50 , struct V_2 , V_19 ) ;
F_15 ( & V_36 -> V_10 ) ;
V_51:
F_19 ( & V_32 -> V_45 ) ;
return V_36 ;
}
static struct V_2 * F_36 (
struct V_2 * V_36 )
{
struct V_30 * V_32 ;
struct V_49 * V_50 ;
struct V_2 * V_52 = NULL ;
V_32 = V_36 -> V_8 -> V_31 -> V_32 ;
F_16 ( & V_32 -> V_45 ) ;
if ( ! V_36 -> V_12 ) {
if ( F_28 ( & V_32 -> V_47 ) )
goto V_51;
V_50 = V_32 -> V_47 . V_52 ;
} else if ( F_37 ( & V_36 -> V_19 , & V_32 -> V_47 ) )
goto V_51;
else
V_50 = V_36 -> V_19 . V_52 ;
V_52 = F_35 ( V_50 , struct V_2 , V_19 ) ;
F_15 ( & V_52 -> V_10 ) ;
V_51:
F_19 ( & V_32 -> V_45 ) ;
return V_52 ;
}
static void F_38 (
struct V_2 * V_6 ,
int V_44 )
{
struct V_30 * V_32 ;
if ( ! V_6 )
return;
V_32 = V_6 -> V_8 -> V_31 -> V_32 ;
F_39 ( & V_6 -> V_17 ) ;
if ( V_6 -> V_11 )
F_27 ( V_32 , V_6 , V_44 ) ;
else
F_31 ( V_32 , V_6 ) ;
F_40 ( & V_6 -> V_17 ) ;
if ( F_41 ( & V_6 -> V_10 ) ) {
struct V_7 * V_8 = V_6 -> V_8 ;
F_16 ( & V_8 -> V_37 ) ;
if ( F_42 ( & V_6 -> V_10 ) == 0 ) {
F_43 ( & V_8 -> V_38 ,
V_6 -> V_9 ) ;
F_24 ( V_1 , V_6 ) ;
}
F_19 ( & V_8 -> V_37 ) ;
}
}
static inline void F_44 ( struct V_2 * V_36 )
{
F_38 ( V_36 , 0 ) ;
}
static struct V_2 * F_45 (
struct V_30 * V_32 )
{
struct V_49 * V_50 ;
struct V_2 * V_36 = NULL ;
F_16 ( & V_32 -> V_45 ) ;
if ( F_28 ( & V_32 -> V_46 ) )
goto V_51;
V_50 = V_32 -> V_46 . V_52 ;
F_33 ( V_50 ) ;
V_36 = F_35 ( V_50 , struct V_2 , V_20 ) ;
F_15 ( & V_36 -> V_10 ) ;
V_51:
F_19 ( & V_32 -> V_45 ) ;
return V_36 ;
}
static inline void F_46 (
struct V_2 * V_36 )
{
F_38 ( V_36 , 1 ) ;
}
static struct V_23 * F_47 ( T_3 V_53 )
{
struct V_23 * V_54 ;
V_54 = F_48 ( sizeof( * V_54 ) + V_53 , V_41 ) ;
if ( V_54 ) {
V_54 -> V_53 = V_53 ;
V_54 -> V_55 = 0 ;
V_54 -> V_21 = 0 ;
V_54 -> V_6 = NULL ;
F_6 ( & V_54 -> V_10 , 1 ) ;
}
return V_54 ;
}
static struct V_23 * F_49 (
struct V_56 * V_8 ,
struct V_57 * V_26 ,
struct V_23 * * V_58 ,
struct V_23 * * V_52 )
{
struct V_59 * V_36 , * V_60 = NULL ;
struct V_23 * V_61 = NULL ;
int V_39 = 0 ;
V_36 = V_8 -> V_59 ;
while ( V_36 ) {
V_61 = F_50 ( V_36 , struct V_23 ,
V_59 ) ;
V_60 = V_36 ;
V_39 = F_51 ( & V_61 -> V_26 , V_26 ) ;
if ( V_39 < 0 )
V_36 = V_36 -> V_62 ;
else if ( V_39 > 0 )
V_36 = V_36 -> V_63 ;
else
return V_61 ;
}
if ( V_58 ) {
if ( ! V_60 )
* V_58 = NULL ;
else if ( V_39 < 0 )
* V_58 = V_61 ;
else if ( ( V_36 = F_52 ( V_60 ) ) != NULL ) {
* V_58 = F_50 ( V_36 , struct V_23 ,
V_59 ) ;
} else
* V_58 = NULL ;
}
if ( V_52 ) {
if ( ! V_60 )
* V_52 = NULL ;
else if ( V_39 > 0 )
* V_52 = V_61 ;
else if ( ( V_36 = F_53 ( V_60 ) ) != NULL ) {
* V_52 = F_50 ( V_36 , struct V_23 ,
V_59 ) ;
} else
* V_52 = NULL ;
}
return NULL ;
}
static struct V_23 * F_54 (
struct V_2 * V_6 ,
struct V_57 * V_26 )
{
struct V_23 * V_54 ;
V_54 = F_49 ( & V_6 -> V_14 , V_26 ,
NULL , NULL ) ;
return V_54 ;
}
static int F_55 ( struct V_2 * V_6 ,
struct V_23 * V_64 ,
int V_65 )
{
struct V_59 * * V_50 , * V_36 ;
struct V_59 * V_66 = NULL ;
struct V_56 * V_8 ;
struct V_23 * V_54 ;
int V_67 ;
if ( V_65 == V_68 )
V_8 = & V_6 -> V_14 ;
else if ( V_65 == V_69 )
V_8 = & V_6 -> V_16 ;
else
F_56 () ;
V_50 = & V_8 -> V_59 ;
V_36 = & V_64 -> V_59 ;
while ( * V_50 ) {
V_66 = * V_50 ;
V_54 = F_50 ( V_66 , struct V_23 ,
V_59 ) ;
V_67 = F_51 ( & V_54 -> V_26 , & V_64 -> V_26 ) ;
if ( V_67 < 0 )
V_50 = & ( * V_50 ) -> V_62 ;
else if ( V_67 > 0 )
V_50 = & ( * V_50 ) -> V_63 ;
else
return - V_43 ;
}
F_57 ( V_36 , V_66 , V_50 ) ;
F_58 ( V_36 , V_8 ) ;
V_64 -> V_6 = V_6 ;
V_64 -> V_55 = V_65 ;
if ( V_64 -> V_26 . type == V_27 &&
V_65 == V_68 &&
V_64 -> V_26 . V_29 >= V_6 -> V_18 )
V_6 -> V_18 = V_64 -> V_26 . V_29 + 1 ;
V_6 -> V_11 ++ ;
F_15 ( & V_6 -> V_8 -> V_31 -> V_32 -> V_70 ) ;
return 0 ;
}
static int F_59 ( struct V_2 * V_36 ,
struct V_23 * V_54 )
{
return F_55 ( V_36 , V_54 ,
V_68 ) ;
}
static int F_60 ( struct V_2 * V_36 ,
struct V_23 * V_54 )
{
return F_55 ( V_36 , V_54 ,
V_69 ) ;
}
static void F_61 ( struct V_30 * V_32 )
{
int V_71 = F_62 ( & V_32 -> V_72 ) ;
if ( ( F_63 ( & V_32 -> V_70 ) <
V_73 || V_71 % V_74 == 0 ) &&
F_64 ( & V_32 -> V_75 ) )
F_65 ( & V_32 -> V_75 ) ;
}
static void F_66 ( struct V_23 * V_61 )
{
struct V_56 * V_8 ;
struct V_30 * V_32 ;
V_32 = V_61 -> V_6 -> V_8 -> V_31 -> V_32 ;
F_18 ( ! V_32 ) ;
F_18 ( V_61 -> V_55 != V_69 &&
V_61 -> V_55 != V_68 ) ;
if ( V_61 -> V_55 == V_68 )
V_8 = & V_61 -> V_6 -> V_14 ;
else
V_8 = & V_61 -> V_6 -> V_16 ;
F_67 ( & V_61 -> V_59 , V_8 ) ;
V_61 -> V_6 -> V_11 -- ;
F_61 ( V_32 ) ;
}
static void F_68 ( struct V_23 * V_54 )
{
if ( V_54 ) {
F_66 ( V_54 ) ;
if ( F_41 ( & V_54 -> V_10 ) )
F_69 ( V_54 ) ;
}
}
static struct V_23 * F_70 (
struct V_2 * V_6 )
{
struct V_59 * V_50 ;
struct V_23 * V_54 = NULL ;
V_50 = F_71 ( & V_6 -> V_14 ) ;
if ( V_50 )
V_54 = F_50 ( V_50 , struct V_23 , V_59 ) ;
return V_54 ;
}
static struct V_23 * F_72 (
struct V_2 * V_6 )
{
struct V_59 * V_50 ;
struct V_23 * V_54 = NULL ;
V_50 = F_71 ( & V_6 -> V_16 ) ;
if ( V_50 )
V_54 = F_50 ( V_50 , struct V_23 , V_59 ) ;
return V_54 ;
}
static struct V_23 * F_73 (
struct V_23 * V_54 )
{
struct V_59 * V_50 ;
struct V_23 * V_52 = NULL ;
V_50 = F_53 ( & V_54 -> V_59 ) ;
if ( V_50 )
V_52 = F_50 ( V_50 , struct V_23 , V_59 ) ;
return V_52 ;
}
static int F_74 ( struct V_76 * V_77 ,
struct V_7 * V_8 ,
struct V_23 * V_54 )
{
struct V_78 * V_79 ;
struct V_78 * V_80 ;
T_2 V_81 ;
int V_39 ;
if ( ! V_77 -> V_21 )
return 0 ;
V_79 = V_77 -> V_82 ;
V_80 = & V_8 -> V_31 -> V_83 ;
V_81 = F_75 ( V_8 , 1 ) ;
V_39 = F_76 ( V_79 , V_80 , V_81 ) ;
if ( ! V_39 ) {
F_77 ( V_8 -> V_31 , L_2 ,
V_54 -> V_26 . V_28 ,
V_81 , 1 ) ;
V_54 -> V_21 = V_81 ;
}
return V_39 ;
}
static void F_78 ( struct V_7 * V_8 ,
struct V_23 * V_54 )
{
struct V_78 * V_84 ;
if ( ! V_54 -> V_21 )
return;
V_84 = & V_8 -> V_31 -> V_83 ;
F_77 ( V_8 -> V_31 , L_2 ,
V_54 -> V_26 . V_28 , V_54 -> V_21 ,
0 ) ;
F_79 ( V_8 , V_84 ,
V_54 -> V_21 ) ;
}
static int F_80 (
struct V_76 * V_77 ,
struct V_7 * V_8 ,
struct V_33 * V_33 ,
struct V_2 * V_36 )
{
struct V_78 * V_79 ;
struct V_78 * V_80 ;
T_2 V_81 ;
int V_39 ;
bool V_85 = false ;
V_79 = V_77 -> V_82 ;
V_80 = & V_8 -> V_31 -> V_83 ;
V_81 = F_75 ( V_8 , 1 ) ;
if ( ! V_79 || ( ! V_77 -> V_21 &&
V_79 -> type != V_86 ) ) {
V_39 = F_81 ( V_8 , V_80 , V_81 ,
V_87 ) ;
if ( V_39 == - V_88 )
V_39 = - V_89 ;
if ( ! V_39 ) {
V_36 -> V_21 = V_81 ;
F_77 ( V_8 -> V_31 ,
L_3 ,
F_13 ( V_33 ) ,
V_81 , 1 ) ;
}
return V_39 ;
} else if ( V_79 -> type == V_86 ) {
F_16 ( & F_12 ( V_33 ) -> V_45 ) ;
if ( F_82 ( V_90 ,
& F_12 ( V_33 ) -> V_91 ) ) {
F_19 ( & F_12 ( V_33 ) -> V_45 ) ;
V_85 = true ;
goto V_92;
}
F_19 ( & F_12 ( V_33 ) -> V_45 ) ;
V_39 = F_81 ( V_8 , V_80 , V_81 ,
V_87 ) ;
if ( ! V_39 )
goto V_51;
V_39 = F_76 ( V_79 , V_80 , V_81 ) ;
if ( ! V_39 )
goto V_51;
F_83 ( 1 ) ;
V_39 = F_76 ( & V_8 -> V_31 -> V_93 ,
V_80 , V_81 ) ;
goto V_51;
}
V_92:
V_39 = F_76 ( V_79 , V_80 , V_81 ) ;
V_51:
if ( ! V_39 ) {
F_77 ( V_8 -> V_31 , L_3 ,
F_13 ( V_33 ) , V_81 , 1 ) ;
V_36 -> V_21 = V_81 ;
}
if ( V_85 ) {
F_77 ( V_8 -> V_31 , L_4 ,
F_13 ( V_33 ) , V_81 , 0 ) ;
F_79 ( V_8 , V_79 , V_81 ) ;
}
return V_39 ;
}
static void F_84 ( struct V_7 * V_8 ,
struct V_2 * V_36 )
{
struct V_78 * V_84 ;
if ( ! V_36 -> V_21 )
return;
V_84 = & V_8 -> V_31 -> V_83 ;
F_77 ( V_8 -> V_31 , L_3 ,
V_36 -> V_9 , V_36 -> V_21 , 0 ) ;
F_79 ( V_8 , V_84 ,
V_36 -> V_21 ) ;
V_36 -> V_21 = 0 ;
}
static int F_85 ( struct V_7 * V_8 ,
struct V_94 * V_95 ,
struct V_23 * V_54 )
{
struct V_23 * V_96 , * V_52 ;
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
int V_39 = 0 ;
F_18 ( ! V_95 -> V_48 [ 0 ] ) ;
V_101 = V_95 -> V_48 [ 0 ] ;
V_97 = F_86 ( V_8 , V_101 ) ;
F_8 ( & V_105 ) ;
V_52 = V_54 ;
V_107 = 0 ;
while ( V_99 + V_52 -> V_53 + sizeof( struct V_109 ) <=
V_97 ) {
V_98 += V_52 -> V_53 ;
V_99 += V_52 -> V_53 + sizeof( struct V_109 ) ;
F_30 ( & V_52 -> V_110 , & V_105 ) ;
V_107 ++ ;
V_96 = V_52 ;
V_52 = F_73 ( V_96 ) ;
if ( ! V_52 )
break;
if ( ! F_9 ( V_96 , V_52 ) )
break;
}
if ( ! V_107 ) {
V_39 = 0 ;
goto V_51;
}
F_87 ( V_95 ) ;
V_103 = F_48 ( sizeof( struct V_57 ) * V_107 , V_41 ) ;
if ( ! V_103 ) {
V_39 = - V_5 ;
goto V_51;
}
V_104 = F_48 ( sizeof( T_3 ) * V_107 , V_41 ) ;
if ( ! V_104 ) {
V_39 = - V_5 ;
goto error;
}
V_108 = 0 ;
F_88 (next, &head, tree_list) {
V_103 [ V_108 ] = V_52 -> V_26 ;
V_104 [ V_108 ] = V_52 -> V_53 ;
V_108 ++ ;
}
F_89 ( V_95 , NULL , 0 ) ;
F_90 ( V_8 , V_95 , V_103 , V_104 ,
V_98 , V_99 , V_107 ) ;
V_106 = V_95 -> V_111 [ 0 ] ;
F_91 (curr, next, &head, tree_list) {
V_102 = F_92 ( V_101 , V_106 , char ) ;
F_93 ( V_101 , & V_96 -> V_112 ,
( unsigned long ) V_102 ,
V_96 -> V_53 ) ;
V_106 ++ ;
F_78 ( V_8 , V_96 ) ;
F_94 ( & V_96 -> V_110 ) ;
F_68 ( V_96 ) ;
}
error:
F_69 ( V_104 ) ;
F_69 ( V_103 ) ;
V_51:
return V_39 ;
}
static int F_95 ( struct V_76 * V_77 ,
struct V_7 * V_8 ,
struct V_94 * V_95 ,
struct V_23 * V_61 )
{
struct V_100 * V_101 ;
char * V_113 ;
int V_39 ;
V_39 = F_96 ( V_77 , V_8 , V_95 , & V_61 -> V_26 ,
V_61 -> V_53 ) ;
if ( V_39 < 0 && V_39 != - V_43 )
return V_39 ;
V_101 = V_95 -> V_48 [ 0 ] ;
V_113 = F_92 ( V_101 , V_95 -> V_111 [ 0 ] , char ) ;
F_93 ( V_101 , V_61 -> V_112 , ( unsigned long ) V_113 ,
V_61 -> V_53 ) ;
F_97 ( V_101 ) ;
F_78 ( V_8 , V_61 ) ;
return 0 ;
}
static int F_98 ( struct V_76 * V_77 ,
struct V_94 * V_95 ,
struct V_7 * V_8 ,
struct V_2 * V_36 )
{
struct V_23 * V_96 , * V_58 ;
int V_39 = 0 ;
V_114:
F_39 ( & V_36 -> V_17 ) ;
V_96 = F_70 ( V_36 ) ;
if ( ! V_96 )
goto V_115;
V_39 = F_95 ( V_77 , V_8 , V_95 , V_96 ) ;
if ( V_39 < 0 ) {
F_99 ( V_95 ) ;
goto V_115;
}
V_58 = V_96 ;
V_96 = F_73 ( V_58 ) ;
if ( V_96 && F_9 ( V_58 , V_96 ) ) {
V_95 -> V_111 [ 0 ] ++ ;
F_85 ( V_8 , V_95 , V_96 ) ;
}
F_68 ( V_58 ) ;
F_97 ( V_95 -> V_48 [ 0 ] ) ;
F_99 ( V_95 ) ;
F_40 ( & V_36 -> V_17 ) ;
goto V_114;
V_115:
F_40 ( & V_36 -> V_17 ) ;
return V_39 ;
}
static int F_100 ( struct V_76 * V_77 ,
struct V_7 * V_8 ,
struct V_94 * V_95 ,
struct V_23 * V_54 )
{
struct V_23 * V_96 , * V_52 ;
struct V_100 * V_101 ;
struct V_57 V_26 ;
struct V_49 V_105 ;
int V_107 , V_108 , V_116 ;
int V_39 = 0 ;
F_18 ( ! V_95 -> V_48 [ 0 ] ) ;
V_101 = V_95 -> V_48 [ 0 ] ;
V_108 = V_95 -> V_111 [ 0 ] ;
V_116 = F_101 ( V_101 ) - 1 ;
if ( V_108 > V_116 )
return - V_117 ;
V_52 = V_54 ;
F_8 ( & V_105 ) ;
F_102 ( V_101 , & V_26 , V_108 ) ;
V_107 = 0 ;
while ( F_51 ( & V_52 -> V_26 , & V_26 ) == 0 ) {
F_30 ( & V_52 -> V_110 , & V_105 ) ;
V_107 ++ ;
V_96 = V_52 ;
V_52 = F_73 ( V_96 ) ;
if ( ! V_52 )
break;
if ( ! F_9 ( V_96 , V_52 ) )
break;
V_108 ++ ;
if ( V_108 > V_116 )
break;
F_102 ( V_101 , & V_26 , V_108 ) ;
}
if ( ! V_107 )
return 0 ;
V_39 = F_103 ( V_77 , V_8 , V_95 , V_95 -> V_111 [ 0 ] , V_107 ) ;
if ( V_39 )
goto V_51;
F_91 (curr, next, &head, tree_list) {
F_78 ( V_8 , V_96 ) ;
F_94 ( & V_96 -> V_110 ) ;
F_68 ( V_96 ) ;
}
V_51:
return V_39 ;
}
static int F_104 ( struct V_76 * V_77 ,
struct V_94 * V_95 ,
struct V_7 * V_8 ,
struct V_2 * V_36 )
{
struct V_23 * V_96 , * V_58 ;
int V_39 = 0 ;
V_114:
F_39 ( & V_36 -> V_17 ) ;
V_96 = F_72 ( V_36 ) ;
if ( ! V_96 )
goto V_118;
V_39 = F_105 ( V_77 , V_8 , & V_96 -> V_26 , V_95 , - 1 , 1 ) ;
if ( V_39 < 0 )
goto V_118;
else if ( V_39 > 0 ) {
V_58 = V_96 ;
V_96 = F_73 ( V_58 ) ;
F_68 ( V_58 ) ;
V_39 = 0 ;
F_99 ( V_95 ) ;
if ( V_96 ) {
F_40 ( & V_36 -> V_17 ) ;
goto V_114;
} else
goto V_118;
}
F_100 ( V_77 , V_8 , V_95 , V_96 ) ;
F_99 ( V_95 ) ;
F_40 ( & V_36 -> V_17 ) ;
goto V_114;
V_118:
F_99 ( V_95 ) ;
F_40 ( & V_36 -> V_17 ) ;
return V_39 ;
}
static void F_106 ( struct V_2 * V_6 )
{
struct V_30 * V_32 ;
if ( V_6 && V_6 -> V_13 ) {
F_18 ( ! V_6 -> V_8 ) ;
V_6 -> V_13 = 0 ;
V_6 -> V_11 -- ;
V_32 = V_6 -> V_8 -> V_31 -> V_32 ;
F_61 ( V_32 ) ;
}
}
static int F_107 ( struct V_76 * V_77 ,
struct V_7 * V_8 ,
struct V_94 * V_95 ,
struct V_2 * V_36 )
{
struct V_57 V_26 ;
struct V_119 * V_22 ;
struct V_100 * V_101 ;
int V_39 ;
V_26 . V_28 = V_36 -> V_9 ;
F_108 ( & V_26 , V_120 ) ;
V_26 . V_29 = 0 ;
V_39 = F_109 ( V_77 , V_8 , V_95 , & V_26 , 1 ) ;
if ( V_39 > 0 ) {
F_99 ( V_95 ) ;
return - V_117 ;
} else if ( V_39 < 0 ) {
return V_39 ;
}
F_110 ( V_95 , 1 ) ;
V_101 = V_95 -> V_48 [ 0 ] ;
V_22 = F_92 ( V_101 , V_95 -> V_111 [ 0 ] ,
struct V_119 ) ;
F_93 ( V_101 , & V_36 -> V_22 , ( unsigned long ) V_22 ,
sizeof( struct V_119 ) ) ;
F_97 ( V_101 ) ;
F_99 ( V_95 ) ;
F_84 ( V_8 , V_36 ) ;
F_106 ( V_36 ) ;
return 0 ;
}
static inline int F_111 ( struct V_76 * V_77 ,
struct V_7 * V_8 ,
struct V_94 * V_95 ,
struct V_2 * V_36 )
{
int V_39 ;
F_39 ( & V_36 -> V_17 ) ;
if ( ! V_36 -> V_13 ) {
F_40 ( & V_36 -> V_17 ) ;
return 0 ;
}
V_39 = F_107 ( V_77 , V_8 , V_95 , V_36 ) ;
F_40 ( & V_36 -> V_17 ) ;
return V_39 ;
}
static inline int
F_112 ( struct V_76 * V_77 ,
struct V_94 * V_95 ,
struct V_2 * V_36 )
{
int V_39 ;
V_39 = F_98 ( V_77 , V_95 , V_36 -> V_8 , V_36 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_104 ( V_77 , V_95 , V_36 -> V_8 , V_36 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_111 ( V_77 , V_36 -> V_8 , V_95 , V_36 ) ;
return V_39 ;
}
static int F_113 ( struct V_76 * V_77 ,
struct V_7 * V_8 , int V_121 )
{
struct V_30 * V_32 ;
struct V_2 * V_122 , * V_60 ;
struct V_94 * V_95 ;
struct V_78 * V_82 ;
int V_39 = 0 ;
bool V_11 = ( V_121 > 0 ) ;
if ( V_77 -> V_123 )
return - V_124 ;
V_95 = F_114 () ;
if ( ! V_95 )
return - V_5 ;
V_95 -> V_125 = 1 ;
V_82 = V_77 -> V_82 ;
V_77 -> V_82 = & V_8 -> V_31 -> V_83 ;
V_32 = F_10 ( V_8 ) ;
V_122 = F_34 ( V_32 ) ;
while ( V_122 && ( ! V_11 || ( V_11 && V_121 -- ) ) ) {
V_39 = F_112 ( V_77 , V_95 ,
V_122 ) ;
if ( V_39 ) {
F_44 ( V_122 ) ;
V_122 = NULL ;
F_115 ( V_77 , V_8 , V_39 ) ;
break;
}
V_60 = V_122 ;
V_122 = F_36 ( V_122 ) ;
F_44 ( V_60 ) ;
}
if ( V_122 )
F_44 ( V_122 ) ;
F_116 ( V_95 ) ;
V_77 -> V_82 = V_82 ;
return V_39 ;
}
int F_117 ( struct V_76 * V_77 ,
struct V_7 * V_8 )
{
return F_113 ( V_77 , V_8 , - 1 ) ;
}
int F_118 ( struct V_76 * V_77 ,
struct V_7 * V_8 , int V_121 )
{
return F_113 ( V_77 , V_8 , V_121 ) ;
}
int F_119 ( struct V_76 * V_77 ,
struct V_33 * V_33 )
{
struct V_2 * V_6 = F_11 ( V_33 ) ;
struct V_94 * V_95 ;
struct V_78 * V_82 ;
int V_39 ;
if ( ! V_6 )
return 0 ;
F_39 ( & V_6 -> V_17 ) ;
if ( ! V_6 -> V_11 ) {
F_40 ( & V_6 -> V_17 ) ;
F_44 ( V_6 ) ;
return 0 ;
}
F_40 ( & V_6 -> V_17 ) ;
V_95 = F_114 () ;
if ( ! V_95 )
return - V_5 ;
V_95 -> V_125 = 1 ;
V_82 = V_77 -> V_82 ;
V_77 -> V_82 = & V_6 -> V_8 -> V_31 -> V_83 ;
V_39 = F_112 ( V_77 , V_95 , V_6 ) ;
F_44 ( V_6 ) ;
F_116 ( V_95 ) ;
V_77 -> V_82 = V_82 ;
return V_39 ;
}
int F_120 ( struct V_33 * V_33 )
{
struct V_76 * V_77 ;
struct V_2 * V_6 = F_11 ( V_33 ) ;
struct V_94 * V_95 ;
struct V_78 * V_82 ;
int V_39 ;
if ( ! V_6 )
return 0 ;
F_39 ( & V_6 -> V_17 ) ;
if ( ! V_6 -> V_13 ) {
F_40 ( & V_6 -> V_17 ) ;
F_44 ( V_6 ) ;
return 0 ;
}
F_40 ( & V_6 -> V_17 ) ;
V_77 = F_121 ( V_6 -> V_8 ) ;
if ( F_122 ( V_77 ) ) {
V_39 = F_123 ( V_77 ) ;
goto V_51;
}
V_95 = F_114 () ;
if ( ! V_95 ) {
V_39 = - V_5 ;
goto V_126;
}
V_95 -> V_125 = 1 ;
V_82 = V_77 -> V_82 ;
V_77 -> V_82 = & V_6 -> V_8 -> V_31 -> V_83 ;
F_39 ( & V_6 -> V_17 ) ;
if ( V_6 -> V_13 )
V_39 = F_107 ( V_77 , V_6 -> V_8 ,
V_95 , V_6 ) ;
else
V_39 = 0 ;
F_40 ( & V_6 -> V_17 ) ;
F_116 ( V_95 ) ;
V_77 -> V_82 = V_82 ;
V_126:
F_124 ( V_77 , V_6 -> V_8 ) ;
F_125 ( V_6 -> V_8 ) ;
V_51:
F_44 ( V_6 ) ;
return V_39 ;
}
void F_126 ( struct V_33 * V_33 )
{
struct V_2 * V_6 ;
V_6 = F_14 ( F_12 ( V_33 ) -> V_6 ) ;
if ( ! V_6 )
return;
F_12 ( V_33 ) -> V_6 = NULL ;
F_44 ( V_6 ) ;
}
static void F_127 ( struct V_127 * V_128 )
{
struct V_129 * V_130 ;
struct V_30 * V_32 ;
struct V_76 * V_77 ;
struct V_94 * V_95 ;
struct V_2 * V_6 = NULL ;
struct V_7 * V_8 ;
struct V_78 * V_82 ;
int V_131 = 0 ;
V_130 = F_128 ( V_128 , struct V_129 , V_128 ) ;
V_32 = V_130 -> V_32 ;
V_95 = F_114 () ;
if ( ! V_95 )
goto V_51;
V_40:
if ( F_42 ( & V_32 -> V_70 ) < V_73 / 2 )
goto V_132;
V_6 = F_45 ( V_32 ) ;
if ( ! V_6 )
goto V_132;
V_95 -> V_125 = 1 ;
V_8 = V_6 -> V_8 ;
V_77 = F_121 ( V_8 ) ;
if ( F_122 ( V_77 ) )
goto V_133;
V_82 = V_77 -> V_82 ;
V_77 -> V_82 = & V_8 -> V_31 -> V_83 ;
F_112 ( V_77 , V_95 , V_6 ) ;
F_39 ( & V_6 -> V_17 ) ;
F_31 ( V_8 -> V_31 -> V_32 , V_6 ) ;
F_40 ( & V_6 -> V_17 ) ;
V_77 -> V_82 = V_82 ;
F_129 ( V_77 , V_8 ) ;
F_130 ( V_8 ) ;
V_133:
F_99 ( V_95 ) ;
V_131 ++ ;
F_46 ( V_6 ) ;
if ( V_130 -> V_121 == 0 || V_131 < V_130 -> V_121 )
goto V_40;
V_132:
F_116 ( V_95 ) ;
V_51:
F_65 ( & V_32 -> V_75 ) ;
F_69 ( V_130 ) ;
}
static int F_131 ( struct V_30 * V_32 ,
struct V_7 * V_8 , int V_121 )
{
struct V_129 * V_130 ;
if ( F_42 ( & V_32 -> V_70 ) < V_73 )
return 0 ;
V_130 = F_48 ( sizeof( * V_130 ) , V_41 ) ;
if ( ! V_130 )
return - V_5 ;
V_130 -> V_32 = V_32 ;
V_130 -> V_128 . V_134 = F_127 ;
V_130 -> V_128 . V_135 = 0 ;
V_130 -> V_121 = V_121 ;
F_132 ( & V_8 -> V_31 -> V_136 , & V_130 -> V_128 ) ;
return 0 ;
}
void F_133 ( struct V_7 * V_8 )
{
struct V_30 * V_32 ;
V_32 = F_10 ( V_8 ) ;
F_83 ( F_34 ( V_32 ) ) ;
}
static int F_134 ( struct V_30 * V_32 ,
int V_71 , int V_11 )
{
int V_137 = F_42 ( & V_32 -> V_72 ) ;
if ( V_137 < V_71 || V_137 >= V_71 + V_11 )
return 1 ;
return 0 ;
}
void F_135 ( struct V_7 * V_8 )
{
struct V_30 * V_32 ;
int V_71 ;
V_32 = F_10 ( V_8 ) ;
if ( F_42 ( & V_32 -> V_70 ) < V_73 )
return;
V_71 = F_42 ( & V_32 -> V_72 ) ;
if ( F_42 ( & V_32 -> V_70 ) >= V_138 ) {
int V_39 ;
F_136 ( V_139 ) ;
V_39 = F_131 ( V_32 , V_8 , 0 ) ;
if ( V_39 )
return;
while ( 1 ) {
F_137 ( & V_32 -> V_75 , & V_139 ,
V_140 ) ;
if ( F_134 ( V_32 , V_71 ,
V_74 ) ||
F_42 ( & V_32 -> V_70 ) <
V_73 ) {
break;
}
if ( ! F_138 ( V_141 ) )
F_139 () ;
else
break;
}
F_140 ( & V_32 -> V_75 , & V_139 ) ;
}
F_131 ( V_32 , V_8 , V_74 ) ;
}
int F_141 ( struct V_76 * V_77 ,
struct V_7 * V_8 , const char * V_142 ,
int V_143 , struct V_33 * V_144 ,
struct V_145 * V_146 , T_4 type ,
T_2 V_147 )
{
struct V_2 * V_6 ;
struct V_23 * V_61 ;
struct V_148 * V_149 ;
int V_39 ;
V_6 = F_20 ( V_144 ) ;
if ( F_122 ( V_6 ) )
return F_123 ( V_6 ) ;
V_61 = F_47 ( sizeof( * V_149 ) + V_143 ) ;
if ( ! V_61 ) {
V_39 = - V_5 ;
goto V_150;
}
V_61 -> V_26 . V_28 = F_13 ( V_144 ) ;
F_108 ( & V_61 -> V_26 , V_27 ) ;
V_61 -> V_26 . V_29 = V_147 ;
V_149 = (struct V_148 * ) V_61 -> V_112 ;
V_149 -> V_151 = * V_146 ;
V_149 -> V_152 = F_142 ( V_77 -> V_152 ) ;
V_149 -> V_53 = 0 ;
V_149 -> V_143 = F_143 ( V_143 ) ;
V_149 -> type = type ;
memcpy ( ( char * ) ( V_149 + 1 ) , V_142 , V_143 ) ;
V_39 = F_74 ( V_77 , V_8 , V_61 ) ;
F_18 ( V_39 ) ;
F_39 ( & V_6 -> V_17 ) ;
V_39 = F_59 ( V_6 , V_61 ) ;
if ( F_144 ( V_39 ) ) {
F_145 ( V_153 L_5
L_6
L_7 ,
V_142 ,
( unsigned long long ) V_6 -> V_8 -> V_28 ,
( unsigned long long ) V_6 -> V_9 ,
V_39 ) ;
F_56 () ;
}
F_40 ( & V_6 -> V_17 ) ;
V_150:
F_44 ( V_6 ) ;
return V_39 ;
}
static int F_146 ( struct V_7 * V_8 ,
struct V_2 * V_36 ,
struct V_57 * V_26 )
{
struct V_23 * V_54 ;
F_39 ( & V_36 -> V_17 ) ;
V_54 = F_54 ( V_36 , V_26 ) ;
if ( ! V_54 ) {
F_40 ( & V_36 -> V_17 ) ;
return 1 ;
}
F_78 ( V_8 , V_54 ) ;
F_68 ( V_54 ) ;
F_40 ( & V_36 -> V_17 ) ;
return 0 ;
}
int F_147 ( struct V_76 * V_77 ,
struct V_7 * V_8 , struct V_33 * V_144 ,
T_2 V_147 )
{
struct V_2 * V_36 ;
struct V_23 * V_54 ;
struct V_57 V_154 ;
int V_39 ;
V_36 = F_20 ( V_144 ) ;
if ( F_122 ( V_36 ) )
return F_123 ( V_36 ) ;
V_154 . V_28 = F_13 ( V_144 ) ;
F_108 ( & V_154 , V_27 ) ;
V_154 . V_29 = V_147 ;
V_39 = F_146 ( V_8 , V_36 , & V_154 ) ;
if ( ! V_39 )
goto V_155;
V_54 = F_47 ( 0 ) ;
if ( ! V_54 ) {
V_39 = - V_5 ;
goto V_155;
}
V_54 -> V_26 = V_154 ;
V_39 = F_74 ( V_77 , V_8 , V_54 ) ;
F_18 ( V_39 ) ;
F_39 ( & V_36 -> V_17 ) ;
V_39 = F_60 ( V_36 , V_54 ) ;
if ( F_144 ( V_39 ) ) {
F_145 ( V_153 L_8
L_9
L_7 ,
( unsigned long long ) V_147 ,
( unsigned long long ) V_36 -> V_8 -> V_28 ,
( unsigned long long ) V_36 -> V_9 ,
V_39 ) ;
F_56 () ;
}
F_40 ( & V_36 -> V_17 ) ;
V_155:
F_44 ( V_36 ) ;
return V_39 ;
}
int F_148 ( struct V_33 * V_33 )
{
struct V_2 * V_6 = F_11 ( V_33 ) ;
if ( ! V_6 )
return - V_117 ;
if ( ! V_6 -> V_18 ) {
F_44 ( V_6 ) ;
return - V_156 ;
}
F_12 ( V_33 ) -> V_18 = V_6 -> V_18 ;
F_44 ( V_6 ) ;
return 0 ;
}
void F_149 ( struct V_33 * V_33 , struct V_49 * V_157 ,
struct V_49 * V_158 )
{
struct V_2 * V_6 ;
struct V_23 * V_54 ;
V_6 = F_11 ( V_33 ) ;
if ( ! V_6 )
return;
F_39 ( & V_6 -> V_17 ) ;
V_54 = F_70 ( V_6 ) ;
while ( V_54 ) {
F_15 ( & V_54 -> V_10 ) ;
F_30 ( & V_54 -> V_159 , V_157 ) ;
V_54 = F_73 ( V_54 ) ;
}
V_54 = F_72 ( V_6 ) ;
while ( V_54 ) {
F_15 ( & V_54 -> V_10 ) ;
F_30 ( & V_54 -> V_159 , V_158 ) ;
V_54 = F_73 ( V_54 ) ;
}
F_40 ( & V_6 -> V_17 ) ;
F_32 ( & V_6 -> V_10 ) ;
}
void F_150 ( struct V_49 * V_157 ,
struct V_49 * V_158 )
{
struct V_23 * V_96 , * V_52 ;
F_91 (curr, next, ins_list, readdir_list) {
F_94 ( & V_96 -> V_159 ) ;
if ( F_41 ( & V_96 -> V_10 ) )
F_69 ( V_96 ) ;
}
F_91 (curr, next, del_list, readdir_list) {
F_94 ( & V_96 -> V_159 ) ;
if ( F_41 ( & V_96 -> V_10 ) )
F_69 ( V_96 ) ;
}
}
int F_151 ( struct V_49 * V_158 ,
T_2 V_147 )
{
struct V_23 * V_96 , * V_52 ;
int V_39 ;
if ( F_28 ( V_158 ) )
return 0 ;
F_91 (curr, next, del_list, readdir_list) {
if ( V_96 -> V_26 . V_29 > V_147 )
break;
F_94 ( & V_96 -> V_159 ) ;
V_39 = ( V_96 -> V_26 . V_29 == V_147 ) ;
if ( F_41 ( & V_96 -> V_10 ) )
F_69 ( V_96 ) ;
if ( V_39 )
return 1 ;
else
continue;
}
return 0 ;
}
int F_152 ( struct V_160 * V_161 ,
struct V_49 * V_157 )
{
struct V_148 * V_162 ;
struct V_23 * V_96 , * V_52 ;
struct V_57 V_151 ;
char * V_142 ;
int V_143 ;
int V_163 = 0 ;
unsigned char V_164 ;
if ( F_28 ( V_157 ) )
return 0 ;
F_91 (curr, next, ins_list, readdir_list) {
F_94 ( & V_96 -> V_159 ) ;
if ( V_96 -> V_26 . V_29 < V_161 -> V_165 ) {
if ( F_41 ( & V_96 -> V_10 ) )
F_69 ( V_96 ) ;
continue;
}
V_161 -> V_165 = V_96 -> V_26 . V_29 ;
V_162 = (struct V_148 * ) V_96 -> V_112 ;
V_142 = ( char * ) ( V_162 + 1 ) ;
V_143 = F_153 ( V_162 -> V_143 ) ;
V_164 = V_166 [ V_162 -> type ] ;
F_154 ( & V_151 , & V_162 -> V_151 ) ;
V_163 = ! F_155 ( V_161 , V_142 , V_143 ,
V_151 . V_28 , V_164 ) ;
if ( F_41 ( & V_96 -> V_10 ) )
F_69 ( V_96 ) ;
if ( V_163 )
return 1 ;
}
return 0 ;
}
static void F_156 ( struct V_76 * V_77 ,
struct V_119 * V_22 ,
struct V_33 * V_33 )
{
F_157 ( V_22 , F_158 ( V_33 ) ) ;
F_159 ( V_22 , F_160 ( V_33 ) ) ;
F_161 ( V_22 , F_12 ( V_33 ) -> V_167 ) ;
F_162 ( V_22 , V_33 -> V_168 ) ;
F_163 ( V_22 , V_33 -> V_169 ) ;
F_164 ( V_22 , F_165 ( V_33 ) ) ;
F_166 ( V_22 ,
F_12 ( V_33 ) -> V_170 ) ;
F_167 ( V_22 , V_33 -> V_171 ) ;
F_168 ( V_22 , V_77 -> V_152 ) ;
F_169 ( V_22 , V_33 -> V_172 ) ;
F_170 ( V_22 , F_12 ( V_33 ) -> V_135 ) ;
F_171 ( V_22 , 0 ) ;
F_172 ( F_173 ( V_22 ) ,
V_33 -> V_173 . V_174 ) ;
F_174 ( F_173 ( V_22 ) ,
V_33 -> V_173 . V_175 ) ;
F_172 ( F_175 ( V_22 ) ,
V_33 -> V_176 . V_174 ) ;
F_174 ( F_175 ( V_22 ) ,
V_33 -> V_176 . V_175 ) ;
F_172 ( F_176 ( V_22 ) ,
V_33 -> V_177 . V_174 ) ;
F_174 ( F_176 ( V_22 ) ,
V_33 -> V_177 . V_175 ) ;
}
int F_177 ( struct V_33 * V_33 , T_3 * V_178 )
{
struct V_2 * V_6 ;
struct V_119 * V_22 ;
struct V_179 * V_180 ;
V_6 = F_11 ( V_33 ) ;
if ( ! V_6 )
return - V_117 ;
F_39 ( & V_6 -> V_17 ) ;
if ( ! V_6 -> V_13 ) {
F_40 ( & V_6 -> V_17 ) ;
F_44 ( V_6 ) ;
return - V_117 ;
}
V_22 = & V_6 -> V_22 ;
F_178 ( V_33 , F_179 ( V_22 ) ) ;
F_180 ( V_33 , F_181 ( V_22 ) ) ;
F_182 ( V_33 , F_183 ( V_22 ) ) ;
V_33 -> V_168 = F_184 ( V_22 ) ;
F_185 ( V_33 , F_186 ( V_22 ) ) ;
F_187 ( V_33 , F_188 ( V_22 ) ) ;
F_12 ( V_33 ) -> V_170 = F_189 ( V_22 ) ;
V_33 -> V_171 = F_190 ( V_22 ) ;
V_33 -> V_172 = 0 ;
* V_178 = F_191 ( V_22 ) ;
F_12 ( V_33 ) -> V_135 = F_192 ( V_22 ) ;
V_180 = F_173 ( V_22 ) ;
V_33 -> V_173 . V_174 = F_193 ( V_180 ) ;
V_33 -> V_173 . V_175 = F_194 ( V_180 ) ;
V_180 = F_175 ( V_22 ) ;
V_33 -> V_176 . V_174 = F_193 ( V_180 ) ;
V_33 -> V_176 . V_175 = F_194 ( V_180 ) ;
V_180 = F_176 ( V_22 ) ;
V_33 -> V_177 . V_174 = F_193 ( V_180 ) ;
V_33 -> V_177 . V_175 = F_194 ( V_180 ) ;
V_33 -> V_181 = F_12 ( V_33 ) -> V_170 ;
F_12 ( V_33 ) -> V_18 = ( T_2 ) - 1 ;
F_40 ( & V_6 -> V_17 ) ;
F_44 ( V_6 ) ;
return 0 ;
}
int F_195 ( struct V_76 * V_77 ,
struct V_7 * V_8 , struct V_33 * V_33 )
{
struct V_2 * V_6 ;
int V_39 = 0 ;
V_6 = F_20 ( V_33 ) ;
if ( F_122 ( V_6 ) )
return F_123 ( V_6 ) ;
F_39 ( & V_6 -> V_17 ) ;
if ( V_6 -> V_13 ) {
F_156 ( V_77 , & V_6 -> V_22 , V_33 ) ;
goto V_150;
}
V_39 = F_80 ( V_77 , V_8 , V_33 ,
V_6 ) ;
if ( V_39 )
goto V_150;
F_156 ( V_77 , & V_6 -> V_22 , V_33 ) ;
V_6 -> V_13 = 1 ;
V_6 -> V_11 ++ ;
F_15 ( & V_8 -> V_31 -> V_32 -> V_70 ) ;
V_150:
F_40 ( & V_6 -> V_17 ) ;
F_44 ( V_6 ) ;
return V_39 ;
}
static void F_196 ( struct V_2 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_23 * V_182 , * V_183 ;
F_39 ( & V_6 -> V_17 ) ;
V_182 = F_70 ( V_6 ) ;
while ( V_182 ) {
F_78 ( V_8 , V_182 ) ;
V_183 = V_182 ;
V_182 = F_73 ( V_183 ) ;
F_68 ( V_183 ) ;
}
V_182 = F_72 ( V_6 ) ;
while ( V_182 ) {
F_78 ( V_8 , V_182 ) ;
V_183 = V_182 ;
V_182 = F_73 ( V_183 ) ;
F_68 ( V_183 ) ;
}
if ( V_6 -> V_13 ) {
F_84 ( V_8 , V_6 ) ;
F_106 ( V_6 ) ;
}
F_40 ( & V_6 -> V_17 ) ;
}
void F_197 ( struct V_33 * V_33 )
{
struct V_2 * V_6 ;
V_6 = F_11 ( V_33 ) ;
if ( ! V_6 )
return;
F_196 ( V_6 ) ;
F_44 ( V_6 ) ;
}
void F_198 ( struct V_7 * V_8 )
{
T_2 V_9 = 0 ;
struct V_2 * V_184 [ 8 ] ;
int V_108 , V_185 ;
while ( 1 ) {
F_16 ( & V_8 -> V_37 ) ;
V_185 = F_199 ( & V_8 -> V_38 ,
( void * * ) V_184 , V_9 ,
F_200 ( V_184 ) ) ;
if ( ! V_185 ) {
F_19 ( & V_8 -> V_37 ) ;
break;
}
V_9 = V_184 [ V_185 - 1 ] -> V_9 + 1 ;
for ( V_108 = 0 ; V_108 < V_185 ; V_108 ++ )
F_15 ( & V_184 [ V_108 ] -> V_10 ) ;
F_19 ( & V_8 -> V_37 ) ;
for ( V_108 = 0 ; V_108 < V_185 ; V_108 ++ ) {
F_196 ( V_184 [ V_108 ] ) ;
F_44 ( V_184 [ V_108 ] ) ;
}
}
}
void F_201 ( struct V_7 * V_8 )
{
struct V_30 * V_32 ;
struct V_2 * V_122 , * V_60 ;
V_32 = F_10 ( V_8 ) ;
V_122 = F_34 ( V_32 ) ;
while ( V_122 ) {
F_196 ( V_122 ) ;
V_60 = V_122 ;
V_122 = F_36 ( V_122 ) ;
F_44 ( V_60 ) ;
}
}
