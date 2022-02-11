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
static void F_22 ( struct V_34 * V_35 )
{
struct V_13 * V_13 = V_35 -> V_36 ;
void * V_37 ;
V_37 = F_18 ( V_13 , V_28 ) ;
memset ( V_37 + V_35 -> V_38 , 0 , V_35 -> V_39 ) ;
F_20 ( V_37 , V_28 ) ;
F_23 ( V_13 ) ;
}
static void F_24 ( struct V_2 * V_2 , struct V_34 * V_35 ,
T_1 V_6 , int V_21 )
{
struct V_13 * V_13 = V_35 -> V_36 ;
unsigned char * V_37 , * V_40 ;
V_37 = F_18 ( V_13 , V_28 ) ;
V_40 = F_18 ( V_2 -> V_9 [ V_6 ] . V_13 , V_41 ) ;
memcpy ( V_37 + V_35 -> V_38 , V_40 + V_21 , V_35 -> V_39 ) ;
F_20 ( V_40 , V_41 ) ;
F_20 ( V_37 , V_28 ) ;
F_23 ( V_13 ) ;
}
static inline int F_25 ( struct V_34 * V_35 )
{
return V_35 -> V_39 != V_14 ;
}
static int F_26 ( struct V_2 * V_2 , struct V_34 * V_35 ,
T_1 V_6 , int V_21 , struct V_42 * V_42 )
{
int V_43 ;
T_3 V_19 ;
struct V_13 * V_13 ;
struct V_29 * V_44 ;
unsigned char * V_37 , * V_40 , * V_45 = NULL ;
V_13 = V_35 -> V_36 ;
if ( F_8 ( V_2 , V_6 , V_22 ) ) {
F_22 ( V_35 ) ;
return 0 ;
}
if ( F_16 ( ! V_2 -> V_9 [ V_6 ] . V_13 ) ) {
F_27 ( L_11 ,
( V_46 ) ( V_42 -> V_47 ) , V_42 -> V_48 ) ;
F_22 ( V_35 ) ;
return 0 ;
}
if ( F_16 ( F_8 ( V_2 , V_6 , V_25 ) ) ) {
F_24 ( V_2 , V_35 , V_6 , V_21 ) ;
return 0 ;
}
if ( F_25 ( V_35 ) ) {
V_45 = F_28 ( V_14 , V_49 ) ;
if ( ! V_45 ) {
F_14 ( L_12 ) ;
return - V_50 ;
}
}
V_37 = F_18 ( V_13 , V_28 ) ;
if ( ! F_25 ( V_35 ) )
V_45 = V_37 ;
V_19 = V_14 ;
V_40 = F_18 ( V_2 -> V_9 [ V_6 ] . V_13 , V_41 ) +
V_2 -> V_9 [ V_6 ] . V_21 ;
V_43 = F_29 ( V_40 + sizeof( * V_44 ) ,
F_19 ( V_40 ) - sizeof( * V_44 ) ,
V_45 , & V_19 ) ;
if ( F_25 ( V_35 ) ) {
memcpy ( V_37 + V_35 -> V_38 , V_45 + V_21 ,
V_35 -> V_39 ) ;
F_30 ( V_45 ) ;
}
F_20 ( V_40 , V_41 ) ;
F_20 ( V_37 , V_28 ) ;
if ( F_16 ( V_43 != V_51 ) ) {
F_31 ( L_13 , V_43 , V_6 ) ;
F_7 ( V_2 , & V_2 -> V_23 . V_52 ) ;
return V_43 ;
}
F_23 ( V_13 ) ;
return 0 ;
}
static int F_32 ( struct V_2 * V_2 , char * V_53 , T_1 V_6 )
{
int V_43 ;
T_3 V_19 = V_14 ;
struct V_29 * V_44 ;
unsigned char * V_40 ;
if ( F_8 ( V_2 , V_6 , V_22 ) ||
! V_2 -> V_9 [ V_6 ] . V_13 ) {
memset ( V_53 , 0 , V_14 ) ;
return 0 ;
}
V_40 = F_18 ( V_2 -> V_9 [ V_6 ] . V_13 , V_28 ) +
V_2 -> V_9 [ V_6 ] . V_21 ;
if ( F_16 ( F_8 ( V_2 , V_6 , V_25 ) ) ) {
memcpy ( V_53 , V_40 , V_14 ) ;
F_20 ( V_40 , V_28 ) ;
return 0 ;
}
V_43 = F_29 ( V_40 + sizeof( * V_44 ) ,
F_19 ( V_40 ) - sizeof( * V_44 ) ,
V_53 , & V_19 ) ;
F_20 ( V_40 , V_28 ) ;
if ( F_16 ( V_43 != V_51 ) ) {
F_31 ( L_13 , V_43 , V_6 ) ;
F_7 ( V_2 , & V_2 -> V_23 . V_52 ) ;
return V_43 ;
}
return 0 ;
}
static int F_33 ( struct V_2 * V_2 , struct V_34 * V_35 , T_1 V_6 ,
int V_21 )
{
int V_43 ;
T_1 V_54 ;
T_3 V_19 ;
struct V_29 * V_44 ;
struct V_13 * V_13 , * V_55 ;
unsigned char * V_37 , * V_40 , * V_56 , * V_45 = NULL ;
V_13 = V_35 -> V_36 ;
V_56 = V_2 -> V_57 ;
if ( F_25 ( V_35 ) ) {
V_45 = F_28 ( V_14 , V_49 ) ;
if ( ! V_45 ) {
F_14 ( L_12 ) ;
V_43 = - V_50 ;
goto V_27;
}
V_43 = F_32 ( V_2 , V_45 , V_6 ) ;
if ( V_43 ) {
F_30 ( V_45 ) ;
goto V_27;
}
}
if ( V_2 -> V_9 [ V_6 ] . V_13 ||
F_8 ( V_2 , V_6 , V_22 ) )
F_15 ( V_2 , V_6 ) ;
V_37 = F_18 ( V_13 , V_28 ) ;
if ( F_25 ( V_35 ) )
memcpy ( V_45 + V_21 , V_37 + V_35 -> V_38 ,
V_35 -> V_39 ) ;
else
V_45 = V_37 ;
if ( F_12 ( V_45 ) ) {
F_20 ( V_37 , V_28 ) ;
if ( F_25 ( V_35 ) )
F_30 ( V_45 ) ;
F_1 ( & V_2 -> V_23 . V_24 ) ;
F_10 ( V_2 , V_6 , V_22 ) ;
V_43 = 0 ;
goto V_27;
}
V_43 = F_34 ( V_45 , V_14 , V_56 , & V_19 ,
V_2 -> V_58 ) ;
F_20 ( V_37 , V_28 ) ;
if ( F_25 ( V_35 ) )
F_30 ( V_45 ) ;
if ( F_16 ( V_43 != V_51 ) ) {
F_31 ( L_14 , V_43 ) ;
goto V_27;
}
if ( F_16 ( V_19 > V_59 ) ) {
V_19 = V_14 ;
V_55 = F_35 ( V_60 | V_61 ) ;
if ( F_16 ( ! V_55 ) ) {
F_14 ( L_15
L_16 , V_6 ) ;
V_43 = - V_50 ;
goto V_27;
}
V_54 = 0 ;
F_10 ( V_2 , V_6 , V_25 ) ;
F_1 ( & V_2 -> V_23 . V_26 ) ;
V_2 -> V_9 [ V_6 ] . V_13 = V_55 ;
V_56 = F_18 ( V_13 , V_28 ) ;
goto V_62;
}
if ( F_36 ( V_2 -> V_30 , V_19 + sizeof( * V_44 ) ,
& V_2 -> V_9 [ V_6 ] . V_13 , & V_54 ,
V_60 | V_61 ) ) {
F_14 ( L_17
L_18 , V_6 , V_19 ) ;
V_43 = - V_50 ;
goto V_27;
}
V_62:
V_2 -> V_9 [ V_6 ] . V_21 = V_54 ;
V_40 = F_18 ( V_2 -> V_9 [ V_6 ] . V_13 , V_41 ) +
V_2 -> V_9 [ V_6 ] . V_21 ;
#if 0
if (!zram_test_flag(zram, index, ZRAM_UNCOMPRESSED)) {
zheader = (struct zobj_header *)cmem;
zheader->table_idx = index;
cmem += sizeof(*zheader);
}
#endif
memcpy ( V_40 , V_56 , V_19 ) ;
F_20 ( V_40 , V_41 ) ;
if ( F_16 ( F_8 ( V_2 , V_6 , V_25 ) ) )
F_20 ( V_56 , V_28 ) ;
F_3 ( V_2 , & V_2 -> V_23 . V_32 , V_19 ) ;
F_1 ( & V_2 -> V_23 . V_33 ) ;
if ( V_19 <= V_14 / 2 )
F_1 ( & V_2 -> V_23 . V_31 ) ;
return 0 ;
V_27:
if ( V_43 )
F_7 ( V_2 , & V_2 -> V_23 . V_63 ) ;
return V_43 ;
}
static int F_37 ( struct V_2 * V_2 , struct V_34 * V_35 , T_1 V_6 ,
int V_21 , struct V_42 * V_42 , int V_64 )
{
int V_43 ;
if ( V_64 == V_65 ) {
F_38 ( & V_2 -> V_66 ) ;
V_43 = F_26 ( V_2 , V_35 , V_6 , V_21 , V_42 ) ;
F_39 ( & V_2 -> V_66 ) ;
} else {
F_40 ( & V_2 -> V_66 ) ;
V_43 = F_33 ( V_2 , V_35 , V_6 , V_21 ) ;
F_41 ( & V_2 -> V_66 ) ;
}
return V_43 ;
}
static void F_42 ( T_1 * V_6 , int * V_21 , struct V_34 * V_35 )
{
if ( * V_21 + V_35 -> V_39 >= V_14 )
( * V_6 ) ++ ;
* V_21 = ( * V_21 + V_35 -> V_39 ) % V_14 ;
}
static void F_43 ( struct V_2 * V_2 , struct V_42 * V_42 , int V_64 )
{
int V_67 , V_21 ;
T_1 V_6 ;
struct V_34 * V_35 ;
switch ( V_64 ) {
case V_65 :
F_7 ( V_2 , & V_2 -> V_23 . V_68 ) ;
break;
case V_69 :
F_7 ( V_2 , & V_2 -> V_23 . V_70 ) ;
break;
}
V_6 = V_42 -> V_47 >> V_71 ;
V_21 = ( V_42 -> V_47 & ( V_72 - 1 ) ) << V_73 ;
F_44 (bvec, bio, i) {
int V_74 = V_14 - V_21 ;
if ( V_35 -> V_39 > V_74 ) {
struct V_34 V_75 ;
V_75 . V_36 = V_35 -> V_36 ;
V_75 . V_39 = V_74 ;
V_75 . V_38 = V_35 -> V_38 ;
if ( F_37 ( V_2 , & V_75 , V_6 , V_21 , V_42 , V_64 ) < 0 )
goto V_27;
V_75 . V_39 = V_35 -> V_39 - V_74 ;
V_75 . V_38 += V_74 ;
if ( F_37 ( V_2 , & V_75 , V_6 + 1 , 0 , V_42 , V_64 ) < 0 )
goto V_27;
} else
if ( F_37 ( V_2 , V_35 , V_6 , V_21 , V_42 , V_64 )
< 0 )
goto V_27;
F_42 ( & V_6 , & V_21 , V_35 ) ;
}
F_45 ( V_76 , & V_42 -> V_77 ) ;
F_46 ( V_42 , 0 ) ;
return;
V_27:
F_47 ( V_42 ) ;
}
static inline int F_48 ( struct V_2 * V_2 , struct V_42 * V_42 )
{
if ( F_16 (
( V_42 -> V_47 >= ( V_2 -> V_16 >> V_73 ) ) ||
( V_42 -> V_47 & ( V_78 - 1 ) ) ||
( V_42 -> V_48 & ( V_79 - 1 ) ) ) ) {
return 0 ;
}
return 1 ;
}
static void F_49 ( struct V_80 * V_81 , struct V_42 * V_42 )
{
struct V_2 * V_2 = V_81 -> V_82 ;
if ( F_16 ( ! V_2 -> V_83 ) && F_50 ( V_2 ) )
goto error;
F_38 ( & V_2 -> V_84 ) ;
if ( F_16 ( ! V_2 -> V_83 ) )
goto V_85;
if ( ! F_48 ( V_2 , V_42 ) ) {
F_7 ( V_2 , & V_2 -> V_23 . V_86 ) ;
goto V_85;
}
F_43 ( V_2 , V_42 , F_51 ( V_42 ) ) ;
F_39 ( & V_2 -> V_84 ) ;
return;
V_85:
F_39 ( & V_2 -> V_84 ) ;
error:
F_47 ( V_42 ) ;
}
void F_52 ( struct V_2 * V_2 )
{
T_3 V_6 ;
V_2 -> V_83 = 0 ;
F_30 ( V_2 -> V_58 ) ;
F_53 ( ( unsigned long ) V_2 -> V_57 , 1 ) ;
V_2 -> V_58 = NULL ;
V_2 -> V_57 = NULL ;
for ( V_6 = 0 ; V_6 < V_2 -> V_16 > > V_87 ; V_6 ++ ) {
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
F_54 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
F_55 ( V_2 -> V_30 ) ;
V_2 -> V_30 = NULL ;
memset ( & V_2 -> V_23 , 0 , sizeof( V_2 -> V_23 ) ) ;
V_2 -> V_16 = 0 ;
}
void F_56 ( struct V_2 * V_2 )
{
F_40 ( & V_2 -> V_84 ) ;
F_52 ( V_2 ) ;
F_41 ( & V_2 -> V_84 ) ;
}
int F_50 ( struct V_2 * V_2 )
{
int V_43 ;
T_3 V_88 ;
F_40 ( & V_2 -> V_84 ) ;
if ( V_2 -> V_83 ) {
F_41 ( & V_2 -> V_84 ) ;
return 0 ;
}
F_13 ( V_2 , V_89 << V_87 ) ;
V_2 -> V_58 = F_57 ( V_90 , V_49 ) ;
if ( ! V_2 -> V_58 ) {
F_31 ( L_19 ) ;
V_43 = - V_50 ;
goto V_91;
}
V_2 -> V_57 =
( void * ) F_58 ( V_49 | V_92 , 1 ) ;
if ( ! V_2 -> V_57 ) {
F_31 ( L_20 ) ;
V_43 = - V_50 ;
goto V_91;
}
V_88 = V_2 -> V_16 >> V_87 ;
V_2 -> V_9 = F_59 ( V_88 * sizeof( * V_2 -> V_9 ) ) ;
if ( ! V_2 -> V_9 ) {
F_31 ( L_21 ) ;
V_43 = - V_50 ;
goto V_91;
}
F_60 ( V_2 -> V_93 , V_2 -> V_16 >> V_73 ) ;
F_61 ( V_94 , V_2 -> V_93 -> V_81 ) ;
V_2 -> V_30 = F_62 () ;
if ( ! V_2 -> V_30 ) {
F_31 ( L_22 ) ;
V_43 = - V_50 ;
goto V_95;
}
V_2 -> V_83 = 1 ;
F_41 ( & V_2 -> V_84 ) ;
F_27 ( L_23 ) ;
return 0 ;
V_91:
V_2 -> V_16 = 0 ;
V_95:
F_52 ( V_2 ) ;
F_41 ( & V_2 -> V_84 ) ;
F_31 ( L_24 , V_43 ) ;
return V_43 ;
}
static void F_63 ( struct V_96 * V_97 ,
unsigned long V_6 )
{
struct V_2 * V_2 ;
V_2 = V_97 -> V_98 -> V_99 ;
F_15 ( V_2 , V_6 ) ;
F_7 ( V_2 , & V_2 -> V_23 . V_100 ) ;
}
static int F_64 ( struct V_2 * V_2 , int V_101 )
{
int V_43 = 0 ;
F_65 ( & V_2 -> V_66 ) ;
F_65 ( & V_2 -> V_84 ) ;
F_66 ( & V_2 -> V_4 ) ;
V_2 -> V_81 = F_67 ( V_49 ) ;
if ( ! V_2 -> V_81 ) {
F_31 ( L_25 ,
V_101 ) ;
V_43 = - V_50 ;
goto V_27;
}
F_68 ( V_2 -> V_81 , F_49 ) ;
V_2 -> V_81 -> V_82 = V_2 ;
V_2 -> V_93 = F_69 ( 1 ) ;
if ( ! V_2 -> V_93 ) {
F_70 ( V_2 -> V_81 ) ;
F_71 ( L_26 ,
V_101 ) ;
V_43 = - V_50 ;
goto V_27;
}
V_2 -> V_93 -> V_102 = V_103 ;
V_2 -> V_93 -> V_104 = V_101 ;
V_2 -> V_93 -> V_105 = & V_106 ;
V_2 -> V_93 -> V_81 = V_2 -> V_81 ;
V_2 -> V_93 -> V_99 = V_2 ;
snprintf ( V_2 -> V_93 -> V_107 , 16 , L_27 , V_101 ) ;
F_60 ( V_2 -> V_93 , 0 ) ;
F_72 ( V_2 -> V_93 -> V_81 , V_14 ) ;
F_73 ( V_2 -> V_93 -> V_81 ,
V_79 ) ;
F_74 ( V_2 -> V_93 -> V_81 , V_14 ) ;
F_75 ( V_2 -> V_93 -> V_81 , V_14 ) ;
F_76 ( V_2 -> V_93 ) ;
V_43 = F_77 ( & F_78 ( V_2 -> V_93 ) -> V_108 ,
& V_109 ) ;
if ( V_43 < 0 ) {
F_71 ( L_28 ) ;
goto V_27;
}
V_2 -> V_83 = 0 ;
V_27:
return V_43 ;
}
static void F_79 ( struct V_2 * V_2 )
{
F_80 ( & F_78 ( V_2 -> V_93 ) -> V_108 ,
& V_109 ) ;
if ( V_2 -> V_93 ) {
F_81 ( V_2 -> V_93 ) ;
F_82 ( V_2 -> V_93 ) ;
}
if ( V_2 -> V_81 )
F_70 ( V_2 -> V_81 ) ;
}
static int T_5 F_83 ( void )
{
int V_43 , V_110 ;
if ( V_111 > V_112 ) {
F_71 ( L_29 ,
V_111 ) ;
V_43 = - V_113 ;
goto V_27;
}
V_103 = F_84 ( 0 , L_30 ) ;
if ( V_103 <= 0 ) {
F_71 ( L_31 ) ;
V_43 = - V_114 ;
goto V_27;
}
if ( ! V_111 ) {
F_14 ( L_32 ) ;
V_111 = 1 ;
}
F_14 ( L_33 , V_111 ) ;
V_115 = F_57 ( V_111 * sizeof( struct V_2 ) , V_49 ) ;
if ( ! V_115 ) {
V_43 = - V_50 ;
goto V_116;
}
for ( V_110 = 0 ; V_110 < V_111 ; V_110 ++ ) {
V_43 = F_64 ( & V_115 [ V_110 ] , V_110 ) ;
if ( V_43 )
goto V_117;
}
return 0 ;
V_117:
while ( V_110 )
F_79 ( & V_115 [ -- V_110 ] ) ;
F_30 ( V_115 ) ;
V_116:
F_85 ( V_103 , L_30 ) ;
V_27:
return V_43 ;
}
static void T_6 F_86 ( void )
{
int V_67 ;
struct V_2 * V_2 ;
for ( V_67 = 0 ; V_67 < V_111 ; V_67 ++ ) {
V_2 = & V_115 [ V_67 ] ;
F_79 ( V_2 ) ;
if ( V_2 -> V_83 )
F_56 ( V_2 ) ;
}
F_85 ( V_103 , L_30 ) ;
F_30 ( V_115 ) ;
F_27 ( L_34 ) ;
}
