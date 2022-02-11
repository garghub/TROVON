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
static void F_64 ( struct V_23 * V_61 )
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
F_65 ( & V_61 -> V_59 , V_8 ) ;
V_61 -> V_6 -> V_11 -- ;
if ( F_66 ( & V_32 -> V_70 ) <
V_71 &&
F_67 ( & V_32 -> V_72 ) )
F_68 ( & V_32 -> V_72 ) ;
}
static void F_69 ( struct V_23 * V_54 )
{
if ( V_54 ) {
F_64 ( V_54 ) ;
if ( F_41 ( & V_54 -> V_10 ) )
F_70 ( V_54 ) ;
}
}
struct V_23 * F_71 (
struct V_2 * V_6 )
{
struct V_59 * V_50 ;
struct V_23 * V_54 = NULL ;
V_50 = F_72 ( & V_6 -> V_14 ) ;
if ( V_50 )
V_54 = F_50 ( V_50 , struct V_23 , V_59 ) ;
return V_54 ;
}
struct V_23 * F_73 (
struct V_2 * V_6 )
{
struct V_59 * V_50 ;
struct V_23 * V_54 = NULL ;
V_50 = F_72 ( & V_6 -> V_16 ) ;
if ( V_50 )
V_54 = F_50 ( V_50 , struct V_23 , V_59 ) ;
return V_54 ;
}
struct V_23 * F_74 (
struct V_23 * V_54 )
{
struct V_59 * V_50 ;
struct V_23 * V_52 = NULL ;
V_50 = F_53 ( & V_54 -> V_59 ) ;
if ( V_50 )
V_52 = F_50 ( V_50 , struct V_23 , V_59 ) ;
return V_52 ;
}
static inline struct V_7 * F_75 ( struct V_7 * V_8 ,
T_2 V_73 )
{
struct V_57 V_74 ;
if ( V_8 -> V_28 == V_73 )
return V_8 ;
V_74 . V_28 = V_73 ;
V_74 . type = V_75 ;
V_74 . V_29 = ( T_2 ) - 1 ;
return F_76 ( V_8 -> V_31 , & V_74 ) ;
}
static int F_77 ( struct V_76 * V_77 ,
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
V_81 = F_78 ( V_8 , 1 ) ;
V_39 = F_79 ( V_79 , V_80 , V_81 ) ;
if ( ! V_39 ) {
F_80 ( V_8 -> V_31 , L_2 ,
V_54 -> V_26 . V_28 ,
V_81 , 1 ) ;
V_54 -> V_21 = V_81 ;
}
return V_39 ;
}
static void F_81 ( struct V_7 * V_8 ,
struct V_23 * V_54 )
{
struct V_78 * V_84 ;
if ( ! V_54 -> V_21 )
return;
V_84 = & V_8 -> V_31 -> V_83 ;
F_80 ( V_8 -> V_31 , L_2 ,
V_54 -> V_26 . V_28 , V_54 -> V_21 ,
0 ) ;
F_82 ( V_8 , V_84 ,
V_54 -> V_21 ) ;
}
static int F_83 (
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
V_81 = F_78 ( V_8 , 1 ) ;
if ( ! V_79 || ( ! V_77 -> V_21 &&
V_79 -> type != V_86 ) ) {
V_39 = F_84 ( V_8 , V_80 , V_81 ) ;
if ( V_39 == - V_87 )
V_39 = - V_88 ;
if ( ! V_39 ) {
V_36 -> V_21 = V_81 ;
F_80 ( V_8 -> V_31 ,
L_3 ,
F_13 ( V_33 ) ,
V_81 , 1 ) ;
}
return V_39 ;
} else if ( V_79 -> type == V_86 ) {
F_16 ( & F_12 ( V_33 ) -> V_45 ) ;
if ( F_85 ( V_89 ,
& F_12 ( V_33 ) -> V_90 ) ) {
F_19 ( & F_12 ( V_33 ) -> V_45 ) ;
V_85 = true ;
goto V_91;
}
F_19 ( & F_12 ( V_33 ) -> V_45 ) ;
V_39 = F_84 ( V_8 , V_80 , V_81 ) ;
if ( ! V_39 )
goto V_51;
V_39 = F_79 ( V_79 , V_80 , V_81 ) ;
if ( ! V_39 )
goto V_51;
F_86 ( 1 ) ;
V_39 = F_79 ( & V_8 -> V_31 -> V_92 ,
V_80 , V_81 ) ;
goto V_51;
}
V_91:
V_39 = F_79 ( V_79 , V_80 , V_81 ) ;
V_51:
if ( ! V_39 ) {
F_80 ( V_8 -> V_31 , L_3 ,
F_13 ( V_33 ) , V_81 , 1 ) ;
V_36 -> V_21 = V_81 ;
}
if ( V_85 ) {
F_80 ( V_8 -> V_31 , L_4 ,
F_13 ( V_33 ) , V_81 , 0 ) ;
F_82 ( V_8 , V_79 , V_81 ) ;
}
return V_39 ;
}
static void F_87 ( struct V_7 * V_8 ,
struct V_2 * V_36 )
{
struct V_78 * V_84 ;
if ( ! V_36 -> V_21 )
return;
V_84 = & V_8 -> V_31 -> V_83 ;
F_80 ( V_8 -> V_31 , L_3 ,
V_36 -> V_9 , V_36 -> V_21 , 0 ) ;
F_82 ( V_8 , V_84 ,
V_36 -> V_21 ) ;
V_36 -> V_21 = 0 ;
}
static int F_88 ( struct V_76 * V_77 ,
struct V_7 * V_8 ,
struct V_93 * V_94 ,
struct V_23 * V_54 )
{
struct V_23 * V_95 , * V_52 ;
int V_96 ;
int V_97 = 0 , V_98 = 0 ;
struct V_99 * V_100 ;
char * V_101 ;
struct V_57 * V_102 ;
T_3 * V_103 ;
struct V_49 V_104 ;
int V_105 ;
int V_106 ;
int V_107 ;
int V_39 = 0 ;
F_18 ( ! V_94 -> V_48 [ 0 ] ) ;
V_100 = V_94 -> V_48 [ 0 ] ;
V_96 = F_89 ( V_8 , V_100 ) ;
F_8 ( & V_104 ) ;
V_52 = V_54 ;
V_106 = 0 ;
while ( V_98 + V_52 -> V_53 + sizeof( struct V_108 ) <=
V_96 ) {
V_97 += V_52 -> V_53 ;
V_98 += V_52 -> V_53 + sizeof( struct V_108 ) ;
F_30 ( & V_52 -> V_109 , & V_104 ) ;
V_106 ++ ;
V_95 = V_52 ;
V_52 = F_74 ( V_95 ) ;
if ( ! V_52 )
break;
if ( ! F_9 ( V_95 , V_52 ) )
break;
}
if ( ! V_106 ) {
V_39 = 0 ;
goto V_51;
}
F_90 ( V_94 ) ;
V_102 = F_48 ( sizeof( struct V_57 ) * V_106 , V_41 ) ;
if ( ! V_102 ) {
V_39 = - V_5 ;
goto V_51;
}
V_103 = F_48 ( sizeof( T_3 ) * V_106 , V_41 ) ;
if ( ! V_103 ) {
V_39 = - V_5 ;
goto error;
}
V_107 = 0 ;
F_91 (next, &head, tree_list) {
V_102 [ V_107 ] = V_52 -> V_26 ;
V_103 [ V_107 ] = V_52 -> V_53 ;
V_107 ++ ;
}
F_92 ( V_94 , NULL , 0 ) ;
F_93 ( V_77 , V_8 , V_94 , V_102 , V_103 ,
V_97 , V_98 , V_106 ) ;
V_105 = V_94 -> V_110 [ 0 ] ;
F_94 (curr, next, &head, tree_list) {
V_101 = F_95 ( V_100 , V_105 , char ) ;
F_96 ( V_100 , & V_95 -> V_111 ,
( unsigned long ) V_101 ,
V_95 -> V_53 ) ;
V_105 ++ ;
F_81 ( V_8 , V_95 ) ;
F_97 ( & V_95 -> V_109 ) ;
F_69 ( V_95 ) ;
}
error:
F_70 ( V_103 ) ;
F_70 ( V_102 ) ;
V_51:
return V_39 ;
}
static int F_98 ( struct V_76 * V_77 ,
struct V_7 * V_8 ,
struct V_93 * V_94 ,
struct V_23 * V_61 )
{
struct V_99 * V_100 ;
struct V_108 * V_54 ;
char * V_112 ;
int V_39 ;
V_39 = F_99 ( V_77 , V_8 , V_94 , & V_61 -> V_26 ,
V_61 -> V_53 ) ;
if ( V_39 < 0 && V_39 != - V_43 )
return V_39 ;
V_100 = V_94 -> V_48 [ 0 ] ;
V_54 = F_100 ( V_100 , V_94 -> V_110 [ 0 ] ) ;
V_112 = F_95 ( V_100 , V_94 -> V_110 [ 0 ] , char ) ;
F_96 ( V_100 , V_61 -> V_111 , ( unsigned long ) V_112 ,
V_61 -> V_53 ) ;
F_101 ( V_100 ) ;
F_81 ( V_8 , V_61 ) ;
return 0 ;
}
static int F_102 ( struct V_76 * V_77 ,
struct V_93 * V_94 ,
struct V_7 * V_8 ,
struct V_2 * V_36 )
{
struct V_23 * V_95 , * V_58 ;
int V_39 = 0 ;
V_113:
F_39 ( & V_36 -> V_17 ) ;
V_95 = F_71 ( V_36 ) ;
if ( ! V_95 )
goto V_114;
V_39 = F_98 ( V_77 , V_8 , V_94 , V_95 ) ;
if ( V_39 < 0 ) {
F_103 ( V_94 ) ;
goto V_114;
}
V_58 = V_95 ;
V_95 = F_74 ( V_58 ) ;
if ( V_95 && F_9 ( V_58 , V_95 ) ) {
V_94 -> V_110 [ 0 ] ++ ;
F_88 ( V_77 , V_8 , V_94 , V_95 ) ;
}
F_69 ( V_58 ) ;
F_101 ( V_94 -> V_48 [ 0 ] ) ;
F_103 ( V_94 ) ;
F_40 ( & V_36 -> V_17 ) ;
goto V_113;
V_114:
F_40 ( & V_36 -> V_17 ) ;
return V_39 ;
}
static int F_104 ( struct V_76 * V_77 ,
struct V_7 * V_8 ,
struct V_93 * V_94 ,
struct V_23 * V_54 )
{
struct V_23 * V_95 , * V_52 ;
struct V_99 * V_100 ;
struct V_57 V_26 ;
struct V_49 V_104 ;
int V_106 , V_107 , V_115 ;
int V_39 = 0 ;
F_18 ( ! V_94 -> V_48 [ 0 ] ) ;
V_100 = V_94 -> V_48 [ 0 ] ;
V_107 = V_94 -> V_110 [ 0 ] ;
V_115 = F_105 ( V_100 ) - 1 ;
if ( V_107 > V_115 )
return - V_116 ;
V_52 = V_54 ;
F_8 ( & V_104 ) ;
F_106 ( V_100 , & V_26 , V_107 ) ;
V_106 = 0 ;
while ( F_51 ( & V_52 -> V_26 , & V_26 ) == 0 ) {
F_30 ( & V_52 -> V_109 , & V_104 ) ;
V_106 ++ ;
V_95 = V_52 ;
V_52 = F_74 ( V_95 ) ;
if ( ! V_52 )
break;
if ( ! F_9 ( V_95 , V_52 ) )
break;
V_107 ++ ;
if ( V_107 > V_115 )
break;
F_106 ( V_100 , & V_26 , V_107 ) ;
}
if ( ! V_106 )
return 0 ;
V_39 = F_107 ( V_77 , V_8 , V_94 , V_94 -> V_110 [ 0 ] , V_106 ) ;
if ( V_39 )
goto V_51;
F_94 (curr, next, &head, tree_list) {
F_81 ( V_8 , V_95 ) ;
F_97 ( & V_95 -> V_109 ) ;
F_69 ( V_95 ) ;
}
V_51:
return V_39 ;
}
static int F_108 ( struct V_76 * V_77 ,
struct V_93 * V_94 ,
struct V_7 * V_8 ,
struct V_2 * V_36 )
{
struct V_23 * V_95 , * V_58 ;
int V_39 = 0 ;
V_113:
F_39 ( & V_36 -> V_17 ) ;
V_95 = F_73 ( V_36 ) ;
if ( ! V_95 )
goto V_117;
V_39 = F_109 ( V_77 , V_8 , & V_95 -> V_26 , V_94 , - 1 , 1 ) ;
if ( V_39 < 0 )
goto V_117;
else if ( V_39 > 0 ) {
V_58 = V_95 ;
V_95 = F_74 ( V_58 ) ;
F_69 ( V_58 ) ;
V_39 = 0 ;
F_103 ( V_94 ) ;
if ( V_95 ) {
F_40 ( & V_36 -> V_17 ) ;
goto V_113;
} else
goto V_117;
}
F_104 ( V_77 , V_8 , V_94 , V_95 ) ;
F_103 ( V_94 ) ;
F_40 ( & V_36 -> V_17 ) ;
goto V_113;
V_117:
F_103 ( V_94 ) ;
F_40 ( & V_36 -> V_17 ) ;
return V_39 ;
}
static void F_110 ( struct V_2 * V_6 )
{
struct V_30 * V_32 ;
if ( V_6 && V_6 -> V_13 ) {
F_18 ( ! V_6 -> V_8 ) ;
V_6 -> V_13 = 0 ;
V_6 -> V_11 -- ;
V_32 = V_6 -> V_8 -> V_31 -> V_32 ;
if ( F_66 ( & V_32 -> V_70 ) <
V_71 &&
F_67 ( & V_32 -> V_72 ) )
F_68 ( & V_32 -> V_72 ) ;
}
}
static int F_111 ( struct V_76 * V_77 ,
struct V_7 * V_8 ,
struct V_93 * V_94 ,
struct V_2 * V_36 )
{
struct V_57 V_26 ;
struct V_118 * V_22 ;
struct V_99 * V_100 ;
int V_39 ;
F_39 ( & V_36 -> V_17 ) ;
if ( ! V_36 -> V_13 ) {
F_40 ( & V_36 -> V_17 ) ;
return 0 ;
}
V_26 . V_28 = V_36 -> V_9 ;
F_112 ( & V_26 , V_119 ) ;
V_26 . V_29 = 0 ;
V_39 = F_113 ( V_77 , V_8 , V_94 , & V_26 , 1 ) ;
if ( V_39 > 0 ) {
F_103 ( V_94 ) ;
F_40 ( & V_36 -> V_17 ) ;
return - V_116 ;
} else if ( V_39 < 0 ) {
F_40 ( & V_36 -> V_17 ) ;
return V_39 ;
}
F_114 ( V_94 , 1 ) ;
V_100 = V_94 -> V_48 [ 0 ] ;
V_22 = F_95 ( V_100 , V_94 -> V_110 [ 0 ] ,
struct V_118 ) ;
F_96 ( V_100 , & V_36 -> V_22 , ( unsigned long ) V_22 ,
sizeof( struct V_118 ) ) ;
F_101 ( V_100 ) ;
F_103 ( V_94 ) ;
F_87 ( V_8 , V_36 ) ;
F_110 ( V_36 ) ;
F_40 ( & V_36 -> V_17 ) ;
return 0 ;
}
static int F_115 ( struct V_76 * V_77 ,
struct V_7 * V_8 , int V_120 )
{
struct V_7 * V_121 = V_8 ;
struct V_30 * V_32 ;
struct V_2 * V_122 , * V_60 ;
struct V_93 * V_94 ;
struct V_78 * V_82 ;
int V_39 = 0 ;
bool V_11 = ( V_120 > 0 ) ;
if ( V_77 -> V_123 )
return - V_124 ;
V_94 = F_116 () ;
if ( ! V_94 )
return - V_5 ;
V_94 -> V_125 = 1 ;
V_82 = V_77 -> V_82 ;
V_77 -> V_82 = & V_8 -> V_31 -> V_83 ;
V_32 = F_10 ( V_8 ) ;
V_122 = F_34 ( V_32 ) ;
while ( V_122 && ( ! V_11 || ( V_11 && V_120 -- ) ) ) {
V_121 = V_122 -> V_8 ;
V_39 = F_102 ( V_77 , V_94 , V_121 ,
V_122 ) ;
if ( ! V_39 )
V_39 = F_108 ( V_77 , V_94 ,
V_121 , V_122 ) ;
if ( ! V_39 )
V_39 = F_111 ( V_77 , V_121 ,
V_94 , V_122 ) ;
if ( V_39 ) {
F_44 ( V_122 ) ;
V_122 = NULL ;
F_117 ( V_77 , V_8 , V_39 ) ;
break;
}
V_60 = V_122 ;
V_122 = F_36 ( V_122 ) ;
F_44 ( V_60 ) ;
}
if ( V_122 )
F_44 ( V_122 ) ;
F_118 ( V_94 ) ;
V_77 -> V_82 = V_82 ;
return V_39 ;
}
int F_119 ( struct V_76 * V_77 ,
struct V_7 * V_8 )
{
return F_115 ( V_77 , V_8 , - 1 ) ;
}
int F_120 ( struct V_76 * V_77 ,
struct V_7 * V_8 , int V_120 )
{
return F_115 ( V_77 , V_8 , V_120 ) ;
}
static int F_121 ( struct V_76 * V_77 ,
struct V_2 * V_36 )
{
struct V_93 * V_94 ;
struct V_78 * V_82 ;
int V_39 ;
V_94 = F_116 () ;
if ( ! V_94 )
return - V_5 ;
V_94 -> V_125 = 1 ;
V_82 = V_77 -> V_82 ;
V_77 -> V_82 = & V_36 -> V_8 -> V_31 -> V_83 ;
V_39 = F_102 ( V_77 , V_94 , V_36 -> V_8 , V_36 ) ;
if ( ! V_39 )
V_39 = F_108 ( V_77 , V_94 , V_36 -> V_8 , V_36 ) ;
if ( ! V_39 )
V_39 = F_111 ( V_77 , V_36 -> V_8 , V_94 , V_36 ) ;
F_118 ( V_94 ) ;
V_77 -> V_82 = V_82 ;
return V_39 ;
}
int F_122 ( struct V_76 * V_77 ,
struct V_33 * V_33 )
{
struct V_2 * V_6 = F_11 ( V_33 ) ;
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
V_39 = F_121 ( V_77 , V_6 ) ;
F_44 ( V_6 ) ;
return V_39 ;
}
void F_123 ( struct V_33 * V_33 )
{
struct V_2 * V_6 ;
V_6 = F_14 ( F_12 ( V_33 ) -> V_6 ) ;
if ( ! V_6 )
return;
F_12 ( V_33 ) -> V_6 = NULL ;
F_44 ( V_6 ) ;
}
static void F_124 ( struct V_126 * V_127 )
{
struct V_128 * V_129 ;
struct V_76 * V_77 ;
struct V_93 * V_94 ;
struct V_2 * V_6 = NULL ;
struct V_7 * V_8 ;
struct V_78 * V_82 ;
unsigned long V_120 = 0 ;
int V_130 = 0 ;
int V_39 ;
V_129 = F_125 ( V_127 , struct V_128 , V_127 ) ;
V_94 = F_116 () ;
if ( ! V_94 )
goto V_51;
V_94 -> V_125 = 1 ;
V_6 = V_129 -> V_6 ;
V_8 = V_6 -> V_8 ;
V_77 = F_126 ( V_8 ) ;
if ( F_127 ( V_77 ) )
goto V_131;
V_82 = V_77 -> V_82 ;
V_77 -> V_82 = & V_8 -> V_31 -> V_83 ;
V_39 = F_102 ( V_77 , V_94 , V_8 , V_6 ) ;
if ( ! V_39 )
V_39 = F_108 ( V_77 , V_94 , V_8 ,
V_6 ) ;
if ( ! V_39 )
F_111 ( V_77 , V_8 , V_94 , V_6 ) ;
F_39 ( & V_6 -> V_17 ) ;
if ( V_6 -> V_11 )
V_130 = 1 ;
else
F_31 ( V_8 -> V_31 -> V_32 ,
V_6 ) ;
F_40 ( & V_6 -> V_17 ) ;
V_120 = V_77 -> V_132 ;
V_77 -> V_82 = V_82 ;
F_128 ( V_77 , V_8 ) ;
F_129 ( V_8 , V_120 ) ;
V_131:
F_118 ( V_94 ) ;
V_51:
if ( V_130 )
F_130 ( & V_129 -> V_127 ) ;
else {
F_46 ( V_6 ) ;
F_70 ( V_129 ) ;
}
}
static int F_131 ( struct V_30 * V_32 ,
struct V_7 * V_8 , int V_133 )
{
struct V_128 * V_129 ;
struct V_2 * V_95 ;
int V_11 = 0 ;
V_40:
V_95 = F_45 ( V_32 ) ;
if ( ! V_95 )
return 0 ;
V_129 = F_48 ( sizeof( * V_129 ) , V_41 ) ;
if ( ! V_129 ) {
F_46 ( V_95 ) ;
return - V_5 ;
}
V_129 -> V_8 = V_8 ;
V_129 -> V_6 = V_95 ;
V_129 -> V_127 . V_134 = F_124 ;
V_129 -> V_127 . V_135 = 0 ;
F_132 ( & V_8 -> V_31 -> V_136 , & V_129 -> V_127 ) ;
V_11 ++ ;
if ( V_133 || V_11 < 4 )
goto V_40;
return 0 ;
}
void F_133 ( struct V_7 * V_8 )
{
struct V_30 * V_32 ;
V_32 = F_10 ( V_8 ) ;
F_86 ( F_34 ( V_32 ) ) ;
}
void F_134 ( struct V_7 * V_8 )
{
struct V_30 * V_32 ;
V_32 = F_10 ( V_8 ) ;
if ( F_42 ( & V_32 -> V_70 ) < V_71 )
return;
if ( F_42 ( & V_32 -> V_70 ) >= V_137 ) {
int V_39 ;
V_39 = F_131 ( V_32 , V_8 , 1 ) ;
if ( V_39 )
return;
F_135 (
V_32 -> V_72 ,
( F_42 ( & V_32 -> V_70 ) <
V_71 ) ,
V_138 ) ;
return;
}
F_131 ( V_32 , V_8 , 0 ) ;
}
int F_136 ( struct V_76 * V_77 ,
struct V_7 * V_8 , const char * V_139 ,
int V_140 , struct V_33 * V_141 ,
struct V_142 * V_143 , T_4 type ,
T_2 V_144 )
{
struct V_2 * V_6 ;
struct V_23 * V_61 ;
struct V_145 * V_146 ;
int V_39 ;
V_6 = F_20 ( V_141 ) ;
if ( F_127 ( V_6 ) )
return F_137 ( V_6 ) ;
V_61 = F_47 ( sizeof( * V_146 ) + V_140 ) ;
if ( ! V_61 ) {
V_39 = - V_5 ;
goto V_147;
}
V_61 -> V_26 . V_28 = F_13 ( V_141 ) ;
F_112 ( & V_61 -> V_26 , V_27 ) ;
V_61 -> V_26 . V_29 = V_144 ;
V_146 = (struct V_145 * ) V_61 -> V_111 ;
V_146 -> V_148 = * V_143 ;
V_146 -> V_149 = F_138 ( V_77 -> V_149 ) ;
V_146 -> V_53 = 0 ;
V_146 -> V_140 = F_139 ( V_140 ) ;
V_146 -> type = type ;
memcpy ( ( char * ) ( V_146 + 1 ) , V_139 , V_140 ) ;
V_39 = F_77 ( V_77 , V_8 , V_61 ) ;
F_18 ( V_39 ) ;
F_39 ( & V_6 -> V_17 ) ;
V_39 = F_62 ( V_6 , V_61 ) ;
if ( F_140 ( V_39 ) ) {
F_141 ( V_150 L_5
L_6
L_7 ,
V_139 ,
( unsigned long long ) V_6 -> V_8 -> V_28 ,
( unsigned long long ) V_6 -> V_9 ,
V_39 ) ;
F_59 () ;
}
F_40 ( & V_6 -> V_17 ) ;
V_147:
F_44 ( V_6 ) ;
return V_39 ;
}
static int F_142 ( struct V_7 * V_8 ,
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
F_81 ( V_8 , V_54 ) ;
F_69 ( V_54 ) ;
F_40 ( & V_36 -> V_17 ) ;
return 0 ;
}
int F_143 ( struct V_76 * V_77 ,
struct V_7 * V_8 , struct V_33 * V_141 ,
T_2 V_144 )
{
struct V_2 * V_36 ;
struct V_23 * V_54 ;
struct V_57 V_151 ;
int V_39 ;
V_36 = F_20 ( V_141 ) ;
if ( F_127 ( V_36 ) )
return F_137 ( V_36 ) ;
V_151 . V_28 = F_13 ( V_141 ) ;
F_112 ( & V_151 , V_27 ) ;
V_151 . V_29 = V_144 ;
V_39 = F_142 ( V_8 , V_36 , & V_151 ) ;
if ( ! V_39 )
goto V_152;
V_54 = F_47 ( 0 ) ;
if ( ! V_54 ) {
V_39 = - V_5 ;
goto V_152;
}
V_54 -> V_26 = V_151 ;
V_39 = F_77 ( V_77 , V_8 , V_54 ) ;
F_18 ( V_39 ) ;
F_39 ( & V_36 -> V_17 ) ;
V_39 = F_63 ( V_36 , V_54 ) ;
if ( F_140 ( V_39 ) ) {
F_141 ( V_150 L_8
L_9
L_7 ,
( unsigned long long ) V_144 ,
( unsigned long long ) V_36 -> V_8 -> V_28 ,
( unsigned long long ) V_36 -> V_9 ,
V_39 ) ;
F_59 () ;
}
F_40 ( & V_36 -> V_17 ) ;
V_152:
F_44 ( V_36 ) ;
return V_39 ;
}
int F_144 ( struct V_33 * V_33 )
{
struct V_2 * V_6 = F_11 ( V_33 ) ;
if ( ! V_6 )
return - V_116 ;
if ( ! V_6 -> V_18 ) {
F_44 ( V_6 ) ;
return - V_153 ;
}
F_12 ( V_33 ) -> V_18 = V_6 -> V_18 ;
F_44 ( V_6 ) ;
return 0 ;
}
void F_145 ( struct V_33 * V_33 , struct V_49 * V_154 ,
struct V_49 * V_155 )
{
struct V_2 * V_6 ;
struct V_23 * V_54 ;
V_6 = F_11 ( V_33 ) ;
if ( ! V_6 )
return;
F_39 ( & V_6 -> V_17 ) ;
V_54 = F_71 ( V_6 ) ;
while ( V_54 ) {
F_15 ( & V_54 -> V_10 ) ;
F_30 ( & V_54 -> V_156 , V_154 ) ;
V_54 = F_74 ( V_54 ) ;
}
V_54 = F_73 ( V_6 ) ;
while ( V_54 ) {
F_15 ( & V_54 -> V_10 ) ;
F_30 ( & V_54 -> V_156 , V_155 ) ;
V_54 = F_74 ( V_54 ) ;
}
F_40 ( & V_6 -> V_17 ) ;
F_32 ( & V_6 -> V_10 ) ;
}
void F_146 ( struct V_49 * V_154 ,
struct V_49 * V_155 )
{
struct V_23 * V_95 , * V_52 ;
F_94 (curr, next, ins_list, readdir_list) {
F_97 ( & V_95 -> V_156 ) ;
if ( F_41 ( & V_95 -> V_10 ) )
F_70 ( V_95 ) ;
}
F_94 (curr, next, del_list, readdir_list) {
F_97 ( & V_95 -> V_156 ) ;
if ( F_41 ( & V_95 -> V_10 ) )
F_70 ( V_95 ) ;
}
}
int F_147 ( struct V_49 * V_155 ,
T_2 V_144 )
{
struct V_23 * V_95 , * V_52 ;
int V_39 ;
if ( F_28 ( V_155 ) )
return 0 ;
F_94 (curr, next, del_list, readdir_list) {
if ( V_95 -> V_26 . V_29 > V_144 )
break;
F_97 ( & V_95 -> V_156 ) ;
V_39 = ( V_95 -> V_26 . V_29 == V_144 ) ;
if ( F_41 ( & V_95 -> V_10 ) )
F_70 ( V_95 ) ;
if ( V_39 )
return 1 ;
else
continue;
}
return 0 ;
}
int F_148 ( struct V_157 * V_158 , void * V_159 ,
T_5 V_160 ,
struct V_49 * V_154 )
{
struct V_145 * V_161 ;
struct V_23 * V_95 , * V_52 ;
struct V_57 V_148 ;
char * V_139 ;
int V_140 ;
int V_162 = 0 ;
unsigned char V_163 ;
if ( F_28 ( V_154 ) )
return 0 ;
F_94 (curr, next, ins_list, readdir_list) {
F_97 ( & V_95 -> V_156 ) ;
if ( V_95 -> V_26 . V_29 < V_158 -> V_164 ) {
if ( F_41 ( & V_95 -> V_10 ) )
F_70 ( V_95 ) ;
continue;
}
V_158 -> V_164 = V_95 -> V_26 . V_29 ;
V_161 = (struct V_145 * ) V_95 -> V_111 ;
V_139 = ( char * ) ( V_161 + 1 ) ;
V_140 = F_149 ( V_161 -> V_140 ) ;
V_163 = V_165 [ V_161 -> type ] ;
F_150 ( & V_148 , & V_161 -> V_148 ) ;
V_162 = V_160 ( V_159 , V_139 , V_140 , V_95 -> V_26 . V_29 ,
V_148 . V_28 , V_163 ) ;
if ( F_41 ( & V_95 -> V_10 ) )
F_70 ( V_95 ) ;
if ( V_162 )
return 1 ;
}
return 0 ;
}
static void F_151 ( struct V_76 * V_77 ,
struct V_118 * V_22 ,
struct V_33 * V_33 )
{
F_152 ( V_22 , F_153 ( V_33 ) ) ;
F_154 ( V_22 , F_155 ( V_33 ) ) ;
F_156 ( V_22 , F_12 ( V_33 ) -> V_166 ) ;
F_157 ( V_22 , V_33 -> V_167 ) ;
F_158 ( V_22 , V_33 -> V_168 ) ;
F_159 ( V_22 , F_160 ( V_33 ) ) ;
F_161 ( V_22 ,
F_12 ( V_33 ) -> V_169 ) ;
F_162 ( V_22 , V_33 -> V_170 ) ;
F_163 ( V_22 , V_77 -> V_149 ) ;
F_164 ( V_22 , V_33 -> V_171 ) ;
F_165 ( V_22 , F_12 ( V_33 ) -> V_135 ) ;
F_166 ( V_22 , 0 ) ;
F_167 ( F_168 ( V_22 ) ,
V_33 -> V_172 . V_173 ) ;
F_169 ( F_168 ( V_22 ) ,
V_33 -> V_172 . V_174 ) ;
F_167 ( F_170 ( V_22 ) ,
V_33 -> V_175 . V_173 ) ;
F_169 ( F_170 ( V_22 ) ,
V_33 -> V_175 . V_174 ) ;
F_167 ( F_171 ( V_22 ) ,
V_33 -> V_176 . V_173 ) ;
F_169 ( F_171 ( V_22 ) ,
V_33 -> V_176 . V_174 ) ;
}
int F_172 ( struct V_33 * V_33 , T_3 * V_177 )
{
struct V_2 * V_6 ;
struct V_118 * V_22 ;
struct V_178 * V_179 ;
V_6 = F_11 ( V_33 ) ;
if ( ! V_6 )
return - V_116 ;
F_39 ( & V_6 -> V_17 ) ;
if ( ! V_6 -> V_13 ) {
F_40 ( & V_6 -> V_17 ) ;
F_44 ( V_6 ) ;
return - V_116 ;
}
V_22 = & V_6 -> V_22 ;
F_173 ( V_33 , F_174 ( V_22 ) ) ;
F_175 ( V_33 , F_176 ( V_22 ) ) ;
F_177 ( V_33 , F_178 ( V_22 ) ) ;
V_33 -> V_167 = F_179 ( V_22 ) ;
F_180 ( V_33 , F_181 ( V_22 ) ) ;
F_182 ( V_33 , F_183 ( V_22 ) ) ;
F_12 ( V_33 ) -> V_169 = F_184 ( V_22 ) ;
V_33 -> V_170 = F_185 ( V_22 ) ;
V_33 -> V_171 = 0 ;
* V_177 = F_186 ( V_22 ) ;
F_12 ( V_33 ) -> V_135 = F_187 ( V_22 ) ;
V_179 = F_168 ( V_22 ) ;
V_33 -> V_172 . V_173 = F_188 ( V_179 ) ;
V_33 -> V_172 . V_174 = F_189 ( V_179 ) ;
V_179 = F_170 ( V_22 ) ;
V_33 -> V_175 . V_173 = F_188 ( V_179 ) ;
V_33 -> V_175 . V_174 = F_189 ( V_179 ) ;
V_179 = F_171 ( V_22 ) ;
V_33 -> V_176 . V_173 = F_188 ( V_179 ) ;
V_33 -> V_176 . V_174 = F_189 ( V_179 ) ;
V_33 -> V_180 = F_12 ( V_33 ) -> V_169 ;
F_12 ( V_33 ) -> V_18 = ( T_2 ) - 1 ;
F_40 ( & V_6 -> V_17 ) ;
F_44 ( V_6 ) ;
return 0 ;
}
int F_190 ( struct V_76 * V_77 ,
struct V_7 * V_8 , struct V_33 * V_33 )
{
struct V_2 * V_6 ;
int V_39 = 0 ;
V_6 = F_20 ( V_33 ) ;
if ( F_127 ( V_6 ) )
return F_137 ( V_6 ) ;
F_39 ( & V_6 -> V_17 ) ;
if ( V_6 -> V_13 ) {
F_151 ( V_77 , & V_6 -> V_22 , V_33 ) ;
goto V_147;
}
V_39 = F_83 ( V_77 , V_8 , V_33 ,
V_6 ) ;
if ( V_39 )
goto V_147;
F_151 ( V_77 , & V_6 -> V_22 , V_33 ) ;
V_6 -> V_13 = 1 ;
V_6 -> V_11 ++ ;
F_15 ( & V_8 -> V_31 -> V_32 -> V_70 ) ;
V_147:
F_40 ( & V_6 -> V_17 ) ;
F_44 ( V_6 ) ;
return V_39 ;
}
static void F_191 ( struct V_2 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_23 * V_181 , * V_182 ;
F_39 ( & V_6 -> V_17 ) ;
V_181 = F_71 ( V_6 ) ;
while ( V_181 ) {
F_81 ( V_8 , V_181 ) ;
V_182 = V_181 ;
V_181 = F_74 ( V_182 ) ;
F_69 ( V_182 ) ;
}
V_181 = F_73 ( V_6 ) ;
while ( V_181 ) {
F_81 ( V_8 , V_181 ) ;
V_182 = V_181 ;
V_181 = F_74 ( V_182 ) ;
F_69 ( V_182 ) ;
}
if ( V_6 -> V_13 ) {
F_87 ( V_8 , V_6 ) ;
F_110 ( V_6 ) ;
}
F_40 ( & V_6 -> V_17 ) ;
}
void F_192 ( struct V_33 * V_33 )
{
struct V_2 * V_6 ;
V_6 = F_11 ( V_33 ) ;
if ( ! V_6 )
return;
F_191 ( V_6 ) ;
F_44 ( V_6 ) ;
}
void F_193 ( struct V_7 * V_8 )
{
T_2 V_9 = 0 ;
struct V_2 * V_183 [ 8 ] ;
int V_107 , V_184 ;
while ( 1 ) {
F_16 ( & V_8 -> V_37 ) ;
V_184 = F_194 ( & V_8 -> V_38 ,
( void * * ) V_183 , V_9 ,
F_195 ( V_183 ) ) ;
if ( ! V_184 ) {
F_19 ( & V_8 -> V_37 ) ;
break;
}
V_9 = V_183 [ V_184 - 1 ] -> V_9 + 1 ;
for ( V_107 = 0 ; V_107 < V_184 ; V_107 ++ )
F_15 ( & V_183 [ V_107 ] -> V_10 ) ;
F_19 ( & V_8 -> V_37 ) ;
for ( V_107 = 0 ; V_107 < V_184 ; V_107 ++ ) {
F_191 ( V_183 [ V_107 ] ) ;
F_44 ( V_183 [ V_107 ] ) ;
}
}
}
void F_196 ( struct V_7 * V_8 )
{
struct V_30 * V_32 ;
struct V_2 * V_122 , * V_60 ;
V_32 = F_10 ( V_8 ) ;
V_122 = F_34 ( V_32 ) ;
while ( V_122 ) {
F_191 ( V_122 ) ;
V_60 = V_122 ;
V_122 = F_36 ( V_122 ) ;
F_44 ( V_60 ) ;
}
}
