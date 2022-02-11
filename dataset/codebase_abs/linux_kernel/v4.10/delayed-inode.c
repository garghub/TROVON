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
static struct V_2 * F_10 ( struct V_23 * V_23 )
{
struct V_24 * V_24 = F_11 ( V_23 ) ;
struct V_6 * V_7 = V_24 -> V_7 ;
T_2 V_25 = F_12 ( V_23 ) ;
struct V_2 * V_26 ;
V_26 = F_13 ( V_24 -> V_5 ) ;
if ( V_26 ) {
F_14 ( & V_26 -> V_9 ) ;
return V_26 ;
}
F_15 ( & V_7 -> V_27 ) ;
V_26 = F_16 ( & V_7 -> V_28 , V_25 ) ;
if ( V_26 ) {
if ( V_24 -> V_5 ) {
F_14 ( & V_26 -> V_9 ) ;
F_17 ( V_24 -> V_5 != V_26 ) ;
F_18 ( & V_7 -> V_27 ) ;
return V_26 ;
}
V_24 -> V_5 = V_26 ;
F_19 ( 2 , & V_26 -> V_9 ) ;
F_18 ( & V_7 -> V_27 ) ;
return V_26 ;
}
F_18 ( & V_7 -> V_27 ) ;
return NULL ;
}
static struct V_2 * F_20 (
struct V_23 * V_23 )
{
struct V_2 * V_26 ;
struct V_24 * V_24 = F_11 ( V_23 ) ;
struct V_6 * V_7 = V_24 -> V_7 ;
T_2 V_25 = F_12 ( V_23 ) ;
int V_29 ;
V_30:
V_26 = F_10 ( V_23 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_21 ( V_1 , V_31 ) ;
if ( ! V_26 )
return F_22 ( - V_4 ) ;
F_5 ( V_26 , V_7 , V_25 ) ;
F_19 ( 2 , & V_26 -> V_9 ) ;
V_29 = F_23 ( V_31 ) ;
if ( V_29 ) {
F_24 ( V_1 , V_26 ) ;
return F_22 ( V_29 ) ;
}
F_15 ( & V_7 -> V_27 ) ;
V_29 = F_25 ( & V_7 -> V_28 , V_25 , V_26 ) ;
if ( V_29 == - V_32 ) {
F_18 ( & V_7 -> V_27 ) ;
F_24 ( V_1 , V_26 ) ;
F_26 () ;
goto V_30;
}
V_24 -> V_5 = V_26 ;
F_18 ( & V_7 -> V_27 ) ;
F_26 () ;
return V_26 ;
}
static void F_27 ( struct V_33 * V_7 ,
struct V_2 * V_26 ,
int V_34 )
{
F_15 ( & V_7 -> V_35 ) ;
if ( F_28 ( V_36 , & V_26 -> V_37 ) ) {
if ( ! F_29 ( & V_26 -> V_15 ) )
F_30 ( & V_26 -> V_15 , & V_7 -> V_38 ) ;
else if ( V_34 )
F_31 ( & V_26 -> V_15 , & V_7 -> V_38 ) ;
} else {
F_31 ( & V_26 -> V_14 , & V_7 -> V_39 ) ;
F_31 ( & V_26 -> V_15 , & V_7 -> V_38 ) ;
F_14 ( & V_26 -> V_9 ) ;
V_7 -> V_40 ++ ;
F_32 ( V_36 , & V_26 -> V_37 ) ;
}
F_18 ( & V_7 -> V_35 ) ;
}
static void F_33 ( struct V_33 * V_7 ,
struct V_2 * V_26 )
{
F_15 ( & V_7 -> V_35 ) ;
if ( F_28 ( V_36 , & V_26 -> V_37 ) ) {
V_7 -> V_40 -- ;
F_34 ( & V_26 -> V_9 ) ;
F_35 ( & V_26 -> V_14 ) ;
if ( ! F_29 ( & V_26 -> V_15 ) )
F_35 ( & V_26 -> V_15 ) ;
F_36 ( V_36 , & V_26 -> V_37 ) ;
}
F_18 ( & V_7 -> V_35 ) ;
}
static struct V_2 * F_37 (
struct V_33 * V_41 )
{
struct V_42 * V_43 ;
struct V_2 * V_26 = NULL ;
F_15 ( & V_41 -> V_35 ) ;
if ( F_29 ( & V_41 -> V_39 ) )
goto V_44;
V_43 = V_41 -> V_39 . V_45 ;
V_26 = F_38 ( V_43 , struct V_2 , V_14 ) ;
F_14 ( & V_26 -> V_9 ) ;
V_44:
F_18 ( & V_41 -> V_35 ) ;
return V_26 ;
}
static struct V_2 * F_39 (
struct V_2 * V_26 )
{
struct V_33 * V_41 ;
struct V_42 * V_43 ;
struct V_2 * V_45 = NULL ;
V_41 = V_26 -> V_7 -> V_46 -> V_41 ;
F_15 ( & V_41 -> V_35 ) ;
if ( ! F_28 ( V_36 , & V_26 -> V_37 ) ) {
if ( F_29 ( & V_41 -> V_39 ) )
goto V_44;
V_43 = V_41 -> V_39 . V_45 ;
} else if ( F_40 ( & V_26 -> V_14 , & V_41 -> V_39 ) )
goto V_44;
else
V_43 = V_26 -> V_14 . V_45 ;
V_45 = F_38 ( V_43 , struct V_2 , V_14 ) ;
F_14 ( & V_45 -> V_9 ) ;
V_44:
F_18 ( & V_41 -> V_35 ) ;
return V_45 ;
}
static void F_41 (
struct V_2 * V_5 ,
int V_34 )
{
struct V_33 * V_41 ;
if ( ! V_5 )
return;
V_41 = V_5 -> V_7 -> V_46 -> V_41 ;
F_42 ( & V_5 -> V_13 ) ;
if ( V_5 -> V_47 )
F_27 ( V_41 , V_5 , V_34 ) ;
else
F_33 ( V_41 , V_5 ) ;
F_43 ( & V_5 -> V_13 ) ;
if ( F_44 ( & V_5 -> V_9 ) ) {
bool free = false ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_15 ( & V_7 -> V_27 ) ;
if ( F_45 ( & V_5 -> V_9 ) == 0 ) {
F_46 ( & V_7 -> V_28 ,
V_5 -> V_8 ) ;
free = true ;
}
F_18 ( & V_7 -> V_27 ) ;
if ( free )
F_24 ( V_1 , V_5 ) ;
}
}
static inline void F_47 ( struct V_2 * V_26 )
{
F_41 ( V_26 , 0 ) ;
}
static struct V_2 * F_48 (
struct V_33 * V_41 )
{
struct V_42 * V_43 ;
struct V_2 * V_26 = NULL ;
F_15 ( & V_41 -> V_35 ) ;
if ( F_29 ( & V_41 -> V_38 ) )
goto V_44;
V_43 = V_41 -> V_38 . V_45 ;
F_35 ( V_43 ) ;
V_26 = F_38 ( V_43 , struct V_2 , V_15 ) ;
F_14 ( & V_26 -> V_9 ) ;
V_44:
F_18 ( & V_41 -> V_35 ) ;
return V_26 ;
}
static inline void F_49 (
struct V_2 * V_26 )
{
F_41 ( V_26 , 1 ) ;
}
static struct V_16 * F_50 ( T_3 V_48 )
{
struct V_16 * V_49 ;
V_49 = F_51 ( sizeof( * V_49 ) + V_48 , V_31 ) ;
if ( V_49 ) {
V_49 -> V_48 = V_48 ;
V_49 -> V_50 = 0 ;
V_49 -> V_51 = 0 ;
V_49 -> V_5 = NULL ;
F_6 ( & V_49 -> V_9 , 1 ) ;
}
return V_49 ;
}
static struct V_16 * F_52 (
struct V_52 * V_7 ,
struct V_53 * V_19 ,
struct V_16 * * V_54 ,
struct V_16 * * V_45 )
{
struct V_55 * V_26 , * V_56 = NULL ;
struct V_16 * V_57 = NULL ;
int V_29 = 0 ;
V_26 = V_7 -> V_55 ;
while ( V_26 ) {
V_57 = F_53 ( V_26 , struct V_16 ,
V_55 ) ;
V_56 = V_26 ;
V_29 = F_54 ( & V_57 -> V_19 , V_19 ) ;
if ( V_29 < 0 )
V_26 = V_26 -> V_58 ;
else if ( V_29 > 0 )
V_26 = V_26 -> V_59 ;
else
return V_57 ;
}
if ( V_54 ) {
if ( ! V_56 )
* V_54 = NULL ;
else if ( V_29 < 0 )
* V_54 = V_57 ;
else if ( ( V_26 = F_55 ( V_56 ) ) != NULL ) {
* V_54 = F_53 ( V_26 , struct V_16 ,
V_55 ) ;
} else
* V_54 = NULL ;
}
if ( V_45 ) {
if ( ! V_56 )
* V_45 = NULL ;
else if ( V_29 > 0 )
* V_45 = V_57 ;
else if ( ( V_26 = F_56 ( V_56 ) ) != NULL ) {
* V_45 = F_53 ( V_26 , struct V_16 ,
V_55 ) ;
} else
* V_45 = NULL ;
}
return NULL ;
}
static struct V_16 * F_57 (
struct V_2 * V_5 ,
struct V_53 * V_19 )
{
return F_52 ( & V_5 -> V_10 , V_19 ,
NULL , NULL ) ;
}
static int F_58 ( struct V_2 * V_5 ,
struct V_16 * V_60 ,
int V_61 )
{
struct V_55 * * V_43 , * V_26 ;
struct V_55 * V_62 = NULL ;
struct V_52 * V_7 ;
struct V_16 * V_49 ;
int V_63 ;
if ( V_61 == V_64 )
V_7 = & V_5 -> V_10 ;
else if ( V_61 == V_65 )
V_7 = & V_5 -> V_12 ;
else
F_59 () ;
V_43 = & V_7 -> V_55 ;
V_26 = & V_60 -> V_55 ;
while ( * V_43 ) {
V_62 = * V_43 ;
V_49 = F_53 ( V_62 , struct V_16 ,
V_55 ) ;
V_63 = F_54 ( & V_49 -> V_19 , & V_60 -> V_19 ) ;
if ( V_63 < 0 )
V_43 = & ( * V_43 ) -> V_58 ;
else if ( V_63 > 0 )
V_43 = & ( * V_43 ) -> V_59 ;
else
return - V_32 ;
}
F_60 ( V_26 , V_62 , V_43 ) ;
F_61 ( V_26 , V_7 ) ;
V_60 -> V_5 = V_5 ;
V_60 -> V_50 = V_61 ;
if ( V_60 -> V_19 . type == V_20 &&
V_61 == V_64 &&
V_60 -> V_19 . V_22 >= V_5 -> V_66 )
V_5 -> V_66 = V_60 -> V_19 . V_22 + 1 ;
V_5 -> V_47 ++ ;
F_14 ( & V_5 -> V_7 -> V_46 -> V_41 -> V_67 ) ;
return 0 ;
}
static int F_62 ( struct V_2 * V_26 ,
struct V_16 * V_49 )
{
return F_58 ( V_26 , V_49 ,
V_64 ) ;
}
static int F_63 ( struct V_2 * V_26 ,
struct V_16 * V_49 )
{
return F_58 ( V_26 , V_49 ,
V_65 ) ;
}
static void F_64 ( struct V_33 * V_41 )
{
int V_68 = F_65 ( & V_41 -> V_69 ) ;
if ( ( F_66 ( & V_41 -> V_67 ) <
V_70 || V_68 % V_71 == 0 ) &&
F_67 ( & V_41 -> V_72 ) )
F_68 ( & V_41 -> V_72 ) ;
}
static void F_69 ( struct V_16 * V_57 )
{
struct V_52 * V_7 ;
struct V_33 * V_41 ;
V_41 = V_57 -> V_5 -> V_7 -> V_46 -> V_41 ;
F_17 ( ! V_41 ) ;
F_17 ( V_57 -> V_50 != V_65 &&
V_57 -> V_50 != V_64 ) ;
if ( V_57 -> V_50 == V_64 )
V_7 = & V_57 -> V_5 -> V_10 ;
else
V_7 = & V_57 -> V_5 -> V_12 ;
F_70 ( & V_57 -> V_55 , V_7 ) ;
V_57 -> V_5 -> V_47 -- ;
F_64 ( V_41 ) ;
}
static void F_71 ( struct V_16 * V_49 )
{
if ( V_49 ) {
F_69 ( V_49 ) ;
if ( F_44 ( & V_49 -> V_9 ) )
F_72 ( V_49 ) ;
}
}
static struct V_16 * F_73 (
struct V_2 * V_5 )
{
struct V_55 * V_43 ;
struct V_16 * V_49 = NULL ;
V_43 = F_74 ( & V_5 -> V_10 ) ;
if ( V_43 )
V_49 = F_53 ( V_43 , struct V_16 , V_55 ) ;
return V_49 ;
}
static struct V_16 * F_75 (
struct V_2 * V_5 )
{
struct V_55 * V_43 ;
struct V_16 * V_49 = NULL ;
V_43 = F_74 ( & V_5 -> V_12 ) ;
if ( V_43 )
V_49 = F_53 ( V_43 , struct V_16 , V_55 ) ;
return V_49 ;
}
static struct V_16 * F_76 (
struct V_16 * V_49 )
{
struct V_55 * V_43 ;
struct V_16 * V_45 = NULL ;
V_43 = F_56 ( & V_49 -> V_55 ) ;
if ( V_43 )
V_45 = F_53 ( V_43 , struct V_16 , V_55 ) ;
return V_45 ;
}
static int F_77 ( struct V_73 * V_74 ,
struct V_75 * V_46 ,
struct V_16 * V_49 )
{
struct V_76 * V_77 ;
struct V_76 * V_78 ;
T_2 V_79 ;
int V_29 ;
if ( ! V_74 -> V_51 )
return 0 ;
V_77 = V_74 -> V_80 ;
V_78 = & V_46 -> V_81 ;
V_79 = F_78 ( V_46 , 1 ) ;
V_29 = F_79 ( V_77 , V_78 , V_79 , 1 ) ;
if ( ! V_29 ) {
F_80 ( V_46 , L_2 ,
V_49 -> V_19 . V_21 ,
V_79 , 1 ) ;
V_49 -> V_51 = V_79 ;
}
return V_29 ;
}
static void F_81 ( struct V_75 * V_46 ,
struct V_16 * V_49 )
{
struct V_76 * V_82 ;
if ( ! V_49 -> V_51 )
return;
V_82 = & V_46 -> V_81 ;
F_80 ( V_46 , L_2 ,
V_49 -> V_19 . V_21 , V_49 -> V_51 ,
0 ) ;
F_82 ( V_46 , V_82 ,
V_49 -> V_51 ) ;
}
static int F_83 (
struct V_73 * V_74 ,
struct V_6 * V_7 ,
struct V_23 * V_23 ,
struct V_2 * V_26 )
{
struct V_75 * V_46 = V_7 -> V_46 ;
struct V_76 * V_77 ;
struct V_76 * V_78 ;
T_2 V_79 ;
int V_29 ;
bool V_83 = false ;
V_77 = V_74 -> V_80 ;
V_78 = & V_46 -> V_81 ;
V_79 = F_78 ( V_46 , 1 ) ;
if ( V_77 && V_77 -> type == V_84 ) {
F_15 ( & F_11 ( V_23 ) -> V_35 ) ;
if ( F_84 ( V_85 ,
& F_11 ( V_23 ) -> V_86 ) )
V_83 = true ;
else
V_77 = NULL ;
F_18 ( & F_11 ( V_23 ) -> V_35 ) ;
}
if ( ! V_77 || ( ! V_74 -> V_51 &&
V_77 -> type != V_84 ) ) {
V_29 = F_85 ( V_7 , V_78 , V_79 ,
V_87 ) ;
if ( V_29 == - V_88 )
V_29 = - V_89 ;
if ( ! V_29 ) {
V_26 -> V_51 = V_79 ;
F_80 ( V_46 ,
L_3 ,
F_12 ( V_23 ) ,
V_79 , 1 ) ;
}
return V_29 ;
}
V_29 = F_79 ( V_77 , V_78 , V_79 , 1 ) ;
if ( ! V_29 ) {
F_80 ( V_46 , L_3 ,
F_12 ( V_23 ) , V_79 , 1 ) ;
V_26 -> V_51 = V_79 ;
}
if ( V_83 ) {
F_80 ( V_46 , L_4 ,
F_12 ( V_23 ) , V_79 , 0 ) ;
F_82 ( V_46 , V_77 , V_79 ) ;
}
return V_29 ;
}
static void F_86 ( struct V_75 * V_46 ,
struct V_2 * V_26 )
{
struct V_76 * V_82 ;
if ( ! V_26 -> V_51 )
return;
V_82 = & V_46 -> V_81 ;
F_80 ( V_46 , L_3 ,
V_26 -> V_8 , V_26 -> V_51 , 0 ) ;
F_82 ( V_46 , V_82 ,
V_26 -> V_51 ) ;
V_26 -> V_51 = 0 ;
}
static int F_87 ( struct V_6 * V_7 ,
struct V_90 * V_91 ,
struct V_16 * V_49 )
{
struct V_75 * V_46 = V_7 -> V_46 ;
struct V_16 * V_92 , * V_45 ;
int V_93 ;
int V_94 = 0 , V_95 = 0 ;
struct V_96 * V_97 ;
char * V_98 ;
struct V_53 * V_99 ;
T_3 * V_100 ;
struct V_42 V_101 ;
int V_102 ;
int V_103 ;
int V_104 ;
int V_29 = 0 ;
F_17 ( ! V_91 -> V_40 [ 0 ] ) ;
V_97 = V_91 -> V_40 [ 0 ] ;
V_93 = F_88 ( V_46 , V_97 ) ;
F_8 ( & V_101 ) ;
V_45 = V_49 ;
V_103 = 0 ;
while ( V_95 + V_45 -> V_48 + sizeof( struct V_105 ) <=
V_93 ) {
V_94 += V_45 -> V_48 ;
V_95 += V_45 -> V_48 + sizeof( struct V_105 ) ;
F_31 ( & V_45 -> V_106 , & V_101 ) ;
V_103 ++ ;
V_92 = V_45 ;
V_45 = F_76 ( V_92 ) ;
if ( ! V_45 )
break;
if ( ! F_9 ( V_92 , V_45 ) )
break;
}
if ( ! V_103 ) {
V_29 = 0 ;
goto V_44;
}
F_89 ( V_91 ) ;
V_99 = F_90 ( V_103 , sizeof( struct V_53 ) , V_31 ) ;
if ( ! V_99 ) {
V_29 = - V_4 ;
goto V_44;
}
V_100 = F_90 ( V_103 , sizeof( T_3 ) , V_31 ) ;
if ( ! V_100 ) {
V_29 = - V_4 ;
goto error;
}
V_104 = 0 ;
F_91 (next, &head, tree_list) {
V_99 [ V_104 ] = V_45 -> V_19 ;
V_100 [ V_104 ] = V_45 -> V_48 ;
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
V_92 -> V_48 ) ;
V_102 ++ ;
F_81 ( V_46 , V_92 ) ;
F_97 ( & V_92 -> V_106 ) ;
F_71 ( V_92 ) ;
}
error:
F_72 ( V_100 ) ;
F_72 ( V_99 ) ;
V_44:
return V_29 ;
}
static int F_98 ( struct V_73 * V_74 ,
struct V_6 * V_7 ,
struct V_90 * V_91 ,
struct V_16 * V_57 )
{
struct V_75 * V_46 = V_7 -> V_46 ;
struct V_96 * V_97 ;
char * V_109 ;
int V_29 ;
V_29 = F_99 ( V_74 , V_7 , V_91 , & V_57 -> V_19 ,
V_57 -> V_48 ) ;
if ( V_29 < 0 && V_29 != - V_32 )
return V_29 ;
V_97 = V_91 -> V_40 [ 0 ] ;
V_109 = F_95 ( V_97 , V_91 -> V_107 [ 0 ] , char ) ;
F_96 ( V_97 , V_57 -> V_108 , ( unsigned long ) V_109 ,
V_57 -> V_48 ) ;
F_100 ( V_97 ) ;
F_81 ( V_46 , V_57 ) ;
return 0 ;
}
static int F_101 ( struct V_73 * V_74 ,
struct V_90 * V_91 ,
struct V_6 * V_7 ,
struct V_2 * V_26 )
{
struct V_16 * V_92 , * V_54 ;
int V_29 = 0 ;
V_110:
F_42 ( & V_26 -> V_13 ) ;
V_92 = F_73 ( V_26 ) ;
if ( ! V_92 )
goto V_111;
V_29 = F_98 ( V_74 , V_7 , V_91 , V_92 ) ;
if ( V_29 < 0 ) {
F_102 ( V_91 ) ;
goto V_111;
}
V_54 = V_92 ;
V_92 = F_76 ( V_54 ) ;
if ( V_92 && F_9 ( V_54 , V_92 ) ) {
V_91 -> V_107 [ 0 ] ++ ;
F_87 ( V_7 , V_91 , V_92 ) ;
}
F_71 ( V_54 ) ;
F_100 ( V_91 -> V_40 [ 0 ] ) ;
F_102 ( V_91 ) ;
F_43 ( & V_26 -> V_13 ) ;
goto V_110;
V_111:
F_43 ( & V_26 -> V_13 ) ;
return V_29 ;
}
static int F_103 ( struct V_73 * V_74 ,
struct V_6 * V_7 ,
struct V_90 * V_91 ,
struct V_16 * V_49 )
{
struct V_75 * V_46 = V_7 -> V_46 ;
struct V_16 * V_92 , * V_45 ;
struct V_96 * V_97 ;
struct V_53 V_19 ;
struct V_42 V_101 ;
int V_103 , V_104 , V_112 ;
int V_29 = 0 ;
F_17 ( ! V_91 -> V_40 [ 0 ] ) ;
V_97 = V_91 -> V_40 [ 0 ] ;
V_104 = V_91 -> V_107 [ 0 ] ;
V_112 = F_104 ( V_97 ) - 1 ;
if ( V_104 > V_112 )
return - V_113 ;
V_45 = V_49 ;
F_8 ( & V_101 ) ;
F_105 ( V_97 , & V_19 , V_104 ) ;
V_103 = 0 ;
while ( F_54 ( & V_45 -> V_19 , & V_19 ) == 0 ) {
F_31 ( & V_45 -> V_106 , & V_101 ) ;
V_103 ++ ;
V_92 = V_45 ;
V_45 = F_76 ( V_92 ) ;
if ( ! V_45 )
break;
if ( ! F_9 ( V_92 , V_45 ) )
break;
V_104 ++ ;
if ( V_104 > V_112 )
break;
F_105 ( V_97 , & V_19 , V_104 ) ;
}
if ( ! V_103 )
return 0 ;
V_29 = F_106 ( V_74 , V_7 , V_91 , V_91 -> V_107 [ 0 ] , V_103 ) ;
if ( V_29 )
goto V_44;
F_94 (curr, next, &head, tree_list) {
F_81 ( V_46 , V_92 ) ;
F_97 ( & V_92 -> V_106 ) ;
F_71 ( V_92 ) ;
}
V_44:
return V_29 ;
}
static int F_107 ( struct V_73 * V_74 ,
struct V_90 * V_91 ,
struct V_6 * V_7 ,
struct V_2 * V_26 )
{
struct V_16 * V_92 , * V_54 ;
int V_29 = 0 ;
V_110:
F_42 ( & V_26 -> V_13 ) ;
V_92 = F_75 ( V_26 ) ;
if ( ! V_92 )
goto V_114;
V_29 = F_108 ( V_74 , V_7 , & V_92 -> V_19 , V_91 , - 1 , 1 ) ;
if ( V_29 < 0 )
goto V_114;
else if ( V_29 > 0 ) {
V_54 = V_92 ;
V_92 = F_76 ( V_54 ) ;
F_71 ( V_54 ) ;
V_29 = 0 ;
F_102 ( V_91 ) ;
if ( V_92 ) {
F_43 ( & V_26 -> V_13 ) ;
goto V_110;
} else
goto V_114;
}
F_103 ( V_74 , V_7 , V_91 , V_92 ) ;
F_102 ( V_91 ) ;
F_43 ( & V_26 -> V_13 ) ;
goto V_110;
V_114:
F_102 ( V_91 ) ;
F_43 ( & V_26 -> V_13 ) ;
return V_29 ;
}
static void F_109 ( struct V_2 * V_5 )
{
struct V_33 * V_41 ;
if ( V_5 &&
F_28 ( V_115 , & V_5 -> V_37 ) ) {
F_17 ( ! V_5 -> V_7 ) ;
F_36 ( V_115 , & V_5 -> V_37 ) ;
V_5 -> V_47 -- ;
V_41 = V_5 -> V_7 -> V_46 -> V_41 ;
F_64 ( V_41 ) ;
}
}
static void F_110 ( struct V_2 * V_5 )
{
struct V_33 * V_41 ;
ASSERT ( V_5 -> V_7 ) ;
F_36 ( V_116 , & V_5 -> V_37 ) ;
V_5 -> V_47 -- ;
V_41 = V_5 -> V_7 -> V_46 -> V_41 ;
F_64 ( V_41 ) ;
}
static int F_111 ( struct V_73 * V_74 ,
struct V_6 * V_7 ,
struct V_90 * V_91 ,
struct V_2 * V_26 )
{
struct V_75 * V_46 = V_7 -> V_46 ;
struct V_53 V_19 ;
struct V_117 * V_118 ;
struct V_96 * V_97 ;
int V_34 ;
int V_29 ;
V_19 . V_21 = V_26 -> V_8 ;
V_19 . type = V_119 ;
V_19 . V_22 = 0 ;
if ( F_28 ( V_116 , & V_26 -> V_37 ) )
V_34 = - 1 ;
else
V_34 = 1 ;
V_29 = F_112 ( V_74 , V_7 , V_91 , & V_19 , V_34 ) ;
if ( V_29 > 0 ) {
F_102 ( V_91 ) ;
return - V_113 ;
} else if ( V_29 < 0 ) {
return V_29 ;
}
V_97 = V_91 -> V_40 [ 0 ] ;
V_118 = F_95 ( V_97 , V_91 -> V_107 [ 0 ] ,
struct V_117 ) ;
F_96 ( V_97 , & V_26 -> V_118 , ( unsigned long ) V_118 ,
sizeof( struct V_117 ) ) ;
F_100 ( V_97 ) ;
if ( ! F_28 ( V_116 , & V_26 -> V_37 ) )
goto V_120;
V_91 -> V_107 [ 0 ] ++ ;
if ( V_91 -> V_107 [ 0 ] >= F_104 ( V_97 ) )
goto V_121;
V_30:
F_105 ( V_97 , & V_19 , V_91 -> V_107 [ 0 ] ) ;
if ( V_19 . V_21 != V_26 -> V_8 )
goto V_44;
if ( V_19 . type != V_122 &&
V_19 . type != V_123 )
goto V_44;
F_113 ( V_74 , V_7 , V_91 ) ;
V_44:
F_110 ( V_26 ) ;
V_120:
F_102 ( V_91 ) ;
V_124:
F_86 ( V_46 , V_26 ) ;
F_109 ( V_26 ) ;
return V_29 ;
V_121:
F_102 ( V_91 ) ;
V_19 . type = V_123 ;
V_19 . V_22 = - 1 ;
V_29 = F_108 ( V_74 , V_7 , & V_19 , V_91 , - 1 , 1 ) ;
if ( V_29 < 0 )
goto V_124;
ASSERT ( V_29 ) ;
V_29 = 0 ;
V_97 = V_91 -> V_40 [ 0 ] ;
V_91 -> V_107 [ 0 ] -- ;
goto V_30;
}
static inline int F_114 ( struct V_73 * V_74 ,
struct V_6 * V_7 ,
struct V_90 * V_91 ,
struct V_2 * V_26 )
{
int V_29 ;
F_42 ( & V_26 -> V_13 ) ;
if ( ! F_28 ( V_115 , & V_26 -> V_37 ) ) {
F_43 ( & V_26 -> V_13 ) ;
return 0 ;
}
V_29 = F_111 ( V_74 , V_7 , V_91 , V_26 ) ;
F_43 ( & V_26 -> V_13 ) ;
return V_29 ;
}
static inline int
F_115 ( struct V_73 * V_74 ,
struct V_90 * V_91 ,
struct V_2 * V_26 )
{
int V_29 ;
V_29 = F_101 ( V_74 , V_91 , V_26 -> V_7 , V_26 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_107 ( V_74 , V_91 , V_26 -> V_7 , V_26 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_114 ( V_74 , V_26 -> V_7 , V_91 , V_26 ) ;
return V_29 ;
}
static int F_116 ( struct V_73 * V_74 ,
struct V_75 * V_46 , int V_125 )
{
struct V_33 * V_41 ;
struct V_2 * V_126 , * V_56 ;
struct V_90 * V_91 ;
struct V_76 * V_80 ;
int V_29 = 0 ;
bool V_47 = ( V_125 > 0 ) ;
if ( V_74 -> V_127 )
return - V_128 ;
V_91 = F_117 () ;
if ( ! V_91 )
return - V_4 ;
V_91 -> V_129 = 1 ;
V_80 = V_74 -> V_80 ;
V_74 -> V_80 = & V_46 -> V_81 ;
V_41 = V_46 -> V_41 ;
V_126 = F_37 ( V_41 ) ;
while ( V_126 && ( ! V_47 || ( V_47 && V_125 -- ) ) ) {
V_29 = F_115 ( V_74 , V_91 ,
V_126 ) ;
if ( V_29 ) {
F_47 ( V_126 ) ;
V_126 = NULL ;
F_118 ( V_74 , V_29 ) ;
break;
}
V_56 = V_126 ;
V_126 = F_39 ( V_126 ) ;
F_47 ( V_56 ) ;
}
if ( V_126 )
F_47 ( V_126 ) ;
F_119 ( V_91 ) ;
V_74 -> V_80 = V_80 ;
return V_29 ;
}
int F_120 ( struct V_73 * V_74 ,
struct V_75 * V_46 )
{
return F_116 ( V_74 , V_46 , - 1 ) ;
}
int F_121 ( struct V_73 * V_74 ,
struct V_75 * V_46 , int V_125 )
{
return F_116 ( V_74 , V_46 , V_125 ) ;
}
int F_122 ( struct V_73 * V_74 ,
struct V_23 * V_23 )
{
struct V_2 * V_5 = F_10 ( V_23 ) ;
struct V_90 * V_91 ;
struct V_76 * V_80 ;
int V_29 ;
if ( ! V_5 )
return 0 ;
F_42 ( & V_5 -> V_13 ) ;
if ( ! V_5 -> V_47 ) {
F_43 ( & V_5 -> V_13 ) ;
F_47 ( V_5 ) ;
return 0 ;
}
F_43 ( & V_5 -> V_13 ) ;
V_91 = F_117 () ;
if ( ! V_91 ) {
F_47 ( V_5 ) ;
return - V_4 ;
}
V_91 -> V_129 = 1 ;
V_80 = V_74 -> V_80 ;
V_74 -> V_80 = & V_5 -> V_7 -> V_46 -> V_81 ;
V_29 = F_115 ( V_74 , V_91 , V_5 ) ;
F_47 ( V_5 ) ;
F_119 ( V_91 ) ;
V_74 -> V_80 = V_80 ;
return V_29 ;
}
int F_123 ( struct V_23 * V_23 )
{
struct V_75 * V_46 = F_124 ( V_23 -> V_130 ) ;
struct V_73 * V_74 ;
struct V_2 * V_5 = F_10 ( V_23 ) ;
struct V_90 * V_91 ;
struct V_76 * V_80 ;
int V_29 ;
if ( ! V_5 )
return 0 ;
F_42 ( & V_5 -> V_13 ) ;
if ( ! F_28 ( V_115 , & V_5 -> V_37 ) ) {
F_43 ( & V_5 -> V_13 ) ;
F_47 ( V_5 ) ;
return 0 ;
}
F_43 ( & V_5 -> V_13 ) ;
V_74 = F_125 ( V_5 -> V_7 ) ;
if ( F_126 ( V_74 ) ) {
V_29 = F_127 ( V_74 ) ;
goto V_44;
}
V_91 = F_117 () ;
if ( ! V_91 ) {
V_29 = - V_4 ;
goto V_131;
}
V_91 -> V_129 = 1 ;
V_80 = V_74 -> V_80 ;
V_74 -> V_80 = & V_46 -> V_81 ;
F_42 ( & V_5 -> V_13 ) ;
if ( F_28 ( V_115 , & V_5 -> V_37 ) )
V_29 = F_111 ( V_74 , V_5 -> V_7 ,
V_91 , V_5 ) ;
else
V_29 = 0 ;
F_43 ( & V_5 -> V_13 ) ;
F_119 ( V_91 ) ;
V_74 -> V_80 = V_80 ;
V_131:
F_128 ( V_74 ) ;
F_129 ( V_46 ) ;
V_44:
F_47 ( V_5 ) ;
return V_29 ;
}
void F_130 ( struct V_23 * V_23 )
{
struct V_2 * V_5 ;
V_5 = F_13 ( F_11 ( V_23 ) -> V_5 ) ;
if ( ! V_5 )
return;
F_11 ( V_23 ) -> V_5 = NULL ;
F_47 ( V_5 ) ;
}
static void F_131 ( struct V_132 * V_133 )
{
struct V_134 * V_135 ;
struct V_33 * V_41 ;
struct V_73 * V_74 ;
struct V_90 * V_91 ;
struct V_2 * V_5 = NULL ;
struct V_6 * V_7 ;
struct V_76 * V_80 ;
int V_136 = 0 ;
V_135 = F_132 ( V_133 , struct V_134 , V_133 ) ;
V_41 = V_135 -> V_41 ;
V_91 = F_117 () ;
if ( ! V_91 )
goto V_44;
V_30:
if ( F_45 ( & V_41 -> V_67 ) < V_70 / 2 )
goto V_137;
V_5 = F_48 ( V_41 ) ;
if ( ! V_5 )
goto V_137;
V_91 -> V_129 = 1 ;
V_7 = V_5 -> V_7 ;
V_74 = F_125 ( V_7 ) ;
if ( F_126 ( V_74 ) )
goto V_138;
V_80 = V_74 -> V_80 ;
V_74 -> V_80 = & V_7 -> V_46 -> V_81 ;
F_115 ( V_74 , V_91 , V_5 ) ;
V_74 -> V_80 = V_80 ;
F_128 ( V_74 ) ;
F_133 ( V_7 -> V_46 ) ;
V_138:
F_102 ( V_91 ) ;
V_136 ++ ;
F_49 ( V_5 ) ;
if ( ( V_135 -> V_125 == 0 && V_136 < V_139 ) ||
V_136 < V_135 -> V_125 )
goto V_30;
V_137:
F_119 ( V_91 ) ;
V_44:
F_68 ( & V_41 -> V_72 ) ;
F_72 ( V_135 ) ;
}
static int F_134 ( struct V_33 * V_41 ,
struct V_75 * V_46 , int V_125 )
{
struct V_134 * V_135 ;
if ( F_45 ( & V_41 -> V_67 ) < V_70 ||
F_135 ( V_46 -> V_140 ) )
return 0 ;
V_135 = F_51 ( sizeof( * V_135 ) , V_31 ) ;
if ( ! V_135 )
return - V_4 ;
V_135 -> V_41 = V_41 ;
F_136 ( & V_135 -> V_133 , V_141 ,
F_131 , NULL , NULL ) ;
V_135 -> V_125 = V_125 ;
F_137 ( V_46 -> V_140 , & V_135 -> V_133 ) ;
return 0 ;
}
void F_138 ( struct V_75 * V_46 )
{
F_139 ( F_37 ( V_46 -> V_41 ) ) ;
}
static int F_140 ( struct V_33 * V_41 , int V_68 )
{
int V_142 = F_45 ( & V_41 -> V_69 ) ;
if ( V_142 < V_68 || V_142 >= V_68 + V_71 )
return 1 ;
if ( F_45 ( & V_41 -> V_67 ) < V_70 )
return 1 ;
return 0 ;
}
void F_141 ( struct V_75 * V_46 )
{
struct V_33 * V_41 = V_46 -> V_41 ;
if ( F_45 ( & V_41 -> V_67 ) < V_70 )
return;
if ( F_45 ( & V_41 -> V_67 ) >= V_139 ) {
int V_68 ;
int V_29 ;
V_68 = F_45 ( & V_41 -> V_69 ) ;
V_29 = F_134 ( V_41 , V_46 , 0 ) ;
if ( V_29 )
return;
F_142 ( V_41 -> V_72 ,
F_140 ( V_41 , V_68 ) ) ;
return;
}
F_134 ( V_41 , V_46 , V_71 ) ;
}
int F_143 ( struct V_73 * V_74 ,
struct V_75 * V_46 ,
const char * V_143 , int V_144 ,
struct V_23 * V_145 ,
struct V_146 * V_147 , T_4 type ,
T_2 V_148 )
{
struct V_2 * V_5 ;
struct V_16 * V_57 ;
struct V_149 * V_150 ;
int V_29 ;
V_5 = F_20 ( V_145 ) ;
if ( F_126 ( V_5 ) )
return F_127 ( V_5 ) ;
V_57 = F_50 ( sizeof( * V_150 ) + V_144 ) ;
if ( ! V_57 ) {
V_29 = - V_4 ;
goto V_151;
}
V_57 -> V_19 . V_21 = F_12 ( V_145 ) ;
V_57 -> V_19 . type = V_20 ;
V_57 -> V_19 . V_22 = V_148 ;
V_150 = (struct V_149 * ) V_57 -> V_108 ;
V_150 -> V_152 = * V_147 ;
F_144 ( V_150 , V_74 -> V_153 ) ;
F_145 ( V_150 , 0 ) ;
F_146 ( V_150 , V_144 ) ;
F_147 ( V_150 , type ) ;
memcpy ( ( char * ) ( V_150 + 1 ) , V_143 , V_144 ) ;
V_29 = F_77 ( V_74 , V_46 , V_57 ) ;
F_17 ( V_29 ) ;
F_42 ( & V_5 -> V_13 ) ;
V_29 = F_62 ( V_5 , V_57 ) ;
if ( F_148 ( V_29 ) ) {
F_149 ( V_46 ,
L_5 ,
V_144 , V_143 , V_5 -> V_7 -> V_21 ,
V_5 -> V_8 , V_29 ) ;
F_59 () ;
}
F_43 ( & V_5 -> V_13 ) ;
V_151:
F_47 ( V_5 ) ;
return V_29 ;
}
static int F_150 ( struct V_75 * V_46 ,
struct V_2 * V_26 ,
struct V_53 * V_19 )
{
struct V_16 * V_49 ;
F_42 ( & V_26 -> V_13 ) ;
V_49 = F_57 ( V_26 , V_19 ) ;
if ( ! V_49 ) {
F_43 ( & V_26 -> V_13 ) ;
return 1 ;
}
F_81 ( V_46 , V_49 ) ;
F_71 ( V_49 ) ;
F_43 ( & V_26 -> V_13 ) ;
return 0 ;
}
int F_151 ( struct V_73 * V_74 ,
struct V_75 * V_46 ,
struct V_23 * V_145 , T_2 V_148 )
{
struct V_2 * V_26 ;
struct V_16 * V_49 ;
struct V_53 V_154 ;
int V_29 ;
V_26 = F_20 ( V_145 ) ;
if ( F_126 ( V_26 ) )
return F_127 ( V_26 ) ;
V_154 . V_21 = F_12 ( V_145 ) ;
V_154 . type = V_20 ;
V_154 . V_22 = V_148 ;
V_29 = F_150 ( V_46 , V_26 , & V_154 ) ;
if ( ! V_29 )
goto V_155;
V_49 = F_50 ( 0 ) ;
if ( ! V_49 ) {
V_29 = - V_4 ;
goto V_155;
}
V_49 -> V_19 = V_154 ;
V_29 = F_77 ( V_74 , V_46 , V_49 ) ;
F_17 ( V_29 ) ;
F_42 ( & V_26 -> V_13 ) ;
V_29 = F_63 ( V_26 , V_49 ) ;
if ( F_148 ( V_29 ) ) {
F_149 ( V_46 ,
L_6 ,
V_148 , V_26 -> V_7 -> V_21 , V_26 -> V_8 , V_29 ) ;
F_59 () ;
}
F_43 ( & V_26 -> V_13 ) ;
V_155:
F_47 ( V_26 ) ;
return V_29 ;
}
int F_152 ( struct V_23 * V_23 )
{
struct V_2 * V_5 = F_10 ( V_23 ) ;
if ( ! V_5 )
return - V_113 ;
if ( ! V_5 -> V_66 ) {
F_47 ( V_5 ) ;
return - V_156 ;
}
F_11 ( V_23 ) -> V_66 = V_5 -> V_66 ;
F_47 ( V_5 ) ;
return 0 ;
}
bool F_153 ( struct V_23 * V_23 ,
struct V_42 * V_157 ,
struct V_42 * V_158 )
{
struct V_2 * V_5 ;
struct V_16 * V_49 ;
V_5 = F_10 ( V_23 ) ;
if ( ! V_5 )
return false ;
F_154 ( V_23 ) ;
V_27 ( V_23 ) ;
F_42 ( & V_5 -> V_13 ) ;
V_49 = F_73 ( V_5 ) ;
while ( V_49 ) {
F_14 ( & V_49 -> V_9 ) ;
F_31 ( & V_49 -> V_159 , V_157 ) ;
V_49 = F_76 ( V_49 ) ;
}
V_49 = F_75 ( V_5 ) ;
while ( V_49 ) {
F_14 ( & V_49 -> V_9 ) ;
F_31 ( & V_49 -> V_159 , V_158 ) ;
V_49 = F_76 ( V_49 ) ;
}
F_43 ( & V_5 -> V_13 ) ;
F_34 ( & V_5 -> V_9 ) ;
return true ;
}
void F_155 ( struct V_23 * V_23 ,
struct V_42 * V_157 ,
struct V_42 * V_158 )
{
struct V_16 * V_92 , * V_45 ;
F_94 (curr, next, ins_list, readdir_list) {
F_97 ( & V_92 -> V_159 ) ;
if ( F_44 ( & V_92 -> V_9 ) )
F_72 ( V_92 ) ;
}
F_94 (curr, next, del_list, readdir_list) {
F_97 ( & V_92 -> V_159 ) ;
if ( F_44 ( & V_92 -> V_9 ) )
F_72 ( V_92 ) ;
}
F_156 ( & V_23 -> V_160 ) ;
}
int F_157 ( struct V_42 * V_158 ,
T_2 V_148 )
{
struct V_16 * V_92 , * V_45 ;
int V_29 ;
if ( F_29 ( V_158 ) )
return 0 ;
F_94 (curr, next, del_list, readdir_list) {
if ( V_92 -> V_19 . V_22 > V_148 )
break;
F_97 ( & V_92 -> V_159 ) ;
V_29 = ( V_92 -> V_19 . V_22 == V_148 ) ;
if ( F_44 ( & V_92 -> V_9 ) )
F_72 ( V_92 ) ;
if ( V_29 )
return 1 ;
else
continue;
}
return 0 ;
}
int F_158 ( struct V_161 * V_162 ,
struct V_42 * V_157 )
{
struct V_149 * V_163 ;
struct V_16 * V_92 , * V_45 ;
struct V_53 V_152 ;
char * V_143 ;
int V_144 ;
int V_164 = 0 ;
unsigned char V_165 ;
if ( F_29 ( V_157 ) )
return 0 ;
F_94 (curr, next, ins_list, readdir_list) {
F_97 ( & V_92 -> V_159 ) ;
if ( V_92 -> V_19 . V_22 < V_162 -> V_166 ) {
if ( F_44 ( & V_92 -> V_9 ) )
F_72 ( V_92 ) ;
continue;
}
V_162 -> V_166 = V_92 -> V_19 . V_22 ;
V_163 = (struct V_149 * ) V_92 -> V_108 ;
V_143 = ( char * ) ( V_163 + 1 ) ;
V_144 = F_159 ( V_163 ) ;
V_165 = V_167 [ V_163 -> type ] ;
F_160 ( & V_152 , & V_163 -> V_152 ) ;
V_164 = ! F_161 ( V_162 , V_143 , V_144 ,
V_152 . V_21 , V_165 ) ;
if ( F_44 ( & V_92 -> V_9 ) )
F_72 ( V_92 ) ;
if ( V_164 )
return 1 ;
}
return 0 ;
}
static void F_162 ( struct V_73 * V_74 ,
struct V_117 * V_118 ,
struct V_23 * V_23 )
{
F_163 ( V_118 , F_164 ( V_23 ) ) ;
F_165 ( V_118 , F_166 ( V_23 ) ) ;
F_167 ( V_118 , F_11 ( V_23 ) -> V_168 ) ;
F_168 ( V_118 , V_23 -> V_169 ) ;
F_169 ( V_118 , V_23 -> V_170 ) ;
F_170 ( V_118 , F_171 ( V_23 ) ) ;
F_172 ( V_118 ,
F_11 ( V_23 ) -> V_171 ) ;
F_173 ( V_118 , V_23 -> V_172 ) ;
F_174 ( V_118 , V_74 -> V_153 ) ;
F_175 ( V_118 , V_23 -> V_173 ) ;
F_176 ( V_118 , F_11 ( V_23 ) -> V_37 ) ;
F_177 ( V_118 , 0 ) ;
F_178 ( & V_118 -> V_174 ,
V_23 -> V_175 . V_176 ) ;
F_179 ( & V_118 -> V_174 ,
V_23 -> V_175 . V_177 ) ;
F_178 ( & V_118 -> V_178 ,
V_23 -> V_179 . V_176 ) ;
F_179 ( & V_118 -> V_178 ,
V_23 -> V_179 . V_177 ) ;
F_178 ( & V_118 -> ctime ,
V_23 -> V_180 . V_176 ) ;
F_179 ( & V_118 -> ctime ,
V_23 -> V_180 . V_177 ) ;
F_178 ( & V_118 -> V_181 ,
F_11 ( V_23 ) -> V_182 . V_176 ) ;
F_179 ( & V_118 -> V_181 ,
F_11 ( V_23 ) -> V_182 . V_177 ) ;
}
int F_180 ( struct V_23 * V_23 , T_3 * V_183 )
{
struct V_2 * V_5 ;
struct V_117 * V_118 ;
V_5 = F_10 ( V_23 ) ;
if ( ! V_5 )
return - V_113 ;
F_42 ( & V_5 -> V_13 ) ;
if ( ! F_28 ( V_115 , & V_5 -> V_37 ) ) {
F_43 ( & V_5 -> V_13 ) ;
F_47 ( V_5 ) ;
return - V_113 ;
}
V_118 = & V_5 -> V_118 ;
F_181 ( V_23 , F_182 ( V_118 ) ) ;
F_183 ( V_23 , F_184 ( V_118 ) ) ;
F_185 ( V_23 , F_186 ( V_118 ) ) ;
V_23 -> V_169 = F_187 ( V_118 ) ;
F_188 ( V_23 , F_189 ( V_118 ) ) ;
F_190 ( V_23 , F_191 ( V_118 ) ) ;
F_11 ( V_23 ) -> V_171 = F_192 ( V_118 ) ;
F_11 ( V_23 ) -> V_184 = F_193 ( V_118 ) ;
V_23 -> V_172 = F_194 ( V_118 ) ;
V_23 -> V_173 = 0 ;
* V_183 = F_195 ( V_118 ) ;
F_11 ( V_23 ) -> V_37 = F_196 ( V_118 ) ;
V_23 -> V_175 . V_176 = F_197 ( & V_118 -> V_174 ) ;
V_23 -> V_175 . V_177 = F_198 ( & V_118 -> V_174 ) ;
V_23 -> V_179 . V_176 = F_197 ( & V_118 -> V_178 ) ;
V_23 -> V_179 . V_177 = F_198 ( & V_118 -> V_178 ) ;
V_23 -> V_180 . V_176 = F_197 ( & V_118 -> ctime ) ;
V_23 -> V_180 . V_177 = F_198 ( & V_118 -> ctime ) ;
F_11 ( V_23 ) -> V_182 . V_176 =
F_197 ( & V_118 -> V_181 ) ;
F_11 ( V_23 ) -> V_182 . V_177 =
F_198 ( & V_118 -> V_181 ) ;
V_23 -> V_185 = F_11 ( V_23 ) -> V_171 ;
F_11 ( V_23 ) -> V_66 = ( T_2 ) - 1 ;
F_43 ( & V_5 -> V_13 ) ;
F_47 ( V_5 ) ;
return 0 ;
}
int F_199 ( struct V_73 * V_74 ,
struct V_6 * V_7 , struct V_23 * V_23 )
{
struct V_2 * V_5 ;
int V_29 = 0 ;
V_5 = F_20 ( V_23 ) ;
if ( F_126 ( V_5 ) )
return F_127 ( V_5 ) ;
F_42 ( & V_5 -> V_13 ) ;
if ( F_28 ( V_115 , & V_5 -> V_37 ) ) {
F_162 ( V_74 , & V_5 -> V_118 , V_23 ) ;
goto V_151;
}
V_29 = F_83 ( V_74 , V_7 , V_23 ,
V_5 ) ;
if ( V_29 )
goto V_151;
F_162 ( V_74 , & V_5 -> V_118 , V_23 ) ;
F_32 ( V_115 , & V_5 -> V_37 ) ;
V_5 -> V_47 ++ ;
F_14 ( & V_7 -> V_46 -> V_41 -> V_67 ) ;
V_151:
F_43 ( & V_5 -> V_13 ) ;
F_47 ( V_5 ) ;
return V_29 ;
}
int F_200 ( struct V_23 * V_23 )
{
struct V_75 * V_46 = F_124 ( V_23 -> V_130 ) ;
struct V_2 * V_5 ;
if ( F_28 ( V_186 , & V_46 -> V_37 ) )
return - V_88 ;
V_5 = F_20 ( V_23 ) ;
if ( F_126 ( V_5 ) )
return F_127 ( V_5 ) ;
F_42 ( & V_5 -> V_13 ) ;
if ( F_28 ( V_116 , & V_5 -> V_37 ) )
goto V_151;
F_32 ( V_116 , & V_5 -> V_37 ) ;
V_5 -> V_47 ++ ;
F_14 ( & V_46 -> V_41 -> V_67 ) ;
V_151:
F_43 ( & V_5 -> V_13 ) ;
F_47 ( V_5 ) ;
return 0 ;
}
static void F_201 ( struct V_2 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_75 * V_46 = V_7 -> V_46 ;
struct V_16 * V_187 , * V_188 ;
F_42 ( & V_5 -> V_13 ) ;
V_187 = F_73 ( V_5 ) ;
while ( V_187 ) {
F_81 ( V_46 , V_187 ) ;
V_188 = V_187 ;
V_187 = F_76 ( V_188 ) ;
F_71 ( V_188 ) ;
}
V_187 = F_75 ( V_5 ) ;
while ( V_187 ) {
F_81 ( V_46 , V_187 ) ;
V_188 = V_187 ;
V_187 = F_76 ( V_188 ) ;
F_71 ( V_188 ) ;
}
if ( F_28 ( V_116 , & V_5 -> V_37 ) )
F_110 ( V_5 ) ;
if ( F_28 ( V_115 , & V_5 -> V_37 ) ) {
F_86 ( V_46 , V_5 ) ;
F_109 ( V_5 ) ;
}
F_43 ( & V_5 -> V_13 ) ;
}
void F_202 ( struct V_23 * V_23 )
{
struct V_2 * V_5 ;
V_5 = F_10 ( V_23 ) ;
if ( ! V_5 )
return;
F_201 ( V_5 ) ;
F_47 ( V_5 ) ;
}
void F_203 ( struct V_6 * V_7 )
{
T_2 V_8 = 0 ;
struct V_2 * V_189 [ 8 ] ;
int V_104 , V_190 ;
while ( 1 ) {
F_15 ( & V_7 -> V_27 ) ;
V_190 = F_204 ( & V_7 -> V_28 ,
( void * * ) V_189 , V_8 ,
F_205 ( V_189 ) ) ;
if ( ! V_190 ) {
F_18 ( & V_7 -> V_27 ) ;
break;
}
V_8 = V_189 [ V_190 - 1 ] -> V_8 + 1 ;
for ( V_104 = 0 ; V_104 < V_190 ; V_104 ++ )
F_14 ( & V_189 [ V_104 ] -> V_9 ) ;
F_18 ( & V_7 -> V_27 ) ;
for ( V_104 = 0 ; V_104 < V_190 ; V_104 ++ ) {
F_201 ( V_189 [ V_104 ] ) ;
F_47 ( V_189 [ V_104 ] ) ;
}
}
}
void F_206 ( struct V_75 * V_46 )
{
struct V_2 * V_126 , * V_56 ;
V_126 = F_37 ( V_46 -> V_41 ) ;
while ( V_126 ) {
F_201 ( V_126 ) ;
V_56 = V_126 ;
V_126 = F_39 ( V_126 ) ;
F_47 ( V_56 ) ;
}
}
