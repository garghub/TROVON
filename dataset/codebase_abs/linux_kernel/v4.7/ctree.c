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
V_141 = F_128 ( V_26 , V_20 -> V_46 ,
V_20 -> V_47 ) ;
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
V_20 = F_128 ( V_19 -> V_26 , V_76 ,
V_19 -> V_146 ) ;
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
! F_25 ( V_147 , & V_19 -> V_24 ) )
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
if ( V_33 -> V_148 != V_19 -> V_26 -> V_44 )
F_142 ( 1 , V_149 L_2 ,
V_33 -> V_43 ,
V_19 -> V_26 -> V_44 -> V_43 ) ;
if ( V_33 -> V_43 != V_19 -> V_26 -> V_87 )
F_142 ( 1 , V_149 L_2 ,
V_33 -> V_43 , V_19 -> V_26 -> V_87 ) ;
if ( ! F_138 ( V_33 , V_19 , V_34 ) ) {
V_33 -> V_150 = true ;
* V_35 = V_34 ;
return 0 ;
}
V_127 = V_34 -> V_46 & ~ ( ( T_2 ) V_151 - 1 ) ;
if ( V_74 )
F_143 ( V_74 ) ;
F_143 ( V_34 ) ;
V_38 = F_111 ( V_33 , V_19 , V_34 , V_74 ,
V_126 , V_35 , V_127 , 0 ) ;
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
T_2 V_127 = * V_161 ;
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
F_32 ( V_33 -> V_148 != V_19 -> V_26 -> V_44 ) ;
F_32 ( V_33 -> V_43 != V_19 -> V_26 -> V_87 ) ;
V_165 = F_90 ( V_74 ) ;
V_154 = V_19 -> V_146 ;
V_166 = V_165 - 1 ;
if ( V_165 <= 1 )
return 0 ;
F_143 ( V_74 ) ;
for ( V_6 = V_160 ; V_6 <= V_166 ; V_6 ++ ) {
int V_171 = 1 ;
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
V_171 = F_145 ( V_152 , V_153 , V_154 ) ;
}
if ( ! V_171 && V_6 < V_166 ) {
V_153 = F_81 ( V_74 , V_6 + 1 ) ;
V_171 = F_145 ( V_152 , V_153 , V_154 ) ;
}
if ( V_171 ) {
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
return - V_172 ;
}
} else if ( ! V_169 ) {
V_167 = F_152 ( V_75 , V_163 ) ;
if ( V_167 ) {
F_11 ( V_75 ) ;
return V_167 ;
}
}
}
if ( V_127 == 0 )
V_127 = V_164 ;
F_19 ( V_75 ) ;
F_143 ( V_75 ) ;
V_167 = F_111 ( V_33 , V_19 , V_75 , V_74 , V_6 ,
& V_75 , V_127 ,
F_153 ( 16 * V_154 ,
( V_166 - V_6 ) * V_154 ) ) ;
if ( V_167 ) {
F_20 ( V_75 ) ;
F_11 ( V_75 ) ;
break;
}
V_127 = V_75 -> V_46 ;
V_164 = V_75 -> V_46 ;
* V_161 = V_127 ;
F_20 ( V_75 ) ;
F_11 ( V_75 ) ;
}
return V_167 ;
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
int V_175 , struct V_156 * V_85 ,
int V_176 , int * V_80 )
{
int V_177 = 0 ;
int V_178 = V_176 ;
int V_179 ;
int V_38 ;
struct V_40 * V_180 = NULL ;
struct V_40 V_181 ;
unsigned long V_159 ;
char * V_182 = NULL ;
unsigned long V_183 = 0 ;
unsigned long V_184 = 0 ;
int V_167 ;
while ( V_177 < V_178 ) {
V_179 = ( V_177 + V_178 ) / 2 ;
V_159 = V_5 + V_179 * V_175 ;
if ( ! V_182 || V_159 < V_183 ||
( V_159 + sizeof( struct V_40 ) ) >
V_183 + V_184 ) {
V_167 = F_158 ( V_20 , V_159 ,
sizeof( struct V_40 ) ,
& V_182 , & V_183 , & V_184 ) ;
if ( ! V_167 ) {
V_180 = (struct V_40 * ) ( V_182 + V_159 -
V_183 ) ;
} else if ( V_167 == 1 ) {
F_159 ( V_20 , & V_181 ,
V_159 , sizeof( V_181 ) ) ;
V_180 = & V_181 ;
} else {
return V_167 ;
}
} else {
V_180 = (struct V_40 * ) ( V_182 + V_159 -
V_183 ) ;
}
V_38 = F_146 ( V_180 , V_85 ) ;
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
static int F_160 ( struct V_14 * V_20 , struct V_156 * V_85 ,
int V_39 , int * V_80 )
{
if ( V_39 == 0 )
return F_157 ( V_20 ,
F_161 ( struct V_185 , V_186 ) ,
sizeof( struct V_187 ) ,
V_85 , F_90 ( V_20 ) ,
V_80 ) ;
else
return F_157 ( V_20 ,
F_161 ( struct V_188 , V_189 ) ,
sizeof( struct V_140 ) ,
V_85 , F_90 ( V_20 ) ,
V_80 ) ;
}
int F_162 ( struct V_14 * V_20 , struct V_156 * V_85 ,
int V_39 , int * V_80 )
{
return F_160 ( V_20 , V_85 , V_39 , V_80 ) ;
}
static void F_163 ( struct V_18 * V_19 , T_4 V_190 )
{
F_26 ( & V_19 -> V_191 ) ;
F_164 ( & V_19 -> V_119 ,
F_165 ( & V_19 -> V_119 ) + V_190 ) ;
F_30 ( & V_19 -> V_191 ) ;
}
static void F_166 ( struct V_18 * V_19 , T_4 V_190 )
{
F_26 ( & V_19 -> V_191 ) ;
F_164 ( & V_19 -> V_119 ,
F_165 ( & V_19 -> V_119 ) - V_190 ) ;
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
V_38 = - V_123 ;
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
V_38 = - V_123 ;
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
T_4 V_98 ;
T_2 V_205 ;
T_2 V_206 ;
T_2 V_207 = 0 ;
T_2 V_163 ;
struct V_14 * V_20 ;
T_4 V_174 ;
T_4 V_154 ;
T_4 V_208 = 0 ;
if ( V_39 != 1 )
return;
if ( ! V_2 -> V_8 [ V_39 ] )
return;
V_21 = V_2 -> V_8 [ V_39 ] ;
V_205 = F_81 ( V_21 , V_80 ) ;
V_154 = V_19 -> V_146 ;
V_20 = F_150 ( V_19 -> V_26 , V_205 ) ;
if ( V_20 ) {
F_11 ( V_20 ) ;
return;
}
V_206 = V_205 ;
V_98 = F_90 ( V_21 ) ;
V_174 = V_80 ;
while ( 1 ) {
if ( V_2 -> V_209 == V_210 ) {
if ( V_174 == 0 )
break;
V_174 -- ;
} else if ( V_2 -> V_209 == V_211 ) {
V_174 ++ ;
if ( V_174 >= V_98 )
break;
}
if ( V_2 -> V_209 == V_210 && V_28 ) {
F_35 ( V_21 , & V_41 , V_174 ) ;
if ( F_175 ( & V_41 ) != V_28 )
break;
}
V_205 = F_81 ( V_21 , V_174 ) ;
if ( ( V_205 <= V_206 && V_206 - V_205 <= 65536 ) ||
( V_205 > V_206 && V_205 - V_206 <= 65536 ) ) {
V_163 = F_82 ( V_21 , V_174 ) ;
F_176 ( V_19 , V_205 ) ;
V_207 += V_154 ;
}
V_208 ++ ;
if ( ( V_207 > 65536 || V_208 > 32 ) )
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
T_2 V_163 ;
T_2 V_212 = 0 ;
T_2 V_213 = 0 ;
V_74 = V_2 -> V_8 [ V_39 + 1 ] ;
if ( ! V_74 )
return;
V_98 = F_90 ( V_74 ) ;
V_80 = V_2 -> V_17 [ V_39 + 1 ] ;
if ( V_80 > 0 ) {
V_212 = F_81 ( V_74 , V_80 - 1 ) ;
V_163 = F_82 ( V_74 , V_80 - 1 ) ;
V_20 = F_150 ( V_19 -> V_26 , V_212 ) ;
if ( V_20 && F_151 ( V_20 , V_163 , 1 ) != 0 )
V_212 = 0 ;
F_11 ( V_20 ) ;
}
if ( V_80 + 1 < V_98 ) {
V_213 = F_81 ( V_74 , V_80 + 1 ) ;
V_163 = F_82 ( V_74 , V_80 + 1 ) ;
V_20 = F_150 ( V_19 -> V_26 , V_213 ) ;
if ( V_20 && F_151 ( V_20 , V_163 , 1 ) != 0 )
V_213 = 0 ;
F_11 ( V_20 ) ;
}
if ( V_212 )
F_176 ( V_19 , V_212 ) ;
if ( V_213 )
F_176 ( V_19 , V_213 ) ;
}
static T_1 void F_178 ( struct V_1 * V_2 , int V_39 ,
int V_214 , int V_215 ,
int * V_216 )
{
int V_6 ;
int V_217 = V_39 ;
int V_218 = 0 ;
struct V_14 * V_219 ;
for ( V_6 = V_39 ; V_6 < V_7 ; V_6 ++ ) {
if ( ! V_2 -> V_8 [ V_6 ] )
break;
if ( ! V_2 -> V_9 [ V_6 ] )
break;
if ( ! V_218 && V_2 -> V_17 [ V_6 ] == 0 ) {
V_217 = V_6 + 1 ;
continue;
}
if ( ! V_218 && V_2 -> V_220 ) {
T_4 V_98 ;
V_219 = V_2 -> V_8 [ V_6 ] ;
V_98 = F_90 ( V_219 ) ;
if ( V_98 < 1 || V_2 -> V_17 [ V_6 ] >= V_98 - 1 ) {
V_217 = V_6 + 1 ;
continue;
}
}
if ( V_217 < V_6 && V_6 >= V_214 )
V_218 = 1 ;
V_219 = V_2 -> V_8 [ V_6 ] ;
if ( V_6 >= V_214 && V_6 > V_217 && V_2 -> V_9 [ V_6 ] ) {
F_10 ( V_219 , V_2 -> V_9 [ V_6 ] ) ;
V_2 -> V_9 [ V_6 ] = 0 ;
if ( V_216 &&
V_6 > V_215 &&
V_6 <= * V_216 ) {
* V_216 = V_6 - 1 ;
}
}
}
}
T_1 void F_179 ( struct V_1 * V_2 , int V_39 )
{
int V_6 ;
if ( V_2 -> V_220 )
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
struct V_14 * * V_221 , int V_39 , int V_80 ,
struct V_156 * V_85 , T_2 V_132 )
{
T_2 V_152 ;
T_2 V_163 ;
struct V_14 * V_222 = * V_221 ;
struct V_14 * V_180 ;
int V_38 ;
V_152 = F_81 ( V_222 , V_80 ) ;
V_163 = F_82 ( V_222 , V_80 ) ;
V_180 = F_150 ( V_19 -> V_26 , V_152 ) ;
if ( V_180 ) {
if ( F_151 ( V_180 , V_163 , 1 ) > 0 ) {
* V_221 = V_180 ;
return 0 ;
}
F_3 ( V_5 ) ;
V_38 = F_152 ( V_180 , V_163 ) ;
if ( ! V_38 ) {
* V_221 = V_180 ;
return 0 ;
}
F_11 ( V_180 ) ;
F_8 ( V_5 ) ;
return - V_172 ;
}
F_179 ( V_5 , V_39 + 1 ) ;
F_3 ( V_5 ) ;
F_11 ( V_180 ) ;
if ( V_5 -> V_209 != V_223 )
F_174 ( V_19 , V_5 , V_39 , V_80 , V_85 -> V_28 ) ;
F_8 ( V_5 ) ;
V_38 = - V_224 ;
V_180 = F_134 ( V_19 , V_152 , 0 ) ;
if ( ! F_37 ( V_180 ) ) {
if ( ! F_151 ( V_180 , 0 , 0 ) )
V_38 = - V_172 ;
F_11 ( V_180 ) ;
} else {
V_38 = F_38 ( V_180 ) ;
}
return V_38 ;
}
static int
F_181 ( struct V_32 * V_33 ,
struct V_18 * V_19 , struct V_1 * V_5 ,
struct V_14 * V_222 , int V_39 , int V_225 ,
int * V_216 )
{
int V_38 ;
if ( ( V_5 -> V_226 || V_225 > 0 ) && F_90 ( V_222 ) >=
F_132 ( V_19 ) - 3 ) {
int V_227 ;
if ( * V_216 < V_39 + 1 ) {
* V_216 = V_39 + 1 ;
F_8 ( V_5 ) ;
goto V_228;
}
F_3 ( V_5 ) ;
F_177 ( V_19 , V_5 , V_39 ) ;
V_227 = F_182 ( V_33 , V_19 , V_5 , V_39 ) ;
F_5 ( V_5 , NULL , 0 ) ;
F_72 ( V_227 > 0 ) ;
if ( V_227 ) {
V_38 = V_227 ;
goto V_229;
}
V_222 = V_5 -> V_8 [ V_39 ] ;
} else if ( V_225 < 0 && F_90 ( V_222 ) <
F_132 ( V_19 ) / 2 ) {
int V_227 ;
if ( * V_216 < V_39 + 1 ) {
* V_216 = V_39 + 1 ;
F_8 ( V_5 ) ;
goto V_228;
}
F_3 ( V_5 ) ;
F_177 ( V_19 , V_5 , V_39 ) ;
V_227 = F_167 ( V_33 , V_19 , V_5 , V_39 ) ;
F_5 ( V_5 , NULL , 0 ) ;
if ( V_227 ) {
V_38 = V_227 ;
goto V_229;
}
V_222 = V_5 -> V_8 [ V_39 ] ;
if ( ! V_222 ) {
F_8 ( V_5 ) ;
goto V_228;
}
F_72 ( F_90 ( V_222 ) == 1 ) ;
}
return 0 ;
V_228:
V_38 = - V_224 ;
V_229:
return V_38 ;
}
static void F_183 ( struct V_14 * V_222 ,
struct V_156 * V_85 ,
int V_39 )
{
#ifdef F_184
struct V_40 V_41 ;
F_185 ( & V_41 , V_85 ) ;
if ( V_39 == 0 )
ASSERT ( ! F_186 ( V_222 , & V_41 ,
F_161 ( struct V_185 , V_186 [ 0 ] . V_85 ) ,
sizeof( V_41 ) ) ) ;
else
ASSERT ( ! F_186 ( V_222 , & V_41 ,
F_161 ( struct V_188 , V_189 [ 0 ] . V_85 ) ,
sizeof( V_41 ) ) ) ;
#endif
}
static int F_187 ( struct V_14 * V_222 , struct V_156 * V_85 ,
int V_39 , int * V_230 , int * V_80 )
{
if ( * V_230 != 0 ) {
* V_230 = F_160 ( V_222 , V_85 , V_39 , V_80 ) ;
return * V_230 ;
}
F_183 ( V_222 , V_85 , V_39 ) ;
* V_80 = 0 ;
return 0 ;
}
int F_188 ( struct V_18 * V_231 , struct V_1 * V_2 ,
T_2 V_232 , T_2 V_233 , T_5 V_234 ,
struct V_156 * V_235 )
{
int V_38 ;
struct V_156 V_85 ;
struct V_14 * V_20 ;
ASSERT ( V_2 ) ;
ASSERT ( V_235 ) ;
V_85 . type = V_234 ;
V_85 . V_28 = V_232 ;
V_85 . V_159 = V_233 ;
V_38 = F_189 ( NULL , V_231 , & V_85 , V_2 , 0 , 0 ) ;
if ( V_38 < 0 )
return V_38 ;
V_20 = V_2 -> V_8 [ 0 ] ;
if ( V_38 && V_2 -> V_17 [ 0 ] >= F_90 ( V_20 ) ) {
V_38 = F_190 ( V_231 , V_2 ) ;
if ( V_38 )
return V_38 ;
V_20 = V_2 -> V_8 [ 0 ] ;
}
F_191 ( V_20 , V_235 , V_2 -> V_17 [ 0 ] ) ;
if ( V_235 -> type != V_85 . type ||
V_235 -> V_28 != V_85 . V_28 )
return 1 ;
return 0 ;
}
int F_189 ( struct V_32 * V_33 , struct V_18
* V_19 , struct V_156 * V_85 , struct V_1 * V_5 , int
V_225 , int V_37 )
{
struct V_14 * V_222 ;
int V_80 ;
int V_38 ;
int V_167 ;
int V_39 ;
int V_214 = 1 ;
int V_236 ;
int V_216 = 0 ;
T_5 V_237 = 0 ;
int V_215 ;
int V_230 ;
V_237 = V_5 -> V_237 ;
F_32 ( V_237 && V_225 > 0 ) ;
F_32 ( V_5 -> V_8 [ 0 ] != NULL ) ;
F_72 ( ! V_37 && V_225 ) ;
if ( V_225 < 0 ) {
V_214 = 2 ;
V_216 = 2 ;
} else if ( V_225 > 0 ) {
V_216 = 1 ;
}
if ( ! V_37 )
V_216 = - 1 ;
if ( V_37 && ( V_5 -> V_220 || V_5 -> V_237 ) )
V_216 = V_7 ;
V_215 = V_216 ;
V_228:
V_230 = - 1 ;
V_236 = V_10 ;
V_39 = 0 ;
if ( V_5 -> V_238 ) {
if ( V_5 -> V_239 )
F_192 ( & V_19 -> V_26 -> V_240 ) ;
V_222 = V_19 -> V_118 ;
F_115 ( V_222 ) ;
V_39 = F_33 ( V_222 ) ;
if ( V_5 -> V_239 )
F_193 ( & V_19 -> V_26 -> V_240 ) ;
if ( ! V_5 -> V_241 )
F_22 ( V_222 ) ;
} else {
if ( V_5 -> V_241 ) {
V_222 = F_12 ( V_19 ) ;
V_39 = F_33 ( V_222 ) ;
} else {
V_222 = F_21 ( V_19 ) ;
V_39 = F_33 ( V_222 ) ;
if ( V_39 <= V_216 ) {
F_23 ( V_222 ) ;
F_11 ( V_222 ) ;
V_222 = F_18 ( V_19 ) ;
V_236 = V_12 ;
V_39 = F_33 ( V_222 ) ;
}
}
}
V_5 -> V_8 [ V_39 ] = V_222 ;
if ( ! V_5 -> V_241 )
V_5 -> V_9 [ V_39 ] = V_236 ;
while ( V_222 ) {
V_39 = F_33 ( V_222 ) ;
if ( V_37 ) {
if ( ! F_138 ( V_33 , V_19 , V_222 ) ) {
V_33 -> V_150 = true ;
goto V_242;
}
if ( V_39 > V_216 ||
( V_39 + 1 > V_216 &&
V_39 + 1 < V_7 &&
V_5 -> V_8 [ V_39 + 1 ] ) ) {
V_216 = V_39 + 1 ;
F_8 ( V_5 ) ;
goto V_228;
}
F_3 ( V_5 ) ;
V_167 = F_141 ( V_33 , V_19 , V_222 ,
V_5 -> V_8 [ V_39 + 1 ] ,
V_5 -> V_17 [ V_39 + 1 ] , & V_222 ) ;
if ( V_167 ) {
V_38 = V_167 ;
goto V_229;
}
}
V_242:
V_5 -> V_8 [ V_39 ] = V_222 ;
F_5 ( V_5 , NULL , 0 ) ;
if ( ! V_225 && ! V_5 -> V_220 ) {
int V_243 = V_39 + 1 ;
if ( V_243 < V_7 && V_5 -> V_9 [ V_243 ] ) {
F_10 ( V_5 -> V_8 [ V_243 ] , V_5 -> V_9 [ V_243 ] ) ;
V_5 -> V_9 [ V_243 ] = 0 ;
}
}
V_38 = F_187 ( V_222 , V_85 , V_39 , & V_230 , & V_80 ) ;
if ( V_38 < 0 )
goto V_229;
if ( V_39 != 0 ) {
int V_244 = 0 ;
if ( V_38 && V_80 > 0 ) {
V_244 = 1 ;
V_80 -= 1 ;
}
V_5 -> V_17 [ V_39 ] = V_80 ;
V_167 = F_181 ( V_33 , V_19 , V_5 , V_222 , V_39 ,
V_225 , & V_216 ) ;
if ( V_167 == - V_224 )
goto V_228;
if ( V_167 ) {
V_38 = V_167 ;
goto V_229;
}
V_222 = V_5 -> V_8 [ V_39 ] ;
V_80 = V_5 -> V_17 [ V_39 ] ;
if ( V_80 == 0 && V_225 &&
V_216 < V_39 + 1 ) {
V_216 = V_39 + 1 ;
F_8 ( V_5 ) ;
goto V_228;
}
F_178 ( V_5 , V_39 , V_214 ,
V_215 , & V_216 ) ;
if ( V_39 == V_237 ) {
if ( V_244 )
V_5 -> V_17 [ V_39 ] ++ ;
goto V_229;
}
V_167 = F_180 ( V_33 , V_19 , V_5 ,
& V_222 , V_39 , V_80 , V_85 , 0 ) ;
if ( V_167 == - V_224 )
goto V_228;
if ( V_167 ) {
V_38 = V_167 ;
goto V_229;
}
if ( ! V_5 -> V_241 ) {
V_39 = F_33 ( V_222 ) ;
if ( V_39 <= V_216 ) {
V_167 = F_194 ( V_222 ) ;
if ( ! V_167 ) {
F_3 ( V_5 ) ;
F_19 ( V_222 ) ;
F_5 ( V_5 , V_222 ,
V_12 ) ;
}
V_5 -> V_9 [ V_39 ] = V_12 ;
} else {
V_167 = F_195 ( V_222 ) ;
if ( ! V_167 ) {
F_3 ( V_5 ) ;
F_22 ( V_222 ) ;
F_5 ( V_5 , V_222 ,
V_10 ) ;
}
V_5 -> V_9 [ V_39 ] = V_10 ;
}
V_5 -> V_8 [ V_39 ] = V_222 ;
}
} else {
V_5 -> V_17 [ V_39 ] = V_80 ;
if ( V_225 > 0 &&
F_196 ( V_19 , V_222 ) < V_225 ) {
if ( V_216 < 1 ) {
V_216 = 1 ;
F_8 ( V_5 ) ;
goto V_228;
}
F_3 ( V_5 ) ;
V_167 = F_197 ( V_33 , V_19 , V_85 ,
V_5 , V_225 , V_38 == 0 ) ;
F_5 ( V_5 , NULL , 0 ) ;
F_72 ( V_167 > 0 ) ;
if ( V_167 ) {
V_38 = V_167 ;
goto V_229;
}
}
if ( ! V_5 -> V_226 )
F_178 ( V_5 , V_39 , V_214 ,
V_215 , & V_216 ) ;
goto V_229;
}
}
V_38 = 1 ;
V_229:
if ( ! V_5 -> V_245 )
F_3 ( V_5 ) ;
if ( V_38 < 0 && ! V_5 -> V_246 )
F_8 ( V_5 ) ;
return V_38 ;
}
int F_198 ( struct V_18 * V_19 , struct V_156 * V_85 ,
struct V_1 * V_5 , T_2 V_132 )
{
struct V_14 * V_222 ;
int V_80 ;
int V_38 ;
int V_167 ;
int V_39 ;
int V_214 = 1 ;
T_5 V_237 = 0 ;
int V_230 = - 1 ;
V_237 = V_5 -> V_237 ;
F_32 ( V_5 -> V_8 [ 0 ] != NULL ) ;
if ( V_5 -> V_238 ) {
F_72 ( V_132 ) ;
return F_189 ( NULL , V_19 , V_85 , V_5 , 0 , 0 ) ;
}
V_228:
V_222 = F_133 ( V_19 , V_132 ) ;
V_39 = F_33 ( V_222 ) ;
V_5 -> V_9 [ V_39 ] = V_10 ;
while ( V_222 ) {
V_39 = F_33 ( V_222 ) ;
V_5 -> V_8 [ V_39 ] = V_222 ;
F_5 ( V_5 , NULL , 0 ) ;
F_179 ( V_5 , V_39 + 1 ) ;
V_230 = - 1 ;
V_38 = F_187 ( V_222 , V_85 , V_39 , & V_230 , & V_80 ) ;
if ( V_39 != 0 ) {
int V_244 = 0 ;
if ( V_38 && V_80 > 0 ) {
V_244 = 1 ;
V_80 -= 1 ;
}
V_5 -> V_17 [ V_39 ] = V_80 ;
F_178 ( V_5 , V_39 , V_214 , 0 , NULL ) ;
if ( V_39 == V_237 ) {
if ( V_244 )
V_5 -> V_17 [ V_39 ] ++ ;
goto V_229;
}
V_167 = F_180 ( NULL , V_19 , V_5 , & V_222 , V_39 ,
V_80 , V_85 , V_132 ) ;
if ( V_167 == - V_224 )
goto V_228;
if ( V_167 ) {
V_38 = V_167 ;
goto V_229;
}
V_39 = F_33 ( V_222 ) ;
V_167 = F_195 ( V_222 ) ;
if ( ! V_167 ) {
F_3 ( V_5 ) ;
F_22 ( V_222 ) ;
F_5 ( V_5 , V_222 ,
V_10 ) ;
}
V_222 = F_127 ( V_19 -> V_26 , V_5 , V_222 , V_132 ) ;
if ( ! V_222 ) {
V_38 = - V_88 ;
goto V_229;
}
V_5 -> V_9 [ V_39 ] = V_10 ;
V_5 -> V_8 [ V_39 ] = V_222 ;
} else {
V_5 -> V_17 [ V_39 ] = V_80 ;
F_178 ( V_5 , V_39 , V_214 , 0 , NULL ) ;
goto V_229;
}
}
V_38 = 1 ;
V_229:
if ( ! V_5 -> V_245 )
F_3 ( V_5 ) ;
if ( V_38 < 0 )
F_8 ( V_5 ) ;
return V_38 ;
}
int F_199 ( struct V_18 * V_19 ,
struct V_156 * V_85 , struct V_1 * V_5 ,
int V_247 , int V_248 )
{
int V_38 ;
struct V_14 * V_173 ;
V_228:
V_38 = F_189 ( NULL , V_19 , V_85 , V_5 , 0 , 0 ) ;
if ( V_38 <= 0 )
return V_38 ;
V_173 = V_5 -> V_8 [ 0 ] ;
if ( V_247 ) {
if ( V_5 -> V_17 [ 0 ] >= F_90 ( V_173 ) ) {
V_38 = F_190 ( V_19 , V_5 ) ;
if ( V_38 <= 0 )
return V_38 ;
if ( ! V_248 )
return 1 ;
V_248 = 0 ;
V_247 = 0 ;
F_8 ( V_5 ) ;
goto V_228;
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
if ( ! V_248 )
return 1 ;
V_248 = 0 ;
V_247 = 1 ;
F_8 ( V_5 ) ;
goto V_228;
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
struct V_14 * V_219 ;
for ( V_6 = V_39 ; V_6 < V_7 ; V_6 ++ ) {
int V_249 = V_2 -> V_17 [ V_6 ] ;
if ( ! V_2 -> V_8 [ V_6 ] )
break;
V_219 = V_2 -> V_8 [ V_6 ] ;
F_96 ( V_26 , V_219 , V_249 , 1 ) ;
F_123 ( V_219 , V_85 , V_249 ) ;
F_50 ( V_2 -> V_8 [ V_6 ] ) ;
if ( V_249 != 0 )
break;
}
}
void F_202 ( struct V_54 * V_26 ,
struct V_1 * V_2 ,
struct V_156 * V_250 )
{
struct V_40 V_41 ;
struct V_14 * V_20 ;
int V_80 ;
V_20 = V_2 -> V_8 [ 0 ] ;
V_80 = V_2 -> V_17 [ 0 ] ;
if ( V_80 > 0 ) {
F_34 ( V_20 , & V_41 , V_80 - 1 ) ;
F_72 ( F_146 ( & V_41 , V_250 ) >= 0 ) ;
}
if ( V_80 < F_90 ( V_20 ) - 1 ) {
F_34 ( V_20 , & V_41 , V_80 + 1 ) ;
F_72 ( F_146 ( & V_41 , V_250 ) <= 0 ) ;
}
F_185 ( & V_41 , V_250 ) ;
F_203 ( V_20 , & V_41 , V_80 ) ;
F_50 ( V_20 ) ;
if ( V_80 == 0 )
F_201 ( V_26 , V_2 , & V_41 , 1 ) ;
}
static int F_169 ( struct V_32 * V_33 ,
struct V_18 * V_19 , struct V_14 * V_107 ,
struct V_14 * V_108 , int V_251 )
{
int V_252 = 0 ;
int V_253 ;
int V_254 ;
int V_38 = 0 ;
V_253 = F_90 ( V_108 ) ;
V_254 = F_90 ( V_107 ) ;
V_252 = F_132 ( V_19 ) - V_254 ;
F_32 ( F_48 ( V_108 ) != V_33 -> V_43 ) ;
F_32 ( F_48 ( V_107 ) != V_33 -> V_43 ) ;
if ( ! V_251 && V_253 <= 8 )
return 1 ;
if ( V_252 <= 0 )
return 1 ;
if ( V_251 ) {
V_252 = F_153 ( V_253 , V_252 ) ;
if ( V_252 < V_253 ) {
if ( V_253 - V_252 < 8 ) {
if ( V_252 <= 8 )
return 1 ;
V_252 -= 8 ;
}
}
} else
V_252 = F_153 ( V_253 - 8 , V_252 ) ;
V_38 = F_94 ( V_19 -> V_26 , V_107 , V_108 , V_254 , 0 ,
V_252 ) ;
if ( V_38 ) {
F_113 ( V_33 , V_19 , V_38 ) ;
return V_38 ;
}
F_39 ( V_107 , V_108 ,
F_124 ( V_254 ) ,
F_124 ( 0 ) ,
V_252 * sizeof( struct V_140 ) ) ;
if ( V_252 < V_253 ) {
F_125 ( V_108 , F_124 ( 0 ) ,
F_124 ( V_252 ) ,
( V_253 - V_252 ) *
sizeof( struct V_140 ) ) ;
}
F_126 ( V_108 , V_253 - V_252 ) ;
F_126 ( V_107 , V_254 + V_252 ) ;
F_50 ( V_108 ) ;
F_50 ( V_107 ) ;
return V_38 ;
}
static int F_171 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_14 * V_107 ,
struct V_14 * V_108 )
{
int V_252 = 0 ;
int V_255 ;
int V_253 ;
int V_254 ;
int V_38 = 0 ;
F_32 ( F_48 ( V_108 ) != V_33 -> V_43 ) ;
F_32 ( F_48 ( V_107 ) != V_33 -> V_43 ) ;
V_253 = F_90 ( V_108 ) ;
V_254 = F_90 ( V_107 ) ;
V_252 = F_132 ( V_19 ) - V_254 ;
if ( V_252 <= 0 )
return 1 ;
if ( V_253 < 4 )
return 1 ;
V_255 = V_253 / 2 + 1 ;
if ( V_255 >= V_253 )
return 1 ;
if ( V_255 < V_252 )
V_252 = V_255 ;
F_95 ( V_19 -> V_26 , V_107 , V_252 , 0 , V_254 ) ;
F_125 ( V_107 , F_124 ( V_252 ) ,
F_124 ( 0 ) ,
( V_254 ) *
sizeof( struct V_140 ) ) ;
V_38 = F_94 ( V_19 -> V_26 , V_107 , V_108 , 0 ,
V_253 - V_252 , V_252 ) ;
if ( V_38 ) {
F_113 ( V_33 , V_19 , V_38 ) ;
return V_38 ;
}
F_39 ( V_107 , V_108 ,
F_124 ( 0 ) ,
F_124 ( V_253 - V_252 ) ,
V_252 * sizeof( struct V_140 ) ) ;
F_126 ( V_108 , V_253 - V_252 ) ;
F_126 ( V_107 , V_254 + V_252 ) ;
F_50 ( V_108 ) ;
F_50 ( V_107 ) ;
return V_38 ;
}
static T_1 int F_204 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_39 )
{
T_2 V_256 ;
struct V_14 * V_257 ;
struct V_14 * V_258 ;
struct V_14 * V_143 ;
struct V_40 V_259 ;
F_72 ( V_2 -> V_8 [ V_39 ] ) ;
F_72 ( V_2 -> V_8 [ V_39 - 1 ] != V_19 -> V_21 ) ;
V_257 = V_2 -> V_8 [ V_39 - 1 ] ;
if ( V_39 == 1 )
F_34 ( V_257 , & V_259 , 0 ) ;
else
F_35 ( V_257 , & V_259 , 0 ) ;
V_258 = F_36 ( V_33 , V_19 , 0 , V_19 -> V_124 . V_28 ,
& V_259 , V_39 , V_19 -> V_21 -> V_46 , 0 ) ;
if ( F_37 ( V_258 ) )
return F_38 ( V_258 ) ;
F_163 ( V_19 , V_19 -> V_146 ) ;
F_205 ( V_258 , 0 , 0 , sizeof( struct V_260 ) ) ;
F_126 ( V_258 , 1 ) ;
F_130 ( V_258 , V_39 ) ;
F_40 ( V_258 , V_258 -> V_46 ) ;
F_41 ( V_258 , V_33 -> V_43 ) ;
F_42 ( V_258 , V_48 ) ;
F_45 ( V_258 , V_19 -> V_124 . V_28 ) ;
F_46 ( V_258 , V_19 -> V_26 -> V_52 , F_47 () ,
V_53 ) ;
F_46 ( V_258 , V_19 -> V_26 -> V_261 ,
F_206 ( V_258 ) , V_262 ) ;
F_123 ( V_258 , & V_259 , 0 ) ;
F_118 ( V_258 , 0 , V_257 -> V_46 ) ;
V_256 = F_48 ( V_257 ) ;
F_32 ( V_256 != V_33 -> V_43 ) ;
F_119 ( V_258 , 0 , V_256 ) ;
F_50 ( V_258 ) ;
V_143 = V_19 -> V_21 ;
F_98 ( V_19 , V_258 , 0 ) ;
F_116 ( V_19 -> V_21 , V_258 ) ;
F_11 ( V_143 ) ;
F_24 ( V_19 ) ;
F_115 ( V_258 ) ;
V_2 -> V_8 [ V_39 ] = V_258 ;
V_2 -> V_9 [ V_39 ] = V_13 ;
V_2 -> V_17 [ V_39 ] = 0 ;
return 0 ;
}
static void F_207 ( struct V_32 * V_33 ,
struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_40 * V_85 , T_2 V_263 ,
int V_80 , int V_39 )
{
struct V_14 * V_257 ;
int V_98 ;
int V_38 ;
F_72 ( ! V_2 -> V_8 [ V_39 ] ) ;
F_112 ( V_2 -> V_8 [ V_39 ] ) ;
V_257 = V_2 -> V_8 [ V_39 ] ;
V_98 = F_90 ( V_257 ) ;
F_72 ( V_80 > V_98 ) ;
F_72 ( V_98 == F_132 ( V_19 ) ) ;
if ( V_80 != V_98 ) {
if ( V_39 )
F_95 ( V_19 -> V_26 , V_257 , V_80 + 1 ,
V_80 , V_98 - V_80 ) ;
F_125 ( V_257 ,
F_124 ( V_80 + 1 ) ,
F_124 ( V_80 ) ,
( V_98 - V_80 ) * sizeof( struct V_140 ) ) ;
}
if ( V_39 ) {
V_38 = F_84 ( V_19 -> V_26 , V_257 , V_80 ,
V_84 , V_4 ) ;
F_72 ( V_38 < 0 ) ;
}
F_123 ( V_257 , V_85 , V_80 ) ;
F_118 ( V_257 , V_80 , V_263 ) ;
F_32 ( V_33 -> V_43 == 0 ) ;
F_119 ( V_257 , V_80 , V_33 -> V_43 ) ;
F_126 ( V_257 , V_98 + 1 ) ;
F_50 ( V_257 ) ;
}
static T_1 int F_182 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_39 )
{
struct V_14 * V_258 ;
struct V_14 * V_264 ;
struct V_40 V_41 ;
int V_179 ;
int V_38 ;
T_4 V_265 ;
V_258 = V_2 -> V_8 [ V_39 ] ;
F_32 ( F_48 ( V_258 ) != V_33 -> V_43 ) ;
if ( V_258 == V_19 -> V_21 ) {
V_38 = F_204 ( V_33 , V_19 , V_2 , V_39 + 1 ) ;
if ( V_38 )
return V_38 ;
} else {
V_38 = F_173 ( V_33 , V_19 , V_2 , V_39 ) ;
V_258 = V_2 -> V_8 [ V_39 ] ;
if ( ! V_38 && F_90 ( V_258 ) <
F_132 ( V_19 ) - 3 )
return 0 ;
if ( V_38 < 0 )
return V_38 ;
}
V_265 = F_90 ( V_258 ) ;
V_179 = ( V_265 + 1 ) / 2 ;
F_35 ( V_258 , & V_41 , V_179 ) ;
V_264 = F_36 ( V_33 , V_19 , 0 , V_19 -> V_124 . V_28 ,
& V_41 , V_39 , V_258 -> V_46 , 0 ) ;
if ( F_37 ( V_264 ) )
return F_38 ( V_264 ) ;
F_163 ( V_19 , V_19 -> V_146 ) ;
F_205 ( V_264 , 0 , 0 , sizeof( struct V_260 ) ) ;
F_130 ( V_264 , F_33 ( V_258 ) ) ;
F_40 ( V_264 , V_264 -> V_46 ) ;
F_41 ( V_264 , V_33 -> V_43 ) ;
F_42 ( V_264 , V_48 ) ;
F_45 ( V_264 , V_19 -> V_124 . V_28 ) ;
F_46 ( V_264 , V_19 -> V_26 -> V_52 ,
F_47 () , V_53 ) ;
F_46 ( V_264 , V_19 -> V_26 -> V_261 ,
F_206 ( V_264 ) ,
V_262 ) ;
V_38 = F_94 ( V_19 -> V_26 , V_264 , V_258 , 0 ,
V_179 , V_265 - V_179 ) ;
if ( V_38 ) {
F_113 ( V_33 , V_19 , V_38 ) ;
return V_38 ;
}
F_39 ( V_264 , V_258 ,
F_124 ( 0 ) ,
F_124 ( V_179 ) ,
( V_265 - V_179 ) * sizeof( struct V_140 ) ) ;
F_126 ( V_264 , V_265 - V_179 ) ;
F_126 ( V_258 , V_179 ) ;
V_38 = 0 ;
F_50 ( V_258 ) ;
F_50 ( V_264 ) ;
F_207 ( V_33 , V_19 , V_2 , & V_41 , V_264 -> V_46 ,
V_2 -> V_17 [ V_39 + 1 ] + 1 , V_39 + 1 ) ;
if ( V_2 -> V_17 [ V_39 ] >= V_179 ) {
V_2 -> V_17 [ V_39 ] -= V_179 ;
F_20 ( V_258 ) ;
F_11 ( V_258 ) ;
V_2 -> V_8 [ V_39 ] = V_264 ;
V_2 -> V_17 [ V_39 + 1 ] += 1 ;
} else {
F_20 ( V_264 ) ;
F_11 ( V_264 ) ;
}
return V_38 ;
}
static int F_208 ( struct V_14 * V_266 , int V_46 , int V_174 )
{
struct V_187 * V_267 ;
struct V_187 * V_268 ;
struct V_269 V_270 ;
int V_271 ;
int V_98 = F_90 ( V_266 ) ;
int V_272 = F_153 ( V_98 , V_46 + V_174 ) - 1 ;
if ( ! V_174 )
return 0 ;
F_209 ( & V_270 ) ;
V_267 = F_210 ( V_46 ) ;
V_268 = F_210 ( V_272 ) ;
V_271 = F_211 ( V_266 , V_267 , & V_270 ) +
F_212 ( V_266 , V_267 , & V_270 ) ;
V_271 = V_271 - F_211 ( V_266 , V_268 , & V_270 ) ;
V_271 += sizeof( struct V_187 ) * V_174 ;
F_32 ( V_271 < 0 ) ;
return V_271 ;
}
T_1 int F_196 ( struct V_18 * V_19 ,
struct V_14 * V_173 )
{
int V_98 = F_90 ( V_173 ) ;
int V_38 ;
V_38 = F_155 ( V_19 ) - F_208 ( V_173 , 0 , V_98 ) ;
if ( V_38 < 0 ) {
F_213 ( V_19 -> V_26 ,
L_3 ,
V_38 , ( unsigned long ) F_155 ( V_19 ) ,
F_208 ( V_173 , 0 , V_98 ) , V_98 ) ;
}
return V_38 ;
}
static T_1 int F_214 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
int V_273 , int V_251 ,
struct V_14 * V_192 ,
int V_274 , T_4 V_275 ,
T_4 V_276 )
{
struct V_14 * V_193 = V_2 -> V_8 [ 0 ] ;
struct V_14 * V_277 = V_2 -> V_8 [ 1 ] ;
struct V_269 V_270 ;
struct V_40 V_41 ;
int V_80 ;
T_4 V_6 ;
int V_278 = 0 ;
int V_252 = 0 ;
struct V_187 * V_279 ;
T_4 V_174 ;
T_4 V_280 ;
T_4 V_281 ;
T_4 V_282 ;
F_209 ( & V_270 ) ;
if ( V_251 )
V_174 = 0 ;
else
V_174 = F_215 ( T_4 , 1 , V_276 ) ;
if ( V_2 -> V_17 [ 0 ] >= V_275 )
V_278 += V_273 ;
V_80 = V_2 -> V_17 [ 1 ] ;
V_6 = V_275 - 1 ;
while ( V_6 >= V_174 ) {
V_279 = F_210 ( V_6 ) ;
if ( ! V_251 && V_252 > 0 ) {
if ( V_2 -> V_17 [ 0 ] > V_6 )
break;
if ( V_2 -> V_17 [ 0 ] == V_6 ) {
int V_283 = F_196 ( V_19 , V_193 ) ;
if ( V_283 + V_278 * 2 > V_274 )
break;
}
}
if ( V_2 -> V_17 [ 0 ] == V_6 )
V_278 += V_273 ;
V_282 = F_216 ( V_193 , V_279 ) ;
if ( V_282 + sizeof( * V_279 ) + V_278 > V_274 )
break;
V_252 ++ ;
V_278 += V_282 + sizeof( * V_279 ) ;
if ( V_6 == 0 )
break;
V_6 -- ;
}
if ( V_252 == 0 )
goto V_284;
F_32 ( ! V_251 && V_252 == V_275 ) ;
V_280 = F_90 ( V_192 ) ;
V_278 = F_217 ( V_193 , V_275 - V_252 ) ;
V_278 -= F_154 ( V_19 , V_193 ) ;
V_281 = F_154 ( V_19 , V_192 ) ;
F_125 ( V_192 ,
F_218 ( V_192 ) + V_281 - V_278 ,
F_218 ( V_192 ) + V_281 ,
F_155 ( V_19 ) - V_281 ) ;
F_39 ( V_192 , V_193 , F_218 ( V_192 ) +
F_155 ( V_19 ) - V_278 ,
F_218 ( V_193 ) + F_154 ( V_19 , V_193 ) ,
V_278 ) ;
F_125 ( V_192 , F_219 ( V_252 ) ,
F_219 ( 0 ) ,
V_280 * sizeof( struct V_187 ) ) ;
F_39 ( V_192 , V_193 , F_219 ( 0 ) ,
F_219 ( V_275 - V_252 ) ,
V_252 * sizeof( struct V_187 ) ) ;
V_280 += V_252 ;
F_126 ( V_192 , V_280 ) ;
V_278 = F_155 ( V_19 ) ;
for ( V_6 = 0 ; V_6 < V_280 ; V_6 ++ ) {
V_279 = F_210 ( V_6 ) ;
V_278 -= F_212 ( V_192 , V_279 , & V_270 ) ;
F_220 ( V_192 , V_279 , V_278 , & V_270 ) ;
}
V_275 -= V_252 ;
F_126 ( V_193 , V_275 ) ;
if ( V_275 )
F_50 ( V_193 ) ;
else
F_110 ( V_33 , V_19 -> V_26 , V_193 ) ;
F_50 ( V_192 ) ;
F_34 ( V_192 , & V_41 , 0 ) ;
F_123 ( V_277 , & V_41 , V_80 + 1 ) ;
F_50 ( V_277 ) ;
if ( V_2 -> V_17 [ 0 ] >= V_275 ) {
V_2 -> V_17 [ 0 ] -= V_275 ;
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
V_284:
F_20 ( V_192 ) ;
F_11 ( V_192 ) ;
return 1 ;
}
static int F_221 ( struct V_32 * V_33 , struct V_18
* V_19 , struct V_1 * V_2 ,
int V_285 , int V_273 ,
int V_251 , T_4 V_276 )
{
struct V_14 * V_193 = V_2 -> V_8 [ 0 ] ;
struct V_14 * V_192 ;
struct V_14 * V_277 ;
int V_80 ;
int V_274 ;
T_4 V_275 ;
int V_38 ;
if ( ! V_2 -> V_8 [ 1 ] )
return 1 ;
V_80 = V_2 -> V_17 [ 1 ] ;
V_277 = V_2 -> V_8 [ 1 ] ;
if ( V_80 >= F_90 ( V_277 ) - 1 )
return 1 ;
F_112 ( V_2 -> V_8 [ 1 ] ) ;
V_192 = F_168 ( V_19 , V_277 , V_80 + 1 ) ;
if ( V_192 == NULL )
return 1 ;
F_19 ( V_192 ) ;
F_143 ( V_192 ) ;
V_274 = F_196 ( V_19 , V_192 ) ;
if ( V_274 < V_273 )
goto V_284;
V_38 = F_141 ( V_33 , V_19 , V_192 , V_277 ,
V_80 + 1 , & V_192 ) ;
if ( V_38 )
goto V_284;
V_274 = F_196 ( V_19 , V_192 ) ;
if ( V_274 < V_273 )
goto V_284;
V_275 = F_90 ( V_193 ) ;
if ( V_275 == 0 )
goto V_284;
if ( V_2 -> V_17 [ 0 ] == V_275 && ! V_251 ) {
F_20 ( V_193 ) ;
F_11 ( V_193 ) ;
V_2 -> V_8 [ 0 ] = V_192 ;
V_2 -> V_17 [ 0 ] = 0 ;
V_2 -> V_17 [ 1 ] ++ ;
return 0 ;
}
return F_214 ( V_33 , V_19 , V_2 , V_285 , V_251 ,
V_192 , V_274 , V_275 , V_276 ) ;
V_284:
F_20 ( V_192 ) ;
F_11 ( V_192 ) ;
return 1 ;
}
static T_1 int F_222 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_273 ,
int V_251 , struct V_14 * V_193 ,
int V_274 , T_4 V_280 ,
T_4 V_286 )
{
struct V_40 V_41 ;
struct V_14 * V_192 = V_2 -> V_8 [ 0 ] ;
int V_6 ;
int V_278 = 0 ;
int V_252 = 0 ;
struct V_187 * V_279 ;
T_4 V_287 ;
T_4 V_174 ;
int V_38 = 0 ;
T_4 V_282 ;
T_4 V_288 ;
struct V_269 V_270 ;
F_209 ( & V_270 ) ;
if ( V_251 )
V_174 = F_153 ( V_280 , V_286 ) ;
else
V_174 = F_153 ( V_280 - 1 , V_286 ) ;
for ( V_6 = 0 ; V_6 < V_174 ; V_6 ++ ) {
V_279 = F_210 ( V_6 ) ;
if ( ! V_251 && V_252 > 0 ) {
if ( V_2 -> V_17 [ 0 ] < V_6 )
break;
if ( V_2 -> V_17 [ 0 ] == V_6 ) {
int V_283 = F_196 ( V_19 , V_192 ) ;
if ( V_283 + V_278 * 2 > V_274 )
break;
}
}
if ( V_2 -> V_17 [ 0 ] == V_6 )
V_278 += V_273 ;
V_282 = F_216 ( V_192 , V_279 ) ;
if ( V_282 + sizeof( * V_279 ) + V_278 > V_274 )
break;
V_252 ++ ;
V_278 += V_282 + sizeof( * V_279 ) ;
}
if ( V_252 == 0 ) {
V_38 = 1 ;
goto V_289;
}
F_32 ( ! V_251 && V_252 == F_90 ( V_192 ) ) ;
F_39 ( V_193 , V_192 ,
F_219 ( F_90 ( V_193 ) ) ,
F_219 ( 0 ) ,
V_252 * sizeof( struct V_187 ) ) ;
V_278 = F_155 ( V_19 ) -
F_156 ( V_192 , V_252 - 1 ) ;
F_39 ( V_193 , V_192 , F_218 ( V_193 ) +
F_154 ( V_19 , V_193 ) - V_278 ,
F_218 ( V_192 ) +
F_156 ( V_192 , V_252 - 1 ) ,
V_278 ) ;
V_287 = F_90 ( V_193 ) ;
F_72 ( V_287 <= 0 ) ;
V_288 = F_156 ( V_193 , V_287 - 1 ) ;
for ( V_6 = V_287 ; V_6 < V_287 + V_252 ; V_6 ++ ) {
T_4 V_233 ;
V_279 = F_210 ( V_6 ) ;
V_233 = F_211 ( V_193 , V_279 , & V_270 ) ;
F_220 ( V_193 , V_279 ,
V_233 - ( F_155 ( V_19 ) - V_288 ) ,
& V_270 ) ;
}
F_126 ( V_193 , V_287 + V_252 ) ;
if ( V_252 > V_280 )
F_142 ( 1 , V_149 L_4 , V_252 ,
V_280 ) ;
if ( V_252 < V_280 ) {
V_278 = F_156 ( V_192 , V_252 - 1 ) -
F_154 ( V_19 , V_192 ) ;
F_125 ( V_192 , F_218 ( V_192 ) +
F_155 ( V_19 ) - V_278 ,
F_218 ( V_192 ) +
F_154 ( V_19 , V_192 ) , V_278 ) ;
F_125 ( V_192 , F_219 ( 0 ) ,
F_219 ( V_252 ) ,
( F_90 ( V_192 ) - V_252 ) *
sizeof( struct V_187 ) ) ;
}
V_280 -= V_252 ;
F_126 ( V_192 , V_280 ) ;
V_278 = F_155 ( V_19 ) ;
for ( V_6 = 0 ; V_6 < V_280 ; V_6 ++ ) {
V_279 = F_210 ( V_6 ) ;
V_278 = V_278 - F_212 ( V_192 ,
V_279 , & V_270 ) ;
F_220 ( V_192 , V_279 , V_278 , & V_270 ) ;
}
F_50 ( V_193 ) ;
if ( V_280 )
F_50 ( V_192 ) ;
else
F_110 ( V_33 , V_19 -> V_26 , V_192 ) ;
F_34 ( V_192 , & V_41 , 0 ) ;
F_201 ( V_19 -> V_26 , V_2 , & V_41 , 1 ) ;
if ( V_2 -> V_17 [ 0 ] < V_252 ) {
V_2 -> V_17 [ 0 ] += V_287 ;
F_20 ( V_2 -> V_8 [ 0 ] ) ;
F_11 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_193 ;
V_2 -> V_17 [ 1 ] -= 1 ;
} else {
F_20 ( V_193 ) ;
F_11 ( V_193 ) ;
V_2 -> V_17 [ 0 ] -= V_252 ;
}
F_72 ( V_2 -> V_17 [ 0 ] < 0 ) ;
return V_38 ;
V_289:
F_20 ( V_193 ) ;
F_11 ( V_193 ) ;
return V_38 ;
}
static int F_223 ( struct V_32 * V_33 , struct V_18
* V_19 , struct V_1 * V_2 , int V_285 ,
int V_273 , int V_251 , T_4 V_286 )
{
struct V_14 * V_192 = V_2 -> V_8 [ 0 ] ;
struct V_14 * V_193 ;
int V_80 ;
int V_274 ;
T_4 V_280 ;
int V_38 = 0 ;
V_80 = V_2 -> V_17 [ 1 ] ;
if ( V_80 == 0 )
return 1 ;
if ( ! V_2 -> V_8 [ 1 ] )
return 1 ;
V_280 = F_90 ( V_192 ) ;
if ( V_280 == 0 )
return 1 ;
F_112 ( V_2 -> V_8 [ 1 ] ) ;
V_193 = F_168 ( V_19 , V_2 -> V_8 [ 1 ] , V_80 - 1 ) ;
if ( V_193 == NULL )
return 1 ;
F_19 ( V_193 ) ;
F_143 ( V_193 ) ;
V_274 = F_196 ( V_19 , V_193 ) ;
if ( V_274 < V_273 ) {
V_38 = 1 ;
goto V_289;
}
V_38 = F_141 ( V_33 , V_19 , V_193 ,
V_2 -> V_8 [ 1 ] , V_80 - 1 , & V_193 ) ;
if ( V_38 ) {
if ( V_38 == - V_200 )
V_38 = 1 ;
goto V_289;
}
V_274 = F_196 ( V_19 , V_193 ) ;
if ( V_274 < V_273 ) {
V_38 = 1 ;
goto V_289;
}
return F_222 ( V_33 , V_19 , V_2 , V_285 ,
V_251 , V_193 , V_274 , V_280 ,
V_286 ) ;
V_289:
F_20 ( V_193 ) ;
F_11 ( V_193 ) ;
return V_38 ;
}
static T_1 void F_224 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_14 * V_266 ,
struct V_14 * V_192 ,
int V_80 , int V_179 , int V_98 )
{
int V_290 ;
int V_291 ;
int V_6 ;
struct V_40 V_41 ;
struct V_269 V_270 ;
F_209 ( & V_270 ) ;
V_98 = V_98 - V_179 ;
F_126 ( V_192 , V_98 ) ;
V_290 = F_217 ( V_266 , V_179 ) - F_154 ( V_19 , V_266 ) ;
F_39 ( V_192 , V_266 , F_219 ( 0 ) ,
F_219 ( V_179 ) ,
V_98 * sizeof( struct V_187 ) ) ;
F_39 ( V_192 , V_266 ,
F_218 ( V_192 ) + F_155 ( V_19 ) -
V_290 , F_218 ( V_266 ) +
F_154 ( V_19 , V_266 ) , V_290 ) ;
V_291 = F_155 ( V_19 ) -
F_217 ( V_266 , V_179 ) ;
for ( V_6 = 0 ; V_6 < V_98 ; V_6 ++ ) {
struct V_187 * V_279 = F_210 ( V_6 ) ;
T_4 V_233 ;
V_233 = F_211 ( V_192 , V_279 , & V_270 ) ;
F_220 ( V_192 , V_279 ,
V_233 + V_291 , & V_270 ) ;
}
F_126 ( V_266 , V_179 ) ;
F_34 ( V_192 , & V_41 , 0 ) ;
F_207 ( V_33 , V_19 , V_2 , & V_41 , V_192 -> V_46 ,
V_2 -> V_17 [ 1 ] + 1 , 1 ) ;
F_50 ( V_192 ) ;
F_50 ( V_266 ) ;
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
int V_273 )
{
int V_38 ;
int V_162 = 0 ;
int V_80 ;
T_4 V_98 ;
int V_292 = V_273 ;
V_80 = V_2 -> V_17 [ 0 ] ;
if ( V_80 < F_90 ( V_2 -> V_8 [ 0 ] ) )
V_292 -= F_196 ( V_19 , V_2 -> V_8 [ 0 ] ) ;
V_38 = F_221 ( V_33 , V_19 , V_2 , 1 , V_292 , 0 , V_80 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_38 == 0 )
V_162 ++ ;
V_98 = F_90 ( V_2 -> V_8 [ 0 ] ) ;
if ( V_2 -> V_17 [ 0 ] == 0 || V_2 -> V_17 [ 0 ] == V_98 )
return 0 ;
if ( F_196 ( V_19 , V_2 -> V_8 [ 0 ] ) >= V_273 )
return 0 ;
V_80 = V_2 -> V_17 [ 0 ] ;
V_38 = F_223 ( V_33 , V_19 , V_2 , 1 , V_292 , 0 , V_80 ) ;
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
struct V_156 * V_293 ,
struct V_1 * V_2 , int V_273 ,
int V_294 )
{
struct V_40 V_41 ;
struct V_14 * V_266 ;
T_4 V_98 ;
int V_179 ;
int V_80 ;
struct V_14 * V_192 ;
struct V_54 * V_26 = V_19 -> V_26 ;
int V_38 = 0 ;
int V_194 ;
int V_264 ;
int V_295 = 0 ;
int V_296 = 0 ;
V_266 = V_2 -> V_8 [ 0 ] ;
V_80 = V_2 -> V_17 [ 0 ] ;
if ( V_294 && V_273 + F_226 ( V_266 , V_80 ) +
sizeof( struct V_187 ) > F_155 ( V_19 ) )
return - V_297 ;
if ( V_273 && V_2 -> V_8 [ 1 ] ) {
int V_292 = V_273 ;
if ( V_80 < F_90 ( V_266 ) )
V_292 -= F_196 ( V_19 , V_266 ) ;
V_194 = F_221 ( V_33 , V_19 , V_2 , V_292 ,
V_292 , 0 , 0 ) ;
if ( V_194 < 0 )
return V_194 ;
if ( V_194 ) {
V_194 = F_223 ( V_33 , V_19 , V_2 , V_292 ,
V_292 , 0 , ( T_4 ) - 1 ) ;
if ( V_194 < 0 )
return V_194 ;
}
V_266 = V_2 -> V_8 [ 0 ] ;
if ( F_196 ( V_19 , V_266 ) >= V_273 )
return 0 ;
}
if ( ! V_2 -> V_8 [ 1 ] ) {
V_38 = F_204 ( V_33 , V_19 , V_2 , 1 ) ;
if ( V_38 )
return V_38 ;
}
V_228:
V_264 = 1 ;
V_266 = V_2 -> V_8 [ 0 ] ;
V_80 = V_2 -> V_17 [ 0 ] ;
V_98 = F_90 ( V_266 ) ;
V_179 = ( V_98 + 1 ) / 2 ;
if ( V_179 <= V_80 ) {
if ( V_98 == 1 ||
F_208 ( V_266 , V_179 , V_98 - V_179 ) + V_273 >
F_155 ( V_19 ) ) {
if ( V_80 >= V_98 ) {
V_264 = 0 ;
} else {
V_179 = V_80 ;
if ( V_179 != V_98 &&
F_208 ( V_266 , V_179 , V_98 - V_179 ) +
V_273 > F_155 ( V_19 ) ) {
if ( V_273 && ! V_296 )
goto V_298;
V_264 = 2 ;
}
}
}
} else {
if ( F_208 ( V_266 , 0 , V_179 ) + V_273 >
F_155 ( V_19 ) ) {
if ( ! V_294 && V_273 && V_80 == 0 ) {
V_264 = 0 ;
} else if ( ( V_294 || ! V_273 ) && V_80 == 0 ) {
V_179 = 1 ;
} else {
V_179 = V_80 ;
if ( V_179 != V_98 &&
F_208 ( V_266 , V_179 , V_98 - V_179 ) +
V_273 > F_155 ( V_19 ) ) {
if ( V_273 && ! V_296 )
goto V_298;
V_264 = 2 ;
}
}
}
}
if ( V_264 == 0 )
F_185 ( & V_41 , V_293 ) ;
else
F_34 ( V_266 , & V_41 , V_179 ) ;
V_192 = F_36 ( V_33 , V_19 , 0 , V_19 -> V_124 . V_28 ,
& V_41 , 0 , V_266 -> V_46 , 0 ) ;
if ( F_37 ( V_192 ) )
return F_38 ( V_192 ) ;
F_163 ( V_19 , V_19 -> V_146 ) ;
F_205 ( V_192 , 0 , 0 , sizeof( struct V_260 ) ) ;
F_40 ( V_192 , V_192 -> V_46 ) ;
F_41 ( V_192 , V_33 -> V_43 ) ;
F_42 ( V_192 , V_48 ) ;
F_45 ( V_192 , V_19 -> V_124 . V_28 ) ;
F_130 ( V_192 , 0 ) ;
F_46 ( V_192 , V_26 -> V_52 ,
F_47 () , V_53 ) ;
F_46 ( V_192 , V_26 -> V_261 ,
F_206 ( V_192 ) ,
V_262 ) ;
if ( V_264 == 0 ) {
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
F_224 ( V_33 , V_19 , V_2 , V_266 , V_192 , V_80 , V_179 , V_98 ) ;
if ( V_264 == 2 ) {
F_72 ( V_295 != 0 ) ;
V_295 ++ ;
goto V_228;
}
return 0 ;
V_298:
F_225 ( V_33 , V_19 , V_2 , V_273 ) ;
V_296 = 1 ;
if ( F_196 ( V_19 , V_2 -> V_8 [ 0 ] ) >= V_273 )
return 0 ;
goto V_228;
}
static T_1 int F_227 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_225 )
{
struct V_156 V_85 ;
struct V_14 * V_173 ;
struct V_299 * V_300 ;
T_2 V_301 = 0 ;
T_4 V_175 ;
int V_38 ;
V_173 = V_2 -> V_8 [ 0 ] ;
F_191 ( V_173 , & V_85 , V_2 -> V_17 [ 0 ] ) ;
F_72 ( V_85 . type != V_302 &&
V_85 . type != V_303 ) ;
if ( F_196 ( V_19 , V_173 ) >= V_225 )
return 0 ;
V_175 = F_226 ( V_173 , V_2 -> V_17 [ 0 ] ) ;
if ( V_85 . type == V_302 ) {
V_300 = F_228 ( V_173 , V_2 -> V_17 [ 0 ] ,
struct V_299 ) ;
V_301 = F_229 ( V_173 , V_300 ) ;
}
F_8 ( V_2 ) ;
V_2 -> V_220 = 1 ;
V_2 -> V_226 = 1 ;
V_38 = F_189 ( V_33 , V_19 , & V_85 , V_2 , 0 , 1 ) ;
V_2 -> V_226 = 0 ;
if ( V_38 > 0 )
V_38 = - V_224 ;
if ( V_38 < 0 )
goto V_167;
V_38 = - V_224 ;
V_173 = V_2 -> V_8 [ 0 ] ;
if ( V_175 != F_226 ( V_173 , V_2 -> V_17 [ 0 ] ) )
goto V_167;
if ( F_196 ( V_19 , V_2 -> V_8 [ 0 ] ) >= V_225 )
goto V_167;
if ( V_85 . type == V_302 ) {
V_300 = F_228 ( V_173 , V_2 -> V_17 [ 0 ] ,
struct V_299 ) ;
if ( V_301 != F_229 ( V_173 , V_300 ) )
goto V_167;
}
F_3 ( V_2 ) ;
V_38 = F_197 ( V_33 , V_19 , & V_85 , V_2 , V_225 , 1 ) ;
if ( V_38 )
goto V_167;
V_2 -> V_220 = 0 ;
F_179 ( V_2 , 1 ) ;
return 0 ;
V_167:
V_2 -> V_220 = 0 ;
return V_38 ;
}
static T_1 int F_230 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_156 * V_250 ,
unsigned long V_304 )
{
struct V_14 * V_173 ;
struct V_187 * V_279 ;
struct V_187 * V_305 ;
int V_80 ;
char * V_34 ;
T_4 V_98 ;
T_4 V_175 ;
T_4 V_306 ;
struct V_40 V_41 ;
V_173 = V_2 -> V_8 [ 0 ] ;
F_72 ( F_196 ( V_19 , V_173 ) < sizeof( struct V_187 ) ) ;
F_3 ( V_2 ) ;
V_279 = F_210 ( V_2 -> V_17 [ 0 ] ) ;
V_306 = F_231 ( V_173 , V_279 ) ;
V_175 = F_216 ( V_173 , V_279 ) ;
V_34 = F_232 ( V_175 , V_4 ) ;
if ( ! V_34 )
return - V_88 ;
F_159 ( V_173 , V_34 , F_233 ( V_173 ,
V_2 -> V_17 [ 0 ] ) , V_175 ) ;
V_80 = V_2 -> V_17 [ 0 ] + 1 ;
V_98 = F_90 ( V_173 ) ;
if ( V_80 != V_98 ) {
F_125 ( V_173 , F_219 ( V_80 + 1 ) ,
F_219 ( V_80 ) ,
( V_98 - V_80 ) * sizeof( struct V_187 ) ) ;
}
F_185 ( & V_41 , V_250 ) ;
F_203 ( V_173 , & V_41 , V_80 ) ;
V_305 = F_210 ( V_80 ) ;
F_234 ( V_173 , V_305 , V_306 ) ;
F_235 ( V_173 , V_305 , V_175 - V_304 ) ;
F_234 ( V_173 , V_279 ,
V_306 + V_175 - V_304 ) ;
F_235 ( V_173 , V_279 , V_304 ) ;
F_126 ( V_173 , V_98 + 1 ) ;
F_46 ( V_173 , V_34 ,
F_233 ( V_173 , V_2 -> V_17 [ 0 ] ) ,
V_304 ) ;
F_46 ( V_173 , V_34 + V_304 ,
F_233 ( V_173 , V_80 ) ,
V_175 - V_304 ) ;
F_50 ( V_173 ) ;
F_72 ( F_196 ( V_19 , V_173 ) < 0 ) ;
F_70 ( V_34 ) ;
return 0 ;
}
int F_236 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_156 * V_250 ,
unsigned long V_304 )
{
int V_38 ;
V_38 = F_227 ( V_33 , V_19 , V_2 ,
sizeof( struct V_187 ) ) ;
if ( V_38 )
return V_38 ;
V_38 = F_230 ( V_33 , V_19 , V_2 , V_250 , V_304 ) ;
return V_38 ;
}
int F_237 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_156 * V_250 )
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
F_238 ( V_19 , V_2 , V_250 , & V_175 ,
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
T_4 V_307 , int V_308 )
{
int V_80 ;
struct V_14 * V_173 ;
struct V_187 * V_279 ;
T_4 V_98 ;
unsigned int V_281 ;
unsigned int V_309 ;
unsigned int V_310 ;
unsigned int V_311 ;
int V_6 ;
struct V_269 V_270 ;
F_209 ( & V_270 ) ;
V_173 = V_2 -> V_8 [ 0 ] ;
V_80 = V_2 -> V_17 [ 0 ] ;
V_310 = F_226 ( V_173 , V_80 ) ;
if ( V_310 == V_307 )
return;
V_98 = F_90 ( V_173 ) ;
V_281 = F_154 ( V_19 , V_173 ) ;
V_309 = F_156 ( V_173 , V_80 ) ;
V_311 = V_310 - V_307 ;
F_72 ( V_80 < 0 ) ;
F_72 ( V_80 >= V_98 ) ;
for ( V_6 = V_80 ; V_6 < V_98 ; V_6 ++ ) {
T_4 V_233 ;
V_279 = F_210 ( V_6 ) ;
V_233 = F_211 ( V_173 , V_279 , & V_270 ) ;
F_220 ( V_173 , V_279 ,
V_233 + V_311 , & V_270 ) ;
}
if ( V_308 ) {
F_125 ( V_173 , F_218 ( V_173 ) +
V_281 + V_311 , F_218 ( V_173 ) +
V_281 , V_309 + V_307 - V_281 ) ;
} else {
struct V_40 V_41 ;
T_2 V_159 ;
F_34 ( V_173 , & V_41 , V_80 ) ;
if ( F_241 ( & V_41 ) == V_302 ) {
unsigned long V_312 ;
struct V_299 * V_300 ;
V_300 = F_228 ( V_173 , V_80 ,
struct V_299 ) ;
V_300 = (struct V_299 * ) (
( unsigned long ) V_300 - V_311 ) ;
if ( F_242 ( V_173 , V_300 ) ==
V_313 ) {
V_312 = F_233 ( V_173 , V_80 ) ;
F_125 ( V_173 , V_312 ,
( unsigned long ) V_300 ,
V_314 ) ;
}
}
F_125 ( V_173 , F_218 ( V_173 ) +
V_281 + V_311 , F_218 ( V_173 ) +
V_281 , V_309 - V_281 ) ;
V_159 = F_243 ( & V_41 ) ;
F_244 ( & V_41 , V_159 + V_311 ) ;
F_203 ( V_173 , & V_41 , V_80 ) ;
if ( V_80 == 0 )
F_201 ( V_19 -> V_26 , V_2 , & V_41 , 1 ) ;
}
V_279 = F_210 ( V_80 ) ;
F_235 ( V_173 , V_279 , V_307 ) ;
F_50 ( V_173 ) ;
if ( F_196 ( V_19 , V_173 ) < 0 ) {
F_245 ( V_19 , V_173 ) ;
F_172 () ;
}
}
void F_246 ( struct V_18 * V_19 , struct V_1 * V_2 ,
T_4 V_273 )
{
int V_80 ;
struct V_14 * V_173 ;
struct V_187 * V_279 ;
T_4 V_98 ;
unsigned int V_281 ;
unsigned int V_315 ;
unsigned int V_310 ;
int V_6 ;
struct V_269 V_270 ;
F_209 ( & V_270 ) ;
V_173 = V_2 -> V_8 [ 0 ] ;
V_98 = F_90 ( V_173 ) ;
V_281 = F_154 ( V_19 , V_173 ) ;
if ( F_196 ( V_19 , V_173 ) < V_273 ) {
F_245 ( V_19 , V_173 ) ;
F_172 () ;
}
V_80 = V_2 -> V_17 [ 0 ] ;
V_315 = F_217 ( V_173 , V_80 ) ;
F_72 ( V_80 < 0 ) ;
if ( V_80 >= V_98 ) {
F_245 ( V_19 , V_173 ) ;
F_213 ( V_19 -> V_26 , L_5 ,
V_80 , V_98 ) ;
F_72 ( 1 ) ;
}
for ( V_6 = V_80 ; V_6 < V_98 ; V_6 ++ ) {
T_4 V_233 ;
V_279 = F_210 ( V_6 ) ;
V_233 = F_211 ( V_173 , V_279 , & V_270 ) ;
F_220 ( V_173 , V_279 ,
V_233 - V_273 , & V_270 ) ;
}
F_125 ( V_173 , F_218 ( V_173 ) +
V_281 - V_273 , F_218 ( V_173 ) +
V_281 , V_315 - V_281 ) ;
V_281 = V_315 ;
V_310 = F_226 ( V_173 , V_80 ) ;
V_279 = F_210 ( V_80 ) ;
F_235 ( V_173 , V_279 , V_310 + V_273 ) ;
F_50 ( V_173 ) ;
if ( F_196 ( V_19 , V_173 ) < 0 ) {
F_245 ( V_19 , V_173 ) ;
F_172 () ;
}
}
void F_238 ( struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_156 * V_316 , T_4 * V_273 ,
T_4 V_317 , T_4 V_318 , int V_174 )
{
struct V_187 * V_279 ;
int V_6 ;
T_4 V_98 ;
unsigned int V_281 ;
struct V_40 V_41 ;
struct V_14 * V_173 ;
int V_80 ;
struct V_269 V_270 ;
if ( V_2 -> V_17 [ 0 ] == 0 ) {
F_185 ( & V_41 , V_316 ) ;
F_201 ( V_19 -> V_26 , V_2 , & V_41 , 1 ) ;
}
F_179 ( V_2 , 1 ) ;
F_209 ( & V_270 ) ;
V_173 = V_2 -> V_8 [ 0 ] ;
V_80 = V_2 -> V_17 [ 0 ] ;
V_98 = F_90 ( V_173 ) ;
V_281 = F_154 ( V_19 , V_173 ) ;
if ( F_196 ( V_19 , V_173 ) < V_318 ) {
F_245 ( V_19 , V_173 ) ;
F_213 ( V_19 -> V_26 , L_6 ,
V_318 , F_196 ( V_19 , V_173 ) ) ;
F_172 () ;
}
if ( V_80 != V_98 ) {
unsigned int V_315 = F_217 ( V_173 , V_80 ) ;
if ( V_315 < V_281 ) {
F_245 ( V_19 , V_173 ) ;
F_213 ( V_19 -> V_26 , L_7 ,
V_80 , V_315 , V_281 ) ;
F_72 ( 1 ) ;
}
for ( V_6 = V_80 ; V_6 < V_98 ; V_6 ++ ) {
T_4 V_233 ;
V_279 = F_210 ( V_6 ) ;
V_233 = F_211 ( V_173 , V_279 , & V_270 ) ;
F_220 ( V_173 , V_279 ,
V_233 - V_317 , & V_270 ) ;
}
F_125 ( V_173 , F_219 ( V_80 + V_174 ) ,
F_219 ( V_80 ) ,
( V_98 - V_80 ) * sizeof( struct V_187 ) ) ;
F_125 ( V_173 , F_218 ( V_173 ) +
V_281 - V_317 , F_218 ( V_173 ) +
V_281 , V_315 - V_281 ) ;
V_281 = V_315 ;
}
for ( V_6 = 0 ; V_6 < V_174 ; V_6 ++ ) {
F_185 ( & V_41 , V_316 + V_6 ) ;
F_203 ( V_173 , & V_41 , V_80 + V_6 ) ;
V_279 = F_210 ( V_80 + V_6 ) ;
F_220 ( V_173 , V_279 ,
V_281 - V_273 [ V_6 ] , & V_270 ) ;
V_281 -= V_273 [ V_6 ] ;
F_247 ( V_173 , V_279 , V_273 [ V_6 ] , & V_270 ) ;
}
F_126 ( V_173 , V_98 + V_174 ) ;
F_50 ( V_173 ) ;
if ( F_196 ( V_19 , V_173 ) < 0 ) {
F_245 ( V_19 , V_173 ) ;
F_172 () ;
}
}
int F_248 ( struct V_32 * V_33 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_156 * V_316 , T_4 * V_273 ,
int V_174 )
{
int V_38 = 0 ;
int V_80 ;
int V_6 ;
T_4 V_318 = 0 ;
T_4 V_317 = 0 ;
for ( V_6 = 0 ; V_6 < V_174 ; V_6 ++ )
V_317 += V_273 [ V_6 ] ;
V_318 = V_317 + ( V_174 * sizeof( struct V_187 ) ) ;
V_38 = F_189 ( V_33 , V_19 , V_316 , V_2 , V_318 , 1 ) ;
if ( V_38 == 0 )
return - V_79 ;
if ( V_38 < 0 )
return V_38 ;
V_80 = V_2 -> V_17 [ 0 ] ;
F_72 ( V_80 < 0 ) ;
F_238 ( V_19 , V_2 , V_316 , V_273 ,
V_317 , V_318 , V_174 ) ;
return 0 ;
}
int F_249 ( struct V_32 * V_33 , struct V_18
* V_19 , struct V_156 * V_316 , void * V_319 , T_4
V_273 )
{
int V_38 = 0 ;
struct V_1 * V_2 ;
struct V_14 * V_173 ;
unsigned long V_312 ;
V_2 = F_1 () ;
if ( ! V_2 )
return - V_88 ;
V_38 = F_250 ( V_33 , V_19 , V_2 , V_316 , V_273 ) ;
if ( ! V_38 ) {
V_173 = V_2 -> V_8 [ 0 ] ;
V_312 = F_233 ( V_173 , V_2 -> V_17 [ 0 ] ) ;
F_46 ( V_173 , V_319 , V_312 , V_273 ) ;
F_50 ( V_173 ) ;
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
struct V_187 * V_279 ;
T_4 V_320 ;
T_4 V_321 = 0 ;
int V_38 = 0 ;
int V_194 ;
int V_6 ;
T_4 V_98 ;
struct V_269 V_270 ;
F_209 ( & V_270 ) ;
V_173 = V_2 -> V_8 [ 0 ] ;
V_320 = F_156 ( V_173 , V_80 + V_174 - 1 ) ;
for ( V_6 = 0 ; V_6 < V_174 ; V_6 ++ )
V_321 += F_226 ( V_173 , V_80 + V_6 ) ;
V_98 = F_90 ( V_173 ) ;
if ( V_80 + V_174 != V_98 ) {
int V_281 = F_154 ( V_19 , V_173 ) ;
F_125 ( V_173 , F_218 ( V_173 ) +
V_281 + V_321 ,
F_218 ( V_173 ) + V_281 ,
V_320 - V_281 ) ;
for ( V_6 = V_80 + V_174 ; V_6 < V_98 ; V_6 ++ ) {
T_4 V_233 ;
V_279 = F_210 ( V_6 ) ;
V_233 = F_211 ( V_173 , V_279 , & V_270 ) ;
F_220 ( V_173 , V_279 ,
V_233 + V_321 , & V_270 ) ;
}
F_125 ( V_173 , F_219 ( V_80 ) ,
F_219 ( V_80 + V_174 ) ,
sizeof( struct V_187 ) *
( V_98 - V_80 - V_174 ) ) ;
}
F_126 ( V_173 , V_98 - V_174 ) ;
V_98 -= V_174 ;
if ( V_98 == 0 ) {
if ( V_173 == V_19 -> V_21 ) {
F_130 ( V_173 , 0 ) ;
} else {
F_3 ( V_2 ) ;
F_110 ( V_33 , V_19 -> V_26 , V_173 ) ;
F_251 ( V_33 , V_19 , V_2 , V_173 ) ;
}
} else {
int V_322 = F_208 ( V_173 , 0 , V_98 ) ;
if ( V_80 == 0 ) {
struct V_40 V_41 ;
F_34 ( V_173 , & V_41 , 0 ) ;
F_201 ( V_19 -> V_26 , V_2 , & V_41 , 1 ) ;
}
if ( V_322 < F_155 ( V_19 ) / 3 ) {
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
struct V_156 V_85 ;
struct V_40 V_235 ;
int V_38 ;
F_191 ( V_2 -> V_8 [ 0 ] , & V_85 , 0 ) ;
if ( V_85 . V_159 > 0 ) {
V_85 . V_159 -- ;
} else if ( V_85 . type > 0 ) {
V_85 . type -- ;
V_85 . V_159 = ( T_2 ) - 1 ;
} else if ( V_85 . V_28 > 0 ) {
V_85 . V_28 -- ;
V_85 . type = ( T_5 ) - 1 ;
V_85 . V_159 = ( T_2 ) - 1 ;
} else {
return 1 ;
}
F_8 ( V_2 ) ;
V_38 = F_189 ( NULL , V_19 , & V_85 , V_2 , 0 , 0 ) ;
if ( V_38 < 0 )
return V_38 ;
F_34 ( V_2 -> V_8 [ 0 ] , & V_235 , 0 ) ;
V_38 = F_146 ( & V_235 , & V_85 ) ;
if ( V_38 <= 0 )
return 0 ;
return 1 ;
}
int F_253 ( struct V_18 * V_19 , struct V_156 * V_323 ,
struct V_1 * V_2 ,
T_2 V_324 )
{
struct V_14 * V_75 ;
struct V_156 V_235 ;
int V_80 ;
int V_227 ;
T_4 V_98 ;
int V_39 ;
int V_38 = 1 ;
int V_220 = V_2 -> V_220 ;
V_2 -> V_220 = 1 ;
V_228:
V_75 = F_21 ( V_19 ) ;
V_39 = F_33 ( V_75 ) ;
F_32 ( V_2 -> V_8 [ V_39 ] ) ;
V_2 -> V_8 [ V_39 ] = V_75 ;
V_2 -> V_9 [ V_39 ] = V_10 ;
if ( F_48 ( V_75 ) < V_324 ) {
V_38 = 1 ;
goto V_289;
}
while ( 1 ) {
V_98 = F_90 ( V_75 ) ;
V_39 = F_33 ( V_75 ) ;
V_227 = F_160 ( V_75 , V_323 , V_39 , & V_80 ) ;
if ( V_39 == V_2 -> V_237 ) {
if ( V_80 >= V_98 )
goto V_325;
V_38 = 0 ;
V_2 -> V_17 [ V_39 ] = V_80 ;
F_191 ( V_75 , & V_235 , V_80 ) ;
goto V_289;
}
if ( V_227 && V_80 > 0 )
V_80 -- ;
while ( V_80 < V_98 ) {
T_2 V_163 ;
V_163 = F_82 ( V_75 , V_80 ) ;
if ( V_163 < V_324 ) {
V_80 ++ ;
continue;
}
break;
}
V_325:
if ( V_80 >= V_98 ) {
V_2 -> V_17 [ V_39 ] = V_80 ;
F_3 ( V_2 ) ;
V_227 = F_254 ( V_19 , V_2 , V_323 , V_39 ,
V_324 ) ;
if ( V_227 == 0 ) {
F_8 ( V_2 ) ;
goto V_228;
} else {
goto V_289;
}
}
F_255 ( V_75 , & V_235 , V_80 ) ;
V_2 -> V_17 [ V_39 ] = V_80 ;
if ( V_39 == V_2 -> V_237 ) {
V_38 = 0 ;
goto V_289;
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
V_289:
V_2 -> V_220 = V_220 ;
if ( V_38 == 0 ) {
F_179 ( V_2 , V_2 -> V_237 + 1 ) ;
F_3 ( V_2 ) ;
memcpy ( V_323 , & V_235 , sizeof( V_235 ) ) ;
}
return V_38 ;
}
static void F_256 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int * V_39 , int V_326 )
{
F_72 ( * V_39 == 0 ) ;
V_2 -> V_8 [ * V_39 - 1 ] = F_168 ( V_19 , V_2 -> V_8 [ * V_39 ] ,
V_2 -> V_17 [ * V_39 ] ) ;
V_2 -> V_17 [ * V_39 - 1 ] = 0 ;
( * V_39 ) -- ;
}
static int F_257 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int * V_39 , int V_326 )
{
int V_38 = 0 ;
int V_98 ;
V_98 = F_90 ( V_2 -> V_8 [ * V_39 ] ) ;
V_2 -> V_17 [ * V_39 ] ++ ;
while ( V_2 -> V_17 [ * V_39 ] >= V_98 ) {
if ( * V_39 == V_326 )
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
int * V_39 , int V_326 ,
int V_327 ,
struct V_156 * V_85 )
{
int V_38 ;
if ( * V_39 == 0 || ! V_327 ) {
V_38 = F_257 ( V_19 , V_2 , V_39 , V_326 ) ;
} else {
F_256 ( V_19 , V_2 , V_39 , V_326 ) ;
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
static int F_259 ( struct V_18 * V_328 ,
struct V_1 * V_329 ,
struct V_1 * V_330 ,
char * V_331 )
{
int V_332 ;
int V_333 , V_334 ;
unsigned long V_335 , V_336 ;
V_333 = F_226 ( V_329 -> V_8 [ 0 ] , V_329 -> V_17 [ 0 ] ) ;
V_334 = F_226 ( V_330 -> V_8 [ 0 ] , V_330 -> V_17 [ 0 ] ) ;
if ( V_333 != V_334 )
return 1 ;
V_335 = F_233 ( V_329 -> V_8 [ 0 ] , V_329 -> V_17 [ 0 ] ) ;
V_336 = F_233 ( V_330 -> V_8 [ 0 ] ,
V_330 -> V_17 [ 0 ] ) ;
F_159 ( V_329 -> V_8 [ 0 ] , V_331 , V_335 , V_333 ) ;
V_332 = F_186 ( V_330 -> V_8 [ 0 ] , V_331 , V_336 , V_333 ) ;
if ( V_332 )
return 1 ;
return 0 ;
}
int F_260 ( struct V_18 * V_328 ,
struct V_18 * V_337 ,
T_6 V_338 , void * V_339 )
{
int V_38 ;
int V_332 ;
struct V_1 * V_329 = NULL ;
struct V_1 * V_330 = NULL ;
struct V_156 V_340 ;
struct V_156 V_201 ;
char * V_331 = NULL ;
int V_341 ;
int V_342 ;
int V_343 ;
int V_344 ;
int V_345 ;
int V_346 ;
int V_347 ;
int V_348 ;
T_2 V_349 ;
T_2 V_350 ;
T_2 V_351 ;
T_2 V_352 ;
V_329 = F_1 () ;
if ( ! V_329 ) {
V_38 = - V_88 ;
goto V_289;
}
V_330 = F_1 () ;
if ( ! V_330 ) {
V_38 = - V_88 ;
goto V_289;
}
V_331 = F_232 ( V_328 -> V_146 , V_353 | V_354 ) ;
if ( ! V_331 ) {
V_331 = F_261 ( V_328 -> V_146 ) ;
if ( ! V_331 ) {
V_38 = - V_88 ;
goto V_289;
}
}
V_329 -> V_238 = 1 ;
V_329 -> V_241 = 1 ;
V_330 -> V_238 = 1 ;
V_330 -> V_241 = 1 ;
F_192 ( & V_328 -> V_26 -> V_240 ) ;
V_343 = F_33 ( V_328 -> V_118 ) ;
V_341 = V_343 ;
V_329 -> V_8 [ V_343 ] = V_328 -> V_118 ;
F_115 ( V_329 -> V_8 [ V_343 ] ) ;
V_344 = F_33 ( V_337 -> V_118 ) ;
V_342 = V_344 ;
V_330 -> V_8 [ V_344 ] = V_337 -> V_118 ;
F_115 ( V_330 -> V_8 [ V_344 ] ) ;
F_193 ( & V_328 -> V_26 -> V_240 ) ;
if ( V_343 == 0 )
F_191 ( V_329 -> V_8 [ V_343 ] ,
& V_340 , V_329 -> V_17 [ V_343 ] ) ;
else
F_255 ( V_329 -> V_8 [ V_343 ] ,
& V_340 , V_329 -> V_17 [ V_343 ] ) ;
if ( V_344 == 0 )
F_191 ( V_330 -> V_8 [ V_344 ] ,
& V_201 , V_330 -> V_17 [ V_344 ] ) ;
else
F_255 ( V_330 -> V_8 [ V_344 ] ,
& V_201 , V_330 -> V_17 [ V_344 ] ) ;
V_345 = V_346 = 0 ;
V_347 = V_348 = 0 ;
while ( 1 ) {
if ( V_347 && ! V_345 ) {
V_38 = F_258 ( V_328 , V_329 , & V_343 ,
V_341 ,
V_347 != V_355 ,
& V_340 ) ;
if ( V_38 < 0 )
V_345 = V_356 ;
V_347 = 0 ;
}
if ( V_348 && ! V_346 ) {
V_38 = F_258 ( V_337 , V_330 , & V_344 ,
V_342 ,
V_348 != V_355 ,
& V_201 ) ;
if ( V_38 < 0 )
V_346 = V_356 ;
V_348 = 0 ;
}
if ( V_345 && V_346 ) {
V_38 = 0 ;
goto V_289;
} else if ( V_345 ) {
if ( V_344 == 0 ) {
V_38 = V_338 ( V_328 , V_337 ,
V_329 , V_330 ,
& V_201 ,
V_357 ,
V_339 ) ;
if ( V_38 < 0 )
goto V_289;
}
V_348 = V_356 ;
continue;
} else if ( V_346 ) {
if ( V_343 == 0 ) {
V_38 = V_338 ( V_328 , V_337 ,
V_329 , V_330 ,
& V_340 ,
V_358 ,
V_339 ) ;
if ( V_38 < 0 )
goto V_289;
}
V_347 = V_356 ;
continue;
}
if ( V_343 == 0 && V_344 == 0 ) {
V_332 = F_148 ( & V_340 , & V_201 ) ;
if ( V_332 < 0 ) {
V_38 = V_338 ( V_328 , V_337 ,
V_329 , V_330 ,
& V_340 ,
V_358 ,
V_339 ) ;
if ( V_38 < 0 )
goto V_289;
V_347 = V_356 ;
} else if ( V_332 > 0 ) {
V_38 = V_338 ( V_328 , V_337 ,
V_329 , V_330 ,
& V_201 ,
V_357 ,
V_339 ) ;
if ( V_38 < 0 )
goto V_289;
V_348 = V_356 ;
} else {
enum V_359 V_360 ;
F_32 ( ! F_135 ( V_329 -> V_8 [ 0 ] ) ) ;
V_38 = F_259 ( V_328 , V_329 ,
V_330 , V_331 ) ;
if ( V_38 )
V_360 = V_361 ;
else
V_360 = V_362 ;
V_38 = V_338 ( V_328 , V_337 ,
V_329 , V_330 ,
& V_340 , V_360 , V_339 ) ;
if ( V_38 < 0 )
goto V_289;
V_347 = V_356 ;
V_348 = V_356 ;
}
} else if ( V_343 == V_344 ) {
V_332 = F_148 ( & V_340 , & V_201 ) ;
if ( V_332 < 0 ) {
V_347 = V_356 ;
} else if ( V_332 > 0 ) {
V_348 = V_356 ;
} else {
V_349 = F_81 (
V_329 -> V_8 [ V_343 ] ,
V_329 -> V_17 [ V_343 ] ) ;
V_350 = F_81 (
V_330 -> V_8 [ V_344 ] ,
V_330 -> V_17 [ V_344 ] ) ;
V_351 = F_82 (
V_329 -> V_8 [ V_343 ] ,
V_329 -> V_17 [ V_343 ] ) ;
V_352 = F_82 (
V_330 -> V_8 [ V_344 ] ,
V_330 -> V_17 [ V_344 ] ) ;
if ( V_349 == V_350 &&
V_351 == V_352 ) {
V_347 = V_355 ;
V_348 = V_355 ;
} else {
V_347 = V_356 ;
V_348 = V_356 ;
}
}
} else if ( V_343 < V_344 ) {
V_348 = V_356 ;
} else {
V_347 = V_356 ;
}
}
V_289:
F_7 ( V_329 ) ;
F_7 ( V_330 ) ;
F_262 ( V_331 ) ;
return V_38 ;
}
int F_254 ( struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_156 * V_85 , int V_39 , T_2 V_324 )
{
int V_80 ;
struct V_14 * V_258 ;
F_32 ( ! V_2 -> V_220 ) ;
while ( V_39 < V_7 ) {
if ( ! V_2 -> V_8 [ V_39 ] )
return 1 ;
V_80 = V_2 -> V_17 [ V_39 ] + 1 ;
V_258 = V_2 -> V_8 [ V_39 ] ;
V_66:
if ( V_80 >= F_90 ( V_258 ) ) {
int V_38 ;
int V_363 ;
struct V_156 V_364 ;
if ( V_39 + 1 >= V_7 ||
! V_2 -> V_8 [ V_39 + 1 ] )
return 1 ;
if ( V_2 -> V_9 [ V_39 + 1 ] ) {
V_39 ++ ;
continue;
}
V_80 = F_90 ( V_258 ) - 1 ;
if ( V_39 == 0 )
F_191 ( V_258 , & V_364 , V_80 ) ;
else
F_255 ( V_258 , & V_364 , V_80 ) ;
V_363 = V_2 -> V_237 ;
F_8 ( V_2 ) ;
V_2 -> V_237 = V_39 ;
V_38 = F_189 ( NULL , V_19 , & V_364 , V_2 ,
0 , 0 ) ;
V_2 -> V_237 = V_363 ;
if ( V_38 < 0 )
return V_38 ;
V_258 = V_2 -> V_8 [ V_39 ] ;
V_80 = V_2 -> V_17 [ V_39 ] ;
if ( V_38 == 0 )
V_80 ++ ;
goto V_66;
}
if ( V_39 == 0 )
F_191 ( V_258 , V_85 , V_80 ) ;
else {
T_2 V_163 = F_82 ( V_258 , V_80 ) ;
if ( V_163 < V_324 ) {
V_80 ++ ;
goto V_66;
}
F_255 ( V_258 , V_85 , V_80 ) ;
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
struct V_14 * V_258 ;
struct V_14 * V_66 ;
struct V_156 V_85 ;
T_4 V_98 ;
int V_38 ;
int V_365 = V_2 -> V_245 ;
int V_366 = 0 ;
V_98 = F_90 ( V_2 -> V_8 [ 0 ] ) ;
if ( V_98 == 0 )
return 1 ;
F_191 ( V_2 -> V_8 [ 0 ] , & V_85 , V_98 - 1 ) ;
V_228:
V_39 = 1 ;
V_66 = NULL ;
V_366 = 0 ;
F_8 ( V_2 ) ;
V_2 -> V_220 = 1 ;
V_2 -> V_245 = 1 ;
if ( V_132 )
V_38 = F_198 ( V_19 , & V_85 , V_2 , V_132 ) ;
else
V_38 = F_189 ( NULL , V_19 , & V_85 , V_2 , 0 , 0 ) ;
V_2 -> V_220 = 0 ;
if ( V_38 < 0 )
return V_38 ;
V_98 = F_90 ( V_2 -> V_8 [ 0 ] ) ;
if ( V_98 > 0 && V_2 -> V_17 [ 0 ] < V_98 - 1 ) {
if ( V_38 == 0 )
V_2 -> V_17 [ 0 ] ++ ;
V_38 = 0 ;
goto V_229;
}
if ( V_98 > 0 && V_38 > 0 && V_2 -> V_17 [ 0 ] == V_98 - 1 ) {
V_38 = 0 ;
goto V_229;
}
while ( V_39 < V_7 ) {
if ( ! V_2 -> V_8 [ V_39 ] ) {
V_38 = 1 ;
goto V_229;
}
V_80 = V_2 -> V_17 [ V_39 ] + 1 ;
V_258 = V_2 -> V_8 [ V_39 ] ;
if ( V_80 >= F_90 ( V_258 ) ) {
V_39 ++ ;
if ( V_39 == V_7 ) {
V_38 = 1 ;
goto V_229;
}
continue;
}
if ( V_66 ) {
F_10 ( V_66 , V_366 ) ;
F_11 ( V_66 ) ;
}
V_66 = V_258 ;
V_366 = V_2 -> V_9 [ V_39 ] ;
V_38 = F_180 ( NULL , V_19 , V_2 , & V_66 , V_39 ,
V_80 , & V_85 , 0 ) ;
if ( V_38 == - V_224 )
goto V_228;
if ( V_38 < 0 ) {
F_8 ( V_2 ) ;
goto V_229;
}
if ( ! V_2 -> V_241 ) {
V_38 = F_264 ( V_66 ) ;
if ( ! V_38 && V_132 ) {
F_11 ( V_66 ) ;
F_8 ( V_2 ) ;
F_265 () ;
goto V_228;
}
if ( ! V_38 ) {
F_3 ( V_2 ) ;
F_22 ( V_66 ) ;
F_5 ( V_2 , V_66 ,
V_10 ) ;
}
V_366 = V_10 ;
}
break;
}
V_2 -> V_17 [ V_39 ] = V_80 ;
while ( 1 ) {
V_39 -- ;
V_258 = V_2 -> V_8 [ V_39 ] ;
if ( V_2 -> V_9 [ V_39 ] )
F_10 ( V_258 , V_2 -> V_9 [ V_39 ] ) ;
F_11 ( V_258 ) ;
V_2 -> V_8 [ V_39 ] = V_66 ;
V_2 -> V_17 [ V_39 ] = 0 ;
if ( ! V_2 -> V_241 )
V_2 -> V_9 [ V_39 ] = V_366 ;
if ( ! V_39 )
break;
V_38 = F_180 ( NULL , V_19 , V_2 , & V_66 , V_39 ,
0 , & V_85 , 0 ) ;
if ( V_38 == - V_224 )
goto V_228;
if ( V_38 < 0 ) {
F_8 ( V_2 ) ;
goto V_229;
}
if ( ! V_2 -> V_241 ) {
V_38 = F_264 ( V_66 ) ;
if ( ! V_38 ) {
F_3 ( V_2 ) ;
F_22 ( V_66 ) ;
F_5 ( V_2 , V_66 ,
V_10 ) ;
}
V_366 = V_10 ;
}
}
V_38 = 0 ;
V_229:
F_178 ( V_2 , 0 , 1 , 0 , NULL ) ;
V_2 -> V_245 = V_365 ;
if ( ! V_365 )
F_3 ( V_2 ) ;
return V_38 ;
}
int F_266 ( struct V_18 * V_19 ,
struct V_1 * V_2 , T_2 V_367 ,
int type )
{
struct V_156 V_235 ;
struct V_14 * V_173 ;
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
V_173 = V_2 -> V_8 [ 0 ] ;
V_98 = F_90 ( V_173 ) ;
if ( V_98 == 0 )
return 1 ;
if ( V_2 -> V_17 [ 0 ] == V_98 )
V_2 -> V_17 [ 0 ] -- ;
F_191 ( V_173 , & V_235 , V_2 -> V_17 [ 0 ] ) ;
if ( V_235 . V_28 < V_367 )
break;
if ( V_235 . type == type )
return 0 ;
if ( V_235 . V_28 == V_367 &&
V_235 . type < type )
break;
}
return 1 ;
}
int F_267 ( struct V_18 * V_19 ,
struct V_1 * V_2 , T_2 V_367 )
{
struct V_156 V_235 ;
struct V_14 * V_173 ;
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
V_173 = V_2 -> V_8 [ 0 ] ;
V_98 = F_90 ( V_173 ) ;
if ( V_98 == 0 )
return 1 ;
if ( V_2 -> V_17 [ 0 ] == V_98 )
V_2 -> V_17 [ 0 ] -- ;
F_191 ( V_173 , & V_235 , V_2 -> V_17 [ 0 ] ) ;
if ( V_235 . V_28 < V_367 )
break;
if ( V_235 . type == V_368 ||
V_235 . type == V_369 )
return 0 ;
if ( V_235 . V_28 == V_367 &&
V_235 . type < V_368 )
break;
}
return 1 ;
}
