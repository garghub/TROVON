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
V_17 -> V_32 = F_10 ( L_1 ) ;
if ( ! V_17 -> V_32 ) {
F_6 ( V_17 ) ;
return NULL ;
}
return V_17 ;
}
static void F_11 ( struct V_33 * V_34 )
{
struct V_16 * V_17 = F_12 ( V_34 ,
struct V_16 ,
V_34 ) ;
F_13 ( V_17 -> V_32 ) ;
F_6 ( V_17 ) ;
}
void F_14 ( struct V_16 * V_17 )
{
F_15 ( & V_17 -> V_34 , F_11 ) ;
F_16 ( V_35 . V_36 , & V_17 -> V_34 ) ;
}
static void F_17 ( struct V_33 * V_34 )
{
struct V_16 * V_17 = F_12 ( V_34 ,
struct V_16 ,
V_34 ) ;
F_18 ( V_17 -> V_37 ) ;
}
static void F_19 ( struct V_33 * V_34 )
{
struct V_16 * V_38 = F_12 ( V_34 ,
struct V_16 ,
V_34 ) ;
struct V_16 * V_17 ;
bool V_39 = true ;
int V_40 ;
int V_41 ;
unsigned long V_42 ;
F_15 ( & V_38 -> V_34 , F_17 ) ;
F_20 ( & V_35 . V_43 , V_42 ) ;
F_21 (channel, &vmbus_connection.chn_list, listentry) {
if ( ! memcmp ( & V_17 -> V_44 . V_45 . V_46 ,
& V_38 -> V_44 . V_45 . V_46 ,
sizeof( struct V_47 ) ) &&
! memcmp ( & V_17 -> V_44 . V_45 . V_48 ,
& V_38 -> V_44 . V_45 . V_48 ,
sizeof( struct V_47 ) ) ) {
V_39 = false ;
break;
}
}
if ( V_39 )
F_22 ( & V_38 -> V_49 ,
& V_35 . V_50 ) ;
F_23 ( & V_35 . V_43 , V_42 ) ;
if ( ! V_39 ) {
F_14 ( V_38 ) ;
return;
}
V_38 -> V_37 = F_24 (
& V_38 -> V_44 . V_45 . V_46 ,
& V_38 -> V_44 . V_45 . V_48 ,
V_38 ) ;
V_40 = F_25 ( V_38 -> V_37 ) ;
if ( V_40 != 0 ) {
F_26 ( L_2 ,
V_38 -> V_44 . V_51 ) ;
F_20 ( & V_35 . V_43 , V_42 ) ;
F_27 ( & V_38 -> V_49 ) ;
F_23 ( & V_35 . V_43 , V_42 ) ;
F_14 ( V_38 ) ;
} else {
V_38 -> V_52 = V_53 ;
V_38 -> V_21 = - 1 ;
for ( V_41 = 0 ; V_41 < V_54 ; V_41 ++ ) {
if ( memcmp ( & V_38 -> V_44 . V_45 . V_46 ,
& V_22 [ V_41 ] . V_55 ,
sizeof( struct V_47 ) ) == 0 &&
F_28 ( V_38 , 2 * V_25 ,
2 * V_25 , NULL , 0 ,
F_2 ,
V_38 ) == 0 ) {
V_22 [ V_41 ] . V_17 = V_38 ;
V_38 -> V_21 = V_41 ;
F_29 ( L_3 , V_22 [ V_41 ] . V_56 ) ;
}
}
}
}
static void F_30 ( struct V_57 * V_58 )
{
struct V_59 * V_45 ;
struct V_16 * V_38 ;
struct V_47 * V_60 ;
struct V_47 * V_61 ;
int V_62 ;
int V_63 = 0 ;
V_45 = (struct V_59 * ) V_58 ;
for ( V_62 = 0 ; V_62 < V_64 ; V_62 ++ ) {
if ( memcmp ( & V_45 -> V_45 . V_46 ,
& V_65 [ V_62 ] ,
sizeof( struct V_47 ) ) == 0 ) {
V_63 = 1 ;
break;
}
}
if ( ! V_63 )
return;
V_60 = & V_45 -> V_45 . V_46 ;
V_61 = & V_45 -> V_45 . V_48 ;
V_38 = F_7 () ;
if ( ! V_38 ) {
F_26 ( L_4 ) ;
return;
}
memcpy ( & V_38 -> V_44 , V_45 ,
sizeof( struct V_59 ) ) ;
V_38 -> V_66 = ( T_1 ) V_45 -> V_67 / 32 ;
V_38 -> V_68 = ( T_1 ) V_45 -> V_67 % 32 ;
F_15 ( & V_38 -> V_34 , F_19 ) ;
F_16 ( V_38 -> V_32 , & V_38 -> V_34 ) ;
}
static void F_31 ( struct V_57 * V_58 )
{
struct V_69 * V_70 ;
struct V_16 * V_17 ;
V_70 = (struct V_69 * ) V_58 ;
V_17 = F_32 ( V_70 -> V_51 ) ;
if ( V_17 == NULL )
return;
F_16 ( V_17 -> V_32 , & V_17 -> V_34 ) ;
}
static void F_33 (
struct V_57 * V_58 )
{
}
static void F_34 ( struct V_57 * V_58 )
{
struct V_71 * V_72 ;
struct V_73 * V_74 ;
struct V_57 * V_75 ;
struct V_76 * V_77 ;
unsigned long V_42 ;
V_72 = (struct V_71 * ) V_58 ;
F_20 ( & V_35 . V_78 , V_42 ) ;
F_21 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_75 =
(struct V_57 * ) V_74 -> V_79 ;
if ( V_75 -> V_80 == V_81 ) {
V_77 =
(struct V_76 * ) V_74 -> V_79 ;
if ( V_77 -> V_51 == V_72 -> V_51 &&
V_77 -> V_82 == V_72 -> V_82 ) {
memcpy ( & V_74 -> V_83 . V_84 ,
V_72 ,
sizeof(
struct V_71 ) ) ;
F_35 ( & V_74 -> V_85 ) ;
break;
}
}
}
F_23 ( & V_35 . V_78 , V_42 ) ;
}
static void F_36 ( struct V_57 * V_58 )
{
struct V_86 * V_87 ;
struct V_73 * V_74 ;
struct V_57 * V_75 ;
struct V_88 * V_89 ;
unsigned long V_42 ;
V_87 = (struct V_86 * ) V_58 ;
F_20 ( & V_35 . V_78 , V_42 ) ;
F_21 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_75 =
(struct V_57 * ) V_74 -> V_79 ;
if ( V_75 -> V_80 == V_90 ) {
V_89 =
(struct V_88 * ) V_75 ;
if ( ( V_87 -> V_51 ==
V_89 -> V_51 ) &&
( V_87 -> V_91 == V_89 -> V_91 ) ) {
memcpy ( & V_74 -> V_83 . V_92 ,
V_87 ,
sizeof(
struct V_86 ) ) ;
F_35 ( & V_74 -> V_85 ) ;
break;
}
}
}
F_23 ( & V_35 . V_78 , V_42 ) ;
}
static void F_37 (
struct V_57 * V_58 )
{
struct V_93 * V_94 ;
struct V_73 * V_74 ;
struct V_57 * V_75 ;
struct V_95 * V_96 ;
unsigned long V_42 ;
V_94 = (struct V_93 * ) V_58 ;
F_20 ( & V_35 . V_78 , V_42 ) ;
F_21 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_75 =
(struct V_57 * ) V_74 -> V_79 ;
if ( V_75 -> V_80 == V_97 ) {
V_96 =
(struct V_95 * ) V_75 ;
if ( V_94 -> V_91 == V_96 -> V_91 ) {
memcpy ( & V_74 -> V_83 . V_94 ,
V_94 ,
sizeof(
struct V_93 ) ) ;
F_35 ( & V_74 -> V_85 ) ;
break;
}
}
}
F_23 ( & V_35 . V_78 , V_42 ) ;
}
static void F_38 (
struct V_57 * V_58 )
{
struct V_73 * V_74 ;
struct V_57 * V_75 ;
struct V_98 * V_99 ;
struct V_100 * V_101 ;
unsigned long V_42 ;
V_101 = (struct V_100 * ) V_58 ;
F_20 ( & V_35 . V_78 , V_42 ) ;
F_21 (msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
V_75 =
(struct V_57 * ) V_74 -> V_79 ;
if ( V_75 -> V_80 ==
V_102 ) {
V_99 =
(struct V_98 * ) V_75 ;
memcpy ( & V_74 -> V_83 . V_101 ,
V_101 ,
sizeof( struct V_100 ) ) ;
F_35 ( & V_74 -> V_85 ) ;
}
}
F_23 ( & V_35 . V_78 , V_42 ) ;
}
void F_39 ( void * V_15 )
{
struct V_103 * V_79 = V_15 ;
struct V_57 * V_58 ;
int V_104 ;
V_58 = (struct V_57 * ) V_79 -> V_105 . V_106 ;
V_104 = V_79 -> V_107 . V_108 ;
if ( V_58 -> V_80 >= V_109 ) {
F_26 ( L_5 ,
V_58 -> V_80 , V_104 ) ;
F_40 ( L_6 , V_110 ,
( unsigned char * ) V_79 -> V_105 . V_106 , V_104 ) ;
return;
}
if ( V_111 [ V_58 -> V_80 ] . V_112 )
V_111 [ V_58 -> V_80 ] . V_112 ( V_58 ) ;
else
F_26 ( L_7 , V_58 -> V_80 ) ;
}
int F_41 ( void )
{
struct V_57 * V_79 ;
struct V_73 * V_74 ;
int V_40 , V_113 ;
V_74 = F_3 ( sizeof( * V_74 ) +
sizeof( struct V_57 ) ,
V_114 ) ;
if ( ! V_74 )
return - V_115 ;
F_42 ( & V_74 -> V_85 ) ;
V_79 = (struct V_57 * ) V_74 -> V_79 ;
V_79 -> V_80 = V_116 ;
V_40 = F_43 ( V_79 ,
sizeof( struct V_57 ) ) ;
if ( V_40 != 0 ) {
F_26 ( L_8 , V_40 ) ;
goto V_117;
}
V_113 = F_44 ( & V_74 -> V_85 , 5 * V_118 ) ;
if ( V_113 == 0 ) {
V_40 = - V_119 ;
goto V_117;
}
V_117:
F_6 ( V_74 ) ;
return V_40 ;
}
