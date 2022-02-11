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
F_15 ( & V_35 -> V_10 ) ;
F_15 ( & V_35 -> V_10 ) ;
F_19 ( & V_8 -> V_36 ) ;
return V_35 ;
}
F_19 ( & V_8 -> V_36 ) ;
return NULL ;
}
static struct V_2 * F_20 (
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
V_35 = F_21 ( V_1 , V_40 ) ;
if ( ! V_35 )
return F_22 ( - V_5 ) ;
F_5 ( V_35 , V_8 , V_34 ) ;
F_15 ( & V_35 -> V_10 ) ;
F_15 ( & V_35 -> V_10 ) ;
V_38 = F_23 ( V_40 & ~ V_41 ) ;
if ( V_38 ) {
F_24 ( V_1 , V_35 ) ;
return F_22 ( V_38 ) ;
}
F_16 ( & V_8 -> V_36 ) ;
V_38 = F_25 ( & V_8 -> V_37 , V_34 , V_35 ) ;
if ( V_38 == - V_42 ) {
F_24 ( V_1 , V_35 ) ;
F_19 ( & V_8 -> V_36 ) ;
F_26 () ;
goto V_39;
}
V_33 -> V_6 = V_35 ;
F_19 ( & V_8 -> V_36 ) ;
F_26 () ;
return V_35 ;
}
static void F_27 ( struct V_29 * V_8 ,
struct V_2 * V_35 ,
int V_43 )
{
F_16 ( & V_8 -> V_44 ) ;
if ( V_35 -> V_12 ) {
if ( ! F_28 ( & V_35 -> V_20 ) )
F_29 ( & V_35 -> V_20 , & V_8 -> V_45 ) ;
else if ( V_43 )
F_30 ( & V_35 -> V_20 , & V_8 -> V_45 ) ;
} else {
F_30 ( & V_35 -> V_19 , & V_8 -> V_46 ) ;
F_30 ( & V_35 -> V_20 , & V_8 -> V_45 ) ;
F_15 ( & V_35 -> V_10 ) ;
V_8 -> V_47 ++ ;
V_35 -> V_12 = 1 ;
}
F_19 ( & V_8 -> V_44 ) ;
}
static void F_31 ( struct V_29 * V_8 ,
struct V_2 * V_35 )
{
F_16 ( & V_8 -> V_44 ) ;
if ( V_35 -> V_12 ) {
V_8 -> V_47 -- ;
F_32 ( & V_35 -> V_10 ) ;
F_33 ( & V_35 -> V_19 ) ;
if ( ! F_28 ( & V_35 -> V_20 ) )
F_33 ( & V_35 -> V_20 ) ;
V_35 -> V_12 = 0 ;
}
F_19 ( & V_8 -> V_44 ) ;
}
struct V_2 * F_34 (
struct V_29 * V_31 )
{
struct V_48 * V_49 ;
struct V_2 * V_35 = NULL ;
F_16 ( & V_31 -> V_44 ) ;
if ( F_28 ( & V_31 -> V_46 ) )
goto V_50;
V_49 = V_31 -> V_46 . V_51 ;
V_35 = F_35 ( V_49 , struct V_2 , V_19 ) ;
F_15 ( & V_35 -> V_10 ) ;
V_50:
F_19 ( & V_31 -> V_44 ) ;
return V_35 ;
}
struct V_2 * F_36 (
struct V_2 * V_35 )
{
struct V_29 * V_31 ;
struct V_48 * V_49 ;
struct V_2 * V_51 = NULL ;
V_31 = V_35 -> V_8 -> V_30 -> V_31 ;
F_16 ( & V_31 -> V_44 ) ;
if ( ! V_35 -> V_12 ) {
if ( F_28 ( & V_31 -> V_46 ) )
goto V_50;
V_49 = V_31 -> V_46 . V_51 ;
} else if ( F_37 ( & V_35 -> V_19 , & V_31 -> V_46 ) )
goto V_50;
else
V_49 = V_35 -> V_19 . V_51 ;
V_51 = F_35 ( V_49 , struct V_2 , V_19 ) ;
F_15 ( & V_51 -> V_10 ) ;
V_50:
F_19 ( & V_31 -> V_44 ) ;
return V_51 ;
}
static void F_38 (
struct V_2 * V_6 ,
int V_43 )
{
struct V_29 * V_31 ;
if ( ! V_6 )
return;
V_31 = V_6 -> V_8 -> V_30 -> V_31 ;
F_39 ( & V_6 -> V_17 ) ;
if ( V_6 -> V_11 )
F_27 ( V_31 , V_6 , V_43 ) ;
else
F_31 ( V_31 , V_6 ) ;
F_40 ( & V_6 -> V_17 ) ;
if ( F_41 ( & V_6 -> V_10 ) ) {
struct V_7 * V_8 = V_6 -> V_8 ;
F_16 ( & V_8 -> V_36 ) ;
if ( F_42 ( & V_6 -> V_10 ) == 0 ) {
F_43 ( & V_8 -> V_37 ,
V_6 -> V_9 ) ;
F_24 ( V_1 , V_6 ) ;
}
F_19 ( & V_8 -> V_36 ) ;
}
}
static inline void F_44 ( struct V_2 * V_35 )
{
F_38 ( V_35 , 0 ) ;
}
struct V_2 * F_45 (
struct V_29 * V_31 )
{
struct V_48 * V_49 ;
struct V_2 * V_35 = NULL ;
F_16 ( & V_31 -> V_44 ) ;
if ( F_28 ( & V_31 -> V_45 ) )
goto V_50;
V_49 = V_31 -> V_45 . V_51 ;
F_33 ( V_49 ) ;
V_35 = F_35 ( V_49 , struct V_2 , V_20 ) ;
F_15 ( & V_35 -> V_10 ) ;
V_50:
F_19 ( & V_31 -> V_44 ) ;
return V_35 ;
}
static inline void F_46 (
struct V_2 * V_35 )
{
F_38 ( V_35 , 1 ) ;
}
struct V_22 * F_47 ( T_3 V_52 )
{
struct V_22 * V_53 ;
V_53 = F_48 ( sizeof( * V_53 ) + V_52 , V_40 ) ;
if ( V_53 ) {
V_53 -> V_52 = V_52 ;
V_53 -> V_54 = 0 ;
V_53 -> V_21 = 0 ;
V_53 -> V_6 = NULL ;
F_6 ( & V_53 -> V_10 , 1 ) ;
}
return V_53 ;
}
static struct V_22 * F_49 (
struct V_55 * V_8 ,
struct V_56 * V_25 ,
struct V_22 * * V_57 ,
struct V_22 * * V_51 )
{
struct V_58 * V_35 , * V_59 = NULL ;
struct V_22 * V_60 = NULL ;
int V_38 = 0 ;
V_35 = V_8 -> V_58 ;
while ( V_35 ) {
V_60 = F_50 ( V_35 , struct V_22 ,
V_58 ) ;
V_59 = V_35 ;
V_38 = F_51 ( & V_60 -> V_25 , V_25 ) ;
if ( V_38 < 0 )
V_35 = V_35 -> V_61 ;
else if ( V_38 > 0 )
V_35 = V_35 -> V_62 ;
else
return V_60 ;
}
if ( V_57 ) {
if ( ! V_59 )
* V_57 = NULL ;
else if ( V_38 < 0 )
* V_57 = V_60 ;
else if ( ( V_35 = F_52 ( V_59 ) ) != NULL ) {
* V_57 = F_50 ( V_35 , struct V_22 ,
V_58 ) ;
} else
* V_57 = NULL ;
}
if ( V_51 ) {
if ( ! V_59 )
* V_51 = NULL ;
else if ( V_38 > 0 )
* V_51 = V_60 ;
else if ( ( V_35 = F_53 ( V_59 ) ) != NULL ) {
* V_51 = F_50 ( V_35 , struct V_22 ,
V_58 ) ;
} else
* V_51 = NULL ;
}
return NULL ;
}
struct V_22 * F_54 (
struct V_2 * V_6 ,
struct V_56 * V_25 )
{
struct V_22 * V_53 ;
V_53 = F_49 ( & V_6 -> V_14 , V_25 ,
NULL , NULL ) ;
return V_53 ;
}
struct V_22 * F_55 (
struct V_2 * V_6 ,
struct V_56 * V_25 )
{
struct V_22 * V_53 ;
V_53 = F_49 ( & V_6 -> V_16 , V_25 ,
NULL , NULL ) ;
return V_53 ;
}
struct V_22 * F_56 (
struct V_2 * V_6 ,
struct V_56 * V_25 )
{
struct V_22 * V_53 , * V_51 ;
V_53 = F_49 ( & V_6 -> V_14 , V_25 ,
NULL , & V_51 ) ;
if ( ! V_53 )
V_53 = V_51 ;
return V_53 ;
}
struct V_22 * F_57 (
struct V_2 * V_6 ,
struct V_56 * V_25 )
{
struct V_22 * V_53 , * V_51 ;
V_53 = F_49 ( & V_6 -> V_16 , V_25 ,
NULL , & V_51 ) ;
if ( ! V_53 )
V_53 = V_51 ;
return V_53 ;
}
static int F_58 ( struct V_2 * V_6 ,
struct V_22 * V_63 ,
int V_64 )
{
struct V_58 * * V_49 , * V_35 ;
struct V_58 * V_65 = NULL ;
struct V_55 * V_8 ;
struct V_22 * V_53 ;
int V_66 ;
if ( V_64 == V_67 )
V_8 = & V_6 -> V_14 ;
else if ( V_64 == V_68 )
V_8 = & V_6 -> V_16 ;
else
F_59 () ;
V_49 = & V_8 -> V_58 ;
V_35 = & V_63 -> V_58 ;
while ( * V_49 ) {
V_65 = * V_49 ;
V_53 = F_50 ( V_65 , struct V_22 ,
V_58 ) ;
V_66 = F_51 ( & V_53 -> V_25 , & V_63 -> V_25 ) ;
if ( V_66 < 0 )
V_49 = & ( * V_49 ) -> V_61 ;
else if ( V_66 > 0 )
V_49 = & ( * V_49 ) -> V_62 ;
else
return - V_42 ;
}
F_60 ( V_35 , V_65 , V_49 ) ;
F_61 ( V_35 , V_8 ) ;
V_63 -> V_6 = V_6 ;
V_63 -> V_54 = V_64 ;
if ( V_63 -> V_25 . type == V_26 &&
V_64 == V_67 &&
V_63 -> V_25 . V_28 >= V_6 -> V_18 )
V_6 -> V_18 = V_63 -> V_25 . V_28 + 1 ;
V_6 -> V_11 ++ ;
F_15 ( & V_6 -> V_8 -> V_30 -> V_31 -> V_69 ) ;
return 0 ;
}
static int F_62 ( struct V_2 * V_35 ,
struct V_22 * V_53 )
{
return F_58 ( V_35 , V_53 ,
V_67 ) ;
}
static int F_63 ( struct V_2 * V_35 ,
struct V_22 * V_53 )
{
return F_58 ( V_35 , V_53 ,
V_68 ) ;
}
static void F_64 ( struct V_22 * V_60 )
{
struct V_55 * V_8 ;
struct V_29 * V_31 ;
V_31 = V_60 -> V_6 -> V_8 -> V_30 -> V_31 ;
F_18 ( ! V_31 ) ;
F_18 ( V_60 -> V_54 != V_68 &&
V_60 -> V_54 != V_67 ) ;
if ( V_60 -> V_54 == V_67 )
V_8 = & V_60 -> V_6 -> V_14 ;
else
V_8 = & V_60 -> V_6 -> V_16 ;
F_65 ( & V_60 -> V_58 , V_8 ) ;
V_60 -> V_6 -> V_11 -- ;
F_32 ( & V_31 -> V_69 ) ;
if ( F_42 ( & V_31 -> V_69 ) < V_70 &&
F_66 ( & V_31 -> V_71 ) )
F_67 ( & V_31 -> V_71 ) ;
}
static void F_68 ( struct V_22 * V_53 )
{
if ( V_53 ) {
F_64 ( V_53 ) ;
if ( F_41 ( & V_53 -> V_10 ) )
F_69 ( V_53 ) ;
}
}
struct V_22 * F_70 (
struct V_2 * V_6 )
{
struct V_58 * V_49 ;
struct V_22 * V_53 = NULL ;
V_49 = F_71 ( & V_6 -> V_14 ) ;
if ( V_49 )
V_53 = F_50 ( V_49 , struct V_22 , V_58 ) ;
return V_53 ;
}
struct V_22 * F_72 (
struct V_2 * V_6 )
{
struct V_58 * V_49 ;
struct V_22 * V_53 = NULL ;
V_49 = F_71 ( & V_6 -> V_16 ) ;
if ( V_49 )
V_53 = F_50 ( V_49 , struct V_22 , V_58 ) ;
return V_53 ;
}
struct V_22 * F_73 (
struct V_22 * V_53 )
{
struct V_58 * V_49 ;
struct V_22 * V_51 = NULL ;
V_49 = F_53 ( & V_53 -> V_58 ) ;
if ( V_49 )
V_51 = F_50 ( V_49 , struct V_22 , V_58 ) ;
return V_51 ;
}
static inline struct V_7 * F_74 ( struct V_7 * V_8 ,
T_2 V_72 )
{
struct V_56 V_73 ;
if ( V_8 -> V_27 == V_72 )
return V_8 ;
V_73 . V_27 = V_72 ;
V_73 . type = V_74 ;
V_73 . V_28 = ( T_2 ) - 1 ;
return F_75 ( V_8 -> V_30 , & V_73 ) ;
}
static int F_76 ( struct V_75 * V_76 ,
struct V_7 * V_8 ,
struct V_22 * V_53 )
{
struct V_77 * V_78 ;
struct V_77 * V_79 ;
T_2 V_80 ;
int V_38 ;
if ( ! V_76 -> V_21 )
return 0 ;
V_78 = V_76 -> V_81 ;
V_79 = & V_8 -> V_30 -> V_82 ;
V_80 = F_77 ( V_8 , 1 ) ;
V_38 = F_78 ( V_78 , V_79 , V_80 ) ;
if ( ! V_38 )
V_53 -> V_21 = V_80 ;
return V_38 ;
}
static void F_79 ( struct V_7 * V_8 ,
struct V_22 * V_53 )
{
struct V_77 * V_83 ;
if ( ! V_53 -> V_21 )
return;
V_83 = & V_8 -> V_30 -> V_82 ;
F_80 ( V_8 , V_83 ,
V_53 -> V_21 ) ;
}
static int F_81 (
struct V_75 * V_76 ,
struct V_7 * V_8 ,
struct V_2 * V_35 )
{
struct V_77 * V_78 ;
struct V_77 * V_79 ;
T_2 V_80 ;
int V_38 ;
if ( ! V_76 -> V_21 )
return 0 ;
V_78 = V_76 -> V_81 ;
V_79 = & V_8 -> V_30 -> V_82 ;
V_80 = F_77 ( V_8 , 1 ) ;
V_38 = F_78 ( V_78 , V_79 , V_80 ) ;
if ( ! V_38 )
V_35 -> V_21 = V_80 ;
return V_38 ;
}
static void F_82 ( struct V_7 * V_8 ,
struct V_2 * V_35 )
{
struct V_77 * V_83 ;
if ( ! V_35 -> V_21 )
return;
V_83 = & V_8 -> V_30 -> V_82 ;
F_80 ( V_8 , V_83 ,
V_35 -> V_21 ) ;
V_35 -> V_21 = 0 ;
}
static int F_83 ( struct V_75 * V_76 ,
struct V_7 * V_8 ,
struct V_84 * V_85 ,
struct V_22 * V_53 )
{
struct V_22 * V_86 , * V_51 ;
int V_87 ;
int V_88 = 0 , V_89 = 0 ;
struct V_90 * V_91 ;
char * V_92 ;
struct V_56 * V_93 ;
T_3 * V_94 ;
struct V_48 V_95 ;
int V_96 ;
int V_97 ;
int V_98 ;
int V_38 = 0 ;
F_18 ( ! V_85 -> V_47 [ 0 ] ) ;
V_91 = V_85 -> V_47 [ 0 ] ;
V_87 = F_84 ( V_8 , V_91 ) ;
F_8 ( & V_95 ) ;
V_51 = V_53 ;
V_97 = 0 ;
while ( V_89 + V_51 -> V_52 + sizeof( struct V_99 ) <=
V_87 ) {
V_88 += V_51 -> V_52 ;
V_89 += V_51 -> V_52 + sizeof( struct V_99 ) ;
F_30 ( & V_51 -> V_100 , & V_95 ) ;
V_97 ++ ;
V_86 = V_51 ;
V_51 = F_73 ( V_86 ) ;
if ( ! V_51 )
break;
if ( ! F_9 ( V_86 , V_51 ) )
break;
}
if ( ! V_97 ) {
V_38 = 0 ;
goto V_50;
}
F_85 ( V_85 ) ;
V_93 = F_48 ( sizeof( struct V_56 ) * V_97 , V_40 ) ;
if ( ! V_93 ) {
V_38 = - V_5 ;
goto V_50;
}
V_94 = F_48 ( sizeof( T_3 ) * V_97 , V_40 ) ;
if ( ! V_94 ) {
V_38 = - V_5 ;
goto error;
}
V_98 = 0 ;
F_86 (next, &head, tree_list) {
V_93 [ V_98 ] = V_51 -> V_25 ;
V_94 [ V_98 ] = V_51 -> V_52 ;
V_98 ++ ;
}
F_87 ( V_85 , NULL , 0 ) ;
V_38 = F_88 ( V_76 , V_8 , V_85 , V_93 , V_94 ,
V_88 , V_89 , V_97 ) ;
if ( V_38 )
goto error;
V_96 = V_85 -> V_101 [ 0 ] ;
F_89 (curr, next, &head, tree_list) {
V_92 = F_90 ( V_91 , V_96 , char ) ;
F_91 ( V_91 , & V_86 -> V_102 ,
( unsigned long ) V_92 ,
V_86 -> V_52 ) ;
V_96 ++ ;
F_79 ( V_8 , V_86 ) ;
F_92 ( & V_86 -> V_100 ) ;
F_68 ( V_86 ) ;
}
error:
F_69 ( V_94 ) ;
F_69 ( V_93 ) ;
V_50:
return V_38 ;
}
static int F_93 ( struct V_75 * V_76 ,
struct V_7 * V_8 ,
struct V_84 * V_85 ,
struct V_22 * V_60 )
{
struct V_90 * V_91 ;
struct V_99 * V_53 ;
char * V_103 ;
int V_38 ;
V_38 = F_94 ( V_76 , V_8 , V_85 , & V_60 -> V_25 ,
V_60 -> V_52 ) ;
if ( V_38 < 0 && V_38 != - V_42 )
return V_38 ;
V_91 = V_85 -> V_47 [ 0 ] ;
V_53 = F_95 ( V_91 , V_85 -> V_101 [ 0 ] ) ;
V_103 = F_90 ( V_91 , V_85 -> V_101 [ 0 ] , char ) ;
F_91 ( V_91 , V_60 -> V_102 , ( unsigned long ) V_103 ,
V_60 -> V_52 ) ;
F_96 ( V_91 ) ;
F_79 ( V_8 , V_60 ) ;
return 0 ;
}
static int F_97 ( struct V_75 * V_76 ,
struct V_84 * V_85 ,
struct V_7 * V_8 ,
struct V_2 * V_35 )
{
struct V_22 * V_86 , * V_57 ;
int V_38 = 0 ;
V_104:
F_39 ( & V_35 -> V_17 ) ;
V_86 = F_70 ( V_35 ) ;
if ( ! V_86 )
goto V_105;
V_38 = F_93 ( V_76 , V_8 , V_85 , V_86 ) ;
if ( V_38 < 0 ) {
F_98 ( V_85 ) ;
goto V_105;
}
V_57 = V_86 ;
V_86 = F_73 ( V_57 ) ;
if ( V_86 && F_9 ( V_57 , V_86 ) ) {
V_85 -> V_101 [ 0 ] ++ ;
F_83 ( V_76 , V_8 , V_85 , V_86 ) ;
}
F_68 ( V_57 ) ;
F_96 ( V_85 -> V_47 [ 0 ] ) ;
F_98 ( V_85 ) ;
F_40 ( & V_35 -> V_17 ) ;
goto V_104;
V_105:
F_40 ( & V_35 -> V_17 ) ;
return V_38 ;
}
static int F_99 ( struct V_75 * V_76 ,
struct V_7 * V_8 ,
struct V_84 * V_85 ,
struct V_22 * V_53 )
{
struct V_22 * V_86 , * V_51 ;
struct V_90 * V_91 ;
struct V_56 V_25 ;
struct V_48 V_95 ;
int V_97 , V_98 , V_106 ;
int V_38 = 0 ;
F_18 ( ! V_85 -> V_47 [ 0 ] ) ;
V_91 = V_85 -> V_47 [ 0 ] ;
V_98 = V_85 -> V_101 [ 0 ] ;
V_106 = F_100 ( V_91 ) - 1 ;
if ( V_98 > V_106 )
return - V_107 ;
V_51 = V_53 ;
F_8 ( & V_95 ) ;
F_101 ( V_91 , & V_25 , V_98 ) ;
V_97 = 0 ;
while ( F_51 ( & V_51 -> V_25 , & V_25 ) == 0 ) {
F_30 ( & V_51 -> V_100 , & V_95 ) ;
V_97 ++ ;
V_86 = V_51 ;
V_51 = F_73 ( V_86 ) ;
if ( ! V_51 )
break;
if ( ! F_9 ( V_86 , V_51 ) )
break;
V_98 ++ ;
if ( V_98 > V_106 )
break;
F_101 ( V_91 , & V_25 , V_98 ) ;
}
if ( ! V_97 )
return 0 ;
V_38 = F_102 ( V_76 , V_8 , V_85 , V_85 -> V_101 [ 0 ] , V_97 ) ;
if ( V_38 )
goto V_50;
F_89 (curr, next, &head, tree_list) {
F_79 ( V_8 , V_86 ) ;
F_92 ( & V_86 -> V_100 ) ;
F_68 ( V_86 ) ;
}
V_50:
return V_38 ;
}
static int F_103 ( struct V_75 * V_76 ,
struct V_84 * V_85 ,
struct V_7 * V_8 ,
struct V_2 * V_35 )
{
struct V_22 * V_86 , * V_57 ;
int V_38 = 0 ;
V_104:
F_39 ( & V_35 -> V_17 ) ;
V_86 = F_72 ( V_35 ) ;
if ( ! V_86 )
goto V_108;
V_38 = F_104 ( V_76 , V_8 , & V_86 -> V_25 , V_85 , - 1 , 1 ) ;
if ( V_38 < 0 )
goto V_108;
else if ( V_38 > 0 ) {
V_57 = V_86 ;
V_86 = F_73 ( V_57 ) ;
F_68 ( V_57 ) ;
V_38 = 0 ;
F_98 ( V_85 ) ;
if ( V_86 )
goto V_104;
else
goto V_108;
}
F_99 ( V_76 , V_8 , V_85 , V_86 ) ;
F_98 ( V_85 ) ;
F_40 ( & V_35 -> V_17 ) ;
goto V_104;
V_108:
F_98 ( V_85 ) ;
F_40 ( & V_35 -> V_17 ) ;
return V_38 ;
}
static void F_105 ( struct V_2 * V_6 )
{
struct V_29 * V_31 ;
if ( V_6 && V_6 -> V_13 ) {
F_18 ( ! V_6 -> V_8 ) ;
V_6 -> V_13 = 0 ;
V_6 -> V_11 -- ;
V_31 = V_6 -> V_8 -> V_30 -> V_31 ;
F_32 ( & V_31 -> V_69 ) ;
if ( F_42 ( & V_31 -> V_69 ) <
V_70 &&
F_66 ( & V_31 -> V_71 ) )
F_67 ( & V_31 -> V_71 ) ;
}
}
static int F_106 ( struct V_75 * V_76 ,
struct V_7 * V_8 ,
struct V_84 * V_85 ,
struct V_2 * V_35 )
{
struct V_56 V_25 ;
struct V_109 * V_110 ;
struct V_90 * V_91 ;
int V_38 ;
F_39 ( & V_35 -> V_17 ) ;
if ( ! V_35 -> V_13 ) {
F_40 ( & V_35 -> V_17 ) ;
return 0 ;
}
V_25 . V_27 = V_35 -> V_9 ;
F_107 ( & V_25 , V_111 ) ;
V_25 . V_28 = 0 ;
V_38 = F_108 ( V_76 , V_8 , V_85 , & V_25 , 1 ) ;
if ( V_38 > 0 ) {
F_98 ( V_85 ) ;
F_40 ( & V_35 -> V_17 ) ;
return - V_107 ;
} else if ( V_38 < 0 ) {
F_40 ( & V_35 -> V_17 ) ;
return V_38 ;
}
F_109 ( V_85 , 1 ) ;
V_91 = V_85 -> V_47 [ 0 ] ;
V_110 = F_90 ( V_91 , V_85 -> V_101 [ 0 ] ,
struct V_109 ) ;
F_91 ( V_91 , & V_35 -> V_110 , ( unsigned long ) V_110 ,
sizeof( struct V_109 ) ) ;
F_96 ( V_91 ) ;
F_98 ( V_85 ) ;
F_82 ( V_8 , V_35 ) ;
F_105 ( V_35 ) ;
F_40 ( & V_35 -> V_17 ) ;
return 0 ;
}
int F_110 ( struct V_75 * V_76 ,
struct V_7 * V_8 )
{
struct V_29 * V_31 ;
struct V_2 * V_112 , * V_59 ;
struct V_84 * V_85 ;
struct V_77 * V_81 ;
int V_38 = 0 ;
V_85 = F_111 () ;
if ( ! V_85 )
return - V_5 ;
V_85 -> V_113 = 1 ;
V_81 = V_76 -> V_81 ;
V_76 -> V_81 = & V_8 -> V_30 -> V_82 ;
V_31 = F_10 ( V_8 ) ;
V_112 = F_34 ( V_31 ) ;
while ( V_112 ) {
V_8 = V_112 -> V_8 ;
V_38 = F_97 ( V_76 , V_85 , V_8 ,
V_112 ) ;
if ( ! V_38 )
V_38 = F_103 ( V_76 , V_85 , V_8 ,
V_112 ) ;
if ( ! V_38 )
V_38 = F_106 ( V_76 , V_8 , V_85 ,
V_112 ) ;
if ( V_38 ) {
F_44 ( V_112 ) ;
break;
}
V_59 = V_112 ;
V_112 = F_36 ( V_112 ) ;
F_44 ( V_59 ) ;
}
F_112 ( V_85 ) ;
V_76 -> V_81 = V_81 ;
return V_38 ;
}
static int F_113 ( struct V_75 * V_76 ,
struct V_2 * V_35 )
{
struct V_84 * V_85 ;
struct V_77 * V_81 ;
int V_38 ;
V_85 = F_111 () ;
if ( ! V_85 )
return - V_5 ;
V_85 -> V_113 = 1 ;
V_81 = V_76 -> V_81 ;
V_76 -> V_81 = & V_35 -> V_8 -> V_30 -> V_82 ;
V_38 = F_97 ( V_76 , V_85 , V_35 -> V_8 , V_35 ) ;
if ( ! V_38 )
V_38 = F_103 ( V_76 , V_85 , V_35 -> V_8 , V_35 ) ;
if ( ! V_38 )
V_38 = F_106 ( V_76 , V_35 -> V_8 , V_85 , V_35 ) ;
F_112 ( V_85 ) ;
V_76 -> V_81 = V_81 ;
return V_38 ;
}
int F_114 ( struct V_75 * V_76 ,
struct V_32 * V_32 )
{
struct V_2 * V_6 = F_11 ( V_32 ) ;
int V_38 ;
if ( ! V_6 )
return 0 ;
F_39 ( & V_6 -> V_17 ) ;
if ( ! V_6 -> V_11 ) {
F_40 ( & V_6 -> V_17 ) ;
F_44 ( V_6 ) ;
return 0 ;
}
F_40 ( & V_6 -> V_17 ) ;
V_38 = F_113 ( V_76 , V_6 ) ;
F_44 ( V_6 ) ;
return V_38 ;
}
void F_115 ( struct V_32 * V_32 )
{
struct V_2 * V_6 ;
V_6 = F_14 ( F_12 ( V_32 ) -> V_6 ) ;
if ( ! V_6 )
return;
F_12 ( V_32 ) -> V_6 = NULL ;
F_44 ( V_6 ) ;
}
static void F_116 ( struct V_114 * V_115 )
{
struct V_116 * V_117 ;
struct V_75 * V_76 ;
struct V_84 * V_85 ;
struct V_2 * V_6 = NULL ;
struct V_7 * V_8 ;
struct V_77 * V_81 ;
unsigned long V_118 = 0 ;
int V_119 = 0 ;
int V_38 ;
V_117 = F_117 ( V_115 , struct V_116 , V_115 ) ;
V_85 = F_111 () ;
if ( ! V_85 )
goto V_50;
V_85 -> V_113 = 1 ;
V_6 = V_117 -> V_6 ;
V_8 = V_6 -> V_8 ;
V_76 = F_118 ( V_8 ) ;
if ( F_119 ( V_76 ) )
goto V_120;
V_81 = V_76 -> V_81 ;
V_76 -> V_81 = & V_8 -> V_30 -> V_82 ;
V_38 = F_97 ( V_76 , V_85 , V_8 , V_6 ) ;
if ( ! V_38 )
V_38 = F_103 ( V_76 , V_85 , V_8 ,
V_6 ) ;
if ( ! V_38 )
F_106 ( V_76 , V_8 , V_85 , V_6 ) ;
F_39 ( & V_6 -> V_17 ) ;
if ( V_6 -> V_11 )
V_119 = 1 ;
else
F_31 ( V_8 -> V_30 -> V_31 ,
V_6 ) ;
F_40 ( & V_6 -> V_17 ) ;
V_118 = V_76 -> V_121 ;
V_76 -> V_81 = V_81 ;
F_120 ( V_76 , V_8 ) ;
F_121 ( V_8 , V_118 ) ;
V_120:
F_112 ( V_85 ) ;
V_50:
if ( V_119 )
F_122 ( & V_117 -> V_115 ) ;
else {
F_46 ( V_6 ) ;
F_69 ( V_117 ) ;
}
}
static int F_123 ( struct V_29 * V_31 ,
struct V_7 * V_8 , int V_122 )
{
struct V_116 * V_117 ;
struct V_2 * V_86 ;
int V_11 = 0 ;
V_39:
V_86 = F_45 ( V_31 ) ;
if ( ! V_86 )
return 0 ;
V_117 = F_48 ( sizeof( * V_117 ) , V_40 ) ;
if ( ! V_117 ) {
F_46 ( V_86 ) ;
return - V_5 ;
}
V_117 -> V_8 = V_8 ;
V_117 -> V_6 = V_86 ;
V_117 -> V_115 . V_123 = F_116 ;
V_117 -> V_115 . V_124 = 0 ;
F_124 ( & V_8 -> V_30 -> V_125 , & V_117 -> V_115 ) ;
V_11 ++ ;
if ( V_122 || V_11 < 4 )
goto V_39;
return 0 ;
}
void F_125 ( struct V_7 * V_8 )
{
struct V_29 * V_31 ;
V_31 = F_10 ( V_8 ) ;
F_126 ( F_34 ( V_31 ) ) ;
}
void F_127 ( struct V_7 * V_8 )
{
struct V_29 * V_31 ;
V_31 = F_10 ( V_8 ) ;
if ( F_42 ( & V_31 -> V_69 ) < V_70 )
return;
if ( F_42 ( & V_31 -> V_69 ) >= V_126 ) {
int V_38 ;
V_38 = F_123 ( V_31 , V_8 , 1 ) ;
if ( V_38 )
return;
F_128 (
V_31 -> V_71 ,
( F_42 ( & V_31 -> V_69 ) <
V_70 ) ,
V_127 ) ;
return;
}
F_123 ( V_31 , V_8 , 0 ) ;
}
int F_129 ( struct V_75 * V_76 ,
struct V_7 * V_8 , const char * V_128 ,
int V_129 , struct V_32 * V_130 ,
struct V_131 * V_132 , T_4 type ,
T_2 V_133 )
{
struct V_2 * V_6 ;
struct V_22 * V_60 ;
struct V_134 * V_135 ;
int V_38 ;
V_6 = F_20 ( V_130 ) ;
if ( F_119 ( V_6 ) )
return F_130 ( V_6 ) ;
V_60 = F_47 ( sizeof( * V_135 ) + V_129 ) ;
if ( ! V_60 ) {
V_38 = - V_5 ;
goto V_136;
}
V_38 = F_76 ( V_76 , V_8 , V_60 ) ;
F_18 ( V_38 ) ;
V_60 -> V_25 . V_27 = F_13 ( V_130 ) ;
F_107 ( & V_60 -> V_25 , V_26 ) ;
V_60 -> V_25 . V_28 = V_133 ;
V_135 = (struct V_134 * ) V_60 -> V_102 ;
V_135 -> V_137 = * V_132 ;
V_135 -> V_138 = F_131 ( V_76 -> V_138 ) ;
V_135 -> V_52 = 0 ;
V_135 -> V_129 = F_132 ( V_129 ) ;
V_135 -> type = type ;
memcpy ( ( char * ) ( V_135 + 1 ) , V_128 , V_129 ) ;
F_39 ( & V_6 -> V_17 ) ;
V_38 = F_62 ( V_6 , V_60 ) ;
if ( F_133 ( V_38 ) ) {
F_134 ( V_139 L_2
L_3
L_4 ,
V_128 ,
( unsigned long long ) V_6 -> V_8 -> V_27 ,
( unsigned long long ) V_6 -> V_9 ,
V_38 ) ;
F_59 () ;
}
F_40 ( & V_6 -> V_17 ) ;
V_136:
F_44 ( V_6 ) ;
return V_38 ;
}
static int F_135 ( struct V_7 * V_8 ,
struct V_2 * V_35 ,
struct V_56 * V_25 )
{
struct V_22 * V_53 ;
F_39 ( & V_35 -> V_17 ) ;
V_53 = F_54 ( V_35 , V_25 ) ;
if ( ! V_53 ) {
F_40 ( & V_35 -> V_17 ) ;
return 1 ;
}
F_79 ( V_8 , V_53 ) ;
F_68 ( V_53 ) ;
F_40 ( & V_35 -> V_17 ) ;
return 0 ;
}
int F_136 ( struct V_75 * V_76 ,
struct V_7 * V_8 , struct V_32 * V_130 ,
T_2 V_133 )
{
struct V_2 * V_35 ;
struct V_22 * V_53 ;
struct V_56 V_140 ;
int V_38 ;
V_35 = F_20 ( V_130 ) ;
if ( F_119 ( V_35 ) )
return F_130 ( V_35 ) ;
V_140 . V_27 = F_13 ( V_130 ) ;
F_107 ( & V_140 , V_26 ) ;
V_140 . V_28 = V_133 ;
V_38 = F_135 ( V_8 , V_35 , & V_140 ) ;
if ( ! V_38 )
goto V_141;
V_53 = F_47 ( 0 ) ;
if ( ! V_53 ) {
V_38 = - V_5 ;
goto V_141;
}
V_53 -> V_25 = V_140 ;
V_38 = F_76 ( V_76 , V_8 , V_53 ) ;
F_18 ( V_38 ) ;
F_39 ( & V_35 -> V_17 ) ;
V_38 = F_63 ( V_35 , V_53 ) ;
if ( F_133 ( V_38 ) ) {
F_134 ( V_139 L_5
L_6
L_4 ,
( unsigned long long ) V_133 ,
( unsigned long long ) V_35 -> V_8 -> V_27 ,
( unsigned long long ) V_35 -> V_9 ,
V_38 ) ;
F_59 () ;
}
F_40 ( & V_35 -> V_17 ) ;
V_141:
F_44 ( V_35 ) ;
return V_38 ;
}
int F_137 ( struct V_32 * V_32 )
{
struct V_2 * V_6 = F_11 ( V_32 ) ;
if ( ! V_6 )
return - V_107 ;
if ( ! V_6 -> V_18 ) {
F_44 ( V_6 ) ;
return - V_142 ;
}
F_12 ( V_32 ) -> V_18 = V_6 -> V_18 ;
F_44 ( V_6 ) ;
return 0 ;
}
void F_138 ( struct V_32 * V_32 , struct V_48 * V_143 ,
struct V_48 * V_144 )
{
struct V_2 * V_6 ;
struct V_22 * V_53 ;
V_6 = F_11 ( V_32 ) ;
if ( ! V_6 )
return;
F_39 ( & V_6 -> V_17 ) ;
V_53 = F_70 ( V_6 ) ;
while ( V_53 ) {
F_15 ( & V_53 -> V_10 ) ;
F_30 ( & V_53 -> V_145 , V_143 ) ;
V_53 = F_73 ( V_53 ) ;
}
V_53 = F_72 ( V_6 ) ;
while ( V_53 ) {
F_15 ( & V_53 -> V_10 ) ;
F_30 ( & V_53 -> V_145 , V_144 ) ;
V_53 = F_73 ( V_53 ) ;
}
F_40 ( & V_6 -> V_17 ) ;
F_32 ( & V_6 -> V_10 ) ;
}
void F_139 ( struct V_48 * V_143 ,
struct V_48 * V_144 )
{
struct V_22 * V_86 , * V_51 ;
F_89 (curr, next, ins_list, readdir_list) {
F_92 ( & V_86 -> V_145 ) ;
if ( F_41 ( & V_86 -> V_10 ) )
F_69 ( V_86 ) ;
}
F_89 (curr, next, del_list, readdir_list) {
F_92 ( & V_86 -> V_145 ) ;
if ( F_41 ( & V_86 -> V_10 ) )
F_69 ( V_86 ) ;
}
}
int F_140 ( struct V_48 * V_144 ,
T_2 V_133 )
{
struct V_22 * V_86 , * V_51 ;
int V_38 ;
if ( F_28 ( V_144 ) )
return 0 ;
F_89 (curr, next, del_list, readdir_list) {
if ( V_86 -> V_25 . V_28 > V_133 )
break;
F_92 ( & V_86 -> V_145 ) ;
V_38 = ( V_86 -> V_25 . V_28 == V_133 ) ;
if ( F_41 ( & V_86 -> V_10 ) )
F_69 ( V_86 ) ;
if ( V_38 )
return 1 ;
else
continue;
}
return 0 ;
}
int F_141 ( struct V_146 * V_147 , void * V_148 ,
T_5 V_149 ,
struct V_48 * V_143 )
{
struct V_134 * V_150 ;
struct V_22 * V_86 , * V_51 ;
struct V_56 V_137 ;
char * V_128 ;
int V_129 ;
int V_151 = 0 ;
unsigned char V_152 ;
if ( F_28 ( V_143 ) )
return 0 ;
F_89 (curr, next, ins_list, readdir_list) {
F_92 ( & V_86 -> V_145 ) ;
if ( V_86 -> V_25 . V_28 < V_147 -> V_153 ) {
if ( F_41 ( & V_86 -> V_10 ) )
F_69 ( V_86 ) ;
continue;
}
V_147 -> V_153 = V_86 -> V_25 . V_28 ;
V_150 = (struct V_134 * ) V_86 -> V_102 ;
V_128 = ( char * ) ( V_150 + 1 ) ;
V_129 = F_142 ( V_150 -> V_129 ) ;
V_152 = V_154 [ V_150 -> type ] ;
F_143 ( & V_137 , & V_150 -> V_137 ) ;
V_151 = V_149 ( V_148 , V_128 , V_129 , V_86 -> V_25 . V_28 ,
V_137 . V_27 , V_152 ) ;
if ( F_41 ( & V_86 -> V_10 ) )
F_69 ( V_86 ) ;
if ( V_151 )
return 1 ;
}
return 0 ;
}
static void F_144 ( struct V_75 * V_76 ,
struct V_109 * V_110 ,
struct V_32 * V_32 )
{
F_145 ( V_110 , V_32 -> V_155 ) ;
F_146 ( V_110 , V_32 -> V_156 ) ;
F_147 ( V_110 , F_12 ( V_32 ) -> V_157 ) ;
F_148 ( V_110 , V_32 -> V_158 ) ;
F_149 ( V_110 , V_32 -> V_159 ) ;
F_150 ( V_110 , F_151 ( V_32 ) ) ;
F_152 ( V_110 ,
F_12 ( V_32 ) -> V_160 ) ;
F_153 ( V_110 , F_12 ( V_32 ) -> V_161 ) ;
F_154 ( V_110 , V_76 -> V_138 ) ;
F_155 ( V_110 , V_32 -> V_162 ) ;
F_156 ( V_110 , F_12 ( V_32 ) -> V_124 ) ;
F_157 ( V_110 , 0 ) ;
F_158 ( F_159 ( V_110 ) ,
V_32 -> V_163 . V_164 ) ;
F_160 ( F_159 ( V_110 ) ,
V_32 -> V_163 . V_165 ) ;
F_158 ( F_161 ( V_110 ) ,
V_32 -> V_166 . V_164 ) ;
F_160 ( F_161 ( V_110 ) ,
V_32 -> V_166 . V_165 ) ;
F_158 ( F_162 ( V_110 ) ,
V_32 -> V_167 . V_164 ) ;
F_160 ( F_162 ( V_110 ) ,
V_32 -> V_167 . V_165 ) ;
}
int F_163 ( struct V_32 * V_32 , T_3 * V_168 )
{
struct V_2 * V_6 ;
struct V_109 * V_110 ;
struct V_169 * V_170 ;
V_6 = F_11 ( V_32 ) ;
if ( ! V_6 )
return - V_107 ;
F_39 ( & V_6 -> V_17 ) ;
if ( ! V_6 -> V_13 ) {
F_40 ( & V_6 -> V_17 ) ;
F_44 ( V_6 ) ;
return - V_107 ;
}
V_110 = & V_6 -> V_110 ;
V_32 -> V_155 = F_164 ( V_110 ) ;
V_32 -> V_156 = F_165 ( V_110 ) ;
F_166 ( V_32 , F_167 ( V_110 ) ) ;
V_32 -> V_158 = F_168 ( V_110 ) ;
V_32 -> V_159 = F_169 ( V_110 ) ;
F_170 ( V_32 , F_171 ( V_110 ) ) ;
F_12 ( V_32 ) -> V_160 = F_172 ( V_110 ) ;
F_12 ( V_32 ) -> V_161 = F_173 ( V_110 ) ;
V_32 -> V_162 = 0 ;
* V_168 = F_174 ( V_110 ) ;
F_12 ( V_32 ) -> V_124 = F_175 ( V_110 ) ;
V_170 = F_159 ( V_110 ) ;
V_32 -> V_163 . V_164 = F_176 ( V_170 ) ;
V_32 -> V_163 . V_165 = F_177 ( V_170 ) ;
V_170 = F_161 ( V_110 ) ;
V_32 -> V_166 . V_164 = F_176 ( V_170 ) ;
V_32 -> V_166 . V_165 = F_177 ( V_170 ) ;
V_170 = F_162 ( V_110 ) ;
V_32 -> V_167 . V_164 = F_176 ( V_170 ) ;
V_32 -> V_167 . V_165 = F_177 ( V_170 ) ;
V_32 -> V_171 = F_12 ( V_32 ) -> V_160 ;
F_12 ( V_32 ) -> V_18 = ( T_2 ) - 1 ;
F_40 ( & V_6 -> V_17 ) ;
F_44 ( V_6 ) ;
return 0 ;
}
int F_178 ( struct V_75 * V_76 ,
struct V_7 * V_8 , struct V_32 * V_32 )
{
struct V_2 * V_6 ;
int V_38 = 0 ;
V_6 = F_20 ( V_32 ) ;
if ( F_119 ( V_6 ) )
return F_130 ( V_6 ) ;
F_39 ( & V_6 -> V_17 ) ;
if ( V_6 -> V_13 ) {
F_144 ( V_76 , & V_6 -> V_110 , V_32 ) ;
goto V_136;
}
V_38 = F_81 ( V_76 , V_8 , V_6 ) ;
F_18 ( V_38 ) ;
F_144 ( V_76 , & V_6 -> V_110 , V_32 ) ;
V_6 -> V_13 = 1 ;
V_6 -> V_11 ++ ;
F_15 ( & V_8 -> V_30 -> V_31 -> V_69 ) ;
V_136:
F_40 ( & V_6 -> V_17 ) ;
F_44 ( V_6 ) ;
return V_38 ;
}
static void F_179 ( struct V_2 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_22 * V_172 , * V_173 ;
F_39 ( & V_6 -> V_17 ) ;
V_172 = F_70 ( V_6 ) ;
while ( V_172 ) {
F_79 ( V_8 , V_172 ) ;
V_173 = V_172 ;
V_172 = F_73 ( V_173 ) ;
F_68 ( V_173 ) ;
}
V_172 = F_72 ( V_6 ) ;
while ( V_172 ) {
F_79 ( V_8 , V_172 ) ;
V_173 = V_172 ;
V_172 = F_73 ( V_173 ) ;
F_68 ( V_173 ) ;
}
if ( V_6 -> V_13 ) {
F_82 ( V_8 , V_6 ) ;
F_105 ( V_6 ) ;
}
F_40 ( & V_6 -> V_17 ) ;
}
void F_180 ( struct V_32 * V_32 )
{
struct V_2 * V_6 ;
V_6 = F_11 ( V_32 ) ;
if ( ! V_6 )
return;
F_179 ( V_6 ) ;
F_44 ( V_6 ) ;
}
void F_181 ( struct V_7 * V_8 )
{
T_2 V_9 = 0 ;
struct V_2 * V_174 [ 8 ] ;
int V_98 , V_175 ;
while ( 1 ) {
F_16 ( & V_8 -> V_36 ) ;
V_175 = F_182 ( & V_8 -> V_37 ,
( void * * ) V_174 , V_9 ,
F_183 ( V_174 ) ) ;
if ( ! V_175 ) {
F_19 ( & V_8 -> V_36 ) ;
break;
}
V_9 = V_174 [ V_175 - 1 ] -> V_9 + 1 ;
for ( V_98 = 0 ; V_98 < V_175 ; V_98 ++ )
F_15 ( & V_174 [ V_98 ] -> V_10 ) ;
F_19 ( & V_8 -> V_36 ) ;
for ( V_98 = 0 ; V_98 < V_175 ; V_98 ++ ) {
F_179 ( V_174 [ V_98 ] ) ;
F_44 ( V_174 [ V_98 ] ) ;
}
}
}
