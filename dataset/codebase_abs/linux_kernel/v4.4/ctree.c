struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( V_3 , V_4 ) ;
return V_2 ;
}
T_1 void F_3 ( struct V_1 * V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
if ( ! V_5 -> V_8 [ V_6 ] || ! V_5 -> V_9 [ V_6 ] )
continue;
F_4 ( V_5 -> V_8 [ V_6 ] , V_5 -> V_9 [ V_6 ] ) ;
if ( V_5 -> V_9 [ V_6 ] == V_10 )
V_5 -> V_9 [ V_6 ] = V_11 ;
else if ( V_5 -> V_9 [ V_6 ] == V_12 )
V_5 -> V_9 [ V_6 ] = V_13 ;
}
}
T_1 void F_5 ( struct V_1 * V_5 ,
struct V_14 * V_15 , int V_16 )
{
int V_6 ;
if ( V_15 ) {
F_4 ( V_15 , V_16 ) ;
if ( V_16 == V_12 )
V_16 = V_13 ;
else if ( V_16 == V_10 )
V_16 = V_11 ;
}
F_3 ( V_5 ) ;
for ( V_6 = V_7 - 1 ; V_6 >= 0 ; V_6 -- ) {
if ( V_5 -> V_8 [ V_6 ] && V_5 -> V_9 [ V_6 ] ) {
F_6 ( V_5 -> V_8 [ V_6 ] , V_5 -> V_9 [ V_6 ] ) ;
if ( V_5 -> V_9 [ V_6 ] == V_13 )
V_5 -> V_9 [ V_6 ] = V_12 ;
else if ( V_5 -> V_9 [ V_6 ] == V_11 )
V_5 -> V_9 [ V_6 ] = V_10 ;
}
}
if ( V_15 )
F_6 ( V_15 , V_16 ) ;
}
void F_7 ( struct V_1 * V_5 )
{
if ( ! V_5 )
return;
F_8 ( V_5 ) ;
F_9 ( V_3 , V_5 ) ;
}
T_1 void F_8 ( struct V_1 * V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
V_5 -> V_17 [ V_6 ] = 0 ;
if ( ! V_5 -> V_8 [ V_6 ] )
continue;
if ( V_5 -> V_9 [ V_6 ] ) {
F_10 ( V_5 -> V_8 [ V_6 ] , V_5 -> V_9 [ V_6 ] ) ;
V_5 -> V_9 [ V_6 ] = 0 ;
}
F_11 ( V_5 -> V_8 [ V_6 ] ) ;
V_5 -> V_8 [ V_6 ] = NULL ;
}
}
struct V_14 * F_12 ( struct V_18 * V_19 )
{
struct V_14 * V_20 ;
while ( 1 ) {
F_13 () ;
V_20 = F_14 ( V_19 -> V_21 ) ;
if ( F_15 ( & V_20 -> V_22 ) ) {
F_16 () ;
break;
}
F_16 () ;
F_17 () ;
}
return V_20 ;
}
struct V_14 * F_18 ( struct V_18 * V_19 )
{
struct V_14 * V_20 ;
while ( 1 ) {
V_20 = F_12 ( V_19 ) ;
F_19 ( V_20 ) ;
if ( V_20 == V_19 -> V_21 )
break;
F_20 ( V_20 ) ;
F_11 ( V_20 ) ;
}
return V_20 ;
}
static struct V_14 * F_21 ( struct V_18 * V_19 )
{
struct V_14 * V_20 ;
while ( 1 ) {
V_20 = F_12 ( V_19 ) ;
F_22 ( V_20 ) ;
if ( V_20 == V_19 -> V_21 )
break;
F_23 ( V_20 ) ;
F_11 ( V_20 ) ;
}
return V_20 ;
}
static void F_24 ( struct V_18 * V_19 )
{
if ( F_25 ( V_23 , & V_19 -> V_24 ) ||
! F_25 ( V_25 , & V_19 -> V_24 ) )
return;
F_26 ( & V_19 -> V_26 -> V_27 ) ;
if ( ! F_27 ( V_23 , & V_19 -> V_24 ) ) {
if ( V_19 -> V_28 == V_29 )
F_28 ( & V_19 -> V_30 ,
& V_19 -> V_26 -> V_31 ) ;
else
F_29 ( & V_19 -> V_30 ,
& V_19 -> V_26 -> V_31 ) ;
}
F_30 ( & V_19 -> V_26 -> V_27 ) ;
}
int F_31 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_14 * V_34 ,
struct V_14 * * V_35 , T_2 V_36 )
{
struct V_14 * V_37 ;
int V_38 = 0 ;
int V_39 ;
struct V_40 V_41 ;
F_32 ( F_25 ( V_42 , & V_19 -> V_24 ) &&
V_33 -> V_43 != V_19 -> V_26 -> V_44 -> V_43 ) ;
F_32 ( F_25 ( V_42 , & V_19 -> V_24 ) &&
V_33 -> V_43 != V_19 -> V_45 ) ;
V_39 = F_33 ( V_34 ) ;
if ( V_39 == 0 )
F_34 ( V_34 , & V_41 , 0 ) ;
else
F_35 ( V_34 , & V_41 , 0 ) ;
V_37 = F_36 ( V_33 , V_19 , 0 , V_36 ,
& V_41 , V_39 , V_34 -> V_46 , 0 ) ;
if ( F_37 ( V_37 ) )
return F_38 ( V_37 ) ;
F_39 ( V_37 , V_34 , 0 , 0 , V_37 -> V_47 ) ;
F_40 ( V_37 , V_37 -> V_46 ) ;
F_41 ( V_37 , V_33 -> V_43 ) ;
F_42 ( V_37 , V_48 ) ;
F_43 ( V_37 , V_49 |
V_50 ) ;
if ( V_36 == V_51 )
F_44 ( V_37 , V_50 ) ;
else
F_45 ( V_37 , V_36 ) ;
F_46 ( V_37 , V_19 -> V_26 -> V_52 , F_47 () ,
V_53 ) ;
F_32 ( F_48 ( V_34 ) > V_33 -> V_43 ) ;
if ( V_36 == V_51 )
V_38 = F_49 ( V_33 , V_19 , V_37 , 1 ) ;
else
V_38 = F_49 ( V_33 , V_19 , V_37 , 0 ) ;
if ( V_38 )
return V_38 ;
F_50 ( V_37 ) ;
* V_35 = V_37 ;
return 0 ;
}
static inline void F_51 ( struct V_54 * V_26 )
{
F_52 ( & V_26 -> V_55 ) ;
}
static inline void F_53 ( struct V_54 * V_26 )
{
F_54 ( & V_26 -> V_55 ) ;
}
static inline void F_55 ( struct V_54 * V_26 )
{
F_56 ( & V_26 -> V_55 ) ;
}
static inline void F_57 ( struct V_54 * V_26 )
{
F_58 ( & V_26 -> V_55 ) ;
}
static inline T_2 F_59 ( struct V_54 * V_26 )
{
return F_60 ( & V_26 -> V_56 ) ;
}
T_2 F_61 ( struct V_54 * V_26 ,
struct V_57 * V_58 )
{
F_55 ( V_26 ) ;
F_26 ( & V_26 -> V_59 ) ;
if ( ! V_58 -> V_60 ) {
V_58 -> V_60 = F_59 ( V_26 ) ;
F_62 ( & V_58 -> V_61 , & V_26 -> V_62 ) ;
}
F_30 ( & V_26 -> V_59 ) ;
F_57 ( V_26 ) ;
return V_58 -> V_60 ;
}
void F_63 ( struct V_54 * V_26 ,
struct V_57 * V_58 )
{
struct V_63 * V_64 ;
struct V_65 * V_21 ;
struct V_65 * V_66 ;
struct V_57 * V_67 ;
struct V_68 * V_69 ;
T_2 V_70 = ( T_2 ) - 1 ;
T_2 V_71 = V_58 -> V_60 ;
if ( ! V_71 )
return;
F_26 ( & V_26 -> V_59 ) ;
F_64 ( & V_58 -> V_61 ) ;
V_58 -> V_60 = 0 ;
F_65 (cur_elem, &fs_info->tree_mod_seq_list, list) {
if ( V_67 -> V_60 < V_70 ) {
if ( V_71 > V_67 -> V_60 ) {
F_30 ( & V_26 -> V_59 ) ;
return;
}
V_70 = V_67 -> V_60 ;
}
}
F_30 ( & V_26 -> V_59 ) ;
F_55 ( V_26 ) ;
V_64 = & V_26 -> V_72 ;
for ( V_21 = F_66 ( V_64 ) ; V_21 ; V_21 = V_66 ) {
V_66 = F_67 ( V_21 ) ;
V_69 = F_68 ( V_21 , struct V_68 , V_21 ) ;
if ( V_69 -> V_60 > V_70 )
continue;
F_69 ( V_21 , V_64 ) ;
F_70 ( V_69 ) ;
}
F_57 ( V_26 ) ;
}
static T_1 int
F_71 ( struct V_54 * V_26 , struct V_68 * V_69 )
{
struct V_63 * V_64 ;
struct V_65 * * V_73 ;
struct V_65 * V_74 = NULL ;
struct V_68 * V_75 ;
F_72 ( ! V_69 ) ;
V_69 -> V_60 = F_59 ( V_26 ) ;
V_64 = & V_26 -> V_72 ;
V_73 = & V_64 -> V_65 ;
while ( * V_73 ) {
V_75 = F_68 ( * V_73 , struct V_68 , V_21 ) ;
V_74 = * V_73 ;
if ( V_75 -> V_76 < V_69 -> V_76 )
V_73 = & ( ( * V_73 ) -> V_77 ) ;
else if ( V_75 -> V_76 > V_69 -> V_76 )
V_73 = & ( ( * V_73 ) -> V_78 ) ;
else if ( V_75 -> V_60 < V_69 -> V_60 )
V_73 = & ( ( * V_73 ) -> V_77 ) ;
else if ( V_75 -> V_60 > V_69 -> V_60 )
V_73 = & ( ( * V_73 ) -> V_78 ) ;
else
return - V_79 ;
}
F_73 ( & V_69 -> V_21 , V_74 , V_73 ) ;
F_74 ( & V_69 -> V_21 , V_64 ) ;
return 0 ;
}
static inline int F_75 ( struct V_54 * V_26 ,
struct V_14 * V_20 ) {
F_76 () ;
if ( F_77 ( & ( V_26 ) -> V_62 ) )
return 1 ;
if ( V_20 && F_33 ( V_20 ) == 0 )
return 1 ;
F_55 ( V_26 ) ;
if ( F_77 ( & ( V_26 ) -> V_62 ) ) {
F_57 ( V_26 ) ;
return 1 ;
}
return 0 ;
}
static inline int F_78 ( const struct V_54 * V_26 ,
struct V_14 * V_20 )
{
F_76 () ;
if ( F_77 ( & ( V_26 ) -> V_62 ) )
return 0 ;
if ( V_20 && F_33 ( V_20 ) == 0 )
return 0 ;
return 1 ;
}
static struct V_68 *
F_79 ( struct V_14 * V_20 , int V_80 ,
enum V_81 V_82 , T_3 V_83 )
{
struct V_68 * V_69 ;
V_69 = F_80 ( sizeof( * V_69 ) , V_83 ) ;
if ( ! V_69 )
return NULL ;
V_69 -> V_76 = V_20 -> V_46 >> V_84 ;
if ( V_82 != V_85 ) {
F_35 ( V_20 , & V_69 -> V_86 , V_80 ) ;
V_69 -> V_87 = F_81 ( V_20 , V_80 ) ;
}
V_69 -> V_82 = V_82 ;
V_69 -> V_80 = V_80 ;
V_69 -> V_88 = F_82 ( V_20 , V_80 ) ;
F_83 ( & V_69 -> V_21 ) ;
return V_69 ;
}
static T_1 int
F_84 ( struct V_54 * V_26 ,
struct V_14 * V_20 , int V_80 ,
enum V_81 V_82 , T_3 V_83 )
{
struct V_68 * V_69 ;
int V_38 ;
if ( ! F_78 ( V_26 , V_20 ) )
return 0 ;
V_69 = F_79 ( V_20 , V_80 , V_82 , V_83 ) ;
if ( ! V_69 )
return - V_89 ;
if ( F_75 ( V_26 , V_20 ) ) {
F_70 ( V_69 ) ;
return 0 ;
}
V_38 = F_71 ( V_26 , V_69 ) ;
F_57 ( V_26 ) ;
if ( V_38 )
F_70 ( V_69 ) ;
return V_38 ;
}
static T_1 int
F_85 ( struct V_54 * V_26 ,
struct V_14 * V_20 , int V_90 , int V_91 ,
int V_92 , T_3 V_83 )
{
struct V_68 * V_69 = NULL ;
struct V_68 * * V_93 = NULL ;
int V_38 = 0 ;
int V_6 ;
int V_94 = 0 ;
if ( ! F_78 ( V_26 , V_20 ) )
return 0 ;
V_93 = F_86 ( V_92 , sizeof( struct V_68 * ) , V_83 ) ;
if ( ! V_93 )
return - V_89 ;
V_69 = F_80 ( sizeof( * V_69 ) , V_83 ) ;
if ( ! V_69 ) {
V_38 = - V_89 ;
goto V_95;
}
V_69 -> V_76 = V_20 -> V_46 >> V_84 ;
V_69 -> V_80 = V_91 ;
V_69 -> V_96 . V_90 = V_90 ;
V_69 -> V_96 . V_92 = V_92 ;
V_69 -> V_82 = V_97 ;
for ( V_6 = 0 ; V_6 + V_90 < V_91 && V_6 < V_92 ; V_6 ++ ) {
V_93 [ V_6 ] = F_79 ( V_20 , V_6 + V_90 ,
V_98 , V_83 ) ;
if ( ! V_93 [ V_6 ] ) {
V_38 = - V_89 ;
goto V_95;
}
}
if ( F_75 ( V_26 , V_20 ) )
goto V_95;
V_94 = 1 ;
for ( V_6 = 0 ; V_6 + V_90 < V_91 && V_6 < V_92 ; V_6 ++ ) {
V_38 = F_71 ( V_26 , V_93 [ V_6 ] ) ;
if ( V_38 )
goto V_95;
}
V_38 = F_71 ( V_26 , V_69 ) ;
if ( V_38 )
goto V_95;
F_57 ( V_26 ) ;
F_70 ( V_93 ) ;
return 0 ;
V_95:
for ( V_6 = 0 ; V_6 < V_92 ; V_6 ++ ) {
if ( V_93 [ V_6 ] && ! F_87 ( & V_93 [ V_6 ] -> V_21 ) )
F_69 ( & V_93 [ V_6 ] -> V_21 , & V_26 -> V_72 ) ;
F_70 ( V_93 [ V_6 ] ) ;
}
if ( V_94 )
F_57 ( V_26 ) ;
F_70 ( V_93 ) ;
F_70 ( V_69 ) ;
return V_38 ;
}
static inline int
F_88 ( struct V_54 * V_26 ,
struct V_68 * * V_93 ,
int V_99 )
{
int V_6 , V_100 ;
int V_38 ;
for ( V_6 = V_99 - 1 ; V_6 >= 0 ; V_6 -- ) {
V_38 = F_71 ( V_26 , V_93 [ V_6 ] ) ;
if ( V_38 ) {
for ( V_100 = V_99 - 1 ; V_100 > V_6 ; V_100 -- )
F_69 ( & V_93 [ V_100 ] -> V_21 ,
& V_26 -> V_72 ) ;
return V_38 ;
}
}
return 0 ;
}
static T_1 int
F_89 ( struct V_54 * V_26 ,
struct V_14 * V_101 ,
struct V_14 * V_102 , T_3 V_83 ,
int V_103 )
{
struct V_68 * V_69 = NULL ;
struct V_68 * * V_93 = NULL ;
int V_99 = 0 ;
int V_38 = 0 ;
int V_6 ;
if ( ! F_78 ( V_26 , NULL ) )
return 0 ;
if ( V_103 && F_33 ( V_101 ) > 0 ) {
V_99 = F_90 ( V_101 ) ;
V_93 = F_86 ( V_99 , sizeof( struct V_68 * ) ,
V_83 ) ;
if ( ! V_93 ) {
V_38 = - V_89 ;
goto V_95;
}
for ( V_6 = 0 ; V_6 < V_99 ; V_6 ++ ) {
V_93 [ V_6 ] = F_79 ( V_101 , V_6 ,
V_104 , V_83 ) ;
if ( ! V_93 [ V_6 ] ) {
V_38 = - V_89 ;
goto V_95;
}
}
}
V_69 = F_80 ( sizeof( * V_69 ) , V_83 ) ;
if ( ! V_69 ) {
V_38 = - V_89 ;
goto V_95;
}
V_69 -> V_76 = V_102 -> V_46 >> V_84 ;
V_69 -> V_101 . V_105 = V_101 -> V_46 ;
V_69 -> V_101 . V_39 = F_33 ( V_101 ) ;
V_69 -> V_88 = F_48 ( V_101 ) ;
V_69 -> V_82 = V_106 ;
if ( F_75 ( V_26 , NULL ) )
goto V_95;
if ( V_93 )
V_38 = F_88 ( V_26 , V_93 , V_99 ) ;
if ( ! V_38 )
V_38 = F_71 ( V_26 , V_69 ) ;
F_57 ( V_26 ) ;
if ( V_38 )
goto V_95;
F_70 ( V_93 ) ;
return V_38 ;
V_95:
if ( V_93 ) {
for ( V_6 = 0 ; V_6 < V_99 ; V_6 ++ )
F_70 ( V_93 [ V_6 ] ) ;
F_70 ( V_93 ) ;
}
F_70 ( V_69 ) ;
return V_38 ;
}
static struct V_68 *
F_91 ( struct V_54 * V_26 , T_2 V_46 , T_2 V_70 ,
int V_107 )
{
struct V_63 * V_64 ;
struct V_65 * V_21 ;
struct V_68 * V_75 = NULL ;
struct V_68 * V_108 = NULL ;
T_2 V_76 = V_46 >> V_84 ;
F_51 ( V_26 ) ;
V_64 = & V_26 -> V_72 ;
V_21 = V_64 -> V_65 ;
while ( V_21 ) {
V_75 = F_68 ( V_21 , struct V_68 , V_21 ) ;
if ( V_75 -> V_76 < V_76 ) {
V_21 = V_21 -> V_77 ;
} else if ( V_75 -> V_76 > V_76 ) {
V_21 = V_21 -> V_78 ;
} else if ( V_75 -> V_60 < V_70 ) {
V_21 = V_21 -> V_77 ;
} else if ( ! V_107 ) {
if ( V_108 )
F_72 ( V_108 -> V_60 > V_75 -> V_60 ) ;
V_108 = V_75 ;
V_21 = V_21 -> V_77 ;
} else if ( V_75 -> V_60 > V_70 ) {
if ( V_108 )
F_72 ( V_108 -> V_60 < V_75 -> V_60 ) ;
V_108 = V_75 ;
V_21 = V_21 -> V_78 ;
} else {
V_108 = V_75 ;
break;
}
}
F_53 ( V_26 ) ;
return V_108 ;
}
static struct V_68 *
F_92 ( struct V_54 * V_26 , T_2 V_46 ,
T_2 V_70 )
{
return F_91 ( V_26 , V_46 , V_70 , 1 ) ;
}
static struct V_68 *
F_93 ( struct V_54 * V_26 , T_2 V_46 , T_2 V_70 )
{
return F_91 ( V_26 , V_46 , V_70 , 0 ) ;
}
static T_1 int
F_94 ( struct V_54 * V_26 , struct V_14 * V_109 ,
struct V_14 * V_110 , unsigned long V_111 ,
unsigned long V_112 , int V_92 )
{
int V_38 = 0 ;
struct V_68 * * V_93 = NULL ;
struct V_68 * * V_113 , * * V_114 ;
int V_6 ;
int V_94 = 0 ;
if ( ! F_78 ( V_26 , NULL ) )
return 0 ;
if ( F_33 ( V_109 ) == 0 && F_33 ( V_110 ) == 0 )
return 0 ;
V_93 = F_86 ( V_92 * 2 , sizeof( struct V_68 * ) ,
V_4 ) ;
if ( ! V_93 )
return - V_89 ;
V_113 = V_93 ;
V_114 = V_93 + V_92 ;
for ( V_6 = 0 ; V_6 < V_92 ; V_6 ++ ) {
V_114 [ V_6 ] = F_79 ( V_110 , V_6 + V_112 ,
V_115 , V_4 ) ;
if ( ! V_114 [ V_6 ] ) {
V_38 = - V_89 ;
goto V_95;
}
V_113 [ V_6 ] = F_79 ( V_109 , V_6 + V_111 ,
V_85 , V_4 ) ;
if ( ! V_113 [ V_6 ] ) {
V_38 = - V_89 ;
goto V_95;
}
}
if ( F_75 ( V_26 , NULL ) )
goto V_95;
V_94 = 1 ;
for ( V_6 = 0 ; V_6 < V_92 ; V_6 ++ ) {
V_38 = F_71 ( V_26 , V_114 [ V_6 ] ) ;
if ( V_38 )
goto V_95;
V_38 = F_71 ( V_26 , V_113 [ V_6 ] ) ;
if ( V_38 )
goto V_95;
}
F_57 ( V_26 ) ;
F_70 ( V_93 ) ;
return 0 ;
V_95:
for ( V_6 = 0 ; V_6 < V_92 * 2 ; V_6 ++ ) {
if ( V_93 [ V_6 ] && ! F_87 ( & V_93 [ V_6 ] -> V_21 ) )
F_69 ( & V_93 [ V_6 ] -> V_21 , & V_26 -> V_72 ) ;
F_70 ( V_93 [ V_6 ] ) ;
}
if ( V_94 )
F_57 ( V_26 ) ;
F_70 ( V_93 ) ;
return V_38 ;
}
static inline void
F_95 ( struct V_54 * V_26 , struct V_14 * V_109 ,
int V_111 , int V_112 , int V_92 )
{
int V_38 ;
V_38 = F_85 ( V_26 , V_109 , V_111 , V_112 ,
V_92 , V_4 ) ;
F_72 ( V_38 < 0 ) ;
}
static T_1 void
F_96 ( struct V_54 * V_26 ,
struct V_14 * V_20 , int V_80 , int V_116 )
{
int V_38 ;
V_38 = F_84 ( V_26 , V_20 , V_80 ,
V_117 ,
V_116 ? V_118 : V_4 ) ;
F_72 ( V_38 < 0 ) ;
}
static T_1 int
F_97 ( struct V_54 * V_26 , struct V_14 * V_20 )
{
struct V_68 * * V_93 = NULL ;
int V_99 = 0 ;
int V_6 ;
int V_38 = 0 ;
if ( F_33 ( V_20 ) == 0 )
return 0 ;
if ( ! F_78 ( V_26 , NULL ) )
return 0 ;
V_99 = F_90 ( V_20 ) ;
V_93 = F_86 ( V_99 , sizeof( struct V_68 * ) , V_4 ) ;
if ( ! V_93 )
return - V_89 ;
for ( V_6 = 0 ; V_6 < V_99 ; V_6 ++ ) {
V_93 [ V_6 ] = F_79 ( V_20 , V_6 ,
V_104 , V_4 ) ;
if ( ! V_93 [ V_6 ] ) {
V_38 = - V_89 ;
goto V_95;
}
}
if ( F_75 ( V_26 , V_20 ) )
goto V_95;
V_38 = F_88 ( V_26 , V_93 , V_99 ) ;
F_57 ( V_26 ) ;
if ( V_38 )
goto V_95;
F_70 ( V_93 ) ;
return 0 ;
V_95:
for ( V_6 = 0 ; V_6 < V_99 ; V_6 ++ )
F_70 ( V_93 [ V_6 ] ) ;
F_70 ( V_93 ) ;
return V_38 ;
}
static T_1 void
F_98 ( struct V_18 * V_19 ,
struct V_14 * V_119 ,
int V_103 )
{
int V_38 ;
V_38 = F_89 ( V_19 -> V_26 , V_19 -> V_21 ,
V_119 , V_4 , V_103 ) ;
F_72 ( V_38 < 0 ) ;
}
int F_99 ( struct V_18 * V_19 ,
struct V_14 * V_34 )
{
if ( F_25 ( V_42 , & V_19 -> V_24 ) &&
V_34 != V_19 -> V_21 && V_34 != V_19 -> V_120 &&
( F_48 ( V_34 ) <=
F_100 ( & V_19 -> V_121 ) ||
F_101 ( V_34 , V_50 ) ) )
return 1 ;
#ifdef F_102
if ( F_25 ( V_42 , & V_19 -> V_24 ) &&
F_103 ( V_34 ) < V_48 )
return 1 ;
#endif
return 0 ;
}
static T_1 int F_104 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_14 * V_34 ,
struct V_14 * V_37 ,
int * V_122 )
{
T_2 V_22 ;
T_2 V_123 ;
T_2 V_83 ;
T_2 V_124 = 0 ;
int V_38 ;
if ( F_99 ( V_19 , V_34 ) ) {
V_38 = F_105 ( V_33 , V_19 , V_34 -> V_46 ,
F_33 ( V_34 ) , 1 ,
& V_22 , & V_83 ) ;
if ( V_38 )
return V_38 ;
if ( V_22 == 0 ) {
V_38 = - V_125 ;
F_106 ( V_19 -> V_26 , V_38 , NULL ) ;
return V_38 ;
}
} else {
V_22 = 1 ;
if ( V_19 -> V_126 . V_28 == V_51 ||
F_103 ( V_34 ) < V_48 )
V_83 = V_127 ;
else
V_83 = 0 ;
}
V_123 = F_107 ( V_34 ) ;
F_72 ( V_123 == V_51 &&
! ( V_83 & V_127 ) ) ;
if ( V_22 > 1 ) {
if ( ( V_123 == V_19 -> V_126 . V_28 ||
V_19 -> V_126 . V_28 == V_51 ) &&
! ( V_83 & V_127 ) ) {
V_38 = F_49 ( V_33 , V_19 , V_34 , 1 ) ;
F_72 ( V_38 ) ;
if ( V_19 -> V_126 . V_28 ==
V_51 ) {
V_38 = F_108 ( V_33 , V_19 , V_34 , 0 ) ;
F_72 ( V_38 ) ;
V_38 = F_49 ( V_33 , V_19 , V_37 , 1 ) ;
F_72 ( V_38 ) ;
}
V_124 |= V_127 ;
} else {
if ( V_19 -> V_126 . V_28 ==
V_51 )
V_38 = F_49 ( V_33 , V_19 , V_37 , 1 ) ;
else
V_38 = F_49 ( V_33 , V_19 , V_37 , 0 ) ;
F_72 ( V_38 ) ;
}
if ( V_124 != 0 ) {
int V_39 = F_33 ( V_34 ) ;
V_38 = F_109 ( V_33 , V_19 ,
V_34 -> V_46 ,
V_34 -> V_47 ,
V_124 , V_39 , 0 ) ;
if ( V_38 )
return V_38 ;
}
} else {
if ( V_83 & V_127 ) {
if ( V_19 -> V_126 . V_28 ==
V_51 )
V_38 = F_49 ( V_33 , V_19 , V_37 , 1 ) ;
else
V_38 = F_49 ( V_33 , V_19 , V_37 , 0 ) ;
F_72 ( V_38 ) ;
V_38 = F_108 ( V_33 , V_19 , V_34 , 1 ) ;
F_72 ( V_38 ) ;
}
F_110 ( V_33 , V_19 -> V_26 , V_34 ) ;
* V_122 = 1 ;
}
return 0 ;
}
static T_1 int F_111 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_14 * V_34 ,
struct V_14 * V_74 , int V_128 ,
struct V_14 * * V_35 ,
T_2 V_129 , T_2 V_130 )
{
struct V_40 V_41 ;
struct V_14 * V_37 ;
int V_39 , V_38 ;
int V_122 = 0 ;
int V_131 = 0 ;
T_2 V_132 ;
if ( * V_35 == V_34 )
V_131 = 1 ;
F_112 ( V_34 ) ;
F_32 ( F_25 ( V_42 , & V_19 -> V_24 ) &&
V_33 -> V_43 != V_19 -> V_26 -> V_44 -> V_43 ) ;
F_32 ( F_25 ( V_42 , & V_19 -> V_24 ) &&
V_33 -> V_43 != V_19 -> V_45 ) ;
V_39 = F_33 ( V_34 ) ;
if ( V_39 == 0 )
F_34 ( V_34 , & V_41 , 0 ) ;
else
F_35 ( V_34 , & V_41 , 0 ) ;
if ( V_19 -> V_126 . V_28 == V_51 ) {
if ( V_74 )
V_132 = V_74 -> V_46 ;
else
V_132 = 0 ;
} else
V_132 = 0 ;
V_37 = F_36 ( V_33 , V_19 , V_132 ,
V_19 -> V_126 . V_28 , & V_41 , V_39 ,
V_129 , V_130 ) ;
if ( F_37 ( V_37 ) )
return F_38 ( V_37 ) ;
F_39 ( V_37 , V_34 , 0 , 0 , V_37 -> V_47 ) ;
F_40 ( V_37 , V_37 -> V_46 ) ;
F_41 ( V_37 , V_33 -> V_43 ) ;
F_42 ( V_37 , V_48 ) ;
F_43 ( V_37 , V_49 |
V_50 ) ;
if ( V_19 -> V_126 . V_28 == V_51 )
F_44 ( V_37 , V_50 ) ;
else
F_45 ( V_37 , V_19 -> V_126 . V_28 ) ;
F_46 ( V_37 , V_19 -> V_26 -> V_52 , F_47 () ,
V_53 ) ;
V_38 = F_104 ( V_33 , V_19 , V_34 , V_37 , & V_122 ) ;
if ( V_38 ) {
F_113 ( V_33 , V_19 , V_38 ) ;
return V_38 ;
}
if ( F_25 ( V_42 , & V_19 -> V_24 ) ) {
V_38 = F_114 ( V_33 , V_19 , V_34 , V_37 ) ;
if ( V_38 ) {
F_113 ( V_33 , V_19 , V_38 ) ;
return V_38 ;
}
}
if ( V_34 == V_19 -> V_21 ) {
F_32 ( V_74 && V_74 != V_34 ) ;
if ( V_19 -> V_126 . V_28 == V_51 ||
F_103 ( V_34 ) < V_48 )
V_132 = V_34 -> V_46 ;
else
V_132 = 0 ;
F_115 ( V_37 ) ;
F_98 ( V_19 , V_37 , 1 ) ;
F_116 ( V_19 -> V_21 , V_37 ) ;
F_117 ( V_33 , V_19 , V_34 , V_132 ,
V_122 ) ;
F_11 ( V_34 ) ;
F_24 ( V_19 ) ;
} else {
if ( V_19 -> V_126 . V_28 == V_51 )
V_132 = V_74 -> V_46 ;
else
V_132 = 0 ;
F_32 ( V_33 -> V_43 != F_48 ( V_74 ) ) ;
F_84 ( V_19 -> V_26 , V_74 , V_128 ,
V_117 , V_4 ) ;
F_118 ( V_74 , V_128 ,
V_37 -> V_46 ) ;
F_119 ( V_74 , V_128 ,
V_33 -> V_43 ) ;
F_50 ( V_74 ) ;
if ( V_122 ) {
V_38 = F_97 ( V_19 -> V_26 , V_34 ) ;
if ( V_38 ) {
F_113 ( V_33 , V_19 , V_38 ) ;
return V_38 ;
}
}
F_117 ( V_33 , V_19 , V_34 , V_132 ,
V_122 ) ;
}
if ( V_131 )
F_20 ( V_34 ) ;
F_120 ( V_34 ) ;
F_50 ( V_37 ) ;
* V_35 = V_37 ;
return 0 ;
}
static struct V_68 *
F_121 ( struct V_54 * V_26 ,
struct V_14 * V_133 , T_2 V_134 )
{
struct V_68 * V_69 ;
struct V_68 * V_108 = NULL ;
T_2 V_135 = V_133 -> V_46 ;
int V_136 = 0 ;
if ( ! V_134 )
return NULL ;
while ( 1 ) {
V_69 = F_92 ( V_26 , V_135 ,
V_134 ) ;
if ( ! V_136 && ! V_69 )
return NULL ;
if ( ! V_69 )
break;
if ( V_69 -> V_82 != V_106 )
break;
V_108 = V_69 ;
V_135 = V_69 -> V_101 . V_105 ;
V_136 = 1 ;
}
if ( ! V_108 )
V_108 = V_69 ;
return V_108 ;
}
static void
F_122 ( struct V_54 * V_26 , struct V_14 * V_20 ,
T_2 V_134 , struct V_68 * V_137 )
{
T_4 V_138 ;
struct V_65 * V_66 ;
struct V_68 * V_69 = V_137 ;
unsigned long V_139 ;
unsigned long V_140 ;
unsigned long V_141 = sizeof( struct V_142 ) ;
V_138 = F_90 ( V_20 ) ;
F_51 ( V_26 ) ;
while ( V_69 && V_69 -> V_60 >= V_134 ) {
switch ( V_69 -> V_82 ) {
case V_104 :
F_72 ( V_69 -> V_80 < V_138 ) ;
case V_98 :
case V_115 :
F_123 ( V_20 , & V_69 -> V_86 , V_69 -> V_80 ) ;
F_118 ( V_20 , V_69 -> V_80 , V_69 -> V_87 ) ;
F_119 ( V_20 , V_69 -> V_80 ,
V_69 -> V_88 ) ;
V_138 ++ ;
break;
case V_117 :
F_72 ( V_69 -> V_80 >= V_138 ) ;
F_123 ( V_20 , & V_69 -> V_86 , V_69 -> V_80 ) ;
F_118 ( V_20 , V_69 -> V_80 , V_69 -> V_87 ) ;
F_119 ( V_20 , V_69 -> V_80 ,
V_69 -> V_88 ) ;
break;
case V_85 :
V_138 -- ;
break;
case V_97 :
V_139 = F_124 ( V_69 -> V_80 ) ;
V_140 = F_124 ( V_69 -> V_96 . V_90 ) ;
F_125 ( V_20 , V_139 , V_140 ,
V_69 -> V_96 . V_92 * V_141 ) ;
break;
case V_106 :
break;
}
V_66 = F_67 ( & V_69 -> V_21 ) ;
if ( ! V_66 )
break;
V_69 = F_68 ( V_66 , struct V_68 , V_21 ) ;
if ( V_69 -> V_76 != V_137 -> V_76 )
break;
}
F_53 ( V_26 ) ;
F_126 ( V_20 , V_138 ) ;
}
static struct V_14 *
F_127 ( struct V_54 * V_26 , struct V_1 * V_2 ,
struct V_14 * V_20 , T_2 V_134 )
{
struct V_14 * V_143 ;
struct V_68 * V_69 ;
if ( ! V_134 )
return V_20 ;
if ( F_33 ( V_20 ) == 0 )
return V_20 ;
V_69 = F_93 ( V_26 , V_20 -> V_46 , V_134 ) ;
if ( ! V_69 )
return V_20 ;
F_3 ( V_2 ) ;
F_4 ( V_20 , V_10 ) ;
if ( V_69 -> V_82 == V_104 ) {
F_72 ( V_69 -> V_80 != 0 ) ;
V_143 = F_128 ( V_26 , V_20 -> V_46 ) ;
if ( ! V_143 ) {
F_129 ( V_20 ) ;
F_11 ( V_20 ) ;
return NULL ;
}
F_40 ( V_143 , V_20 -> V_46 ) ;
F_42 ( V_143 ,
F_103 ( V_20 ) ) ;
F_45 ( V_143 , F_107 ( V_20 ) ) ;
F_130 ( V_143 , F_33 ( V_20 ) ) ;
} else {
V_143 = F_131 ( V_20 ) ;
if ( ! V_143 ) {
F_129 ( V_20 ) ;
F_11 ( V_20 ) ;
return NULL ;
}
}
F_5 ( V_2 , NULL , V_10 ) ;
F_129 ( V_20 ) ;
F_11 ( V_20 ) ;
F_115 ( V_143 ) ;
F_22 ( V_143 ) ;
F_122 ( V_26 , V_143 , V_134 , V_69 ) ;
F_32 ( F_90 ( V_143 ) >
F_132 ( V_26 -> V_144 ) ) ;
return V_143 ;
}
static inline struct V_14 *
F_133 ( struct V_18 * V_19 , T_2 V_134 )
{
struct V_68 * V_69 ;
struct V_14 * V_20 = NULL ;
struct V_14 * V_133 ;
struct V_14 * V_145 ;
struct V_146 * V_101 = NULL ;
T_2 V_147 = 0 ;
T_2 V_105 ;
V_133 = F_21 ( V_19 ) ;
V_69 = F_121 ( V_19 -> V_26 , V_133 , V_134 ) ;
if ( ! V_69 )
return V_133 ;
if ( V_69 -> V_82 == V_106 ) {
V_101 = & V_69 -> V_101 ;
V_147 = V_69 -> V_88 ;
V_105 = V_101 -> V_105 ;
} else {
V_105 = V_133 -> V_46 ;
}
V_69 = F_93 ( V_19 -> V_26 , V_105 , V_134 ) ;
if ( V_101 && V_69 && V_69 -> V_82 != V_104 ) {
F_23 ( V_133 ) ;
F_11 ( V_133 ) ;
V_145 = F_134 ( V_19 , V_105 , 0 ) ;
if ( F_32 ( F_37 ( V_145 ) || ! F_135 ( V_145 ) ) ) {
if ( ! F_37 ( V_145 ) )
F_11 ( V_145 ) ;
F_136 ( V_19 -> V_26 ,
L_1 , V_105 ) ;
} else {
V_20 = F_131 ( V_145 ) ;
F_11 ( V_145 ) ;
}
} else if ( V_101 ) {
F_23 ( V_133 ) ;
F_11 ( V_133 ) ;
V_20 = F_128 ( V_19 -> V_26 , V_105 ) ;
} else {
F_4 ( V_133 , V_10 ) ;
V_20 = F_131 ( V_133 ) ;
F_129 ( V_133 ) ;
F_11 ( V_133 ) ;
}
if ( ! V_20 )
return NULL ;
F_115 ( V_20 ) ;
F_22 ( V_20 ) ;
if ( V_101 ) {
F_40 ( V_20 , V_20 -> V_46 ) ;
F_42 ( V_20 , V_48 ) ;
F_45 ( V_20 , F_107 ( V_133 ) ) ;
F_130 ( V_20 , V_101 -> V_39 ) ;
F_41 ( V_20 , V_147 ) ;
}
if ( V_69 )
F_122 ( V_19 -> V_26 , V_20 , V_134 , V_69 ) ;
else
F_32 ( F_33 ( V_20 ) != 0 ) ;
F_32 ( F_90 ( V_20 ) > F_132 ( V_19 ) ) ;
return V_20 ;
}
int F_137 ( struct V_18 * V_19 , T_2 V_134 )
{
struct V_68 * V_69 ;
int V_39 ;
struct V_14 * V_133 = F_12 ( V_19 ) ;
V_69 = F_121 ( V_19 -> V_26 , V_133 , V_134 ) ;
if ( V_69 && V_69 -> V_82 == V_106 ) {
V_39 = V_69 -> V_101 . V_39 ;
} else {
V_39 = F_33 ( V_133 ) ;
}
F_11 ( V_133 ) ;
return V_39 ;
}
static inline int F_138 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_14 * V_34 )
{
if ( F_139 ( V_19 ) )
return 0 ;
F_140 () ;
if ( F_48 ( V_34 ) == V_33 -> V_43 &&
! F_101 ( V_34 , V_49 ) &&
! ( V_19 -> V_126 . V_28 != V_51 &&
F_101 ( V_34 , V_50 ) ) &&
! F_25 ( V_148 , & V_19 -> V_24 ) )
return 0 ;
return 1 ;
}
T_1 int F_141 ( struct V_32 * V_33 ,
struct V_18 * V_19 , struct V_14 * V_34 ,
struct V_14 * V_74 , int V_128 ,
struct V_14 * * V_35 )
{
T_2 V_129 ;
int V_38 ;
if ( V_33 -> V_149 != V_19 -> V_26 -> V_44 )
F_142 ( 1 , V_150 L_2 ,
V_33 -> V_43 ,
V_19 -> V_26 -> V_44 -> V_43 ) ;
if ( V_33 -> V_43 != V_19 -> V_26 -> V_88 )
F_142 ( 1 , V_150 L_2 ,
V_33 -> V_43 , V_19 -> V_26 -> V_88 ) ;
if ( ! F_138 ( V_33 , V_19 , V_34 ) ) {
* V_35 = V_34 ;
return 0 ;
}
V_129 = V_34 -> V_46 & ~ ( ( T_2 ) ( 1024 * 1024 * 1024 ) - 1 ) ;
if ( V_74 )
F_143 ( V_74 ) ;
F_143 ( V_34 ) ;
V_38 = F_111 ( V_33 , V_19 , V_34 , V_74 ,
V_128 , V_35 , V_129 , 0 ) ;
F_144 ( V_19 , V_34 , * V_35 ) ;
return V_38 ;
}
static int F_145 ( T_2 V_151 , T_2 V_152 , T_4 V_153 )
{
if ( V_151 < V_152 && V_152 - ( V_151 + V_153 ) < 32768 )
return 1 ;
if ( V_151 > V_152 && V_151 - ( V_152 + V_153 ) < 32768 )
return 1 ;
return 0 ;
}
static int F_146 ( struct V_40 * V_154 , struct V_155 * V_156 )
{
struct V_155 V_157 ;
F_147 ( & V_157 , V_154 ) ;
return F_148 ( & V_157 , V_156 ) ;
}
int F_148 ( struct V_155 * V_157 , struct V_155 * V_156 )
{
if ( V_157 -> V_28 > V_156 -> V_28 )
return 1 ;
if ( V_157 -> V_28 < V_156 -> V_28 )
return - 1 ;
if ( V_157 -> type > V_156 -> type )
return 1 ;
if ( V_157 -> type < V_156 -> type )
return - 1 ;
if ( V_157 -> V_158 > V_156 -> V_158 )
return 1 ;
if ( V_157 -> V_158 < V_156 -> V_158 )
return - 1 ;
return 0 ;
}
int F_149 ( struct V_32 * V_33 ,
struct V_18 * V_19 , struct V_14 * V_74 ,
int V_159 , T_2 * V_160 ,
struct V_155 * V_161 )
{
struct V_14 * V_75 ;
T_2 V_151 ;
T_2 V_162 ;
T_2 V_129 = * V_160 ;
T_2 V_163 = 0 ;
T_2 V_152 ;
T_4 V_164 ;
int V_165 ;
int V_6 ;
int V_166 = 0 ;
int V_167 ;
int V_168 ;
T_4 V_153 ;
int V_169 = 0 ;
struct V_40 V_41 ;
V_167 = F_33 ( V_74 ) ;
F_32 ( V_33 -> V_149 != V_19 -> V_26 -> V_44 ) ;
F_32 ( V_33 -> V_43 != V_19 -> V_26 -> V_88 ) ;
V_164 = F_90 ( V_74 ) ;
V_153 = V_19 -> V_170 ;
V_165 = V_164 - 1 ;
if ( V_164 <= 1 )
return 0 ;
F_143 ( V_74 ) ;
for ( V_6 = V_159 ; V_6 <= V_165 ; V_6 ++ ) {
int V_171 = 1 ;
F_35 ( V_74 , & V_41 , V_6 ) ;
if ( ! V_169 && F_146 ( & V_41 , V_161 ) < 0 )
continue;
V_169 = 1 ;
V_151 = F_81 ( V_74 , V_6 ) ;
V_162 = F_82 ( V_74 , V_6 ) ;
if ( V_163 == 0 )
V_163 = V_151 ;
if ( V_6 > 0 ) {
V_152 = F_81 ( V_74 , V_6 - 1 ) ;
V_171 = F_145 ( V_151 , V_152 , V_153 ) ;
}
if ( ! V_171 && V_6 < V_165 ) {
V_152 = F_81 ( V_74 , V_6 + 1 ) ;
V_171 = F_145 ( V_151 , V_152 , V_153 ) ;
}
if ( V_171 ) {
V_163 = V_151 ;
continue;
}
V_75 = F_150 ( V_19 -> V_26 , V_151 ) ;
if ( V_75 )
V_168 = F_151 ( V_75 , V_162 , 0 ) ;
else
V_168 = 0 ;
if ( ! V_75 || ! V_168 ) {
if ( ! V_75 ) {
V_75 = F_134 ( V_19 , V_151 , V_162 ) ;
if ( F_37 ( V_75 ) ) {
return F_38 ( V_75 ) ;
} else if ( ! F_135 ( V_75 ) ) {
F_11 ( V_75 ) ;
return - V_172 ;
}
} else if ( ! V_168 ) {
V_166 = F_152 ( V_75 , V_162 ) ;
if ( V_166 ) {
F_11 ( V_75 ) ;
return V_166 ;
}
}
}
if ( V_129 == 0 )
V_129 = V_163 ;
F_19 ( V_75 ) ;
F_143 ( V_75 ) ;
V_166 = F_111 ( V_33 , V_19 , V_75 , V_74 , V_6 ,
& V_75 , V_129 ,
F_153 ( 16 * V_153 ,
( V_165 - V_6 ) * V_153 ) ) ;
if ( V_166 ) {
F_20 ( V_75 ) ;
F_11 ( V_75 ) ;
break;
}
V_129 = V_75 -> V_46 ;
V_163 = V_75 -> V_46 ;
* V_160 = V_129 ;
F_20 ( V_75 ) ;
F_11 ( V_75 ) ;
}
return V_166 ;
}
static inline unsigned int F_154 ( struct V_18 * V_19 ,
struct V_14 * V_173 )
{
T_4 V_174 = F_90 ( V_173 ) ;
if ( V_174 == 0 )
return F_155 ( V_19 ) ;
return F_156 ( V_173 , V_174 - 1 ) ;
}
static T_1 int F_157 ( struct V_14 * V_20 ,
unsigned long V_5 ,
int V_175 , struct V_155 * V_86 ,
int V_176 , int * V_80 )
{
int V_177 = 0 ;
int V_178 = V_176 ;
int V_179 ;
int V_38 ;
struct V_40 * V_180 = NULL ;
struct V_40 V_181 ;
unsigned long V_158 ;
char * V_182 = NULL ;
unsigned long V_183 = 0 ;
unsigned long V_184 = 0 ;
int V_166 ;
while ( V_177 < V_178 ) {
V_179 = ( V_177 + V_178 ) / 2 ;
V_158 = V_5 + V_179 * V_175 ;
if ( ! V_182 || V_158 < V_183 ||
( V_158 + sizeof( struct V_40 ) ) >
V_183 + V_184 ) {
V_166 = F_158 ( V_20 , V_158 ,
sizeof( struct V_40 ) ,
& V_182 , & V_183 , & V_184 ) ;
if ( ! V_166 ) {
V_180 = (struct V_40 * ) ( V_182 + V_158 -
V_183 ) ;
} else {
F_159 ( V_20 , & V_181 ,
V_158 , sizeof( V_181 ) ) ;
V_180 = & V_181 ;
}
} else {
V_180 = (struct V_40 * ) ( V_182 + V_158 -
V_183 ) ;
}
V_38 = F_146 ( V_180 , V_86 ) ;
if ( V_38 < 0 )
V_177 = V_179 + 1 ;
else if ( V_38 > 0 )
V_178 = V_179 ;
else {
* V_80 = V_179 ;
return 0 ;
}
}
* V_80 = V_177 ;
return 1 ;
}
static int F_160 ( struct V_14 * V_20 , struct V_155 * V_86 ,
int V_39 , int * V_80 )
{
if ( V_39 == 0 )
return F_157 ( V_20 ,
F_161 ( struct V_185 , V_186 ) ,
sizeof( struct V_187 ) ,
V_86 , F_90 ( V_20 ) ,
V_80 ) ;
else
return F_157 ( V_20 ,
F_161 ( struct V_188 , V_189 ) ,
sizeof( struct V_142 ) ,
V_86 , F_90 ( V_20 ) ,
V_80 ) ;
}
int F_162 ( struct V_14 * V_20 , struct V_155 * V_86 ,
int V_39 , int * V_80 )
{
return F_160 ( V_20 , V_86 , V_39 , V_80 ) ;
}
static void F_163 ( struct V_18 * V_19 , T_4 V_190 )
{
F_26 ( & V_19 -> V_191 ) ;
F_164 ( & V_19 -> V_121 ,
F_165 ( & V_19 -> V_121 ) + V_190 ) ;
F_30 ( & V_19 -> V_191 ) ;
}
static void F_166 ( struct V_18 * V_19 , T_4 V_190 )
{
F_26 ( & V_19 -> V_191 ) ;
F_164 ( & V_19 -> V_121 ,
F_165 ( & V_19 -> V_121 ) - V_190 ) ;
F_30 ( & V_19 -> V_191 ) ;
}
T_1 int F_167 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_39 )
{
struct V_14 * V_192 = NULL ;
struct V_14 * V_179 ;
struct V_14 * V_193 = NULL ;
struct V_14 * V_74 = NULL ;
int V_38 = 0 ;
int V_194 ;
int V_195 ;
int V_196 = V_2 -> V_17 [ V_39 ] ;
T_2 V_197 ;
if ( V_39 == 0 )
return 0 ;
V_179 = V_2 -> V_8 [ V_39 ] ;
F_32 ( V_2 -> V_9 [ V_39 ] != V_12 &&
V_2 -> V_9 [ V_39 ] != V_13 ) ;
F_32 ( F_48 ( V_179 ) != V_33 -> V_43 ) ;
V_197 = F_81 ( V_179 , V_196 ) ;
if ( V_39 < V_7 - 1 ) {
V_74 = V_2 -> V_8 [ V_39 + 1 ] ;
V_195 = V_2 -> V_17 [ V_39 + 1 ] ;
}
if ( ! V_74 ) {
struct V_14 * V_198 ;
if ( F_90 ( V_179 ) != 1 )
return 0 ;
V_198 = F_168 ( V_19 , V_179 , 0 ) ;
if ( ! V_198 ) {
V_38 = - V_125 ;
F_106 ( V_19 -> V_26 , V_38 , NULL ) ;
goto V_199;
}
F_19 ( V_198 ) ;
F_143 ( V_198 ) ;
V_38 = F_141 ( V_33 , V_19 , V_198 , V_179 , 0 , & V_198 ) ;
if ( V_38 ) {
F_20 ( V_198 ) ;
F_11 ( V_198 ) ;
goto V_199;
}
F_98 ( V_19 , V_198 , 1 ) ;
F_116 ( V_19 -> V_21 , V_198 ) ;
F_24 ( V_19 ) ;
F_20 ( V_198 ) ;
V_2 -> V_9 [ V_39 ] = 0 ;
V_2 -> V_8 [ V_39 ] = NULL ;
F_110 ( V_33 , V_19 -> V_26 , V_179 ) ;
F_20 ( V_179 ) ;
F_11 ( V_179 ) ;
F_166 ( V_19 , V_179 -> V_47 ) ;
F_117 ( V_33 , V_19 , V_179 , 0 , 1 ) ;
F_120 ( V_179 ) ;
return 0 ;
}
if ( F_90 ( V_179 ) >
F_132 ( V_19 ) / 4 )
return 0 ;
V_193 = F_168 ( V_19 , V_74 , V_195 - 1 ) ;
if ( V_193 ) {
F_19 ( V_193 ) ;
F_143 ( V_193 ) ;
V_194 = F_141 ( V_33 , V_19 , V_193 ,
V_74 , V_195 - 1 , & V_193 ) ;
if ( V_194 ) {
V_38 = V_194 ;
goto V_199;
}
}
V_192 = F_168 ( V_19 , V_74 , V_195 + 1 ) ;
if ( V_192 ) {
F_19 ( V_192 ) ;
F_143 ( V_192 ) ;
V_194 = F_141 ( V_33 , V_19 , V_192 ,
V_74 , V_195 + 1 , & V_192 ) ;
if ( V_194 ) {
V_38 = V_194 ;
goto V_199;
}
}
if ( V_193 ) {
V_196 += F_90 ( V_193 ) ;
V_194 = F_169 ( V_33 , V_19 , V_193 , V_179 , 1 ) ;
if ( V_194 < 0 )
V_38 = V_194 ;
}
if ( V_192 ) {
V_194 = F_169 ( V_33 , V_19 , V_179 , V_192 , 1 ) ;
if ( V_194 < 0 && V_194 != - V_200 )
V_38 = V_194 ;
if ( F_90 ( V_192 ) == 0 ) {
F_110 ( V_33 , V_19 -> V_26 , V_192 ) ;
F_20 ( V_192 ) ;
F_170 ( V_19 , V_2 , V_39 + 1 , V_195 + 1 ) ;
F_166 ( V_19 , V_192 -> V_47 ) ;
F_117 ( V_33 , V_19 , V_192 , 0 , 1 ) ;
F_120 ( V_192 ) ;
V_192 = NULL ;
} else {
struct V_40 V_201 ;
F_35 ( V_192 , & V_201 , 0 ) ;
F_96 ( V_19 -> V_26 , V_74 ,
V_195 + 1 , 0 ) ;
F_123 ( V_74 , & V_201 , V_195 + 1 ) ;
F_50 ( V_74 ) ;
}
}
if ( F_90 ( V_179 ) == 1 ) {
if ( ! V_193 ) {
V_38 = - V_125 ;
F_106 ( V_19 -> V_26 , V_38 , NULL ) ;
goto V_199;
}
V_194 = F_171 ( V_33 , V_19 , V_179 , V_193 ) ;
if ( V_194 < 0 ) {
V_38 = V_194 ;
goto V_199;
}
if ( V_194 == 1 ) {
V_194 = F_169 ( V_33 , V_19 , V_193 , V_179 , 1 ) ;
if ( V_194 < 0 )
V_38 = V_194 ;
}
F_72 ( V_194 == 1 ) ;
}
if ( F_90 ( V_179 ) == 0 ) {
F_110 ( V_33 , V_19 -> V_26 , V_179 ) ;
F_20 ( V_179 ) ;
F_170 ( V_19 , V_2 , V_39 + 1 , V_195 ) ;
F_166 ( V_19 , V_179 -> V_47 ) ;
F_117 ( V_33 , V_19 , V_179 , 0 , 1 ) ;
F_120 ( V_179 ) ;
V_179 = NULL ;
} else {
struct V_40 V_202 ;
F_35 ( V_179 , & V_202 , 0 ) ;
F_96 ( V_19 -> V_26 , V_74 ,
V_195 , 0 ) ;
F_123 ( V_74 , & V_202 , V_195 ) ;
F_50 ( V_74 ) ;
}
if ( V_193 ) {
if ( F_90 ( V_193 ) > V_196 ) {
F_115 ( V_193 ) ;
V_2 -> V_8 [ V_39 ] = V_193 ;
V_2 -> V_17 [ V_39 + 1 ] -= 1 ;
V_2 -> V_17 [ V_39 ] = V_196 ;
if ( V_179 ) {
F_20 ( V_179 ) ;
F_11 ( V_179 ) ;
}
} else {
V_196 -= F_90 ( V_193 ) ;
V_2 -> V_17 [ V_39 ] = V_196 ;
}
}
if ( V_197 !=
F_81 ( V_2 -> V_8 [ V_39 ] , V_2 -> V_17 [ V_39 ] ) )
F_172 () ;
V_199:
if ( V_192 ) {
F_20 ( V_192 ) ;
F_11 ( V_192 ) ;
}
if ( V_193 ) {
if ( V_2 -> V_8 [ V_39 ] != V_193 )
F_20 ( V_193 ) ;
F_11 ( V_193 ) ;
}
return V_38 ;
}
static T_1 int F_173 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_39 )
{
struct V_14 * V_192 = NULL ;
struct V_14 * V_179 ;
struct V_14 * V_193 = NULL ;
struct V_14 * V_74 = NULL ;
int V_38 = 0 ;
int V_194 ;
int V_195 ;
int V_196 = V_2 -> V_17 [ V_39 ] ;
if ( V_39 == 0 )
return 1 ;
V_179 = V_2 -> V_8 [ V_39 ] ;
F_32 ( F_48 ( V_179 ) != V_33 -> V_43 ) ;
if ( V_39 < V_7 - 1 ) {
V_74 = V_2 -> V_8 [ V_39 + 1 ] ;
V_195 = V_2 -> V_17 [ V_39 + 1 ] ;
}
if ( ! V_74 )
return 1 ;
V_193 = F_168 ( V_19 , V_74 , V_195 - 1 ) ;
if ( V_193 ) {
T_4 V_203 ;
F_19 ( V_193 ) ;
F_143 ( V_193 ) ;
V_203 = F_90 ( V_193 ) ;
if ( V_203 >= F_132 ( V_19 ) - 1 ) {
V_194 = 1 ;
} else {
V_38 = F_141 ( V_33 , V_19 , V_193 , V_74 ,
V_195 - 1 , & V_193 ) ;
if ( V_38 )
V_194 = 1 ;
else {
V_194 = F_169 ( V_33 , V_19 ,
V_193 , V_179 , 0 ) ;
}
}
if ( V_194 < 0 )
V_38 = V_194 ;
if ( V_194 == 0 ) {
struct V_40 V_41 ;
V_196 += V_203 ;
F_35 ( V_179 , & V_41 , 0 ) ;
F_96 ( V_19 -> V_26 , V_74 ,
V_195 , 0 ) ;
F_123 ( V_74 , & V_41 , V_195 ) ;
F_50 ( V_74 ) ;
if ( F_90 ( V_193 ) > V_196 ) {
V_2 -> V_8 [ V_39 ] = V_193 ;
V_2 -> V_17 [ V_39 + 1 ] -= 1 ;
V_2 -> V_17 [ V_39 ] = V_196 ;
F_20 ( V_179 ) ;
F_11 ( V_179 ) ;
} else {
V_196 -=
F_90 ( V_193 ) ;
V_2 -> V_17 [ V_39 ] = V_196 ;
F_20 ( V_193 ) ;
F_11 ( V_193 ) ;
}
return 0 ;
}
F_20 ( V_193 ) ;
F_11 ( V_193 ) ;
}
V_192 = F_168 ( V_19 , V_74 , V_195 + 1 ) ;
if ( V_192 ) {
T_4 V_204 ;
F_19 ( V_192 ) ;
F_143 ( V_192 ) ;
V_204 = F_90 ( V_192 ) ;
if ( V_204 >= F_132 ( V_19 ) - 1 ) {
V_194 = 1 ;
} else {
V_38 = F_141 ( V_33 , V_19 , V_192 ,
V_74 , V_195 + 1 ,
& V_192 ) ;
if ( V_38 )
V_194 = 1 ;
else {
V_194 = F_171 ( V_33 , V_19 ,
V_192 , V_179 ) ;
}
}
if ( V_194 < 0 )
V_38 = V_194 ;
if ( V_194 == 0 ) {
struct V_40 V_41 ;
F_35 ( V_192 , & V_41 , 0 ) ;
F_96 ( V_19 -> V_26 , V_74 ,
V_195 + 1 , 0 ) ;
F_123 ( V_74 , & V_41 , V_195 + 1 ) ;
F_50 ( V_74 ) ;
if ( F_90 ( V_179 ) <= V_196 ) {
V_2 -> V_8 [ V_39 ] = V_192 ;
V_2 -> V_17 [ V_39 + 1 ] += 1 ;
V_2 -> V_17 [ V_39 ] = V_196 -
F_90 ( V_179 ) ;
F_20 ( V_179 ) ;
F_11 ( V_179 ) ;
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
static void F_174 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int V_39 , int V_80 , T_2 V_28 )
{
struct V_14 * V_21 ;
struct V_40 V_41 ;
T_4 V_99 ;
T_2 V_205 ;
T_2 V_206 ;
T_2 V_207 = 0 ;
T_2 V_162 ;
int V_208 = V_2 -> V_209 ;
struct V_14 * V_20 ;
T_4 V_174 ;
T_4 V_153 ;
T_4 V_210 = 0 ;
if ( V_39 != 1 )
return;
if ( ! V_2 -> V_8 [ V_39 ] )
return;
V_21 = V_2 -> V_8 [ V_39 ] ;
V_205 = F_81 ( V_21 , V_80 ) ;
V_153 = V_19 -> V_170 ;
V_20 = F_150 ( V_19 -> V_26 , V_205 ) ;
if ( V_20 ) {
F_11 ( V_20 ) ;
return;
}
V_206 = V_205 ;
V_99 = F_90 ( V_21 ) ;
V_174 = V_80 ;
while ( 1 ) {
if ( V_208 < 0 ) {
if ( V_174 == 0 )
break;
V_174 -- ;
} else if ( V_208 > 0 ) {
V_174 ++ ;
if ( V_174 >= V_99 )
break;
}
if ( V_2 -> V_209 < 0 && V_28 ) {
F_35 ( V_21 , & V_41 , V_174 ) ;
if ( F_175 ( & V_41 ) != V_28 )
break;
}
V_205 = F_81 ( V_21 , V_174 ) ;
if ( ( V_205 <= V_206 && V_206 - V_205 <= 65536 ) ||
( V_205 > V_206 && V_205 - V_206 <= 65536 ) ) {
V_162 = F_82 ( V_21 , V_174 ) ;
F_176 ( V_19 , V_205 ) ;
V_207 += V_153 ;
}
V_210 ++ ;
if ( ( V_207 > 65536 || V_210 > 32 ) )
break;
}
}
static T_1 void F_177 ( struct V_18 * V_19 ,
struct V_1 * V_2 , int V_39 )
{
int V_80 ;
int V_99 ;
struct V_14 * V_74 ;
struct V_14 * V_20 ;
T_2 V_162 ;
T_2 V_211 = 0 ;
T_2 V_212 = 0 ;
V_74 = V_2 -> V_8 [ V_39 + 1 ] ;
if ( ! V_74 )
return;
V_99 = F_90 ( V_74 ) ;
V_80 = V_2 -> V_17 [ V_39 + 1 ] ;
if ( V_80 > 0 ) {
V_211 = F_81 ( V_74 , V_80 - 1 ) ;
V_162 = F_82 ( V_74 , V_80 - 1 ) ;
V_20 = F_150 ( V_19 -> V_26 , V_211 ) ;
if ( V_20 && F_151 ( V_20 , V_162 , 1 ) != 0 )
V_211 = 0 ;
F_11 ( V_20 ) ;
}
if ( V_80 + 1 < V_99 ) {
V_212 = F_81 ( V_74 , V_80 + 1 ) ;
V_162 = F_82 ( V_74 , V_80 + 1 ) ;
V_20 = F_150 ( V_19 -> V_26 , V_212 ) ;
if ( V_20 && F_151 ( V_20 , V_162 , 1 ) != 0 )
V_212 = 0 ;
F_11 ( V_20 ) ;
}
if ( V_211 )
F_176 ( V_19 , V_211 ) ;
if ( V_212 )
F_176 ( V_19 , V_212 ) ;
}
static T_1 void F_178 ( struct V_1 * V_2 , int V_39 ,
int V_213 , int V_214 ,
int * V_215 )
{
int V_6 ;
int V_216 = V_39 ;
int V_217 = 0 ;
struct V_14 * V_218 ;
for ( V_6 = V_39 ; V_6 < V_7 ; V_6 ++ ) {
if ( ! V_2 -> V_8 [ V_6 ] )
break;
if ( ! V_2 -> V_9 [ V_6 ] )
break;
if ( ! V_217 && V_2 -> V_17 [ V_6 ] == 0 ) {
V_216 = V_6 + 1 ;
continue;
}
if ( ! V_217 && V_2 -> V_219 ) {
T_4 V_99 ;
V_218 = V_2 -> V_8 [ V_6 ] ;
V_99 = F_90 ( V_218 ) ;
if ( V_99 < 1 || V_2 -> V_17 [ V_6 ] >= V_99 - 1 ) {
V_216 = V_6 + 1 ;
continue;
}
}
if ( V_216 < V_6 && V_6 >= V_213 )
V_217 = 1 ;
V_218 = V_2 -> V_8 [ V_6 ] ;
if ( V_6 >= V_213 && V_6 > V_216 && V_2 -> V_9 [ V_6 ] ) {
F_10 ( V_218 , V_2 -> V_9 [ V_6 ] ) ;
V_2 -> V_9 [ V_6 ] = 0 ;
if ( V_215 &&
V_6 > V_214 &&
V_6 <= * V_215 ) {
* V_215 = V_6 - 1 ;
}
}
}
}
T_1 void F_179 ( struct V_1 * V_2 , int V_39 )
{
int V_6 ;
if ( V_2 -> V_219 )
return;
for ( V_6 = V_39 ; V_6 < V_7 ; V_6 ++ ) {
if ( ! V_2 -> V_8 [ V_6 ] )
continue;
if ( ! V_2 -> V_9 [ V_6 ] )
continue;
F_10 ( V_2 -> V_8 [ V_6 ] , V_2 -> V_9 [ V_6 ] ) ;
V_2 -> V_9 [ V_6 ] = 0 ;
}
}
static int
F_180 ( struct V_32 * V_33 ,
struct V_18 * V_19 , struct V_1 * V_5 ,
struct V_14 * * V_220 , int V_39 , int V_80 ,
struct V_155 * V_86 , T_2 V_134 )
{
T_2 V_151 ;
T_2 V_162 ;
struct V_14 * V_221 = * V_220 ;
struct V_14 * V_180 ;
int V_38 ;
V_151 = F_81 ( V_221 , V_80 ) ;
V_162 = F_82 ( V_221 , V_80 ) ;
V_180 = F_150 ( V_19 -> V_26 , V_151 ) ;
if ( V_180 ) {
if ( F_151 ( V_180 , V_162 , 1 ) > 0 ) {
* V_220 = V_180 ;
return 0 ;
}
F_3 ( V_5 ) ;
V_38 = F_152 ( V_180 , V_162 ) ;
if ( ! V_38 ) {
* V_220 = V_180 ;
return 0 ;
}
F_11 ( V_180 ) ;
F_8 ( V_5 ) ;
return - V_172 ;
}
F_179 ( V_5 , V_39 + 1 ) ;
F_3 ( V_5 ) ;
F_11 ( V_180 ) ;
if ( V_5 -> V_209 )
F_174 ( V_19 , V_5 , V_39 , V_80 , V_86 -> V_28 ) ;
F_8 ( V_5 ) ;
V_38 = - V_222 ;
V_180 = F_134 ( V_19 , V_151 , 0 ) ;
if ( ! F_37 ( V_180 ) ) {
if ( ! F_151 ( V_180 , 0 , 0 ) )
V_38 = - V_172 ;
F_11 ( V_180 ) ;
}
return V_38 ;
}
static int
F_181 ( struct V_32 * V_33 ,
struct V_18 * V_19 , struct V_1 * V_5 ,
struct V_14 * V_221 , int V_39 , int V_223 ,
int * V_215 )
{
int V_38 ;
if ( ( V_5 -> V_224 || V_223 > 0 ) && F_90 ( V_221 ) >=
F_132 ( V_19 ) - 3 ) {
int V_225 ;
if ( * V_215 < V_39 + 1 ) {
* V_215 = V_39 + 1 ;
F_8 ( V_5 ) ;
goto V_226;
}
F_3 ( V_5 ) ;
F_177 ( V_19 , V_5 , V_39 ) ;
V_225 = F_182 ( V_33 , V_19 , V_5 , V_39 ) ;
F_5 ( V_5 , NULL , 0 ) ;
F_72 ( V_225 > 0 ) ;
if ( V_225 ) {
V_38 = V_225 ;
goto V_227;
}
V_221 = V_5 -> V_8 [ V_39 ] ;
} else if ( V_223 < 0 && F_90 ( V_221 ) <
F_132 ( V_19 ) / 2 ) {
int V_225 ;
if ( * V_215 < V_39 + 1 ) {
* V_215 = V_39 + 1 ;
F_8 ( V_5 ) ;
goto V_226;
}
F_3 ( V_5 ) ;
F_177 ( V_19 , V_5 , V_39 ) ;
V_225 = F_167 ( V_33 , V_19 , V_5 , V_39 ) ;
F_5 ( V_5 , NULL , 0 ) ;
if ( V_225 ) {
V_38 = V_225 ;
goto V_227;
}
V_221 = V_5 -> V_8 [ V_39 ] ;
if ( ! V_221 ) {
F_8 ( V_5 ) ;
goto V_226;
}
F_72 ( F_90 ( V_221 ) == 1 ) ;
}
return 0 ;
V_226:
V_38 = - V_222 ;
V_227:
return V_38 ;
}
static void F_183 ( struct V_14 * V_221 ,
struct V_155 * V_86 ,
int V_39 )
{
#ifdef F_184
struct V_40 V_41 ;
F_185 ( & V_41 , V_86 ) ;
if ( V_39 == 0 )
ASSERT ( ! F_186 ( V_221 , & V_41 ,
F_161 ( struct V_185 , V_186 [ 0 ] . V_86 ) ,
sizeof( V_41 ) ) ) ;
else
ASSERT ( ! F_186 ( V_221 , & V_41 ,
F_161 ( struct V_188 , V_189 [ 0 ] . V_86 ) ,
sizeof( V_41 ) ) ) ;
#endif
}
static int F_187 ( struct V_14 * V_221 , struct V_155 * V_86 ,
int V_39 , int * V_228 , int * V_80 )
{
if ( * V_228 != 0 ) {
* V_228 = F_160 ( V_221 , V_86 , V_39 , V_80 ) ;
return * V_228 ;
}
F_183 ( V_221 , V_86 , V_39 ) ;
* V_80 = 0 ;
return 0 ;
}
int F_188 ( struct V_18 * V_229 , struct V_1 * V_2 ,
T_2 V_230 , T_2 V_231 , T_5 V_232 ,
struct V_155 * V_233 )
{
int V_38 ;
struct V_155 V_86 ;
struct V_14 * V_20 ;
ASSERT ( V_2 ) ;
ASSERT ( V_233 ) ;
V_86 . type = V_232 ;
V_86 . V_28 = V_230 ;
V_86 . V_158 = V_231 ;
V_38 = F_189 ( NULL , V_229 , & V_86 , V_2 , 0 , 0 ) ;
if ( V_38 < 0 )
return V_38 ;
V_20 = V_2 -> V_8 [ 0 ] ;
if ( V_38 && V_2 -> V_17 [ 0 ] >= F_90 ( V_20 ) ) {
V_38 = F_190 ( V_229 , V_2 ) ;
if ( V_38 )
return V_38 ;
V_20 = V_2 -> V_8 [ 0 ] ;
}
F_191 ( V_20 , V_233 , V_2 -> V_17 [ 0 ] ) ;
if ( V_233 -> type != V_86 . type ||
V_233 -> V_28 != V_86 . V_28 )
return 1 ;
return 0 ;
}
int F_189 ( struct V_32 * V_33 , struct V_18
* V_19 , struct V_155 * V_86 , struct V_1 * V_5 , int
V_223 , int V_37 )
{
struct V_14 * V_221 ;
int V_80 ;
int V_38 ;
int V_166 ;
int V_39 ;
int V_213 = 1 ;
int V_234 ;
int V_215 = 0 ;
T_5 V_235 = 0 ;
int V_214 ;
int V_228 ;
V_235 = V_5 -> V_235 ;
F_32 ( V_235 && V_223 > 0 ) ;
F_32 ( V_5 -> V_8 [ 0 ] != NULL ) ;
F_72 ( ! V_37 && V_223 ) ;
if ( V_223 < 0 ) {
V_213 = 2 ;
V_215 = 2 ;
} else if ( V_223 > 0 ) {
V_215 = 1 ;
}
if ( ! V_37 )
V_215 = - 1 ;
if ( V_37 && ( V_5 -> V_219 || V_5 -> V_235 ) )
V_215 = V_7 ;
V_214 = V_215 ;
V_226:
V_228 = - 1 ;
V_234 = V_10 ;
V_39 = 0 ;
if ( V_5 -> V_236 ) {
if ( V_5 -> V_237 )
F_192 ( & V_19 -> V_26 -> V_238 ) ;
V_221 = V_19 -> V_120 ;
F_115 ( V_221 ) ;
V_39 = F_33 ( V_221 ) ;
if ( V_5 -> V_237 )
F_193 ( & V_19 -> V_26 -> V_238 ) ;
if ( ! V_5 -> V_239 )
F_22 ( V_221 ) ;
} else {
if ( V_5 -> V_239 ) {
V_221 = F_12 ( V_19 ) ;
V_39 = F_33 ( V_221 ) ;
} else {
V_221 = F_21 ( V_19 ) ;
V_39 = F_33 ( V_221 ) ;
if ( V_39 <= V_215 ) {
F_23 ( V_221 ) ;
F_11 ( V_221 ) ;
V_221 = F_18 ( V_19 ) ;
V_234 = V_12 ;
V_39 = F_33 ( V_221 ) ;
}
}
}
V_5 -> V_8 [ V_39 ] = V_221 ;
if ( ! V_5 -> V_239 )
V_5 -> V_9 [ V_39 ] = V_234 ;
while ( V_221 ) {
V_39 = F_33 ( V_221 ) ;
if ( V_37 ) {
if ( ! F_138 ( V_33 , V_19 , V_221 ) )
goto V_240;
if ( V_39 > V_215 ||
( V_39 + 1 > V_215 &&
V_39 + 1 < V_7 &&
V_5 -> V_8 [ V_39 + 1 ] ) ) {
V_215 = V_39 + 1 ;
F_8 ( V_5 ) ;
goto V_226;
}
F_3 ( V_5 ) ;
V_166 = F_141 ( V_33 , V_19 , V_221 ,
V_5 -> V_8 [ V_39 + 1 ] ,
V_5 -> V_17 [ V_39 + 1 ] , & V_221 ) ;
if ( V_166 ) {
V_38 = V_166 ;
goto V_227;
}
}
V_240:
V_5 -> V_8 [ V_39 ] = V_221 ;
F_5 ( V_5 , NULL , 0 ) ;
if ( ! V_223 && ! V_5 -> V_219 ) {
int V_241 = V_39 + 1 ;
if ( V_241 < V_7 && V_5 -> V_9 [ V_241 ] ) {
F_10 ( V_5 -> V_8 [ V_241 ] , V_5 -> V_9 [ V_241 ] ) ;
V_5 -> V_9 [ V_241 ] = 0 ;
}
}
V_38 = F_187 ( V_221 , V_86 , V_39 , & V_228 , & V_80 ) ;
if ( V_39 != 0 ) {
int V_242 = 0 ;
if ( V_38 && V_80 > 0 ) {
V_242 = 1 ;
V_80 -= 1 ;
}
V_5 -> V_17 [ V_39 ] = V_80 ;
V_166 = F_181 ( V_33 , V_19 , V_5 , V_221 , V_39 ,
V_223 , & V_215 ) ;
if ( V_166 == - V_222 )
goto V_226;
if ( V_166 ) {
V_38 = V_166 ;
goto V_227;
}
V_221 = V_5 -> V_8 [ V_39 ] ;
V_80 = V_5 -> V_17 [ V_39 ] ;
if ( V_80 == 0 && V_223 &&
V_215 < V_39 + 1 ) {
V_215 = V_39 + 1 ;
F_8 ( V_5 ) ;
goto V_226;
}
F_178 ( V_5 , V_39 , V_213 ,
V_214 , & V_215 ) ;
if ( V_39 == V_235 ) {
if ( V_242 )
V_5 -> V_17 [ V_39 ] ++ ;
goto V_227;
}
V_166 = F_180 ( V_33 , V_19 , V_5 ,
& V_221 , V_39 , V_80 , V_86 , 0 ) ;
if ( V_166 == - V_222 )
goto V_226;
if ( V_166 ) {
V_38 = V_166 ;
goto V_227;
}
if ( ! V_5 -> V_239 ) {
V_39 = F_33 ( V_221 ) ;
if ( V_39 <= V_215 ) {
V_166 = F_194 ( V_221 ) ;
if ( ! V_166 ) {
F_3 ( V_5 ) ;
F_19 ( V_221 ) ;
F_5 ( V_5 , V_221 ,
V_12 ) ;
}
V_5 -> V_9 [ V_39 ] = V_12 ;
} else {
V_166 = F_195 ( V_221 ) ;
if ( ! V_166 ) {
F_3 ( V_5 ) ;
F_22 ( V_221 ) ;
F_5 ( V_5 , V_221 ,
V_10 ) ;
}
V_5 -> V_9 [ V_39 ] = V_10 ;
}
V_5 -> V_8 [ V_39 ] = V_221 ;
}
} else {
V_5 -> V_17 [ V_39 ] = V_80 ;
if ( V_223 > 0 &&
F_196 ( V_19 , V_221 ) < V_223 ) {
if ( V_215 < 1 ) {
V_215 = 1 ;
F_8 ( V_5 ) ;
goto V_226;
}
F_3 ( V_5 ) ;
V_166 = F_197 ( V_33 , V_19 , V_86 ,
V_5 , V_223 , V_38 == 0 ) ;
F_5 ( V_5 , NULL , 0 ) ;
F_72 ( V_166 > 0 ) ;
if ( V_166 ) {
V_38 = V_166 ;
goto V_227;
}
}
if ( ! V_5 -> V_224 )
F_178 ( V_5 , V_39 , V_213 ,
V_214 , & V_215 ) ;
goto V_227;
}
}
V_38 = 1 ;
V_227:
if ( ! V_5 -> V_243 )
F_3 ( V_5 ) ;
if ( V_38 < 0 && ! V_5 -> V_244 )
F_8 ( V_5 ) ;
return V_38 ;
}
int F_198 ( struct V_18 * V_19 , struct V_155 * V_86 ,
struct V_1 * V_5 , T_2 V_134 )
{
struct V_14 * V_221 ;
int V_80 ;
int V_38 ;
int V_166 ;
int V_39 ;
int V_213 = 1 ;
T_5 V_235 = 0 ;
int V_228 = - 1 ;
V_235 = V_5 -> V_235 ;
F_32 ( V_5 -> V_8 [ 0 ] != NULL ) ;
if ( V_5 -> V_236 ) {
F_72 ( V_134 ) ;
return F_189 ( NULL , V_19 , V_86 , V_5 , 0 , 0 ) ;
}
V_226:
V_221 = F_133 ( V_19 , V_134 ) ;
V_39 = F_33 ( V_221 ) ;
V_5 -> V_9 [ V_39 ] = V_10 ;
while ( V_221 ) {
V_39 = F_33 ( V_221 ) ;
V_5 -> V_8 [ V_39 ] = V_221 ;
F_5 ( V_5 , NULL , 0 ) ;
F_179 ( V_5 , V_39 + 1 ) ;
V_228 = - 1 ;
V_38 = F_187 ( V_221 , V_86 , V_39 , & V_228 , & V_80 ) ;
if ( V_39 != 0 ) {
int V_242 = 0 ;
if ( V_38 && V_80 > 0 ) {
V_242 = 1 ;
V_80 -= 1 ;
}
V_5 -> V_17 [ V_39 ] = V_80 ;
F_178 ( V_5 , V_39 , V_213 , 0 , NULL ) ;
if ( V_39 == V_235 ) {
if ( V_242 )
V_5 -> V_17 [ V_39 ] ++ ;
goto V_227;
}
V_166 = F_180 ( NULL , V_19 , V_5 , & V_221 , V_39 ,
V_80 , V_86 , V_134 ) ;
if ( V_166 == - V_222 )
goto V_226;
if ( V_166 ) {
V_38 = V_166 ;
goto V_227;
}
V_39 = F_33 ( V_221 ) ;
V_166 = F_195 ( V_221 ) ;
if ( ! V_166 ) {
F_3 ( V_5 ) ;
F_22 ( V_221 ) ;
F_5 ( V_5 , V_221 ,
V_10 ) ;
}
V_221 = F_127 ( V_19 -> V_26 , V_5 , V_221 , V_134 ) ;
if ( ! V_221 ) {
V_38 = - V_89 ;
goto V_227;
}
V_5 -> V_9 [ V_39 ] = V_10 ;
V_5 -> V_8 [ V_39 ] = V_221 ;
} else {
V_5 -> V_17 [ V_39 ] = V_80 ;
F_178 ( V_5 , V_39 , V_213 , 0 , NULL ) ;
goto V_227;
}
}
V_38 = 1 ;
V_227:
if ( ! V_5 -> V_243 )
F_3 ( V_5 ) ;
if ( V_38 < 0 )
F_8 ( V_5 ) ;
return V_38 ;
}
int F_199 ( struct V_18 * V_19 ,
struct V_155 * V_86 , struct V_1 * V_5 ,
int V_245 , int V_246 )
{
int V_38 ;
struct V_14 * V_173 ;
V_226:
V_38 = F_189 ( NULL , V_19 , V_86 , V_5 , 0 , 0 ) ;
if ( V_38 <= 0 )
return V_38 ;
V_173 = V_5 -> V_8 [ 0 ] ;
if ( V_245 ) {
if ( V_5 -> V_17 [ 0 ] >= F_90 ( V_173 ) ) {
V_38 = F_190 ( V_19 , V_5 ) ;
if ( V_38 <= 0 )
return V_38 ;
if ( ! V_246 )
return 1 ;
V_246 = 0 ;
V_245 = 0 ;
F_8 ( V_5 ) ;
goto V_226;
}
} else {
if ( V_5 -> V_17 [ 0 ] == 0 ) {
V_38 = F_200 ( V_19 , V_5 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( ! V_38 ) {
V_173 = V_5 -> V_8 [ 0 ] ;
if ( V_5 -> V_17 [ 0 ] == F_90 ( V_173 ) )
V_5 -> V_17 [ 0 ] -- ;
return 0 ;
}
if ( ! V_246 )
return 1 ;
V_246 = 0 ;
V_245 = 1 ;
F_8 ( V_5 ) ;
goto V_226;
} else {
-- V_5 -> V_17 [ 0 ] ;
}
}
return 0 ;
}
static void F_201 ( struct V_54 * V_26 ,
struct V_1 * V_2 ,
struct V_40 * V_86 , int V_39 )
{
int V_6 ;
struct V_14 * V_218 ;
for ( V_6 = V_39 ; V_6 < V_7 ; V_6 ++ ) {
int V_247 = V_2 -> V_17 [ V_6 ] ;
if ( ! V_2 -> V_8 [ V_6 ] )
break;
V_218 = V_2 -> V_8 [ V_6 ] ;
F_96 ( V_26 , V_218 , V_247 , 1 ) ;
F_123 ( V_218 , V_86 , V_247 ) ;
F_50 ( V_2 -> V_8 [ V_6 ] ) ;
if ( V_247 != 0 )
break;
}
}
void F_202 ( struct V_54 * V_26 ,
struct V_1 * V_2 ,
struct V_155 * V_248 )
{
struct V_40 V_41 ;
struct V_14 * V_20 ;
int V_80 ;
V_20 = V_2 -> V_8 [ 0 ] ;
V_80 = V_2 -> V_17 [ 0 ] ;
if ( V_80 > 0 ) {
F_34 ( V_20 , & V_41 , V_80 - 1 ) ;
F_72 ( F_146 ( & V_41 , V_248 ) >= 0 ) ;
}
if ( V_80 < F_90 ( V_20 ) - 1 ) {
F_34 ( V_20 , & V_41 , V_80 + 1 ) ;
F_72 ( F_146 ( & V_41 , V_248 ) <= 0 ) ;
}
F_185 ( & V_41 , V_248 ) ;
F_203 ( V_20 , & V_41 , V_80 ) ;
F_50 ( V_20 ) ;
if ( V_80 == 0 )
F_201 ( V_26 , V_2 , & V_41 , 1 ) ;
}
static int F_169 ( struct V_32 * V_33 ,
struct V_18 * V_19 , struct V_14 * V_109 ,
struct V_14 * V_110 , int V_249 )
{
int V_250 = 0 ;
int V_251 ;
int V_252 ;
int V_38 = 0 ;
V_251 = F_90 ( V_110 ) ;
V_252 = F_90 ( V_109 ) ;
V_250 = F_132 ( V_19 ) - V_252 ;
F_32 ( F_48 ( V_110 ) != V_33 -> V_43 ) ;
F_32 ( F_48 ( V_109 ) != V_33 -> V_43 ) ;
if ( ! V_249 && V_251 <= 8 )
return 1 ;
if ( V_250 <= 0 )
return 1 ;
if ( V_249 ) {
V_250 = F_153 ( V_251 , V_250 ) ;
if ( V_250 < V_251 ) {
if ( V_251 - V_250 < 8 ) {
if ( V_250 <= 8 )
return 1 ;
V_250 -= 8 ;
}
}
} else
V_250 = F_153 ( V_251 - 8 , V_250 ) ;
V_38 = F_94 ( V_19 -> V_26 , V_109 , V_110 , V_252 , 0 ,
V_250 ) ;
if ( V_38 ) {
F_113 ( V_33 , V_19 , V_38 ) ;
return V_38 ;
}
F_39 ( V_109 , V_110 ,
F_124 ( V_252 ) ,
F_124 ( 0 ) ,
V_250 * sizeof( struct V_142 ) ) ;
if ( V_250 < V_251 ) {
F_125 ( V_110 , F_124 ( 0 ) ,
F_124 ( V_250 ) ,
( V_251 - V_250 ) *
sizeof( struct V_142 ) ) ;
}
F_126 ( V_110 , V_251 - V_250 ) ;
F_126 ( V_109 , V_252 + V_250 ) ;
F_50 ( V_110 ) ;
F_50 ( V_109 ) ;
return V_38 ;
}
static int F_171 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_14 * V_109 ,
struct V_14 * V_110 )
{
int V_250 = 0 ;
int V_253 ;
int V_251 ;
int V_252 ;
int V_38 = 0 ;
F_32 ( F_48 ( V_110 ) != V_33 -> V_43 ) ;
F_32 ( F_48 ( V_109 ) != V_33 -> V_43 ) ;
V_251 = F_90 ( V_110 ) ;
V_252 = F_90 ( V_109 ) ;
V_250 = F_132 ( V_19 ) - V_252 ;
if ( V_250 <= 0 )
return 1 ;
if ( V_251 < 4 )
return 1 ;
V_253 = V_251 / 2 + 1 ;
if ( V_253 >= V_251 )
return 1 ;
if ( V_253 < V_250 )
V_250 = V_253 ;
F_95 ( V_19 -> V_26 , V_109 , V_250 , 0 , V_252 ) ;
F_125 ( V_109 , F_124 ( V_250 ) ,
F_124 ( 0 ) ,
( V_252 ) *
sizeof( struct V_142 ) ) ;
V_38 = F_94 ( V_19 -> V_26 , V_109 , V_110 , 0 ,
V_251 - V_250 , V_250 ) ;
if ( V_38 ) {
F_113 ( V_33 , V_19 , V_38 ) ;
return V_38 ;
}
F_39 ( V_109 , V_110 ,
F_124 ( 0 ) ,
F_124 ( V_251 - V_250 ) ,
V_250 * sizeof( struct V_142 ) ) ;
F_126 ( V_110 , V_251 - V_250 ) ;
F_126 ( V_109 , V_252 + V_250 ) ;
F_50 ( V_110 ) ;
F_50 ( V_109 ) ;
return V_38 ;
}
static T_1 int F_204 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_39 )
{
T_2 V_254 ;
struct V_14 * V_255 ;
struct V_14 * V_256 ;
struct V_14 * V_145 ;
struct V_40 V_257 ;
F_72 ( V_2 -> V_8 [ V_39 ] ) ;
F_72 ( V_2 -> V_8 [ V_39 - 1 ] != V_19 -> V_21 ) ;
V_255 = V_2 -> V_8 [ V_39 - 1 ] ;
if ( V_39 == 1 )
F_34 ( V_255 , & V_257 , 0 ) ;
else
F_35 ( V_255 , & V_257 , 0 ) ;
V_256 = F_36 ( V_33 , V_19 , 0 , V_19 -> V_126 . V_28 ,
& V_257 , V_39 , V_19 -> V_21 -> V_46 , 0 ) ;
if ( F_37 ( V_256 ) )
return F_38 ( V_256 ) ;
F_163 ( V_19 , V_19 -> V_170 ) ;
F_205 ( V_256 , 0 , 0 , sizeof( struct V_258 ) ) ;
F_126 ( V_256 , 1 ) ;
F_130 ( V_256 , V_39 ) ;
F_40 ( V_256 , V_256 -> V_46 ) ;
F_41 ( V_256 , V_33 -> V_43 ) ;
F_42 ( V_256 , V_48 ) ;
F_45 ( V_256 , V_19 -> V_126 . V_28 ) ;
F_46 ( V_256 , V_19 -> V_26 -> V_52 , F_47 () ,
V_53 ) ;
F_46 ( V_256 , V_19 -> V_26 -> V_259 ,
F_206 ( V_256 ) , V_260 ) ;
F_123 ( V_256 , & V_257 , 0 ) ;
F_118 ( V_256 , 0 , V_255 -> V_46 ) ;
V_254 = F_48 ( V_255 ) ;
F_32 ( V_254 != V_33 -> V_43 ) ;
F_119 ( V_256 , 0 , V_254 ) ;
F_50 ( V_256 ) ;
V_145 = V_19 -> V_21 ;
F_98 ( V_19 , V_256 , 0 ) ;
F_116 ( V_19 -> V_21 , V_256 ) ;
F_11 ( V_145 ) ;
F_24 ( V_19 ) ;
F_115 ( V_256 ) ;
V_2 -> V_8 [ V_39 ] = V_256 ;
V_2 -> V_9 [ V_39 ] = V_13 ;
V_2 -> V_17 [ V_39 ] = 0 ;
return 0 ;
}
static void F_207 ( struct V_32 * V_33 ,
struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_40 * V_86 , T_2 V_261 ,
int V_80 , int V_39 )
{
struct V_14 * V_255 ;
int V_99 ;
int V_38 ;
F_72 ( ! V_2 -> V_8 [ V_39 ] ) ;
F_112 ( V_2 -> V_8 [ V_39 ] ) ;
V_255 = V_2 -> V_8 [ V_39 ] ;
V_99 = F_90 ( V_255 ) ;
F_72 ( V_80 > V_99 ) ;
F_72 ( V_99 == F_132 ( V_19 ) ) ;
if ( V_80 != V_99 ) {
if ( V_39 )
F_95 ( V_19 -> V_26 , V_255 , V_80 + 1 ,
V_80 , V_99 - V_80 ) ;
F_125 ( V_255 ,
F_124 ( V_80 + 1 ) ,
F_124 ( V_80 ) ,
( V_99 - V_80 ) * sizeof( struct V_142 ) ) ;
}
if ( V_39 ) {
V_38 = F_84 ( V_19 -> V_26 , V_255 , V_80 ,
V_85 , V_4 ) ;
F_72 ( V_38 < 0 ) ;
}
F_123 ( V_255 , V_86 , V_80 ) ;
F_118 ( V_255 , V_80 , V_261 ) ;
F_32 ( V_33 -> V_43 == 0 ) ;
F_119 ( V_255 , V_80 , V_33 -> V_43 ) ;
F_126 ( V_255 , V_99 + 1 ) ;
F_50 ( V_255 ) ;
}
static T_1 int F_182 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_39 )
{
struct V_14 * V_256 ;
struct V_14 * V_262 ;
struct V_40 V_41 ;
int V_179 ;
int V_38 ;
T_4 V_263 ;
V_256 = V_2 -> V_8 [ V_39 ] ;
F_32 ( F_48 ( V_256 ) != V_33 -> V_43 ) ;
if ( V_256 == V_19 -> V_21 ) {
V_38 = F_204 ( V_33 , V_19 , V_2 , V_39 + 1 ) ;
if ( V_38 )
return V_38 ;
} else {
V_38 = F_173 ( V_33 , V_19 , V_2 , V_39 ) ;
V_256 = V_2 -> V_8 [ V_39 ] ;
if ( ! V_38 && F_90 ( V_256 ) <
F_132 ( V_19 ) - 3 )
return 0 ;
if ( V_38 < 0 )
return V_38 ;
}
V_263 = F_90 ( V_256 ) ;
V_179 = ( V_263 + 1 ) / 2 ;
F_35 ( V_256 , & V_41 , V_179 ) ;
V_262 = F_36 ( V_33 , V_19 , 0 , V_19 -> V_126 . V_28 ,
& V_41 , V_39 , V_256 -> V_46 , 0 ) ;
if ( F_37 ( V_262 ) )
return F_38 ( V_262 ) ;
F_163 ( V_19 , V_19 -> V_170 ) ;
F_205 ( V_262 , 0 , 0 , sizeof( struct V_258 ) ) ;
F_130 ( V_262 , F_33 ( V_256 ) ) ;
F_40 ( V_262 , V_262 -> V_46 ) ;
F_41 ( V_262 , V_33 -> V_43 ) ;
F_42 ( V_262 , V_48 ) ;
F_45 ( V_262 , V_19 -> V_126 . V_28 ) ;
F_46 ( V_262 , V_19 -> V_26 -> V_52 ,
F_47 () , V_53 ) ;
F_46 ( V_262 , V_19 -> V_26 -> V_259 ,
F_206 ( V_262 ) ,
V_260 ) ;
V_38 = F_94 ( V_19 -> V_26 , V_262 , V_256 , 0 ,
V_179 , V_263 - V_179 ) ;
if ( V_38 ) {
F_113 ( V_33 , V_19 , V_38 ) ;
return V_38 ;
}
F_39 ( V_262 , V_256 ,
F_124 ( 0 ) ,
F_124 ( V_179 ) ,
( V_263 - V_179 ) * sizeof( struct V_142 ) ) ;
F_126 ( V_262 , V_263 - V_179 ) ;
F_126 ( V_256 , V_179 ) ;
V_38 = 0 ;
F_50 ( V_256 ) ;
F_50 ( V_262 ) ;
F_207 ( V_33 , V_19 , V_2 , & V_41 , V_262 -> V_46 ,
V_2 -> V_17 [ V_39 + 1 ] + 1 , V_39 + 1 ) ;
if ( V_2 -> V_17 [ V_39 ] >= V_179 ) {
V_2 -> V_17 [ V_39 ] -= V_179 ;
F_20 ( V_256 ) ;
F_11 ( V_256 ) ;
V_2 -> V_8 [ V_39 ] = V_262 ;
V_2 -> V_17 [ V_39 + 1 ] += 1 ;
} else {
F_20 ( V_262 ) ;
F_11 ( V_262 ) ;
}
return V_38 ;
}
static int F_208 ( struct V_14 * V_264 , int V_46 , int V_174 )
{
struct V_187 * V_265 ;
struct V_187 * V_266 ;
struct V_267 V_268 ;
int V_269 ;
int V_99 = F_90 ( V_264 ) ;
int V_270 = F_153 ( V_99 , V_46 + V_174 ) - 1 ;
if ( ! V_174 )
return 0 ;
F_209 ( & V_268 ) ;
V_265 = F_210 ( V_46 ) ;
V_266 = F_210 ( V_270 ) ;
V_269 = F_211 ( V_264 , V_265 , & V_268 ) +
F_212 ( V_264 , V_265 , & V_268 ) ;
V_269 = V_269 - F_211 ( V_264 , V_266 , & V_268 ) ;
V_269 += sizeof( struct V_187 ) * V_174 ;
F_32 ( V_269 < 0 ) ;
return V_269 ;
}
T_1 int F_196 ( struct V_18 * V_19 ,
struct V_14 * V_173 )
{
int V_99 = F_90 ( V_173 ) ;
int V_38 ;
V_38 = F_155 ( V_19 ) - F_208 ( V_173 , 0 , V_99 ) ;
if ( V_38 < 0 ) {
F_213 ( V_19 -> V_26 ,
L_3 ,
V_38 , ( unsigned long ) F_155 ( V_19 ) ,
F_208 ( V_173 , 0 , V_99 ) , V_99 ) ;
}
return V_38 ;
}
static T_1 int F_214 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
int V_271 , int V_249 ,
struct V_14 * V_192 ,
int V_272 , T_4 V_273 ,
T_4 V_274 )
{
struct V_14 * V_193 = V_2 -> V_8 [ 0 ] ;
struct V_14 * V_275 = V_2 -> V_8 [ 1 ] ;
struct V_267 V_268 ;
struct V_40 V_41 ;
int V_80 ;
T_4 V_6 ;
int V_276 = 0 ;
int V_250 = 0 ;
struct V_187 * V_277 ;
T_4 V_174 ;
T_4 V_278 ;
T_4 V_279 ;
T_4 V_280 ;
F_209 ( & V_268 ) ;
if ( V_249 )
V_174 = 0 ;
else
V_174 = F_215 ( T_4 , 1 , V_274 ) ;
if ( V_2 -> V_17 [ 0 ] >= V_273 )
V_276 += V_271 ;
V_80 = V_2 -> V_17 [ 1 ] ;
V_6 = V_273 - 1 ;
while ( V_6 >= V_174 ) {
V_277 = F_210 ( V_6 ) ;
if ( ! V_249 && V_250 > 0 ) {
if ( V_2 -> V_17 [ 0 ] > V_6 )
break;
if ( V_2 -> V_17 [ 0 ] == V_6 ) {
int V_281 = F_196 ( V_19 , V_193 ) ;
if ( V_281 + V_276 * 2 > V_272 )
break;
}
}
if ( V_2 -> V_17 [ 0 ] == V_6 )
V_276 += V_271 ;
V_280 = F_216 ( V_193 , V_277 ) ;
if ( V_280 + sizeof( * V_277 ) + V_276 > V_272 )
break;
V_250 ++ ;
V_276 += V_280 + sizeof( * V_277 ) ;
if ( V_6 == 0 )
break;
V_6 -- ;
}
if ( V_250 == 0 )
goto V_282;
F_32 ( ! V_249 && V_250 == V_273 ) ;
V_278 = F_90 ( V_192 ) ;
V_276 = F_217 ( V_193 , V_273 - V_250 ) ;
V_276 -= F_154 ( V_19 , V_193 ) ;
V_279 = F_154 ( V_19 , V_192 ) ;
F_125 ( V_192 ,
F_218 ( V_192 ) + V_279 - V_276 ,
F_218 ( V_192 ) + V_279 ,
F_155 ( V_19 ) - V_279 ) ;
F_39 ( V_192 , V_193 , F_218 ( V_192 ) +
F_155 ( V_19 ) - V_276 ,
F_218 ( V_193 ) + F_154 ( V_19 , V_193 ) ,
V_276 ) ;
F_125 ( V_192 , F_219 ( V_250 ) ,
F_219 ( 0 ) ,
V_278 * sizeof( struct V_187 ) ) ;
F_39 ( V_192 , V_193 , F_219 ( 0 ) ,
F_219 ( V_273 - V_250 ) ,
V_250 * sizeof( struct V_187 ) ) ;
V_278 += V_250 ;
F_126 ( V_192 , V_278 ) ;
V_276 = F_155 ( V_19 ) ;
for ( V_6 = 0 ; V_6 < V_278 ; V_6 ++ ) {
V_277 = F_210 ( V_6 ) ;
V_276 -= F_212 ( V_192 , V_277 , & V_268 ) ;
F_220 ( V_192 , V_277 , V_276 , & V_268 ) ;
}
V_273 -= V_250 ;
F_126 ( V_193 , V_273 ) ;
if ( V_273 )
F_50 ( V_193 ) ;
else
F_110 ( V_33 , V_19 -> V_26 , V_193 ) ;
F_50 ( V_192 ) ;
F_34 ( V_192 , & V_41 , 0 ) ;
F_123 ( V_275 , & V_41 , V_80 + 1 ) ;
F_50 ( V_275 ) ;
if ( V_2 -> V_17 [ 0 ] >= V_273 ) {
V_2 -> V_17 [ 0 ] -= V_273 ;
if ( F_90 ( V_2 -> V_8 [ 0 ] ) == 0 )
F_110 ( V_33 , V_19 -> V_26 , V_2 -> V_8 [ 0 ] ) ;
F_20 ( V_2 -> V_8 [ 0 ] ) ;
F_11 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_192 ;
V_2 -> V_17 [ 1 ] += 1 ;
} else {
F_20 ( V_192 ) ;
F_11 ( V_192 ) ;
}
return 0 ;
V_282:
F_20 ( V_192 ) ;
F_11 ( V_192 ) ;
return 1 ;
}
static int F_221 ( struct V_32 * V_33 , struct V_18
* V_19 , struct V_1 * V_2 ,
int V_283 , int V_271 ,
int V_249 , T_4 V_274 )
{
struct V_14 * V_193 = V_2 -> V_8 [ 0 ] ;
struct V_14 * V_192 ;
struct V_14 * V_275 ;
int V_80 ;
int V_272 ;
T_4 V_273 ;
int V_38 ;
if ( ! V_2 -> V_8 [ 1 ] )
return 1 ;
V_80 = V_2 -> V_17 [ 1 ] ;
V_275 = V_2 -> V_8 [ 1 ] ;
if ( V_80 >= F_90 ( V_275 ) - 1 )
return 1 ;
F_112 ( V_2 -> V_8 [ 1 ] ) ;
V_192 = F_168 ( V_19 , V_275 , V_80 + 1 ) ;
if ( V_192 == NULL )
return 1 ;
F_19 ( V_192 ) ;
F_143 ( V_192 ) ;
V_272 = F_196 ( V_19 , V_192 ) ;
if ( V_272 < V_271 )
goto V_282;
V_38 = F_141 ( V_33 , V_19 , V_192 , V_275 ,
V_80 + 1 , & V_192 ) ;
if ( V_38 )
goto V_282;
V_272 = F_196 ( V_19 , V_192 ) ;
if ( V_272 < V_271 )
goto V_282;
V_273 = F_90 ( V_193 ) ;
if ( V_273 == 0 )
goto V_282;
if ( V_2 -> V_17 [ 0 ] == V_273 && ! V_249 ) {
F_20 ( V_193 ) ;
F_11 ( V_193 ) ;
V_2 -> V_8 [ 0 ] = V_192 ;
V_2 -> V_17 [ 0 ] = 0 ;
V_2 -> V_17 [ 1 ] ++ ;
return 0 ;
}
return F_214 ( V_33 , V_19 , V_2 , V_283 , V_249 ,
V_192 , V_272 , V_273 , V_274 ) ;
V_282:
F_20 ( V_192 ) ;
F_11 ( V_192 ) ;
return 1 ;
}
static T_1 int F_222 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_271 ,
int V_249 , struct V_14 * V_193 ,
int V_272 , T_4 V_278 ,
T_4 V_284 )
{
struct V_40 V_41 ;
struct V_14 * V_192 = V_2 -> V_8 [ 0 ] ;
int V_6 ;
int V_276 = 0 ;
int V_250 = 0 ;
struct V_187 * V_277 ;
T_4 V_285 ;
T_4 V_174 ;
int V_38 = 0 ;
T_4 V_280 ;
T_4 V_286 ;
struct V_267 V_268 ;
F_209 ( & V_268 ) ;
if ( V_249 )
V_174 = F_153 ( V_278 , V_284 ) ;
else
V_174 = F_153 ( V_278 - 1 , V_284 ) ;
for ( V_6 = 0 ; V_6 < V_174 ; V_6 ++ ) {
V_277 = F_210 ( V_6 ) ;
if ( ! V_249 && V_250 > 0 ) {
if ( V_2 -> V_17 [ 0 ] < V_6 )
break;
if ( V_2 -> V_17 [ 0 ] == V_6 ) {
int V_281 = F_196 ( V_19 , V_192 ) ;
if ( V_281 + V_276 * 2 > V_272 )
break;
}
}
if ( V_2 -> V_17 [ 0 ] == V_6 )
V_276 += V_271 ;
V_280 = F_216 ( V_192 , V_277 ) ;
if ( V_280 + sizeof( * V_277 ) + V_276 > V_272 )
break;
V_250 ++ ;
V_276 += V_280 + sizeof( * V_277 ) ;
}
if ( V_250 == 0 ) {
V_38 = 1 ;
goto V_287;
}
F_32 ( ! V_249 && V_250 == F_90 ( V_192 ) ) ;
F_39 ( V_193 , V_192 ,
F_219 ( F_90 ( V_193 ) ) ,
F_219 ( 0 ) ,
V_250 * sizeof( struct V_187 ) ) ;
V_276 = F_155 ( V_19 ) -
F_156 ( V_192 , V_250 - 1 ) ;
F_39 ( V_193 , V_192 , F_218 ( V_193 ) +
F_154 ( V_19 , V_193 ) - V_276 ,
F_218 ( V_192 ) +
F_156 ( V_192 , V_250 - 1 ) ,
V_276 ) ;
V_285 = F_90 ( V_193 ) ;
F_72 ( V_285 <= 0 ) ;
V_286 = F_156 ( V_193 , V_285 - 1 ) ;
for ( V_6 = V_285 ; V_6 < V_285 + V_250 ; V_6 ++ ) {
T_4 V_231 ;
V_277 = F_210 ( V_6 ) ;
V_231 = F_211 ( V_193 , V_277 , & V_268 ) ;
F_220 ( V_193 , V_277 ,
V_231 - ( F_155 ( V_19 ) - V_286 ) ,
& V_268 ) ;
}
F_126 ( V_193 , V_285 + V_250 ) ;
if ( V_250 > V_278 )
F_142 ( 1 , V_150 L_4 , V_250 ,
V_278 ) ;
if ( V_250 < V_278 ) {
V_276 = F_156 ( V_192 , V_250 - 1 ) -
F_154 ( V_19 , V_192 ) ;
F_125 ( V_192 , F_218 ( V_192 ) +
F_155 ( V_19 ) - V_276 ,
F_218 ( V_192 ) +
F_154 ( V_19 , V_192 ) , V_276 ) ;
F_125 ( V_192 , F_219 ( 0 ) ,
F_219 ( V_250 ) ,
( F_90 ( V_192 ) - V_250 ) *
sizeof( struct V_187 ) ) ;
}
V_278 -= V_250 ;
F_126 ( V_192 , V_278 ) ;
V_276 = F_155 ( V_19 ) ;
for ( V_6 = 0 ; V_6 < V_278 ; V_6 ++ ) {
V_277 = F_210 ( V_6 ) ;
V_276 = V_276 - F_212 ( V_192 ,
V_277 , & V_268 ) ;
F_220 ( V_192 , V_277 , V_276 , & V_268 ) ;
}
F_50 ( V_193 ) ;
if ( V_278 )
F_50 ( V_192 ) ;
else
F_110 ( V_33 , V_19 -> V_26 , V_192 ) ;
F_34 ( V_192 , & V_41 , 0 ) ;
F_201 ( V_19 -> V_26 , V_2 , & V_41 , 1 ) ;
if ( V_2 -> V_17 [ 0 ] < V_250 ) {
V_2 -> V_17 [ 0 ] += V_285 ;
F_20 ( V_2 -> V_8 [ 0 ] ) ;
F_11 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_193 ;
V_2 -> V_17 [ 1 ] -= 1 ;
} else {
F_20 ( V_193 ) ;
F_11 ( V_193 ) ;
V_2 -> V_17 [ 0 ] -= V_250 ;
}
F_72 ( V_2 -> V_17 [ 0 ] < 0 ) ;
return V_38 ;
V_287:
F_20 ( V_193 ) ;
F_11 ( V_193 ) ;
return V_38 ;
}
static int F_223 ( struct V_32 * V_33 , struct V_18
* V_19 , struct V_1 * V_2 , int V_283 ,
int V_271 , int V_249 , T_4 V_284 )
{
struct V_14 * V_192 = V_2 -> V_8 [ 0 ] ;
struct V_14 * V_193 ;
int V_80 ;
int V_272 ;
T_4 V_278 ;
int V_38 = 0 ;
V_80 = V_2 -> V_17 [ 1 ] ;
if ( V_80 == 0 )
return 1 ;
if ( ! V_2 -> V_8 [ 1 ] )
return 1 ;
V_278 = F_90 ( V_192 ) ;
if ( V_278 == 0 )
return 1 ;
F_112 ( V_2 -> V_8 [ 1 ] ) ;
V_193 = F_168 ( V_19 , V_2 -> V_8 [ 1 ] , V_80 - 1 ) ;
if ( V_193 == NULL )
return 1 ;
F_19 ( V_193 ) ;
F_143 ( V_193 ) ;
V_272 = F_196 ( V_19 , V_193 ) ;
if ( V_272 < V_271 ) {
V_38 = 1 ;
goto V_287;
}
V_38 = F_141 ( V_33 , V_19 , V_193 ,
V_2 -> V_8 [ 1 ] , V_80 - 1 , & V_193 ) ;
if ( V_38 ) {
if ( V_38 == - V_200 )
V_38 = 1 ;
goto V_287;
}
V_272 = F_196 ( V_19 , V_193 ) ;
if ( V_272 < V_271 ) {
V_38 = 1 ;
goto V_287;
}
return F_222 ( V_33 , V_19 , V_2 , V_283 ,
V_249 , V_193 , V_272 , V_278 ,
V_284 ) ;
V_287:
F_20 ( V_193 ) ;
F_11 ( V_193 ) ;
return V_38 ;
}
static T_1 void F_224 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_14 * V_264 ,
struct V_14 * V_192 ,
int V_80 , int V_179 , int V_99 )
{
int V_288 ;
int V_289 ;
int V_6 ;
struct V_40 V_41 ;
struct V_267 V_268 ;
F_209 ( & V_268 ) ;
V_99 = V_99 - V_179 ;
F_126 ( V_192 , V_99 ) ;
V_288 = F_217 ( V_264 , V_179 ) - F_154 ( V_19 , V_264 ) ;
F_39 ( V_192 , V_264 , F_219 ( 0 ) ,
F_219 ( V_179 ) ,
V_99 * sizeof( struct V_187 ) ) ;
F_39 ( V_192 , V_264 ,
F_218 ( V_192 ) + F_155 ( V_19 ) -
V_288 , F_218 ( V_264 ) +
F_154 ( V_19 , V_264 ) , V_288 ) ;
V_289 = F_155 ( V_19 ) -
F_217 ( V_264 , V_179 ) ;
for ( V_6 = 0 ; V_6 < V_99 ; V_6 ++ ) {
struct V_187 * V_277 = F_210 ( V_6 ) ;
T_4 V_231 ;
V_231 = F_211 ( V_192 , V_277 , & V_268 ) ;
F_220 ( V_192 , V_277 ,
V_231 + V_289 , & V_268 ) ;
}
F_126 ( V_264 , V_179 ) ;
F_34 ( V_192 , & V_41 , 0 ) ;
F_207 ( V_33 , V_19 , V_2 , & V_41 , V_192 -> V_46 ,
V_2 -> V_17 [ 1 ] + 1 , 1 ) ;
F_50 ( V_192 ) ;
F_50 ( V_264 ) ;
F_72 ( V_2 -> V_17 [ 0 ] != V_80 ) ;
if ( V_179 <= V_80 ) {
F_20 ( V_2 -> V_8 [ 0 ] ) ;
F_11 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_192 ;
V_2 -> V_17 [ 0 ] -= V_179 ;
V_2 -> V_17 [ 1 ] += 1 ;
} else {
F_20 ( V_192 ) ;
F_11 ( V_192 ) ;
}
F_72 ( V_2 -> V_17 [ 0 ] < 0 ) ;
}
static T_1 int F_225 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
int V_271 )
{
int V_38 ;
int V_161 = 0 ;
int V_80 ;
T_4 V_99 ;
int V_290 = V_271 ;
V_80 = V_2 -> V_17 [ 0 ] ;
if ( V_80 < F_90 ( V_2 -> V_8 [ 0 ] ) )
V_290 -= F_196 ( V_19 , V_2 -> V_8 [ 0 ] ) ;
V_38 = F_221 ( V_33 , V_19 , V_2 , 1 , V_290 , 0 , V_80 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_38 == 0 )
V_161 ++ ;
V_99 = F_90 ( V_2 -> V_8 [ 0 ] ) ;
if ( V_2 -> V_17 [ 0 ] == 0 || V_2 -> V_17 [ 0 ] == V_99 )
return 0 ;
if ( F_196 ( V_19 , V_2 -> V_8 [ 0 ] ) >= V_271 )
return 0 ;
V_80 = V_2 -> V_17 [ 0 ] ;
V_38 = F_223 ( V_33 , V_19 , V_2 , 1 , V_290 , 0 , V_80 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_38 == 0 )
V_161 ++ ;
if ( V_161 )
return 0 ;
return 1 ;
}
static T_1 int F_197 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_155 * V_291 ,
struct V_1 * V_2 , int V_271 ,
int V_292 )
{
struct V_40 V_41 ;
struct V_14 * V_264 ;
T_4 V_99 ;
int V_179 ;
int V_80 ;
struct V_14 * V_192 ;
struct V_54 * V_26 = V_19 -> V_26 ;
int V_38 = 0 ;
int V_194 ;
int V_262 ;
int V_293 = 0 ;
int V_294 = 0 ;
V_264 = V_2 -> V_8 [ 0 ] ;
V_80 = V_2 -> V_17 [ 0 ] ;
if ( V_292 && V_271 + F_226 ( V_264 , V_80 ) +
sizeof( struct V_187 ) > F_155 ( V_19 ) )
return - V_295 ;
if ( V_271 && V_2 -> V_8 [ 1 ] ) {
int V_290 = V_271 ;
if ( V_80 < F_90 ( V_264 ) )
V_290 -= F_196 ( V_19 , V_264 ) ;
V_194 = F_221 ( V_33 , V_19 , V_2 , V_290 ,
V_290 , 0 , 0 ) ;
if ( V_194 < 0 )
return V_194 ;
if ( V_194 ) {
V_194 = F_223 ( V_33 , V_19 , V_2 , V_290 ,
V_290 , 0 , ( T_4 ) - 1 ) ;
if ( V_194 < 0 )
return V_194 ;
}
V_264 = V_2 -> V_8 [ 0 ] ;
if ( F_196 ( V_19 , V_264 ) >= V_271 )
return 0 ;
}
if ( ! V_2 -> V_8 [ 1 ] ) {
V_38 = F_204 ( V_33 , V_19 , V_2 , 1 ) ;
if ( V_38 )
return V_38 ;
}
V_226:
V_262 = 1 ;
V_264 = V_2 -> V_8 [ 0 ] ;
V_80 = V_2 -> V_17 [ 0 ] ;
V_99 = F_90 ( V_264 ) ;
V_179 = ( V_99 + 1 ) / 2 ;
if ( V_179 <= V_80 ) {
if ( V_99 == 1 ||
F_208 ( V_264 , V_179 , V_99 - V_179 ) + V_271 >
F_155 ( V_19 ) ) {
if ( V_80 >= V_99 ) {
V_262 = 0 ;
} else {
V_179 = V_80 ;
if ( V_179 != V_99 &&
F_208 ( V_264 , V_179 , V_99 - V_179 ) +
V_271 > F_155 ( V_19 ) ) {
if ( V_271 && ! V_294 )
goto V_296;
V_262 = 2 ;
}
}
}
} else {
if ( F_208 ( V_264 , 0 , V_179 ) + V_271 >
F_155 ( V_19 ) ) {
if ( ! V_292 && V_271 && V_80 == 0 ) {
V_262 = 0 ;
} else if ( ( V_292 || ! V_271 ) && V_80 == 0 ) {
V_179 = 1 ;
} else {
V_179 = V_80 ;
if ( V_179 != V_99 &&
F_208 ( V_264 , V_179 , V_99 - V_179 ) +
V_271 > F_155 ( V_19 ) ) {
if ( V_271 && ! V_294 )
goto V_296;
V_262 = 2 ;
}
}
}
}
if ( V_262 == 0 )
F_185 ( & V_41 , V_291 ) ;
else
F_34 ( V_264 , & V_41 , V_179 ) ;
V_192 = F_36 ( V_33 , V_19 , 0 , V_19 -> V_126 . V_28 ,
& V_41 , 0 , V_264 -> V_46 , 0 ) ;
if ( F_37 ( V_192 ) )
return F_38 ( V_192 ) ;
F_163 ( V_19 , V_19 -> V_170 ) ;
F_205 ( V_192 , 0 , 0 , sizeof( struct V_258 ) ) ;
F_40 ( V_192 , V_192 -> V_46 ) ;
F_41 ( V_192 , V_33 -> V_43 ) ;
F_42 ( V_192 , V_48 ) ;
F_45 ( V_192 , V_19 -> V_126 . V_28 ) ;
F_130 ( V_192 , 0 ) ;
F_46 ( V_192 , V_26 -> V_52 ,
F_47 () , V_53 ) ;
F_46 ( V_192 , V_26 -> V_259 ,
F_206 ( V_192 ) ,
V_260 ) ;
if ( V_262 == 0 ) {
if ( V_179 <= V_80 ) {
F_126 ( V_192 , 0 ) ;
F_207 ( V_33 , V_19 , V_2 , & V_41 , V_192 -> V_46 ,
V_2 -> V_17 [ 1 ] + 1 , 1 ) ;
F_20 ( V_2 -> V_8 [ 0 ] ) ;
F_11 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_192 ;
V_2 -> V_17 [ 0 ] = 0 ;
V_2 -> V_17 [ 1 ] += 1 ;
} else {
F_126 ( V_192 , 0 ) ;
F_207 ( V_33 , V_19 , V_2 , & V_41 , V_192 -> V_46 ,
V_2 -> V_17 [ 1 ] , 1 ) ;
F_20 ( V_2 -> V_8 [ 0 ] ) ;
F_11 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_192 ;
V_2 -> V_17 [ 0 ] = 0 ;
if ( V_2 -> V_17 [ 1 ] == 0 )
F_201 ( V_26 , V_2 , & V_41 , 1 ) ;
}
F_50 ( V_192 ) ;
return V_38 ;
}
F_224 ( V_33 , V_19 , V_2 , V_264 , V_192 , V_80 , V_179 , V_99 ) ;
if ( V_262 == 2 ) {
F_72 ( V_293 != 0 ) ;
V_293 ++ ;
goto V_226;
}
return 0 ;
V_296:
F_225 ( V_33 , V_19 , V_2 , V_271 ) ;
V_294 = 1 ;
if ( F_196 ( V_19 , V_2 -> V_8 [ 0 ] ) >= V_271 )
return 0 ;
goto V_226;
}
static T_1 int F_227 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_223 )
{
struct V_155 V_86 ;
struct V_14 * V_173 ;
struct V_297 * V_298 ;
T_2 V_299 = 0 ;
T_4 V_175 ;
int V_38 ;
V_173 = V_2 -> V_8 [ 0 ] ;
F_191 ( V_173 , & V_86 , V_2 -> V_17 [ 0 ] ) ;
F_72 ( V_86 . type != V_300 &&
V_86 . type != V_301 ) ;
if ( F_196 ( V_19 , V_173 ) >= V_223 )
return 0 ;
V_175 = F_226 ( V_173 , V_2 -> V_17 [ 0 ] ) ;
if ( V_86 . type == V_300 ) {
V_298 = F_228 ( V_173 , V_2 -> V_17 [ 0 ] ,
struct V_297 ) ;
V_299 = F_229 ( V_173 , V_298 ) ;
}
F_8 ( V_2 ) ;
V_2 -> V_219 = 1 ;
V_2 -> V_224 = 1 ;
V_38 = F_189 ( V_33 , V_19 , & V_86 , V_2 , 0 , 1 ) ;
V_2 -> V_224 = 0 ;
if ( V_38 > 0 )
V_38 = - V_222 ;
if ( V_38 < 0 )
goto V_166;
V_38 = - V_222 ;
V_173 = V_2 -> V_8 [ 0 ] ;
if ( V_175 != F_226 ( V_173 , V_2 -> V_17 [ 0 ] ) )
goto V_166;
if ( F_196 ( V_19 , V_2 -> V_8 [ 0 ] ) >= V_223 )
goto V_166;
if ( V_86 . type == V_300 ) {
V_298 = F_228 ( V_173 , V_2 -> V_17 [ 0 ] ,
struct V_297 ) ;
if ( V_299 != F_229 ( V_173 , V_298 ) )
goto V_166;
}
F_3 ( V_2 ) ;
V_38 = F_197 ( V_33 , V_19 , & V_86 , V_2 , V_223 , 1 ) ;
if ( V_38 )
goto V_166;
V_2 -> V_219 = 0 ;
F_179 ( V_2 , 1 ) ;
return 0 ;
V_166:
V_2 -> V_219 = 0 ;
return V_38 ;
}
static T_1 int F_230 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_155 * V_248 ,
unsigned long V_302 )
{
struct V_14 * V_173 ;
struct V_187 * V_277 ;
struct V_187 * V_303 ;
int V_80 ;
char * V_34 ;
T_4 V_99 ;
T_4 V_175 ;
T_4 V_304 ;
struct V_40 V_41 ;
V_173 = V_2 -> V_8 [ 0 ] ;
F_72 ( F_196 ( V_19 , V_173 ) < sizeof( struct V_187 ) ) ;
F_3 ( V_2 ) ;
V_277 = F_210 ( V_2 -> V_17 [ 0 ] ) ;
V_304 = F_231 ( V_173 , V_277 ) ;
V_175 = F_216 ( V_173 , V_277 ) ;
V_34 = F_232 ( V_175 , V_4 ) ;
if ( ! V_34 )
return - V_89 ;
F_159 ( V_173 , V_34 , F_233 ( V_173 ,
V_2 -> V_17 [ 0 ] ) , V_175 ) ;
V_80 = V_2 -> V_17 [ 0 ] + 1 ;
V_99 = F_90 ( V_173 ) ;
if ( V_80 != V_99 ) {
F_125 ( V_173 , F_219 ( V_80 + 1 ) ,
F_219 ( V_80 ) ,
( V_99 - V_80 ) * sizeof( struct V_187 ) ) ;
}
F_185 ( & V_41 , V_248 ) ;
F_203 ( V_173 , & V_41 , V_80 ) ;
V_303 = F_210 ( V_80 ) ;
F_234 ( V_173 , V_303 , V_304 ) ;
F_235 ( V_173 , V_303 , V_175 - V_302 ) ;
F_234 ( V_173 , V_277 ,
V_304 + V_175 - V_302 ) ;
F_235 ( V_173 , V_277 , V_302 ) ;
F_126 ( V_173 , V_99 + 1 ) ;
F_46 ( V_173 , V_34 ,
F_233 ( V_173 , V_2 -> V_17 [ 0 ] ) ,
V_302 ) ;
F_46 ( V_173 , V_34 + V_302 ,
F_233 ( V_173 , V_80 ) ,
V_175 - V_302 ) ;
F_50 ( V_173 ) ;
F_72 ( F_196 ( V_19 , V_173 ) < 0 ) ;
F_70 ( V_34 ) ;
return 0 ;
}
int F_236 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_155 * V_248 ,
unsigned long V_302 )
{
int V_38 ;
V_38 = F_227 ( V_33 , V_19 , V_2 ,
sizeof( struct V_187 ) ) ;
if ( V_38 )
return V_38 ;
V_38 = F_230 ( V_33 , V_19 , V_2 , V_248 , V_302 ) ;
return V_38 ;
}
int F_237 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_155 * V_248 )
{
struct V_14 * V_173 ;
int V_38 ;
T_4 V_175 ;
V_173 = V_2 -> V_8 [ 0 ] ;
V_175 = F_226 ( V_173 , V_2 -> V_17 [ 0 ] ) ;
V_38 = F_227 ( V_33 , V_19 , V_2 ,
V_175 + sizeof( struct V_187 ) ) ;
if ( V_38 )
return V_38 ;
V_2 -> V_17 [ 0 ] ++ ;
F_238 ( V_19 , V_2 , V_248 , & V_175 ,
V_175 , V_175 +
sizeof( struct V_187 ) , 1 ) ;
V_173 = V_2 -> V_8 [ 0 ] ;
F_239 ( V_173 ,
F_233 ( V_173 , V_2 -> V_17 [ 0 ] ) ,
F_233 ( V_173 , V_2 -> V_17 [ 0 ] - 1 ) ,
V_175 ) ;
return 0 ;
}
void F_240 ( struct V_18 * V_19 , struct V_1 * V_2 ,
T_4 V_305 , int V_306 )
{
int V_80 ;
struct V_14 * V_173 ;
struct V_187 * V_277 ;
T_4 V_99 ;
unsigned int V_279 ;
unsigned int V_307 ;
unsigned int V_308 ;
unsigned int V_309 ;
int V_6 ;
struct V_267 V_268 ;
F_209 ( & V_268 ) ;
V_173 = V_2 -> V_8 [ 0 ] ;
V_80 = V_2 -> V_17 [ 0 ] ;
V_308 = F_226 ( V_173 , V_80 ) ;
if ( V_308 == V_305 )
return;
V_99 = F_90 ( V_173 ) ;
V_279 = F_154 ( V_19 , V_173 ) ;
V_307 = F_156 ( V_173 , V_80 ) ;
V_309 = V_308 - V_305 ;
F_72 ( V_80 < 0 ) ;
F_72 ( V_80 >= V_99 ) ;
for ( V_6 = V_80 ; V_6 < V_99 ; V_6 ++ ) {
T_4 V_231 ;
V_277 = F_210 ( V_6 ) ;
V_231 = F_211 ( V_173 , V_277 , & V_268 ) ;
F_220 ( V_173 , V_277 ,
V_231 + V_309 , & V_268 ) ;
}
if ( V_306 ) {
F_125 ( V_173 , F_218 ( V_173 ) +
V_279 + V_309 , F_218 ( V_173 ) +
V_279 , V_307 + V_305 - V_279 ) ;
} else {
struct V_40 V_41 ;
T_2 V_158 ;
F_34 ( V_173 , & V_41 , V_80 ) ;
if ( F_241 ( & V_41 ) == V_300 ) {
unsigned long V_310 ;
struct V_297 * V_298 ;
V_298 = F_228 ( V_173 , V_80 ,
struct V_297 ) ;
V_298 = (struct V_297 * ) (
( unsigned long ) V_298 - V_309 ) ;
if ( F_242 ( V_173 , V_298 ) ==
V_311 ) {
V_310 = F_233 ( V_173 , V_80 ) ;
F_125 ( V_173 , V_310 ,
( unsigned long ) V_298 ,
V_312 ) ;
}
}
F_125 ( V_173 , F_218 ( V_173 ) +
V_279 + V_309 , F_218 ( V_173 ) +
V_279 , V_307 - V_279 ) ;
V_158 = F_243 ( & V_41 ) ;
F_244 ( & V_41 , V_158 + V_309 ) ;
F_203 ( V_173 , & V_41 , V_80 ) ;
if ( V_80 == 0 )
F_201 ( V_19 -> V_26 , V_2 , & V_41 , 1 ) ;
}
V_277 = F_210 ( V_80 ) ;
F_235 ( V_173 , V_277 , V_305 ) ;
F_50 ( V_173 ) ;
if ( F_196 ( V_19 , V_173 ) < 0 ) {
F_245 ( V_19 , V_173 ) ;
F_172 () ;
}
}
void F_246 ( struct V_18 * V_19 , struct V_1 * V_2 ,
T_4 V_271 )
{
int V_80 ;
struct V_14 * V_173 ;
struct V_187 * V_277 ;
T_4 V_99 ;
unsigned int V_279 ;
unsigned int V_313 ;
unsigned int V_308 ;
int V_6 ;
struct V_267 V_268 ;
F_209 ( & V_268 ) ;
V_173 = V_2 -> V_8 [ 0 ] ;
V_99 = F_90 ( V_173 ) ;
V_279 = F_154 ( V_19 , V_173 ) ;
if ( F_196 ( V_19 , V_173 ) < V_271 ) {
F_245 ( V_19 , V_173 ) ;
F_172 () ;
}
V_80 = V_2 -> V_17 [ 0 ] ;
V_313 = F_217 ( V_173 , V_80 ) ;
F_72 ( V_80 < 0 ) ;
if ( V_80 >= V_99 ) {
F_245 ( V_19 , V_173 ) ;
F_213 ( V_19 -> V_26 , L_5 ,
V_80 , V_99 ) ;
F_72 ( 1 ) ;
}
for ( V_6 = V_80 ; V_6 < V_99 ; V_6 ++ ) {
T_4 V_231 ;
V_277 = F_210 ( V_6 ) ;
V_231 = F_211 ( V_173 , V_277 , & V_268 ) ;
F_220 ( V_173 , V_277 ,
V_231 - V_271 , & V_268 ) ;
}
F_125 ( V_173 , F_218 ( V_173 ) +
V_279 - V_271 , F_218 ( V_173 ) +
V_279 , V_313 - V_279 ) ;
V_279 = V_313 ;
V_308 = F_226 ( V_173 , V_80 ) ;
V_277 = F_210 ( V_80 ) ;
F_235 ( V_173 , V_277 , V_308 + V_271 ) ;
F_50 ( V_173 ) ;
if ( F_196 ( V_19 , V_173 ) < 0 ) {
F_245 ( V_19 , V_173 ) ;
F_172 () ;
}
}
void F_238 ( struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_155 * V_314 , T_4 * V_271 ,
T_4 V_315 , T_4 V_316 , int V_174 )
{
struct V_187 * V_277 ;
int V_6 ;
T_4 V_99 ;
unsigned int V_279 ;
struct V_40 V_41 ;
struct V_14 * V_173 ;
int V_80 ;
struct V_267 V_268 ;
if ( V_2 -> V_17 [ 0 ] == 0 ) {
F_185 ( & V_41 , V_314 ) ;
F_201 ( V_19 -> V_26 , V_2 , & V_41 , 1 ) ;
}
F_179 ( V_2 , 1 ) ;
F_209 ( & V_268 ) ;
V_173 = V_2 -> V_8 [ 0 ] ;
V_80 = V_2 -> V_17 [ 0 ] ;
V_99 = F_90 ( V_173 ) ;
V_279 = F_154 ( V_19 , V_173 ) ;
if ( F_196 ( V_19 , V_173 ) < V_316 ) {
F_245 ( V_19 , V_173 ) ;
F_213 ( V_19 -> V_26 , L_6 ,
V_316 , F_196 ( V_19 , V_173 ) ) ;
F_172 () ;
}
if ( V_80 != V_99 ) {
unsigned int V_313 = F_217 ( V_173 , V_80 ) ;
if ( V_313 < V_279 ) {
F_245 ( V_19 , V_173 ) ;
F_213 ( V_19 -> V_26 , L_7 ,
V_80 , V_313 , V_279 ) ;
F_72 ( 1 ) ;
}
for ( V_6 = V_80 ; V_6 < V_99 ; V_6 ++ ) {
T_4 V_231 ;
V_277 = F_210 ( V_6 ) ;
V_231 = F_211 ( V_173 , V_277 , & V_268 ) ;
F_220 ( V_173 , V_277 ,
V_231 - V_315 , & V_268 ) ;
}
F_125 ( V_173 , F_219 ( V_80 + V_174 ) ,
F_219 ( V_80 ) ,
( V_99 - V_80 ) * sizeof( struct V_187 ) ) ;
F_125 ( V_173 , F_218 ( V_173 ) +
V_279 - V_315 , F_218 ( V_173 ) +
V_279 , V_313 - V_279 ) ;
V_279 = V_313 ;
}
for ( V_6 = 0 ; V_6 < V_174 ; V_6 ++ ) {
F_185 ( & V_41 , V_314 + V_6 ) ;
F_203 ( V_173 , & V_41 , V_80 + V_6 ) ;
V_277 = F_210 ( V_80 + V_6 ) ;
F_220 ( V_173 , V_277 ,
V_279 - V_271 [ V_6 ] , & V_268 ) ;
V_279 -= V_271 [ V_6 ] ;
F_247 ( V_173 , V_277 , V_271 [ V_6 ] , & V_268 ) ;
}
F_126 ( V_173 , V_99 + V_174 ) ;
F_50 ( V_173 ) ;
if ( F_196 ( V_19 , V_173 ) < 0 ) {
F_245 ( V_19 , V_173 ) ;
F_172 () ;
}
}
int F_248 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_155 * V_314 , T_4 * V_271 ,
int V_174 )
{
int V_38 = 0 ;
int V_80 ;
int V_6 ;
T_4 V_316 = 0 ;
T_4 V_315 = 0 ;
for ( V_6 = 0 ; V_6 < V_174 ; V_6 ++ )
V_315 += V_271 [ V_6 ] ;
V_316 = V_315 + ( V_174 * sizeof( struct V_187 ) ) ;
V_38 = F_189 ( V_33 , V_19 , V_314 , V_2 , V_316 , 1 ) ;
if ( V_38 == 0 )
return - V_79 ;
if ( V_38 < 0 )
return V_38 ;
V_80 = V_2 -> V_17 [ 0 ] ;
F_72 ( V_80 < 0 ) ;
F_238 ( V_19 , V_2 , V_314 , V_271 ,
V_315 , V_316 , V_174 ) ;
return 0 ;
}
int F_249 ( struct V_32 * V_33 , struct V_18
* V_19 , struct V_155 * V_314 , void * V_317 , T_4
V_271 )
{
int V_38 = 0 ;
struct V_1 * V_2 ;
struct V_14 * V_173 ;
unsigned long V_310 ;
V_2 = F_1 () ;
if ( ! V_2 )
return - V_89 ;
V_38 = F_250 ( V_33 , V_19 , V_2 , V_314 , V_271 ) ;
if ( ! V_38 ) {
V_173 = V_2 -> V_8 [ 0 ] ;
V_310 = F_233 ( V_173 , V_2 -> V_17 [ 0 ] ) ;
F_46 ( V_173 , V_317 , V_310 , V_271 ) ;
F_50 ( V_173 ) ;
}
F_7 ( V_2 ) ;
return V_38 ;
}
static void F_170 ( struct V_18 * V_19 , struct V_1 * V_2 ,
int V_39 , int V_80 )
{
struct V_14 * V_74 = V_2 -> V_8 [ V_39 ] ;
T_4 V_99 ;
int V_38 ;
V_99 = F_90 ( V_74 ) ;
if ( V_80 != V_99 - 1 ) {
if ( V_39 )
F_95 ( V_19 -> V_26 , V_74 , V_80 ,
V_80 + 1 , V_99 - V_80 - 1 ) ;
F_125 ( V_74 ,
F_124 ( V_80 ) ,
F_124 ( V_80 + 1 ) ,
sizeof( struct V_142 ) *
( V_99 - V_80 - 1 ) ) ;
} else if ( V_39 ) {
V_38 = F_84 ( V_19 -> V_26 , V_74 , V_80 ,
V_115 , V_4 ) ;
F_72 ( V_38 < 0 ) ;
}
V_99 -- ;
F_126 ( V_74 , V_99 ) ;
if ( V_99 == 0 && V_74 == V_19 -> V_21 ) {
F_72 ( F_33 ( V_19 -> V_21 ) != 1 ) ;
F_130 ( V_19 -> V_21 , 0 ) ;
} else if ( V_80 == 0 ) {
struct V_40 V_41 ;
F_35 ( V_74 , & V_41 , 0 ) ;
F_201 ( V_19 -> V_26 , V_2 , & V_41 , V_39 + 1 ) ;
}
F_50 ( V_74 ) ;
}
static T_1 void F_251 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_14 * V_173 )
{
F_32 ( F_48 ( V_173 ) != V_33 -> V_43 ) ;
F_170 ( V_19 , V_2 , 1 , V_2 -> V_17 [ 1 ] ) ;
F_179 ( V_2 , 0 ) ;
F_166 ( V_19 , V_173 -> V_47 ) ;
F_115 ( V_173 ) ;
F_117 ( V_33 , V_19 , V_173 , 0 , 1 ) ;
F_120 ( V_173 ) ;
}
int F_252 ( struct V_32 * V_33 , struct V_18 * V_19 ,
struct V_1 * V_2 , int V_80 , int V_174 )
{
struct V_14 * V_173 ;
struct V_187 * V_277 ;
T_4 V_318 ;
T_4 V_319 = 0 ;
int V_38 = 0 ;
int V_194 ;
int V_6 ;
T_4 V_99 ;
struct V_267 V_268 ;
F_209 ( & V_268 ) ;
V_173 = V_2 -> V_8 [ 0 ] ;
V_318 = F_156 ( V_173 , V_80 + V_174 - 1 ) ;
for ( V_6 = 0 ; V_6 < V_174 ; V_6 ++ )
V_319 += F_226 ( V_173 , V_80 + V_6 ) ;
V_99 = F_90 ( V_173 ) ;
if ( V_80 + V_174 != V_99 ) {
int V_279 = F_154 ( V_19 , V_173 ) ;
F_125 ( V_173 , F_218 ( V_173 ) +
V_279 + V_319 ,
F_218 ( V_173 ) + V_279 ,
V_318 - V_279 ) ;
for ( V_6 = V_80 + V_174 ; V_6 < V_99 ; V_6 ++ ) {
T_4 V_231 ;
V_277 = F_210 ( V_6 ) ;
V_231 = F_211 ( V_173 , V_277 , & V_268 ) ;
F_220 ( V_173 , V_277 ,
V_231 + V_319 , & V_268 ) ;
}
F_125 ( V_173 , F_219 ( V_80 ) ,
F_219 ( V_80 + V_174 ) ,
sizeof( struct V_187 ) *
( V_99 - V_80 - V_174 ) ) ;
}
F_126 ( V_173 , V_99 - V_174 ) ;
V_99 -= V_174 ;
if ( V_99 == 0 ) {
if ( V_173 == V_19 -> V_21 ) {
F_130 ( V_173 , 0 ) ;
} else {
F_3 ( V_2 ) ;
F_110 ( V_33 , V_19 -> V_26 , V_173 ) ;
F_251 ( V_33 , V_19 , V_2 , V_173 ) ;
}
} else {
int V_320 = F_208 ( V_173 , 0 , V_99 ) ;
if ( V_80 == 0 ) {
struct V_40 V_41 ;
F_34 ( V_173 , & V_41 , 0 ) ;
F_201 ( V_19 -> V_26 , V_2 , & V_41 , 1 ) ;
}
if ( V_320 < F_155 ( V_19 ) / 3 ) {
V_80 = V_2 -> V_17 [ 1 ] ;
F_115 ( V_173 ) ;
F_3 ( V_2 ) ;
V_194 = F_223 ( V_33 , V_19 , V_2 , 1 , 1 ,
1 , ( T_4 ) - 1 ) ;
if ( V_194 < 0 && V_194 != - V_200 )
V_38 = V_194 ;
if ( V_2 -> V_8 [ 0 ] == V_173 &&
F_90 ( V_173 ) ) {
V_194 = F_221 ( V_33 , V_19 , V_2 , 1 ,
1 , 1 , 0 ) ;
if ( V_194 < 0 && V_194 != - V_200 )
V_38 = V_194 ;
}
if ( F_90 ( V_173 ) == 0 ) {
V_2 -> V_17 [ 1 ] = V_80 ;
F_251 ( V_33 , V_19 , V_2 , V_173 ) ;
F_11 ( V_173 ) ;
V_38 = 0 ;
} else {
if ( V_2 -> V_8 [ 0 ] == V_173 )
F_50 ( V_173 ) ;
F_11 ( V_173 ) ;
}
} else {
F_50 ( V_173 ) ;
}
}
return V_38 ;
}
int F_200 ( struct V_18 * V_19 , struct V_1 * V_2 )
{
struct V_155 V_86 ;
struct V_40 V_233 ;
int V_38 ;
F_191 ( V_2 -> V_8 [ 0 ] , & V_86 , 0 ) ;
if ( V_86 . V_158 > 0 ) {
V_86 . V_158 -- ;
} else if ( V_86 . type > 0 ) {
V_86 . type -- ;
V_86 . V_158 = ( T_2 ) - 1 ;
} else if ( V_86 . V_28 > 0 ) {
V_86 . V_28 -- ;
V_86 . type = ( T_5 ) - 1 ;
V_86 . V_158 = ( T_2 ) - 1 ;
} else {
return 1 ;
}
F_8 ( V_2 ) ;
V_38 = F_189 ( NULL , V_19 , & V_86 , V_2 , 0 , 0 ) ;
if ( V_38 < 0 )
return V_38 ;
F_34 ( V_2 -> V_8 [ 0 ] , & V_233 , 0 ) ;
V_38 = F_146 ( & V_233 , & V_86 ) ;
if ( V_38 <= 0 )
return 0 ;
return 1 ;
}
int F_253 ( struct V_18 * V_19 , struct V_155 * V_321 ,
struct V_1 * V_2 ,
T_2 V_322 )
{
struct V_14 * V_75 ;
struct V_155 V_233 ;
int V_80 ;
int V_225 ;
T_4 V_99 ;
int V_39 ;
int V_38 = 1 ;
int V_219 = V_2 -> V_219 ;
V_2 -> V_219 = 1 ;
V_226:
V_75 = F_21 ( V_19 ) ;
V_39 = F_33 ( V_75 ) ;
F_32 ( V_2 -> V_8 [ V_39 ] ) ;
V_2 -> V_8 [ V_39 ] = V_75 ;
V_2 -> V_9 [ V_39 ] = V_10 ;
if ( F_48 ( V_75 ) < V_322 ) {
V_38 = 1 ;
goto V_287;
}
while ( 1 ) {
V_99 = F_90 ( V_75 ) ;
V_39 = F_33 ( V_75 ) ;
V_225 = F_160 ( V_75 , V_321 , V_39 , & V_80 ) ;
if ( V_39 == V_2 -> V_235 ) {
if ( V_80 >= V_99 )
goto V_323;
V_38 = 0 ;
V_2 -> V_17 [ V_39 ] = V_80 ;
F_191 ( V_75 , & V_233 , V_80 ) ;
goto V_287;
}
if ( V_225 && V_80 > 0 )
V_80 -- ;
while ( V_80 < V_99 ) {
T_2 V_162 ;
V_162 = F_82 ( V_75 , V_80 ) ;
if ( V_162 < V_322 ) {
V_80 ++ ;
continue;
}
break;
}
V_323:
if ( V_80 >= V_99 ) {
V_2 -> V_17 [ V_39 ] = V_80 ;
F_3 ( V_2 ) ;
V_225 = F_254 ( V_19 , V_2 , V_321 , V_39 ,
V_322 ) ;
if ( V_225 == 0 ) {
F_8 ( V_2 ) ;
goto V_226;
} else {
goto V_287;
}
}
F_255 ( V_75 , & V_233 , V_80 ) ;
V_2 -> V_17 [ V_39 ] = V_80 ;
if ( V_39 == V_2 -> V_235 ) {
V_38 = 0 ;
goto V_287;
}
F_3 ( V_2 ) ;
V_75 = F_168 ( V_19 , V_75 , V_80 ) ;
F_72 ( ! V_75 ) ;
F_22 ( V_75 ) ;
V_2 -> V_9 [ V_39 - 1 ] = V_10 ;
V_2 -> V_8 [ V_39 - 1 ] = V_75 ;
F_178 ( V_2 , V_39 , 1 , 0 , NULL ) ;
F_5 ( V_2 , NULL , 0 ) ;
}
V_287:
V_2 -> V_219 = V_219 ;
if ( V_38 == 0 ) {
F_179 ( V_2 , V_2 -> V_235 + 1 ) ;
F_3 ( V_2 ) ;
memcpy ( V_321 , & V_233 , sizeof( V_233 ) ) ;
}
return V_38 ;
}
static void F_256 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int * V_39 , int V_324 )
{
F_72 ( * V_39 == 0 ) ;
V_2 -> V_8 [ * V_39 - 1 ] = F_168 ( V_19 , V_2 -> V_8 [ * V_39 ] ,
V_2 -> V_17 [ * V_39 ] ) ;
V_2 -> V_17 [ * V_39 - 1 ] = 0 ;
( * V_39 ) -- ;
}
static int F_257 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int * V_39 , int V_324 )
{
int V_38 = 0 ;
int V_99 ;
V_99 = F_90 ( V_2 -> V_8 [ * V_39 ] ) ;
V_2 -> V_17 [ * V_39 ] ++ ;
while ( V_2 -> V_17 [ * V_39 ] >= V_99 ) {
if ( * V_39 == V_324 )
return - 1 ;
V_2 -> V_17 [ * V_39 ] = 0 ;
F_11 ( V_2 -> V_8 [ * V_39 ] ) ;
V_2 -> V_8 [ * V_39 ] = NULL ;
( * V_39 ) ++ ;
V_2 -> V_17 [ * V_39 ] ++ ;
V_99 = F_90 ( V_2 -> V_8 [ * V_39 ] ) ;
V_38 = 1 ;
}
return V_38 ;
}
static int F_258 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int * V_39 , int V_324 ,
int V_325 ,
struct V_155 * V_86 )
{
int V_38 ;
if ( * V_39 == 0 || ! V_325 ) {
V_38 = F_257 ( V_19 , V_2 , V_39 , V_324 ) ;
} else {
F_256 ( V_19 , V_2 , V_39 , V_324 ) ;
V_38 = 0 ;
}
if ( V_38 >= 0 ) {
if ( * V_39 == 0 )
F_191 ( V_2 -> V_8 [ * V_39 ] , V_86 ,
V_2 -> V_17 [ * V_39 ] ) ;
else
F_255 ( V_2 -> V_8 [ * V_39 ] , V_86 ,
V_2 -> V_17 [ * V_39 ] ) ;
}
return V_38 ;
}
static int F_259 ( struct V_18 * V_326 ,
struct V_1 * V_327 ,
struct V_1 * V_328 ,
char * V_329 )
{
int V_330 ;
int V_331 , V_332 ;
unsigned long V_333 , V_334 ;
V_331 = F_226 ( V_327 -> V_8 [ 0 ] , V_327 -> V_17 [ 0 ] ) ;
V_332 = F_226 ( V_328 -> V_8 [ 0 ] , V_328 -> V_17 [ 0 ] ) ;
if ( V_331 != V_332 )
return 1 ;
V_333 = F_233 ( V_327 -> V_8 [ 0 ] , V_327 -> V_17 [ 0 ] ) ;
V_334 = F_233 ( V_328 -> V_8 [ 0 ] ,
V_328 -> V_17 [ 0 ] ) ;
F_159 ( V_327 -> V_8 [ 0 ] , V_329 , V_333 , V_331 ) ;
V_330 = F_186 ( V_328 -> V_8 [ 0 ] , V_329 , V_334 , V_331 ) ;
if ( V_330 )
return 1 ;
return 0 ;
}
int F_260 ( struct V_18 * V_326 ,
struct V_18 * V_335 ,
T_6 V_336 , void * V_337 )
{
int V_38 ;
int V_330 ;
struct V_1 * V_327 = NULL ;
struct V_1 * V_328 = NULL ;
struct V_155 V_338 ;
struct V_155 V_201 ;
char * V_329 = NULL ;
int V_339 ;
int V_340 ;
int V_341 ;
int V_342 ;
int V_343 ;
int V_344 ;
int V_345 ;
int V_346 ;
T_2 V_347 ;
T_2 V_348 ;
T_2 V_349 ;
T_2 V_350 ;
V_327 = F_1 () ;
if ( ! V_327 ) {
V_38 = - V_89 ;
goto V_287;
}
V_328 = F_1 () ;
if ( ! V_328 ) {
V_38 = - V_89 ;
goto V_287;
}
V_329 = F_232 ( V_326 -> V_170 , V_4 ) ;
if ( ! V_329 ) {
V_38 = - V_89 ;
goto V_287;
}
V_327 -> V_236 = 1 ;
V_327 -> V_239 = 1 ;
V_328 -> V_236 = 1 ;
V_328 -> V_239 = 1 ;
F_192 ( & V_326 -> V_26 -> V_238 ) ;
V_341 = F_33 ( V_326 -> V_120 ) ;
V_339 = V_341 ;
V_327 -> V_8 [ V_341 ] = V_326 -> V_120 ;
F_115 ( V_327 -> V_8 [ V_341 ] ) ;
V_342 = F_33 ( V_335 -> V_120 ) ;
V_340 = V_342 ;
V_328 -> V_8 [ V_342 ] = V_335 -> V_120 ;
F_115 ( V_328 -> V_8 [ V_342 ] ) ;
F_193 ( & V_326 -> V_26 -> V_238 ) ;
if ( V_341 == 0 )
F_191 ( V_327 -> V_8 [ V_341 ] ,
& V_338 , V_327 -> V_17 [ V_341 ] ) ;
else
F_255 ( V_327 -> V_8 [ V_341 ] ,
& V_338 , V_327 -> V_17 [ V_341 ] ) ;
if ( V_342 == 0 )
F_191 ( V_328 -> V_8 [ V_342 ] ,
& V_201 , V_328 -> V_17 [ V_342 ] ) ;
else
F_255 ( V_328 -> V_8 [ V_342 ] ,
& V_201 , V_328 -> V_17 [ V_342 ] ) ;
V_343 = V_344 = 0 ;
V_345 = V_346 = 0 ;
while ( 1 ) {
if ( V_345 && ! V_343 ) {
V_38 = F_258 ( V_326 , V_327 , & V_341 ,
V_339 ,
V_345 != V_351 ,
& V_338 ) ;
if ( V_38 < 0 )
V_343 = V_352 ;
V_345 = 0 ;
}
if ( V_346 && ! V_344 ) {
V_38 = F_258 ( V_335 , V_328 , & V_342 ,
V_340 ,
V_346 != V_351 ,
& V_201 ) ;
if ( V_38 < 0 )
V_344 = V_352 ;
V_346 = 0 ;
}
if ( V_343 && V_344 ) {
V_38 = 0 ;
goto V_287;
} else if ( V_343 ) {
if ( V_342 == 0 ) {
V_38 = V_336 ( V_326 , V_335 ,
V_327 , V_328 ,
& V_201 ,
V_353 ,
V_337 ) ;
if ( V_38 < 0 )
goto V_287;
}
V_346 = V_352 ;
continue;
} else if ( V_344 ) {
if ( V_341 == 0 ) {
V_38 = V_336 ( V_326 , V_335 ,
V_327 , V_328 ,
& V_338 ,
V_354 ,
V_337 ) ;
if ( V_38 < 0 )
goto V_287;
}
V_345 = V_352 ;
continue;
}
if ( V_341 == 0 && V_342 == 0 ) {
V_330 = F_148 ( & V_338 , & V_201 ) ;
if ( V_330 < 0 ) {
V_38 = V_336 ( V_326 , V_335 ,
V_327 , V_328 ,
& V_338 ,
V_354 ,
V_337 ) ;
if ( V_38 < 0 )
goto V_287;
V_345 = V_352 ;
} else if ( V_330 > 0 ) {
V_38 = V_336 ( V_326 , V_335 ,
V_327 , V_328 ,
& V_201 ,
V_353 ,
V_337 ) ;
if ( V_38 < 0 )
goto V_287;
V_346 = V_352 ;
} else {
enum V_355 V_356 ;
F_32 ( ! F_135 ( V_327 -> V_8 [ 0 ] ) ) ;
V_38 = F_259 ( V_326 , V_327 ,
V_328 , V_329 ) ;
if ( V_38 )
V_356 = V_357 ;
else
V_356 = V_358 ;
V_38 = V_336 ( V_326 , V_335 ,
V_327 , V_328 ,
& V_338 , V_356 , V_337 ) ;
if ( V_38 < 0 )
goto V_287;
V_345 = V_352 ;
V_346 = V_352 ;
}
} else if ( V_341 == V_342 ) {
V_330 = F_148 ( & V_338 , & V_201 ) ;
if ( V_330 < 0 ) {
V_345 = V_352 ;
} else if ( V_330 > 0 ) {
V_346 = V_352 ;
} else {
V_347 = F_81 (
V_327 -> V_8 [ V_341 ] ,
V_327 -> V_17 [ V_341 ] ) ;
V_348 = F_81 (
V_328 -> V_8 [ V_342 ] ,
V_328 -> V_17 [ V_342 ] ) ;
V_349 = F_82 (
V_327 -> V_8 [ V_341 ] ,
V_327 -> V_17 [ V_341 ] ) ;
V_350 = F_82 (
V_328 -> V_8 [ V_342 ] ,
V_328 -> V_17 [ V_342 ] ) ;
if ( V_347 == V_348 &&
V_349 == V_350 ) {
V_345 = V_351 ;
V_346 = V_351 ;
} else {
V_345 = V_352 ;
V_346 = V_352 ;
}
}
} else if ( V_341 < V_342 ) {
V_346 = V_352 ;
} else {
V_345 = V_352 ;
}
}
V_287:
F_7 ( V_327 ) ;
F_7 ( V_328 ) ;
F_70 ( V_329 ) ;
return V_38 ;
}
int F_254 ( struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_155 * V_86 , int V_39 , T_2 V_322 )
{
int V_80 ;
struct V_14 * V_256 ;
F_32 ( ! V_2 -> V_219 ) ;
while ( V_39 < V_7 ) {
if ( ! V_2 -> V_8 [ V_39 ] )
return 1 ;
V_80 = V_2 -> V_17 [ V_39 ] + 1 ;
V_256 = V_2 -> V_8 [ V_39 ] ;
V_66:
if ( V_80 >= F_90 ( V_256 ) ) {
int V_38 ;
int V_359 ;
struct V_155 V_360 ;
if ( V_39 + 1 >= V_7 ||
! V_2 -> V_8 [ V_39 + 1 ] )
return 1 ;
if ( V_2 -> V_9 [ V_39 + 1 ] ) {
V_39 ++ ;
continue;
}
V_80 = F_90 ( V_256 ) - 1 ;
if ( V_39 == 0 )
F_191 ( V_256 , & V_360 , V_80 ) ;
else
F_255 ( V_256 , & V_360 , V_80 ) ;
V_359 = V_2 -> V_235 ;
F_8 ( V_2 ) ;
V_2 -> V_235 = V_39 ;
V_38 = F_189 ( NULL , V_19 , & V_360 , V_2 ,
0 , 0 ) ;
V_2 -> V_235 = V_359 ;
if ( V_38 < 0 )
return V_38 ;
V_256 = V_2 -> V_8 [ V_39 ] ;
V_80 = V_2 -> V_17 [ V_39 ] ;
if ( V_38 == 0 )
V_80 ++ ;
goto V_66;
}
if ( V_39 == 0 )
F_191 ( V_256 , V_86 , V_80 ) ;
else {
T_2 V_162 = F_82 ( V_256 , V_80 ) ;
if ( V_162 < V_322 ) {
V_80 ++ ;
goto V_66;
}
F_255 ( V_256 , V_86 , V_80 ) ;
}
return 0 ;
}
return 1 ;
}
int F_190 ( struct V_18 * V_19 , struct V_1 * V_2 )
{
return F_261 ( V_19 , V_2 , 0 ) ;
}
int F_261 ( struct V_18 * V_19 , struct V_1 * V_2 ,
T_2 V_134 )
{
int V_80 ;
int V_39 ;
struct V_14 * V_256 ;
struct V_14 * V_66 ;
struct V_155 V_86 ;
T_4 V_99 ;
int V_38 ;
int V_361 = V_2 -> V_243 ;
int V_362 = 0 ;
V_99 = F_90 ( V_2 -> V_8 [ 0 ] ) ;
if ( V_99 == 0 )
return 1 ;
F_191 ( V_2 -> V_8 [ 0 ] , & V_86 , V_99 - 1 ) ;
V_226:
V_39 = 1 ;
V_66 = NULL ;
V_362 = 0 ;
F_8 ( V_2 ) ;
V_2 -> V_219 = 1 ;
V_2 -> V_243 = 1 ;
if ( V_134 )
V_38 = F_198 ( V_19 , & V_86 , V_2 , V_134 ) ;
else
V_38 = F_189 ( NULL , V_19 , & V_86 , V_2 , 0 , 0 ) ;
V_2 -> V_219 = 0 ;
if ( V_38 < 0 )
return V_38 ;
V_99 = F_90 ( V_2 -> V_8 [ 0 ] ) ;
if ( V_99 > 0 && V_2 -> V_17 [ 0 ] < V_99 - 1 ) {
if ( V_38 == 0 )
V_2 -> V_17 [ 0 ] ++ ;
V_38 = 0 ;
goto V_227;
}
if ( V_99 > 0 && V_38 > 0 && V_2 -> V_17 [ 0 ] == V_99 - 1 ) {
V_38 = 0 ;
goto V_227;
}
while ( V_39 < V_7 ) {
if ( ! V_2 -> V_8 [ V_39 ] ) {
V_38 = 1 ;
goto V_227;
}
V_80 = V_2 -> V_17 [ V_39 ] + 1 ;
V_256 = V_2 -> V_8 [ V_39 ] ;
if ( V_80 >= F_90 ( V_256 ) ) {
V_39 ++ ;
if ( V_39 == V_7 ) {
V_38 = 1 ;
goto V_227;
}
continue;
}
if ( V_66 ) {
F_10 ( V_66 , V_362 ) ;
F_11 ( V_66 ) ;
}
V_66 = V_256 ;
V_362 = V_2 -> V_9 [ V_39 ] ;
V_38 = F_180 ( NULL , V_19 , V_2 , & V_66 , V_39 ,
V_80 , & V_86 , 0 ) ;
if ( V_38 == - V_222 )
goto V_226;
if ( V_38 < 0 ) {
F_8 ( V_2 ) ;
goto V_227;
}
if ( ! V_2 -> V_239 ) {
V_38 = F_262 ( V_66 ) ;
if ( ! V_38 && V_134 ) {
F_11 ( V_66 ) ;
F_8 ( V_2 ) ;
F_263 () ;
goto V_226;
}
if ( ! V_38 ) {
F_3 ( V_2 ) ;
F_22 ( V_66 ) ;
F_5 ( V_2 , V_66 ,
V_10 ) ;
}
V_362 = V_10 ;
}
break;
}
V_2 -> V_17 [ V_39 ] = V_80 ;
while ( 1 ) {
V_39 -- ;
V_256 = V_2 -> V_8 [ V_39 ] ;
if ( V_2 -> V_9 [ V_39 ] )
F_10 ( V_256 , V_2 -> V_9 [ V_39 ] ) ;
F_11 ( V_256 ) ;
V_2 -> V_8 [ V_39 ] = V_66 ;
V_2 -> V_17 [ V_39 ] = 0 ;
if ( ! V_2 -> V_239 )
V_2 -> V_9 [ V_39 ] = V_362 ;
if ( ! V_39 )
break;
V_38 = F_180 ( NULL , V_19 , V_2 , & V_66 , V_39 ,
0 , & V_86 , 0 ) ;
if ( V_38 == - V_222 )
goto V_226;
if ( V_38 < 0 ) {
F_8 ( V_2 ) ;
goto V_227;
}
if ( ! V_2 -> V_239 ) {
V_38 = F_262 ( V_66 ) ;
if ( ! V_38 ) {
F_3 ( V_2 ) ;
F_22 ( V_66 ) ;
F_5 ( V_2 , V_66 ,
V_10 ) ;
}
V_362 = V_10 ;
}
}
V_38 = 0 ;
V_227:
F_178 ( V_2 , 0 , 1 , 0 , NULL ) ;
V_2 -> V_243 = V_361 ;
if ( ! V_361 )
F_3 ( V_2 ) ;
return V_38 ;
}
int F_264 ( struct V_18 * V_19 ,
struct V_1 * V_2 , T_2 V_363 ,
int type )
{
struct V_155 V_233 ;
struct V_14 * V_173 ;
T_4 V_99 ;
int V_38 ;
while ( 1 ) {
if ( V_2 -> V_17 [ 0 ] == 0 ) {
F_3 ( V_2 ) ;
V_38 = F_200 ( V_19 , V_2 ) ;
if ( V_38 != 0 )
return V_38 ;
} else {
V_2 -> V_17 [ 0 ] -- ;
}
V_173 = V_2 -> V_8 [ 0 ] ;
V_99 = F_90 ( V_173 ) ;
if ( V_99 == 0 )
return 1 ;
if ( V_2 -> V_17 [ 0 ] == V_99 )
V_2 -> V_17 [ 0 ] -- ;
F_191 ( V_173 , & V_233 , V_2 -> V_17 [ 0 ] ) ;
if ( V_233 . V_28 < V_363 )
break;
if ( V_233 . type == type )
return 0 ;
if ( V_233 . V_28 == V_363 &&
V_233 . type < type )
break;
}
return 1 ;
}
int F_265 ( struct V_18 * V_19 ,
struct V_1 * V_2 , T_2 V_363 )
{
struct V_155 V_233 ;
struct V_14 * V_173 ;
T_4 V_99 ;
int V_38 ;
while ( 1 ) {
if ( V_2 -> V_17 [ 0 ] == 0 ) {
F_3 ( V_2 ) ;
V_38 = F_200 ( V_19 , V_2 ) ;
if ( V_38 != 0 )
return V_38 ;
} else {
V_2 -> V_17 [ 0 ] -- ;
}
V_173 = V_2 -> V_8 [ 0 ] ;
V_99 = F_90 ( V_173 ) ;
if ( V_99 == 0 )
return 1 ;
if ( V_2 -> V_17 [ 0 ] == V_99 )
V_2 -> V_17 [ 0 ] -- ;
F_191 ( V_173 , & V_233 , V_2 -> V_17 [ 0 ] ) ;
if ( V_233 . V_28 < V_363 )
break;
if ( V_233 . type == V_364 ||
V_233 . type == V_365 )
return 0 ;
if ( V_233 . V_28 == V_363 &&
V_233 . type < V_364 )
break;
}
return 1 ;
}
