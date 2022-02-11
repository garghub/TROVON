int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_3 * V_5 ;
struct V_6 * V_7 ;
struct V_6 * V_8 ;
int V_9 = 1 << V_10 ;
int V_11 ;
int V_12 ;
if ( V_2 -> V_13 )
return 0 ;
V_12 = sizeof( * V_4 ) + sizeof( * V_8 ) * V_9 ;
V_4 = F_2 ( V_12 , V_14 | V_15 | V_16 ) ;
if ( ! V_4 ) {
V_4 = F_3 ( V_12 ) ;
if ( ! V_4 )
return - V_17 ;
}
F_4 ( & V_4 -> V_18 ) ;
F_5 ( & V_4 -> V_19 ) ;
V_8 = V_4 -> V_4 ;
for ( V_11 = 0 ; V_11 < V_9 ; V_11 ++ ) {
V_7 = V_8 + V_11 ;
F_5 ( & V_7 -> V_20 ) ;
F_4 ( & V_7 -> V_21 ) ;
F_6 ( & V_7 -> V_22 ) ;
}
V_5 = F_7 ( & V_2 -> V_13 , NULL , V_4 ) ;
if ( V_5 ) {
if ( F_8 ( V_5 ) )
F_9 ( V_5 ) ;
else
F_10 ( V_5 ) ;
}
return 0 ;
}
static void F_11 ( struct V_23 * V_24 )
{
int V_11 ;
char * V_25 ;
char * V_26 ;
int V_27 ;
V_27 = F_12 ( V_24 ) ;
if ( V_27 )
return;
for ( V_11 = 0 ; V_11 < V_24 -> V_28 ; V_11 ++ ) {
if ( ! V_24 -> V_29 [ V_11 ] )
continue;
V_25 = F_13 ( V_24 -> V_29 [ V_11 ] ) ;
V_26 = F_13 ( V_24 -> V_30 [ V_11 ] ) ;
memcpy ( V_26 , V_25 , V_31 ) ;
F_14 ( V_24 -> V_29 [ V_11 ] ) ;
F_14 ( V_24 -> V_30 [ V_11 ] ) ;
F_15 ( V_24 -> V_30 [ V_11 ] ) ;
}
F_16 ( V_32 , & V_24 -> V_33 ) ;
}
static int F_17 ( struct V_23 * V_24 )
{
T_1 V_34 = V_24 -> V_35 [ 0 ] ;
return F_18 ( V_34 >> 16 , V_10 ) ;
}
static void F_19 ( struct V_23 * V_36 , struct V_23 * V_37 )
{
int V_11 ;
struct V_38 * V_25 ;
struct V_38 * V_26 ;
if ( ! F_20 ( V_32 , & V_36 -> V_33 ) )
return;
for ( V_11 = 0 ; V_11 < V_37 -> V_28 ; V_11 ++ ) {
V_25 = V_36 -> V_30 [ V_11 ] ;
if ( ! V_25 || ! F_21 ( V_25 ) ) {
continue;
}
V_26 = V_37 -> V_30 [ V_11 ] ;
if ( V_26 )
F_22 ( V_26 ) ;
V_37 -> V_30 [ V_11 ] = V_25 ;
V_36 -> V_30 [ V_11 ] = NULL ;
}
}
static void F_23 ( struct V_23 * V_37 ,
struct V_23 * V_39 )
{
F_24 ( & V_37 -> V_40 , & V_39 -> V_40 ) ;
V_37 -> V_41 += V_39 -> V_41 ;
V_37 -> V_42 += V_39 -> V_42 ;
F_25 ( & V_39 -> V_40 ) ;
}
static void F_26 ( struct V_23 * V_24 )
{
int V_43 = F_17 ( V_24 ) ;
struct V_3 * V_4 ;
struct V_6 * V_8 ;
int V_44 = 0 ;
if ( ! F_20 ( V_45 , & V_24 -> V_33 ) )
return;
V_4 = V_24 -> V_46 -> V_13 ;
V_8 = V_4 -> V_4 + V_43 ;
F_27 ( & V_8 -> V_21 ) ;
F_27 ( & V_24 -> V_47 ) ;
if ( F_28 ( V_45 , & V_24 -> V_33 ) ) {
F_29 ( & V_24 -> V_19 ) ;
V_4 -> V_48 -= 1 ;
V_44 = 1 ;
if ( F_30 ( & V_24 -> V_40 ) ) {
if ( ! F_31 ( & V_24 -> V_20 ) ) {
F_29 ( & V_24 -> V_20 ) ;
F_32 ( & V_24 -> V_49 ) ;
F_33 ( ! F_31 ( & V_24 -> V_50 ) ) ;
}
}
}
F_34 ( & V_24 -> V_47 ) ;
F_34 ( & V_8 -> V_21 ) ;
if ( V_44 )
F_35 ( V_24 ) ;
}
static void F_36 ( struct V_23 * V_24 )
{
struct V_3 * V_4 ;
unsigned long V_33 ;
if ( ! F_20 ( V_45 , & V_24 -> V_33 ) )
return;
V_4 = V_24 -> V_46 -> V_13 ;
F_37 ( & V_4 -> V_18 , V_33 ) ;
F_26 ( V_24 ) ;
F_38 ( & V_4 -> V_18 , V_33 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_33 ;
struct V_23 * V_24 ;
V_4 = V_2 -> V_13 ;
F_37 ( & V_4 -> V_18 , V_33 ) ;
while ( ! F_31 ( & V_4 -> V_19 ) ) {
V_24 = F_40 ( V_4 -> V_19 . V_51 ,
struct V_23 ,
V_19 ) ;
F_26 ( V_24 ) ;
}
F_38 ( & V_4 -> V_18 , V_33 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_13 )
return;
F_39 ( V_2 ) ;
if ( F_8 ( V_2 -> V_13 ) )
F_9 ( V_2 -> V_13 ) ;
else
F_10 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
}
static void F_42 ( struct V_23 * V_24 )
{
struct V_3 * V_4 ;
unsigned long V_33 ;
if ( ! F_20 ( V_32 , & V_24 -> V_33 ) )
return;
V_4 = V_24 -> V_46 -> V_13 ;
F_37 ( & V_4 -> V_18 , V_33 ) ;
F_27 ( & V_24 -> V_47 ) ;
if ( ! F_43 ( V_45 , & V_24 -> V_33 ) )
F_44 ( & V_24 -> V_49 ) ;
if ( ! F_31 ( & V_24 -> V_19 ) ) {
F_45 ( & V_24 -> V_19 , & V_4 -> V_19 ) ;
} else {
F_46 ( & V_24 -> V_19 , & V_4 -> V_19 ) ;
V_4 -> V_48 += 1 ;
}
F_34 ( & V_24 -> V_47 ) ;
if ( V_4 -> V_48 > V_52 ) {
struct V_23 * V_53 ;
V_53 = F_40 ( V_4 -> V_19 . V_54 ,
struct V_23 ,
V_19 ) ;
if ( V_53 != V_24 )
F_26 ( V_53 ) ;
}
F_38 ( & V_4 -> V_18 , V_33 ) ;
return;
}
static void F_47 ( void * * V_55 , int V_56 , T_2 V_57 )
{
int V_58 = 0 ;
int V_59 = 0 ;
void * V_37 = V_55 [ V_56 ] ;
while( V_56 > 0 ) {
V_59 = F_48 ( V_56 , V_60 ) ;
F_49 ( V_59 , V_57 , V_37 , V_55 + V_58 ) ;
V_56 -= V_59 ;
V_58 += V_59 ;
}
}
static int F_50 ( struct V_23 * V_24 )
{
unsigned long V_61 = V_24 -> V_41 ;
int V_27 = 1 ;
if ( V_61 != V_24 -> V_62 * V_24 -> V_63 )
V_27 = 0 ;
F_33 ( V_61 > V_24 -> V_62 * V_24 -> V_63 ) ;
return V_27 ;
}
static int F_51 ( struct V_23 * V_24 )
{
unsigned long V_33 ;
int V_27 ;
F_37 ( & V_24 -> V_47 , V_33 ) ;
V_27 = F_50 ( V_24 ) ;
F_38 ( & V_24 -> V_47 , V_33 ) ;
return V_27 ;
}
static int F_52 ( struct V_23 * V_64 ,
struct V_23 * V_7 )
{
if ( F_20 ( V_65 , & V_64 -> V_33 ) ||
F_20 ( V_65 , & V_7 -> V_33 ) )
return 0 ;
if ( F_20 ( V_45 , & V_64 -> V_33 ) ||
F_20 ( V_45 , & V_7 -> V_33 ) )
return 0 ;
if ( V_64 -> V_35 [ 0 ] !=
V_7 -> V_35 [ 0 ] )
return 0 ;
if ( V_64 -> V_66 != V_7 -> V_66 )
return 0 ;
if ( V_64 -> V_66 == V_67 ||
V_7 -> V_66 == V_67 )
return 0 ;
return 1 ;
}
static struct V_38 * F_53 ( struct V_23 * V_24 , int V_68 )
{
V_68 += ( V_24 -> V_62 * V_24 -> V_63 ) >> V_69 ;
return V_24 -> V_30 [ V_68 ] ;
}
static struct V_38 * F_54 ( struct V_23 * V_24 , int V_68 )
{
if ( V_24 -> V_62 + 1 == V_24 -> V_70 )
return NULL ;
V_68 += ( ( V_24 -> V_62 + 1 ) * V_24 -> V_63 ) >>
V_69 ;
return V_24 -> V_30 [ V_68 ] ;
}
static T_3 int F_55 ( struct V_23 * V_24 )
{
int V_43 = F_17 ( V_24 ) ;
struct V_6 * V_8 = V_24 -> V_46 -> V_13 -> V_4 + V_43 ;
struct V_23 * V_7 ;
struct V_23 * V_71 ;
unsigned long V_33 ;
F_56 ( V_22 ) ;
struct V_23 * V_44 = NULL ;
struct V_23 * V_72 = NULL ;
int V_27 = 0 ;
int V_73 = 0 ;
F_37 ( & V_8 -> V_21 , V_33 ) ;
F_57 (cur, &h->hash_list, hash_list) {
V_73 ++ ;
if ( V_7 -> V_35 [ 0 ] == V_24 -> V_35 [ 0 ] ) {
F_27 ( & V_7 -> V_47 ) ;
if ( F_30 ( & V_7 -> V_40 ) &&
F_31 ( & V_7 -> V_50 ) &&
F_20 ( V_45 , & V_7 -> V_33 ) &&
! F_20 ( V_65 , & V_7 -> V_33 ) ) {
F_29 ( & V_7 -> V_20 ) ;
F_32 ( & V_7 -> V_49 ) ;
F_19 ( V_7 , V_24 ) ;
V_72 = V_7 ;
F_34 ( & V_7 -> V_47 ) ;
goto V_74;
}
if ( F_52 ( V_7 , V_24 ) ) {
F_23 ( V_7 , V_24 ) ;
F_34 ( & V_7 -> V_47 ) ;
V_44 = V_24 ;
V_27 = 1 ;
goto V_75;
}
F_57 (pending, &cur->plug_list,
plug_list) {
if ( F_52 ( V_71 , V_24 ) ) {
F_23 ( V_71 , V_24 ) ;
F_34 ( & V_7 -> V_47 ) ;
V_44 = V_24 ;
V_27 = 1 ;
goto V_75;
}
}
F_58 ( & V_24 -> V_50 , & V_7 -> V_50 ) ;
F_34 ( & V_7 -> V_47 ) ;
V_27 = 1 ;
goto V_75;
}
}
V_74:
F_44 ( & V_24 -> V_49 ) ;
F_46 ( & V_24 -> V_20 , & V_8 -> V_20 ) ;
V_75:
F_38 ( & V_8 -> V_21 , V_33 ) ;
if ( V_72 )
F_36 ( V_72 ) ;
if ( V_44 )
F_35 ( V_44 ) ;
return V_27 ;
}
static T_3 void F_59 ( struct V_23 * V_24 )
{
int V_43 ;
struct V_6 * V_8 ;
unsigned long V_33 ;
int V_76 = 0 ;
V_43 = F_17 ( V_24 ) ;
V_8 = V_24 -> V_46 -> V_13 -> V_4 + V_43 ;
if ( F_31 ( & V_24 -> V_50 ) )
F_42 ( V_24 ) ;
F_37 ( & V_8 -> V_21 , V_33 ) ;
F_27 ( & V_24 -> V_47 ) ;
if ( ! F_31 ( & V_24 -> V_20 ) ) {
if ( F_31 ( & V_24 -> V_50 ) &&
F_20 ( V_45 , & V_24 -> V_33 ) ) {
V_76 = 1 ;
F_60 ( V_65 , & V_24 -> V_33 ) ;
F_33 ( ! F_30 ( & V_24 -> V_40 ) ) ;
goto V_77;
}
F_29 ( & V_24 -> V_20 ) ;
F_32 ( & V_24 -> V_49 ) ;
if ( ! F_31 ( & V_24 -> V_50 ) ) {
struct V_23 * V_51 ;
struct V_78 * V_79 = V_24 -> V_50 . V_51 ;
V_51 = F_40 ( V_79 , struct V_23 ,
V_50 ) ;
F_29 ( & V_24 -> V_50 ) ;
F_46 ( & V_51 -> V_20 , & V_8 -> V_20 ) ;
F_44 ( & V_51 -> V_49 ) ;
F_34 ( & V_24 -> V_47 ) ;
F_38 ( & V_8 -> V_21 , V_33 ) ;
if ( V_51 -> V_66 == V_80 )
F_61 ( V_51 ) ;
else if ( V_51 -> V_66 == V_81 ) {
F_19 ( V_24 , V_51 ) ;
F_62 ( V_51 ) ;
} else if ( V_51 -> V_66 == V_67 ) {
F_19 ( V_24 , V_51 ) ;
F_63 ( V_51 ) ;
}
goto V_82;
} else if ( F_64 ( & V_8 -> V_22 ) ) {
F_34 ( & V_24 -> V_47 ) ;
F_38 ( & V_8 -> V_21 , V_33 ) ;
F_65 ( & V_8 -> V_22 ) ;
goto V_82;
}
}
V_77:
F_34 ( & V_24 -> V_47 ) ;
F_38 ( & V_8 -> V_21 , V_33 ) ;
V_82:
if ( ! V_76 )
F_36 ( V_24 ) ;
}
static inline void
F_66 ( struct V_83 * V_84 , T_1 * V_35 , int V_85 )
{
if ( V_85 ) {
F_10 ( V_35 ) ;
F_10 ( V_84 ) ;
}
}
static inline void F_67 ( struct V_23 * V_24 )
{
F_66 ( V_24 -> V_84 , V_24 -> V_35 ,
! F_20 ( V_86 , & V_24 -> V_33 ) ) ;
}
static void F_35 ( struct V_23 * V_24 )
{
int V_11 ;
F_68 ( F_69 ( & V_24 -> V_49 ) < 0 ) ;
if ( ! F_70 ( & V_24 -> V_49 ) )
return;
F_68 ( ! F_31 ( & V_24 -> V_19 ) ) ;
F_68 ( ! F_31 ( & V_24 -> V_20 ) ) ;
F_68 ( ! F_30 ( & V_24 -> V_40 ) ) ;
for ( V_11 = 0 ; V_11 < V_24 -> V_28 ; V_11 ++ ) {
if ( V_24 -> V_30 [ V_11 ] ) {
F_22 ( V_24 -> V_30 [ V_11 ] ) ;
V_24 -> V_30 [ V_11 ] = NULL ;
}
}
F_67 ( V_24 ) ;
F_10 ( V_24 ) ;
}
static void F_71 ( struct V_23 * V_24 )
{
F_59 ( V_24 ) ;
F_35 ( V_24 ) ;
}
static void F_72 ( struct V_23 * V_24 , int V_87 , int V_88 )
{
struct V_89 * V_7 = F_73 ( & V_24 -> V_40 ) ;
struct V_89 * V_51 ;
if ( V_24 -> V_42 )
F_74 ( V_24 -> V_46 , V_24 -> V_42 ) ;
F_71 ( V_24 ) ;
while ( V_7 ) {
V_51 = V_7 -> V_90 ;
V_7 -> V_90 = NULL ;
if ( V_88 )
F_16 ( V_91 , & V_7 -> V_92 ) ;
F_75 ( V_7 , V_87 ) ;
V_7 = V_51 ;
}
}
static void F_76 ( struct V_89 * V_89 , int V_87 )
{
struct V_23 * V_24 = V_89 -> V_93 ;
if ( V_87 )
F_77 ( V_24 , V_89 ) ;
F_78 ( V_89 ) ;
if ( ! F_70 ( & V_24 -> V_94 ) )
return;
V_87 = 0 ;
if ( F_69 ( & V_24 -> error ) > V_24 -> V_84 -> V_95 )
V_87 = - V_96 ;
F_72 ( V_24 , V_87 , 0 ) ;
return;
}
static struct V_38 * F_79 ( struct V_23 * V_24 ,
int V_68 , int V_97 , int V_98 )
{
int V_99 ;
struct V_38 * V_100 = NULL ;
V_99 = V_68 * ( V_24 -> V_63 >> V_101 ) + V_97 ;
F_80 ( & V_24 -> V_47 ) ;
V_100 = V_24 -> V_29 [ V_99 ] ;
F_81 ( & V_24 -> V_47 ) ;
if ( V_100 || V_98 )
return V_100 ;
return V_24 -> V_30 [ V_99 ] ;
}
static unsigned long F_82 ( unsigned long V_63 , int V_102 )
{
unsigned long V_103 = V_63 * V_102 ;
return F_83 ( V_103 , V_31 ) ;
}
static struct V_23 * F_84 ( struct V_104 * V_105 ,
struct V_83 * V_84 , T_1 * V_35 ,
T_1 V_63 )
{
struct V_23 * V_24 ;
int V_62 = 0 ;
int V_70 = V_84 -> V_106 - V_84 -> V_107 ;
int V_108 = F_82 ( V_63 , V_70 ) ;
int V_109 = F_83 ( V_63 , V_110 ) ;
void * V_100 ;
V_24 = F_2 ( sizeof( * V_24 ) + V_108 * sizeof( struct V_38 * ) * 2 +
F_83 ( V_109 , V_111 / 8 ) ,
V_112 ) ;
if ( ! V_24 )
return F_85 ( - V_17 ) ;
F_25 ( & V_24 -> V_40 ) ;
F_5 ( & V_24 -> V_50 ) ;
F_4 ( & V_24 -> V_47 ) ;
F_5 ( & V_24 -> V_19 ) ;
F_5 ( & V_24 -> V_20 ) ;
V_24 -> V_84 = V_84 ;
V_24 -> V_35 = V_35 ;
V_24 -> V_46 = V_105 -> V_46 ;
V_24 -> V_63 = V_63 ;
V_24 -> V_28 = V_108 ;
V_24 -> V_70 = V_70 ;
V_24 -> V_109 = V_109 ;
V_24 -> V_113 = - 1 ;
V_24 -> V_114 = - 1 ;
F_86 ( & V_24 -> V_49 , 1 ) ;
F_86 ( & V_24 -> error , 0 ) ;
F_86 ( & V_24 -> V_94 , 0 ) ;
V_100 = V_24 + 1 ;
V_24 -> V_30 = V_100 ;
V_24 -> V_29 = V_100 + sizeof( struct V_38 * ) * V_108 ;
V_24 -> V_115 = V_100 + sizeof( struct V_38 * ) * V_108 * 2 ;
if ( V_35 [ V_70 - 1 ] == V_116 )
V_62 = V_70 - 2 ;
else
V_62 = V_70 - 1 ;
V_24 -> V_62 = V_62 ;
return V_24 ;
}
static int F_12 ( struct V_23 * V_24 )
{
int V_11 ;
struct V_38 * V_38 ;
for ( V_11 = 0 ; V_11 < V_24 -> V_28 ; V_11 ++ ) {
if ( V_24 -> V_30 [ V_11 ] )
continue;
V_38 = F_87 ( V_112 | V_117 ) ;
if ( ! V_38 )
return - V_17 ;
V_24 -> V_30 [ V_11 ] = V_38 ;
F_88 ( V_38 ) ;
}
return 0 ;
}
static int F_89 ( struct V_23 * V_24 )
{
int V_11 ;
struct V_38 * V_38 ;
V_11 = ( V_24 -> V_62 * V_24 -> V_63 ) >> V_69 ;
for (; V_11 < V_24 -> V_28 ; V_11 ++ ) {
if ( V_24 -> V_30 [ V_11 ] )
continue;
V_38 = F_87 ( V_112 | V_117 ) ;
if ( ! V_38 )
return - V_17 ;
V_24 -> V_30 [ V_11 ] = V_38 ;
}
return 0 ;
}
static int F_90 ( struct V_23 * V_24 ,
struct V_40 * V_40 ,
struct V_38 * V_38 ,
int V_118 ,
unsigned long V_119 ,
unsigned long V_120 )
{
struct V_89 * V_64 = V_40 -> V_121 ;
T_1 V_122 = 0 ;
int V_27 ;
struct V_89 * V_89 ;
struct V_123 * V_124 ;
T_1 V_125 ;
V_124 = & V_24 -> V_84 -> V_126 [ V_118 ] ;
V_125 = V_124 -> V_127 + ( V_119 << V_69 ) ;
if ( ! V_124 -> V_128 -> V_129 )
return F_91 ( V_24 , V_118 ) ;
if ( V_64 ) {
V_122 = ( T_1 ) V_64 -> V_130 . V_131 << 9 ;
V_122 += V_64 -> V_130 . V_132 ;
if ( V_122 == V_125 && V_124 -> V_128 -> V_129 &&
F_20 ( V_91 , & V_64 -> V_92 ) &&
V_64 -> V_133 == V_124 -> V_128 -> V_129 ) {
V_27 = F_92 ( V_64 , V_38 , V_31 , 0 ) ;
if ( V_27 == V_31 )
return 0 ;
}
}
V_89 = F_93 ( V_112 , V_120 >> V_101 ? : 1 ) ;
if ( ! V_89 )
return - V_17 ;
V_89 -> V_130 . V_132 = 0 ;
V_89 -> V_133 = V_124 -> V_128 -> V_129 ;
V_89 -> V_130 . V_131 = V_125 >> 9 ;
F_16 ( V_91 , & V_89 -> V_92 ) ;
F_92 ( V_89 , V_38 , V_31 , 0 ) ;
F_94 ( V_40 , V_89 ) ;
return 0 ;
}
static void F_95 ( struct V_23 * V_24 )
{
if ( V_24 -> V_113 >= 0 || V_24 -> V_114 >= 0 ) {
F_33 ( V_24 -> V_113 == V_24 -> V_70 - 1 ) ;
F_96 ( V_24 ) ;
} else {
F_97 ( V_24 ) ;
}
}
static struct V_38 * F_98 ( struct V_23 * V_24 , int V_124 , int V_38 )
{
int V_68 ;
V_68 = V_124 * ( V_24 -> V_63 >> V_69 ) ;
V_68 += V_38 ;
return V_24 -> V_30 [ V_68 ] ;
}
static void F_99 ( struct V_23 * V_24 )
{
struct V_89 * V_89 ;
T_1 V_134 ;
unsigned long V_135 ;
unsigned long V_119 ;
struct V_38 * V_100 ;
int V_11 ;
F_80 ( & V_24 -> V_47 ) ;
F_100 (bio, &rbio->bio_list) {
V_134 = ( T_1 ) V_89 -> V_130 . V_131 << 9 ;
V_135 = V_134 - V_24 -> V_35 [ 0 ] ;
V_119 = V_135 >> V_69 ;
for ( V_11 = 0 ; V_11 < V_89 -> V_136 ; V_11 ++ ) {
V_100 = V_89 -> V_137 [ V_11 ] . V_138 ;
V_24 -> V_29 [ V_119 + V_11 ] = V_100 ;
}
}
F_81 ( & V_24 -> V_47 ) ;
}
static T_3 void F_97 ( struct V_23 * V_24 )
{
struct V_83 * V_84 = V_24 -> V_84 ;
void * V_139 [ V_24 -> V_70 ] ;
int V_63 = V_24 -> V_63 ;
int V_62 = V_24 -> V_62 ;
int V_124 ;
int V_97 ;
int V_140 = - 1 ;
int V_141 = - 1 ;
struct V_40 V_40 ;
struct V_89 * V_89 ;
int V_142 = V_63 >> V_69 ;
int V_27 ;
F_25 ( & V_40 ) ;
if ( V_24 -> V_70 - V_24 -> V_62 == 1 ) {
V_140 = V_24 -> V_70 - 1 ;
} else if ( V_24 -> V_70 - V_24 -> V_62 == 2 ) {
V_140 = V_24 -> V_70 - 2 ;
V_141 = V_24 -> V_70 - 1 ;
} else {
F_101 () ;
}
F_80 ( & V_24 -> V_47 ) ;
F_16 ( V_65 , & V_24 -> V_33 ) ;
F_81 ( & V_24 -> V_47 ) ;
F_86 ( & V_24 -> error , 0 ) ;
F_99 ( V_24 ) ;
if ( ! F_51 ( V_24 ) )
F_11 ( V_24 ) ;
else
F_60 ( V_32 , & V_24 -> V_33 ) ;
for ( V_97 = 0 ; V_97 < V_142 ; V_97 ++ ) {
struct V_38 * V_100 ;
for ( V_124 = 0 ; V_124 < V_62 ; V_124 ++ ) {
V_100 = F_79 ( V_24 , V_124 , V_97 , 0 ) ;
V_139 [ V_124 ] = F_13 ( V_100 ) ;
}
V_100 = F_53 ( V_24 , V_97 ) ;
F_15 ( V_100 ) ;
V_139 [ V_124 ++ ] = F_13 ( V_100 ) ;
if ( V_141 != - 1 ) {
V_100 = F_54 ( V_24 , V_97 ) ;
F_15 ( V_100 ) ;
V_139 [ V_124 ++ ] = F_13 ( V_100 ) ;
V_143 . V_144 ( V_24 -> V_70 , V_110 ,
V_139 ) ;
} else {
memcpy ( V_139 [ V_62 ] , V_139 [ 0 ] , V_110 ) ;
F_47 ( V_139 + 1 , V_62 - 1 , V_31 ) ;
}
for ( V_124 = 0 ; V_124 < V_24 -> V_70 ; V_124 ++ )
F_14 ( F_79 ( V_24 , V_124 , V_97 , 0 ) ) ;
}
for ( V_124 = 0 ; V_124 < V_24 -> V_70 ; V_124 ++ ) {
for ( V_97 = 0 ; V_97 < V_142 ; V_97 ++ ) {
struct V_38 * V_38 ;
if ( V_124 < V_24 -> V_62 ) {
V_38 = F_79 ( V_24 , V_124 , V_97 , 1 ) ;
if ( ! V_38 )
continue;
} else {
V_38 = F_98 ( V_24 , V_124 , V_97 ) ;
}
V_27 = F_90 ( V_24 , & V_40 ,
V_38 , V_124 , V_97 , V_24 -> V_63 ) ;
if ( V_27 )
goto V_145;
}
}
if ( F_102 ( ! V_84 -> V_107 ) )
goto V_146;
for ( V_124 = 0 ; V_124 < V_24 -> V_70 ; V_124 ++ ) {
if ( ! V_84 -> V_147 [ V_124 ] )
continue;
for ( V_97 = 0 ; V_97 < V_142 ; V_97 ++ ) {
struct V_38 * V_38 ;
if ( V_124 < V_24 -> V_62 ) {
V_38 = F_79 ( V_24 , V_124 , V_97 , 1 ) ;
if ( ! V_38 )
continue;
} else {
V_38 = F_98 ( V_24 , V_124 , V_97 ) ;
}
V_27 = F_90 ( V_24 , & V_40 , V_38 ,
V_24 -> V_84 -> V_147 [ V_124 ] ,
V_97 , V_24 -> V_63 ) ;
if ( V_27 )
goto V_145;
}
}
V_146:
F_86 ( & V_24 -> V_94 , F_103 ( & V_40 ) ) ;
F_33 ( F_69 ( & V_24 -> V_94 ) == 0 ) ;
while ( 1 ) {
V_89 = F_104 ( & V_40 ) ;
if ( ! V_89 )
break;
V_89 -> V_93 = V_24 ;
V_89 -> V_148 = F_76 ;
F_33 ( ! F_20 ( V_91 , & V_89 -> V_92 ) ) ;
F_105 ( V_149 , V_89 ) ;
}
return;
V_145:
F_72 ( V_24 , - V_96 , 0 ) ;
}
static int F_106 ( struct V_23 * V_24 ,
struct V_89 * V_89 )
{
T_1 V_127 = V_89 -> V_130 . V_131 ;
T_1 V_150 ;
int V_11 ;
struct V_123 * V_124 ;
V_127 <<= 9 ;
for ( V_11 = 0 ; V_11 < V_24 -> V_84 -> V_106 ; V_11 ++ ) {
V_124 = & V_24 -> V_84 -> V_126 [ V_11 ] ;
V_150 = V_124 -> V_127 ;
if ( V_127 >= V_150 &&
V_127 < V_150 + V_24 -> V_63 &&
V_89 -> V_133 == V_124 -> V_128 -> V_129 ) {
return V_11 ;
}
}
return - 1 ;
}
static int F_107 ( struct V_23 * V_24 ,
struct V_89 * V_89 )
{
T_1 V_151 = V_89 -> V_130 . V_131 ;
T_1 V_150 ;
int V_11 ;
V_151 <<= 9 ;
for ( V_11 = 0 ; V_11 < V_24 -> V_62 ; V_11 ++ ) {
V_150 = V_24 -> V_35 [ V_11 ] ;
if ( V_151 >= V_150 &&
V_151 < V_150 + V_24 -> V_63 ) {
return V_11 ;
}
}
return - 1 ;
}
static int F_91 ( struct V_23 * V_24 , int V_152 )
{
unsigned long V_33 ;
int V_27 = 0 ;
F_37 ( & V_24 -> V_47 , V_33 ) ;
if ( V_24 -> V_113 == V_152 || V_24 -> V_114 == V_152 )
goto V_75;
if ( V_24 -> V_113 == - 1 ) {
V_24 -> V_113 = V_152 ;
F_44 ( & V_24 -> error ) ;
} else if ( V_24 -> V_114 == - 1 ) {
V_24 -> V_114 = V_152 ;
F_44 ( & V_24 -> error ) ;
} else {
V_27 = - V_96 ;
}
V_75:
F_38 ( & V_24 -> V_47 , V_33 ) ;
return V_27 ;
}
static int F_77 ( struct V_23 * V_24 ,
struct V_89 * V_89 )
{
int V_152 = F_106 ( V_24 , V_89 ) ;
if ( V_152 < 0 )
return - V_96 ;
return F_91 ( V_24 , V_152 ) ;
}
static void F_108 ( struct V_89 * V_89 )
{
int V_11 ;
struct V_38 * V_100 ;
for ( V_11 = 0 ; V_11 < V_89 -> V_136 ; V_11 ++ ) {
V_100 = V_89 -> V_137 [ V_11 ] . V_138 ;
F_15 ( V_100 ) ;
}
}
static void F_109 ( struct V_89 * V_89 , int V_87 )
{
struct V_23 * V_24 = V_89 -> V_93 ;
if ( V_87 )
F_77 ( V_24 , V_89 ) ;
else
F_108 ( V_89 ) ;
F_78 ( V_89 ) ;
if ( ! F_70 ( & V_24 -> V_94 ) )
return;
V_87 = 0 ;
if ( F_69 ( & V_24 -> error ) > V_24 -> V_84 -> V_95 )
goto V_145;
F_95 ( V_24 ) ;
return;
V_145:
F_72 ( V_24 , - V_96 , 0 ) ;
}
static void F_62 ( struct V_23 * V_24 )
{
F_110 ( & V_24 -> V_153 , V_154 ,
V_155 , NULL , NULL ) ;
F_111 ( V_24 -> V_46 -> V_156 ,
& V_24 -> V_153 ) ;
}
static void F_61 ( struct V_23 * V_24 )
{
F_110 ( & V_24 -> V_153 , V_154 ,
V_157 , NULL , NULL ) ;
F_111 ( V_24 -> V_46 -> V_156 ,
& V_24 -> V_153 ) ;
}
static int F_112 ( struct V_23 * V_24 )
{
int V_158 = 0 ;
struct V_40 V_40 ;
int V_27 ;
int V_28 = F_83 ( V_24 -> V_63 , V_31 ) ;
int V_97 ;
int V_124 ;
struct V_89 * V_89 ;
F_25 ( & V_40 ) ;
V_27 = F_12 ( V_24 ) ;
if ( V_27 )
goto V_145;
F_99 ( V_24 ) ;
F_86 ( & V_24 -> error , 0 ) ;
for ( V_124 = 0 ; V_124 < V_24 -> V_62 ; V_124 ++ ) {
for ( V_97 = 0 ; V_97 < V_28 ; V_97 ++ ) {
struct V_38 * V_38 ;
V_38 = F_79 ( V_24 , V_124 , V_97 , 1 ) ;
if ( V_38 )
continue;
V_38 = F_98 ( V_24 , V_124 , V_97 ) ;
if ( F_21 ( V_38 ) )
continue;
V_27 = F_90 ( V_24 , & V_40 , V_38 ,
V_124 , V_97 , V_24 -> V_63 ) ;
if ( V_27 )
goto V_145;
}
}
V_158 = F_103 ( & V_40 ) ;
if ( ! V_158 ) {
goto V_159;
}
F_86 ( & V_24 -> V_94 , V_158 ) ;
while ( 1 ) {
V_89 = F_104 ( & V_40 ) ;
if ( ! V_89 )
break;
V_89 -> V_93 = V_24 ;
V_89 -> V_148 = F_109 ;
F_113 ( V_24 -> V_46 , V_89 ,
V_160 ) ;
F_33 ( ! F_20 ( V_91 , & V_89 -> V_92 ) ) ;
F_105 ( V_161 , V_89 ) ;
}
return 0 ;
V_145:
F_72 ( V_24 , - V_96 , 0 ) ;
return - V_96 ;
V_159:
F_95 ( V_24 ) ;
return 0 ;
}
static int F_114 ( struct V_23 * V_24 )
{
int V_27 ;
V_27 = F_89 ( V_24 ) ;
if ( V_27 ) {
F_35 ( V_24 ) ;
return V_27 ;
}
V_27 = F_55 ( V_24 ) ;
if ( V_27 == 0 )
F_97 ( V_24 ) ;
return 0 ;
}
static int F_115 ( struct V_23 * V_24 )
{
int V_27 ;
V_27 = F_55 ( V_24 ) ;
if ( V_27 == 0 )
F_62 ( V_24 ) ;
return 0 ;
}
static int F_116 ( struct V_23 * V_24 )
{
if ( ! F_51 ( V_24 ) )
return F_115 ( V_24 ) ;
return F_114 ( V_24 ) ;
}
static int F_117 ( void * V_162 , struct V_78 * V_163 , struct V_78 * V_164 )
{
struct V_23 * V_165 = F_118 ( V_163 , struct V_23 ,
V_50 ) ;
struct V_23 * V_166 = F_118 ( V_164 , struct V_23 ,
V_50 ) ;
T_1 V_167 = V_165 -> V_40 . V_79 -> V_130 . V_131 ;
T_1 V_168 = V_166 -> V_40 . V_79 -> V_130 . V_131 ;
if ( V_167 < V_168 )
return - 1 ;
if ( V_167 > V_168 )
return 1 ;
return 0 ;
}
static void F_119 ( struct V_169 * V_170 )
{
struct V_23 * V_7 ;
struct V_23 * V_64 = NULL ;
F_120 ( NULL , & V_170 -> V_171 , F_117 ) ;
while ( ! F_31 ( & V_170 -> V_171 ) ) {
V_7 = F_40 ( V_170 -> V_171 . V_51 ,
struct V_23 , V_50 ) ;
F_29 ( & V_7 -> V_50 ) ;
if ( F_51 ( V_7 ) ) {
F_114 ( V_7 ) ;
continue;
}
if ( V_64 ) {
if ( F_52 ( V_64 , V_7 ) ) {
F_23 ( V_64 , V_7 ) ;
F_35 ( V_7 ) ;
continue;
}
F_116 ( V_64 ) ;
}
V_64 = V_7 ;
}
if ( V_64 ) {
F_116 ( V_64 ) ;
}
F_10 ( V_170 ) ;
}
static void F_121 ( struct V_172 * V_153 )
{
struct V_169 * V_170 ;
V_170 = F_118 ( V_153 , struct V_169 , V_153 ) ;
F_119 ( V_170 ) ;
}
static void F_122 ( struct V_173 * V_174 , bool V_175 )
{
struct V_169 * V_170 ;
V_170 = F_118 ( V_174 , struct V_169 , V_174 ) ;
if ( V_175 ) {
F_110 ( & V_170 -> V_153 , V_154 ,
F_121 , NULL , NULL ) ;
F_111 ( V_170 -> V_2 -> V_156 ,
& V_170 -> V_153 ) ;
return;
}
F_119 ( V_170 ) ;
}
int F_123 ( struct V_104 * V_105 , struct V_89 * V_89 ,
struct V_83 * V_84 , T_1 * V_35 ,
T_1 V_63 )
{
struct V_23 * V_24 ;
struct V_169 * V_170 = NULL ;
struct V_173 * V_174 ;
int V_27 ;
V_24 = F_84 ( V_105 , V_84 , V_35 , V_63 ) ;
if ( F_124 ( V_24 ) ) {
F_66 ( V_84 , V_35 , 1 ) ;
return F_125 ( V_24 ) ;
}
F_94 ( & V_24 -> V_40 , V_89 ) ;
V_24 -> V_41 = V_89 -> V_130 . V_132 ;
V_24 -> V_66 = V_81 ;
F_126 ( V_105 -> V_46 ) ;
V_24 -> V_42 = 1 ;
if ( F_51 ( V_24 ) ) {
V_27 = F_114 ( V_24 ) ;
if ( V_27 )
F_127 ( V_105 -> V_46 ) ;
return V_27 ;
}
V_174 = F_128 ( F_122 , V_105 -> V_46 ,
sizeof( * V_170 ) ) ;
if ( V_174 ) {
V_170 = F_118 ( V_174 , struct V_169 , V_174 ) ;
if ( ! V_170 -> V_2 ) {
V_170 -> V_2 = V_105 -> V_46 ;
F_5 ( & V_170 -> V_171 ) ;
}
F_58 ( & V_24 -> V_50 , & V_170 -> V_171 ) ;
V_27 = 0 ;
} else {
V_27 = F_116 ( V_24 ) ;
if ( V_27 )
F_127 ( V_105 -> V_46 ) ;
}
return V_27 ;
}
static void F_129 ( struct V_23 * V_24 )
{
int V_97 , V_124 ;
void * * V_139 ;
int V_113 = - 1 , V_114 = - 1 ;
int V_28 = F_83 ( V_24 -> V_63 , V_31 ) ;
struct V_38 * V_38 ;
int V_87 ;
int V_11 ;
V_139 = F_2 ( V_24 -> V_70 * sizeof( void * ) ,
V_112 ) ;
if ( ! V_139 ) {
V_87 = - V_17 ;
goto V_176;
}
V_113 = V_24 -> V_113 ;
V_114 = V_24 -> V_114 ;
if ( V_24 -> V_66 == V_80 ) {
F_80 ( & V_24 -> V_47 ) ;
F_16 ( V_65 , & V_24 -> V_33 ) ;
F_81 ( & V_24 -> V_47 ) ;
}
F_99 ( V_24 ) ;
for ( V_97 = 0 ; V_97 < V_28 ; V_97 ++ ) {
if ( V_24 -> V_66 == V_67 &&
! F_20 ( V_97 , V_24 -> V_115 ) )
continue;
for ( V_124 = 0 ; V_124 < V_24 -> V_70 ; V_124 ++ ) {
if ( V_24 -> V_66 == V_80 &&
( V_124 == V_113 || V_124 == V_114 ) ) {
V_38 = F_79 ( V_24 , V_124 , V_97 , 0 ) ;
} else {
V_38 = F_98 ( V_24 , V_124 , V_97 ) ;
}
V_139 [ V_124 ] = F_13 ( V_38 ) ;
}
if ( V_24 -> V_35 [ V_24 -> V_70 - 1 ] ==
V_116 ) {
if ( V_114 < 0 ) {
if ( V_113 == V_24 -> V_62 ) {
V_87 = - V_96 ;
goto V_145;
}
goto V_177;
}
if ( V_113 > V_114 ) {
int V_178 = V_114 ;
V_114 = V_113 ;
V_113 = V_178 ;
}
if ( V_24 -> V_35 [ V_114 ] == V_116 ) {
if ( V_24 -> V_35 [ V_113 ] == V_179 ) {
V_87 = - V_96 ;
goto V_145;
}
goto V_177;
}
if ( V_24 -> V_35 [ V_114 ] == V_179 ) {
F_130 ( V_24 -> V_70 ,
V_110 , V_113 , V_139 ) ;
} else {
F_131 ( V_24 -> V_70 ,
V_110 , V_113 , V_114 ,
V_139 ) ;
}
} else {
void * V_100 ;
F_33 ( V_114 != - 1 ) ;
V_177:
memcpy ( V_139 [ V_113 ] ,
V_139 [ V_24 -> V_62 ] ,
V_31 ) ;
V_100 = V_139 [ V_113 ] ;
for ( V_124 = V_113 ; V_124 < V_24 -> V_62 - 1 ; V_124 ++ )
V_139 [ V_124 ] = V_139 [ V_124 + 1 ] ;
V_139 [ V_24 -> V_62 - 1 ] = V_100 ;
F_47 ( V_139 , V_24 -> V_62 - 1 , V_31 ) ;
}
if ( V_24 -> V_66 == V_81 ) {
for ( V_11 = 0 ; V_11 < V_28 ; V_11 ++ ) {
if ( V_113 != - 1 ) {
V_38 = F_98 ( V_24 , V_113 , V_11 ) ;
F_15 ( V_38 ) ;
}
if ( V_114 != - 1 ) {
V_38 = F_98 ( V_24 , V_114 , V_11 ) ;
F_15 ( V_38 ) ;
}
}
}
for ( V_124 = 0 ; V_124 < V_24 -> V_70 ; V_124 ++ ) {
if ( V_24 -> V_66 == V_80 &&
( V_124 == V_113 || V_124 == V_114 ) ) {
V_38 = F_79 ( V_24 , V_124 , V_97 , 0 ) ;
} else {
V_38 = F_98 ( V_24 , V_124 , V_97 ) ;
}
F_14 ( V_38 ) ;
}
}
V_87 = 0 ;
V_145:
F_10 ( V_139 ) ;
V_176:
if ( V_24 -> V_66 == V_80 ) {
if ( V_87 == 0 &&
! F_20 ( V_86 , & V_24 -> V_33 ) )
F_11 ( V_24 ) ;
else
F_60 ( V_32 , & V_24 -> V_33 ) ;
F_72 ( V_24 , V_87 , V_87 == 0 ) ;
} else if ( V_87 == 0 ) {
V_24 -> V_113 = - 1 ;
V_24 -> V_114 = - 1 ;
if ( V_24 -> V_66 == V_81 )
F_97 ( V_24 ) ;
else if ( V_24 -> V_66 == V_67 )
F_132 ( V_24 , 0 ) ;
else
F_101 () ;
} else {
F_72 ( V_24 , V_87 , 0 ) ;
}
}
static void F_133 ( struct V_89 * V_89 , int V_87 )
{
struct V_23 * V_24 = V_89 -> V_93 ;
if ( V_87 )
F_77 ( V_24 , V_89 ) ;
else
F_108 ( V_89 ) ;
F_78 ( V_89 ) ;
if ( ! F_70 ( & V_24 -> V_94 ) )
return;
if ( F_69 ( & V_24 -> error ) > V_24 -> V_84 -> V_95 )
F_72 ( V_24 , - V_96 , 0 ) ;
else
F_129 ( V_24 ) ;
}
static int F_96 ( struct V_23 * V_24 )
{
int V_158 = 0 ;
struct V_40 V_40 ;
int V_27 ;
int V_28 = F_83 ( V_24 -> V_63 , V_31 ) ;
int V_97 ;
int V_124 ;
struct V_89 * V_89 ;
F_25 ( & V_40 ) ;
V_27 = F_12 ( V_24 ) ;
if ( V_27 )
goto V_145;
F_86 ( & V_24 -> error , 0 ) ;
for ( V_124 = 0 ; V_124 < V_24 -> V_70 ; V_124 ++ ) {
if ( V_24 -> V_113 == V_124 || V_24 -> V_114 == V_124 ) {
F_44 ( & V_24 -> error ) ;
continue;
}
for ( V_97 = 0 ; V_97 < V_28 ; V_97 ++ ) {
struct V_38 * V_100 ;
V_100 = F_98 ( V_24 , V_124 , V_97 ) ;
if ( F_21 ( V_100 ) )
continue;
V_27 = F_90 ( V_24 , & V_40 ,
F_98 ( V_24 , V_124 , V_97 ) ,
V_124 , V_97 , V_24 -> V_63 ) ;
if ( V_27 < 0 )
goto V_145;
}
}
V_158 = F_103 ( & V_40 ) ;
if ( ! V_158 ) {
if ( F_69 ( & V_24 -> error ) <= V_24 -> V_84 -> V_95 ) {
F_129 ( V_24 ) ;
goto V_75;
} else {
goto V_145;
}
}
F_86 ( & V_24 -> V_94 , V_158 ) ;
while ( 1 ) {
V_89 = F_104 ( & V_40 ) ;
if ( ! V_89 )
break;
V_89 -> V_93 = V_24 ;
V_89 -> V_148 = F_133 ;
F_113 ( V_24 -> V_46 , V_89 ,
V_160 ) ;
F_33 ( ! F_20 ( V_91 , & V_89 -> V_92 ) ) ;
F_105 ( V_161 , V_89 ) ;
}
V_75:
return 0 ;
V_145:
if ( V_24 -> V_66 == V_80 )
F_72 ( V_24 , - V_96 , 0 ) ;
return - V_96 ;
}
int F_134 ( struct V_104 * V_105 , struct V_89 * V_89 ,
struct V_83 * V_84 , T_1 * V_35 ,
T_1 V_63 , int V_180 , int V_181 )
{
struct V_23 * V_24 ;
int V_27 ;
V_24 = F_84 ( V_105 , V_84 , V_35 , V_63 ) ;
if ( F_124 ( V_24 ) ) {
F_66 ( V_84 , V_35 , V_181 ) ;
return F_125 ( V_24 ) ;
}
V_24 -> V_66 = V_80 ;
F_94 ( & V_24 -> V_40 , V_89 ) ;
V_24 -> V_41 = V_89 -> V_130 . V_132 ;
V_24 -> V_113 = F_107 ( V_24 , V_89 ) ;
if ( V_24 -> V_113 == - 1 ) {
F_101 () ;
F_66 ( V_84 , V_35 , V_181 ) ;
F_10 ( V_24 ) ;
return - V_96 ;
}
if ( V_181 ) {
F_126 ( V_105 -> V_46 ) ;
V_24 -> V_42 = 1 ;
} else {
F_16 ( V_86 , & V_24 -> V_33 ) ;
}
if ( V_180 == 3 )
V_24 -> V_114 = V_24 -> V_70 - 2 ;
V_27 = F_55 ( V_24 ) ;
if ( V_27 == 0 )
F_96 ( V_24 ) ;
return 0 ;
}
static void V_155 ( struct V_172 * V_153 )
{
struct V_23 * V_24 ;
V_24 = F_118 ( V_153 , struct V_23 , V_153 ) ;
F_112 ( V_24 ) ;
}
static void V_157 ( struct V_172 * V_153 )
{
struct V_23 * V_24 ;
V_24 = F_118 ( V_153 , struct V_23 , V_153 ) ;
F_96 ( V_24 ) ;
}
struct V_23 *
F_135 ( struct V_104 * V_105 , struct V_89 * V_89 ,
struct V_83 * V_84 , T_1 * V_35 ,
T_1 V_63 , struct V_182 * V_183 ,
unsigned long * V_115 , int V_184 )
{
struct V_23 * V_24 ;
int V_11 ;
V_24 = F_84 ( V_105 , V_84 , V_35 , V_63 ) ;
if ( F_124 ( V_24 ) )
return NULL ;
F_94 ( & V_24 -> V_40 , V_89 ) ;
ASSERT ( ! V_89 -> V_130 . V_132 ) ;
V_24 -> V_66 = V_67 ;
for ( V_11 = 0 ; V_11 < V_24 -> V_70 ; V_11 ++ ) {
if ( V_84 -> V_126 [ V_11 ] . V_128 == V_183 ) {
V_24 -> V_185 = V_11 ;
break;
}
}
ASSERT ( V_105 -> V_186 == V_110 ) ;
ASSERT ( V_24 -> V_109 == V_184 ) ;
F_136 ( V_24 -> V_115 , V_115 , V_184 ) ;
return V_24 ;
}
void F_137 ( struct V_23 * V_24 ,
struct V_38 * V_38 , T_1 V_151 )
{
int V_135 ;
int V_68 ;
ASSERT ( V_151 >= V_24 -> V_35 [ 0 ] ) ;
ASSERT ( V_151 + V_110 <= V_24 -> V_35 [ 0 ] +
V_24 -> V_63 * V_24 -> V_62 ) ;
V_135 = ( int ) ( V_151 - V_24 -> V_35 [ 0 ] ) ;
V_68 = V_135 >> V_69 ;
V_24 -> V_29 [ V_68 ] = V_38 ;
}
static int F_138 ( struct V_23 * V_24 )
{
int V_11 ;
int V_187 ;
int V_68 ;
struct V_38 * V_38 ;
F_139 (bit, rbio->dbitmap, rbio->stripe_npages) {
for ( V_11 = 0 ; V_11 < V_24 -> V_70 ; V_11 ++ ) {
V_68 = V_11 * V_24 -> V_109 + V_187 ;
if ( V_24 -> V_30 [ V_68 ] )
continue;
V_38 = F_87 ( V_112 | V_117 ) ;
if ( ! V_38 )
return - V_17 ;
V_24 -> V_30 [ V_68 ] = V_38 ;
F_88 ( V_38 ) ;
}
}
return 0 ;
}
static void F_140 ( struct V_89 * V_89 , int V_87 )
{
struct V_23 * V_24 = V_89 -> V_93 ;
if ( V_87 )
F_77 ( V_24 , V_89 ) ;
F_78 ( V_89 ) ;
if ( ! F_70 ( & V_24 -> V_94 ) )
return;
V_87 = 0 ;
if ( F_69 ( & V_24 -> error ) )
V_87 = - V_96 ;
F_72 ( V_24 , V_87 , 0 ) ;
}
static T_3 void F_132 ( struct V_23 * V_24 ,
int V_188 )
{
struct V_83 * V_84 = V_24 -> V_84 ;
void * V_139 [ V_24 -> V_70 ] ;
F_141 ( V_189 , V_24 -> V_109 ) ;
int V_62 = V_24 -> V_62 ;
int V_124 ;
int V_97 ;
int V_140 = - 1 ;
int V_141 = - 1 ;
struct V_38 * V_190 = NULL ;
struct V_38 * V_191 = NULL ;
struct V_40 V_40 ;
struct V_89 * V_89 ;
int V_192 = 0 ;
int V_27 ;
F_25 ( & V_40 ) ;
if ( V_24 -> V_70 - V_24 -> V_62 == 1 ) {
V_140 = V_24 -> V_70 - 1 ;
} else if ( V_24 -> V_70 - V_24 -> V_62 == 2 ) {
V_140 = V_24 -> V_70 - 2 ;
V_141 = V_24 -> V_70 - 1 ;
} else {
F_101 () ;
}
if ( V_84 -> V_107 && V_84 -> V_147 [ V_24 -> V_185 ] ) {
V_192 = 1 ;
F_136 ( V_189 , V_24 -> V_115 , V_24 -> V_109 ) ;
}
F_60 ( V_32 , & V_24 -> V_33 ) ;
if ( ! V_188 )
goto V_193;
V_190 = F_87 ( V_112 | V_117 ) ;
if ( ! V_190 )
goto V_145;
F_15 ( V_190 ) ;
if ( V_141 != - 1 ) {
V_191 = F_87 ( V_112 | V_117 ) ;
if ( ! V_191 ) {
F_22 ( V_190 ) ;
goto V_145;
}
F_15 ( V_191 ) ;
}
F_86 ( & V_24 -> error , 0 ) ;
F_139 (pagenr, rbio->dbitmap, rbio->stripe_npages) {
struct V_38 * V_100 ;
void * V_194 ;
for ( V_124 = 0 ; V_124 < V_62 ; V_124 ++ ) {
V_100 = F_79 ( V_24 , V_124 , V_97 , 0 ) ;
V_139 [ V_124 ] = F_13 ( V_100 ) ;
}
V_139 [ V_124 ++ ] = F_13 ( V_190 ) ;
if ( V_141 != - 1 ) {
V_139 [ V_124 ++ ] = F_13 ( V_191 ) ;
V_143 . V_144 ( V_24 -> V_70 , V_110 ,
V_139 ) ;
} else {
memcpy ( V_139 [ V_62 ] , V_139 [ 0 ] , V_110 ) ;
F_47 ( V_139 + 1 , V_62 - 1 , V_31 ) ;
}
V_100 = F_98 ( V_24 , V_24 -> V_185 , V_97 ) ;
V_194 = F_13 ( V_100 ) ;
if ( memcmp ( V_194 , V_139 [ V_24 -> V_185 ] , V_31 ) )
memcpy ( V_194 , V_139 [ V_24 -> V_185 ] , V_31 ) ;
else
F_142 ( V_24 -> V_115 , V_97 , 1 ) ;
F_14 ( V_100 ) ;
for ( V_124 = 0 ; V_124 < V_24 -> V_70 ; V_124 ++ )
F_14 ( F_79 ( V_24 , V_124 , V_97 , 0 ) ) ;
}
F_22 ( V_190 ) ;
if ( V_191 )
F_22 ( V_191 ) ;
V_193:
F_139 (pagenr, rbio->dbitmap, rbio->stripe_npages) {
struct V_38 * V_38 ;
V_38 = F_98 ( V_24 , V_24 -> V_185 , V_97 ) ;
V_27 = F_90 ( V_24 , & V_40 ,
V_38 , V_24 -> V_185 , V_97 , V_24 -> V_63 ) ;
if ( V_27 )
goto V_145;
}
if ( ! V_192 )
goto V_195;
F_139 (pagenr, pbitmap, rbio->stripe_npages) {
struct V_38 * V_38 ;
V_38 = F_98 ( V_24 , V_24 -> V_185 , V_97 ) ;
V_27 = F_90 ( V_24 , & V_40 , V_38 ,
V_84 -> V_147 [ V_24 -> V_185 ] ,
V_97 , V_24 -> V_63 ) ;
if ( V_27 )
goto V_145;
}
V_195:
V_62 = F_103 ( & V_40 ) ;
if ( ! V_62 ) {
F_72 ( V_24 , 0 , 0 ) ;
return;
}
F_86 ( & V_24 -> V_94 , V_62 ) ;
while ( 1 ) {
V_89 = F_104 ( & V_40 ) ;
if ( ! V_89 )
break;
V_89 -> V_93 = V_24 ;
V_89 -> V_148 = F_140 ;
F_33 ( ! F_20 ( V_91 , & V_89 -> V_92 ) ) ;
F_105 ( V_149 , V_89 ) ;
}
return;
V_145:
F_72 ( V_24 , - V_96 , 0 ) ;
}
static inline int F_143 ( struct V_23 * V_24 , int V_124 )
{
if ( V_124 >= 0 && V_124 < V_24 -> V_62 )
return 1 ;
return 0 ;
}
static void F_144 ( struct V_23 * V_24 )
{
if ( F_69 ( & V_24 -> error ) > V_24 -> V_84 -> V_95 )
goto V_145;
if ( V_24 -> V_113 >= 0 || V_24 -> V_114 >= 0 ) {
int V_196 = 0 , V_197 = - 1 ;
if ( F_143 ( V_24 , V_24 -> V_113 ) )
V_196 ++ ;
else if ( F_145 ( V_24 -> V_113 ) )
V_197 = V_24 -> V_113 ;
if ( F_143 ( V_24 , V_24 -> V_114 ) )
V_196 ++ ;
else if ( F_145 ( V_24 -> V_114 ) )
V_197 = V_24 -> V_114 ;
if ( V_196 > V_24 -> V_84 -> V_95 - 1 )
goto V_145;
if ( V_196 == 0 ) {
F_132 ( V_24 , 0 ) ;
return;
}
if ( V_197 != V_24 -> V_185 )
goto V_145;
F_129 ( V_24 ) ;
} else {
F_132 ( V_24 , 1 ) ;
}
return;
V_145:
F_72 ( V_24 , - V_96 , 0 ) ;
}
static void F_146 ( struct V_89 * V_89 , int V_87 )
{
struct V_23 * V_24 = V_89 -> V_93 ;
if ( V_87 )
F_77 ( V_24 , V_89 ) ;
else
F_108 ( V_89 ) ;
F_78 ( V_89 ) ;
if ( ! F_70 ( & V_24 -> V_94 ) )
return;
F_144 ( V_24 ) ;
}
static void F_147 ( struct V_23 * V_24 )
{
int V_158 = 0 ;
struct V_40 V_40 ;
int V_27 ;
int V_97 ;
int V_124 ;
struct V_89 * V_89 ;
V_27 = F_138 ( V_24 ) ;
if ( V_27 )
goto V_145;
F_25 ( & V_40 ) ;
F_86 ( & V_24 -> error , 0 ) ;
for ( V_124 = 0 ; V_124 < V_24 -> V_70 ; V_124 ++ ) {
F_139 (pagenr, rbio->dbitmap, rbio->stripe_npages) {
struct V_38 * V_38 ;
V_38 = F_79 ( V_24 , V_124 , V_97 , 1 ) ;
if ( V_38 )
continue;
V_38 = F_98 ( V_24 , V_124 , V_97 ) ;
if ( F_21 ( V_38 ) )
continue;
V_27 = F_90 ( V_24 , & V_40 , V_38 ,
V_124 , V_97 , V_24 -> V_63 ) ;
if ( V_27 )
goto V_145;
}
}
V_158 = F_103 ( & V_40 ) ;
if ( ! V_158 ) {
goto V_159;
}
F_86 ( & V_24 -> V_94 , V_158 ) ;
while ( 1 ) {
V_89 = F_104 ( & V_40 ) ;
if ( ! V_89 )
break;
V_89 -> V_93 = V_24 ;
V_89 -> V_148 = F_146 ;
F_113 ( V_24 -> V_46 , V_89 ,
V_160 ) ;
F_33 ( ! F_20 ( V_91 , & V_89 -> V_92 ) ) ;
F_105 ( V_161 , V_89 ) ;
}
return;
V_145:
F_72 ( V_24 , - V_96 , 0 ) ;
return;
V_159:
F_144 ( V_24 ) ;
}
static void F_148 ( struct V_172 * V_153 )
{
struct V_23 * V_24 ;
V_24 = F_118 ( V_153 , struct V_23 , V_153 ) ;
F_147 ( V_24 ) ;
}
static void F_63 ( struct V_23 * V_24 )
{
F_110 ( & V_24 -> V_153 , V_154 ,
F_148 , NULL , NULL ) ;
F_111 ( V_24 -> V_46 -> V_156 ,
& V_24 -> V_153 ) ;
}
void F_149 ( struct V_23 * V_24 )
{
if ( ! F_55 ( V_24 ) )
F_63 ( V_24 ) ;
}
