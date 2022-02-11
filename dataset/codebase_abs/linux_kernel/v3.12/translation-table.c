static int F_1 ( const struct V_1 * V_2 , const void * V_3 )
{
const void * V_4 = F_2 ( V_2 , struct V_5 ,
V_6 ) ;
return ( memcmp ( V_4 , V_3 , V_7 ) == 0 ? 1 : 0 ) ;
}
static struct V_5 *
F_3 ( struct V_8 * V_9 , const void * V_10 )
{
struct V_11 * V_12 ;
struct V_5 * V_13 ;
struct V_5 * V_14 = NULL ;
T_1 V_15 ;
if ( ! V_9 )
return NULL ;
V_15 = F_4 ( V_10 , V_9 -> V_16 ) ;
V_12 = & V_9 -> V_17 [ V_15 ] ;
F_5 () ;
F_6 (tt_common_entry, head, hash_entry) {
if ( ! F_7 ( V_13 , V_10 ) )
continue;
if ( ! F_8 ( & V_13 -> V_18 ) )
continue;
V_14 = V_13 ;
break;
}
F_9 () ;
return V_14 ;
}
static struct V_19 *
F_10 ( struct V_20 * V_21 , const void * V_10 )
{
struct V_5 * V_13 ;
struct V_19 * V_22 = NULL ;
V_13 = F_3 ( V_21 -> V_23 . V_24 , V_10 ) ;
if ( V_13 )
V_22 = F_2 ( V_13 ,
struct V_19 ,
V_25 ) ;
return V_22 ;
}
static struct V_26 *
F_11 ( struct V_20 * V_21 , const void * V_10 )
{
struct V_5 * V_13 ;
struct V_26 * V_27 = NULL ;
V_13 = F_3 ( V_21 -> V_23 . V_28 , V_10 ) ;
if ( V_13 )
V_27 = F_2 ( V_13 ,
struct V_26 ,
V_25 ) ;
return V_27 ;
}
static void
F_12 ( struct V_19 * V_22 )
{
if ( F_13 ( & V_22 -> V_25 . V_18 ) )
F_14 ( V_22 , V_25 . V_29 ) ;
}
static void F_15 ( struct V_30 * V_29 )
{
struct V_5 * V_13 ;
struct V_26 * V_27 ;
V_13 = F_2 ( V_29 , struct V_5 , V_29 ) ;
V_27 = F_2 ( V_13 ,
struct V_26 , V_25 ) ;
F_16 ( V_27 ) ;
}
static void
F_17 ( struct V_26 * V_27 )
{
if ( F_13 ( & V_27 -> V_25 . V_18 ) ) {
F_18 ( V_27 ) ;
F_19 ( & V_27 -> V_25 . V_29 ,
F_15 ) ;
}
}
static void F_20 ( struct V_30 * V_29 )
{
struct V_31 * V_32 ;
V_32 = F_2 ( V_29 , struct V_31 , V_29 ) ;
F_21 ( V_32 -> V_33 ) ;
F_16 ( V_32 ) ;
}
static void
F_22 ( struct V_31 * V_32 )
{
if ( ! F_13 ( & V_32 -> V_18 ) )
return;
F_23 ( & V_32 -> V_33 -> V_34 ) ;
F_19 ( & V_32 -> V_29 , F_20 ) ;
}
static void F_24 ( struct V_20 * V_21 ,
struct V_19 * V_22 ,
T_2 V_35 )
{
struct V_36 * V_37 , * V_38 , * V_39 ;
struct V_5 * V_25 = & V_22 -> V_25 ;
T_2 V_40 = V_25 -> V_40 | V_35 ;
bool V_41 = false ;
bool V_42 , V_43 ;
V_37 = F_25 ( sizeof( * V_37 ) , V_44 ) ;
if ( ! V_37 )
return;
V_37 -> V_45 . V_40 = V_40 ;
memcpy ( V_37 -> V_45 . V_46 , V_25 -> V_46 , V_7 ) ;
V_42 = V_40 & V_47 ;
F_26 ( & V_21 -> V_23 . V_48 ) ;
F_27 (entry, safe, &bat_priv->tt.changes_list,
list) {
if ( ! F_7 ( V_38 -> V_45 . V_46 , V_25 -> V_46 ) )
continue;
V_43 = V_38 -> V_45 . V_40 & V_47 ;
if ( ! V_42 && V_43 )
goto V_49;
if ( V_42 && ! V_43 )
goto V_49;
continue;
V_49:
F_28 ( & V_38 -> V_50 ) ;
F_16 ( V_38 ) ;
F_16 ( V_37 ) ;
V_41 = true ;
goto V_51;
}
F_29 ( & V_37 -> V_50 , & V_21 -> V_23 . V_52 ) ;
V_51:
F_30 ( & V_21 -> V_23 . V_48 ) ;
if ( V_41 )
F_23 ( & V_21 -> V_23 . V_53 ) ;
else
F_31 ( & V_21 -> V_23 . V_53 ) ;
}
int F_32 ( int V_54 )
{
return V_54 * sizeof( struct V_55 ) ;
}
static int F_33 ( struct V_20 * V_21 )
{
if ( V_21 -> V_23 . V_24 )
return 0 ;
V_21 -> V_23 . V_24 = F_34 ( 1024 ) ;
if ( ! V_21 -> V_23 . V_24 )
return - V_56 ;
F_35 ( V_21 -> V_23 . V_24 ,
& V_57 ) ;
return 0 ;
}
static void F_36 ( struct V_20 * V_21 ,
struct V_26 * V_58 ,
const char * V_59 )
{
F_37 ( V_60 , V_21 ,
L_1 ,
V_58 -> V_25 . V_46 , V_59 ) ;
F_38 ( V_21 -> V_23 . V_28 , F_1 ,
F_4 , V_58 -> V_25 . V_46 ) ;
F_17 ( V_58 ) ;
}
void F_39 ( struct V_61 * V_62 , const T_2 * V_46 ,
int V_63 )
{
struct V_20 * V_21 = F_40 ( V_62 ) ;
struct V_19 * V_64 ;
struct V_26 * V_58 ;
struct V_11 * V_12 ;
struct V_31 * V_32 ;
int V_65 ;
bool V_66 = false ;
V_64 = F_10 ( V_21 , V_46 ) ;
V_58 = F_11 ( V_21 , V_46 ) ;
if ( V_64 ) {
V_64 -> V_67 = V_68 ;
if ( V_64 -> V_25 . V_40 & V_69 ) {
F_37 ( V_60 , V_21 ,
L_2 , V_46 ) ;
V_64 -> V_25 . V_40 &= ~ V_69 ;
goto V_70;
}
if ( V_64 -> V_25 . V_40 & V_71 ) {
F_37 ( V_60 , V_21 ,
L_3 ,
V_46 ) ;
V_64 -> V_25 . V_40 &= ~ V_71 ;
V_66 = true ;
}
goto V_72;
}
V_64 = F_25 ( sizeof( * V_64 ) , V_44 ) ;
if ( ! V_64 )
goto V_73;
F_37 ( V_60 , V_21 ,
L_4 , V_46 ,
( T_2 ) F_41 ( & V_21 -> V_23 . V_74 ) ) ;
memcpy ( V_64 -> V_25 . V_46 , V_46 , V_7 ) ;
V_64 -> V_25 . V_40 = V_75 ;
if ( F_42 ( V_63 ) )
V_64 -> V_25 . V_40 |= V_76 ;
F_43 ( & V_64 -> V_25 . V_18 , 2 ) ;
V_64 -> V_67 = V_68 ;
V_64 -> V_25 . V_77 = V_64 -> V_67 ;
if ( F_7 ( V_46 , V_62 -> V_78 ) )
V_64 -> V_25 . V_40 |= V_79 ;
V_65 = F_44 ( V_21 -> V_23 . V_24 , F_1 ,
F_4 , & V_64 -> V_25 ,
& V_64 -> V_25 . V_6 ) ;
if ( F_45 ( V_65 != 0 ) ) {
F_12 ( V_64 ) ;
goto V_73;
}
V_70:
F_24 ( V_21 , V_64 , V_80 ) ;
V_72:
if ( V_58 && ! ( V_58 -> V_25 . V_40 & V_71 ) ) {
V_12 = & V_58 -> V_81 ;
F_5 () ;
F_6 (orig_entry, head, list) {
F_46 ( V_21 , V_58 -> V_25 . V_46 ,
V_32 -> V_33 ) ;
}
F_9 () ;
if ( V_66 ) {
F_36 ( V_21 , V_58 ,
L_5 ) ;
V_58 = NULL ;
} else {
V_58 -> V_25 . V_40 |= V_71 ;
V_58 -> V_82 = V_68 ;
}
}
V_73:
if ( V_64 )
F_12 ( V_64 ) ;
if ( V_58 )
F_17 ( V_58 ) ;
}
static void F_47 ( unsigned char * * V_83 ,
int * V_84 ,
int V_85 ,
int V_86 )
{
unsigned char * V_87 ;
V_87 = F_25 ( V_86 , V_44 ) ;
if ( V_87 ) {
memcpy ( V_87 , * V_83 , V_85 ) ;
F_16 ( * V_83 ) ;
* V_83 = V_87 ;
* V_84 = V_86 ;
}
}
static void F_48 ( struct V_20 * V_21 ,
unsigned char * * V_83 ,
int * V_84 ,
int V_85 )
{
int V_88 ;
V_88 = V_85 ;
V_88 += F_32 ( F_41 ( & V_21 -> V_23 . V_53 ) ) ;
if ( V_88 > V_21 -> V_62 -> V_89 )
V_88 = V_85 ;
F_47 ( V_83 , V_84 ,
V_85 , V_88 ) ;
}
static int F_49 ( struct V_20 * V_21 ,
unsigned char * * V_83 ,
int * V_84 ,
int V_85 )
{
struct V_36 * V_38 , * V_39 ;
int V_90 = 0 , V_91 = 0 , V_92 ;
unsigned char * V_93 ;
F_48 ( V_21 , V_83 ,
V_84 , V_85 ) ;
V_92 = * V_84 - V_85 ;
V_93 = * V_83 + V_85 ;
if ( V_92 > 0 )
V_91 = V_92 / F_32 ( 1 ) ;
F_26 ( & V_21 -> V_23 . V_48 ) ;
F_43 ( & V_21 -> V_23 . V_53 , 0 ) ;
F_27 (entry, safe, &bat_priv->tt.changes_list,
list) {
if ( V_90 < V_91 ) {
memcpy ( V_93 + F_32 ( V_90 ) ,
& V_38 -> V_45 , sizeof( struct V_55 ) ) ;
V_90 ++ ;
}
F_28 ( & V_38 -> V_50 ) ;
F_16 ( V_38 ) ;
}
F_30 ( & V_21 -> V_23 . V_48 ) ;
F_26 ( & V_21 -> V_23 . V_94 ) ;
F_16 ( V_21 -> V_23 . V_95 ) ;
V_21 -> V_23 . V_96 = 0 ;
V_21 -> V_23 . V_95 = NULL ;
if ( V_92 > 0 ) {
V_21 -> V_23 . V_95 = F_25 ( V_92 , V_44 ) ;
if ( V_21 -> V_23 . V_95 ) {
memcpy ( V_21 -> V_23 . V_95 , V_93 , V_92 ) ;
V_21 -> V_23 . V_96 = V_92 ;
}
}
F_30 ( & V_21 -> V_23 . V_94 ) ;
return V_90 ;
}
int F_50 ( struct V_97 * V_98 , void * V_99 )
{
struct V_61 * V_100 = (struct V_61 * ) V_98 -> V_101 ;
struct V_20 * V_21 = F_40 ( V_100 ) ;
struct V_8 * V_9 = V_21 -> V_23 . V_24 ;
struct V_5 * V_13 ;
struct V_19 * V_64 ;
struct V_102 * V_103 ;
struct V_11 * V_12 ;
T_1 V_104 ;
int V_105 ;
int V_106 ;
unsigned long V_107 ;
bool V_108 ;
T_3 V_109 = V_79 ;
V_103 = F_51 ( V_98 ) ;
if ( ! V_103 )
goto V_73;
F_52 ( V_98 ,
L_6 ,
V_100 -> V_110 , ( T_2 ) F_41 ( & V_21 -> V_23 . V_74 ) ,
V_21 -> V_23 . V_111 ) ;
F_52 ( V_98 , L_7 , L_8 , L_9 ,
L_10 ) ;
for ( V_104 = 0 ; V_104 < V_9 -> V_16 ; V_104 ++ ) {
V_12 = & V_9 -> V_17 [ V_104 ] ;
F_5 () ;
F_6 (tt_common_entry,
head, hash_entry) {
V_64 = F_2 ( V_13 ,
struct V_19 ,
V_25 ) ;
V_107 = V_68 - V_64 -> V_67 ;
V_106 = F_53 ( V_107 ) ;
V_105 = V_106 / 1000 ;
V_106 = V_106 % 1000 ;
V_108 = V_13 -> V_40 & V_109 ;
F_52 ( V_98 , L_11 ,
V_13 -> V_46 ,
( V_13 -> V_40 &
V_71 ? 'R' : '.' ) ,
V_108 ? 'P' : '.' ,
( V_13 -> V_40 &
V_75 ? 'N' : '.' ) ,
( V_13 -> V_40 &
V_69 ? 'X' : '.' ) ,
( V_13 -> V_40 &
V_76 ? 'W' : '.' ) ,
V_108 ? 0 : V_105 ,
V_108 ? 0 : V_106 ) ;
}
F_9 () ;
}
V_73:
if ( V_103 )
F_54 ( V_103 ) ;
return 0 ;
}
static void
F_55 ( struct V_20 * V_21 ,
struct V_19 * V_22 ,
T_3 V_40 , const char * V_59 )
{
F_24 ( V_21 , V_22 , V_40 ) ;
V_22 -> V_25 . V_40 |= V_69 ;
F_37 ( V_60 , V_21 ,
L_12 ,
V_22 -> V_25 . V_46 , V_59 ) ;
}
T_3 F_56 ( struct V_20 * V_21 ,
const T_2 * V_46 , const char * V_59 ,
bool V_112 )
{
struct V_19 * V_22 ;
T_3 V_40 , V_113 = V_80 ;
V_22 = F_10 ( V_21 , V_46 ) ;
if ( ! V_22 )
goto V_73;
V_113 = V_22 -> V_25 . V_40 ;
V_40 = V_47 ;
if ( V_112 ) {
V_40 |= V_71 ;
V_22 -> V_25 . V_40 |= V_71 ;
}
if ( ! ( V_22 -> V_25 . V_40 & V_75 ) ) {
F_55 ( V_21 , V_22 , V_40 ,
V_59 ) ;
goto V_73;
}
F_24 ( V_21 , V_22 , V_47 ) ;
F_57 ( & V_22 -> V_25 . V_6 ) ;
F_12 ( V_22 ) ;
V_73:
if ( V_22 )
F_12 ( V_22 ) ;
return V_113 ;
}
static void F_58 ( struct V_20 * V_21 ,
struct V_11 * V_12 )
{
struct V_19 * V_22 ;
struct V_5 * V_13 ;
struct V_1 * V_114 ;
F_59 (tt_common_entry, node_tmp, head,
hash_entry) {
V_22 = F_2 ( V_13 ,
struct V_19 ,
V_25 ) ;
if ( V_22 -> V_25 . V_40 & V_79 )
continue;
if ( V_22 -> V_25 . V_40 & V_69 )
continue;
if ( ! F_60 ( V_22 -> V_67 ,
V_115 ) )
continue;
F_55 ( V_21 , V_22 ,
V_47 , L_13 ) ;
}
}
static void F_61 ( struct V_20 * V_21 )
{
struct V_8 * V_9 = V_21 -> V_23 . V_24 ;
struct V_11 * V_12 ;
T_4 * V_116 ;
T_1 V_104 ;
for ( V_104 = 0 ; V_104 < V_9 -> V_16 ; V_104 ++ ) {
V_12 = & V_9 -> V_17 [ V_104 ] ;
V_116 = & V_9 -> V_117 [ V_104 ] ;
F_26 ( V_116 ) ;
F_58 ( V_21 , V_12 ) ;
F_30 ( V_116 ) ;
}
}
static void F_62 ( struct V_20 * V_21 )
{
struct V_8 * V_9 ;
T_4 * V_116 ;
struct V_5 * V_13 ;
struct V_19 * V_64 ;
struct V_1 * V_114 ;
struct V_11 * V_12 ;
T_1 V_104 ;
if ( ! V_21 -> V_23 . V_24 )
return;
V_9 = V_21 -> V_23 . V_24 ;
for ( V_104 = 0 ; V_104 < V_9 -> V_16 ; V_104 ++ ) {
V_12 = & V_9 -> V_17 [ V_104 ] ;
V_116 = & V_9 -> V_117 [ V_104 ] ;
F_26 ( V_116 ) ;
F_59 (tt_common_entry, node_tmp,
head, hash_entry) {
F_57 ( & V_13 -> V_6 ) ;
V_64 = F_2 ( V_13 ,
struct V_19 ,
V_25 ) ;
F_12 ( V_64 ) ;
}
F_30 ( V_116 ) ;
}
F_63 ( V_9 ) ;
V_21 -> V_23 . V_24 = NULL ;
}
static int F_64 ( struct V_20 * V_21 )
{
if ( V_21 -> V_23 . V_28 )
return 0 ;
V_21 -> V_23 . V_28 = F_34 ( 1024 ) ;
if ( ! V_21 -> V_23 . V_28 )
return - V_56 ;
F_35 ( V_21 -> V_23 . V_28 ,
& V_118 ) ;
return 0 ;
}
static void F_65 ( struct V_20 * V_21 )
{
struct V_36 * V_38 , * V_39 ;
F_26 ( & V_21 -> V_23 . V_48 ) ;
F_27 (entry, safe, &bat_priv->tt.changes_list,
list) {
F_28 ( & V_38 -> V_50 ) ;
F_16 ( V_38 ) ;
}
F_43 ( & V_21 -> V_23 . V_53 , 0 ) ;
F_30 ( & V_21 -> V_23 . V_48 ) ;
}
static struct V_31 *
F_66 ( const struct V_26 * V_38 ,
const struct V_119 * V_33 )
{
struct V_31 * V_120 , * V_32 = NULL ;
const struct V_11 * V_12 ;
F_5 () ;
V_12 = & V_38 -> V_81 ;
F_6 (tmp_orig_entry, head, list) {
if ( V_120 -> V_33 != V_33 )
continue;
if ( ! F_8 ( & V_120 -> V_18 ) )
continue;
V_32 = V_120 ;
break;
}
F_9 () ;
return V_32 ;
}
static bool
F_67 ( const struct V_26 * V_38 ,
const struct V_119 * V_33 )
{
struct V_31 * V_32 ;
bool V_121 = false ;
V_32 = F_66 ( V_38 , V_33 ) ;
if ( V_32 ) {
V_121 = true ;
F_22 ( V_32 ) ;
}
return V_121 ;
}
static void
F_68 ( struct V_26 * V_58 ,
struct V_119 * V_33 , int V_122 )
{
struct V_31 * V_32 ;
V_32 = F_66 ( V_58 , V_33 ) ;
if ( V_32 ) {
V_32 -> V_122 = V_122 ;
goto V_73;
}
V_32 = F_69 ( sizeof( * V_32 ) , V_44 ) ;
if ( ! V_32 )
goto V_73;
F_70 ( & V_32 -> V_50 ) ;
F_31 ( & V_33 -> V_18 ) ;
F_31 ( & V_33 -> V_34 ) ;
V_32 -> V_33 = V_33 ;
V_32 -> V_122 = V_122 ;
F_43 ( & V_32 -> V_18 , 2 ) ;
F_26 ( & V_58 -> V_116 ) ;
F_71 ( & V_32 -> V_50 ,
& V_58 -> V_81 ) ;
F_30 ( & V_58 -> V_116 ) ;
V_73:
if ( V_32 )
F_22 ( V_32 ) ;
}
int F_72 ( struct V_20 * V_21 ,
struct V_119 * V_33 ,
const unsigned char * V_123 , T_3 V_40 ,
T_2 V_122 )
{
struct V_26 * V_27 ;
struct V_19 * V_22 ;
int V_124 = 0 ;
int V_65 ;
struct V_5 * V_25 ;
T_3 V_125 ;
V_27 = F_11 ( V_21 , V_123 ) ;
V_22 = F_10 ( V_21 , V_123 ) ;
if ( ( V_40 & V_126 ) && V_22 &&
! ( V_22 -> V_25 . V_40 & V_75 ) )
goto V_73;
if ( ! V_27 ) {
V_27 = F_69 ( sizeof( * V_27 ) , V_44 ) ;
if ( ! V_27 )
goto V_73;
V_25 = & V_27 -> V_25 ;
memcpy ( V_25 -> V_46 , V_123 , V_7 ) ;
V_25 -> V_40 = V_40 ;
V_27 -> V_82 = 0 ;
if ( V_40 & V_71 )
V_27 -> V_82 = V_68 ;
F_43 ( & V_25 -> V_18 , 2 ) ;
V_25 -> V_77 = V_68 ;
F_73 ( & V_27 -> V_81 ) ;
F_74 ( & V_27 -> V_116 ) ;
V_65 = F_44 ( V_21 -> V_23 . V_28 ,
F_1 ,
F_4 , V_25 ,
& V_25 -> V_6 ) ;
if ( F_45 ( V_65 != 0 ) ) {
F_17 ( V_27 ) ;
goto V_127;
}
} else {
V_25 = & V_27 -> V_25 ;
if ( V_40 & V_126 ) {
if ( ! ( V_25 -> V_40 & V_126 ) )
goto V_73;
if ( F_67 ( V_27 ,
V_33 ) )
goto V_127;
F_18 ( V_27 ) ;
goto V_128;
}
V_25 -> V_40 &= ~ V_126 ;
V_27 -> V_25 . V_40 |= V_40 ;
if ( V_25 -> V_40 & V_71 ) {
F_18 ( V_27 ) ;
V_25 -> V_40 &= ~ V_71 ;
V_27 -> V_82 = 0 ;
}
}
V_128:
F_68 ( V_27 , V_33 , V_122 ) ;
F_37 ( V_60 , V_21 ,
L_14 ,
V_25 -> V_46 , V_33 -> V_129 ) ;
V_124 = 1 ;
V_127:
V_125 = F_56 ( V_21 , V_123 ,
L_15 ,
V_40 & V_71 ) ;
V_27 -> V_25 . V_40 |= V_125 & V_76 ;
if ( ! ( V_40 & V_71 ) )
V_27 -> V_25 . V_40 &= ~ V_71 ;
V_73:
if ( V_27 )
F_17 ( V_27 ) ;
if ( V_22 )
F_12 ( V_22 ) ;
return V_124 ;
}
static struct V_31 *
F_75 ( struct V_26 * V_27 )
{
struct V_130 * V_131 = NULL ;
struct V_11 * V_12 ;
struct V_31 * V_32 , * V_132 = NULL ;
int V_133 = 0 ;
V_12 = & V_27 -> V_81 ;
F_6 (orig_entry, head, list) {
V_131 = F_76 ( V_32 -> V_33 ) ;
if ( ! V_131 )
continue;
if ( V_131 -> V_134 > V_133 ) {
V_132 = V_32 ;
V_133 = V_131 -> V_134 ;
}
F_77 ( V_131 ) ;
}
return V_132 ;
}
static void
F_78 ( struct V_26 * V_27 ,
struct V_97 * V_98 )
{
struct V_11 * V_12 ;
struct V_31 * V_32 , * V_132 ;
struct V_5 * V_13 ;
T_3 V_40 ;
T_2 V_135 ;
V_13 = & V_27 -> V_25 ;
V_40 = V_13 -> V_40 ;
V_132 = F_75 ( V_27 ) ;
if ( V_132 ) {
V_135 = F_41 ( & V_132 -> V_33 -> V_135 ) ;
F_52 ( V_98 ,
L_16 ,
'*' , V_27 -> V_25 . V_46 ,
V_132 -> V_122 , V_132 -> V_33 -> V_129 ,
V_135 , V_132 -> V_33 -> V_136 ,
( V_40 & V_71 ? 'R' : '.' ) ,
( V_40 & V_76 ? 'W' : '.' ) ,
( V_40 & V_126 ? 'T' : '.' ) ) ;
}
V_12 = & V_27 -> V_81 ;
F_6 (orig_entry, head, list) {
if ( V_132 == V_32 )
continue;
V_135 = F_41 ( & V_32 -> V_33 -> V_135 ) ;
F_52 ( V_98 , L_17 ,
'+' , V_27 -> V_25 . V_46 ,
V_32 -> V_122 , V_32 -> V_33 -> V_129 ,
V_135 ,
( V_40 & V_71 ? 'R' : '.' ) ,
( V_40 & V_76 ? 'W' : '.' ) ,
( V_40 & V_126 ? 'T' : '.' ) ) ;
}
}
int F_79 ( struct V_97 * V_98 , void * V_99 )
{
struct V_61 * V_100 = (struct V_61 * ) V_98 -> V_101 ;
struct V_20 * V_21 = F_40 ( V_100 ) ;
struct V_8 * V_9 = V_21 -> V_23 . V_28 ;
struct V_5 * V_13 ;
struct V_26 * V_58 ;
struct V_102 * V_103 ;
struct V_11 * V_12 ;
T_1 V_104 ;
V_103 = F_51 ( V_98 ) ;
if ( ! V_103 )
goto V_73;
F_52 ( V_98 ,
L_18 ,
V_100 -> V_110 ) ;
F_52 ( V_98 , L_19 ,
L_8 , L_20 , L_21 , L_22 , L_23 ,
L_9 ) ;
for ( V_104 = 0 ; V_104 < V_9 -> V_16 ; V_104 ++ ) {
V_12 = & V_9 -> V_17 [ V_104 ] ;
F_5 () ;
F_6 (tt_common_entry,
head, hash_entry) {
V_58 = F_2 ( V_13 ,
struct V_26 ,
V_25 ) ;
F_78 ( V_58 , V_98 ) ;
}
F_9 () ;
}
V_73:
if ( V_103 )
F_54 ( V_103 ) ;
return 0 ;
}
static void
F_18 ( struct V_26 * V_27 )
{
struct V_11 * V_12 ;
struct V_1 * V_39 ;
struct V_31 * V_32 ;
F_26 ( & V_27 -> V_116 ) ;
V_12 = & V_27 -> V_81 ;
F_59 (orig_entry, safe, head, list) {
F_57 ( & V_32 -> V_50 ) ;
F_22 ( V_32 ) ;
}
F_30 ( & V_27 -> V_116 ) ;
}
static void
F_80 ( struct V_20 * V_21 ,
struct V_26 * V_27 ,
struct V_119 * V_33 ,
const char * V_59 )
{
struct V_11 * V_12 ;
struct V_1 * V_39 ;
struct V_31 * V_32 ;
F_26 ( & V_27 -> V_116 ) ;
V_12 = & V_27 -> V_81 ;
F_59 (orig_entry, safe, head, list) {
if ( V_32 -> V_33 == V_33 ) {
F_37 ( V_60 , V_21 ,
L_24 ,
V_33 -> V_129 ,
V_27 -> V_25 . V_46 , V_59 ) ;
F_57 ( & V_32 -> V_50 ) ;
F_22 ( V_32 ) ;
}
}
F_30 ( & V_27 -> V_116 ) ;
}
static void
F_81 ( struct V_20 * V_21 ,
struct V_26 * V_27 ,
struct V_119 * V_33 ,
const char * V_59 )
{
bool V_137 = true ;
struct V_11 * V_12 ;
struct V_31 * V_32 ;
F_5 () ;
V_12 = & V_27 -> V_81 ;
F_6 (orig_entry, head, list) {
if ( V_32 -> V_33 != V_33 ) {
V_137 = false ;
break;
}
}
F_9 () ;
if ( V_137 ) {
V_27 -> V_25 . V_40 |= V_71 ;
V_27 -> V_82 = V_68 ;
} else
F_80 ( V_21 , V_27 ,
V_33 , V_59 ) ;
}
static void F_82 ( struct V_20 * V_21 ,
struct V_119 * V_33 ,
const unsigned char * V_46 ,
const char * V_59 , bool V_112 )
{
struct V_26 * V_27 ;
struct V_19 * V_138 = NULL ;
V_27 = F_11 ( V_21 , V_46 ) ;
if ( ! V_27 )
goto V_73;
if ( ! V_112 ) {
F_80 ( V_21 , V_27 ,
V_33 , V_59 ) ;
if ( F_83 ( & V_27 -> V_81 ) )
F_36 ( V_21 , V_27 ,
V_59 ) ;
goto V_73;
}
V_138 = F_10 ( V_21 ,
V_27 -> V_25 . V_46 ) ;
if ( V_138 ) {
F_18 ( V_27 ) ;
F_36 ( V_21 , V_27 , V_59 ) ;
} else
F_81 ( V_21 , V_27 ,
V_33 , V_59 ) ;
V_73:
if ( V_27 )
F_17 ( V_27 ) ;
if ( V_138 )
F_12 ( V_138 ) ;
}
void F_84 ( struct V_20 * V_21 ,
struct V_119 * V_33 ,
const char * V_59 )
{
struct V_26 * V_58 ;
struct V_5 * V_13 ;
T_1 V_104 ;
struct V_8 * V_9 = V_21 -> V_23 . V_28 ;
struct V_1 * V_39 ;
struct V_11 * V_12 ;
T_4 * V_116 ;
if ( ! V_9 )
return;
for ( V_104 = 0 ; V_104 < V_9 -> V_16 ; V_104 ++ ) {
V_12 = & V_9 -> V_17 [ V_104 ] ;
V_116 = & V_9 -> V_117 [ V_104 ] ;
F_26 ( V_116 ) ;
F_59 (tt_common_entry, safe,
head, hash_entry) {
V_58 = F_2 ( V_13 ,
struct V_26 ,
V_25 ) ;
F_80 ( V_21 , V_58 ,
V_33 , V_59 ) ;
if ( F_83 ( & V_58 -> V_81 ) ) {
F_37 ( V_60 , V_21 ,
L_1 ,
V_58 -> V_25 . V_46 , V_59 ) ;
F_57 ( & V_13 -> V_6 ) ;
F_17 ( V_58 ) ;
}
}
F_30 ( V_116 ) ;
}
V_33 -> V_139 = false ;
}
static bool F_85 ( struct V_26 * V_58 ,
char * * V_140 )
{
bool V_141 = false ;
unsigned long V_142 = V_143 ;
unsigned long V_144 = V_145 ;
if ( ( V_58 -> V_25 . V_40 & V_71 ) &&
F_60 ( V_58 -> V_82 , V_142 ) ) {
V_141 = true ;
* V_140 = L_25 ;
}
if ( ( V_58 -> V_25 . V_40 & V_126 ) &&
F_60 ( V_58 -> V_25 . V_77 , V_144 ) ) {
V_141 = true ;
* V_140 = L_26 ;
}
return V_141 ;
}
static void F_86 ( struct V_20 * V_21 )
{
struct V_8 * V_9 = V_21 -> V_23 . V_28 ;
struct V_11 * V_12 ;
struct V_1 * V_114 ;
T_4 * V_116 ;
T_1 V_104 ;
char * V_140 = NULL ;
struct V_5 * V_146 ;
struct V_26 * V_58 ;
for ( V_104 = 0 ; V_104 < V_9 -> V_16 ; V_104 ++ ) {
V_12 = & V_9 -> V_17 [ V_104 ] ;
V_116 = & V_9 -> V_117 [ V_104 ] ;
F_26 ( V_116 ) ;
F_59 (tt_common, node_tmp, head,
hash_entry) {
V_58 = F_2 ( V_146 ,
struct V_26 ,
V_25 ) ;
if ( ! F_85 ( V_58 , & V_140 ) )
continue;
F_37 ( V_60 , V_21 ,
L_27 ,
V_58 -> V_25 . V_46 , V_140 ) ;
F_57 ( & V_146 -> V_6 ) ;
F_17 ( V_58 ) ;
}
F_30 ( V_116 ) ;
}
}
static void F_87 ( struct V_20 * V_21 )
{
struct V_8 * V_9 ;
T_4 * V_116 ;
struct V_5 * V_13 ;
struct V_26 * V_58 ;
struct V_1 * V_114 ;
struct V_11 * V_12 ;
T_1 V_104 ;
if ( ! V_21 -> V_23 . V_28 )
return;
V_9 = V_21 -> V_23 . V_28 ;
for ( V_104 = 0 ; V_104 < V_9 -> V_16 ; V_104 ++ ) {
V_12 = & V_9 -> V_17 [ V_104 ] ;
V_116 = & V_9 -> V_117 [ V_104 ] ;
F_26 ( V_116 ) ;
F_59 (tt_common_entry, node_tmp,
head, hash_entry) {
F_57 ( & V_13 -> V_6 ) ;
V_58 = F_2 ( V_13 ,
struct V_26 ,
V_25 ) ;
F_17 ( V_58 ) ;
}
F_30 ( V_116 ) ;
}
F_63 ( V_9 ) ;
V_21 -> V_23 . V_28 = NULL ;
}
static bool
F_88 ( struct V_19 * V_22 ,
struct V_26 * V_27 )
{
bool V_124 = false ;
if ( V_22 -> V_25 . V_40 & V_76 &&
V_27 -> V_25 . V_40 & V_76 )
V_124 = true ;
return V_124 ;
}
struct V_119 * F_89 ( struct V_20 * V_21 ,
const T_2 * V_147 ,
const T_2 * V_46 )
{
struct V_19 * V_22 = NULL ;
struct V_26 * V_27 = NULL ;
struct V_119 * V_33 = NULL ;
struct V_31 * V_132 ;
if ( V_147 && F_41 ( & V_21 -> V_148 ) ) {
V_22 = F_10 ( V_21 , V_147 ) ;
if ( ! V_22 ||
( V_22 -> V_25 . V_40 & V_69 ) )
goto V_73;
}
V_27 = F_11 ( V_21 , V_46 ) ;
if ( ! V_27 )
goto V_73;
if ( V_22 &&
F_88 ( V_22 , V_27 ) )
goto V_73;
F_5 () ;
V_132 = F_75 ( V_27 ) ;
if ( V_132 )
V_33 = V_132 -> V_33 ;
if ( V_33 && ! F_8 ( & V_33 -> V_18 ) )
V_33 = NULL ;
F_9 () ;
V_73:
if ( V_27 )
F_17 ( V_27 ) ;
if ( V_22 )
F_12 ( V_22 ) ;
return V_33 ;
}
static T_3 F_90 ( struct V_20 * V_21 ,
struct V_119 * V_33 )
{
T_3 V_149 = 0 , V_150 ;
struct V_8 * V_9 = V_21 -> V_23 . V_28 ;
struct V_5 * V_146 ;
struct V_26 * V_58 ;
struct V_11 * V_12 ;
T_1 V_104 ;
int V_151 ;
for ( V_104 = 0 ; V_104 < V_9 -> V_16 ; V_104 ++ ) {
V_12 = & V_9 -> V_17 [ V_104 ] ;
F_5 () ;
F_6 (tt_common, head, hash_entry) {
V_58 = F_2 ( V_146 ,
struct V_26 ,
V_25 ) ;
if ( V_146 -> V_40 & V_71 )
continue;
if ( V_146 -> V_40 & V_126 )
continue;
if ( ! F_67 ( V_58 ,
V_33 ) )
continue;
V_150 = 0 ;
for ( V_151 = 0 ; V_151 < V_7 ; V_151 ++ )
V_150 = F_91 ( V_150 ,
V_146 -> V_46 [ V_151 ] ) ;
V_149 ^= V_150 ;
}
F_9 () ;
}
return V_149 ;
}
static T_3 F_92 ( struct V_20 * V_21 )
{
T_3 V_149 = 0 , V_150 ;
struct V_8 * V_9 = V_21 -> V_23 . V_24 ;
struct V_5 * V_146 ;
struct V_11 * V_12 ;
T_1 V_104 ;
int V_151 ;
for ( V_104 = 0 ; V_104 < V_9 -> V_16 ; V_104 ++ ) {
V_12 = & V_9 -> V_17 [ V_104 ] ;
F_5 () ;
F_6 (tt_common, head, hash_entry) {
if ( V_146 -> V_40 & V_75 )
continue;
V_150 = 0 ;
for ( V_151 = 0 ; V_151 < V_7 ; V_151 ++ )
V_150 = F_91 ( V_150 ,
V_146 -> V_46 [ V_151 ] ) ;
V_149 ^= V_150 ;
}
F_9 () ;
}
return V_149 ;
}
static void F_93 ( struct V_20 * V_21 )
{
struct V_152 * V_2 , * V_39 ;
F_26 ( & V_21 -> V_23 . V_153 ) ;
F_27 (node, safe, &bat_priv->tt.req_list, list) {
F_28 ( & V_2 -> V_50 ) ;
F_16 ( V_2 ) ;
}
F_30 ( & V_21 -> V_23 . V_153 ) ;
}
static void F_94 ( struct V_20 * V_21 ,
struct V_119 * V_33 ,
const unsigned char * V_93 ,
T_2 V_154 )
{
T_3 V_155 = F_32 ( V_154 ) ;
F_26 ( & V_33 -> V_156 ) ;
if ( V_155 > 0 ) {
F_16 ( V_33 -> V_93 ) ;
V_33 -> V_155 = 0 ;
V_33 -> V_93 = F_25 ( V_155 , V_44 ) ;
if ( V_33 -> V_93 ) {
memcpy ( V_33 -> V_93 , V_93 , V_155 ) ;
V_33 -> V_155 = V_155 ;
}
}
F_30 ( & V_33 -> V_156 ) ;
}
static void F_95 ( struct V_20 * V_21 )
{
struct V_152 * V_2 , * V_39 ;
F_26 ( & V_21 -> V_23 . V_153 ) ;
F_27 (node, safe, &bat_priv->tt.req_list, list) {
if ( F_60 ( V_2 -> V_157 ,
V_158 ) ) {
F_28 ( & V_2 -> V_50 ) ;
F_16 ( V_2 ) ;
}
}
F_30 ( & V_21 -> V_23 . V_153 ) ;
}
static struct V_152 *
F_96 ( struct V_20 * V_21 ,
struct V_119 * V_33 )
{
struct V_152 * V_159 , * V_160 = NULL ;
F_26 ( & V_21 -> V_23 . V_153 ) ;
F_97 (tt_req_node_tmp, &bat_priv->tt.req_list, list) {
if ( F_7 ( V_159 , V_33 ) &&
! F_60 ( V_159 -> V_157 ,
V_158 ) )
goto V_51;
}
V_160 = F_25 ( sizeof( * V_160 ) , V_44 ) ;
if ( ! V_160 )
goto V_51;
memcpy ( V_160 -> V_46 , V_33 -> V_129 , V_7 ) ;
V_160 -> V_157 = V_68 ;
F_98 ( & V_160 -> V_50 , & V_21 -> V_23 . V_161 ) ;
V_51:
F_30 ( & V_21 -> V_23 . V_153 ) ;
return V_160 ;
}
static int F_99 ( const void * V_162 ,
const void * V_163 )
{
const struct V_5 * V_13 = V_162 ;
if ( V_13 -> V_40 & V_75 )
return 0 ;
return 1 ;
}
static int F_100 ( const void * V_162 ,
const void * V_163 )
{
const struct V_5 * V_13 = V_162 ;
const struct V_26 * V_27 ;
const struct V_119 * V_33 = V_163 ;
if ( V_13 -> V_40 & V_71 ||
V_13 -> V_40 & V_126 )
return 0 ;
V_27 = F_2 ( V_13 ,
struct V_26 ,
V_25 ) ;
return F_67 ( V_27 , V_33 ) ;
}
static struct V_164 *
F_101 ( T_3 V_165 , T_2 V_122 ,
struct V_8 * V_9 ,
struct V_20 * V_21 ,
int (* F_102)( const void * , const void * ) ,
void * V_166 )
{
struct V_5 * V_13 ;
struct V_167 * V_168 ;
struct V_55 * V_169 ;
struct V_11 * V_12 ;
struct V_164 * V_170 = NULL ;
T_3 V_171 , V_172 ;
T_5 V_173 = sizeof( struct V_167 ) ;
T_1 V_104 ;
T_6 V_174 ;
if ( V_173 + V_165 > V_21 -> V_62 -> V_89 ) {
V_165 = V_21 -> V_62 -> V_89 - V_173 ;
V_165 -= V_165 % sizeof( struct V_55 ) ;
}
V_171 = V_165 / sizeof( struct V_55 ) ;
V_174 = V_173 + V_165 ;
V_170 = F_103 ( NULL , V_174 + V_175 ) ;
if ( ! V_170 )
goto V_73;
V_170 -> V_176 = V_177 ;
F_104 ( V_170 , V_175 ) ;
V_168 = (struct V_167 * ) F_105 ( V_170 , V_174 ) ;
V_168 -> V_122 = V_122 ;
V_169 = (struct V_55 * ) ( V_170 -> V_10 + V_173 ) ;
V_172 = 0 ;
F_5 () ;
for ( V_104 = 0 ; V_104 < V_9 -> V_16 ; V_104 ++ ) {
V_12 = & V_9 -> V_17 [ V_104 ] ;
F_6 (tt_common_entry,
head, hash_entry) {
if ( V_172 == V_171 )
break;
if ( ( F_102 ) && ( ! F_102 ( V_13 , V_166 ) ) )
continue;
memcpy ( V_169 -> V_46 , V_13 -> V_46 ,
V_7 ) ;
V_169 -> V_40 = V_13 -> V_40 ;
V_172 ++ ;
V_169 ++ ;
}
}
F_9 () ;
V_168 -> V_178 = F_106 ( V_172 ) ;
V_73:
return V_170 ;
}
static int F_107 ( struct V_20 * V_21 ,
struct V_119 * V_179 ,
T_2 V_122 , T_3 V_136 ,
bool V_180 )
{
struct V_164 * V_170 = NULL ;
struct V_167 * V_181 ;
struct V_102 * V_103 ;
struct V_152 * V_160 = NULL ;
int V_124 = 1 ;
T_6 V_182 ;
V_103 = F_108 ( V_21 ) ;
if ( ! V_103 )
goto V_73;
V_160 = F_96 ( V_21 , V_179 ) ;
if ( ! V_160 )
goto V_73;
V_170 = F_103 ( NULL , sizeof( * V_181 ) + V_175 ) ;
if ( ! V_170 )
goto V_73;
V_170 -> V_176 = V_177 ;
F_104 ( V_170 , V_175 ) ;
V_182 = sizeof( * V_181 ) ;
V_181 = (struct V_167 * ) F_105 ( V_170 , V_182 ) ;
V_181 -> V_183 . V_184 = V_185 ;
V_181 -> V_183 . V_186 = V_187 ;
memcpy ( V_181 -> V_147 , V_103 -> V_100 -> V_78 , V_7 ) ;
memcpy ( V_181 -> V_188 , V_179 -> V_129 , V_7 ) ;
V_181 -> V_183 . V_189 = V_190 ;
V_181 -> V_122 = V_122 ;
V_181 -> V_178 = F_106 ( V_136 ) ;
V_181 -> V_40 = V_191 ;
if ( V_180 )
V_181 -> V_40 |= V_192 ;
F_37 ( V_60 , V_21 , L_28 ,
V_179 -> V_129 , ( V_180 ? 'F' : '.' ) ) ;
F_109 ( V_21 , V_193 ) ;
if ( F_110 ( V_170 , V_179 , NULL ) != V_194 )
V_124 = 0 ;
V_73:
if ( V_103 )
F_54 ( V_103 ) ;
if ( V_124 )
F_111 ( V_170 ) ;
if ( V_124 && V_160 ) {
F_26 ( & V_21 -> V_23 . V_153 ) ;
F_28 ( & V_160 -> V_50 ) ;
F_30 ( & V_21 -> V_23 . V_153 ) ;
F_16 ( V_160 ) ;
}
return V_124 ;
}
static bool
F_112 ( struct V_20 * V_21 ,
struct V_167 * V_181 )
{
struct V_119 * V_195 ;
struct V_119 * V_196 = NULL ;
T_2 V_197 , V_198 , V_122 ;
int V_199 , V_124 = false ;
unsigned char * V_93 ;
bool V_180 ;
T_3 V_165 , V_171 ;
struct V_164 * V_170 = NULL ;
struct V_167 * V_168 ;
T_2 * V_200 ;
T_6 V_174 ;
F_37 ( V_60 , V_21 ,
L_29 ,
V_181 -> V_147 , V_181 -> V_122 , V_181 -> V_188 ,
( V_181 -> V_40 & V_192 ? 'F' : '.' ) ) ;
V_195 = F_113 ( V_21 , V_181 -> V_188 ) ;
if ( ! V_195 )
goto V_73;
V_196 = F_113 ( V_21 , V_181 -> V_147 ) ;
if ( ! V_196 )
goto V_73;
V_197 = ( T_2 ) F_41 ( & V_195 -> V_135 ) ;
V_198 = V_181 -> V_122 ;
if ( V_197 != V_198 ||
V_181 -> V_178 != F_106 ( V_195 -> V_136 ) )
goto V_73;
if ( V_181 -> V_40 & V_192 ||
! V_195 -> V_93 )
V_180 = true ;
else
V_180 = false ;
if ( ! V_180 ) {
F_26 ( & V_195 -> V_156 ) ;
V_165 = V_195 -> V_155 ;
V_171 = V_165 / sizeof( struct V_55 ) ;
V_174 = sizeof( * V_168 ) + V_165 ;
V_170 = F_103 ( NULL , V_174 + V_175 ) ;
if ( ! V_170 )
goto V_51;
V_170 -> V_176 = V_177 ;
F_104 ( V_170 , V_175 ) ;
V_200 = F_105 ( V_170 , V_174 ) ;
V_168 = (struct V_167 * ) V_200 ;
V_168 -> V_122 = V_198 ;
V_168 -> V_178 = F_106 ( V_171 ) ;
V_93 = V_170 -> V_10 + sizeof( * V_168 ) ;
memcpy ( V_93 , V_195 -> V_93 ,
V_195 -> V_155 ) ;
F_30 ( & V_195 -> V_156 ) ;
} else {
V_165 = ( T_3 ) F_41 ( & V_195 -> V_34 ) ;
V_165 *= sizeof( struct V_55 ) ;
V_122 = ( T_2 ) F_41 ( & V_195 -> V_135 ) ;
V_170 = F_101 ( V_165 , V_122 ,
V_21 -> V_23 . V_28 ,
V_21 ,
F_100 ,
V_195 ) ;
if ( ! V_170 )
goto V_73;
V_168 = (struct V_167 * ) V_170 -> V_10 ;
}
V_168 -> V_183 . V_184 = V_185 ;
V_168 -> V_183 . V_186 = V_187 ;
V_168 -> V_183 . V_189 = V_190 ;
memcpy ( V_168 -> V_147 , V_195 -> V_129 , V_7 ) ;
memcpy ( V_168 -> V_188 , V_181 -> V_147 , V_7 ) ;
V_168 -> V_40 = V_201 ;
if ( V_180 )
V_168 -> V_40 |= V_192 ;
F_37 ( V_60 , V_21 ,
L_30 ,
V_196 -> V_129 , V_195 -> V_129 , V_198 ) ;
F_109 ( V_21 , V_202 ) ;
V_199 = F_110 ( V_170 , V_196 , NULL ) ;
if ( V_199 != V_194 )
V_124 = true ;
goto V_73;
V_51:
F_30 ( & V_195 -> V_156 ) ;
V_73:
if ( V_196 )
F_114 ( V_196 ) ;
if ( V_195 )
F_114 ( V_195 ) ;
if ( ! V_124 )
F_111 ( V_170 ) ;
return V_124 ;
}
static bool
F_115 ( struct V_20 * V_21 ,
struct V_167 * V_181 )
{
struct V_119 * V_33 ;
struct V_102 * V_103 = NULL ;
T_2 V_203 , V_198 , V_122 ;
int V_124 = false ;
unsigned char * V_93 ;
bool V_180 ;
T_3 V_165 , V_171 ;
struct V_164 * V_170 = NULL ;
struct V_167 * V_168 ;
T_2 * V_200 ;
T_6 V_174 ;
F_37 ( V_60 , V_21 ,
L_31 ,
V_181 -> V_147 , V_181 -> V_122 ,
( V_181 -> V_40 & V_192 ? 'F' : '.' ) ) ;
V_203 = ( T_2 ) F_41 ( & V_21 -> V_23 . V_74 ) ;
V_198 = V_181 -> V_122 ;
V_33 = F_113 ( V_21 , V_181 -> V_147 ) ;
if ( ! V_33 )
goto V_73;
V_103 = F_108 ( V_21 ) ;
if ( ! V_103 )
goto V_73;
if ( V_181 -> V_40 & V_192 || V_203 != V_198 ||
! V_21 -> V_23 . V_95 )
V_180 = true ;
else
V_180 = false ;
if ( ! V_180 ) {
F_26 ( & V_21 -> V_23 . V_94 ) ;
V_165 = V_21 -> V_23 . V_96 ;
V_171 = V_165 / sizeof( struct V_55 ) ;
V_174 = sizeof( * V_168 ) + V_165 ;
V_170 = F_103 ( NULL , V_174 + V_175 ) ;
if ( ! V_170 )
goto V_51;
V_170 -> V_176 = V_177 ;
F_104 ( V_170 , V_175 ) ;
V_200 = F_105 ( V_170 , V_174 ) ;
V_168 = (struct V_167 * ) V_200 ;
V_168 -> V_122 = V_198 ;
V_168 -> V_178 = F_106 ( V_171 ) ;
V_93 = V_170 -> V_10 + sizeof( * V_168 ) ;
memcpy ( V_93 , V_21 -> V_23 . V_95 ,
V_21 -> V_23 . V_96 ) ;
F_30 ( & V_21 -> V_23 . V_94 ) ;
} else {
V_165 = ( T_3 ) F_41 ( & V_21 -> V_23 . V_204 ) ;
V_165 *= sizeof( struct V_55 ) ;
V_122 = ( T_2 ) F_41 ( & V_21 -> V_23 . V_74 ) ;
V_170 = F_101 ( V_165 , V_122 ,
V_21 -> V_23 . V_24 ,
V_21 ,
F_99 ,
NULL ) ;
if ( ! V_170 )
goto V_73;
V_168 = (struct V_167 * ) V_170 -> V_10 ;
}
V_168 -> V_183 . V_184 = V_185 ;
V_168 -> V_183 . V_186 = V_187 ;
V_168 -> V_183 . V_189 = V_190 ;
memcpy ( V_168 -> V_147 , V_103 -> V_100 -> V_78 , V_7 ) ;
memcpy ( V_168 -> V_188 , V_181 -> V_147 , V_7 ) ;
V_168 -> V_40 = V_201 ;
if ( V_180 )
V_168 -> V_40 |= V_192 ;
F_37 ( V_60 , V_21 ,
L_32 ,
V_33 -> V_129 ,
( V_168 -> V_40 & V_192 ? 'F' : '.' ) ) ;
F_109 ( V_21 , V_202 ) ;
if ( F_110 ( V_170 , V_33 , NULL ) != V_194 )
V_124 = true ;
goto V_73;
V_51:
F_30 ( & V_21 -> V_23 . V_94 ) ;
V_73:
if ( V_33 )
F_114 ( V_33 ) ;
if ( V_103 )
F_54 ( V_103 ) ;
if ( ! V_124 )
F_111 ( V_170 ) ;
return true ;
}
bool F_116 ( struct V_20 * V_21 ,
struct V_167 * V_181 )
{
if ( F_117 ( V_21 , V_181 -> V_188 ) ) {
if ( F_118 ( V_21 , V_181 -> V_147 ) )
return true ;
return F_115 ( V_21 , V_181 ) ;
} else {
return F_112 ( V_21 , V_181 ) ;
}
}
static void F_119 ( struct V_20 * V_21 ,
struct V_119 * V_33 ,
struct V_55 * V_169 ,
T_3 V_154 , T_2 V_122 )
{
int V_104 ;
int V_205 ;
for ( V_104 = 0 ; V_104 < V_154 ; V_104 ++ ) {
if ( ( V_169 + V_104 ) -> V_40 & V_47 ) {
V_205 = ( V_169 + V_104 ) -> V_40 & V_71 ;
F_82 ( V_21 , V_33 ,
( V_169 + V_104 ) -> V_46 ,
L_33 ,
V_205 ) ;
} else {
if ( ! F_72 ( V_21 , V_33 ,
( V_169 + V_104 ) -> V_46 ,
( V_169 + V_104 ) -> V_40 , V_122 ) )
return;
}
}
V_33 -> V_139 = true ;
}
static void F_120 ( struct V_20 * V_21 ,
struct V_167 * V_168 )
{
struct V_119 * V_33 ;
V_33 = F_113 ( V_21 , V_168 -> V_147 ) ;
if ( ! V_33 )
goto V_73;
F_84 ( V_21 , V_33 , L_34 ) ;
F_119 ( V_21 , V_33 ,
(struct V_55 * ) ( V_168 + 1 ) ,
F_121 ( V_168 -> V_178 ) ,
V_168 -> V_122 ) ;
F_26 ( & V_33 -> V_156 ) ;
F_16 ( V_33 -> V_93 ) ;
V_33 -> V_155 = 0 ;
V_33 -> V_93 = NULL ;
F_30 ( & V_33 -> V_156 ) ;
F_43 ( & V_33 -> V_135 , V_168 -> V_122 ) ;
V_73:
if ( V_33 )
F_114 ( V_33 ) ;
}
static void F_122 ( struct V_20 * V_21 ,
struct V_119 * V_33 ,
T_3 V_154 , T_2 V_122 ,
struct V_55 * V_169 )
{
F_119 ( V_21 , V_33 , V_169 ,
V_154 , V_122 ) ;
F_94 ( V_21 , V_33 ,
( unsigned char * ) V_169 , V_154 ) ;
F_43 ( & V_33 -> V_135 , V_122 ) ;
}
bool F_123 ( struct V_20 * V_21 , const T_2 * V_46 )
{
struct V_19 * V_22 ;
bool V_124 = false ;
V_22 = F_10 ( V_21 , V_46 ) ;
if ( ! V_22 )
goto V_73;
if ( ( V_22 -> V_25 . V_40 & V_69 ) ||
( V_22 -> V_25 . V_40 & V_71 ) )
goto V_73;
V_124 = true ;
V_73:
if ( V_22 )
F_12 ( V_22 ) ;
return V_124 ;
}
void F_124 ( struct V_20 * V_21 ,
struct V_167 * V_168 )
{
struct V_152 * V_2 , * V_39 ;
struct V_119 * V_33 = NULL ;
struct V_55 * V_169 ;
F_37 ( V_60 , V_21 ,
L_35 ,
V_168 -> V_147 , V_168 -> V_122 ,
F_121 ( V_168 -> V_178 ) ,
( V_168 -> V_40 & V_192 ? 'F' : '.' ) ) ;
if ( F_118 ( V_21 , V_168 -> V_147 ) )
goto V_73;
V_33 = F_113 ( V_21 , V_168 -> V_147 ) ;
if ( ! V_33 )
goto V_73;
if ( V_168 -> V_40 & V_192 ) {
F_120 ( V_21 , V_168 ) ;
} else {
V_169 = (struct V_55 * ) ( V_168 + 1 ) ;
F_122 ( V_21 , V_33 ,
F_121 ( V_168 -> V_178 ) ,
V_168 -> V_122 , V_169 ) ;
}
F_26 ( & V_21 -> V_23 . V_153 ) ;
F_27 (node, safe, &bat_priv->tt.req_list, list) {
if ( ! F_7 ( V_2 -> V_46 , V_168 -> V_147 ) )
continue;
F_28 ( & V_2 -> V_50 ) ;
F_16 ( V_2 ) ;
}
F_30 ( & V_21 -> V_23 . V_153 ) ;
V_33 -> V_136 = F_90 ( V_21 , V_33 ) ;
V_73:
if ( V_33 )
F_114 ( V_33 ) ;
}
int F_125 ( struct V_20 * V_21 )
{
int V_124 ;
V_124 = F_33 ( V_21 ) ;
if ( V_124 < 0 )
return V_124 ;
V_124 = F_64 ( V_21 ) ;
if ( V_124 < 0 )
return V_124 ;
F_126 ( & V_21 -> V_23 . V_206 , V_207 ) ;
F_127 ( V_208 , & V_21 -> V_23 . V_206 ,
F_128 ( V_209 ) ) ;
return 1 ;
}
static void F_129 ( struct V_20 * V_21 )
{
struct V_210 * V_2 , * V_39 ;
F_26 ( & V_21 -> V_23 . V_211 ) ;
F_27 (node, safe, &bat_priv->tt.roam_list, list) {
F_28 ( & V_2 -> V_50 ) ;
F_16 ( V_2 ) ;
}
F_30 ( & V_21 -> V_23 . V_211 ) ;
}
static void F_130 ( struct V_20 * V_21 )
{
struct V_210 * V_2 , * V_39 ;
F_26 ( & V_21 -> V_23 . V_211 ) ;
F_27 (node, safe, &bat_priv->tt.roam_list, list) {
if ( ! F_60 ( V_2 -> V_212 ,
V_213 ) )
continue;
F_28 ( & V_2 -> V_50 ) ;
F_16 ( V_2 ) ;
}
F_30 ( & V_21 -> V_23 . V_211 ) ;
}
static bool F_131 ( struct V_20 * V_21 ,
T_2 * V_214 )
{
struct V_210 * V_215 ;
bool V_124 = false ;
F_26 ( & V_21 -> V_23 . V_211 ) ;
F_97 (tt_roam_node, &bat_priv->tt.roam_list, list) {
if ( ! F_7 ( V_215 -> V_46 , V_214 ) )
continue;
if ( F_60 ( V_215 -> V_212 ,
V_213 ) )
continue;
if ( ! F_132 ( & V_215 -> V_216 ) )
goto V_51;
V_124 = true ;
break;
}
if ( ! V_124 ) {
V_215 = F_25 ( sizeof( * V_215 ) , V_44 ) ;
if ( ! V_215 )
goto V_51;
V_215 -> V_212 = V_68 ;
F_43 ( & V_215 -> V_216 ,
V_217 - 1 ) ;
memcpy ( V_215 -> V_46 , V_214 , V_7 ) ;
F_98 ( & V_215 -> V_50 , & V_21 -> V_23 . V_218 ) ;
V_124 = true ;
}
V_51:
F_30 ( & V_21 -> V_23 . V_211 ) ;
return V_124 ;
}
static void F_46 ( struct V_20 * V_21 , T_2 * V_214 ,
struct V_119 * V_33 )
{
struct V_164 * V_170 = NULL ;
struct V_219 * V_220 ;
int V_124 = 1 ;
struct V_102 * V_103 ;
T_6 V_174 = sizeof( * V_220 ) ;
if ( ! F_131 ( V_21 , V_214 ) )
goto V_73;
V_170 = F_103 ( NULL , V_174 + V_175 ) ;
if ( ! V_170 )
goto V_73;
V_170 -> V_176 = V_177 ;
F_104 ( V_170 , V_175 ) ;
V_220 = (struct V_219 * ) F_105 ( V_170 , V_174 ) ;
V_220 -> V_183 . V_184 = V_221 ;
V_220 -> V_183 . V_186 = V_187 ;
V_220 -> V_183 . V_189 = V_190 ;
V_220 -> V_222 = 0 ;
V_103 = F_108 ( V_21 ) ;
if ( ! V_103 )
goto V_73;
memcpy ( V_220 -> V_147 , V_103 -> V_100 -> V_78 , V_7 ) ;
F_54 ( V_103 ) ;
memcpy ( V_220 -> V_188 , V_33 -> V_129 , V_7 ) ;
memcpy ( V_220 -> V_214 , V_214 , V_7 ) ;
F_37 ( V_60 , V_21 ,
L_36 ,
V_33 -> V_129 , V_214 ) ;
F_109 ( V_21 , V_223 ) ;
if ( F_110 ( V_170 , V_33 , NULL ) != V_194 )
V_124 = 0 ;
V_73:
if ( V_124 && V_170 )
F_111 ( V_170 ) ;
return;
}
static void V_207 ( struct V_224 * V_206 )
{
struct V_225 * V_225 ;
struct V_226 * V_227 ;
struct V_20 * V_21 ;
V_225 = F_2 ( V_206 , struct V_225 , V_206 ) ;
V_227 = F_2 ( V_225 , struct V_226 , V_206 ) ;
V_21 = F_2 ( V_227 , struct V_20 , V_23 ) ;
F_61 ( V_21 ) ;
F_86 ( V_21 ) ;
F_95 ( V_21 ) ;
F_130 ( V_21 ) ;
F_127 ( V_208 , & V_21 -> V_23 . V_206 ,
F_128 ( V_209 ) ) ;
}
void F_133 ( struct V_20 * V_21 )
{
F_134 ( & V_21 -> V_23 . V_206 ) ;
F_62 ( V_21 ) ;
F_87 ( V_21 ) ;
F_93 ( V_21 ) ;
F_65 ( V_21 ) ;
F_129 ( V_21 ) ;
F_16 ( V_21 -> V_23 . V_95 ) ;
}
static T_3 F_135 ( struct V_8 * V_9 ,
T_3 V_40 , bool V_228 )
{
T_1 V_104 ;
T_3 V_229 = 0 ;
struct V_11 * V_12 ;
struct V_5 * V_13 ;
if ( ! V_9 )
goto V_73;
for ( V_104 = 0 ; V_104 < V_9 -> V_16 ; V_104 ++ ) {
V_12 = & V_9 -> V_17 [ V_104 ] ;
F_5 () ;
F_6 (tt_common_entry,
head, hash_entry) {
if ( V_228 ) {
if ( ( V_13 -> V_40 & V_40 ) == V_40 )
continue;
V_13 -> V_40 |= V_40 ;
} else {
if ( ! ( V_13 -> V_40 & V_40 ) )
continue;
V_13 -> V_40 &= ~ V_40 ;
}
V_229 ++ ;
}
F_9 () ;
}
V_73:
return V_229 ;
}
static void F_136 ( struct V_20 * V_21 )
{
struct V_8 * V_9 = V_21 -> V_23 . V_24 ;
struct V_5 * V_146 ;
struct V_19 * V_64 ;
struct V_1 * V_114 ;
struct V_11 * V_12 ;
T_4 * V_116 ;
T_1 V_104 ;
if ( ! V_9 )
return;
for ( V_104 = 0 ; V_104 < V_9 -> V_16 ; V_104 ++ ) {
V_12 = & V_9 -> V_17 [ V_104 ] ;
V_116 = & V_9 -> V_117 [ V_104 ] ;
F_26 ( V_116 ) ;
F_59 (tt_common, node_tmp, head,
hash_entry) {
if ( ! ( V_146 -> V_40 & V_69 ) )
continue;
F_37 ( V_60 , V_21 ,
L_37 ,
V_146 -> V_46 ) ;
F_23 ( & V_21 -> V_23 . V_204 ) ;
F_57 ( & V_146 -> V_6 ) ;
V_64 = F_2 ( V_146 ,
struct V_19 ,
V_25 ) ;
F_12 ( V_64 ) ;
}
F_30 ( V_116 ) ;
}
}
static int F_137 ( struct V_20 * V_21 ,
unsigned char * * V_83 ,
int * V_84 , int V_230 )
{
T_3 V_229 = 0 ;
if ( F_41 ( & V_21 -> V_23 . V_53 ) < 1 )
return - V_231 ;
V_229 = F_135 ( V_21 -> V_23 . V_24 ,
V_75 , false ) ;
F_138 ( V_229 , & V_21 -> V_23 . V_204 ) ;
F_136 ( V_21 ) ;
V_21 -> V_23 . V_111 = F_92 ( V_21 ) ;
F_31 ( & V_21 -> V_23 . V_74 ) ;
F_37 ( V_60 , V_21 ,
L_38 ,
( T_2 ) F_41 ( & V_21 -> V_23 . V_74 ) ) ;
F_43 ( & V_21 -> V_23 . V_232 , V_233 ) ;
return F_49 ( V_21 , V_83 ,
V_84 , V_230 ) ;
}
int F_139 ( struct V_20 * V_21 ,
unsigned char * * V_83 , int * V_84 ,
int V_230 )
{
int V_154 ;
V_154 = F_137 ( V_21 , V_83 ,
V_84 ,
V_230 ) ;
if ( ( V_154 < 0 ) &&
( ! F_132 ( & V_21 -> V_23 . V_232 ) ) ) {
F_47 ( V_83 , V_84 ,
V_230 , V_230 ) ;
V_154 = 0 ;
}
return V_154 ;
}
bool F_140 ( struct V_20 * V_21 , T_2 * V_147 ,
T_2 * V_188 )
{
struct V_19 * V_22 = NULL ;
struct V_26 * V_27 = NULL ;
bool V_124 = false ;
if ( ! F_41 ( & V_21 -> V_148 ) )
goto V_73;
V_22 = F_10 ( V_21 , V_188 ) ;
if ( ! V_22 )
goto V_73;
V_27 = F_11 ( V_21 , V_147 ) ;
if ( ! V_27 )
goto V_73;
if ( ! F_88 ( V_22 , V_27 ) )
goto V_73;
V_124 = true ;
V_73:
if ( V_27 )
F_17 ( V_27 ) ;
if ( V_22 )
F_12 ( V_22 ) ;
return V_124 ;
}
void F_141 ( struct V_20 * V_21 ,
struct V_119 * V_33 ,
const unsigned char * V_93 , T_2 V_154 ,
T_2 V_122 , T_3 V_136 )
{
T_2 V_197 = ( T_2 ) F_41 ( & V_33 -> V_135 ) ;
bool V_180 = true ;
struct V_55 * V_169 ;
if ( F_118 ( V_21 , V_33 -> V_129 ) )
return;
if ( ( ! V_33 -> V_139 && V_122 == 1 ) ||
V_122 - V_197 == 1 ) {
if ( ! V_154 ) {
V_180 = false ;
goto V_234;
}
V_169 = (struct V_55 * ) V_93 ;
F_122 ( V_21 , V_33 , V_154 ,
V_122 , V_169 ) ;
V_33 -> V_136 = F_90 ( V_21 , V_33 ) ;
if ( V_33 -> V_136 != V_136 )
goto V_234;
} else {
if ( ! V_33 -> V_139 || V_122 != V_197 ||
V_33 -> V_136 != V_136 ) {
V_234:
F_37 ( V_60 , V_21 ,
L_39 ,
V_33 -> V_129 , V_122 , V_197 , V_136 ,
V_33 -> V_136 , V_154 ) ;
F_107 ( V_21 , V_33 , V_122 ,
V_136 , V_180 ) ;
return;
}
}
}
bool F_142 ( struct V_20 * V_21 ,
T_2 * V_46 )
{
struct V_26 * V_27 ;
bool V_124 = false ;
V_27 = F_11 ( V_21 , V_46 ) ;
if ( ! V_27 )
goto V_73;
V_124 = V_27 -> V_25 . V_40 & V_71 ;
F_17 ( V_27 ) ;
V_73:
return V_124 ;
}
bool F_143 ( struct V_20 * V_21 ,
T_2 * V_46 )
{
struct V_19 * V_22 ;
bool V_124 = false ;
V_22 = F_10 ( V_21 , V_46 ) ;
if ( ! V_22 )
goto V_73;
V_124 = V_22 -> V_25 . V_40 & V_71 ;
F_12 ( V_22 ) ;
V_73:
return V_124 ;
}
bool F_144 ( struct V_20 * V_21 ,
struct V_119 * V_33 ,
const unsigned char * V_46 )
{
bool V_124 = false ;
if ( F_118 ( V_21 , V_33 -> V_129 ) )
goto V_73;
if ( ! F_72 ( V_21 , V_33 , V_46 ,
V_126 ,
F_41 ( & V_33 -> V_135 ) ) )
goto V_73;
F_37 ( V_60 , V_21 ,
L_40 ,
V_46 , V_33 -> V_129 ) ;
V_124 = true ;
V_73:
return V_124 ;
}
