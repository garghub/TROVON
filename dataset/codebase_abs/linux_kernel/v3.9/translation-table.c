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
const T_2 * V_35 , T_2 V_36 )
{
struct V_37 * V_38 , * V_39 , * V_40 ;
bool V_41 = false ;
bool V_42 , V_43 ;
V_38 = F_25 ( sizeof( * V_38 ) , V_44 ) ;
if ( ! V_38 )
return;
V_38 -> V_45 . V_36 = V_36 ;
memcpy ( V_38 -> V_45 . V_35 , V_35 , V_7 ) ;
V_42 = V_36 & V_46 ;
F_26 ( & V_21 -> V_23 . V_47 ) ;
F_27 (entry, safe, &bat_priv->tt.changes_list,
list) {
if ( ! F_7 ( V_39 -> V_45 . V_35 , V_35 ) )
continue;
V_43 = V_39 -> V_45 . V_36 & V_46 ;
if ( ! V_42 && V_43 )
goto V_48;
if ( V_42 && ! V_43 )
goto V_48;
continue;
V_48:
F_28 ( & V_39 -> V_49 ) ;
F_16 ( V_39 ) ;
F_16 ( V_38 ) ;
V_41 = true ;
goto V_50;
}
F_29 ( & V_38 -> V_49 , & V_21 -> V_23 . V_51 ) ;
V_50:
F_30 ( & V_21 -> V_23 . V_47 ) ;
if ( V_41 )
F_23 ( & V_21 -> V_23 . V_52 ) ;
else
F_31 ( & V_21 -> V_23 . V_52 ) ;
}
int F_32 ( int V_53 )
{
return V_53 * sizeof( struct V_54 ) ;
}
static int F_33 ( struct V_20 * V_21 )
{
if ( V_21 -> V_23 . V_24 )
return 0 ;
V_21 -> V_23 . V_24 = F_34 ( 1024 ) ;
if ( ! V_21 -> V_23 . V_24 )
return - V_55 ;
F_35 ( V_21 -> V_23 . V_24 ,
& V_56 ) ;
return 0 ;
}
static void F_36 ( struct V_20 * V_21 ,
struct V_26 * V_57 ,
const char * V_58 )
{
F_37 ( V_59 , V_21 ,
L_1 ,
V_57 -> V_25 . V_35 , V_58 ) ;
F_38 ( V_21 -> V_23 . V_28 , F_1 ,
F_4 , V_57 -> V_25 . V_35 ) ;
F_17 ( V_57 ) ;
}
void F_39 ( struct V_60 * V_61 , const T_2 * V_35 ,
int V_62 )
{
struct V_20 * V_21 = F_40 ( V_61 ) ;
struct V_19 * V_63 ;
struct V_26 * V_57 ;
struct V_11 * V_12 ;
struct V_31 * V_32 ;
int V_64 ;
bool V_65 = false ;
V_63 = F_10 ( V_21 , V_35 ) ;
V_57 = F_11 ( V_21 , V_35 ) ;
if ( V_63 ) {
V_63 -> V_66 = V_67 ;
if ( V_63 -> V_25 . V_36 & V_68 ) {
F_37 ( V_59 , V_21 ,
L_2 , V_35 ) ;
V_63 -> V_25 . V_36 &= ~ V_68 ;
goto V_69;
}
if ( V_63 -> V_25 . V_36 & V_70 ) {
F_37 ( V_59 , V_21 ,
L_3 ,
V_35 ) ;
V_63 -> V_25 . V_36 &= ~ V_70 ;
V_65 = true ;
}
goto V_71;
}
V_63 = F_25 ( sizeof( * V_63 ) , V_44 ) ;
if ( ! V_63 )
goto V_72;
F_37 ( V_59 , V_21 ,
L_4 , V_35 ,
( T_2 ) F_41 ( & V_21 -> V_23 . V_73 ) ) ;
memcpy ( V_63 -> V_25 . V_35 , V_35 , V_7 ) ;
V_63 -> V_25 . V_36 = V_74 ;
if ( F_42 ( V_62 ) )
V_63 -> V_25 . V_36 |= V_75 ;
F_43 ( & V_63 -> V_25 . V_18 , 2 ) ;
V_63 -> V_66 = V_67 ;
V_63 -> V_25 . V_76 = V_63 -> V_66 ;
if ( F_7 ( V_35 , V_61 -> V_77 ) )
V_63 -> V_25 . V_36 |= V_78 ;
V_64 = F_44 ( V_21 -> V_23 . V_24 , F_1 ,
F_4 , & V_63 -> V_25 ,
& V_63 -> V_25 . V_6 ) ;
if ( F_45 ( V_64 != 0 ) ) {
F_12 ( V_63 ) ;
goto V_72;
}
V_69:
F_24 ( V_21 , V_35 , V_63 -> V_25 . V_36 ) ;
V_71:
if ( V_57 && ! ( V_57 -> V_25 . V_36 & V_70 ) ) {
V_12 = & V_57 -> V_79 ;
F_5 () ;
F_6 (orig_entry, head, list) {
F_46 ( V_21 , V_57 -> V_25 . V_35 ,
V_32 -> V_33 ) ;
}
F_9 () ;
if ( V_65 ) {
F_36 ( V_21 , V_57 ,
L_5 ) ;
V_57 = NULL ;
} else {
V_57 -> V_25 . V_36 |= V_70 ;
V_57 -> V_80 = V_67 ;
}
}
V_72:
if ( V_63 )
F_12 ( V_63 ) ;
if ( V_57 )
F_17 ( V_57 ) ;
}
static void F_47 ( unsigned char * * V_81 ,
int * V_82 ,
int V_83 ,
int V_84 )
{
unsigned char * V_85 ;
V_85 = F_25 ( V_84 , V_44 ) ;
if ( V_85 ) {
memcpy ( V_85 , * V_81 , V_83 ) ;
F_16 ( * V_81 ) ;
* V_81 = V_85 ;
* V_82 = V_84 ;
}
}
static void F_48 ( struct V_20 * V_21 ,
unsigned char * * V_81 ,
int * V_82 ,
int V_83 )
{
struct V_86 * V_87 ;
int V_88 ;
V_87 = F_49 ( V_21 ) ;
V_88 = V_83 ;
V_88 += F_32 ( F_41 ( & V_21 -> V_23 . V_52 ) ) ;
if ( ( ! V_87 ) || ( V_88 > V_87 -> V_61 -> V_89 ) )
V_88 = V_83 ;
F_47 ( V_81 , V_82 ,
V_83 , V_88 ) ;
if ( V_87 )
F_50 ( V_87 ) ;
}
static int F_51 ( struct V_20 * V_21 ,
unsigned char * * V_81 ,
int * V_82 ,
int V_83 )
{
struct V_37 * V_39 , * V_40 ;
int V_90 = 0 , V_91 = 0 , V_92 ;
unsigned char * V_93 ;
F_48 ( V_21 , V_81 ,
V_82 , V_83 ) ;
V_92 = * V_82 - V_83 ;
V_93 = * V_81 + V_83 ;
if ( V_92 > 0 )
V_91 = V_92 / F_32 ( 1 ) ;
F_26 ( & V_21 -> V_23 . V_47 ) ;
F_43 ( & V_21 -> V_23 . V_52 , 0 ) ;
F_27 (entry, safe, &bat_priv->tt.changes_list,
list) {
if ( V_90 < V_91 ) {
memcpy ( V_93 + F_32 ( V_90 ) ,
& V_39 -> V_45 , sizeof( struct V_54 ) ) ;
V_90 ++ ;
}
F_28 ( & V_39 -> V_49 ) ;
F_16 ( V_39 ) ;
}
F_30 ( & V_21 -> V_23 . V_47 ) ;
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
int F_52 ( struct V_97 * V_98 , void * V_99 )
{
struct V_60 * V_100 = (struct V_60 * ) V_98 -> V_101 ;
struct V_20 * V_21 = F_40 ( V_100 ) ;
struct V_8 * V_9 = V_21 -> V_23 . V_24 ;
struct V_5 * V_13 ;
struct V_19 * V_63 ;
struct V_86 * V_87 ;
struct V_11 * V_12 ;
T_1 V_102 ;
int V_103 ;
int V_104 ;
unsigned long V_105 ;
bool V_106 ;
T_3 V_107 = V_78 ;
V_87 = F_53 ( V_98 ) ;
if ( ! V_87 )
goto V_72;
F_54 ( V_98 ,
L_6 ,
V_100 -> V_108 , ( T_2 ) F_41 ( & V_21 -> V_23 . V_73 ) ,
V_21 -> V_23 . V_109 ) ;
F_54 ( V_98 , L_7 , L_8 , L_9 ,
L_10 ) ;
for ( V_102 = 0 ; V_102 < V_9 -> V_16 ; V_102 ++ ) {
V_12 = & V_9 -> V_17 [ V_102 ] ;
F_5 () ;
F_6 (tt_common_entry,
head, hash_entry) {
V_63 = F_2 ( V_13 ,
struct V_19 ,
V_25 ) ;
V_105 = V_67 - V_63 -> V_66 ;
V_104 = F_55 ( V_105 ) ;
V_103 = V_104 / 1000 ;
V_104 = V_104 % 1000 ;
V_106 = V_13 -> V_36 & V_107 ;
F_54 ( V_98 , L_11 ,
V_13 -> V_35 ,
( V_13 -> V_36 &
V_70 ? 'R' : '.' ) ,
V_106 ? 'P' : '.' ,
( V_13 -> V_36 &
V_74 ? 'N' : '.' ) ,
( V_13 -> V_36 &
V_68 ? 'X' : '.' ) ,
( V_13 -> V_36 &
V_75 ? 'W' : '.' ) ,
V_106 ? 0 : V_103 ,
V_106 ? 0 : V_104 ) ;
}
F_9 () ;
}
V_72:
if ( V_87 )
F_50 ( V_87 ) ;
return 0 ;
}
static void
F_56 ( struct V_20 * V_21 ,
struct V_19 * V_22 ,
T_3 V_36 , const char * V_58 )
{
F_24 ( V_21 , V_22 -> V_25 . V_35 ,
V_22 -> V_25 . V_36 | V_36 ) ;
V_22 -> V_25 . V_36 |= V_68 ;
F_37 ( V_59 , V_21 ,
L_12 ,
V_22 -> V_25 . V_35 , V_58 ) ;
}
T_3 F_57 ( struct V_20 * V_21 ,
const T_2 * V_35 , const char * V_58 ,
bool V_110 )
{
struct V_19 * V_22 ;
T_3 V_36 , V_111 = V_112 ;
V_22 = F_10 ( V_21 , V_35 ) ;
if ( ! V_22 )
goto V_72;
V_111 = V_22 -> V_25 . V_36 ;
V_36 = V_46 ;
if ( V_110 ) {
V_36 |= V_70 ;
V_22 -> V_25 . V_36 |= V_70 ;
}
if ( ! ( V_22 -> V_25 . V_36 & V_74 ) ) {
F_56 ( V_21 , V_22 , V_36 ,
V_58 ) ;
goto V_72;
}
F_24 ( V_21 , V_22 -> V_25 . V_35 ,
V_111 | V_46 ) ;
F_58 ( & V_22 -> V_25 . V_6 ) ;
F_12 ( V_22 ) ;
V_72:
if ( V_22 )
F_12 ( V_22 ) ;
return V_111 ;
}
static void F_59 ( struct V_20 * V_21 ,
struct V_11 * V_12 )
{
struct V_19 * V_22 ;
struct V_5 * V_13 ;
struct V_1 * V_113 ;
F_60 (tt_common_entry, node_tmp, head,
hash_entry) {
V_22 = F_2 ( V_13 ,
struct V_19 ,
V_25 ) ;
if ( V_22 -> V_25 . V_36 & V_78 )
continue;
if ( V_22 -> V_25 . V_36 & V_68 )
continue;
if ( ! F_61 ( V_22 -> V_66 ,
V_114 ) )
continue;
F_56 ( V_21 , V_22 ,
V_46 , L_13 ) ;
}
}
static void F_62 ( struct V_20 * V_21 )
{
struct V_8 * V_9 = V_21 -> V_23 . V_24 ;
struct V_11 * V_12 ;
T_4 * V_115 ;
T_1 V_102 ;
for ( V_102 = 0 ; V_102 < V_9 -> V_16 ; V_102 ++ ) {
V_12 = & V_9 -> V_17 [ V_102 ] ;
V_115 = & V_9 -> V_116 [ V_102 ] ;
F_26 ( V_115 ) ;
F_59 ( V_21 , V_12 ) ;
F_30 ( V_115 ) ;
}
}
static void F_63 ( struct V_20 * V_21 )
{
struct V_8 * V_9 ;
T_4 * V_115 ;
struct V_5 * V_13 ;
struct V_19 * V_63 ;
struct V_1 * V_113 ;
struct V_11 * V_12 ;
T_1 V_102 ;
if ( ! V_21 -> V_23 . V_24 )
return;
V_9 = V_21 -> V_23 . V_24 ;
for ( V_102 = 0 ; V_102 < V_9 -> V_16 ; V_102 ++ ) {
V_12 = & V_9 -> V_17 [ V_102 ] ;
V_115 = & V_9 -> V_116 [ V_102 ] ;
F_26 ( V_115 ) ;
F_60 (tt_common_entry, node_tmp,
head, hash_entry) {
F_58 ( & V_13 -> V_6 ) ;
V_63 = F_2 ( V_13 ,
struct V_19 ,
V_25 ) ;
F_12 ( V_63 ) ;
}
F_30 ( V_115 ) ;
}
F_64 ( V_9 ) ;
V_21 -> V_23 . V_24 = NULL ;
}
static int F_65 ( struct V_20 * V_21 )
{
if ( V_21 -> V_23 . V_28 )
return 0 ;
V_21 -> V_23 . V_28 = F_34 ( 1024 ) ;
if ( ! V_21 -> V_23 . V_28 )
return - V_55 ;
F_35 ( V_21 -> V_23 . V_28 ,
& V_117 ) ;
return 0 ;
}
static void F_66 ( struct V_20 * V_21 )
{
struct V_37 * V_39 , * V_40 ;
F_26 ( & V_21 -> V_23 . V_47 ) ;
F_27 (entry, safe, &bat_priv->tt.changes_list,
list) {
F_28 ( & V_39 -> V_49 ) ;
F_16 ( V_39 ) ;
}
F_43 ( & V_21 -> V_23 . V_52 , 0 ) ;
F_30 ( & V_21 -> V_23 . V_47 ) ;
}
static struct V_31 *
F_67 ( const struct V_26 * V_39 ,
const struct V_118 * V_33 )
{
struct V_31 * V_119 , * V_32 = NULL ;
const struct V_11 * V_12 ;
F_5 () ;
V_12 = & V_39 -> V_79 ;
F_6 (tmp_orig_entry, head, list) {
if ( V_119 -> V_33 != V_33 )
continue;
if ( ! F_8 ( & V_119 -> V_18 ) )
continue;
V_32 = V_119 ;
break;
}
F_9 () ;
return V_32 ;
}
static bool
F_68 ( const struct V_26 * V_39 ,
const struct V_118 * V_33 )
{
struct V_31 * V_32 ;
bool V_120 = false ;
V_32 = F_67 ( V_39 , V_33 ) ;
if ( V_32 ) {
V_120 = true ;
F_22 ( V_32 ) ;
}
return V_120 ;
}
static void
F_69 ( struct V_26 * V_57 ,
struct V_118 * V_33 , int V_121 )
{
struct V_31 * V_32 ;
V_32 = F_67 ( V_57 , V_33 ) ;
if ( V_32 ) {
V_32 -> V_121 = V_121 ;
goto V_72;
}
V_32 = F_70 ( sizeof( * V_32 ) , V_44 ) ;
if ( ! V_32 )
goto V_72;
F_71 ( & V_32 -> V_49 ) ;
F_31 ( & V_33 -> V_18 ) ;
F_31 ( & V_33 -> V_34 ) ;
V_32 -> V_33 = V_33 ;
V_32 -> V_121 = V_121 ;
F_43 ( & V_32 -> V_18 , 2 ) ;
F_26 ( & V_57 -> V_115 ) ;
F_72 ( & V_32 -> V_49 ,
& V_57 -> V_79 ) ;
F_30 ( & V_57 -> V_115 ) ;
V_72:
if ( V_32 )
F_22 ( V_32 ) ;
}
int F_73 ( struct V_20 * V_21 ,
struct V_118 * V_33 ,
const unsigned char * V_122 , T_2 V_36 ,
T_2 V_121 )
{
struct V_26 * V_27 ;
struct V_19 * V_22 ;
int V_123 = 0 ;
int V_64 ;
struct V_5 * V_25 ;
T_3 V_124 ;
V_27 = F_11 ( V_21 , V_122 ) ;
V_22 = F_10 ( V_21 , V_122 ) ;
if ( ( V_36 & V_125 ) && V_22 &&
! ( V_22 -> V_25 . V_36 & V_74 ) )
goto V_72;
if ( ! V_27 ) {
V_27 = F_70 ( sizeof( * V_27 ) , V_44 ) ;
if ( ! V_27 )
goto V_72;
V_25 = & V_27 -> V_25 ;
memcpy ( V_25 -> V_35 , V_122 , V_7 ) ;
V_25 -> V_36 = V_36 ;
V_27 -> V_80 = 0 ;
if ( V_36 & V_70 )
V_27 -> V_80 = V_67 ;
F_43 ( & V_25 -> V_18 , 2 ) ;
V_25 -> V_76 = V_67 ;
F_74 ( & V_27 -> V_79 ) ;
F_75 ( & V_27 -> V_115 ) ;
V_64 = F_44 ( V_21 -> V_23 . V_28 ,
F_1 ,
F_4 , V_25 ,
& V_25 -> V_6 ) ;
if ( F_45 ( V_64 != 0 ) ) {
F_17 ( V_27 ) ;
goto V_126;
}
} else {
V_25 = & V_27 -> V_25 ;
if ( V_36 & V_125 ) {
if ( ! ( V_25 -> V_36 & V_125 ) )
goto V_72;
if ( F_68 ( V_27 ,
V_33 ) )
goto V_126;
F_18 ( V_27 ) ;
goto V_127;
}
V_25 -> V_36 &= ~ V_125 ;
V_27 -> V_25 . V_36 |= V_36 ;
if ( V_25 -> V_36 & V_70 ) {
F_18 ( V_27 ) ;
V_25 -> V_36 &= ~ V_70 ;
V_27 -> V_80 = 0 ;
}
}
V_127:
F_69 ( V_27 , V_33 , V_121 ) ;
F_37 ( V_59 , V_21 ,
L_14 ,
V_25 -> V_35 , V_33 -> V_128 ) ;
V_123 = 1 ;
V_126:
V_124 = F_57 ( V_21 , V_122 ,
L_15 ,
! ! ( V_36 & V_70 ) ) ;
V_27 -> V_25 . V_36 |= V_124 & V_75 ;
if ( ! ( V_36 & V_70 ) )
V_27 -> V_25 . V_36 &= ~ V_70 ;
V_72:
if ( V_27 )
F_17 ( V_27 ) ;
if ( V_22 )
F_12 ( V_22 ) ;
return V_123 ;
}
static struct V_31 *
F_76 ( struct V_26 * V_27 )
{
struct V_129 * V_130 = NULL ;
struct V_11 * V_12 ;
struct V_31 * V_32 , * V_131 = NULL ;
int V_132 = 0 ;
V_12 = & V_27 -> V_79 ;
F_6 (orig_entry, head, list) {
V_130 = F_77 ( V_32 -> V_33 ) ;
if ( ! V_130 )
continue;
if ( V_130 -> V_133 > V_132 ) {
V_131 = V_32 ;
V_132 = V_130 -> V_133 ;
}
F_78 ( V_130 ) ;
}
return V_131 ;
}
static void
F_79 ( struct V_26 * V_27 ,
struct V_97 * V_98 )
{
struct V_11 * V_12 ;
struct V_31 * V_32 , * V_131 ;
struct V_5 * V_13 ;
T_3 V_36 ;
T_2 V_134 ;
V_13 = & V_27 -> V_25 ;
V_36 = V_13 -> V_36 ;
V_131 = F_76 ( V_27 ) ;
if ( V_131 ) {
V_134 = F_41 ( & V_131 -> V_33 -> V_134 ) ;
F_54 ( V_98 ,
L_16 ,
'*' , V_27 -> V_25 . V_35 ,
V_131 -> V_121 , V_131 -> V_33 -> V_128 ,
V_134 , V_131 -> V_33 -> V_135 ,
( V_36 & V_70 ? 'R' : '.' ) ,
( V_36 & V_75 ? 'W' : '.' ) ,
( V_36 & V_125 ? 'T' : '.' ) ) ;
}
V_12 = & V_27 -> V_79 ;
F_6 (orig_entry, head, list) {
if ( V_131 == V_32 )
continue;
V_134 = F_41 ( & V_32 -> V_33 -> V_134 ) ;
F_54 ( V_98 , L_17 ,
'+' , V_27 -> V_25 . V_35 ,
V_32 -> V_121 , V_32 -> V_33 -> V_128 ,
V_134 ,
( V_36 & V_70 ? 'R' : '.' ) ,
( V_36 & V_75 ? 'W' : '.' ) ,
( V_36 & V_125 ? 'T' : '.' ) ) ;
}
}
int F_80 ( struct V_97 * V_98 , void * V_99 )
{
struct V_60 * V_100 = (struct V_60 * ) V_98 -> V_101 ;
struct V_20 * V_21 = F_40 ( V_100 ) ;
struct V_8 * V_9 = V_21 -> V_23 . V_28 ;
struct V_5 * V_13 ;
struct V_26 * V_57 ;
struct V_86 * V_87 ;
struct V_11 * V_12 ;
T_1 V_102 ;
V_87 = F_53 ( V_98 ) ;
if ( ! V_87 )
goto V_72;
F_54 ( V_98 ,
L_18 ,
V_100 -> V_108 ) ;
F_54 ( V_98 , L_19 ,
L_8 , L_20 , L_21 , L_22 , L_23 ,
L_9 ) ;
for ( V_102 = 0 ; V_102 < V_9 -> V_16 ; V_102 ++ ) {
V_12 = & V_9 -> V_17 [ V_102 ] ;
F_5 () ;
F_6 (tt_common_entry,
head, hash_entry) {
V_57 = F_2 ( V_13 ,
struct V_26 ,
V_25 ) ;
F_79 ( V_57 , V_98 ) ;
}
F_9 () ;
}
V_72:
if ( V_87 )
F_50 ( V_87 ) ;
return 0 ;
}
static void
F_18 ( struct V_26 * V_27 )
{
struct V_11 * V_12 ;
struct V_1 * V_40 ;
struct V_31 * V_32 ;
F_26 ( & V_27 -> V_115 ) ;
V_12 = & V_27 -> V_79 ;
F_60 (orig_entry, safe, head, list) {
F_58 ( & V_32 -> V_49 ) ;
F_22 ( V_32 ) ;
}
F_30 ( & V_27 -> V_115 ) ;
}
static void
F_81 ( struct V_20 * V_21 ,
struct V_26 * V_27 ,
struct V_118 * V_33 ,
const char * V_58 )
{
struct V_11 * V_12 ;
struct V_1 * V_40 ;
struct V_31 * V_32 ;
F_26 ( & V_27 -> V_115 ) ;
V_12 = & V_27 -> V_79 ;
F_60 (orig_entry, safe, head, list) {
if ( V_32 -> V_33 == V_33 ) {
F_37 ( V_59 , V_21 ,
L_24 ,
V_33 -> V_128 ,
V_27 -> V_25 . V_35 , V_58 ) ;
F_58 ( & V_32 -> V_49 ) ;
F_22 ( V_32 ) ;
}
}
F_30 ( & V_27 -> V_115 ) ;
}
static void
F_82 ( struct V_20 * V_21 ,
struct V_26 * V_27 ,
struct V_118 * V_33 ,
const char * V_58 )
{
bool V_136 = true ;
struct V_11 * V_12 ;
struct V_31 * V_32 ;
F_5 () ;
V_12 = & V_27 -> V_79 ;
F_6 (orig_entry, head, list) {
if ( V_32 -> V_33 != V_33 ) {
V_136 = false ;
break;
}
}
F_9 () ;
if ( V_136 ) {
V_27 -> V_25 . V_36 |= V_70 ;
V_27 -> V_80 = V_67 ;
} else
F_81 ( V_21 , V_27 ,
V_33 , V_58 ) ;
}
static void F_83 ( struct V_20 * V_21 ,
struct V_118 * V_33 ,
const unsigned char * V_35 ,
const char * V_58 , bool V_110 )
{
struct V_26 * V_27 ;
struct V_19 * V_137 = NULL ;
V_27 = F_11 ( V_21 , V_35 ) ;
if ( ! V_27 )
goto V_72;
if ( ! V_110 ) {
F_81 ( V_21 , V_27 ,
V_33 , V_58 ) ;
if ( F_84 ( & V_27 -> V_79 ) )
F_36 ( V_21 , V_27 ,
V_58 ) ;
goto V_72;
}
V_137 = F_10 ( V_21 ,
V_27 -> V_25 . V_35 ) ;
if ( V_137 ) {
F_18 ( V_27 ) ;
F_36 ( V_21 , V_27 , V_58 ) ;
} else
F_82 ( V_21 , V_27 ,
V_33 , V_58 ) ;
V_72:
if ( V_27 )
F_17 ( V_27 ) ;
if ( V_137 )
F_12 ( V_137 ) ;
}
void F_85 ( struct V_20 * V_21 ,
struct V_118 * V_33 ,
const char * V_58 )
{
struct V_26 * V_57 ;
struct V_5 * V_13 ;
T_1 V_102 ;
struct V_8 * V_9 = V_21 -> V_23 . V_28 ;
struct V_1 * V_40 ;
struct V_11 * V_12 ;
T_4 * V_115 ;
if ( ! V_9 )
return;
for ( V_102 = 0 ; V_102 < V_9 -> V_16 ; V_102 ++ ) {
V_12 = & V_9 -> V_17 [ V_102 ] ;
V_115 = & V_9 -> V_116 [ V_102 ] ;
F_26 ( V_115 ) ;
F_60 (tt_common_entry, safe,
head, hash_entry) {
V_57 = F_2 ( V_13 ,
struct V_26 ,
V_25 ) ;
F_81 ( V_21 , V_57 ,
V_33 , V_58 ) ;
if ( F_84 ( & V_57 -> V_79 ) ) {
F_37 ( V_59 , V_21 ,
L_1 ,
V_57 -> V_25 . V_35 , V_58 ) ;
F_58 ( & V_13 -> V_6 ) ;
F_17 ( V_57 ) ;
}
}
F_30 ( V_115 ) ;
}
V_33 -> V_138 = false ;
}
static bool F_86 ( struct V_26 * V_57 ,
char * * V_139 )
{
bool V_140 = false ;
unsigned long V_141 = V_142 ;
unsigned long V_143 = V_144 ;
if ( ( V_57 -> V_25 . V_36 & V_70 ) &&
F_61 ( V_57 -> V_80 , V_141 ) ) {
V_140 = true ;
* V_139 = L_25 ;
}
if ( ( V_57 -> V_25 . V_36 & V_125 ) &&
F_61 ( V_57 -> V_25 . V_76 , V_143 ) ) {
V_140 = true ;
* V_139 = L_26 ;
}
return V_140 ;
}
static void F_87 ( struct V_20 * V_21 )
{
struct V_8 * V_9 = V_21 -> V_23 . V_28 ;
struct V_11 * V_12 ;
struct V_1 * V_113 ;
T_4 * V_115 ;
T_1 V_102 ;
char * V_139 = NULL ;
struct V_5 * V_145 ;
struct V_26 * V_57 ;
for ( V_102 = 0 ; V_102 < V_9 -> V_16 ; V_102 ++ ) {
V_12 = & V_9 -> V_17 [ V_102 ] ;
V_115 = & V_9 -> V_116 [ V_102 ] ;
F_26 ( V_115 ) ;
F_60 (tt_common, node_tmp, head,
hash_entry) {
V_57 = F_2 ( V_145 ,
struct V_26 ,
V_25 ) ;
if ( ! F_86 ( V_57 , & V_139 ) )
continue;
F_37 ( V_59 , V_21 ,
L_27 ,
V_57 -> V_25 . V_35 , V_139 ) ;
F_58 ( & V_145 -> V_6 ) ;
F_17 ( V_57 ) ;
}
F_30 ( V_115 ) ;
}
}
static void F_88 ( struct V_20 * V_21 )
{
struct V_8 * V_9 ;
T_4 * V_115 ;
struct V_5 * V_13 ;
struct V_26 * V_57 ;
struct V_1 * V_113 ;
struct V_11 * V_12 ;
T_1 V_102 ;
if ( ! V_21 -> V_23 . V_28 )
return;
V_9 = V_21 -> V_23 . V_28 ;
for ( V_102 = 0 ; V_102 < V_9 -> V_16 ; V_102 ++ ) {
V_12 = & V_9 -> V_17 [ V_102 ] ;
V_115 = & V_9 -> V_116 [ V_102 ] ;
F_26 ( V_115 ) ;
F_60 (tt_common_entry, node_tmp,
head, hash_entry) {
F_58 ( & V_13 -> V_6 ) ;
V_57 = F_2 ( V_13 ,
struct V_26 ,
V_25 ) ;
F_17 ( V_57 ) ;
}
F_30 ( V_115 ) ;
}
F_64 ( V_9 ) ;
V_21 -> V_23 . V_28 = NULL ;
}
static bool
F_89 ( struct V_19 * V_22 ,
struct V_26 * V_27 )
{
bool V_123 = false ;
if ( V_22 -> V_25 . V_36 & V_75 &&
V_27 -> V_25 . V_36 & V_75 )
V_123 = true ;
return V_123 ;
}
struct V_118 * F_90 ( struct V_20 * V_21 ,
const T_2 * V_146 ,
const T_2 * V_35 )
{
struct V_19 * V_22 = NULL ;
struct V_26 * V_27 = NULL ;
struct V_118 * V_33 = NULL ;
struct V_31 * V_131 ;
if ( V_146 && F_41 ( & V_21 -> V_147 ) ) {
V_22 = F_10 ( V_21 , V_146 ) ;
if ( ! V_22 ||
( V_22 -> V_25 . V_36 & V_68 ) )
goto V_72;
}
V_27 = F_11 ( V_21 , V_35 ) ;
if ( ! V_27 )
goto V_72;
if ( V_22 &&
F_89 ( V_22 , V_27 ) )
goto V_72;
F_5 () ;
V_131 = F_76 ( V_27 ) ;
if ( V_131 )
V_33 = V_131 -> V_33 ;
if ( V_33 && ! F_8 ( & V_33 -> V_18 ) )
V_33 = NULL ;
F_9 () ;
V_72:
if ( V_27 )
F_17 ( V_27 ) ;
if ( V_22 )
F_12 ( V_22 ) ;
return V_33 ;
}
static T_3 F_91 ( struct V_20 * V_21 ,
struct V_118 * V_33 )
{
T_3 V_148 = 0 , V_149 ;
struct V_8 * V_9 = V_21 -> V_23 . V_28 ;
struct V_5 * V_145 ;
struct V_26 * V_57 ;
struct V_11 * V_12 ;
T_1 V_102 ;
int V_150 ;
for ( V_102 = 0 ; V_102 < V_9 -> V_16 ; V_102 ++ ) {
V_12 = & V_9 -> V_17 [ V_102 ] ;
F_5 () ;
F_6 (tt_common, head, hash_entry) {
V_57 = F_2 ( V_145 ,
struct V_26 ,
V_25 ) ;
if ( V_145 -> V_36 & V_70 )
continue;
if ( V_145 -> V_36 & V_125 )
continue;
if ( ! F_68 ( V_57 ,
V_33 ) )
continue;
V_149 = 0 ;
for ( V_150 = 0 ; V_150 < V_7 ; V_150 ++ )
V_149 = F_92 ( V_149 ,
V_145 -> V_35 [ V_150 ] ) ;
V_148 ^= V_149 ;
}
F_9 () ;
}
return V_148 ;
}
static T_3 F_93 ( struct V_20 * V_21 )
{
T_3 V_148 = 0 , V_149 ;
struct V_8 * V_9 = V_21 -> V_23 . V_24 ;
struct V_5 * V_145 ;
struct V_11 * V_12 ;
T_1 V_102 ;
int V_150 ;
for ( V_102 = 0 ; V_102 < V_9 -> V_16 ; V_102 ++ ) {
V_12 = & V_9 -> V_17 [ V_102 ] ;
F_5 () ;
F_6 (tt_common, head, hash_entry) {
if ( V_145 -> V_36 & V_74 )
continue;
V_149 = 0 ;
for ( V_150 = 0 ; V_150 < V_7 ; V_150 ++ )
V_149 = F_92 ( V_149 ,
V_145 -> V_35 [ V_150 ] ) ;
V_148 ^= V_149 ;
}
F_9 () ;
}
return V_148 ;
}
static void F_94 ( struct V_20 * V_21 )
{
struct V_151 * V_2 , * V_40 ;
F_26 ( & V_21 -> V_23 . V_152 ) ;
F_27 (node, safe, &bat_priv->tt.req_list, list) {
F_28 ( & V_2 -> V_49 ) ;
F_16 ( V_2 ) ;
}
F_30 ( & V_21 -> V_23 . V_152 ) ;
}
static void F_95 ( struct V_20 * V_21 ,
struct V_118 * V_33 ,
const unsigned char * V_93 ,
T_2 V_153 )
{
T_3 V_154 = F_32 ( V_153 ) ;
F_26 ( & V_33 -> V_155 ) ;
if ( V_154 > 0 ) {
F_16 ( V_33 -> V_93 ) ;
V_33 -> V_154 = 0 ;
V_33 -> V_93 = F_25 ( V_154 , V_44 ) ;
if ( V_33 -> V_93 ) {
memcpy ( V_33 -> V_93 , V_93 , V_154 ) ;
V_33 -> V_154 = V_154 ;
}
}
F_30 ( & V_33 -> V_155 ) ;
}
static void F_96 ( struct V_20 * V_21 )
{
struct V_151 * V_2 , * V_40 ;
F_26 ( & V_21 -> V_23 . V_152 ) ;
F_27 (node, safe, &bat_priv->tt.req_list, list) {
if ( F_61 ( V_2 -> V_156 ,
V_157 ) ) {
F_28 ( & V_2 -> V_49 ) ;
F_16 ( V_2 ) ;
}
}
F_30 ( & V_21 -> V_23 . V_152 ) ;
}
static struct V_151 *
F_97 ( struct V_20 * V_21 ,
struct V_118 * V_33 )
{
struct V_151 * V_158 , * V_159 = NULL ;
F_26 ( & V_21 -> V_23 . V_152 ) ;
F_98 (tt_req_node_tmp, &bat_priv->tt.req_list, list) {
if ( F_7 ( V_158 , V_33 ) &&
! F_61 ( V_158 -> V_156 ,
V_157 ) )
goto V_50;
}
V_159 = F_25 ( sizeof( * V_159 ) , V_44 ) ;
if ( ! V_159 )
goto V_50;
memcpy ( V_159 -> V_35 , V_33 -> V_128 , V_7 ) ;
V_159 -> V_156 = V_67 ;
F_99 ( & V_159 -> V_49 , & V_21 -> V_23 . V_160 ) ;
V_50:
F_30 ( & V_21 -> V_23 . V_152 ) ;
return V_159 ;
}
static int F_100 ( const void * V_161 ,
const void * V_162 )
{
const struct V_5 * V_13 = V_161 ;
if ( V_13 -> V_36 & V_74 )
return 0 ;
return 1 ;
}
static int F_101 ( const void * V_161 ,
const void * V_162 )
{
const struct V_5 * V_13 = V_161 ;
const struct V_26 * V_27 ;
const struct V_118 * V_33 = V_162 ;
if ( V_13 -> V_36 & V_70 ||
V_13 -> V_36 & V_125 )
return 0 ;
V_27 = F_2 ( V_13 ,
struct V_26 ,
V_25 ) ;
return F_68 ( V_27 , V_33 ) ;
}
static struct V_163 *
F_102 ( T_3 V_164 , T_2 V_121 ,
struct V_8 * V_9 ,
struct V_86 * V_87 ,
int (* F_103)( const void * , const void * ) ,
void * V_165 )
{
struct V_5 * V_13 ;
struct V_166 * V_167 ;
struct V_54 * V_168 ;
struct V_11 * V_12 ;
struct V_163 * V_169 = NULL ;
T_3 V_170 , V_171 ;
T_5 V_172 = sizeof( struct V_166 ) ;
T_1 V_102 ;
T_6 V_173 ;
if ( V_172 + V_164 > V_87 -> V_61 -> V_89 ) {
V_164 = V_87 -> V_61 -> V_89 - V_172 ;
V_164 -= V_164 % sizeof( struct V_54 ) ;
}
V_170 = V_164 / sizeof( struct V_54 ) ;
V_173 = V_172 + V_164 ;
V_169 = F_104 ( V_173 + V_174 + V_175 ) ;
if ( ! V_169 )
goto V_72;
F_105 ( V_169 , V_174 + V_175 ) ;
V_167 = (struct V_166 * ) F_106 ( V_169 , V_173 ) ;
V_167 -> V_121 = V_121 ;
V_168 = (struct V_54 * ) ( V_169 -> V_10 + V_172 ) ;
V_171 = 0 ;
F_5 () ;
for ( V_102 = 0 ; V_102 < V_9 -> V_16 ; V_102 ++ ) {
V_12 = & V_9 -> V_17 [ V_102 ] ;
F_6 (tt_common_entry,
head, hash_entry) {
if ( V_171 == V_170 )
break;
if ( ( F_103 ) && ( ! F_103 ( V_13 , V_165 ) ) )
continue;
memcpy ( V_168 -> V_35 , V_13 -> V_35 ,
V_7 ) ;
V_168 -> V_36 = V_13 -> V_36 ;
V_171 ++ ;
V_168 ++ ;
}
}
F_9 () ;
V_167 -> V_176 = F_107 ( V_171 ) ;
V_72:
return V_169 ;
}
static int F_108 ( struct V_20 * V_21 ,
struct V_118 * V_177 ,
T_2 V_121 , T_3 V_135 ,
bool V_178 )
{
struct V_163 * V_169 = NULL ;
struct V_166 * V_179 ;
struct V_86 * V_87 ;
struct V_151 * V_159 = NULL ;
int V_123 = 1 ;
T_6 V_180 ;
V_87 = F_49 ( V_21 ) ;
if ( ! V_87 )
goto V_72;
V_159 = F_97 ( V_21 , V_177 ) ;
if ( ! V_159 )
goto V_72;
V_169 = F_104 ( sizeof( * V_179 ) + V_174 + V_175 ) ;
if ( ! V_169 )
goto V_72;
F_105 ( V_169 , V_174 + V_175 ) ;
V_180 = sizeof( * V_179 ) ;
V_179 = (struct V_166 * ) F_106 ( V_169 , V_180 ) ;
V_179 -> V_181 . V_182 = V_183 ;
V_179 -> V_181 . V_184 = V_185 ;
memcpy ( V_179 -> V_146 , V_87 -> V_100 -> V_77 , V_7 ) ;
memcpy ( V_179 -> V_186 , V_177 -> V_128 , V_7 ) ;
V_179 -> V_181 . V_187 = V_188 ;
V_179 -> V_121 = V_121 ;
V_179 -> V_176 = F_107 ( V_135 ) ;
V_179 -> V_36 = V_189 ;
if ( V_178 )
V_179 -> V_36 |= V_190 ;
F_37 ( V_59 , V_21 , L_28 ,
V_177 -> V_128 , ( V_178 ? 'F' : '.' ) ) ;
F_109 ( V_21 , V_191 ) ;
if ( F_110 ( V_169 , V_177 , NULL ) )
V_123 = 0 ;
V_72:
if ( V_87 )
F_50 ( V_87 ) ;
if ( V_123 )
F_111 ( V_169 ) ;
if ( V_123 && V_159 ) {
F_26 ( & V_21 -> V_23 . V_152 ) ;
F_28 ( & V_159 -> V_49 ) ;
F_30 ( & V_21 -> V_23 . V_152 ) ;
F_16 ( V_159 ) ;
}
return V_123 ;
}
static bool
F_112 ( struct V_20 * V_21 ,
struct V_166 * V_179 )
{
struct V_118 * V_192 ;
struct V_118 * V_193 = NULL ;
struct V_86 * V_87 = NULL ;
T_2 V_194 , V_195 , V_121 ;
int V_123 = false ;
unsigned char * V_93 ;
bool V_178 ;
T_3 V_164 , V_170 ;
struct V_163 * V_169 = NULL ;
struct V_166 * V_167 ;
T_2 * V_196 ;
T_6 V_173 ;
F_37 ( V_59 , V_21 ,
L_29 ,
V_179 -> V_146 , V_179 -> V_121 , V_179 -> V_186 ,
( V_179 -> V_36 & V_190 ? 'F' : '.' ) ) ;
V_192 = F_113 ( V_21 , V_179 -> V_186 ) ;
if ( ! V_192 )
goto V_72;
V_193 = F_113 ( V_21 , V_179 -> V_146 ) ;
if ( ! V_193 )
goto V_72;
V_87 = F_49 ( V_21 ) ;
if ( ! V_87 )
goto V_72;
V_194 = ( T_2 ) F_41 ( & V_192 -> V_134 ) ;
V_195 = V_179 -> V_121 ;
if ( V_194 != V_195 ||
V_179 -> V_176 != F_107 ( V_192 -> V_135 ) )
goto V_72;
if ( V_179 -> V_36 & V_190 ||
! V_192 -> V_93 )
V_178 = true ;
else
V_178 = false ;
if ( ! V_178 ) {
F_26 ( & V_192 -> V_155 ) ;
V_164 = V_192 -> V_154 ;
V_170 = V_164 / sizeof( struct V_54 ) ;
V_173 = sizeof( * V_167 ) + V_164 ;
V_169 = F_104 ( V_173 + V_174 + V_175 ) ;
if ( ! V_169 )
goto V_50;
F_105 ( V_169 , V_174 + V_175 ) ;
V_196 = F_106 ( V_169 , V_173 ) ;
V_167 = (struct V_166 * ) V_196 ;
V_167 -> V_121 = V_195 ;
V_167 -> V_176 = F_107 ( V_170 ) ;
V_93 = V_169 -> V_10 + sizeof( * V_167 ) ;
memcpy ( V_93 , V_192 -> V_93 ,
V_192 -> V_154 ) ;
F_30 ( & V_192 -> V_155 ) ;
} else {
V_164 = ( T_3 ) F_41 ( & V_192 -> V_34 ) ;
V_164 *= sizeof( struct V_54 ) ;
V_121 = ( T_2 ) F_41 ( & V_192 -> V_134 ) ;
V_169 = F_102 ( V_164 , V_121 ,
V_21 -> V_23 . V_28 ,
V_87 ,
F_101 ,
V_192 ) ;
if ( ! V_169 )
goto V_72;
V_167 = (struct V_166 * ) V_169 -> V_10 ;
}
V_167 -> V_181 . V_182 = V_183 ;
V_167 -> V_181 . V_184 = V_185 ;
V_167 -> V_181 . V_187 = V_188 ;
memcpy ( V_167 -> V_146 , V_192 -> V_128 , V_7 ) ;
memcpy ( V_167 -> V_186 , V_179 -> V_146 , V_7 ) ;
V_167 -> V_36 = V_197 ;
if ( V_178 )
V_167 -> V_36 |= V_190 ;
F_37 ( V_59 , V_21 ,
L_30 ,
V_193 -> V_128 , V_192 -> V_128 , V_195 ) ;
F_109 ( V_21 , V_198 ) ;
if ( F_110 ( V_169 , V_193 , NULL ) )
V_123 = true ;
goto V_72;
V_50:
F_30 ( & V_192 -> V_155 ) ;
V_72:
if ( V_193 )
F_21 ( V_193 ) ;
if ( V_192 )
F_21 ( V_192 ) ;
if ( V_87 )
F_50 ( V_87 ) ;
if ( ! V_123 )
F_111 ( V_169 ) ;
return V_123 ;
}
static bool
F_114 ( struct V_20 * V_21 ,
struct V_166 * V_179 )
{
struct V_118 * V_33 ;
struct V_86 * V_87 = NULL ;
T_2 V_199 , V_195 , V_121 ;
int V_123 = false ;
unsigned char * V_93 ;
bool V_178 ;
T_3 V_164 , V_170 ;
struct V_163 * V_169 = NULL ;
struct V_166 * V_167 ;
T_2 * V_196 ;
T_6 V_173 ;
F_37 ( V_59 , V_21 ,
L_31 ,
V_179 -> V_146 , V_179 -> V_121 ,
( V_179 -> V_36 & V_190 ? 'F' : '.' ) ) ;
V_199 = ( T_2 ) F_41 ( & V_21 -> V_23 . V_73 ) ;
V_195 = V_179 -> V_121 ;
V_33 = F_113 ( V_21 , V_179 -> V_146 ) ;
if ( ! V_33 )
goto V_72;
V_87 = F_49 ( V_21 ) ;
if ( ! V_87 )
goto V_72;
if ( V_179 -> V_36 & V_190 || V_199 != V_195 ||
! V_21 -> V_23 . V_95 )
V_178 = true ;
else
V_178 = false ;
if ( ! V_178 ) {
F_26 ( & V_21 -> V_23 . V_94 ) ;
V_164 = V_21 -> V_23 . V_96 ;
V_170 = V_164 / sizeof( struct V_54 ) ;
V_173 = sizeof( * V_167 ) + V_164 ;
V_169 = F_104 ( V_173 + V_174 + V_175 ) ;
if ( ! V_169 )
goto V_50;
F_105 ( V_169 , V_174 + V_175 ) ;
V_196 = F_106 ( V_169 , V_173 ) ;
V_167 = (struct V_166 * ) V_196 ;
V_167 -> V_121 = V_195 ;
V_167 -> V_176 = F_107 ( V_170 ) ;
V_93 = V_169 -> V_10 + sizeof( * V_167 ) ;
memcpy ( V_93 , V_21 -> V_23 . V_95 ,
V_21 -> V_23 . V_96 ) ;
F_30 ( & V_21 -> V_23 . V_94 ) ;
} else {
V_164 = ( T_3 ) F_41 ( & V_21 -> V_23 . V_200 ) ;
V_164 *= sizeof( struct V_54 ) ;
V_121 = ( T_2 ) F_41 ( & V_21 -> V_23 . V_73 ) ;
V_169 = F_102 ( V_164 , V_121 ,
V_21 -> V_23 . V_24 ,
V_87 ,
F_100 ,
NULL ) ;
if ( ! V_169 )
goto V_72;
V_167 = (struct V_166 * ) V_169 -> V_10 ;
}
V_167 -> V_181 . V_182 = V_183 ;
V_167 -> V_181 . V_184 = V_185 ;
V_167 -> V_181 . V_187 = V_188 ;
memcpy ( V_167 -> V_146 , V_87 -> V_100 -> V_77 , V_7 ) ;
memcpy ( V_167 -> V_186 , V_179 -> V_146 , V_7 ) ;
V_167 -> V_36 = V_197 ;
if ( V_178 )
V_167 -> V_36 |= V_190 ;
F_37 ( V_59 , V_21 ,
L_32 ,
V_33 -> V_128 ,
( V_167 -> V_36 & V_190 ? 'F' : '.' ) ) ;
F_109 ( V_21 , V_198 ) ;
if ( F_110 ( V_169 , V_33 , NULL ) )
V_123 = true ;
goto V_72;
V_50:
F_30 ( & V_21 -> V_23 . V_94 ) ;
V_72:
if ( V_33 )
F_21 ( V_33 ) ;
if ( V_87 )
F_50 ( V_87 ) ;
if ( ! V_123 )
F_111 ( V_169 ) ;
return true ;
}
bool F_115 ( struct V_20 * V_21 ,
struct V_166 * V_179 )
{
if ( F_116 ( V_21 , V_179 -> V_186 ) ) {
if ( F_117 ( V_21 , V_179 -> V_146 ) )
return true ;
return F_114 ( V_21 , V_179 ) ;
} else {
return F_112 ( V_21 , V_179 ) ;
}
}
static void F_118 ( struct V_20 * V_21 ,
struct V_118 * V_33 ,
struct V_54 * V_168 ,
T_3 V_153 , T_2 V_121 )
{
int V_102 ;
int V_201 ;
for ( V_102 = 0 ; V_102 < V_153 ; V_102 ++ ) {
if ( ( V_168 + V_102 ) -> V_36 & V_46 ) {
V_201 = ( V_168 + V_102 ) -> V_36 & V_70 ;
F_83 ( V_21 , V_33 ,
( V_168 + V_102 ) -> V_35 ,
L_33 ,
V_201 ) ;
} else {
if ( ! F_73 ( V_21 , V_33 ,
( V_168 + V_102 ) -> V_35 ,
( V_168 + V_102 ) -> V_36 , V_121 ) )
return;
}
}
V_33 -> V_138 = true ;
}
static void F_119 ( struct V_20 * V_21 ,
struct V_166 * V_167 )
{
struct V_118 * V_33 ;
V_33 = F_113 ( V_21 , V_167 -> V_146 ) ;
if ( ! V_33 )
goto V_72;
F_85 ( V_21 , V_33 , L_34 ) ;
F_118 ( V_21 , V_33 ,
(struct V_54 * ) ( V_167 + 1 ) ,
F_120 ( V_167 -> V_176 ) ,
V_167 -> V_121 ) ;
F_26 ( & V_33 -> V_155 ) ;
F_16 ( V_33 -> V_93 ) ;
V_33 -> V_154 = 0 ;
V_33 -> V_93 = NULL ;
F_30 ( & V_33 -> V_155 ) ;
F_43 ( & V_33 -> V_134 , V_167 -> V_121 ) ;
V_72:
if ( V_33 )
F_21 ( V_33 ) ;
}
static void F_121 ( struct V_20 * V_21 ,
struct V_118 * V_33 ,
T_3 V_153 , T_2 V_121 ,
struct V_54 * V_168 )
{
F_118 ( V_21 , V_33 , V_168 ,
V_153 , V_121 ) ;
F_95 ( V_21 , V_33 ,
( unsigned char * ) V_168 , V_153 ) ;
F_43 ( & V_33 -> V_134 , V_121 ) ;
}
bool F_122 ( struct V_20 * V_21 , const T_2 * V_35 )
{
struct V_19 * V_22 ;
bool V_123 = false ;
V_22 = F_10 ( V_21 , V_35 ) ;
if ( ! V_22 )
goto V_72;
if ( ( V_22 -> V_25 . V_36 & V_68 ) ||
( V_22 -> V_25 . V_36 & V_70 ) )
goto V_72;
V_123 = true ;
V_72:
if ( V_22 )
F_12 ( V_22 ) ;
return V_123 ;
}
void F_123 ( struct V_20 * V_21 ,
struct V_166 * V_167 )
{
struct V_151 * V_2 , * V_40 ;
struct V_118 * V_33 = NULL ;
struct V_54 * V_168 ;
F_37 ( V_59 , V_21 ,
L_35 ,
V_167 -> V_146 , V_167 -> V_121 ,
F_120 ( V_167 -> V_176 ) ,
( V_167 -> V_36 & V_190 ? 'F' : '.' ) ) ;
if ( F_117 ( V_21 , V_167 -> V_146 ) )
goto V_72;
V_33 = F_113 ( V_21 , V_167 -> V_146 ) ;
if ( ! V_33 )
goto V_72;
if ( V_167 -> V_36 & V_190 ) {
F_119 ( V_21 , V_167 ) ;
} else {
V_168 = (struct V_54 * ) ( V_167 + 1 ) ;
F_121 ( V_21 , V_33 ,
F_120 ( V_167 -> V_176 ) ,
V_167 -> V_121 , V_168 ) ;
}
F_26 ( & V_21 -> V_23 . V_152 ) ;
F_27 (node, safe, &bat_priv->tt.req_list, list) {
if ( ! F_7 ( V_2 -> V_35 , V_167 -> V_146 ) )
continue;
F_28 ( & V_2 -> V_49 ) ;
F_16 ( V_2 ) ;
}
F_30 ( & V_21 -> V_23 . V_152 ) ;
V_33 -> V_135 = F_91 ( V_21 , V_33 ) ;
V_72:
if ( V_33 )
F_21 ( V_33 ) ;
}
int F_124 ( struct V_20 * V_21 )
{
int V_123 ;
V_123 = F_33 ( V_21 ) ;
if ( V_123 < 0 )
return V_123 ;
V_123 = F_65 ( V_21 ) ;
if ( V_123 < 0 )
return V_123 ;
F_125 ( & V_21 -> V_23 . V_202 , V_203 ) ;
F_126 ( V_204 , & V_21 -> V_23 . V_202 ,
F_127 ( V_205 ) ) ;
return 1 ;
}
static void F_128 ( struct V_20 * V_21 )
{
struct V_206 * V_2 , * V_40 ;
F_26 ( & V_21 -> V_23 . V_207 ) ;
F_27 (node, safe, &bat_priv->tt.roam_list, list) {
F_28 ( & V_2 -> V_49 ) ;
F_16 ( V_2 ) ;
}
F_30 ( & V_21 -> V_23 . V_207 ) ;
}
static void F_129 ( struct V_20 * V_21 )
{
struct V_206 * V_2 , * V_40 ;
F_26 ( & V_21 -> V_23 . V_207 ) ;
F_27 (node, safe, &bat_priv->tt.roam_list, list) {
if ( ! F_61 ( V_2 -> V_208 ,
V_209 ) )
continue;
F_28 ( & V_2 -> V_49 ) ;
F_16 ( V_2 ) ;
}
F_30 ( & V_21 -> V_23 . V_207 ) ;
}
static bool F_130 ( struct V_20 * V_21 ,
T_2 * V_210 )
{
struct V_206 * V_211 ;
bool V_123 = false ;
F_26 ( & V_21 -> V_23 . V_207 ) ;
F_98 (tt_roam_node, &bat_priv->tt.roam_list, list) {
if ( ! F_7 ( V_211 -> V_35 , V_210 ) )
continue;
if ( F_61 ( V_211 -> V_208 ,
V_209 ) )
continue;
if ( ! F_131 ( & V_211 -> V_212 ) )
goto V_50;
V_123 = true ;
break;
}
if ( ! V_123 ) {
V_211 = F_25 ( sizeof( * V_211 ) , V_44 ) ;
if ( ! V_211 )
goto V_50;
V_211 -> V_208 = V_67 ;
F_43 ( & V_211 -> V_212 ,
V_213 - 1 ) ;
memcpy ( V_211 -> V_35 , V_210 , V_7 ) ;
F_99 ( & V_211 -> V_49 , & V_21 -> V_23 . V_214 ) ;
V_123 = true ;
}
V_50:
F_30 ( & V_21 -> V_23 . V_207 ) ;
return V_123 ;
}
static void F_46 ( struct V_20 * V_21 , T_2 * V_210 ,
struct V_118 * V_33 )
{
struct V_163 * V_169 = NULL ;
struct V_215 * V_216 ;
int V_123 = 1 ;
struct V_86 * V_87 ;
T_6 V_173 = sizeof( * V_216 ) ;
if ( ! F_130 ( V_21 , V_210 ) )
goto V_72;
V_169 = F_104 ( sizeof( * V_216 ) + V_174 + V_175 ) ;
if ( ! V_169 )
goto V_72;
F_105 ( V_169 , V_174 + V_175 ) ;
V_216 = (struct V_215 * ) F_106 ( V_169 , V_173 ) ;
V_216 -> V_181 . V_182 = V_217 ;
V_216 -> V_181 . V_184 = V_185 ;
V_216 -> V_181 . V_187 = V_188 ;
V_216 -> V_218 = 0 ;
V_87 = F_49 ( V_21 ) ;
if ( ! V_87 )
goto V_72;
memcpy ( V_216 -> V_146 , V_87 -> V_100 -> V_77 , V_7 ) ;
F_50 ( V_87 ) ;
memcpy ( V_216 -> V_186 , V_33 -> V_128 , V_7 ) ;
memcpy ( V_216 -> V_210 , V_210 , V_7 ) ;
F_37 ( V_59 , V_21 ,
L_36 ,
V_33 -> V_128 , V_210 ) ;
F_109 ( V_21 , V_219 ) ;
if ( F_110 ( V_169 , V_33 , NULL ) )
V_123 = 0 ;
V_72:
if ( V_123 && V_169 )
F_111 ( V_169 ) ;
return;
}
static void V_203 ( struct V_220 * V_202 )
{
struct V_221 * V_221 ;
struct V_222 * V_223 ;
struct V_20 * V_21 ;
V_221 = F_2 ( V_202 , struct V_221 , V_202 ) ;
V_223 = F_2 ( V_221 , struct V_222 , V_202 ) ;
V_21 = F_2 ( V_223 , struct V_20 , V_23 ) ;
F_62 ( V_21 ) ;
F_87 ( V_21 ) ;
F_96 ( V_21 ) ;
F_129 ( V_21 ) ;
F_126 ( V_204 , & V_21 -> V_23 . V_202 ,
F_127 ( V_205 ) ) ;
}
void F_132 ( struct V_20 * V_21 )
{
F_133 ( & V_21 -> V_23 . V_202 ) ;
F_63 ( V_21 ) ;
F_88 ( V_21 ) ;
F_94 ( V_21 ) ;
F_66 ( V_21 ) ;
F_128 ( V_21 ) ;
F_16 ( V_21 -> V_23 . V_95 ) ;
}
static T_3 F_134 ( struct V_8 * V_9 ,
T_3 V_36 , bool V_224 )
{
T_1 V_102 ;
T_3 V_225 = 0 ;
struct V_11 * V_12 ;
struct V_5 * V_13 ;
if ( ! V_9 )
goto V_72;
for ( V_102 = 0 ; V_102 < V_9 -> V_16 ; V_102 ++ ) {
V_12 = & V_9 -> V_17 [ V_102 ] ;
F_5 () ;
F_6 (tt_common_entry,
head, hash_entry) {
if ( V_224 ) {
if ( ( V_13 -> V_36 & V_36 ) == V_36 )
continue;
V_13 -> V_36 |= V_36 ;
} else {
if ( ! ( V_13 -> V_36 & V_36 ) )
continue;
V_13 -> V_36 &= ~ V_36 ;
}
V_225 ++ ;
}
F_9 () ;
}
V_72:
return V_225 ;
}
static void F_135 ( struct V_20 * V_21 )
{
struct V_8 * V_9 = V_21 -> V_23 . V_24 ;
struct V_5 * V_145 ;
struct V_19 * V_63 ;
struct V_1 * V_113 ;
struct V_11 * V_12 ;
T_4 * V_115 ;
T_1 V_102 ;
if ( ! V_9 )
return;
for ( V_102 = 0 ; V_102 < V_9 -> V_16 ; V_102 ++ ) {
V_12 = & V_9 -> V_17 [ V_102 ] ;
V_115 = & V_9 -> V_116 [ V_102 ] ;
F_26 ( V_115 ) ;
F_60 (tt_common, node_tmp, head,
hash_entry) {
if ( ! ( V_145 -> V_36 & V_68 ) )
continue;
F_37 ( V_59 , V_21 ,
L_37 ,
V_145 -> V_35 ) ;
F_23 ( & V_21 -> V_23 . V_200 ) ;
F_58 ( & V_145 -> V_6 ) ;
V_63 = F_2 ( V_145 ,
struct V_19 ,
V_25 ) ;
F_12 ( V_63 ) ;
}
F_30 ( V_115 ) ;
}
}
static int F_136 ( struct V_20 * V_21 ,
unsigned char * * V_81 ,
int * V_82 , int V_226 )
{
T_3 V_225 = 0 ;
if ( F_41 ( & V_21 -> V_23 . V_52 ) < 1 )
return - V_227 ;
V_225 = F_134 ( V_21 -> V_23 . V_24 ,
V_74 , false ) ;
F_137 ( V_225 , & V_21 -> V_23 . V_200 ) ;
F_135 ( V_21 ) ;
V_21 -> V_23 . V_109 = F_93 ( V_21 ) ;
F_31 ( & V_21 -> V_23 . V_73 ) ;
F_37 ( V_59 , V_21 ,
L_38 ,
( T_2 ) F_41 ( & V_21 -> V_23 . V_73 ) ) ;
F_43 ( & V_21 -> V_23 . V_228 , V_229 ) ;
return F_51 ( V_21 , V_81 ,
V_82 , V_226 ) ;
}
int F_138 ( struct V_20 * V_21 ,
unsigned char * * V_81 , int * V_82 ,
int V_226 )
{
int V_153 ;
V_153 = F_136 ( V_21 , V_81 ,
V_82 ,
V_226 ) ;
if ( ( V_153 < 0 ) &&
( ! F_131 ( & V_21 -> V_23 . V_228 ) ) ) {
F_47 ( V_81 , V_82 ,
V_226 , V_226 ) ;
V_153 = 0 ;
}
return V_153 ;
}
bool F_139 ( struct V_20 * V_21 , T_2 * V_146 ,
T_2 * V_186 )
{
struct V_19 * V_22 = NULL ;
struct V_26 * V_27 = NULL ;
bool V_123 = false ;
if ( ! F_41 ( & V_21 -> V_147 ) )
goto V_72;
V_22 = F_10 ( V_21 , V_186 ) ;
if ( ! V_22 )
goto V_72;
V_27 = F_11 ( V_21 , V_146 ) ;
if ( ! V_27 )
goto V_72;
if ( ! F_89 ( V_22 , V_27 ) )
goto V_72;
V_123 = true ;
V_72:
if ( V_27 )
F_17 ( V_27 ) ;
if ( V_22 )
F_12 ( V_22 ) ;
return V_123 ;
}
void F_140 ( struct V_20 * V_21 ,
struct V_118 * V_33 ,
const unsigned char * V_93 , T_2 V_153 ,
T_2 V_121 , T_3 V_135 )
{
T_2 V_194 = ( T_2 ) F_41 ( & V_33 -> V_134 ) ;
bool V_178 = true ;
struct V_54 * V_168 ;
if ( F_117 ( V_21 , V_33 -> V_128 ) )
return;
if ( ( ! V_33 -> V_138 && V_121 == 1 ) ||
V_121 - V_194 == 1 ) {
if ( ! V_153 ) {
V_178 = false ;
goto V_230;
}
V_168 = (struct V_54 * ) V_93 ;
F_121 ( V_21 , V_33 , V_153 ,
V_121 , V_168 ) ;
V_33 -> V_135 = F_91 ( V_21 , V_33 ) ;
if ( V_33 -> V_135 != V_135 )
goto V_230;
} else {
if ( ! V_33 -> V_138 || V_121 != V_194 ||
V_33 -> V_135 != V_135 ) {
V_230:
F_37 ( V_59 , V_21 ,
L_39 ,
V_33 -> V_128 , V_121 , V_194 , V_135 ,
V_33 -> V_135 , V_153 ) ;
F_108 ( V_21 , V_33 , V_121 ,
V_135 , V_178 ) ;
return;
}
}
}
bool F_141 ( struct V_20 * V_21 ,
T_2 * V_35 )
{
struct V_26 * V_27 ;
bool V_123 = false ;
V_27 = F_11 ( V_21 , V_35 ) ;
if ( ! V_27 )
goto V_72;
V_123 = ! ! ( V_27 -> V_25 . V_36 & V_70 ) ;
F_17 ( V_27 ) ;
V_72:
return V_123 ;
}
bool F_142 ( struct V_20 * V_21 ,
T_2 * V_35 )
{
struct V_19 * V_22 ;
bool V_123 = false ;
V_22 = F_10 ( V_21 , V_35 ) ;
if ( ! V_22 )
goto V_72;
V_123 = V_22 -> V_25 . V_36 & V_70 ;
F_12 ( V_22 ) ;
V_72:
return V_123 ;
}
bool F_143 ( struct V_20 * V_21 ,
struct V_118 * V_33 ,
const unsigned char * V_35 )
{
bool V_123 = false ;
if ( F_117 ( V_21 , V_33 -> V_128 ) )
goto V_72;
if ( ! F_73 ( V_21 , V_33 , V_35 ,
V_125 ,
F_41 ( & V_33 -> V_134 ) ) )
goto V_72;
F_37 ( V_59 , V_21 ,
L_40 ,
V_35 , V_33 -> V_128 ) ;
V_123 = true ;
V_72:
return V_123 ;
}
