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
#ifdef F_6
if ( V_15 ) {
F_4 ( V_15 , V_16 ) ;
if ( V_16 == V_12 )
V_16 = V_13 ;
else if ( V_16 == V_10 )
V_16 = V_11 ;
}
F_3 ( V_5 ) ;
#endif
for ( V_6 = V_7 - 1 ; V_6 >= 0 ; V_6 -- ) {
if ( V_5 -> V_8 [ V_6 ] && V_5 -> V_9 [ V_6 ] ) {
F_7 ( V_5 -> V_8 [ V_6 ] , V_5 -> V_9 [ V_6 ] ) ;
if ( V_5 -> V_9 [ V_6 ] == V_13 )
V_5 -> V_9 [ V_6 ] = V_12 ;
else if ( V_5 -> V_9 [ V_6 ] == V_11 )
V_5 -> V_9 [ V_6 ] = V_10 ;
}
}
#ifdef F_6
if ( V_15 )
F_7 ( V_15 , V_16 ) ;
#endif
}
void F_8 ( struct V_1 * V_5 )
{
if ( ! V_5 )
return;
F_9 ( V_5 ) ;
F_10 ( V_3 , V_5 ) ;
}
T_1 void F_9 ( struct V_1 * V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
V_5 -> V_17 [ V_6 ] = 0 ;
if ( ! V_5 -> V_8 [ V_6 ] )
continue;
if ( V_5 -> V_9 [ V_6 ] ) {
F_11 ( V_5 -> V_8 [ V_6 ] , V_5 -> V_9 [ V_6 ] ) ;
V_5 -> V_9 [ V_6 ] = 0 ;
}
F_12 ( V_5 -> V_8 [ V_6 ] ) ;
V_5 -> V_8 [ V_6 ] = NULL ;
}
}
struct V_14 * F_13 ( struct V_18 * V_19 )
{
struct V_14 * V_20 ;
while ( 1 ) {
F_14 () ;
V_20 = F_15 ( V_19 -> V_21 ) ;
if ( F_16 ( & V_20 -> V_22 ) ) {
F_17 () ;
break;
}
F_17 () ;
F_18 () ;
}
return V_20 ;
}
struct V_14 * F_19 ( struct V_18 * V_19 )
{
struct V_14 * V_20 ;
while ( 1 ) {
V_20 = F_13 ( V_19 ) ;
F_20 ( V_20 ) ;
if ( V_20 == V_19 -> V_21 )
break;
F_21 ( V_20 ) ;
F_12 ( V_20 ) ;
}
return V_20 ;
}
static struct V_14 * F_22 ( struct V_18 * V_19 )
{
struct V_14 * V_20 ;
while ( 1 ) {
V_20 = F_13 ( V_19 ) ;
F_23 ( V_20 ) ;
if ( V_20 == V_19 -> V_21 )
break;
F_24 ( V_20 ) ;
F_12 ( V_20 ) ;
}
return V_20 ;
}
static void F_25 ( struct V_18 * V_19 )
{
F_26 ( & V_19 -> V_23 -> V_24 ) ;
if ( F_27 ( V_25 , & V_19 -> V_26 ) &&
F_28 ( & V_19 -> V_27 ) ) {
F_29 ( & V_19 -> V_27 ,
& V_19 -> V_23 -> V_28 ) ;
}
F_30 ( & V_19 -> V_23 -> V_24 ) ;
}
int F_31 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_14 * V_31 ,
struct V_14 * * V_32 , T_2 V_33 )
{
struct V_14 * V_34 ;
int V_35 = 0 ;
int V_36 ;
struct V_37 V_38 ;
F_32 ( F_27 ( V_39 , & V_19 -> V_26 ) &&
V_30 -> V_40 != V_19 -> V_23 -> V_41 -> V_40 ) ;
F_32 ( F_27 ( V_39 , & V_19 -> V_26 ) &&
V_30 -> V_40 != V_19 -> V_42 ) ;
V_36 = F_33 ( V_31 ) ;
if ( V_36 == 0 )
F_34 ( V_31 , & V_38 , 0 ) ;
else
F_35 ( V_31 , & V_38 , 0 ) ;
V_34 = F_36 ( V_30 , V_19 , V_31 -> V_43 , 0 ,
V_33 , & V_38 , V_36 ,
V_31 -> V_44 , 0 ) ;
if ( F_37 ( V_34 ) )
return F_38 ( V_34 ) ;
F_39 ( V_34 , V_31 , 0 , 0 , V_34 -> V_43 ) ;
F_40 ( V_34 , V_34 -> V_44 ) ;
F_41 ( V_34 , V_30 -> V_40 ) ;
F_42 ( V_34 , V_45 ) ;
F_43 ( V_34 , V_46 |
V_47 ) ;
if ( V_33 == V_48 )
F_44 ( V_34 , V_47 ) ;
else
F_45 ( V_34 , V_33 ) ;
F_46 ( V_34 , V_19 -> V_23 -> V_49 , F_47 () ,
V_50 ) ;
F_32 ( F_48 ( V_31 ) > V_30 -> V_40 ) ;
if ( V_33 == V_48 )
V_35 = F_49 ( V_30 , V_19 , V_34 , 1 , 1 ) ;
else
V_35 = F_49 ( V_30 , V_19 , V_34 , 0 , 1 ) ;
if ( V_35 )
return V_35 ;
F_50 ( V_34 ) ;
* V_32 = V_34 ;
return 0 ;
}
static inline void F_51 ( struct V_51 * V_23 )
{
F_52 ( & V_23 -> V_52 ) ;
}
static inline void F_53 ( struct V_51 * V_23 )
{
F_54 ( & V_23 -> V_52 ) ;
}
static inline void F_55 ( struct V_51 * V_23 )
{
F_56 ( & V_23 -> V_52 ) ;
}
static inline void F_57 ( struct V_51 * V_23 )
{
F_58 ( & V_23 -> V_52 ) ;
}
static inline T_2 F_59 ( struct V_51 * V_23 )
{
return F_60 ( & V_23 -> V_53 ) ;
}
T_2 F_61 ( struct V_51 * V_23 ,
struct V_54 * V_55 )
{
F_55 ( V_23 ) ;
F_26 ( & V_23 -> V_56 ) ;
if ( ! V_55 -> V_57 ) {
V_55 -> V_57 = F_59 ( V_23 ) ;
F_62 ( & V_55 -> V_58 , & V_23 -> V_59 ) ;
}
F_30 ( & V_23 -> V_56 ) ;
F_57 ( V_23 ) ;
return V_55 -> V_57 ;
}
void F_63 ( struct V_51 * V_23 ,
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
F_26 ( & V_23 -> V_56 ) ;
F_64 ( & V_55 -> V_58 ) ;
V_55 -> V_57 = 0 ;
F_65 (cur_elem, &fs_info->tree_mod_seq_list, list) {
if ( V_64 -> V_57 < V_67 ) {
if ( V_68 > V_64 -> V_57 ) {
F_30 ( & V_23 -> V_56 ) ;
return;
}
V_67 = V_64 -> V_57 ;
}
}
F_30 ( & V_23 -> V_56 ) ;
F_55 ( V_23 ) ;
V_61 = & V_23 -> V_69 ;
for ( V_21 = F_66 ( V_61 ) ; V_21 ; V_21 = V_63 ) {
V_63 = F_67 ( V_21 ) ;
V_66 = F_68 ( V_21 , struct V_65 , V_21 ) ;
if ( V_66 -> V_57 > V_67 )
continue;
F_69 ( V_21 , V_61 ) ;
F_70 ( V_66 ) ;
}
F_57 ( V_23 ) ;
}
static T_1 int
F_71 ( struct V_51 * V_23 , struct V_65 * V_66 )
{
struct V_60 * V_61 ;
struct V_62 * * V_70 ;
struct V_62 * V_71 = NULL ;
struct V_65 * V_72 ;
F_72 ( ! V_66 ) ;
V_66 -> V_57 = F_59 ( V_23 ) ;
V_61 = & V_23 -> V_69 ;
V_70 = & V_61 -> V_62 ;
while ( * V_70 ) {
V_72 = F_68 ( * V_70 , struct V_65 , V_21 ) ;
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
F_73 ( & V_66 -> V_21 , V_71 , V_70 ) ;
F_74 ( & V_66 -> V_21 , V_61 ) ;
return 0 ;
}
static inline int F_75 ( struct V_51 * V_23 ,
struct V_14 * V_20 ) {
F_76 () ;
if ( F_28 ( & ( V_23 ) -> V_59 ) )
return 1 ;
if ( V_20 && F_33 ( V_20 ) == 0 )
return 1 ;
F_55 ( V_23 ) ;
if ( F_28 ( & ( V_23 ) -> V_59 ) ) {
F_57 ( V_23 ) ;
return 1 ;
}
return 0 ;
}
static inline int F_77 ( const struct V_51 * V_23 ,
struct V_14 * V_20 )
{
F_76 () ;
if ( F_28 ( & ( V_23 ) -> V_59 ) )
return 0 ;
if ( V_20 && F_33 ( V_20 ) == 0 )
return 0 ;
return 1 ;
}
static struct V_65 *
F_78 ( struct V_14 * V_20 , int V_77 ,
enum V_78 V_79 , T_3 V_80 )
{
struct V_65 * V_66 ;
V_66 = F_79 ( sizeof( * V_66 ) , V_80 ) ;
if ( ! V_66 )
return NULL ;
V_66 -> V_73 = V_20 -> V_44 >> V_81 ;
if ( V_79 != V_82 ) {
F_35 ( V_20 , & V_66 -> V_83 , V_77 ) ;
V_66 -> V_84 = F_80 ( V_20 , V_77 ) ;
}
V_66 -> V_79 = V_79 ;
V_66 -> V_77 = V_77 ;
V_66 -> V_85 = F_81 ( V_20 , V_77 ) ;
F_82 ( & V_66 -> V_21 ) ;
return V_66 ;
}
static T_1 int
F_83 ( struct V_51 * V_23 ,
struct V_14 * V_20 , int V_77 ,
enum V_78 V_79 , T_3 V_80 )
{
struct V_65 * V_66 ;
int V_35 ;
if ( ! F_77 ( V_23 , V_20 ) )
return 0 ;
V_66 = F_78 ( V_20 , V_77 , V_79 , V_80 ) ;
if ( ! V_66 )
return - V_86 ;
if ( F_75 ( V_23 , V_20 ) ) {
F_70 ( V_66 ) ;
return 0 ;
}
V_35 = F_71 ( V_23 , V_66 ) ;
F_57 ( V_23 ) ;
if ( V_35 )
F_70 ( V_66 ) ;
return V_35 ;
}
static T_1 int
F_84 ( struct V_51 * V_23 ,
struct V_14 * V_20 , int V_87 , int V_88 ,
int V_89 , T_3 V_80 )
{
struct V_65 * V_66 = NULL ;
struct V_65 * * V_90 = NULL ;
int V_35 = 0 ;
int V_6 ;
int V_91 = 0 ;
if ( ! F_77 ( V_23 , V_20 ) )
return 0 ;
V_90 = F_79 ( V_89 * sizeof( struct V_65 * ) , V_80 ) ;
if ( ! V_90 )
return - V_86 ;
V_66 = F_79 ( sizeof( * V_66 ) , V_80 ) ;
if ( ! V_66 ) {
V_35 = - V_86 ;
goto V_92;
}
V_66 -> V_73 = V_20 -> V_44 >> V_81 ;
V_66 -> V_77 = V_88 ;
V_66 -> V_93 . V_87 = V_87 ;
V_66 -> V_93 . V_89 = V_89 ;
V_66 -> V_79 = V_94 ;
for ( V_6 = 0 ; V_6 + V_87 < V_88 && V_6 < V_89 ; V_6 ++ ) {
V_90 [ V_6 ] = F_78 ( V_20 , V_6 + V_87 ,
V_95 , V_80 ) ;
if ( ! V_90 [ V_6 ] ) {
V_35 = - V_86 ;
goto V_92;
}
}
if ( F_75 ( V_23 , V_20 ) )
goto V_92;
V_91 = 1 ;
for ( V_6 = 0 ; V_6 + V_87 < V_88 && V_6 < V_89 ; V_6 ++ ) {
V_35 = F_71 ( V_23 , V_90 [ V_6 ] ) ;
if ( V_35 )
goto V_92;
}
V_35 = F_71 ( V_23 , V_66 ) ;
if ( V_35 )
goto V_92;
F_57 ( V_23 ) ;
F_70 ( V_90 ) ;
return 0 ;
V_92:
for ( V_6 = 0 ; V_6 < V_89 ; V_6 ++ ) {
if ( V_90 [ V_6 ] && ! F_85 ( & V_90 [ V_6 ] -> V_21 ) )
F_69 ( & V_90 [ V_6 ] -> V_21 , & V_23 -> V_69 ) ;
F_70 ( V_90 [ V_6 ] ) ;
}
if ( V_91 )
F_57 ( V_23 ) ;
F_70 ( V_90 ) ;
F_70 ( V_66 ) ;
return V_35 ;
}
static inline int
F_86 ( struct V_51 * V_23 ,
struct V_65 * * V_90 ,
int V_96 )
{
int V_6 , V_97 ;
int V_35 ;
for ( V_6 = V_96 - 1 ; V_6 >= 0 ; V_6 -- ) {
V_35 = F_71 ( V_23 , V_90 [ V_6 ] ) ;
if ( V_35 ) {
for ( V_97 = V_96 - 1 ; V_97 > V_6 ; V_97 -- )
F_69 ( & V_90 [ V_97 ] -> V_21 ,
& V_23 -> V_69 ) ;
return V_35 ;
}
}
return 0 ;
}
static T_1 int
F_87 ( struct V_51 * V_23 ,
struct V_14 * V_98 ,
struct V_14 * V_99 , T_3 V_80 ,
int V_100 )
{
struct V_65 * V_66 = NULL ;
struct V_65 * * V_90 = NULL ;
int V_96 = 0 ;
int V_35 = 0 ;
int V_6 ;
if ( ! F_77 ( V_23 , NULL ) )
return 0 ;
if ( V_100 && F_33 ( V_98 ) > 0 ) {
V_96 = F_88 ( V_98 ) ;
V_90 = F_79 ( V_96 * sizeof( struct V_65 * ) ,
V_80 ) ;
if ( ! V_90 ) {
V_35 = - V_86 ;
goto V_92;
}
for ( V_6 = 0 ; V_6 < V_96 ; V_6 ++ ) {
V_90 [ V_6 ] = F_78 ( V_98 , V_6 ,
V_101 , V_80 ) ;
if ( ! V_90 [ V_6 ] ) {
V_35 = - V_86 ;
goto V_92;
}
}
}
V_66 = F_79 ( sizeof( * V_66 ) , V_80 ) ;
if ( ! V_66 ) {
V_35 = - V_86 ;
goto V_92;
}
V_66 -> V_73 = V_99 -> V_44 >> V_81 ;
V_66 -> V_98 . V_102 = V_98 -> V_44 ;
V_66 -> V_98 . V_36 = F_33 ( V_98 ) ;
V_66 -> V_85 = F_48 ( V_98 ) ;
V_66 -> V_79 = V_103 ;
if ( F_75 ( V_23 , NULL ) )
goto V_92;
if ( V_90 )
V_35 = F_86 ( V_23 , V_90 , V_96 ) ;
if ( ! V_35 )
V_35 = F_71 ( V_23 , V_66 ) ;
F_57 ( V_23 ) ;
if ( V_35 )
goto V_92;
F_70 ( V_90 ) ;
return V_35 ;
V_92:
if ( V_90 ) {
for ( V_6 = 0 ; V_6 < V_96 ; V_6 ++ )
F_70 ( V_90 [ V_6 ] ) ;
F_70 ( V_90 ) ;
}
F_70 ( V_66 ) ;
return V_35 ;
}
static struct V_65 *
F_89 ( struct V_51 * V_23 , T_2 V_44 , T_2 V_67 ,
int V_104 )
{
struct V_60 * V_61 ;
struct V_62 * V_21 ;
struct V_65 * V_72 = NULL ;
struct V_65 * V_105 = NULL ;
T_2 V_73 = V_44 >> V_81 ;
F_51 ( V_23 ) ;
V_61 = & V_23 -> V_69 ;
V_21 = V_61 -> V_62 ;
while ( V_21 ) {
V_72 = F_68 ( V_21 , struct V_65 , V_21 ) ;
if ( V_72 -> V_73 < V_73 ) {
V_21 = V_21 -> V_74 ;
} else if ( V_72 -> V_73 > V_73 ) {
V_21 = V_21 -> V_75 ;
} else if ( V_72 -> V_57 < V_67 ) {
V_21 = V_21 -> V_74 ;
} else if ( ! V_104 ) {
if ( V_105 )
F_72 ( V_105 -> V_57 > V_72 -> V_57 ) ;
V_105 = V_72 ;
V_21 = V_21 -> V_74 ;
} else if ( V_72 -> V_57 > V_67 ) {
if ( V_105 )
F_72 ( V_105 -> V_57 < V_72 -> V_57 ) ;
V_105 = V_72 ;
V_21 = V_21 -> V_75 ;
} else {
V_105 = V_72 ;
break;
}
}
F_53 ( V_23 ) ;
return V_105 ;
}
static struct V_65 *
F_90 ( struct V_51 * V_23 , T_2 V_44 ,
T_2 V_67 )
{
return F_89 ( V_23 , V_44 , V_67 , 1 ) ;
}
static struct V_65 *
F_91 ( struct V_51 * V_23 , T_2 V_44 , T_2 V_67 )
{
return F_89 ( V_23 , V_44 , V_67 , 0 ) ;
}
static T_1 int
F_92 ( struct V_51 * V_23 , struct V_14 * V_106 ,
struct V_14 * V_107 , unsigned long V_108 ,
unsigned long V_109 , int V_89 )
{
int V_35 = 0 ;
struct V_65 * * V_90 = NULL ;
struct V_65 * * V_110 , * * V_111 ;
int V_6 ;
int V_91 = 0 ;
if ( ! F_77 ( V_23 , NULL ) )
return 0 ;
if ( F_33 ( V_106 ) == 0 && F_33 ( V_107 ) == 0 )
return 0 ;
V_90 = F_79 ( V_89 * 2 * sizeof( struct V_65 * ) ,
V_4 ) ;
if ( ! V_90 )
return - V_86 ;
V_110 = V_90 ;
V_111 = V_90 + V_89 ;
for ( V_6 = 0 ; V_6 < V_89 ; V_6 ++ ) {
V_111 [ V_6 ] = F_78 ( V_107 , V_6 + V_109 ,
V_112 , V_4 ) ;
if ( ! V_111 [ V_6 ] ) {
V_35 = - V_86 ;
goto V_92;
}
V_110 [ V_6 ] = F_78 ( V_106 , V_6 + V_108 ,
V_82 , V_4 ) ;
if ( ! V_110 [ V_6 ] ) {
V_35 = - V_86 ;
goto V_92;
}
}
if ( F_75 ( V_23 , NULL ) )
goto V_92;
V_91 = 1 ;
for ( V_6 = 0 ; V_6 < V_89 ; V_6 ++ ) {
V_35 = F_71 ( V_23 , V_111 [ V_6 ] ) ;
if ( V_35 )
goto V_92;
V_35 = F_71 ( V_23 , V_110 [ V_6 ] ) ;
if ( V_35 )
goto V_92;
}
F_57 ( V_23 ) ;
F_70 ( V_90 ) ;
return 0 ;
V_92:
for ( V_6 = 0 ; V_6 < V_89 * 2 ; V_6 ++ ) {
if ( V_90 [ V_6 ] && ! F_85 ( & V_90 [ V_6 ] -> V_21 ) )
F_69 ( & V_90 [ V_6 ] -> V_21 , & V_23 -> V_69 ) ;
F_70 ( V_90 [ V_6 ] ) ;
}
if ( V_91 )
F_57 ( V_23 ) ;
F_70 ( V_90 ) ;
return V_35 ;
}
static inline void
F_93 ( struct V_51 * V_23 , struct V_14 * V_106 ,
int V_108 , int V_109 , int V_89 )
{
int V_35 ;
V_35 = F_84 ( V_23 , V_106 , V_108 , V_109 ,
V_89 , V_4 ) ;
F_72 ( V_35 < 0 ) ;
}
static T_1 void
F_94 ( struct V_51 * V_23 ,
struct V_14 * V_20 , int V_77 , int V_113 )
{
int V_35 ;
V_35 = F_83 ( V_23 , V_20 , V_77 ,
V_114 ,
V_113 ? V_115 : V_4 ) ;
F_72 ( V_35 < 0 ) ;
}
static T_1 int
F_95 ( struct V_51 * V_23 , struct V_14 * V_20 )
{
struct V_65 * * V_90 = NULL ;
int V_96 = 0 ;
int V_6 ;
int V_35 = 0 ;
if ( F_33 ( V_20 ) == 0 )
return 0 ;
if ( ! F_77 ( V_23 , NULL ) )
return 0 ;
V_96 = F_88 ( V_20 ) ;
V_90 = F_79 ( V_96 * sizeof( struct V_65 * ) ,
V_4 ) ;
if ( ! V_90 )
return - V_86 ;
for ( V_6 = 0 ; V_6 < V_96 ; V_6 ++ ) {
V_90 [ V_6 ] = F_78 ( V_20 , V_6 ,
V_101 , V_4 ) ;
if ( ! V_90 [ V_6 ] ) {
V_35 = - V_86 ;
goto V_92;
}
}
if ( F_75 ( V_23 , V_20 ) )
goto V_92;
V_35 = F_86 ( V_23 , V_90 , V_96 ) ;
F_57 ( V_23 ) ;
if ( V_35 )
goto V_92;
F_70 ( V_90 ) ;
return 0 ;
V_92:
for ( V_6 = 0 ; V_6 < V_96 ; V_6 ++ )
F_70 ( V_90 [ V_6 ] ) ;
F_70 ( V_90 ) ;
return V_35 ;
}
static T_1 void
F_96 ( struct V_18 * V_19 ,
struct V_14 * V_116 ,
int V_100 )
{
int V_35 ;
V_35 = F_87 ( V_19 -> V_23 , V_19 -> V_21 ,
V_116 , V_4 , V_100 ) ;
F_72 ( V_35 < 0 ) ;
}
int F_97 ( struct V_18 * V_19 ,
struct V_14 * V_31 )
{
if ( F_27 ( V_39 , & V_19 -> V_26 ) &&
V_31 != V_19 -> V_21 && V_31 != V_19 -> V_117 &&
( F_48 ( V_31 ) <=
F_98 ( & V_19 -> V_118 ) ||
F_99 ( V_31 , V_47 ) ) )
return 1 ;
#ifdef F_100
if ( F_27 ( V_39 , & V_19 -> V_26 ) &&
F_101 ( V_31 ) < V_45 )
return 1 ;
#endif
return 0 ;
}
static T_1 int F_102 ( struct V_29 * V_30 ,
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
if ( F_97 ( V_19 , V_31 ) ) {
V_35 = F_103 ( V_30 , V_19 , V_31 -> V_44 ,
F_33 ( V_31 ) , 1 ,
& V_22 , & V_80 ) ;
if ( V_35 )
return V_35 ;
if ( V_22 == 0 ) {
V_35 = - V_122 ;
F_104 ( V_19 -> V_23 , V_35 ) ;
return V_35 ;
}
} else {
V_22 = 1 ;
if ( V_19 -> V_123 . V_124 == V_48 ||
F_101 ( V_31 ) < V_45 )
V_80 = V_125 ;
else
V_80 = 0 ;
}
V_120 = F_105 ( V_31 ) ;
F_72 ( V_120 == V_48 &&
! ( V_80 & V_125 ) ) ;
if ( V_22 > 1 ) {
if ( ( V_120 == V_19 -> V_123 . V_124 ||
V_19 -> V_123 . V_124 == V_48 ) &&
! ( V_80 & V_125 ) ) {
V_35 = F_49 ( V_30 , V_19 , V_31 , 1 , 1 ) ;
F_72 ( V_35 ) ;
if ( V_19 -> V_123 . V_124 ==
V_48 ) {
V_35 = F_106 ( V_30 , V_19 , V_31 , 0 , 1 ) ;
F_72 ( V_35 ) ;
V_35 = F_49 ( V_30 , V_19 , V_34 , 1 , 1 ) ;
F_72 ( V_35 ) ;
}
V_121 |= V_125 ;
} else {
if ( V_19 -> V_123 . V_124 ==
V_48 )
V_35 = F_49 ( V_30 , V_19 , V_34 , 1 , 1 ) ;
else
V_35 = F_49 ( V_30 , V_19 , V_34 , 0 , 1 ) ;
F_72 ( V_35 ) ;
}
if ( V_121 != 0 ) {
int V_36 = F_33 ( V_31 ) ;
V_35 = F_107 ( V_30 , V_19 ,
V_31 -> V_44 ,
V_31 -> V_43 ,
V_121 , V_36 , 0 ) ;
if ( V_35 )
return V_35 ;
}
} else {
if ( V_80 & V_125 ) {
if ( V_19 -> V_123 . V_124 ==
V_48 )
V_35 = F_49 ( V_30 , V_19 , V_34 , 1 , 1 ) ;
else
V_35 = F_49 ( V_30 , V_19 , V_34 , 0 , 1 ) ;
F_72 ( V_35 ) ;
V_35 = F_106 ( V_30 , V_19 , V_31 , 1 , 1 ) ;
F_72 ( V_35 ) ;
}
F_108 ( V_30 , V_19 , V_31 ) ;
* V_119 = 1 ;
}
return 0 ;
}
static T_1 int F_109 ( struct V_29 * V_30 ,
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
F_110 ( V_31 ) ;
F_32 ( F_27 ( V_39 , & V_19 -> V_26 ) &&
V_30 -> V_40 != V_19 -> V_23 -> V_41 -> V_40 ) ;
F_32 ( F_27 ( V_39 , & V_19 -> V_26 ) &&
V_30 -> V_40 != V_19 -> V_42 ) ;
V_36 = F_33 ( V_31 ) ;
if ( V_36 == 0 )
F_34 ( V_31 , & V_38 , 0 ) ;
else
F_35 ( V_31 , & V_38 , 0 ) ;
if ( V_19 -> V_123 . V_124 == V_48 ) {
if ( V_71 )
V_130 = V_71 -> V_44 ;
else
V_130 = 0 ;
} else
V_130 = 0 ;
V_34 = F_36 ( V_30 , V_19 , V_31 -> V_43 , V_130 ,
V_19 -> V_123 . V_124 , & V_38 ,
V_36 , V_127 , V_128 ) ;
if ( F_37 ( V_34 ) )
return F_38 ( V_34 ) ;
F_39 ( V_34 , V_31 , 0 , 0 , V_34 -> V_43 ) ;
F_40 ( V_34 , V_34 -> V_44 ) ;
F_41 ( V_34 , V_30 -> V_40 ) ;
F_42 ( V_34 , V_45 ) ;
F_43 ( V_34 , V_46 |
V_47 ) ;
if ( V_19 -> V_123 . V_124 == V_48 )
F_44 ( V_34 , V_47 ) ;
else
F_45 ( V_34 , V_19 -> V_123 . V_124 ) ;
F_46 ( V_34 , V_19 -> V_23 -> V_49 , F_47 () ,
V_50 ) ;
V_35 = F_102 ( V_30 , V_19 , V_31 , V_34 , & V_119 ) ;
if ( V_35 ) {
F_111 ( V_30 , V_19 , V_35 ) ;
return V_35 ;
}
if ( F_27 ( V_39 , & V_19 -> V_26 ) ) {
V_35 = F_112 ( V_30 , V_19 , V_31 , V_34 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_31 == V_19 -> V_21 ) {
F_32 ( V_71 && V_71 != V_31 ) ;
if ( V_19 -> V_123 . V_124 == V_48 ||
F_101 ( V_31 ) < V_45 )
V_130 = V_31 -> V_44 ;
else
V_130 = 0 ;
F_113 ( V_34 ) ;
F_96 ( V_19 , V_34 , 1 ) ;
F_114 ( V_19 -> V_21 , V_34 ) ;
F_115 ( V_30 , V_19 , V_31 , V_130 ,
V_119 ) ;
F_12 ( V_31 ) ;
F_25 ( V_19 ) ;
} else {
if ( V_19 -> V_123 . V_124 == V_48 )
V_130 = V_71 -> V_44 ;
else
V_130 = 0 ;
F_32 ( V_30 -> V_40 != F_48 ( V_71 ) ) ;
F_83 ( V_19 -> V_23 , V_71 , V_126 ,
V_114 , V_4 ) ;
F_116 ( V_71 , V_126 ,
V_34 -> V_44 ) ;
F_117 ( V_71 , V_126 ,
V_30 -> V_40 ) ;
F_50 ( V_71 ) ;
if ( V_119 ) {
V_35 = F_95 ( V_19 -> V_23 , V_31 ) ;
if ( V_35 ) {
F_111 ( V_30 , V_19 , V_35 ) ;
return V_35 ;
}
}
F_115 ( V_30 , V_19 , V_31 , V_130 ,
V_119 ) ;
}
if ( V_129 )
F_21 ( V_31 ) ;
F_118 ( V_31 ) ;
F_50 ( V_34 ) ;
* V_32 = V_34 ;
return 0 ;
}
static struct V_65 *
F_119 ( struct V_51 * V_23 ,
struct V_14 * V_131 , T_2 V_132 )
{
struct V_65 * V_66 ;
struct V_65 * V_105 = NULL ;
T_2 V_133 = V_131 -> V_44 ;
int V_134 = 0 ;
if ( ! V_132 )
return NULL ;
while ( 1 ) {
V_66 = F_90 ( V_23 , V_133 ,
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
F_120 ( struct V_51 * V_23 , struct V_14 * V_20 ,
T_2 V_132 , struct V_65 * V_135 )
{
T_4 V_136 ;
struct V_62 * V_63 ;
struct V_65 * V_66 = V_135 ;
unsigned long V_137 ;
unsigned long V_138 ;
unsigned long V_139 = sizeof( struct V_140 ) ;
V_136 = F_88 ( V_20 ) ;
F_51 ( V_23 ) ;
while ( V_66 && V_66 -> V_57 >= V_132 ) {
switch ( V_66 -> V_79 ) {
case V_101 :
F_72 ( V_66 -> V_77 < V_136 ) ;
case V_95 :
case V_112 :
F_121 ( V_20 , & V_66 -> V_83 , V_66 -> V_77 ) ;
F_116 ( V_20 , V_66 -> V_77 , V_66 -> V_84 ) ;
F_117 ( V_20 , V_66 -> V_77 ,
V_66 -> V_85 ) ;
V_136 ++ ;
break;
case V_114 :
F_72 ( V_66 -> V_77 >= V_136 ) ;
F_121 ( V_20 , & V_66 -> V_83 , V_66 -> V_77 ) ;
F_116 ( V_20 , V_66 -> V_77 , V_66 -> V_84 ) ;
F_117 ( V_20 , V_66 -> V_77 ,
V_66 -> V_85 ) ;
break;
case V_82 :
V_136 -- ;
break;
case V_94 :
V_137 = F_122 ( V_66 -> V_77 ) ;
V_138 = F_122 ( V_66 -> V_93 . V_87 ) ;
F_123 ( V_20 , V_137 , V_138 ,
V_66 -> V_93 . V_89 * V_139 ) ;
break;
case V_103 :
break;
}
V_63 = F_67 ( & V_66 -> V_21 ) ;
if ( ! V_63 )
break;
V_66 = F_68 ( V_63 , struct V_65 , V_21 ) ;
if ( V_66 -> V_73 != V_135 -> V_73 )
break;
}
F_53 ( V_23 ) ;
F_124 ( V_20 , V_136 ) ;
}
static struct V_14 *
F_125 ( struct V_51 * V_23 , struct V_1 * V_2 ,
struct V_14 * V_20 , T_2 V_132 )
{
struct V_14 * V_141 ;
struct V_65 * V_66 ;
if ( ! V_132 )
return V_20 ;
if ( F_33 ( V_20 ) == 0 )
return V_20 ;
V_66 = F_91 ( V_23 , V_20 -> V_44 , V_132 ) ;
if ( ! V_66 )
return V_20 ;
F_3 ( V_2 ) ;
F_4 ( V_20 , V_10 ) ;
if ( V_66 -> V_79 == V_101 ) {
F_72 ( V_66 -> V_77 != 0 ) ;
V_141 = F_126 ( V_20 -> V_44 ,
V_23 -> V_142 -> V_143 ) ;
if ( ! V_141 ) {
F_127 ( V_20 ) ;
F_12 ( V_20 ) ;
return NULL ;
}
F_40 ( V_141 , V_20 -> V_44 ) ;
F_42 ( V_141 ,
F_101 ( V_20 ) ) ;
F_45 ( V_141 , F_105 ( V_20 ) ) ;
F_128 ( V_141 , F_33 ( V_20 ) ) ;
} else {
V_141 = F_129 ( V_20 ) ;
if ( ! V_141 ) {
F_127 ( V_20 ) ;
F_12 ( V_20 ) ;
return NULL ;
}
}
F_5 ( V_2 , NULL , V_10 ) ;
F_127 ( V_20 ) ;
F_12 ( V_20 ) ;
F_113 ( V_141 ) ;
F_23 ( V_141 ) ;
F_120 ( V_23 , V_141 , V_132 , V_66 ) ;
F_32 ( F_88 ( V_141 ) >
F_130 ( V_23 -> V_142 ) ) ;
return V_141 ;
}
static inline struct V_14 *
F_131 ( struct V_18 * V_19 , T_2 V_132 )
{
struct V_65 * V_66 ;
struct V_14 * V_20 = NULL ;
struct V_14 * V_131 ;
struct V_14 * V_144 ;
struct V_145 * V_98 = NULL ;
T_2 V_146 = 0 ;
T_2 V_102 ;
T_4 V_147 ;
V_131 = F_22 ( V_19 ) ;
V_66 = F_119 ( V_19 -> V_23 , V_131 , V_132 ) ;
if ( ! V_66 )
return V_131 ;
if ( V_66 -> V_79 == V_103 ) {
V_98 = & V_66 -> V_98 ;
V_146 = V_66 -> V_85 ;
V_102 = V_98 -> V_102 ;
} else {
V_102 = V_131 -> V_44 ;
}
V_66 = F_91 ( V_19 -> V_23 , V_102 , V_132 ) ;
if ( V_98 && V_66 && V_66 -> V_79 != V_101 ) {
F_24 ( V_131 ) ;
F_12 ( V_131 ) ;
V_147 = F_132 ( V_19 , V_98 -> V_36 ) ;
V_144 = F_133 ( V_19 , V_102 , V_147 , 0 ) ;
if ( F_32 ( ! V_144 || ! F_134 ( V_144 ) ) ) {
F_12 ( V_144 ) ;
F_135 ( V_19 -> V_23 ,
L_1 , V_102 ) ;
} else {
V_20 = F_129 ( V_144 ) ;
F_12 ( V_144 ) ;
}
} else if ( V_98 ) {
F_24 ( V_131 ) ;
F_12 ( V_131 ) ;
V_20 = F_126 ( V_102 , V_19 -> V_143 ) ;
} else {
F_4 ( V_131 , V_10 ) ;
V_20 = F_129 ( V_131 ) ;
F_127 ( V_131 ) ;
F_12 ( V_131 ) ;
}
if ( ! V_20 )
return NULL ;
F_113 ( V_20 ) ;
F_23 ( V_20 ) ;
if ( V_98 ) {
F_40 ( V_20 , V_20 -> V_44 ) ;
F_42 ( V_20 , V_45 ) ;
F_45 ( V_20 , F_105 ( V_131 ) ) ;
F_128 ( V_20 , V_98 -> V_36 ) ;
F_41 ( V_20 , V_146 ) ;
}
if ( V_66 )
F_120 ( V_19 -> V_23 , V_20 , V_132 , V_66 ) ;
else
F_32 ( F_33 ( V_20 ) != 0 ) ;
F_32 ( F_88 ( V_20 ) > F_130 ( V_19 ) ) ;
return V_20 ;
}
int F_136 ( struct V_18 * V_19 , T_2 V_132 )
{
struct V_65 * V_66 ;
int V_36 ;
struct V_14 * V_131 = F_13 ( V_19 ) ;
V_66 = F_119 ( V_19 -> V_23 , V_131 , V_132 ) ;
if ( V_66 && V_66 -> V_79 == V_103 ) {
V_36 = V_66 -> V_98 . V_36 ;
} else {
V_36 = F_33 ( V_131 ) ;
}
F_12 ( V_131 ) ;
return V_36 ;
}
static inline int F_137 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_14 * V_31 )
{
#ifdef F_138
if ( F_139 ( F_27 ( V_148 , & V_19 -> V_26 ) ) )
return 0 ;
#endif
F_140 () ;
if ( F_48 ( V_31 ) == V_30 -> V_40 &&
! F_99 ( V_31 , V_46 ) &&
! ( V_19 -> V_123 . V_124 != V_48 &&
F_99 ( V_31 , V_47 ) ) &&
! F_27 ( V_149 , & V_19 -> V_26 ) )
return 0 ;
return 1 ;
}
T_1 int F_141 ( struct V_29 * V_30 ,
struct V_18 * V_19 , struct V_14 * V_31 ,
struct V_14 * V_71 , int V_126 ,
struct V_14 * * V_32 )
{
T_2 V_127 ;
int V_35 ;
if ( V_30 -> V_150 != V_19 -> V_23 -> V_41 )
F_142 ( 1 , V_151 L_2 ,
V_30 -> V_40 ,
V_19 -> V_23 -> V_41 -> V_40 ) ;
if ( V_30 -> V_40 != V_19 -> V_23 -> V_85 )
F_142 ( 1 , V_151 L_2 ,
V_30 -> V_40 , V_19 -> V_23 -> V_85 ) ;
if ( ! F_137 ( V_30 , V_19 , V_31 ) ) {
* V_32 = V_31 ;
return 0 ;
}
V_127 = V_31 -> V_44 & ~ ( ( T_2 ) ( 1024 * 1024 * 1024 ) - 1 ) ;
if ( V_71 )
F_143 ( V_71 ) ;
F_143 ( V_31 ) ;
V_35 = F_109 ( V_30 , V_19 , V_31 , V_71 ,
V_126 , V_32 , V_127 , 0 ) ;
F_144 ( V_19 , V_31 , * V_32 ) ;
return V_35 ;
}
static int F_145 ( T_2 V_152 , T_2 V_153 , T_4 V_147 )
{
if ( V_152 < V_153 && V_153 - ( V_152 + V_147 ) < 32768 )
return 1 ;
if ( V_152 > V_153 && V_152 - ( V_153 + V_147 ) < 32768 )
return 1 ;
return 0 ;
}
static int F_146 ( struct V_37 * V_154 , struct V_155 * V_156 )
{
struct V_155 V_157 ;
F_147 ( & V_157 , V_154 ) ;
return F_148 ( & V_157 , V_156 ) ;
}
int F_148 ( struct V_155 * V_157 , struct V_155 * V_156 )
{
if ( V_157 -> V_124 > V_156 -> V_124 )
return 1 ;
if ( V_157 -> V_124 < V_156 -> V_124 )
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
int F_149 ( struct V_29 * V_30 ,
struct V_18 * V_19 , struct V_14 * V_71 ,
int V_159 , T_2 * V_160 ,
struct V_155 * V_161 )
{
struct V_14 * V_72 ;
T_2 V_152 ;
T_2 V_162 ;
T_2 V_127 = * V_160 ;
T_2 V_163 = 0 ;
T_2 V_153 ;
T_4 V_164 ;
int V_165 ;
int V_6 ;
int V_166 = 0 ;
int V_167 ;
int V_168 ;
T_4 V_147 ;
int V_169 = 0 ;
struct V_37 V_38 ;
V_167 = F_33 ( V_71 ) ;
F_32 ( V_30 -> V_150 != V_19 -> V_23 -> V_41 ) ;
F_32 ( V_30 -> V_40 != V_19 -> V_23 -> V_85 ) ;
V_164 = F_88 ( V_71 ) ;
V_147 = F_132 ( V_19 , V_167 - 1 ) ;
V_165 = V_164 ;
if ( V_164 == 1 )
return 0 ;
F_143 ( V_71 ) ;
for ( V_6 = V_159 ; V_6 < V_165 ; V_6 ++ ) {
int V_170 = 1 ;
F_35 ( V_71 , & V_38 , V_6 ) ;
if ( ! V_169 && F_146 ( & V_38 , V_161 ) < 0 )
continue;
V_169 = 1 ;
V_152 = F_80 ( V_71 , V_6 ) ;
V_162 = F_81 ( V_71 , V_6 ) ;
if ( V_163 == 0 )
V_163 = V_152 ;
if ( V_6 > 0 ) {
V_153 = F_80 ( V_71 , V_6 - 1 ) ;
V_170 = F_145 ( V_152 , V_153 , V_147 ) ;
}
if ( ! V_170 && V_6 < V_165 - 2 ) {
V_153 = F_80 ( V_71 , V_6 + 1 ) ;
V_170 = F_145 ( V_152 , V_153 , V_147 ) ;
}
if ( V_170 ) {
V_163 = V_152 ;
continue;
}
V_72 = F_150 ( V_19 , V_152 , V_147 ) ;
if ( V_72 )
V_168 = F_151 ( V_72 , V_162 , 0 ) ;
else
V_168 = 0 ;
if ( ! V_72 || ! V_168 ) {
if ( ! V_72 ) {
V_72 = F_133 ( V_19 , V_152 ,
V_147 , V_162 ) ;
if ( ! V_72 || ! F_134 ( V_72 ) ) {
F_12 ( V_72 ) ;
return - V_171 ;
}
} else if ( ! V_168 ) {
V_166 = F_152 ( V_72 , V_162 ) ;
if ( V_166 ) {
F_12 ( V_72 ) ;
return V_166 ;
}
}
}
if ( V_127 == 0 )
V_127 = V_163 ;
F_20 ( V_72 ) ;
F_143 ( V_72 ) ;
V_166 = F_109 ( V_30 , V_19 , V_72 , V_71 , V_6 ,
& V_72 , V_127 ,
F_153 ( 16 * V_147 ,
( V_165 - V_6 ) * V_147 ) ) ;
if ( V_166 ) {
F_21 ( V_72 ) ;
F_12 ( V_72 ) ;
break;
}
V_127 = V_72 -> V_44 ;
V_163 = V_72 -> V_44 ;
* V_160 = V_127 ;
F_21 ( V_72 ) ;
F_12 ( V_72 ) ;
}
return V_166 ;
}
static inline unsigned int F_154 ( struct V_18 * V_19 ,
struct V_14 * V_172 )
{
T_4 V_173 = F_88 ( V_172 ) ;
if ( V_173 == 0 )
return F_155 ( V_19 ) ;
return F_156 ( V_172 , V_173 - 1 ) ;
}
static T_1 int F_157 ( struct V_14 * V_20 ,
unsigned long V_5 ,
int V_174 , struct V_155 * V_83 ,
int V_175 , int * V_77 )
{
int V_176 = 0 ;
int V_177 = V_175 ;
int V_178 ;
int V_35 ;
struct V_37 * V_179 = NULL ;
struct V_37 V_180 ;
unsigned long V_158 ;
char * V_181 = NULL ;
unsigned long V_182 = 0 ;
unsigned long V_183 = 0 ;
int V_166 ;
while ( V_176 < V_177 ) {
V_178 = ( V_176 + V_177 ) / 2 ;
V_158 = V_5 + V_178 * V_174 ;
if ( ! V_181 || V_158 < V_182 ||
( V_158 + sizeof( struct V_37 ) ) >
V_182 + V_183 ) {
V_166 = F_158 ( V_20 , V_158 ,
sizeof( struct V_37 ) ,
& V_181 , & V_182 , & V_183 ) ;
if ( ! V_166 ) {
V_179 = (struct V_37 * ) ( V_181 + V_158 -
V_182 ) ;
} else {
F_159 ( V_20 , & V_180 ,
V_158 , sizeof( V_180 ) ) ;
V_179 = & V_180 ;
}
} else {
V_179 = (struct V_37 * ) ( V_181 + V_158 -
V_182 ) ;
}
V_35 = F_146 ( V_179 , V_83 ) ;
if ( V_35 < 0 )
V_176 = V_178 + 1 ;
else if ( V_35 > 0 )
V_177 = V_178 ;
else {
* V_77 = V_178 ;
return 0 ;
}
}
* V_77 = V_176 ;
return 1 ;
}
static int F_160 ( struct V_14 * V_20 , struct V_155 * V_83 ,
int V_36 , int * V_77 )
{
if ( V_36 == 0 )
return F_157 ( V_20 ,
F_161 ( struct V_184 , V_185 ) ,
sizeof( struct V_186 ) ,
V_83 , F_88 ( V_20 ) ,
V_77 ) ;
else
return F_157 ( V_20 ,
F_161 ( struct V_187 , V_188 ) ,
sizeof( struct V_140 ) ,
V_83 , F_88 ( V_20 ) ,
V_77 ) ;
}
int F_162 ( struct V_14 * V_20 , struct V_155 * V_83 ,
int V_36 , int * V_77 )
{
return F_160 ( V_20 , V_83 , V_36 , V_77 ) ;
}
static void F_163 ( struct V_18 * V_19 , T_4 V_189 )
{
F_26 ( & V_19 -> V_190 ) ;
F_164 ( & V_19 -> V_118 ,
F_165 ( & V_19 -> V_118 ) + V_189 ) ;
F_30 ( & V_19 -> V_190 ) ;
}
static void F_166 ( struct V_18 * V_19 , T_4 V_189 )
{
F_26 ( & V_19 -> V_190 ) ;
F_164 ( & V_19 -> V_118 ,
F_165 ( & V_19 -> V_118 ) - V_189 ) ;
F_30 ( & V_19 -> V_190 ) ;
}
T_1 int F_167 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_36 )
{
struct V_14 * V_191 = NULL ;
struct V_14 * V_178 ;
struct V_14 * V_192 = NULL ;
struct V_14 * V_71 = NULL ;
int V_35 = 0 ;
int V_193 ;
int V_194 ;
int V_195 = V_2 -> V_17 [ V_36 ] ;
T_2 V_196 ;
if ( V_36 == 0 )
return 0 ;
V_178 = V_2 -> V_8 [ V_36 ] ;
F_32 ( V_2 -> V_9 [ V_36 ] != V_12 &&
V_2 -> V_9 [ V_36 ] != V_13 ) ;
F_32 ( F_48 ( V_178 ) != V_30 -> V_40 ) ;
V_196 = F_80 ( V_178 , V_195 ) ;
if ( V_36 < V_7 - 1 ) {
V_71 = V_2 -> V_8 [ V_36 + 1 ] ;
V_194 = V_2 -> V_17 [ V_36 + 1 ] ;
}
if ( ! V_71 ) {
struct V_14 * V_197 ;
if ( F_88 ( V_178 ) != 1 )
return 0 ;
V_197 = F_168 ( V_19 , V_178 , 0 ) ;
if ( ! V_197 ) {
V_35 = - V_122 ;
F_104 ( V_19 -> V_23 , V_35 ) ;
goto V_198;
}
F_20 ( V_197 ) ;
F_143 ( V_197 ) ;
V_35 = F_141 ( V_30 , V_19 , V_197 , V_178 , 0 , & V_197 ) ;
if ( V_35 ) {
F_21 ( V_197 ) ;
F_12 ( V_197 ) ;
goto V_198;
}
F_96 ( V_19 , V_197 , 1 ) ;
F_114 ( V_19 -> V_21 , V_197 ) ;
F_25 ( V_19 ) ;
F_21 ( V_197 ) ;
V_2 -> V_9 [ V_36 ] = 0 ;
V_2 -> V_8 [ V_36 ] = NULL ;
F_108 ( V_30 , V_19 , V_178 ) ;
F_21 ( V_178 ) ;
F_12 ( V_178 ) ;
F_166 ( V_19 , V_178 -> V_43 ) ;
F_115 ( V_30 , V_19 , V_178 , 0 , 1 ) ;
F_118 ( V_178 ) ;
return 0 ;
}
if ( F_88 ( V_178 ) >
F_130 ( V_19 ) / 4 )
return 0 ;
V_192 = F_168 ( V_19 , V_71 , V_194 - 1 ) ;
if ( V_192 ) {
F_20 ( V_192 ) ;
F_143 ( V_192 ) ;
V_193 = F_141 ( V_30 , V_19 , V_192 ,
V_71 , V_194 - 1 , & V_192 ) ;
if ( V_193 ) {
V_35 = V_193 ;
goto V_198;
}
}
V_191 = F_168 ( V_19 , V_71 , V_194 + 1 ) ;
if ( V_191 ) {
F_20 ( V_191 ) ;
F_143 ( V_191 ) ;
V_193 = F_141 ( V_30 , V_19 , V_191 ,
V_71 , V_194 + 1 , & V_191 ) ;
if ( V_193 ) {
V_35 = V_193 ;
goto V_198;
}
}
if ( V_192 ) {
V_195 += F_88 ( V_192 ) ;
V_193 = F_169 ( V_30 , V_19 , V_192 , V_178 , 1 ) ;
if ( V_193 < 0 )
V_35 = V_193 ;
}
if ( V_191 ) {
V_193 = F_169 ( V_30 , V_19 , V_178 , V_191 , 1 ) ;
if ( V_193 < 0 && V_193 != - V_199 )
V_35 = V_193 ;
if ( F_88 ( V_191 ) == 0 ) {
F_108 ( V_30 , V_19 , V_191 ) ;
F_21 ( V_191 ) ;
F_170 ( V_19 , V_2 , V_36 + 1 , V_194 + 1 ) ;
F_166 ( V_19 , V_191 -> V_43 ) ;
F_115 ( V_30 , V_19 , V_191 , 0 , 1 ) ;
F_118 ( V_191 ) ;
V_191 = NULL ;
} else {
struct V_37 V_200 ;
F_35 ( V_191 , & V_200 , 0 ) ;
F_94 ( V_19 -> V_23 , V_71 ,
V_194 + 1 , 0 ) ;
F_121 ( V_71 , & V_200 , V_194 + 1 ) ;
F_50 ( V_71 ) ;
}
}
if ( F_88 ( V_178 ) == 1 ) {
if ( ! V_192 ) {
V_35 = - V_122 ;
F_104 ( V_19 -> V_23 , V_35 ) ;
goto V_198;
}
V_193 = F_171 ( V_30 , V_19 , V_178 , V_192 ) ;
if ( V_193 < 0 ) {
V_35 = V_193 ;
goto V_198;
}
if ( V_193 == 1 ) {
V_193 = F_169 ( V_30 , V_19 , V_192 , V_178 , 1 ) ;
if ( V_193 < 0 )
V_35 = V_193 ;
}
F_72 ( V_193 == 1 ) ;
}
if ( F_88 ( V_178 ) == 0 ) {
F_108 ( V_30 , V_19 , V_178 ) ;
F_21 ( V_178 ) ;
F_170 ( V_19 , V_2 , V_36 + 1 , V_194 ) ;
F_166 ( V_19 , V_178 -> V_43 ) ;
F_115 ( V_30 , V_19 , V_178 , 0 , 1 ) ;
F_118 ( V_178 ) ;
V_178 = NULL ;
} else {
struct V_37 V_201 ;
F_35 ( V_178 , & V_201 , 0 ) ;
F_94 ( V_19 -> V_23 , V_71 ,
V_194 , 0 ) ;
F_121 ( V_71 , & V_201 , V_194 ) ;
F_50 ( V_71 ) ;
}
if ( V_192 ) {
if ( F_88 ( V_192 ) > V_195 ) {
F_113 ( V_192 ) ;
V_2 -> V_8 [ V_36 ] = V_192 ;
V_2 -> V_17 [ V_36 + 1 ] -= 1 ;
V_2 -> V_17 [ V_36 ] = V_195 ;
if ( V_178 ) {
F_21 ( V_178 ) ;
F_12 ( V_178 ) ;
}
} else {
V_195 -= F_88 ( V_192 ) ;
V_2 -> V_17 [ V_36 ] = V_195 ;
}
}
if ( V_196 !=
F_80 ( V_2 -> V_8 [ V_36 ] , V_2 -> V_17 [ V_36 ] ) )
F_172 () ;
V_198:
if ( V_191 ) {
F_21 ( V_191 ) ;
F_12 ( V_191 ) ;
}
if ( V_192 ) {
if ( V_2 -> V_8 [ V_36 ] != V_192 )
F_21 ( V_192 ) ;
F_12 ( V_192 ) ;
}
return V_35 ;
}
static T_1 int F_173 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_36 )
{
struct V_14 * V_191 = NULL ;
struct V_14 * V_178 ;
struct V_14 * V_192 = NULL ;
struct V_14 * V_71 = NULL ;
int V_35 = 0 ;
int V_193 ;
int V_194 ;
int V_195 = V_2 -> V_17 [ V_36 ] ;
if ( V_36 == 0 )
return 1 ;
V_178 = V_2 -> V_8 [ V_36 ] ;
F_32 ( F_48 ( V_178 ) != V_30 -> V_40 ) ;
if ( V_36 < V_7 - 1 ) {
V_71 = V_2 -> V_8 [ V_36 + 1 ] ;
V_194 = V_2 -> V_17 [ V_36 + 1 ] ;
}
if ( ! V_71 )
return 1 ;
V_192 = F_168 ( V_19 , V_71 , V_194 - 1 ) ;
if ( V_192 ) {
T_4 V_202 ;
F_20 ( V_192 ) ;
F_143 ( V_192 ) ;
V_202 = F_88 ( V_192 ) ;
if ( V_202 >= F_130 ( V_19 ) - 1 ) {
V_193 = 1 ;
} else {
V_35 = F_141 ( V_30 , V_19 , V_192 , V_71 ,
V_194 - 1 , & V_192 ) ;
if ( V_35 )
V_193 = 1 ;
else {
V_193 = F_169 ( V_30 , V_19 ,
V_192 , V_178 , 0 ) ;
}
}
if ( V_193 < 0 )
V_35 = V_193 ;
if ( V_193 == 0 ) {
struct V_37 V_38 ;
V_195 += V_202 ;
F_35 ( V_178 , & V_38 , 0 ) ;
F_94 ( V_19 -> V_23 , V_71 ,
V_194 , 0 ) ;
F_121 ( V_71 , & V_38 , V_194 ) ;
F_50 ( V_71 ) ;
if ( F_88 ( V_192 ) > V_195 ) {
V_2 -> V_8 [ V_36 ] = V_192 ;
V_2 -> V_17 [ V_36 + 1 ] -= 1 ;
V_2 -> V_17 [ V_36 ] = V_195 ;
F_21 ( V_178 ) ;
F_12 ( V_178 ) ;
} else {
V_195 -=
F_88 ( V_192 ) ;
V_2 -> V_17 [ V_36 ] = V_195 ;
F_21 ( V_192 ) ;
F_12 ( V_192 ) ;
}
return 0 ;
}
F_21 ( V_192 ) ;
F_12 ( V_192 ) ;
}
V_191 = F_168 ( V_19 , V_71 , V_194 + 1 ) ;
if ( V_191 ) {
T_4 V_203 ;
F_20 ( V_191 ) ;
F_143 ( V_191 ) ;
V_203 = F_88 ( V_191 ) ;
if ( V_203 >= F_130 ( V_19 ) - 1 ) {
V_193 = 1 ;
} else {
V_35 = F_141 ( V_30 , V_19 , V_191 ,
V_71 , V_194 + 1 ,
& V_191 ) ;
if ( V_35 )
V_193 = 1 ;
else {
V_193 = F_171 ( V_30 , V_19 ,
V_191 , V_178 ) ;
}
}
if ( V_193 < 0 )
V_35 = V_193 ;
if ( V_193 == 0 ) {
struct V_37 V_38 ;
F_35 ( V_191 , & V_38 , 0 ) ;
F_94 ( V_19 -> V_23 , V_71 ,
V_194 + 1 , 0 ) ;
F_121 ( V_71 , & V_38 , V_194 + 1 ) ;
F_50 ( V_71 ) ;
if ( F_88 ( V_178 ) <= V_195 ) {
V_2 -> V_8 [ V_36 ] = V_191 ;
V_2 -> V_17 [ V_36 + 1 ] += 1 ;
V_2 -> V_17 [ V_36 ] = V_195 -
F_88 ( V_178 ) ;
F_21 ( V_178 ) ;
F_12 ( V_178 ) ;
} else {
F_21 ( V_191 ) ;
F_12 ( V_191 ) ;
}
return 0 ;
}
F_21 ( V_191 ) ;
F_12 ( V_191 ) ;
}
return 1 ;
}
static void F_174 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int V_36 , int V_77 , T_2 V_124 )
{
struct V_14 * V_21 ;
struct V_37 V_38 ;
T_4 V_96 ;
T_2 V_204 ;
T_2 V_205 ;
T_2 V_206 = 0 ;
T_2 V_162 ;
int V_207 = V_2 -> V_208 ;
struct V_14 * V_20 ;
T_4 V_173 ;
T_4 V_147 ;
T_4 V_209 = 0 ;
if ( V_36 != 1 )
return;
if ( ! V_2 -> V_8 [ V_36 ] )
return;
V_21 = V_2 -> V_8 [ V_36 ] ;
V_204 = F_80 ( V_21 , V_77 ) ;
V_147 = F_132 ( V_19 , V_36 - 1 ) ;
V_20 = F_150 ( V_19 , V_204 , V_147 ) ;
if ( V_20 ) {
F_12 ( V_20 ) ;
return;
}
V_205 = V_204 ;
V_96 = F_88 ( V_21 ) ;
V_173 = V_77 ;
while ( 1 ) {
if ( V_207 < 0 ) {
if ( V_173 == 0 )
break;
V_173 -- ;
} else if ( V_207 > 0 ) {
V_173 ++ ;
if ( V_173 >= V_96 )
break;
}
if ( V_2 -> V_208 < 0 && V_124 ) {
F_35 ( V_21 , & V_38 , V_173 ) ;
if ( F_175 ( & V_38 ) != V_124 )
break;
}
V_204 = F_80 ( V_21 , V_173 ) ;
if ( ( V_204 <= V_205 && V_205 - V_204 <= 65536 ) ||
( V_204 > V_205 && V_204 - V_205 <= 65536 ) ) {
V_162 = F_81 ( V_21 , V_173 ) ;
F_176 ( V_19 , V_204 , V_147 , V_162 ) ;
V_206 += V_147 ;
}
V_209 ++ ;
if ( ( V_206 > 65536 || V_209 > 32 ) )
break;
}
}
static T_1 void F_177 ( struct V_18 * V_19 ,
struct V_1 * V_2 , int V_36 )
{
int V_77 ;
int V_96 ;
struct V_14 * V_71 ;
struct V_14 * V_20 ;
T_2 V_162 ;
T_2 V_210 = 0 ;
T_2 V_211 = 0 ;
int V_147 ;
V_71 = V_2 -> V_8 [ V_36 + 1 ] ;
if ( ! V_71 )
return;
V_96 = F_88 ( V_71 ) ;
V_77 = V_2 -> V_17 [ V_36 + 1 ] ;
V_147 = F_132 ( V_19 , V_36 ) ;
if ( V_77 > 0 ) {
V_210 = F_80 ( V_71 , V_77 - 1 ) ;
V_162 = F_81 ( V_71 , V_77 - 1 ) ;
V_20 = F_150 ( V_19 , V_210 , V_147 ) ;
if ( V_20 && F_151 ( V_20 , V_162 , 1 ) != 0 )
V_210 = 0 ;
F_12 ( V_20 ) ;
}
if ( V_77 + 1 < V_96 ) {
V_211 = F_80 ( V_71 , V_77 + 1 ) ;
V_162 = F_81 ( V_71 , V_77 + 1 ) ;
V_20 = F_150 ( V_19 , V_211 , V_147 ) ;
if ( V_20 && F_151 ( V_20 , V_162 , 1 ) != 0 )
V_211 = 0 ;
F_12 ( V_20 ) ;
}
if ( V_210 )
F_176 ( V_19 , V_210 , V_147 , 0 ) ;
if ( V_211 )
F_176 ( V_19 , V_211 , V_147 , 0 ) ;
}
static T_1 void F_178 ( struct V_1 * V_2 , int V_36 ,
int V_212 , int V_213 ,
int * V_214 )
{
int V_6 ;
int V_215 = V_36 ;
int V_216 = 0 ;
struct V_14 * V_217 ;
for ( V_6 = V_36 ; V_6 < V_7 ; V_6 ++ ) {
if ( ! V_2 -> V_8 [ V_6 ] )
break;
if ( ! V_2 -> V_9 [ V_6 ] )
break;
if ( ! V_216 && V_2 -> V_17 [ V_6 ] == 0 ) {
V_215 = V_6 + 1 ;
continue;
}
if ( ! V_216 && V_2 -> V_218 ) {
T_4 V_96 ;
V_217 = V_2 -> V_8 [ V_6 ] ;
V_96 = F_88 ( V_217 ) ;
if ( V_96 < 1 || V_2 -> V_17 [ V_6 ] >= V_96 - 1 ) {
V_215 = V_6 + 1 ;
continue;
}
}
if ( V_215 < V_6 && V_6 >= V_212 )
V_216 = 1 ;
V_217 = V_2 -> V_8 [ V_6 ] ;
if ( V_6 >= V_212 && V_6 > V_215 && V_2 -> V_9 [ V_6 ] ) {
F_11 ( V_217 , V_2 -> V_9 [ V_6 ] ) ;
V_2 -> V_9 [ V_6 ] = 0 ;
if ( V_214 &&
V_6 > V_213 &&
V_6 <= * V_214 ) {
* V_214 = V_6 - 1 ;
}
}
}
}
T_1 void F_179 ( struct V_1 * V_2 , int V_36 )
{
int V_6 ;
if ( V_2 -> V_218 )
return;
for ( V_6 = V_36 ; V_6 < V_7 ; V_6 ++ ) {
if ( ! V_2 -> V_8 [ V_6 ] )
continue;
if ( ! V_2 -> V_9 [ V_6 ] )
continue;
F_11 ( V_2 -> V_8 [ V_6 ] , V_2 -> V_9 [ V_6 ] ) ;
V_2 -> V_9 [ V_6 ] = 0 ;
}
}
static int
F_180 ( struct V_29 * V_30 ,
struct V_18 * V_19 , struct V_1 * V_5 ,
struct V_14 * * V_219 , int V_36 , int V_77 ,
struct V_155 * V_83 , T_2 V_132 )
{
T_2 V_152 ;
T_2 V_162 ;
T_4 V_147 ;
struct V_14 * V_220 = * V_219 ;
struct V_14 * V_179 ;
int V_35 ;
V_152 = F_80 ( V_220 , V_77 ) ;
V_162 = F_81 ( V_220 , V_77 ) ;
V_147 = F_132 ( V_19 , V_36 - 1 ) ;
V_179 = F_150 ( V_19 , V_152 , V_147 ) ;
if ( V_179 ) {
if ( F_151 ( V_179 , V_162 , 1 ) > 0 ) {
* V_219 = V_179 ;
return 0 ;
}
F_3 ( V_5 ) ;
V_35 = F_152 ( V_179 , V_162 ) ;
if ( ! V_35 ) {
* V_219 = V_179 ;
return 0 ;
}
F_12 ( V_179 ) ;
F_9 ( V_5 ) ;
return - V_171 ;
}
F_179 ( V_5 , V_36 + 1 ) ;
F_3 ( V_5 ) ;
F_12 ( V_179 ) ;
if ( V_5 -> V_208 )
F_174 ( V_19 , V_5 , V_36 , V_77 , V_83 -> V_124 ) ;
F_9 ( V_5 ) ;
V_35 = - V_221 ;
V_179 = F_133 ( V_19 , V_152 , V_147 , 0 ) ;
if ( V_179 ) {
if ( ! F_151 ( V_179 , 0 , 0 ) )
V_35 = - V_171 ;
F_12 ( V_179 ) ;
}
return V_35 ;
}
static int
F_181 ( struct V_29 * V_30 ,
struct V_18 * V_19 , struct V_1 * V_5 ,
struct V_14 * V_220 , int V_36 , int V_222 ,
int * V_214 )
{
int V_35 ;
if ( ( V_5 -> V_223 || V_222 > 0 ) && F_88 ( V_220 ) >=
F_130 ( V_19 ) - 3 ) {
int V_224 ;
if ( * V_214 < V_36 + 1 ) {
* V_214 = V_36 + 1 ;
F_9 ( V_5 ) ;
goto V_225;
}
F_3 ( V_5 ) ;
F_177 ( V_19 , V_5 , V_36 ) ;
V_224 = F_182 ( V_30 , V_19 , V_5 , V_36 ) ;
F_5 ( V_5 , NULL , 0 ) ;
F_72 ( V_224 > 0 ) ;
if ( V_224 ) {
V_35 = V_224 ;
goto V_226;
}
V_220 = V_5 -> V_8 [ V_36 ] ;
} else if ( V_222 < 0 && F_88 ( V_220 ) <
F_130 ( V_19 ) / 2 ) {
int V_224 ;
if ( * V_214 < V_36 + 1 ) {
* V_214 = V_36 + 1 ;
F_9 ( V_5 ) ;
goto V_225;
}
F_3 ( V_5 ) ;
F_177 ( V_19 , V_5 , V_36 ) ;
V_224 = F_167 ( V_30 , V_19 , V_5 , V_36 ) ;
F_5 ( V_5 , NULL , 0 ) ;
if ( V_224 ) {
V_35 = V_224 ;
goto V_226;
}
V_220 = V_5 -> V_8 [ V_36 ] ;
if ( ! V_220 ) {
F_9 ( V_5 ) ;
goto V_225;
}
F_72 ( F_88 ( V_220 ) == 1 ) ;
}
return 0 ;
V_225:
V_35 = - V_221 ;
V_226:
return V_35 ;
}
static void F_183 ( struct V_14 * V_220 ,
struct V_155 * V_83 ,
int V_36 )
{
#ifdef F_184
struct V_37 V_38 ;
F_185 ( & V_38 , V_83 ) ;
if ( V_36 == 0 )
ASSERT ( ! F_186 ( V_220 , & V_38 ,
F_161 ( struct V_184 , V_185 [ 0 ] . V_83 ) ,
sizeof( V_38 ) ) ) ;
else
ASSERT ( ! F_186 ( V_220 , & V_38 ,
F_161 ( struct V_187 , V_188 [ 0 ] . V_83 ) ,
sizeof( V_38 ) ) ) ;
#endif
}
static int F_187 ( struct V_14 * V_220 , struct V_155 * V_83 ,
int V_36 , int * V_227 , int * V_77 )
{
if ( * V_227 != 0 ) {
* V_227 = F_160 ( V_220 , V_83 , V_36 , V_77 ) ;
return * V_227 ;
}
F_183 ( V_220 , V_83 , V_36 ) ;
* V_77 = 0 ;
return 0 ;
}
int F_188 ( struct V_18 * V_228 , struct V_1 * V_229 ,
T_2 V_230 , T_2 V_231 , T_5 V_232 ,
struct V_155 * V_233 )
{
int V_35 ;
struct V_155 V_83 ;
struct V_14 * V_20 ;
struct V_1 * V_2 ;
V_83 . type = V_232 ;
V_83 . V_124 = V_230 ;
V_83 . V_158 = V_231 ;
if ( V_229 == NULL ) {
V_2 = F_1 () ;
if ( ! V_2 )
return - V_86 ;
} else
V_2 = V_229 ;
V_35 = F_189 ( NULL , V_228 , & V_83 , V_2 , 0 , 0 ) ;
if ( ( V_35 < 0 ) || ( V_233 == NULL ) ) {
if ( V_2 != V_229 )
F_8 ( V_2 ) ;
return V_35 ;
}
V_20 = V_2 -> V_8 [ 0 ] ;
if ( V_35 && V_2 -> V_17 [ 0 ] >= F_88 ( V_20 ) ) {
V_35 = F_190 ( V_228 , V_2 ) ;
if ( V_35 )
return V_35 ;
V_20 = V_2 -> V_8 [ 0 ] ;
}
F_191 ( V_20 , V_233 , V_2 -> V_17 [ 0 ] ) ;
if ( V_233 -> type != V_83 . type ||
V_233 -> V_124 != V_83 . V_124 )
return 1 ;
return 0 ;
}
int F_189 ( struct V_29 * V_30 , struct V_18
* V_19 , struct V_155 * V_83 , struct V_1 * V_5 , int
V_222 , int V_34 )
{
struct V_14 * V_220 ;
int V_77 ;
int V_35 ;
int V_166 ;
int V_36 ;
int V_212 = 1 ;
int V_234 ;
int V_214 = 0 ;
T_5 V_235 = 0 ;
int V_213 ;
int V_227 ;
V_235 = V_5 -> V_235 ;
F_32 ( V_235 && V_222 > 0 ) ;
F_32 ( V_5 -> V_8 [ 0 ] != NULL ) ;
F_72 ( ! V_34 && V_222 ) ;
if ( V_222 < 0 ) {
V_212 = 2 ;
V_214 = 2 ;
} else if ( V_222 > 0 ) {
V_214 = 1 ;
}
if ( ! V_34 )
V_214 = - 1 ;
if ( V_34 && ( V_5 -> V_218 || V_5 -> V_235 ) )
V_214 = V_7 ;
V_213 = V_214 ;
V_225:
V_227 = - 1 ;
V_234 = V_10 ;
V_36 = 0 ;
if ( V_5 -> V_236 ) {
if ( V_5 -> V_237 )
F_192 ( & V_19 -> V_23 -> V_238 ) ;
V_220 = V_19 -> V_117 ;
F_113 ( V_220 ) ;
V_36 = F_33 ( V_220 ) ;
if ( V_5 -> V_237 )
F_193 ( & V_19 -> V_23 -> V_238 ) ;
if ( ! V_5 -> V_239 )
F_23 ( V_220 ) ;
} else {
if ( V_5 -> V_239 ) {
V_220 = F_13 ( V_19 ) ;
V_36 = F_33 ( V_220 ) ;
} else {
V_220 = F_22 ( V_19 ) ;
V_36 = F_33 ( V_220 ) ;
if ( V_36 <= V_214 ) {
F_24 ( V_220 ) ;
F_12 ( V_220 ) ;
V_220 = F_19 ( V_19 ) ;
V_234 = V_12 ;
V_36 = F_33 ( V_220 ) ;
}
}
}
V_5 -> V_8 [ V_36 ] = V_220 ;
if ( ! V_5 -> V_239 )
V_5 -> V_9 [ V_36 ] = V_234 ;
while ( V_220 ) {
V_36 = F_33 ( V_220 ) ;
if ( V_34 ) {
if ( ! F_137 ( V_30 , V_19 , V_220 ) )
goto V_240;
F_3 ( V_5 ) ;
if ( V_36 > V_214 ||
( V_36 + 1 > V_214 &&
V_36 + 1 < V_7 &&
V_5 -> V_8 [ V_36 + 1 ] ) ) {
V_214 = V_36 + 1 ;
F_9 ( V_5 ) ;
goto V_225;
}
V_166 = F_141 ( V_30 , V_19 , V_220 ,
V_5 -> V_8 [ V_36 + 1 ] ,
V_5 -> V_17 [ V_36 + 1 ] , & V_220 ) ;
if ( V_166 ) {
V_35 = V_166 ;
goto V_226;
}
}
V_240:
V_5 -> V_8 [ V_36 ] = V_220 ;
F_5 ( V_5 , NULL , 0 ) ;
if ( ! V_222 && ! V_5 -> V_218 ) {
int V_241 = V_36 + 1 ;
if ( V_241 < V_7 && V_5 -> V_9 [ V_241 ] ) {
F_11 ( V_5 -> V_8 [ V_241 ] , V_5 -> V_9 [ V_241 ] ) ;
V_5 -> V_9 [ V_241 ] = 0 ;
}
}
V_35 = F_187 ( V_220 , V_83 , V_36 , & V_227 , & V_77 ) ;
if ( V_36 != 0 ) {
int V_242 = 0 ;
if ( V_35 && V_77 > 0 ) {
V_242 = 1 ;
V_77 -= 1 ;
}
V_5 -> V_17 [ V_36 ] = V_77 ;
V_166 = F_181 ( V_30 , V_19 , V_5 , V_220 , V_36 ,
V_222 , & V_214 ) ;
if ( V_166 == - V_221 )
goto V_225;
if ( V_166 ) {
V_35 = V_166 ;
goto V_226;
}
V_220 = V_5 -> V_8 [ V_36 ] ;
V_77 = V_5 -> V_17 [ V_36 ] ;
if ( V_77 == 0 && V_222 &&
V_214 < V_36 + 1 ) {
V_214 = V_36 + 1 ;
F_9 ( V_5 ) ;
goto V_225;
}
F_178 ( V_5 , V_36 , V_212 ,
V_213 , & V_214 ) ;
if ( V_36 == V_235 ) {
if ( V_242 )
V_5 -> V_17 [ V_36 ] ++ ;
goto V_226;
}
V_166 = F_180 ( V_30 , V_19 , V_5 ,
& V_220 , V_36 , V_77 , V_83 , 0 ) ;
if ( V_166 == - V_221 )
goto V_225;
if ( V_166 ) {
V_35 = V_166 ;
goto V_226;
}
if ( ! V_5 -> V_239 ) {
V_36 = F_33 ( V_220 ) ;
if ( V_36 <= V_214 ) {
V_166 = F_194 ( V_220 ) ;
if ( ! V_166 ) {
F_3 ( V_5 ) ;
F_20 ( V_220 ) ;
F_5 ( V_5 , V_220 ,
V_12 ) ;
}
V_5 -> V_9 [ V_36 ] = V_12 ;
} else {
V_166 = F_195 ( V_220 ) ;
if ( ! V_166 ) {
F_3 ( V_5 ) ;
F_23 ( V_220 ) ;
F_5 ( V_5 , V_220 ,
V_10 ) ;
}
V_5 -> V_9 [ V_36 ] = V_10 ;
}
V_5 -> V_8 [ V_36 ] = V_220 ;
}
} else {
V_5 -> V_17 [ V_36 ] = V_77 ;
if ( V_222 > 0 &&
F_196 ( V_19 , V_220 ) < V_222 ) {
if ( V_214 < 1 ) {
V_214 = 1 ;
F_9 ( V_5 ) ;
goto V_225;
}
F_3 ( V_5 ) ;
V_166 = F_197 ( V_30 , V_19 , V_83 ,
V_5 , V_222 , V_35 == 0 ) ;
F_5 ( V_5 , NULL , 0 ) ;
F_72 ( V_166 > 0 ) ;
if ( V_166 ) {
V_35 = V_166 ;
goto V_226;
}
}
if ( ! V_5 -> V_223 )
F_178 ( V_5 , V_36 , V_212 ,
V_213 , & V_214 ) ;
goto V_226;
}
}
V_35 = 1 ;
V_226:
if ( ! V_5 -> V_243 )
F_3 ( V_5 ) ;
if ( V_35 < 0 )
F_9 ( V_5 ) ;
return V_35 ;
}
int F_198 ( struct V_18 * V_19 , struct V_155 * V_83 ,
struct V_1 * V_5 , T_2 V_132 )
{
struct V_14 * V_220 ;
int V_77 ;
int V_35 ;
int V_166 ;
int V_36 ;
int V_212 = 1 ;
T_5 V_235 = 0 ;
int V_227 = - 1 ;
V_235 = V_5 -> V_235 ;
F_32 ( V_5 -> V_8 [ 0 ] != NULL ) ;
if ( V_5 -> V_236 ) {
F_72 ( V_132 ) ;
return F_189 ( NULL , V_19 , V_83 , V_5 , 0 , 0 ) ;
}
V_225:
V_220 = F_131 ( V_19 , V_132 ) ;
V_36 = F_33 ( V_220 ) ;
V_5 -> V_9 [ V_36 ] = V_10 ;
while ( V_220 ) {
V_36 = F_33 ( V_220 ) ;
V_5 -> V_8 [ V_36 ] = V_220 ;
F_5 ( V_5 , NULL , 0 ) ;
F_179 ( V_5 , V_36 + 1 ) ;
V_227 = - 1 ;
V_35 = F_187 ( V_220 , V_83 , V_36 , & V_227 , & V_77 ) ;
if ( V_36 != 0 ) {
int V_242 = 0 ;
if ( V_35 && V_77 > 0 ) {
V_242 = 1 ;
V_77 -= 1 ;
}
V_5 -> V_17 [ V_36 ] = V_77 ;
F_178 ( V_5 , V_36 , V_212 , 0 , NULL ) ;
if ( V_36 == V_235 ) {
if ( V_242 )
V_5 -> V_17 [ V_36 ] ++ ;
goto V_226;
}
V_166 = F_180 ( NULL , V_19 , V_5 , & V_220 , V_36 ,
V_77 , V_83 , V_132 ) ;
if ( V_166 == - V_221 )
goto V_225;
if ( V_166 ) {
V_35 = V_166 ;
goto V_226;
}
V_36 = F_33 ( V_220 ) ;
V_166 = F_195 ( V_220 ) ;
if ( ! V_166 ) {
F_3 ( V_5 ) ;
F_23 ( V_220 ) ;
F_5 ( V_5 , V_220 ,
V_10 ) ;
}
V_220 = F_125 ( V_19 -> V_23 , V_5 , V_220 , V_132 ) ;
if ( ! V_220 ) {
V_35 = - V_86 ;
goto V_226;
}
V_5 -> V_9 [ V_36 ] = V_10 ;
V_5 -> V_8 [ V_36 ] = V_220 ;
} else {
V_5 -> V_17 [ V_36 ] = V_77 ;
F_178 ( V_5 , V_36 , V_212 , 0 , NULL ) ;
goto V_226;
}
}
V_35 = 1 ;
V_226:
if ( ! V_5 -> V_243 )
F_3 ( V_5 ) ;
if ( V_35 < 0 )
F_9 ( V_5 ) ;
return V_35 ;
}
int F_199 ( struct V_18 * V_19 ,
struct V_155 * V_83 , struct V_1 * V_5 ,
int V_244 , int V_245 )
{
int V_35 ;
struct V_14 * V_172 ;
V_225:
V_35 = F_189 ( NULL , V_19 , V_83 , V_5 , 0 , 0 ) ;
if ( V_35 <= 0 )
return V_35 ;
V_172 = V_5 -> V_8 [ 0 ] ;
if ( V_244 ) {
if ( V_5 -> V_17 [ 0 ] >= F_88 ( V_172 ) ) {
V_35 = F_190 ( V_19 , V_5 ) ;
if ( V_35 <= 0 )
return V_35 ;
if ( ! V_245 )
return 1 ;
V_245 = 0 ;
V_244 = 0 ;
F_9 ( V_5 ) ;
goto V_225;
}
} else {
if ( V_5 -> V_17 [ 0 ] == 0 ) {
V_35 = F_200 ( V_19 , V_5 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( ! V_35 ) {
V_172 = V_5 -> V_8 [ 0 ] ;
if ( V_5 -> V_17 [ 0 ] == F_88 ( V_172 ) )
V_5 -> V_17 [ 0 ] -- ;
return 0 ;
}
if ( ! V_245 )
return 1 ;
V_245 = 0 ;
V_244 = 1 ;
F_9 ( V_5 ) ;
goto V_225;
} else {
-- V_5 -> V_17 [ 0 ] ;
}
}
return 0 ;
}
static void F_201 ( struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_37 * V_83 , int V_36 )
{
int V_6 ;
struct V_14 * V_217 ;
for ( V_6 = V_36 ; V_6 < V_7 ; V_6 ++ ) {
int V_246 = V_2 -> V_17 [ V_6 ] ;
if ( ! V_2 -> V_8 [ V_6 ] )
break;
V_217 = V_2 -> V_8 [ V_6 ] ;
F_94 ( V_19 -> V_23 , V_217 , V_246 , 1 ) ;
F_121 ( V_217 , V_83 , V_246 ) ;
F_50 ( V_2 -> V_8 [ V_6 ] ) ;
if ( V_246 != 0 )
break;
}
}
void F_202 ( struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_155 * V_247 )
{
struct V_37 V_38 ;
struct V_14 * V_20 ;
int V_77 ;
V_20 = V_2 -> V_8 [ 0 ] ;
V_77 = V_2 -> V_17 [ 0 ] ;
if ( V_77 > 0 ) {
F_34 ( V_20 , & V_38 , V_77 - 1 ) ;
F_72 ( F_146 ( & V_38 , V_247 ) >= 0 ) ;
}
if ( V_77 < F_88 ( V_20 ) - 1 ) {
F_34 ( V_20 , & V_38 , V_77 + 1 ) ;
F_72 ( F_146 ( & V_38 , V_247 ) <= 0 ) ;
}
F_185 ( & V_38 , V_247 ) ;
F_203 ( V_20 , & V_38 , V_77 ) ;
F_50 ( V_20 ) ;
if ( V_77 == 0 )
F_201 ( V_19 , V_2 , & V_38 , 1 ) ;
}
static int F_169 ( struct V_29 * V_30 ,
struct V_18 * V_19 , struct V_14 * V_106 ,
struct V_14 * V_107 , int V_248 )
{
int V_249 = 0 ;
int V_250 ;
int V_251 ;
int V_35 = 0 ;
V_250 = F_88 ( V_107 ) ;
V_251 = F_88 ( V_106 ) ;
V_249 = F_130 ( V_19 ) - V_251 ;
F_32 ( F_48 ( V_107 ) != V_30 -> V_40 ) ;
F_32 ( F_48 ( V_106 ) != V_30 -> V_40 ) ;
if ( ! V_248 && V_250 <= 8 )
return 1 ;
if ( V_249 <= 0 )
return 1 ;
if ( V_248 ) {
V_249 = F_153 ( V_250 , V_249 ) ;
if ( V_249 < V_250 ) {
if ( V_250 - V_249 < 8 ) {
if ( V_249 <= 8 )
return 1 ;
V_249 -= 8 ;
}
}
} else
V_249 = F_153 ( V_250 - 8 , V_249 ) ;
V_35 = F_92 ( V_19 -> V_23 , V_106 , V_107 , V_251 , 0 ,
V_249 ) ;
if ( V_35 ) {
F_111 ( V_30 , V_19 , V_35 ) ;
return V_35 ;
}
F_39 ( V_106 , V_107 ,
F_122 ( V_251 ) ,
F_122 ( 0 ) ,
V_249 * sizeof( struct V_140 ) ) ;
if ( V_249 < V_250 ) {
F_123 ( V_107 , F_122 ( 0 ) ,
F_122 ( V_249 ) ,
( V_250 - V_249 ) *
sizeof( struct V_140 ) ) ;
}
F_124 ( V_107 , V_250 - V_249 ) ;
F_124 ( V_106 , V_251 + V_249 ) ;
F_50 ( V_107 ) ;
F_50 ( V_106 ) ;
return V_35 ;
}
static int F_171 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_14 * V_106 ,
struct V_14 * V_107 )
{
int V_249 = 0 ;
int V_252 ;
int V_250 ;
int V_251 ;
int V_35 = 0 ;
F_32 ( F_48 ( V_107 ) != V_30 -> V_40 ) ;
F_32 ( F_48 ( V_106 ) != V_30 -> V_40 ) ;
V_250 = F_88 ( V_107 ) ;
V_251 = F_88 ( V_106 ) ;
V_249 = F_130 ( V_19 ) - V_251 ;
if ( V_249 <= 0 )
return 1 ;
if ( V_250 < 4 )
return 1 ;
V_252 = V_250 / 2 + 1 ;
if ( V_252 >= V_250 )
return 1 ;
if ( V_252 < V_249 )
V_249 = V_252 ;
F_93 ( V_19 -> V_23 , V_106 , V_249 , 0 , V_251 ) ;
F_123 ( V_106 , F_122 ( V_249 ) ,
F_122 ( 0 ) ,
( V_251 ) *
sizeof( struct V_140 ) ) ;
V_35 = F_92 ( V_19 -> V_23 , V_106 , V_107 , 0 ,
V_250 - V_249 , V_249 ) ;
if ( V_35 ) {
F_111 ( V_30 , V_19 , V_35 ) ;
return V_35 ;
}
F_39 ( V_106 , V_107 ,
F_122 ( 0 ) ,
F_122 ( V_250 - V_249 ) ,
V_249 * sizeof( struct V_140 ) ) ;
F_124 ( V_107 , V_250 - V_249 ) ;
F_124 ( V_106 , V_251 + V_249 ) ;
F_50 ( V_107 ) ;
F_50 ( V_106 ) ;
return V_35 ;
}
static T_1 int F_204 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_36 )
{
T_2 V_253 ;
struct V_14 * V_254 ;
struct V_14 * V_255 ;
struct V_14 * V_144 ;
struct V_37 V_256 ;
F_72 ( V_2 -> V_8 [ V_36 ] ) ;
F_72 ( V_2 -> V_8 [ V_36 - 1 ] != V_19 -> V_21 ) ;
V_254 = V_2 -> V_8 [ V_36 - 1 ] ;
if ( V_36 == 1 )
F_34 ( V_254 , & V_256 , 0 ) ;
else
F_35 ( V_254 , & V_256 , 0 ) ;
V_255 = F_36 ( V_30 , V_19 , V_19 -> V_143 , 0 ,
V_19 -> V_123 . V_124 , & V_256 ,
V_36 , V_19 -> V_21 -> V_44 , 0 ) ;
if ( F_37 ( V_255 ) )
return F_38 ( V_255 ) ;
F_163 ( V_19 , V_19 -> V_143 ) ;
F_205 ( V_255 , 0 , 0 , sizeof( struct V_257 ) ) ;
F_124 ( V_255 , 1 ) ;
F_128 ( V_255 , V_36 ) ;
F_40 ( V_255 , V_255 -> V_44 ) ;
F_41 ( V_255 , V_30 -> V_40 ) ;
F_42 ( V_255 , V_45 ) ;
F_45 ( V_255 , V_19 -> V_123 . V_124 ) ;
F_46 ( V_255 , V_19 -> V_23 -> V_49 , F_47 () ,
V_50 ) ;
F_46 ( V_255 , V_19 -> V_23 -> V_258 ,
F_206 ( V_255 ) , V_259 ) ;
F_121 ( V_255 , & V_256 , 0 ) ;
F_116 ( V_255 , 0 , V_254 -> V_44 ) ;
V_253 = F_48 ( V_254 ) ;
F_32 ( V_253 != V_30 -> V_40 ) ;
F_117 ( V_255 , 0 , V_253 ) ;
F_50 ( V_255 ) ;
V_144 = V_19 -> V_21 ;
F_96 ( V_19 , V_255 , 0 ) ;
F_114 ( V_19 -> V_21 , V_255 ) ;
F_12 ( V_144 ) ;
F_25 ( V_19 ) ;
F_113 ( V_255 ) ;
V_2 -> V_8 [ V_36 ] = V_255 ;
V_2 -> V_9 [ V_36 ] = V_12 ;
V_2 -> V_17 [ V_36 ] = 0 ;
return 0 ;
}
static void F_207 ( struct V_29 * V_30 ,
struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_37 * V_83 , T_2 V_260 ,
int V_77 , int V_36 )
{
struct V_14 * V_254 ;
int V_96 ;
int V_35 ;
F_72 ( ! V_2 -> V_8 [ V_36 ] ) ;
F_110 ( V_2 -> V_8 [ V_36 ] ) ;
V_254 = V_2 -> V_8 [ V_36 ] ;
V_96 = F_88 ( V_254 ) ;
F_72 ( V_77 > V_96 ) ;
F_72 ( V_96 == F_130 ( V_19 ) ) ;
if ( V_77 != V_96 ) {
if ( V_36 )
F_93 ( V_19 -> V_23 , V_254 , V_77 + 1 ,
V_77 , V_96 - V_77 ) ;
F_123 ( V_254 ,
F_122 ( V_77 + 1 ) ,
F_122 ( V_77 ) ,
( V_96 - V_77 ) * sizeof( struct V_140 ) ) ;
}
if ( V_36 ) {
V_35 = F_83 ( V_19 -> V_23 , V_254 , V_77 ,
V_82 , V_4 ) ;
F_72 ( V_35 < 0 ) ;
}
F_121 ( V_254 , V_83 , V_77 ) ;
F_116 ( V_254 , V_77 , V_260 ) ;
F_32 ( V_30 -> V_40 == 0 ) ;
F_117 ( V_254 , V_77 , V_30 -> V_40 ) ;
F_124 ( V_254 , V_96 + 1 ) ;
F_50 ( V_254 ) ;
}
static T_1 int F_182 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_36 )
{
struct V_14 * V_255 ;
struct V_14 * V_261 ;
struct V_37 V_38 ;
int V_178 ;
int V_35 ;
T_4 V_262 ;
V_255 = V_2 -> V_8 [ V_36 ] ;
F_32 ( F_48 ( V_255 ) != V_30 -> V_40 ) ;
if ( V_255 == V_19 -> V_21 ) {
V_35 = F_204 ( V_30 , V_19 , V_2 , V_36 + 1 ) ;
if ( V_35 )
return V_35 ;
} else {
V_35 = F_173 ( V_30 , V_19 , V_2 , V_36 ) ;
V_255 = V_2 -> V_8 [ V_36 ] ;
if ( ! V_35 && F_88 ( V_255 ) <
F_130 ( V_19 ) - 3 )
return 0 ;
if ( V_35 < 0 )
return V_35 ;
}
V_262 = F_88 ( V_255 ) ;
V_178 = ( V_262 + 1 ) / 2 ;
F_35 ( V_255 , & V_38 , V_178 ) ;
V_261 = F_36 ( V_30 , V_19 , V_19 -> V_143 , 0 ,
V_19 -> V_123 . V_124 ,
& V_38 , V_36 , V_255 -> V_44 , 0 ) ;
if ( F_37 ( V_261 ) )
return F_38 ( V_261 ) ;
F_163 ( V_19 , V_19 -> V_143 ) ;
F_205 ( V_261 , 0 , 0 , sizeof( struct V_257 ) ) ;
F_128 ( V_261 , F_33 ( V_255 ) ) ;
F_40 ( V_261 , V_261 -> V_44 ) ;
F_41 ( V_261 , V_30 -> V_40 ) ;
F_42 ( V_261 , V_45 ) ;
F_45 ( V_261 , V_19 -> V_123 . V_124 ) ;
F_46 ( V_261 , V_19 -> V_23 -> V_49 ,
F_47 () , V_50 ) ;
F_46 ( V_261 , V_19 -> V_23 -> V_258 ,
F_206 ( V_261 ) ,
V_259 ) ;
V_35 = F_92 ( V_19 -> V_23 , V_261 , V_255 , 0 ,
V_178 , V_262 - V_178 ) ;
if ( V_35 ) {
F_111 ( V_30 , V_19 , V_35 ) ;
return V_35 ;
}
F_39 ( V_261 , V_255 ,
F_122 ( 0 ) ,
F_122 ( V_178 ) ,
( V_262 - V_178 ) * sizeof( struct V_140 ) ) ;
F_124 ( V_261 , V_262 - V_178 ) ;
F_124 ( V_255 , V_178 ) ;
V_35 = 0 ;
F_50 ( V_255 ) ;
F_50 ( V_261 ) ;
F_207 ( V_30 , V_19 , V_2 , & V_38 , V_261 -> V_44 ,
V_2 -> V_17 [ V_36 + 1 ] + 1 , V_36 + 1 ) ;
if ( V_2 -> V_17 [ V_36 ] >= V_178 ) {
V_2 -> V_17 [ V_36 ] -= V_178 ;
F_21 ( V_255 ) ;
F_12 ( V_255 ) ;
V_2 -> V_8 [ V_36 ] = V_261 ;
V_2 -> V_17 [ V_36 + 1 ] += 1 ;
} else {
F_21 ( V_261 ) ;
F_12 ( V_261 ) ;
}
return V_35 ;
}
static int F_208 ( struct V_14 * V_263 , int V_44 , int V_173 )
{
struct V_186 * V_264 ;
struct V_186 * V_265 ;
struct V_266 V_267 ;
int V_268 ;
int V_96 = F_88 ( V_263 ) ;
int V_269 = F_153 ( V_96 , V_44 + V_173 ) - 1 ;
if ( ! V_173 )
return 0 ;
F_209 ( & V_267 ) ;
V_264 = F_210 ( V_44 ) ;
V_265 = F_210 ( V_269 ) ;
V_268 = F_211 ( V_263 , V_264 , & V_267 ) +
F_212 ( V_263 , V_264 , & V_267 ) ;
V_268 = V_268 - F_211 ( V_263 , V_265 , & V_267 ) ;
V_268 += sizeof( struct V_186 ) * V_173 ;
F_32 ( V_268 < 0 ) ;
return V_268 ;
}
T_1 int F_196 ( struct V_18 * V_19 ,
struct V_14 * V_172 )
{
int V_96 = F_88 ( V_172 ) ;
int V_35 ;
V_35 = F_155 ( V_19 ) - F_208 ( V_172 , 0 , V_96 ) ;
if ( V_35 < 0 ) {
F_213 ( V_19 -> V_23 ,
L_3 ,
V_35 , ( unsigned long ) F_155 ( V_19 ) ,
F_208 ( V_172 , 0 , V_96 ) , V_96 ) ;
}
return V_35 ;
}
static T_1 int F_214 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
int V_270 , int V_248 ,
struct V_14 * V_191 ,
int V_271 , T_4 V_272 ,
T_4 V_273 )
{
struct V_14 * V_192 = V_2 -> V_8 [ 0 ] ;
struct V_14 * V_274 = V_2 -> V_8 [ 1 ] ;
struct V_266 V_267 ;
struct V_37 V_38 ;
int V_77 ;
T_4 V_6 ;
int V_275 = 0 ;
int V_249 = 0 ;
struct V_186 * V_276 ;
T_4 V_173 ;
T_4 V_277 ;
T_4 V_278 ;
T_4 V_279 ;
F_209 ( & V_267 ) ;
if ( V_248 )
V_173 = 0 ;
else
V_173 = F_215 ( T_4 , 1 , V_273 ) ;
if ( V_2 -> V_17 [ 0 ] >= V_272 )
V_275 += V_270 ;
V_77 = V_2 -> V_17 [ 1 ] ;
V_6 = V_272 - 1 ;
while ( V_6 >= V_173 ) {
V_276 = F_210 ( V_6 ) ;
if ( ! V_248 && V_249 > 0 ) {
if ( V_2 -> V_17 [ 0 ] > V_6 )
break;
if ( V_2 -> V_17 [ 0 ] == V_6 ) {
int V_280 = F_196 ( V_19 , V_192 ) ;
if ( V_280 + V_275 * 2 > V_271 )
break;
}
}
if ( V_2 -> V_17 [ 0 ] == V_6 )
V_275 += V_270 ;
V_279 = F_216 ( V_192 , V_276 ) ;
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
F_32 ( ! V_248 && V_249 == V_272 ) ;
V_277 = F_88 ( V_191 ) ;
V_275 = F_217 ( V_192 , V_272 - V_249 ) ;
V_275 -= F_154 ( V_19 , V_192 ) ;
V_278 = F_154 ( V_19 , V_191 ) ;
F_123 ( V_191 ,
F_218 ( V_191 ) + V_278 - V_275 ,
F_218 ( V_191 ) + V_278 ,
F_155 ( V_19 ) - V_278 ) ;
F_39 ( V_191 , V_192 , F_218 ( V_191 ) +
F_155 ( V_19 ) - V_275 ,
F_218 ( V_192 ) + F_154 ( V_19 , V_192 ) ,
V_275 ) ;
F_123 ( V_191 , F_219 ( V_249 ) ,
F_219 ( 0 ) ,
V_277 * sizeof( struct V_186 ) ) ;
F_39 ( V_191 , V_192 , F_219 ( 0 ) ,
F_219 ( V_272 - V_249 ) ,
V_249 * sizeof( struct V_186 ) ) ;
V_277 += V_249 ;
F_124 ( V_191 , V_277 ) ;
V_275 = F_155 ( V_19 ) ;
for ( V_6 = 0 ; V_6 < V_277 ; V_6 ++ ) {
V_276 = F_210 ( V_6 ) ;
V_275 -= F_212 ( V_191 , V_276 , & V_267 ) ;
F_220 ( V_191 , V_276 , V_275 , & V_267 ) ;
}
V_272 -= V_249 ;
F_124 ( V_192 , V_272 ) ;
if ( V_272 )
F_50 ( V_192 ) ;
else
F_108 ( V_30 , V_19 , V_192 ) ;
F_50 ( V_191 ) ;
F_34 ( V_191 , & V_38 , 0 ) ;
F_121 ( V_274 , & V_38 , V_77 + 1 ) ;
F_50 ( V_274 ) ;
if ( V_2 -> V_17 [ 0 ] >= V_272 ) {
V_2 -> V_17 [ 0 ] -= V_272 ;
if ( F_88 ( V_2 -> V_8 [ 0 ] ) == 0 )
F_108 ( V_30 , V_19 , V_2 -> V_8 [ 0 ] ) ;
F_21 ( V_2 -> V_8 [ 0 ] ) ;
F_12 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_191 ;
V_2 -> V_17 [ 1 ] += 1 ;
} else {
F_21 ( V_191 ) ;
F_12 ( V_191 ) ;
}
return 0 ;
V_281:
F_21 ( V_191 ) ;
F_12 ( V_191 ) ;
return 1 ;
}
static int F_221 ( struct V_29 * V_30 , struct V_18
* V_19 , struct V_1 * V_2 ,
int V_282 , int V_270 ,
int V_248 , T_4 V_273 )
{
struct V_14 * V_192 = V_2 -> V_8 [ 0 ] ;
struct V_14 * V_191 ;
struct V_14 * V_274 ;
int V_77 ;
int V_271 ;
T_4 V_272 ;
int V_35 ;
if ( ! V_2 -> V_8 [ 1 ] )
return 1 ;
V_77 = V_2 -> V_17 [ 1 ] ;
V_274 = V_2 -> V_8 [ 1 ] ;
if ( V_77 >= F_88 ( V_274 ) - 1 )
return 1 ;
F_110 ( V_2 -> V_8 [ 1 ] ) ;
V_191 = F_168 ( V_19 , V_274 , V_77 + 1 ) ;
if ( V_191 == NULL )
return 1 ;
F_20 ( V_191 ) ;
F_143 ( V_191 ) ;
V_271 = F_196 ( V_19 , V_191 ) ;
if ( V_271 < V_270 )
goto V_281;
V_35 = F_141 ( V_30 , V_19 , V_191 , V_274 ,
V_77 + 1 , & V_191 ) ;
if ( V_35 )
goto V_281;
V_271 = F_196 ( V_19 , V_191 ) ;
if ( V_271 < V_270 )
goto V_281;
V_272 = F_88 ( V_192 ) ;
if ( V_272 == 0 )
goto V_281;
if ( V_2 -> V_17 [ 0 ] == V_272 && ! V_248 ) {
F_21 ( V_192 ) ;
F_12 ( V_192 ) ;
V_2 -> V_8 [ 0 ] = V_191 ;
V_2 -> V_17 [ 0 ] = 0 ;
V_2 -> V_17 [ 1 ] ++ ;
return 0 ;
}
return F_214 ( V_30 , V_19 , V_2 , V_282 , V_248 ,
V_191 , V_271 , V_272 , V_273 ) ;
V_281:
F_21 ( V_191 ) ;
F_12 ( V_191 ) ;
return 1 ;
}
static T_1 int F_222 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_270 ,
int V_248 , struct V_14 * V_192 ,
int V_271 , T_4 V_277 ,
T_4 V_283 )
{
struct V_37 V_38 ;
struct V_14 * V_191 = V_2 -> V_8 [ 0 ] ;
int V_6 ;
int V_275 = 0 ;
int V_249 = 0 ;
struct V_186 * V_276 ;
T_4 V_284 ;
T_4 V_173 ;
int V_35 = 0 ;
T_4 V_279 ;
T_4 V_285 ;
struct V_266 V_267 ;
F_209 ( & V_267 ) ;
if ( V_248 )
V_173 = F_153 ( V_277 , V_283 ) ;
else
V_173 = F_153 ( V_277 - 1 , V_283 ) ;
for ( V_6 = 0 ; V_6 < V_173 ; V_6 ++ ) {
V_276 = F_210 ( V_6 ) ;
if ( ! V_248 && V_249 > 0 ) {
if ( V_2 -> V_17 [ 0 ] < V_6 )
break;
if ( V_2 -> V_17 [ 0 ] == V_6 ) {
int V_280 = F_196 ( V_19 , V_191 ) ;
if ( V_280 + V_275 * 2 > V_271 )
break;
}
}
if ( V_2 -> V_17 [ 0 ] == V_6 )
V_275 += V_270 ;
V_279 = F_216 ( V_191 , V_276 ) ;
if ( V_279 + sizeof( * V_276 ) + V_275 > V_271 )
break;
V_249 ++ ;
V_275 += V_279 + sizeof( * V_276 ) ;
}
if ( V_249 == 0 ) {
V_35 = 1 ;
goto V_286;
}
F_32 ( ! V_248 && V_249 == F_88 ( V_191 ) ) ;
F_39 ( V_192 , V_191 ,
F_219 ( F_88 ( V_192 ) ) ,
F_219 ( 0 ) ,
V_249 * sizeof( struct V_186 ) ) ;
V_275 = F_155 ( V_19 ) -
F_156 ( V_191 , V_249 - 1 ) ;
F_39 ( V_192 , V_191 , F_218 ( V_192 ) +
F_154 ( V_19 , V_192 ) - V_275 ,
F_218 ( V_191 ) +
F_156 ( V_191 , V_249 - 1 ) ,
V_275 ) ;
V_284 = F_88 ( V_192 ) ;
F_72 ( V_284 <= 0 ) ;
V_285 = F_156 ( V_192 , V_284 - 1 ) ;
for ( V_6 = V_284 ; V_6 < V_284 + V_249 ; V_6 ++ ) {
T_4 V_231 ;
V_276 = F_210 ( V_6 ) ;
V_231 = F_211 ( V_192 , V_276 , & V_267 ) ;
F_220 ( V_192 , V_276 ,
V_231 - ( F_155 ( V_19 ) - V_285 ) ,
& V_267 ) ;
}
F_124 ( V_192 , V_284 + V_249 ) ;
if ( V_249 > V_277 )
F_142 ( 1 , V_151 L_4 , V_249 ,
V_277 ) ;
if ( V_249 < V_277 ) {
V_275 = F_156 ( V_191 , V_249 - 1 ) -
F_154 ( V_19 , V_191 ) ;
F_123 ( V_191 , F_218 ( V_191 ) +
F_155 ( V_19 ) - V_275 ,
F_218 ( V_191 ) +
F_154 ( V_19 , V_191 ) , V_275 ) ;
F_123 ( V_191 , F_219 ( 0 ) ,
F_219 ( V_249 ) ,
( F_88 ( V_191 ) - V_249 ) *
sizeof( struct V_186 ) ) ;
}
V_277 -= V_249 ;
F_124 ( V_191 , V_277 ) ;
V_275 = F_155 ( V_19 ) ;
for ( V_6 = 0 ; V_6 < V_277 ; V_6 ++ ) {
V_276 = F_210 ( V_6 ) ;
V_275 = V_275 - F_212 ( V_191 ,
V_276 , & V_267 ) ;
F_220 ( V_191 , V_276 , V_275 , & V_267 ) ;
}
F_50 ( V_192 ) ;
if ( V_277 )
F_50 ( V_191 ) ;
else
F_108 ( V_30 , V_19 , V_191 ) ;
F_34 ( V_191 , & V_38 , 0 ) ;
F_201 ( V_19 , V_2 , & V_38 , 1 ) ;
if ( V_2 -> V_17 [ 0 ] < V_249 ) {
V_2 -> V_17 [ 0 ] += V_284 ;
F_21 ( V_2 -> V_8 [ 0 ] ) ;
F_12 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_192 ;
V_2 -> V_17 [ 1 ] -= 1 ;
} else {
F_21 ( V_192 ) ;
F_12 ( V_192 ) ;
V_2 -> V_17 [ 0 ] -= V_249 ;
}
F_72 ( V_2 -> V_17 [ 0 ] < 0 ) ;
return V_35 ;
V_286:
F_21 ( V_192 ) ;
F_12 ( V_192 ) ;
return V_35 ;
}
static int F_223 ( struct V_29 * V_30 , struct V_18
* V_19 , struct V_1 * V_2 , int V_282 ,
int V_270 , int V_248 , T_4 V_283 )
{
struct V_14 * V_191 = V_2 -> V_8 [ 0 ] ;
struct V_14 * V_192 ;
int V_77 ;
int V_271 ;
T_4 V_277 ;
int V_35 = 0 ;
V_77 = V_2 -> V_17 [ 1 ] ;
if ( V_77 == 0 )
return 1 ;
if ( ! V_2 -> V_8 [ 1 ] )
return 1 ;
V_277 = F_88 ( V_191 ) ;
if ( V_277 == 0 )
return 1 ;
F_110 ( V_2 -> V_8 [ 1 ] ) ;
V_192 = F_168 ( V_19 , V_2 -> V_8 [ 1 ] , V_77 - 1 ) ;
if ( V_192 == NULL )
return 1 ;
F_20 ( V_192 ) ;
F_143 ( V_192 ) ;
V_271 = F_196 ( V_19 , V_192 ) ;
if ( V_271 < V_270 ) {
V_35 = 1 ;
goto V_286;
}
V_35 = F_141 ( V_30 , V_19 , V_192 ,
V_2 -> V_8 [ 1 ] , V_77 - 1 , & V_192 ) ;
if ( V_35 ) {
if ( V_35 == - V_199 )
V_35 = 1 ;
goto V_286;
}
V_271 = F_196 ( V_19 , V_192 ) ;
if ( V_271 < V_270 ) {
V_35 = 1 ;
goto V_286;
}
return F_222 ( V_30 , V_19 , V_2 , V_282 ,
V_248 , V_192 , V_271 , V_277 ,
V_283 ) ;
V_286:
F_21 ( V_192 ) ;
F_12 ( V_192 ) ;
return V_35 ;
}
static T_1 void F_224 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_14 * V_263 ,
struct V_14 * V_191 ,
int V_77 , int V_178 , int V_96 )
{
int V_287 ;
int V_288 ;
int V_6 ;
struct V_37 V_38 ;
struct V_266 V_267 ;
F_209 ( & V_267 ) ;
V_96 = V_96 - V_178 ;
F_124 ( V_191 , V_96 ) ;
V_287 = F_217 ( V_263 , V_178 ) - F_154 ( V_19 , V_263 ) ;
F_39 ( V_191 , V_263 , F_219 ( 0 ) ,
F_219 ( V_178 ) ,
V_96 * sizeof( struct V_186 ) ) ;
F_39 ( V_191 , V_263 ,
F_218 ( V_191 ) + F_155 ( V_19 ) -
V_287 , F_218 ( V_263 ) +
F_154 ( V_19 , V_263 ) , V_287 ) ;
V_288 = F_155 ( V_19 ) -
F_217 ( V_263 , V_178 ) ;
for ( V_6 = 0 ; V_6 < V_96 ; V_6 ++ ) {
struct V_186 * V_276 = F_210 ( V_6 ) ;
T_4 V_231 ;
V_231 = F_211 ( V_191 , V_276 , & V_267 ) ;
F_220 ( V_191 , V_276 ,
V_231 + V_288 , & V_267 ) ;
}
F_124 ( V_263 , V_178 ) ;
F_34 ( V_191 , & V_38 , 0 ) ;
F_207 ( V_30 , V_19 , V_2 , & V_38 , V_191 -> V_44 ,
V_2 -> V_17 [ 1 ] + 1 , 1 ) ;
F_50 ( V_191 ) ;
F_50 ( V_263 ) ;
F_72 ( V_2 -> V_17 [ 0 ] != V_77 ) ;
if ( V_178 <= V_77 ) {
F_21 ( V_2 -> V_8 [ 0 ] ) ;
F_12 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_191 ;
V_2 -> V_17 [ 0 ] -= V_178 ;
V_2 -> V_17 [ 1 ] += 1 ;
} else {
F_21 ( V_191 ) ;
F_12 ( V_191 ) ;
}
F_72 ( V_2 -> V_17 [ 0 ] < 0 ) ;
}
static T_1 int F_225 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
int V_270 )
{
int V_35 ;
int V_161 = 0 ;
int V_77 ;
T_4 V_96 ;
int V_289 = V_270 ;
V_77 = V_2 -> V_17 [ 0 ] ;
if ( V_77 < F_88 ( V_2 -> V_8 [ 0 ] ) )
V_289 -= F_196 ( V_19 , V_2 -> V_8 [ 0 ] ) ;
V_35 = F_221 ( V_30 , V_19 , V_2 , 1 , V_289 , 0 , V_77 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 == 0 )
V_161 ++ ;
V_96 = F_88 ( V_2 -> V_8 [ 0 ] ) ;
if ( V_2 -> V_17 [ 0 ] == 0 || V_2 -> V_17 [ 0 ] == V_96 )
return 0 ;
if ( F_196 ( V_19 , V_2 -> V_8 [ 0 ] ) >= V_270 )
return 0 ;
V_77 = V_2 -> V_17 [ 0 ] ;
V_35 = F_223 ( V_30 , V_19 , V_2 , 1 , V_289 , 0 , V_77 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 == 0 )
V_161 ++ ;
if ( V_161 )
return 0 ;
return 1 ;
}
static T_1 int F_197 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_155 * V_290 ,
struct V_1 * V_2 , int V_270 ,
int V_291 )
{
struct V_37 V_38 ;
struct V_14 * V_263 ;
T_4 V_96 ;
int V_178 ;
int V_77 ;
struct V_14 * V_191 ;
int V_35 = 0 ;
int V_193 ;
int V_261 ;
int V_292 = 0 ;
int V_293 = 0 ;
V_263 = V_2 -> V_8 [ 0 ] ;
V_77 = V_2 -> V_17 [ 0 ] ;
if ( V_291 && V_270 + F_226 ( V_263 , V_77 ) +
sizeof( struct V_186 ) > F_155 ( V_19 ) )
return - V_294 ;
if ( V_270 && V_2 -> V_8 [ 1 ] ) {
int V_289 = V_270 ;
if ( V_77 < F_88 ( V_263 ) )
V_289 -= F_196 ( V_19 , V_263 ) ;
V_193 = F_221 ( V_30 , V_19 , V_2 , V_289 ,
V_289 , 0 , 0 ) ;
if ( V_193 < 0 )
return V_193 ;
if ( V_193 ) {
V_193 = F_223 ( V_30 , V_19 , V_2 , V_289 ,
V_289 , 0 , ( T_4 ) - 1 ) ;
if ( V_193 < 0 )
return V_193 ;
}
V_263 = V_2 -> V_8 [ 0 ] ;
if ( F_196 ( V_19 , V_263 ) >= V_270 )
return 0 ;
}
if ( ! V_2 -> V_8 [ 1 ] ) {
V_35 = F_204 ( V_30 , V_19 , V_2 , 1 ) ;
if ( V_35 )
return V_35 ;
}
V_225:
V_261 = 1 ;
V_263 = V_2 -> V_8 [ 0 ] ;
V_77 = V_2 -> V_17 [ 0 ] ;
V_96 = F_88 ( V_263 ) ;
V_178 = ( V_96 + 1 ) / 2 ;
if ( V_178 <= V_77 ) {
if ( V_96 == 1 ||
F_208 ( V_263 , V_178 , V_96 - V_178 ) + V_270 >
F_155 ( V_19 ) ) {
if ( V_77 >= V_96 ) {
V_261 = 0 ;
} else {
V_178 = V_77 ;
if ( V_178 != V_96 &&
F_208 ( V_263 , V_178 , V_96 - V_178 ) +
V_270 > F_155 ( V_19 ) ) {
if ( V_270 && ! V_293 )
goto V_295;
V_261 = 2 ;
}
}
}
} else {
if ( F_208 ( V_263 , 0 , V_178 ) + V_270 >
F_155 ( V_19 ) ) {
if ( ! V_291 && V_270 && V_77 == 0 ) {
V_261 = 0 ;
} else if ( ( V_291 || ! V_270 ) && V_77 == 0 ) {
V_178 = 1 ;
} else {
V_178 = V_77 ;
if ( V_178 != V_96 &&
F_208 ( V_263 , V_178 , V_96 - V_178 ) +
V_270 > F_155 ( V_19 ) ) {
if ( V_270 && ! V_293 )
goto V_295;
V_261 = 2 ;
}
}
}
}
if ( V_261 == 0 )
F_185 ( & V_38 , V_290 ) ;
else
F_34 ( V_263 , & V_38 , V_178 ) ;
V_191 = F_36 ( V_30 , V_19 , V_19 -> V_296 , 0 ,
V_19 -> V_123 . V_124 ,
& V_38 , 0 , V_263 -> V_44 , 0 ) ;
if ( F_37 ( V_191 ) )
return F_38 ( V_191 ) ;
F_163 ( V_19 , V_19 -> V_296 ) ;
F_205 ( V_191 , 0 , 0 , sizeof( struct V_257 ) ) ;
F_40 ( V_191 , V_191 -> V_44 ) ;
F_41 ( V_191 , V_30 -> V_40 ) ;
F_42 ( V_191 , V_45 ) ;
F_45 ( V_191 , V_19 -> V_123 . V_124 ) ;
F_128 ( V_191 , 0 ) ;
F_46 ( V_191 , V_19 -> V_23 -> V_49 ,
F_47 () , V_50 ) ;
F_46 ( V_191 , V_19 -> V_23 -> V_258 ,
F_206 ( V_191 ) ,
V_259 ) ;
if ( V_261 == 0 ) {
if ( V_178 <= V_77 ) {
F_124 ( V_191 , 0 ) ;
F_207 ( V_30 , V_19 , V_2 , & V_38 , V_191 -> V_44 ,
V_2 -> V_17 [ 1 ] + 1 , 1 ) ;
F_21 ( V_2 -> V_8 [ 0 ] ) ;
F_12 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_191 ;
V_2 -> V_17 [ 0 ] = 0 ;
V_2 -> V_17 [ 1 ] += 1 ;
} else {
F_124 ( V_191 , 0 ) ;
F_207 ( V_30 , V_19 , V_2 , & V_38 , V_191 -> V_44 ,
V_2 -> V_17 [ 1 ] , 1 ) ;
F_21 ( V_2 -> V_8 [ 0 ] ) ;
F_12 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_191 ;
V_2 -> V_17 [ 0 ] = 0 ;
if ( V_2 -> V_17 [ 1 ] == 0 )
F_201 ( V_19 , V_2 , & V_38 , 1 ) ;
}
F_50 ( V_191 ) ;
return V_35 ;
}
F_224 ( V_30 , V_19 , V_2 , V_263 , V_191 , V_77 , V_178 , V_96 ) ;
if ( V_261 == 2 ) {
F_72 ( V_292 != 0 ) ;
V_292 ++ ;
goto V_225;
}
return 0 ;
V_295:
F_225 ( V_30 , V_19 , V_2 , V_270 ) ;
V_293 = 1 ;
if ( F_196 ( V_19 , V_2 -> V_8 [ 0 ] ) >= V_270 )
return 0 ;
goto V_225;
}
static T_1 int F_227 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_222 )
{
struct V_155 V_83 ;
struct V_14 * V_172 ;
struct V_297 * V_298 ;
T_2 V_299 = 0 ;
T_4 V_174 ;
int V_35 ;
V_172 = V_2 -> V_8 [ 0 ] ;
F_191 ( V_172 , & V_83 , V_2 -> V_17 [ 0 ] ) ;
F_72 ( V_83 . type != V_300 &&
V_83 . type != V_301 ) ;
if ( F_196 ( V_19 , V_172 ) >= V_222 )
return 0 ;
V_174 = F_226 ( V_172 , V_2 -> V_17 [ 0 ] ) ;
if ( V_83 . type == V_300 ) {
V_298 = F_228 ( V_172 , V_2 -> V_17 [ 0 ] ,
struct V_297 ) ;
V_299 = F_229 ( V_172 , V_298 ) ;
}
F_9 ( V_2 ) ;
V_2 -> V_218 = 1 ;
V_2 -> V_223 = 1 ;
V_35 = F_189 ( V_30 , V_19 , & V_83 , V_2 , 0 , 1 ) ;
V_2 -> V_223 = 0 ;
if ( V_35 < 0 )
goto V_166;
V_35 = - V_221 ;
V_172 = V_2 -> V_8 [ 0 ] ;
if ( V_35 > 0 || V_174 != F_226 ( V_172 , V_2 -> V_17 [ 0 ] ) )
goto V_166;
if ( F_196 ( V_19 , V_2 -> V_8 [ 0 ] ) >= V_222 )
goto V_166;
if ( V_83 . type == V_300 ) {
V_298 = F_228 ( V_172 , V_2 -> V_17 [ 0 ] ,
struct V_297 ) ;
if ( V_299 != F_229 ( V_172 , V_298 ) )
goto V_166;
}
F_3 ( V_2 ) ;
V_35 = F_197 ( V_30 , V_19 , & V_83 , V_2 , V_222 , 1 ) ;
if ( V_35 )
goto V_166;
V_2 -> V_218 = 0 ;
F_179 ( V_2 , 1 ) ;
return 0 ;
V_166:
V_2 -> V_218 = 0 ;
return V_35 ;
}
static T_1 int F_230 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_155 * V_247 ,
unsigned long V_302 )
{
struct V_14 * V_172 ;
struct V_186 * V_276 ;
struct V_186 * V_303 ;
int V_77 ;
char * V_31 ;
T_4 V_96 ;
T_4 V_174 ;
T_4 V_304 ;
struct V_37 V_38 ;
V_172 = V_2 -> V_8 [ 0 ] ;
F_72 ( F_196 ( V_19 , V_172 ) < sizeof( struct V_186 ) ) ;
F_3 ( V_2 ) ;
V_276 = F_210 ( V_2 -> V_17 [ 0 ] ) ;
V_304 = F_231 ( V_172 , V_276 ) ;
V_174 = F_216 ( V_172 , V_276 ) ;
V_31 = F_232 ( V_174 , V_4 ) ;
if ( ! V_31 )
return - V_86 ;
F_159 ( V_172 , V_31 , F_233 ( V_172 ,
V_2 -> V_17 [ 0 ] ) , V_174 ) ;
V_77 = V_2 -> V_17 [ 0 ] + 1 ;
V_96 = F_88 ( V_172 ) ;
if ( V_77 != V_96 ) {
F_123 ( V_172 , F_219 ( V_77 + 1 ) ,
F_219 ( V_77 ) ,
( V_96 - V_77 ) * sizeof( struct V_186 ) ) ;
}
F_185 ( & V_38 , V_247 ) ;
F_203 ( V_172 , & V_38 , V_77 ) ;
V_303 = F_210 ( V_77 ) ;
F_234 ( V_172 , V_303 , V_304 ) ;
F_235 ( V_172 , V_303 , V_174 - V_302 ) ;
F_234 ( V_172 , V_276 ,
V_304 + V_174 - V_302 ) ;
F_235 ( V_172 , V_276 , V_302 ) ;
F_124 ( V_172 , V_96 + 1 ) ;
F_46 ( V_172 , V_31 ,
F_233 ( V_172 , V_2 -> V_17 [ 0 ] ) ,
V_302 ) ;
F_46 ( V_172 , V_31 + V_302 ,
F_233 ( V_172 , V_77 ) ,
V_174 - V_302 ) ;
F_50 ( V_172 ) ;
F_72 ( F_196 ( V_19 , V_172 ) < 0 ) ;
F_70 ( V_31 ) ;
return 0 ;
}
int F_236 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_155 * V_247 ,
unsigned long V_302 )
{
int V_35 ;
V_35 = F_227 ( V_30 , V_19 , V_2 ,
sizeof( struct V_186 ) ) ;
if ( V_35 )
return V_35 ;
V_35 = F_230 ( V_30 , V_19 , V_2 , V_247 , V_302 ) ;
return V_35 ;
}
int F_237 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_155 * V_247 )
{
struct V_14 * V_172 ;
int V_35 ;
T_4 V_174 ;
V_172 = V_2 -> V_8 [ 0 ] ;
V_174 = F_226 ( V_172 , V_2 -> V_17 [ 0 ] ) ;
V_35 = F_227 ( V_30 , V_19 , V_2 ,
V_174 + sizeof( struct V_186 ) ) ;
if ( V_35 )
return V_35 ;
V_2 -> V_17 [ 0 ] ++ ;
F_238 ( V_19 , V_2 , V_247 , & V_174 ,
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
T_4 V_305 , int V_306 )
{
int V_77 ;
struct V_14 * V_172 ;
struct V_186 * V_276 ;
T_4 V_96 ;
unsigned int V_278 ;
unsigned int V_307 ;
unsigned int V_308 ;
unsigned int V_309 ;
int V_6 ;
struct V_266 V_267 ;
F_209 ( & V_267 ) ;
V_172 = V_2 -> V_8 [ 0 ] ;
V_77 = V_2 -> V_17 [ 0 ] ;
V_308 = F_226 ( V_172 , V_77 ) ;
if ( V_308 == V_305 )
return;
V_96 = F_88 ( V_172 ) ;
V_278 = F_154 ( V_19 , V_172 ) ;
V_307 = F_156 ( V_172 , V_77 ) ;
V_309 = V_308 - V_305 ;
F_72 ( V_77 < 0 ) ;
F_72 ( V_77 >= V_96 ) ;
for ( V_6 = V_77 ; V_6 < V_96 ; V_6 ++ ) {
T_4 V_231 ;
V_276 = F_210 ( V_6 ) ;
V_231 = F_211 ( V_172 , V_276 , & V_267 ) ;
F_220 ( V_172 , V_276 ,
V_231 + V_309 , & V_267 ) ;
}
if ( V_306 ) {
F_123 ( V_172 , F_218 ( V_172 ) +
V_278 + V_309 , F_218 ( V_172 ) +
V_278 , V_307 + V_305 - V_278 ) ;
} else {
struct V_37 V_38 ;
T_2 V_158 ;
F_34 ( V_172 , & V_38 , V_77 ) ;
if ( F_241 ( & V_38 ) == V_300 ) {
unsigned long V_310 ;
struct V_297 * V_298 ;
V_298 = F_228 ( V_172 , V_77 ,
struct V_297 ) ;
V_298 = (struct V_297 * ) (
( unsigned long ) V_298 - V_309 ) ;
if ( F_242 ( V_172 , V_298 ) ==
V_311 ) {
V_310 = F_233 ( V_172 , V_77 ) ;
F_123 ( V_172 , V_310 ,
( unsigned long ) V_298 ,
F_161 ( struct V_297 ,
V_312 ) ) ;
}
}
F_123 ( V_172 , F_218 ( V_172 ) +
V_278 + V_309 , F_218 ( V_172 ) +
V_278 , V_307 - V_278 ) ;
V_158 = F_243 ( & V_38 ) ;
F_244 ( & V_38 , V_158 + V_309 ) ;
F_203 ( V_172 , & V_38 , V_77 ) ;
if ( V_77 == 0 )
F_201 ( V_19 , V_2 , & V_38 , 1 ) ;
}
V_276 = F_210 ( V_77 ) ;
F_235 ( V_172 , V_276 , V_305 ) ;
F_50 ( V_172 ) ;
if ( F_196 ( V_19 , V_172 ) < 0 ) {
F_245 ( V_19 , V_172 ) ;
F_172 () ;
}
}
void F_246 ( struct V_18 * V_19 , struct V_1 * V_2 ,
T_4 V_270 )
{
int V_77 ;
struct V_14 * V_172 ;
struct V_186 * V_276 ;
T_4 V_96 ;
unsigned int V_278 ;
unsigned int V_313 ;
unsigned int V_308 ;
int V_6 ;
struct V_266 V_267 ;
F_209 ( & V_267 ) ;
V_172 = V_2 -> V_8 [ 0 ] ;
V_96 = F_88 ( V_172 ) ;
V_278 = F_154 ( V_19 , V_172 ) ;
if ( F_196 ( V_19 , V_172 ) < V_270 ) {
F_245 ( V_19 , V_172 ) ;
F_172 () ;
}
V_77 = V_2 -> V_17 [ 0 ] ;
V_313 = F_217 ( V_172 , V_77 ) ;
F_72 ( V_77 < 0 ) ;
if ( V_77 >= V_96 ) {
F_245 ( V_19 , V_172 ) ;
F_213 ( V_19 -> V_23 , L_5 ,
V_77 , V_96 ) ;
F_72 ( 1 ) ;
}
for ( V_6 = V_77 ; V_6 < V_96 ; V_6 ++ ) {
T_4 V_231 ;
V_276 = F_210 ( V_6 ) ;
V_231 = F_211 ( V_172 , V_276 , & V_267 ) ;
F_220 ( V_172 , V_276 ,
V_231 - V_270 , & V_267 ) ;
}
F_123 ( V_172 , F_218 ( V_172 ) +
V_278 - V_270 , F_218 ( V_172 ) +
V_278 , V_313 - V_278 ) ;
V_278 = V_313 ;
V_308 = F_226 ( V_172 , V_77 ) ;
V_276 = F_210 ( V_77 ) ;
F_235 ( V_172 , V_276 , V_308 + V_270 ) ;
F_50 ( V_172 ) ;
if ( F_196 ( V_19 , V_172 ) < 0 ) {
F_245 ( V_19 , V_172 ) ;
F_172 () ;
}
}
void F_238 ( struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_155 * V_314 , T_4 * V_270 ,
T_4 V_315 , T_4 V_316 , int V_173 )
{
struct V_186 * V_276 ;
int V_6 ;
T_4 V_96 ;
unsigned int V_278 ;
struct V_37 V_38 ;
struct V_14 * V_172 ;
int V_77 ;
struct V_266 V_267 ;
F_209 ( & V_267 ) ;
V_172 = V_2 -> V_8 [ 0 ] ;
V_77 = V_2 -> V_17 [ 0 ] ;
V_96 = F_88 ( V_172 ) ;
V_278 = F_154 ( V_19 , V_172 ) ;
if ( F_196 ( V_19 , V_172 ) < V_316 ) {
F_245 ( V_19 , V_172 ) ;
F_213 ( V_19 -> V_23 , L_6 ,
V_316 , F_196 ( V_19 , V_172 ) ) ;
F_172 () ;
}
if ( V_77 != V_96 ) {
unsigned int V_313 = F_217 ( V_172 , V_77 ) ;
if ( V_313 < V_278 ) {
F_245 ( V_19 , V_172 ) ;
F_213 ( V_19 -> V_23 , L_7 ,
V_77 , V_313 , V_278 ) ;
F_72 ( 1 ) ;
}
for ( V_6 = V_77 ; V_6 < V_96 ; V_6 ++ ) {
T_4 V_231 ;
V_276 = F_210 ( V_6 ) ;
V_231 = F_211 ( V_172 , V_276 , & V_267 ) ;
F_220 ( V_172 , V_276 ,
V_231 - V_315 , & V_267 ) ;
}
F_123 ( V_172 , F_219 ( V_77 + V_173 ) ,
F_219 ( V_77 ) ,
( V_96 - V_77 ) * sizeof( struct V_186 ) ) ;
F_123 ( V_172 , F_218 ( V_172 ) +
V_278 - V_315 , F_218 ( V_172 ) +
V_278 , V_313 - V_278 ) ;
V_278 = V_313 ;
}
for ( V_6 = 0 ; V_6 < V_173 ; V_6 ++ ) {
F_185 ( & V_38 , V_314 + V_6 ) ;
F_203 ( V_172 , & V_38 , V_77 + V_6 ) ;
V_276 = F_210 ( V_77 + V_6 ) ;
F_220 ( V_172 , V_276 ,
V_278 - V_270 [ V_6 ] , & V_267 ) ;
V_278 -= V_270 [ V_6 ] ;
F_247 ( V_172 , V_276 , V_270 [ V_6 ] , & V_267 ) ;
}
F_124 ( V_172 , V_96 + V_173 ) ;
if ( V_77 == 0 ) {
F_185 ( & V_38 , V_314 ) ;
F_201 ( V_19 , V_2 , & V_38 , 1 ) ;
}
F_179 ( V_2 , 1 ) ;
F_50 ( V_172 ) ;
if ( F_196 ( V_19 , V_172 ) < 0 ) {
F_245 ( V_19 , V_172 ) ;
F_172 () ;
}
}
int F_248 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_155 * V_314 , T_4 * V_270 ,
int V_173 )
{
int V_35 = 0 ;
int V_77 ;
int V_6 ;
T_4 V_316 = 0 ;
T_4 V_315 = 0 ;
for ( V_6 = 0 ; V_6 < V_173 ; V_6 ++ )
V_315 += V_270 [ V_6 ] ;
V_316 = V_315 + ( V_173 * sizeof( struct V_186 ) ) ;
V_35 = F_189 ( V_30 , V_19 , V_314 , V_2 , V_316 , 1 ) ;
if ( V_35 == 0 )
return - V_76 ;
if ( V_35 < 0 )
return V_35 ;
V_77 = V_2 -> V_17 [ 0 ] ;
F_72 ( V_77 < 0 ) ;
F_238 ( V_19 , V_2 , V_314 , V_270 ,
V_315 , V_316 , V_173 ) ;
return 0 ;
}
int F_249 ( struct V_29 * V_30 , struct V_18
* V_19 , struct V_155 * V_314 , void * V_317 , T_4
V_270 )
{
int V_35 = 0 ;
struct V_1 * V_2 ;
struct V_14 * V_172 ;
unsigned long V_310 ;
V_2 = F_1 () ;
if ( ! V_2 )
return - V_86 ;
V_35 = F_250 ( V_30 , V_19 , V_2 , V_314 , V_270 ) ;
if ( ! V_35 ) {
V_172 = V_2 -> V_8 [ 0 ] ;
V_310 = F_233 ( V_172 , V_2 -> V_17 [ 0 ] ) ;
F_46 ( V_172 , V_317 , V_310 , V_270 ) ;
F_50 ( V_172 ) ;
}
F_8 ( V_2 ) ;
return V_35 ;
}
static void F_170 ( struct V_18 * V_19 , struct V_1 * V_2 ,
int V_36 , int V_77 )
{
struct V_14 * V_71 = V_2 -> V_8 [ V_36 ] ;
T_4 V_96 ;
int V_35 ;
V_96 = F_88 ( V_71 ) ;
if ( V_77 != V_96 - 1 ) {
if ( V_36 )
F_93 ( V_19 -> V_23 , V_71 , V_77 ,
V_77 + 1 , V_96 - V_77 - 1 ) ;
F_123 ( V_71 ,
F_122 ( V_77 ) ,
F_122 ( V_77 + 1 ) ,
sizeof( struct V_140 ) *
( V_96 - V_77 - 1 ) ) ;
} else if ( V_36 ) {
V_35 = F_83 ( V_19 -> V_23 , V_71 , V_77 ,
V_112 , V_4 ) ;
F_72 ( V_35 < 0 ) ;
}
V_96 -- ;
F_124 ( V_71 , V_96 ) ;
if ( V_96 == 0 && V_71 == V_19 -> V_21 ) {
F_72 ( F_33 ( V_19 -> V_21 ) != 1 ) ;
F_128 ( V_19 -> V_21 , 0 ) ;
} else if ( V_77 == 0 ) {
struct V_37 V_38 ;
F_35 ( V_71 , & V_38 , 0 ) ;
F_201 ( V_19 , V_2 , & V_38 , V_36 + 1 ) ;
}
F_50 ( V_71 ) ;
}
static T_1 void F_251 ( struct V_29 * V_30 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_14 * V_172 )
{
F_32 ( F_48 ( V_172 ) != V_30 -> V_40 ) ;
F_170 ( V_19 , V_2 , 1 , V_2 -> V_17 [ 1 ] ) ;
F_179 ( V_2 , 0 ) ;
F_166 ( V_19 , V_172 -> V_43 ) ;
F_113 ( V_172 ) ;
F_115 ( V_30 , V_19 , V_172 , 0 , 1 ) ;
F_118 ( V_172 ) ;
}
int F_252 ( struct V_29 * V_30 , struct V_18 * V_19 ,
struct V_1 * V_2 , int V_77 , int V_173 )
{
struct V_14 * V_172 ;
struct V_186 * V_276 ;
int V_318 ;
int V_319 = 0 ;
int V_35 = 0 ;
int V_193 ;
int V_6 ;
T_4 V_96 ;
struct V_266 V_267 ;
F_209 ( & V_267 ) ;
V_172 = V_2 -> V_8 [ 0 ] ;
V_318 = F_156 ( V_172 , V_77 + V_173 - 1 ) ;
for ( V_6 = 0 ; V_6 < V_173 ; V_6 ++ )
V_319 += F_226 ( V_172 , V_77 + V_6 ) ;
V_96 = F_88 ( V_172 ) ;
if ( V_77 + V_173 != V_96 ) {
int V_278 = F_154 ( V_19 , V_172 ) ;
F_123 ( V_172 , F_218 ( V_172 ) +
V_278 + V_319 ,
F_218 ( V_172 ) + V_278 ,
V_318 - V_278 ) ;
for ( V_6 = V_77 + V_173 ; V_6 < V_96 ; V_6 ++ ) {
T_4 V_231 ;
V_276 = F_210 ( V_6 ) ;
V_231 = F_211 ( V_172 , V_276 , & V_267 ) ;
F_220 ( V_172 , V_276 ,
V_231 + V_319 , & V_267 ) ;
}
F_123 ( V_172 , F_219 ( V_77 ) ,
F_219 ( V_77 + V_173 ) ,
sizeof( struct V_186 ) *
( V_96 - V_77 - V_173 ) ) ;
}
F_124 ( V_172 , V_96 - V_173 ) ;
V_96 -= V_173 ;
if ( V_96 == 0 ) {
if ( V_172 == V_19 -> V_21 ) {
F_128 ( V_172 , 0 ) ;
} else {
F_3 ( V_2 ) ;
F_108 ( V_30 , V_19 , V_172 ) ;
F_251 ( V_30 , V_19 , V_2 , V_172 ) ;
}
} else {
int V_320 = F_208 ( V_172 , 0 , V_96 ) ;
if ( V_77 == 0 ) {
struct V_37 V_38 ;
F_34 ( V_172 , & V_38 , 0 ) ;
F_201 ( V_19 , V_2 , & V_38 , 1 ) ;
}
if ( V_320 < F_155 ( V_19 ) / 3 ) {
V_77 = V_2 -> V_17 [ 1 ] ;
F_113 ( V_172 ) ;
F_3 ( V_2 ) ;
V_193 = F_223 ( V_30 , V_19 , V_2 , 1 , 1 ,
1 , ( T_4 ) - 1 ) ;
if ( V_193 < 0 && V_193 != - V_199 )
V_35 = V_193 ;
if ( V_2 -> V_8 [ 0 ] == V_172 &&
F_88 ( V_172 ) ) {
V_193 = F_221 ( V_30 , V_19 , V_2 , 1 ,
1 , 1 , 0 ) ;
if ( V_193 < 0 && V_193 != - V_199 )
V_35 = V_193 ;
}
if ( F_88 ( V_172 ) == 0 ) {
V_2 -> V_17 [ 1 ] = V_77 ;
F_251 ( V_30 , V_19 , V_2 , V_172 ) ;
F_12 ( V_172 ) ;
V_35 = 0 ;
} else {
if ( V_2 -> V_8 [ 0 ] == V_172 )
F_50 ( V_172 ) ;
F_12 ( V_172 ) ;
}
} else {
F_50 ( V_172 ) ;
}
}
return V_35 ;
}
int F_200 ( struct V_18 * V_19 , struct V_1 * V_2 )
{
struct V_155 V_83 ;
struct V_37 V_233 ;
int V_35 ;
F_191 ( V_2 -> V_8 [ 0 ] , & V_83 , 0 ) ;
if ( V_83 . V_158 > 0 ) {
V_83 . V_158 -- ;
} else if ( V_83 . type > 0 ) {
V_83 . type -- ;
V_83 . V_158 = ( T_2 ) - 1 ;
} else if ( V_83 . V_124 > 0 ) {
V_83 . V_124 -- ;
V_83 . type = ( T_5 ) - 1 ;
V_83 . V_158 = ( T_2 ) - 1 ;
} else {
return 1 ;
}
F_9 ( V_2 ) ;
V_35 = F_189 ( NULL , V_19 , & V_83 , V_2 , 0 , 0 ) ;
if ( V_35 < 0 )
return V_35 ;
F_34 ( V_2 -> V_8 [ 0 ] , & V_233 , 0 ) ;
V_35 = F_146 ( & V_233 , & V_83 ) ;
if ( V_35 <= 0 )
return 0 ;
return 1 ;
}
int F_253 ( struct V_18 * V_19 , struct V_155 * V_321 ,
struct V_1 * V_2 ,
T_2 V_322 )
{
struct V_14 * V_72 ;
struct V_155 V_233 ;
int V_77 ;
int V_224 ;
T_4 V_96 ;
int V_36 ;
int V_35 = 1 ;
F_32 ( ! V_2 -> V_218 ) ;
V_225:
V_72 = F_22 ( V_19 ) ;
V_36 = F_33 ( V_72 ) ;
F_32 ( V_2 -> V_8 [ V_36 ] ) ;
V_2 -> V_8 [ V_36 ] = V_72 ;
V_2 -> V_9 [ V_36 ] = V_10 ;
if ( F_48 ( V_72 ) < V_322 ) {
V_35 = 1 ;
goto V_286;
}
while ( 1 ) {
V_96 = F_88 ( V_72 ) ;
V_36 = F_33 ( V_72 ) ;
V_224 = F_160 ( V_72 , V_321 , V_36 , & V_77 ) ;
if ( V_36 == V_2 -> V_235 ) {
if ( V_77 >= V_96 )
goto V_323;
V_35 = 0 ;
V_2 -> V_17 [ V_36 ] = V_77 ;
F_191 ( V_72 , & V_233 , V_77 ) ;
goto V_286;
}
if ( V_224 && V_77 > 0 )
V_77 -- ;
while ( V_77 < V_96 ) {
T_2 V_162 ;
V_162 = F_81 ( V_72 , V_77 ) ;
if ( V_162 < V_322 ) {
V_77 ++ ;
continue;
}
break;
}
V_323:
if ( V_77 >= V_96 ) {
V_2 -> V_17 [ V_36 ] = V_77 ;
F_3 ( V_2 ) ;
V_224 = F_254 ( V_19 , V_2 , V_321 , V_36 ,
V_322 ) ;
if ( V_224 == 0 ) {
F_9 ( V_2 ) ;
goto V_225;
} else {
goto V_286;
}
}
F_255 ( V_72 , & V_233 , V_77 ) ;
V_2 -> V_17 [ V_36 ] = V_77 ;
if ( V_36 == V_2 -> V_235 ) {
V_35 = 0 ;
F_178 ( V_2 , V_36 , 1 , 0 , NULL ) ;
goto V_286;
}
F_3 ( V_2 ) ;
V_72 = F_168 ( V_19 , V_72 , V_77 ) ;
F_72 ( ! V_72 ) ;
F_23 ( V_72 ) ;
V_2 -> V_9 [ V_36 - 1 ] = V_10 ;
V_2 -> V_8 [ V_36 - 1 ] = V_72 ;
F_178 ( V_2 , V_36 , 1 , 0 , NULL ) ;
F_5 ( V_2 , NULL , 0 ) ;
}
V_286:
if ( V_35 == 0 )
memcpy ( V_321 , & V_233 , sizeof( V_233 ) ) ;
F_3 ( V_2 ) ;
return V_35 ;
}
static void F_256 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int * V_36 , int V_324 )
{
F_72 ( * V_36 == 0 ) ;
V_2 -> V_8 [ * V_36 - 1 ] = F_168 ( V_19 , V_2 -> V_8 [ * V_36 ] ,
V_2 -> V_17 [ * V_36 ] ) ;
V_2 -> V_17 [ * V_36 - 1 ] = 0 ;
( * V_36 ) -- ;
}
static int F_257 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int * V_36 , int V_324 )
{
int V_35 = 0 ;
int V_96 ;
V_96 = F_88 ( V_2 -> V_8 [ * V_36 ] ) ;
V_2 -> V_17 [ * V_36 ] ++ ;
while ( V_2 -> V_17 [ * V_36 ] >= V_96 ) {
if ( * V_36 == V_324 )
return - 1 ;
V_2 -> V_17 [ * V_36 ] = 0 ;
F_12 ( V_2 -> V_8 [ * V_36 ] ) ;
V_2 -> V_8 [ * V_36 ] = NULL ;
( * V_36 ) ++ ;
V_2 -> V_17 [ * V_36 ] ++ ;
V_96 = F_88 ( V_2 -> V_8 [ * V_36 ] ) ;
V_35 = 1 ;
}
return V_35 ;
}
static int F_258 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int * V_36 , int V_324 ,
int V_325 ,
struct V_155 * V_83 )
{
int V_35 ;
if ( * V_36 == 0 || ! V_325 ) {
V_35 = F_257 ( V_19 , V_2 , V_36 , V_324 ) ;
} else {
F_256 ( V_19 , V_2 , V_36 , V_324 ) ;
V_35 = 0 ;
}
if ( V_35 >= 0 ) {
if ( * V_36 == 0 )
F_191 ( V_2 -> V_8 [ * V_36 ] , V_83 ,
V_2 -> V_17 [ * V_36 ] ) ;
else
F_255 ( V_2 -> V_8 [ * V_36 ] , V_83 ,
V_2 -> V_17 [ * V_36 ] ) ;
}
return V_35 ;
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
int V_35 ;
int V_330 ;
struct V_1 * V_327 = NULL ;
struct V_1 * V_328 = NULL ;
struct V_155 V_338 ;
struct V_155 V_200 ;
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
V_35 = - V_86 ;
goto V_286;
}
V_328 = F_1 () ;
if ( ! V_328 ) {
V_35 = - V_86 ;
goto V_286;
}
V_329 = F_232 ( V_326 -> V_296 , V_4 ) ;
if ( ! V_329 ) {
V_35 = - V_86 ;
goto V_286;
}
V_327 -> V_236 = 1 ;
V_327 -> V_239 = 1 ;
V_328 -> V_236 = 1 ;
V_328 -> V_239 = 1 ;
F_192 ( & V_326 -> V_23 -> V_238 ) ;
V_341 = F_33 ( V_326 -> V_117 ) ;
V_339 = V_341 ;
V_327 -> V_8 [ V_341 ] = V_326 -> V_117 ;
F_113 ( V_327 -> V_8 [ V_341 ] ) ;
V_342 = F_33 ( V_335 -> V_117 ) ;
V_340 = V_342 ;
V_328 -> V_8 [ V_342 ] = V_335 -> V_117 ;
F_113 ( V_328 -> V_8 [ V_342 ] ) ;
F_193 ( & V_326 -> V_23 -> V_238 ) ;
if ( V_341 == 0 )
F_191 ( V_327 -> V_8 [ V_341 ] ,
& V_338 , V_327 -> V_17 [ V_341 ] ) ;
else
F_255 ( V_327 -> V_8 [ V_341 ] ,
& V_338 , V_327 -> V_17 [ V_341 ] ) ;
if ( V_342 == 0 )
F_191 ( V_328 -> V_8 [ V_342 ] ,
& V_200 , V_328 -> V_17 [ V_342 ] ) ;
else
F_255 ( V_328 -> V_8 [ V_342 ] ,
& V_200 , V_328 -> V_17 [ V_342 ] ) ;
V_343 = V_344 = 0 ;
V_345 = V_346 = 0 ;
while ( 1 ) {
if ( V_345 && ! V_343 ) {
V_35 = F_258 ( V_326 , V_327 , & V_341 ,
V_339 ,
V_345 != V_351 ,
& V_338 ) ;
if ( V_35 < 0 )
V_343 = V_352 ;
V_345 = 0 ;
}
if ( V_346 && ! V_344 ) {
V_35 = F_258 ( V_335 , V_328 , & V_342 ,
V_340 ,
V_346 != V_351 ,
& V_200 ) ;
if ( V_35 < 0 )
V_344 = V_352 ;
V_346 = 0 ;
}
if ( V_343 && V_344 ) {
V_35 = 0 ;
goto V_286;
} else if ( V_343 ) {
if ( V_342 == 0 ) {
V_35 = V_336 ( V_326 , V_335 ,
V_327 , V_328 ,
& V_200 ,
V_353 ,
V_337 ) ;
if ( V_35 < 0 )
goto V_286;
}
V_346 = V_352 ;
continue;
} else if ( V_344 ) {
if ( V_341 == 0 ) {
V_35 = V_336 ( V_326 , V_335 ,
V_327 , V_328 ,
& V_338 ,
V_354 ,
V_337 ) ;
if ( V_35 < 0 )
goto V_286;
}
V_345 = V_352 ;
continue;
}
if ( V_341 == 0 && V_342 == 0 ) {
V_330 = F_148 ( & V_338 , & V_200 ) ;
if ( V_330 < 0 ) {
V_35 = V_336 ( V_326 , V_335 ,
V_327 , V_328 ,
& V_338 ,
V_354 ,
V_337 ) ;
if ( V_35 < 0 )
goto V_286;
V_345 = V_352 ;
} else if ( V_330 > 0 ) {
V_35 = V_336 ( V_326 , V_335 ,
V_327 , V_328 ,
& V_200 ,
V_353 ,
V_337 ) ;
if ( V_35 < 0 )
goto V_286;
V_346 = V_352 ;
} else {
enum V_355 V_330 ;
F_32 ( ! F_134 ( V_327 -> V_8 [ 0 ] ) ) ;
V_35 = F_259 ( V_326 , V_327 ,
V_328 , V_329 ) ;
if ( V_35 )
V_330 = V_356 ;
else
V_330 = V_357 ;
V_35 = V_336 ( V_326 , V_335 ,
V_327 , V_328 ,
& V_338 , V_330 , V_337 ) ;
if ( V_35 < 0 )
goto V_286;
V_345 = V_352 ;
V_346 = V_352 ;
}
} else if ( V_341 == V_342 ) {
V_330 = F_148 ( & V_338 , & V_200 ) ;
if ( V_330 < 0 ) {
V_345 = V_352 ;
} else if ( V_330 > 0 ) {
V_346 = V_352 ;
} else {
V_347 = F_80 (
V_327 -> V_8 [ V_341 ] ,
V_327 -> V_17 [ V_341 ] ) ;
V_348 = F_80 (
V_328 -> V_8 [ V_342 ] ,
V_328 -> V_17 [ V_342 ] ) ;
V_349 = F_81 (
V_327 -> V_8 [ V_341 ] ,
V_327 -> V_17 [ V_341 ] ) ;
V_350 = F_81 (
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
V_286:
F_8 ( V_327 ) ;
F_8 ( V_328 ) ;
F_70 ( V_329 ) ;
return V_35 ;
}
int F_254 ( struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_155 * V_83 , int V_36 , T_2 V_322 )
{
int V_77 ;
struct V_14 * V_255 ;
F_32 ( ! V_2 -> V_218 ) ;
while ( V_36 < V_7 ) {
if ( ! V_2 -> V_8 [ V_36 ] )
return 1 ;
V_77 = V_2 -> V_17 [ V_36 ] + 1 ;
V_255 = V_2 -> V_8 [ V_36 ] ;
V_63:
if ( V_77 >= F_88 ( V_255 ) ) {
int V_35 ;
int V_358 ;
struct V_155 V_359 ;
if ( V_36 + 1 >= V_7 ||
! V_2 -> V_8 [ V_36 + 1 ] )
return 1 ;
if ( V_2 -> V_9 [ V_36 + 1 ] ) {
V_36 ++ ;
continue;
}
V_77 = F_88 ( V_255 ) - 1 ;
if ( V_36 == 0 )
F_191 ( V_255 , & V_359 , V_77 ) ;
else
F_255 ( V_255 , & V_359 , V_77 ) ;
V_358 = V_2 -> V_235 ;
F_9 ( V_2 ) ;
V_2 -> V_235 = V_36 ;
V_35 = F_189 ( NULL , V_19 , & V_359 , V_2 ,
0 , 0 ) ;
V_2 -> V_235 = V_358 ;
if ( V_35 < 0 )
return V_35 ;
V_255 = V_2 -> V_8 [ V_36 ] ;
V_77 = V_2 -> V_17 [ V_36 ] ;
if ( V_35 == 0 )
V_77 ++ ;
goto V_63;
}
if ( V_36 == 0 )
F_191 ( V_255 , V_83 , V_77 ) ;
else {
T_2 V_162 = F_81 ( V_255 , V_77 ) ;
if ( V_162 < V_322 ) {
V_77 ++ ;
goto V_63;
}
F_255 ( V_255 , V_83 , V_77 ) ;
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
T_2 V_132 )
{
int V_77 ;
int V_36 ;
struct V_14 * V_255 ;
struct V_14 * V_63 ;
struct V_155 V_83 ;
T_4 V_96 ;
int V_35 ;
int V_360 = V_2 -> V_243 ;
int V_361 = 0 ;
V_96 = F_88 ( V_2 -> V_8 [ 0 ] ) ;
if ( V_96 == 0 )
return 1 ;
F_191 ( V_2 -> V_8 [ 0 ] , & V_83 , V_96 - 1 ) ;
V_225:
V_36 = 1 ;
V_63 = NULL ;
V_361 = 0 ;
F_9 ( V_2 ) ;
V_2 -> V_218 = 1 ;
V_2 -> V_243 = 1 ;
if ( V_132 )
V_35 = F_198 ( V_19 , & V_83 , V_2 , V_132 ) ;
else
V_35 = F_189 ( NULL , V_19 , & V_83 , V_2 , 0 , 0 ) ;
V_2 -> V_218 = 0 ;
if ( V_35 < 0 )
return V_35 ;
V_96 = F_88 ( V_2 -> V_8 [ 0 ] ) ;
if ( V_96 > 0 && V_2 -> V_17 [ 0 ] < V_96 - 1 ) {
if ( V_35 == 0 )
V_2 -> V_17 [ 0 ] ++ ;
V_35 = 0 ;
goto V_226;
}
if ( V_96 > 0 && V_35 > 0 && V_2 -> V_17 [ 0 ] == V_96 - 1 ) {
V_35 = 0 ;
goto V_226;
}
while ( V_36 < V_7 ) {
if ( ! V_2 -> V_8 [ V_36 ] ) {
V_35 = 1 ;
goto V_226;
}
V_77 = V_2 -> V_17 [ V_36 ] + 1 ;
V_255 = V_2 -> V_8 [ V_36 ] ;
if ( V_77 >= F_88 ( V_255 ) ) {
V_36 ++ ;
if ( V_36 == V_7 ) {
V_35 = 1 ;
goto V_226;
}
continue;
}
if ( V_63 ) {
F_11 ( V_63 , V_361 ) ;
F_12 ( V_63 ) ;
}
V_63 = V_255 ;
V_361 = V_2 -> V_9 [ V_36 ] ;
V_35 = F_180 ( NULL , V_19 , V_2 , & V_63 , V_36 ,
V_77 , & V_83 , 0 ) ;
if ( V_35 == - V_221 )
goto V_225;
if ( V_35 < 0 ) {
F_9 ( V_2 ) ;
goto V_226;
}
if ( ! V_2 -> V_239 ) {
V_35 = F_195 ( V_63 ) ;
if ( ! V_35 && V_132 ) {
F_12 ( V_63 ) ;
F_9 ( V_2 ) ;
F_262 () ;
goto V_225;
}
if ( ! V_35 ) {
F_3 ( V_2 ) ;
F_23 ( V_63 ) ;
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
F_11 ( V_255 , V_2 -> V_9 [ V_36 ] ) ;
F_12 ( V_255 ) ;
V_2 -> V_8 [ V_36 ] = V_63 ;
V_2 -> V_17 [ V_36 ] = 0 ;
if ( ! V_2 -> V_239 )
V_2 -> V_9 [ V_36 ] = V_361 ;
if ( ! V_36 )
break;
V_35 = F_180 ( NULL , V_19 , V_2 , & V_63 , V_36 ,
0 , & V_83 , 0 ) ;
if ( V_35 == - V_221 )
goto V_225;
if ( V_35 < 0 ) {
F_9 ( V_2 ) ;
goto V_226;
}
if ( ! V_2 -> V_239 ) {
V_35 = F_195 ( V_63 ) ;
if ( ! V_35 ) {
F_3 ( V_2 ) ;
F_23 ( V_63 ) ;
F_5 ( V_2 , V_63 ,
V_10 ) ;
}
V_361 = V_10 ;
}
}
V_35 = 0 ;
V_226:
F_178 ( V_2 , 0 , 1 , 0 , NULL ) ;
V_2 -> V_243 = V_360 ;
if ( ! V_360 )
F_3 ( V_2 ) ;
return V_35 ;
}
int F_263 ( struct V_18 * V_19 ,
struct V_1 * V_2 , T_2 V_362 ,
int type )
{
struct V_155 V_233 ;
struct V_14 * V_172 ;
T_4 V_96 ;
int V_35 ;
while ( 1 ) {
if ( V_2 -> V_17 [ 0 ] == 0 ) {
F_3 ( V_2 ) ;
V_35 = F_200 ( V_19 , V_2 ) ;
if ( V_35 != 0 )
return V_35 ;
} else {
V_2 -> V_17 [ 0 ] -- ;
}
V_172 = V_2 -> V_8 [ 0 ] ;
V_96 = F_88 ( V_172 ) ;
if ( V_96 == 0 )
return 1 ;
if ( V_2 -> V_17 [ 0 ] == V_96 )
V_2 -> V_17 [ 0 ] -- ;
F_191 ( V_172 , & V_233 , V_2 -> V_17 [ 0 ] ) ;
if ( V_233 . V_124 < V_362 )
break;
if ( V_233 . type == type )
return 0 ;
if ( V_233 . V_124 == V_362 &&
V_233 . type < type )
break;
}
return 1 ;
}
int F_264 ( struct V_18 * V_19 ,
struct V_1 * V_2 , T_2 V_362 )
{
struct V_155 V_233 ;
struct V_14 * V_172 ;
T_4 V_96 ;
int V_35 ;
while ( 1 ) {
if ( V_2 -> V_17 [ 0 ] == 0 ) {
F_3 ( V_2 ) ;
V_35 = F_200 ( V_19 , V_2 ) ;
if ( V_35 != 0 )
return V_35 ;
} else {
V_2 -> V_17 [ 0 ] -- ;
}
V_172 = V_2 -> V_8 [ 0 ] ;
V_96 = F_88 ( V_172 ) ;
if ( V_96 == 0 )
return 1 ;
if ( V_2 -> V_17 [ 0 ] == V_96 )
V_2 -> V_17 [ 0 ] -- ;
F_191 ( V_172 , & V_233 , V_2 -> V_17 [ 0 ] ) ;
if ( V_233 . V_124 < V_362 )
break;
if ( V_233 . type == V_363 ||
V_233 . type == V_364 )
return 0 ;
if ( V_233 . V_124 == V_362 &&
V_233 . type < V_363 )
break;
}
return 1 ;
}
