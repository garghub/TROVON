static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_2 (pos, &aliastree.serverlist, server) {
if ( ! strncmp ( V_4 -> V_3 . V_5 , V_3 -> V_5 ,
sizeof( V_3 -> V_5 ) )
&& ! strncmp ( V_4 -> V_3 . V_6 , V_3 -> V_6 ,
sizeof( V_3 -> V_6 ) ) )
return V_4 ;
}
return NULL ;
}
static struct V_7 * F_3 ( struct V_1 * V_8 ,
struct V_2 * V_3 )
{
struct V_7 * V_4 ;
F_2 (pos, &server->lculist, lcu) {
if ( V_4 -> V_3 . V_9 == V_3 -> V_9 )
return V_4 ;
}
return NULL ;
}
static struct V_10 * F_4 ( struct V_7 * V_11 ,
struct V_2 * V_3 )
{
struct V_10 * V_4 ;
T_1 V_12 ;
if ( V_11 -> V_13 == V_14 ) {
if ( F_5 ( & V_11 -> V_15 ) )
return NULL ;
else
return F_6 ( & V_11 -> V_15 ,
struct V_10 , V_16 ) ;
}
if ( V_3 -> type == V_17 )
V_12 = V_3 -> V_18 ;
else
V_12 = V_3 -> V_19 ;
F_2 (pos, &lcu->grouplist, group) {
if ( V_4 -> V_3 . V_19 == V_12 &&
! strncmp ( V_4 -> V_3 . V_20 , V_3 -> V_20 , sizeof( V_3 -> V_20 ) ) )
return V_4 ;
}
return NULL ;
}
static struct V_1 * F_7 ( struct V_2 * V_3 )
{
struct V_1 * V_8 ;
V_8 = F_8 ( sizeof( * V_8 ) , V_21 ) ;
if ( ! V_8 )
return F_9 ( - V_22 ) ;
memcpy ( V_8 -> V_3 . V_5 , V_3 -> V_5 , sizeof( V_3 -> V_5 ) ) ;
memcpy ( V_8 -> V_3 . V_6 , V_3 -> V_6 , sizeof( V_3 -> V_6 ) ) ;
F_10 ( & V_8 -> V_8 ) ;
F_10 ( & V_8 -> V_23 ) ;
return V_8 ;
}
static void F_11 ( struct V_1 * V_8 )
{
F_12 ( V_8 ) ;
}
static struct V_7 * F_13 ( struct V_2 * V_3 )
{
struct V_7 * V_11 ;
V_11 = F_8 ( sizeof( * V_11 ) , V_21 ) ;
if ( ! V_11 )
return F_9 ( - V_22 ) ;
V_11 -> V_24 = F_8 ( sizeof( * ( V_11 -> V_24 ) ) , V_21 | V_25 ) ;
if ( ! V_11 -> V_24 )
goto V_26;
V_11 -> V_27 = F_8 ( sizeof( * V_11 -> V_27 ) , V_21 | V_25 ) ;
if ( ! V_11 -> V_27 )
goto V_28;
V_11 -> V_27 -> V_29 = F_8 ( sizeof( struct V_30 ) ,
V_21 | V_25 ) ;
if ( ! V_11 -> V_27 -> V_29 )
goto V_31;
V_11 -> V_27 -> V_32 = F_8 ( 16 , V_21 | V_25 ) ;
if ( ! V_11 -> V_27 -> V_32 )
goto V_33;
memcpy ( V_11 -> V_3 . V_5 , V_3 -> V_5 , sizeof( V_3 -> V_5 ) ) ;
memcpy ( V_11 -> V_3 . V_6 , V_3 -> V_6 , sizeof( V_3 -> V_6 ) ) ;
V_11 -> V_3 . V_9 = V_3 -> V_9 ;
V_11 -> V_13 = V_34 ;
V_11 -> V_35 = V_36 | V_37 ;
F_10 ( & V_11 -> V_11 ) ;
F_10 ( & V_11 -> V_38 ) ;
F_10 ( & V_11 -> V_39 ) ;
F_10 ( & V_11 -> V_15 ) ;
F_14 ( & V_11 -> V_40 . V_41 , V_42 ) ;
F_15 ( & V_11 -> V_43 . V_44 , V_45 ) ;
F_16 ( & V_11 -> V_46 ) ;
F_17 ( & V_11 -> V_47 ) ;
return V_11 ;
V_33:
F_12 ( V_11 -> V_27 -> V_29 ) ;
V_31:
F_12 ( V_11 -> V_27 ) ;
V_28:
F_12 ( V_11 -> V_24 ) ;
V_26:
F_12 ( V_11 ) ;
return F_9 ( - V_22 ) ;
}
static void F_18 ( struct V_7 * V_11 )
{
F_12 ( V_11 -> V_27 -> V_32 ) ;
F_12 ( V_11 -> V_27 -> V_29 ) ;
F_12 ( V_11 -> V_27 ) ;
F_12 ( V_11 -> V_24 ) ;
F_12 ( V_11 ) ;
}
int F_19 ( struct V_48 * V_49 )
{
struct V_50 * V_51 ;
unsigned long V_35 ;
struct V_1 * V_8 , * V_52 ;
struct V_7 * V_11 , * V_53 ;
struct V_2 V_3 ;
V_51 = (struct V_50 * ) V_49 -> V_51 ;
V_49 -> V_54 -> V_55 ( V_49 , & V_3 ) ;
F_20 ( & V_56 . V_46 , V_35 ) ;
V_8 = F_1 ( & V_3 ) ;
if ( ! V_8 ) {
F_21 ( & V_56 . V_46 , V_35 ) ;
V_52 = F_7 ( & V_3 ) ;
if ( F_22 ( V_52 ) )
return F_23 ( V_52 ) ;
F_20 ( & V_56 . V_46 , V_35 ) ;
V_8 = F_1 ( & V_3 ) ;
if ( ! V_8 ) {
F_24 ( & V_52 -> V_8 , & V_56 . V_57 ) ;
V_8 = V_52 ;
} else {
F_11 ( V_52 ) ;
}
}
V_11 = F_3 ( V_8 , & V_3 ) ;
if ( ! V_11 ) {
F_21 ( & V_56 . V_46 , V_35 ) ;
V_53 = F_13 ( & V_3 ) ;
if ( F_22 ( V_53 ) )
return F_23 ( V_53 ) ;
F_20 ( & V_56 . V_46 , V_35 ) ;
V_11 = F_3 ( V_8 , & V_3 ) ;
if ( ! V_11 ) {
F_24 ( & V_53 -> V_11 , & V_8 -> V_23 ) ;
V_11 = V_53 ;
} else {
F_18 ( V_53 ) ;
}
}
F_25 ( & V_11 -> V_46 ) ;
F_24 ( & V_49 -> V_58 , & V_11 -> V_38 ) ;
V_51 -> V_11 = V_11 ;
F_26 ( & V_11 -> V_46 ) ;
F_21 ( & V_56 . V_46 , V_35 ) ;
return 0 ;
}
void F_27 ( struct V_48 * V_49 )
{
struct V_50 * V_51 ;
unsigned long V_35 ;
struct V_7 * V_11 ;
struct V_1 * V_8 ;
int V_59 ;
struct V_2 V_3 ;
V_51 = (struct V_50 * ) V_49 -> V_51 ;
V_11 = V_51 -> V_11 ;
if ( ! V_11 )
return;
V_49 -> V_54 -> V_55 ( V_49 , & V_3 ) ;
F_20 ( & V_11 -> V_46 , V_35 ) ;
F_28 ( & V_49 -> V_58 ) ;
if ( V_49 == V_11 -> V_40 . V_49 ) {
F_21 ( & V_11 -> V_46 , V_35 ) ;
F_29 ( & V_11 -> V_40 . V_41 ) ;
F_20 ( & V_11 -> V_46 , V_35 ) ;
if ( V_49 == V_11 -> V_40 . V_49 )
V_11 -> V_40 . V_49 = NULL ;
}
V_59 = 0 ;
if ( V_49 == V_11 -> V_43 . V_49 ) {
F_21 ( & V_11 -> V_46 , V_35 ) ;
V_59 = 1 ;
F_30 ( & V_11 -> V_43 . V_44 ) ;
F_20 ( & V_11 -> V_46 , V_35 ) ;
if ( V_49 == V_11 -> V_43 . V_49 )
V_11 -> V_43 . V_49 = NULL ;
}
V_51 -> V_11 = NULL ;
F_21 ( & V_11 -> V_46 , V_35 ) ;
F_20 ( & V_56 . V_46 , V_35 ) ;
F_25 ( & V_11 -> V_46 ) ;
if ( F_5 ( & V_11 -> V_15 ) &&
F_5 ( & V_11 -> V_39 ) &&
F_5 ( & V_11 -> V_38 ) ) {
F_31 ( & V_11 -> V_11 ) ;
F_26 ( & V_11 -> V_46 ) ;
F_18 ( V_11 ) ;
V_11 = NULL ;
} else {
if ( V_59 )
F_32 ( V_11 , NULL ) ;
F_26 ( & V_11 -> V_46 ) ;
}
V_8 = F_1 ( & V_3 ) ;
if ( V_8 && F_5 ( & V_8 -> V_23 ) ) {
F_31 ( & V_8 -> V_8 ) ;
F_11 ( V_8 ) ;
}
F_21 ( & V_56 . V_46 , V_35 ) ;
}
static int F_33 ( struct V_7 * V_11 ,
struct V_48 * V_49 ,
struct V_48 * V_4 )
{
struct V_50 * V_51 ;
struct V_10 * V_16 ;
struct V_2 V_3 ;
unsigned long V_35 ;
V_51 = (struct V_50 * ) V_49 -> V_51 ;
if ( V_49 != V_4 )
F_34 ( F_35 ( V_49 -> V_60 ) , V_35 ,
V_61 ) ;
V_51 -> V_3 . type = V_11 -> V_24 -> V_62 [ V_51 -> V_3 . V_18 ] . V_63 ;
V_51 -> V_3 . V_19 =
V_11 -> V_24 -> V_62 [ V_51 -> V_3 . V_18 ] . V_64 ;
V_3 = V_51 -> V_3 ;
if ( V_49 != V_4 )
F_21 ( F_35 ( V_49 -> V_60 ) , V_35 ) ;
if ( V_11 -> V_13 == V_34 ) {
F_36 ( & V_49 -> V_58 , & V_11 -> V_39 ) ;
return 0 ;
}
V_16 = F_4 ( V_11 , & V_3 ) ;
if ( ! V_16 ) {
V_16 = F_8 ( sizeof( * V_16 ) , V_65 ) ;
if ( ! V_16 )
return - V_22 ;
memcpy ( V_16 -> V_3 . V_5 , V_3 . V_5 , sizeof( V_3 . V_5 ) ) ;
memcpy ( V_16 -> V_3 . V_6 , V_3 . V_6 , sizeof( V_3 . V_6 ) ) ;
V_16 -> V_3 . V_9 = V_3 . V_9 ;
if ( V_3 . type == V_17 )
V_16 -> V_3 . V_19 = V_3 . V_18 ;
else
V_16 -> V_3 . V_19 = V_3 . V_19 ;
memcpy ( V_16 -> V_3 . V_20 , V_3 . V_20 , sizeof( V_3 . V_20 ) ) ;
F_10 ( & V_16 -> V_16 ) ;
F_10 ( & V_16 -> V_66 ) ;
F_10 ( & V_16 -> V_67 ) ;
F_24 ( & V_16 -> V_16 , & V_11 -> V_15 ) ;
}
if ( V_3 . type == V_17 )
F_36 ( & V_49 -> V_58 , & V_16 -> V_66 ) ;
else
F_36 ( & V_49 -> V_58 , & V_16 -> V_67 ) ;
V_51 -> V_68 = V_16 ;
return 0 ;
}
static void F_37 ( struct V_7 * V_11 ,
struct V_48 * V_49 )
{
struct V_50 * V_51 ;
struct V_10 * V_16 ;
V_51 = (struct V_50 * ) V_49 -> V_51 ;
F_36 ( & V_49 -> V_58 , & V_11 -> V_38 ) ;
V_16 = V_51 -> V_68 ;
if ( ! V_16 )
return;
V_51 -> V_68 = NULL ;
if ( F_5 ( & V_16 -> V_66 ) && F_5 ( & V_16 -> V_67 ) ) {
F_31 ( & V_16 -> V_16 ) ;
F_12 ( V_16 ) ;
return;
}
if ( V_16 -> V_69 == V_49 )
V_16 -> V_69 = NULL ;
}
static int
F_38 ( struct V_70 * V_71 )
{
char * V_72 ;
char V_73 ;
char V_74 ;
char V_75 ;
V_72 = F_39 ( & V_71 -> V_76 ) ;
if ( ! V_72 )
return 0 ;
V_73 = V_72 [ 0 ] ;
V_74 = ( V_72 [ 7 ] & 0xF0 ) ;
V_75 = ( V_72 [ 7 ] & 0x0F ) ;
if ( ( V_73 == 0x80 ) && ( V_74 == 0x00 ) && ( V_75 == 0x04 ) )
return 1 ;
return 0 ;
}
static int F_40 ( struct V_48 * V_49 ,
struct V_7 * V_11 )
{
struct V_77 * V_78 ;
struct V_70 * V_71 ;
struct V_30 * V_79 ;
int V_80 ;
unsigned long V_35 ;
V_71 = F_41 ( V_81 , 1 + 1 ,
( sizeof( struct V_77 ) ) ,
V_49 ) ;
if ( F_22 ( V_71 ) )
return F_23 ( V_71 ) ;
V_71 -> V_82 = V_49 ;
V_71 -> V_83 = V_49 ;
F_42 ( V_84 , & V_71 -> V_35 ) ;
V_71 -> V_85 = 10 ;
V_71 -> V_86 = 20 * V_87 ;
V_78 = (struct V_77 * ) V_71 -> V_32 ;
memset ( V_78 , 0 , sizeof( struct V_77 ) ) ;
V_78 -> V_88 = V_89 ;
V_78 -> V_90 = 0x0e ;
V_79 = V_71 -> V_29 ;
V_79 -> V_91 = V_92 ;
V_79 -> V_93 = sizeof( struct V_77 ) ;
V_79 -> V_35 |= V_94 ;
V_79 -> V_95 = ( V_96 ) ( V_97 ) V_78 ;
memset ( V_11 -> V_24 , 0 , sizeof( * ( V_11 -> V_24 ) ) ) ;
V_79 ++ ;
V_79 -> V_91 = V_98 ;
V_79 -> V_93 = sizeof( * ( V_11 -> V_24 ) ) ;
V_79 -> V_95 = ( V_96 ) ( V_97 ) V_11 -> V_24 ;
V_71 -> V_99 = F_43 () ;
V_71 -> V_100 = V_101 ;
F_20 ( & V_11 -> V_46 , V_35 ) ;
V_11 -> V_35 &= ~ V_36 ;
F_21 ( & V_11 -> V_46 , V_35 ) ;
do {
V_80 = F_44 ( V_71 ) ;
if ( V_80 && F_38 ( V_71 ) )
return - V_102 ;
} while ( V_80 && ( V_71 -> V_85 > 0 ) );
if ( V_80 ) {
F_20 ( & V_11 -> V_46 , V_35 ) ;
V_11 -> V_35 |= V_36 ;
F_21 ( & V_11 -> V_46 , V_35 ) ;
}
F_45 ( V_71 , V_71 -> V_83 ) ;
return V_80 ;
}
static int F_46 ( struct V_48 * V_103 , struct V_7 * V_11 )
{
unsigned long V_35 ;
struct V_10 * V_68 , * V_104 ;
struct V_48 * V_49 , * V_105 ;
int V_106 , V_80 ;
struct V_50 * V_51 ;
F_20 ( & V_11 -> V_46 , V_35 ) ;
F_47 (pavgroup, tempgroup, &lcu->grouplist, group) {
F_47 (device, tempdev, &pavgroup->baselist,
alias_list) {
F_36 ( & V_49 -> V_58 , & V_11 -> V_39 ) ;
V_51 = (struct V_50 * ) V_49 -> V_51 ;
V_51 -> V_68 = NULL ;
}
F_47 (device, tempdev, &pavgroup->aliaslist,
alias_list) {
F_36 ( & V_49 -> V_58 , & V_11 -> V_39 ) ;
V_51 = (struct V_50 * ) V_49 -> V_51 ;
V_51 -> V_68 = NULL ;
}
F_31 ( & V_68 -> V_16 ) ;
F_12 ( V_68 ) ;
}
F_21 ( & V_11 -> V_46 , V_35 ) ;
V_80 = F_40 ( V_103 , V_11 ) ;
if ( V_80 )
return V_80 ;
F_34 ( F_35 ( V_103 -> V_60 ) , V_35 ,
V_107 ) ;
F_25 ( & V_11 -> V_46 ) ;
V_11 -> V_13 = V_34 ;
for ( V_106 = 0 ; V_106 < V_108 ; ++ V_106 ) {
switch ( V_11 -> V_24 -> V_62 [ V_106 ] . V_63 ) {
case V_109 :
V_11 -> V_13 = V_110 ;
break;
case V_111 :
V_11 -> V_13 = V_14 ;
break;
}
if ( V_11 -> V_13 != V_34 )
break;
}
F_47 (device, tempdev, &lcu->active_devices,
alias_list) {
F_33 ( V_11 , V_49 , V_103 ) ;
}
F_26 ( & V_11 -> V_46 ) ;
F_21 ( F_35 ( V_103 -> V_60 ) , V_35 ) ;
return 0 ;
}
static void V_45 ( struct V_112 * V_113 )
{
struct V_7 * V_11 ;
struct V_114 * V_43 ;
struct V_48 * V_49 ;
unsigned long V_35 ;
int V_80 ;
V_43 = F_48 ( V_113 , struct V_114 , V_44 . V_113 ) ;
V_11 = F_48 ( V_43 , struct V_7 , V_43 ) ;
V_49 = V_43 -> V_49 ;
V_80 = F_46 ( V_49 , V_11 ) ;
F_20 ( & V_11 -> V_46 , V_35 ) ;
if ( ( V_80 && ( V_80 != - V_102 ) ) || ( V_11 -> V_35 & V_36 ) ) {
F_49 ( V_115 , V_49 , L_1
L_2 , V_80 ) ;
F_50 ( & V_11 -> V_43 . V_44 , 30 * V_87 ) ;
} else {
V_11 -> V_43 . V_49 = NULL ;
V_11 -> V_35 &= ~ V_37 ;
}
F_21 ( & V_11 -> V_46 , V_35 ) ;
}
static int F_32 ( struct V_7 * V_11 ,
struct V_48 * V_49 )
{
struct V_48 * V_116 = NULL ;
struct V_10 * V_16 ;
V_11 -> V_35 |= V_36 ;
if ( V_11 -> V_43 . V_49 ) {
return 0 ;
}
if ( V_49 && ! F_5 ( & V_49 -> V_58 ) )
V_116 = V_49 ;
if ( ! V_116 && ! F_5 ( & V_11 -> V_15 ) ) {
V_16 = F_6 ( & V_11 -> V_15 ,
struct V_10 , V_16 ) ;
if ( ! F_5 ( & V_16 -> V_66 ) )
V_116 = F_6 ( & V_16 -> V_66 ,
struct V_48 ,
V_58 ) ;
else if ( ! F_5 ( & V_16 -> V_67 ) )
V_116 = F_6 ( & V_16 -> V_67 ,
struct V_48 ,
V_58 ) ;
}
if ( ! V_116 && ! F_5 ( & V_11 -> V_39 ) ) {
V_116 = F_6 ( & V_11 -> V_39 ,
struct V_48 , V_58 ) ;
}
if ( ! V_116 )
return - V_117 ;
V_11 -> V_43 . V_49 = V_116 ;
F_50 ( & V_11 -> V_43 . V_44 , 0 ) ;
return 0 ;
}
int F_51 ( struct V_48 * V_49 )
{
struct V_50 * V_51 ;
struct V_7 * V_11 ;
unsigned long V_35 ;
int V_80 ;
V_51 = (struct V_50 * ) V_49 -> V_51 ;
V_11 = V_51 -> V_11 ;
V_80 = 0 ;
F_20 ( F_35 ( V_49 -> V_60 ) , V_35 ) ;
F_25 ( & V_11 -> V_46 ) ;
if ( ! ( V_11 -> V_35 & V_37 ) ) {
V_80 = F_33 ( V_11 , V_49 , V_49 ) ;
if ( V_80 )
V_11 -> V_35 |= V_37 ;
}
if ( V_11 -> V_35 & V_37 ) {
F_36 ( & V_49 -> V_58 , & V_11 -> V_39 ) ;
F_32 ( V_11 , V_49 ) ;
}
F_26 ( & V_11 -> V_46 ) ;
F_21 ( F_35 ( V_49 -> V_60 ) , V_35 ) ;
return V_80 ;
}
int F_52 ( struct V_48 * V_49 )
{
struct V_50 * V_51 ;
V_51 = (struct V_50 * ) V_49 -> V_51 ;
V_51 -> V_11 -> V_35 |= V_37 ;
return F_51 ( V_49 ) ;
}
int F_53 ( struct V_48 * V_49 )
{
struct V_50 * V_51 ;
struct V_7 * V_11 ;
unsigned long V_35 ;
V_51 = (struct V_50 * ) V_49 -> V_51 ;
V_11 = V_51 -> V_11 ;
if ( ! V_11 )
return 0 ;
F_20 ( & V_11 -> V_46 , V_35 ) ;
F_37 ( V_11 , V_49 ) ;
F_21 ( & V_11 -> V_46 , V_35 ) ;
return 0 ;
}
struct V_48 * F_54 ( struct V_48 * V_118 )
{
struct V_48 * V_119 ;
struct V_10 * V_16 ;
struct V_7 * V_11 ;
struct V_50 * V_51 , * V_120 ;
unsigned long V_35 ;
V_51 = (struct V_50 * ) V_118 -> V_51 ;
V_16 = V_51 -> V_68 ;
V_11 = V_51 -> V_11 ;
if ( ! V_16 || ! V_11 )
return NULL ;
if ( V_11 -> V_13 == V_34 ||
V_11 -> V_35 & ( V_36 | V_37 ) )
return NULL ;
if ( F_55 ( ! ( V_51 -> V_121 . V_122 [ 8 ] & 0x01 ) ) ) {
F_49 ( V_123 , V_118 , L_3 ,
L_4 ) ;
return NULL ;
}
F_20 ( & V_11 -> V_46 , V_35 ) ;
V_119 = V_16 -> V_69 ;
if ( ! V_119 ) {
if ( F_5 ( & V_16 -> V_67 ) ) {
F_21 ( & V_11 -> V_46 , V_35 ) ;
return NULL ;
} else {
V_119 = F_6 ( & V_16 -> V_67 ,
struct V_48 ,
V_58 ) ;
}
}
if ( F_56 ( & V_119 -> V_58 , & V_16 -> V_67 ) )
V_16 -> V_69 = F_6 ( & V_16 -> V_67 ,
struct V_48 , V_58 ) ;
else
V_16 -> V_69 = F_6 ( & V_119 -> V_58 ,
struct V_48 , V_58 ) ;
F_21 ( & V_11 -> V_46 , V_35 ) ;
V_120 = (struct V_50 * ) V_119 -> V_51 ;
if ( ( V_120 -> V_93 < V_51 -> V_93 ) && ! V_119 -> V_124 &&
! F_57 ( V_125 , & V_119 -> V_35 ) )
return V_119 ;
else
return NULL ;
}
static int F_58 ( struct V_7 * V_11 ,
struct V_48 * V_49 ,
char V_73 )
{
struct V_70 * V_71 ;
int V_80 = 0 ;
struct V_30 * V_79 ;
V_71 = V_11 -> V_27 ;
strncpy ( ( char * ) & V_71 -> V_126 , L_5 , 4 ) ;
F_59 ( ( char * ) & V_71 -> V_126 , 4 ) ;
V_79 = V_71 -> V_29 ;
V_79 -> V_91 = V_127 ;
V_79 -> V_35 = 0 ;
V_79 -> V_93 = 16 ;
V_79 -> V_95 = ( V_96 ) ( V_97 ) V_71 -> V_32 ;
( ( char * ) V_71 -> V_32 ) [ 0 ] = V_73 ;
F_42 ( V_84 , & V_71 -> V_35 ) ;
V_71 -> V_85 = 255 ;
V_71 -> V_82 = V_49 ;
V_71 -> V_83 = V_49 ;
V_71 -> V_128 = NULL ;
V_71 -> V_86 = 5 * V_87 ;
V_71 -> V_99 = F_43 () ;
V_71 -> V_100 = V_101 ;
V_80 = F_60 ( V_71 ) ;
return V_80 ;
}
static void F_61 ( struct V_7 * V_11 )
{
struct V_10 * V_68 ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
unsigned long V_35 ;
F_2 (device, &lcu->active_devices, alias_list) {
V_51 = (struct V_50 * ) V_49 -> V_51 ;
F_20 ( F_35 ( V_49 -> V_60 ) , V_35 ) ;
if ( V_51 -> V_3 . type != V_17 ) {
F_21 ( F_35 ( V_49 -> V_60 ) ,
V_35 ) ;
continue;
}
F_21 ( F_35 ( V_49 -> V_60 ) , V_35 ) ;
F_62 ( V_49 -> V_128 ) ;
F_63 ( V_49 ) ;
}
F_2 (device, &lcu->inactive_devices, alias_list) {
V_51 = (struct V_50 * ) V_49 -> V_51 ;
F_20 ( F_35 ( V_49 -> V_60 ) , V_35 ) ;
if ( V_51 -> V_3 . type != V_17 ) {
F_21 ( F_35 ( V_49 -> V_60 ) ,
V_35 ) ;
continue;
}
F_21 ( F_35 ( V_49 -> V_60 ) , V_35 ) ;
F_62 ( V_49 -> V_128 ) ;
F_63 ( V_49 ) ;
}
F_2 (pavgroup, &lcu->grouplist, group) {
F_2 (device, &pavgroup->baselist, alias_list) {
F_62 ( V_49 -> V_128 ) ;
F_63 ( V_49 ) ;
}
}
}
static void F_64 ( struct V_7 * V_11 )
{
struct V_10 * V_68 ;
struct V_48 * V_49 , * V_129 ;
struct V_50 * V_51 ;
int V_80 ;
unsigned long V_35 ;
F_65 ( V_130 ) ;
F_20 ( & V_11 -> V_46 , V_35 ) ;
F_47 (device, temp, &lcu->active_devices,
alias_list) {
V_51 = (struct V_50 * ) V_49 -> V_51 ;
if ( V_51 -> V_3 . type == V_17 )
continue;
F_36 ( & V_49 -> V_58 , & V_130 ) ;
}
F_2 (pavgroup, &lcu->grouplist, group) {
F_66 ( & V_68 -> V_67 , & V_130 ) ;
}
while ( ! F_5 ( & V_130 ) ) {
V_49 = F_6 ( & V_130 , struct V_48 ,
V_58 ) ;
F_21 ( & V_11 -> V_46 , V_35 ) ;
V_80 = F_67 ( V_49 ) ;
F_20 ( & V_11 -> V_46 , V_35 ) ;
if ( V_49 == F_6 ( & V_130 ,
struct V_48 , V_58 ) ) {
F_36 ( & V_49 -> V_58 , & V_11 -> V_39 ) ;
V_51 = (struct V_50 * ) V_49 -> V_51 ;
V_51 -> V_68 = NULL ;
}
}
F_21 ( & V_11 -> V_46 , V_35 ) ;
}
static void F_68 ( struct V_48 * V_49 ,
struct V_48 * V_4 )
{
if ( V_4 == V_49 ) {
F_69 ( V_4 , V_131 ) ;
return;
}
F_25 ( F_35 ( V_4 -> V_60 ) ) ;
F_69 ( V_4 , V_131 ) ;
F_26 ( F_35 ( V_4 -> V_60 ) ) ;
}
static void F_70 ( struct V_7 * V_11 ,
struct V_48 * V_49 )
{
struct V_10 * V_68 ;
struct V_48 * V_4 ;
F_2 (pos, &lcu->active_devices, alias_list)
F_68 ( V_49 , V_4 ) ;
F_2 (pos, &lcu->inactive_devices, alias_list)
F_68 ( V_49 , V_4 ) ;
F_2 (pavgroup, &lcu->grouplist, group) {
F_2 (pos, &pavgroup->baselist, alias_list)
F_68 ( V_49 , V_4 ) ;
F_2 (pos, &pavgroup->aliaslist, alias_list)
F_68 ( V_49 , V_4 ) ;
}
}
static void F_71 ( struct V_7 * V_11 )
{
struct V_10 * V_68 ;
struct V_48 * V_49 ;
unsigned long V_35 ;
F_2 (device, &lcu->active_devices, alias_list) {
F_20 ( F_35 ( V_49 -> V_60 ) , V_35 ) ;
F_72 ( V_49 , V_131 ) ;
F_21 ( F_35 ( V_49 -> V_60 ) , V_35 ) ;
}
F_2 (device, &lcu->inactive_devices, alias_list) {
F_20 ( F_35 ( V_49 -> V_60 ) , V_35 ) ;
F_72 ( V_49 , V_131 ) ;
F_21 ( F_35 ( V_49 -> V_60 ) , V_35 ) ;
}
F_2 (pavgroup, &lcu->grouplist, group) {
F_2 (device, &pavgroup->baselist, alias_list) {
F_20 ( F_35 ( V_49 -> V_60 ) , V_35 ) ;
F_72 ( V_49 , V_131 ) ;
F_21 ( F_35 ( V_49 -> V_60 ) ,
V_35 ) ;
}
F_2 (device, &pavgroup->aliaslist, alias_list) {
F_20 ( F_35 ( V_49 -> V_60 ) , V_35 ) ;
F_72 ( V_49 , V_131 ) ;
F_21 ( F_35 ( V_49 -> V_60 ) ,
V_35 ) ;
}
}
}
static void V_42 ( struct V_112 * V_113 )
{
struct V_7 * V_11 ;
struct V_132 * V_40 ;
unsigned long V_35 ;
struct V_48 * V_49 ;
V_40 = F_48 ( V_113 , struct V_132 ,
V_41 ) ;
V_11 = F_48 ( V_40 , struct V_7 , V_40 ) ;
V_49 = V_40 -> V_49 ;
F_64 ( V_11 ) ;
F_20 ( F_35 ( V_49 -> V_60 ) , V_35 ) ;
F_72 ( V_49 ,
( V_131 | V_133 ) ) ;
F_21 ( F_35 ( V_49 -> V_60 ) , V_35 ) ;
F_58 ( V_11 , V_49 , V_40 -> V_73 ) ;
F_20 ( & V_11 -> V_46 , V_35 ) ;
F_71 ( V_11 ) ;
F_61 ( V_11 ) ;
F_32 ( V_11 , V_49 ) ;
V_11 -> V_40 . V_49 = NULL ;
F_21 ( & V_11 -> V_46 , V_35 ) ;
}
void F_73 ( struct V_48 * V_49 ,
struct V_76 * V_76 )
{
struct V_7 * V_11 ;
char V_73 ;
struct V_50 * V_51 ;
char * V_72 ;
V_51 = (struct V_50 * ) V_49 -> V_51 ;
V_72 = F_39 ( V_76 ) ;
if ( V_72 ) {
V_73 = V_72 [ 8 ] ;
F_49 ( V_134 , V_49 , L_6 ,
L_7 , V_73 ) ;
} else {
F_49 ( V_115 , V_49 , L_3 ,
L_8
L_9 ) ;
return;
}
V_11 = V_51 -> V_11 ;
if ( ! V_11 ) {
F_49 ( V_115 , V_49 , L_3 ,
L_10
L_11 ) ;
return;
}
F_25 ( & V_11 -> V_46 ) ;
F_70 ( V_11 , V_49 ) ;
V_51 -> V_11 -> V_35 |= V_36 | V_37 ;
if ( F_5 ( & V_49 -> V_58 ) ) {
F_49 ( V_115 , V_49 , L_3 ,
L_12
L_13 ) ;
F_26 ( & V_11 -> V_46 ) ;
return;
}
if ( V_11 -> V_40 . V_49 ) {
F_49 ( V_115 , V_49 , L_3 ,
L_14
L_15 ) ;
F_26 ( & V_11 -> V_46 ) ;
return ;
}
V_11 -> V_40 . V_73 = V_73 ;
V_11 -> V_40 . V_49 = V_49 ;
F_26 ( & V_11 -> V_46 ) ;
F_74 ( & V_11 -> V_40 . V_41 ) ;
}
