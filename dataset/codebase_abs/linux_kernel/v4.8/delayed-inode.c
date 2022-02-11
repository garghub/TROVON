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
static inline struct V_23 * F_10 (
struct V_6 * V_7 )
{
return V_7 -> V_24 -> V_25 ;
}
static struct V_2 * F_11 ( struct V_26 * V_26 )
{
struct V_27 * V_27 = F_12 ( V_26 ) ;
struct V_6 * V_7 = V_27 -> V_7 ;
T_2 V_28 = F_13 ( V_26 ) ;
struct V_2 * V_29 ;
V_29 = F_14 ( V_27 -> V_5 ) ;
if ( V_29 ) {
F_15 ( & V_29 -> V_9 ) ;
return V_29 ;
}
F_16 ( & V_7 -> V_30 ) ;
V_29 = F_17 ( & V_7 -> V_31 , V_28 ) ;
if ( V_29 ) {
if ( V_27 -> V_5 ) {
F_15 ( & V_29 -> V_9 ) ;
F_18 ( V_27 -> V_5 != V_29 ) ;
F_19 ( & V_7 -> V_30 ) ;
return V_29 ;
}
V_27 -> V_5 = V_29 ;
F_20 ( 2 , & V_29 -> V_9 ) ;
F_19 ( & V_7 -> V_30 ) ;
return V_29 ;
}
F_19 ( & V_7 -> V_30 ) ;
return NULL ;
}
static struct V_2 * F_21 (
struct V_26 * V_26 )
{
struct V_2 * V_29 ;
struct V_27 * V_27 = F_12 ( V_26 ) ;
struct V_6 * V_7 = V_27 -> V_7 ;
T_2 V_28 = F_13 ( V_26 ) ;
int V_32 ;
V_33:
V_29 = F_11 ( V_26 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_22 ( V_1 , V_34 ) ;
if ( ! V_29 )
return F_23 ( - V_4 ) ;
F_5 ( V_29 , V_7 , V_28 ) ;
F_20 ( 2 , & V_29 -> V_9 ) ;
V_32 = F_24 ( V_34 ) ;
if ( V_32 ) {
F_25 ( V_1 , V_29 ) ;
return F_23 ( V_32 ) ;
}
F_16 ( & V_7 -> V_30 ) ;
V_32 = F_26 ( & V_7 -> V_31 , V_28 , V_29 ) ;
if ( V_32 == - V_35 ) {
F_19 ( & V_7 -> V_30 ) ;
F_25 ( V_1 , V_29 ) ;
F_27 () ;
goto V_33;
}
V_27 -> V_5 = V_29 ;
F_19 ( & V_7 -> V_30 ) ;
F_27 () ;
return V_29 ;
}
static void F_28 ( struct V_23 * V_7 ,
struct V_2 * V_29 ,
int V_36 )
{
F_16 ( & V_7 -> V_37 ) ;
if ( F_29 ( V_38 , & V_29 -> V_39 ) ) {
if ( ! F_30 ( & V_29 -> V_15 ) )
F_31 ( & V_29 -> V_15 , & V_7 -> V_40 ) ;
else if ( V_36 )
F_32 ( & V_29 -> V_15 , & V_7 -> V_40 ) ;
} else {
F_32 ( & V_29 -> V_14 , & V_7 -> V_41 ) ;
F_32 ( & V_29 -> V_15 , & V_7 -> V_40 ) ;
F_15 ( & V_29 -> V_9 ) ;
V_7 -> V_42 ++ ;
F_33 ( V_38 , & V_29 -> V_39 ) ;
}
F_19 ( & V_7 -> V_37 ) ;
}
static void F_34 ( struct V_23 * V_7 ,
struct V_2 * V_29 )
{
F_16 ( & V_7 -> V_37 ) ;
if ( F_29 ( V_38 , & V_29 -> V_39 ) ) {
V_7 -> V_42 -- ;
F_35 ( & V_29 -> V_9 ) ;
F_36 ( & V_29 -> V_14 ) ;
if ( ! F_30 ( & V_29 -> V_15 ) )
F_36 ( & V_29 -> V_15 ) ;
F_37 ( V_38 , & V_29 -> V_39 ) ;
}
F_19 ( & V_7 -> V_37 ) ;
}
static struct V_2 * F_38 (
struct V_23 * V_25 )
{
struct V_43 * V_44 ;
struct V_2 * V_29 = NULL ;
F_16 ( & V_25 -> V_37 ) ;
if ( F_30 ( & V_25 -> V_41 ) )
goto V_45;
V_44 = V_25 -> V_41 . V_46 ;
V_29 = F_39 ( V_44 , struct V_2 , V_14 ) ;
F_15 ( & V_29 -> V_9 ) ;
V_45:
F_19 ( & V_25 -> V_37 ) ;
return V_29 ;
}
static struct V_2 * F_40 (
struct V_2 * V_29 )
{
struct V_23 * V_25 ;
struct V_43 * V_44 ;
struct V_2 * V_46 = NULL ;
V_25 = V_29 -> V_7 -> V_24 -> V_25 ;
F_16 ( & V_25 -> V_37 ) ;
if ( ! F_29 ( V_38 , & V_29 -> V_39 ) ) {
if ( F_30 ( & V_25 -> V_41 ) )
goto V_45;
V_44 = V_25 -> V_41 . V_46 ;
} else if ( F_41 ( & V_29 -> V_14 , & V_25 -> V_41 ) )
goto V_45;
else
V_44 = V_29 -> V_14 . V_46 ;
V_46 = F_39 ( V_44 , struct V_2 , V_14 ) ;
F_15 ( & V_46 -> V_9 ) ;
V_45:
F_19 ( & V_25 -> V_37 ) ;
return V_46 ;
}
static void F_42 (
struct V_2 * V_5 ,
int V_36 )
{
struct V_23 * V_25 ;
if ( ! V_5 )
return;
V_25 = V_5 -> V_7 -> V_24 -> V_25 ;
F_43 ( & V_5 -> V_13 ) ;
if ( V_5 -> V_47 )
F_28 ( V_25 , V_5 , V_36 ) ;
else
F_34 ( V_25 , V_5 ) ;
F_44 ( & V_5 -> V_13 ) ;
if ( F_45 ( & V_5 -> V_9 ) ) {
bool free = false ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_16 ( & V_7 -> V_30 ) ;
if ( F_46 ( & V_5 -> V_9 ) == 0 ) {
F_47 ( & V_7 -> V_31 ,
V_5 -> V_8 ) ;
free = true ;
}
F_19 ( & V_7 -> V_30 ) ;
if ( free )
F_25 ( V_1 , V_5 ) ;
}
}
static inline void F_48 ( struct V_2 * V_29 )
{
F_42 ( V_29 , 0 ) ;
}
static struct V_2 * F_49 (
struct V_23 * V_25 )
{
struct V_43 * V_44 ;
struct V_2 * V_29 = NULL ;
F_16 ( & V_25 -> V_37 ) ;
if ( F_30 ( & V_25 -> V_40 ) )
goto V_45;
V_44 = V_25 -> V_40 . V_46 ;
F_36 ( V_44 ) ;
V_29 = F_39 ( V_44 , struct V_2 , V_15 ) ;
F_15 ( & V_29 -> V_9 ) ;
V_45:
F_19 ( & V_25 -> V_37 ) ;
return V_29 ;
}
static inline void F_50 (
struct V_2 * V_29 )
{
F_42 ( V_29 , 1 ) ;
}
static struct V_16 * F_51 ( T_3 V_48 )
{
struct V_16 * V_49 ;
V_49 = F_52 ( sizeof( * V_49 ) + V_48 , V_34 ) ;
if ( V_49 ) {
V_49 -> V_48 = V_48 ;
V_49 -> V_50 = 0 ;
V_49 -> V_51 = 0 ;
V_49 -> V_5 = NULL ;
F_6 ( & V_49 -> V_9 , 1 ) ;
}
return V_49 ;
}
static struct V_16 * F_53 (
struct V_52 * V_7 ,
struct V_53 * V_19 ,
struct V_16 * * V_54 ,
struct V_16 * * V_46 )
{
struct V_55 * V_29 , * V_56 = NULL ;
struct V_16 * V_57 = NULL ;
int V_32 = 0 ;
V_29 = V_7 -> V_55 ;
while ( V_29 ) {
V_57 = F_54 ( V_29 , struct V_16 ,
V_55 ) ;
V_56 = V_29 ;
V_32 = F_55 ( & V_57 -> V_19 , V_19 ) ;
if ( V_32 < 0 )
V_29 = V_29 -> V_58 ;
else if ( V_32 > 0 )
V_29 = V_29 -> V_59 ;
else
return V_57 ;
}
if ( V_54 ) {
if ( ! V_56 )
* V_54 = NULL ;
else if ( V_32 < 0 )
* V_54 = V_57 ;
else if ( ( V_29 = F_56 ( V_56 ) ) != NULL ) {
* V_54 = F_54 ( V_29 , struct V_16 ,
V_55 ) ;
} else
* V_54 = NULL ;
}
if ( V_46 ) {
if ( ! V_56 )
* V_46 = NULL ;
else if ( V_32 > 0 )
* V_46 = V_57 ;
else if ( ( V_29 = F_57 ( V_56 ) ) != NULL ) {
* V_46 = F_54 ( V_29 , struct V_16 ,
V_55 ) ;
} else
* V_46 = NULL ;
}
return NULL ;
}
static struct V_16 * F_58 (
struct V_2 * V_5 ,
struct V_53 * V_19 )
{
struct V_16 * V_49 ;
V_49 = F_53 ( & V_5 -> V_10 , V_19 ,
NULL , NULL ) ;
return V_49 ;
}
static int F_59 ( struct V_2 * V_5 ,
struct V_16 * V_60 ,
int V_61 )
{
struct V_55 * * V_44 , * V_29 ;
struct V_55 * V_62 = NULL ;
struct V_52 * V_7 ;
struct V_16 * V_49 ;
int V_63 ;
if ( V_61 == V_64 )
V_7 = & V_5 -> V_10 ;
else if ( V_61 == V_65 )
V_7 = & V_5 -> V_12 ;
else
F_60 () ;
V_44 = & V_7 -> V_55 ;
V_29 = & V_60 -> V_55 ;
while ( * V_44 ) {
V_62 = * V_44 ;
V_49 = F_54 ( V_62 , struct V_16 ,
V_55 ) ;
V_63 = F_55 ( & V_49 -> V_19 , & V_60 -> V_19 ) ;
if ( V_63 < 0 )
V_44 = & ( * V_44 ) -> V_58 ;
else if ( V_63 > 0 )
V_44 = & ( * V_44 ) -> V_59 ;
else
return - V_35 ;
}
F_61 ( V_29 , V_62 , V_44 ) ;
F_62 ( V_29 , V_7 ) ;
V_60 -> V_5 = V_5 ;
V_60 -> V_50 = V_61 ;
if ( V_60 -> V_19 . type == V_20 &&
V_61 == V_64 &&
V_60 -> V_19 . V_22 >= V_5 -> V_66 )
V_5 -> V_66 = V_60 -> V_19 . V_22 + 1 ;
V_5 -> V_47 ++ ;
F_15 ( & V_5 -> V_7 -> V_24 -> V_25 -> V_67 ) ;
return 0 ;
}
static int F_63 ( struct V_2 * V_29 ,
struct V_16 * V_49 )
{
return F_59 ( V_29 , V_49 ,
V_64 ) ;
}
static int F_64 ( struct V_2 * V_29 ,
struct V_16 * V_49 )
{
return F_59 ( V_29 , V_49 ,
V_65 ) ;
}
static void F_65 ( struct V_23 * V_25 )
{
int V_68 = F_66 ( & V_25 -> V_69 ) ;
if ( ( F_67 ( & V_25 -> V_67 ) <
V_70 || V_68 % V_71 == 0 ) &&
F_68 ( & V_25 -> V_72 ) )
F_69 ( & V_25 -> V_72 ) ;
}
static void F_70 ( struct V_16 * V_57 )
{
struct V_52 * V_7 ;
struct V_23 * V_25 ;
V_25 = V_57 -> V_5 -> V_7 -> V_24 -> V_25 ;
F_18 ( ! V_25 ) ;
F_18 ( V_57 -> V_50 != V_65 &&
V_57 -> V_50 != V_64 ) ;
if ( V_57 -> V_50 == V_64 )
V_7 = & V_57 -> V_5 -> V_10 ;
else
V_7 = & V_57 -> V_5 -> V_12 ;
F_71 ( & V_57 -> V_55 , V_7 ) ;
V_57 -> V_5 -> V_47 -- ;
F_65 ( V_25 ) ;
}
static void F_72 ( struct V_16 * V_49 )
{
if ( V_49 ) {
F_70 ( V_49 ) ;
if ( F_45 ( & V_49 -> V_9 ) )
F_73 ( V_49 ) ;
}
}
static struct V_16 * F_74 (
struct V_2 * V_5 )
{
struct V_55 * V_44 ;
struct V_16 * V_49 = NULL ;
V_44 = F_75 ( & V_5 -> V_10 ) ;
if ( V_44 )
V_49 = F_54 ( V_44 , struct V_16 , V_55 ) ;
return V_49 ;
}
static struct V_16 * F_76 (
struct V_2 * V_5 )
{
struct V_55 * V_44 ;
struct V_16 * V_49 = NULL ;
V_44 = F_75 ( & V_5 -> V_12 ) ;
if ( V_44 )
V_49 = F_54 ( V_44 , struct V_16 , V_55 ) ;
return V_49 ;
}
static struct V_16 * F_77 (
struct V_16 * V_49 )
{
struct V_55 * V_44 ;
struct V_16 * V_46 = NULL ;
V_44 = F_57 ( & V_49 -> V_55 ) ;
if ( V_44 )
V_46 = F_54 ( V_44 , struct V_16 , V_55 ) ;
return V_46 ;
}
static int F_78 ( struct V_73 * V_74 ,
struct V_6 * V_7 ,
struct V_16 * V_49 )
{
struct V_75 * V_76 ;
struct V_75 * V_77 ;
T_2 V_78 ;
int V_32 ;
if ( ! V_74 -> V_51 )
return 0 ;
V_76 = V_74 -> V_79 ;
V_77 = & V_7 -> V_24 -> V_80 ;
V_78 = F_79 ( V_7 , 1 ) ;
V_32 = F_80 ( V_76 , V_77 , V_78 , 1 ) ;
if ( ! V_32 ) {
F_81 ( V_7 -> V_24 , L_2 ,
V_49 -> V_19 . V_21 ,
V_78 , 1 ) ;
V_49 -> V_51 = V_78 ;
}
return V_32 ;
}
static void F_82 ( struct V_6 * V_7 ,
struct V_16 * V_49 )
{
struct V_75 * V_81 ;
if ( ! V_49 -> V_51 )
return;
V_81 = & V_7 -> V_24 -> V_80 ;
F_81 ( V_7 -> V_24 , L_2 ,
V_49 -> V_19 . V_21 , V_49 -> V_51 ,
0 ) ;
F_83 ( V_7 , V_81 ,
V_49 -> V_51 ) ;
}
static int F_84 (
struct V_73 * V_74 ,
struct V_6 * V_7 ,
struct V_26 * V_26 ,
struct V_2 * V_29 )
{
struct V_75 * V_76 ;
struct V_75 * V_77 ;
T_2 V_78 ;
int V_32 ;
bool V_82 = false ;
V_76 = V_74 -> V_79 ;
V_77 = & V_7 -> V_24 -> V_80 ;
V_78 = F_79 ( V_7 , 1 ) ;
if ( V_76 && V_76 -> type == V_83 ) {
F_16 ( & F_12 ( V_26 ) -> V_37 ) ;
if ( F_85 ( V_84 ,
& F_12 ( V_26 ) -> V_85 ) )
V_82 = true ;
else
V_76 = NULL ;
F_19 ( & F_12 ( V_26 ) -> V_37 ) ;
}
if ( ! V_76 || ( ! V_74 -> V_51 &&
V_76 -> type != V_83 ) ) {
V_32 = F_86 ( V_7 , V_77 , V_78 ,
V_86 ) ;
if ( V_32 == - V_87 )
V_32 = - V_88 ;
if ( ! V_32 ) {
V_29 -> V_51 = V_78 ;
F_81 ( V_7 -> V_24 ,
L_3 ,
F_13 ( V_26 ) ,
V_78 , 1 ) ;
}
return V_32 ;
}
V_32 = F_80 ( V_76 , V_77 , V_78 , 1 ) ;
if ( ! V_32 ) {
F_81 ( V_7 -> V_24 , L_3 ,
F_13 ( V_26 ) , V_78 , 1 ) ;
V_29 -> V_51 = V_78 ;
}
if ( V_82 ) {
F_81 ( V_7 -> V_24 , L_4 ,
F_13 ( V_26 ) , V_78 , 0 ) ;
F_83 ( V_7 , V_76 , V_78 ) ;
}
return V_32 ;
}
static void F_87 ( struct V_6 * V_7 ,
struct V_2 * V_29 )
{
struct V_75 * V_81 ;
if ( ! V_29 -> V_51 )
return;
V_81 = & V_7 -> V_24 -> V_80 ;
F_81 ( V_7 -> V_24 , L_3 ,
V_29 -> V_8 , V_29 -> V_51 , 0 ) ;
F_83 ( V_7 , V_81 ,
V_29 -> V_51 ) ;
V_29 -> V_51 = 0 ;
}
static int F_88 ( struct V_6 * V_7 ,
struct V_89 * V_90 ,
struct V_16 * V_49 )
{
struct V_16 * V_91 , * V_46 ;
int V_92 ;
int V_93 = 0 , V_94 = 0 ;
struct V_95 * V_96 ;
char * V_97 ;
struct V_53 * V_98 ;
T_3 * V_99 ;
struct V_43 V_100 ;
int V_101 ;
int V_102 ;
int V_103 ;
int V_32 = 0 ;
F_18 ( ! V_90 -> V_42 [ 0 ] ) ;
V_96 = V_90 -> V_42 [ 0 ] ;
V_92 = F_89 ( V_7 , V_96 ) ;
F_8 ( & V_100 ) ;
V_46 = V_49 ;
V_102 = 0 ;
while ( V_94 + V_46 -> V_48 + sizeof( struct V_104 ) <=
V_92 ) {
V_93 += V_46 -> V_48 ;
V_94 += V_46 -> V_48 + sizeof( struct V_104 ) ;
F_32 ( & V_46 -> V_105 , & V_100 ) ;
V_102 ++ ;
V_91 = V_46 ;
V_46 = F_77 ( V_91 ) ;
if ( ! V_46 )
break;
if ( ! F_9 ( V_91 , V_46 ) )
break;
}
if ( ! V_102 ) {
V_32 = 0 ;
goto V_45;
}
F_90 ( V_90 ) ;
V_98 = F_91 ( V_102 , sizeof( struct V_53 ) , V_34 ) ;
if ( ! V_98 ) {
V_32 = - V_4 ;
goto V_45;
}
V_99 = F_91 ( V_102 , sizeof( T_3 ) , V_34 ) ;
if ( ! V_99 ) {
V_32 = - V_4 ;
goto error;
}
V_103 = 0 ;
F_92 (next, &head, tree_list) {
V_98 [ V_103 ] = V_46 -> V_19 ;
V_99 [ V_103 ] = V_46 -> V_48 ;
V_103 ++ ;
}
F_93 ( V_90 , NULL , 0 ) ;
F_94 ( V_7 , V_90 , V_98 , V_99 ,
V_93 , V_94 , V_102 ) ;
V_101 = V_90 -> V_106 [ 0 ] ;
F_95 (curr, next, &head, tree_list) {
V_97 = F_96 ( V_96 , V_101 , char ) ;
F_97 ( V_96 , & V_91 -> V_107 ,
( unsigned long ) V_97 ,
V_91 -> V_48 ) ;
V_101 ++ ;
F_82 ( V_7 , V_91 ) ;
F_98 ( & V_91 -> V_105 ) ;
F_72 ( V_91 ) ;
}
error:
F_73 ( V_99 ) ;
F_73 ( V_98 ) ;
V_45:
return V_32 ;
}
static int F_99 ( struct V_73 * V_74 ,
struct V_6 * V_7 ,
struct V_89 * V_90 ,
struct V_16 * V_57 )
{
struct V_95 * V_96 ;
char * V_108 ;
int V_32 ;
V_32 = F_100 ( V_74 , V_7 , V_90 , & V_57 -> V_19 ,
V_57 -> V_48 ) ;
if ( V_32 < 0 && V_32 != - V_35 )
return V_32 ;
V_96 = V_90 -> V_42 [ 0 ] ;
V_108 = F_96 ( V_96 , V_90 -> V_106 [ 0 ] , char ) ;
F_97 ( V_96 , V_57 -> V_107 , ( unsigned long ) V_108 ,
V_57 -> V_48 ) ;
F_101 ( V_96 ) ;
F_82 ( V_7 , V_57 ) ;
return 0 ;
}
static int F_102 ( struct V_73 * V_74 ,
struct V_89 * V_90 ,
struct V_6 * V_7 ,
struct V_2 * V_29 )
{
struct V_16 * V_91 , * V_54 ;
int V_32 = 0 ;
V_109:
F_43 ( & V_29 -> V_13 ) ;
V_91 = F_74 ( V_29 ) ;
if ( ! V_91 )
goto V_110;
V_32 = F_99 ( V_74 , V_7 , V_90 , V_91 ) ;
if ( V_32 < 0 ) {
F_103 ( V_90 ) ;
goto V_110;
}
V_54 = V_91 ;
V_91 = F_77 ( V_54 ) ;
if ( V_91 && F_9 ( V_54 , V_91 ) ) {
V_90 -> V_106 [ 0 ] ++ ;
F_88 ( V_7 , V_90 , V_91 ) ;
}
F_72 ( V_54 ) ;
F_101 ( V_90 -> V_42 [ 0 ] ) ;
F_103 ( V_90 ) ;
F_44 ( & V_29 -> V_13 ) ;
goto V_109;
V_110:
F_44 ( & V_29 -> V_13 ) ;
return V_32 ;
}
static int F_104 ( struct V_73 * V_74 ,
struct V_6 * V_7 ,
struct V_89 * V_90 ,
struct V_16 * V_49 )
{
struct V_16 * V_91 , * V_46 ;
struct V_95 * V_96 ;
struct V_53 V_19 ;
struct V_43 V_100 ;
int V_102 , V_103 , V_111 ;
int V_32 = 0 ;
F_18 ( ! V_90 -> V_42 [ 0 ] ) ;
V_96 = V_90 -> V_42 [ 0 ] ;
V_103 = V_90 -> V_106 [ 0 ] ;
V_111 = F_105 ( V_96 ) - 1 ;
if ( V_103 > V_111 )
return - V_112 ;
V_46 = V_49 ;
F_8 ( & V_100 ) ;
F_106 ( V_96 , & V_19 , V_103 ) ;
V_102 = 0 ;
while ( F_55 ( & V_46 -> V_19 , & V_19 ) == 0 ) {
F_32 ( & V_46 -> V_105 , & V_100 ) ;
V_102 ++ ;
V_91 = V_46 ;
V_46 = F_77 ( V_91 ) ;
if ( ! V_46 )
break;
if ( ! F_9 ( V_91 , V_46 ) )
break;
V_103 ++ ;
if ( V_103 > V_111 )
break;
F_106 ( V_96 , & V_19 , V_103 ) ;
}
if ( ! V_102 )
return 0 ;
V_32 = F_107 ( V_74 , V_7 , V_90 , V_90 -> V_106 [ 0 ] , V_102 ) ;
if ( V_32 )
goto V_45;
F_95 (curr, next, &head, tree_list) {
F_82 ( V_7 , V_91 ) ;
F_98 ( & V_91 -> V_105 ) ;
F_72 ( V_91 ) ;
}
V_45:
return V_32 ;
}
static int F_108 ( struct V_73 * V_74 ,
struct V_89 * V_90 ,
struct V_6 * V_7 ,
struct V_2 * V_29 )
{
struct V_16 * V_91 , * V_54 ;
int V_32 = 0 ;
V_109:
F_43 ( & V_29 -> V_13 ) ;
V_91 = F_76 ( V_29 ) ;
if ( ! V_91 )
goto V_113;
V_32 = F_109 ( V_74 , V_7 , & V_91 -> V_19 , V_90 , - 1 , 1 ) ;
if ( V_32 < 0 )
goto V_113;
else if ( V_32 > 0 ) {
V_54 = V_91 ;
V_91 = F_77 ( V_54 ) ;
F_72 ( V_54 ) ;
V_32 = 0 ;
F_103 ( V_90 ) ;
if ( V_91 ) {
F_44 ( & V_29 -> V_13 ) ;
goto V_109;
} else
goto V_113;
}
F_104 ( V_74 , V_7 , V_90 , V_91 ) ;
F_103 ( V_90 ) ;
F_44 ( & V_29 -> V_13 ) ;
goto V_109;
V_113:
F_103 ( V_90 ) ;
F_44 ( & V_29 -> V_13 ) ;
return V_32 ;
}
static void F_110 ( struct V_2 * V_5 )
{
struct V_23 * V_25 ;
if ( V_5 &&
F_29 ( V_114 , & V_5 -> V_39 ) ) {
F_18 ( ! V_5 -> V_7 ) ;
F_37 ( V_114 , & V_5 -> V_39 ) ;
V_5 -> V_47 -- ;
V_25 = V_5 -> V_7 -> V_24 -> V_25 ;
F_65 ( V_25 ) ;
}
}
static void F_111 ( struct V_2 * V_5 )
{
struct V_23 * V_25 ;
ASSERT ( V_5 -> V_7 ) ;
F_37 ( V_115 , & V_5 -> V_39 ) ;
V_5 -> V_47 -- ;
V_25 = V_5 -> V_7 -> V_24 -> V_25 ;
F_65 ( V_25 ) ;
}
static int F_112 ( struct V_73 * V_74 ,
struct V_6 * V_7 ,
struct V_89 * V_90 ,
struct V_2 * V_29 )
{
struct V_53 V_19 ;
struct V_116 * V_117 ;
struct V_95 * V_96 ;
int V_36 ;
int V_32 ;
V_19 . V_21 = V_29 -> V_8 ;
V_19 . type = V_118 ;
V_19 . V_22 = 0 ;
if ( F_29 ( V_115 , & V_29 -> V_39 ) )
V_36 = - 1 ;
else
V_36 = 1 ;
V_32 = F_113 ( V_74 , V_7 , V_90 , & V_19 , V_36 ) ;
if ( V_32 > 0 ) {
F_103 ( V_90 ) ;
return - V_112 ;
} else if ( V_32 < 0 ) {
return V_32 ;
}
V_96 = V_90 -> V_42 [ 0 ] ;
V_117 = F_96 ( V_96 , V_90 -> V_106 [ 0 ] ,
struct V_116 ) ;
F_97 ( V_96 , & V_29 -> V_117 , ( unsigned long ) V_117 ,
sizeof( struct V_116 ) ) ;
F_101 ( V_96 ) ;
if ( ! F_29 ( V_115 , & V_29 -> V_39 ) )
goto V_119;
V_90 -> V_106 [ 0 ] ++ ;
if ( V_90 -> V_106 [ 0 ] >= F_105 ( V_96 ) )
goto V_120;
V_33:
F_106 ( V_96 , & V_19 , V_90 -> V_106 [ 0 ] ) ;
if ( V_19 . V_21 != V_29 -> V_8 )
goto V_45;
if ( V_19 . type != V_121 &&
V_19 . type != V_122 )
goto V_45;
F_114 ( V_74 , V_7 , V_90 ) ;
V_45:
F_111 ( V_29 ) ;
V_119:
F_103 ( V_90 ) ;
V_123:
F_87 ( V_7 , V_29 ) ;
F_110 ( V_29 ) ;
return V_32 ;
V_120:
F_103 ( V_90 ) ;
V_19 . type = V_122 ;
V_19 . V_22 = - 1 ;
V_32 = F_109 ( V_74 , V_7 , & V_19 , V_90 , - 1 , 1 ) ;
if ( V_32 < 0 )
goto V_123;
ASSERT ( V_32 ) ;
V_32 = 0 ;
V_96 = V_90 -> V_42 [ 0 ] ;
V_90 -> V_106 [ 0 ] -- ;
goto V_33;
}
static inline int F_115 ( struct V_73 * V_74 ,
struct V_6 * V_7 ,
struct V_89 * V_90 ,
struct V_2 * V_29 )
{
int V_32 ;
F_43 ( & V_29 -> V_13 ) ;
if ( ! F_29 ( V_114 , & V_29 -> V_39 ) ) {
F_44 ( & V_29 -> V_13 ) ;
return 0 ;
}
V_32 = F_112 ( V_74 , V_7 , V_90 , V_29 ) ;
F_44 ( & V_29 -> V_13 ) ;
return V_32 ;
}
static inline int
F_116 ( struct V_73 * V_74 ,
struct V_89 * V_90 ,
struct V_2 * V_29 )
{
int V_32 ;
V_32 = F_102 ( V_74 , V_90 , V_29 -> V_7 , V_29 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_108 ( V_74 , V_90 , V_29 -> V_7 , V_29 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_115 ( V_74 , V_29 -> V_7 , V_90 , V_29 ) ;
return V_32 ;
}
static int F_117 ( struct V_73 * V_74 ,
struct V_6 * V_7 , int V_124 )
{
struct V_23 * V_25 ;
struct V_2 * V_125 , * V_56 ;
struct V_89 * V_90 ;
struct V_75 * V_79 ;
int V_32 = 0 ;
bool V_47 = ( V_124 > 0 ) ;
if ( V_74 -> V_126 )
return - V_127 ;
V_90 = F_118 () ;
if ( ! V_90 )
return - V_4 ;
V_90 -> V_128 = 1 ;
V_79 = V_74 -> V_79 ;
V_74 -> V_79 = & V_7 -> V_24 -> V_80 ;
V_25 = F_10 ( V_7 ) ;
V_125 = F_38 ( V_25 ) ;
while ( V_125 && ( ! V_47 || ( V_47 && V_124 -- ) ) ) {
V_32 = F_116 ( V_74 , V_90 ,
V_125 ) ;
if ( V_32 ) {
F_48 ( V_125 ) ;
V_125 = NULL ;
F_119 ( V_74 , V_32 ) ;
break;
}
V_56 = V_125 ;
V_125 = F_40 ( V_125 ) ;
F_48 ( V_56 ) ;
}
if ( V_125 )
F_48 ( V_125 ) ;
F_120 ( V_90 ) ;
V_74 -> V_79 = V_79 ;
return V_32 ;
}
int F_121 ( struct V_73 * V_74 ,
struct V_6 * V_7 )
{
return F_117 ( V_74 , V_7 , - 1 ) ;
}
int F_122 ( struct V_73 * V_74 ,
struct V_6 * V_7 , int V_124 )
{
return F_117 ( V_74 , V_7 , V_124 ) ;
}
int F_123 ( struct V_73 * V_74 ,
struct V_26 * V_26 )
{
struct V_2 * V_5 = F_11 ( V_26 ) ;
struct V_89 * V_90 ;
struct V_75 * V_79 ;
int V_32 ;
if ( ! V_5 )
return 0 ;
F_43 ( & V_5 -> V_13 ) ;
if ( ! V_5 -> V_47 ) {
F_44 ( & V_5 -> V_13 ) ;
F_48 ( V_5 ) ;
return 0 ;
}
F_44 ( & V_5 -> V_13 ) ;
V_90 = F_118 () ;
if ( ! V_90 ) {
F_48 ( V_5 ) ;
return - V_4 ;
}
V_90 -> V_128 = 1 ;
V_79 = V_74 -> V_79 ;
V_74 -> V_79 = & V_5 -> V_7 -> V_24 -> V_80 ;
V_32 = F_116 ( V_74 , V_90 , V_5 ) ;
F_48 ( V_5 ) ;
F_120 ( V_90 ) ;
V_74 -> V_79 = V_79 ;
return V_32 ;
}
int F_124 ( struct V_26 * V_26 )
{
struct V_73 * V_74 ;
struct V_2 * V_5 = F_11 ( V_26 ) ;
struct V_89 * V_90 ;
struct V_75 * V_79 ;
int V_32 ;
if ( ! V_5 )
return 0 ;
F_43 ( & V_5 -> V_13 ) ;
if ( ! F_29 ( V_114 , & V_5 -> V_39 ) ) {
F_44 ( & V_5 -> V_13 ) ;
F_48 ( V_5 ) ;
return 0 ;
}
F_44 ( & V_5 -> V_13 ) ;
V_74 = F_125 ( V_5 -> V_7 ) ;
if ( F_126 ( V_74 ) ) {
V_32 = F_127 ( V_74 ) ;
goto V_45;
}
V_90 = F_118 () ;
if ( ! V_90 ) {
V_32 = - V_4 ;
goto V_129;
}
V_90 -> V_128 = 1 ;
V_79 = V_74 -> V_79 ;
V_74 -> V_79 = & V_5 -> V_7 -> V_24 -> V_80 ;
F_43 ( & V_5 -> V_13 ) ;
if ( F_29 ( V_114 , & V_5 -> V_39 ) )
V_32 = F_112 ( V_74 , V_5 -> V_7 ,
V_90 , V_5 ) ;
else
V_32 = 0 ;
F_44 ( & V_5 -> V_13 ) ;
F_120 ( V_90 ) ;
V_74 -> V_79 = V_79 ;
V_129:
F_128 ( V_74 , V_5 -> V_7 ) ;
F_129 ( V_5 -> V_7 ) ;
V_45:
F_48 ( V_5 ) ;
return V_32 ;
}
void F_130 ( struct V_26 * V_26 )
{
struct V_2 * V_5 ;
V_5 = F_14 ( F_12 ( V_26 ) -> V_5 ) ;
if ( ! V_5 )
return;
F_12 ( V_26 ) -> V_5 = NULL ;
F_48 ( V_5 ) ;
}
static void F_131 ( struct V_130 * V_131 )
{
struct V_132 * V_133 ;
struct V_23 * V_25 ;
struct V_73 * V_74 ;
struct V_89 * V_90 ;
struct V_2 * V_5 = NULL ;
struct V_6 * V_7 ;
struct V_75 * V_79 ;
int V_134 = 0 ;
V_133 = F_132 ( V_131 , struct V_132 , V_131 ) ;
V_25 = V_133 -> V_25 ;
V_90 = F_118 () ;
if ( ! V_90 )
goto V_45;
V_33:
if ( F_46 ( & V_25 -> V_67 ) < V_70 / 2 )
goto V_135;
V_5 = F_49 ( V_25 ) ;
if ( ! V_5 )
goto V_135;
V_90 -> V_128 = 1 ;
V_7 = V_5 -> V_7 ;
V_74 = F_125 ( V_7 ) ;
if ( F_126 ( V_74 ) )
goto V_136;
V_79 = V_74 -> V_79 ;
V_74 -> V_79 = & V_7 -> V_24 -> V_80 ;
F_116 ( V_74 , V_90 , V_5 ) ;
V_74 -> V_79 = V_79 ;
F_128 ( V_74 , V_7 ) ;
F_133 ( V_7 ) ;
V_136:
F_103 ( V_90 ) ;
V_134 ++ ;
F_50 ( V_5 ) ;
if ( V_133 -> V_124 == 0 || V_134 < V_133 -> V_124 )
goto V_33;
V_135:
F_120 ( V_90 ) ;
V_45:
F_69 ( & V_25 -> V_72 ) ;
F_73 ( V_133 ) ;
}
static int F_134 ( struct V_23 * V_25 ,
struct V_137 * V_24 , int V_124 )
{
struct V_132 * V_133 ;
if ( F_46 ( & V_25 -> V_67 ) < V_70 )
return 0 ;
V_133 = F_52 ( sizeof( * V_133 ) , V_34 ) ;
if ( ! V_133 )
return - V_4 ;
V_133 -> V_25 = V_25 ;
F_135 ( & V_133 -> V_131 , V_138 ,
F_131 , NULL , NULL ) ;
V_133 -> V_124 = V_124 ;
F_136 ( V_24 -> V_139 , & V_133 -> V_131 ) ;
return 0 ;
}
void F_137 ( struct V_6 * V_7 )
{
struct V_23 * V_25 ;
V_25 = F_10 ( V_7 ) ;
F_138 ( F_38 ( V_25 ) ) ;
}
static int F_139 ( struct V_23 * V_25 , int V_68 )
{
int V_140 = F_46 ( & V_25 -> V_69 ) ;
if ( V_140 < V_68 || V_140 >= V_68 + V_71 )
return 1 ;
if ( F_46 ( & V_25 -> V_67 ) < V_70 )
return 1 ;
return 0 ;
}
void F_140 ( struct V_6 * V_7 )
{
struct V_23 * V_25 ;
struct V_137 * V_24 = V_7 -> V_24 ;
V_25 = F_10 ( V_7 ) ;
if ( F_46 ( & V_25 -> V_67 ) < V_70 )
return;
if ( F_46 ( & V_25 -> V_67 ) >= V_141 ) {
int V_68 ;
int V_32 ;
V_68 = F_46 ( & V_25 -> V_69 ) ;
V_32 = F_134 ( V_25 , V_24 , 0 ) ;
if ( V_32 )
return;
F_141 ( V_25 -> V_72 ,
F_139 ( V_25 , V_68 ) ) ;
return;
}
F_134 ( V_25 , V_24 , V_71 ) ;
}
int F_142 ( struct V_73 * V_74 ,
struct V_6 * V_7 , const char * V_142 ,
int V_143 , struct V_26 * V_144 ,
struct V_145 * V_146 , T_4 type ,
T_2 V_147 )
{
struct V_2 * V_5 ;
struct V_16 * V_57 ;
struct V_148 * V_149 ;
int V_32 ;
V_5 = F_21 ( V_144 ) ;
if ( F_126 ( V_5 ) )
return F_127 ( V_5 ) ;
V_57 = F_51 ( sizeof( * V_149 ) + V_143 ) ;
if ( ! V_57 ) {
V_32 = - V_4 ;
goto V_150;
}
V_57 -> V_19 . V_21 = F_13 ( V_144 ) ;
V_57 -> V_19 . type = V_20 ;
V_57 -> V_19 . V_22 = V_147 ;
V_149 = (struct V_148 * ) V_57 -> V_107 ;
V_149 -> V_151 = * V_146 ;
F_143 ( V_149 , V_74 -> V_152 ) ;
F_144 ( V_149 , 0 ) ;
F_145 ( V_149 , V_143 ) ;
F_146 ( V_149 , type ) ;
memcpy ( ( char * ) ( V_149 + 1 ) , V_142 , V_143 ) ;
V_32 = F_78 ( V_74 , V_7 , V_57 ) ;
F_18 ( V_32 ) ;
F_43 ( & V_5 -> V_13 ) ;
V_32 = F_63 ( V_5 , V_57 ) ;
if ( F_147 ( V_32 ) ) {
F_148 ( V_7 -> V_24 , L_5
L_6
L_7 ,
V_143 , V_142 , V_5 -> V_7 -> V_21 ,
V_5 -> V_8 , V_32 ) ;
F_60 () ;
}
F_44 ( & V_5 -> V_13 ) ;
V_150:
F_48 ( V_5 ) ;
return V_32 ;
}
static int F_149 ( struct V_6 * V_7 ,
struct V_2 * V_29 ,
struct V_53 * V_19 )
{
struct V_16 * V_49 ;
F_43 ( & V_29 -> V_13 ) ;
V_49 = F_58 ( V_29 , V_19 ) ;
if ( ! V_49 ) {
F_44 ( & V_29 -> V_13 ) ;
return 1 ;
}
F_82 ( V_7 , V_49 ) ;
F_72 ( V_49 ) ;
F_44 ( & V_29 -> V_13 ) ;
return 0 ;
}
int F_150 ( struct V_73 * V_74 ,
struct V_6 * V_7 , struct V_26 * V_144 ,
T_2 V_147 )
{
struct V_2 * V_29 ;
struct V_16 * V_49 ;
struct V_53 V_153 ;
int V_32 ;
V_29 = F_21 ( V_144 ) ;
if ( F_126 ( V_29 ) )
return F_127 ( V_29 ) ;
V_153 . V_21 = F_13 ( V_144 ) ;
V_153 . type = V_20 ;
V_153 . V_22 = V_147 ;
V_32 = F_149 ( V_7 , V_29 , & V_153 ) ;
if ( ! V_32 )
goto V_154;
V_49 = F_51 ( 0 ) ;
if ( ! V_49 ) {
V_32 = - V_4 ;
goto V_154;
}
V_49 -> V_19 = V_153 ;
V_32 = F_78 ( V_74 , V_7 , V_49 ) ;
F_18 ( V_32 ) ;
F_43 ( & V_29 -> V_13 ) ;
V_32 = F_64 ( V_29 , V_49 ) ;
if ( F_147 ( V_32 ) ) {
F_148 ( V_7 -> V_24 , L_8
L_9
L_7 ,
V_147 , V_29 -> V_7 -> V_21 , V_29 -> V_8 ,
V_32 ) ;
F_60 () ;
}
F_44 ( & V_29 -> V_13 ) ;
V_154:
F_48 ( V_29 ) ;
return V_32 ;
}
int F_151 ( struct V_26 * V_26 )
{
struct V_2 * V_5 = F_11 ( V_26 ) ;
if ( ! V_5 )
return - V_112 ;
if ( ! V_5 -> V_66 ) {
F_48 ( V_5 ) ;
return - V_155 ;
}
F_12 ( V_26 ) -> V_66 = V_5 -> V_66 ;
F_48 ( V_5 ) ;
return 0 ;
}
bool F_152 ( struct V_26 * V_26 ,
struct V_43 * V_156 ,
struct V_43 * V_157 )
{
struct V_2 * V_5 ;
struct V_16 * V_49 ;
V_5 = F_11 ( V_26 ) ;
if ( ! V_5 )
return false ;
F_153 ( V_26 ) ;
V_30 ( V_26 ) ;
F_43 ( & V_5 -> V_13 ) ;
V_49 = F_74 ( V_5 ) ;
while ( V_49 ) {
F_15 ( & V_49 -> V_9 ) ;
F_32 ( & V_49 -> V_158 , V_156 ) ;
V_49 = F_77 ( V_49 ) ;
}
V_49 = F_76 ( V_5 ) ;
while ( V_49 ) {
F_15 ( & V_49 -> V_9 ) ;
F_32 ( & V_49 -> V_158 , V_157 ) ;
V_49 = F_77 ( V_49 ) ;
}
F_44 ( & V_5 -> V_13 ) ;
F_35 ( & V_5 -> V_9 ) ;
return true ;
}
void F_154 ( struct V_26 * V_26 ,
struct V_43 * V_156 ,
struct V_43 * V_157 )
{
struct V_16 * V_91 , * V_46 ;
F_95 (curr, next, ins_list, readdir_list) {
F_98 ( & V_91 -> V_158 ) ;
if ( F_45 ( & V_91 -> V_9 ) )
F_73 ( V_91 ) ;
}
F_95 (curr, next, del_list, readdir_list) {
F_98 ( & V_91 -> V_158 ) ;
if ( F_45 ( & V_91 -> V_9 ) )
F_73 ( V_91 ) ;
}
F_155 ( & V_26 -> V_159 ) ;
}
int F_156 ( struct V_43 * V_157 ,
T_2 V_147 )
{
struct V_16 * V_91 , * V_46 ;
int V_32 ;
if ( F_30 ( V_157 ) )
return 0 ;
F_95 (curr, next, del_list, readdir_list) {
if ( V_91 -> V_19 . V_22 > V_147 )
break;
F_98 ( & V_91 -> V_158 ) ;
V_32 = ( V_91 -> V_19 . V_22 == V_147 ) ;
if ( F_45 ( & V_91 -> V_9 ) )
F_73 ( V_91 ) ;
if ( V_32 )
return 1 ;
else
continue;
}
return 0 ;
}
int F_157 ( struct V_160 * V_161 ,
struct V_43 * V_156 , bool * V_162 )
{
struct V_148 * V_163 ;
struct V_16 * V_91 , * V_46 ;
struct V_53 V_151 ;
char * V_142 ;
int V_143 ;
int V_164 = 0 ;
unsigned char V_165 ;
if ( F_30 ( V_156 ) )
return 0 ;
F_95 (curr, next, ins_list, readdir_list) {
F_98 ( & V_91 -> V_158 ) ;
if ( V_91 -> V_19 . V_22 < V_161 -> V_166 ) {
if ( F_45 ( & V_91 -> V_9 ) )
F_73 ( V_91 ) ;
continue;
}
V_161 -> V_166 = V_91 -> V_19 . V_22 ;
V_163 = (struct V_148 * ) V_91 -> V_107 ;
V_142 = ( char * ) ( V_163 + 1 ) ;
V_143 = F_158 ( V_163 ) ;
V_165 = V_167 [ V_163 -> type ] ;
F_159 ( & V_151 , & V_163 -> V_151 ) ;
V_164 = ! F_160 ( V_161 , V_142 , V_143 ,
V_151 . V_21 , V_165 ) ;
if ( F_45 ( & V_91 -> V_9 ) )
F_73 ( V_91 ) ;
if ( V_164 )
return 1 ;
* V_162 = true ;
}
return 0 ;
}
static void F_161 ( struct V_73 * V_74 ,
struct V_116 * V_117 ,
struct V_26 * V_26 )
{
F_162 ( V_117 , F_163 ( V_26 ) ) ;
F_164 ( V_117 , F_165 ( V_26 ) ) ;
F_166 ( V_117 , F_12 ( V_26 ) -> V_168 ) ;
F_167 ( V_117 , V_26 -> V_169 ) ;
F_168 ( V_117 , V_26 -> V_170 ) ;
F_169 ( V_117 , F_170 ( V_26 ) ) ;
F_171 ( V_117 ,
F_12 ( V_26 ) -> V_171 ) ;
F_172 ( V_117 , V_26 -> V_172 ) ;
F_173 ( V_117 , V_74 -> V_152 ) ;
F_174 ( V_117 , V_26 -> V_173 ) ;
F_175 ( V_117 , F_12 ( V_26 ) -> V_39 ) ;
F_176 ( V_117 , 0 ) ;
F_177 ( & V_117 -> V_174 ,
V_26 -> V_175 . V_176 ) ;
F_178 ( & V_117 -> V_174 ,
V_26 -> V_175 . V_177 ) ;
F_177 ( & V_117 -> V_178 ,
V_26 -> V_179 . V_176 ) ;
F_178 ( & V_117 -> V_178 ,
V_26 -> V_179 . V_177 ) ;
F_177 ( & V_117 -> ctime ,
V_26 -> V_180 . V_176 ) ;
F_178 ( & V_117 -> ctime ,
V_26 -> V_180 . V_177 ) ;
F_177 ( & V_117 -> V_181 ,
F_12 ( V_26 ) -> V_182 . V_176 ) ;
F_178 ( & V_117 -> V_181 ,
F_12 ( V_26 ) -> V_182 . V_177 ) ;
}
int F_179 ( struct V_26 * V_26 , T_3 * V_183 )
{
struct V_2 * V_5 ;
struct V_116 * V_117 ;
V_5 = F_11 ( V_26 ) ;
if ( ! V_5 )
return - V_112 ;
F_43 ( & V_5 -> V_13 ) ;
if ( ! F_29 ( V_114 , & V_5 -> V_39 ) ) {
F_44 ( & V_5 -> V_13 ) ;
F_48 ( V_5 ) ;
return - V_112 ;
}
V_117 = & V_5 -> V_117 ;
F_180 ( V_26 , F_181 ( V_117 ) ) ;
F_182 ( V_26 , F_183 ( V_117 ) ) ;
F_184 ( V_26 , F_185 ( V_117 ) ) ;
V_26 -> V_169 = F_186 ( V_117 ) ;
F_187 ( V_26 , F_188 ( V_117 ) ) ;
F_189 ( V_26 , F_190 ( V_117 ) ) ;
F_12 ( V_26 ) -> V_171 = F_191 ( V_117 ) ;
F_12 ( V_26 ) -> V_184 = F_192 ( V_117 ) ;
V_26 -> V_172 = F_193 ( V_117 ) ;
V_26 -> V_173 = 0 ;
* V_183 = F_194 ( V_117 ) ;
F_12 ( V_26 ) -> V_39 = F_195 ( V_117 ) ;
V_26 -> V_175 . V_176 = F_196 ( & V_117 -> V_174 ) ;
V_26 -> V_175 . V_177 = F_197 ( & V_117 -> V_174 ) ;
V_26 -> V_179 . V_176 = F_196 ( & V_117 -> V_178 ) ;
V_26 -> V_179 . V_177 = F_197 ( & V_117 -> V_178 ) ;
V_26 -> V_180 . V_176 = F_196 ( & V_117 -> ctime ) ;
V_26 -> V_180 . V_177 = F_197 ( & V_117 -> ctime ) ;
F_12 ( V_26 ) -> V_182 . V_176 =
F_196 ( & V_117 -> V_181 ) ;
F_12 ( V_26 ) -> V_182 . V_177 =
F_197 ( & V_117 -> V_181 ) ;
V_26 -> V_185 = F_12 ( V_26 ) -> V_171 ;
F_12 ( V_26 ) -> V_66 = ( T_2 ) - 1 ;
F_44 ( & V_5 -> V_13 ) ;
F_48 ( V_5 ) ;
return 0 ;
}
int F_198 ( struct V_73 * V_74 ,
struct V_6 * V_7 , struct V_26 * V_26 )
{
struct V_2 * V_5 ;
int V_32 = 0 ;
V_5 = F_21 ( V_26 ) ;
if ( F_126 ( V_5 ) )
return F_127 ( V_5 ) ;
F_43 ( & V_5 -> V_13 ) ;
if ( F_29 ( V_114 , & V_5 -> V_39 ) ) {
F_161 ( V_74 , & V_5 -> V_117 , V_26 ) ;
goto V_150;
}
V_32 = F_84 ( V_74 , V_7 , V_26 ,
V_5 ) ;
if ( V_32 )
goto V_150;
F_161 ( V_74 , & V_5 -> V_117 , V_26 ) ;
F_33 ( V_114 , & V_5 -> V_39 ) ;
V_5 -> V_47 ++ ;
F_15 ( & V_7 -> V_24 -> V_25 -> V_67 ) ;
V_150:
F_44 ( & V_5 -> V_13 ) ;
F_48 ( V_5 ) ;
return V_32 ;
}
int F_199 ( struct V_26 * V_26 )
{
struct V_2 * V_5 ;
if ( F_12 ( V_26 ) -> V_7 -> V_24 -> V_186 )
return - V_87 ;
V_5 = F_21 ( V_26 ) ;
if ( F_126 ( V_5 ) )
return F_127 ( V_5 ) ;
F_43 ( & V_5 -> V_13 ) ;
if ( F_29 ( V_115 , & V_5 -> V_39 ) )
goto V_150;
F_33 ( V_115 , & V_5 -> V_39 ) ;
V_5 -> V_47 ++ ;
F_15 ( & F_12 ( V_26 ) -> V_7 -> V_24 -> V_25 -> V_67 ) ;
V_150:
F_44 ( & V_5 -> V_13 ) ;
F_48 ( V_5 ) ;
return 0 ;
}
static void F_200 ( struct V_2 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_16 * V_187 , * V_188 ;
F_43 ( & V_5 -> V_13 ) ;
V_187 = F_74 ( V_5 ) ;
while ( V_187 ) {
F_82 ( V_7 , V_187 ) ;
V_188 = V_187 ;
V_187 = F_77 ( V_188 ) ;
F_72 ( V_188 ) ;
}
V_187 = F_76 ( V_5 ) ;
while ( V_187 ) {
F_82 ( V_7 , V_187 ) ;
V_188 = V_187 ;
V_187 = F_77 ( V_188 ) ;
F_72 ( V_188 ) ;
}
if ( F_29 ( V_115 , & V_5 -> V_39 ) )
F_111 ( V_5 ) ;
if ( F_29 ( V_114 , & V_5 -> V_39 ) ) {
F_87 ( V_7 , V_5 ) ;
F_110 ( V_5 ) ;
}
F_44 ( & V_5 -> V_13 ) ;
}
void F_201 ( struct V_26 * V_26 )
{
struct V_2 * V_5 ;
V_5 = F_11 ( V_26 ) ;
if ( ! V_5 )
return;
F_200 ( V_5 ) ;
F_48 ( V_5 ) ;
}
void F_202 ( struct V_6 * V_7 )
{
T_2 V_8 = 0 ;
struct V_2 * V_189 [ 8 ] ;
int V_103 , V_190 ;
while ( 1 ) {
F_16 ( & V_7 -> V_30 ) ;
V_190 = F_203 ( & V_7 -> V_31 ,
( void * * ) V_189 , V_8 ,
F_204 ( V_189 ) ) ;
if ( ! V_190 ) {
F_19 ( & V_7 -> V_30 ) ;
break;
}
V_8 = V_189 [ V_190 - 1 ] -> V_8 + 1 ;
for ( V_103 = 0 ; V_103 < V_190 ; V_103 ++ )
F_15 ( & V_189 [ V_103 ] -> V_9 ) ;
F_19 ( & V_7 -> V_30 ) ;
for ( V_103 = 0 ; V_103 < V_190 ; V_103 ++ ) {
F_200 ( V_189 [ V_103 ] ) ;
F_48 ( V_189 [ V_103 ] ) ;
}
}
}
void F_205 ( struct V_6 * V_7 )
{
struct V_23 * V_25 ;
struct V_2 * V_125 , * V_56 ;
V_25 = F_10 ( V_7 ) ;
V_125 = F_38 ( V_25 ) ;
while ( V_125 ) {
F_200 ( V_125 ) ;
V_56 = V_125 ;
V_125 = F_40 ( V_125 ) ;
F_48 ( V_56 ) ;
}
}
