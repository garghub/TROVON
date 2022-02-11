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
if ( V_5 )
F_8 ( V_5 ) ;
return 0 ;
}
static void F_9 ( struct V_23 * V_24 )
{
int V_11 ;
char * V_25 ;
char * V_26 ;
int V_27 ;
V_27 = F_10 ( V_24 ) ;
if ( V_27 )
return;
for ( V_11 = 0 ; V_11 < V_24 -> V_28 ; V_11 ++ ) {
if ( ! V_24 -> V_29 [ V_11 ] )
continue;
V_25 = F_11 ( V_24 -> V_29 [ V_11 ] ) ;
V_26 = F_11 ( V_24 -> V_30 [ V_11 ] ) ;
memcpy ( V_26 , V_25 , V_31 ) ;
F_12 ( V_24 -> V_29 [ V_11 ] ) ;
F_12 ( V_24 -> V_30 [ V_11 ] ) ;
F_13 ( V_24 -> V_30 [ V_11 ] ) ;
}
F_14 ( V_32 , & V_24 -> V_33 ) ;
}
static int F_15 ( struct V_23 * V_24 )
{
T_1 V_34 = V_24 -> V_35 -> V_36 [ 0 ] ;
return F_16 ( V_34 >> 16 , V_10 ) ;
}
static void F_17 ( struct V_23 * V_37 , struct V_23 * V_38 )
{
int V_11 ;
struct V_39 * V_25 ;
struct V_39 * V_26 ;
if ( ! F_18 ( V_32 , & V_37 -> V_33 ) )
return;
for ( V_11 = 0 ; V_11 < V_38 -> V_28 ; V_11 ++ ) {
V_25 = V_37 -> V_30 [ V_11 ] ;
if ( ! V_25 || ! F_19 ( V_25 ) ) {
continue;
}
V_26 = V_38 -> V_30 [ V_11 ] ;
if ( V_26 )
F_20 ( V_26 ) ;
V_38 -> V_30 [ V_11 ] = V_25 ;
V_37 -> V_30 [ V_11 ] = NULL ;
}
}
static void F_21 ( struct V_23 * V_38 ,
struct V_23 * V_40 )
{
F_22 ( & V_38 -> V_41 , & V_40 -> V_41 ) ;
V_38 -> V_42 += V_40 -> V_42 ;
V_38 -> V_43 += V_40 -> V_43 ;
F_23 ( & V_40 -> V_41 ) ;
}
static void F_24 ( struct V_23 * V_24 )
{
int V_44 = F_15 ( V_24 ) ;
struct V_3 * V_4 ;
struct V_6 * V_8 ;
int V_45 = 0 ;
if ( ! F_18 ( V_46 , & V_24 -> V_33 ) )
return;
V_4 = V_24 -> V_47 -> V_13 ;
V_8 = V_4 -> V_4 + V_44 ;
F_25 ( & V_8 -> V_21 ) ;
F_25 ( & V_24 -> V_48 ) ;
if ( F_26 ( V_46 , & V_24 -> V_33 ) ) {
F_27 ( & V_24 -> V_19 ) ;
V_4 -> V_49 -= 1 ;
V_45 = 1 ;
if ( F_28 ( & V_24 -> V_41 ) ) {
if ( ! F_29 ( & V_24 -> V_20 ) ) {
F_27 ( & V_24 -> V_20 ) ;
F_30 ( & V_24 -> V_50 ) ;
F_31 ( ! F_29 ( & V_24 -> V_51 ) ) ;
}
}
}
F_32 ( & V_24 -> V_48 ) ;
F_32 ( & V_8 -> V_21 ) ;
if ( V_45 )
F_33 ( V_24 ) ;
}
static void F_34 ( struct V_23 * V_24 )
{
struct V_3 * V_4 ;
unsigned long V_33 ;
if ( ! F_18 ( V_46 , & V_24 -> V_33 ) )
return;
V_4 = V_24 -> V_47 -> V_13 ;
F_35 ( & V_4 -> V_18 , V_33 ) ;
F_24 ( V_24 ) ;
F_36 ( & V_4 -> V_18 , V_33 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_33 ;
struct V_23 * V_24 ;
V_4 = V_2 -> V_13 ;
F_35 ( & V_4 -> V_18 , V_33 ) ;
while ( ! F_29 ( & V_4 -> V_19 ) ) {
V_24 = F_38 ( V_4 -> V_19 . V_52 ,
struct V_23 ,
V_19 ) ;
F_24 ( V_24 ) ;
}
F_36 ( & V_4 -> V_18 , V_33 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_13 )
return;
F_37 ( V_2 ) ;
F_8 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
}
static void F_40 ( struct V_23 * V_24 )
{
struct V_3 * V_4 ;
unsigned long V_33 ;
if ( ! F_18 ( V_32 , & V_24 -> V_33 ) )
return;
V_4 = V_24 -> V_47 -> V_13 ;
F_35 ( & V_4 -> V_18 , V_33 ) ;
F_25 ( & V_24 -> V_48 ) ;
if ( ! F_41 ( V_46 , & V_24 -> V_33 ) )
F_42 ( & V_24 -> V_50 ) ;
if ( ! F_29 ( & V_24 -> V_19 ) ) {
F_43 ( & V_24 -> V_19 , & V_4 -> V_19 ) ;
} else {
F_44 ( & V_24 -> V_19 , & V_4 -> V_19 ) ;
V_4 -> V_49 += 1 ;
}
F_32 ( & V_24 -> V_48 ) ;
if ( V_4 -> V_49 > V_53 ) {
struct V_23 * V_54 ;
V_54 = F_38 ( V_4 -> V_19 . V_55 ,
struct V_23 ,
V_19 ) ;
if ( V_54 != V_24 )
F_24 ( V_54 ) ;
}
F_36 ( & V_4 -> V_18 , V_33 ) ;
return;
}
static void F_45 ( void * * V_56 , int V_57 , T_2 V_58 )
{
int V_59 = 0 ;
int V_60 = 0 ;
void * V_38 = V_56 [ V_57 ] ;
while( V_57 > 0 ) {
V_60 = F_46 ( V_57 , V_61 ) ;
F_47 ( V_60 , V_58 , V_38 , V_56 + V_59 ) ;
V_57 -= V_60 ;
V_59 += V_60 ;
}
}
static int F_48 ( struct V_23 * V_24 )
{
unsigned long V_62 = V_24 -> V_42 ;
int V_27 = 1 ;
if ( V_62 != V_24 -> V_63 * V_24 -> V_64 )
V_27 = 0 ;
F_31 ( V_62 > V_24 -> V_63 * V_24 -> V_64 ) ;
return V_27 ;
}
static int F_49 ( struct V_23 * V_24 )
{
unsigned long V_33 ;
int V_27 ;
F_35 ( & V_24 -> V_48 , V_33 ) ;
V_27 = F_48 ( V_24 ) ;
F_36 ( & V_24 -> V_48 , V_33 ) ;
return V_27 ;
}
static int F_50 ( struct V_23 * V_65 ,
struct V_23 * V_7 )
{
if ( F_18 ( V_66 , & V_65 -> V_33 ) ||
F_18 ( V_66 , & V_7 -> V_33 ) )
return 0 ;
if ( F_18 ( V_46 , & V_65 -> V_33 ) ||
F_18 ( V_46 , & V_7 -> V_33 ) )
return 0 ;
if ( V_65 -> V_35 -> V_36 [ 0 ] !=
V_7 -> V_35 -> V_36 [ 0 ] )
return 0 ;
if ( V_65 -> V_67 != V_7 -> V_67 )
return 0 ;
if ( V_65 -> V_67 == V_68 ||
V_7 -> V_67 == V_68 )
return 0 ;
if ( V_65 -> V_67 == V_69 ||
V_7 -> V_67 == V_69 )
return 0 ;
return 1 ;
}
static struct V_39 * F_51 ( struct V_23 * V_24 , int V_70 )
{
V_70 += ( V_24 -> V_63 * V_24 -> V_64 ) >> V_71 ;
return V_24 -> V_30 [ V_70 ] ;
}
static struct V_39 * F_52 ( struct V_23 * V_24 , int V_70 )
{
if ( V_24 -> V_63 + 1 == V_24 -> V_72 )
return NULL ;
V_70 += ( ( V_24 -> V_63 + 1 ) * V_24 -> V_64 ) >>
V_71 ;
return V_24 -> V_30 [ V_70 ] ;
}
static T_3 int F_53 ( struct V_23 * V_24 )
{
int V_44 = F_15 ( V_24 ) ;
struct V_6 * V_8 = V_24 -> V_47 -> V_13 -> V_4 + V_44 ;
struct V_23 * V_7 ;
struct V_23 * V_73 ;
unsigned long V_33 ;
F_54 ( V_22 ) ;
struct V_23 * V_45 = NULL ;
struct V_23 * V_74 = NULL ;
int V_27 = 0 ;
int V_75 = 0 ;
F_35 ( & V_8 -> V_21 , V_33 ) ;
F_55 (cur, &h->hash_list, hash_list) {
V_75 ++ ;
if ( V_7 -> V_35 -> V_36 [ 0 ] == V_24 -> V_35 -> V_36 [ 0 ] ) {
F_25 ( & V_7 -> V_48 ) ;
if ( F_28 ( & V_7 -> V_41 ) &&
F_29 ( & V_7 -> V_51 ) &&
F_18 ( V_46 , & V_7 -> V_33 ) &&
! F_18 ( V_66 , & V_7 -> V_33 ) ) {
F_27 ( & V_7 -> V_20 ) ;
F_30 ( & V_7 -> V_50 ) ;
F_17 ( V_7 , V_24 ) ;
V_74 = V_7 ;
F_32 ( & V_7 -> V_48 ) ;
goto V_76;
}
if ( F_50 ( V_7 , V_24 ) ) {
F_21 ( V_7 , V_24 ) ;
F_32 ( & V_7 -> V_48 ) ;
V_45 = V_24 ;
V_27 = 1 ;
goto V_77;
}
F_55 (pending, &cur->plug_list,
plug_list) {
if ( F_50 ( V_73 , V_24 ) ) {
F_21 ( V_73 , V_24 ) ;
F_32 ( & V_7 -> V_48 ) ;
V_45 = V_24 ;
V_27 = 1 ;
goto V_77;
}
}
F_56 ( & V_24 -> V_51 , & V_7 -> V_51 ) ;
F_32 ( & V_7 -> V_48 ) ;
V_27 = 1 ;
goto V_77;
}
}
V_76:
F_42 ( & V_24 -> V_50 ) ;
F_44 ( & V_24 -> V_20 , & V_8 -> V_20 ) ;
V_77:
F_36 ( & V_8 -> V_21 , V_33 ) ;
if ( V_74 )
F_34 ( V_74 ) ;
if ( V_45 )
F_33 ( V_45 ) ;
return V_27 ;
}
static T_3 void F_57 ( struct V_23 * V_24 )
{
int V_44 ;
struct V_6 * V_8 ;
unsigned long V_33 ;
int V_78 = 0 ;
V_44 = F_15 ( V_24 ) ;
V_8 = V_24 -> V_47 -> V_13 -> V_4 + V_44 ;
if ( F_29 ( & V_24 -> V_51 ) )
F_40 ( V_24 ) ;
F_35 ( & V_8 -> V_21 , V_33 ) ;
F_25 ( & V_24 -> V_48 ) ;
if ( ! F_29 ( & V_24 -> V_20 ) ) {
if ( F_29 ( & V_24 -> V_51 ) &&
F_18 ( V_46 , & V_24 -> V_33 ) ) {
V_78 = 1 ;
F_58 ( V_66 , & V_24 -> V_33 ) ;
F_31 ( ! F_28 ( & V_24 -> V_41 ) ) ;
goto V_79;
}
F_27 ( & V_24 -> V_20 ) ;
F_30 ( & V_24 -> V_50 ) ;
if ( ! F_29 ( & V_24 -> V_51 ) ) {
struct V_23 * V_52 ;
struct V_80 * V_81 = V_24 -> V_51 . V_52 ;
V_52 = F_38 ( V_81 , struct V_23 ,
V_51 ) ;
F_27 ( & V_24 -> V_51 ) ;
F_44 ( & V_52 -> V_20 , & V_8 -> V_20 ) ;
F_42 ( & V_52 -> V_50 ) ;
F_32 ( & V_24 -> V_48 ) ;
F_36 ( & V_8 -> V_21 , V_33 ) ;
if ( V_52 -> V_67 == V_82 )
F_59 ( V_52 ) ;
else if ( V_52 -> V_67 == V_69 ) {
F_17 ( V_24 , V_52 ) ;
F_59 ( V_52 ) ;
} else if ( V_52 -> V_67 == V_83 ) {
F_17 ( V_24 , V_52 ) ;
F_60 ( V_52 ) ;
} else if ( V_52 -> V_67 == V_68 ) {
F_17 ( V_24 , V_52 ) ;
F_61 ( V_52 ) ;
}
goto V_84;
} else if ( F_62 ( & V_8 -> V_22 ) ) {
F_32 ( & V_24 -> V_48 ) ;
F_36 ( & V_8 -> V_21 , V_33 ) ;
F_63 ( & V_8 -> V_22 ) ;
goto V_84;
}
}
V_79:
F_32 ( & V_24 -> V_48 ) ;
F_36 ( & V_8 -> V_21 , V_33 ) ;
V_84:
if ( ! V_78 )
F_34 ( V_24 ) ;
}
static void F_33 ( struct V_23 * V_24 )
{
int V_11 ;
F_64 ( F_65 ( & V_24 -> V_50 ) < 0 ) ;
if ( ! F_66 ( & V_24 -> V_50 ) )
return;
F_64 ( ! F_29 ( & V_24 -> V_19 ) ) ;
F_64 ( ! F_29 ( & V_24 -> V_20 ) ) ;
F_64 ( ! F_28 ( & V_24 -> V_41 ) ) ;
for ( V_11 = 0 ; V_11 < V_24 -> V_28 ; V_11 ++ ) {
if ( V_24 -> V_30 [ V_11 ] ) {
F_20 ( V_24 -> V_30 [ V_11 ] ) ;
V_24 -> V_30 [ V_11 ] = NULL ;
}
}
F_67 ( V_24 -> V_35 ) ;
F_68 ( V_24 ) ;
}
static void F_69 ( struct V_23 * V_24 )
{
F_57 ( V_24 ) ;
F_33 ( V_24 ) ;
}
static void F_70 ( struct V_23 * V_24 , int V_85 )
{
struct V_86 * V_7 = F_71 ( & V_24 -> V_41 ) ;
struct V_86 * V_52 ;
if ( V_24 -> V_43 )
F_72 ( V_24 -> V_47 , V_24 -> V_43 ) ;
F_69 ( V_24 ) ;
while ( V_7 ) {
V_52 = V_7 -> V_87 ;
V_7 -> V_87 = NULL ;
V_7 -> V_88 = V_85 ;
F_73 ( V_7 ) ;
V_7 = V_52 ;
}
}
static void F_74 ( struct V_86 * V_86 )
{
struct V_23 * V_24 = V_86 -> V_89 ;
int V_85 = V_86 -> V_88 ;
if ( V_85 )
F_75 ( V_24 , V_86 ) ;
F_76 ( V_86 ) ;
if ( ! F_66 ( & V_24 -> V_90 ) )
return;
V_85 = 0 ;
if ( F_65 ( & V_24 -> error ) > V_24 -> V_35 -> V_91 )
V_85 = - V_92 ;
F_70 ( V_24 , V_85 ) ;
return;
}
static struct V_39 * F_77 ( struct V_23 * V_24 ,
int V_70 , int V_93 , int V_94 )
{
int V_95 ;
struct V_39 * V_96 = NULL ;
V_95 = V_70 * ( V_24 -> V_64 >> V_97 ) + V_93 ;
F_78 ( & V_24 -> V_48 ) ;
V_96 = V_24 -> V_29 [ V_95 ] ;
F_79 ( & V_24 -> V_48 ) ;
if ( V_96 || V_94 )
return V_96 ;
return V_24 -> V_30 [ V_95 ] ;
}
static unsigned long F_80 ( unsigned long V_64 , int V_98 )
{
unsigned long V_99 = V_64 * V_98 ;
return F_81 ( V_99 , V_31 ) ;
}
static struct V_23 * F_82 ( struct V_100 * V_101 ,
struct V_102 * V_35 , T_1 V_64 )
{
struct V_23 * V_24 ;
int V_63 = 0 ;
int V_72 = V_35 -> V_103 - V_35 -> V_104 ;
int V_105 = F_80 ( V_64 , V_72 ) ;
int V_106 = F_81 ( V_64 , V_107 ) ;
void * V_96 ;
V_24 = F_2 ( sizeof( * V_24 ) + V_105 * sizeof( struct V_39 * ) * 2 +
F_81 ( V_106 , V_108 / 8 ) ,
V_109 ) ;
if ( ! V_24 )
return F_83 ( - V_17 ) ;
F_23 ( & V_24 -> V_41 ) ;
F_5 ( & V_24 -> V_51 ) ;
F_4 ( & V_24 -> V_48 ) ;
F_5 ( & V_24 -> V_19 ) ;
F_5 ( & V_24 -> V_20 ) ;
V_24 -> V_35 = V_35 ;
V_24 -> V_47 = V_101 -> V_47 ;
V_24 -> V_64 = V_64 ;
V_24 -> V_28 = V_105 ;
V_24 -> V_72 = V_72 ;
V_24 -> V_106 = V_106 ;
V_24 -> V_110 = - 1 ;
V_24 -> V_111 = - 1 ;
F_84 ( & V_24 -> V_50 , 1 ) ;
F_84 ( & V_24 -> error , 0 ) ;
F_84 ( & V_24 -> V_90 , 0 ) ;
V_96 = V_24 + 1 ;
V_24 -> V_30 = V_96 ;
V_24 -> V_29 = V_96 + sizeof( struct V_39 * ) * V_105 ;
V_24 -> V_112 = V_96 + sizeof( struct V_39 * ) * V_105 * 2 ;
if ( V_35 -> V_113 & V_114 )
V_63 = V_72 - 1 ;
else if ( V_35 -> V_113 & V_115 )
V_63 = V_72 - 2 ;
else
F_85 () ;
V_24 -> V_63 = V_63 ;
return V_24 ;
}
static int F_10 ( struct V_23 * V_24 )
{
int V_11 ;
struct V_39 * V_39 ;
for ( V_11 = 0 ; V_11 < V_24 -> V_28 ; V_11 ++ ) {
if ( V_24 -> V_30 [ V_11 ] )
continue;
V_39 = F_86 ( V_109 | V_116 ) ;
if ( ! V_39 )
return - V_17 ;
V_24 -> V_30 [ V_11 ] = V_39 ;
F_87 ( V_39 ) ;
}
return 0 ;
}
static int F_88 ( struct V_23 * V_24 )
{
int V_11 ;
struct V_39 * V_39 ;
V_11 = ( V_24 -> V_63 * V_24 -> V_64 ) >> V_71 ;
for (; V_11 < V_24 -> V_28 ; V_11 ++ ) {
if ( V_24 -> V_30 [ V_11 ] )
continue;
V_39 = F_86 ( V_109 | V_116 ) ;
if ( ! V_39 )
return - V_17 ;
V_24 -> V_30 [ V_11 ] = V_39 ;
}
return 0 ;
}
static int F_89 ( struct V_23 * V_24 ,
struct V_41 * V_41 ,
struct V_39 * V_39 ,
int V_117 ,
unsigned long V_118 ,
unsigned long V_119 )
{
struct V_86 * V_65 = V_41 -> V_120 ;
T_1 V_121 = 0 ;
int V_27 ;
struct V_86 * V_86 ;
struct V_122 * V_123 ;
T_1 V_124 ;
V_123 = & V_24 -> V_35 -> V_125 [ V_117 ] ;
V_124 = V_123 -> V_126 + ( V_118 << V_71 ) ;
if ( ! V_123 -> V_127 -> V_128 )
return F_90 ( V_24 , V_117 ) ;
if ( V_65 ) {
V_121 = ( T_1 ) V_65 -> V_129 . V_130 << 9 ;
V_121 += V_65 -> V_129 . V_131 ;
if ( V_121 == V_124 && V_123 -> V_127 -> V_128 &&
! V_65 -> V_88 &&
V_65 -> V_132 == V_123 -> V_127 -> V_128 ) {
V_27 = F_91 ( V_65 , V_39 , V_31 , 0 ) ;
if ( V_27 == V_31 )
return 0 ;
}
}
V_86 = F_92 ( V_109 , V_119 >> V_97 ? : 1 ) ;
if ( ! V_86 )
return - V_17 ;
V_86 -> V_129 . V_131 = 0 ;
V_86 -> V_132 = V_123 -> V_127 -> V_128 ;
V_86 -> V_129 . V_130 = V_124 >> 9 ;
F_91 ( V_86 , V_39 , V_31 , 0 ) ;
F_93 ( V_41 , V_86 ) ;
return 0 ;
}
static void F_94 ( struct V_23 * V_24 )
{
if ( V_24 -> V_110 >= 0 || V_24 -> V_111 >= 0 ) {
F_31 ( V_24 -> V_110 == V_24 -> V_72 - 1 ) ;
F_95 ( V_24 ) ;
} else {
F_96 ( V_24 ) ;
}
}
static struct V_39 * F_97 ( struct V_23 * V_24 , int V_123 , int V_39 )
{
int V_70 ;
V_70 = V_123 * ( V_24 -> V_64 >> V_71 ) ;
V_70 += V_39 ;
return V_24 -> V_30 [ V_70 ] ;
}
static void F_98 ( struct V_23 * V_24 )
{
struct V_86 * V_86 ;
T_1 V_133 ;
unsigned long V_134 ;
unsigned long V_118 ;
struct V_39 * V_96 ;
int V_11 ;
F_78 ( & V_24 -> V_48 ) ;
F_99 (bio, &rbio->bio_list) {
V_133 = ( T_1 ) V_86 -> V_129 . V_130 << 9 ;
V_134 = V_133 - V_24 -> V_35 -> V_36 [ 0 ] ;
V_118 = V_134 >> V_71 ;
for ( V_11 = 0 ; V_11 < V_86 -> V_135 ; V_11 ++ ) {
V_96 = V_86 -> V_136 [ V_11 ] . V_137 ;
V_24 -> V_29 [ V_118 + V_11 ] = V_96 ;
}
}
F_79 ( & V_24 -> V_48 ) ;
}
static T_3 void F_96 ( struct V_23 * V_24 )
{
struct V_102 * V_35 = V_24 -> V_35 ;
void * V_138 [ V_24 -> V_72 ] ;
int V_64 = V_24 -> V_64 ;
int V_63 = V_24 -> V_63 ;
int V_123 ;
int V_93 ;
int V_139 = - 1 ;
int V_140 = - 1 ;
struct V_41 V_41 ;
struct V_86 * V_86 ;
int V_141 = V_64 >> V_71 ;
int V_27 ;
F_23 ( & V_41 ) ;
if ( V_24 -> V_72 - V_24 -> V_63 == 1 ) {
V_139 = V_24 -> V_72 - 1 ;
} else if ( V_24 -> V_72 - V_24 -> V_63 == 2 ) {
V_139 = V_24 -> V_72 - 2 ;
V_140 = V_24 -> V_72 - 1 ;
} else {
F_85 () ;
}
F_78 ( & V_24 -> V_48 ) ;
F_14 ( V_66 , & V_24 -> V_33 ) ;
F_79 ( & V_24 -> V_48 ) ;
F_84 ( & V_24 -> error , 0 ) ;
F_98 ( V_24 ) ;
if ( ! F_49 ( V_24 ) )
F_9 ( V_24 ) ;
else
F_58 ( V_32 , & V_24 -> V_33 ) ;
for ( V_93 = 0 ; V_93 < V_141 ; V_93 ++ ) {
struct V_39 * V_96 ;
for ( V_123 = 0 ; V_123 < V_63 ; V_123 ++ ) {
V_96 = F_77 ( V_24 , V_123 , V_93 , 0 ) ;
V_138 [ V_123 ] = F_11 ( V_96 ) ;
}
V_96 = F_51 ( V_24 , V_93 ) ;
F_13 ( V_96 ) ;
V_138 [ V_123 ++ ] = F_11 ( V_96 ) ;
if ( V_140 != - 1 ) {
V_96 = F_52 ( V_24 , V_93 ) ;
F_13 ( V_96 ) ;
V_138 [ V_123 ++ ] = F_11 ( V_96 ) ;
V_142 . V_143 ( V_24 -> V_72 , V_107 ,
V_138 ) ;
} else {
memcpy ( V_138 [ V_63 ] , V_138 [ 0 ] , V_107 ) ;
F_45 ( V_138 + 1 , V_63 - 1 , V_31 ) ;
}
for ( V_123 = 0 ; V_123 < V_24 -> V_72 ; V_123 ++ )
F_12 ( F_77 ( V_24 , V_123 , V_93 , 0 ) ) ;
}
for ( V_123 = 0 ; V_123 < V_24 -> V_72 ; V_123 ++ ) {
for ( V_93 = 0 ; V_93 < V_141 ; V_93 ++ ) {
struct V_39 * V_39 ;
if ( V_123 < V_24 -> V_63 ) {
V_39 = F_77 ( V_24 , V_123 , V_93 , 1 ) ;
if ( ! V_39 )
continue;
} else {
V_39 = F_97 ( V_24 , V_123 , V_93 ) ;
}
V_27 = F_89 ( V_24 , & V_41 ,
V_39 , V_123 , V_93 , V_24 -> V_64 ) ;
if ( V_27 )
goto V_144;
}
}
if ( F_100 ( ! V_35 -> V_104 ) )
goto V_145;
for ( V_123 = 0 ; V_123 < V_24 -> V_72 ; V_123 ++ ) {
if ( ! V_35 -> V_146 [ V_123 ] )
continue;
for ( V_93 = 0 ; V_93 < V_141 ; V_93 ++ ) {
struct V_39 * V_39 ;
if ( V_123 < V_24 -> V_63 ) {
V_39 = F_77 ( V_24 , V_123 , V_93 , 1 ) ;
if ( ! V_39 )
continue;
} else {
V_39 = F_97 ( V_24 , V_123 , V_93 ) ;
}
V_27 = F_89 ( V_24 , & V_41 , V_39 ,
V_24 -> V_35 -> V_146 [ V_123 ] ,
V_93 , V_24 -> V_64 ) ;
if ( V_27 )
goto V_144;
}
}
V_145:
F_84 ( & V_24 -> V_90 , F_101 ( & V_41 ) ) ;
F_31 ( F_65 ( & V_24 -> V_90 ) == 0 ) ;
while ( 1 ) {
V_86 = F_102 ( & V_41 ) ;
if ( ! V_86 )
break;
V_86 -> V_89 = V_24 ;
V_86 -> V_147 = F_74 ;
F_103 ( V_148 , V_86 ) ;
}
return;
V_144:
F_70 ( V_24 , - V_92 ) ;
}
static int F_104 ( struct V_23 * V_24 ,
struct V_86 * V_86 )
{
T_1 V_126 = V_86 -> V_129 . V_130 ;
T_1 V_149 ;
int V_11 ;
struct V_122 * V_123 ;
V_126 <<= 9 ;
for ( V_11 = 0 ; V_11 < V_24 -> V_35 -> V_103 ; V_11 ++ ) {
V_123 = & V_24 -> V_35 -> V_125 [ V_11 ] ;
V_149 = V_123 -> V_126 ;
if ( V_126 >= V_149 &&
V_126 < V_149 + V_24 -> V_64 &&
V_86 -> V_132 == V_123 -> V_127 -> V_128 ) {
return V_11 ;
}
}
return - 1 ;
}
static int F_105 ( struct V_23 * V_24 ,
struct V_86 * V_86 )
{
T_1 V_150 = V_86 -> V_129 . V_130 ;
T_1 V_149 ;
int V_11 ;
V_150 <<= 9 ;
for ( V_11 = 0 ; V_11 < V_24 -> V_63 ; V_11 ++ ) {
V_149 = V_24 -> V_35 -> V_36 [ V_11 ] ;
if ( V_150 >= V_149 &&
V_150 < V_149 + V_24 -> V_64 ) {
return V_11 ;
}
}
return - 1 ;
}
static int F_90 ( struct V_23 * V_24 , int V_151 )
{
unsigned long V_33 ;
int V_27 = 0 ;
F_35 ( & V_24 -> V_48 , V_33 ) ;
if ( V_24 -> V_110 == V_151 || V_24 -> V_111 == V_151 )
goto V_77;
if ( V_24 -> V_110 == - 1 ) {
V_24 -> V_110 = V_151 ;
F_42 ( & V_24 -> error ) ;
} else if ( V_24 -> V_111 == - 1 ) {
V_24 -> V_111 = V_151 ;
F_42 ( & V_24 -> error ) ;
} else {
V_27 = - V_92 ;
}
V_77:
F_36 ( & V_24 -> V_48 , V_33 ) ;
return V_27 ;
}
static int F_75 ( struct V_23 * V_24 ,
struct V_86 * V_86 )
{
int V_151 = F_104 ( V_24 , V_86 ) ;
if ( V_151 < 0 )
return - V_92 ;
return F_90 ( V_24 , V_151 ) ;
}
static void F_106 ( struct V_86 * V_86 )
{
int V_11 ;
struct V_39 * V_96 ;
for ( V_11 = 0 ; V_11 < V_86 -> V_135 ; V_11 ++ ) {
V_96 = V_86 -> V_136 [ V_11 ] . V_137 ;
F_13 ( V_96 ) ;
}
}
static void F_107 ( struct V_86 * V_86 )
{
struct V_23 * V_24 = V_86 -> V_89 ;
if ( V_86 -> V_88 )
F_75 ( V_24 , V_86 ) ;
else
F_106 ( V_86 ) ;
F_76 ( V_86 ) ;
if ( ! F_66 ( & V_24 -> V_90 ) )
return;
if ( F_65 ( & V_24 -> error ) > V_24 -> V_35 -> V_91 )
goto V_144;
F_94 ( V_24 ) ;
return;
V_144:
F_70 ( V_24 , - V_92 ) ;
}
static void F_60 ( struct V_23 * V_24 )
{
F_108 ( & V_24 -> V_152 , V_153 ,
V_154 , NULL , NULL ) ;
F_109 ( V_24 -> V_47 -> V_155 ,
& V_24 -> V_152 ) ;
}
static void F_59 ( struct V_23 * V_24 )
{
F_108 ( & V_24 -> V_152 , V_153 ,
V_156 , NULL , NULL ) ;
F_109 ( V_24 -> V_47 -> V_155 ,
& V_24 -> V_152 ) ;
}
static int F_110 ( struct V_23 * V_24 )
{
int V_157 = 0 ;
struct V_41 V_41 ;
int V_27 ;
int V_28 = F_81 ( V_24 -> V_64 , V_31 ) ;
int V_93 ;
int V_123 ;
struct V_86 * V_86 ;
F_23 ( & V_41 ) ;
V_27 = F_10 ( V_24 ) ;
if ( V_27 )
goto V_144;
F_98 ( V_24 ) ;
F_84 ( & V_24 -> error , 0 ) ;
for ( V_123 = 0 ; V_123 < V_24 -> V_63 ; V_123 ++ ) {
for ( V_93 = 0 ; V_93 < V_28 ; V_93 ++ ) {
struct V_39 * V_39 ;
V_39 = F_77 ( V_24 , V_123 , V_93 , 1 ) ;
if ( V_39 )
continue;
V_39 = F_97 ( V_24 , V_123 , V_93 ) ;
if ( F_19 ( V_39 ) )
continue;
V_27 = F_89 ( V_24 , & V_41 , V_39 ,
V_123 , V_93 , V_24 -> V_64 ) ;
if ( V_27 )
goto V_144;
}
}
V_157 = F_101 ( & V_41 ) ;
if ( ! V_157 ) {
goto V_158;
}
F_84 ( & V_24 -> V_90 , V_157 ) ;
while ( 1 ) {
V_86 = F_102 ( & V_41 ) ;
if ( ! V_86 )
break;
V_86 -> V_89 = V_24 ;
V_86 -> V_147 = F_107 ;
F_111 ( V_24 -> V_47 , V_86 ,
V_159 ) ;
F_103 ( V_160 , V_86 ) ;
}
return 0 ;
V_144:
F_70 ( V_24 , - V_92 ) ;
return - V_92 ;
V_158:
F_94 ( V_24 ) ;
return 0 ;
}
static int F_112 ( struct V_23 * V_24 )
{
int V_27 ;
V_27 = F_88 ( V_24 ) ;
if ( V_27 ) {
F_33 ( V_24 ) ;
return V_27 ;
}
V_27 = F_53 ( V_24 ) ;
if ( V_27 == 0 )
F_96 ( V_24 ) ;
return 0 ;
}
static int F_113 ( struct V_23 * V_24 )
{
int V_27 ;
V_27 = F_53 ( V_24 ) ;
if ( V_27 == 0 )
F_60 ( V_24 ) ;
return 0 ;
}
static int F_114 ( struct V_23 * V_24 )
{
if ( ! F_49 ( V_24 ) )
return F_113 ( V_24 ) ;
return F_112 ( V_24 ) ;
}
static int F_115 ( void * V_161 , struct V_80 * V_162 , struct V_80 * V_163 )
{
struct V_23 * V_164 = F_116 ( V_162 , struct V_23 ,
V_51 ) ;
struct V_23 * V_165 = F_116 ( V_163 , struct V_23 ,
V_51 ) ;
T_1 V_166 = V_164 -> V_41 . V_81 -> V_129 . V_130 ;
T_1 V_167 = V_165 -> V_41 . V_81 -> V_129 . V_130 ;
if ( V_166 < V_167 )
return - 1 ;
if ( V_166 > V_167 )
return 1 ;
return 0 ;
}
static void F_117 ( struct V_168 * V_169 )
{
struct V_23 * V_7 ;
struct V_23 * V_65 = NULL ;
F_118 ( NULL , & V_169 -> V_170 , F_115 ) ;
while ( ! F_29 ( & V_169 -> V_170 ) ) {
V_7 = F_38 ( V_169 -> V_170 . V_52 ,
struct V_23 , V_51 ) ;
F_27 ( & V_7 -> V_51 ) ;
if ( F_49 ( V_7 ) ) {
F_112 ( V_7 ) ;
continue;
}
if ( V_65 ) {
if ( F_50 ( V_65 , V_7 ) ) {
F_21 ( V_65 , V_7 ) ;
F_33 ( V_7 ) ;
continue;
}
F_114 ( V_65 ) ;
}
V_65 = V_7 ;
}
if ( V_65 ) {
F_114 ( V_65 ) ;
}
F_68 ( V_169 ) ;
}
static void F_119 ( struct V_171 * V_152 )
{
struct V_168 * V_169 ;
V_169 = F_116 ( V_152 , struct V_168 , V_152 ) ;
F_117 ( V_169 ) ;
}
static void F_120 ( struct V_172 * V_173 , bool V_174 )
{
struct V_168 * V_169 ;
V_169 = F_116 ( V_173 , struct V_168 , V_173 ) ;
if ( V_174 ) {
F_108 ( & V_169 -> V_152 , V_153 ,
F_119 , NULL , NULL ) ;
F_109 ( V_169 -> V_2 -> V_155 ,
& V_169 -> V_152 ) ;
return;
}
F_117 ( V_169 ) ;
}
int F_121 ( struct V_100 * V_101 , struct V_86 * V_86 ,
struct V_102 * V_35 , T_1 V_64 )
{
struct V_23 * V_24 ;
struct V_168 * V_169 = NULL ;
struct V_172 * V_173 ;
int V_27 ;
V_24 = F_82 ( V_101 , V_35 , V_64 ) ;
if ( F_122 ( V_24 ) ) {
F_67 ( V_35 ) ;
return F_123 ( V_24 ) ;
}
F_93 ( & V_24 -> V_41 , V_86 ) ;
V_24 -> V_42 = V_86 -> V_129 . V_131 ;
V_24 -> V_67 = V_83 ;
F_124 ( V_101 -> V_47 ) ;
V_24 -> V_43 = 1 ;
if ( F_49 ( V_24 ) ) {
V_27 = F_112 ( V_24 ) ;
if ( V_27 )
F_125 ( V_101 -> V_47 ) ;
return V_27 ;
}
V_173 = F_126 ( F_120 , V_101 -> V_47 ,
sizeof( * V_169 ) ) ;
if ( V_173 ) {
V_169 = F_116 ( V_173 , struct V_168 , V_173 ) ;
if ( ! V_169 -> V_2 ) {
V_169 -> V_2 = V_101 -> V_47 ;
F_5 ( & V_169 -> V_170 ) ;
}
F_56 ( & V_24 -> V_51 , & V_169 -> V_170 ) ;
V_27 = 0 ;
} else {
V_27 = F_114 ( V_24 ) ;
if ( V_27 )
F_125 ( V_101 -> V_47 ) ;
}
return V_27 ;
}
static void F_127 ( struct V_23 * V_24 )
{
int V_93 , V_123 ;
void * * V_138 ;
int V_110 = - 1 , V_111 = - 1 ;
int V_28 = F_81 ( V_24 -> V_64 , V_31 ) ;
struct V_39 * V_39 ;
int V_85 ;
int V_11 ;
V_138 = F_128 ( V_24 -> V_72 , sizeof( void * ) , V_109 ) ;
if ( ! V_138 ) {
V_85 = - V_17 ;
goto V_175;
}
V_110 = V_24 -> V_110 ;
V_111 = V_24 -> V_111 ;
if ( V_24 -> V_67 == V_82 ||
V_24 -> V_67 == V_69 ) {
F_78 ( & V_24 -> V_48 ) ;
F_14 ( V_66 , & V_24 -> V_33 ) ;
F_79 ( & V_24 -> V_48 ) ;
}
F_98 ( V_24 ) ;
for ( V_93 = 0 ; V_93 < V_28 ; V_93 ++ ) {
if ( V_24 -> V_67 == V_68 &&
! F_18 ( V_93 , V_24 -> V_112 ) )
continue;
for ( V_123 = 0 ; V_123 < V_24 -> V_72 ; V_123 ++ ) {
if ( ( V_24 -> V_67 == V_82 ||
V_24 -> V_67 == V_69 ) &&
( V_123 == V_110 || V_123 == V_111 ) ) {
V_39 = F_77 ( V_24 , V_123 , V_93 , 0 ) ;
} else {
V_39 = F_97 ( V_24 , V_123 , V_93 ) ;
}
V_138 [ V_123 ] = F_11 ( V_39 ) ;
}
if ( V_24 -> V_35 -> V_113 & V_115 ) {
if ( V_111 < 0 ) {
if ( V_110 == V_24 -> V_63 ) {
V_85 = - V_92 ;
goto V_144;
}
goto V_176;
}
if ( V_110 > V_111 ) {
int V_177 = V_111 ;
V_111 = V_110 ;
V_110 = V_177 ;
}
if ( V_24 -> V_35 -> V_36 [ V_111 ] == V_178 ) {
if ( V_24 -> V_35 -> V_36 [ V_110 ] ==
V_179 ) {
V_85 = - V_92 ;
goto V_144;
}
goto V_176;
}
if ( V_24 -> V_35 -> V_36 [ V_111 ] == V_179 ) {
F_129 ( V_24 -> V_72 ,
V_107 , V_110 , V_138 ) ;
} else {
F_130 ( V_24 -> V_72 ,
V_107 , V_110 , V_111 ,
V_138 ) ;
}
} else {
void * V_96 ;
F_31 ( V_111 != - 1 ) ;
V_176:
memcpy ( V_138 [ V_110 ] ,
V_138 [ V_24 -> V_63 ] ,
V_31 ) ;
V_96 = V_138 [ V_110 ] ;
for ( V_123 = V_110 ; V_123 < V_24 -> V_63 - 1 ; V_123 ++ )
V_138 [ V_123 ] = V_138 [ V_123 + 1 ] ;
V_138 [ V_24 -> V_63 - 1 ] = V_96 ;
F_45 ( V_138 , V_24 -> V_63 - 1 , V_31 ) ;
}
if ( V_24 -> V_67 == V_83 ) {
for ( V_11 = 0 ; V_11 < V_28 ; V_11 ++ ) {
if ( V_110 != - 1 ) {
V_39 = F_97 ( V_24 , V_110 , V_11 ) ;
F_13 ( V_39 ) ;
}
if ( V_111 != - 1 ) {
V_39 = F_97 ( V_24 , V_111 , V_11 ) ;
F_13 ( V_39 ) ;
}
}
}
for ( V_123 = 0 ; V_123 < V_24 -> V_72 ; V_123 ++ ) {
if ( ( V_24 -> V_67 == V_82 ||
V_24 -> V_67 == V_69 ) &&
( V_123 == V_110 || V_123 == V_111 ) ) {
V_39 = F_77 ( V_24 , V_123 , V_93 , 0 ) ;
} else {
V_39 = F_97 ( V_24 , V_123 , V_93 ) ;
}
F_12 ( V_39 ) ;
}
}
V_85 = 0 ;
V_144:
F_68 ( V_138 ) ;
V_175:
if ( V_24 -> V_67 == V_82 ) {
if ( V_85 == 0 )
F_9 ( V_24 ) ;
else
F_58 ( V_32 , & V_24 -> V_33 ) ;
F_70 ( V_24 , V_85 ) ;
} else if ( V_24 -> V_67 == V_69 ) {
F_70 ( V_24 , V_85 ) ;
} else if ( V_85 == 0 ) {
V_24 -> V_110 = - 1 ;
V_24 -> V_111 = - 1 ;
if ( V_24 -> V_67 == V_83 )
F_96 ( V_24 ) ;
else if ( V_24 -> V_67 == V_68 )
F_131 ( V_24 , 0 ) ;
else
F_85 () ;
} else {
F_70 ( V_24 , V_85 ) ;
}
}
static void F_132 ( struct V_86 * V_86 )
{
struct V_23 * V_24 = V_86 -> V_89 ;
if ( V_86 -> V_88 )
F_75 ( V_24 , V_86 ) ;
else
F_106 ( V_86 ) ;
F_76 ( V_86 ) ;
if ( ! F_66 ( & V_24 -> V_90 ) )
return;
if ( F_65 ( & V_24 -> error ) > V_24 -> V_35 -> V_91 )
F_70 ( V_24 , - V_92 ) ;
else
F_127 ( V_24 ) ;
}
static int F_95 ( struct V_23 * V_24 )
{
int V_157 = 0 ;
struct V_41 V_41 ;
int V_27 ;
int V_28 = F_81 ( V_24 -> V_64 , V_31 ) ;
int V_93 ;
int V_123 ;
struct V_86 * V_86 ;
F_23 ( & V_41 ) ;
V_27 = F_10 ( V_24 ) ;
if ( V_27 )
goto V_144;
F_84 ( & V_24 -> error , 0 ) ;
for ( V_123 = 0 ; V_123 < V_24 -> V_72 ; V_123 ++ ) {
if ( V_24 -> V_110 == V_123 || V_24 -> V_111 == V_123 ) {
F_42 ( & V_24 -> error ) ;
continue;
}
for ( V_93 = 0 ; V_93 < V_28 ; V_93 ++ ) {
struct V_39 * V_96 ;
V_96 = F_97 ( V_24 , V_123 , V_93 ) ;
if ( F_19 ( V_96 ) )
continue;
V_27 = F_89 ( V_24 , & V_41 ,
F_97 ( V_24 , V_123 , V_93 ) ,
V_123 , V_93 , V_24 -> V_64 ) ;
if ( V_27 < 0 )
goto V_144;
}
}
V_157 = F_101 ( & V_41 ) ;
if ( ! V_157 ) {
if ( F_65 ( & V_24 -> error ) <= V_24 -> V_35 -> V_91 ) {
F_127 ( V_24 ) ;
goto V_77;
} else {
goto V_144;
}
}
F_84 ( & V_24 -> V_90 , V_157 ) ;
while ( 1 ) {
V_86 = F_102 ( & V_41 ) ;
if ( ! V_86 )
break;
V_86 -> V_89 = V_24 ;
V_86 -> V_147 = F_132 ;
F_111 ( V_24 -> V_47 , V_86 ,
V_159 ) ;
F_103 ( V_160 , V_86 ) ;
}
V_77:
return 0 ;
V_144:
if ( V_24 -> V_67 == V_82 ||
V_24 -> V_67 == V_69 )
F_70 ( V_24 , - V_92 ) ;
return - V_92 ;
}
int F_133 ( struct V_100 * V_101 , struct V_86 * V_86 ,
struct V_102 * V_35 , T_1 V_64 ,
int V_180 , int V_181 )
{
struct V_23 * V_24 ;
int V_27 ;
V_24 = F_82 ( V_101 , V_35 , V_64 ) ;
if ( F_122 ( V_24 ) ) {
if ( V_181 )
F_67 ( V_35 ) ;
return F_123 ( V_24 ) ;
}
V_24 -> V_67 = V_82 ;
F_93 ( & V_24 -> V_41 , V_86 ) ;
V_24 -> V_42 = V_86 -> V_129 . V_131 ;
V_24 -> V_110 = F_105 ( V_24 , V_86 ) ;
if ( V_24 -> V_110 == - 1 ) {
F_85 () ;
if ( V_181 )
F_67 ( V_35 ) ;
F_68 ( V_24 ) ;
return - V_92 ;
}
if ( V_181 ) {
F_124 ( V_101 -> V_47 ) ;
V_24 -> V_43 = 1 ;
} else {
F_134 ( V_35 ) ;
}
if ( V_180 == 3 )
V_24 -> V_111 = V_24 -> V_72 - 2 ;
V_27 = F_53 ( V_24 ) ;
if ( V_27 == 0 )
F_95 ( V_24 ) ;
return 0 ;
}
static void V_154 ( struct V_171 * V_152 )
{
struct V_23 * V_24 ;
V_24 = F_116 ( V_152 , struct V_23 , V_152 ) ;
F_110 ( V_24 ) ;
}
static void V_156 ( struct V_171 * V_152 )
{
struct V_23 * V_24 ;
V_24 = F_116 ( V_152 , struct V_23 , V_152 ) ;
F_95 ( V_24 ) ;
}
struct V_23 *
F_135 ( struct V_100 * V_101 , struct V_86 * V_86 ,
struct V_102 * V_35 , T_1 V_64 ,
struct V_182 * V_183 ,
unsigned long * V_112 , int V_184 )
{
struct V_23 * V_24 ;
int V_11 ;
V_24 = F_82 ( V_101 , V_35 , V_64 ) ;
if ( F_122 ( V_24 ) )
return NULL ;
F_93 ( & V_24 -> V_41 , V_86 ) ;
ASSERT ( ! V_86 -> V_129 . V_131 ) ;
V_24 -> V_67 = V_68 ;
for ( V_11 = 0 ; V_11 < V_24 -> V_72 ; V_11 ++ ) {
if ( V_35 -> V_125 [ V_11 ] . V_127 == V_183 ) {
V_24 -> V_185 = V_11 ;
break;
}
}
ASSERT ( V_101 -> V_186 == V_107 ) ;
ASSERT ( V_24 -> V_106 == V_184 ) ;
F_136 ( V_24 -> V_112 , V_112 , V_184 ) ;
return V_24 ;
}
void F_137 ( struct V_23 * V_24 , struct V_39 * V_39 ,
T_1 V_150 )
{
int V_134 ;
int V_70 ;
ASSERT ( V_150 >= V_24 -> V_35 -> V_36 [ 0 ] ) ;
ASSERT ( V_150 + V_107 <= V_24 -> V_35 -> V_36 [ 0 ] +
V_24 -> V_64 * V_24 -> V_63 ) ;
V_134 = ( int ) ( V_150 - V_24 -> V_35 -> V_36 [ 0 ] ) ;
V_70 = V_134 >> V_71 ;
V_24 -> V_29 [ V_70 ] = V_39 ;
}
static int F_138 ( struct V_23 * V_24 )
{
int V_11 ;
int V_187 ;
int V_70 ;
struct V_39 * V_39 ;
F_139 (bit, rbio->dbitmap, rbio->stripe_npages) {
for ( V_11 = 0 ; V_11 < V_24 -> V_72 ; V_11 ++ ) {
V_70 = V_11 * V_24 -> V_106 + V_187 ;
if ( V_24 -> V_30 [ V_70 ] )
continue;
V_39 = F_86 ( V_109 | V_116 ) ;
if ( ! V_39 )
return - V_17 ;
V_24 -> V_30 [ V_70 ] = V_39 ;
F_87 ( V_39 ) ;
}
}
return 0 ;
}
static void F_140 ( struct V_86 * V_86 )
{
struct V_23 * V_24 = V_86 -> V_89 ;
int V_85 = V_86 -> V_88 ;
if ( V_86 -> V_88 )
F_75 ( V_24 , V_86 ) ;
F_76 ( V_86 ) ;
if ( ! F_66 ( & V_24 -> V_90 ) )
return;
V_85 = 0 ;
if ( F_65 ( & V_24 -> error ) )
V_85 = - V_92 ;
F_70 ( V_24 , V_85 ) ;
}
static T_3 void F_131 ( struct V_23 * V_24 ,
int V_188 )
{
struct V_102 * V_35 = V_24 -> V_35 ;
void * V_138 [ V_24 -> V_72 ] ;
F_141 ( V_189 , V_24 -> V_106 ) ;
int V_63 = V_24 -> V_63 ;
int V_123 ;
int V_93 ;
int V_139 = - 1 ;
int V_140 = - 1 ;
struct V_39 * V_190 = NULL ;
struct V_39 * V_191 = NULL ;
struct V_41 V_41 ;
struct V_86 * V_86 ;
int V_192 = 0 ;
int V_27 ;
F_23 ( & V_41 ) ;
if ( V_24 -> V_72 - V_24 -> V_63 == 1 ) {
V_139 = V_24 -> V_72 - 1 ;
} else if ( V_24 -> V_72 - V_24 -> V_63 == 2 ) {
V_139 = V_24 -> V_72 - 2 ;
V_140 = V_24 -> V_72 - 1 ;
} else {
F_85 () ;
}
if ( V_35 -> V_104 && V_35 -> V_146 [ V_24 -> V_185 ] ) {
V_192 = 1 ;
F_136 ( V_189 , V_24 -> V_112 , V_24 -> V_106 ) ;
}
F_58 ( V_32 , & V_24 -> V_33 ) ;
if ( ! V_188 )
goto V_193;
V_190 = F_86 ( V_109 | V_116 ) ;
if ( ! V_190 )
goto V_144;
F_13 ( V_190 ) ;
if ( V_140 != - 1 ) {
V_191 = F_86 ( V_109 | V_116 ) ;
if ( ! V_191 ) {
F_20 ( V_190 ) ;
goto V_144;
}
F_13 ( V_191 ) ;
}
F_84 ( & V_24 -> error , 0 ) ;
F_139 (pagenr, rbio->dbitmap, rbio->stripe_npages) {
struct V_39 * V_96 ;
void * V_194 ;
for ( V_123 = 0 ; V_123 < V_63 ; V_123 ++ ) {
V_96 = F_77 ( V_24 , V_123 , V_93 , 0 ) ;
V_138 [ V_123 ] = F_11 ( V_96 ) ;
}
V_138 [ V_123 ++ ] = F_11 ( V_190 ) ;
if ( V_140 != - 1 ) {
V_138 [ V_123 ++ ] = F_11 ( V_191 ) ;
V_142 . V_143 ( V_24 -> V_72 , V_107 ,
V_138 ) ;
} else {
memcpy ( V_138 [ V_63 ] , V_138 [ 0 ] , V_107 ) ;
F_45 ( V_138 + 1 , V_63 - 1 , V_31 ) ;
}
V_96 = F_97 ( V_24 , V_24 -> V_185 , V_93 ) ;
V_194 = F_11 ( V_96 ) ;
if ( memcmp ( V_194 , V_138 [ V_24 -> V_185 ] , V_31 ) )
memcpy ( V_194 , V_138 [ V_24 -> V_185 ] , V_31 ) ;
else
F_142 ( V_24 -> V_112 , V_93 , 1 ) ;
F_12 ( V_96 ) ;
for ( V_123 = 0 ; V_123 < V_24 -> V_72 ; V_123 ++ )
F_12 ( F_77 ( V_24 , V_123 , V_93 , 0 ) ) ;
}
F_20 ( V_190 ) ;
if ( V_191 )
F_20 ( V_191 ) ;
V_193:
F_139 (pagenr, rbio->dbitmap, rbio->stripe_npages) {
struct V_39 * V_39 ;
V_39 = F_97 ( V_24 , V_24 -> V_185 , V_93 ) ;
V_27 = F_89 ( V_24 , & V_41 ,
V_39 , V_24 -> V_185 , V_93 , V_24 -> V_64 ) ;
if ( V_27 )
goto V_144;
}
if ( ! V_192 )
goto V_195;
F_139 (pagenr, pbitmap, rbio->stripe_npages) {
struct V_39 * V_39 ;
V_39 = F_97 ( V_24 , V_24 -> V_185 , V_93 ) ;
V_27 = F_89 ( V_24 , & V_41 , V_39 ,
V_35 -> V_146 [ V_24 -> V_185 ] ,
V_93 , V_24 -> V_64 ) ;
if ( V_27 )
goto V_144;
}
V_195:
V_63 = F_101 ( & V_41 ) ;
if ( ! V_63 ) {
F_70 ( V_24 , 0 ) ;
return;
}
F_84 ( & V_24 -> V_90 , V_63 ) ;
while ( 1 ) {
V_86 = F_102 ( & V_41 ) ;
if ( ! V_86 )
break;
V_86 -> V_89 = V_24 ;
V_86 -> V_147 = F_140 ;
F_103 ( V_148 , V_86 ) ;
}
return;
V_144:
F_70 ( V_24 , - V_92 ) ;
}
static inline int F_143 ( struct V_23 * V_24 , int V_123 )
{
if ( V_123 >= 0 && V_123 < V_24 -> V_63 )
return 1 ;
return 0 ;
}
static void F_144 ( struct V_23 * V_24 )
{
if ( F_65 ( & V_24 -> error ) > V_24 -> V_35 -> V_91 )
goto V_144;
if ( V_24 -> V_110 >= 0 || V_24 -> V_111 >= 0 ) {
int V_196 = 0 , V_197 = - 1 ;
if ( F_143 ( V_24 , V_24 -> V_110 ) )
V_196 ++ ;
else if ( F_145 ( V_24 -> V_110 ) )
V_197 = V_24 -> V_110 ;
if ( F_143 ( V_24 , V_24 -> V_111 ) )
V_196 ++ ;
else if ( F_145 ( V_24 -> V_111 ) )
V_197 = V_24 -> V_111 ;
if ( V_196 > V_24 -> V_35 -> V_91 - 1 )
goto V_144;
if ( V_196 == 0 ) {
F_131 ( V_24 , 0 ) ;
return;
}
if ( V_197 != V_24 -> V_185 )
goto V_144;
F_127 ( V_24 ) ;
} else {
F_131 ( V_24 , 1 ) ;
}
return;
V_144:
F_70 ( V_24 , - V_92 ) ;
}
static void F_146 ( struct V_86 * V_86 )
{
struct V_23 * V_24 = V_86 -> V_89 ;
if ( V_86 -> V_88 )
F_75 ( V_24 , V_86 ) ;
else
F_106 ( V_86 ) ;
F_76 ( V_86 ) ;
if ( ! F_66 ( & V_24 -> V_90 ) )
return;
F_144 ( V_24 ) ;
}
static void F_147 ( struct V_23 * V_24 )
{
int V_157 = 0 ;
struct V_41 V_41 ;
int V_27 ;
int V_93 ;
int V_123 ;
struct V_86 * V_86 ;
V_27 = F_138 ( V_24 ) ;
if ( V_27 )
goto V_144;
F_23 ( & V_41 ) ;
F_84 ( & V_24 -> error , 0 ) ;
for ( V_123 = 0 ; V_123 < V_24 -> V_72 ; V_123 ++ ) {
F_139 (pagenr, rbio->dbitmap, rbio->stripe_npages) {
struct V_39 * V_39 ;
V_39 = F_77 ( V_24 , V_123 , V_93 , 1 ) ;
if ( V_39 )
continue;
V_39 = F_97 ( V_24 , V_123 , V_93 ) ;
if ( F_19 ( V_39 ) )
continue;
V_27 = F_89 ( V_24 , & V_41 , V_39 ,
V_123 , V_93 , V_24 -> V_64 ) ;
if ( V_27 )
goto V_144;
}
}
V_157 = F_101 ( & V_41 ) ;
if ( ! V_157 ) {
goto V_158;
}
F_84 ( & V_24 -> V_90 , V_157 ) ;
while ( 1 ) {
V_86 = F_102 ( & V_41 ) ;
if ( ! V_86 )
break;
V_86 -> V_89 = V_24 ;
V_86 -> V_147 = F_146 ;
F_111 ( V_24 -> V_47 , V_86 ,
V_159 ) ;
F_103 ( V_160 , V_86 ) ;
}
return;
V_144:
F_70 ( V_24 , - V_92 ) ;
return;
V_158:
F_144 ( V_24 ) ;
}
static void F_148 ( struct V_171 * V_152 )
{
struct V_23 * V_24 ;
V_24 = F_116 ( V_152 , struct V_23 , V_152 ) ;
F_147 ( V_24 ) ;
}
static void F_61 ( struct V_23 * V_24 )
{
F_108 ( & V_24 -> V_152 , V_153 ,
F_148 , NULL , NULL ) ;
F_109 ( V_24 -> V_47 -> V_155 ,
& V_24 -> V_152 ) ;
}
void F_149 ( struct V_23 * V_24 )
{
if ( ! F_53 ( V_24 ) )
F_61 ( V_24 ) ;
}
struct V_23 *
F_150 ( struct V_100 * V_101 , struct V_86 * V_86 ,
struct V_102 * V_35 , T_1 V_198 )
{
struct V_23 * V_24 ;
V_24 = F_82 ( V_101 , V_35 , V_198 ) ;
if ( F_122 ( V_24 ) )
return NULL ;
V_24 -> V_67 = V_69 ;
F_93 ( & V_24 -> V_41 , V_86 ) ;
ASSERT ( ! V_86 -> V_129 . V_131 ) ;
V_24 -> V_110 = F_105 ( V_24 , V_86 ) ;
if ( V_24 -> V_110 == - 1 ) {
F_85 () ;
F_68 ( V_24 ) ;
return NULL ;
}
return V_24 ;
}
static void F_151 ( struct V_171 * V_152 )
{
struct V_23 * V_24 ;
V_24 = F_116 ( V_152 , struct V_23 , V_152 ) ;
F_95 ( V_24 ) ;
}
static void F_152 ( struct V_23 * V_24 )
{
F_108 ( & V_24 -> V_152 , V_153 ,
F_151 , NULL , NULL ) ;
F_109 ( V_24 -> V_47 -> V_155 , & V_24 -> V_152 ) ;
}
void F_153 ( struct V_23 * V_24 )
{
if ( ! F_53 ( V_24 ) )
F_152 ( V_24 ) ;
}
