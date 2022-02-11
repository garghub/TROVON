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
struct V_14 * F_22 ( struct V_18 * V_19 )
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
F_45 ( V_33 , V_19 -> V_23 -> V_48 ,
( unsigned long ) F_46 ( V_33 ) ,
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
T_2 F_58 ( struct V_50 * V_23 ,
struct V_52 * V_53 )
{
T_2 V_54 ;
F_54 ( V_23 ) ;
F_26 ( & V_23 -> V_55 ) ;
if ( ! V_53 -> V_54 ) {
V_53 -> V_54 = F_59 ( V_23 ) ;
F_60 ( & V_53 -> V_56 , & V_23 -> V_57 ) ;
}
V_54 = F_59 ( V_23 ) ;
F_29 ( & V_23 -> V_55 ) ;
F_56 ( V_23 ) ;
return V_54 ;
}
void F_61 ( struct V_50 * V_23 ,
struct V_52 * V_53 )
{
struct V_58 * V_59 ;
struct V_60 * V_21 ;
struct V_60 * V_61 ;
struct V_52 * V_62 ;
struct V_63 * V_64 ;
T_2 V_65 = ( T_2 ) - 1 ;
T_2 V_66 = V_53 -> V_54 ;
if ( ! V_66 )
return;
F_26 ( & V_23 -> V_55 ) ;
F_62 ( & V_53 -> V_56 ) ;
V_53 -> V_54 = 0 ;
F_63 (cur_elem, &fs_info->tree_mod_seq_list, list) {
if ( V_62 -> V_54 < V_65 ) {
if ( V_66 > V_62 -> V_54 ) {
F_29 ( & V_23 -> V_55 ) ;
return;
}
V_65 = V_62 -> V_54 ;
}
}
F_29 ( & V_23 -> V_55 ) ;
F_54 ( V_23 ) ;
V_59 = & V_23 -> V_67 ;
for ( V_21 = F_64 ( V_59 ) ; V_21 ; V_21 = V_61 ) {
V_61 = F_65 ( V_21 ) ;
V_64 = F_66 ( V_21 , struct V_63 , V_21 ) ;
if ( V_64 -> V_54 > V_65 )
continue;
F_67 ( V_21 , V_59 ) ;
F_68 ( V_64 ) ;
}
F_56 ( V_23 ) ;
}
static T_1 int
F_69 ( struct V_50 * V_23 , struct V_63 * V_64 )
{
struct V_58 * V_59 ;
struct V_60 * * V_68 ;
struct V_60 * V_69 = NULL ;
struct V_63 * V_70 ;
F_70 ( ! V_64 || ! V_64 -> V_54 ) ;
V_59 = & V_23 -> V_67 ;
V_68 = & V_59 -> V_60 ;
while ( * V_68 ) {
V_70 = F_66 ( * V_68 , struct V_63 , V_21 ) ;
V_69 = * V_68 ;
if ( V_70 -> V_71 < V_64 -> V_71 )
V_68 = & ( ( * V_68 ) -> V_72 ) ;
else if ( V_70 -> V_71 > V_64 -> V_71 )
V_68 = & ( ( * V_68 ) -> V_73 ) ;
else if ( V_70 -> V_54 < V_64 -> V_54 )
V_68 = & ( ( * V_68 ) -> V_72 ) ;
else if ( V_70 -> V_54 > V_64 -> V_54 )
V_68 = & ( ( * V_68 ) -> V_73 ) ;
else {
F_68 ( V_64 ) ;
return - V_74 ;
}
}
F_71 ( & V_64 -> V_21 , V_69 , V_68 ) ;
F_72 ( & V_64 -> V_21 , V_59 ) ;
return 0 ;
}
static inline int F_73 ( struct V_50 * V_23 ,
struct V_14 * V_20 ) {
F_74 () ;
if ( F_27 ( & ( V_23 ) -> V_57 ) )
return 1 ;
if ( V_20 && F_32 ( V_20 ) == 0 )
return 1 ;
F_54 ( V_23 ) ;
if ( F_27 ( & V_23 -> V_57 ) ) {
F_56 ( V_23 ) ;
return 1 ;
}
return 0 ;
}
static inline int F_75 ( struct V_50 * V_23 , T_3 V_75 ,
struct V_63 * * V_76 )
{
struct V_63 * V_64 ;
V_64 = * V_76 = F_76 ( sizeof( * V_64 ) , V_77 ) ;
if ( ! V_64 )
return - V_78 ;
V_64 -> V_54 = F_59 ( V_23 ) ;
return V_64 -> V_54 ;
}
static inline int
F_77 ( struct V_50 * V_23 ,
struct V_14 * V_20 , int V_79 ,
enum V_80 V_81 , T_3 V_75 )
{
int V_34 ;
struct V_63 * V_64 ;
V_34 = F_75 ( V_23 , V_75 , & V_64 ) ;
if ( V_34 < 0 )
return V_34 ;
V_64 -> V_71 = V_20 -> V_43 >> V_82 ;
if ( V_81 != V_83 ) {
F_34 ( V_20 , & V_64 -> V_84 , V_79 ) ;
V_64 -> V_85 = F_78 ( V_20 , V_79 ) ;
}
V_64 -> V_81 = V_81 ;
V_64 -> V_79 = V_79 ;
V_64 -> V_86 = F_79 ( V_20 , V_79 ) ;
return F_69 ( V_23 , V_64 ) ;
}
static T_1 int
F_80 ( struct V_50 * V_23 ,
struct V_14 * V_20 , int V_79 ,
enum V_80 V_81 , T_3 V_75 )
{
int V_34 ;
if ( F_73 ( V_23 , V_20 ) )
return 0 ;
V_34 = F_77 ( V_23 , V_20 , V_79 , V_81 , V_75 ) ;
F_56 ( V_23 ) ;
return V_34 ;
}
static T_1 int
F_81 ( struct V_50 * V_23 , struct V_14 * V_20 ,
int V_79 , enum V_80 V_81 )
{
return F_80 ( V_23 , V_20 , V_79 , V_81 , V_4 ) ;
}
static T_1 int
F_82 ( struct V_50 * V_23 ,
struct V_14 * V_20 , int V_79 ,
enum V_80 V_81 )
{
return F_77 ( V_23 , V_20 , V_79 , V_81 , V_4 ) ;
}
static T_1 int
F_83 ( struct V_50 * V_23 ,
struct V_14 * V_20 , int V_87 , int V_88 ,
int V_89 , T_3 V_75 )
{
struct V_63 * V_64 ;
int V_34 ;
int V_6 ;
if ( F_73 ( V_23 , V_20 ) )
return 0 ;
for ( V_6 = 0 ; V_6 + V_87 < V_88 && V_6 < V_89 ; V_6 ++ ) {
V_34 = F_82 ( V_23 , V_20 , V_6 + V_87 ,
V_90 ) ;
F_70 ( V_34 < 0 ) ;
}
V_34 = F_75 ( V_23 , V_75 , & V_64 ) ;
if ( V_34 < 0 )
goto V_91;
V_64 -> V_71 = V_20 -> V_43 >> V_82 ;
V_64 -> V_79 = V_88 ;
V_64 -> V_92 . V_87 = V_87 ;
V_64 -> V_92 . V_89 = V_89 ;
V_64 -> V_81 = V_93 ;
V_34 = F_69 ( V_23 , V_64 ) ;
V_91:
F_56 ( V_23 ) ;
return V_34 ;
}
static inline void
F_84 ( struct V_50 * V_23 , struct V_14 * V_20 )
{
int V_6 ;
T_4 V_94 ;
int V_34 ;
if ( F_32 ( V_20 ) == 0 )
return;
V_94 = F_85 ( V_20 ) ;
for ( V_6 = V_94 - 1 ; V_6 >= 0 ; V_6 -- ) {
V_34 = F_82 ( V_23 , V_20 , V_6 ,
V_95 ) ;
F_70 ( V_34 < 0 ) ;
}
}
static T_1 int
F_86 ( struct V_50 * V_23 ,
struct V_14 * V_96 ,
struct V_14 * V_97 , T_3 V_75 )
{
struct V_63 * V_64 ;
int V_34 ;
if ( F_73 ( V_23 , NULL ) )
return 0 ;
F_84 ( V_23 , V_96 ) ;
V_34 = F_75 ( V_23 , V_75 , & V_64 ) ;
if ( V_34 < 0 )
goto V_91;
V_64 -> V_71 = V_97 -> V_43 >> V_82 ;
V_64 -> V_96 . V_98 = V_96 -> V_43 ;
V_64 -> V_96 . V_35 = F_32 ( V_96 ) ;
V_64 -> V_86 = F_47 ( V_96 ) ;
V_64 -> V_81 = V_99 ;
V_34 = F_69 ( V_23 , V_64 ) ;
V_91:
F_56 ( V_23 ) ;
return V_34 ;
}
static struct V_63 *
F_87 ( struct V_50 * V_23 , T_2 V_43 , T_2 V_65 ,
int V_100 )
{
struct V_58 * V_59 ;
struct V_60 * V_21 ;
struct V_63 * V_70 = NULL ;
struct V_63 * V_101 = NULL ;
T_2 V_71 = V_43 >> V_82 ;
F_50 ( V_23 ) ;
V_59 = & V_23 -> V_67 ;
V_21 = V_59 -> V_60 ;
while ( V_21 ) {
V_70 = F_66 ( V_21 , struct V_63 , V_21 ) ;
if ( V_70 -> V_71 < V_71 ) {
V_21 = V_21 -> V_72 ;
} else if ( V_70 -> V_71 > V_71 ) {
V_21 = V_21 -> V_73 ;
} else if ( V_70 -> V_54 < V_65 ) {
V_21 = V_21 -> V_72 ;
} else if ( ! V_100 ) {
if ( V_101 )
F_70 ( V_101 -> V_54 > V_70 -> V_54 ) ;
V_101 = V_70 ;
V_21 = V_21 -> V_72 ;
} else if ( V_70 -> V_54 > V_65 ) {
if ( V_101 )
F_70 ( V_101 -> V_54 < V_70 -> V_54 ) ;
V_101 = V_70 ;
V_21 = V_21 -> V_73 ;
} else {
V_101 = V_70 ;
break;
}
}
F_52 ( V_23 ) ;
return V_101 ;
}
static struct V_63 *
F_88 ( struct V_50 * V_23 , T_2 V_43 ,
T_2 V_65 )
{
return F_87 ( V_23 , V_43 , V_65 , 1 ) ;
}
static struct V_63 *
F_89 ( struct V_50 * V_23 , T_2 V_43 , T_2 V_65 )
{
return F_87 ( V_23 , V_43 , V_65 , 0 ) ;
}
static T_1 void
F_90 ( struct V_50 * V_23 , struct V_14 * V_102 ,
struct V_14 * V_103 , unsigned long V_104 ,
unsigned long V_105 , int V_89 )
{
int V_34 ;
int V_6 ;
if ( F_73 ( V_23 , NULL ) )
return;
if ( F_32 ( V_102 ) == 0 && F_32 ( V_103 ) == 0 ) {
F_56 ( V_23 ) ;
return;
}
for ( V_6 = 0 ; V_6 < V_89 ; V_6 ++ ) {
V_34 = F_82 ( V_23 , V_103 ,
V_6 + V_105 ,
V_106 ) ;
F_70 ( V_34 < 0 ) ;
V_34 = F_82 ( V_23 , V_102 ,
V_6 + V_104 ,
V_83 ) ;
F_70 ( V_34 < 0 ) ;
}
F_56 ( V_23 ) ;
}
static inline void
F_91 ( struct V_50 * V_23 , struct V_14 * V_102 ,
int V_104 , int V_105 , int V_89 )
{
int V_34 ;
V_34 = F_83 ( V_23 , V_102 , V_104 , V_105 ,
V_89 , V_4 ) ;
F_70 ( V_34 < 0 ) ;
}
static T_1 void
F_92 ( struct V_50 * V_23 ,
struct V_14 * V_20 ,
struct V_36 * V_37 , int V_79 , int V_107 )
{
int V_34 ;
V_34 = F_80 ( V_23 , V_20 , V_79 ,
V_108 ,
V_107 ? V_77 : V_4 ) ;
F_70 ( V_34 < 0 ) ;
}
static T_1 void
F_93 ( struct V_50 * V_23 , struct V_14 * V_20 )
{
if ( F_73 ( V_23 , V_20 ) )
return;
F_84 ( V_23 , V_20 ) ;
F_56 ( V_23 ) ;
}
static T_1 void
F_94 ( struct V_18 * V_19 ,
struct V_14 * V_109 )
{
int V_34 ;
V_34 = F_86 ( V_19 -> V_23 , V_19 -> V_21 ,
V_109 , V_4 ) ;
F_70 ( V_34 < 0 ) ;
}
int F_95 ( struct V_18 * V_19 ,
struct V_14 * V_30 )
{
if ( V_19 -> V_38 &&
V_30 != V_19 -> V_21 && V_30 != V_19 -> V_110 &&
( F_47 ( V_30 ) <=
F_96 ( & V_19 -> V_111 ) ||
F_97 ( V_30 , V_46 ) ) )
return 1 ;
#ifdef F_98
if ( V_19 -> V_38 &&
F_99 ( V_30 ) < V_44 )
return 1 ;
#endif
return 0 ;
}
static T_1 int F_100 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_14 * V_30 ,
struct V_14 * V_33 ,
int * V_112 )
{
T_2 V_22 ;
T_2 V_113 ;
T_2 V_75 ;
T_2 V_114 = 0 ;
int V_34 ;
if ( F_95 ( V_19 , V_30 ) ) {
V_34 = F_101 ( V_29 , V_19 , V_30 -> V_43 ,
V_30 -> V_42 , & V_22 , & V_75 ) ;
if ( V_34 )
return V_34 ;
if ( V_22 == 0 ) {
V_34 = - V_115 ;
F_102 ( V_19 -> V_23 , V_34 ) ;
return V_34 ;
}
} else {
V_22 = 1 ;
if ( V_19 -> V_116 . V_117 == V_47 ||
F_99 ( V_30 ) < V_44 )
V_75 = V_118 ;
else
V_75 = 0 ;
}
V_113 = F_103 ( V_30 ) ;
F_70 ( V_113 == V_47 &&
! ( V_75 & V_118 ) ) ;
if ( V_22 > 1 ) {
if ( ( V_113 == V_19 -> V_116 . V_117 ||
V_19 -> V_116 . V_117 == V_47 ) &&
! ( V_75 & V_118 ) ) {
V_34 = F_48 ( V_29 , V_19 , V_30 , 1 , 1 ) ;
F_70 ( V_34 ) ;
if ( V_19 -> V_116 . V_117 ==
V_47 ) {
V_34 = F_104 ( V_29 , V_19 , V_30 , 0 , 1 ) ;
F_70 ( V_34 ) ;
V_34 = F_48 ( V_29 , V_19 , V_33 , 1 , 1 ) ;
F_70 ( V_34 ) ;
}
V_114 |= V_118 ;
} else {
if ( V_19 -> V_116 . V_117 ==
V_47 )
V_34 = F_48 ( V_29 , V_19 , V_33 , 1 , 1 ) ;
else
V_34 = F_48 ( V_29 , V_19 , V_33 , 0 , 1 ) ;
F_70 ( V_34 ) ;
}
if ( V_114 != 0 ) {
V_34 = F_105 ( V_29 , V_19 ,
V_30 -> V_43 ,
V_30 -> V_42 ,
V_114 , 0 ) ;
if ( V_34 )
return V_34 ;
}
} else {
if ( V_75 & V_118 ) {
if ( V_19 -> V_116 . V_117 ==
V_47 )
V_34 = F_48 ( V_29 , V_19 , V_33 , 1 , 1 ) ;
else
V_34 = F_48 ( V_29 , V_19 , V_33 , 0 , 1 ) ;
F_70 ( V_34 ) ;
V_34 = F_104 ( V_29 , V_19 , V_30 , 1 , 1 ) ;
F_70 ( V_34 ) ;
}
if ( V_30 != V_19 -> V_21 && F_32 ( V_30 ) != 0 )
F_93 ( V_19 -> V_23 , V_30 ) ;
F_106 ( V_29 , V_19 , V_30 ) ;
* V_112 = 1 ;
}
return 0 ;
}
static T_1 int F_107 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_14 * V_30 ,
struct V_14 * V_69 , int V_119 ,
struct V_14 * * V_31 ,
T_2 V_120 , T_2 V_121 )
{
struct V_36 V_37 ;
struct V_14 * V_33 ;
int V_35 , V_34 ;
int V_112 = 0 ;
int V_122 = 0 ;
T_2 V_123 ;
if ( * V_31 == V_30 )
V_122 = 1 ;
F_108 ( V_30 ) ;
F_31 ( V_19 -> V_38 && V_29 -> V_39 !=
V_19 -> V_23 -> V_40 -> V_39 ) ;
F_31 ( V_19 -> V_38 && V_29 -> V_39 != V_19 -> V_41 ) ;
V_35 = F_32 ( V_30 ) ;
if ( V_35 == 0 )
F_33 ( V_30 , & V_37 , 0 ) ;
else
F_34 ( V_30 , & V_37 , 0 ) ;
if ( V_19 -> V_116 . V_117 == V_47 ) {
if ( V_69 )
V_123 = V_69 -> V_43 ;
else
V_123 = 0 ;
} else
V_123 = 0 ;
V_33 = F_35 ( V_29 , V_19 , V_30 -> V_42 , V_123 ,
V_19 -> V_116 . V_117 , & V_37 ,
V_35 , V_120 , V_121 ) ;
if ( F_36 ( V_33 ) )
return F_37 ( V_33 ) ;
F_38 ( V_33 , V_30 , 0 , 0 , V_33 -> V_42 ) ;
F_39 ( V_33 , V_33 -> V_43 ) ;
F_40 ( V_33 , V_29 -> V_39 ) ;
F_41 ( V_33 , V_44 ) ;
F_42 ( V_33 , V_45 |
V_46 ) ;
if ( V_19 -> V_116 . V_117 == V_47 )
F_43 ( V_33 , V_46 ) ;
else
F_44 ( V_33 , V_19 -> V_116 . V_117 ) ;
F_45 ( V_33 , V_19 -> V_23 -> V_48 ,
( unsigned long ) F_46 ( V_33 ) ,
V_49 ) ;
V_34 = F_100 ( V_29 , V_19 , V_30 , V_33 , & V_112 ) ;
if ( V_34 ) {
F_109 ( V_29 , V_19 , V_34 ) ;
return V_34 ;
}
if ( V_19 -> V_38 )
F_110 ( V_29 , V_19 , V_30 , V_33 ) ;
if ( V_30 == V_19 -> V_21 ) {
F_31 ( V_69 && V_69 != V_30 ) ;
if ( V_19 -> V_116 . V_117 == V_47 ||
F_99 ( V_30 ) < V_44 )
V_123 = V_30 -> V_43 ;
else
V_123 = 0 ;
F_111 ( V_33 ) ;
F_94 ( V_19 , V_33 ) ;
F_112 ( V_19 -> V_21 , V_33 ) ;
F_113 ( V_29 , V_19 , V_30 , V_123 ,
V_112 ) ;
F_12 ( V_30 ) ;
F_25 ( V_19 ) ;
} else {
if ( V_19 -> V_116 . V_117 == V_47 )
V_123 = V_69 -> V_43 ;
else
V_123 = 0 ;
F_31 ( V_29 -> V_39 != F_47 ( V_69 ) ) ;
F_81 ( V_19 -> V_23 , V_69 , V_119 ,
V_108 ) ;
F_114 ( V_69 , V_119 ,
V_33 -> V_43 ) ;
F_115 ( V_69 , V_119 ,
V_29 -> V_39 ) ;
F_49 ( V_69 ) ;
F_113 ( V_29 , V_19 , V_30 , V_123 ,
V_112 ) ;
}
if ( V_122 )
F_21 ( V_30 ) ;
F_116 ( V_30 ) ;
F_49 ( V_33 ) ;
* V_31 = V_33 ;
return 0 ;
}
static struct V_63 *
F_117 ( struct V_50 * V_23 ,
struct V_18 * V_19 , T_2 V_124 )
{
struct V_63 * V_64 ;
struct V_63 * V_101 = NULL ;
T_2 V_125 = V_19 -> V_21 -> V_43 ;
int V_126 = 0 ;
if ( ! V_124 )
return 0 ;
while ( 1 ) {
V_64 = F_88 ( V_23 , V_125 ,
V_124 ) ;
if ( ! V_126 && ! V_64 )
return 0 ;
if ( ! V_64 )
break;
if ( V_64 -> V_81 != V_99 )
break;
V_101 = V_64 ;
V_125 = V_64 -> V_96 . V_98 ;
F_70 ( V_125 == V_19 -> V_21 -> V_43 ) ;
V_126 = 1 ;
}
if ( ! V_101 )
V_101 = V_64 ;
return V_101 ;
}
static void
F_118 ( struct V_14 * V_20 , T_2 V_124 ,
struct V_63 * V_127 )
{
T_4 V_128 ;
struct V_60 * V_61 ;
struct V_63 * V_64 = V_127 ;
unsigned long V_129 ;
unsigned long V_130 ;
unsigned long V_131 = sizeof( struct V_132 ) ;
V_128 = F_85 ( V_20 ) ;
while ( V_64 && V_64 -> V_54 >= V_124 ) {
switch ( V_64 -> V_81 ) {
case V_95 :
F_70 ( V_64 -> V_79 < V_128 ) ;
case V_90 :
case V_106 :
F_119 ( V_20 , & V_64 -> V_84 , V_64 -> V_79 ) ;
F_114 ( V_20 , V_64 -> V_79 , V_64 -> V_85 ) ;
F_115 ( V_20 , V_64 -> V_79 ,
V_64 -> V_86 ) ;
V_128 ++ ;
break;
case V_108 :
F_70 ( V_64 -> V_79 >= V_128 ) ;
F_119 ( V_20 , & V_64 -> V_84 , V_64 -> V_79 ) ;
F_114 ( V_20 , V_64 -> V_79 , V_64 -> V_85 ) ;
F_115 ( V_20 , V_64 -> V_79 ,
V_64 -> V_86 ) ;
break;
case V_83 :
V_128 -- ;
break;
case V_93 :
V_129 = F_120 ( V_64 -> V_79 ) ;
V_130 = F_120 ( V_64 -> V_92 . V_87 ) ;
F_121 ( V_20 , V_129 , V_130 ,
V_64 -> V_92 . V_89 * V_131 ) ;
break;
case V_99 :
break;
}
V_61 = F_65 ( & V_64 -> V_21 ) ;
if ( ! V_61 )
break;
V_64 = F_66 ( V_61 , struct V_63 , V_21 ) ;
if ( V_64 -> V_71 != V_127 -> V_71 )
break;
}
F_122 ( V_20 , V_128 ) ;
}
static struct V_14 *
F_123 ( struct V_50 * V_23 , struct V_14 * V_20 ,
T_2 V_124 )
{
struct V_14 * V_133 ;
struct V_63 * V_64 ;
if ( ! V_124 )
return V_20 ;
if ( F_32 ( V_20 ) == 0 )
return V_20 ;
V_64 = F_89 ( V_23 , V_20 -> V_43 , V_124 ) ;
if ( ! V_64 )
return V_20 ;
if ( V_64 -> V_81 == V_95 ) {
F_70 ( V_64 -> V_79 != 0 ) ;
V_133 = F_124 ( V_20 -> V_43 ,
V_23 -> V_134 -> V_135 ) ;
F_70 ( ! V_133 ) ;
F_39 ( V_133 , V_20 -> V_43 ) ;
F_41 ( V_133 ,
F_99 ( V_20 ) ) ;
F_44 ( V_133 , F_103 ( V_20 ) ) ;
F_125 ( V_133 , F_32 ( V_20 ) ) ;
} else {
V_133 = F_126 ( V_20 ) ;
F_70 ( ! V_133 ) ;
}
F_111 ( V_133 ) ;
F_12 ( V_20 ) ;
F_118 ( V_133 , V_124 , V_64 ) ;
return V_133 ;
}
static inline struct V_14 *
F_127 ( struct V_18 * V_19 , T_2 V_124 )
{
struct V_63 * V_64 ;
struct V_14 * V_20 ;
struct V_136 * V_96 = NULL ;
T_2 V_137 = 0 ;
T_2 V_98 ;
V_20 = F_22 ( V_19 ) ;
V_64 = F_117 ( V_19 -> V_23 , V_19 , V_124 ) ;
if ( ! V_64 )
return V_19 -> V_21 ;
if ( V_64 -> V_81 == V_99 ) {
V_96 = & V_64 -> V_96 ;
V_137 = V_64 -> V_86 ;
V_98 = V_96 -> V_98 ;
} else {
V_98 = V_19 -> V_21 -> V_43 ;
}
V_64 = F_89 ( V_19 -> V_23 , V_98 , V_124 ) ;
if ( V_96 )
V_20 = F_124 ( V_98 , V_19 -> V_135 ) ;
else
V_20 = F_126 ( V_19 -> V_21 ) ;
F_24 ( V_19 -> V_21 ) ;
F_12 ( V_19 -> V_21 ) ;
if ( ! V_20 )
return NULL ;
F_23 ( V_20 ) ;
if ( V_96 ) {
F_39 ( V_20 , V_20 -> V_43 ) ;
F_41 ( V_20 , V_44 ) ;
F_44 ( V_20 , V_19 -> V_116 . V_117 ) ;
F_125 ( V_20 , V_96 -> V_35 ) ;
F_40 ( V_20 , V_137 ) ;
}
if ( V_64 )
F_118 ( V_20 , V_124 , V_64 ) ;
else
F_31 ( F_32 ( V_20 ) != 0 ) ;
F_111 ( V_20 ) ;
return V_20 ;
}
static inline int F_128 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_14 * V_30 )
{
F_129 () ;
if ( F_47 ( V_30 ) == V_29 -> V_39 &&
! F_97 ( V_30 , V_45 ) &&
! ( V_19 -> V_116 . V_117 != V_47 &&
F_97 ( V_30 , V_46 ) ) &&
! V_19 -> V_138 )
return 0 ;
return 1 ;
}
T_1 int F_130 ( struct V_28 * V_29 ,
struct V_18 * V_19 , struct V_14 * V_30 ,
struct V_14 * V_69 , int V_119 ,
struct V_14 * * V_31 )
{
T_2 V_120 ;
int V_34 ;
if ( V_29 -> V_139 != V_19 -> V_23 -> V_40 ) {
F_131 ( V_140 L_1 ,
( unsigned long long ) V_29 -> V_39 ,
( unsigned long long )
V_19 -> V_23 -> V_40 -> V_39 ) ;
F_31 ( 1 ) ;
}
if ( V_29 -> V_39 != V_19 -> V_23 -> V_86 ) {
F_131 ( V_140 L_1 ,
( unsigned long long ) V_29 -> V_39 ,
( unsigned long long ) V_19 -> V_23 -> V_86 ) ;
F_31 ( 1 ) ;
}
if ( ! F_128 ( V_29 , V_19 , V_30 ) ) {
* V_31 = V_30 ;
return 0 ;
}
V_120 = V_30 -> V_43 & ~ ( ( T_2 ) ( 1024 * 1024 * 1024 ) - 1 ) ;
if ( V_69 )
F_132 ( V_69 ) ;
F_132 ( V_30 ) ;
V_34 = F_107 ( V_29 , V_19 , V_30 , V_69 ,
V_119 , V_31 , V_120 , 0 ) ;
F_133 ( V_19 , V_30 , * V_31 ) ;
return V_34 ;
}
static int F_134 ( T_2 V_141 , T_2 V_142 , T_4 V_143 )
{
if ( V_141 < V_142 && V_142 - ( V_141 + V_143 ) < 32768 )
return 1 ;
if ( V_141 > V_142 && V_141 - ( V_142 + V_143 ) < 32768 )
return 1 ;
return 0 ;
}
static int F_135 ( struct V_36 * V_144 , struct V_145 * V_146 )
{
struct V_145 V_147 ;
F_136 ( & V_147 , V_144 ) ;
return F_137 ( & V_147 , V_146 ) ;
}
int F_137 ( struct V_145 * V_147 , struct V_145 * V_146 )
{
if ( V_147 -> V_117 > V_146 -> V_117 )
return 1 ;
if ( V_147 -> V_117 < V_146 -> V_117 )
return - 1 ;
if ( V_147 -> type > V_146 -> type )
return 1 ;
if ( V_147 -> type < V_146 -> type )
return - 1 ;
if ( V_147 -> V_148 > V_146 -> V_148 )
return 1 ;
if ( V_147 -> V_148 < V_146 -> V_148 )
return - 1 ;
return 0 ;
}
int F_138 ( struct V_28 * V_29 ,
struct V_18 * V_19 , struct V_14 * V_69 ,
int V_149 , int V_150 , T_2 * V_151 ,
struct V_145 * V_152 )
{
struct V_14 * V_70 ;
T_2 V_141 ;
T_2 V_153 ;
T_2 V_120 = * V_151 ;
T_2 V_154 = 0 ;
T_2 V_142 ;
T_4 V_155 ;
int V_156 ;
int V_6 ;
int V_157 = 0 ;
int V_158 ;
int V_159 ;
T_4 V_143 ;
int V_160 = 0 ;
struct V_36 V_37 ;
V_158 = F_32 ( V_69 ) ;
if ( V_150 && V_158 != 1 )
return 0 ;
if ( V_29 -> V_139 != V_19 -> V_23 -> V_40 )
F_31 ( 1 ) ;
if ( V_29 -> V_39 != V_19 -> V_23 -> V_86 )
F_31 ( 1 ) ;
V_155 = F_85 ( V_69 ) ;
V_143 = F_139 ( V_19 , V_158 - 1 ) ;
V_156 = V_155 ;
if ( V_155 == 1 )
return 0 ;
F_132 ( V_69 ) ;
for ( V_6 = V_149 ; V_6 < V_156 ; V_6 ++ ) {
int V_161 = 1 ;
F_34 ( V_69 , & V_37 , V_6 ) ;
if ( ! V_160 && F_135 ( & V_37 , V_152 ) < 0 )
continue;
V_160 = 1 ;
V_141 = F_78 ( V_69 , V_6 ) ;
V_153 = F_79 ( V_69 , V_6 ) ;
if ( V_154 == 0 )
V_154 = V_141 ;
if ( V_6 > 0 ) {
V_142 = F_78 ( V_69 , V_6 - 1 ) ;
V_161 = F_134 ( V_141 , V_142 , V_143 ) ;
}
if ( ! V_161 && V_6 < V_156 - 2 ) {
V_142 = F_78 ( V_69 , V_6 + 1 ) ;
V_161 = F_134 ( V_141 , V_142 , V_143 ) ;
}
if ( V_161 ) {
V_154 = V_141 ;
continue;
}
V_70 = F_140 ( V_19 , V_141 , V_143 ) ;
if ( V_70 )
V_159 = F_141 ( V_70 , V_153 , 0 ) ;
else
V_159 = 0 ;
if ( ! V_70 || ! V_159 ) {
if ( V_150 ) {
F_12 ( V_70 ) ;
continue;
}
if ( ! V_70 ) {
V_70 = F_142 ( V_19 , V_141 ,
V_143 , V_153 ) ;
if ( ! V_70 )
return - V_162 ;
} else if ( ! V_159 ) {
V_157 = F_143 ( V_70 , V_153 ) ;
if ( V_157 ) {
F_12 ( V_70 ) ;
return V_157 ;
}
}
}
if ( V_120 == 0 )
V_120 = V_154 ;
F_20 ( V_70 ) ;
F_132 ( V_70 ) ;
V_157 = F_107 ( V_29 , V_19 , V_70 , V_69 , V_6 ,
& V_70 , V_120 ,
F_144 ( 16 * V_143 ,
( V_156 - V_6 ) * V_143 ) ) ;
if ( V_157 ) {
F_21 ( V_70 ) ;
F_12 ( V_70 ) ;
break;
}
V_120 = V_70 -> V_43 ;
V_154 = V_70 -> V_43 ;
* V_151 = V_120 ;
F_21 ( V_70 ) ;
F_12 ( V_70 ) ;
}
return V_157 ;
}
static inline unsigned int F_145 ( struct V_18 * V_19 ,
struct V_14 * V_163 )
{
T_4 V_164 = F_85 ( V_163 ) ;
if ( V_164 == 0 )
return F_146 ( V_19 ) ;
return F_147 ( V_163 , V_164 - 1 ) ;
}
static T_1 int F_148 ( struct V_14 * V_20 ,
unsigned long V_5 ,
int V_165 , struct V_145 * V_84 ,
int V_166 , int * V_79 )
{
int V_167 = 0 ;
int V_168 = V_166 ;
int V_169 ;
int V_34 ;
struct V_36 * V_170 = NULL ;
struct V_36 V_171 ;
unsigned long V_148 ;
char * V_172 = NULL ;
unsigned long V_173 = 0 ;
unsigned long V_174 = 0 ;
int V_157 ;
while ( V_167 < V_168 ) {
V_169 = ( V_167 + V_168 ) / 2 ;
V_148 = V_5 + V_169 * V_165 ;
if ( ! V_172 || V_148 < V_173 ||
( V_148 + sizeof( struct V_36 ) ) >
V_173 + V_174 ) {
V_157 = F_149 ( V_20 , V_148 ,
sizeof( struct V_36 ) ,
& V_172 , & V_173 , & V_174 ) ;
if ( ! V_157 ) {
V_170 = (struct V_36 * ) ( V_172 + V_148 -
V_173 ) ;
} else {
F_150 ( V_20 , & V_171 ,
V_148 , sizeof( V_171 ) ) ;
V_170 = & V_171 ;
}
} else {
V_170 = (struct V_36 * ) ( V_172 + V_148 -
V_173 ) ;
}
V_34 = F_135 ( V_170 , V_84 ) ;
if ( V_34 < 0 )
V_167 = V_169 + 1 ;
else if ( V_34 > 0 )
V_168 = V_169 ;
else {
* V_79 = V_169 ;
return 0 ;
}
}
* V_79 = V_167 ;
return 1 ;
}
static int F_151 ( struct V_14 * V_20 , struct V_145 * V_84 ,
int V_35 , int * V_79 )
{
if ( V_35 == 0 )
return F_148 ( V_20 ,
F_152 ( struct V_175 , V_176 ) ,
sizeof( struct V_177 ) ,
V_84 , F_85 ( V_20 ) ,
V_79 ) ;
else
return F_148 ( V_20 ,
F_152 ( struct V_178 , V_179 ) ,
sizeof( struct V_132 ) ,
V_84 , F_85 ( V_20 ) ,
V_79 ) ;
}
int F_153 ( struct V_14 * V_20 , struct V_145 * V_84 ,
int V_35 , int * V_79 )
{
return F_151 ( V_20 , V_84 , V_35 , V_79 ) ;
}
static void F_154 ( struct V_18 * V_19 , T_4 V_180 )
{
F_26 ( & V_19 -> V_181 ) ;
F_155 ( & V_19 -> V_111 ,
F_156 ( & V_19 -> V_111 ) + V_180 ) ;
F_29 ( & V_19 -> V_181 ) ;
}
static void F_157 ( struct V_18 * V_19 , T_4 V_180 )
{
F_26 ( & V_19 -> V_181 ) ;
F_155 ( & V_19 -> V_111 ,
F_156 ( & V_19 -> V_111 ) - V_180 ) ;
F_29 ( & V_19 -> V_181 ) ;
}
T_1 int F_158 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_35 )
{
struct V_14 * V_182 = NULL ;
struct V_14 * V_169 ;
struct V_14 * V_183 = NULL ;
struct V_14 * V_69 = NULL ;
int V_34 = 0 ;
int V_184 ;
int V_185 ;
int V_186 = V_2 -> V_17 [ V_35 ] ;
T_2 V_187 ;
if ( V_35 == 0 )
return 0 ;
V_169 = V_2 -> V_8 [ V_35 ] ;
F_31 ( V_2 -> V_9 [ V_35 ] != V_12 &&
V_2 -> V_9 [ V_35 ] != V_13 ) ;
F_31 ( F_47 ( V_169 ) != V_29 -> V_39 ) ;
V_187 = F_78 ( V_169 , V_186 ) ;
if ( V_35 < V_7 - 1 ) {
V_69 = V_2 -> V_8 [ V_35 + 1 ] ;
V_185 = V_2 -> V_17 [ V_35 + 1 ] ;
}
if ( ! V_69 ) {
struct V_14 * V_188 ;
if ( F_85 ( V_169 ) != 1 )
return 0 ;
V_188 = F_159 ( V_19 , V_169 , 0 ) ;
if ( ! V_188 ) {
V_34 = - V_115 ;
F_102 ( V_19 -> V_23 , V_34 ) ;
goto V_189;
}
F_20 ( V_188 ) ;
F_132 ( V_188 ) ;
V_34 = F_130 ( V_29 , V_19 , V_188 , V_169 , 0 , & V_188 ) ;
if ( V_34 ) {
F_21 ( V_188 ) ;
F_12 ( V_188 ) ;
goto V_189;
}
F_94 ( V_19 , V_188 ) ;
F_112 ( V_19 -> V_21 , V_188 ) ;
F_25 ( V_19 ) ;
F_21 ( V_188 ) ;
V_2 -> V_9 [ V_35 ] = 0 ;
V_2 -> V_8 [ V_35 ] = NULL ;
F_106 ( V_29 , V_19 , V_169 ) ;
F_21 ( V_169 ) ;
F_12 ( V_169 ) ;
F_157 ( V_19 , V_169 -> V_42 ) ;
F_113 ( V_29 , V_19 , V_169 , 0 , 1 ) ;
F_116 ( V_169 ) ;
return 0 ;
}
if ( F_85 ( V_169 ) >
F_160 ( V_19 ) / 4 )
return 0 ;
V_183 = F_159 ( V_19 , V_69 , V_185 - 1 ) ;
if ( V_183 ) {
F_20 ( V_183 ) ;
F_132 ( V_183 ) ;
V_184 = F_130 ( V_29 , V_19 , V_183 ,
V_69 , V_185 - 1 , & V_183 ) ;
if ( V_184 ) {
V_34 = V_184 ;
goto V_189;
}
}
V_182 = F_159 ( V_19 , V_69 , V_185 + 1 ) ;
if ( V_182 ) {
F_20 ( V_182 ) ;
F_132 ( V_182 ) ;
V_184 = F_130 ( V_29 , V_19 , V_182 ,
V_69 , V_185 + 1 , & V_182 ) ;
if ( V_184 ) {
V_34 = V_184 ;
goto V_189;
}
}
if ( V_183 ) {
V_186 += F_85 ( V_183 ) ;
V_184 = F_161 ( V_29 , V_19 , V_183 , V_169 , 1 ) ;
if ( V_184 < 0 )
V_34 = V_184 ;
}
if ( V_182 ) {
V_184 = F_161 ( V_29 , V_19 , V_169 , V_182 , 1 ) ;
if ( V_184 < 0 && V_184 != - V_190 )
V_34 = V_184 ;
if ( F_85 ( V_182 ) == 0 ) {
F_106 ( V_29 , V_19 , V_182 ) ;
F_21 ( V_182 ) ;
F_162 ( V_29 , V_19 , V_2 , V_35 + 1 , V_185 + 1 , 1 ) ;
F_157 ( V_19 , V_182 -> V_42 ) ;
F_113 ( V_29 , V_19 , V_182 , 0 , 1 ) ;
F_116 ( V_182 ) ;
V_182 = NULL ;
} else {
struct V_36 V_191 ;
F_34 ( V_182 , & V_191 , 0 ) ;
F_92 ( V_19 -> V_23 , V_69 ,
& V_191 , V_185 + 1 , 0 ) ;
F_119 ( V_69 , & V_191 , V_185 + 1 ) ;
F_49 ( V_69 ) ;
}
}
if ( F_85 ( V_169 ) == 1 ) {
if ( ! V_183 ) {
V_34 = - V_115 ;
F_102 ( V_19 -> V_23 , V_34 ) ;
goto V_189;
}
V_184 = F_163 ( V_29 , V_19 , V_169 , V_183 ) ;
if ( V_184 < 0 ) {
V_34 = V_184 ;
goto V_189;
}
if ( V_184 == 1 ) {
V_184 = F_161 ( V_29 , V_19 , V_183 , V_169 , 1 ) ;
if ( V_184 < 0 )
V_34 = V_184 ;
}
F_70 ( V_184 == 1 ) ;
}
if ( F_85 ( V_169 ) == 0 ) {
F_106 ( V_29 , V_19 , V_169 ) ;
F_21 ( V_169 ) ;
F_162 ( V_29 , V_19 , V_2 , V_35 + 1 , V_185 , 1 ) ;
F_157 ( V_19 , V_169 -> V_42 ) ;
F_113 ( V_29 , V_19 , V_169 , 0 , 1 ) ;
F_116 ( V_169 ) ;
V_169 = NULL ;
} else {
struct V_36 V_192 ;
F_34 ( V_169 , & V_192 , 0 ) ;
F_92 ( V_19 -> V_23 , V_69 , & V_192 ,
V_185 , 0 ) ;
F_119 ( V_69 , & V_192 , V_185 ) ;
F_49 ( V_69 ) ;
}
if ( V_183 ) {
if ( F_85 ( V_183 ) > V_186 ) {
F_111 ( V_183 ) ;
V_2 -> V_8 [ V_35 ] = V_183 ;
V_2 -> V_17 [ V_35 + 1 ] -= 1 ;
V_2 -> V_17 [ V_35 ] = V_186 ;
if ( V_169 ) {
F_21 ( V_169 ) ;
F_12 ( V_169 ) ;
}
} else {
V_186 -= F_85 ( V_183 ) ;
V_2 -> V_17 [ V_35 ] = V_186 ;
}
}
if ( V_187 !=
F_78 ( V_2 -> V_8 [ V_35 ] , V_2 -> V_17 [ V_35 ] ) )
F_164 () ;
V_189:
if ( V_182 ) {
F_21 ( V_182 ) ;
F_12 ( V_182 ) ;
}
if ( V_183 ) {
if ( V_2 -> V_8 [ V_35 ] != V_183 )
F_21 ( V_183 ) ;
F_12 ( V_183 ) ;
}
return V_34 ;
}
static T_1 int F_165 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_35 )
{
struct V_14 * V_182 = NULL ;
struct V_14 * V_169 ;
struct V_14 * V_183 = NULL ;
struct V_14 * V_69 = NULL ;
int V_34 = 0 ;
int V_184 ;
int V_185 ;
int V_186 = V_2 -> V_17 [ V_35 ] ;
if ( V_35 == 0 )
return 1 ;
V_169 = V_2 -> V_8 [ V_35 ] ;
F_31 ( F_47 ( V_169 ) != V_29 -> V_39 ) ;
if ( V_35 < V_7 - 1 ) {
V_69 = V_2 -> V_8 [ V_35 + 1 ] ;
V_185 = V_2 -> V_17 [ V_35 + 1 ] ;
}
if ( ! V_69 )
return 1 ;
V_183 = F_159 ( V_19 , V_69 , V_185 - 1 ) ;
if ( V_183 ) {
T_4 V_193 ;
F_20 ( V_183 ) ;
F_132 ( V_183 ) ;
V_193 = F_85 ( V_183 ) ;
if ( V_193 >= F_160 ( V_19 ) - 1 ) {
V_184 = 1 ;
} else {
V_34 = F_130 ( V_29 , V_19 , V_183 , V_69 ,
V_185 - 1 , & V_183 ) ;
if ( V_34 )
V_184 = 1 ;
else {
V_184 = F_161 ( V_29 , V_19 ,
V_183 , V_169 , 0 ) ;
}
}
if ( V_184 < 0 )
V_34 = V_184 ;
if ( V_184 == 0 ) {
struct V_36 V_37 ;
V_186 += V_193 ;
F_34 ( V_169 , & V_37 , 0 ) ;
F_92 ( V_19 -> V_23 , V_69 ,
& V_37 , V_185 , 0 ) ;
F_119 ( V_69 , & V_37 , V_185 ) ;
F_49 ( V_69 ) ;
if ( F_85 ( V_183 ) > V_186 ) {
V_2 -> V_8 [ V_35 ] = V_183 ;
V_2 -> V_17 [ V_35 + 1 ] -= 1 ;
V_2 -> V_17 [ V_35 ] = V_186 ;
F_21 ( V_169 ) ;
F_12 ( V_169 ) ;
} else {
V_186 -=
F_85 ( V_183 ) ;
V_2 -> V_17 [ V_35 ] = V_186 ;
F_21 ( V_183 ) ;
F_12 ( V_183 ) ;
}
return 0 ;
}
F_21 ( V_183 ) ;
F_12 ( V_183 ) ;
}
V_182 = F_159 ( V_19 , V_69 , V_185 + 1 ) ;
if ( V_182 ) {
T_4 V_194 ;
F_20 ( V_182 ) ;
F_132 ( V_182 ) ;
V_194 = F_85 ( V_182 ) ;
if ( V_194 >= F_160 ( V_19 ) - 1 ) {
V_184 = 1 ;
} else {
V_34 = F_130 ( V_29 , V_19 , V_182 ,
V_69 , V_185 + 1 ,
& V_182 ) ;
if ( V_34 )
V_184 = 1 ;
else {
V_184 = F_163 ( V_29 , V_19 ,
V_182 , V_169 ) ;
}
}
if ( V_184 < 0 )
V_34 = V_184 ;
if ( V_184 == 0 ) {
struct V_36 V_37 ;
F_34 ( V_182 , & V_37 , 0 ) ;
F_92 ( V_19 -> V_23 , V_69 ,
& V_37 , V_185 + 1 , 0 ) ;
F_119 ( V_69 , & V_37 , V_185 + 1 ) ;
F_49 ( V_69 ) ;
if ( F_85 ( V_169 ) <= V_186 ) {
V_2 -> V_8 [ V_35 ] = V_182 ;
V_2 -> V_17 [ V_35 + 1 ] += 1 ;
V_2 -> V_17 [ V_35 ] = V_186 -
F_85 ( V_169 ) ;
F_21 ( V_169 ) ;
F_12 ( V_169 ) ;
} else {
F_21 ( V_182 ) ;
F_12 ( V_182 ) ;
}
return 0 ;
}
F_21 ( V_182 ) ;
F_12 ( V_182 ) ;
}
return 1 ;
}
static void F_166 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int V_35 , int V_79 , T_2 V_117 )
{
struct V_14 * V_21 ;
struct V_36 V_37 ;
T_4 V_94 ;
T_2 V_195 ;
T_2 V_196 ;
T_2 V_197 = 0 ;
T_2 V_153 ;
int V_198 = V_2 -> V_199 ;
struct V_14 * V_20 ;
T_4 V_164 ;
T_4 V_143 ;
T_4 V_200 = 0 ;
if ( V_35 != 1 )
return;
if ( ! V_2 -> V_8 [ V_35 ] )
return;
V_21 = V_2 -> V_8 [ V_35 ] ;
V_195 = F_78 ( V_21 , V_79 ) ;
V_143 = F_139 ( V_19 , V_35 - 1 ) ;
V_20 = F_140 ( V_19 , V_195 , V_143 ) ;
if ( V_20 ) {
F_12 ( V_20 ) ;
return;
}
V_196 = V_195 ;
V_94 = F_85 ( V_21 ) ;
V_164 = V_79 ;
while ( 1 ) {
if ( V_198 < 0 ) {
if ( V_164 == 0 )
break;
V_164 -- ;
} else if ( V_198 > 0 ) {
V_164 ++ ;
if ( V_164 >= V_94 )
break;
}
if ( V_2 -> V_199 < 0 && V_117 ) {
F_34 ( V_21 , & V_37 , V_164 ) ;
if ( F_167 ( & V_37 ) != V_117 )
break;
}
V_195 = F_78 ( V_21 , V_164 ) ;
if ( ( V_195 <= V_196 && V_196 - V_195 <= 65536 ) ||
( V_195 > V_196 && V_195 - V_196 <= 65536 ) ) {
V_153 = F_79 ( V_21 , V_164 ) ;
F_168 ( V_19 , V_195 , V_143 , V_153 ) ;
V_197 += V_143 ;
}
V_200 ++ ;
if ( ( V_197 > 65536 || V_200 > 32 ) )
break;
}
}
static T_1 int F_169 ( struct V_18 * V_19 ,
struct V_1 * V_2 , int V_35 )
{
int V_79 ;
int V_94 ;
struct V_14 * V_69 ;
struct V_14 * V_20 ;
T_2 V_153 ;
T_2 V_201 = 0 ;
T_2 V_202 = 0 ;
int V_34 = 0 ;
int V_143 ;
V_69 = V_2 -> V_8 [ V_35 + 1 ] ;
if ( ! V_69 )
return 0 ;
V_94 = F_85 ( V_69 ) ;
V_79 = V_2 -> V_17 [ V_35 + 1 ] ;
V_143 = F_139 ( V_19 , V_35 ) ;
if ( V_79 > 0 ) {
V_201 = F_78 ( V_69 , V_79 - 1 ) ;
V_153 = F_79 ( V_69 , V_79 - 1 ) ;
V_20 = F_140 ( V_19 , V_201 , V_143 ) ;
if ( V_20 && F_141 ( V_20 , V_153 , 1 ) != 0 )
V_201 = 0 ;
F_12 ( V_20 ) ;
}
if ( V_79 + 1 < V_94 ) {
V_202 = F_78 ( V_69 , V_79 + 1 ) ;
V_153 = F_79 ( V_69 , V_79 + 1 ) ;
V_20 = F_140 ( V_19 , V_202 , V_143 ) ;
if ( V_20 && F_141 ( V_20 , V_153 , 1 ) != 0 )
V_202 = 0 ;
F_12 ( V_20 ) ;
}
if ( V_201 || V_202 ) {
V_34 = - V_203 ;
F_9 ( V_2 ) ;
if ( V_201 )
F_168 ( V_19 , V_201 , V_143 , 0 ) ;
if ( V_202 )
F_168 ( V_19 , V_202 , V_143 , 0 ) ;
if ( V_201 ) {
V_20 = F_142 ( V_19 , V_201 , V_143 , 0 ) ;
F_12 ( V_20 ) ;
}
if ( V_202 ) {
V_20 = F_142 ( V_19 , V_202 , V_143 , 0 ) ;
F_12 ( V_20 ) ;
}
}
return V_34 ;
}
static T_1 void F_170 ( struct V_1 * V_2 , int V_35 ,
int V_204 , int V_205 ,
int * V_206 )
{
int V_6 ;
int V_207 = V_35 ;
int V_208 = 0 ;
struct V_14 * V_209 ;
for ( V_6 = V_35 ; V_6 < V_7 ; V_6 ++ ) {
if ( ! V_2 -> V_8 [ V_6 ] )
break;
if ( ! V_2 -> V_9 [ V_6 ] )
break;
if ( ! V_208 && V_2 -> V_17 [ V_6 ] == 0 ) {
V_207 = V_6 + 1 ;
continue;
}
if ( ! V_208 && V_2 -> V_210 ) {
T_4 V_94 ;
V_209 = V_2 -> V_8 [ V_6 ] ;
V_94 = F_85 ( V_209 ) ;
if ( V_94 < 1 || V_2 -> V_17 [ V_6 ] >= V_94 - 1 ) {
V_207 = V_6 + 1 ;
continue;
}
}
if ( V_207 < V_6 && V_6 >= V_204 )
V_208 = 1 ;
V_209 = V_2 -> V_8 [ V_6 ] ;
if ( V_6 >= V_204 && V_6 > V_207 && V_2 -> V_9 [ V_6 ] ) {
F_11 ( V_209 , V_2 -> V_9 [ V_6 ] ) ;
V_2 -> V_9 [ V_6 ] = 0 ;
if ( V_206 &&
V_6 > V_205 &&
V_6 <= * V_206 ) {
* V_206 = V_6 - 1 ;
}
}
}
}
T_1 void F_171 ( struct V_1 * V_2 , int V_35 )
{
int V_6 ;
if ( V_2 -> V_210 )
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
F_172 ( struct V_28 * V_29 ,
struct V_18 * V_19 , struct V_1 * V_5 ,
struct V_14 * * V_211 , int V_35 , int V_79 ,
struct V_145 * V_84 , T_2 V_124 )
{
T_2 V_141 ;
T_2 V_153 ;
T_4 V_143 ;
struct V_14 * V_212 = * V_211 ;
struct V_14 * V_170 ;
int V_34 ;
V_141 = F_78 ( V_212 , V_79 ) ;
V_153 = F_79 ( V_212 , V_79 ) ;
V_143 = F_139 ( V_19 , V_35 - 1 ) ;
V_170 = F_140 ( V_19 , V_141 , V_143 ) ;
if ( V_170 ) {
if ( F_141 ( V_170 , 0 , 1 ) > 0 ) {
if ( F_141 ( V_170 , V_153 , 1 ) > 0 ) {
* V_211 = V_170 ;
return 0 ;
}
F_12 ( V_170 ) ;
F_3 ( V_5 ) ;
V_170 = F_142 ( V_19 , V_141 , V_143 , V_153 ) ;
if ( V_170 && F_141 ( V_170 , V_153 , 0 ) > 0 ) {
* V_211 = V_170 ;
return 0 ;
}
F_12 ( V_170 ) ;
F_9 ( V_5 ) ;
return - V_162 ;
}
}
F_171 ( V_5 , V_35 + 1 ) ;
F_3 ( V_5 ) ;
F_12 ( V_170 ) ;
if ( V_5 -> V_199 )
F_166 ( V_19 , V_5 , V_35 , V_79 , V_84 -> V_117 ) ;
F_9 ( V_5 ) ;
V_34 = - V_203 ;
V_170 = F_142 ( V_19 , V_141 , V_143 , 0 ) ;
if ( V_170 ) {
if ( ! F_141 ( V_170 , 0 , 0 ) )
V_34 = - V_162 ;
F_12 ( V_170 ) ;
}
return V_34 ;
}
static int
F_173 ( struct V_28 * V_29 ,
struct V_18 * V_19 , struct V_1 * V_5 ,
struct V_14 * V_212 , int V_35 , int V_213 ,
int * V_206 )
{
int V_34 ;
if ( ( V_5 -> V_214 || V_213 > 0 ) && F_85 ( V_212 ) >=
F_160 ( V_19 ) - 3 ) {
int V_215 ;
if ( * V_206 < V_35 + 1 ) {
* V_206 = V_35 + 1 ;
F_9 ( V_5 ) ;
goto V_216;
}
V_215 = F_169 ( V_19 , V_5 , V_35 ) ;
if ( V_215 )
goto V_216;
F_3 ( V_5 ) ;
V_215 = F_174 ( V_29 , V_19 , V_5 , V_35 ) ;
F_5 ( V_5 , NULL , 0 ) ;
F_70 ( V_215 > 0 ) ;
if ( V_215 ) {
V_34 = V_215 ;
goto V_217;
}
V_212 = V_5 -> V_8 [ V_35 ] ;
} else if ( V_213 < 0 && F_85 ( V_212 ) <
F_160 ( V_19 ) / 2 ) {
int V_215 ;
if ( * V_206 < V_35 + 1 ) {
* V_206 = V_35 + 1 ;
F_9 ( V_5 ) ;
goto V_216;
}
V_215 = F_169 ( V_19 , V_5 , V_35 ) ;
if ( V_215 )
goto V_216;
F_3 ( V_5 ) ;
V_215 = F_158 ( V_29 , V_19 , V_5 , V_35 ) ;
F_5 ( V_5 , NULL , 0 ) ;
if ( V_215 ) {
V_34 = V_215 ;
goto V_217;
}
V_212 = V_5 -> V_8 [ V_35 ] ;
if ( ! V_212 ) {
F_9 ( V_5 ) ;
goto V_216;
}
F_70 ( F_85 ( V_212 ) == 1 ) ;
}
return 0 ;
V_216:
V_34 = - V_203 ;
V_217:
return V_34 ;
}
int F_175 ( struct V_28 * V_29 , struct V_18
* V_19 , struct V_145 * V_84 , struct V_1 * V_5 , int
V_213 , int V_33 )
{
struct V_14 * V_212 ;
int V_79 ;
int V_34 ;
int V_157 ;
int V_35 ;
int V_204 = 1 ;
int V_218 ;
int V_206 = 0 ;
T_5 V_219 = 0 ;
int V_205 ;
V_219 = V_5 -> V_219 ;
F_31 ( V_219 && V_213 > 0 ) ;
F_31 ( V_5 -> V_8 [ 0 ] != NULL ) ;
if ( V_213 < 0 ) {
V_204 = 2 ;
V_206 = 2 ;
} else if ( V_213 > 0 ) {
V_206 = 1 ;
}
if ( ! V_33 )
V_206 = - 1 ;
if ( V_33 && ( V_5 -> V_210 || V_5 -> V_219 ) )
V_206 = V_7 ;
V_205 = V_206 ;
V_216:
V_218 = V_10 ;
V_35 = 0 ;
if ( V_5 -> V_220 ) {
V_212 = V_19 -> V_110 ;
F_111 ( V_212 ) ;
V_35 = F_32 ( V_212 ) ;
if ( ! V_5 -> V_221 )
F_23 ( V_212 ) ;
} else {
if ( V_5 -> V_221 ) {
V_212 = F_13 ( V_19 ) ;
V_35 = F_32 ( V_212 ) ;
} else {
V_212 = F_22 ( V_19 ) ;
V_35 = F_32 ( V_212 ) ;
if ( V_35 <= V_206 ) {
F_24 ( V_212 ) ;
F_12 ( V_212 ) ;
V_212 = F_19 ( V_19 ) ;
V_218 = V_12 ;
V_35 = F_32 ( V_212 ) ;
}
}
}
V_5 -> V_8 [ V_35 ] = V_212 ;
if ( ! V_5 -> V_221 )
V_5 -> V_9 [ V_35 ] = V_218 ;
while ( V_212 ) {
V_35 = F_32 ( V_212 ) ;
if ( V_33 ) {
if ( ! F_128 ( V_29 , V_19 , V_212 ) )
goto V_222;
F_3 ( V_5 ) ;
if ( V_35 + 1 > V_206 ) {
V_206 = V_35 + 1 ;
F_9 ( V_5 ) ;
goto V_216;
}
V_157 = F_130 ( V_29 , V_19 , V_212 ,
V_5 -> V_8 [ V_35 + 1 ] ,
V_5 -> V_17 [ V_35 + 1 ] , & V_212 ) ;
if ( V_157 ) {
V_34 = V_157 ;
goto V_217;
}
}
V_222:
F_70 ( ! V_33 && V_213 ) ;
V_5 -> V_8 [ V_35 ] = V_212 ;
F_5 ( V_5 , NULL , 0 ) ;
if ( ! V_33 )
F_171 ( V_5 , V_35 + 1 ) ;
V_34 = F_151 ( V_212 , V_84 , V_35 , & V_79 ) ;
if ( V_35 != 0 ) {
int V_223 = 0 ;
if ( V_34 && V_79 > 0 ) {
V_223 = 1 ;
V_79 -= 1 ;
}
V_5 -> V_17 [ V_35 ] = V_79 ;
V_157 = F_173 ( V_29 , V_19 , V_5 , V_212 , V_35 ,
V_213 , & V_206 ) ;
if ( V_157 == - V_203 )
goto V_216;
if ( V_157 ) {
V_34 = V_157 ;
goto V_217;
}
V_212 = V_5 -> V_8 [ V_35 ] ;
V_79 = V_5 -> V_17 [ V_35 ] ;
if ( V_79 == 0 && V_33 &&
V_206 < V_35 + 1 ) {
V_206 = V_35 + 1 ;
F_9 ( V_5 ) ;
goto V_216;
}
F_170 ( V_5 , V_35 , V_204 ,
V_205 , & V_206 ) ;
if ( V_35 == V_219 ) {
if ( V_223 )
V_5 -> V_17 [ V_35 ] ++ ;
goto V_217;
}
V_157 = F_172 ( V_29 , V_19 , V_5 ,
& V_212 , V_35 , V_79 , V_84 , 0 ) ;
if ( V_157 == - V_203 )
goto V_216;
if ( V_157 ) {
V_34 = V_157 ;
goto V_217;
}
if ( ! V_5 -> V_221 ) {
V_35 = F_32 ( V_212 ) ;
if ( V_35 <= V_206 ) {
V_157 = F_176 ( V_212 ) ;
if ( ! V_157 ) {
F_3 ( V_5 ) ;
F_20 ( V_212 ) ;
F_5 ( V_5 , V_212 ,
V_12 ) ;
}
V_5 -> V_9 [ V_35 ] = V_12 ;
} else {
V_157 = F_177 ( V_212 ) ;
if ( ! V_157 ) {
F_3 ( V_5 ) ;
F_23 ( V_212 ) ;
F_5 ( V_5 , V_212 ,
V_10 ) ;
}
V_5 -> V_9 [ V_35 ] = V_10 ;
}
V_5 -> V_8 [ V_35 ] = V_212 ;
}
} else {
V_5 -> V_17 [ V_35 ] = V_79 ;
if ( V_213 > 0 &&
F_178 ( V_19 , V_212 ) < V_213 ) {
if ( V_206 < 1 ) {
V_206 = 1 ;
F_9 ( V_5 ) ;
goto V_216;
}
F_3 ( V_5 ) ;
V_157 = F_179 ( V_29 , V_19 , V_84 ,
V_5 , V_213 , V_34 == 0 ) ;
F_5 ( V_5 , NULL , 0 ) ;
F_70 ( V_157 > 0 ) ;
if ( V_157 ) {
V_34 = V_157 ;
goto V_217;
}
}
if ( ! V_5 -> V_214 )
F_170 ( V_5 , V_35 , V_204 ,
V_205 , & V_206 ) ;
goto V_217;
}
}
V_34 = 1 ;
V_217:
if ( ! V_5 -> V_224 )
F_3 ( V_5 ) ;
if ( V_34 < 0 )
F_9 ( V_5 ) ;
return V_34 ;
}
int F_180 ( struct V_18 * V_19 , struct V_145 * V_84 ,
struct V_1 * V_5 , T_2 V_124 )
{
struct V_14 * V_212 ;
int V_79 ;
int V_34 ;
int V_157 ;
int V_35 ;
int V_204 = 1 ;
T_5 V_219 = 0 ;
V_219 = V_5 -> V_219 ;
F_31 ( V_5 -> V_8 [ 0 ] != NULL ) ;
if ( V_5 -> V_220 ) {
F_70 ( V_124 ) ;
return F_175 ( NULL , V_19 , V_84 , V_5 , 0 , 0 ) ;
}
V_216:
V_212 = F_127 ( V_19 , V_124 ) ;
V_35 = F_32 ( V_212 ) ;
V_5 -> V_9 [ V_35 ] = V_10 ;
while ( V_212 ) {
V_35 = F_32 ( V_212 ) ;
V_5 -> V_8 [ V_35 ] = V_212 ;
F_5 ( V_5 , NULL , 0 ) ;
F_171 ( V_5 , V_35 + 1 ) ;
V_34 = F_151 ( V_212 , V_84 , V_35 , & V_79 ) ;
if ( V_35 != 0 ) {
int V_223 = 0 ;
if ( V_34 && V_79 > 0 ) {
V_223 = 1 ;
V_79 -= 1 ;
}
V_5 -> V_17 [ V_35 ] = V_79 ;
F_170 ( V_5 , V_35 , V_204 , 0 , NULL ) ;
if ( V_35 == V_219 ) {
if ( V_223 )
V_5 -> V_17 [ V_35 ] ++ ;
goto V_217;
}
V_157 = F_172 ( NULL , V_19 , V_5 , & V_212 , V_35 ,
V_79 , V_84 , V_124 ) ;
if ( V_157 == - V_203 )
goto V_216;
if ( V_157 ) {
V_34 = V_157 ;
goto V_217;
}
V_35 = F_32 ( V_212 ) ;
V_157 = F_177 ( V_212 ) ;
if ( ! V_157 ) {
F_3 ( V_5 ) ;
F_23 ( V_212 ) ;
F_5 ( V_5 , V_212 ,
V_10 ) ;
}
V_5 -> V_9 [ V_35 ] = V_10 ;
V_5 -> V_8 [ V_35 ] = V_212 ;
V_212 = F_123 ( V_19 -> V_23 , V_212 , V_124 ) ;
if ( V_212 != V_5 -> V_8 [ V_35 ] ) {
F_11 ( V_5 -> V_8 [ V_35 ] ,
V_5 -> V_9 [ V_35 ] ) ;
V_5 -> V_9 [ V_35 ] = 0 ;
V_5 -> V_8 [ V_35 ] = V_212 ;
}
} else {
V_5 -> V_17 [ V_35 ] = V_79 ;
F_170 ( V_5 , V_35 , V_204 , 0 , NULL ) ;
goto V_217;
}
}
V_34 = 1 ;
V_217:
if ( ! V_5 -> V_224 )
F_3 ( V_5 ) ;
if ( V_34 < 0 )
F_9 ( V_5 ) ;
return V_34 ;
}
int F_181 ( struct V_18 * V_19 ,
struct V_145 * V_84 , struct V_1 * V_5 ,
int V_225 , int V_226 )
{
int V_34 ;
struct V_14 * V_163 ;
V_216:
V_34 = F_175 ( NULL , V_19 , V_84 , V_5 , 0 , 0 ) ;
if ( V_34 <= 0 )
return V_34 ;
V_163 = V_5 -> V_8 [ 0 ] ;
if ( V_225 ) {
if ( V_5 -> V_17 [ 0 ] >= F_85 ( V_163 ) ) {
V_34 = F_182 ( V_19 , V_5 ) ;
if ( V_34 <= 0 )
return V_34 ;
if ( ! V_226 )
return 1 ;
V_226 = 0 ;
V_225 = 0 ;
F_9 ( V_5 ) ;
goto V_216;
}
} else {
if ( V_5 -> V_17 [ 0 ] == 0 ) {
V_34 = F_183 ( V_19 , V_5 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( ! V_34 ) {
V_5 -> V_17 [ 0 ] = F_85 ( V_163 ) - 1 ;
return 0 ;
}
if ( ! V_226 )
return 1 ;
V_226 = 0 ;
V_225 = 1 ;
F_9 ( V_5 ) ;
goto V_216;
} else {
-- V_5 -> V_17 [ 0 ] ;
}
}
return 0 ;
}
static void F_184 ( struct V_28 * V_29 ,
struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_36 * V_84 , int V_35 )
{
int V_6 ;
struct V_14 * V_209 ;
for ( V_6 = V_35 ; V_6 < V_7 ; V_6 ++ ) {
int V_227 = V_2 -> V_17 [ V_6 ] ;
if ( ! V_2 -> V_8 [ V_6 ] )
break;
V_209 = V_2 -> V_8 [ V_6 ] ;
F_92 ( V_19 -> V_23 , V_209 , V_84 , V_227 , 1 ) ;
F_119 ( V_209 , V_84 , V_227 ) ;
F_49 ( V_2 -> V_8 [ V_6 ] ) ;
if ( V_227 != 0 )
break;
}
}
void F_185 ( struct V_28 * V_29 ,
struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_145 * V_228 )
{
struct V_36 V_37 ;
struct V_14 * V_20 ;
int V_79 ;
V_20 = V_2 -> V_8 [ 0 ] ;
V_79 = V_2 -> V_17 [ 0 ] ;
if ( V_79 > 0 ) {
F_33 ( V_20 , & V_37 , V_79 - 1 ) ;
F_70 ( F_135 ( & V_37 , V_228 ) >= 0 ) ;
}
if ( V_79 < F_85 ( V_20 ) - 1 ) {
F_33 ( V_20 , & V_37 , V_79 + 1 ) ;
F_70 ( F_135 ( & V_37 , V_228 ) <= 0 ) ;
}
F_186 ( & V_37 , V_228 ) ;
F_187 ( V_20 , & V_37 , V_79 ) ;
F_49 ( V_20 ) ;
if ( V_79 == 0 )
F_184 ( V_29 , V_19 , V_2 , & V_37 , 1 ) ;
}
static int F_161 ( struct V_28 * V_29 ,
struct V_18 * V_19 , struct V_14 * V_102 ,
struct V_14 * V_103 , int V_229 )
{
int V_230 = 0 ;
int V_231 ;
int V_232 ;
int V_34 = 0 ;
V_231 = F_85 ( V_103 ) ;
V_232 = F_85 ( V_102 ) ;
V_230 = F_160 ( V_19 ) - V_232 ;
F_31 ( F_47 ( V_103 ) != V_29 -> V_39 ) ;
F_31 ( F_47 ( V_102 ) != V_29 -> V_39 ) ;
if ( ! V_229 && V_231 <= 8 )
return 1 ;
if ( V_230 <= 0 )
return 1 ;
if ( V_229 ) {
V_230 = F_144 ( V_231 , V_230 ) ;
if ( V_230 < V_231 ) {
if ( V_231 - V_230 < 8 ) {
if ( V_230 <= 8 )
return 1 ;
V_230 -= 8 ;
}
}
} else
V_230 = F_144 ( V_231 - 8 , V_230 ) ;
F_90 ( V_19 -> V_23 , V_102 , V_103 , V_232 , 0 ,
V_230 ) ;
F_38 ( V_102 , V_103 ,
F_120 ( V_232 ) ,
F_120 ( 0 ) ,
V_230 * sizeof( struct V_132 ) ) ;
if ( V_230 < V_231 ) {
F_91 ( V_19 -> V_23 , V_103 , 0 , V_230 ,
V_231 - V_230 ) ;
F_121 ( V_103 , F_120 ( 0 ) ,
F_120 ( V_230 ) ,
( V_231 - V_230 ) *
sizeof( struct V_132 ) ) ;
}
F_122 ( V_103 , V_231 - V_230 ) ;
F_122 ( V_102 , V_232 + V_230 ) ;
F_49 ( V_103 ) ;
F_49 ( V_102 ) ;
return V_34 ;
}
static int F_163 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_14 * V_102 ,
struct V_14 * V_103 )
{
int V_230 = 0 ;
int V_233 ;
int V_231 ;
int V_232 ;
int V_34 = 0 ;
F_31 ( F_47 ( V_103 ) != V_29 -> V_39 ) ;
F_31 ( F_47 ( V_102 ) != V_29 -> V_39 ) ;
V_231 = F_85 ( V_103 ) ;
V_232 = F_85 ( V_102 ) ;
V_230 = F_160 ( V_19 ) - V_232 ;
if ( V_230 <= 0 )
return 1 ;
if ( V_231 < 4 )
return 1 ;
V_233 = V_231 / 2 + 1 ;
if ( V_233 >= V_231 )
return 1 ;
if ( V_233 < V_230 )
V_230 = V_233 ;
F_91 ( V_19 -> V_23 , V_102 , V_230 , 0 , V_232 ) ;
F_121 ( V_102 , F_120 ( V_230 ) ,
F_120 ( 0 ) ,
( V_232 ) *
sizeof( struct V_132 ) ) ;
F_90 ( V_19 -> V_23 , V_102 , V_103 , 0 ,
V_231 - V_230 , V_230 ) ;
F_38 ( V_102 , V_103 ,
F_120 ( 0 ) ,
F_120 ( V_231 - V_230 ) ,
V_230 * sizeof( struct V_132 ) ) ;
F_122 ( V_103 , V_231 - V_230 ) ;
F_122 ( V_102 , V_232 + V_230 ) ;
F_49 ( V_103 ) ;
F_49 ( V_102 ) ;
return V_34 ;
}
static T_1 int F_188 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_35 )
{
T_2 V_234 ;
struct V_14 * V_235 ;
struct V_14 * V_236 ;
struct V_14 * V_237 ;
struct V_36 V_238 ;
F_70 ( V_2 -> V_8 [ V_35 ] ) ;
F_70 ( V_2 -> V_8 [ V_35 - 1 ] != V_19 -> V_21 ) ;
V_235 = V_2 -> V_8 [ V_35 - 1 ] ;
if ( V_35 == 1 )
F_33 ( V_235 , & V_238 , 0 ) ;
else
F_34 ( V_235 , & V_238 , 0 ) ;
V_236 = F_35 ( V_29 , V_19 , V_19 -> V_135 , 0 ,
V_19 -> V_116 . V_117 , & V_238 ,
V_35 , V_19 -> V_21 -> V_43 , 0 ) ;
if ( F_36 ( V_236 ) )
return F_37 ( V_236 ) ;
F_154 ( V_19 , V_19 -> V_135 ) ;
F_189 ( V_236 , 0 , 0 , sizeof( struct V_239 ) ) ;
F_122 ( V_236 , 1 ) ;
F_125 ( V_236 , V_35 ) ;
F_39 ( V_236 , V_236 -> V_43 ) ;
F_40 ( V_236 , V_29 -> V_39 ) ;
F_41 ( V_236 , V_44 ) ;
F_44 ( V_236 , V_19 -> V_116 . V_117 ) ;
F_45 ( V_236 , V_19 -> V_23 -> V_48 ,
( unsigned long ) F_46 ( V_236 ) ,
V_49 ) ;
F_45 ( V_236 , V_19 -> V_23 -> V_240 ,
( unsigned long ) F_190 ( V_236 ) ,
V_241 ) ;
F_119 ( V_236 , & V_238 , 0 ) ;
F_114 ( V_236 , 0 , V_235 -> V_43 ) ;
V_234 = F_47 ( V_235 ) ;
F_31 ( V_234 != V_29 -> V_39 ) ;
F_115 ( V_236 , 0 , V_234 ) ;
F_49 ( V_236 ) ;
V_237 = V_19 -> V_21 ;
F_94 ( V_19 , V_236 ) ;
F_112 ( V_19 -> V_21 , V_236 ) ;
F_12 ( V_237 ) ;
F_25 ( V_19 ) ;
F_111 ( V_236 ) ;
V_2 -> V_8 [ V_35 ] = V_236 ;
V_2 -> V_9 [ V_35 ] = V_12 ;
V_2 -> V_17 [ V_35 ] = 0 ;
return 0 ;
}
static void F_191 ( struct V_28 * V_29 ,
struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_36 * V_84 , T_2 V_242 ,
int V_79 , int V_35 )
{
struct V_14 * V_235 ;
int V_94 ;
int V_34 ;
F_70 ( ! V_2 -> V_8 [ V_35 ] ) ;
F_108 ( V_2 -> V_8 [ V_35 ] ) ;
V_235 = V_2 -> V_8 [ V_35 ] ;
V_94 = F_85 ( V_235 ) ;
F_70 ( V_79 > V_94 ) ;
F_70 ( V_94 == F_160 ( V_19 ) ) ;
if ( V_79 != V_94 ) {
if ( V_35 )
F_91 ( V_19 -> V_23 , V_235 , V_79 + 1 ,
V_79 , V_94 - V_79 ) ;
F_121 ( V_235 ,
F_120 ( V_79 + 1 ) ,
F_120 ( V_79 ) ,
( V_94 - V_79 ) * sizeof( struct V_132 ) ) ;
}
if ( V_35 ) {
V_34 = F_81 ( V_19 -> V_23 , V_235 , V_79 ,
V_83 ) ;
F_70 ( V_34 < 0 ) ;
}
F_119 ( V_235 , V_84 , V_79 ) ;
F_114 ( V_235 , V_79 , V_242 ) ;
F_31 ( V_29 -> V_39 == 0 ) ;
F_115 ( V_235 , V_79 , V_29 -> V_39 ) ;
F_122 ( V_235 , V_94 + 1 ) ;
F_49 ( V_235 ) ;
}
static T_1 int F_174 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_35 )
{
struct V_14 * V_236 ;
struct V_14 * V_243 ;
struct V_36 V_37 ;
int V_169 ;
int V_34 ;
T_4 V_244 ;
V_236 = V_2 -> V_8 [ V_35 ] ;
F_31 ( F_47 ( V_236 ) != V_29 -> V_39 ) ;
if ( V_236 == V_19 -> V_21 ) {
V_34 = F_188 ( V_29 , V_19 , V_2 , V_35 + 1 ) ;
if ( V_34 )
return V_34 ;
} else {
V_34 = F_165 ( V_29 , V_19 , V_2 , V_35 ) ;
V_236 = V_2 -> V_8 [ V_35 ] ;
if ( ! V_34 && F_85 ( V_236 ) <
F_160 ( V_19 ) - 3 )
return 0 ;
if ( V_34 < 0 )
return V_34 ;
}
V_244 = F_85 ( V_236 ) ;
V_169 = ( V_244 + 1 ) / 2 ;
F_34 ( V_236 , & V_37 , V_169 ) ;
V_243 = F_35 ( V_29 , V_19 , V_19 -> V_135 , 0 ,
V_19 -> V_116 . V_117 ,
& V_37 , V_35 , V_236 -> V_43 , 0 ) ;
if ( F_36 ( V_243 ) )
return F_37 ( V_243 ) ;
F_154 ( V_19 , V_19 -> V_135 ) ;
F_189 ( V_243 , 0 , 0 , sizeof( struct V_239 ) ) ;
F_125 ( V_243 , F_32 ( V_236 ) ) ;
F_39 ( V_243 , V_243 -> V_43 ) ;
F_40 ( V_243 , V_29 -> V_39 ) ;
F_41 ( V_243 , V_44 ) ;
F_44 ( V_243 , V_19 -> V_116 . V_117 ) ;
F_45 ( V_243 , V_19 -> V_23 -> V_48 ,
( unsigned long ) F_46 ( V_243 ) ,
V_49 ) ;
F_45 ( V_243 , V_19 -> V_23 -> V_240 ,
( unsigned long ) F_190 ( V_243 ) ,
V_241 ) ;
F_90 ( V_19 -> V_23 , V_243 , V_236 , 0 , V_169 , V_244 - V_169 ) ;
F_38 ( V_243 , V_236 ,
F_120 ( 0 ) ,
F_120 ( V_169 ) ,
( V_244 - V_169 ) * sizeof( struct V_132 ) ) ;
F_122 ( V_243 , V_244 - V_169 ) ;
F_122 ( V_236 , V_169 ) ;
V_34 = 0 ;
F_49 ( V_236 ) ;
F_49 ( V_243 ) ;
F_191 ( V_29 , V_19 , V_2 , & V_37 , V_243 -> V_43 ,
V_2 -> V_17 [ V_35 + 1 ] + 1 , V_35 + 1 ) ;
if ( V_2 -> V_17 [ V_35 ] >= V_169 ) {
V_2 -> V_17 [ V_35 ] -= V_169 ;
F_21 ( V_236 ) ;
F_12 ( V_236 ) ;
V_2 -> V_8 [ V_35 ] = V_243 ;
V_2 -> V_17 [ V_35 + 1 ] += 1 ;
} else {
F_21 ( V_243 ) ;
F_12 ( V_243 ) ;
}
return V_34 ;
}
static int F_192 ( struct V_14 * V_245 , int V_43 , int V_164 )
{
int V_246 ;
int V_94 = F_85 ( V_245 ) ;
int V_247 = F_144 ( V_94 , V_43 + V_164 ) - 1 ;
if ( ! V_164 )
return 0 ;
V_246 = F_193 ( V_245 , V_43 ) ;
V_246 = V_246 - F_147 ( V_245 , V_247 ) ;
V_246 += sizeof( struct V_177 ) * V_164 ;
F_31 ( V_246 < 0 ) ;
return V_246 ;
}
T_1 int F_178 ( struct V_18 * V_19 ,
struct V_14 * V_163 )
{
int V_94 = F_85 ( V_163 ) ;
int V_34 ;
V_34 = F_146 ( V_19 ) - F_192 ( V_163 , 0 , V_94 ) ;
if ( V_34 < 0 ) {
F_131 ( V_140 L_2
L_3 ,
V_34 , ( unsigned long ) F_146 ( V_19 ) ,
F_192 ( V_163 , 0 , V_94 ) , V_94 ) ;
}
return V_34 ;
}
static T_1 int F_194 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
int V_248 , int V_229 ,
struct V_14 * V_182 ,
int V_249 , T_4 V_250 ,
T_4 V_251 )
{
struct V_14 * V_183 = V_2 -> V_8 [ 0 ] ;
struct V_14 * V_252 = V_2 -> V_8 [ 1 ] ;
struct V_253 V_254 ;
struct V_36 V_37 ;
int V_79 ;
T_4 V_6 ;
int V_255 = 0 ;
int V_230 = 0 ;
struct V_177 * V_256 ;
T_4 V_164 ;
T_4 V_257 ;
T_4 V_258 ;
T_4 V_259 ;
F_195 ( & V_254 ) ;
if ( V_229 )
V_164 = 0 ;
else
V_164 = F_196 ( T_4 , 1 , V_251 ) ;
if ( V_2 -> V_17 [ 0 ] >= V_250 )
V_255 += V_248 ;
V_79 = V_2 -> V_17 [ 1 ] ;
V_6 = V_250 - 1 ;
while ( V_6 >= V_164 ) {
V_256 = F_197 ( V_183 , V_6 ) ;
if ( ! V_229 && V_230 > 0 ) {
if ( V_2 -> V_17 [ 0 ] > V_6 )
break;
if ( V_2 -> V_17 [ 0 ] == V_6 ) {
int V_260 = F_178 ( V_19 , V_183 ) ;
if ( V_260 + V_255 * 2 > V_249 )
break;
}
}
if ( V_2 -> V_17 [ 0 ] == V_6 )
V_255 += V_248 ;
V_259 = F_198 ( V_183 , V_256 ) ;
if ( V_259 + sizeof( * V_256 ) + V_255 > V_249 )
break;
V_230 ++ ;
V_255 += V_259 + sizeof( * V_256 ) ;
if ( V_6 == 0 )
break;
V_6 -- ;
}
if ( V_230 == 0 )
goto V_261;
if ( ! V_229 && V_230 == V_250 )
F_31 ( 1 ) ;
V_257 = F_85 ( V_182 ) ;
V_255 = F_193 ( V_183 , V_250 - V_230 ) ;
V_255 -= F_145 ( V_19 , V_183 ) ;
V_258 = F_145 ( V_19 , V_182 ) ;
F_121 ( V_182 ,
F_199 ( V_182 ) + V_258 - V_255 ,
F_199 ( V_182 ) + V_258 ,
F_146 ( V_19 ) - V_258 ) ;
F_38 ( V_182 , V_183 , F_199 ( V_182 ) +
F_146 ( V_19 ) - V_255 ,
F_199 ( V_183 ) + F_145 ( V_19 , V_183 ) ,
V_255 ) ;
F_121 ( V_182 , F_200 ( V_230 ) ,
F_200 ( 0 ) ,
V_257 * sizeof( struct V_177 ) ) ;
F_38 ( V_182 , V_183 , F_200 ( 0 ) ,
F_200 ( V_250 - V_230 ) ,
V_230 * sizeof( struct V_177 ) ) ;
V_257 += V_230 ;
F_122 ( V_182 , V_257 ) ;
V_255 = F_146 ( V_19 ) ;
for ( V_6 = 0 ; V_6 < V_257 ; V_6 ++ ) {
V_256 = F_197 ( V_182 , V_6 ) ;
V_255 -= F_201 ( V_182 , V_256 , & V_254 ) ;
F_202 ( V_182 , V_256 , V_255 , & V_254 ) ;
}
V_250 -= V_230 ;
F_122 ( V_183 , V_250 ) ;
if ( V_250 )
F_49 ( V_183 ) ;
else
F_106 ( V_29 , V_19 , V_183 ) ;
F_49 ( V_182 ) ;
F_33 ( V_182 , & V_37 , 0 ) ;
F_119 ( V_252 , & V_37 , V_79 + 1 ) ;
F_49 ( V_252 ) ;
if ( V_2 -> V_17 [ 0 ] >= V_250 ) {
V_2 -> V_17 [ 0 ] -= V_250 ;
if ( F_85 ( V_2 -> V_8 [ 0 ] ) == 0 )
F_106 ( V_29 , V_19 , V_2 -> V_8 [ 0 ] ) ;
F_21 ( V_2 -> V_8 [ 0 ] ) ;
F_12 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_182 ;
V_2 -> V_17 [ 1 ] += 1 ;
} else {
F_21 ( V_182 ) ;
F_12 ( V_182 ) ;
}
return 0 ;
V_261:
F_21 ( V_182 ) ;
F_12 ( V_182 ) ;
return 1 ;
}
static int F_203 ( struct V_28 * V_29 , struct V_18
* V_19 , struct V_1 * V_2 ,
int V_262 , int V_248 ,
int V_229 , T_4 V_251 )
{
struct V_14 * V_183 = V_2 -> V_8 [ 0 ] ;
struct V_14 * V_182 ;
struct V_14 * V_252 ;
int V_79 ;
int V_249 ;
T_4 V_250 ;
int V_34 ;
if ( ! V_2 -> V_8 [ 1 ] )
return 1 ;
V_79 = V_2 -> V_17 [ 1 ] ;
V_252 = V_2 -> V_8 [ 1 ] ;
if ( V_79 >= F_85 ( V_252 ) - 1 )
return 1 ;
F_108 ( V_2 -> V_8 [ 1 ] ) ;
V_182 = F_159 ( V_19 , V_252 , V_79 + 1 ) ;
if ( V_182 == NULL )
return 1 ;
F_20 ( V_182 ) ;
F_132 ( V_182 ) ;
V_249 = F_178 ( V_19 , V_182 ) ;
if ( V_249 < V_248 )
goto V_261;
V_34 = F_130 ( V_29 , V_19 , V_182 , V_252 ,
V_79 + 1 , & V_182 ) ;
if ( V_34 )
goto V_261;
V_249 = F_178 ( V_19 , V_182 ) ;
if ( V_249 < V_248 )
goto V_261;
V_250 = F_85 ( V_183 ) ;
if ( V_250 == 0 )
goto V_261;
return F_194 ( V_29 , V_19 , V_2 , V_262 , V_229 ,
V_182 , V_249 , V_250 , V_251 ) ;
V_261:
F_21 ( V_182 ) ;
F_12 ( V_182 ) ;
return 1 ;
}
static T_1 int F_204 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_248 ,
int V_229 , struct V_14 * V_183 ,
int V_249 , T_4 V_257 ,
T_4 V_263 )
{
struct V_36 V_37 ;
struct V_14 * V_182 = V_2 -> V_8 [ 0 ] ;
int V_6 ;
int V_255 = 0 ;
int V_230 = 0 ;
struct V_177 * V_256 ;
T_4 V_264 ;
T_4 V_164 ;
int V_34 = 0 ;
T_4 V_259 ;
T_4 V_265 ;
struct V_253 V_254 ;
F_195 ( & V_254 ) ;
if ( V_229 )
V_164 = F_144 ( V_257 , V_263 ) ;
else
V_164 = F_144 ( V_257 - 1 , V_263 ) ;
for ( V_6 = 0 ; V_6 < V_164 ; V_6 ++ ) {
V_256 = F_197 ( V_182 , V_6 ) ;
if ( ! V_229 && V_230 > 0 ) {
if ( V_2 -> V_17 [ 0 ] < V_6 )
break;
if ( V_2 -> V_17 [ 0 ] == V_6 ) {
int V_260 = F_178 ( V_19 , V_182 ) ;
if ( V_260 + V_255 * 2 > V_249 )
break;
}
}
if ( V_2 -> V_17 [ 0 ] == V_6 )
V_255 += V_248 ;
V_259 = F_198 ( V_182 , V_256 ) ;
if ( V_259 + sizeof( * V_256 ) + V_255 > V_249 )
break;
V_230 ++ ;
V_255 += V_259 + sizeof( * V_256 ) ;
}
if ( V_230 == 0 ) {
V_34 = 1 ;
goto V_91;
}
if ( ! V_229 && V_230 == F_85 ( V_182 ) )
F_31 ( 1 ) ;
F_38 ( V_183 , V_182 ,
F_200 ( F_85 ( V_183 ) ) ,
F_200 ( 0 ) ,
V_230 * sizeof( struct V_177 ) ) ;
V_255 = F_146 ( V_19 ) -
F_147 ( V_182 , V_230 - 1 ) ;
F_38 ( V_183 , V_182 , F_199 ( V_183 ) +
F_145 ( V_19 , V_183 ) - V_255 ,
F_199 ( V_182 ) +
F_147 ( V_182 , V_230 - 1 ) ,
V_255 ) ;
V_264 = F_85 ( V_183 ) ;
F_70 ( V_264 <= 0 ) ;
V_265 = F_147 ( V_183 , V_264 - 1 ) ;
for ( V_6 = V_264 ; V_6 < V_264 + V_230 ; V_6 ++ ) {
T_4 V_266 ;
V_256 = F_197 ( V_183 , V_6 ) ;
V_266 = F_205 ( V_183 , V_256 , & V_254 ) ;
F_202 ( V_183 , V_256 ,
V_266 - ( F_146 ( V_19 ) - V_265 ) ,
& V_254 ) ;
}
F_122 ( V_183 , V_264 + V_230 ) ;
if ( V_230 > V_257 ) {
F_131 ( V_140 L_4 , V_230 ,
V_257 ) ;
F_31 ( 1 ) ;
}
if ( V_230 < V_257 ) {
V_255 = F_147 ( V_182 , V_230 - 1 ) -
F_145 ( V_19 , V_182 ) ;
F_121 ( V_182 , F_199 ( V_182 ) +
F_146 ( V_19 ) - V_255 ,
F_199 ( V_182 ) +
F_145 ( V_19 , V_182 ) , V_255 ) ;
F_121 ( V_182 , F_200 ( 0 ) ,
F_200 ( V_230 ) ,
( F_85 ( V_182 ) - V_230 ) *
sizeof( struct V_177 ) ) ;
}
V_257 -= V_230 ;
F_122 ( V_182 , V_257 ) ;
V_255 = F_146 ( V_19 ) ;
for ( V_6 = 0 ; V_6 < V_257 ; V_6 ++ ) {
V_256 = F_197 ( V_182 , V_6 ) ;
V_255 = V_255 - F_201 ( V_182 ,
V_256 , & V_254 ) ;
F_202 ( V_182 , V_256 , V_255 , & V_254 ) ;
}
F_49 ( V_183 ) ;
if ( V_257 )
F_49 ( V_182 ) ;
else
F_106 ( V_29 , V_19 , V_182 ) ;
F_33 ( V_182 , & V_37 , 0 ) ;
F_184 ( V_29 , V_19 , V_2 , & V_37 , 1 ) ;
if ( V_2 -> V_17 [ 0 ] < V_230 ) {
V_2 -> V_17 [ 0 ] += V_264 ;
F_21 ( V_2 -> V_8 [ 0 ] ) ;
F_12 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_183 ;
V_2 -> V_17 [ 1 ] -= 1 ;
} else {
F_21 ( V_183 ) ;
F_12 ( V_183 ) ;
V_2 -> V_17 [ 0 ] -= V_230 ;
}
F_70 ( V_2 -> V_17 [ 0 ] < 0 ) ;
return V_34 ;
V_91:
F_21 ( V_183 ) ;
F_12 ( V_183 ) ;
return V_34 ;
}
static int F_206 ( struct V_28 * V_29 , struct V_18
* V_19 , struct V_1 * V_2 , int V_262 ,
int V_248 , int V_229 , T_4 V_263 )
{
struct V_14 * V_182 = V_2 -> V_8 [ 0 ] ;
struct V_14 * V_183 ;
int V_79 ;
int V_249 ;
T_4 V_257 ;
int V_34 = 0 ;
V_79 = V_2 -> V_17 [ 1 ] ;
if ( V_79 == 0 )
return 1 ;
if ( ! V_2 -> V_8 [ 1 ] )
return 1 ;
V_257 = F_85 ( V_182 ) ;
if ( V_257 == 0 )
return 1 ;
F_108 ( V_2 -> V_8 [ 1 ] ) ;
V_183 = F_159 ( V_19 , V_2 -> V_8 [ 1 ] , V_79 - 1 ) ;
if ( V_183 == NULL )
return 1 ;
F_20 ( V_183 ) ;
F_132 ( V_183 ) ;
V_249 = F_178 ( V_19 , V_183 ) ;
if ( V_249 < V_248 ) {
V_34 = 1 ;
goto V_91;
}
V_34 = F_130 ( V_29 , V_19 , V_183 ,
V_2 -> V_8 [ 1 ] , V_79 - 1 , & V_183 ) ;
if ( V_34 ) {
if ( V_34 == - V_190 )
V_34 = 1 ;
goto V_91;
}
V_249 = F_178 ( V_19 , V_183 ) ;
if ( V_249 < V_248 ) {
V_34 = 1 ;
goto V_91;
}
return F_204 ( V_29 , V_19 , V_2 , V_262 ,
V_229 , V_183 , V_249 , V_257 ,
V_263 ) ;
V_91:
F_21 ( V_183 ) ;
F_12 ( V_183 ) ;
return V_34 ;
}
static T_1 void F_207 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_14 * V_245 ,
struct V_14 * V_182 ,
int V_79 , int V_169 , int V_94 )
{
int V_267 ;
int V_268 ;
int V_6 ;
struct V_36 V_37 ;
struct V_253 V_254 ;
F_195 ( & V_254 ) ;
V_94 = V_94 - V_169 ;
F_122 ( V_182 , V_94 ) ;
V_267 = F_193 ( V_245 , V_169 ) - F_145 ( V_19 , V_245 ) ;
F_38 ( V_182 , V_245 , F_200 ( 0 ) ,
F_200 ( V_169 ) ,
V_94 * sizeof( struct V_177 ) ) ;
F_38 ( V_182 , V_245 ,
F_199 ( V_182 ) + F_146 ( V_19 ) -
V_267 , F_199 ( V_245 ) +
F_145 ( V_19 , V_245 ) , V_267 ) ;
V_268 = F_146 ( V_19 ) -
F_193 ( V_245 , V_169 ) ;
for ( V_6 = 0 ; V_6 < V_94 ; V_6 ++ ) {
struct V_177 * V_256 = F_197 ( V_182 , V_6 ) ;
T_4 V_266 ;
V_266 = F_205 ( V_182 , V_256 , & V_254 ) ;
F_202 ( V_182 , V_256 ,
V_266 + V_268 , & V_254 ) ;
}
F_122 ( V_245 , V_169 ) ;
F_33 ( V_182 , & V_37 , 0 ) ;
F_191 ( V_29 , V_19 , V_2 , & V_37 , V_182 -> V_43 ,
V_2 -> V_17 [ 1 ] + 1 , 1 ) ;
F_49 ( V_182 ) ;
F_49 ( V_245 ) ;
F_70 ( V_2 -> V_17 [ 0 ] != V_79 ) ;
if ( V_169 <= V_79 ) {
F_21 ( V_2 -> V_8 [ 0 ] ) ;
F_12 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_182 ;
V_2 -> V_17 [ 0 ] -= V_169 ;
V_2 -> V_17 [ 1 ] += 1 ;
} else {
F_21 ( V_182 ) ;
F_12 ( V_182 ) ;
}
F_70 ( V_2 -> V_17 [ 0 ] < 0 ) ;
}
static T_1 int F_208 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
int V_248 )
{
int V_34 ;
int V_152 = 0 ;
int V_79 ;
T_4 V_94 ;
V_79 = V_2 -> V_17 [ 0 ] ;
V_34 = F_203 ( V_29 , V_19 , V_2 , 1 , V_248 , 0 , V_79 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_34 == 0 )
V_152 ++ ;
V_94 = F_85 ( V_2 -> V_8 [ 0 ] ) ;
if ( V_2 -> V_17 [ 0 ] == 0 || V_2 -> V_17 [ 0 ] == V_94 )
return 0 ;
if ( F_178 ( V_19 , V_2 -> V_8 [ 0 ] ) >= V_248 )
return 0 ;
V_79 = V_2 -> V_17 [ 0 ] ;
V_34 = F_206 ( V_29 , V_19 , V_2 , 1 , V_248 , 0 , V_79 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_34 == 0 )
V_152 ++ ;
if ( V_152 )
return 0 ;
return 1 ;
}
static T_1 int F_179 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_145 * V_269 ,
struct V_1 * V_2 , int V_248 ,
int V_270 )
{
struct V_36 V_37 ;
struct V_14 * V_245 ;
T_4 V_94 ;
int V_169 ;
int V_79 ;
struct V_14 * V_182 ;
int V_34 = 0 ;
int V_184 ;
int V_243 ;
int V_271 = 0 ;
int V_272 = 0 ;
V_245 = V_2 -> V_8 [ 0 ] ;
V_79 = V_2 -> V_17 [ 0 ] ;
if ( V_270 && V_248 + F_209 ( V_245 , V_79 ) +
sizeof( struct V_177 ) > F_146 ( V_19 ) )
return - V_273 ;
if ( V_248 ) {
V_184 = F_203 ( V_29 , V_19 , V_2 , V_248 ,
V_248 , 0 , 0 ) ;
if ( V_184 < 0 )
return V_184 ;
if ( V_184 ) {
V_184 = F_206 ( V_29 , V_19 , V_2 , V_248 ,
V_248 , 0 , ( T_4 ) - 1 ) ;
if ( V_184 < 0 )
return V_184 ;
}
V_245 = V_2 -> V_8 [ 0 ] ;
if ( F_178 ( V_19 , V_245 ) >= V_248 )
return 0 ;
}
if ( ! V_2 -> V_8 [ 1 ] ) {
V_34 = F_188 ( V_29 , V_19 , V_2 , 1 ) ;
if ( V_34 )
return V_34 ;
}
V_216:
V_243 = 1 ;
V_245 = V_2 -> V_8 [ 0 ] ;
V_79 = V_2 -> V_17 [ 0 ] ;
V_94 = F_85 ( V_245 ) ;
V_169 = ( V_94 + 1 ) / 2 ;
if ( V_169 <= V_79 ) {
if ( V_94 == 1 ||
F_192 ( V_245 , V_169 , V_94 - V_169 ) + V_248 >
F_146 ( V_19 ) ) {
if ( V_79 >= V_94 ) {
V_243 = 0 ;
} else {
V_169 = V_79 ;
if ( V_169 != V_94 &&
F_192 ( V_245 , V_169 , V_94 - V_169 ) +
V_248 > F_146 ( V_19 ) ) {
if ( V_248 && ! V_272 )
goto V_274;
V_243 = 2 ;
}
}
}
} else {
if ( F_192 ( V_245 , 0 , V_169 ) + V_248 >
F_146 ( V_19 ) ) {
if ( ! V_270 && V_248 && V_79 == 0 ) {
V_243 = 0 ;
} else if ( ( V_270 || ! V_248 ) && V_79 == 0 ) {
V_169 = 1 ;
} else {
V_169 = V_79 ;
if ( V_169 != V_94 &&
F_192 ( V_245 , V_169 , V_94 - V_169 ) +
V_248 > F_146 ( V_19 ) ) {
if ( V_248 && ! V_272 )
goto V_274;
V_243 = 2 ;
}
}
}
}
if ( V_243 == 0 )
F_186 ( & V_37 , V_269 ) ;
else
F_33 ( V_245 , & V_37 , V_169 ) ;
V_182 = F_35 ( V_29 , V_19 , V_19 -> V_275 , 0 ,
V_19 -> V_116 . V_117 ,
& V_37 , 0 , V_245 -> V_43 , 0 ) ;
if ( F_36 ( V_182 ) )
return F_37 ( V_182 ) ;
F_154 ( V_19 , V_19 -> V_275 ) ;
F_189 ( V_182 , 0 , 0 , sizeof( struct V_239 ) ) ;
F_39 ( V_182 , V_182 -> V_43 ) ;
F_40 ( V_182 , V_29 -> V_39 ) ;
F_41 ( V_182 , V_44 ) ;
F_44 ( V_182 , V_19 -> V_116 . V_117 ) ;
F_125 ( V_182 , 0 ) ;
F_45 ( V_182 , V_19 -> V_23 -> V_48 ,
( unsigned long ) F_46 ( V_182 ) ,
V_49 ) ;
F_45 ( V_182 , V_19 -> V_23 -> V_240 ,
( unsigned long ) F_190 ( V_182 ) ,
V_241 ) ;
if ( V_243 == 0 ) {
if ( V_169 <= V_79 ) {
F_122 ( V_182 , 0 ) ;
F_191 ( V_29 , V_19 , V_2 , & V_37 , V_182 -> V_43 ,
V_2 -> V_17 [ 1 ] + 1 , 1 ) ;
F_21 ( V_2 -> V_8 [ 0 ] ) ;
F_12 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_182 ;
V_2 -> V_17 [ 0 ] = 0 ;
V_2 -> V_17 [ 1 ] += 1 ;
} else {
F_122 ( V_182 , 0 ) ;
F_191 ( V_29 , V_19 , V_2 , & V_37 , V_182 -> V_43 ,
V_2 -> V_17 [ 1 ] , 1 ) ;
F_21 ( V_2 -> V_8 [ 0 ] ) ;
F_12 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_182 ;
V_2 -> V_17 [ 0 ] = 0 ;
if ( V_2 -> V_17 [ 1 ] == 0 )
F_184 ( V_29 , V_19 , V_2 ,
& V_37 , 1 ) ;
}
F_49 ( V_182 ) ;
return V_34 ;
}
F_207 ( V_29 , V_19 , V_2 , V_245 , V_182 , V_79 , V_169 , V_94 ) ;
if ( V_243 == 2 ) {
F_70 ( V_271 != 0 ) ;
V_271 ++ ;
goto V_216;
}
return 0 ;
V_274:
F_208 ( V_29 , V_19 , V_2 , V_248 ) ;
V_272 = 1 ;
if ( F_178 ( V_19 , V_2 -> V_8 [ 0 ] ) >= V_248 )
return 0 ;
goto V_216;
}
static T_1 int F_210 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_213 )
{
struct V_145 V_84 ;
struct V_14 * V_163 ;
struct V_276 * V_277 ;
T_2 V_278 = 0 ;
T_4 V_165 ;
int V_34 ;
V_163 = V_2 -> V_8 [ 0 ] ;
F_211 ( V_163 , & V_84 , V_2 -> V_17 [ 0 ] ) ;
F_70 ( V_84 . type != V_279 &&
V_84 . type != V_280 ) ;
if ( F_178 ( V_19 , V_163 ) >= V_213 )
return 0 ;
V_165 = F_209 ( V_163 , V_2 -> V_17 [ 0 ] ) ;
if ( V_84 . type == V_279 ) {
V_277 = F_212 ( V_163 , V_2 -> V_17 [ 0 ] ,
struct V_276 ) ;
V_278 = F_213 ( V_163 , V_277 ) ;
}
F_9 ( V_2 ) ;
V_2 -> V_210 = 1 ;
V_2 -> V_214 = 1 ;
V_34 = F_175 ( V_29 , V_19 , & V_84 , V_2 , 0 , 1 ) ;
V_2 -> V_214 = 0 ;
if ( V_34 < 0 )
goto V_157;
V_34 = - V_203 ;
V_163 = V_2 -> V_8 [ 0 ] ;
if ( V_34 > 0 || V_165 != F_209 ( V_163 , V_2 -> V_17 [ 0 ] ) )
goto V_157;
if ( F_178 ( V_19 , V_2 -> V_8 [ 0 ] ) >= V_213 )
goto V_157;
if ( V_84 . type == V_279 ) {
V_277 = F_212 ( V_163 , V_2 -> V_17 [ 0 ] ,
struct V_276 ) ;
if ( V_278 != F_213 ( V_163 , V_277 ) )
goto V_157;
}
F_3 ( V_2 ) ;
V_34 = F_179 ( V_29 , V_19 , & V_84 , V_2 , V_213 , 1 ) ;
if ( V_34 )
goto V_157;
V_2 -> V_210 = 0 ;
F_171 ( V_2 , 1 ) ;
return 0 ;
V_157:
V_2 -> V_210 = 0 ;
return V_34 ;
}
static T_1 int F_214 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_145 * V_228 ,
unsigned long V_281 )
{
struct V_14 * V_163 ;
struct V_177 * V_256 ;
struct V_177 * V_282 ;
int V_79 ;
char * V_30 ;
T_4 V_94 ;
T_4 V_165 ;
T_4 V_283 ;
struct V_36 V_37 ;
V_163 = V_2 -> V_8 [ 0 ] ;
F_70 ( F_178 ( V_19 , V_163 ) < sizeof( struct V_177 ) ) ;
F_3 ( V_2 ) ;
V_256 = F_197 ( V_163 , V_2 -> V_17 [ 0 ] ) ;
V_283 = F_215 ( V_163 , V_256 ) ;
V_165 = F_198 ( V_163 , V_256 ) ;
V_30 = F_216 ( V_165 , V_4 ) ;
if ( ! V_30 )
return - V_78 ;
F_150 ( V_163 , V_30 , F_217 ( V_163 ,
V_2 -> V_17 [ 0 ] ) , V_165 ) ;
V_79 = V_2 -> V_17 [ 0 ] + 1 ;
V_94 = F_85 ( V_163 ) ;
if ( V_79 != V_94 ) {
F_121 ( V_163 , F_200 ( V_79 + 1 ) ,
F_200 ( V_79 ) ,
( V_94 - V_79 ) * sizeof( struct V_177 ) ) ;
}
F_186 ( & V_37 , V_228 ) ;
F_187 ( V_163 , & V_37 , V_79 ) ;
V_282 = F_197 ( V_163 , V_79 ) ;
F_218 ( V_163 , V_282 , V_283 ) ;
F_219 ( V_163 , V_282 , V_165 - V_281 ) ;
F_218 ( V_163 , V_256 ,
V_283 + V_165 - V_281 ) ;
F_219 ( V_163 , V_256 , V_281 ) ;
F_122 ( V_163 , V_94 + 1 ) ;
F_45 ( V_163 , V_30 ,
F_217 ( V_163 , V_2 -> V_17 [ 0 ] ) ,
V_281 ) ;
F_45 ( V_163 , V_30 + V_281 ,
F_217 ( V_163 , V_79 ) ,
V_165 - V_281 ) ;
F_49 ( V_163 ) ;
F_70 ( F_178 ( V_19 , V_163 ) < 0 ) ;
F_68 ( V_30 ) ;
return 0 ;
}
int F_220 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_145 * V_228 ,
unsigned long V_281 )
{
int V_34 ;
V_34 = F_210 ( V_29 , V_19 , V_2 ,
sizeof( struct V_177 ) ) ;
if ( V_34 )
return V_34 ;
V_34 = F_214 ( V_29 , V_19 , V_2 , V_228 , V_281 ) ;
return V_34 ;
}
int F_221 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_145 * V_228 )
{
struct V_14 * V_163 ;
int V_34 ;
T_4 V_165 ;
V_163 = V_2 -> V_8 [ 0 ] ;
V_165 = F_209 ( V_163 , V_2 -> V_17 [ 0 ] ) ;
V_34 = F_210 ( V_29 , V_19 , V_2 ,
V_165 + sizeof( struct V_177 ) ) ;
if ( V_34 )
return V_34 ;
V_2 -> V_17 [ 0 ] ++ ;
F_222 ( V_29 , V_19 , V_2 , V_228 , & V_165 ,
V_165 , V_165 +
sizeof( struct V_177 ) , 1 ) ;
V_163 = V_2 -> V_8 [ 0 ] ;
F_223 ( V_163 ,
F_217 ( V_163 , V_2 -> V_17 [ 0 ] ) ,
F_217 ( V_163 , V_2 -> V_17 [ 0 ] - 1 ) ,
V_165 ) ;
return 0 ;
}
void F_224 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
T_4 V_284 , int V_285 )
{
int V_79 ;
struct V_14 * V_163 ;
struct V_177 * V_256 ;
T_4 V_94 ;
unsigned int V_258 ;
unsigned int V_286 ;
unsigned int V_287 ;
unsigned int V_288 ;
int V_6 ;
struct V_253 V_254 ;
F_195 ( & V_254 ) ;
V_163 = V_2 -> V_8 [ 0 ] ;
V_79 = V_2 -> V_17 [ 0 ] ;
V_287 = F_209 ( V_163 , V_79 ) ;
if ( V_287 == V_284 )
return;
V_94 = F_85 ( V_163 ) ;
V_258 = F_145 ( V_19 , V_163 ) ;
V_286 = F_147 ( V_163 , V_79 ) ;
V_288 = V_287 - V_284 ;
F_70 ( V_79 < 0 ) ;
F_70 ( V_79 >= V_94 ) ;
for ( V_6 = V_79 ; V_6 < V_94 ; V_6 ++ ) {
T_4 V_266 ;
V_256 = F_197 ( V_163 , V_6 ) ;
V_266 = F_205 ( V_163 , V_256 , & V_254 ) ;
F_202 ( V_163 , V_256 ,
V_266 + V_288 , & V_254 ) ;
}
if ( V_285 ) {
F_121 ( V_163 , F_199 ( V_163 ) +
V_258 + V_288 , F_199 ( V_163 ) +
V_258 , V_286 + V_284 - V_258 ) ;
} else {
struct V_36 V_37 ;
T_2 V_148 ;
F_33 ( V_163 , & V_37 , V_79 ) ;
if ( F_225 ( & V_37 ) == V_279 ) {
unsigned long V_289 ;
struct V_276 * V_277 ;
V_277 = F_212 ( V_163 , V_79 ,
struct V_276 ) ;
V_277 = (struct V_276 * ) (
( unsigned long ) V_277 - V_288 ) ;
if ( F_226 ( V_163 , V_277 ) ==
V_290 ) {
V_289 = F_217 ( V_163 , V_79 ) ;
F_121 ( V_163 , V_289 ,
( unsigned long ) V_277 ,
F_152 ( struct V_276 ,
V_291 ) ) ;
}
}
F_121 ( V_163 , F_199 ( V_163 ) +
V_258 + V_288 , F_199 ( V_163 ) +
V_258 , V_286 - V_258 ) ;
V_148 = F_227 ( & V_37 ) ;
F_228 ( & V_37 , V_148 + V_288 ) ;
F_187 ( V_163 , & V_37 , V_79 ) ;
if ( V_79 == 0 )
F_184 ( V_29 , V_19 , V_2 , & V_37 , 1 ) ;
}
V_256 = F_197 ( V_163 , V_79 ) ;
F_219 ( V_163 , V_256 , V_284 ) ;
F_49 ( V_163 ) ;
if ( F_178 ( V_19 , V_163 ) < 0 ) {
F_229 ( V_19 , V_163 ) ;
F_164 () ;
}
}
void F_230 ( struct V_28 * V_29 ,
struct V_18 * V_19 , struct V_1 * V_2 ,
T_4 V_248 )
{
int V_79 ;
struct V_14 * V_163 ;
struct V_177 * V_256 ;
T_4 V_94 ;
unsigned int V_258 ;
unsigned int V_292 ;
unsigned int V_287 ;
int V_6 ;
struct V_253 V_254 ;
F_195 ( & V_254 ) ;
V_163 = V_2 -> V_8 [ 0 ] ;
V_94 = F_85 ( V_163 ) ;
V_258 = F_145 ( V_19 , V_163 ) ;
if ( F_178 ( V_19 , V_163 ) < V_248 ) {
F_229 ( V_19 , V_163 ) ;
F_164 () ;
}
V_79 = V_2 -> V_17 [ 0 ] ;
V_292 = F_193 ( V_163 , V_79 ) ;
F_70 ( V_79 < 0 ) ;
if ( V_79 >= V_94 ) {
F_229 ( V_19 , V_163 ) ;
F_131 ( V_140 L_5 ,
V_79 , V_94 ) ;
F_70 ( 1 ) ;
}
for ( V_6 = V_79 ; V_6 < V_94 ; V_6 ++ ) {
T_4 V_266 ;
V_256 = F_197 ( V_163 , V_6 ) ;
V_266 = F_205 ( V_163 , V_256 , & V_254 ) ;
F_202 ( V_163 , V_256 ,
V_266 - V_248 , & V_254 ) ;
}
F_121 ( V_163 , F_199 ( V_163 ) +
V_258 - V_248 , F_199 ( V_163 ) +
V_258 , V_292 - V_258 ) ;
V_258 = V_292 ;
V_287 = F_209 ( V_163 , V_79 ) ;
V_256 = F_197 ( V_163 , V_79 ) ;
F_219 ( V_163 , V_256 , V_287 + V_248 ) ;
F_49 ( V_163 ) ;
if ( F_178 ( V_19 , V_163 ) < 0 ) {
F_229 ( V_19 , V_163 ) ;
F_164 () ;
}
}
int F_231 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_145 * V_293 , T_4 * V_248 ,
int V_164 )
{
struct V_14 * V_163 ;
struct V_177 * V_256 ;
int V_34 = 0 ;
int V_79 ;
int V_6 ;
T_4 V_94 ;
T_4 V_294 = 0 ;
T_4 V_295 = 0 ;
unsigned int V_258 ;
struct V_36 V_37 ;
struct V_145 V_296 ;
struct V_253 V_254 ;
F_195 ( & V_254 ) ;
for ( V_6 = 0 ; V_6 < V_164 ; V_6 ++ ) {
if ( V_295 + V_248 [ V_6 ] + sizeof( struct V_177 ) >
F_146 ( V_19 ) ) {
break;
V_164 = V_6 ;
}
V_294 += V_248 [ V_6 ] ;
V_295 += V_248 [ V_6 ] + sizeof( struct V_177 ) ;
}
F_70 ( V_164 == 0 ) ;
V_34 = F_175 ( V_29 , V_19 , V_293 , V_2 , V_295 , 1 ) ;
if ( V_34 == 0 )
return - V_74 ;
if ( V_34 < 0 )
goto V_91;
V_163 = V_2 -> V_8 [ 0 ] ;
V_94 = F_85 ( V_163 ) ;
V_258 = F_145 ( V_19 , V_163 ) ;
if ( F_178 ( V_19 , V_163 ) < V_295 ) {
for ( V_6 = V_164 ; V_6 >= 0 ; V_6 -- ) {
V_294 -= V_248 [ V_6 ] ;
V_295 -= V_248 [ V_6 ] + sizeof( struct V_177 ) ;
if ( V_295 < F_178 ( V_19 , V_163 ) )
break;
}
V_164 = V_6 ;
}
V_79 = V_2 -> V_17 [ 0 ] ;
F_70 ( V_79 < 0 ) ;
if ( V_79 != V_94 ) {
unsigned int V_292 = F_193 ( V_163 , V_79 ) ;
V_256 = F_197 ( V_163 , V_79 ) ;
F_211 ( V_163 , & V_296 , V_79 ) ;
V_294 = V_248 [ 0 ] ;
for ( V_6 = 1 ; V_6 < V_164 ; V_6 ++ ) {
if ( F_137 ( & V_296 , V_293 + V_6 ) <= 0 )
break;
V_294 += V_248 [ V_6 ] ;
}
V_164 = V_6 ;
if ( V_292 < V_258 ) {
F_229 ( V_19 , V_163 ) ;
F_131 ( V_140 L_6 ,
V_79 , V_292 , V_258 ) ;
F_70 ( 1 ) ;
}
for ( V_6 = V_79 ; V_6 < V_94 ; V_6 ++ ) {
T_4 V_266 ;
V_256 = F_197 ( V_163 , V_6 ) ;
V_266 = F_205 ( V_163 , V_256 , & V_254 ) ;
F_202 ( V_163 , V_256 ,
V_266 - V_294 , & V_254 ) ;
}
F_121 ( V_163 , F_200 ( V_79 + V_164 ) ,
F_200 ( V_79 ) ,
( V_94 - V_79 ) * sizeof( struct V_177 ) ) ;
F_121 ( V_163 , F_199 ( V_163 ) +
V_258 - V_294 , F_199 ( V_163 ) +
V_258 , V_292 - V_258 ) ;
V_258 = V_292 ;
} else {
V_164 = 1 ;
}
for ( V_6 = 0 ; V_6 < V_164 ; V_6 ++ ) {
F_186 ( & V_37 , V_293 + V_6 ) ;
F_187 ( V_163 , & V_37 , V_79 + V_6 ) ;
V_256 = F_197 ( V_163 , V_79 + V_6 ) ;
F_202 ( V_163 , V_256 ,
V_258 - V_248 [ V_6 ] , & V_254 ) ;
V_258 -= V_248 [ V_6 ] ;
F_232 ( V_163 , V_256 , V_248 [ V_6 ] , & V_254 ) ;
}
F_122 ( V_163 , V_94 + V_164 ) ;
F_49 ( V_163 ) ;
V_34 = 0 ;
if ( V_79 == 0 ) {
F_186 ( & V_37 , V_293 ) ;
F_184 ( V_29 , V_19 , V_2 , & V_37 , 1 ) ;
}
if ( F_178 ( V_19 , V_163 ) < 0 ) {
F_229 ( V_19 , V_163 ) ;
F_164 () ;
}
V_91:
if ( ! V_34 )
V_34 = V_164 ;
return V_34 ;
}
void F_222 ( struct V_28 * V_29 ,
struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_145 * V_293 , T_4 * V_248 ,
T_4 V_294 , T_4 V_295 , int V_164 )
{
struct V_177 * V_256 ;
int V_6 ;
T_4 V_94 ;
unsigned int V_258 ;
struct V_36 V_37 ;
struct V_14 * V_163 ;
int V_79 ;
struct V_253 V_254 ;
F_195 ( & V_254 ) ;
V_163 = V_2 -> V_8 [ 0 ] ;
V_79 = V_2 -> V_17 [ 0 ] ;
V_94 = F_85 ( V_163 ) ;
V_258 = F_145 ( V_19 , V_163 ) ;
if ( F_178 ( V_19 , V_163 ) < V_295 ) {
F_229 ( V_19 , V_163 ) ;
F_131 ( V_140 L_7 ,
V_295 , F_178 ( V_19 , V_163 ) ) ;
F_164 () ;
}
if ( V_79 != V_94 ) {
unsigned int V_292 = F_193 ( V_163 , V_79 ) ;
if ( V_292 < V_258 ) {
F_229 ( V_19 , V_163 ) ;
F_131 ( V_140 L_6 ,
V_79 , V_292 , V_258 ) ;
F_70 ( 1 ) ;
}
for ( V_6 = V_79 ; V_6 < V_94 ; V_6 ++ ) {
T_4 V_266 ;
V_256 = F_197 ( V_163 , V_6 ) ;
V_266 = F_205 ( V_163 , V_256 , & V_254 ) ;
F_202 ( V_163 , V_256 ,
V_266 - V_294 , & V_254 ) ;
}
F_121 ( V_163 , F_200 ( V_79 + V_164 ) ,
F_200 ( V_79 ) ,
( V_94 - V_79 ) * sizeof( struct V_177 ) ) ;
F_121 ( V_163 , F_199 ( V_163 ) +
V_258 - V_294 , F_199 ( V_163 ) +
V_258 , V_292 - V_258 ) ;
V_258 = V_292 ;
}
for ( V_6 = 0 ; V_6 < V_164 ; V_6 ++ ) {
F_186 ( & V_37 , V_293 + V_6 ) ;
F_187 ( V_163 , & V_37 , V_79 + V_6 ) ;
V_256 = F_197 ( V_163 , V_79 + V_6 ) ;
F_202 ( V_163 , V_256 ,
V_258 - V_248 [ V_6 ] , & V_254 ) ;
V_258 -= V_248 [ V_6 ] ;
F_232 ( V_163 , V_256 , V_248 [ V_6 ] , & V_254 ) ;
}
F_122 ( V_163 , V_94 + V_164 ) ;
if ( V_79 == 0 ) {
F_186 ( & V_37 , V_293 ) ;
F_184 ( V_29 , V_19 , V_2 , & V_37 , 1 ) ;
}
F_171 ( V_2 , 1 ) ;
F_49 ( V_163 ) ;
if ( F_178 ( V_19 , V_163 ) < 0 ) {
F_229 ( V_19 , V_163 ) ;
F_164 () ;
}
}
int F_233 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_145 * V_293 , T_4 * V_248 ,
int V_164 )
{
int V_34 = 0 ;
int V_79 ;
int V_6 ;
T_4 V_295 = 0 ;
T_4 V_294 = 0 ;
for ( V_6 = 0 ; V_6 < V_164 ; V_6 ++ )
V_294 += V_248 [ V_6 ] ;
V_295 = V_294 + ( V_164 * sizeof( struct V_177 ) ) ;
V_34 = F_175 ( V_29 , V_19 , V_293 , V_2 , V_295 , 1 ) ;
if ( V_34 == 0 )
return - V_74 ;
if ( V_34 < 0 )
return V_34 ;
V_79 = V_2 -> V_17 [ 0 ] ;
F_70 ( V_79 < 0 ) ;
F_222 ( V_29 , V_19 , V_2 , V_293 , V_248 ,
V_294 , V_295 , V_164 ) ;
return 0 ;
}
int F_234 ( struct V_28 * V_29 , struct V_18
* V_19 , struct V_145 * V_293 , void * V_297 , T_4
V_248 )
{
int V_34 = 0 ;
struct V_1 * V_2 ;
struct V_14 * V_163 ;
unsigned long V_289 ;
V_2 = F_1 () ;
if ( ! V_2 )
return - V_78 ;
V_34 = F_235 ( V_29 , V_19 , V_2 , V_293 , V_248 ) ;
if ( ! V_34 ) {
V_163 = V_2 -> V_8 [ 0 ] ;
V_289 = F_217 ( V_163 , V_2 -> V_17 [ 0 ] ) ;
F_45 ( V_163 , V_297 , V_289 , V_248 ) ;
F_49 ( V_163 ) ;
}
F_8 ( V_2 ) ;
return V_34 ;
}
static void F_162 ( struct V_28 * V_29 , struct V_18 * V_19 ,
struct V_1 * V_2 , int V_35 , int V_79 ,
int V_67 )
{
struct V_14 * V_69 = V_2 -> V_8 [ V_35 ] ;
T_4 V_94 ;
int V_34 ;
V_94 = F_85 ( V_69 ) ;
if ( V_79 != V_94 - 1 ) {
if ( V_67 && V_35 )
F_91 ( V_19 -> V_23 , V_69 , V_79 ,
V_79 + 1 , V_94 - V_79 - 1 ) ;
F_121 ( V_69 ,
F_120 ( V_79 ) ,
F_120 ( V_79 + 1 ) ,
sizeof( struct V_132 ) *
( V_94 - V_79 - 1 ) ) ;
} else if ( V_67 && V_35 ) {
V_34 = F_81 ( V_19 -> V_23 , V_69 , V_79 ,
V_106 ) ;
F_70 ( V_34 < 0 ) ;
}
V_94 -- ;
F_122 ( V_69 , V_94 ) ;
if ( V_94 == 0 && V_69 == V_19 -> V_21 ) {
F_70 ( F_32 ( V_19 -> V_21 ) != 1 ) ;
F_125 ( V_19 -> V_21 , 0 ) ;
} else if ( V_79 == 0 ) {
struct V_36 V_37 ;
F_34 ( V_69 , & V_37 , 0 ) ;
F_184 ( V_29 , V_19 , V_2 , & V_37 , V_35 + 1 ) ;
}
F_49 ( V_69 ) ;
}
static T_1 void F_236 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_14 * V_163 )
{
F_31 ( F_47 ( V_163 ) != V_29 -> V_39 ) ;
F_162 ( V_29 , V_19 , V_2 , 1 , V_2 -> V_17 [ 1 ] , 1 ) ;
F_171 ( V_2 , 0 ) ;
F_157 ( V_19 , V_163 -> V_42 ) ;
F_111 ( V_163 ) ;
F_113 ( V_29 , V_19 , V_163 , 0 , 1 ) ;
F_116 ( V_163 ) ;
}
int F_237 ( struct V_28 * V_29 , struct V_18 * V_19 ,
struct V_1 * V_2 , int V_79 , int V_164 )
{
struct V_14 * V_163 ;
struct V_177 * V_256 ;
int V_298 ;
int V_299 = 0 ;
int V_34 = 0 ;
int V_184 ;
int V_6 ;
T_4 V_94 ;
struct V_253 V_254 ;
F_195 ( & V_254 ) ;
V_163 = V_2 -> V_8 [ 0 ] ;
V_298 = F_147 ( V_163 , V_79 + V_164 - 1 ) ;
for ( V_6 = 0 ; V_6 < V_164 ; V_6 ++ )
V_299 += F_209 ( V_163 , V_79 + V_6 ) ;
V_94 = F_85 ( V_163 ) ;
if ( V_79 + V_164 != V_94 ) {
int V_258 = F_145 ( V_19 , V_163 ) ;
F_121 ( V_163 , F_199 ( V_163 ) +
V_258 + V_299 ,
F_199 ( V_163 ) + V_258 ,
V_298 - V_258 ) ;
for ( V_6 = V_79 + V_164 ; V_6 < V_94 ; V_6 ++ ) {
T_4 V_266 ;
V_256 = F_197 ( V_163 , V_6 ) ;
V_266 = F_205 ( V_163 , V_256 , & V_254 ) ;
F_202 ( V_163 , V_256 ,
V_266 + V_299 , & V_254 ) ;
}
F_121 ( V_163 , F_200 ( V_79 ) ,
F_200 ( V_79 + V_164 ) ,
sizeof( struct V_177 ) *
( V_94 - V_79 - V_164 ) ) ;
}
F_122 ( V_163 , V_94 - V_164 ) ;
V_94 -= V_164 ;
if ( V_94 == 0 ) {
if ( V_163 == V_19 -> V_21 ) {
F_125 ( V_163 , 0 ) ;
} else {
F_3 ( V_2 ) ;
F_106 ( V_29 , V_19 , V_163 ) ;
F_236 ( V_29 , V_19 , V_2 , V_163 ) ;
}
} else {
int V_300 = F_192 ( V_163 , 0 , V_94 ) ;
if ( V_79 == 0 ) {
struct V_36 V_37 ;
F_33 ( V_163 , & V_37 , 0 ) ;
F_184 ( V_29 , V_19 , V_2 , & V_37 , 1 ) ;
}
if ( V_300 < F_146 ( V_19 ) / 3 ) {
V_79 = V_2 -> V_17 [ 1 ] ;
F_111 ( V_163 ) ;
F_3 ( V_2 ) ;
V_184 = F_206 ( V_29 , V_19 , V_2 , 1 , 1 ,
1 , ( T_4 ) - 1 ) ;
if ( V_184 < 0 && V_184 != - V_190 )
V_34 = V_184 ;
if ( V_2 -> V_8 [ 0 ] == V_163 &&
F_85 ( V_163 ) ) {
V_184 = F_203 ( V_29 , V_19 , V_2 , 1 ,
1 , 1 , 0 ) ;
if ( V_184 < 0 && V_184 != - V_190 )
V_34 = V_184 ;
}
if ( F_85 ( V_163 ) == 0 ) {
V_2 -> V_17 [ 1 ] = V_79 ;
F_236 ( V_29 , V_19 , V_2 , V_163 ) ;
F_12 ( V_163 ) ;
V_34 = 0 ;
} else {
if ( V_2 -> V_8 [ 0 ] == V_163 )
F_49 ( V_163 ) ;
F_12 ( V_163 ) ;
}
} else {
F_49 ( V_163 ) ;
}
}
return V_34 ;
}
int F_183 ( struct V_18 * V_19 , struct V_1 * V_2 )
{
struct V_145 V_84 ;
struct V_36 V_296 ;
int V_34 ;
F_211 ( V_2 -> V_8 [ 0 ] , & V_84 , 0 ) ;
if ( V_84 . V_148 > 0 )
V_84 . V_148 -- ;
else if ( V_84 . type > 0 )
V_84 . type -- ;
else if ( V_84 . V_117 > 0 )
V_84 . V_117 -- ;
else
return 1 ;
F_9 ( V_2 ) ;
V_34 = F_175 ( NULL , V_19 , & V_84 , V_2 , 0 , 0 ) ;
if ( V_34 < 0 )
return V_34 ;
F_33 ( V_2 -> V_8 [ 0 ] , & V_296 , 0 ) ;
V_34 = F_135 ( & V_296 , & V_84 ) ;
if ( V_34 < 0 )
return 0 ;
return 1 ;
}
int F_238 ( struct V_18 * V_19 , struct V_145 * V_301 ,
struct V_145 * V_302 ,
struct V_1 * V_2 , int V_150 ,
T_2 V_303 )
{
struct V_14 * V_70 ;
struct V_145 V_296 ;
int V_79 ;
int V_215 ;
T_4 V_94 ;
int V_35 ;
int V_34 = 1 ;
F_31 ( ! V_2 -> V_210 ) ;
V_216:
V_70 = F_22 ( V_19 ) ;
V_35 = F_32 ( V_70 ) ;
F_31 ( V_2 -> V_8 [ V_35 ] ) ;
V_2 -> V_8 [ V_35 ] = V_70 ;
V_2 -> V_9 [ V_35 ] = V_10 ;
if ( F_47 ( V_70 ) < V_303 ) {
V_34 = 1 ;
goto V_91;
}
while ( 1 ) {
V_94 = F_85 ( V_70 ) ;
V_35 = F_32 ( V_70 ) ;
V_215 = F_151 ( V_70 , V_301 , V_35 , & V_79 ) ;
if ( V_35 == V_2 -> V_219 ) {
if ( V_79 >= V_94 )
goto V_304;
V_34 = 0 ;
V_2 -> V_17 [ V_35 ] = V_79 ;
F_211 ( V_70 , & V_296 , V_79 ) ;
goto V_91;
}
if ( V_215 && V_79 > 0 )
V_79 -- ;
while ( V_79 < V_94 ) {
T_2 V_85 ;
T_2 V_153 ;
struct V_14 * V_170 ;
struct V_36 V_37 ;
V_85 = F_78 ( V_70 , V_79 ) ;
V_153 = F_79 ( V_70 , V_79 ) ;
if ( V_153 < V_303 ) {
V_79 ++ ;
continue;
}
if ( ! V_150 )
break;
if ( V_302 ) {
F_34 ( V_70 , & V_37 , V_79 ) ;
if ( F_135 ( & V_37 , V_302 ) >= 0 ) {
V_34 = 1 ;
goto V_91;
}
}
V_170 = F_140 ( V_19 , V_85 ,
F_139 ( V_19 , V_35 - 1 ) ) ;
if ( V_170 && F_141 ( V_170 , V_153 , 1 ) > 0 ) {
F_12 ( V_170 ) ;
break;
}
if ( V_170 )
F_12 ( V_170 ) ;
V_79 ++ ;
}
V_304:
if ( V_79 >= V_94 ) {
V_2 -> V_17 [ V_35 ] = V_79 ;
F_3 ( V_2 ) ;
V_215 = F_239 ( V_19 , V_2 , V_301 , V_35 ,
V_150 , V_303 ) ;
if ( V_215 == 0 ) {
F_9 ( V_2 ) ;
goto V_216;
} else {
goto V_91;
}
}
F_240 ( V_70 , & V_296 , V_79 ) ;
V_2 -> V_17 [ V_35 ] = V_79 ;
if ( V_35 == V_2 -> V_219 ) {
V_34 = 0 ;
F_170 ( V_2 , V_35 , 1 , 0 , NULL ) ;
goto V_91;
}
F_3 ( V_2 ) ;
V_70 = F_159 ( V_19 , V_70 , V_79 ) ;
F_70 ( ! V_70 ) ;
F_23 ( V_70 ) ;
V_2 -> V_9 [ V_35 - 1 ] = V_10 ;
V_2 -> V_8 [ V_35 - 1 ] = V_70 ;
F_170 ( V_2 , V_35 , 1 , 0 , NULL ) ;
F_5 ( V_2 , NULL , 0 ) ;
}
V_91:
if ( V_34 == 0 )
memcpy ( V_301 , & V_296 , sizeof( V_296 ) ) ;
F_3 ( V_2 ) ;
return V_34 ;
}
static void F_241 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int * V_35 , int V_305 )
{
V_2 -> V_8 [ * V_35 - 1 ] = F_159 ( V_19 , V_2 -> V_8 [ * V_35 ] ,
V_2 -> V_17 [ * V_35 ] ) ;
V_2 -> V_17 [ * V_35 - 1 ] = 0 ;
( * V_35 ) -- ;
}
static int F_242 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int * V_35 , int V_305 )
{
int V_34 = 0 ;
int V_94 ;
V_94 = F_85 ( V_2 -> V_8 [ * V_35 ] ) ;
V_2 -> V_17 [ * V_35 ] ++ ;
while ( V_2 -> V_17 [ * V_35 ] == V_94 ) {
if ( * V_35 == V_305 )
return - 1 ;
V_2 -> V_17 [ * V_35 ] = 0 ;
F_12 ( V_2 -> V_8 [ * V_35 ] ) ;
V_2 -> V_8 [ * V_35 ] = NULL ;
( * V_35 ) ++ ;
V_2 -> V_17 [ * V_35 ] ++ ;
V_94 = F_85 ( V_2 -> V_8 [ * V_35 ] ) ;
V_34 = 1 ;
}
return V_34 ;
}
static int F_243 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int * V_35 , int V_305 ,
int V_306 ,
struct V_145 * V_84 )
{
int V_34 ;
if ( * V_35 == 0 || ! V_306 ) {
V_34 = F_242 ( V_19 , V_2 , V_35 , V_305 ) ;
} else {
F_241 ( V_19 , V_2 , V_35 , V_305 ) ;
V_34 = 0 ;
}
if ( V_34 >= 0 ) {
if ( * V_35 == 0 )
F_211 ( V_2 -> V_8 [ * V_35 ] , V_84 ,
V_2 -> V_17 [ * V_35 ] ) ;
else
F_240 ( V_2 -> V_8 [ * V_35 ] , V_84 ,
V_2 -> V_17 [ * V_35 ] ) ;
}
return V_34 ;
}
static int F_244 ( struct V_18 * V_307 ,
struct V_1 * V_308 ,
struct V_1 * V_309 ,
char * V_310 )
{
int V_311 ;
int V_312 , V_313 ;
unsigned long V_314 , V_315 ;
V_312 = F_209 ( V_308 -> V_8 [ 0 ] , V_308 -> V_17 [ 0 ] ) ;
V_313 = F_209 ( V_309 -> V_8 [ 0 ] , V_309 -> V_17 [ 0 ] ) ;
if ( V_312 != V_313 )
return 1 ;
V_314 = F_217 ( V_308 -> V_8 [ 0 ] , V_308 -> V_17 [ 0 ] ) ;
V_315 = F_217 ( V_309 -> V_8 [ 0 ] ,
V_309 -> V_17 [ 0 ] ) ;
F_150 ( V_308 -> V_8 [ 0 ] , V_310 , V_314 , V_312 ) ;
V_311 = F_245 ( V_309 -> V_8 [ 0 ] , V_310 , V_315 , V_312 ) ;
if ( V_311 )
return 1 ;
return 0 ;
}
int F_246 ( struct V_18 * V_307 ,
struct V_18 * V_316 ,
T_6 V_317 , void * V_318 )
{
int V_34 ;
int V_311 ;
struct V_28 * V_29 = NULL ;
struct V_1 * V_308 = NULL ;
struct V_1 * V_309 = NULL ;
struct V_145 V_319 ;
struct V_145 V_191 ;
char * V_310 = NULL ;
int V_320 ;
int V_321 ;
int V_322 ;
int V_323 ;
int V_324 ;
int V_325 ;
int V_326 ;
int V_327 ;
T_2 V_328 ;
T_2 V_329 ;
T_2 V_330 ;
T_2 V_331 ;
T_2 V_332 ;
V_308 = F_1 () ;
if ( ! V_308 ) {
V_34 = - V_78 ;
goto V_91;
}
V_309 = F_1 () ;
if ( ! V_309 ) {
V_34 = - V_78 ;
goto V_91;
}
V_310 = F_216 ( V_307 -> V_275 , V_4 ) ;
if ( ! V_310 ) {
V_34 = - V_78 ;
goto V_91;
}
V_308 -> V_220 = 1 ;
V_308 -> V_221 = 1 ;
V_309 -> V_220 = 1 ;
V_309 -> V_221 = 1 ;
F_26 ( & V_307 -> V_333 ) ;
V_330 = F_247 ( & V_307 -> V_111 ) ;
F_29 ( & V_307 -> V_333 ) ;
F_26 ( & V_316 -> V_333 ) ;
V_331 = F_247 ( & V_316 -> V_111 ) ;
F_29 ( & V_316 -> V_333 ) ;
V_29 = F_248 ( V_307 ) ;
if ( F_36 ( V_29 ) ) {
V_34 = F_37 ( V_29 ) ;
V_29 = NULL ;
goto V_91;
}
V_322 = F_32 ( V_307 -> V_110 ) ;
V_320 = V_322 ;
V_308 -> V_8 [ V_322 ] = V_307 -> V_110 ;
F_111 ( V_308 -> V_8 [ V_322 ] ) ;
V_323 = F_32 ( V_316 -> V_110 ) ;
V_321 = V_323 ;
V_309 -> V_8 [ V_323 ] = V_316 -> V_110 ;
F_111 ( V_309 -> V_8 [ V_323 ] ) ;
if ( V_322 == 0 )
F_211 ( V_308 -> V_8 [ V_322 ] ,
& V_319 , V_308 -> V_17 [ V_322 ] ) ;
else
F_240 ( V_308 -> V_8 [ V_322 ] ,
& V_319 , V_308 -> V_17 [ V_322 ] ) ;
if ( V_323 == 0 )
F_211 ( V_309 -> V_8 [ V_323 ] ,
& V_191 , V_309 -> V_17 [ V_323 ] ) ;
else
F_240 ( V_309 -> V_8 [ V_323 ] ,
& V_191 , V_309 -> V_17 [ V_323 ] ) ;
V_324 = V_325 = 0 ;
V_326 = V_327 = 0 ;
while ( 1 ) {
if ( V_29 && F_249 ( V_29 , V_307 ) ) {
F_9 ( V_308 ) ;
F_9 ( V_309 ) ;
V_34 = F_250 ( V_29 , V_307 ) ;
V_29 = NULL ;
if ( V_34 < 0 )
goto V_91;
}
if ( ! V_29 ) {
V_29 = F_248 ( V_307 ) ;
if ( F_36 ( V_29 ) ) {
V_34 = F_37 ( V_29 ) ;
V_29 = NULL ;
goto V_91;
}
F_26 ( & V_307 -> V_333 ) ;
V_332 = F_247 ( & V_307 -> V_111 ) ;
F_29 ( & V_307 -> V_333 ) ;
if ( V_332 != V_330 )
V_330 = 0 ;
F_26 ( & V_316 -> V_333 ) ;
V_332 = F_247 ( & V_316 -> V_111 ) ;
F_29 ( & V_316 -> V_333 ) ;
if ( V_332 != V_331 )
V_331 = 0 ;
if ( ! V_330 || ! V_331 ) {
F_251 ( 1 , V_334
L_8
L_9
L_10
L_11 ) ;
V_34 = - V_162 ;
goto V_91;
}
V_308 -> V_219 = V_322 ;
V_309 -> V_219 = V_323 ;
V_34 = F_175 ( NULL , V_307 ,
& V_319 , V_308 , 0 , 0 ) ;
if ( V_34 < 0 )
goto V_91;
V_34 = F_175 ( NULL , V_316 ,
& V_191 , V_309 , 0 , 0 ) ;
if ( V_34 < 0 )
goto V_91;
}
if ( V_326 && ! V_324 ) {
V_34 = F_243 ( V_307 , V_308 , & V_322 ,
V_320 ,
V_326 != V_335 ,
& V_319 ) ;
if ( V_34 < 0 )
V_324 = V_336 ;
V_326 = 0 ;
}
if ( V_327 && ! V_325 ) {
V_34 = F_243 ( V_316 , V_309 , & V_323 ,
V_321 ,
V_327 != V_335 ,
& V_191 ) ;
if ( V_34 < 0 )
V_325 = V_336 ;
V_327 = 0 ;
}
if ( V_324 && V_325 ) {
V_34 = 0 ;
goto V_91;
} else if ( V_324 ) {
if ( V_323 == 0 ) {
V_34 = V_317 ( V_307 , V_316 ,
V_308 , V_309 ,
& V_191 ,
V_337 ,
V_318 ) ;
if ( V_34 < 0 )
goto V_91;
}
V_327 = V_336 ;
continue;
} else if ( V_325 ) {
if ( V_322 == 0 ) {
V_34 = V_317 ( V_307 , V_316 ,
V_308 , V_309 ,
& V_319 ,
V_338 ,
V_318 ) ;
if ( V_34 < 0 )
goto V_91;
}
V_326 = V_336 ;
continue;
}
if ( V_322 == 0 && V_323 == 0 ) {
V_311 = F_137 ( & V_319 , & V_191 ) ;
if ( V_311 < 0 ) {
V_34 = V_317 ( V_307 , V_316 ,
V_308 , V_309 ,
& V_319 ,
V_338 ,
V_318 ) ;
if ( V_34 < 0 )
goto V_91;
V_326 = V_336 ;
} else if ( V_311 > 0 ) {
V_34 = V_317 ( V_307 , V_316 ,
V_308 , V_309 ,
& V_191 ,
V_337 ,
V_318 ) ;
if ( V_34 < 0 )
goto V_91;
V_327 = V_336 ;
} else {
V_34 = F_244 ( V_307 , V_308 ,
V_309 , V_310 ) ;
if ( V_34 ) {
V_34 = V_317 ( V_307 , V_316 ,
V_308 , V_309 ,
& V_319 ,
V_339 ,
V_318 ) ;
if ( V_34 < 0 )
goto V_91;
}
V_326 = V_336 ;
V_327 = V_336 ;
}
} else if ( V_322 == V_323 ) {
V_311 = F_137 ( & V_319 , & V_191 ) ;
if ( V_311 < 0 ) {
V_326 = V_336 ;
} else if ( V_311 > 0 ) {
V_327 = V_336 ;
} else {
V_328 = F_78 (
V_308 -> V_8 [ V_322 ] ,
V_308 -> V_17 [ V_322 ] ) ;
V_329 = F_78 (
V_309 -> V_8 [ V_323 ] ,
V_309 -> V_17 [ V_323 ] ) ;
if ( V_328 == V_329 ) {
V_326 = V_335 ;
V_327 = V_335 ;
} else {
V_326 = V_336 ;
V_327 = V_336 ;
}
}
} else if ( V_322 < V_323 ) {
V_327 = V_336 ;
} else {
V_326 = V_336 ;
}
}
V_91:
F_8 ( V_308 ) ;
F_8 ( V_309 ) ;
F_68 ( V_310 ) ;
if ( V_29 ) {
if ( ! V_34 )
V_34 = F_250 ( V_29 , V_307 ) ;
else
F_250 ( V_29 , V_307 ) ;
}
return V_34 ;
}
int F_239 ( struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_145 * V_84 , int V_35 ,
int V_150 , T_2 V_303 )
{
int V_79 ;
struct V_14 * V_236 ;
F_31 ( ! V_2 -> V_210 ) ;
while ( V_35 < V_7 ) {
if ( ! V_2 -> V_8 [ V_35 ] )
return 1 ;
V_79 = V_2 -> V_17 [ V_35 ] + 1 ;
V_236 = V_2 -> V_8 [ V_35 ] ;
V_61:
if ( V_79 >= F_85 ( V_236 ) ) {
int V_34 ;
int V_340 ;
struct V_145 V_341 ;
if ( V_35 + 1 >= V_7 ||
! V_2 -> V_8 [ V_35 + 1 ] )
return 1 ;
if ( V_2 -> V_9 [ V_35 + 1 ] ) {
V_35 ++ ;
continue;
}
V_79 = F_85 ( V_236 ) - 1 ;
if ( V_35 == 0 )
F_211 ( V_236 , & V_341 , V_79 ) ;
else
F_240 ( V_236 , & V_341 , V_79 ) ;
V_340 = V_2 -> V_219 ;
F_9 ( V_2 ) ;
V_2 -> V_219 = V_35 ;
V_34 = F_175 ( NULL , V_19 , & V_341 , V_2 ,
0 , 0 ) ;
V_2 -> V_219 = V_340 ;
if ( V_34 < 0 )
return V_34 ;
V_236 = V_2 -> V_8 [ V_35 ] ;
V_79 = V_2 -> V_17 [ V_35 ] ;
if ( V_34 == 0 )
V_79 ++ ;
goto V_61;
}
if ( V_35 == 0 )
F_211 ( V_236 , V_84 , V_79 ) ;
else {
T_2 V_85 = F_78 ( V_236 , V_79 ) ;
T_2 V_153 = F_79 ( V_236 , V_79 ) ;
if ( V_150 ) {
struct V_14 * V_70 ;
V_70 = F_140 ( V_19 , V_85 ,
F_139 ( V_19 , V_35 - 1 ) ) ;
if ( ! V_70 ||
F_141 ( V_70 , V_153 , 1 ) <= 0 ) {
V_79 ++ ;
if ( V_70 )
F_12 ( V_70 ) ;
goto V_61;
}
F_12 ( V_70 ) ;
}
if ( V_153 < V_303 ) {
V_79 ++ ;
goto V_61;
}
F_240 ( V_236 , V_84 , V_79 ) ;
}
return 0 ;
}
return 1 ;
}
int F_182 ( struct V_18 * V_19 , struct V_1 * V_2 )
{
return F_252 ( V_19 , V_2 , 0 ) ;
}
int F_252 ( struct V_18 * V_19 , struct V_1 * V_2 ,
T_2 V_124 )
{
int V_79 ;
int V_35 ;
struct V_14 * V_236 ;
struct V_14 * V_61 ;
struct V_145 V_84 ;
T_4 V_94 ;
int V_34 ;
int V_342 = V_2 -> V_224 ;
int V_343 = 0 ;
V_94 = F_85 ( V_2 -> V_8 [ 0 ] ) ;
if ( V_94 == 0 )
return 1 ;
F_211 ( V_2 -> V_8 [ 0 ] , & V_84 , V_94 - 1 ) ;
V_216:
V_35 = 1 ;
V_61 = NULL ;
V_343 = 0 ;
F_9 ( V_2 ) ;
V_2 -> V_210 = 1 ;
V_2 -> V_224 = 1 ;
if ( V_124 )
V_34 = F_180 ( V_19 , & V_84 , V_2 , V_124 ) ;
else
V_34 = F_175 ( NULL , V_19 , & V_84 , V_2 , 0 , 0 ) ;
V_2 -> V_210 = 0 ;
if ( V_34 < 0 )
return V_34 ;
V_94 = F_85 ( V_2 -> V_8 [ 0 ] ) ;
if ( V_94 > 0 && V_2 -> V_17 [ 0 ] < V_94 - 1 ) {
if ( V_34 == 0 )
V_2 -> V_17 [ 0 ] ++ ;
V_34 = 0 ;
goto V_217;
}
while ( V_35 < V_7 ) {
if ( ! V_2 -> V_8 [ V_35 ] ) {
V_34 = 1 ;
goto V_217;
}
V_79 = V_2 -> V_17 [ V_35 ] + 1 ;
V_236 = V_2 -> V_8 [ V_35 ] ;
if ( V_79 >= F_85 ( V_236 ) ) {
V_35 ++ ;
if ( V_35 == V_7 ) {
V_34 = 1 ;
goto V_217;
}
continue;
}
if ( V_61 ) {
F_11 ( V_61 , V_343 ) ;
F_12 ( V_61 ) ;
}
V_61 = V_236 ;
V_343 = V_2 -> V_9 [ V_35 ] ;
V_34 = F_172 ( NULL , V_19 , V_2 , & V_61 , V_35 ,
V_79 , & V_84 , 0 ) ;
if ( V_34 == - V_203 )
goto V_216;
if ( V_34 < 0 ) {
F_9 ( V_2 ) ;
goto V_217;
}
if ( ! V_2 -> V_221 ) {
V_34 = F_177 ( V_61 ) ;
if ( ! V_34 && V_124 ) {
F_12 ( V_61 ) ;
F_9 ( V_2 ) ;
F_253 () ;
goto V_216;
}
if ( ! V_34 ) {
F_3 ( V_2 ) ;
F_23 ( V_61 ) ;
F_5 ( V_2 , V_61 ,
V_10 ) ;
}
V_343 = V_10 ;
}
break;
}
V_2 -> V_17 [ V_35 ] = V_79 ;
while ( 1 ) {
V_35 -- ;
V_236 = V_2 -> V_8 [ V_35 ] ;
if ( V_2 -> V_9 [ V_35 ] )
F_11 ( V_236 , V_2 -> V_9 [ V_35 ] ) ;
F_12 ( V_236 ) ;
V_2 -> V_8 [ V_35 ] = V_61 ;
V_2 -> V_17 [ V_35 ] = 0 ;
if ( ! V_2 -> V_221 )
V_2 -> V_9 [ V_35 ] = V_343 ;
if ( ! V_35 )
break;
V_34 = F_172 ( NULL , V_19 , V_2 , & V_61 , V_35 ,
0 , & V_84 , 0 ) ;
if ( V_34 == - V_203 )
goto V_216;
if ( V_34 < 0 ) {
F_9 ( V_2 ) ;
goto V_217;
}
if ( ! V_2 -> V_221 ) {
V_34 = F_177 ( V_61 ) ;
if ( ! V_34 ) {
F_3 ( V_2 ) ;
F_23 ( V_61 ) ;
F_5 ( V_2 , V_61 ,
V_10 ) ;
}
V_343 = V_10 ;
}
}
V_34 = 0 ;
V_217:
F_170 ( V_2 , 0 , 1 , 0 , NULL ) ;
V_2 -> V_224 = V_342 ;
if ( ! V_342 )
F_3 ( V_2 ) ;
return V_34 ;
}
int F_254 ( struct V_18 * V_19 ,
struct V_1 * V_2 , T_2 V_344 ,
int type )
{
struct V_145 V_296 ;
struct V_14 * V_163 ;
T_4 V_94 ;
int V_34 ;
while ( 1 ) {
if ( V_2 -> V_17 [ 0 ] == 0 ) {
F_3 ( V_2 ) ;
V_34 = F_183 ( V_19 , V_2 ) ;
if ( V_34 != 0 )
return V_34 ;
} else {
V_2 -> V_17 [ 0 ] -- ;
}
V_163 = V_2 -> V_8 [ 0 ] ;
V_94 = F_85 ( V_163 ) ;
if ( V_94 == 0 )
return 1 ;
if ( V_2 -> V_17 [ 0 ] == V_94 )
V_2 -> V_17 [ 0 ] -- ;
F_211 ( V_163 , & V_296 , V_2 -> V_17 [ 0 ] ) ;
if ( V_296 . V_117 < V_344 )
break;
if ( V_296 . type == type )
return 0 ;
if ( V_296 . V_117 == V_344 &&
V_296 . type < type )
break;
}
return 1 ;
}
