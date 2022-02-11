static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned long V_4 ;
F_2 ( & V_2 -> V_5 , V_4 ) ;
V_3 = F_3 ( & V_2 -> V_6 ) ;
F_4 ( & V_2 -> V_5 , V_4 ) ;
return ! V_3 ;
}
static void F_5 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
unsigned long V_4 ;
V_8 -> V_9 = V_10 ;
F_2 ( & V_2 -> V_5 , V_4 ) ;
F_6 ( & V_8 -> V_11 , & V_2 -> V_6 ) ;
F_4 ( & V_2 -> V_5 , V_4 ) ;
}
static int F_7 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_5 , V_4 ) ;
F_8 ( & V_8 -> V_11 ) ;
F_4 ( & V_2 -> V_5 , V_4 ) ;
return 0 ;
}
static void F_9 ( struct V_7 * V_8 , struct V_12 * V_13 )
{
unsigned long V_4 ;
F_2 ( & V_8 -> V_14 , V_4 ) ;
F_6 ( & V_13 -> V_15 , & V_8 -> V_15 ) ;
F_4 ( & V_8 -> V_14 , V_4 ) ;
}
static int F_10 ( struct V_7 * V_8 , struct V_12 * V_13 )
{
unsigned long V_4 ;
F_2 ( & V_8 -> V_14 , V_4 ) ;
F_8 ( & V_13 -> V_15 ) ;
F_4 ( & V_8 -> V_14 , V_4 ) ;
return 0 ;
}
static struct V_12 * F_11 ( struct V_7 * V_8 ,
unsigned long V_16 ,
unsigned int V_17 ,
void * * V_18 )
{
unsigned long V_4 ;
struct V_12 * V_13 ;
F_2 ( & V_8 -> V_14 , V_4 ) ;
F_12 (m, &cfile->pin_list, pin_list) {
if ( ( ( ( V_19 ) V_13 -> V_20 ) <= ( V_16 ) ) &&
( ( ( V_19 ) V_13 -> V_20 + V_13 -> V_17 ) >= ( V_16 + V_17 ) ) ) {
if ( V_18 )
* V_18 = V_13 -> V_21 +
( V_16 - ( V_19 ) V_13 -> V_20 ) ;
F_4 ( & V_8 -> V_14 , V_4 ) ;
return V_13 ;
}
}
F_4 ( & V_8 -> V_14 , V_4 ) ;
return NULL ;
}
static void F_13 ( struct V_7 * V_8 ,
struct V_12 * V_22 )
{
unsigned long V_4 ;
F_2 ( & V_8 -> V_23 , V_4 ) ;
F_6 ( & V_22 -> V_24 , & V_8 -> V_25 ) ;
F_4 ( & V_8 -> V_23 , V_4 ) ;
}
static void F_14 ( struct V_7 * V_8 ,
struct V_12 * V_22 )
{
unsigned long V_4 ;
F_2 ( & V_8 -> V_23 , V_4 ) ;
F_8 ( & V_22 -> V_24 ) ;
F_4 ( & V_8 -> V_23 , V_4 ) ;
}
static struct V_12 * F_15 ( struct V_7 * V_8 ,
unsigned long V_16 ,
unsigned int V_17 ,
T_1 * V_26 ,
void * * V_18 )
{
unsigned long V_4 ;
struct V_12 * V_13 ;
struct V_27 * V_27 = V_8 -> V_2 -> V_27 ;
F_2 ( & V_8 -> V_23 , V_4 ) ;
F_12 (m, &cfile->map_list, card_list) {
if ( ( ( ( V_19 ) V_13 -> V_20 ) <= ( V_16 ) ) &&
( ( ( V_19 ) V_13 -> V_20 + V_13 -> V_17 ) >= ( V_16 + V_17 ) ) ) {
if ( V_26 )
* V_26 = V_13 -> V_26 +
( V_16 - ( V_19 ) V_13 -> V_20 ) ;
if ( V_18 )
* V_18 = V_13 -> V_21 +
( V_16 - ( V_19 ) V_13 -> V_20 ) ;
F_4 ( & V_8 -> V_23 , V_4 ) ;
return V_13 ;
}
}
F_4 ( & V_8 -> V_23 , V_4 ) ;
F_16 ( & V_27 -> V_28 ,
L_1 ,
V_29 , V_16 , V_17 ) ;
return NULL ;
}
static void F_17 ( struct V_7 * V_8 )
{
int V_30 = 0 ;
struct V_31 * V_32 , * V_33 ;
struct V_12 * V_22 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_27 * V_27 = V_8 -> V_2 -> V_27 ;
F_18 (node, next, &cfile->map_list) {
V_22 = F_19 ( V_32 , struct V_12 , V_24 ) ;
F_20 ( & V_22 -> V_24 ) ;
F_16 ( & V_27 -> V_28 ,
L_2 ,
V_29 , V_30 ++ , V_22 -> V_20 ,
( unsigned long ) V_22 -> V_21 ,
( unsigned long ) V_22 -> V_26 ) ;
if ( V_22 -> type == V_34 ) {
F_21 ( V_2 , V_22 -> V_17 ,
V_22 -> V_21 ,
V_22 -> V_26 ) ;
F_22 ( V_22 ) ;
} else if ( V_22 -> type == V_35 ) {
F_23 ( V_2 , V_22 , NULL ) ;
}
}
}
static void F_24 ( struct V_7 * V_8 )
{
struct V_31 * V_32 , * V_33 ;
struct V_12 * V_22 ;
struct V_1 * V_2 = V_8 -> V_2 ;
F_18 (node, next, &cfile->pin_list) {
V_22 = F_19 ( V_32 , struct V_12 , V_15 ) ;
F_20 ( & V_22 -> V_15 ) ;
F_23 ( V_2 , V_22 , NULL ) ;
F_22 ( V_22 ) ;
}
}
static int F_25 ( struct V_1 * V_2 , int V_36 )
{
unsigned int V_37 = 0 ;
unsigned long V_4 ;
struct V_7 * V_8 ;
F_2 ( & V_2 -> V_5 , V_4 ) ;
F_12 (cfile, &cd->file_list, list) {
if ( V_8 -> V_38 )
F_26 ( & V_8 -> V_38 , V_36 , V_39 ) ;
V_37 ++ ;
}
F_4 ( & V_2 -> V_5 , V_4 ) ;
return V_37 ;
}
static int F_27 ( struct V_1 * V_2 , int V_36 )
{
unsigned int V_37 = 0 ;
unsigned long V_4 ;
struct V_7 * V_8 ;
F_2 ( & V_2 -> V_5 , V_4 ) ;
F_12 (cfile, &cd->file_list, list) {
F_28 ( V_36 , V_8 -> V_9 ) ;
V_37 ++ ;
}
F_4 ( & V_2 -> V_5 , V_4 ) ;
return V_37 ;
}
static int F_29 ( struct V_40 * V_40 , struct V_41 * V_42 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 ;
struct V_27 * V_27 ;
V_8 = F_30 ( sizeof( * V_8 ) , V_43 ) ;
if ( V_8 == NULL )
return - V_44 ;
V_2 = F_31 ( V_40 -> V_45 , struct V_1 , V_46 ) ;
V_27 = V_2 -> V_27 ;
V_8 -> V_2 = V_2 ;
V_8 -> V_42 = V_42 ;
V_8 -> V_47 = NULL ;
F_32 ( & V_8 -> V_23 ) ;
F_33 ( & V_8 -> V_25 ) ;
F_32 ( & V_8 -> V_14 ) ;
F_33 ( & V_8 -> V_15 ) ;
V_42 -> V_48 = V_8 ;
F_5 ( V_2 , V_8 ) ;
return 0 ;
}
static int F_34 ( int V_49 , struct V_41 * V_42 , int V_50 )
{
struct V_7 * V_51 = (struct V_7 * ) V_42 -> V_48 ;
return F_35 ( V_49 , V_42 , V_50 , & V_51 -> V_38 ) ;
}
static int F_36 ( struct V_40 * V_40 , struct V_41 * V_42 )
{
struct V_7 * V_8 = (struct V_7 * ) V_42 -> V_48 ;
struct V_1 * V_2 = V_8 -> V_2 ;
F_17 ( V_8 ) ;
F_24 ( V_8 ) ;
F_34 ( - 1 , V_42 , 0 ) ;
F_7 ( V_2 , V_8 ) ;
F_22 ( V_8 ) ;
return 0 ;
}
static void F_37 ( struct V_52 * V_53 )
{
}
static void F_38 ( struct V_52 * V_53 )
{
unsigned long V_54 = V_53 -> V_55 - V_53 -> V_56 ;
struct V_40 * V_40 = F_39 ( V_53 -> V_57 ) ;
struct V_12 * V_22 ;
struct V_1 * V_2 = F_31 ( V_40 -> V_45 , struct V_1 ,
V_46 ) ;
struct V_27 * V_27 = V_2 -> V_27 ;
T_1 V_58 = 0 ;
struct V_7 * V_8 = V_53 -> V_59 ;
V_22 = F_15 ( V_8 , V_53 -> V_56 , V_54 ,
& V_58 , NULL ) ;
if ( V_22 == NULL ) {
F_16 ( & V_27 -> V_28 ,
L_3 ,
V_29 , V_53 -> V_56 , V_53 -> V_60 << V_61 ,
V_54 ) ;
return;
}
F_14 ( V_8 , V_22 ) ;
F_21 ( V_2 , V_22 -> V_17 , V_22 -> V_21 ,
V_22 -> V_26 ) ;
F_22 ( V_22 ) ;
}
static int F_40 ( struct V_41 * V_42 , struct V_52 * V_53 )
{
int V_3 ;
unsigned long V_62 , V_54 = V_53 -> V_55 - V_53 -> V_56 ;
struct V_7 * V_8 = (struct V_7 * ) V_42 -> V_48 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_12 * V_22 ;
if ( V_54 == 0 )
return - V_63 ;
if ( F_41 ( V_54 ) > V_64 )
return - V_44 ;
V_22 = F_30 ( sizeof( struct V_12 ) , V_65 ) ;
if ( V_22 == NULL )
return - V_44 ;
F_42 ( V_22 , V_34 ) ;
V_22 -> V_20 = ( void * ) V_53 -> V_56 ;
V_22 -> V_17 = V_54 ;
V_22 -> V_66 = F_43 ( V_54 , V_67 ) ;
V_22 -> V_21 = F_44 ( V_2 , V_54 ,
& V_22 -> V_26 ) ;
if ( V_22 -> V_21 == NULL ) {
V_3 = - V_44 ;
goto V_68;
}
if ( F_45 ( V_69 ) && ( V_54 > sizeof( T_1 ) ) )
* ( T_1 * ) V_22 -> V_21 = V_22 -> V_26 ;
V_62 = F_46 ( V_22 -> V_21 ) >> V_61 ;
V_3 = F_47 ( V_53 ,
V_53 -> V_56 ,
V_62 ,
V_54 ,
V_53 -> V_70 ) ;
if ( V_3 != 0 ) {
V_3 = - V_71 ;
goto V_72;
}
V_53 -> V_59 = V_8 ;
V_53 -> V_73 = & V_74 ;
F_13 ( V_8 , V_22 ) ;
return 0 ;
V_72:
F_21 ( V_2 , V_22 -> V_17 ,
V_22 -> V_21 ,
V_22 -> V_26 ) ;
V_68:
F_22 ( V_22 ) ;
return V_3 ;
}
static int F_48 ( struct V_7 * V_8 ,
struct V_75 * V_76 )
{
int V_3 = 0 ;
int V_77 ;
T_1 V_26 ;
V_19 V_78 = 0 ;
T_2 V_79 = 0 ;
T_3 T_4 * V_80 ;
T_3 * V_81 ;
T_5 V_82 ;
T_3 V_83 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_41 * V_42 = V_8 -> V_42 ;
struct V_27 * V_27 = V_2 -> V_27 ;
if ( ( V_76 -> V_17 & 0x3 ) != 0 )
return - V_63 ;
if ( ( ( unsigned long ) ( V_76 -> V_84 ) & ~ V_85 ) != 0 )
return - V_63 ;
switch ( ( char ) V_76 -> V_86 ) {
case '0' :
V_83 = 0x14 ;
break;
case '1' :
V_83 = 0x1C ;
break;
case 'v' :
V_83 = 0x0C ;
break;
default:
return - V_63 ;
}
V_80 = ( T_3 T_4 * ) V_76 -> V_84 ;
V_81 = F_44 ( V_2 , V_87 , & V_26 ) ;
if ( V_81 == NULL )
return - V_44 ;
V_77 = V_76 -> V_17 / V_87 ;
while ( V_76 -> V_17 ) {
struct V_88 * V_89 ;
V_79 = F_49 ( T_2 , V_76 -> V_17 , V_87 ) ;
V_3 = F_50 ( V_81 , V_80 , V_79 ) ;
if ( V_3 ) {
V_3 = - V_71 ;
goto V_90;
}
V_82 = F_51 ( V_81 , V_79 , 0xffffffff ) ;
F_52 ( & V_27 -> V_28 ,
L_4 ,
V_29 , ( unsigned long ) V_26 , V_82 , V_79 ,
V_77 ) ;
V_89 = F_53 () ;
if ( V_89 == NULL ) {
V_3 = - V_44 ;
goto V_90;
}
V_89 -> V_91 = V_92 ;
V_89 -> V_83 = V_83 ;
if ( F_54 ( V_2 ) <= 0x2 ) {
* ( V_93 * ) & V_89 -> V_94 [ 0 ] = F_55 ( V_26 ) ;
* ( V_93 * ) & V_89 -> V_94 [ 8 ] = F_55 ( V_79 ) ;
* ( V_93 * ) & V_89 -> V_94 [ 16 ] = F_55 ( V_78 ) ;
* ( V_95 * ) & V_89 -> V_94 [ 24 ] = F_56 ( 0 ) ;
V_89 -> V_94 [ 24 ] = V_76 -> V_96 ;
* ( V_95 * ) & V_89 -> V_94 [ 28 ] = F_56 ( V_82 ) ;
* ( V_93 * ) & V_89 -> V_94 [ 88 ] = F_55 ( V_76 -> V_97 ) ;
* ( V_93 * ) & V_89 -> V_94 [ 96 ] = F_55 ( V_76 -> V_98 ) ;
V_89 -> V_99 = 32 ;
} else {
* ( V_93 * ) & V_89 -> V_100 [ 0 ] = F_55 ( V_26 ) ;
* ( V_95 * ) & V_89 -> V_100 [ 8 ] = F_56 ( V_79 ) ;
* ( V_95 * ) & V_89 -> V_100 [ 12 ] = F_56 ( 0 ) ;
* ( V_93 * ) & V_89 -> V_100 [ 16 ] = F_55 ( V_78 ) ;
* ( V_95 * ) & V_89 -> V_100 [ 24 ] = F_56 ( V_76 -> V_96 << 24 ) ;
* ( V_95 * ) & V_89 -> V_100 [ 28 ] = F_56 ( V_82 ) ;
* ( V_93 * ) & V_89 -> V_100 [ 80 ] = F_55 ( V_76 -> V_97 ) ;
* ( V_93 * ) & V_89 -> V_100 [ 88 ] = F_55 ( V_76 -> V_98 ) ;
V_89 -> V_101 = 0x4ULL << 44 ;
V_89 -> V_99 = 40 ;
}
V_89 -> V_102 = 8 ;
* ( V_19 * ) & V_89 -> V_103 [ 0 ] = 0ULL ;
V_3 = F_57 ( V_2 , V_89 , V_42 -> V_104 ) ;
V_76 -> V_105 = V_89 -> V_105 ;
V_76 -> V_106 = V_89 -> V_106 ;
V_76 -> V_107 = V_89 -> V_107 ;
if ( V_3 < 0 ) {
F_58 ( V_89 ) ;
goto V_90;
}
if ( V_89 -> V_105 != V_108 ) {
V_3 = - V_109 ;
F_58 ( V_89 ) ;
goto V_90;
}
V_76 -> V_17 -= V_79 ;
V_78 += V_79 ;
V_80 += V_79 ;
V_77 -- ;
F_58 ( V_89 ) ;
}
V_90:
F_21 ( V_2 , V_87 , V_81 , V_26 ) ;
return V_3 ;
}
static int F_59 ( struct V_7 * V_8 ,
struct V_75 * V_76 )
{
int V_3 , V_77 ;
T_1 V_26 ;
V_19 V_78 = 0 ;
T_2 V_79 = 0 ;
T_3 T_4 * V_80 ;
T_3 * V_81 ;
T_3 V_83 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_41 * V_42 = V_8 -> V_42 ;
struct V_27 * V_27 = V_2 -> V_27 ;
struct V_88 * V_91 ;
if ( ( V_76 -> V_17 & 0x3 ) != 0 )
return - V_63 ;
if ( ( ( unsigned long ) ( V_76 -> V_84 ) & ~ V_85 ) != 0 )
return - V_63 ;
switch ( ( char ) V_76 -> V_86 ) {
case '0' :
V_83 = 0x12 ;
break;
case '1' :
V_83 = 0x1A ;
break;
case 'v' :
V_83 = 0x0A ;
break;
default:
return - V_63 ;
}
V_80 = ( T_3 T_4 * ) V_76 -> V_84 ;
V_81 = F_44 ( V_2 , V_87 , & V_26 ) ;
if ( V_81 == NULL )
return - V_44 ;
V_77 = V_76 -> V_17 / V_87 ;
while ( V_76 -> V_17 ) {
V_79 = F_49 ( T_2 , V_76 -> V_17 , V_87 ) ;
F_52 ( & V_27 -> V_28 ,
L_5 ,
V_29 , ( unsigned long ) V_26 , V_79 ,
V_77 ) ;
V_91 = F_53 () ;
if ( V_91 == NULL ) {
V_3 = - V_44 ;
goto V_90;
}
V_91 -> V_91 = V_92 ;
V_91 -> V_83 = V_83 ;
if ( F_54 ( V_2 ) <= 0x2 ) {
* ( V_93 * ) & V_91 -> V_94 [ 0 ] = F_55 ( V_26 ) ;
* ( V_93 * ) & V_91 -> V_94 [ 8 ] = F_55 ( V_79 ) ;
* ( V_93 * ) & V_91 -> V_94 [ 16 ] = F_55 ( V_78 ) ;
* ( V_95 * ) & V_91 -> V_94 [ 24 ] = F_56 ( 0 ) ;
V_91 -> V_94 [ 24 ] = V_76 -> V_96 ;
* ( V_95 * ) & V_91 -> V_94 [ 28 ] = F_56 ( 0 ) ;
V_91 -> V_99 = 32 ;
} else {
* ( V_93 * ) & V_91 -> V_100 [ 0 ] = F_55 ( V_26 ) ;
* ( V_95 * ) & V_91 -> V_100 [ 8 ] = F_56 ( V_79 ) ;
* ( V_95 * ) & V_91 -> V_100 [ 12 ] = F_56 ( 0 ) ;
* ( V_93 * ) & V_91 -> V_100 [ 16 ] = F_55 ( V_78 ) ;
* ( V_95 * ) & V_91 -> V_100 [ 24 ] = F_56 ( V_76 -> V_96 << 24 ) ;
* ( V_95 * ) & V_91 -> V_100 [ 28 ] = F_56 ( 0 ) ;
V_91 -> V_101 = 0x5ULL << 44 ;
V_91 -> V_99 = 40 ;
}
V_91 -> V_102 = 8 ;
* ( V_19 * ) & V_91 -> V_103 [ 0 ] = 0ULL ;
V_3 = F_57 ( V_2 , V_91 , V_42 -> V_104 ) ;
V_76 -> V_105 = V_91 -> V_105 ;
V_76 -> V_106 = V_91 -> V_106 ;
V_76 -> V_107 = V_91 -> V_107 ;
if ( ( V_3 < 0 ) && ( V_3 != - V_110 ) ) {
F_58 ( V_91 ) ;
goto V_90;
}
V_3 = F_60 ( V_80 , V_81 , V_79 ) ;
if ( V_3 ) {
V_3 = - V_71 ;
F_58 ( V_91 ) ;
goto V_90;
}
if ( ( ( V_91 -> V_105 == V_111 ) &&
( V_91 -> V_106 != 0x02 ) ) ||
( ( V_91 -> V_105 == V_108 ) &&
( V_91 -> V_106 != 0x00 ) ) ) {
V_3 = - V_109 ;
F_58 ( V_91 ) ;
goto V_90;
}
V_76 -> V_17 -= V_79 ;
V_78 += V_79 ;
V_80 += V_79 ;
V_77 -- ;
F_58 ( V_91 ) ;
}
V_3 = 0 ;
V_90:
F_21 ( V_2 , V_87 , V_81 , V_26 ) ;
return V_3 ;
}
static int F_61 ( struct V_7 * V_8 , struct V_112 * V_13 )
{
int V_3 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_27 * V_27 = V_8 -> V_2 -> V_27 ;
struct V_12 * V_22 ;
unsigned long V_113 ;
unsigned long V_114 ;
if ( ( V_13 -> V_115 == 0x0 ) || ( V_13 -> V_17 == 0 ) )
return - V_63 ;
V_113 = ( V_13 -> V_115 & V_85 ) ;
V_114 = F_62 ( V_13 -> V_17 + ( V_13 -> V_115 & ~ V_85 ) , V_67 ) ;
V_22 = F_30 ( sizeof( struct V_12 ) , V_65 ) ;
if ( V_22 == NULL )
return - V_44 ;
F_42 ( V_22 , V_116 ) ;
V_3 = F_63 ( V_2 , V_22 , ( void * ) V_113 , V_114 , NULL ) ;
if ( V_3 != 0 ) {
F_16 ( & V_27 -> V_28 ,
L_6 , V_29 , V_3 ) ;
F_22 ( V_22 ) ;
return V_3 ;
}
F_9 ( V_8 , V_22 ) ;
return 0 ;
}
static int F_64 ( struct V_7 * V_8 , struct V_112 * V_13 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_12 * V_22 ;
unsigned long V_113 ;
unsigned long V_114 ;
if ( V_13 -> V_115 == 0x0 )
return - V_63 ;
V_113 = ( V_13 -> V_115 & V_85 ) ;
V_114 = F_62 ( V_13 -> V_17 + ( V_13 -> V_115 & ~ V_85 ) , V_67 ) ;
V_22 = F_11 ( V_8 , V_113 , V_114 , NULL ) ;
if ( V_22 == NULL )
return - V_117 ;
F_10 ( V_8 , V_22 ) ;
F_23 ( V_2 , V_22 , NULL ) ;
F_22 ( V_22 ) ;
return 0 ;
}
static int F_65 ( struct V_7 * V_8 , struct V_118 * V_89 )
{
unsigned int V_30 ;
struct V_12 * V_22 ;
struct V_1 * V_2 = V_8 -> V_2 ;
for ( V_30 = 0 ; V_30 < V_119 ; V_30 ++ ) {
V_22 = & V_89 -> V_120 [ V_30 ] ;
if ( F_66 ( V_22 ) ) {
F_14 ( V_8 , V_22 ) ;
F_23 ( V_2 , V_22 , V_89 ) ;
}
if ( V_89 -> V_121 [ V_30 ] . V_122 != NULL )
F_67 ( V_2 , & V_89 -> V_121 [ V_30 ] ) ;
}
return 0 ;
}
static int F_68 ( struct V_7 * V_8 , struct V_118 * V_89 )
{
int V_3 ;
unsigned int V_123 , V_30 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_88 * V_91 = & V_89 -> V_91 ;
struct V_12 * V_13 ;
const char * type = L_7 ;
for ( V_30 = 0 , V_123 = 0x00 ; V_123 <= 0x58 ;
V_30 ++ , V_123 += 0x08 ) {
V_19 V_16 ;
T_1 V_58 ;
T_5 V_124 = 0 ;
V_19 V_125 ;
V_125 = F_69 ( V_91 -> V_101 , V_123 ) ;
switch ( V_125 ) {
case V_126 :
break;
case V_127 :
case V_128 : {
V_16 = F_70 ( * ( ( V_93 * ) & V_91 ->
V_100 [ V_123 ] ) ) ;
V_124 = F_71 ( * ( ( V_95 * ) & V_91 ->
V_100 [ V_123 + 0x08 ] ) ) ;
if ( V_124 == 0x0 ) {
* ( ( V_93 * ) & V_91 -> V_100 [ V_123 ] ) =
F_55 ( 0x0 ) ;
break;
}
V_13 = F_15 ( V_8 , V_16 , V_124 ,
& V_58 , NULL ) ;
if ( V_13 == NULL ) {
V_3 = - V_71 ;
goto V_129;
}
* ( ( V_93 * ) & V_91 -> V_100 [ V_123 ] ) =
F_55 ( V_58 ) ;
break;
}
case V_130 :
case V_131 : {
int V_132 ;
V_16 = F_70 ( * ( ( V_93 * )
& V_91 -> V_100 [ V_123 ] ) ) ;
V_124 = F_71 ( * ( ( V_95 * )
& V_91 -> V_100 [ V_123 + 0x08 ] ) ) ;
if ( V_124 == 0x0 ) {
* ( ( V_93 * ) & V_91 -> V_100 [ V_123 ] ) =
F_55 ( 0x0 ) ;
break;
}
V_13 = F_11 ( V_8 , V_16 , V_124 , NULL ) ;
if ( V_13 != NULL ) {
type = L_8 ;
V_132 = ( V_16 -
( V_19 ) V_13 -> V_20 ) / V_67 ;
} else {
type = L_9 ;
V_13 = & V_89 -> V_120 [ V_30 ] ;
F_42 ( V_13 ,
V_35 ) ;
V_3 = F_63 ( V_2 , V_13 , ( void * ) V_16 ,
V_124 , V_89 ) ;
if ( V_3 != 0 )
goto V_129;
F_13 ( V_8 , V_13 ) ;
V_132 = 0 ;
}
V_3 = F_72 ( V_2 , & V_89 -> V_121 [ V_30 ] ,
( void T_4 * ) V_16 ,
V_124 ) ;
if ( V_3 != 0 )
goto V_129;
F_73 ( V_2 , & V_89 -> V_121 [ V_30 ] ,
& V_13 -> V_133 [ V_132 ] ) ;
* ( ( V_93 * ) & V_91 -> V_100 [ V_123 ] ) =
F_55 ( V_89 -> V_121 [ V_30 ] . V_134 ) ;
break;
}
default:
V_3 = - V_63 ;
goto V_129;
}
}
return 0 ;
V_129:
F_65 ( V_8 , V_89 ) ;
return V_3 ;
}
static int F_74 ( struct V_7 * V_8 ,
struct V_88 * V_91 )
{
int V_3 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_41 * V_42 = V_8 -> V_42 ;
struct V_118 * V_89 = F_31 ( V_91 , struct V_118 , V_91 ) ;
V_3 = F_68 ( V_8 , V_89 ) ;
if ( V_3 != 0 )
return V_3 ;
V_3 = F_57 ( V_2 , V_91 , V_42 -> V_104 ) ;
F_65 ( V_8 , V_89 ) ;
return V_3 ;
}
static int F_75 ( struct V_7 * V_8 ,
unsigned long V_135 , int V_136 )
{
int V_3 ;
struct V_88 * V_91 ;
struct V_118 * V_89 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_41 * V_42 = V_8 -> V_42 ;
V_91 = F_53 () ;
if ( V_91 == NULL )
return - V_44 ;
V_89 = F_31 ( V_91 , struct V_118 , V_91 ) ;
if ( F_50 ( V_91 , ( void T_4 * ) V_135 , sizeof( * V_91 ) ) ) {
F_58 ( V_91 ) ;
return - V_71 ;
}
if ( ! V_136 )
V_3 = F_74 ( V_8 , V_91 ) ;
else
V_3 = F_57 ( V_2 , V_91 , V_42 -> V_104 ) ;
if ( F_60 ( ( void T_4 * ) V_135 , V_91 ,
sizeof( * V_91 ) - V_137 ) ) {
F_58 ( V_91 ) ;
return - V_71 ;
}
F_58 ( V_91 ) ;
return V_3 ;
}
static long F_76 ( struct V_41 * V_42 , unsigned int V_91 ,
unsigned long V_135 )
{
int V_3 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) V_42 -> V_48 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_27 * V_27 = V_2 -> V_27 ;
struct V_138 T_4 * V_139 ;
V_19 V_140 ;
T_5 V_141 ;
if ( F_77 ( V_27 ) )
return - V_109 ;
if ( F_78 ( V_91 ) != V_142 )
return - V_63 ;
switch ( V_91 ) {
case V_143 :
F_79 ( V_2 -> V_144 , (enum V_145 T_4 * ) V_135 ) ;
return 0 ;
case V_146 : {
V_139 = (struct V_138 T_4 * ) V_135 ;
if ( F_80 ( V_141 , & V_139 -> V_147 ) )
return - V_71 ;
if ( ( V_141 >= V_2 -> V_148 ) || ( V_141 & 0x7 ) )
return - V_63 ;
V_140 = F_81 ( V_2 , V_141 ) ;
F_79 ( V_140 , & V_139 -> V_149 ) ;
return 0 ;
}
case V_150 : {
V_139 = (struct V_138 T_4 * ) V_135 ;
if ( ! F_45 ( V_69 ) )
return - V_151 ;
if ( ( V_42 -> V_104 & V_152 ) == V_153 )
return - V_151 ;
if ( F_80 ( V_141 , & V_139 -> V_147 ) )
return - V_71 ;
if ( ( V_141 >= V_2 -> V_148 ) || ( V_141 & 0x7 ) )
return - V_63 ;
if ( F_80 ( V_140 , & V_139 -> V_149 ) )
return - V_71 ;
F_82 ( V_2 , V_141 , V_140 ) ;
return 0 ;
}
case V_154 : {
V_139 = (struct V_138 T_4 * ) V_135 ;
if ( F_80 ( V_141 , & V_139 -> V_147 ) )
return - V_71 ;
if ( ( V_141 >= V_2 -> V_148 ) || ( V_141 & 0x3 ) )
return - V_63 ;
V_140 = F_83 ( V_2 , V_141 ) ;
F_79 ( V_140 , & V_139 -> V_149 ) ;
return 0 ;
}
case V_155 : {
V_139 = (struct V_138 T_4 * ) V_135 ;
if ( ! F_45 ( V_69 ) )
return - V_151 ;
if ( ( V_42 -> V_104 & V_152 ) == V_153 )
return - V_151 ;
if ( F_80 ( V_141 , & V_139 -> V_147 ) )
return - V_71 ;
if ( ( V_141 >= V_2 -> V_148 ) || ( V_141 & 0x3 ) )
return - V_63 ;
if ( F_80 ( V_140 , & V_139 -> V_149 ) )
return - V_71 ;
F_84 ( V_2 , V_141 , V_140 ) ;
return 0 ;
}
case V_156 : {
struct V_75 V_76 ;
if ( ! F_85 ( V_2 ) )
return - V_151 ;
if ( ( V_42 -> V_104 & V_152 ) == V_153 )
return - V_151 ;
if ( F_50 ( & V_76 , ( void T_4 * ) V_135 ,
sizeof( V_76 ) ) )
return - V_71 ;
V_3 = F_48 ( V_8 , & V_76 ) ;
if ( F_60 ( ( void T_4 * ) V_135 , & V_76 , sizeof( V_76 ) ) )
return - V_71 ;
return V_3 ;
}
case V_157 : {
struct V_75 V_76 ;
if ( ! F_85 ( V_2 ) )
return - V_151 ;
if ( F_86 ( V_2 ) )
return - V_158 ;
if ( F_50 ( & V_76 , ( void T_4 * ) V_135 , sizeof( V_76 ) ) )
return - V_71 ;
V_3 = F_59 ( V_8 , & V_76 ) ;
if ( F_60 ( ( void T_4 * ) V_135 , & V_76 , sizeof( V_76 ) ) )
return - V_71 ;
return V_3 ;
}
case V_159 : {
struct V_112 V_13 ;
if ( F_50 ( & V_13 , ( void T_4 * ) V_135 , sizeof( V_13 ) ) )
return - V_71 ;
return F_61 ( V_8 , & V_13 ) ;
}
case V_160 : {
struct V_112 V_13 ;
if ( F_50 ( & V_13 , ( void T_4 * ) V_135 , sizeof( V_13 ) ) )
return - V_71 ;
return F_64 ( V_8 , & V_13 ) ;
}
case V_161 :
return F_75 ( V_8 , V_135 , 0 ) ;
case V_162 : {
if ( ! F_45 ( V_69 ) )
return - V_151 ;
return F_75 ( V_8 , V_135 , 1 ) ;
}
default:
return - V_63 ;
}
return V_3 ;
}
static long F_87 ( struct V_41 * V_42 , unsigned int V_91 ,
unsigned long V_135 )
{
return F_76 ( V_42 , V_91 , V_135 ) ;
}
static int F_88 ( struct V_1 * V_2 )
{
return V_2 -> V_28 != NULL ;
}
int F_89 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_27 * V_27 = V_2 -> V_27 ;
V_3 = F_90 ( & V_2 -> V_163 , 0 ,
V_164 , V_165 ) ;
if ( V_3 < 0 ) {
F_16 ( & V_27 -> V_28 , L_10 ) ;
goto V_166;
}
F_91 ( & V_2 -> V_46 , & V_167 ) ;
V_2 -> V_46 . V_9 = V_168 ;
V_3 = F_92 ( & V_2 -> V_46 , V_2 -> V_163 , 1 ) ;
if ( V_3 < 0 ) {
F_16 ( & V_27 -> V_28 , L_11 ) ;
goto V_169;
}
V_2 -> V_28 = F_93 ( V_2 -> V_170 ,
& V_2 -> V_27 -> V_28 ,
V_2 -> V_163 , V_2 ,
V_171 ,
V_165 L_12 ,
V_2 -> V_172 ) ;
if ( F_94 ( V_2 -> V_28 ) ) {
V_3 = F_95 ( V_2 -> V_28 ) ;
goto V_173;
}
V_3 = F_96 ( V_2 ) ;
if ( V_3 != 0 )
goto V_174;
return 0 ;
V_174:
F_97 ( V_2 -> V_170 , V_2 -> V_163 ) ;
V_173:
F_98 ( & V_2 -> V_46 ) ;
V_169:
F_99 ( V_2 -> V_163 , V_164 ) ;
V_166:
V_2 -> V_28 = NULL ;
return V_3 ;
}
static int F_100 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned int V_30 ;
struct V_27 * V_27 = V_2 -> V_27 ;
if ( ! F_1 ( V_2 ) )
return 0 ;
F_101 ( & V_27 -> V_28 , L_13 , V_29 ) ;
V_3 = F_25 ( V_2 , V_175 ) ;
if ( V_3 > 0 ) {
for ( V_30 = 0 ; ( V_30 < V_176 ) &&
F_1 ( V_2 ) ; V_30 ++ ) {
F_102 ( & V_27 -> V_28 , L_14 , V_30 ) ;
F_103 () ;
F_104 ( 1000 ) ;
}
if ( ! F_1 ( V_2 ) )
return 0 ;
F_101 ( & V_27 -> V_28 ,
L_15 , V_29 ) ;
V_3 = F_27 ( V_2 , V_177 ) ;
if ( V_3 ) {
for ( V_30 = 0 ; ( V_30 < V_176 ) &&
F_1 ( V_2 ) ; V_30 ++ ) {
F_101 ( & V_27 -> V_28 , L_14 , V_30 ) ;
F_103 () ;
F_104 ( 1000 ) ;
}
}
}
return 0 ;
}
int F_105 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_27 * V_27 = V_2 -> V_27 ;
if ( ! F_88 ( V_2 ) )
return 1 ;
F_100 ( V_2 ) ;
V_3 = F_106 ( & V_2 -> V_46 . V_178 . V_179 . V_180 ) ;
if ( V_3 != 1 ) {
F_16 ( & V_27 -> V_28 ,
L_16 , V_29 , V_3 ) ;
F_107 ( L_17 ) ;
}
F_108 ( V_2 ) ;
F_97 ( V_2 -> V_170 , V_2 -> V_163 ) ;
F_98 ( & V_2 -> V_46 ) ;
F_99 ( V_2 -> V_163 , V_164 ) ;
V_2 -> V_28 = NULL ;
return 0 ;
}
