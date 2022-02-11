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
V_4 = F_2 ( V_12 , V_14 ) ;
if ( ! V_4 )
return - V_15 ;
F_3 ( & V_4 -> V_16 ) ;
F_4 ( & V_4 -> V_17 ) ;
V_8 = V_4 -> V_4 ;
for ( V_11 = 0 ; V_11 < V_9 ; V_11 ++ ) {
V_7 = V_8 + V_11 ;
F_4 ( & V_7 -> V_18 ) ;
F_3 ( & V_7 -> V_19 ) ;
F_5 ( & V_7 -> V_20 ) ;
}
V_5 = F_6 ( & V_2 -> V_13 , NULL , V_4 ) ;
if ( V_5 )
F_7 ( V_5 ) ;
return 0 ;
}
static void F_8 ( struct V_21 * V_22 )
{
int V_11 ;
char * V_23 ;
char * V_24 ;
int V_25 ;
V_25 = F_9 ( V_22 ) ;
if ( V_25 )
return;
for ( V_11 = 0 ; V_11 < V_22 -> V_26 ; V_11 ++ ) {
if ( ! V_22 -> V_27 [ V_11 ] )
continue;
V_23 = F_10 ( V_22 -> V_27 [ V_11 ] ) ;
V_24 = F_10 ( V_22 -> V_28 [ V_11 ] ) ;
memcpy ( V_24 , V_23 , V_29 ) ;
F_11 ( V_22 -> V_27 [ V_11 ] ) ;
F_11 ( V_22 -> V_28 [ V_11 ] ) ;
F_12 ( V_22 -> V_28 [ V_11 ] ) ;
}
F_13 ( V_30 , & V_22 -> V_31 ) ;
}
static int F_14 ( struct V_21 * V_22 )
{
T_1 V_32 = V_22 -> V_33 -> V_34 [ 0 ] ;
return F_15 ( V_32 >> 16 , V_10 ) ;
}
static void F_16 ( struct V_21 * V_35 , struct V_21 * V_36 )
{
int V_11 ;
struct V_37 * V_23 ;
struct V_37 * V_24 ;
if ( ! F_17 ( V_30 , & V_35 -> V_31 ) )
return;
for ( V_11 = 0 ; V_11 < V_36 -> V_26 ; V_11 ++ ) {
V_23 = V_35 -> V_28 [ V_11 ] ;
if ( ! V_23 || ! F_18 ( V_23 ) ) {
continue;
}
V_24 = V_36 -> V_28 [ V_11 ] ;
if ( V_24 )
F_19 ( V_24 ) ;
V_36 -> V_28 [ V_11 ] = V_23 ;
V_35 -> V_28 [ V_11 ] = NULL ;
}
}
static void F_20 ( struct V_21 * V_36 ,
struct V_21 * V_38 )
{
F_21 ( & V_36 -> V_39 , & V_38 -> V_39 ) ;
V_36 -> V_40 += V_38 -> V_40 ;
V_36 -> V_41 += V_38 -> V_41 ;
F_22 ( & V_38 -> V_39 ) ;
}
static void F_23 ( struct V_21 * V_22 )
{
int V_42 = F_14 ( V_22 ) ;
struct V_3 * V_4 ;
struct V_6 * V_8 ;
int V_43 = 0 ;
if ( ! F_17 ( V_44 , & V_22 -> V_31 ) )
return;
V_4 = V_22 -> V_45 -> V_13 ;
V_8 = V_4 -> V_4 + V_42 ;
F_24 ( & V_8 -> V_19 ) ;
F_24 ( & V_22 -> V_46 ) ;
if ( F_25 ( V_44 , & V_22 -> V_31 ) ) {
F_26 ( & V_22 -> V_17 ) ;
V_4 -> V_47 -= 1 ;
V_43 = 1 ;
if ( F_27 ( & V_22 -> V_39 ) ) {
if ( ! F_28 ( & V_22 -> V_18 ) ) {
F_26 ( & V_22 -> V_18 ) ;
F_29 ( & V_22 -> V_48 ) ;
F_30 ( ! F_28 ( & V_22 -> V_49 ) ) ;
}
}
}
F_31 ( & V_22 -> V_46 ) ;
F_31 ( & V_8 -> V_19 ) ;
if ( V_43 )
F_32 ( V_22 ) ;
}
static void F_33 ( struct V_21 * V_22 )
{
struct V_3 * V_4 ;
unsigned long V_31 ;
if ( ! F_17 ( V_44 , & V_22 -> V_31 ) )
return;
V_4 = V_22 -> V_45 -> V_13 ;
F_34 ( & V_4 -> V_16 , V_31 ) ;
F_23 ( V_22 ) ;
F_35 ( & V_4 -> V_16 , V_31 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_31 ;
struct V_21 * V_22 ;
V_4 = V_2 -> V_13 ;
F_34 ( & V_4 -> V_16 , V_31 ) ;
while ( ! F_28 ( & V_4 -> V_17 ) ) {
V_22 = F_37 ( V_4 -> V_17 . V_50 ,
struct V_21 ,
V_17 ) ;
F_23 ( V_22 ) ;
}
F_35 ( & V_4 -> V_16 , V_31 ) ;
}
void F_38 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_13 )
return;
F_36 ( V_2 ) ;
F_7 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
}
static void F_39 ( struct V_21 * V_22 )
{
struct V_3 * V_4 ;
unsigned long V_31 ;
if ( ! F_17 ( V_30 , & V_22 -> V_31 ) )
return;
V_4 = V_22 -> V_45 -> V_13 ;
F_34 ( & V_4 -> V_16 , V_31 ) ;
F_24 ( & V_22 -> V_46 ) ;
if ( ! F_40 ( V_44 , & V_22 -> V_31 ) )
F_41 ( & V_22 -> V_48 ) ;
if ( ! F_28 ( & V_22 -> V_17 ) ) {
F_42 ( & V_22 -> V_17 , & V_4 -> V_17 ) ;
} else {
F_43 ( & V_22 -> V_17 , & V_4 -> V_17 ) ;
V_4 -> V_47 += 1 ;
}
F_31 ( & V_22 -> V_46 ) ;
if ( V_4 -> V_47 > V_51 ) {
struct V_21 * V_52 ;
V_52 = F_37 ( V_4 -> V_17 . V_53 ,
struct V_21 ,
V_17 ) ;
if ( V_52 != V_22 )
F_23 ( V_52 ) ;
}
F_35 ( & V_4 -> V_16 , V_31 ) ;
}
static void F_44 ( void * * V_54 , int V_55 , T_2 V_56 )
{
int V_57 = 0 ;
int V_58 = 0 ;
void * V_36 = V_54 [ V_55 ] ;
while( V_55 > 0 ) {
V_58 = F_45 ( V_55 , V_59 ) ;
F_46 ( V_58 , V_56 , V_36 , V_54 + V_57 ) ;
V_55 -= V_58 ;
V_57 += V_58 ;
}
}
static int F_47 ( struct V_21 * V_22 )
{
unsigned long V_60 = V_22 -> V_40 ;
int V_25 = 1 ;
if ( V_60 != V_22 -> V_61 * V_22 -> V_62 )
V_25 = 0 ;
F_30 ( V_60 > V_22 -> V_61 * V_22 -> V_62 ) ;
return V_25 ;
}
static int F_48 ( struct V_21 * V_22 )
{
unsigned long V_31 ;
int V_25 ;
F_34 ( & V_22 -> V_46 , V_31 ) ;
V_25 = F_47 ( V_22 ) ;
F_35 ( & V_22 -> V_46 , V_31 ) ;
return V_25 ;
}
static int F_49 ( struct V_21 * V_63 ,
struct V_21 * V_7 )
{
if ( F_17 ( V_64 , & V_63 -> V_31 ) ||
F_17 ( V_64 , & V_7 -> V_31 ) )
return 0 ;
if ( F_17 ( V_44 , & V_63 -> V_31 ) ||
F_17 ( V_44 , & V_7 -> V_31 ) )
return 0 ;
if ( V_63 -> V_33 -> V_34 [ 0 ] !=
V_7 -> V_33 -> V_34 [ 0 ] )
return 0 ;
if ( V_63 -> V_65 != V_7 -> V_65 )
return 0 ;
if ( V_63 -> V_65 == V_66 ||
V_7 -> V_65 == V_66 )
return 0 ;
if ( V_63 -> V_65 == V_67 ||
V_7 -> V_65 == V_67 )
return 0 ;
return 1 ;
}
static int F_50 ( struct V_21 * V_22 , int V_68 ,
int V_69 )
{
return V_68 * V_22 -> V_70 + V_69 ;
}
static struct V_37 * F_51 ( struct V_21 * V_22 , int V_68 ,
int V_69 )
{
return V_22 -> V_28 [ F_50 ( V_22 , V_68 , V_69 ) ] ;
}
static struct V_37 * F_52 ( struct V_21 * V_22 , int V_69 )
{
return F_51 ( V_22 , V_22 -> V_61 , V_69 ) ;
}
static struct V_37 * F_53 ( struct V_21 * V_22 , int V_69 )
{
if ( V_22 -> V_61 + 1 == V_22 -> V_71 )
return NULL ;
return F_51 ( V_22 , V_22 -> V_61 + 1 , V_69 ) ;
}
static T_3 int F_54 ( struct V_21 * V_22 )
{
int V_42 = F_14 ( V_22 ) ;
struct V_6 * V_8 = V_22 -> V_45 -> V_13 -> V_4 + V_42 ;
struct V_21 * V_7 ;
struct V_21 * V_72 ;
unsigned long V_31 ;
F_55 ( V_20 ) ;
struct V_21 * V_43 = NULL ;
struct V_21 * V_73 = NULL ;
int V_25 = 0 ;
F_34 ( & V_8 -> V_19 , V_31 ) ;
F_56 (cur, &h->hash_list, hash_list) {
if ( V_7 -> V_33 -> V_34 [ 0 ] == V_22 -> V_33 -> V_34 [ 0 ] ) {
F_24 ( & V_7 -> V_46 ) ;
if ( F_27 ( & V_7 -> V_39 ) &&
F_28 ( & V_7 -> V_49 ) &&
F_17 ( V_44 , & V_7 -> V_31 ) &&
! F_17 ( V_64 , & V_7 -> V_31 ) ) {
F_26 ( & V_7 -> V_18 ) ;
F_29 ( & V_7 -> V_48 ) ;
F_16 ( V_7 , V_22 ) ;
V_73 = V_7 ;
F_31 ( & V_7 -> V_46 ) ;
goto V_74;
}
if ( F_49 ( V_7 , V_22 ) ) {
F_20 ( V_7 , V_22 ) ;
F_31 ( & V_7 -> V_46 ) ;
V_43 = V_22 ;
V_25 = 1 ;
goto V_75;
}
F_56 (pending, &cur->plug_list,
plug_list) {
if ( F_49 ( V_72 , V_22 ) ) {
F_20 ( V_72 , V_22 ) ;
F_31 ( & V_7 -> V_46 ) ;
V_43 = V_22 ;
V_25 = 1 ;
goto V_75;
}
}
F_57 ( & V_22 -> V_49 , & V_7 -> V_49 ) ;
F_31 ( & V_7 -> V_46 ) ;
V_25 = 1 ;
goto V_75;
}
}
V_74:
F_41 ( & V_22 -> V_48 ) ;
F_43 ( & V_22 -> V_18 , & V_8 -> V_18 ) ;
V_75:
F_35 ( & V_8 -> V_19 , V_31 ) ;
if ( V_73 )
F_33 ( V_73 ) ;
if ( V_43 )
F_32 ( V_43 ) ;
return V_25 ;
}
static T_3 void F_58 ( struct V_21 * V_22 )
{
int V_42 ;
struct V_6 * V_8 ;
unsigned long V_31 ;
int V_76 = 0 ;
V_42 = F_14 ( V_22 ) ;
V_8 = V_22 -> V_45 -> V_13 -> V_4 + V_42 ;
if ( F_28 ( & V_22 -> V_49 ) )
F_39 ( V_22 ) ;
F_34 ( & V_8 -> V_19 , V_31 ) ;
F_24 ( & V_22 -> V_46 ) ;
if ( ! F_28 ( & V_22 -> V_18 ) ) {
if ( F_28 ( & V_22 -> V_49 ) &&
F_17 ( V_44 , & V_22 -> V_31 ) ) {
V_76 = 1 ;
F_59 ( V_64 , & V_22 -> V_31 ) ;
F_30 ( ! F_27 ( & V_22 -> V_39 ) ) ;
goto V_77;
}
F_26 ( & V_22 -> V_18 ) ;
F_29 ( & V_22 -> V_48 ) ;
if ( ! F_28 ( & V_22 -> V_49 ) ) {
struct V_21 * V_50 ;
struct V_78 * V_79 = V_22 -> V_49 . V_50 ;
V_50 = F_37 ( V_79 , struct V_21 ,
V_49 ) ;
F_26 ( & V_22 -> V_49 ) ;
F_43 ( & V_50 -> V_18 , & V_8 -> V_18 ) ;
F_41 ( & V_50 -> V_48 ) ;
F_31 ( & V_22 -> V_46 ) ;
F_35 ( & V_8 -> V_19 , V_31 ) ;
if ( V_50 -> V_65 == V_80 )
F_60 ( V_50 ) ;
else if ( V_50 -> V_65 == V_67 ) {
F_16 ( V_22 , V_50 ) ;
F_60 ( V_50 ) ;
} else if ( V_50 -> V_65 == V_81 ) {
F_16 ( V_22 , V_50 ) ;
F_61 ( V_50 ) ;
} else if ( V_50 -> V_65 == V_66 ) {
F_16 ( V_22 , V_50 ) ;
F_62 ( V_50 ) ;
}
goto V_82;
} else if ( F_63 ( & V_8 -> V_20 ) ) {
F_31 ( & V_22 -> V_46 ) ;
F_35 ( & V_8 -> V_19 , V_31 ) ;
F_64 ( & V_8 -> V_20 ) ;
goto V_82;
}
}
V_77:
F_31 ( & V_22 -> V_46 ) ;
F_35 ( & V_8 -> V_19 , V_31 ) ;
V_82:
if ( ! V_76 )
F_33 ( V_22 ) ;
}
static void F_32 ( struct V_21 * V_22 )
{
int V_11 ;
if ( ! F_65 ( & V_22 -> V_48 ) )
return;
F_66 ( ! F_28 ( & V_22 -> V_17 ) ) ;
F_66 ( ! F_28 ( & V_22 -> V_18 ) ) ;
F_66 ( ! F_27 ( & V_22 -> V_39 ) ) ;
for ( V_11 = 0 ; V_11 < V_22 -> V_26 ; V_11 ++ ) {
if ( V_22 -> V_28 [ V_11 ] ) {
F_19 ( V_22 -> V_28 [ V_11 ] ) ;
V_22 -> V_28 [ V_11 ] = NULL ;
}
}
F_67 ( V_22 -> V_33 ) ;
F_68 ( V_22 ) ;
}
static void F_69 ( struct V_21 * V_22 )
{
F_58 ( V_22 ) ;
F_32 ( V_22 ) ;
}
static void F_70 ( struct V_21 * V_22 , T_4 V_83 )
{
struct V_84 * V_7 = F_71 ( & V_22 -> V_39 ) ;
struct V_84 * V_50 ;
if ( V_22 -> V_41 )
F_72 ( V_22 -> V_45 , V_22 -> V_41 ) ;
F_69 ( V_22 ) ;
while ( V_7 ) {
V_50 = V_7 -> V_85 ;
V_7 -> V_85 = NULL ;
V_7 -> V_86 = V_83 ;
F_73 ( V_7 ) ;
V_7 = V_50 ;
}
}
static void F_74 ( struct V_84 * V_84 )
{
struct V_21 * V_22 = V_84 -> V_87 ;
T_4 V_83 = V_84 -> V_86 ;
int V_88 ;
if ( V_83 )
F_75 ( V_22 , V_84 ) ;
F_76 ( V_84 ) ;
if ( ! F_77 ( & V_22 -> V_89 ) )
return;
V_83 = V_90 ;
V_88 = ( V_22 -> V_65 == V_66 ) ?
0 : V_22 -> V_33 -> V_88 ;
if ( F_78 ( & V_22 -> error ) > V_88 )
V_83 = V_91 ;
F_70 ( V_22 , V_83 ) ;
}
static struct V_37 * F_79 ( struct V_21 * V_22 ,
int V_69 , int V_92 , int V_93 )
{
int V_94 ;
struct V_37 * V_95 = NULL ;
V_94 = V_69 * ( V_22 -> V_62 >> V_96 ) + V_92 ;
F_80 ( & V_22 -> V_46 ) ;
V_95 = V_22 -> V_27 [ V_94 ] ;
F_81 ( & V_22 -> V_46 ) ;
if ( V_95 || V_93 )
return V_95 ;
return V_22 -> V_28 [ V_94 ] ;
}
static unsigned long F_82 ( unsigned long V_62 , int V_97 )
{
return F_83 ( V_62 , V_29 ) * V_97 ;
}
static struct V_21 * F_84 ( struct V_1 * V_45 ,
struct V_98 * V_33 ,
T_1 V_62 )
{
struct V_21 * V_22 ;
int V_61 = 0 ;
int V_71 = V_33 -> V_99 - V_33 -> V_100 ;
int V_101 = F_82 ( V_62 , V_71 ) ;
int V_70 = F_83 ( V_62 , V_29 ) ;
void * V_95 ;
V_22 = F_85 ( sizeof( * V_22 ) + V_101 * sizeof( struct V_37 * ) * 2 +
F_83 ( V_70 , V_102 ) *
sizeof( long ) , V_103 ) ;
if ( ! V_22 )
return F_86 ( - V_15 ) ;
F_22 ( & V_22 -> V_39 ) ;
F_4 ( & V_22 -> V_49 ) ;
F_3 ( & V_22 -> V_46 ) ;
F_4 ( & V_22 -> V_17 ) ;
F_4 ( & V_22 -> V_18 ) ;
V_22 -> V_33 = V_33 ;
V_22 -> V_45 = V_45 ;
V_22 -> V_62 = V_62 ;
V_22 -> V_26 = V_101 ;
V_22 -> V_71 = V_71 ;
V_22 -> V_70 = V_70 ;
V_22 -> V_104 = - 1 ;
V_22 -> V_105 = - 1 ;
F_87 ( & V_22 -> V_48 , 1 ) ;
F_88 ( & V_22 -> error , 0 ) ;
F_88 ( & V_22 -> V_89 , 0 ) ;
V_95 = V_22 + 1 ;
V_22 -> V_28 = V_95 ;
V_22 -> V_27 = V_95 + sizeof( struct V_37 * ) * V_101 ;
V_22 -> V_106 = V_95 + sizeof( struct V_37 * ) * V_101 * 2 ;
if ( V_33 -> V_107 & V_108 )
V_61 = V_71 - 1 ;
else if ( V_33 -> V_107 & V_109 )
V_61 = V_71 - 2 ;
else
F_89 () ;
V_22 -> V_61 = V_61 ;
return V_22 ;
}
static int F_9 ( struct V_21 * V_22 )
{
int V_11 ;
struct V_37 * V_37 ;
for ( V_11 = 0 ; V_11 < V_22 -> V_26 ; V_11 ++ ) {
if ( V_22 -> V_28 [ V_11 ] )
continue;
V_37 = F_90 ( V_103 | V_110 ) ;
if ( ! V_37 )
return - V_15 ;
V_22 -> V_28 [ V_11 ] = V_37 ;
}
return 0 ;
}
static int F_91 ( struct V_21 * V_22 )
{
int V_11 ;
struct V_37 * V_37 ;
V_11 = F_50 ( V_22 , V_22 -> V_61 , 0 ) ;
for (; V_11 < V_22 -> V_26 ; V_11 ++ ) {
if ( V_22 -> V_28 [ V_11 ] )
continue;
V_37 = F_90 ( V_103 | V_110 ) ;
if ( ! V_37 )
return - V_15 ;
V_22 -> V_28 [ V_11 ] = V_37 ;
}
return 0 ;
}
static int F_92 ( struct V_21 * V_22 ,
struct V_39 * V_39 ,
struct V_37 * V_37 ,
int V_111 ,
unsigned long V_112 ,
unsigned long V_113 )
{
struct V_84 * V_63 = V_39 -> V_114 ;
T_1 V_115 = 0 ;
int V_25 ;
struct V_84 * V_84 ;
struct V_116 * V_68 ;
T_1 V_117 ;
V_68 = & V_22 -> V_33 -> V_118 [ V_111 ] ;
V_117 = V_68 -> V_119 + ( V_112 << V_96 ) ;
if ( ! V_68 -> V_120 -> V_121 )
return F_93 ( V_22 , V_111 ) ;
if ( V_63 ) {
V_115 = ( T_1 ) V_63 -> V_122 . V_123 << 9 ;
V_115 += V_63 -> V_122 . V_124 ;
if ( V_115 == V_117 && V_68 -> V_120 -> V_121 &&
! V_63 -> V_86 &&
V_63 -> V_125 == V_68 -> V_120 -> V_121 -> V_126 &&
V_63 -> V_127 == V_68 -> V_120 -> V_121 -> V_128 ) {
V_25 = F_94 ( V_63 , V_37 , V_29 , 0 ) ;
if ( V_25 == V_29 )
return 0 ;
}
}
V_84 = F_95 ( V_113 >> V_96 ? : 1 ) ;
V_84 -> V_122 . V_124 = 0 ;
F_96 ( V_84 , V_68 -> V_120 -> V_121 ) ;
V_84 -> V_122 . V_123 = V_117 >> 9 ;
F_94 ( V_84 , V_37 , V_29 , 0 ) ;
F_97 ( V_39 , V_84 ) ;
return 0 ;
}
static void F_98 ( struct V_21 * V_22 )
{
if ( V_22 -> V_104 >= 0 || V_22 -> V_105 >= 0 ) {
F_30 ( V_22 -> V_104 == V_22 -> V_71 - 1 ) ;
F_99 ( V_22 ) ;
} else {
F_100 ( V_22 ) ;
}
}
static void F_101 ( struct V_21 * V_22 )
{
struct V_84 * V_84 ;
T_1 V_129 ;
unsigned long V_130 ;
unsigned long V_112 ;
F_80 ( & V_22 -> V_46 ) ;
F_102 (bio, &rbio->bio_list) {
struct V_131 V_132 ;
struct V_133 V_134 ;
int V_11 = 0 ;
V_129 = ( T_1 ) V_84 -> V_122 . V_123 << 9 ;
V_130 = V_129 - V_22 -> V_33 -> V_34 [ 0 ] ;
V_112 = V_130 >> V_96 ;
if ( F_103 ( V_84 , V_135 ) )
V_84 -> V_122 = F_104 ( V_84 ) -> V_134 ;
F_105 (bvec, bio, iter) {
V_22 -> V_27 [ V_112 + V_11 ] = V_132 . V_136 ;
V_11 ++ ;
}
}
F_81 ( & V_22 -> V_46 ) ;
}
static T_3 void F_100 ( struct V_21 * V_22 )
{
struct V_98 * V_33 = V_22 -> V_33 ;
void * V_137 [ V_22 -> V_71 ] ;
int V_61 = V_22 -> V_61 ;
int V_68 ;
int V_92 ;
int V_138 = - 1 ;
int V_139 = - 1 ;
struct V_39 V_39 ;
struct V_84 * V_84 ;
int V_25 ;
F_22 ( & V_39 ) ;
if ( V_22 -> V_71 - V_22 -> V_61 == 1 ) {
V_138 = V_22 -> V_71 - 1 ;
} else if ( V_22 -> V_71 - V_22 -> V_61 == 2 ) {
V_138 = V_22 -> V_71 - 2 ;
V_139 = V_22 -> V_71 - 1 ;
} else {
F_89 () ;
}
F_80 ( & V_22 -> V_46 ) ;
F_13 ( V_64 , & V_22 -> V_31 ) ;
F_81 ( & V_22 -> V_46 ) ;
F_88 ( & V_22 -> error , 0 ) ;
F_101 ( V_22 ) ;
if ( ! F_48 ( V_22 ) )
F_8 ( V_22 ) ;
else
F_59 ( V_30 , & V_22 -> V_31 ) ;
for ( V_92 = 0 ; V_92 < V_22 -> V_70 ; V_92 ++ ) {
struct V_37 * V_95 ;
for ( V_68 = 0 ; V_68 < V_61 ; V_68 ++ ) {
V_95 = F_79 ( V_22 , V_68 , V_92 , 0 ) ;
V_137 [ V_68 ] = F_10 ( V_95 ) ;
}
V_95 = F_52 ( V_22 , V_92 ) ;
F_12 ( V_95 ) ;
V_137 [ V_68 ++ ] = F_10 ( V_95 ) ;
if ( V_139 != - 1 ) {
V_95 = F_53 ( V_22 , V_92 ) ;
F_12 ( V_95 ) ;
V_137 [ V_68 ++ ] = F_10 ( V_95 ) ;
V_140 . V_141 ( V_22 -> V_71 , V_29 ,
V_137 ) ;
} else {
memcpy ( V_137 [ V_61 ] , V_137 [ 0 ] , V_29 ) ;
F_44 ( V_137 + 1 , V_61 - 1 , V_29 ) ;
}
for ( V_68 = 0 ; V_68 < V_22 -> V_71 ; V_68 ++ )
F_11 ( F_79 ( V_22 , V_68 , V_92 , 0 ) ) ;
}
for ( V_68 = 0 ; V_68 < V_22 -> V_71 ; V_68 ++ ) {
for ( V_92 = 0 ; V_92 < V_22 -> V_70 ; V_92 ++ ) {
struct V_37 * V_37 ;
if ( V_68 < V_22 -> V_61 ) {
V_37 = F_79 ( V_22 , V_68 , V_92 , 1 ) ;
if ( ! V_37 )
continue;
} else {
V_37 = F_51 ( V_22 , V_68 , V_92 ) ;
}
V_25 = F_92 ( V_22 , & V_39 ,
V_37 , V_68 , V_92 , V_22 -> V_62 ) ;
if ( V_25 )
goto V_142;
}
}
if ( F_106 ( ! V_33 -> V_100 ) )
goto V_143;
for ( V_68 = 0 ; V_68 < V_22 -> V_71 ; V_68 ++ ) {
if ( ! V_33 -> V_144 [ V_68 ] )
continue;
for ( V_92 = 0 ; V_92 < V_22 -> V_70 ; V_92 ++ ) {
struct V_37 * V_37 ;
if ( V_68 < V_22 -> V_61 ) {
V_37 = F_79 ( V_22 , V_68 , V_92 , 1 ) ;
if ( ! V_37 )
continue;
} else {
V_37 = F_51 ( V_22 , V_68 , V_92 ) ;
}
V_25 = F_92 ( V_22 , & V_39 , V_37 ,
V_22 -> V_33 -> V_144 [ V_68 ] ,
V_92 , V_22 -> V_62 ) ;
if ( V_25 )
goto V_142;
}
}
V_143:
F_88 ( & V_22 -> V_89 , F_107 ( & V_39 ) ) ;
F_30 ( F_78 ( & V_22 -> V_89 ) == 0 ) ;
while ( 1 ) {
V_84 = F_108 ( & V_39 ) ;
if ( ! V_84 )
break;
V_84 -> V_87 = V_22 ;
V_84 -> V_145 = F_74 ;
F_109 ( V_84 , V_146 , 0 ) ;
F_110 ( V_84 ) ;
}
return;
V_142:
F_70 ( V_22 , V_91 ) ;
}
static int F_111 ( struct V_21 * V_22 ,
struct V_84 * V_84 )
{
T_1 V_119 = V_84 -> V_122 . V_123 ;
T_1 V_147 ;
int V_11 ;
struct V_116 * V_68 ;
V_119 <<= 9 ;
for ( V_11 = 0 ; V_11 < V_22 -> V_33 -> V_99 ; V_11 ++ ) {
V_68 = & V_22 -> V_33 -> V_118 [ V_11 ] ;
V_147 = V_68 -> V_119 ;
if ( V_119 >= V_147 &&
V_119 < V_147 + V_22 -> V_62 &&
V_84 -> V_125 == V_68 -> V_120 -> V_121 -> V_126 &&
V_84 -> V_127 == V_68 -> V_120 -> V_121 -> V_128 ) {
return V_11 ;
}
}
return - 1 ;
}
static int F_112 ( struct V_21 * V_22 ,
struct V_84 * V_84 )
{
T_1 V_148 = V_84 -> V_122 . V_123 ;
T_1 V_147 ;
int V_11 ;
V_148 <<= 9 ;
for ( V_11 = 0 ; V_11 < V_22 -> V_61 ; V_11 ++ ) {
V_147 = V_22 -> V_33 -> V_34 [ V_11 ] ;
if ( V_148 >= V_147 &&
V_148 < V_147 + V_22 -> V_62 ) {
return V_11 ;
}
}
return - 1 ;
}
static int F_93 ( struct V_21 * V_22 , int V_149 )
{
unsigned long V_31 ;
int V_25 = 0 ;
F_34 ( & V_22 -> V_46 , V_31 ) ;
if ( V_22 -> V_104 == V_149 || V_22 -> V_105 == V_149 )
goto V_75;
if ( V_22 -> V_104 == - 1 ) {
V_22 -> V_104 = V_149 ;
F_113 ( & V_22 -> error ) ;
} else if ( V_22 -> V_105 == - 1 ) {
V_22 -> V_105 = V_149 ;
F_113 ( & V_22 -> error ) ;
} else {
V_25 = - V_150 ;
}
V_75:
F_35 ( & V_22 -> V_46 , V_31 ) ;
return V_25 ;
}
static int F_75 ( struct V_21 * V_22 ,
struct V_84 * V_84 )
{
int V_149 = F_111 ( V_22 , V_84 ) ;
if ( V_149 < 0 )
return - V_150 ;
return F_93 ( V_22 , V_149 ) ;
}
static void F_114 ( struct V_84 * V_84 )
{
struct V_131 V_132 ;
struct V_133 V_134 ;
if ( F_103 ( V_84 , V_135 ) )
V_84 -> V_122 = F_104 ( V_84 ) -> V_134 ;
F_105 (bvec, bio, iter)
F_12 ( V_132 . V_136 ) ;
}
static void F_115 ( struct V_84 * V_84 )
{
struct V_21 * V_22 = V_84 -> V_87 ;
if ( V_84 -> V_86 )
F_75 ( V_22 , V_84 ) ;
else
F_114 ( V_84 ) ;
F_76 ( V_84 ) ;
if ( ! F_77 ( & V_22 -> V_89 ) )
return;
if ( F_78 ( & V_22 -> error ) > V_22 -> V_33 -> V_88 )
goto V_142;
F_98 ( V_22 ) ;
return;
V_142:
F_70 ( V_22 , V_91 ) ;
}
static void F_61 ( struct V_21 * V_22 )
{
F_116 ( & V_22 -> V_151 , V_152 , V_153 , NULL , NULL ) ;
F_117 ( V_22 -> V_45 -> V_154 , & V_22 -> V_151 ) ;
}
static void F_60 ( struct V_21 * V_22 )
{
F_116 ( & V_22 -> V_151 , V_152 ,
V_155 , NULL , NULL ) ;
F_117 ( V_22 -> V_45 -> V_154 , & V_22 -> V_151 ) ;
}
static int F_118 ( struct V_21 * V_22 )
{
int V_156 = 0 ;
struct V_39 V_39 ;
int V_25 ;
int V_92 ;
int V_68 ;
struct V_84 * V_84 ;
F_22 ( & V_39 ) ;
V_25 = F_9 ( V_22 ) ;
if ( V_25 )
goto V_142;
F_101 ( V_22 ) ;
F_88 ( & V_22 -> error , 0 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_61 ; V_68 ++ ) {
for ( V_92 = 0 ; V_92 < V_22 -> V_70 ; V_92 ++ ) {
struct V_37 * V_37 ;
V_37 = F_79 ( V_22 , V_68 , V_92 , 1 ) ;
if ( V_37 )
continue;
V_37 = F_51 ( V_22 , V_68 , V_92 ) ;
if ( F_18 ( V_37 ) )
continue;
V_25 = F_92 ( V_22 , & V_39 , V_37 ,
V_68 , V_92 , V_22 -> V_62 ) ;
if ( V_25 )
goto V_142;
}
}
V_156 = F_107 ( & V_39 ) ;
if ( ! V_156 ) {
goto V_157;
}
F_88 ( & V_22 -> V_89 , V_156 ) ;
while ( 1 ) {
V_84 = F_108 ( & V_39 ) ;
if ( ! V_84 )
break;
V_84 -> V_87 = V_22 ;
V_84 -> V_145 = F_115 ;
F_109 ( V_84 , V_158 , 0 ) ;
F_119 ( V_22 -> V_45 , V_84 , V_159 ) ;
F_110 ( V_84 ) ;
}
return 0 ;
V_142:
F_70 ( V_22 , V_91 ) ;
return - V_150 ;
V_157:
F_98 ( V_22 ) ;
return 0 ;
}
static int F_120 ( struct V_21 * V_22 )
{
int V_25 ;
V_25 = F_91 ( V_22 ) ;
if ( V_25 ) {
F_32 ( V_22 ) ;
return V_25 ;
}
V_25 = F_54 ( V_22 ) ;
if ( V_25 == 0 )
F_100 ( V_22 ) ;
return 0 ;
}
static int F_121 ( struct V_21 * V_22 )
{
int V_25 ;
V_25 = F_54 ( V_22 ) ;
if ( V_25 == 0 )
F_61 ( V_22 ) ;
return 0 ;
}
static int F_122 ( struct V_21 * V_22 )
{
if ( ! F_48 ( V_22 ) )
return F_121 ( V_22 ) ;
return F_120 ( V_22 ) ;
}
static int F_123 ( void * V_160 , struct V_78 * V_161 , struct V_78 * V_162 )
{
struct V_21 * V_163 = F_124 ( V_161 , struct V_21 ,
V_49 ) ;
struct V_21 * V_164 = F_124 ( V_162 , struct V_21 ,
V_49 ) ;
T_1 V_165 = V_163 -> V_39 . V_79 -> V_122 . V_123 ;
T_1 V_166 = V_164 -> V_39 . V_79 -> V_122 . V_123 ;
if ( V_165 < V_166 )
return - 1 ;
if ( V_165 > V_166 )
return 1 ;
return 0 ;
}
static void F_125 ( struct V_167 * V_168 )
{
struct V_21 * V_7 ;
struct V_21 * V_63 = NULL ;
F_126 ( NULL , & V_168 -> V_169 , F_123 ) ;
while ( ! F_28 ( & V_168 -> V_169 ) ) {
V_7 = F_37 ( V_168 -> V_169 . V_50 ,
struct V_21 , V_49 ) ;
F_26 ( & V_7 -> V_49 ) ;
if ( F_48 ( V_7 ) ) {
F_120 ( V_7 ) ;
continue;
}
if ( V_63 ) {
if ( F_49 ( V_63 , V_7 ) ) {
F_20 ( V_63 , V_7 ) ;
F_32 ( V_7 ) ;
continue;
}
F_122 ( V_63 ) ;
}
V_63 = V_7 ;
}
if ( V_63 ) {
F_122 ( V_63 ) ;
}
F_68 ( V_168 ) ;
}
static void F_127 ( struct V_170 * V_151 )
{
struct V_167 * V_168 ;
V_168 = F_124 ( V_151 , struct V_167 , V_151 ) ;
F_125 ( V_168 ) ;
}
static void F_128 ( struct V_171 * V_172 , bool V_173 )
{
struct V_167 * V_168 ;
V_168 = F_124 ( V_172 , struct V_167 , V_172 ) ;
if ( V_173 ) {
F_116 ( & V_168 -> V_151 , V_152 ,
F_127 , NULL , NULL ) ;
F_117 ( V_168 -> V_2 -> V_154 ,
& V_168 -> V_151 ) ;
return;
}
F_125 ( V_168 ) ;
}
int F_129 ( struct V_1 * V_45 , struct V_84 * V_84 ,
struct V_98 * V_33 , T_1 V_62 )
{
struct V_21 * V_22 ;
struct V_167 * V_168 = NULL ;
struct V_171 * V_172 ;
int V_25 ;
V_22 = F_84 ( V_45 , V_33 , V_62 ) ;
if ( F_130 ( V_22 ) ) {
F_67 ( V_33 ) ;
return F_131 ( V_22 ) ;
}
F_97 ( & V_22 -> V_39 , V_84 ) ;
V_22 -> V_40 = V_84 -> V_122 . V_124 ;
V_22 -> V_65 = V_81 ;
F_132 ( V_45 ) ;
V_22 -> V_41 = 1 ;
if ( F_48 ( V_22 ) ) {
V_25 = F_120 ( V_22 ) ;
if ( V_25 )
F_133 ( V_45 ) ;
return V_25 ;
}
V_172 = F_134 ( F_128 , V_45 , sizeof( * V_168 ) ) ;
if ( V_172 ) {
V_168 = F_124 ( V_172 , struct V_167 , V_172 ) ;
if ( ! V_168 -> V_2 ) {
V_168 -> V_2 = V_45 ;
F_4 ( & V_168 -> V_169 ) ;
}
F_57 ( & V_22 -> V_49 , & V_168 -> V_169 ) ;
V_25 = 0 ;
} else {
V_25 = F_122 ( V_22 ) ;
if ( V_25 )
F_133 ( V_45 ) ;
}
return V_25 ;
}
static void F_135 ( struct V_21 * V_22 )
{
int V_92 , V_68 ;
void * * V_137 ;
int V_104 = - 1 , V_105 = - 1 ;
struct V_37 * V_37 ;
T_4 V_83 ;
int V_11 ;
V_137 = F_136 ( V_22 -> V_71 , sizeof( void * ) , V_103 ) ;
if ( ! V_137 ) {
V_83 = V_174 ;
goto V_175;
}
V_104 = V_22 -> V_104 ;
V_105 = V_22 -> V_105 ;
if ( V_22 -> V_65 == V_80 ||
V_22 -> V_65 == V_67 ) {
F_80 ( & V_22 -> V_46 ) ;
F_13 ( V_64 , & V_22 -> V_31 ) ;
F_81 ( & V_22 -> V_46 ) ;
}
F_101 ( V_22 ) ;
for ( V_92 = 0 ; V_92 < V_22 -> V_70 ; V_92 ++ ) {
if ( V_22 -> V_65 == V_66 &&
! F_17 ( V_92 , V_22 -> V_106 ) )
continue;
for ( V_68 = 0 ; V_68 < V_22 -> V_71 ; V_68 ++ ) {
if ( ( V_22 -> V_65 == V_80 ||
V_22 -> V_65 == V_67 ) &&
( V_68 == V_104 || V_68 == V_105 ) ) {
V_37 = F_79 ( V_22 , V_68 , V_92 , 0 ) ;
} else {
V_37 = F_51 ( V_22 , V_68 , V_92 ) ;
}
V_137 [ V_68 ] = F_10 ( V_37 ) ;
}
if ( V_22 -> V_33 -> V_107 & V_109 ) {
if ( V_105 < 0 ) {
if ( V_104 == V_22 -> V_61 ) {
V_83 = V_91 ;
goto V_142;
}
goto V_176;
}
if ( V_104 > V_105 ) {
int V_177 = V_105 ;
V_105 = V_104 ;
V_104 = V_177 ;
}
if ( V_22 -> V_33 -> V_34 [ V_105 ] == V_178 ) {
if ( V_22 -> V_33 -> V_34 [ V_104 ] ==
V_179 ) {
V_83 = V_91 ;
goto V_142;
}
goto V_176;
}
if ( V_22 -> V_33 -> V_34 [ V_105 ] == V_179 ) {
F_137 ( V_22 -> V_71 ,
V_29 , V_104 , V_137 ) ;
} else {
F_138 ( V_22 -> V_71 ,
V_29 , V_104 , V_105 ,
V_137 ) ;
}
} else {
void * V_95 ;
F_30 ( V_105 != - 1 ) ;
V_176:
memcpy ( V_137 [ V_104 ] ,
V_137 [ V_22 -> V_61 ] ,
V_29 ) ;
V_95 = V_137 [ V_104 ] ;
for ( V_68 = V_104 ; V_68 < V_22 -> V_61 - 1 ; V_68 ++ )
V_137 [ V_68 ] = V_137 [ V_68 + 1 ] ;
V_137 [ V_22 -> V_61 - 1 ] = V_95 ;
F_44 ( V_137 , V_22 -> V_61 - 1 , V_29 ) ;
}
if ( V_22 -> V_65 == V_81 ) {
for ( V_11 = 0 ; V_11 < V_22 -> V_70 ; V_11 ++ ) {
if ( V_104 != - 1 ) {
V_37 = F_51 ( V_22 , V_104 , V_11 ) ;
F_12 ( V_37 ) ;
}
if ( V_105 != - 1 ) {
V_37 = F_51 ( V_22 , V_105 , V_11 ) ;
F_12 ( V_37 ) ;
}
}
}
for ( V_68 = 0 ; V_68 < V_22 -> V_71 ; V_68 ++ ) {
if ( ( V_22 -> V_65 == V_80 ||
V_22 -> V_65 == V_67 ) &&
( V_68 == V_104 || V_68 == V_105 ) ) {
V_37 = F_79 ( V_22 , V_68 , V_92 , 0 ) ;
} else {
V_37 = F_51 ( V_22 , V_68 , V_92 ) ;
}
F_11 ( V_37 ) ;
}
}
V_83 = V_90 ;
V_142:
F_68 ( V_137 ) ;
V_175:
if ( V_22 -> V_65 == V_80 ) {
if ( V_83 == V_90 )
F_8 ( V_22 ) ;
else
F_59 ( V_30 , & V_22 -> V_31 ) ;
F_70 ( V_22 , V_83 ) ;
} else if ( V_22 -> V_65 == V_67 ) {
F_70 ( V_22 , V_83 ) ;
} else if ( V_83 == V_90 ) {
V_22 -> V_104 = - 1 ;
V_22 -> V_105 = - 1 ;
if ( V_22 -> V_65 == V_81 )
F_100 ( V_22 ) ;
else if ( V_22 -> V_65 == V_66 )
F_139 ( V_22 , 0 ) ;
else
F_89 () ;
} else {
F_70 ( V_22 , V_83 ) ;
}
}
static void F_140 ( struct V_84 * V_84 )
{
struct V_21 * V_22 = V_84 -> V_87 ;
if ( V_84 -> V_86 )
F_75 ( V_22 , V_84 ) ;
else
F_114 ( V_84 ) ;
F_76 ( V_84 ) ;
if ( ! F_77 ( & V_22 -> V_89 ) )
return;
if ( F_78 ( & V_22 -> error ) > V_22 -> V_33 -> V_88 )
F_70 ( V_22 , V_91 ) ;
else
F_135 ( V_22 ) ;
}
static int F_99 ( struct V_21 * V_22 )
{
int V_156 = 0 ;
struct V_39 V_39 ;
int V_25 ;
int V_92 ;
int V_68 ;
struct V_84 * V_84 ;
F_22 ( & V_39 ) ;
V_25 = F_9 ( V_22 ) ;
if ( V_25 )
goto V_142;
F_88 ( & V_22 -> error , 0 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_71 ; V_68 ++ ) {
if ( V_22 -> V_104 == V_68 || V_22 -> V_105 == V_68 ) {
F_113 ( & V_22 -> error ) ;
continue;
}
for ( V_92 = 0 ; V_92 < V_22 -> V_70 ; V_92 ++ ) {
struct V_37 * V_95 ;
V_95 = F_51 ( V_22 , V_68 , V_92 ) ;
if ( F_18 ( V_95 ) )
continue;
V_25 = F_92 ( V_22 , & V_39 ,
F_51 ( V_22 , V_68 , V_92 ) ,
V_68 , V_92 , V_22 -> V_62 ) ;
if ( V_25 < 0 )
goto V_142;
}
}
V_156 = F_107 ( & V_39 ) ;
if ( ! V_156 ) {
if ( F_78 ( & V_22 -> error ) <= V_22 -> V_33 -> V_88 ) {
F_135 ( V_22 ) ;
goto V_75;
} else {
goto V_142;
}
}
F_88 ( & V_22 -> V_89 , V_156 ) ;
while ( 1 ) {
V_84 = F_108 ( & V_39 ) ;
if ( ! V_84 )
break;
V_84 -> V_87 = V_22 ;
V_84 -> V_145 = F_140 ;
F_109 ( V_84 , V_158 , 0 ) ;
F_119 ( V_22 -> V_45 , V_84 , V_159 ) ;
F_110 ( V_84 ) ;
}
V_75:
return 0 ;
V_142:
if ( V_22 -> V_65 == V_80 ||
V_22 -> V_65 == V_67 )
F_70 ( V_22 , V_91 ) ;
return - V_150 ;
}
int F_141 ( struct V_1 * V_45 , struct V_84 * V_84 ,
struct V_98 * V_33 , T_1 V_62 ,
int V_180 , int V_181 )
{
struct V_21 * V_22 ;
int V_25 ;
if ( V_181 ) {
ASSERT ( V_33 -> V_180 == V_180 ) ;
F_104 ( V_84 ) -> V_180 = V_180 ;
}
V_22 = F_84 ( V_45 , V_33 , V_62 ) ;
if ( F_130 ( V_22 ) ) {
if ( V_181 )
F_67 ( V_33 ) ;
return F_131 ( V_22 ) ;
}
V_22 -> V_65 = V_80 ;
F_97 ( & V_22 -> V_39 , V_84 ) ;
V_22 -> V_40 = V_84 -> V_122 . V_124 ;
V_22 -> V_104 = F_112 ( V_22 , V_84 ) ;
if ( V_22 -> V_104 == - 1 ) {
F_142 ( V_45 ,
L_1 ,
V_182 , ( T_1 ) V_84 -> V_122 . V_123 << 9 ,
( T_1 ) V_84 -> V_122 . V_124 , V_33 -> V_107 ) ;
if ( V_181 )
F_67 ( V_33 ) ;
F_68 ( V_22 ) ;
return - V_150 ;
}
if ( V_181 ) {
F_132 ( V_45 ) ;
V_22 -> V_41 = 1 ;
} else {
F_143 ( V_33 ) ;
}
if ( V_180 == 3 )
V_22 -> V_105 = V_22 -> V_71 - 2 ;
V_25 = F_54 ( V_22 ) ;
if ( V_25 == 0 )
F_99 ( V_22 ) ;
return 0 ;
}
static void V_153 ( struct V_170 * V_151 )
{
struct V_21 * V_22 ;
V_22 = F_124 ( V_151 , struct V_21 , V_151 ) ;
F_118 ( V_22 ) ;
}
static void V_155 ( struct V_170 * V_151 )
{
struct V_21 * V_22 ;
V_22 = F_124 ( V_151 , struct V_21 , V_151 ) ;
F_99 ( V_22 ) ;
}
struct V_21 *
F_144 ( struct V_1 * V_45 , struct V_84 * V_84 ,
struct V_98 * V_33 , T_1 V_62 ,
struct V_183 * V_184 ,
unsigned long * V_106 , int V_185 )
{
struct V_21 * V_22 ;
int V_11 ;
V_22 = F_84 ( V_45 , V_33 , V_62 ) ;
if ( F_130 ( V_22 ) )
return NULL ;
F_97 ( & V_22 -> V_39 , V_84 ) ;
ASSERT ( ! V_84 -> V_122 . V_124 ) ;
V_22 -> V_65 = V_66 ;
for ( V_11 = 0 ; V_11 < V_22 -> V_71 ; V_11 ++ ) {
if ( V_33 -> V_118 [ V_11 ] . V_120 == V_184 ) {
V_22 -> V_186 = V_11 ;
break;
}
}
ASSERT ( V_45 -> V_187 == V_29 ) ;
ASSERT ( V_22 -> V_70 == V_185 ) ;
F_145 ( V_22 -> V_106 , V_106 , V_185 ) ;
V_22 -> V_41 = 1 ;
return V_22 ;
}
void F_146 ( struct V_21 * V_22 , struct V_37 * V_37 ,
T_1 V_148 )
{
int V_130 ;
int V_69 ;
ASSERT ( V_148 >= V_22 -> V_33 -> V_34 [ 0 ] ) ;
ASSERT ( V_148 + V_29 <= V_22 -> V_33 -> V_34 [ 0 ] +
V_22 -> V_62 * V_22 -> V_61 ) ;
V_130 = ( int ) ( V_148 - V_22 -> V_33 -> V_34 [ 0 ] ) ;
V_69 = V_130 >> V_96 ;
V_22 -> V_27 [ V_69 ] = V_37 ;
}
static int F_147 ( struct V_21 * V_22 )
{
int V_11 ;
int V_188 ;
int V_69 ;
struct V_37 * V_37 ;
F_148 (bit, rbio->dbitmap, rbio->stripe_npages) {
for ( V_11 = 0 ; V_11 < V_22 -> V_71 ; V_11 ++ ) {
V_69 = V_11 * V_22 -> V_70 + V_188 ;
if ( V_22 -> V_28 [ V_69 ] )
continue;
V_37 = F_90 ( V_103 | V_110 ) ;
if ( ! V_37 )
return - V_15 ;
V_22 -> V_28 [ V_69 ] = V_37 ;
}
}
return 0 ;
}
static T_3 void F_139 ( struct V_21 * V_22 ,
int V_189 )
{
struct V_98 * V_33 = V_22 -> V_33 ;
void * V_137 [ V_22 -> V_71 ] ;
F_149 ( V_190 , V_22 -> V_70 ) ;
int V_61 = V_22 -> V_61 ;
int V_68 ;
int V_92 ;
int V_138 = - 1 ;
int V_139 = - 1 ;
struct V_37 * V_191 = NULL ;
struct V_37 * V_192 = NULL ;
struct V_39 V_39 ;
struct V_84 * V_84 ;
int V_193 = 0 ;
int V_25 ;
F_22 ( & V_39 ) ;
if ( V_22 -> V_71 - V_22 -> V_61 == 1 ) {
V_138 = V_22 -> V_71 - 1 ;
} else if ( V_22 -> V_71 - V_22 -> V_61 == 2 ) {
V_138 = V_22 -> V_71 - 2 ;
V_139 = V_22 -> V_71 - 1 ;
} else {
F_89 () ;
}
if ( V_33 -> V_100 && V_33 -> V_144 [ V_22 -> V_186 ] ) {
V_193 = 1 ;
F_145 ( V_190 , V_22 -> V_106 , V_22 -> V_70 ) ;
}
F_59 ( V_30 , & V_22 -> V_31 ) ;
if ( ! V_189 )
goto V_194;
V_191 = F_90 ( V_103 | V_110 ) ;
if ( ! V_191 )
goto V_142;
F_12 ( V_191 ) ;
if ( V_139 != - 1 ) {
V_192 = F_90 ( V_103 | V_110 ) ;
if ( ! V_192 ) {
F_19 ( V_191 ) ;
goto V_142;
}
F_12 ( V_192 ) ;
}
F_88 ( & V_22 -> error , 0 ) ;
F_148 (pagenr, rbio->dbitmap, rbio->stripe_npages) {
struct V_37 * V_95 ;
void * V_195 ;
for ( V_68 = 0 ; V_68 < V_61 ; V_68 ++ ) {
V_95 = F_79 ( V_22 , V_68 , V_92 , 0 ) ;
V_137 [ V_68 ] = F_10 ( V_95 ) ;
}
V_137 [ V_68 ++ ] = F_10 ( V_191 ) ;
if ( V_139 != - 1 ) {
V_137 [ V_68 ++ ] = F_10 ( V_192 ) ;
V_140 . V_141 ( V_22 -> V_71 , V_29 ,
V_137 ) ;
} else {
memcpy ( V_137 [ V_61 ] , V_137 [ 0 ] , V_29 ) ;
F_44 ( V_137 + 1 , V_61 - 1 , V_29 ) ;
}
V_95 = F_51 ( V_22 , V_22 -> V_186 , V_92 ) ;
V_195 = F_10 ( V_95 ) ;
if ( memcmp ( V_195 , V_137 [ V_22 -> V_186 ] , V_29 ) )
memcpy ( V_195 , V_137 [ V_22 -> V_186 ] , V_29 ) ;
else
F_150 ( V_22 -> V_106 , V_92 , 1 ) ;
F_11 ( V_95 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_71 ; V_68 ++ )
F_11 ( F_79 ( V_22 , V_68 , V_92 , 0 ) ) ;
}
F_19 ( V_191 ) ;
if ( V_192 )
F_19 ( V_192 ) ;
V_194:
F_148 (pagenr, rbio->dbitmap, rbio->stripe_npages) {
struct V_37 * V_37 ;
V_37 = F_51 ( V_22 , V_22 -> V_186 , V_92 ) ;
V_25 = F_92 ( V_22 , & V_39 ,
V_37 , V_22 -> V_186 , V_92 , V_22 -> V_62 ) ;
if ( V_25 )
goto V_142;
}
if ( ! V_193 )
goto V_196;
F_148 (pagenr, pbitmap, rbio->stripe_npages) {
struct V_37 * V_37 ;
V_37 = F_51 ( V_22 , V_22 -> V_186 , V_92 ) ;
V_25 = F_92 ( V_22 , & V_39 , V_37 ,
V_33 -> V_144 [ V_22 -> V_186 ] ,
V_92 , V_22 -> V_62 ) ;
if ( V_25 )
goto V_142;
}
V_196:
V_61 = F_107 ( & V_39 ) ;
if ( ! V_61 ) {
F_70 ( V_22 , V_90 ) ;
return;
}
F_88 ( & V_22 -> V_89 , V_61 ) ;
while ( 1 ) {
V_84 = F_108 ( & V_39 ) ;
if ( ! V_84 )
break;
V_84 -> V_87 = V_22 ;
V_84 -> V_145 = F_74 ;
F_109 ( V_84 , V_146 , 0 ) ;
F_110 ( V_84 ) ;
}
return;
V_142:
F_70 ( V_22 , V_91 ) ;
}
static inline int F_151 ( struct V_21 * V_22 , int V_68 )
{
if ( V_68 >= 0 && V_68 < V_22 -> V_61 )
return 1 ;
return 0 ;
}
static void F_152 ( struct V_21 * V_22 )
{
if ( F_78 ( & V_22 -> error ) > V_22 -> V_33 -> V_88 )
goto V_142;
if ( V_22 -> V_104 >= 0 || V_22 -> V_105 >= 0 ) {
int V_197 = 0 , V_198 = - 1 ;
if ( F_151 ( V_22 , V_22 -> V_104 ) )
V_197 ++ ;
else if ( F_153 ( V_22 -> V_104 ) )
V_198 = V_22 -> V_104 ;
if ( F_151 ( V_22 , V_22 -> V_105 ) )
V_197 ++ ;
else if ( F_153 ( V_22 -> V_105 ) )
V_198 = V_22 -> V_105 ;
if ( V_197 > V_22 -> V_33 -> V_88 - 1 )
goto V_142;
if ( V_197 == 0 ) {
F_139 ( V_22 , 0 ) ;
return;
}
if ( V_198 != V_22 -> V_186 )
goto V_142;
F_135 ( V_22 ) ;
} else {
F_139 ( V_22 , 1 ) ;
}
return;
V_142:
F_70 ( V_22 , V_91 ) ;
}
static void F_154 ( struct V_84 * V_84 )
{
struct V_21 * V_22 = V_84 -> V_87 ;
if ( V_84 -> V_86 )
F_75 ( V_22 , V_84 ) ;
else
F_114 ( V_84 ) ;
F_76 ( V_84 ) ;
if ( ! F_77 ( & V_22 -> V_89 ) )
return;
F_152 ( V_22 ) ;
}
static void F_155 ( struct V_21 * V_22 )
{
int V_156 = 0 ;
struct V_39 V_39 ;
int V_25 ;
int V_92 ;
int V_68 ;
struct V_84 * V_84 ;
V_25 = F_147 ( V_22 ) ;
if ( V_25 )
goto V_142;
F_22 ( & V_39 ) ;
F_88 ( & V_22 -> error , 0 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_71 ; V_68 ++ ) {
F_148 (pagenr, rbio->dbitmap, rbio->stripe_npages) {
struct V_37 * V_37 ;
V_37 = F_79 ( V_22 , V_68 , V_92 , 1 ) ;
if ( V_37 )
continue;
V_37 = F_51 ( V_22 , V_68 , V_92 ) ;
if ( F_18 ( V_37 ) )
continue;
V_25 = F_92 ( V_22 , & V_39 , V_37 ,
V_68 , V_92 , V_22 -> V_62 ) ;
if ( V_25 )
goto V_142;
}
}
V_156 = F_107 ( & V_39 ) ;
if ( ! V_156 ) {
goto V_157;
}
F_88 ( & V_22 -> V_89 , V_156 ) ;
while ( 1 ) {
V_84 = F_108 ( & V_39 ) ;
if ( ! V_84 )
break;
V_84 -> V_87 = V_22 ;
V_84 -> V_145 = F_154 ;
F_109 ( V_84 , V_158 , 0 ) ;
F_119 ( V_22 -> V_45 , V_84 , V_159 ) ;
F_110 ( V_84 ) ;
}
return;
V_142:
F_70 ( V_22 , V_91 ) ;
return;
V_157:
F_152 ( V_22 ) ;
}
static void F_156 ( struct V_170 * V_151 )
{
struct V_21 * V_22 ;
V_22 = F_124 ( V_151 , struct V_21 , V_151 ) ;
F_155 ( V_22 ) ;
}
static void F_62 ( struct V_21 * V_22 )
{
F_116 ( & V_22 -> V_151 , V_152 ,
F_156 , NULL , NULL ) ;
F_117 ( V_22 -> V_45 -> V_154 , & V_22 -> V_151 ) ;
}
void F_157 ( struct V_21 * V_22 )
{
if ( ! F_54 ( V_22 ) )
F_62 ( V_22 ) ;
}
struct V_21 *
F_158 ( struct V_1 * V_45 , struct V_84 * V_84 ,
struct V_98 * V_33 , T_1 V_199 )
{
struct V_21 * V_22 ;
V_22 = F_84 ( V_45 , V_33 , V_199 ) ;
if ( F_130 ( V_22 ) )
return NULL ;
V_22 -> V_65 = V_67 ;
F_97 ( & V_22 -> V_39 , V_84 ) ;
ASSERT ( ! V_84 -> V_122 . V_124 ) ;
V_22 -> V_104 = F_112 ( V_22 , V_84 ) ;
if ( V_22 -> V_104 == - 1 ) {
F_89 () ;
F_68 ( V_22 ) ;
return NULL ;
}
V_22 -> V_41 = 1 ;
return V_22 ;
}
static void F_159 ( struct V_170 * V_151 )
{
struct V_21 * V_22 ;
V_22 = F_124 ( V_151 , struct V_21 , V_151 ) ;
F_99 ( V_22 ) ;
}
static void F_160 ( struct V_21 * V_22 )
{
F_116 ( & V_22 -> V_151 , V_152 ,
F_159 , NULL , NULL ) ;
F_117 ( V_22 -> V_45 -> V_154 , & V_22 -> V_151 ) ;
}
void F_161 ( struct V_21 * V_22 )
{
if ( ! F_54 ( V_22 ) )
F_160 ( V_22 ) ;
}
