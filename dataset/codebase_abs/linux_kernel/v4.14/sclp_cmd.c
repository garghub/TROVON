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
V_6 -> V_27 . V_47 = 0x40 ;
V_9 = F_4 ( 0x00080001 | V_44 << 8 , V_6 ,
V_30 ) ;
if ( V_9 )
goto V_18;
switch ( V_6 -> V_27 . V_31 ) {
case 0x0020 :
F_27 ( V_44 , V_48 ) ;
for ( V_46 = 0 ; V_46 < V_6 -> V_49 ; V_46 ++ ) {
if ( V_6 -> V_50 [ V_46 ] )
F_25 ( V_6 -> V_50 [ V_46 ] >> 16 ) ;
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
static int F_28 ( unsigned long V_43 , unsigned long V_51 ,
int V_52 )
{
struct V_53 * V_54 ;
unsigned long long V_55 ;
int V_9 = 0 ;
F_29 (incr, &sclp_mem_list, list) {
V_55 = F_21 ( V_54 -> V_40 ) ;
if ( V_43 + V_51 - 1 < V_55 )
break;
if ( V_43 > V_55 + V_38 . V_39 - 1 )
continue;
if ( V_52 )
V_9 |= F_23 ( V_54 -> V_40 ) ;
else
F_25 ( V_54 -> V_40 ) ;
if ( V_9 == 0 )
V_54 -> V_56 = V_52 ? 0 : 1 ;
}
return V_9 ? - V_20 : 0 ;
}
static bool F_30 ( unsigned long V_43 , unsigned long V_57 )
{
struct V_53 * V_54 ;
unsigned long V_55 ;
F_29 (incr, &sclp_mem_list, list) {
V_55 = F_21 ( V_54 -> V_40 ) ;
if ( V_57 - 1 < V_55 )
continue;
if ( V_43 > V_55 + V_38 . V_39 - 1 )
continue;
if ( V_54 -> V_56 )
return true ;
}
return false ;
}
static int F_31 ( struct V_58 * V_59 ,
unsigned long V_60 , void * V_3 )
{
unsigned long V_43 , V_51 ;
struct V_61 * V_62 ;
unsigned char V_44 ;
int V_9 = 0 ;
V_62 = V_3 ;
V_43 = V_62 -> V_37 << V_63 ;
V_51 = V_62 -> V_64 << V_63 ;
F_32 ( & V_65 ) ;
F_33 (id, sclp_storage_ids, sclp_max_storage_id + 1 )
F_26 ( V_44 ) ;
switch ( V_60 ) {
case V_66 :
if ( F_30 ( V_43 , V_43 + V_51 ) )
V_9 = - V_67 ;
break;
case V_68 :
case V_69 :
break;
case V_70 :
V_9 = F_28 ( V_43 , V_51 , 1 ) ;
break;
case V_71 :
F_28 ( V_43 , V_51 , 0 ) ;
break;
case V_72 :
F_28 ( V_43 , V_51 , 0 ) ;
break;
default:
V_9 = - V_73 ;
break;
}
if ( ! V_9 )
V_74 = 1 ;
F_34 ( & V_65 ) ;
return V_9 ? V_75 : V_76 ;
}
static void T_4 F_35 ( unsigned long long * V_43 ,
unsigned long long * V_51 ,
unsigned long long V_77 )
{
unsigned long long V_78 , V_79 ;
V_78 = F_36 ( * V_43 , V_77 ) ;
V_79 = F_37 ( * V_43 + * V_51 , V_77 ) - V_78 ;
F_38 ( L_5 ,
* V_43 , V_79 >> 20 , * V_51 >> 20 ) ;
* V_43 = V_78 ;
* V_51 = V_79 ;
}
static void T_4 F_39 ( T_3 V_40 )
{
unsigned long long V_43 , V_51 , V_80 , V_81 ;
static T_3 V_82 , V_83 ;
if ( V_40 && V_82 && ( V_82 + V_83 == V_40 ) ) {
V_83 ++ ;
return;
}
if ( ! V_82 )
goto V_84;
V_43 = F_21 ( V_82 ) ;
V_51 = ( unsigned long long ) V_83 * V_38 . V_39 ;
if ( V_43 >= V_85 )
goto V_84;
if ( V_43 + V_51 > V_85 )
V_51 = V_85 - V_43 ;
if ( V_86 && ( V_43 >= V_87 ) )
goto V_84;
if ( V_86 && ( V_43 + V_51 > V_87 ) )
V_51 = V_87 - V_43 ;
V_81 = F_40 () ;
F_35 ( & V_43 , & V_51 , V_81 ) ;
if ( ! V_51 )
goto V_84;
for ( V_80 = V_43 ; V_80 < V_43 + V_51 ; V_80 += V_81 )
F_41 ( F_42 ( F_43 ( V_80 ) ) , V_80 , V_81 ) ;
V_84:
V_82 = V_40 ;
V_83 = 1 ;
}
static void T_4 F_44 ( void )
{
struct V_53 * V_54 ;
F_29 (incr, &sclp_mem_list, list)
if ( V_54 -> V_56 )
F_39 ( V_54 -> V_40 ) ;
F_39 ( 0 ) ;
}
static void T_4 F_45 ( T_3 V_40 , int V_56 , int V_49 )
{
struct V_53 * V_54 , * V_88 ;
struct V_89 * V_90 ;
T_3 V_91 ;
V_88 = F_5 ( sizeof( * V_88 ) , V_10 ) ;
if ( ! V_88 )
return;
V_88 -> V_40 = V_40 ;
V_88 -> V_56 = V_56 ;
V_91 = 0 ;
V_90 = & V_92 ;
F_29 (incr, &sclp_mem_list, list) {
if ( V_49 && V_54 -> V_40 > V_40 )
break;
if ( ! V_49 && V_54 -> V_40 - V_91 > 1 )
break;
V_91 = V_54 -> V_40 ;
V_90 = & V_54 -> V_93 ;
}
if ( ! V_49 )
V_88 -> V_40 = V_91 + 1 ;
if ( V_88 -> V_40 > V_38 . V_94 ) {
F_10 ( V_88 ) ;
return;
}
F_46 ( & V_88 -> V_93 , V_90 ) ;
}
static int F_47 ( struct V_95 * V_96 )
{
if ( ! V_74 )
return 0 ;
F_48 ( L_6 ) ;
return - V_67 ;
}
static int T_4 F_49 ( void )
{
struct V_97 * V_98 ;
struct V_99 * V_6 ;
int V_46 , V_44 , V_49 , V_9 ;
if ( V_100 )
return 0 ;
if ( ( V_38 . V_101 & 0xe00000000000ULL ) != 0xe00000000000ULL )
return 0 ;
V_9 = - V_11 ;
V_6 = ( void * ) F_50 ( V_10 | V_26 ) ;
if ( ! V_6 )
goto V_18;
V_49 = 0 ;
for ( V_44 = 0 ; V_44 <= V_102 ; V_44 ++ ) {
memset ( V_6 , 0 , V_42 ) ;
V_6 -> V_27 . V_28 = V_42 ;
V_9 = F_3 ( 0x00040001 | V_44 << 8 , V_6 ) ;
if ( V_9 )
goto V_18;
switch ( V_6 -> V_27 . V_31 ) {
case 0x0010 :
F_27 ( V_44 , V_48 ) ;
for ( V_46 = 0 ; V_46 < V_6 -> V_49 ; V_46 ++ ) {
if ( ! V_6 -> V_50 [ V_46 ] )
continue;
V_49 ++ ;
F_45 ( V_6 -> V_50 [ V_46 ] >> 16 , 0 , 1 ) ;
}
break;
case 0x0310 :
break;
case 0x0410 :
for ( V_46 = 0 ; V_46 < V_6 -> V_49 ; V_46 ++ ) {
if ( ! V_6 -> V_50 [ V_46 ] )
continue;
V_49 ++ ;
F_45 ( V_6 -> V_50 [ V_46 ] >> 16 , 1 , 1 ) ;
}
break;
default:
V_9 = - V_20 ;
break;
}
if ( ! V_9 )
V_102 = V_6 -> V_103 ;
}
if ( V_9 || F_51 ( & V_92 ) )
goto V_18;
for ( V_46 = 1 ; V_46 <= V_38 . V_94 - V_49 ; V_46 ++ )
F_45 ( 0 , 1 , 0 ) ;
V_9 = F_52 ( & V_104 ) ;
if ( V_9 )
goto V_18;
V_9 = F_53 ( & V_105 ) ;
if ( V_9 )
goto V_18;
V_98 = F_54 ( L_7 , - 1 , NULL , 0 ) ;
V_9 = F_55 ( V_98 ) ;
if ( V_9 )
goto V_106;
F_44 () ;
goto V_18;
V_106:
F_56 ( & V_105 ) ;
V_18:
F_14 ( ( unsigned long ) V_6 ) ;
return V_9 ;
}
static int F_57 ( T_1 V_5 )
{
struct V_107 * V_6 ;
int V_9 ;
if ( ! V_108 )
return - V_25 ;
V_6 = (struct V_107 * ) F_12 ( V_10 | V_26 ) ;
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
int F_58 ( struct V_109 V_110 )
{
return F_57 ( V_111 | V_110 . V_44 << 8 ) ;
}
int F_59 ( struct V_109 V_110 )
{
return F_57 ( V_112 | V_110 . V_44 << 8 ) ;
}
int F_60 ( struct V_113 * V_22 )
{
struct V_114 * V_6 ;
int V_9 ;
if ( ! V_115 )
return - V_25 ;
V_6 = (struct V_114 * ) F_12 ( V_10 | V_26 ) ;
if ( ! V_6 )
return - V_11 ;
V_6 -> V_27 . V_28 = sizeof( * V_6 ) ;
V_9 = F_3 ( V_116 , V_6 ) ;
if ( V_9 )
goto V_18;
if ( V_6 -> V_27 . V_31 != 0x0010 ) {
F_9 ( L_9 ,
V_6 -> V_27 . V_31 ) ;
V_9 = - V_20 ;
goto V_18;
}
memcpy ( V_22 -> V_117 , V_6 -> V_117 , V_118 ) ;
memcpy ( V_22 -> V_56 , V_6 -> V_56 , V_118 ) ;
memcpy ( V_22 -> V_119 , V_6 -> V_119 , V_118 ) ;
V_18:
F_14 ( ( unsigned long ) V_6 ) ;
return V_9 ;
}
