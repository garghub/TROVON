struct V_1 * F_1 ( void )
{
return F_2 ( V_2 , V_3 ) ;
}
T_1 void F_3 ( struct V_1 * V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( ! V_4 -> V_7 [ V_5 ] || ! V_4 -> V_8 [ V_5 ] )
continue;
F_4 ( V_4 -> V_7 [ V_5 ] , V_4 -> V_8 [ V_5 ] ) ;
if ( V_4 -> V_8 [ V_5 ] == V_9 )
V_4 -> V_8 [ V_5 ] = V_10 ;
else if ( V_4 -> V_8 [ V_5 ] == V_11 )
V_4 -> V_8 [ V_5 ] = V_12 ;
}
}
T_1 void F_5 ( struct V_1 * V_4 ,
struct V_13 * V_14 , int V_15 )
{
int V_5 ;
if ( V_14 ) {
F_4 ( V_14 , V_15 ) ;
if ( V_15 == V_11 )
V_15 = V_12 ;
else if ( V_15 == V_9 )
V_15 = V_10 ;
}
F_3 ( V_4 ) ;
for ( V_5 = V_6 - 1 ; V_5 >= 0 ; V_5 -- ) {
if ( V_4 -> V_7 [ V_5 ] && V_4 -> V_8 [ V_5 ] ) {
F_6 ( V_4 -> V_7 [ V_5 ] , V_4 -> V_8 [ V_5 ] ) ;
if ( V_4 -> V_8 [ V_5 ] == V_12 )
V_4 -> V_8 [ V_5 ] = V_11 ;
else if ( V_4 -> V_8 [ V_5 ] == V_10 )
V_4 -> V_8 [ V_5 ] = V_9 ;
}
}
if ( V_14 )
F_6 ( V_14 , V_15 ) ;
}
void F_7 ( struct V_1 * V_4 )
{
if ( ! V_4 )
return;
F_8 ( V_4 ) ;
F_9 ( V_2 , V_4 ) ;
}
T_1 void F_8 ( struct V_1 * V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
V_4 -> V_16 [ V_5 ] = 0 ;
if ( ! V_4 -> V_7 [ V_5 ] )
continue;
if ( V_4 -> V_8 [ V_5 ] ) {
F_10 ( V_4 -> V_7 [ V_5 ] , V_4 -> V_8 [ V_5 ] ) ;
V_4 -> V_8 [ V_5 ] = 0 ;
}
F_11 ( V_4 -> V_7 [ V_5 ] ) ;
V_4 -> V_7 [ V_5 ] = NULL ;
}
}
struct V_13 * F_12 ( struct V_17 * V_18 )
{
struct V_13 * V_19 ;
while ( 1 ) {
F_13 () ;
V_19 = F_14 ( V_18 -> V_20 ) ;
if ( F_15 ( & V_19 -> V_21 ) ) {
F_16 () ;
break;
}
F_16 () ;
F_17 () ;
}
return V_19 ;
}
struct V_13 * F_18 ( struct V_17 * V_18 )
{
struct V_13 * V_19 ;
while ( 1 ) {
V_19 = F_12 ( V_18 ) ;
F_19 ( V_19 ) ;
if ( V_19 == V_18 -> V_20 )
break;
F_20 ( V_19 ) ;
F_11 ( V_19 ) ;
}
return V_19 ;
}
static struct V_13 * F_21 ( struct V_17 * V_18 )
{
struct V_13 * V_19 ;
while ( 1 ) {
V_19 = F_12 ( V_18 ) ;
F_22 ( V_19 ) ;
if ( V_19 == V_18 -> V_20 )
break;
F_23 ( V_19 ) ;
F_11 ( V_19 ) ;
}
return V_19 ;
}
static void F_24 ( struct V_17 * V_18 )
{
if ( F_25 ( V_22 , & V_18 -> V_23 ) ||
! F_25 ( V_24 , & V_18 -> V_23 ) )
return;
F_26 ( & V_18 -> V_25 -> V_26 ) ;
if ( ! F_27 ( V_22 , & V_18 -> V_23 ) ) {
if ( V_18 -> V_27 == V_28 )
F_28 ( & V_18 -> V_29 ,
& V_18 -> V_25 -> V_30 ) ;
else
F_29 ( & V_18 -> V_29 ,
& V_18 -> V_25 -> V_30 ) ;
}
F_30 ( & V_18 -> V_25 -> V_26 ) ;
}
int F_31 ( struct V_31 * V_32 ,
struct V_17 * V_18 ,
struct V_13 * V_33 ,
struct V_13 * * V_34 , T_2 V_35 )
{
struct V_13 * V_36 ;
int V_37 = 0 ;
int V_38 ;
struct V_39 V_40 ;
F_32 ( F_25 ( V_41 , & V_18 -> V_23 ) &&
V_32 -> V_42 != V_18 -> V_25 -> V_43 -> V_42 ) ;
F_32 ( F_25 ( V_41 , & V_18 -> V_23 ) &&
V_32 -> V_42 != V_18 -> V_44 ) ;
V_38 = F_33 ( V_33 ) ;
if ( V_38 == 0 )
F_34 ( V_33 , & V_40 , 0 ) ;
else
F_35 ( V_33 , & V_40 , 0 ) ;
V_36 = F_36 ( V_32 , V_18 , 0 , V_35 ,
& V_40 , V_38 , V_33 -> V_45 , 0 ) ;
if ( F_37 ( V_36 ) )
return F_38 ( V_36 ) ;
F_39 ( V_36 , V_33 , 0 , 0 , V_36 -> V_46 ) ;
F_40 ( V_36 , V_36 -> V_45 ) ;
F_41 ( V_36 , V_32 -> V_42 ) ;
F_42 ( V_36 , V_47 ) ;
F_43 ( V_36 , V_48 |
V_49 ) ;
if ( V_35 == V_50 )
F_44 ( V_36 , V_49 ) ;
else
F_45 ( V_36 , V_35 ) ;
F_46 ( V_36 , V_18 -> V_25 -> V_51 , F_47 () ,
V_52 ) ;
F_32 ( F_48 ( V_33 ) > V_32 -> V_42 ) ;
if ( V_35 == V_50 )
V_37 = F_49 ( V_32 , V_18 , V_36 , 1 ) ;
else
V_37 = F_49 ( V_32 , V_18 , V_36 , 0 ) ;
if ( V_37 )
return V_37 ;
F_50 ( V_36 ) ;
* V_34 = V_36 ;
return 0 ;
}
static inline void F_51 ( struct V_53 * V_25 )
{
F_52 ( & V_25 -> V_54 ) ;
}
static inline void F_53 ( struct V_53 * V_25 )
{
F_54 ( & V_25 -> V_54 ) ;
}
static inline void F_55 ( struct V_53 * V_25 )
{
F_56 ( & V_25 -> V_54 ) ;
}
static inline void F_57 ( struct V_53 * V_25 )
{
F_58 ( & V_25 -> V_54 ) ;
}
static inline T_2 F_59 ( struct V_53 * V_25 )
{
return F_60 ( & V_25 -> V_55 ) ;
}
T_2 F_61 ( struct V_53 * V_25 ,
struct V_56 * V_57 )
{
F_55 ( V_25 ) ;
F_26 ( & V_25 -> V_58 ) ;
if ( ! V_57 -> V_59 ) {
V_57 -> V_59 = F_59 ( V_25 ) ;
F_62 ( & V_57 -> V_60 , & V_25 -> V_61 ) ;
}
F_30 ( & V_25 -> V_58 ) ;
F_57 ( V_25 ) ;
return V_57 -> V_59 ;
}
void F_63 ( struct V_53 * V_25 ,
struct V_56 * V_57 )
{
struct V_62 * V_63 ;
struct V_64 * V_20 ;
struct V_64 * V_65 ;
struct V_56 * V_66 ;
struct V_67 * V_68 ;
T_2 V_69 = ( T_2 ) - 1 ;
T_2 V_70 = V_57 -> V_59 ;
if ( ! V_70 )
return;
F_26 ( & V_25 -> V_58 ) ;
F_64 ( & V_57 -> V_60 ) ;
V_57 -> V_59 = 0 ;
F_65 (cur_elem, &fs_info->tree_mod_seq_list, list) {
if ( V_66 -> V_59 < V_69 ) {
if ( V_70 > V_66 -> V_59 ) {
F_30 ( & V_25 -> V_58 ) ;
return;
}
V_69 = V_66 -> V_59 ;
}
}
F_30 ( & V_25 -> V_58 ) ;
F_55 ( V_25 ) ;
V_63 = & V_25 -> V_71 ;
for ( V_20 = F_66 ( V_63 ) ; V_20 ; V_20 = V_65 ) {
V_65 = F_67 ( V_20 ) ;
V_68 = F_68 ( V_20 , struct V_67 , V_20 ) ;
if ( V_68 -> V_59 > V_69 )
continue;
F_69 ( V_20 , V_63 ) ;
F_70 ( V_68 ) ;
}
F_57 ( V_25 ) ;
}
static T_1 int
F_71 ( struct V_53 * V_25 , struct V_67 * V_68 )
{
struct V_62 * V_63 ;
struct V_64 * * V_72 ;
struct V_64 * V_73 = NULL ;
struct V_67 * V_74 ;
F_72 ( ! V_68 ) ;
V_68 -> V_59 = F_59 ( V_25 ) ;
V_63 = & V_25 -> V_71 ;
V_72 = & V_63 -> V_64 ;
while ( * V_72 ) {
V_74 = F_68 ( * V_72 , struct V_67 , V_20 ) ;
V_73 = * V_72 ;
if ( V_74 -> V_75 < V_68 -> V_75 )
V_72 = & ( ( * V_72 ) -> V_76 ) ;
else if ( V_74 -> V_75 > V_68 -> V_75 )
V_72 = & ( ( * V_72 ) -> V_77 ) ;
else if ( V_74 -> V_59 < V_68 -> V_59 )
V_72 = & ( ( * V_72 ) -> V_76 ) ;
else if ( V_74 -> V_59 > V_68 -> V_59 )
V_72 = & ( ( * V_72 ) -> V_77 ) ;
else
return - V_78 ;
}
F_73 ( & V_68 -> V_20 , V_73 , V_72 ) ;
F_74 ( & V_68 -> V_20 , V_63 ) ;
return 0 ;
}
static inline int F_75 ( struct V_53 * V_25 ,
struct V_13 * V_19 ) {
F_76 () ;
if ( F_77 ( & ( V_25 ) -> V_61 ) )
return 1 ;
if ( V_19 && F_33 ( V_19 ) == 0 )
return 1 ;
F_55 ( V_25 ) ;
if ( F_77 ( & ( V_25 ) -> V_61 ) ) {
F_57 ( V_25 ) ;
return 1 ;
}
return 0 ;
}
static inline int F_78 ( const struct V_53 * V_25 ,
struct V_13 * V_19 )
{
F_76 () ;
if ( F_77 ( & ( V_25 ) -> V_61 ) )
return 0 ;
if ( V_19 && F_33 ( V_19 ) == 0 )
return 0 ;
return 1 ;
}
static struct V_67 *
F_79 ( struct V_13 * V_19 , int V_79 ,
enum V_80 V_81 , T_3 V_82 )
{
struct V_67 * V_68 ;
V_68 = F_80 ( sizeof( * V_68 ) , V_82 ) ;
if ( ! V_68 )
return NULL ;
V_68 -> V_75 = V_19 -> V_45 ;
if ( V_81 != V_83 ) {
F_35 ( V_19 , & V_68 -> V_84 , V_79 ) ;
V_68 -> V_85 = F_81 ( V_19 , V_79 ) ;
}
V_68 -> V_81 = V_81 ;
V_68 -> V_79 = V_79 ;
V_68 -> V_86 = F_82 ( V_19 , V_79 ) ;
F_83 ( & V_68 -> V_20 ) ;
return V_68 ;
}
static T_1 int
F_84 ( struct V_53 * V_25 ,
struct V_13 * V_19 , int V_79 ,
enum V_80 V_81 , T_3 V_82 )
{
struct V_67 * V_68 ;
int V_37 ;
if ( ! F_78 ( V_25 , V_19 ) )
return 0 ;
V_68 = F_79 ( V_19 , V_79 , V_81 , V_82 ) ;
if ( ! V_68 )
return - V_87 ;
if ( F_75 ( V_25 , V_19 ) ) {
F_70 ( V_68 ) ;
return 0 ;
}
V_37 = F_71 ( V_25 , V_68 ) ;
F_57 ( V_25 ) ;
if ( V_37 )
F_70 ( V_68 ) ;
return V_37 ;
}
static T_1 int
F_85 ( struct V_53 * V_25 ,
struct V_13 * V_19 , int V_88 , int V_89 ,
int V_90 , T_3 V_82 )
{
struct V_67 * V_68 = NULL ;
struct V_67 * * V_91 = NULL ;
int V_37 = 0 ;
int V_5 ;
int V_92 = 0 ;
if ( ! F_78 ( V_25 , V_19 ) )
return 0 ;
V_91 = F_86 ( V_90 , sizeof( struct V_67 * ) , V_82 ) ;
if ( ! V_91 )
return - V_87 ;
V_68 = F_80 ( sizeof( * V_68 ) , V_82 ) ;
if ( ! V_68 ) {
V_37 = - V_87 ;
goto V_93;
}
V_68 -> V_75 = V_19 -> V_45 ;
V_68 -> V_79 = V_89 ;
V_68 -> V_94 . V_88 = V_88 ;
V_68 -> V_94 . V_90 = V_90 ;
V_68 -> V_81 = V_95 ;
for ( V_5 = 0 ; V_5 + V_88 < V_89 && V_5 < V_90 ; V_5 ++ ) {
V_91 [ V_5 ] = F_79 ( V_19 , V_5 + V_88 ,
V_96 , V_82 ) ;
if ( ! V_91 [ V_5 ] ) {
V_37 = - V_87 ;
goto V_93;
}
}
if ( F_75 ( V_25 , V_19 ) )
goto V_93;
V_92 = 1 ;
for ( V_5 = 0 ; V_5 + V_88 < V_89 && V_5 < V_90 ; V_5 ++ ) {
V_37 = F_71 ( V_25 , V_91 [ V_5 ] ) ;
if ( V_37 )
goto V_93;
}
V_37 = F_71 ( V_25 , V_68 ) ;
if ( V_37 )
goto V_93;
F_57 ( V_25 ) ;
F_70 ( V_91 ) ;
return 0 ;
V_93:
for ( V_5 = 0 ; V_5 < V_90 ; V_5 ++ ) {
if ( V_91 [ V_5 ] && ! F_87 ( & V_91 [ V_5 ] -> V_20 ) )
F_69 ( & V_91 [ V_5 ] -> V_20 , & V_25 -> V_71 ) ;
F_70 ( V_91 [ V_5 ] ) ;
}
if ( V_92 )
F_57 ( V_25 ) ;
F_70 ( V_91 ) ;
F_70 ( V_68 ) ;
return V_37 ;
}
static inline int
F_88 ( struct V_53 * V_25 ,
struct V_67 * * V_91 ,
int V_97 )
{
int V_5 , V_98 ;
int V_37 ;
for ( V_5 = V_97 - 1 ; V_5 >= 0 ; V_5 -- ) {
V_37 = F_71 ( V_25 , V_91 [ V_5 ] ) ;
if ( V_37 ) {
for ( V_98 = V_97 - 1 ; V_98 > V_5 ; V_98 -- )
F_69 ( & V_91 [ V_98 ] -> V_20 ,
& V_25 -> V_71 ) ;
return V_37 ;
}
}
return 0 ;
}
static T_1 int
F_89 ( struct V_53 * V_25 ,
struct V_13 * V_99 ,
struct V_13 * V_100 , T_3 V_82 ,
int V_101 )
{
struct V_67 * V_68 = NULL ;
struct V_67 * * V_91 = NULL ;
int V_97 = 0 ;
int V_37 = 0 ;
int V_5 ;
if ( ! F_78 ( V_25 , NULL ) )
return 0 ;
if ( V_101 && F_33 ( V_99 ) > 0 ) {
V_97 = F_90 ( V_99 ) ;
V_91 = F_86 ( V_97 , sizeof( struct V_67 * ) ,
V_82 ) ;
if ( ! V_91 ) {
V_37 = - V_87 ;
goto V_93;
}
for ( V_5 = 0 ; V_5 < V_97 ; V_5 ++ ) {
V_91 [ V_5 ] = F_79 ( V_99 , V_5 ,
V_102 , V_82 ) ;
if ( ! V_91 [ V_5 ] ) {
V_37 = - V_87 ;
goto V_93;
}
}
}
V_68 = F_80 ( sizeof( * V_68 ) , V_82 ) ;
if ( ! V_68 ) {
V_37 = - V_87 ;
goto V_93;
}
V_68 -> V_75 = V_100 -> V_45 ;
V_68 -> V_99 . V_75 = V_99 -> V_45 ;
V_68 -> V_99 . V_38 = F_33 ( V_99 ) ;
V_68 -> V_86 = F_48 ( V_99 ) ;
V_68 -> V_81 = V_103 ;
if ( F_75 ( V_25 , NULL ) )
goto V_93;
if ( V_91 )
V_37 = F_88 ( V_25 , V_91 , V_97 ) ;
if ( ! V_37 )
V_37 = F_71 ( V_25 , V_68 ) ;
F_57 ( V_25 ) ;
if ( V_37 )
goto V_93;
F_70 ( V_91 ) ;
return V_37 ;
V_93:
if ( V_91 ) {
for ( V_5 = 0 ; V_5 < V_97 ; V_5 ++ )
F_70 ( V_91 [ V_5 ] ) ;
F_70 ( V_91 ) ;
}
F_70 ( V_68 ) ;
return V_37 ;
}
static struct V_67 *
F_91 ( struct V_53 * V_25 , T_2 V_45 , T_2 V_69 ,
int V_104 )
{
struct V_62 * V_63 ;
struct V_64 * V_20 ;
struct V_67 * V_74 = NULL ;
struct V_67 * V_105 = NULL ;
F_51 ( V_25 ) ;
V_63 = & V_25 -> V_71 ;
V_20 = V_63 -> V_64 ;
while ( V_20 ) {
V_74 = F_68 ( V_20 , struct V_67 , V_20 ) ;
if ( V_74 -> V_75 < V_45 ) {
V_20 = V_20 -> V_76 ;
} else if ( V_74 -> V_75 > V_45 ) {
V_20 = V_20 -> V_77 ;
} else if ( V_74 -> V_59 < V_69 ) {
V_20 = V_20 -> V_76 ;
} else if ( ! V_104 ) {
if ( V_105 )
F_72 ( V_105 -> V_59 > V_74 -> V_59 ) ;
V_105 = V_74 ;
V_20 = V_20 -> V_76 ;
} else if ( V_74 -> V_59 > V_69 ) {
if ( V_105 )
F_72 ( V_105 -> V_59 < V_74 -> V_59 ) ;
V_105 = V_74 ;
V_20 = V_20 -> V_77 ;
} else {
V_105 = V_74 ;
break;
}
}
F_53 ( V_25 ) ;
return V_105 ;
}
static struct V_67 *
F_92 ( struct V_53 * V_25 , T_2 V_45 ,
T_2 V_69 )
{
return F_91 ( V_25 , V_45 , V_69 , 1 ) ;
}
static struct V_67 *
F_93 ( struct V_53 * V_25 , T_2 V_45 , T_2 V_69 )
{
return F_91 ( V_25 , V_45 , V_69 , 0 ) ;
}
static T_1 int
F_94 ( struct V_53 * V_25 , struct V_13 * V_106 ,
struct V_13 * V_107 , unsigned long V_108 ,
unsigned long V_109 , int V_90 )
{
int V_37 = 0 ;
struct V_67 * * V_91 = NULL ;
struct V_67 * * V_110 , * * V_111 ;
int V_5 ;
int V_92 = 0 ;
if ( ! F_78 ( V_25 , NULL ) )
return 0 ;
if ( F_33 ( V_106 ) == 0 && F_33 ( V_107 ) == 0 )
return 0 ;
V_91 = F_86 ( V_90 * 2 , sizeof( struct V_67 * ) ,
V_3 ) ;
if ( ! V_91 )
return - V_87 ;
V_110 = V_91 ;
V_111 = V_91 + V_90 ;
for ( V_5 = 0 ; V_5 < V_90 ; V_5 ++ ) {
V_111 [ V_5 ] = F_79 ( V_107 , V_5 + V_109 ,
V_112 , V_3 ) ;
if ( ! V_111 [ V_5 ] ) {
V_37 = - V_87 ;
goto V_93;
}
V_110 [ V_5 ] = F_79 ( V_106 , V_5 + V_108 ,
V_83 , V_3 ) ;
if ( ! V_110 [ V_5 ] ) {
V_37 = - V_87 ;
goto V_93;
}
}
if ( F_75 ( V_25 , NULL ) )
goto V_93;
V_92 = 1 ;
for ( V_5 = 0 ; V_5 < V_90 ; V_5 ++ ) {
V_37 = F_71 ( V_25 , V_111 [ V_5 ] ) ;
if ( V_37 )
goto V_93;
V_37 = F_71 ( V_25 , V_110 [ V_5 ] ) ;
if ( V_37 )
goto V_93;
}
F_57 ( V_25 ) ;
F_70 ( V_91 ) ;
return 0 ;
V_93:
for ( V_5 = 0 ; V_5 < V_90 * 2 ; V_5 ++ ) {
if ( V_91 [ V_5 ] && ! F_87 ( & V_91 [ V_5 ] -> V_20 ) )
F_69 ( & V_91 [ V_5 ] -> V_20 , & V_25 -> V_71 ) ;
F_70 ( V_91 [ V_5 ] ) ;
}
if ( V_92 )
F_57 ( V_25 ) ;
F_70 ( V_91 ) ;
return V_37 ;
}
static inline void
F_95 ( struct V_53 * V_25 , struct V_13 * V_106 ,
int V_108 , int V_109 , int V_90 )
{
int V_37 ;
V_37 = F_85 ( V_25 , V_106 , V_108 , V_109 ,
V_90 , V_3 ) ;
F_72 ( V_37 < 0 ) ;
}
static T_1 void
F_96 ( struct V_53 * V_25 ,
struct V_13 * V_19 , int V_79 , int V_113 )
{
int V_37 ;
V_37 = F_84 ( V_25 , V_19 , V_79 ,
V_114 ,
V_113 ? V_115 : V_3 ) ;
F_72 ( V_37 < 0 ) ;
}
static T_1 int
F_97 ( struct V_53 * V_25 , struct V_13 * V_19 )
{
struct V_67 * * V_91 = NULL ;
int V_97 = 0 ;
int V_5 ;
int V_37 = 0 ;
if ( F_33 ( V_19 ) == 0 )
return 0 ;
if ( ! F_78 ( V_25 , NULL ) )
return 0 ;
V_97 = F_90 ( V_19 ) ;
V_91 = F_86 ( V_97 , sizeof( struct V_67 * ) , V_3 ) ;
if ( ! V_91 )
return - V_87 ;
for ( V_5 = 0 ; V_5 < V_97 ; V_5 ++ ) {
V_91 [ V_5 ] = F_79 ( V_19 , V_5 ,
V_102 , V_3 ) ;
if ( ! V_91 [ V_5 ] ) {
V_37 = - V_87 ;
goto V_93;
}
}
if ( F_75 ( V_25 , V_19 ) )
goto V_93;
V_37 = F_88 ( V_25 , V_91 , V_97 ) ;
F_57 ( V_25 ) ;
if ( V_37 )
goto V_93;
F_70 ( V_91 ) ;
return 0 ;
V_93:
for ( V_5 = 0 ; V_5 < V_97 ; V_5 ++ )
F_70 ( V_91 [ V_5 ] ) ;
F_70 ( V_91 ) ;
return V_37 ;
}
static T_1 void
F_98 ( struct V_17 * V_18 ,
struct V_13 * V_116 ,
int V_101 )
{
int V_37 ;
V_37 = F_89 ( V_18 -> V_25 , V_18 -> V_20 ,
V_116 , V_3 , V_101 ) ;
F_72 ( V_37 < 0 ) ;
}
int F_99 ( struct V_17 * V_18 ,
struct V_13 * V_33 )
{
if ( F_25 ( V_41 , & V_18 -> V_23 ) &&
V_33 != V_18 -> V_20 && V_33 != V_18 -> V_117 &&
( F_48 ( V_33 ) <=
F_100 ( & V_18 -> V_118 ) ||
F_101 ( V_33 , V_49 ) ) )
return 1 ;
#ifdef F_102
if ( F_25 ( V_41 , & V_18 -> V_23 ) &&
F_103 ( V_33 ) < V_47 )
return 1 ;
#endif
return 0 ;
}
static T_1 int F_104 ( struct V_31 * V_32 ,
struct V_17 * V_18 ,
struct V_13 * V_33 ,
struct V_13 * V_36 ,
int * V_119 )
{
T_2 V_21 ;
T_2 V_120 ;
T_2 V_82 ;
T_2 V_121 = 0 ;
int V_37 ;
if ( F_99 ( V_18 , V_33 ) ) {
V_37 = F_105 ( V_32 , V_18 , V_33 -> V_45 ,
F_33 ( V_33 ) , 1 ,
& V_21 , & V_82 ) ;
if ( V_37 )
return V_37 ;
if ( V_21 == 0 ) {
V_37 = - V_122 ;
F_106 ( V_18 -> V_25 , V_37 , NULL ) ;
return V_37 ;
}
} else {
V_21 = 1 ;
if ( V_18 -> V_123 . V_27 == V_50 ||
F_103 ( V_33 ) < V_47 )
V_82 = V_124 ;
else
V_82 = 0 ;
}
V_120 = F_107 ( V_33 ) ;
F_72 ( V_120 == V_50 &&
! ( V_82 & V_124 ) ) ;
if ( V_21 > 1 ) {
if ( ( V_120 == V_18 -> V_123 . V_27 ||
V_18 -> V_123 . V_27 == V_50 ) &&
! ( V_82 & V_124 ) ) {
V_37 = F_49 ( V_32 , V_18 , V_33 , 1 ) ;
F_72 ( V_37 ) ;
if ( V_18 -> V_123 . V_27 ==
V_50 ) {
V_37 = F_108 ( V_32 , V_18 , V_33 , 0 ) ;
F_72 ( V_37 ) ;
V_37 = F_49 ( V_32 , V_18 , V_36 , 1 ) ;
F_72 ( V_37 ) ;
}
V_121 |= V_124 ;
} else {
if ( V_18 -> V_123 . V_27 ==
V_50 )
V_37 = F_49 ( V_32 , V_18 , V_36 , 1 ) ;
else
V_37 = F_49 ( V_32 , V_18 , V_36 , 0 ) ;
F_72 ( V_37 ) ;
}
if ( V_121 != 0 ) {
int V_38 = F_33 ( V_33 ) ;
V_37 = F_109 ( V_32 , V_18 ,
V_33 -> V_45 ,
V_33 -> V_46 ,
V_121 , V_38 , 0 ) ;
if ( V_37 )
return V_37 ;
}
} else {
if ( V_82 & V_124 ) {
if ( V_18 -> V_123 . V_27 ==
V_50 )
V_37 = F_49 ( V_32 , V_18 , V_36 , 1 ) ;
else
V_37 = F_49 ( V_32 , V_18 , V_36 , 0 ) ;
F_72 ( V_37 ) ;
V_37 = F_108 ( V_32 , V_18 , V_33 , 1 ) ;
F_72 ( V_37 ) ;
}
F_110 ( V_32 , V_18 -> V_25 , V_33 ) ;
* V_119 = 1 ;
}
return 0 ;
}
static T_1 int F_111 ( struct V_31 * V_32 ,
struct V_17 * V_18 ,
struct V_13 * V_33 ,
struct V_13 * V_73 , int V_125 ,
struct V_13 * * V_34 ,
T_2 V_126 , T_2 V_127 )
{
struct V_39 V_40 ;
struct V_13 * V_36 ;
int V_38 , V_37 ;
int V_119 = 0 ;
int V_128 = 0 ;
T_2 V_129 = 0 ;
if ( * V_34 == V_33 )
V_128 = 1 ;
F_112 ( V_33 ) ;
F_32 ( F_25 ( V_41 , & V_18 -> V_23 ) &&
V_32 -> V_42 != V_18 -> V_25 -> V_43 -> V_42 ) ;
F_32 ( F_25 ( V_41 , & V_18 -> V_23 ) &&
V_32 -> V_42 != V_18 -> V_44 ) ;
V_38 = F_33 ( V_33 ) ;
if ( V_38 == 0 )
F_34 ( V_33 , & V_40 , 0 ) ;
else
F_35 ( V_33 , & V_40 , 0 ) ;
if ( ( V_18 -> V_123 . V_27 == V_50 ) && V_73 )
V_129 = V_73 -> V_45 ;
V_36 = F_36 ( V_32 , V_18 , V_129 ,
V_18 -> V_123 . V_27 , & V_40 , V_38 ,
V_126 , V_127 ) ;
if ( F_37 ( V_36 ) )
return F_38 ( V_36 ) ;
F_39 ( V_36 , V_33 , 0 , 0 , V_36 -> V_46 ) ;
F_40 ( V_36 , V_36 -> V_45 ) ;
F_41 ( V_36 , V_32 -> V_42 ) ;
F_42 ( V_36 , V_47 ) ;
F_43 ( V_36 , V_48 |
V_49 ) ;
if ( V_18 -> V_123 . V_27 == V_50 )
F_44 ( V_36 , V_49 ) ;
else
F_45 ( V_36 , V_18 -> V_123 . V_27 ) ;
F_46 ( V_36 , V_18 -> V_25 -> V_51 , F_47 () ,
V_52 ) ;
V_37 = F_104 ( V_32 , V_18 , V_33 , V_36 , & V_119 ) ;
if ( V_37 ) {
F_113 ( V_32 , V_37 ) ;
return V_37 ;
}
if ( F_25 ( V_41 , & V_18 -> V_23 ) ) {
V_37 = F_114 ( V_32 , V_18 , V_33 , V_36 ) ;
if ( V_37 ) {
F_113 ( V_32 , V_37 ) ;
return V_37 ;
}
}
if ( V_33 == V_18 -> V_20 ) {
F_32 ( V_73 && V_73 != V_33 ) ;
if ( V_18 -> V_123 . V_27 == V_50 ||
F_103 ( V_33 ) < V_47 )
V_129 = V_33 -> V_45 ;
F_115 ( V_36 ) ;
F_98 ( V_18 , V_36 , 1 ) ;
F_116 ( V_18 -> V_20 , V_36 ) ;
F_117 ( V_32 , V_18 , V_33 , V_129 ,
V_119 ) ;
F_11 ( V_33 ) ;
F_24 ( V_18 ) ;
} else {
F_32 ( V_32 -> V_42 != F_48 ( V_73 ) ) ;
F_84 ( V_18 -> V_25 , V_73 , V_125 ,
V_114 , V_3 ) ;
F_118 ( V_73 , V_125 ,
V_36 -> V_45 ) ;
F_119 ( V_73 , V_125 ,
V_32 -> V_42 ) ;
F_50 ( V_73 ) ;
if ( V_119 ) {
V_37 = F_97 ( V_18 -> V_25 , V_33 ) ;
if ( V_37 ) {
F_113 ( V_32 , V_37 ) ;
return V_37 ;
}
}
F_117 ( V_32 , V_18 , V_33 , V_129 ,
V_119 ) ;
}
if ( V_128 )
F_20 ( V_33 ) ;
F_120 ( V_33 ) ;
F_50 ( V_36 ) ;
* V_34 = V_36 ;
return 0 ;
}
static struct V_67 *
F_121 ( struct V_53 * V_25 ,
struct V_13 * V_130 , T_2 V_131 )
{
struct V_67 * V_68 ;
struct V_67 * V_105 = NULL ;
T_2 V_132 = V_130 -> V_45 ;
int V_133 = 0 ;
if ( ! V_131 )
return NULL ;
while ( 1 ) {
V_68 = F_92 ( V_25 , V_132 ,
V_131 ) ;
if ( ! V_133 && ! V_68 )
return NULL ;
if ( ! V_68 )
break;
if ( V_68 -> V_81 != V_103 )
break;
V_105 = V_68 ;
V_132 = V_68 -> V_99 . V_75 ;
V_133 = 1 ;
}
if ( ! V_105 )
V_105 = V_68 ;
return V_105 ;
}
static void
F_122 ( struct V_53 * V_25 , struct V_13 * V_19 ,
T_2 V_131 , struct V_67 * V_134 )
{
T_4 V_135 ;
struct V_64 * V_65 ;
struct V_67 * V_68 = V_134 ;
unsigned long V_136 ;
unsigned long V_137 ;
unsigned long V_138 = sizeof( struct V_139 ) ;
V_135 = F_90 ( V_19 ) ;
F_51 ( V_25 ) ;
while ( V_68 && V_68 -> V_59 >= V_131 ) {
switch ( V_68 -> V_81 ) {
case V_102 :
F_72 ( V_68 -> V_79 < V_135 ) ;
case V_96 :
case V_112 :
F_123 ( V_19 , & V_68 -> V_84 , V_68 -> V_79 ) ;
F_118 ( V_19 , V_68 -> V_79 , V_68 -> V_85 ) ;
F_119 ( V_19 , V_68 -> V_79 ,
V_68 -> V_86 ) ;
V_135 ++ ;
break;
case V_114 :
F_72 ( V_68 -> V_79 >= V_135 ) ;
F_123 ( V_19 , & V_68 -> V_84 , V_68 -> V_79 ) ;
F_118 ( V_19 , V_68 -> V_79 , V_68 -> V_85 ) ;
F_119 ( V_19 , V_68 -> V_79 ,
V_68 -> V_86 ) ;
break;
case V_83 :
V_135 -- ;
break;
case V_95 :
V_136 = F_124 ( V_68 -> V_79 ) ;
V_137 = F_124 ( V_68 -> V_94 . V_88 ) ;
F_125 ( V_19 , V_136 , V_137 ,
V_68 -> V_94 . V_90 * V_138 ) ;
break;
case V_103 :
break;
}
V_65 = F_67 ( & V_68 -> V_20 ) ;
if ( ! V_65 )
break;
V_68 = F_68 ( V_65 , struct V_67 , V_20 ) ;
if ( V_68 -> V_75 != V_134 -> V_75 )
break;
}
F_53 ( V_25 ) ;
F_126 ( V_19 , V_135 ) ;
}
static struct V_13 *
F_127 ( struct V_53 * V_25 , struct V_1 * V_140 ,
struct V_13 * V_19 , T_2 V_131 )
{
struct V_13 * V_141 ;
struct V_67 * V_68 ;
if ( ! V_131 )
return V_19 ;
if ( F_33 ( V_19 ) == 0 )
return V_19 ;
V_68 = F_93 ( V_25 , V_19 -> V_45 , V_131 ) ;
if ( ! V_68 )
return V_19 ;
F_3 ( V_140 ) ;
F_4 ( V_19 , V_9 ) ;
if ( V_68 -> V_81 == V_102 ) {
F_72 ( V_68 -> V_79 != 0 ) ;
V_141 = F_128 ( V_25 , V_19 -> V_45 ,
V_19 -> V_46 ) ;
if ( ! V_141 ) {
F_129 ( V_19 ) ;
F_11 ( V_19 ) ;
return NULL ;
}
F_40 ( V_141 , V_19 -> V_45 ) ;
F_42 ( V_141 ,
F_103 ( V_19 ) ) ;
F_45 ( V_141 , F_107 ( V_19 ) ) ;
F_130 ( V_141 , F_33 ( V_19 ) ) ;
} else {
V_141 = F_131 ( V_19 ) ;
if ( ! V_141 ) {
F_129 ( V_19 ) ;
F_11 ( V_19 ) ;
return NULL ;
}
}
F_5 ( V_140 , NULL , V_9 ) ;
F_129 ( V_19 ) ;
F_11 ( V_19 ) ;
F_115 ( V_141 ) ;
F_22 ( V_141 ) ;
F_122 ( V_25 , V_141 , V_131 , V_68 ) ;
F_32 ( F_90 ( V_141 ) >
F_132 ( V_25 -> V_142 ) ) ;
return V_141 ;
}
static inline struct V_13 *
F_133 ( struct V_17 * V_18 , T_2 V_131 )
{
struct V_67 * V_68 ;
struct V_13 * V_19 = NULL ;
struct V_13 * V_130 ;
struct V_13 * V_143 ;
struct V_144 * V_99 = NULL ;
T_2 V_145 = 0 ;
T_2 V_75 ;
V_130 = F_21 ( V_18 ) ;
V_68 = F_121 ( V_18 -> V_25 , V_130 , V_131 ) ;
if ( ! V_68 )
return V_130 ;
if ( V_68 -> V_81 == V_103 ) {
V_99 = & V_68 -> V_99 ;
V_145 = V_68 -> V_86 ;
V_75 = V_99 -> V_75 ;
} else {
V_75 = V_130 -> V_45 ;
}
V_68 = F_93 ( V_18 -> V_25 , V_75 , V_131 ) ;
if ( V_99 && V_68 && V_68 -> V_81 != V_102 ) {
F_23 ( V_130 ) ;
F_11 ( V_130 ) ;
V_143 = F_134 ( V_18 , V_75 , 0 ) ;
if ( F_32 ( F_37 ( V_143 ) || ! F_135 ( V_143 ) ) ) {
if ( ! F_37 ( V_143 ) )
F_11 ( V_143 ) ;
F_136 ( V_18 -> V_25 ,
L_1 , V_75 ) ;
} else {
V_19 = F_131 ( V_143 ) ;
F_11 ( V_143 ) ;
}
} else if ( V_99 ) {
F_23 ( V_130 ) ;
F_11 ( V_130 ) ;
V_19 = F_128 ( V_18 -> V_25 , V_75 ,
V_18 -> V_146 ) ;
} else {
F_4 ( V_130 , V_9 ) ;
V_19 = F_131 ( V_130 ) ;
F_129 ( V_130 ) ;
F_11 ( V_130 ) ;
}
if ( ! V_19 )
return NULL ;
F_115 ( V_19 ) ;
F_22 ( V_19 ) ;
if ( V_99 ) {
F_40 ( V_19 , V_19 -> V_45 ) ;
F_42 ( V_19 , V_47 ) ;
F_45 ( V_19 , F_107 ( V_130 ) ) ;
F_130 ( V_19 , V_99 -> V_38 ) ;
F_41 ( V_19 , V_145 ) ;
}
if ( V_68 )
F_122 ( V_18 -> V_25 , V_19 , V_131 , V_68 ) ;
else
F_32 ( F_33 ( V_19 ) != 0 ) ;
F_32 ( F_90 ( V_19 ) > F_132 ( V_18 ) ) ;
return V_19 ;
}
int F_137 ( struct V_17 * V_18 , T_2 V_131 )
{
struct V_67 * V_68 ;
int V_38 ;
struct V_13 * V_130 = F_12 ( V_18 ) ;
V_68 = F_121 ( V_18 -> V_25 , V_130 , V_131 ) ;
if ( V_68 && V_68 -> V_81 == V_103 ) {
V_38 = V_68 -> V_99 . V_38 ;
} else {
V_38 = F_33 ( V_130 ) ;
}
F_11 ( V_130 ) ;
return V_38 ;
}
static inline int F_138 ( struct V_31 * V_32 ,
struct V_17 * V_18 ,
struct V_13 * V_33 )
{
if ( F_139 ( V_18 -> V_25 ) )
return 0 ;
F_140 () ;
if ( F_48 ( V_33 ) == V_32 -> V_42 &&
! F_101 ( V_33 , V_48 ) &&
! ( V_18 -> V_123 . V_27 != V_50 &&
F_101 ( V_33 , V_49 ) ) &&
! F_25 ( V_147 , & V_18 -> V_23 ) )
return 0 ;
return 1 ;
}
T_1 int F_141 ( struct V_31 * V_32 ,
struct V_17 * V_18 , struct V_13 * V_33 ,
struct V_13 * V_73 , int V_125 ,
struct V_13 * * V_34 )
{
T_2 V_126 ;
int V_37 ;
if ( V_32 -> V_148 != V_18 -> V_25 -> V_43 )
F_142 ( 1 , V_149 L_2 ,
V_32 -> V_42 ,
V_18 -> V_25 -> V_43 -> V_42 ) ;
if ( V_32 -> V_42 != V_18 -> V_25 -> V_86 )
F_142 ( 1 , V_149 L_2 ,
V_32 -> V_42 , V_18 -> V_25 -> V_86 ) ;
if ( ! F_138 ( V_32 , V_18 , V_33 ) ) {
V_32 -> V_150 = true ;
* V_34 = V_33 ;
return 0 ;
}
V_126 = V_33 -> V_45 & ~ ( ( T_2 ) V_151 - 1 ) ;
if ( V_73 )
F_143 ( V_73 ) ;
F_143 ( V_33 ) ;
V_37 = F_111 ( V_32 , V_18 , V_33 , V_73 ,
V_125 , V_34 , V_126 , 0 ) ;
F_144 ( V_18 , V_33 , * V_34 ) ;
return V_37 ;
}
static int F_145 ( T_2 V_152 , T_2 V_153 , T_4 V_154 )
{
if ( V_152 < V_153 && V_153 - ( V_152 + V_154 ) < 32768 )
return 1 ;
if ( V_152 > V_153 && V_152 - ( V_153 + V_154 ) < 32768 )
return 1 ;
return 0 ;
}
static int F_146 ( struct V_39 * V_155 , struct V_156 * V_157 )
{
struct V_156 V_158 ;
F_147 ( & V_158 , V_155 ) ;
return F_148 ( & V_158 , V_157 ) ;
}
int F_148 ( struct V_156 * V_158 , struct V_156 * V_157 )
{
if ( V_158 -> V_27 > V_157 -> V_27 )
return 1 ;
if ( V_158 -> V_27 < V_157 -> V_27 )
return - 1 ;
if ( V_158 -> type > V_157 -> type )
return 1 ;
if ( V_158 -> type < V_157 -> type )
return - 1 ;
if ( V_158 -> V_159 > V_157 -> V_159 )
return 1 ;
if ( V_158 -> V_159 < V_157 -> V_159 )
return - 1 ;
return 0 ;
}
int F_149 ( struct V_31 * V_32 ,
struct V_17 * V_18 , struct V_13 * V_73 ,
int V_160 , T_2 * V_161 ,
struct V_156 * V_162 )
{
struct V_13 * V_74 ;
T_2 V_152 ;
T_2 V_163 ;
T_2 V_126 = * V_161 ;
T_2 V_164 = 0 ;
T_2 V_153 ;
T_4 V_165 ;
int V_166 ;
int V_5 ;
int V_167 = 0 ;
int V_168 ;
int V_169 ;
T_4 V_154 ;
int V_170 = 0 ;
struct V_39 V_40 ;
V_168 = F_33 ( V_73 ) ;
F_32 ( V_32 -> V_148 != V_18 -> V_25 -> V_43 ) ;
F_32 ( V_32 -> V_42 != V_18 -> V_25 -> V_86 ) ;
V_165 = F_90 ( V_73 ) ;
V_154 = V_18 -> V_146 ;
V_166 = V_165 - 1 ;
if ( V_165 <= 1 )
return 0 ;
F_143 ( V_73 ) ;
for ( V_5 = V_160 ; V_5 <= V_166 ; V_5 ++ ) {
int V_171 = 1 ;
F_35 ( V_73 , & V_40 , V_5 ) ;
if ( ! V_170 && F_146 ( & V_40 , V_162 ) < 0 )
continue;
V_170 = 1 ;
V_152 = F_81 ( V_73 , V_5 ) ;
V_163 = F_82 ( V_73 , V_5 ) ;
if ( V_164 == 0 )
V_164 = V_152 ;
if ( V_5 > 0 ) {
V_153 = F_81 ( V_73 , V_5 - 1 ) ;
V_171 = F_145 ( V_152 , V_153 , V_154 ) ;
}
if ( ! V_171 && V_5 < V_166 ) {
V_153 = F_81 ( V_73 , V_5 + 1 ) ;
V_171 = F_145 ( V_152 , V_153 , V_154 ) ;
}
if ( V_171 ) {
V_164 = V_152 ;
continue;
}
V_74 = F_150 ( V_18 -> V_25 , V_152 ) ;
if ( V_74 )
V_169 = F_151 ( V_74 , V_163 , 0 ) ;
else
V_169 = 0 ;
if ( ! V_74 || ! V_169 ) {
if ( ! V_74 ) {
V_74 = F_134 ( V_18 , V_152 , V_163 ) ;
if ( F_37 ( V_74 ) ) {
return F_38 ( V_74 ) ;
} else if ( ! F_135 ( V_74 ) ) {
F_11 ( V_74 ) ;
return - V_172 ;
}
} else if ( ! V_169 ) {
V_167 = F_152 ( V_74 , V_163 ) ;
if ( V_167 ) {
F_11 ( V_74 ) ;
return V_167 ;
}
}
}
if ( V_126 == 0 )
V_126 = V_164 ;
F_19 ( V_74 ) ;
F_143 ( V_74 ) ;
V_167 = F_111 ( V_32 , V_18 , V_74 , V_73 , V_5 ,
& V_74 , V_126 ,
F_153 ( 16 * V_154 ,
( V_166 - V_5 ) * V_154 ) ) ;
if ( V_167 ) {
F_20 ( V_74 ) ;
F_11 ( V_74 ) ;
break;
}
V_126 = V_74 -> V_45 ;
V_164 = V_74 -> V_45 ;
* V_161 = V_126 ;
F_20 ( V_74 ) ;
F_11 ( V_74 ) ;
}
return V_167 ;
}
static T_1 int F_154 ( struct V_13 * V_19 ,
unsigned long V_4 ,
int V_173 , struct V_156 * V_84 ,
int V_174 , int * V_79 )
{
int V_175 = 0 ;
int V_176 = V_174 ;
int V_177 ;
int V_37 ;
struct V_39 * V_178 = NULL ;
struct V_39 V_179 ;
unsigned long V_159 ;
char * V_180 = NULL ;
unsigned long V_181 = 0 ;
unsigned long V_182 = 0 ;
int V_167 ;
if ( V_175 > V_176 ) {
F_155 ( V_19 -> V_25 ,
L_3 ,
V_183 , V_175 , V_176 , V_19 -> V_45 ,
F_107 ( V_19 ) , F_33 ( V_19 ) ) ;
return - V_184 ;
}
while ( V_175 < V_176 ) {
V_177 = ( V_175 + V_176 ) / 2 ;
V_159 = V_4 + V_177 * V_173 ;
if ( ! V_180 || V_159 < V_181 ||
( V_159 + sizeof( struct V_39 ) ) >
V_181 + V_182 ) {
V_167 = F_156 ( V_19 , V_159 ,
sizeof( struct V_39 ) ,
& V_180 , & V_181 , & V_182 ) ;
if ( ! V_167 ) {
V_178 = (struct V_39 * ) ( V_180 + V_159 -
V_181 ) ;
} else if ( V_167 == 1 ) {
F_157 ( V_19 , & V_179 ,
V_159 , sizeof( V_179 ) ) ;
V_178 = & V_179 ;
} else {
return V_167 ;
}
} else {
V_178 = (struct V_39 * ) ( V_180 + V_159 -
V_181 ) ;
}
V_37 = F_146 ( V_178 , V_84 ) ;
if ( V_37 < 0 )
V_175 = V_177 + 1 ;
else if ( V_37 > 0 )
V_176 = V_177 ;
else {
* V_79 = V_177 ;
return 0 ;
}
}
* V_79 = V_175 ;
return 1 ;
}
static int F_158 ( struct V_13 * V_19 , struct V_156 * V_84 ,
int V_38 , int * V_79 )
{
if ( V_38 == 0 )
return F_154 ( V_19 ,
F_159 ( struct V_185 , V_186 ) ,
sizeof( struct V_187 ) ,
V_84 , F_90 ( V_19 ) ,
V_79 ) ;
else
return F_154 ( V_19 ,
F_159 ( struct V_188 , V_189 ) ,
sizeof( struct V_139 ) ,
V_84 , F_90 ( V_19 ) ,
V_79 ) ;
}
int F_160 ( struct V_13 * V_19 , struct V_156 * V_84 ,
int V_38 , int * V_79 )
{
return F_158 ( V_19 , V_84 , V_38 , V_79 ) ;
}
static void F_161 ( struct V_17 * V_18 , T_4 V_190 )
{
F_26 ( & V_18 -> V_191 ) ;
F_162 ( & V_18 -> V_118 ,
F_163 ( & V_18 -> V_118 ) + V_190 ) ;
F_30 ( & V_18 -> V_191 ) ;
}
static void F_164 ( struct V_17 * V_18 , T_4 V_190 )
{
F_26 ( & V_18 -> V_191 ) ;
F_162 ( & V_18 -> V_118 ,
F_163 ( & V_18 -> V_118 ) - V_190 ) ;
F_30 ( & V_18 -> V_191 ) ;
}
T_1 int F_165 ( struct V_31 * V_32 ,
struct V_17 * V_18 ,
struct V_1 * V_140 , int V_38 )
{
struct V_13 * V_192 = NULL ;
struct V_13 * V_177 ;
struct V_13 * V_193 = NULL ;
struct V_13 * V_73 = NULL ;
int V_37 = 0 ;
int V_194 ;
int V_195 ;
int V_196 = V_140 -> V_16 [ V_38 ] ;
T_2 V_197 ;
if ( V_38 == 0 )
return 0 ;
V_177 = V_140 -> V_7 [ V_38 ] ;
F_32 ( V_140 -> V_8 [ V_38 ] != V_11 &&
V_140 -> V_8 [ V_38 ] != V_12 ) ;
F_32 ( F_48 ( V_177 ) != V_32 -> V_42 ) ;
V_197 = F_81 ( V_177 , V_196 ) ;
if ( V_38 < V_6 - 1 ) {
V_73 = V_140 -> V_7 [ V_38 + 1 ] ;
V_195 = V_140 -> V_16 [ V_38 + 1 ] ;
}
if ( ! V_73 ) {
struct V_13 * V_198 ;
if ( F_90 ( V_177 ) != 1 )
return 0 ;
V_198 = F_166 ( V_18 , V_177 , 0 ) ;
if ( F_37 ( V_198 ) ) {
V_37 = F_38 ( V_198 ) ;
F_106 ( V_18 -> V_25 , V_37 , NULL ) ;
goto V_199;
}
F_19 ( V_198 ) ;
F_143 ( V_198 ) ;
V_37 = F_141 ( V_32 , V_18 , V_198 , V_177 , 0 , & V_198 ) ;
if ( V_37 ) {
F_20 ( V_198 ) ;
F_11 ( V_198 ) ;
goto V_199;
}
F_98 ( V_18 , V_198 , 1 ) ;
F_116 ( V_18 -> V_20 , V_198 ) ;
F_24 ( V_18 ) ;
F_20 ( V_198 ) ;
V_140 -> V_8 [ V_38 ] = 0 ;
V_140 -> V_7 [ V_38 ] = NULL ;
F_110 ( V_32 , V_18 -> V_25 , V_177 ) ;
F_20 ( V_177 ) ;
F_11 ( V_177 ) ;
F_164 ( V_18 , V_177 -> V_46 ) ;
F_117 ( V_32 , V_18 , V_177 , 0 , 1 ) ;
F_120 ( V_177 ) ;
return 0 ;
}
if ( F_90 ( V_177 ) >
F_132 ( V_18 ) / 4 )
return 0 ;
V_193 = F_166 ( V_18 , V_73 , V_195 - 1 ) ;
if ( F_37 ( V_193 ) )
V_193 = NULL ;
if ( V_193 ) {
F_19 ( V_193 ) ;
F_143 ( V_193 ) ;
V_194 = F_141 ( V_32 , V_18 , V_193 ,
V_73 , V_195 - 1 , & V_193 ) ;
if ( V_194 ) {
V_37 = V_194 ;
goto V_199;
}
}
V_192 = F_166 ( V_18 , V_73 , V_195 + 1 ) ;
if ( F_37 ( V_192 ) )
V_192 = NULL ;
if ( V_192 ) {
F_19 ( V_192 ) ;
F_143 ( V_192 ) ;
V_194 = F_141 ( V_32 , V_18 , V_192 ,
V_73 , V_195 + 1 , & V_192 ) ;
if ( V_194 ) {
V_37 = V_194 ;
goto V_199;
}
}
if ( V_193 ) {
V_196 += F_90 ( V_193 ) ;
V_194 = F_167 ( V_32 , V_18 , V_193 , V_177 , 1 ) ;
if ( V_194 < 0 )
V_37 = V_194 ;
}
if ( V_192 ) {
V_194 = F_167 ( V_32 , V_18 , V_177 , V_192 , 1 ) ;
if ( V_194 < 0 && V_194 != - V_200 )
V_37 = V_194 ;
if ( F_90 ( V_192 ) == 0 ) {
F_110 ( V_32 , V_18 -> V_25 , V_192 ) ;
F_20 ( V_192 ) ;
F_168 ( V_18 , V_140 , V_38 + 1 , V_195 + 1 ) ;
F_164 ( V_18 , V_192 -> V_46 ) ;
F_117 ( V_32 , V_18 , V_192 , 0 , 1 ) ;
F_120 ( V_192 ) ;
V_192 = NULL ;
} else {
struct V_39 V_201 ;
F_35 ( V_192 , & V_201 , 0 ) ;
F_96 ( V_18 -> V_25 , V_73 ,
V_195 + 1 , 0 ) ;
F_123 ( V_73 , & V_201 , V_195 + 1 ) ;
F_50 ( V_73 ) ;
}
}
if ( F_90 ( V_177 ) == 1 ) {
if ( ! V_193 ) {
V_37 = - V_122 ;
F_106 ( V_18 -> V_25 , V_37 , NULL ) ;
goto V_199;
}
V_194 = F_169 ( V_32 , V_18 , V_177 , V_193 ) ;
if ( V_194 < 0 ) {
V_37 = V_194 ;
goto V_199;
}
if ( V_194 == 1 ) {
V_194 = F_167 ( V_32 , V_18 , V_193 , V_177 , 1 ) ;
if ( V_194 < 0 )
V_37 = V_194 ;
}
F_72 ( V_194 == 1 ) ;
}
if ( F_90 ( V_177 ) == 0 ) {
F_110 ( V_32 , V_18 -> V_25 , V_177 ) ;
F_20 ( V_177 ) ;
F_168 ( V_18 , V_140 , V_38 + 1 , V_195 ) ;
F_164 ( V_18 , V_177 -> V_46 ) ;
F_117 ( V_32 , V_18 , V_177 , 0 , 1 ) ;
F_120 ( V_177 ) ;
V_177 = NULL ;
} else {
struct V_39 V_202 ;
F_35 ( V_177 , & V_202 , 0 ) ;
F_96 ( V_18 -> V_25 , V_73 ,
V_195 , 0 ) ;
F_123 ( V_73 , & V_202 , V_195 ) ;
F_50 ( V_73 ) ;
}
if ( V_193 ) {
if ( F_90 ( V_193 ) > V_196 ) {
F_115 ( V_193 ) ;
V_140 -> V_7 [ V_38 ] = V_193 ;
V_140 -> V_16 [ V_38 + 1 ] -= 1 ;
V_140 -> V_16 [ V_38 ] = V_196 ;
if ( V_177 ) {
F_20 ( V_177 ) ;
F_11 ( V_177 ) ;
}
} else {
V_196 -= F_90 ( V_193 ) ;
V_140 -> V_16 [ V_38 ] = V_196 ;
}
}
if ( V_197 !=
F_81 ( V_140 -> V_7 [ V_38 ] , V_140 -> V_16 [ V_38 ] ) )
F_170 () ;
V_199:
if ( V_192 ) {
F_20 ( V_192 ) ;
F_11 ( V_192 ) ;
}
if ( V_193 ) {
if ( V_140 -> V_7 [ V_38 ] != V_193 )
F_20 ( V_193 ) ;
F_11 ( V_193 ) ;
}
return V_37 ;
}
static T_1 int F_171 ( struct V_31 * V_32 ,
struct V_17 * V_18 ,
struct V_1 * V_140 , int V_38 )
{
struct V_13 * V_192 = NULL ;
struct V_13 * V_177 ;
struct V_13 * V_193 = NULL ;
struct V_13 * V_73 = NULL ;
int V_37 = 0 ;
int V_194 ;
int V_195 ;
int V_196 = V_140 -> V_16 [ V_38 ] ;
if ( V_38 == 0 )
return 1 ;
V_177 = V_140 -> V_7 [ V_38 ] ;
F_32 ( F_48 ( V_177 ) != V_32 -> V_42 ) ;
if ( V_38 < V_6 - 1 ) {
V_73 = V_140 -> V_7 [ V_38 + 1 ] ;
V_195 = V_140 -> V_16 [ V_38 + 1 ] ;
}
if ( ! V_73 )
return 1 ;
V_193 = F_166 ( V_18 , V_73 , V_195 - 1 ) ;
if ( F_37 ( V_193 ) )
V_193 = NULL ;
if ( V_193 ) {
T_4 V_203 ;
F_19 ( V_193 ) ;
F_143 ( V_193 ) ;
V_203 = F_90 ( V_193 ) ;
if ( V_203 >= F_132 ( V_18 ) - 1 ) {
V_194 = 1 ;
} else {
V_37 = F_141 ( V_32 , V_18 , V_193 , V_73 ,
V_195 - 1 , & V_193 ) ;
if ( V_37 )
V_194 = 1 ;
else {
V_194 = F_167 ( V_32 , V_18 ,
V_193 , V_177 , 0 ) ;
}
}
if ( V_194 < 0 )
V_37 = V_194 ;
if ( V_194 == 0 ) {
struct V_39 V_40 ;
V_196 += V_203 ;
F_35 ( V_177 , & V_40 , 0 ) ;
F_96 ( V_18 -> V_25 , V_73 ,
V_195 , 0 ) ;
F_123 ( V_73 , & V_40 , V_195 ) ;
F_50 ( V_73 ) ;
if ( F_90 ( V_193 ) > V_196 ) {
V_140 -> V_7 [ V_38 ] = V_193 ;
V_140 -> V_16 [ V_38 + 1 ] -= 1 ;
V_140 -> V_16 [ V_38 ] = V_196 ;
F_20 ( V_177 ) ;
F_11 ( V_177 ) ;
} else {
V_196 -=
F_90 ( V_193 ) ;
V_140 -> V_16 [ V_38 ] = V_196 ;
F_20 ( V_193 ) ;
F_11 ( V_193 ) ;
}
return 0 ;
}
F_20 ( V_193 ) ;
F_11 ( V_193 ) ;
}
V_192 = F_166 ( V_18 , V_73 , V_195 + 1 ) ;
if ( F_37 ( V_192 ) )
V_192 = NULL ;
if ( V_192 ) {
T_4 V_204 ;
F_19 ( V_192 ) ;
F_143 ( V_192 ) ;
V_204 = F_90 ( V_192 ) ;
if ( V_204 >= F_132 ( V_18 ) - 1 ) {
V_194 = 1 ;
} else {
V_37 = F_141 ( V_32 , V_18 , V_192 ,
V_73 , V_195 + 1 ,
& V_192 ) ;
if ( V_37 )
V_194 = 1 ;
else {
V_194 = F_169 ( V_32 , V_18 ,
V_192 , V_177 ) ;
}
}
if ( V_194 < 0 )
V_37 = V_194 ;
if ( V_194 == 0 ) {
struct V_39 V_40 ;
F_35 ( V_192 , & V_40 , 0 ) ;
F_96 ( V_18 -> V_25 , V_73 ,
V_195 + 1 , 0 ) ;
F_123 ( V_73 , & V_40 , V_195 + 1 ) ;
F_50 ( V_73 ) ;
if ( F_90 ( V_177 ) <= V_196 ) {
V_140 -> V_7 [ V_38 ] = V_192 ;
V_140 -> V_16 [ V_38 + 1 ] += 1 ;
V_140 -> V_16 [ V_38 ] = V_196 -
F_90 ( V_177 ) ;
F_20 ( V_177 ) ;
F_11 ( V_177 ) ;
} else {
F_20 ( V_192 ) ;
F_11 ( V_192 ) ;
}
return 0 ;
}
F_20 ( V_192 ) ;
F_11 ( V_192 ) ;
}
return 1 ;
}
static void F_172 ( struct V_17 * V_18 ,
struct V_1 * V_140 ,
int V_38 , int V_79 , T_2 V_27 )
{
struct V_13 * V_20 ;
struct V_39 V_40 ;
T_4 V_97 ;
T_2 V_205 ;
T_2 V_206 ;
T_2 V_207 = 0 ;
struct V_13 * V_19 ;
T_4 V_208 ;
T_4 V_154 ;
T_4 V_209 = 0 ;
if ( V_38 != 1 )
return;
if ( ! V_140 -> V_7 [ V_38 ] )
return;
V_20 = V_140 -> V_7 [ V_38 ] ;
V_205 = F_81 ( V_20 , V_79 ) ;
V_154 = V_18 -> V_146 ;
V_19 = F_150 ( V_18 -> V_25 , V_205 ) ;
if ( V_19 ) {
F_11 ( V_19 ) ;
return;
}
V_206 = V_205 ;
V_97 = F_90 ( V_20 ) ;
V_208 = V_79 ;
while ( 1 ) {
if ( V_140 -> V_210 == V_211 ) {
if ( V_208 == 0 )
break;
V_208 -- ;
} else if ( V_140 -> V_210 == V_212 ) {
V_208 ++ ;
if ( V_208 >= V_97 )
break;
}
if ( V_140 -> V_210 == V_211 && V_27 ) {
F_35 ( V_20 , & V_40 , V_208 ) ;
if ( F_173 ( & V_40 ) != V_27 )
break;
}
V_205 = F_81 ( V_20 , V_208 ) ;
if ( ( V_205 <= V_206 && V_206 - V_205 <= 65536 ) ||
( V_205 > V_206 && V_205 - V_206 <= 65536 ) ) {
F_174 ( V_18 , V_205 ) ;
V_207 += V_154 ;
}
V_209 ++ ;
if ( ( V_207 > 65536 || V_209 > 32 ) )
break;
}
}
static T_1 void F_175 ( struct V_17 * V_18 ,
struct V_1 * V_140 , int V_38 )
{
int V_79 ;
int V_97 ;
struct V_13 * V_73 ;
struct V_13 * V_19 ;
T_2 V_163 ;
T_2 V_213 = 0 ;
T_2 V_214 = 0 ;
V_73 = V_140 -> V_7 [ V_38 + 1 ] ;
if ( ! V_73 )
return;
V_97 = F_90 ( V_73 ) ;
V_79 = V_140 -> V_16 [ V_38 + 1 ] ;
if ( V_79 > 0 ) {
V_213 = F_81 ( V_73 , V_79 - 1 ) ;
V_163 = F_82 ( V_73 , V_79 - 1 ) ;
V_19 = F_150 ( V_18 -> V_25 , V_213 ) ;
if ( V_19 && F_151 ( V_19 , V_163 , 1 ) != 0 )
V_213 = 0 ;
F_11 ( V_19 ) ;
}
if ( V_79 + 1 < V_97 ) {
V_214 = F_81 ( V_73 , V_79 + 1 ) ;
V_163 = F_82 ( V_73 , V_79 + 1 ) ;
V_19 = F_150 ( V_18 -> V_25 , V_214 ) ;
if ( V_19 && F_151 ( V_19 , V_163 , 1 ) != 0 )
V_214 = 0 ;
F_11 ( V_19 ) ;
}
if ( V_213 )
F_174 ( V_18 , V_213 ) ;
if ( V_214 )
F_174 ( V_18 , V_214 ) ;
}
static T_1 void F_176 ( struct V_1 * V_140 , int V_38 ,
int V_215 , int V_216 ,
int * V_217 )
{
int V_5 ;
int V_218 = V_38 ;
int V_219 = 0 ;
struct V_13 * V_220 ;
for ( V_5 = V_38 ; V_5 < V_6 ; V_5 ++ ) {
if ( ! V_140 -> V_7 [ V_5 ] )
break;
if ( ! V_140 -> V_8 [ V_5 ] )
break;
if ( ! V_219 && V_140 -> V_16 [ V_5 ] == 0 ) {
V_218 = V_5 + 1 ;
continue;
}
if ( ! V_219 && V_140 -> V_221 ) {
T_4 V_97 ;
V_220 = V_140 -> V_7 [ V_5 ] ;
V_97 = F_90 ( V_220 ) ;
if ( V_97 < 1 || V_140 -> V_16 [ V_5 ] >= V_97 - 1 ) {
V_218 = V_5 + 1 ;
continue;
}
}
if ( V_218 < V_5 && V_5 >= V_215 )
V_219 = 1 ;
V_220 = V_140 -> V_7 [ V_5 ] ;
if ( V_5 >= V_215 && V_5 > V_218 && V_140 -> V_8 [ V_5 ] ) {
F_10 ( V_220 , V_140 -> V_8 [ V_5 ] ) ;
V_140 -> V_8 [ V_5 ] = 0 ;
if ( V_217 &&
V_5 > V_216 &&
V_5 <= * V_217 ) {
* V_217 = V_5 - 1 ;
}
}
}
}
T_1 void F_177 ( struct V_1 * V_140 , int V_38 )
{
int V_5 ;
if ( V_140 -> V_221 )
return;
for ( V_5 = V_38 ; V_5 < V_6 ; V_5 ++ ) {
if ( ! V_140 -> V_7 [ V_5 ] )
continue;
if ( ! V_140 -> V_8 [ V_5 ] )
continue;
F_10 ( V_140 -> V_7 [ V_5 ] , V_140 -> V_8 [ V_5 ] ) ;
V_140 -> V_8 [ V_5 ] = 0 ;
}
}
static int
F_178 ( struct V_31 * V_32 ,
struct V_17 * V_18 , struct V_1 * V_4 ,
struct V_13 * * V_222 , int V_38 , int V_79 ,
struct V_156 * V_84 , T_2 V_131 )
{
T_2 V_152 ;
T_2 V_163 ;
struct V_13 * V_223 = * V_222 ;
struct V_13 * V_178 ;
int V_37 ;
V_152 = F_81 ( V_223 , V_79 ) ;
V_163 = F_82 ( V_223 , V_79 ) ;
V_178 = F_150 ( V_18 -> V_25 , V_152 ) ;
if ( V_178 ) {
if ( F_151 ( V_178 , V_163 , 1 ) > 0 ) {
* V_222 = V_178 ;
return 0 ;
}
F_3 ( V_4 ) ;
V_37 = F_152 ( V_178 , V_163 ) ;
if ( ! V_37 ) {
* V_222 = V_178 ;
return 0 ;
}
F_11 ( V_178 ) ;
F_8 ( V_4 ) ;
return - V_172 ;
}
F_177 ( V_4 , V_38 + 1 ) ;
F_3 ( V_4 ) ;
F_11 ( V_178 ) ;
if ( V_4 -> V_210 != V_224 )
F_172 ( V_18 , V_4 , V_38 , V_79 , V_84 -> V_27 ) ;
F_8 ( V_4 ) ;
V_37 = - V_225 ;
V_178 = F_134 ( V_18 , V_152 , 0 ) ;
if ( ! F_37 ( V_178 ) ) {
if ( ! F_151 ( V_178 , 0 , 0 ) )
V_37 = - V_172 ;
F_11 ( V_178 ) ;
} else {
V_37 = F_38 ( V_178 ) ;
}
return V_37 ;
}
static int
F_179 ( struct V_31 * V_32 ,
struct V_17 * V_18 , struct V_1 * V_4 ,
struct V_13 * V_223 , int V_38 , int V_226 ,
int * V_217 )
{
int V_37 ;
if ( ( V_4 -> V_227 || V_226 > 0 ) && F_90 ( V_223 ) >=
F_132 ( V_18 ) - 3 ) {
int V_228 ;
if ( * V_217 < V_38 + 1 ) {
* V_217 = V_38 + 1 ;
F_8 ( V_4 ) ;
goto V_229;
}
F_3 ( V_4 ) ;
F_175 ( V_18 , V_4 , V_38 ) ;
V_228 = F_180 ( V_32 , V_18 , V_4 , V_38 ) ;
F_5 ( V_4 , NULL , 0 ) ;
F_72 ( V_228 > 0 ) ;
if ( V_228 ) {
V_37 = V_228 ;
goto V_230;
}
V_223 = V_4 -> V_7 [ V_38 ] ;
} else if ( V_226 < 0 && F_90 ( V_223 ) <
F_132 ( V_18 ) / 2 ) {
int V_228 ;
if ( * V_217 < V_38 + 1 ) {
* V_217 = V_38 + 1 ;
F_8 ( V_4 ) ;
goto V_229;
}
F_3 ( V_4 ) ;
F_175 ( V_18 , V_4 , V_38 ) ;
V_228 = F_165 ( V_32 , V_18 , V_4 , V_38 ) ;
F_5 ( V_4 , NULL , 0 ) ;
if ( V_228 ) {
V_37 = V_228 ;
goto V_230;
}
V_223 = V_4 -> V_7 [ V_38 ] ;
if ( ! V_223 ) {
F_8 ( V_4 ) ;
goto V_229;
}
F_72 ( F_90 ( V_223 ) == 1 ) ;
}
return 0 ;
V_229:
V_37 = - V_225 ;
V_230:
return V_37 ;
}
static void F_181 ( struct V_13 * V_223 ,
struct V_156 * V_84 ,
int V_38 )
{
#ifdef F_182
struct V_39 V_40 ;
F_183 ( & V_40 , V_84 ) ;
if ( V_38 == 0 )
ASSERT ( ! F_184 ( V_223 , & V_40 ,
F_159 ( struct V_185 , V_186 [ 0 ] . V_84 ) ,
sizeof( V_40 ) ) ) ;
else
ASSERT ( ! F_184 ( V_223 , & V_40 ,
F_159 ( struct V_188 , V_189 [ 0 ] . V_84 ) ,
sizeof( V_40 ) ) ) ;
#endif
}
static int F_185 ( struct V_13 * V_223 , struct V_156 * V_84 ,
int V_38 , int * V_231 , int * V_79 )
{
if ( * V_231 != 0 ) {
* V_231 = F_158 ( V_223 , V_84 , V_38 , V_79 ) ;
return * V_231 ;
}
F_181 ( V_223 , V_84 , V_38 ) ;
* V_79 = 0 ;
return 0 ;
}
int F_186 ( struct V_17 * V_232 , struct V_1 * V_140 ,
T_2 V_233 , T_2 V_234 , T_5 V_235 ,
struct V_156 * V_236 )
{
int V_37 ;
struct V_156 V_84 ;
struct V_13 * V_19 ;
ASSERT ( V_140 ) ;
ASSERT ( V_236 ) ;
V_84 . type = V_235 ;
V_84 . V_27 = V_233 ;
V_84 . V_159 = V_234 ;
V_37 = F_187 ( NULL , V_232 , & V_84 , V_140 , 0 , 0 ) ;
if ( V_37 < 0 )
return V_37 ;
V_19 = V_140 -> V_7 [ 0 ] ;
if ( V_37 && V_140 -> V_16 [ 0 ] >= F_90 ( V_19 ) ) {
V_37 = F_188 ( V_232 , V_140 ) ;
if ( V_37 )
return V_37 ;
V_19 = V_140 -> V_7 [ 0 ] ;
}
F_189 ( V_19 , V_236 , V_140 -> V_16 [ 0 ] ) ;
if ( V_236 -> type != V_84 . type ||
V_236 -> V_27 != V_84 . V_27 )
return 1 ;
return 0 ;
}
int F_187 ( struct V_31 * V_32 , struct V_17
* V_18 , struct V_156 * V_84 , struct V_1 * V_4 , int
V_226 , int V_36 )
{
struct V_13 * V_223 ;
int V_79 ;
int V_37 ;
int V_167 ;
int V_38 ;
int V_215 = 1 ;
int V_237 ;
int V_217 = 0 ;
T_5 V_238 = 0 ;
int V_216 ;
int V_231 ;
V_238 = V_4 -> V_238 ;
F_32 ( V_238 && V_226 > 0 ) ;
F_32 ( V_4 -> V_7 [ 0 ] != NULL ) ;
F_72 ( ! V_36 && V_226 ) ;
if ( V_226 < 0 ) {
V_215 = 2 ;
V_217 = 2 ;
} else if ( V_226 > 0 ) {
V_217 = 1 ;
}
if ( ! V_36 )
V_217 = - 1 ;
if ( V_36 && ( V_4 -> V_221 || V_4 -> V_238 ) )
V_217 = V_6 ;
V_216 = V_217 ;
V_229:
V_231 = - 1 ;
V_237 = V_9 ;
V_38 = 0 ;
if ( V_4 -> V_239 ) {
if ( V_4 -> V_240 )
F_190 ( & V_18 -> V_25 -> V_241 ) ;
V_223 = V_18 -> V_117 ;
F_115 ( V_223 ) ;
V_38 = F_33 ( V_223 ) ;
if ( V_4 -> V_240 )
F_191 ( & V_18 -> V_25 -> V_241 ) ;
if ( ! V_4 -> V_242 )
F_22 ( V_223 ) ;
} else {
if ( V_4 -> V_242 ) {
V_223 = F_12 ( V_18 ) ;
V_38 = F_33 ( V_223 ) ;
} else {
V_223 = F_21 ( V_18 ) ;
V_38 = F_33 ( V_223 ) ;
if ( V_38 <= V_217 ) {
F_23 ( V_223 ) ;
F_11 ( V_223 ) ;
V_223 = F_18 ( V_18 ) ;
V_237 = V_11 ;
V_38 = F_33 ( V_223 ) ;
}
}
}
V_4 -> V_7 [ V_38 ] = V_223 ;
if ( ! V_4 -> V_242 )
V_4 -> V_8 [ V_38 ] = V_237 ;
while ( V_223 ) {
V_38 = F_33 ( V_223 ) ;
if ( V_36 ) {
if ( ! F_138 ( V_32 , V_18 , V_223 ) ) {
V_32 -> V_150 = true ;
goto V_243;
}
if ( V_38 > V_217 ||
( V_38 + 1 > V_217 &&
V_38 + 1 < V_6 &&
V_4 -> V_7 [ V_38 + 1 ] ) ) {
V_217 = V_38 + 1 ;
F_8 ( V_4 ) ;
goto V_229;
}
F_3 ( V_4 ) ;
V_167 = F_141 ( V_32 , V_18 , V_223 ,
V_4 -> V_7 [ V_38 + 1 ] ,
V_4 -> V_16 [ V_38 + 1 ] , & V_223 ) ;
if ( V_167 ) {
V_37 = V_167 ;
goto V_230;
}
}
V_243:
V_4 -> V_7 [ V_38 ] = V_223 ;
F_5 ( V_4 , NULL , 0 ) ;
if ( ! V_226 && ! V_4 -> V_221 ) {
int V_244 = V_38 + 1 ;
if ( V_244 < V_6 && V_4 -> V_8 [ V_244 ] ) {
F_10 ( V_4 -> V_7 [ V_244 ] , V_4 -> V_8 [ V_244 ] ) ;
V_4 -> V_8 [ V_244 ] = 0 ;
}
}
V_37 = F_185 ( V_223 , V_84 , V_38 , & V_231 , & V_79 ) ;
if ( V_37 < 0 )
goto V_230;
if ( V_38 != 0 ) {
int V_245 = 0 ;
if ( V_37 && V_79 > 0 ) {
V_245 = 1 ;
V_79 -= 1 ;
}
V_4 -> V_16 [ V_38 ] = V_79 ;
V_167 = F_179 ( V_32 , V_18 , V_4 , V_223 , V_38 ,
V_226 , & V_217 ) ;
if ( V_167 == - V_225 )
goto V_229;
if ( V_167 ) {
V_37 = V_167 ;
goto V_230;
}
V_223 = V_4 -> V_7 [ V_38 ] ;
V_79 = V_4 -> V_16 [ V_38 ] ;
if ( V_79 == 0 && V_226 &&
V_217 < V_38 + 1 ) {
V_217 = V_38 + 1 ;
F_8 ( V_4 ) ;
goto V_229;
}
F_176 ( V_4 , V_38 , V_215 ,
V_216 , & V_217 ) ;
if ( V_38 == V_238 ) {
if ( V_245 )
V_4 -> V_16 [ V_38 ] ++ ;
goto V_230;
}
V_167 = F_178 ( V_32 , V_18 , V_4 ,
& V_223 , V_38 , V_79 , V_84 , 0 ) ;
if ( V_167 == - V_225 )
goto V_229;
if ( V_167 ) {
V_37 = V_167 ;
goto V_230;
}
if ( ! V_4 -> V_242 ) {
V_38 = F_33 ( V_223 ) ;
if ( V_38 <= V_217 ) {
V_167 = F_192 ( V_223 ) ;
if ( ! V_167 ) {
F_3 ( V_4 ) ;
F_19 ( V_223 ) ;
F_5 ( V_4 , V_223 ,
V_11 ) ;
}
V_4 -> V_8 [ V_38 ] = V_11 ;
} else {
V_167 = F_193 ( V_223 ) ;
if ( ! V_167 ) {
F_3 ( V_4 ) ;
F_22 ( V_223 ) ;
F_5 ( V_4 , V_223 ,
V_9 ) ;
}
V_4 -> V_8 [ V_38 ] = V_9 ;
}
V_4 -> V_7 [ V_38 ] = V_223 ;
}
} else {
V_4 -> V_16 [ V_38 ] = V_79 ;
if ( V_226 > 0 &&
F_194 ( V_18 , V_223 ) < V_226 ) {
if ( V_217 < 1 ) {
V_217 = 1 ;
F_8 ( V_4 ) ;
goto V_229;
}
F_3 ( V_4 ) ;
V_167 = F_195 ( V_32 , V_18 , V_84 ,
V_4 , V_226 , V_37 == 0 ) ;
F_5 ( V_4 , NULL , 0 ) ;
F_72 ( V_167 > 0 ) ;
if ( V_167 ) {
V_37 = V_167 ;
goto V_230;
}
}
if ( ! V_4 -> V_227 )
F_176 ( V_4 , V_38 , V_215 ,
V_216 , & V_217 ) ;
goto V_230;
}
}
V_37 = 1 ;
V_230:
if ( ! V_4 -> V_246 )
F_3 ( V_4 ) ;
if ( V_37 < 0 && ! V_4 -> V_247 )
F_8 ( V_4 ) ;
return V_37 ;
}
int F_196 ( struct V_17 * V_18 , struct V_156 * V_84 ,
struct V_1 * V_4 , T_2 V_131 )
{
struct V_13 * V_223 ;
int V_79 ;
int V_37 ;
int V_167 ;
int V_38 ;
int V_215 = 1 ;
T_5 V_238 = 0 ;
int V_231 = - 1 ;
V_238 = V_4 -> V_238 ;
F_32 ( V_4 -> V_7 [ 0 ] != NULL ) ;
if ( V_4 -> V_239 ) {
F_72 ( V_131 ) ;
return F_187 ( NULL , V_18 , V_84 , V_4 , 0 , 0 ) ;
}
V_229:
V_223 = F_133 ( V_18 , V_131 ) ;
V_38 = F_33 ( V_223 ) ;
V_4 -> V_8 [ V_38 ] = V_9 ;
while ( V_223 ) {
V_38 = F_33 ( V_223 ) ;
V_4 -> V_7 [ V_38 ] = V_223 ;
F_5 ( V_4 , NULL , 0 ) ;
F_177 ( V_4 , V_38 + 1 ) ;
V_231 = - 1 ;
V_37 = F_185 ( V_223 , V_84 , V_38 , & V_231 , & V_79 ) ;
if ( V_38 != 0 ) {
int V_245 = 0 ;
if ( V_37 && V_79 > 0 ) {
V_245 = 1 ;
V_79 -= 1 ;
}
V_4 -> V_16 [ V_38 ] = V_79 ;
F_176 ( V_4 , V_38 , V_215 , 0 , NULL ) ;
if ( V_38 == V_238 ) {
if ( V_245 )
V_4 -> V_16 [ V_38 ] ++ ;
goto V_230;
}
V_167 = F_178 ( NULL , V_18 , V_4 , & V_223 , V_38 ,
V_79 , V_84 , V_131 ) ;
if ( V_167 == - V_225 )
goto V_229;
if ( V_167 ) {
V_37 = V_167 ;
goto V_230;
}
V_38 = F_33 ( V_223 ) ;
V_167 = F_193 ( V_223 ) ;
if ( ! V_167 ) {
F_3 ( V_4 ) ;
F_22 ( V_223 ) ;
F_5 ( V_4 , V_223 ,
V_9 ) ;
}
V_223 = F_127 ( V_18 -> V_25 , V_4 , V_223 , V_131 ) ;
if ( ! V_223 ) {
V_37 = - V_87 ;
goto V_230;
}
V_4 -> V_8 [ V_38 ] = V_9 ;
V_4 -> V_7 [ V_38 ] = V_223 ;
} else {
V_4 -> V_16 [ V_38 ] = V_79 ;
F_176 ( V_4 , V_38 , V_215 , 0 , NULL ) ;
goto V_230;
}
}
V_37 = 1 ;
V_230:
if ( ! V_4 -> V_246 )
F_3 ( V_4 ) ;
if ( V_37 < 0 )
F_8 ( V_4 ) ;
return V_37 ;
}
int F_197 ( struct V_17 * V_18 ,
struct V_156 * V_84 , struct V_1 * V_4 ,
int V_248 , int V_249 )
{
int V_37 ;
struct V_13 * V_250 ;
V_229:
V_37 = F_187 ( NULL , V_18 , V_84 , V_4 , 0 , 0 ) ;
if ( V_37 <= 0 )
return V_37 ;
V_250 = V_4 -> V_7 [ 0 ] ;
if ( V_248 ) {
if ( V_4 -> V_16 [ 0 ] >= F_90 ( V_250 ) ) {
V_37 = F_188 ( V_18 , V_4 ) ;
if ( V_37 <= 0 )
return V_37 ;
if ( ! V_249 )
return 1 ;
V_249 = 0 ;
V_248 = 0 ;
F_8 ( V_4 ) ;
goto V_229;
}
} else {
if ( V_4 -> V_16 [ 0 ] == 0 ) {
V_37 = F_198 ( V_18 , V_4 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( ! V_37 ) {
V_250 = V_4 -> V_7 [ 0 ] ;
if ( V_4 -> V_16 [ 0 ] == F_90 ( V_250 ) )
V_4 -> V_16 [ 0 ] -- ;
return 0 ;
}
if ( ! V_249 )
return 1 ;
V_249 = 0 ;
V_248 = 1 ;
F_8 ( V_4 ) ;
goto V_229;
} else {
-- V_4 -> V_16 [ 0 ] ;
}
}
return 0 ;
}
static void F_199 ( struct V_53 * V_25 ,
struct V_1 * V_140 ,
struct V_39 * V_84 , int V_38 )
{
int V_5 ;
struct V_13 * V_220 ;
for ( V_5 = V_38 ; V_5 < V_6 ; V_5 ++ ) {
int V_251 = V_140 -> V_16 [ V_5 ] ;
if ( ! V_140 -> V_7 [ V_5 ] )
break;
V_220 = V_140 -> V_7 [ V_5 ] ;
F_96 ( V_25 , V_220 , V_251 , 1 ) ;
F_123 ( V_220 , V_84 , V_251 ) ;
F_50 ( V_140 -> V_7 [ V_5 ] ) ;
if ( V_251 != 0 )
break;
}
}
void F_200 ( struct V_53 * V_25 ,
struct V_1 * V_140 ,
struct V_156 * V_252 )
{
struct V_39 V_40 ;
struct V_13 * V_19 ;
int V_79 ;
V_19 = V_140 -> V_7 [ 0 ] ;
V_79 = V_140 -> V_16 [ 0 ] ;
if ( V_79 > 0 ) {
F_34 ( V_19 , & V_40 , V_79 - 1 ) ;
F_72 ( F_146 ( & V_40 , V_252 ) >= 0 ) ;
}
if ( V_79 < F_90 ( V_19 ) - 1 ) {
F_34 ( V_19 , & V_40 , V_79 + 1 ) ;
F_72 ( F_146 ( & V_40 , V_252 ) <= 0 ) ;
}
F_183 ( & V_40 , V_252 ) ;
F_201 ( V_19 , & V_40 , V_79 ) ;
F_50 ( V_19 ) ;
if ( V_79 == 0 )
F_199 ( V_25 , V_140 , & V_40 , 1 ) ;
}
static int F_167 ( struct V_31 * V_32 ,
struct V_17 * V_18 , struct V_13 * V_106 ,
struct V_13 * V_107 , int V_253 )
{
int V_254 = 0 ;
int V_255 ;
int V_256 ;
int V_37 = 0 ;
V_255 = F_90 ( V_107 ) ;
V_256 = F_90 ( V_106 ) ;
V_254 = F_132 ( V_18 ) - V_256 ;
F_32 ( F_48 ( V_107 ) != V_32 -> V_42 ) ;
F_32 ( F_48 ( V_106 ) != V_32 -> V_42 ) ;
if ( ! V_253 && V_255 <= 8 )
return 1 ;
if ( V_254 <= 0 )
return 1 ;
if ( V_253 ) {
V_254 = F_153 ( V_255 , V_254 ) ;
if ( V_254 < V_255 ) {
if ( V_255 - V_254 < 8 ) {
if ( V_254 <= 8 )
return 1 ;
V_254 -= 8 ;
}
}
} else
V_254 = F_153 ( V_255 - 8 , V_254 ) ;
V_37 = F_94 ( V_18 -> V_25 , V_106 , V_107 , V_256 , 0 ,
V_254 ) ;
if ( V_37 ) {
F_113 ( V_32 , V_37 ) ;
return V_37 ;
}
F_39 ( V_106 , V_107 ,
F_124 ( V_256 ) ,
F_124 ( 0 ) ,
V_254 * sizeof( struct V_139 ) ) ;
if ( V_254 < V_255 ) {
F_125 ( V_107 , F_124 ( 0 ) ,
F_124 ( V_254 ) ,
( V_255 - V_254 ) *
sizeof( struct V_139 ) ) ;
}
F_126 ( V_107 , V_255 - V_254 ) ;
F_126 ( V_106 , V_256 + V_254 ) ;
F_50 ( V_107 ) ;
F_50 ( V_106 ) ;
return V_37 ;
}
static int F_169 ( struct V_31 * V_32 ,
struct V_17 * V_18 ,
struct V_13 * V_106 ,
struct V_13 * V_107 )
{
int V_254 = 0 ;
int V_257 ;
int V_255 ;
int V_256 ;
int V_37 = 0 ;
F_32 ( F_48 ( V_107 ) != V_32 -> V_42 ) ;
F_32 ( F_48 ( V_106 ) != V_32 -> V_42 ) ;
V_255 = F_90 ( V_107 ) ;
V_256 = F_90 ( V_106 ) ;
V_254 = F_132 ( V_18 ) - V_256 ;
if ( V_254 <= 0 )
return 1 ;
if ( V_255 < 4 )
return 1 ;
V_257 = V_255 / 2 + 1 ;
if ( V_257 >= V_255 )
return 1 ;
if ( V_257 < V_254 )
V_254 = V_257 ;
F_95 ( V_18 -> V_25 , V_106 , V_254 , 0 , V_256 ) ;
F_125 ( V_106 , F_124 ( V_254 ) ,
F_124 ( 0 ) ,
( V_256 ) *
sizeof( struct V_139 ) ) ;
V_37 = F_94 ( V_18 -> V_25 , V_106 , V_107 , 0 ,
V_255 - V_254 , V_254 ) ;
if ( V_37 ) {
F_113 ( V_32 , V_37 ) ;
return V_37 ;
}
F_39 ( V_106 , V_107 ,
F_124 ( 0 ) ,
F_124 ( V_255 - V_254 ) ,
V_254 * sizeof( struct V_139 ) ) ;
F_126 ( V_107 , V_255 - V_254 ) ;
F_126 ( V_106 , V_256 + V_254 ) ;
F_50 ( V_107 ) ;
F_50 ( V_106 ) ;
return V_37 ;
}
static T_1 int F_202 ( struct V_31 * V_32 ,
struct V_17 * V_18 ,
struct V_1 * V_140 , int V_38 )
{
T_2 V_258 ;
struct V_13 * V_259 ;
struct V_13 * V_260 ;
struct V_13 * V_143 ;
struct V_39 V_261 ;
F_72 ( V_140 -> V_7 [ V_38 ] ) ;
F_72 ( V_140 -> V_7 [ V_38 - 1 ] != V_18 -> V_20 ) ;
V_259 = V_140 -> V_7 [ V_38 - 1 ] ;
if ( V_38 == 1 )
F_34 ( V_259 , & V_261 , 0 ) ;
else
F_35 ( V_259 , & V_261 , 0 ) ;
V_260 = F_36 ( V_32 , V_18 , 0 , V_18 -> V_123 . V_27 ,
& V_261 , V_38 , V_18 -> V_20 -> V_45 , 0 ) ;
if ( F_37 ( V_260 ) )
return F_38 ( V_260 ) ;
F_161 ( V_18 , V_18 -> V_146 ) ;
F_203 ( V_260 , 0 , 0 , sizeof( struct V_262 ) ) ;
F_126 ( V_260 , 1 ) ;
F_130 ( V_260 , V_38 ) ;
F_40 ( V_260 , V_260 -> V_45 ) ;
F_41 ( V_260 , V_32 -> V_42 ) ;
F_42 ( V_260 , V_47 ) ;
F_45 ( V_260 , V_18 -> V_123 . V_27 ) ;
F_46 ( V_260 , V_18 -> V_25 -> V_51 , F_47 () ,
V_52 ) ;
F_46 ( V_260 , V_18 -> V_25 -> V_263 ,
F_204 ( V_260 ) , V_264 ) ;
F_123 ( V_260 , & V_261 , 0 ) ;
F_118 ( V_260 , 0 , V_259 -> V_45 ) ;
V_258 = F_48 ( V_259 ) ;
F_32 ( V_258 != V_32 -> V_42 ) ;
F_119 ( V_260 , 0 , V_258 ) ;
F_50 ( V_260 ) ;
V_143 = V_18 -> V_20 ;
F_98 ( V_18 , V_260 , 0 ) ;
F_116 ( V_18 -> V_20 , V_260 ) ;
F_11 ( V_143 ) ;
F_24 ( V_18 ) ;
F_115 ( V_260 ) ;
V_140 -> V_7 [ V_38 ] = V_260 ;
V_140 -> V_8 [ V_38 ] = V_12 ;
V_140 -> V_16 [ V_38 ] = 0 ;
return 0 ;
}
static void F_205 ( struct V_31 * V_32 ,
struct V_17 * V_18 , struct V_1 * V_140 ,
struct V_39 * V_84 , T_2 V_265 ,
int V_79 , int V_38 )
{
struct V_13 * V_259 ;
int V_97 ;
int V_37 ;
F_72 ( ! V_140 -> V_7 [ V_38 ] ) ;
F_112 ( V_140 -> V_7 [ V_38 ] ) ;
V_259 = V_140 -> V_7 [ V_38 ] ;
V_97 = F_90 ( V_259 ) ;
F_72 ( V_79 > V_97 ) ;
F_72 ( V_97 == F_132 ( V_18 ) ) ;
if ( V_79 != V_97 ) {
if ( V_38 )
F_95 ( V_18 -> V_25 , V_259 , V_79 + 1 ,
V_79 , V_97 - V_79 ) ;
F_125 ( V_259 ,
F_124 ( V_79 + 1 ) ,
F_124 ( V_79 ) ,
( V_97 - V_79 ) * sizeof( struct V_139 ) ) ;
}
if ( V_38 ) {
V_37 = F_84 ( V_18 -> V_25 , V_259 , V_79 ,
V_83 , V_3 ) ;
F_72 ( V_37 < 0 ) ;
}
F_123 ( V_259 , V_84 , V_79 ) ;
F_118 ( V_259 , V_79 , V_265 ) ;
F_32 ( V_32 -> V_42 == 0 ) ;
F_119 ( V_259 , V_79 , V_32 -> V_42 ) ;
F_126 ( V_259 , V_97 + 1 ) ;
F_50 ( V_259 ) ;
}
static T_1 int F_180 ( struct V_31 * V_32 ,
struct V_17 * V_18 ,
struct V_1 * V_140 , int V_38 )
{
struct V_13 * V_260 ;
struct V_13 * V_266 ;
struct V_39 V_40 ;
int V_177 ;
int V_37 ;
T_4 V_267 ;
V_260 = V_140 -> V_7 [ V_38 ] ;
F_32 ( F_48 ( V_260 ) != V_32 -> V_42 ) ;
if ( V_260 == V_18 -> V_20 ) {
V_37 = F_202 ( V_32 , V_18 , V_140 , V_38 + 1 ) ;
if ( V_37 )
return V_37 ;
} else {
V_37 = F_171 ( V_32 , V_18 , V_140 , V_38 ) ;
V_260 = V_140 -> V_7 [ V_38 ] ;
if ( ! V_37 && F_90 ( V_260 ) <
F_132 ( V_18 ) - 3 )
return 0 ;
if ( V_37 < 0 )
return V_37 ;
}
V_267 = F_90 ( V_260 ) ;
V_177 = ( V_267 + 1 ) / 2 ;
F_35 ( V_260 , & V_40 , V_177 ) ;
V_266 = F_36 ( V_32 , V_18 , 0 , V_18 -> V_123 . V_27 ,
& V_40 , V_38 , V_260 -> V_45 , 0 ) ;
if ( F_37 ( V_266 ) )
return F_38 ( V_266 ) ;
F_161 ( V_18 , V_18 -> V_146 ) ;
F_203 ( V_266 , 0 , 0 , sizeof( struct V_262 ) ) ;
F_130 ( V_266 , F_33 ( V_260 ) ) ;
F_40 ( V_266 , V_266 -> V_45 ) ;
F_41 ( V_266 , V_32 -> V_42 ) ;
F_42 ( V_266 , V_47 ) ;
F_45 ( V_266 , V_18 -> V_123 . V_27 ) ;
F_46 ( V_266 , V_18 -> V_25 -> V_51 ,
F_47 () , V_52 ) ;
F_46 ( V_266 , V_18 -> V_25 -> V_263 ,
F_204 ( V_266 ) ,
V_264 ) ;
V_37 = F_94 ( V_18 -> V_25 , V_266 , V_260 , 0 ,
V_177 , V_267 - V_177 ) ;
if ( V_37 ) {
F_113 ( V_32 , V_37 ) ;
return V_37 ;
}
F_39 ( V_266 , V_260 ,
F_124 ( 0 ) ,
F_124 ( V_177 ) ,
( V_267 - V_177 ) * sizeof( struct V_139 ) ) ;
F_126 ( V_266 , V_267 - V_177 ) ;
F_126 ( V_260 , V_177 ) ;
V_37 = 0 ;
F_50 ( V_260 ) ;
F_50 ( V_266 ) ;
F_205 ( V_32 , V_18 , V_140 , & V_40 , V_266 -> V_45 ,
V_140 -> V_16 [ V_38 + 1 ] + 1 , V_38 + 1 ) ;
if ( V_140 -> V_16 [ V_38 ] >= V_177 ) {
V_140 -> V_16 [ V_38 ] -= V_177 ;
F_20 ( V_260 ) ;
F_11 ( V_260 ) ;
V_140 -> V_7 [ V_38 ] = V_266 ;
V_140 -> V_16 [ V_38 + 1 ] += 1 ;
} else {
F_20 ( V_266 ) ;
F_11 ( V_266 ) ;
}
return V_37 ;
}
static int F_206 ( struct V_13 * V_268 , int V_45 , int V_208 )
{
struct V_187 * V_269 ;
struct V_187 * V_270 ;
struct V_271 V_272 ;
int V_273 ;
int V_97 = F_90 ( V_268 ) ;
int V_274 = F_153 ( V_97 , V_45 + V_208 ) - 1 ;
if ( ! V_208 )
return 0 ;
F_207 ( & V_272 ) ;
V_269 = F_208 ( V_45 ) ;
V_270 = F_208 ( V_274 ) ;
V_273 = F_209 ( V_268 , V_269 , & V_272 ) +
F_210 ( V_268 , V_269 , & V_272 ) ;
V_273 = V_273 - F_209 ( V_268 , V_270 , & V_272 ) ;
V_273 += sizeof( struct V_187 ) * V_208 ;
F_32 ( V_273 < 0 ) ;
return V_273 ;
}
T_1 int F_194 ( struct V_17 * V_18 ,
struct V_13 * V_250 )
{
int V_97 = F_90 ( V_250 ) ;
int V_37 ;
V_37 = F_211 ( V_18 ) - F_206 ( V_250 , 0 , V_97 ) ;
if ( V_37 < 0 ) {
F_212 ( V_18 -> V_25 ,
L_4 ,
V_37 , ( unsigned long ) F_211 ( V_18 ) ,
F_206 ( V_250 , 0 , V_97 ) , V_97 ) ;
}
return V_37 ;
}
static T_1 int F_213 ( struct V_31 * V_32 ,
struct V_17 * V_18 ,
struct V_1 * V_140 ,
int V_275 , int V_253 ,
struct V_13 * V_192 ,
int V_276 , T_4 V_277 ,
T_4 V_278 )
{
struct V_13 * V_193 = V_140 -> V_7 [ 0 ] ;
struct V_13 * V_279 = V_140 -> V_7 [ 1 ] ;
struct V_271 V_272 ;
struct V_39 V_40 ;
int V_79 ;
T_4 V_5 ;
int V_280 = 0 ;
int V_254 = 0 ;
struct V_187 * V_281 ;
T_4 V_208 ;
T_4 V_282 ;
T_4 V_283 ;
T_4 V_284 ;
F_207 ( & V_272 ) ;
if ( V_253 )
V_208 = 0 ;
else
V_208 = F_214 ( T_4 , 1 , V_278 ) ;
if ( V_140 -> V_16 [ 0 ] >= V_277 )
V_280 += V_275 ;
V_79 = V_140 -> V_16 [ 1 ] ;
V_5 = V_277 - 1 ;
while ( V_5 >= V_208 ) {
V_281 = F_208 ( V_5 ) ;
if ( ! V_253 && V_254 > 0 ) {
if ( V_140 -> V_16 [ 0 ] > V_5 )
break;
if ( V_140 -> V_16 [ 0 ] == V_5 ) {
int V_285 = F_194 ( V_18 , V_193 ) ;
if ( V_285 + V_280 * 2 > V_276 )
break;
}
}
if ( V_140 -> V_16 [ 0 ] == V_5 )
V_280 += V_275 ;
V_284 = F_215 ( V_193 , V_281 ) ;
if ( V_284 + sizeof( * V_281 ) + V_280 > V_276 )
break;
V_254 ++ ;
V_280 += V_284 + sizeof( * V_281 ) ;
if ( V_5 == 0 )
break;
V_5 -- ;
}
if ( V_254 == 0 )
goto V_286;
F_32 ( ! V_253 && V_254 == V_277 ) ;
V_282 = F_90 ( V_192 ) ;
V_280 = F_216 ( V_193 , V_277 - V_254 ) ;
V_280 -= F_217 ( V_18 , V_193 ) ;
V_283 = F_217 ( V_18 , V_192 ) ;
F_125 ( V_192 ,
F_218 ( V_192 ) + V_283 - V_280 ,
F_218 ( V_192 ) + V_283 ,
F_211 ( V_18 ) - V_283 ) ;
F_39 ( V_192 , V_193 , F_218 ( V_192 ) +
F_211 ( V_18 ) - V_280 ,
F_218 ( V_193 ) + F_217 ( V_18 , V_193 ) ,
V_280 ) ;
F_125 ( V_192 , F_219 ( V_254 ) ,
F_219 ( 0 ) ,
V_282 * sizeof( struct V_187 ) ) ;
F_39 ( V_192 , V_193 , F_219 ( 0 ) ,
F_219 ( V_277 - V_254 ) ,
V_254 * sizeof( struct V_187 ) ) ;
V_282 += V_254 ;
F_126 ( V_192 , V_282 ) ;
V_280 = F_211 ( V_18 ) ;
for ( V_5 = 0 ; V_5 < V_282 ; V_5 ++ ) {
V_281 = F_208 ( V_5 ) ;
V_280 -= F_210 ( V_192 , V_281 , & V_272 ) ;
F_220 ( V_192 , V_281 , V_280 , & V_272 ) ;
}
V_277 -= V_254 ;
F_126 ( V_193 , V_277 ) ;
if ( V_277 )
F_50 ( V_193 ) ;
else
F_110 ( V_32 , V_18 -> V_25 , V_193 ) ;
F_50 ( V_192 ) ;
F_34 ( V_192 , & V_40 , 0 ) ;
F_123 ( V_279 , & V_40 , V_79 + 1 ) ;
F_50 ( V_279 ) ;
if ( V_140 -> V_16 [ 0 ] >= V_277 ) {
V_140 -> V_16 [ 0 ] -= V_277 ;
if ( F_90 ( V_140 -> V_7 [ 0 ] ) == 0 )
F_110 ( V_32 , V_18 -> V_25 , V_140 -> V_7 [ 0 ] ) ;
F_20 ( V_140 -> V_7 [ 0 ] ) ;
F_11 ( V_140 -> V_7 [ 0 ] ) ;
V_140 -> V_7 [ 0 ] = V_192 ;
V_140 -> V_16 [ 1 ] += 1 ;
} else {
F_20 ( V_192 ) ;
F_11 ( V_192 ) ;
}
return 0 ;
V_286:
F_20 ( V_192 ) ;
F_11 ( V_192 ) ;
return 1 ;
}
static int F_221 ( struct V_31 * V_32 , struct V_17
* V_18 , struct V_1 * V_140 ,
int V_287 , int V_275 ,
int V_253 , T_4 V_278 )
{
struct V_13 * V_193 = V_140 -> V_7 [ 0 ] ;
struct V_13 * V_192 ;
struct V_13 * V_279 ;
int V_79 ;
int V_276 ;
T_4 V_277 ;
int V_37 ;
if ( ! V_140 -> V_7 [ 1 ] )
return 1 ;
V_79 = V_140 -> V_16 [ 1 ] ;
V_279 = V_140 -> V_7 [ 1 ] ;
if ( V_79 >= F_90 ( V_279 ) - 1 )
return 1 ;
F_112 ( V_140 -> V_7 [ 1 ] ) ;
V_192 = F_166 ( V_18 , V_279 , V_79 + 1 ) ;
if ( F_37 ( V_192 ) )
return 1 ;
F_19 ( V_192 ) ;
F_143 ( V_192 ) ;
V_276 = F_194 ( V_18 , V_192 ) ;
if ( V_276 < V_275 )
goto V_286;
V_37 = F_141 ( V_32 , V_18 , V_192 , V_279 ,
V_79 + 1 , & V_192 ) ;
if ( V_37 )
goto V_286;
V_276 = F_194 ( V_18 , V_192 ) ;
if ( V_276 < V_275 )
goto V_286;
V_277 = F_90 ( V_193 ) ;
if ( V_277 == 0 )
goto V_286;
if ( V_140 -> V_16 [ 0 ] == V_277 && ! V_253 ) {
F_20 ( V_193 ) ;
F_11 ( V_193 ) ;
V_140 -> V_7 [ 0 ] = V_192 ;
V_140 -> V_16 [ 0 ] = 0 ;
V_140 -> V_16 [ 1 ] ++ ;
return 0 ;
}
return F_213 ( V_32 , V_18 , V_140 , V_287 , V_253 ,
V_192 , V_276 , V_277 , V_278 ) ;
V_286:
F_20 ( V_192 ) ;
F_11 ( V_192 ) ;
return 1 ;
}
static T_1 int F_222 ( struct V_31 * V_32 ,
struct V_17 * V_18 ,
struct V_1 * V_140 , int V_275 ,
int V_253 , struct V_13 * V_193 ,
int V_276 , T_4 V_282 ,
T_4 V_288 )
{
struct V_39 V_40 ;
struct V_13 * V_192 = V_140 -> V_7 [ 0 ] ;
int V_5 ;
int V_280 = 0 ;
int V_254 = 0 ;
struct V_187 * V_281 ;
T_4 V_289 ;
T_4 V_208 ;
int V_37 = 0 ;
T_4 V_284 ;
T_4 V_290 ;
struct V_271 V_272 ;
F_207 ( & V_272 ) ;
if ( V_253 )
V_208 = F_153 ( V_282 , V_288 ) ;
else
V_208 = F_153 ( V_282 - 1 , V_288 ) ;
for ( V_5 = 0 ; V_5 < V_208 ; V_5 ++ ) {
V_281 = F_208 ( V_5 ) ;
if ( ! V_253 && V_254 > 0 ) {
if ( V_140 -> V_16 [ 0 ] < V_5 )
break;
if ( V_140 -> V_16 [ 0 ] == V_5 ) {
int V_285 = F_194 ( V_18 , V_192 ) ;
if ( V_285 + V_280 * 2 > V_276 )
break;
}
}
if ( V_140 -> V_16 [ 0 ] == V_5 )
V_280 += V_275 ;
V_284 = F_215 ( V_192 , V_281 ) ;
if ( V_284 + sizeof( * V_281 ) + V_280 > V_276 )
break;
V_254 ++ ;
V_280 += V_284 + sizeof( * V_281 ) ;
}
if ( V_254 == 0 ) {
V_37 = 1 ;
goto V_291;
}
F_32 ( ! V_253 && V_254 == F_90 ( V_192 ) ) ;
F_39 ( V_193 , V_192 ,
F_219 ( F_90 ( V_193 ) ) ,
F_219 ( 0 ) ,
V_254 * sizeof( struct V_187 ) ) ;
V_280 = F_211 ( V_18 ) -
F_223 ( V_192 , V_254 - 1 ) ;
F_39 ( V_193 , V_192 , F_218 ( V_193 ) +
F_217 ( V_18 , V_193 ) - V_280 ,
F_218 ( V_192 ) +
F_223 ( V_192 , V_254 - 1 ) ,
V_280 ) ;
V_289 = F_90 ( V_193 ) ;
F_72 ( V_289 <= 0 ) ;
V_290 = F_223 ( V_193 , V_289 - 1 ) ;
for ( V_5 = V_289 ; V_5 < V_289 + V_254 ; V_5 ++ ) {
T_4 V_234 ;
V_281 = F_208 ( V_5 ) ;
V_234 = F_209 ( V_193 , V_281 , & V_272 ) ;
F_220 ( V_193 , V_281 ,
V_234 - ( F_211 ( V_18 ) - V_290 ) ,
& V_272 ) ;
}
F_126 ( V_193 , V_289 + V_254 ) ;
if ( V_254 > V_282 )
F_142 ( 1 , V_149 L_5 , V_254 ,
V_282 ) ;
if ( V_254 < V_282 ) {
V_280 = F_223 ( V_192 , V_254 - 1 ) -
F_217 ( V_18 , V_192 ) ;
F_125 ( V_192 , F_218 ( V_192 ) +
F_211 ( V_18 ) - V_280 ,
F_218 ( V_192 ) +
F_217 ( V_18 , V_192 ) , V_280 ) ;
F_125 ( V_192 , F_219 ( 0 ) ,
F_219 ( V_254 ) ,
( F_90 ( V_192 ) - V_254 ) *
sizeof( struct V_187 ) ) ;
}
V_282 -= V_254 ;
F_126 ( V_192 , V_282 ) ;
V_280 = F_211 ( V_18 ) ;
for ( V_5 = 0 ; V_5 < V_282 ; V_5 ++ ) {
V_281 = F_208 ( V_5 ) ;
V_280 = V_280 - F_210 ( V_192 ,
V_281 , & V_272 ) ;
F_220 ( V_192 , V_281 , V_280 , & V_272 ) ;
}
F_50 ( V_193 ) ;
if ( V_282 )
F_50 ( V_192 ) ;
else
F_110 ( V_32 , V_18 -> V_25 , V_192 ) ;
F_34 ( V_192 , & V_40 , 0 ) ;
F_199 ( V_18 -> V_25 , V_140 , & V_40 , 1 ) ;
if ( V_140 -> V_16 [ 0 ] < V_254 ) {
V_140 -> V_16 [ 0 ] += V_289 ;
F_20 ( V_140 -> V_7 [ 0 ] ) ;
F_11 ( V_140 -> V_7 [ 0 ] ) ;
V_140 -> V_7 [ 0 ] = V_193 ;
V_140 -> V_16 [ 1 ] -= 1 ;
} else {
F_20 ( V_193 ) ;
F_11 ( V_193 ) ;
V_140 -> V_16 [ 0 ] -= V_254 ;
}
F_72 ( V_140 -> V_16 [ 0 ] < 0 ) ;
return V_37 ;
V_291:
F_20 ( V_193 ) ;
F_11 ( V_193 ) ;
return V_37 ;
}
static int F_224 ( struct V_31 * V_32 , struct V_17
* V_18 , struct V_1 * V_140 , int V_287 ,
int V_275 , int V_253 , T_4 V_288 )
{
struct V_13 * V_192 = V_140 -> V_7 [ 0 ] ;
struct V_13 * V_193 ;
int V_79 ;
int V_276 ;
T_4 V_282 ;
int V_37 = 0 ;
V_79 = V_140 -> V_16 [ 1 ] ;
if ( V_79 == 0 )
return 1 ;
if ( ! V_140 -> V_7 [ 1 ] )
return 1 ;
V_282 = F_90 ( V_192 ) ;
if ( V_282 == 0 )
return 1 ;
F_112 ( V_140 -> V_7 [ 1 ] ) ;
V_193 = F_166 ( V_18 , V_140 -> V_7 [ 1 ] , V_79 - 1 ) ;
if ( F_37 ( V_193 ) )
return 1 ;
F_19 ( V_193 ) ;
F_143 ( V_193 ) ;
V_276 = F_194 ( V_18 , V_193 ) ;
if ( V_276 < V_275 ) {
V_37 = 1 ;
goto V_291;
}
V_37 = F_141 ( V_32 , V_18 , V_193 ,
V_140 -> V_7 [ 1 ] , V_79 - 1 , & V_193 ) ;
if ( V_37 ) {
if ( V_37 == - V_200 )
V_37 = 1 ;
goto V_291;
}
V_276 = F_194 ( V_18 , V_193 ) ;
if ( V_276 < V_275 ) {
V_37 = 1 ;
goto V_291;
}
return F_222 ( V_32 , V_18 , V_140 , V_287 ,
V_253 , V_193 , V_276 , V_282 ,
V_288 ) ;
V_291:
F_20 ( V_193 ) ;
F_11 ( V_193 ) ;
return V_37 ;
}
static T_1 void F_225 ( struct V_31 * V_32 ,
struct V_17 * V_18 ,
struct V_1 * V_140 ,
struct V_13 * V_268 ,
struct V_13 * V_192 ,
int V_79 , int V_177 , int V_97 )
{
int V_292 ;
int V_293 ;
int V_5 ;
struct V_39 V_40 ;
struct V_271 V_272 ;
F_207 ( & V_272 ) ;
V_97 = V_97 - V_177 ;
F_126 ( V_192 , V_97 ) ;
V_292 = F_216 ( V_268 , V_177 ) - F_217 ( V_18 , V_268 ) ;
F_39 ( V_192 , V_268 , F_219 ( 0 ) ,
F_219 ( V_177 ) ,
V_97 * sizeof( struct V_187 ) ) ;
F_39 ( V_192 , V_268 ,
F_218 ( V_192 ) + F_211 ( V_18 ) -
V_292 , F_218 ( V_268 ) +
F_217 ( V_18 , V_268 ) , V_292 ) ;
V_293 = F_211 ( V_18 ) -
F_216 ( V_268 , V_177 ) ;
for ( V_5 = 0 ; V_5 < V_97 ; V_5 ++ ) {
struct V_187 * V_281 = F_208 ( V_5 ) ;
T_4 V_234 ;
V_234 = F_209 ( V_192 , V_281 , & V_272 ) ;
F_220 ( V_192 , V_281 ,
V_234 + V_293 , & V_272 ) ;
}
F_126 ( V_268 , V_177 ) ;
F_34 ( V_192 , & V_40 , 0 ) ;
F_205 ( V_32 , V_18 , V_140 , & V_40 , V_192 -> V_45 ,
V_140 -> V_16 [ 1 ] + 1 , 1 ) ;
F_50 ( V_192 ) ;
F_50 ( V_268 ) ;
F_72 ( V_140 -> V_16 [ 0 ] != V_79 ) ;
if ( V_177 <= V_79 ) {
F_20 ( V_140 -> V_7 [ 0 ] ) ;
F_11 ( V_140 -> V_7 [ 0 ] ) ;
V_140 -> V_7 [ 0 ] = V_192 ;
V_140 -> V_16 [ 0 ] -= V_177 ;
V_140 -> V_16 [ 1 ] += 1 ;
} else {
F_20 ( V_192 ) ;
F_11 ( V_192 ) ;
}
F_72 ( V_140 -> V_16 [ 0 ] < 0 ) ;
}
static T_1 int F_226 ( struct V_31 * V_32 ,
struct V_17 * V_18 ,
struct V_1 * V_140 ,
int V_275 )
{
int V_37 ;
int V_162 = 0 ;
int V_79 ;
T_4 V_97 ;
int V_294 = V_275 ;
V_79 = V_140 -> V_16 [ 0 ] ;
if ( V_79 < F_90 ( V_140 -> V_7 [ 0 ] ) )
V_294 -= F_194 ( V_18 , V_140 -> V_7 [ 0 ] ) ;
V_37 = F_221 ( V_32 , V_18 , V_140 , 1 , V_294 , 0 , V_79 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_37 == 0 )
V_162 ++ ;
V_97 = F_90 ( V_140 -> V_7 [ 0 ] ) ;
if ( V_140 -> V_16 [ 0 ] == 0 || V_140 -> V_16 [ 0 ] == V_97 )
return 0 ;
if ( F_194 ( V_18 , V_140 -> V_7 [ 0 ] ) >= V_275 )
return 0 ;
V_79 = V_140 -> V_16 [ 0 ] ;
V_37 = F_224 ( V_32 , V_18 , V_140 , 1 , V_294 , 0 , V_79 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_37 == 0 )
V_162 ++ ;
if ( V_162 )
return 0 ;
return 1 ;
}
static T_1 int F_195 ( struct V_31 * V_32 ,
struct V_17 * V_18 ,
struct V_156 * V_295 ,
struct V_1 * V_140 , int V_275 ,
int V_296 )
{
struct V_39 V_40 ;
struct V_13 * V_268 ;
T_4 V_97 ;
int V_177 ;
int V_79 ;
struct V_13 * V_192 ;
struct V_53 * V_25 = V_18 -> V_25 ;
int V_37 = 0 ;
int V_194 ;
int V_266 ;
int V_297 = 0 ;
int V_298 = 0 ;
V_268 = V_140 -> V_7 [ 0 ] ;
V_79 = V_140 -> V_16 [ 0 ] ;
if ( V_296 && V_275 + F_227 ( V_268 , V_79 ) +
sizeof( struct V_187 ) > F_211 ( V_18 ) )
return - V_299 ;
if ( V_275 && V_140 -> V_7 [ 1 ] ) {
int V_294 = V_275 ;
if ( V_79 < F_90 ( V_268 ) )
V_294 -= F_194 ( V_18 , V_268 ) ;
V_194 = F_221 ( V_32 , V_18 , V_140 , V_294 ,
V_294 , 0 , 0 ) ;
if ( V_194 < 0 )
return V_194 ;
if ( V_194 ) {
V_194 = F_224 ( V_32 , V_18 , V_140 , V_294 ,
V_294 , 0 , ( T_4 ) - 1 ) ;
if ( V_194 < 0 )
return V_194 ;
}
V_268 = V_140 -> V_7 [ 0 ] ;
if ( F_194 ( V_18 , V_268 ) >= V_275 )
return 0 ;
}
if ( ! V_140 -> V_7 [ 1 ] ) {
V_37 = F_202 ( V_32 , V_18 , V_140 , 1 ) ;
if ( V_37 )
return V_37 ;
}
V_229:
V_266 = 1 ;
V_268 = V_140 -> V_7 [ 0 ] ;
V_79 = V_140 -> V_16 [ 0 ] ;
V_97 = F_90 ( V_268 ) ;
V_177 = ( V_97 + 1 ) / 2 ;
if ( V_177 <= V_79 ) {
if ( V_97 == 1 ||
F_206 ( V_268 , V_177 , V_97 - V_177 ) + V_275 >
F_211 ( V_18 ) ) {
if ( V_79 >= V_97 ) {
V_266 = 0 ;
} else {
V_177 = V_79 ;
if ( V_177 != V_97 &&
F_206 ( V_268 , V_177 , V_97 - V_177 ) +
V_275 > F_211 ( V_18 ) ) {
if ( V_275 && ! V_298 )
goto V_300;
V_266 = 2 ;
}
}
}
} else {
if ( F_206 ( V_268 , 0 , V_177 ) + V_275 >
F_211 ( V_18 ) ) {
if ( ! V_296 && V_275 && V_79 == 0 ) {
V_266 = 0 ;
} else if ( ( V_296 || ! V_275 ) && V_79 == 0 ) {
V_177 = 1 ;
} else {
V_177 = V_79 ;
if ( V_177 != V_97 &&
F_206 ( V_268 , V_177 , V_97 - V_177 ) +
V_275 > F_211 ( V_18 ) ) {
if ( V_275 && ! V_298 )
goto V_300;
V_266 = 2 ;
}
}
}
}
if ( V_266 == 0 )
F_183 ( & V_40 , V_295 ) ;
else
F_34 ( V_268 , & V_40 , V_177 ) ;
V_192 = F_36 ( V_32 , V_18 , 0 , V_18 -> V_123 . V_27 ,
& V_40 , 0 , V_268 -> V_45 , 0 ) ;
if ( F_37 ( V_192 ) )
return F_38 ( V_192 ) ;
F_161 ( V_18 , V_18 -> V_146 ) ;
F_203 ( V_192 , 0 , 0 , sizeof( struct V_262 ) ) ;
F_40 ( V_192 , V_192 -> V_45 ) ;
F_41 ( V_192 , V_32 -> V_42 ) ;
F_42 ( V_192 , V_47 ) ;
F_45 ( V_192 , V_18 -> V_123 . V_27 ) ;
F_130 ( V_192 , 0 ) ;
F_46 ( V_192 , V_25 -> V_51 ,
F_47 () , V_52 ) ;
F_46 ( V_192 , V_25 -> V_263 ,
F_204 ( V_192 ) ,
V_264 ) ;
if ( V_266 == 0 ) {
if ( V_177 <= V_79 ) {
F_126 ( V_192 , 0 ) ;
F_205 ( V_32 , V_18 , V_140 , & V_40 , V_192 -> V_45 ,
V_140 -> V_16 [ 1 ] + 1 , 1 ) ;
F_20 ( V_140 -> V_7 [ 0 ] ) ;
F_11 ( V_140 -> V_7 [ 0 ] ) ;
V_140 -> V_7 [ 0 ] = V_192 ;
V_140 -> V_16 [ 0 ] = 0 ;
V_140 -> V_16 [ 1 ] += 1 ;
} else {
F_126 ( V_192 , 0 ) ;
F_205 ( V_32 , V_18 , V_140 , & V_40 , V_192 -> V_45 ,
V_140 -> V_16 [ 1 ] , 1 ) ;
F_20 ( V_140 -> V_7 [ 0 ] ) ;
F_11 ( V_140 -> V_7 [ 0 ] ) ;
V_140 -> V_7 [ 0 ] = V_192 ;
V_140 -> V_16 [ 0 ] = 0 ;
if ( V_140 -> V_16 [ 1 ] == 0 )
F_199 ( V_25 , V_140 , & V_40 , 1 ) ;
}
return V_37 ;
}
F_225 ( V_32 , V_18 , V_140 , V_268 , V_192 , V_79 , V_177 , V_97 ) ;
if ( V_266 == 2 ) {
F_72 ( V_297 != 0 ) ;
V_297 ++ ;
goto V_229;
}
return 0 ;
V_300:
F_226 ( V_32 , V_18 , V_140 , V_275 ) ;
V_298 = 1 ;
if ( F_194 ( V_18 , V_140 -> V_7 [ 0 ] ) >= V_275 )
return 0 ;
goto V_229;
}
static T_1 int F_228 ( struct V_31 * V_32 ,
struct V_17 * V_18 ,
struct V_1 * V_140 , int V_226 )
{
struct V_156 V_84 ;
struct V_13 * V_250 ;
struct V_301 * V_302 ;
T_2 V_303 = 0 ;
T_4 V_173 ;
int V_37 ;
V_250 = V_140 -> V_7 [ 0 ] ;
F_189 ( V_250 , & V_84 , V_140 -> V_16 [ 0 ] ) ;
F_72 ( V_84 . type != V_304 &&
V_84 . type != V_305 ) ;
if ( F_194 ( V_18 , V_250 ) >= V_226 )
return 0 ;
V_173 = F_227 ( V_250 , V_140 -> V_16 [ 0 ] ) ;
if ( V_84 . type == V_304 ) {
V_302 = F_229 ( V_250 , V_140 -> V_16 [ 0 ] ,
struct V_301 ) ;
V_303 = F_230 ( V_250 , V_302 ) ;
}
F_8 ( V_140 ) ;
V_140 -> V_221 = 1 ;
V_140 -> V_227 = 1 ;
V_37 = F_187 ( V_32 , V_18 , & V_84 , V_140 , 0 , 1 ) ;
V_140 -> V_227 = 0 ;
if ( V_37 > 0 )
V_37 = - V_225 ;
if ( V_37 < 0 )
goto V_167;
V_37 = - V_225 ;
V_250 = V_140 -> V_7 [ 0 ] ;
if ( V_173 != F_227 ( V_250 , V_140 -> V_16 [ 0 ] ) )
goto V_167;
if ( F_194 ( V_18 , V_140 -> V_7 [ 0 ] ) >= V_226 )
goto V_167;
if ( V_84 . type == V_304 ) {
V_302 = F_229 ( V_250 , V_140 -> V_16 [ 0 ] ,
struct V_301 ) ;
if ( V_303 != F_230 ( V_250 , V_302 ) )
goto V_167;
}
F_3 ( V_140 ) ;
V_37 = F_195 ( V_32 , V_18 , & V_84 , V_140 , V_226 , 1 ) ;
if ( V_37 )
goto V_167;
V_140 -> V_221 = 0 ;
F_177 ( V_140 , 1 ) ;
return 0 ;
V_167:
V_140 -> V_221 = 0 ;
return V_37 ;
}
static T_1 int F_231 ( struct V_31 * V_32 ,
struct V_17 * V_18 ,
struct V_1 * V_140 ,
struct V_156 * V_252 ,
unsigned long V_306 )
{
struct V_13 * V_250 ;
struct V_187 * V_281 ;
struct V_187 * V_307 ;
int V_79 ;
char * V_33 ;
T_4 V_97 ;
T_4 V_173 ;
T_4 V_308 ;
struct V_39 V_40 ;
V_250 = V_140 -> V_7 [ 0 ] ;
F_72 ( F_194 ( V_18 , V_250 ) < sizeof( struct V_187 ) ) ;
F_3 ( V_140 ) ;
V_281 = F_208 ( V_140 -> V_16 [ 0 ] ) ;
V_308 = F_232 ( V_250 , V_281 ) ;
V_173 = F_215 ( V_250 , V_281 ) ;
V_33 = F_233 ( V_173 , V_3 ) ;
if ( ! V_33 )
return - V_87 ;
F_157 ( V_250 , V_33 , F_234 ( V_250 ,
V_140 -> V_16 [ 0 ] ) , V_173 ) ;
V_79 = V_140 -> V_16 [ 0 ] + 1 ;
V_97 = F_90 ( V_250 ) ;
if ( V_79 != V_97 ) {
F_125 ( V_250 , F_219 ( V_79 + 1 ) ,
F_219 ( V_79 ) ,
( V_97 - V_79 ) * sizeof( struct V_187 ) ) ;
}
F_183 ( & V_40 , V_252 ) ;
F_201 ( V_250 , & V_40 , V_79 ) ;
V_307 = F_208 ( V_79 ) ;
F_235 ( V_250 , V_307 , V_308 ) ;
F_236 ( V_250 , V_307 , V_173 - V_306 ) ;
F_235 ( V_250 , V_281 ,
V_308 + V_173 - V_306 ) ;
F_236 ( V_250 , V_281 , V_306 ) ;
F_126 ( V_250 , V_97 + 1 ) ;
F_46 ( V_250 , V_33 ,
F_234 ( V_250 , V_140 -> V_16 [ 0 ] ) ,
V_306 ) ;
F_46 ( V_250 , V_33 + V_306 ,
F_234 ( V_250 , V_79 ) ,
V_173 - V_306 ) ;
F_50 ( V_250 ) ;
F_72 ( F_194 ( V_18 , V_250 ) < 0 ) ;
F_70 ( V_33 ) ;
return 0 ;
}
int F_237 ( struct V_31 * V_32 ,
struct V_17 * V_18 ,
struct V_1 * V_140 ,
struct V_156 * V_252 ,
unsigned long V_306 )
{
int V_37 ;
V_37 = F_228 ( V_32 , V_18 , V_140 ,
sizeof( struct V_187 ) ) ;
if ( V_37 )
return V_37 ;
V_37 = F_231 ( V_32 , V_18 , V_140 , V_252 , V_306 ) ;
return V_37 ;
}
int F_238 ( struct V_31 * V_32 ,
struct V_17 * V_18 ,
struct V_1 * V_140 ,
struct V_156 * V_252 )
{
struct V_13 * V_250 ;
int V_37 ;
T_4 V_173 ;
V_250 = V_140 -> V_7 [ 0 ] ;
V_173 = F_227 ( V_250 , V_140 -> V_16 [ 0 ] ) ;
V_37 = F_228 ( V_32 , V_18 , V_140 ,
V_173 + sizeof( struct V_187 ) ) ;
if ( V_37 )
return V_37 ;
V_140 -> V_16 [ 0 ] ++ ;
F_239 ( V_18 , V_140 , V_252 , & V_173 ,
V_173 , V_173 +
sizeof( struct V_187 ) , 1 ) ;
V_250 = V_140 -> V_7 [ 0 ] ;
F_240 ( V_250 ,
F_234 ( V_250 , V_140 -> V_16 [ 0 ] ) ,
F_234 ( V_250 , V_140 -> V_16 [ 0 ] - 1 ) ,
V_173 ) ;
return 0 ;
}
void F_241 ( struct V_17 * V_18 , struct V_1 * V_140 ,
T_4 V_309 , int V_310 )
{
int V_79 ;
struct V_13 * V_250 ;
struct V_187 * V_281 ;
T_4 V_97 ;
unsigned int V_283 ;
unsigned int V_311 ;
unsigned int V_312 ;
unsigned int V_313 ;
int V_5 ;
struct V_271 V_272 ;
F_207 ( & V_272 ) ;
V_250 = V_140 -> V_7 [ 0 ] ;
V_79 = V_140 -> V_16 [ 0 ] ;
V_312 = F_227 ( V_250 , V_79 ) ;
if ( V_312 == V_309 )
return;
V_97 = F_90 ( V_250 ) ;
V_283 = F_217 ( V_18 , V_250 ) ;
V_311 = F_223 ( V_250 , V_79 ) ;
V_313 = V_312 - V_309 ;
F_72 ( V_79 < 0 ) ;
F_72 ( V_79 >= V_97 ) ;
for ( V_5 = V_79 ; V_5 < V_97 ; V_5 ++ ) {
T_4 V_234 ;
V_281 = F_208 ( V_5 ) ;
V_234 = F_209 ( V_250 , V_281 , & V_272 ) ;
F_220 ( V_250 , V_281 ,
V_234 + V_313 , & V_272 ) ;
}
if ( V_310 ) {
F_125 ( V_250 , F_218 ( V_250 ) +
V_283 + V_313 , F_218 ( V_250 ) +
V_283 , V_311 + V_309 - V_283 ) ;
} else {
struct V_39 V_40 ;
T_2 V_159 ;
F_34 ( V_250 , & V_40 , V_79 ) ;
if ( F_242 ( & V_40 ) == V_304 ) {
unsigned long V_314 ;
struct V_301 * V_302 ;
V_302 = F_229 ( V_250 , V_79 ,
struct V_301 ) ;
V_302 = (struct V_301 * ) (
( unsigned long ) V_302 - V_313 ) ;
if ( F_243 ( V_250 , V_302 ) ==
V_315 ) {
V_314 = F_234 ( V_250 , V_79 ) ;
F_125 ( V_250 , V_314 ,
( unsigned long ) V_302 ,
V_316 ) ;
}
}
F_125 ( V_250 , F_218 ( V_250 ) +
V_283 + V_313 , F_218 ( V_250 ) +
V_283 , V_311 - V_283 ) ;
V_159 = F_244 ( & V_40 ) ;
F_245 ( & V_40 , V_159 + V_313 ) ;
F_201 ( V_250 , & V_40 , V_79 ) ;
if ( V_79 == 0 )
F_199 ( V_18 -> V_25 , V_140 , & V_40 , 1 ) ;
}
V_281 = F_208 ( V_79 ) ;
F_236 ( V_250 , V_281 , V_309 ) ;
F_50 ( V_250 ) ;
if ( F_194 ( V_18 , V_250 ) < 0 ) {
F_246 ( V_18 , V_250 ) ;
F_170 () ;
}
}
void F_247 ( struct V_17 * V_18 , struct V_1 * V_140 ,
T_4 V_275 )
{
int V_79 ;
struct V_13 * V_250 ;
struct V_187 * V_281 ;
T_4 V_97 ;
unsigned int V_283 ;
unsigned int V_317 ;
unsigned int V_312 ;
int V_5 ;
struct V_271 V_272 ;
F_207 ( & V_272 ) ;
V_250 = V_140 -> V_7 [ 0 ] ;
V_97 = F_90 ( V_250 ) ;
V_283 = F_217 ( V_18 , V_250 ) ;
if ( F_194 ( V_18 , V_250 ) < V_275 ) {
F_246 ( V_18 , V_250 ) ;
F_170 () ;
}
V_79 = V_140 -> V_16 [ 0 ] ;
V_317 = F_216 ( V_250 , V_79 ) ;
F_72 ( V_79 < 0 ) ;
if ( V_79 >= V_97 ) {
F_246 ( V_18 , V_250 ) ;
F_212 ( V_18 -> V_25 , L_6 ,
V_79 , V_97 ) ;
F_72 ( 1 ) ;
}
for ( V_5 = V_79 ; V_5 < V_97 ; V_5 ++ ) {
T_4 V_234 ;
V_281 = F_208 ( V_5 ) ;
V_234 = F_209 ( V_250 , V_281 , & V_272 ) ;
F_220 ( V_250 , V_281 ,
V_234 - V_275 , & V_272 ) ;
}
F_125 ( V_250 , F_218 ( V_250 ) +
V_283 - V_275 , F_218 ( V_250 ) +
V_283 , V_317 - V_283 ) ;
V_283 = V_317 ;
V_312 = F_227 ( V_250 , V_79 ) ;
V_281 = F_208 ( V_79 ) ;
F_236 ( V_250 , V_281 , V_312 + V_275 ) ;
F_50 ( V_250 ) ;
if ( F_194 ( V_18 , V_250 ) < 0 ) {
F_246 ( V_18 , V_250 ) ;
F_170 () ;
}
}
void F_239 ( struct V_17 * V_18 , struct V_1 * V_140 ,
struct V_156 * V_318 , T_4 * V_275 ,
T_4 V_319 , T_4 V_320 , int V_208 )
{
struct V_187 * V_281 ;
int V_5 ;
T_4 V_97 ;
unsigned int V_283 ;
struct V_39 V_40 ;
struct V_13 * V_250 ;
int V_79 ;
struct V_271 V_272 ;
if ( V_140 -> V_16 [ 0 ] == 0 ) {
F_183 ( & V_40 , V_318 ) ;
F_199 ( V_18 -> V_25 , V_140 , & V_40 , 1 ) ;
}
F_177 ( V_140 , 1 ) ;
F_207 ( & V_272 ) ;
V_250 = V_140 -> V_7 [ 0 ] ;
V_79 = V_140 -> V_16 [ 0 ] ;
V_97 = F_90 ( V_250 ) ;
V_283 = F_217 ( V_18 , V_250 ) ;
if ( F_194 ( V_18 , V_250 ) < V_320 ) {
F_246 ( V_18 , V_250 ) ;
F_212 ( V_18 -> V_25 ,
L_7 ,
V_320 , F_194 ( V_18 , V_250 ) ) ;
F_170 () ;
}
if ( V_79 != V_97 ) {
unsigned int V_317 = F_216 ( V_250 , V_79 ) ;
if ( V_317 < V_283 ) {
F_246 ( V_18 , V_250 ) ;
F_212 ( V_18 -> V_25 ,
L_8 ,
V_79 , V_317 , V_283 ) ;
F_72 ( 1 ) ;
}
for ( V_5 = V_79 ; V_5 < V_97 ; V_5 ++ ) {
T_4 V_234 ;
V_281 = F_208 ( V_5 ) ;
V_234 = F_209 ( V_250 , V_281 , & V_272 ) ;
F_220 ( V_250 , V_281 ,
V_234 - V_319 , & V_272 ) ;
}
F_125 ( V_250 , F_219 ( V_79 + V_208 ) ,
F_219 ( V_79 ) ,
( V_97 - V_79 ) * sizeof( struct V_187 ) ) ;
F_125 ( V_250 , F_218 ( V_250 ) +
V_283 - V_319 , F_218 ( V_250 ) +
V_283 , V_317 - V_283 ) ;
V_283 = V_317 ;
}
for ( V_5 = 0 ; V_5 < V_208 ; V_5 ++ ) {
F_183 ( & V_40 , V_318 + V_5 ) ;
F_201 ( V_250 , & V_40 , V_79 + V_5 ) ;
V_281 = F_208 ( V_79 + V_5 ) ;
F_220 ( V_250 , V_281 ,
V_283 - V_275 [ V_5 ] , & V_272 ) ;
V_283 -= V_275 [ V_5 ] ;
F_248 ( V_250 , V_281 , V_275 [ V_5 ] , & V_272 ) ;
}
F_126 ( V_250 , V_97 + V_208 ) ;
F_50 ( V_250 ) ;
if ( F_194 ( V_18 , V_250 ) < 0 ) {
F_246 ( V_18 , V_250 ) ;
F_170 () ;
}
}
int F_249 ( struct V_31 * V_32 ,
struct V_17 * V_18 ,
struct V_1 * V_140 ,
struct V_156 * V_318 , T_4 * V_275 ,
int V_208 )
{
int V_37 = 0 ;
int V_79 ;
int V_5 ;
T_4 V_320 = 0 ;
T_4 V_319 = 0 ;
for ( V_5 = 0 ; V_5 < V_208 ; V_5 ++ )
V_319 += V_275 [ V_5 ] ;
V_320 = V_319 + ( V_208 * sizeof( struct V_187 ) ) ;
V_37 = F_187 ( V_32 , V_18 , V_318 , V_140 , V_320 , 1 ) ;
if ( V_37 == 0 )
return - V_78 ;
if ( V_37 < 0 )
return V_37 ;
V_79 = V_140 -> V_16 [ 0 ] ;
F_72 ( V_79 < 0 ) ;
F_239 ( V_18 , V_140 , V_318 , V_275 ,
V_319 , V_320 , V_208 ) ;
return 0 ;
}
int F_250 ( struct V_31 * V_32 , struct V_17
* V_18 , struct V_156 * V_318 , void * V_321 , T_4
V_275 )
{
int V_37 = 0 ;
struct V_1 * V_140 ;
struct V_13 * V_250 ;
unsigned long V_314 ;
V_140 = F_1 () ;
if ( ! V_140 )
return - V_87 ;
V_37 = F_251 ( V_32 , V_18 , V_140 , V_318 , V_275 ) ;
if ( ! V_37 ) {
V_250 = V_140 -> V_7 [ 0 ] ;
V_314 = F_234 ( V_250 , V_140 -> V_16 [ 0 ] ) ;
F_46 ( V_250 , V_321 , V_314 , V_275 ) ;
F_50 ( V_250 ) ;
}
F_7 ( V_140 ) ;
return V_37 ;
}
static void F_168 ( struct V_17 * V_18 , struct V_1 * V_140 ,
int V_38 , int V_79 )
{
struct V_13 * V_73 = V_140 -> V_7 [ V_38 ] ;
T_4 V_97 ;
int V_37 ;
V_97 = F_90 ( V_73 ) ;
if ( V_79 != V_97 - 1 ) {
if ( V_38 )
F_95 ( V_18 -> V_25 , V_73 , V_79 ,
V_79 + 1 , V_97 - V_79 - 1 ) ;
F_125 ( V_73 ,
F_124 ( V_79 ) ,
F_124 ( V_79 + 1 ) ,
sizeof( struct V_139 ) *
( V_97 - V_79 - 1 ) ) ;
} else if ( V_38 ) {
V_37 = F_84 ( V_18 -> V_25 , V_73 , V_79 ,
V_112 , V_3 ) ;
F_72 ( V_37 < 0 ) ;
}
V_97 -- ;
F_126 ( V_73 , V_97 ) ;
if ( V_97 == 0 && V_73 == V_18 -> V_20 ) {
F_72 ( F_33 ( V_18 -> V_20 ) != 1 ) ;
F_130 ( V_18 -> V_20 , 0 ) ;
} else if ( V_79 == 0 ) {
struct V_39 V_40 ;
F_35 ( V_73 , & V_40 , 0 ) ;
F_199 ( V_18 -> V_25 , V_140 , & V_40 , V_38 + 1 ) ;
}
F_50 ( V_73 ) ;
}
static T_1 void F_252 ( struct V_31 * V_32 ,
struct V_17 * V_18 ,
struct V_1 * V_140 ,
struct V_13 * V_250 )
{
F_32 ( F_48 ( V_250 ) != V_32 -> V_42 ) ;
F_168 ( V_18 , V_140 , 1 , V_140 -> V_16 [ 1 ] ) ;
F_177 ( V_140 , 0 ) ;
F_164 ( V_18 , V_250 -> V_46 ) ;
F_115 ( V_250 ) ;
F_117 ( V_32 , V_18 , V_250 , 0 , 1 ) ;
F_120 ( V_250 ) ;
}
int F_253 ( struct V_31 * V_32 , struct V_17 * V_18 ,
struct V_1 * V_140 , int V_79 , int V_208 )
{
struct V_13 * V_250 ;
struct V_187 * V_281 ;
T_4 V_322 ;
T_4 V_323 = 0 ;
int V_37 = 0 ;
int V_194 ;
int V_5 ;
T_4 V_97 ;
struct V_271 V_272 ;
F_207 ( & V_272 ) ;
V_250 = V_140 -> V_7 [ 0 ] ;
V_322 = F_223 ( V_250 , V_79 + V_208 - 1 ) ;
for ( V_5 = 0 ; V_5 < V_208 ; V_5 ++ )
V_323 += F_227 ( V_250 , V_79 + V_5 ) ;
V_97 = F_90 ( V_250 ) ;
if ( V_79 + V_208 != V_97 ) {
int V_283 = F_217 ( V_18 , V_250 ) ;
F_125 ( V_250 , F_218 ( V_250 ) +
V_283 + V_323 ,
F_218 ( V_250 ) + V_283 ,
V_322 - V_283 ) ;
for ( V_5 = V_79 + V_208 ; V_5 < V_97 ; V_5 ++ ) {
T_4 V_234 ;
V_281 = F_208 ( V_5 ) ;
V_234 = F_209 ( V_250 , V_281 , & V_272 ) ;
F_220 ( V_250 , V_281 ,
V_234 + V_323 , & V_272 ) ;
}
F_125 ( V_250 , F_219 ( V_79 ) ,
F_219 ( V_79 + V_208 ) ,
sizeof( struct V_187 ) *
( V_97 - V_79 - V_208 ) ) ;
}
F_126 ( V_250 , V_97 - V_208 ) ;
V_97 -= V_208 ;
if ( V_97 == 0 ) {
if ( V_250 == V_18 -> V_20 ) {
F_130 ( V_250 , 0 ) ;
} else {
F_3 ( V_140 ) ;
F_110 ( V_32 , V_18 -> V_25 , V_250 ) ;
F_252 ( V_32 , V_18 , V_140 , V_250 ) ;
}
} else {
int V_324 = F_206 ( V_250 , 0 , V_97 ) ;
if ( V_79 == 0 ) {
struct V_39 V_40 ;
F_34 ( V_250 , & V_40 , 0 ) ;
F_199 ( V_18 -> V_25 , V_140 , & V_40 , 1 ) ;
}
if ( V_324 < F_211 ( V_18 ) / 3 ) {
V_79 = V_140 -> V_16 [ 1 ] ;
F_115 ( V_250 ) ;
F_3 ( V_140 ) ;
V_194 = F_224 ( V_32 , V_18 , V_140 , 1 , 1 ,
1 , ( T_4 ) - 1 ) ;
if ( V_194 < 0 && V_194 != - V_200 )
V_37 = V_194 ;
if ( V_140 -> V_7 [ 0 ] == V_250 &&
F_90 ( V_250 ) ) {
V_194 = F_221 ( V_32 , V_18 , V_140 , 1 ,
1 , 1 , 0 ) ;
if ( V_194 < 0 && V_194 != - V_200 )
V_37 = V_194 ;
}
if ( F_90 ( V_250 ) == 0 ) {
V_140 -> V_16 [ 1 ] = V_79 ;
F_252 ( V_32 , V_18 , V_140 , V_250 ) ;
F_11 ( V_250 ) ;
V_37 = 0 ;
} else {
if ( V_140 -> V_7 [ 0 ] == V_250 )
F_50 ( V_250 ) ;
F_11 ( V_250 ) ;
}
} else {
F_50 ( V_250 ) ;
}
}
return V_37 ;
}
int F_198 ( struct V_17 * V_18 , struct V_1 * V_140 )
{
struct V_156 V_84 ;
struct V_39 V_236 ;
int V_37 ;
F_189 ( V_140 -> V_7 [ 0 ] , & V_84 , 0 ) ;
if ( V_84 . V_159 > 0 ) {
V_84 . V_159 -- ;
} else if ( V_84 . type > 0 ) {
V_84 . type -- ;
V_84 . V_159 = ( T_2 ) - 1 ;
} else if ( V_84 . V_27 > 0 ) {
V_84 . V_27 -- ;
V_84 . type = ( T_5 ) - 1 ;
V_84 . V_159 = ( T_2 ) - 1 ;
} else {
return 1 ;
}
F_8 ( V_140 ) ;
V_37 = F_187 ( NULL , V_18 , & V_84 , V_140 , 0 , 0 ) ;
if ( V_37 < 0 )
return V_37 ;
F_34 ( V_140 -> V_7 [ 0 ] , & V_236 , 0 ) ;
V_37 = F_146 ( & V_236 , & V_84 ) ;
if ( V_37 <= 0 )
return 0 ;
return 1 ;
}
int F_254 ( struct V_17 * V_18 , struct V_156 * V_325 ,
struct V_1 * V_140 ,
T_2 V_326 )
{
struct V_13 * V_74 ;
struct V_156 V_236 ;
int V_79 ;
int V_228 ;
T_4 V_97 ;
int V_38 ;
int V_37 = 1 ;
int V_221 = V_140 -> V_221 ;
V_140 -> V_221 = 1 ;
V_229:
V_74 = F_21 ( V_18 ) ;
V_38 = F_33 ( V_74 ) ;
F_32 ( V_140 -> V_7 [ V_38 ] ) ;
V_140 -> V_7 [ V_38 ] = V_74 ;
V_140 -> V_8 [ V_38 ] = V_9 ;
if ( F_48 ( V_74 ) < V_326 ) {
V_37 = 1 ;
goto V_291;
}
while ( 1 ) {
V_97 = F_90 ( V_74 ) ;
V_38 = F_33 ( V_74 ) ;
V_228 = F_158 ( V_74 , V_325 , V_38 , & V_79 ) ;
if ( V_38 == V_140 -> V_238 ) {
if ( V_79 >= V_97 )
goto V_327;
V_37 = 0 ;
V_140 -> V_16 [ V_38 ] = V_79 ;
F_189 ( V_74 , & V_236 , V_79 ) ;
goto V_291;
}
if ( V_228 && V_79 > 0 )
V_79 -- ;
while ( V_79 < V_97 ) {
T_2 V_163 ;
V_163 = F_82 ( V_74 , V_79 ) ;
if ( V_163 < V_326 ) {
V_79 ++ ;
continue;
}
break;
}
V_327:
if ( V_79 >= V_97 ) {
V_140 -> V_16 [ V_38 ] = V_79 ;
F_3 ( V_140 ) ;
V_228 = F_255 ( V_18 , V_140 , V_325 , V_38 ,
V_326 ) ;
if ( V_228 == 0 ) {
F_8 ( V_140 ) ;
goto V_229;
} else {
goto V_291;
}
}
F_256 ( V_74 , & V_236 , V_79 ) ;
V_140 -> V_16 [ V_38 ] = V_79 ;
if ( V_38 == V_140 -> V_238 ) {
V_37 = 0 ;
goto V_291;
}
F_3 ( V_140 ) ;
V_74 = F_166 ( V_18 , V_74 , V_79 ) ;
if ( F_37 ( V_74 ) ) {
V_37 = F_38 ( V_74 ) ;
goto V_291;
}
F_22 ( V_74 ) ;
V_140 -> V_8 [ V_38 - 1 ] = V_9 ;
V_140 -> V_7 [ V_38 - 1 ] = V_74 ;
F_176 ( V_140 , V_38 , 1 , 0 , NULL ) ;
F_5 ( V_140 , NULL , 0 ) ;
}
V_291:
V_140 -> V_221 = V_221 ;
if ( V_37 == 0 ) {
F_177 ( V_140 , V_140 -> V_238 + 1 ) ;
F_3 ( V_140 ) ;
memcpy ( V_325 , & V_236 , sizeof( V_236 ) ) ;
}
return V_37 ;
}
static int F_257 ( struct V_17 * V_18 ,
struct V_1 * V_140 ,
int * V_38 , int V_328 )
{
struct V_13 * V_19 ;
F_72 ( * V_38 == 0 ) ;
V_19 = F_166 ( V_18 , V_140 -> V_7 [ * V_38 ] , V_140 -> V_16 [ * V_38 ] ) ;
if ( F_37 ( V_19 ) )
return F_38 ( V_19 ) ;
V_140 -> V_7 [ * V_38 - 1 ] = V_19 ;
V_140 -> V_16 [ * V_38 - 1 ] = 0 ;
( * V_38 ) -- ;
return 0 ;
}
static int F_258 ( struct V_17 * V_18 ,
struct V_1 * V_140 ,
int * V_38 , int V_328 )
{
int V_37 = 0 ;
int V_97 ;
V_97 = F_90 ( V_140 -> V_7 [ * V_38 ] ) ;
V_140 -> V_16 [ * V_38 ] ++ ;
while ( V_140 -> V_16 [ * V_38 ] >= V_97 ) {
if ( * V_38 == V_328 )
return - 1 ;
V_140 -> V_16 [ * V_38 ] = 0 ;
F_11 ( V_140 -> V_7 [ * V_38 ] ) ;
V_140 -> V_7 [ * V_38 ] = NULL ;
( * V_38 ) ++ ;
V_140 -> V_16 [ * V_38 ] ++ ;
V_97 = F_90 ( V_140 -> V_7 [ * V_38 ] ) ;
V_37 = 1 ;
}
return V_37 ;
}
static int F_259 ( struct V_17 * V_18 ,
struct V_1 * V_140 ,
int * V_38 , int V_328 ,
int V_329 ,
struct V_156 * V_84 )
{
int V_37 ;
if ( * V_38 == 0 || ! V_329 ) {
V_37 = F_258 ( V_18 , V_140 , V_38 , V_328 ) ;
} else {
V_37 = F_257 ( V_18 , V_140 , V_38 , V_328 ) ;
}
if ( V_37 >= 0 ) {
if ( * V_38 == 0 )
F_189 ( V_140 -> V_7 [ * V_38 ] , V_84 ,
V_140 -> V_16 [ * V_38 ] ) ;
else
F_256 ( V_140 -> V_7 [ * V_38 ] , V_84 ,
V_140 -> V_16 [ * V_38 ] ) ;
}
return V_37 ;
}
static int F_260 ( struct V_17 * V_330 ,
struct V_1 * V_331 ,
struct V_1 * V_332 ,
char * V_333 )
{
int V_334 ;
int V_335 , V_336 ;
unsigned long V_337 , V_338 ;
V_335 = F_227 ( V_331 -> V_7 [ 0 ] , V_331 -> V_16 [ 0 ] ) ;
V_336 = F_227 ( V_332 -> V_7 [ 0 ] , V_332 -> V_16 [ 0 ] ) ;
if ( V_335 != V_336 )
return 1 ;
V_337 = F_234 ( V_331 -> V_7 [ 0 ] , V_331 -> V_16 [ 0 ] ) ;
V_338 = F_234 ( V_332 -> V_7 [ 0 ] ,
V_332 -> V_16 [ 0 ] ) ;
F_157 ( V_331 -> V_7 [ 0 ] , V_333 , V_337 , V_335 ) ;
V_334 = F_184 ( V_332 -> V_7 [ 0 ] , V_333 , V_338 , V_335 ) ;
if ( V_334 )
return 1 ;
return 0 ;
}
int F_261 ( struct V_17 * V_330 ,
struct V_17 * V_339 ,
T_6 V_340 , void * V_341 )
{
int V_37 ;
int V_334 ;
struct V_1 * V_331 = NULL ;
struct V_1 * V_332 = NULL ;
struct V_156 V_342 ;
struct V_156 V_201 ;
char * V_333 = NULL ;
int V_343 ;
int V_344 ;
int V_345 ;
int V_346 ;
int V_347 ;
int V_348 ;
int V_349 ;
int V_350 ;
T_2 V_351 ;
T_2 V_352 ;
T_2 V_353 ;
T_2 V_354 ;
V_331 = F_1 () ;
if ( ! V_331 ) {
V_37 = - V_87 ;
goto V_291;
}
V_332 = F_1 () ;
if ( ! V_332 ) {
V_37 = - V_87 ;
goto V_291;
}
V_333 = F_233 ( V_330 -> V_146 , V_355 | V_356 ) ;
if ( ! V_333 ) {
V_333 = F_262 ( V_330 -> V_146 ) ;
if ( ! V_333 ) {
V_37 = - V_87 ;
goto V_291;
}
}
V_331 -> V_239 = 1 ;
V_331 -> V_242 = 1 ;
V_332 -> V_239 = 1 ;
V_332 -> V_242 = 1 ;
F_190 ( & V_330 -> V_25 -> V_241 ) ;
V_345 = F_33 ( V_330 -> V_117 ) ;
V_343 = V_345 ;
V_331 -> V_7 [ V_345 ] = V_330 -> V_117 ;
F_115 ( V_331 -> V_7 [ V_345 ] ) ;
V_346 = F_33 ( V_339 -> V_117 ) ;
V_344 = V_346 ;
V_332 -> V_7 [ V_346 ] = V_339 -> V_117 ;
F_115 ( V_332 -> V_7 [ V_346 ] ) ;
F_191 ( & V_330 -> V_25 -> V_241 ) ;
if ( V_345 == 0 )
F_189 ( V_331 -> V_7 [ V_345 ] ,
& V_342 , V_331 -> V_16 [ V_345 ] ) ;
else
F_256 ( V_331 -> V_7 [ V_345 ] ,
& V_342 , V_331 -> V_16 [ V_345 ] ) ;
if ( V_346 == 0 )
F_189 ( V_332 -> V_7 [ V_346 ] ,
& V_201 , V_332 -> V_16 [ V_346 ] ) ;
else
F_256 ( V_332 -> V_7 [ V_346 ] ,
& V_201 , V_332 -> V_16 [ V_346 ] ) ;
V_347 = V_348 = 0 ;
V_349 = V_350 = 0 ;
while ( 1 ) {
if ( V_349 && ! V_347 ) {
V_37 = F_259 ( V_330 , V_331 , & V_345 ,
V_343 ,
V_349 != V_357 ,
& V_342 ) ;
if ( V_37 == - 1 )
V_347 = V_358 ;
else if ( V_37 < 0 )
goto V_291;
V_349 = 0 ;
}
if ( V_350 && ! V_348 ) {
V_37 = F_259 ( V_339 , V_332 , & V_346 ,
V_344 ,
V_350 != V_357 ,
& V_201 ) ;
if ( V_37 == - 1 )
V_348 = V_358 ;
else if ( V_37 < 0 )
goto V_291;
V_350 = 0 ;
}
if ( V_347 && V_348 ) {
V_37 = 0 ;
goto V_291;
} else if ( V_347 ) {
if ( V_346 == 0 ) {
V_37 = V_340 ( V_330 , V_339 ,
V_331 , V_332 ,
& V_201 ,
V_359 ,
V_341 ) ;
if ( V_37 < 0 )
goto V_291;
}
V_350 = V_358 ;
continue;
} else if ( V_348 ) {
if ( V_345 == 0 ) {
V_37 = V_340 ( V_330 , V_339 ,
V_331 , V_332 ,
& V_342 ,
V_360 ,
V_341 ) ;
if ( V_37 < 0 )
goto V_291;
}
V_349 = V_358 ;
continue;
}
if ( V_345 == 0 && V_346 == 0 ) {
V_334 = F_148 ( & V_342 , & V_201 ) ;
if ( V_334 < 0 ) {
V_37 = V_340 ( V_330 , V_339 ,
V_331 , V_332 ,
& V_342 ,
V_360 ,
V_341 ) ;
if ( V_37 < 0 )
goto V_291;
V_349 = V_358 ;
} else if ( V_334 > 0 ) {
V_37 = V_340 ( V_330 , V_339 ,
V_331 , V_332 ,
& V_201 ,
V_359 ,
V_341 ) ;
if ( V_37 < 0 )
goto V_291;
V_350 = V_358 ;
} else {
enum V_361 V_362 ;
F_32 ( ! F_135 ( V_331 -> V_7 [ 0 ] ) ) ;
V_37 = F_260 ( V_330 , V_331 ,
V_332 , V_333 ) ;
if ( V_37 )
V_362 = V_363 ;
else
V_362 = V_364 ;
V_37 = V_340 ( V_330 , V_339 ,
V_331 , V_332 ,
& V_342 , V_362 , V_341 ) ;
if ( V_37 < 0 )
goto V_291;
V_349 = V_358 ;
V_350 = V_358 ;
}
} else if ( V_345 == V_346 ) {
V_334 = F_148 ( & V_342 , & V_201 ) ;
if ( V_334 < 0 ) {
V_349 = V_358 ;
} else if ( V_334 > 0 ) {
V_350 = V_358 ;
} else {
V_351 = F_81 (
V_331 -> V_7 [ V_345 ] ,
V_331 -> V_16 [ V_345 ] ) ;
V_352 = F_81 (
V_332 -> V_7 [ V_346 ] ,
V_332 -> V_16 [ V_346 ] ) ;
V_353 = F_82 (
V_331 -> V_7 [ V_345 ] ,
V_331 -> V_16 [ V_345 ] ) ;
V_354 = F_82 (
V_332 -> V_7 [ V_346 ] ,
V_332 -> V_16 [ V_346 ] ) ;
if ( V_351 == V_352 &&
V_353 == V_354 ) {
V_349 = V_357 ;
V_350 = V_357 ;
} else {
V_349 = V_358 ;
V_350 = V_358 ;
}
}
} else if ( V_345 < V_346 ) {
V_350 = V_358 ;
} else {
V_349 = V_358 ;
}
}
V_291:
F_7 ( V_331 ) ;
F_7 ( V_332 ) ;
F_263 ( V_333 ) ;
return V_37 ;
}
int F_255 ( struct V_17 * V_18 , struct V_1 * V_140 ,
struct V_156 * V_84 , int V_38 , T_2 V_326 )
{
int V_79 ;
struct V_13 * V_260 ;
F_32 ( ! V_140 -> V_221 ) ;
while ( V_38 < V_6 ) {
if ( ! V_140 -> V_7 [ V_38 ] )
return 1 ;
V_79 = V_140 -> V_16 [ V_38 ] + 1 ;
V_260 = V_140 -> V_7 [ V_38 ] ;
V_65:
if ( V_79 >= F_90 ( V_260 ) ) {
int V_37 ;
int V_365 ;
struct V_156 V_366 ;
if ( V_38 + 1 >= V_6 ||
! V_140 -> V_7 [ V_38 + 1 ] )
return 1 ;
if ( V_140 -> V_8 [ V_38 + 1 ] ) {
V_38 ++ ;
continue;
}
V_79 = F_90 ( V_260 ) - 1 ;
if ( V_38 == 0 )
F_189 ( V_260 , & V_366 , V_79 ) ;
else
F_256 ( V_260 , & V_366 , V_79 ) ;
V_365 = V_140 -> V_238 ;
F_8 ( V_140 ) ;
V_140 -> V_238 = V_38 ;
V_37 = F_187 ( NULL , V_18 , & V_366 , V_140 ,
0 , 0 ) ;
V_140 -> V_238 = V_365 ;
if ( V_37 < 0 )
return V_37 ;
V_260 = V_140 -> V_7 [ V_38 ] ;
V_79 = V_140 -> V_16 [ V_38 ] ;
if ( V_37 == 0 )
V_79 ++ ;
goto V_65;
}
if ( V_38 == 0 )
F_189 ( V_260 , V_84 , V_79 ) ;
else {
T_2 V_163 = F_82 ( V_260 , V_79 ) ;
if ( V_163 < V_326 ) {
V_79 ++ ;
goto V_65;
}
F_256 ( V_260 , V_84 , V_79 ) ;
}
return 0 ;
}
return 1 ;
}
int F_188 ( struct V_17 * V_18 , struct V_1 * V_140 )
{
return F_264 ( V_18 , V_140 , 0 ) ;
}
int F_264 ( struct V_17 * V_18 , struct V_1 * V_140 ,
T_2 V_131 )
{
int V_79 ;
int V_38 ;
struct V_13 * V_260 ;
struct V_13 * V_65 ;
struct V_156 V_84 ;
T_4 V_97 ;
int V_37 ;
int V_367 = V_140 -> V_246 ;
int V_368 = 0 ;
V_97 = F_90 ( V_140 -> V_7 [ 0 ] ) ;
if ( V_97 == 0 )
return 1 ;
F_189 ( V_140 -> V_7 [ 0 ] , & V_84 , V_97 - 1 ) ;
V_229:
V_38 = 1 ;
V_65 = NULL ;
V_368 = 0 ;
F_8 ( V_140 ) ;
V_140 -> V_221 = 1 ;
V_140 -> V_246 = 1 ;
if ( V_131 )
V_37 = F_196 ( V_18 , & V_84 , V_140 , V_131 ) ;
else
V_37 = F_187 ( NULL , V_18 , & V_84 , V_140 , 0 , 0 ) ;
V_140 -> V_221 = 0 ;
if ( V_37 < 0 )
return V_37 ;
V_97 = F_90 ( V_140 -> V_7 [ 0 ] ) ;
if ( V_97 > 0 && V_140 -> V_16 [ 0 ] < V_97 - 1 ) {
if ( V_37 == 0 )
V_140 -> V_16 [ 0 ] ++ ;
V_37 = 0 ;
goto V_230;
}
if ( V_97 > 0 && V_37 > 0 && V_140 -> V_16 [ 0 ] == V_97 - 1 ) {
V_37 = 0 ;
goto V_230;
}
while ( V_38 < V_6 ) {
if ( ! V_140 -> V_7 [ V_38 ] ) {
V_37 = 1 ;
goto V_230;
}
V_79 = V_140 -> V_16 [ V_38 ] + 1 ;
V_260 = V_140 -> V_7 [ V_38 ] ;
if ( V_79 >= F_90 ( V_260 ) ) {
V_38 ++ ;
if ( V_38 == V_6 ) {
V_37 = 1 ;
goto V_230;
}
continue;
}
if ( V_65 ) {
F_10 ( V_65 , V_368 ) ;
F_11 ( V_65 ) ;
}
V_65 = V_260 ;
V_368 = V_140 -> V_8 [ V_38 ] ;
V_37 = F_178 ( NULL , V_18 , V_140 , & V_65 , V_38 ,
V_79 , & V_84 , 0 ) ;
if ( V_37 == - V_225 )
goto V_229;
if ( V_37 < 0 ) {
F_8 ( V_140 ) ;
goto V_230;
}
if ( ! V_140 -> V_242 ) {
V_37 = F_265 ( V_65 ) ;
if ( ! V_37 && V_131 ) {
F_11 ( V_65 ) ;
F_8 ( V_140 ) ;
F_266 () ;
goto V_229;
}
if ( ! V_37 ) {
F_3 ( V_140 ) ;
F_22 ( V_65 ) ;
F_5 ( V_140 , V_65 ,
V_9 ) ;
}
V_368 = V_9 ;
}
break;
}
V_140 -> V_16 [ V_38 ] = V_79 ;
while ( 1 ) {
V_38 -- ;
V_260 = V_140 -> V_7 [ V_38 ] ;
if ( V_140 -> V_8 [ V_38 ] )
F_10 ( V_260 , V_140 -> V_8 [ V_38 ] ) ;
F_11 ( V_260 ) ;
V_140 -> V_7 [ V_38 ] = V_65 ;
V_140 -> V_16 [ V_38 ] = 0 ;
if ( ! V_140 -> V_242 )
V_140 -> V_8 [ V_38 ] = V_368 ;
if ( ! V_38 )
break;
V_37 = F_178 ( NULL , V_18 , V_140 , & V_65 , V_38 ,
0 , & V_84 , 0 ) ;
if ( V_37 == - V_225 )
goto V_229;
if ( V_37 < 0 ) {
F_8 ( V_140 ) ;
goto V_230;
}
if ( ! V_140 -> V_242 ) {
V_37 = F_265 ( V_65 ) ;
if ( ! V_37 ) {
F_3 ( V_140 ) ;
F_22 ( V_65 ) ;
F_5 ( V_140 , V_65 ,
V_9 ) ;
}
V_368 = V_9 ;
}
}
V_37 = 0 ;
V_230:
F_176 ( V_140 , 0 , 1 , 0 , NULL ) ;
V_140 -> V_246 = V_367 ;
if ( ! V_367 )
F_3 ( V_140 ) ;
return V_37 ;
}
int F_267 ( struct V_17 * V_18 ,
struct V_1 * V_140 , T_2 V_369 ,
int type )
{
struct V_156 V_236 ;
struct V_13 * V_250 ;
T_4 V_97 ;
int V_37 ;
while ( 1 ) {
if ( V_140 -> V_16 [ 0 ] == 0 ) {
F_3 ( V_140 ) ;
V_37 = F_198 ( V_18 , V_140 ) ;
if ( V_37 != 0 )
return V_37 ;
} else {
V_140 -> V_16 [ 0 ] -- ;
}
V_250 = V_140 -> V_7 [ 0 ] ;
V_97 = F_90 ( V_250 ) ;
if ( V_97 == 0 )
return 1 ;
if ( V_140 -> V_16 [ 0 ] == V_97 )
V_140 -> V_16 [ 0 ] -- ;
F_189 ( V_250 , & V_236 , V_140 -> V_16 [ 0 ] ) ;
if ( V_236 . V_27 < V_369 )
break;
if ( V_236 . type == type )
return 0 ;
if ( V_236 . V_27 == V_369 &&
V_236 . type < type )
break;
}
return 1 ;
}
int F_268 ( struct V_17 * V_18 ,
struct V_1 * V_140 , T_2 V_369 )
{
struct V_156 V_236 ;
struct V_13 * V_250 ;
T_4 V_97 ;
int V_37 ;
while ( 1 ) {
if ( V_140 -> V_16 [ 0 ] == 0 ) {
F_3 ( V_140 ) ;
V_37 = F_198 ( V_18 , V_140 ) ;
if ( V_37 != 0 )
return V_37 ;
} else {
V_140 -> V_16 [ 0 ] -- ;
}
V_250 = V_140 -> V_7 [ 0 ] ;
V_97 = F_90 ( V_250 ) ;
if ( V_97 == 0 )
return 1 ;
if ( V_140 -> V_16 [ 0 ] == V_97 )
V_140 -> V_16 [ 0 ] -- ;
F_189 ( V_250 , & V_236 , V_140 -> V_16 [ 0 ] ) ;
if ( V_236 . V_27 < V_369 )
break;
if ( V_236 . type == V_370 ||
V_236 . type == V_371 )
return 0 ;
if ( V_236 . V_27 == V_369 &&
V_236 . type < V_370 )
break;
}
return 1 ;
}
