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
static int F_51 ( struct V_23 * V_24 , int V_70 ,
int V_71 )
{
return V_70 * V_24 -> V_72 + V_71 ;
}
static struct V_39 * F_52 ( struct V_23 * V_24 , int V_70 ,
int V_71 )
{
return V_24 -> V_30 [ F_51 ( V_24 , V_70 , V_71 ) ] ;
}
static struct V_39 * F_53 ( struct V_23 * V_24 , int V_71 )
{
return F_52 ( V_24 , V_24 -> V_63 , V_71 ) ;
}
static struct V_39 * F_54 ( struct V_23 * V_24 , int V_71 )
{
if ( V_24 -> V_63 + 1 == V_24 -> V_73 )
return NULL ;
return F_52 ( V_24 , V_24 -> V_63 + 1 , V_71 ) ;
}
static T_3 int F_55 ( struct V_23 * V_24 )
{
int V_44 = F_15 ( V_24 ) ;
struct V_6 * V_8 = V_24 -> V_47 -> V_13 -> V_4 + V_44 ;
struct V_23 * V_7 ;
struct V_23 * V_74 ;
unsigned long V_33 ;
F_56 ( V_22 ) ;
struct V_23 * V_45 = NULL ;
struct V_23 * V_75 = NULL ;
int V_27 = 0 ;
int V_76 = 0 ;
F_35 ( & V_8 -> V_21 , V_33 ) ;
F_57 (cur, &h->hash_list, hash_list) {
V_76 ++ ;
if ( V_7 -> V_35 -> V_36 [ 0 ] == V_24 -> V_35 -> V_36 [ 0 ] ) {
F_25 ( & V_7 -> V_48 ) ;
if ( F_28 ( & V_7 -> V_41 ) &&
F_29 ( & V_7 -> V_51 ) &&
F_18 ( V_46 , & V_7 -> V_33 ) &&
! F_18 ( V_66 , & V_7 -> V_33 ) ) {
F_27 ( & V_7 -> V_20 ) ;
F_30 ( & V_7 -> V_50 ) ;
F_17 ( V_7 , V_24 ) ;
V_75 = V_7 ;
F_32 ( & V_7 -> V_48 ) ;
goto V_77;
}
if ( F_50 ( V_7 , V_24 ) ) {
F_21 ( V_7 , V_24 ) ;
F_32 ( & V_7 -> V_48 ) ;
V_45 = V_24 ;
V_27 = 1 ;
goto V_78;
}
F_57 (pending, &cur->plug_list,
plug_list) {
if ( F_50 ( V_74 , V_24 ) ) {
F_21 ( V_74 , V_24 ) ;
F_32 ( & V_7 -> V_48 ) ;
V_45 = V_24 ;
V_27 = 1 ;
goto V_78;
}
}
F_58 ( & V_24 -> V_51 , & V_7 -> V_51 ) ;
F_32 ( & V_7 -> V_48 ) ;
V_27 = 1 ;
goto V_78;
}
}
V_77:
F_42 ( & V_24 -> V_50 ) ;
F_44 ( & V_24 -> V_20 , & V_8 -> V_20 ) ;
V_78:
F_36 ( & V_8 -> V_21 , V_33 ) ;
if ( V_75 )
F_34 ( V_75 ) ;
if ( V_45 )
F_33 ( V_45 ) ;
return V_27 ;
}
static T_3 void F_59 ( struct V_23 * V_24 )
{
int V_44 ;
struct V_6 * V_8 ;
unsigned long V_33 ;
int V_79 = 0 ;
V_44 = F_15 ( V_24 ) ;
V_8 = V_24 -> V_47 -> V_13 -> V_4 + V_44 ;
if ( F_29 ( & V_24 -> V_51 ) )
F_40 ( V_24 ) ;
F_35 ( & V_8 -> V_21 , V_33 ) ;
F_25 ( & V_24 -> V_48 ) ;
if ( ! F_29 ( & V_24 -> V_20 ) ) {
if ( F_29 ( & V_24 -> V_51 ) &&
F_18 ( V_46 , & V_24 -> V_33 ) ) {
V_79 = 1 ;
F_60 ( V_66 , & V_24 -> V_33 ) ;
F_31 ( ! F_28 ( & V_24 -> V_41 ) ) ;
goto V_80;
}
F_27 ( & V_24 -> V_20 ) ;
F_30 ( & V_24 -> V_50 ) ;
if ( ! F_29 ( & V_24 -> V_51 ) ) {
struct V_23 * V_52 ;
struct V_81 * V_82 = V_24 -> V_51 . V_52 ;
V_52 = F_38 ( V_82 , struct V_23 ,
V_51 ) ;
F_27 ( & V_24 -> V_51 ) ;
F_44 ( & V_52 -> V_20 , & V_8 -> V_20 ) ;
F_42 ( & V_52 -> V_50 ) ;
F_32 ( & V_24 -> V_48 ) ;
F_36 ( & V_8 -> V_21 , V_33 ) ;
if ( V_52 -> V_67 == V_83 )
F_61 ( V_52 ) ;
else if ( V_52 -> V_67 == V_69 ) {
F_17 ( V_24 , V_52 ) ;
F_61 ( V_52 ) ;
} else if ( V_52 -> V_67 == V_84 ) {
F_17 ( V_24 , V_52 ) ;
F_62 ( V_52 ) ;
} else if ( V_52 -> V_67 == V_68 ) {
F_17 ( V_24 , V_52 ) ;
F_63 ( V_52 ) ;
}
goto V_85;
} else if ( F_64 ( & V_8 -> V_22 ) ) {
F_32 ( & V_24 -> V_48 ) ;
F_36 ( & V_8 -> V_21 , V_33 ) ;
F_65 ( & V_8 -> V_22 ) ;
goto V_85;
}
}
V_80:
F_32 ( & V_24 -> V_48 ) ;
F_36 ( & V_8 -> V_21 , V_33 ) ;
V_85:
if ( ! V_79 )
F_34 ( V_24 ) ;
}
static void F_33 ( struct V_23 * V_24 )
{
int V_11 ;
F_66 ( F_67 ( & V_24 -> V_50 ) < 0 ) ;
if ( ! F_68 ( & V_24 -> V_50 ) )
return;
F_66 ( ! F_29 ( & V_24 -> V_19 ) ) ;
F_66 ( ! F_29 ( & V_24 -> V_20 ) ) ;
F_66 ( ! F_28 ( & V_24 -> V_41 ) ) ;
for ( V_11 = 0 ; V_11 < V_24 -> V_28 ; V_11 ++ ) {
if ( V_24 -> V_30 [ V_11 ] ) {
F_20 ( V_24 -> V_30 [ V_11 ] ) ;
V_24 -> V_30 [ V_11 ] = NULL ;
}
}
F_69 ( V_24 -> V_35 ) ;
F_70 ( V_24 ) ;
}
static void F_71 ( struct V_23 * V_24 )
{
F_59 ( V_24 ) ;
F_33 ( V_24 ) ;
}
static void F_72 ( struct V_23 * V_24 , int V_86 )
{
struct V_87 * V_7 = F_73 ( & V_24 -> V_41 ) ;
struct V_87 * V_52 ;
if ( V_24 -> V_43 )
F_74 ( V_24 -> V_47 , V_24 -> V_43 ) ;
F_71 ( V_24 ) ;
while ( V_7 ) {
V_52 = V_7 -> V_88 ;
V_7 -> V_88 = NULL ;
V_7 -> V_89 = V_86 ;
F_75 ( V_7 ) ;
V_7 = V_52 ;
}
}
static void F_76 ( struct V_87 * V_87 )
{
struct V_23 * V_24 = V_87 -> V_90 ;
int V_86 = V_87 -> V_89 ;
int V_91 ;
if ( V_86 )
F_77 ( V_24 , V_87 ) ;
F_78 ( V_87 ) ;
if ( ! F_68 ( & V_24 -> V_92 ) )
return;
V_86 = 0 ;
V_91 = ( V_24 -> V_67 == V_68 ) ?
0 : V_24 -> V_35 -> V_91 ;
if ( F_67 ( & V_24 -> error ) > V_91 )
V_86 = - V_93 ;
F_72 ( V_24 , V_86 ) ;
}
static struct V_39 * F_79 ( struct V_23 * V_24 ,
int V_71 , int V_94 , int V_95 )
{
int V_96 ;
struct V_39 * V_97 = NULL ;
V_96 = V_71 * ( V_24 -> V_64 >> V_98 ) + V_94 ;
F_80 ( & V_24 -> V_48 ) ;
V_97 = V_24 -> V_29 [ V_96 ] ;
F_81 ( & V_24 -> V_48 ) ;
if ( V_97 || V_95 )
return V_97 ;
return V_24 -> V_30 [ V_96 ] ;
}
static unsigned long F_82 ( unsigned long V_64 , int V_99 )
{
return F_83 ( V_64 , V_31 ) * V_99 ;
}
static struct V_23 * F_84 ( struct V_100 * V_101 ,
struct V_102 * V_35 , T_1 V_64 )
{
struct V_23 * V_24 ;
int V_63 = 0 ;
int V_73 = V_35 -> V_103 - V_35 -> V_104 ;
int V_105 = F_82 ( V_64 , V_73 ) ;
int V_72 = F_83 ( V_64 , V_106 ) ;
void * V_97 ;
V_24 = F_2 ( sizeof( * V_24 ) + V_105 * sizeof( struct V_39 * ) * 2 +
F_83 ( V_72 , V_107 ) *
sizeof( long ) , V_108 ) ;
if ( ! V_24 )
return F_85 ( - V_17 ) ;
F_23 ( & V_24 -> V_41 ) ;
F_5 ( & V_24 -> V_51 ) ;
F_4 ( & V_24 -> V_48 ) ;
F_5 ( & V_24 -> V_19 ) ;
F_5 ( & V_24 -> V_20 ) ;
V_24 -> V_35 = V_35 ;
V_24 -> V_47 = V_101 -> V_47 ;
V_24 -> V_64 = V_64 ;
V_24 -> V_28 = V_105 ;
V_24 -> V_73 = V_73 ;
V_24 -> V_72 = V_72 ;
V_24 -> V_109 = - 1 ;
V_24 -> V_110 = - 1 ;
F_86 ( & V_24 -> V_50 , 1 ) ;
F_86 ( & V_24 -> error , 0 ) ;
F_86 ( & V_24 -> V_92 , 0 ) ;
V_97 = V_24 + 1 ;
V_24 -> V_30 = V_97 ;
V_24 -> V_29 = V_97 + sizeof( struct V_39 * ) * V_105 ;
V_24 -> V_111 = V_97 + sizeof( struct V_39 * ) * V_105 * 2 ;
if ( V_35 -> V_112 & V_113 )
V_63 = V_73 - 1 ;
else if ( V_35 -> V_112 & V_114 )
V_63 = V_73 - 2 ;
else
F_87 () ;
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
V_39 = F_88 ( V_108 | V_115 ) ;
if ( ! V_39 )
return - V_17 ;
V_24 -> V_30 [ V_11 ] = V_39 ;
}
return 0 ;
}
static int F_89 ( struct V_23 * V_24 )
{
int V_11 ;
struct V_39 * V_39 ;
V_11 = F_51 ( V_24 , V_24 -> V_63 , 0 ) ;
for (; V_11 < V_24 -> V_28 ; V_11 ++ ) {
if ( V_24 -> V_30 [ V_11 ] )
continue;
V_39 = F_88 ( V_108 | V_115 ) ;
if ( ! V_39 )
return - V_17 ;
V_24 -> V_30 [ V_11 ] = V_39 ;
}
return 0 ;
}
static int F_90 ( struct V_23 * V_24 ,
struct V_41 * V_41 ,
struct V_39 * V_39 ,
int V_116 ,
unsigned long V_117 ,
unsigned long V_118 )
{
struct V_87 * V_65 = V_41 -> V_119 ;
T_1 V_120 = 0 ;
int V_27 ;
struct V_87 * V_87 ;
struct V_121 * V_70 ;
T_1 V_122 ;
V_70 = & V_24 -> V_35 -> V_123 [ V_116 ] ;
V_122 = V_70 -> V_124 + ( V_117 << V_125 ) ;
if ( ! V_70 -> V_126 -> V_127 )
return F_91 ( V_24 , V_116 ) ;
if ( V_65 ) {
V_120 = ( T_1 ) V_65 -> V_128 . V_129 << 9 ;
V_120 += V_65 -> V_128 . V_130 ;
if ( V_120 == V_122 && V_70 -> V_126 -> V_127 &&
! V_65 -> V_89 &&
V_65 -> V_131 == V_70 -> V_126 -> V_127 ) {
V_27 = F_92 ( V_65 , V_39 , V_31 , 0 ) ;
if ( V_27 == V_31 )
return 0 ;
}
}
V_87 = F_93 ( V_108 , V_118 >> V_98 ? : 1 ) ;
if ( ! V_87 )
return - V_17 ;
V_87 -> V_128 . V_130 = 0 ;
V_87 -> V_131 = V_70 -> V_126 -> V_127 ;
V_87 -> V_128 . V_129 = V_122 >> 9 ;
F_92 ( V_87 , V_39 , V_31 , 0 ) ;
F_94 ( V_41 , V_87 ) ;
return 0 ;
}
static void F_95 ( struct V_23 * V_24 )
{
if ( V_24 -> V_109 >= 0 || V_24 -> V_110 >= 0 ) {
F_31 ( V_24 -> V_109 == V_24 -> V_73 - 1 ) ;
F_96 ( V_24 ) ;
} else {
F_97 ( V_24 ) ;
}
}
static void F_98 ( struct V_23 * V_24 )
{
struct V_87 * V_87 ;
T_1 V_132 ;
unsigned long V_133 ;
unsigned long V_117 ;
struct V_39 * V_97 ;
int V_11 ;
F_80 ( & V_24 -> V_48 ) ;
F_99 (bio, &rbio->bio_list) {
V_132 = ( T_1 ) V_87 -> V_128 . V_129 << 9 ;
V_133 = V_132 - V_24 -> V_35 -> V_36 [ 0 ] ;
V_117 = V_133 >> V_125 ;
for ( V_11 = 0 ; V_11 < V_87 -> V_134 ; V_11 ++ ) {
V_97 = V_87 -> V_135 [ V_11 ] . V_136 ;
V_24 -> V_29 [ V_117 + V_11 ] = V_97 ;
}
}
F_81 ( & V_24 -> V_48 ) ;
}
static T_3 void F_97 ( struct V_23 * V_24 )
{
struct V_102 * V_35 = V_24 -> V_35 ;
void * V_137 [ V_24 -> V_73 ] ;
int V_63 = V_24 -> V_63 ;
int V_70 ;
int V_94 ;
int V_138 = - 1 ;
int V_139 = - 1 ;
struct V_41 V_41 ;
struct V_87 * V_87 ;
int V_27 ;
F_23 ( & V_41 ) ;
if ( V_24 -> V_73 - V_24 -> V_63 == 1 ) {
V_138 = V_24 -> V_73 - 1 ;
} else if ( V_24 -> V_73 - V_24 -> V_63 == 2 ) {
V_138 = V_24 -> V_73 - 2 ;
V_139 = V_24 -> V_73 - 1 ;
} else {
F_87 () ;
}
F_80 ( & V_24 -> V_48 ) ;
F_14 ( V_66 , & V_24 -> V_33 ) ;
F_81 ( & V_24 -> V_48 ) ;
F_86 ( & V_24 -> error , 0 ) ;
F_98 ( V_24 ) ;
if ( ! F_49 ( V_24 ) )
F_9 ( V_24 ) ;
else
F_60 ( V_32 , & V_24 -> V_33 ) ;
for ( V_94 = 0 ; V_94 < V_24 -> V_72 ; V_94 ++ ) {
struct V_39 * V_97 ;
for ( V_70 = 0 ; V_70 < V_63 ; V_70 ++ ) {
V_97 = F_79 ( V_24 , V_70 , V_94 , 0 ) ;
V_137 [ V_70 ] = F_11 ( V_97 ) ;
}
V_97 = F_53 ( V_24 , V_94 ) ;
F_13 ( V_97 ) ;
V_137 [ V_70 ++ ] = F_11 ( V_97 ) ;
if ( V_139 != - 1 ) {
V_97 = F_54 ( V_24 , V_94 ) ;
F_13 ( V_97 ) ;
V_137 [ V_70 ++ ] = F_11 ( V_97 ) ;
V_140 . V_141 ( V_24 -> V_73 , V_106 ,
V_137 ) ;
} else {
memcpy ( V_137 [ V_63 ] , V_137 [ 0 ] , V_106 ) ;
F_45 ( V_137 + 1 , V_63 - 1 , V_31 ) ;
}
for ( V_70 = 0 ; V_70 < V_24 -> V_73 ; V_70 ++ )
F_12 ( F_79 ( V_24 , V_70 , V_94 , 0 ) ) ;
}
for ( V_70 = 0 ; V_70 < V_24 -> V_73 ; V_70 ++ ) {
for ( V_94 = 0 ; V_94 < V_24 -> V_72 ; V_94 ++ ) {
struct V_39 * V_39 ;
if ( V_70 < V_24 -> V_63 ) {
V_39 = F_79 ( V_24 , V_70 , V_94 , 1 ) ;
if ( ! V_39 )
continue;
} else {
V_39 = F_52 ( V_24 , V_70 , V_94 ) ;
}
V_27 = F_90 ( V_24 , & V_41 ,
V_39 , V_70 , V_94 , V_24 -> V_64 ) ;
if ( V_27 )
goto V_142;
}
}
if ( F_100 ( ! V_35 -> V_104 ) )
goto V_143;
for ( V_70 = 0 ; V_70 < V_24 -> V_73 ; V_70 ++ ) {
if ( ! V_35 -> V_144 [ V_70 ] )
continue;
for ( V_94 = 0 ; V_94 < V_24 -> V_72 ; V_94 ++ ) {
struct V_39 * V_39 ;
if ( V_70 < V_24 -> V_63 ) {
V_39 = F_79 ( V_24 , V_70 , V_94 , 1 ) ;
if ( ! V_39 )
continue;
} else {
V_39 = F_52 ( V_24 , V_70 , V_94 ) ;
}
V_27 = F_90 ( V_24 , & V_41 , V_39 ,
V_24 -> V_35 -> V_144 [ V_70 ] ,
V_94 , V_24 -> V_64 ) ;
if ( V_27 )
goto V_142;
}
}
V_143:
F_86 ( & V_24 -> V_92 , F_101 ( & V_41 ) ) ;
F_31 ( F_67 ( & V_24 -> V_92 ) == 0 ) ;
while ( 1 ) {
V_87 = F_102 ( & V_41 ) ;
if ( ! V_87 )
break;
V_87 -> V_90 = V_24 ;
V_87 -> V_145 = F_76 ;
F_103 ( V_146 , V_87 ) ;
}
return;
V_142:
F_72 ( V_24 , - V_93 ) ;
}
static int F_104 ( struct V_23 * V_24 ,
struct V_87 * V_87 )
{
T_1 V_124 = V_87 -> V_128 . V_129 ;
T_1 V_147 ;
int V_11 ;
struct V_121 * V_70 ;
V_124 <<= 9 ;
for ( V_11 = 0 ; V_11 < V_24 -> V_35 -> V_103 ; V_11 ++ ) {
V_70 = & V_24 -> V_35 -> V_123 [ V_11 ] ;
V_147 = V_70 -> V_124 ;
if ( V_124 >= V_147 &&
V_124 < V_147 + V_24 -> V_64 &&
V_87 -> V_131 == V_70 -> V_126 -> V_127 ) {
return V_11 ;
}
}
return - 1 ;
}
static int F_105 ( struct V_23 * V_24 ,
struct V_87 * V_87 )
{
T_1 V_148 = V_87 -> V_128 . V_129 ;
T_1 V_147 ;
int V_11 ;
V_148 <<= 9 ;
for ( V_11 = 0 ; V_11 < V_24 -> V_63 ; V_11 ++ ) {
V_147 = V_24 -> V_35 -> V_36 [ V_11 ] ;
if ( V_148 >= V_147 &&
V_148 < V_147 + V_24 -> V_64 ) {
return V_11 ;
}
}
return - 1 ;
}
static int F_91 ( struct V_23 * V_24 , int V_149 )
{
unsigned long V_33 ;
int V_27 = 0 ;
F_35 ( & V_24 -> V_48 , V_33 ) ;
if ( V_24 -> V_109 == V_149 || V_24 -> V_110 == V_149 )
goto V_78;
if ( V_24 -> V_109 == - 1 ) {
V_24 -> V_109 = V_149 ;
F_42 ( & V_24 -> error ) ;
} else if ( V_24 -> V_110 == - 1 ) {
V_24 -> V_110 = V_149 ;
F_42 ( & V_24 -> error ) ;
} else {
V_27 = - V_93 ;
}
V_78:
F_36 ( & V_24 -> V_48 , V_33 ) ;
return V_27 ;
}
static int F_77 ( struct V_23 * V_24 ,
struct V_87 * V_87 )
{
int V_149 = F_104 ( V_24 , V_87 ) ;
if ( V_149 < 0 )
return - V_93 ;
return F_91 ( V_24 , V_149 ) ;
}
static void F_106 ( struct V_87 * V_87 )
{
int V_11 ;
struct V_39 * V_97 ;
for ( V_11 = 0 ; V_11 < V_87 -> V_134 ; V_11 ++ ) {
V_97 = V_87 -> V_135 [ V_11 ] . V_136 ;
F_13 ( V_97 ) ;
}
}
static void F_107 ( struct V_87 * V_87 )
{
struct V_23 * V_24 = V_87 -> V_90 ;
if ( V_87 -> V_89 )
F_77 ( V_24 , V_87 ) ;
else
F_106 ( V_87 ) ;
F_78 ( V_87 ) ;
if ( ! F_68 ( & V_24 -> V_92 ) )
return;
if ( F_67 ( & V_24 -> error ) > V_24 -> V_35 -> V_91 )
goto V_142;
F_95 ( V_24 ) ;
return;
V_142:
F_72 ( V_24 , - V_93 ) ;
}
static void F_62 ( struct V_23 * V_24 )
{
F_108 ( & V_24 -> V_150 , V_151 ,
V_152 , NULL , NULL ) ;
F_109 ( V_24 -> V_47 -> V_153 ,
& V_24 -> V_150 ) ;
}
static void F_61 ( struct V_23 * V_24 )
{
F_108 ( & V_24 -> V_150 , V_151 ,
V_154 , NULL , NULL ) ;
F_109 ( V_24 -> V_47 -> V_153 ,
& V_24 -> V_150 ) ;
}
static int F_110 ( struct V_23 * V_24 )
{
int V_155 = 0 ;
struct V_41 V_41 ;
int V_27 ;
int V_94 ;
int V_70 ;
struct V_87 * V_87 ;
F_23 ( & V_41 ) ;
V_27 = F_10 ( V_24 ) ;
if ( V_27 )
goto V_142;
F_98 ( V_24 ) ;
F_86 ( & V_24 -> error , 0 ) ;
for ( V_70 = 0 ; V_70 < V_24 -> V_63 ; V_70 ++ ) {
for ( V_94 = 0 ; V_94 < V_24 -> V_72 ; V_94 ++ ) {
struct V_39 * V_39 ;
V_39 = F_79 ( V_24 , V_70 , V_94 , 1 ) ;
if ( V_39 )
continue;
V_39 = F_52 ( V_24 , V_70 , V_94 ) ;
if ( F_19 ( V_39 ) )
continue;
V_27 = F_90 ( V_24 , & V_41 , V_39 ,
V_70 , V_94 , V_24 -> V_64 ) ;
if ( V_27 )
goto V_142;
}
}
V_155 = F_101 ( & V_41 ) ;
if ( ! V_155 ) {
goto V_156;
}
F_86 ( & V_24 -> V_92 , V_155 ) ;
while ( 1 ) {
V_87 = F_102 ( & V_41 ) ;
if ( ! V_87 )
break;
V_87 -> V_90 = V_24 ;
V_87 -> V_145 = F_107 ;
F_111 ( V_24 -> V_47 , V_87 ,
V_157 ) ;
F_103 ( V_158 , V_87 ) ;
}
return 0 ;
V_142:
F_72 ( V_24 , - V_93 ) ;
return - V_93 ;
V_156:
F_95 ( V_24 ) ;
return 0 ;
}
static int F_112 ( struct V_23 * V_24 )
{
int V_27 ;
V_27 = F_89 ( V_24 ) ;
if ( V_27 ) {
F_33 ( V_24 ) ;
return V_27 ;
}
V_27 = F_55 ( V_24 ) ;
if ( V_27 == 0 )
F_97 ( V_24 ) ;
return 0 ;
}
static int F_113 ( struct V_23 * V_24 )
{
int V_27 ;
V_27 = F_55 ( V_24 ) ;
if ( V_27 == 0 )
F_62 ( V_24 ) ;
return 0 ;
}
static int F_114 ( struct V_23 * V_24 )
{
if ( ! F_49 ( V_24 ) )
return F_113 ( V_24 ) ;
return F_112 ( V_24 ) ;
}
static int F_115 ( void * V_159 , struct V_81 * V_160 , struct V_81 * V_161 )
{
struct V_23 * V_162 = F_116 ( V_160 , struct V_23 ,
V_51 ) ;
struct V_23 * V_163 = F_116 ( V_161 , struct V_23 ,
V_51 ) ;
T_1 V_164 = V_162 -> V_41 . V_82 -> V_128 . V_129 ;
T_1 V_165 = V_163 -> V_41 . V_82 -> V_128 . V_129 ;
if ( V_164 < V_165 )
return - 1 ;
if ( V_164 > V_165 )
return 1 ;
return 0 ;
}
static void F_117 ( struct V_166 * V_167 )
{
struct V_23 * V_7 ;
struct V_23 * V_65 = NULL ;
F_118 ( NULL , & V_167 -> V_168 , F_115 ) ;
while ( ! F_29 ( & V_167 -> V_168 ) ) {
V_7 = F_38 ( V_167 -> V_168 . V_52 ,
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
F_70 ( V_167 ) ;
}
static void F_119 ( struct V_169 * V_150 )
{
struct V_166 * V_167 ;
V_167 = F_116 ( V_150 , struct V_166 , V_150 ) ;
F_117 ( V_167 ) ;
}
static void F_120 ( struct V_170 * V_171 , bool V_172 )
{
struct V_166 * V_167 ;
V_167 = F_116 ( V_171 , struct V_166 , V_171 ) ;
if ( V_172 ) {
F_108 ( & V_167 -> V_150 , V_151 ,
F_119 , NULL , NULL ) ;
F_109 ( V_167 -> V_2 -> V_153 ,
& V_167 -> V_150 ) ;
return;
}
F_117 ( V_167 ) ;
}
int F_121 ( struct V_100 * V_101 , struct V_87 * V_87 ,
struct V_102 * V_35 , T_1 V_64 )
{
struct V_23 * V_24 ;
struct V_166 * V_167 = NULL ;
struct V_170 * V_171 ;
int V_27 ;
V_24 = F_84 ( V_101 , V_35 , V_64 ) ;
if ( F_122 ( V_24 ) ) {
F_69 ( V_35 ) ;
return F_123 ( V_24 ) ;
}
F_94 ( & V_24 -> V_41 , V_87 ) ;
V_24 -> V_42 = V_87 -> V_128 . V_130 ;
V_24 -> V_67 = V_84 ;
F_124 ( V_101 -> V_47 ) ;
V_24 -> V_43 = 1 ;
if ( F_49 ( V_24 ) ) {
V_27 = F_112 ( V_24 ) ;
if ( V_27 )
F_125 ( V_101 -> V_47 ) ;
return V_27 ;
}
V_171 = F_126 ( F_120 , V_101 -> V_47 ,
sizeof( * V_167 ) ) ;
if ( V_171 ) {
V_167 = F_116 ( V_171 , struct V_166 , V_171 ) ;
if ( ! V_167 -> V_2 ) {
V_167 -> V_2 = V_101 -> V_47 ;
F_5 ( & V_167 -> V_168 ) ;
}
F_58 ( & V_24 -> V_51 , & V_167 -> V_168 ) ;
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
int V_94 , V_70 ;
void * * V_137 ;
int V_109 = - 1 , V_110 = - 1 ;
struct V_39 * V_39 ;
int V_86 ;
int V_11 ;
V_137 = F_128 ( V_24 -> V_73 , sizeof( void * ) , V_108 ) ;
if ( ! V_137 ) {
V_86 = - V_17 ;
goto V_173;
}
V_109 = V_24 -> V_109 ;
V_110 = V_24 -> V_110 ;
if ( V_24 -> V_67 == V_83 ||
V_24 -> V_67 == V_69 ) {
F_80 ( & V_24 -> V_48 ) ;
F_14 ( V_66 , & V_24 -> V_33 ) ;
F_81 ( & V_24 -> V_48 ) ;
}
F_98 ( V_24 ) ;
for ( V_94 = 0 ; V_94 < V_24 -> V_72 ; V_94 ++ ) {
if ( V_24 -> V_67 == V_68 &&
! F_18 ( V_94 , V_24 -> V_111 ) )
continue;
for ( V_70 = 0 ; V_70 < V_24 -> V_73 ; V_70 ++ ) {
if ( ( V_24 -> V_67 == V_83 ||
V_24 -> V_67 == V_69 ) &&
( V_70 == V_109 || V_70 == V_110 ) ) {
V_39 = F_79 ( V_24 , V_70 , V_94 , 0 ) ;
} else {
V_39 = F_52 ( V_24 , V_70 , V_94 ) ;
}
V_137 [ V_70 ] = F_11 ( V_39 ) ;
}
if ( V_24 -> V_35 -> V_112 & V_114 ) {
if ( V_110 < 0 ) {
if ( V_109 == V_24 -> V_63 ) {
V_86 = - V_93 ;
goto V_142;
}
goto V_174;
}
if ( V_109 > V_110 ) {
int V_175 = V_110 ;
V_110 = V_109 ;
V_109 = V_175 ;
}
if ( V_24 -> V_35 -> V_36 [ V_110 ] == V_176 ) {
if ( V_24 -> V_35 -> V_36 [ V_109 ] ==
V_177 ) {
V_86 = - V_93 ;
goto V_142;
}
goto V_174;
}
if ( V_24 -> V_35 -> V_36 [ V_110 ] == V_177 ) {
F_129 ( V_24 -> V_73 ,
V_106 , V_109 , V_137 ) ;
} else {
F_130 ( V_24 -> V_73 ,
V_106 , V_109 , V_110 ,
V_137 ) ;
}
} else {
void * V_97 ;
F_31 ( V_110 != - 1 ) ;
V_174:
memcpy ( V_137 [ V_109 ] ,
V_137 [ V_24 -> V_63 ] ,
V_31 ) ;
V_97 = V_137 [ V_109 ] ;
for ( V_70 = V_109 ; V_70 < V_24 -> V_63 - 1 ; V_70 ++ )
V_137 [ V_70 ] = V_137 [ V_70 + 1 ] ;
V_137 [ V_24 -> V_63 - 1 ] = V_97 ;
F_45 ( V_137 , V_24 -> V_63 - 1 , V_31 ) ;
}
if ( V_24 -> V_67 == V_84 ) {
for ( V_11 = 0 ; V_11 < V_24 -> V_72 ; V_11 ++ ) {
if ( V_109 != - 1 ) {
V_39 = F_52 ( V_24 , V_109 , V_11 ) ;
F_13 ( V_39 ) ;
}
if ( V_110 != - 1 ) {
V_39 = F_52 ( V_24 , V_110 , V_11 ) ;
F_13 ( V_39 ) ;
}
}
}
for ( V_70 = 0 ; V_70 < V_24 -> V_73 ; V_70 ++ ) {
if ( ( V_24 -> V_67 == V_83 ||
V_24 -> V_67 == V_69 ) &&
( V_70 == V_109 || V_70 == V_110 ) ) {
V_39 = F_79 ( V_24 , V_70 , V_94 , 0 ) ;
} else {
V_39 = F_52 ( V_24 , V_70 , V_94 ) ;
}
F_12 ( V_39 ) ;
}
}
V_86 = 0 ;
V_142:
F_70 ( V_137 ) ;
V_173:
if ( V_24 -> V_67 == V_83 ) {
if ( V_86 == 0 )
F_9 ( V_24 ) ;
else
F_60 ( V_32 , & V_24 -> V_33 ) ;
F_72 ( V_24 , V_86 ) ;
} else if ( V_24 -> V_67 == V_69 ) {
F_72 ( V_24 , V_86 ) ;
} else if ( V_86 == 0 ) {
V_24 -> V_109 = - 1 ;
V_24 -> V_110 = - 1 ;
if ( V_24 -> V_67 == V_84 )
F_97 ( V_24 ) ;
else if ( V_24 -> V_67 == V_68 )
F_131 ( V_24 , 0 ) ;
else
F_87 () ;
} else {
F_72 ( V_24 , V_86 ) ;
}
}
static void F_132 ( struct V_87 * V_87 )
{
struct V_23 * V_24 = V_87 -> V_90 ;
if ( V_87 -> V_89 )
F_77 ( V_24 , V_87 ) ;
else
F_106 ( V_87 ) ;
F_78 ( V_87 ) ;
if ( ! F_68 ( & V_24 -> V_92 ) )
return;
if ( F_67 ( & V_24 -> error ) > V_24 -> V_35 -> V_91 )
F_72 ( V_24 , - V_93 ) ;
else
F_127 ( V_24 ) ;
}
static int F_96 ( struct V_23 * V_24 )
{
int V_155 = 0 ;
struct V_41 V_41 ;
int V_27 ;
int V_94 ;
int V_70 ;
struct V_87 * V_87 ;
F_23 ( & V_41 ) ;
V_27 = F_10 ( V_24 ) ;
if ( V_27 )
goto V_142;
F_86 ( & V_24 -> error , 0 ) ;
for ( V_70 = 0 ; V_70 < V_24 -> V_73 ; V_70 ++ ) {
if ( V_24 -> V_109 == V_70 || V_24 -> V_110 == V_70 ) {
F_42 ( & V_24 -> error ) ;
continue;
}
for ( V_94 = 0 ; V_94 < V_24 -> V_72 ; V_94 ++ ) {
struct V_39 * V_97 ;
V_97 = F_52 ( V_24 , V_70 , V_94 ) ;
if ( F_19 ( V_97 ) )
continue;
V_27 = F_90 ( V_24 , & V_41 ,
F_52 ( V_24 , V_70 , V_94 ) ,
V_70 , V_94 , V_24 -> V_64 ) ;
if ( V_27 < 0 )
goto V_142;
}
}
V_155 = F_101 ( & V_41 ) ;
if ( ! V_155 ) {
if ( F_67 ( & V_24 -> error ) <= V_24 -> V_35 -> V_91 ) {
F_127 ( V_24 ) ;
goto V_78;
} else {
goto V_142;
}
}
F_86 ( & V_24 -> V_92 , V_155 ) ;
while ( 1 ) {
V_87 = F_102 ( & V_41 ) ;
if ( ! V_87 )
break;
V_87 -> V_90 = V_24 ;
V_87 -> V_145 = F_132 ;
F_111 ( V_24 -> V_47 , V_87 ,
V_157 ) ;
F_103 ( V_158 , V_87 ) ;
}
V_78:
return 0 ;
V_142:
if ( V_24 -> V_67 == V_83 ||
V_24 -> V_67 == V_69 )
F_72 ( V_24 , - V_93 ) ;
return - V_93 ;
}
int F_133 ( struct V_100 * V_101 , struct V_87 * V_87 ,
struct V_102 * V_35 , T_1 V_64 ,
int V_178 , int V_179 )
{
struct V_23 * V_24 ;
int V_27 ;
V_24 = F_84 ( V_101 , V_35 , V_64 ) ;
if ( F_122 ( V_24 ) ) {
if ( V_179 )
F_69 ( V_35 ) ;
return F_123 ( V_24 ) ;
}
V_24 -> V_67 = V_83 ;
F_94 ( & V_24 -> V_41 , V_87 ) ;
V_24 -> V_42 = V_87 -> V_128 . V_130 ;
V_24 -> V_109 = F_105 ( V_24 , V_87 ) ;
if ( V_24 -> V_109 == - 1 ) {
F_87 () ;
if ( V_179 )
F_69 ( V_35 ) ;
F_70 ( V_24 ) ;
return - V_93 ;
}
if ( V_179 ) {
F_124 ( V_101 -> V_47 ) ;
V_24 -> V_43 = 1 ;
} else {
F_134 ( V_35 ) ;
}
if ( V_178 == 3 )
V_24 -> V_110 = V_24 -> V_73 - 2 ;
V_27 = F_55 ( V_24 ) ;
if ( V_27 == 0 )
F_96 ( V_24 ) ;
return 0 ;
}
static void V_152 ( struct V_169 * V_150 )
{
struct V_23 * V_24 ;
V_24 = F_116 ( V_150 , struct V_23 , V_150 ) ;
F_110 ( V_24 ) ;
}
static void V_154 ( struct V_169 * V_150 )
{
struct V_23 * V_24 ;
V_24 = F_116 ( V_150 , struct V_23 , V_150 ) ;
F_96 ( V_24 ) ;
}
struct V_23 *
F_135 ( struct V_100 * V_101 , struct V_87 * V_87 ,
struct V_102 * V_35 , T_1 V_64 ,
struct V_180 * V_181 ,
unsigned long * V_111 , int V_182 )
{
struct V_23 * V_24 ;
int V_11 ;
V_24 = F_84 ( V_101 , V_35 , V_64 ) ;
if ( F_122 ( V_24 ) )
return NULL ;
F_94 ( & V_24 -> V_41 , V_87 ) ;
ASSERT ( ! V_87 -> V_128 . V_130 ) ;
V_24 -> V_67 = V_68 ;
for ( V_11 = 0 ; V_11 < V_24 -> V_73 ; V_11 ++ ) {
if ( V_35 -> V_123 [ V_11 ] . V_126 == V_181 ) {
V_24 -> V_183 = V_11 ;
break;
}
}
ASSERT ( V_101 -> V_184 == V_106 ) ;
ASSERT ( V_24 -> V_72 == V_182 ) ;
F_136 ( V_24 -> V_111 , V_111 , V_182 ) ;
return V_24 ;
}
void F_137 ( struct V_23 * V_24 , struct V_39 * V_39 ,
T_1 V_148 )
{
int V_133 ;
int V_71 ;
ASSERT ( V_148 >= V_24 -> V_35 -> V_36 [ 0 ] ) ;
ASSERT ( V_148 + V_106 <= V_24 -> V_35 -> V_36 [ 0 ] +
V_24 -> V_64 * V_24 -> V_63 ) ;
V_133 = ( int ) ( V_148 - V_24 -> V_35 -> V_36 [ 0 ] ) ;
V_71 = V_133 >> V_125 ;
V_24 -> V_29 [ V_71 ] = V_39 ;
}
static int F_138 ( struct V_23 * V_24 )
{
int V_11 ;
int V_185 ;
int V_71 ;
struct V_39 * V_39 ;
F_139 (bit, rbio->dbitmap, rbio->stripe_npages) {
for ( V_11 = 0 ; V_11 < V_24 -> V_73 ; V_11 ++ ) {
V_71 = V_11 * V_24 -> V_72 + V_185 ;
if ( V_24 -> V_30 [ V_71 ] )
continue;
V_39 = F_88 ( V_108 | V_115 ) ;
if ( ! V_39 )
return - V_17 ;
V_24 -> V_30 [ V_71 ] = V_39 ;
}
}
return 0 ;
}
static T_3 void F_131 ( struct V_23 * V_24 ,
int V_186 )
{
struct V_102 * V_35 = V_24 -> V_35 ;
void * V_137 [ V_24 -> V_73 ] ;
F_140 ( V_187 , V_24 -> V_72 ) ;
int V_63 = V_24 -> V_63 ;
int V_70 ;
int V_94 ;
int V_138 = - 1 ;
int V_139 = - 1 ;
struct V_39 * V_188 = NULL ;
struct V_39 * V_189 = NULL ;
struct V_41 V_41 ;
struct V_87 * V_87 ;
int V_190 = 0 ;
int V_27 ;
F_23 ( & V_41 ) ;
if ( V_24 -> V_73 - V_24 -> V_63 == 1 ) {
V_138 = V_24 -> V_73 - 1 ;
} else if ( V_24 -> V_73 - V_24 -> V_63 == 2 ) {
V_138 = V_24 -> V_73 - 2 ;
V_139 = V_24 -> V_73 - 1 ;
} else {
F_87 () ;
}
if ( V_35 -> V_104 && V_35 -> V_144 [ V_24 -> V_183 ] ) {
V_190 = 1 ;
F_136 ( V_187 , V_24 -> V_111 , V_24 -> V_72 ) ;
}
F_60 ( V_32 , & V_24 -> V_33 ) ;
if ( ! V_186 )
goto V_191;
V_188 = F_88 ( V_108 | V_115 ) ;
if ( ! V_188 )
goto V_142;
F_13 ( V_188 ) ;
if ( V_139 != - 1 ) {
V_189 = F_88 ( V_108 | V_115 ) ;
if ( ! V_189 ) {
F_20 ( V_188 ) ;
goto V_142;
}
F_13 ( V_189 ) ;
}
F_86 ( & V_24 -> error , 0 ) ;
F_139 (pagenr, rbio->dbitmap, rbio->stripe_npages) {
struct V_39 * V_97 ;
void * V_192 ;
for ( V_70 = 0 ; V_70 < V_63 ; V_70 ++ ) {
V_97 = F_79 ( V_24 , V_70 , V_94 , 0 ) ;
V_137 [ V_70 ] = F_11 ( V_97 ) ;
}
V_137 [ V_70 ++ ] = F_11 ( V_188 ) ;
if ( V_139 != - 1 ) {
V_137 [ V_70 ++ ] = F_11 ( V_189 ) ;
V_140 . V_141 ( V_24 -> V_73 , V_106 ,
V_137 ) ;
} else {
memcpy ( V_137 [ V_63 ] , V_137 [ 0 ] , V_106 ) ;
F_45 ( V_137 + 1 , V_63 - 1 , V_31 ) ;
}
V_97 = F_52 ( V_24 , V_24 -> V_183 , V_94 ) ;
V_192 = F_11 ( V_97 ) ;
if ( memcmp ( V_192 , V_137 [ V_24 -> V_183 ] , V_31 ) )
memcpy ( V_192 , V_137 [ V_24 -> V_183 ] , V_31 ) ;
else
F_141 ( V_24 -> V_111 , V_94 , 1 ) ;
F_12 ( V_97 ) ;
for ( V_70 = 0 ; V_70 < V_24 -> V_73 ; V_70 ++ )
F_12 ( F_79 ( V_24 , V_70 , V_94 , 0 ) ) ;
}
F_20 ( V_188 ) ;
if ( V_189 )
F_20 ( V_189 ) ;
V_191:
F_139 (pagenr, rbio->dbitmap, rbio->stripe_npages) {
struct V_39 * V_39 ;
V_39 = F_52 ( V_24 , V_24 -> V_183 , V_94 ) ;
V_27 = F_90 ( V_24 , & V_41 ,
V_39 , V_24 -> V_183 , V_94 , V_24 -> V_64 ) ;
if ( V_27 )
goto V_142;
}
if ( ! V_190 )
goto V_193;
F_139 (pagenr, pbitmap, rbio->stripe_npages) {
struct V_39 * V_39 ;
V_39 = F_52 ( V_24 , V_24 -> V_183 , V_94 ) ;
V_27 = F_90 ( V_24 , & V_41 , V_39 ,
V_35 -> V_144 [ V_24 -> V_183 ] ,
V_94 , V_24 -> V_64 ) ;
if ( V_27 )
goto V_142;
}
V_193:
V_63 = F_101 ( & V_41 ) ;
if ( ! V_63 ) {
F_72 ( V_24 , 0 ) ;
return;
}
F_86 ( & V_24 -> V_92 , V_63 ) ;
while ( 1 ) {
V_87 = F_102 ( & V_41 ) ;
if ( ! V_87 )
break;
V_87 -> V_90 = V_24 ;
V_87 -> V_145 = F_76 ;
F_103 ( V_146 , V_87 ) ;
}
return;
V_142:
F_72 ( V_24 , - V_93 ) ;
}
static inline int F_142 ( struct V_23 * V_24 , int V_70 )
{
if ( V_70 >= 0 && V_70 < V_24 -> V_63 )
return 1 ;
return 0 ;
}
static void F_143 ( struct V_23 * V_24 )
{
if ( F_67 ( & V_24 -> error ) > V_24 -> V_35 -> V_91 )
goto V_142;
if ( V_24 -> V_109 >= 0 || V_24 -> V_110 >= 0 ) {
int V_194 = 0 , V_195 = - 1 ;
if ( F_142 ( V_24 , V_24 -> V_109 ) )
V_194 ++ ;
else if ( F_144 ( V_24 -> V_109 ) )
V_195 = V_24 -> V_109 ;
if ( F_142 ( V_24 , V_24 -> V_110 ) )
V_194 ++ ;
else if ( F_144 ( V_24 -> V_110 ) )
V_195 = V_24 -> V_110 ;
if ( V_194 > V_24 -> V_35 -> V_91 - 1 )
goto V_142;
if ( V_194 == 0 ) {
F_131 ( V_24 , 0 ) ;
return;
}
if ( V_195 != V_24 -> V_183 )
goto V_142;
F_127 ( V_24 ) ;
} else {
F_131 ( V_24 , 1 ) ;
}
return;
V_142:
F_72 ( V_24 , - V_93 ) ;
}
static void F_145 ( struct V_87 * V_87 )
{
struct V_23 * V_24 = V_87 -> V_90 ;
if ( V_87 -> V_89 )
F_77 ( V_24 , V_87 ) ;
else
F_106 ( V_87 ) ;
F_78 ( V_87 ) ;
if ( ! F_68 ( & V_24 -> V_92 ) )
return;
F_143 ( V_24 ) ;
}
static void F_146 ( struct V_23 * V_24 )
{
int V_155 = 0 ;
struct V_41 V_41 ;
int V_27 ;
int V_94 ;
int V_70 ;
struct V_87 * V_87 ;
V_27 = F_138 ( V_24 ) ;
if ( V_27 )
goto V_142;
F_23 ( & V_41 ) ;
F_86 ( & V_24 -> error , 0 ) ;
for ( V_70 = 0 ; V_70 < V_24 -> V_73 ; V_70 ++ ) {
F_139 (pagenr, rbio->dbitmap, rbio->stripe_npages) {
struct V_39 * V_39 ;
V_39 = F_79 ( V_24 , V_70 , V_94 , 1 ) ;
if ( V_39 )
continue;
V_39 = F_52 ( V_24 , V_70 , V_94 ) ;
if ( F_19 ( V_39 ) )
continue;
V_27 = F_90 ( V_24 , & V_41 , V_39 ,
V_70 , V_94 , V_24 -> V_64 ) ;
if ( V_27 )
goto V_142;
}
}
V_155 = F_101 ( & V_41 ) ;
if ( ! V_155 ) {
goto V_156;
}
F_86 ( & V_24 -> V_92 , V_155 ) ;
while ( 1 ) {
V_87 = F_102 ( & V_41 ) ;
if ( ! V_87 )
break;
V_87 -> V_90 = V_24 ;
V_87 -> V_145 = F_145 ;
F_111 ( V_24 -> V_47 , V_87 ,
V_157 ) ;
F_103 ( V_158 , V_87 ) ;
}
return;
V_142:
F_72 ( V_24 , - V_93 ) ;
return;
V_156:
F_143 ( V_24 ) ;
}
static void F_147 ( struct V_169 * V_150 )
{
struct V_23 * V_24 ;
V_24 = F_116 ( V_150 , struct V_23 , V_150 ) ;
F_146 ( V_24 ) ;
}
static void F_63 ( struct V_23 * V_24 )
{
F_108 ( & V_24 -> V_150 , V_151 ,
F_147 , NULL , NULL ) ;
F_109 ( V_24 -> V_47 -> V_153 ,
& V_24 -> V_150 ) ;
}
void F_148 ( struct V_23 * V_24 )
{
if ( ! F_55 ( V_24 ) )
F_63 ( V_24 ) ;
}
struct V_23 *
F_149 ( struct V_100 * V_101 , struct V_87 * V_87 ,
struct V_102 * V_35 , T_1 V_196 )
{
struct V_23 * V_24 ;
V_24 = F_84 ( V_101 , V_35 , V_196 ) ;
if ( F_122 ( V_24 ) )
return NULL ;
V_24 -> V_67 = V_69 ;
F_94 ( & V_24 -> V_41 , V_87 ) ;
ASSERT ( ! V_87 -> V_128 . V_130 ) ;
V_24 -> V_109 = F_105 ( V_24 , V_87 ) ;
if ( V_24 -> V_109 == - 1 ) {
F_87 () ;
F_70 ( V_24 ) ;
return NULL ;
}
return V_24 ;
}
static void F_150 ( struct V_169 * V_150 )
{
struct V_23 * V_24 ;
V_24 = F_116 ( V_150 , struct V_23 , V_150 ) ;
F_96 ( V_24 ) ;
}
static void F_151 ( struct V_23 * V_24 )
{
F_108 ( & V_24 -> V_150 , V_151 ,
F_150 , NULL , NULL ) ;
F_109 ( V_24 -> V_47 -> V_153 , & V_24 -> V_150 ) ;
}
void F_152 ( struct V_23 * V_24 )
{
if ( ! F_55 ( V_24 ) )
F_151 ( V_24 ) ;
}
