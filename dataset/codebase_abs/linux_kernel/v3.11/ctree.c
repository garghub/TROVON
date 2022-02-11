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
F_75 ( ! V_65 || ! V_65 -> V_52 ) ;
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
else {
F_73 ( V_65 ) ;
return - V_75 ;
}
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
if ( F_27 ( & V_23 -> V_58 ) ) {
F_56 ( V_23 ) ;
return 1 ;
}
return 0 ;
}
static inline int F_80 ( struct V_50 * V_23 , T_3 V_76 ,
struct V_64 * * V_77 )
{
struct V_64 * V_65 ;
V_65 = * V_77 = F_81 ( sizeof( * V_65 ) , V_78 ) ;
if ( ! V_65 )
return - V_79 ;
F_26 ( & V_23 -> V_56 ) ;
V_65 -> V_52 = F_61 ( V_23 ) ;
F_29 ( & V_23 -> V_56 ) ;
return V_65 -> V_52 ;
}
static inline int
F_82 ( struct V_50 * V_23 ,
struct V_14 * V_20 , int V_80 ,
enum V_81 V_82 , T_3 V_76 )
{
int V_34 ;
struct V_64 * V_65 ;
V_34 = F_80 ( V_23 , V_76 , & V_65 ) ;
if ( V_34 < 0 )
return V_34 ;
V_65 -> V_72 = V_20 -> V_43 >> V_83 ;
if ( V_82 != V_84 ) {
F_34 ( V_20 , & V_65 -> V_85 , V_80 ) ;
V_65 -> V_86 = F_83 ( V_20 , V_80 ) ;
}
V_65 -> V_82 = V_82 ;
V_65 -> V_80 = V_80 ;
V_65 -> V_87 = F_84 ( V_20 , V_80 ) ;
return F_74 ( V_23 , V_65 ) ;
}
static T_1 int
F_85 ( struct V_50 * V_23 ,
struct V_14 * V_20 , int V_80 ,
enum V_81 V_82 , T_3 V_76 )
{
int V_34 ;
if ( F_78 ( V_23 , V_20 ) )
return 0 ;
V_34 = F_82 ( V_23 , V_20 , V_80 , V_82 , V_76 ) ;
F_56 ( V_23 ) ;
return V_34 ;
}
static T_1 int
F_86 ( struct V_50 * V_23 , struct V_14 * V_20 ,
int V_80 , enum V_81 V_82 )
{
return F_85 ( V_23 , V_20 , V_80 , V_82 , V_4 ) ;
}
static T_1 int
F_87 ( struct V_50 * V_23 ,
struct V_14 * V_20 , int V_80 ,
enum V_81 V_82 )
{
return F_82 ( V_23 , V_20 , V_80 , V_82 , V_4 ) ;
}
static T_1 int
F_88 ( struct V_50 * V_23 ,
struct V_14 * V_20 , int V_88 , int V_89 ,
int V_90 , T_3 V_76 )
{
struct V_64 * V_65 ;
int V_34 ;
int V_6 ;
if ( F_78 ( V_23 , V_20 ) )
return 0 ;
for ( V_6 = 0 ; V_6 + V_88 < V_89 && V_6 < V_90 ; V_6 ++ ) {
V_34 = F_87 ( V_23 , V_20 , V_6 + V_88 ,
V_91 ) ;
F_75 ( V_34 < 0 ) ;
}
V_34 = F_80 ( V_23 , V_76 , & V_65 ) ;
if ( V_34 < 0 )
goto V_92;
V_65 -> V_72 = V_20 -> V_43 >> V_83 ;
V_65 -> V_80 = V_89 ;
V_65 -> V_93 . V_88 = V_88 ;
V_65 -> V_93 . V_90 = V_90 ;
V_65 -> V_82 = V_94 ;
V_34 = F_74 ( V_23 , V_65 ) ;
V_92:
F_56 ( V_23 ) ;
return V_34 ;
}
static inline void
F_89 ( struct V_50 * V_23 , struct V_14 * V_20 )
{
int V_6 ;
T_4 V_95 ;
int V_34 ;
if ( F_32 ( V_20 ) == 0 )
return;
V_95 = F_90 ( V_20 ) ;
for ( V_6 = V_95 - 1 ; V_6 >= 0 ; V_6 -- ) {
V_34 = F_87 ( V_23 , V_20 , V_6 ,
V_96 ) ;
F_75 ( V_34 < 0 ) ;
}
}
static T_1 int
F_91 ( struct V_50 * V_23 ,
struct V_14 * V_97 ,
struct V_14 * V_98 , T_3 V_76 ,
int V_99 )
{
struct V_64 * V_65 ;
int V_34 ;
if ( F_78 ( V_23 , NULL ) )
return 0 ;
if ( V_99 )
F_89 ( V_23 , V_97 ) ;
V_34 = F_80 ( V_23 , V_76 , & V_65 ) ;
if ( V_34 < 0 )
goto V_92;
V_65 -> V_72 = V_98 -> V_43 >> V_83 ;
V_65 -> V_97 . V_100 = V_97 -> V_43 ;
V_65 -> V_97 . V_35 = F_32 ( V_97 ) ;
V_65 -> V_87 = F_47 ( V_97 ) ;
V_65 -> V_82 = V_101 ;
V_34 = F_74 ( V_23 , V_65 ) ;
V_92:
F_56 ( V_23 ) ;
return V_34 ;
}
static struct V_64 *
F_92 ( struct V_50 * V_23 , T_2 V_43 , T_2 V_66 ,
int V_102 )
{
struct V_59 * V_60 ;
struct V_61 * V_21 ;
struct V_64 * V_71 = NULL ;
struct V_64 * V_103 = NULL ;
T_2 V_72 = V_43 >> V_83 ;
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
} else if ( ! V_102 ) {
if ( V_103 )
F_75 ( V_103 -> V_52 > V_71 -> V_52 ) ;
V_103 = V_71 ;
V_21 = V_21 -> V_73 ;
} else if ( V_71 -> V_52 > V_66 ) {
if ( V_103 )
F_75 ( V_103 -> V_52 < V_71 -> V_52 ) ;
V_103 = V_71 ;
V_21 = V_21 -> V_74 ;
} else {
V_103 = V_71 ;
break;
}
}
F_52 ( V_23 ) ;
return V_103 ;
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
static T_1 void
F_95 ( struct V_50 * V_23 , struct V_14 * V_104 ,
struct V_14 * V_105 , unsigned long V_106 ,
unsigned long V_107 , int V_90 )
{
int V_34 ;
int V_6 ;
if ( F_78 ( V_23 , NULL ) )
return;
if ( F_32 ( V_104 ) == 0 && F_32 ( V_105 ) == 0 ) {
F_56 ( V_23 ) ;
return;
}
for ( V_6 = 0 ; V_6 < V_90 ; V_6 ++ ) {
V_34 = F_87 ( V_23 , V_105 ,
V_6 + V_107 ,
V_108 ) ;
F_75 ( V_34 < 0 ) ;
V_34 = F_87 ( V_23 , V_104 ,
V_6 + V_106 ,
V_84 ) ;
F_75 ( V_34 < 0 ) ;
}
F_56 ( V_23 ) ;
}
static inline void
F_96 ( struct V_50 * V_23 , struct V_14 * V_104 ,
int V_106 , int V_107 , int V_90 )
{
int V_34 ;
V_34 = F_88 ( V_23 , V_104 , V_106 , V_107 ,
V_90 , V_4 ) ;
F_75 ( V_34 < 0 ) ;
}
static T_1 void
F_97 ( struct V_50 * V_23 ,
struct V_14 * V_20 , int V_80 , int V_109 )
{
int V_34 ;
V_34 = F_85 ( V_23 , V_20 , V_80 ,
V_110 ,
V_109 ? V_78 : V_4 ) ;
F_75 ( V_34 < 0 ) ;
}
static T_1 void
F_98 ( struct V_50 * V_23 , struct V_14 * V_20 )
{
if ( F_78 ( V_23 , V_20 ) )
return;
F_89 ( V_23 , V_20 ) ;
F_56 ( V_23 ) ;
}
static T_1 void
F_99 ( struct V_18 * V_19 ,
struct V_14 * V_111 ,
int V_99 )
{
int V_34 ;
V_34 = F_91 ( V_19 -> V_23 , V_19 -> V_21 ,
V_111 , V_4 , V_99 ) ;
F_75 ( V_34 < 0 ) ;
}
int F_100 ( struct V_18 * V_19 ,
struct V_14 * V_30 )
{
if ( V_19 -> V_38 &&
V_30 != V_19 -> V_21 && V_30 != V_19 -> V_112 &&
( F_47 ( V_30 ) <=
F_101 ( & V_19 -> V_113 ) ||
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
int * V_114 )
{
T_2 V_22 ;
T_2 V_115 ;
T_2 V_76 ;
T_2 V_116 = 0 ;
int V_34 ;
if ( F_100 ( V_19 , V_30 ) ) {
V_34 = F_106 ( V_29 , V_19 , V_30 -> V_43 ,
F_32 ( V_30 ) , 1 ,
& V_22 , & V_76 ) ;
if ( V_34 )
return V_34 ;
if ( V_22 == 0 ) {
V_34 = - V_117 ;
F_107 ( V_19 -> V_23 , V_34 ) ;
return V_34 ;
}
} else {
V_22 = 1 ;
if ( V_19 -> V_118 . V_119 == V_47 ||
F_104 ( V_30 ) < V_44 )
V_76 = V_120 ;
else
V_76 = 0 ;
}
V_115 = F_108 ( V_30 ) ;
F_75 ( V_115 == V_47 &&
! ( V_76 & V_120 ) ) ;
if ( V_22 > 1 ) {
if ( ( V_115 == V_19 -> V_118 . V_119 ||
V_19 -> V_118 . V_119 == V_47 ) &&
! ( V_76 & V_120 ) ) {
V_34 = F_48 ( V_29 , V_19 , V_30 , 1 , 1 ) ;
F_75 ( V_34 ) ;
if ( V_19 -> V_118 . V_119 ==
V_47 ) {
V_34 = F_109 ( V_29 , V_19 , V_30 , 0 , 1 ) ;
F_75 ( V_34 ) ;
V_34 = F_48 ( V_29 , V_19 , V_33 , 1 , 1 ) ;
F_75 ( V_34 ) ;
}
V_116 |= V_120 ;
} else {
if ( V_19 -> V_118 . V_119 ==
V_47 )
V_34 = F_48 ( V_29 , V_19 , V_33 , 1 , 1 ) ;
else
V_34 = F_48 ( V_29 , V_19 , V_33 , 0 , 1 ) ;
F_75 ( V_34 ) ;
}
if ( V_116 != 0 ) {
int V_35 = F_32 ( V_30 ) ;
V_34 = F_110 ( V_29 , V_19 ,
V_30 -> V_43 ,
V_30 -> V_42 ,
V_116 , V_35 , 0 ) ;
if ( V_34 )
return V_34 ;
}
} else {
if ( V_76 & V_120 ) {
if ( V_19 -> V_118 . V_119 ==
V_47 )
V_34 = F_48 ( V_29 , V_19 , V_33 , 1 , 1 ) ;
else
V_34 = F_48 ( V_29 , V_19 , V_33 , 0 , 1 ) ;
F_75 ( V_34 ) ;
V_34 = F_109 ( V_29 , V_19 , V_30 , 1 , 1 ) ;
F_75 ( V_34 ) ;
}
F_111 ( V_29 , V_19 , V_30 ) ;
* V_114 = 1 ;
}
return 0 ;
}
static T_1 int F_112 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_14 * V_30 ,
struct V_14 * V_70 , int V_121 ,
struct V_14 * * V_31 ,
T_2 V_122 , T_2 V_123 )
{
struct V_36 V_37 ;
struct V_14 * V_33 ;
int V_35 , V_34 ;
int V_114 = 0 ;
int V_124 = 0 ;
T_2 V_125 ;
if ( * V_31 == V_30 )
V_124 = 1 ;
F_113 ( V_30 ) ;
F_31 ( V_19 -> V_38 && V_29 -> V_39 !=
V_19 -> V_23 -> V_40 -> V_39 ) ;
F_31 ( V_19 -> V_38 && V_29 -> V_39 != V_19 -> V_41 ) ;
V_35 = F_32 ( V_30 ) ;
if ( V_35 == 0 )
F_33 ( V_30 , & V_37 , 0 ) ;
else
F_34 ( V_30 , & V_37 , 0 ) ;
if ( V_19 -> V_118 . V_119 == V_47 ) {
if ( V_70 )
V_125 = V_70 -> V_43 ;
else
V_125 = 0 ;
} else
V_125 = 0 ;
V_33 = F_35 ( V_29 , V_19 , V_30 -> V_42 , V_125 ,
V_19 -> V_118 . V_119 , & V_37 ,
V_35 , V_122 , V_123 ) ;
if ( F_36 ( V_33 ) )
return F_37 ( V_33 ) ;
F_38 ( V_33 , V_30 , 0 , 0 , V_33 -> V_42 ) ;
F_39 ( V_33 , V_33 -> V_43 ) ;
F_40 ( V_33 , V_29 -> V_39 ) ;
F_41 ( V_33 , V_44 ) ;
F_42 ( V_33 , V_45 |
V_46 ) ;
if ( V_19 -> V_118 . V_119 == V_47 )
F_43 ( V_33 , V_46 ) ;
else
F_44 ( V_33 , V_19 -> V_118 . V_119 ) ;
F_45 ( V_33 , V_19 -> V_23 -> V_48 ,
( unsigned long ) F_46 ( V_33 ) ,
V_49 ) ;
V_34 = F_105 ( V_29 , V_19 , V_30 , V_33 , & V_114 ) ;
if ( V_34 ) {
F_114 ( V_29 , V_19 , V_34 ) ;
return V_34 ;
}
if ( V_19 -> V_38 )
F_115 ( V_29 , V_19 , V_30 , V_33 ) ;
if ( V_30 == V_19 -> V_21 ) {
F_31 ( V_70 && V_70 != V_30 ) ;
if ( V_19 -> V_118 . V_119 == V_47 ||
F_104 ( V_30 ) < V_44 )
V_125 = V_30 -> V_43 ;
else
V_125 = 0 ;
F_116 ( V_33 ) ;
F_99 ( V_19 , V_33 , 1 ) ;
F_117 ( V_19 -> V_21 , V_33 ) ;
F_118 ( V_29 , V_19 , V_30 , V_125 ,
V_114 ) ;
F_12 ( V_30 ) ;
F_25 ( V_19 ) ;
} else {
if ( V_19 -> V_118 . V_119 == V_47 )
V_125 = V_70 -> V_43 ;
else
V_125 = 0 ;
F_31 ( V_29 -> V_39 != F_47 ( V_70 ) ) ;
F_86 ( V_19 -> V_23 , V_70 , V_121 ,
V_110 ) ;
F_119 ( V_70 , V_121 ,
V_33 -> V_43 ) ;
F_120 ( V_70 , V_121 ,
V_29 -> V_39 ) ;
F_49 ( V_70 ) ;
if ( V_114 )
F_98 ( V_19 -> V_23 , V_30 ) ;
F_118 ( V_29 , V_19 , V_30 , V_125 ,
V_114 ) ;
}
if ( V_124 )
F_21 ( V_30 ) ;
F_121 ( V_30 ) ;
F_49 ( V_33 ) ;
* V_31 = V_33 ;
return 0 ;
}
static struct V_64 *
F_122 ( struct V_50 * V_23 ,
struct V_14 * V_126 , T_2 V_127 )
{
struct V_64 * V_65 ;
struct V_64 * V_103 = NULL ;
T_2 V_128 = V_126 -> V_43 ;
int V_129 = 0 ;
if ( ! V_127 )
return 0 ;
while ( 1 ) {
V_65 = F_93 ( V_23 , V_128 ,
V_127 ) ;
if ( ! V_129 && ! V_65 )
return 0 ;
if ( ! V_65 )
break;
if ( V_65 -> V_82 != V_101 )
break;
V_103 = V_65 ;
V_128 = V_65 -> V_97 . V_100 ;
V_129 = 1 ;
}
if ( ! V_103 )
V_103 = V_65 ;
return V_103 ;
}
static void
F_123 ( struct V_50 * V_23 , struct V_14 * V_20 ,
T_2 V_127 , struct V_64 * V_130 )
{
T_4 V_131 ;
struct V_61 * V_62 ;
struct V_64 * V_65 = V_130 ;
unsigned long V_132 ;
unsigned long V_133 ;
unsigned long V_134 = sizeof( struct V_135 ) ;
V_131 = F_90 ( V_20 ) ;
F_50 ( V_23 ) ;
while ( V_65 && V_65 -> V_52 >= V_127 ) {
switch ( V_65 -> V_82 ) {
case V_96 :
F_75 ( V_65 -> V_80 < V_131 ) ;
case V_91 :
case V_108 :
F_124 ( V_20 , & V_65 -> V_85 , V_65 -> V_80 ) ;
F_119 ( V_20 , V_65 -> V_80 , V_65 -> V_86 ) ;
F_120 ( V_20 , V_65 -> V_80 ,
V_65 -> V_87 ) ;
V_131 ++ ;
break;
case V_110 :
F_75 ( V_65 -> V_80 >= V_131 ) ;
F_124 ( V_20 , & V_65 -> V_85 , V_65 -> V_80 ) ;
F_119 ( V_20 , V_65 -> V_80 , V_65 -> V_86 ) ;
F_120 ( V_20 , V_65 -> V_80 ,
V_65 -> V_87 ) ;
break;
case V_84 :
V_131 -- ;
break;
case V_94 :
V_132 = F_125 ( V_65 -> V_80 ) ;
V_133 = F_125 ( V_65 -> V_93 . V_88 ) ;
F_126 ( V_20 , V_132 , V_133 ,
V_65 -> V_93 . V_90 * V_134 ) ;
break;
case V_101 :
break;
}
V_62 = F_70 ( & V_65 -> V_21 ) ;
if ( ! V_62 )
break;
V_65 = F_71 ( V_62 , struct V_64 , V_21 ) ;
if ( V_65 -> V_72 != V_130 -> V_72 )
break;
}
F_52 ( V_23 ) ;
F_127 ( V_20 , V_131 ) ;
}
static struct V_14 *
F_128 ( struct V_50 * V_23 , struct V_14 * V_20 ,
T_2 V_127 )
{
struct V_14 * V_136 ;
struct V_64 * V_65 ;
if ( ! V_127 )
return V_20 ;
if ( F_32 ( V_20 ) == 0 )
return V_20 ;
V_65 = F_94 ( V_23 , V_20 -> V_43 , V_127 ) ;
if ( ! V_65 )
return V_20 ;
if ( V_65 -> V_82 == V_96 ) {
F_75 ( V_65 -> V_80 != 0 ) ;
V_136 = F_129 ( V_20 -> V_43 ,
V_23 -> V_137 -> V_138 ) ;
F_75 ( ! V_136 ) ;
F_39 ( V_136 , V_20 -> V_43 ) ;
F_41 ( V_136 ,
F_104 ( V_20 ) ) ;
F_44 ( V_136 , F_108 ( V_20 ) ) ;
F_130 ( V_136 , F_32 ( V_20 ) ) ;
} else {
V_136 = F_131 ( V_20 ) ;
F_75 ( ! V_136 ) ;
}
F_24 ( V_20 ) ;
F_12 ( V_20 ) ;
F_116 ( V_136 ) ;
F_23 ( V_136 ) ;
F_123 ( V_23 , V_136 , V_127 , V_65 ) ;
F_31 ( F_90 ( V_136 ) >
F_132 ( V_23 -> V_137 ) ) ;
return V_136 ;
}
static inline struct V_14 *
F_133 ( struct V_18 * V_19 , T_2 V_127 )
{
struct V_64 * V_65 ;
struct V_14 * V_20 = NULL ;
struct V_14 * V_126 ;
struct V_14 * V_139 ;
struct V_140 * V_97 = NULL ;
T_2 V_141 = 0 ;
T_2 V_100 ;
T_4 V_142 ;
V_126 = F_22 ( V_19 ) ;
V_65 = F_122 ( V_19 -> V_23 , V_126 , V_127 ) ;
if ( ! V_65 )
return V_126 ;
if ( V_65 -> V_82 == V_101 ) {
V_97 = & V_65 -> V_97 ;
V_141 = V_65 -> V_87 ;
V_100 = V_97 -> V_100 ;
} else {
V_100 = V_126 -> V_43 ;
}
V_65 = F_94 ( V_19 -> V_23 , V_100 , V_127 ) ;
if ( V_97 && V_65 && V_65 -> V_82 != V_96 ) {
F_24 ( V_126 ) ;
F_12 ( V_126 ) ;
V_142 = F_134 ( V_19 , V_97 -> V_35 ) ;
V_139 = F_135 ( V_19 , V_100 , V_142 , 0 ) ;
if ( ! V_139 || ! F_136 ( V_139 ) ) {
F_12 ( V_139 ) ;
F_137 ( L_1 ,
V_100 ) ;
F_31 ( 1 ) ;
} else {
V_20 = F_131 ( V_139 ) ;
F_12 ( V_139 ) ;
}
} else if ( V_97 ) {
F_24 ( V_126 ) ;
F_12 ( V_126 ) ;
V_20 = F_129 ( V_100 , V_19 -> V_138 ) ;
} else {
V_20 = F_131 ( V_126 ) ;
F_24 ( V_126 ) ;
F_12 ( V_126 ) ;
}
if ( ! V_20 )
return NULL ;
F_116 ( V_20 ) ;
F_23 ( V_20 ) ;
if ( V_97 ) {
F_39 ( V_20 , V_20 -> V_43 ) ;
F_41 ( V_20 , V_44 ) ;
F_44 ( V_20 , F_108 ( V_126 ) ) ;
F_130 ( V_20 , V_97 -> V_35 ) ;
F_40 ( V_20 , V_141 ) ;
}
if ( V_65 )
F_123 ( V_19 -> V_23 , V_20 , V_127 , V_65 ) ;
else
F_31 ( F_32 ( V_20 ) != 0 ) ;
F_31 ( F_90 ( V_20 ) > F_132 ( V_19 ) ) ;
return V_20 ;
}
int F_138 ( struct V_18 * V_19 , T_2 V_127 )
{
struct V_64 * V_65 ;
int V_35 ;
struct V_14 * V_126 = F_13 ( V_19 ) ;
V_65 = F_122 ( V_19 -> V_23 , V_126 , V_127 ) ;
if ( V_65 && V_65 -> V_82 == V_101 ) {
V_35 = V_65 -> V_97 . V_35 ;
} else {
V_35 = F_32 ( V_126 ) ;
}
F_12 ( V_126 ) ;
return V_35 ;
}
static inline int F_139 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_14 * V_30 )
{
F_140 () ;
if ( F_47 ( V_30 ) == V_29 -> V_39 &&
! F_102 ( V_30 , V_45 ) &&
! ( V_19 -> V_118 . V_119 != V_47 &&
F_102 ( V_30 , V_46 ) ) &&
! V_19 -> V_143 )
return 0 ;
return 1 ;
}
T_1 int F_141 ( struct V_28 * V_29 ,
struct V_18 * V_19 , struct V_14 * V_30 ,
struct V_14 * V_70 , int V_121 ,
struct V_14 * * V_31 )
{
T_2 V_122 ;
int V_34 ;
if ( V_29 -> V_144 != V_19 -> V_23 -> V_40 )
F_142 ( 1 , V_145 L_2 ,
( unsigned long long ) V_29 -> V_39 ,
( unsigned long long )
V_19 -> V_23 -> V_40 -> V_39 ) ;
if ( V_29 -> V_39 != V_19 -> V_23 -> V_87 )
F_142 ( 1 , V_145 L_2 ,
( unsigned long long ) V_29 -> V_39 ,
( unsigned long long ) V_19 -> V_23 -> V_87 ) ;
if ( ! F_139 ( V_29 , V_19 , V_30 ) ) {
* V_31 = V_30 ;
return 0 ;
}
V_122 = V_30 -> V_43 & ~ ( ( T_2 ) ( 1024 * 1024 * 1024 ) - 1 ) ;
if ( V_70 )
F_143 ( V_70 ) ;
F_143 ( V_30 ) ;
V_34 = F_112 ( V_29 , V_19 , V_30 , V_70 ,
V_121 , V_31 , V_122 , 0 ) ;
F_144 ( V_19 , V_30 , * V_31 ) ;
return V_34 ;
}
static int F_145 ( T_2 V_146 , T_2 V_147 , T_4 V_142 )
{
if ( V_146 < V_147 && V_147 - ( V_146 + V_142 ) < 32768 )
return 1 ;
if ( V_146 > V_147 && V_146 - ( V_147 + V_142 ) < 32768 )
return 1 ;
return 0 ;
}
static int F_146 ( struct V_36 * V_148 , struct V_149 * V_150 )
{
struct V_149 V_151 ;
F_147 ( & V_151 , V_148 ) ;
return F_148 ( & V_151 , V_150 ) ;
}
int F_148 ( struct V_149 * V_151 , struct V_149 * V_150 )
{
if ( V_151 -> V_119 > V_150 -> V_119 )
return 1 ;
if ( V_151 -> V_119 < V_150 -> V_119 )
return - 1 ;
if ( V_151 -> type > V_150 -> type )
return 1 ;
if ( V_151 -> type < V_150 -> type )
return - 1 ;
if ( V_151 -> V_152 > V_150 -> V_152 )
return 1 ;
if ( V_151 -> V_152 < V_150 -> V_152 )
return - 1 ;
return 0 ;
}
int F_149 ( struct V_28 * V_29 ,
struct V_18 * V_19 , struct V_14 * V_70 ,
int V_153 , T_2 * V_154 ,
struct V_149 * V_155 )
{
struct V_14 * V_71 ;
T_2 V_146 ;
T_2 V_156 ;
T_2 V_122 = * V_154 ;
T_2 V_157 = 0 ;
T_2 V_147 ;
T_4 V_158 ;
int V_159 ;
int V_6 ;
int V_160 = 0 ;
int V_161 ;
int V_162 ;
T_4 V_142 ;
int V_163 = 0 ;
struct V_36 V_37 ;
V_161 = F_32 ( V_70 ) ;
F_31 ( V_29 -> V_144 != V_19 -> V_23 -> V_40 ) ;
F_31 ( V_29 -> V_39 != V_19 -> V_23 -> V_87 ) ;
V_158 = F_90 ( V_70 ) ;
V_142 = F_134 ( V_19 , V_161 - 1 ) ;
V_159 = V_158 ;
if ( V_158 == 1 )
return 0 ;
F_143 ( V_70 ) ;
for ( V_6 = V_153 ; V_6 < V_159 ; V_6 ++ ) {
int V_164 = 1 ;
F_34 ( V_70 , & V_37 , V_6 ) ;
if ( ! V_163 && F_146 ( & V_37 , V_155 ) < 0 )
continue;
V_163 = 1 ;
V_146 = F_83 ( V_70 , V_6 ) ;
V_156 = F_84 ( V_70 , V_6 ) ;
if ( V_157 == 0 )
V_157 = V_146 ;
if ( V_6 > 0 ) {
V_147 = F_83 ( V_70 , V_6 - 1 ) ;
V_164 = F_145 ( V_146 , V_147 , V_142 ) ;
}
if ( ! V_164 && V_6 < V_159 - 2 ) {
V_147 = F_83 ( V_70 , V_6 + 1 ) ;
V_164 = F_145 ( V_146 , V_147 , V_142 ) ;
}
if ( V_164 ) {
V_157 = V_146 ;
continue;
}
V_71 = F_150 ( V_19 , V_146 , V_142 ) ;
if ( V_71 )
V_162 = F_151 ( V_71 , V_156 , 0 ) ;
else
V_162 = 0 ;
if ( ! V_71 || ! V_162 ) {
if ( ! V_71 ) {
V_71 = F_135 ( V_19 , V_146 ,
V_142 , V_156 ) ;
if ( ! V_71 || ! F_136 ( V_71 ) ) {
F_12 ( V_71 ) ;
return - V_165 ;
}
} else if ( ! V_162 ) {
V_160 = F_152 ( V_71 , V_156 ) ;
if ( V_160 ) {
F_12 ( V_71 ) ;
return V_160 ;
}
}
}
if ( V_122 == 0 )
V_122 = V_157 ;
F_20 ( V_71 ) ;
F_143 ( V_71 ) ;
V_160 = F_112 ( V_29 , V_19 , V_71 , V_70 , V_6 ,
& V_71 , V_122 ,
F_153 ( 16 * V_142 ,
( V_159 - V_6 ) * V_142 ) ) ;
if ( V_160 ) {
F_21 ( V_71 ) ;
F_12 ( V_71 ) ;
break;
}
V_122 = V_71 -> V_43 ;
V_157 = V_71 -> V_43 ;
* V_154 = V_122 ;
F_21 ( V_71 ) ;
F_12 ( V_71 ) ;
}
return V_160 ;
}
static inline unsigned int F_154 ( struct V_18 * V_19 ,
struct V_14 * V_166 )
{
T_4 V_167 = F_90 ( V_166 ) ;
if ( V_167 == 0 )
return F_155 ( V_19 ) ;
return F_156 ( V_166 , V_167 - 1 ) ;
}
static T_1 int F_157 ( struct V_14 * V_20 ,
unsigned long V_5 ,
int V_168 , struct V_149 * V_85 ,
int V_169 , int * V_80 )
{
int V_170 = 0 ;
int V_171 = V_169 ;
int V_172 ;
int V_34 ;
struct V_36 * V_173 = NULL ;
struct V_36 V_174 ;
unsigned long V_152 ;
char * V_175 = NULL ;
unsigned long V_176 = 0 ;
unsigned long V_177 = 0 ;
int V_160 ;
while ( V_170 < V_171 ) {
V_172 = ( V_170 + V_171 ) / 2 ;
V_152 = V_5 + V_172 * V_168 ;
if ( ! V_175 || V_152 < V_176 ||
( V_152 + sizeof( struct V_36 ) ) >
V_176 + V_177 ) {
V_160 = F_158 ( V_20 , V_152 ,
sizeof( struct V_36 ) ,
& V_175 , & V_176 , & V_177 ) ;
if ( ! V_160 ) {
V_173 = (struct V_36 * ) ( V_175 + V_152 -
V_176 ) ;
} else {
F_159 ( V_20 , & V_174 ,
V_152 , sizeof( V_174 ) ) ;
V_173 = & V_174 ;
}
} else {
V_173 = (struct V_36 * ) ( V_175 + V_152 -
V_176 ) ;
}
V_34 = F_146 ( V_173 , V_85 ) ;
if ( V_34 < 0 )
V_170 = V_172 + 1 ;
else if ( V_34 > 0 )
V_171 = V_172 ;
else {
* V_80 = V_172 ;
return 0 ;
}
}
* V_80 = V_170 ;
return 1 ;
}
static int F_160 ( struct V_14 * V_20 , struct V_149 * V_85 ,
int V_35 , int * V_80 )
{
if ( V_35 == 0 )
return F_157 ( V_20 ,
F_161 ( struct V_178 , V_179 ) ,
sizeof( struct V_180 ) ,
V_85 , F_90 ( V_20 ) ,
V_80 ) ;
else
return F_157 ( V_20 ,
F_161 ( struct V_181 , V_182 ) ,
sizeof( struct V_135 ) ,
V_85 , F_90 ( V_20 ) ,
V_80 ) ;
}
int F_162 ( struct V_14 * V_20 , struct V_149 * V_85 ,
int V_35 , int * V_80 )
{
return F_160 ( V_20 , V_85 , V_35 , V_80 ) ;
}
static void F_163 ( struct V_18 * V_19 , T_4 V_183 )
{
F_26 ( & V_19 -> V_184 ) ;
F_164 ( & V_19 -> V_113 ,
F_165 ( & V_19 -> V_113 ) + V_183 ) ;
F_29 ( & V_19 -> V_184 ) ;
}
static void F_166 ( struct V_18 * V_19 , T_4 V_183 )
{
F_26 ( & V_19 -> V_184 ) ;
F_164 ( & V_19 -> V_113 ,
F_165 ( & V_19 -> V_113 ) - V_183 ) ;
F_29 ( & V_19 -> V_184 ) ;
}
T_1 int F_167 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_35 )
{
struct V_14 * V_185 = NULL ;
struct V_14 * V_172 ;
struct V_14 * V_186 = NULL ;
struct V_14 * V_70 = NULL ;
int V_34 = 0 ;
int V_187 ;
int V_188 ;
int V_189 = V_2 -> V_17 [ V_35 ] ;
T_2 V_190 ;
if ( V_35 == 0 )
return 0 ;
V_172 = V_2 -> V_8 [ V_35 ] ;
F_31 ( V_2 -> V_9 [ V_35 ] != V_12 &&
V_2 -> V_9 [ V_35 ] != V_13 ) ;
F_31 ( F_47 ( V_172 ) != V_29 -> V_39 ) ;
V_190 = F_83 ( V_172 , V_189 ) ;
if ( V_35 < V_7 - 1 ) {
V_70 = V_2 -> V_8 [ V_35 + 1 ] ;
V_188 = V_2 -> V_17 [ V_35 + 1 ] ;
}
if ( ! V_70 ) {
struct V_14 * V_191 ;
if ( F_90 ( V_172 ) != 1 )
return 0 ;
V_191 = F_168 ( V_19 , V_172 , 0 ) ;
if ( ! V_191 ) {
V_34 = - V_117 ;
F_107 ( V_19 -> V_23 , V_34 ) ;
goto V_192;
}
F_20 ( V_191 ) ;
F_143 ( V_191 ) ;
V_34 = F_141 ( V_29 , V_19 , V_191 , V_172 , 0 , & V_191 ) ;
if ( V_34 ) {
F_21 ( V_191 ) ;
F_12 ( V_191 ) ;
goto V_192;
}
F_99 ( V_19 , V_191 , 1 ) ;
F_117 ( V_19 -> V_21 , V_191 ) ;
F_25 ( V_19 ) ;
F_21 ( V_191 ) ;
V_2 -> V_9 [ V_35 ] = 0 ;
V_2 -> V_8 [ V_35 ] = NULL ;
F_111 ( V_29 , V_19 , V_172 ) ;
F_21 ( V_172 ) ;
F_12 ( V_172 ) ;
F_166 ( V_19 , V_172 -> V_42 ) ;
F_118 ( V_29 , V_19 , V_172 , 0 , 1 ) ;
F_121 ( V_172 ) ;
return 0 ;
}
if ( F_90 ( V_172 ) >
F_132 ( V_19 ) / 4 )
return 0 ;
V_186 = F_168 ( V_19 , V_70 , V_188 - 1 ) ;
if ( V_186 ) {
F_20 ( V_186 ) ;
F_143 ( V_186 ) ;
V_187 = F_141 ( V_29 , V_19 , V_186 ,
V_70 , V_188 - 1 , & V_186 ) ;
if ( V_187 ) {
V_34 = V_187 ;
goto V_192;
}
}
V_185 = F_168 ( V_19 , V_70 , V_188 + 1 ) ;
if ( V_185 ) {
F_20 ( V_185 ) ;
F_143 ( V_185 ) ;
V_187 = F_141 ( V_29 , V_19 , V_185 ,
V_70 , V_188 + 1 , & V_185 ) ;
if ( V_187 ) {
V_34 = V_187 ;
goto V_192;
}
}
if ( V_186 ) {
V_189 += F_90 ( V_186 ) ;
V_187 = F_169 ( V_29 , V_19 , V_186 , V_172 , 1 ) ;
if ( V_187 < 0 )
V_34 = V_187 ;
}
if ( V_185 ) {
V_187 = F_169 ( V_29 , V_19 , V_172 , V_185 , 1 ) ;
if ( V_187 < 0 && V_187 != - V_193 )
V_34 = V_187 ;
if ( F_90 ( V_185 ) == 0 ) {
F_111 ( V_29 , V_19 , V_185 ) ;
F_21 ( V_185 ) ;
F_170 ( V_19 , V_2 , V_35 + 1 , V_188 + 1 ) ;
F_166 ( V_19 , V_185 -> V_42 ) ;
F_118 ( V_29 , V_19 , V_185 , 0 , 1 ) ;
F_121 ( V_185 ) ;
V_185 = NULL ;
} else {
struct V_36 V_194 ;
F_34 ( V_185 , & V_194 , 0 ) ;
F_97 ( V_19 -> V_23 , V_70 ,
V_188 + 1 , 0 ) ;
F_124 ( V_70 , & V_194 , V_188 + 1 ) ;
F_49 ( V_70 ) ;
}
}
if ( F_90 ( V_172 ) == 1 ) {
if ( ! V_186 ) {
V_34 = - V_117 ;
F_107 ( V_19 -> V_23 , V_34 ) ;
goto V_192;
}
V_187 = F_171 ( V_29 , V_19 , V_172 , V_186 ) ;
if ( V_187 < 0 ) {
V_34 = V_187 ;
goto V_192;
}
if ( V_187 == 1 ) {
V_187 = F_169 ( V_29 , V_19 , V_186 , V_172 , 1 ) ;
if ( V_187 < 0 )
V_34 = V_187 ;
}
F_75 ( V_187 == 1 ) ;
}
if ( F_90 ( V_172 ) == 0 ) {
F_111 ( V_29 , V_19 , V_172 ) ;
F_21 ( V_172 ) ;
F_170 ( V_19 , V_2 , V_35 + 1 , V_188 ) ;
F_166 ( V_19 , V_172 -> V_42 ) ;
F_118 ( V_29 , V_19 , V_172 , 0 , 1 ) ;
F_121 ( V_172 ) ;
V_172 = NULL ;
} else {
struct V_36 V_195 ;
F_34 ( V_172 , & V_195 , 0 ) ;
F_97 ( V_19 -> V_23 , V_70 ,
V_188 , 0 ) ;
F_124 ( V_70 , & V_195 , V_188 ) ;
F_49 ( V_70 ) ;
}
if ( V_186 ) {
if ( F_90 ( V_186 ) > V_189 ) {
F_116 ( V_186 ) ;
V_2 -> V_8 [ V_35 ] = V_186 ;
V_2 -> V_17 [ V_35 + 1 ] -= 1 ;
V_2 -> V_17 [ V_35 ] = V_189 ;
if ( V_172 ) {
F_21 ( V_172 ) ;
F_12 ( V_172 ) ;
}
} else {
V_189 -= F_90 ( V_186 ) ;
V_2 -> V_17 [ V_35 ] = V_189 ;
}
}
if ( V_190 !=
F_83 ( V_2 -> V_8 [ V_35 ] , V_2 -> V_17 [ V_35 ] ) )
F_172 () ;
V_192:
if ( V_185 ) {
F_21 ( V_185 ) ;
F_12 ( V_185 ) ;
}
if ( V_186 ) {
if ( V_2 -> V_8 [ V_35 ] != V_186 )
F_21 ( V_186 ) ;
F_12 ( V_186 ) ;
}
return V_34 ;
}
static T_1 int F_173 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_35 )
{
struct V_14 * V_185 = NULL ;
struct V_14 * V_172 ;
struct V_14 * V_186 = NULL ;
struct V_14 * V_70 = NULL ;
int V_34 = 0 ;
int V_187 ;
int V_188 ;
int V_189 = V_2 -> V_17 [ V_35 ] ;
if ( V_35 == 0 )
return 1 ;
V_172 = V_2 -> V_8 [ V_35 ] ;
F_31 ( F_47 ( V_172 ) != V_29 -> V_39 ) ;
if ( V_35 < V_7 - 1 ) {
V_70 = V_2 -> V_8 [ V_35 + 1 ] ;
V_188 = V_2 -> V_17 [ V_35 + 1 ] ;
}
if ( ! V_70 )
return 1 ;
V_186 = F_168 ( V_19 , V_70 , V_188 - 1 ) ;
if ( V_186 ) {
T_4 V_196 ;
F_20 ( V_186 ) ;
F_143 ( V_186 ) ;
V_196 = F_90 ( V_186 ) ;
if ( V_196 >= F_132 ( V_19 ) - 1 ) {
V_187 = 1 ;
} else {
V_34 = F_141 ( V_29 , V_19 , V_186 , V_70 ,
V_188 - 1 , & V_186 ) ;
if ( V_34 )
V_187 = 1 ;
else {
V_187 = F_169 ( V_29 , V_19 ,
V_186 , V_172 , 0 ) ;
}
}
if ( V_187 < 0 )
V_34 = V_187 ;
if ( V_187 == 0 ) {
struct V_36 V_37 ;
V_189 += V_196 ;
F_34 ( V_172 , & V_37 , 0 ) ;
F_97 ( V_19 -> V_23 , V_70 ,
V_188 , 0 ) ;
F_124 ( V_70 , & V_37 , V_188 ) ;
F_49 ( V_70 ) ;
if ( F_90 ( V_186 ) > V_189 ) {
V_2 -> V_8 [ V_35 ] = V_186 ;
V_2 -> V_17 [ V_35 + 1 ] -= 1 ;
V_2 -> V_17 [ V_35 ] = V_189 ;
F_21 ( V_172 ) ;
F_12 ( V_172 ) ;
} else {
V_189 -=
F_90 ( V_186 ) ;
V_2 -> V_17 [ V_35 ] = V_189 ;
F_21 ( V_186 ) ;
F_12 ( V_186 ) ;
}
return 0 ;
}
F_21 ( V_186 ) ;
F_12 ( V_186 ) ;
}
V_185 = F_168 ( V_19 , V_70 , V_188 + 1 ) ;
if ( V_185 ) {
T_4 V_197 ;
F_20 ( V_185 ) ;
F_143 ( V_185 ) ;
V_197 = F_90 ( V_185 ) ;
if ( V_197 >= F_132 ( V_19 ) - 1 ) {
V_187 = 1 ;
} else {
V_34 = F_141 ( V_29 , V_19 , V_185 ,
V_70 , V_188 + 1 ,
& V_185 ) ;
if ( V_34 )
V_187 = 1 ;
else {
V_187 = F_171 ( V_29 , V_19 ,
V_185 , V_172 ) ;
}
}
if ( V_187 < 0 )
V_34 = V_187 ;
if ( V_187 == 0 ) {
struct V_36 V_37 ;
F_34 ( V_185 , & V_37 , 0 ) ;
F_97 ( V_19 -> V_23 , V_70 ,
V_188 + 1 , 0 ) ;
F_124 ( V_70 , & V_37 , V_188 + 1 ) ;
F_49 ( V_70 ) ;
if ( F_90 ( V_172 ) <= V_189 ) {
V_2 -> V_8 [ V_35 ] = V_185 ;
V_2 -> V_17 [ V_35 + 1 ] += 1 ;
V_2 -> V_17 [ V_35 ] = V_189 -
F_90 ( V_172 ) ;
F_21 ( V_172 ) ;
F_12 ( V_172 ) ;
} else {
F_21 ( V_185 ) ;
F_12 ( V_185 ) ;
}
return 0 ;
}
F_21 ( V_185 ) ;
F_12 ( V_185 ) ;
}
return 1 ;
}
static void F_174 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int V_35 , int V_80 , T_2 V_119 )
{
struct V_14 * V_21 ;
struct V_36 V_37 ;
T_4 V_95 ;
T_2 V_198 ;
T_2 V_199 ;
T_2 V_200 = 0 ;
T_2 V_156 ;
int V_201 = V_2 -> V_202 ;
struct V_14 * V_20 ;
T_4 V_167 ;
T_4 V_142 ;
T_4 V_203 = 0 ;
if ( V_35 != 1 )
return;
if ( ! V_2 -> V_8 [ V_35 ] )
return;
V_21 = V_2 -> V_8 [ V_35 ] ;
V_198 = F_83 ( V_21 , V_80 ) ;
V_142 = F_134 ( V_19 , V_35 - 1 ) ;
V_20 = F_150 ( V_19 , V_198 , V_142 ) ;
if ( V_20 ) {
F_12 ( V_20 ) ;
return;
}
V_199 = V_198 ;
V_95 = F_90 ( V_21 ) ;
V_167 = V_80 ;
while ( 1 ) {
if ( V_201 < 0 ) {
if ( V_167 == 0 )
break;
V_167 -- ;
} else if ( V_201 > 0 ) {
V_167 ++ ;
if ( V_167 >= V_95 )
break;
}
if ( V_2 -> V_202 < 0 && V_119 ) {
F_34 ( V_21 , & V_37 , V_167 ) ;
if ( F_175 ( & V_37 ) != V_119 )
break;
}
V_198 = F_83 ( V_21 , V_167 ) ;
if ( ( V_198 <= V_199 && V_199 - V_198 <= 65536 ) ||
( V_198 > V_199 && V_198 - V_199 <= 65536 ) ) {
V_156 = F_84 ( V_21 , V_167 ) ;
F_176 ( V_19 , V_198 , V_142 , V_156 ) ;
V_200 += V_142 ;
}
V_203 ++ ;
if ( ( V_200 > 65536 || V_203 > 32 ) )
break;
}
}
static T_1 void F_177 ( struct V_18 * V_19 ,
struct V_1 * V_2 , int V_35 )
{
int V_80 ;
int V_95 ;
struct V_14 * V_70 ;
struct V_14 * V_20 ;
T_2 V_156 ;
T_2 V_204 = 0 ;
T_2 V_205 = 0 ;
int V_142 ;
V_70 = V_2 -> V_8 [ V_35 + 1 ] ;
if ( ! V_70 )
return;
V_95 = F_90 ( V_70 ) ;
V_80 = V_2 -> V_17 [ V_35 + 1 ] ;
V_142 = F_134 ( V_19 , V_35 ) ;
if ( V_80 > 0 ) {
V_204 = F_83 ( V_70 , V_80 - 1 ) ;
V_156 = F_84 ( V_70 , V_80 - 1 ) ;
V_20 = F_150 ( V_19 , V_204 , V_142 ) ;
if ( V_20 && F_151 ( V_20 , V_156 , 1 ) != 0 )
V_204 = 0 ;
F_12 ( V_20 ) ;
}
if ( V_80 + 1 < V_95 ) {
V_205 = F_83 ( V_70 , V_80 + 1 ) ;
V_156 = F_84 ( V_70 , V_80 + 1 ) ;
V_20 = F_150 ( V_19 , V_205 , V_142 ) ;
if ( V_20 && F_151 ( V_20 , V_156 , 1 ) != 0 )
V_205 = 0 ;
F_12 ( V_20 ) ;
}
if ( V_204 )
F_176 ( V_19 , V_204 , V_142 , 0 ) ;
if ( V_205 )
F_176 ( V_19 , V_205 , V_142 , 0 ) ;
}
static T_1 void F_178 ( struct V_1 * V_2 , int V_35 ,
int V_206 , int V_207 ,
int * V_208 )
{
int V_6 ;
int V_209 = V_35 ;
int V_210 = 0 ;
struct V_14 * V_211 ;
for ( V_6 = V_35 ; V_6 < V_7 ; V_6 ++ ) {
if ( ! V_2 -> V_8 [ V_6 ] )
break;
if ( ! V_2 -> V_9 [ V_6 ] )
break;
if ( ! V_210 && V_2 -> V_17 [ V_6 ] == 0 ) {
V_209 = V_6 + 1 ;
continue;
}
if ( ! V_210 && V_2 -> V_212 ) {
T_4 V_95 ;
V_211 = V_2 -> V_8 [ V_6 ] ;
V_95 = F_90 ( V_211 ) ;
if ( V_95 < 1 || V_2 -> V_17 [ V_6 ] >= V_95 - 1 ) {
V_209 = V_6 + 1 ;
continue;
}
}
if ( V_209 < V_6 && V_6 >= V_206 )
V_210 = 1 ;
V_211 = V_2 -> V_8 [ V_6 ] ;
if ( V_6 >= V_206 && V_6 > V_209 && V_2 -> V_9 [ V_6 ] ) {
F_11 ( V_211 , V_2 -> V_9 [ V_6 ] ) ;
V_2 -> V_9 [ V_6 ] = 0 ;
if ( V_208 &&
V_6 > V_207 &&
V_6 <= * V_208 ) {
* V_208 = V_6 - 1 ;
}
}
}
}
T_1 void F_179 ( struct V_1 * V_2 , int V_35 )
{
int V_6 ;
if ( V_2 -> V_212 )
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
F_180 ( struct V_28 * V_29 ,
struct V_18 * V_19 , struct V_1 * V_5 ,
struct V_14 * * V_213 , int V_35 , int V_80 ,
struct V_149 * V_85 , T_2 V_127 )
{
T_2 V_146 ;
T_2 V_156 ;
T_4 V_142 ;
struct V_14 * V_214 = * V_213 ;
struct V_14 * V_173 ;
int V_34 ;
V_146 = F_83 ( V_214 , V_80 ) ;
V_156 = F_84 ( V_214 , V_80 ) ;
V_142 = F_134 ( V_19 , V_35 - 1 ) ;
V_173 = F_150 ( V_19 , V_146 , V_142 ) ;
if ( V_173 ) {
if ( F_151 ( V_173 , V_156 , 1 ) > 0 ) {
* V_213 = V_173 ;
return 0 ;
}
F_3 ( V_5 ) ;
V_34 = F_152 ( V_173 , V_156 ) ;
if ( ! V_34 ) {
* V_213 = V_173 ;
return 0 ;
}
F_12 ( V_173 ) ;
F_9 ( V_5 ) ;
return - V_165 ;
}
F_179 ( V_5 , V_35 + 1 ) ;
F_3 ( V_5 ) ;
F_12 ( V_173 ) ;
if ( V_5 -> V_202 )
F_174 ( V_19 , V_5 , V_35 , V_80 , V_85 -> V_119 ) ;
F_9 ( V_5 ) ;
V_34 = - V_215 ;
V_173 = F_135 ( V_19 , V_146 , V_142 , 0 ) ;
if ( V_173 ) {
if ( ! F_151 ( V_173 , 0 , 0 ) )
V_34 = - V_165 ;
F_12 ( V_173 ) ;
}
return V_34 ;
}
static int
F_181 ( struct V_28 * V_29 ,
struct V_18 * V_19 , struct V_1 * V_5 ,
struct V_14 * V_214 , int V_35 , int V_216 ,
int * V_208 )
{
int V_34 ;
if ( ( V_5 -> V_217 || V_216 > 0 ) && F_90 ( V_214 ) >=
F_132 ( V_19 ) - 3 ) {
int V_218 ;
if ( * V_208 < V_35 + 1 ) {
* V_208 = V_35 + 1 ;
F_9 ( V_5 ) ;
goto V_219;
}
F_3 ( V_5 ) ;
F_177 ( V_19 , V_5 , V_35 ) ;
V_218 = F_182 ( V_29 , V_19 , V_5 , V_35 ) ;
F_5 ( V_5 , NULL , 0 ) ;
F_75 ( V_218 > 0 ) ;
if ( V_218 ) {
V_34 = V_218 ;
goto V_220;
}
V_214 = V_5 -> V_8 [ V_35 ] ;
} else if ( V_216 < 0 && F_90 ( V_214 ) <
F_132 ( V_19 ) / 2 ) {
int V_218 ;
if ( * V_208 < V_35 + 1 ) {
* V_208 = V_35 + 1 ;
F_9 ( V_5 ) ;
goto V_219;
}
F_3 ( V_5 ) ;
F_177 ( V_19 , V_5 , V_35 ) ;
V_218 = F_167 ( V_29 , V_19 , V_5 , V_35 ) ;
F_5 ( V_5 , NULL , 0 ) ;
if ( V_218 ) {
V_34 = V_218 ;
goto V_220;
}
V_214 = V_5 -> V_8 [ V_35 ] ;
if ( ! V_214 ) {
F_9 ( V_5 ) ;
goto V_219;
}
F_75 ( F_90 ( V_214 ) == 1 ) ;
}
return 0 ;
V_219:
V_34 = - V_215 ;
V_220:
return V_34 ;
}
int F_183 ( struct V_28 * V_29 , struct V_18
* V_19 , struct V_149 * V_85 , struct V_1 * V_5 , int
V_216 , int V_33 )
{
struct V_14 * V_214 ;
int V_80 ;
int V_34 ;
int V_160 ;
int V_35 ;
int V_206 = 1 ;
int V_221 ;
int V_208 = 0 ;
T_5 V_222 = 0 ;
int V_207 ;
V_222 = V_5 -> V_222 ;
F_31 ( V_222 && V_216 > 0 ) ;
F_31 ( V_5 -> V_8 [ 0 ] != NULL ) ;
if ( V_216 < 0 ) {
V_206 = 2 ;
V_208 = 2 ;
} else if ( V_216 > 0 ) {
V_208 = 1 ;
}
if ( ! V_33 )
V_208 = - 1 ;
if ( V_33 && ( V_5 -> V_212 || V_5 -> V_222 ) )
V_208 = V_7 ;
V_207 = V_208 ;
V_219:
V_221 = V_10 ;
V_35 = 0 ;
if ( V_5 -> V_223 ) {
V_214 = V_19 -> V_112 ;
F_116 ( V_214 ) ;
V_35 = F_32 ( V_214 ) ;
if ( ! V_5 -> V_224 )
F_23 ( V_214 ) ;
} else {
if ( V_5 -> V_224 ) {
V_214 = F_13 ( V_19 ) ;
V_35 = F_32 ( V_214 ) ;
} else {
V_214 = F_22 ( V_19 ) ;
V_35 = F_32 ( V_214 ) ;
if ( V_35 <= V_208 ) {
F_24 ( V_214 ) ;
F_12 ( V_214 ) ;
V_214 = F_19 ( V_19 ) ;
V_221 = V_12 ;
V_35 = F_32 ( V_214 ) ;
}
}
}
V_5 -> V_8 [ V_35 ] = V_214 ;
if ( ! V_5 -> V_224 )
V_5 -> V_9 [ V_35 ] = V_221 ;
while ( V_214 ) {
V_35 = F_32 ( V_214 ) ;
if ( V_33 ) {
if ( ! F_139 ( V_29 , V_19 , V_214 ) )
goto V_225;
F_3 ( V_5 ) ;
if ( V_35 > V_208 ||
( V_35 + 1 > V_208 &&
V_35 + 1 < V_7 &&
V_5 -> V_8 [ V_35 + 1 ] ) ) {
V_208 = V_35 + 1 ;
F_9 ( V_5 ) ;
goto V_219;
}
V_160 = F_141 ( V_29 , V_19 , V_214 ,
V_5 -> V_8 [ V_35 + 1 ] ,
V_5 -> V_17 [ V_35 + 1 ] , & V_214 ) ;
if ( V_160 ) {
V_34 = V_160 ;
goto V_220;
}
}
V_225:
F_75 ( ! V_33 && V_216 ) ;
V_5 -> V_8 [ V_35 ] = V_214 ;
F_5 ( V_5 , NULL , 0 ) ;
if ( ! V_33 )
F_179 ( V_5 , V_35 + 1 ) ;
V_34 = F_160 ( V_214 , V_85 , V_35 , & V_80 ) ;
if ( V_35 != 0 ) {
int V_226 = 0 ;
if ( V_34 && V_80 > 0 ) {
V_226 = 1 ;
V_80 -= 1 ;
}
V_5 -> V_17 [ V_35 ] = V_80 ;
V_160 = F_181 ( V_29 , V_19 , V_5 , V_214 , V_35 ,
V_216 , & V_208 ) ;
if ( V_160 == - V_215 )
goto V_219;
if ( V_160 ) {
V_34 = V_160 ;
goto V_220;
}
V_214 = V_5 -> V_8 [ V_35 ] ;
V_80 = V_5 -> V_17 [ V_35 ] ;
if ( V_80 == 0 && V_33 &&
V_208 < V_35 + 1 ) {
V_208 = V_35 + 1 ;
F_9 ( V_5 ) ;
goto V_219;
}
F_178 ( V_5 , V_35 , V_206 ,
V_207 , & V_208 ) ;
if ( V_35 == V_222 ) {
if ( V_226 )
V_5 -> V_17 [ V_35 ] ++ ;
goto V_220;
}
V_160 = F_180 ( V_29 , V_19 , V_5 ,
& V_214 , V_35 , V_80 , V_85 , 0 ) ;
if ( V_160 == - V_215 )
goto V_219;
if ( V_160 ) {
V_34 = V_160 ;
goto V_220;
}
if ( ! V_5 -> V_224 ) {
V_35 = F_32 ( V_214 ) ;
if ( V_35 <= V_208 ) {
V_160 = F_184 ( V_214 ) ;
if ( ! V_160 ) {
F_3 ( V_5 ) ;
F_20 ( V_214 ) ;
F_5 ( V_5 , V_214 ,
V_12 ) ;
}
V_5 -> V_9 [ V_35 ] = V_12 ;
} else {
V_160 = F_185 ( V_214 ) ;
if ( ! V_160 ) {
F_3 ( V_5 ) ;
F_23 ( V_214 ) ;
F_5 ( V_5 , V_214 ,
V_10 ) ;
}
V_5 -> V_9 [ V_35 ] = V_10 ;
}
V_5 -> V_8 [ V_35 ] = V_214 ;
}
} else {
V_5 -> V_17 [ V_35 ] = V_80 ;
if ( V_216 > 0 &&
F_186 ( V_19 , V_214 ) < V_216 ) {
if ( V_208 < 1 ) {
V_208 = 1 ;
F_9 ( V_5 ) ;
goto V_219;
}
F_3 ( V_5 ) ;
V_160 = F_187 ( V_29 , V_19 , V_85 ,
V_5 , V_216 , V_34 == 0 ) ;
F_5 ( V_5 , NULL , 0 ) ;
F_75 ( V_160 > 0 ) ;
if ( V_160 ) {
V_34 = V_160 ;
goto V_220;
}
}
if ( ! V_5 -> V_217 )
F_178 ( V_5 , V_35 , V_206 ,
V_207 , & V_208 ) ;
goto V_220;
}
}
V_34 = 1 ;
V_220:
if ( ! V_5 -> V_227 )
F_3 ( V_5 ) ;
if ( V_34 < 0 )
F_9 ( V_5 ) ;
return V_34 ;
}
int F_188 ( struct V_18 * V_19 , struct V_149 * V_85 ,
struct V_1 * V_5 , T_2 V_127 )
{
struct V_14 * V_214 ;
int V_80 ;
int V_34 ;
int V_160 ;
int V_35 ;
int V_206 = 1 ;
T_5 V_222 = 0 ;
V_222 = V_5 -> V_222 ;
F_31 ( V_5 -> V_8 [ 0 ] != NULL ) ;
if ( V_5 -> V_223 ) {
F_75 ( V_127 ) ;
return F_183 ( NULL , V_19 , V_85 , V_5 , 0 , 0 ) ;
}
V_219:
V_214 = F_133 ( V_19 , V_127 ) ;
V_35 = F_32 ( V_214 ) ;
V_5 -> V_9 [ V_35 ] = V_10 ;
while ( V_214 ) {
V_35 = F_32 ( V_214 ) ;
V_5 -> V_8 [ V_35 ] = V_214 ;
F_5 ( V_5 , NULL , 0 ) ;
F_179 ( V_5 , V_35 + 1 ) ;
V_34 = F_160 ( V_214 , V_85 , V_35 , & V_80 ) ;
if ( V_35 != 0 ) {
int V_226 = 0 ;
if ( V_34 && V_80 > 0 ) {
V_226 = 1 ;
V_80 -= 1 ;
}
V_5 -> V_17 [ V_35 ] = V_80 ;
F_178 ( V_5 , V_35 , V_206 , 0 , NULL ) ;
if ( V_35 == V_222 ) {
if ( V_226 )
V_5 -> V_17 [ V_35 ] ++ ;
goto V_220;
}
V_160 = F_180 ( NULL , V_19 , V_5 , & V_214 , V_35 ,
V_80 , V_85 , V_127 ) ;
if ( V_160 == - V_215 )
goto V_219;
if ( V_160 ) {
V_34 = V_160 ;
goto V_220;
}
V_35 = F_32 ( V_214 ) ;
V_160 = F_185 ( V_214 ) ;
if ( ! V_160 ) {
F_3 ( V_5 ) ;
F_23 ( V_214 ) ;
F_5 ( V_5 , V_214 ,
V_10 ) ;
}
V_214 = F_128 ( V_19 -> V_23 , V_214 , V_127 ) ;
V_5 -> V_9 [ V_35 ] = V_10 ;
V_5 -> V_8 [ V_35 ] = V_214 ;
} else {
V_5 -> V_17 [ V_35 ] = V_80 ;
F_178 ( V_5 , V_35 , V_206 , 0 , NULL ) ;
goto V_220;
}
}
V_34 = 1 ;
V_220:
if ( ! V_5 -> V_227 )
F_3 ( V_5 ) ;
if ( V_34 < 0 )
F_9 ( V_5 ) ;
return V_34 ;
}
int F_189 ( struct V_18 * V_19 ,
struct V_149 * V_85 , struct V_1 * V_5 ,
int V_228 , int V_229 )
{
int V_34 ;
struct V_14 * V_166 ;
V_219:
V_34 = F_183 ( NULL , V_19 , V_85 , V_5 , 0 , 0 ) ;
if ( V_34 <= 0 )
return V_34 ;
V_166 = V_5 -> V_8 [ 0 ] ;
if ( V_228 ) {
if ( V_5 -> V_17 [ 0 ] >= F_90 ( V_166 ) ) {
V_34 = F_190 ( V_19 , V_5 ) ;
if ( V_34 <= 0 )
return V_34 ;
if ( ! V_229 )
return 1 ;
V_229 = 0 ;
V_228 = 0 ;
F_9 ( V_5 ) ;
goto V_219;
}
} else {
if ( V_5 -> V_17 [ 0 ] == 0 ) {
V_34 = F_191 ( V_19 , V_5 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( ! V_34 ) {
V_5 -> V_17 [ 0 ] = F_90 ( V_166 ) - 1 ;
return 0 ;
}
if ( ! V_229 )
return 1 ;
V_229 = 0 ;
V_228 = 1 ;
F_9 ( V_5 ) ;
goto V_219;
} else {
-- V_5 -> V_17 [ 0 ] ;
}
}
return 0 ;
}
static void F_192 ( struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_36 * V_85 , int V_35 )
{
int V_6 ;
struct V_14 * V_211 ;
for ( V_6 = V_35 ; V_6 < V_7 ; V_6 ++ ) {
int V_230 = V_2 -> V_17 [ V_6 ] ;
if ( ! V_2 -> V_8 [ V_6 ] )
break;
V_211 = V_2 -> V_8 [ V_6 ] ;
F_97 ( V_19 -> V_23 , V_211 , V_230 , 1 ) ;
F_124 ( V_211 , V_85 , V_230 ) ;
F_49 ( V_2 -> V_8 [ V_6 ] ) ;
if ( V_230 != 0 )
break;
}
}
void F_193 ( struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_149 * V_231 )
{
struct V_36 V_37 ;
struct V_14 * V_20 ;
int V_80 ;
V_20 = V_2 -> V_8 [ 0 ] ;
V_80 = V_2 -> V_17 [ 0 ] ;
if ( V_80 > 0 ) {
F_33 ( V_20 , & V_37 , V_80 - 1 ) ;
F_75 ( F_146 ( & V_37 , V_231 ) >= 0 ) ;
}
if ( V_80 < F_90 ( V_20 ) - 1 ) {
F_33 ( V_20 , & V_37 , V_80 + 1 ) ;
F_75 ( F_146 ( & V_37 , V_231 ) <= 0 ) ;
}
F_194 ( & V_37 , V_231 ) ;
F_195 ( V_20 , & V_37 , V_80 ) ;
F_49 ( V_20 ) ;
if ( V_80 == 0 )
F_192 ( V_19 , V_2 , & V_37 , 1 ) ;
}
static int F_169 ( struct V_28 * V_29 ,
struct V_18 * V_19 , struct V_14 * V_104 ,
struct V_14 * V_105 , int V_232 )
{
int V_233 = 0 ;
int V_234 ;
int V_235 ;
int V_34 = 0 ;
V_234 = F_90 ( V_105 ) ;
V_235 = F_90 ( V_104 ) ;
V_233 = F_132 ( V_19 ) - V_235 ;
F_31 ( F_47 ( V_105 ) != V_29 -> V_39 ) ;
F_31 ( F_47 ( V_104 ) != V_29 -> V_39 ) ;
if ( ! V_232 && V_234 <= 8 )
return 1 ;
if ( V_233 <= 0 )
return 1 ;
if ( V_232 ) {
V_233 = F_153 ( V_234 , V_233 ) ;
if ( V_233 < V_234 ) {
if ( V_234 - V_233 < 8 ) {
if ( V_233 <= 8 )
return 1 ;
V_233 -= 8 ;
}
}
} else
V_233 = F_153 ( V_234 - 8 , V_233 ) ;
F_95 ( V_19 -> V_23 , V_104 , V_105 , V_235 , 0 ,
V_233 ) ;
F_38 ( V_104 , V_105 ,
F_125 ( V_235 ) ,
F_125 ( 0 ) ,
V_233 * sizeof( struct V_135 ) ) ;
if ( V_233 < V_234 ) {
F_126 ( V_105 , F_125 ( 0 ) ,
F_125 ( V_233 ) ,
( V_234 - V_233 ) *
sizeof( struct V_135 ) ) ;
}
F_127 ( V_105 , V_234 - V_233 ) ;
F_127 ( V_104 , V_235 + V_233 ) ;
F_49 ( V_105 ) ;
F_49 ( V_104 ) ;
return V_34 ;
}
static int F_171 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_14 * V_104 ,
struct V_14 * V_105 )
{
int V_233 = 0 ;
int V_236 ;
int V_234 ;
int V_235 ;
int V_34 = 0 ;
F_31 ( F_47 ( V_105 ) != V_29 -> V_39 ) ;
F_31 ( F_47 ( V_104 ) != V_29 -> V_39 ) ;
V_234 = F_90 ( V_105 ) ;
V_235 = F_90 ( V_104 ) ;
V_233 = F_132 ( V_19 ) - V_235 ;
if ( V_233 <= 0 )
return 1 ;
if ( V_234 < 4 )
return 1 ;
V_236 = V_234 / 2 + 1 ;
if ( V_236 >= V_234 )
return 1 ;
if ( V_236 < V_233 )
V_233 = V_236 ;
F_96 ( V_19 -> V_23 , V_104 , V_233 , 0 , V_235 ) ;
F_126 ( V_104 , F_125 ( V_233 ) ,
F_125 ( 0 ) ,
( V_235 ) *
sizeof( struct V_135 ) ) ;
F_95 ( V_19 -> V_23 , V_104 , V_105 , 0 ,
V_234 - V_233 , V_233 ) ;
F_38 ( V_104 , V_105 ,
F_125 ( 0 ) ,
F_125 ( V_234 - V_233 ) ,
V_233 * sizeof( struct V_135 ) ) ;
F_127 ( V_105 , V_234 - V_233 ) ;
F_127 ( V_104 , V_235 + V_233 ) ;
F_49 ( V_105 ) ;
F_49 ( V_104 ) ;
return V_34 ;
}
static T_1 int F_196 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_35 )
{
T_2 V_237 ;
struct V_14 * V_238 ;
struct V_14 * V_239 ;
struct V_14 * V_139 ;
struct V_36 V_240 ;
F_75 ( V_2 -> V_8 [ V_35 ] ) ;
F_75 ( V_2 -> V_8 [ V_35 - 1 ] != V_19 -> V_21 ) ;
V_238 = V_2 -> V_8 [ V_35 - 1 ] ;
if ( V_35 == 1 )
F_33 ( V_238 , & V_240 , 0 ) ;
else
F_34 ( V_238 , & V_240 , 0 ) ;
V_239 = F_35 ( V_29 , V_19 , V_19 -> V_138 , 0 ,
V_19 -> V_118 . V_119 , & V_240 ,
V_35 , V_19 -> V_21 -> V_43 , 0 ) ;
if ( F_36 ( V_239 ) )
return F_37 ( V_239 ) ;
F_163 ( V_19 , V_19 -> V_138 ) ;
F_197 ( V_239 , 0 , 0 , sizeof( struct V_241 ) ) ;
F_127 ( V_239 , 1 ) ;
F_130 ( V_239 , V_35 ) ;
F_39 ( V_239 , V_239 -> V_43 ) ;
F_40 ( V_239 , V_29 -> V_39 ) ;
F_41 ( V_239 , V_44 ) ;
F_44 ( V_239 , V_19 -> V_118 . V_119 ) ;
F_45 ( V_239 , V_19 -> V_23 -> V_48 ,
( unsigned long ) F_46 ( V_239 ) ,
V_49 ) ;
F_45 ( V_239 , V_19 -> V_23 -> V_242 ,
( unsigned long ) F_198 ( V_239 ) ,
V_243 ) ;
F_124 ( V_239 , & V_240 , 0 ) ;
F_119 ( V_239 , 0 , V_238 -> V_43 ) ;
V_237 = F_47 ( V_238 ) ;
F_31 ( V_237 != V_29 -> V_39 ) ;
F_120 ( V_239 , 0 , V_237 ) ;
F_49 ( V_239 ) ;
V_139 = V_19 -> V_21 ;
F_99 ( V_19 , V_239 , 0 ) ;
F_117 ( V_19 -> V_21 , V_239 ) ;
F_12 ( V_139 ) ;
F_25 ( V_19 ) ;
F_116 ( V_239 ) ;
V_2 -> V_8 [ V_35 ] = V_239 ;
V_2 -> V_9 [ V_35 ] = V_12 ;
V_2 -> V_17 [ V_35 ] = 0 ;
return 0 ;
}
static void F_199 ( struct V_28 * V_29 ,
struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_36 * V_85 , T_2 V_244 ,
int V_80 , int V_35 )
{
struct V_14 * V_238 ;
int V_95 ;
int V_34 ;
F_75 ( ! V_2 -> V_8 [ V_35 ] ) ;
F_113 ( V_2 -> V_8 [ V_35 ] ) ;
V_238 = V_2 -> V_8 [ V_35 ] ;
V_95 = F_90 ( V_238 ) ;
F_75 ( V_80 > V_95 ) ;
F_75 ( V_95 == F_132 ( V_19 ) ) ;
if ( V_80 != V_95 ) {
if ( V_35 )
F_96 ( V_19 -> V_23 , V_238 , V_80 + 1 ,
V_80 , V_95 - V_80 ) ;
F_126 ( V_238 ,
F_125 ( V_80 + 1 ) ,
F_125 ( V_80 ) ,
( V_95 - V_80 ) * sizeof( struct V_135 ) ) ;
}
if ( V_35 ) {
V_34 = F_86 ( V_19 -> V_23 , V_238 , V_80 ,
V_84 ) ;
F_75 ( V_34 < 0 ) ;
}
F_124 ( V_238 , V_85 , V_80 ) ;
F_119 ( V_238 , V_80 , V_244 ) ;
F_31 ( V_29 -> V_39 == 0 ) ;
F_120 ( V_238 , V_80 , V_29 -> V_39 ) ;
F_127 ( V_238 , V_95 + 1 ) ;
F_49 ( V_238 ) ;
}
static T_1 int F_182 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_35 )
{
struct V_14 * V_239 ;
struct V_14 * V_245 ;
struct V_36 V_37 ;
int V_172 ;
int V_34 ;
T_4 V_246 ;
V_239 = V_2 -> V_8 [ V_35 ] ;
F_31 ( F_47 ( V_239 ) != V_29 -> V_39 ) ;
if ( V_239 == V_19 -> V_21 ) {
V_34 = F_196 ( V_29 , V_19 , V_2 , V_35 + 1 ) ;
if ( V_34 )
return V_34 ;
} else {
V_34 = F_173 ( V_29 , V_19 , V_2 , V_35 ) ;
V_239 = V_2 -> V_8 [ V_35 ] ;
if ( ! V_34 && F_90 ( V_239 ) <
F_132 ( V_19 ) - 3 )
return 0 ;
if ( V_34 < 0 )
return V_34 ;
}
V_246 = F_90 ( V_239 ) ;
V_172 = ( V_246 + 1 ) / 2 ;
F_34 ( V_239 , & V_37 , V_172 ) ;
V_245 = F_35 ( V_29 , V_19 , V_19 -> V_138 , 0 ,
V_19 -> V_118 . V_119 ,
& V_37 , V_35 , V_239 -> V_43 , 0 ) ;
if ( F_36 ( V_245 ) )
return F_37 ( V_245 ) ;
F_163 ( V_19 , V_19 -> V_138 ) ;
F_197 ( V_245 , 0 , 0 , sizeof( struct V_241 ) ) ;
F_130 ( V_245 , F_32 ( V_239 ) ) ;
F_39 ( V_245 , V_245 -> V_43 ) ;
F_40 ( V_245 , V_29 -> V_39 ) ;
F_41 ( V_245 , V_44 ) ;
F_44 ( V_245 , V_19 -> V_118 . V_119 ) ;
F_45 ( V_245 , V_19 -> V_23 -> V_48 ,
( unsigned long ) F_46 ( V_245 ) ,
V_49 ) ;
F_45 ( V_245 , V_19 -> V_23 -> V_242 ,
( unsigned long ) F_198 ( V_245 ) ,
V_243 ) ;
F_95 ( V_19 -> V_23 , V_245 , V_239 , 0 , V_172 , V_246 - V_172 ) ;
F_38 ( V_245 , V_239 ,
F_125 ( 0 ) ,
F_125 ( V_172 ) ,
( V_246 - V_172 ) * sizeof( struct V_135 ) ) ;
F_127 ( V_245 , V_246 - V_172 ) ;
F_127 ( V_239 , V_172 ) ;
V_34 = 0 ;
F_49 ( V_239 ) ;
F_49 ( V_245 ) ;
F_199 ( V_29 , V_19 , V_2 , & V_37 , V_245 -> V_43 ,
V_2 -> V_17 [ V_35 + 1 ] + 1 , V_35 + 1 ) ;
if ( V_2 -> V_17 [ V_35 ] >= V_172 ) {
V_2 -> V_17 [ V_35 ] -= V_172 ;
F_21 ( V_239 ) ;
F_12 ( V_239 ) ;
V_2 -> V_8 [ V_35 ] = V_245 ;
V_2 -> V_17 [ V_35 + 1 ] += 1 ;
} else {
F_21 ( V_245 ) ;
F_12 ( V_245 ) ;
}
return V_34 ;
}
static int F_200 ( struct V_14 * V_247 , int V_43 , int V_167 )
{
struct V_180 * V_248 ;
struct V_180 * V_249 ;
struct V_250 V_251 ;
int V_252 ;
int V_95 = F_90 ( V_247 ) ;
int V_253 = F_153 ( V_95 , V_43 + V_167 ) - 1 ;
if ( ! V_167 )
return 0 ;
F_201 ( & V_251 ) ;
V_248 = F_202 ( V_247 , V_43 ) ;
V_249 = F_202 ( V_247 , V_253 ) ;
V_252 = F_203 ( V_247 , V_248 , & V_251 ) +
F_204 ( V_247 , V_248 , & V_251 ) ;
V_252 = V_252 - F_203 ( V_247 , V_249 , & V_251 ) ;
V_252 += sizeof( struct V_180 ) * V_167 ;
F_31 ( V_252 < 0 ) ;
return V_252 ;
}
T_1 int F_186 ( struct V_18 * V_19 ,
struct V_14 * V_166 )
{
int V_95 = F_90 ( V_166 ) ;
int V_34 ;
V_34 = F_155 ( V_19 ) - F_200 ( V_166 , 0 , V_95 ) ;
if ( V_34 < 0 ) {
F_205 ( V_145 L_3
L_4 ,
V_34 , ( unsigned long ) F_155 ( V_19 ) ,
F_200 ( V_166 , 0 , V_95 ) , V_95 ) ;
}
return V_34 ;
}
static T_1 int F_206 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
int V_254 , int V_232 ,
struct V_14 * V_185 ,
int V_255 , T_4 V_256 ,
T_4 V_257 )
{
struct V_14 * V_186 = V_2 -> V_8 [ 0 ] ;
struct V_14 * V_258 = V_2 -> V_8 [ 1 ] ;
struct V_250 V_251 ;
struct V_36 V_37 ;
int V_80 ;
T_4 V_6 ;
int V_259 = 0 ;
int V_233 = 0 ;
struct V_180 * V_260 ;
T_4 V_167 ;
T_4 V_261 ;
T_4 V_262 ;
T_4 V_263 ;
F_201 ( & V_251 ) ;
if ( V_232 )
V_167 = 0 ;
else
V_167 = F_207 ( T_4 , 1 , V_257 ) ;
if ( V_2 -> V_17 [ 0 ] >= V_256 )
V_259 += V_254 ;
V_80 = V_2 -> V_17 [ 1 ] ;
V_6 = V_256 - 1 ;
while ( V_6 >= V_167 ) {
V_260 = F_202 ( V_186 , V_6 ) ;
if ( ! V_232 && V_233 > 0 ) {
if ( V_2 -> V_17 [ 0 ] > V_6 )
break;
if ( V_2 -> V_17 [ 0 ] == V_6 ) {
int V_264 = F_186 ( V_19 , V_186 ) ;
if ( V_264 + V_259 * 2 > V_255 )
break;
}
}
if ( V_2 -> V_17 [ 0 ] == V_6 )
V_259 += V_254 ;
V_263 = F_208 ( V_186 , V_260 ) ;
if ( V_263 + sizeof( * V_260 ) + V_259 > V_255 )
break;
V_233 ++ ;
V_259 += V_263 + sizeof( * V_260 ) ;
if ( V_6 == 0 )
break;
V_6 -- ;
}
if ( V_233 == 0 )
goto V_265;
F_31 ( ! V_232 && V_233 == V_256 ) ;
V_261 = F_90 ( V_185 ) ;
V_259 = F_209 ( V_186 , V_256 - V_233 ) ;
V_259 -= F_154 ( V_19 , V_186 ) ;
V_262 = F_154 ( V_19 , V_185 ) ;
F_126 ( V_185 ,
F_210 ( V_185 ) + V_262 - V_259 ,
F_210 ( V_185 ) + V_262 ,
F_155 ( V_19 ) - V_262 ) ;
F_38 ( V_185 , V_186 , F_210 ( V_185 ) +
F_155 ( V_19 ) - V_259 ,
F_210 ( V_186 ) + F_154 ( V_19 , V_186 ) ,
V_259 ) ;
F_126 ( V_185 , F_211 ( V_233 ) ,
F_211 ( 0 ) ,
V_261 * sizeof( struct V_180 ) ) ;
F_38 ( V_185 , V_186 , F_211 ( 0 ) ,
F_211 ( V_256 - V_233 ) ,
V_233 * sizeof( struct V_180 ) ) ;
V_261 += V_233 ;
F_127 ( V_185 , V_261 ) ;
V_259 = F_155 ( V_19 ) ;
for ( V_6 = 0 ; V_6 < V_261 ; V_6 ++ ) {
V_260 = F_202 ( V_185 , V_6 ) ;
V_259 -= F_204 ( V_185 , V_260 , & V_251 ) ;
F_212 ( V_185 , V_260 , V_259 , & V_251 ) ;
}
V_256 -= V_233 ;
F_127 ( V_186 , V_256 ) ;
if ( V_256 )
F_49 ( V_186 ) ;
else
F_111 ( V_29 , V_19 , V_186 ) ;
F_49 ( V_185 ) ;
F_33 ( V_185 , & V_37 , 0 ) ;
F_124 ( V_258 , & V_37 , V_80 + 1 ) ;
F_49 ( V_258 ) ;
if ( V_2 -> V_17 [ 0 ] >= V_256 ) {
V_2 -> V_17 [ 0 ] -= V_256 ;
if ( F_90 ( V_2 -> V_8 [ 0 ] ) == 0 )
F_111 ( V_29 , V_19 , V_2 -> V_8 [ 0 ] ) ;
F_21 ( V_2 -> V_8 [ 0 ] ) ;
F_12 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_185 ;
V_2 -> V_17 [ 1 ] += 1 ;
} else {
F_21 ( V_185 ) ;
F_12 ( V_185 ) ;
}
return 0 ;
V_265:
F_21 ( V_185 ) ;
F_12 ( V_185 ) ;
return 1 ;
}
static int F_213 ( struct V_28 * V_29 , struct V_18
* V_19 , struct V_1 * V_2 ,
int V_266 , int V_254 ,
int V_232 , T_4 V_257 )
{
struct V_14 * V_186 = V_2 -> V_8 [ 0 ] ;
struct V_14 * V_185 ;
struct V_14 * V_258 ;
int V_80 ;
int V_255 ;
T_4 V_256 ;
int V_34 ;
if ( ! V_2 -> V_8 [ 1 ] )
return 1 ;
V_80 = V_2 -> V_17 [ 1 ] ;
V_258 = V_2 -> V_8 [ 1 ] ;
if ( V_80 >= F_90 ( V_258 ) - 1 )
return 1 ;
F_113 ( V_2 -> V_8 [ 1 ] ) ;
V_185 = F_168 ( V_19 , V_258 , V_80 + 1 ) ;
if ( V_185 == NULL )
return 1 ;
F_20 ( V_185 ) ;
F_143 ( V_185 ) ;
V_255 = F_186 ( V_19 , V_185 ) ;
if ( V_255 < V_254 )
goto V_265;
V_34 = F_141 ( V_29 , V_19 , V_185 , V_258 ,
V_80 + 1 , & V_185 ) ;
if ( V_34 )
goto V_265;
V_255 = F_186 ( V_19 , V_185 ) ;
if ( V_255 < V_254 )
goto V_265;
V_256 = F_90 ( V_186 ) ;
if ( V_256 == 0 )
goto V_265;
return F_206 ( V_29 , V_19 , V_2 , V_266 , V_232 ,
V_185 , V_255 , V_256 , V_257 ) ;
V_265:
F_21 ( V_185 ) ;
F_12 ( V_185 ) ;
return 1 ;
}
static T_1 int F_214 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_254 ,
int V_232 , struct V_14 * V_186 ,
int V_255 , T_4 V_261 ,
T_4 V_267 )
{
struct V_36 V_37 ;
struct V_14 * V_185 = V_2 -> V_8 [ 0 ] ;
int V_6 ;
int V_259 = 0 ;
int V_233 = 0 ;
struct V_180 * V_260 ;
T_4 V_268 ;
T_4 V_167 ;
int V_34 = 0 ;
T_4 V_263 ;
T_4 V_269 ;
struct V_250 V_251 ;
F_201 ( & V_251 ) ;
if ( V_232 )
V_167 = F_153 ( V_261 , V_267 ) ;
else
V_167 = F_153 ( V_261 - 1 , V_267 ) ;
for ( V_6 = 0 ; V_6 < V_167 ; V_6 ++ ) {
V_260 = F_202 ( V_185 , V_6 ) ;
if ( ! V_232 && V_233 > 0 ) {
if ( V_2 -> V_17 [ 0 ] < V_6 )
break;
if ( V_2 -> V_17 [ 0 ] == V_6 ) {
int V_264 = F_186 ( V_19 , V_185 ) ;
if ( V_264 + V_259 * 2 > V_255 )
break;
}
}
if ( V_2 -> V_17 [ 0 ] == V_6 )
V_259 += V_254 ;
V_263 = F_208 ( V_185 , V_260 ) ;
if ( V_263 + sizeof( * V_260 ) + V_259 > V_255 )
break;
V_233 ++ ;
V_259 += V_263 + sizeof( * V_260 ) ;
}
if ( V_233 == 0 ) {
V_34 = 1 ;
goto V_92;
}
if ( ! V_232 && V_233 == F_90 ( V_185 ) )
F_31 ( 1 ) ;
F_38 ( V_186 , V_185 ,
F_211 ( F_90 ( V_186 ) ) ,
F_211 ( 0 ) ,
V_233 * sizeof( struct V_180 ) ) ;
V_259 = F_155 ( V_19 ) -
F_156 ( V_185 , V_233 - 1 ) ;
F_38 ( V_186 , V_185 , F_210 ( V_186 ) +
F_154 ( V_19 , V_186 ) - V_259 ,
F_210 ( V_185 ) +
F_156 ( V_185 , V_233 - 1 ) ,
V_259 ) ;
V_268 = F_90 ( V_186 ) ;
F_75 ( V_268 <= 0 ) ;
V_269 = F_156 ( V_186 , V_268 - 1 ) ;
for ( V_6 = V_268 ; V_6 < V_268 + V_233 ; V_6 ++ ) {
T_4 V_270 ;
V_260 = F_202 ( V_186 , V_6 ) ;
V_270 = F_203 ( V_186 , V_260 , & V_251 ) ;
F_212 ( V_186 , V_260 ,
V_270 - ( F_155 ( V_19 ) - V_269 ) ,
& V_251 ) ;
}
F_127 ( V_186 , V_268 + V_233 ) ;
if ( V_233 > V_261 )
F_142 ( 1 , V_145 L_5 , V_233 ,
V_261 ) ;
if ( V_233 < V_261 ) {
V_259 = F_156 ( V_185 , V_233 - 1 ) -
F_154 ( V_19 , V_185 ) ;
F_126 ( V_185 , F_210 ( V_185 ) +
F_155 ( V_19 ) - V_259 ,
F_210 ( V_185 ) +
F_154 ( V_19 , V_185 ) , V_259 ) ;
F_126 ( V_185 , F_211 ( 0 ) ,
F_211 ( V_233 ) ,
( F_90 ( V_185 ) - V_233 ) *
sizeof( struct V_180 ) ) ;
}
V_261 -= V_233 ;
F_127 ( V_185 , V_261 ) ;
V_259 = F_155 ( V_19 ) ;
for ( V_6 = 0 ; V_6 < V_261 ; V_6 ++ ) {
V_260 = F_202 ( V_185 , V_6 ) ;
V_259 = V_259 - F_204 ( V_185 ,
V_260 , & V_251 ) ;
F_212 ( V_185 , V_260 , V_259 , & V_251 ) ;
}
F_49 ( V_186 ) ;
if ( V_261 )
F_49 ( V_185 ) ;
else
F_111 ( V_29 , V_19 , V_185 ) ;
F_33 ( V_185 , & V_37 , 0 ) ;
F_192 ( V_19 , V_2 , & V_37 , 1 ) ;
if ( V_2 -> V_17 [ 0 ] < V_233 ) {
V_2 -> V_17 [ 0 ] += V_268 ;
F_21 ( V_2 -> V_8 [ 0 ] ) ;
F_12 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_186 ;
V_2 -> V_17 [ 1 ] -= 1 ;
} else {
F_21 ( V_186 ) ;
F_12 ( V_186 ) ;
V_2 -> V_17 [ 0 ] -= V_233 ;
}
F_75 ( V_2 -> V_17 [ 0 ] < 0 ) ;
return V_34 ;
V_92:
F_21 ( V_186 ) ;
F_12 ( V_186 ) ;
return V_34 ;
}
static int F_215 ( struct V_28 * V_29 , struct V_18
* V_19 , struct V_1 * V_2 , int V_266 ,
int V_254 , int V_232 , T_4 V_267 )
{
struct V_14 * V_185 = V_2 -> V_8 [ 0 ] ;
struct V_14 * V_186 ;
int V_80 ;
int V_255 ;
T_4 V_261 ;
int V_34 = 0 ;
V_80 = V_2 -> V_17 [ 1 ] ;
if ( V_80 == 0 )
return 1 ;
if ( ! V_2 -> V_8 [ 1 ] )
return 1 ;
V_261 = F_90 ( V_185 ) ;
if ( V_261 == 0 )
return 1 ;
F_113 ( V_2 -> V_8 [ 1 ] ) ;
V_186 = F_168 ( V_19 , V_2 -> V_8 [ 1 ] , V_80 - 1 ) ;
if ( V_186 == NULL )
return 1 ;
F_20 ( V_186 ) ;
F_143 ( V_186 ) ;
V_255 = F_186 ( V_19 , V_186 ) ;
if ( V_255 < V_254 ) {
V_34 = 1 ;
goto V_92;
}
V_34 = F_141 ( V_29 , V_19 , V_186 ,
V_2 -> V_8 [ 1 ] , V_80 - 1 , & V_186 ) ;
if ( V_34 ) {
if ( V_34 == - V_193 )
V_34 = 1 ;
goto V_92;
}
V_255 = F_186 ( V_19 , V_186 ) ;
if ( V_255 < V_254 ) {
V_34 = 1 ;
goto V_92;
}
return F_214 ( V_29 , V_19 , V_2 , V_266 ,
V_232 , V_186 , V_255 , V_261 ,
V_267 ) ;
V_92:
F_21 ( V_186 ) ;
F_12 ( V_186 ) ;
return V_34 ;
}
static T_1 void F_216 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_14 * V_247 ,
struct V_14 * V_185 ,
int V_80 , int V_172 , int V_95 )
{
int V_271 ;
int V_272 ;
int V_6 ;
struct V_36 V_37 ;
struct V_250 V_251 ;
F_201 ( & V_251 ) ;
V_95 = V_95 - V_172 ;
F_127 ( V_185 , V_95 ) ;
V_271 = F_209 ( V_247 , V_172 ) - F_154 ( V_19 , V_247 ) ;
F_38 ( V_185 , V_247 , F_211 ( 0 ) ,
F_211 ( V_172 ) ,
V_95 * sizeof( struct V_180 ) ) ;
F_38 ( V_185 , V_247 ,
F_210 ( V_185 ) + F_155 ( V_19 ) -
V_271 , F_210 ( V_247 ) +
F_154 ( V_19 , V_247 ) , V_271 ) ;
V_272 = F_155 ( V_19 ) -
F_209 ( V_247 , V_172 ) ;
for ( V_6 = 0 ; V_6 < V_95 ; V_6 ++ ) {
struct V_180 * V_260 = F_202 ( V_185 , V_6 ) ;
T_4 V_270 ;
V_270 = F_203 ( V_185 , V_260 , & V_251 ) ;
F_212 ( V_185 , V_260 ,
V_270 + V_272 , & V_251 ) ;
}
F_127 ( V_247 , V_172 ) ;
F_33 ( V_185 , & V_37 , 0 ) ;
F_199 ( V_29 , V_19 , V_2 , & V_37 , V_185 -> V_43 ,
V_2 -> V_17 [ 1 ] + 1 , 1 ) ;
F_49 ( V_185 ) ;
F_49 ( V_247 ) ;
F_75 ( V_2 -> V_17 [ 0 ] != V_80 ) ;
if ( V_172 <= V_80 ) {
F_21 ( V_2 -> V_8 [ 0 ] ) ;
F_12 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_185 ;
V_2 -> V_17 [ 0 ] -= V_172 ;
V_2 -> V_17 [ 1 ] += 1 ;
} else {
F_21 ( V_185 ) ;
F_12 ( V_185 ) ;
}
F_75 ( V_2 -> V_17 [ 0 ] < 0 ) ;
}
static T_1 int F_217 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
int V_254 )
{
int V_34 ;
int V_155 = 0 ;
int V_80 ;
T_4 V_95 ;
V_80 = V_2 -> V_17 [ 0 ] ;
V_34 = F_213 ( V_29 , V_19 , V_2 , 1 , V_254 , 0 , V_80 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_34 == 0 )
V_155 ++ ;
V_95 = F_90 ( V_2 -> V_8 [ 0 ] ) ;
if ( V_2 -> V_17 [ 0 ] == 0 || V_2 -> V_17 [ 0 ] == V_95 )
return 0 ;
if ( F_186 ( V_19 , V_2 -> V_8 [ 0 ] ) >= V_254 )
return 0 ;
V_80 = V_2 -> V_17 [ 0 ] ;
V_34 = F_215 ( V_29 , V_19 , V_2 , 1 , V_254 , 0 , V_80 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_34 == 0 )
V_155 ++ ;
if ( V_155 )
return 0 ;
return 1 ;
}
static T_1 int F_187 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_149 * V_273 ,
struct V_1 * V_2 , int V_254 ,
int V_274 )
{
struct V_36 V_37 ;
struct V_14 * V_247 ;
T_4 V_95 ;
int V_172 ;
int V_80 ;
struct V_14 * V_185 ;
int V_34 = 0 ;
int V_187 ;
int V_245 ;
int V_275 = 0 ;
int V_276 = 0 ;
V_247 = V_2 -> V_8 [ 0 ] ;
V_80 = V_2 -> V_17 [ 0 ] ;
if ( V_274 && V_254 + F_218 ( V_247 , V_80 ) +
sizeof( struct V_180 ) > F_155 ( V_19 ) )
return - V_277 ;
if ( V_254 && V_2 -> V_8 [ 1 ] ) {
V_187 = F_213 ( V_29 , V_19 , V_2 , V_254 ,
V_254 , 0 , 0 ) ;
if ( V_187 < 0 )
return V_187 ;
if ( V_187 ) {
V_187 = F_215 ( V_29 , V_19 , V_2 , V_254 ,
V_254 , 0 , ( T_4 ) - 1 ) ;
if ( V_187 < 0 )
return V_187 ;
}
V_247 = V_2 -> V_8 [ 0 ] ;
if ( F_186 ( V_19 , V_247 ) >= V_254 )
return 0 ;
}
if ( ! V_2 -> V_8 [ 1 ] ) {
V_34 = F_196 ( V_29 , V_19 , V_2 , 1 ) ;
if ( V_34 )
return V_34 ;
}
V_219:
V_245 = 1 ;
V_247 = V_2 -> V_8 [ 0 ] ;
V_80 = V_2 -> V_17 [ 0 ] ;
V_95 = F_90 ( V_247 ) ;
V_172 = ( V_95 + 1 ) / 2 ;
if ( V_172 <= V_80 ) {
if ( V_95 == 1 ||
F_200 ( V_247 , V_172 , V_95 - V_172 ) + V_254 >
F_155 ( V_19 ) ) {
if ( V_80 >= V_95 ) {
V_245 = 0 ;
} else {
V_172 = V_80 ;
if ( V_172 != V_95 &&
F_200 ( V_247 , V_172 , V_95 - V_172 ) +
V_254 > F_155 ( V_19 ) ) {
if ( V_254 && ! V_276 )
goto V_278;
V_245 = 2 ;
}
}
}
} else {
if ( F_200 ( V_247 , 0 , V_172 ) + V_254 >
F_155 ( V_19 ) ) {
if ( ! V_274 && V_254 && V_80 == 0 ) {
V_245 = 0 ;
} else if ( ( V_274 || ! V_254 ) && V_80 == 0 ) {
V_172 = 1 ;
} else {
V_172 = V_80 ;
if ( V_172 != V_95 &&
F_200 ( V_247 , V_172 , V_95 - V_172 ) +
V_254 > F_155 ( V_19 ) ) {
if ( V_254 && ! V_276 )
goto V_278;
V_245 = 2 ;
}
}
}
}
if ( V_245 == 0 )
F_194 ( & V_37 , V_273 ) ;
else
F_33 ( V_247 , & V_37 , V_172 ) ;
V_185 = F_35 ( V_29 , V_19 , V_19 -> V_279 , 0 ,
V_19 -> V_118 . V_119 ,
& V_37 , 0 , V_247 -> V_43 , 0 ) ;
if ( F_36 ( V_185 ) )
return F_37 ( V_185 ) ;
F_163 ( V_19 , V_19 -> V_279 ) ;
F_197 ( V_185 , 0 , 0 , sizeof( struct V_241 ) ) ;
F_39 ( V_185 , V_185 -> V_43 ) ;
F_40 ( V_185 , V_29 -> V_39 ) ;
F_41 ( V_185 , V_44 ) ;
F_44 ( V_185 , V_19 -> V_118 . V_119 ) ;
F_130 ( V_185 , 0 ) ;
F_45 ( V_185 , V_19 -> V_23 -> V_48 ,
( unsigned long ) F_46 ( V_185 ) ,
V_49 ) ;
F_45 ( V_185 , V_19 -> V_23 -> V_242 ,
( unsigned long ) F_198 ( V_185 ) ,
V_243 ) ;
if ( V_245 == 0 ) {
if ( V_172 <= V_80 ) {
F_127 ( V_185 , 0 ) ;
F_199 ( V_29 , V_19 , V_2 , & V_37 , V_185 -> V_43 ,
V_2 -> V_17 [ 1 ] + 1 , 1 ) ;
F_21 ( V_2 -> V_8 [ 0 ] ) ;
F_12 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_185 ;
V_2 -> V_17 [ 0 ] = 0 ;
V_2 -> V_17 [ 1 ] += 1 ;
} else {
F_127 ( V_185 , 0 ) ;
F_199 ( V_29 , V_19 , V_2 , & V_37 , V_185 -> V_43 ,
V_2 -> V_17 [ 1 ] , 1 ) ;
F_21 ( V_2 -> V_8 [ 0 ] ) ;
F_12 ( V_2 -> V_8 [ 0 ] ) ;
V_2 -> V_8 [ 0 ] = V_185 ;
V_2 -> V_17 [ 0 ] = 0 ;
if ( V_2 -> V_17 [ 1 ] == 0 )
F_192 ( V_19 , V_2 , & V_37 , 1 ) ;
}
F_49 ( V_185 ) ;
return V_34 ;
}
F_216 ( V_29 , V_19 , V_2 , V_247 , V_185 , V_80 , V_172 , V_95 ) ;
if ( V_245 == 2 ) {
F_75 ( V_275 != 0 ) ;
V_275 ++ ;
goto V_219;
}
return 0 ;
V_278:
F_217 ( V_29 , V_19 , V_2 , V_254 ) ;
V_276 = 1 ;
if ( F_186 ( V_19 , V_2 -> V_8 [ 0 ] ) >= V_254 )
return 0 ;
goto V_219;
}
static T_1 int F_219 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 , int V_216 )
{
struct V_149 V_85 ;
struct V_14 * V_166 ;
struct V_280 * V_281 ;
T_2 V_282 = 0 ;
T_4 V_168 ;
int V_34 ;
V_166 = V_2 -> V_8 [ 0 ] ;
F_220 ( V_166 , & V_85 , V_2 -> V_17 [ 0 ] ) ;
F_75 ( V_85 . type != V_283 &&
V_85 . type != V_284 ) ;
if ( F_186 ( V_19 , V_166 ) >= V_216 )
return 0 ;
V_168 = F_218 ( V_166 , V_2 -> V_17 [ 0 ] ) ;
if ( V_85 . type == V_283 ) {
V_281 = F_221 ( V_166 , V_2 -> V_17 [ 0 ] ,
struct V_280 ) ;
V_282 = F_222 ( V_166 , V_281 ) ;
}
F_9 ( V_2 ) ;
V_2 -> V_212 = 1 ;
V_2 -> V_217 = 1 ;
V_34 = F_183 ( V_29 , V_19 , & V_85 , V_2 , 0 , 1 ) ;
V_2 -> V_217 = 0 ;
if ( V_34 < 0 )
goto V_160;
V_34 = - V_215 ;
V_166 = V_2 -> V_8 [ 0 ] ;
if ( V_34 > 0 || V_168 != F_218 ( V_166 , V_2 -> V_17 [ 0 ] ) )
goto V_160;
if ( F_186 ( V_19 , V_2 -> V_8 [ 0 ] ) >= V_216 )
goto V_160;
if ( V_85 . type == V_283 ) {
V_281 = F_221 ( V_166 , V_2 -> V_17 [ 0 ] ,
struct V_280 ) ;
if ( V_282 != F_222 ( V_166 , V_281 ) )
goto V_160;
}
F_3 ( V_2 ) ;
V_34 = F_187 ( V_29 , V_19 , & V_85 , V_2 , V_216 , 1 ) ;
if ( V_34 )
goto V_160;
V_2 -> V_212 = 0 ;
F_179 ( V_2 , 1 ) ;
return 0 ;
V_160:
V_2 -> V_212 = 0 ;
return V_34 ;
}
static T_1 int F_223 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_149 * V_231 ,
unsigned long V_285 )
{
struct V_14 * V_166 ;
struct V_180 * V_260 ;
struct V_180 * V_286 ;
int V_80 ;
char * V_30 ;
T_4 V_95 ;
T_4 V_168 ;
T_4 V_287 ;
struct V_36 V_37 ;
V_166 = V_2 -> V_8 [ 0 ] ;
F_75 ( F_186 ( V_19 , V_166 ) < sizeof( struct V_180 ) ) ;
F_3 ( V_2 ) ;
V_260 = F_202 ( V_166 , V_2 -> V_17 [ 0 ] ) ;
V_287 = F_224 ( V_166 , V_260 ) ;
V_168 = F_208 ( V_166 , V_260 ) ;
V_30 = F_225 ( V_168 , V_4 ) ;
if ( ! V_30 )
return - V_79 ;
F_159 ( V_166 , V_30 , F_226 ( V_166 ,
V_2 -> V_17 [ 0 ] ) , V_168 ) ;
V_80 = V_2 -> V_17 [ 0 ] + 1 ;
V_95 = F_90 ( V_166 ) ;
if ( V_80 != V_95 ) {
F_126 ( V_166 , F_211 ( V_80 + 1 ) ,
F_211 ( V_80 ) ,
( V_95 - V_80 ) * sizeof( struct V_180 ) ) ;
}
F_194 ( & V_37 , V_231 ) ;
F_195 ( V_166 , & V_37 , V_80 ) ;
V_286 = F_202 ( V_166 , V_80 ) ;
F_227 ( V_166 , V_286 , V_287 ) ;
F_228 ( V_166 , V_286 , V_168 - V_285 ) ;
F_227 ( V_166 , V_260 ,
V_287 + V_168 - V_285 ) ;
F_228 ( V_166 , V_260 , V_285 ) ;
F_127 ( V_166 , V_95 + 1 ) ;
F_45 ( V_166 , V_30 ,
F_226 ( V_166 , V_2 -> V_17 [ 0 ] ) ,
V_285 ) ;
F_45 ( V_166 , V_30 + V_285 ,
F_226 ( V_166 , V_80 ) ,
V_168 - V_285 ) ;
F_49 ( V_166 ) ;
F_75 ( F_186 ( V_19 , V_166 ) < 0 ) ;
F_73 ( V_30 ) ;
return 0 ;
}
int F_229 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_149 * V_231 ,
unsigned long V_285 )
{
int V_34 ;
V_34 = F_219 ( V_29 , V_19 , V_2 ,
sizeof( struct V_180 ) ) ;
if ( V_34 )
return V_34 ;
V_34 = F_223 ( V_29 , V_19 , V_2 , V_231 , V_285 ) ;
return V_34 ;
}
int F_230 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_149 * V_231 )
{
struct V_14 * V_166 ;
int V_34 ;
T_4 V_168 ;
V_166 = V_2 -> V_8 [ 0 ] ;
V_168 = F_218 ( V_166 , V_2 -> V_17 [ 0 ] ) ;
V_34 = F_219 ( V_29 , V_19 , V_2 ,
V_168 + sizeof( struct V_180 ) ) ;
if ( V_34 )
return V_34 ;
V_2 -> V_17 [ 0 ] ++ ;
F_231 ( V_19 , V_2 , V_231 , & V_168 ,
V_168 , V_168 +
sizeof( struct V_180 ) , 1 ) ;
V_166 = V_2 -> V_8 [ 0 ] ;
F_232 ( V_166 ,
F_226 ( V_166 , V_2 -> V_17 [ 0 ] ) ,
F_226 ( V_166 , V_2 -> V_17 [ 0 ] - 1 ) ,
V_168 ) ;
return 0 ;
}
void F_233 ( struct V_18 * V_19 , struct V_1 * V_2 ,
T_4 V_288 , int V_289 )
{
int V_80 ;
struct V_14 * V_166 ;
struct V_180 * V_260 ;
T_4 V_95 ;
unsigned int V_262 ;
unsigned int V_290 ;
unsigned int V_291 ;
unsigned int V_292 ;
int V_6 ;
struct V_250 V_251 ;
F_201 ( & V_251 ) ;
V_166 = V_2 -> V_8 [ 0 ] ;
V_80 = V_2 -> V_17 [ 0 ] ;
V_291 = F_218 ( V_166 , V_80 ) ;
if ( V_291 == V_288 )
return;
V_95 = F_90 ( V_166 ) ;
V_262 = F_154 ( V_19 , V_166 ) ;
V_290 = F_156 ( V_166 , V_80 ) ;
V_292 = V_291 - V_288 ;
F_75 ( V_80 < 0 ) ;
F_75 ( V_80 >= V_95 ) ;
for ( V_6 = V_80 ; V_6 < V_95 ; V_6 ++ ) {
T_4 V_270 ;
V_260 = F_202 ( V_166 , V_6 ) ;
V_270 = F_203 ( V_166 , V_260 , & V_251 ) ;
F_212 ( V_166 , V_260 ,
V_270 + V_292 , & V_251 ) ;
}
if ( V_289 ) {
F_126 ( V_166 , F_210 ( V_166 ) +
V_262 + V_292 , F_210 ( V_166 ) +
V_262 , V_290 + V_288 - V_262 ) ;
} else {
struct V_36 V_37 ;
T_2 V_152 ;
F_33 ( V_166 , & V_37 , V_80 ) ;
if ( F_234 ( & V_37 ) == V_283 ) {
unsigned long V_293 ;
struct V_280 * V_281 ;
V_281 = F_221 ( V_166 , V_80 ,
struct V_280 ) ;
V_281 = (struct V_280 * ) (
( unsigned long ) V_281 - V_292 ) ;
if ( F_235 ( V_166 , V_281 ) ==
V_294 ) {
V_293 = F_226 ( V_166 , V_80 ) ;
F_126 ( V_166 , V_293 ,
( unsigned long ) V_281 ,
F_161 ( struct V_280 ,
V_295 ) ) ;
}
}
F_126 ( V_166 , F_210 ( V_166 ) +
V_262 + V_292 , F_210 ( V_166 ) +
V_262 , V_290 - V_262 ) ;
V_152 = F_236 ( & V_37 ) ;
F_237 ( & V_37 , V_152 + V_292 ) ;
F_195 ( V_166 , & V_37 , V_80 ) ;
if ( V_80 == 0 )
F_192 ( V_19 , V_2 , & V_37 , 1 ) ;
}
V_260 = F_202 ( V_166 , V_80 ) ;
F_228 ( V_166 , V_260 , V_288 ) ;
F_49 ( V_166 ) ;
if ( F_186 ( V_19 , V_166 ) < 0 ) {
F_238 ( V_19 , V_166 ) ;
F_172 () ;
}
}
void F_239 ( struct V_18 * V_19 , struct V_1 * V_2 ,
T_4 V_254 )
{
int V_80 ;
struct V_14 * V_166 ;
struct V_180 * V_260 ;
T_4 V_95 ;
unsigned int V_262 ;
unsigned int V_296 ;
unsigned int V_291 ;
int V_6 ;
struct V_250 V_251 ;
F_201 ( & V_251 ) ;
V_166 = V_2 -> V_8 [ 0 ] ;
V_95 = F_90 ( V_166 ) ;
V_262 = F_154 ( V_19 , V_166 ) ;
if ( F_186 ( V_19 , V_166 ) < V_254 ) {
F_238 ( V_19 , V_166 ) ;
F_172 () ;
}
V_80 = V_2 -> V_17 [ 0 ] ;
V_296 = F_209 ( V_166 , V_80 ) ;
F_75 ( V_80 < 0 ) ;
if ( V_80 >= V_95 ) {
F_238 ( V_19 , V_166 ) ;
F_205 ( V_145 L_6 ,
V_80 , V_95 ) ;
F_75 ( 1 ) ;
}
for ( V_6 = V_80 ; V_6 < V_95 ; V_6 ++ ) {
T_4 V_270 ;
V_260 = F_202 ( V_166 , V_6 ) ;
V_270 = F_203 ( V_166 , V_260 , & V_251 ) ;
F_212 ( V_166 , V_260 ,
V_270 - V_254 , & V_251 ) ;
}
F_126 ( V_166 , F_210 ( V_166 ) +
V_262 - V_254 , F_210 ( V_166 ) +
V_262 , V_296 - V_262 ) ;
V_262 = V_296 ;
V_291 = F_218 ( V_166 , V_80 ) ;
V_260 = F_202 ( V_166 , V_80 ) ;
F_228 ( V_166 , V_260 , V_291 + V_254 ) ;
F_49 ( V_166 ) ;
if ( F_186 ( V_19 , V_166 ) < 0 ) {
F_238 ( V_19 , V_166 ) ;
F_172 () ;
}
}
void F_231 ( struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_149 * V_297 , T_4 * V_254 ,
T_4 V_298 , T_4 V_299 , int V_167 )
{
struct V_180 * V_260 ;
int V_6 ;
T_4 V_95 ;
unsigned int V_262 ;
struct V_36 V_37 ;
struct V_14 * V_166 ;
int V_80 ;
struct V_250 V_251 ;
F_201 ( & V_251 ) ;
V_166 = V_2 -> V_8 [ 0 ] ;
V_80 = V_2 -> V_17 [ 0 ] ;
V_95 = F_90 ( V_166 ) ;
V_262 = F_154 ( V_19 , V_166 ) ;
if ( F_186 ( V_19 , V_166 ) < V_299 ) {
F_238 ( V_19 , V_166 ) ;
F_205 ( V_145 L_7 ,
V_299 , F_186 ( V_19 , V_166 ) ) ;
F_172 () ;
}
if ( V_80 != V_95 ) {
unsigned int V_296 = F_209 ( V_166 , V_80 ) ;
if ( V_296 < V_262 ) {
F_238 ( V_19 , V_166 ) ;
F_205 ( V_145 L_8 ,
V_80 , V_296 , V_262 ) ;
F_75 ( 1 ) ;
}
for ( V_6 = V_80 ; V_6 < V_95 ; V_6 ++ ) {
T_4 V_270 ;
V_260 = F_202 ( V_166 , V_6 ) ;
V_270 = F_203 ( V_166 , V_260 , & V_251 ) ;
F_212 ( V_166 , V_260 ,
V_270 - V_298 , & V_251 ) ;
}
F_126 ( V_166 , F_211 ( V_80 + V_167 ) ,
F_211 ( V_80 ) ,
( V_95 - V_80 ) * sizeof( struct V_180 ) ) ;
F_126 ( V_166 , F_210 ( V_166 ) +
V_262 - V_298 , F_210 ( V_166 ) +
V_262 , V_296 - V_262 ) ;
V_262 = V_296 ;
}
for ( V_6 = 0 ; V_6 < V_167 ; V_6 ++ ) {
F_194 ( & V_37 , V_297 + V_6 ) ;
F_195 ( V_166 , & V_37 , V_80 + V_6 ) ;
V_260 = F_202 ( V_166 , V_80 + V_6 ) ;
F_212 ( V_166 , V_260 ,
V_262 - V_254 [ V_6 ] , & V_251 ) ;
V_262 -= V_254 [ V_6 ] ;
F_240 ( V_166 , V_260 , V_254 [ V_6 ] , & V_251 ) ;
}
F_127 ( V_166 , V_95 + V_167 ) ;
if ( V_80 == 0 ) {
F_194 ( & V_37 , V_297 ) ;
F_192 ( V_19 , V_2 , & V_37 , 1 ) ;
}
F_179 ( V_2 , 1 ) ;
F_49 ( V_166 ) ;
if ( F_186 ( V_19 , V_166 ) < 0 ) {
F_238 ( V_19 , V_166 ) ;
F_172 () ;
}
}
int F_241 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_149 * V_297 , T_4 * V_254 ,
int V_167 )
{
int V_34 = 0 ;
int V_80 ;
int V_6 ;
T_4 V_299 = 0 ;
T_4 V_298 = 0 ;
for ( V_6 = 0 ; V_6 < V_167 ; V_6 ++ )
V_298 += V_254 [ V_6 ] ;
V_299 = V_298 + ( V_167 * sizeof( struct V_180 ) ) ;
V_34 = F_183 ( V_29 , V_19 , V_297 , V_2 , V_299 , 1 ) ;
if ( V_34 == 0 )
return - V_75 ;
if ( V_34 < 0 )
return V_34 ;
V_80 = V_2 -> V_17 [ 0 ] ;
F_75 ( V_80 < 0 ) ;
F_231 ( V_19 , V_2 , V_297 , V_254 ,
V_298 , V_299 , V_167 ) ;
return 0 ;
}
int F_242 ( struct V_28 * V_29 , struct V_18
* V_19 , struct V_149 * V_297 , void * V_300 , T_4
V_254 )
{
int V_34 = 0 ;
struct V_1 * V_2 ;
struct V_14 * V_166 ;
unsigned long V_293 ;
V_2 = F_1 () ;
if ( ! V_2 )
return - V_79 ;
V_34 = F_243 ( V_29 , V_19 , V_2 , V_297 , V_254 ) ;
if ( ! V_34 ) {
V_166 = V_2 -> V_8 [ 0 ] ;
V_293 = F_226 ( V_166 , V_2 -> V_17 [ 0 ] ) ;
F_45 ( V_166 , V_300 , V_293 , V_254 ) ;
F_49 ( V_166 ) ;
}
F_8 ( V_2 ) ;
return V_34 ;
}
static void F_170 ( struct V_18 * V_19 , struct V_1 * V_2 ,
int V_35 , int V_80 )
{
struct V_14 * V_70 = V_2 -> V_8 [ V_35 ] ;
T_4 V_95 ;
int V_34 ;
V_95 = F_90 ( V_70 ) ;
if ( V_80 != V_95 - 1 ) {
if ( V_35 )
F_96 ( V_19 -> V_23 , V_70 , V_80 ,
V_80 + 1 , V_95 - V_80 - 1 ) ;
F_126 ( V_70 ,
F_125 ( V_80 ) ,
F_125 ( V_80 + 1 ) ,
sizeof( struct V_135 ) *
( V_95 - V_80 - 1 ) ) ;
} else if ( V_35 ) {
V_34 = F_86 ( V_19 -> V_23 , V_70 , V_80 ,
V_108 ) ;
F_75 ( V_34 < 0 ) ;
}
V_95 -- ;
F_127 ( V_70 , V_95 ) ;
if ( V_95 == 0 && V_70 == V_19 -> V_21 ) {
F_75 ( F_32 ( V_19 -> V_21 ) != 1 ) ;
F_130 ( V_19 -> V_21 , 0 ) ;
} else if ( V_80 == 0 ) {
struct V_36 V_37 ;
F_34 ( V_70 , & V_37 , 0 ) ;
F_192 ( V_19 , V_2 , & V_37 , V_35 + 1 ) ;
}
F_49 ( V_70 ) ;
}
static T_1 void F_244 ( struct V_28 * V_29 ,
struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_14 * V_166 )
{
F_31 ( F_47 ( V_166 ) != V_29 -> V_39 ) ;
F_170 ( V_19 , V_2 , 1 , V_2 -> V_17 [ 1 ] ) ;
F_179 ( V_2 , 0 ) ;
F_166 ( V_19 , V_166 -> V_42 ) ;
F_116 ( V_166 ) ;
F_118 ( V_29 , V_19 , V_166 , 0 , 1 ) ;
F_121 ( V_166 ) ;
}
int F_245 ( struct V_28 * V_29 , struct V_18 * V_19 ,
struct V_1 * V_2 , int V_80 , int V_167 )
{
struct V_14 * V_166 ;
struct V_180 * V_260 ;
int V_301 ;
int V_302 = 0 ;
int V_34 = 0 ;
int V_187 ;
int V_6 ;
T_4 V_95 ;
struct V_250 V_251 ;
F_201 ( & V_251 ) ;
V_166 = V_2 -> V_8 [ 0 ] ;
V_301 = F_156 ( V_166 , V_80 + V_167 - 1 ) ;
for ( V_6 = 0 ; V_6 < V_167 ; V_6 ++ )
V_302 += F_218 ( V_166 , V_80 + V_6 ) ;
V_95 = F_90 ( V_166 ) ;
if ( V_80 + V_167 != V_95 ) {
int V_262 = F_154 ( V_19 , V_166 ) ;
F_126 ( V_166 , F_210 ( V_166 ) +
V_262 + V_302 ,
F_210 ( V_166 ) + V_262 ,
V_301 - V_262 ) ;
for ( V_6 = V_80 + V_167 ; V_6 < V_95 ; V_6 ++ ) {
T_4 V_270 ;
V_260 = F_202 ( V_166 , V_6 ) ;
V_270 = F_203 ( V_166 , V_260 , & V_251 ) ;
F_212 ( V_166 , V_260 ,
V_270 + V_302 , & V_251 ) ;
}
F_126 ( V_166 , F_211 ( V_80 ) ,
F_211 ( V_80 + V_167 ) ,
sizeof( struct V_180 ) *
( V_95 - V_80 - V_167 ) ) ;
}
F_127 ( V_166 , V_95 - V_167 ) ;
V_95 -= V_167 ;
if ( V_95 == 0 ) {
if ( V_166 == V_19 -> V_21 ) {
F_130 ( V_166 , 0 ) ;
} else {
F_3 ( V_2 ) ;
F_111 ( V_29 , V_19 , V_166 ) ;
F_244 ( V_29 , V_19 , V_2 , V_166 ) ;
}
} else {
int V_303 = F_200 ( V_166 , 0 , V_95 ) ;
if ( V_80 == 0 ) {
struct V_36 V_37 ;
F_33 ( V_166 , & V_37 , 0 ) ;
F_192 ( V_19 , V_2 , & V_37 , 1 ) ;
}
if ( V_303 < F_155 ( V_19 ) / 3 ) {
V_80 = V_2 -> V_17 [ 1 ] ;
F_116 ( V_166 ) ;
F_3 ( V_2 ) ;
V_187 = F_215 ( V_29 , V_19 , V_2 , 1 , 1 ,
1 , ( T_4 ) - 1 ) ;
if ( V_187 < 0 && V_187 != - V_193 )
V_34 = V_187 ;
if ( V_2 -> V_8 [ 0 ] == V_166 &&
F_90 ( V_166 ) ) {
V_187 = F_213 ( V_29 , V_19 , V_2 , 1 ,
1 , 1 , 0 ) ;
if ( V_187 < 0 && V_187 != - V_193 )
V_34 = V_187 ;
}
if ( F_90 ( V_166 ) == 0 ) {
V_2 -> V_17 [ 1 ] = V_80 ;
F_244 ( V_29 , V_19 , V_2 , V_166 ) ;
F_12 ( V_166 ) ;
V_34 = 0 ;
} else {
if ( V_2 -> V_8 [ 0 ] == V_166 )
F_49 ( V_166 ) ;
F_12 ( V_166 ) ;
}
} else {
F_49 ( V_166 ) ;
}
}
return V_34 ;
}
int F_191 ( struct V_18 * V_19 , struct V_1 * V_2 )
{
struct V_149 V_85 ;
struct V_36 V_304 ;
int V_34 ;
F_220 ( V_2 -> V_8 [ 0 ] , & V_85 , 0 ) ;
if ( V_85 . V_152 > 0 )
V_85 . V_152 -- ;
else if ( V_85 . type > 0 )
V_85 . type -- ;
else if ( V_85 . V_119 > 0 )
V_85 . V_119 -- ;
else
return 1 ;
F_9 ( V_2 ) ;
V_34 = F_183 ( NULL , V_19 , & V_85 , V_2 , 0 , 0 ) ;
if ( V_34 < 0 )
return V_34 ;
F_33 ( V_2 -> V_8 [ 0 ] , & V_304 , 0 ) ;
V_34 = F_146 ( & V_304 , & V_85 ) ;
if ( V_34 < 0 )
return 0 ;
return 1 ;
}
int F_246 ( struct V_18 * V_19 , struct V_149 * V_305 ,
struct V_149 * V_306 ,
struct V_1 * V_2 ,
T_2 V_307 )
{
struct V_14 * V_71 ;
struct V_149 V_304 ;
int V_80 ;
int V_218 ;
T_4 V_95 ;
int V_35 ;
int V_34 = 1 ;
F_31 ( ! V_2 -> V_212 ) ;
V_219:
V_71 = F_22 ( V_19 ) ;
V_35 = F_32 ( V_71 ) ;
F_31 ( V_2 -> V_8 [ V_35 ] ) ;
V_2 -> V_8 [ V_35 ] = V_71 ;
V_2 -> V_9 [ V_35 ] = V_10 ;
if ( F_47 ( V_71 ) < V_307 ) {
V_34 = 1 ;
goto V_92;
}
while ( 1 ) {
V_95 = F_90 ( V_71 ) ;
V_35 = F_32 ( V_71 ) ;
V_218 = F_160 ( V_71 , V_305 , V_35 , & V_80 ) ;
if ( V_35 == V_2 -> V_222 ) {
if ( V_80 >= V_95 )
goto V_308;
V_34 = 0 ;
V_2 -> V_17 [ V_35 ] = V_80 ;
F_220 ( V_71 , & V_304 , V_80 ) ;
goto V_92;
}
if ( V_218 && V_80 > 0 )
V_80 -- ;
while ( V_80 < V_95 ) {
T_2 V_86 ;
T_2 V_156 ;
V_86 = F_83 ( V_71 , V_80 ) ;
V_156 = F_84 ( V_71 , V_80 ) ;
if ( V_156 < V_307 ) {
V_80 ++ ;
continue;
}
break;
}
V_308:
if ( V_80 >= V_95 ) {
V_2 -> V_17 [ V_35 ] = V_80 ;
F_3 ( V_2 ) ;
V_218 = F_247 ( V_19 , V_2 , V_305 , V_35 ,
V_307 ) ;
if ( V_218 == 0 ) {
F_9 ( V_2 ) ;
goto V_219;
} else {
goto V_92;
}
}
F_248 ( V_71 , & V_304 , V_80 ) ;
V_2 -> V_17 [ V_35 ] = V_80 ;
if ( V_35 == V_2 -> V_222 ) {
V_34 = 0 ;
F_178 ( V_2 , V_35 , 1 , 0 , NULL ) ;
goto V_92;
}
F_3 ( V_2 ) ;
V_71 = F_168 ( V_19 , V_71 , V_80 ) ;
F_75 ( ! V_71 ) ;
F_23 ( V_71 ) ;
V_2 -> V_9 [ V_35 - 1 ] = V_10 ;
V_2 -> V_8 [ V_35 - 1 ] = V_71 ;
F_178 ( V_2 , V_35 , 1 , 0 , NULL ) ;
F_5 ( V_2 , NULL , 0 ) ;
}
V_92:
if ( V_34 == 0 )
memcpy ( V_305 , & V_304 , sizeof( V_304 ) ) ;
F_3 ( V_2 ) ;
return V_34 ;
}
static void F_249 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int * V_35 , int V_309 )
{
F_75 ( * V_35 == 0 ) ;
V_2 -> V_8 [ * V_35 - 1 ] = F_168 ( V_19 , V_2 -> V_8 [ * V_35 ] ,
V_2 -> V_17 [ * V_35 ] ) ;
V_2 -> V_17 [ * V_35 - 1 ] = 0 ;
( * V_35 ) -- ;
}
static int F_250 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int * V_35 , int V_309 )
{
int V_34 = 0 ;
int V_95 ;
V_95 = F_90 ( V_2 -> V_8 [ * V_35 ] ) ;
V_2 -> V_17 [ * V_35 ] ++ ;
while ( V_2 -> V_17 [ * V_35 ] >= V_95 ) {
if ( * V_35 == V_309 )
return - 1 ;
V_2 -> V_17 [ * V_35 ] = 0 ;
F_12 ( V_2 -> V_8 [ * V_35 ] ) ;
V_2 -> V_8 [ * V_35 ] = NULL ;
( * V_35 ) ++ ;
V_2 -> V_17 [ * V_35 ] ++ ;
V_95 = F_90 ( V_2 -> V_8 [ * V_35 ] ) ;
V_34 = 1 ;
}
return V_34 ;
}
static int F_251 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
int * V_35 , int V_309 ,
int V_310 ,
struct V_149 * V_85 )
{
int V_34 ;
if ( * V_35 == 0 || ! V_310 ) {
V_34 = F_250 ( V_19 , V_2 , V_35 , V_309 ) ;
} else {
F_249 ( V_19 , V_2 , V_35 , V_309 ) ;
V_34 = 0 ;
}
if ( V_34 >= 0 ) {
if ( * V_35 == 0 )
F_220 ( V_2 -> V_8 [ * V_35 ] , V_85 ,
V_2 -> V_17 [ * V_35 ] ) ;
else
F_248 ( V_2 -> V_8 [ * V_35 ] , V_85 ,
V_2 -> V_17 [ * V_35 ] ) ;
}
return V_34 ;
}
static int F_252 ( struct V_18 * V_311 ,
struct V_1 * V_312 ,
struct V_1 * V_313 ,
char * V_314 )
{
int V_315 ;
int V_316 , V_317 ;
unsigned long V_318 , V_319 ;
V_316 = F_218 ( V_312 -> V_8 [ 0 ] , V_312 -> V_17 [ 0 ] ) ;
V_317 = F_218 ( V_313 -> V_8 [ 0 ] , V_313 -> V_17 [ 0 ] ) ;
if ( V_316 != V_317 )
return 1 ;
V_318 = F_226 ( V_312 -> V_8 [ 0 ] , V_312 -> V_17 [ 0 ] ) ;
V_319 = F_226 ( V_313 -> V_8 [ 0 ] ,
V_313 -> V_17 [ 0 ] ) ;
F_159 ( V_312 -> V_8 [ 0 ] , V_314 , V_318 , V_316 ) ;
V_315 = F_253 ( V_313 -> V_8 [ 0 ] , V_314 , V_319 , V_316 ) ;
if ( V_315 )
return 1 ;
return 0 ;
}
int F_254 ( struct V_18 * V_311 ,
struct V_18 * V_320 ,
T_6 V_321 , void * V_322 )
{
int V_34 ;
int V_315 ;
struct V_28 * V_29 = NULL ;
struct V_1 * V_312 = NULL ;
struct V_1 * V_313 = NULL ;
struct V_149 V_323 ;
struct V_149 V_194 ;
char * V_314 = NULL ;
int V_324 ;
int V_325 ;
int V_326 ;
int V_327 ;
int V_328 ;
int V_329 ;
int V_330 ;
int V_331 ;
T_2 V_332 ;
T_2 V_333 ;
T_2 V_334 ;
T_2 V_335 ;
T_2 V_336 ;
V_312 = F_1 () ;
if ( ! V_312 ) {
V_34 = - V_79 ;
goto V_92;
}
V_313 = F_1 () ;
if ( ! V_313 ) {
V_34 = - V_79 ;
goto V_92;
}
V_314 = F_225 ( V_311 -> V_279 , V_4 ) ;
if ( ! V_314 ) {
V_34 = - V_79 ;
goto V_92;
}
V_312 -> V_223 = 1 ;
V_312 -> V_224 = 1 ;
V_313 -> V_223 = 1 ;
V_313 -> V_224 = 1 ;
F_26 ( & V_311 -> V_337 ) ;
V_334 = F_255 ( & V_311 -> V_113 ) ;
F_29 ( & V_311 -> V_337 ) ;
F_26 ( & V_320 -> V_337 ) ;
V_335 = F_255 ( & V_320 -> V_113 ) ;
F_29 ( & V_320 -> V_337 ) ;
V_29 = F_256 ( V_311 ) ;
if ( F_36 ( V_29 ) ) {
V_34 = F_37 ( V_29 ) ;
V_29 = NULL ;
goto V_92;
}
V_326 = F_32 ( V_311 -> V_112 ) ;
V_324 = V_326 ;
V_312 -> V_8 [ V_326 ] = V_311 -> V_112 ;
F_116 ( V_312 -> V_8 [ V_326 ] ) ;
V_327 = F_32 ( V_320 -> V_112 ) ;
V_325 = V_327 ;
V_313 -> V_8 [ V_327 ] = V_320 -> V_112 ;
F_116 ( V_313 -> V_8 [ V_327 ] ) ;
if ( V_326 == 0 )
F_220 ( V_312 -> V_8 [ V_326 ] ,
& V_323 , V_312 -> V_17 [ V_326 ] ) ;
else
F_248 ( V_312 -> V_8 [ V_326 ] ,
& V_323 , V_312 -> V_17 [ V_326 ] ) ;
if ( V_327 == 0 )
F_220 ( V_313 -> V_8 [ V_327 ] ,
& V_194 , V_313 -> V_17 [ V_327 ] ) ;
else
F_248 ( V_313 -> V_8 [ V_327 ] ,
& V_194 , V_313 -> V_17 [ V_327 ] ) ;
V_328 = V_329 = 0 ;
V_330 = V_331 = 0 ;
while ( 1 ) {
if ( V_29 && F_257 ( V_29 , V_311 ) ) {
F_9 ( V_312 ) ;
F_9 ( V_313 ) ;
V_34 = F_258 ( V_29 , V_311 ) ;
V_29 = NULL ;
if ( V_34 < 0 )
goto V_92;
}
if ( ! V_29 ) {
V_29 = F_256 ( V_311 ) ;
if ( F_36 ( V_29 ) ) {
V_34 = F_37 ( V_29 ) ;
V_29 = NULL ;
goto V_92;
}
F_26 ( & V_311 -> V_337 ) ;
V_336 = F_255 ( & V_311 -> V_113 ) ;
F_29 ( & V_311 -> V_337 ) ;
if ( V_336 != V_334 )
V_334 = 0 ;
F_26 ( & V_320 -> V_337 ) ;
V_336 = F_255 ( & V_320 -> V_113 ) ;
F_29 ( & V_320 -> V_337 ) ;
if ( V_336 != V_335 )
V_335 = 0 ;
if ( ! V_334 || ! V_335 ) {
F_142 ( 1 , V_338
L_9
L_10
L_11
L_12 ) ;
V_34 = - V_165 ;
goto V_92;
}
V_312 -> V_222 = V_326 ;
V_313 -> V_222 = V_327 ;
V_34 = F_183 ( NULL , V_311 ,
& V_323 , V_312 , 0 , 0 ) ;
if ( V_34 < 0 )
goto V_92;
V_34 = F_183 ( NULL , V_320 ,
& V_194 , V_313 , 0 , 0 ) ;
if ( V_34 < 0 )
goto V_92;
}
if ( V_330 && ! V_328 ) {
V_34 = F_251 ( V_311 , V_312 , & V_326 ,
V_324 ,
V_330 != V_339 ,
& V_323 ) ;
if ( V_34 < 0 )
V_328 = V_340 ;
V_330 = 0 ;
}
if ( V_331 && ! V_329 ) {
V_34 = F_251 ( V_320 , V_313 , & V_327 ,
V_325 ,
V_331 != V_339 ,
& V_194 ) ;
if ( V_34 < 0 )
V_329 = V_340 ;
V_331 = 0 ;
}
if ( V_328 && V_329 ) {
V_34 = 0 ;
goto V_92;
} else if ( V_328 ) {
if ( V_327 == 0 ) {
V_34 = V_321 ( V_311 , V_320 ,
V_312 , V_313 ,
& V_194 ,
V_341 ,
V_322 ) ;
if ( V_34 < 0 )
goto V_92;
}
V_331 = V_340 ;
continue;
} else if ( V_329 ) {
if ( V_326 == 0 ) {
V_34 = V_321 ( V_311 , V_320 ,
V_312 , V_313 ,
& V_323 ,
V_342 ,
V_322 ) ;
if ( V_34 < 0 )
goto V_92;
}
V_330 = V_340 ;
continue;
}
if ( V_326 == 0 && V_327 == 0 ) {
V_315 = F_148 ( & V_323 , & V_194 ) ;
if ( V_315 < 0 ) {
V_34 = V_321 ( V_311 , V_320 ,
V_312 , V_313 ,
& V_323 ,
V_342 ,
V_322 ) ;
if ( V_34 < 0 )
goto V_92;
V_330 = V_340 ;
} else if ( V_315 > 0 ) {
V_34 = V_321 ( V_311 , V_320 ,
V_312 , V_313 ,
& V_194 ,
V_341 ,
V_322 ) ;
if ( V_34 < 0 )
goto V_92;
V_331 = V_340 ;
} else {
F_31 ( ! F_136 ( V_312 -> V_8 [ 0 ] ) ) ;
V_34 = F_252 ( V_311 , V_312 ,
V_313 , V_314 ) ;
if ( V_34 ) {
F_31 ( ! F_136 ( V_312 -> V_8 [ 0 ] ) ) ;
V_34 = V_321 ( V_311 , V_320 ,
V_312 , V_313 ,
& V_323 ,
V_343 ,
V_322 ) ;
if ( V_34 < 0 )
goto V_92;
}
V_330 = V_340 ;
V_331 = V_340 ;
}
} else if ( V_326 == V_327 ) {
V_315 = F_148 ( & V_323 , & V_194 ) ;
if ( V_315 < 0 ) {
V_330 = V_340 ;
} else if ( V_315 > 0 ) {
V_331 = V_340 ;
} else {
V_332 = F_83 (
V_312 -> V_8 [ V_326 ] ,
V_312 -> V_17 [ V_326 ] ) ;
V_333 = F_83 (
V_313 -> V_8 [ V_327 ] ,
V_313 -> V_17 [ V_327 ] ) ;
if ( V_332 == V_333 ) {
V_330 = V_339 ;
V_331 = V_339 ;
} else {
V_330 = V_340 ;
V_331 = V_340 ;
}
}
} else if ( V_326 < V_327 ) {
V_331 = V_340 ;
} else {
V_330 = V_340 ;
}
}
V_92:
F_8 ( V_312 ) ;
F_8 ( V_313 ) ;
F_73 ( V_314 ) ;
if ( V_29 ) {
if ( ! V_34 )
V_34 = F_258 ( V_29 , V_311 ) ;
else
F_258 ( V_29 , V_311 ) ;
}
return V_34 ;
}
int F_247 ( struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_149 * V_85 , int V_35 , T_2 V_307 )
{
int V_80 ;
struct V_14 * V_239 ;
F_31 ( ! V_2 -> V_212 ) ;
while ( V_35 < V_7 ) {
if ( ! V_2 -> V_8 [ V_35 ] )
return 1 ;
V_80 = V_2 -> V_17 [ V_35 ] + 1 ;
V_239 = V_2 -> V_8 [ V_35 ] ;
V_62:
if ( V_80 >= F_90 ( V_239 ) ) {
int V_34 ;
int V_344 ;
struct V_149 V_345 ;
if ( V_35 + 1 >= V_7 ||
! V_2 -> V_8 [ V_35 + 1 ] )
return 1 ;
if ( V_2 -> V_9 [ V_35 + 1 ] ) {
V_35 ++ ;
continue;
}
V_80 = F_90 ( V_239 ) - 1 ;
if ( V_35 == 0 )
F_220 ( V_239 , & V_345 , V_80 ) ;
else
F_248 ( V_239 , & V_345 , V_80 ) ;
V_344 = V_2 -> V_222 ;
F_9 ( V_2 ) ;
V_2 -> V_222 = V_35 ;
V_34 = F_183 ( NULL , V_19 , & V_345 , V_2 ,
0 , 0 ) ;
V_2 -> V_222 = V_344 ;
if ( V_34 < 0 )
return V_34 ;
V_239 = V_2 -> V_8 [ V_35 ] ;
V_80 = V_2 -> V_17 [ V_35 ] ;
if ( V_34 == 0 )
V_80 ++ ;
goto V_62;
}
if ( V_35 == 0 )
F_220 ( V_239 , V_85 , V_80 ) ;
else {
T_2 V_156 = F_84 ( V_239 , V_80 ) ;
if ( V_156 < V_307 ) {
V_80 ++ ;
goto V_62;
}
F_248 ( V_239 , V_85 , V_80 ) ;
}
return 0 ;
}
return 1 ;
}
int F_190 ( struct V_18 * V_19 , struct V_1 * V_2 )
{
return F_259 ( V_19 , V_2 , 0 ) ;
}
int F_259 ( struct V_18 * V_19 , struct V_1 * V_2 ,
T_2 V_127 )
{
int V_80 ;
int V_35 ;
struct V_14 * V_239 ;
struct V_14 * V_62 ;
struct V_149 V_85 ;
T_4 V_95 ;
int V_34 ;
int V_346 = V_2 -> V_227 ;
int V_347 = 0 ;
V_95 = F_90 ( V_2 -> V_8 [ 0 ] ) ;
if ( V_95 == 0 )
return 1 ;
F_220 ( V_2 -> V_8 [ 0 ] , & V_85 , V_95 - 1 ) ;
V_219:
V_35 = 1 ;
V_62 = NULL ;
V_347 = 0 ;
F_9 ( V_2 ) ;
V_2 -> V_212 = 1 ;
V_2 -> V_227 = 1 ;
if ( V_127 )
V_34 = F_188 ( V_19 , & V_85 , V_2 , V_127 ) ;
else
V_34 = F_183 ( NULL , V_19 , & V_85 , V_2 , 0 , 0 ) ;
V_2 -> V_212 = 0 ;
if ( V_34 < 0 )
return V_34 ;
V_95 = F_90 ( V_2 -> V_8 [ 0 ] ) ;
if ( V_95 > 0 && V_2 -> V_17 [ 0 ] < V_95 - 1 ) {
if ( V_34 == 0 )
V_2 -> V_17 [ 0 ] ++ ;
V_34 = 0 ;
goto V_220;
}
while ( V_35 < V_7 ) {
if ( ! V_2 -> V_8 [ V_35 ] ) {
V_34 = 1 ;
goto V_220;
}
V_80 = V_2 -> V_17 [ V_35 ] + 1 ;
V_239 = V_2 -> V_8 [ V_35 ] ;
if ( V_80 >= F_90 ( V_239 ) ) {
V_35 ++ ;
if ( V_35 == V_7 ) {
V_34 = 1 ;
goto V_220;
}
continue;
}
if ( V_62 ) {
F_11 ( V_62 , V_347 ) ;
F_12 ( V_62 ) ;
}
V_62 = V_239 ;
V_347 = V_2 -> V_9 [ V_35 ] ;
V_34 = F_180 ( NULL , V_19 , V_2 , & V_62 , V_35 ,
V_80 , & V_85 , 0 ) ;
if ( V_34 == - V_215 )
goto V_219;
if ( V_34 < 0 ) {
F_9 ( V_2 ) ;
goto V_220;
}
if ( ! V_2 -> V_224 ) {
V_34 = F_185 ( V_62 ) ;
if ( ! V_34 && V_127 ) {
F_12 ( V_62 ) ;
F_9 ( V_2 ) ;
F_260 () ;
goto V_219;
}
if ( ! V_34 ) {
F_3 ( V_2 ) ;
F_23 ( V_62 ) ;
F_5 ( V_2 , V_62 ,
V_10 ) ;
}
V_347 = V_10 ;
}
break;
}
V_2 -> V_17 [ V_35 ] = V_80 ;
while ( 1 ) {
V_35 -- ;
V_239 = V_2 -> V_8 [ V_35 ] ;
if ( V_2 -> V_9 [ V_35 ] )
F_11 ( V_239 , V_2 -> V_9 [ V_35 ] ) ;
F_12 ( V_239 ) ;
V_2 -> V_8 [ V_35 ] = V_62 ;
V_2 -> V_17 [ V_35 ] = 0 ;
if ( ! V_2 -> V_224 )
V_2 -> V_9 [ V_35 ] = V_347 ;
if ( ! V_35 )
break;
V_34 = F_180 ( NULL , V_19 , V_2 , & V_62 , V_35 ,
0 , & V_85 , 0 ) ;
if ( V_34 == - V_215 )
goto V_219;
if ( V_34 < 0 ) {
F_9 ( V_2 ) ;
goto V_220;
}
if ( ! V_2 -> V_224 ) {
V_34 = F_185 ( V_62 ) ;
if ( ! V_34 ) {
F_3 ( V_2 ) ;
F_23 ( V_62 ) ;
F_5 ( V_2 , V_62 ,
V_10 ) ;
}
V_347 = V_10 ;
}
}
V_34 = 0 ;
V_220:
F_178 ( V_2 , 0 , 1 , 0 , NULL ) ;
V_2 -> V_227 = V_346 ;
if ( ! V_346 )
F_3 ( V_2 ) ;
return V_34 ;
}
int F_261 ( struct V_18 * V_19 ,
struct V_1 * V_2 , T_2 V_348 ,
int type )
{
struct V_149 V_304 ;
struct V_14 * V_166 ;
T_4 V_95 ;
int V_34 ;
while ( 1 ) {
if ( V_2 -> V_17 [ 0 ] == 0 ) {
F_3 ( V_2 ) ;
V_34 = F_191 ( V_19 , V_2 ) ;
if ( V_34 != 0 )
return V_34 ;
} else {
V_2 -> V_17 [ 0 ] -- ;
}
V_166 = V_2 -> V_8 [ 0 ] ;
V_95 = F_90 ( V_166 ) ;
if ( V_95 == 0 )
return 1 ;
if ( V_2 -> V_17 [ 0 ] == V_95 )
V_2 -> V_17 [ 0 ] -- ;
F_220 ( V_166 , & V_304 , V_2 -> V_17 [ 0 ] ) ;
if ( V_304 . V_119 < V_348 )
break;
if ( V_304 . type == type )
return 0 ;
if ( V_304 . V_119 == V_348 &&
V_304 . type < type )
break;
}
return 1 ;
}
