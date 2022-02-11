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
F_35 ( & V_8 -> V_21 , V_33 ) ;
F_57 (cur, &h->hash_list, hash_list) {
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
goto V_76;
}
if ( F_50 ( V_7 , V_24 ) ) {
F_21 ( V_7 , V_24 ) ;
F_32 ( & V_7 -> V_48 ) ;
V_45 = V_24 ;
V_27 = 1 ;
goto V_77;
}
F_57 (pending, &cur->plug_list,
plug_list) {
if ( F_50 ( V_74 , V_24 ) ) {
F_21 ( V_74 , V_24 ) ;
F_32 ( & V_7 -> V_48 ) ;
V_45 = V_24 ;
V_27 = 1 ;
goto V_77;
}
}
F_58 ( & V_24 -> V_51 , & V_7 -> V_51 ) ;
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
F_60 ( V_66 , & V_24 -> V_33 ) ;
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
F_61 ( V_52 ) ;
else if ( V_52 -> V_67 == V_69 ) {
F_17 ( V_24 , V_52 ) ;
F_61 ( V_52 ) ;
} else if ( V_52 -> V_67 == V_83 ) {
F_17 ( V_24 , V_52 ) ;
F_62 ( V_52 ) ;
} else if ( V_52 -> V_67 == V_68 ) {
F_17 ( V_24 , V_52 ) ;
F_63 ( V_52 ) ;
}
goto V_84;
} else if ( F_64 ( & V_8 -> V_22 ) ) {
F_32 ( & V_24 -> V_48 ) ;
F_36 ( & V_8 -> V_21 , V_33 ) ;
F_65 ( & V_8 -> V_22 ) ;
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
if ( ! F_66 ( & V_24 -> V_50 ) )
return;
F_67 ( ! F_29 ( & V_24 -> V_19 ) ) ;
F_67 ( ! F_29 ( & V_24 -> V_20 ) ) ;
F_67 ( ! F_28 ( & V_24 -> V_41 ) ) ;
for ( V_11 = 0 ; V_11 < V_24 -> V_28 ; V_11 ++ ) {
if ( V_24 -> V_30 [ V_11 ] ) {
F_20 ( V_24 -> V_30 [ V_11 ] ) ;
V_24 -> V_30 [ V_11 ] = NULL ;
}
}
F_68 ( V_24 -> V_35 ) ;
F_69 ( V_24 ) ;
}
static void F_70 ( struct V_23 * V_24 )
{
F_59 ( V_24 ) ;
F_33 ( V_24 ) ;
}
static void F_71 ( struct V_23 * V_24 , int V_85 )
{
struct V_86 * V_7 = F_72 ( & V_24 -> V_41 ) ;
struct V_86 * V_52 ;
if ( V_24 -> V_43 )
F_73 ( V_24 -> V_47 , V_24 -> V_43 ) ;
F_70 ( V_24 ) ;
while ( V_7 ) {
V_52 = V_7 -> V_87 ;
V_7 -> V_87 = NULL ;
V_7 -> V_88 = V_85 ;
F_74 ( V_7 ) ;
V_7 = V_52 ;
}
}
static void F_75 ( struct V_86 * V_86 )
{
struct V_23 * V_24 = V_86 -> V_89 ;
int V_85 = V_86 -> V_88 ;
int V_90 ;
if ( V_85 )
F_76 ( V_24 , V_86 ) ;
F_77 ( V_86 ) ;
if ( ! F_78 ( & V_24 -> V_91 ) )
return;
V_85 = 0 ;
V_90 = ( V_24 -> V_67 == V_68 ) ?
0 : V_24 -> V_35 -> V_90 ;
if ( F_79 ( & V_24 -> error ) > V_90 )
V_85 = - V_92 ;
F_71 ( V_24 , V_85 ) ;
}
static struct V_39 * F_80 ( struct V_23 * V_24 ,
int V_71 , int V_93 , int V_94 )
{
int V_95 ;
struct V_39 * V_96 = NULL ;
V_95 = V_71 * ( V_24 -> V_64 >> V_97 ) + V_93 ;
F_81 ( & V_24 -> V_48 ) ;
V_96 = V_24 -> V_29 [ V_95 ] ;
F_82 ( & V_24 -> V_48 ) ;
if ( V_96 || V_94 )
return V_96 ;
return V_24 -> V_30 [ V_95 ] ;
}
static unsigned long F_83 ( unsigned long V_64 , int V_98 )
{
return F_84 ( V_64 , V_31 ) * V_98 ;
}
static struct V_23 * F_85 ( struct V_1 * V_47 ,
struct V_99 * V_35 ,
T_1 V_64 )
{
struct V_23 * V_24 ;
int V_63 = 0 ;
int V_73 = V_35 -> V_100 - V_35 -> V_101 ;
int V_102 = F_83 ( V_64 , V_73 ) ;
int V_72 = F_84 ( V_64 , V_31 ) ;
void * V_96 ;
V_24 = F_2 ( sizeof( * V_24 ) + V_102 * sizeof( struct V_39 * ) * 2 +
F_84 ( V_72 , V_103 ) *
sizeof( long ) , V_104 ) ;
if ( ! V_24 )
return F_86 ( - V_17 ) ;
F_23 ( & V_24 -> V_41 ) ;
F_5 ( & V_24 -> V_51 ) ;
F_4 ( & V_24 -> V_48 ) ;
F_5 ( & V_24 -> V_19 ) ;
F_5 ( & V_24 -> V_20 ) ;
V_24 -> V_35 = V_35 ;
V_24 -> V_47 = V_47 ;
V_24 -> V_64 = V_64 ;
V_24 -> V_28 = V_102 ;
V_24 -> V_73 = V_73 ;
V_24 -> V_72 = V_72 ;
V_24 -> V_105 = - 1 ;
V_24 -> V_106 = - 1 ;
F_87 ( & V_24 -> V_50 , 1 ) ;
F_88 ( & V_24 -> error , 0 ) ;
F_88 ( & V_24 -> V_91 , 0 ) ;
V_96 = V_24 + 1 ;
V_24 -> V_30 = V_96 ;
V_24 -> V_29 = V_96 + sizeof( struct V_39 * ) * V_102 ;
V_24 -> V_107 = V_96 + sizeof( struct V_39 * ) * V_102 * 2 ;
if ( V_35 -> V_108 & V_109 )
V_63 = V_73 - 1 ;
else if ( V_35 -> V_108 & V_110 )
V_63 = V_73 - 2 ;
else
F_89 () ;
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
V_39 = F_90 ( V_104 | V_111 ) ;
if ( ! V_39 )
return - V_17 ;
V_24 -> V_30 [ V_11 ] = V_39 ;
}
return 0 ;
}
static int F_91 ( struct V_23 * V_24 )
{
int V_11 ;
struct V_39 * V_39 ;
V_11 = F_51 ( V_24 , V_24 -> V_63 , 0 ) ;
for (; V_11 < V_24 -> V_28 ; V_11 ++ ) {
if ( V_24 -> V_30 [ V_11 ] )
continue;
V_39 = F_90 ( V_104 | V_111 ) ;
if ( ! V_39 )
return - V_17 ;
V_24 -> V_30 [ V_11 ] = V_39 ;
}
return 0 ;
}
static int F_92 ( struct V_23 * V_24 ,
struct V_41 * V_41 ,
struct V_39 * V_39 ,
int V_112 ,
unsigned long V_113 ,
unsigned long V_114 )
{
struct V_86 * V_65 = V_41 -> V_115 ;
T_1 V_116 = 0 ;
int V_27 ;
struct V_86 * V_86 ;
struct V_117 * V_70 ;
T_1 V_118 ;
V_70 = & V_24 -> V_35 -> V_119 [ V_112 ] ;
V_118 = V_70 -> V_120 + ( V_113 << V_97 ) ;
if ( ! V_70 -> V_121 -> V_122 )
return F_93 ( V_24 , V_112 ) ;
if ( V_65 ) {
V_116 = ( T_1 ) V_65 -> V_123 . V_124 << 9 ;
V_116 += V_65 -> V_123 . V_125 ;
if ( V_116 == V_118 && V_70 -> V_121 -> V_122 &&
! V_65 -> V_88 &&
V_65 -> V_126 == V_70 -> V_121 -> V_122 ) {
V_27 = F_94 ( V_65 , V_39 , V_31 , 0 ) ;
if ( V_27 == V_31 )
return 0 ;
}
}
V_86 = F_95 ( V_104 , V_114 >> V_97 ? : 1 ) ;
if ( ! V_86 )
return - V_17 ;
V_86 -> V_123 . V_125 = 0 ;
V_86 -> V_126 = V_70 -> V_121 -> V_122 ;
V_86 -> V_123 . V_124 = V_118 >> 9 ;
F_94 ( V_86 , V_39 , V_31 , 0 ) ;
F_96 ( V_41 , V_86 ) ;
return 0 ;
}
static void F_97 ( struct V_23 * V_24 )
{
if ( V_24 -> V_105 >= 0 || V_24 -> V_106 >= 0 ) {
F_31 ( V_24 -> V_105 == V_24 -> V_73 - 1 ) ;
F_98 ( V_24 ) ;
} else {
F_99 ( V_24 ) ;
}
}
static void F_100 ( struct V_23 * V_24 )
{
struct V_86 * V_86 ;
struct V_127 * V_128 ;
T_1 V_129 ;
unsigned long V_130 ;
unsigned long V_113 ;
int V_11 ;
F_81 ( & V_24 -> V_48 ) ;
F_101 (bio, &rbio->bio_list) {
V_129 = ( T_1 ) V_86 -> V_123 . V_124 << 9 ;
V_130 = V_129 - V_24 -> V_35 -> V_36 [ 0 ] ;
V_113 = V_130 >> V_97 ;
F_102 (bvec, bio, i)
V_24 -> V_29 [ V_113 + V_11 ] = V_128 -> V_131 ;
}
F_82 ( & V_24 -> V_48 ) ;
}
static T_3 void F_99 ( struct V_23 * V_24 )
{
struct V_99 * V_35 = V_24 -> V_35 ;
void * V_132 [ V_24 -> V_73 ] ;
int V_63 = V_24 -> V_63 ;
int V_70 ;
int V_93 ;
int V_133 = - 1 ;
int V_134 = - 1 ;
struct V_41 V_41 ;
struct V_86 * V_86 ;
int V_27 ;
F_23 ( & V_41 ) ;
if ( V_24 -> V_73 - V_24 -> V_63 == 1 ) {
V_133 = V_24 -> V_73 - 1 ;
} else if ( V_24 -> V_73 - V_24 -> V_63 == 2 ) {
V_133 = V_24 -> V_73 - 2 ;
V_134 = V_24 -> V_73 - 1 ;
} else {
F_89 () ;
}
F_81 ( & V_24 -> V_48 ) ;
F_14 ( V_66 , & V_24 -> V_33 ) ;
F_82 ( & V_24 -> V_48 ) ;
F_88 ( & V_24 -> error , 0 ) ;
F_100 ( V_24 ) ;
if ( ! F_49 ( V_24 ) )
F_9 ( V_24 ) ;
else
F_60 ( V_32 , & V_24 -> V_33 ) ;
for ( V_93 = 0 ; V_93 < V_24 -> V_72 ; V_93 ++ ) {
struct V_39 * V_96 ;
for ( V_70 = 0 ; V_70 < V_63 ; V_70 ++ ) {
V_96 = F_80 ( V_24 , V_70 , V_93 , 0 ) ;
V_132 [ V_70 ] = F_11 ( V_96 ) ;
}
V_96 = F_53 ( V_24 , V_93 ) ;
F_13 ( V_96 ) ;
V_132 [ V_70 ++ ] = F_11 ( V_96 ) ;
if ( V_134 != - 1 ) {
V_96 = F_54 ( V_24 , V_93 ) ;
F_13 ( V_96 ) ;
V_132 [ V_70 ++ ] = F_11 ( V_96 ) ;
V_135 . V_136 ( V_24 -> V_73 , V_31 ,
V_132 ) ;
} else {
memcpy ( V_132 [ V_63 ] , V_132 [ 0 ] , V_31 ) ;
F_45 ( V_132 + 1 , V_63 - 1 , V_31 ) ;
}
for ( V_70 = 0 ; V_70 < V_24 -> V_73 ; V_70 ++ )
F_12 ( F_80 ( V_24 , V_70 , V_93 , 0 ) ) ;
}
for ( V_70 = 0 ; V_70 < V_24 -> V_73 ; V_70 ++ ) {
for ( V_93 = 0 ; V_93 < V_24 -> V_72 ; V_93 ++ ) {
struct V_39 * V_39 ;
if ( V_70 < V_24 -> V_63 ) {
V_39 = F_80 ( V_24 , V_70 , V_93 , 1 ) ;
if ( ! V_39 )
continue;
} else {
V_39 = F_52 ( V_24 , V_70 , V_93 ) ;
}
V_27 = F_92 ( V_24 , & V_41 ,
V_39 , V_70 , V_93 , V_24 -> V_64 ) ;
if ( V_27 )
goto V_137;
}
}
if ( F_103 ( ! V_35 -> V_101 ) )
goto V_138;
for ( V_70 = 0 ; V_70 < V_24 -> V_73 ; V_70 ++ ) {
if ( ! V_35 -> V_139 [ V_70 ] )
continue;
for ( V_93 = 0 ; V_93 < V_24 -> V_72 ; V_93 ++ ) {
struct V_39 * V_39 ;
if ( V_70 < V_24 -> V_63 ) {
V_39 = F_80 ( V_24 , V_70 , V_93 , 1 ) ;
if ( ! V_39 )
continue;
} else {
V_39 = F_52 ( V_24 , V_70 , V_93 ) ;
}
V_27 = F_92 ( V_24 , & V_41 , V_39 ,
V_24 -> V_35 -> V_139 [ V_70 ] ,
V_93 , V_24 -> V_64 ) ;
if ( V_27 )
goto V_137;
}
}
V_138:
F_88 ( & V_24 -> V_91 , F_104 ( & V_41 ) ) ;
F_31 ( F_79 ( & V_24 -> V_91 ) == 0 ) ;
while ( 1 ) {
V_86 = F_105 ( & V_41 ) ;
if ( ! V_86 )
break;
V_86 -> V_89 = V_24 ;
V_86 -> V_140 = F_75 ;
F_106 ( V_86 , V_141 , 0 ) ;
F_107 ( V_86 ) ;
}
return;
V_137:
F_71 ( V_24 , - V_92 ) ;
}
static int F_108 ( struct V_23 * V_24 ,
struct V_86 * V_86 )
{
T_1 V_120 = V_86 -> V_123 . V_124 ;
T_1 V_142 ;
int V_11 ;
struct V_117 * V_70 ;
V_120 <<= 9 ;
for ( V_11 = 0 ; V_11 < V_24 -> V_35 -> V_100 ; V_11 ++ ) {
V_70 = & V_24 -> V_35 -> V_119 [ V_11 ] ;
V_142 = V_70 -> V_120 ;
if ( V_120 >= V_142 &&
V_120 < V_142 + V_24 -> V_64 &&
V_86 -> V_126 == V_70 -> V_121 -> V_122 ) {
return V_11 ;
}
}
return - 1 ;
}
static int F_109 ( struct V_23 * V_24 ,
struct V_86 * V_86 )
{
T_1 V_143 = V_86 -> V_123 . V_124 ;
T_1 V_142 ;
int V_11 ;
V_143 <<= 9 ;
for ( V_11 = 0 ; V_11 < V_24 -> V_63 ; V_11 ++ ) {
V_142 = V_24 -> V_35 -> V_36 [ V_11 ] ;
if ( V_143 >= V_142 &&
V_143 < V_142 + V_24 -> V_64 ) {
return V_11 ;
}
}
return - 1 ;
}
static int F_93 ( struct V_23 * V_24 , int V_144 )
{
unsigned long V_33 ;
int V_27 = 0 ;
F_35 ( & V_24 -> V_48 , V_33 ) ;
if ( V_24 -> V_105 == V_144 || V_24 -> V_106 == V_144 )
goto V_77;
if ( V_24 -> V_105 == - 1 ) {
V_24 -> V_105 = V_144 ;
F_110 ( & V_24 -> error ) ;
} else if ( V_24 -> V_106 == - 1 ) {
V_24 -> V_106 = V_144 ;
F_110 ( & V_24 -> error ) ;
} else {
V_27 = - V_92 ;
}
V_77:
F_36 ( & V_24 -> V_48 , V_33 ) ;
return V_27 ;
}
static int F_76 ( struct V_23 * V_24 ,
struct V_86 * V_86 )
{
int V_144 = F_108 ( V_24 , V_86 ) ;
if ( V_144 < 0 )
return - V_92 ;
return F_93 ( V_24 , V_144 ) ;
}
static void F_111 ( struct V_86 * V_86 )
{
struct V_127 * V_128 ;
int V_11 ;
F_102 (bvec, bio, i)
F_13 ( V_128 -> V_131 ) ;
}
static void F_112 ( struct V_86 * V_86 )
{
struct V_23 * V_24 = V_86 -> V_89 ;
if ( V_86 -> V_88 )
F_76 ( V_24 , V_86 ) ;
else
F_111 ( V_86 ) ;
F_77 ( V_86 ) ;
if ( ! F_78 ( & V_24 -> V_91 ) )
return;
if ( F_79 ( & V_24 -> error ) > V_24 -> V_35 -> V_90 )
goto V_137;
F_97 ( V_24 ) ;
return;
V_137:
F_71 ( V_24 , - V_92 ) ;
}
static void F_62 ( struct V_23 * V_24 )
{
F_113 ( & V_24 -> V_145 , V_146 , V_147 , NULL , NULL ) ;
F_114 ( V_24 -> V_47 -> V_148 , & V_24 -> V_145 ) ;
}
static void F_61 ( struct V_23 * V_24 )
{
F_113 ( & V_24 -> V_145 , V_146 ,
V_149 , NULL , NULL ) ;
F_114 ( V_24 -> V_47 -> V_148 , & V_24 -> V_145 ) ;
}
static int F_115 ( struct V_23 * V_24 )
{
int V_150 = 0 ;
struct V_41 V_41 ;
int V_27 ;
int V_93 ;
int V_70 ;
struct V_86 * V_86 ;
F_23 ( & V_41 ) ;
V_27 = F_10 ( V_24 ) ;
if ( V_27 )
goto V_137;
F_100 ( V_24 ) ;
F_88 ( & V_24 -> error , 0 ) ;
for ( V_70 = 0 ; V_70 < V_24 -> V_63 ; V_70 ++ ) {
for ( V_93 = 0 ; V_93 < V_24 -> V_72 ; V_93 ++ ) {
struct V_39 * V_39 ;
V_39 = F_80 ( V_24 , V_70 , V_93 , 1 ) ;
if ( V_39 )
continue;
V_39 = F_52 ( V_24 , V_70 , V_93 ) ;
if ( F_19 ( V_39 ) )
continue;
V_27 = F_92 ( V_24 , & V_41 , V_39 ,
V_70 , V_93 , V_24 -> V_64 ) ;
if ( V_27 )
goto V_137;
}
}
V_150 = F_104 ( & V_41 ) ;
if ( ! V_150 ) {
goto V_151;
}
F_88 ( & V_24 -> V_91 , V_150 ) ;
while ( 1 ) {
V_86 = F_105 ( & V_41 ) ;
if ( ! V_86 )
break;
V_86 -> V_89 = V_24 ;
V_86 -> V_140 = F_112 ;
F_106 ( V_86 , V_152 , 0 ) ;
F_116 ( V_24 -> V_47 , V_86 , V_153 ) ;
F_107 ( V_86 ) ;
}
return 0 ;
V_137:
F_71 ( V_24 , - V_92 ) ;
return - V_92 ;
V_151:
F_97 ( V_24 ) ;
return 0 ;
}
static int F_117 ( struct V_23 * V_24 )
{
int V_27 ;
V_27 = F_91 ( V_24 ) ;
if ( V_27 ) {
F_33 ( V_24 ) ;
return V_27 ;
}
V_27 = F_55 ( V_24 ) ;
if ( V_27 == 0 )
F_99 ( V_24 ) ;
return 0 ;
}
static int F_118 ( struct V_23 * V_24 )
{
int V_27 ;
V_27 = F_55 ( V_24 ) ;
if ( V_27 == 0 )
F_62 ( V_24 ) ;
return 0 ;
}
static int F_119 ( struct V_23 * V_24 )
{
if ( ! F_49 ( V_24 ) )
return F_118 ( V_24 ) ;
return F_117 ( V_24 ) ;
}
static int F_120 ( void * V_154 , struct V_80 * V_155 , struct V_80 * V_156 )
{
struct V_23 * V_157 = F_121 ( V_155 , struct V_23 ,
V_51 ) ;
struct V_23 * V_158 = F_121 ( V_156 , struct V_23 ,
V_51 ) ;
T_1 V_159 = V_157 -> V_41 . V_81 -> V_123 . V_124 ;
T_1 V_160 = V_158 -> V_41 . V_81 -> V_123 . V_124 ;
if ( V_159 < V_160 )
return - 1 ;
if ( V_159 > V_160 )
return 1 ;
return 0 ;
}
static void F_122 ( struct V_161 * V_162 )
{
struct V_23 * V_7 ;
struct V_23 * V_65 = NULL ;
F_123 ( NULL , & V_162 -> V_163 , F_120 ) ;
while ( ! F_29 ( & V_162 -> V_163 ) ) {
V_7 = F_38 ( V_162 -> V_163 . V_52 ,
struct V_23 , V_51 ) ;
F_27 ( & V_7 -> V_51 ) ;
if ( F_49 ( V_7 ) ) {
F_117 ( V_7 ) ;
continue;
}
if ( V_65 ) {
if ( F_50 ( V_65 , V_7 ) ) {
F_21 ( V_65 , V_7 ) ;
F_33 ( V_7 ) ;
continue;
}
F_119 ( V_65 ) ;
}
V_65 = V_7 ;
}
if ( V_65 ) {
F_119 ( V_65 ) ;
}
F_69 ( V_162 ) ;
}
static void F_124 ( struct V_164 * V_145 )
{
struct V_161 * V_162 ;
V_162 = F_121 ( V_145 , struct V_161 , V_145 ) ;
F_122 ( V_162 ) ;
}
static void F_125 ( struct V_165 * V_166 , bool V_167 )
{
struct V_161 * V_162 ;
V_162 = F_121 ( V_166 , struct V_161 , V_166 ) ;
if ( V_167 ) {
F_113 ( & V_162 -> V_145 , V_146 ,
F_124 , NULL , NULL ) ;
F_114 ( V_162 -> V_2 -> V_148 ,
& V_162 -> V_145 ) ;
return;
}
F_122 ( V_162 ) ;
}
int F_126 ( struct V_1 * V_47 , struct V_86 * V_86 ,
struct V_99 * V_35 , T_1 V_64 )
{
struct V_23 * V_24 ;
struct V_161 * V_162 = NULL ;
struct V_165 * V_166 ;
int V_27 ;
V_24 = F_85 ( V_47 , V_35 , V_64 ) ;
if ( F_127 ( V_24 ) ) {
F_68 ( V_35 ) ;
return F_128 ( V_24 ) ;
}
F_96 ( & V_24 -> V_41 , V_86 ) ;
V_24 -> V_42 = V_86 -> V_123 . V_125 ;
V_24 -> V_67 = V_83 ;
F_129 ( V_47 ) ;
V_24 -> V_43 = 1 ;
if ( F_49 ( V_24 ) ) {
V_27 = F_117 ( V_24 ) ;
if ( V_27 )
F_130 ( V_47 ) ;
return V_27 ;
}
V_166 = F_131 ( F_125 , V_47 , sizeof( * V_162 ) ) ;
if ( V_166 ) {
V_162 = F_121 ( V_166 , struct V_161 , V_166 ) ;
if ( ! V_162 -> V_2 ) {
V_162 -> V_2 = V_47 ;
F_5 ( & V_162 -> V_163 ) ;
}
F_58 ( & V_24 -> V_51 , & V_162 -> V_163 ) ;
V_27 = 0 ;
} else {
V_27 = F_119 ( V_24 ) ;
if ( V_27 )
F_130 ( V_47 ) ;
}
return V_27 ;
}
static void F_132 ( struct V_23 * V_24 )
{
int V_93 , V_70 ;
void * * V_132 ;
int V_105 = - 1 , V_106 = - 1 ;
struct V_39 * V_39 ;
int V_85 ;
int V_11 ;
V_132 = F_133 ( V_24 -> V_73 , sizeof( void * ) , V_104 ) ;
if ( ! V_132 ) {
V_85 = - V_17 ;
goto V_168;
}
V_105 = V_24 -> V_105 ;
V_106 = V_24 -> V_106 ;
if ( V_24 -> V_67 == V_82 ||
V_24 -> V_67 == V_69 ) {
F_81 ( & V_24 -> V_48 ) ;
F_14 ( V_66 , & V_24 -> V_33 ) ;
F_82 ( & V_24 -> V_48 ) ;
}
F_100 ( V_24 ) ;
for ( V_93 = 0 ; V_93 < V_24 -> V_72 ; V_93 ++ ) {
if ( V_24 -> V_67 == V_68 &&
! F_18 ( V_93 , V_24 -> V_107 ) )
continue;
for ( V_70 = 0 ; V_70 < V_24 -> V_73 ; V_70 ++ ) {
if ( ( V_24 -> V_67 == V_82 ||
V_24 -> V_67 == V_69 ) &&
( V_70 == V_105 || V_70 == V_106 ) ) {
V_39 = F_80 ( V_24 , V_70 , V_93 , 0 ) ;
} else {
V_39 = F_52 ( V_24 , V_70 , V_93 ) ;
}
V_132 [ V_70 ] = F_11 ( V_39 ) ;
}
if ( V_24 -> V_35 -> V_108 & V_110 ) {
if ( V_106 < 0 ) {
if ( V_105 == V_24 -> V_63 ) {
V_85 = - V_92 ;
goto V_137;
}
goto V_169;
}
if ( V_105 > V_106 ) {
int V_170 = V_106 ;
V_106 = V_105 ;
V_105 = V_170 ;
}
if ( V_24 -> V_35 -> V_36 [ V_106 ] == V_171 ) {
if ( V_24 -> V_35 -> V_36 [ V_105 ] ==
V_172 ) {
V_85 = - V_92 ;
goto V_137;
}
goto V_169;
}
if ( V_24 -> V_35 -> V_36 [ V_106 ] == V_172 ) {
F_134 ( V_24 -> V_73 ,
V_31 , V_105 , V_132 ) ;
} else {
F_135 ( V_24 -> V_73 ,
V_31 , V_105 , V_106 ,
V_132 ) ;
}
} else {
void * V_96 ;
F_31 ( V_106 != - 1 ) ;
V_169:
memcpy ( V_132 [ V_105 ] ,
V_132 [ V_24 -> V_63 ] ,
V_31 ) ;
V_96 = V_132 [ V_105 ] ;
for ( V_70 = V_105 ; V_70 < V_24 -> V_63 - 1 ; V_70 ++ )
V_132 [ V_70 ] = V_132 [ V_70 + 1 ] ;
V_132 [ V_24 -> V_63 - 1 ] = V_96 ;
F_45 ( V_132 , V_24 -> V_63 - 1 , V_31 ) ;
}
if ( V_24 -> V_67 == V_83 ) {
for ( V_11 = 0 ; V_11 < V_24 -> V_72 ; V_11 ++ ) {
if ( V_105 != - 1 ) {
V_39 = F_52 ( V_24 , V_105 , V_11 ) ;
F_13 ( V_39 ) ;
}
if ( V_106 != - 1 ) {
V_39 = F_52 ( V_24 , V_106 , V_11 ) ;
F_13 ( V_39 ) ;
}
}
}
for ( V_70 = 0 ; V_70 < V_24 -> V_73 ; V_70 ++ ) {
if ( ( V_24 -> V_67 == V_82 ||
V_24 -> V_67 == V_69 ) &&
( V_70 == V_105 || V_70 == V_106 ) ) {
V_39 = F_80 ( V_24 , V_70 , V_93 , 0 ) ;
} else {
V_39 = F_52 ( V_24 , V_70 , V_93 ) ;
}
F_12 ( V_39 ) ;
}
}
V_85 = 0 ;
V_137:
F_69 ( V_132 ) ;
V_168:
if ( V_24 -> V_67 == V_82 ) {
if ( V_85 == 0 )
F_9 ( V_24 ) ;
else
F_60 ( V_32 , & V_24 -> V_33 ) ;
F_71 ( V_24 , V_85 ) ;
} else if ( V_24 -> V_67 == V_69 ) {
F_71 ( V_24 , V_85 ) ;
} else if ( V_85 == 0 ) {
V_24 -> V_105 = - 1 ;
V_24 -> V_106 = - 1 ;
if ( V_24 -> V_67 == V_83 )
F_99 ( V_24 ) ;
else if ( V_24 -> V_67 == V_68 )
F_136 ( V_24 , 0 ) ;
else
F_89 () ;
} else {
F_71 ( V_24 , V_85 ) ;
}
}
static void F_137 ( struct V_86 * V_86 )
{
struct V_23 * V_24 = V_86 -> V_89 ;
if ( V_86 -> V_88 )
F_76 ( V_24 , V_86 ) ;
else
F_111 ( V_86 ) ;
F_77 ( V_86 ) ;
if ( ! F_78 ( & V_24 -> V_91 ) )
return;
if ( F_79 ( & V_24 -> error ) > V_24 -> V_35 -> V_90 )
F_71 ( V_24 , - V_92 ) ;
else
F_132 ( V_24 ) ;
}
static int F_98 ( struct V_23 * V_24 )
{
int V_150 = 0 ;
struct V_41 V_41 ;
int V_27 ;
int V_93 ;
int V_70 ;
struct V_86 * V_86 ;
F_23 ( & V_41 ) ;
V_27 = F_10 ( V_24 ) ;
if ( V_27 )
goto V_137;
F_88 ( & V_24 -> error , 0 ) ;
for ( V_70 = 0 ; V_70 < V_24 -> V_73 ; V_70 ++ ) {
if ( V_24 -> V_105 == V_70 || V_24 -> V_106 == V_70 ) {
F_110 ( & V_24 -> error ) ;
continue;
}
for ( V_93 = 0 ; V_93 < V_24 -> V_72 ; V_93 ++ ) {
struct V_39 * V_96 ;
V_96 = F_52 ( V_24 , V_70 , V_93 ) ;
if ( F_19 ( V_96 ) )
continue;
V_27 = F_92 ( V_24 , & V_41 ,
F_52 ( V_24 , V_70 , V_93 ) ,
V_70 , V_93 , V_24 -> V_64 ) ;
if ( V_27 < 0 )
goto V_137;
}
}
V_150 = F_104 ( & V_41 ) ;
if ( ! V_150 ) {
if ( F_79 ( & V_24 -> error ) <= V_24 -> V_35 -> V_90 ) {
F_132 ( V_24 ) ;
goto V_77;
} else {
goto V_137;
}
}
F_88 ( & V_24 -> V_91 , V_150 ) ;
while ( 1 ) {
V_86 = F_105 ( & V_41 ) ;
if ( ! V_86 )
break;
V_86 -> V_89 = V_24 ;
V_86 -> V_140 = F_137 ;
F_106 ( V_86 , V_152 , 0 ) ;
F_116 ( V_24 -> V_47 , V_86 , V_153 ) ;
F_107 ( V_86 ) ;
}
V_77:
return 0 ;
V_137:
if ( V_24 -> V_67 == V_82 ||
V_24 -> V_67 == V_69 )
F_71 ( V_24 , - V_92 ) ;
return - V_92 ;
}
int F_138 ( struct V_1 * V_47 , struct V_86 * V_86 ,
struct V_99 * V_35 , T_1 V_64 ,
int V_173 , int V_174 )
{
struct V_23 * V_24 ;
int V_27 ;
if ( V_174 ) {
ASSERT ( V_35 -> V_173 == V_173 ) ;
F_139 ( V_86 ) -> V_173 = V_173 ;
}
V_24 = F_85 ( V_47 , V_35 , V_64 ) ;
if ( F_127 ( V_24 ) ) {
if ( V_174 )
F_68 ( V_35 ) ;
return F_128 ( V_24 ) ;
}
V_24 -> V_67 = V_82 ;
F_96 ( & V_24 -> V_41 , V_86 ) ;
V_24 -> V_42 = V_86 -> V_123 . V_125 ;
V_24 -> V_105 = F_109 ( V_24 , V_86 ) ;
if ( V_24 -> V_105 == - 1 ) {
F_140 ( V_47 ,
L_1 ,
V_175 , ( T_1 ) V_86 -> V_123 . V_124 << 9 ,
( T_1 ) V_86 -> V_123 . V_125 , V_35 -> V_108 ) ;
if ( V_174 )
F_68 ( V_35 ) ;
F_69 ( V_24 ) ;
return - V_92 ;
}
if ( V_174 ) {
F_129 ( V_47 ) ;
V_24 -> V_43 = 1 ;
} else {
F_141 ( V_35 ) ;
}
if ( V_173 == 3 )
V_24 -> V_106 = V_24 -> V_73 - 2 ;
V_27 = F_55 ( V_24 ) ;
if ( V_27 == 0 )
F_98 ( V_24 ) ;
return 0 ;
}
static void V_147 ( struct V_164 * V_145 )
{
struct V_23 * V_24 ;
V_24 = F_121 ( V_145 , struct V_23 , V_145 ) ;
F_115 ( V_24 ) ;
}
static void V_149 ( struct V_164 * V_145 )
{
struct V_23 * V_24 ;
V_24 = F_121 ( V_145 , struct V_23 , V_145 ) ;
F_98 ( V_24 ) ;
}
struct V_23 *
F_142 ( struct V_1 * V_47 , struct V_86 * V_86 ,
struct V_99 * V_35 , T_1 V_64 ,
struct V_176 * V_177 ,
unsigned long * V_107 , int V_178 )
{
struct V_23 * V_24 ;
int V_11 ;
V_24 = F_85 ( V_47 , V_35 , V_64 ) ;
if ( F_127 ( V_24 ) )
return NULL ;
F_96 ( & V_24 -> V_41 , V_86 ) ;
ASSERT ( ! V_86 -> V_123 . V_125 ) ;
V_24 -> V_67 = V_68 ;
for ( V_11 = 0 ; V_11 < V_24 -> V_73 ; V_11 ++ ) {
if ( V_35 -> V_119 [ V_11 ] . V_121 == V_177 ) {
V_24 -> V_179 = V_11 ;
break;
}
}
ASSERT ( V_47 -> V_180 == V_31 ) ;
ASSERT ( V_24 -> V_72 == V_178 ) ;
F_143 ( V_24 -> V_107 , V_107 , V_178 ) ;
V_24 -> V_43 = 1 ;
return V_24 ;
}
void F_144 ( struct V_23 * V_24 , struct V_39 * V_39 ,
T_1 V_143 )
{
int V_130 ;
int V_71 ;
ASSERT ( V_143 >= V_24 -> V_35 -> V_36 [ 0 ] ) ;
ASSERT ( V_143 + V_31 <= V_24 -> V_35 -> V_36 [ 0 ] +
V_24 -> V_64 * V_24 -> V_63 ) ;
V_130 = ( int ) ( V_143 - V_24 -> V_35 -> V_36 [ 0 ] ) ;
V_71 = V_130 >> V_97 ;
V_24 -> V_29 [ V_71 ] = V_39 ;
}
static int F_145 ( struct V_23 * V_24 )
{
int V_11 ;
int V_181 ;
int V_71 ;
struct V_39 * V_39 ;
F_146 (bit, rbio->dbitmap, rbio->stripe_npages) {
for ( V_11 = 0 ; V_11 < V_24 -> V_73 ; V_11 ++ ) {
V_71 = V_11 * V_24 -> V_72 + V_181 ;
if ( V_24 -> V_30 [ V_71 ] )
continue;
V_39 = F_90 ( V_104 | V_111 ) ;
if ( ! V_39 )
return - V_17 ;
V_24 -> V_30 [ V_71 ] = V_39 ;
}
}
return 0 ;
}
static T_3 void F_136 ( struct V_23 * V_24 ,
int V_182 )
{
struct V_99 * V_35 = V_24 -> V_35 ;
void * V_132 [ V_24 -> V_73 ] ;
F_147 ( V_183 , V_24 -> V_72 ) ;
int V_63 = V_24 -> V_63 ;
int V_70 ;
int V_93 ;
int V_133 = - 1 ;
int V_134 = - 1 ;
struct V_39 * V_184 = NULL ;
struct V_39 * V_185 = NULL ;
struct V_41 V_41 ;
struct V_86 * V_86 ;
int V_186 = 0 ;
int V_27 ;
F_23 ( & V_41 ) ;
if ( V_24 -> V_73 - V_24 -> V_63 == 1 ) {
V_133 = V_24 -> V_73 - 1 ;
} else if ( V_24 -> V_73 - V_24 -> V_63 == 2 ) {
V_133 = V_24 -> V_73 - 2 ;
V_134 = V_24 -> V_73 - 1 ;
} else {
F_89 () ;
}
if ( V_35 -> V_101 && V_35 -> V_139 [ V_24 -> V_179 ] ) {
V_186 = 1 ;
F_143 ( V_183 , V_24 -> V_107 , V_24 -> V_72 ) ;
}
F_60 ( V_32 , & V_24 -> V_33 ) ;
if ( ! V_182 )
goto V_187;
V_184 = F_90 ( V_104 | V_111 ) ;
if ( ! V_184 )
goto V_137;
F_13 ( V_184 ) ;
if ( V_134 != - 1 ) {
V_185 = F_90 ( V_104 | V_111 ) ;
if ( ! V_185 ) {
F_20 ( V_184 ) ;
goto V_137;
}
F_13 ( V_185 ) ;
}
F_88 ( & V_24 -> error , 0 ) ;
F_146 (pagenr, rbio->dbitmap, rbio->stripe_npages) {
struct V_39 * V_96 ;
void * V_188 ;
for ( V_70 = 0 ; V_70 < V_63 ; V_70 ++ ) {
V_96 = F_80 ( V_24 , V_70 , V_93 , 0 ) ;
V_132 [ V_70 ] = F_11 ( V_96 ) ;
}
V_132 [ V_70 ++ ] = F_11 ( V_184 ) ;
if ( V_134 != - 1 ) {
V_132 [ V_70 ++ ] = F_11 ( V_185 ) ;
V_135 . V_136 ( V_24 -> V_73 , V_31 ,
V_132 ) ;
} else {
memcpy ( V_132 [ V_63 ] , V_132 [ 0 ] , V_31 ) ;
F_45 ( V_132 + 1 , V_63 - 1 , V_31 ) ;
}
V_96 = F_52 ( V_24 , V_24 -> V_179 , V_93 ) ;
V_188 = F_11 ( V_96 ) ;
if ( memcmp ( V_188 , V_132 [ V_24 -> V_179 ] , V_31 ) )
memcpy ( V_188 , V_132 [ V_24 -> V_179 ] , V_31 ) ;
else
F_148 ( V_24 -> V_107 , V_93 , 1 ) ;
F_12 ( V_96 ) ;
for ( V_70 = 0 ; V_70 < V_24 -> V_73 ; V_70 ++ )
F_12 ( F_80 ( V_24 , V_70 , V_93 , 0 ) ) ;
}
F_20 ( V_184 ) ;
if ( V_185 )
F_20 ( V_185 ) ;
V_187:
F_146 (pagenr, rbio->dbitmap, rbio->stripe_npages) {
struct V_39 * V_39 ;
V_39 = F_52 ( V_24 , V_24 -> V_179 , V_93 ) ;
V_27 = F_92 ( V_24 , & V_41 ,
V_39 , V_24 -> V_179 , V_93 , V_24 -> V_64 ) ;
if ( V_27 )
goto V_137;
}
if ( ! V_186 )
goto V_189;
F_146 (pagenr, pbitmap, rbio->stripe_npages) {
struct V_39 * V_39 ;
V_39 = F_52 ( V_24 , V_24 -> V_179 , V_93 ) ;
V_27 = F_92 ( V_24 , & V_41 , V_39 ,
V_35 -> V_139 [ V_24 -> V_179 ] ,
V_93 , V_24 -> V_64 ) ;
if ( V_27 )
goto V_137;
}
V_189:
V_63 = F_104 ( & V_41 ) ;
if ( ! V_63 ) {
F_71 ( V_24 , 0 ) ;
return;
}
F_88 ( & V_24 -> V_91 , V_63 ) ;
while ( 1 ) {
V_86 = F_105 ( & V_41 ) ;
if ( ! V_86 )
break;
V_86 -> V_89 = V_24 ;
V_86 -> V_140 = F_75 ;
F_106 ( V_86 , V_141 , 0 ) ;
F_107 ( V_86 ) ;
}
return;
V_137:
F_71 ( V_24 , - V_92 ) ;
}
static inline int F_149 ( struct V_23 * V_24 , int V_70 )
{
if ( V_70 >= 0 && V_70 < V_24 -> V_63 )
return 1 ;
return 0 ;
}
static void F_150 ( struct V_23 * V_24 )
{
if ( F_79 ( & V_24 -> error ) > V_24 -> V_35 -> V_90 )
goto V_137;
if ( V_24 -> V_105 >= 0 || V_24 -> V_106 >= 0 ) {
int V_190 = 0 , V_191 = - 1 ;
if ( F_149 ( V_24 , V_24 -> V_105 ) )
V_190 ++ ;
else if ( F_151 ( V_24 -> V_105 ) )
V_191 = V_24 -> V_105 ;
if ( F_149 ( V_24 , V_24 -> V_106 ) )
V_190 ++ ;
else if ( F_151 ( V_24 -> V_106 ) )
V_191 = V_24 -> V_106 ;
if ( V_190 > V_24 -> V_35 -> V_90 - 1 )
goto V_137;
if ( V_190 == 0 ) {
F_136 ( V_24 , 0 ) ;
return;
}
if ( V_191 != V_24 -> V_179 )
goto V_137;
F_132 ( V_24 ) ;
} else {
F_136 ( V_24 , 1 ) ;
}
return;
V_137:
F_71 ( V_24 , - V_92 ) ;
}
static void F_152 ( struct V_86 * V_86 )
{
struct V_23 * V_24 = V_86 -> V_89 ;
if ( V_86 -> V_88 )
F_76 ( V_24 , V_86 ) ;
else
F_111 ( V_86 ) ;
F_77 ( V_86 ) ;
if ( ! F_78 ( & V_24 -> V_91 ) )
return;
F_150 ( V_24 ) ;
}
static void F_153 ( struct V_23 * V_24 )
{
int V_150 = 0 ;
struct V_41 V_41 ;
int V_27 ;
int V_93 ;
int V_70 ;
struct V_86 * V_86 ;
V_27 = F_145 ( V_24 ) ;
if ( V_27 )
goto V_137;
F_23 ( & V_41 ) ;
F_88 ( & V_24 -> error , 0 ) ;
for ( V_70 = 0 ; V_70 < V_24 -> V_73 ; V_70 ++ ) {
F_146 (pagenr, rbio->dbitmap, rbio->stripe_npages) {
struct V_39 * V_39 ;
V_39 = F_80 ( V_24 , V_70 , V_93 , 1 ) ;
if ( V_39 )
continue;
V_39 = F_52 ( V_24 , V_70 , V_93 ) ;
if ( F_19 ( V_39 ) )
continue;
V_27 = F_92 ( V_24 , & V_41 , V_39 ,
V_70 , V_93 , V_24 -> V_64 ) ;
if ( V_27 )
goto V_137;
}
}
V_150 = F_104 ( & V_41 ) ;
if ( ! V_150 ) {
goto V_151;
}
F_88 ( & V_24 -> V_91 , V_150 ) ;
while ( 1 ) {
V_86 = F_105 ( & V_41 ) ;
if ( ! V_86 )
break;
V_86 -> V_89 = V_24 ;
V_86 -> V_140 = F_152 ;
F_106 ( V_86 , V_152 , 0 ) ;
F_116 ( V_24 -> V_47 , V_86 , V_153 ) ;
F_107 ( V_86 ) ;
}
return;
V_137:
F_71 ( V_24 , - V_92 ) ;
return;
V_151:
F_150 ( V_24 ) ;
}
static void F_154 ( struct V_164 * V_145 )
{
struct V_23 * V_24 ;
V_24 = F_121 ( V_145 , struct V_23 , V_145 ) ;
F_153 ( V_24 ) ;
}
static void F_63 ( struct V_23 * V_24 )
{
F_113 ( & V_24 -> V_145 , V_146 ,
F_154 , NULL , NULL ) ;
F_114 ( V_24 -> V_47 -> V_148 , & V_24 -> V_145 ) ;
}
void F_155 ( struct V_23 * V_24 )
{
if ( ! F_55 ( V_24 ) )
F_63 ( V_24 ) ;
}
struct V_23 *
F_156 ( struct V_1 * V_47 , struct V_86 * V_86 ,
struct V_99 * V_35 , T_1 V_192 )
{
struct V_23 * V_24 ;
V_24 = F_85 ( V_47 , V_35 , V_192 ) ;
if ( F_127 ( V_24 ) )
return NULL ;
V_24 -> V_67 = V_69 ;
F_96 ( & V_24 -> V_41 , V_86 ) ;
ASSERT ( ! V_86 -> V_123 . V_125 ) ;
V_24 -> V_105 = F_109 ( V_24 , V_86 ) ;
if ( V_24 -> V_105 == - 1 ) {
F_89 () ;
F_69 ( V_24 ) ;
return NULL ;
}
V_24 -> V_43 = 1 ;
return V_24 ;
}
static void F_157 ( struct V_164 * V_145 )
{
struct V_23 * V_24 ;
V_24 = F_121 ( V_145 , struct V_23 , V_145 ) ;
F_98 ( V_24 ) ;
}
static void F_158 ( struct V_23 * V_24 )
{
F_113 ( & V_24 -> V_145 , V_146 ,
F_157 , NULL , NULL ) ;
F_114 ( V_24 -> V_47 -> V_148 , & V_24 -> V_145 ) ;
}
void F_159 ( struct V_23 * V_24 )
{
if ( ! F_55 ( V_24 ) )
F_158 ( V_24 ) ;
}
