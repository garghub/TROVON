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
V_129 = V_34 -> V_46 & ~ ( ( T_2 ) V_151 - 1 ) ;
if ( V_74 )
F_143 ( V_74 ) ;
F_143 ( V_34 ) ;
V_38 = F_111 ( V_33 , V_19 , V_34 , V_74 ,
V_128 , V_35 , V_129 , 0 ) ;
F_144 ( V_19 , V_34 , * V_35 ) ;
return V_38 ;
}
static int F_145 ( T_2 V_152 , T_2 V_153 , T_4 V_154 )
{
if ( V_152 < V_153 && V_153 - ( V_152 + V_154 ) < 32768 )
return 1 ;
if ( V_152 > V_153 && V_152 - ( V_153 + V_154 ) < 32768 )
return 1 ;
return 0 ;
}
static int F_146 ( struct V_40 * V_155 , struct V_156 * V_157 )
{
struct V_156 V_158 ;
F_147 ( & V_158 , V_155 ) ;
return F_148 ( & V_158 , V_157 ) ;
}
int F_148 ( struct V_156 * V_158 , struct V_156 * V_157 )
{
if ( V_158 -> V_28 > V_157 -> V_28 )
return 1 ;
if ( V_158 -> V_28 < V_157 -> V_28 )
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
int F_149 ( struct V_32 * V_33 ,
struct V_18 * V_19 , struct V_14 * V_74 ,
int V_160 , T_2 * V_161 ,
struct V_156 * V_162 )
{
struct V_14 * V_75 ;
T_2 V_152 ;
T_2 V_163 ;
T_2 V_129 = * V_161 ;
T_2 V_164 = 0 ;
T_2 V_153 ;
T_4 V_165 ;
int V_166 ;
int V_6 ;
int V_167 = 0 ;
int V_168 ;
int V_169 ;
T_4 V_154 ;
int V_170 = 0 ;
struct V_40 V_41 ;
V_168 = F_33 ( V_74 ) ;
F_32 ( V_33 -> V_149 != V_19 -> V_26 -> V_44 ) ;
F_32 ( V_33 -> V_43 != V_19 -> V_26 -> V_88 ) ;
V_165 = F_90 ( V_74 ) ;
V_154 = V_19 -> V_171 ;
V_166 = V_165 - 1 ;
if ( V_165 <= 1 )
return 0 ;
F_143 ( V_74 ) ;
for ( V_6 = V_160 ; V_6 <= V_166 ; V_6 ++ ) {
int V_172 = 1 ;
F_35 ( V_74 , & V_41 , V_6 ) ;
if ( ! V_170 && F_146 ( & V_41 , V_162 ) < 0 )
continue;
V_170 = 1 ;
V_152 = F_81 ( V_74 , V_6 ) ;
V_163 = F_82 ( V_74 , V_6 ) ;
if ( V_164 == 0 )
V_164 = V_152 ;
if ( V_6 > 0 ) {
V_153 = F_81 ( V_74 , V_6 - 1 ) ;
V_172 = F_145 ( V_152 , V_153 , V_154 ) ;
}
if ( ! V_172 && V_6 < V_166 ) {
V_153 = F_81 ( V_74 , V_6 + 1 ) ;
V_172 = F_145 ( V_152 , V_153 , V_154 ) ;
}
if ( V_172 ) {
V_164 = V_152 ;
continue;
}
V_75 = F_150 ( V_19 -> V_26 , V_152 ) ;
if ( V_75 )
V_169 = F_151 ( V_75 , V_163 , 0 ) ;
else
V_169 = 0 ;
if ( ! V_75 || ! V_169 ) {
if ( ! V_75 ) {
V_75 = F_134 ( V_19 , V_152 , V_163 ) ;
if ( F_37 ( V_75 ) ) {
return F_38 ( V_75 ) ;
} else if ( ! F_135 ( V_75 ) ) {
F_11 ( V_75 ) ;
return - V_173 ;
}
} else if ( ! V_169 ) {
V_167 = F_152 ( V_75 , V_163 ) ;
if ( V_167 ) {
F_11 ( V_75 ) ;
return V_167 ;
}
}
}
if ( V_129 == 0 )
V_129 = V_164 ;
F_19 ( V_75 ) ;
F_143 ( V_75 ) ;
V_167 = F_111 ( V_33 , V_19 , V_75 , V_74 , V_6 ,
& V_75 , V_129 ,
F_153 ( 16 * V_154 ,
( V_166 - V_6 ) * V_154 ) ) ;
if ( V_167 ) {
F_20 ( V_75 ) ;
F_11 ( V_75 ) ;
break;
}
V_129 = V_75 -> V_46 ;
V_164 = V_75 -> V_46 ;
* V_161 = V_129 ;
F_20 ( V_75 ) ;
F_11 ( V_75 ) ;
}
return V_167 ;
}
static inline unsigned int F_154 ( struct V_18 * V_19 ,
struct V_14 * V_174 )
{
T_4 V_175 = F_90 ( V_174 ) ;
if ( V_175 == 0 )
return F_155 ( V_19 ) ;
return F_156 ( V_174 , V_175 - 1 ) ;
}
static T_1 int F_157 ( struct V_14 * V_20 ,
unsigned long V_5 ,
int V_176 , struct V_156 * V_86 ,
int V_177 , int * V_80 )
{
int V_178 = 0 ;
int V_179 = V_177 ;
int V_180 ;
int V_38 ;
struct V_40 * V_181 = NULL ;
struct V_40 V_182 ;
unsigned long V_159 ;
char * V_183 = NULL ;
unsigned long V_184 = 0 ;
unsigned long V_185 = 0 ;
int V_167 ;
while ( V_178 < V_179 ) {
V_180 = ( V_178 + V_179 ) / 2 ;
V_159 = V_5 + V_180 * V_176 ;
if ( ! V_183 || V_159 < V_184 ||
( V_159 + sizeof( struct V_40 ) ) >
V_184 + V_185 ) {
V_167 = F_158 ( V_20 , V_159 ,
sizeof( struct V_40 ) ,
& V_183 , & V_184 , & V_185 ) ;
if ( ! V_167 ) {
V_181 = (struct V_40 * ) ( V_183 + V_159 -
V_184 ) ;
} else {
F_159 ( V_20 , & V_182 ,
V_159 , sizeof( V_182 ) ) ;
V_181 = & V_182 ;
}
} else {
V_181 = (struct V_40 * ) ( V_183 + V_159 -
V_184 ) ;
}
V_38 = F_146 ( V_181 , V_86 ) ;
if ( V_38 < 0 )
V_178 = V_180 + 1 ;
else if ( V_38 > 0 )
V_179 = V_180 ;
else {
* V_80 = V_180 ;
return 0 ;
}
}
* V_80 = V_178 ;
return 1 ;
}
static int F_160 ( struct V_14 * V_20 , struct V_156 * V_86 ,
int V_39 , int * V_80 )
{
if ( V_39 == 0 )
return F_157 ( V_20 ,
F_161 ( struct V_186 , V_187 ) ,
sizeof( struct V_188 ) ,
V_86 , F_90 ( V_20 ) ,
V_80 ) ;
else
return F_157 ( V_20 ,
F_161 ( struct V_189 , V_190 ) ,
sizeof( struct V_142 ) ,
V_86 , F_90 ( V_20 ) ,
V_80 ) ;
}
int F_162 ( struct V_14 * V_20 , struct V_156 * V_86 ,
int V_39 , int * V_80 )
{
return F_160 ( V_20 , V_86 , V_39 , V_80 ) ;
}
static void F_163 ( struct V_18 * V_19 , T_4 V_191 )
{
F_26 ( & V_19 -> V_192 ) ;
F_164 ( & V_19 -> V_121 ,
F_165 ( & V_19 -> V_121 ) + V_191 ) ;
F_30 ( & V_19 -> V_192 ) ;
}
static void F_166 ( struct V_18 * V_19 , T_4 V_191 )
{
F_26 ( & V_19 -> V_192 ) ;
F_164 ( & V_19 -> V_121 ,
F_165 ( & V_19 -> V_121 ) - V_191 ) ;
F_30 ( & V_19 -> V_192 ) ;
}
T_1 int F_167 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_39 )
{
struct V_14 * V_193 = NULL ;
struct V_14 * V_180 ;
struct V_14 * V_194 = NULL ;
struct V_14 * V_74 = NULL ;
int V_38 = 0 ;
int V_195 ;
int V_196 ;
int V_197 = V_2 -> V_17 [ V_39 ] ;
T_2 V_198 ;
if ( V_39 == 0 )
return 0 ;
V_180 = V_2 -> V_8 [ V_39 ] ;
F_32 ( V_2 -> V_9 [ V_39 ] != V_12 &&
V_2 -> V_9 [ V_39 ] != V_13 ) ;
F_32 ( F_48 ( V_180 ) != V_33 -> V_43 ) ;
V_198 = F_81 ( V_180 , V_197 ) ;
if ( V_39 < V_7 - 1 ) {
V_74 = V_2 -> V_8 [ V_39 + 1 ] ;
V_196 = V_2 -> V_17 [ V_39 + 1 ] ;
}
if ( ! V_74 ) {
struct V_14 * V_199 ;
if ( F_90 ( V_180 ) != 1 )
return 0 ;
V_199 = F_168 ( V_19 , V_180 , 0 ) ;
if ( ! V_199 ) {
V_38 = - V_125 ;
F_106 ( V_19 -> V_26 , V_38 , NULL ) ;
goto V_200;
}
F_19 ( V_199 ) ;
F_143 ( V_199 ) ;
V_38 = F_141 ( V_33 , V_19 , V_199 , V_180 , 0 , & V_199 ) ;
if ( V_38 ) {
F_20 ( V_199 ) ;
F_11 ( V_199 ) ;
goto V_200;
}
F_98 ( V_19 , V_199 , 1 ) ;
F_116 ( V_19 -> V_21 , V_199 ) ;
F_24 ( V_19 ) ;
F_20 ( V_199 ) ;
V_2 -> V_9 [ V_39 ] = 0 ;
V_2 -> V_8 [ V_39 ] = NULL ;
F_110 ( V_33 , V_19 -> V_26 , V_180 ) ;
F_20 ( V_180 ) ;
F_11 ( V_180 ) ;
F_166 ( V_19 , V_180 -> V_47 ) ;
F_117 ( V_33 , V_19 , V_180 , 0 , 1 ) ;
F_120 ( V_180 ) ;
return 0 ;
}
if ( F_90 ( V_180 ) >
F_132 ( V_19 ) / 4 )
return 0 ;
V_194 = F_168 ( V_19 , V_74 , V_196 - 1 ) ;
if ( V_194 ) {
F_19 ( V_194 ) ;
F_143 ( V_194 ) ;
V_195 = F_141 ( V_33 , V_19 , V_194 ,
V_74 , V_196 - 1 , & V_194 ) ;
if ( V_195 ) {
V_38 = V_195 ;
goto V_200;
}
}
V_193 = F_168 ( V_19 , V_74 , V_196 + 1 ) ;
if ( V_193 ) {
F_19 ( V_193 ) ;
F_143 ( V_193 ) ;
V_195 = F_141 ( V_33 , V_19 , V_193 ,
V_74 , V_196 + 1 , & V_193 ) ;
if ( V_195 ) {
V_38 = V_195 ;
goto V_200;
}
}
if ( V_194 ) {
V_197 += F_90 ( V_194 ) ;
V_195 = F_169 ( V_33 , V_19 , V_194 , V_180 , 1 ) ;
if ( V_195 < 0 )
V_38 = V_195 ;
}
if ( V_193 ) {
V_195 = F_169 ( V_33 , V_19 , V_180 , V_193 , 1 ) ;
if ( V_195 < 0 && V_195 != - V_201 )
V_38 = V_195 ;
if ( F_90 ( V_193 ) == 0 ) {
F_110 ( V_33 , V_19 -> V_26 , V_193 ) ;
F_20 ( V_193 ) ;
F_170 ( V_19 , V_2 , V_39 + 1 , V_196 + 1 ) ;
F_166 ( V_19 , V_193 -> V_47 ) ;
F_117 ( V_33 , V_19 , V_193 , 0 , 1 ) ;
F_120 ( V_193 ) ;
V_193 = NULL ;
} else {
struct V_40 V_202 ;
F_35 ( V_193 , & V_202 , 0 ) ;
F_96 ( V_19 -> V_26 , V_74 ,
V_196 + 1 , 0 ) ;
F_123 ( V_74 , & V_202 , V_196 + 1 ) ;
F_50 ( V_74 ) ;
}
}
if ( F_90 ( V_180 ) == 1 ) {
if ( ! V_194 ) {
V_38 = - V_125 ;
F_106 ( V_19 -> V_26 , V_38 , NULL ) ;
goto V_200;
}
V_195 = F_171 ( V_33 , V_19 , V_180 , V_194 ) ;
if ( V_195 < 0 ) {
V_38 = V_195 ;
goto V_200;
}
if ( V_195 == 1 ) {
V_195 = F_169 ( V_33 , V_19 , V_194 , V_180 , 1 ) ;
if ( V_195 < 0 )
V_38 = V_195 ;
}
F_72 ( V_195 == 1 ) ;
}
if ( F_90 ( V_180 ) == 0 ) {
F_110 ( V_33 , V_19 -> V_26 , V_180 ) ;
F_20 ( V_180 ) ;
F_170 ( V_19 , V_2 , V_39 + 1 , V_196 ) ;
F_166 ( V_19 , V_180 -> V_47 ) ;
F_117 ( V_33 , V_19 , V_180 , 0 , 1 ) ;
F_120 ( V_180 ) ;
V_180 = NULL ;
} else {
struct V_40 V_203 ;
F_35 ( V_180 , & V_203 , 0 ) ;
F_96 ( V_19 -> V_26 , V_74 ,
V_196 , 0 ) ;
F_123 ( V_74 , & V_203 , V_196 ) ;
F_50 ( V_74 ) ;
}
if ( V_194 ) {
if ( F_90 ( V_194 ) > V_197 ) {
F_115 ( V_194 ) ;
V_2 -> V_8 [ V_39 ] = V_194 ;
V_2 -> V_17 [ V_39 + 1 ] -= 1 ;
V_2 -> V_17 [ V_39 ] = V_197 ;
if ( V_180 ) {
F_20 ( V_180 ) ;
F_11 ( V_180 ) ;
}
} else {
V_197 -= F_90 ( V_194 ) ;
V_2 -> V_17 [ V_39 ] = V_197 ;
}
}
if ( V_198 !=
F_81 ( V_2 -> V_8 [ V_39 ] , V_2 -> V_17 [ V_39 ] ) )
F_172 () ;
V_200:
if ( V_193 ) {
F_20 ( V_193 ) ;
F_11 ( V_193 ) ;
}
if ( V_194 ) {
if ( V_2 -> V_8 [ V_39 ] != V_194 )
F_20 ( V_194 ) ;
F_11 ( V_194 ) ;
}
return V_38 ;
}
static T_1 int F_173 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_39 )
{
struct V_14 * V_193 = NULL ;
struct V_14 * V_180 ;
struct V_14 * V_194 = NULL ;
struct V_14 * V_74 = NULL ;
int V_38 = 0 ;
int V_195 ;
int V_196 ;
int V_197 = V_2 -> V_17 [ V_39 ] ;
if ( V_39 == 0 )
return 1 ;
V_180 = V_2 -> V_8 [ V_39 ] ;
F_32 ( F_48 ( V_180 ) != V_33 -> V_43 ) ;
if ( V_39 < V_7 - 1 ) {
V_74 = V_2 -> V_8 [ V_39 + 1 ] ;
V_196 = V_2 -> V_17 [ V_39 + 1 ] ;
}
if ( ! V_74 )
return 1 ;
V_194 = F_168 ( V_19 , V_74 , V_196 - 1 ) ;
if ( V_194 ) {
T_4 V_204 ;
F_19 ( V_194 ) ;
F_143 ( V_194 ) ;
V_204 = F_90 ( V_194 ) ;
if ( V_204 >= F_132 ( V_19 ) - 1 ) {
V_195 = 1 ;
} else {
V_38 = F_141 ( V_33 , V_19 , V_194 , V_74 ,
V_196 - 1 , & V_194 ) ;
if ( V_38 )
V_195 = 1 ;
else {
V_195 = F_169 ( V_33 , V_19 ,
V_194 , V_180 , 0 ) ;
}
}
if ( V_195 < 0 )
V_38 = V_195 ;
if ( V_195 == 0 ) {
struct V_40 V_41 ;
V_197 += V_204 ;
F_35 ( V_180 , & V_41 , 0 ) ;
F_96 ( V_19 -> V_26 , V_74 ,
V_196 , 0 ) ;
F_123 ( V_74 , & V_41 , V_196 ) ;
F_50 ( V_74 ) ;
if ( F_90 ( V_194 ) > V_197 ) {
V_2 -> V_8 [ V_39 ] = V_194 ;
V_2 -> V_17 [ V_39 + 1 ] -= 1 ;
V_2 -> V_17 [ V_39 ] = V_197 ;
F_20 ( V_180 ) ;
F_11 ( V_180 ) ;
} else {
V_197 -=
F_90 ( V_194 ) ;
V_2 -> V_17 [ V_39 ] = V_197 ;
F_20 ( V_194 ) ;
F_11 ( V_194 ) ;
}
return 0 ;
}
F_20 ( V_194 ) ;
F_11 ( V_194 ) ;
}
V_193 = F_168 ( V_19 , V_74 , V_196 + 1 ) ;
if ( V_193 ) {
T_4 V_205 ;
F_19 ( V_193 ) ;
F_143 ( V_193 ) ;
V_205 = F_90 ( V_193 ) ;
if ( V_205 >= F_132 ( V_19 ) - 1 ) {
V_195 = 1 ;
} else {
V_38 = F_141 ( V_33 , V_19 , V_193 ,
V_74 , V_196 + 1 ,
& V_193 ) ;
if ( V_38 )
V_195 = 1 ;
else {
V_195 = F_171 ( V_33 , V_19 ,
V_193 , V_180 ) ;
}
}
if ( V_195 < 0 )
V_38 = V_195 ;
if ( V_195 == 0 ) {
struct V_40 V_41 ;
F_35 ( V_193 , & V_41 , 0 ) ;
F_96 ( V_19 -> V_26 , V_74 ,
V_196 + 1 , 0 ) ;
F_123 ( V_74 , & V_41 , V_196 + 1 ) ;
F_50 ( V_74 ) ;
if ( F_90 ( V_180 ) <= V_197 ) {
V_2 -> V_8 [ V_39 ] = V_193 ;
V_2 -> V_17 [ V_39 + 1 ] += 1 ;
V_2 -> V_17 [ V_39 ] = V_197 -
F_90 ( V_180 ) ;
F_20 ( V_180 ) ;
F_11 ( V_180 ) ;
} else {
F_20 ( V_193 ) ;
F_11 ( V_193 ) ;
}
return 0 ;
}
F_20 ( V_193 ) ;
F_11 ( V_193 ) ;
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
T_2 V_206 ;
T_2 V_207 ;
T_2 V_208 = 0 ;
T_2 V_163 ;
struct V_14 * V_20 ;
T_4 V_175 ;
T_4 V_154 ;
T_4 V_209 = 0 ;
if ( V_39 != 1 )
return;
if ( ! V_2 -> V_8 [ V_39 ] )
return;
V_21 = V_2 -> V_8 [ V_39 ] ;
V_206 = F_81 ( V_21 , V_80 ) ;
V_154 = V_19 -> V_171 ;
V_20 = F_150 ( V_19 -> V_26 , V_206 ) ;
if ( V_20 ) {
F_11 ( V_20 ) ;
return;
}
V_207 = V_206 ;
V_99 = F_90 ( V_21 ) ;
V_175 = V_80 ;
while ( 1 ) {
if ( V_2 -> V_210 == V_211 ) {
if ( V_175 == 0 )
break;
V_175 -- ;
} else if ( V_2 -> V_210 == V_212 ) {
V_175 ++ ;
if ( V_175 >= V_99 )
break;
}
if ( V_2 -> V_210 == V_211 && V_28 ) {
F_35 ( V_21 , & V_41 , V_175 ) ;
if ( F_175 ( & V_41 ) != V_28 )
break;
}
V_206 = F_81 ( V_21 , V_175 ) ;
if ( ( V_206 <= V_207 && V_207 - V_206 <= 65536 ) ||
( V_206 > V_207 && V_206 - V_207 <= 65536 ) ) {
V_163 = F_82 ( V_21 , V_175 ) ;
F_176 ( V_19 , V_206 ) ;
V_208 += V_154 ;
}
V_209 ++ ;
if ( ( V_208 > 65536 || V_209 > 32 ) )
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
T_2 V_163 ;
T_2 V_213 = 0 ;
T_2 V_214 = 0 ;
V_74 = V_2 -> V_8 [ V_39 + 1 ] ;
if ( ! V_74 )
return;
V_99 = F_90 ( V_74 ) ;
V_80 = V_2 -> V_17 [ V_39 + 1 ] ;
if ( V_80 > 0 ) {
V_213 = F_81 ( V_74 , V_80 - 1 ) ;
V_163 = F_82 ( V_74 , V_80 - 1 ) ;
V_20 = F_150 ( V_19 -> V_26 , V_213 ) ;
if ( V_20 && F_151 ( V_20 , V_163 , 1 ) != 0 )
V_213 = 0 ;
F_11 ( V_20 ) ;
}
if ( V_80 + 1 < V_99 ) {
V_214 = F_81 ( V_74 , V_80 + 1 ) ;
V_163 = F_82 ( V_74 , V_80 + 1 ) ;
V_20 = F_150 ( V_19 -> V_26 , V_214 ) ;
if ( V_20 && F_151 ( V_20 , V_163 , 1 ) != 0 )
V_214 = 0 ;
F_11 ( V_20 ) ;
}
if ( V_213 )
F_176 ( V_19 , V_213 ) ;
if ( V_214 )
F_176 ( V_19 , V_214 ) ;
}
static T_1 void F_178 ( struct V_1 * V_2 , int V_39 ,
int V_215 , int V_216 ,
int * V_217 )
{
int V_6 ;
int V_218 = V_39 ;
int V_219 = 0 ;
struct V_14 * V_220 ;
for ( V_6 = V_39 ; V_6 < V_7 ; V_6 ++ ) {
if ( ! V_2 -> V_8 [ V_6 ] )
break;
if ( ! V_2 -> V_9 [ V_6 ] )
break;
if ( ! V_219 && V_2 -> V_17 [ V_6 ] == 0 ) {
V_218 = V_6 + 1 ;
continue;
}
if ( ! V_219 && V_2 -> V_221 ) {
T_4 V_99 ;
V_220 = V_2 -> V_8 [ V_6 ] ;
V_99 = F_90 ( V_220 ) ;
if ( V_99 < 1 || V_2 -> V_17 [ V_6 ] >= V_99 - 1 ) {
V_218 = V_6 + 1 ;
continue;
}
}
if ( V_218 < V_6 && V_6 >= V_215 )
V_219 = 1 ;
V_220 = V_2 -> V_8 [ V_6 ] ;
if ( V_6 >= V_215 && V_6 > V_218 && V_2 -> V_9 [ V_6 ] ) {
F_10 ( V_220 , V_2 -> V_9 [ V_6 ] ) ;
V_2 -> V_9 [ V_6 ] = 0 ;
if ( V_217 &&
V_6 > V_216 &&
V_6 <= * V_217 ) {
* V_217 = V_6 - 1 ;
}
}
}
}
T_1 void F_179 ( struct V_1 * V_2 , int V_39 )
{
int V_6 ;
if ( V_2 -> V_221 )
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
struct V_14 * * V_222 , int V_39 , int V_80 ,
struct V_156 * V_86 , T_2 V_134 )
{
T_2 V_152 ;
T_2 V_163 ;
struct V_14 * V_223 = * V_222 ;
struct V_14 * V_181 ;
int V_38 ;
V_152 = F_81 ( V_223 , V_80 ) ;
V_163 = F_82 ( V_223 , V_80 ) ;
V_181 = F_150 ( V_19 -> V_26 , V_152 ) ;
if ( V_181 ) {
if ( F_151 ( V_181 , V_163 , 1 ) > 0 ) {
* V_222 = V_181 ;
return 0 ;
}
F_3 ( V_5 ) ;
V_38 = F_152 ( V_181 , V_163 ) ;
if ( ! V_38 ) {
* V_222 = V_181 ;
return 0 ;
}
F_11 ( V_181 ) ;
F_8 ( V_5 ) ;
return - V_173 ;
}
F_179 ( V_5 , V_39 + 1 ) ;
F_3 ( V_5 ) ;
F_11 ( V_181 ) ;
if ( V_5 -> V_210 != V_224 )
F_174 ( V_19 , V_5 , V_39 , V_80 , V_86 -> V_28 ) ;
F_8 ( V_5 ) ;
V_38 = - V_225 ;
V_181 = F_134 ( V_19 , V_152 , 0 ) ;
if ( ! F_37 ( V_181 ) ) {
if ( ! F_151 ( V_181 , 0 , 0 ) )
V_38 = - V_173 ;
F_11 ( V_181 ) ;
}
return V_38 ;
}
static int
F_181 ( struct V_32 * V_33 ,
struct V_18 * V_19 , struct V_1 * V_5 ,
struct V_14 * V_223 , int V_39 , int V_226 ,
int * V_217 )
{
int V_38 ;
if ( ( V_5 -> V_227 || V_226 > 0 ) && F_90 ( V_223 ) >=
F_132 ( V_19 ) - 3 ) {
int V_228 ;
if ( * V_217 < V_39 + 1 ) {
* V_217 = V_39 + 1 ;
F_8 ( V_5 ) ;
goto V_229;
}
F_3 ( V_5 ) ;
F_177 ( V_19 , V_5 , V_39 ) ;
V_228 = F_182 ( V_33 , V_19 , V_5 , V_39 ) ;
F_5 ( V_5 , NULL , 0 ) ;
F_72 ( V_228 > 0 ) ;
if ( V_228 ) {
V_38 = V_228 ;
goto V_230;
}
V_223 = V_5 -> V_8 [ V_39 ] ;
} else if ( V_226 < 0 && F_90 ( V_223 ) <
F_132 ( V_19 ) / 2 ) {
int V_228 ;
if ( * V_217 < V_39 + 1 ) {
* V_217 = V_39 + 1 ;
F_8 ( V_5 ) ;
goto V_229;
}
F_3 ( V_5 ) ;
F_177 ( V_19 , V_5 , V_39 ) ;
V_228 = F_167 ( V_33 , V_19 , V_5 , V_39 ) ;
F_5 ( V_5 , NULL , 0 ) ;
if ( V_228 ) {
V_38 = V_228 ;
goto V_230;
}
V_223 = V_5 -> V_8 [ V_39 ] ;
if ( ! V_223 ) {
F_8 ( V_5 ) ;
goto V_229;
}
F_72 ( F_90 ( V_223 ) == 1 ) ;
}
return 0 ;
V_229:
V_38 = - V_225 ;
V_230:
return V_38 ;
}
static void F_183 ( struct V_14 * V_223 ,
struct V_156 * V_86 ,
int V_39 )
{
#ifdef F_184
struct V_40 V_41 ;
F_185 ( & V_41 , V_86 ) ;
if ( V_39 == 0 )
ASSERT ( ! F_186 ( V_223 , & V_41 ,
F_161 ( struct V_186 , V_187 [ 0 ] . V_86 ) ,
sizeof( V_41 ) ) ) ;
else
ASSERT ( ! F_186 ( V_223 , & V_41 ,
F_161 ( struct V_189 , V_190 [ 0 ] . V_86 ) ,
sizeof( V_41 ) ) ) ;
#endif
}
static int F_187 ( struct V_14 * V_223 , struct V_156 * V_86 ,
int V_39 , int * V_231 , int * V_80 )
{
if ( * V_231 != 0 ) {
* V_231 = F_160 ( V_223 , V_86 , V_39 , V_80 ) ;
return * V_231 ;
}
F_183 ( V_223 , V_86 , V_39 ) ;
* V_80 = 0 ;
return 0 ;
}
int F_188 ( struct V_18 * V_232 , struct V_1 * V_2 ,
T_2 V_233 , T_2 V_234 , T_5 V_235 ,
struct V_156 * V_236 )
{
int V_38 ;
struct V_156 V_86 ;
struct V_14 * V_20 ;
ASSERT ( V_2 ) ;
ASSERT ( V_236 ) ;
V_86 . type = V_235 ;
V_86 . V_28 = V_233 ;
V_86 . V_159 = V_234 ;
V_38 = F_189 ( NULL , V_232 , & V_86 , V_2 , 0 , 0 ) ;
if ( V_38 < 0 )
return V_38 ;
V_20 = V_2 -> V_8 [ 0 ] ;
if ( V_38 && V_2 -> V_17 [ 0 ] >= F_90 ( V_20 ) ) {
V_38 = F_190 ( V_232 , V_2 ) ;
if ( V_38 )
return V_38 ;
V_20 = V_2 -> V_8 [ 0 ] ;
}
F_191 ( V_20 , V_236 , V_2 -> V_17 [ 0 ] ) ;
if ( V_236 -> type != V_86 . type ||
V_236 -> V_28 != V_86 . V_28 )
return 1 ;
return 0 ;
}
int F_189 ( struct V_32 * V_33 , struct V_18
* V_19 , struct V_156 * V_86 , struct V_1 * V_5 , int
V_226 , int V_37 )
{
struct V_14 * V_223 ;
int V_80 ;
int V_38 ;
int V_167 ;
int V_39 ;
int V_215 = 1 ;
int V_237 ;
int V_217 = 0 ;
T_5 V_238 = 0 ;
int V_216 ;
int V_231 ;
V_238 = V_5 -> V_238 ;
F_32 ( V_238 && V_226 > 0 ) ;
F_32 ( V_5 -> V_8 [ 0 ] != NULL ) ;
F_72 ( ! V_37 && V_226 ) ;
if ( V_226 < 0 ) {
V_215 = 2 ;
V_217 = 2 ;
} else if ( V_226 > 0 ) {
V_217 = 1 ;
}
if ( ! V_37 )
V_217 = - 1 ;
if ( V_37 && ( V_5 -> V_221 || V_5 -> V_238 ) )
V_217 = V_7 ;
V_216 = V_217 ;
V_229:
V_231 = - 1 ;
V_237 = V_10 ;
V_39 = 0 ;
if ( V_5 -> V_239 ) {
if ( V_5 -> V_240 )
F_192 ( & V_19 -> V_26 -> V_241 ) ;
V_223 = V_19 -> V_120 ;
F_115 ( V_223 ) ;
V_39 = F_33 ( V_223 ) ;
if ( V_5 -> V_240 )
F_193 ( & V_19 -> V_26 -> V_241 ) ;
if ( ! V_5 -> V_242 )
F_22 ( V_223 ) ;
} else {
if ( V_5 -> V_242 ) {
V_223 = F_12 ( V_19 ) ;
V_39 = F_33 ( V_223 ) ;
} else {
V_223 = F_21 ( V_19 ) ;
V_39 = F_33 ( V_223 ) ;
if ( V_39 <= V_217 ) {
F_23 ( V_223 ) ;
F_11 ( V_223 ) ;
V_223 = F_18 ( V_19 ) ;
V_237 = V_12 ;
V_39 = F_33 ( V_223 ) ;
}
}
}
V_5 -> V_8 [ V_39 ] = V_223 ;
if ( ! V_5 -> V_242 )
V_5 -> V_9 [ V_39 ] = V_237 ;
while ( V_223 ) {
V_39 = F_33 ( V_223 ) ;
if ( V_37 ) {
if ( ! F_138 ( V_33 , V_19 , V_223 ) )
goto V_243;
if ( V_39 > V_217 ||
( V_39 + 1 > V_217 &&
V_39 + 1 < V_7 &&
V_5 -> V_8 [ V_39 + 1 ] ) ) {
V_217 = V_39 + 1 ;
F_8 ( V_5 ) ;
goto V_229;
}
F_3 ( V_5 ) ;
V_167 = F_141 ( V_33 , V_19 , V_223 ,
V_5 -> V_8 [ V_39 + 1 ] ,
V_5 -> V_17 [ V_39 + 1 ] , & V_223 ) ;
if ( V_167 ) {
V_38 = V_167 ;
goto V_230;
}
}
V_243:
V_5 -> V_8 [ V_39 ] = V_223 ;
F_5 ( V_5 , NULL , 0 ) ;
if ( ! V_226 && ! V_5 -> V_221 ) {
int V_244 = V_39 + 1 ;
if ( V_244 < V_7 && V_5 -> V_9 [ V_244 ] ) {
F_10 ( V_5 -> V_8 [ V_244 ] , V_5 -> V_9 [ V_244 ] ) ;
V_5 -> V_9 [ V_244 ] = 0 ;
}
}
V_38 = F_187 ( V_223 , V_86 , V_39 , & V_231 , & V_80 ) ;
if ( V_39 != 0 ) {
int V_245 = 0 ;
if ( V_38 && V_80 > 0 ) {
V_245 = 1 ;
V_80 -= 1 ;
}
V_5 -> V_17 [ V_39 ] = V_80 ;
V_167 = F_181 ( V_33 , V_19 , V_5 , V_223 , V_39 ,
V_226 , & V_217 ) ;
if ( V_167 == - V_225 )
goto V_229;
if ( V_167 ) {
V_38 = V_167 ;
goto V_230;
}
V_223 = V_5 -> V_8 [ V_39 ] ;
V_80 = V_5 -> V_17 [ V_39 ] ;
if ( V_80 == 0 && V_226 &&
V_217 < V_39 + 1 ) {
V_217 = V_39 + 1 ;
F_8 ( V_5 ) ;
goto V_229;
}
F_178 ( V_5 , V_39 , V_215 ,
V_216 , & V_217 ) ;
if ( V_39 == V_238 ) {
if ( V_245 )
V_5 -> V_17 [ V_39 ] ++ ;
goto V_230;
}
V_167 = F_180 ( V_33 , V_19 , V_5 ,
& V_223 , V_39 , V_80 , V_86 , 0 ) ;
if ( V_167 == - V_225 )
goto V_229;
if ( V_167 ) {
V_38 = V_167 ;
goto V_230;
}
if ( ! V_5 -> V_242 ) {
V_39 = F_33 ( V_223 ) ;
if ( V_39 <= V_217 ) {
V_167 = F_194 ( V_223 ) ;
if ( ! V_167 ) {
F_3 ( V_5 ) ;
F_19 ( V_223 ) ;
F_5 ( V_5 , V_223 ,
V_12 ) ;
}
V_5 -> V_9 [ V_39 ] = V_12 ;
} else {
V_167 = F_195 ( V_223 ) ;
if ( ! V_167 ) {
F_3 ( V_5 ) ;
F_22 ( V_223 ) ;
F_5 ( V_5 , V_223 ,
V_10 ) ;
}
V_5 -> V_9 [ V_39 ] = V_10 ;
}
V_5 -> V_8 [ V_39 ] = V_223 ;
}
} else {
V_5 -> V_17 [ V_39 ] = V_80 ;
if ( V_226 > 0 &&
F_196 ( V_19 , V_223 ) < V_226 ) {
if ( V_217 < 1 ) {
V_217 = 1 ;
F_8 ( V_5 ) ;
goto V_229;
}
F_3 ( V_5 ) ;
V_167 = F_197 ( V_33 , V_19 , V_86 ,
V_5 , V_226 , V_38 == 0 ) ;
F_5 ( V_5 , NULL , 0 ) ;
F_72 ( V_167 > 0 ) ;
if ( V_167 ) {
V_38 = V_167 ;
goto V_230;
}
}
if ( ! V_5 -> V_227 )
F_178 ( V_5 , V_39 , V_215 ,
V_216 , & V_217 ) ;
goto V_230;
}
}
V_38 = 1 ;
V_230:
if ( ! V_5 -> V_246 )
F_3 ( V_5 ) ;
if ( V_38 < 0 && ! V_5 -> V_247 )
F_8 ( V_5 ) ;
return V_38 ;
}
int F_198 ( struct V_18 * V_19 , struct V_156 * V_86 ,
struct V_1 * V_5 , T_2 V_134 )
{
struct V_14 * V_223 ;
int V_80 ;
int V_38 ;
int V_167 ;
int V_39 ;
int V_215 = 1 ;
T_5 V_238 = 0 ;
int V_231 = - 1 ;
V_238 = V_5 -> V_238 ;
F_32 ( V_5 -> V_8 [ 0 ] != NULL ) ;
if ( V_5 -> V_239 ) {
F_72 ( V_134 ) ;
return F_189 ( NULL , V_19 , V_86 , V_5 , 0 , 0 ) ;
}
V_229:
V_223 = F_133 ( V_19 , V_134 ) ;
V_39 = F_33 ( V_223 ) ;
V_5 -> V_9 [ V_39 ] = V_10 ;
while ( V_223 ) {
V_39 = F_33 ( V_223 ) ;
V_5 -> V_8 [ V_39 ] = V_223 ;
F_5 ( V_5 , NULL , 0 ) ;
F_179 ( V_5 , V_39 + 1 ) ;
V_231 = - 1 ;
V_38 = F_187 ( V_223 , V_86 , V_39 , & V_231 , & V_80 ) ;
if ( V_39 != 0 ) {
int V_245 = 0 ;
if ( V_38 && V_80 > 0 ) {
V_245 = 1 ;
V_80 -= 1 ;
}
V_5 -> V_17 [ V_39 ] = V_80 ;
F_178 ( V_5 , V_39 , V_215 , 0 , NULL ) ;
if ( V_39 == V_238 ) {
if ( V_245 )
V_5 -> V_17 [ V_39 ] ++ ;
goto V_230;
}
V_167 = F_180 ( NULL , V_19 , V_5 , & V_223 , V_39 ,
V_80 , V_86 , V_134 ) ;
if ( V_167 == - V_225 )
goto V_229;
if ( V_167 ) {
V_38 = V_167 ;
goto V_230;
}
V_39 = F_33 ( V_223 ) ;
V_167 = F_195 ( V_223 ) ;
if ( ! V_167 ) {
F_3 ( V_5 ) ;
F_22 ( V_223 ) ;
F_5 ( V_5 , V_223 ,
V_10 ) ;
}
V_223 = F_127 ( V_19 -> V_26 , V_5 , V_223 , V_134 ) ;
if ( ! V_223 ) {
V_38 = - V_89 ;
goto V_230;
}
V_5 -> V_9 [ V_39 ] = V_10 ;
V_5 -> V_8 [ V_39 ] = V_223 ;
} else {
V_5 -> V_17 [ V_39 ] = V_80 ;
F_178 ( V_5 , V_39 , V_215 , 0 , NULL ) ;
goto V_230;
}
}
V_38 = 1 ;
V_230:
if ( ! V_5 -> V_246 )
F_3 ( V_5 ) ;
if ( V_38 < 0 )
F_8 ( V_5 ) ;
return V_38 ;
}
int F_199 ( struct V_18 * V_19 ,
struct V_156 * V_86 , struct V_1 * V_5 ,
int V_248 , int V_249 )
{
int V_38 ;
struct V_14 * V_174 ;
V_229:
V_38 = F_189 ( NULL , V_19 , V_86 , V_5 , 0 , 0 ) ;
if ( V_38 <= 0 )
return V_38 ;
V_174 = V_5 -> V_8 [ 0 ] ;
if ( V_248 ) {
if ( V_5 -> V_17 [ 0 ] >= F_90 ( V_174 ) ) {
V_38 = F_190 ( V_19 , V_5 ) ;
if ( V_38 <= 0 )
return V_38 ;
if ( ! V_249 )
return 1 ;
V_249 = 0 ;
V_248 = 0 ;
F_8 ( V_5 ) ;
goto V_229;
}
} else {
if ( V_5 -> V_17 [ 0 ] == 0 ) {
V_38 = F_200 ( V_19 , V_5 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( ! V_38 ) {
V_174 = V_5 -> V_8 [ 0 ] ;
if ( V_5 -> V_17 [ 0 ] == F_90 ( V_174 ) )
V_5 -> V_17 [ 0 ] -- ;
return 0 ;
}
if ( ! V_249 )
return 1 ;
V_249 = 0 ;
V_248 = 1 ;
F_8 ( V_5 ) ;
goto V_229;
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
struct V_14 * V_220 ;
for ( V_6 = V_39 ; V_6 < V_7 ; V_6 ++ ) {
int V_250 = V_2 -> V_17 [ V_6 ] ;
if ( ! V_2 -> V_8 [ V_6 ] )
break;
V_220 = V_2 -> V_8 [ V_6 ] ;
F_96 ( V_26 , V_220 , V_250 , 1 ) ;
F_123 ( V_220 , V_86 , V_250 ) ;
F_50 ( V_2 -> V_8 [ V_6 ] ) ;
if ( V_250 != 0 )
break;
}
}
void F_202 ( struct V_54 * V_26 ,
struct V_1 * V_2 ,
struct V_156 * V_251 )
{
struct V_40 V_41 ;
struct V_14 * V_20 ;
int V_80 ;
V_20 = V_2 -> V_8 [ 0 ] ;
V_80 = V_2 -> V_17 [ 0 ] ;
if ( V_80 > 0 ) {
F_34 ( V_20 , & V_41 , V_80 - 1 ) ;
F_72 ( F_146 ( & V_41 , V_251 ) >= 0 ) ;
}
if ( V_80 < F_90 ( V_20 ) - 1 ) {
F_34 ( V_20 , & V_41 , V_80 + 1 ) ;
F_72 ( F_146 ( & V_41 , V_251 ) <= 0 ) ;
}
F_185 ( & V_41 , V_251 ) ;
F_203 ( V_20 , & V_41 , V_80 ) ;
F_50 ( V_20 ) ;
if ( V_80 == 0 )
F_201 ( V_26 , V_2 , & V_41 , 1 ) ;
}
static int F_169 ( struct V_32 * V_33 ,
struct V_18 * V_19 , struct V_14 * V_109 ,
struct V_14 * V_110 , int V_252 )
{
int V_253 = 0 ;
int V_254 ;
int V_255 ;
int V_38 = 0 ;
V_254 = F_90 ( V_110 ) ;
V_255 = F_90 ( V_109 ) ;
V_253 = F_132 ( V_19 ) - V_255 ;
F_32 ( F_48 ( V_110 ) != V_33 -> V_43 ) ;
F_32 ( F_48 ( V_109 ) != V_33 -> V_43 ) ;
if ( ! V_252 && V_254 <= 8 )
return 1 ;
if ( V_253 <= 0 )
return 1 ;
if ( V_252 ) {
V_253 = F_153 ( V_254 , V_253 ) ;
if ( V_253 < V_254 ) {
if ( V_254 - V_253 < 8 ) {
if ( V_253 <= 8 )
return 1 ;
V_253 -= 8 ;
}
}
} else
V_253 = F_153 ( V_254 - 8 , V_253 ) ;
V_38 = F_94 ( V_19 -> V_26 , V_109 , V_110 , V_255 , 0 ,
V_253 ) ;
if ( V_38 ) {
F_113 ( V_33 , V_19 , V_38 ) ;
return V_38 ;
}
F_39 ( V_109 , V_110 ,
F_124 ( V_255 ) ,
F_124 ( 0 ) ,
V_253 * sizeof( struct V_142 ) ) ;
if ( V_253 < V_254 ) {
F_125 ( V_110 , F_124 ( 0 ) ,
F_124 ( V_253 ) ,
( V_254 - V_253 ) *
sizeof( struct V_142 ) ) ;
}
F_126 ( V_110 , V_254 - V_253 ) ;
F_126 ( V_109 , V_255 + V_253 ) ;
F_50 ( V_110 ) ;
F_50 ( V_109 ) ;
return V_38 ;
}
static int F_171 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_14 * V_109 ,
struct V_14 * V_110 )
{
int V_253 = 0 ;
int V_256 ;
int V_254 ;
int V_255 ;
int V_38 = 0 ;
F_32 ( F_48 ( V_110 ) != V_33 -> V_43 ) ;
F_32 ( F_48 ( V_109 ) != V_33 -> V_43 ) ;
V_254 = F_90 ( V_110 ) ;
V_255 = F_90 ( V_109 ) ;
V_253 = F_132 ( V_19 ) - V_255 ;
if ( V_253 <= 0 )
return 1 ;
if ( V_254 < 4 )
return 1 ;
V_256 = V_254 / 2 + 1 ;
if ( V_256 >= V_254 )
return 1 ;
if ( V_256 < V_253 )
V_253 = V_256 ;
F_95 ( V_19 -> V_26 , V_109 , V_253 , 0 , V_255 ) ;
F_125 ( V_109 , F_124 ( V_253 ) ,
F_124 ( 0 ) ,
( V_255 ) *
sizeof( struct V_142 ) ) ;
V_38 = F_94 ( V_19 -> V_26 , V_109 , V_110 , 0 ,
V_254 - V_253 , V_253 ) ;
if ( V_38 ) {
F_113 ( V_33 , V_19 , V_38 ) ;
return V_38 ;
}
F_39 ( V_109 , V_110 ,
F_124 ( 0 ) ,
F_124 ( V_254 - V_253 ) ,
V_253 * sizeof( struct V_142 ) ) ;
F_126 ( V_110 , V_254 - V_253 ) ;
F_126 ( V_109 , V_255 + V_253 ) ;
F_50 ( V_110 ) ;
F_50 ( V_109 ) ;
return V_38 ;
}
static T_1 int F_204 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_39 )
{
T_2 V_257 ;
struct V_14 * V_258 ;
struct V_14 * V_259 ;
struct V_14 * V_145 ;
struct V_40 V_260 ;
F_72 ( V_2 -> V_8 [ V_39 ] ) ;
F_72 ( V_2 -> V_8 [ V_39 - 1 ] != V_19 -> V_21 ) ;
V_258 = V_2 -> V_8 [ V_39 - 1 ] ;
if ( V_39 == 1 )
F_34 ( V_258 , & V_260 , 0 ) ;
else
F_35 ( V_258 , & V_260 , 0 ) ;
V_259 = F_36 ( V_33 , V_19 , 0 , V_19 -> V_126 . V_28 ,
& V_260 , V_39 , V_19 -> V_21 -> V_46 , 0 ) ;
if ( F_37 ( V_259 ) )
return F_38 ( V_259 ) ;
F_163 ( V_19 , V_19 -> V_171 ) ;
F_205 ( V_259 , 0 , 0 , sizeof( struct V_261 ) ) ;
F_126 ( V_259 , 1 ) ;
F_130 ( V_259 , V_39 ) ;
F_40 ( V_259 , V_259 -> V_46 ) ;
F_41 ( V_259 , V_33 -> V_43 ) ;
F_42 ( V_259 , V_48 ) ;
F_45 ( V_259 , V_19 -> V_126 . V_28 ) ;
F_46 ( V_259 , V_19 -> V_26 -> V_52 , F_47 () ,
V_53 ) ;
F_46 ( V_259 , V_19 -> V_26 -> V_262 ,
F_206 ( V_259 ) , V_263 ) ;
F_123 ( V_259 , & V_260 , 0 ) ;
F_118 ( V_259 , 0 , V_258 -> V_46 ) ;
V_257 = F_48 ( V_258 ) ;
F_32 ( V_257 != V_33 -> V_43 ) ;
F_119 ( V_259 , 0 , V_257 ) ;
F_50 ( V_259 ) ;
V_145 = V_19 -> V_21 ;
F_98 ( V_19 , V_259 , 0 ) ;
F_116 ( V_19 -> V_21 , V_259 ) ;
F_11 ( V_145 ) ;
F_24 ( V_19 ) ;
F_115 ( V_259 ) ;
V_2 -> V_8 [ V_39 ] = V_259 ;
V_2 -> V_9 [ V_39 ] = V_13 ;
V_2 -> V_17 [ V_39 ] = 0 ;
return 0 ;
}
static void F_207 ( struct V_32 * V_33 ,
struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_40 * V_86 , T_2 V_264 ,
int V_80 , int V_39 )
{
struct V_14 * V_258 ;
int V_99 ;
int V_38 ;
F_72 ( ! V_2 -> V_8 [ V_39 ] ) ;
F_112 ( V_2 -> V_8 [ V_39 ] ) ;
V_258 = V_2 -> V_8 [ V_39 ] ;
V_99 = F_90 ( V_258 ) ;
F_72 ( V_80 > V_99 ) ;
F_72 ( V_99 == F_132 ( V_19 ) ) ;
if ( V_80 != V_99 ) {
if ( V_39 )
F_95 ( V_19 -> V_26 , V_258 , V_80 + 1 ,
V_80 , V_99 - V_80 ) ;
F_125 ( V_258 ,
F_124 ( V_80 + 1 ) ,
F_124 ( V_80 ) ,
( V_99 - V_80 ) * sizeof( struct V_142 ) ) ;
}
if ( V_39 ) {
V_38 = F_84 ( V_19 -> V_26 , V_258 , V_80 ,
V_85 , V_4 ) ;
F_72 ( V_38 < 0 ) ;
}
F_123 ( V_258 , V_86 , V_80 ) ;
F_118 ( V_258 , V_80 , V_264 ) ;
F_32 ( V_33 -> V_43 == 0 ) ;
F_119 ( V_258 , V_80 , V_33 -> V_43 ) ;
F_126 ( V_258 , V_99 + 1 ) ;
F_50 ( V_258 ) ;
}
static T_1 int F_182 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_39 )
{
struct V_14 * V_259 ;
struct V_14 * V_265 ;
struct V_40 V_41 ;
int V_180 ;
int V_38 ;
T_4 V_266 ;
V_259 = V_2 -> V_8 [ V_39 ] ;
F_32 ( F_48 ( V_259 ) != V_33 -> V_43 ) ;
if ( V_259 == V_19 -> V_21 ) {
V_38 = F_204 ( V_33 , V_19 , V_2 , V_39 + 1 ) ;
if ( V_38 )
return V_38 ;
} else {
V_38 = F_173 ( V_33 , V_19 , V_2 , V_39 ) ;
V_259 = V_2 -> V_8 [ V_39 ] ;
if ( ! V_38 && F_90 ( V_259 ) <
F_132 ( V_19 ) - 3 )
return 0 ;
if ( V_38 < 0 )
return V_38 ;
}
V_266 = F_90 ( V_259 ) ;
V_180 = ( V_266 + 1 ) / 2 ;
F_35 ( V_259 , & V_41 , V_180 ) ;
V_265 = F_36 ( V_33 , V_19 , 0 , V_19 -> V_126 . V_28 ,
& V_41 , V_39 , V_259 -> V_46 , 0 ) ;
if ( F_37 ( V_265 ) )
return F_38 ( V_265 ) ;
F_163 ( V_19 , V_19 -> V_171 ) ;
F_205 ( V_265 , 0 , 0 , sizeof( struct V_261 ) ) ;
F_130 ( V_265 , F_33 ( V_259 ) ) ;
F_40 ( V_265 , V_265 -> V_46 ) ;
F_41 ( V_265 , V_33 -> V_43 ) ;
F_42 ( V_265 , V_48 ) ;
F_45 ( V_265 , V_19 -> V_126 . V_28 ) ;
F_46 ( V_265 , V_19 -> V_26 -> V_52 ,
F_47 () , V_53 ) ;
F_46 ( V_265 , V_19 -> V_26 -> V_262 ,
F_206 ( V_265 ) ,
V_263 ) ;
V_38 = F_94 ( V_19 -> V_26 , V_265 , V_259 , 0 ,
V_180 , V_266 - V_180 ) ;
if ( V_38 ) {
F_113 ( V_33 , V_19 , V_38 ) ;
return V_38 ;
}
F_39 ( V_265 , V_259 ,
F_124 ( 0 ) ,
F_124 ( V_180 ) ,
( V_266 - V_180 ) * sizeof( struct V_142 ) ) ;
F_126 ( V_265 , V_266 - V_180 ) ;
F_126 ( V_259 , V_180 ) ;
V_38 = 0 ;
F_50 ( V_259 ) ;
F_50 ( V_265 ) ;
F_207 ( V_33 , V_19 , V_2 , & V_41 , V_265 -> V_46 ,
V_2 -> V_17 [ V_39 + 1 ] + 1 , V_39 + 1 ) ;
if ( V_2 -> V_17 [ V_39 ] >= V_180 ) {
V_2 -> V_17 [ V_39 ] -= V_180 ;
F_20 ( V_259 ) ;
F_11 ( V_259 ) ;
V_2 -> V_8 [ V_39 ] = V_265 ;
V_2 -> V_17 [ V_39 + 1 ] += 1 ;
} else {
F_20 ( V_265 ) ;
F_11 ( V_265 ) ;
}
return V_38 ;
}
static int F_208 ( struct V_14 * V_267 , int V_46 , int V_175 )
{
struct V_188 * V_268 ;
struct V_188 * V_269 ;
struct V_270 V_271 ;
int V_272 ;
int V_99 = F_90 ( V_267 ) ;
int V_273 = F_153 ( V_99 , V_46 + V_175 ) - 1 ;
if ( ! V_175 )
return 0 ;
F_209 ( & V_271 ) ;
V_268 = F_210 ( V_46 ) ;
V_269 = F_210 ( V_273 ) ;
V_272 = F_211 ( V_267 , V_268 , & V_271 ) +
F_212 ( V_267 , V_268 , & V_271 ) ;
V_272 = V_272 - F_211 ( V_267 , V_269 , & V_271 ) ;
V_272 += sizeof( struct V_188 ) * V_175 ;
F_32 ( V_272 < 0 ) ;
return V_272 ;
}
T_1 int F_196 ( struct V_18 * V_19 ,
struct V_14 * V_174 )
{
int V_99 = F_90 ( V_174 ) ;
int V_38 ;
V_38 = F_155 ( V_19 ) - F_208 ( V_174 , 0 , V_99 ) ;
if ( V_38 < 0 ) {
F_213 ( V_19 -> V_26 ,
L_3 ,
V_38 , ( unsigned long ) F_155 ( V_19 ) ,
F_208 ( V_174 , 0 , V_99 ) , V_99 ) ;
}
return V_38 ;
}
static T_1 int F_214 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
int V_274 , int V_252 ,
struct V_14 * V_193 ,
int V_275 , T_4 V_276 ,
T_4 V_277 )
{
struct V_14 * V_194 = V_2 -> V_8 [ 0 ] ;
struct V_14 * V_278 = V_2 -> V_8 [ 1 ] ;
struct V_270 V_271 ;
struct V_40 V_41 ;
int V_80 ;
T_4 V_6 ;
int V_279 = 0 ;
int V_253 = 0 ;
struct V_188 * V_280 ;
T_4 V_175 ;
T_4 V_281 ;
T_4 V_282 ;
T_4 V_283 ;
F_209 ( & V_271 ) ;
if ( V_252 )
V_175 = 0 ;
else
V_175 = F_215 ( T_4 , 1 , V_277 ) ;
if ( V_2 -> V_17 [ 0 ] >= V_276 )
V_279 += V_274 ;
V_80 = V_2 -> V_17 [ 1 ] ;
V_6 = V_276 - 1 ;
while ( V_6 >= V_175 ) {
V_280 = F_210 ( V_6 ) ;
if ( ! V_252 && V_253 > 0 ) {
if ( V_2 -> V_17 [ 0 ] > V_6 )
break;
if ( V_2 -> V_17 [ 0 ] == V_6 ) {
int V_284 = F_196 ( V_19 , V_194 ) ;
if ( V_284 + V_279 * 2 > V_275 )
break;
}
}
if ( V_2 -> V_17 [ 0 ] == V_6 )
V_279 += V_274 ;
V_283 = F_216 ( V_194 , V_280 ) ;
if ( V_283 + sizeof( * V_280 ) + V_279 > V_275 )
break;
V_253 ++ ;
V_279 += V_283 + sizeof( * V_280 ) ;
if ( V_6 == 0 )
break;
V_6 -- ;
}
if ( V_253 == 0 )
goto V_285;
F_32 ( ! V_252 && V_253 == V_276 ) ;
V_281 = F_90 ( V_193 ) ;
V_279 = F_217 ( V_194 , V_276 - V_253 ) ;
V_279 -= F_154 ( V_19 , V_194 ) ;
V_282 = F_154 ( V_19 , V_193 ) ;
F_125 ( V_193 ,
F_218 ( V_193 ) + V_282 - V_279 ,
F_218 ( V_193 ) + V_282 ,
F_155 ( V_19 ) - V_282 ) ;
F_39 ( V_193 , V_194 , F_218 ( V_193 ) +
F_155 ( V_19 ) - V_279 ,
F_218 ( V_194 ) + F_154 ( V_19 , V_194 ) ,
V_279 ) ;
F_125 ( V_193 , F_219 ( V_253 ) ,
F_219 ( 0 ) ,
V_281 * sizeof( struct V_188 ) ) ;
F_39 ( V_193 , V_194 , F_219 ( 0 ) ,
F_219 ( V_276 - V_253 ) ,
V_253 * sizeof( struct V_188 ) ) ;
V_281 += V_253 ;
F_126 ( V_193 , V_281 ) ;
V_279 = F_155 ( V_19 ) ;
for ( V_6 = 0 ; V_6 < V_281 ; V_6 ++ ) {
V_280 = F_210 ( V_6 ) ;
V_279 -= F_212 ( V_193 , V_280 , & V_271 ) ;
F_220 ( V_193 , V_280 , V_279 , & V_271 ) ;
}
V_276 -= V_253 ;
F_126 ( V_194 , V_276 ) ;
if ( V_276 )
F_50 ( V_194 ) ;
else
F_110 ( V_33 , V_19 -> V_26 , V_194 ) ;
F_50 ( V_193 ) ;
F_34 ( V_193 , & V_41 , 0 ) ;
F_123 ( V_278 , & V_41 , V_80 + 1 ) ;
F_50 ( V_278 ) ;
if ( V_2 -> V_17 [ 0 ] >= V_276 ) {
V_2 -> V_17 [ 0 ] -= V_276 ;
if ( F_90 ( V_2 -> V_8 [ 0 ] ) == 0 )
F_110 ( V_33 , V_19 -> V_26 , V_2 -> V_8 [ 0 ] ) ;
F_20 ( V_2 -> V_8 [ 0 ] ) ;
F_11 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_193 ;
V_2 -> V_17 [ 1 ] += 1 ;
} else {
F_20 ( V_193 ) ;
F_11 ( V_193 ) ;
}
return 0 ;
V_285:
F_20 ( V_193 ) ;
F_11 ( V_193 ) ;
return 1 ;
}
static int F_221 ( struct V_32 * V_33 , struct V_18
* V_19 , struct V_1 * V_2 ,
int V_286 , int V_274 ,
int V_252 , T_4 V_277 )
{
struct V_14 * V_194 = V_2 -> V_8 [ 0 ] ;
struct V_14 * V_193 ;
struct V_14 * V_278 ;
int V_80 ;
int V_275 ;
T_4 V_276 ;
int V_38 ;
if ( ! V_2 -> V_8 [ 1 ] )
return 1 ;
V_80 = V_2 -> V_17 [ 1 ] ;
V_278 = V_2 -> V_8 [ 1 ] ;
if ( V_80 >= F_90 ( V_278 ) - 1 )
return 1 ;
F_112 ( V_2 -> V_8 [ 1 ] ) ;
V_193 = F_168 ( V_19 , V_278 , V_80 + 1 ) ;
if ( V_193 == NULL )
return 1 ;
F_19 ( V_193 ) ;
F_143 ( V_193 ) ;
V_275 = F_196 ( V_19 , V_193 ) ;
if ( V_275 < V_274 )
goto V_285;
V_38 = F_141 ( V_33 , V_19 , V_193 , V_278 ,
V_80 + 1 , & V_193 ) ;
if ( V_38 )
goto V_285;
V_275 = F_196 ( V_19 , V_193 ) ;
if ( V_275 < V_274 )
goto V_285;
V_276 = F_90 ( V_194 ) ;
if ( V_276 == 0 )
goto V_285;
if ( V_2 -> V_17 [ 0 ] == V_276 && ! V_252 ) {
F_20 ( V_194 ) ;
F_11 ( V_194 ) ;
V_2 -> V_8 [ 0 ] = V_193 ;
V_2 -> V_17 [ 0 ] = 0 ;
V_2 -> V_17 [ 1 ] ++ ;
return 0 ;
}
return F_214 ( V_33 , V_19 , V_2 , V_286 , V_252 ,
V_193 , V_275 , V_276 , V_277 ) ;
V_285:
F_20 ( V_193 ) ;
F_11 ( V_193 ) ;
return 1 ;
}
static T_1 int F_222 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_274 ,
int V_252 , struct V_14 * V_194 ,
int V_275 , T_4 V_281 ,
T_4 V_287 )
{
struct V_40 V_41 ;
struct V_14 * V_193 = V_2 -> V_8 [ 0 ] ;
int V_6 ;
int V_279 = 0 ;
int V_253 = 0 ;
struct V_188 * V_280 ;
T_4 V_288 ;
T_4 V_175 ;
int V_38 = 0 ;
T_4 V_283 ;
T_4 V_289 ;
struct V_270 V_271 ;
F_209 ( & V_271 ) ;
if ( V_252 )
V_175 = F_153 ( V_281 , V_287 ) ;
else
V_175 = F_153 ( V_281 - 1 , V_287 ) ;
for ( V_6 = 0 ; V_6 < V_175 ; V_6 ++ ) {
V_280 = F_210 ( V_6 ) ;
if ( ! V_252 && V_253 > 0 ) {
if ( V_2 -> V_17 [ 0 ] < V_6 )
break;
if ( V_2 -> V_17 [ 0 ] == V_6 ) {
int V_284 = F_196 ( V_19 , V_193 ) ;
if ( V_284 + V_279 * 2 > V_275 )
break;
}
}
if ( V_2 -> V_17 [ 0 ] == V_6 )
V_279 += V_274 ;
V_283 = F_216 ( V_193 , V_280 ) ;
if ( V_283 + sizeof( * V_280 ) + V_279 > V_275 )
break;
V_253 ++ ;
V_279 += V_283 + sizeof( * V_280 ) ;
}
if ( V_253 == 0 ) {
V_38 = 1 ;
goto V_290;
}
F_32 ( ! V_252 && V_253 == F_90 ( V_193 ) ) ;
F_39 ( V_194 , V_193 ,
F_219 ( F_90 ( V_194 ) ) ,
F_219 ( 0 ) ,
V_253 * sizeof( struct V_188 ) ) ;
V_279 = F_155 ( V_19 ) -
F_156 ( V_193 , V_253 - 1 ) ;
F_39 ( V_194 , V_193 , F_218 ( V_194 ) +
F_154 ( V_19 , V_194 ) - V_279 ,
F_218 ( V_193 ) +
F_156 ( V_193 , V_253 - 1 ) ,
V_279 ) ;
V_288 = F_90 ( V_194 ) ;
F_72 ( V_288 <= 0 ) ;
V_289 = F_156 ( V_194 , V_288 - 1 ) ;
for ( V_6 = V_288 ; V_6 < V_288 + V_253 ; V_6 ++ ) {
T_4 V_234 ;
V_280 = F_210 ( V_6 ) ;
V_234 = F_211 ( V_194 , V_280 , & V_271 ) ;
F_220 ( V_194 , V_280 ,
V_234 - ( F_155 ( V_19 ) - V_289 ) ,
& V_271 ) ;
}
F_126 ( V_194 , V_288 + V_253 ) ;
if ( V_253 > V_281 )
F_142 ( 1 , V_150 L_4 , V_253 ,
V_281 ) ;
if ( V_253 < V_281 ) {
V_279 = F_156 ( V_193 , V_253 - 1 ) -
F_154 ( V_19 , V_193 ) ;
F_125 ( V_193 , F_218 ( V_193 ) +
F_155 ( V_19 ) - V_279 ,
F_218 ( V_193 ) +
F_154 ( V_19 , V_193 ) , V_279 ) ;
F_125 ( V_193 , F_219 ( 0 ) ,
F_219 ( V_253 ) ,
( F_90 ( V_193 ) - V_253 ) *
sizeof( struct V_188 ) ) ;
}
V_281 -= V_253 ;
F_126 ( V_193 , V_281 ) ;
V_279 = F_155 ( V_19 ) ;
for ( V_6 = 0 ; V_6 < V_281 ; V_6 ++ ) {
V_280 = F_210 ( V_6 ) ;
V_279 = V_279 - F_212 ( V_193 ,
V_280 , & V_271 ) ;
F_220 ( V_193 , V_280 , V_279 , & V_271 ) ;
}
F_50 ( V_194 ) ;
if ( V_281 )
F_50 ( V_193 ) ;
else
F_110 ( V_33 , V_19 -> V_26 , V_193 ) ;
F_34 ( V_193 , & V_41 , 0 ) ;
F_201 ( V_19 -> V_26 , V_2 , & V_41 , 1 ) ;
if ( V_2 -> V_17 [ 0 ] < V_253 ) {
V_2 -> V_17 [ 0 ] += V_288 ;
F_20 ( V_2 -> V_8 [ 0 ] ) ;
F_11 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_194 ;
V_2 -> V_17 [ 1 ] -= 1 ;
} else {
F_20 ( V_194 ) ;
F_11 ( V_194 ) ;
V_2 -> V_17 [ 0 ] -= V_253 ;
}
F_72 ( V_2 -> V_17 [ 0 ] < 0 ) ;
return V_38 ;
V_290:
F_20 ( V_194 ) ;
F_11 ( V_194 ) ;
return V_38 ;
}
static int F_223 ( struct V_32 * V_33 , struct V_18
* V_19 , struct V_1 * V_2 , int V_286 ,
int V_274 , int V_252 , T_4 V_287 )
{
struct V_14 * V_193 = V_2 -> V_8 [ 0 ] ;
struct V_14 * V_194 ;
int V_80 ;
int V_275 ;
T_4 V_281 ;
int V_38 = 0 ;
V_80 = V_2 -> V_17 [ 1 ] ;
if ( V_80 == 0 )
return 1 ;
if ( ! V_2 -> V_8 [ 1 ] )
return 1 ;
V_281 = F_90 ( V_193 ) ;
if ( V_281 == 0 )
return 1 ;
F_112 ( V_2 -> V_8 [ 1 ] ) ;
V_194 = F_168 ( V_19 , V_2 -> V_8 [ 1 ] , V_80 - 1 ) ;
if ( V_194 == NULL )
return 1 ;
F_19 ( V_194 ) ;
F_143 ( V_194 ) ;
V_275 = F_196 ( V_19 , V_194 ) ;
if ( V_275 < V_274 ) {
V_38 = 1 ;
goto V_290;
}
V_38 = F_141 ( V_33 , V_19 , V_194 ,
V_2 -> V_8 [ 1 ] , V_80 - 1 , & V_194 ) ;
if ( V_38 ) {
if ( V_38 == - V_201 )
V_38 = 1 ;
goto V_290;
}
V_275 = F_196 ( V_19 , V_194 ) ;
if ( V_275 < V_274 ) {
V_38 = 1 ;
goto V_290;
}
return F_222 ( V_33 , V_19 , V_2 , V_286 ,
V_252 , V_194 , V_275 , V_281 ,
V_287 ) ;
V_290:
F_20 ( V_194 ) ;
F_11 ( V_194 ) ;
return V_38 ;
}
static T_1 void F_224 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_14 * V_267 ,
struct V_14 * V_193 ,
int V_80 , int V_180 , int V_99 )
{
int V_291 ;
int V_292 ;
int V_6 ;
struct V_40 V_41 ;
struct V_270 V_271 ;
F_209 ( & V_271 ) ;
V_99 = V_99 - V_180 ;
F_126 ( V_193 , V_99 ) ;
V_291 = F_217 ( V_267 , V_180 ) - F_154 ( V_19 , V_267 ) ;
F_39 ( V_193 , V_267 , F_219 ( 0 ) ,
F_219 ( V_180 ) ,
V_99 * sizeof( struct V_188 ) ) ;
F_39 ( V_193 , V_267 ,
F_218 ( V_193 ) + F_155 ( V_19 ) -
V_291 , F_218 ( V_267 ) +
F_154 ( V_19 , V_267 ) , V_291 ) ;
V_292 = F_155 ( V_19 ) -
F_217 ( V_267 , V_180 ) ;
for ( V_6 = 0 ; V_6 < V_99 ; V_6 ++ ) {
struct V_188 * V_280 = F_210 ( V_6 ) ;
T_4 V_234 ;
V_234 = F_211 ( V_193 , V_280 , & V_271 ) ;
F_220 ( V_193 , V_280 ,
V_234 + V_292 , & V_271 ) ;
}
F_126 ( V_267 , V_180 ) ;
F_34 ( V_193 , & V_41 , 0 ) ;
F_207 ( V_33 , V_19 , V_2 , & V_41 , V_193 -> V_46 ,
V_2 -> V_17 [ 1 ] + 1 , 1 ) ;
F_50 ( V_193 ) ;
F_50 ( V_267 ) ;
F_72 ( V_2 -> V_17 [ 0 ] != V_80 ) ;
if ( V_180 <= V_80 ) {
F_20 ( V_2 -> V_8 [ 0 ] ) ;
F_11 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_193 ;
V_2 -> V_17 [ 0 ] -= V_180 ;
V_2 -> V_17 [ 1 ] += 1 ;
} else {
F_20 ( V_193 ) ;
F_11 ( V_193 ) ;
}
F_72 ( V_2 -> V_17 [ 0 ] < 0 ) ;
}
static T_1 int F_225 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
int V_274 )
{
int V_38 ;
int V_162 = 0 ;
int V_80 ;
T_4 V_99 ;
int V_293 = V_274 ;
V_80 = V_2 -> V_17 [ 0 ] ;
if ( V_80 < F_90 ( V_2 -> V_8 [ 0 ] ) )
V_293 -= F_196 ( V_19 , V_2 -> V_8 [ 0 ] ) ;
V_38 = F_221 ( V_33 , V_19 , V_2 , 1 , V_293 , 0 , V_80 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_38 == 0 )
V_162 ++ ;
V_99 = F_90 ( V_2 -> V_8 [ 0 ] ) ;
if ( V_2 -> V_17 [ 0 ] == 0 || V_2 -> V_17 [ 0 ] == V_99 )
return 0 ;
if ( F_196 ( V_19 , V_2 -> V_8 [ 0 ] ) >= V_274 )
return 0 ;
V_80 = V_2 -> V_17 [ 0 ] ;
V_38 = F_223 ( V_33 , V_19 , V_2 , 1 , V_293 , 0 , V_80 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_38 == 0 )
V_162 ++ ;
if ( V_162 )
return 0 ;
return 1 ;
}
static T_1 int F_197 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_156 * V_294 ,
struct V_1 * V_2 , int V_274 ,
int V_295 )
{
struct V_40 V_41 ;
struct V_14 * V_267 ;
T_4 V_99 ;
int V_180 ;
int V_80 ;
struct V_14 * V_193 ;
struct V_54 * V_26 = V_19 -> V_26 ;
int V_38 = 0 ;
int V_195 ;
int V_265 ;
int V_296 = 0 ;
int V_297 = 0 ;
V_267 = V_2 -> V_8 [ 0 ] ;
V_80 = V_2 -> V_17 [ 0 ] ;
if ( V_295 && V_274 + F_226 ( V_267 , V_80 ) +
sizeof( struct V_188 ) > F_155 ( V_19 ) )
return - V_298 ;
if ( V_274 && V_2 -> V_8 [ 1 ] ) {
int V_293 = V_274 ;
if ( V_80 < F_90 ( V_267 ) )
V_293 -= F_196 ( V_19 , V_267 ) ;
V_195 = F_221 ( V_33 , V_19 , V_2 , V_293 ,
V_293 , 0 , 0 ) ;
if ( V_195 < 0 )
return V_195 ;
if ( V_195 ) {
V_195 = F_223 ( V_33 , V_19 , V_2 , V_293 ,
V_293 , 0 , ( T_4 ) - 1 ) ;
if ( V_195 < 0 )
return V_195 ;
}
V_267 = V_2 -> V_8 [ 0 ] ;
if ( F_196 ( V_19 , V_267 ) >= V_274 )
return 0 ;
}
if ( ! V_2 -> V_8 [ 1 ] ) {
V_38 = F_204 ( V_33 , V_19 , V_2 , 1 ) ;
if ( V_38 )
return V_38 ;
}
V_229:
V_265 = 1 ;
V_267 = V_2 -> V_8 [ 0 ] ;
V_80 = V_2 -> V_17 [ 0 ] ;
V_99 = F_90 ( V_267 ) ;
V_180 = ( V_99 + 1 ) / 2 ;
if ( V_180 <= V_80 ) {
if ( V_99 == 1 ||
F_208 ( V_267 , V_180 , V_99 - V_180 ) + V_274 >
F_155 ( V_19 ) ) {
if ( V_80 >= V_99 ) {
V_265 = 0 ;
} else {
V_180 = V_80 ;
if ( V_180 != V_99 &&
F_208 ( V_267 , V_180 , V_99 - V_180 ) +
V_274 > F_155 ( V_19 ) ) {
if ( V_274 && ! V_297 )
goto V_299;
V_265 = 2 ;
}
}
}
} else {
if ( F_208 ( V_267 , 0 , V_180 ) + V_274 >
F_155 ( V_19 ) ) {
if ( ! V_295 && V_274 && V_80 == 0 ) {
V_265 = 0 ;
} else if ( ( V_295 || ! V_274 ) && V_80 == 0 ) {
V_180 = 1 ;
} else {
V_180 = V_80 ;
if ( V_180 != V_99 &&
F_208 ( V_267 , V_180 , V_99 - V_180 ) +
V_274 > F_155 ( V_19 ) ) {
if ( V_274 && ! V_297 )
goto V_299;
V_265 = 2 ;
}
}
}
}
if ( V_265 == 0 )
F_185 ( & V_41 , V_294 ) ;
else
F_34 ( V_267 , & V_41 , V_180 ) ;
V_193 = F_36 ( V_33 , V_19 , 0 , V_19 -> V_126 . V_28 ,
& V_41 , 0 , V_267 -> V_46 , 0 ) ;
if ( F_37 ( V_193 ) )
return F_38 ( V_193 ) ;
F_163 ( V_19 , V_19 -> V_171 ) ;
F_205 ( V_193 , 0 , 0 , sizeof( struct V_261 ) ) ;
F_40 ( V_193 , V_193 -> V_46 ) ;
F_41 ( V_193 , V_33 -> V_43 ) ;
F_42 ( V_193 , V_48 ) ;
F_45 ( V_193 , V_19 -> V_126 . V_28 ) ;
F_130 ( V_193 , 0 ) ;
F_46 ( V_193 , V_26 -> V_52 ,
F_47 () , V_53 ) ;
F_46 ( V_193 , V_26 -> V_262 ,
F_206 ( V_193 ) ,
V_263 ) ;
if ( V_265 == 0 ) {
if ( V_180 <= V_80 ) {
F_126 ( V_193 , 0 ) ;
F_207 ( V_33 , V_19 , V_2 , & V_41 , V_193 -> V_46 ,
V_2 -> V_17 [ 1 ] + 1 , 1 ) ;
F_20 ( V_2 -> V_8 [ 0 ] ) ;
F_11 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_193 ;
V_2 -> V_17 [ 0 ] = 0 ;
V_2 -> V_17 [ 1 ] += 1 ;
} else {
F_126 ( V_193 , 0 ) ;
F_207 ( V_33 , V_19 , V_2 , & V_41 , V_193 -> V_46 ,
V_2 -> V_17 [ 1 ] , 1 ) ;
F_20 ( V_2 -> V_8 [ 0 ] ) ;
F_11 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_193 ;
V_2 -> V_17 [ 0 ] = 0 ;
if ( V_2 -> V_17 [ 1 ] == 0 )
F_201 ( V_26 , V_2 , & V_41 , 1 ) ;
}
F_50 ( V_193 ) ;
return V_38 ;
}
F_224 ( V_33 , V_19 , V_2 , V_267 , V_193 , V_80 , V_180 , V_99 ) ;
if ( V_265 == 2 ) {
F_72 ( V_296 != 0 ) ;
V_296 ++ ;
goto V_229;
}
return 0 ;
V_299:
F_225 ( V_33 , V_19 , V_2 , V_274 ) ;
V_297 = 1 ;
if ( F_196 ( V_19 , V_2 -> V_8 [ 0 ] ) >= V_274 )
return 0 ;
goto V_229;
}
static T_1 int F_227 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_226 )
{
struct V_156 V_86 ;
struct V_14 * V_174 ;
struct V_300 * V_301 ;
T_2 V_302 = 0 ;
T_4 V_176 ;
int V_38 ;
V_174 = V_2 -> V_8 [ 0 ] ;
F_191 ( V_174 , & V_86 , V_2 -> V_17 [ 0 ] ) ;
F_72 ( V_86 . type != V_303 &&
V_86 . type != V_304 ) ;
if ( F_196 ( V_19 , V_174 ) >= V_226 )
return 0 ;
V_176 = F_226 ( V_174 , V_2 -> V_17 [ 0 ] ) ;
if ( V_86 . type == V_303 ) {
V_301 = F_228 ( V_174 , V_2 -> V_17 [ 0 ] ,
struct V_300 ) ;
V_302 = F_229 ( V_174 , V_301 ) ;
}
F_8 ( V_2 ) ;
V_2 -> V_221 = 1 ;
V_2 -> V_227 = 1 ;
V_38 = F_189 ( V_33 , V_19 , & V_86 , V_2 , 0 , 1 ) ;
V_2 -> V_227 = 0 ;
if ( V_38 > 0 )
V_38 = - V_225 ;
if ( V_38 < 0 )
goto V_167;
V_38 = - V_225 ;
V_174 = V_2 -> V_8 [ 0 ] ;
if ( V_176 != F_226 ( V_174 , V_2 -> V_17 [ 0 ] ) )
goto V_167;
if ( F_196 ( V_19 , V_2 -> V_8 [ 0 ] ) >= V_226 )
goto V_167;
if ( V_86 . type == V_303 ) {
V_301 = F_228 ( V_174 , V_2 -> V_17 [ 0 ] ,
struct V_300 ) ;
if ( V_302 != F_229 ( V_174 , V_301 ) )
goto V_167;
}
F_3 ( V_2 ) ;
V_38 = F_197 ( V_33 , V_19 , & V_86 , V_2 , V_226 , 1 ) ;
if ( V_38 )
goto V_167;
V_2 -> V_221 = 0 ;
F_179 ( V_2 , 1 ) ;
return 0 ;
V_167:
V_2 -> V_221 = 0 ;
return V_38 ;
}
static T_1 int F_230 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_156 * V_251 ,
unsigned long V_305 )
{
struct V_14 * V_174 ;
struct V_188 * V_280 ;
struct V_188 * V_306 ;
int V_80 ;
char * V_34 ;
T_4 V_99 ;
T_4 V_176 ;
T_4 V_307 ;
struct V_40 V_41 ;
V_174 = V_2 -> V_8 [ 0 ] ;
F_72 ( F_196 ( V_19 , V_174 ) < sizeof( struct V_188 ) ) ;
F_3 ( V_2 ) ;
V_280 = F_210 ( V_2 -> V_17 [ 0 ] ) ;
V_307 = F_231 ( V_174 , V_280 ) ;
V_176 = F_216 ( V_174 , V_280 ) ;
V_34 = F_232 ( V_176 , V_4 ) ;
if ( ! V_34 )
return - V_89 ;
F_159 ( V_174 , V_34 , F_233 ( V_174 ,
V_2 -> V_17 [ 0 ] ) , V_176 ) ;
V_80 = V_2 -> V_17 [ 0 ] + 1 ;
V_99 = F_90 ( V_174 ) ;
if ( V_80 != V_99 ) {
F_125 ( V_174 , F_219 ( V_80 + 1 ) ,
F_219 ( V_80 ) ,
( V_99 - V_80 ) * sizeof( struct V_188 ) ) ;
}
F_185 ( & V_41 , V_251 ) ;
F_203 ( V_174 , & V_41 , V_80 ) ;
V_306 = F_210 ( V_80 ) ;
F_234 ( V_174 , V_306 , V_307 ) ;
F_235 ( V_174 , V_306 , V_176 - V_305 ) ;
F_234 ( V_174 , V_280 ,
V_307 + V_176 - V_305 ) ;
F_235 ( V_174 , V_280 , V_305 ) ;
F_126 ( V_174 , V_99 + 1 ) ;
F_46 ( V_174 , V_34 ,
F_233 ( V_174 , V_2 -> V_17 [ 0 ] ) ,
V_305 ) ;
F_46 ( V_174 , V_34 + V_305 ,
F_233 ( V_174 , V_80 ) ,
V_176 - V_305 ) ;
F_50 ( V_174 ) ;
F_72 ( F_196 ( V_19 , V_174 ) < 0 ) ;
F_70 ( V_34 ) ;
return 0 ;
}
int F_236 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_156 * V_251 ,
unsigned long V_305 )
{
int V_38 ;
V_38 = F_227 ( V_33 , V_19 , V_2 ,
sizeof( struct V_188 ) ) ;
if ( V_38 )
return V_38 ;
V_38 = F_230 ( V_33 , V_19 , V_2 , V_251 , V_305 ) ;
return V_38 ;
}
int F_237 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_156 * V_251 )
{
struct V_14 * V_174 ;
int V_38 ;
T_4 V_176 ;
V_174 = V_2 -> V_8 [ 0 ] ;
V_176 = F_226 ( V_174 , V_2 -> V_17 [ 0 ] ) ;
V_38 = F_227 ( V_33 , V_19 , V_2 ,
V_176 + sizeof( struct V_188 ) ) ;
if ( V_38 )
return V_38 ;
V_2 -> V_17 [ 0 ] ++ ;
F_238 ( V_19 , V_2 , V_251 , & V_176 ,
V_176 , V_176 +
sizeof( struct V_188 ) , 1 ) ;
V_174 = V_2 -> V_8 [ 0 ] ;
F_239 ( V_174 ,
F_233 ( V_174 , V_2 -> V_17 [ 0 ] ) ,
F_233 ( V_174 , V_2 -> V_17 [ 0 ] - 1 ) ,
V_176 ) ;
return 0 ;
}
void F_240 ( struct V_18 * V_19 , struct V_1 * V_2 ,
T_4 V_308 , int V_309 )
{
int V_80 ;
struct V_14 * V_174 ;
struct V_188 * V_280 ;
T_4 V_99 ;
unsigned int V_282 ;
unsigned int V_310 ;
unsigned int V_311 ;
unsigned int V_312 ;
int V_6 ;
struct V_270 V_271 ;
F_209 ( & V_271 ) ;
V_174 = V_2 -> V_8 [ 0 ] ;
V_80 = V_2 -> V_17 [ 0 ] ;
V_311 = F_226 ( V_174 , V_80 ) ;
if ( V_311 == V_308 )
return;
V_99 = F_90 ( V_174 ) ;
V_282 = F_154 ( V_19 , V_174 ) ;
V_310 = F_156 ( V_174 , V_80 ) ;
V_312 = V_311 - V_308 ;
F_72 ( V_80 < 0 ) ;
F_72 ( V_80 >= V_99 ) ;
for ( V_6 = V_80 ; V_6 < V_99 ; V_6 ++ ) {
T_4 V_234 ;
V_280 = F_210 ( V_6 ) ;
V_234 = F_211 ( V_174 , V_280 , & V_271 ) ;
F_220 ( V_174 , V_280 ,
V_234 + V_312 , & V_271 ) ;
}
if ( V_309 ) {
F_125 ( V_174 , F_218 ( V_174 ) +
V_282 + V_312 , F_218 ( V_174 ) +
V_282 , V_310 + V_308 - V_282 ) ;
} else {
struct V_40 V_41 ;
T_2 V_159 ;
F_34 ( V_174 , & V_41 , V_80 ) ;
if ( F_241 ( & V_41 ) == V_303 ) {
unsigned long V_313 ;
struct V_300 * V_301 ;
V_301 = F_228 ( V_174 , V_80 ,
struct V_300 ) ;
V_301 = (struct V_300 * ) (
( unsigned long ) V_301 - V_312 ) ;
if ( F_242 ( V_174 , V_301 ) ==
V_314 ) {
V_313 = F_233 ( V_174 , V_80 ) ;
F_125 ( V_174 , V_313 ,
( unsigned long ) V_301 ,
V_315 ) ;
}
}
F_125 ( V_174 , F_218 ( V_174 ) +
V_282 + V_312 , F_218 ( V_174 ) +
V_282 , V_310 - V_282 ) ;
V_159 = F_243 ( & V_41 ) ;
F_244 ( & V_41 , V_159 + V_312 ) ;
F_203 ( V_174 , & V_41 , V_80 ) ;
if ( V_80 == 0 )
F_201 ( V_19 -> V_26 , V_2 , & V_41 , 1 ) ;
}
V_280 = F_210 ( V_80 ) ;
F_235 ( V_174 , V_280 , V_308 ) ;
F_50 ( V_174 ) ;
if ( F_196 ( V_19 , V_174 ) < 0 ) {
F_245 ( V_19 , V_174 ) ;
F_172 () ;
}
}
void F_246 ( struct V_18 * V_19 , struct V_1 * V_2 ,
T_4 V_274 )
{
int V_80 ;
struct V_14 * V_174 ;
struct V_188 * V_280 ;
T_4 V_99 ;
unsigned int V_282 ;
unsigned int V_316 ;
unsigned int V_311 ;
int V_6 ;
struct V_270 V_271 ;
F_209 ( & V_271 ) ;
V_174 = V_2 -> V_8 [ 0 ] ;
V_99 = F_90 ( V_174 ) ;
V_282 = F_154 ( V_19 , V_174 ) ;
if ( F_196 ( V_19 , V_174 ) < V_274 ) {
F_245 ( V_19 , V_174 ) ;
F_172 () ;
}
V_80 = V_2 -> V_17 [ 0 ] ;
V_316 = F_217 ( V_174 , V_80 ) ;
F_72 ( V_80 < 0 ) ;
if ( V_80 >= V_99 ) {
F_245 ( V_19 , V_174 ) ;
F_213 ( V_19 -> V_26 , L_5 ,
V_80 , V_99 ) ;
F_72 ( 1 ) ;
}
for ( V_6 = V_80 ; V_6 < V_99 ; V_6 ++ ) {
T_4 V_234 ;
V_280 = F_210 ( V_6 ) ;
V_234 = F_211 ( V_174 , V_280 , & V_271 ) ;
F_220 ( V_174 , V_280 ,
V_234 - V_274 , & V_271 ) ;
}
F_125 ( V_174 , F_218 ( V_174 ) +
V_282 - V_274 , F_218 ( V_174 ) +
V_282 , V_316 - V_282 ) ;
V_282 = V_316 ;
V_311 = F_226 ( V_174 , V_80 ) ;
V_280 = F_210 ( V_80 ) ;
F_235 ( V_174 , V_280 , V_311 + V_274 ) ;
F_50 ( V_174 ) ;
if ( F_196 ( V_19 , V_174 ) < 0 ) {
F_245 ( V_19 , V_174 ) ;
F_172 () ;
}
}
void F_238 ( struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_156 * V_317 , T_4 * V_274 ,
T_4 V_318 , T_4 V_319 , int V_175 )
{
struct V_188 * V_280 ;
int V_6 ;
T_4 V_99 ;
unsigned int V_282 ;
struct V_40 V_41 ;
struct V_14 * V_174 ;
int V_80 ;
struct V_270 V_271 ;
if ( V_2 -> V_17 [ 0 ] == 0 ) {
F_185 ( & V_41 , V_317 ) ;
F_201 ( V_19 -> V_26 , V_2 , & V_41 , 1 ) ;
}
F_179 ( V_2 , 1 ) ;
F_209 ( & V_271 ) ;
V_174 = V_2 -> V_8 [ 0 ] ;
V_80 = V_2 -> V_17 [ 0 ] ;
V_99 = F_90 ( V_174 ) ;
V_282 = F_154 ( V_19 , V_174 ) ;
if ( F_196 ( V_19 , V_174 ) < V_319 ) {
F_245 ( V_19 , V_174 ) ;
F_213 ( V_19 -> V_26 , L_6 ,
V_319 , F_196 ( V_19 , V_174 ) ) ;
F_172 () ;
}
if ( V_80 != V_99 ) {
unsigned int V_316 = F_217 ( V_174 , V_80 ) ;
if ( V_316 < V_282 ) {
F_245 ( V_19 , V_174 ) ;
F_213 ( V_19 -> V_26 , L_7 ,
V_80 , V_316 , V_282 ) ;
F_72 ( 1 ) ;
}
for ( V_6 = V_80 ; V_6 < V_99 ; V_6 ++ ) {
T_4 V_234 ;
V_280 = F_210 ( V_6 ) ;
V_234 = F_211 ( V_174 , V_280 , & V_271 ) ;
F_220 ( V_174 , V_280 ,
V_234 - V_318 , & V_271 ) ;
}
F_125 ( V_174 , F_219 ( V_80 + V_175 ) ,
F_219 ( V_80 ) ,
( V_99 - V_80 ) * sizeof( struct V_188 ) ) ;
F_125 ( V_174 , F_218 ( V_174 ) +
V_282 - V_318 , F_218 ( V_174 ) +
V_282 , V_316 - V_282 ) ;
V_282 = V_316 ;
}
for ( V_6 = 0 ; V_6 < V_175 ; V_6 ++ ) {
F_185 ( & V_41 , V_317 + V_6 ) ;
F_203 ( V_174 , & V_41 , V_80 + V_6 ) ;
V_280 = F_210 ( V_80 + V_6 ) ;
F_220 ( V_174 , V_280 ,
V_282 - V_274 [ V_6 ] , & V_271 ) ;
V_282 -= V_274 [ V_6 ] ;
F_247 ( V_174 , V_280 , V_274 [ V_6 ] , & V_271 ) ;
}
F_126 ( V_174 , V_99 + V_175 ) ;
F_50 ( V_174 ) ;
if ( F_196 ( V_19 , V_174 ) < 0 ) {
F_245 ( V_19 , V_174 ) ;
F_172 () ;
}
}
int F_248 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_156 * V_317 , T_4 * V_274 ,
int V_175 )
{
int V_38 = 0 ;
int V_80 ;
int V_6 ;
T_4 V_319 = 0 ;
T_4 V_318 = 0 ;
for ( V_6 = 0 ; V_6 < V_175 ; V_6 ++ )
V_318 += V_274 [ V_6 ] ;
V_319 = V_318 + ( V_175 * sizeof( struct V_188 ) ) ;
V_38 = F_189 ( V_33 , V_19 , V_317 , V_2 , V_319 , 1 ) ;
if ( V_38 == 0 )
return - V_79 ;
if ( V_38 < 0 )
return V_38 ;
V_80 = V_2 -> V_17 [ 0 ] ;
F_72 ( V_80 < 0 ) ;
F_238 ( V_19 , V_2 , V_317 , V_274 ,
V_318 , V_319 , V_175 ) ;
return 0 ;
}
int F_249 ( struct V_32 * V_33 , struct V_18
* V_19 , struct V_156 * V_317 , void * V_320 , T_4
V_274 )
{
int V_38 = 0 ;
struct V_1 * V_2 ;
struct V_14 * V_174 ;
unsigned long V_313 ;
V_2 = F_1 () ;
if ( ! V_2 )
return - V_89 ;
V_38 = F_250 ( V_33 , V_19 , V_2 , V_317 , V_274 ) ;
if ( ! V_38 ) {
V_174 = V_2 -> V_8 [ 0 ] ;
V_313 = F_233 ( V_174 , V_2 -> V_17 [ 0 ] ) ;
F_46 ( V_174 , V_320 , V_313 , V_274 ) ;
F_50 ( V_174 ) ;
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
struct V_14 * V_174 )
{
F_32 ( F_48 ( V_174 ) != V_33 -> V_43 ) ;
F_170 ( V_19 , V_2 , 1 , V_2 -> V_17 [ 1 ] ) ;
F_179 ( V_2 , 0 ) ;
F_166 ( V_19 , V_174 -> V_47 ) ;
F_115 ( V_174 ) ;
F_117 ( V_33 , V_19 , V_174 , 0 , 1 ) ;
F_120 ( V_174 ) ;
}
int F_252 ( struct V_32 * V_33 , struct V_18 * V_19 ,
struct V_1 * V_2 , int V_80 , int V_175 )
{
struct V_14 * V_174 ;
struct V_188 * V_280 ;
T_4 V_321 ;
T_4 V_322 = 0 ;
int V_38 = 0 ;
int V_195 ;
int V_6 ;
T_4 V_99 ;
struct V_270 V_271 ;
F_209 ( & V_271 ) ;
V_174 = V_2 -> V_8 [ 0 ] ;
V_321 = F_156 ( V_174 , V_80 + V_175 - 1 ) ;
for ( V_6 = 0 ; V_6 < V_175 ; V_6 ++ )
V_322 += F_226 ( V_174 , V_80 + V_6 ) ;
V_99 = F_90 ( V_174 ) ;
if ( V_80 + V_175 != V_99 ) {
int V_282 = F_154 ( V_19 , V_174 ) ;
F_125 ( V_174 , F_218 ( V_174 ) +
V_282 + V_322 ,
F_218 ( V_174 ) + V_282 ,
V_321 - V_282 ) ;
for ( V_6 = V_80 + V_175 ; V_6 < V_99 ; V_6 ++ ) {
T_4 V_234 ;
V_280 = F_210 ( V_6 ) ;
V_234 = F_211 ( V_174 , V_280 , & V_271 ) ;
F_220 ( V_174 , V_280 ,
V_234 + V_322 , & V_271 ) ;
}
F_125 ( V_174 , F_219 ( V_80 ) ,
F_219 ( V_80 + V_175 ) ,
sizeof( struct V_188 ) *
( V_99 - V_80 - V_175 ) ) ;
}
F_126 ( V_174 , V_99 - V_175 ) ;
V_99 -= V_175 ;
if ( V_99 == 0 ) {
if ( V_174 == V_19 -> V_21 ) {
F_130 ( V_174 , 0 ) ;
} else {
F_3 ( V_2 ) ;
F_110 ( V_33 , V_19 -> V_26 , V_174 ) ;
F_251 ( V_33 , V_19 , V_2 , V_174 ) ;
}
} else {
int V_323 = F_208 ( V_174 , 0 , V_99 ) ;
if ( V_80 == 0 ) {
struct V_40 V_41 ;
F_34 ( V_174 , & V_41 , 0 ) ;
F_201 ( V_19 -> V_26 , V_2 , & V_41 , 1 ) ;
}
if ( V_323 < F_155 ( V_19 ) / 3 ) {
V_80 = V_2 -> V_17 [ 1 ] ;
F_115 ( V_174 ) ;
F_3 ( V_2 ) ;
V_195 = F_223 ( V_33 , V_19 , V_2 , 1 , 1 ,
1 , ( T_4 ) - 1 ) ;
if ( V_195 < 0 && V_195 != - V_201 )
V_38 = V_195 ;
if ( V_2 -> V_8 [ 0 ] == V_174 &&
F_90 ( V_174 ) ) {
V_195 = F_221 ( V_33 , V_19 , V_2 , 1 ,
1 , 1 , 0 ) ;
if ( V_195 < 0 && V_195 != - V_201 )
V_38 = V_195 ;
}
if ( F_90 ( V_174 ) == 0 ) {
V_2 -> V_17 [ 1 ] = V_80 ;
F_251 ( V_33 , V_19 , V_2 , V_174 ) ;
F_11 ( V_174 ) ;
V_38 = 0 ;
} else {
if ( V_2 -> V_8 [ 0 ] == V_174 )
F_50 ( V_174 ) ;
F_11 ( V_174 ) ;
}
} else {
F_50 ( V_174 ) ;
}
}
return V_38 ;
}
int F_200 ( struct V_18 * V_19 , struct V_1 * V_2 )
{
struct V_156 V_86 ;
struct V_40 V_236 ;
int V_38 ;
F_191 ( V_2 -> V_8 [ 0 ] , & V_86 , 0 ) ;
if ( V_86 . V_159 > 0 ) {
V_86 . V_159 -- ;
} else if ( V_86 . type > 0 ) {
V_86 . type -- ;
V_86 . V_159 = ( T_2 ) - 1 ;
} else if ( V_86 . V_28 > 0 ) {
V_86 . V_28 -- ;
V_86 . type = ( T_5 ) - 1 ;
V_86 . V_159 = ( T_2 ) - 1 ;
} else {
return 1 ;
}
F_8 ( V_2 ) ;
V_38 = F_189 ( NULL , V_19 , & V_86 , V_2 , 0 , 0 ) ;
if ( V_38 < 0 )
return V_38 ;
F_34 ( V_2 -> V_8 [ 0 ] , & V_236 , 0 ) ;
V_38 = F_146 ( & V_236 , & V_86 ) ;
if ( V_38 <= 0 )
return 0 ;
return 1 ;
}
int F_253 ( struct V_18 * V_19 , struct V_156 * V_324 ,
struct V_1 * V_2 ,
T_2 V_325 )
{
struct V_14 * V_75 ;
struct V_156 V_236 ;
int V_80 ;
int V_228 ;
T_4 V_99 ;
int V_39 ;
int V_38 = 1 ;
int V_221 = V_2 -> V_221 ;
V_2 -> V_221 = 1 ;
V_229:
V_75 = F_21 ( V_19 ) ;
V_39 = F_33 ( V_75 ) ;
F_32 ( V_2 -> V_8 [ V_39 ] ) ;
V_2 -> V_8 [ V_39 ] = V_75 ;
V_2 -> V_9 [ V_39 ] = V_10 ;
if ( F_48 ( V_75 ) < V_325 ) {
V_38 = 1 ;
goto V_290;
}
while ( 1 ) {
V_99 = F_90 ( V_75 ) ;
V_39 = F_33 ( V_75 ) ;
V_228 = F_160 ( V_75 , V_324 , V_39 , & V_80 ) ;
if ( V_39 == V_2 -> V_238 ) {
if ( V_80 >= V_99 )
goto V_326;
V_38 = 0 ;
V_2 -> V_17 [ V_39 ] = V_80 ;
F_191 ( V_75 , & V_236 , V_80 ) ;
goto V_290;
}
if ( V_228 && V_80 > 0 )
V_80 -- ;
while ( V_80 < V_99 ) {
T_2 V_163 ;
V_163 = F_82 ( V_75 , V_80 ) ;
if ( V_163 < V_325 ) {
V_80 ++ ;
continue;
}
break;
}
V_326:
if ( V_80 >= V_99 ) {
V_2 -> V_17 [ V_39 ] = V_80 ;
F_3 ( V_2 ) ;
V_228 = F_254 ( V_19 , V_2 , V_324 , V_39 ,
V_325 ) ;
if ( V_228 == 0 ) {
F_8 ( V_2 ) ;
goto V_229;
} else {
goto V_290;
}
}
F_255 ( V_75 , & V_236 , V_80 ) ;
V_2 -> V_17 [ V_39 ] = V_80 ;
if ( V_39 == V_2 -> V_238 ) {
V_38 = 0 ;
goto V_290;
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
V_290:
V_2 -> V_221 = V_221 ;
if ( V_38 == 0 ) {
F_179 ( V_2 , V_2 -> V_238 + 1 ) ;
F_3 ( V_2 ) ;
memcpy ( V_324 , & V_236 , sizeof( V_236 ) ) ;
}
return V_38 ;
}
static void F_256 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int * V_39 , int V_327 )
{
F_72 ( * V_39 == 0 ) ;
V_2 -> V_8 [ * V_39 - 1 ] = F_168 ( V_19 , V_2 -> V_8 [ * V_39 ] ,
V_2 -> V_17 [ * V_39 ] ) ;
V_2 -> V_17 [ * V_39 - 1 ] = 0 ;
( * V_39 ) -- ;
}
static int F_257 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int * V_39 , int V_327 )
{
int V_38 = 0 ;
int V_99 ;
V_99 = F_90 ( V_2 -> V_8 [ * V_39 ] ) ;
V_2 -> V_17 [ * V_39 ] ++ ;
while ( V_2 -> V_17 [ * V_39 ] >= V_99 ) {
if ( * V_39 == V_327 )
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
int * V_39 , int V_327 ,
int V_328 ,
struct V_156 * V_86 )
{
int V_38 ;
if ( * V_39 == 0 || ! V_328 ) {
V_38 = F_257 ( V_19 , V_2 , V_39 , V_327 ) ;
} else {
F_256 ( V_19 , V_2 , V_39 , V_327 ) ;
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
static int F_259 ( struct V_18 * V_329 ,
struct V_1 * V_330 ,
struct V_1 * V_331 ,
char * V_332 )
{
int V_333 ;
int V_334 , V_335 ;
unsigned long V_336 , V_337 ;
V_334 = F_226 ( V_330 -> V_8 [ 0 ] , V_330 -> V_17 [ 0 ] ) ;
V_335 = F_226 ( V_331 -> V_8 [ 0 ] , V_331 -> V_17 [ 0 ] ) ;
if ( V_334 != V_335 )
return 1 ;
V_336 = F_233 ( V_330 -> V_8 [ 0 ] , V_330 -> V_17 [ 0 ] ) ;
V_337 = F_233 ( V_331 -> V_8 [ 0 ] ,
V_331 -> V_17 [ 0 ] ) ;
F_159 ( V_330 -> V_8 [ 0 ] , V_332 , V_336 , V_334 ) ;
V_333 = F_186 ( V_331 -> V_8 [ 0 ] , V_332 , V_337 , V_334 ) ;
if ( V_333 )
return 1 ;
return 0 ;
}
int F_260 ( struct V_18 * V_329 ,
struct V_18 * V_338 ,
T_6 V_339 , void * V_340 )
{
int V_38 ;
int V_333 ;
struct V_1 * V_330 = NULL ;
struct V_1 * V_331 = NULL ;
struct V_156 V_341 ;
struct V_156 V_202 ;
char * V_332 = NULL ;
int V_342 ;
int V_343 ;
int V_344 ;
int V_345 ;
int V_346 ;
int V_347 ;
int V_348 ;
int V_349 ;
T_2 V_350 ;
T_2 V_351 ;
T_2 V_352 ;
T_2 V_353 ;
V_330 = F_1 () ;
if ( ! V_330 ) {
V_38 = - V_89 ;
goto V_290;
}
V_331 = F_1 () ;
if ( ! V_331 ) {
V_38 = - V_89 ;
goto V_290;
}
V_332 = F_232 ( V_329 -> V_171 , V_4 ) ;
if ( ! V_332 ) {
V_38 = - V_89 ;
goto V_290;
}
V_330 -> V_239 = 1 ;
V_330 -> V_242 = 1 ;
V_331 -> V_239 = 1 ;
V_331 -> V_242 = 1 ;
F_192 ( & V_329 -> V_26 -> V_241 ) ;
V_344 = F_33 ( V_329 -> V_120 ) ;
V_342 = V_344 ;
V_330 -> V_8 [ V_344 ] = V_329 -> V_120 ;
F_115 ( V_330 -> V_8 [ V_344 ] ) ;
V_345 = F_33 ( V_338 -> V_120 ) ;
V_343 = V_345 ;
V_331 -> V_8 [ V_345 ] = V_338 -> V_120 ;
F_115 ( V_331 -> V_8 [ V_345 ] ) ;
F_193 ( & V_329 -> V_26 -> V_241 ) ;
if ( V_344 == 0 )
F_191 ( V_330 -> V_8 [ V_344 ] ,
& V_341 , V_330 -> V_17 [ V_344 ] ) ;
else
F_255 ( V_330 -> V_8 [ V_344 ] ,
& V_341 , V_330 -> V_17 [ V_344 ] ) ;
if ( V_345 == 0 )
F_191 ( V_331 -> V_8 [ V_345 ] ,
& V_202 , V_331 -> V_17 [ V_345 ] ) ;
else
F_255 ( V_331 -> V_8 [ V_345 ] ,
& V_202 , V_331 -> V_17 [ V_345 ] ) ;
V_346 = V_347 = 0 ;
V_348 = V_349 = 0 ;
while ( 1 ) {
if ( V_348 && ! V_346 ) {
V_38 = F_258 ( V_329 , V_330 , & V_344 ,
V_342 ,
V_348 != V_354 ,
& V_341 ) ;
if ( V_38 < 0 )
V_346 = V_355 ;
V_348 = 0 ;
}
if ( V_349 && ! V_347 ) {
V_38 = F_258 ( V_338 , V_331 , & V_345 ,
V_343 ,
V_349 != V_354 ,
& V_202 ) ;
if ( V_38 < 0 )
V_347 = V_355 ;
V_349 = 0 ;
}
if ( V_346 && V_347 ) {
V_38 = 0 ;
goto V_290;
} else if ( V_346 ) {
if ( V_345 == 0 ) {
V_38 = V_339 ( V_329 , V_338 ,
V_330 , V_331 ,
& V_202 ,
V_356 ,
V_340 ) ;
if ( V_38 < 0 )
goto V_290;
}
V_349 = V_355 ;
continue;
} else if ( V_347 ) {
if ( V_344 == 0 ) {
V_38 = V_339 ( V_329 , V_338 ,
V_330 , V_331 ,
& V_341 ,
V_357 ,
V_340 ) ;
if ( V_38 < 0 )
goto V_290;
}
V_348 = V_355 ;
continue;
}
if ( V_344 == 0 && V_345 == 0 ) {
V_333 = F_148 ( & V_341 , & V_202 ) ;
if ( V_333 < 0 ) {
V_38 = V_339 ( V_329 , V_338 ,
V_330 , V_331 ,
& V_341 ,
V_357 ,
V_340 ) ;
if ( V_38 < 0 )
goto V_290;
V_348 = V_355 ;
} else if ( V_333 > 0 ) {
V_38 = V_339 ( V_329 , V_338 ,
V_330 , V_331 ,
& V_202 ,
V_356 ,
V_340 ) ;
if ( V_38 < 0 )
goto V_290;
V_349 = V_355 ;
} else {
enum V_358 V_359 ;
F_32 ( ! F_135 ( V_330 -> V_8 [ 0 ] ) ) ;
V_38 = F_259 ( V_329 , V_330 ,
V_331 , V_332 ) ;
if ( V_38 )
V_359 = V_360 ;
else
V_359 = V_361 ;
V_38 = V_339 ( V_329 , V_338 ,
V_330 , V_331 ,
& V_341 , V_359 , V_340 ) ;
if ( V_38 < 0 )
goto V_290;
V_348 = V_355 ;
V_349 = V_355 ;
}
} else if ( V_344 == V_345 ) {
V_333 = F_148 ( & V_341 , & V_202 ) ;
if ( V_333 < 0 ) {
V_348 = V_355 ;
} else if ( V_333 > 0 ) {
V_349 = V_355 ;
} else {
V_350 = F_81 (
V_330 -> V_8 [ V_344 ] ,
V_330 -> V_17 [ V_344 ] ) ;
V_351 = F_81 (
V_331 -> V_8 [ V_345 ] ,
V_331 -> V_17 [ V_345 ] ) ;
V_352 = F_82 (
V_330 -> V_8 [ V_344 ] ,
V_330 -> V_17 [ V_344 ] ) ;
V_353 = F_82 (
V_331 -> V_8 [ V_345 ] ,
V_331 -> V_17 [ V_345 ] ) ;
if ( V_350 == V_351 &&
V_352 == V_353 ) {
V_348 = V_354 ;
V_349 = V_354 ;
} else {
V_348 = V_355 ;
V_349 = V_355 ;
}
}
} else if ( V_344 < V_345 ) {
V_349 = V_355 ;
} else {
V_348 = V_355 ;
}
}
V_290:
F_7 ( V_330 ) ;
F_7 ( V_331 ) ;
F_70 ( V_332 ) ;
return V_38 ;
}
int F_254 ( struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_156 * V_86 , int V_39 , T_2 V_325 )
{
int V_80 ;
struct V_14 * V_259 ;
F_32 ( ! V_2 -> V_221 ) ;
while ( V_39 < V_7 ) {
if ( ! V_2 -> V_8 [ V_39 ] )
return 1 ;
V_80 = V_2 -> V_17 [ V_39 ] + 1 ;
V_259 = V_2 -> V_8 [ V_39 ] ;
V_66:
if ( V_80 >= F_90 ( V_259 ) ) {
int V_38 ;
int V_362 ;
struct V_156 V_363 ;
if ( V_39 + 1 >= V_7 ||
! V_2 -> V_8 [ V_39 + 1 ] )
return 1 ;
if ( V_2 -> V_9 [ V_39 + 1 ] ) {
V_39 ++ ;
continue;
}
V_80 = F_90 ( V_259 ) - 1 ;
if ( V_39 == 0 )
F_191 ( V_259 , & V_363 , V_80 ) ;
else
F_255 ( V_259 , & V_363 , V_80 ) ;
V_362 = V_2 -> V_238 ;
F_8 ( V_2 ) ;
V_2 -> V_238 = V_39 ;
V_38 = F_189 ( NULL , V_19 , & V_363 , V_2 ,
0 , 0 ) ;
V_2 -> V_238 = V_362 ;
if ( V_38 < 0 )
return V_38 ;
V_259 = V_2 -> V_8 [ V_39 ] ;
V_80 = V_2 -> V_17 [ V_39 ] ;
if ( V_38 == 0 )
V_80 ++ ;
goto V_66;
}
if ( V_39 == 0 )
F_191 ( V_259 , V_86 , V_80 ) ;
else {
T_2 V_163 = F_82 ( V_259 , V_80 ) ;
if ( V_163 < V_325 ) {
V_80 ++ ;
goto V_66;
}
F_255 ( V_259 , V_86 , V_80 ) ;
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
struct V_14 * V_259 ;
struct V_14 * V_66 ;
struct V_156 V_86 ;
T_4 V_99 ;
int V_38 ;
int V_364 = V_2 -> V_246 ;
int V_365 = 0 ;
V_99 = F_90 ( V_2 -> V_8 [ 0 ] ) ;
if ( V_99 == 0 )
return 1 ;
F_191 ( V_2 -> V_8 [ 0 ] , & V_86 , V_99 - 1 ) ;
V_229:
V_39 = 1 ;
V_66 = NULL ;
V_365 = 0 ;
F_8 ( V_2 ) ;
V_2 -> V_221 = 1 ;
V_2 -> V_246 = 1 ;
if ( V_134 )
V_38 = F_198 ( V_19 , & V_86 , V_2 , V_134 ) ;
else
V_38 = F_189 ( NULL , V_19 , & V_86 , V_2 , 0 , 0 ) ;
V_2 -> V_221 = 0 ;
if ( V_38 < 0 )
return V_38 ;
V_99 = F_90 ( V_2 -> V_8 [ 0 ] ) ;
if ( V_99 > 0 && V_2 -> V_17 [ 0 ] < V_99 - 1 ) {
if ( V_38 == 0 )
V_2 -> V_17 [ 0 ] ++ ;
V_38 = 0 ;
goto V_230;
}
if ( V_99 > 0 && V_38 > 0 && V_2 -> V_17 [ 0 ] == V_99 - 1 ) {
V_38 = 0 ;
goto V_230;
}
while ( V_39 < V_7 ) {
if ( ! V_2 -> V_8 [ V_39 ] ) {
V_38 = 1 ;
goto V_230;
}
V_80 = V_2 -> V_17 [ V_39 ] + 1 ;
V_259 = V_2 -> V_8 [ V_39 ] ;
if ( V_80 >= F_90 ( V_259 ) ) {
V_39 ++ ;
if ( V_39 == V_7 ) {
V_38 = 1 ;
goto V_230;
}
continue;
}
if ( V_66 ) {
F_10 ( V_66 , V_365 ) ;
F_11 ( V_66 ) ;
}
V_66 = V_259 ;
V_365 = V_2 -> V_9 [ V_39 ] ;
V_38 = F_180 ( NULL , V_19 , V_2 , & V_66 , V_39 ,
V_80 , & V_86 , 0 ) ;
if ( V_38 == - V_225 )
goto V_229;
if ( V_38 < 0 ) {
F_8 ( V_2 ) ;
goto V_230;
}
if ( ! V_2 -> V_242 ) {
V_38 = F_262 ( V_66 ) ;
if ( ! V_38 && V_134 ) {
F_11 ( V_66 ) ;
F_8 ( V_2 ) ;
F_263 () ;
goto V_229;
}
if ( ! V_38 ) {
F_3 ( V_2 ) ;
F_22 ( V_66 ) ;
F_5 ( V_2 , V_66 ,
V_10 ) ;
}
V_365 = V_10 ;
}
break;
}
V_2 -> V_17 [ V_39 ] = V_80 ;
while ( 1 ) {
V_39 -- ;
V_259 = V_2 -> V_8 [ V_39 ] ;
if ( V_2 -> V_9 [ V_39 ] )
F_10 ( V_259 , V_2 -> V_9 [ V_39 ] ) ;
F_11 ( V_259 ) ;
V_2 -> V_8 [ V_39 ] = V_66 ;
V_2 -> V_17 [ V_39 ] = 0 ;
if ( ! V_2 -> V_242 )
V_2 -> V_9 [ V_39 ] = V_365 ;
if ( ! V_39 )
break;
V_38 = F_180 ( NULL , V_19 , V_2 , & V_66 , V_39 ,
0 , & V_86 , 0 ) ;
if ( V_38 == - V_225 )
goto V_229;
if ( V_38 < 0 ) {
F_8 ( V_2 ) ;
goto V_230;
}
if ( ! V_2 -> V_242 ) {
V_38 = F_262 ( V_66 ) ;
if ( ! V_38 ) {
F_3 ( V_2 ) ;
F_22 ( V_66 ) ;
F_5 ( V_2 , V_66 ,
V_10 ) ;
}
V_365 = V_10 ;
}
}
V_38 = 0 ;
V_230:
F_178 ( V_2 , 0 , 1 , 0 , NULL ) ;
V_2 -> V_246 = V_364 ;
if ( ! V_364 )
F_3 ( V_2 ) ;
return V_38 ;
}
int F_264 ( struct V_18 * V_19 ,
struct V_1 * V_2 , T_2 V_366 ,
int type )
{
struct V_156 V_236 ;
struct V_14 * V_174 ;
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
V_174 = V_2 -> V_8 [ 0 ] ;
V_99 = F_90 ( V_174 ) ;
if ( V_99 == 0 )
return 1 ;
if ( V_2 -> V_17 [ 0 ] == V_99 )
V_2 -> V_17 [ 0 ] -- ;
F_191 ( V_174 , & V_236 , V_2 -> V_17 [ 0 ] ) ;
if ( V_236 . V_28 < V_366 )
break;
if ( V_236 . type == type )
return 0 ;
if ( V_236 . V_28 == V_366 &&
V_236 . type < type )
break;
}
return 1 ;
}
int F_265 ( struct V_18 * V_19 ,
struct V_1 * V_2 , T_2 V_366 )
{
struct V_156 V_236 ;
struct V_14 * V_174 ;
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
V_174 = V_2 -> V_8 [ 0 ] ;
V_99 = F_90 ( V_174 ) ;
if ( V_99 == 0 )
return 1 ;
if ( V_2 -> V_17 [ 0 ] == V_99 )
V_2 -> V_17 [ 0 ] -- ;
F_191 ( V_174 , & V_236 , V_2 -> V_17 [ 0 ] ) ;
if ( V_236 . V_28 < V_366 )
break;
if ( V_236 . type == V_367 ||
V_236 . type == V_368 )
return 0 ;
if ( V_236 . V_28 == V_366 &&
V_236 . type < V_367 )
break;
}
return 1 ;
}
