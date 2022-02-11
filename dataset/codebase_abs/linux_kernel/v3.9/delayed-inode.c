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
struct V_2 * F_34 (
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
struct V_2 * F_36 (
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
struct V_2 * F_45 (
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
struct V_23 * F_47 ( T_3 V_53 )
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
struct V_23 * F_54 (
struct V_2 * V_6 ,
struct V_57 * V_26 )
{
struct V_23 * V_54 ;
V_54 = F_49 ( & V_6 -> V_14 , V_26 ,
NULL , NULL ) ;
return V_54 ;
}
struct V_23 * F_55 (
struct V_2 * V_6 ,
struct V_57 * V_26 )
{
struct V_23 * V_54 ;
V_54 = F_49 ( & V_6 -> V_16 , V_26 ,
NULL , NULL ) ;
return V_54 ;
}
struct V_23 * F_56 (
struct V_2 * V_6 ,
struct V_57 * V_26 )
{
struct V_23 * V_54 , * V_52 ;
V_54 = F_49 ( & V_6 -> V_14 , V_26 ,
NULL , & V_52 ) ;
if ( ! V_54 )
V_54 = V_52 ;
return V_54 ;
}
struct V_23 * F_57 (
struct V_2 * V_6 ,
struct V_57 * V_26 )
{
struct V_23 * V_54 , * V_52 ;
V_54 = F_49 ( & V_6 -> V_16 , V_26 ,
NULL , & V_52 ) ;
if ( ! V_54 )
V_54 = V_52 ;
return V_54 ;
}
static int F_58 ( struct V_2 * V_6 ,
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
F_59 () ;
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
F_60 ( V_36 , V_66 , V_50 ) ;
F_61 ( V_36 , V_8 ) ;
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
static int F_62 ( struct V_2 * V_36 ,
struct V_23 * V_54 )
{
return F_58 ( V_36 , V_54 ,
V_68 ) ;
}
static int F_63 ( struct V_2 * V_36 ,
struct V_23 * V_54 )
{
return F_58 ( V_36 , V_54 ,
V_69 ) ;
}
static void F_64 ( struct V_30 * V_32 )
{
int V_71 = F_65 ( & V_32 -> V_72 ) ;
if ( ( F_66 ( & V_32 -> V_70 ) <
V_73 || V_71 % V_74 == 0 ) &&
F_67 ( & V_32 -> V_75 ) )
F_68 ( & V_32 -> V_75 ) ;
}
static void F_69 ( struct V_23 * V_61 )
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
F_70 ( & V_61 -> V_59 , V_8 ) ;
V_61 -> V_6 -> V_11 -- ;
F_64 ( V_32 ) ;
}
static void F_71 ( struct V_23 * V_54 )
{
if ( V_54 ) {
F_69 ( V_54 ) ;
if ( F_41 ( & V_54 -> V_10 ) )
F_72 ( V_54 ) ;
}
}
struct V_23 * F_73 (
struct V_2 * V_6 )
{
struct V_59 * V_50 ;
struct V_23 * V_54 = NULL ;
V_50 = F_74 ( & V_6 -> V_14 ) ;
if ( V_50 )
V_54 = F_50 ( V_50 , struct V_23 , V_59 ) ;
return V_54 ;
}
struct V_23 * F_75 (
struct V_2 * V_6 )
{
struct V_59 * V_50 ;
struct V_23 * V_54 = NULL ;
V_50 = F_74 ( & V_6 -> V_16 ) ;
if ( V_50 )
V_54 = F_50 ( V_50 , struct V_23 , V_59 ) ;
return V_54 ;
}
struct V_23 * F_76 (
struct V_23 * V_54 )
{
struct V_59 * V_50 ;
struct V_23 * V_52 = NULL ;
V_50 = F_53 ( & V_54 -> V_59 ) ;
if ( V_50 )
V_52 = F_50 ( V_50 , struct V_23 , V_59 ) ;
return V_52 ;
}
static inline struct V_7 * F_77 ( struct V_7 * V_8 ,
T_2 V_76 )
{
struct V_57 V_77 ;
if ( V_8 -> V_28 == V_76 )
return V_8 ;
V_77 . V_28 = V_76 ;
V_77 . type = V_78 ;
V_77 . V_29 = ( T_2 ) - 1 ;
return F_78 ( V_8 -> V_31 , & V_77 ) ;
}
static int F_79 ( struct V_79 * V_80 ,
struct V_7 * V_8 ,
struct V_23 * V_54 )
{
struct V_81 * V_82 ;
struct V_81 * V_83 ;
T_2 V_84 ;
int V_39 ;
if ( ! V_80 -> V_21 )
return 0 ;
V_82 = V_80 -> V_85 ;
V_83 = & V_8 -> V_31 -> V_86 ;
V_84 = F_80 ( V_8 , 1 ) ;
V_39 = F_81 ( V_82 , V_83 , V_84 ) ;
if ( ! V_39 ) {
F_82 ( V_8 -> V_31 , L_2 ,
V_54 -> V_26 . V_28 ,
V_84 , 1 ) ;
V_54 -> V_21 = V_84 ;
}
return V_39 ;
}
static void F_83 ( struct V_7 * V_8 ,
struct V_23 * V_54 )
{
struct V_81 * V_87 ;
if ( ! V_54 -> V_21 )
return;
V_87 = & V_8 -> V_31 -> V_86 ;
F_82 ( V_8 -> V_31 , L_2 ,
V_54 -> V_26 . V_28 , V_54 -> V_21 ,
0 ) ;
F_84 ( V_8 , V_87 ,
V_54 -> V_21 ) ;
}
static int F_85 (
struct V_79 * V_80 ,
struct V_7 * V_8 ,
struct V_33 * V_33 ,
struct V_2 * V_36 )
{
struct V_81 * V_82 ;
struct V_81 * V_83 ;
T_2 V_84 ;
int V_39 ;
bool V_88 = false ;
V_82 = V_80 -> V_85 ;
V_83 = & V_8 -> V_31 -> V_86 ;
V_84 = F_80 ( V_8 , 1 ) ;
if ( ! V_82 || ( ! V_80 -> V_21 &&
V_82 -> type != V_89 ) ) {
V_39 = F_86 ( V_8 , V_83 , V_84 ,
V_90 ) ;
if ( V_39 == - V_91 )
V_39 = - V_92 ;
if ( ! V_39 ) {
V_36 -> V_21 = V_84 ;
F_82 ( V_8 -> V_31 ,
L_3 ,
F_13 ( V_33 ) ,
V_84 , 1 ) ;
}
return V_39 ;
} else if ( V_82 -> type == V_89 ) {
F_16 ( & F_12 ( V_33 ) -> V_45 ) ;
if ( F_87 ( V_93 ,
& F_12 ( V_33 ) -> V_94 ) ) {
F_19 ( & F_12 ( V_33 ) -> V_45 ) ;
V_88 = true ;
goto V_95;
}
F_19 ( & F_12 ( V_33 ) -> V_45 ) ;
V_39 = F_86 ( V_8 , V_83 , V_84 ,
V_90 ) ;
if ( ! V_39 )
goto V_51;
V_39 = F_81 ( V_82 , V_83 , V_84 ) ;
if ( ! V_39 )
goto V_51;
F_88 ( 1 ) ;
V_39 = F_81 ( & V_8 -> V_31 -> V_96 ,
V_83 , V_84 ) ;
goto V_51;
}
V_95:
V_39 = F_81 ( V_82 , V_83 , V_84 ) ;
V_51:
if ( ! V_39 ) {
F_82 ( V_8 -> V_31 , L_3 ,
F_13 ( V_33 ) , V_84 , 1 ) ;
V_36 -> V_21 = V_84 ;
}
if ( V_88 ) {
F_82 ( V_8 -> V_31 , L_4 ,
F_13 ( V_33 ) , V_84 , 0 ) ;
F_84 ( V_8 , V_82 , V_84 ) ;
}
return V_39 ;
}
static void F_89 ( struct V_7 * V_8 ,
struct V_2 * V_36 )
{
struct V_81 * V_87 ;
if ( ! V_36 -> V_21 )
return;
V_87 = & V_8 -> V_31 -> V_86 ;
F_82 ( V_8 -> V_31 , L_3 ,
V_36 -> V_9 , V_36 -> V_21 , 0 ) ;
F_84 ( V_8 , V_87 ,
V_36 -> V_21 ) ;
V_36 -> V_21 = 0 ;
}
static int F_90 ( struct V_79 * V_80 ,
struct V_7 * V_8 ,
struct V_97 * V_98 ,
struct V_23 * V_54 )
{
struct V_23 * V_99 , * V_52 ;
int V_100 ;
int V_101 = 0 , V_102 = 0 ;
struct V_103 * V_104 ;
char * V_105 ;
struct V_57 * V_106 ;
T_3 * V_107 ;
struct V_49 V_108 ;
int V_109 ;
int V_110 ;
int V_111 ;
int V_39 = 0 ;
F_18 ( ! V_98 -> V_48 [ 0 ] ) ;
V_104 = V_98 -> V_48 [ 0 ] ;
V_100 = F_91 ( V_8 , V_104 ) ;
F_8 ( & V_108 ) ;
V_52 = V_54 ;
V_110 = 0 ;
while ( V_102 + V_52 -> V_53 + sizeof( struct V_112 ) <=
V_100 ) {
V_101 += V_52 -> V_53 ;
V_102 += V_52 -> V_53 + sizeof( struct V_112 ) ;
F_30 ( & V_52 -> V_113 , & V_108 ) ;
V_110 ++ ;
V_99 = V_52 ;
V_52 = F_76 ( V_99 ) ;
if ( ! V_52 )
break;
if ( ! F_9 ( V_99 , V_52 ) )
break;
}
if ( ! V_110 ) {
V_39 = 0 ;
goto V_51;
}
F_92 ( V_98 ) ;
V_106 = F_48 ( sizeof( struct V_57 ) * V_110 , V_41 ) ;
if ( ! V_106 ) {
V_39 = - V_5 ;
goto V_51;
}
V_107 = F_48 ( sizeof( T_3 ) * V_110 , V_41 ) ;
if ( ! V_107 ) {
V_39 = - V_5 ;
goto error;
}
V_111 = 0 ;
F_93 (next, &head, tree_list) {
V_106 [ V_111 ] = V_52 -> V_26 ;
V_107 [ V_111 ] = V_52 -> V_53 ;
V_111 ++ ;
}
F_94 ( V_98 , NULL , 0 ) ;
F_95 ( V_80 , V_8 , V_98 , V_106 , V_107 ,
V_101 , V_102 , V_110 ) ;
V_109 = V_98 -> V_114 [ 0 ] ;
F_96 (curr, next, &head, tree_list) {
V_105 = F_97 ( V_104 , V_109 , char ) ;
F_98 ( V_104 , & V_99 -> V_115 ,
( unsigned long ) V_105 ,
V_99 -> V_53 ) ;
V_109 ++ ;
F_83 ( V_8 , V_99 ) ;
F_99 ( & V_99 -> V_113 ) ;
F_71 ( V_99 ) ;
}
error:
F_72 ( V_107 ) ;
F_72 ( V_106 ) ;
V_51:
return V_39 ;
}
static int F_100 ( struct V_79 * V_80 ,
struct V_7 * V_8 ,
struct V_97 * V_98 ,
struct V_23 * V_61 )
{
struct V_103 * V_104 ;
char * V_116 ;
int V_39 ;
V_39 = F_101 ( V_80 , V_8 , V_98 , & V_61 -> V_26 ,
V_61 -> V_53 ) ;
if ( V_39 < 0 && V_39 != - V_43 )
return V_39 ;
V_104 = V_98 -> V_48 [ 0 ] ;
V_116 = F_97 ( V_104 , V_98 -> V_114 [ 0 ] , char ) ;
F_98 ( V_104 , V_61 -> V_115 , ( unsigned long ) V_116 ,
V_61 -> V_53 ) ;
F_102 ( V_104 ) ;
F_83 ( V_8 , V_61 ) ;
return 0 ;
}
static int F_103 ( struct V_79 * V_80 ,
struct V_97 * V_98 ,
struct V_7 * V_8 ,
struct V_2 * V_36 )
{
struct V_23 * V_99 , * V_58 ;
int V_39 = 0 ;
V_117:
F_39 ( & V_36 -> V_17 ) ;
V_99 = F_73 ( V_36 ) ;
if ( ! V_99 )
goto V_118;
V_39 = F_100 ( V_80 , V_8 , V_98 , V_99 ) ;
if ( V_39 < 0 ) {
F_104 ( V_98 ) ;
goto V_118;
}
V_58 = V_99 ;
V_99 = F_76 ( V_58 ) ;
if ( V_99 && F_9 ( V_58 , V_99 ) ) {
V_98 -> V_114 [ 0 ] ++ ;
F_90 ( V_80 , V_8 , V_98 , V_99 ) ;
}
F_71 ( V_58 ) ;
F_102 ( V_98 -> V_48 [ 0 ] ) ;
F_104 ( V_98 ) ;
F_40 ( & V_36 -> V_17 ) ;
goto V_117;
V_118:
F_40 ( & V_36 -> V_17 ) ;
return V_39 ;
}
static int F_105 ( struct V_79 * V_80 ,
struct V_7 * V_8 ,
struct V_97 * V_98 ,
struct V_23 * V_54 )
{
struct V_23 * V_99 , * V_52 ;
struct V_103 * V_104 ;
struct V_57 V_26 ;
struct V_49 V_108 ;
int V_110 , V_111 , V_119 ;
int V_39 = 0 ;
F_18 ( ! V_98 -> V_48 [ 0 ] ) ;
V_104 = V_98 -> V_48 [ 0 ] ;
V_111 = V_98 -> V_114 [ 0 ] ;
V_119 = F_106 ( V_104 ) - 1 ;
if ( V_111 > V_119 )
return - V_120 ;
V_52 = V_54 ;
F_8 ( & V_108 ) ;
F_107 ( V_104 , & V_26 , V_111 ) ;
V_110 = 0 ;
while ( F_51 ( & V_52 -> V_26 , & V_26 ) == 0 ) {
F_30 ( & V_52 -> V_113 , & V_108 ) ;
V_110 ++ ;
V_99 = V_52 ;
V_52 = F_76 ( V_99 ) ;
if ( ! V_52 )
break;
if ( ! F_9 ( V_99 , V_52 ) )
break;
V_111 ++ ;
if ( V_111 > V_119 )
break;
F_107 ( V_104 , & V_26 , V_111 ) ;
}
if ( ! V_110 )
return 0 ;
V_39 = F_108 ( V_80 , V_8 , V_98 , V_98 -> V_114 [ 0 ] , V_110 ) ;
if ( V_39 )
goto V_51;
F_96 (curr, next, &head, tree_list) {
F_83 ( V_8 , V_99 ) ;
F_99 ( & V_99 -> V_113 ) ;
F_71 ( V_99 ) ;
}
V_51:
return V_39 ;
}
static int F_109 ( struct V_79 * V_80 ,
struct V_97 * V_98 ,
struct V_7 * V_8 ,
struct V_2 * V_36 )
{
struct V_23 * V_99 , * V_58 ;
int V_39 = 0 ;
V_117:
F_39 ( & V_36 -> V_17 ) ;
V_99 = F_75 ( V_36 ) ;
if ( ! V_99 )
goto V_121;
V_39 = F_110 ( V_80 , V_8 , & V_99 -> V_26 , V_98 , - 1 , 1 ) ;
if ( V_39 < 0 )
goto V_121;
else if ( V_39 > 0 ) {
V_58 = V_99 ;
V_99 = F_76 ( V_58 ) ;
F_71 ( V_58 ) ;
V_39 = 0 ;
F_104 ( V_98 ) ;
if ( V_99 ) {
F_40 ( & V_36 -> V_17 ) ;
goto V_117;
} else
goto V_121;
}
F_105 ( V_80 , V_8 , V_98 , V_99 ) ;
F_104 ( V_98 ) ;
F_40 ( & V_36 -> V_17 ) ;
goto V_117;
V_121:
F_104 ( V_98 ) ;
F_40 ( & V_36 -> V_17 ) ;
return V_39 ;
}
static void F_111 ( struct V_2 * V_6 )
{
struct V_30 * V_32 ;
if ( V_6 && V_6 -> V_13 ) {
F_18 ( ! V_6 -> V_8 ) ;
V_6 -> V_13 = 0 ;
V_6 -> V_11 -- ;
V_32 = V_6 -> V_8 -> V_31 -> V_32 ;
F_64 ( V_32 ) ;
}
}
static int F_112 ( struct V_79 * V_80 ,
struct V_7 * V_8 ,
struct V_97 * V_98 ,
struct V_2 * V_36 )
{
struct V_57 V_26 ;
struct V_122 * V_22 ;
struct V_103 * V_104 ;
int V_39 ;
V_26 . V_28 = V_36 -> V_9 ;
F_113 ( & V_26 , V_123 ) ;
V_26 . V_29 = 0 ;
V_39 = F_114 ( V_80 , V_8 , V_98 , & V_26 , 1 ) ;
if ( V_39 > 0 ) {
F_104 ( V_98 ) ;
return - V_120 ;
} else if ( V_39 < 0 ) {
return V_39 ;
}
F_115 ( V_98 , 1 ) ;
V_104 = V_98 -> V_48 [ 0 ] ;
V_22 = F_97 ( V_104 , V_98 -> V_114 [ 0 ] ,
struct V_122 ) ;
F_98 ( V_104 , & V_36 -> V_22 , ( unsigned long ) V_22 ,
sizeof( struct V_122 ) ) ;
F_102 ( V_104 ) ;
F_104 ( V_98 ) ;
F_89 ( V_8 , V_36 ) ;
F_111 ( V_36 ) ;
return 0 ;
}
static inline int F_116 ( struct V_79 * V_80 ,
struct V_7 * V_8 ,
struct V_97 * V_98 ,
struct V_2 * V_36 )
{
int V_39 ;
F_39 ( & V_36 -> V_17 ) ;
if ( ! V_36 -> V_13 ) {
F_40 ( & V_36 -> V_17 ) ;
return 0 ;
}
V_39 = F_112 ( V_80 , V_8 , V_98 , V_36 ) ;
F_40 ( & V_36 -> V_17 ) ;
return V_39 ;
}
static inline int
F_117 ( struct V_79 * V_80 ,
struct V_97 * V_98 ,
struct V_2 * V_36 )
{
int V_39 ;
V_39 = F_103 ( V_80 , V_98 , V_36 -> V_8 , V_36 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_109 ( V_80 , V_98 , V_36 -> V_8 , V_36 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_116 ( V_80 , V_36 -> V_8 , V_98 , V_36 ) ;
return V_39 ;
}
static int F_118 ( struct V_79 * V_80 ,
struct V_7 * V_8 , int V_124 )
{
struct V_30 * V_32 ;
struct V_2 * V_125 , * V_60 ;
struct V_97 * V_98 ;
struct V_81 * V_85 ;
int V_39 = 0 ;
bool V_11 = ( V_124 > 0 ) ;
if ( V_80 -> V_126 )
return - V_127 ;
V_98 = F_119 () ;
if ( ! V_98 )
return - V_5 ;
V_98 -> V_128 = 1 ;
V_85 = V_80 -> V_85 ;
V_80 -> V_85 = & V_8 -> V_31 -> V_86 ;
V_32 = F_10 ( V_8 ) ;
V_125 = F_34 ( V_32 ) ;
while ( V_125 && ( ! V_11 || ( V_11 && V_124 -- ) ) ) {
V_39 = F_117 ( V_80 , V_98 ,
V_125 ) ;
if ( V_39 ) {
F_44 ( V_125 ) ;
V_125 = NULL ;
F_120 ( V_80 , V_8 , V_39 ) ;
break;
}
V_60 = V_125 ;
V_125 = F_36 ( V_125 ) ;
F_44 ( V_60 ) ;
}
if ( V_125 )
F_44 ( V_125 ) ;
F_121 ( V_98 ) ;
V_80 -> V_85 = V_85 ;
return V_39 ;
}
int F_122 ( struct V_79 * V_80 ,
struct V_7 * V_8 )
{
return F_118 ( V_80 , V_8 , - 1 ) ;
}
int F_123 ( struct V_79 * V_80 ,
struct V_7 * V_8 , int V_124 )
{
return F_118 ( V_80 , V_8 , V_124 ) ;
}
int F_124 ( struct V_79 * V_80 ,
struct V_33 * V_33 )
{
struct V_2 * V_6 = F_11 ( V_33 ) ;
struct V_97 * V_98 ;
struct V_81 * V_85 ;
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
V_98 = F_119 () ;
if ( ! V_98 )
return - V_5 ;
V_98 -> V_128 = 1 ;
V_85 = V_80 -> V_85 ;
V_80 -> V_85 = & V_6 -> V_8 -> V_31 -> V_86 ;
V_39 = F_117 ( V_80 , V_98 , V_6 ) ;
F_44 ( V_6 ) ;
F_121 ( V_98 ) ;
V_80 -> V_85 = V_85 ;
return V_39 ;
}
int F_125 ( struct V_33 * V_33 )
{
struct V_79 * V_80 ;
struct V_2 * V_6 = F_11 ( V_33 ) ;
struct V_97 * V_98 ;
struct V_81 * V_85 ;
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
V_80 = F_126 ( V_6 -> V_8 ) ;
if ( F_127 ( V_80 ) ) {
V_39 = F_128 ( V_80 ) ;
goto V_51;
}
V_98 = F_119 () ;
if ( ! V_98 ) {
V_39 = - V_5 ;
goto V_129;
}
V_98 -> V_128 = 1 ;
V_85 = V_80 -> V_85 ;
V_80 -> V_85 = & V_6 -> V_8 -> V_31 -> V_86 ;
F_39 ( & V_6 -> V_17 ) ;
if ( V_6 -> V_13 )
V_39 = F_112 ( V_80 , V_6 -> V_8 ,
V_98 , V_6 ) ;
else
V_39 = 0 ;
F_40 ( & V_6 -> V_17 ) ;
F_121 ( V_98 ) ;
V_80 -> V_85 = V_85 ;
V_129:
F_129 ( V_80 , V_6 -> V_8 ) ;
F_130 ( V_6 -> V_8 ) ;
V_51:
F_44 ( V_6 ) ;
return V_39 ;
}
void F_131 ( struct V_33 * V_33 )
{
struct V_2 * V_6 ;
V_6 = F_14 ( F_12 ( V_33 ) -> V_6 ) ;
if ( ! V_6 )
return;
F_12 ( V_33 ) -> V_6 = NULL ;
F_44 ( V_6 ) ;
}
static void F_132 ( struct V_130 * V_131 )
{
struct V_132 * V_133 ;
struct V_30 * V_32 ;
struct V_79 * V_80 ;
struct V_97 * V_98 ;
struct V_2 * V_6 = NULL ;
struct V_7 * V_8 ;
struct V_81 * V_85 ;
int V_134 = 0 ;
V_133 = F_133 ( V_131 , struct V_132 , V_131 ) ;
V_32 = V_133 -> V_32 ;
V_98 = F_119 () ;
if ( ! V_98 )
goto V_51;
V_40:
if ( F_42 ( & V_32 -> V_70 ) < V_73 / 2 )
goto V_135;
V_6 = F_45 ( V_32 ) ;
if ( ! V_6 )
goto V_135;
V_98 -> V_128 = 1 ;
V_8 = V_6 -> V_8 ;
V_80 = F_126 ( V_8 ) ;
if ( F_127 ( V_80 ) )
goto V_136;
V_85 = V_80 -> V_85 ;
V_80 -> V_85 = & V_8 -> V_31 -> V_86 ;
F_117 ( V_80 , V_98 , V_6 ) ;
F_39 ( & V_6 -> V_17 ) ;
F_31 ( V_8 -> V_31 -> V_32 , V_6 ) ;
F_40 ( & V_6 -> V_17 ) ;
V_80 -> V_85 = V_85 ;
F_134 ( V_80 , V_8 ) ;
F_135 ( V_8 ) ;
V_136:
F_104 ( V_98 ) ;
V_134 ++ ;
F_46 ( V_6 ) ;
if ( V_133 -> V_124 == 0 || V_134 < V_133 -> V_124 )
goto V_40;
V_135:
F_121 ( V_98 ) ;
V_51:
F_68 ( & V_32 -> V_75 ) ;
F_72 ( V_133 ) ;
}
static int F_136 ( struct V_30 * V_32 ,
struct V_7 * V_8 , int V_124 )
{
struct V_132 * V_133 ;
if ( F_42 ( & V_32 -> V_70 ) < V_73 )
return 0 ;
V_133 = F_48 ( sizeof( * V_133 ) , V_41 ) ;
if ( ! V_133 )
return - V_5 ;
V_133 -> V_32 = V_32 ;
V_133 -> V_131 . V_137 = F_132 ;
V_133 -> V_131 . V_138 = 0 ;
V_133 -> V_124 = V_124 ;
F_137 ( & V_8 -> V_31 -> V_139 , & V_133 -> V_131 ) ;
return 0 ;
}
void F_138 ( struct V_7 * V_8 )
{
struct V_30 * V_32 ;
V_32 = F_10 ( V_8 ) ;
F_88 ( F_34 ( V_32 ) ) ;
}
static int F_139 ( struct V_30 * V_32 ,
int V_71 , int V_11 )
{
int V_140 = F_42 ( & V_32 -> V_72 ) ;
if ( V_140 < V_71 || V_140 >= V_71 + V_11 )
return 1 ;
return 0 ;
}
void F_140 ( struct V_7 * V_8 )
{
struct V_30 * V_32 ;
int V_71 ;
V_32 = F_10 ( V_8 ) ;
if ( F_42 ( & V_32 -> V_70 ) < V_73 )
return;
V_71 = F_42 ( & V_32 -> V_72 ) ;
if ( F_42 ( & V_32 -> V_70 ) >= V_141 ) {
int V_39 ;
F_141 ( V_142 ) ;
V_39 = F_136 ( V_32 , V_8 , 0 ) ;
if ( V_39 )
return;
while ( 1 ) {
F_142 ( & V_32 -> V_75 , & V_142 ,
V_143 ) ;
if ( F_139 ( V_32 , V_71 ,
V_74 ) ||
F_42 ( & V_32 -> V_70 ) <
V_73 ) {
break;
}
if ( ! F_143 ( V_144 ) )
F_144 () ;
else
break;
}
F_145 ( & V_32 -> V_75 , & V_142 ) ;
}
F_136 ( V_32 , V_8 , V_74 ) ;
}
int F_146 ( struct V_79 * V_80 ,
struct V_7 * V_8 , const char * V_145 ,
int V_146 , struct V_33 * V_147 ,
struct V_148 * V_149 , T_4 type ,
T_2 V_150 )
{
struct V_2 * V_6 ;
struct V_23 * V_61 ;
struct V_151 * V_152 ;
int V_39 ;
V_6 = F_20 ( V_147 ) ;
if ( F_127 ( V_6 ) )
return F_128 ( V_6 ) ;
V_61 = F_47 ( sizeof( * V_152 ) + V_146 ) ;
if ( ! V_61 ) {
V_39 = - V_5 ;
goto V_153;
}
V_61 -> V_26 . V_28 = F_13 ( V_147 ) ;
F_113 ( & V_61 -> V_26 , V_27 ) ;
V_61 -> V_26 . V_29 = V_150 ;
V_152 = (struct V_151 * ) V_61 -> V_115 ;
V_152 -> V_154 = * V_149 ;
V_152 -> V_155 = F_147 ( V_80 -> V_155 ) ;
V_152 -> V_53 = 0 ;
V_152 -> V_146 = F_148 ( V_146 ) ;
V_152 -> type = type ;
memcpy ( ( char * ) ( V_152 + 1 ) , V_145 , V_146 ) ;
V_39 = F_79 ( V_80 , V_8 , V_61 ) ;
F_18 ( V_39 ) ;
F_39 ( & V_6 -> V_17 ) ;
V_39 = F_62 ( V_6 , V_61 ) ;
if ( F_149 ( V_39 ) ) {
F_150 ( V_156 L_5
L_6
L_7 ,
V_145 ,
( unsigned long long ) V_6 -> V_8 -> V_28 ,
( unsigned long long ) V_6 -> V_9 ,
V_39 ) ;
F_59 () ;
}
F_40 ( & V_6 -> V_17 ) ;
V_153:
F_44 ( V_6 ) ;
return V_39 ;
}
static int F_151 ( struct V_7 * V_8 ,
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
F_83 ( V_8 , V_54 ) ;
F_71 ( V_54 ) ;
F_40 ( & V_36 -> V_17 ) ;
return 0 ;
}
int F_152 ( struct V_79 * V_80 ,
struct V_7 * V_8 , struct V_33 * V_147 ,
T_2 V_150 )
{
struct V_2 * V_36 ;
struct V_23 * V_54 ;
struct V_57 V_157 ;
int V_39 ;
V_36 = F_20 ( V_147 ) ;
if ( F_127 ( V_36 ) )
return F_128 ( V_36 ) ;
V_157 . V_28 = F_13 ( V_147 ) ;
F_113 ( & V_157 , V_27 ) ;
V_157 . V_29 = V_150 ;
V_39 = F_151 ( V_8 , V_36 , & V_157 ) ;
if ( ! V_39 )
goto V_158;
V_54 = F_47 ( 0 ) ;
if ( ! V_54 ) {
V_39 = - V_5 ;
goto V_158;
}
V_54 -> V_26 = V_157 ;
V_39 = F_79 ( V_80 , V_8 , V_54 ) ;
F_18 ( V_39 ) ;
F_39 ( & V_36 -> V_17 ) ;
V_39 = F_63 ( V_36 , V_54 ) ;
if ( F_149 ( V_39 ) ) {
F_150 ( V_156 L_8
L_9
L_7 ,
( unsigned long long ) V_150 ,
( unsigned long long ) V_36 -> V_8 -> V_28 ,
( unsigned long long ) V_36 -> V_9 ,
V_39 ) ;
F_59 () ;
}
F_40 ( & V_36 -> V_17 ) ;
V_158:
F_44 ( V_36 ) ;
return V_39 ;
}
int F_153 ( struct V_33 * V_33 )
{
struct V_2 * V_6 = F_11 ( V_33 ) ;
if ( ! V_6 )
return - V_120 ;
if ( ! V_6 -> V_18 ) {
F_44 ( V_6 ) ;
return - V_159 ;
}
F_12 ( V_33 ) -> V_18 = V_6 -> V_18 ;
F_44 ( V_6 ) ;
return 0 ;
}
void F_154 ( struct V_33 * V_33 , struct V_49 * V_160 ,
struct V_49 * V_161 )
{
struct V_2 * V_6 ;
struct V_23 * V_54 ;
V_6 = F_11 ( V_33 ) ;
if ( ! V_6 )
return;
F_39 ( & V_6 -> V_17 ) ;
V_54 = F_73 ( V_6 ) ;
while ( V_54 ) {
F_15 ( & V_54 -> V_10 ) ;
F_30 ( & V_54 -> V_162 , V_160 ) ;
V_54 = F_76 ( V_54 ) ;
}
V_54 = F_75 ( V_6 ) ;
while ( V_54 ) {
F_15 ( & V_54 -> V_10 ) ;
F_30 ( & V_54 -> V_162 , V_161 ) ;
V_54 = F_76 ( V_54 ) ;
}
F_40 ( & V_6 -> V_17 ) ;
F_32 ( & V_6 -> V_10 ) ;
}
void F_155 ( struct V_49 * V_160 ,
struct V_49 * V_161 )
{
struct V_23 * V_99 , * V_52 ;
F_96 (curr, next, ins_list, readdir_list) {
F_99 ( & V_99 -> V_162 ) ;
if ( F_41 ( & V_99 -> V_10 ) )
F_72 ( V_99 ) ;
}
F_96 (curr, next, del_list, readdir_list) {
F_99 ( & V_99 -> V_162 ) ;
if ( F_41 ( & V_99 -> V_10 ) )
F_72 ( V_99 ) ;
}
}
int F_156 ( struct V_49 * V_161 ,
T_2 V_150 )
{
struct V_23 * V_99 , * V_52 ;
int V_39 ;
if ( F_28 ( V_161 ) )
return 0 ;
F_96 (curr, next, del_list, readdir_list) {
if ( V_99 -> V_26 . V_29 > V_150 )
break;
F_99 ( & V_99 -> V_162 ) ;
V_39 = ( V_99 -> V_26 . V_29 == V_150 ) ;
if ( F_41 ( & V_99 -> V_10 ) )
F_72 ( V_99 ) ;
if ( V_39 )
return 1 ;
else
continue;
}
return 0 ;
}
int F_157 ( struct V_163 * V_164 , void * V_165 ,
T_5 V_166 ,
struct V_49 * V_160 )
{
struct V_151 * V_167 ;
struct V_23 * V_99 , * V_52 ;
struct V_57 V_154 ;
char * V_145 ;
int V_146 ;
int V_168 = 0 ;
unsigned char V_169 ;
if ( F_28 ( V_160 ) )
return 0 ;
F_96 (curr, next, ins_list, readdir_list) {
F_99 ( & V_99 -> V_162 ) ;
if ( V_99 -> V_26 . V_29 < V_164 -> V_170 ) {
if ( F_41 ( & V_99 -> V_10 ) )
F_72 ( V_99 ) ;
continue;
}
V_164 -> V_170 = V_99 -> V_26 . V_29 ;
V_167 = (struct V_151 * ) V_99 -> V_115 ;
V_145 = ( char * ) ( V_167 + 1 ) ;
V_146 = F_158 ( V_167 -> V_146 ) ;
V_169 = V_171 [ V_167 -> type ] ;
F_159 ( & V_154 , & V_167 -> V_154 ) ;
V_168 = V_166 ( V_165 , V_145 , V_146 , V_99 -> V_26 . V_29 ,
V_154 . V_28 , V_169 ) ;
if ( F_41 ( & V_99 -> V_10 ) )
F_72 ( V_99 ) ;
if ( V_168 )
return 1 ;
}
return 0 ;
}
static void F_160 ( struct V_79 * V_80 ,
struct V_122 * V_22 ,
struct V_33 * V_33 )
{
F_161 ( V_22 , F_162 ( V_33 ) ) ;
F_163 ( V_22 , F_164 ( V_33 ) ) ;
F_165 ( V_22 , F_12 ( V_33 ) -> V_172 ) ;
F_166 ( V_22 , V_33 -> V_173 ) ;
F_167 ( V_22 , V_33 -> V_174 ) ;
F_168 ( V_22 , F_169 ( V_33 ) ) ;
F_170 ( V_22 ,
F_12 ( V_33 ) -> V_175 ) ;
F_171 ( V_22 , V_33 -> V_176 ) ;
F_172 ( V_22 , V_80 -> V_155 ) ;
F_173 ( V_22 , V_33 -> V_177 ) ;
F_174 ( V_22 , F_12 ( V_33 ) -> V_138 ) ;
F_175 ( V_22 , 0 ) ;
F_176 ( F_177 ( V_22 ) ,
V_33 -> V_178 . V_179 ) ;
F_178 ( F_177 ( V_22 ) ,
V_33 -> V_178 . V_180 ) ;
F_176 ( F_179 ( V_22 ) ,
V_33 -> V_181 . V_179 ) ;
F_178 ( F_179 ( V_22 ) ,
V_33 -> V_181 . V_180 ) ;
F_176 ( F_180 ( V_22 ) ,
V_33 -> V_182 . V_179 ) ;
F_178 ( F_180 ( V_22 ) ,
V_33 -> V_182 . V_180 ) ;
}
int F_181 ( struct V_33 * V_33 , T_3 * V_183 )
{
struct V_2 * V_6 ;
struct V_122 * V_22 ;
struct V_184 * V_185 ;
V_6 = F_11 ( V_33 ) ;
if ( ! V_6 )
return - V_120 ;
F_39 ( & V_6 -> V_17 ) ;
if ( ! V_6 -> V_13 ) {
F_40 ( & V_6 -> V_17 ) ;
F_44 ( V_6 ) ;
return - V_120 ;
}
V_22 = & V_6 -> V_22 ;
F_182 ( V_33 , F_183 ( V_22 ) ) ;
F_184 ( V_33 , F_185 ( V_22 ) ) ;
F_186 ( V_33 , F_187 ( V_22 ) ) ;
V_33 -> V_173 = F_188 ( V_22 ) ;
F_189 ( V_33 , F_190 ( V_22 ) ) ;
F_191 ( V_33 , F_192 ( V_22 ) ) ;
F_12 ( V_33 ) -> V_175 = F_193 ( V_22 ) ;
V_33 -> V_176 = F_194 ( V_22 ) ;
V_33 -> V_177 = 0 ;
* V_183 = F_195 ( V_22 ) ;
F_12 ( V_33 ) -> V_138 = F_196 ( V_22 ) ;
V_185 = F_177 ( V_22 ) ;
V_33 -> V_178 . V_179 = F_197 ( V_185 ) ;
V_33 -> V_178 . V_180 = F_198 ( V_185 ) ;
V_185 = F_179 ( V_22 ) ;
V_33 -> V_181 . V_179 = F_197 ( V_185 ) ;
V_33 -> V_181 . V_180 = F_198 ( V_185 ) ;
V_185 = F_180 ( V_22 ) ;
V_33 -> V_182 . V_179 = F_197 ( V_185 ) ;
V_33 -> V_182 . V_180 = F_198 ( V_185 ) ;
V_33 -> V_186 = F_12 ( V_33 ) -> V_175 ;
F_12 ( V_33 ) -> V_18 = ( T_2 ) - 1 ;
F_40 ( & V_6 -> V_17 ) ;
F_44 ( V_6 ) ;
return 0 ;
}
int F_199 ( struct V_79 * V_80 ,
struct V_7 * V_8 , struct V_33 * V_33 )
{
struct V_2 * V_6 ;
int V_39 = 0 ;
V_6 = F_20 ( V_33 ) ;
if ( F_127 ( V_6 ) )
return F_128 ( V_6 ) ;
F_39 ( & V_6 -> V_17 ) ;
if ( V_6 -> V_13 ) {
F_160 ( V_80 , & V_6 -> V_22 , V_33 ) ;
goto V_153;
}
V_39 = F_85 ( V_80 , V_8 , V_33 ,
V_6 ) ;
if ( V_39 )
goto V_153;
F_160 ( V_80 , & V_6 -> V_22 , V_33 ) ;
V_6 -> V_13 = 1 ;
V_6 -> V_11 ++ ;
F_15 ( & V_8 -> V_31 -> V_32 -> V_70 ) ;
V_153:
F_40 ( & V_6 -> V_17 ) ;
F_44 ( V_6 ) ;
return V_39 ;
}
static void F_200 ( struct V_2 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_23 * V_187 , * V_188 ;
F_39 ( & V_6 -> V_17 ) ;
V_187 = F_73 ( V_6 ) ;
while ( V_187 ) {
F_83 ( V_8 , V_187 ) ;
V_188 = V_187 ;
V_187 = F_76 ( V_188 ) ;
F_71 ( V_188 ) ;
}
V_187 = F_75 ( V_6 ) ;
while ( V_187 ) {
F_83 ( V_8 , V_187 ) ;
V_188 = V_187 ;
V_187 = F_76 ( V_188 ) ;
F_71 ( V_188 ) ;
}
if ( V_6 -> V_13 ) {
F_89 ( V_8 , V_6 ) ;
F_111 ( V_6 ) ;
}
F_40 ( & V_6 -> V_17 ) ;
}
void F_201 ( struct V_33 * V_33 )
{
struct V_2 * V_6 ;
V_6 = F_11 ( V_33 ) ;
if ( ! V_6 )
return;
F_200 ( V_6 ) ;
F_44 ( V_6 ) ;
}
void F_202 ( struct V_7 * V_8 )
{
T_2 V_9 = 0 ;
struct V_2 * V_189 [ 8 ] ;
int V_111 , V_190 ;
while ( 1 ) {
F_16 ( & V_8 -> V_37 ) ;
V_190 = F_203 ( & V_8 -> V_38 ,
( void * * ) V_189 , V_9 ,
F_204 ( V_189 ) ) ;
if ( ! V_190 ) {
F_19 ( & V_8 -> V_37 ) ;
break;
}
V_9 = V_189 [ V_190 - 1 ] -> V_9 + 1 ;
for ( V_111 = 0 ; V_111 < V_190 ; V_111 ++ )
F_15 ( & V_189 [ V_111 ] -> V_10 ) ;
F_19 ( & V_8 -> V_37 ) ;
for ( V_111 = 0 ; V_111 < V_190 ; V_111 ++ ) {
F_200 ( V_189 [ V_111 ] ) ;
F_44 ( V_189 [ V_111 ] ) ;
}
}
}
void F_205 ( struct V_7 * V_8 )
{
struct V_30 * V_32 ;
struct V_2 * V_125 , * V_60 ;
V_32 = F_10 ( V_8 ) ;
V_125 = F_34 ( V_32 ) ;
while ( V_125 ) {
F_200 ( V_125 ) ;
V_60 = V_125 ;
V_125 = F_36 ( V_125 ) ;
F_44 ( V_60 ) ;
}
}
