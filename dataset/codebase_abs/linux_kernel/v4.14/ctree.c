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
struct V_22 * V_23 = V_18 -> V_23 ;
if ( F_25 ( V_24 , & V_18 -> V_25 ) ||
! F_25 ( V_26 , & V_18 -> V_25 ) )
return;
F_26 ( & V_23 -> V_27 ) ;
if ( ! F_27 ( V_24 , & V_18 -> V_25 ) ) {
if ( V_18 -> V_28 == V_29 )
F_28 ( & V_18 -> V_30 ,
& V_23 -> V_31 ) ;
else
F_29 ( & V_18 -> V_30 ,
& V_23 -> V_31 ) ;
}
F_30 ( & V_23 -> V_27 ) ;
}
int F_31 ( struct V_32 * V_33 ,
struct V_17 * V_18 ,
struct V_13 * V_34 ,
struct V_13 * * V_35 , T_2 V_36 )
{
struct V_22 * V_23 = V_18 -> V_23 ;
struct V_13 * V_37 ;
int V_38 = 0 ;
int V_39 ;
struct V_40 V_41 ;
F_32 ( F_25 ( V_42 , & V_18 -> V_25 ) &&
V_33 -> V_43 != V_23 -> V_44 -> V_43 ) ;
F_32 ( F_25 ( V_42 , & V_18 -> V_25 ) &&
V_33 -> V_43 != V_18 -> V_45 ) ;
V_39 = F_33 ( V_34 ) ;
if ( V_39 == 0 )
F_34 ( V_34 , & V_41 , 0 ) ;
else
F_35 ( V_34 , & V_41 , 0 ) ;
V_37 = F_36 ( V_33 , V_18 , 0 , V_36 ,
& V_41 , V_39 , V_34 -> V_46 , 0 ) ;
if ( F_37 ( V_37 ) )
return F_38 ( V_37 ) ;
F_39 ( V_37 , V_34 ) ;
F_40 ( V_37 , V_37 -> V_46 ) ;
F_41 ( V_37 , V_33 -> V_43 ) ;
F_42 ( V_37 , V_47 ) ;
F_43 ( V_37 , V_48 |
V_49 ) ;
if ( V_36 == V_50 )
F_44 ( V_37 , V_49 ) ;
else
F_45 ( V_37 , V_36 ) ;
F_46 ( V_37 , V_23 -> V_51 ) ;
F_32 ( F_47 ( V_34 ) > V_33 -> V_43 ) ;
if ( V_36 == V_50 )
V_38 = F_48 ( V_33 , V_18 , V_37 , 1 ) ;
else
V_38 = F_48 ( V_33 , V_18 , V_37 , 0 ) ;
if ( V_38 )
return V_38 ;
F_49 ( V_37 ) ;
* V_35 = V_37 ;
return 0 ;
}
static inline void F_50 ( struct V_22 * V_23 )
{
F_51 ( & V_23 -> V_52 ) ;
}
static inline void F_52 ( struct V_22 * V_23 )
{
F_53 ( & V_23 -> V_52 ) ;
}
static inline void F_54 ( struct V_22 * V_23 )
{
F_55 ( & V_23 -> V_52 ) ;
}
static inline void F_56 ( struct V_22 * V_23 )
{
F_57 ( & V_23 -> V_52 ) ;
}
static inline T_2 F_58 ( struct V_22 * V_23 )
{
return F_59 ( & V_23 -> V_53 ) ;
}
T_2 F_60 ( struct V_22 * V_23 ,
struct V_54 * V_55 )
{
F_54 ( V_23 ) ;
F_26 ( & V_23 -> V_56 ) ;
if ( ! V_55 -> V_57 ) {
V_55 -> V_57 = F_58 ( V_23 ) ;
F_61 ( & V_55 -> V_58 , & V_23 -> V_59 ) ;
}
F_30 ( & V_23 -> V_56 ) ;
F_56 ( V_23 ) ;
return V_55 -> V_57 ;
}
void F_62 ( struct V_22 * V_23 ,
struct V_54 * V_55 )
{
struct V_60 * V_61 ;
struct V_62 * V_20 ;
struct V_62 * V_63 ;
struct V_54 * V_64 ;
struct V_65 * V_66 ;
T_2 V_67 = ( T_2 ) - 1 ;
T_2 V_68 = V_55 -> V_57 ;
if ( ! V_68 )
return;
F_26 ( & V_23 -> V_56 ) ;
F_63 ( & V_55 -> V_58 ) ;
V_55 -> V_57 = 0 ;
F_64 (cur_elem, &fs_info->tree_mod_seq_list, list) {
if ( V_64 -> V_57 < V_67 ) {
if ( V_68 > V_64 -> V_57 ) {
F_30 ( & V_23 -> V_56 ) ;
return;
}
V_67 = V_64 -> V_57 ;
}
}
F_30 ( & V_23 -> V_56 ) ;
F_54 ( V_23 ) ;
V_61 = & V_23 -> V_69 ;
for ( V_20 = F_65 ( V_61 ) ; V_20 ; V_20 = V_63 ) {
V_63 = F_66 ( V_20 ) ;
V_66 = F_67 ( V_20 , struct V_65 , V_20 ) ;
if ( V_66 -> V_57 > V_67 )
continue;
F_68 ( V_20 , V_61 ) ;
F_69 ( V_66 ) ;
}
F_56 ( V_23 ) ;
}
static T_1 int
F_70 ( struct V_22 * V_23 , struct V_65 * V_66 )
{
struct V_60 * V_61 ;
struct V_62 * * V_70 ;
struct V_62 * V_71 = NULL ;
struct V_65 * V_72 ;
V_66 -> V_57 = F_58 ( V_23 ) ;
V_61 = & V_23 -> V_69 ;
V_70 = & V_61 -> V_62 ;
while ( * V_70 ) {
V_72 = F_67 ( * V_70 , struct V_65 , V_20 ) ;
V_71 = * V_70 ;
if ( V_72 -> V_73 < V_66 -> V_73 )
V_70 = & ( ( * V_70 ) -> V_74 ) ;
else if ( V_72 -> V_73 > V_66 -> V_73 )
V_70 = & ( ( * V_70 ) -> V_75 ) ;
else if ( V_72 -> V_57 < V_66 -> V_57 )
V_70 = & ( ( * V_70 ) -> V_74 ) ;
else if ( V_72 -> V_57 > V_66 -> V_57 )
V_70 = & ( ( * V_70 ) -> V_75 ) ;
else
return - V_76 ;
}
F_71 ( & V_66 -> V_20 , V_71 , V_70 ) ;
F_72 ( & V_66 -> V_20 , V_61 ) ;
return 0 ;
}
static inline int F_73 ( struct V_22 * V_23 ,
struct V_13 * V_19 ) {
F_74 () ;
if ( F_75 ( & ( V_23 ) -> V_59 ) )
return 1 ;
if ( V_19 && F_33 ( V_19 ) == 0 )
return 1 ;
F_54 ( V_23 ) ;
if ( F_75 ( & ( V_23 ) -> V_59 ) ) {
F_56 ( V_23 ) ;
return 1 ;
}
return 0 ;
}
static inline int F_76 ( const struct V_22 * V_23 ,
struct V_13 * V_19 )
{
F_74 () ;
if ( F_75 ( & ( V_23 ) -> V_59 ) )
return 0 ;
if ( V_19 && F_33 ( V_19 ) == 0 )
return 0 ;
return 1 ;
}
static struct V_65 *
F_77 ( struct V_13 * V_19 , int V_77 ,
enum V_78 V_79 , T_3 V_80 )
{
struct V_65 * V_66 ;
V_66 = F_78 ( sizeof( * V_66 ) , V_80 ) ;
if ( ! V_66 )
return NULL ;
V_66 -> V_73 = V_19 -> V_46 ;
if ( V_79 != V_81 ) {
F_35 ( V_19 , & V_66 -> V_82 , V_77 ) ;
V_66 -> V_83 = F_79 ( V_19 , V_77 ) ;
}
V_66 -> V_79 = V_79 ;
V_66 -> V_77 = V_77 ;
V_66 -> V_84 = F_80 ( V_19 , V_77 ) ;
F_81 ( & V_66 -> V_20 ) ;
return V_66 ;
}
static T_1 int
F_82 ( struct V_22 * V_23 ,
struct V_13 * V_19 , int V_77 ,
enum V_78 V_79 , T_3 V_80 )
{
struct V_65 * V_66 ;
int V_38 ;
if ( ! F_76 ( V_23 , V_19 ) )
return 0 ;
V_66 = F_77 ( V_19 , V_77 , V_79 , V_80 ) ;
if ( ! V_66 )
return - V_85 ;
if ( F_73 ( V_23 , V_19 ) ) {
F_69 ( V_66 ) ;
return 0 ;
}
V_38 = F_70 ( V_23 , V_66 ) ;
F_56 ( V_23 ) ;
if ( V_38 )
F_69 ( V_66 ) ;
return V_38 ;
}
static T_1 int
F_83 ( struct V_22 * V_23 ,
struct V_13 * V_19 , int V_86 , int V_87 ,
int V_88 )
{
struct V_65 * V_66 = NULL ;
struct V_65 * * V_89 = NULL ;
int V_38 = 0 ;
int V_5 ;
int V_90 = 0 ;
if ( ! F_76 ( V_23 , V_19 ) )
return 0 ;
V_89 = F_84 ( V_88 , sizeof( struct V_65 * ) , V_3 ) ;
if ( ! V_89 )
return - V_85 ;
V_66 = F_78 ( sizeof( * V_66 ) , V_3 ) ;
if ( ! V_66 ) {
V_38 = - V_85 ;
goto V_91;
}
V_66 -> V_73 = V_19 -> V_46 ;
V_66 -> V_77 = V_87 ;
V_66 -> V_92 . V_86 = V_86 ;
V_66 -> V_92 . V_88 = V_88 ;
V_66 -> V_79 = V_93 ;
for ( V_5 = 0 ; V_5 + V_86 < V_87 && V_5 < V_88 ; V_5 ++ ) {
V_89 [ V_5 ] = F_77 ( V_19 , V_5 + V_86 ,
V_94 , V_3 ) ;
if ( ! V_89 [ V_5 ] ) {
V_38 = - V_85 ;
goto V_91;
}
}
if ( F_73 ( V_23 , V_19 ) )
goto V_91;
V_90 = 1 ;
for ( V_5 = 0 ; V_5 + V_86 < V_87 && V_5 < V_88 ; V_5 ++ ) {
V_38 = F_70 ( V_23 , V_89 [ V_5 ] ) ;
if ( V_38 )
goto V_91;
}
V_38 = F_70 ( V_23 , V_66 ) ;
if ( V_38 )
goto V_91;
F_56 ( V_23 ) ;
F_69 ( V_89 ) ;
return 0 ;
V_91:
for ( V_5 = 0 ; V_5 < V_88 ; V_5 ++ ) {
if ( V_89 [ V_5 ] && ! F_85 ( & V_89 [ V_5 ] -> V_20 ) )
F_68 ( & V_89 [ V_5 ] -> V_20 , & V_23 -> V_69 ) ;
F_69 ( V_89 [ V_5 ] ) ;
}
if ( V_90 )
F_56 ( V_23 ) ;
F_69 ( V_89 ) ;
F_69 ( V_66 ) ;
return V_38 ;
}
static inline int
F_86 ( struct V_22 * V_23 ,
struct V_65 * * V_89 ,
int V_95 )
{
int V_5 , V_96 ;
int V_38 ;
for ( V_5 = V_95 - 1 ; V_5 >= 0 ; V_5 -- ) {
V_38 = F_70 ( V_23 , V_89 [ V_5 ] ) ;
if ( V_38 ) {
for ( V_96 = V_95 - 1 ; V_96 > V_5 ; V_96 -- )
F_68 ( & V_89 [ V_96 ] -> V_20 ,
& V_23 -> V_69 ) ;
return V_38 ;
}
}
return 0 ;
}
static T_1 int
F_87 ( struct V_22 * V_23 ,
struct V_13 * V_97 ,
struct V_13 * V_98 ,
int V_99 )
{
struct V_65 * V_66 = NULL ;
struct V_65 * * V_89 = NULL ;
int V_95 = 0 ;
int V_38 = 0 ;
int V_5 ;
if ( ! F_76 ( V_23 , NULL ) )
return 0 ;
if ( V_99 && F_33 ( V_97 ) > 0 ) {
V_95 = F_88 ( V_97 ) ;
V_89 = F_84 ( V_95 , sizeof( struct V_65 * ) ,
V_3 ) ;
if ( ! V_89 ) {
V_38 = - V_85 ;
goto V_91;
}
for ( V_5 = 0 ; V_5 < V_95 ; V_5 ++ ) {
V_89 [ V_5 ] = F_77 ( V_97 , V_5 ,
V_100 , V_3 ) ;
if ( ! V_89 [ V_5 ] ) {
V_38 = - V_85 ;
goto V_91;
}
}
}
V_66 = F_78 ( sizeof( * V_66 ) , V_3 ) ;
if ( ! V_66 ) {
V_38 = - V_85 ;
goto V_91;
}
V_66 -> V_73 = V_98 -> V_46 ;
V_66 -> V_97 . V_73 = V_97 -> V_46 ;
V_66 -> V_97 . V_39 = F_33 ( V_97 ) ;
V_66 -> V_84 = F_47 ( V_97 ) ;
V_66 -> V_79 = V_101 ;
if ( F_73 ( V_23 , NULL ) )
goto V_91;
if ( V_89 )
V_38 = F_86 ( V_23 , V_89 , V_95 ) ;
if ( ! V_38 )
V_38 = F_70 ( V_23 , V_66 ) ;
F_56 ( V_23 ) ;
if ( V_38 )
goto V_91;
F_69 ( V_89 ) ;
return V_38 ;
V_91:
if ( V_89 ) {
for ( V_5 = 0 ; V_5 < V_95 ; V_5 ++ )
F_69 ( V_89 [ V_5 ] ) ;
F_69 ( V_89 ) ;
}
F_69 ( V_66 ) ;
return V_38 ;
}
static struct V_65 *
F_89 ( struct V_22 * V_23 , T_2 V_46 , T_2 V_67 ,
int V_102 )
{
struct V_60 * V_61 ;
struct V_62 * V_20 ;
struct V_65 * V_72 = NULL ;
struct V_65 * V_103 = NULL ;
F_50 ( V_23 ) ;
V_61 = & V_23 -> V_69 ;
V_20 = V_61 -> V_62 ;
while ( V_20 ) {
V_72 = F_67 ( V_20 , struct V_65 , V_20 ) ;
if ( V_72 -> V_73 < V_46 ) {
V_20 = V_20 -> V_74 ;
} else if ( V_72 -> V_73 > V_46 ) {
V_20 = V_20 -> V_75 ;
} else if ( V_72 -> V_57 < V_67 ) {
V_20 = V_20 -> V_74 ;
} else if ( ! V_102 ) {
if ( V_103 )
F_90 ( V_103 -> V_57 > V_72 -> V_57 ) ;
V_103 = V_72 ;
V_20 = V_20 -> V_74 ;
} else if ( V_72 -> V_57 > V_67 ) {
if ( V_103 )
F_90 ( V_103 -> V_57 < V_72 -> V_57 ) ;
V_103 = V_72 ;
V_20 = V_20 -> V_75 ;
} else {
V_103 = V_72 ;
break;
}
}
F_52 ( V_23 ) ;
return V_103 ;
}
static struct V_65 *
F_91 ( struct V_22 * V_23 , T_2 V_46 ,
T_2 V_67 )
{
return F_89 ( V_23 , V_46 , V_67 , 1 ) ;
}
static struct V_65 *
F_92 ( struct V_22 * V_23 , T_2 V_46 , T_2 V_67 )
{
return F_89 ( V_23 , V_46 , V_67 , 0 ) ;
}
static T_1 int
F_93 ( struct V_22 * V_23 , struct V_13 * V_104 ,
struct V_13 * V_105 , unsigned long V_106 ,
unsigned long V_107 , int V_88 )
{
int V_38 = 0 ;
struct V_65 * * V_89 = NULL ;
struct V_65 * * V_108 , * * V_109 ;
int V_5 ;
int V_90 = 0 ;
if ( ! F_76 ( V_23 , NULL ) )
return 0 ;
if ( F_33 ( V_104 ) == 0 && F_33 ( V_105 ) == 0 )
return 0 ;
V_89 = F_84 ( V_88 * 2 , sizeof( struct V_65 * ) ,
V_3 ) ;
if ( ! V_89 )
return - V_85 ;
V_108 = V_89 ;
V_109 = V_89 + V_88 ;
for ( V_5 = 0 ; V_5 < V_88 ; V_5 ++ ) {
V_109 [ V_5 ] = F_77 ( V_105 , V_5 + V_107 ,
V_110 , V_3 ) ;
if ( ! V_109 [ V_5 ] ) {
V_38 = - V_85 ;
goto V_91;
}
V_108 [ V_5 ] = F_77 ( V_104 , V_5 + V_106 ,
V_81 , V_3 ) ;
if ( ! V_108 [ V_5 ] ) {
V_38 = - V_85 ;
goto V_91;
}
}
if ( F_73 ( V_23 , NULL ) )
goto V_91;
V_90 = 1 ;
for ( V_5 = 0 ; V_5 < V_88 ; V_5 ++ ) {
V_38 = F_70 ( V_23 , V_109 [ V_5 ] ) ;
if ( V_38 )
goto V_91;
V_38 = F_70 ( V_23 , V_108 [ V_5 ] ) ;
if ( V_38 )
goto V_91;
}
F_56 ( V_23 ) ;
F_69 ( V_89 ) ;
return 0 ;
V_91:
for ( V_5 = 0 ; V_5 < V_88 * 2 ; V_5 ++ ) {
if ( V_89 [ V_5 ] && ! F_85 ( & V_89 [ V_5 ] -> V_20 ) )
F_68 ( & V_89 [ V_5 ] -> V_20 , & V_23 -> V_69 ) ;
F_69 ( V_89 [ V_5 ] ) ;
}
if ( V_90 )
F_56 ( V_23 ) ;
F_69 ( V_89 ) ;
return V_38 ;
}
static inline void
F_94 ( struct V_22 * V_23 , struct V_13 * V_104 ,
int V_106 , int V_107 , int V_88 )
{
int V_38 ;
V_38 = F_83 ( V_23 , V_104 , V_106 , V_107 ,
V_88 ) ;
F_90 ( V_38 < 0 ) ;
}
static T_1 void
F_95 ( struct V_22 * V_23 ,
struct V_13 * V_19 , int V_77 , int V_111 )
{
int V_38 ;
V_38 = F_82 ( V_23 , V_19 , V_77 ,
V_112 ,
V_111 ? V_113 : V_3 ) ;
F_90 ( V_38 < 0 ) ;
}
static T_1 int
F_96 ( struct V_22 * V_23 , struct V_13 * V_19 )
{
struct V_65 * * V_89 = NULL ;
int V_95 = 0 ;
int V_5 ;
int V_38 = 0 ;
if ( F_33 ( V_19 ) == 0 )
return 0 ;
if ( ! F_76 ( V_23 , NULL ) )
return 0 ;
V_95 = F_88 ( V_19 ) ;
V_89 = F_84 ( V_95 , sizeof( struct V_65 * ) , V_3 ) ;
if ( ! V_89 )
return - V_85 ;
for ( V_5 = 0 ; V_5 < V_95 ; V_5 ++ ) {
V_89 [ V_5 ] = F_77 ( V_19 , V_5 ,
V_100 , V_3 ) ;
if ( ! V_89 [ V_5 ] ) {
V_38 = - V_85 ;
goto V_91;
}
}
if ( F_73 ( V_23 , V_19 ) )
goto V_91;
V_38 = F_86 ( V_23 , V_89 , V_95 ) ;
F_56 ( V_23 ) ;
if ( V_38 )
goto V_91;
F_69 ( V_89 ) ;
return 0 ;
V_91:
for ( V_5 = 0 ; V_5 < V_95 ; V_5 ++ )
F_69 ( V_89 [ V_5 ] ) ;
F_69 ( V_89 ) ;
return V_38 ;
}
static T_1 void
F_97 ( struct V_17 * V_18 ,
struct V_13 * V_114 ,
int V_99 )
{
int V_38 ;
V_38 = F_87 ( V_18 -> V_23 , V_18 -> V_20 ,
V_114 , V_99 ) ;
F_90 ( V_38 < 0 ) ;
}
int F_98 ( struct V_17 * V_18 ,
struct V_13 * V_34 )
{
if ( F_25 ( V_42 , & V_18 -> V_25 ) &&
V_34 != V_18 -> V_20 && V_34 != V_18 -> V_115 &&
( F_47 ( V_34 ) <=
F_99 ( & V_18 -> V_116 ) ||
F_100 ( V_34 , V_49 ) ) )
return 1 ;
#ifdef F_101
if ( F_25 ( V_42 , & V_18 -> V_25 ) &&
F_102 ( V_34 ) < V_47 )
return 1 ;
#endif
return 0 ;
}
static T_1 int F_103 ( struct V_32 * V_33 ,
struct V_17 * V_18 ,
struct V_13 * V_34 ,
struct V_13 * V_37 ,
int * V_117 )
{
struct V_22 * V_23 = V_18 -> V_23 ;
T_2 V_21 ;
T_2 V_118 ;
T_2 V_80 ;
T_2 V_119 = 0 ;
int V_38 ;
if ( F_98 ( V_18 , V_34 ) ) {
V_38 = F_104 ( V_33 , V_23 , V_34 -> V_46 ,
F_33 ( V_34 ) , 1 ,
& V_21 , & V_80 ) ;
if ( V_38 )
return V_38 ;
if ( V_21 == 0 ) {
V_38 = - V_120 ;
F_105 ( V_23 , V_38 , NULL ) ;
return V_38 ;
}
} else {
V_21 = 1 ;
if ( V_18 -> V_121 . V_28 == V_50 ||
F_102 ( V_34 ) < V_47 )
V_80 = V_122 ;
else
V_80 = 0 ;
}
V_118 = F_106 ( V_34 ) ;
F_90 ( V_118 == V_50 &&
! ( V_80 & V_122 ) ) ;
if ( V_21 > 1 ) {
if ( ( V_118 == V_18 -> V_121 . V_28 ||
V_18 -> V_121 . V_28 == V_50 ) &&
! ( V_80 & V_122 ) ) {
V_38 = F_48 ( V_33 , V_18 , V_34 , 1 ) ;
F_90 ( V_38 ) ;
if ( V_18 -> V_121 . V_28 ==
V_50 ) {
V_38 = F_107 ( V_33 , V_18 , V_34 , 0 ) ;
F_90 ( V_38 ) ;
V_38 = F_48 ( V_33 , V_18 , V_37 , 1 ) ;
F_90 ( V_38 ) ;
}
V_119 |= V_122 ;
} else {
if ( V_18 -> V_121 . V_28 ==
V_50 )
V_38 = F_48 ( V_33 , V_18 , V_37 , 1 ) ;
else
V_38 = F_48 ( V_33 , V_18 , V_37 , 0 ) ;
F_90 ( V_38 ) ;
}
if ( V_119 != 0 ) {
int V_39 = F_33 ( V_34 ) ;
V_38 = F_108 ( V_33 , V_23 ,
V_34 -> V_46 ,
V_34 -> V_123 ,
V_119 , V_39 , 0 ) ;
if ( V_38 )
return V_38 ;
}
} else {
if ( V_80 & V_122 ) {
if ( V_18 -> V_121 . V_28 ==
V_50 )
V_38 = F_48 ( V_33 , V_18 , V_37 , 1 ) ;
else
V_38 = F_48 ( V_33 , V_18 , V_37 , 0 ) ;
F_90 ( V_38 ) ;
V_38 = F_107 ( V_33 , V_18 , V_34 , 1 ) ;
F_90 ( V_38 ) ;
}
F_109 ( V_23 , V_34 ) ;
* V_117 = 1 ;
}
return 0 ;
}
static T_1 int F_110 ( struct V_32 * V_33 ,
struct V_17 * V_18 ,
struct V_13 * V_34 ,
struct V_13 * V_71 , int V_124 ,
struct V_13 * * V_35 ,
T_2 V_125 , T_2 V_126 )
{
struct V_22 * V_23 = V_18 -> V_23 ;
struct V_40 V_41 ;
struct V_13 * V_37 ;
int V_39 , V_38 ;
int V_117 = 0 ;
int V_127 = 0 ;
T_2 V_128 = 0 ;
if ( * V_35 == V_34 )
V_127 = 1 ;
F_111 ( V_34 ) ;
F_32 ( F_25 ( V_42 , & V_18 -> V_25 ) &&
V_33 -> V_43 != V_23 -> V_44 -> V_43 ) ;
F_32 ( F_25 ( V_42 , & V_18 -> V_25 ) &&
V_33 -> V_43 != V_18 -> V_45 ) ;
V_39 = F_33 ( V_34 ) ;
if ( V_39 == 0 )
F_34 ( V_34 , & V_41 , 0 ) ;
else
F_35 ( V_34 , & V_41 , 0 ) ;
if ( ( V_18 -> V_121 . V_28 == V_50 ) && V_71 )
V_128 = V_71 -> V_46 ;
V_37 = F_36 ( V_33 , V_18 , V_128 ,
V_18 -> V_121 . V_28 , & V_41 , V_39 ,
V_125 , V_126 ) ;
if ( F_37 ( V_37 ) )
return F_38 ( V_37 ) ;
F_39 ( V_37 , V_34 ) ;
F_40 ( V_37 , V_37 -> V_46 ) ;
F_41 ( V_37 , V_33 -> V_43 ) ;
F_42 ( V_37 , V_47 ) ;
F_43 ( V_37 , V_48 |
V_49 ) ;
if ( V_18 -> V_121 . V_28 == V_50 )
F_44 ( V_37 , V_49 ) ;
else
F_45 ( V_37 , V_18 -> V_121 . V_28 ) ;
F_46 ( V_37 , V_23 -> V_51 ) ;
V_38 = F_103 ( V_33 , V_18 , V_34 , V_37 , & V_117 ) ;
if ( V_38 ) {
F_112 ( V_33 , V_38 ) ;
return V_38 ;
}
if ( F_25 ( V_42 , & V_18 -> V_25 ) ) {
V_38 = F_113 ( V_33 , V_18 , V_34 , V_37 ) ;
if ( V_38 ) {
F_112 ( V_33 , V_38 ) ;
return V_38 ;
}
}
if ( V_34 == V_18 -> V_20 ) {
F_32 ( V_71 && V_71 != V_34 ) ;
if ( V_18 -> V_121 . V_28 == V_50 ||
F_102 ( V_34 ) < V_47 )
V_128 = V_34 -> V_46 ;
F_114 ( V_37 ) ;
F_97 ( V_18 , V_37 , 1 ) ;
F_115 ( V_18 -> V_20 , V_37 ) ;
F_116 ( V_33 , V_18 , V_34 , V_128 ,
V_117 ) ;
F_11 ( V_34 ) ;
F_24 ( V_18 ) ;
} else {
F_32 ( V_33 -> V_43 != F_47 ( V_71 ) ) ;
F_82 ( V_23 , V_71 , V_124 ,
V_112 , V_3 ) ;
F_117 ( V_71 , V_124 ,
V_37 -> V_46 ) ;
F_118 ( V_71 , V_124 ,
V_33 -> V_43 ) ;
F_49 ( V_71 ) ;
if ( V_117 ) {
V_38 = F_96 ( V_23 , V_34 ) ;
if ( V_38 ) {
F_112 ( V_33 , V_38 ) ;
return V_38 ;
}
}
F_116 ( V_33 , V_18 , V_34 , V_128 ,
V_117 ) ;
}
if ( V_127 )
F_20 ( V_34 ) ;
F_119 ( V_34 ) ;
F_49 ( V_37 ) ;
* V_35 = V_37 ;
return 0 ;
}
static struct V_65 *
F_120 ( struct V_22 * V_23 ,
struct V_13 * V_129 , T_2 V_130 )
{
struct V_65 * V_66 ;
struct V_65 * V_103 = NULL ;
T_2 V_131 = V_129 -> V_46 ;
int V_132 = 0 ;
if ( ! V_130 )
return NULL ;
while ( 1 ) {
V_66 = F_91 ( V_23 , V_131 ,
V_130 ) ;
if ( ! V_132 && ! V_66 )
return NULL ;
if ( ! V_66 )
break;
if ( V_66 -> V_79 != V_101 )
break;
V_103 = V_66 ;
V_131 = V_66 -> V_97 . V_73 ;
V_132 = 1 ;
}
if ( ! V_103 )
V_103 = V_66 ;
return V_103 ;
}
static void
F_121 ( struct V_22 * V_23 , struct V_13 * V_19 ,
T_2 V_130 , struct V_65 * V_133 )
{
T_4 V_134 ;
struct V_62 * V_63 ;
struct V_65 * V_66 = V_133 ;
unsigned long V_135 ;
unsigned long V_136 ;
unsigned long V_137 = sizeof( struct V_138 ) ;
V_134 = F_88 ( V_19 ) ;
F_50 ( V_23 ) ;
while ( V_66 && V_66 -> V_57 >= V_130 ) {
switch ( V_66 -> V_79 ) {
case V_100 :
F_90 ( V_66 -> V_77 < V_134 ) ;
case V_94 :
case V_110 :
F_122 ( V_19 , & V_66 -> V_82 , V_66 -> V_77 ) ;
F_117 ( V_19 , V_66 -> V_77 , V_66 -> V_83 ) ;
F_118 ( V_19 , V_66 -> V_77 ,
V_66 -> V_84 ) ;
V_134 ++ ;
break;
case V_112 :
F_90 ( V_66 -> V_77 >= V_134 ) ;
F_122 ( V_19 , & V_66 -> V_82 , V_66 -> V_77 ) ;
F_117 ( V_19 , V_66 -> V_77 , V_66 -> V_83 ) ;
F_118 ( V_19 , V_66 -> V_77 ,
V_66 -> V_84 ) ;
break;
case V_81 :
V_134 -- ;
break;
case V_93 :
V_135 = F_123 ( V_66 -> V_77 ) ;
V_136 = F_123 ( V_66 -> V_92 . V_86 ) ;
F_124 ( V_19 , V_135 , V_136 ,
V_66 -> V_92 . V_88 * V_137 ) ;
break;
case V_101 :
break;
}
V_63 = F_66 ( & V_66 -> V_20 ) ;
if ( ! V_63 )
break;
V_66 = F_67 ( V_63 , struct V_65 , V_20 ) ;
if ( V_66 -> V_73 != V_133 -> V_73 )
break;
}
F_52 ( V_23 ) ;
F_125 ( V_19 , V_134 ) ;
}
static struct V_13 *
F_126 ( struct V_22 * V_23 , struct V_1 * V_139 ,
struct V_13 * V_19 , T_2 V_130 )
{
struct V_13 * V_140 ;
struct V_65 * V_66 ;
if ( ! V_130 )
return V_19 ;
if ( F_33 ( V_19 ) == 0 )
return V_19 ;
V_66 = F_92 ( V_23 , V_19 -> V_46 , V_130 ) ;
if ( ! V_66 )
return V_19 ;
F_3 ( V_139 ) ;
F_4 ( V_19 , V_9 ) ;
if ( V_66 -> V_79 == V_100 ) {
F_90 ( V_66 -> V_77 != 0 ) ;
V_140 = F_127 ( V_23 , V_19 -> V_46 ) ;
if ( ! V_140 ) {
F_128 ( V_19 ) ;
F_11 ( V_19 ) ;
return NULL ;
}
F_40 ( V_140 , V_19 -> V_46 ) ;
F_42 ( V_140 ,
F_102 ( V_19 ) ) ;
F_45 ( V_140 , F_106 ( V_19 ) ) ;
F_129 ( V_140 , F_33 ( V_19 ) ) ;
} else {
V_140 = F_130 ( V_19 ) ;
if ( ! V_140 ) {
F_128 ( V_19 ) ;
F_11 ( V_19 ) ;
return NULL ;
}
}
F_5 ( V_139 , NULL , V_9 ) ;
F_128 ( V_19 ) ;
F_11 ( V_19 ) ;
F_114 ( V_140 ) ;
F_22 ( V_140 ) ;
F_121 ( V_23 , V_140 , V_130 , V_66 ) ;
F_32 ( F_88 ( V_140 ) >
F_131 ( V_23 ) ) ;
return V_140 ;
}
static inline struct V_13 *
F_132 ( struct V_17 * V_18 , T_2 V_130 )
{
struct V_22 * V_23 = V_18 -> V_23 ;
struct V_65 * V_66 ;
struct V_13 * V_19 = NULL ;
struct V_13 * V_129 ;
struct V_13 * V_141 ;
struct V_142 * V_97 = NULL ;
T_2 V_143 = 0 ;
T_2 V_73 ;
V_129 = F_21 ( V_18 ) ;
V_66 = F_120 ( V_23 , V_129 , V_130 ) ;
if ( ! V_66 )
return V_129 ;
if ( V_66 -> V_79 == V_101 ) {
V_97 = & V_66 -> V_97 ;
V_143 = V_66 -> V_84 ;
V_73 = V_97 -> V_73 ;
} else {
V_73 = V_129 -> V_46 ;
}
V_66 = F_92 ( V_23 , V_73 , V_130 ) ;
if ( V_97 && V_66 && V_66 -> V_79 != V_100 ) {
F_23 ( V_129 ) ;
F_11 ( V_129 ) ;
V_141 = F_133 ( V_23 , V_73 , 0 ) ;
if ( F_32 ( F_37 ( V_141 ) || ! F_134 ( V_141 ) ) ) {
if ( ! F_37 ( V_141 ) )
F_11 ( V_141 ) ;
F_135 ( V_23 ,
L_1 ,
V_73 ) ;
} else {
V_19 = F_130 ( V_141 ) ;
F_11 ( V_141 ) ;
}
} else if ( V_97 ) {
F_23 ( V_129 ) ;
F_11 ( V_129 ) ;
V_19 = F_127 ( V_23 , V_73 ) ;
} else {
F_4 ( V_129 , V_9 ) ;
V_19 = F_130 ( V_129 ) ;
F_128 ( V_129 ) ;
F_11 ( V_129 ) ;
}
if ( ! V_19 )
return NULL ;
F_114 ( V_19 ) ;
F_22 ( V_19 ) ;
if ( V_97 ) {
F_40 ( V_19 , V_19 -> V_46 ) ;
F_42 ( V_19 , V_47 ) ;
F_45 ( V_19 , F_106 ( V_129 ) ) ;
F_129 ( V_19 , V_97 -> V_39 ) ;
F_41 ( V_19 , V_143 ) ;
}
if ( V_66 )
F_121 ( V_23 , V_19 , V_130 , V_66 ) ;
else
F_32 ( F_33 ( V_19 ) != 0 ) ;
F_32 ( F_88 ( V_19 ) > F_131 ( V_23 ) ) ;
return V_19 ;
}
int F_136 ( struct V_17 * V_18 , T_2 V_130 )
{
struct V_65 * V_66 ;
int V_39 ;
struct V_13 * V_129 = F_12 ( V_18 ) ;
V_66 = F_120 ( V_18 -> V_23 , V_129 , V_130 ) ;
if ( V_66 && V_66 -> V_79 == V_101 ) {
V_39 = V_66 -> V_97 . V_39 ;
} else {
V_39 = F_33 ( V_129 ) ;
}
F_11 ( V_129 ) ;
return V_39 ;
}
static inline int F_137 ( struct V_32 * V_33 ,
struct V_17 * V_18 ,
struct V_13 * V_34 )
{
if ( F_138 ( V_18 -> V_23 ) )
return 0 ;
F_139 () ;
if ( F_47 ( V_34 ) == V_33 -> V_43 &&
! F_100 ( V_34 , V_48 ) &&
! ( V_18 -> V_121 . V_28 != V_50 &&
F_100 ( V_34 , V_49 ) ) &&
! F_25 ( V_144 , & V_18 -> V_25 ) )
return 0 ;
return 1 ;
}
T_1 int F_140 ( struct V_32 * V_33 ,
struct V_17 * V_18 , struct V_13 * V_34 ,
struct V_13 * V_71 , int V_124 ,
struct V_13 * * V_35 )
{
struct V_22 * V_23 = V_18 -> V_23 ;
T_2 V_125 ;
int V_38 ;
if ( V_33 -> V_145 != V_23 -> V_44 )
F_141 ( 1 , V_146 L_2 ,
V_33 -> V_43 ,
V_23 -> V_44 -> V_43 ) ;
if ( V_33 -> V_43 != V_23 -> V_84 )
F_141 ( 1 , V_146 L_2 ,
V_33 -> V_43 , V_23 -> V_84 ) ;
if ( ! F_137 ( V_33 , V_18 , V_34 ) ) {
V_33 -> V_147 = true ;
* V_35 = V_34 ;
return 0 ;
}
V_125 = V_34 -> V_46 & ~ ( ( T_2 ) V_148 - 1 ) ;
if ( V_71 )
F_142 ( V_71 ) ;
F_142 ( V_34 ) ;
V_38 = F_110 ( V_33 , V_18 , V_34 , V_71 ,
V_124 , V_35 , V_125 , 0 ) ;
F_143 ( V_18 , V_34 , * V_35 ) ;
return V_38 ;
}
static int F_144 ( T_2 V_149 , T_2 V_150 , T_4 V_151 )
{
if ( V_149 < V_150 && V_150 - ( V_149 + V_151 ) < 32768 )
return 1 ;
if ( V_149 > V_150 && V_149 - ( V_150 + V_151 ) < 32768 )
return 1 ;
return 0 ;
}
static int F_145 ( const struct V_40 * V_152 ,
const struct V_153 * V_154 )
{
struct V_153 V_155 ;
F_146 ( & V_155 , V_152 ) ;
return F_147 ( & V_155 , V_154 ) ;
}
int F_147 ( const struct V_153 * V_155 , const struct V_153 * V_154 )
{
if ( V_155 -> V_28 > V_154 -> V_28 )
return 1 ;
if ( V_155 -> V_28 < V_154 -> V_28 )
return - 1 ;
if ( V_155 -> type > V_154 -> type )
return 1 ;
if ( V_155 -> type < V_154 -> type )
return - 1 ;
if ( V_155 -> V_156 > V_154 -> V_156 )
return 1 ;
if ( V_155 -> V_156 < V_154 -> V_156 )
return - 1 ;
return 0 ;
}
int F_148 ( struct V_32 * V_33 ,
struct V_17 * V_18 , struct V_13 * V_71 ,
int V_157 , T_2 * V_158 ,
struct V_153 * V_159 )
{
struct V_22 * V_23 = V_18 -> V_23 ;
struct V_13 * V_72 ;
T_2 V_149 ;
T_2 V_160 ;
T_2 V_125 = * V_158 ;
T_2 V_161 = 0 ;
T_2 V_150 ;
T_4 V_162 ;
int V_163 ;
int V_5 ;
int V_164 = 0 ;
int V_165 ;
int V_166 ;
T_4 V_151 ;
int V_167 = 0 ;
struct V_40 V_41 ;
V_165 = F_33 ( V_71 ) ;
F_32 ( V_33 -> V_145 != V_23 -> V_44 ) ;
F_32 ( V_33 -> V_43 != V_23 -> V_84 ) ;
V_162 = F_88 ( V_71 ) ;
V_151 = V_23 -> V_168 ;
V_163 = V_162 - 1 ;
if ( V_162 <= 1 )
return 0 ;
F_142 ( V_71 ) ;
for ( V_5 = V_157 ; V_5 <= V_163 ; V_5 ++ ) {
int V_169 = 1 ;
F_35 ( V_71 , & V_41 , V_5 ) ;
if ( ! V_167 && F_145 ( & V_41 , V_159 ) < 0 )
continue;
V_167 = 1 ;
V_149 = F_79 ( V_71 , V_5 ) ;
V_160 = F_80 ( V_71 , V_5 ) ;
if ( V_161 == 0 )
V_161 = V_149 ;
if ( V_5 > 0 ) {
V_150 = F_79 ( V_71 , V_5 - 1 ) ;
V_169 = F_144 ( V_149 , V_150 , V_151 ) ;
}
if ( ! V_169 && V_5 < V_163 ) {
V_150 = F_79 ( V_71 , V_5 + 1 ) ;
V_169 = F_144 ( V_149 , V_150 , V_151 ) ;
}
if ( V_169 ) {
V_161 = V_149 ;
continue;
}
V_72 = F_149 ( V_23 , V_149 ) ;
if ( V_72 )
V_166 = F_150 ( V_72 , V_160 , 0 ) ;
else
V_166 = 0 ;
if ( ! V_72 || ! V_166 ) {
if ( ! V_72 ) {
V_72 = F_133 ( V_23 , V_149 , V_160 ) ;
if ( F_37 ( V_72 ) ) {
return F_38 ( V_72 ) ;
} else if ( ! F_134 ( V_72 ) ) {
F_11 ( V_72 ) ;
return - V_170 ;
}
} else if ( ! V_166 ) {
V_164 = F_151 ( V_72 , V_160 ) ;
if ( V_164 ) {
F_11 ( V_72 ) ;
return V_164 ;
}
}
}
if ( V_125 == 0 )
V_125 = V_161 ;
F_19 ( V_72 ) ;
F_142 ( V_72 ) ;
V_164 = F_110 ( V_33 , V_18 , V_72 , V_71 , V_5 ,
& V_72 , V_125 ,
F_152 ( 16 * V_151 ,
( V_163 - V_5 ) * V_151 ) ) ;
if ( V_164 ) {
F_20 ( V_72 ) ;
F_11 ( V_72 ) ;
break;
}
V_125 = V_72 -> V_46 ;
V_161 = V_72 -> V_46 ;
* V_158 = V_125 ;
F_20 ( V_72 ) ;
F_11 ( V_72 ) ;
}
return V_164 ;
}
static T_1 int F_153 ( struct V_13 * V_19 ,
unsigned long V_4 , int V_171 ,
const struct V_153 * V_82 ,
int V_172 , int * V_77 )
{
int V_173 = 0 ;
int V_174 = V_172 ;
int V_175 ;
int V_38 ;
struct V_40 * V_176 = NULL ;
struct V_40 V_177 ;
unsigned long V_156 ;
char * V_178 = NULL ;
unsigned long V_179 = 0 ;
unsigned long V_180 = 0 ;
int V_164 ;
if ( V_173 > V_174 ) {
F_154 ( V_19 -> V_23 ,
L_3 ,
V_181 , V_173 , V_174 , V_19 -> V_46 ,
F_106 ( V_19 ) , F_33 ( V_19 ) ) ;
return - V_182 ;
}
while ( V_173 < V_174 ) {
V_175 = ( V_173 + V_174 ) / 2 ;
V_156 = V_4 + V_175 * V_171 ;
if ( ! V_178 || V_156 < V_179 ||
( V_156 + sizeof( struct V_40 ) ) >
V_179 + V_180 ) {
V_164 = F_155 ( V_19 , V_156 ,
sizeof( struct V_40 ) ,
& V_178 , & V_179 , & V_180 ) ;
if ( ! V_164 ) {
V_176 = (struct V_40 * ) ( V_178 + V_156 -
V_179 ) ;
} else if ( V_164 == 1 ) {
F_156 ( V_19 , & V_177 ,
V_156 , sizeof( V_177 ) ) ;
V_176 = & V_177 ;
} else {
return V_164 ;
}
} else {
V_176 = (struct V_40 * ) ( V_178 + V_156 -
V_179 ) ;
}
V_38 = F_145 ( V_176 , V_82 ) ;
if ( V_38 < 0 )
V_173 = V_175 + 1 ;
else if ( V_38 > 0 )
V_174 = V_175 ;
else {
* V_77 = V_175 ;
return 0 ;
}
}
* V_77 = V_173 ;
return 1 ;
}
static int F_157 ( struct V_13 * V_19 , const struct V_153 * V_82 ,
int V_39 , int * V_77 )
{
if ( V_39 == 0 )
return F_153 ( V_19 ,
F_158 ( struct V_183 , V_184 ) ,
sizeof( struct V_185 ) ,
V_82 , F_88 ( V_19 ) ,
V_77 ) ;
else
return F_153 ( V_19 ,
F_158 ( struct V_186 , V_187 ) ,
sizeof( struct V_138 ) ,
V_82 , F_88 ( V_19 ) ,
V_77 ) ;
}
int F_159 ( struct V_13 * V_19 , const struct V_153 * V_82 ,
int V_39 , int * V_77 )
{
return F_157 ( V_19 , V_82 , V_39 , V_77 ) ;
}
static void F_160 ( struct V_17 * V_18 , T_4 V_188 )
{
F_26 ( & V_18 -> V_189 ) ;
F_161 ( & V_18 -> V_116 ,
F_162 ( & V_18 -> V_116 ) + V_188 ) ;
F_30 ( & V_18 -> V_189 ) ;
}
static void F_163 ( struct V_17 * V_18 , T_4 V_188 )
{
F_26 ( & V_18 -> V_189 ) ;
F_161 ( & V_18 -> V_116 ,
F_162 ( & V_18 -> V_116 ) - V_188 ) ;
F_30 ( & V_18 -> V_189 ) ;
}
T_1 int F_164 ( struct V_32 * V_33 ,
struct V_17 * V_18 ,
struct V_1 * V_139 , int V_39 )
{
struct V_22 * V_23 = V_18 -> V_23 ;
struct V_13 * V_190 = NULL ;
struct V_13 * V_175 ;
struct V_13 * V_191 = NULL ;
struct V_13 * V_71 = NULL ;
int V_38 = 0 ;
int V_192 ;
int V_193 ;
int V_194 = V_139 -> V_16 [ V_39 ] ;
T_2 V_195 ;
if ( V_39 == 0 )
return 0 ;
V_175 = V_139 -> V_7 [ V_39 ] ;
F_32 ( V_139 -> V_8 [ V_39 ] != V_11 &&
V_139 -> V_8 [ V_39 ] != V_12 ) ;
F_32 ( F_47 ( V_175 ) != V_33 -> V_43 ) ;
V_195 = F_79 ( V_175 , V_194 ) ;
if ( V_39 < V_6 - 1 ) {
V_71 = V_139 -> V_7 [ V_39 + 1 ] ;
V_193 = V_139 -> V_16 [ V_39 + 1 ] ;
}
if ( ! V_71 ) {
struct V_13 * V_196 ;
if ( F_88 ( V_175 ) != 1 )
return 0 ;
V_196 = F_165 ( V_23 , V_175 , 0 ) ;
if ( F_37 ( V_196 ) ) {
V_38 = F_38 ( V_196 ) ;
F_105 ( V_23 , V_38 , NULL ) ;
goto V_197;
}
F_19 ( V_196 ) ;
F_142 ( V_196 ) ;
V_38 = F_140 ( V_33 , V_18 , V_196 , V_175 , 0 , & V_196 ) ;
if ( V_38 ) {
F_20 ( V_196 ) ;
F_11 ( V_196 ) ;
goto V_197;
}
F_97 ( V_18 , V_196 , 1 ) ;
F_115 ( V_18 -> V_20 , V_196 ) ;
F_24 ( V_18 ) ;
F_20 ( V_196 ) ;
V_139 -> V_8 [ V_39 ] = 0 ;
V_139 -> V_7 [ V_39 ] = NULL ;
F_109 ( V_23 , V_175 ) ;
F_20 ( V_175 ) ;
F_11 ( V_175 ) ;
F_163 ( V_18 , V_175 -> V_123 ) ;
F_116 ( V_33 , V_18 , V_175 , 0 , 1 ) ;
F_119 ( V_175 ) ;
return 0 ;
}
if ( F_88 ( V_175 ) >
F_131 ( V_23 ) / 4 )
return 0 ;
V_191 = F_165 ( V_23 , V_71 , V_193 - 1 ) ;
if ( F_37 ( V_191 ) )
V_191 = NULL ;
if ( V_191 ) {
F_19 ( V_191 ) ;
F_142 ( V_191 ) ;
V_192 = F_140 ( V_33 , V_18 , V_191 ,
V_71 , V_193 - 1 , & V_191 ) ;
if ( V_192 ) {
V_38 = V_192 ;
goto V_197;
}
}
V_190 = F_165 ( V_23 , V_71 , V_193 + 1 ) ;
if ( F_37 ( V_190 ) )
V_190 = NULL ;
if ( V_190 ) {
F_19 ( V_190 ) ;
F_142 ( V_190 ) ;
V_192 = F_140 ( V_33 , V_18 , V_190 ,
V_71 , V_193 + 1 , & V_190 ) ;
if ( V_192 ) {
V_38 = V_192 ;
goto V_197;
}
}
if ( V_191 ) {
V_194 += F_88 ( V_191 ) ;
V_192 = F_166 ( V_33 , V_23 , V_191 , V_175 , 1 ) ;
if ( V_192 < 0 )
V_38 = V_192 ;
}
if ( V_190 ) {
V_192 = F_166 ( V_33 , V_23 , V_175 , V_190 , 1 ) ;
if ( V_192 < 0 && V_192 != - V_198 )
V_38 = V_192 ;
if ( F_88 ( V_190 ) == 0 ) {
F_109 ( V_23 , V_190 ) ;
F_20 ( V_190 ) ;
F_167 ( V_18 , V_139 , V_39 + 1 , V_193 + 1 ) ;
F_163 ( V_18 , V_190 -> V_123 ) ;
F_116 ( V_33 , V_18 , V_190 , 0 , 1 ) ;
F_119 ( V_190 ) ;
V_190 = NULL ;
} else {
struct V_40 V_199 ;
F_35 ( V_190 , & V_199 , 0 ) ;
F_95 ( V_23 , V_71 ,
V_193 + 1 , 0 ) ;
F_122 ( V_71 , & V_199 , V_193 + 1 ) ;
F_49 ( V_71 ) ;
}
}
if ( F_88 ( V_175 ) == 1 ) {
if ( ! V_191 ) {
V_38 = - V_120 ;
F_105 ( V_23 , V_38 , NULL ) ;
goto V_197;
}
V_192 = F_168 ( V_33 , V_23 , V_175 , V_191 ) ;
if ( V_192 < 0 ) {
V_38 = V_192 ;
goto V_197;
}
if ( V_192 == 1 ) {
V_192 = F_166 ( V_33 , V_23 , V_191 , V_175 , 1 ) ;
if ( V_192 < 0 )
V_38 = V_192 ;
}
F_90 ( V_192 == 1 ) ;
}
if ( F_88 ( V_175 ) == 0 ) {
F_109 ( V_23 , V_175 ) ;
F_20 ( V_175 ) ;
F_167 ( V_18 , V_139 , V_39 + 1 , V_193 ) ;
F_163 ( V_18 , V_175 -> V_123 ) ;
F_116 ( V_33 , V_18 , V_175 , 0 , 1 ) ;
F_119 ( V_175 ) ;
V_175 = NULL ;
} else {
struct V_40 V_200 ;
F_35 ( V_175 , & V_200 , 0 ) ;
F_95 ( V_23 , V_71 , V_193 , 0 ) ;
F_122 ( V_71 , & V_200 , V_193 ) ;
F_49 ( V_71 ) ;
}
if ( V_191 ) {
if ( F_88 ( V_191 ) > V_194 ) {
F_114 ( V_191 ) ;
V_139 -> V_7 [ V_39 ] = V_191 ;
V_139 -> V_16 [ V_39 + 1 ] -= 1 ;
V_139 -> V_16 [ V_39 ] = V_194 ;
if ( V_175 ) {
F_20 ( V_175 ) ;
F_11 ( V_175 ) ;
}
} else {
V_194 -= F_88 ( V_191 ) ;
V_139 -> V_16 [ V_39 ] = V_194 ;
}
}
if ( V_195 !=
F_79 ( V_139 -> V_7 [ V_39 ] , V_139 -> V_16 [ V_39 ] ) )
F_169 () ;
V_197:
if ( V_190 ) {
F_20 ( V_190 ) ;
F_11 ( V_190 ) ;
}
if ( V_191 ) {
if ( V_139 -> V_7 [ V_39 ] != V_191 )
F_20 ( V_191 ) ;
F_11 ( V_191 ) ;
}
return V_38 ;
}
static T_1 int F_170 ( struct V_32 * V_33 ,
struct V_17 * V_18 ,
struct V_1 * V_139 , int V_39 )
{
struct V_22 * V_23 = V_18 -> V_23 ;
struct V_13 * V_190 = NULL ;
struct V_13 * V_175 ;
struct V_13 * V_191 = NULL ;
struct V_13 * V_71 = NULL ;
int V_38 = 0 ;
int V_192 ;
int V_193 ;
int V_194 = V_139 -> V_16 [ V_39 ] ;
if ( V_39 == 0 )
return 1 ;
V_175 = V_139 -> V_7 [ V_39 ] ;
F_32 ( F_47 ( V_175 ) != V_33 -> V_43 ) ;
if ( V_39 < V_6 - 1 ) {
V_71 = V_139 -> V_7 [ V_39 + 1 ] ;
V_193 = V_139 -> V_16 [ V_39 + 1 ] ;
}
if ( ! V_71 )
return 1 ;
V_191 = F_165 ( V_23 , V_71 , V_193 - 1 ) ;
if ( F_37 ( V_191 ) )
V_191 = NULL ;
if ( V_191 ) {
T_4 V_201 ;
F_19 ( V_191 ) ;
F_142 ( V_191 ) ;
V_201 = F_88 ( V_191 ) ;
if ( V_201 >= F_131 ( V_23 ) - 1 ) {
V_192 = 1 ;
} else {
V_38 = F_140 ( V_33 , V_18 , V_191 , V_71 ,
V_193 - 1 , & V_191 ) ;
if ( V_38 )
V_192 = 1 ;
else {
V_192 = F_166 ( V_33 , V_23 ,
V_191 , V_175 , 0 ) ;
}
}
if ( V_192 < 0 )
V_38 = V_192 ;
if ( V_192 == 0 ) {
struct V_40 V_41 ;
V_194 += V_201 ;
F_35 ( V_175 , & V_41 , 0 ) ;
F_95 ( V_23 , V_71 , V_193 , 0 ) ;
F_122 ( V_71 , & V_41 , V_193 ) ;
F_49 ( V_71 ) ;
if ( F_88 ( V_191 ) > V_194 ) {
V_139 -> V_7 [ V_39 ] = V_191 ;
V_139 -> V_16 [ V_39 + 1 ] -= 1 ;
V_139 -> V_16 [ V_39 ] = V_194 ;
F_20 ( V_175 ) ;
F_11 ( V_175 ) ;
} else {
V_194 -=
F_88 ( V_191 ) ;
V_139 -> V_16 [ V_39 ] = V_194 ;
F_20 ( V_191 ) ;
F_11 ( V_191 ) ;
}
return 0 ;
}
F_20 ( V_191 ) ;
F_11 ( V_191 ) ;
}
V_190 = F_165 ( V_23 , V_71 , V_193 + 1 ) ;
if ( F_37 ( V_190 ) )
V_190 = NULL ;
if ( V_190 ) {
T_4 V_202 ;
F_19 ( V_190 ) ;
F_142 ( V_190 ) ;
V_202 = F_88 ( V_190 ) ;
if ( V_202 >= F_131 ( V_23 ) - 1 ) {
V_192 = 1 ;
} else {
V_38 = F_140 ( V_33 , V_18 , V_190 ,
V_71 , V_193 + 1 ,
& V_190 ) ;
if ( V_38 )
V_192 = 1 ;
else {
V_192 = F_168 ( V_33 , V_23 ,
V_190 , V_175 ) ;
}
}
if ( V_192 < 0 )
V_38 = V_192 ;
if ( V_192 == 0 ) {
struct V_40 V_41 ;
F_35 ( V_190 , & V_41 , 0 ) ;
F_95 ( V_23 , V_71 ,
V_193 + 1 , 0 ) ;
F_122 ( V_71 , & V_41 , V_193 + 1 ) ;
F_49 ( V_71 ) ;
if ( F_88 ( V_175 ) <= V_194 ) {
V_139 -> V_7 [ V_39 ] = V_190 ;
V_139 -> V_16 [ V_39 + 1 ] += 1 ;
V_139 -> V_16 [ V_39 ] = V_194 -
F_88 ( V_175 ) ;
F_20 ( V_175 ) ;
F_11 ( V_175 ) ;
} else {
F_20 ( V_190 ) ;
F_11 ( V_190 ) ;
}
return 0 ;
}
F_20 ( V_190 ) ;
F_11 ( V_190 ) ;
}
return 1 ;
}
static void F_171 ( struct V_22 * V_23 ,
struct V_1 * V_139 ,
int V_39 , int V_77 , T_2 V_28 )
{
struct V_13 * V_20 ;
struct V_40 V_41 ;
T_4 V_95 ;
T_2 V_203 ;
T_2 V_204 ;
T_2 V_205 = 0 ;
struct V_13 * V_19 ;
T_4 V_206 ;
T_4 V_151 ;
T_4 V_207 = 0 ;
if ( V_39 != 1 )
return;
if ( ! V_139 -> V_7 [ V_39 ] )
return;
V_20 = V_139 -> V_7 [ V_39 ] ;
V_203 = F_79 ( V_20 , V_77 ) ;
V_151 = V_23 -> V_168 ;
V_19 = F_149 ( V_23 , V_203 ) ;
if ( V_19 ) {
F_11 ( V_19 ) ;
return;
}
V_204 = V_203 ;
V_95 = F_88 ( V_20 ) ;
V_206 = V_77 ;
while ( 1 ) {
if ( V_139 -> V_208 == V_209 ) {
if ( V_206 == 0 )
break;
V_206 -- ;
} else if ( V_139 -> V_208 == V_210 ) {
V_206 ++ ;
if ( V_206 >= V_95 )
break;
}
if ( V_139 -> V_208 == V_209 && V_28 ) {
F_35 ( V_20 , & V_41 , V_206 ) ;
if ( F_172 ( & V_41 ) != V_28 )
break;
}
V_203 = F_79 ( V_20 , V_206 ) ;
if ( ( V_203 <= V_204 && V_204 - V_203 <= 65536 ) ||
( V_203 > V_204 && V_203 - V_204 <= 65536 ) ) {
F_173 ( V_23 , V_203 ) ;
V_205 += V_151 ;
}
V_207 ++ ;
if ( ( V_205 > 65536 || V_207 > 32 ) )
break;
}
}
static T_1 void F_174 ( struct V_22 * V_23 ,
struct V_1 * V_139 , int V_39 )
{
int V_77 ;
int V_95 ;
struct V_13 * V_71 ;
struct V_13 * V_19 ;
T_2 V_160 ;
T_2 V_211 = 0 ;
T_2 V_212 = 0 ;
V_71 = V_139 -> V_7 [ V_39 + 1 ] ;
if ( ! V_71 )
return;
V_95 = F_88 ( V_71 ) ;
V_77 = V_139 -> V_16 [ V_39 + 1 ] ;
if ( V_77 > 0 ) {
V_211 = F_79 ( V_71 , V_77 - 1 ) ;
V_160 = F_80 ( V_71 , V_77 - 1 ) ;
V_19 = F_149 ( V_23 , V_211 ) ;
if ( V_19 && F_150 ( V_19 , V_160 , 1 ) != 0 )
V_211 = 0 ;
F_11 ( V_19 ) ;
}
if ( V_77 + 1 < V_95 ) {
V_212 = F_79 ( V_71 , V_77 + 1 ) ;
V_160 = F_80 ( V_71 , V_77 + 1 ) ;
V_19 = F_149 ( V_23 , V_212 ) ;
if ( V_19 && F_150 ( V_19 , V_160 , 1 ) != 0 )
V_212 = 0 ;
F_11 ( V_19 ) ;
}
if ( V_211 )
F_173 ( V_23 , V_211 ) ;
if ( V_212 )
F_173 ( V_23 , V_212 ) ;
}
static T_1 void F_175 ( struct V_1 * V_139 , int V_39 ,
int V_213 , int V_214 ,
int * V_215 )
{
int V_5 ;
int V_216 = V_39 ;
int V_217 = 0 ;
struct V_13 * V_218 ;
for ( V_5 = V_39 ; V_5 < V_6 ; V_5 ++ ) {
if ( ! V_139 -> V_7 [ V_5 ] )
break;
if ( ! V_139 -> V_8 [ V_5 ] )
break;
if ( ! V_217 && V_139 -> V_16 [ V_5 ] == 0 ) {
V_216 = V_5 + 1 ;
continue;
}
if ( ! V_217 && V_139 -> V_219 ) {
T_4 V_95 ;
V_218 = V_139 -> V_7 [ V_5 ] ;
V_95 = F_88 ( V_218 ) ;
if ( V_95 < 1 || V_139 -> V_16 [ V_5 ] >= V_95 - 1 ) {
V_216 = V_5 + 1 ;
continue;
}
}
if ( V_216 < V_5 && V_5 >= V_213 )
V_217 = 1 ;
V_218 = V_139 -> V_7 [ V_5 ] ;
if ( V_5 >= V_213 && V_5 > V_216 && V_139 -> V_8 [ V_5 ] ) {
F_10 ( V_218 , V_139 -> V_8 [ V_5 ] ) ;
V_139 -> V_8 [ V_5 ] = 0 ;
if ( V_215 &&
V_5 > V_214 &&
V_5 <= * V_215 ) {
* V_215 = V_5 - 1 ;
}
}
}
}
T_1 void F_176 ( struct V_1 * V_139 , int V_39 )
{
int V_5 ;
if ( V_139 -> V_219 )
return;
for ( V_5 = V_39 ; V_5 < V_6 ; V_5 ++ ) {
if ( ! V_139 -> V_7 [ V_5 ] )
continue;
if ( ! V_139 -> V_8 [ V_5 ] )
continue;
F_10 ( V_139 -> V_7 [ V_5 ] , V_139 -> V_8 [ V_5 ] ) ;
V_139 -> V_8 [ V_5 ] = 0 ;
}
}
static int
F_177 ( struct V_17 * V_18 , struct V_1 * V_4 ,
struct V_13 * * V_220 , int V_39 , int V_77 ,
const struct V_153 * V_82 )
{
struct V_22 * V_23 = V_18 -> V_23 ;
T_2 V_149 ;
T_2 V_160 ;
struct V_13 * V_221 = * V_220 ;
struct V_13 * V_176 ;
int V_38 ;
V_149 = F_79 ( V_221 , V_77 ) ;
V_160 = F_80 ( V_221 , V_77 ) ;
V_176 = F_149 ( V_23 , V_149 ) ;
if ( V_176 ) {
if ( F_150 ( V_176 , V_160 , 1 ) > 0 ) {
* V_220 = V_176 ;
return 0 ;
}
F_3 ( V_4 ) ;
V_38 = F_151 ( V_176 , V_160 ) ;
if ( ! V_38 ) {
* V_220 = V_176 ;
return 0 ;
}
F_11 ( V_176 ) ;
F_8 ( V_4 ) ;
return - V_170 ;
}
F_176 ( V_4 , V_39 + 1 ) ;
F_3 ( V_4 ) ;
F_11 ( V_176 ) ;
if ( V_4 -> V_208 != V_222 )
F_171 ( V_23 , V_4 , V_39 , V_77 , V_82 -> V_28 ) ;
F_8 ( V_4 ) ;
V_38 = - V_223 ;
V_176 = F_133 ( V_23 , V_149 , 0 ) ;
if ( ! F_37 ( V_176 ) ) {
if ( ! F_150 ( V_176 , 0 , 0 ) )
V_38 = - V_170 ;
F_11 ( V_176 ) ;
} else {
V_38 = F_38 ( V_176 ) ;
}
return V_38 ;
}
static int
F_178 ( struct V_32 * V_33 ,
struct V_17 * V_18 , struct V_1 * V_4 ,
struct V_13 * V_221 , int V_39 , int V_224 ,
int * V_215 )
{
struct V_22 * V_23 = V_18 -> V_23 ;
int V_38 ;
if ( ( V_4 -> V_225 || V_224 > 0 ) && F_88 ( V_221 ) >=
F_131 ( V_23 ) - 3 ) {
int V_226 ;
if ( * V_215 < V_39 + 1 ) {
* V_215 = V_39 + 1 ;
F_8 ( V_4 ) ;
goto V_227;
}
F_3 ( V_4 ) ;
F_174 ( V_23 , V_4 , V_39 ) ;
V_226 = F_179 ( V_33 , V_18 , V_4 , V_39 ) ;
F_5 ( V_4 , NULL , 0 ) ;
F_90 ( V_226 > 0 ) ;
if ( V_226 ) {
V_38 = V_226 ;
goto V_228;
}
V_221 = V_4 -> V_7 [ V_39 ] ;
} else if ( V_224 < 0 && F_88 ( V_221 ) <
F_131 ( V_23 ) / 2 ) {
int V_226 ;
if ( * V_215 < V_39 + 1 ) {
* V_215 = V_39 + 1 ;
F_8 ( V_4 ) ;
goto V_227;
}
F_3 ( V_4 ) ;
F_174 ( V_23 , V_4 , V_39 ) ;
V_226 = F_164 ( V_33 , V_18 , V_4 , V_39 ) ;
F_5 ( V_4 , NULL , 0 ) ;
if ( V_226 ) {
V_38 = V_226 ;
goto V_228;
}
V_221 = V_4 -> V_7 [ V_39 ] ;
if ( ! V_221 ) {
F_8 ( V_4 ) ;
goto V_227;
}
F_90 ( F_88 ( V_221 ) == 1 ) ;
}
return 0 ;
V_227:
V_38 = - V_223 ;
V_228:
return V_38 ;
}
static void F_180 ( struct V_13 * V_221 ,
const struct V_153 * V_82 ,
int V_39 )
{
#ifdef F_181
struct V_40 V_41 ;
F_182 ( & V_41 , V_82 ) ;
if ( V_39 == 0 )
ASSERT ( ! F_183 ( V_221 , & V_41 ,
F_158 ( struct V_183 , V_184 [ 0 ] . V_82 ) ,
sizeof( V_41 ) ) ) ;
else
ASSERT ( ! F_183 ( V_221 , & V_41 ,
F_158 ( struct V_186 , V_187 [ 0 ] . V_82 ) ,
sizeof( V_41 ) ) ) ;
#endif
}
static int F_184 ( struct V_13 * V_221 , const struct V_153 * V_82 ,
int V_39 , int * V_229 , int * V_77 )
{
if ( * V_229 != 0 ) {
* V_229 = F_157 ( V_221 , V_82 , V_39 , V_77 ) ;
return * V_229 ;
}
F_180 ( V_221 , V_82 , V_39 ) ;
* V_77 = 0 ;
return 0 ;
}
int F_185 ( struct V_17 * V_230 , struct V_1 * V_139 ,
T_2 V_231 , T_2 V_232 , T_5 V_233 ,
struct V_153 * V_234 )
{
int V_38 ;
struct V_153 V_82 ;
struct V_13 * V_19 ;
ASSERT ( V_139 ) ;
ASSERT ( V_234 ) ;
V_82 . type = V_233 ;
V_82 . V_28 = V_231 ;
V_82 . V_156 = V_232 ;
V_38 = F_186 ( NULL , V_230 , & V_82 , V_139 , 0 , 0 ) ;
if ( V_38 < 0 )
return V_38 ;
V_19 = V_139 -> V_7 [ 0 ] ;
if ( V_38 && V_139 -> V_16 [ 0 ] >= F_88 ( V_19 ) ) {
V_38 = F_187 ( V_230 , V_139 ) ;
if ( V_38 )
return V_38 ;
V_19 = V_139 -> V_7 [ 0 ] ;
}
F_188 ( V_19 , V_234 , V_139 -> V_16 [ 0 ] ) ;
if ( V_234 -> type != V_82 . type ||
V_234 -> V_28 != V_82 . V_28 )
return 1 ;
return 0 ;
}
int F_186 ( struct V_32 * V_33 , struct V_17 * V_18 ,
const struct V_153 * V_82 , struct V_1 * V_4 ,
int V_224 , int V_37 )
{
struct V_22 * V_23 = V_18 -> V_23 ;
struct V_13 * V_221 ;
int V_77 ;
int V_38 ;
int V_164 ;
int V_39 ;
int V_213 = 1 ;
int V_235 ;
int V_215 = 0 ;
T_5 V_236 = 0 ;
int V_214 ;
int V_229 ;
V_236 = V_4 -> V_236 ;
F_32 ( V_236 && V_224 > 0 ) ;
F_32 ( V_4 -> V_7 [ 0 ] != NULL ) ;
F_90 ( ! V_37 && V_224 ) ;
if ( V_224 < 0 ) {
V_213 = 2 ;
V_215 = 2 ;
} else if ( V_224 > 0 ) {
V_215 = 1 ;
}
if ( ! V_37 )
V_215 = - 1 ;
if ( V_37 && ( V_4 -> V_219 || V_4 -> V_236 ) )
V_215 = V_6 ;
V_214 = V_215 ;
V_227:
V_229 = - 1 ;
V_235 = V_9 ;
V_39 = 0 ;
if ( V_4 -> V_237 ) {
if ( V_4 -> V_238 )
F_189 ( & V_23 -> V_239 ) ;
V_221 = V_18 -> V_115 ;
F_114 ( V_221 ) ;
V_39 = F_33 ( V_221 ) ;
if ( V_4 -> V_238 )
F_190 ( & V_23 -> V_239 ) ;
if ( ! V_4 -> V_240 )
F_22 ( V_221 ) ;
} else {
if ( V_4 -> V_240 ) {
V_221 = F_12 ( V_18 ) ;
V_39 = F_33 ( V_221 ) ;
} else {
V_221 = F_21 ( V_18 ) ;
V_39 = F_33 ( V_221 ) ;
if ( V_39 <= V_215 ) {
F_23 ( V_221 ) ;
F_11 ( V_221 ) ;
V_221 = F_18 ( V_18 ) ;
V_235 = V_11 ;
V_39 = F_33 ( V_221 ) ;
}
}
}
V_4 -> V_7 [ V_39 ] = V_221 ;
if ( ! V_4 -> V_240 )
V_4 -> V_8 [ V_39 ] = V_235 ;
while ( V_221 ) {
V_39 = F_33 ( V_221 ) ;
if ( V_37 ) {
if ( ! F_137 ( V_33 , V_18 , V_221 ) ) {
V_33 -> V_147 = true ;
goto V_241;
}
if ( V_39 > V_215 ||
( V_39 + 1 > V_215 &&
V_39 + 1 < V_6 &&
V_4 -> V_7 [ V_39 + 1 ] ) ) {
V_215 = V_39 + 1 ;
F_8 ( V_4 ) ;
goto V_227;
}
F_3 ( V_4 ) ;
V_164 = F_140 ( V_33 , V_18 , V_221 ,
V_4 -> V_7 [ V_39 + 1 ] ,
V_4 -> V_16 [ V_39 + 1 ] , & V_221 ) ;
if ( V_164 ) {
V_38 = V_164 ;
goto V_228;
}
}
V_241:
V_4 -> V_7 [ V_39 ] = V_221 ;
F_5 ( V_4 , NULL , 0 ) ;
if ( ! V_224 && ! V_4 -> V_219 ) {
int V_242 = V_39 + 1 ;
if ( V_242 < V_6 && V_4 -> V_8 [ V_242 ] ) {
F_10 ( V_4 -> V_7 [ V_242 ] , V_4 -> V_8 [ V_242 ] ) ;
V_4 -> V_8 [ V_242 ] = 0 ;
}
}
V_38 = F_184 ( V_221 , V_82 , V_39 , & V_229 , & V_77 ) ;
if ( V_38 < 0 )
goto V_228;
if ( V_39 != 0 ) {
int V_243 = 0 ;
if ( V_38 && V_77 > 0 ) {
V_243 = 1 ;
V_77 -= 1 ;
}
V_4 -> V_16 [ V_39 ] = V_77 ;
V_164 = F_178 ( V_33 , V_18 , V_4 , V_221 , V_39 ,
V_224 , & V_215 ) ;
if ( V_164 == - V_223 )
goto V_227;
if ( V_164 ) {
V_38 = V_164 ;
goto V_228;
}
V_221 = V_4 -> V_7 [ V_39 ] ;
V_77 = V_4 -> V_16 [ V_39 ] ;
if ( V_77 == 0 && V_224 &&
V_215 < V_39 + 1 ) {
V_215 = V_39 + 1 ;
F_8 ( V_4 ) ;
goto V_227;
}
F_175 ( V_4 , V_39 , V_213 ,
V_214 , & V_215 ) ;
if ( V_39 == V_236 ) {
if ( V_243 )
V_4 -> V_16 [ V_39 ] ++ ;
goto V_228;
}
V_164 = F_177 ( V_18 , V_4 , & V_221 , V_39 ,
V_77 , V_82 ) ;
if ( V_164 == - V_223 )
goto V_227;
if ( V_164 ) {
V_38 = V_164 ;
goto V_228;
}
if ( ! V_4 -> V_240 ) {
V_39 = F_33 ( V_221 ) ;
if ( V_39 <= V_215 ) {
V_164 = F_191 ( V_221 ) ;
if ( ! V_164 ) {
F_3 ( V_4 ) ;
F_19 ( V_221 ) ;
F_5 ( V_4 , V_221 ,
V_11 ) ;
}
V_4 -> V_8 [ V_39 ] = V_11 ;
} else {
V_164 = F_192 ( V_221 ) ;
if ( ! V_164 ) {
F_3 ( V_4 ) ;
F_22 ( V_221 ) ;
F_5 ( V_4 , V_221 ,
V_9 ) ;
}
V_4 -> V_8 [ V_39 ] = V_9 ;
}
V_4 -> V_7 [ V_39 ] = V_221 ;
}
} else {
V_4 -> V_16 [ V_39 ] = V_77 ;
if ( V_224 > 0 &&
F_193 ( V_23 , V_221 ) < V_224 ) {
if ( V_215 < 1 ) {
V_215 = 1 ;
F_8 ( V_4 ) ;
goto V_227;
}
F_3 ( V_4 ) ;
V_164 = F_194 ( V_33 , V_18 , V_82 ,
V_4 , V_224 , V_38 == 0 ) ;
F_5 ( V_4 , NULL , 0 ) ;
F_90 ( V_164 > 0 ) ;
if ( V_164 ) {
V_38 = V_164 ;
goto V_228;
}
}
if ( ! V_4 -> V_225 )
F_175 ( V_4 , V_39 , V_213 ,
V_214 , & V_215 ) ;
goto V_228;
}
}
V_38 = 1 ;
V_228:
if ( ! V_4 -> V_244 )
F_3 ( V_4 ) ;
if ( V_38 < 0 && ! V_4 -> V_245 )
F_8 ( V_4 ) ;
return V_38 ;
}
int F_195 ( struct V_17 * V_18 , const struct V_153 * V_82 ,
struct V_1 * V_4 , T_2 V_130 )
{
struct V_22 * V_23 = V_18 -> V_23 ;
struct V_13 * V_221 ;
int V_77 ;
int V_38 ;
int V_164 ;
int V_39 ;
int V_213 = 1 ;
T_5 V_236 = 0 ;
int V_229 = - 1 ;
V_236 = V_4 -> V_236 ;
F_32 ( V_4 -> V_7 [ 0 ] != NULL ) ;
if ( V_4 -> V_237 ) {
F_90 ( V_130 ) ;
return F_186 ( NULL , V_18 , V_82 , V_4 , 0 , 0 ) ;
}
V_227:
V_221 = F_132 ( V_18 , V_130 ) ;
V_39 = F_33 ( V_221 ) ;
V_4 -> V_8 [ V_39 ] = V_9 ;
while ( V_221 ) {
V_39 = F_33 ( V_221 ) ;
V_4 -> V_7 [ V_39 ] = V_221 ;
F_5 ( V_4 , NULL , 0 ) ;
F_176 ( V_4 , V_39 + 1 ) ;
V_229 = - 1 ;
V_38 = F_184 ( V_221 , V_82 , V_39 , & V_229 , & V_77 ) ;
if ( V_39 != 0 ) {
int V_243 = 0 ;
if ( V_38 && V_77 > 0 ) {
V_243 = 1 ;
V_77 -= 1 ;
}
V_4 -> V_16 [ V_39 ] = V_77 ;
F_175 ( V_4 , V_39 , V_213 , 0 , NULL ) ;
if ( V_39 == V_236 ) {
if ( V_243 )
V_4 -> V_16 [ V_39 ] ++ ;
goto V_228;
}
V_164 = F_177 ( V_18 , V_4 , & V_221 , V_39 ,
V_77 , V_82 ) ;
if ( V_164 == - V_223 )
goto V_227;
if ( V_164 ) {
V_38 = V_164 ;
goto V_228;
}
V_39 = F_33 ( V_221 ) ;
V_164 = F_192 ( V_221 ) ;
if ( ! V_164 ) {
F_3 ( V_4 ) ;
F_22 ( V_221 ) ;
F_5 ( V_4 , V_221 ,
V_9 ) ;
}
V_221 = F_126 ( V_23 , V_4 , V_221 , V_130 ) ;
if ( ! V_221 ) {
V_38 = - V_85 ;
goto V_228;
}
V_4 -> V_8 [ V_39 ] = V_9 ;
V_4 -> V_7 [ V_39 ] = V_221 ;
} else {
V_4 -> V_16 [ V_39 ] = V_77 ;
F_175 ( V_4 , V_39 , V_213 , 0 , NULL ) ;
goto V_228;
}
}
V_38 = 1 ;
V_228:
if ( ! V_4 -> V_244 )
F_3 ( V_4 ) ;
if ( V_38 < 0 )
F_8 ( V_4 ) ;
return V_38 ;
}
int F_196 ( struct V_17 * V_18 ,
const struct V_153 * V_82 ,
struct V_1 * V_4 , int V_246 ,
int V_247 )
{
int V_38 ;
struct V_13 * V_248 ;
V_227:
V_38 = F_186 ( NULL , V_18 , V_82 , V_4 , 0 , 0 ) ;
if ( V_38 <= 0 )
return V_38 ;
V_248 = V_4 -> V_7 [ 0 ] ;
if ( V_246 ) {
if ( V_4 -> V_16 [ 0 ] >= F_88 ( V_248 ) ) {
V_38 = F_187 ( V_18 , V_4 ) ;
if ( V_38 <= 0 )
return V_38 ;
if ( ! V_247 )
return 1 ;
V_247 = 0 ;
V_246 = 0 ;
F_8 ( V_4 ) ;
goto V_227;
}
} else {
if ( V_4 -> V_16 [ 0 ] == 0 ) {
V_38 = F_197 ( V_18 , V_4 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( ! V_38 ) {
V_248 = V_4 -> V_7 [ 0 ] ;
if ( V_4 -> V_16 [ 0 ] == F_88 ( V_248 ) )
V_4 -> V_16 [ 0 ] -- ;
return 0 ;
}
if ( ! V_247 )
return 1 ;
V_247 = 0 ;
V_246 = 1 ;
F_8 ( V_4 ) ;
goto V_227;
} else {
-- V_4 -> V_16 [ 0 ] ;
}
}
return 0 ;
}
static void F_198 ( struct V_22 * V_23 ,
struct V_1 * V_139 ,
struct V_40 * V_82 , int V_39 )
{
int V_5 ;
struct V_13 * V_218 ;
for ( V_5 = V_39 ; V_5 < V_6 ; V_5 ++ ) {
int V_249 = V_139 -> V_16 [ V_5 ] ;
if ( ! V_139 -> V_7 [ V_5 ] )
break;
V_218 = V_139 -> V_7 [ V_5 ] ;
F_95 ( V_23 , V_218 , V_249 , 1 ) ;
F_122 ( V_218 , V_82 , V_249 ) ;
F_49 ( V_139 -> V_7 [ V_5 ] ) ;
if ( V_249 != 0 )
break;
}
}
void F_199 ( struct V_22 * V_23 ,
struct V_1 * V_139 ,
const struct V_153 * V_250 )
{
struct V_40 V_41 ;
struct V_13 * V_19 ;
int V_77 ;
V_19 = V_139 -> V_7 [ 0 ] ;
V_77 = V_139 -> V_16 [ 0 ] ;
if ( V_77 > 0 ) {
F_34 ( V_19 , & V_41 , V_77 - 1 ) ;
F_90 ( F_145 ( & V_41 , V_250 ) >= 0 ) ;
}
if ( V_77 < F_88 ( V_19 ) - 1 ) {
F_34 ( V_19 , & V_41 , V_77 + 1 ) ;
F_90 ( F_145 ( & V_41 , V_250 ) <= 0 ) ;
}
F_182 ( & V_41 , V_250 ) ;
F_200 ( V_19 , & V_41 , V_77 ) ;
F_49 ( V_19 ) ;
if ( V_77 == 0 )
F_198 ( V_23 , V_139 , & V_41 , 1 ) ;
}
static int F_166 ( struct V_32 * V_33 ,
struct V_22 * V_23 ,
struct V_13 * V_104 ,
struct V_13 * V_105 , int V_251 )
{
int V_252 = 0 ;
int V_253 ;
int V_254 ;
int V_38 = 0 ;
V_253 = F_88 ( V_105 ) ;
V_254 = F_88 ( V_104 ) ;
V_252 = F_131 ( V_23 ) - V_254 ;
F_32 ( F_47 ( V_105 ) != V_33 -> V_43 ) ;
F_32 ( F_47 ( V_104 ) != V_33 -> V_43 ) ;
if ( ! V_251 && V_253 <= 8 )
return 1 ;
if ( V_252 <= 0 )
return 1 ;
if ( V_251 ) {
V_252 = F_152 ( V_253 , V_252 ) ;
if ( V_252 < V_253 ) {
if ( V_253 - V_252 < 8 ) {
if ( V_252 <= 8 )
return 1 ;
V_252 -= 8 ;
}
}
} else
V_252 = F_152 ( V_253 - 8 , V_252 ) ;
V_38 = F_93 ( V_23 , V_104 , V_105 , V_254 , 0 ,
V_252 ) ;
if ( V_38 ) {
F_112 ( V_33 , V_38 ) ;
return V_38 ;
}
F_201 ( V_104 , V_105 ,
F_123 ( V_254 ) ,
F_123 ( 0 ) ,
V_252 * sizeof( struct V_138 ) ) ;
if ( V_252 < V_253 ) {
F_124 ( V_105 , F_123 ( 0 ) ,
F_123 ( V_252 ) ,
( V_253 - V_252 ) *
sizeof( struct V_138 ) ) ;
}
F_125 ( V_105 , V_253 - V_252 ) ;
F_125 ( V_104 , V_254 + V_252 ) ;
F_49 ( V_105 ) ;
F_49 ( V_104 ) ;
return V_38 ;
}
static int F_168 ( struct V_32 * V_33 ,
struct V_22 * V_23 ,
struct V_13 * V_104 ,
struct V_13 * V_105 )
{
int V_252 = 0 ;
int V_255 ;
int V_253 ;
int V_254 ;
int V_38 = 0 ;
F_32 ( F_47 ( V_105 ) != V_33 -> V_43 ) ;
F_32 ( F_47 ( V_104 ) != V_33 -> V_43 ) ;
V_253 = F_88 ( V_105 ) ;
V_254 = F_88 ( V_104 ) ;
V_252 = F_131 ( V_23 ) - V_254 ;
if ( V_252 <= 0 )
return 1 ;
if ( V_253 < 4 )
return 1 ;
V_255 = V_253 / 2 + 1 ;
if ( V_255 >= V_253 )
return 1 ;
if ( V_255 < V_252 )
V_252 = V_255 ;
F_94 ( V_23 , V_104 , V_252 , 0 , V_254 ) ;
F_124 ( V_104 , F_123 ( V_252 ) ,
F_123 ( 0 ) ,
( V_254 ) *
sizeof( struct V_138 ) ) ;
V_38 = F_93 ( V_23 , V_104 , V_105 , 0 ,
V_253 - V_252 , V_252 ) ;
if ( V_38 ) {
F_112 ( V_33 , V_38 ) ;
return V_38 ;
}
F_201 ( V_104 , V_105 ,
F_123 ( 0 ) ,
F_123 ( V_253 - V_252 ) ,
V_252 * sizeof( struct V_138 ) ) ;
F_125 ( V_105 , V_253 - V_252 ) ;
F_125 ( V_104 , V_254 + V_252 ) ;
F_49 ( V_105 ) ;
F_49 ( V_104 ) ;
return V_38 ;
}
static T_1 int F_202 ( struct V_32 * V_33 ,
struct V_17 * V_18 ,
struct V_1 * V_139 , int V_39 )
{
struct V_22 * V_23 = V_18 -> V_23 ;
T_2 V_256 ;
struct V_13 * V_257 ;
struct V_13 * V_258 ;
struct V_13 * V_141 ;
struct V_40 V_259 ;
F_90 ( V_139 -> V_7 [ V_39 ] ) ;
F_90 ( V_139 -> V_7 [ V_39 - 1 ] != V_18 -> V_20 ) ;
V_257 = V_139 -> V_7 [ V_39 - 1 ] ;
if ( V_39 == 1 )
F_34 ( V_257 , & V_259 , 0 ) ;
else
F_35 ( V_257 , & V_259 , 0 ) ;
V_258 = F_36 ( V_33 , V_18 , 0 , V_18 -> V_121 . V_28 ,
& V_259 , V_39 , V_18 -> V_20 -> V_46 , 0 ) ;
if ( F_37 ( V_258 ) )
return F_38 ( V_258 ) ;
F_160 ( V_18 , V_23 -> V_168 ) ;
F_203 ( V_258 , 0 , sizeof( struct V_260 ) ) ;
F_125 ( V_258 , 1 ) ;
F_129 ( V_258 , V_39 ) ;
F_40 ( V_258 , V_258 -> V_46 ) ;
F_41 ( V_258 , V_33 -> V_43 ) ;
F_42 ( V_258 , V_47 ) ;
F_45 ( V_258 , V_18 -> V_121 . V_28 ) ;
F_46 ( V_258 , V_23 -> V_51 ) ;
F_204 ( V_258 , V_23 -> V_261 ) ;
F_122 ( V_258 , & V_259 , 0 ) ;
F_117 ( V_258 , 0 , V_257 -> V_46 ) ;
V_256 = F_47 ( V_257 ) ;
F_32 ( V_256 != V_33 -> V_43 ) ;
F_118 ( V_258 , 0 , V_256 ) ;
F_49 ( V_258 ) ;
V_141 = V_18 -> V_20 ;
F_97 ( V_18 , V_258 , 0 ) ;
F_115 ( V_18 -> V_20 , V_258 ) ;
F_11 ( V_141 ) ;
F_24 ( V_18 ) ;
F_114 ( V_258 ) ;
V_139 -> V_7 [ V_39 ] = V_258 ;
V_139 -> V_8 [ V_39 ] = V_12 ;
V_139 -> V_16 [ V_39 ] = 0 ;
return 0 ;
}
static void F_205 ( struct V_32 * V_33 ,
struct V_22 * V_23 , struct V_1 * V_139 ,
struct V_40 * V_82 , T_2 V_262 ,
int V_77 , int V_39 )
{
struct V_13 * V_257 ;
int V_95 ;
int V_38 ;
F_90 ( ! V_139 -> V_7 [ V_39 ] ) ;
F_111 ( V_139 -> V_7 [ V_39 ] ) ;
V_257 = V_139 -> V_7 [ V_39 ] ;
V_95 = F_88 ( V_257 ) ;
F_90 ( V_77 > V_95 ) ;
F_90 ( V_95 == F_131 ( V_23 ) ) ;
if ( V_77 != V_95 ) {
if ( V_39 )
F_94 ( V_23 , V_257 , V_77 + 1 ,
V_77 , V_95 - V_77 ) ;
F_124 ( V_257 ,
F_123 ( V_77 + 1 ) ,
F_123 ( V_77 ) ,
( V_95 - V_77 ) * sizeof( struct V_138 ) ) ;
}
if ( V_39 ) {
V_38 = F_82 ( V_23 , V_257 , V_77 ,
V_81 , V_3 ) ;
F_90 ( V_38 < 0 ) ;
}
F_122 ( V_257 , V_82 , V_77 ) ;
F_117 ( V_257 , V_77 , V_262 ) ;
F_32 ( V_33 -> V_43 == 0 ) ;
F_118 ( V_257 , V_77 , V_33 -> V_43 ) ;
F_125 ( V_257 , V_95 + 1 ) ;
F_49 ( V_257 ) ;
}
static T_1 int F_179 ( struct V_32 * V_33 ,
struct V_17 * V_18 ,
struct V_1 * V_139 , int V_39 )
{
struct V_22 * V_23 = V_18 -> V_23 ;
struct V_13 * V_258 ;
struct V_13 * V_263 ;
struct V_40 V_41 ;
int V_175 ;
int V_38 ;
T_4 V_264 ;
V_258 = V_139 -> V_7 [ V_39 ] ;
F_32 ( F_47 ( V_258 ) != V_33 -> V_43 ) ;
if ( V_258 == V_18 -> V_20 ) {
V_38 = F_202 ( V_33 , V_18 , V_139 , V_39 + 1 ) ;
if ( V_38 )
return V_38 ;
} else {
V_38 = F_170 ( V_33 , V_18 , V_139 , V_39 ) ;
V_258 = V_139 -> V_7 [ V_39 ] ;
if ( ! V_38 && F_88 ( V_258 ) <
F_131 ( V_23 ) - 3 )
return 0 ;
if ( V_38 < 0 )
return V_38 ;
}
V_264 = F_88 ( V_258 ) ;
V_175 = ( V_264 + 1 ) / 2 ;
F_35 ( V_258 , & V_41 , V_175 ) ;
V_263 = F_36 ( V_33 , V_18 , 0 , V_18 -> V_121 . V_28 ,
& V_41 , V_39 , V_258 -> V_46 , 0 ) ;
if ( F_37 ( V_263 ) )
return F_38 ( V_263 ) ;
F_160 ( V_18 , V_23 -> V_168 ) ;
F_203 ( V_263 , 0 , sizeof( struct V_260 ) ) ;
F_129 ( V_263 , F_33 ( V_258 ) ) ;
F_40 ( V_263 , V_263 -> V_46 ) ;
F_41 ( V_263 , V_33 -> V_43 ) ;
F_42 ( V_263 , V_47 ) ;
F_45 ( V_263 , V_18 -> V_121 . V_28 ) ;
F_46 ( V_263 , V_23 -> V_51 ) ;
F_204 ( V_263 , V_23 -> V_261 ) ;
V_38 = F_93 ( V_23 , V_263 , V_258 , 0 , V_175 , V_264 - V_175 ) ;
if ( V_38 ) {
F_112 ( V_33 , V_38 ) ;
return V_38 ;
}
F_201 ( V_263 , V_258 ,
F_123 ( 0 ) ,
F_123 ( V_175 ) ,
( V_264 - V_175 ) * sizeof( struct V_138 ) ) ;
F_125 ( V_263 , V_264 - V_175 ) ;
F_125 ( V_258 , V_175 ) ;
V_38 = 0 ;
F_49 ( V_258 ) ;
F_49 ( V_263 ) ;
F_205 ( V_33 , V_23 , V_139 , & V_41 , V_263 -> V_46 ,
V_139 -> V_16 [ V_39 + 1 ] + 1 , V_39 + 1 ) ;
if ( V_139 -> V_16 [ V_39 ] >= V_175 ) {
V_139 -> V_16 [ V_39 ] -= V_175 ;
F_20 ( V_258 ) ;
F_11 ( V_258 ) ;
V_139 -> V_7 [ V_39 ] = V_263 ;
V_139 -> V_16 [ V_39 + 1 ] += 1 ;
} else {
F_20 ( V_263 ) ;
F_11 ( V_263 ) ;
}
return V_38 ;
}
static int F_206 ( struct V_13 * V_265 , int V_46 , int V_206 )
{
struct V_185 * V_266 ;
struct V_185 * V_267 ;
struct V_268 V_269 ;
int V_270 ;
int V_95 = F_88 ( V_265 ) ;
int V_271 = F_152 ( V_95 , V_46 + V_206 ) - 1 ;
if ( ! V_206 )
return 0 ;
F_207 ( & V_269 ) ;
V_266 = F_208 ( V_46 ) ;
V_267 = F_208 ( V_271 ) ;
V_270 = F_209 ( V_265 , V_266 , & V_269 ) +
F_210 ( V_265 , V_266 , & V_269 ) ;
V_270 = V_270 - F_209 ( V_265 , V_267 , & V_269 ) ;
V_270 += sizeof( struct V_185 ) * V_206 ;
F_32 ( V_270 < 0 ) ;
return V_270 ;
}
T_1 int F_193 ( struct V_22 * V_23 ,
struct V_13 * V_248 )
{
int V_95 = F_88 ( V_248 ) ;
int V_38 ;
V_38 = F_211 ( V_23 ) - F_206 ( V_248 , 0 , V_95 ) ;
if ( V_38 < 0 ) {
F_212 ( V_23 ,
L_4 ,
V_38 ,
( unsigned long ) F_211 ( V_23 ) ,
F_206 ( V_248 , 0 , V_95 ) , V_95 ) ;
}
return V_38 ;
}
static T_1 int F_213 ( struct V_22 * V_23 ,
struct V_1 * V_139 ,
int V_272 , int V_251 ,
struct V_13 * V_190 ,
int V_273 , T_4 V_274 ,
T_4 V_275 )
{
struct V_13 * V_191 = V_139 -> V_7 [ 0 ] ;
struct V_13 * V_276 = V_139 -> V_7 [ 1 ] ;
struct V_268 V_269 ;
struct V_40 V_41 ;
int V_77 ;
T_4 V_5 ;
int V_277 = 0 ;
int V_252 = 0 ;
struct V_185 * V_278 ;
T_4 V_206 ;
T_4 V_279 ;
T_4 V_280 ;
T_4 V_281 ;
F_207 ( & V_269 ) ;
if ( V_251 )
V_206 = 0 ;
else
V_206 = F_214 ( T_4 , 1 , V_275 ) ;
if ( V_139 -> V_16 [ 0 ] >= V_274 )
V_277 += V_272 ;
V_77 = V_139 -> V_16 [ 1 ] ;
V_5 = V_274 - 1 ;
while ( V_5 >= V_206 ) {
V_278 = F_208 ( V_5 ) ;
if ( ! V_251 && V_252 > 0 ) {
if ( V_139 -> V_16 [ 0 ] > V_5 )
break;
if ( V_139 -> V_16 [ 0 ] == V_5 ) {
int V_282 = F_193 ( V_23 , V_191 ) ;
if ( V_282 + V_277 * 2 > V_273 )
break;
}
}
if ( V_139 -> V_16 [ 0 ] == V_5 )
V_277 += V_272 ;
V_281 = F_215 ( V_191 , V_278 ) ;
if ( V_281 + sizeof( * V_278 ) + V_277 > V_273 )
break;
V_252 ++ ;
V_277 += V_281 + sizeof( * V_278 ) ;
if ( V_5 == 0 )
break;
V_5 -- ;
}
if ( V_252 == 0 )
goto V_283;
F_32 ( ! V_251 && V_252 == V_274 ) ;
V_279 = F_88 ( V_190 ) ;
V_277 = F_216 ( V_191 , V_274 - V_252 ) ;
V_277 -= F_217 ( V_23 , V_191 ) ;
V_280 = F_217 ( V_23 , V_190 ) ;
F_124 ( V_190 ,
V_284 + V_280 - V_277 ,
V_284 + V_280 ,
F_211 ( V_23 ) - V_280 ) ;
F_201 ( V_190 , V_191 , V_284 +
F_211 ( V_23 ) - V_277 ,
V_284 + F_217 ( V_23 , V_191 ) ,
V_277 ) ;
F_124 ( V_190 , F_218 ( V_252 ) ,
F_218 ( 0 ) ,
V_279 * sizeof( struct V_185 ) ) ;
F_201 ( V_190 , V_191 , F_218 ( 0 ) ,
F_218 ( V_274 - V_252 ) ,
V_252 * sizeof( struct V_185 ) ) ;
V_279 += V_252 ;
F_125 ( V_190 , V_279 ) ;
V_277 = F_211 ( V_23 ) ;
for ( V_5 = 0 ; V_5 < V_279 ; V_5 ++ ) {
V_278 = F_208 ( V_5 ) ;
V_277 -= F_210 ( V_190 , V_278 , & V_269 ) ;
F_219 ( V_190 , V_278 , V_277 , & V_269 ) ;
}
V_274 -= V_252 ;
F_125 ( V_191 , V_274 ) ;
if ( V_274 )
F_49 ( V_191 ) ;
else
F_109 ( V_23 , V_191 ) ;
F_49 ( V_190 ) ;
F_34 ( V_190 , & V_41 , 0 ) ;
F_122 ( V_276 , & V_41 , V_77 + 1 ) ;
F_49 ( V_276 ) ;
if ( V_139 -> V_16 [ 0 ] >= V_274 ) {
V_139 -> V_16 [ 0 ] -= V_274 ;
if ( F_88 ( V_139 -> V_7 [ 0 ] ) == 0 )
F_109 ( V_23 , V_139 -> V_7 [ 0 ] ) ;
F_20 ( V_139 -> V_7 [ 0 ] ) ;
F_11 ( V_139 -> V_7 [ 0 ] ) ;
V_139 -> V_7 [ 0 ] = V_190 ;
V_139 -> V_16 [ 1 ] += 1 ;
} else {
F_20 ( V_190 ) ;
F_11 ( V_190 ) ;
}
return 0 ;
V_283:
F_20 ( V_190 ) ;
F_11 ( V_190 ) ;
return 1 ;
}
static int F_220 ( struct V_32 * V_33 , struct V_17
* V_18 , struct V_1 * V_139 ,
int V_285 , int V_272 ,
int V_251 , T_4 V_275 )
{
struct V_22 * V_23 = V_18 -> V_23 ;
struct V_13 * V_191 = V_139 -> V_7 [ 0 ] ;
struct V_13 * V_190 ;
struct V_13 * V_276 ;
int V_77 ;
int V_273 ;
T_4 V_274 ;
int V_38 ;
if ( ! V_139 -> V_7 [ 1 ] )
return 1 ;
V_77 = V_139 -> V_16 [ 1 ] ;
V_276 = V_139 -> V_7 [ 1 ] ;
if ( V_77 >= F_88 ( V_276 ) - 1 )
return 1 ;
F_111 ( V_139 -> V_7 [ 1 ] ) ;
V_190 = F_165 ( V_23 , V_276 , V_77 + 1 ) ;
if ( F_37 ( V_190 ) )
return 1 ;
F_19 ( V_190 ) ;
F_142 ( V_190 ) ;
V_273 = F_193 ( V_23 , V_190 ) ;
if ( V_273 < V_272 )
goto V_283;
V_38 = F_140 ( V_33 , V_18 , V_190 , V_276 ,
V_77 + 1 , & V_190 ) ;
if ( V_38 )
goto V_283;
V_273 = F_193 ( V_23 , V_190 ) ;
if ( V_273 < V_272 )
goto V_283;
V_274 = F_88 ( V_191 ) ;
if ( V_274 == 0 )
goto V_283;
if ( V_139 -> V_16 [ 0 ] == V_274 && ! V_251 ) {
F_20 ( V_191 ) ;
F_11 ( V_191 ) ;
V_139 -> V_7 [ 0 ] = V_190 ;
V_139 -> V_16 [ 0 ] = 0 ;
V_139 -> V_16 [ 1 ] ++ ;
return 0 ;
}
return F_213 ( V_23 , V_139 , V_285 , V_251 ,
V_190 , V_273 , V_274 , V_275 ) ;
V_283:
F_20 ( V_190 ) ;
F_11 ( V_190 ) ;
return 1 ;
}
static T_1 int F_221 ( struct V_22 * V_23 ,
struct V_1 * V_139 , int V_272 ,
int V_251 , struct V_13 * V_191 ,
int V_273 , T_4 V_279 ,
T_4 V_286 )
{
struct V_40 V_41 ;
struct V_13 * V_190 = V_139 -> V_7 [ 0 ] ;
int V_5 ;
int V_277 = 0 ;
int V_252 = 0 ;
struct V_185 * V_278 ;
T_4 V_287 ;
T_4 V_206 ;
int V_38 = 0 ;
T_4 V_281 ;
T_4 V_288 ;
struct V_268 V_269 ;
F_207 ( & V_269 ) ;
if ( V_251 )
V_206 = F_152 ( V_279 , V_286 ) ;
else
V_206 = F_152 ( V_279 - 1 , V_286 ) ;
for ( V_5 = 0 ; V_5 < V_206 ; V_5 ++ ) {
V_278 = F_208 ( V_5 ) ;
if ( ! V_251 && V_252 > 0 ) {
if ( V_139 -> V_16 [ 0 ] < V_5 )
break;
if ( V_139 -> V_16 [ 0 ] == V_5 ) {
int V_282 = F_193 ( V_23 , V_190 ) ;
if ( V_282 + V_277 * 2 > V_273 )
break;
}
}
if ( V_139 -> V_16 [ 0 ] == V_5 )
V_277 += V_272 ;
V_281 = F_215 ( V_190 , V_278 ) ;
if ( V_281 + sizeof( * V_278 ) + V_277 > V_273 )
break;
V_252 ++ ;
V_277 += V_281 + sizeof( * V_278 ) ;
}
if ( V_252 == 0 ) {
V_38 = 1 ;
goto V_289;
}
F_32 ( ! V_251 && V_252 == F_88 ( V_190 ) ) ;
F_201 ( V_191 , V_190 ,
F_218 ( F_88 ( V_191 ) ) ,
F_218 ( 0 ) ,
V_252 * sizeof( struct V_185 ) ) ;
V_277 = F_211 ( V_23 ) -
F_222 ( V_190 , V_252 - 1 ) ;
F_201 ( V_191 , V_190 , V_284 +
F_217 ( V_23 , V_191 ) - V_277 ,
V_284 +
F_222 ( V_190 , V_252 - 1 ) ,
V_277 ) ;
V_287 = F_88 ( V_191 ) ;
F_90 ( V_287 <= 0 ) ;
V_288 = F_222 ( V_191 , V_287 - 1 ) ;
for ( V_5 = V_287 ; V_5 < V_287 + V_252 ; V_5 ++ ) {
T_4 V_232 ;
V_278 = F_208 ( V_5 ) ;
V_232 = F_209 ( V_191 , V_278 , & V_269 ) ;
F_219 ( V_191 , V_278 ,
V_232 - ( F_211 ( V_23 ) - V_288 ) ,
& V_269 ) ;
}
F_125 ( V_191 , V_287 + V_252 ) ;
if ( V_252 > V_279 )
F_141 ( 1 , V_146 L_5 , V_252 ,
V_279 ) ;
if ( V_252 < V_279 ) {
V_277 = F_222 ( V_190 , V_252 - 1 ) -
F_217 ( V_23 , V_190 ) ;
F_124 ( V_190 , V_284 +
F_211 ( V_23 ) - V_277 ,
V_284 +
F_217 ( V_23 , V_190 ) , V_277 ) ;
F_124 ( V_190 , F_218 ( 0 ) ,
F_218 ( V_252 ) ,
( F_88 ( V_190 ) - V_252 ) *
sizeof( struct V_185 ) ) ;
}
V_279 -= V_252 ;
F_125 ( V_190 , V_279 ) ;
V_277 = F_211 ( V_23 ) ;
for ( V_5 = 0 ; V_5 < V_279 ; V_5 ++ ) {
V_278 = F_208 ( V_5 ) ;
V_277 = V_277 - F_210 ( V_190 ,
V_278 , & V_269 ) ;
F_219 ( V_190 , V_278 , V_277 , & V_269 ) ;
}
F_49 ( V_191 ) ;
if ( V_279 )
F_49 ( V_190 ) ;
else
F_109 ( V_23 , V_190 ) ;
F_34 ( V_190 , & V_41 , 0 ) ;
F_198 ( V_23 , V_139 , & V_41 , 1 ) ;
if ( V_139 -> V_16 [ 0 ] < V_252 ) {
V_139 -> V_16 [ 0 ] += V_287 ;
F_20 ( V_139 -> V_7 [ 0 ] ) ;
F_11 ( V_139 -> V_7 [ 0 ] ) ;
V_139 -> V_7 [ 0 ] = V_191 ;
V_139 -> V_16 [ 1 ] -= 1 ;
} else {
F_20 ( V_191 ) ;
F_11 ( V_191 ) ;
V_139 -> V_16 [ 0 ] -= V_252 ;
}
F_90 ( V_139 -> V_16 [ 0 ] < 0 ) ;
return V_38 ;
V_289:
F_20 ( V_191 ) ;
F_11 ( V_191 ) ;
return V_38 ;
}
static int F_223 ( struct V_32 * V_33 , struct V_17
* V_18 , struct V_1 * V_139 , int V_285 ,
int V_272 , int V_251 , T_4 V_286 )
{
struct V_22 * V_23 = V_18 -> V_23 ;
struct V_13 * V_190 = V_139 -> V_7 [ 0 ] ;
struct V_13 * V_191 ;
int V_77 ;
int V_273 ;
T_4 V_279 ;
int V_38 = 0 ;
V_77 = V_139 -> V_16 [ 1 ] ;
if ( V_77 == 0 )
return 1 ;
if ( ! V_139 -> V_7 [ 1 ] )
return 1 ;
V_279 = F_88 ( V_190 ) ;
if ( V_279 == 0 )
return 1 ;
F_111 ( V_139 -> V_7 [ 1 ] ) ;
V_191 = F_165 ( V_23 , V_139 -> V_7 [ 1 ] , V_77 - 1 ) ;
if ( F_37 ( V_191 ) )
return 1 ;
F_19 ( V_191 ) ;
F_142 ( V_191 ) ;
V_273 = F_193 ( V_23 , V_191 ) ;
if ( V_273 < V_272 ) {
V_38 = 1 ;
goto V_289;
}
V_38 = F_140 ( V_33 , V_18 , V_191 ,
V_139 -> V_7 [ 1 ] , V_77 - 1 , & V_191 ) ;
if ( V_38 ) {
if ( V_38 == - V_198 )
V_38 = 1 ;
goto V_289;
}
V_273 = F_193 ( V_23 , V_191 ) ;
if ( V_273 < V_272 ) {
V_38 = 1 ;
goto V_289;
}
return F_221 ( V_23 , V_139 , V_285 ,
V_251 , V_191 , V_273 , V_279 ,
V_286 ) ;
V_289:
F_20 ( V_191 ) ;
F_11 ( V_191 ) ;
return V_38 ;
}
static T_1 void F_224 ( struct V_32 * V_33 ,
struct V_22 * V_23 ,
struct V_1 * V_139 ,
struct V_13 * V_265 ,
struct V_13 * V_190 ,
int V_77 , int V_175 , int V_95 )
{
int V_290 ;
int V_291 ;
int V_5 ;
struct V_40 V_41 ;
struct V_268 V_269 ;
F_207 ( & V_269 ) ;
V_95 = V_95 - V_175 ;
F_125 ( V_190 , V_95 ) ;
V_290 = F_216 ( V_265 , V_175 ) - F_217 ( V_23 , V_265 ) ;
F_201 ( V_190 , V_265 , F_218 ( 0 ) ,
F_218 ( V_175 ) ,
V_95 * sizeof( struct V_185 ) ) ;
F_201 ( V_190 , V_265 ,
V_284 + F_211 ( V_23 ) -
V_290 , V_284 +
F_217 ( V_23 , V_265 ) , V_290 ) ;
V_291 = F_211 ( V_23 ) - F_216 ( V_265 , V_175 ) ;
for ( V_5 = 0 ; V_5 < V_95 ; V_5 ++ ) {
struct V_185 * V_278 = F_208 ( V_5 ) ;
T_4 V_232 ;
V_232 = F_209 ( V_190 , V_278 , & V_269 ) ;
F_219 ( V_190 , V_278 ,
V_232 + V_291 , & V_269 ) ;
}
F_125 ( V_265 , V_175 ) ;
F_34 ( V_190 , & V_41 , 0 ) ;
F_205 ( V_33 , V_23 , V_139 , & V_41 , V_190 -> V_46 ,
V_139 -> V_16 [ 1 ] + 1 , 1 ) ;
F_49 ( V_190 ) ;
F_49 ( V_265 ) ;
F_90 ( V_139 -> V_16 [ 0 ] != V_77 ) ;
if ( V_175 <= V_77 ) {
F_20 ( V_139 -> V_7 [ 0 ] ) ;
F_11 ( V_139 -> V_7 [ 0 ] ) ;
V_139 -> V_7 [ 0 ] = V_190 ;
V_139 -> V_16 [ 0 ] -= V_175 ;
V_139 -> V_16 [ 1 ] += 1 ;
} else {
F_20 ( V_190 ) ;
F_11 ( V_190 ) ;
}
F_90 ( V_139 -> V_16 [ 0 ] < 0 ) ;
}
static T_1 int F_225 ( struct V_32 * V_33 ,
struct V_17 * V_18 ,
struct V_1 * V_139 ,
int V_272 )
{
struct V_22 * V_23 = V_18 -> V_23 ;
int V_38 ;
int V_159 = 0 ;
int V_77 ;
T_4 V_95 ;
int V_292 = V_272 ;
V_77 = V_139 -> V_16 [ 0 ] ;
if ( V_77 < F_88 ( V_139 -> V_7 [ 0 ] ) )
V_292 -= F_193 ( V_23 , V_139 -> V_7 [ 0 ] ) ;
V_38 = F_220 ( V_33 , V_18 , V_139 , 1 , V_292 , 0 , V_77 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_38 == 0 )
V_159 ++ ;
V_95 = F_88 ( V_139 -> V_7 [ 0 ] ) ;
if ( V_139 -> V_16 [ 0 ] == 0 || V_139 -> V_16 [ 0 ] == V_95 )
return 0 ;
if ( F_193 ( V_23 , V_139 -> V_7 [ 0 ] ) >= V_272 )
return 0 ;
V_77 = V_139 -> V_16 [ 0 ] ;
V_292 = V_272 ;
if ( V_77 > 0 )
V_292 -= F_193 ( V_23 , V_139 -> V_7 [ 0 ] ) ;
V_38 = F_223 ( V_33 , V_18 , V_139 , 1 , V_292 , 0 , V_77 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_38 == 0 )
V_159 ++ ;
if ( V_159 )
return 0 ;
return 1 ;
}
static T_1 int F_194 ( struct V_32 * V_33 ,
struct V_17 * V_18 ,
const struct V_153 * V_293 ,
struct V_1 * V_139 , int V_272 ,
int V_294 )
{
struct V_40 V_41 ;
struct V_13 * V_265 ;
T_4 V_95 ;
int V_175 ;
int V_77 ;
struct V_13 * V_190 ;
struct V_22 * V_23 = V_18 -> V_23 ;
int V_38 = 0 ;
int V_192 ;
int V_263 ;
int V_295 = 0 ;
int V_296 = 0 ;
V_265 = V_139 -> V_7 [ 0 ] ;
V_77 = V_139 -> V_16 [ 0 ] ;
if ( V_294 && V_272 + F_226 ( V_265 , V_77 ) +
sizeof( struct V_185 ) > F_211 ( V_23 ) )
return - V_297 ;
if ( V_272 && V_139 -> V_7 [ 1 ] ) {
int V_292 = V_272 ;
if ( V_77 < F_88 ( V_265 ) )
V_292 -= F_193 ( V_23 , V_265 ) ;
V_192 = F_220 ( V_33 , V_18 , V_139 , V_292 ,
V_292 , 0 , 0 ) ;
if ( V_192 < 0 )
return V_192 ;
if ( V_192 ) {
V_292 = V_272 ;
if ( V_77 > 0 )
V_292 -= F_193 ( V_23 ,
V_265 ) ;
V_192 = F_223 ( V_33 , V_18 , V_139 , V_292 ,
V_292 , 0 , ( T_4 ) - 1 ) ;
if ( V_192 < 0 )
return V_192 ;
}
V_265 = V_139 -> V_7 [ 0 ] ;
if ( F_193 ( V_23 , V_265 ) >= V_272 )
return 0 ;
}
if ( ! V_139 -> V_7 [ 1 ] ) {
V_38 = F_202 ( V_33 , V_18 , V_139 , 1 ) ;
if ( V_38 )
return V_38 ;
}
V_227:
V_263 = 1 ;
V_265 = V_139 -> V_7 [ 0 ] ;
V_77 = V_139 -> V_16 [ 0 ] ;
V_95 = F_88 ( V_265 ) ;
V_175 = ( V_95 + 1 ) / 2 ;
if ( V_175 <= V_77 ) {
if ( V_95 == 1 ||
F_206 ( V_265 , V_175 , V_95 - V_175 ) + V_272 >
F_211 ( V_23 ) ) {
if ( V_77 >= V_95 ) {
V_263 = 0 ;
} else {
V_175 = V_77 ;
if ( V_175 != V_95 &&
F_206 ( V_265 , V_175 , V_95 - V_175 ) +
V_272 > F_211 ( V_23 ) ) {
if ( V_272 && ! V_296 )
goto V_298;
V_263 = 2 ;
}
}
}
} else {
if ( F_206 ( V_265 , 0 , V_175 ) + V_272 >
F_211 ( V_23 ) ) {
if ( ! V_294 && V_272 && V_77 == 0 ) {
V_263 = 0 ;
} else if ( ( V_294 || ! V_272 ) && V_77 == 0 ) {
V_175 = 1 ;
} else {
V_175 = V_77 ;
if ( V_175 != V_95 &&
F_206 ( V_265 , V_175 , V_95 - V_175 ) +
V_272 > F_211 ( V_23 ) ) {
if ( V_272 && ! V_296 )
goto V_298;
V_263 = 2 ;
}
}
}
}
if ( V_263 == 0 )
F_182 ( & V_41 , V_293 ) ;
else
F_34 ( V_265 , & V_41 , V_175 ) ;
V_190 = F_36 ( V_33 , V_18 , 0 , V_18 -> V_121 . V_28 ,
& V_41 , 0 , V_265 -> V_46 , 0 ) ;
if ( F_37 ( V_190 ) )
return F_38 ( V_190 ) ;
F_160 ( V_18 , V_23 -> V_168 ) ;
F_203 ( V_190 , 0 , sizeof( struct V_260 ) ) ;
F_40 ( V_190 , V_190 -> V_46 ) ;
F_41 ( V_190 , V_33 -> V_43 ) ;
F_42 ( V_190 , V_47 ) ;
F_45 ( V_190 , V_18 -> V_121 . V_28 ) ;
F_129 ( V_190 , 0 ) ;
F_46 ( V_190 , V_23 -> V_51 ) ;
F_204 ( V_190 , V_23 -> V_261 ) ;
if ( V_263 == 0 ) {
if ( V_175 <= V_77 ) {
F_125 ( V_190 , 0 ) ;
F_205 ( V_33 , V_23 , V_139 , & V_41 ,
V_190 -> V_46 , V_139 -> V_16 [ 1 ] + 1 , 1 ) ;
F_20 ( V_139 -> V_7 [ 0 ] ) ;
F_11 ( V_139 -> V_7 [ 0 ] ) ;
V_139 -> V_7 [ 0 ] = V_190 ;
V_139 -> V_16 [ 0 ] = 0 ;
V_139 -> V_16 [ 1 ] += 1 ;
} else {
F_125 ( V_190 , 0 ) ;
F_205 ( V_33 , V_23 , V_139 , & V_41 ,
V_190 -> V_46 , V_139 -> V_16 [ 1 ] , 1 ) ;
F_20 ( V_139 -> V_7 [ 0 ] ) ;
F_11 ( V_139 -> V_7 [ 0 ] ) ;
V_139 -> V_7 [ 0 ] = V_190 ;
V_139 -> V_16 [ 0 ] = 0 ;
if ( V_139 -> V_16 [ 1 ] == 0 )
F_198 ( V_23 , V_139 , & V_41 , 1 ) ;
}
return V_38 ;
}
F_224 ( V_33 , V_23 , V_139 , V_265 , V_190 , V_77 , V_175 , V_95 ) ;
if ( V_263 == 2 ) {
F_90 ( V_295 != 0 ) ;
V_295 ++ ;
goto V_227;
}
return 0 ;
V_298:
F_225 ( V_33 , V_18 , V_139 , V_272 ) ;
V_296 = 1 ;
if ( F_193 ( V_23 , V_139 -> V_7 [ 0 ] ) >= V_272 )
return 0 ;
goto V_227;
}
static T_1 int F_227 ( struct V_32 * V_33 ,
struct V_17 * V_18 ,
struct V_1 * V_139 , int V_224 )
{
struct V_22 * V_23 = V_18 -> V_23 ;
struct V_153 V_82 ;
struct V_13 * V_248 ;
struct V_299 * V_300 ;
T_2 V_301 = 0 ;
T_4 V_171 ;
int V_38 ;
V_248 = V_139 -> V_7 [ 0 ] ;
F_188 ( V_248 , & V_82 , V_139 -> V_16 [ 0 ] ) ;
F_90 ( V_82 . type != V_302 &&
V_82 . type != V_303 ) ;
if ( F_193 ( V_23 , V_248 ) >= V_224 )
return 0 ;
V_171 = F_226 ( V_248 , V_139 -> V_16 [ 0 ] ) ;
if ( V_82 . type == V_302 ) {
V_300 = F_228 ( V_248 , V_139 -> V_16 [ 0 ] ,
struct V_299 ) ;
V_301 = F_229 ( V_248 , V_300 ) ;
}
F_8 ( V_139 ) ;
V_139 -> V_219 = 1 ;
V_139 -> V_225 = 1 ;
V_38 = F_186 ( V_33 , V_18 , & V_82 , V_139 , 0 , 1 ) ;
V_139 -> V_225 = 0 ;
if ( V_38 > 0 )
V_38 = - V_223 ;
if ( V_38 < 0 )
goto V_164;
V_38 = - V_223 ;
V_248 = V_139 -> V_7 [ 0 ] ;
if ( V_171 != F_226 ( V_248 , V_139 -> V_16 [ 0 ] ) )
goto V_164;
if ( F_193 ( V_23 , V_139 -> V_7 [ 0 ] ) >= V_224 )
goto V_164;
if ( V_82 . type == V_302 ) {
V_300 = F_228 ( V_248 , V_139 -> V_16 [ 0 ] ,
struct V_299 ) ;
if ( V_301 != F_229 ( V_248 , V_300 ) )
goto V_164;
}
F_3 ( V_139 ) ;
V_38 = F_194 ( V_33 , V_18 , & V_82 , V_139 , V_224 , 1 ) ;
if ( V_38 )
goto V_164;
V_139 -> V_219 = 0 ;
F_176 ( V_139 , 1 ) ;
return 0 ;
V_164:
V_139 -> V_219 = 0 ;
return V_38 ;
}
static T_1 int F_230 ( struct V_22 * V_23 ,
struct V_1 * V_139 ,
const struct V_153 * V_250 ,
unsigned long V_304 )
{
struct V_13 * V_248 ;
struct V_185 * V_278 ;
struct V_185 * V_305 ;
int V_77 ;
char * V_34 ;
T_4 V_95 ;
T_4 V_171 ;
T_4 V_306 ;
struct V_40 V_41 ;
V_248 = V_139 -> V_7 [ 0 ] ;
F_90 ( F_193 ( V_23 , V_248 ) < sizeof( struct V_185 ) ) ;
F_3 ( V_139 ) ;
V_278 = F_208 ( V_139 -> V_16 [ 0 ] ) ;
V_306 = F_231 ( V_248 , V_278 ) ;
V_171 = F_215 ( V_248 , V_278 ) ;
V_34 = F_232 ( V_171 , V_3 ) ;
if ( ! V_34 )
return - V_85 ;
F_156 ( V_248 , V_34 , F_233 ( V_248 ,
V_139 -> V_16 [ 0 ] ) , V_171 ) ;
V_77 = V_139 -> V_16 [ 0 ] + 1 ;
V_95 = F_88 ( V_248 ) ;
if ( V_77 != V_95 ) {
F_124 ( V_248 , F_218 ( V_77 + 1 ) ,
F_218 ( V_77 ) ,
( V_95 - V_77 ) * sizeof( struct V_185 ) ) ;
}
F_182 ( & V_41 , V_250 ) ;
F_200 ( V_248 , & V_41 , V_77 ) ;
V_305 = F_208 ( V_77 ) ;
F_234 ( V_248 , V_305 , V_306 ) ;
F_235 ( V_248 , V_305 , V_171 - V_304 ) ;
F_234 ( V_248 , V_278 ,
V_306 + V_171 - V_304 ) ;
F_235 ( V_248 , V_278 , V_304 ) ;
F_125 ( V_248 , V_95 + 1 ) ;
F_236 ( V_248 , V_34 ,
F_233 ( V_248 , V_139 -> V_16 [ 0 ] ) ,
V_304 ) ;
F_236 ( V_248 , V_34 + V_304 ,
F_233 ( V_248 , V_77 ) ,
V_171 - V_304 ) ;
F_49 ( V_248 ) ;
F_90 ( F_193 ( V_23 , V_248 ) < 0 ) ;
F_69 ( V_34 ) ;
return 0 ;
}
int F_237 ( struct V_32 * V_33 ,
struct V_17 * V_18 ,
struct V_1 * V_139 ,
const struct V_153 * V_250 ,
unsigned long V_304 )
{
int V_38 ;
V_38 = F_227 ( V_33 , V_18 , V_139 ,
sizeof( struct V_185 ) ) ;
if ( V_38 )
return V_38 ;
V_38 = F_230 ( V_18 -> V_23 , V_139 , V_250 , V_304 ) ;
return V_38 ;
}
int F_238 ( struct V_32 * V_33 ,
struct V_17 * V_18 ,
struct V_1 * V_139 ,
const struct V_153 * V_250 )
{
struct V_13 * V_248 ;
int V_38 ;
T_4 V_171 ;
V_248 = V_139 -> V_7 [ 0 ] ;
V_171 = F_226 ( V_248 , V_139 -> V_16 [ 0 ] ) ;
V_38 = F_227 ( V_33 , V_18 , V_139 ,
V_171 + sizeof( struct V_185 ) ) ;
if ( V_38 )
return V_38 ;
V_139 -> V_16 [ 0 ] ++ ;
F_239 ( V_18 , V_139 , V_250 , & V_171 ,
V_171 , V_171 +
sizeof( struct V_185 ) , 1 ) ;
V_248 = V_139 -> V_7 [ 0 ] ;
F_240 ( V_248 ,
F_233 ( V_248 , V_139 -> V_16 [ 0 ] ) ,
F_233 ( V_248 , V_139 -> V_16 [ 0 ] - 1 ) ,
V_171 ) ;
return 0 ;
}
void F_241 ( struct V_22 * V_23 ,
struct V_1 * V_139 , T_4 V_307 , int V_308 )
{
int V_77 ;
struct V_13 * V_248 ;
struct V_185 * V_278 ;
T_4 V_95 ;
unsigned int V_280 ;
unsigned int V_309 ;
unsigned int V_310 ;
unsigned int V_311 ;
int V_5 ;
struct V_268 V_269 ;
F_207 ( & V_269 ) ;
V_248 = V_139 -> V_7 [ 0 ] ;
V_77 = V_139 -> V_16 [ 0 ] ;
V_310 = F_226 ( V_248 , V_77 ) ;
if ( V_310 == V_307 )
return;
V_95 = F_88 ( V_248 ) ;
V_280 = F_217 ( V_23 , V_248 ) ;
V_309 = F_222 ( V_248 , V_77 ) ;
V_311 = V_310 - V_307 ;
F_90 ( V_77 < 0 ) ;
F_90 ( V_77 >= V_95 ) ;
for ( V_5 = V_77 ; V_5 < V_95 ; V_5 ++ ) {
T_4 V_232 ;
V_278 = F_208 ( V_5 ) ;
V_232 = F_209 ( V_248 , V_278 , & V_269 ) ;
F_219 ( V_248 , V_278 ,
V_232 + V_311 , & V_269 ) ;
}
if ( V_308 ) {
F_124 ( V_248 , V_284 +
V_280 + V_311 , V_284 +
V_280 , V_309 + V_307 - V_280 ) ;
} else {
struct V_40 V_41 ;
T_2 V_156 ;
F_34 ( V_248 , & V_41 , V_77 ) ;
if ( F_242 ( & V_41 ) == V_302 ) {
unsigned long V_312 ;
struct V_299 * V_300 ;
V_300 = F_228 ( V_248 , V_77 ,
struct V_299 ) ;
V_300 = (struct V_299 * ) (
( unsigned long ) V_300 - V_311 ) ;
if ( F_243 ( V_248 , V_300 ) ==
V_313 ) {
V_312 = F_233 ( V_248 , V_77 ) ;
F_124 ( V_248 , V_312 ,
( unsigned long ) V_300 ,
V_314 ) ;
}
}
F_124 ( V_248 , V_284 +
V_280 + V_311 , V_284 +
V_280 , V_309 - V_280 ) ;
V_156 = F_244 ( & V_41 ) ;
F_245 ( & V_41 , V_156 + V_311 ) ;
F_200 ( V_248 , & V_41 , V_77 ) ;
if ( V_77 == 0 )
F_198 ( V_23 , V_139 , & V_41 , 1 ) ;
}
V_278 = F_208 ( V_77 ) ;
F_235 ( V_248 , V_278 , V_307 ) ;
F_49 ( V_248 ) ;
if ( F_193 ( V_23 , V_248 ) < 0 ) {
F_246 ( V_248 ) ;
F_169 () ;
}
}
void F_247 ( struct V_22 * V_23 , struct V_1 * V_139 ,
T_4 V_272 )
{
int V_77 ;
struct V_13 * V_248 ;
struct V_185 * V_278 ;
T_4 V_95 ;
unsigned int V_280 ;
unsigned int V_315 ;
unsigned int V_310 ;
int V_5 ;
struct V_268 V_269 ;
F_207 ( & V_269 ) ;
V_248 = V_139 -> V_7 [ 0 ] ;
V_95 = F_88 ( V_248 ) ;
V_280 = F_217 ( V_23 , V_248 ) ;
if ( F_193 ( V_23 , V_248 ) < V_272 ) {
F_246 ( V_248 ) ;
F_169 () ;
}
V_77 = V_139 -> V_16 [ 0 ] ;
V_315 = F_216 ( V_248 , V_77 ) ;
F_90 ( V_77 < 0 ) ;
if ( V_77 >= V_95 ) {
F_246 ( V_248 ) ;
F_212 ( V_23 , L_6 ,
V_77 , V_95 ) ;
F_90 ( 1 ) ;
}
for ( V_5 = V_77 ; V_5 < V_95 ; V_5 ++ ) {
T_4 V_232 ;
V_278 = F_208 ( V_5 ) ;
V_232 = F_209 ( V_248 , V_278 , & V_269 ) ;
F_219 ( V_248 , V_278 ,
V_232 - V_272 , & V_269 ) ;
}
F_124 ( V_248 , V_284 +
V_280 - V_272 , V_284 +
V_280 , V_315 - V_280 ) ;
V_280 = V_315 ;
V_310 = F_226 ( V_248 , V_77 ) ;
V_278 = F_208 ( V_77 ) ;
F_235 ( V_248 , V_278 , V_310 + V_272 ) ;
F_49 ( V_248 ) ;
if ( F_193 ( V_23 , V_248 ) < 0 ) {
F_246 ( V_248 ) ;
F_169 () ;
}
}
void F_239 ( struct V_17 * V_18 , struct V_1 * V_139 ,
const struct V_153 * V_316 , T_4 * V_272 ,
T_4 V_317 , T_4 V_318 , int V_206 )
{
struct V_22 * V_23 = V_18 -> V_23 ;
struct V_185 * V_278 ;
int V_5 ;
T_4 V_95 ;
unsigned int V_280 ;
struct V_40 V_41 ;
struct V_13 * V_248 ;
int V_77 ;
struct V_268 V_269 ;
if ( V_139 -> V_16 [ 0 ] == 0 ) {
F_182 ( & V_41 , V_316 ) ;
F_198 ( V_23 , V_139 , & V_41 , 1 ) ;
}
F_176 ( V_139 , 1 ) ;
F_207 ( & V_269 ) ;
V_248 = V_139 -> V_7 [ 0 ] ;
V_77 = V_139 -> V_16 [ 0 ] ;
V_95 = F_88 ( V_248 ) ;
V_280 = F_217 ( V_23 , V_248 ) ;
if ( F_193 ( V_23 , V_248 ) < V_318 ) {
F_246 ( V_248 ) ;
F_212 ( V_23 , L_7 ,
V_318 , F_193 ( V_23 , V_248 ) ) ;
F_169 () ;
}
if ( V_77 != V_95 ) {
unsigned int V_315 = F_216 ( V_248 , V_77 ) ;
if ( V_315 < V_280 ) {
F_246 ( V_248 ) ;
F_212 ( V_23 , L_8 ,
V_77 , V_315 , V_280 ) ;
F_90 ( 1 ) ;
}
for ( V_5 = V_77 ; V_5 < V_95 ; V_5 ++ ) {
T_4 V_232 ;
V_278 = F_208 ( V_5 ) ;
V_232 = F_209 ( V_248 , V_278 , & V_269 ) ;
F_219 ( V_248 , V_278 ,
V_232 - V_317 , & V_269 ) ;
}
F_124 ( V_248 , F_218 ( V_77 + V_206 ) ,
F_218 ( V_77 ) ,
( V_95 - V_77 ) * sizeof( struct V_185 ) ) ;
F_124 ( V_248 , V_284 +
V_280 - V_317 , V_284 +
V_280 , V_315 - V_280 ) ;
V_280 = V_315 ;
}
for ( V_5 = 0 ; V_5 < V_206 ; V_5 ++ ) {
F_182 ( & V_41 , V_316 + V_5 ) ;
F_200 ( V_248 , & V_41 , V_77 + V_5 ) ;
V_278 = F_208 ( V_77 + V_5 ) ;
F_219 ( V_248 , V_278 ,
V_280 - V_272 [ V_5 ] , & V_269 ) ;
V_280 -= V_272 [ V_5 ] ;
F_248 ( V_248 , V_278 , V_272 [ V_5 ] , & V_269 ) ;
}
F_125 ( V_248 , V_95 + V_206 ) ;
F_49 ( V_248 ) ;
if ( F_193 ( V_23 , V_248 ) < 0 ) {
F_246 ( V_248 ) ;
F_169 () ;
}
}
int F_249 ( struct V_32 * V_33 ,
struct V_17 * V_18 ,
struct V_1 * V_139 ,
const struct V_153 * V_316 , T_4 * V_272 ,
int V_206 )
{
int V_38 = 0 ;
int V_77 ;
int V_5 ;
T_4 V_318 = 0 ;
T_4 V_317 = 0 ;
for ( V_5 = 0 ; V_5 < V_206 ; V_5 ++ )
V_317 += V_272 [ V_5 ] ;
V_318 = V_317 + ( V_206 * sizeof( struct V_185 ) ) ;
V_38 = F_186 ( V_33 , V_18 , V_316 , V_139 , V_318 , 1 ) ;
if ( V_38 == 0 )
return - V_76 ;
if ( V_38 < 0 )
return V_38 ;
V_77 = V_139 -> V_16 [ 0 ] ;
F_90 ( V_77 < 0 ) ;
F_239 ( V_18 , V_139 , V_316 , V_272 ,
V_317 , V_318 , V_206 ) ;
return 0 ;
}
int F_250 ( struct V_32 * V_33 , struct V_17 * V_18 ,
const struct V_153 * V_316 , void * V_319 ,
T_4 V_272 )
{
int V_38 = 0 ;
struct V_1 * V_139 ;
struct V_13 * V_248 ;
unsigned long V_312 ;
V_139 = F_1 () ;
if ( ! V_139 )
return - V_85 ;
V_38 = F_251 ( V_33 , V_18 , V_139 , V_316 , V_272 ) ;
if ( ! V_38 ) {
V_248 = V_139 -> V_7 [ 0 ] ;
V_312 = F_233 ( V_248 , V_139 -> V_16 [ 0 ] ) ;
F_236 ( V_248 , V_319 , V_312 , V_272 ) ;
F_49 ( V_248 ) ;
}
F_7 ( V_139 ) ;
return V_38 ;
}
static void F_167 ( struct V_17 * V_18 , struct V_1 * V_139 ,
int V_39 , int V_77 )
{
struct V_22 * V_23 = V_18 -> V_23 ;
struct V_13 * V_71 = V_139 -> V_7 [ V_39 ] ;
T_4 V_95 ;
int V_38 ;
V_95 = F_88 ( V_71 ) ;
if ( V_77 != V_95 - 1 ) {
if ( V_39 )
F_94 ( V_23 , V_71 , V_77 ,
V_77 + 1 , V_95 - V_77 - 1 ) ;
F_124 ( V_71 ,
F_123 ( V_77 ) ,
F_123 ( V_77 + 1 ) ,
sizeof( struct V_138 ) *
( V_95 - V_77 - 1 ) ) ;
} else if ( V_39 ) {
V_38 = F_82 ( V_23 , V_71 , V_77 ,
V_110 , V_3 ) ;
F_90 ( V_38 < 0 ) ;
}
V_95 -- ;
F_125 ( V_71 , V_95 ) ;
if ( V_95 == 0 && V_71 == V_18 -> V_20 ) {
F_90 ( F_33 ( V_18 -> V_20 ) != 1 ) ;
F_129 ( V_18 -> V_20 , 0 ) ;
} else if ( V_77 == 0 ) {
struct V_40 V_41 ;
F_35 ( V_71 , & V_41 , 0 ) ;
F_198 ( V_23 , V_139 , & V_41 , V_39 + 1 ) ;
}
F_49 ( V_71 ) ;
}
static T_1 void F_252 ( struct V_32 * V_33 ,
struct V_17 * V_18 ,
struct V_1 * V_139 ,
struct V_13 * V_248 )
{
F_32 ( F_47 ( V_248 ) != V_33 -> V_43 ) ;
F_167 ( V_18 , V_139 , 1 , V_139 -> V_16 [ 1 ] ) ;
F_176 ( V_139 , 0 ) ;
F_163 ( V_18 , V_248 -> V_123 ) ;
F_114 ( V_248 ) ;
F_116 ( V_33 , V_18 , V_248 , 0 , 1 ) ;
F_119 ( V_248 ) ;
}
int F_253 ( struct V_32 * V_33 , struct V_17 * V_18 ,
struct V_1 * V_139 , int V_77 , int V_206 )
{
struct V_22 * V_23 = V_18 -> V_23 ;
struct V_13 * V_248 ;
struct V_185 * V_278 ;
T_4 V_320 ;
T_4 V_321 = 0 ;
int V_38 = 0 ;
int V_192 ;
int V_5 ;
T_4 V_95 ;
struct V_268 V_269 ;
F_207 ( & V_269 ) ;
V_248 = V_139 -> V_7 [ 0 ] ;
V_320 = F_222 ( V_248 , V_77 + V_206 - 1 ) ;
for ( V_5 = 0 ; V_5 < V_206 ; V_5 ++ )
V_321 += F_226 ( V_248 , V_77 + V_5 ) ;
V_95 = F_88 ( V_248 ) ;
if ( V_77 + V_206 != V_95 ) {
int V_280 = F_217 ( V_23 , V_248 ) ;
F_124 ( V_248 , V_284 +
V_280 + V_321 ,
V_284 + V_280 ,
V_320 - V_280 ) ;
for ( V_5 = V_77 + V_206 ; V_5 < V_95 ; V_5 ++ ) {
T_4 V_232 ;
V_278 = F_208 ( V_5 ) ;
V_232 = F_209 ( V_248 , V_278 , & V_269 ) ;
F_219 ( V_248 , V_278 ,
V_232 + V_321 , & V_269 ) ;
}
F_124 ( V_248 , F_218 ( V_77 ) ,
F_218 ( V_77 + V_206 ) ,
sizeof( struct V_185 ) *
( V_95 - V_77 - V_206 ) ) ;
}
F_125 ( V_248 , V_95 - V_206 ) ;
V_95 -= V_206 ;
if ( V_95 == 0 ) {
if ( V_248 == V_18 -> V_20 ) {
F_129 ( V_248 , 0 ) ;
} else {
F_3 ( V_139 ) ;
F_109 ( V_23 , V_248 ) ;
F_252 ( V_33 , V_18 , V_139 , V_248 ) ;
}
} else {
int V_322 = F_206 ( V_248 , 0 , V_95 ) ;
if ( V_77 == 0 ) {
struct V_40 V_41 ;
F_34 ( V_248 , & V_41 , 0 ) ;
F_198 ( V_23 , V_139 , & V_41 , 1 ) ;
}
if ( V_322 < F_211 ( V_23 ) / 3 ) {
V_77 = V_139 -> V_16 [ 1 ] ;
F_114 ( V_248 ) ;
F_3 ( V_139 ) ;
V_192 = F_223 ( V_33 , V_18 , V_139 , 1 , 1 ,
1 , ( T_4 ) - 1 ) ;
if ( V_192 < 0 && V_192 != - V_198 )
V_38 = V_192 ;
if ( V_139 -> V_7 [ 0 ] == V_248 &&
F_88 ( V_248 ) ) {
V_192 = F_220 ( V_33 , V_18 , V_139 , 1 ,
1 , 1 , 0 ) ;
if ( V_192 < 0 && V_192 != - V_198 )
V_38 = V_192 ;
}
if ( F_88 ( V_248 ) == 0 ) {
V_139 -> V_16 [ 1 ] = V_77 ;
F_252 ( V_33 , V_18 , V_139 , V_248 ) ;
F_11 ( V_248 ) ;
V_38 = 0 ;
} else {
if ( V_139 -> V_7 [ 0 ] == V_248 )
F_49 ( V_248 ) ;
F_11 ( V_248 ) ;
}
} else {
F_49 ( V_248 ) ;
}
}
return V_38 ;
}
int F_197 ( struct V_17 * V_18 , struct V_1 * V_139 )
{
struct V_153 V_82 ;
struct V_40 V_234 ;
int V_38 ;
F_188 ( V_139 -> V_7 [ 0 ] , & V_82 , 0 ) ;
if ( V_82 . V_156 > 0 ) {
V_82 . V_156 -- ;
} else if ( V_82 . type > 0 ) {
V_82 . type -- ;
V_82 . V_156 = ( T_2 ) - 1 ;
} else if ( V_82 . V_28 > 0 ) {
V_82 . V_28 -- ;
V_82 . type = ( T_5 ) - 1 ;
V_82 . V_156 = ( T_2 ) - 1 ;
} else {
return 1 ;
}
F_8 ( V_139 ) ;
V_38 = F_186 ( NULL , V_18 , & V_82 , V_139 , 0 , 0 ) ;
if ( V_38 < 0 )
return V_38 ;
F_34 ( V_139 -> V_7 [ 0 ] , & V_234 , 0 ) ;
V_38 = F_145 ( & V_234 , & V_82 ) ;
if ( V_38 <= 0 )
return 0 ;
return 1 ;
}
int F_254 ( struct V_17 * V_18 , struct V_153 * V_323 ,
struct V_1 * V_139 ,
T_2 V_324 )
{
struct V_22 * V_23 = V_18 -> V_23 ;
struct V_13 * V_72 ;
struct V_153 V_234 ;
int V_77 ;
int V_226 ;
T_4 V_95 ;
int V_39 ;
int V_38 = 1 ;
int V_219 = V_139 -> V_219 ;
V_139 -> V_219 = 1 ;
V_227:
V_72 = F_21 ( V_18 ) ;
V_39 = F_33 ( V_72 ) ;
F_32 ( V_139 -> V_7 [ V_39 ] ) ;
V_139 -> V_7 [ V_39 ] = V_72 ;
V_139 -> V_8 [ V_39 ] = V_9 ;
if ( F_47 ( V_72 ) < V_324 ) {
V_38 = 1 ;
goto V_289;
}
while ( 1 ) {
V_95 = F_88 ( V_72 ) ;
V_39 = F_33 ( V_72 ) ;
V_226 = F_157 ( V_72 , V_323 , V_39 , & V_77 ) ;
if ( V_39 == V_139 -> V_236 ) {
if ( V_77 >= V_95 )
goto V_325;
V_38 = 0 ;
V_139 -> V_16 [ V_39 ] = V_77 ;
F_188 ( V_72 , & V_234 , V_77 ) ;
goto V_289;
}
if ( V_226 && V_77 > 0 )
V_77 -- ;
while ( V_77 < V_95 ) {
T_2 V_160 ;
V_160 = F_80 ( V_72 , V_77 ) ;
if ( V_160 < V_324 ) {
V_77 ++ ;
continue;
}
break;
}
V_325:
if ( V_77 >= V_95 ) {
V_139 -> V_16 [ V_39 ] = V_77 ;
F_3 ( V_139 ) ;
V_226 = F_255 ( V_18 , V_139 , V_323 , V_39 ,
V_324 ) ;
if ( V_226 == 0 ) {
F_8 ( V_139 ) ;
goto V_227;
} else {
goto V_289;
}
}
F_256 ( V_72 , & V_234 , V_77 ) ;
V_139 -> V_16 [ V_39 ] = V_77 ;
if ( V_39 == V_139 -> V_236 ) {
V_38 = 0 ;
goto V_289;
}
F_3 ( V_139 ) ;
V_72 = F_165 ( V_23 , V_72 , V_77 ) ;
if ( F_37 ( V_72 ) ) {
V_38 = F_38 ( V_72 ) ;
goto V_289;
}
F_22 ( V_72 ) ;
V_139 -> V_8 [ V_39 - 1 ] = V_9 ;
V_139 -> V_7 [ V_39 - 1 ] = V_72 ;
F_175 ( V_139 , V_39 , 1 , 0 , NULL ) ;
F_5 ( V_139 , NULL , 0 ) ;
}
V_289:
V_139 -> V_219 = V_219 ;
if ( V_38 == 0 ) {
F_176 ( V_139 , V_139 -> V_236 + 1 ) ;
F_3 ( V_139 ) ;
memcpy ( V_323 , & V_234 , sizeof( V_234 ) ) ;
}
return V_38 ;
}
static int F_257 ( struct V_22 * V_23 ,
struct V_1 * V_139 ,
int * V_39 )
{
struct V_13 * V_19 ;
F_90 ( * V_39 == 0 ) ;
V_19 = F_165 ( V_23 , V_139 -> V_7 [ * V_39 ] , V_139 -> V_16 [ * V_39 ] ) ;
if ( F_37 ( V_19 ) )
return F_38 ( V_19 ) ;
V_139 -> V_7 [ * V_39 - 1 ] = V_19 ;
V_139 -> V_16 [ * V_39 - 1 ] = 0 ;
( * V_39 ) -- ;
return 0 ;
}
static int F_258 ( struct V_1 * V_139 ,
int * V_39 , int V_326 )
{
int V_38 = 0 ;
int V_95 ;
V_95 = F_88 ( V_139 -> V_7 [ * V_39 ] ) ;
V_139 -> V_16 [ * V_39 ] ++ ;
while ( V_139 -> V_16 [ * V_39 ] >= V_95 ) {
if ( * V_39 == V_326 )
return - 1 ;
V_139 -> V_16 [ * V_39 ] = 0 ;
F_11 ( V_139 -> V_7 [ * V_39 ] ) ;
V_139 -> V_7 [ * V_39 ] = NULL ;
( * V_39 ) ++ ;
V_139 -> V_16 [ * V_39 ] ++ ;
V_95 = F_88 ( V_139 -> V_7 [ * V_39 ] ) ;
V_38 = 1 ;
}
return V_38 ;
}
static int F_259 ( struct V_22 * V_23 ,
struct V_1 * V_139 ,
int * V_39 , int V_326 ,
int V_327 ,
struct V_153 * V_82 )
{
int V_38 ;
if ( * V_39 == 0 || ! V_327 ) {
V_38 = F_258 ( V_139 , V_39 , V_326 ) ;
} else {
V_38 = F_257 ( V_23 , V_139 , V_39 ) ;
}
if ( V_38 >= 0 ) {
if ( * V_39 == 0 )
F_188 ( V_139 -> V_7 [ * V_39 ] , V_82 ,
V_139 -> V_16 [ * V_39 ] ) ;
else
F_256 ( V_139 -> V_7 [ * V_39 ] , V_82 ,
V_139 -> V_16 [ * V_39 ] ) ;
}
return V_38 ;
}
static int F_260 ( struct V_1 * V_328 ,
struct V_1 * V_329 ,
char * V_330 )
{
int V_331 ;
int V_332 , V_333 ;
unsigned long V_334 , V_335 ;
V_332 = F_226 ( V_328 -> V_7 [ 0 ] , V_328 -> V_16 [ 0 ] ) ;
V_333 = F_226 ( V_329 -> V_7 [ 0 ] , V_329 -> V_16 [ 0 ] ) ;
if ( V_332 != V_333 )
return 1 ;
V_334 = F_233 ( V_328 -> V_7 [ 0 ] , V_328 -> V_16 [ 0 ] ) ;
V_335 = F_233 ( V_329 -> V_7 [ 0 ] ,
V_329 -> V_16 [ 0 ] ) ;
F_156 ( V_328 -> V_7 [ 0 ] , V_330 , V_334 , V_332 ) ;
V_331 = F_183 ( V_329 -> V_7 [ 0 ] , V_330 , V_335 , V_332 ) ;
if ( V_331 )
return 1 ;
return 0 ;
}
int F_261 ( struct V_17 * V_336 ,
struct V_17 * V_337 ,
T_6 V_338 , void * V_339 )
{
struct V_22 * V_23 = V_336 -> V_23 ;
int V_38 ;
int V_331 ;
struct V_1 * V_328 = NULL ;
struct V_1 * V_329 = NULL ;
struct V_153 V_340 ;
struct V_153 V_199 ;
char * V_330 = NULL ;
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
V_328 = F_1 () ;
if ( ! V_328 ) {
V_38 = - V_85 ;
goto V_289;
}
V_329 = F_1 () ;
if ( ! V_329 ) {
V_38 = - V_85 ;
goto V_289;
}
V_330 = F_262 ( V_23 -> V_168 , V_353 ) ;
if ( ! V_330 ) {
V_38 = - V_85 ;
goto V_289;
}
V_328 -> V_237 = 1 ;
V_328 -> V_240 = 1 ;
V_329 -> V_237 = 1 ;
V_329 -> V_240 = 1 ;
F_189 ( & V_23 -> V_239 ) ;
V_343 = F_33 ( V_336 -> V_115 ) ;
V_341 = V_343 ;
V_328 -> V_7 [ V_343 ] = V_336 -> V_115 ;
F_114 ( V_328 -> V_7 [ V_343 ] ) ;
V_344 = F_33 ( V_337 -> V_115 ) ;
V_342 = V_344 ;
V_329 -> V_7 [ V_344 ] = V_337 -> V_115 ;
F_114 ( V_329 -> V_7 [ V_344 ] ) ;
F_190 ( & V_23 -> V_239 ) ;
if ( V_343 == 0 )
F_188 ( V_328 -> V_7 [ V_343 ] ,
& V_340 , V_328 -> V_16 [ V_343 ] ) ;
else
F_256 ( V_328 -> V_7 [ V_343 ] ,
& V_340 , V_328 -> V_16 [ V_343 ] ) ;
if ( V_344 == 0 )
F_188 ( V_329 -> V_7 [ V_344 ] ,
& V_199 , V_329 -> V_16 [ V_344 ] ) ;
else
F_256 ( V_329 -> V_7 [ V_344 ] ,
& V_199 , V_329 -> V_16 [ V_344 ] ) ;
V_345 = V_346 = 0 ;
V_347 = V_348 = 0 ;
while ( 1 ) {
if ( V_347 && ! V_345 ) {
V_38 = F_259 ( V_23 , V_328 , & V_343 ,
V_341 ,
V_347 != V_354 ,
& V_340 ) ;
if ( V_38 == - 1 )
V_345 = V_355 ;
else if ( V_38 < 0 )
goto V_289;
V_347 = 0 ;
}
if ( V_348 && ! V_346 ) {
V_38 = F_259 ( V_23 , V_329 , & V_344 ,
V_342 ,
V_348 != V_354 ,
& V_199 ) ;
if ( V_38 == - 1 )
V_346 = V_355 ;
else if ( V_38 < 0 )
goto V_289;
V_348 = 0 ;
}
if ( V_345 && V_346 ) {
V_38 = 0 ;
goto V_289;
} else if ( V_345 ) {
if ( V_344 == 0 ) {
V_38 = V_338 ( V_336 , V_337 ,
V_328 , V_329 ,
& V_199 ,
V_356 ,
V_339 ) ;
if ( V_38 < 0 )
goto V_289;
}
V_348 = V_355 ;
continue;
} else if ( V_346 ) {
if ( V_343 == 0 ) {
V_38 = V_338 ( V_336 , V_337 ,
V_328 , V_329 ,
& V_340 ,
V_357 ,
V_339 ) ;
if ( V_38 < 0 )
goto V_289;
}
V_347 = V_355 ;
continue;
}
if ( V_343 == 0 && V_344 == 0 ) {
V_331 = F_147 ( & V_340 , & V_199 ) ;
if ( V_331 < 0 ) {
V_38 = V_338 ( V_336 , V_337 ,
V_328 , V_329 ,
& V_340 ,
V_357 ,
V_339 ) ;
if ( V_38 < 0 )
goto V_289;
V_347 = V_355 ;
} else if ( V_331 > 0 ) {
V_38 = V_338 ( V_336 , V_337 ,
V_328 , V_329 ,
& V_199 ,
V_356 ,
V_339 ) ;
if ( V_38 < 0 )
goto V_289;
V_348 = V_355 ;
} else {
enum V_358 V_359 ;
F_32 ( ! F_134 ( V_328 -> V_7 [ 0 ] ) ) ;
V_38 = F_260 ( V_328 , V_329 ,
V_330 ) ;
if ( V_38 )
V_359 = V_360 ;
else
V_359 = V_361 ;
V_38 = V_338 ( V_336 , V_337 ,
V_328 , V_329 ,
& V_340 , V_359 , V_339 ) ;
if ( V_38 < 0 )
goto V_289;
V_347 = V_355 ;
V_348 = V_355 ;
}
} else if ( V_343 == V_344 ) {
V_331 = F_147 ( & V_340 , & V_199 ) ;
if ( V_331 < 0 ) {
V_347 = V_355 ;
} else if ( V_331 > 0 ) {
V_348 = V_355 ;
} else {
V_349 = F_79 (
V_328 -> V_7 [ V_343 ] ,
V_328 -> V_16 [ V_343 ] ) ;
V_350 = F_79 (
V_329 -> V_7 [ V_344 ] ,
V_329 -> V_16 [ V_344 ] ) ;
V_351 = F_80 (
V_328 -> V_7 [ V_343 ] ,
V_328 -> V_16 [ V_343 ] ) ;
V_352 = F_80 (
V_329 -> V_7 [ V_344 ] ,
V_329 -> V_16 [ V_344 ] ) ;
if ( V_349 == V_350 &&
V_351 == V_352 ) {
V_347 = V_354 ;
V_348 = V_354 ;
} else {
V_347 = V_355 ;
V_348 = V_355 ;
}
}
} else if ( V_343 < V_344 ) {
V_348 = V_355 ;
} else {
V_347 = V_355 ;
}
}
V_289:
F_7 ( V_328 ) ;
F_7 ( V_329 ) ;
F_263 ( V_330 ) ;
return V_38 ;
}
int F_255 ( struct V_17 * V_18 , struct V_1 * V_139 ,
struct V_153 * V_82 , int V_39 , T_2 V_324 )
{
int V_77 ;
struct V_13 * V_258 ;
F_32 ( ! V_139 -> V_219 ) ;
while ( V_39 < V_6 ) {
if ( ! V_139 -> V_7 [ V_39 ] )
return 1 ;
V_77 = V_139 -> V_16 [ V_39 ] + 1 ;
V_258 = V_139 -> V_7 [ V_39 ] ;
V_63:
if ( V_77 >= F_88 ( V_258 ) ) {
int V_38 ;
int V_362 ;
struct V_153 V_363 ;
if ( V_39 + 1 >= V_6 ||
! V_139 -> V_7 [ V_39 + 1 ] )
return 1 ;
if ( V_139 -> V_8 [ V_39 + 1 ] ) {
V_39 ++ ;
continue;
}
V_77 = F_88 ( V_258 ) - 1 ;
if ( V_39 == 0 )
F_188 ( V_258 , & V_363 , V_77 ) ;
else
F_256 ( V_258 , & V_363 , V_77 ) ;
V_362 = V_139 -> V_236 ;
F_8 ( V_139 ) ;
V_139 -> V_236 = V_39 ;
V_38 = F_186 ( NULL , V_18 , & V_363 , V_139 ,
0 , 0 ) ;
V_139 -> V_236 = V_362 ;
if ( V_38 < 0 )
return V_38 ;
V_258 = V_139 -> V_7 [ V_39 ] ;
V_77 = V_139 -> V_16 [ V_39 ] ;
if ( V_38 == 0 )
V_77 ++ ;
goto V_63;
}
if ( V_39 == 0 )
F_188 ( V_258 , V_82 , V_77 ) ;
else {
T_2 V_160 = F_80 ( V_258 , V_77 ) ;
if ( V_160 < V_324 ) {
V_77 ++ ;
goto V_63;
}
F_256 ( V_258 , V_82 , V_77 ) ;
}
return 0 ;
}
return 1 ;
}
int F_187 ( struct V_17 * V_18 , struct V_1 * V_139 )
{
return F_264 ( V_18 , V_139 , 0 ) ;
}
int F_264 ( struct V_17 * V_18 , struct V_1 * V_139 ,
T_2 V_130 )
{
int V_77 ;
int V_39 ;
struct V_13 * V_258 ;
struct V_13 * V_63 ;
struct V_153 V_82 ;
T_4 V_95 ;
int V_38 ;
int V_364 = V_139 -> V_244 ;
int V_365 = 0 ;
V_95 = F_88 ( V_139 -> V_7 [ 0 ] ) ;
if ( V_95 == 0 )
return 1 ;
F_188 ( V_139 -> V_7 [ 0 ] , & V_82 , V_95 - 1 ) ;
V_227:
V_39 = 1 ;
V_63 = NULL ;
V_365 = 0 ;
F_8 ( V_139 ) ;
V_139 -> V_219 = 1 ;
V_139 -> V_244 = 1 ;
if ( V_130 )
V_38 = F_195 ( V_18 , & V_82 , V_139 , V_130 ) ;
else
V_38 = F_186 ( NULL , V_18 , & V_82 , V_139 , 0 , 0 ) ;
V_139 -> V_219 = 0 ;
if ( V_38 < 0 )
return V_38 ;
V_95 = F_88 ( V_139 -> V_7 [ 0 ] ) ;
if ( V_95 > 0 && V_139 -> V_16 [ 0 ] < V_95 - 1 ) {
if ( V_38 == 0 )
V_139 -> V_16 [ 0 ] ++ ;
V_38 = 0 ;
goto V_228;
}
if ( V_95 > 0 && V_38 > 0 && V_139 -> V_16 [ 0 ] == V_95 - 1 ) {
V_38 = 0 ;
goto V_228;
}
while ( V_39 < V_6 ) {
if ( ! V_139 -> V_7 [ V_39 ] ) {
V_38 = 1 ;
goto V_228;
}
V_77 = V_139 -> V_16 [ V_39 ] + 1 ;
V_258 = V_139 -> V_7 [ V_39 ] ;
if ( V_77 >= F_88 ( V_258 ) ) {
V_39 ++ ;
if ( V_39 == V_6 ) {
V_38 = 1 ;
goto V_228;
}
continue;
}
if ( V_63 ) {
F_10 ( V_63 , V_365 ) ;
F_11 ( V_63 ) ;
}
V_63 = V_258 ;
V_365 = V_139 -> V_8 [ V_39 ] ;
V_38 = F_177 ( V_18 , V_139 , & V_63 , V_39 ,
V_77 , & V_82 ) ;
if ( V_38 == - V_223 )
goto V_227;
if ( V_38 < 0 ) {
F_8 ( V_139 ) ;
goto V_228;
}
if ( ! V_139 -> V_240 ) {
V_38 = F_265 ( V_63 ) ;
if ( ! V_38 && V_130 ) {
F_11 ( V_63 ) ;
F_8 ( V_139 ) ;
F_266 () ;
goto V_227;
}
if ( ! V_38 ) {
F_3 ( V_139 ) ;
F_22 ( V_63 ) ;
F_5 ( V_139 , V_63 ,
V_9 ) ;
}
V_365 = V_9 ;
}
break;
}
V_139 -> V_16 [ V_39 ] = V_77 ;
while ( 1 ) {
V_39 -- ;
V_258 = V_139 -> V_7 [ V_39 ] ;
if ( V_139 -> V_8 [ V_39 ] )
F_10 ( V_258 , V_139 -> V_8 [ V_39 ] ) ;
F_11 ( V_258 ) ;
V_139 -> V_7 [ V_39 ] = V_63 ;
V_139 -> V_16 [ V_39 ] = 0 ;
if ( ! V_139 -> V_240 )
V_139 -> V_8 [ V_39 ] = V_365 ;
if ( ! V_39 )
break;
V_38 = F_177 ( V_18 , V_139 , & V_63 , V_39 ,
0 , & V_82 ) ;
if ( V_38 == - V_223 )
goto V_227;
if ( V_38 < 0 ) {
F_8 ( V_139 ) ;
goto V_228;
}
if ( ! V_139 -> V_240 ) {
V_38 = F_265 ( V_63 ) ;
if ( ! V_38 ) {
F_3 ( V_139 ) ;
F_22 ( V_63 ) ;
F_5 ( V_139 , V_63 ,
V_9 ) ;
}
V_365 = V_9 ;
}
}
V_38 = 0 ;
V_228:
F_175 ( V_139 , 0 , 1 , 0 , NULL ) ;
V_139 -> V_244 = V_364 ;
if ( ! V_364 )
F_3 ( V_139 ) ;
return V_38 ;
}
int F_267 ( struct V_17 * V_18 ,
struct V_1 * V_139 , T_2 V_366 ,
int type )
{
struct V_153 V_234 ;
struct V_13 * V_248 ;
T_4 V_95 ;
int V_38 ;
while ( 1 ) {
if ( V_139 -> V_16 [ 0 ] == 0 ) {
F_3 ( V_139 ) ;
V_38 = F_197 ( V_18 , V_139 ) ;
if ( V_38 != 0 )
return V_38 ;
} else {
V_139 -> V_16 [ 0 ] -- ;
}
V_248 = V_139 -> V_7 [ 0 ] ;
V_95 = F_88 ( V_248 ) ;
if ( V_95 == 0 )
return 1 ;
if ( V_139 -> V_16 [ 0 ] == V_95 )
V_139 -> V_16 [ 0 ] -- ;
F_188 ( V_248 , & V_234 , V_139 -> V_16 [ 0 ] ) ;
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
int F_268 ( struct V_17 * V_18 ,
struct V_1 * V_139 , T_2 V_366 )
{
struct V_153 V_234 ;
struct V_13 * V_248 ;
T_4 V_95 ;
int V_38 ;
while ( 1 ) {
if ( V_139 -> V_16 [ 0 ] == 0 ) {
F_3 ( V_139 ) ;
V_38 = F_197 ( V_18 , V_139 ) ;
if ( V_38 != 0 )
return V_38 ;
} else {
V_139 -> V_16 [ 0 ] -- ;
}
V_248 = V_139 -> V_7 [ 0 ] ;
V_95 = F_88 ( V_248 ) ;
if ( V_95 == 0 )
return 1 ;
if ( V_139 -> V_16 [ 0 ] == V_95 )
V_139 -> V_16 [ 0 ] -- ;
F_188 ( V_248 , & V_234 , V_139 -> V_16 [ 0 ] ) ;
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
