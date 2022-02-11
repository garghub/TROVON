struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( V_5 , V_6 ) ;
if ( F_3 ( ! V_4 ) )
return NULL ;
V_4 -> V_7 = V_3 ;
F_4 ( & V_4 -> V_8 ) ;
F_4 ( & V_4 -> V_9 ) ;
F_4 ( & V_4 -> V_10 ) ;
V_4 -> V_11 = NULL ;
F_5 ( & V_4 -> V_12 ) ;
F_6 ( & V_4 -> V_13 , 0 ) ;
V_4 -> V_14 = 0 ;
return V_4 ;
}
void F_7 ( struct V_1 * V_4 )
{
F_8 ( V_5 , V_4 ) ;
}
void F_9 ( struct V_1 * V_4 , T_1 V_15 ,
unsigned long V_16 , struct V_17 * V_18 )
{
V_4 -> V_19 = V_15 ;
F_10 ( V_18 , V_15 , & V_4 -> V_20 ,
& V_4 -> V_21 ) ;
V_4 -> V_22 = V_4 -> V_20 + V_16 ;
V_4 -> V_23 =
V_4 -> V_21 - V_4 -> V_22 + 1 ;
}
void F_11 ( struct V_1 * V_4 ,
struct V_1 * V_24 )
{
V_4 -> V_19 = V_24 -> V_19 ;
V_4 -> V_20 = V_24 -> V_20 ;
V_4 -> V_21 = V_24 -> V_21 ;
V_4 -> V_22 = V_24 -> V_22 + V_24 -> V_25 . V_26 ;
V_4 -> V_23 =
V_4 -> V_21 - V_4 -> V_22 + 1 ;
}
void F_12 ( struct V_1 * V_4 ,
T_1 V_27 , struct V_17 * V_18 )
{
V_4 -> V_28 = V_27 ;
V_4 -> V_25 . V_29 = F_13 ( V_18 , V_27 ) ;
}
int F_14 ( struct V_1 * V_4 )
{
struct V_30 * V_31 ;
V_31 = F_15 ( V_4 -> V_7 ,
V_4 -> V_22 + V_4 -> V_25 . V_32 ) ;
if ( F_3 ( ! V_31 ) )
return - V_33 ;
F_16 ( V_4 , V_31 ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_4 ,
struct V_30 * * V_34 )
{
struct V_30 * V_31 ;
V_31 = F_15 ( V_4 -> V_7 ,
V_4 -> V_22 + V_4 -> V_25 . V_26 ) ;
if ( F_3 ( ! V_31 ) )
return - V_33 ;
F_18 ( V_4 , V_31 ) ;
* V_34 = V_31 ;
return 0 ;
}
int F_19 ( struct V_1 * V_4 , unsigned V_35 ,
T_2 ctime , T_1 V_36 )
{
int V_37 ;
V_4 -> V_25 . V_26 = V_4 -> V_25 . V_32 = 0 ;
V_37 = F_14 ( V_4 ) ;
if ( F_3 ( V_37 ) )
return V_37 ;
V_4 -> V_25 . V_35 = V_35 ;
V_4 -> V_25 . V_38 = sizeof( struct V_39 ) ;
V_4 -> V_25 . V_40 = V_4 -> V_25 . V_41 = 0 ;
V_4 -> V_25 . ctime = ctime ;
V_4 -> V_25 . V_36 = V_36 ;
return 0 ;
}
void F_20 ( struct V_1 * V_4 )
{
struct V_39 * V_42 ;
struct V_30 * V_43 ;
V_43 = F_21 ( V_4 -> V_9 . V_29 ,
struct V_30 , V_44 ) ;
V_42 = (struct V_39 * ) V_43 -> V_45 ;
V_42 -> V_46 = F_22 ( V_47 ) ;
V_42 -> V_48 = F_23 ( sizeof( * V_42 ) ) ;
V_42 -> V_49 = F_23 ( V_4 -> V_25 . V_35 ) ;
V_42 -> V_50 = F_24 ( V_4 -> V_25 . V_51 ) ;
V_42 -> V_52 = F_24 ( V_4 -> V_25 . ctime ) ;
V_42 -> V_53 = F_24 ( V_4 -> V_25 . V_29 ) ;
V_42 -> V_54 = F_22 ( V_4 -> V_25 . V_26 ) ;
V_42 -> V_55 = F_22 ( V_4 -> V_25 . V_40 ) ;
V_42 -> V_56 = F_22 ( V_4 -> V_25 . V_38 ) ;
V_42 -> V_57 = 0 ;
V_42 -> V_58 = F_24 ( V_4 -> V_25 . V_36 ) ;
}
static void
F_25 ( struct V_1 * V_4 , T_3 V_59 )
{
struct V_30 * V_31 ;
struct V_39 * V_42 ;
unsigned long V_60 , V_61 = V_4 -> V_25 . V_38 ;
T_3 V_62 ;
V_31 = F_21 ( V_4 -> V_9 . V_29 , struct V_30 ,
V_44 ) ;
V_42 = (struct V_39 * ) V_31 -> V_45 ;
V_60 = F_26 (unsigned long, bytes, bh->b_size) ;
V_62 = F_27 ( V_59 ,
( unsigned char * ) V_42 +
sizeof( V_42 -> V_63 ) + sizeof( V_42 -> V_64 ) ,
V_60 - ( sizeof( V_42 -> V_63 ) +
sizeof( V_42 -> V_64 ) ) ) ;
F_28 (bh, &segbuf->sb_segsum_buffers,
b_assoc_buffers) {
V_61 -= V_60 ;
V_60 = F_26 (unsigned long, bytes, bh->b_size) ;
V_62 = F_27 ( V_62 , V_31 -> V_45 , V_60 ) ;
}
V_42 -> V_64 = F_22 ( V_62 ) ;
}
static void F_29 ( struct V_1 * V_4 ,
T_3 V_59 )
{
struct V_30 * V_31 ;
struct V_39 * V_42 ;
void * V_65 ;
T_3 V_62 ;
V_31 = F_21 ( V_4 -> V_9 . V_29 , struct V_30 ,
V_44 ) ;
V_42 = (struct V_39 * ) V_31 -> V_45 ;
V_62 = F_27 ( V_59 ,
( unsigned char * ) V_42 + sizeof( V_42 -> V_63 ) ,
V_31 -> V_66 - sizeof( V_42 -> V_63 ) ) ;
F_28 (bh, &segbuf->sb_segsum_buffers,
b_assoc_buffers) {
V_62 = F_27 ( V_62 , V_31 -> V_45 , V_31 -> V_66 ) ;
}
F_30 (bh, &segbuf->sb_payload_buffers, b_assoc_buffers) {
V_65 = F_31 ( V_31 -> V_67 ) ;
V_62 = F_27 ( V_62 , V_65 + F_32 ( V_31 ) , V_31 -> V_66 ) ;
F_33 ( V_65 ) ;
}
V_42 -> V_63 = F_22 ( V_62 ) ;
}
static void
F_34 ( struct V_1 * V_4 ,
T_3 V_59 )
{
struct V_68 * V_69 ;
struct V_17 * V_18 = V_4 -> V_7 -> V_70 ;
unsigned V_71 ;
T_3 V_62 ;
V_69 = (struct V_68 * ) V_4 -> V_11 -> V_45 ;
V_71 = F_35 ( V_18 -> V_72 ) ;
V_62 = F_27 ( V_59 ,
( unsigned char * ) V_69 + sizeof( V_69 -> V_73 ) ,
V_71 - sizeof( V_69 -> V_73 ) ) ;
V_69 -> V_73 = F_22 ( V_62 ) ;
}
static void F_36 ( struct V_74 * V_75 )
{
struct V_30 * V_31 , * V_76 ;
F_37 (bh, n, list, b_assoc_buffers) {
F_38 ( & V_31 -> V_44 ) ;
F_39 ( V_31 ) ;
}
}
static void F_40 ( struct V_1 * V_4 )
{
F_36 ( & V_4 -> V_9 ) ;
F_36 ( & V_4 -> V_10 ) ;
V_4 -> V_11 = NULL ;
}
void F_41 ( struct V_74 * V_77 )
{
struct V_1 * V_4 ;
F_30 (segbuf, logs, sb_list)
F_40 ( V_4 ) ;
}
void F_42 ( struct V_74 * V_77 ,
struct V_1 * V_78 )
{
struct V_1 * V_76 , * V_4 ;
V_4 = F_43 ( V_78 , V_77 , V_8 ) ;
F_44 (segbuf, n, logs, sb_list) {
F_38 ( & V_4 -> V_8 ) ;
F_40 ( V_4 ) ;
F_7 ( V_4 ) ;
}
}
int F_45 ( struct V_74 * V_77 , struct V_17 * V_18 )
{
struct V_1 * V_4 ;
int V_79 = 0 ;
F_30 (segbuf, logs, sb_list) {
V_79 = F_46 ( V_4 , V_18 ) ;
if ( V_79 )
break;
}
return V_79 ;
}
int F_47 ( struct V_74 * V_77 )
{
struct V_1 * V_4 ;
int V_37 , V_79 = 0 ;
F_30 (segbuf, logs, sb_list) {
V_37 = F_48 ( V_4 ) ;
if ( V_37 && ! V_79 )
V_79 = V_37 ;
}
return V_79 ;
}
void F_49 ( struct V_74 * V_77 , T_3 V_59 )
{
struct V_1 * V_4 ;
F_30 (segbuf, logs, sb_list) {
if ( V_4 -> V_11 )
F_34 ( V_4 , V_59 ) ;
F_25 ( V_4 , V_59 ) ;
F_29 ( V_4 , V_59 ) ;
}
}
static void F_50 ( struct V_80 * V_80 , int V_37 )
{
const int V_81 = F_51 ( V_82 , & V_80 -> V_83 ) ;
struct V_1 * V_4 = V_80 -> V_84 ;
if ( V_37 == - V_85 ) {
F_52 ( V_86 , & V_80 -> V_83 ) ;
}
if ( ! V_81 )
F_53 ( & V_4 -> V_13 ) ;
F_54 ( V_80 ) ;
F_55 ( & V_4 -> V_12 ) ;
}
static int F_56 ( struct V_1 * V_4 ,
struct V_87 * V_88 , int V_89 )
{
struct V_80 * V_80 = V_88 -> V_80 ;
int V_37 ;
if ( V_4 -> V_14 > 0 &&
F_57 ( V_4 -> V_7 -> V_90 ) ) {
F_58 ( & V_4 -> V_12 ) ;
V_4 -> V_14 -- ;
if ( F_3 ( F_59 ( & V_4 -> V_13 ) ) ) {
F_54 ( V_80 ) ;
V_37 = - V_91 ;
goto V_92;
}
}
V_80 -> V_93 = F_50 ;
V_80 -> V_84 = V_4 ;
F_60 ( V_80 ) ;
F_61 ( V_89 , V_80 ) ;
V_4 -> V_14 ++ ;
if ( F_62 ( V_80 , V_86 ) ) {
F_54 ( V_80 ) ;
V_37 = - V_85 ;
goto V_92;
}
F_54 ( V_80 ) ;
V_88 -> V_80 = NULL ;
V_88 -> V_94 -= V_88 -> V_95 - V_88 -> V_96 ;
V_88 -> V_97 = F_63 ( V_88 -> V_98 , V_88 -> V_94 ) ;
V_88 -> V_96 = V_88 -> V_95 ;
return 0 ;
V_92:
V_88 -> V_80 = NULL ;
return V_37 ;
}
static struct V_80 * F_64 ( struct V_17 * V_18 , T_4 V_96 ,
int V_97 )
{
struct V_80 * V_80 ;
V_80 = F_65 ( V_99 , V_97 ) ;
if ( V_80 == NULL ) {
while ( ! V_80 && ( V_97 >>= 1 ) )
V_80 = F_65 ( V_99 , V_97 ) ;
}
if ( F_66 ( V_80 ) ) {
V_80 -> V_100 = V_18 -> V_101 ;
V_80 -> V_102 . V_103 =
V_96 << ( V_18 -> V_104 - 9 ) ;
}
return V_80 ;
}
static void F_67 ( struct V_1 * V_4 ,
struct V_87 * V_88 )
{
V_88 -> V_80 = NULL ;
V_88 -> V_94 = V_4 -> V_25 . V_26 ;
V_88 -> V_98 = F_68 ( V_88 -> V_18 -> V_101 ) ;
V_88 -> V_97 = F_63 ( V_88 -> V_98 , V_88 -> V_94 ) ;
V_88 -> V_96 = V_88 -> V_95 = 0 ;
V_88 -> V_105 = V_4 -> V_22 ;
}
static int F_69 ( struct V_1 * V_4 ,
struct V_87 * V_88 ,
struct V_30 * V_31 , int V_89 )
{
int V_106 , V_37 ;
F_70 ( V_88 -> V_97 <= 0 ) ;
V_107:
if ( ! V_88 -> V_80 ) {
V_88 -> V_80 = F_64 ( V_88 -> V_18 , V_88 -> V_105 + V_88 -> V_95 ,
V_88 -> V_97 ) ;
if ( F_3 ( ! V_88 -> V_80 ) )
return - V_33 ;
}
V_106 = F_71 ( V_88 -> V_80 , V_31 -> V_67 , V_31 -> V_66 , F_32 ( V_31 ) ) ;
if ( V_106 == V_31 -> V_66 ) {
V_88 -> V_95 ++ ;
return 0 ;
}
V_37 = F_56 ( V_4 , V_88 , V_89 ) ;
if ( F_66 ( ! V_37 ) )
goto V_107;
return V_37 ;
}
static int F_46 ( struct V_1 * V_4 ,
struct V_17 * V_18 )
{
struct V_87 V_88 ;
struct V_30 * V_31 ;
int V_108 = 0 , V_109 = V_110 ;
V_88 . V_18 = V_18 ;
F_67 ( V_4 , & V_88 ) ;
F_30 (bh, &segbuf->sb_segsum_buffers, b_assoc_buffers) {
V_108 = F_69 ( V_4 , & V_88 , V_31 , V_109 ) ;
if ( F_3 ( V_108 ) )
goto V_111;
}
F_30 (bh, &segbuf->sb_payload_buffers, b_assoc_buffers) {
V_108 = F_69 ( V_4 , & V_88 , V_31 , V_109 ) ;
if ( F_3 ( V_108 ) )
goto V_111;
}
if ( V_88 . V_80 ) {
V_109 |= V_112 ;
V_108 = F_56 ( V_4 , & V_88 , V_109 ) ;
}
V_111:
return V_108 ;
}
static int F_48 ( struct V_1 * V_4 )
{
int V_37 = 0 ;
if ( ! V_4 -> V_14 )
return 0 ;
do {
F_58 ( & V_4 -> V_12 ) ;
} while ( -- V_4 -> V_14 > 0 );
if ( F_3 ( F_59 ( & V_4 -> V_13 ) > 0 ) ) {
F_72 ( V_113 L_1 ) ;
V_37 = - V_91 ;
}
return V_37 ;
}
