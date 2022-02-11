static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_2 (pos, &aliastree.serverlist, server) {
if ( ! strncmp ( V_4 -> V_3 . V_5 , V_3 -> V_5 ,
sizeof( V_3 -> V_5 ) )
&& ! strncmp ( V_4 -> V_3 . V_6 , V_3 -> V_6 ,
sizeof( V_3 -> V_6 ) ) )
return V_4 ;
} ;
return NULL ;
}
static struct V_7 * F_3 ( struct V_1 * V_8 ,
struct V_2 * V_3 )
{
struct V_7 * V_4 ;
F_2 (pos, &server->lculist, lcu) {
if ( V_4 -> V_3 . V_9 == V_3 -> V_9 )
return V_4 ;
} ;
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
} ;
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
int V_54 ;
struct V_2 V_3 ;
V_51 = (struct V_50 * ) V_49 -> V_51 ;
V_49 -> V_55 -> V_56 ( V_49 , & V_3 ) ;
F_20 ( & V_57 . V_46 , V_35 ) ;
V_54 = 1 ;
V_8 = F_1 ( & V_3 ) ;
if ( ! V_8 ) {
F_21 ( & V_57 . V_46 , V_35 ) ;
V_52 = F_7 ( & V_3 ) ;
if ( F_22 ( V_52 ) )
return F_23 ( V_52 ) ;
F_20 ( & V_57 . V_46 , V_35 ) ;
V_8 = F_1 ( & V_3 ) ;
if ( ! V_8 ) {
F_24 ( & V_52 -> V_8 , & V_57 . V_58 ) ;
V_8 = V_52 ;
V_54 = 0 ;
} else {
F_11 ( V_52 ) ;
}
}
V_11 = F_3 ( V_8 , & V_3 ) ;
if ( ! V_11 ) {
F_21 ( & V_57 . V_46 , V_35 ) ;
V_53 = F_13 ( & V_3 ) ;
if ( F_22 ( V_53 ) )
return F_23 ( V_53 ) ;
F_20 ( & V_57 . V_46 , V_35 ) ;
V_11 = F_3 ( V_8 , & V_3 ) ;
if ( ! V_11 ) {
F_24 ( & V_53 -> V_11 , & V_8 -> V_23 ) ;
V_11 = V_53 ;
V_54 = 0 ;
} else {
F_18 ( V_53 ) ;
}
V_54 = 0 ;
}
F_25 ( & V_11 -> V_46 ) ;
F_24 ( & V_49 -> V_59 , & V_11 -> V_38 ) ;
V_51 -> V_11 = V_11 ;
F_26 ( & V_11 -> V_46 ) ;
F_21 ( & V_57 . V_46 , V_35 ) ;
return V_54 ;
}
void F_27 ( struct V_48 * V_49 )
{
unsigned long V_35 ;
struct V_1 * V_8 ;
struct V_7 * V_11 ;
struct V_2 V_3 ;
V_49 -> V_55 -> V_56 ( V_49 , & V_3 ) ;
V_11 = NULL ;
F_20 ( & V_57 . V_46 , V_35 ) ;
V_8 = F_1 ( & V_3 ) ;
if ( V_8 )
V_11 = F_3 ( V_8 , & V_3 ) ;
F_21 ( & V_57 . V_46 , V_35 ) ;
if ( ! V_11 ) {
F_28 ( V_60 , V_49 -> V_61 ,
L_1 ,
V_3 . V_9 , V_3 . V_18 ) ;
F_29 ( 1 ) ;
return;
}
F_30 ( & V_11 -> V_47 ) ;
}
void F_31 ( struct V_48 * V_49 )
{
unsigned long V_35 ;
struct V_1 * V_8 ;
struct V_7 * V_11 ;
struct V_2 V_3 ;
V_49 -> V_55 -> V_56 ( V_49 , & V_3 ) ;
V_11 = NULL ;
F_20 ( & V_57 . V_46 , V_35 ) ;
V_8 = F_1 ( & V_3 ) ;
if ( V_8 )
V_11 = F_3 ( V_8 , & V_3 ) ;
F_21 ( & V_57 . V_46 , V_35 ) ;
if ( ! V_11 ) {
F_28 ( V_60 , V_49 -> V_61 ,
L_1 ,
V_3 . V_9 , V_3 . V_18 ) ;
F_29 ( 1 ) ;
return;
}
F_32 ( & V_11 -> V_47 ) ;
}
void F_33 ( struct V_48 * V_49 )
{
struct V_50 * V_51 ;
unsigned long V_35 ;
struct V_7 * V_11 ;
struct V_1 * V_8 ;
int V_62 ;
struct V_2 V_3 ;
V_51 = (struct V_50 * ) V_49 -> V_51 ;
V_11 = V_51 -> V_11 ;
if ( ! V_11 )
return;
V_49 -> V_55 -> V_56 ( V_49 , & V_3 ) ;
F_20 ( & V_11 -> V_46 , V_35 ) ;
F_34 ( & V_49 -> V_59 ) ;
if ( V_49 == V_11 -> V_40 . V_49 ) {
F_21 ( & V_11 -> V_46 , V_35 ) ;
F_35 ( & V_11 -> V_40 . V_41 ) ;
F_20 ( & V_11 -> V_46 , V_35 ) ;
if ( V_49 == V_11 -> V_40 . V_49 )
V_11 -> V_40 . V_49 = NULL ;
}
V_62 = 0 ;
if ( V_49 == V_11 -> V_43 . V_49 ) {
F_21 ( & V_11 -> V_46 , V_35 ) ;
V_62 = 1 ;
F_36 ( & V_11 -> V_43 . V_44 ) ;
F_20 ( & V_11 -> V_46 , V_35 ) ;
if ( V_49 == V_11 -> V_43 . V_49 )
V_11 -> V_43 . V_49 = NULL ;
}
V_51 -> V_11 = NULL ;
F_21 ( & V_11 -> V_46 , V_35 ) ;
F_20 ( & V_57 . V_46 , V_35 ) ;
F_25 ( & V_11 -> V_46 ) ;
if ( F_5 ( & V_11 -> V_15 ) &&
F_5 ( & V_11 -> V_39 ) &&
F_5 ( & V_11 -> V_38 ) ) {
F_37 ( & V_11 -> V_11 ) ;
F_26 ( & V_11 -> V_46 ) ;
F_18 ( V_11 ) ;
V_11 = NULL ;
} else {
if ( V_62 )
F_38 ( V_11 , NULL ) ;
F_26 ( & V_11 -> V_46 ) ;
}
V_8 = F_1 ( & V_3 ) ;
if ( V_8 && F_5 ( & V_8 -> V_23 ) ) {
F_37 ( & V_8 -> V_8 ) ;
F_11 ( V_8 ) ;
}
F_21 ( & V_57 . V_46 , V_35 ) ;
}
static int F_39 ( struct V_7 * V_11 ,
struct V_48 * V_49 ,
struct V_48 * V_4 )
{
struct V_50 * V_51 ;
struct V_10 * V_16 ;
struct V_2 V_3 ;
unsigned long V_35 ;
V_51 = (struct V_50 * ) V_49 -> V_51 ;
if ( V_49 != V_4 )
F_40 ( F_41 ( V_49 -> V_61 ) , V_35 ,
V_63 ) ;
V_51 -> V_3 . type = V_11 -> V_24 -> V_64 [ V_51 -> V_3 . V_18 ] . V_65 ;
V_51 -> V_3 . V_19 =
V_11 -> V_24 -> V_64 [ V_51 -> V_3 . V_18 ] . V_66 ;
V_3 = V_51 -> V_3 ;
if ( V_49 != V_4 )
F_21 ( F_41 ( V_49 -> V_61 ) , V_35 ) ;
if ( V_11 -> V_13 == V_34 ) {
F_42 ( & V_49 -> V_59 , & V_11 -> V_39 ) ;
return 0 ;
}
V_16 = F_4 ( V_11 , & V_3 ) ;
if ( ! V_16 ) {
V_16 = F_8 ( sizeof( * V_16 ) , V_67 ) ;
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
F_10 ( & V_16 -> V_68 ) ;
F_10 ( & V_16 -> V_69 ) ;
F_24 ( & V_16 -> V_16 , & V_11 -> V_15 ) ;
}
if ( V_3 . type == V_17 )
F_42 ( & V_49 -> V_59 , & V_16 -> V_68 ) ;
else
F_42 ( & V_49 -> V_59 , & V_16 -> V_69 ) ;
V_51 -> V_70 = V_16 ;
return 0 ;
}
static void F_43 ( struct V_7 * V_11 ,
struct V_48 * V_49 )
{
struct V_50 * V_51 ;
struct V_10 * V_16 ;
V_51 = (struct V_50 * ) V_49 -> V_51 ;
F_42 ( & V_49 -> V_59 , & V_11 -> V_38 ) ;
V_16 = V_51 -> V_70 ;
if ( ! V_16 )
return;
V_51 -> V_70 = NULL ;
if ( F_5 ( & V_16 -> V_68 ) && F_5 ( & V_16 -> V_69 ) ) {
F_37 ( & V_16 -> V_16 ) ;
F_12 ( V_16 ) ;
return;
}
if ( V_16 -> V_71 == V_49 )
V_16 -> V_71 = NULL ;
}
static int F_44 ( struct V_48 * V_49 ,
struct V_7 * V_11 )
{
struct V_72 * V_73 ;
struct V_74 * V_75 ;
struct V_30 * V_76 ;
int V_77 ;
unsigned long V_35 ;
V_75 = F_45 ( V_78 , 1 + 1 ,
( sizeof( struct V_72 ) ) ,
V_49 ) ;
if ( F_22 ( V_75 ) )
return F_23 ( V_75 ) ;
V_75 -> V_79 = V_49 ;
V_75 -> V_80 = V_49 ;
F_46 ( V_81 , & V_75 -> V_35 ) ;
V_75 -> V_82 = 10 ;
V_75 -> V_83 = 20 * V_84 ;
V_73 = (struct V_72 * ) V_75 -> V_32 ;
memset ( V_73 , 0 , sizeof( struct V_72 ) ) ;
V_73 -> V_85 = V_86 ;
V_73 -> V_87 = 0x0e ;
V_76 = V_75 -> V_29 ;
V_76 -> V_88 = V_89 ;
V_76 -> V_90 = sizeof( struct V_72 ) ;
V_76 -> V_35 |= V_91 ;
V_76 -> V_92 = ( V_93 ) ( V_94 ) V_73 ;
memset ( V_11 -> V_24 , 0 , sizeof( * ( V_11 -> V_24 ) ) ) ;
V_76 ++ ;
V_76 -> V_88 = V_95 ;
V_76 -> V_90 = sizeof( * ( V_11 -> V_24 ) ) ;
V_76 -> V_92 = ( V_93 ) ( V_94 ) V_11 -> V_24 ;
V_75 -> V_96 = F_47 () ;
V_75 -> V_97 = V_98 ;
F_20 ( & V_11 -> V_46 , V_35 ) ;
V_11 -> V_35 &= ~ V_36 ;
F_21 ( & V_11 -> V_46 , V_35 ) ;
do {
V_77 = F_48 ( V_75 ) ;
} while ( V_77 && ( V_75 -> V_82 > 0 ) );
if ( V_77 ) {
F_20 ( & V_11 -> V_46 , V_35 ) ;
V_11 -> V_35 |= V_36 ;
F_21 ( & V_11 -> V_46 , V_35 ) ;
}
F_49 ( V_75 , V_75 -> V_80 ) ;
return V_77 ;
}
static int F_50 ( struct V_48 * V_99 , struct V_7 * V_11 )
{
unsigned long V_35 ;
struct V_10 * V_70 , * V_100 ;
struct V_48 * V_49 , * V_101 ;
int V_102 , V_77 ;
struct V_50 * V_51 ;
F_20 ( & V_11 -> V_46 , V_35 ) ;
F_51 (pavgroup, tempgroup, &lcu->grouplist, group) {
F_51 (device, tempdev, &pavgroup->baselist,
alias_list) {
F_42 ( & V_49 -> V_59 , & V_11 -> V_39 ) ;
V_51 = (struct V_50 * ) V_49 -> V_51 ;
V_51 -> V_70 = NULL ;
}
F_51 (device, tempdev, &pavgroup->aliaslist,
alias_list) {
F_42 ( & V_49 -> V_59 , & V_11 -> V_39 ) ;
V_51 = (struct V_50 * ) V_49 -> V_51 ;
V_51 -> V_70 = NULL ;
}
F_37 ( & V_70 -> V_16 ) ;
F_12 ( V_70 ) ;
}
F_21 ( & V_11 -> V_46 , V_35 ) ;
V_77 = F_44 ( V_99 , V_11 ) ;
if ( V_77 )
return V_77 ;
F_40 ( F_41 ( V_99 -> V_61 ) , V_35 ,
V_103 ) ;
F_25 ( & V_11 -> V_46 ) ;
V_11 -> V_13 = V_34 ;
for ( V_102 = 0 ; V_102 < V_104 ; ++ V_102 ) {
switch ( V_11 -> V_24 -> V_64 [ V_102 ] . V_65 ) {
case V_105 :
V_11 -> V_13 = V_106 ;
break;
case V_107 :
V_11 -> V_13 = V_14 ;
break;
}
if ( V_11 -> V_13 != V_34 )
break;
}
F_51 (device, tempdev, &lcu->active_devices,
alias_list) {
F_39 ( V_11 , V_49 , V_99 ) ;
}
F_26 ( & V_11 -> V_46 ) ;
F_21 ( F_41 ( V_99 -> V_61 ) , V_35 ) ;
return 0 ;
}
static void V_45 ( struct V_108 * V_109 )
{
struct V_7 * V_11 ;
struct V_110 * V_43 ;
struct V_48 * V_49 ;
unsigned long V_35 ;
int V_77 ;
V_43 = F_52 ( V_109 , struct V_110 , V_44 . V_109 ) ;
V_11 = F_52 ( V_43 , struct V_7 , V_43 ) ;
V_49 = V_43 -> V_49 ;
V_77 = F_50 ( V_49 , V_11 ) ;
F_20 ( & V_11 -> V_46 , V_35 ) ;
if ( V_77 || ( V_11 -> V_35 & V_36 ) ) {
F_53 ( V_111 , V_49 , L_2
L_3 , V_77 ) ;
F_54 ( & V_11 -> V_43 . V_44 , 30 * V_84 ) ;
} else {
V_11 -> V_43 . V_49 = NULL ;
V_11 -> V_35 &= ~ V_37 ;
}
F_21 ( & V_11 -> V_46 , V_35 ) ;
}
static int F_38 ( struct V_7 * V_11 ,
struct V_48 * V_49 )
{
struct V_48 * V_112 = NULL ;
struct V_10 * V_16 ;
V_11 -> V_35 |= V_36 ;
if ( V_11 -> V_43 . V_49 ) {
return 0 ;
}
if ( V_49 && ! F_5 ( & V_49 -> V_59 ) )
V_112 = V_49 ;
if ( ! V_112 && ! F_5 ( & V_11 -> V_15 ) ) {
V_16 = F_6 ( & V_11 -> V_15 ,
struct V_10 , V_16 ) ;
if ( ! F_5 ( & V_16 -> V_68 ) )
V_112 = F_6 ( & V_16 -> V_68 ,
struct V_48 ,
V_59 ) ;
else if ( ! F_5 ( & V_16 -> V_69 ) )
V_112 = F_6 ( & V_16 -> V_69 ,
struct V_48 ,
V_59 ) ;
}
if ( ! V_112 && ! F_5 ( & V_11 -> V_39 ) ) {
V_112 = F_6 ( & V_11 -> V_39 ,
struct V_48 , V_59 ) ;
}
if ( ! V_112 )
return - V_113 ;
V_11 -> V_43 . V_49 = V_112 ;
F_54 ( & V_11 -> V_43 . V_44 , 0 ) ;
return 0 ;
}
int F_55 ( struct V_48 * V_49 )
{
struct V_50 * V_51 ;
struct V_7 * V_11 ;
unsigned long V_35 ;
int V_77 ;
V_51 = (struct V_50 * ) V_49 -> V_51 ;
V_11 = V_51 -> V_11 ;
V_77 = 0 ;
F_20 ( F_41 ( V_49 -> V_61 ) , V_35 ) ;
F_25 ( & V_11 -> V_46 ) ;
if ( ! ( V_11 -> V_35 & V_37 ) ) {
V_77 = F_39 ( V_11 , V_49 , V_49 ) ;
if ( V_77 )
V_11 -> V_35 |= V_37 ;
}
if ( V_11 -> V_35 & V_37 ) {
F_42 ( & V_49 -> V_59 , & V_11 -> V_39 ) ;
F_38 ( V_11 , V_49 ) ;
}
F_26 ( & V_11 -> V_46 ) ;
F_21 ( F_41 ( V_49 -> V_61 ) , V_35 ) ;
return V_77 ;
}
int F_56 ( struct V_48 * V_49 )
{
struct V_50 * V_51 ;
V_51 = (struct V_50 * ) V_49 -> V_51 ;
V_51 -> V_11 -> V_35 |= V_37 ;
return F_55 ( V_49 ) ;
}
int F_57 ( struct V_48 * V_49 )
{
struct V_50 * V_51 ;
struct V_7 * V_11 ;
unsigned long V_35 ;
V_51 = (struct V_50 * ) V_49 -> V_51 ;
V_11 = V_51 -> V_11 ;
if ( ! V_11 )
return 0 ;
F_20 ( & V_11 -> V_46 , V_35 ) ;
F_43 ( V_11 , V_49 ) ;
F_21 ( & V_11 -> V_46 , V_35 ) ;
return 0 ;
}
struct V_48 * F_58 ( struct V_48 * V_114 )
{
struct V_48 * V_115 ;
struct V_10 * V_16 ;
struct V_7 * V_11 ;
struct V_50 * V_51 , * V_116 ;
unsigned long V_35 ;
V_51 = (struct V_50 * ) V_114 -> V_51 ;
V_16 = V_51 -> V_70 ;
V_11 = V_51 -> V_11 ;
if ( ! V_16 || ! V_11 )
return NULL ;
if ( V_11 -> V_13 == V_34 ||
V_11 -> V_35 & ( V_36 | V_37 ) )
return NULL ;
F_20 ( & V_11 -> V_46 , V_35 ) ;
V_115 = V_16 -> V_71 ;
if ( ! V_115 ) {
if ( F_5 ( & V_16 -> V_69 ) ) {
F_21 ( & V_11 -> V_46 , V_35 ) ;
return NULL ;
} else {
V_115 = F_6 ( & V_16 -> V_69 ,
struct V_48 ,
V_59 ) ;
}
}
if ( F_59 ( & V_115 -> V_59 , & V_16 -> V_69 ) )
V_16 -> V_71 = F_6 ( & V_16 -> V_69 ,
struct V_48 , V_59 ) ;
else
V_16 -> V_71 = F_6 ( & V_115 -> V_59 ,
struct V_48 , V_59 ) ;
F_21 ( & V_11 -> V_46 , V_35 ) ;
V_116 = (struct V_50 * ) V_115 -> V_51 ;
if ( ( V_116 -> V_90 < V_51 -> V_90 ) && ! V_115 -> V_117 )
return V_115 ;
else
return NULL ;
}
static int F_60 ( struct V_7 * V_11 ,
struct V_48 * V_49 ,
char V_118 )
{
struct V_74 * V_75 ;
int V_77 = 0 ;
struct V_30 * V_76 ;
V_75 = V_11 -> V_27 ;
strncpy ( ( char * ) & V_75 -> V_119 , L_4 , 4 ) ;
F_61 ( ( char * ) & V_75 -> V_119 , 4 ) ;
V_76 = V_75 -> V_29 ;
V_76 -> V_88 = V_120 ;
V_76 -> V_35 = 0 ;
V_76 -> V_90 = 16 ;
V_76 -> V_92 = ( V_93 ) ( V_94 ) V_75 -> V_32 ;
( ( char * ) V_75 -> V_32 ) [ 0 ] = V_118 ;
F_46 ( V_81 , & V_75 -> V_35 ) ;
V_75 -> V_82 = 255 ;
V_75 -> V_79 = V_49 ;
V_75 -> V_80 = V_49 ;
V_75 -> V_121 = NULL ;
V_75 -> V_83 = 5 * V_84 ;
V_75 -> V_96 = F_47 () ;
V_75 -> V_97 = V_98 ;
V_77 = F_62 ( V_75 ) ;
return V_77 ;
}
static void F_63 ( struct V_7 * V_11 )
{
struct V_10 * V_70 ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
unsigned long V_35 ;
F_2 (device, &lcu->active_devices, alias_list) {
V_51 = (struct V_50 * ) V_49 -> V_51 ;
F_20 ( F_41 ( V_49 -> V_61 ) , V_35 ) ;
if ( V_51 -> V_3 . type != V_17 ) {
F_21 ( F_41 ( V_49 -> V_61 ) ,
V_35 ) ;
continue;
}
F_21 ( F_41 ( V_49 -> V_61 ) , V_35 ) ;
F_64 ( V_49 -> V_121 ) ;
F_65 ( V_49 ) ;
}
F_2 (device, &lcu->inactive_devices, alias_list) {
V_51 = (struct V_50 * ) V_49 -> V_51 ;
F_20 ( F_41 ( V_49 -> V_61 ) , V_35 ) ;
if ( V_51 -> V_3 . type != V_17 ) {
F_21 ( F_41 ( V_49 -> V_61 ) ,
V_35 ) ;
continue;
}
F_21 ( F_41 ( V_49 -> V_61 ) , V_35 ) ;
F_64 ( V_49 -> V_121 ) ;
F_65 ( V_49 ) ;
}
F_2 (pavgroup, &lcu->grouplist, group) {
F_2 (device, &pavgroup->baselist, alias_list) {
F_64 ( V_49 -> V_121 ) ;
F_65 ( V_49 ) ;
}
}
}
static void F_66 ( struct V_7 * V_11 )
{
struct V_10 * V_70 ;
struct V_48 * V_49 , * V_122 ;
struct V_50 * V_51 ;
int V_77 ;
unsigned long V_35 ;
F_67 ( V_123 ) ;
F_20 ( & V_11 -> V_46 , V_35 ) ;
F_51 (device, temp, &lcu->active_devices,
alias_list) {
V_51 = (struct V_50 * ) V_49 -> V_51 ;
if ( V_51 -> V_3 . type == V_17 )
continue;
F_42 ( & V_49 -> V_59 , & V_123 ) ;
}
F_2 (pavgroup, &lcu->grouplist, group) {
F_68 ( & V_70 -> V_69 , & V_123 ) ;
}
while ( ! F_5 ( & V_123 ) ) {
V_49 = F_6 ( & V_123 , struct V_48 ,
V_59 ) ;
F_21 ( & V_11 -> V_46 , V_35 ) ;
V_77 = F_69 ( V_49 ) ;
F_20 ( & V_11 -> V_46 , V_35 ) ;
if ( V_49 == F_6 ( & V_123 ,
struct V_48 , V_59 ) )
F_42 ( & V_49 -> V_59 , & V_11 -> V_39 ) ;
}
F_21 ( & V_11 -> V_46 , V_35 ) ;
}
static void F_70 ( struct V_48 * V_49 ,
struct V_48 * V_4 )
{
if ( V_4 == V_49 ) {
F_71 ( V_4 , V_124 ) ;
return;
}
F_25 ( F_41 ( V_4 -> V_61 ) ) ;
F_71 ( V_4 , V_124 ) ;
F_26 ( F_41 ( V_4 -> V_61 ) ) ;
}
static void F_72 ( struct V_7 * V_11 ,
struct V_48 * V_49 )
{
struct V_10 * V_70 ;
struct V_48 * V_4 ;
F_2 (pos, &lcu->active_devices, alias_list)
F_70 ( V_49 , V_4 ) ;
F_2 (pos, &lcu->inactive_devices, alias_list)
F_70 ( V_49 , V_4 ) ;
F_2 (pavgroup, &lcu->grouplist, group) {
F_2 (pos, &pavgroup->baselist, alias_list)
F_70 ( V_49 , V_4 ) ;
F_2 (pos, &pavgroup->aliaslist, alias_list)
F_70 ( V_49 , V_4 ) ;
}
}
static void F_73 ( struct V_7 * V_11 )
{
struct V_10 * V_70 ;
struct V_48 * V_49 ;
unsigned long V_35 ;
F_2 (device, &lcu->active_devices, alias_list) {
F_20 ( F_41 ( V_49 -> V_61 ) , V_35 ) ;
F_74 ( V_49 , V_124 ) ;
F_21 ( F_41 ( V_49 -> V_61 ) , V_35 ) ;
}
F_2 (device, &lcu->inactive_devices, alias_list) {
F_20 ( F_41 ( V_49 -> V_61 ) , V_35 ) ;
F_74 ( V_49 , V_124 ) ;
F_21 ( F_41 ( V_49 -> V_61 ) , V_35 ) ;
}
F_2 (pavgroup, &lcu->grouplist, group) {
F_2 (device, &pavgroup->baselist, alias_list) {
F_20 ( F_41 ( V_49 -> V_61 ) , V_35 ) ;
F_74 ( V_49 , V_124 ) ;
F_21 ( F_41 ( V_49 -> V_61 ) ,
V_35 ) ;
}
F_2 (device, &pavgroup->aliaslist, alias_list) {
F_20 ( F_41 ( V_49 -> V_61 ) , V_35 ) ;
F_74 ( V_49 , V_124 ) ;
F_21 ( F_41 ( V_49 -> V_61 ) ,
V_35 ) ;
}
}
}
static void V_42 ( struct V_108 * V_109 )
{
struct V_7 * V_11 ;
struct V_125 * V_40 ;
unsigned long V_35 ;
struct V_48 * V_49 ;
V_40 = F_52 ( V_109 , struct V_125 ,
V_41 ) ;
V_11 = F_52 ( V_40 , struct V_7 , V_40 ) ;
V_49 = V_40 -> V_49 ;
F_66 ( V_11 ) ;
F_20 ( F_41 ( V_49 -> V_61 ) , V_35 ) ;
F_74 ( V_49 ,
( V_124 | V_126 ) ) ;
F_21 ( F_41 ( V_49 -> V_61 ) , V_35 ) ;
F_60 ( V_11 , V_49 , V_40 -> V_118 ) ;
F_20 ( & V_11 -> V_46 , V_35 ) ;
F_73 ( V_11 ) ;
F_63 ( V_11 ) ;
F_38 ( V_11 , V_49 ) ;
V_11 -> V_40 . V_49 = NULL ;
F_21 ( & V_11 -> V_46 , V_35 ) ;
}
void F_75 ( struct V_48 * V_49 ,
struct V_127 * V_127 )
{
struct V_7 * V_11 ;
char V_118 ;
struct V_50 * V_51 ;
char * V_128 ;
V_51 = (struct V_50 * ) V_49 -> V_51 ;
V_128 = F_76 ( V_127 ) ;
if ( V_128 ) {
V_118 = V_128 [ 8 ] ;
F_53 ( V_129 , V_49 , L_5 ,
L_6 , V_118 ) ;
} else {
F_53 ( V_111 , V_49 , L_7 ,
L_8
L_9 ) ;
return;
}
V_11 = V_51 -> V_11 ;
if ( ! V_11 ) {
F_53 ( V_111 , V_49 , L_7 ,
L_10
L_11 ) ;
return;
}
F_25 ( & V_11 -> V_46 ) ;
F_72 ( V_11 , V_49 ) ;
V_51 -> V_11 -> V_35 |= V_36 | V_37 ;
if ( F_5 ( & V_49 -> V_59 ) ) {
F_53 ( V_111 , V_49 , L_7 ,
L_12
L_13 ) ;
F_26 ( & V_11 -> V_46 ) ;
return;
}
if ( V_11 -> V_40 . V_49 ) {
F_53 ( V_111 , V_49 , L_7 ,
L_14
L_15 ) ;
F_26 ( & V_11 -> V_46 ) ;
return ;
}
V_11 -> V_40 . V_118 = V_118 ;
V_11 -> V_40 . V_49 = V_49 ;
F_26 ( & V_11 -> V_46 ) ;
F_77 ( & V_11 -> V_40 . V_41 ) ;
}
