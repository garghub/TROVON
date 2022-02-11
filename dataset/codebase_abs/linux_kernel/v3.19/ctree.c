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
F_25 ( & V_19 -> V_23 -> V_24 ) ;
if ( F_26 ( V_25 , & V_19 -> V_26 ) &&
F_27 ( & V_19 -> V_27 ) ) {
F_28 ( & V_19 -> V_27 ,
& V_19 -> V_23 -> V_28 ) ;
}
F_29 ( & V_19 -> V_23 -> V_24 ) ;
}
int F_30 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_14 * V_31 ,
struct V_14 * * V_32 , T_2 V_33 )
{
struct V_14 * V_34 ;
int V_35 = 0 ;
int V_36 ;
struct V_37 V_38 ;
F_31 ( F_26 ( V_39 , & V_19 -> V_26 ) &&
V_30 -> V_40 != V_19 -> V_23 -> V_41 -> V_40 ) ;
F_31 ( F_26 ( V_39 , & V_19 -> V_26 ) &&
V_30 -> V_40 != V_19 -> V_42 ) ;
V_36 = F_32 ( V_31 ) ;
if ( V_36 == 0 )
F_33 ( V_31 , & V_38 , 0 ) ;
else
F_34 ( V_31 , & V_38 , 0 ) ;
V_34 = F_35 ( V_30 , V_19 , 0 , V_33 ,
& V_38 , V_36 , V_31 -> V_43 , 0 ) ;
if ( F_36 ( V_34 ) )
return F_37 ( V_34 ) ;
F_38 ( V_34 , V_31 , 0 , 0 , V_34 -> V_44 ) ;
F_39 ( V_34 , V_34 -> V_43 ) ;
F_40 ( V_34 , V_30 -> V_40 ) ;
F_41 ( V_34 , V_45 ) ;
F_42 ( V_34 , V_46 |
V_47 ) ;
if ( V_33 == V_48 )
F_43 ( V_34 , V_47 ) ;
else
F_44 ( V_34 , V_33 ) ;
F_45 ( V_34 , V_19 -> V_23 -> V_49 , F_46 () ,
V_50 ) ;
F_31 ( F_47 ( V_31 ) > V_30 -> V_40 ) ;
if ( V_33 == V_48 )
V_35 = F_48 ( V_30 , V_19 , V_34 , 1 ) ;
else
V_35 = F_48 ( V_30 , V_19 , V_34 , 0 ) ;
if ( V_35 )
return V_35 ;
F_49 ( V_34 ) ;
* V_32 = V_34 ;
return 0 ;
}
static inline void F_50 ( struct V_51 * V_23 )
{
F_51 ( & V_23 -> V_52 ) ;
}
static inline void F_52 ( struct V_51 * V_23 )
{
F_53 ( & V_23 -> V_52 ) ;
}
static inline void F_54 ( struct V_51 * V_23 )
{
F_55 ( & V_23 -> V_52 ) ;
}
static inline void F_56 ( struct V_51 * V_23 )
{
F_57 ( & V_23 -> V_52 ) ;
}
static inline T_2 F_58 ( struct V_51 * V_23 )
{
return F_59 ( & V_23 -> V_53 ) ;
}
T_2 F_60 ( struct V_51 * V_23 ,
struct V_54 * V_55 )
{
F_54 ( V_23 ) ;
F_25 ( & V_23 -> V_56 ) ;
if ( ! V_55 -> V_57 ) {
V_55 -> V_57 = F_58 ( V_23 ) ;
F_61 ( & V_55 -> V_58 , & V_23 -> V_59 ) ;
}
F_29 ( & V_23 -> V_56 ) ;
F_56 ( V_23 ) ;
return V_55 -> V_57 ;
}
void F_62 ( struct V_51 * V_23 ,
struct V_54 * V_55 )
{
struct V_60 * V_61 ;
struct V_62 * V_21 ;
struct V_62 * V_63 ;
struct V_54 * V_64 ;
struct V_65 * V_66 ;
T_2 V_67 = ( T_2 ) - 1 ;
T_2 V_68 = V_55 -> V_57 ;
if ( ! V_68 )
return;
F_25 ( & V_23 -> V_56 ) ;
F_63 ( & V_55 -> V_58 ) ;
V_55 -> V_57 = 0 ;
F_64 (cur_elem, &fs_info->tree_mod_seq_list, list) {
if ( V_64 -> V_57 < V_67 ) {
if ( V_68 > V_64 -> V_57 ) {
F_29 ( & V_23 -> V_56 ) ;
return;
}
V_67 = V_64 -> V_57 ;
}
}
F_29 ( & V_23 -> V_56 ) ;
F_54 ( V_23 ) ;
V_61 = & V_23 -> V_69 ;
for ( V_21 = F_65 ( V_61 ) ; V_21 ; V_21 = V_63 ) {
V_63 = F_66 ( V_21 ) ;
V_66 = F_67 ( V_21 , struct V_65 , V_21 ) ;
if ( V_66 -> V_57 > V_67 )
continue;
F_68 ( V_21 , V_61 ) ;
F_69 ( V_66 ) ;
}
F_56 ( V_23 ) ;
}
static T_1 int
F_70 ( struct V_51 * V_23 , struct V_65 * V_66 )
{
struct V_60 * V_61 ;
struct V_62 * * V_70 ;
struct V_62 * V_71 = NULL ;
struct V_65 * V_72 ;
F_71 ( ! V_66 ) ;
V_66 -> V_57 = F_58 ( V_23 ) ;
V_61 = & V_23 -> V_69 ;
V_70 = & V_61 -> V_62 ;
while ( * V_70 ) {
V_72 = F_67 ( * V_70 , struct V_65 , V_21 ) ;
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
F_72 ( & V_66 -> V_21 , V_71 , V_70 ) ;
F_73 ( & V_66 -> V_21 , V_61 ) ;
return 0 ;
}
static inline int F_74 ( struct V_51 * V_23 ,
struct V_14 * V_20 ) {
F_75 () ;
if ( F_27 ( & ( V_23 ) -> V_59 ) )
return 1 ;
if ( V_20 && F_32 ( V_20 ) == 0 )
return 1 ;
F_54 ( V_23 ) ;
if ( F_27 ( & ( V_23 ) -> V_59 ) ) {
F_56 ( V_23 ) ;
return 1 ;
}
return 0 ;
}
static inline int F_76 ( const struct V_51 * V_23 ,
struct V_14 * V_20 )
{
F_75 () ;
if ( F_27 ( & ( V_23 ) -> V_59 ) )
return 0 ;
if ( V_20 && F_32 ( V_20 ) == 0 )
return 0 ;
return 1 ;
}
static struct V_65 *
F_77 ( struct V_14 * V_20 , int V_77 ,
enum V_78 V_79 , T_3 V_80 )
{
struct V_65 * V_66 ;
V_66 = F_78 ( sizeof( * V_66 ) , V_80 ) ;
if ( ! V_66 )
return NULL ;
V_66 -> V_73 = V_20 -> V_43 >> V_81 ;
if ( V_79 != V_82 ) {
F_34 ( V_20 , & V_66 -> V_83 , V_77 ) ;
V_66 -> V_84 = F_79 ( V_20 , V_77 ) ;
}
V_66 -> V_79 = V_79 ;
V_66 -> V_77 = V_77 ;
V_66 -> V_85 = F_80 ( V_20 , V_77 ) ;
F_81 ( & V_66 -> V_21 ) ;
return V_66 ;
}
static T_1 int
F_82 ( struct V_51 * V_23 ,
struct V_14 * V_20 , int V_77 ,
enum V_78 V_79 , T_3 V_80 )
{
struct V_65 * V_66 ;
int V_35 ;
if ( ! F_76 ( V_23 , V_20 ) )
return 0 ;
V_66 = F_77 ( V_20 , V_77 , V_79 , V_80 ) ;
if ( ! V_66 )
return - V_86 ;
if ( F_74 ( V_23 , V_20 ) ) {
F_69 ( V_66 ) ;
return 0 ;
}
V_35 = F_70 ( V_23 , V_66 ) ;
F_56 ( V_23 ) ;
if ( V_35 )
F_69 ( V_66 ) ;
return V_35 ;
}
static T_1 int
F_83 ( struct V_51 * V_23 ,
struct V_14 * V_20 , int V_87 , int V_88 ,
int V_89 , T_3 V_80 )
{
struct V_65 * V_66 = NULL ;
struct V_65 * * V_90 = NULL ;
int V_35 = 0 ;
int V_6 ;
int V_91 = 0 ;
if ( ! F_76 ( V_23 , V_20 ) )
return 0 ;
V_90 = F_78 ( V_89 * sizeof( struct V_65 * ) , V_80 ) ;
if ( ! V_90 )
return - V_86 ;
V_66 = F_78 ( sizeof( * V_66 ) , V_80 ) ;
if ( ! V_66 ) {
V_35 = - V_86 ;
goto V_92;
}
V_66 -> V_73 = V_20 -> V_43 >> V_81 ;
V_66 -> V_77 = V_88 ;
V_66 -> V_93 . V_87 = V_87 ;
V_66 -> V_93 . V_89 = V_89 ;
V_66 -> V_79 = V_94 ;
for ( V_6 = 0 ; V_6 + V_87 < V_88 && V_6 < V_89 ; V_6 ++ ) {
V_90 [ V_6 ] = F_77 ( V_20 , V_6 + V_87 ,
V_95 , V_80 ) ;
if ( ! V_90 [ V_6 ] ) {
V_35 = - V_86 ;
goto V_92;
}
}
if ( F_74 ( V_23 , V_20 ) )
goto V_92;
V_91 = 1 ;
for ( V_6 = 0 ; V_6 + V_87 < V_88 && V_6 < V_89 ; V_6 ++ ) {
V_35 = F_70 ( V_23 , V_90 [ V_6 ] ) ;
if ( V_35 )
goto V_92;
}
V_35 = F_70 ( V_23 , V_66 ) ;
if ( V_35 )
goto V_92;
F_56 ( V_23 ) ;
F_69 ( V_90 ) ;
return 0 ;
V_92:
for ( V_6 = 0 ; V_6 < V_89 ; V_6 ++ ) {
if ( V_90 [ V_6 ] && ! F_84 ( & V_90 [ V_6 ] -> V_21 ) )
F_68 ( & V_90 [ V_6 ] -> V_21 , & V_23 -> V_69 ) ;
F_69 ( V_90 [ V_6 ] ) ;
}
if ( V_91 )
F_56 ( V_23 ) ;
F_69 ( V_90 ) ;
F_69 ( V_66 ) ;
return V_35 ;
}
static inline int
F_85 ( struct V_51 * V_23 ,
struct V_65 * * V_90 ,
int V_96 )
{
int V_6 , V_97 ;
int V_35 ;
for ( V_6 = V_96 - 1 ; V_6 >= 0 ; V_6 -- ) {
V_35 = F_70 ( V_23 , V_90 [ V_6 ] ) ;
if ( V_35 ) {
for ( V_97 = V_96 - 1 ; V_97 > V_6 ; V_97 -- )
F_68 ( & V_90 [ V_97 ] -> V_21 ,
& V_23 -> V_69 ) ;
return V_35 ;
}
}
return 0 ;
}
static T_1 int
F_86 ( struct V_51 * V_23 ,
struct V_14 * V_98 ,
struct V_14 * V_99 , T_3 V_80 ,
int V_100 )
{
struct V_65 * V_66 = NULL ;
struct V_65 * * V_90 = NULL ;
int V_96 = 0 ;
int V_35 = 0 ;
int V_6 ;
if ( ! F_76 ( V_23 , NULL ) )
return 0 ;
if ( V_100 && F_32 ( V_98 ) > 0 ) {
V_96 = F_87 ( V_98 ) ;
V_90 = F_78 ( V_96 * sizeof( struct V_65 * ) ,
V_80 ) ;
if ( ! V_90 ) {
V_35 = - V_86 ;
goto V_92;
}
for ( V_6 = 0 ; V_6 < V_96 ; V_6 ++ ) {
V_90 [ V_6 ] = F_77 ( V_98 , V_6 ,
V_101 , V_80 ) ;
if ( ! V_90 [ V_6 ] ) {
V_35 = - V_86 ;
goto V_92;
}
}
}
V_66 = F_78 ( sizeof( * V_66 ) , V_80 ) ;
if ( ! V_66 ) {
V_35 = - V_86 ;
goto V_92;
}
V_66 -> V_73 = V_99 -> V_43 >> V_81 ;
V_66 -> V_98 . V_102 = V_98 -> V_43 ;
V_66 -> V_98 . V_36 = F_32 ( V_98 ) ;
V_66 -> V_85 = F_47 ( V_98 ) ;
V_66 -> V_79 = V_103 ;
if ( F_74 ( V_23 , NULL ) )
goto V_92;
if ( V_90 )
V_35 = F_85 ( V_23 , V_90 , V_96 ) ;
if ( ! V_35 )
V_35 = F_70 ( V_23 , V_66 ) ;
F_56 ( V_23 ) ;
if ( V_35 )
goto V_92;
F_69 ( V_90 ) ;
return V_35 ;
V_92:
if ( V_90 ) {
for ( V_6 = 0 ; V_6 < V_96 ; V_6 ++ )
F_69 ( V_90 [ V_6 ] ) ;
F_69 ( V_90 ) ;
}
F_69 ( V_66 ) ;
return V_35 ;
}
static struct V_65 *
F_88 ( struct V_51 * V_23 , T_2 V_43 , T_2 V_67 ,
int V_104 )
{
struct V_60 * V_61 ;
struct V_62 * V_21 ;
struct V_65 * V_72 = NULL ;
struct V_65 * V_105 = NULL ;
T_2 V_73 = V_43 >> V_81 ;
F_50 ( V_23 ) ;
V_61 = & V_23 -> V_69 ;
V_21 = V_61 -> V_62 ;
while ( V_21 ) {
V_72 = F_67 ( V_21 , struct V_65 , V_21 ) ;
if ( V_72 -> V_73 < V_73 ) {
V_21 = V_21 -> V_74 ;
} else if ( V_72 -> V_73 > V_73 ) {
V_21 = V_21 -> V_75 ;
} else if ( V_72 -> V_57 < V_67 ) {
V_21 = V_21 -> V_74 ;
} else if ( ! V_104 ) {
if ( V_105 )
F_71 ( V_105 -> V_57 > V_72 -> V_57 ) ;
V_105 = V_72 ;
V_21 = V_21 -> V_74 ;
} else if ( V_72 -> V_57 > V_67 ) {
if ( V_105 )
F_71 ( V_105 -> V_57 < V_72 -> V_57 ) ;
V_105 = V_72 ;
V_21 = V_21 -> V_75 ;
} else {
V_105 = V_72 ;
break;
}
}
F_52 ( V_23 ) ;
return V_105 ;
}
static struct V_65 *
F_89 ( struct V_51 * V_23 , T_2 V_43 ,
T_2 V_67 )
{
return F_88 ( V_23 , V_43 , V_67 , 1 ) ;
}
static struct V_65 *
F_90 ( struct V_51 * V_23 , T_2 V_43 , T_2 V_67 )
{
return F_88 ( V_23 , V_43 , V_67 , 0 ) ;
}
static T_1 int
F_91 ( struct V_51 * V_23 , struct V_14 * V_106 ,
struct V_14 * V_107 , unsigned long V_108 ,
unsigned long V_109 , int V_89 )
{
int V_35 = 0 ;
struct V_65 * * V_90 = NULL ;
struct V_65 * * V_110 , * * V_111 ;
int V_6 ;
int V_91 = 0 ;
if ( ! F_76 ( V_23 , NULL ) )
return 0 ;
if ( F_32 ( V_106 ) == 0 && F_32 ( V_107 ) == 0 )
return 0 ;
V_90 = F_78 ( V_89 * 2 * sizeof( struct V_65 * ) ,
V_4 ) ;
if ( ! V_90 )
return - V_86 ;
V_110 = V_90 ;
V_111 = V_90 + V_89 ;
for ( V_6 = 0 ; V_6 < V_89 ; V_6 ++ ) {
V_111 [ V_6 ] = F_77 ( V_107 , V_6 + V_109 ,
V_112 , V_4 ) ;
if ( ! V_111 [ V_6 ] ) {
V_35 = - V_86 ;
goto V_92;
}
V_110 [ V_6 ] = F_77 ( V_106 , V_6 + V_108 ,
V_82 , V_4 ) ;
if ( ! V_110 [ V_6 ] ) {
V_35 = - V_86 ;
goto V_92;
}
}
if ( F_74 ( V_23 , NULL ) )
goto V_92;
V_91 = 1 ;
for ( V_6 = 0 ; V_6 < V_89 ; V_6 ++ ) {
V_35 = F_70 ( V_23 , V_111 [ V_6 ] ) ;
if ( V_35 )
goto V_92;
V_35 = F_70 ( V_23 , V_110 [ V_6 ] ) ;
if ( V_35 )
goto V_92;
}
F_56 ( V_23 ) ;
F_69 ( V_90 ) ;
return 0 ;
V_92:
for ( V_6 = 0 ; V_6 < V_89 * 2 ; V_6 ++ ) {
if ( V_90 [ V_6 ] && ! F_84 ( & V_90 [ V_6 ] -> V_21 ) )
F_68 ( & V_90 [ V_6 ] -> V_21 , & V_23 -> V_69 ) ;
F_69 ( V_90 [ V_6 ] ) ;
}
if ( V_91 )
F_56 ( V_23 ) ;
F_69 ( V_90 ) ;
return V_35 ;
}
static inline void
F_92 ( struct V_51 * V_23 , struct V_14 * V_106 ,
int V_108 , int V_109 , int V_89 )
{
int V_35 ;
V_35 = F_83 ( V_23 , V_106 , V_108 , V_109 ,
V_89 , V_4 ) ;
F_71 ( V_35 < 0 ) ;
}
static T_1 void
F_93 ( struct V_51 * V_23 ,
struct V_14 * V_20 , int V_77 , int V_113 )
{
int V_35 ;
V_35 = F_82 ( V_23 , V_20 , V_77 ,
V_114 ,
V_113 ? V_115 : V_4 ) ;
F_71 ( V_35 < 0 ) ;
}
static T_1 int
F_94 ( struct V_51 * V_23 , struct V_14 * V_20 )
{
struct V_65 * * V_90 = NULL ;
int V_96 = 0 ;
int V_6 ;
int V_35 = 0 ;
if ( F_32 ( V_20 ) == 0 )
return 0 ;
if ( ! F_76 ( V_23 , NULL ) )
return 0 ;
V_96 = F_87 ( V_20 ) ;
V_90 = F_78 ( V_96 * sizeof( struct V_65 * ) ,
V_4 ) ;
if ( ! V_90 )
return - V_86 ;
for ( V_6 = 0 ; V_6 < V_96 ; V_6 ++ ) {
V_90 [ V_6 ] = F_77 ( V_20 , V_6 ,
V_101 , V_4 ) ;
if ( ! V_90 [ V_6 ] ) {
V_35 = - V_86 ;
goto V_92;
}
}
if ( F_74 ( V_23 , V_20 ) )
goto V_92;
V_35 = F_85 ( V_23 , V_90 , V_96 ) ;
F_56 ( V_23 ) ;
if ( V_35 )
goto V_92;
F_69 ( V_90 ) ;
return 0 ;
V_92:
for ( V_6 = 0 ; V_6 < V_96 ; V_6 ++ )
F_69 ( V_90 [ V_6 ] ) ;
F_69 ( V_90 ) ;
return V_35 ;
}
static T_1 void
F_95 ( struct V_18 * V_19 ,
struct V_14 * V_116 ,
int V_100 )
{
int V_35 ;
V_35 = F_86 ( V_19 -> V_23 , V_19 -> V_21 ,
V_116 , V_4 , V_100 ) ;
F_71 ( V_35 < 0 ) ;
}
int F_96 ( struct V_18 * V_19 ,
struct V_14 * V_31 )
{
if ( F_26 ( V_39 , & V_19 -> V_26 ) &&
V_31 != V_19 -> V_21 && V_31 != V_19 -> V_117 &&
( F_47 ( V_31 ) <=
F_97 ( & V_19 -> V_118 ) ||
F_98 ( V_31 , V_47 ) ) )
return 1 ;
#ifdef F_99
if ( F_26 ( V_39 , & V_19 -> V_26 ) &&
F_100 ( V_31 ) < V_45 )
return 1 ;
#endif
return 0 ;
}
static T_1 int F_101 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_14 * V_31 ,
struct V_14 * V_34 ,
int * V_119 )
{
T_2 V_22 ;
T_2 V_120 ;
T_2 V_80 ;
T_2 V_121 = 0 ;
int V_35 ;
if ( F_96 ( V_19 , V_31 ) ) {
V_35 = F_102 ( V_30 , V_19 , V_31 -> V_43 ,
F_32 ( V_31 ) , 1 ,
& V_22 , & V_80 ) ;
if ( V_35 )
return V_35 ;
if ( V_22 == 0 ) {
V_35 = - V_122 ;
F_103 ( V_19 -> V_23 , V_35 ) ;
return V_35 ;
}
} else {
V_22 = 1 ;
if ( V_19 -> V_123 . V_124 == V_48 ||
F_100 ( V_31 ) < V_45 )
V_80 = V_125 ;
else
V_80 = 0 ;
}
V_120 = F_104 ( V_31 ) ;
F_71 ( V_120 == V_48 &&
! ( V_80 & V_125 ) ) ;
if ( V_22 > 1 ) {
if ( ( V_120 == V_19 -> V_123 . V_124 ||
V_19 -> V_123 . V_124 == V_48 ) &&
! ( V_80 & V_125 ) ) {
V_35 = F_48 ( V_30 , V_19 , V_31 , 1 ) ;
F_71 ( V_35 ) ;
if ( V_19 -> V_123 . V_124 ==
V_48 ) {
V_35 = F_105 ( V_30 , V_19 , V_31 , 0 ) ;
F_71 ( V_35 ) ;
V_35 = F_48 ( V_30 , V_19 , V_34 , 1 ) ;
F_71 ( V_35 ) ;
}
V_121 |= V_125 ;
} else {
if ( V_19 -> V_123 . V_124 ==
V_48 )
V_35 = F_48 ( V_30 , V_19 , V_34 , 1 ) ;
else
V_35 = F_48 ( V_30 , V_19 , V_34 , 0 ) ;
F_71 ( V_35 ) ;
}
if ( V_121 != 0 ) {
int V_36 = F_32 ( V_31 ) ;
V_35 = F_106 ( V_30 , V_19 ,
V_31 -> V_43 ,
V_31 -> V_44 ,
V_121 , V_36 , 0 ) ;
if ( V_35 )
return V_35 ;
}
} else {
if ( V_80 & V_125 ) {
if ( V_19 -> V_123 . V_124 ==
V_48 )
V_35 = F_48 ( V_30 , V_19 , V_34 , 1 ) ;
else
V_35 = F_48 ( V_30 , V_19 , V_34 , 0 ) ;
F_71 ( V_35 ) ;
V_35 = F_105 ( V_30 , V_19 , V_31 , 1 ) ;
F_71 ( V_35 ) ;
}
F_107 ( V_30 , V_19 , V_31 ) ;
* V_119 = 1 ;
}
return 0 ;
}
static T_1 int F_108 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_14 * V_31 ,
struct V_14 * V_71 , int V_126 ,
struct V_14 * * V_32 ,
T_2 V_127 , T_2 V_128 )
{
struct V_37 V_38 ;
struct V_14 * V_34 ;
int V_36 , V_35 ;
int V_119 = 0 ;
int V_129 = 0 ;
T_2 V_130 ;
if ( * V_32 == V_31 )
V_129 = 1 ;
F_109 ( V_31 ) ;
F_31 ( F_26 ( V_39 , & V_19 -> V_26 ) &&
V_30 -> V_40 != V_19 -> V_23 -> V_41 -> V_40 ) ;
F_31 ( F_26 ( V_39 , & V_19 -> V_26 ) &&
V_30 -> V_40 != V_19 -> V_42 ) ;
V_36 = F_32 ( V_31 ) ;
if ( V_36 == 0 )
F_33 ( V_31 , & V_38 , 0 ) ;
else
F_34 ( V_31 , & V_38 , 0 ) ;
if ( V_19 -> V_123 . V_124 == V_48 ) {
if ( V_71 )
V_130 = V_71 -> V_43 ;
else
V_130 = 0 ;
} else
V_130 = 0 ;
V_34 = F_35 ( V_30 , V_19 , V_130 ,
V_19 -> V_123 . V_124 , & V_38 , V_36 ,
V_127 , V_128 ) ;
if ( F_36 ( V_34 ) )
return F_37 ( V_34 ) ;
F_38 ( V_34 , V_31 , 0 , 0 , V_34 -> V_44 ) ;
F_39 ( V_34 , V_34 -> V_43 ) ;
F_40 ( V_34 , V_30 -> V_40 ) ;
F_41 ( V_34 , V_45 ) ;
F_42 ( V_34 , V_46 |
V_47 ) ;
if ( V_19 -> V_123 . V_124 == V_48 )
F_43 ( V_34 , V_47 ) ;
else
F_44 ( V_34 , V_19 -> V_123 . V_124 ) ;
F_45 ( V_34 , V_19 -> V_23 -> V_49 , F_46 () ,
V_50 ) ;
V_35 = F_101 ( V_30 , V_19 , V_31 , V_34 , & V_119 ) ;
if ( V_35 ) {
F_110 ( V_30 , V_19 , V_35 ) ;
return V_35 ;
}
if ( F_26 ( V_39 , & V_19 -> V_26 ) ) {
V_35 = F_111 ( V_30 , V_19 , V_31 , V_34 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_31 == V_19 -> V_21 ) {
F_31 ( V_71 && V_71 != V_31 ) ;
if ( V_19 -> V_123 . V_124 == V_48 ||
F_100 ( V_31 ) < V_45 )
V_130 = V_31 -> V_43 ;
else
V_130 = 0 ;
F_112 ( V_34 ) ;
F_95 ( V_19 , V_34 , 1 ) ;
F_113 ( V_19 -> V_21 , V_34 ) ;
F_114 ( V_30 , V_19 , V_31 , V_130 ,
V_119 ) ;
F_11 ( V_31 ) ;
F_24 ( V_19 ) ;
} else {
if ( V_19 -> V_123 . V_124 == V_48 )
V_130 = V_71 -> V_43 ;
else
V_130 = 0 ;
F_31 ( V_30 -> V_40 != F_47 ( V_71 ) ) ;
F_82 ( V_19 -> V_23 , V_71 , V_126 ,
V_114 , V_4 ) ;
F_115 ( V_71 , V_126 ,
V_34 -> V_43 ) ;
F_116 ( V_71 , V_126 ,
V_30 -> V_40 ) ;
F_49 ( V_71 ) ;
if ( V_119 ) {
V_35 = F_94 ( V_19 -> V_23 , V_31 ) ;
if ( V_35 ) {
F_110 ( V_30 , V_19 , V_35 ) ;
return V_35 ;
}
}
F_114 ( V_30 , V_19 , V_31 , V_130 ,
V_119 ) ;
}
if ( V_129 )
F_20 ( V_31 ) ;
F_117 ( V_31 ) ;
F_49 ( V_34 ) ;
* V_32 = V_34 ;
return 0 ;
}
static struct V_65 *
F_118 ( struct V_51 * V_23 ,
struct V_14 * V_131 , T_2 V_132 )
{
struct V_65 * V_66 ;
struct V_65 * V_105 = NULL ;
T_2 V_133 = V_131 -> V_43 ;
int V_134 = 0 ;
if ( ! V_132 )
return NULL ;
while ( 1 ) {
V_66 = F_89 ( V_23 , V_133 ,
V_132 ) ;
if ( ! V_134 && ! V_66 )
return NULL ;
if ( ! V_66 )
break;
if ( V_66 -> V_79 != V_103 )
break;
V_105 = V_66 ;
V_133 = V_66 -> V_98 . V_102 ;
V_134 = 1 ;
}
if ( ! V_105 )
V_105 = V_66 ;
return V_105 ;
}
static void
F_119 ( struct V_51 * V_23 , struct V_14 * V_20 ,
T_2 V_132 , struct V_65 * V_135 )
{
T_4 V_136 ;
struct V_62 * V_63 ;
struct V_65 * V_66 = V_135 ;
unsigned long V_137 ;
unsigned long V_138 ;
unsigned long V_139 = sizeof( struct V_140 ) ;
V_136 = F_87 ( V_20 ) ;
F_50 ( V_23 ) ;
while ( V_66 && V_66 -> V_57 >= V_132 ) {
switch ( V_66 -> V_79 ) {
case V_101 :
F_71 ( V_66 -> V_77 < V_136 ) ;
case V_95 :
case V_112 :
F_120 ( V_20 , & V_66 -> V_83 , V_66 -> V_77 ) ;
F_115 ( V_20 , V_66 -> V_77 , V_66 -> V_84 ) ;
F_116 ( V_20 , V_66 -> V_77 ,
V_66 -> V_85 ) ;
V_136 ++ ;
break;
case V_114 :
F_71 ( V_66 -> V_77 >= V_136 ) ;
F_120 ( V_20 , & V_66 -> V_83 , V_66 -> V_77 ) ;
F_115 ( V_20 , V_66 -> V_77 , V_66 -> V_84 ) ;
F_116 ( V_20 , V_66 -> V_77 ,
V_66 -> V_85 ) ;
break;
case V_82 :
V_136 -- ;
break;
case V_94 :
V_137 = F_121 ( V_66 -> V_77 ) ;
V_138 = F_121 ( V_66 -> V_93 . V_87 ) ;
F_122 ( V_20 , V_137 , V_138 ,
V_66 -> V_93 . V_89 * V_139 ) ;
break;
case V_103 :
break;
}
V_63 = F_66 ( & V_66 -> V_21 ) ;
if ( ! V_63 )
break;
V_66 = F_67 ( V_63 , struct V_65 , V_21 ) ;
if ( V_66 -> V_73 != V_135 -> V_73 )
break;
}
F_52 ( V_23 ) ;
F_123 ( V_20 , V_136 ) ;
}
static struct V_14 *
F_124 ( struct V_51 * V_23 , struct V_1 * V_2 ,
struct V_14 * V_20 , T_2 V_132 )
{
struct V_14 * V_141 ;
struct V_65 * V_66 ;
if ( ! V_132 )
return V_20 ;
if ( F_32 ( V_20 ) == 0 )
return V_20 ;
V_66 = F_90 ( V_23 , V_20 -> V_43 , V_132 ) ;
if ( ! V_66 )
return V_20 ;
F_3 ( V_2 ) ;
F_4 ( V_20 , V_10 ) ;
if ( V_66 -> V_79 == V_101 ) {
F_71 ( V_66 -> V_77 != 0 ) ;
V_141 = F_125 ( V_20 -> V_43 ,
V_23 -> V_142 -> V_143 ) ;
if ( ! V_141 ) {
F_126 ( V_20 ) ;
F_11 ( V_20 ) ;
return NULL ;
}
F_39 ( V_141 , V_20 -> V_43 ) ;
F_41 ( V_141 ,
F_100 ( V_20 ) ) ;
F_44 ( V_141 , F_104 ( V_20 ) ) ;
F_127 ( V_141 , F_32 ( V_20 ) ) ;
} else {
V_141 = F_128 ( V_20 ) ;
if ( ! V_141 ) {
F_126 ( V_20 ) ;
F_11 ( V_20 ) ;
return NULL ;
}
}
F_5 ( V_2 , NULL , V_10 ) ;
F_126 ( V_20 ) ;
F_11 ( V_20 ) ;
F_112 ( V_141 ) ;
F_22 ( V_141 ) ;
F_119 ( V_23 , V_141 , V_132 , V_66 ) ;
F_31 ( F_87 ( V_141 ) >
F_129 ( V_23 -> V_142 ) ) ;
return V_141 ;
}
static inline struct V_14 *
F_130 ( struct V_18 * V_19 , T_2 V_132 )
{
struct V_65 * V_66 ;
struct V_14 * V_20 = NULL ;
struct V_14 * V_131 ;
struct V_14 * V_144 ;
struct V_145 * V_98 = NULL ;
T_2 V_146 = 0 ;
T_2 V_102 ;
V_131 = F_21 ( V_19 ) ;
V_66 = F_118 ( V_19 -> V_23 , V_131 , V_132 ) ;
if ( ! V_66 )
return V_131 ;
if ( V_66 -> V_79 == V_103 ) {
V_98 = & V_66 -> V_98 ;
V_146 = V_66 -> V_85 ;
V_102 = V_98 -> V_102 ;
} else {
V_102 = V_131 -> V_43 ;
}
V_66 = F_90 ( V_19 -> V_23 , V_102 , V_132 ) ;
if ( V_98 && V_66 && V_66 -> V_79 != V_101 ) {
F_23 ( V_131 ) ;
F_11 ( V_131 ) ;
V_144 = F_131 ( V_19 , V_102 , 0 ) ;
if ( F_31 ( ! V_144 || ! F_132 ( V_144 ) ) ) {
F_11 ( V_144 ) ;
F_133 ( V_19 -> V_23 ,
L_1 , V_102 ) ;
} else {
V_20 = F_128 ( V_144 ) ;
F_11 ( V_144 ) ;
}
} else if ( V_98 ) {
F_23 ( V_131 ) ;
F_11 ( V_131 ) ;
V_20 = F_125 ( V_102 , V_19 -> V_143 ) ;
} else {
F_4 ( V_131 , V_10 ) ;
V_20 = F_128 ( V_131 ) ;
F_126 ( V_131 ) ;
F_11 ( V_131 ) ;
}
if ( ! V_20 )
return NULL ;
F_112 ( V_20 ) ;
F_22 ( V_20 ) ;
if ( V_98 ) {
F_39 ( V_20 , V_20 -> V_43 ) ;
F_41 ( V_20 , V_45 ) ;
F_44 ( V_20 , F_104 ( V_131 ) ) ;
F_127 ( V_20 , V_98 -> V_36 ) ;
F_40 ( V_20 , V_146 ) ;
}
if ( V_66 )
F_119 ( V_19 -> V_23 , V_20 , V_132 , V_66 ) ;
else
F_31 ( F_32 ( V_20 ) != 0 ) ;
F_31 ( F_87 ( V_20 ) > F_129 ( V_19 ) ) ;
return V_20 ;
}
int F_134 ( struct V_18 * V_19 , T_2 V_132 )
{
struct V_65 * V_66 ;
int V_36 ;
struct V_14 * V_131 = F_12 ( V_19 ) ;
V_66 = F_118 ( V_19 -> V_23 , V_131 , V_132 ) ;
if ( V_66 && V_66 -> V_79 == V_103 ) {
V_36 = V_66 -> V_98 . V_36 ;
} else {
V_36 = F_32 ( V_131 ) ;
}
F_11 ( V_131 ) ;
return V_36 ;
}
static inline int F_135 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_14 * V_31 )
{
if ( F_136 ( V_19 ) )
return 0 ;
F_137 () ;
if ( F_47 ( V_31 ) == V_30 -> V_40 &&
! F_98 ( V_31 , V_46 ) &&
! ( V_19 -> V_123 . V_124 != V_48 &&
F_98 ( V_31 , V_47 ) ) &&
! F_26 ( V_147 , & V_19 -> V_26 ) )
return 0 ;
return 1 ;
}
T_1 int F_138 ( struct V_29 * V_30 ,
struct V_18 * V_19 , struct V_14 * V_31 ,
struct V_14 * V_71 , int V_126 ,
struct V_14 * * V_32 )
{
T_2 V_127 ;
int V_35 ;
if ( V_30 -> V_148 != V_19 -> V_23 -> V_41 )
F_139 ( 1 , V_149 L_2 ,
V_30 -> V_40 ,
V_19 -> V_23 -> V_41 -> V_40 ) ;
if ( V_30 -> V_40 != V_19 -> V_23 -> V_85 )
F_139 ( 1 , V_149 L_2 ,
V_30 -> V_40 , V_19 -> V_23 -> V_85 ) ;
if ( ! F_135 ( V_30 , V_19 , V_31 ) ) {
* V_32 = V_31 ;
return 0 ;
}
V_127 = V_31 -> V_43 & ~ ( ( T_2 ) ( 1024 * 1024 * 1024 ) - 1 ) ;
if ( V_71 )
F_140 ( V_71 ) ;
F_140 ( V_31 ) ;
V_35 = F_108 ( V_30 , V_19 , V_31 , V_71 ,
V_126 , V_32 , V_127 , 0 ) ;
F_141 ( V_19 , V_31 , * V_32 ) ;
return V_35 ;
}
static int F_142 ( T_2 V_150 , T_2 V_151 , T_4 V_152 )
{
if ( V_150 < V_151 && V_151 - ( V_150 + V_152 ) < 32768 )
return 1 ;
if ( V_150 > V_151 && V_150 - ( V_151 + V_152 ) < 32768 )
return 1 ;
return 0 ;
}
static int F_143 ( struct V_37 * V_153 , struct V_154 * V_155 )
{
struct V_154 V_156 ;
F_144 ( & V_156 , V_153 ) ;
return F_145 ( & V_156 , V_155 ) ;
}
int F_145 ( struct V_154 * V_156 , struct V_154 * V_155 )
{
if ( V_156 -> V_124 > V_155 -> V_124 )
return 1 ;
if ( V_156 -> V_124 < V_155 -> V_124 )
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
int F_146 ( struct V_29 * V_30 ,
struct V_18 * V_19 , struct V_14 * V_71 ,
int V_158 , T_2 * V_159 ,
struct V_154 * V_160 )
{
struct V_14 * V_72 ;
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
struct V_37 V_38 ;
V_166 = F_32 ( V_71 ) ;
F_31 ( V_30 -> V_148 != V_19 -> V_23 -> V_41 ) ;
F_31 ( V_30 -> V_40 != V_19 -> V_23 -> V_85 ) ;
V_163 = F_87 ( V_71 ) ;
V_152 = V_19 -> V_143 ;
V_164 = V_163 ;
if ( V_163 == 1 )
return 0 ;
F_140 ( V_71 ) ;
for ( V_6 = V_158 ; V_6 < V_164 ; V_6 ++ ) {
int V_169 = 1 ;
F_34 ( V_71 , & V_38 , V_6 ) ;
if ( ! V_168 && F_143 ( & V_38 , V_160 ) < 0 )
continue;
V_168 = 1 ;
V_150 = F_79 ( V_71 , V_6 ) ;
V_161 = F_80 ( V_71 , V_6 ) ;
if ( V_162 == 0 )
V_162 = V_150 ;
if ( V_6 > 0 ) {
V_151 = F_79 ( V_71 , V_6 - 1 ) ;
V_169 = F_142 ( V_150 , V_151 , V_152 ) ;
}
if ( ! V_169 && V_6 < V_164 - 2 ) {
V_151 = F_79 ( V_71 , V_6 + 1 ) ;
V_169 = F_142 ( V_150 , V_151 , V_152 ) ;
}
if ( V_169 ) {
V_162 = V_150 ;
continue;
}
V_72 = F_147 ( V_19 , V_150 ) ;
if ( V_72 )
V_167 = F_148 ( V_72 , V_161 , 0 ) ;
else
V_167 = 0 ;
if ( ! V_72 || ! V_167 ) {
if ( ! V_72 ) {
V_72 = F_131 ( V_19 , V_150 , V_161 ) ;
if ( ! V_72 || ! F_132 ( V_72 ) ) {
F_11 ( V_72 ) ;
return - V_170 ;
}
} else if ( ! V_167 ) {
V_165 = F_149 ( V_72 , V_161 ) ;
if ( V_165 ) {
F_11 ( V_72 ) ;
return V_165 ;
}
}
}
if ( V_127 == 0 )
V_127 = V_162 ;
F_19 ( V_72 ) ;
F_140 ( V_72 ) ;
V_165 = F_108 ( V_30 , V_19 , V_72 , V_71 , V_6 ,
& V_72 , V_127 ,
F_150 ( 16 * V_152 ,
( V_164 - V_6 ) * V_152 ) ) ;
if ( V_165 ) {
F_20 ( V_72 ) ;
F_11 ( V_72 ) ;
break;
}
V_127 = V_72 -> V_43 ;
V_162 = V_72 -> V_43 ;
* V_159 = V_127 ;
F_20 ( V_72 ) ;
F_11 ( V_72 ) ;
}
return V_165 ;
}
static inline unsigned int F_151 ( struct V_18 * V_19 ,
struct V_14 * V_171 )
{
T_4 V_172 = F_87 ( V_171 ) ;
if ( V_172 == 0 )
return F_152 ( V_19 ) ;
return F_153 ( V_171 , V_172 - 1 ) ;
}
static T_1 int F_154 ( struct V_14 * V_20 ,
unsigned long V_5 ,
int V_173 , struct V_154 * V_83 ,
int V_174 , int * V_77 )
{
int V_175 = 0 ;
int V_176 = V_174 ;
int V_177 ;
int V_35 ;
struct V_37 * V_178 = NULL ;
struct V_37 V_179 ;
unsigned long V_157 ;
char * V_180 = NULL ;
unsigned long V_181 = 0 ;
unsigned long V_182 = 0 ;
int V_165 ;
while ( V_175 < V_176 ) {
V_177 = ( V_175 + V_176 ) / 2 ;
V_157 = V_5 + V_177 * V_173 ;
if ( ! V_180 || V_157 < V_181 ||
( V_157 + sizeof( struct V_37 ) ) >
V_181 + V_182 ) {
V_165 = F_155 ( V_20 , V_157 ,
sizeof( struct V_37 ) ,
& V_180 , & V_181 , & V_182 ) ;
if ( ! V_165 ) {
V_178 = (struct V_37 * ) ( V_180 + V_157 -
V_181 ) ;
} else {
F_156 ( V_20 , & V_179 ,
V_157 , sizeof( V_179 ) ) ;
V_178 = & V_179 ;
}
} else {
V_178 = (struct V_37 * ) ( V_180 + V_157 -
V_181 ) ;
}
V_35 = F_143 ( V_178 , V_83 ) ;
if ( V_35 < 0 )
V_175 = V_177 + 1 ;
else if ( V_35 > 0 )
V_176 = V_177 ;
else {
* V_77 = V_177 ;
return 0 ;
}
}
* V_77 = V_175 ;
return 1 ;
}
static int F_157 ( struct V_14 * V_20 , struct V_154 * V_83 ,
int V_36 , int * V_77 )
{
if ( V_36 == 0 )
return F_154 ( V_20 ,
F_158 ( struct V_183 , V_184 ) ,
sizeof( struct V_185 ) ,
V_83 , F_87 ( V_20 ) ,
V_77 ) ;
else
return F_154 ( V_20 ,
F_158 ( struct V_186 , V_187 ) ,
sizeof( struct V_140 ) ,
V_83 , F_87 ( V_20 ) ,
V_77 ) ;
}
int F_159 ( struct V_14 * V_20 , struct V_154 * V_83 ,
int V_36 , int * V_77 )
{
return F_157 ( V_20 , V_83 , V_36 , V_77 ) ;
}
static void F_160 ( struct V_18 * V_19 , T_4 V_188 )
{
F_25 ( & V_19 -> V_189 ) ;
F_161 ( & V_19 -> V_118 ,
F_162 ( & V_19 -> V_118 ) + V_188 ) ;
F_29 ( & V_19 -> V_189 ) ;
}
static void F_163 ( struct V_18 * V_19 , T_4 V_188 )
{
F_25 ( & V_19 -> V_189 ) ;
F_161 ( & V_19 -> V_118 ,
F_162 ( & V_19 -> V_118 ) - V_188 ) ;
F_29 ( & V_19 -> V_189 ) ;
}
T_1 int F_164 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_36 )
{
struct V_14 * V_190 = NULL ;
struct V_14 * V_177 ;
struct V_14 * V_191 = NULL ;
struct V_14 * V_71 = NULL ;
int V_35 = 0 ;
int V_192 ;
int V_193 ;
int V_194 = V_2 -> V_17 [ V_36 ] ;
T_2 V_195 ;
if ( V_36 == 0 )
return 0 ;
V_177 = V_2 -> V_8 [ V_36 ] ;
F_31 ( V_2 -> V_9 [ V_36 ] != V_12 &&
V_2 -> V_9 [ V_36 ] != V_13 ) ;
F_31 ( F_47 ( V_177 ) != V_30 -> V_40 ) ;
V_195 = F_79 ( V_177 , V_194 ) ;
if ( V_36 < V_7 - 1 ) {
V_71 = V_2 -> V_8 [ V_36 + 1 ] ;
V_193 = V_2 -> V_17 [ V_36 + 1 ] ;
}
if ( ! V_71 ) {
struct V_14 * V_196 ;
if ( F_87 ( V_177 ) != 1 )
return 0 ;
V_196 = F_165 ( V_19 , V_177 , 0 ) ;
if ( ! V_196 ) {
V_35 = - V_122 ;
F_103 ( V_19 -> V_23 , V_35 ) ;
goto V_197;
}
F_19 ( V_196 ) ;
F_140 ( V_196 ) ;
V_35 = F_138 ( V_30 , V_19 , V_196 , V_177 , 0 , & V_196 ) ;
if ( V_35 ) {
F_20 ( V_196 ) ;
F_11 ( V_196 ) ;
goto V_197;
}
F_95 ( V_19 , V_196 , 1 ) ;
F_113 ( V_19 -> V_21 , V_196 ) ;
F_24 ( V_19 ) ;
F_20 ( V_196 ) ;
V_2 -> V_9 [ V_36 ] = 0 ;
V_2 -> V_8 [ V_36 ] = NULL ;
F_107 ( V_30 , V_19 , V_177 ) ;
F_20 ( V_177 ) ;
F_11 ( V_177 ) ;
F_163 ( V_19 , V_177 -> V_44 ) ;
F_114 ( V_30 , V_19 , V_177 , 0 , 1 ) ;
F_117 ( V_177 ) ;
return 0 ;
}
if ( F_87 ( V_177 ) >
F_129 ( V_19 ) / 4 )
return 0 ;
V_191 = F_165 ( V_19 , V_71 , V_193 - 1 ) ;
if ( V_191 ) {
F_19 ( V_191 ) ;
F_140 ( V_191 ) ;
V_192 = F_138 ( V_30 , V_19 , V_191 ,
V_71 , V_193 - 1 , & V_191 ) ;
if ( V_192 ) {
V_35 = V_192 ;
goto V_197;
}
}
V_190 = F_165 ( V_19 , V_71 , V_193 + 1 ) ;
if ( V_190 ) {
F_19 ( V_190 ) ;
F_140 ( V_190 ) ;
V_192 = F_138 ( V_30 , V_19 , V_190 ,
V_71 , V_193 + 1 , & V_190 ) ;
if ( V_192 ) {
V_35 = V_192 ;
goto V_197;
}
}
if ( V_191 ) {
V_194 += F_87 ( V_191 ) ;
V_192 = F_166 ( V_30 , V_19 , V_191 , V_177 , 1 ) ;
if ( V_192 < 0 )
V_35 = V_192 ;
}
if ( V_190 ) {
V_192 = F_166 ( V_30 , V_19 , V_177 , V_190 , 1 ) ;
if ( V_192 < 0 && V_192 != - V_198 )
V_35 = V_192 ;
if ( F_87 ( V_190 ) == 0 ) {
F_107 ( V_30 , V_19 , V_190 ) ;
F_20 ( V_190 ) ;
F_167 ( V_19 , V_2 , V_36 + 1 , V_193 + 1 ) ;
F_163 ( V_19 , V_190 -> V_44 ) ;
F_114 ( V_30 , V_19 , V_190 , 0 , 1 ) ;
F_117 ( V_190 ) ;
V_190 = NULL ;
} else {
struct V_37 V_199 ;
F_34 ( V_190 , & V_199 , 0 ) ;
F_93 ( V_19 -> V_23 , V_71 ,
V_193 + 1 , 0 ) ;
F_120 ( V_71 , & V_199 , V_193 + 1 ) ;
F_49 ( V_71 ) ;
}
}
if ( F_87 ( V_177 ) == 1 ) {
if ( ! V_191 ) {
V_35 = - V_122 ;
F_103 ( V_19 -> V_23 , V_35 ) ;
goto V_197;
}
V_192 = F_168 ( V_30 , V_19 , V_177 , V_191 ) ;
if ( V_192 < 0 ) {
V_35 = V_192 ;
goto V_197;
}
if ( V_192 == 1 ) {
V_192 = F_166 ( V_30 , V_19 , V_191 , V_177 , 1 ) ;
if ( V_192 < 0 )
V_35 = V_192 ;
}
F_71 ( V_192 == 1 ) ;
}
if ( F_87 ( V_177 ) == 0 ) {
F_107 ( V_30 , V_19 , V_177 ) ;
F_20 ( V_177 ) ;
F_167 ( V_19 , V_2 , V_36 + 1 , V_193 ) ;
F_163 ( V_19 , V_177 -> V_44 ) ;
F_114 ( V_30 , V_19 , V_177 , 0 , 1 ) ;
F_117 ( V_177 ) ;
V_177 = NULL ;
} else {
struct V_37 V_200 ;
F_34 ( V_177 , & V_200 , 0 ) ;
F_93 ( V_19 -> V_23 , V_71 ,
V_193 , 0 ) ;
F_120 ( V_71 , & V_200 , V_193 ) ;
F_49 ( V_71 ) ;
}
if ( V_191 ) {
if ( F_87 ( V_191 ) > V_194 ) {
F_112 ( V_191 ) ;
V_2 -> V_8 [ V_36 ] = V_191 ;
V_2 -> V_17 [ V_36 + 1 ] -= 1 ;
V_2 -> V_17 [ V_36 ] = V_194 ;
if ( V_177 ) {
F_20 ( V_177 ) ;
F_11 ( V_177 ) ;
}
} else {
V_194 -= F_87 ( V_191 ) ;
V_2 -> V_17 [ V_36 ] = V_194 ;
}
}
if ( V_195 !=
F_79 ( V_2 -> V_8 [ V_36 ] , V_2 -> V_17 [ V_36 ] ) )
F_169 () ;
V_197:
if ( V_190 ) {
F_20 ( V_190 ) ;
F_11 ( V_190 ) ;
}
if ( V_191 ) {
if ( V_2 -> V_8 [ V_36 ] != V_191 )
F_20 ( V_191 ) ;
F_11 ( V_191 ) ;
}
return V_35 ;
}
static T_1 int F_170 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_36 )
{
struct V_14 * V_190 = NULL ;
struct V_14 * V_177 ;
struct V_14 * V_191 = NULL ;
struct V_14 * V_71 = NULL ;
int V_35 = 0 ;
int V_192 ;
int V_193 ;
int V_194 = V_2 -> V_17 [ V_36 ] ;
if ( V_36 == 0 )
return 1 ;
V_177 = V_2 -> V_8 [ V_36 ] ;
F_31 ( F_47 ( V_177 ) != V_30 -> V_40 ) ;
if ( V_36 < V_7 - 1 ) {
V_71 = V_2 -> V_8 [ V_36 + 1 ] ;
V_193 = V_2 -> V_17 [ V_36 + 1 ] ;
}
if ( ! V_71 )
return 1 ;
V_191 = F_165 ( V_19 , V_71 , V_193 - 1 ) ;
if ( V_191 ) {
T_4 V_201 ;
F_19 ( V_191 ) ;
F_140 ( V_191 ) ;
V_201 = F_87 ( V_191 ) ;
if ( V_201 >= F_129 ( V_19 ) - 1 ) {
V_192 = 1 ;
} else {
V_35 = F_138 ( V_30 , V_19 , V_191 , V_71 ,
V_193 - 1 , & V_191 ) ;
if ( V_35 )
V_192 = 1 ;
else {
V_192 = F_166 ( V_30 , V_19 ,
V_191 , V_177 , 0 ) ;
}
}
if ( V_192 < 0 )
V_35 = V_192 ;
if ( V_192 == 0 ) {
struct V_37 V_38 ;
V_194 += V_201 ;
F_34 ( V_177 , & V_38 , 0 ) ;
F_93 ( V_19 -> V_23 , V_71 ,
V_193 , 0 ) ;
F_120 ( V_71 , & V_38 , V_193 ) ;
F_49 ( V_71 ) ;
if ( F_87 ( V_191 ) > V_194 ) {
V_2 -> V_8 [ V_36 ] = V_191 ;
V_2 -> V_17 [ V_36 + 1 ] -= 1 ;
V_2 -> V_17 [ V_36 ] = V_194 ;
F_20 ( V_177 ) ;
F_11 ( V_177 ) ;
} else {
V_194 -=
F_87 ( V_191 ) ;
V_2 -> V_17 [ V_36 ] = V_194 ;
F_20 ( V_191 ) ;
F_11 ( V_191 ) ;
}
return 0 ;
}
F_20 ( V_191 ) ;
F_11 ( V_191 ) ;
}
V_190 = F_165 ( V_19 , V_71 , V_193 + 1 ) ;
if ( V_190 ) {
T_4 V_202 ;
F_19 ( V_190 ) ;
F_140 ( V_190 ) ;
V_202 = F_87 ( V_190 ) ;
if ( V_202 >= F_129 ( V_19 ) - 1 ) {
V_192 = 1 ;
} else {
V_35 = F_138 ( V_30 , V_19 , V_190 ,
V_71 , V_193 + 1 ,
& V_190 ) ;
if ( V_35 )
V_192 = 1 ;
else {
V_192 = F_168 ( V_30 , V_19 ,
V_190 , V_177 ) ;
}
}
if ( V_192 < 0 )
V_35 = V_192 ;
if ( V_192 == 0 ) {
struct V_37 V_38 ;
F_34 ( V_190 , & V_38 , 0 ) ;
F_93 ( V_19 -> V_23 , V_71 ,
V_193 + 1 , 0 ) ;
F_120 ( V_71 , & V_38 , V_193 + 1 ) ;
F_49 ( V_71 ) ;
if ( F_87 ( V_177 ) <= V_194 ) {
V_2 -> V_8 [ V_36 ] = V_190 ;
V_2 -> V_17 [ V_36 + 1 ] += 1 ;
V_2 -> V_17 [ V_36 ] = V_194 -
F_87 ( V_177 ) ;
F_20 ( V_177 ) ;
F_11 ( V_177 ) ;
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
static void F_171 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int V_36 , int V_77 , T_2 V_124 )
{
struct V_14 * V_21 ;
struct V_37 V_38 ;
T_4 V_96 ;
T_2 V_203 ;
T_2 V_204 ;
T_2 V_205 = 0 ;
T_2 V_161 ;
int V_206 = V_2 -> V_207 ;
struct V_14 * V_20 ;
T_4 V_172 ;
T_4 V_152 ;
T_4 V_208 = 0 ;
if ( V_36 != 1 )
return;
if ( ! V_2 -> V_8 [ V_36 ] )
return;
V_21 = V_2 -> V_8 [ V_36 ] ;
V_203 = F_79 ( V_21 , V_77 ) ;
V_152 = V_19 -> V_143 ;
V_20 = F_147 ( V_19 , V_203 ) ;
if ( V_20 ) {
F_11 ( V_20 ) ;
return;
}
V_204 = V_203 ;
V_96 = F_87 ( V_21 ) ;
V_172 = V_77 ;
while ( 1 ) {
if ( V_206 < 0 ) {
if ( V_172 == 0 )
break;
V_172 -- ;
} else if ( V_206 > 0 ) {
V_172 ++ ;
if ( V_172 >= V_96 )
break;
}
if ( V_2 -> V_207 < 0 && V_124 ) {
F_34 ( V_21 , & V_38 , V_172 ) ;
if ( F_172 ( & V_38 ) != V_124 )
break;
}
V_203 = F_79 ( V_21 , V_172 ) ;
if ( ( V_203 <= V_204 && V_204 - V_203 <= 65536 ) ||
( V_203 > V_204 && V_203 - V_204 <= 65536 ) ) {
V_161 = F_80 ( V_21 , V_172 ) ;
F_173 ( V_19 , V_203 , V_152 ) ;
V_205 += V_152 ;
}
V_208 ++ ;
if ( ( V_205 > 65536 || V_208 > 32 ) )
break;
}
}
static T_1 void F_174 ( struct V_18 * V_19 ,
struct V_1 * V_2 , int V_36 )
{
int V_77 ;
int V_96 ;
struct V_14 * V_71 ;
struct V_14 * V_20 ;
T_2 V_161 ;
T_2 V_209 = 0 ;
T_2 V_210 = 0 ;
int V_152 ;
V_71 = V_2 -> V_8 [ V_36 + 1 ] ;
if ( ! V_71 )
return;
V_96 = F_87 ( V_71 ) ;
V_77 = V_2 -> V_17 [ V_36 + 1 ] ;
V_152 = V_19 -> V_143 ;
if ( V_77 > 0 ) {
V_209 = F_79 ( V_71 , V_77 - 1 ) ;
V_161 = F_80 ( V_71 , V_77 - 1 ) ;
V_20 = F_147 ( V_19 , V_209 ) ;
if ( V_20 && F_148 ( V_20 , V_161 , 1 ) != 0 )
V_209 = 0 ;
F_11 ( V_20 ) ;
}
if ( V_77 + 1 < V_96 ) {
V_210 = F_79 ( V_71 , V_77 + 1 ) ;
V_161 = F_80 ( V_71 , V_77 + 1 ) ;
V_20 = F_147 ( V_19 , V_210 ) ;
if ( V_20 && F_148 ( V_20 , V_161 , 1 ) != 0 )
V_210 = 0 ;
F_11 ( V_20 ) ;
}
if ( V_209 )
F_173 ( V_19 , V_209 , V_152 ) ;
if ( V_210 )
F_173 ( V_19 , V_210 , V_152 ) ;
}
static T_1 void F_175 ( struct V_1 * V_2 , int V_36 ,
int V_211 , int V_212 ,
int * V_213 )
{
int V_6 ;
int V_214 = V_36 ;
int V_215 = 0 ;
struct V_14 * V_216 ;
for ( V_6 = V_36 ; V_6 < V_7 ; V_6 ++ ) {
if ( ! V_2 -> V_8 [ V_6 ] )
break;
if ( ! V_2 -> V_9 [ V_6 ] )
break;
if ( ! V_215 && V_2 -> V_17 [ V_6 ] == 0 ) {
V_214 = V_6 + 1 ;
continue;
}
if ( ! V_215 && V_2 -> V_217 ) {
T_4 V_96 ;
V_216 = V_2 -> V_8 [ V_6 ] ;
V_96 = F_87 ( V_216 ) ;
if ( V_96 < 1 || V_2 -> V_17 [ V_6 ] >= V_96 - 1 ) {
V_214 = V_6 + 1 ;
continue;
}
}
if ( V_214 < V_6 && V_6 >= V_211 )
V_215 = 1 ;
V_216 = V_2 -> V_8 [ V_6 ] ;
if ( V_6 >= V_211 && V_6 > V_214 && V_2 -> V_9 [ V_6 ] ) {
F_10 ( V_216 , V_2 -> V_9 [ V_6 ] ) ;
V_2 -> V_9 [ V_6 ] = 0 ;
if ( V_213 &&
V_6 > V_212 &&
V_6 <= * V_213 ) {
* V_213 = V_6 - 1 ;
}
}
}
}
T_1 void F_176 ( struct V_1 * V_2 , int V_36 )
{
int V_6 ;
if ( V_2 -> V_217 )
return;
for ( V_6 = V_36 ; V_6 < V_7 ; V_6 ++ ) {
if ( ! V_2 -> V_8 [ V_6 ] )
continue;
if ( ! V_2 -> V_9 [ V_6 ] )
continue;
F_10 ( V_2 -> V_8 [ V_6 ] , V_2 -> V_9 [ V_6 ] ) ;
V_2 -> V_9 [ V_6 ] = 0 ;
}
}
static int
F_177 ( struct V_29 * V_30 ,
struct V_18 * V_19 , struct V_1 * V_5 ,
struct V_14 * * V_218 , int V_36 , int V_77 ,
struct V_154 * V_83 , T_2 V_132 )
{
T_2 V_150 ;
T_2 V_161 ;
struct V_14 * V_219 = * V_218 ;
struct V_14 * V_178 ;
int V_35 ;
V_150 = F_79 ( V_219 , V_77 ) ;
V_161 = F_80 ( V_219 , V_77 ) ;
V_178 = F_147 ( V_19 , V_150 ) ;
if ( V_178 ) {
if ( F_148 ( V_178 , V_161 , 1 ) > 0 ) {
* V_218 = V_178 ;
return 0 ;
}
F_3 ( V_5 ) ;
V_35 = F_149 ( V_178 , V_161 ) ;
if ( ! V_35 ) {
* V_218 = V_178 ;
return 0 ;
}
F_11 ( V_178 ) ;
F_8 ( V_5 ) ;
return - V_170 ;
}
F_176 ( V_5 , V_36 + 1 ) ;
F_3 ( V_5 ) ;
F_11 ( V_178 ) ;
if ( V_5 -> V_207 )
F_171 ( V_19 , V_5 , V_36 , V_77 , V_83 -> V_124 ) ;
F_8 ( V_5 ) ;
V_35 = - V_220 ;
V_178 = F_131 ( V_19 , V_150 , 0 ) ;
if ( V_178 ) {
if ( ! F_148 ( V_178 , 0 , 0 ) )
V_35 = - V_170 ;
F_11 ( V_178 ) ;
}
return V_35 ;
}
static int
F_178 ( struct V_29 * V_30 ,
struct V_18 * V_19 , struct V_1 * V_5 ,
struct V_14 * V_219 , int V_36 , int V_221 ,
int * V_213 )
{
int V_35 ;
if ( ( V_5 -> V_222 || V_221 > 0 ) && F_87 ( V_219 ) >=
F_129 ( V_19 ) - 3 ) {
int V_223 ;
if ( * V_213 < V_36 + 1 ) {
* V_213 = V_36 + 1 ;
F_8 ( V_5 ) ;
goto V_224;
}
F_3 ( V_5 ) ;
F_174 ( V_19 , V_5 , V_36 ) ;
V_223 = F_179 ( V_30 , V_19 , V_5 , V_36 ) ;
F_5 ( V_5 , NULL , 0 ) ;
F_71 ( V_223 > 0 ) ;
if ( V_223 ) {
V_35 = V_223 ;
goto V_225;
}
V_219 = V_5 -> V_8 [ V_36 ] ;
} else if ( V_221 < 0 && F_87 ( V_219 ) <
F_129 ( V_19 ) / 2 ) {
int V_223 ;
if ( * V_213 < V_36 + 1 ) {
* V_213 = V_36 + 1 ;
F_8 ( V_5 ) ;
goto V_224;
}
F_3 ( V_5 ) ;
F_174 ( V_19 , V_5 , V_36 ) ;
V_223 = F_164 ( V_30 , V_19 , V_5 , V_36 ) ;
F_5 ( V_5 , NULL , 0 ) ;
if ( V_223 ) {
V_35 = V_223 ;
goto V_225;
}
V_219 = V_5 -> V_8 [ V_36 ] ;
if ( ! V_219 ) {
F_8 ( V_5 ) ;
goto V_224;
}
F_71 ( F_87 ( V_219 ) == 1 ) ;
}
return 0 ;
V_224:
V_35 = - V_220 ;
V_225:
return V_35 ;
}
static void F_180 ( struct V_14 * V_219 ,
struct V_154 * V_83 ,
int V_36 )
{
#ifdef F_181
struct V_37 V_38 ;
F_182 ( & V_38 , V_83 ) ;
if ( V_36 == 0 )
ASSERT ( ! F_183 ( V_219 , & V_38 ,
F_158 ( struct V_183 , V_184 [ 0 ] . V_83 ) ,
sizeof( V_38 ) ) ) ;
else
ASSERT ( ! F_183 ( V_219 , & V_38 ,
F_158 ( struct V_186 , V_187 [ 0 ] . V_83 ) ,
sizeof( V_38 ) ) ) ;
#endif
}
static int F_184 ( struct V_14 * V_219 , struct V_154 * V_83 ,
int V_36 , int * V_226 , int * V_77 )
{
if ( * V_226 != 0 ) {
* V_226 = F_157 ( V_219 , V_83 , V_36 , V_77 ) ;
return * V_226 ;
}
F_180 ( V_219 , V_83 , V_36 ) ;
* V_77 = 0 ;
return 0 ;
}
int F_185 ( struct V_18 * V_227 , struct V_1 * V_228 ,
T_2 V_229 , T_2 V_230 , T_5 V_231 ,
struct V_154 * V_232 )
{
int V_35 ;
struct V_154 V_83 ;
struct V_14 * V_20 ;
struct V_1 * V_2 ;
V_83 . type = V_231 ;
V_83 . V_124 = V_229 ;
V_83 . V_157 = V_230 ;
if ( V_228 == NULL ) {
V_2 = F_1 () ;
if ( ! V_2 )
return - V_86 ;
} else
V_2 = V_228 ;
V_35 = F_186 ( NULL , V_227 , & V_83 , V_2 , 0 , 0 ) ;
if ( ( V_35 < 0 ) || ( V_232 == NULL ) ) {
if ( V_2 != V_228 )
F_7 ( V_2 ) ;
return V_35 ;
}
V_20 = V_2 -> V_8 [ 0 ] ;
if ( V_35 && V_2 -> V_17 [ 0 ] >= F_87 ( V_20 ) ) {
V_35 = F_187 ( V_227 , V_2 ) ;
if ( V_35 )
return V_35 ;
V_20 = V_2 -> V_8 [ 0 ] ;
}
F_188 ( V_20 , V_232 , V_2 -> V_17 [ 0 ] ) ;
if ( V_232 -> type != V_83 . type ||
V_232 -> V_124 != V_83 . V_124 )
return 1 ;
return 0 ;
}
int F_186 ( struct V_29 * V_30 , struct V_18
* V_19 , struct V_154 * V_83 , struct V_1 * V_5 , int
V_221 , int V_34 )
{
struct V_14 * V_219 ;
int V_77 ;
int V_35 ;
int V_165 ;
int V_36 ;
int V_211 = 1 ;
int V_233 ;
int V_213 = 0 ;
T_5 V_234 = 0 ;
int V_212 ;
int V_226 ;
V_234 = V_5 -> V_234 ;
F_31 ( V_234 && V_221 > 0 ) ;
F_31 ( V_5 -> V_8 [ 0 ] != NULL ) ;
F_71 ( ! V_34 && V_221 ) ;
if ( V_221 < 0 ) {
V_211 = 2 ;
V_213 = 2 ;
} else if ( V_221 > 0 ) {
V_213 = 1 ;
}
if ( ! V_34 )
V_213 = - 1 ;
if ( V_34 && ( V_5 -> V_217 || V_5 -> V_234 ) )
V_213 = V_7 ;
V_212 = V_213 ;
V_224:
V_226 = - 1 ;
V_233 = V_10 ;
V_36 = 0 ;
if ( V_5 -> V_235 ) {
if ( V_5 -> V_236 )
F_189 ( & V_19 -> V_23 -> V_237 ) ;
V_219 = V_19 -> V_117 ;
F_112 ( V_219 ) ;
V_36 = F_32 ( V_219 ) ;
if ( V_5 -> V_236 )
F_190 ( & V_19 -> V_23 -> V_237 ) ;
if ( ! V_5 -> V_238 )
F_22 ( V_219 ) ;
} else {
if ( V_5 -> V_238 ) {
V_219 = F_12 ( V_19 ) ;
V_36 = F_32 ( V_219 ) ;
} else {
V_219 = F_21 ( V_19 ) ;
V_36 = F_32 ( V_219 ) ;
if ( V_36 <= V_213 ) {
F_23 ( V_219 ) ;
F_11 ( V_219 ) ;
V_219 = F_18 ( V_19 ) ;
V_233 = V_12 ;
V_36 = F_32 ( V_219 ) ;
}
}
}
V_5 -> V_8 [ V_36 ] = V_219 ;
if ( ! V_5 -> V_238 )
V_5 -> V_9 [ V_36 ] = V_233 ;
while ( V_219 ) {
V_36 = F_32 ( V_219 ) ;
if ( V_34 ) {
if ( ! F_135 ( V_30 , V_19 , V_219 ) )
goto V_239;
if ( V_36 > V_213 ||
( V_36 + 1 > V_213 &&
V_36 + 1 < V_7 &&
V_5 -> V_8 [ V_36 + 1 ] ) ) {
V_213 = V_36 + 1 ;
F_8 ( V_5 ) ;
goto V_224;
}
F_3 ( V_5 ) ;
V_165 = F_138 ( V_30 , V_19 , V_219 ,
V_5 -> V_8 [ V_36 + 1 ] ,
V_5 -> V_17 [ V_36 + 1 ] , & V_219 ) ;
if ( V_165 ) {
V_35 = V_165 ;
goto V_225;
}
}
V_239:
V_5 -> V_8 [ V_36 ] = V_219 ;
F_5 ( V_5 , NULL , 0 ) ;
if ( ! V_221 && ! V_5 -> V_217 ) {
int V_240 = V_36 + 1 ;
if ( V_240 < V_7 && V_5 -> V_9 [ V_240 ] ) {
F_10 ( V_5 -> V_8 [ V_240 ] , V_5 -> V_9 [ V_240 ] ) ;
V_5 -> V_9 [ V_240 ] = 0 ;
}
}
V_35 = F_184 ( V_219 , V_83 , V_36 , & V_226 , & V_77 ) ;
if ( V_36 != 0 ) {
int V_241 = 0 ;
if ( V_35 && V_77 > 0 ) {
V_241 = 1 ;
V_77 -= 1 ;
}
V_5 -> V_17 [ V_36 ] = V_77 ;
V_165 = F_178 ( V_30 , V_19 , V_5 , V_219 , V_36 ,
V_221 , & V_213 ) ;
if ( V_165 == - V_220 )
goto V_224;
if ( V_165 ) {
V_35 = V_165 ;
goto V_225;
}
V_219 = V_5 -> V_8 [ V_36 ] ;
V_77 = V_5 -> V_17 [ V_36 ] ;
if ( V_77 == 0 && V_221 &&
V_213 < V_36 + 1 ) {
V_213 = V_36 + 1 ;
F_8 ( V_5 ) ;
goto V_224;
}
F_175 ( V_5 , V_36 , V_211 ,
V_212 , & V_213 ) ;
if ( V_36 == V_234 ) {
if ( V_241 )
V_5 -> V_17 [ V_36 ] ++ ;
goto V_225;
}
V_165 = F_177 ( V_30 , V_19 , V_5 ,
& V_219 , V_36 , V_77 , V_83 , 0 ) ;
if ( V_165 == - V_220 )
goto V_224;
if ( V_165 ) {
V_35 = V_165 ;
goto V_225;
}
if ( ! V_5 -> V_238 ) {
V_36 = F_32 ( V_219 ) ;
if ( V_36 <= V_213 ) {
V_165 = F_191 ( V_219 ) ;
if ( ! V_165 ) {
F_3 ( V_5 ) ;
F_19 ( V_219 ) ;
F_5 ( V_5 , V_219 ,
V_12 ) ;
}
V_5 -> V_9 [ V_36 ] = V_12 ;
} else {
V_165 = F_192 ( V_219 ) ;
if ( ! V_165 ) {
F_3 ( V_5 ) ;
F_22 ( V_219 ) ;
F_5 ( V_5 , V_219 ,
V_10 ) ;
}
V_5 -> V_9 [ V_36 ] = V_10 ;
}
V_5 -> V_8 [ V_36 ] = V_219 ;
}
} else {
V_5 -> V_17 [ V_36 ] = V_77 ;
if ( V_221 > 0 &&
F_193 ( V_19 , V_219 ) < V_221 ) {
if ( V_213 < 1 ) {
V_213 = 1 ;
F_8 ( V_5 ) ;
goto V_224;
}
F_3 ( V_5 ) ;
V_165 = F_194 ( V_30 , V_19 , V_83 ,
V_5 , V_221 , V_35 == 0 ) ;
F_5 ( V_5 , NULL , 0 ) ;
F_71 ( V_165 > 0 ) ;
if ( V_165 ) {
V_35 = V_165 ;
goto V_225;
}
}
if ( ! V_5 -> V_222 )
F_175 ( V_5 , V_36 , V_211 ,
V_212 , & V_213 ) ;
goto V_225;
}
}
V_35 = 1 ;
V_225:
if ( ! V_5 -> V_242 )
F_3 ( V_5 ) ;
if ( V_35 < 0 && ! V_5 -> V_243 )
F_8 ( V_5 ) ;
return V_35 ;
}
int F_195 ( struct V_18 * V_19 , struct V_154 * V_83 ,
struct V_1 * V_5 , T_2 V_132 )
{
struct V_14 * V_219 ;
int V_77 ;
int V_35 ;
int V_165 ;
int V_36 ;
int V_211 = 1 ;
T_5 V_234 = 0 ;
int V_226 = - 1 ;
V_234 = V_5 -> V_234 ;
F_31 ( V_5 -> V_8 [ 0 ] != NULL ) ;
if ( V_5 -> V_235 ) {
F_71 ( V_132 ) ;
return F_186 ( NULL , V_19 , V_83 , V_5 , 0 , 0 ) ;
}
V_224:
V_219 = F_130 ( V_19 , V_132 ) ;
V_36 = F_32 ( V_219 ) ;
V_5 -> V_9 [ V_36 ] = V_10 ;
while ( V_219 ) {
V_36 = F_32 ( V_219 ) ;
V_5 -> V_8 [ V_36 ] = V_219 ;
F_5 ( V_5 , NULL , 0 ) ;
F_176 ( V_5 , V_36 + 1 ) ;
V_226 = - 1 ;
V_35 = F_184 ( V_219 , V_83 , V_36 , & V_226 , & V_77 ) ;
if ( V_36 != 0 ) {
int V_241 = 0 ;
if ( V_35 && V_77 > 0 ) {
V_241 = 1 ;
V_77 -= 1 ;
}
V_5 -> V_17 [ V_36 ] = V_77 ;
F_175 ( V_5 , V_36 , V_211 , 0 , NULL ) ;
if ( V_36 == V_234 ) {
if ( V_241 )
V_5 -> V_17 [ V_36 ] ++ ;
goto V_225;
}
V_165 = F_177 ( NULL , V_19 , V_5 , & V_219 , V_36 ,
V_77 , V_83 , V_132 ) ;
if ( V_165 == - V_220 )
goto V_224;
if ( V_165 ) {
V_35 = V_165 ;
goto V_225;
}
V_36 = F_32 ( V_219 ) ;
V_165 = F_192 ( V_219 ) ;
if ( ! V_165 ) {
F_3 ( V_5 ) ;
F_22 ( V_219 ) ;
F_5 ( V_5 , V_219 ,
V_10 ) ;
}
V_219 = F_124 ( V_19 -> V_23 , V_5 , V_219 , V_132 ) ;
if ( ! V_219 ) {
V_35 = - V_86 ;
goto V_225;
}
V_5 -> V_9 [ V_36 ] = V_10 ;
V_5 -> V_8 [ V_36 ] = V_219 ;
} else {
V_5 -> V_17 [ V_36 ] = V_77 ;
F_175 ( V_5 , V_36 , V_211 , 0 , NULL ) ;
goto V_225;
}
}
V_35 = 1 ;
V_225:
if ( ! V_5 -> V_242 )
F_3 ( V_5 ) ;
if ( V_35 < 0 )
F_8 ( V_5 ) ;
return V_35 ;
}
int F_196 ( struct V_18 * V_19 ,
struct V_154 * V_83 , struct V_1 * V_5 ,
int V_244 , int V_245 )
{
int V_35 ;
struct V_14 * V_171 ;
V_224:
V_35 = F_186 ( NULL , V_19 , V_83 , V_5 , 0 , 0 ) ;
if ( V_35 <= 0 )
return V_35 ;
V_171 = V_5 -> V_8 [ 0 ] ;
if ( V_244 ) {
if ( V_5 -> V_17 [ 0 ] >= F_87 ( V_171 ) ) {
V_35 = F_187 ( V_19 , V_5 ) ;
if ( V_35 <= 0 )
return V_35 ;
if ( ! V_245 )
return 1 ;
V_245 = 0 ;
V_244 = 0 ;
F_8 ( V_5 ) ;
goto V_224;
}
} else {
if ( V_5 -> V_17 [ 0 ] == 0 ) {
V_35 = F_197 ( V_19 , V_5 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( ! V_35 ) {
V_171 = V_5 -> V_8 [ 0 ] ;
if ( V_5 -> V_17 [ 0 ] == F_87 ( V_171 ) )
V_5 -> V_17 [ 0 ] -- ;
return 0 ;
}
if ( ! V_245 )
return 1 ;
V_245 = 0 ;
V_244 = 1 ;
F_8 ( V_5 ) ;
goto V_224;
} else {
-- V_5 -> V_17 [ 0 ] ;
}
}
return 0 ;
}
static void F_198 ( struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_37 * V_83 , int V_36 )
{
int V_6 ;
struct V_14 * V_216 ;
for ( V_6 = V_36 ; V_6 < V_7 ; V_6 ++ ) {
int V_246 = V_2 -> V_17 [ V_6 ] ;
if ( ! V_2 -> V_8 [ V_6 ] )
break;
V_216 = V_2 -> V_8 [ V_6 ] ;
F_93 ( V_19 -> V_23 , V_216 , V_246 , 1 ) ;
F_120 ( V_216 , V_83 , V_246 ) ;
F_49 ( V_2 -> V_8 [ V_6 ] ) ;
if ( V_246 != 0 )
break;
}
}
void F_199 ( struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_154 * V_247 )
{
struct V_37 V_38 ;
struct V_14 * V_20 ;
int V_77 ;
V_20 = V_2 -> V_8 [ 0 ] ;
V_77 = V_2 -> V_17 [ 0 ] ;
if ( V_77 > 0 ) {
F_33 ( V_20 , & V_38 , V_77 - 1 ) ;
F_71 ( F_143 ( & V_38 , V_247 ) >= 0 ) ;
}
if ( V_77 < F_87 ( V_20 ) - 1 ) {
F_33 ( V_20 , & V_38 , V_77 + 1 ) ;
F_71 ( F_143 ( & V_38 , V_247 ) <= 0 ) ;
}
F_182 ( & V_38 , V_247 ) ;
F_200 ( V_20 , & V_38 , V_77 ) ;
F_49 ( V_20 ) ;
if ( V_77 == 0 )
F_198 ( V_19 , V_2 , & V_38 , 1 ) ;
}
static int F_166 ( struct V_29 * V_30 ,
struct V_18 * V_19 , struct V_14 * V_106 ,
struct V_14 * V_107 , int V_248 )
{
int V_249 = 0 ;
int V_250 ;
int V_251 ;
int V_35 = 0 ;
V_250 = F_87 ( V_107 ) ;
V_251 = F_87 ( V_106 ) ;
V_249 = F_129 ( V_19 ) - V_251 ;
F_31 ( F_47 ( V_107 ) != V_30 -> V_40 ) ;
F_31 ( F_47 ( V_106 ) != V_30 -> V_40 ) ;
if ( ! V_248 && V_250 <= 8 )
return 1 ;
if ( V_249 <= 0 )
return 1 ;
if ( V_248 ) {
V_249 = F_150 ( V_250 , V_249 ) ;
if ( V_249 < V_250 ) {
if ( V_250 - V_249 < 8 ) {
if ( V_249 <= 8 )
return 1 ;
V_249 -= 8 ;
}
}
} else
V_249 = F_150 ( V_250 - 8 , V_249 ) ;
V_35 = F_91 ( V_19 -> V_23 , V_106 , V_107 , V_251 , 0 ,
V_249 ) ;
if ( V_35 ) {
F_110 ( V_30 , V_19 , V_35 ) ;
return V_35 ;
}
F_38 ( V_106 , V_107 ,
F_121 ( V_251 ) ,
F_121 ( 0 ) ,
V_249 * sizeof( struct V_140 ) ) ;
if ( V_249 < V_250 ) {
F_122 ( V_107 , F_121 ( 0 ) ,
F_121 ( V_249 ) ,
( V_250 - V_249 ) *
sizeof( struct V_140 ) ) ;
}
F_123 ( V_107 , V_250 - V_249 ) ;
F_123 ( V_106 , V_251 + V_249 ) ;
F_49 ( V_107 ) ;
F_49 ( V_106 ) ;
return V_35 ;
}
static int F_168 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_14 * V_106 ,
struct V_14 * V_107 )
{
int V_249 = 0 ;
int V_252 ;
int V_250 ;
int V_251 ;
int V_35 = 0 ;
F_31 ( F_47 ( V_107 ) != V_30 -> V_40 ) ;
F_31 ( F_47 ( V_106 ) != V_30 -> V_40 ) ;
V_250 = F_87 ( V_107 ) ;
V_251 = F_87 ( V_106 ) ;
V_249 = F_129 ( V_19 ) - V_251 ;
if ( V_249 <= 0 )
return 1 ;
if ( V_250 < 4 )
return 1 ;
V_252 = V_250 / 2 + 1 ;
if ( V_252 >= V_250 )
return 1 ;
if ( V_252 < V_249 )
V_249 = V_252 ;
F_92 ( V_19 -> V_23 , V_106 , V_249 , 0 , V_251 ) ;
F_122 ( V_106 , F_121 ( V_249 ) ,
F_121 ( 0 ) ,
( V_251 ) *
sizeof( struct V_140 ) ) ;
V_35 = F_91 ( V_19 -> V_23 , V_106 , V_107 , 0 ,
V_250 - V_249 , V_249 ) ;
if ( V_35 ) {
F_110 ( V_30 , V_19 , V_35 ) ;
return V_35 ;
}
F_38 ( V_106 , V_107 ,
F_121 ( 0 ) ,
F_121 ( V_250 - V_249 ) ,
V_249 * sizeof( struct V_140 ) ) ;
F_123 ( V_107 , V_250 - V_249 ) ;
F_123 ( V_106 , V_251 + V_249 ) ;
F_49 ( V_107 ) ;
F_49 ( V_106 ) ;
return V_35 ;
}
static T_1 int F_201 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_36 )
{
T_2 V_253 ;
struct V_14 * V_254 ;
struct V_14 * V_255 ;
struct V_14 * V_144 ;
struct V_37 V_256 ;
F_71 ( V_2 -> V_8 [ V_36 ] ) ;
F_71 ( V_2 -> V_8 [ V_36 - 1 ] != V_19 -> V_21 ) ;
V_254 = V_2 -> V_8 [ V_36 - 1 ] ;
if ( V_36 == 1 )
F_33 ( V_254 , & V_256 , 0 ) ;
else
F_34 ( V_254 , & V_256 , 0 ) ;
V_255 = F_35 ( V_30 , V_19 , 0 , V_19 -> V_123 . V_124 ,
& V_256 , V_36 , V_19 -> V_21 -> V_43 , 0 ) ;
if ( F_36 ( V_255 ) )
return F_37 ( V_255 ) ;
F_160 ( V_19 , V_19 -> V_143 ) ;
F_202 ( V_255 , 0 , 0 , sizeof( struct V_257 ) ) ;
F_123 ( V_255 , 1 ) ;
F_127 ( V_255 , V_36 ) ;
F_39 ( V_255 , V_255 -> V_43 ) ;
F_40 ( V_255 , V_30 -> V_40 ) ;
F_41 ( V_255 , V_45 ) ;
F_44 ( V_255 , V_19 -> V_123 . V_124 ) ;
F_45 ( V_255 , V_19 -> V_23 -> V_49 , F_46 () ,
V_50 ) ;
F_45 ( V_255 , V_19 -> V_23 -> V_258 ,
F_203 ( V_255 ) , V_259 ) ;
F_120 ( V_255 , & V_256 , 0 ) ;
F_115 ( V_255 , 0 , V_254 -> V_43 ) ;
V_253 = F_47 ( V_254 ) ;
F_31 ( V_253 != V_30 -> V_40 ) ;
F_116 ( V_255 , 0 , V_253 ) ;
F_49 ( V_255 ) ;
V_144 = V_19 -> V_21 ;
F_95 ( V_19 , V_255 , 0 ) ;
F_113 ( V_19 -> V_21 , V_255 ) ;
F_11 ( V_144 ) ;
F_24 ( V_19 ) ;
F_112 ( V_255 ) ;
V_2 -> V_8 [ V_36 ] = V_255 ;
V_2 -> V_9 [ V_36 ] = V_12 ;
V_2 -> V_17 [ V_36 ] = 0 ;
return 0 ;
}
static void F_204 ( struct V_29 * V_30 ,
struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_37 * V_83 , T_2 V_260 ,
int V_77 , int V_36 )
{
struct V_14 * V_254 ;
int V_96 ;
int V_35 ;
F_71 ( ! V_2 -> V_8 [ V_36 ] ) ;
F_109 ( V_2 -> V_8 [ V_36 ] ) ;
V_254 = V_2 -> V_8 [ V_36 ] ;
V_96 = F_87 ( V_254 ) ;
F_71 ( V_77 > V_96 ) ;
F_71 ( V_96 == F_129 ( V_19 ) ) ;
if ( V_77 != V_96 ) {
if ( V_36 )
F_92 ( V_19 -> V_23 , V_254 , V_77 + 1 ,
V_77 , V_96 - V_77 ) ;
F_122 ( V_254 ,
F_121 ( V_77 + 1 ) ,
F_121 ( V_77 ) ,
( V_96 - V_77 ) * sizeof( struct V_140 ) ) ;
}
if ( V_36 ) {
V_35 = F_82 ( V_19 -> V_23 , V_254 , V_77 ,
V_82 , V_4 ) ;
F_71 ( V_35 < 0 ) ;
}
F_120 ( V_254 , V_83 , V_77 ) ;
F_115 ( V_254 , V_77 , V_260 ) ;
F_31 ( V_30 -> V_40 == 0 ) ;
F_116 ( V_254 , V_77 , V_30 -> V_40 ) ;
F_123 ( V_254 , V_96 + 1 ) ;
F_49 ( V_254 ) ;
}
static T_1 int F_179 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_36 )
{
struct V_14 * V_255 ;
struct V_14 * V_261 ;
struct V_37 V_38 ;
int V_177 ;
int V_35 ;
T_4 V_262 ;
V_255 = V_2 -> V_8 [ V_36 ] ;
F_31 ( F_47 ( V_255 ) != V_30 -> V_40 ) ;
if ( V_255 == V_19 -> V_21 ) {
V_35 = F_201 ( V_30 , V_19 , V_2 , V_36 + 1 ) ;
if ( V_35 )
return V_35 ;
} else {
V_35 = F_170 ( V_30 , V_19 , V_2 , V_36 ) ;
V_255 = V_2 -> V_8 [ V_36 ] ;
if ( ! V_35 && F_87 ( V_255 ) <
F_129 ( V_19 ) - 3 )
return 0 ;
if ( V_35 < 0 )
return V_35 ;
}
V_262 = F_87 ( V_255 ) ;
V_177 = ( V_262 + 1 ) / 2 ;
F_34 ( V_255 , & V_38 , V_177 ) ;
V_261 = F_35 ( V_30 , V_19 , 0 , V_19 -> V_123 . V_124 ,
& V_38 , V_36 , V_255 -> V_43 , 0 ) ;
if ( F_36 ( V_261 ) )
return F_37 ( V_261 ) ;
F_160 ( V_19 , V_19 -> V_143 ) ;
F_202 ( V_261 , 0 , 0 , sizeof( struct V_257 ) ) ;
F_127 ( V_261 , F_32 ( V_255 ) ) ;
F_39 ( V_261 , V_261 -> V_43 ) ;
F_40 ( V_261 , V_30 -> V_40 ) ;
F_41 ( V_261 , V_45 ) ;
F_44 ( V_261 , V_19 -> V_123 . V_124 ) ;
F_45 ( V_261 , V_19 -> V_23 -> V_49 ,
F_46 () , V_50 ) ;
F_45 ( V_261 , V_19 -> V_23 -> V_258 ,
F_203 ( V_261 ) ,
V_259 ) ;
V_35 = F_91 ( V_19 -> V_23 , V_261 , V_255 , 0 ,
V_177 , V_262 - V_177 ) ;
if ( V_35 ) {
F_110 ( V_30 , V_19 , V_35 ) ;
return V_35 ;
}
F_38 ( V_261 , V_255 ,
F_121 ( 0 ) ,
F_121 ( V_177 ) ,
( V_262 - V_177 ) * sizeof( struct V_140 ) ) ;
F_123 ( V_261 , V_262 - V_177 ) ;
F_123 ( V_255 , V_177 ) ;
V_35 = 0 ;
F_49 ( V_255 ) ;
F_49 ( V_261 ) ;
F_204 ( V_30 , V_19 , V_2 , & V_38 , V_261 -> V_43 ,
V_2 -> V_17 [ V_36 + 1 ] + 1 , V_36 + 1 ) ;
if ( V_2 -> V_17 [ V_36 ] >= V_177 ) {
V_2 -> V_17 [ V_36 ] -= V_177 ;
F_20 ( V_255 ) ;
F_11 ( V_255 ) ;
V_2 -> V_8 [ V_36 ] = V_261 ;
V_2 -> V_17 [ V_36 + 1 ] += 1 ;
} else {
F_20 ( V_261 ) ;
F_11 ( V_261 ) ;
}
return V_35 ;
}
static int F_205 ( struct V_14 * V_263 , int V_43 , int V_172 )
{
struct V_185 * V_264 ;
struct V_185 * V_265 ;
struct V_266 V_267 ;
int V_268 ;
int V_96 = F_87 ( V_263 ) ;
int V_269 = F_150 ( V_96 , V_43 + V_172 ) - 1 ;
if ( ! V_172 )
return 0 ;
F_206 ( & V_267 ) ;
V_264 = F_207 ( V_43 ) ;
V_265 = F_207 ( V_269 ) ;
V_268 = F_208 ( V_263 , V_264 , & V_267 ) +
F_209 ( V_263 , V_264 , & V_267 ) ;
V_268 = V_268 - F_208 ( V_263 , V_265 , & V_267 ) ;
V_268 += sizeof( struct V_185 ) * V_172 ;
F_31 ( V_268 < 0 ) ;
return V_268 ;
}
T_1 int F_193 ( struct V_18 * V_19 ,
struct V_14 * V_171 )
{
int V_96 = F_87 ( V_171 ) ;
int V_35 ;
V_35 = F_152 ( V_19 ) - F_205 ( V_171 , 0 , V_96 ) ;
if ( V_35 < 0 ) {
F_210 ( V_19 -> V_23 ,
L_3 ,
V_35 , ( unsigned long ) F_152 ( V_19 ) ,
F_205 ( V_171 , 0 , V_96 ) , V_96 ) ;
}
return V_35 ;
}
static T_1 int F_211 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
int V_270 , int V_248 ,
struct V_14 * V_190 ,
int V_271 , T_4 V_272 ,
T_4 V_273 )
{
struct V_14 * V_191 = V_2 -> V_8 [ 0 ] ;
struct V_14 * V_274 = V_2 -> V_8 [ 1 ] ;
struct V_266 V_267 ;
struct V_37 V_38 ;
int V_77 ;
T_4 V_6 ;
int V_275 = 0 ;
int V_249 = 0 ;
struct V_185 * V_276 ;
T_4 V_172 ;
T_4 V_277 ;
T_4 V_278 ;
T_4 V_279 ;
F_206 ( & V_267 ) ;
if ( V_248 )
V_172 = 0 ;
else
V_172 = F_212 ( T_4 , 1 , V_273 ) ;
if ( V_2 -> V_17 [ 0 ] >= V_272 )
V_275 += V_270 ;
V_77 = V_2 -> V_17 [ 1 ] ;
V_6 = V_272 - 1 ;
while ( V_6 >= V_172 ) {
V_276 = F_207 ( V_6 ) ;
if ( ! V_248 && V_249 > 0 ) {
if ( V_2 -> V_17 [ 0 ] > V_6 )
break;
if ( V_2 -> V_17 [ 0 ] == V_6 ) {
int V_280 = F_193 ( V_19 , V_191 ) ;
if ( V_280 + V_275 * 2 > V_271 )
break;
}
}
if ( V_2 -> V_17 [ 0 ] == V_6 )
V_275 += V_270 ;
V_279 = F_213 ( V_191 , V_276 ) ;
if ( V_279 + sizeof( * V_276 ) + V_275 > V_271 )
break;
V_249 ++ ;
V_275 += V_279 + sizeof( * V_276 ) ;
if ( V_6 == 0 )
break;
V_6 -- ;
}
if ( V_249 == 0 )
goto V_281;
F_31 ( ! V_248 && V_249 == V_272 ) ;
V_277 = F_87 ( V_190 ) ;
V_275 = F_214 ( V_191 , V_272 - V_249 ) ;
V_275 -= F_151 ( V_19 , V_191 ) ;
V_278 = F_151 ( V_19 , V_190 ) ;
F_122 ( V_190 ,
F_215 ( V_190 ) + V_278 - V_275 ,
F_215 ( V_190 ) + V_278 ,
F_152 ( V_19 ) - V_278 ) ;
F_38 ( V_190 , V_191 , F_215 ( V_190 ) +
F_152 ( V_19 ) - V_275 ,
F_215 ( V_191 ) + F_151 ( V_19 , V_191 ) ,
V_275 ) ;
F_122 ( V_190 , F_216 ( V_249 ) ,
F_216 ( 0 ) ,
V_277 * sizeof( struct V_185 ) ) ;
F_38 ( V_190 , V_191 , F_216 ( 0 ) ,
F_216 ( V_272 - V_249 ) ,
V_249 * sizeof( struct V_185 ) ) ;
V_277 += V_249 ;
F_123 ( V_190 , V_277 ) ;
V_275 = F_152 ( V_19 ) ;
for ( V_6 = 0 ; V_6 < V_277 ; V_6 ++ ) {
V_276 = F_207 ( V_6 ) ;
V_275 -= F_209 ( V_190 , V_276 , & V_267 ) ;
F_217 ( V_190 , V_276 , V_275 , & V_267 ) ;
}
V_272 -= V_249 ;
F_123 ( V_191 , V_272 ) ;
if ( V_272 )
F_49 ( V_191 ) ;
else
F_107 ( V_30 , V_19 , V_191 ) ;
F_49 ( V_190 ) ;
F_33 ( V_190 , & V_38 , 0 ) ;
F_120 ( V_274 , & V_38 , V_77 + 1 ) ;
F_49 ( V_274 ) ;
if ( V_2 -> V_17 [ 0 ] >= V_272 ) {
V_2 -> V_17 [ 0 ] -= V_272 ;
if ( F_87 ( V_2 -> V_8 [ 0 ] ) == 0 )
F_107 ( V_30 , V_19 , V_2 -> V_8 [ 0 ] ) ;
F_20 ( V_2 -> V_8 [ 0 ] ) ;
F_11 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_190 ;
V_2 -> V_17 [ 1 ] += 1 ;
} else {
F_20 ( V_190 ) ;
F_11 ( V_190 ) ;
}
return 0 ;
V_281:
F_20 ( V_190 ) ;
F_11 ( V_190 ) ;
return 1 ;
}
static int F_218 ( struct V_29 * V_30 , struct V_18
* V_19 , struct V_1 * V_2 ,
int V_282 , int V_270 ,
int V_248 , T_4 V_273 )
{
struct V_14 * V_191 = V_2 -> V_8 [ 0 ] ;
struct V_14 * V_190 ;
struct V_14 * V_274 ;
int V_77 ;
int V_271 ;
T_4 V_272 ;
int V_35 ;
if ( ! V_2 -> V_8 [ 1 ] )
return 1 ;
V_77 = V_2 -> V_17 [ 1 ] ;
V_274 = V_2 -> V_8 [ 1 ] ;
if ( V_77 >= F_87 ( V_274 ) - 1 )
return 1 ;
F_109 ( V_2 -> V_8 [ 1 ] ) ;
V_190 = F_165 ( V_19 , V_274 , V_77 + 1 ) ;
if ( V_190 == NULL )
return 1 ;
F_19 ( V_190 ) ;
F_140 ( V_190 ) ;
V_271 = F_193 ( V_19 , V_190 ) ;
if ( V_271 < V_270 )
goto V_281;
V_35 = F_138 ( V_30 , V_19 , V_190 , V_274 ,
V_77 + 1 , & V_190 ) ;
if ( V_35 )
goto V_281;
V_271 = F_193 ( V_19 , V_190 ) ;
if ( V_271 < V_270 )
goto V_281;
V_272 = F_87 ( V_191 ) ;
if ( V_272 == 0 )
goto V_281;
if ( V_2 -> V_17 [ 0 ] == V_272 && ! V_248 ) {
F_20 ( V_191 ) ;
F_11 ( V_191 ) ;
V_2 -> V_8 [ 0 ] = V_190 ;
V_2 -> V_17 [ 0 ] = 0 ;
V_2 -> V_17 [ 1 ] ++ ;
return 0 ;
}
return F_211 ( V_30 , V_19 , V_2 , V_282 , V_248 ,
V_190 , V_271 , V_272 , V_273 ) ;
V_281:
F_20 ( V_190 ) ;
F_11 ( V_190 ) ;
return 1 ;
}
static T_1 int F_219 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_270 ,
int V_248 , struct V_14 * V_191 ,
int V_271 , T_4 V_277 ,
T_4 V_283 )
{
struct V_37 V_38 ;
struct V_14 * V_190 = V_2 -> V_8 [ 0 ] ;
int V_6 ;
int V_275 = 0 ;
int V_249 = 0 ;
struct V_185 * V_276 ;
T_4 V_284 ;
T_4 V_172 ;
int V_35 = 0 ;
T_4 V_279 ;
T_4 V_285 ;
struct V_266 V_267 ;
F_206 ( & V_267 ) ;
if ( V_248 )
V_172 = F_150 ( V_277 , V_283 ) ;
else
V_172 = F_150 ( V_277 - 1 , V_283 ) ;
for ( V_6 = 0 ; V_6 < V_172 ; V_6 ++ ) {
V_276 = F_207 ( V_6 ) ;
if ( ! V_248 && V_249 > 0 ) {
if ( V_2 -> V_17 [ 0 ] < V_6 )
break;
if ( V_2 -> V_17 [ 0 ] == V_6 ) {
int V_280 = F_193 ( V_19 , V_190 ) ;
if ( V_280 + V_275 * 2 > V_271 )
break;
}
}
if ( V_2 -> V_17 [ 0 ] == V_6 )
V_275 += V_270 ;
V_279 = F_213 ( V_190 , V_276 ) ;
if ( V_279 + sizeof( * V_276 ) + V_275 > V_271 )
break;
V_249 ++ ;
V_275 += V_279 + sizeof( * V_276 ) ;
}
if ( V_249 == 0 ) {
V_35 = 1 ;
goto V_286;
}
F_31 ( ! V_248 && V_249 == F_87 ( V_190 ) ) ;
F_38 ( V_191 , V_190 ,
F_216 ( F_87 ( V_191 ) ) ,
F_216 ( 0 ) ,
V_249 * sizeof( struct V_185 ) ) ;
V_275 = F_152 ( V_19 ) -
F_153 ( V_190 , V_249 - 1 ) ;
F_38 ( V_191 , V_190 , F_215 ( V_191 ) +
F_151 ( V_19 , V_191 ) - V_275 ,
F_215 ( V_190 ) +
F_153 ( V_190 , V_249 - 1 ) ,
V_275 ) ;
V_284 = F_87 ( V_191 ) ;
F_71 ( V_284 <= 0 ) ;
V_285 = F_153 ( V_191 , V_284 - 1 ) ;
for ( V_6 = V_284 ; V_6 < V_284 + V_249 ; V_6 ++ ) {
T_4 V_230 ;
V_276 = F_207 ( V_6 ) ;
V_230 = F_208 ( V_191 , V_276 , & V_267 ) ;
F_217 ( V_191 , V_276 ,
V_230 - ( F_152 ( V_19 ) - V_285 ) ,
& V_267 ) ;
}
F_123 ( V_191 , V_284 + V_249 ) ;
if ( V_249 > V_277 )
F_139 ( 1 , V_149 L_4 , V_249 ,
V_277 ) ;
if ( V_249 < V_277 ) {
V_275 = F_153 ( V_190 , V_249 - 1 ) -
F_151 ( V_19 , V_190 ) ;
F_122 ( V_190 , F_215 ( V_190 ) +
F_152 ( V_19 ) - V_275 ,
F_215 ( V_190 ) +
F_151 ( V_19 , V_190 ) , V_275 ) ;
F_122 ( V_190 , F_216 ( 0 ) ,
F_216 ( V_249 ) ,
( F_87 ( V_190 ) - V_249 ) *
sizeof( struct V_185 ) ) ;
}
V_277 -= V_249 ;
F_123 ( V_190 , V_277 ) ;
V_275 = F_152 ( V_19 ) ;
for ( V_6 = 0 ; V_6 < V_277 ; V_6 ++ ) {
V_276 = F_207 ( V_6 ) ;
V_275 = V_275 - F_209 ( V_190 ,
V_276 , & V_267 ) ;
F_217 ( V_190 , V_276 , V_275 , & V_267 ) ;
}
F_49 ( V_191 ) ;
if ( V_277 )
F_49 ( V_190 ) ;
else
F_107 ( V_30 , V_19 , V_190 ) ;
F_33 ( V_190 , & V_38 , 0 ) ;
F_198 ( V_19 , V_2 , & V_38 , 1 ) ;
if ( V_2 -> V_17 [ 0 ] < V_249 ) {
V_2 -> V_17 [ 0 ] += V_284 ;
F_20 ( V_2 -> V_8 [ 0 ] ) ;
F_11 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_191 ;
V_2 -> V_17 [ 1 ] -= 1 ;
} else {
F_20 ( V_191 ) ;
F_11 ( V_191 ) ;
V_2 -> V_17 [ 0 ] -= V_249 ;
}
F_71 ( V_2 -> V_17 [ 0 ] < 0 ) ;
return V_35 ;
V_286:
F_20 ( V_191 ) ;
F_11 ( V_191 ) ;
return V_35 ;
}
static int F_220 ( struct V_29 * V_30 , struct V_18
* V_19 , struct V_1 * V_2 , int V_282 ,
int V_270 , int V_248 , T_4 V_283 )
{
struct V_14 * V_190 = V_2 -> V_8 [ 0 ] ;
struct V_14 * V_191 ;
int V_77 ;
int V_271 ;
T_4 V_277 ;
int V_35 = 0 ;
V_77 = V_2 -> V_17 [ 1 ] ;
if ( V_77 == 0 )
return 1 ;
if ( ! V_2 -> V_8 [ 1 ] )
return 1 ;
V_277 = F_87 ( V_190 ) ;
if ( V_277 == 0 )
return 1 ;
F_109 ( V_2 -> V_8 [ 1 ] ) ;
V_191 = F_165 ( V_19 , V_2 -> V_8 [ 1 ] , V_77 - 1 ) ;
if ( V_191 == NULL )
return 1 ;
F_19 ( V_191 ) ;
F_140 ( V_191 ) ;
V_271 = F_193 ( V_19 , V_191 ) ;
if ( V_271 < V_270 ) {
V_35 = 1 ;
goto V_286;
}
V_35 = F_138 ( V_30 , V_19 , V_191 ,
V_2 -> V_8 [ 1 ] , V_77 - 1 , & V_191 ) ;
if ( V_35 ) {
if ( V_35 == - V_198 )
V_35 = 1 ;
goto V_286;
}
V_271 = F_193 ( V_19 , V_191 ) ;
if ( V_271 < V_270 ) {
V_35 = 1 ;
goto V_286;
}
return F_219 ( V_30 , V_19 , V_2 , V_282 ,
V_248 , V_191 , V_271 , V_277 ,
V_283 ) ;
V_286:
F_20 ( V_191 ) ;
F_11 ( V_191 ) ;
return V_35 ;
}
static T_1 void F_221 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_14 * V_263 ,
struct V_14 * V_190 ,
int V_77 , int V_177 , int V_96 )
{
int V_287 ;
int V_288 ;
int V_6 ;
struct V_37 V_38 ;
struct V_266 V_267 ;
F_206 ( & V_267 ) ;
V_96 = V_96 - V_177 ;
F_123 ( V_190 , V_96 ) ;
V_287 = F_214 ( V_263 , V_177 ) - F_151 ( V_19 , V_263 ) ;
F_38 ( V_190 , V_263 , F_216 ( 0 ) ,
F_216 ( V_177 ) ,
V_96 * sizeof( struct V_185 ) ) ;
F_38 ( V_190 , V_263 ,
F_215 ( V_190 ) + F_152 ( V_19 ) -
V_287 , F_215 ( V_263 ) +
F_151 ( V_19 , V_263 ) , V_287 ) ;
V_288 = F_152 ( V_19 ) -
F_214 ( V_263 , V_177 ) ;
for ( V_6 = 0 ; V_6 < V_96 ; V_6 ++ ) {
struct V_185 * V_276 = F_207 ( V_6 ) ;
T_4 V_230 ;
V_230 = F_208 ( V_190 , V_276 , & V_267 ) ;
F_217 ( V_190 , V_276 ,
V_230 + V_288 , & V_267 ) ;
}
F_123 ( V_263 , V_177 ) ;
F_33 ( V_190 , & V_38 , 0 ) ;
F_204 ( V_30 , V_19 , V_2 , & V_38 , V_190 -> V_43 ,
V_2 -> V_17 [ 1 ] + 1 , 1 ) ;
F_49 ( V_190 ) ;
F_49 ( V_263 ) ;
F_71 ( V_2 -> V_17 [ 0 ] != V_77 ) ;
if ( V_177 <= V_77 ) {
F_20 ( V_2 -> V_8 [ 0 ] ) ;
F_11 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_190 ;
V_2 -> V_17 [ 0 ] -= V_177 ;
V_2 -> V_17 [ 1 ] += 1 ;
} else {
F_20 ( V_190 ) ;
F_11 ( V_190 ) ;
}
F_71 ( V_2 -> V_17 [ 0 ] < 0 ) ;
}
static T_1 int F_222 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
int V_270 )
{
int V_35 ;
int V_160 = 0 ;
int V_77 ;
T_4 V_96 ;
int V_289 = V_270 ;
V_77 = V_2 -> V_17 [ 0 ] ;
if ( V_77 < F_87 ( V_2 -> V_8 [ 0 ] ) )
V_289 -= F_193 ( V_19 , V_2 -> V_8 [ 0 ] ) ;
V_35 = F_218 ( V_30 , V_19 , V_2 , 1 , V_289 , 0 , V_77 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 == 0 )
V_160 ++ ;
V_96 = F_87 ( V_2 -> V_8 [ 0 ] ) ;
if ( V_2 -> V_17 [ 0 ] == 0 || V_2 -> V_17 [ 0 ] == V_96 )
return 0 ;
if ( F_193 ( V_19 , V_2 -> V_8 [ 0 ] ) >= V_270 )
return 0 ;
V_77 = V_2 -> V_17 [ 0 ] ;
V_35 = F_220 ( V_30 , V_19 , V_2 , 1 , V_289 , 0 , V_77 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 == 0 )
V_160 ++ ;
if ( V_160 )
return 0 ;
return 1 ;
}
static T_1 int F_194 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_154 * V_290 ,
struct V_1 * V_2 , int V_270 ,
int V_291 )
{
struct V_37 V_38 ;
struct V_14 * V_263 ;
T_4 V_96 ;
int V_177 ;
int V_77 ;
struct V_14 * V_190 ;
int V_35 = 0 ;
int V_192 ;
int V_261 ;
int V_292 = 0 ;
int V_293 = 0 ;
V_263 = V_2 -> V_8 [ 0 ] ;
V_77 = V_2 -> V_17 [ 0 ] ;
if ( V_291 && V_270 + F_223 ( V_263 , V_77 ) +
sizeof( struct V_185 ) > F_152 ( V_19 ) )
return - V_294 ;
if ( V_270 && V_2 -> V_8 [ 1 ] ) {
int V_289 = V_270 ;
if ( V_77 < F_87 ( V_263 ) )
V_289 -= F_193 ( V_19 , V_263 ) ;
V_192 = F_218 ( V_30 , V_19 , V_2 , V_289 ,
V_289 , 0 , 0 ) ;
if ( V_192 < 0 )
return V_192 ;
if ( V_192 ) {
V_192 = F_220 ( V_30 , V_19 , V_2 , V_289 ,
V_289 , 0 , ( T_4 ) - 1 ) ;
if ( V_192 < 0 )
return V_192 ;
}
V_263 = V_2 -> V_8 [ 0 ] ;
if ( F_193 ( V_19 , V_263 ) >= V_270 )
return 0 ;
}
if ( ! V_2 -> V_8 [ 1 ] ) {
V_35 = F_201 ( V_30 , V_19 , V_2 , 1 ) ;
if ( V_35 )
return V_35 ;
}
V_224:
V_261 = 1 ;
V_263 = V_2 -> V_8 [ 0 ] ;
V_77 = V_2 -> V_17 [ 0 ] ;
V_96 = F_87 ( V_263 ) ;
V_177 = ( V_96 + 1 ) / 2 ;
if ( V_177 <= V_77 ) {
if ( V_96 == 1 ||
F_205 ( V_263 , V_177 , V_96 - V_177 ) + V_270 >
F_152 ( V_19 ) ) {
if ( V_77 >= V_96 ) {
V_261 = 0 ;
} else {
V_177 = V_77 ;
if ( V_177 != V_96 &&
F_205 ( V_263 , V_177 , V_96 - V_177 ) +
V_270 > F_152 ( V_19 ) ) {
if ( V_270 && ! V_293 )
goto V_295;
V_261 = 2 ;
}
}
}
} else {
if ( F_205 ( V_263 , 0 , V_177 ) + V_270 >
F_152 ( V_19 ) ) {
if ( ! V_291 && V_270 && V_77 == 0 ) {
V_261 = 0 ;
} else if ( ( V_291 || ! V_270 ) && V_77 == 0 ) {
V_177 = 1 ;
} else {
V_177 = V_77 ;
if ( V_177 != V_96 &&
F_205 ( V_263 , V_177 , V_96 - V_177 ) +
V_270 > F_152 ( V_19 ) ) {
if ( V_270 && ! V_293 )
goto V_295;
V_261 = 2 ;
}
}
}
}
if ( V_261 == 0 )
F_182 ( & V_38 , V_290 ) ;
else
F_33 ( V_263 , & V_38 , V_177 ) ;
V_190 = F_35 ( V_30 , V_19 , 0 , V_19 -> V_123 . V_124 ,
& V_38 , 0 , V_263 -> V_43 , 0 ) ;
if ( F_36 ( V_190 ) )
return F_37 ( V_190 ) ;
F_160 ( V_19 , V_19 -> V_143 ) ;
F_202 ( V_190 , 0 , 0 , sizeof( struct V_257 ) ) ;
F_39 ( V_190 , V_190 -> V_43 ) ;
F_40 ( V_190 , V_30 -> V_40 ) ;
F_41 ( V_190 , V_45 ) ;
F_44 ( V_190 , V_19 -> V_123 . V_124 ) ;
F_127 ( V_190 , 0 ) ;
F_45 ( V_190 , V_19 -> V_23 -> V_49 ,
F_46 () , V_50 ) ;
F_45 ( V_190 , V_19 -> V_23 -> V_258 ,
F_203 ( V_190 ) ,
V_259 ) ;
if ( V_261 == 0 ) {
if ( V_177 <= V_77 ) {
F_123 ( V_190 , 0 ) ;
F_204 ( V_30 , V_19 , V_2 , & V_38 , V_190 -> V_43 ,
V_2 -> V_17 [ 1 ] + 1 , 1 ) ;
F_20 ( V_2 -> V_8 [ 0 ] ) ;
F_11 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_190 ;
V_2 -> V_17 [ 0 ] = 0 ;
V_2 -> V_17 [ 1 ] += 1 ;
} else {
F_123 ( V_190 , 0 ) ;
F_204 ( V_30 , V_19 , V_2 , & V_38 , V_190 -> V_43 ,
V_2 -> V_17 [ 1 ] , 1 ) ;
F_20 ( V_2 -> V_8 [ 0 ] ) ;
F_11 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_190 ;
V_2 -> V_17 [ 0 ] = 0 ;
if ( V_2 -> V_17 [ 1 ] == 0 )
F_198 ( V_19 , V_2 , & V_38 , 1 ) ;
}
F_49 ( V_190 ) ;
return V_35 ;
}
F_221 ( V_30 , V_19 , V_2 , V_263 , V_190 , V_77 , V_177 , V_96 ) ;
if ( V_261 == 2 ) {
F_71 ( V_292 != 0 ) ;
V_292 ++ ;
goto V_224;
}
return 0 ;
V_295:
F_222 ( V_30 , V_19 , V_2 , V_270 ) ;
V_293 = 1 ;
if ( F_193 ( V_19 , V_2 -> V_8 [ 0 ] ) >= V_270 )
return 0 ;
goto V_224;
}
static T_1 int F_224 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_221 )
{
struct V_154 V_83 ;
struct V_14 * V_171 ;
struct V_296 * V_297 ;
T_2 V_298 = 0 ;
T_4 V_173 ;
int V_35 ;
V_171 = V_2 -> V_8 [ 0 ] ;
F_188 ( V_171 , & V_83 , V_2 -> V_17 [ 0 ] ) ;
F_71 ( V_83 . type != V_299 &&
V_83 . type != V_300 ) ;
if ( F_193 ( V_19 , V_171 ) >= V_221 )
return 0 ;
V_173 = F_223 ( V_171 , V_2 -> V_17 [ 0 ] ) ;
if ( V_83 . type == V_299 ) {
V_297 = F_225 ( V_171 , V_2 -> V_17 [ 0 ] ,
struct V_296 ) ;
V_298 = F_226 ( V_171 , V_297 ) ;
}
F_8 ( V_2 ) ;
V_2 -> V_217 = 1 ;
V_2 -> V_222 = 1 ;
V_35 = F_186 ( V_30 , V_19 , & V_83 , V_2 , 0 , 1 ) ;
V_2 -> V_222 = 0 ;
if ( V_35 < 0 )
goto V_165;
V_35 = - V_220 ;
V_171 = V_2 -> V_8 [ 0 ] ;
if ( V_35 > 0 || V_173 != F_223 ( V_171 , V_2 -> V_17 [ 0 ] ) )
goto V_165;
if ( F_193 ( V_19 , V_2 -> V_8 [ 0 ] ) >= V_221 )
goto V_165;
if ( V_83 . type == V_299 ) {
V_297 = F_225 ( V_171 , V_2 -> V_17 [ 0 ] ,
struct V_296 ) ;
if ( V_298 != F_226 ( V_171 , V_297 ) )
goto V_165;
}
F_3 ( V_2 ) ;
V_35 = F_194 ( V_30 , V_19 , & V_83 , V_2 , V_221 , 1 ) ;
if ( V_35 )
goto V_165;
V_2 -> V_217 = 0 ;
F_176 ( V_2 , 1 ) ;
return 0 ;
V_165:
V_2 -> V_217 = 0 ;
return V_35 ;
}
static T_1 int F_227 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_154 * V_247 ,
unsigned long V_301 )
{
struct V_14 * V_171 ;
struct V_185 * V_276 ;
struct V_185 * V_302 ;
int V_77 ;
char * V_31 ;
T_4 V_96 ;
T_4 V_173 ;
T_4 V_303 ;
struct V_37 V_38 ;
V_171 = V_2 -> V_8 [ 0 ] ;
F_71 ( F_193 ( V_19 , V_171 ) < sizeof( struct V_185 ) ) ;
F_3 ( V_2 ) ;
V_276 = F_207 ( V_2 -> V_17 [ 0 ] ) ;
V_303 = F_228 ( V_171 , V_276 ) ;
V_173 = F_213 ( V_171 , V_276 ) ;
V_31 = F_229 ( V_173 , V_4 ) ;
if ( ! V_31 )
return - V_86 ;
F_156 ( V_171 , V_31 , F_230 ( V_171 ,
V_2 -> V_17 [ 0 ] ) , V_173 ) ;
V_77 = V_2 -> V_17 [ 0 ] + 1 ;
V_96 = F_87 ( V_171 ) ;
if ( V_77 != V_96 ) {
F_122 ( V_171 , F_216 ( V_77 + 1 ) ,
F_216 ( V_77 ) ,
( V_96 - V_77 ) * sizeof( struct V_185 ) ) ;
}
F_182 ( & V_38 , V_247 ) ;
F_200 ( V_171 , & V_38 , V_77 ) ;
V_302 = F_207 ( V_77 ) ;
F_231 ( V_171 , V_302 , V_303 ) ;
F_232 ( V_171 , V_302 , V_173 - V_301 ) ;
F_231 ( V_171 , V_276 ,
V_303 + V_173 - V_301 ) ;
F_232 ( V_171 , V_276 , V_301 ) ;
F_123 ( V_171 , V_96 + 1 ) ;
F_45 ( V_171 , V_31 ,
F_230 ( V_171 , V_2 -> V_17 [ 0 ] ) ,
V_301 ) ;
F_45 ( V_171 , V_31 + V_301 ,
F_230 ( V_171 , V_77 ) ,
V_173 - V_301 ) ;
F_49 ( V_171 ) ;
F_71 ( F_193 ( V_19 , V_171 ) < 0 ) ;
F_69 ( V_31 ) ;
return 0 ;
}
int F_233 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_154 * V_247 ,
unsigned long V_301 )
{
int V_35 ;
V_35 = F_224 ( V_30 , V_19 , V_2 ,
sizeof( struct V_185 ) ) ;
if ( V_35 )
return V_35 ;
V_35 = F_227 ( V_30 , V_19 , V_2 , V_247 , V_301 ) ;
return V_35 ;
}
int F_234 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_154 * V_247 )
{
struct V_14 * V_171 ;
int V_35 ;
T_4 V_173 ;
V_171 = V_2 -> V_8 [ 0 ] ;
V_173 = F_223 ( V_171 , V_2 -> V_17 [ 0 ] ) ;
V_35 = F_224 ( V_30 , V_19 , V_2 ,
V_173 + sizeof( struct V_185 ) ) ;
if ( V_35 )
return V_35 ;
V_2 -> V_17 [ 0 ] ++ ;
F_235 ( V_19 , V_2 , V_247 , & V_173 ,
V_173 , V_173 +
sizeof( struct V_185 ) , 1 ) ;
V_171 = V_2 -> V_8 [ 0 ] ;
F_236 ( V_171 ,
F_230 ( V_171 , V_2 -> V_17 [ 0 ] ) ,
F_230 ( V_171 , V_2 -> V_17 [ 0 ] - 1 ) ,
V_173 ) ;
return 0 ;
}
void F_237 ( struct V_18 * V_19 , struct V_1 * V_2 ,
T_4 V_304 , int V_305 )
{
int V_77 ;
struct V_14 * V_171 ;
struct V_185 * V_276 ;
T_4 V_96 ;
unsigned int V_278 ;
unsigned int V_306 ;
unsigned int V_307 ;
unsigned int V_308 ;
int V_6 ;
struct V_266 V_267 ;
F_206 ( & V_267 ) ;
V_171 = V_2 -> V_8 [ 0 ] ;
V_77 = V_2 -> V_17 [ 0 ] ;
V_307 = F_223 ( V_171 , V_77 ) ;
if ( V_307 == V_304 )
return;
V_96 = F_87 ( V_171 ) ;
V_278 = F_151 ( V_19 , V_171 ) ;
V_306 = F_153 ( V_171 , V_77 ) ;
V_308 = V_307 - V_304 ;
F_71 ( V_77 < 0 ) ;
F_71 ( V_77 >= V_96 ) ;
for ( V_6 = V_77 ; V_6 < V_96 ; V_6 ++ ) {
T_4 V_230 ;
V_276 = F_207 ( V_6 ) ;
V_230 = F_208 ( V_171 , V_276 , & V_267 ) ;
F_217 ( V_171 , V_276 ,
V_230 + V_308 , & V_267 ) ;
}
if ( V_305 ) {
F_122 ( V_171 , F_215 ( V_171 ) +
V_278 + V_308 , F_215 ( V_171 ) +
V_278 , V_306 + V_304 - V_278 ) ;
} else {
struct V_37 V_38 ;
T_2 V_157 ;
F_33 ( V_171 , & V_38 , V_77 ) ;
if ( F_238 ( & V_38 ) == V_299 ) {
unsigned long V_309 ;
struct V_296 * V_297 ;
V_297 = F_225 ( V_171 , V_77 ,
struct V_296 ) ;
V_297 = (struct V_296 * ) (
( unsigned long ) V_297 - V_308 ) ;
if ( F_239 ( V_171 , V_297 ) ==
V_310 ) {
V_309 = F_230 ( V_171 , V_77 ) ;
F_122 ( V_171 , V_309 ,
( unsigned long ) V_297 ,
V_311 ) ;
}
}
F_122 ( V_171 , F_215 ( V_171 ) +
V_278 + V_308 , F_215 ( V_171 ) +
V_278 , V_306 - V_278 ) ;
V_157 = F_240 ( & V_38 ) ;
F_241 ( & V_38 , V_157 + V_308 ) ;
F_200 ( V_171 , & V_38 , V_77 ) ;
if ( V_77 == 0 )
F_198 ( V_19 , V_2 , & V_38 , 1 ) ;
}
V_276 = F_207 ( V_77 ) ;
F_232 ( V_171 , V_276 , V_304 ) ;
F_49 ( V_171 ) ;
if ( F_193 ( V_19 , V_171 ) < 0 ) {
F_242 ( V_19 , V_171 ) ;
F_169 () ;
}
}
void F_243 ( struct V_18 * V_19 , struct V_1 * V_2 ,
T_4 V_270 )
{
int V_77 ;
struct V_14 * V_171 ;
struct V_185 * V_276 ;
T_4 V_96 ;
unsigned int V_278 ;
unsigned int V_312 ;
unsigned int V_307 ;
int V_6 ;
struct V_266 V_267 ;
F_206 ( & V_267 ) ;
V_171 = V_2 -> V_8 [ 0 ] ;
V_96 = F_87 ( V_171 ) ;
V_278 = F_151 ( V_19 , V_171 ) ;
if ( F_193 ( V_19 , V_171 ) < V_270 ) {
F_242 ( V_19 , V_171 ) ;
F_169 () ;
}
V_77 = V_2 -> V_17 [ 0 ] ;
V_312 = F_214 ( V_171 , V_77 ) ;
F_71 ( V_77 < 0 ) ;
if ( V_77 >= V_96 ) {
F_242 ( V_19 , V_171 ) ;
F_210 ( V_19 -> V_23 , L_5 ,
V_77 , V_96 ) ;
F_71 ( 1 ) ;
}
for ( V_6 = V_77 ; V_6 < V_96 ; V_6 ++ ) {
T_4 V_230 ;
V_276 = F_207 ( V_6 ) ;
V_230 = F_208 ( V_171 , V_276 , & V_267 ) ;
F_217 ( V_171 , V_276 ,
V_230 - V_270 , & V_267 ) ;
}
F_122 ( V_171 , F_215 ( V_171 ) +
V_278 - V_270 , F_215 ( V_171 ) +
V_278 , V_312 - V_278 ) ;
V_278 = V_312 ;
V_307 = F_223 ( V_171 , V_77 ) ;
V_276 = F_207 ( V_77 ) ;
F_232 ( V_171 , V_276 , V_307 + V_270 ) ;
F_49 ( V_171 ) ;
if ( F_193 ( V_19 , V_171 ) < 0 ) {
F_242 ( V_19 , V_171 ) ;
F_169 () ;
}
}
void F_235 ( struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_154 * V_313 , T_4 * V_270 ,
T_4 V_314 , T_4 V_315 , int V_172 )
{
struct V_185 * V_276 ;
int V_6 ;
T_4 V_96 ;
unsigned int V_278 ;
struct V_37 V_38 ;
struct V_14 * V_171 ;
int V_77 ;
struct V_266 V_267 ;
if ( V_2 -> V_17 [ 0 ] == 0 ) {
F_182 ( & V_38 , V_313 ) ;
F_198 ( V_19 , V_2 , & V_38 , 1 ) ;
}
F_176 ( V_2 , 1 ) ;
F_206 ( & V_267 ) ;
V_171 = V_2 -> V_8 [ 0 ] ;
V_77 = V_2 -> V_17 [ 0 ] ;
V_96 = F_87 ( V_171 ) ;
V_278 = F_151 ( V_19 , V_171 ) ;
if ( F_193 ( V_19 , V_171 ) < V_315 ) {
F_242 ( V_19 , V_171 ) ;
F_210 ( V_19 -> V_23 , L_6 ,
V_315 , F_193 ( V_19 , V_171 ) ) ;
F_169 () ;
}
if ( V_77 != V_96 ) {
unsigned int V_312 = F_214 ( V_171 , V_77 ) ;
if ( V_312 < V_278 ) {
F_242 ( V_19 , V_171 ) ;
F_210 ( V_19 -> V_23 , L_7 ,
V_77 , V_312 , V_278 ) ;
F_71 ( 1 ) ;
}
for ( V_6 = V_77 ; V_6 < V_96 ; V_6 ++ ) {
T_4 V_230 ;
V_276 = F_207 ( V_6 ) ;
V_230 = F_208 ( V_171 , V_276 , & V_267 ) ;
F_217 ( V_171 , V_276 ,
V_230 - V_314 , & V_267 ) ;
}
F_122 ( V_171 , F_216 ( V_77 + V_172 ) ,
F_216 ( V_77 ) ,
( V_96 - V_77 ) * sizeof( struct V_185 ) ) ;
F_122 ( V_171 , F_215 ( V_171 ) +
V_278 - V_314 , F_215 ( V_171 ) +
V_278 , V_312 - V_278 ) ;
V_278 = V_312 ;
}
for ( V_6 = 0 ; V_6 < V_172 ; V_6 ++ ) {
F_182 ( & V_38 , V_313 + V_6 ) ;
F_200 ( V_171 , & V_38 , V_77 + V_6 ) ;
V_276 = F_207 ( V_77 + V_6 ) ;
F_217 ( V_171 , V_276 ,
V_278 - V_270 [ V_6 ] , & V_267 ) ;
V_278 -= V_270 [ V_6 ] ;
F_244 ( V_171 , V_276 , V_270 [ V_6 ] , & V_267 ) ;
}
F_123 ( V_171 , V_96 + V_172 ) ;
F_49 ( V_171 ) ;
if ( F_193 ( V_19 , V_171 ) < 0 ) {
F_242 ( V_19 , V_171 ) ;
F_169 () ;
}
}
int F_245 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_154 * V_313 , T_4 * V_270 ,
int V_172 )
{
int V_35 = 0 ;
int V_77 ;
int V_6 ;
T_4 V_315 = 0 ;
T_4 V_314 = 0 ;
for ( V_6 = 0 ; V_6 < V_172 ; V_6 ++ )
V_314 += V_270 [ V_6 ] ;
V_315 = V_314 + ( V_172 * sizeof( struct V_185 ) ) ;
V_35 = F_186 ( V_30 , V_19 , V_313 , V_2 , V_315 , 1 ) ;
if ( V_35 == 0 )
return - V_76 ;
if ( V_35 < 0 )
return V_35 ;
V_77 = V_2 -> V_17 [ 0 ] ;
F_71 ( V_77 < 0 ) ;
F_235 ( V_19 , V_2 , V_313 , V_270 ,
V_314 , V_315 , V_172 ) ;
return 0 ;
}
int F_246 ( struct V_29 * V_30 , struct V_18
* V_19 , struct V_154 * V_313 , void * V_316 , T_4
V_270 )
{
int V_35 = 0 ;
struct V_1 * V_2 ;
struct V_14 * V_171 ;
unsigned long V_309 ;
V_2 = F_1 () ;
if ( ! V_2 )
return - V_86 ;
V_35 = F_247 ( V_30 , V_19 , V_2 , V_313 , V_270 ) ;
if ( ! V_35 ) {
V_171 = V_2 -> V_8 [ 0 ] ;
V_309 = F_230 ( V_171 , V_2 -> V_17 [ 0 ] ) ;
F_45 ( V_171 , V_316 , V_309 , V_270 ) ;
F_49 ( V_171 ) ;
}
F_7 ( V_2 ) ;
return V_35 ;
}
static void F_167 ( struct V_18 * V_19 , struct V_1 * V_2 ,
int V_36 , int V_77 )
{
struct V_14 * V_71 = V_2 -> V_8 [ V_36 ] ;
T_4 V_96 ;
int V_35 ;
V_96 = F_87 ( V_71 ) ;
if ( V_77 != V_96 - 1 ) {
if ( V_36 )
F_92 ( V_19 -> V_23 , V_71 , V_77 ,
V_77 + 1 , V_96 - V_77 - 1 ) ;
F_122 ( V_71 ,
F_121 ( V_77 ) ,
F_121 ( V_77 + 1 ) ,
sizeof( struct V_140 ) *
( V_96 - V_77 - 1 ) ) ;
} else if ( V_36 ) {
V_35 = F_82 ( V_19 -> V_23 , V_71 , V_77 ,
V_112 , V_4 ) ;
F_71 ( V_35 < 0 ) ;
}
V_96 -- ;
F_123 ( V_71 , V_96 ) ;
if ( V_96 == 0 && V_71 == V_19 -> V_21 ) {
F_71 ( F_32 ( V_19 -> V_21 ) != 1 ) ;
F_127 ( V_19 -> V_21 , 0 ) ;
} else if ( V_77 == 0 ) {
struct V_37 V_38 ;
F_34 ( V_71 , & V_38 , 0 ) ;
F_198 ( V_19 , V_2 , & V_38 , V_36 + 1 ) ;
}
F_49 ( V_71 ) ;
}
static T_1 void F_248 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_14 * V_171 )
{
F_31 ( F_47 ( V_171 ) != V_30 -> V_40 ) ;
F_167 ( V_19 , V_2 , 1 , V_2 -> V_17 [ 1 ] ) ;
F_176 ( V_2 , 0 ) ;
F_163 ( V_19 , V_171 -> V_44 ) ;
F_112 ( V_171 ) ;
F_114 ( V_30 , V_19 , V_171 , 0 , 1 ) ;
F_117 ( V_171 ) ;
}
int F_249 ( struct V_29 * V_30 , struct V_18 * V_19 ,
struct V_1 * V_2 , int V_77 , int V_172 )
{
struct V_14 * V_171 ;
struct V_185 * V_276 ;
int V_317 ;
int V_318 = 0 ;
int V_35 = 0 ;
int V_192 ;
int V_6 ;
T_4 V_96 ;
struct V_266 V_267 ;
F_206 ( & V_267 ) ;
V_171 = V_2 -> V_8 [ 0 ] ;
V_317 = F_153 ( V_171 , V_77 + V_172 - 1 ) ;
for ( V_6 = 0 ; V_6 < V_172 ; V_6 ++ )
V_318 += F_223 ( V_171 , V_77 + V_6 ) ;
V_96 = F_87 ( V_171 ) ;
if ( V_77 + V_172 != V_96 ) {
int V_278 = F_151 ( V_19 , V_171 ) ;
F_122 ( V_171 , F_215 ( V_171 ) +
V_278 + V_318 ,
F_215 ( V_171 ) + V_278 ,
V_317 - V_278 ) ;
for ( V_6 = V_77 + V_172 ; V_6 < V_96 ; V_6 ++ ) {
T_4 V_230 ;
V_276 = F_207 ( V_6 ) ;
V_230 = F_208 ( V_171 , V_276 , & V_267 ) ;
F_217 ( V_171 , V_276 ,
V_230 + V_318 , & V_267 ) ;
}
F_122 ( V_171 , F_216 ( V_77 ) ,
F_216 ( V_77 + V_172 ) ,
sizeof( struct V_185 ) *
( V_96 - V_77 - V_172 ) ) ;
}
F_123 ( V_171 , V_96 - V_172 ) ;
V_96 -= V_172 ;
if ( V_96 == 0 ) {
if ( V_171 == V_19 -> V_21 ) {
F_127 ( V_171 , 0 ) ;
} else {
F_3 ( V_2 ) ;
F_107 ( V_30 , V_19 , V_171 ) ;
F_248 ( V_30 , V_19 , V_2 , V_171 ) ;
}
} else {
int V_319 = F_205 ( V_171 , 0 , V_96 ) ;
if ( V_77 == 0 ) {
struct V_37 V_38 ;
F_33 ( V_171 , & V_38 , 0 ) ;
F_198 ( V_19 , V_2 , & V_38 , 1 ) ;
}
if ( V_319 < F_152 ( V_19 ) / 3 ) {
V_77 = V_2 -> V_17 [ 1 ] ;
F_112 ( V_171 ) ;
F_3 ( V_2 ) ;
V_192 = F_220 ( V_30 , V_19 , V_2 , 1 , 1 ,
1 , ( T_4 ) - 1 ) ;
if ( V_192 < 0 && V_192 != - V_198 )
V_35 = V_192 ;
if ( V_2 -> V_8 [ 0 ] == V_171 &&
F_87 ( V_171 ) ) {
V_192 = F_218 ( V_30 , V_19 , V_2 , 1 ,
1 , 1 , 0 ) ;
if ( V_192 < 0 && V_192 != - V_198 )
V_35 = V_192 ;
}
if ( F_87 ( V_171 ) == 0 ) {
V_2 -> V_17 [ 1 ] = V_77 ;
F_248 ( V_30 , V_19 , V_2 , V_171 ) ;
F_11 ( V_171 ) ;
V_35 = 0 ;
} else {
if ( V_2 -> V_8 [ 0 ] == V_171 )
F_49 ( V_171 ) ;
F_11 ( V_171 ) ;
}
} else {
F_49 ( V_171 ) ;
}
}
return V_35 ;
}
int F_197 ( struct V_18 * V_19 , struct V_1 * V_2 )
{
struct V_154 V_83 ;
struct V_37 V_232 ;
int V_35 ;
F_188 ( V_2 -> V_8 [ 0 ] , & V_83 , 0 ) ;
if ( V_83 . V_157 > 0 ) {
V_83 . V_157 -- ;
} else if ( V_83 . type > 0 ) {
V_83 . type -- ;
V_83 . V_157 = ( T_2 ) - 1 ;
} else if ( V_83 . V_124 > 0 ) {
V_83 . V_124 -- ;
V_83 . type = ( T_5 ) - 1 ;
V_83 . V_157 = ( T_2 ) - 1 ;
} else {
return 1 ;
}
F_8 ( V_2 ) ;
V_35 = F_186 ( NULL , V_19 , & V_83 , V_2 , 0 , 0 ) ;
if ( V_35 < 0 )
return V_35 ;
F_33 ( V_2 -> V_8 [ 0 ] , & V_232 , 0 ) ;
V_35 = F_143 ( & V_232 , & V_83 ) ;
if ( V_35 <= 0 )
return 0 ;
return 1 ;
}
int F_250 ( struct V_18 * V_19 , struct V_154 * V_320 ,
struct V_1 * V_2 ,
T_2 V_321 )
{
struct V_14 * V_72 ;
struct V_154 V_232 ;
int V_77 ;
int V_223 ;
T_4 V_96 ;
int V_36 ;
int V_35 = 1 ;
int V_217 = V_2 -> V_217 ;
V_2 -> V_217 = 1 ;
V_224:
V_72 = F_21 ( V_19 ) ;
V_36 = F_32 ( V_72 ) ;
F_31 ( V_2 -> V_8 [ V_36 ] ) ;
V_2 -> V_8 [ V_36 ] = V_72 ;
V_2 -> V_9 [ V_36 ] = V_10 ;
if ( F_47 ( V_72 ) < V_321 ) {
V_35 = 1 ;
goto V_286;
}
while ( 1 ) {
V_96 = F_87 ( V_72 ) ;
V_36 = F_32 ( V_72 ) ;
V_223 = F_157 ( V_72 , V_320 , V_36 , & V_77 ) ;
if ( V_36 == V_2 -> V_234 ) {
if ( V_77 >= V_96 )
goto V_322;
V_35 = 0 ;
V_2 -> V_17 [ V_36 ] = V_77 ;
F_188 ( V_72 , & V_232 , V_77 ) ;
goto V_286;
}
if ( V_223 && V_77 > 0 )
V_77 -- ;
while ( V_77 < V_96 ) {
T_2 V_161 ;
V_161 = F_80 ( V_72 , V_77 ) ;
if ( V_161 < V_321 ) {
V_77 ++ ;
continue;
}
break;
}
V_322:
if ( V_77 >= V_96 ) {
V_2 -> V_17 [ V_36 ] = V_77 ;
F_3 ( V_2 ) ;
V_223 = F_251 ( V_19 , V_2 , V_320 , V_36 ,
V_321 ) ;
if ( V_223 == 0 ) {
F_8 ( V_2 ) ;
goto V_224;
} else {
goto V_286;
}
}
F_252 ( V_72 , & V_232 , V_77 ) ;
V_2 -> V_17 [ V_36 ] = V_77 ;
if ( V_36 == V_2 -> V_234 ) {
V_35 = 0 ;
goto V_286;
}
F_3 ( V_2 ) ;
V_72 = F_165 ( V_19 , V_72 , V_77 ) ;
F_71 ( ! V_72 ) ;
F_22 ( V_72 ) ;
V_2 -> V_9 [ V_36 - 1 ] = V_10 ;
V_2 -> V_8 [ V_36 - 1 ] = V_72 ;
F_175 ( V_2 , V_36 , 1 , 0 , NULL ) ;
F_5 ( V_2 , NULL , 0 ) ;
}
V_286:
V_2 -> V_217 = V_217 ;
if ( V_35 == 0 ) {
F_176 ( V_2 , V_2 -> V_234 + 1 ) ;
F_3 ( V_2 ) ;
memcpy ( V_320 , & V_232 , sizeof( V_232 ) ) ;
}
return V_35 ;
}
static void F_253 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int * V_36 , int V_323 )
{
F_71 ( * V_36 == 0 ) ;
V_2 -> V_8 [ * V_36 - 1 ] = F_165 ( V_19 , V_2 -> V_8 [ * V_36 ] ,
V_2 -> V_17 [ * V_36 ] ) ;
V_2 -> V_17 [ * V_36 - 1 ] = 0 ;
( * V_36 ) -- ;
}
static int F_254 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int * V_36 , int V_323 )
{
int V_35 = 0 ;
int V_96 ;
V_96 = F_87 ( V_2 -> V_8 [ * V_36 ] ) ;
V_2 -> V_17 [ * V_36 ] ++ ;
while ( V_2 -> V_17 [ * V_36 ] >= V_96 ) {
if ( * V_36 == V_323 )
return - 1 ;
V_2 -> V_17 [ * V_36 ] = 0 ;
F_11 ( V_2 -> V_8 [ * V_36 ] ) ;
V_2 -> V_8 [ * V_36 ] = NULL ;
( * V_36 ) ++ ;
V_2 -> V_17 [ * V_36 ] ++ ;
V_96 = F_87 ( V_2 -> V_8 [ * V_36 ] ) ;
V_35 = 1 ;
}
return V_35 ;
}
static int F_255 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int * V_36 , int V_323 ,
int V_324 ,
struct V_154 * V_83 )
{
int V_35 ;
if ( * V_36 == 0 || ! V_324 ) {
V_35 = F_254 ( V_19 , V_2 , V_36 , V_323 ) ;
} else {
F_253 ( V_19 , V_2 , V_36 , V_323 ) ;
V_35 = 0 ;
}
if ( V_35 >= 0 ) {
if ( * V_36 == 0 )
F_188 ( V_2 -> V_8 [ * V_36 ] , V_83 ,
V_2 -> V_17 [ * V_36 ] ) ;
else
F_252 ( V_2 -> V_8 [ * V_36 ] , V_83 ,
V_2 -> V_17 [ * V_36 ] ) ;
}
return V_35 ;
}
static int F_256 ( struct V_18 * V_325 ,
struct V_1 * V_326 ,
struct V_1 * V_327 ,
char * V_328 )
{
int V_329 ;
int V_330 , V_331 ;
unsigned long V_332 , V_333 ;
V_330 = F_223 ( V_326 -> V_8 [ 0 ] , V_326 -> V_17 [ 0 ] ) ;
V_331 = F_223 ( V_327 -> V_8 [ 0 ] , V_327 -> V_17 [ 0 ] ) ;
if ( V_330 != V_331 )
return 1 ;
V_332 = F_230 ( V_326 -> V_8 [ 0 ] , V_326 -> V_17 [ 0 ] ) ;
V_333 = F_230 ( V_327 -> V_8 [ 0 ] ,
V_327 -> V_17 [ 0 ] ) ;
F_156 ( V_326 -> V_8 [ 0 ] , V_328 , V_332 , V_330 ) ;
V_329 = F_183 ( V_327 -> V_8 [ 0 ] , V_328 , V_333 , V_330 ) ;
if ( V_329 )
return 1 ;
return 0 ;
}
int F_257 ( struct V_18 * V_325 ,
struct V_18 * V_334 ,
T_6 V_335 , void * V_336 )
{
int V_35 ;
int V_329 ;
struct V_1 * V_326 = NULL ;
struct V_1 * V_327 = NULL ;
struct V_154 V_337 ;
struct V_154 V_199 ;
char * V_328 = NULL ;
int V_338 ;
int V_339 ;
int V_340 ;
int V_341 ;
int V_342 ;
int V_343 ;
int V_344 ;
int V_345 ;
T_2 V_346 ;
T_2 V_347 ;
T_2 V_348 ;
T_2 V_349 ;
V_326 = F_1 () ;
if ( ! V_326 ) {
V_35 = - V_86 ;
goto V_286;
}
V_327 = F_1 () ;
if ( ! V_327 ) {
V_35 = - V_86 ;
goto V_286;
}
V_328 = F_229 ( V_325 -> V_143 , V_4 ) ;
if ( ! V_328 ) {
V_35 = - V_86 ;
goto V_286;
}
V_326 -> V_235 = 1 ;
V_326 -> V_238 = 1 ;
V_327 -> V_235 = 1 ;
V_327 -> V_238 = 1 ;
F_189 ( & V_325 -> V_23 -> V_237 ) ;
V_340 = F_32 ( V_325 -> V_117 ) ;
V_338 = V_340 ;
V_326 -> V_8 [ V_340 ] = V_325 -> V_117 ;
F_112 ( V_326 -> V_8 [ V_340 ] ) ;
V_341 = F_32 ( V_334 -> V_117 ) ;
V_339 = V_341 ;
V_327 -> V_8 [ V_341 ] = V_334 -> V_117 ;
F_112 ( V_327 -> V_8 [ V_341 ] ) ;
F_190 ( & V_325 -> V_23 -> V_237 ) ;
if ( V_340 == 0 )
F_188 ( V_326 -> V_8 [ V_340 ] ,
& V_337 , V_326 -> V_17 [ V_340 ] ) ;
else
F_252 ( V_326 -> V_8 [ V_340 ] ,
& V_337 , V_326 -> V_17 [ V_340 ] ) ;
if ( V_341 == 0 )
F_188 ( V_327 -> V_8 [ V_341 ] ,
& V_199 , V_327 -> V_17 [ V_341 ] ) ;
else
F_252 ( V_327 -> V_8 [ V_341 ] ,
& V_199 , V_327 -> V_17 [ V_341 ] ) ;
V_342 = V_343 = 0 ;
V_344 = V_345 = 0 ;
while ( 1 ) {
if ( V_344 && ! V_342 ) {
V_35 = F_255 ( V_325 , V_326 , & V_340 ,
V_338 ,
V_344 != V_350 ,
& V_337 ) ;
if ( V_35 < 0 )
V_342 = V_351 ;
V_344 = 0 ;
}
if ( V_345 && ! V_343 ) {
V_35 = F_255 ( V_334 , V_327 , & V_341 ,
V_339 ,
V_345 != V_350 ,
& V_199 ) ;
if ( V_35 < 0 )
V_343 = V_351 ;
V_345 = 0 ;
}
if ( V_342 && V_343 ) {
V_35 = 0 ;
goto V_286;
} else if ( V_342 ) {
if ( V_341 == 0 ) {
V_35 = V_335 ( V_325 , V_334 ,
V_326 , V_327 ,
& V_199 ,
V_352 ,
V_336 ) ;
if ( V_35 < 0 )
goto V_286;
}
V_345 = V_351 ;
continue;
} else if ( V_343 ) {
if ( V_340 == 0 ) {
V_35 = V_335 ( V_325 , V_334 ,
V_326 , V_327 ,
& V_337 ,
V_353 ,
V_336 ) ;
if ( V_35 < 0 )
goto V_286;
}
V_344 = V_351 ;
continue;
}
if ( V_340 == 0 && V_341 == 0 ) {
V_329 = F_145 ( & V_337 , & V_199 ) ;
if ( V_329 < 0 ) {
V_35 = V_335 ( V_325 , V_334 ,
V_326 , V_327 ,
& V_337 ,
V_353 ,
V_336 ) ;
if ( V_35 < 0 )
goto V_286;
V_344 = V_351 ;
} else if ( V_329 > 0 ) {
V_35 = V_335 ( V_325 , V_334 ,
V_326 , V_327 ,
& V_199 ,
V_352 ,
V_336 ) ;
if ( V_35 < 0 )
goto V_286;
V_345 = V_351 ;
} else {
enum V_354 V_355 ;
F_31 ( ! F_132 ( V_326 -> V_8 [ 0 ] ) ) ;
V_35 = F_256 ( V_325 , V_326 ,
V_327 , V_328 ) ;
if ( V_35 )
V_355 = V_356 ;
else
V_355 = V_357 ;
V_35 = V_335 ( V_325 , V_334 ,
V_326 , V_327 ,
& V_337 , V_355 , V_336 ) ;
if ( V_35 < 0 )
goto V_286;
V_344 = V_351 ;
V_345 = V_351 ;
}
} else if ( V_340 == V_341 ) {
V_329 = F_145 ( & V_337 , & V_199 ) ;
if ( V_329 < 0 ) {
V_344 = V_351 ;
} else if ( V_329 > 0 ) {
V_345 = V_351 ;
} else {
V_346 = F_79 (
V_326 -> V_8 [ V_340 ] ,
V_326 -> V_17 [ V_340 ] ) ;
V_347 = F_79 (
V_327 -> V_8 [ V_341 ] ,
V_327 -> V_17 [ V_341 ] ) ;
V_348 = F_80 (
V_326 -> V_8 [ V_340 ] ,
V_326 -> V_17 [ V_340 ] ) ;
V_349 = F_80 (
V_327 -> V_8 [ V_341 ] ,
V_327 -> V_17 [ V_341 ] ) ;
if ( V_346 == V_347 &&
V_348 == V_349 ) {
V_344 = V_350 ;
V_345 = V_350 ;
} else {
V_344 = V_351 ;
V_345 = V_351 ;
}
}
} else if ( V_340 < V_341 ) {
V_345 = V_351 ;
} else {
V_344 = V_351 ;
}
}
V_286:
F_7 ( V_326 ) ;
F_7 ( V_327 ) ;
F_69 ( V_328 ) ;
return V_35 ;
}
int F_251 ( struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_154 * V_83 , int V_36 , T_2 V_321 )
{
int V_77 ;
struct V_14 * V_255 ;
F_31 ( ! V_2 -> V_217 ) ;
while ( V_36 < V_7 ) {
if ( ! V_2 -> V_8 [ V_36 ] )
return 1 ;
V_77 = V_2 -> V_17 [ V_36 ] + 1 ;
V_255 = V_2 -> V_8 [ V_36 ] ;
V_63:
if ( V_77 >= F_87 ( V_255 ) ) {
int V_35 ;
int V_358 ;
struct V_154 V_359 ;
if ( V_36 + 1 >= V_7 ||
! V_2 -> V_8 [ V_36 + 1 ] )
return 1 ;
if ( V_2 -> V_9 [ V_36 + 1 ] ) {
V_36 ++ ;
continue;
}
V_77 = F_87 ( V_255 ) - 1 ;
if ( V_36 == 0 )
F_188 ( V_255 , & V_359 , V_77 ) ;
else
F_252 ( V_255 , & V_359 , V_77 ) ;
V_358 = V_2 -> V_234 ;
F_8 ( V_2 ) ;
V_2 -> V_234 = V_36 ;
V_35 = F_186 ( NULL , V_19 , & V_359 , V_2 ,
0 , 0 ) ;
V_2 -> V_234 = V_358 ;
if ( V_35 < 0 )
return V_35 ;
V_255 = V_2 -> V_8 [ V_36 ] ;
V_77 = V_2 -> V_17 [ V_36 ] ;
if ( V_35 == 0 )
V_77 ++ ;
goto V_63;
}
if ( V_36 == 0 )
F_188 ( V_255 , V_83 , V_77 ) ;
else {
T_2 V_161 = F_80 ( V_255 , V_77 ) ;
if ( V_161 < V_321 ) {
V_77 ++ ;
goto V_63;
}
F_252 ( V_255 , V_83 , V_77 ) ;
}
return 0 ;
}
return 1 ;
}
int F_187 ( struct V_18 * V_19 , struct V_1 * V_2 )
{
return F_258 ( V_19 , V_2 , 0 ) ;
}
int F_258 ( struct V_18 * V_19 , struct V_1 * V_2 ,
T_2 V_132 )
{
int V_77 ;
int V_36 ;
struct V_14 * V_255 ;
struct V_14 * V_63 ;
struct V_154 V_83 ;
T_4 V_96 ;
int V_35 ;
int V_360 = V_2 -> V_242 ;
int V_361 = 0 ;
V_96 = F_87 ( V_2 -> V_8 [ 0 ] ) ;
if ( V_96 == 0 )
return 1 ;
F_188 ( V_2 -> V_8 [ 0 ] , & V_83 , V_96 - 1 ) ;
V_224:
V_36 = 1 ;
V_63 = NULL ;
V_361 = 0 ;
F_8 ( V_2 ) ;
V_2 -> V_217 = 1 ;
V_2 -> V_242 = 1 ;
if ( V_132 )
V_35 = F_195 ( V_19 , & V_83 , V_2 , V_132 ) ;
else
V_35 = F_186 ( NULL , V_19 , & V_83 , V_2 , 0 , 0 ) ;
V_2 -> V_217 = 0 ;
if ( V_35 < 0 )
return V_35 ;
V_96 = F_87 ( V_2 -> V_8 [ 0 ] ) ;
if ( V_96 > 0 && V_2 -> V_17 [ 0 ] < V_96 - 1 ) {
if ( V_35 == 0 )
V_2 -> V_17 [ 0 ] ++ ;
V_35 = 0 ;
goto V_225;
}
if ( V_96 > 0 && V_35 > 0 && V_2 -> V_17 [ 0 ] == V_96 - 1 ) {
V_35 = 0 ;
goto V_225;
}
while ( V_36 < V_7 ) {
if ( ! V_2 -> V_8 [ V_36 ] ) {
V_35 = 1 ;
goto V_225;
}
V_77 = V_2 -> V_17 [ V_36 ] + 1 ;
V_255 = V_2 -> V_8 [ V_36 ] ;
if ( V_77 >= F_87 ( V_255 ) ) {
V_36 ++ ;
if ( V_36 == V_7 ) {
V_35 = 1 ;
goto V_225;
}
continue;
}
if ( V_63 ) {
F_10 ( V_63 , V_361 ) ;
F_11 ( V_63 ) ;
}
V_63 = V_255 ;
V_361 = V_2 -> V_9 [ V_36 ] ;
V_35 = F_177 ( NULL , V_19 , V_2 , & V_63 , V_36 ,
V_77 , & V_83 , 0 ) ;
if ( V_35 == - V_220 )
goto V_224;
if ( V_35 < 0 ) {
F_8 ( V_2 ) ;
goto V_225;
}
if ( ! V_2 -> V_238 ) {
V_35 = F_259 ( V_63 ) ;
if ( ! V_35 && V_132 ) {
F_11 ( V_63 ) ;
F_8 ( V_2 ) ;
F_260 () ;
goto V_224;
}
if ( ! V_35 ) {
F_3 ( V_2 ) ;
F_22 ( V_63 ) ;
F_5 ( V_2 , V_63 ,
V_10 ) ;
}
V_361 = V_10 ;
}
break;
}
V_2 -> V_17 [ V_36 ] = V_77 ;
while ( 1 ) {
V_36 -- ;
V_255 = V_2 -> V_8 [ V_36 ] ;
if ( V_2 -> V_9 [ V_36 ] )
F_10 ( V_255 , V_2 -> V_9 [ V_36 ] ) ;
F_11 ( V_255 ) ;
V_2 -> V_8 [ V_36 ] = V_63 ;
V_2 -> V_17 [ V_36 ] = 0 ;
if ( ! V_2 -> V_238 )
V_2 -> V_9 [ V_36 ] = V_361 ;
if ( ! V_36 )
break;
V_35 = F_177 ( NULL , V_19 , V_2 , & V_63 , V_36 ,
0 , & V_83 , 0 ) ;
if ( V_35 == - V_220 )
goto V_224;
if ( V_35 < 0 ) {
F_8 ( V_2 ) ;
goto V_225;
}
if ( ! V_2 -> V_238 ) {
V_35 = F_259 ( V_63 ) ;
if ( ! V_35 ) {
F_3 ( V_2 ) ;
F_22 ( V_63 ) ;
F_5 ( V_2 , V_63 ,
V_10 ) ;
}
V_361 = V_10 ;
}
}
V_35 = 0 ;
V_225:
F_175 ( V_2 , 0 , 1 , 0 , NULL ) ;
V_2 -> V_242 = V_360 ;
if ( ! V_360 )
F_3 ( V_2 ) ;
return V_35 ;
}
int F_261 ( struct V_18 * V_19 ,
struct V_1 * V_2 , T_2 V_362 ,
int type )
{
struct V_154 V_232 ;
struct V_14 * V_171 ;
T_4 V_96 ;
int V_35 ;
while ( 1 ) {
if ( V_2 -> V_17 [ 0 ] == 0 ) {
F_3 ( V_2 ) ;
V_35 = F_197 ( V_19 , V_2 ) ;
if ( V_35 != 0 )
return V_35 ;
} else {
V_2 -> V_17 [ 0 ] -- ;
}
V_171 = V_2 -> V_8 [ 0 ] ;
V_96 = F_87 ( V_171 ) ;
if ( V_96 == 0 )
return 1 ;
if ( V_2 -> V_17 [ 0 ] == V_96 )
V_2 -> V_17 [ 0 ] -- ;
F_188 ( V_171 , & V_232 , V_2 -> V_17 [ 0 ] ) ;
if ( V_232 . V_124 < V_362 )
break;
if ( V_232 . type == type )
return 0 ;
if ( V_232 . V_124 == V_362 &&
V_232 . type < type )
break;
}
return 1 ;
}
int F_262 ( struct V_18 * V_19 ,
struct V_1 * V_2 , T_2 V_362 )
{
struct V_154 V_232 ;
struct V_14 * V_171 ;
T_4 V_96 ;
int V_35 ;
while ( 1 ) {
if ( V_2 -> V_17 [ 0 ] == 0 ) {
F_3 ( V_2 ) ;
V_35 = F_197 ( V_19 , V_2 ) ;
if ( V_35 != 0 )
return V_35 ;
} else {
V_2 -> V_17 [ 0 ] -- ;
}
V_171 = V_2 -> V_8 [ 0 ] ;
V_96 = F_87 ( V_171 ) ;
if ( V_96 == 0 )
return 1 ;
if ( V_2 -> V_17 [ 0 ] == V_96 )
V_2 -> V_17 [ 0 ] -- ;
F_188 ( V_171 , & V_232 , V_2 -> V_17 [ 0 ] ) ;
if ( V_232 . V_124 < V_362 )
break;
if ( V_232 . type == V_363 ||
V_232 . type == V_364 )
return 0 ;
if ( V_232 . V_124 == V_362 &&
V_232 . type < V_363 )
break;
}
return 1 ;
}
