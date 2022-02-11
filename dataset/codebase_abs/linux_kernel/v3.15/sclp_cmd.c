static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_4 = V_3 ;
F_2 ( V_4 ) ;
}
int F_3 ( T_1 V_5 , void * V_6 )
{
return F_4 ( V_5 , V_6 , 0 ) ;
}
int F_4 ( T_1 V_5 , void * V_6 , int V_7 )
{
struct V_4 V_4 ;
struct V_1 * V_8 ;
int V_9 ;
V_8 = F_5 ( sizeof( * V_8 ) , V_10 ) ;
if ( ! V_8 )
return - V_11 ;
if ( V_7 )
V_8 -> V_12 = V_7 ;
V_8 -> V_13 = V_5 ;
V_8 -> V_6 = V_6 ;
V_8 -> V_14 = V_15 ;
V_8 -> V_16 = F_1 ;
V_8 -> V_17 = & V_4 ;
F_6 ( & V_4 ) ;
V_9 = F_7 ( V_8 ) ;
if ( V_9 )
goto V_18;
F_8 ( & V_4 ) ;
if ( V_8 -> V_14 != V_19 ) {
F_9 ( L_1
L_2 , V_5 , V_8 -> V_14 ) ;
V_9 = - V_20 ;
}
V_18:
F_10 ( V_8 ) ;
return V_9 ;
}
static void F_11 ( struct V_21 * V_22 ,
struct V_23 * V_6 )
{
char * V_24 = ( char * ) V_6 ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_22 -> V_25 = V_6 -> V_26 ;
V_22 -> V_27 = V_6 -> V_28 ;
V_22 -> V_29 = V_6 -> V_26 + V_6 -> V_28 ;
V_22 -> V_30 = V_31 & 0x1 ;
memcpy ( & V_22 -> V_32 , V_24 + V_6 -> V_33 ,
V_22 -> V_29 * sizeof( struct V_34 ) ) ;
}
int F_12 ( struct V_21 * V_22 )
{
int V_9 ;
struct V_23 * V_6 ;
if ( ! V_35 )
return - V_36 ;
V_6 = ( void * ) F_13 ( V_10 | V_37 ) ;
if ( ! V_6 )
return - V_11 ;
V_6 -> V_38 . V_39 = sizeof( * V_6 ) ;
V_9 = F_4 ( V_40 , V_6 ,
V_41 ) ;
if ( V_9 )
goto V_18;
if ( V_6 -> V_38 . V_42 != 0x0010 ) {
F_9 ( L_3 ,
V_6 -> V_38 . V_42 ) ;
V_9 = - V_20 ;
goto V_18;
}
F_11 ( V_22 , V_6 ) ;
V_18:
F_14 ( ( unsigned long ) V_6 ) ;
return V_9 ;
}
static int F_15 ( T_1 V_5 )
{
struct V_43 * V_6 ;
int V_9 ;
if ( ! V_44 )
return - V_36 ;
V_6 = F_5 ( sizeof( * V_6 ) , V_10 | V_37 ) ;
if ( ! V_6 )
return - V_11 ;
V_6 -> V_38 . V_39 = sizeof( * V_6 ) ;
V_9 = F_4 ( V_5 , V_6 , V_41 ) ;
if ( V_9 )
goto V_18;
switch ( V_6 -> V_38 . V_42 ) {
case 0x0020 :
case 0x0120 :
break;
default:
F_9 ( L_4
L_5 , V_5 ,
V_6 -> V_38 . V_42 ) ;
V_9 = - V_20 ;
break;
}
V_18:
F_10 ( V_6 ) ;
return V_9 ;
}
int F_16 ( T_2 V_32 )
{
return F_15 ( V_45 | V_32 << 8 ) ;
}
int F_17 ( T_2 V_32 )
{
return F_15 ( V_46 | V_32 << 8 ) ;
}
int F_18 ( unsigned long V_47 )
{
if ( ! V_48 )
return 0 ;
return F_19 ( V_47 ) >> F_20 ( V_48 ) ;
}
static unsigned long long F_21 ( T_3 V_49 )
{
return ( unsigned long long ) ( V_49 - 1 ) * V_48 ;
}
static int F_22 ( T_1 V_5 , T_3 V_49 )
{
struct V_50 * V_6 ;
int V_9 ;
V_6 = ( void * ) F_13 ( V_10 | V_37 ) ;
if ( ! V_6 )
return - V_11 ;
V_6 -> V_38 . V_39 = V_51 ;
V_6 -> V_49 = V_49 ;
V_9 = F_4 ( V_5 , V_6 , V_41 ) ;
if ( V_9 )
goto V_18;
switch ( V_6 -> V_38 . V_42 ) {
case 0x0020 :
case 0x0120 :
break;
default:
F_9 ( L_6
L_7 , V_5 ,
V_6 -> V_38 . V_42 , V_49 ) ;
V_9 = - V_20 ;
break;
}
V_18:
F_14 ( ( unsigned long ) V_6 ) ;
return V_9 ;
}
static int F_23 ( T_3 V_49 )
{
unsigned long long V_52 ;
int V_9 ;
V_9 = F_22 ( 0x000d0001 , V_49 ) ;
if ( V_9 )
return V_9 ;
V_52 = F_21 ( V_49 ) ;
F_24 ( V_52 , V_52 + V_48 ) ;
return 0 ;
}
static int F_25 ( T_3 V_49 )
{
return F_22 ( 0x000c0001 , V_49 ) ;
}
static int F_26 ( T_2 V_53 )
{
struct V_54 * V_6 ;
int V_9 ;
int V_55 ;
V_6 = ( void * ) F_13 ( V_10 | V_37 ) ;
if ( ! V_6 )
return - V_11 ;
V_6 -> V_38 . V_39 = V_51 ;
V_9 = F_4 ( 0x00080001 | V_53 << 8 , V_6 ,
V_41 ) ;
if ( V_9 )
goto V_18;
switch ( V_6 -> V_38 . V_42 ) {
case 0x0020 :
F_27 ( V_53 , V_56 ) ;
for ( V_55 = 0 ; V_55 < V_6 -> V_57 ; V_55 ++ ) {
if ( V_6 -> V_58 [ V_55 ] )
F_25 ( V_6 -> V_58 [ V_55 ] >> 16 ) ;
}
break;
default:
V_9 = - V_20 ;
break;
}
V_18:
F_14 ( ( unsigned long ) V_6 ) ;
return V_9 ;
}
static int F_28 ( unsigned long V_52 , unsigned long V_59 ,
int V_60 )
{
struct V_61 * V_62 ;
unsigned long long V_63 ;
int V_9 = 0 ;
F_29 (incr, &sclp_mem_list, list) {
V_63 = F_21 ( V_62 -> V_49 ) ;
if ( V_52 + V_59 - 1 < V_63 )
break;
if ( V_52 > V_63 + V_48 - 1 )
continue;
if ( V_60 )
V_9 |= F_23 ( V_62 -> V_49 ) ;
else
F_25 ( V_62 -> V_49 ) ;
}
return V_9 ? - V_20 : 0 ;
}
static int F_30 ( struct V_64 * V_65 ,
unsigned long V_66 , void * V_3 )
{
unsigned long V_52 , V_59 ;
struct V_67 * V_68 ;
unsigned char V_53 ;
int V_9 = 0 ;
V_68 = V_3 ;
V_52 = V_68 -> V_47 << V_69 ;
V_59 = V_68 -> V_70 << V_69 ;
F_31 ( & V_71 ) ;
F_32 (id, sclp_storage_ids, sclp_max_storage_id + 1 )
F_26 ( V_53 ) ;
switch ( V_66 ) {
case V_72 :
case V_73 :
case V_74 :
break;
case V_75 :
V_9 = F_28 ( V_52 , V_59 , 1 ) ;
break;
case V_76 :
F_28 ( V_52 , V_59 , 0 ) ;
break;
case V_77 :
F_28 ( V_52 , V_59 , 0 ) ;
break;
default:
V_9 = - V_78 ;
break;
}
if ( ! V_9 )
V_79 = 1 ;
F_33 ( & V_71 ) ;
return V_9 ? V_80 : V_81 ;
}
static void T_4 F_34 ( T_3 V_49 )
{
static T_3 V_82 , V_83 ;
unsigned long long V_52 , V_59 ;
if ( V_49 && V_82 && ( V_82 + V_83 == V_49 ) ) {
V_83 ++ ;
return;
}
if ( ! V_82 )
goto V_84;
V_52 = F_21 ( V_82 ) ;
V_59 = ( unsigned long long ) V_83 * V_48 ;
if ( V_52 >= V_85 )
goto V_84;
if ( V_52 + V_59 > V_85 )
V_59 = V_85 - V_52 ;
if ( V_86 && ( V_52 >= V_87 ) )
goto V_84;
if ( V_86 && ( V_52 + V_59 > V_87 ) )
V_59 = V_87 - V_52 ;
F_35 ( 0 , V_52 , V_59 ) ;
V_84:
V_82 = V_49 ;
V_83 = 1 ;
}
static void T_4 F_36 ( void )
{
struct V_61 * V_62 ;
F_29 (incr, &sclp_mem_list, list)
if ( V_62 -> V_27 )
F_34 ( V_62 -> V_49 ) ;
F_34 ( 0 ) ;
}
static void T_4 F_37 ( T_3 V_49 , int V_27 , int V_57 )
{
struct V_61 * V_62 , * V_88 ;
struct V_89 * V_90 ;
T_3 V_91 ;
V_88 = F_5 ( sizeof( * V_88 ) , V_10 ) ;
if ( ! V_88 )
return;
V_88 -> V_49 = V_49 ;
V_88 -> V_27 = V_27 ;
V_91 = 0 ;
V_90 = & V_92 ;
F_29 (incr, &sclp_mem_list, list) {
if ( V_57 && V_62 -> V_49 > V_49 )
break;
if ( ! V_57 && V_62 -> V_49 - V_91 > 1 )
break;
V_91 = V_62 -> V_49 ;
V_90 = & V_62 -> V_93 ;
}
if ( ! V_57 )
V_88 -> V_49 = V_91 + 1 ;
if ( V_88 -> V_49 > V_94 ) {
F_10 ( V_88 ) ;
return;
}
F_38 ( & V_88 -> V_93 , V_90 ) ;
}
static int F_39 ( struct V_95 * V_96 )
{
if ( ! V_79 )
return 0 ;
F_40 ( L_8 ) ;
return - V_97 ;
}
static int T_4 F_41 ( void )
{
struct V_98 * V_99 ;
struct V_100 * V_6 ;
int V_55 , V_53 , V_57 , V_9 ;
if ( V_101 )
return 0 ;
if ( ( V_102 & 0xe00000000000ULL ) != 0xe00000000000ULL )
return 0 ;
V_9 = - V_11 ;
V_6 = ( void * ) F_42 ( V_10 | V_37 ) ;
if ( ! V_6 )
goto V_18;
V_57 = 0 ;
for ( V_53 = 0 ; V_53 <= V_103 ; V_53 ++ ) {
memset ( V_6 , 0 , V_51 ) ;
V_6 -> V_38 . V_39 = V_51 ;
V_9 = F_3 ( 0x00040001 | V_53 << 8 , V_6 ) ;
if ( V_9 )
goto V_18;
switch ( V_6 -> V_38 . V_42 ) {
case 0x0010 :
F_27 ( V_53 , V_56 ) ;
for ( V_55 = 0 ; V_55 < V_6 -> V_57 ; V_55 ++ ) {
if ( ! V_6 -> V_58 [ V_55 ] )
continue;
V_57 ++ ;
F_37 ( V_6 -> V_58 [ V_55 ] >> 16 , 0 , 1 ) ;
}
break;
case 0x0310 :
break;
case 0x0410 :
for ( V_55 = 0 ; V_55 < V_6 -> V_57 ; V_55 ++ ) {
if ( ! V_6 -> V_58 [ V_55 ] )
continue;
V_57 ++ ;
F_37 ( V_6 -> V_58 [ V_55 ] >> 16 , 1 , 1 ) ;
}
break;
default:
V_9 = - V_20 ;
break;
}
if ( ! V_9 )
V_103 = V_6 -> V_104 ;
}
if ( V_9 || F_43 ( & V_92 ) )
goto V_18;
for ( V_55 = 1 ; V_55 <= V_94 - V_57 ; V_55 ++ )
F_37 ( 0 , 1 , 0 ) ;
V_9 = F_44 ( & V_105 ) ;
if ( V_9 )
goto V_18;
V_9 = F_45 ( & V_106 ) ;
if ( V_9 )
goto V_18;
V_99 = F_46 ( L_9 , - 1 , NULL , 0 ) ;
V_9 = F_47 ( V_99 ) ;
if ( V_9 )
goto V_107;
F_36 () ;
goto V_18;
V_107:
F_48 ( & V_106 ) ;
V_18:
F_14 ( ( unsigned long ) V_6 ) ;
return V_9 ;
}
static int F_49 ( T_1 V_5 , T_5 V_108 )
{
struct V_109 * V_6 ;
int V_9 ;
if ( ! V_110 )
return - V_36 ;
V_6 = (struct V_109 * ) F_13 ( V_10 | V_37 ) ;
if ( ! V_6 )
return - V_11 ;
V_6 -> V_38 . V_39 = V_51 ;
V_6 -> V_111 = V_112 ;
V_6 -> V_113 = V_108 ;
V_9 = F_3 ( V_5 , V_6 ) ;
if ( V_9 )
goto V_18;
switch ( V_6 -> V_38 . V_42 ) {
case 0x0020 :
case 0x0120 :
break;
default:
F_50 ( L_10 ,
V_5 , V_6 -> V_38 . V_42 ) ;
V_9 = - V_20 ;
break;
}
V_18:
F_14 ( ( unsigned long ) V_6 ) ;
return V_9 ;
}
int F_51 ( T_5 V_108 )
{
return F_49 ( V_114 , V_108 ) ;
}
int F_52 ( T_5 V_108 )
{
return F_49 ( V_115 , V_108 ) ;
}
static int F_53 ( T_1 V_5 )
{
struct V_116 * V_6 ;
int V_9 ;
if ( ! V_117 )
return - V_36 ;
V_6 = (struct V_116 * ) F_13 ( V_10 | V_37 ) ;
if ( ! V_6 )
return - V_11 ;
V_6 -> V_38 . V_39 = sizeof( * V_6 ) ;
V_9 = F_3 ( V_5 , V_6 ) ;
if ( V_9 )
goto V_18;
switch ( V_6 -> V_38 . V_42 ) {
case 0x0020 :
case 0x0120 :
case 0x0440 :
case 0x0450 :
break;
default:
F_9 ( L_11
L_12 , V_5 ,
V_6 -> V_38 . V_42 ) ;
V_9 = - V_20 ;
break;
}
V_18:
F_14 ( ( unsigned long ) V_6 ) ;
return V_9 ;
}
int F_54 ( struct V_118 V_119 )
{
return F_53 ( V_120 | V_119 . V_53 << 8 ) ;
}
int F_55 ( struct V_118 V_119 )
{
return F_53 ( V_121 | V_119 . V_53 << 8 ) ;
}
int F_56 ( struct V_122 * V_22 )
{
struct V_123 * V_6 ;
int V_9 ;
if ( ! V_124 )
return - V_36 ;
V_6 = (struct V_123 * ) F_13 ( V_10 | V_37 ) ;
if ( ! V_6 )
return - V_11 ;
V_6 -> V_38 . V_39 = sizeof( * V_6 ) ;
V_9 = F_3 ( V_125 , V_6 ) ;
if ( V_9 )
goto V_18;
if ( V_6 -> V_38 . V_42 != 0x0010 ) {
F_9 ( L_13
L_14 , V_6 -> V_38 . V_42 ) ;
V_9 = - V_20 ;
goto V_18;
}
memcpy ( V_22 -> V_126 , V_6 -> V_126 , V_127 ) ;
memcpy ( V_22 -> V_27 , V_6 -> V_27 , V_127 ) ;
memcpy ( V_22 -> V_25 , V_6 -> V_25 , V_127 ) ;
V_18:
F_14 ( ( unsigned long ) V_6 ) ;
return V_9 ;
}
bool F_57 ( void )
{
return ! ! ( V_31 & 0x2 ) ;
}
