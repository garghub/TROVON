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
if ( V_19 -> V_25 && F_27 ( & V_19 -> V_26 ) ) {
F_28 ( & V_19 -> V_26 ,
& V_19 -> V_23 -> V_27 ) ;
}
F_29 ( & V_19 -> V_23 -> V_24 ) ;
}
int F_30 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_14 * V_30 ,
struct V_14 * * V_31 , T_2 V_32 )
{
struct V_14 * V_33 ;
int V_34 = 0 ;
int V_35 ;
struct V_36 V_37 ;
F_31 ( V_19 -> V_38 && V_29 -> V_39 !=
V_19 -> V_23 -> V_40 -> V_39 ) ;
F_31 ( V_19 -> V_38 && V_29 -> V_39 != V_19 -> V_41 ) ;
V_35 = F_32 ( V_30 ) ;
if ( V_35 == 0 )
F_33 ( V_30 , & V_37 , 0 ) ;
else
F_34 ( V_30 , & V_37 , 0 ) ;
V_33 = F_35 ( V_29 , V_19 , V_30 -> V_42 , 0 ,
V_32 , & V_37 , V_35 ,
V_30 -> V_43 , 0 ) ;
if ( F_36 ( V_33 ) )
return F_37 ( V_33 ) ;
F_38 ( V_33 , V_30 , 0 , 0 , V_33 -> V_42 ) ;
F_39 ( V_33 , V_33 -> V_43 ) ;
F_40 ( V_33 , V_29 -> V_39 ) ;
F_41 ( V_33 , V_44 ) ;
F_42 ( V_33 , V_45 |
V_46 ) ;
if ( V_32 == V_47 )
F_43 ( V_33 , V_46 ) ;
else
F_44 ( V_33 , V_32 ) ;
F_45 ( V_33 , V_19 -> V_23 -> V_48 , F_46 () ,
V_49 ) ;
F_31 ( F_47 ( V_30 ) > V_29 -> V_39 ) ;
if ( V_32 == V_47 )
V_34 = F_48 ( V_29 , V_19 , V_33 , 1 , 1 ) ;
else
V_34 = F_48 ( V_29 , V_19 , V_33 , 0 , 1 ) ;
if ( V_34 )
return V_34 ;
F_49 ( V_33 ) ;
* V_31 = V_33 ;
return 0 ;
}
static inline void F_50 ( struct V_50 * V_23 )
{
F_51 ( & V_23 -> V_51 ) ;
}
static inline void F_52 ( struct V_50 * V_23 )
{
F_53 ( & V_23 -> V_51 ) ;
}
static inline void F_54 ( struct V_50 * V_23 )
{
F_55 ( & V_23 -> V_51 ) ;
}
static inline void F_56 ( struct V_50 * V_23 )
{
F_57 ( & V_23 -> V_51 ) ;
}
static inline T_2 F_58 ( struct V_50 * V_23 )
{
T_2 V_52 = F_59 ( & V_23 -> V_53 ) ;
V_52 &= 0xffffffff00000000ull ;
V_52 += 1ull << 32 ;
F_60 ( & V_23 -> V_53 , V_52 ) ;
return V_52 ;
}
static inline T_2 F_61 ( struct V_50 * V_23 )
{
return F_62 ( & V_23 -> V_53 ) ;
}
T_2 F_63 ( T_2 V_52 )
{
return ( V_52 & 0xffffffff00000000ull ) - 1ull ;
}
T_2 F_64 ( struct V_50 * V_23 ,
struct V_54 * V_55 )
{
T_2 V_52 ;
F_54 ( V_23 ) ;
F_26 ( & V_23 -> V_56 ) ;
if ( ! V_55 -> V_52 ) {
V_55 -> V_52 = F_58 ( V_23 ) ;
F_65 ( & V_55 -> V_57 , & V_23 -> V_58 ) ;
}
V_52 = F_61 ( V_23 ) ;
F_29 ( & V_23 -> V_56 ) ;
F_56 ( V_23 ) ;
return V_52 ;
}
void F_66 ( struct V_50 * V_23 ,
struct V_54 * V_55 )
{
struct V_59 * V_60 ;
struct V_61 * V_21 ;
struct V_61 * V_62 ;
struct V_54 * V_63 ;
struct V_64 * V_65 ;
T_2 V_66 = ( T_2 ) - 1 ;
T_2 V_67 = V_55 -> V_52 ;
if ( ! V_67 )
return;
F_26 ( & V_23 -> V_56 ) ;
F_67 ( & V_55 -> V_57 ) ;
V_55 -> V_52 = 0 ;
F_68 (cur_elem, &fs_info->tree_mod_seq_list, list) {
if ( V_63 -> V_52 < V_66 ) {
if ( V_67 > V_63 -> V_52 ) {
F_29 ( & V_23 -> V_56 ) ;
return;
}
V_66 = V_63 -> V_52 ;
}
}
F_29 ( & V_23 -> V_56 ) ;
F_54 ( V_23 ) ;
V_60 = & V_23 -> V_68 ;
for ( V_21 = F_69 ( V_60 ) ; V_21 ; V_21 = V_62 ) {
V_62 = F_70 ( V_21 ) ;
V_65 = F_71 ( V_21 , struct V_64 , V_21 ) ;
if ( V_65 -> V_52 > V_66 )
continue;
F_72 ( V_21 , V_60 ) ;
F_73 ( V_65 ) ;
}
F_56 ( V_23 ) ;
}
static T_1 int
F_74 ( struct V_50 * V_23 , struct V_64 * V_65 )
{
struct V_59 * V_60 ;
struct V_61 * * V_69 ;
struct V_61 * V_70 = NULL ;
struct V_64 * V_71 ;
F_75 ( ! V_65 ) ;
F_26 ( & V_23 -> V_56 ) ;
V_65 -> V_52 = F_61 ( V_23 ) ;
F_29 ( & V_23 -> V_56 ) ;
V_60 = & V_23 -> V_68 ;
V_69 = & V_60 -> V_61 ;
while ( * V_69 ) {
V_71 = F_71 ( * V_69 , struct V_64 , V_21 ) ;
V_70 = * V_69 ;
if ( V_71 -> V_72 < V_65 -> V_72 )
V_69 = & ( ( * V_69 ) -> V_73 ) ;
else if ( V_71 -> V_72 > V_65 -> V_72 )
V_69 = & ( ( * V_69 ) -> V_74 ) ;
else if ( V_71 -> V_52 < V_65 -> V_52 )
V_69 = & ( ( * V_69 ) -> V_73 ) ;
else if ( V_71 -> V_52 > V_65 -> V_52 )
V_69 = & ( ( * V_69 ) -> V_74 ) ;
else
return - V_75 ;
}
F_76 ( & V_65 -> V_21 , V_70 , V_69 ) ;
F_77 ( & V_65 -> V_21 , V_60 ) ;
return 0 ;
}
static inline int F_78 ( struct V_50 * V_23 ,
struct V_14 * V_20 ) {
F_79 () ;
if ( F_27 ( & ( V_23 ) -> V_58 ) )
return 1 ;
if ( V_20 && F_32 ( V_20 ) == 0 )
return 1 ;
F_54 ( V_23 ) ;
if ( F_27 ( & ( V_23 ) -> V_58 ) ) {
F_56 ( V_23 ) ;
return 1 ;
}
return 0 ;
}
static inline int F_80 ( const struct V_50 * V_23 ,
struct V_14 * V_20 )
{
F_79 () ;
if ( F_27 ( & ( V_23 ) -> V_58 ) )
return 0 ;
if ( V_20 && F_32 ( V_20 ) == 0 )
return 0 ;
return 1 ;
}
static struct V_64 *
F_81 ( struct V_14 * V_20 , int V_76 ,
enum V_77 V_78 , T_3 V_79 )
{
struct V_64 * V_65 ;
V_65 = F_82 ( sizeof( * V_65 ) , V_79 ) ;
if ( ! V_65 )
return NULL ;
V_65 -> V_72 = V_20 -> V_43 >> V_80 ;
if ( V_78 != V_81 ) {
F_34 ( V_20 , & V_65 -> V_82 , V_76 ) ;
V_65 -> V_83 = F_83 ( V_20 , V_76 ) ;
}
V_65 -> V_78 = V_78 ;
V_65 -> V_76 = V_76 ;
V_65 -> V_84 = F_84 ( V_20 , V_76 ) ;
F_85 ( & V_65 -> V_21 ) ;
return V_65 ;
}
static T_1 int
F_86 ( struct V_50 * V_23 ,
struct V_14 * V_20 , int V_76 ,
enum V_77 V_78 , T_3 V_79 )
{
struct V_64 * V_65 ;
int V_34 ;
if ( ! F_80 ( V_23 , V_20 ) )
return 0 ;
V_65 = F_81 ( V_20 , V_76 , V_78 , V_79 ) ;
if ( ! V_65 )
return - V_85 ;
if ( F_78 ( V_23 , V_20 ) ) {
F_73 ( V_65 ) ;
return 0 ;
}
V_34 = F_74 ( V_23 , V_65 ) ;
F_56 ( V_23 ) ;
if ( V_34 )
F_73 ( V_65 ) ;
return V_34 ;
}
static T_1 int
F_87 ( struct V_50 * V_23 ,
struct V_14 * V_20 , int V_86 , int V_87 ,
int V_88 , T_3 V_79 )
{
struct V_64 * V_65 = NULL ;
struct V_64 * * V_89 = NULL ;
int V_34 = 0 ;
int V_6 ;
int V_90 = 0 ;
if ( ! F_80 ( V_23 , V_20 ) )
return 0 ;
V_89 = F_82 ( V_88 * sizeof( struct V_64 * ) , V_79 ) ;
if ( ! V_89 )
return - V_85 ;
V_65 = F_82 ( sizeof( * V_65 ) , V_79 ) ;
if ( ! V_65 ) {
V_34 = - V_85 ;
goto V_91;
}
V_65 -> V_72 = V_20 -> V_43 >> V_80 ;
V_65 -> V_76 = V_87 ;
V_65 -> V_92 . V_86 = V_86 ;
V_65 -> V_92 . V_88 = V_88 ;
V_65 -> V_78 = V_93 ;
for ( V_6 = 0 ; V_6 + V_86 < V_87 && V_6 < V_88 ; V_6 ++ ) {
V_89 [ V_6 ] = F_81 ( V_20 , V_6 + V_86 ,
V_94 , V_79 ) ;
if ( ! V_89 [ V_6 ] ) {
V_34 = - V_85 ;
goto V_91;
}
}
if ( F_78 ( V_23 , V_20 ) )
goto V_91;
V_90 = 1 ;
for ( V_6 = 0 ; V_6 + V_86 < V_87 && V_6 < V_88 ; V_6 ++ ) {
V_34 = F_74 ( V_23 , V_89 [ V_6 ] ) ;
if ( V_34 )
goto V_91;
}
V_34 = F_74 ( V_23 , V_65 ) ;
if ( V_34 )
goto V_91;
F_56 ( V_23 ) ;
F_73 ( V_89 ) ;
return 0 ;
V_91:
for ( V_6 = 0 ; V_6 < V_88 ; V_6 ++ ) {
if ( V_89 [ V_6 ] && ! F_88 ( & V_89 [ V_6 ] -> V_21 ) )
F_72 ( & V_89 [ V_6 ] -> V_21 , & V_23 -> V_68 ) ;
F_73 ( V_89 [ V_6 ] ) ;
}
if ( V_90 )
F_56 ( V_23 ) ;
F_73 ( V_89 ) ;
F_73 ( V_65 ) ;
return V_34 ;
}
static inline int
F_89 ( struct V_50 * V_23 ,
struct V_64 * * V_89 ,
int V_95 )
{
int V_6 , V_96 ;
int V_34 ;
for ( V_6 = V_95 - 1 ; V_6 >= 0 ; V_6 -- ) {
V_34 = F_74 ( V_23 , V_89 [ V_6 ] ) ;
if ( V_34 ) {
for ( V_96 = V_95 - 1 ; V_96 > V_6 ; V_96 -- )
F_72 ( & V_89 [ V_96 ] -> V_21 ,
& V_23 -> V_68 ) ;
return V_34 ;
}
}
return 0 ;
}
static T_1 int
F_90 ( struct V_50 * V_23 ,
struct V_14 * V_97 ,
struct V_14 * V_98 , T_3 V_79 ,
int V_99 )
{
struct V_64 * V_65 = NULL ;
struct V_64 * * V_89 = NULL ;
int V_95 = 0 ;
int V_34 = 0 ;
int V_6 ;
if ( ! F_80 ( V_23 , NULL ) )
return 0 ;
if ( V_99 && F_32 ( V_97 ) > 0 ) {
V_95 = F_91 ( V_97 ) ;
V_89 = F_82 ( V_95 * sizeof( struct V_64 * ) ,
V_79 ) ;
if ( ! V_89 ) {
V_34 = - V_85 ;
goto V_91;
}
for ( V_6 = 0 ; V_6 < V_95 ; V_6 ++ ) {
V_89 [ V_6 ] = F_81 ( V_97 , V_6 ,
V_100 , V_79 ) ;
if ( ! V_89 [ V_6 ] ) {
V_34 = - V_85 ;
goto V_91;
}
}
}
V_65 = F_82 ( sizeof( * V_65 ) , V_79 ) ;
if ( ! V_65 ) {
V_34 = - V_85 ;
goto V_91;
}
V_65 -> V_72 = V_98 -> V_43 >> V_80 ;
V_65 -> V_97 . V_101 = V_97 -> V_43 ;
V_65 -> V_97 . V_35 = F_32 ( V_97 ) ;
V_65 -> V_84 = F_47 ( V_97 ) ;
V_65 -> V_78 = V_102 ;
if ( F_78 ( V_23 , NULL ) )
goto V_91;
if ( V_89 )
V_34 = F_89 ( V_23 , V_89 , V_95 ) ;
if ( ! V_34 )
V_34 = F_74 ( V_23 , V_65 ) ;
F_56 ( V_23 ) ;
if ( V_34 )
goto V_91;
F_73 ( V_89 ) ;
return V_34 ;
V_91:
if ( V_89 ) {
for ( V_6 = 0 ; V_6 < V_95 ; V_6 ++ )
F_73 ( V_89 [ V_6 ] ) ;
F_73 ( V_89 ) ;
}
F_73 ( V_65 ) ;
return V_34 ;
}
static struct V_64 *
F_92 ( struct V_50 * V_23 , T_2 V_43 , T_2 V_66 ,
int V_103 )
{
struct V_59 * V_60 ;
struct V_61 * V_21 ;
struct V_64 * V_71 = NULL ;
struct V_64 * V_104 = NULL ;
T_2 V_72 = V_43 >> V_80 ;
F_50 ( V_23 ) ;
V_60 = & V_23 -> V_68 ;
V_21 = V_60 -> V_61 ;
while ( V_21 ) {
V_71 = F_71 ( V_21 , struct V_64 , V_21 ) ;
if ( V_71 -> V_72 < V_72 ) {
V_21 = V_21 -> V_73 ;
} else if ( V_71 -> V_72 > V_72 ) {
V_21 = V_21 -> V_74 ;
} else if ( V_71 -> V_52 < V_66 ) {
V_21 = V_21 -> V_73 ;
} else if ( ! V_103 ) {
if ( V_104 )
F_75 ( V_104 -> V_52 > V_71 -> V_52 ) ;
V_104 = V_71 ;
V_21 = V_21 -> V_73 ;
} else if ( V_71 -> V_52 > V_66 ) {
if ( V_104 )
F_75 ( V_104 -> V_52 < V_71 -> V_52 ) ;
V_104 = V_71 ;
V_21 = V_21 -> V_74 ;
} else {
V_104 = V_71 ;
break;
}
}
F_52 ( V_23 ) ;
return V_104 ;
}
static struct V_64 *
F_93 ( struct V_50 * V_23 , T_2 V_43 ,
T_2 V_66 )
{
return F_92 ( V_23 , V_43 , V_66 , 1 ) ;
}
static struct V_64 *
F_94 ( struct V_50 * V_23 , T_2 V_43 , T_2 V_66 )
{
return F_92 ( V_23 , V_43 , V_66 , 0 ) ;
}
static T_1 int
F_95 ( struct V_50 * V_23 , struct V_14 * V_105 ,
struct V_14 * V_106 , unsigned long V_107 ,
unsigned long V_108 , int V_88 )
{
int V_34 = 0 ;
struct V_64 * * V_89 = NULL ;
struct V_64 * * V_109 , * * V_110 ;
int V_6 ;
int V_90 = 0 ;
if ( ! F_80 ( V_23 , NULL ) )
return 0 ;
if ( F_32 ( V_105 ) == 0 && F_32 ( V_106 ) == 0 )
return 0 ;
V_89 = F_82 ( V_88 * 2 * sizeof( struct V_64 * ) ,
V_4 ) ;
if ( ! V_89 )
return - V_85 ;
V_109 = V_89 ;
V_110 = V_89 + V_88 ;
for ( V_6 = 0 ; V_6 < V_88 ; V_6 ++ ) {
V_110 [ V_6 ] = F_81 ( V_106 , V_6 + V_108 ,
V_111 , V_4 ) ;
if ( ! V_110 [ V_6 ] ) {
V_34 = - V_85 ;
goto V_91;
}
V_109 [ V_6 ] = F_81 ( V_105 , V_6 + V_107 ,
V_81 , V_4 ) ;
if ( ! V_109 [ V_6 ] ) {
V_34 = - V_85 ;
goto V_91;
}
}
if ( F_78 ( V_23 , NULL ) )
goto V_91;
V_90 = 1 ;
for ( V_6 = 0 ; V_6 < V_88 ; V_6 ++ ) {
V_34 = F_74 ( V_23 , V_110 [ V_6 ] ) ;
if ( V_34 )
goto V_91;
V_34 = F_74 ( V_23 , V_109 [ V_6 ] ) ;
if ( V_34 )
goto V_91;
}
F_56 ( V_23 ) ;
F_73 ( V_89 ) ;
return 0 ;
V_91:
for ( V_6 = 0 ; V_6 < V_88 * 2 ; V_6 ++ ) {
if ( V_89 [ V_6 ] && ! F_88 ( & V_89 [ V_6 ] -> V_21 ) )
F_72 ( & V_89 [ V_6 ] -> V_21 , & V_23 -> V_68 ) ;
F_73 ( V_89 [ V_6 ] ) ;
}
if ( V_90 )
F_56 ( V_23 ) ;
F_73 ( V_89 ) ;
return V_34 ;
}
static inline void
F_96 ( struct V_50 * V_23 , struct V_14 * V_105 ,
int V_107 , int V_108 , int V_88 )
{
int V_34 ;
V_34 = F_87 ( V_23 , V_105 , V_107 , V_108 ,
V_88 , V_4 ) ;
F_75 ( V_34 < 0 ) ;
}
static T_1 void
F_97 ( struct V_50 * V_23 ,
struct V_14 * V_20 , int V_76 , int V_112 )
{
int V_34 ;
V_34 = F_86 ( V_23 , V_20 , V_76 ,
V_113 ,
V_112 ? V_114 : V_4 ) ;
F_75 ( V_34 < 0 ) ;
}
static T_1 int
F_98 ( struct V_50 * V_23 , struct V_14 * V_20 )
{
struct V_64 * * V_89 = NULL ;
int V_95 = 0 ;
int V_6 ;
int V_34 = 0 ;
if ( F_32 ( V_20 ) == 0 )
return 0 ;
if ( ! F_80 ( V_23 , NULL ) )
return 0 ;
V_95 = F_91 ( V_20 ) ;
V_89 = F_82 ( V_95 * sizeof( struct V_64 * ) ,
V_4 ) ;
if ( ! V_89 )
return - V_85 ;
for ( V_6 = 0 ; V_6 < V_95 ; V_6 ++ ) {
V_89 [ V_6 ] = F_81 ( V_20 , V_6 ,
V_100 , V_4 ) ;
if ( ! V_89 [ V_6 ] ) {
V_34 = - V_85 ;
goto V_91;
}
}
if ( F_78 ( V_23 , V_20 ) )
goto V_91;
V_34 = F_89 ( V_23 , V_89 , V_95 ) ;
F_56 ( V_23 ) ;
if ( V_34 )
goto V_91;
F_73 ( V_89 ) ;
return 0 ;
V_91:
for ( V_6 = 0 ; V_6 < V_95 ; V_6 ++ )
F_73 ( V_89 [ V_6 ] ) ;
F_73 ( V_89 ) ;
return V_34 ;
}
static T_1 void
F_99 ( struct V_18 * V_19 ,
struct V_14 * V_115 ,
int V_99 )
{
int V_34 ;
V_34 = F_90 ( V_19 -> V_23 , V_19 -> V_21 ,
V_115 , V_4 , V_99 ) ;
F_75 ( V_34 < 0 ) ;
}
int F_100 ( struct V_18 * V_19 ,
struct V_14 * V_30 )
{
if ( V_19 -> V_38 &&
V_30 != V_19 -> V_21 && V_30 != V_19 -> V_116 &&
( F_47 ( V_30 ) <=
F_101 ( & V_19 -> V_117 ) ||
F_102 ( V_30 , V_46 ) ) )
return 1 ;
#ifdef F_103
if ( V_19 -> V_38 &&
F_104 ( V_30 ) < V_44 )
return 1 ;
#endif
return 0 ;
}
static T_1 int F_105 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_14 * V_30 ,
struct V_14 * V_33 ,
int * V_118 )
{
T_2 V_22 ;
T_2 V_119 ;
T_2 V_79 ;
T_2 V_120 = 0 ;
int V_34 ;
if ( F_100 ( V_19 , V_30 ) ) {
V_34 = F_106 ( V_29 , V_19 , V_30 -> V_43 ,
F_32 ( V_30 ) , 1 ,
& V_22 , & V_79 ) ;
if ( V_34 )
return V_34 ;
if ( V_22 == 0 ) {
V_34 = - V_121 ;
F_107 ( V_19 -> V_23 , V_34 ) ;
return V_34 ;
}
} else {
V_22 = 1 ;
if ( V_19 -> V_122 . V_123 == V_47 ||
F_104 ( V_30 ) < V_44 )
V_79 = V_124 ;
else
V_79 = 0 ;
}
V_119 = F_108 ( V_30 ) ;
F_75 ( V_119 == V_47 &&
! ( V_79 & V_124 ) ) ;
if ( V_22 > 1 ) {
if ( ( V_119 == V_19 -> V_122 . V_123 ||
V_19 -> V_122 . V_123 == V_47 ) &&
! ( V_79 & V_124 ) ) {
V_34 = F_48 ( V_29 , V_19 , V_30 , 1 , 1 ) ;
F_75 ( V_34 ) ;
if ( V_19 -> V_122 . V_123 ==
V_47 ) {
V_34 = F_109 ( V_29 , V_19 , V_30 , 0 , 1 ) ;
F_75 ( V_34 ) ;
V_34 = F_48 ( V_29 , V_19 , V_33 , 1 , 1 ) ;
F_75 ( V_34 ) ;
}
V_120 |= V_124 ;
} else {
if ( V_19 -> V_122 . V_123 ==
V_47 )
V_34 = F_48 ( V_29 , V_19 , V_33 , 1 , 1 ) ;
else
V_34 = F_48 ( V_29 , V_19 , V_33 , 0 , 1 ) ;
F_75 ( V_34 ) ;
}
if ( V_120 != 0 ) {
int V_35 = F_32 ( V_30 ) ;
V_34 = F_110 ( V_29 , V_19 ,
V_30 -> V_43 ,
V_30 -> V_42 ,
V_120 , V_35 , 0 ) ;
if ( V_34 )
return V_34 ;
}
} else {
if ( V_79 & V_124 ) {
if ( V_19 -> V_122 . V_123 ==
V_47 )
V_34 = F_48 ( V_29 , V_19 , V_33 , 1 , 1 ) ;
else
V_34 = F_48 ( V_29 , V_19 , V_33 , 0 , 1 ) ;
F_75 ( V_34 ) ;
V_34 = F_109 ( V_29 , V_19 , V_30 , 1 , 1 ) ;
F_75 ( V_34 ) ;
}
F_111 ( V_29 , V_19 , V_30 ) ;
* V_118 = 1 ;
}
return 0 ;
}
static T_1 int F_112 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_14 * V_30 ,
struct V_14 * V_70 , int V_125 ,
struct V_14 * * V_31 ,
T_2 V_126 , T_2 V_127 )
{
struct V_36 V_37 ;
struct V_14 * V_33 ;
int V_35 , V_34 ;
int V_118 = 0 ;
int V_128 = 0 ;
T_2 V_129 ;
if ( * V_31 == V_30 )
V_128 = 1 ;
F_113 ( V_30 ) ;
F_31 ( V_19 -> V_38 && V_29 -> V_39 !=
V_19 -> V_23 -> V_40 -> V_39 ) ;
F_31 ( V_19 -> V_38 && V_29 -> V_39 != V_19 -> V_41 ) ;
V_35 = F_32 ( V_30 ) ;
if ( V_35 == 0 )
F_33 ( V_30 , & V_37 , 0 ) ;
else
F_34 ( V_30 , & V_37 , 0 ) ;
if ( V_19 -> V_122 . V_123 == V_47 ) {
if ( V_70 )
V_129 = V_70 -> V_43 ;
else
V_129 = 0 ;
} else
V_129 = 0 ;
V_33 = F_35 ( V_29 , V_19 , V_30 -> V_42 , V_129 ,
V_19 -> V_122 . V_123 , & V_37 ,
V_35 , V_126 , V_127 ) ;
if ( F_36 ( V_33 ) )
return F_37 ( V_33 ) ;
F_38 ( V_33 , V_30 , 0 , 0 , V_33 -> V_42 ) ;
F_39 ( V_33 , V_33 -> V_43 ) ;
F_40 ( V_33 , V_29 -> V_39 ) ;
F_41 ( V_33 , V_44 ) ;
F_42 ( V_33 , V_45 |
V_46 ) ;
if ( V_19 -> V_122 . V_123 == V_47 )
F_43 ( V_33 , V_46 ) ;
else
F_44 ( V_33 , V_19 -> V_122 . V_123 ) ;
F_45 ( V_33 , V_19 -> V_23 -> V_48 , F_46 () ,
V_49 ) ;
V_34 = F_105 ( V_29 , V_19 , V_30 , V_33 , & V_118 ) ;
if ( V_34 ) {
F_114 ( V_29 , V_19 , V_34 ) ;
return V_34 ;
}
if ( V_19 -> V_38 ) {
V_34 = F_115 ( V_29 , V_19 , V_30 , V_33 ) ;
if ( V_34 )
return V_34 ;
}
if ( V_30 == V_19 -> V_21 ) {
F_31 ( V_70 && V_70 != V_30 ) ;
if ( V_19 -> V_122 . V_123 == V_47 ||
F_104 ( V_30 ) < V_44 )
V_129 = V_30 -> V_43 ;
else
V_129 = 0 ;
F_116 ( V_33 ) ;
F_99 ( V_19 , V_33 , 1 ) ;
F_117 ( V_19 -> V_21 , V_33 ) ;
F_118 ( V_29 , V_19 , V_30 , V_129 ,
V_118 ) ;
F_12 ( V_30 ) ;
F_25 ( V_19 ) ;
} else {
if ( V_19 -> V_122 . V_123 == V_47 )
V_129 = V_70 -> V_43 ;
else
V_129 = 0 ;
F_31 ( V_29 -> V_39 != F_47 ( V_70 ) ) ;
F_86 ( V_19 -> V_23 , V_70 , V_125 ,
V_113 , V_4 ) ;
F_119 ( V_70 , V_125 ,
V_33 -> V_43 ) ;
F_120 ( V_70 , V_125 ,
V_29 -> V_39 ) ;
F_49 ( V_70 ) ;
if ( V_118 ) {
V_34 = F_98 ( V_19 -> V_23 , V_30 ) ;
if ( V_34 ) {
F_114 ( V_29 , V_19 , V_34 ) ;
return V_34 ;
}
}
F_118 ( V_29 , V_19 , V_30 , V_129 ,
V_118 ) ;
}
if ( V_128 )
F_21 ( V_30 ) ;
F_121 ( V_30 ) ;
F_49 ( V_33 ) ;
* V_31 = V_33 ;
return 0 ;
}
static struct V_64 *
F_122 ( struct V_50 * V_23 ,
struct V_14 * V_130 , T_2 V_131 )
{
struct V_64 * V_65 ;
struct V_64 * V_104 = NULL ;
T_2 V_132 = V_130 -> V_43 ;
int V_133 = 0 ;
if ( ! V_131 )
return NULL ;
while ( 1 ) {
V_65 = F_93 ( V_23 , V_132 ,
V_131 ) ;
if ( ! V_133 && ! V_65 )
return NULL ;
if ( ! V_65 )
break;
if ( V_65 -> V_78 != V_102 )
break;
V_104 = V_65 ;
V_132 = V_65 -> V_97 . V_101 ;
V_133 = 1 ;
}
if ( ! V_104 )
V_104 = V_65 ;
return V_104 ;
}
static void
F_123 ( struct V_50 * V_23 , struct V_14 * V_20 ,
T_2 V_131 , struct V_64 * V_134 )
{
T_4 V_135 ;
struct V_61 * V_62 ;
struct V_64 * V_65 = V_134 ;
unsigned long V_136 ;
unsigned long V_137 ;
unsigned long V_138 = sizeof( struct V_139 ) ;
V_135 = F_91 ( V_20 ) ;
F_50 ( V_23 ) ;
while ( V_65 && V_65 -> V_52 >= V_131 ) {
switch ( V_65 -> V_78 ) {
case V_100 :
F_75 ( V_65 -> V_76 < V_135 ) ;
case V_94 :
case V_111 :
F_124 ( V_20 , & V_65 -> V_82 , V_65 -> V_76 ) ;
F_119 ( V_20 , V_65 -> V_76 , V_65 -> V_83 ) ;
F_120 ( V_20 , V_65 -> V_76 ,
V_65 -> V_84 ) ;
V_135 ++ ;
break;
case V_113 :
F_75 ( V_65 -> V_76 >= V_135 ) ;
F_124 ( V_20 , & V_65 -> V_82 , V_65 -> V_76 ) ;
F_119 ( V_20 , V_65 -> V_76 , V_65 -> V_83 ) ;
F_120 ( V_20 , V_65 -> V_76 ,
V_65 -> V_84 ) ;
break;
case V_81 :
V_135 -- ;
break;
case V_93 :
V_136 = F_125 ( V_65 -> V_76 ) ;
V_137 = F_125 ( V_65 -> V_92 . V_86 ) ;
F_126 ( V_20 , V_136 , V_137 ,
V_65 -> V_92 . V_88 * V_138 ) ;
break;
case V_102 :
break;
}
V_62 = F_70 ( & V_65 -> V_21 ) ;
if ( ! V_62 )
break;
V_65 = F_71 ( V_62 , struct V_64 , V_21 ) ;
if ( V_65 -> V_72 != V_134 -> V_72 )
break;
}
F_52 ( V_23 ) ;
F_127 ( V_20 , V_135 ) ;
}
static struct V_14 *
F_128 ( struct V_50 * V_23 , struct V_1 * V_2 ,
struct V_14 * V_20 , T_2 V_131 )
{
struct V_14 * V_140 ;
struct V_64 * V_65 ;
if ( ! V_131 )
return V_20 ;
if ( F_32 ( V_20 ) == 0 )
return V_20 ;
V_65 = F_94 ( V_23 , V_20 -> V_43 , V_131 ) ;
if ( ! V_65 )
return V_20 ;
F_3 ( V_2 ) ;
F_4 ( V_20 , V_10 ) ;
if ( V_65 -> V_78 == V_100 ) {
F_75 ( V_65 -> V_76 != 0 ) ;
V_140 = F_129 ( V_20 -> V_43 ,
V_23 -> V_141 -> V_142 ) ;
if ( ! V_140 ) {
F_130 ( V_20 ) ;
F_12 ( V_20 ) ;
return NULL ;
}
F_39 ( V_140 , V_20 -> V_43 ) ;
F_41 ( V_140 ,
F_104 ( V_20 ) ) ;
F_44 ( V_140 , F_108 ( V_20 ) ) ;
F_131 ( V_140 , F_32 ( V_20 ) ) ;
} else {
V_140 = F_132 ( V_20 ) ;
if ( ! V_140 ) {
F_130 ( V_20 ) ;
F_12 ( V_20 ) ;
return NULL ;
}
}
F_5 ( V_2 , NULL , V_10 ) ;
F_130 ( V_20 ) ;
F_12 ( V_20 ) ;
F_116 ( V_140 ) ;
F_23 ( V_140 ) ;
F_123 ( V_23 , V_140 , V_131 , V_65 ) ;
F_31 ( F_91 ( V_140 ) >
F_133 ( V_23 -> V_141 ) ) ;
return V_140 ;
}
static inline struct V_14 *
F_134 ( struct V_18 * V_19 , T_2 V_131 )
{
struct V_64 * V_65 ;
struct V_14 * V_20 = NULL ;
struct V_14 * V_130 ;
struct V_14 * V_143 ;
struct V_144 * V_97 = NULL ;
T_2 V_145 = 0 ;
T_2 V_101 ;
T_4 V_146 ;
V_130 = F_22 ( V_19 ) ;
V_65 = F_122 ( V_19 -> V_23 , V_130 , V_131 ) ;
if ( ! V_65 )
return V_130 ;
if ( V_65 -> V_78 == V_102 ) {
V_97 = & V_65 -> V_97 ;
V_145 = V_65 -> V_84 ;
V_101 = V_97 -> V_101 ;
} else {
V_101 = V_130 -> V_43 ;
}
V_65 = F_94 ( V_19 -> V_23 , V_101 , V_131 ) ;
if ( V_97 && V_65 && V_65 -> V_78 != V_100 ) {
F_24 ( V_130 ) ;
F_12 ( V_130 ) ;
V_146 = F_135 ( V_19 , V_97 -> V_35 ) ;
V_143 = F_136 ( V_19 , V_101 , V_146 , 0 ) ;
if ( F_31 ( ! V_143 || ! F_137 ( V_143 ) ) ) {
F_12 ( V_143 ) ;
F_138 ( V_19 -> V_23 ,
L_1 , V_101 ) ;
} else {
V_20 = F_132 ( V_143 ) ;
F_12 ( V_143 ) ;
}
} else if ( V_97 ) {
F_24 ( V_130 ) ;
F_12 ( V_130 ) ;
V_20 = F_129 ( V_101 , V_19 -> V_142 ) ;
} else {
F_4 ( V_130 , V_10 ) ;
V_20 = F_132 ( V_130 ) ;
F_130 ( V_130 ) ;
F_12 ( V_130 ) ;
}
if ( ! V_20 )
return NULL ;
F_116 ( V_20 ) ;
F_23 ( V_20 ) ;
if ( V_97 ) {
F_39 ( V_20 , V_20 -> V_43 ) ;
F_41 ( V_20 , V_44 ) ;
F_44 ( V_20 , F_108 ( V_130 ) ) ;
F_131 ( V_20 , V_97 -> V_35 ) ;
F_40 ( V_20 , V_145 ) ;
}
if ( V_65 )
F_123 ( V_19 -> V_23 , V_20 , V_131 , V_65 ) ;
else
F_31 ( F_32 ( V_20 ) != 0 ) ;
F_31 ( F_91 ( V_20 ) > F_133 ( V_19 ) ) ;
return V_20 ;
}
int F_139 ( struct V_18 * V_19 , T_2 V_131 )
{
struct V_64 * V_65 ;
int V_35 ;
struct V_14 * V_130 = F_13 ( V_19 ) ;
V_65 = F_122 ( V_19 -> V_23 , V_130 , V_131 ) ;
if ( V_65 && V_65 -> V_78 == V_102 ) {
V_35 = V_65 -> V_97 . V_35 ;
} else {
V_35 = F_32 ( V_130 ) ;
}
F_12 ( V_130 ) ;
return V_35 ;
}
static inline int F_140 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_14 * V_30 )
{
F_141 () ;
if ( F_47 ( V_30 ) == V_29 -> V_39 &&
! F_102 ( V_30 , V_45 ) &&
! ( V_19 -> V_122 . V_123 != V_47 &&
F_102 ( V_30 , V_46 ) ) &&
! V_19 -> V_147 )
return 0 ;
return 1 ;
}
T_1 int F_142 ( struct V_28 * V_29 ,
struct V_18 * V_19 , struct V_14 * V_30 ,
struct V_14 * V_70 , int V_125 ,
struct V_14 * * V_31 )
{
T_2 V_126 ;
int V_34 ;
if ( V_29 -> V_148 != V_19 -> V_23 -> V_40 )
F_143 ( 1 , V_149 L_2 ,
V_29 -> V_39 ,
V_19 -> V_23 -> V_40 -> V_39 ) ;
if ( V_29 -> V_39 != V_19 -> V_23 -> V_84 )
F_143 ( 1 , V_149 L_2 ,
V_29 -> V_39 , V_19 -> V_23 -> V_84 ) ;
if ( ! F_140 ( V_29 , V_19 , V_30 ) ) {
* V_31 = V_30 ;
return 0 ;
}
V_126 = V_30 -> V_43 & ~ ( ( T_2 ) ( 1024 * 1024 * 1024 ) - 1 ) ;
if ( V_70 )
F_144 ( V_70 ) ;
F_144 ( V_30 ) ;
V_34 = F_112 ( V_29 , V_19 , V_30 , V_70 ,
V_125 , V_31 , V_126 , 0 ) ;
F_145 ( V_19 , V_30 , * V_31 ) ;
return V_34 ;
}
static int F_146 ( T_2 V_150 , T_2 V_151 , T_4 V_146 )
{
if ( V_150 < V_151 && V_151 - ( V_150 + V_146 ) < 32768 )
return 1 ;
if ( V_150 > V_151 && V_150 - ( V_151 + V_146 ) < 32768 )
return 1 ;
return 0 ;
}
static int F_147 ( struct V_36 * V_152 , struct V_153 * V_154 )
{
struct V_153 V_155 ;
F_148 ( & V_155 , V_152 ) ;
return F_149 ( & V_155 , V_154 ) ;
}
int F_149 ( struct V_153 * V_155 , struct V_153 * V_154 )
{
if ( V_155 -> V_123 > V_154 -> V_123 )
return 1 ;
if ( V_155 -> V_123 < V_154 -> V_123 )
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
int F_150 ( struct V_28 * V_29 ,
struct V_18 * V_19 , struct V_14 * V_70 ,
int V_157 , T_2 * V_158 ,
struct V_153 * V_159 )
{
struct V_14 * V_71 ;
T_2 V_150 ;
T_2 V_160 ;
T_2 V_126 = * V_158 ;
T_2 V_161 = 0 ;
T_2 V_151 ;
T_4 V_162 ;
int V_163 ;
int V_6 ;
int V_164 = 0 ;
int V_165 ;
int V_166 ;
T_4 V_146 ;
int V_167 = 0 ;
struct V_36 V_37 ;
V_165 = F_32 ( V_70 ) ;
F_31 ( V_29 -> V_148 != V_19 -> V_23 -> V_40 ) ;
F_31 ( V_29 -> V_39 != V_19 -> V_23 -> V_84 ) ;
V_162 = F_91 ( V_70 ) ;
V_146 = F_135 ( V_19 , V_165 - 1 ) ;
V_163 = V_162 ;
if ( V_162 == 1 )
return 0 ;
F_144 ( V_70 ) ;
for ( V_6 = V_157 ; V_6 < V_163 ; V_6 ++ ) {
int V_168 = 1 ;
F_34 ( V_70 , & V_37 , V_6 ) ;
if ( ! V_167 && F_147 ( & V_37 , V_159 ) < 0 )
continue;
V_167 = 1 ;
V_150 = F_83 ( V_70 , V_6 ) ;
V_160 = F_84 ( V_70 , V_6 ) ;
if ( V_161 == 0 )
V_161 = V_150 ;
if ( V_6 > 0 ) {
V_151 = F_83 ( V_70 , V_6 - 1 ) ;
V_168 = F_146 ( V_150 , V_151 , V_146 ) ;
}
if ( ! V_168 && V_6 < V_163 - 2 ) {
V_151 = F_83 ( V_70 , V_6 + 1 ) ;
V_168 = F_146 ( V_150 , V_151 , V_146 ) ;
}
if ( V_168 ) {
V_161 = V_150 ;
continue;
}
V_71 = F_151 ( V_19 , V_150 , V_146 ) ;
if ( V_71 )
V_166 = F_152 ( V_71 , V_160 , 0 ) ;
else
V_166 = 0 ;
if ( ! V_71 || ! V_166 ) {
if ( ! V_71 ) {
V_71 = F_136 ( V_19 , V_150 ,
V_146 , V_160 ) ;
if ( ! V_71 || ! F_137 ( V_71 ) ) {
F_12 ( V_71 ) ;
return - V_169 ;
}
} else if ( ! V_166 ) {
V_164 = F_153 ( V_71 , V_160 ) ;
if ( V_164 ) {
F_12 ( V_71 ) ;
return V_164 ;
}
}
}
if ( V_126 == 0 )
V_126 = V_161 ;
F_20 ( V_71 ) ;
F_144 ( V_71 ) ;
V_164 = F_112 ( V_29 , V_19 , V_71 , V_70 , V_6 ,
& V_71 , V_126 ,
F_154 ( 16 * V_146 ,
( V_163 - V_6 ) * V_146 ) ) ;
if ( V_164 ) {
F_21 ( V_71 ) ;
F_12 ( V_71 ) ;
break;
}
V_126 = V_71 -> V_43 ;
V_161 = V_71 -> V_43 ;
* V_158 = V_126 ;
F_21 ( V_71 ) ;
F_12 ( V_71 ) ;
}
return V_164 ;
}
static inline unsigned int F_155 ( struct V_18 * V_19 ,
struct V_14 * V_170 )
{
T_4 V_171 = F_91 ( V_170 ) ;
if ( V_171 == 0 )
return F_156 ( V_19 ) ;
return F_157 ( V_170 , V_171 - 1 ) ;
}
static T_1 int F_158 ( struct V_14 * V_20 ,
unsigned long V_5 ,
int V_172 , struct V_153 * V_82 ,
int V_173 , int * V_76 )
{
int V_174 = 0 ;
int V_175 = V_173 ;
int V_176 ;
int V_34 ;
struct V_36 * V_177 = NULL ;
struct V_36 V_178 ;
unsigned long V_156 ;
char * V_179 = NULL ;
unsigned long V_180 = 0 ;
unsigned long V_181 = 0 ;
int V_164 ;
while ( V_174 < V_175 ) {
V_176 = ( V_174 + V_175 ) / 2 ;
V_156 = V_5 + V_176 * V_172 ;
if ( ! V_179 || V_156 < V_180 ||
( V_156 + sizeof( struct V_36 ) ) >
V_180 + V_181 ) {
V_164 = F_159 ( V_20 , V_156 ,
sizeof( struct V_36 ) ,
& V_179 , & V_180 , & V_181 ) ;
if ( ! V_164 ) {
V_177 = (struct V_36 * ) ( V_179 + V_156 -
V_180 ) ;
} else {
F_160 ( V_20 , & V_178 ,
V_156 , sizeof( V_178 ) ) ;
V_177 = & V_178 ;
}
} else {
V_177 = (struct V_36 * ) ( V_179 + V_156 -
V_180 ) ;
}
V_34 = F_147 ( V_177 , V_82 ) ;
if ( V_34 < 0 )
V_174 = V_176 + 1 ;
else if ( V_34 > 0 )
V_175 = V_176 ;
else {
* V_76 = V_176 ;
return 0 ;
}
}
* V_76 = V_174 ;
return 1 ;
}
static int F_161 ( struct V_14 * V_20 , struct V_153 * V_82 ,
int V_35 , int * V_76 )
{
if ( V_35 == 0 )
return F_158 ( V_20 ,
F_162 ( struct V_182 , V_183 ) ,
sizeof( struct V_184 ) ,
V_82 , F_91 ( V_20 ) ,
V_76 ) ;
else
return F_158 ( V_20 ,
F_162 ( struct V_185 , V_186 ) ,
sizeof( struct V_139 ) ,
V_82 , F_91 ( V_20 ) ,
V_76 ) ;
}
int F_163 ( struct V_14 * V_20 , struct V_153 * V_82 ,
int V_35 , int * V_76 )
{
return F_161 ( V_20 , V_82 , V_35 , V_76 ) ;
}
static void F_164 ( struct V_18 * V_19 , T_4 V_187 )
{
F_26 ( & V_19 -> V_188 ) ;
F_165 ( & V_19 -> V_117 ,
F_166 ( & V_19 -> V_117 ) + V_187 ) ;
F_29 ( & V_19 -> V_188 ) ;
}
static void F_167 ( struct V_18 * V_19 , T_4 V_187 )
{
F_26 ( & V_19 -> V_188 ) ;
F_165 ( & V_19 -> V_117 ,
F_166 ( & V_19 -> V_117 ) - V_187 ) ;
F_29 ( & V_19 -> V_188 ) ;
}
T_1 int F_168 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_35 )
{
struct V_14 * V_189 = NULL ;
struct V_14 * V_176 ;
struct V_14 * V_190 = NULL ;
struct V_14 * V_70 = NULL ;
int V_34 = 0 ;
int V_191 ;
int V_192 ;
int V_193 = V_2 -> V_17 [ V_35 ] ;
T_2 V_194 ;
if ( V_35 == 0 )
return 0 ;
V_176 = V_2 -> V_8 [ V_35 ] ;
F_31 ( V_2 -> V_9 [ V_35 ] != V_12 &&
V_2 -> V_9 [ V_35 ] != V_13 ) ;
F_31 ( F_47 ( V_176 ) != V_29 -> V_39 ) ;
V_194 = F_83 ( V_176 , V_193 ) ;
if ( V_35 < V_7 - 1 ) {
V_70 = V_2 -> V_8 [ V_35 + 1 ] ;
V_192 = V_2 -> V_17 [ V_35 + 1 ] ;
}
if ( ! V_70 ) {
struct V_14 * V_195 ;
if ( F_91 ( V_176 ) != 1 )
return 0 ;
V_195 = F_169 ( V_19 , V_176 , 0 ) ;
if ( ! V_195 ) {
V_34 = - V_121 ;
F_107 ( V_19 -> V_23 , V_34 ) ;
goto V_196;
}
F_20 ( V_195 ) ;
F_144 ( V_195 ) ;
V_34 = F_142 ( V_29 , V_19 , V_195 , V_176 , 0 , & V_195 ) ;
if ( V_34 ) {
F_21 ( V_195 ) ;
F_12 ( V_195 ) ;
goto V_196;
}
F_99 ( V_19 , V_195 , 1 ) ;
F_117 ( V_19 -> V_21 , V_195 ) ;
F_25 ( V_19 ) ;
F_21 ( V_195 ) ;
V_2 -> V_9 [ V_35 ] = 0 ;
V_2 -> V_8 [ V_35 ] = NULL ;
F_111 ( V_29 , V_19 , V_176 ) ;
F_21 ( V_176 ) ;
F_12 ( V_176 ) ;
F_167 ( V_19 , V_176 -> V_42 ) ;
F_118 ( V_29 , V_19 , V_176 , 0 , 1 ) ;
F_121 ( V_176 ) ;
return 0 ;
}
if ( F_91 ( V_176 ) >
F_133 ( V_19 ) / 4 )
return 0 ;
V_190 = F_169 ( V_19 , V_70 , V_192 - 1 ) ;
if ( V_190 ) {
F_20 ( V_190 ) ;
F_144 ( V_190 ) ;
V_191 = F_142 ( V_29 , V_19 , V_190 ,
V_70 , V_192 - 1 , & V_190 ) ;
if ( V_191 ) {
V_34 = V_191 ;
goto V_196;
}
}
V_189 = F_169 ( V_19 , V_70 , V_192 + 1 ) ;
if ( V_189 ) {
F_20 ( V_189 ) ;
F_144 ( V_189 ) ;
V_191 = F_142 ( V_29 , V_19 , V_189 ,
V_70 , V_192 + 1 , & V_189 ) ;
if ( V_191 ) {
V_34 = V_191 ;
goto V_196;
}
}
if ( V_190 ) {
V_193 += F_91 ( V_190 ) ;
V_191 = F_170 ( V_29 , V_19 , V_190 , V_176 , 1 ) ;
if ( V_191 < 0 )
V_34 = V_191 ;
}
if ( V_189 ) {
V_191 = F_170 ( V_29 , V_19 , V_176 , V_189 , 1 ) ;
if ( V_191 < 0 && V_191 != - V_197 )
V_34 = V_191 ;
if ( F_91 ( V_189 ) == 0 ) {
F_111 ( V_29 , V_19 , V_189 ) ;
F_21 ( V_189 ) ;
F_171 ( V_19 , V_2 , V_35 + 1 , V_192 + 1 ) ;
F_167 ( V_19 , V_189 -> V_42 ) ;
F_118 ( V_29 , V_19 , V_189 , 0 , 1 ) ;
F_121 ( V_189 ) ;
V_189 = NULL ;
} else {
struct V_36 V_198 ;
F_34 ( V_189 , & V_198 , 0 ) ;
F_97 ( V_19 -> V_23 , V_70 ,
V_192 + 1 , 0 ) ;
F_124 ( V_70 , & V_198 , V_192 + 1 ) ;
F_49 ( V_70 ) ;
}
}
if ( F_91 ( V_176 ) == 1 ) {
if ( ! V_190 ) {
V_34 = - V_121 ;
F_107 ( V_19 -> V_23 , V_34 ) ;
goto V_196;
}
V_191 = F_172 ( V_29 , V_19 , V_176 , V_190 ) ;
if ( V_191 < 0 ) {
V_34 = V_191 ;
goto V_196;
}
if ( V_191 == 1 ) {
V_191 = F_170 ( V_29 , V_19 , V_190 , V_176 , 1 ) ;
if ( V_191 < 0 )
V_34 = V_191 ;
}
F_75 ( V_191 == 1 ) ;
}
if ( F_91 ( V_176 ) == 0 ) {
F_111 ( V_29 , V_19 , V_176 ) ;
F_21 ( V_176 ) ;
F_171 ( V_19 , V_2 , V_35 + 1 , V_192 ) ;
F_167 ( V_19 , V_176 -> V_42 ) ;
F_118 ( V_29 , V_19 , V_176 , 0 , 1 ) ;
F_121 ( V_176 ) ;
V_176 = NULL ;
} else {
struct V_36 V_199 ;
F_34 ( V_176 , & V_199 , 0 ) ;
F_97 ( V_19 -> V_23 , V_70 ,
V_192 , 0 ) ;
F_124 ( V_70 , & V_199 , V_192 ) ;
F_49 ( V_70 ) ;
}
if ( V_190 ) {
if ( F_91 ( V_190 ) > V_193 ) {
F_116 ( V_190 ) ;
V_2 -> V_8 [ V_35 ] = V_190 ;
V_2 -> V_17 [ V_35 + 1 ] -= 1 ;
V_2 -> V_17 [ V_35 ] = V_193 ;
if ( V_176 ) {
F_21 ( V_176 ) ;
F_12 ( V_176 ) ;
}
} else {
V_193 -= F_91 ( V_190 ) ;
V_2 -> V_17 [ V_35 ] = V_193 ;
}
}
if ( V_194 !=
F_83 ( V_2 -> V_8 [ V_35 ] , V_2 -> V_17 [ V_35 ] ) )
F_173 () ;
V_196:
if ( V_189 ) {
F_21 ( V_189 ) ;
F_12 ( V_189 ) ;
}
if ( V_190 ) {
if ( V_2 -> V_8 [ V_35 ] != V_190 )
F_21 ( V_190 ) ;
F_12 ( V_190 ) ;
}
return V_34 ;
}
static T_1 int F_174 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_35 )
{
struct V_14 * V_189 = NULL ;
struct V_14 * V_176 ;
struct V_14 * V_190 = NULL ;
struct V_14 * V_70 = NULL ;
int V_34 = 0 ;
int V_191 ;
int V_192 ;
int V_193 = V_2 -> V_17 [ V_35 ] ;
if ( V_35 == 0 )
return 1 ;
V_176 = V_2 -> V_8 [ V_35 ] ;
F_31 ( F_47 ( V_176 ) != V_29 -> V_39 ) ;
if ( V_35 < V_7 - 1 ) {
V_70 = V_2 -> V_8 [ V_35 + 1 ] ;
V_192 = V_2 -> V_17 [ V_35 + 1 ] ;
}
if ( ! V_70 )
return 1 ;
V_190 = F_169 ( V_19 , V_70 , V_192 - 1 ) ;
if ( V_190 ) {
T_4 V_200 ;
F_20 ( V_190 ) ;
F_144 ( V_190 ) ;
V_200 = F_91 ( V_190 ) ;
if ( V_200 >= F_133 ( V_19 ) - 1 ) {
V_191 = 1 ;
} else {
V_34 = F_142 ( V_29 , V_19 , V_190 , V_70 ,
V_192 - 1 , & V_190 ) ;
if ( V_34 )
V_191 = 1 ;
else {
V_191 = F_170 ( V_29 , V_19 ,
V_190 , V_176 , 0 ) ;
}
}
if ( V_191 < 0 )
V_34 = V_191 ;
if ( V_191 == 0 ) {
struct V_36 V_37 ;
V_193 += V_200 ;
F_34 ( V_176 , & V_37 , 0 ) ;
F_97 ( V_19 -> V_23 , V_70 ,
V_192 , 0 ) ;
F_124 ( V_70 , & V_37 , V_192 ) ;
F_49 ( V_70 ) ;
if ( F_91 ( V_190 ) > V_193 ) {
V_2 -> V_8 [ V_35 ] = V_190 ;
V_2 -> V_17 [ V_35 + 1 ] -= 1 ;
V_2 -> V_17 [ V_35 ] = V_193 ;
F_21 ( V_176 ) ;
F_12 ( V_176 ) ;
} else {
V_193 -=
F_91 ( V_190 ) ;
V_2 -> V_17 [ V_35 ] = V_193 ;
F_21 ( V_190 ) ;
F_12 ( V_190 ) ;
}
return 0 ;
}
F_21 ( V_190 ) ;
F_12 ( V_190 ) ;
}
V_189 = F_169 ( V_19 , V_70 , V_192 + 1 ) ;
if ( V_189 ) {
T_4 V_201 ;
F_20 ( V_189 ) ;
F_144 ( V_189 ) ;
V_201 = F_91 ( V_189 ) ;
if ( V_201 >= F_133 ( V_19 ) - 1 ) {
V_191 = 1 ;
} else {
V_34 = F_142 ( V_29 , V_19 , V_189 ,
V_70 , V_192 + 1 ,
& V_189 ) ;
if ( V_34 )
V_191 = 1 ;
else {
V_191 = F_172 ( V_29 , V_19 ,
V_189 , V_176 ) ;
}
}
if ( V_191 < 0 )
V_34 = V_191 ;
if ( V_191 == 0 ) {
struct V_36 V_37 ;
F_34 ( V_189 , & V_37 , 0 ) ;
F_97 ( V_19 -> V_23 , V_70 ,
V_192 + 1 , 0 ) ;
F_124 ( V_70 , & V_37 , V_192 + 1 ) ;
F_49 ( V_70 ) ;
if ( F_91 ( V_176 ) <= V_193 ) {
V_2 -> V_8 [ V_35 ] = V_189 ;
V_2 -> V_17 [ V_35 + 1 ] += 1 ;
V_2 -> V_17 [ V_35 ] = V_193 -
F_91 ( V_176 ) ;
F_21 ( V_176 ) ;
F_12 ( V_176 ) ;
} else {
F_21 ( V_189 ) ;
F_12 ( V_189 ) ;
}
return 0 ;
}
F_21 ( V_189 ) ;
F_12 ( V_189 ) ;
}
return 1 ;
}
static void F_175 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int V_35 , int V_76 , T_2 V_123 )
{
struct V_14 * V_21 ;
struct V_36 V_37 ;
T_4 V_95 ;
T_2 V_202 ;
T_2 V_203 ;
T_2 V_204 = 0 ;
T_2 V_160 ;
int V_205 = V_2 -> V_206 ;
struct V_14 * V_20 ;
T_4 V_171 ;
T_4 V_146 ;
T_4 V_207 = 0 ;
if ( V_35 != 1 )
return;
if ( ! V_2 -> V_8 [ V_35 ] )
return;
V_21 = V_2 -> V_8 [ V_35 ] ;
V_202 = F_83 ( V_21 , V_76 ) ;
V_146 = F_135 ( V_19 , V_35 - 1 ) ;
V_20 = F_151 ( V_19 , V_202 , V_146 ) ;
if ( V_20 ) {
F_12 ( V_20 ) ;
return;
}
V_203 = V_202 ;
V_95 = F_91 ( V_21 ) ;
V_171 = V_76 ;
while ( 1 ) {
if ( V_205 < 0 ) {
if ( V_171 == 0 )
break;
V_171 -- ;
} else if ( V_205 > 0 ) {
V_171 ++ ;
if ( V_171 >= V_95 )
break;
}
if ( V_2 -> V_206 < 0 && V_123 ) {
F_34 ( V_21 , & V_37 , V_171 ) ;
if ( F_176 ( & V_37 ) != V_123 )
break;
}
V_202 = F_83 ( V_21 , V_171 ) ;
if ( ( V_202 <= V_203 && V_203 - V_202 <= 65536 ) ||
( V_202 > V_203 && V_202 - V_203 <= 65536 ) ) {
V_160 = F_84 ( V_21 , V_171 ) ;
F_177 ( V_19 , V_202 , V_146 , V_160 ) ;
V_204 += V_146 ;
}
V_207 ++ ;
if ( ( V_204 > 65536 || V_207 > 32 ) )
break;
}
}
static T_1 void F_178 ( struct V_18 * V_19 ,
struct V_1 * V_2 , int V_35 )
{
int V_76 ;
int V_95 ;
struct V_14 * V_70 ;
struct V_14 * V_20 ;
T_2 V_160 ;
T_2 V_208 = 0 ;
T_2 V_209 = 0 ;
int V_146 ;
V_70 = V_2 -> V_8 [ V_35 + 1 ] ;
if ( ! V_70 )
return;
V_95 = F_91 ( V_70 ) ;
V_76 = V_2 -> V_17 [ V_35 + 1 ] ;
V_146 = F_135 ( V_19 , V_35 ) ;
if ( V_76 > 0 ) {
V_208 = F_83 ( V_70 , V_76 - 1 ) ;
V_160 = F_84 ( V_70 , V_76 - 1 ) ;
V_20 = F_151 ( V_19 , V_208 , V_146 ) ;
if ( V_20 && F_152 ( V_20 , V_160 , 1 ) != 0 )
V_208 = 0 ;
F_12 ( V_20 ) ;
}
if ( V_76 + 1 < V_95 ) {
V_209 = F_83 ( V_70 , V_76 + 1 ) ;
V_160 = F_84 ( V_70 , V_76 + 1 ) ;
V_20 = F_151 ( V_19 , V_209 , V_146 ) ;
if ( V_20 && F_152 ( V_20 , V_160 , 1 ) != 0 )
V_209 = 0 ;
F_12 ( V_20 ) ;
}
if ( V_208 )
F_177 ( V_19 , V_208 , V_146 , 0 ) ;
if ( V_209 )
F_177 ( V_19 , V_209 , V_146 , 0 ) ;
}
static T_1 void F_179 ( struct V_1 * V_2 , int V_35 ,
int V_210 , int V_211 ,
int * V_212 )
{
int V_6 ;
int V_213 = V_35 ;
int V_214 = 0 ;
struct V_14 * V_215 ;
for ( V_6 = V_35 ; V_6 < V_7 ; V_6 ++ ) {
if ( ! V_2 -> V_8 [ V_6 ] )
break;
if ( ! V_2 -> V_9 [ V_6 ] )
break;
if ( ! V_214 && V_2 -> V_17 [ V_6 ] == 0 ) {
V_213 = V_6 + 1 ;
continue;
}
if ( ! V_214 && V_2 -> V_216 ) {
T_4 V_95 ;
V_215 = V_2 -> V_8 [ V_6 ] ;
V_95 = F_91 ( V_215 ) ;
if ( V_95 < 1 || V_2 -> V_17 [ V_6 ] >= V_95 - 1 ) {
V_213 = V_6 + 1 ;
continue;
}
}
if ( V_213 < V_6 && V_6 >= V_210 )
V_214 = 1 ;
V_215 = V_2 -> V_8 [ V_6 ] ;
if ( V_6 >= V_210 && V_6 > V_213 && V_2 -> V_9 [ V_6 ] ) {
F_11 ( V_215 , V_2 -> V_9 [ V_6 ] ) ;
V_2 -> V_9 [ V_6 ] = 0 ;
if ( V_212 &&
V_6 > V_211 &&
V_6 <= * V_212 ) {
* V_212 = V_6 - 1 ;
}
}
}
}
T_1 void F_180 ( struct V_1 * V_2 , int V_35 )
{
int V_6 ;
if ( V_2 -> V_216 )
return;
for ( V_6 = V_35 ; V_6 < V_7 ; V_6 ++ ) {
if ( ! V_2 -> V_8 [ V_6 ] )
continue;
if ( ! V_2 -> V_9 [ V_6 ] )
continue;
F_11 ( V_2 -> V_8 [ V_6 ] , V_2 -> V_9 [ V_6 ] ) ;
V_2 -> V_9 [ V_6 ] = 0 ;
}
}
static int
F_181 ( struct V_28 * V_29 ,
struct V_18 * V_19 , struct V_1 * V_5 ,
struct V_14 * * V_217 , int V_35 , int V_76 ,
struct V_153 * V_82 , T_2 V_131 )
{
T_2 V_150 ;
T_2 V_160 ;
T_4 V_146 ;
struct V_14 * V_218 = * V_217 ;
struct V_14 * V_177 ;
int V_34 ;
V_150 = F_83 ( V_218 , V_76 ) ;
V_160 = F_84 ( V_218 , V_76 ) ;
V_146 = F_135 ( V_19 , V_35 - 1 ) ;
V_177 = F_151 ( V_19 , V_150 , V_146 ) ;
if ( V_177 ) {
if ( F_152 ( V_177 , V_160 , 1 ) > 0 ) {
* V_217 = V_177 ;
return 0 ;
}
F_3 ( V_5 ) ;
V_34 = F_153 ( V_177 , V_160 ) ;
if ( ! V_34 ) {
* V_217 = V_177 ;
return 0 ;
}
F_12 ( V_177 ) ;
F_9 ( V_5 ) ;
return - V_169 ;
}
F_180 ( V_5 , V_35 + 1 ) ;
F_3 ( V_5 ) ;
F_12 ( V_177 ) ;
if ( V_5 -> V_206 )
F_175 ( V_19 , V_5 , V_35 , V_76 , V_82 -> V_123 ) ;
F_9 ( V_5 ) ;
V_34 = - V_219 ;
V_177 = F_136 ( V_19 , V_150 , V_146 , 0 ) ;
if ( V_177 ) {
if ( ! F_152 ( V_177 , 0 , 0 ) )
V_34 = - V_169 ;
F_12 ( V_177 ) ;
}
return V_34 ;
}
static int
F_182 ( struct V_28 * V_29 ,
struct V_18 * V_19 , struct V_1 * V_5 ,
struct V_14 * V_218 , int V_35 , int V_220 ,
int * V_212 )
{
int V_34 ;
if ( ( V_5 -> V_221 || V_220 > 0 ) && F_91 ( V_218 ) >=
F_133 ( V_19 ) - 3 ) {
int V_222 ;
if ( * V_212 < V_35 + 1 ) {
* V_212 = V_35 + 1 ;
F_9 ( V_5 ) ;
goto V_223;
}
F_3 ( V_5 ) ;
F_178 ( V_19 , V_5 , V_35 ) ;
V_222 = F_183 ( V_29 , V_19 , V_5 , V_35 ) ;
F_5 ( V_5 , NULL , 0 ) ;
F_75 ( V_222 > 0 ) ;
if ( V_222 ) {
V_34 = V_222 ;
goto V_224;
}
V_218 = V_5 -> V_8 [ V_35 ] ;
} else if ( V_220 < 0 && F_91 ( V_218 ) <
F_133 ( V_19 ) / 2 ) {
int V_222 ;
if ( * V_212 < V_35 + 1 ) {
* V_212 = V_35 + 1 ;
F_9 ( V_5 ) ;
goto V_223;
}
F_3 ( V_5 ) ;
F_178 ( V_19 , V_5 , V_35 ) ;
V_222 = F_168 ( V_29 , V_19 , V_5 , V_35 ) ;
F_5 ( V_5 , NULL , 0 ) ;
if ( V_222 ) {
V_34 = V_222 ;
goto V_224;
}
V_218 = V_5 -> V_8 [ V_35 ] ;
if ( ! V_218 ) {
F_9 ( V_5 ) ;
goto V_223;
}
F_75 ( F_91 ( V_218 ) == 1 ) ;
}
return 0 ;
V_223:
V_34 = - V_219 ;
V_224:
return V_34 ;
}
static void F_184 ( struct V_14 * V_218 ,
struct V_153 * V_82 ,
int V_35 )
{
#ifdef F_185
struct V_36 V_37 ;
F_186 ( & V_37 , V_82 ) ;
if ( V_35 == 0 )
ASSERT ( ! F_187 ( V_218 , & V_37 ,
F_162 ( struct V_182 , V_183 [ 0 ] . V_82 ) ,
sizeof( V_37 ) ) ) ;
else
ASSERT ( ! F_187 ( V_218 , & V_37 ,
F_162 ( struct V_185 , V_186 [ 0 ] . V_82 ) ,
sizeof( V_37 ) ) ) ;
#endif
}
static int F_188 ( struct V_14 * V_218 , struct V_153 * V_82 ,
int V_35 , int * V_225 , int * V_76 )
{
if ( * V_225 != 0 ) {
* V_225 = F_161 ( V_218 , V_82 , V_35 , V_76 ) ;
return * V_225 ;
}
F_184 ( V_218 , V_82 , V_35 ) ;
* V_76 = 0 ;
return 0 ;
}
int F_189 ( struct V_18 * V_226 , struct V_1 * V_227 ,
T_2 V_228 , T_2 V_229 , T_5 V_230 ,
struct V_153 * V_231 )
{
int V_34 ;
struct V_153 V_82 ;
struct V_14 * V_20 ;
struct V_1 * V_2 ;
V_82 . type = V_230 ;
V_82 . V_123 = V_228 ;
V_82 . V_156 = V_229 ;
if ( V_227 == NULL ) {
V_2 = F_1 () ;
if ( ! V_2 )
return - V_85 ;
} else
V_2 = V_227 ;
V_34 = F_190 ( NULL , V_226 , & V_82 , V_2 , 0 , 0 ) ;
if ( ( V_34 < 0 ) || ( V_231 == NULL ) ) {
if ( V_2 != V_227 )
F_8 ( V_2 ) ;
return V_34 ;
}
V_20 = V_2 -> V_8 [ 0 ] ;
if ( V_34 && V_2 -> V_17 [ 0 ] >= F_91 ( V_20 ) ) {
V_34 = F_191 ( V_226 , V_2 ) ;
if ( V_34 )
return V_34 ;
V_20 = V_2 -> V_8 [ 0 ] ;
}
F_192 ( V_20 , V_231 , V_2 -> V_17 [ 0 ] ) ;
if ( V_231 -> type != V_82 . type ||
V_231 -> V_123 != V_82 . V_123 )
return 1 ;
return 0 ;
}
int F_190 ( struct V_28 * V_29 , struct V_18
* V_19 , struct V_153 * V_82 , struct V_1 * V_5 , int
V_220 , int V_33 )
{
struct V_14 * V_218 ;
int V_76 ;
int V_34 ;
int V_164 ;
int V_35 ;
int V_210 = 1 ;
int V_232 ;
int V_212 = 0 ;
T_5 V_233 = 0 ;
int V_211 ;
int V_225 ;
V_233 = V_5 -> V_233 ;
F_31 ( V_233 && V_220 > 0 ) ;
F_31 ( V_5 -> V_8 [ 0 ] != NULL ) ;
F_75 ( ! V_33 && V_220 ) ;
if ( V_220 < 0 ) {
V_210 = 2 ;
V_212 = 2 ;
} else if ( V_220 > 0 ) {
V_212 = 1 ;
}
if ( ! V_33 )
V_212 = - 1 ;
if ( V_33 && ( V_5 -> V_216 || V_5 -> V_233 ) )
V_212 = V_7 ;
V_211 = V_212 ;
V_223:
V_225 = - 1 ;
V_232 = V_10 ;
V_35 = 0 ;
if ( V_5 -> V_234 ) {
V_218 = V_19 -> V_116 ;
F_116 ( V_218 ) ;
V_35 = F_32 ( V_218 ) ;
if ( ! V_5 -> V_235 )
F_23 ( V_218 ) ;
} else {
if ( V_5 -> V_235 ) {
V_218 = F_13 ( V_19 ) ;
V_35 = F_32 ( V_218 ) ;
} else {
V_218 = F_22 ( V_19 ) ;
V_35 = F_32 ( V_218 ) ;
if ( V_35 <= V_212 ) {
F_24 ( V_218 ) ;
F_12 ( V_218 ) ;
V_218 = F_19 ( V_19 ) ;
V_232 = V_12 ;
V_35 = F_32 ( V_218 ) ;
}
}
}
V_5 -> V_8 [ V_35 ] = V_218 ;
if ( ! V_5 -> V_235 )
V_5 -> V_9 [ V_35 ] = V_232 ;
while ( V_218 ) {
V_35 = F_32 ( V_218 ) ;
if ( V_33 ) {
if ( ! F_140 ( V_29 , V_19 , V_218 ) )
goto V_236;
F_3 ( V_5 ) ;
if ( V_35 > V_212 ||
( V_35 + 1 > V_212 &&
V_35 + 1 < V_7 &&
V_5 -> V_8 [ V_35 + 1 ] ) ) {
V_212 = V_35 + 1 ;
F_9 ( V_5 ) ;
goto V_223;
}
V_164 = F_142 ( V_29 , V_19 , V_218 ,
V_5 -> V_8 [ V_35 + 1 ] ,
V_5 -> V_17 [ V_35 + 1 ] , & V_218 ) ;
if ( V_164 ) {
V_34 = V_164 ;
goto V_224;
}
}
V_236:
V_5 -> V_8 [ V_35 ] = V_218 ;
F_5 ( V_5 , NULL , 0 ) ;
if ( ! V_220 && ! V_5 -> V_216 ) {
int V_237 = V_35 + 1 ;
if ( V_237 < V_7 && V_5 -> V_9 [ V_237 ] ) {
F_11 ( V_5 -> V_8 [ V_237 ] , V_5 -> V_9 [ V_237 ] ) ;
V_5 -> V_9 [ V_237 ] = 0 ;
}
}
V_34 = F_188 ( V_218 , V_82 , V_35 , & V_225 , & V_76 ) ;
if ( V_35 != 0 ) {
int V_238 = 0 ;
if ( V_34 && V_76 > 0 ) {
V_238 = 1 ;
V_76 -= 1 ;
}
V_5 -> V_17 [ V_35 ] = V_76 ;
V_164 = F_182 ( V_29 , V_19 , V_5 , V_218 , V_35 ,
V_220 , & V_212 ) ;
if ( V_164 == - V_219 )
goto V_223;
if ( V_164 ) {
V_34 = V_164 ;
goto V_224;
}
V_218 = V_5 -> V_8 [ V_35 ] ;
V_76 = V_5 -> V_17 [ V_35 ] ;
if ( V_76 == 0 && V_220 &&
V_212 < V_35 + 1 ) {
V_212 = V_35 + 1 ;
F_9 ( V_5 ) ;
goto V_223;
}
F_179 ( V_5 , V_35 , V_210 ,
V_211 , & V_212 ) ;
if ( V_35 == V_233 ) {
if ( V_238 )
V_5 -> V_17 [ V_35 ] ++ ;
goto V_224;
}
V_164 = F_181 ( V_29 , V_19 , V_5 ,
& V_218 , V_35 , V_76 , V_82 , 0 ) ;
if ( V_164 == - V_219 )
goto V_223;
if ( V_164 ) {
V_34 = V_164 ;
goto V_224;
}
if ( ! V_5 -> V_235 ) {
V_35 = F_32 ( V_218 ) ;
if ( V_35 <= V_212 ) {
V_164 = F_193 ( V_218 ) ;
if ( ! V_164 ) {
F_3 ( V_5 ) ;
F_20 ( V_218 ) ;
F_5 ( V_5 , V_218 ,
V_12 ) ;
}
V_5 -> V_9 [ V_35 ] = V_12 ;
} else {
V_164 = F_194 ( V_218 ) ;
if ( ! V_164 ) {
F_3 ( V_5 ) ;
F_23 ( V_218 ) ;
F_5 ( V_5 , V_218 ,
V_10 ) ;
}
V_5 -> V_9 [ V_35 ] = V_10 ;
}
V_5 -> V_8 [ V_35 ] = V_218 ;
}
} else {
V_5 -> V_17 [ V_35 ] = V_76 ;
if ( V_220 > 0 &&
F_195 ( V_19 , V_218 ) < V_220 ) {
if ( V_212 < 1 ) {
V_212 = 1 ;
F_9 ( V_5 ) ;
goto V_223;
}
F_3 ( V_5 ) ;
V_164 = F_196 ( V_29 , V_19 , V_82 ,
V_5 , V_220 , V_34 == 0 ) ;
F_5 ( V_5 , NULL , 0 ) ;
F_75 ( V_164 > 0 ) ;
if ( V_164 ) {
V_34 = V_164 ;
goto V_224;
}
}
if ( ! V_5 -> V_221 )
F_179 ( V_5 , V_35 , V_210 ,
V_211 , & V_212 ) ;
goto V_224;
}
}
V_34 = 1 ;
V_224:
if ( ! V_5 -> V_239 )
F_3 ( V_5 ) ;
if ( V_34 < 0 )
F_9 ( V_5 ) ;
return V_34 ;
}
int F_197 ( struct V_18 * V_19 , struct V_153 * V_82 ,
struct V_1 * V_5 , T_2 V_131 )
{
struct V_14 * V_218 ;
int V_76 ;
int V_34 ;
int V_164 ;
int V_35 ;
int V_210 = 1 ;
T_5 V_233 = 0 ;
int V_225 = - 1 ;
V_233 = V_5 -> V_233 ;
F_31 ( V_5 -> V_8 [ 0 ] != NULL ) ;
if ( V_5 -> V_234 ) {
F_75 ( V_131 ) ;
return F_190 ( NULL , V_19 , V_82 , V_5 , 0 , 0 ) ;
}
V_223:
V_218 = F_134 ( V_19 , V_131 ) ;
V_35 = F_32 ( V_218 ) ;
V_5 -> V_9 [ V_35 ] = V_10 ;
while ( V_218 ) {
V_35 = F_32 ( V_218 ) ;
V_5 -> V_8 [ V_35 ] = V_218 ;
F_5 ( V_5 , NULL , 0 ) ;
F_180 ( V_5 , V_35 + 1 ) ;
V_225 = - 1 ;
V_34 = F_188 ( V_218 , V_82 , V_35 , & V_225 , & V_76 ) ;
if ( V_35 != 0 ) {
int V_238 = 0 ;
if ( V_34 && V_76 > 0 ) {
V_238 = 1 ;
V_76 -= 1 ;
}
V_5 -> V_17 [ V_35 ] = V_76 ;
F_179 ( V_5 , V_35 , V_210 , 0 , NULL ) ;
if ( V_35 == V_233 ) {
if ( V_238 )
V_5 -> V_17 [ V_35 ] ++ ;
goto V_224;
}
V_164 = F_181 ( NULL , V_19 , V_5 , & V_218 , V_35 ,
V_76 , V_82 , V_131 ) ;
if ( V_164 == - V_219 )
goto V_223;
if ( V_164 ) {
V_34 = V_164 ;
goto V_224;
}
V_35 = F_32 ( V_218 ) ;
V_164 = F_194 ( V_218 ) ;
if ( ! V_164 ) {
F_3 ( V_5 ) ;
F_23 ( V_218 ) ;
F_5 ( V_5 , V_218 ,
V_10 ) ;
}
V_218 = F_128 ( V_19 -> V_23 , V_5 , V_218 , V_131 ) ;
if ( ! V_218 ) {
V_34 = - V_85 ;
goto V_224;
}
V_5 -> V_9 [ V_35 ] = V_10 ;
V_5 -> V_8 [ V_35 ] = V_218 ;
} else {
V_5 -> V_17 [ V_35 ] = V_76 ;
F_179 ( V_5 , V_35 , V_210 , 0 , NULL ) ;
goto V_224;
}
}
V_34 = 1 ;
V_224:
if ( ! V_5 -> V_239 )
F_3 ( V_5 ) ;
if ( V_34 < 0 )
F_9 ( V_5 ) ;
return V_34 ;
}
int F_198 ( struct V_18 * V_19 ,
struct V_153 * V_82 , struct V_1 * V_5 ,
int V_240 , int V_241 )
{
int V_34 ;
struct V_14 * V_170 ;
V_223:
V_34 = F_190 ( NULL , V_19 , V_82 , V_5 , 0 , 0 ) ;
if ( V_34 <= 0 )
return V_34 ;
V_170 = V_5 -> V_8 [ 0 ] ;
if ( V_240 ) {
if ( V_5 -> V_17 [ 0 ] >= F_91 ( V_170 ) ) {
V_34 = F_191 ( V_19 , V_5 ) ;
if ( V_34 <= 0 )
return V_34 ;
if ( ! V_241 )
return 1 ;
V_241 = 0 ;
V_240 = 0 ;
F_9 ( V_5 ) ;
goto V_223;
}
} else {
if ( V_5 -> V_17 [ 0 ] == 0 ) {
V_34 = F_199 ( V_19 , V_5 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( ! V_34 ) {
V_170 = V_5 -> V_8 [ 0 ] ;
if ( V_5 -> V_17 [ 0 ] == F_91 ( V_170 ) )
V_5 -> V_17 [ 0 ] -- ;
return 0 ;
}
if ( ! V_241 )
return 1 ;
V_241 = 0 ;
V_240 = 1 ;
F_9 ( V_5 ) ;
goto V_223;
} else {
-- V_5 -> V_17 [ 0 ] ;
}
}
return 0 ;
}
static void F_200 ( struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_36 * V_82 , int V_35 )
{
int V_6 ;
struct V_14 * V_215 ;
for ( V_6 = V_35 ; V_6 < V_7 ; V_6 ++ ) {
int V_242 = V_2 -> V_17 [ V_6 ] ;
if ( ! V_2 -> V_8 [ V_6 ] )
break;
V_215 = V_2 -> V_8 [ V_6 ] ;
F_97 ( V_19 -> V_23 , V_215 , V_242 , 1 ) ;
F_124 ( V_215 , V_82 , V_242 ) ;
F_49 ( V_2 -> V_8 [ V_6 ] ) ;
if ( V_242 != 0 )
break;
}
}
void F_201 ( struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_153 * V_243 )
{
struct V_36 V_37 ;
struct V_14 * V_20 ;
int V_76 ;
V_20 = V_2 -> V_8 [ 0 ] ;
V_76 = V_2 -> V_17 [ 0 ] ;
if ( V_76 > 0 ) {
F_33 ( V_20 , & V_37 , V_76 - 1 ) ;
F_75 ( F_147 ( & V_37 , V_243 ) >= 0 ) ;
}
if ( V_76 < F_91 ( V_20 ) - 1 ) {
F_33 ( V_20 , & V_37 , V_76 + 1 ) ;
F_75 ( F_147 ( & V_37 , V_243 ) <= 0 ) ;
}
F_186 ( & V_37 , V_243 ) ;
F_202 ( V_20 , & V_37 , V_76 ) ;
F_49 ( V_20 ) ;
if ( V_76 == 0 )
F_200 ( V_19 , V_2 , & V_37 , 1 ) ;
}
static int F_170 ( struct V_28 * V_29 ,
struct V_18 * V_19 , struct V_14 * V_105 ,
struct V_14 * V_106 , int V_244 )
{
int V_245 = 0 ;
int V_246 ;
int V_247 ;
int V_34 = 0 ;
V_246 = F_91 ( V_106 ) ;
V_247 = F_91 ( V_105 ) ;
V_245 = F_133 ( V_19 ) - V_247 ;
F_31 ( F_47 ( V_106 ) != V_29 -> V_39 ) ;
F_31 ( F_47 ( V_105 ) != V_29 -> V_39 ) ;
if ( ! V_244 && V_246 <= 8 )
return 1 ;
if ( V_245 <= 0 )
return 1 ;
if ( V_244 ) {
V_245 = F_154 ( V_246 , V_245 ) ;
if ( V_245 < V_246 ) {
if ( V_246 - V_245 < 8 ) {
if ( V_245 <= 8 )
return 1 ;
V_245 -= 8 ;
}
}
} else
V_245 = F_154 ( V_246 - 8 , V_245 ) ;
V_34 = F_95 ( V_19 -> V_23 , V_105 , V_106 , V_247 , 0 ,
V_245 ) ;
if ( V_34 ) {
F_114 ( V_29 , V_19 , V_34 ) ;
return V_34 ;
}
F_38 ( V_105 , V_106 ,
F_125 ( V_247 ) ,
F_125 ( 0 ) ,
V_245 * sizeof( struct V_139 ) ) ;
if ( V_245 < V_246 ) {
F_126 ( V_106 , F_125 ( 0 ) ,
F_125 ( V_245 ) ,
( V_246 - V_245 ) *
sizeof( struct V_139 ) ) ;
}
F_127 ( V_106 , V_246 - V_245 ) ;
F_127 ( V_105 , V_247 + V_245 ) ;
F_49 ( V_106 ) ;
F_49 ( V_105 ) ;
return V_34 ;
}
static int F_172 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_14 * V_105 ,
struct V_14 * V_106 )
{
int V_245 = 0 ;
int V_248 ;
int V_246 ;
int V_247 ;
int V_34 = 0 ;
F_31 ( F_47 ( V_106 ) != V_29 -> V_39 ) ;
F_31 ( F_47 ( V_105 ) != V_29 -> V_39 ) ;
V_246 = F_91 ( V_106 ) ;
V_247 = F_91 ( V_105 ) ;
V_245 = F_133 ( V_19 ) - V_247 ;
if ( V_245 <= 0 )
return 1 ;
if ( V_246 < 4 )
return 1 ;
V_248 = V_246 / 2 + 1 ;
if ( V_248 >= V_246 )
return 1 ;
if ( V_248 < V_245 )
V_245 = V_248 ;
F_96 ( V_19 -> V_23 , V_105 , V_245 , 0 , V_247 ) ;
F_126 ( V_105 , F_125 ( V_245 ) ,
F_125 ( 0 ) ,
( V_247 ) *
sizeof( struct V_139 ) ) ;
V_34 = F_95 ( V_19 -> V_23 , V_105 , V_106 , 0 ,
V_246 - V_245 , V_245 ) ;
if ( V_34 ) {
F_114 ( V_29 , V_19 , V_34 ) ;
return V_34 ;
}
F_38 ( V_105 , V_106 ,
F_125 ( 0 ) ,
F_125 ( V_246 - V_245 ) ,
V_245 * sizeof( struct V_139 ) ) ;
F_127 ( V_106 , V_246 - V_245 ) ;
F_127 ( V_105 , V_247 + V_245 ) ;
F_49 ( V_106 ) ;
F_49 ( V_105 ) ;
return V_34 ;
}
static T_1 int F_203 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_35 )
{
T_2 V_249 ;
struct V_14 * V_250 ;
struct V_14 * V_251 ;
struct V_14 * V_143 ;
struct V_36 V_252 ;
F_75 ( V_2 -> V_8 [ V_35 ] ) ;
F_75 ( V_2 -> V_8 [ V_35 - 1 ] != V_19 -> V_21 ) ;
V_250 = V_2 -> V_8 [ V_35 - 1 ] ;
if ( V_35 == 1 )
F_33 ( V_250 , & V_252 , 0 ) ;
else
F_34 ( V_250 , & V_252 , 0 ) ;
V_251 = F_35 ( V_29 , V_19 , V_19 -> V_142 , 0 ,
V_19 -> V_122 . V_123 , & V_252 ,
V_35 , V_19 -> V_21 -> V_43 , 0 ) ;
if ( F_36 ( V_251 ) )
return F_37 ( V_251 ) ;
F_164 ( V_19 , V_19 -> V_142 ) ;
F_204 ( V_251 , 0 , 0 , sizeof( struct V_253 ) ) ;
F_127 ( V_251 , 1 ) ;
F_131 ( V_251 , V_35 ) ;
F_39 ( V_251 , V_251 -> V_43 ) ;
F_40 ( V_251 , V_29 -> V_39 ) ;
F_41 ( V_251 , V_44 ) ;
F_44 ( V_251 , V_19 -> V_122 . V_123 ) ;
F_45 ( V_251 , V_19 -> V_23 -> V_48 , F_46 () ,
V_49 ) ;
F_45 ( V_251 , V_19 -> V_23 -> V_254 ,
F_205 ( V_251 ) , V_255 ) ;
F_124 ( V_251 , & V_252 , 0 ) ;
F_119 ( V_251 , 0 , V_250 -> V_43 ) ;
V_249 = F_47 ( V_250 ) ;
F_31 ( V_249 != V_29 -> V_39 ) ;
F_120 ( V_251 , 0 , V_249 ) ;
F_49 ( V_251 ) ;
V_143 = V_19 -> V_21 ;
F_99 ( V_19 , V_251 , 0 ) ;
F_117 ( V_19 -> V_21 , V_251 ) ;
F_12 ( V_143 ) ;
F_25 ( V_19 ) ;
F_116 ( V_251 ) ;
V_2 -> V_8 [ V_35 ] = V_251 ;
V_2 -> V_9 [ V_35 ] = V_12 ;
V_2 -> V_17 [ V_35 ] = 0 ;
return 0 ;
}
static void F_206 ( struct V_28 * V_29 ,
struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_36 * V_82 , T_2 V_256 ,
int V_76 , int V_35 )
{
struct V_14 * V_250 ;
int V_95 ;
int V_34 ;
F_75 ( ! V_2 -> V_8 [ V_35 ] ) ;
F_113 ( V_2 -> V_8 [ V_35 ] ) ;
V_250 = V_2 -> V_8 [ V_35 ] ;
V_95 = F_91 ( V_250 ) ;
F_75 ( V_76 > V_95 ) ;
F_75 ( V_95 == F_133 ( V_19 ) ) ;
if ( V_76 != V_95 ) {
if ( V_35 )
F_96 ( V_19 -> V_23 , V_250 , V_76 + 1 ,
V_76 , V_95 - V_76 ) ;
F_126 ( V_250 ,
F_125 ( V_76 + 1 ) ,
F_125 ( V_76 ) ,
( V_95 - V_76 ) * sizeof( struct V_139 ) ) ;
}
if ( V_35 ) {
V_34 = F_86 ( V_19 -> V_23 , V_250 , V_76 ,
V_81 , V_4 ) ;
F_75 ( V_34 < 0 ) ;
}
F_124 ( V_250 , V_82 , V_76 ) ;
F_119 ( V_250 , V_76 , V_256 ) ;
F_31 ( V_29 -> V_39 == 0 ) ;
F_120 ( V_250 , V_76 , V_29 -> V_39 ) ;
F_127 ( V_250 , V_95 + 1 ) ;
F_49 ( V_250 ) ;
}
static T_1 int F_183 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_35 )
{
struct V_14 * V_251 ;
struct V_14 * V_257 ;
struct V_36 V_37 ;
int V_176 ;
int V_34 ;
T_4 V_258 ;
V_251 = V_2 -> V_8 [ V_35 ] ;
F_31 ( F_47 ( V_251 ) != V_29 -> V_39 ) ;
if ( V_251 == V_19 -> V_21 ) {
V_34 = F_203 ( V_29 , V_19 , V_2 , V_35 + 1 ) ;
if ( V_34 )
return V_34 ;
} else {
V_34 = F_174 ( V_29 , V_19 , V_2 , V_35 ) ;
V_251 = V_2 -> V_8 [ V_35 ] ;
if ( ! V_34 && F_91 ( V_251 ) <
F_133 ( V_19 ) - 3 )
return 0 ;
if ( V_34 < 0 )
return V_34 ;
}
V_258 = F_91 ( V_251 ) ;
V_176 = ( V_258 + 1 ) / 2 ;
F_34 ( V_251 , & V_37 , V_176 ) ;
V_257 = F_35 ( V_29 , V_19 , V_19 -> V_142 , 0 ,
V_19 -> V_122 . V_123 ,
& V_37 , V_35 , V_251 -> V_43 , 0 ) ;
if ( F_36 ( V_257 ) )
return F_37 ( V_257 ) ;
F_164 ( V_19 , V_19 -> V_142 ) ;
F_204 ( V_257 , 0 , 0 , sizeof( struct V_253 ) ) ;
F_131 ( V_257 , F_32 ( V_251 ) ) ;
F_39 ( V_257 , V_257 -> V_43 ) ;
F_40 ( V_257 , V_29 -> V_39 ) ;
F_41 ( V_257 , V_44 ) ;
F_44 ( V_257 , V_19 -> V_122 . V_123 ) ;
F_45 ( V_257 , V_19 -> V_23 -> V_48 ,
F_46 () , V_49 ) ;
F_45 ( V_257 , V_19 -> V_23 -> V_254 ,
F_205 ( V_257 ) ,
V_255 ) ;
V_34 = F_95 ( V_19 -> V_23 , V_257 , V_251 , 0 ,
V_176 , V_258 - V_176 ) ;
if ( V_34 ) {
F_114 ( V_29 , V_19 , V_34 ) ;
return V_34 ;
}
F_38 ( V_257 , V_251 ,
F_125 ( 0 ) ,
F_125 ( V_176 ) ,
( V_258 - V_176 ) * sizeof( struct V_139 ) ) ;
F_127 ( V_257 , V_258 - V_176 ) ;
F_127 ( V_251 , V_176 ) ;
V_34 = 0 ;
F_49 ( V_251 ) ;
F_49 ( V_257 ) ;
F_206 ( V_29 , V_19 , V_2 , & V_37 , V_257 -> V_43 ,
V_2 -> V_17 [ V_35 + 1 ] + 1 , V_35 + 1 ) ;
if ( V_2 -> V_17 [ V_35 ] >= V_176 ) {
V_2 -> V_17 [ V_35 ] -= V_176 ;
F_21 ( V_251 ) ;
F_12 ( V_251 ) ;
V_2 -> V_8 [ V_35 ] = V_257 ;
V_2 -> V_17 [ V_35 + 1 ] += 1 ;
} else {
F_21 ( V_257 ) ;
F_12 ( V_257 ) ;
}
return V_34 ;
}
static int F_207 ( struct V_14 * V_259 , int V_43 , int V_171 )
{
struct V_184 * V_260 ;
struct V_184 * V_261 ;
struct V_262 V_263 ;
int V_264 ;
int V_95 = F_91 ( V_259 ) ;
int V_265 = F_154 ( V_95 , V_43 + V_171 ) - 1 ;
if ( ! V_171 )
return 0 ;
F_208 ( & V_263 ) ;
V_260 = F_209 ( V_43 ) ;
V_261 = F_209 ( V_265 ) ;
V_264 = F_210 ( V_259 , V_260 , & V_263 ) +
F_211 ( V_259 , V_260 , & V_263 ) ;
V_264 = V_264 - F_210 ( V_259 , V_261 , & V_263 ) ;
V_264 += sizeof( struct V_184 ) * V_171 ;
F_31 ( V_264 < 0 ) ;
return V_264 ;
}
T_1 int F_195 ( struct V_18 * V_19 ,
struct V_14 * V_170 )
{
int V_95 = F_91 ( V_170 ) ;
int V_34 ;
V_34 = F_156 ( V_19 ) - F_207 ( V_170 , 0 , V_95 ) ;
if ( V_34 < 0 ) {
F_212 ( V_19 -> V_23 ,
L_3 ,
V_34 , ( unsigned long ) F_156 ( V_19 ) ,
F_207 ( V_170 , 0 , V_95 ) , V_95 ) ;
}
return V_34 ;
}
static T_1 int F_213 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
int V_266 , int V_244 ,
struct V_14 * V_189 ,
int V_267 , T_4 V_268 ,
T_4 V_269 )
{
struct V_14 * V_190 = V_2 -> V_8 [ 0 ] ;
struct V_14 * V_270 = V_2 -> V_8 [ 1 ] ;
struct V_262 V_263 ;
struct V_36 V_37 ;
int V_76 ;
T_4 V_6 ;
int V_271 = 0 ;
int V_245 = 0 ;
struct V_184 * V_272 ;
T_4 V_171 ;
T_4 V_273 ;
T_4 V_274 ;
T_4 V_275 ;
F_208 ( & V_263 ) ;
if ( V_244 )
V_171 = 0 ;
else
V_171 = F_214 ( T_4 , 1 , V_269 ) ;
if ( V_2 -> V_17 [ 0 ] >= V_268 )
V_271 += V_266 ;
V_76 = V_2 -> V_17 [ 1 ] ;
V_6 = V_268 - 1 ;
while ( V_6 >= V_171 ) {
V_272 = F_209 ( V_6 ) ;
if ( ! V_244 && V_245 > 0 ) {
if ( V_2 -> V_17 [ 0 ] > V_6 )
break;
if ( V_2 -> V_17 [ 0 ] == V_6 ) {
int V_276 = F_195 ( V_19 , V_190 ) ;
if ( V_276 + V_271 * 2 > V_267 )
break;
}
}
if ( V_2 -> V_17 [ 0 ] == V_6 )
V_271 += V_266 ;
V_275 = F_215 ( V_190 , V_272 ) ;
if ( V_275 + sizeof( * V_272 ) + V_271 > V_267 )
break;
V_245 ++ ;
V_271 += V_275 + sizeof( * V_272 ) ;
if ( V_6 == 0 )
break;
V_6 -- ;
}
if ( V_245 == 0 )
goto V_277;
F_31 ( ! V_244 && V_245 == V_268 ) ;
V_273 = F_91 ( V_189 ) ;
V_271 = F_216 ( V_190 , V_268 - V_245 ) ;
V_271 -= F_155 ( V_19 , V_190 ) ;
V_274 = F_155 ( V_19 , V_189 ) ;
F_126 ( V_189 ,
F_217 ( V_189 ) + V_274 - V_271 ,
F_217 ( V_189 ) + V_274 ,
F_156 ( V_19 ) - V_274 ) ;
F_38 ( V_189 , V_190 , F_217 ( V_189 ) +
F_156 ( V_19 ) - V_271 ,
F_217 ( V_190 ) + F_155 ( V_19 , V_190 ) ,
V_271 ) ;
F_126 ( V_189 , F_218 ( V_245 ) ,
F_218 ( 0 ) ,
V_273 * sizeof( struct V_184 ) ) ;
F_38 ( V_189 , V_190 , F_218 ( 0 ) ,
F_218 ( V_268 - V_245 ) ,
V_245 * sizeof( struct V_184 ) ) ;
V_273 += V_245 ;
F_127 ( V_189 , V_273 ) ;
V_271 = F_156 ( V_19 ) ;
for ( V_6 = 0 ; V_6 < V_273 ; V_6 ++ ) {
V_272 = F_209 ( V_6 ) ;
V_271 -= F_211 ( V_189 , V_272 , & V_263 ) ;
F_219 ( V_189 , V_272 , V_271 , & V_263 ) ;
}
V_268 -= V_245 ;
F_127 ( V_190 , V_268 ) ;
if ( V_268 )
F_49 ( V_190 ) ;
else
F_111 ( V_29 , V_19 , V_190 ) ;
F_49 ( V_189 ) ;
F_33 ( V_189 , & V_37 , 0 ) ;
F_124 ( V_270 , & V_37 , V_76 + 1 ) ;
F_49 ( V_270 ) ;
if ( V_2 -> V_17 [ 0 ] >= V_268 ) {
V_2 -> V_17 [ 0 ] -= V_268 ;
if ( F_91 ( V_2 -> V_8 [ 0 ] ) == 0 )
F_111 ( V_29 , V_19 , V_2 -> V_8 [ 0 ] ) ;
F_21 ( V_2 -> V_8 [ 0 ] ) ;
F_12 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_189 ;
V_2 -> V_17 [ 1 ] += 1 ;
} else {
F_21 ( V_189 ) ;
F_12 ( V_189 ) ;
}
return 0 ;
V_277:
F_21 ( V_189 ) ;
F_12 ( V_189 ) ;
return 1 ;
}
static int F_220 ( struct V_28 * V_29 , struct V_18
* V_19 , struct V_1 * V_2 ,
int V_278 , int V_266 ,
int V_244 , T_4 V_269 )
{
struct V_14 * V_190 = V_2 -> V_8 [ 0 ] ;
struct V_14 * V_189 ;
struct V_14 * V_270 ;
int V_76 ;
int V_267 ;
T_4 V_268 ;
int V_34 ;
if ( ! V_2 -> V_8 [ 1 ] )
return 1 ;
V_76 = V_2 -> V_17 [ 1 ] ;
V_270 = V_2 -> V_8 [ 1 ] ;
if ( V_76 >= F_91 ( V_270 ) - 1 )
return 1 ;
F_113 ( V_2 -> V_8 [ 1 ] ) ;
V_189 = F_169 ( V_19 , V_270 , V_76 + 1 ) ;
if ( V_189 == NULL )
return 1 ;
F_20 ( V_189 ) ;
F_144 ( V_189 ) ;
V_267 = F_195 ( V_19 , V_189 ) ;
if ( V_267 < V_266 )
goto V_277;
V_34 = F_142 ( V_29 , V_19 , V_189 , V_270 ,
V_76 + 1 , & V_189 ) ;
if ( V_34 )
goto V_277;
V_267 = F_195 ( V_19 , V_189 ) ;
if ( V_267 < V_266 )
goto V_277;
V_268 = F_91 ( V_190 ) ;
if ( V_268 == 0 )
goto V_277;
if ( V_2 -> V_17 [ 0 ] == V_268 && ! V_244 ) {
F_21 ( V_190 ) ;
F_12 ( V_190 ) ;
V_2 -> V_8 [ 0 ] = V_189 ;
V_2 -> V_17 [ 0 ] = 0 ;
V_2 -> V_17 [ 1 ] ++ ;
return 0 ;
}
return F_213 ( V_29 , V_19 , V_2 , V_278 , V_244 ,
V_189 , V_267 , V_268 , V_269 ) ;
V_277:
F_21 ( V_189 ) ;
F_12 ( V_189 ) ;
return 1 ;
}
static T_1 int F_221 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_266 ,
int V_244 , struct V_14 * V_190 ,
int V_267 , T_4 V_273 ,
T_4 V_279 )
{
struct V_36 V_37 ;
struct V_14 * V_189 = V_2 -> V_8 [ 0 ] ;
int V_6 ;
int V_271 = 0 ;
int V_245 = 0 ;
struct V_184 * V_272 ;
T_4 V_280 ;
T_4 V_171 ;
int V_34 = 0 ;
T_4 V_275 ;
T_4 V_281 ;
struct V_262 V_263 ;
F_208 ( & V_263 ) ;
if ( V_244 )
V_171 = F_154 ( V_273 , V_279 ) ;
else
V_171 = F_154 ( V_273 - 1 , V_279 ) ;
for ( V_6 = 0 ; V_6 < V_171 ; V_6 ++ ) {
V_272 = F_209 ( V_6 ) ;
if ( ! V_244 && V_245 > 0 ) {
if ( V_2 -> V_17 [ 0 ] < V_6 )
break;
if ( V_2 -> V_17 [ 0 ] == V_6 ) {
int V_276 = F_195 ( V_19 , V_189 ) ;
if ( V_276 + V_271 * 2 > V_267 )
break;
}
}
if ( V_2 -> V_17 [ 0 ] == V_6 )
V_271 += V_266 ;
V_275 = F_215 ( V_189 , V_272 ) ;
if ( V_275 + sizeof( * V_272 ) + V_271 > V_267 )
break;
V_245 ++ ;
V_271 += V_275 + sizeof( * V_272 ) ;
}
if ( V_245 == 0 ) {
V_34 = 1 ;
goto V_282;
}
F_31 ( ! V_244 && V_245 == F_91 ( V_189 ) ) ;
F_38 ( V_190 , V_189 ,
F_218 ( F_91 ( V_190 ) ) ,
F_218 ( 0 ) ,
V_245 * sizeof( struct V_184 ) ) ;
V_271 = F_156 ( V_19 ) -
F_157 ( V_189 , V_245 - 1 ) ;
F_38 ( V_190 , V_189 , F_217 ( V_190 ) +
F_155 ( V_19 , V_190 ) - V_271 ,
F_217 ( V_189 ) +
F_157 ( V_189 , V_245 - 1 ) ,
V_271 ) ;
V_280 = F_91 ( V_190 ) ;
F_75 ( V_280 <= 0 ) ;
V_281 = F_157 ( V_190 , V_280 - 1 ) ;
for ( V_6 = V_280 ; V_6 < V_280 + V_245 ; V_6 ++ ) {
T_4 V_229 ;
V_272 = F_209 ( V_6 ) ;
V_229 = F_210 ( V_190 , V_272 , & V_263 ) ;
F_219 ( V_190 , V_272 ,
V_229 - ( F_156 ( V_19 ) - V_281 ) ,
& V_263 ) ;
}
F_127 ( V_190 , V_280 + V_245 ) ;
if ( V_245 > V_273 )
F_143 ( 1 , V_149 L_4 , V_245 ,
V_273 ) ;
if ( V_245 < V_273 ) {
V_271 = F_157 ( V_189 , V_245 - 1 ) -
F_155 ( V_19 , V_189 ) ;
F_126 ( V_189 , F_217 ( V_189 ) +
F_156 ( V_19 ) - V_271 ,
F_217 ( V_189 ) +
F_155 ( V_19 , V_189 ) , V_271 ) ;
F_126 ( V_189 , F_218 ( 0 ) ,
F_218 ( V_245 ) ,
( F_91 ( V_189 ) - V_245 ) *
sizeof( struct V_184 ) ) ;
}
V_273 -= V_245 ;
F_127 ( V_189 , V_273 ) ;
V_271 = F_156 ( V_19 ) ;
for ( V_6 = 0 ; V_6 < V_273 ; V_6 ++ ) {
V_272 = F_209 ( V_6 ) ;
V_271 = V_271 - F_211 ( V_189 ,
V_272 , & V_263 ) ;
F_219 ( V_189 , V_272 , V_271 , & V_263 ) ;
}
F_49 ( V_190 ) ;
if ( V_273 )
F_49 ( V_189 ) ;
else
F_111 ( V_29 , V_19 , V_189 ) ;
F_33 ( V_189 , & V_37 , 0 ) ;
F_200 ( V_19 , V_2 , & V_37 , 1 ) ;
if ( V_2 -> V_17 [ 0 ] < V_245 ) {
V_2 -> V_17 [ 0 ] += V_280 ;
F_21 ( V_2 -> V_8 [ 0 ] ) ;
F_12 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_190 ;
V_2 -> V_17 [ 1 ] -= 1 ;
} else {
F_21 ( V_190 ) ;
F_12 ( V_190 ) ;
V_2 -> V_17 [ 0 ] -= V_245 ;
}
F_75 ( V_2 -> V_17 [ 0 ] < 0 ) ;
return V_34 ;
V_282:
F_21 ( V_190 ) ;
F_12 ( V_190 ) ;
return V_34 ;
}
static int F_222 ( struct V_28 * V_29 , struct V_18
* V_19 , struct V_1 * V_2 , int V_278 ,
int V_266 , int V_244 , T_4 V_279 )
{
struct V_14 * V_189 = V_2 -> V_8 [ 0 ] ;
struct V_14 * V_190 ;
int V_76 ;
int V_267 ;
T_4 V_273 ;
int V_34 = 0 ;
V_76 = V_2 -> V_17 [ 1 ] ;
if ( V_76 == 0 )
return 1 ;
if ( ! V_2 -> V_8 [ 1 ] )
return 1 ;
V_273 = F_91 ( V_189 ) ;
if ( V_273 == 0 )
return 1 ;
F_113 ( V_2 -> V_8 [ 1 ] ) ;
V_190 = F_169 ( V_19 , V_2 -> V_8 [ 1 ] , V_76 - 1 ) ;
if ( V_190 == NULL )
return 1 ;
F_20 ( V_190 ) ;
F_144 ( V_190 ) ;
V_267 = F_195 ( V_19 , V_190 ) ;
if ( V_267 < V_266 ) {
V_34 = 1 ;
goto V_282;
}
V_34 = F_142 ( V_29 , V_19 , V_190 ,
V_2 -> V_8 [ 1 ] , V_76 - 1 , & V_190 ) ;
if ( V_34 ) {
if ( V_34 == - V_197 )
V_34 = 1 ;
goto V_282;
}
V_267 = F_195 ( V_19 , V_190 ) ;
if ( V_267 < V_266 ) {
V_34 = 1 ;
goto V_282;
}
return F_221 ( V_29 , V_19 , V_2 , V_278 ,
V_244 , V_190 , V_267 , V_273 ,
V_279 ) ;
V_282:
F_21 ( V_190 ) ;
F_12 ( V_190 ) ;
return V_34 ;
}
static T_1 void F_223 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_14 * V_259 ,
struct V_14 * V_189 ,
int V_76 , int V_176 , int V_95 )
{
int V_283 ;
int V_284 ;
int V_6 ;
struct V_36 V_37 ;
struct V_262 V_263 ;
F_208 ( & V_263 ) ;
V_95 = V_95 - V_176 ;
F_127 ( V_189 , V_95 ) ;
V_283 = F_216 ( V_259 , V_176 ) - F_155 ( V_19 , V_259 ) ;
F_38 ( V_189 , V_259 , F_218 ( 0 ) ,
F_218 ( V_176 ) ,
V_95 * sizeof( struct V_184 ) ) ;
F_38 ( V_189 , V_259 ,
F_217 ( V_189 ) + F_156 ( V_19 ) -
V_283 , F_217 ( V_259 ) +
F_155 ( V_19 , V_259 ) , V_283 ) ;
V_284 = F_156 ( V_19 ) -
F_216 ( V_259 , V_176 ) ;
for ( V_6 = 0 ; V_6 < V_95 ; V_6 ++ ) {
struct V_184 * V_272 = F_209 ( V_6 ) ;
T_4 V_229 ;
V_229 = F_210 ( V_189 , V_272 , & V_263 ) ;
F_219 ( V_189 , V_272 ,
V_229 + V_284 , & V_263 ) ;
}
F_127 ( V_259 , V_176 ) ;
F_33 ( V_189 , & V_37 , 0 ) ;
F_206 ( V_29 , V_19 , V_2 , & V_37 , V_189 -> V_43 ,
V_2 -> V_17 [ 1 ] + 1 , 1 ) ;
F_49 ( V_189 ) ;
F_49 ( V_259 ) ;
F_75 ( V_2 -> V_17 [ 0 ] != V_76 ) ;
if ( V_176 <= V_76 ) {
F_21 ( V_2 -> V_8 [ 0 ] ) ;
F_12 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_189 ;
V_2 -> V_17 [ 0 ] -= V_176 ;
V_2 -> V_17 [ 1 ] += 1 ;
} else {
F_21 ( V_189 ) ;
F_12 ( V_189 ) ;
}
F_75 ( V_2 -> V_17 [ 0 ] < 0 ) ;
}
static T_1 int F_224 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
int V_266 )
{
int V_34 ;
int V_159 = 0 ;
int V_76 ;
T_4 V_95 ;
int V_285 = V_266 ;
V_76 = V_2 -> V_17 [ 0 ] ;
if ( V_76 < F_91 ( V_2 -> V_8 [ 0 ] ) )
V_285 -= F_195 ( V_19 , V_2 -> V_8 [ 0 ] ) ;
V_34 = F_220 ( V_29 , V_19 , V_2 , 1 , V_285 , 0 , V_76 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_34 == 0 )
V_159 ++ ;
V_95 = F_91 ( V_2 -> V_8 [ 0 ] ) ;
if ( V_2 -> V_17 [ 0 ] == 0 || V_2 -> V_17 [ 0 ] == V_95 )
return 0 ;
if ( F_195 ( V_19 , V_2 -> V_8 [ 0 ] ) >= V_266 )
return 0 ;
V_76 = V_2 -> V_17 [ 0 ] ;
V_34 = F_222 ( V_29 , V_19 , V_2 , 1 , V_285 , 0 , V_76 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_34 == 0 )
V_159 ++ ;
if ( V_159 )
return 0 ;
return 1 ;
}
static T_1 int F_196 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_153 * V_286 ,
struct V_1 * V_2 , int V_266 ,
int V_287 )
{
struct V_36 V_37 ;
struct V_14 * V_259 ;
T_4 V_95 ;
int V_176 ;
int V_76 ;
struct V_14 * V_189 ;
int V_34 = 0 ;
int V_191 ;
int V_257 ;
int V_288 = 0 ;
int V_289 = 0 ;
V_259 = V_2 -> V_8 [ 0 ] ;
V_76 = V_2 -> V_17 [ 0 ] ;
if ( V_287 && V_266 + F_225 ( V_259 , V_76 ) +
sizeof( struct V_184 ) > F_156 ( V_19 ) )
return - V_290 ;
if ( V_266 && V_2 -> V_8 [ 1 ] ) {
int V_285 = V_266 ;
if ( V_76 < F_91 ( V_259 ) )
V_285 -= F_195 ( V_19 , V_259 ) ;
V_191 = F_220 ( V_29 , V_19 , V_2 , V_285 ,
V_285 , 0 , 0 ) ;
if ( V_191 < 0 )
return V_191 ;
if ( V_191 ) {
V_191 = F_222 ( V_29 , V_19 , V_2 , V_285 ,
V_285 , 0 , ( T_4 ) - 1 ) ;
if ( V_191 < 0 )
return V_191 ;
}
V_259 = V_2 -> V_8 [ 0 ] ;
if ( F_195 ( V_19 , V_259 ) >= V_266 )
return 0 ;
}
if ( ! V_2 -> V_8 [ 1 ] ) {
V_34 = F_203 ( V_29 , V_19 , V_2 , 1 ) ;
if ( V_34 )
return V_34 ;
}
V_223:
V_257 = 1 ;
V_259 = V_2 -> V_8 [ 0 ] ;
V_76 = V_2 -> V_17 [ 0 ] ;
V_95 = F_91 ( V_259 ) ;
V_176 = ( V_95 + 1 ) / 2 ;
if ( V_176 <= V_76 ) {
if ( V_95 == 1 ||
F_207 ( V_259 , V_176 , V_95 - V_176 ) + V_266 >
F_156 ( V_19 ) ) {
if ( V_76 >= V_95 ) {
V_257 = 0 ;
} else {
V_176 = V_76 ;
if ( V_176 != V_95 &&
F_207 ( V_259 , V_176 , V_95 - V_176 ) +
V_266 > F_156 ( V_19 ) ) {
if ( V_266 && ! V_289 )
goto V_291;
V_257 = 2 ;
}
}
}
} else {
if ( F_207 ( V_259 , 0 , V_176 ) + V_266 >
F_156 ( V_19 ) ) {
if ( ! V_287 && V_266 && V_76 == 0 ) {
V_257 = 0 ;
} else if ( ( V_287 || ! V_266 ) && V_76 == 0 ) {
V_176 = 1 ;
} else {
V_176 = V_76 ;
if ( V_176 != V_95 &&
F_207 ( V_259 , V_176 , V_95 - V_176 ) +
V_266 > F_156 ( V_19 ) ) {
if ( V_266 && ! V_289 )
goto V_291;
V_257 = 2 ;
}
}
}
}
if ( V_257 == 0 )
F_186 ( & V_37 , V_286 ) ;
else
F_33 ( V_259 , & V_37 , V_176 ) ;
V_189 = F_35 ( V_29 , V_19 , V_19 -> V_292 , 0 ,
V_19 -> V_122 . V_123 ,
& V_37 , 0 , V_259 -> V_43 , 0 ) ;
if ( F_36 ( V_189 ) )
return F_37 ( V_189 ) ;
F_164 ( V_19 , V_19 -> V_292 ) ;
F_204 ( V_189 , 0 , 0 , sizeof( struct V_253 ) ) ;
F_39 ( V_189 , V_189 -> V_43 ) ;
F_40 ( V_189 , V_29 -> V_39 ) ;
F_41 ( V_189 , V_44 ) ;
F_44 ( V_189 , V_19 -> V_122 . V_123 ) ;
F_131 ( V_189 , 0 ) ;
F_45 ( V_189 , V_19 -> V_23 -> V_48 ,
F_46 () , V_49 ) ;
F_45 ( V_189 , V_19 -> V_23 -> V_254 ,
F_205 ( V_189 ) ,
V_255 ) ;
if ( V_257 == 0 ) {
if ( V_176 <= V_76 ) {
F_127 ( V_189 , 0 ) ;
F_206 ( V_29 , V_19 , V_2 , & V_37 , V_189 -> V_43 ,
V_2 -> V_17 [ 1 ] + 1 , 1 ) ;
F_21 ( V_2 -> V_8 [ 0 ] ) ;
F_12 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_189 ;
V_2 -> V_17 [ 0 ] = 0 ;
V_2 -> V_17 [ 1 ] += 1 ;
} else {
F_127 ( V_189 , 0 ) ;
F_206 ( V_29 , V_19 , V_2 , & V_37 , V_189 -> V_43 ,
V_2 -> V_17 [ 1 ] , 1 ) ;
F_21 ( V_2 -> V_8 [ 0 ] ) ;
F_12 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_189 ;
V_2 -> V_17 [ 0 ] = 0 ;
if ( V_2 -> V_17 [ 1 ] == 0 )
F_200 ( V_19 , V_2 , & V_37 , 1 ) ;
}
F_49 ( V_189 ) ;
return V_34 ;
}
F_223 ( V_29 , V_19 , V_2 , V_259 , V_189 , V_76 , V_176 , V_95 ) ;
if ( V_257 == 2 ) {
F_75 ( V_288 != 0 ) ;
V_288 ++ ;
goto V_223;
}
return 0 ;
V_291:
F_224 ( V_29 , V_19 , V_2 , V_266 ) ;
V_289 = 1 ;
if ( F_195 ( V_19 , V_2 -> V_8 [ 0 ] ) >= V_266 )
return 0 ;
goto V_223;
}
static T_1 int F_226 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_220 )
{
struct V_153 V_82 ;
struct V_14 * V_170 ;
struct V_293 * V_294 ;
T_2 V_295 = 0 ;
T_4 V_172 ;
int V_34 ;
V_170 = V_2 -> V_8 [ 0 ] ;
F_192 ( V_170 , & V_82 , V_2 -> V_17 [ 0 ] ) ;
F_75 ( V_82 . type != V_296 &&
V_82 . type != V_297 ) ;
if ( F_195 ( V_19 , V_170 ) >= V_220 )
return 0 ;
V_172 = F_225 ( V_170 , V_2 -> V_17 [ 0 ] ) ;
if ( V_82 . type == V_296 ) {
V_294 = F_227 ( V_170 , V_2 -> V_17 [ 0 ] ,
struct V_293 ) ;
V_295 = F_228 ( V_170 , V_294 ) ;
}
F_9 ( V_2 ) ;
V_2 -> V_216 = 1 ;
V_2 -> V_221 = 1 ;
V_34 = F_190 ( V_29 , V_19 , & V_82 , V_2 , 0 , 1 ) ;
V_2 -> V_221 = 0 ;
if ( V_34 < 0 )
goto V_164;
V_34 = - V_219 ;
V_170 = V_2 -> V_8 [ 0 ] ;
if ( V_34 > 0 || V_172 != F_225 ( V_170 , V_2 -> V_17 [ 0 ] ) )
goto V_164;
if ( F_195 ( V_19 , V_2 -> V_8 [ 0 ] ) >= V_220 )
goto V_164;
if ( V_82 . type == V_296 ) {
V_294 = F_227 ( V_170 , V_2 -> V_17 [ 0 ] ,
struct V_293 ) ;
if ( V_295 != F_228 ( V_170 , V_294 ) )
goto V_164;
}
F_3 ( V_2 ) ;
V_34 = F_196 ( V_29 , V_19 , & V_82 , V_2 , V_220 , 1 ) ;
if ( V_34 )
goto V_164;
V_2 -> V_216 = 0 ;
F_180 ( V_2 , 1 ) ;
return 0 ;
V_164:
V_2 -> V_216 = 0 ;
return V_34 ;
}
static T_1 int F_229 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_153 * V_243 ,
unsigned long V_298 )
{
struct V_14 * V_170 ;
struct V_184 * V_272 ;
struct V_184 * V_299 ;
int V_76 ;
char * V_30 ;
T_4 V_95 ;
T_4 V_172 ;
T_4 V_300 ;
struct V_36 V_37 ;
V_170 = V_2 -> V_8 [ 0 ] ;
F_75 ( F_195 ( V_19 , V_170 ) < sizeof( struct V_184 ) ) ;
F_3 ( V_2 ) ;
V_272 = F_209 ( V_2 -> V_17 [ 0 ] ) ;
V_300 = F_230 ( V_170 , V_272 ) ;
V_172 = F_215 ( V_170 , V_272 ) ;
V_30 = F_231 ( V_172 , V_4 ) ;
if ( ! V_30 )
return - V_85 ;
F_160 ( V_170 , V_30 , F_232 ( V_170 ,
V_2 -> V_17 [ 0 ] ) , V_172 ) ;
V_76 = V_2 -> V_17 [ 0 ] + 1 ;
V_95 = F_91 ( V_170 ) ;
if ( V_76 != V_95 ) {
F_126 ( V_170 , F_218 ( V_76 + 1 ) ,
F_218 ( V_76 ) ,
( V_95 - V_76 ) * sizeof( struct V_184 ) ) ;
}
F_186 ( & V_37 , V_243 ) ;
F_202 ( V_170 , & V_37 , V_76 ) ;
V_299 = F_209 ( V_76 ) ;
F_233 ( V_170 , V_299 , V_300 ) ;
F_234 ( V_170 , V_299 , V_172 - V_298 ) ;
F_233 ( V_170 , V_272 ,
V_300 + V_172 - V_298 ) ;
F_234 ( V_170 , V_272 , V_298 ) ;
F_127 ( V_170 , V_95 + 1 ) ;
F_45 ( V_170 , V_30 ,
F_232 ( V_170 , V_2 -> V_17 [ 0 ] ) ,
V_298 ) ;
F_45 ( V_170 , V_30 + V_298 ,
F_232 ( V_170 , V_76 ) ,
V_172 - V_298 ) ;
F_49 ( V_170 ) ;
F_75 ( F_195 ( V_19 , V_170 ) < 0 ) ;
F_73 ( V_30 ) ;
return 0 ;
}
int F_235 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_153 * V_243 ,
unsigned long V_298 )
{
int V_34 ;
V_34 = F_226 ( V_29 , V_19 , V_2 ,
sizeof( struct V_184 ) ) ;
if ( V_34 )
return V_34 ;
V_34 = F_229 ( V_29 , V_19 , V_2 , V_243 , V_298 ) ;
return V_34 ;
}
int F_236 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_153 * V_243 )
{
struct V_14 * V_170 ;
int V_34 ;
T_4 V_172 ;
V_170 = V_2 -> V_8 [ 0 ] ;
V_172 = F_225 ( V_170 , V_2 -> V_17 [ 0 ] ) ;
V_34 = F_226 ( V_29 , V_19 , V_2 ,
V_172 + sizeof( struct V_184 ) ) ;
if ( V_34 )
return V_34 ;
V_2 -> V_17 [ 0 ] ++ ;
F_237 ( V_19 , V_2 , V_243 , & V_172 ,
V_172 , V_172 +
sizeof( struct V_184 ) , 1 ) ;
V_170 = V_2 -> V_8 [ 0 ] ;
F_238 ( V_170 ,
F_232 ( V_170 , V_2 -> V_17 [ 0 ] ) ,
F_232 ( V_170 , V_2 -> V_17 [ 0 ] - 1 ) ,
V_172 ) ;
return 0 ;
}
void F_239 ( struct V_18 * V_19 , struct V_1 * V_2 ,
T_4 V_301 , int V_302 )
{
int V_76 ;
struct V_14 * V_170 ;
struct V_184 * V_272 ;
T_4 V_95 ;
unsigned int V_274 ;
unsigned int V_303 ;
unsigned int V_304 ;
unsigned int V_305 ;
int V_6 ;
struct V_262 V_263 ;
F_208 ( & V_263 ) ;
V_170 = V_2 -> V_8 [ 0 ] ;
V_76 = V_2 -> V_17 [ 0 ] ;
V_304 = F_225 ( V_170 , V_76 ) ;
if ( V_304 == V_301 )
return;
V_95 = F_91 ( V_170 ) ;
V_274 = F_155 ( V_19 , V_170 ) ;
V_303 = F_157 ( V_170 , V_76 ) ;
V_305 = V_304 - V_301 ;
F_75 ( V_76 < 0 ) ;
F_75 ( V_76 >= V_95 ) ;
for ( V_6 = V_76 ; V_6 < V_95 ; V_6 ++ ) {
T_4 V_229 ;
V_272 = F_209 ( V_6 ) ;
V_229 = F_210 ( V_170 , V_272 , & V_263 ) ;
F_219 ( V_170 , V_272 ,
V_229 + V_305 , & V_263 ) ;
}
if ( V_302 ) {
F_126 ( V_170 , F_217 ( V_170 ) +
V_274 + V_305 , F_217 ( V_170 ) +
V_274 , V_303 + V_301 - V_274 ) ;
} else {
struct V_36 V_37 ;
T_2 V_156 ;
F_33 ( V_170 , & V_37 , V_76 ) ;
if ( F_240 ( & V_37 ) == V_296 ) {
unsigned long V_306 ;
struct V_293 * V_294 ;
V_294 = F_227 ( V_170 , V_76 ,
struct V_293 ) ;
V_294 = (struct V_293 * ) (
( unsigned long ) V_294 - V_305 ) ;
if ( F_241 ( V_170 , V_294 ) ==
V_307 ) {
V_306 = F_232 ( V_170 , V_76 ) ;
F_126 ( V_170 , V_306 ,
( unsigned long ) V_294 ,
F_162 ( struct V_293 ,
V_308 ) ) ;
}
}
F_126 ( V_170 , F_217 ( V_170 ) +
V_274 + V_305 , F_217 ( V_170 ) +
V_274 , V_303 - V_274 ) ;
V_156 = F_242 ( & V_37 ) ;
F_243 ( & V_37 , V_156 + V_305 ) ;
F_202 ( V_170 , & V_37 , V_76 ) ;
if ( V_76 == 0 )
F_200 ( V_19 , V_2 , & V_37 , 1 ) ;
}
V_272 = F_209 ( V_76 ) ;
F_234 ( V_170 , V_272 , V_301 ) ;
F_49 ( V_170 ) ;
if ( F_195 ( V_19 , V_170 ) < 0 ) {
F_244 ( V_19 , V_170 ) ;
F_173 () ;
}
}
void F_245 ( struct V_18 * V_19 , struct V_1 * V_2 ,
T_4 V_266 )
{
int V_76 ;
struct V_14 * V_170 ;
struct V_184 * V_272 ;
T_4 V_95 ;
unsigned int V_274 ;
unsigned int V_309 ;
unsigned int V_304 ;
int V_6 ;
struct V_262 V_263 ;
F_208 ( & V_263 ) ;
V_170 = V_2 -> V_8 [ 0 ] ;
V_95 = F_91 ( V_170 ) ;
V_274 = F_155 ( V_19 , V_170 ) ;
if ( F_195 ( V_19 , V_170 ) < V_266 ) {
F_244 ( V_19 , V_170 ) ;
F_173 () ;
}
V_76 = V_2 -> V_17 [ 0 ] ;
V_309 = F_216 ( V_170 , V_76 ) ;
F_75 ( V_76 < 0 ) ;
if ( V_76 >= V_95 ) {
F_244 ( V_19 , V_170 ) ;
F_212 ( V_19 -> V_23 , L_5 ,
V_76 , V_95 ) ;
F_75 ( 1 ) ;
}
for ( V_6 = V_76 ; V_6 < V_95 ; V_6 ++ ) {
T_4 V_229 ;
V_272 = F_209 ( V_6 ) ;
V_229 = F_210 ( V_170 , V_272 , & V_263 ) ;
F_219 ( V_170 , V_272 ,
V_229 - V_266 , & V_263 ) ;
}
F_126 ( V_170 , F_217 ( V_170 ) +
V_274 - V_266 , F_217 ( V_170 ) +
V_274 , V_309 - V_274 ) ;
V_274 = V_309 ;
V_304 = F_225 ( V_170 , V_76 ) ;
V_272 = F_209 ( V_76 ) ;
F_234 ( V_170 , V_272 , V_304 + V_266 ) ;
F_49 ( V_170 ) ;
if ( F_195 ( V_19 , V_170 ) < 0 ) {
F_244 ( V_19 , V_170 ) ;
F_173 () ;
}
}
void F_237 ( struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_153 * V_310 , T_4 * V_266 ,
T_4 V_311 , T_4 V_312 , int V_171 )
{
struct V_184 * V_272 ;
int V_6 ;
T_4 V_95 ;
unsigned int V_274 ;
struct V_36 V_37 ;
struct V_14 * V_170 ;
int V_76 ;
struct V_262 V_263 ;
F_208 ( & V_263 ) ;
V_170 = V_2 -> V_8 [ 0 ] ;
V_76 = V_2 -> V_17 [ 0 ] ;
V_95 = F_91 ( V_170 ) ;
V_274 = F_155 ( V_19 , V_170 ) ;
if ( F_195 ( V_19 , V_170 ) < V_312 ) {
F_244 ( V_19 , V_170 ) ;
F_212 ( V_19 -> V_23 , L_6 ,
V_312 , F_195 ( V_19 , V_170 ) ) ;
F_173 () ;
}
if ( V_76 != V_95 ) {
unsigned int V_309 = F_216 ( V_170 , V_76 ) ;
if ( V_309 < V_274 ) {
F_244 ( V_19 , V_170 ) ;
F_212 ( V_19 -> V_23 , L_7 ,
V_76 , V_309 , V_274 ) ;
F_75 ( 1 ) ;
}
for ( V_6 = V_76 ; V_6 < V_95 ; V_6 ++ ) {
T_4 V_229 ;
V_272 = F_209 ( V_6 ) ;
V_229 = F_210 ( V_170 , V_272 , & V_263 ) ;
F_219 ( V_170 , V_272 ,
V_229 - V_311 , & V_263 ) ;
}
F_126 ( V_170 , F_218 ( V_76 + V_171 ) ,
F_218 ( V_76 ) ,
( V_95 - V_76 ) * sizeof( struct V_184 ) ) ;
F_126 ( V_170 , F_217 ( V_170 ) +
V_274 - V_311 , F_217 ( V_170 ) +
V_274 , V_309 - V_274 ) ;
V_274 = V_309 ;
}
for ( V_6 = 0 ; V_6 < V_171 ; V_6 ++ ) {
F_186 ( & V_37 , V_310 + V_6 ) ;
F_202 ( V_170 , & V_37 , V_76 + V_6 ) ;
V_272 = F_209 ( V_76 + V_6 ) ;
F_219 ( V_170 , V_272 ,
V_274 - V_266 [ V_6 ] , & V_263 ) ;
V_274 -= V_266 [ V_6 ] ;
F_246 ( V_170 , V_272 , V_266 [ V_6 ] , & V_263 ) ;
}
F_127 ( V_170 , V_95 + V_171 ) ;
if ( V_76 == 0 ) {
F_186 ( & V_37 , V_310 ) ;
F_200 ( V_19 , V_2 , & V_37 , 1 ) ;
}
F_180 ( V_2 , 1 ) ;
F_49 ( V_170 ) ;
if ( F_195 ( V_19 , V_170 ) < 0 ) {
F_244 ( V_19 , V_170 ) ;
F_173 () ;
}
}
int F_247 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_153 * V_310 , T_4 * V_266 ,
int V_171 )
{
int V_34 = 0 ;
int V_76 ;
int V_6 ;
T_4 V_312 = 0 ;
T_4 V_311 = 0 ;
for ( V_6 = 0 ; V_6 < V_171 ; V_6 ++ )
V_311 += V_266 [ V_6 ] ;
V_312 = V_311 + ( V_171 * sizeof( struct V_184 ) ) ;
V_34 = F_190 ( V_29 , V_19 , V_310 , V_2 , V_312 , 1 ) ;
if ( V_34 == 0 )
return - V_75 ;
if ( V_34 < 0 )
return V_34 ;
V_76 = V_2 -> V_17 [ 0 ] ;
F_75 ( V_76 < 0 ) ;
F_237 ( V_19 , V_2 , V_310 , V_266 ,
V_311 , V_312 , V_171 ) ;
return 0 ;
}
int F_248 ( struct V_28 * V_29 , struct V_18
* V_19 , struct V_153 * V_310 , void * V_313 , T_4
V_266 )
{
int V_34 = 0 ;
struct V_1 * V_2 ;
struct V_14 * V_170 ;
unsigned long V_306 ;
V_2 = F_1 () ;
if ( ! V_2 )
return - V_85 ;
V_34 = F_249 ( V_29 , V_19 , V_2 , V_310 , V_266 ) ;
if ( ! V_34 ) {
V_170 = V_2 -> V_8 [ 0 ] ;
V_306 = F_232 ( V_170 , V_2 -> V_17 [ 0 ] ) ;
F_45 ( V_170 , V_313 , V_306 , V_266 ) ;
F_49 ( V_170 ) ;
}
F_8 ( V_2 ) ;
return V_34 ;
}
static void F_171 ( struct V_18 * V_19 , struct V_1 * V_2 ,
int V_35 , int V_76 )
{
struct V_14 * V_70 = V_2 -> V_8 [ V_35 ] ;
T_4 V_95 ;
int V_34 ;
V_95 = F_91 ( V_70 ) ;
if ( V_76 != V_95 - 1 ) {
if ( V_35 )
F_96 ( V_19 -> V_23 , V_70 , V_76 ,
V_76 + 1 , V_95 - V_76 - 1 ) ;
F_126 ( V_70 ,
F_125 ( V_76 ) ,
F_125 ( V_76 + 1 ) ,
sizeof( struct V_139 ) *
( V_95 - V_76 - 1 ) ) ;
} else if ( V_35 ) {
V_34 = F_86 ( V_19 -> V_23 , V_70 , V_76 ,
V_111 , V_4 ) ;
F_75 ( V_34 < 0 ) ;
}
V_95 -- ;
F_127 ( V_70 , V_95 ) ;
if ( V_95 == 0 && V_70 == V_19 -> V_21 ) {
F_75 ( F_32 ( V_19 -> V_21 ) != 1 ) ;
F_131 ( V_19 -> V_21 , 0 ) ;
} else if ( V_76 == 0 ) {
struct V_36 V_37 ;
F_34 ( V_70 , & V_37 , 0 ) ;
F_200 ( V_19 , V_2 , & V_37 , V_35 + 1 ) ;
}
F_49 ( V_70 ) ;
}
static T_1 void F_250 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_14 * V_170 )
{
F_31 ( F_47 ( V_170 ) != V_29 -> V_39 ) ;
F_171 ( V_19 , V_2 , 1 , V_2 -> V_17 [ 1 ] ) ;
F_180 ( V_2 , 0 ) ;
F_167 ( V_19 , V_170 -> V_42 ) ;
F_116 ( V_170 ) ;
F_118 ( V_29 , V_19 , V_170 , 0 , 1 ) ;
F_121 ( V_170 ) ;
}
int F_251 ( struct V_28 * V_29 , struct V_18 * V_19 ,
struct V_1 * V_2 , int V_76 , int V_171 )
{
struct V_14 * V_170 ;
struct V_184 * V_272 ;
int V_314 ;
int V_315 = 0 ;
int V_34 = 0 ;
int V_191 ;
int V_6 ;
T_4 V_95 ;
struct V_262 V_263 ;
F_208 ( & V_263 ) ;
V_170 = V_2 -> V_8 [ 0 ] ;
V_314 = F_157 ( V_170 , V_76 + V_171 - 1 ) ;
for ( V_6 = 0 ; V_6 < V_171 ; V_6 ++ )
V_315 += F_225 ( V_170 , V_76 + V_6 ) ;
V_95 = F_91 ( V_170 ) ;
if ( V_76 + V_171 != V_95 ) {
int V_274 = F_155 ( V_19 , V_170 ) ;
F_126 ( V_170 , F_217 ( V_170 ) +
V_274 + V_315 ,
F_217 ( V_170 ) + V_274 ,
V_314 - V_274 ) ;
for ( V_6 = V_76 + V_171 ; V_6 < V_95 ; V_6 ++ ) {
T_4 V_229 ;
V_272 = F_209 ( V_6 ) ;
V_229 = F_210 ( V_170 , V_272 , & V_263 ) ;
F_219 ( V_170 , V_272 ,
V_229 + V_315 , & V_263 ) ;
}
F_126 ( V_170 , F_218 ( V_76 ) ,
F_218 ( V_76 + V_171 ) ,
sizeof( struct V_184 ) *
( V_95 - V_76 - V_171 ) ) ;
}
F_127 ( V_170 , V_95 - V_171 ) ;
V_95 -= V_171 ;
if ( V_95 == 0 ) {
if ( V_170 == V_19 -> V_21 ) {
F_131 ( V_170 , 0 ) ;
} else {
F_3 ( V_2 ) ;
F_111 ( V_29 , V_19 , V_170 ) ;
F_250 ( V_29 , V_19 , V_2 , V_170 ) ;
}
} else {
int V_316 = F_207 ( V_170 , 0 , V_95 ) ;
if ( V_76 == 0 ) {
struct V_36 V_37 ;
F_33 ( V_170 , & V_37 , 0 ) ;
F_200 ( V_19 , V_2 , & V_37 , 1 ) ;
}
if ( V_316 < F_156 ( V_19 ) / 3 ) {
V_76 = V_2 -> V_17 [ 1 ] ;
F_116 ( V_170 ) ;
F_3 ( V_2 ) ;
V_191 = F_222 ( V_29 , V_19 , V_2 , 1 , 1 ,
1 , ( T_4 ) - 1 ) ;
if ( V_191 < 0 && V_191 != - V_197 )
V_34 = V_191 ;
if ( V_2 -> V_8 [ 0 ] == V_170 &&
F_91 ( V_170 ) ) {
V_191 = F_220 ( V_29 , V_19 , V_2 , 1 ,
1 , 1 , 0 ) ;
if ( V_191 < 0 && V_191 != - V_197 )
V_34 = V_191 ;
}
if ( F_91 ( V_170 ) == 0 ) {
V_2 -> V_17 [ 1 ] = V_76 ;
F_250 ( V_29 , V_19 , V_2 , V_170 ) ;
F_12 ( V_170 ) ;
V_34 = 0 ;
} else {
if ( V_2 -> V_8 [ 0 ] == V_170 )
F_49 ( V_170 ) ;
F_12 ( V_170 ) ;
}
} else {
F_49 ( V_170 ) ;
}
}
return V_34 ;
}
int F_199 ( struct V_18 * V_19 , struct V_1 * V_2 )
{
struct V_153 V_82 ;
struct V_36 V_231 ;
int V_34 ;
F_192 ( V_2 -> V_8 [ 0 ] , & V_82 , 0 ) ;
if ( V_82 . V_156 > 0 ) {
V_82 . V_156 -- ;
} else if ( V_82 . type > 0 ) {
V_82 . type -- ;
V_82 . V_156 = ( T_2 ) - 1 ;
} else if ( V_82 . V_123 > 0 ) {
V_82 . V_123 -- ;
V_82 . type = ( T_5 ) - 1 ;
V_82 . V_156 = ( T_2 ) - 1 ;
} else {
return 1 ;
}
F_9 ( V_2 ) ;
V_34 = F_190 ( NULL , V_19 , & V_82 , V_2 , 0 , 0 ) ;
if ( V_34 < 0 )
return V_34 ;
F_33 ( V_2 -> V_8 [ 0 ] , & V_231 , 0 ) ;
V_34 = F_147 ( & V_231 , & V_82 ) ;
if ( V_34 < 0 )
return 0 ;
return 1 ;
}
int F_252 ( struct V_18 * V_19 , struct V_153 * V_317 ,
struct V_1 * V_2 ,
T_2 V_318 )
{
struct V_14 * V_71 ;
struct V_153 V_231 ;
int V_76 ;
int V_222 ;
T_4 V_95 ;
int V_35 ;
int V_34 = 1 ;
F_31 ( ! V_2 -> V_216 ) ;
V_223:
V_71 = F_22 ( V_19 ) ;
V_35 = F_32 ( V_71 ) ;
F_31 ( V_2 -> V_8 [ V_35 ] ) ;
V_2 -> V_8 [ V_35 ] = V_71 ;
V_2 -> V_9 [ V_35 ] = V_10 ;
if ( F_47 ( V_71 ) < V_318 ) {
V_34 = 1 ;
goto V_282;
}
while ( 1 ) {
V_95 = F_91 ( V_71 ) ;
V_35 = F_32 ( V_71 ) ;
V_222 = F_161 ( V_71 , V_317 , V_35 , & V_76 ) ;
if ( V_35 == V_2 -> V_233 ) {
if ( V_76 >= V_95 )
goto V_319;
V_34 = 0 ;
V_2 -> V_17 [ V_35 ] = V_76 ;
F_192 ( V_71 , & V_231 , V_76 ) ;
goto V_282;
}
if ( V_222 && V_76 > 0 )
V_76 -- ;
while ( V_76 < V_95 ) {
T_2 V_160 ;
V_160 = F_84 ( V_71 , V_76 ) ;
if ( V_160 < V_318 ) {
V_76 ++ ;
continue;
}
break;
}
V_319:
if ( V_76 >= V_95 ) {
V_2 -> V_17 [ V_35 ] = V_76 ;
F_3 ( V_2 ) ;
V_222 = F_253 ( V_19 , V_2 , V_317 , V_35 ,
V_318 ) ;
if ( V_222 == 0 ) {
F_9 ( V_2 ) ;
goto V_223;
} else {
goto V_282;
}
}
F_254 ( V_71 , & V_231 , V_76 ) ;
V_2 -> V_17 [ V_35 ] = V_76 ;
if ( V_35 == V_2 -> V_233 ) {
V_34 = 0 ;
F_179 ( V_2 , V_35 , 1 , 0 , NULL ) ;
goto V_282;
}
F_3 ( V_2 ) ;
V_71 = F_169 ( V_19 , V_71 , V_76 ) ;
F_75 ( ! V_71 ) ;
F_23 ( V_71 ) ;
V_2 -> V_9 [ V_35 - 1 ] = V_10 ;
V_2 -> V_8 [ V_35 - 1 ] = V_71 ;
F_179 ( V_2 , V_35 , 1 , 0 , NULL ) ;
F_5 ( V_2 , NULL , 0 ) ;
}
V_282:
if ( V_34 == 0 )
memcpy ( V_317 , & V_231 , sizeof( V_231 ) ) ;
F_3 ( V_2 ) ;
return V_34 ;
}
static void F_255 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int * V_35 , int V_320 )
{
F_75 ( * V_35 == 0 ) ;
V_2 -> V_8 [ * V_35 - 1 ] = F_169 ( V_19 , V_2 -> V_8 [ * V_35 ] ,
V_2 -> V_17 [ * V_35 ] ) ;
V_2 -> V_17 [ * V_35 - 1 ] = 0 ;
( * V_35 ) -- ;
}
static int F_256 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int * V_35 , int V_320 )
{
int V_34 = 0 ;
int V_95 ;
V_95 = F_91 ( V_2 -> V_8 [ * V_35 ] ) ;
V_2 -> V_17 [ * V_35 ] ++ ;
while ( V_2 -> V_17 [ * V_35 ] >= V_95 ) {
if ( * V_35 == V_320 )
return - 1 ;
V_2 -> V_17 [ * V_35 ] = 0 ;
F_12 ( V_2 -> V_8 [ * V_35 ] ) ;
V_2 -> V_8 [ * V_35 ] = NULL ;
( * V_35 ) ++ ;
V_2 -> V_17 [ * V_35 ] ++ ;
V_95 = F_91 ( V_2 -> V_8 [ * V_35 ] ) ;
V_34 = 1 ;
}
return V_34 ;
}
static int F_257 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int * V_35 , int V_320 ,
int V_321 ,
struct V_153 * V_82 )
{
int V_34 ;
if ( * V_35 == 0 || ! V_321 ) {
V_34 = F_256 ( V_19 , V_2 , V_35 , V_320 ) ;
} else {
F_255 ( V_19 , V_2 , V_35 , V_320 ) ;
V_34 = 0 ;
}
if ( V_34 >= 0 ) {
if ( * V_35 == 0 )
F_192 ( V_2 -> V_8 [ * V_35 ] , V_82 ,
V_2 -> V_17 [ * V_35 ] ) ;
else
F_254 ( V_2 -> V_8 [ * V_35 ] , V_82 ,
V_2 -> V_17 [ * V_35 ] ) ;
}
return V_34 ;
}
static int F_258 ( struct V_18 * V_322 ,
struct V_1 * V_323 ,
struct V_1 * V_324 ,
char * V_325 )
{
int V_326 ;
int V_327 , V_328 ;
unsigned long V_329 , V_330 ;
V_327 = F_225 ( V_323 -> V_8 [ 0 ] , V_323 -> V_17 [ 0 ] ) ;
V_328 = F_225 ( V_324 -> V_8 [ 0 ] , V_324 -> V_17 [ 0 ] ) ;
if ( V_327 != V_328 )
return 1 ;
V_329 = F_232 ( V_323 -> V_8 [ 0 ] , V_323 -> V_17 [ 0 ] ) ;
V_330 = F_232 ( V_324 -> V_8 [ 0 ] ,
V_324 -> V_17 [ 0 ] ) ;
F_160 ( V_323 -> V_8 [ 0 ] , V_325 , V_329 , V_327 ) ;
V_326 = F_187 ( V_324 -> V_8 [ 0 ] , V_325 , V_330 , V_327 ) ;
if ( V_326 )
return 1 ;
return 0 ;
}
int F_259 ( struct V_18 * V_322 ,
struct V_18 * V_331 ,
T_6 V_332 , void * V_333 )
{
int V_34 ;
int V_326 ;
struct V_28 * V_29 = NULL ;
struct V_1 * V_323 = NULL ;
struct V_1 * V_324 = NULL ;
struct V_153 V_334 ;
struct V_153 V_198 ;
char * V_325 = NULL ;
int V_335 ;
int V_336 ;
int V_337 ;
int V_338 ;
int V_339 ;
int V_340 ;
int V_341 ;
int V_342 ;
T_2 V_343 ;
T_2 V_344 ;
T_2 V_345 ;
T_2 V_346 ;
T_2 V_347 ;
V_323 = F_1 () ;
if ( ! V_323 ) {
V_34 = - V_85 ;
goto V_282;
}
V_324 = F_1 () ;
if ( ! V_324 ) {
V_34 = - V_85 ;
goto V_282;
}
V_325 = F_231 ( V_322 -> V_292 , V_4 ) ;
if ( ! V_325 ) {
V_34 = - V_85 ;
goto V_282;
}
V_323 -> V_234 = 1 ;
V_323 -> V_235 = 1 ;
V_324 -> V_234 = 1 ;
V_324 -> V_235 = 1 ;
F_26 ( & V_322 -> V_348 ) ;
V_345 = F_260 ( & V_322 -> V_117 ) ;
F_29 ( & V_322 -> V_348 ) ;
F_26 ( & V_331 -> V_348 ) ;
V_346 = F_260 ( & V_331 -> V_117 ) ;
F_29 ( & V_331 -> V_348 ) ;
V_29 = F_261 ( V_322 ) ;
if ( F_36 ( V_29 ) ) {
V_34 = F_37 ( V_29 ) ;
V_29 = NULL ;
goto V_282;
}
V_337 = F_32 ( V_322 -> V_116 ) ;
V_335 = V_337 ;
V_323 -> V_8 [ V_337 ] = V_322 -> V_116 ;
F_116 ( V_323 -> V_8 [ V_337 ] ) ;
V_338 = F_32 ( V_331 -> V_116 ) ;
V_336 = V_338 ;
V_324 -> V_8 [ V_338 ] = V_331 -> V_116 ;
F_116 ( V_324 -> V_8 [ V_338 ] ) ;
if ( V_337 == 0 )
F_192 ( V_323 -> V_8 [ V_337 ] ,
& V_334 , V_323 -> V_17 [ V_337 ] ) ;
else
F_254 ( V_323 -> V_8 [ V_337 ] ,
& V_334 , V_323 -> V_17 [ V_337 ] ) ;
if ( V_338 == 0 )
F_192 ( V_324 -> V_8 [ V_338 ] ,
& V_198 , V_324 -> V_17 [ V_338 ] ) ;
else
F_254 ( V_324 -> V_8 [ V_338 ] ,
& V_198 , V_324 -> V_17 [ V_338 ] ) ;
V_339 = V_340 = 0 ;
V_341 = V_342 = 0 ;
while ( 1 ) {
if ( V_29 && F_262 ( V_29 , V_322 ) ) {
F_9 ( V_323 ) ;
F_9 ( V_324 ) ;
V_34 = F_263 ( V_29 , V_322 ) ;
V_29 = NULL ;
if ( V_34 < 0 )
goto V_282;
}
if ( ! V_29 ) {
V_29 = F_261 ( V_322 ) ;
if ( F_36 ( V_29 ) ) {
V_34 = F_37 ( V_29 ) ;
V_29 = NULL ;
goto V_282;
}
F_26 ( & V_322 -> V_348 ) ;
V_347 = F_260 ( & V_322 -> V_117 ) ;
F_29 ( & V_322 -> V_348 ) ;
if ( V_347 != V_345 )
V_345 = 0 ;
F_26 ( & V_331 -> V_348 ) ;
V_347 = F_260 ( & V_331 -> V_117 ) ;
F_29 ( & V_331 -> V_348 ) ;
if ( V_347 != V_346 )
V_346 = 0 ;
if ( ! V_345 || ! V_346 ) {
F_143 ( 1 , V_349
L_8
L_9
L_10
L_11 ) ;
V_34 = - V_169 ;
goto V_282;
}
V_323 -> V_233 = V_337 ;
V_324 -> V_233 = V_338 ;
V_34 = F_190 ( NULL , V_322 ,
& V_334 , V_323 , 0 , 0 ) ;
if ( V_34 < 0 )
goto V_282;
V_34 = F_190 ( NULL , V_331 ,
& V_198 , V_324 , 0 , 0 ) ;
if ( V_34 < 0 )
goto V_282;
}
if ( V_341 && ! V_339 ) {
V_34 = F_257 ( V_322 , V_323 , & V_337 ,
V_335 ,
V_341 != V_350 ,
& V_334 ) ;
if ( V_34 < 0 )
V_339 = V_351 ;
V_341 = 0 ;
}
if ( V_342 && ! V_340 ) {
V_34 = F_257 ( V_331 , V_324 , & V_338 ,
V_336 ,
V_342 != V_350 ,
& V_198 ) ;
if ( V_34 < 0 )
V_340 = V_351 ;
V_342 = 0 ;
}
if ( V_339 && V_340 ) {
V_34 = 0 ;
goto V_282;
} else if ( V_339 ) {
if ( V_338 == 0 ) {
V_34 = V_332 ( V_322 , V_331 ,
V_323 , V_324 ,
& V_198 ,
V_352 ,
V_333 ) ;
if ( V_34 < 0 )
goto V_282;
}
V_342 = V_351 ;
continue;
} else if ( V_340 ) {
if ( V_337 == 0 ) {
V_34 = V_332 ( V_322 , V_331 ,
V_323 , V_324 ,
& V_334 ,
V_353 ,
V_333 ) ;
if ( V_34 < 0 )
goto V_282;
}
V_341 = V_351 ;
continue;
}
if ( V_337 == 0 && V_338 == 0 ) {
V_326 = F_149 ( & V_334 , & V_198 ) ;
if ( V_326 < 0 ) {
V_34 = V_332 ( V_322 , V_331 ,
V_323 , V_324 ,
& V_334 ,
V_353 ,
V_333 ) ;
if ( V_34 < 0 )
goto V_282;
V_341 = V_351 ;
} else if ( V_326 > 0 ) {
V_34 = V_332 ( V_322 , V_331 ,
V_323 , V_324 ,
& V_198 ,
V_352 ,
V_333 ) ;
if ( V_34 < 0 )
goto V_282;
V_342 = V_351 ;
} else {
enum V_354 V_326 ;
F_31 ( ! F_137 ( V_323 -> V_8 [ 0 ] ) ) ;
V_34 = F_258 ( V_322 , V_323 ,
V_324 , V_325 ) ;
if ( V_34 )
V_326 = V_355 ;
else
V_326 = V_356 ;
V_34 = V_332 ( V_322 , V_331 ,
V_323 , V_324 ,
& V_334 , V_326 , V_333 ) ;
if ( V_34 < 0 )
goto V_282;
V_341 = V_351 ;
V_342 = V_351 ;
}
} else if ( V_337 == V_338 ) {
V_326 = F_149 ( & V_334 , & V_198 ) ;
if ( V_326 < 0 ) {
V_341 = V_351 ;
} else if ( V_326 > 0 ) {
V_342 = V_351 ;
} else {
V_343 = F_83 (
V_323 -> V_8 [ V_337 ] ,
V_323 -> V_17 [ V_337 ] ) ;
V_344 = F_83 (
V_324 -> V_8 [ V_338 ] ,
V_324 -> V_17 [ V_338 ] ) ;
if ( V_343 == V_344 ) {
V_341 = V_350 ;
V_342 = V_350 ;
} else {
V_341 = V_351 ;
V_342 = V_351 ;
}
}
} else if ( V_337 < V_338 ) {
V_342 = V_351 ;
} else {
V_341 = V_351 ;
}
}
V_282:
F_8 ( V_323 ) ;
F_8 ( V_324 ) ;
F_73 ( V_325 ) ;
if ( V_29 ) {
if ( ! V_34 )
V_34 = F_263 ( V_29 , V_322 ) ;
else
F_263 ( V_29 , V_322 ) ;
}
return V_34 ;
}
int F_253 ( struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_153 * V_82 , int V_35 , T_2 V_318 )
{
int V_76 ;
struct V_14 * V_251 ;
F_31 ( ! V_2 -> V_216 ) ;
while ( V_35 < V_7 ) {
if ( ! V_2 -> V_8 [ V_35 ] )
return 1 ;
V_76 = V_2 -> V_17 [ V_35 ] + 1 ;
V_251 = V_2 -> V_8 [ V_35 ] ;
V_62:
if ( V_76 >= F_91 ( V_251 ) ) {
int V_34 ;
int V_357 ;
struct V_153 V_358 ;
if ( V_35 + 1 >= V_7 ||
! V_2 -> V_8 [ V_35 + 1 ] )
return 1 ;
if ( V_2 -> V_9 [ V_35 + 1 ] ) {
V_35 ++ ;
continue;
}
V_76 = F_91 ( V_251 ) - 1 ;
if ( V_35 == 0 )
F_192 ( V_251 , & V_358 , V_76 ) ;
else
F_254 ( V_251 , & V_358 , V_76 ) ;
V_357 = V_2 -> V_233 ;
F_9 ( V_2 ) ;
V_2 -> V_233 = V_35 ;
V_34 = F_190 ( NULL , V_19 , & V_358 , V_2 ,
0 , 0 ) ;
V_2 -> V_233 = V_357 ;
if ( V_34 < 0 )
return V_34 ;
V_251 = V_2 -> V_8 [ V_35 ] ;
V_76 = V_2 -> V_17 [ V_35 ] ;
if ( V_34 == 0 )
V_76 ++ ;
goto V_62;
}
if ( V_35 == 0 )
F_192 ( V_251 , V_82 , V_76 ) ;
else {
T_2 V_160 = F_84 ( V_251 , V_76 ) ;
if ( V_160 < V_318 ) {
V_76 ++ ;
goto V_62;
}
F_254 ( V_251 , V_82 , V_76 ) ;
}
return 0 ;
}
return 1 ;
}
int F_191 ( struct V_18 * V_19 , struct V_1 * V_2 )
{
return F_264 ( V_19 , V_2 , 0 ) ;
}
int F_264 ( struct V_18 * V_19 , struct V_1 * V_2 ,
T_2 V_131 )
{
int V_76 ;
int V_35 ;
struct V_14 * V_251 ;
struct V_14 * V_62 ;
struct V_153 V_82 ;
T_4 V_95 ;
int V_34 ;
int V_359 = V_2 -> V_239 ;
int V_360 = 0 ;
V_95 = F_91 ( V_2 -> V_8 [ 0 ] ) ;
if ( V_95 == 0 )
return 1 ;
F_192 ( V_2 -> V_8 [ 0 ] , & V_82 , V_95 - 1 ) ;
V_223:
V_35 = 1 ;
V_62 = NULL ;
V_360 = 0 ;
F_9 ( V_2 ) ;
V_2 -> V_216 = 1 ;
V_2 -> V_239 = 1 ;
if ( V_131 )
V_34 = F_197 ( V_19 , & V_82 , V_2 , V_131 ) ;
else
V_34 = F_190 ( NULL , V_19 , & V_82 , V_2 , 0 , 0 ) ;
V_2 -> V_216 = 0 ;
if ( V_34 < 0 )
return V_34 ;
V_95 = F_91 ( V_2 -> V_8 [ 0 ] ) ;
if ( V_95 > 0 && V_2 -> V_17 [ 0 ] < V_95 - 1 ) {
if ( V_34 == 0 )
V_2 -> V_17 [ 0 ] ++ ;
V_34 = 0 ;
goto V_224;
}
while ( V_35 < V_7 ) {
if ( ! V_2 -> V_8 [ V_35 ] ) {
V_34 = 1 ;
goto V_224;
}
V_76 = V_2 -> V_17 [ V_35 ] + 1 ;
V_251 = V_2 -> V_8 [ V_35 ] ;
if ( V_76 >= F_91 ( V_251 ) ) {
V_35 ++ ;
if ( V_35 == V_7 ) {
V_34 = 1 ;
goto V_224;
}
continue;
}
if ( V_62 ) {
F_11 ( V_62 , V_360 ) ;
F_12 ( V_62 ) ;
}
V_62 = V_251 ;
V_360 = V_2 -> V_9 [ V_35 ] ;
V_34 = F_181 ( NULL , V_19 , V_2 , & V_62 , V_35 ,
V_76 , & V_82 , 0 ) ;
if ( V_34 == - V_219 )
goto V_223;
if ( V_34 < 0 ) {
F_9 ( V_2 ) ;
goto V_224;
}
if ( ! V_2 -> V_235 ) {
V_34 = F_194 ( V_62 ) ;
if ( ! V_34 && V_131 ) {
F_12 ( V_62 ) ;
F_9 ( V_2 ) ;
F_265 () ;
goto V_223;
}
if ( ! V_34 ) {
F_3 ( V_2 ) ;
F_23 ( V_62 ) ;
F_5 ( V_2 , V_62 ,
V_10 ) ;
}
V_360 = V_10 ;
}
break;
}
V_2 -> V_17 [ V_35 ] = V_76 ;
while ( 1 ) {
V_35 -- ;
V_251 = V_2 -> V_8 [ V_35 ] ;
if ( V_2 -> V_9 [ V_35 ] )
F_11 ( V_251 , V_2 -> V_9 [ V_35 ] ) ;
F_12 ( V_251 ) ;
V_2 -> V_8 [ V_35 ] = V_62 ;
V_2 -> V_17 [ V_35 ] = 0 ;
if ( ! V_2 -> V_235 )
V_2 -> V_9 [ V_35 ] = V_360 ;
if ( ! V_35 )
break;
V_34 = F_181 ( NULL , V_19 , V_2 , & V_62 , V_35 ,
0 , & V_82 , 0 ) ;
if ( V_34 == - V_219 )
goto V_223;
if ( V_34 < 0 ) {
F_9 ( V_2 ) ;
goto V_224;
}
if ( ! V_2 -> V_235 ) {
V_34 = F_194 ( V_62 ) ;
if ( ! V_34 ) {
F_3 ( V_2 ) ;
F_23 ( V_62 ) ;
F_5 ( V_2 , V_62 ,
V_10 ) ;
}
V_360 = V_10 ;
}
}
V_34 = 0 ;
V_224:
F_179 ( V_2 , 0 , 1 , 0 , NULL ) ;
V_2 -> V_239 = V_359 ;
if ( ! V_359 )
F_3 ( V_2 ) ;
return V_34 ;
}
int F_266 ( struct V_18 * V_19 ,
struct V_1 * V_2 , T_2 V_361 ,
int type )
{
struct V_153 V_231 ;
struct V_14 * V_170 ;
T_4 V_95 ;
int V_34 ;
while ( 1 ) {
if ( V_2 -> V_17 [ 0 ] == 0 ) {
F_3 ( V_2 ) ;
V_34 = F_199 ( V_19 , V_2 ) ;
if ( V_34 != 0 )
return V_34 ;
} else {
V_2 -> V_17 [ 0 ] -- ;
}
V_170 = V_2 -> V_8 [ 0 ] ;
V_95 = F_91 ( V_170 ) ;
if ( V_95 == 0 )
return 1 ;
if ( V_2 -> V_17 [ 0 ] == V_95 )
V_2 -> V_17 [ 0 ] -- ;
F_192 ( V_170 , & V_231 , V_2 -> V_17 [ 0 ] ) ;
if ( V_231 . V_123 < V_361 )
break;
if ( V_231 . type == type )
return 0 ;
if ( V_231 . V_123 == V_361 &&
V_231 . type < type )
break;
}
return 1 ;
}
int F_267 ( struct V_18 * V_19 ,
struct V_1 * V_2 , T_2 V_361 )
{
struct V_153 V_231 ;
struct V_14 * V_170 ;
T_4 V_95 ;
int V_34 ;
while ( 1 ) {
if ( V_2 -> V_17 [ 0 ] == 0 ) {
F_3 ( V_2 ) ;
V_34 = F_199 ( V_19 , V_2 ) ;
if ( V_34 != 0 )
return V_34 ;
} else {
V_2 -> V_17 [ 0 ] -- ;
}
V_170 = V_2 -> V_8 [ 0 ] ;
V_95 = F_91 ( V_170 ) ;
if ( V_95 == 0 )
return 1 ;
if ( V_2 -> V_17 [ 0 ] == V_95 )
V_2 -> V_17 [ 0 ] -- ;
F_192 ( V_170 , & V_231 , V_2 -> V_17 [ 0 ] ) ;
if ( V_231 . V_123 < V_361 )
break;
if ( V_231 . type == V_362 ||
V_231 . type == V_363 )
return 0 ;
if ( V_231 . V_123 == V_361 &&
V_231 . type < V_362 )
break;
}
return 1 ;
}
