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
T_1 V_34 = V_24 -> V_35 -> V_36 [ 0 ] ;
return F_18 ( V_34 >> 16 , V_10 ) ;
}
static void F_19 ( struct V_23 * V_37 , struct V_23 * V_38 )
{
int V_11 ;
struct V_39 * V_25 ;
struct V_39 * V_26 ;
if ( ! F_20 ( V_32 , & V_37 -> V_33 ) )
return;
for ( V_11 = 0 ; V_11 < V_38 -> V_28 ; V_11 ++ ) {
V_25 = V_37 -> V_30 [ V_11 ] ;
if ( ! V_25 || ! F_21 ( V_25 ) ) {
continue;
}
V_26 = V_38 -> V_30 [ V_11 ] ;
if ( V_26 )
F_22 ( V_26 ) ;
V_38 -> V_30 [ V_11 ] = V_25 ;
V_37 -> V_30 [ V_11 ] = NULL ;
}
}
static void F_23 ( struct V_23 * V_38 ,
struct V_23 * V_40 )
{
F_24 ( & V_38 -> V_41 , & V_40 -> V_41 ) ;
V_38 -> V_42 += V_40 -> V_42 ;
V_38 -> V_43 += V_40 -> V_43 ;
F_25 ( & V_40 -> V_41 ) ;
}
static void F_26 ( struct V_23 * V_24 )
{
int V_44 = F_17 ( V_24 ) ;
struct V_3 * V_4 ;
struct V_6 * V_8 ;
int V_45 = 0 ;
if ( ! F_20 ( V_46 , & V_24 -> V_33 ) )
return;
V_4 = V_24 -> V_47 -> V_13 ;
V_8 = V_4 -> V_4 + V_44 ;
F_27 ( & V_8 -> V_21 ) ;
F_27 ( & V_24 -> V_48 ) ;
if ( F_28 ( V_46 , & V_24 -> V_33 ) ) {
F_29 ( & V_24 -> V_19 ) ;
V_4 -> V_49 -= 1 ;
V_45 = 1 ;
if ( F_30 ( & V_24 -> V_41 ) ) {
if ( ! F_31 ( & V_24 -> V_20 ) ) {
F_29 ( & V_24 -> V_20 ) ;
F_32 ( & V_24 -> V_50 ) ;
F_33 ( ! F_31 ( & V_24 -> V_51 ) ) ;
}
}
}
F_34 ( & V_24 -> V_48 ) ;
F_34 ( & V_8 -> V_21 ) ;
if ( V_45 )
F_35 ( V_24 ) ;
}
static void F_36 ( struct V_23 * V_24 )
{
struct V_3 * V_4 ;
unsigned long V_33 ;
if ( ! F_20 ( V_46 , & V_24 -> V_33 ) )
return;
V_4 = V_24 -> V_47 -> V_13 ;
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
V_24 = F_40 ( V_4 -> V_19 . V_52 ,
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
V_4 = V_24 -> V_47 -> V_13 ;
F_37 ( & V_4 -> V_18 , V_33 ) ;
F_27 ( & V_24 -> V_48 ) ;
if ( ! F_43 ( V_46 , & V_24 -> V_33 ) )
F_44 ( & V_24 -> V_50 ) ;
if ( ! F_31 ( & V_24 -> V_19 ) ) {
F_45 ( & V_24 -> V_19 , & V_4 -> V_19 ) ;
} else {
F_46 ( & V_24 -> V_19 , & V_4 -> V_19 ) ;
V_4 -> V_49 += 1 ;
}
F_34 ( & V_24 -> V_48 ) ;
if ( V_4 -> V_49 > V_53 ) {
struct V_23 * V_54 ;
V_54 = F_40 ( V_4 -> V_19 . V_55 ,
struct V_23 ,
V_19 ) ;
if ( V_54 != V_24 )
F_26 ( V_54 ) ;
}
F_38 ( & V_4 -> V_18 , V_33 ) ;
return;
}
static void F_47 ( void * * V_56 , int V_57 , T_2 V_58 )
{
int V_59 = 0 ;
int V_60 = 0 ;
void * V_38 = V_56 [ V_57 ] ;
while( V_57 > 0 ) {
V_60 = F_48 ( V_57 , V_61 ) ;
F_49 ( V_60 , V_58 , V_38 , V_56 + V_59 ) ;
V_57 -= V_60 ;
V_59 += V_60 ;
}
}
static int F_50 ( struct V_23 * V_24 )
{
unsigned long V_62 = V_24 -> V_42 ;
int V_27 = 1 ;
if ( V_62 != V_24 -> V_63 * V_24 -> V_64 )
V_27 = 0 ;
F_33 ( V_62 > V_24 -> V_63 * V_24 -> V_64 ) ;
return V_27 ;
}
static int F_51 ( struct V_23 * V_24 )
{
unsigned long V_33 ;
int V_27 ;
F_37 ( & V_24 -> V_48 , V_33 ) ;
V_27 = F_50 ( V_24 ) ;
F_38 ( & V_24 -> V_48 , V_33 ) ;
return V_27 ;
}
static int F_52 ( struct V_23 * V_65 ,
struct V_23 * V_7 )
{
if ( F_20 ( V_66 , & V_65 -> V_33 ) ||
F_20 ( V_66 , & V_7 -> V_33 ) )
return 0 ;
if ( F_20 ( V_46 , & V_65 -> V_33 ) ||
F_20 ( V_46 , & V_7 -> V_33 ) )
return 0 ;
if ( V_65 -> V_35 -> V_36 [ 0 ] !=
V_7 -> V_35 -> V_36 [ 0 ] )
return 0 ;
if ( V_65 -> V_67 != V_7 -> V_67 )
return 0 ;
if ( V_65 -> V_67 == V_68 ||
V_7 -> V_67 == V_68 )
return 0 ;
return 1 ;
}
static struct V_39 * F_53 ( struct V_23 * V_24 , int V_69 )
{
V_69 += ( V_24 -> V_63 * V_24 -> V_64 ) >> V_70 ;
return V_24 -> V_30 [ V_69 ] ;
}
static struct V_39 * F_54 ( struct V_23 * V_24 , int V_69 )
{
if ( V_24 -> V_63 + 1 == V_24 -> V_71 )
return NULL ;
V_69 += ( ( V_24 -> V_63 + 1 ) * V_24 -> V_64 ) >>
V_70 ;
return V_24 -> V_30 [ V_69 ] ;
}
static T_3 int F_55 ( struct V_23 * V_24 )
{
int V_44 = F_17 ( V_24 ) ;
struct V_6 * V_8 = V_24 -> V_47 -> V_13 -> V_4 + V_44 ;
struct V_23 * V_7 ;
struct V_23 * V_72 ;
unsigned long V_33 ;
F_56 ( V_22 ) ;
struct V_23 * V_45 = NULL ;
struct V_23 * V_73 = NULL ;
int V_27 = 0 ;
int V_74 = 0 ;
F_37 ( & V_8 -> V_21 , V_33 ) ;
F_57 (cur, &h->hash_list, hash_list) {
V_74 ++ ;
if ( V_7 -> V_35 -> V_36 [ 0 ] == V_24 -> V_35 -> V_36 [ 0 ] ) {
F_27 ( & V_7 -> V_48 ) ;
if ( F_30 ( & V_7 -> V_41 ) &&
F_31 ( & V_7 -> V_51 ) &&
F_20 ( V_46 , & V_7 -> V_33 ) &&
! F_20 ( V_66 , & V_7 -> V_33 ) ) {
F_29 ( & V_7 -> V_20 ) ;
F_32 ( & V_7 -> V_50 ) ;
F_19 ( V_7 , V_24 ) ;
V_73 = V_7 ;
F_34 ( & V_7 -> V_48 ) ;
goto V_75;
}
if ( F_52 ( V_7 , V_24 ) ) {
F_23 ( V_7 , V_24 ) ;
F_34 ( & V_7 -> V_48 ) ;
V_45 = V_24 ;
V_27 = 1 ;
goto V_76;
}
F_57 (pending, &cur->plug_list,
plug_list) {
if ( F_52 ( V_72 , V_24 ) ) {
F_23 ( V_72 , V_24 ) ;
F_34 ( & V_7 -> V_48 ) ;
V_45 = V_24 ;
V_27 = 1 ;
goto V_76;
}
}
F_58 ( & V_24 -> V_51 , & V_7 -> V_51 ) ;
F_34 ( & V_7 -> V_48 ) ;
V_27 = 1 ;
goto V_76;
}
}
V_75:
F_44 ( & V_24 -> V_50 ) ;
F_46 ( & V_24 -> V_20 , & V_8 -> V_20 ) ;
V_76:
F_38 ( & V_8 -> V_21 , V_33 ) ;
if ( V_73 )
F_36 ( V_73 ) ;
if ( V_45 )
F_35 ( V_45 ) ;
return V_27 ;
}
static T_3 void F_59 ( struct V_23 * V_24 )
{
int V_44 ;
struct V_6 * V_8 ;
unsigned long V_33 ;
int V_77 = 0 ;
V_44 = F_17 ( V_24 ) ;
V_8 = V_24 -> V_47 -> V_13 -> V_4 + V_44 ;
if ( F_31 ( & V_24 -> V_51 ) )
F_42 ( V_24 ) ;
F_37 ( & V_8 -> V_21 , V_33 ) ;
F_27 ( & V_24 -> V_48 ) ;
if ( ! F_31 ( & V_24 -> V_20 ) ) {
if ( F_31 ( & V_24 -> V_51 ) &&
F_20 ( V_46 , & V_24 -> V_33 ) ) {
V_77 = 1 ;
F_60 ( V_66 , & V_24 -> V_33 ) ;
F_33 ( ! F_30 ( & V_24 -> V_41 ) ) ;
goto V_78;
}
F_29 ( & V_24 -> V_20 ) ;
F_32 ( & V_24 -> V_50 ) ;
if ( ! F_31 ( & V_24 -> V_51 ) ) {
struct V_23 * V_52 ;
struct V_79 * V_80 = V_24 -> V_51 . V_52 ;
V_52 = F_40 ( V_80 , struct V_23 ,
V_51 ) ;
F_29 ( & V_24 -> V_51 ) ;
F_46 ( & V_52 -> V_20 , & V_8 -> V_20 ) ;
F_44 ( & V_52 -> V_50 ) ;
F_34 ( & V_24 -> V_48 ) ;
F_38 ( & V_8 -> V_21 , V_33 ) ;
if ( V_52 -> V_67 == V_81 )
F_61 ( V_52 ) ;
else if ( V_52 -> V_67 == V_82 ) {
F_19 ( V_24 , V_52 ) ;
F_62 ( V_52 ) ;
} else if ( V_52 -> V_67 == V_68 ) {
F_19 ( V_24 , V_52 ) ;
F_63 ( V_52 ) ;
}
goto V_83;
} else if ( F_64 ( & V_8 -> V_22 ) ) {
F_34 ( & V_24 -> V_48 ) ;
F_38 ( & V_8 -> V_21 , V_33 ) ;
F_65 ( & V_8 -> V_22 ) ;
goto V_83;
}
}
V_78:
F_34 ( & V_24 -> V_48 ) ;
F_38 ( & V_8 -> V_21 , V_33 ) ;
V_83:
if ( ! V_77 )
F_36 ( V_24 ) ;
}
static void F_35 ( struct V_23 * V_24 )
{
int V_11 ;
F_66 ( F_67 ( & V_24 -> V_50 ) < 0 ) ;
if ( ! F_68 ( & V_24 -> V_50 ) )
return;
F_66 ( ! F_31 ( & V_24 -> V_19 ) ) ;
F_66 ( ! F_31 ( & V_24 -> V_20 ) ) ;
F_66 ( ! F_30 ( & V_24 -> V_41 ) ) ;
for ( V_11 = 0 ; V_11 < V_24 -> V_28 ; V_11 ++ ) {
if ( V_24 -> V_30 [ V_11 ] ) {
F_22 ( V_24 -> V_30 [ V_11 ] ) ;
V_24 -> V_30 [ V_11 ] = NULL ;
}
}
F_69 ( V_24 -> V_35 ) ;
F_10 ( V_24 ) ;
}
static void F_70 ( struct V_23 * V_24 )
{
F_59 ( V_24 ) ;
F_35 ( V_24 ) ;
}
static void F_71 ( struct V_23 * V_24 , int V_84 , int V_85 )
{
struct V_86 * V_7 = F_72 ( & V_24 -> V_41 ) ;
struct V_86 * V_52 ;
if ( V_24 -> V_43 )
F_73 ( V_24 -> V_47 , V_24 -> V_43 ) ;
F_70 ( V_24 ) ;
while ( V_7 ) {
V_52 = V_7 -> V_87 ;
V_7 -> V_87 = NULL ;
if ( V_85 )
F_16 ( V_88 , & V_7 -> V_89 ) ;
F_74 ( V_7 , V_84 ) ;
V_7 = V_52 ;
}
}
static void F_75 ( struct V_86 * V_86 , int V_84 )
{
struct V_23 * V_24 = V_86 -> V_90 ;
if ( V_84 )
F_76 ( V_24 , V_86 ) ;
F_77 ( V_86 ) ;
if ( ! F_68 ( & V_24 -> V_91 ) )
return;
V_84 = 0 ;
if ( F_67 ( & V_24 -> error ) > V_24 -> V_35 -> V_92 )
V_84 = - V_93 ;
F_71 ( V_24 , V_84 , 0 ) ;
return;
}
static struct V_39 * F_78 ( struct V_23 * V_24 ,
int V_69 , int V_94 , int V_95 )
{
int V_96 ;
struct V_39 * V_97 = NULL ;
V_96 = V_69 * ( V_24 -> V_64 >> V_98 ) + V_94 ;
F_79 ( & V_24 -> V_48 ) ;
V_97 = V_24 -> V_29 [ V_96 ] ;
F_80 ( & V_24 -> V_48 ) ;
if ( V_97 || V_95 )
return V_97 ;
return V_24 -> V_30 [ V_96 ] ;
}
static unsigned long F_81 ( unsigned long V_64 , int V_99 )
{
unsigned long V_100 = V_64 * V_99 ;
return F_82 ( V_100 , V_31 ) ;
}
static struct V_23 * F_83 ( struct V_101 * V_102 ,
struct V_103 * V_35 , T_1 V_64 )
{
struct V_23 * V_24 ;
int V_63 = 0 ;
int V_71 = V_35 -> V_104 - V_35 -> V_105 ;
int V_106 = F_81 ( V_64 , V_71 ) ;
int V_107 = F_82 ( V_64 , V_108 ) ;
void * V_97 ;
V_24 = F_2 ( sizeof( * V_24 ) + V_106 * sizeof( struct V_39 * ) * 2 +
F_82 ( V_107 , V_109 / 8 ) ,
V_110 ) ;
if ( ! V_24 )
return F_84 ( - V_17 ) ;
F_25 ( & V_24 -> V_41 ) ;
F_5 ( & V_24 -> V_51 ) ;
F_4 ( & V_24 -> V_48 ) ;
F_5 ( & V_24 -> V_19 ) ;
F_5 ( & V_24 -> V_20 ) ;
V_24 -> V_35 = V_35 ;
V_24 -> V_47 = V_102 -> V_47 ;
V_24 -> V_64 = V_64 ;
V_24 -> V_28 = V_106 ;
V_24 -> V_71 = V_71 ;
V_24 -> V_107 = V_107 ;
V_24 -> V_111 = - 1 ;
V_24 -> V_112 = - 1 ;
F_85 ( & V_24 -> V_50 , 1 ) ;
F_85 ( & V_24 -> error , 0 ) ;
F_85 ( & V_24 -> V_91 , 0 ) ;
V_97 = V_24 + 1 ;
V_24 -> V_30 = V_97 ;
V_24 -> V_29 = V_97 + sizeof( struct V_39 * ) * V_106 ;
V_24 -> V_113 = V_97 + sizeof( struct V_39 * ) * V_106 * 2 ;
if ( V_35 -> V_114 & V_115 )
V_63 = V_71 - 1 ;
else if ( V_35 -> V_114 & V_116 )
V_63 = V_71 - 2 ;
else
F_86 () ;
V_24 -> V_63 = V_63 ;
return V_24 ;
}
static int F_12 ( struct V_23 * V_24 )
{
int V_11 ;
struct V_39 * V_39 ;
for ( V_11 = 0 ; V_11 < V_24 -> V_28 ; V_11 ++ ) {
if ( V_24 -> V_30 [ V_11 ] )
continue;
V_39 = F_87 ( V_110 | V_117 ) ;
if ( ! V_39 )
return - V_17 ;
V_24 -> V_30 [ V_11 ] = V_39 ;
F_88 ( V_39 ) ;
}
return 0 ;
}
static int F_89 ( struct V_23 * V_24 )
{
int V_11 ;
struct V_39 * V_39 ;
V_11 = ( V_24 -> V_63 * V_24 -> V_64 ) >> V_70 ;
for (; V_11 < V_24 -> V_28 ; V_11 ++ ) {
if ( V_24 -> V_30 [ V_11 ] )
continue;
V_39 = F_87 ( V_110 | V_117 ) ;
if ( ! V_39 )
return - V_17 ;
V_24 -> V_30 [ V_11 ] = V_39 ;
}
return 0 ;
}
static int F_90 ( struct V_23 * V_24 ,
struct V_41 * V_41 ,
struct V_39 * V_39 ,
int V_118 ,
unsigned long V_119 ,
unsigned long V_120 )
{
struct V_86 * V_65 = V_41 -> V_121 ;
T_1 V_122 = 0 ;
int V_27 ;
struct V_86 * V_86 ;
struct V_123 * V_124 ;
T_1 V_125 ;
V_124 = & V_24 -> V_35 -> V_126 [ V_118 ] ;
V_125 = V_124 -> V_127 + ( V_119 << V_70 ) ;
if ( ! V_124 -> V_128 -> V_129 )
return F_91 ( V_24 , V_118 ) ;
if ( V_65 ) {
V_122 = ( T_1 ) V_65 -> V_130 . V_131 << 9 ;
V_122 += V_65 -> V_130 . V_132 ;
if ( V_122 == V_125 && V_124 -> V_128 -> V_129 &&
F_20 ( V_88 , & V_65 -> V_89 ) &&
V_65 -> V_133 == V_124 -> V_128 -> V_129 ) {
V_27 = F_92 ( V_65 , V_39 , V_31 , 0 ) ;
if ( V_27 == V_31 )
return 0 ;
}
}
V_86 = F_93 ( V_110 , V_120 >> V_98 ? : 1 ) ;
if ( ! V_86 )
return - V_17 ;
V_86 -> V_130 . V_132 = 0 ;
V_86 -> V_133 = V_124 -> V_128 -> V_129 ;
V_86 -> V_130 . V_131 = V_125 >> 9 ;
F_16 ( V_88 , & V_86 -> V_89 ) ;
F_92 ( V_86 , V_39 , V_31 , 0 ) ;
F_94 ( V_41 , V_86 ) ;
return 0 ;
}
static void F_95 ( struct V_23 * V_24 )
{
if ( V_24 -> V_111 >= 0 || V_24 -> V_112 >= 0 ) {
F_33 ( V_24 -> V_111 == V_24 -> V_71 - 1 ) ;
F_96 ( V_24 ) ;
} else {
F_97 ( V_24 ) ;
}
}
static struct V_39 * F_98 ( struct V_23 * V_24 , int V_124 , int V_39 )
{
int V_69 ;
V_69 = V_124 * ( V_24 -> V_64 >> V_70 ) ;
V_69 += V_39 ;
return V_24 -> V_30 [ V_69 ] ;
}
static void F_99 ( struct V_23 * V_24 )
{
struct V_86 * V_86 ;
T_1 V_134 ;
unsigned long V_135 ;
unsigned long V_119 ;
struct V_39 * V_97 ;
int V_11 ;
F_79 ( & V_24 -> V_48 ) ;
F_100 (bio, &rbio->bio_list) {
V_134 = ( T_1 ) V_86 -> V_130 . V_131 << 9 ;
V_135 = V_134 - V_24 -> V_35 -> V_36 [ 0 ] ;
V_119 = V_135 >> V_70 ;
for ( V_11 = 0 ; V_11 < V_86 -> V_136 ; V_11 ++ ) {
V_97 = V_86 -> V_137 [ V_11 ] . V_138 ;
V_24 -> V_29 [ V_119 + V_11 ] = V_97 ;
}
}
F_80 ( & V_24 -> V_48 ) ;
}
static T_3 void F_97 ( struct V_23 * V_24 )
{
struct V_103 * V_35 = V_24 -> V_35 ;
void * V_139 [ V_24 -> V_71 ] ;
int V_64 = V_24 -> V_64 ;
int V_63 = V_24 -> V_63 ;
int V_124 ;
int V_94 ;
int V_140 = - 1 ;
int V_141 = - 1 ;
struct V_41 V_41 ;
struct V_86 * V_86 ;
int V_142 = V_64 >> V_70 ;
int V_27 ;
F_25 ( & V_41 ) ;
if ( V_24 -> V_71 - V_24 -> V_63 == 1 ) {
V_140 = V_24 -> V_71 - 1 ;
} else if ( V_24 -> V_71 - V_24 -> V_63 == 2 ) {
V_140 = V_24 -> V_71 - 2 ;
V_141 = V_24 -> V_71 - 1 ;
} else {
F_86 () ;
}
F_79 ( & V_24 -> V_48 ) ;
F_16 ( V_66 , & V_24 -> V_33 ) ;
F_80 ( & V_24 -> V_48 ) ;
F_85 ( & V_24 -> error , 0 ) ;
F_99 ( V_24 ) ;
if ( ! F_51 ( V_24 ) )
F_11 ( V_24 ) ;
else
F_60 ( V_32 , & V_24 -> V_33 ) ;
for ( V_94 = 0 ; V_94 < V_142 ; V_94 ++ ) {
struct V_39 * V_97 ;
for ( V_124 = 0 ; V_124 < V_63 ; V_124 ++ ) {
V_97 = F_78 ( V_24 , V_124 , V_94 , 0 ) ;
V_139 [ V_124 ] = F_13 ( V_97 ) ;
}
V_97 = F_53 ( V_24 , V_94 ) ;
F_15 ( V_97 ) ;
V_139 [ V_124 ++ ] = F_13 ( V_97 ) ;
if ( V_141 != - 1 ) {
V_97 = F_54 ( V_24 , V_94 ) ;
F_15 ( V_97 ) ;
V_139 [ V_124 ++ ] = F_13 ( V_97 ) ;
V_143 . V_144 ( V_24 -> V_71 , V_108 ,
V_139 ) ;
} else {
memcpy ( V_139 [ V_63 ] , V_139 [ 0 ] , V_108 ) ;
F_47 ( V_139 + 1 , V_63 - 1 , V_31 ) ;
}
for ( V_124 = 0 ; V_124 < V_24 -> V_71 ; V_124 ++ )
F_14 ( F_78 ( V_24 , V_124 , V_94 , 0 ) ) ;
}
for ( V_124 = 0 ; V_124 < V_24 -> V_71 ; V_124 ++ ) {
for ( V_94 = 0 ; V_94 < V_142 ; V_94 ++ ) {
struct V_39 * V_39 ;
if ( V_124 < V_24 -> V_63 ) {
V_39 = F_78 ( V_24 , V_124 , V_94 , 1 ) ;
if ( ! V_39 )
continue;
} else {
V_39 = F_98 ( V_24 , V_124 , V_94 ) ;
}
V_27 = F_90 ( V_24 , & V_41 ,
V_39 , V_124 , V_94 , V_24 -> V_64 ) ;
if ( V_27 )
goto V_145;
}
}
if ( F_101 ( ! V_35 -> V_105 ) )
goto V_146;
for ( V_124 = 0 ; V_124 < V_24 -> V_71 ; V_124 ++ ) {
if ( ! V_35 -> V_147 [ V_124 ] )
continue;
for ( V_94 = 0 ; V_94 < V_142 ; V_94 ++ ) {
struct V_39 * V_39 ;
if ( V_124 < V_24 -> V_63 ) {
V_39 = F_78 ( V_24 , V_124 , V_94 , 1 ) ;
if ( ! V_39 )
continue;
} else {
V_39 = F_98 ( V_24 , V_124 , V_94 ) ;
}
V_27 = F_90 ( V_24 , & V_41 , V_39 ,
V_24 -> V_35 -> V_147 [ V_124 ] ,
V_94 , V_24 -> V_64 ) ;
if ( V_27 )
goto V_145;
}
}
V_146:
F_85 ( & V_24 -> V_91 , F_102 ( & V_41 ) ) ;
F_33 ( F_67 ( & V_24 -> V_91 ) == 0 ) ;
while ( 1 ) {
V_86 = F_103 ( & V_41 ) ;
if ( ! V_86 )
break;
V_86 -> V_90 = V_24 ;
V_86 -> V_148 = F_75 ;
F_33 ( ! F_20 ( V_88 , & V_86 -> V_89 ) ) ;
F_104 ( V_149 , V_86 ) ;
}
return;
V_145:
F_71 ( V_24 , - V_93 , 0 ) ;
}
static int F_105 ( struct V_23 * V_24 ,
struct V_86 * V_86 )
{
T_1 V_127 = V_86 -> V_130 . V_131 ;
T_1 V_150 ;
int V_11 ;
struct V_123 * V_124 ;
V_127 <<= 9 ;
for ( V_11 = 0 ; V_11 < V_24 -> V_35 -> V_104 ; V_11 ++ ) {
V_124 = & V_24 -> V_35 -> V_126 [ V_11 ] ;
V_150 = V_124 -> V_127 ;
if ( V_127 >= V_150 &&
V_127 < V_150 + V_24 -> V_64 &&
V_86 -> V_133 == V_124 -> V_128 -> V_129 ) {
return V_11 ;
}
}
return - 1 ;
}
static int F_106 ( struct V_23 * V_24 ,
struct V_86 * V_86 )
{
T_1 V_151 = V_86 -> V_130 . V_131 ;
T_1 V_150 ;
int V_11 ;
V_151 <<= 9 ;
for ( V_11 = 0 ; V_11 < V_24 -> V_63 ; V_11 ++ ) {
V_150 = V_24 -> V_35 -> V_36 [ V_11 ] ;
if ( V_151 >= V_150 &&
V_151 < V_150 + V_24 -> V_64 ) {
return V_11 ;
}
}
return - 1 ;
}
static int F_91 ( struct V_23 * V_24 , int V_152 )
{
unsigned long V_33 ;
int V_27 = 0 ;
F_37 ( & V_24 -> V_48 , V_33 ) ;
if ( V_24 -> V_111 == V_152 || V_24 -> V_112 == V_152 )
goto V_76;
if ( V_24 -> V_111 == - 1 ) {
V_24 -> V_111 = V_152 ;
F_44 ( & V_24 -> error ) ;
} else if ( V_24 -> V_112 == - 1 ) {
V_24 -> V_112 = V_152 ;
F_44 ( & V_24 -> error ) ;
} else {
V_27 = - V_93 ;
}
V_76:
F_38 ( & V_24 -> V_48 , V_33 ) ;
return V_27 ;
}
static int F_76 ( struct V_23 * V_24 ,
struct V_86 * V_86 )
{
int V_152 = F_105 ( V_24 , V_86 ) ;
if ( V_152 < 0 )
return - V_93 ;
return F_91 ( V_24 , V_152 ) ;
}
static void F_107 ( struct V_86 * V_86 )
{
int V_11 ;
struct V_39 * V_97 ;
for ( V_11 = 0 ; V_11 < V_86 -> V_136 ; V_11 ++ ) {
V_97 = V_86 -> V_137 [ V_11 ] . V_138 ;
F_15 ( V_97 ) ;
}
}
static void F_108 ( struct V_86 * V_86 , int V_84 )
{
struct V_23 * V_24 = V_86 -> V_90 ;
if ( V_84 )
F_76 ( V_24 , V_86 ) ;
else
F_107 ( V_86 ) ;
F_77 ( V_86 ) ;
if ( ! F_68 ( & V_24 -> V_91 ) )
return;
V_84 = 0 ;
if ( F_67 ( & V_24 -> error ) > V_24 -> V_35 -> V_92 )
goto V_145;
F_95 ( V_24 ) ;
return;
V_145:
F_71 ( V_24 , - V_93 , 0 ) ;
}
static void F_62 ( struct V_23 * V_24 )
{
F_109 ( & V_24 -> V_153 , V_154 ,
V_155 , NULL , NULL ) ;
F_110 ( V_24 -> V_47 -> V_156 ,
& V_24 -> V_153 ) ;
}
static void F_61 ( struct V_23 * V_24 )
{
F_109 ( & V_24 -> V_153 , V_154 ,
V_157 , NULL , NULL ) ;
F_110 ( V_24 -> V_47 -> V_156 ,
& V_24 -> V_153 ) ;
}
static int F_111 ( struct V_23 * V_24 )
{
int V_158 = 0 ;
struct V_41 V_41 ;
int V_27 ;
int V_28 = F_82 ( V_24 -> V_64 , V_31 ) ;
int V_94 ;
int V_124 ;
struct V_86 * V_86 ;
F_25 ( & V_41 ) ;
V_27 = F_12 ( V_24 ) ;
if ( V_27 )
goto V_145;
F_99 ( V_24 ) ;
F_85 ( & V_24 -> error , 0 ) ;
for ( V_124 = 0 ; V_124 < V_24 -> V_63 ; V_124 ++ ) {
for ( V_94 = 0 ; V_94 < V_28 ; V_94 ++ ) {
struct V_39 * V_39 ;
V_39 = F_78 ( V_24 , V_124 , V_94 , 1 ) ;
if ( V_39 )
continue;
V_39 = F_98 ( V_24 , V_124 , V_94 ) ;
if ( F_21 ( V_39 ) )
continue;
V_27 = F_90 ( V_24 , & V_41 , V_39 ,
V_124 , V_94 , V_24 -> V_64 ) ;
if ( V_27 )
goto V_145;
}
}
V_158 = F_102 ( & V_41 ) ;
if ( ! V_158 ) {
goto V_159;
}
F_85 ( & V_24 -> V_91 , V_158 ) ;
while ( 1 ) {
V_86 = F_103 ( & V_41 ) ;
if ( ! V_86 )
break;
V_86 -> V_90 = V_24 ;
V_86 -> V_148 = F_108 ;
F_112 ( V_24 -> V_47 , V_86 ,
V_160 ) ;
F_33 ( ! F_20 ( V_88 , & V_86 -> V_89 ) ) ;
F_104 ( V_161 , V_86 ) ;
}
return 0 ;
V_145:
F_71 ( V_24 , - V_93 , 0 ) ;
return - V_93 ;
V_159:
F_95 ( V_24 ) ;
return 0 ;
}
static int F_113 ( struct V_23 * V_24 )
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
static int F_114 ( struct V_23 * V_24 )
{
int V_27 ;
V_27 = F_55 ( V_24 ) ;
if ( V_27 == 0 )
F_62 ( V_24 ) ;
return 0 ;
}
static int F_115 ( struct V_23 * V_24 )
{
if ( ! F_51 ( V_24 ) )
return F_114 ( V_24 ) ;
return F_113 ( V_24 ) ;
}
static int F_116 ( void * V_162 , struct V_79 * V_163 , struct V_79 * V_164 )
{
struct V_23 * V_165 = F_117 ( V_163 , struct V_23 ,
V_51 ) ;
struct V_23 * V_166 = F_117 ( V_164 , struct V_23 ,
V_51 ) ;
T_1 V_167 = V_165 -> V_41 . V_80 -> V_130 . V_131 ;
T_1 V_168 = V_166 -> V_41 . V_80 -> V_130 . V_131 ;
if ( V_167 < V_168 )
return - 1 ;
if ( V_167 > V_168 )
return 1 ;
return 0 ;
}
static void F_118 ( struct V_169 * V_170 )
{
struct V_23 * V_7 ;
struct V_23 * V_65 = NULL ;
F_119 ( NULL , & V_170 -> V_171 , F_116 ) ;
while ( ! F_31 ( & V_170 -> V_171 ) ) {
V_7 = F_40 ( V_170 -> V_171 . V_52 ,
struct V_23 , V_51 ) ;
F_29 ( & V_7 -> V_51 ) ;
if ( F_51 ( V_7 ) ) {
F_113 ( V_7 ) ;
continue;
}
if ( V_65 ) {
if ( F_52 ( V_65 , V_7 ) ) {
F_23 ( V_65 , V_7 ) ;
F_35 ( V_7 ) ;
continue;
}
F_115 ( V_65 ) ;
}
V_65 = V_7 ;
}
if ( V_65 ) {
F_115 ( V_65 ) ;
}
F_10 ( V_170 ) ;
}
static void F_120 ( struct V_172 * V_153 )
{
struct V_169 * V_170 ;
V_170 = F_117 ( V_153 , struct V_169 , V_153 ) ;
F_118 ( V_170 ) ;
}
static void F_121 ( struct V_173 * V_174 , bool V_175 )
{
struct V_169 * V_170 ;
V_170 = F_117 ( V_174 , struct V_169 , V_174 ) ;
if ( V_175 ) {
F_109 ( & V_170 -> V_153 , V_154 ,
F_120 , NULL , NULL ) ;
F_110 ( V_170 -> V_2 -> V_156 ,
& V_170 -> V_153 ) ;
return;
}
F_118 ( V_170 ) ;
}
int F_122 ( struct V_101 * V_102 , struct V_86 * V_86 ,
struct V_103 * V_35 , T_1 V_64 )
{
struct V_23 * V_24 ;
struct V_169 * V_170 = NULL ;
struct V_173 * V_174 ;
int V_27 ;
V_24 = F_83 ( V_102 , V_35 , V_64 ) ;
if ( F_123 ( V_24 ) ) {
F_69 ( V_35 ) ;
return F_124 ( V_24 ) ;
}
F_94 ( & V_24 -> V_41 , V_86 ) ;
V_24 -> V_42 = V_86 -> V_130 . V_132 ;
V_24 -> V_67 = V_82 ;
F_125 ( V_102 -> V_47 ) ;
V_24 -> V_43 = 1 ;
if ( F_51 ( V_24 ) ) {
V_27 = F_113 ( V_24 ) ;
if ( V_27 )
F_126 ( V_102 -> V_47 ) ;
return V_27 ;
}
V_174 = F_127 ( F_121 , V_102 -> V_47 ,
sizeof( * V_170 ) ) ;
if ( V_174 ) {
V_170 = F_117 ( V_174 , struct V_169 , V_174 ) ;
if ( ! V_170 -> V_2 ) {
V_170 -> V_2 = V_102 -> V_47 ;
F_5 ( & V_170 -> V_171 ) ;
}
F_58 ( & V_24 -> V_51 , & V_170 -> V_171 ) ;
V_27 = 0 ;
} else {
V_27 = F_115 ( V_24 ) ;
if ( V_27 )
F_126 ( V_102 -> V_47 ) ;
}
return V_27 ;
}
static void F_128 ( struct V_23 * V_24 )
{
int V_94 , V_124 ;
void * * V_139 ;
int V_111 = - 1 , V_112 = - 1 ;
int V_28 = F_82 ( V_24 -> V_64 , V_31 ) ;
struct V_39 * V_39 ;
int V_84 ;
int V_11 ;
V_139 = F_2 ( V_24 -> V_71 * sizeof( void * ) ,
V_110 ) ;
if ( ! V_139 ) {
V_84 = - V_17 ;
goto V_176;
}
V_111 = V_24 -> V_111 ;
V_112 = V_24 -> V_112 ;
if ( V_24 -> V_67 == V_81 ) {
F_79 ( & V_24 -> V_48 ) ;
F_16 ( V_66 , & V_24 -> V_33 ) ;
F_80 ( & V_24 -> V_48 ) ;
}
F_99 ( V_24 ) ;
for ( V_94 = 0 ; V_94 < V_28 ; V_94 ++ ) {
if ( V_24 -> V_67 == V_68 &&
! F_20 ( V_94 , V_24 -> V_113 ) )
continue;
for ( V_124 = 0 ; V_124 < V_24 -> V_71 ; V_124 ++ ) {
if ( V_24 -> V_67 == V_81 &&
( V_124 == V_111 || V_124 == V_112 ) ) {
V_39 = F_78 ( V_24 , V_124 , V_94 , 0 ) ;
} else {
V_39 = F_98 ( V_24 , V_124 , V_94 ) ;
}
V_139 [ V_124 ] = F_13 ( V_39 ) ;
}
if ( V_24 -> V_35 -> V_114 & V_116 ) {
if ( V_112 < 0 ) {
if ( V_111 == V_24 -> V_63 ) {
V_84 = - V_93 ;
goto V_145;
}
goto V_177;
}
if ( V_111 > V_112 ) {
int V_178 = V_112 ;
V_112 = V_111 ;
V_111 = V_178 ;
}
if ( V_24 -> V_35 -> V_36 [ V_112 ] == V_179 ) {
if ( V_24 -> V_35 -> V_36 [ V_111 ] ==
V_180 ) {
V_84 = - V_93 ;
goto V_145;
}
goto V_177;
}
if ( V_24 -> V_35 -> V_36 [ V_112 ] == V_180 ) {
F_129 ( V_24 -> V_71 ,
V_108 , V_111 , V_139 ) ;
} else {
F_130 ( V_24 -> V_71 ,
V_108 , V_111 , V_112 ,
V_139 ) ;
}
} else {
void * V_97 ;
F_33 ( V_112 != - 1 ) ;
V_177:
memcpy ( V_139 [ V_111 ] ,
V_139 [ V_24 -> V_63 ] ,
V_31 ) ;
V_97 = V_139 [ V_111 ] ;
for ( V_124 = V_111 ; V_124 < V_24 -> V_63 - 1 ; V_124 ++ )
V_139 [ V_124 ] = V_139 [ V_124 + 1 ] ;
V_139 [ V_24 -> V_63 - 1 ] = V_97 ;
F_47 ( V_139 , V_24 -> V_63 - 1 , V_31 ) ;
}
if ( V_24 -> V_67 == V_82 ) {
for ( V_11 = 0 ; V_11 < V_28 ; V_11 ++ ) {
if ( V_111 != - 1 ) {
V_39 = F_98 ( V_24 , V_111 , V_11 ) ;
F_15 ( V_39 ) ;
}
if ( V_112 != - 1 ) {
V_39 = F_98 ( V_24 , V_112 , V_11 ) ;
F_15 ( V_39 ) ;
}
}
}
for ( V_124 = 0 ; V_124 < V_24 -> V_71 ; V_124 ++ ) {
if ( V_24 -> V_67 == V_81 &&
( V_124 == V_111 || V_124 == V_112 ) ) {
V_39 = F_78 ( V_24 , V_124 , V_94 , 0 ) ;
} else {
V_39 = F_98 ( V_24 , V_124 , V_94 ) ;
}
F_14 ( V_39 ) ;
}
}
V_84 = 0 ;
V_145:
F_10 ( V_139 ) ;
V_176:
if ( V_24 -> V_67 == V_81 ) {
if ( V_84 == 0 )
F_11 ( V_24 ) ;
else
F_60 ( V_32 , & V_24 -> V_33 ) ;
F_71 ( V_24 , V_84 , V_84 == 0 ) ;
} else if ( V_84 == 0 ) {
V_24 -> V_111 = - 1 ;
V_24 -> V_112 = - 1 ;
if ( V_24 -> V_67 == V_82 )
F_97 ( V_24 ) ;
else if ( V_24 -> V_67 == V_68 )
F_131 ( V_24 , 0 ) ;
else
F_86 () ;
} else {
F_71 ( V_24 , V_84 , 0 ) ;
}
}
static void F_132 ( struct V_86 * V_86 , int V_84 )
{
struct V_23 * V_24 = V_86 -> V_90 ;
if ( V_84 )
F_76 ( V_24 , V_86 ) ;
else
F_107 ( V_86 ) ;
F_77 ( V_86 ) ;
if ( ! F_68 ( & V_24 -> V_91 ) )
return;
if ( F_67 ( & V_24 -> error ) > V_24 -> V_35 -> V_92 )
F_71 ( V_24 , - V_93 , 0 ) ;
else
F_128 ( V_24 ) ;
}
static int F_96 ( struct V_23 * V_24 )
{
int V_158 = 0 ;
struct V_41 V_41 ;
int V_27 ;
int V_28 = F_82 ( V_24 -> V_64 , V_31 ) ;
int V_94 ;
int V_124 ;
struct V_86 * V_86 ;
F_25 ( & V_41 ) ;
V_27 = F_12 ( V_24 ) ;
if ( V_27 )
goto V_145;
F_85 ( & V_24 -> error , 0 ) ;
for ( V_124 = 0 ; V_124 < V_24 -> V_71 ; V_124 ++ ) {
if ( V_24 -> V_111 == V_124 || V_24 -> V_112 == V_124 ) {
F_44 ( & V_24 -> error ) ;
continue;
}
for ( V_94 = 0 ; V_94 < V_28 ; V_94 ++ ) {
struct V_39 * V_97 ;
V_97 = F_98 ( V_24 , V_124 , V_94 ) ;
if ( F_21 ( V_97 ) )
continue;
V_27 = F_90 ( V_24 , & V_41 ,
F_98 ( V_24 , V_124 , V_94 ) ,
V_124 , V_94 , V_24 -> V_64 ) ;
if ( V_27 < 0 )
goto V_145;
}
}
V_158 = F_102 ( & V_41 ) ;
if ( ! V_158 ) {
if ( F_67 ( & V_24 -> error ) <= V_24 -> V_35 -> V_92 ) {
F_128 ( V_24 ) ;
goto V_76;
} else {
goto V_145;
}
}
F_85 ( & V_24 -> V_91 , V_158 ) ;
while ( 1 ) {
V_86 = F_103 ( & V_41 ) ;
if ( ! V_86 )
break;
V_86 -> V_90 = V_24 ;
V_86 -> V_148 = F_132 ;
F_112 ( V_24 -> V_47 , V_86 ,
V_160 ) ;
F_33 ( ! F_20 ( V_88 , & V_86 -> V_89 ) ) ;
F_104 ( V_161 , V_86 ) ;
}
V_76:
return 0 ;
V_145:
if ( V_24 -> V_67 == V_81 )
F_71 ( V_24 , - V_93 , 0 ) ;
return - V_93 ;
}
int F_133 ( struct V_101 * V_102 , struct V_86 * V_86 ,
struct V_103 * V_35 , T_1 V_64 ,
int V_181 , int V_182 )
{
struct V_23 * V_24 ;
int V_27 ;
V_24 = F_83 ( V_102 , V_35 , V_64 ) ;
if ( F_123 ( V_24 ) ) {
if ( V_182 )
F_69 ( V_35 ) ;
return F_124 ( V_24 ) ;
}
V_24 -> V_67 = V_81 ;
F_94 ( & V_24 -> V_41 , V_86 ) ;
V_24 -> V_42 = V_86 -> V_130 . V_132 ;
V_24 -> V_111 = F_106 ( V_24 , V_86 ) ;
if ( V_24 -> V_111 == - 1 ) {
F_86 () ;
if ( V_182 )
F_69 ( V_35 ) ;
F_10 ( V_24 ) ;
return - V_93 ;
}
if ( V_182 ) {
F_125 ( V_102 -> V_47 ) ;
V_24 -> V_43 = 1 ;
} else {
F_134 ( V_35 ) ;
}
if ( V_181 == 3 )
V_24 -> V_112 = V_24 -> V_71 - 2 ;
V_27 = F_55 ( V_24 ) ;
if ( V_27 == 0 )
F_96 ( V_24 ) ;
return 0 ;
}
static void V_155 ( struct V_172 * V_153 )
{
struct V_23 * V_24 ;
V_24 = F_117 ( V_153 , struct V_23 , V_153 ) ;
F_111 ( V_24 ) ;
}
static void V_157 ( struct V_172 * V_153 )
{
struct V_23 * V_24 ;
V_24 = F_117 ( V_153 , struct V_23 , V_153 ) ;
F_96 ( V_24 ) ;
}
struct V_23 *
F_135 ( struct V_101 * V_102 , struct V_86 * V_86 ,
struct V_103 * V_35 , T_1 V_64 ,
struct V_183 * V_184 ,
unsigned long * V_113 , int V_185 )
{
struct V_23 * V_24 ;
int V_11 ;
V_24 = F_83 ( V_102 , V_35 , V_64 ) ;
if ( F_123 ( V_24 ) )
return NULL ;
F_94 ( & V_24 -> V_41 , V_86 ) ;
ASSERT ( ! V_86 -> V_130 . V_132 ) ;
V_24 -> V_67 = V_68 ;
for ( V_11 = 0 ; V_11 < V_24 -> V_71 ; V_11 ++ ) {
if ( V_35 -> V_126 [ V_11 ] . V_128 == V_184 ) {
V_24 -> V_186 = V_11 ;
break;
}
}
ASSERT ( V_102 -> V_187 == V_108 ) ;
ASSERT ( V_24 -> V_107 == V_185 ) ;
F_136 ( V_24 -> V_113 , V_113 , V_185 ) ;
return V_24 ;
}
void F_137 ( struct V_23 * V_24 ,
struct V_39 * V_39 , T_1 V_151 )
{
int V_135 ;
int V_69 ;
ASSERT ( V_151 >= V_24 -> V_35 -> V_36 [ 0 ] ) ;
ASSERT ( V_151 + V_108 <= V_24 -> V_35 -> V_36 [ 0 ] +
V_24 -> V_64 * V_24 -> V_63 ) ;
V_135 = ( int ) ( V_151 - V_24 -> V_35 -> V_36 [ 0 ] ) ;
V_69 = V_135 >> V_70 ;
V_24 -> V_29 [ V_69 ] = V_39 ;
}
static int F_138 ( struct V_23 * V_24 )
{
int V_11 ;
int V_188 ;
int V_69 ;
struct V_39 * V_39 ;
F_139 (bit, rbio->dbitmap, rbio->stripe_npages) {
for ( V_11 = 0 ; V_11 < V_24 -> V_71 ; V_11 ++ ) {
V_69 = V_11 * V_24 -> V_107 + V_188 ;
if ( V_24 -> V_30 [ V_69 ] )
continue;
V_39 = F_87 ( V_110 | V_117 ) ;
if ( ! V_39 )
return - V_17 ;
V_24 -> V_30 [ V_69 ] = V_39 ;
F_88 ( V_39 ) ;
}
}
return 0 ;
}
static void F_140 ( struct V_86 * V_86 , int V_84 )
{
struct V_23 * V_24 = V_86 -> V_90 ;
if ( V_84 )
F_76 ( V_24 , V_86 ) ;
F_77 ( V_86 ) ;
if ( ! F_68 ( & V_24 -> V_91 ) )
return;
V_84 = 0 ;
if ( F_67 ( & V_24 -> error ) )
V_84 = - V_93 ;
F_71 ( V_24 , V_84 , 0 ) ;
}
static T_3 void F_131 ( struct V_23 * V_24 ,
int V_189 )
{
struct V_103 * V_35 = V_24 -> V_35 ;
void * V_139 [ V_24 -> V_71 ] ;
F_141 ( V_190 , V_24 -> V_107 ) ;
int V_63 = V_24 -> V_63 ;
int V_124 ;
int V_94 ;
int V_140 = - 1 ;
int V_141 = - 1 ;
struct V_39 * V_191 = NULL ;
struct V_39 * V_192 = NULL ;
struct V_41 V_41 ;
struct V_86 * V_86 ;
int V_193 = 0 ;
int V_27 ;
F_25 ( & V_41 ) ;
if ( V_24 -> V_71 - V_24 -> V_63 == 1 ) {
V_140 = V_24 -> V_71 - 1 ;
} else if ( V_24 -> V_71 - V_24 -> V_63 == 2 ) {
V_140 = V_24 -> V_71 - 2 ;
V_141 = V_24 -> V_71 - 1 ;
} else {
F_86 () ;
}
if ( V_35 -> V_105 && V_35 -> V_147 [ V_24 -> V_186 ] ) {
V_193 = 1 ;
F_136 ( V_190 , V_24 -> V_113 , V_24 -> V_107 ) ;
}
F_60 ( V_32 , & V_24 -> V_33 ) ;
if ( ! V_189 )
goto V_194;
V_191 = F_87 ( V_110 | V_117 ) ;
if ( ! V_191 )
goto V_145;
F_15 ( V_191 ) ;
if ( V_141 != - 1 ) {
V_192 = F_87 ( V_110 | V_117 ) ;
if ( ! V_192 ) {
F_22 ( V_191 ) ;
goto V_145;
}
F_15 ( V_192 ) ;
}
F_85 ( & V_24 -> error , 0 ) ;
F_139 (pagenr, rbio->dbitmap, rbio->stripe_npages) {
struct V_39 * V_97 ;
void * V_195 ;
for ( V_124 = 0 ; V_124 < V_63 ; V_124 ++ ) {
V_97 = F_78 ( V_24 , V_124 , V_94 , 0 ) ;
V_139 [ V_124 ] = F_13 ( V_97 ) ;
}
V_139 [ V_124 ++ ] = F_13 ( V_191 ) ;
if ( V_141 != - 1 ) {
V_139 [ V_124 ++ ] = F_13 ( V_192 ) ;
V_143 . V_144 ( V_24 -> V_71 , V_108 ,
V_139 ) ;
} else {
memcpy ( V_139 [ V_63 ] , V_139 [ 0 ] , V_108 ) ;
F_47 ( V_139 + 1 , V_63 - 1 , V_31 ) ;
}
V_97 = F_98 ( V_24 , V_24 -> V_186 , V_94 ) ;
V_195 = F_13 ( V_97 ) ;
if ( memcmp ( V_195 , V_139 [ V_24 -> V_186 ] , V_31 ) )
memcpy ( V_195 , V_139 [ V_24 -> V_186 ] , V_31 ) ;
else
F_142 ( V_24 -> V_113 , V_94 , 1 ) ;
F_14 ( V_97 ) ;
for ( V_124 = 0 ; V_124 < V_24 -> V_71 ; V_124 ++ )
F_14 ( F_78 ( V_24 , V_124 , V_94 , 0 ) ) ;
}
F_22 ( V_191 ) ;
if ( V_192 )
F_22 ( V_192 ) ;
V_194:
F_139 (pagenr, rbio->dbitmap, rbio->stripe_npages) {
struct V_39 * V_39 ;
V_39 = F_98 ( V_24 , V_24 -> V_186 , V_94 ) ;
V_27 = F_90 ( V_24 , & V_41 ,
V_39 , V_24 -> V_186 , V_94 , V_24 -> V_64 ) ;
if ( V_27 )
goto V_145;
}
if ( ! V_193 )
goto V_196;
F_139 (pagenr, pbitmap, rbio->stripe_npages) {
struct V_39 * V_39 ;
V_39 = F_98 ( V_24 , V_24 -> V_186 , V_94 ) ;
V_27 = F_90 ( V_24 , & V_41 , V_39 ,
V_35 -> V_147 [ V_24 -> V_186 ] ,
V_94 , V_24 -> V_64 ) ;
if ( V_27 )
goto V_145;
}
V_196:
V_63 = F_102 ( & V_41 ) ;
if ( ! V_63 ) {
F_71 ( V_24 , 0 , 0 ) ;
return;
}
F_85 ( & V_24 -> V_91 , V_63 ) ;
while ( 1 ) {
V_86 = F_103 ( & V_41 ) ;
if ( ! V_86 )
break;
V_86 -> V_90 = V_24 ;
V_86 -> V_148 = F_140 ;
F_33 ( ! F_20 ( V_88 , & V_86 -> V_89 ) ) ;
F_104 ( V_149 , V_86 ) ;
}
return;
V_145:
F_71 ( V_24 , - V_93 , 0 ) ;
}
static inline int F_143 ( struct V_23 * V_24 , int V_124 )
{
if ( V_124 >= 0 && V_124 < V_24 -> V_63 )
return 1 ;
return 0 ;
}
static void F_144 ( struct V_23 * V_24 )
{
if ( F_67 ( & V_24 -> error ) > V_24 -> V_35 -> V_92 )
goto V_145;
if ( V_24 -> V_111 >= 0 || V_24 -> V_112 >= 0 ) {
int V_197 = 0 , V_198 = - 1 ;
if ( F_143 ( V_24 , V_24 -> V_111 ) )
V_197 ++ ;
else if ( F_145 ( V_24 -> V_111 ) )
V_198 = V_24 -> V_111 ;
if ( F_143 ( V_24 , V_24 -> V_112 ) )
V_197 ++ ;
else if ( F_145 ( V_24 -> V_112 ) )
V_198 = V_24 -> V_112 ;
if ( V_197 > V_24 -> V_35 -> V_92 - 1 )
goto V_145;
if ( V_197 == 0 ) {
F_131 ( V_24 , 0 ) ;
return;
}
if ( V_198 != V_24 -> V_186 )
goto V_145;
F_128 ( V_24 ) ;
} else {
F_131 ( V_24 , 1 ) ;
}
return;
V_145:
F_71 ( V_24 , - V_93 , 0 ) ;
}
static void F_146 ( struct V_86 * V_86 , int V_84 )
{
struct V_23 * V_24 = V_86 -> V_90 ;
if ( V_84 )
F_76 ( V_24 , V_86 ) ;
else
F_107 ( V_86 ) ;
F_77 ( V_86 ) ;
if ( ! F_68 ( & V_24 -> V_91 ) )
return;
F_144 ( V_24 ) ;
}
static void F_147 ( struct V_23 * V_24 )
{
int V_158 = 0 ;
struct V_41 V_41 ;
int V_27 ;
int V_94 ;
int V_124 ;
struct V_86 * V_86 ;
V_27 = F_138 ( V_24 ) ;
if ( V_27 )
goto V_145;
F_25 ( & V_41 ) ;
F_85 ( & V_24 -> error , 0 ) ;
for ( V_124 = 0 ; V_124 < V_24 -> V_71 ; V_124 ++ ) {
F_139 (pagenr, rbio->dbitmap, rbio->stripe_npages) {
struct V_39 * V_39 ;
V_39 = F_78 ( V_24 , V_124 , V_94 , 1 ) ;
if ( V_39 )
continue;
V_39 = F_98 ( V_24 , V_124 , V_94 ) ;
if ( F_21 ( V_39 ) )
continue;
V_27 = F_90 ( V_24 , & V_41 , V_39 ,
V_124 , V_94 , V_24 -> V_64 ) ;
if ( V_27 )
goto V_145;
}
}
V_158 = F_102 ( & V_41 ) ;
if ( ! V_158 ) {
goto V_159;
}
F_85 ( & V_24 -> V_91 , V_158 ) ;
while ( 1 ) {
V_86 = F_103 ( & V_41 ) ;
if ( ! V_86 )
break;
V_86 -> V_90 = V_24 ;
V_86 -> V_148 = F_146 ;
F_112 ( V_24 -> V_47 , V_86 ,
V_160 ) ;
F_33 ( ! F_20 ( V_88 , & V_86 -> V_89 ) ) ;
F_104 ( V_161 , V_86 ) ;
}
return;
V_145:
F_71 ( V_24 , - V_93 , 0 ) ;
return;
V_159:
F_144 ( V_24 ) ;
}
static void F_148 ( struct V_172 * V_153 )
{
struct V_23 * V_24 ;
V_24 = F_117 ( V_153 , struct V_23 , V_153 ) ;
F_147 ( V_24 ) ;
}
static void F_63 ( struct V_23 * V_24 )
{
F_109 ( & V_24 -> V_153 , V_154 ,
F_148 , NULL , NULL ) ;
F_110 ( V_24 -> V_47 -> V_156 ,
& V_24 -> V_153 ) ;
}
void F_149 ( struct V_23 * V_24 )
{
if ( ! F_55 ( V_24 ) )
F_63 ( V_24 ) ;
}
