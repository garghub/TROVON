static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_4 = V_3 ;
F_2 ( V_4 ) ;
}
int F_3 ( T_1 V_5 , void * V_6 )
{
struct V_4 V_4 ;
struct V_1 * V_7 ;
int V_8 ;
V_7 = F_4 ( sizeof( * V_7 ) , V_9 ) ;
if ( ! V_7 )
return - V_10 ;
V_7 -> V_11 = V_5 ;
V_7 -> V_6 = V_6 ;
V_7 -> V_12 = V_13 ;
V_7 -> V_14 = F_1 ;
V_7 -> V_15 = & V_4 ;
F_5 ( & V_4 ) ;
V_8 = F_6 ( V_7 ) ;
if ( V_8 )
goto V_16;
F_7 ( & V_4 ) ;
if ( V_7 -> V_12 != V_17 ) {
F_8 ( L_1
L_2 , V_5 , V_7 -> V_12 ) ;
V_8 = - V_18 ;
}
V_16:
F_9 ( V_7 ) ;
return V_8 ;
}
static void F_10 ( struct V_19 * V_20 ,
struct V_21 * V_6 )
{
char * V_22 = ( char * ) V_6 ;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
V_20 -> V_23 = V_6 -> V_24 ;
V_20 -> V_25 = V_6 -> V_26 ;
V_20 -> V_27 = V_6 -> V_24 + V_6 -> V_26 ;
V_20 -> V_28 = V_29 & 0x1 ;
memcpy ( & V_20 -> V_30 , V_22 + V_6 -> V_31 ,
V_20 -> V_27 * sizeof( struct V_32 ) ) ;
}
int F_11 ( struct V_19 * V_20 )
{
int V_8 ;
struct V_21 * V_6 ;
if ( ! V_33 )
return - V_34 ;
V_6 = ( void * ) F_12 ( V_9 | V_35 ) ;
if ( ! V_6 )
return - V_10 ;
V_6 -> V_36 . V_37 = sizeof( * V_6 ) ;
V_8 = F_3 ( V_38 , V_6 ) ;
if ( V_8 )
goto V_16;
if ( V_6 -> V_36 . V_39 != 0x0010 ) {
F_8 ( L_3 ,
V_6 -> V_36 . V_39 ) ;
V_8 = - V_18 ;
goto V_16;
}
F_10 ( V_20 , V_6 ) ;
V_16:
F_13 ( ( unsigned long ) V_6 ) ;
return V_8 ;
}
static int F_14 ( T_1 V_5 )
{
struct V_40 * V_6 ;
int V_8 ;
if ( ! V_41 )
return - V_34 ;
V_6 = F_4 ( sizeof( * V_6 ) , V_9 | V_35 ) ;
if ( ! V_6 )
return - V_10 ;
V_6 -> V_36 . V_37 = sizeof( * V_6 ) ;
V_8 = F_3 ( V_5 , V_6 ) ;
if ( V_8 )
goto V_16;
switch ( V_6 -> V_36 . V_39 ) {
case 0x0020 :
case 0x0120 :
break;
default:
F_8 ( L_4
L_5 , V_5 ,
V_6 -> V_36 . V_39 ) ;
V_8 = - V_18 ;
break;
}
V_16:
F_9 ( V_6 ) ;
return V_8 ;
}
int F_15 ( T_2 V_30 )
{
return F_14 ( V_42 | V_30 << 8 ) ;
}
int F_16 ( T_2 V_30 )
{
return F_14 ( V_43 | V_30 << 8 ) ;
}
int F_17 ( unsigned long V_44 )
{
if ( ! V_45 )
return 0 ;
return F_18 ( V_44 ) >> F_19 ( V_45 ) ;
}
static unsigned long long F_20 ( T_3 V_46 )
{
return ( unsigned long long ) ( V_46 - 1 ) * V_45 ;
}
static int F_21 ( T_1 V_5 , T_3 V_46 )
{
struct V_47 * V_6 ;
int V_8 ;
V_6 = ( void * ) F_12 ( V_9 | V_35 ) ;
if ( ! V_6 )
return - V_10 ;
V_6 -> V_36 . V_37 = V_48 ;
V_6 -> V_46 = V_46 ;
V_8 = F_3 ( V_5 , V_6 ) ;
if ( V_8 )
goto V_16;
switch ( V_6 -> V_36 . V_39 ) {
case 0x0020 :
case 0x0120 :
break;
default:
F_8 ( L_6
L_7 , V_5 ,
V_6 -> V_36 . V_39 , V_46 ) ;
V_8 = - V_18 ;
break;
}
V_16:
F_13 ( ( unsigned long ) V_6 ) ;
return V_8 ;
}
static int F_22 ( T_3 V_46 )
{
unsigned long long V_49 ;
int V_8 ;
V_8 = F_21 ( 0x000d0001 , V_46 ) ;
if ( V_8 )
return V_8 ;
V_49 = F_20 ( V_46 ) ;
F_23 ( V_49 , V_49 + V_45 ) ;
return 0 ;
}
static int F_24 ( T_3 V_46 )
{
return F_21 ( 0x000c0001 , V_46 ) ;
}
static int F_25 ( T_2 V_50 )
{
struct V_51 * V_6 ;
int V_8 ;
int V_52 ;
V_6 = ( void * ) F_12 ( V_9 | V_35 ) ;
if ( ! V_6 )
return - V_10 ;
V_6 -> V_36 . V_37 = V_48 ;
V_8 = F_3 ( 0x00080001 | V_50 << 8 , V_6 ) ;
if ( V_8 )
goto V_16;
switch ( V_6 -> V_36 . V_39 ) {
case 0x0020 :
F_26 ( V_50 , V_53 ) ;
for ( V_52 = 0 ; V_52 < V_6 -> V_54 ; V_52 ++ ) {
if ( V_6 -> V_55 [ V_52 ] )
F_24 ( V_6 -> V_55 [ V_52 ] >> 16 ) ;
}
break;
default:
V_8 = - V_18 ;
break;
}
V_16:
F_13 ( ( unsigned long ) V_6 ) ;
return V_8 ;
}
static int F_27 ( unsigned long V_49 , unsigned long V_56 ,
int V_57 )
{
struct V_58 * V_59 ;
unsigned long long V_60 ;
int V_8 = 0 ;
F_28 (incr, &sclp_mem_list, list) {
V_60 = F_20 ( V_59 -> V_46 ) ;
if ( V_49 + V_56 - 1 < V_60 )
break;
if ( V_49 > V_60 + V_45 - 1 )
continue;
if ( V_57 )
V_8 |= F_22 ( V_59 -> V_46 ) ;
else
F_24 ( V_59 -> V_46 ) ;
}
return V_8 ? - V_18 : 0 ;
}
static int F_29 ( struct V_61 * V_62 ,
unsigned long V_63 , void * V_3 )
{
unsigned long V_49 , V_56 ;
struct V_64 * V_65 ;
unsigned char V_50 ;
int V_8 = 0 ;
V_65 = V_3 ;
V_49 = V_65 -> V_44 << V_66 ;
V_56 = V_65 -> V_67 << V_66 ;
F_30 ( & V_68 ) ;
F_31 (id, sclp_storage_ids, sclp_max_storage_id + 1 )
F_25 ( V_50 ) ;
switch ( V_63 ) {
case V_69 :
case V_70 :
case V_71 :
break;
case V_72 :
V_8 = F_27 ( V_49 , V_56 , 1 ) ;
break;
case V_73 :
F_27 ( V_49 , V_56 , 0 ) ;
break;
case V_74 :
F_27 ( V_49 , V_56 , 0 ) ;
break;
default:
V_8 = - V_75 ;
break;
}
if ( ! V_8 )
V_76 = 1 ;
F_32 ( & V_68 ) ;
return V_8 ? V_77 : V_78 ;
}
static void T_4 F_33 ( T_3 V_46 )
{
static T_3 V_79 , V_80 ;
unsigned long long V_49 , V_56 ;
if ( V_46 && V_79 && ( V_79 + V_80 == V_46 ) ) {
V_80 ++ ;
return;
}
if ( ! V_79 )
goto V_81;
V_49 = F_20 ( V_79 ) ;
V_56 = ( unsigned long long ) V_80 * V_45 ;
if ( V_49 >= V_82 )
goto V_81;
if ( V_49 + V_56 > V_82 )
V_56 = V_82 - V_49 ;
if ( V_83 && ( V_49 >= V_84 ) )
goto V_81;
if ( V_83 && ( V_49 + V_56 > V_84 ) )
V_56 = V_84 - V_49 ;
F_34 ( 0 , V_49 , V_56 ) ;
V_81:
V_79 = V_46 ;
V_80 = 1 ;
}
static void T_4 F_35 ( void )
{
struct V_58 * V_59 ;
F_28 (incr, &sclp_mem_list, list)
if ( V_59 -> V_25 )
F_33 ( V_59 -> V_46 ) ;
F_33 ( 0 ) ;
}
static void T_4 F_36 ( T_3 V_46 , int V_25 , int V_54 )
{
struct V_58 * V_59 , * V_85 ;
struct V_86 * V_87 ;
T_3 V_88 ;
V_85 = F_4 ( sizeof( * V_85 ) , V_9 ) ;
if ( ! V_85 )
return;
V_85 -> V_46 = V_46 ;
V_85 -> V_25 = V_25 ;
V_88 = 0 ;
V_87 = & V_89 ;
F_28 (incr, &sclp_mem_list, list) {
if ( V_54 && V_59 -> V_46 > V_46 )
break;
if ( ! V_54 && V_59 -> V_46 - V_88 > 1 )
break;
V_88 = V_59 -> V_46 ;
V_87 = & V_59 -> V_90 ;
}
if ( ! V_54 )
V_85 -> V_46 = V_88 + 1 ;
if ( V_85 -> V_46 > V_91 ) {
F_9 ( V_85 ) ;
return;
}
F_37 ( & V_85 -> V_90 , V_87 ) ;
}
static int F_38 ( struct V_92 * V_93 )
{
if ( ! V_76 )
return 0 ;
F_39 ( L_8 ) ;
return - V_94 ;
}
static int T_4 F_40 ( void )
{
struct V_95 * V_96 ;
struct V_97 * V_6 ;
int V_52 , V_50 , V_54 , V_8 ;
if ( V_98 )
return 0 ;
if ( ( V_99 & 0xe00000000000ULL ) != 0xe00000000000ULL )
return 0 ;
V_8 = - V_10 ;
V_6 = ( void * ) F_41 ( V_9 | V_35 ) ;
if ( ! V_6 )
goto V_16;
V_54 = 0 ;
for ( V_50 = 0 ; V_50 <= V_100 ; V_50 ++ ) {
memset ( V_6 , 0 , V_48 ) ;
V_6 -> V_36 . V_37 = V_48 ;
V_8 = F_3 ( 0x00040001 | V_50 << 8 , V_6 ) ;
if ( V_8 )
goto V_16;
switch ( V_6 -> V_36 . V_39 ) {
case 0x0010 :
F_26 ( V_50 , V_53 ) ;
for ( V_52 = 0 ; V_52 < V_6 -> V_54 ; V_52 ++ ) {
if ( ! V_6 -> V_55 [ V_52 ] )
continue;
V_54 ++ ;
F_36 ( V_6 -> V_55 [ V_52 ] >> 16 , 0 , 1 ) ;
}
break;
case 0x0310 :
break;
case 0x0410 :
for ( V_52 = 0 ; V_52 < V_6 -> V_54 ; V_52 ++ ) {
if ( ! V_6 -> V_55 [ V_52 ] )
continue;
V_54 ++ ;
F_36 ( V_6 -> V_55 [ V_52 ] >> 16 , 1 , 1 ) ;
}
break;
default:
V_8 = - V_18 ;
break;
}
if ( ! V_8 )
V_100 = V_6 -> V_101 ;
}
if ( V_8 || F_42 ( & V_89 ) )
goto V_16;
for ( V_52 = 1 ; V_52 <= V_91 - V_54 ; V_52 ++ )
F_36 ( 0 , 1 , 0 ) ;
V_8 = F_43 ( & V_102 ) ;
if ( V_8 )
goto V_16;
V_8 = F_44 ( & V_103 ) ;
if ( V_8 )
goto V_16;
V_96 = F_45 ( L_9 , - 1 , NULL , 0 ) ;
V_8 = F_46 ( V_96 ) ;
if ( V_8 )
goto V_104;
F_35 () ;
goto V_16;
V_104:
F_47 ( & V_103 ) ;
V_16:
F_13 ( ( unsigned long ) V_6 ) ;
return V_8 ;
}
static int F_48 ( T_1 V_5 , T_5 V_105 )
{
struct V_106 * V_6 ;
int V_8 ;
if ( ! V_107 )
return - V_34 ;
V_6 = (struct V_106 * ) F_12 ( V_9 | V_35 ) ;
if ( ! V_6 )
return - V_10 ;
V_6 -> V_36 . V_37 = V_48 ;
V_6 -> V_108 = V_109 ;
V_6 -> V_110 = V_105 ;
V_8 = F_3 ( V_5 , V_6 ) ;
if ( V_8 )
goto V_16;
switch ( V_6 -> V_36 . V_39 ) {
case 0x0020 :
case 0x0120 :
break;
default:
F_49 ( L_10 ,
V_5 , V_6 -> V_36 . V_39 ) ;
V_8 = - V_18 ;
break;
}
V_16:
F_13 ( ( unsigned long ) V_6 ) ;
return V_8 ;
}
int F_50 ( T_5 V_105 )
{
return F_48 ( V_111 , V_105 ) ;
}
int F_51 ( T_5 V_105 )
{
return F_48 ( V_112 , V_105 ) ;
}
static int F_52 ( T_1 V_5 )
{
struct V_113 * V_6 ;
int V_8 ;
if ( ! V_114 )
return - V_34 ;
V_6 = (struct V_113 * ) F_12 ( V_9 | V_35 ) ;
if ( ! V_6 )
return - V_10 ;
V_6 -> V_36 . V_37 = sizeof( * V_6 ) ;
V_8 = F_3 ( V_5 , V_6 ) ;
if ( V_8 )
goto V_16;
switch ( V_6 -> V_36 . V_39 ) {
case 0x0020 :
case 0x0120 :
case 0x0440 :
case 0x0450 :
break;
default:
F_8 ( L_11
L_12 , V_5 ,
V_6 -> V_36 . V_39 ) ;
V_8 = - V_18 ;
break;
}
V_16:
F_13 ( ( unsigned long ) V_6 ) ;
return V_8 ;
}
int F_53 ( struct V_115 V_116 )
{
return F_52 ( V_117 | V_116 . V_50 << 8 ) ;
}
int F_54 ( struct V_115 V_116 )
{
return F_52 ( V_118 | V_116 . V_50 << 8 ) ;
}
int F_55 ( struct V_119 * V_20 )
{
struct V_120 * V_6 ;
int V_8 ;
if ( ! V_121 )
return - V_34 ;
V_6 = (struct V_120 * ) F_12 ( V_9 | V_35 ) ;
if ( ! V_6 )
return - V_10 ;
V_6 -> V_36 . V_37 = sizeof( * V_6 ) ;
V_8 = F_3 ( V_122 , V_6 ) ;
if ( V_8 )
goto V_16;
if ( V_6 -> V_36 . V_39 != 0x0010 ) {
F_8 ( L_13
L_14 , V_6 -> V_36 . V_39 ) ;
V_8 = - V_18 ;
goto V_16;
}
memcpy ( V_20 -> V_123 , V_6 -> V_123 , V_124 ) ;
memcpy ( V_20 -> V_25 , V_6 -> V_25 , V_124 ) ;
memcpy ( V_20 -> V_23 , V_6 -> V_23 , V_124 ) ;
V_16:
F_13 ( ( unsigned long ) V_6 ) ;
return V_8 ;
}
bool F_56 ( void )
{
return ! ! ( V_29 & 0x2 ) ;
}
