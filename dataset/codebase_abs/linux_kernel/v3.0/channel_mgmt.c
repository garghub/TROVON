void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 )
{
if ( V_2 -> V_6 == V_7 ) {
V_2 -> V_8 = 0x10 ;
V_4 = (struct V_3 * ) & V_5 [
sizeof( struct V_9 ) +
sizeof( struct V_1 ) ] ;
if ( V_4 -> V_10 == 2 &&
V_4 -> V_11 [ 1 ] . V_12 == 3 ) {
V_4 -> V_11 [ 0 ] . V_12 = 3 ;
V_4 -> V_11 [ 0 ] . V_13 = 0 ;
V_4 -> V_11 [ 1 ] . V_12 = 3 ;
V_4 -> V_11 [ 1 ] . V_13 = 0 ;
} else {
V_4 -> V_11 [ 0 ] . V_12 = 1 ;
V_4 -> V_11 [ 0 ] . V_13 = 0 ;
V_4 -> V_11 [ 1 ] . V_12 = 1 ;
V_4 -> V_11 [ 1 ] . V_13 = 0 ;
}
V_4 -> V_10 = 1 ;
V_4 -> V_14 = 1 ;
}
}
void F_2 ( void * V_15 )
{
struct V_16 * V_17 = V_15 ;
T_1 * V_5 ;
T_2 V_18 , V_19 ;
T_3 V_20 ;
struct V_1 * V_2 ;
struct V_3 * V_4 = NULL ;
if ( V_17 -> V_21 >= 0 ) {
if ( V_22 [ V_17 -> V_21 ] . V_23 != NULL ) {
V_17 -> V_24 =
V_22 [ V_17 -> V_21 ] . V_23 ;
( V_22 [ V_17 -> V_21 ] . V_23 ) ( V_17 ) ;
return;
}
}
V_18 = V_25 ;
V_5 = F_3 ( V_18 , V_26 ) ;
F_4 ( V_17 , V_5 , V_18 , & V_19 , & V_20 ) ;
if ( V_19 > 0 ) {
V_2 = (struct V_1 * ) & V_5 [
sizeof( struct V_9 ) ] ;
F_1 ( V_2 , V_4 , V_5 ) ;
V_2 -> V_27 = V_28
| V_29 ;
F_5 ( V_17 , V_5 ,
V_19 , V_20 ,
V_30 , 0 ) ;
}
F_6 ( V_5 ) ;
}
static struct V_16 * F_7 ( void )
{
struct V_16 * V_17 ;
V_17 = F_8 ( sizeof( * V_17 ) , V_26 ) ;
if ( ! V_17 )
return NULL ;
F_9 ( & V_17 -> V_31 ) ;
F_10 ( & V_17 -> V_32 ) ;
V_17 -> V_32 . V_33 = ( unsigned long ) V_17 ;
V_17 -> V_32 . V_34 = V_35 ;
V_17 -> V_36 = F_11 ( L_1 ) ;
if ( ! V_17 -> V_36 ) {
F_6 ( V_17 ) ;
return NULL ;
}
return V_17 ;
}
static void F_12 ( struct V_37 * V_38 )
{
struct V_16 * V_17 = F_13 ( V_38 ,
struct V_16 ,
V_38 ) ;
F_14 ( V_17 -> V_36 ) ;
F_6 ( V_17 ) ;
}
void F_15 ( struct V_16 * V_17 )
{
F_16 ( & V_17 -> V_32 ) ;
F_17 ( & V_17 -> V_38 , F_12 ) ;
F_18 ( V_39 . V_40 , & V_17 -> V_38 ) ;
}
static void F_19 ( struct V_37 * V_38 )
{
struct V_16 * V_17 = F_13 ( V_38 ,
struct V_16 ,
V_38 ) ;
F_20 ( V_17 -> V_41 ) ;
}
static void F_21 ( struct V_37 * V_38 )
{
struct V_16 * V_42 = F_13 ( V_38 ,
struct V_16 ,
V_38 ) ;
struct V_16 * V_17 ;
bool V_43 = true ;
int V_44 ;
int V_45 ;
unsigned long V_46 ;
F_17 ( & V_42 -> V_38 , F_19 ) ;
F_22 ( & V_39 . V_47 , V_46 ) ;
F_23 (channel, &vmbus_connection.chn_list, listentry) {
if ( ! memcmp ( & V_17 -> V_48 . V_49 . V_50 ,
& V_42 -> V_48 . V_49 . V_50 ,
sizeof( struct V_51 ) ) &&
! memcmp ( & V_17 -> V_48 . V_49 . V_52 ,
& V_42 -> V_48 . V_49 . V_52 ,
sizeof( struct V_51 ) ) ) {
V_43 = false ;
break;
}
}
if ( V_43 )
F_24 ( & V_42 -> V_53 ,
& V_39 . V_54 ) ;
F_25 ( & V_39 . V_47 , V_46 ) ;
if ( ! V_43 ) {
F_15 ( V_42 ) ;
return;
}
V_42 -> V_41 = F_26 (
& V_42 -> V_48 . V_49 . V_50 ,
& V_42 -> V_48 . V_49 . V_52 ,
V_42 ) ;
V_44 = F_27 ( V_42 -> V_41 ) ;
if ( V_44 != 0 ) {
F_28 ( L_2 ,
V_42 -> V_48 . V_55 ) ;
F_22 ( & V_39 . V_47 , V_46 ) ;
F_29 ( & V_42 -> V_53 ) ;
F_25 ( & V_39 . V_47 , V_46 ) ;
F_15 ( V_42 ) ;
} else {
V_42 -> V_56 = V_57 ;
V_42 -> V_21 = - 1 ;
for ( V_45 = 0 ; V_45 < V_58 ; V_45 ++ ) {
if ( memcmp ( & V_42 -> V_48 . V_49 . V_50 ,
& V_22 [ V_45 ] . V_33 ,
sizeof( struct V_51 ) ) == 0 &&
F_30 ( V_42 , 2 * V_25 ,
2 * V_25 , NULL , 0 ,
F_2 ,
V_42 ) == 0 ) {
V_22 [ V_45 ] . V_17 = V_42 ;
V_42 -> V_21 = V_45 ;
F_31 ( L_3 , V_22 [ V_45 ] . V_59 ) ;
}
}
}
}
static void F_32 ( struct V_60 * V_61 )
{
struct V_62 * V_49 ;
struct V_16 * V_42 ;
struct V_51 * V_63 ;
struct V_51 * V_64 ;
int V_65 ;
int V_66 = 0 ;
V_49 = (struct V_62 * ) V_61 ;
for ( V_65 = 0 ; V_65 < V_67 ; V_65 ++ ) {
if ( memcmp ( & V_49 -> V_49 . V_50 ,
& V_68 [ V_65 ] ,
sizeof( struct V_51 ) ) == 0 ) {
V_66 = 1 ;
break;
}
}
if ( ! V_66 )
return;
V_63 = & V_49 -> V_49 . V_50 ;
V_64 = & V_49 -> V_49 . V_52 ;
V_42 = F_7 () ;
if ( ! V_42 ) {
F_28 ( L_4 ) ;
return;
}
memcpy ( & V_42 -> V_48 , V_49 ,
sizeof( struct V_62 ) ) ;
V_42 -> V_69 = ( T_1 ) V_49 -> V_70 / 32 ;
V_42 -> V_71 = ( T_1 ) V_49 -> V_70 % 32 ;
F_17 ( & V_42 -> V_38 , F_21 ) ;
F_18 ( V_42 -> V_36 , & V_42 -> V_38 ) ;
}
static void F_33 ( struct V_60 * V_61 )
{
struct V_72 * V_73 ;
struct V_16 * V_17 ;
V_73 = (struct V_72 * ) V_61 ;
V_17 = F_34 ( V_73 -> V_55 ) ;
if ( V_17 == NULL )
return;
F_18 ( V_17 -> V_36 , & V_17 -> V_38 ) ;
}
static void F_35 (
struct V_60 * V_61 )
{
}
static void F_36 ( struct V_60 * V_61 )
{
struct V_74 * V_75 ;
struct V_76 * V_77 ;
struct V_60 * V_78 ;
struct V_79 * V_80 ;
unsigned long V_46 ;
V_75 = (struct V_74 * ) V_61 ;
F_22 ( & V_39 . V_81 , V_46 ) ;
F_23 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_78 =
(struct V_60 * ) V_77 -> V_82 ;
if ( V_78 -> V_83 == V_84 ) {
V_80 =
(struct V_79 * ) V_77 -> V_82 ;
if ( V_80 -> V_55 == V_75 -> V_55 &&
V_80 -> V_85 == V_75 -> V_85 ) {
memcpy ( & V_77 -> V_86 . V_87 ,
V_75 ,
sizeof(
struct V_74 ) ) ;
F_37 ( & V_77 -> V_88 ) ;
break;
}
}
}
F_25 ( & V_39 . V_81 , V_46 ) ;
}
static void F_38 ( struct V_60 * V_61 )
{
struct V_89 * V_90 ;
struct V_76 * V_77 ;
struct V_60 * V_78 ;
struct V_91 * V_92 ;
unsigned long V_46 ;
V_90 = (struct V_89 * ) V_61 ;
F_22 ( & V_39 . V_81 , V_46 ) ;
F_23 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_78 =
(struct V_60 * ) V_77 -> V_82 ;
if ( V_78 -> V_83 == V_93 ) {
V_92 =
(struct V_91 * ) V_78 ;
if ( ( V_90 -> V_55 ==
V_92 -> V_55 ) &&
( V_90 -> V_94 == V_92 -> V_94 ) ) {
memcpy ( & V_77 -> V_86 . V_95 ,
V_90 ,
sizeof(
struct V_89 ) ) ;
F_37 ( & V_77 -> V_88 ) ;
break;
}
}
}
F_25 ( & V_39 . V_81 , V_46 ) ;
}
static void F_39 (
struct V_60 * V_61 )
{
struct V_96 * V_97 ;
struct V_76 * V_77 ;
struct V_60 * V_78 ;
struct V_98 * V_99 ;
unsigned long V_46 ;
V_97 = (struct V_96 * ) V_61 ;
F_22 ( & V_39 . V_81 , V_46 ) ;
F_23 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_78 =
(struct V_60 * ) V_77 -> V_82 ;
if ( V_78 -> V_83 == V_100 ) {
V_99 =
(struct V_98 * ) V_78 ;
if ( V_97 -> V_94 == V_99 -> V_94 ) {
memcpy ( & V_77 -> V_86 . V_97 ,
V_97 ,
sizeof(
struct V_96 ) ) ;
F_37 ( & V_77 -> V_88 ) ;
break;
}
}
}
F_25 ( & V_39 . V_81 , V_46 ) ;
}
static void F_40 (
struct V_60 * V_61 )
{
struct V_76 * V_77 ;
struct V_60 * V_78 ;
struct V_101 * V_102 ;
struct V_103 * V_104 ;
unsigned long V_46 ;
V_104 = (struct V_103 * ) V_61 ;
F_22 ( & V_39 . V_81 , V_46 ) ;
F_23 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_78 =
(struct V_60 * ) V_77 -> V_82 ;
if ( V_78 -> V_83 ==
V_105 ) {
V_102 =
(struct V_101 * ) V_78 ;
memcpy ( & V_77 -> V_86 . V_104 ,
V_104 ,
sizeof( struct V_103 ) ) ;
F_37 ( & V_77 -> V_88 ) ;
}
}
F_25 ( & V_39 . V_81 , V_46 ) ;
}
void F_41 ( void * V_15 )
{
struct V_106 * V_82 = V_15 ;
struct V_60 * V_61 ;
int V_107 ;
V_61 = (struct V_60 * ) V_82 -> V_108 . V_109 ;
V_107 = V_82 -> V_110 . V_111 ;
if ( V_61 -> V_83 >= V_112 ) {
F_28 ( L_5 ,
V_61 -> V_83 , V_107 ) ;
F_42 ( L_6 , V_113 ,
( unsigned char * ) V_82 -> V_108 . V_109 , V_107 ) ;
return;
}
if ( V_114 [ V_61 -> V_83 ] . V_115 )
V_114 [ V_61 -> V_83 ] . V_115 ( V_61 ) ;
else
F_28 ( L_7 , V_61 -> V_83 ) ;
}
int F_43 ( void )
{
struct V_60 * V_82 ;
struct V_76 * V_77 ;
int V_44 , V_116 ;
V_77 = F_3 ( sizeof( * V_77 ) +
sizeof( struct V_60 ) ,
V_117 ) ;
if ( ! V_77 )
return - V_118 ;
F_44 ( & V_77 -> V_88 ) ;
V_82 = (struct V_60 * ) V_77 -> V_82 ;
V_82 -> V_83 = V_119 ;
V_44 = F_45 ( V_82 ,
sizeof( struct V_60 ) ) ;
if ( V_44 != 0 ) {
F_28 ( L_8 , V_44 ) ;
goto V_120;
}
V_116 = F_46 ( & V_77 -> V_88 , V_121 ) ;
if ( V_116 == 0 ) {
V_44 = - V_122 ;
goto V_120;
}
V_120:
F_6 ( V_77 ) ;
return V_44 ;
}
