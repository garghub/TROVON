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
void * V_19 = V_2 -> V_9 [ V_6 ] . V_19 ;
if ( F_16 ( ! V_19 ) ) {
if ( F_8 ( V_2 , V_6 , V_20 ) ) {
F_11 ( V_2 , V_6 , V_20 ) ;
F_2 ( & V_2 -> V_21 . V_22 ) ;
}
return;
}
if ( F_16 ( F_8 ( V_2 , V_6 , V_23 ) ) ) {
F_17 ( V_19 ) ;
F_11 ( V_2 , V_6 , V_23 ) ;
F_2 ( & V_2 -> V_21 . V_24 ) ;
goto V_25;
}
F_18 ( V_2 -> V_26 , V_19 ) ;
if ( V_2 -> V_9 [ V_6 ] . V_27 <= V_14 / 2 )
F_2 ( & V_2 -> V_21 . V_28 ) ;
V_25:
F_6 ( V_2 , & V_2 -> V_21 . V_29 ,
V_2 -> V_9 [ V_6 ] . V_27 ) ;
F_2 ( & V_2 -> V_21 . V_30 ) ;
V_2 -> V_9 [ V_6 ] . V_19 = NULL ;
V_2 -> V_9 [ V_6 ] . V_27 = 0 ;
}
static void F_19 ( struct V_31 * V_32 )
{
struct V_13 * V_13 = V_32 -> V_33 ;
void * V_34 ;
V_34 = F_20 ( V_13 ) ;
memset ( V_34 + V_32 -> V_35 , 0 , V_32 -> V_36 ) ;
F_21 ( V_34 ) ;
F_22 ( V_13 ) ;
}
static void F_23 ( struct V_2 * V_2 , struct V_31 * V_32 ,
T_1 V_6 , int V_37 )
{
struct V_13 * V_13 = V_32 -> V_33 ;
unsigned char * V_34 , * V_38 ;
V_34 = F_20 ( V_13 ) ;
V_38 = F_20 ( V_2 -> V_9 [ V_6 ] . V_19 ) ;
memcpy ( V_34 + V_32 -> V_35 , V_38 + V_37 , V_32 -> V_36 ) ;
F_21 ( V_38 ) ;
F_21 ( V_34 ) ;
F_22 ( V_13 ) ;
}
static inline int F_24 ( struct V_31 * V_32 )
{
return V_32 -> V_36 != V_14 ;
}
static int F_25 ( struct V_2 * V_2 , struct V_31 * V_32 ,
T_1 V_6 , int V_37 , struct V_39 * V_39 )
{
int V_40 ;
T_3 V_41 ;
struct V_13 * V_13 ;
struct V_42 * V_43 ;
unsigned char * V_34 , * V_38 , * V_44 = NULL ;
V_13 = V_32 -> V_33 ;
if ( F_8 ( V_2 , V_6 , V_20 ) ) {
F_19 ( V_32 ) ;
return 0 ;
}
if ( F_16 ( ! V_2 -> V_9 [ V_6 ] . V_19 ) ) {
F_26 ( L_11 ,
( V_45 ) ( V_39 -> V_46 ) , V_39 -> V_47 ) ;
F_19 ( V_32 ) ;
return 0 ;
}
if ( F_16 ( F_8 ( V_2 , V_6 , V_23 ) ) ) {
F_23 ( V_2 , V_32 , V_6 , V_37 ) ;
return 0 ;
}
if ( F_24 ( V_32 ) ) {
V_44 = F_27 ( V_14 , V_48 ) ;
if ( ! V_44 ) {
F_14 ( L_12 ) ;
return - V_49 ;
}
}
V_34 = F_20 ( V_13 ) ;
if ( ! F_24 ( V_32 ) )
V_44 = V_34 ;
V_41 = V_14 ;
V_38 = F_28 ( V_2 -> V_26 , V_2 -> V_9 [ V_6 ] . V_19 ) ;
V_40 = F_29 ( V_38 + sizeof( * V_43 ) ,
V_2 -> V_9 [ V_6 ] . V_27 ,
V_44 , & V_41 ) ;
if ( F_24 ( V_32 ) ) {
memcpy ( V_34 + V_32 -> V_35 , V_44 + V_37 ,
V_32 -> V_36 ) ;
F_30 ( V_44 ) ;
}
F_31 ( V_2 -> V_26 , V_2 -> V_9 [ V_6 ] . V_19 ) ;
F_21 ( V_34 ) ;
if ( F_16 ( V_40 != V_50 ) ) {
F_32 ( L_13 , V_40 , V_6 ) ;
F_7 ( V_2 , & V_2 -> V_21 . V_51 ) ;
return V_40 ;
}
F_22 ( V_13 ) ;
return 0 ;
}
static int F_33 ( struct V_2 * V_2 , char * V_52 , T_1 V_6 )
{
int V_40 ;
T_3 V_41 = V_14 ;
struct V_42 * V_43 ;
unsigned char * V_38 ;
if ( F_8 ( V_2 , V_6 , V_20 ) ||
! V_2 -> V_9 [ V_6 ] . V_19 ) {
memset ( V_52 , 0 , V_14 ) ;
return 0 ;
}
V_38 = F_28 ( V_2 -> V_26 , V_2 -> V_9 [ V_6 ] . V_19 ) ;
if ( F_16 ( F_8 ( V_2 , V_6 , V_23 ) ) ) {
memcpy ( V_52 , V_38 , V_14 ) ;
F_21 ( V_38 ) ;
return 0 ;
}
V_40 = F_29 ( V_38 + sizeof( * V_43 ) ,
V_2 -> V_9 [ V_6 ] . V_27 ,
V_52 , & V_41 ) ;
F_31 ( V_2 -> V_26 , V_2 -> V_9 [ V_6 ] . V_19 ) ;
if ( F_16 ( V_40 != V_50 ) ) {
F_32 ( L_13 , V_40 , V_6 ) ;
F_7 ( V_2 , & V_2 -> V_21 . V_51 ) ;
return V_40 ;
}
return 0 ;
}
static int F_34 ( struct V_2 * V_2 , struct V_31 * V_32 , T_1 V_6 ,
int V_37 )
{
int V_40 ;
T_1 V_53 ;
T_3 V_41 ;
void * V_19 ;
struct V_42 * V_43 ;
struct V_13 * V_13 , * V_54 ;
unsigned char * V_34 , * V_38 , * V_55 , * V_44 = NULL ;
V_13 = V_32 -> V_33 ;
V_55 = V_2 -> V_56 ;
if ( F_24 ( V_32 ) ) {
V_44 = F_27 ( V_14 , V_48 ) ;
if ( ! V_44 ) {
F_14 ( L_12 ) ;
V_40 = - V_49 ;
goto V_25;
}
V_40 = F_33 ( V_2 , V_44 , V_6 ) ;
if ( V_40 ) {
F_30 ( V_44 ) ;
goto V_25;
}
}
if ( V_2 -> V_9 [ V_6 ] . V_19 ||
F_8 ( V_2 , V_6 , V_20 ) )
F_15 ( V_2 , V_6 ) ;
V_34 = F_20 ( V_13 ) ;
if ( F_24 ( V_32 ) )
memcpy ( V_44 + V_37 , V_34 + V_32 -> V_35 ,
V_32 -> V_36 ) ;
else
V_44 = V_34 ;
if ( F_12 ( V_44 ) ) {
F_21 ( V_34 ) ;
if ( F_24 ( V_32 ) )
F_30 ( V_44 ) ;
F_1 ( & V_2 -> V_21 . V_22 ) ;
F_10 ( V_2 , V_6 , V_20 ) ;
V_40 = 0 ;
goto V_25;
}
V_40 = F_35 ( V_44 , V_14 , V_55 , & V_41 ,
V_2 -> V_57 ) ;
F_21 ( V_34 ) ;
if ( F_24 ( V_32 ) )
F_30 ( V_44 ) ;
if ( F_16 ( V_40 != V_50 ) ) {
F_32 ( L_14 , V_40 ) ;
goto V_25;
}
if ( F_16 ( V_41 > V_58 ) ) {
V_41 = V_14 ;
V_54 = F_36 ( V_59 | V_60 ) ;
if ( F_16 ( ! V_54 ) ) {
F_14 ( L_15
L_16 , V_6 ) ;
V_40 = - V_49 ;
goto V_25;
}
V_53 = 0 ;
F_10 ( V_2 , V_6 , V_23 ) ;
F_1 ( & V_2 -> V_21 . V_24 ) ;
V_19 = V_54 ;
V_55 = F_20 ( V_13 ) ;
V_38 = F_20 ( V_54 ) ;
goto V_61;
}
V_19 = F_37 ( V_2 -> V_26 , V_41 + sizeof( * V_43 ) ) ;
if ( ! V_19 ) {
F_14 ( L_17
L_18 , V_6 , V_41 ) ;
V_40 = - V_49 ;
goto V_25;
}
V_38 = F_28 ( V_2 -> V_26 , V_19 ) ;
V_61:
#if 0
if (!zram_test_flag(zram, index, ZRAM_UNCOMPRESSED)) {
zheader = (struct zobj_header *)cmem;
zheader->table_idx = index;
cmem += sizeof(*zheader);
}
#endif
memcpy ( V_38 , V_55 , V_41 ) ;
if ( F_16 ( F_8 ( V_2 , V_6 , V_23 ) ) ) {
F_21 ( V_38 ) ;
F_21 ( V_55 ) ;
} else {
F_31 ( V_2 -> V_26 , V_19 ) ;
}
V_2 -> V_9 [ V_6 ] . V_19 = V_19 ;
V_2 -> V_9 [ V_6 ] . V_27 = V_41 ;
F_3 ( V_2 , & V_2 -> V_21 . V_29 , V_41 ) ;
F_1 ( & V_2 -> V_21 . V_30 ) ;
if ( V_41 <= V_14 / 2 )
F_1 ( & V_2 -> V_21 . V_28 ) ;
return 0 ;
V_25:
if ( V_40 )
F_7 ( V_2 , & V_2 -> V_21 . V_62 ) ;
return V_40 ;
}
static int F_38 ( struct V_2 * V_2 , struct V_31 * V_32 , T_1 V_6 ,
int V_37 , struct V_39 * V_39 , int V_63 )
{
int V_40 ;
if ( V_63 == V_64 ) {
F_39 ( & V_2 -> V_65 ) ;
V_40 = F_25 ( V_2 , V_32 , V_6 , V_37 , V_39 ) ;
F_40 ( & V_2 -> V_65 ) ;
} else {
F_41 ( & V_2 -> V_65 ) ;
V_40 = F_34 ( V_2 , V_32 , V_6 , V_37 ) ;
F_42 ( & V_2 -> V_65 ) ;
}
return V_40 ;
}
static void F_43 ( T_1 * V_6 , int * V_37 , struct V_31 * V_32 )
{
if ( * V_37 + V_32 -> V_36 >= V_14 )
( * V_6 ) ++ ;
* V_37 = ( * V_37 + V_32 -> V_36 ) % V_14 ;
}
static void F_44 ( struct V_2 * V_2 , struct V_39 * V_39 , int V_63 )
{
int V_66 , V_37 ;
T_1 V_6 ;
struct V_31 * V_32 ;
switch ( V_63 ) {
case V_64 :
F_7 ( V_2 , & V_2 -> V_21 . V_67 ) ;
break;
case V_68 :
F_7 ( V_2 , & V_2 -> V_21 . V_69 ) ;
break;
}
V_6 = V_39 -> V_46 >> V_70 ;
V_37 = ( V_39 -> V_46 & ( V_71 - 1 ) ) << V_72 ;
F_45 (bvec, bio, i) {
int V_73 = V_14 - V_37 ;
if ( V_32 -> V_36 > V_73 ) {
struct V_31 V_74 ;
V_74 . V_33 = V_32 -> V_33 ;
V_74 . V_36 = V_73 ;
V_74 . V_35 = V_32 -> V_35 ;
if ( F_38 ( V_2 , & V_74 , V_6 , V_37 , V_39 , V_63 ) < 0 )
goto V_25;
V_74 . V_36 = V_32 -> V_36 - V_73 ;
V_74 . V_35 += V_73 ;
if ( F_38 ( V_2 , & V_74 , V_6 + 1 , 0 , V_39 , V_63 ) < 0 )
goto V_25;
} else
if ( F_38 ( V_2 , V_32 , V_6 , V_37 , V_39 , V_63 )
< 0 )
goto V_25;
F_43 ( & V_6 , & V_37 , V_32 ) ;
}
F_46 ( V_75 , & V_39 -> V_76 ) ;
F_47 ( V_39 , 0 ) ;
return;
V_25:
F_48 ( V_39 ) ;
}
static inline int F_49 ( struct V_2 * V_2 , struct V_39 * V_39 )
{
if ( F_16 (
( V_39 -> V_46 >= ( V_2 -> V_16 >> V_72 ) ) ||
( V_39 -> V_46 & ( V_77 - 1 ) ) ||
( V_39 -> V_47 & ( V_78 - 1 ) ) ) ) {
return 0 ;
}
return 1 ;
}
static void F_50 ( struct V_79 * V_80 , struct V_39 * V_39 )
{
struct V_2 * V_2 = V_80 -> V_81 ;
if ( F_16 ( ! V_2 -> V_82 ) && F_51 ( V_2 ) )
goto error;
F_39 ( & V_2 -> V_83 ) ;
if ( F_16 ( ! V_2 -> V_82 ) )
goto V_84;
if ( ! F_49 ( V_2 , V_39 ) ) {
F_7 ( V_2 , & V_2 -> V_21 . V_85 ) ;
goto V_84;
}
F_44 ( V_2 , V_39 , F_52 ( V_39 ) ) ;
F_40 ( & V_2 -> V_83 ) ;
return;
V_84:
F_40 ( & V_2 -> V_83 ) ;
error:
F_48 ( V_39 ) ;
}
void F_53 ( struct V_2 * V_2 )
{
T_3 V_6 ;
V_2 -> V_82 = 0 ;
F_30 ( V_2 -> V_57 ) ;
F_54 ( ( unsigned long ) V_2 -> V_56 , 1 ) ;
V_2 -> V_57 = NULL ;
V_2 -> V_56 = NULL ;
for ( V_6 = 0 ; V_6 < V_2 -> V_16 > > V_86 ; V_6 ++ ) {
void * V_19 = V_2 -> V_9 [ V_6 ] . V_19 ;
if ( ! V_19 )
continue;
if ( F_16 ( F_8 ( V_2 , V_6 , V_23 ) ) )
F_17 ( V_19 ) ;
else
F_18 ( V_2 -> V_26 , V_19 ) ;
}
F_55 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
F_56 ( V_2 -> V_26 ) ;
V_2 -> V_26 = NULL ;
memset ( & V_2 -> V_21 , 0 , sizeof( V_2 -> V_21 ) ) ;
V_2 -> V_16 = 0 ;
}
void F_57 ( struct V_2 * V_2 )
{
F_41 ( & V_2 -> V_83 ) ;
F_53 ( V_2 ) ;
F_42 ( & V_2 -> V_83 ) ;
}
int F_51 ( struct V_2 * V_2 )
{
int V_40 ;
T_3 V_87 ;
F_41 ( & V_2 -> V_83 ) ;
if ( V_2 -> V_82 ) {
F_42 ( & V_2 -> V_83 ) ;
return 0 ;
}
F_13 ( V_2 , V_88 << V_86 ) ;
V_2 -> V_57 = F_58 ( V_89 , V_48 ) ;
if ( ! V_2 -> V_57 ) {
F_32 ( L_19 ) ;
V_40 = - V_49 ;
goto V_90;
}
V_2 -> V_56 =
( void * ) F_59 ( V_48 | V_91 , 1 ) ;
if ( ! V_2 -> V_56 ) {
F_32 ( L_20 ) ;
V_40 = - V_49 ;
goto V_90;
}
V_87 = V_2 -> V_16 >> V_86 ;
V_2 -> V_9 = F_60 ( V_87 * sizeof( * V_2 -> V_9 ) ) ;
if ( ! V_2 -> V_9 ) {
F_32 ( L_21 ) ;
V_40 = - V_49 ;
goto V_90;
}
F_61 ( V_2 -> V_92 , V_2 -> V_16 >> V_72 ) ;
F_62 ( V_93 , V_2 -> V_92 -> V_80 ) ;
V_2 -> V_26 = F_63 ( L_22 , V_59 | V_60 ) ;
if ( ! V_2 -> V_26 ) {
F_32 ( L_23 ) ;
V_40 = - V_49 ;
goto V_94;
}
V_2 -> V_82 = 1 ;
F_42 ( & V_2 -> V_83 ) ;
F_26 ( L_24 ) ;
return 0 ;
V_90:
V_2 -> V_16 = 0 ;
V_94:
F_53 ( V_2 ) ;
F_42 ( & V_2 -> V_83 ) ;
F_32 ( L_25 , V_40 ) ;
return V_40 ;
}
static void F_64 ( struct V_95 * V_96 ,
unsigned long V_6 )
{
struct V_2 * V_2 ;
V_2 = V_96 -> V_97 -> V_98 ;
F_15 ( V_2 , V_6 ) ;
F_7 ( V_2 , & V_2 -> V_21 . V_99 ) ;
}
static int F_65 ( struct V_2 * V_2 , int V_100 )
{
int V_40 = 0 ;
F_66 ( & V_2 -> V_65 ) ;
F_66 ( & V_2 -> V_83 ) ;
F_67 ( & V_2 -> V_4 ) ;
V_2 -> V_80 = F_68 ( V_48 ) ;
if ( ! V_2 -> V_80 ) {
F_32 ( L_26 ,
V_100 ) ;
V_40 = - V_49 ;
goto V_25;
}
F_69 ( V_2 -> V_80 , F_50 ) ;
V_2 -> V_80 -> V_81 = V_2 ;
V_2 -> V_92 = F_70 ( 1 ) ;
if ( ! V_2 -> V_92 ) {
F_71 ( V_2 -> V_80 ) ;
F_72 ( L_27 ,
V_100 ) ;
V_40 = - V_49 ;
goto V_25;
}
V_2 -> V_92 -> V_101 = V_102 ;
V_2 -> V_92 -> V_103 = V_100 ;
V_2 -> V_92 -> V_104 = & V_105 ;
V_2 -> V_92 -> V_80 = V_2 -> V_80 ;
V_2 -> V_92 -> V_98 = V_2 ;
snprintf ( V_2 -> V_92 -> V_106 , 16 , L_28 , V_100 ) ;
F_61 ( V_2 -> V_92 , 0 ) ;
F_73 ( V_2 -> V_92 -> V_80 , V_14 ) ;
F_74 ( V_2 -> V_92 -> V_80 ,
V_78 ) ;
F_75 ( V_2 -> V_92 -> V_80 , V_14 ) ;
F_76 ( V_2 -> V_92 -> V_80 , V_14 ) ;
F_77 ( V_2 -> V_92 ) ;
V_40 = F_78 ( & F_79 ( V_2 -> V_92 ) -> V_107 ,
& V_108 ) ;
if ( V_40 < 0 ) {
F_72 ( L_29 ) ;
goto V_25;
}
V_2 -> V_82 = 0 ;
V_25:
return V_40 ;
}
static void F_80 ( struct V_2 * V_2 )
{
F_81 ( & F_79 ( V_2 -> V_92 ) -> V_107 ,
& V_108 ) ;
if ( V_2 -> V_92 ) {
F_82 ( V_2 -> V_92 ) ;
F_83 ( V_2 -> V_92 ) ;
}
if ( V_2 -> V_80 )
F_71 ( V_2 -> V_80 ) ;
}
unsigned int F_84 ( void )
{
return V_109 ;
}
static int T_4 F_85 ( void )
{
int V_40 , V_110 ;
if ( V_109 > V_111 ) {
F_72 ( L_30 ,
V_109 ) ;
V_40 = - V_112 ;
goto V_25;
}
V_102 = F_86 ( 0 , L_22 ) ;
if ( V_102 <= 0 ) {
F_72 ( L_31 ) ;
V_40 = - V_113 ;
goto V_25;
}
if ( ! V_109 ) {
F_14 ( L_32 ) ;
V_109 = 1 ;
}
F_14 ( L_33 , V_109 ) ;
V_114 = F_58 ( V_109 * sizeof( struct V_2 ) , V_48 ) ;
if ( ! V_114 ) {
V_40 = - V_49 ;
goto V_115;
}
for ( V_110 = 0 ; V_110 < V_109 ; V_110 ++ ) {
V_40 = F_65 ( & V_114 [ V_110 ] , V_110 ) ;
if ( V_40 )
goto V_116;
}
return 0 ;
V_116:
while ( V_110 )
F_80 ( & V_114 [ -- V_110 ] ) ;
F_30 ( V_114 ) ;
V_115:
F_87 ( V_102 , L_22 ) ;
V_25:
return V_40 ;
}
static void T_5 F_88 ( void )
{
int V_66 ;
struct V_2 * V_2 ;
for ( V_66 = 0 ; V_66 < V_109 ; V_66 ++ ) {
V_2 = & V_114 [ V_66 ] ;
F_80 ( V_2 ) ;
if ( V_2 -> V_82 )
F_57 ( V_2 ) ;
}
F_87 ( V_102 , L_22 ) ;
F_30 ( V_114 ) ;
F_26 ( L_34 ) ;
}
