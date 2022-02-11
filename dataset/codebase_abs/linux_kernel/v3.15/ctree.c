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
if ( V_5 -> V_235 )
F_193 ( & V_19 -> V_23 -> V_236 ) ;
V_218 = V_19 -> V_116 ;
F_116 ( V_218 ) ;
V_35 = F_32 ( V_218 ) ;
if ( V_5 -> V_235 )
F_194 ( & V_19 -> V_23 -> V_236 ) ;
if ( ! V_5 -> V_237 )
F_23 ( V_218 ) ;
} else {
if ( V_5 -> V_237 ) {
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
if ( ! V_5 -> V_237 )
V_5 -> V_9 [ V_35 ] = V_232 ;
while ( V_218 ) {
V_35 = F_32 ( V_218 ) ;
if ( V_33 ) {
if ( ! F_140 ( V_29 , V_19 , V_218 ) )
goto V_238;
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
V_238:
V_5 -> V_8 [ V_35 ] = V_218 ;
F_5 ( V_5 , NULL , 0 ) ;
if ( ! V_220 && ! V_5 -> V_216 ) {
int V_239 = V_35 + 1 ;
if ( V_239 < V_7 && V_5 -> V_9 [ V_239 ] ) {
F_11 ( V_5 -> V_8 [ V_239 ] , V_5 -> V_9 [ V_239 ] ) ;
V_5 -> V_9 [ V_239 ] = 0 ;
}
}
V_34 = F_188 ( V_218 , V_82 , V_35 , & V_225 , & V_76 ) ;
if ( V_35 != 0 ) {
int V_240 = 0 ;
if ( V_34 && V_76 > 0 ) {
V_240 = 1 ;
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
if ( V_240 )
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
if ( ! V_5 -> V_237 ) {
V_35 = F_32 ( V_218 ) ;
if ( V_35 <= V_212 ) {
V_164 = F_195 ( V_218 ) ;
if ( ! V_164 ) {
F_3 ( V_5 ) ;
F_20 ( V_218 ) ;
F_5 ( V_5 , V_218 ,
V_12 ) ;
}
V_5 -> V_9 [ V_35 ] = V_12 ;
} else {
V_164 = F_196 ( V_218 ) ;
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
F_197 ( V_19 , V_218 ) < V_220 ) {
if ( V_212 < 1 ) {
V_212 = 1 ;
F_9 ( V_5 ) ;
goto V_223;
}
F_3 ( V_5 ) ;
V_164 = F_198 ( V_29 , V_19 , V_82 ,
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
if ( ! V_5 -> V_241 )
F_3 ( V_5 ) ;
if ( V_34 < 0 )
F_9 ( V_5 ) ;
return V_34 ;
}
int F_199 ( struct V_18 * V_19 , struct V_153 * V_82 ,
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
int V_240 = 0 ;
if ( V_34 && V_76 > 0 ) {
V_240 = 1 ;
V_76 -= 1 ;
}
V_5 -> V_17 [ V_35 ] = V_76 ;
F_179 ( V_5 , V_35 , V_210 , 0 , NULL ) ;
if ( V_35 == V_233 ) {
if ( V_240 )
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
V_164 = F_196 ( V_218 ) ;
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
if ( ! V_5 -> V_241 )
F_3 ( V_5 ) ;
if ( V_34 < 0 )
F_9 ( V_5 ) ;
return V_34 ;
}
int F_200 ( struct V_18 * V_19 ,
struct V_153 * V_82 , struct V_1 * V_5 ,
int V_242 , int V_243 )
{
int V_34 ;
struct V_14 * V_170 ;
V_223:
V_34 = F_190 ( NULL , V_19 , V_82 , V_5 , 0 , 0 ) ;
if ( V_34 <= 0 )
return V_34 ;
V_170 = V_5 -> V_8 [ 0 ] ;
if ( V_242 ) {
if ( V_5 -> V_17 [ 0 ] >= F_91 ( V_170 ) ) {
V_34 = F_191 ( V_19 , V_5 ) ;
if ( V_34 <= 0 )
return V_34 ;
if ( ! V_243 )
return 1 ;
V_243 = 0 ;
V_242 = 0 ;
F_9 ( V_5 ) ;
goto V_223;
}
} else {
if ( V_5 -> V_17 [ 0 ] == 0 ) {
V_34 = F_201 ( V_19 , V_5 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( ! V_34 ) {
V_170 = V_5 -> V_8 [ 0 ] ;
if ( V_5 -> V_17 [ 0 ] == F_91 ( V_170 ) )
V_5 -> V_17 [ 0 ] -- ;
return 0 ;
}
if ( ! V_243 )
return 1 ;
V_243 = 0 ;
V_242 = 1 ;
F_9 ( V_5 ) ;
goto V_223;
} else {
-- V_5 -> V_17 [ 0 ] ;
}
}
return 0 ;
}
static void F_202 ( struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_36 * V_82 , int V_35 )
{
int V_6 ;
struct V_14 * V_215 ;
for ( V_6 = V_35 ; V_6 < V_7 ; V_6 ++ ) {
int V_244 = V_2 -> V_17 [ V_6 ] ;
if ( ! V_2 -> V_8 [ V_6 ] )
break;
V_215 = V_2 -> V_8 [ V_6 ] ;
F_97 ( V_19 -> V_23 , V_215 , V_244 , 1 ) ;
F_124 ( V_215 , V_82 , V_244 ) ;
F_49 ( V_2 -> V_8 [ V_6 ] ) ;
if ( V_244 != 0 )
break;
}
}
void F_203 ( struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_153 * V_245 )
{
struct V_36 V_37 ;
struct V_14 * V_20 ;
int V_76 ;
V_20 = V_2 -> V_8 [ 0 ] ;
V_76 = V_2 -> V_17 [ 0 ] ;
if ( V_76 > 0 ) {
F_33 ( V_20 , & V_37 , V_76 - 1 ) ;
F_75 ( F_147 ( & V_37 , V_245 ) >= 0 ) ;
}
if ( V_76 < F_91 ( V_20 ) - 1 ) {
F_33 ( V_20 , & V_37 , V_76 + 1 ) ;
F_75 ( F_147 ( & V_37 , V_245 ) <= 0 ) ;
}
F_186 ( & V_37 , V_245 ) ;
F_204 ( V_20 , & V_37 , V_76 ) ;
F_49 ( V_20 ) ;
if ( V_76 == 0 )
F_202 ( V_19 , V_2 , & V_37 , 1 ) ;
}
static int F_170 ( struct V_28 * V_29 ,
struct V_18 * V_19 , struct V_14 * V_105 ,
struct V_14 * V_106 , int V_246 )
{
int V_247 = 0 ;
int V_248 ;
int V_249 ;
int V_34 = 0 ;
V_248 = F_91 ( V_106 ) ;
V_249 = F_91 ( V_105 ) ;
V_247 = F_133 ( V_19 ) - V_249 ;
F_31 ( F_47 ( V_106 ) != V_29 -> V_39 ) ;
F_31 ( F_47 ( V_105 ) != V_29 -> V_39 ) ;
if ( ! V_246 && V_248 <= 8 )
return 1 ;
if ( V_247 <= 0 )
return 1 ;
if ( V_246 ) {
V_247 = F_154 ( V_248 , V_247 ) ;
if ( V_247 < V_248 ) {
if ( V_248 - V_247 < 8 ) {
if ( V_247 <= 8 )
return 1 ;
V_247 -= 8 ;
}
}
} else
V_247 = F_154 ( V_248 - 8 , V_247 ) ;
V_34 = F_95 ( V_19 -> V_23 , V_105 , V_106 , V_249 , 0 ,
V_247 ) ;
if ( V_34 ) {
F_114 ( V_29 , V_19 , V_34 ) ;
return V_34 ;
}
F_38 ( V_105 , V_106 ,
F_125 ( V_249 ) ,
F_125 ( 0 ) ,
V_247 * sizeof( struct V_139 ) ) ;
if ( V_247 < V_248 ) {
F_126 ( V_106 , F_125 ( 0 ) ,
F_125 ( V_247 ) ,
( V_248 - V_247 ) *
sizeof( struct V_139 ) ) ;
}
F_127 ( V_106 , V_248 - V_247 ) ;
F_127 ( V_105 , V_249 + V_247 ) ;
F_49 ( V_106 ) ;
F_49 ( V_105 ) ;
return V_34 ;
}
static int F_172 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_14 * V_105 ,
struct V_14 * V_106 )
{
int V_247 = 0 ;
int V_250 ;
int V_248 ;
int V_249 ;
int V_34 = 0 ;
F_31 ( F_47 ( V_106 ) != V_29 -> V_39 ) ;
F_31 ( F_47 ( V_105 ) != V_29 -> V_39 ) ;
V_248 = F_91 ( V_106 ) ;
V_249 = F_91 ( V_105 ) ;
V_247 = F_133 ( V_19 ) - V_249 ;
if ( V_247 <= 0 )
return 1 ;
if ( V_248 < 4 )
return 1 ;
V_250 = V_248 / 2 + 1 ;
if ( V_250 >= V_248 )
return 1 ;
if ( V_250 < V_247 )
V_247 = V_250 ;
F_96 ( V_19 -> V_23 , V_105 , V_247 , 0 , V_249 ) ;
F_126 ( V_105 , F_125 ( V_247 ) ,
F_125 ( 0 ) ,
( V_249 ) *
sizeof( struct V_139 ) ) ;
V_34 = F_95 ( V_19 -> V_23 , V_105 , V_106 , 0 ,
V_248 - V_247 , V_247 ) ;
if ( V_34 ) {
F_114 ( V_29 , V_19 , V_34 ) ;
return V_34 ;
}
F_38 ( V_105 , V_106 ,
F_125 ( 0 ) ,
F_125 ( V_248 - V_247 ) ,
V_247 * sizeof( struct V_139 ) ) ;
F_127 ( V_106 , V_248 - V_247 ) ;
F_127 ( V_105 , V_249 + V_247 ) ;
F_49 ( V_106 ) ;
F_49 ( V_105 ) ;
return V_34 ;
}
static T_1 int F_205 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_35 )
{
T_2 V_251 ;
struct V_14 * V_252 ;
struct V_14 * V_253 ;
struct V_14 * V_143 ;
struct V_36 V_254 ;
F_75 ( V_2 -> V_8 [ V_35 ] ) ;
F_75 ( V_2 -> V_8 [ V_35 - 1 ] != V_19 -> V_21 ) ;
V_252 = V_2 -> V_8 [ V_35 - 1 ] ;
if ( V_35 == 1 )
F_33 ( V_252 , & V_254 , 0 ) ;
else
F_34 ( V_252 , & V_254 , 0 ) ;
V_253 = F_35 ( V_29 , V_19 , V_19 -> V_142 , 0 ,
V_19 -> V_122 . V_123 , & V_254 ,
V_35 , V_19 -> V_21 -> V_43 , 0 ) ;
if ( F_36 ( V_253 ) )
return F_37 ( V_253 ) ;
F_164 ( V_19 , V_19 -> V_142 ) ;
F_206 ( V_253 , 0 , 0 , sizeof( struct V_255 ) ) ;
F_127 ( V_253 , 1 ) ;
F_131 ( V_253 , V_35 ) ;
F_39 ( V_253 , V_253 -> V_43 ) ;
F_40 ( V_253 , V_29 -> V_39 ) ;
F_41 ( V_253 , V_44 ) ;
F_44 ( V_253 , V_19 -> V_122 . V_123 ) ;
F_45 ( V_253 , V_19 -> V_23 -> V_48 , F_46 () ,
V_49 ) ;
F_45 ( V_253 , V_19 -> V_23 -> V_256 ,
F_207 ( V_253 ) , V_257 ) ;
F_124 ( V_253 , & V_254 , 0 ) ;
F_119 ( V_253 , 0 , V_252 -> V_43 ) ;
V_251 = F_47 ( V_252 ) ;
F_31 ( V_251 != V_29 -> V_39 ) ;
F_120 ( V_253 , 0 , V_251 ) ;
F_49 ( V_253 ) ;
V_143 = V_19 -> V_21 ;
F_99 ( V_19 , V_253 , 0 ) ;
F_117 ( V_19 -> V_21 , V_253 ) ;
F_12 ( V_143 ) ;
F_25 ( V_19 ) ;
F_116 ( V_253 ) ;
V_2 -> V_8 [ V_35 ] = V_253 ;
V_2 -> V_9 [ V_35 ] = V_12 ;
V_2 -> V_17 [ V_35 ] = 0 ;
return 0 ;
}
static void F_208 ( struct V_28 * V_29 ,
struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_36 * V_82 , T_2 V_258 ,
int V_76 , int V_35 )
{
struct V_14 * V_252 ;
int V_95 ;
int V_34 ;
F_75 ( ! V_2 -> V_8 [ V_35 ] ) ;
F_113 ( V_2 -> V_8 [ V_35 ] ) ;
V_252 = V_2 -> V_8 [ V_35 ] ;
V_95 = F_91 ( V_252 ) ;
F_75 ( V_76 > V_95 ) ;
F_75 ( V_95 == F_133 ( V_19 ) ) ;
if ( V_76 != V_95 ) {
if ( V_35 )
F_96 ( V_19 -> V_23 , V_252 , V_76 + 1 ,
V_76 , V_95 - V_76 ) ;
F_126 ( V_252 ,
F_125 ( V_76 + 1 ) ,
F_125 ( V_76 ) ,
( V_95 - V_76 ) * sizeof( struct V_139 ) ) ;
}
if ( V_35 ) {
V_34 = F_86 ( V_19 -> V_23 , V_252 , V_76 ,
V_81 , V_4 ) ;
F_75 ( V_34 < 0 ) ;
}
F_124 ( V_252 , V_82 , V_76 ) ;
F_119 ( V_252 , V_76 , V_258 ) ;
F_31 ( V_29 -> V_39 == 0 ) ;
F_120 ( V_252 , V_76 , V_29 -> V_39 ) ;
F_127 ( V_252 , V_95 + 1 ) ;
F_49 ( V_252 ) ;
}
static T_1 int F_183 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_35 )
{
struct V_14 * V_253 ;
struct V_14 * V_259 ;
struct V_36 V_37 ;
int V_176 ;
int V_34 ;
T_4 V_260 ;
V_253 = V_2 -> V_8 [ V_35 ] ;
F_31 ( F_47 ( V_253 ) != V_29 -> V_39 ) ;
if ( V_253 == V_19 -> V_21 ) {
V_34 = F_205 ( V_29 , V_19 , V_2 , V_35 + 1 ) ;
if ( V_34 )
return V_34 ;
} else {
V_34 = F_174 ( V_29 , V_19 , V_2 , V_35 ) ;
V_253 = V_2 -> V_8 [ V_35 ] ;
if ( ! V_34 && F_91 ( V_253 ) <
F_133 ( V_19 ) - 3 )
return 0 ;
if ( V_34 < 0 )
return V_34 ;
}
V_260 = F_91 ( V_253 ) ;
V_176 = ( V_260 + 1 ) / 2 ;
F_34 ( V_253 , & V_37 , V_176 ) ;
V_259 = F_35 ( V_29 , V_19 , V_19 -> V_142 , 0 ,
V_19 -> V_122 . V_123 ,
& V_37 , V_35 , V_253 -> V_43 , 0 ) ;
if ( F_36 ( V_259 ) )
return F_37 ( V_259 ) ;
F_164 ( V_19 , V_19 -> V_142 ) ;
F_206 ( V_259 , 0 , 0 , sizeof( struct V_255 ) ) ;
F_131 ( V_259 , F_32 ( V_253 ) ) ;
F_39 ( V_259 , V_259 -> V_43 ) ;
F_40 ( V_259 , V_29 -> V_39 ) ;
F_41 ( V_259 , V_44 ) ;
F_44 ( V_259 , V_19 -> V_122 . V_123 ) ;
F_45 ( V_259 , V_19 -> V_23 -> V_48 ,
F_46 () , V_49 ) ;
F_45 ( V_259 , V_19 -> V_23 -> V_256 ,
F_207 ( V_259 ) ,
V_257 ) ;
V_34 = F_95 ( V_19 -> V_23 , V_259 , V_253 , 0 ,
V_176 , V_260 - V_176 ) ;
if ( V_34 ) {
F_114 ( V_29 , V_19 , V_34 ) ;
return V_34 ;
}
F_38 ( V_259 , V_253 ,
F_125 ( 0 ) ,
F_125 ( V_176 ) ,
( V_260 - V_176 ) * sizeof( struct V_139 ) ) ;
F_127 ( V_259 , V_260 - V_176 ) ;
F_127 ( V_253 , V_176 ) ;
V_34 = 0 ;
F_49 ( V_253 ) ;
F_49 ( V_259 ) ;
F_208 ( V_29 , V_19 , V_2 , & V_37 , V_259 -> V_43 ,
V_2 -> V_17 [ V_35 + 1 ] + 1 , V_35 + 1 ) ;
if ( V_2 -> V_17 [ V_35 ] >= V_176 ) {
V_2 -> V_17 [ V_35 ] -= V_176 ;
F_21 ( V_253 ) ;
F_12 ( V_253 ) ;
V_2 -> V_8 [ V_35 ] = V_259 ;
V_2 -> V_17 [ V_35 + 1 ] += 1 ;
} else {
F_21 ( V_259 ) ;
F_12 ( V_259 ) ;
}
return V_34 ;
}
static int F_209 ( struct V_14 * V_261 , int V_43 , int V_171 )
{
struct V_184 * V_262 ;
struct V_184 * V_263 ;
struct V_264 V_265 ;
int V_266 ;
int V_95 = F_91 ( V_261 ) ;
int V_267 = F_154 ( V_95 , V_43 + V_171 ) - 1 ;
if ( ! V_171 )
return 0 ;
F_210 ( & V_265 ) ;
V_262 = F_211 ( V_43 ) ;
V_263 = F_211 ( V_267 ) ;
V_266 = F_212 ( V_261 , V_262 , & V_265 ) +
F_213 ( V_261 , V_262 , & V_265 ) ;
V_266 = V_266 - F_212 ( V_261 , V_263 , & V_265 ) ;
V_266 += sizeof( struct V_184 ) * V_171 ;
F_31 ( V_266 < 0 ) ;
return V_266 ;
}
T_1 int F_197 ( struct V_18 * V_19 ,
struct V_14 * V_170 )
{
int V_95 = F_91 ( V_170 ) ;
int V_34 ;
V_34 = F_156 ( V_19 ) - F_209 ( V_170 , 0 , V_95 ) ;
if ( V_34 < 0 ) {
F_214 ( V_19 -> V_23 ,
L_3 ,
V_34 , ( unsigned long ) F_156 ( V_19 ) ,
F_209 ( V_170 , 0 , V_95 ) , V_95 ) ;
}
return V_34 ;
}
static T_1 int F_215 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
int V_268 , int V_246 ,
struct V_14 * V_189 ,
int V_269 , T_4 V_270 ,
T_4 V_271 )
{
struct V_14 * V_190 = V_2 -> V_8 [ 0 ] ;
struct V_14 * V_272 = V_2 -> V_8 [ 1 ] ;
struct V_264 V_265 ;
struct V_36 V_37 ;
int V_76 ;
T_4 V_6 ;
int V_273 = 0 ;
int V_247 = 0 ;
struct V_184 * V_274 ;
T_4 V_171 ;
T_4 V_275 ;
T_4 V_276 ;
T_4 V_277 ;
F_210 ( & V_265 ) ;
if ( V_246 )
V_171 = 0 ;
else
V_171 = F_216 ( T_4 , 1 , V_271 ) ;
if ( V_2 -> V_17 [ 0 ] >= V_270 )
V_273 += V_268 ;
V_76 = V_2 -> V_17 [ 1 ] ;
V_6 = V_270 - 1 ;
while ( V_6 >= V_171 ) {
V_274 = F_211 ( V_6 ) ;
if ( ! V_246 && V_247 > 0 ) {
if ( V_2 -> V_17 [ 0 ] > V_6 )
break;
if ( V_2 -> V_17 [ 0 ] == V_6 ) {
int V_278 = F_197 ( V_19 , V_190 ) ;
if ( V_278 + V_273 * 2 > V_269 )
break;
}
}
if ( V_2 -> V_17 [ 0 ] == V_6 )
V_273 += V_268 ;
V_277 = F_217 ( V_190 , V_274 ) ;
if ( V_277 + sizeof( * V_274 ) + V_273 > V_269 )
break;
V_247 ++ ;
V_273 += V_277 + sizeof( * V_274 ) ;
if ( V_6 == 0 )
break;
V_6 -- ;
}
if ( V_247 == 0 )
goto V_279;
F_31 ( ! V_246 && V_247 == V_270 ) ;
V_275 = F_91 ( V_189 ) ;
V_273 = F_218 ( V_190 , V_270 - V_247 ) ;
V_273 -= F_155 ( V_19 , V_190 ) ;
V_276 = F_155 ( V_19 , V_189 ) ;
F_126 ( V_189 ,
F_219 ( V_189 ) + V_276 - V_273 ,
F_219 ( V_189 ) + V_276 ,
F_156 ( V_19 ) - V_276 ) ;
F_38 ( V_189 , V_190 , F_219 ( V_189 ) +
F_156 ( V_19 ) - V_273 ,
F_219 ( V_190 ) + F_155 ( V_19 , V_190 ) ,
V_273 ) ;
F_126 ( V_189 , F_220 ( V_247 ) ,
F_220 ( 0 ) ,
V_275 * sizeof( struct V_184 ) ) ;
F_38 ( V_189 , V_190 , F_220 ( 0 ) ,
F_220 ( V_270 - V_247 ) ,
V_247 * sizeof( struct V_184 ) ) ;
V_275 += V_247 ;
F_127 ( V_189 , V_275 ) ;
V_273 = F_156 ( V_19 ) ;
for ( V_6 = 0 ; V_6 < V_275 ; V_6 ++ ) {
V_274 = F_211 ( V_6 ) ;
V_273 -= F_213 ( V_189 , V_274 , & V_265 ) ;
F_221 ( V_189 , V_274 , V_273 , & V_265 ) ;
}
V_270 -= V_247 ;
F_127 ( V_190 , V_270 ) ;
if ( V_270 )
F_49 ( V_190 ) ;
else
F_111 ( V_29 , V_19 , V_190 ) ;
F_49 ( V_189 ) ;
F_33 ( V_189 , & V_37 , 0 ) ;
F_124 ( V_272 , & V_37 , V_76 + 1 ) ;
F_49 ( V_272 ) ;
if ( V_2 -> V_17 [ 0 ] >= V_270 ) {
V_2 -> V_17 [ 0 ] -= V_270 ;
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
V_279:
F_21 ( V_189 ) ;
F_12 ( V_189 ) ;
return 1 ;
}
static int F_222 ( struct V_28 * V_29 , struct V_18
* V_19 , struct V_1 * V_2 ,
int V_280 , int V_268 ,
int V_246 , T_4 V_271 )
{
struct V_14 * V_190 = V_2 -> V_8 [ 0 ] ;
struct V_14 * V_189 ;
struct V_14 * V_272 ;
int V_76 ;
int V_269 ;
T_4 V_270 ;
int V_34 ;
if ( ! V_2 -> V_8 [ 1 ] )
return 1 ;
V_76 = V_2 -> V_17 [ 1 ] ;
V_272 = V_2 -> V_8 [ 1 ] ;
if ( V_76 >= F_91 ( V_272 ) - 1 )
return 1 ;
F_113 ( V_2 -> V_8 [ 1 ] ) ;
V_189 = F_169 ( V_19 , V_272 , V_76 + 1 ) ;
if ( V_189 == NULL )
return 1 ;
F_20 ( V_189 ) ;
F_144 ( V_189 ) ;
V_269 = F_197 ( V_19 , V_189 ) ;
if ( V_269 < V_268 )
goto V_279;
V_34 = F_142 ( V_29 , V_19 , V_189 , V_272 ,
V_76 + 1 , & V_189 ) ;
if ( V_34 )
goto V_279;
V_269 = F_197 ( V_19 , V_189 ) ;
if ( V_269 < V_268 )
goto V_279;
V_270 = F_91 ( V_190 ) ;
if ( V_270 == 0 )
goto V_279;
if ( V_2 -> V_17 [ 0 ] == V_270 && ! V_246 ) {
F_21 ( V_190 ) ;
F_12 ( V_190 ) ;
V_2 -> V_8 [ 0 ] = V_189 ;
V_2 -> V_17 [ 0 ] = 0 ;
V_2 -> V_17 [ 1 ] ++ ;
return 0 ;
}
return F_215 ( V_29 , V_19 , V_2 , V_280 , V_246 ,
V_189 , V_269 , V_270 , V_271 ) ;
V_279:
F_21 ( V_189 ) ;
F_12 ( V_189 ) ;
return 1 ;
}
static T_1 int F_223 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_268 ,
int V_246 , struct V_14 * V_190 ,
int V_269 , T_4 V_275 ,
T_4 V_281 )
{
struct V_36 V_37 ;
struct V_14 * V_189 = V_2 -> V_8 [ 0 ] ;
int V_6 ;
int V_273 = 0 ;
int V_247 = 0 ;
struct V_184 * V_274 ;
T_4 V_282 ;
T_4 V_171 ;
int V_34 = 0 ;
T_4 V_277 ;
T_4 V_283 ;
struct V_264 V_265 ;
F_210 ( & V_265 ) ;
if ( V_246 )
V_171 = F_154 ( V_275 , V_281 ) ;
else
V_171 = F_154 ( V_275 - 1 , V_281 ) ;
for ( V_6 = 0 ; V_6 < V_171 ; V_6 ++ ) {
V_274 = F_211 ( V_6 ) ;
if ( ! V_246 && V_247 > 0 ) {
if ( V_2 -> V_17 [ 0 ] < V_6 )
break;
if ( V_2 -> V_17 [ 0 ] == V_6 ) {
int V_278 = F_197 ( V_19 , V_189 ) ;
if ( V_278 + V_273 * 2 > V_269 )
break;
}
}
if ( V_2 -> V_17 [ 0 ] == V_6 )
V_273 += V_268 ;
V_277 = F_217 ( V_189 , V_274 ) ;
if ( V_277 + sizeof( * V_274 ) + V_273 > V_269 )
break;
V_247 ++ ;
V_273 += V_277 + sizeof( * V_274 ) ;
}
if ( V_247 == 0 ) {
V_34 = 1 ;
goto V_284;
}
F_31 ( ! V_246 && V_247 == F_91 ( V_189 ) ) ;
F_38 ( V_190 , V_189 ,
F_220 ( F_91 ( V_190 ) ) ,
F_220 ( 0 ) ,
V_247 * sizeof( struct V_184 ) ) ;
V_273 = F_156 ( V_19 ) -
F_157 ( V_189 , V_247 - 1 ) ;
F_38 ( V_190 , V_189 , F_219 ( V_190 ) +
F_155 ( V_19 , V_190 ) - V_273 ,
F_219 ( V_189 ) +
F_157 ( V_189 , V_247 - 1 ) ,
V_273 ) ;
V_282 = F_91 ( V_190 ) ;
F_75 ( V_282 <= 0 ) ;
V_283 = F_157 ( V_190 , V_282 - 1 ) ;
for ( V_6 = V_282 ; V_6 < V_282 + V_247 ; V_6 ++ ) {
T_4 V_229 ;
V_274 = F_211 ( V_6 ) ;
V_229 = F_212 ( V_190 , V_274 , & V_265 ) ;
F_221 ( V_190 , V_274 ,
V_229 - ( F_156 ( V_19 ) - V_283 ) ,
& V_265 ) ;
}
F_127 ( V_190 , V_282 + V_247 ) ;
if ( V_247 > V_275 )
F_143 ( 1 , V_149 L_4 , V_247 ,
V_275 ) ;
if ( V_247 < V_275 ) {
V_273 = F_157 ( V_189 , V_247 - 1 ) -
F_155 ( V_19 , V_189 ) ;
F_126 ( V_189 , F_219 ( V_189 ) +
F_156 ( V_19 ) - V_273 ,
F_219 ( V_189 ) +
F_155 ( V_19 , V_189 ) , V_273 ) ;
F_126 ( V_189 , F_220 ( 0 ) ,
F_220 ( V_247 ) ,
( F_91 ( V_189 ) - V_247 ) *
sizeof( struct V_184 ) ) ;
}
V_275 -= V_247 ;
F_127 ( V_189 , V_275 ) ;
V_273 = F_156 ( V_19 ) ;
for ( V_6 = 0 ; V_6 < V_275 ; V_6 ++ ) {
V_274 = F_211 ( V_6 ) ;
V_273 = V_273 - F_213 ( V_189 ,
V_274 , & V_265 ) ;
F_221 ( V_189 , V_274 , V_273 , & V_265 ) ;
}
F_49 ( V_190 ) ;
if ( V_275 )
F_49 ( V_189 ) ;
else
F_111 ( V_29 , V_19 , V_189 ) ;
F_33 ( V_189 , & V_37 , 0 ) ;
F_202 ( V_19 , V_2 , & V_37 , 1 ) ;
if ( V_2 -> V_17 [ 0 ] < V_247 ) {
V_2 -> V_17 [ 0 ] += V_282 ;
F_21 ( V_2 -> V_8 [ 0 ] ) ;
F_12 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_190 ;
V_2 -> V_17 [ 1 ] -= 1 ;
} else {
F_21 ( V_190 ) ;
F_12 ( V_190 ) ;
V_2 -> V_17 [ 0 ] -= V_247 ;
}
F_75 ( V_2 -> V_17 [ 0 ] < 0 ) ;
return V_34 ;
V_284:
F_21 ( V_190 ) ;
F_12 ( V_190 ) ;
return V_34 ;
}
static int F_224 ( struct V_28 * V_29 , struct V_18
* V_19 , struct V_1 * V_2 , int V_280 ,
int V_268 , int V_246 , T_4 V_281 )
{
struct V_14 * V_189 = V_2 -> V_8 [ 0 ] ;
struct V_14 * V_190 ;
int V_76 ;
int V_269 ;
T_4 V_275 ;
int V_34 = 0 ;
V_76 = V_2 -> V_17 [ 1 ] ;
if ( V_76 == 0 )
return 1 ;
if ( ! V_2 -> V_8 [ 1 ] )
return 1 ;
V_275 = F_91 ( V_189 ) ;
if ( V_275 == 0 )
return 1 ;
F_113 ( V_2 -> V_8 [ 1 ] ) ;
V_190 = F_169 ( V_19 , V_2 -> V_8 [ 1 ] , V_76 - 1 ) ;
if ( V_190 == NULL )
return 1 ;
F_20 ( V_190 ) ;
F_144 ( V_190 ) ;
V_269 = F_197 ( V_19 , V_190 ) ;
if ( V_269 < V_268 ) {
V_34 = 1 ;
goto V_284;
}
V_34 = F_142 ( V_29 , V_19 , V_190 ,
V_2 -> V_8 [ 1 ] , V_76 - 1 , & V_190 ) ;
if ( V_34 ) {
if ( V_34 == - V_197 )
V_34 = 1 ;
goto V_284;
}
V_269 = F_197 ( V_19 , V_190 ) ;
if ( V_269 < V_268 ) {
V_34 = 1 ;
goto V_284;
}
return F_223 ( V_29 , V_19 , V_2 , V_280 ,
V_246 , V_190 , V_269 , V_275 ,
V_281 ) ;
V_284:
F_21 ( V_190 ) ;
F_12 ( V_190 ) ;
return V_34 ;
}
static T_1 void F_225 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_14 * V_261 ,
struct V_14 * V_189 ,
int V_76 , int V_176 , int V_95 )
{
int V_285 ;
int V_286 ;
int V_6 ;
struct V_36 V_37 ;
struct V_264 V_265 ;
F_210 ( & V_265 ) ;
V_95 = V_95 - V_176 ;
F_127 ( V_189 , V_95 ) ;
V_285 = F_218 ( V_261 , V_176 ) - F_155 ( V_19 , V_261 ) ;
F_38 ( V_189 , V_261 , F_220 ( 0 ) ,
F_220 ( V_176 ) ,
V_95 * sizeof( struct V_184 ) ) ;
F_38 ( V_189 , V_261 ,
F_219 ( V_189 ) + F_156 ( V_19 ) -
V_285 , F_219 ( V_261 ) +
F_155 ( V_19 , V_261 ) , V_285 ) ;
V_286 = F_156 ( V_19 ) -
F_218 ( V_261 , V_176 ) ;
for ( V_6 = 0 ; V_6 < V_95 ; V_6 ++ ) {
struct V_184 * V_274 = F_211 ( V_6 ) ;
T_4 V_229 ;
V_229 = F_212 ( V_189 , V_274 , & V_265 ) ;
F_221 ( V_189 , V_274 ,
V_229 + V_286 , & V_265 ) ;
}
F_127 ( V_261 , V_176 ) ;
F_33 ( V_189 , & V_37 , 0 ) ;
F_208 ( V_29 , V_19 , V_2 , & V_37 , V_189 -> V_43 ,
V_2 -> V_17 [ 1 ] + 1 , 1 ) ;
F_49 ( V_189 ) ;
F_49 ( V_261 ) ;
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
static T_1 int F_226 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
int V_268 )
{
int V_34 ;
int V_159 = 0 ;
int V_76 ;
T_4 V_95 ;
int V_287 = V_268 ;
V_76 = V_2 -> V_17 [ 0 ] ;
if ( V_76 < F_91 ( V_2 -> V_8 [ 0 ] ) )
V_287 -= F_197 ( V_19 , V_2 -> V_8 [ 0 ] ) ;
V_34 = F_222 ( V_29 , V_19 , V_2 , 1 , V_287 , 0 , V_76 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_34 == 0 )
V_159 ++ ;
V_95 = F_91 ( V_2 -> V_8 [ 0 ] ) ;
if ( V_2 -> V_17 [ 0 ] == 0 || V_2 -> V_17 [ 0 ] == V_95 )
return 0 ;
if ( F_197 ( V_19 , V_2 -> V_8 [ 0 ] ) >= V_268 )
return 0 ;
V_76 = V_2 -> V_17 [ 0 ] ;
V_34 = F_224 ( V_29 , V_19 , V_2 , 1 , V_287 , 0 , V_76 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_34 == 0 )
V_159 ++ ;
if ( V_159 )
return 0 ;
return 1 ;
}
static T_1 int F_198 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_153 * V_288 ,
struct V_1 * V_2 , int V_268 ,
int V_289 )
{
struct V_36 V_37 ;
struct V_14 * V_261 ;
T_4 V_95 ;
int V_176 ;
int V_76 ;
struct V_14 * V_189 ;
int V_34 = 0 ;
int V_191 ;
int V_259 ;
int V_290 = 0 ;
int V_291 = 0 ;
V_261 = V_2 -> V_8 [ 0 ] ;
V_76 = V_2 -> V_17 [ 0 ] ;
if ( V_289 && V_268 + F_227 ( V_261 , V_76 ) +
sizeof( struct V_184 ) > F_156 ( V_19 ) )
return - V_292 ;
if ( V_268 && V_2 -> V_8 [ 1 ] ) {
int V_287 = V_268 ;
if ( V_76 < F_91 ( V_261 ) )
V_287 -= F_197 ( V_19 , V_261 ) ;
V_191 = F_222 ( V_29 , V_19 , V_2 , V_287 ,
V_287 , 0 , 0 ) ;
if ( V_191 < 0 )
return V_191 ;
if ( V_191 ) {
V_191 = F_224 ( V_29 , V_19 , V_2 , V_287 ,
V_287 , 0 , ( T_4 ) - 1 ) ;
if ( V_191 < 0 )
return V_191 ;
}
V_261 = V_2 -> V_8 [ 0 ] ;
if ( F_197 ( V_19 , V_261 ) >= V_268 )
return 0 ;
}
if ( ! V_2 -> V_8 [ 1 ] ) {
V_34 = F_205 ( V_29 , V_19 , V_2 , 1 ) ;
if ( V_34 )
return V_34 ;
}
V_223:
V_259 = 1 ;
V_261 = V_2 -> V_8 [ 0 ] ;
V_76 = V_2 -> V_17 [ 0 ] ;
V_95 = F_91 ( V_261 ) ;
V_176 = ( V_95 + 1 ) / 2 ;
if ( V_176 <= V_76 ) {
if ( V_95 == 1 ||
F_209 ( V_261 , V_176 , V_95 - V_176 ) + V_268 >
F_156 ( V_19 ) ) {
if ( V_76 >= V_95 ) {
V_259 = 0 ;
} else {
V_176 = V_76 ;
if ( V_176 != V_95 &&
F_209 ( V_261 , V_176 , V_95 - V_176 ) +
V_268 > F_156 ( V_19 ) ) {
if ( V_268 && ! V_291 )
goto V_293;
V_259 = 2 ;
}
}
}
} else {
if ( F_209 ( V_261 , 0 , V_176 ) + V_268 >
F_156 ( V_19 ) ) {
if ( ! V_289 && V_268 && V_76 == 0 ) {
V_259 = 0 ;
} else if ( ( V_289 || ! V_268 ) && V_76 == 0 ) {
V_176 = 1 ;
} else {
V_176 = V_76 ;
if ( V_176 != V_95 &&
F_209 ( V_261 , V_176 , V_95 - V_176 ) +
V_268 > F_156 ( V_19 ) ) {
if ( V_268 && ! V_291 )
goto V_293;
V_259 = 2 ;
}
}
}
}
if ( V_259 == 0 )
F_186 ( & V_37 , V_288 ) ;
else
F_33 ( V_261 , & V_37 , V_176 ) ;
V_189 = F_35 ( V_29 , V_19 , V_19 -> V_294 , 0 ,
V_19 -> V_122 . V_123 ,
& V_37 , 0 , V_261 -> V_43 , 0 ) ;
if ( F_36 ( V_189 ) )
return F_37 ( V_189 ) ;
F_164 ( V_19 , V_19 -> V_294 ) ;
F_206 ( V_189 , 0 , 0 , sizeof( struct V_255 ) ) ;
F_39 ( V_189 , V_189 -> V_43 ) ;
F_40 ( V_189 , V_29 -> V_39 ) ;
F_41 ( V_189 , V_44 ) ;
F_44 ( V_189 , V_19 -> V_122 . V_123 ) ;
F_131 ( V_189 , 0 ) ;
F_45 ( V_189 , V_19 -> V_23 -> V_48 ,
F_46 () , V_49 ) ;
F_45 ( V_189 , V_19 -> V_23 -> V_256 ,
F_207 ( V_189 ) ,
V_257 ) ;
if ( V_259 == 0 ) {
if ( V_176 <= V_76 ) {
F_127 ( V_189 , 0 ) ;
F_208 ( V_29 , V_19 , V_2 , & V_37 , V_189 -> V_43 ,
V_2 -> V_17 [ 1 ] + 1 , 1 ) ;
F_21 ( V_2 -> V_8 [ 0 ] ) ;
F_12 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_189 ;
V_2 -> V_17 [ 0 ] = 0 ;
V_2 -> V_17 [ 1 ] += 1 ;
} else {
F_127 ( V_189 , 0 ) ;
F_208 ( V_29 , V_19 , V_2 , & V_37 , V_189 -> V_43 ,
V_2 -> V_17 [ 1 ] , 1 ) ;
F_21 ( V_2 -> V_8 [ 0 ] ) ;
F_12 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_189 ;
V_2 -> V_17 [ 0 ] = 0 ;
if ( V_2 -> V_17 [ 1 ] == 0 )
F_202 ( V_19 , V_2 , & V_37 , 1 ) ;
}
F_49 ( V_189 ) ;
return V_34 ;
}
F_225 ( V_29 , V_19 , V_2 , V_261 , V_189 , V_76 , V_176 , V_95 ) ;
if ( V_259 == 2 ) {
F_75 ( V_290 != 0 ) ;
V_290 ++ ;
goto V_223;
}
return 0 ;
V_293:
F_226 ( V_29 , V_19 , V_2 , V_268 ) ;
V_291 = 1 ;
if ( F_197 ( V_19 , V_2 -> V_8 [ 0 ] ) >= V_268 )
return 0 ;
goto V_223;
}
static T_1 int F_228 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_220 )
{
struct V_153 V_82 ;
struct V_14 * V_170 ;
struct V_295 * V_296 ;
T_2 V_297 = 0 ;
T_4 V_172 ;
int V_34 ;
V_170 = V_2 -> V_8 [ 0 ] ;
F_192 ( V_170 , & V_82 , V_2 -> V_17 [ 0 ] ) ;
F_75 ( V_82 . type != V_298 &&
V_82 . type != V_299 ) ;
if ( F_197 ( V_19 , V_170 ) >= V_220 )
return 0 ;
V_172 = F_227 ( V_170 , V_2 -> V_17 [ 0 ] ) ;
if ( V_82 . type == V_298 ) {
V_296 = F_229 ( V_170 , V_2 -> V_17 [ 0 ] ,
struct V_295 ) ;
V_297 = F_230 ( V_170 , V_296 ) ;
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
if ( V_34 > 0 || V_172 != F_227 ( V_170 , V_2 -> V_17 [ 0 ] ) )
goto V_164;
if ( F_197 ( V_19 , V_2 -> V_8 [ 0 ] ) >= V_220 )
goto V_164;
if ( V_82 . type == V_298 ) {
V_296 = F_229 ( V_170 , V_2 -> V_17 [ 0 ] ,
struct V_295 ) ;
if ( V_297 != F_230 ( V_170 , V_296 ) )
goto V_164;
}
F_3 ( V_2 ) ;
V_34 = F_198 ( V_29 , V_19 , & V_82 , V_2 , V_220 , 1 ) ;
if ( V_34 )
goto V_164;
V_2 -> V_216 = 0 ;
F_180 ( V_2 , 1 ) ;
return 0 ;
V_164:
V_2 -> V_216 = 0 ;
return V_34 ;
}
static T_1 int F_231 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_153 * V_245 ,
unsigned long V_300 )
{
struct V_14 * V_170 ;
struct V_184 * V_274 ;
struct V_184 * V_301 ;
int V_76 ;
char * V_30 ;
T_4 V_95 ;
T_4 V_172 ;
T_4 V_302 ;
struct V_36 V_37 ;
V_170 = V_2 -> V_8 [ 0 ] ;
F_75 ( F_197 ( V_19 , V_170 ) < sizeof( struct V_184 ) ) ;
F_3 ( V_2 ) ;
V_274 = F_211 ( V_2 -> V_17 [ 0 ] ) ;
V_302 = F_232 ( V_170 , V_274 ) ;
V_172 = F_217 ( V_170 , V_274 ) ;
V_30 = F_233 ( V_172 , V_4 ) ;
if ( ! V_30 )
return - V_85 ;
F_160 ( V_170 , V_30 , F_234 ( V_170 ,
V_2 -> V_17 [ 0 ] ) , V_172 ) ;
V_76 = V_2 -> V_17 [ 0 ] + 1 ;
V_95 = F_91 ( V_170 ) ;
if ( V_76 != V_95 ) {
F_126 ( V_170 , F_220 ( V_76 + 1 ) ,
F_220 ( V_76 ) ,
( V_95 - V_76 ) * sizeof( struct V_184 ) ) ;
}
F_186 ( & V_37 , V_245 ) ;
F_204 ( V_170 , & V_37 , V_76 ) ;
V_301 = F_211 ( V_76 ) ;
F_235 ( V_170 , V_301 , V_302 ) ;
F_236 ( V_170 , V_301 , V_172 - V_300 ) ;
F_235 ( V_170 , V_274 ,
V_302 + V_172 - V_300 ) ;
F_236 ( V_170 , V_274 , V_300 ) ;
F_127 ( V_170 , V_95 + 1 ) ;
F_45 ( V_170 , V_30 ,
F_234 ( V_170 , V_2 -> V_17 [ 0 ] ) ,
V_300 ) ;
F_45 ( V_170 , V_30 + V_300 ,
F_234 ( V_170 , V_76 ) ,
V_172 - V_300 ) ;
F_49 ( V_170 ) ;
F_75 ( F_197 ( V_19 , V_170 ) < 0 ) ;
F_73 ( V_30 ) ;
return 0 ;
}
int F_237 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_153 * V_245 ,
unsigned long V_300 )
{
int V_34 ;
V_34 = F_228 ( V_29 , V_19 , V_2 ,
sizeof( struct V_184 ) ) ;
if ( V_34 )
return V_34 ;
V_34 = F_231 ( V_29 , V_19 , V_2 , V_245 , V_300 ) ;
return V_34 ;
}
int F_238 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_153 * V_245 )
{
struct V_14 * V_170 ;
int V_34 ;
T_4 V_172 ;
V_170 = V_2 -> V_8 [ 0 ] ;
V_172 = F_227 ( V_170 , V_2 -> V_17 [ 0 ] ) ;
V_34 = F_228 ( V_29 , V_19 , V_2 ,
V_172 + sizeof( struct V_184 ) ) ;
if ( V_34 )
return V_34 ;
V_2 -> V_17 [ 0 ] ++ ;
F_239 ( V_19 , V_2 , V_245 , & V_172 ,
V_172 , V_172 +
sizeof( struct V_184 ) , 1 ) ;
V_170 = V_2 -> V_8 [ 0 ] ;
F_240 ( V_170 ,
F_234 ( V_170 , V_2 -> V_17 [ 0 ] ) ,
F_234 ( V_170 , V_2 -> V_17 [ 0 ] - 1 ) ,
V_172 ) ;
return 0 ;
}
void F_241 ( struct V_18 * V_19 , struct V_1 * V_2 ,
T_4 V_303 , int V_304 )
{
int V_76 ;
struct V_14 * V_170 ;
struct V_184 * V_274 ;
T_4 V_95 ;
unsigned int V_276 ;
unsigned int V_305 ;
unsigned int V_306 ;
unsigned int V_307 ;
int V_6 ;
struct V_264 V_265 ;
F_210 ( & V_265 ) ;
V_170 = V_2 -> V_8 [ 0 ] ;
V_76 = V_2 -> V_17 [ 0 ] ;
V_306 = F_227 ( V_170 , V_76 ) ;
if ( V_306 == V_303 )
return;
V_95 = F_91 ( V_170 ) ;
V_276 = F_155 ( V_19 , V_170 ) ;
V_305 = F_157 ( V_170 , V_76 ) ;
V_307 = V_306 - V_303 ;
F_75 ( V_76 < 0 ) ;
F_75 ( V_76 >= V_95 ) ;
for ( V_6 = V_76 ; V_6 < V_95 ; V_6 ++ ) {
T_4 V_229 ;
V_274 = F_211 ( V_6 ) ;
V_229 = F_212 ( V_170 , V_274 , & V_265 ) ;
F_221 ( V_170 , V_274 ,
V_229 + V_307 , & V_265 ) ;
}
if ( V_304 ) {
F_126 ( V_170 , F_219 ( V_170 ) +
V_276 + V_307 , F_219 ( V_170 ) +
V_276 , V_305 + V_303 - V_276 ) ;
} else {
struct V_36 V_37 ;
T_2 V_156 ;
F_33 ( V_170 , & V_37 , V_76 ) ;
if ( F_242 ( & V_37 ) == V_298 ) {
unsigned long V_308 ;
struct V_295 * V_296 ;
V_296 = F_229 ( V_170 , V_76 ,
struct V_295 ) ;
V_296 = (struct V_295 * ) (
( unsigned long ) V_296 - V_307 ) ;
if ( F_243 ( V_170 , V_296 ) ==
V_309 ) {
V_308 = F_234 ( V_170 , V_76 ) ;
F_126 ( V_170 , V_308 ,
( unsigned long ) V_296 ,
F_162 ( struct V_295 ,
V_310 ) ) ;
}
}
F_126 ( V_170 , F_219 ( V_170 ) +
V_276 + V_307 , F_219 ( V_170 ) +
V_276 , V_305 - V_276 ) ;
V_156 = F_244 ( & V_37 ) ;
F_245 ( & V_37 , V_156 + V_307 ) ;
F_204 ( V_170 , & V_37 , V_76 ) ;
if ( V_76 == 0 )
F_202 ( V_19 , V_2 , & V_37 , 1 ) ;
}
V_274 = F_211 ( V_76 ) ;
F_236 ( V_170 , V_274 , V_303 ) ;
F_49 ( V_170 ) ;
if ( F_197 ( V_19 , V_170 ) < 0 ) {
F_246 ( V_19 , V_170 ) ;
F_173 () ;
}
}
void F_247 ( struct V_18 * V_19 , struct V_1 * V_2 ,
T_4 V_268 )
{
int V_76 ;
struct V_14 * V_170 ;
struct V_184 * V_274 ;
T_4 V_95 ;
unsigned int V_276 ;
unsigned int V_311 ;
unsigned int V_306 ;
int V_6 ;
struct V_264 V_265 ;
F_210 ( & V_265 ) ;
V_170 = V_2 -> V_8 [ 0 ] ;
V_95 = F_91 ( V_170 ) ;
V_276 = F_155 ( V_19 , V_170 ) ;
if ( F_197 ( V_19 , V_170 ) < V_268 ) {
F_246 ( V_19 , V_170 ) ;
F_173 () ;
}
V_76 = V_2 -> V_17 [ 0 ] ;
V_311 = F_218 ( V_170 , V_76 ) ;
F_75 ( V_76 < 0 ) ;
if ( V_76 >= V_95 ) {
F_246 ( V_19 , V_170 ) ;
F_214 ( V_19 -> V_23 , L_5 ,
V_76 , V_95 ) ;
F_75 ( 1 ) ;
}
for ( V_6 = V_76 ; V_6 < V_95 ; V_6 ++ ) {
T_4 V_229 ;
V_274 = F_211 ( V_6 ) ;
V_229 = F_212 ( V_170 , V_274 , & V_265 ) ;
F_221 ( V_170 , V_274 ,
V_229 - V_268 , & V_265 ) ;
}
F_126 ( V_170 , F_219 ( V_170 ) +
V_276 - V_268 , F_219 ( V_170 ) +
V_276 , V_311 - V_276 ) ;
V_276 = V_311 ;
V_306 = F_227 ( V_170 , V_76 ) ;
V_274 = F_211 ( V_76 ) ;
F_236 ( V_170 , V_274 , V_306 + V_268 ) ;
F_49 ( V_170 ) ;
if ( F_197 ( V_19 , V_170 ) < 0 ) {
F_246 ( V_19 , V_170 ) ;
F_173 () ;
}
}
void F_239 ( struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_153 * V_312 , T_4 * V_268 ,
T_4 V_313 , T_4 V_314 , int V_171 )
{
struct V_184 * V_274 ;
int V_6 ;
T_4 V_95 ;
unsigned int V_276 ;
struct V_36 V_37 ;
struct V_14 * V_170 ;
int V_76 ;
struct V_264 V_265 ;
F_210 ( & V_265 ) ;
V_170 = V_2 -> V_8 [ 0 ] ;
V_76 = V_2 -> V_17 [ 0 ] ;
V_95 = F_91 ( V_170 ) ;
V_276 = F_155 ( V_19 , V_170 ) ;
if ( F_197 ( V_19 , V_170 ) < V_314 ) {
F_246 ( V_19 , V_170 ) ;
F_214 ( V_19 -> V_23 , L_6 ,
V_314 , F_197 ( V_19 , V_170 ) ) ;
F_173 () ;
}
if ( V_76 != V_95 ) {
unsigned int V_311 = F_218 ( V_170 , V_76 ) ;
if ( V_311 < V_276 ) {
F_246 ( V_19 , V_170 ) ;
F_214 ( V_19 -> V_23 , L_7 ,
V_76 , V_311 , V_276 ) ;
F_75 ( 1 ) ;
}
for ( V_6 = V_76 ; V_6 < V_95 ; V_6 ++ ) {
T_4 V_229 ;
V_274 = F_211 ( V_6 ) ;
V_229 = F_212 ( V_170 , V_274 , & V_265 ) ;
F_221 ( V_170 , V_274 ,
V_229 - V_313 , & V_265 ) ;
}
F_126 ( V_170 , F_220 ( V_76 + V_171 ) ,
F_220 ( V_76 ) ,
( V_95 - V_76 ) * sizeof( struct V_184 ) ) ;
F_126 ( V_170 , F_219 ( V_170 ) +
V_276 - V_313 , F_219 ( V_170 ) +
V_276 , V_311 - V_276 ) ;
V_276 = V_311 ;
}
for ( V_6 = 0 ; V_6 < V_171 ; V_6 ++ ) {
F_186 ( & V_37 , V_312 + V_6 ) ;
F_204 ( V_170 , & V_37 , V_76 + V_6 ) ;
V_274 = F_211 ( V_76 + V_6 ) ;
F_221 ( V_170 , V_274 ,
V_276 - V_268 [ V_6 ] , & V_265 ) ;
V_276 -= V_268 [ V_6 ] ;
F_248 ( V_170 , V_274 , V_268 [ V_6 ] , & V_265 ) ;
}
F_127 ( V_170 , V_95 + V_171 ) ;
if ( V_76 == 0 ) {
F_186 ( & V_37 , V_312 ) ;
F_202 ( V_19 , V_2 , & V_37 , 1 ) ;
}
F_180 ( V_2 , 1 ) ;
F_49 ( V_170 ) ;
if ( F_197 ( V_19 , V_170 ) < 0 ) {
F_246 ( V_19 , V_170 ) ;
F_173 () ;
}
}
int F_249 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_153 * V_312 , T_4 * V_268 ,
int V_171 )
{
int V_34 = 0 ;
int V_76 ;
int V_6 ;
T_4 V_314 = 0 ;
T_4 V_313 = 0 ;
for ( V_6 = 0 ; V_6 < V_171 ; V_6 ++ )
V_313 += V_268 [ V_6 ] ;
V_314 = V_313 + ( V_171 * sizeof( struct V_184 ) ) ;
V_34 = F_190 ( V_29 , V_19 , V_312 , V_2 , V_314 , 1 ) ;
if ( V_34 == 0 )
return - V_75 ;
if ( V_34 < 0 )
return V_34 ;
V_76 = V_2 -> V_17 [ 0 ] ;
F_75 ( V_76 < 0 ) ;
F_239 ( V_19 , V_2 , V_312 , V_268 ,
V_313 , V_314 , V_171 ) ;
return 0 ;
}
int F_250 ( struct V_28 * V_29 , struct V_18
* V_19 , struct V_153 * V_312 , void * V_315 , T_4
V_268 )
{
int V_34 = 0 ;
struct V_1 * V_2 ;
struct V_14 * V_170 ;
unsigned long V_308 ;
V_2 = F_1 () ;
if ( ! V_2 )
return - V_85 ;
V_34 = F_251 ( V_29 , V_19 , V_2 , V_312 , V_268 ) ;
if ( ! V_34 ) {
V_170 = V_2 -> V_8 [ 0 ] ;
V_308 = F_234 ( V_170 , V_2 -> V_17 [ 0 ] ) ;
F_45 ( V_170 , V_315 , V_308 , V_268 ) ;
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
F_202 ( V_19 , V_2 , & V_37 , V_35 + 1 ) ;
}
F_49 ( V_70 ) ;
}
static T_1 void F_252 ( struct V_28 * V_29 ,
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
int F_253 ( struct V_28 * V_29 , struct V_18 * V_19 ,
struct V_1 * V_2 , int V_76 , int V_171 )
{
struct V_14 * V_170 ;
struct V_184 * V_274 ;
int V_316 ;
int V_317 = 0 ;
int V_34 = 0 ;
int V_191 ;
int V_6 ;
T_4 V_95 ;
struct V_264 V_265 ;
F_210 ( & V_265 ) ;
V_170 = V_2 -> V_8 [ 0 ] ;
V_316 = F_157 ( V_170 , V_76 + V_171 - 1 ) ;
for ( V_6 = 0 ; V_6 < V_171 ; V_6 ++ )
V_317 += F_227 ( V_170 , V_76 + V_6 ) ;
V_95 = F_91 ( V_170 ) ;
if ( V_76 + V_171 != V_95 ) {
int V_276 = F_155 ( V_19 , V_170 ) ;
F_126 ( V_170 , F_219 ( V_170 ) +
V_276 + V_317 ,
F_219 ( V_170 ) + V_276 ,
V_316 - V_276 ) ;
for ( V_6 = V_76 + V_171 ; V_6 < V_95 ; V_6 ++ ) {
T_4 V_229 ;
V_274 = F_211 ( V_6 ) ;
V_229 = F_212 ( V_170 , V_274 , & V_265 ) ;
F_221 ( V_170 , V_274 ,
V_229 + V_317 , & V_265 ) ;
}
F_126 ( V_170 , F_220 ( V_76 ) ,
F_220 ( V_76 + V_171 ) ,
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
F_252 ( V_29 , V_19 , V_2 , V_170 ) ;
}
} else {
int V_318 = F_209 ( V_170 , 0 , V_95 ) ;
if ( V_76 == 0 ) {
struct V_36 V_37 ;
F_33 ( V_170 , & V_37 , 0 ) ;
F_202 ( V_19 , V_2 , & V_37 , 1 ) ;
}
if ( V_318 < F_156 ( V_19 ) / 3 ) {
V_76 = V_2 -> V_17 [ 1 ] ;
F_116 ( V_170 ) ;
F_3 ( V_2 ) ;
V_191 = F_224 ( V_29 , V_19 , V_2 , 1 , 1 ,
1 , ( T_4 ) - 1 ) ;
if ( V_191 < 0 && V_191 != - V_197 )
V_34 = V_191 ;
if ( V_2 -> V_8 [ 0 ] == V_170 &&
F_91 ( V_170 ) ) {
V_191 = F_222 ( V_29 , V_19 , V_2 , 1 ,
1 , 1 , 0 ) ;
if ( V_191 < 0 && V_191 != - V_197 )
V_34 = V_191 ;
}
if ( F_91 ( V_170 ) == 0 ) {
V_2 -> V_17 [ 1 ] = V_76 ;
F_252 ( V_29 , V_19 , V_2 , V_170 ) ;
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
int F_201 ( struct V_18 * V_19 , struct V_1 * V_2 )
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
int F_254 ( struct V_18 * V_19 , struct V_153 * V_319 ,
struct V_1 * V_2 ,
T_2 V_320 )
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
if ( F_47 ( V_71 ) < V_320 ) {
V_34 = 1 ;
goto V_284;
}
while ( 1 ) {
V_95 = F_91 ( V_71 ) ;
V_35 = F_32 ( V_71 ) ;
V_222 = F_161 ( V_71 , V_319 , V_35 , & V_76 ) ;
if ( V_35 == V_2 -> V_233 ) {
if ( V_76 >= V_95 )
goto V_321;
V_34 = 0 ;
V_2 -> V_17 [ V_35 ] = V_76 ;
F_192 ( V_71 , & V_231 , V_76 ) ;
goto V_284;
}
if ( V_222 && V_76 > 0 )
V_76 -- ;
while ( V_76 < V_95 ) {
T_2 V_160 ;
V_160 = F_84 ( V_71 , V_76 ) ;
if ( V_160 < V_320 ) {
V_76 ++ ;
continue;
}
break;
}
V_321:
if ( V_76 >= V_95 ) {
V_2 -> V_17 [ V_35 ] = V_76 ;
F_3 ( V_2 ) ;
V_222 = F_255 ( V_19 , V_2 , V_319 , V_35 ,
V_320 ) ;
if ( V_222 == 0 ) {
F_9 ( V_2 ) ;
goto V_223;
} else {
goto V_284;
}
}
F_256 ( V_71 , & V_231 , V_76 ) ;
V_2 -> V_17 [ V_35 ] = V_76 ;
if ( V_35 == V_2 -> V_233 ) {
V_34 = 0 ;
F_179 ( V_2 , V_35 , 1 , 0 , NULL ) ;
goto V_284;
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
V_284:
if ( V_34 == 0 )
memcpy ( V_319 , & V_231 , sizeof( V_231 ) ) ;
F_3 ( V_2 ) ;
return V_34 ;
}
static void F_257 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int * V_35 , int V_322 )
{
F_75 ( * V_35 == 0 ) ;
V_2 -> V_8 [ * V_35 - 1 ] = F_169 ( V_19 , V_2 -> V_8 [ * V_35 ] ,
V_2 -> V_17 [ * V_35 ] ) ;
V_2 -> V_17 [ * V_35 - 1 ] = 0 ;
( * V_35 ) -- ;
}
static int F_258 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int * V_35 , int V_322 )
{
int V_34 = 0 ;
int V_95 ;
V_95 = F_91 ( V_2 -> V_8 [ * V_35 ] ) ;
V_2 -> V_17 [ * V_35 ] ++ ;
while ( V_2 -> V_17 [ * V_35 ] >= V_95 ) {
if ( * V_35 == V_322 )
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
static int F_259 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int * V_35 , int V_322 ,
int V_323 ,
struct V_153 * V_82 )
{
int V_34 ;
if ( * V_35 == 0 || ! V_323 ) {
V_34 = F_258 ( V_19 , V_2 , V_35 , V_322 ) ;
} else {
F_257 ( V_19 , V_2 , V_35 , V_322 ) ;
V_34 = 0 ;
}
if ( V_34 >= 0 ) {
if ( * V_35 == 0 )
F_192 ( V_2 -> V_8 [ * V_35 ] , V_82 ,
V_2 -> V_17 [ * V_35 ] ) ;
else
F_256 ( V_2 -> V_8 [ * V_35 ] , V_82 ,
V_2 -> V_17 [ * V_35 ] ) ;
}
return V_34 ;
}
static int F_260 ( struct V_18 * V_324 ,
struct V_1 * V_325 ,
struct V_1 * V_326 ,
char * V_327 )
{
int V_328 ;
int V_329 , V_330 ;
unsigned long V_331 , V_332 ;
V_329 = F_227 ( V_325 -> V_8 [ 0 ] , V_325 -> V_17 [ 0 ] ) ;
V_330 = F_227 ( V_326 -> V_8 [ 0 ] , V_326 -> V_17 [ 0 ] ) ;
if ( V_329 != V_330 )
return 1 ;
V_331 = F_234 ( V_325 -> V_8 [ 0 ] , V_325 -> V_17 [ 0 ] ) ;
V_332 = F_234 ( V_326 -> V_8 [ 0 ] ,
V_326 -> V_17 [ 0 ] ) ;
F_160 ( V_325 -> V_8 [ 0 ] , V_327 , V_331 , V_329 ) ;
V_328 = F_187 ( V_326 -> V_8 [ 0 ] , V_327 , V_332 , V_329 ) ;
if ( V_328 )
return 1 ;
return 0 ;
}
int F_261 ( struct V_18 * V_324 ,
struct V_18 * V_333 ,
T_6 V_334 , void * V_335 )
{
int V_34 ;
int V_328 ;
struct V_1 * V_325 = NULL ;
struct V_1 * V_326 = NULL ;
struct V_153 V_336 ;
struct V_153 V_198 ;
char * V_327 = NULL ;
int V_337 ;
int V_338 ;
int V_339 ;
int V_340 ;
int V_341 ;
int V_342 ;
int V_343 ;
int V_344 ;
T_2 V_345 ;
T_2 V_346 ;
T_2 V_347 ;
T_2 V_348 ;
V_325 = F_1 () ;
if ( ! V_325 ) {
V_34 = - V_85 ;
goto V_284;
}
V_326 = F_1 () ;
if ( ! V_326 ) {
V_34 = - V_85 ;
goto V_284;
}
V_327 = F_233 ( V_324 -> V_294 , V_4 ) ;
if ( ! V_327 ) {
V_34 = - V_85 ;
goto V_284;
}
V_325 -> V_234 = 1 ;
V_325 -> V_237 = 1 ;
V_326 -> V_234 = 1 ;
V_326 -> V_237 = 1 ;
F_193 ( & V_324 -> V_23 -> V_236 ) ;
V_339 = F_32 ( V_324 -> V_116 ) ;
V_337 = V_339 ;
V_325 -> V_8 [ V_339 ] = V_324 -> V_116 ;
F_116 ( V_325 -> V_8 [ V_339 ] ) ;
V_340 = F_32 ( V_333 -> V_116 ) ;
V_338 = V_340 ;
V_326 -> V_8 [ V_340 ] = V_333 -> V_116 ;
F_116 ( V_326 -> V_8 [ V_340 ] ) ;
F_194 ( & V_324 -> V_23 -> V_236 ) ;
if ( V_339 == 0 )
F_192 ( V_325 -> V_8 [ V_339 ] ,
& V_336 , V_325 -> V_17 [ V_339 ] ) ;
else
F_256 ( V_325 -> V_8 [ V_339 ] ,
& V_336 , V_325 -> V_17 [ V_339 ] ) ;
if ( V_340 == 0 )
F_192 ( V_326 -> V_8 [ V_340 ] ,
& V_198 , V_326 -> V_17 [ V_340 ] ) ;
else
F_256 ( V_326 -> V_8 [ V_340 ] ,
& V_198 , V_326 -> V_17 [ V_340 ] ) ;
V_341 = V_342 = 0 ;
V_343 = V_344 = 0 ;
while ( 1 ) {
if ( V_343 && ! V_341 ) {
V_34 = F_259 ( V_324 , V_325 , & V_339 ,
V_337 ,
V_343 != V_349 ,
& V_336 ) ;
if ( V_34 < 0 )
V_341 = V_350 ;
V_343 = 0 ;
}
if ( V_344 && ! V_342 ) {
V_34 = F_259 ( V_333 , V_326 , & V_340 ,
V_338 ,
V_344 != V_349 ,
& V_198 ) ;
if ( V_34 < 0 )
V_342 = V_350 ;
V_344 = 0 ;
}
if ( V_341 && V_342 ) {
V_34 = 0 ;
goto V_284;
} else if ( V_341 ) {
if ( V_340 == 0 ) {
V_34 = V_334 ( V_324 , V_333 ,
V_325 , V_326 ,
& V_198 ,
V_351 ,
V_335 ) ;
if ( V_34 < 0 )
goto V_284;
}
V_344 = V_350 ;
continue;
} else if ( V_342 ) {
if ( V_339 == 0 ) {
V_34 = V_334 ( V_324 , V_333 ,
V_325 , V_326 ,
& V_336 ,
V_352 ,
V_335 ) ;
if ( V_34 < 0 )
goto V_284;
}
V_343 = V_350 ;
continue;
}
if ( V_339 == 0 && V_340 == 0 ) {
V_328 = F_149 ( & V_336 , & V_198 ) ;
if ( V_328 < 0 ) {
V_34 = V_334 ( V_324 , V_333 ,
V_325 , V_326 ,
& V_336 ,
V_352 ,
V_335 ) ;
if ( V_34 < 0 )
goto V_284;
V_343 = V_350 ;
} else if ( V_328 > 0 ) {
V_34 = V_334 ( V_324 , V_333 ,
V_325 , V_326 ,
& V_198 ,
V_351 ,
V_335 ) ;
if ( V_34 < 0 )
goto V_284;
V_344 = V_350 ;
} else {
enum V_353 V_328 ;
F_31 ( ! F_137 ( V_325 -> V_8 [ 0 ] ) ) ;
V_34 = F_260 ( V_324 , V_325 ,
V_326 , V_327 ) ;
if ( V_34 )
V_328 = V_354 ;
else
V_328 = V_355 ;
V_34 = V_334 ( V_324 , V_333 ,
V_325 , V_326 ,
& V_336 , V_328 , V_335 ) ;
if ( V_34 < 0 )
goto V_284;
V_343 = V_350 ;
V_344 = V_350 ;
}
} else if ( V_339 == V_340 ) {
V_328 = F_149 ( & V_336 , & V_198 ) ;
if ( V_328 < 0 ) {
V_343 = V_350 ;
} else if ( V_328 > 0 ) {
V_344 = V_350 ;
} else {
V_345 = F_83 (
V_325 -> V_8 [ V_339 ] ,
V_325 -> V_17 [ V_339 ] ) ;
V_346 = F_83 (
V_326 -> V_8 [ V_340 ] ,
V_326 -> V_17 [ V_340 ] ) ;
V_347 = F_84 (
V_325 -> V_8 [ V_339 ] ,
V_325 -> V_17 [ V_339 ] ) ;
V_348 = F_84 (
V_326 -> V_8 [ V_340 ] ,
V_326 -> V_17 [ V_340 ] ) ;
if ( V_345 == V_346 &&
V_347 == V_348 ) {
V_343 = V_349 ;
V_344 = V_349 ;
} else {
V_343 = V_350 ;
V_344 = V_350 ;
}
}
} else if ( V_339 < V_340 ) {
V_344 = V_350 ;
} else {
V_343 = V_350 ;
}
}
V_284:
F_8 ( V_325 ) ;
F_8 ( V_326 ) ;
F_73 ( V_327 ) ;
return V_34 ;
}
int F_255 ( struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_153 * V_82 , int V_35 , T_2 V_320 )
{
int V_76 ;
struct V_14 * V_253 ;
F_31 ( ! V_2 -> V_216 ) ;
while ( V_35 < V_7 ) {
if ( ! V_2 -> V_8 [ V_35 ] )
return 1 ;
V_76 = V_2 -> V_17 [ V_35 ] + 1 ;
V_253 = V_2 -> V_8 [ V_35 ] ;
V_62:
if ( V_76 >= F_91 ( V_253 ) ) {
int V_34 ;
int V_356 ;
struct V_153 V_357 ;
if ( V_35 + 1 >= V_7 ||
! V_2 -> V_8 [ V_35 + 1 ] )
return 1 ;
if ( V_2 -> V_9 [ V_35 + 1 ] ) {
V_35 ++ ;
continue;
}
V_76 = F_91 ( V_253 ) - 1 ;
if ( V_35 == 0 )
F_192 ( V_253 , & V_357 , V_76 ) ;
else
F_256 ( V_253 , & V_357 , V_76 ) ;
V_356 = V_2 -> V_233 ;
F_9 ( V_2 ) ;
V_2 -> V_233 = V_35 ;
V_34 = F_190 ( NULL , V_19 , & V_357 , V_2 ,
0 , 0 ) ;
V_2 -> V_233 = V_356 ;
if ( V_34 < 0 )
return V_34 ;
V_253 = V_2 -> V_8 [ V_35 ] ;
V_76 = V_2 -> V_17 [ V_35 ] ;
if ( V_34 == 0 )
V_76 ++ ;
goto V_62;
}
if ( V_35 == 0 )
F_192 ( V_253 , V_82 , V_76 ) ;
else {
T_2 V_160 = F_84 ( V_253 , V_76 ) ;
if ( V_160 < V_320 ) {
V_76 ++ ;
goto V_62;
}
F_256 ( V_253 , V_82 , V_76 ) ;
}
return 0 ;
}
return 1 ;
}
int F_191 ( struct V_18 * V_19 , struct V_1 * V_2 )
{
return F_262 ( V_19 , V_2 , 0 ) ;
}
int F_262 ( struct V_18 * V_19 , struct V_1 * V_2 ,
T_2 V_131 )
{
int V_76 ;
int V_35 ;
struct V_14 * V_253 ;
struct V_14 * V_62 ;
struct V_153 V_82 ;
T_4 V_95 ;
int V_34 ;
int V_358 = V_2 -> V_241 ;
int V_359 = 0 ;
V_95 = F_91 ( V_2 -> V_8 [ 0 ] ) ;
if ( V_95 == 0 )
return 1 ;
F_192 ( V_2 -> V_8 [ 0 ] , & V_82 , V_95 - 1 ) ;
V_223:
V_35 = 1 ;
V_62 = NULL ;
V_359 = 0 ;
F_9 ( V_2 ) ;
V_2 -> V_216 = 1 ;
V_2 -> V_241 = 1 ;
if ( V_131 )
V_34 = F_199 ( V_19 , & V_82 , V_2 , V_131 ) ;
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
V_253 = V_2 -> V_8 [ V_35 ] ;
if ( V_76 >= F_91 ( V_253 ) ) {
V_35 ++ ;
if ( V_35 == V_7 ) {
V_34 = 1 ;
goto V_224;
}
continue;
}
if ( V_62 ) {
F_11 ( V_62 , V_359 ) ;
F_12 ( V_62 ) ;
}
V_62 = V_253 ;
V_359 = V_2 -> V_9 [ V_35 ] ;
V_34 = F_181 ( NULL , V_19 , V_2 , & V_62 , V_35 ,
V_76 , & V_82 , 0 ) ;
if ( V_34 == - V_219 )
goto V_223;
if ( V_34 < 0 ) {
F_9 ( V_2 ) ;
goto V_224;
}
if ( ! V_2 -> V_237 ) {
V_34 = F_196 ( V_62 ) ;
if ( ! V_34 && V_131 ) {
F_12 ( V_62 ) ;
F_9 ( V_2 ) ;
F_263 () ;
goto V_223;
}
if ( ! V_34 ) {
F_3 ( V_2 ) ;
F_23 ( V_62 ) ;
F_5 ( V_2 , V_62 ,
V_10 ) ;
}
V_359 = V_10 ;
}
break;
}
V_2 -> V_17 [ V_35 ] = V_76 ;
while ( 1 ) {
V_35 -- ;
V_253 = V_2 -> V_8 [ V_35 ] ;
if ( V_2 -> V_9 [ V_35 ] )
F_11 ( V_253 , V_2 -> V_9 [ V_35 ] ) ;
F_12 ( V_253 ) ;
V_2 -> V_8 [ V_35 ] = V_62 ;
V_2 -> V_17 [ V_35 ] = 0 ;
if ( ! V_2 -> V_237 )
V_2 -> V_9 [ V_35 ] = V_359 ;
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
if ( ! V_2 -> V_237 ) {
V_34 = F_196 ( V_62 ) ;
if ( ! V_34 ) {
F_3 ( V_2 ) ;
F_23 ( V_62 ) ;
F_5 ( V_2 , V_62 ,
V_10 ) ;
}
V_359 = V_10 ;
}
}
V_34 = 0 ;
V_224:
F_179 ( V_2 , 0 , 1 , 0 , NULL ) ;
V_2 -> V_241 = V_358 ;
if ( ! V_358 )
F_3 ( V_2 ) ;
return V_34 ;
}
int F_264 ( struct V_18 * V_19 ,
struct V_1 * V_2 , T_2 V_360 ,
int type )
{
struct V_153 V_231 ;
struct V_14 * V_170 ;
T_4 V_95 ;
int V_34 ;
while ( 1 ) {
if ( V_2 -> V_17 [ 0 ] == 0 ) {
F_3 ( V_2 ) ;
V_34 = F_201 ( V_19 , V_2 ) ;
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
if ( V_231 . V_123 < V_360 )
break;
if ( V_231 . type == type )
return 0 ;
if ( V_231 . V_123 == V_360 &&
V_231 . type < type )
break;
}
return 1 ;
}
int F_265 ( struct V_18 * V_19 ,
struct V_1 * V_2 , T_2 V_360 )
{
struct V_153 V_231 ;
struct V_14 * V_170 ;
T_4 V_95 ;
int V_34 ;
while ( 1 ) {
if ( V_2 -> V_17 [ 0 ] == 0 ) {
F_3 ( V_2 ) ;
V_34 = F_201 ( V_19 , V_2 ) ;
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
if ( V_231 . V_123 < V_360 )
break;
if ( V_231 . type == V_361 ||
V_231 . type == V_362 )
return 0 ;
if ( V_231 . V_123 == V_360 &&
V_231 . type < V_361 )
break;
}
return 1 ;
}
