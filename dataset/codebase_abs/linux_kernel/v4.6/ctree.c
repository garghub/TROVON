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
V_69 -> V_76 = V_20 -> V_46 ;
if ( V_82 != V_84 ) {
F_35 ( V_20 , & V_69 -> V_85 , V_80 ) ;
V_69 -> V_86 = F_81 ( V_20 , V_80 ) ;
}
V_69 -> V_82 = V_82 ;
V_69 -> V_80 = V_80 ;
V_69 -> V_87 = F_82 ( V_20 , V_80 ) ;
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
return - V_88 ;
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
struct V_14 * V_20 , int V_89 , int V_90 ,
int V_91 , T_3 V_83 )
{
struct V_68 * V_69 = NULL ;
struct V_68 * * V_92 = NULL ;
int V_38 = 0 ;
int V_6 ;
int V_93 = 0 ;
if ( ! F_78 ( V_26 , V_20 ) )
return 0 ;
V_92 = F_86 ( V_91 , sizeof( struct V_68 * ) , V_83 ) ;
if ( ! V_92 )
return - V_88 ;
V_69 = F_80 ( sizeof( * V_69 ) , V_83 ) ;
if ( ! V_69 ) {
V_38 = - V_88 ;
goto V_94;
}
V_69 -> V_76 = V_20 -> V_46 ;
V_69 -> V_80 = V_90 ;
V_69 -> V_95 . V_89 = V_89 ;
V_69 -> V_95 . V_91 = V_91 ;
V_69 -> V_82 = V_96 ;
for ( V_6 = 0 ; V_6 + V_89 < V_90 && V_6 < V_91 ; V_6 ++ ) {
V_92 [ V_6 ] = F_79 ( V_20 , V_6 + V_89 ,
V_97 , V_83 ) ;
if ( ! V_92 [ V_6 ] ) {
V_38 = - V_88 ;
goto V_94;
}
}
if ( F_75 ( V_26 , V_20 ) )
goto V_94;
V_93 = 1 ;
for ( V_6 = 0 ; V_6 + V_89 < V_90 && V_6 < V_91 ; V_6 ++ ) {
V_38 = F_71 ( V_26 , V_92 [ V_6 ] ) ;
if ( V_38 )
goto V_94;
}
V_38 = F_71 ( V_26 , V_69 ) ;
if ( V_38 )
goto V_94;
F_57 ( V_26 ) ;
F_70 ( V_92 ) ;
return 0 ;
V_94:
for ( V_6 = 0 ; V_6 < V_91 ; V_6 ++ ) {
if ( V_92 [ V_6 ] && ! F_87 ( & V_92 [ V_6 ] -> V_21 ) )
F_69 ( & V_92 [ V_6 ] -> V_21 , & V_26 -> V_72 ) ;
F_70 ( V_92 [ V_6 ] ) ;
}
if ( V_93 )
F_57 ( V_26 ) ;
F_70 ( V_92 ) ;
F_70 ( V_69 ) ;
return V_38 ;
}
static inline int
F_88 ( struct V_54 * V_26 ,
struct V_68 * * V_92 ,
int V_98 )
{
int V_6 , V_99 ;
int V_38 ;
for ( V_6 = V_98 - 1 ; V_6 >= 0 ; V_6 -- ) {
V_38 = F_71 ( V_26 , V_92 [ V_6 ] ) ;
if ( V_38 ) {
for ( V_99 = V_98 - 1 ; V_99 > V_6 ; V_99 -- )
F_69 ( & V_92 [ V_99 ] -> V_21 ,
& V_26 -> V_72 ) ;
return V_38 ;
}
}
return 0 ;
}
static T_1 int
F_89 ( struct V_54 * V_26 ,
struct V_14 * V_100 ,
struct V_14 * V_101 , T_3 V_83 ,
int V_102 )
{
struct V_68 * V_69 = NULL ;
struct V_68 * * V_92 = NULL ;
int V_98 = 0 ;
int V_38 = 0 ;
int V_6 ;
if ( ! F_78 ( V_26 , NULL ) )
return 0 ;
if ( V_102 && F_33 ( V_100 ) > 0 ) {
V_98 = F_90 ( V_100 ) ;
V_92 = F_86 ( V_98 , sizeof( struct V_68 * ) ,
V_83 ) ;
if ( ! V_92 ) {
V_38 = - V_88 ;
goto V_94;
}
for ( V_6 = 0 ; V_6 < V_98 ; V_6 ++ ) {
V_92 [ V_6 ] = F_79 ( V_100 , V_6 ,
V_103 , V_83 ) ;
if ( ! V_92 [ V_6 ] ) {
V_38 = - V_88 ;
goto V_94;
}
}
}
V_69 = F_80 ( sizeof( * V_69 ) , V_83 ) ;
if ( ! V_69 ) {
V_38 = - V_88 ;
goto V_94;
}
V_69 -> V_76 = V_101 -> V_46 ;
V_69 -> V_100 . V_76 = V_100 -> V_46 ;
V_69 -> V_100 . V_39 = F_33 ( V_100 ) ;
V_69 -> V_87 = F_48 ( V_100 ) ;
V_69 -> V_82 = V_104 ;
if ( F_75 ( V_26 , NULL ) )
goto V_94;
if ( V_92 )
V_38 = F_88 ( V_26 , V_92 , V_98 ) ;
if ( ! V_38 )
V_38 = F_71 ( V_26 , V_69 ) ;
F_57 ( V_26 ) ;
if ( V_38 )
goto V_94;
F_70 ( V_92 ) ;
return V_38 ;
V_94:
if ( V_92 ) {
for ( V_6 = 0 ; V_6 < V_98 ; V_6 ++ )
F_70 ( V_92 [ V_6 ] ) ;
F_70 ( V_92 ) ;
}
F_70 ( V_69 ) ;
return V_38 ;
}
static struct V_68 *
F_91 ( struct V_54 * V_26 , T_2 V_46 , T_2 V_70 ,
int V_105 )
{
struct V_63 * V_64 ;
struct V_65 * V_21 ;
struct V_68 * V_75 = NULL ;
struct V_68 * V_106 = NULL ;
F_51 ( V_26 ) ;
V_64 = & V_26 -> V_72 ;
V_21 = V_64 -> V_65 ;
while ( V_21 ) {
V_75 = F_68 ( V_21 , struct V_68 , V_21 ) ;
if ( V_75 -> V_76 < V_46 ) {
V_21 = V_21 -> V_77 ;
} else if ( V_75 -> V_76 > V_46 ) {
V_21 = V_21 -> V_78 ;
} else if ( V_75 -> V_60 < V_70 ) {
V_21 = V_21 -> V_77 ;
} else if ( ! V_105 ) {
if ( V_106 )
F_72 ( V_106 -> V_60 > V_75 -> V_60 ) ;
V_106 = V_75 ;
V_21 = V_21 -> V_77 ;
} else if ( V_75 -> V_60 > V_70 ) {
if ( V_106 )
F_72 ( V_106 -> V_60 < V_75 -> V_60 ) ;
V_106 = V_75 ;
V_21 = V_21 -> V_78 ;
} else {
V_106 = V_75 ;
break;
}
}
F_53 ( V_26 ) ;
return V_106 ;
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
F_94 ( struct V_54 * V_26 , struct V_14 * V_107 ,
struct V_14 * V_108 , unsigned long V_109 ,
unsigned long V_110 , int V_91 )
{
int V_38 = 0 ;
struct V_68 * * V_92 = NULL ;
struct V_68 * * V_111 , * * V_112 ;
int V_6 ;
int V_93 = 0 ;
if ( ! F_78 ( V_26 , NULL ) )
return 0 ;
if ( F_33 ( V_107 ) == 0 && F_33 ( V_108 ) == 0 )
return 0 ;
V_92 = F_86 ( V_91 * 2 , sizeof( struct V_68 * ) ,
V_4 ) ;
if ( ! V_92 )
return - V_88 ;
V_111 = V_92 ;
V_112 = V_92 + V_91 ;
for ( V_6 = 0 ; V_6 < V_91 ; V_6 ++ ) {
V_112 [ V_6 ] = F_79 ( V_108 , V_6 + V_110 ,
V_113 , V_4 ) ;
if ( ! V_112 [ V_6 ] ) {
V_38 = - V_88 ;
goto V_94;
}
V_111 [ V_6 ] = F_79 ( V_107 , V_6 + V_109 ,
V_84 , V_4 ) ;
if ( ! V_111 [ V_6 ] ) {
V_38 = - V_88 ;
goto V_94;
}
}
if ( F_75 ( V_26 , NULL ) )
goto V_94;
V_93 = 1 ;
for ( V_6 = 0 ; V_6 < V_91 ; V_6 ++ ) {
V_38 = F_71 ( V_26 , V_112 [ V_6 ] ) ;
if ( V_38 )
goto V_94;
V_38 = F_71 ( V_26 , V_111 [ V_6 ] ) ;
if ( V_38 )
goto V_94;
}
F_57 ( V_26 ) ;
F_70 ( V_92 ) ;
return 0 ;
V_94:
for ( V_6 = 0 ; V_6 < V_91 * 2 ; V_6 ++ ) {
if ( V_92 [ V_6 ] && ! F_87 ( & V_92 [ V_6 ] -> V_21 ) )
F_69 ( & V_92 [ V_6 ] -> V_21 , & V_26 -> V_72 ) ;
F_70 ( V_92 [ V_6 ] ) ;
}
if ( V_93 )
F_57 ( V_26 ) ;
F_70 ( V_92 ) ;
return V_38 ;
}
static inline void
F_95 ( struct V_54 * V_26 , struct V_14 * V_107 ,
int V_109 , int V_110 , int V_91 )
{
int V_38 ;
V_38 = F_85 ( V_26 , V_107 , V_109 , V_110 ,
V_91 , V_4 ) ;
F_72 ( V_38 < 0 ) ;
}
static T_1 void
F_96 ( struct V_54 * V_26 ,
struct V_14 * V_20 , int V_80 , int V_114 )
{
int V_38 ;
V_38 = F_84 ( V_26 , V_20 , V_80 ,
V_115 ,
V_114 ? V_116 : V_4 ) ;
F_72 ( V_38 < 0 ) ;
}
static T_1 int
F_97 ( struct V_54 * V_26 , struct V_14 * V_20 )
{
struct V_68 * * V_92 = NULL ;
int V_98 = 0 ;
int V_6 ;
int V_38 = 0 ;
if ( F_33 ( V_20 ) == 0 )
return 0 ;
if ( ! F_78 ( V_26 , NULL ) )
return 0 ;
V_98 = F_90 ( V_20 ) ;
V_92 = F_86 ( V_98 , sizeof( struct V_68 * ) , V_4 ) ;
if ( ! V_92 )
return - V_88 ;
for ( V_6 = 0 ; V_6 < V_98 ; V_6 ++ ) {
V_92 [ V_6 ] = F_79 ( V_20 , V_6 ,
V_103 , V_4 ) ;
if ( ! V_92 [ V_6 ] ) {
V_38 = - V_88 ;
goto V_94;
}
}
if ( F_75 ( V_26 , V_20 ) )
goto V_94;
V_38 = F_88 ( V_26 , V_92 , V_98 ) ;
F_57 ( V_26 ) ;
if ( V_38 )
goto V_94;
F_70 ( V_92 ) ;
return 0 ;
V_94:
for ( V_6 = 0 ; V_6 < V_98 ; V_6 ++ )
F_70 ( V_92 [ V_6 ] ) ;
F_70 ( V_92 ) ;
return V_38 ;
}
static T_1 void
F_98 ( struct V_18 * V_19 ,
struct V_14 * V_117 ,
int V_102 )
{
int V_38 ;
V_38 = F_89 ( V_19 -> V_26 , V_19 -> V_21 ,
V_117 , V_4 , V_102 ) ;
F_72 ( V_38 < 0 ) ;
}
int F_99 ( struct V_18 * V_19 ,
struct V_14 * V_34 )
{
if ( F_25 ( V_42 , & V_19 -> V_24 ) &&
V_34 != V_19 -> V_21 && V_34 != V_19 -> V_118 &&
( F_48 ( V_34 ) <=
F_100 ( & V_19 -> V_119 ) ||
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
int * V_120 )
{
T_2 V_22 ;
T_2 V_121 ;
T_2 V_83 ;
T_2 V_122 = 0 ;
int V_38 ;
if ( F_99 ( V_19 , V_34 ) ) {
V_38 = F_105 ( V_33 , V_19 , V_34 -> V_46 ,
F_33 ( V_34 ) , 1 ,
& V_22 , & V_83 ) ;
if ( V_38 )
return V_38 ;
if ( V_22 == 0 ) {
V_38 = - V_123 ;
F_106 ( V_19 -> V_26 , V_38 , NULL ) ;
return V_38 ;
}
} else {
V_22 = 1 ;
if ( V_19 -> V_124 . V_28 == V_51 ||
F_103 ( V_34 ) < V_48 )
V_83 = V_125 ;
else
V_83 = 0 ;
}
V_121 = F_107 ( V_34 ) ;
F_72 ( V_121 == V_51 &&
! ( V_83 & V_125 ) ) ;
if ( V_22 > 1 ) {
if ( ( V_121 == V_19 -> V_124 . V_28 ||
V_19 -> V_124 . V_28 == V_51 ) &&
! ( V_83 & V_125 ) ) {
V_38 = F_49 ( V_33 , V_19 , V_34 , 1 ) ;
F_72 ( V_38 ) ;
if ( V_19 -> V_124 . V_28 ==
V_51 ) {
V_38 = F_108 ( V_33 , V_19 , V_34 , 0 ) ;
F_72 ( V_38 ) ;
V_38 = F_49 ( V_33 , V_19 , V_37 , 1 ) ;
F_72 ( V_38 ) ;
}
V_122 |= V_125 ;
} else {
if ( V_19 -> V_124 . V_28 ==
V_51 )
V_38 = F_49 ( V_33 , V_19 , V_37 , 1 ) ;
else
V_38 = F_49 ( V_33 , V_19 , V_37 , 0 ) ;
F_72 ( V_38 ) ;
}
if ( V_122 != 0 ) {
int V_39 = F_33 ( V_34 ) ;
V_38 = F_109 ( V_33 , V_19 ,
V_34 -> V_46 ,
V_34 -> V_47 ,
V_122 , V_39 , 0 ) ;
if ( V_38 )
return V_38 ;
}
} else {
if ( V_83 & V_125 ) {
if ( V_19 -> V_124 . V_28 ==
V_51 )
V_38 = F_49 ( V_33 , V_19 , V_37 , 1 ) ;
else
V_38 = F_49 ( V_33 , V_19 , V_37 , 0 ) ;
F_72 ( V_38 ) ;
V_38 = F_108 ( V_33 , V_19 , V_34 , 1 ) ;
F_72 ( V_38 ) ;
}
F_110 ( V_33 , V_19 -> V_26 , V_34 ) ;
* V_120 = 1 ;
}
return 0 ;
}
static T_1 int F_111 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_14 * V_34 ,
struct V_14 * V_74 , int V_126 ,
struct V_14 * * V_35 ,
T_2 V_127 , T_2 V_128 )
{
struct V_40 V_41 ;
struct V_14 * V_37 ;
int V_39 , V_38 ;
int V_120 = 0 ;
int V_129 = 0 ;
T_2 V_130 ;
if ( * V_35 == V_34 )
V_129 = 1 ;
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
if ( V_19 -> V_124 . V_28 == V_51 ) {
if ( V_74 )
V_130 = V_74 -> V_46 ;
else
V_130 = 0 ;
} else
V_130 = 0 ;
V_37 = F_36 ( V_33 , V_19 , V_130 ,
V_19 -> V_124 . V_28 , & V_41 , V_39 ,
V_127 , V_128 ) ;
if ( F_37 ( V_37 ) )
return F_38 ( V_37 ) ;
F_39 ( V_37 , V_34 , 0 , 0 , V_37 -> V_47 ) ;
F_40 ( V_37 , V_37 -> V_46 ) ;
F_41 ( V_37 , V_33 -> V_43 ) ;
F_42 ( V_37 , V_48 ) ;
F_43 ( V_37 , V_49 |
V_50 ) ;
if ( V_19 -> V_124 . V_28 == V_51 )
F_44 ( V_37 , V_50 ) ;
else
F_45 ( V_37 , V_19 -> V_124 . V_28 ) ;
F_46 ( V_37 , V_19 -> V_26 -> V_52 , F_47 () ,
V_53 ) ;
V_38 = F_104 ( V_33 , V_19 , V_34 , V_37 , & V_120 ) ;
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
if ( V_19 -> V_124 . V_28 == V_51 ||
F_103 ( V_34 ) < V_48 )
V_130 = V_34 -> V_46 ;
else
V_130 = 0 ;
F_115 ( V_37 ) ;
F_98 ( V_19 , V_37 , 1 ) ;
F_116 ( V_19 -> V_21 , V_37 ) ;
F_117 ( V_33 , V_19 , V_34 , V_130 ,
V_120 ) ;
F_11 ( V_34 ) ;
F_24 ( V_19 ) ;
} else {
if ( V_19 -> V_124 . V_28 == V_51 )
V_130 = V_74 -> V_46 ;
else
V_130 = 0 ;
F_32 ( V_33 -> V_43 != F_48 ( V_74 ) ) ;
F_84 ( V_19 -> V_26 , V_74 , V_126 ,
V_115 , V_4 ) ;
F_118 ( V_74 , V_126 ,
V_37 -> V_46 ) ;
F_119 ( V_74 , V_126 ,
V_33 -> V_43 ) ;
F_50 ( V_74 ) ;
if ( V_120 ) {
V_38 = F_97 ( V_19 -> V_26 , V_34 ) ;
if ( V_38 ) {
F_113 ( V_33 , V_19 , V_38 ) ;
return V_38 ;
}
}
F_117 ( V_33 , V_19 , V_34 , V_130 ,
V_120 ) ;
}
if ( V_129 )
F_20 ( V_34 ) ;
F_120 ( V_34 ) ;
F_50 ( V_37 ) ;
* V_35 = V_37 ;
return 0 ;
}
static struct V_68 *
F_121 ( struct V_54 * V_26 ,
struct V_14 * V_131 , T_2 V_132 )
{
struct V_68 * V_69 ;
struct V_68 * V_106 = NULL ;
T_2 V_133 = V_131 -> V_46 ;
int V_134 = 0 ;
if ( ! V_132 )
return NULL ;
while ( 1 ) {
V_69 = F_92 ( V_26 , V_133 ,
V_132 ) ;
if ( ! V_134 && ! V_69 )
return NULL ;
if ( ! V_69 )
break;
if ( V_69 -> V_82 != V_104 )
break;
V_106 = V_69 ;
V_133 = V_69 -> V_100 . V_76 ;
V_134 = 1 ;
}
if ( ! V_106 )
V_106 = V_69 ;
return V_106 ;
}
static void
F_122 ( struct V_54 * V_26 , struct V_14 * V_20 ,
T_2 V_132 , struct V_68 * V_135 )
{
T_4 V_136 ;
struct V_65 * V_66 ;
struct V_68 * V_69 = V_135 ;
unsigned long V_137 ;
unsigned long V_138 ;
unsigned long V_139 = sizeof( struct V_140 ) ;
V_136 = F_90 ( V_20 ) ;
F_51 ( V_26 ) ;
while ( V_69 && V_69 -> V_60 >= V_132 ) {
switch ( V_69 -> V_82 ) {
case V_103 :
F_72 ( V_69 -> V_80 < V_136 ) ;
case V_97 :
case V_113 :
F_123 ( V_20 , & V_69 -> V_85 , V_69 -> V_80 ) ;
F_118 ( V_20 , V_69 -> V_80 , V_69 -> V_86 ) ;
F_119 ( V_20 , V_69 -> V_80 ,
V_69 -> V_87 ) ;
V_136 ++ ;
break;
case V_115 :
F_72 ( V_69 -> V_80 >= V_136 ) ;
F_123 ( V_20 , & V_69 -> V_85 , V_69 -> V_80 ) ;
F_118 ( V_20 , V_69 -> V_80 , V_69 -> V_86 ) ;
F_119 ( V_20 , V_69 -> V_80 ,
V_69 -> V_87 ) ;
break;
case V_84 :
V_136 -- ;
break;
case V_96 :
V_137 = F_124 ( V_69 -> V_80 ) ;
V_138 = F_124 ( V_69 -> V_95 . V_89 ) ;
F_125 ( V_20 , V_137 , V_138 ,
V_69 -> V_95 . V_91 * V_139 ) ;
break;
case V_104 :
break;
}
V_66 = F_67 ( & V_69 -> V_21 ) ;
if ( ! V_66 )
break;
V_69 = F_68 ( V_66 , struct V_68 , V_21 ) ;
if ( V_69 -> V_76 != V_135 -> V_76 )
break;
}
F_53 ( V_26 ) ;
F_126 ( V_20 , V_136 ) ;
}
static struct V_14 *
F_127 ( struct V_54 * V_26 , struct V_1 * V_2 ,
struct V_14 * V_20 , T_2 V_132 )
{
struct V_14 * V_141 ;
struct V_68 * V_69 ;
if ( ! V_132 )
return V_20 ;
if ( F_33 ( V_20 ) == 0 )
return V_20 ;
V_69 = F_93 ( V_26 , V_20 -> V_46 , V_132 ) ;
if ( ! V_69 )
return V_20 ;
F_3 ( V_2 ) ;
F_4 ( V_20 , V_10 ) ;
if ( V_69 -> V_82 == V_103 ) {
F_72 ( V_69 -> V_80 != 0 ) ;
V_141 = F_128 ( V_26 , V_20 -> V_46 ) ;
if ( ! V_141 ) {
F_129 ( V_20 ) ;
F_11 ( V_20 ) ;
return NULL ;
}
F_40 ( V_141 , V_20 -> V_46 ) ;
F_42 ( V_141 ,
F_103 ( V_20 ) ) ;
F_45 ( V_141 , F_107 ( V_20 ) ) ;
F_130 ( V_141 , F_33 ( V_20 ) ) ;
} else {
V_141 = F_131 ( V_20 ) ;
if ( ! V_141 ) {
F_129 ( V_20 ) ;
F_11 ( V_20 ) ;
return NULL ;
}
}
F_5 ( V_2 , NULL , V_10 ) ;
F_129 ( V_20 ) ;
F_11 ( V_20 ) ;
F_115 ( V_141 ) ;
F_22 ( V_141 ) ;
F_122 ( V_26 , V_141 , V_132 , V_69 ) ;
F_32 ( F_90 ( V_141 ) >
F_132 ( V_26 -> V_142 ) ) ;
return V_141 ;
}
static inline struct V_14 *
F_133 ( struct V_18 * V_19 , T_2 V_132 )
{
struct V_68 * V_69 ;
struct V_14 * V_20 = NULL ;
struct V_14 * V_131 ;
struct V_14 * V_143 ;
struct V_144 * V_100 = NULL ;
T_2 V_145 = 0 ;
T_2 V_76 ;
V_131 = F_21 ( V_19 ) ;
V_69 = F_121 ( V_19 -> V_26 , V_131 , V_132 ) ;
if ( ! V_69 )
return V_131 ;
if ( V_69 -> V_82 == V_104 ) {
V_100 = & V_69 -> V_100 ;
V_145 = V_69 -> V_87 ;
V_76 = V_100 -> V_76 ;
} else {
V_76 = V_131 -> V_46 ;
}
V_69 = F_93 ( V_19 -> V_26 , V_76 , V_132 ) ;
if ( V_100 && V_69 && V_69 -> V_82 != V_103 ) {
F_23 ( V_131 ) ;
F_11 ( V_131 ) ;
V_143 = F_134 ( V_19 , V_76 , 0 ) ;
if ( F_32 ( F_37 ( V_143 ) || ! F_135 ( V_143 ) ) ) {
if ( ! F_37 ( V_143 ) )
F_11 ( V_143 ) ;
F_136 ( V_19 -> V_26 ,
L_1 , V_76 ) ;
} else {
V_20 = F_131 ( V_143 ) ;
F_11 ( V_143 ) ;
}
} else if ( V_100 ) {
F_23 ( V_131 ) ;
F_11 ( V_131 ) ;
V_20 = F_128 ( V_19 -> V_26 , V_76 ) ;
} else {
F_4 ( V_131 , V_10 ) ;
V_20 = F_131 ( V_131 ) ;
F_129 ( V_131 ) ;
F_11 ( V_131 ) ;
}
if ( ! V_20 )
return NULL ;
F_115 ( V_20 ) ;
F_22 ( V_20 ) ;
if ( V_100 ) {
F_40 ( V_20 , V_20 -> V_46 ) ;
F_42 ( V_20 , V_48 ) ;
F_45 ( V_20 , F_107 ( V_131 ) ) ;
F_130 ( V_20 , V_100 -> V_39 ) ;
F_41 ( V_20 , V_145 ) ;
}
if ( V_69 )
F_122 ( V_19 -> V_26 , V_20 , V_132 , V_69 ) ;
else
F_32 ( F_33 ( V_20 ) != 0 ) ;
F_32 ( F_90 ( V_20 ) > F_132 ( V_19 ) ) ;
return V_20 ;
}
int F_137 ( struct V_18 * V_19 , T_2 V_132 )
{
struct V_68 * V_69 ;
int V_39 ;
struct V_14 * V_131 = F_12 ( V_19 ) ;
V_69 = F_121 ( V_19 -> V_26 , V_131 , V_132 ) ;
if ( V_69 && V_69 -> V_82 == V_104 ) {
V_39 = V_69 -> V_100 . V_39 ;
} else {
V_39 = F_33 ( V_131 ) ;
}
F_11 ( V_131 ) ;
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
! ( V_19 -> V_124 . V_28 != V_51 &&
F_101 ( V_34 , V_50 ) ) &&
! F_25 ( V_146 , & V_19 -> V_24 ) )
return 0 ;
return 1 ;
}
T_1 int F_141 ( struct V_32 * V_33 ,
struct V_18 * V_19 , struct V_14 * V_34 ,
struct V_14 * V_74 , int V_126 ,
struct V_14 * * V_35 )
{
T_2 V_127 ;
int V_38 ;
if ( V_33 -> V_147 != V_19 -> V_26 -> V_44 )
F_142 ( 1 , V_148 L_2 ,
V_33 -> V_43 ,
V_19 -> V_26 -> V_44 -> V_43 ) ;
if ( V_33 -> V_43 != V_19 -> V_26 -> V_87 )
F_142 ( 1 , V_148 L_2 ,
V_33 -> V_43 , V_19 -> V_26 -> V_87 ) ;
if ( ! F_138 ( V_33 , V_19 , V_34 ) ) {
* V_35 = V_34 ;
return 0 ;
}
V_127 = V_34 -> V_46 & ~ ( ( T_2 ) V_149 - 1 ) ;
if ( V_74 )
F_143 ( V_74 ) ;
F_143 ( V_34 ) ;
V_38 = F_111 ( V_33 , V_19 , V_34 , V_74 ,
V_126 , V_35 , V_127 , 0 ) ;
F_144 ( V_19 , V_34 , * V_35 ) ;
return V_38 ;
}
static int F_145 ( T_2 V_150 , T_2 V_151 , T_4 V_152 )
{
if ( V_150 < V_151 && V_151 - ( V_150 + V_152 ) < 32768 )
return 1 ;
if ( V_150 > V_151 && V_150 - ( V_151 + V_152 ) < 32768 )
return 1 ;
return 0 ;
}
static int F_146 ( struct V_40 * V_153 , struct V_154 * V_155 )
{
struct V_154 V_156 ;
F_147 ( & V_156 , V_153 ) ;
return F_148 ( & V_156 , V_155 ) ;
}
int F_148 ( struct V_154 * V_156 , struct V_154 * V_155 )
{
if ( V_156 -> V_28 > V_155 -> V_28 )
return 1 ;
if ( V_156 -> V_28 < V_155 -> V_28 )
return - 1 ;
if ( V_156 -> type > V_155 -> type )
return 1 ;
if ( V_156 -> type < V_155 -> type )
return - 1 ;
if ( V_156 -> V_157 > V_155 -> V_157 )
return 1 ;
if ( V_156 -> V_157 < V_155 -> V_157 )
return - 1 ;
return 0 ;
}
int F_149 ( struct V_32 * V_33 ,
struct V_18 * V_19 , struct V_14 * V_74 ,
int V_158 , T_2 * V_159 ,
struct V_154 * V_160 )
{
struct V_14 * V_75 ;
T_2 V_150 ;
T_2 V_161 ;
T_2 V_127 = * V_159 ;
T_2 V_162 = 0 ;
T_2 V_151 ;
T_4 V_163 ;
int V_164 ;
int V_6 ;
int V_165 = 0 ;
int V_166 ;
int V_167 ;
T_4 V_152 ;
int V_168 = 0 ;
struct V_40 V_41 ;
V_166 = F_33 ( V_74 ) ;
F_32 ( V_33 -> V_147 != V_19 -> V_26 -> V_44 ) ;
F_32 ( V_33 -> V_43 != V_19 -> V_26 -> V_87 ) ;
V_163 = F_90 ( V_74 ) ;
V_152 = V_19 -> V_169 ;
V_164 = V_163 - 1 ;
if ( V_163 <= 1 )
return 0 ;
F_143 ( V_74 ) ;
for ( V_6 = V_158 ; V_6 <= V_164 ; V_6 ++ ) {
int V_170 = 1 ;
F_35 ( V_74 , & V_41 , V_6 ) ;
if ( ! V_168 && F_146 ( & V_41 , V_160 ) < 0 )
continue;
V_168 = 1 ;
V_150 = F_81 ( V_74 , V_6 ) ;
V_161 = F_82 ( V_74 , V_6 ) ;
if ( V_162 == 0 )
V_162 = V_150 ;
if ( V_6 > 0 ) {
V_151 = F_81 ( V_74 , V_6 - 1 ) ;
V_170 = F_145 ( V_150 , V_151 , V_152 ) ;
}
if ( ! V_170 && V_6 < V_164 ) {
V_151 = F_81 ( V_74 , V_6 + 1 ) ;
V_170 = F_145 ( V_150 , V_151 , V_152 ) ;
}
if ( V_170 ) {
V_162 = V_150 ;
continue;
}
V_75 = F_150 ( V_19 -> V_26 , V_150 ) ;
if ( V_75 )
V_167 = F_151 ( V_75 , V_161 , 0 ) ;
else
V_167 = 0 ;
if ( ! V_75 || ! V_167 ) {
if ( ! V_75 ) {
V_75 = F_134 ( V_19 , V_150 , V_161 ) ;
if ( F_37 ( V_75 ) ) {
return F_38 ( V_75 ) ;
} else if ( ! F_135 ( V_75 ) ) {
F_11 ( V_75 ) ;
return - V_171 ;
}
} else if ( ! V_167 ) {
V_165 = F_152 ( V_75 , V_161 ) ;
if ( V_165 ) {
F_11 ( V_75 ) ;
return V_165 ;
}
}
}
if ( V_127 == 0 )
V_127 = V_162 ;
F_19 ( V_75 ) ;
F_143 ( V_75 ) ;
V_165 = F_111 ( V_33 , V_19 , V_75 , V_74 , V_6 ,
& V_75 , V_127 ,
F_153 ( 16 * V_152 ,
( V_164 - V_6 ) * V_152 ) ) ;
if ( V_165 ) {
F_20 ( V_75 ) ;
F_11 ( V_75 ) ;
break;
}
V_127 = V_75 -> V_46 ;
V_162 = V_75 -> V_46 ;
* V_159 = V_127 ;
F_20 ( V_75 ) ;
F_11 ( V_75 ) ;
}
return V_165 ;
}
static inline unsigned int F_154 ( struct V_18 * V_19 ,
struct V_14 * V_172 )
{
T_4 V_173 = F_90 ( V_172 ) ;
if ( V_173 == 0 )
return F_155 ( V_19 ) ;
return F_156 ( V_172 , V_173 - 1 ) ;
}
static T_1 int F_157 ( struct V_14 * V_20 ,
unsigned long V_5 ,
int V_174 , struct V_154 * V_85 ,
int V_175 , int * V_80 )
{
int V_176 = 0 ;
int V_177 = V_175 ;
int V_178 ;
int V_38 ;
struct V_40 * V_179 = NULL ;
struct V_40 V_180 ;
unsigned long V_157 ;
char * V_181 = NULL ;
unsigned long V_182 = 0 ;
unsigned long V_183 = 0 ;
int V_165 ;
while ( V_176 < V_177 ) {
V_178 = ( V_176 + V_177 ) / 2 ;
V_157 = V_5 + V_178 * V_174 ;
if ( ! V_181 || V_157 < V_182 ||
( V_157 + sizeof( struct V_40 ) ) >
V_182 + V_183 ) {
V_165 = F_158 ( V_20 , V_157 ,
sizeof( struct V_40 ) ,
& V_181 , & V_182 , & V_183 ) ;
if ( ! V_165 ) {
V_179 = (struct V_40 * ) ( V_181 + V_157 -
V_182 ) ;
} else {
F_159 ( V_20 , & V_180 ,
V_157 , sizeof( V_180 ) ) ;
V_179 = & V_180 ;
}
} else {
V_179 = (struct V_40 * ) ( V_181 + V_157 -
V_182 ) ;
}
V_38 = F_146 ( V_179 , V_85 ) ;
if ( V_38 < 0 )
V_176 = V_178 + 1 ;
else if ( V_38 > 0 )
V_177 = V_178 ;
else {
* V_80 = V_178 ;
return 0 ;
}
}
* V_80 = V_176 ;
return 1 ;
}
static int F_160 ( struct V_14 * V_20 , struct V_154 * V_85 ,
int V_39 , int * V_80 )
{
if ( V_39 == 0 )
return F_157 ( V_20 ,
F_161 ( struct V_184 , V_185 ) ,
sizeof( struct V_186 ) ,
V_85 , F_90 ( V_20 ) ,
V_80 ) ;
else
return F_157 ( V_20 ,
F_161 ( struct V_187 , V_188 ) ,
sizeof( struct V_140 ) ,
V_85 , F_90 ( V_20 ) ,
V_80 ) ;
}
int F_162 ( struct V_14 * V_20 , struct V_154 * V_85 ,
int V_39 , int * V_80 )
{
return F_160 ( V_20 , V_85 , V_39 , V_80 ) ;
}
static void F_163 ( struct V_18 * V_19 , T_4 V_189 )
{
F_26 ( & V_19 -> V_190 ) ;
F_164 ( & V_19 -> V_119 ,
F_165 ( & V_19 -> V_119 ) + V_189 ) ;
F_30 ( & V_19 -> V_190 ) ;
}
static void F_166 ( struct V_18 * V_19 , T_4 V_189 )
{
F_26 ( & V_19 -> V_190 ) ;
F_164 ( & V_19 -> V_119 ,
F_165 ( & V_19 -> V_119 ) - V_189 ) ;
F_30 ( & V_19 -> V_190 ) ;
}
T_1 int F_167 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_39 )
{
struct V_14 * V_191 = NULL ;
struct V_14 * V_178 ;
struct V_14 * V_192 = NULL ;
struct V_14 * V_74 = NULL ;
int V_38 = 0 ;
int V_193 ;
int V_194 ;
int V_195 = V_2 -> V_17 [ V_39 ] ;
T_2 V_196 ;
if ( V_39 == 0 )
return 0 ;
V_178 = V_2 -> V_8 [ V_39 ] ;
F_32 ( V_2 -> V_9 [ V_39 ] != V_12 &&
V_2 -> V_9 [ V_39 ] != V_13 ) ;
F_32 ( F_48 ( V_178 ) != V_33 -> V_43 ) ;
V_196 = F_81 ( V_178 , V_195 ) ;
if ( V_39 < V_7 - 1 ) {
V_74 = V_2 -> V_8 [ V_39 + 1 ] ;
V_194 = V_2 -> V_17 [ V_39 + 1 ] ;
}
if ( ! V_74 ) {
struct V_14 * V_197 ;
if ( F_90 ( V_178 ) != 1 )
return 0 ;
V_197 = F_168 ( V_19 , V_178 , 0 ) ;
if ( ! V_197 ) {
V_38 = - V_123 ;
F_106 ( V_19 -> V_26 , V_38 , NULL ) ;
goto V_198;
}
F_19 ( V_197 ) ;
F_143 ( V_197 ) ;
V_38 = F_141 ( V_33 , V_19 , V_197 , V_178 , 0 , & V_197 ) ;
if ( V_38 ) {
F_20 ( V_197 ) ;
F_11 ( V_197 ) ;
goto V_198;
}
F_98 ( V_19 , V_197 , 1 ) ;
F_116 ( V_19 -> V_21 , V_197 ) ;
F_24 ( V_19 ) ;
F_20 ( V_197 ) ;
V_2 -> V_9 [ V_39 ] = 0 ;
V_2 -> V_8 [ V_39 ] = NULL ;
F_110 ( V_33 , V_19 -> V_26 , V_178 ) ;
F_20 ( V_178 ) ;
F_11 ( V_178 ) ;
F_166 ( V_19 , V_178 -> V_47 ) ;
F_117 ( V_33 , V_19 , V_178 , 0 , 1 ) ;
F_120 ( V_178 ) ;
return 0 ;
}
if ( F_90 ( V_178 ) >
F_132 ( V_19 ) / 4 )
return 0 ;
V_192 = F_168 ( V_19 , V_74 , V_194 - 1 ) ;
if ( V_192 ) {
F_19 ( V_192 ) ;
F_143 ( V_192 ) ;
V_193 = F_141 ( V_33 , V_19 , V_192 ,
V_74 , V_194 - 1 , & V_192 ) ;
if ( V_193 ) {
V_38 = V_193 ;
goto V_198;
}
}
V_191 = F_168 ( V_19 , V_74 , V_194 + 1 ) ;
if ( V_191 ) {
F_19 ( V_191 ) ;
F_143 ( V_191 ) ;
V_193 = F_141 ( V_33 , V_19 , V_191 ,
V_74 , V_194 + 1 , & V_191 ) ;
if ( V_193 ) {
V_38 = V_193 ;
goto V_198;
}
}
if ( V_192 ) {
V_195 += F_90 ( V_192 ) ;
V_193 = F_169 ( V_33 , V_19 , V_192 , V_178 , 1 ) ;
if ( V_193 < 0 )
V_38 = V_193 ;
}
if ( V_191 ) {
V_193 = F_169 ( V_33 , V_19 , V_178 , V_191 , 1 ) ;
if ( V_193 < 0 && V_193 != - V_199 )
V_38 = V_193 ;
if ( F_90 ( V_191 ) == 0 ) {
F_110 ( V_33 , V_19 -> V_26 , V_191 ) ;
F_20 ( V_191 ) ;
F_170 ( V_19 , V_2 , V_39 + 1 , V_194 + 1 ) ;
F_166 ( V_19 , V_191 -> V_47 ) ;
F_117 ( V_33 , V_19 , V_191 , 0 , 1 ) ;
F_120 ( V_191 ) ;
V_191 = NULL ;
} else {
struct V_40 V_200 ;
F_35 ( V_191 , & V_200 , 0 ) ;
F_96 ( V_19 -> V_26 , V_74 ,
V_194 + 1 , 0 ) ;
F_123 ( V_74 , & V_200 , V_194 + 1 ) ;
F_50 ( V_74 ) ;
}
}
if ( F_90 ( V_178 ) == 1 ) {
if ( ! V_192 ) {
V_38 = - V_123 ;
F_106 ( V_19 -> V_26 , V_38 , NULL ) ;
goto V_198;
}
V_193 = F_171 ( V_33 , V_19 , V_178 , V_192 ) ;
if ( V_193 < 0 ) {
V_38 = V_193 ;
goto V_198;
}
if ( V_193 == 1 ) {
V_193 = F_169 ( V_33 , V_19 , V_192 , V_178 , 1 ) ;
if ( V_193 < 0 )
V_38 = V_193 ;
}
F_72 ( V_193 == 1 ) ;
}
if ( F_90 ( V_178 ) == 0 ) {
F_110 ( V_33 , V_19 -> V_26 , V_178 ) ;
F_20 ( V_178 ) ;
F_170 ( V_19 , V_2 , V_39 + 1 , V_194 ) ;
F_166 ( V_19 , V_178 -> V_47 ) ;
F_117 ( V_33 , V_19 , V_178 , 0 , 1 ) ;
F_120 ( V_178 ) ;
V_178 = NULL ;
} else {
struct V_40 V_201 ;
F_35 ( V_178 , & V_201 , 0 ) ;
F_96 ( V_19 -> V_26 , V_74 ,
V_194 , 0 ) ;
F_123 ( V_74 , & V_201 , V_194 ) ;
F_50 ( V_74 ) ;
}
if ( V_192 ) {
if ( F_90 ( V_192 ) > V_195 ) {
F_115 ( V_192 ) ;
V_2 -> V_8 [ V_39 ] = V_192 ;
V_2 -> V_17 [ V_39 + 1 ] -= 1 ;
V_2 -> V_17 [ V_39 ] = V_195 ;
if ( V_178 ) {
F_20 ( V_178 ) ;
F_11 ( V_178 ) ;
}
} else {
V_195 -= F_90 ( V_192 ) ;
V_2 -> V_17 [ V_39 ] = V_195 ;
}
}
if ( V_196 !=
F_81 ( V_2 -> V_8 [ V_39 ] , V_2 -> V_17 [ V_39 ] ) )
F_172 () ;
V_198:
if ( V_191 ) {
F_20 ( V_191 ) ;
F_11 ( V_191 ) ;
}
if ( V_192 ) {
if ( V_2 -> V_8 [ V_39 ] != V_192 )
F_20 ( V_192 ) ;
F_11 ( V_192 ) ;
}
return V_38 ;
}
static T_1 int F_173 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_39 )
{
struct V_14 * V_191 = NULL ;
struct V_14 * V_178 ;
struct V_14 * V_192 = NULL ;
struct V_14 * V_74 = NULL ;
int V_38 = 0 ;
int V_193 ;
int V_194 ;
int V_195 = V_2 -> V_17 [ V_39 ] ;
if ( V_39 == 0 )
return 1 ;
V_178 = V_2 -> V_8 [ V_39 ] ;
F_32 ( F_48 ( V_178 ) != V_33 -> V_43 ) ;
if ( V_39 < V_7 - 1 ) {
V_74 = V_2 -> V_8 [ V_39 + 1 ] ;
V_194 = V_2 -> V_17 [ V_39 + 1 ] ;
}
if ( ! V_74 )
return 1 ;
V_192 = F_168 ( V_19 , V_74 , V_194 - 1 ) ;
if ( V_192 ) {
T_4 V_202 ;
F_19 ( V_192 ) ;
F_143 ( V_192 ) ;
V_202 = F_90 ( V_192 ) ;
if ( V_202 >= F_132 ( V_19 ) - 1 ) {
V_193 = 1 ;
} else {
V_38 = F_141 ( V_33 , V_19 , V_192 , V_74 ,
V_194 - 1 , & V_192 ) ;
if ( V_38 )
V_193 = 1 ;
else {
V_193 = F_169 ( V_33 , V_19 ,
V_192 , V_178 , 0 ) ;
}
}
if ( V_193 < 0 )
V_38 = V_193 ;
if ( V_193 == 0 ) {
struct V_40 V_41 ;
V_195 += V_202 ;
F_35 ( V_178 , & V_41 , 0 ) ;
F_96 ( V_19 -> V_26 , V_74 ,
V_194 , 0 ) ;
F_123 ( V_74 , & V_41 , V_194 ) ;
F_50 ( V_74 ) ;
if ( F_90 ( V_192 ) > V_195 ) {
V_2 -> V_8 [ V_39 ] = V_192 ;
V_2 -> V_17 [ V_39 + 1 ] -= 1 ;
V_2 -> V_17 [ V_39 ] = V_195 ;
F_20 ( V_178 ) ;
F_11 ( V_178 ) ;
} else {
V_195 -=
F_90 ( V_192 ) ;
V_2 -> V_17 [ V_39 ] = V_195 ;
F_20 ( V_192 ) ;
F_11 ( V_192 ) ;
}
return 0 ;
}
F_20 ( V_192 ) ;
F_11 ( V_192 ) ;
}
V_191 = F_168 ( V_19 , V_74 , V_194 + 1 ) ;
if ( V_191 ) {
T_4 V_203 ;
F_19 ( V_191 ) ;
F_143 ( V_191 ) ;
V_203 = F_90 ( V_191 ) ;
if ( V_203 >= F_132 ( V_19 ) - 1 ) {
V_193 = 1 ;
} else {
V_38 = F_141 ( V_33 , V_19 , V_191 ,
V_74 , V_194 + 1 ,
& V_191 ) ;
if ( V_38 )
V_193 = 1 ;
else {
V_193 = F_171 ( V_33 , V_19 ,
V_191 , V_178 ) ;
}
}
if ( V_193 < 0 )
V_38 = V_193 ;
if ( V_193 == 0 ) {
struct V_40 V_41 ;
F_35 ( V_191 , & V_41 , 0 ) ;
F_96 ( V_19 -> V_26 , V_74 ,
V_194 + 1 , 0 ) ;
F_123 ( V_74 , & V_41 , V_194 + 1 ) ;
F_50 ( V_74 ) ;
if ( F_90 ( V_178 ) <= V_195 ) {
V_2 -> V_8 [ V_39 ] = V_191 ;
V_2 -> V_17 [ V_39 + 1 ] += 1 ;
V_2 -> V_17 [ V_39 ] = V_195 -
F_90 ( V_178 ) ;
F_20 ( V_178 ) ;
F_11 ( V_178 ) ;
} else {
F_20 ( V_191 ) ;
F_11 ( V_191 ) ;
}
return 0 ;
}
F_20 ( V_191 ) ;
F_11 ( V_191 ) ;
}
return 1 ;
}
static void F_174 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int V_39 , int V_80 , T_2 V_28 )
{
struct V_14 * V_21 ;
struct V_40 V_41 ;
T_4 V_98 ;
T_2 V_204 ;
T_2 V_205 ;
T_2 V_206 = 0 ;
T_2 V_161 ;
struct V_14 * V_20 ;
T_4 V_173 ;
T_4 V_152 ;
T_4 V_207 = 0 ;
if ( V_39 != 1 )
return;
if ( ! V_2 -> V_8 [ V_39 ] )
return;
V_21 = V_2 -> V_8 [ V_39 ] ;
V_204 = F_81 ( V_21 , V_80 ) ;
V_152 = V_19 -> V_169 ;
V_20 = F_150 ( V_19 -> V_26 , V_204 ) ;
if ( V_20 ) {
F_11 ( V_20 ) ;
return;
}
V_205 = V_204 ;
V_98 = F_90 ( V_21 ) ;
V_173 = V_80 ;
while ( 1 ) {
if ( V_2 -> V_208 == V_209 ) {
if ( V_173 == 0 )
break;
V_173 -- ;
} else if ( V_2 -> V_208 == V_210 ) {
V_173 ++ ;
if ( V_173 >= V_98 )
break;
}
if ( V_2 -> V_208 == V_209 && V_28 ) {
F_35 ( V_21 , & V_41 , V_173 ) ;
if ( F_175 ( & V_41 ) != V_28 )
break;
}
V_204 = F_81 ( V_21 , V_173 ) ;
if ( ( V_204 <= V_205 && V_205 - V_204 <= 65536 ) ||
( V_204 > V_205 && V_204 - V_205 <= 65536 ) ) {
V_161 = F_82 ( V_21 , V_173 ) ;
F_176 ( V_19 , V_204 ) ;
V_206 += V_152 ;
}
V_207 ++ ;
if ( ( V_206 > 65536 || V_207 > 32 ) )
break;
}
}
static T_1 void F_177 ( struct V_18 * V_19 ,
struct V_1 * V_2 , int V_39 )
{
int V_80 ;
int V_98 ;
struct V_14 * V_74 ;
struct V_14 * V_20 ;
T_2 V_161 ;
T_2 V_211 = 0 ;
T_2 V_212 = 0 ;
V_74 = V_2 -> V_8 [ V_39 + 1 ] ;
if ( ! V_74 )
return;
V_98 = F_90 ( V_74 ) ;
V_80 = V_2 -> V_17 [ V_39 + 1 ] ;
if ( V_80 > 0 ) {
V_211 = F_81 ( V_74 , V_80 - 1 ) ;
V_161 = F_82 ( V_74 , V_80 - 1 ) ;
V_20 = F_150 ( V_19 -> V_26 , V_211 ) ;
if ( V_20 && F_151 ( V_20 , V_161 , 1 ) != 0 )
V_211 = 0 ;
F_11 ( V_20 ) ;
}
if ( V_80 + 1 < V_98 ) {
V_212 = F_81 ( V_74 , V_80 + 1 ) ;
V_161 = F_82 ( V_74 , V_80 + 1 ) ;
V_20 = F_150 ( V_19 -> V_26 , V_212 ) ;
if ( V_20 && F_151 ( V_20 , V_161 , 1 ) != 0 )
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
T_4 V_98 ;
V_218 = V_2 -> V_8 [ V_6 ] ;
V_98 = F_90 ( V_218 ) ;
if ( V_98 < 1 || V_2 -> V_17 [ V_6 ] >= V_98 - 1 ) {
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
struct V_154 * V_85 , T_2 V_132 )
{
T_2 V_150 ;
T_2 V_161 ;
struct V_14 * V_221 = * V_220 ;
struct V_14 * V_179 ;
int V_38 ;
V_150 = F_81 ( V_221 , V_80 ) ;
V_161 = F_82 ( V_221 , V_80 ) ;
V_179 = F_150 ( V_19 -> V_26 , V_150 ) ;
if ( V_179 ) {
if ( F_151 ( V_179 , V_161 , 1 ) > 0 ) {
* V_220 = V_179 ;
return 0 ;
}
F_3 ( V_5 ) ;
V_38 = F_152 ( V_179 , V_161 ) ;
if ( ! V_38 ) {
* V_220 = V_179 ;
return 0 ;
}
F_11 ( V_179 ) ;
F_8 ( V_5 ) ;
return - V_171 ;
}
F_179 ( V_5 , V_39 + 1 ) ;
F_3 ( V_5 ) ;
F_11 ( V_179 ) ;
if ( V_5 -> V_208 != V_222 )
F_174 ( V_19 , V_5 , V_39 , V_80 , V_85 -> V_28 ) ;
F_8 ( V_5 ) ;
V_38 = - V_223 ;
V_179 = F_134 ( V_19 , V_150 , 0 ) ;
if ( ! F_37 ( V_179 ) ) {
if ( ! F_151 ( V_179 , 0 , 0 ) )
V_38 = - V_171 ;
F_11 ( V_179 ) ;
}
return V_38 ;
}
static int
F_181 ( struct V_32 * V_33 ,
struct V_18 * V_19 , struct V_1 * V_5 ,
struct V_14 * V_221 , int V_39 , int V_224 ,
int * V_215 )
{
int V_38 ;
if ( ( V_5 -> V_225 || V_224 > 0 ) && F_90 ( V_221 ) >=
F_132 ( V_19 ) - 3 ) {
int V_226 ;
if ( * V_215 < V_39 + 1 ) {
* V_215 = V_39 + 1 ;
F_8 ( V_5 ) ;
goto V_227;
}
F_3 ( V_5 ) ;
F_177 ( V_19 , V_5 , V_39 ) ;
V_226 = F_182 ( V_33 , V_19 , V_5 , V_39 ) ;
F_5 ( V_5 , NULL , 0 ) ;
F_72 ( V_226 > 0 ) ;
if ( V_226 ) {
V_38 = V_226 ;
goto V_228;
}
V_221 = V_5 -> V_8 [ V_39 ] ;
} else if ( V_224 < 0 && F_90 ( V_221 ) <
F_132 ( V_19 ) / 2 ) {
int V_226 ;
if ( * V_215 < V_39 + 1 ) {
* V_215 = V_39 + 1 ;
F_8 ( V_5 ) ;
goto V_227;
}
F_3 ( V_5 ) ;
F_177 ( V_19 , V_5 , V_39 ) ;
V_226 = F_167 ( V_33 , V_19 , V_5 , V_39 ) ;
F_5 ( V_5 , NULL , 0 ) ;
if ( V_226 ) {
V_38 = V_226 ;
goto V_228;
}
V_221 = V_5 -> V_8 [ V_39 ] ;
if ( ! V_221 ) {
F_8 ( V_5 ) ;
goto V_227;
}
F_72 ( F_90 ( V_221 ) == 1 ) ;
}
return 0 ;
V_227:
V_38 = - V_223 ;
V_228:
return V_38 ;
}
static void F_183 ( struct V_14 * V_221 ,
struct V_154 * V_85 ,
int V_39 )
{
#ifdef F_184
struct V_40 V_41 ;
F_185 ( & V_41 , V_85 ) ;
if ( V_39 == 0 )
ASSERT ( ! F_186 ( V_221 , & V_41 ,
F_161 ( struct V_184 , V_185 [ 0 ] . V_85 ) ,
sizeof( V_41 ) ) ) ;
else
ASSERT ( ! F_186 ( V_221 , & V_41 ,
F_161 ( struct V_187 , V_188 [ 0 ] . V_85 ) ,
sizeof( V_41 ) ) ) ;
#endif
}
static int F_187 ( struct V_14 * V_221 , struct V_154 * V_85 ,
int V_39 , int * V_229 , int * V_80 )
{
if ( * V_229 != 0 ) {
* V_229 = F_160 ( V_221 , V_85 , V_39 , V_80 ) ;
return * V_229 ;
}
F_183 ( V_221 , V_85 , V_39 ) ;
* V_80 = 0 ;
return 0 ;
}
int F_188 ( struct V_18 * V_230 , struct V_1 * V_2 ,
T_2 V_231 , T_2 V_232 , T_5 V_233 ,
struct V_154 * V_234 )
{
int V_38 ;
struct V_154 V_85 ;
struct V_14 * V_20 ;
ASSERT ( V_2 ) ;
ASSERT ( V_234 ) ;
V_85 . type = V_233 ;
V_85 . V_28 = V_231 ;
V_85 . V_157 = V_232 ;
V_38 = F_189 ( NULL , V_230 , & V_85 , V_2 , 0 , 0 ) ;
if ( V_38 < 0 )
return V_38 ;
V_20 = V_2 -> V_8 [ 0 ] ;
if ( V_38 && V_2 -> V_17 [ 0 ] >= F_90 ( V_20 ) ) {
V_38 = F_190 ( V_230 , V_2 ) ;
if ( V_38 )
return V_38 ;
V_20 = V_2 -> V_8 [ 0 ] ;
}
F_191 ( V_20 , V_234 , V_2 -> V_17 [ 0 ] ) ;
if ( V_234 -> type != V_85 . type ||
V_234 -> V_28 != V_85 . V_28 )
return 1 ;
return 0 ;
}
int F_189 ( struct V_32 * V_33 , struct V_18
* V_19 , struct V_154 * V_85 , struct V_1 * V_5 , int
V_224 , int V_37 )
{
struct V_14 * V_221 ;
int V_80 ;
int V_38 ;
int V_165 ;
int V_39 ;
int V_213 = 1 ;
int V_235 ;
int V_215 = 0 ;
T_5 V_236 = 0 ;
int V_214 ;
int V_229 ;
V_236 = V_5 -> V_236 ;
F_32 ( V_236 && V_224 > 0 ) ;
F_32 ( V_5 -> V_8 [ 0 ] != NULL ) ;
F_72 ( ! V_37 && V_224 ) ;
if ( V_224 < 0 ) {
V_213 = 2 ;
V_215 = 2 ;
} else if ( V_224 > 0 ) {
V_215 = 1 ;
}
if ( ! V_37 )
V_215 = - 1 ;
if ( V_37 && ( V_5 -> V_219 || V_5 -> V_236 ) )
V_215 = V_7 ;
V_214 = V_215 ;
V_227:
V_229 = - 1 ;
V_235 = V_10 ;
V_39 = 0 ;
if ( V_5 -> V_237 ) {
if ( V_5 -> V_238 )
F_192 ( & V_19 -> V_26 -> V_239 ) ;
V_221 = V_19 -> V_118 ;
F_115 ( V_221 ) ;
V_39 = F_33 ( V_221 ) ;
if ( V_5 -> V_238 )
F_193 ( & V_19 -> V_26 -> V_239 ) ;
if ( ! V_5 -> V_240 )
F_22 ( V_221 ) ;
} else {
if ( V_5 -> V_240 ) {
V_221 = F_12 ( V_19 ) ;
V_39 = F_33 ( V_221 ) ;
} else {
V_221 = F_21 ( V_19 ) ;
V_39 = F_33 ( V_221 ) ;
if ( V_39 <= V_215 ) {
F_23 ( V_221 ) ;
F_11 ( V_221 ) ;
V_221 = F_18 ( V_19 ) ;
V_235 = V_12 ;
V_39 = F_33 ( V_221 ) ;
}
}
}
V_5 -> V_8 [ V_39 ] = V_221 ;
if ( ! V_5 -> V_240 )
V_5 -> V_9 [ V_39 ] = V_235 ;
while ( V_221 ) {
V_39 = F_33 ( V_221 ) ;
if ( V_37 ) {
if ( ! F_138 ( V_33 , V_19 , V_221 ) )
goto V_241;
if ( V_39 > V_215 ||
( V_39 + 1 > V_215 &&
V_39 + 1 < V_7 &&
V_5 -> V_8 [ V_39 + 1 ] ) ) {
V_215 = V_39 + 1 ;
F_8 ( V_5 ) ;
goto V_227;
}
F_3 ( V_5 ) ;
V_165 = F_141 ( V_33 , V_19 , V_221 ,
V_5 -> V_8 [ V_39 + 1 ] ,
V_5 -> V_17 [ V_39 + 1 ] , & V_221 ) ;
if ( V_165 ) {
V_38 = V_165 ;
goto V_228;
}
}
V_241:
V_5 -> V_8 [ V_39 ] = V_221 ;
F_5 ( V_5 , NULL , 0 ) ;
if ( ! V_224 && ! V_5 -> V_219 ) {
int V_242 = V_39 + 1 ;
if ( V_242 < V_7 && V_5 -> V_9 [ V_242 ] ) {
F_10 ( V_5 -> V_8 [ V_242 ] , V_5 -> V_9 [ V_242 ] ) ;
V_5 -> V_9 [ V_242 ] = 0 ;
}
}
V_38 = F_187 ( V_221 , V_85 , V_39 , & V_229 , & V_80 ) ;
if ( V_39 != 0 ) {
int V_243 = 0 ;
if ( V_38 && V_80 > 0 ) {
V_243 = 1 ;
V_80 -= 1 ;
}
V_5 -> V_17 [ V_39 ] = V_80 ;
V_165 = F_181 ( V_33 , V_19 , V_5 , V_221 , V_39 ,
V_224 , & V_215 ) ;
if ( V_165 == - V_223 )
goto V_227;
if ( V_165 ) {
V_38 = V_165 ;
goto V_228;
}
V_221 = V_5 -> V_8 [ V_39 ] ;
V_80 = V_5 -> V_17 [ V_39 ] ;
if ( V_80 == 0 && V_224 &&
V_215 < V_39 + 1 ) {
V_215 = V_39 + 1 ;
F_8 ( V_5 ) ;
goto V_227;
}
F_178 ( V_5 , V_39 , V_213 ,
V_214 , & V_215 ) ;
if ( V_39 == V_236 ) {
if ( V_243 )
V_5 -> V_17 [ V_39 ] ++ ;
goto V_228;
}
V_165 = F_180 ( V_33 , V_19 , V_5 ,
& V_221 , V_39 , V_80 , V_85 , 0 ) ;
if ( V_165 == - V_223 )
goto V_227;
if ( V_165 ) {
V_38 = V_165 ;
goto V_228;
}
if ( ! V_5 -> V_240 ) {
V_39 = F_33 ( V_221 ) ;
if ( V_39 <= V_215 ) {
V_165 = F_194 ( V_221 ) ;
if ( ! V_165 ) {
F_3 ( V_5 ) ;
F_19 ( V_221 ) ;
F_5 ( V_5 , V_221 ,
V_12 ) ;
}
V_5 -> V_9 [ V_39 ] = V_12 ;
} else {
V_165 = F_195 ( V_221 ) ;
if ( ! V_165 ) {
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
if ( V_224 > 0 &&
F_196 ( V_19 , V_221 ) < V_224 ) {
if ( V_215 < 1 ) {
V_215 = 1 ;
F_8 ( V_5 ) ;
goto V_227;
}
F_3 ( V_5 ) ;
V_165 = F_197 ( V_33 , V_19 , V_85 ,
V_5 , V_224 , V_38 == 0 ) ;
F_5 ( V_5 , NULL , 0 ) ;
F_72 ( V_165 > 0 ) ;
if ( V_165 ) {
V_38 = V_165 ;
goto V_228;
}
}
if ( ! V_5 -> V_225 )
F_178 ( V_5 , V_39 , V_213 ,
V_214 , & V_215 ) ;
goto V_228;
}
}
V_38 = 1 ;
V_228:
if ( ! V_5 -> V_244 )
F_3 ( V_5 ) ;
if ( V_38 < 0 && ! V_5 -> V_245 )
F_8 ( V_5 ) ;
return V_38 ;
}
int F_198 ( struct V_18 * V_19 , struct V_154 * V_85 ,
struct V_1 * V_5 , T_2 V_132 )
{
struct V_14 * V_221 ;
int V_80 ;
int V_38 ;
int V_165 ;
int V_39 ;
int V_213 = 1 ;
T_5 V_236 = 0 ;
int V_229 = - 1 ;
V_236 = V_5 -> V_236 ;
F_32 ( V_5 -> V_8 [ 0 ] != NULL ) ;
if ( V_5 -> V_237 ) {
F_72 ( V_132 ) ;
return F_189 ( NULL , V_19 , V_85 , V_5 , 0 , 0 ) ;
}
V_227:
V_221 = F_133 ( V_19 , V_132 ) ;
V_39 = F_33 ( V_221 ) ;
V_5 -> V_9 [ V_39 ] = V_10 ;
while ( V_221 ) {
V_39 = F_33 ( V_221 ) ;
V_5 -> V_8 [ V_39 ] = V_221 ;
F_5 ( V_5 , NULL , 0 ) ;
F_179 ( V_5 , V_39 + 1 ) ;
V_229 = - 1 ;
V_38 = F_187 ( V_221 , V_85 , V_39 , & V_229 , & V_80 ) ;
if ( V_39 != 0 ) {
int V_243 = 0 ;
if ( V_38 && V_80 > 0 ) {
V_243 = 1 ;
V_80 -= 1 ;
}
V_5 -> V_17 [ V_39 ] = V_80 ;
F_178 ( V_5 , V_39 , V_213 , 0 , NULL ) ;
if ( V_39 == V_236 ) {
if ( V_243 )
V_5 -> V_17 [ V_39 ] ++ ;
goto V_228;
}
V_165 = F_180 ( NULL , V_19 , V_5 , & V_221 , V_39 ,
V_80 , V_85 , V_132 ) ;
if ( V_165 == - V_223 )
goto V_227;
if ( V_165 ) {
V_38 = V_165 ;
goto V_228;
}
V_39 = F_33 ( V_221 ) ;
V_165 = F_195 ( V_221 ) ;
if ( ! V_165 ) {
F_3 ( V_5 ) ;
F_22 ( V_221 ) ;
F_5 ( V_5 , V_221 ,
V_10 ) ;
}
V_221 = F_127 ( V_19 -> V_26 , V_5 , V_221 , V_132 ) ;
if ( ! V_221 ) {
V_38 = - V_88 ;
goto V_228;
}
V_5 -> V_9 [ V_39 ] = V_10 ;
V_5 -> V_8 [ V_39 ] = V_221 ;
} else {
V_5 -> V_17 [ V_39 ] = V_80 ;
F_178 ( V_5 , V_39 , V_213 , 0 , NULL ) ;
goto V_228;
}
}
V_38 = 1 ;
V_228:
if ( ! V_5 -> V_244 )
F_3 ( V_5 ) ;
if ( V_38 < 0 )
F_8 ( V_5 ) ;
return V_38 ;
}
int F_199 ( struct V_18 * V_19 ,
struct V_154 * V_85 , struct V_1 * V_5 ,
int V_246 , int V_247 )
{
int V_38 ;
struct V_14 * V_172 ;
V_227:
V_38 = F_189 ( NULL , V_19 , V_85 , V_5 , 0 , 0 ) ;
if ( V_38 <= 0 )
return V_38 ;
V_172 = V_5 -> V_8 [ 0 ] ;
if ( V_246 ) {
if ( V_5 -> V_17 [ 0 ] >= F_90 ( V_172 ) ) {
V_38 = F_190 ( V_19 , V_5 ) ;
if ( V_38 <= 0 )
return V_38 ;
if ( ! V_247 )
return 1 ;
V_247 = 0 ;
V_246 = 0 ;
F_8 ( V_5 ) ;
goto V_227;
}
} else {
if ( V_5 -> V_17 [ 0 ] == 0 ) {
V_38 = F_200 ( V_19 , V_5 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( ! V_38 ) {
V_172 = V_5 -> V_8 [ 0 ] ;
if ( V_5 -> V_17 [ 0 ] == F_90 ( V_172 ) )
V_5 -> V_17 [ 0 ] -- ;
return 0 ;
}
if ( ! V_247 )
return 1 ;
V_247 = 0 ;
V_246 = 1 ;
F_8 ( V_5 ) ;
goto V_227;
} else {
-- V_5 -> V_17 [ 0 ] ;
}
}
return 0 ;
}
static void F_201 ( struct V_54 * V_26 ,
struct V_1 * V_2 ,
struct V_40 * V_85 , int V_39 )
{
int V_6 ;
struct V_14 * V_218 ;
for ( V_6 = V_39 ; V_6 < V_7 ; V_6 ++ ) {
int V_248 = V_2 -> V_17 [ V_6 ] ;
if ( ! V_2 -> V_8 [ V_6 ] )
break;
V_218 = V_2 -> V_8 [ V_6 ] ;
F_96 ( V_26 , V_218 , V_248 , 1 ) ;
F_123 ( V_218 , V_85 , V_248 ) ;
F_50 ( V_2 -> V_8 [ V_6 ] ) ;
if ( V_248 != 0 )
break;
}
}
void F_202 ( struct V_54 * V_26 ,
struct V_1 * V_2 ,
struct V_154 * V_249 )
{
struct V_40 V_41 ;
struct V_14 * V_20 ;
int V_80 ;
V_20 = V_2 -> V_8 [ 0 ] ;
V_80 = V_2 -> V_17 [ 0 ] ;
if ( V_80 > 0 ) {
F_34 ( V_20 , & V_41 , V_80 - 1 ) ;
F_72 ( F_146 ( & V_41 , V_249 ) >= 0 ) ;
}
if ( V_80 < F_90 ( V_20 ) - 1 ) {
F_34 ( V_20 , & V_41 , V_80 + 1 ) ;
F_72 ( F_146 ( & V_41 , V_249 ) <= 0 ) ;
}
F_185 ( & V_41 , V_249 ) ;
F_203 ( V_20 , & V_41 , V_80 ) ;
F_50 ( V_20 ) ;
if ( V_80 == 0 )
F_201 ( V_26 , V_2 , & V_41 , 1 ) ;
}
static int F_169 ( struct V_32 * V_33 ,
struct V_18 * V_19 , struct V_14 * V_107 ,
struct V_14 * V_108 , int V_250 )
{
int V_251 = 0 ;
int V_252 ;
int V_253 ;
int V_38 = 0 ;
V_252 = F_90 ( V_108 ) ;
V_253 = F_90 ( V_107 ) ;
V_251 = F_132 ( V_19 ) - V_253 ;
F_32 ( F_48 ( V_108 ) != V_33 -> V_43 ) ;
F_32 ( F_48 ( V_107 ) != V_33 -> V_43 ) ;
if ( ! V_250 && V_252 <= 8 )
return 1 ;
if ( V_251 <= 0 )
return 1 ;
if ( V_250 ) {
V_251 = F_153 ( V_252 , V_251 ) ;
if ( V_251 < V_252 ) {
if ( V_252 - V_251 < 8 ) {
if ( V_251 <= 8 )
return 1 ;
V_251 -= 8 ;
}
}
} else
V_251 = F_153 ( V_252 - 8 , V_251 ) ;
V_38 = F_94 ( V_19 -> V_26 , V_107 , V_108 , V_253 , 0 ,
V_251 ) ;
if ( V_38 ) {
F_113 ( V_33 , V_19 , V_38 ) ;
return V_38 ;
}
F_39 ( V_107 , V_108 ,
F_124 ( V_253 ) ,
F_124 ( 0 ) ,
V_251 * sizeof( struct V_140 ) ) ;
if ( V_251 < V_252 ) {
F_125 ( V_108 , F_124 ( 0 ) ,
F_124 ( V_251 ) ,
( V_252 - V_251 ) *
sizeof( struct V_140 ) ) ;
}
F_126 ( V_108 , V_252 - V_251 ) ;
F_126 ( V_107 , V_253 + V_251 ) ;
F_50 ( V_108 ) ;
F_50 ( V_107 ) ;
return V_38 ;
}
static int F_171 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_14 * V_107 ,
struct V_14 * V_108 )
{
int V_251 = 0 ;
int V_254 ;
int V_252 ;
int V_253 ;
int V_38 = 0 ;
F_32 ( F_48 ( V_108 ) != V_33 -> V_43 ) ;
F_32 ( F_48 ( V_107 ) != V_33 -> V_43 ) ;
V_252 = F_90 ( V_108 ) ;
V_253 = F_90 ( V_107 ) ;
V_251 = F_132 ( V_19 ) - V_253 ;
if ( V_251 <= 0 )
return 1 ;
if ( V_252 < 4 )
return 1 ;
V_254 = V_252 / 2 + 1 ;
if ( V_254 >= V_252 )
return 1 ;
if ( V_254 < V_251 )
V_251 = V_254 ;
F_95 ( V_19 -> V_26 , V_107 , V_251 , 0 , V_253 ) ;
F_125 ( V_107 , F_124 ( V_251 ) ,
F_124 ( 0 ) ,
( V_253 ) *
sizeof( struct V_140 ) ) ;
V_38 = F_94 ( V_19 -> V_26 , V_107 , V_108 , 0 ,
V_252 - V_251 , V_251 ) ;
if ( V_38 ) {
F_113 ( V_33 , V_19 , V_38 ) ;
return V_38 ;
}
F_39 ( V_107 , V_108 ,
F_124 ( 0 ) ,
F_124 ( V_252 - V_251 ) ,
V_251 * sizeof( struct V_140 ) ) ;
F_126 ( V_108 , V_252 - V_251 ) ;
F_126 ( V_107 , V_253 + V_251 ) ;
F_50 ( V_108 ) ;
F_50 ( V_107 ) ;
return V_38 ;
}
static T_1 int F_204 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_39 )
{
T_2 V_255 ;
struct V_14 * V_256 ;
struct V_14 * V_257 ;
struct V_14 * V_143 ;
struct V_40 V_258 ;
F_72 ( V_2 -> V_8 [ V_39 ] ) ;
F_72 ( V_2 -> V_8 [ V_39 - 1 ] != V_19 -> V_21 ) ;
V_256 = V_2 -> V_8 [ V_39 - 1 ] ;
if ( V_39 == 1 )
F_34 ( V_256 , & V_258 , 0 ) ;
else
F_35 ( V_256 , & V_258 , 0 ) ;
V_257 = F_36 ( V_33 , V_19 , 0 , V_19 -> V_124 . V_28 ,
& V_258 , V_39 , V_19 -> V_21 -> V_46 , 0 ) ;
if ( F_37 ( V_257 ) )
return F_38 ( V_257 ) ;
F_163 ( V_19 , V_19 -> V_169 ) ;
F_205 ( V_257 , 0 , 0 , sizeof( struct V_259 ) ) ;
F_126 ( V_257 , 1 ) ;
F_130 ( V_257 , V_39 ) ;
F_40 ( V_257 , V_257 -> V_46 ) ;
F_41 ( V_257 , V_33 -> V_43 ) ;
F_42 ( V_257 , V_48 ) ;
F_45 ( V_257 , V_19 -> V_124 . V_28 ) ;
F_46 ( V_257 , V_19 -> V_26 -> V_52 , F_47 () ,
V_53 ) ;
F_46 ( V_257 , V_19 -> V_26 -> V_260 ,
F_206 ( V_257 ) , V_261 ) ;
F_123 ( V_257 , & V_258 , 0 ) ;
F_118 ( V_257 , 0 , V_256 -> V_46 ) ;
V_255 = F_48 ( V_256 ) ;
F_32 ( V_255 != V_33 -> V_43 ) ;
F_119 ( V_257 , 0 , V_255 ) ;
F_50 ( V_257 ) ;
V_143 = V_19 -> V_21 ;
F_98 ( V_19 , V_257 , 0 ) ;
F_116 ( V_19 -> V_21 , V_257 ) ;
F_11 ( V_143 ) ;
F_24 ( V_19 ) ;
F_115 ( V_257 ) ;
V_2 -> V_8 [ V_39 ] = V_257 ;
V_2 -> V_9 [ V_39 ] = V_13 ;
V_2 -> V_17 [ V_39 ] = 0 ;
return 0 ;
}
static void F_207 ( struct V_32 * V_33 ,
struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_40 * V_85 , T_2 V_262 ,
int V_80 , int V_39 )
{
struct V_14 * V_256 ;
int V_98 ;
int V_38 ;
F_72 ( ! V_2 -> V_8 [ V_39 ] ) ;
F_112 ( V_2 -> V_8 [ V_39 ] ) ;
V_256 = V_2 -> V_8 [ V_39 ] ;
V_98 = F_90 ( V_256 ) ;
F_72 ( V_80 > V_98 ) ;
F_72 ( V_98 == F_132 ( V_19 ) ) ;
if ( V_80 != V_98 ) {
if ( V_39 )
F_95 ( V_19 -> V_26 , V_256 , V_80 + 1 ,
V_80 , V_98 - V_80 ) ;
F_125 ( V_256 ,
F_124 ( V_80 + 1 ) ,
F_124 ( V_80 ) ,
( V_98 - V_80 ) * sizeof( struct V_140 ) ) ;
}
if ( V_39 ) {
V_38 = F_84 ( V_19 -> V_26 , V_256 , V_80 ,
V_84 , V_4 ) ;
F_72 ( V_38 < 0 ) ;
}
F_123 ( V_256 , V_85 , V_80 ) ;
F_118 ( V_256 , V_80 , V_262 ) ;
F_32 ( V_33 -> V_43 == 0 ) ;
F_119 ( V_256 , V_80 , V_33 -> V_43 ) ;
F_126 ( V_256 , V_98 + 1 ) ;
F_50 ( V_256 ) ;
}
static T_1 int F_182 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_39 )
{
struct V_14 * V_257 ;
struct V_14 * V_263 ;
struct V_40 V_41 ;
int V_178 ;
int V_38 ;
T_4 V_264 ;
V_257 = V_2 -> V_8 [ V_39 ] ;
F_32 ( F_48 ( V_257 ) != V_33 -> V_43 ) ;
if ( V_257 == V_19 -> V_21 ) {
V_38 = F_204 ( V_33 , V_19 , V_2 , V_39 + 1 ) ;
if ( V_38 )
return V_38 ;
} else {
V_38 = F_173 ( V_33 , V_19 , V_2 , V_39 ) ;
V_257 = V_2 -> V_8 [ V_39 ] ;
if ( ! V_38 && F_90 ( V_257 ) <
F_132 ( V_19 ) - 3 )
return 0 ;
if ( V_38 < 0 )
return V_38 ;
}
V_264 = F_90 ( V_257 ) ;
V_178 = ( V_264 + 1 ) / 2 ;
F_35 ( V_257 , & V_41 , V_178 ) ;
V_263 = F_36 ( V_33 , V_19 , 0 , V_19 -> V_124 . V_28 ,
& V_41 , V_39 , V_257 -> V_46 , 0 ) ;
if ( F_37 ( V_263 ) )
return F_38 ( V_263 ) ;
F_163 ( V_19 , V_19 -> V_169 ) ;
F_205 ( V_263 , 0 , 0 , sizeof( struct V_259 ) ) ;
F_130 ( V_263 , F_33 ( V_257 ) ) ;
F_40 ( V_263 , V_263 -> V_46 ) ;
F_41 ( V_263 , V_33 -> V_43 ) ;
F_42 ( V_263 , V_48 ) ;
F_45 ( V_263 , V_19 -> V_124 . V_28 ) ;
F_46 ( V_263 , V_19 -> V_26 -> V_52 ,
F_47 () , V_53 ) ;
F_46 ( V_263 , V_19 -> V_26 -> V_260 ,
F_206 ( V_263 ) ,
V_261 ) ;
V_38 = F_94 ( V_19 -> V_26 , V_263 , V_257 , 0 ,
V_178 , V_264 - V_178 ) ;
if ( V_38 ) {
F_113 ( V_33 , V_19 , V_38 ) ;
return V_38 ;
}
F_39 ( V_263 , V_257 ,
F_124 ( 0 ) ,
F_124 ( V_178 ) ,
( V_264 - V_178 ) * sizeof( struct V_140 ) ) ;
F_126 ( V_263 , V_264 - V_178 ) ;
F_126 ( V_257 , V_178 ) ;
V_38 = 0 ;
F_50 ( V_257 ) ;
F_50 ( V_263 ) ;
F_207 ( V_33 , V_19 , V_2 , & V_41 , V_263 -> V_46 ,
V_2 -> V_17 [ V_39 + 1 ] + 1 , V_39 + 1 ) ;
if ( V_2 -> V_17 [ V_39 ] >= V_178 ) {
V_2 -> V_17 [ V_39 ] -= V_178 ;
F_20 ( V_257 ) ;
F_11 ( V_257 ) ;
V_2 -> V_8 [ V_39 ] = V_263 ;
V_2 -> V_17 [ V_39 + 1 ] += 1 ;
} else {
F_20 ( V_263 ) ;
F_11 ( V_263 ) ;
}
return V_38 ;
}
static int F_208 ( struct V_14 * V_265 , int V_46 , int V_173 )
{
struct V_186 * V_266 ;
struct V_186 * V_267 ;
struct V_268 V_269 ;
int V_270 ;
int V_98 = F_90 ( V_265 ) ;
int V_271 = F_153 ( V_98 , V_46 + V_173 ) - 1 ;
if ( ! V_173 )
return 0 ;
F_209 ( & V_269 ) ;
V_266 = F_210 ( V_46 ) ;
V_267 = F_210 ( V_271 ) ;
V_270 = F_211 ( V_265 , V_266 , & V_269 ) +
F_212 ( V_265 , V_266 , & V_269 ) ;
V_270 = V_270 - F_211 ( V_265 , V_267 , & V_269 ) ;
V_270 += sizeof( struct V_186 ) * V_173 ;
F_32 ( V_270 < 0 ) ;
return V_270 ;
}
T_1 int F_196 ( struct V_18 * V_19 ,
struct V_14 * V_172 )
{
int V_98 = F_90 ( V_172 ) ;
int V_38 ;
V_38 = F_155 ( V_19 ) - F_208 ( V_172 , 0 , V_98 ) ;
if ( V_38 < 0 ) {
F_213 ( V_19 -> V_26 ,
L_3 ,
V_38 , ( unsigned long ) F_155 ( V_19 ) ,
F_208 ( V_172 , 0 , V_98 ) , V_98 ) ;
}
return V_38 ;
}
static T_1 int F_214 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
int V_272 , int V_250 ,
struct V_14 * V_191 ,
int V_273 , T_4 V_274 ,
T_4 V_275 )
{
struct V_14 * V_192 = V_2 -> V_8 [ 0 ] ;
struct V_14 * V_276 = V_2 -> V_8 [ 1 ] ;
struct V_268 V_269 ;
struct V_40 V_41 ;
int V_80 ;
T_4 V_6 ;
int V_277 = 0 ;
int V_251 = 0 ;
struct V_186 * V_278 ;
T_4 V_173 ;
T_4 V_279 ;
T_4 V_280 ;
T_4 V_281 ;
F_209 ( & V_269 ) ;
if ( V_250 )
V_173 = 0 ;
else
V_173 = F_215 ( T_4 , 1 , V_275 ) ;
if ( V_2 -> V_17 [ 0 ] >= V_274 )
V_277 += V_272 ;
V_80 = V_2 -> V_17 [ 1 ] ;
V_6 = V_274 - 1 ;
while ( V_6 >= V_173 ) {
V_278 = F_210 ( V_6 ) ;
if ( ! V_250 && V_251 > 0 ) {
if ( V_2 -> V_17 [ 0 ] > V_6 )
break;
if ( V_2 -> V_17 [ 0 ] == V_6 ) {
int V_282 = F_196 ( V_19 , V_192 ) ;
if ( V_282 + V_277 * 2 > V_273 )
break;
}
}
if ( V_2 -> V_17 [ 0 ] == V_6 )
V_277 += V_272 ;
V_281 = F_216 ( V_192 , V_278 ) ;
if ( V_281 + sizeof( * V_278 ) + V_277 > V_273 )
break;
V_251 ++ ;
V_277 += V_281 + sizeof( * V_278 ) ;
if ( V_6 == 0 )
break;
V_6 -- ;
}
if ( V_251 == 0 )
goto V_283;
F_32 ( ! V_250 && V_251 == V_274 ) ;
V_279 = F_90 ( V_191 ) ;
V_277 = F_217 ( V_192 , V_274 - V_251 ) ;
V_277 -= F_154 ( V_19 , V_192 ) ;
V_280 = F_154 ( V_19 , V_191 ) ;
F_125 ( V_191 ,
F_218 ( V_191 ) + V_280 - V_277 ,
F_218 ( V_191 ) + V_280 ,
F_155 ( V_19 ) - V_280 ) ;
F_39 ( V_191 , V_192 , F_218 ( V_191 ) +
F_155 ( V_19 ) - V_277 ,
F_218 ( V_192 ) + F_154 ( V_19 , V_192 ) ,
V_277 ) ;
F_125 ( V_191 , F_219 ( V_251 ) ,
F_219 ( 0 ) ,
V_279 * sizeof( struct V_186 ) ) ;
F_39 ( V_191 , V_192 , F_219 ( 0 ) ,
F_219 ( V_274 - V_251 ) ,
V_251 * sizeof( struct V_186 ) ) ;
V_279 += V_251 ;
F_126 ( V_191 , V_279 ) ;
V_277 = F_155 ( V_19 ) ;
for ( V_6 = 0 ; V_6 < V_279 ; V_6 ++ ) {
V_278 = F_210 ( V_6 ) ;
V_277 -= F_212 ( V_191 , V_278 , & V_269 ) ;
F_220 ( V_191 , V_278 , V_277 , & V_269 ) ;
}
V_274 -= V_251 ;
F_126 ( V_192 , V_274 ) ;
if ( V_274 )
F_50 ( V_192 ) ;
else
F_110 ( V_33 , V_19 -> V_26 , V_192 ) ;
F_50 ( V_191 ) ;
F_34 ( V_191 , & V_41 , 0 ) ;
F_123 ( V_276 , & V_41 , V_80 + 1 ) ;
F_50 ( V_276 ) ;
if ( V_2 -> V_17 [ 0 ] >= V_274 ) {
V_2 -> V_17 [ 0 ] -= V_274 ;
if ( F_90 ( V_2 -> V_8 [ 0 ] ) == 0 )
F_110 ( V_33 , V_19 -> V_26 , V_2 -> V_8 [ 0 ] ) ;
F_20 ( V_2 -> V_8 [ 0 ] ) ;
F_11 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_191 ;
V_2 -> V_17 [ 1 ] += 1 ;
} else {
F_20 ( V_191 ) ;
F_11 ( V_191 ) ;
}
return 0 ;
V_283:
F_20 ( V_191 ) ;
F_11 ( V_191 ) ;
return 1 ;
}
static int F_221 ( struct V_32 * V_33 , struct V_18
* V_19 , struct V_1 * V_2 ,
int V_284 , int V_272 ,
int V_250 , T_4 V_275 )
{
struct V_14 * V_192 = V_2 -> V_8 [ 0 ] ;
struct V_14 * V_191 ;
struct V_14 * V_276 ;
int V_80 ;
int V_273 ;
T_4 V_274 ;
int V_38 ;
if ( ! V_2 -> V_8 [ 1 ] )
return 1 ;
V_80 = V_2 -> V_17 [ 1 ] ;
V_276 = V_2 -> V_8 [ 1 ] ;
if ( V_80 >= F_90 ( V_276 ) - 1 )
return 1 ;
F_112 ( V_2 -> V_8 [ 1 ] ) ;
V_191 = F_168 ( V_19 , V_276 , V_80 + 1 ) ;
if ( V_191 == NULL )
return 1 ;
F_19 ( V_191 ) ;
F_143 ( V_191 ) ;
V_273 = F_196 ( V_19 , V_191 ) ;
if ( V_273 < V_272 )
goto V_283;
V_38 = F_141 ( V_33 , V_19 , V_191 , V_276 ,
V_80 + 1 , & V_191 ) ;
if ( V_38 )
goto V_283;
V_273 = F_196 ( V_19 , V_191 ) ;
if ( V_273 < V_272 )
goto V_283;
V_274 = F_90 ( V_192 ) ;
if ( V_274 == 0 )
goto V_283;
if ( V_2 -> V_17 [ 0 ] == V_274 && ! V_250 ) {
F_20 ( V_192 ) ;
F_11 ( V_192 ) ;
V_2 -> V_8 [ 0 ] = V_191 ;
V_2 -> V_17 [ 0 ] = 0 ;
V_2 -> V_17 [ 1 ] ++ ;
return 0 ;
}
return F_214 ( V_33 , V_19 , V_2 , V_284 , V_250 ,
V_191 , V_273 , V_274 , V_275 ) ;
V_283:
F_20 ( V_191 ) ;
F_11 ( V_191 ) ;
return 1 ;
}
static T_1 int F_222 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_272 ,
int V_250 , struct V_14 * V_192 ,
int V_273 , T_4 V_279 ,
T_4 V_285 )
{
struct V_40 V_41 ;
struct V_14 * V_191 = V_2 -> V_8 [ 0 ] ;
int V_6 ;
int V_277 = 0 ;
int V_251 = 0 ;
struct V_186 * V_278 ;
T_4 V_286 ;
T_4 V_173 ;
int V_38 = 0 ;
T_4 V_281 ;
T_4 V_287 ;
struct V_268 V_269 ;
F_209 ( & V_269 ) ;
if ( V_250 )
V_173 = F_153 ( V_279 , V_285 ) ;
else
V_173 = F_153 ( V_279 - 1 , V_285 ) ;
for ( V_6 = 0 ; V_6 < V_173 ; V_6 ++ ) {
V_278 = F_210 ( V_6 ) ;
if ( ! V_250 && V_251 > 0 ) {
if ( V_2 -> V_17 [ 0 ] < V_6 )
break;
if ( V_2 -> V_17 [ 0 ] == V_6 ) {
int V_282 = F_196 ( V_19 , V_191 ) ;
if ( V_282 + V_277 * 2 > V_273 )
break;
}
}
if ( V_2 -> V_17 [ 0 ] == V_6 )
V_277 += V_272 ;
V_281 = F_216 ( V_191 , V_278 ) ;
if ( V_281 + sizeof( * V_278 ) + V_277 > V_273 )
break;
V_251 ++ ;
V_277 += V_281 + sizeof( * V_278 ) ;
}
if ( V_251 == 0 ) {
V_38 = 1 ;
goto V_288;
}
F_32 ( ! V_250 && V_251 == F_90 ( V_191 ) ) ;
F_39 ( V_192 , V_191 ,
F_219 ( F_90 ( V_192 ) ) ,
F_219 ( 0 ) ,
V_251 * sizeof( struct V_186 ) ) ;
V_277 = F_155 ( V_19 ) -
F_156 ( V_191 , V_251 - 1 ) ;
F_39 ( V_192 , V_191 , F_218 ( V_192 ) +
F_154 ( V_19 , V_192 ) - V_277 ,
F_218 ( V_191 ) +
F_156 ( V_191 , V_251 - 1 ) ,
V_277 ) ;
V_286 = F_90 ( V_192 ) ;
F_72 ( V_286 <= 0 ) ;
V_287 = F_156 ( V_192 , V_286 - 1 ) ;
for ( V_6 = V_286 ; V_6 < V_286 + V_251 ; V_6 ++ ) {
T_4 V_232 ;
V_278 = F_210 ( V_6 ) ;
V_232 = F_211 ( V_192 , V_278 , & V_269 ) ;
F_220 ( V_192 , V_278 ,
V_232 - ( F_155 ( V_19 ) - V_287 ) ,
& V_269 ) ;
}
F_126 ( V_192 , V_286 + V_251 ) ;
if ( V_251 > V_279 )
F_142 ( 1 , V_148 L_4 , V_251 ,
V_279 ) ;
if ( V_251 < V_279 ) {
V_277 = F_156 ( V_191 , V_251 - 1 ) -
F_154 ( V_19 , V_191 ) ;
F_125 ( V_191 , F_218 ( V_191 ) +
F_155 ( V_19 ) - V_277 ,
F_218 ( V_191 ) +
F_154 ( V_19 , V_191 ) , V_277 ) ;
F_125 ( V_191 , F_219 ( 0 ) ,
F_219 ( V_251 ) ,
( F_90 ( V_191 ) - V_251 ) *
sizeof( struct V_186 ) ) ;
}
V_279 -= V_251 ;
F_126 ( V_191 , V_279 ) ;
V_277 = F_155 ( V_19 ) ;
for ( V_6 = 0 ; V_6 < V_279 ; V_6 ++ ) {
V_278 = F_210 ( V_6 ) ;
V_277 = V_277 - F_212 ( V_191 ,
V_278 , & V_269 ) ;
F_220 ( V_191 , V_278 , V_277 , & V_269 ) ;
}
F_50 ( V_192 ) ;
if ( V_279 )
F_50 ( V_191 ) ;
else
F_110 ( V_33 , V_19 -> V_26 , V_191 ) ;
F_34 ( V_191 , & V_41 , 0 ) ;
F_201 ( V_19 -> V_26 , V_2 , & V_41 , 1 ) ;
if ( V_2 -> V_17 [ 0 ] < V_251 ) {
V_2 -> V_17 [ 0 ] += V_286 ;
F_20 ( V_2 -> V_8 [ 0 ] ) ;
F_11 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_192 ;
V_2 -> V_17 [ 1 ] -= 1 ;
} else {
F_20 ( V_192 ) ;
F_11 ( V_192 ) ;
V_2 -> V_17 [ 0 ] -= V_251 ;
}
F_72 ( V_2 -> V_17 [ 0 ] < 0 ) ;
return V_38 ;
V_288:
F_20 ( V_192 ) ;
F_11 ( V_192 ) ;
return V_38 ;
}
static int F_223 ( struct V_32 * V_33 , struct V_18
* V_19 , struct V_1 * V_2 , int V_284 ,
int V_272 , int V_250 , T_4 V_285 )
{
struct V_14 * V_191 = V_2 -> V_8 [ 0 ] ;
struct V_14 * V_192 ;
int V_80 ;
int V_273 ;
T_4 V_279 ;
int V_38 = 0 ;
V_80 = V_2 -> V_17 [ 1 ] ;
if ( V_80 == 0 )
return 1 ;
if ( ! V_2 -> V_8 [ 1 ] )
return 1 ;
V_279 = F_90 ( V_191 ) ;
if ( V_279 == 0 )
return 1 ;
F_112 ( V_2 -> V_8 [ 1 ] ) ;
V_192 = F_168 ( V_19 , V_2 -> V_8 [ 1 ] , V_80 - 1 ) ;
if ( V_192 == NULL )
return 1 ;
F_19 ( V_192 ) ;
F_143 ( V_192 ) ;
V_273 = F_196 ( V_19 , V_192 ) ;
if ( V_273 < V_272 ) {
V_38 = 1 ;
goto V_288;
}
V_38 = F_141 ( V_33 , V_19 , V_192 ,
V_2 -> V_8 [ 1 ] , V_80 - 1 , & V_192 ) ;
if ( V_38 ) {
if ( V_38 == - V_199 )
V_38 = 1 ;
goto V_288;
}
V_273 = F_196 ( V_19 , V_192 ) ;
if ( V_273 < V_272 ) {
V_38 = 1 ;
goto V_288;
}
return F_222 ( V_33 , V_19 , V_2 , V_284 ,
V_250 , V_192 , V_273 , V_279 ,
V_285 ) ;
V_288:
F_20 ( V_192 ) ;
F_11 ( V_192 ) ;
return V_38 ;
}
static T_1 void F_224 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_14 * V_265 ,
struct V_14 * V_191 ,
int V_80 , int V_178 , int V_98 )
{
int V_289 ;
int V_290 ;
int V_6 ;
struct V_40 V_41 ;
struct V_268 V_269 ;
F_209 ( & V_269 ) ;
V_98 = V_98 - V_178 ;
F_126 ( V_191 , V_98 ) ;
V_289 = F_217 ( V_265 , V_178 ) - F_154 ( V_19 , V_265 ) ;
F_39 ( V_191 , V_265 , F_219 ( 0 ) ,
F_219 ( V_178 ) ,
V_98 * sizeof( struct V_186 ) ) ;
F_39 ( V_191 , V_265 ,
F_218 ( V_191 ) + F_155 ( V_19 ) -
V_289 , F_218 ( V_265 ) +
F_154 ( V_19 , V_265 ) , V_289 ) ;
V_290 = F_155 ( V_19 ) -
F_217 ( V_265 , V_178 ) ;
for ( V_6 = 0 ; V_6 < V_98 ; V_6 ++ ) {
struct V_186 * V_278 = F_210 ( V_6 ) ;
T_4 V_232 ;
V_232 = F_211 ( V_191 , V_278 , & V_269 ) ;
F_220 ( V_191 , V_278 ,
V_232 + V_290 , & V_269 ) ;
}
F_126 ( V_265 , V_178 ) ;
F_34 ( V_191 , & V_41 , 0 ) ;
F_207 ( V_33 , V_19 , V_2 , & V_41 , V_191 -> V_46 ,
V_2 -> V_17 [ 1 ] + 1 , 1 ) ;
F_50 ( V_191 ) ;
F_50 ( V_265 ) ;
F_72 ( V_2 -> V_17 [ 0 ] != V_80 ) ;
if ( V_178 <= V_80 ) {
F_20 ( V_2 -> V_8 [ 0 ] ) ;
F_11 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_191 ;
V_2 -> V_17 [ 0 ] -= V_178 ;
V_2 -> V_17 [ 1 ] += 1 ;
} else {
F_20 ( V_191 ) ;
F_11 ( V_191 ) ;
}
F_72 ( V_2 -> V_17 [ 0 ] < 0 ) ;
}
static T_1 int F_225 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
int V_272 )
{
int V_38 ;
int V_160 = 0 ;
int V_80 ;
T_4 V_98 ;
int V_291 = V_272 ;
V_80 = V_2 -> V_17 [ 0 ] ;
if ( V_80 < F_90 ( V_2 -> V_8 [ 0 ] ) )
V_291 -= F_196 ( V_19 , V_2 -> V_8 [ 0 ] ) ;
V_38 = F_221 ( V_33 , V_19 , V_2 , 1 , V_291 , 0 , V_80 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_38 == 0 )
V_160 ++ ;
V_98 = F_90 ( V_2 -> V_8 [ 0 ] ) ;
if ( V_2 -> V_17 [ 0 ] == 0 || V_2 -> V_17 [ 0 ] == V_98 )
return 0 ;
if ( F_196 ( V_19 , V_2 -> V_8 [ 0 ] ) >= V_272 )
return 0 ;
V_80 = V_2 -> V_17 [ 0 ] ;
V_38 = F_223 ( V_33 , V_19 , V_2 , 1 , V_291 , 0 , V_80 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_38 == 0 )
V_160 ++ ;
if ( V_160 )
return 0 ;
return 1 ;
}
static T_1 int F_197 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_154 * V_292 ,
struct V_1 * V_2 , int V_272 ,
int V_293 )
{
struct V_40 V_41 ;
struct V_14 * V_265 ;
T_4 V_98 ;
int V_178 ;
int V_80 ;
struct V_14 * V_191 ;
struct V_54 * V_26 = V_19 -> V_26 ;
int V_38 = 0 ;
int V_193 ;
int V_263 ;
int V_294 = 0 ;
int V_295 = 0 ;
V_265 = V_2 -> V_8 [ 0 ] ;
V_80 = V_2 -> V_17 [ 0 ] ;
if ( V_293 && V_272 + F_226 ( V_265 , V_80 ) +
sizeof( struct V_186 ) > F_155 ( V_19 ) )
return - V_296 ;
if ( V_272 && V_2 -> V_8 [ 1 ] ) {
int V_291 = V_272 ;
if ( V_80 < F_90 ( V_265 ) )
V_291 -= F_196 ( V_19 , V_265 ) ;
V_193 = F_221 ( V_33 , V_19 , V_2 , V_291 ,
V_291 , 0 , 0 ) ;
if ( V_193 < 0 )
return V_193 ;
if ( V_193 ) {
V_193 = F_223 ( V_33 , V_19 , V_2 , V_291 ,
V_291 , 0 , ( T_4 ) - 1 ) ;
if ( V_193 < 0 )
return V_193 ;
}
V_265 = V_2 -> V_8 [ 0 ] ;
if ( F_196 ( V_19 , V_265 ) >= V_272 )
return 0 ;
}
if ( ! V_2 -> V_8 [ 1 ] ) {
V_38 = F_204 ( V_33 , V_19 , V_2 , 1 ) ;
if ( V_38 )
return V_38 ;
}
V_227:
V_263 = 1 ;
V_265 = V_2 -> V_8 [ 0 ] ;
V_80 = V_2 -> V_17 [ 0 ] ;
V_98 = F_90 ( V_265 ) ;
V_178 = ( V_98 + 1 ) / 2 ;
if ( V_178 <= V_80 ) {
if ( V_98 == 1 ||
F_208 ( V_265 , V_178 , V_98 - V_178 ) + V_272 >
F_155 ( V_19 ) ) {
if ( V_80 >= V_98 ) {
V_263 = 0 ;
} else {
V_178 = V_80 ;
if ( V_178 != V_98 &&
F_208 ( V_265 , V_178 , V_98 - V_178 ) +
V_272 > F_155 ( V_19 ) ) {
if ( V_272 && ! V_295 )
goto V_297;
V_263 = 2 ;
}
}
}
} else {
if ( F_208 ( V_265 , 0 , V_178 ) + V_272 >
F_155 ( V_19 ) ) {
if ( ! V_293 && V_272 && V_80 == 0 ) {
V_263 = 0 ;
} else if ( ( V_293 || ! V_272 ) && V_80 == 0 ) {
V_178 = 1 ;
} else {
V_178 = V_80 ;
if ( V_178 != V_98 &&
F_208 ( V_265 , V_178 , V_98 - V_178 ) +
V_272 > F_155 ( V_19 ) ) {
if ( V_272 && ! V_295 )
goto V_297;
V_263 = 2 ;
}
}
}
}
if ( V_263 == 0 )
F_185 ( & V_41 , V_292 ) ;
else
F_34 ( V_265 , & V_41 , V_178 ) ;
V_191 = F_36 ( V_33 , V_19 , 0 , V_19 -> V_124 . V_28 ,
& V_41 , 0 , V_265 -> V_46 , 0 ) ;
if ( F_37 ( V_191 ) )
return F_38 ( V_191 ) ;
F_163 ( V_19 , V_19 -> V_169 ) ;
F_205 ( V_191 , 0 , 0 , sizeof( struct V_259 ) ) ;
F_40 ( V_191 , V_191 -> V_46 ) ;
F_41 ( V_191 , V_33 -> V_43 ) ;
F_42 ( V_191 , V_48 ) ;
F_45 ( V_191 , V_19 -> V_124 . V_28 ) ;
F_130 ( V_191 , 0 ) ;
F_46 ( V_191 , V_26 -> V_52 ,
F_47 () , V_53 ) ;
F_46 ( V_191 , V_26 -> V_260 ,
F_206 ( V_191 ) ,
V_261 ) ;
if ( V_263 == 0 ) {
if ( V_178 <= V_80 ) {
F_126 ( V_191 , 0 ) ;
F_207 ( V_33 , V_19 , V_2 , & V_41 , V_191 -> V_46 ,
V_2 -> V_17 [ 1 ] + 1 , 1 ) ;
F_20 ( V_2 -> V_8 [ 0 ] ) ;
F_11 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_191 ;
V_2 -> V_17 [ 0 ] = 0 ;
V_2 -> V_17 [ 1 ] += 1 ;
} else {
F_126 ( V_191 , 0 ) ;
F_207 ( V_33 , V_19 , V_2 , & V_41 , V_191 -> V_46 ,
V_2 -> V_17 [ 1 ] , 1 ) ;
F_20 ( V_2 -> V_8 [ 0 ] ) ;
F_11 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_191 ;
V_2 -> V_17 [ 0 ] = 0 ;
if ( V_2 -> V_17 [ 1 ] == 0 )
F_201 ( V_26 , V_2 , & V_41 , 1 ) ;
}
F_50 ( V_191 ) ;
return V_38 ;
}
F_224 ( V_33 , V_19 , V_2 , V_265 , V_191 , V_80 , V_178 , V_98 ) ;
if ( V_263 == 2 ) {
F_72 ( V_294 != 0 ) ;
V_294 ++ ;
goto V_227;
}
return 0 ;
V_297:
F_225 ( V_33 , V_19 , V_2 , V_272 ) ;
V_295 = 1 ;
if ( F_196 ( V_19 , V_2 -> V_8 [ 0 ] ) >= V_272 )
return 0 ;
goto V_227;
}
static T_1 int F_227 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_224 )
{
struct V_154 V_85 ;
struct V_14 * V_172 ;
struct V_298 * V_299 ;
T_2 V_300 = 0 ;
T_4 V_174 ;
int V_38 ;
V_172 = V_2 -> V_8 [ 0 ] ;
F_191 ( V_172 , & V_85 , V_2 -> V_17 [ 0 ] ) ;
F_72 ( V_85 . type != V_301 &&
V_85 . type != V_302 ) ;
if ( F_196 ( V_19 , V_172 ) >= V_224 )
return 0 ;
V_174 = F_226 ( V_172 , V_2 -> V_17 [ 0 ] ) ;
if ( V_85 . type == V_301 ) {
V_299 = F_228 ( V_172 , V_2 -> V_17 [ 0 ] ,
struct V_298 ) ;
V_300 = F_229 ( V_172 , V_299 ) ;
}
F_8 ( V_2 ) ;
V_2 -> V_219 = 1 ;
V_2 -> V_225 = 1 ;
V_38 = F_189 ( V_33 , V_19 , & V_85 , V_2 , 0 , 1 ) ;
V_2 -> V_225 = 0 ;
if ( V_38 > 0 )
V_38 = - V_223 ;
if ( V_38 < 0 )
goto V_165;
V_38 = - V_223 ;
V_172 = V_2 -> V_8 [ 0 ] ;
if ( V_174 != F_226 ( V_172 , V_2 -> V_17 [ 0 ] ) )
goto V_165;
if ( F_196 ( V_19 , V_2 -> V_8 [ 0 ] ) >= V_224 )
goto V_165;
if ( V_85 . type == V_301 ) {
V_299 = F_228 ( V_172 , V_2 -> V_17 [ 0 ] ,
struct V_298 ) ;
if ( V_300 != F_229 ( V_172 , V_299 ) )
goto V_165;
}
F_3 ( V_2 ) ;
V_38 = F_197 ( V_33 , V_19 , & V_85 , V_2 , V_224 , 1 ) ;
if ( V_38 )
goto V_165;
V_2 -> V_219 = 0 ;
F_179 ( V_2 , 1 ) ;
return 0 ;
V_165:
V_2 -> V_219 = 0 ;
return V_38 ;
}
static T_1 int F_230 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_154 * V_249 ,
unsigned long V_303 )
{
struct V_14 * V_172 ;
struct V_186 * V_278 ;
struct V_186 * V_304 ;
int V_80 ;
char * V_34 ;
T_4 V_98 ;
T_4 V_174 ;
T_4 V_305 ;
struct V_40 V_41 ;
V_172 = V_2 -> V_8 [ 0 ] ;
F_72 ( F_196 ( V_19 , V_172 ) < sizeof( struct V_186 ) ) ;
F_3 ( V_2 ) ;
V_278 = F_210 ( V_2 -> V_17 [ 0 ] ) ;
V_305 = F_231 ( V_172 , V_278 ) ;
V_174 = F_216 ( V_172 , V_278 ) ;
V_34 = F_232 ( V_174 , V_4 ) ;
if ( ! V_34 )
return - V_88 ;
F_159 ( V_172 , V_34 , F_233 ( V_172 ,
V_2 -> V_17 [ 0 ] ) , V_174 ) ;
V_80 = V_2 -> V_17 [ 0 ] + 1 ;
V_98 = F_90 ( V_172 ) ;
if ( V_80 != V_98 ) {
F_125 ( V_172 , F_219 ( V_80 + 1 ) ,
F_219 ( V_80 ) ,
( V_98 - V_80 ) * sizeof( struct V_186 ) ) ;
}
F_185 ( & V_41 , V_249 ) ;
F_203 ( V_172 , & V_41 , V_80 ) ;
V_304 = F_210 ( V_80 ) ;
F_234 ( V_172 , V_304 , V_305 ) ;
F_235 ( V_172 , V_304 , V_174 - V_303 ) ;
F_234 ( V_172 , V_278 ,
V_305 + V_174 - V_303 ) ;
F_235 ( V_172 , V_278 , V_303 ) ;
F_126 ( V_172 , V_98 + 1 ) ;
F_46 ( V_172 , V_34 ,
F_233 ( V_172 , V_2 -> V_17 [ 0 ] ) ,
V_303 ) ;
F_46 ( V_172 , V_34 + V_303 ,
F_233 ( V_172 , V_80 ) ,
V_174 - V_303 ) ;
F_50 ( V_172 ) ;
F_72 ( F_196 ( V_19 , V_172 ) < 0 ) ;
F_70 ( V_34 ) ;
return 0 ;
}
int F_236 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_154 * V_249 ,
unsigned long V_303 )
{
int V_38 ;
V_38 = F_227 ( V_33 , V_19 , V_2 ,
sizeof( struct V_186 ) ) ;
if ( V_38 )
return V_38 ;
V_38 = F_230 ( V_33 , V_19 , V_2 , V_249 , V_303 ) ;
return V_38 ;
}
int F_237 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_154 * V_249 )
{
struct V_14 * V_172 ;
int V_38 ;
T_4 V_174 ;
V_172 = V_2 -> V_8 [ 0 ] ;
V_174 = F_226 ( V_172 , V_2 -> V_17 [ 0 ] ) ;
V_38 = F_227 ( V_33 , V_19 , V_2 ,
V_174 + sizeof( struct V_186 ) ) ;
if ( V_38 )
return V_38 ;
V_2 -> V_17 [ 0 ] ++ ;
F_238 ( V_19 , V_2 , V_249 , & V_174 ,
V_174 , V_174 +
sizeof( struct V_186 ) , 1 ) ;
V_172 = V_2 -> V_8 [ 0 ] ;
F_239 ( V_172 ,
F_233 ( V_172 , V_2 -> V_17 [ 0 ] ) ,
F_233 ( V_172 , V_2 -> V_17 [ 0 ] - 1 ) ,
V_174 ) ;
return 0 ;
}
void F_240 ( struct V_18 * V_19 , struct V_1 * V_2 ,
T_4 V_306 , int V_307 )
{
int V_80 ;
struct V_14 * V_172 ;
struct V_186 * V_278 ;
T_4 V_98 ;
unsigned int V_280 ;
unsigned int V_308 ;
unsigned int V_309 ;
unsigned int V_310 ;
int V_6 ;
struct V_268 V_269 ;
F_209 ( & V_269 ) ;
V_172 = V_2 -> V_8 [ 0 ] ;
V_80 = V_2 -> V_17 [ 0 ] ;
V_309 = F_226 ( V_172 , V_80 ) ;
if ( V_309 == V_306 )
return;
V_98 = F_90 ( V_172 ) ;
V_280 = F_154 ( V_19 , V_172 ) ;
V_308 = F_156 ( V_172 , V_80 ) ;
V_310 = V_309 - V_306 ;
F_72 ( V_80 < 0 ) ;
F_72 ( V_80 >= V_98 ) ;
for ( V_6 = V_80 ; V_6 < V_98 ; V_6 ++ ) {
T_4 V_232 ;
V_278 = F_210 ( V_6 ) ;
V_232 = F_211 ( V_172 , V_278 , & V_269 ) ;
F_220 ( V_172 , V_278 ,
V_232 + V_310 , & V_269 ) ;
}
if ( V_307 ) {
F_125 ( V_172 , F_218 ( V_172 ) +
V_280 + V_310 , F_218 ( V_172 ) +
V_280 , V_308 + V_306 - V_280 ) ;
} else {
struct V_40 V_41 ;
T_2 V_157 ;
F_34 ( V_172 , & V_41 , V_80 ) ;
if ( F_241 ( & V_41 ) == V_301 ) {
unsigned long V_311 ;
struct V_298 * V_299 ;
V_299 = F_228 ( V_172 , V_80 ,
struct V_298 ) ;
V_299 = (struct V_298 * ) (
( unsigned long ) V_299 - V_310 ) ;
if ( F_242 ( V_172 , V_299 ) ==
V_312 ) {
V_311 = F_233 ( V_172 , V_80 ) ;
F_125 ( V_172 , V_311 ,
( unsigned long ) V_299 ,
V_313 ) ;
}
}
F_125 ( V_172 , F_218 ( V_172 ) +
V_280 + V_310 , F_218 ( V_172 ) +
V_280 , V_308 - V_280 ) ;
V_157 = F_243 ( & V_41 ) ;
F_244 ( & V_41 , V_157 + V_310 ) ;
F_203 ( V_172 , & V_41 , V_80 ) ;
if ( V_80 == 0 )
F_201 ( V_19 -> V_26 , V_2 , & V_41 , 1 ) ;
}
V_278 = F_210 ( V_80 ) ;
F_235 ( V_172 , V_278 , V_306 ) ;
F_50 ( V_172 ) ;
if ( F_196 ( V_19 , V_172 ) < 0 ) {
F_245 ( V_19 , V_172 ) ;
F_172 () ;
}
}
void F_246 ( struct V_18 * V_19 , struct V_1 * V_2 ,
T_4 V_272 )
{
int V_80 ;
struct V_14 * V_172 ;
struct V_186 * V_278 ;
T_4 V_98 ;
unsigned int V_280 ;
unsigned int V_314 ;
unsigned int V_309 ;
int V_6 ;
struct V_268 V_269 ;
F_209 ( & V_269 ) ;
V_172 = V_2 -> V_8 [ 0 ] ;
V_98 = F_90 ( V_172 ) ;
V_280 = F_154 ( V_19 , V_172 ) ;
if ( F_196 ( V_19 , V_172 ) < V_272 ) {
F_245 ( V_19 , V_172 ) ;
F_172 () ;
}
V_80 = V_2 -> V_17 [ 0 ] ;
V_314 = F_217 ( V_172 , V_80 ) ;
F_72 ( V_80 < 0 ) ;
if ( V_80 >= V_98 ) {
F_245 ( V_19 , V_172 ) ;
F_213 ( V_19 -> V_26 , L_5 ,
V_80 , V_98 ) ;
F_72 ( 1 ) ;
}
for ( V_6 = V_80 ; V_6 < V_98 ; V_6 ++ ) {
T_4 V_232 ;
V_278 = F_210 ( V_6 ) ;
V_232 = F_211 ( V_172 , V_278 , & V_269 ) ;
F_220 ( V_172 , V_278 ,
V_232 - V_272 , & V_269 ) ;
}
F_125 ( V_172 , F_218 ( V_172 ) +
V_280 - V_272 , F_218 ( V_172 ) +
V_280 , V_314 - V_280 ) ;
V_280 = V_314 ;
V_309 = F_226 ( V_172 , V_80 ) ;
V_278 = F_210 ( V_80 ) ;
F_235 ( V_172 , V_278 , V_309 + V_272 ) ;
F_50 ( V_172 ) ;
if ( F_196 ( V_19 , V_172 ) < 0 ) {
F_245 ( V_19 , V_172 ) ;
F_172 () ;
}
}
void F_238 ( struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_154 * V_315 , T_4 * V_272 ,
T_4 V_316 , T_4 V_317 , int V_173 )
{
struct V_186 * V_278 ;
int V_6 ;
T_4 V_98 ;
unsigned int V_280 ;
struct V_40 V_41 ;
struct V_14 * V_172 ;
int V_80 ;
struct V_268 V_269 ;
if ( V_2 -> V_17 [ 0 ] == 0 ) {
F_185 ( & V_41 , V_315 ) ;
F_201 ( V_19 -> V_26 , V_2 , & V_41 , 1 ) ;
}
F_179 ( V_2 , 1 ) ;
F_209 ( & V_269 ) ;
V_172 = V_2 -> V_8 [ 0 ] ;
V_80 = V_2 -> V_17 [ 0 ] ;
V_98 = F_90 ( V_172 ) ;
V_280 = F_154 ( V_19 , V_172 ) ;
if ( F_196 ( V_19 , V_172 ) < V_317 ) {
F_245 ( V_19 , V_172 ) ;
F_213 ( V_19 -> V_26 , L_6 ,
V_317 , F_196 ( V_19 , V_172 ) ) ;
F_172 () ;
}
if ( V_80 != V_98 ) {
unsigned int V_314 = F_217 ( V_172 , V_80 ) ;
if ( V_314 < V_280 ) {
F_245 ( V_19 , V_172 ) ;
F_213 ( V_19 -> V_26 , L_7 ,
V_80 , V_314 , V_280 ) ;
F_72 ( 1 ) ;
}
for ( V_6 = V_80 ; V_6 < V_98 ; V_6 ++ ) {
T_4 V_232 ;
V_278 = F_210 ( V_6 ) ;
V_232 = F_211 ( V_172 , V_278 , & V_269 ) ;
F_220 ( V_172 , V_278 ,
V_232 - V_316 , & V_269 ) ;
}
F_125 ( V_172 , F_219 ( V_80 + V_173 ) ,
F_219 ( V_80 ) ,
( V_98 - V_80 ) * sizeof( struct V_186 ) ) ;
F_125 ( V_172 , F_218 ( V_172 ) +
V_280 - V_316 , F_218 ( V_172 ) +
V_280 , V_314 - V_280 ) ;
V_280 = V_314 ;
}
for ( V_6 = 0 ; V_6 < V_173 ; V_6 ++ ) {
F_185 ( & V_41 , V_315 + V_6 ) ;
F_203 ( V_172 , & V_41 , V_80 + V_6 ) ;
V_278 = F_210 ( V_80 + V_6 ) ;
F_220 ( V_172 , V_278 ,
V_280 - V_272 [ V_6 ] , & V_269 ) ;
V_280 -= V_272 [ V_6 ] ;
F_247 ( V_172 , V_278 , V_272 [ V_6 ] , & V_269 ) ;
}
F_126 ( V_172 , V_98 + V_173 ) ;
F_50 ( V_172 ) ;
if ( F_196 ( V_19 , V_172 ) < 0 ) {
F_245 ( V_19 , V_172 ) ;
F_172 () ;
}
}
int F_248 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_154 * V_315 , T_4 * V_272 ,
int V_173 )
{
int V_38 = 0 ;
int V_80 ;
int V_6 ;
T_4 V_317 = 0 ;
T_4 V_316 = 0 ;
for ( V_6 = 0 ; V_6 < V_173 ; V_6 ++ )
V_316 += V_272 [ V_6 ] ;
V_317 = V_316 + ( V_173 * sizeof( struct V_186 ) ) ;
V_38 = F_189 ( V_33 , V_19 , V_315 , V_2 , V_317 , 1 ) ;
if ( V_38 == 0 )
return - V_79 ;
if ( V_38 < 0 )
return V_38 ;
V_80 = V_2 -> V_17 [ 0 ] ;
F_72 ( V_80 < 0 ) ;
F_238 ( V_19 , V_2 , V_315 , V_272 ,
V_316 , V_317 , V_173 ) ;
return 0 ;
}
int F_249 ( struct V_32 * V_33 , struct V_18
* V_19 , struct V_154 * V_315 , void * V_318 , T_4
V_272 )
{
int V_38 = 0 ;
struct V_1 * V_2 ;
struct V_14 * V_172 ;
unsigned long V_311 ;
V_2 = F_1 () ;
if ( ! V_2 )
return - V_88 ;
V_38 = F_250 ( V_33 , V_19 , V_2 , V_315 , V_272 ) ;
if ( ! V_38 ) {
V_172 = V_2 -> V_8 [ 0 ] ;
V_311 = F_233 ( V_172 , V_2 -> V_17 [ 0 ] ) ;
F_46 ( V_172 , V_318 , V_311 , V_272 ) ;
F_50 ( V_172 ) ;
}
F_7 ( V_2 ) ;
return V_38 ;
}
static void F_170 ( struct V_18 * V_19 , struct V_1 * V_2 ,
int V_39 , int V_80 )
{
struct V_14 * V_74 = V_2 -> V_8 [ V_39 ] ;
T_4 V_98 ;
int V_38 ;
V_98 = F_90 ( V_74 ) ;
if ( V_80 != V_98 - 1 ) {
if ( V_39 )
F_95 ( V_19 -> V_26 , V_74 , V_80 ,
V_80 + 1 , V_98 - V_80 - 1 ) ;
F_125 ( V_74 ,
F_124 ( V_80 ) ,
F_124 ( V_80 + 1 ) ,
sizeof( struct V_140 ) *
( V_98 - V_80 - 1 ) ) ;
} else if ( V_39 ) {
V_38 = F_84 ( V_19 -> V_26 , V_74 , V_80 ,
V_113 , V_4 ) ;
F_72 ( V_38 < 0 ) ;
}
V_98 -- ;
F_126 ( V_74 , V_98 ) ;
if ( V_98 == 0 && V_74 == V_19 -> V_21 ) {
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
struct V_14 * V_172 )
{
F_32 ( F_48 ( V_172 ) != V_33 -> V_43 ) ;
F_170 ( V_19 , V_2 , 1 , V_2 -> V_17 [ 1 ] ) ;
F_179 ( V_2 , 0 ) ;
F_166 ( V_19 , V_172 -> V_47 ) ;
F_115 ( V_172 ) ;
F_117 ( V_33 , V_19 , V_172 , 0 , 1 ) ;
F_120 ( V_172 ) ;
}
int F_252 ( struct V_32 * V_33 , struct V_18 * V_19 ,
struct V_1 * V_2 , int V_80 , int V_173 )
{
struct V_14 * V_172 ;
struct V_186 * V_278 ;
T_4 V_319 ;
T_4 V_320 = 0 ;
int V_38 = 0 ;
int V_193 ;
int V_6 ;
T_4 V_98 ;
struct V_268 V_269 ;
F_209 ( & V_269 ) ;
V_172 = V_2 -> V_8 [ 0 ] ;
V_319 = F_156 ( V_172 , V_80 + V_173 - 1 ) ;
for ( V_6 = 0 ; V_6 < V_173 ; V_6 ++ )
V_320 += F_226 ( V_172 , V_80 + V_6 ) ;
V_98 = F_90 ( V_172 ) ;
if ( V_80 + V_173 != V_98 ) {
int V_280 = F_154 ( V_19 , V_172 ) ;
F_125 ( V_172 , F_218 ( V_172 ) +
V_280 + V_320 ,
F_218 ( V_172 ) + V_280 ,
V_319 - V_280 ) ;
for ( V_6 = V_80 + V_173 ; V_6 < V_98 ; V_6 ++ ) {
T_4 V_232 ;
V_278 = F_210 ( V_6 ) ;
V_232 = F_211 ( V_172 , V_278 , & V_269 ) ;
F_220 ( V_172 , V_278 ,
V_232 + V_320 , & V_269 ) ;
}
F_125 ( V_172 , F_219 ( V_80 ) ,
F_219 ( V_80 + V_173 ) ,
sizeof( struct V_186 ) *
( V_98 - V_80 - V_173 ) ) ;
}
F_126 ( V_172 , V_98 - V_173 ) ;
V_98 -= V_173 ;
if ( V_98 == 0 ) {
if ( V_172 == V_19 -> V_21 ) {
F_130 ( V_172 , 0 ) ;
} else {
F_3 ( V_2 ) ;
F_110 ( V_33 , V_19 -> V_26 , V_172 ) ;
F_251 ( V_33 , V_19 , V_2 , V_172 ) ;
}
} else {
int V_321 = F_208 ( V_172 , 0 , V_98 ) ;
if ( V_80 == 0 ) {
struct V_40 V_41 ;
F_34 ( V_172 , & V_41 , 0 ) ;
F_201 ( V_19 -> V_26 , V_2 , & V_41 , 1 ) ;
}
if ( V_321 < F_155 ( V_19 ) / 3 ) {
V_80 = V_2 -> V_17 [ 1 ] ;
F_115 ( V_172 ) ;
F_3 ( V_2 ) ;
V_193 = F_223 ( V_33 , V_19 , V_2 , 1 , 1 ,
1 , ( T_4 ) - 1 ) ;
if ( V_193 < 0 && V_193 != - V_199 )
V_38 = V_193 ;
if ( V_2 -> V_8 [ 0 ] == V_172 &&
F_90 ( V_172 ) ) {
V_193 = F_221 ( V_33 , V_19 , V_2 , 1 ,
1 , 1 , 0 ) ;
if ( V_193 < 0 && V_193 != - V_199 )
V_38 = V_193 ;
}
if ( F_90 ( V_172 ) == 0 ) {
V_2 -> V_17 [ 1 ] = V_80 ;
F_251 ( V_33 , V_19 , V_2 , V_172 ) ;
F_11 ( V_172 ) ;
V_38 = 0 ;
} else {
if ( V_2 -> V_8 [ 0 ] == V_172 )
F_50 ( V_172 ) ;
F_11 ( V_172 ) ;
}
} else {
F_50 ( V_172 ) ;
}
}
return V_38 ;
}
int F_200 ( struct V_18 * V_19 , struct V_1 * V_2 )
{
struct V_154 V_85 ;
struct V_40 V_234 ;
int V_38 ;
F_191 ( V_2 -> V_8 [ 0 ] , & V_85 , 0 ) ;
if ( V_85 . V_157 > 0 ) {
V_85 . V_157 -- ;
} else if ( V_85 . type > 0 ) {
V_85 . type -- ;
V_85 . V_157 = ( T_2 ) - 1 ;
} else if ( V_85 . V_28 > 0 ) {
V_85 . V_28 -- ;
V_85 . type = ( T_5 ) - 1 ;
V_85 . V_157 = ( T_2 ) - 1 ;
} else {
return 1 ;
}
F_8 ( V_2 ) ;
V_38 = F_189 ( NULL , V_19 , & V_85 , V_2 , 0 , 0 ) ;
if ( V_38 < 0 )
return V_38 ;
F_34 ( V_2 -> V_8 [ 0 ] , & V_234 , 0 ) ;
V_38 = F_146 ( & V_234 , & V_85 ) ;
if ( V_38 <= 0 )
return 0 ;
return 1 ;
}
int F_253 ( struct V_18 * V_19 , struct V_154 * V_322 ,
struct V_1 * V_2 ,
T_2 V_323 )
{
struct V_14 * V_75 ;
struct V_154 V_234 ;
int V_80 ;
int V_226 ;
T_4 V_98 ;
int V_39 ;
int V_38 = 1 ;
int V_219 = V_2 -> V_219 ;
V_2 -> V_219 = 1 ;
V_227:
V_75 = F_21 ( V_19 ) ;
V_39 = F_33 ( V_75 ) ;
F_32 ( V_2 -> V_8 [ V_39 ] ) ;
V_2 -> V_8 [ V_39 ] = V_75 ;
V_2 -> V_9 [ V_39 ] = V_10 ;
if ( F_48 ( V_75 ) < V_323 ) {
V_38 = 1 ;
goto V_288;
}
while ( 1 ) {
V_98 = F_90 ( V_75 ) ;
V_39 = F_33 ( V_75 ) ;
V_226 = F_160 ( V_75 , V_322 , V_39 , & V_80 ) ;
if ( V_39 == V_2 -> V_236 ) {
if ( V_80 >= V_98 )
goto V_324;
V_38 = 0 ;
V_2 -> V_17 [ V_39 ] = V_80 ;
F_191 ( V_75 , & V_234 , V_80 ) ;
goto V_288;
}
if ( V_226 && V_80 > 0 )
V_80 -- ;
while ( V_80 < V_98 ) {
T_2 V_161 ;
V_161 = F_82 ( V_75 , V_80 ) ;
if ( V_161 < V_323 ) {
V_80 ++ ;
continue;
}
break;
}
V_324:
if ( V_80 >= V_98 ) {
V_2 -> V_17 [ V_39 ] = V_80 ;
F_3 ( V_2 ) ;
V_226 = F_254 ( V_19 , V_2 , V_322 , V_39 ,
V_323 ) ;
if ( V_226 == 0 ) {
F_8 ( V_2 ) ;
goto V_227;
} else {
goto V_288;
}
}
F_255 ( V_75 , & V_234 , V_80 ) ;
V_2 -> V_17 [ V_39 ] = V_80 ;
if ( V_39 == V_2 -> V_236 ) {
V_38 = 0 ;
goto V_288;
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
V_288:
V_2 -> V_219 = V_219 ;
if ( V_38 == 0 ) {
F_179 ( V_2 , V_2 -> V_236 + 1 ) ;
F_3 ( V_2 ) ;
memcpy ( V_322 , & V_234 , sizeof( V_234 ) ) ;
}
return V_38 ;
}
static void F_256 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int * V_39 , int V_325 )
{
F_72 ( * V_39 == 0 ) ;
V_2 -> V_8 [ * V_39 - 1 ] = F_168 ( V_19 , V_2 -> V_8 [ * V_39 ] ,
V_2 -> V_17 [ * V_39 ] ) ;
V_2 -> V_17 [ * V_39 - 1 ] = 0 ;
( * V_39 ) -- ;
}
static int F_257 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int * V_39 , int V_325 )
{
int V_38 = 0 ;
int V_98 ;
V_98 = F_90 ( V_2 -> V_8 [ * V_39 ] ) ;
V_2 -> V_17 [ * V_39 ] ++ ;
while ( V_2 -> V_17 [ * V_39 ] >= V_98 ) {
if ( * V_39 == V_325 )
return - 1 ;
V_2 -> V_17 [ * V_39 ] = 0 ;
F_11 ( V_2 -> V_8 [ * V_39 ] ) ;
V_2 -> V_8 [ * V_39 ] = NULL ;
( * V_39 ) ++ ;
V_2 -> V_17 [ * V_39 ] ++ ;
V_98 = F_90 ( V_2 -> V_8 [ * V_39 ] ) ;
V_38 = 1 ;
}
return V_38 ;
}
static int F_258 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int * V_39 , int V_325 ,
int V_326 ,
struct V_154 * V_85 )
{
int V_38 ;
if ( * V_39 == 0 || ! V_326 ) {
V_38 = F_257 ( V_19 , V_2 , V_39 , V_325 ) ;
} else {
F_256 ( V_19 , V_2 , V_39 , V_325 ) ;
V_38 = 0 ;
}
if ( V_38 >= 0 ) {
if ( * V_39 == 0 )
F_191 ( V_2 -> V_8 [ * V_39 ] , V_85 ,
V_2 -> V_17 [ * V_39 ] ) ;
else
F_255 ( V_2 -> V_8 [ * V_39 ] , V_85 ,
V_2 -> V_17 [ * V_39 ] ) ;
}
return V_38 ;
}
static int F_259 ( struct V_18 * V_327 ,
struct V_1 * V_328 ,
struct V_1 * V_329 ,
char * V_330 )
{
int V_331 ;
int V_332 , V_333 ;
unsigned long V_334 , V_335 ;
V_332 = F_226 ( V_328 -> V_8 [ 0 ] , V_328 -> V_17 [ 0 ] ) ;
V_333 = F_226 ( V_329 -> V_8 [ 0 ] , V_329 -> V_17 [ 0 ] ) ;
if ( V_332 != V_333 )
return 1 ;
V_334 = F_233 ( V_328 -> V_8 [ 0 ] , V_328 -> V_17 [ 0 ] ) ;
V_335 = F_233 ( V_329 -> V_8 [ 0 ] ,
V_329 -> V_17 [ 0 ] ) ;
F_159 ( V_328 -> V_8 [ 0 ] , V_330 , V_334 , V_332 ) ;
V_331 = F_186 ( V_329 -> V_8 [ 0 ] , V_330 , V_335 , V_332 ) ;
if ( V_331 )
return 1 ;
return 0 ;
}
int F_260 ( struct V_18 * V_327 ,
struct V_18 * V_336 ,
T_6 V_337 , void * V_338 )
{
int V_38 ;
int V_331 ;
struct V_1 * V_328 = NULL ;
struct V_1 * V_329 = NULL ;
struct V_154 V_339 ;
struct V_154 V_200 ;
char * V_330 = NULL ;
int V_340 ;
int V_341 ;
int V_342 ;
int V_343 ;
int V_344 ;
int V_345 ;
int V_346 ;
int V_347 ;
T_2 V_348 ;
T_2 V_349 ;
T_2 V_350 ;
T_2 V_351 ;
V_328 = F_1 () ;
if ( ! V_328 ) {
V_38 = - V_88 ;
goto V_288;
}
V_329 = F_1 () ;
if ( ! V_329 ) {
V_38 = - V_88 ;
goto V_288;
}
V_330 = F_232 ( V_327 -> V_169 , V_352 | V_353 ) ;
if ( ! V_330 ) {
V_330 = F_261 ( V_327 -> V_169 ) ;
if ( ! V_330 ) {
V_38 = - V_88 ;
goto V_288;
}
}
V_328 -> V_237 = 1 ;
V_328 -> V_240 = 1 ;
V_329 -> V_237 = 1 ;
V_329 -> V_240 = 1 ;
F_192 ( & V_327 -> V_26 -> V_239 ) ;
V_342 = F_33 ( V_327 -> V_118 ) ;
V_340 = V_342 ;
V_328 -> V_8 [ V_342 ] = V_327 -> V_118 ;
F_115 ( V_328 -> V_8 [ V_342 ] ) ;
V_343 = F_33 ( V_336 -> V_118 ) ;
V_341 = V_343 ;
V_329 -> V_8 [ V_343 ] = V_336 -> V_118 ;
F_115 ( V_329 -> V_8 [ V_343 ] ) ;
F_193 ( & V_327 -> V_26 -> V_239 ) ;
if ( V_342 == 0 )
F_191 ( V_328 -> V_8 [ V_342 ] ,
& V_339 , V_328 -> V_17 [ V_342 ] ) ;
else
F_255 ( V_328 -> V_8 [ V_342 ] ,
& V_339 , V_328 -> V_17 [ V_342 ] ) ;
if ( V_343 == 0 )
F_191 ( V_329 -> V_8 [ V_343 ] ,
& V_200 , V_329 -> V_17 [ V_343 ] ) ;
else
F_255 ( V_329 -> V_8 [ V_343 ] ,
& V_200 , V_329 -> V_17 [ V_343 ] ) ;
V_344 = V_345 = 0 ;
V_346 = V_347 = 0 ;
while ( 1 ) {
if ( V_346 && ! V_344 ) {
V_38 = F_258 ( V_327 , V_328 , & V_342 ,
V_340 ,
V_346 != V_354 ,
& V_339 ) ;
if ( V_38 < 0 )
V_344 = V_355 ;
V_346 = 0 ;
}
if ( V_347 && ! V_345 ) {
V_38 = F_258 ( V_336 , V_329 , & V_343 ,
V_341 ,
V_347 != V_354 ,
& V_200 ) ;
if ( V_38 < 0 )
V_345 = V_355 ;
V_347 = 0 ;
}
if ( V_344 && V_345 ) {
V_38 = 0 ;
goto V_288;
} else if ( V_344 ) {
if ( V_343 == 0 ) {
V_38 = V_337 ( V_327 , V_336 ,
V_328 , V_329 ,
& V_200 ,
V_356 ,
V_338 ) ;
if ( V_38 < 0 )
goto V_288;
}
V_347 = V_355 ;
continue;
} else if ( V_345 ) {
if ( V_342 == 0 ) {
V_38 = V_337 ( V_327 , V_336 ,
V_328 , V_329 ,
& V_339 ,
V_357 ,
V_338 ) ;
if ( V_38 < 0 )
goto V_288;
}
V_346 = V_355 ;
continue;
}
if ( V_342 == 0 && V_343 == 0 ) {
V_331 = F_148 ( & V_339 , & V_200 ) ;
if ( V_331 < 0 ) {
V_38 = V_337 ( V_327 , V_336 ,
V_328 , V_329 ,
& V_339 ,
V_357 ,
V_338 ) ;
if ( V_38 < 0 )
goto V_288;
V_346 = V_355 ;
} else if ( V_331 > 0 ) {
V_38 = V_337 ( V_327 , V_336 ,
V_328 , V_329 ,
& V_200 ,
V_356 ,
V_338 ) ;
if ( V_38 < 0 )
goto V_288;
V_347 = V_355 ;
} else {
enum V_358 V_359 ;
F_32 ( ! F_135 ( V_328 -> V_8 [ 0 ] ) ) ;
V_38 = F_259 ( V_327 , V_328 ,
V_329 , V_330 ) ;
if ( V_38 )
V_359 = V_360 ;
else
V_359 = V_361 ;
V_38 = V_337 ( V_327 , V_336 ,
V_328 , V_329 ,
& V_339 , V_359 , V_338 ) ;
if ( V_38 < 0 )
goto V_288;
V_346 = V_355 ;
V_347 = V_355 ;
}
} else if ( V_342 == V_343 ) {
V_331 = F_148 ( & V_339 , & V_200 ) ;
if ( V_331 < 0 ) {
V_346 = V_355 ;
} else if ( V_331 > 0 ) {
V_347 = V_355 ;
} else {
V_348 = F_81 (
V_328 -> V_8 [ V_342 ] ,
V_328 -> V_17 [ V_342 ] ) ;
V_349 = F_81 (
V_329 -> V_8 [ V_343 ] ,
V_329 -> V_17 [ V_343 ] ) ;
V_350 = F_82 (
V_328 -> V_8 [ V_342 ] ,
V_328 -> V_17 [ V_342 ] ) ;
V_351 = F_82 (
V_329 -> V_8 [ V_343 ] ,
V_329 -> V_17 [ V_343 ] ) ;
if ( V_348 == V_349 &&
V_350 == V_351 ) {
V_346 = V_354 ;
V_347 = V_354 ;
} else {
V_346 = V_355 ;
V_347 = V_355 ;
}
}
} else if ( V_342 < V_343 ) {
V_347 = V_355 ;
} else {
V_346 = V_355 ;
}
}
V_288:
F_7 ( V_328 ) ;
F_7 ( V_329 ) ;
F_262 ( V_330 ) ;
return V_38 ;
}
int F_254 ( struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_154 * V_85 , int V_39 , T_2 V_323 )
{
int V_80 ;
struct V_14 * V_257 ;
F_32 ( ! V_2 -> V_219 ) ;
while ( V_39 < V_7 ) {
if ( ! V_2 -> V_8 [ V_39 ] )
return 1 ;
V_80 = V_2 -> V_17 [ V_39 ] + 1 ;
V_257 = V_2 -> V_8 [ V_39 ] ;
V_66:
if ( V_80 >= F_90 ( V_257 ) ) {
int V_38 ;
int V_362 ;
struct V_154 V_363 ;
if ( V_39 + 1 >= V_7 ||
! V_2 -> V_8 [ V_39 + 1 ] )
return 1 ;
if ( V_2 -> V_9 [ V_39 + 1 ] ) {
V_39 ++ ;
continue;
}
V_80 = F_90 ( V_257 ) - 1 ;
if ( V_39 == 0 )
F_191 ( V_257 , & V_363 , V_80 ) ;
else
F_255 ( V_257 , & V_363 , V_80 ) ;
V_362 = V_2 -> V_236 ;
F_8 ( V_2 ) ;
V_2 -> V_236 = V_39 ;
V_38 = F_189 ( NULL , V_19 , & V_363 , V_2 ,
0 , 0 ) ;
V_2 -> V_236 = V_362 ;
if ( V_38 < 0 )
return V_38 ;
V_257 = V_2 -> V_8 [ V_39 ] ;
V_80 = V_2 -> V_17 [ V_39 ] ;
if ( V_38 == 0 )
V_80 ++ ;
goto V_66;
}
if ( V_39 == 0 )
F_191 ( V_257 , V_85 , V_80 ) ;
else {
T_2 V_161 = F_82 ( V_257 , V_80 ) ;
if ( V_161 < V_323 ) {
V_80 ++ ;
goto V_66;
}
F_255 ( V_257 , V_85 , V_80 ) ;
}
return 0 ;
}
return 1 ;
}
int F_190 ( struct V_18 * V_19 , struct V_1 * V_2 )
{
return F_263 ( V_19 , V_2 , 0 ) ;
}
int F_263 ( struct V_18 * V_19 , struct V_1 * V_2 ,
T_2 V_132 )
{
int V_80 ;
int V_39 ;
struct V_14 * V_257 ;
struct V_14 * V_66 ;
struct V_154 V_85 ;
T_4 V_98 ;
int V_38 ;
int V_364 = V_2 -> V_244 ;
int V_365 = 0 ;
V_98 = F_90 ( V_2 -> V_8 [ 0 ] ) ;
if ( V_98 == 0 )
return 1 ;
F_191 ( V_2 -> V_8 [ 0 ] , & V_85 , V_98 - 1 ) ;
V_227:
V_39 = 1 ;
V_66 = NULL ;
V_365 = 0 ;
F_8 ( V_2 ) ;
V_2 -> V_219 = 1 ;
V_2 -> V_244 = 1 ;
if ( V_132 )
V_38 = F_198 ( V_19 , & V_85 , V_2 , V_132 ) ;
else
V_38 = F_189 ( NULL , V_19 , & V_85 , V_2 , 0 , 0 ) ;
V_2 -> V_219 = 0 ;
if ( V_38 < 0 )
return V_38 ;
V_98 = F_90 ( V_2 -> V_8 [ 0 ] ) ;
if ( V_98 > 0 && V_2 -> V_17 [ 0 ] < V_98 - 1 ) {
if ( V_38 == 0 )
V_2 -> V_17 [ 0 ] ++ ;
V_38 = 0 ;
goto V_228;
}
if ( V_98 > 0 && V_38 > 0 && V_2 -> V_17 [ 0 ] == V_98 - 1 ) {
V_38 = 0 ;
goto V_228;
}
while ( V_39 < V_7 ) {
if ( ! V_2 -> V_8 [ V_39 ] ) {
V_38 = 1 ;
goto V_228;
}
V_80 = V_2 -> V_17 [ V_39 ] + 1 ;
V_257 = V_2 -> V_8 [ V_39 ] ;
if ( V_80 >= F_90 ( V_257 ) ) {
V_39 ++ ;
if ( V_39 == V_7 ) {
V_38 = 1 ;
goto V_228;
}
continue;
}
if ( V_66 ) {
F_10 ( V_66 , V_365 ) ;
F_11 ( V_66 ) ;
}
V_66 = V_257 ;
V_365 = V_2 -> V_9 [ V_39 ] ;
V_38 = F_180 ( NULL , V_19 , V_2 , & V_66 , V_39 ,
V_80 , & V_85 , 0 ) ;
if ( V_38 == - V_223 )
goto V_227;
if ( V_38 < 0 ) {
F_8 ( V_2 ) ;
goto V_228;
}
if ( ! V_2 -> V_240 ) {
V_38 = F_264 ( V_66 ) ;
if ( ! V_38 && V_132 ) {
F_11 ( V_66 ) ;
F_8 ( V_2 ) ;
F_265 () ;
goto V_227;
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
V_257 = V_2 -> V_8 [ V_39 ] ;
if ( V_2 -> V_9 [ V_39 ] )
F_10 ( V_257 , V_2 -> V_9 [ V_39 ] ) ;
F_11 ( V_257 ) ;
V_2 -> V_8 [ V_39 ] = V_66 ;
V_2 -> V_17 [ V_39 ] = 0 ;
if ( ! V_2 -> V_240 )
V_2 -> V_9 [ V_39 ] = V_365 ;
if ( ! V_39 )
break;
V_38 = F_180 ( NULL , V_19 , V_2 , & V_66 , V_39 ,
0 , & V_85 , 0 ) ;
if ( V_38 == - V_223 )
goto V_227;
if ( V_38 < 0 ) {
F_8 ( V_2 ) ;
goto V_228;
}
if ( ! V_2 -> V_240 ) {
V_38 = F_264 ( V_66 ) ;
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
V_228:
F_178 ( V_2 , 0 , 1 , 0 , NULL ) ;
V_2 -> V_244 = V_364 ;
if ( ! V_364 )
F_3 ( V_2 ) ;
return V_38 ;
}
int F_266 ( struct V_18 * V_19 ,
struct V_1 * V_2 , T_2 V_366 ,
int type )
{
struct V_154 V_234 ;
struct V_14 * V_172 ;
T_4 V_98 ;
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
V_172 = V_2 -> V_8 [ 0 ] ;
V_98 = F_90 ( V_172 ) ;
if ( V_98 == 0 )
return 1 ;
if ( V_2 -> V_17 [ 0 ] == V_98 )
V_2 -> V_17 [ 0 ] -- ;
F_191 ( V_172 , & V_234 , V_2 -> V_17 [ 0 ] ) ;
if ( V_234 . V_28 < V_366 )
break;
if ( V_234 . type == type )
return 0 ;
if ( V_234 . V_28 == V_366 &&
V_234 . type < type )
break;
}
return 1 ;
}
int F_267 ( struct V_18 * V_19 ,
struct V_1 * V_2 , T_2 V_366 )
{
struct V_154 V_234 ;
struct V_14 * V_172 ;
T_4 V_98 ;
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
V_172 = V_2 -> V_8 [ 0 ] ;
V_98 = F_90 ( V_172 ) ;
if ( V_98 == 0 )
return 1 ;
if ( V_2 -> V_17 [ 0 ] == V_98 )
V_2 -> V_17 [ 0 ] -- ;
F_191 ( V_172 , & V_234 , V_2 -> V_17 [ 0 ] ) ;
if ( V_234 . V_28 < V_366 )
break;
if ( V_234 . type == V_367 ||
V_234 . type == V_368 )
return 0 ;
if ( V_234 . V_28 == V_366 &&
V_234 . type < V_367 )
break;
}
return 1 ;
}
