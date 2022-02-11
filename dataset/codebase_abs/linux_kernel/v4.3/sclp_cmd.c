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
memcpy ( & V_22 -> V_30 , V_24 + V_6 -> V_31 ,
V_22 -> V_29 * sizeof( struct V_32 ) ) ;
}
int F_12 ( struct V_21 * V_22 )
{
int V_9 ;
struct V_23 * V_6 ;
if ( ! V_33 )
return - V_34 ;
V_6 = ( void * ) F_13 ( V_10 | V_35 ) ;
if ( ! V_6 )
return - V_11 ;
V_6 -> V_36 . V_37 = sizeof( * V_6 ) ;
V_9 = F_4 ( V_38 , V_6 ,
V_39 ) ;
if ( V_9 )
goto V_18;
if ( V_6 -> V_36 . V_40 != 0x0010 ) {
F_9 ( L_3 ,
V_6 -> V_36 . V_40 ) ;
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
struct V_41 * V_6 ;
int V_9 ;
if ( ! V_42 )
return - V_34 ;
V_6 = F_5 ( sizeof( * V_6 ) , V_10 | V_35 ) ;
if ( ! V_6 )
return - V_11 ;
V_6 -> V_36 . V_37 = sizeof( * V_6 ) ;
V_9 = F_4 ( V_5 , V_6 , V_39 ) ;
if ( V_9 )
goto V_18;
switch ( V_6 -> V_36 . V_40 ) {
case 0x0020 :
case 0x0120 :
break;
default:
F_9 ( L_4
L_5 , V_5 ,
V_6 -> V_36 . V_40 ) ;
V_9 = - V_20 ;
break;
}
V_18:
F_10 ( V_6 ) ;
return V_9 ;
}
int F_16 ( T_2 V_30 )
{
return F_15 ( V_43 | V_30 << 8 ) ;
}
int F_17 ( T_2 V_30 )
{
return F_15 ( V_44 | V_30 << 8 ) ;
}
int F_18 ( unsigned long V_45 )
{
if ( ! V_46 . V_47 )
return 0 ;
return F_19 ( V_45 ) >> F_20 ( V_46 . V_47 ) ;
}
static unsigned long long F_21 ( T_3 V_48 )
{
return ( unsigned long long ) ( V_48 - 1 ) * V_46 . V_47 ;
}
static int F_22 ( T_1 V_5 , T_3 V_48 )
{
struct V_49 * V_6 ;
int V_9 ;
V_6 = ( void * ) F_13 ( V_10 | V_35 ) ;
if ( ! V_6 )
return - V_11 ;
V_6 -> V_36 . V_37 = V_50 ;
V_6 -> V_48 = V_48 ;
V_9 = F_4 ( V_5 , V_6 , V_39 ) ;
if ( V_9 )
goto V_18;
switch ( V_6 -> V_36 . V_40 ) {
case 0x0020 :
case 0x0120 :
break;
default:
F_9 ( L_6
L_7 , V_5 ,
V_6 -> V_36 . V_40 , V_48 ) ;
V_9 = - V_20 ;
break;
}
V_18:
F_14 ( ( unsigned long ) V_6 ) ;
return V_9 ;
}
static int F_23 ( T_3 V_48 )
{
unsigned long long V_51 ;
int V_9 ;
V_9 = F_22 ( 0x000d0001 , V_48 ) ;
if ( V_9 )
return V_9 ;
V_51 = F_21 ( V_48 ) ;
F_24 ( V_51 , V_51 + V_46 . V_47 ) ;
return 0 ;
}
static int F_25 ( T_3 V_48 )
{
return F_22 ( 0x000c0001 , V_48 ) ;
}
static int F_26 ( T_2 V_52 )
{
struct V_53 * V_6 ;
int V_9 ;
int V_54 ;
V_6 = ( void * ) F_13 ( V_10 | V_35 ) ;
if ( ! V_6 )
return - V_11 ;
V_6 -> V_36 . V_37 = V_50 ;
V_9 = F_4 ( 0x00080001 | V_52 << 8 , V_6 ,
V_39 ) ;
if ( V_9 )
goto V_18;
switch ( V_6 -> V_36 . V_40 ) {
case 0x0020 :
F_27 ( V_52 , V_55 ) ;
for ( V_54 = 0 ; V_54 < V_6 -> V_56 ; V_54 ++ ) {
if ( V_6 -> V_57 [ V_54 ] )
F_25 ( V_6 -> V_57 [ V_54 ] >> 16 ) ;
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
static int F_28 ( unsigned long V_51 , unsigned long V_58 ,
int V_59 )
{
struct V_60 * V_61 ;
unsigned long long V_62 ;
int V_9 = 0 ;
F_29 (incr, &sclp_mem_list, list) {
V_62 = F_21 ( V_61 -> V_48 ) ;
if ( V_51 + V_58 - 1 < V_62 )
break;
if ( V_51 > V_62 + V_46 . V_47 - 1 )
continue;
if ( V_59 )
V_9 |= F_23 ( V_61 -> V_48 ) ;
else
F_25 ( V_61 -> V_48 ) ;
if ( V_9 == 0 )
V_61 -> V_27 = V_59 ? 0 : 1 ;
}
return V_9 ? - V_20 : 0 ;
}
static bool F_30 ( unsigned long V_51 , unsigned long V_63 )
{
struct V_60 * V_61 ;
unsigned long V_62 ;
F_29 (incr, &sclp_mem_list, list) {
V_62 = F_21 ( V_61 -> V_48 ) ;
if ( V_63 - 1 < V_62 )
continue;
if ( V_51 > V_62 + V_46 . V_47 - 1 )
continue;
if ( V_61 -> V_27 )
return true ;
}
return false ;
}
static int F_31 ( struct V_64 * V_65 ,
unsigned long V_66 , void * V_3 )
{
unsigned long V_51 , V_58 ;
struct V_67 * V_68 ;
unsigned char V_52 ;
int V_9 = 0 ;
V_68 = V_3 ;
V_51 = V_68 -> V_45 << V_69 ;
V_58 = V_68 -> V_70 << V_69 ;
F_32 ( & V_71 ) ;
F_33 (id, sclp_storage_ids, sclp_max_storage_id + 1 )
F_26 ( V_52 ) ;
switch ( V_66 ) {
case V_72 :
if ( F_30 ( V_51 , V_51 + V_58 ) )
V_9 = - V_73 ;
break;
case V_74 :
case V_75 :
break;
case V_76 :
V_9 = F_28 ( V_51 , V_58 , 1 ) ;
break;
case V_77 :
F_28 ( V_51 , V_58 , 0 ) ;
break;
case V_78 :
F_28 ( V_51 , V_58 , 0 ) ;
break;
default:
V_9 = - V_79 ;
break;
}
if ( ! V_9 )
V_80 = 1 ;
F_34 ( & V_71 ) ;
return V_9 ? V_81 : V_82 ;
}
static void T_4 F_35 ( unsigned long long * V_51 ,
unsigned long long * V_58 ,
unsigned long long V_83 )
{
unsigned long long V_84 , V_85 ;
V_84 = F_36 ( * V_51 , V_83 ) ;
V_85 = F_37 ( * V_51 + * V_58 , V_83 ) - V_84 ;
F_38 ( L_8 ,
* V_51 , V_85 >> 20 , * V_58 >> 20 ) ;
* V_51 = V_84 ;
* V_58 = V_85 ;
}
static void T_4 F_39 ( T_3 V_48 )
{
unsigned long long V_51 , V_58 , V_86 , V_87 ;
static T_3 V_88 , V_89 ;
if ( V_48 && V_88 && ( V_88 + V_89 == V_48 ) ) {
V_89 ++ ;
return;
}
if ( ! V_88 )
goto V_90;
V_51 = F_21 ( V_88 ) ;
V_58 = ( unsigned long long ) V_89 * V_46 . V_47 ;
if ( V_51 >= V_91 )
goto V_90;
if ( V_51 + V_58 > V_91 )
V_58 = V_91 - V_51 ;
if ( V_92 && ( V_51 >= V_93 ) )
goto V_90;
if ( V_92 && ( V_51 + V_58 > V_93 ) )
V_58 = V_93 - V_51 ;
V_87 = F_40 () ;
F_35 ( & V_51 , & V_58 , V_87 ) ;
if ( ! V_58 )
goto V_90;
for ( V_86 = V_51 ; V_86 < V_51 + V_58 ; V_86 += V_87 )
F_41 ( F_42 ( F_43 ( V_86 ) ) , V_86 , V_87 ) ;
V_90:
V_88 = V_48 ;
V_89 = 1 ;
}
static void T_4 F_44 ( void )
{
struct V_60 * V_61 ;
F_29 (incr, &sclp_mem_list, list)
if ( V_61 -> V_27 )
F_39 ( V_61 -> V_48 ) ;
F_39 ( 0 ) ;
}
static void T_4 F_45 ( T_3 V_48 , int V_27 , int V_56 )
{
struct V_60 * V_61 , * V_94 ;
struct V_95 * V_96 ;
T_3 V_97 ;
V_94 = F_5 ( sizeof( * V_94 ) , V_10 ) ;
if ( ! V_94 )
return;
V_94 -> V_48 = V_48 ;
V_94 -> V_27 = V_27 ;
V_97 = 0 ;
V_96 = & V_98 ;
F_29 (incr, &sclp_mem_list, list) {
if ( V_56 && V_61 -> V_48 > V_48 )
break;
if ( ! V_56 && V_61 -> V_48 - V_97 > 1 )
break;
V_97 = V_61 -> V_48 ;
V_96 = & V_61 -> V_99 ;
}
if ( ! V_56 )
V_94 -> V_48 = V_97 + 1 ;
if ( V_94 -> V_48 > V_46 . V_100 ) {
F_10 ( V_94 ) ;
return;
}
F_46 ( & V_94 -> V_99 , V_96 ) ;
}
static int F_47 ( struct V_101 * V_102 )
{
if ( ! V_80 )
return 0 ;
F_48 ( L_9 ) ;
return - V_73 ;
}
static int T_4 F_49 ( void )
{
struct V_103 * V_104 ;
struct V_105 * V_6 ;
int V_54 , V_52 , V_56 , V_9 ;
if ( V_106 )
return 0 ;
if ( ( V_46 . V_107 & 0xe00000000000ULL ) != 0xe00000000000ULL )
return 0 ;
V_9 = - V_11 ;
V_6 = ( void * ) F_50 ( V_10 | V_35 ) ;
if ( ! V_6 )
goto V_18;
V_56 = 0 ;
for ( V_52 = 0 ; V_52 <= V_108 ; V_52 ++ ) {
memset ( V_6 , 0 , V_50 ) ;
V_6 -> V_36 . V_37 = V_50 ;
V_9 = F_3 ( 0x00040001 | V_52 << 8 , V_6 ) ;
if ( V_9 )
goto V_18;
switch ( V_6 -> V_36 . V_40 ) {
case 0x0010 :
F_27 ( V_52 , V_55 ) ;
for ( V_54 = 0 ; V_54 < V_6 -> V_56 ; V_54 ++ ) {
if ( ! V_6 -> V_57 [ V_54 ] )
continue;
V_56 ++ ;
F_45 ( V_6 -> V_57 [ V_54 ] >> 16 , 0 , 1 ) ;
}
break;
case 0x0310 :
break;
case 0x0410 :
for ( V_54 = 0 ; V_54 < V_6 -> V_56 ; V_54 ++ ) {
if ( ! V_6 -> V_57 [ V_54 ] )
continue;
V_56 ++ ;
F_45 ( V_6 -> V_57 [ V_54 ] >> 16 , 1 , 1 ) ;
}
break;
default:
V_9 = - V_20 ;
break;
}
if ( ! V_9 )
V_108 = V_6 -> V_109 ;
}
if ( V_9 || F_51 ( & V_98 ) )
goto V_18;
for ( V_54 = 1 ; V_54 <= V_46 . V_100 - V_56 ; V_54 ++ )
F_45 ( 0 , 1 , 0 ) ;
V_9 = F_52 ( & V_110 ) ;
if ( V_9 )
goto V_18;
V_9 = F_53 ( & V_111 ) ;
if ( V_9 )
goto V_18;
V_104 = F_54 ( L_10 , - 1 , NULL , 0 ) ;
V_9 = F_55 ( V_104 ) ;
if ( V_9 )
goto V_112;
F_44 () ;
goto V_18;
V_112:
F_56 ( & V_111 ) ;
V_18:
F_14 ( ( unsigned long ) V_6 ) ;
return V_9 ;
}
static int F_57 ( T_1 V_5 , T_5 V_113 )
{
struct V_114 * V_6 ;
int V_9 ;
if ( ! V_115 )
return - V_34 ;
V_6 = (struct V_114 * ) F_13 ( V_10 | V_35 ) ;
if ( ! V_6 )
return - V_11 ;
V_6 -> V_36 . V_37 = V_50 ;
V_6 -> V_116 = V_117 ;
V_6 -> V_118 = V_113 ;
V_9 = F_3 ( V_5 , V_6 ) ;
if ( V_9 )
goto V_18;
switch ( V_6 -> V_36 . V_40 ) {
case 0x0020 :
case 0x0120 :
break;
default:
F_58 ( L_11 ,
V_5 , V_6 -> V_36 . V_40 ) ;
V_9 = - V_20 ;
break;
}
V_18:
F_14 ( ( unsigned long ) V_6 ) ;
return V_9 ;
}
int F_59 ( T_5 V_113 )
{
return F_57 ( V_119 , V_113 ) ;
}
int F_60 ( T_5 V_113 )
{
return F_57 ( V_120 , V_113 ) ;
}
static int F_61 ( T_1 V_5 )
{
struct V_121 * V_6 ;
int V_9 ;
if ( ! V_122 )
return - V_34 ;
V_6 = (struct V_121 * ) F_13 ( V_10 | V_35 ) ;
if ( ! V_6 )
return - V_11 ;
V_6 -> V_36 . V_37 = sizeof( * V_6 ) ;
V_9 = F_3 ( V_5 , V_6 ) ;
if ( V_9 )
goto V_18;
switch ( V_6 -> V_36 . V_40 ) {
case 0x0020 :
case 0x0120 :
case 0x0440 :
case 0x0450 :
break;
default:
F_9 ( L_12
L_13 , V_5 ,
V_6 -> V_36 . V_40 ) ;
V_9 = - V_20 ;
break;
}
V_18:
F_14 ( ( unsigned long ) V_6 ) ;
return V_9 ;
}
int F_62 ( struct V_123 V_124 )
{
return F_61 ( V_125 | V_124 . V_52 << 8 ) ;
}
int F_63 ( struct V_123 V_124 )
{
return F_61 ( V_126 | V_124 . V_52 << 8 ) ;
}
int F_64 ( struct V_127 * V_22 )
{
struct V_128 * V_6 ;
int V_9 ;
if ( ! V_129 )
return - V_34 ;
V_6 = (struct V_128 * ) F_13 ( V_10 | V_35 ) ;
if ( ! V_6 )
return - V_11 ;
V_6 -> V_36 . V_37 = sizeof( * V_6 ) ;
V_9 = F_3 ( V_130 , V_6 ) ;
if ( V_9 )
goto V_18;
if ( V_6 -> V_36 . V_40 != 0x0010 ) {
F_9 ( L_14
L_15 , V_6 -> V_36 . V_40 ) ;
V_9 = - V_20 ;
goto V_18;
}
memcpy ( V_22 -> V_131 , V_6 -> V_131 , V_132 ) ;
memcpy ( V_22 -> V_27 , V_6 -> V_27 , V_132 ) ;
memcpy ( V_22 -> V_25 , V_6 -> V_25 , V_132 ) ;
V_18:
F_14 ( ( unsigned long ) V_6 ) ;
return V_9 ;
}
