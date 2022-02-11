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
F_25 ( & V_39 -> V_40 ) ;
}
static void F_26 ( struct V_23 * V_24 )
{
int V_42 = F_17 ( V_24 ) ;
struct V_3 * V_4 ;
struct V_6 * V_8 ;
int V_43 = 0 ;
if ( ! F_20 ( V_44 , & V_24 -> V_33 ) )
return;
V_4 = V_24 -> V_45 -> V_13 ;
V_8 = V_4 -> V_4 + V_42 ;
F_27 ( & V_8 -> V_21 ) ;
F_27 ( & V_24 -> V_46 ) ;
if ( F_28 ( V_44 , & V_24 -> V_33 ) ) {
F_29 ( & V_24 -> V_19 ) ;
V_4 -> V_47 -= 1 ;
V_43 = 1 ;
if ( F_30 ( & V_24 -> V_40 ) ) {
if ( ! F_31 ( & V_24 -> V_20 ) ) {
F_29 ( & V_24 -> V_20 ) ;
F_32 ( & V_24 -> V_48 ) ;
F_33 ( ! F_31 ( & V_24 -> V_49 ) ) ;
}
}
}
F_34 ( & V_24 -> V_46 ) ;
F_34 ( & V_8 -> V_21 ) ;
if ( V_43 )
F_35 ( V_24 ) ;
}
static void F_36 ( struct V_23 * V_24 )
{
struct V_3 * V_4 ;
unsigned long V_33 ;
if ( ! F_20 ( V_44 , & V_24 -> V_33 ) )
return;
V_4 = V_24 -> V_45 -> V_13 ;
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
V_24 = F_40 ( V_4 -> V_19 . V_50 ,
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
V_4 = V_24 -> V_45 -> V_13 ;
F_37 ( & V_4 -> V_18 , V_33 ) ;
F_27 ( & V_24 -> V_46 ) ;
if ( ! F_43 ( V_44 , & V_24 -> V_33 ) )
F_44 ( & V_24 -> V_48 ) ;
if ( ! F_31 ( & V_24 -> V_19 ) ) {
F_45 ( & V_24 -> V_19 , & V_4 -> V_19 ) ;
} else {
F_46 ( & V_24 -> V_19 , & V_4 -> V_19 ) ;
V_4 -> V_47 += 1 ;
}
F_34 ( & V_24 -> V_46 ) ;
if ( V_4 -> V_47 > V_51 ) {
struct V_23 * V_52 ;
V_52 = F_40 ( V_4 -> V_19 . V_53 ,
struct V_23 ,
V_19 ) ;
if ( V_52 != V_24 )
F_26 ( V_52 ) ;
}
F_38 ( & V_4 -> V_18 , V_33 ) ;
return;
}
static void F_47 ( void * * V_54 , int V_55 , T_2 V_56 )
{
int V_57 = 0 ;
int V_58 = 0 ;
void * V_37 = V_54 [ V_55 ] ;
while( V_55 > 0 ) {
V_58 = F_48 ( V_55 , V_59 ) ;
F_49 ( V_58 , V_56 , V_37 , V_54 + V_57 ) ;
V_55 -= V_58 ;
V_57 += V_58 ;
}
}
static int F_50 ( struct V_23 * V_24 )
{
unsigned long V_60 = V_24 -> V_41 ;
int V_27 = 1 ;
if ( V_60 != V_24 -> V_61 * V_24 -> V_62 )
V_27 = 0 ;
F_33 ( V_60 > V_24 -> V_61 * V_24 -> V_62 ) ;
return V_27 ;
}
static int F_51 ( struct V_23 * V_24 )
{
unsigned long V_33 ;
int V_27 ;
F_37 ( & V_24 -> V_46 , V_33 ) ;
V_27 = F_50 ( V_24 ) ;
F_38 ( & V_24 -> V_46 , V_33 ) ;
return V_27 ;
}
static int F_52 ( struct V_23 * V_63 ,
struct V_23 * V_7 )
{
if ( F_20 ( V_64 , & V_63 -> V_33 ) ||
F_20 ( V_64 , & V_7 -> V_33 ) )
return 0 ;
if ( F_20 ( V_44 , & V_63 -> V_33 ) ||
F_20 ( V_44 , & V_7 -> V_33 ) )
return 0 ;
if ( V_63 -> V_35 [ 0 ] !=
V_7 -> V_35 [ 0 ] )
return 0 ;
if ( V_63 -> V_65 !=
V_7 -> V_65 ) {
return 0 ;
}
return 1 ;
}
static struct V_38 * F_53 ( struct V_23 * V_24 , int V_66 )
{
V_66 += ( V_24 -> V_61 * V_24 -> V_62 ) >> V_67 ;
return V_24 -> V_30 [ V_66 ] ;
}
static struct V_38 * F_54 ( struct V_23 * V_24 , int V_66 )
{
if ( V_24 -> V_61 + 1 == V_24 -> V_68 -> V_69 )
return NULL ;
V_66 += ( ( V_24 -> V_61 + 1 ) * V_24 -> V_62 ) >>
V_67 ;
return V_24 -> V_30 [ V_66 ] ;
}
static T_3 int F_55 ( struct V_23 * V_24 )
{
int V_42 = F_17 ( V_24 ) ;
struct V_6 * V_8 = V_24 -> V_45 -> V_13 -> V_4 + V_42 ;
struct V_23 * V_7 ;
struct V_23 * V_70 ;
unsigned long V_33 ;
F_56 ( V_22 ) ;
struct V_23 * V_43 = NULL ;
struct V_23 * V_71 = NULL ;
int V_27 = 0 ;
int V_72 = 0 ;
F_37 ( & V_8 -> V_21 , V_33 ) ;
F_57 (cur, &h->hash_list, hash_list) {
V_72 ++ ;
if ( V_7 -> V_35 [ 0 ] == V_24 -> V_35 [ 0 ] ) {
F_27 ( & V_7 -> V_46 ) ;
if ( F_30 ( & V_7 -> V_40 ) &&
F_31 ( & V_7 -> V_49 ) &&
F_20 ( V_44 , & V_7 -> V_33 ) &&
! F_20 ( V_64 , & V_7 -> V_33 ) ) {
F_29 ( & V_7 -> V_20 ) ;
F_32 ( & V_7 -> V_48 ) ;
F_19 ( V_7 , V_24 ) ;
V_71 = V_7 ;
F_34 ( & V_7 -> V_46 ) ;
goto V_73;
}
if ( F_52 ( V_7 , V_24 ) ) {
F_23 ( V_7 , V_24 ) ;
F_34 ( & V_7 -> V_46 ) ;
V_43 = V_24 ;
V_27 = 1 ;
goto V_74;
}
F_57 (pending, &cur->plug_list,
plug_list) {
if ( F_52 ( V_70 , V_24 ) ) {
F_23 ( V_70 , V_24 ) ;
F_34 ( & V_7 -> V_46 ) ;
V_43 = V_24 ;
V_27 = 1 ;
goto V_74;
}
}
F_58 ( & V_24 -> V_49 , & V_7 -> V_49 ) ;
F_34 ( & V_7 -> V_46 ) ;
V_27 = 1 ;
goto V_74;
}
}
V_73:
F_44 ( & V_24 -> V_48 ) ;
F_46 ( & V_24 -> V_20 , & V_8 -> V_20 ) ;
V_74:
F_38 ( & V_8 -> V_21 , V_33 ) ;
if ( V_71 )
F_36 ( V_71 ) ;
if ( V_43 )
F_35 ( V_43 ) ;
return V_27 ;
}
static T_3 void F_59 ( struct V_23 * V_24 )
{
int V_42 ;
struct V_6 * V_8 ;
unsigned long V_33 ;
int V_75 = 0 ;
V_42 = F_17 ( V_24 ) ;
V_8 = V_24 -> V_45 -> V_13 -> V_4 + V_42 ;
if ( F_31 ( & V_24 -> V_49 ) )
F_42 ( V_24 ) ;
F_37 ( & V_8 -> V_21 , V_33 ) ;
F_27 ( & V_24 -> V_46 ) ;
if ( ! F_31 ( & V_24 -> V_20 ) ) {
if ( F_31 ( & V_24 -> V_49 ) &&
F_20 ( V_44 , & V_24 -> V_33 ) ) {
V_75 = 1 ;
F_60 ( V_64 , & V_24 -> V_33 ) ;
F_33 ( ! F_30 ( & V_24 -> V_40 ) ) ;
goto V_76;
}
F_29 ( & V_24 -> V_20 ) ;
F_32 ( & V_24 -> V_48 ) ;
if ( ! F_31 ( & V_24 -> V_49 ) ) {
struct V_23 * V_50 ;
struct V_77 * V_78 = V_24 -> V_49 . V_50 ;
V_50 = F_40 ( V_78 , struct V_23 ,
V_49 ) ;
F_29 ( & V_24 -> V_49 ) ;
F_46 ( & V_50 -> V_20 , & V_8 -> V_20 ) ;
F_44 ( & V_50 -> V_48 ) ;
F_34 ( & V_24 -> V_46 ) ;
F_38 ( & V_8 -> V_21 , V_33 ) ;
if ( V_50 -> V_65 )
F_61 ( V_50 ) ;
else {
F_19 ( V_24 , V_50 ) ;
F_62 ( V_50 ) ;
}
goto V_79;
} else if ( F_63 ( & V_8 -> V_22 ) ) {
F_34 ( & V_24 -> V_46 ) ;
F_38 ( & V_8 -> V_21 , V_33 ) ;
F_64 ( & V_8 -> V_22 ) ;
goto V_79;
}
}
V_76:
F_34 ( & V_24 -> V_46 ) ;
F_38 ( & V_8 -> V_21 , V_33 ) ;
V_79:
if ( ! V_75 )
F_36 ( V_24 ) ;
}
static void F_35 ( struct V_23 * V_24 )
{
int V_11 ;
F_65 ( F_66 ( & V_24 -> V_48 ) < 0 ) ;
if ( ! F_67 ( & V_24 -> V_48 ) )
return;
F_65 ( ! F_31 ( & V_24 -> V_19 ) ) ;
F_65 ( ! F_31 ( & V_24 -> V_20 ) ) ;
F_65 ( ! F_30 ( & V_24 -> V_40 ) ) ;
for ( V_11 = 0 ; V_11 < V_24 -> V_28 ; V_11 ++ ) {
if ( V_24 -> V_30 [ V_11 ] ) {
F_22 ( V_24 -> V_30 [ V_11 ] ) ;
V_24 -> V_30 [ V_11 ] = NULL ;
}
}
F_10 ( V_24 -> V_35 ) ;
F_10 ( V_24 -> V_68 ) ;
F_10 ( V_24 ) ;
}
static void F_68 ( struct V_23 * V_24 )
{
F_59 ( V_24 ) ;
F_35 ( V_24 ) ;
}
static void F_69 ( struct V_23 * V_24 , int V_80 , int V_81 )
{
struct V_82 * V_7 = F_70 ( & V_24 -> V_40 ) ;
struct V_82 * V_50 ;
F_68 ( V_24 ) ;
while ( V_7 ) {
V_50 = V_7 -> V_83 ;
V_7 -> V_83 = NULL ;
if ( V_81 )
F_16 ( V_84 , & V_7 -> V_85 ) ;
F_71 ( V_7 , V_80 ) ;
V_7 = V_50 ;
}
}
static void F_72 ( struct V_82 * V_82 , int V_80 )
{
struct V_23 * V_24 = V_82 -> V_86 ;
if ( V_80 )
F_73 ( V_24 , V_82 ) ;
F_74 ( V_82 ) ;
if ( ! F_67 ( & V_24 -> V_68 -> V_87 ) )
return;
V_80 = 0 ;
if ( F_66 ( & V_24 -> V_68 -> error ) > V_24 -> V_68 -> V_88 )
V_80 = - V_89 ;
F_69 ( V_24 , V_80 , 0 ) ;
return;
}
static struct V_38 * F_75 ( struct V_23 * V_24 ,
int V_66 , int V_90 , int V_91 )
{
int V_92 ;
struct V_38 * V_93 = NULL ;
V_92 = V_66 * ( V_24 -> V_62 >> V_94 ) + V_90 ;
F_76 ( & V_24 -> V_46 ) ;
V_93 = V_24 -> V_29 [ V_92 ] ;
F_77 ( & V_24 -> V_46 ) ;
if ( V_93 || V_91 )
return V_93 ;
return V_24 -> V_30 [ V_92 ] ;
}
static unsigned long F_78 ( unsigned long V_62 , int V_95 )
{
unsigned long V_96 = V_62 * V_95 ;
return ( V_96 + V_31 - 1 ) >> V_67 ;
}
static struct V_23 * F_79 ( struct V_97 * V_98 ,
struct V_99 * V_68 , T_1 * V_35 ,
T_1 V_62 )
{
struct V_23 * V_24 ;
int V_61 = 0 ;
int V_100 = F_78 ( V_62 , V_68 -> V_69 ) ;
void * V_93 ;
V_24 = F_2 ( sizeof( * V_24 ) + V_100 * sizeof( struct V_38 * ) * 2 ,
V_101 ) ;
if ( ! V_24 ) {
F_10 ( V_35 ) ;
F_10 ( V_68 ) ;
return F_80 ( - V_17 ) ;
}
F_25 ( & V_24 -> V_40 ) ;
F_5 ( & V_24 -> V_49 ) ;
F_4 ( & V_24 -> V_46 ) ;
F_5 ( & V_24 -> V_19 ) ;
F_5 ( & V_24 -> V_20 ) ;
V_24 -> V_68 = V_68 ;
V_24 -> V_35 = V_35 ;
V_24 -> V_45 = V_98 -> V_45 ;
V_24 -> V_62 = V_62 ;
V_24 -> V_28 = V_100 ;
V_24 -> V_102 = - 1 ;
V_24 -> V_103 = - 1 ;
F_81 ( & V_24 -> V_48 , 1 ) ;
V_93 = V_24 + 1 ;
V_24 -> V_30 = V_93 ;
V_24 -> V_29 = V_93 + sizeof( struct V_38 * ) * V_100 ;
if ( V_35 [ V_68 -> V_69 - 1 ] == V_104 )
V_61 = V_68 -> V_69 - 2 ;
else
V_61 = V_68 -> V_69 - 1 ;
V_24 -> V_61 = V_61 ;
return V_24 ;
}
static int F_12 ( struct V_23 * V_24 )
{
int V_11 ;
struct V_38 * V_38 ;
for ( V_11 = 0 ; V_11 < V_24 -> V_28 ; V_11 ++ ) {
if ( V_24 -> V_30 [ V_11 ] )
continue;
V_38 = F_82 ( V_101 | V_105 ) ;
if ( ! V_38 )
return - V_17 ;
V_24 -> V_30 [ V_11 ] = V_38 ;
F_83 ( V_38 ) ;
}
return 0 ;
}
static int F_84 ( struct V_23 * V_24 )
{
int V_11 ;
struct V_38 * V_38 ;
V_11 = ( V_24 -> V_61 * V_24 -> V_62 ) >> V_67 ;
for (; V_11 < V_24 -> V_28 ; V_11 ++ ) {
if ( V_24 -> V_30 [ V_11 ] )
continue;
V_38 = F_82 ( V_101 | V_105 ) ;
if ( ! V_38 )
return - V_17 ;
V_24 -> V_30 [ V_11 ] = V_38 ;
}
return 0 ;
}
static int F_85 ( struct V_23 * V_24 ,
struct V_40 * V_40 ,
struct V_38 * V_38 ,
int V_106 ,
unsigned long V_107 ,
unsigned long V_108 )
{
struct V_82 * V_63 = V_40 -> V_109 ;
T_1 V_110 = 0 ;
int V_27 ;
struct V_82 * V_82 ;
struct V_111 * V_112 ;
T_1 V_113 ;
V_112 = & V_24 -> V_68 -> V_114 [ V_106 ] ;
V_113 = V_112 -> V_115 + ( V_107 << V_67 ) ;
if ( ! V_112 -> V_116 -> V_117 )
return F_86 ( V_24 , V_106 ) ;
if ( V_63 ) {
V_110 = ( T_1 ) V_63 -> V_118 . V_119 << 9 ;
V_110 += V_63 -> V_118 . V_120 ;
if ( V_110 == V_113 && V_112 -> V_116 -> V_117 &&
F_20 ( V_84 , & V_63 -> V_85 ) &&
V_63 -> V_121 == V_112 -> V_116 -> V_117 ) {
V_27 = F_87 ( V_63 , V_38 , V_31 , 0 ) ;
if ( V_27 == V_31 )
return 0 ;
}
}
V_82 = F_88 ( V_101 , V_108 >> V_94 ? : 1 ) ;
if ( ! V_82 )
return - V_17 ;
V_82 -> V_118 . V_120 = 0 ;
V_82 -> V_121 = V_112 -> V_116 -> V_117 ;
V_82 -> V_118 . V_119 = V_113 >> 9 ;
F_16 ( V_84 , & V_82 -> V_85 ) ;
F_87 ( V_82 , V_38 , V_31 , 0 ) ;
F_89 ( V_40 , V_82 ) ;
return 0 ;
}
static void F_90 ( struct V_23 * V_24 )
{
if ( V_24 -> V_102 >= 0 || V_24 -> V_103 >= 0 ) {
F_33 ( V_24 -> V_102 == V_24 -> V_68 -> V_69 - 1 ) ;
F_91 ( V_24 ) ;
} else {
F_92 ( V_24 ) ;
}
}
static struct V_38 * F_93 ( struct V_23 * V_24 , int V_112 , int V_38 )
{
int V_66 ;
V_66 = V_112 * ( V_24 -> V_62 >> V_67 ) ;
V_66 += V_38 ;
return V_24 -> V_30 [ V_66 ] ;
}
static void F_94 ( struct V_23 * V_24 )
{
struct V_82 * V_82 ;
T_1 V_122 ;
unsigned long V_123 ;
unsigned long V_107 ;
struct V_38 * V_93 ;
int V_11 ;
F_76 ( & V_24 -> V_46 ) ;
F_95 (bio, &rbio->bio_list) {
V_122 = ( T_1 ) V_82 -> V_118 . V_119 << 9 ;
V_123 = V_122 - V_24 -> V_35 [ 0 ] ;
V_107 = V_123 >> V_67 ;
for ( V_11 = 0 ; V_11 < V_82 -> V_124 ; V_11 ++ ) {
V_93 = V_82 -> V_125 [ V_11 ] . V_126 ;
V_24 -> V_29 [ V_107 + V_11 ] = V_93 ;
}
}
F_77 ( & V_24 -> V_46 ) ;
}
static T_3 void F_92 ( struct V_23 * V_24 )
{
struct V_99 * V_68 = V_24 -> V_68 ;
void * V_127 [ V_68 -> V_69 ] ;
int V_62 = V_24 -> V_62 ;
int V_61 = V_24 -> V_61 ;
int V_112 ;
int V_90 ;
int V_128 = - 1 ;
int V_129 = - 1 ;
struct V_40 V_40 ;
struct V_82 * V_82 ;
int V_130 = V_62 >> V_67 ;
int V_27 ;
F_25 ( & V_40 ) ;
if ( V_68 -> V_69 - V_24 -> V_61 == 1 ) {
V_128 = V_68 -> V_69 - 1 ;
} else if ( V_68 -> V_69 - V_24 -> V_61 == 2 ) {
V_128 = V_68 -> V_69 - 2 ;
V_129 = V_68 -> V_69 - 1 ;
} else {
F_96 () ;
}
F_76 ( & V_24 -> V_46 ) ;
F_16 ( V_64 , & V_24 -> V_33 ) ;
F_77 ( & V_24 -> V_46 ) ;
F_81 ( & V_24 -> V_68 -> error , 0 ) ;
F_94 ( V_24 ) ;
if ( ! F_51 ( V_24 ) )
F_11 ( V_24 ) ;
else
F_60 ( V_32 , & V_24 -> V_33 ) ;
for ( V_90 = 0 ; V_90 < V_130 ; V_90 ++ ) {
struct V_38 * V_93 ;
for ( V_112 = 0 ; V_112 < V_61 ; V_112 ++ ) {
V_93 = F_75 ( V_24 , V_112 , V_90 , 0 ) ;
V_127 [ V_112 ] = F_13 ( V_93 ) ;
}
V_93 = F_53 ( V_24 , V_90 ) ;
F_15 ( V_93 ) ;
V_127 [ V_112 ++ ] = F_13 ( V_93 ) ;
if ( V_129 != - 1 ) {
V_93 = F_54 ( V_24 , V_90 ) ;
F_15 ( V_93 ) ;
V_127 [ V_112 ++ ] = F_13 ( V_93 ) ;
V_131 . V_132 ( V_68 -> V_69 , V_133 ,
V_127 ) ;
} else {
memcpy ( V_127 [ V_61 ] , V_127 [ 0 ] , V_133 ) ;
F_47 ( V_127 + 1 , V_61 - 1 , V_31 ) ;
}
for ( V_112 = 0 ; V_112 < V_68 -> V_69 ; V_112 ++ )
F_14 ( F_75 ( V_24 , V_112 , V_90 , 0 ) ) ;
}
for ( V_112 = 0 ; V_112 < V_68 -> V_69 ; V_112 ++ ) {
for ( V_90 = 0 ; V_90 < V_130 ; V_90 ++ ) {
struct V_38 * V_38 ;
if ( V_112 < V_24 -> V_61 ) {
V_38 = F_75 ( V_24 , V_112 , V_90 , 1 ) ;
if ( ! V_38 )
continue;
} else {
V_38 = F_93 ( V_24 , V_112 , V_90 ) ;
}
V_27 = F_85 ( V_24 , & V_40 ,
V_38 , V_112 , V_90 , V_24 -> V_62 ) ;
if ( V_27 )
goto V_134;
}
}
F_81 ( & V_68 -> V_87 , F_97 ( & V_40 ) ) ;
F_33 ( F_66 ( & V_68 -> V_87 ) == 0 ) ;
while ( 1 ) {
V_82 = F_98 ( & V_40 ) ;
if ( ! V_82 )
break;
V_82 -> V_86 = V_24 ;
V_82 -> V_135 = F_72 ;
F_33 ( ! F_20 ( V_84 , & V_82 -> V_85 ) ) ;
F_99 ( V_136 , V_82 ) ;
}
return;
V_134:
F_69 ( V_24 , - V_89 , 0 ) ;
}
static int F_100 ( struct V_23 * V_24 ,
struct V_82 * V_82 )
{
T_1 V_115 = V_82 -> V_118 . V_119 ;
T_1 V_137 ;
int V_11 ;
struct V_111 * V_112 ;
V_115 <<= 9 ;
for ( V_11 = 0 ; V_11 < V_24 -> V_68 -> V_69 ; V_11 ++ ) {
V_112 = & V_24 -> V_68 -> V_114 [ V_11 ] ;
V_137 = V_112 -> V_115 ;
if ( V_115 >= V_137 &&
V_115 < V_137 + V_24 -> V_62 ) {
return V_11 ;
}
}
return - 1 ;
}
static int F_101 ( struct V_23 * V_24 ,
struct V_82 * V_82 )
{
T_1 V_138 = V_82 -> V_118 . V_119 ;
T_1 V_137 ;
int V_11 ;
V_138 <<= 9 ;
for ( V_11 = 0 ; V_11 < V_24 -> V_61 ; V_11 ++ ) {
V_137 = V_24 -> V_35 [ V_11 ] ;
if ( V_138 >= V_137 &&
V_138 < V_137 + V_24 -> V_62 ) {
return V_11 ;
}
}
return - 1 ;
}
static int F_86 ( struct V_23 * V_24 , int V_139 )
{
unsigned long V_33 ;
int V_27 = 0 ;
F_37 ( & V_24 -> V_46 , V_33 ) ;
if ( V_24 -> V_102 == V_139 || V_24 -> V_103 == V_139 )
goto V_74;
if ( V_24 -> V_102 == - 1 ) {
V_24 -> V_102 = V_139 ;
F_44 ( & V_24 -> V_68 -> error ) ;
} else if ( V_24 -> V_103 == - 1 ) {
V_24 -> V_103 = V_139 ;
F_44 ( & V_24 -> V_68 -> error ) ;
} else {
V_27 = - V_89 ;
}
V_74:
F_38 ( & V_24 -> V_46 , V_33 ) ;
return V_27 ;
}
static int F_73 ( struct V_23 * V_24 ,
struct V_82 * V_82 )
{
int V_139 = F_100 ( V_24 , V_82 ) ;
if ( V_139 < 0 )
return - V_89 ;
return F_86 ( V_24 , V_139 ) ;
}
static void F_102 ( struct V_82 * V_82 )
{
int V_11 ;
struct V_38 * V_93 ;
for ( V_11 = 0 ; V_11 < V_82 -> V_124 ; V_11 ++ ) {
V_93 = V_82 -> V_125 [ V_11 ] . V_126 ;
F_15 ( V_93 ) ;
}
}
static void F_103 ( struct V_82 * V_82 , int V_80 )
{
struct V_23 * V_24 = V_82 -> V_86 ;
if ( V_80 )
F_73 ( V_24 , V_82 ) ;
else
F_102 ( V_82 ) ;
F_74 ( V_82 ) ;
if ( ! F_67 ( & V_24 -> V_68 -> V_87 ) )
return;
V_80 = 0 ;
if ( F_66 ( & V_24 -> V_68 -> error ) > V_24 -> V_68 -> V_88 )
goto V_134;
F_90 ( V_24 ) ;
return;
V_134:
F_69 ( V_24 , - V_89 , 0 ) ;
}
static void F_62 ( struct V_23 * V_24 )
{
F_104 ( & V_24 -> V_140 , V_141 , NULL , NULL ) ;
F_105 ( V_24 -> V_45 -> V_142 ,
& V_24 -> V_140 ) ;
}
static void F_61 ( struct V_23 * V_24 )
{
F_104 ( & V_24 -> V_140 , V_143 , NULL , NULL ) ;
F_105 ( V_24 -> V_45 -> V_142 ,
& V_24 -> V_140 ) ;
}
static int F_106 ( struct V_23 * V_24 )
{
int V_144 = 0 ;
struct V_99 * V_68 = V_24 -> V_68 ;
struct V_40 V_40 ;
int V_27 ;
int V_28 = ( V_24 -> V_62 + V_31 - 1 ) >> V_67 ;
int V_90 ;
int V_112 ;
struct V_82 * V_82 ;
F_25 ( & V_40 ) ;
V_27 = F_12 ( V_24 ) ;
if ( V_27 )
goto V_134;
F_94 ( V_24 ) ;
F_81 ( & V_24 -> V_68 -> error , 0 ) ;
for ( V_112 = 0 ; V_112 < V_24 -> V_61 ; V_112 ++ ) {
for ( V_90 = 0 ; V_90 < V_28 ; V_90 ++ ) {
struct V_38 * V_38 ;
V_38 = F_75 ( V_24 , V_112 , V_90 , 1 ) ;
if ( V_38 )
continue;
V_38 = F_93 ( V_24 , V_112 , V_90 ) ;
if ( F_21 ( V_38 ) )
continue;
V_27 = F_85 ( V_24 , & V_40 , V_38 ,
V_112 , V_90 , V_24 -> V_62 ) ;
if ( V_27 )
goto V_134;
}
}
V_144 = F_97 ( & V_40 ) ;
if ( ! V_144 ) {
goto V_145;
}
F_81 ( & V_68 -> V_87 , V_144 ) ;
while ( 1 ) {
V_82 = F_98 ( & V_40 ) ;
if ( ! V_82 )
break;
V_82 -> V_86 = V_24 ;
V_82 -> V_135 = F_103 ;
F_107 ( V_24 -> V_45 , V_82 ,
V_146 ) ;
F_33 ( ! F_20 ( V_84 , & V_82 -> V_85 ) ) ;
F_99 ( V_147 , V_82 ) ;
}
return 0 ;
V_134:
F_69 ( V_24 , - V_89 , 0 ) ;
return - V_89 ;
V_145:
F_90 ( V_24 ) ;
return 0 ;
}
static int F_108 ( struct V_23 * V_24 )
{
int V_27 ;
V_27 = F_84 ( V_24 ) ;
if ( V_27 ) {
F_35 ( V_24 ) ;
return V_27 ;
}
V_27 = F_55 ( V_24 ) ;
if ( V_27 == 0 )
F_92 ( V_24 ) ;
return 0 ;
}
static int F_109 ( struct V_23 * V_24 )
{
int V_27 ;
V_27 = F_55 ( V_24 ) ;
if ( V_27 == 0 )
F_62 ( V_24 ) ;
return 0 ;
}
static int F_110 ( struct V_23 * V_24 )
{
if ( ! F_51 ( V_24 ) )
return F_109 ( V_24 ) ;
return F_108 ( V_24 ) ;
}
static int F_111 ( void * V_148 , struct V_77 * V_149 , struct V_77 * V_150 )
{
struct V_23 * V_151 = F_112 ( V_149 , struct V_23 ,
V_49 ) ;
struct V_23 * V_152 = F_112 ( V_150 , struct V_23 ,
V_49 ) ;
T_1 V_153 = V_151 -> V_40 . V_78 -> V_118 . V_119 ;
T_1 V_154 = V_152 -> V_40 . V_78 -> V_118 . V_119 ;
if ( V_153 < V_154 )
return - 1 ;
if ( V_153 > V_154 )
return 1 ;
return 0 ;
}
static void F_113 ( struct V_155 * V_156 )
{
struct V_23 * V_7 ;
struct V_23 * V_63 = NULL ;
F_114 ( NULL , & V_156 -> V_157 , F_111 ) ;
while ( ! F_31 ( & V_156 -> V_157 ) ) {
V_7 = F_40 ( V_156 -> V_157 . V_50 ,
struct V_23 , V_49 ) ;
F_29 ( & V_7 -> V_49 ) ;
if ( F_51 ( V_7 ) ) {
F_108 ( V_7 ) ;
continue;
}
if ( V_63 ) {
if ( F_52 ( V_63 , V_7 ) ) {
F_23 ( V_63 , V_7 ) ;
F_35 ( V_7 ) ;
continue;
}
F_110 ( V_63 ) ;
}
V_63 = V_7 ;
}
if ( V_63 ) {
F_110 ( V_63 ) ;
}
F_10 ( V_156 ) ;
}
static void F_115 ( struct V_158 * V_140 )
{
struct V_155 * V_156 ;
V_156 = F_112 ( V_140 , struct V_155 , V_140 ) ;
F_113 ( V_156 ) ;
}
static void F_116 ( struct V_159 * V_160 , bool V_161 )
{
struct V_155 * V_156 ;
V_156 = F_112 ( V_160 , struct V_155 , V_160 ) ;
if ( V_161 ) {
F_104 ( & V_156 -> V_140 , F_115 , NULL , NULL ) ;
F_105 ( V_156 -> V_2 -> V_142 ,
& V_156 -> V_140 ) ;
return;
}
F_113 ( V_156 ) ;
}
int F_117 ( struct V_97 * V_98 , struct V_82 * V_82 ,
struct V_99 * V_68 , T_1 * V_35 ,
T_1 V_62 )
{
struct V_23 * V_24 ;
struct V_155 * V_156 = NULL ;
struct V_159 * V_160 ;
V_24 = F_79 ( V_98 , V_68 , V_35 , V_62 ) ;
if ( F_118 ( V_24 ) )
return F_119 ( V_24 ) ;
F_89 ( & V_24 -> V_40 , V_82 ) ;
V_24 -> V_41 = V_82 -> V_118 . V_120 ;
if ( F_51 ( V_24 ) )
return F_108 ( V_24 ) ;
V_160 = F_120 ( F_116 , V_98 -> V_45 ,
sizeof( * V_156 ) ) ;
if ( V_160 ) {
V_156 = F_112 ( V_160 , struct V_155 , V_160 ) ;
if ( ! V_156 -> V_2 ) {
V_156 -> V_2 = V_98 -> V_45 ;
F_5 ( & V_156 -> V_157 ) ;
}
F_58 ( & V_24 -> V_49 , & V_156 -> V_157 ) ;
} else {
return F_110 ( V_24 ) ;
}
return 0 ;
}
static void F_121 ( struct V_23 * V_24 )
{
int V_90 , V_112 ;
void * * V_127 ;
int V_102 = - 1 , V_103 = - 1 ;
int V_28 = ( V_24 -> V_62 + V_31 - 1 ) >> V_67 ;
struct V_38 * V_38 ;
int V_80 ;
int V_11 ;
V_127 = F_2 ( V_24 -> V_68 -> V_69 * sizeof( void * ) ,
V_101 ) ;
if ( ! V_127 ) {
V_80 = - V_17 ;
goto V_162;
}
V_102 = V_24 -> V_102 ;
V_103 = V_24 -> V_103 ;
if ( V_24 -> V_65 ) {
F_76 ( & V_24 -> V_46 ) ;
F_16 ( V_64 , & V_24 -> V_33 ) ;
F_77 ( & V_24 -> V_46 ) ;
}
F_94 ( V_24 ) ;
for ( V_90 = 0 ; V_90 < V_28 ; V_90 ++ ) {
for ( V_112 = 0 ; V_112 < V_24 -> V_68 -> V_69 ; V_112 ++ ) {
if ( V_24 -> V_65 &&
( V_112 == V_102 || V_112 == V_103 ) ) {
V_38 = F_75 ( V_24 , V_112 , V_90 , 0 ) ;
} else {
V_38 = F_93 ( V_24 , V_112 , V_90 ) ;
}
V_127 [ V_112 ] = F_13 ( V_38 ) ;
}
if ( V_24 -> V_35 [ V_24 -> V_68 -> V_69 - 1 ] ==
V_104 ) {
if ( V_103 < 0 ) {
if ( V_102 == V_24 -> V_61 ) {
V_80 = - V_89 ;
goto V_134;
}
goto V_163;
}
if ( V_102 > V_103 ) {
int V_164 = V_103 ;
V_103 = V_102 ;
V_102 = V_164 ;
}
if ( V_24 -> V_35 [ V_103 ] == V_104 ) {
if ( V_24 -> V_35 [ V_102 ] == V_165 ) {
V_80 = - V_89 ;
goto V_134;
}
goto V_163;
}
if ( V_24 -> V_35 [ V_103 ] == V_165 ) {
F_122 ( V_24 -> V_68 -> V_69 ,
V_133 , V_102 , V_127 ) ;
} else {
F_123 ( V_24 -> V_68 -> V_69 ,
V_133 , V_102 , V_103 ,
V_127 ) ;
}
} else {
void * V_93 ;
F_33 ( V_103 != - 1 ) ;
V_163:
memcpy ( V_127 [ V_102 ] ,
V_127 [ V_24 -> V_61 ] ,
V_31 ) ;
V_93 = V_127 [ V_102 ] ;
for ( V_112 = V_102 ; V_112 < V_24 -> V_61 - 1 ; V_112 ++ )
V_127 [ V_112 ] = V_127 [ V_112 + 1 ] ;
V_127 [ V_24 -> V_61 - 1 ] = V_93 ;
F_47 ( V_127 , V_24 -> V_61 - 1 , V_31 ) ;
}
if ( ! V_24 -> V_65 ) {
for ( V_11 = 0 ; V_11 < V_28 ; V_11 ++ ) {
if ( V_102 != - 1 ) {
V_38 = F_93 ( V_24 , V_102 , V_11 ) ;
F_15 ( V_38 ) ;
}
if ( V_103 != - 1 ) {
V_38 = F_93 ( V_24 , V_103 , V_11 ) ;
F_15 ( V_38 ) ;
}
}
}
for ( V_112 = 0 ; V_112 < V_24 -> V_68 -> V_69 ; V_112 ++ ) {
if ( V_24 -> V_65 &&
( V_112 == V_102 || V_112 == V_103 ) ) {
V_38 = F_75 ( V_24 , V_112 , V_90 , 0 ) ;
} else {
V_38 = F_93 ( V_24 , V_112 , V_90 ) ;
}
F_14 ( V_38 ) ;
}
}
V_80 = 0 ;
V_134:
F_10 ( V_127 ) ;
V_162:
if ( V_24 -> V_65 ) {
if ( V_80 == 0 )
F_11 ( V_24 ) ;
else
F_60 ( V_32 , & V_24 -> V_33 ) ;
F_69 ( V_24 , V_80 , V_80 == 0 ) ;
} else if ( V_80 == 0 ) {
V_24 -> V_102 = - 1 ;
V_24 -> V_103 = - 1 ;
F_92 ( V_24 ) ;
} else {
F_69 ( V_24 , V_80 , 0 ) ;
}
}
static void F_124 ( struct V_82 * V_82 , int V_80 )
{
struct V_23 * V_24 = V_82 -> V_86 ;
if ( V_80 )
F_73 ( V_24 , V_82 ) ;
else
F_102 ( V_82 ) ;
F_74 ( V_82 ) ;
if ( ! F_67 ( & V_24 -> V_68 -> V_87 ) )
return;
if ( F_66 ( & V_24 -> V_68 -> error ) > V_24 -> V_68 -> V_88 )
F_69 ( V_24 , - V_89 , 0 ) ;
else
F_121 ( V_24 ) ;
}
static int F_91 ( struct V_23 * V_24 )
{
int V_144 = 0 ;
struct V_99 * V_68 = V_24 -> V_68 ;
struct V_40 V_40 ;
int V_27 ;
int V_28 = ( V_24 -> V_62 + V_31 - 1 ) >> V_67 ;
int V_90 ;
int V_112 ;
struct V_82 * V_82 ;
F_25 ( & V_40 ) ;
V_27 = F_12 ( V_24 ) ;
if ( V_27 )
goto V_134;
F_81 ( & V_24 -> V_68 -> error , 0 ) ;
for ( V_112 = 0 ; V_112 < V_68 -> V_69 ; V_112 ++ ) {
if ( V_24 -> V_102 == V_112 ||
V_24 -> V_103 == V_112 )
continue;
for ( V_90 = 0 ; V_90 < V_28 ; V_90 ++ ) {
struct V_38 * V_93 ;
V_93 = F_93 ( V_24 , V_112 , V_90 ) ;
if ( F_21 ( V_93 ) )
continue;
V_27 = F_85 ( V_24 , & V_40 ,
F_93 ( V_24 , V_112 , V_90 ) ,
V_112 , V_90 , V_24 -> V_62 ) ;
if ( V_27 < 0 )
goto V_134;
}
}
V_144 = F_97 ( & V_40 ) ;
if ( ! V_144 ) {
if ( F_66 ( & V_24 -> V_68 -> error ) <= V_24 -> V_68 -> V_88 ) {
F_121 ( V_24 ) ;
goto V_74;
} else {
goto V_134;
}
}
F_81 ( & V_68 -> V_87 , V_144 ) ;
while ( 1 ) {
V_82 = F_98 ( & V_40 ) ;
if ( ! V_82 )
break;
V_82 -> V_86 = V_24 ;
V_82 -> V_135 = F_124 ;
F_107 ( V_24 -> V_45 , V_82 ,
V_146 ) ;
F_33 ( ! F_20 ( V_84 , & V_82 -> V_85 ) ) ;
F_99 ( V_147 , V_82 ) ;
}
V_74:
return 0 ;
V_134:
if ( V_24 -> V_65 )
F_69 ( V_24 , - V_89 , 0 ) ;
return - V_89 ;
}
int F_125 ( struct V_97 * V_98 , struct V_82 * V_82 ,
struct V_99 * V_68 , T_1 * V_35 ,
T_1 V_62 , int V_166 )
{
struct V_23 * V_24 ;
int V_27 ;
V_24 = F_79 ( V_98 , V_68 , V_35 , V_62 ) ;
if ( F_118 ( V_24 ) )
return F_119 ( V_24 ) ;
V_24 -> V_65 = 1 ;
F_89 ( & V_24 -> V_40 , V_82 ) ;
V_24 -> V_41 = V_82 -> V_118 . V_120 ;
V_24 -> V_102 = F_101 ( V_24 , V_82 ) ;
if ( V_24 -> V_102 == - 1 ) {
F_96 () ;
F_10 ( V_35 ) ;
F_10 ( V_68 ) ;
F_10 ( V_24 ) ;
return - V_89 ;
}
if ( V_166 == 3 )
V_24 -> V_103 = V_68 -> V_69 - 2 ;
V_27 = F_55 ( V_24 ) ;
if ( V_27 == 0 )
F_91 ( V_24 ) ;
return 0 ;
}
static void V_141 ( struct V_158 * V_140 )
{
struct V_23 * V_24 ;
V_24 = F_112 ( V_140 , struct V_23 , V_140 ) ;
F_106 ( V_24 ) ;
}
static void V_143 ( struct V_158 * V_140 )
{
struct V_23 * V_24 ;
V_24 = F_112 ( V_140 , struct V_23 , V_140 ) ;
F_91 ( V_24 ) ;
}
