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
struct V_32 * V_32 ,
struct V_2 * V_35 )
{
struct V_77 * V_78 ;
struct V_77 * V_79 ;
T_2 V_80 ;
int V_38 ;
int V_84 = false ;
V_78 = V_76 -> V_81 ;
V_79 = & V_8 -> V_30 -> V_82 ;
V_80 = F_77 ( V_8 , 1 ) ;
if ( ! V_78 || ( ! V_76 -> V_21 &&
V_78 != & V_8 -> V_30 -> V_85 ) ) {
V_38 = F_82 ( V_8 , V_79 , V_80 ) ;
if ( V_38 == - V_86 )
V_38 = - V_87 ;
if ( ! V_38 )
V_35 -> V_21 = V_80 ;
return V_38 ;
} else if ( V_78 == & V_8 -> V_30 -> V_85 ) {
F_16 ( & F_12 ( V_32 ) -> V_44 ) ;
if ( F_12 ( V_32 ) -> V_88 ) {
F_12 ( V_32 ) -> V_88 = 0 ;
F_19 ( & F_12 ( V_32 ) -> V_44 ) ;
V_84 = true ;
goto V_89;
}
F_19 ( & F_12 ( V_32 ) -> V_44 ) ;
V_38 = F_82 ( V_8 , V_79 , V_80 ) ;
if ( ! V_38 )
goto V_50;
V_38 = F_78 ( V_78 , V_79 , V_80 ) ;
if ( ! V_38 )
goto V_50;
F_83 ( 1 ) ;
V_38 = F_78 ( & V_8 -> V_30 -> V_90 ,
V_79 , V_80 ) ;
goto V_50;
}
V_89:
V_38 = F_78 ( V_78 , V_79 , V_80 ) ;
V_50:
if ( ! V_38 )
V_35 -> V_21 = V_80 ;
if ( V_84 )
F_80 ( V_8 , V_78 , V_80 ) ;
return V_38 ;
}
static void F_84 ( struct V_7 * V_8 ,
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
static int F_85 ( struct V_75 * V_76 ,
struct V_7 * V_8 ,
struct V_91 * V_92 ,
struct V_22 * V_53 )
{
struct V_22 * V_93 , * V_51 ;
int V_94 ;
int V_95 = 0 , V_96 = 0 ;
struct V_97 * V_98 ;
char * V_99 ;
struct V_56 * V_100 ;
T_3 * V_101 ;
struct V_48 V_102 ;
int V_103 ;
int V_104 ;
int V_105 ;
int V_38 = 0 ;
F_18 ( ! V_92 -> V_47 [ 0 ] ) ;
V_98 = V_92 -> V_47 [ 0 ] ;
V_94 = F_86 ( V_8 , V_98 ) ;
F_8 ( & V_102 ) ;
V_51 = V_53 ;
V_104 = 0 ;
while ( V_96 + V_51 -> V_52 + sizeof( struct V_106 ) <=
V_94 ) {
V_95 += V_51 -> V_52 ;
V_96 += V_51 -> V_52 + sizeof( struct V_106 ) ;
F_30 ( & V_51 -> V_107 , & V_102 ) ;
V_104 ++ ;
V_93 = V_51 ;
V_51 = F_73 ( V_93 ) ;
if ( ! V_51 )
break;
if ( ! F_9 ( V_93 , V_51 ) )
break;
}
if ( ! V_104 ) {
V_38 = 0 ;
goto V_50;
}
F_87 ( V_92 ) ;
V_100 = F_48 ( sizeof( struct V_56 ) * V_104 , V_40 ) ;
if ( ! V_100 ) {
V_38 = - V_5 ;
goto V_50;
}
V_101 = F_48 ( sizeof( T_3 ) * V_104 , V_40 ) ;
if ( ! V_101 ) {
V_38 = - V_5 ;
goto error;
}
V_105 = 0 ;
F_88 (next, &head, tree_list) {
V_100 [ V_105 ] = V_51 -> V_25 ;
V_101 [ V_105 ] = V_51 -> V_52 ;
V_105 ++ ;
}
F_89 ( V_92 , NULL , 0 ) ;
V_38 = F_90 ( V_76 , V_8 , V_92 , V_100 , V_101 ,
V_95 , V_96 , V_104 ) ;
if ( V_38 )
goto error;
V_103 = V_92 -> V_108 [ 0 ] ;
F_91 (curr, next, &head, tree_list) {
V_99 = F_92 ( V_98 , V_103 , char ) ;
F_93 ( V_98 , & V_93 -> V_109 ,
( unsigned long ) V_99 ,
V_93 -> V_52 ) ;
V_103 ++ ;
F_79 ( V_8 , V_93 ) ;
F_94 ( & V_93 -> V_107 ) ;
F_68 ( V_93 ) ;
}
error:
F_69 ( V_101 ) ;
F_69 ( V_100 ) ;
V_50:
return V_38 ;
}
static int F_95 ( struct V_75 * V_76 ,
struct V_7 * V_8 ,
struct V_91 * V_92 ,
struct V_22 * V_60 )
{
struct V_97 * V_98 ;
struct V_106 * V_53 ;
char * V_110 ;
int V_38 ;
V_38 = F_96 ( V_76 , V_8 , V_92 , & V_60 -> V_25 ,
V_60 -> V_52 ) ;
if ( V_38 < 0 && V_38 != - V_42 )
return V_38 ;
V_98 = V_92 -> V_47 [ 0 ] ;
V_53 = F_97 ( V_98 , V_92 -> V_108 [ 0 ] ) ;
V_110 = F_92 ( V_98 , V_92 -> V_108 [ 0 ] , char ) ;
F_93 ( V_98 , V_60 -> V_109 , ( unsigned long ) V_110 ,
V_60 -> V_52 ) ;
F_98 ( V_98 ) ;
F_79 ( V_8 , V_60 ) ;
return 0 ;
}
static int F_99 ( struct V_75 * V_76 ,
struct V_91 * V_92 ,
struct V_7 * V_8 ,
struct V_2 * V_35 )
{
struct V_22 * V_93 , * V_57 ;
int V_38 = 0 ;
V_111:
F_39 ( & V_35 -> V_17 ) ;
V_93 = F_70 ( V_35 ) ;
if ( ! V_93 )
goto V_112;
V_38 = F_95 ( V_76 , V_8 , V_92 , V_93 ) ;
if ( V_38 < 0 ) {
F_100 ( V_92 ) ;
goto V_112;
}
V_57 = V_93 ;
V_93 = F_73 ( V_57 ) ;
if ( V_93 && F_9 ( V_57 , V_93 ) ) {
V_92 -> V_108 [ 0 ] ++ ;
F_85 ( V_76 , V_8 , V_92 , V_93 ) ;
}
F_68 ( V_57 ) ;
F_98 ( V_92 -> V_47 [ 0 ] ) ;
F_100 ( V_92 ) ;
F_40 ( & V_35 -> V_17 ) ;
goto V_111;
V_112:
F_40 ( & V_35 -> V_17 ) ;
return V_38 ;
}
static int F_101 ( struct V_75 * V_76 ,
struct V_7 * V_8 ,
struct V_91 * V_92 ,
struct V_22 * V_53 )
{
struct V_22 * V_93 , * V_51 ;
struct V_97 * V_98 ;
struct V_56 V_25 ;
struct V_48 V_102 ;
int V_104 , V_105 , V_113 ;
int V_38 = 0 ;
F_18 ( ! V_92 -> V_47 [ 0 ] ) ;
V_98 = V_92 -> V_47 [ 0 ] ;
V_105 = V_92 -> V_108 [ 0 ] ;
V_113 = F_102 ( V_98 ) - 1 ;
if ( V_105 > V_113 )
return - V_114 ;
V_51 = V_53 ;
F_8 ( & V_102 ) ;
F_103 ( V_98 , & V_25 , V_105 ) ;
V_104 = 0 ;
while ( F_51 ( & V_51 -> V_25 , & V_25 ) == 0 ) {
F_30 ( & V_51 -> V_107 , & V_102 ) ;
V_104 ++ ;
V_93 = V_51 ;
V_51 = F_73 ( V_93 ) ;
if ( ! V_51 )
break;
if ( ! F_9 ( V_93 , V_51 ) )
break;
V_105 ++ ;
if ( V_105 > V_113 )
break;
F_103 ( V_98 , & V_25 , V_105 ) ;
}
if ( ! V_104 )
return 0 ;
V_38 = F_104 ( V_76 , V_8 , V_92 , V_92 -> V_108 [ 0 ] , V_104 ) ;
if ( V_38 )
goto V_50;
F_91 (curr, next, &head, tree_list) {
F_79 ( V_8 , V_93 ) ;
F_94 ( & V_93 -> V_107 ) ;
F_68 ( V_93 ) ;
}
V_50:
return V_38 ;
}
static int F_105 ( struct V_75 * V_76 ,
struct V_91 * V_92 ,
struct V_7 * V_8 ,
struct V_2 * V_35 )
{
struct V_22 * V_93 , * V_57 ;
int V_38 = 0 ;
V_111:
F_39 ( & V_35 -> V_17 ) ;
V_93 = F_72 ( V_35 ) ;
if ( ! V_93 )
goto V_115;
V_38 = F_106 ( V_76 , V_8 , & V_93 -> V_25 , V_92 , - 1 , 1 ) ;
if ( V_38 < 0 )
goto V_115;
else if ( V_38 > 0 ) {
V_57 = V_93 ;
V_93 = F_73 ( V_57 ) ;
F_68 ( V_57 ) ;
V_38 = 0 ;
F_100 ( V_92 ) ;
if ( V_93 )
goto V_111;
else
goto V_115;
}
F_101 ( V_76 , V_8 , V_92 , V_93 ) ;
F_100 ( V_92 ) ;
F_40 ( & V_35 -> V_17 ) ;
goto V_111;
V_115:
F_100 ( V_92 ) ;
F_40 ( & V_35 -> V_17 ) ;
return V_38 ;
}
static void F_107 ( struct V_2 * V_6 )
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
static int F_108 ( struct V_75 * V_76 ,
struct V_7 * V_8 ,
struct V_91 * V_92 ,
struct V_2 * V_35 )
{
struct V_56 V_25 ;
struct V_116 * V_117 ;
struct V_97 * V_98 ;
int V_38 ;
F_39 ( & V_35 -> V_17 ) ;
if ( ! V_35 -> V_13 ) {
F_40 ( & V_35 -> V_17 ) ;
return 0 ;
}
V_25 . V_27 = V_35 -> V_9 ;
F_109 ( & V_25 , V_118 ) ;
V_25 . V_28 = 0 ;
V_38 = F_110 ( V_76 , V_8 , V_92 , & V_25 , 1 ) ;
if ( V_38 > 0 ) {
F_100 ( V_92 ) ;
F_40 ( & V_35 -> V_17 ) ;
return - V_114 ;
} else if ( V_38 < 0 ) {
F_40 ( & V_35 -> V_17 ) ;
return V_38 ;
}
F_111 ( V_92 , 1 ) ;
V_98 = V_92 -> V_47 [ 0 ] ;
V_117 = F_92 ( V_98 , V_92 -> V_108 [ 0 ] ,
struct V_116 ) ;
F_93 ( V_98 , & V_35 -> V_117 , ( unsigned long ) V_117 ,
sizeof( struct V_116 ) ) ;
F_98 ( V_98 ) ;
F_100 ( V_92 ) ;
F_84 ( V_8 , V_35 ) ;
F_107 ( V_35 ) ;
F_40 ( & V_35 -> V_17 ) ;
return 0 ;
}
int F_112 ( struct V_75 * V_76 ,
struct V_7 * V_8 )
{
struct V_29 * V_31 ;
struct V_2 * V_119 , * V_59 ;
struct V_91 * V_92 ;
struct V_77 * V_81 ;
int V_38 = 0 ;
V_92 = F_113 () ;
if ( ! V_92 )
return - V_5 ;
V_92 -> V_120 = 1 ;
V_81 = V_76 -> V_81 ;
V_76 -> V_81 = & V_8 -> V_30 -> V_82 ;
V_31 = F_10 ( V_8 ) ;
V_119 = F_34 ( V_31 ) ;
while ( V_119 ) {
V_8 = V_119 -> V_8 ;
V_38 = F_99 ( V_76 , V_92 , V_8 ,
V_119 ) ;
if ( ! V_38 )
V_38 = F_105 ( V_76 , V_92 , V_8 ,
V_119 ) ;
if ( ! V_38 )
V_38 = F_108 ( V_76 , V_8 , V_92 ,
V_119 ) ;
if ( V_38 ) {
F_44 ( V_119 ) ;
break;
}
V_59 = V_119 ;
V_119 = F_36 ( V_119 ) ;
F_44 ( V_59 ) ;
}
F_114 ( V_92 ) ;
V_76 -> V_81 = V_81 ;
return V_38 ;
}
static int F_115 ( struct V_75 * V_76 ,
struct V_2 * V_35 )
{
struct V_91 * V_92 ;
struct V_77 * V_81 ;
int V_38 ;
V_92 = F_113 () ;
if ( ! V_92 )
return - V_5 ;
V_92 -> V_120 = 1 ;
V_81 = V_76 -> V_81 ;
V_76 -> V_81 = & V_35 -> V_8 -> V_30 -> V_82 ;
V_38 = F_99 ( V_76 , V_92 , V_35 -> V_8 , V_35 ) ;
if ( ! V_38 )
V_38 = F_105 ( V_76 , V_92 , V_35 -> V_8 , V_35 ) ;
if ( ! V_38 )
V_38 = F_108 ( V_76 , V_35 -> V_8 , V_92 , V_35 ) ;
F_114 ( V_92 ) ;
V_76 -> V_81 = V_81 ;
return V_38 ;
}
int F_116 ( struct V_75 * V_76 ,
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
V_38 = F_115 ( V_76 , V_6 ) ;
F_44 ( V_6 ) ;
return V_38 ;
}
void F_117 ( struct V_32 * V_32 )
{
struct V_2 * V_6 ;
V_6 = F_14 ( F_12 ( V_32 ) -> V_6 ) ;
if ( ! V_6 )
return;
F_12 ( V_32 ) -> V_6 = NULL ;
F_44 ( V_6 ) ;
}
static void F_118 ( struct V_121 * V_122 )
{
struct V_123 * V_124 ;
struct V_75 * V_76 ;
struct V_91 * V_92 ;
struct V_2 * V_6 = NULL ;
struct V_7 * V_8 ;
struct V_77 * V_81 ;
unsigned long V_125 = 0 ;
int V_126 = 0 ;
int V_38 ;
V_124 = F_119 ( V_122 , struct V_123 , V_122 ) ;
V_92 = F_113 () ;
if ( ! V_92 )
goto V_50;
V_92 -> V_120 = 1 ;
V_6 = V_124 -> V_6 ;
V_8 = V_6 -> V_8 ;
V_76 = F_120 ( V_8 ) ;
if ( F_121 ( V_76 ) )
goto V_127;
V_81 = V_76 -> V_81 ;
V_76 -> V_81 = & V_8 -> V_30 -> V_82 ;
V_38 = F_99 ( V_76 , V_92 , V_8 , V_6 ) ;
if ( ! V_38 )
V_38 = F_105 ( V_76 , V_92 , V_8 ,
V_6 ) ;
if ( ! V_38 )
F_108 ( V_76 , V_8 , V_92 , V_6 ) ;
F_39 ( & V_6 -> V_17 ) ;
if ( V_6 -> V_11 )
V_126 = 1 ;
else
F_31 ( V_8 -> V_30 -> V_31 ,
V_6 ) ;
F_40 ( & V_6 -> V_17 ) ;
V_125 = V_76 -> V_128 ;
V_76 -> V_81 = V_81 ;
F_122 ( V_76 , V_8 ) ;
F_123 ( V_8 , V_125 ) ;
V_127:
F_114 ( V_92 ) ;
V_50:
if ( V_126 )
F_124 ( & V_124 -> V_122 ) ;
else {
F_46 ( V_6 ) ;
F_69 ( V_124 ) ;
}
}
static int F_125 ( struct V_29 * V_31 ,
struct V_7 * V_8 , int V_129 )
{
struct V_123 * V_124 ;
struct V_2 * V_93 ;
int V_11 = 0 ;
V_39:
V_93 = F_45 ( V_31 ) ;
if ( ! V_93 )
return 0 ;
V_124 = F_48 ( sizeof( * V_124 ) , V_40 ) ;
if ( ! V_124 ) {
F_46 ( V_93 ) ;
return - V_5 ;
}
V_124 -> V_8 = V_8 ;
V_124 -> V_6 = V_93 ;
V_124 -> V_122 . V_130 = F_118 ;
V_124 -> V_122 . V_131 = 0 ;
F_126 ( & V_8 -> V_30 -> V_132 , & V_124 -> V_122 ) ;
V_11 ++ ;
if ( V_129 || V_11 < 4 )
goto V_39;
return 0 ;
}
void F_127 ( struct V_7 * V_8 )
{
struct V_29 * V_31 ;
V_31 = F_10 ( V_8 ) ;
F_83 ( F_34 ( V_31 ) ) ;
}
void F_128 ( struct V_7 * V_8 )
{
struct V_29 * V_31 ;
V_31 = F_10 ( V_8 ) ;
if ( F_42 ( & V_31 -> V_69 ) < V_70 )
return;
if ( F_42 ( & V_31 -> V_69 ) >= V_133 ) {
int V_38 ;
V_38 = F_125 ( V_31 , V_8 , 1 ) ;
if ( V_38 )
return;
F_129 (
V_31 -> V_71 ,
( F_42 ( & V_31 -> V_69 ) <
V_70 ) ,
V_134 ) ;
return;
}
F_125 ( V_31 , V_8 , 0 ) ;
}
int F_130 ( struct V_75 * V_76 ,
struct V_7 * V_8 , const char * V_135 ,
int V_136 , struct V_32 * V_137 ,
struct V_138 * V_139 , T_4 type ,
T_2 V_140 )
{
struct V_2 * V_6 ;
struct V_22 * V_60 ;
struct V_141 * V_142 ;
int V_38 ;
V_6 = F_20 ( V_137 ) ;
if ( F_121 ( V_6 ) )
return F_131 ( V_6 ) ;
V_60 = F_47 ( sizeof( * V_142 ) + V_136 ) ;
if ( ! V_60 ) {
V_38 = - V_5 ;
goto V_143;
}
V_38 = F_76 ( V_76 , V_8 , V_60 ) ;
F_18 ( V_38 ) ;
V_60 -> V_25 . V_27 = F_13 ( V_137 ) ;
F_109 ( & V_60 -> V_25 , V_26 ) ;
V_60 -> V_25 . V_28 = V_140 ;
V_142 = (struct V_141 * ) V_60 -> V_109 ;
V_142 -> V_144 = * V_139 ;
V_142 -> V_145 = F_132 ( V_76 -> V_145 ) ;
V_142 -> V_52 = 0 ;
V_142 -> V_136 = F_133 ( V_136 ) ;
V_142 -> type = type ;
memcpy ( ( char * ) ( V_142 + 1 ) , V_135 , V_136 ) ;
F_39 ( & V_6 -> V_17 ) ;
V_38 = F_62 ( V_6 , V_60 ) ;
if ( F_134 ( V_38 ) ) {
F_135 ( V_146 L_2
L_3
L_4 ,
V_135 ,
( unsigned long long ) V_6 -> V_8 -> V_27 ,
( unsigned long long ) V_6 -> V_9 ,
V_38 ) ;
F_59 () ;
}
F_40 ( & V_6 -> V_17 ) ;
V_143:
F_44 ( V_6 ) ;
return V_38 ;
}
static int F_136 ( struct V_7 * V_8 ,
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
int F_137 ( struct V_75 * V_76 ,
struct V_7 * V_8 , struct V_32 * V_137 ,
T_2 V_140 )
{
struct V_2 * V_35 ;
struct V_22 * V_53 ;
struct V_56 V_147 ;
int V_38 ;
V_35 = F_20 ( V_137 ) ;
if ( F_121 ( V_35 ) )
return F_131 ( V_35 ) ;
V_147 . V_27 = F_13 ( V_137 ) ;
F_109 ( & V_147 , V_26 ) ;
V_147 . V_28 = V_140 ;
V_38 = F_136 ( V_8 , V_35 , & V_147 ) ;
if ( ! V_38 )
goto V_148;
V_53 = F_47 ( 0 ) ;
if ( ! V_53 ) {
V_38 = - V_5 ;
goto V_148;
}
V_53 -> V_25 = V_147 ;
V_38 = F_76 ( V_76 , V_8 , V_53 ) ;
F_18 ( V_38 ) ;
F_39 ( & V_35 -> V_17 ) ;
V_38 = F_63 ( V_35 , V_53 ) ;
if ( F_134 ( V_38 ) ) {
F_135 ( V_146 L_5
L_6
L_4 ,
( unsigned long long ) V_140 ,
( unsigned long long ) V_35 -> V_8 -> V_27 ,
( unsigned long long ) V_35 -> V_9 ,
V_38 ) ;
F_59 () ;
}
F_40 ( & V_35 -> V_17 ) ;
V_148:
F_44 ( V_35 ) ;
return V_38 ;
}
int F_138 ( struct V_32 * V_32 )
{
struct V_2 * V_6 = F_11 ( V_32 ) ;
if ( ! V_6 )
return - V_114 ;
if ( ! V_6 -> V_18 ) {
F_44 ( V_6 ) ;
return - V_149 ;
}
F_12 ( V_32 ) -> V_18 = V_6 -> V_18 ;
F_44 ( V_6 ) ;
return 0 ;
}
void F_139 ( struct V_32 * V_32 , struct V_48 * V_150 ,
struct V_48 * V_151 )
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
F_30 ( & V_53 -> V_152 , V_150 ) ;
V_53 = F_73 ( V_53 ) ;
}
V_53 = F_72 ( V_6 ) ;
while ( V_53 ) {
F_15 ( & V_53 -> V_10 ) ;
F_30 ( & V_53 -> V_152 , V_151 ) ;
V_53 = F_73 ( V_53 ) ;
}
F_40 ( & V_6 -> V_17 ) ;
F_32 ( & V_6 -> V_10 ) ;
}
void F_140 ( struct V_48 * V_150 ,
struct V_48 * V_151 )
{
struct V_22 * V_93 , * V_51 ;
F_91 (curr, next, ins_list, readdir_list) {
F_94 ( & V_93 -> V_152 ) ;
if ( F_41 ( & V_93 -> V_10 ) )
F_69 ( V_93 ) ;
}
F_91 (curr, next, del_list, readdir_list) {
F_94 ( & V_93 -> V_152 ) ;
if ( F_41 ( & V_93 -> V_10 ) )
F_69 ( V_93 ) ;
}
}
int F_141 ( struct V_48 * V_151 ,
T_2 V_140 )
{
struct V_22 * V_93 , * V_51 ;
int V_38 ;
if ( F_28 ( V_151 ) )
return 0 ;
F_91 (curr, next, del_list, readdir_list) {
if ( V_93 -> V_25 . V_28 > V_140 )
break;
F_94 ( & V_93 -> V_152 ) ;
V_38 = ( V_93 -> V_25 . V_28 == V_140 ) ;
if ( F_41 ( & V_93 -> V_10 ) )
F_69 ( V_93 ) ;
if ( V_38 )
return 1 ;
else
continue;
}
return 0 ;
}
int F_142 ( struct V_153 * V_154 , void * V_155 ,
T_5 V_156 ,
struct V_48 * V_150 )
{
struct V_141 * V_157 ;
struct V_22 * V_93 , * V_51 ;
struct V_56 V_144 ;
char * V_135 ;
int V_136 ;
int V_158 = 0 ;
unsigned char V_159 ;
if ( F_28 ( V_150 ) )
return 0 ;
F_91 (curr, next, ins_list, readdir_list) {
F_94 ( & V_93 -> V_152 ) ;
if ( V_93 -> V_25 . V_28 < V_154 -> V_160 ) {
if ( F_41 ( & V_93 -> V_10 ) )
F_69 ( V_93 ) ;
continue;
}
V_154 -> V_160 = V_93 -> V_25 . V_28 ;
V_157 = (struct V_141 * ) V_93 -> V_109 ;
V_135 = ( char * ) ( V_157 + 1 ) ;
V_136 = F_143 ( V_157 -> V_136 ) ;
V_159 = V_161 [ V_157 -> type ] ;
F_144 ( & V_144 , & V_157 -> V_144 ) ;
V_158 = V_156 ( V_155 , V_135 , V_136 , V_93 -> V_25 . V_28 ,
V_144 . V_27 , V_159 ) ;
if ( F_41 ( & V_93 -> V_10 ) )
F_69 ( V_93 ) ;
if ( V_158 )
return 1 ;
}
return 0 ;
}
static void F_145 ( struct V_75 * V_76 ,
struct V_116 * V_117 ,
struct V_32 * V_32 )
{
F_146 ( V_117 , V_32 -> V_162 ) ;
F_147 ( V_117 , V_32 -> V_163 ) ;
F_148 ( V_117 , F_12 ( V_32 ) -> V_164 ) ;
F_149 ( V_117 , V_32 -> V_165 ) ;
F_150 ( V_117 , V_32 -> V_166 ) ;
F_151 ( V_117 , F_152 ( V_32 ) ) ;
F_153 ( V_117 ,
F_12 ( V_32 ) -> V_167 ) ;
F_154 ( V_117 , F_12 ( V_32 ) -> V_168 ) ;
F_155 ( V_117 , V_76 -> V_145 ) ;
F_156 ( V_117 , V_32 -> V_169 ) ;
F_157 ( V_117 , F_12 ( V_32 ) -> V_131 ) ;
F_158 ( V_117 , 0 ) ;
F_159 ( F_160 ( V_117 ) ,
V_32 -> V_170 . V_171 ) ;
F_161 ( F_160 ( V_117 ) ,
V_32 -> V_170 . V_172 ) ;
F_159 ( F_162 ( V_117 ) ,
V_32 -> V_173 . V_171 ) ;
F_161 ( F_162 ( V_117 ) ,
V_32 -> V_173 . V_172 ) ;
F_159 ( F_163 ( V_117 ) ,
V_32 -> V_174 . V_171 ) ;
F_161 ( F_163 ( V_117 ) ,
V_32 -> V_174 . V_172 ) ;
}
int F_164 ( struct V_32 * V_32 , T_3 * V_175 )
{
struct V_2 * V_6 ;
struct V_116 * V_117 ;
struct V_176 * V_177 ;
V_6 = F_11 ( V_32 ) ;
if ( ! V_6 )
return - V_114 ;
F_39 ( & V_6 -> V_17 ) ;
if ( ! V_6 -> V_13 ) {
F_40 ( & V_6 -> V_17 ) ;
F_44 ( V_6 ) ;
return - V_114 ;
}
V_117 = & V_6 -> V_117 ;
V_32 -> V_162 = F_165 ( V_117 ) ;
V_32 -> V_163 = F_166 ( V_117 ) ;
F_167 ( V_32 , F_168 ( V_117 ) ) ;
V_32 -> V_165 = F_169 ( V_117 ) ;
F_170 ( V_32 , F_171 ( V_117 ) ) ;
F_172 ( V_32 , F_173 ( V_117 ) ) ;
F_12 ( V_32 ) -> V_167 = F_174 ( V_117 ) ;
F_12 ( V_32 ) -> V_168 = F_175 ( V_117 ) ;
V_32 -> V_169 = 0 ;
* V_175 = F_176 ( V_117 ) ;
F_12 ( V_32 ) -> V_131 = F_177 ( V_117 ) ;
V_177 = F_160 ( V_117 ) ;
V_32 -> V_170 . V_171 = F_178 ( V_177 ) ;
V_32 -> V_170 . V_172 = F_179 ( V_177 ) ;
V_177 = F_162 ( V_117 ) ;
V_32 -> V_173 . V_171 = F_178 ( V_177 ) ;
V_32 -> V_173 . V_172 = F_179 ( V_177 ) ;
V_177 = F_163 ( V_117 ) ;
V_32 -> V_174 . V_171 = F_178 ( V_177 ) ;
V_32 -> V_174 . V_172 = F_179 ( V_177 ) ;
V_32 -> V_178 = F_12 ( V_32 ) -> V_167 ;
F_12 ( V_32 ) -> V_18 = ( T_2 ) - 1 ;
F_40 ( & V_6 -> V_17 ) ;
F_44 ( V_6 ) ;
return 0 ;
}
int F_180 ( struct V_75 * V_76 ,
struct V_7 * V_8 , struct V_32 * V_32 )
{
struct V_2 * V_6 ;
int V_38 = 0 ;
V_6 = F_20 ( V_32 ) ;
if ( F_121 ( V_6 ) )
return F_131 ( V_6 ) ;
F_39 ( & V_6 -> V_17 ) ;
if ( V_6 -> V_13 ) {
F_145 ( V_76 , & V_6 -> V_117 , V_32 ) ;
goto V_143;
}
V_38 = F_81 ( V_76 , V_8 , V_32 ,
V_6 ) ;
if ( V_38 )
goto V_143;
F_145 ( V_76 , & V_6 -> V_117 , V_32 ) ;
V_6 -> V_13 = 1 ;
V_6 -> V_11 ++ ;
F_15 ( & V_8 -> V_30 -> V_31 -> V_69 ) ;
V_143:
F_40 ( & V_6 -> V_17 ) ;
F_44 ( V_6 ) ;
return V_38 ;
}
static void F_181 ( struct V_2 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_22 * V_179 , * V_180 ;
F_39 ( & V_6 -> V_17 ) ;
V_179 = F_70 ( V_6 ) ;
while ( V_179 ) {
F_79 ( V_8 , V_179 ) ;
V_180 = V_179 ;
V_179 = F_73 ( V_180 ) ;
F_68 ( V_180 ) ;
}
V_179 = F_72 ( V_6 ) ;
while ( V_179 ) {
F_79 ( V_8 , V_179 ) ;
V_180 = V_179 ;
V_179 = F_73 ( V_180 ) ;
F_68 ( V_180 ) ;
}
if ( V_6 -> V_13 ) {
F_84 ( V_8 , V_6 ) ;
F_107 ( V_6 ) ;
}
F_40 ( & V_6 -> V_17 ) ;
}
void F_182 ( struct V_32 * V_32 )
{
struct V_2 * V_6 ;
V_6 = F_11 ( V_32 ) ;
if ( ! V_6 )
return;
F_181 ( V_6 ) ;
F_44 ( V_6 ) ;
}
void F_183 ( struct V_7 * V_8 )
{
T_2 V_9 = 0 ;
struct V_2 * V_181 [ 8 ] ;
int V_105 , V_182 ;
while ( 1 ) {
F_16 ( & V_8 -> V_36 ) ;
V_182 = F_184 ( & V_8 -> V_37 ,
( void * * ) V_181 , V_9 ,
F_185 ( V_181 ) ) ;
if ( ! V_182 ) {
F_19 ( & V_8 -> V_36 ) ;
break;
}
V_9 = V_181 [ V_182 - 1 ] -> V_9 + 1 ;
for ( V_105 = 0 ; V_105 < V_182 ; V_105 ++ )
F_15 ( & V_181 [ V_105 ] -> V_10 ) ;
F_19 ( & V_8 -> V_36 ) ;
for ( V_105 = 0 ; V_105 < V_182 ; V_105 ++ ) {
F_181 ( V_181 [ V_105 ] ) ;
F_44 ( V_181 [ V_105 ] ) ;
}
}
}
