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
F_9 ( L_1 ,
V_5 , V_8 -> V_14 ) ;
V_9 = - V_20 ;
}
V_18:
F_10 ( V_8 ) ;
return V_9 ;
}
int F_11 ( struct V_21 * V_22 )
{
int V_9 ;
struct V_23 * V_6 ;
if ( ! V_24 )
return - V_25 ;
V_6 = ( void * ) F_12 ( V_10 | V_26 ) ;
if ( ! V_6 )
return - V_11 ;
V_6 -> V_27 . V_28 = sizeof( * V_6 ) ;
V_9 = F_4 ( V_29 , V_6 ,
V_30 ) ;
if ( V_9 )
goto V_18;
if ( V_6 -> V_27 . V_31 != 0x0010 ) {
F_9 ( L_2 ,
V_6 -> V_27 . V_31 ) ;
V_9 = - V_20 ;
goto V_18;
}
F_13 ( V_22 , V_6 ) ;
V_18:
F_14 ( ( unsigned long ) V_6 ) ;
return V_9 ;
}
static int F_15 ( T_1 V_5 )
{
struct V_32 * V_6 ;
int V_9 ;
if ( ! V_33 )
return - V_25 ;
V_6 = F_5 ( sizeof( * V_6 ) , V_10 | V_26 ) ;
if ( ! V_6 )
return - V_11 ;
V_6 -> V_27 . V_28 = sizeof( * V_6 ) ;
V_9 = F_4 ( V_5 , V_6 , V_30 ) ;
if ( V_9 )
goto V_18;
switch ( V_6 -> V_27 . V_31 ) {
case 0x0020 :
case 0x0120 :
break;
default:
F_9 ( L_3 ,
V_5 , V_6 -> V_27 . V_31 ) ;
V_9 = - V_20 ;
break;
}
V_18:
F_10 ( V_6 ) ;
return V_9 ;
}
int F_16 ( T_2 V_34 )
{
return F_15 ( V_35 | V_34 << 8 ) ;
}
int F_17 ( T_2 V_34 )
{
return F_15 ( V_36 | V_34 << 8 ) ;
}
int F_18 ( unsigned long V_37 )
{
if ( ! V_38 . V_39 )
return 0 ;
return F_19 ( V_37 ) >> F_20 ( V_38 . V_39 ) ;
}
static unsigned long long F_21 ( T_3 V_40 )
{
return ( unsigned long long ) ( V_40 - 1 ) * V_38 . V_39 ;
}
static int F_22 ( T_1 V_5 , T_3 V_40 )
{
struct V_41 * V_6 ;
int V_9 ;
V_6 = ( void * ) F_12 ( V_10 | V_26 ) ;
if ( ! V_6 )
return - V_11 ;
V_6 -> V_27 . V_28 = V_42 ;
V_6 -> V_40 = V_40 ;
V_9 = F_4 ( V_5 , V_6 , V_30 ) ;
if ( V_9 )
goto V_18;
switch ( V_6 -> V_27 . V_31 ) {
case 0x0020 :
case 0x0120 :
break;
default:
F_9 ( L_4 ,
V_5 , V_6 -> V_27 . V_31 , V_40 ) ;
V_9 = - V_20 ;
break;
}
V_18:
F_14 ( ( unsigned long ) V_6 ) ;
return V_9 ;
}
static int F_23 ( T_3 V_40 )
{
unsigned long long V_43 ;
int V_9 ;
V_9 = F_22 ( 0x000d0001 , V_40 ) ;
if ( V_9 )
return V_9 ;
V_43 = F_21 ( V_40 ) ;
F_24 ( V_43 , V_43 + V_38 . V_39 ) ;
return 0 ;
}
static int F_25 ( T_3 V_40 )
{
return F_22 ( 0x000c0001 , V_40 ) ;
}
static int F_26 ( T_2 V_44 )
{
struct V_45 * V_6 ;
int V_9 ;
int V_46 ;
V_6 = ( void * ) F_12 ( V_10 | V_26 ) ;
if ( ! V_6 )
return - V_11 ;
V_6 -> V_27 . V_28 = V_42 ;
V_9 = F_4 ( 0x00080001 | V_44 << 8 , V_6 ,
V_30 ) ;
if ( V_9 )
goto V_18;
switch ( V_6 -> V_27 . V_31 ) {
case 0x0020 :
F_27 ( V_44 , V_47 ) ;
for ( V_46 = 0 ; V_46 < V_6 -> V_48 ; V_46 ++ ) {
if ( V_6 -> V_49 [ V_46 ] )
F_25 ( V_6 -> V_49 [ V_46 ] >> 16 ) ;
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
static int F_28 ( unsigned long V_43 , unsigned long V_50 ,
int V_51 )
{
struct V_52 * V_53 ;
unsigned long long V_54 ;
int V_9 = 0 ;
F_29 (incr, &sclp_mem_list, list) {
V_54 = F_21 ( V_53 -> V_40 ) ;
if ( V_43 + V_50 - 1 < V_54 )
break;
if ( V_43 > V_54 + V_38 . V_39 - 1 )
continue;
if ( V_51 )
V_9 |= F_23 ( V_53 -> V_40 ) ;
else
F_25 ( V_53 -> V_40 ) ;
if ( V_9 == 0 )
V_53 -> V_55 = V_51 ? 0 : 1 ;
}
return V_9 ? - V_20 : 0 ;
}
static bool F_30 ( unsigned long V_43 , unsigned long V_56 )
{
struct V_52 * V_53 ;
unsigned long V_54 ;
F_29 (incr, &sclp_mem_list, list) {
V_54 = F_21 ( V_53 -> V_40 ) ;
if ( V_56 - 1 < V_54 )
continue;
if ( V_43 > V_54 + V_38 . V_39 - 1 )
continue;
if ( V_53 -> V_55 )
return true ;
}
return false ;
}
static int F_31 ( struct V_57 * V_58 ,
unsigned long V_59 , void * V_3 )
{
unsigned long V_43 , V_50 ;
struct V_60 * V_61 ;
unsigned char V_44 ;
int V_9 = 0 ;
V_61 = V_3 ;
V_43 = V_61 -> V_37 << V_62 ;
V_50 = V_61 -> V_63 << V_62 ;
F_32 ( & V_64 ) ;
F_33 (id, sclp_storage_ids, sclp_max_storage_id + 1 )
F_26 ( V_44 ) ;
switch ( V_59 ) {
case V_65 :
if ( F_30 ( V_43 , V_43 + V_50 ) )
V_9 = - V_66 ;
break;
case V_67 :
case V_68 :
break;
case V_69 :
V_9 = F_28 ( V_43 , V_50 , 1 ) ;
break;
case V_70 :
F_28 ( V_43 , V_50 , 0 ) ;
break;
case V_71 :
F_28 ( V_43 , V_50 , 0 ) ;
break;
default:
V_9 = - V_72 ;
break;
}
if ( ! V_9 )
V_73 = 1 ;
F_34 ( & V_64 ) ;
return V_9 ? V_74 : V_75 ;
}
static void T_4 F_35 ( unsigned long long * V_43 ,
unsigned long long * V_50 ,
unsigned long long V_76 )
{
unsigned long long V_77 , V_78 ;
V_77 = F_36 ( * V_43 , V_76 ) ;
V_78 = F_37 ( * V_43 + * V_50 , V_76 ) - V_77 ;
F_38 ( L_5 ,
* V_43 , V_78 >> 20 , * V_50 >> 20 ) ;
* V_43 = V_77 ;
* V_50 = V_78 ;
}
static void T_4 F_39 ( T_3 V_40 )
{
unsigned long long V_43 , V_50 , V_79 , V_80 ;
static T_3 V_81 , V_82 ;
if ( V_40 && V_81 && ( V_81 + V_82 == V_40 ) ) {
V_82 ++ ;
return;
}
if ( ! V_81 )
goto V_83;
V_43 = F_21 ( V_81 ) ;
V_50 = ( unsigned long long ) V_82 * V_38 . V_39 ;
if ( V_43 >= V_84 )
goto V_83;
if ( V_43 + V_50 > V_84 )
V_50 = V_84 - V_43 ;
if ( V_85 && ( V_43 >= V_86 ) )
goto V_83;
if ( V_85 && ( V_43 + V_50 > V_86 ) )
V_50 = V_86 - V_43 ;
V_80 = F_40 () ;
F_35 ( & V_43 , & V_50 , V_80 ) ;
if ( ! V_50 )
goto V_83;
for ( V_79 = V_43 ; V_79 < V_43 + V_50 ; V_79 += V_80 )
F_41 ( F_42 ( F_43 ( V_79 ) ) , V_79 , V_80 ) ;
V_83:
V_81 = V_40 ;
V_82 = 1 ;
}
static void T_4 F_44 ( void )
{
struct V_52 * V_53 ;
F_29 (incr, &sclp_mem_list, list)
if ( V_53 -> V_55 )
F_39 ( V_53 -> V_40 ) ;
F_39 ( 0 ) ;
}
static void T_4 F_45 ( T_3 V_40 , int V_55 , int V_48 )
{
struct V_52 * V_53 , * V_87 ;
struct V_88 * V_89 ;
T_3 V_90 ;
V_87 = F_5 ( sizeof( * V_87 ) , V_10 ) ;
if ( ! V_87 )
return;
V_87 -> V_40 = V_40 ;
V_87 -> V_55 = V_55 ;
V_90 = 0 ;
V_89 = & V_91 ;
F_29 (incr, &sclp_mem_list, list) {
if ( V_48 && V_53 -> V_40 > V_40 )
break;
if ( ! V_48 && V_53 -> V_40 - V_90 > 1 )
break;
V_90 = V_53 -> V_40 ;
V_89 = & V_53 -> V_92 ;
}
if ( ! V_48 )
V_87 -> V_40 = V_90 + 1 ;
if ( V_87 -> V_40 > V_38 . V_93 ) {
F_10 ( V_87 ) ;
return;
}
F_46 ( & V_87 -> V_92 , V_89 ) ;
}
static int F_47 ( struct V_94 * V_95 )
{
if ( ! V_73 )
return 0 ;
F_48 ( L_6 ) ;
return - V_66 ;
}
static int T_4 F_49 ( void )
{
struct V_96 * V_97 ;
struct V_98 * V_6 ;
int V_46 , V_44 , V_48 , V_9 ;
if ( V_99 )
return 0 ;
if ( ( V_38 . V_100 & 0xe00000000000ULL ) != 0xe00000000000ULL )
return 0 ;
V_9 = - V_11 ;
V_6 = ( void * ) F_50 ( V_10 | V_26 ) ;
if ( ! V_6 )
goto V_18;
V_48 = 0 ;
for ( V_44 = 0 ; V_44 <= V_101 ; V_44 ++ ) {
memset ( V_6 , 0 , V_42 ) ;
V_6 -> V_27 . V_28 = V_42 ;
V_9 = F_3 ( 0x00040001 | V_44 << 8 , V_6 ) ;
if ( V_9 )
goto V_18;
switch ( V_6 -> V_27 . V_31 ) {
case 0x0010 :
F_27 ( V_44 , V_47 ) ;
for ( V_46 = 0 ; V_46 < V_6 -> V_48 ; V_46 ++ ) {
if ( ! V_6 -> V_49 [ V_46 ] )
continue;
V_48 ++ ;
F_45 ( V_6 -> V_49 [ V_46 ] >> 16 , 0 , 1 ) ;
}
break;
case 0x0310 :
break;
case 0x0410 :
for ( V_46 = 0 ; V_46 < V_6 -> V_48 ; V_46 ++ ) {
if ( ! V_6 -> V_49 [ V_46 ] )
continue;
V_48 ++ ;
F_45 ( V_6 -> V_49 [ V_46 ] >> 16 , 1 , 1 ) ;
}
break;
default:
V_9 = - V_20 ;
break;
}
if ( ! V_9 )
V_101 = V_6 -> V_102 ;
}
if ( V_9 || F_51 ( & V_91 ) )
goto V_18;
for ( V_46 = 1 ; V_46 <= V_38 . V_93 - V_48 ; V_46 ++ )
F_45 ( 0 , 1 , 0 ) ;
V_9 = F_52 ( & V_103 ) ;
if ( V_9 )
goto V_18;
V_9 = F_53 ( & V_104 ) ;
if ( V_9 )
goto V_18;
V_97 = F_54 ( L_7 , - 1 , NULL , 0 ) ;
V_9 = F_55 ( V_97 ) ;
if ( V_9 )
goto V_105;
F_44 () ;
goto V_18;
V_105:
F_56 ( & V_104 ) ;
V_18:
F_14 ( ( unsigned long ) V_6 ) ;
return V_9 ;
}
static int F_57 ( T_1 V_5 )
{
struct V_106 * V_6 ;
int V_9 ;
if ( ! V_107 )
return - V_25 ;
V_6 = (struct V_106 * ) F_12 ( V_10 | V_26 ) ;
if ( ! V_6 )
return - V_11 ;
V_6 -> V_27 . V_28 = sizeof( * V_6 ) ;
V_9 = F_3 ( V_5 , V_6 ) ;
if ( V_9 )
goto V_18;
switch ( V_6 -> V_27 . V_31 ) {
case 0x0020 :
case 0x0120 :
case 0x0440 :
case 0x0450 :
break;
default:
F_9 ( L_8 ,
V_5 , V_6 -> V_27 . V_31 ) ;
V_9 = - V_20 ;
break;
}
V_18:
F_14 ( ( unsigned long ) V_6 ) ;
return V_9 ;
}
int F_58 ( struct V_108 V_109 )
{
return F_57 ( V_110 | V_109 . V_44 << 8 ) ;
}
int F_59 ( struct V_108 V_109 )
{
return F_57 ( V_111 | V_109 . V_44 << 8 ) ;
}
int F_60 ( struct V_112 * V_22 )
{
struct V_113 * V_6 ;
int V_9 ;
if ( ! V_114 )
return - V_25 ;
V_6 = (struct V_113 * ) F_12 ( V_10 | V_26 ) ;
if ( ! V_6 )
return - V_11 ;
V_6 -> V_27 . V_28 = sizeof( * V_6 ) ;
V_9 = F_3 ( V_115 , V_6 ) ;
if ( V_9 )
goto V_18;
if ( V_6 -> V_27 . V_31 != 0x0010 ) {
F_9 ( L_9 ,
V_6 -> V_27 . V_31 ) ;
V_9 = - V_20 ;
goto V_18;
}
memcpy ( V_22 -> V_116 , V_6 -> V_116 , V_117 ) ;
memcpy ( V_22 -> V_55 , V_6 -> V_55 , V_117 ) ;
memcpy ( V_22 -> V_118 , V_6 -> V_118 , V_117 ) ;
V_18:
F_14 ( ( unsigned long ) V_6 ) ;
return V_9 ;
}
