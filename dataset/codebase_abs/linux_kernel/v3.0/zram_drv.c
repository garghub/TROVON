static void F_1 ( T_1 * V_1 )
{
* V_1 = * V_1 + 1 ;
}
static void F_2 ( T_1 * V_1 )
{
* V_1 = * V_1 - 1 ;
}
static void F_3 ( struct V_2 * V_2 , T_2 * V_1 , T_2 V_3 )
{
F_4 ( & V_2 -> V_4 ) ;
* V_1 = * V_1 + V_3 ;
F_5 ( & V_2 -> V_4 ) ;
}
static void F_6 ( struct V_2 * V_2 , T_2 * V_1 , T_2 V_5 )
{
F_4 ( & V_2 -> V_4 ) ;
* V_1 = * V_1 - V_5 ;
F_5 ( & V_2 -> V_4 ) ;
}
static void F_7 ( struct V_2 * V_2 , T_2 * V_1 )
{
F_3 ( V_2 , V_1 , 1 ) ;
}
static int F_8 ( struct V_2 * V_2 , T_1 V_6 ,
enum V_7 V_8 )
{
return V_2 -> V_9 [ V_6 ] . V_10 & F_9 ( V_8 ) ;
}
static void F_10 ( struct V_2 * V_2 , T_1 V_6 ,
enum V_7 V_8 )
{
V_2 -> V_9 [ V_6 ] . V_10 |= F_9 ( V_8 ) ;
}
static void F_11 ( struct V_2 * V_2 , T_1 V_6 ,
enum V_7 V_8 )
{
V_2 -> V_9 [ V_6 ] . V_10 &= ~ F_9 ( V_8 ) ;
}
static int F_12 ( void * V_11 )
{
unsigned int V_12 ;
unsigned long * V_13 ;
V_13 = ( unsigned long * ) V_11 ;
for ( V_12 = 0 ; V_12 != V_14 / sizeof( * V_13 ) ; V_12 ++ ) {
if ( V_13 [ V_12 ] )
return 0 ;
}
return 1 ;
}
static void F_13 ( struct V_2 * V_2 , T_3 V_15 )
{
if ( ! V_2 -> V_16 ) {
F_14 (
L_1
L_2 ,
V_17
) ;
V_2 -> V_16 = V_17 *
( V_15 / 100 ) ;
}
if ( V_2 -> V_16 > 2 * ( V_15 ) ) {
F_14 (
L_3
L_4
L_5
L_6
L_7
L_8
L_9
L_10 ,
V_15 >> 10 , V_2 -> V_16
) ;
}
V_2 -> V_16 &= V_18 ;
}
static void F_15 ( struct V_2 * V_2 , T_3 V_6 )
{
T_1 V_19 ;
void * V_20 ;
struct V_13 * V_13 = V_2 -> V_9 [ V_6 ] . V_13 ;
T_1 V_21 = V_2 -> V_9 [ V_6 ] . V_21 ;
if ( F_16 ( ! V_13 ) ) {
if ( F_8 ( V_2 , V_6 , V_22 ) ) {
F_11 ( V_2 , V_6 , V_22 ) ;
F_2 ( & V_2 -> V_23 . V_24 ) ;
}
return;
}
if ( F_16 ( F_8 ( V_2 , V_6 , V_25 ) ) ) {
V_19 = V_14 ;
F_17 ( V_13 ) ;
F_11 ( V_2 , V_6 , V_25 ) ;
F_2 ( & V_2 -> V_23 . V_26 ) ;
goto V_27;
}
V_20 = F_18 ( V_13 , V_28 ) + V_21 ;
V_19 = F_19 ( V_20 ) - sizeof( struct V_29 ) ;
F_20 ( V_20 , V_28 ) ;
F_21 ( V_2 -> V_30 , V_13 , V_21 ) ;
if ( V_19 <= V_14 / 2 )
F_2 ( & V_2 -> V_23 . V_31 ) ;
V_27:
F_6 ( V_2 , & V_2 -> V_23 . V_32 , V_19 ) ;
F_2 ( & V_2 -> V_23 . V_33 ) ;
V_2 -> V_9 [ V_6 ] . V_13 = NULL ;
V_2 -> V_9 [ V_6 ] . V_21 = 0 ;
}
static void F_22 ( struct V_13 * V_13 )
{
void * V_34 ;
V_34 = F_18 ( V_13 , V_28 ) ;
memset ( V_34 , 0 , V_14 ) ;
F_20 ( V_34 , V_28 ) ;
F_23 ( V_13 ) ;
}
static void F_24 ( struct V_2 * V_2 ,
struct V_13 * V_13 , T_1 V_6 )
{
unsigned char * V_34 , * V_35 ;
V_34 = F_18 ( V_13 , V_28 ) ;
V_35 = F_18 ( V_2 -> V_9 [ V_6 ] . V_13 , V_36 ) +
V_2 -> V_9 [ V_6 ] . V_21 ;
memcpy ( V_34 , V_35 , V_14 ) ;
F_20 ( V_34 , V_28 ) ;
F_20 ( V_35 , V_36 ) ;
F_23 ( V_13 ) ;
}
static void F_25 ( struct V_2 * V_2 , struct V_37 * V_37 )
{
int V_38 ;
T_1 V_6 ;
struct V_39 * V_40 ;
F_7 ( V_2 , & V_2 -> V_23 . V_41 ) ;
V_6 = V_37 -> V_42 >> V_43 ;
F_26 (bvec, bio, i) {
int V_44 ;
T_3 V_19 ;
struct V_13 * V_13 ;
struct V_29 * V_45 ;
unsigned char * V_34 , * V_35 ;
V_13 = V_40 -> V_46 ;
if ( F_8 ( V_2 , V_6 , V_22 ) ) {
F_22 ( V_13 ) ;
V_6 ++ ;
continue;
}
if ( F_16 ( ! V_2 -> V_9 [ V_6 ] . V_13 ) ) {
F_27 ( L_11 ,
( V_47 ) ( V_37 -> V_42 ) , V_37 -> V_48 ) ;
F_22 ( V_13 ) ;
V_6 ++ ;
continue;
}
if ( F_16 ( F_8 ( V_2 , V_6 , V_25 ) ) ) {
F_24 ( V_2 , V_13 , V_6 ) ;
V_6 ++ ;
continue;
}
V_34 = F_18 ( V_13 , V_28 ) ;
V_19 = V_14 ;
V_35 = F_18 ( V_2 -> V_9 [ V_6 ] . V_13 , V_36 ) +
V_2 -> V_9 [ V_6 ] . V_21 ;
V_44 = F_28 (
V_35 + sizeof( * V_45 ) ,
F_19 ( V_35 ) - sizeof( * V_45 ) ,
V_34 , & V_19 ) ;
F_20 ( V_34 , V_28 ) ;
F_20 ( V_35 , V_36 ) ;
if ( F_16 ( V_44 != V_49 ) ) {
F_29 ( L_12 ,
V_44 , V_6 ) ;
F_7 ( V_2 , & V_2 -> V_23 . V_50 ) ;
goto V_27;
}
F_23 ( V_13 ) ;
V_6 ++ ;
}
F_30 ( V_51 , & V_37 -> V_52 ) ;
F_31 ( V_37 , 0 ) ;
return;
V_27:
F_32 ( V_37 ) ;
}
static void F_33 ( struct V_2 * V_2 , struct V_37 * V_37 )
{
int V_38 ;
T_1 V_6 ;
struct V_39 * V_40 ;
F_7 ( V_2 , & V_2 -> V_23 . V_53 ) ;
V_6 = V_37 -> V_42 >> V_43 ;
F_26 (bvec, bio, i) {
int V_44 ;
T_1 V_21 ;
T_3 V_19 ;
struct V_29 * V_45 ;
struct V_13 * V_13 , * V_54 ;
unsigned char * V_34 , * V_35 , * V_55 ;
V_13 = V_40 -> V_46 ;
V_55 = V_2 -> V_56 ;
if ( V_2 -> V_9 [ V_6 ] . V_13 ||
F_8 ( V_2 , V_6 , V_22 ) )
F_15 ( V_2 , V_6 ) ;
F_34 ( & V_2 -> V_57 ) ;
V_34 = F_18 ( V_13 , V_28 ) ;
if ( F_12 ( V_34 ) ) {
F_20 ( V_34 , V_28 ) ;
F_35 ( & V_2 -> V_57 ) ;
F_1 ( & V_2 -> V_23 . V_24 ) ;
F_10 ( V_2 , V_6 , V_22 ) ;
V_6 ++ ;
continue;
}
V_44 = F_36 ( V_34 , V_14 , V_55 , & V_19 ,
V_2 -> V_58 ) ;
F_20 ( V_34 , V_28 ) ;
if ( F_16 ( V_44 != V_49 ) ) {
F_35 ( & V_2 -> V_57 ) ;
F_29 ( L_13 , V_44 ) ;
F_7 ( V_2 , & V_2 -> V_23 . V_59 ) ;
goto V_27;
}
if ( F_16 ( V_19 > V_60 ) ) {
V_19 = V_14 ;
V_54 = F_37 ( V_61 | V_62 ) ;
if ( F_16 ( ! V_54 ) ) {
F_35 ( & V_2 -> V_57 ) ;
F_14 ( L_14
L_15 , V_6 ) ;
F_7 ( V_2 ,
& V_2 -> V_23 . V_59 ) ;
goto V_27;
}
V_21 = 0 ;
F_10 ( V_2 , V_6 , V_25 ) ;
F_1 ( & V_2 -> V_23 . V_26 ) ;
V_2 -> V_9 [ V_6 ] . V_13 = V_54 ;
V_55 = F_18 ( V_13 , V_28 ) ;
goto V_63;
}
if ( F_38 ( V_2 -> V_30 , V_19 + sizeof( * V_45 ) ,
& V_2 -> V_9 [ V_6 ] . V_13 , & V_21 ,
V_61 | V_62 ) ) {
F_35 ( & V_2 -> V_57 ) ;
F_14 ( L_16
L_17 , V_6 , V_19 ) ;
F_7 ( V_2 , & V_2 -> V_23 . V_59 ) ;
goto V_27;
}
V_63:
V_2 -> V_9 [ V_6 ] . V_21 = V_21 ;
V_35 = F_18 ( V_2 -> V_9 [ V_6 ] . V_13 , V_36 ) +
V_2 -> V_9 [ V_6 ] . V_21 ;
#if 0
if (!zram_test_flag(zram, index, ZRAM_UNCOMPRESSED)) {
zheader = (struct zobj_header *)cmem;
zheader->table_idx = index;
cmem += sizeof(*zheader);
}
#endif
memcpy ( V_35 , V_55 , V_19 ) ;
F_20 ( V_35 , V_36 ) ;
if ( F_16 ( F_8 ( V_2 , V_6 , V_25 ) ) )
F_20 ( V_55 , V_28 ) ;
F_3 ( V_2 , & V_2 -> V_23 . V_32 , V_19 ) ;
F_1 ( & V_2 -> V_23 . V_33 ) ;
if ( V_19 <= V_14 / 2 )
F_1 ( & V_2 -> V_23 . V_31 ) ;
F_35 ( & V_2 -> V_57 ) ;
V_6 ++ ;
}
F_30 ( V_51 , & V_37 -> V_52 ) ;
F_31 ( V_37 , 0 ) ;
return;
V_27:
F_32 ( V_37 ) ;
}
static inline int F_39 ( struct V_2 * V_2 , struct V_37 * V_37 )
{
if ( F_16 (
( V_37 -> V_42 >= ( V_2 -> V_16 >> V_64 ) ) ||
( V_37 -> V_42 & ( V_65 - 1 ) ) ||
( V_37 -> V_48 & ( V_14 - 1 ) ) ) ) {
return 0 ;
}
return 1 ;
}
static int F_40 ( struct V_66 * V_67 , struct V_37 * V_37 )
{
struct V_2 * V_2 = V_67 -> V_68 ;
if ( ! F_39 ( V_2 , V_37 ) ) {
F_7 ( V_2 , & V_2 -> V_23 . V_69 ) ;
F_32 ( V_37 ) ;
return 0 ;
}
if ( F_16 ( ! V_2 -> V_70 ) && F_41 ( V_2 ) ) {
F_32 ( V_37 ) ;
return 0 ;
}
switch ( F_42 ( V_37 ) ) {
case V_71 :
F_25 ( V_2 , V_37 ) ;
break;
case V_72 :
F_33 ( V_2 , V_37 ) ;
break;
}
return 0 ;
}
void F_43 ( struct V_2 * V_2 )
{
T_3 V_6 ;
F_34 ( & V_2 -> V_73 ) ;
V_2 -> V_70 = 0 ;
F_44 ( V_2 -> V_58 ) ;
F_45 ( ( unsigned long ) V_2 -> V_56 , 1 ) ;
V_2 -> V_58 = NULL ;
V_2 -> V_56 = NULL ;
for ( V_6 = 0 ; V_6 < V_2 -> V_16 > > V_74 ; V_6 ++ ) {
struct V_13 * V_13 ;
T_4 V_21 ;
V_13 = V_2 -> V_9 [ V_6 ] . V_13 ;
V_21 = V_2 -> V_9 [ V_6 ] . V_21 ;
if ( ! V_13 )
continue;
if ( F_16 ( F_8 ( V_2 , V_6 , V_25 ) ) )
F_17 ( V_13 ) ;
else
F_21 ( V_2 -> V_30 , V_13 , V_21 ) ;
}
F_46 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
F_47 ( V_2 -> V_30 ) ;
V_2 -> V_30 = NULL ;
memset ( & V_2 -> V_23 , 0 , sizeof( V_2 -> V_23 ) ) ;
V_2 -> V_16 = 0 ;
F_35 ( & V_2 -> V_73 ) ;
}
int F_41 ( struct V_2 * V_2 )
{
int V_44 ;
T_3 V_75 ;
F_34 ( & V_2 -> V_73 ) ;
if ( V_2 -> V_70 ) {
F_35 ( & V_2 -> V_73 ) ;
return 0 ;
}
F_13 ( V_2 , V_76 << V_74 ) ;
V_2 -> V_58 = F_48 ( V_77 , V_78 ) ;
if ( ! V_2 -> V_58 ) {
F_29 ( L_18 ) ;
V_44 = - V_79 ;
goto V_80;
}
V_2 -> V_56 = ( void * ) F_49 ( V_81 , 1 ) ;
if ( ! V_2 -> V_56 ) {
F_29 ( L_19 ) ;
V_44 = - V_79 ;
goto V_80;
}
V_75 = V_2 -> V_16 >> V_74 ;
V_2 -> V_9 = F_50 ( V_75 * sizeof( * V_2 -> V_9 ) ) ;
if ( ! V_2 -> V_9 ) {
F_29 ( L_20 ) ;
V_2 -> V_16 = 0 ;
V_44 = - V_79 ;
goto V_80;
}
F_51 ( V_2 -> V_82 , V_2 -> V_16 >> V_64 ) ;
F_52 ( V_83 , V_2 -> V_82 -> V_67 ) ;
V_2 -> V_30 = F_53 () ;
if ( ! V_2 -> V_30 ) {
F_29 ( L_21 ) ;
V_44 = - V_79 ;
goto V_80;
}
V_2 -> V_70 = 1 ;
F_35 ( & V_2 -> V_73 ) ;
F_27 ( L_22 ) ;
return 0 ;
V_80:
F_35 ( & V_2 -> V_73 ) ;
F_43 ( V_2 ) ;
F_29 ( L_23 , V_44 ) ;
return V_44 ;
}
void F_54 ( struct V_84 * V_85 , unsigned long V_6 )
{
struct V_2 * V_2 ;
V_2 = V_85 -> V_86 -> V_87 ;
F_15 ( V_2 , V_6 ) ;
F_7 ( V_2 , & V_2 -> V_23 . V_88 ) ;
}
static int F_55 ( struct V_2 * V_2 , int V_89 )
{
int V_44 = 0 ;
F_56 ( & V_2 -> V_57 ) ;
F_56 ( & V_2 -> V_73 ) ;
F_57 ( & V_2 -> V_4 ) ;
V_2 -> V_67 = F_58 ( V_78 ) ;
if ( ! V_2 -> V_67 ) {
F_29 ( L_24 ,
V_89 ) ;
V_44 = - V_79 ;
goto V_27;
}
F_59 ( V_2 -> V_67 , F_40 ) ;
V_2 -> V_67 -> V_68 = V_2 ;
V_2 -> V_82 = F_60 ( 1 ) ;
if ( ! V_2 -> V_82 ) {
F_61 ( V_2 -> V_67 ) ;
F_62 ( L_25 ,
V_89 ) ;
V_44 = - V_79 ;
goto V_27;
}
V_2 -> V_82 -> V_90 = V_91 ;
V_2 -> V_82 -> V_92 = V_89 ;
V_2 -> V_82 -> V_93 = & V_94 ;
V_2 -> V_82 -> V_67 = V_2 -> V_67 ;
V_2 -> V_82 -> V_87 = V_2 ;
snprintf ( V_2 -> V_82 -> V_95 , 16 , L_26 , V_89 ) ;
F_51 ( V_2 -> V_82 , 0 ) ;
F_63 ( V_2 -> V_82 -> V_67 , V_14 ) ;
F_64 ( V_2 -> V_82 -> V_67 ,
V_96 ) ;
F_65 ( V_2 -> V_82 -> V_67 , V_14 ) ;
F_66 ( V_2 -> V_82 -> V_67 , V_14 ) ;
F_67 ( V_2 -> V_82 ) ;
V_44 = F_68 ( & F_69 ( V_2 -> V_82 ) -> V_97 ,
& V_98 ) ;
if ( V_44 < 0 ) {
F_62 ( L_27 ) ;
goto V_27;
}
V_2 -> V_70 = 0 ;
V_27:
return V_44 ;
}
static void F_70 ( struct V_2 * V_2 )
{
F_71 ( & F_69 ( V_2 -> V_82 ) -> V_97 ,
& V_98 ) ;
if ( V_2 -> V_82 ) {
F_72 ( V_2 -> V_82 ) ;
F_73 ( V_2 -> V_82 ) ;
}
if ( V_2 -> V_67 )
F_61 ( V_2 -> V_67 ) ;
}
static int T_5 F_74 ( void )
{
int V_44 , V_99 ;
if ( V_100 > V_101 ) {
F_62 ( L_28 ,
V_100 ) ;
V_44 = - V_102 ;
goto V_27;
}
V_91 = F_75 ( 0 , L_29 ) ;
if ( V_91 <= 0 ) {
F_62 ( L_30 ) ;
V_44 = - V_103 ;
goto V_27;
}
if ( ! V_100 ) {
F_14 ( L_31 ) ;
V_100 = 1 ;
}
F_14 ( L_32 , V_100 ) ;
V_104 = F_48 ( V_100 * sizeof( struct V_2 ) , V_78 ) ;
if ( ! V_104 ) {
V_44 = - V_79 ;
goto V_105;
}
for ( V_99 = 0 ; V_99 < V_100 ; V_99 ++ ) {
V_44 = F_55 ( & V_104 [ V_99 ] , V_99 ) ;
if ( V_44 )
goto V_106;
}
return 0 ;
V_106:
while ( V_99 )
F_70 ( & V_104 [ -- V_99 ] ) ;
F_44 ( V_104 ) ;
V_105:
F_76 ( V_91 , L_29 ) ;
V_27:
return V_44 ;
}
static void T_6 F_77 ( void )
{
int V_38 ;
struct V_2 * V_2 ;
for ( V_38 = 0 ; V_38 < V_100 ; V_38 ++ ) {
V_2 = & V_104 [ V_38 ] ;
F_70 ( V_2 ) ;
if ( V_2 -> V_70 )
F_43 ( V_2 ) ;
}
F_76 ( V_91 , L_29 ) ;
F_44 ( V_104 ) ;
F_27 ( L_33 ) ;
}
