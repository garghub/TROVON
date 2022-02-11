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
L_2
L_3 , V_29 , V_30 ++ ,
V_22 -> V_20 , ( unsigned long ) V_22 -> V_21 ,
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
struct V_40 * V_40 = V_53 -> V_57 -> V_58 -> V_59 ;
struct V_12 * V_22 ;
struct V_1 * V_2 = F_31 ( V_40 -> V_45 , struct V_1 ,
V_46 ) ;
struct V_27 * V_27 = V_2 -> V_27 ;
T_1 V_60 = 0 ;
struct V_7 * V_8 = V_53 -> V_61 ;
V_22 = F_15 ( V_8 , V_53 -> V_56 , V_54 ,
& V_60 , NULL ) ;
if ( V_22 == NULL ) {
F_16 ( & V_27 -> V_28 ,
L_4 ,
V_29 , V_53 -> V_56 , V_53 -> V_62 << V_63 ,
V_54 ) ;
return;
}
F_14 ( V_8 , V_22 ) ;
F_21 ( V_2 , V_22 -> V_17 , V_22 -> V_21 ,
V_22 -> V_26 ) ;
F_22 ( V_22 ) ;
}
static int F_39 ( struct V_41 * V_42 , struct V_52 * V_53 )
{
int V_3 ;
unsigned long V_64 , V_54 = V_53 -> V_55 - V_53 -> V_56 ;
struct V_7 * V_8 = (struct V_7 * ) V_42 -> V_48 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_12 * V_22 ;
if ( V_54 == 0 )
return - V_65 ;
if ( F_40 ( V_54 ) > V_66 )
return - V_44 ;
V_22 = F_30 ( sizeof( struct V_12 ) , V_67 ) ;
if ( V_22 == NULL )
return - V_44 ;
F_41 ( V_22 , V_34 ) ;
V_22 -> V_20 = ( void * ) V_53 -> V_56 ;
V_22 -> V_17 = V_54 ;
V_22 -> V_68 = F_42 ( V_54 , V_69 ) ;
V_22 -> V_21 = F_43 ( V_2 , V_54 ,
& V_22 -> V_26 ) ;
if ( V_22 -> V_21 == NULL ) {
V_3 = - V_44 ;
goto V_70;
}
if ( F_44 ( V_71 ) && ( V_54 > sizeof( T_1 ) ) )
* ( T_1 * ) V_22 -> V_21 = V_22 -> V_26 ;
V_64 = F_45 ( V_22 -> V_21 ) >> V_63 ;
V_3 = F_46 ( V_53 ,
V_53 -> V_56 ,
V_64 ,
V_54 ,
V_53 -> V_72 ) ;
if ( V_3 != 0 ) {
V_3 = - V_73 ;
goto V_74;
}
V_53 -> V_61 = V_8 ;
V_53 -> V_75 = & V_76 ;
F_13 ( V_8 , V_22 ) ;
return 0 ;
V_74:
F_21 ( V_2 , V_22 -> V_17 ,
V_22 -> V_21 ,
V_22 -> V_26 ) ;
V_70:
F_22 ( V_22 ) ;
return V_3 ;
}
static int F_47 ( struct V_7 * V_8 ,
struct V_77 * V_78 )
{
int V_3 = 0 ;
int V_79 ;
T_1 V_26 ;
V_19 V_80 = 0 ;
T_2 V_81 = 0 ;
T_3 T_4 * V_82 ;
T_3 * V_83 ;
T_5 V_84 ;
T_3 V_85 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_27 * V_27 = V_2 -> V_27 ;
if ( ( V_78 -> V_17 & 0x3 ) != 0 )
return - V_65 ;
if ( ( ( unsigned long ) ( V_78 -> V_86 ) & ~ V_87 ) != 0 )
return - V_65 ;
switch ( ( char ) V_78 -> V_88 ) {
case '0' :
V_85 = 0x14 ;
break;
case '1' :
V_85 = 0x1C ;
break;
case 'v' :
V_85 = 0x0C ;
break;
default:
return - V_65 ;
}
V_82 = ( T_3 T_4 * ) V_78 -> V_86 ;
V_83 = F_43 ( V_2 , V_89 , & V_26 ) ;
if ( V_83 == NULL )
return - V_44 ;
V_79 = V_78 -> V_17 / V_89 ;
while ( V_78 -> V_17 ) {
struct V_90 * V_91 ;
V_81 = F_48 ( T_2 , V_78 -> V_17 , V_89 ) ;
V_3 = F_49 ( V_83 , V_82 , V_81 ) ;
if ( V_3 ) {
V_3 = - V_73 ;
goto V_92;
}
V_84 = F_50 ( V_83 , V_81 , 0xffffffff ) ;
F_51 ( & V_27 -> V_28 ,
L_5 ,
V_29 , ( unsigned long ) V_26 , V_84 , V_81 ,
V_79 ) ;
V_91 = F_52 () ;
if ( V_91 == NULL ) {
V_3 = - V_44 ;
goto V_92;
}
V_91 -> V_93 = V_94 ;
V_91 -> V_85 = V_85 ;
if ( F_53 ( V_2 ) <= 0x2 ) {
* ( V_95 * ) & V_91 -> V_96 [ 0 ] = F_54 ( V_26 ) ;
* ( V_95 * ) & V_91 -> V_96 [ 8 ] = F_54 ( V_81 ) ;
* ( V_95 * ) & V_91 -> V_96 [ 16 ] = F_54 ( V_80 ) ;
* ( V_97 * ) & V_91 -> V_96 [ 24 ] = F_55 ( 0 ) ;
V_91 -> V_96 [ 24 ] = V_78 -> V_98 ;
* ( V_97 * ) & V_91 -> V_96 [ 28 ] = F_55 ( V_84 ) ;
* ( V_95 * ) & V_91 -> V_96 [ 88 ] = F_54 ( V_78 -> V_99 ) ;
* ( V_95 * ) & V_91 -> V_96 [ 96 ] = F_54 ( V_78 -> V_100 ) ;
V_91 -> V_101 = 32 ;
} else {
* ( V_95 * ) & V_91 -> V_102 [ 0 ] = F_54 ( V_26 ) ;
* ( V_97 * ) & V_91 -> V_102 [ 8 ] = F_55 ( V_81 ) ;
* ( V_97 * ) & V_91 -> V_102 [ 12 ] = F_55 ( 0 ) ;
* ( V_95 * ) & V_91 -> V_102 [ 16 ] = F_54 ( V_80 ) ;
* ( V_97 * ) & V_91 -> V_102 [ 24 ] = F_55 ( V_78 -> V_98 << 24 ) ;
* ( V_97 * ) & V_91 -> V_102 [ 28 ] = F_55 ( V_84 ) ;
* ( V_95 * ) & V_91 -> V_102 [ 80 ] = F_54 ( V_78 -> V_99 ) ;
* ( V_95 * ) & V_91 -> V_102 [ 88 ] = F_54 ( V_78 -> V_100 ) ;
V_91 -> V_103 = 0x4ULL << 44 ;
V_91 -> V_101 = 40 ;
}
V_91 -> V_104 = 8 ;
* ( V_19 * ) & V_91 -> V_105 [ 0 ] = 0ULL ;
V_3 = F_56 ( V_2 , V_91 ) ;
V_78 -> V_106 = V_91 -> V_106 ;
V_78 -> V_107 = V_91 -> V_107 ;
V_78 -> V_108 = V_91 -> V_108 ;
if ( V_3 < 0 ) {
F_57 ( V_91 ) ;
goto V_92;
}
if ( V_91 -> V_106 != V_109 ) {
V_3 = - V_110 ;
F_57 ( V_91 ) ;
goto V_92;
}
V_78 -> V_17 -= V_81 ;
V_80 += V_81 ;
V_82 += V_81 ;
V_79 -- ;
F_57 ( V_91 ) ;
}
V_92:
F_21 ( V_2 , V_89 , V_83 , V_26 ) ;
return V_3 ;
}
static int F_58 ( struct V_7 * V_8 ,
struct V_77 * V_78 )
{
int V_3 , V_79 ;
T_1 V_26 ;
V_19 V_80 = 0 ;
T_2 V_81 = 0 ;
T_3 T_4 * V_82 ;
T_3 * V_83 ;
T_3 V_85 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_27 * V_27 = V_2 -> V_27 ;
struct V_90 * V_93 ;
if ( ( V_78 -> V_17 & 0x3 ) != 0 )
return - V_65 ;
if ( ( ( unsigned long ) ( V_78 -> V_86 ) & ~ V_87 ) != 0 )
return - V_65 ;
switch ( ( char ) V_78 -> V_88 ) {
case '0' :
V_85 = 0x12 ;
break;
case '1' :
V_85 = 0x1A ;
break;
case 'v' :
V_85 = 0x0A ;
break;
default:
return - V_65 ;
}
V_82 = ( T_3 T_4 * ) V_78 -> V_86 ;
V_83 = F_43 ( V_2 , V_89 , & V_26 ) ;
if ( V_83 == NULL )
return - V_44 ;
V_79 = V_78 -> V_17 / V_89 ;
while ( V_78 -> V_17 ) {
V_81 = F_48 ( T_2 , V_78 -> V_17 , V_89 ) ;
F_51 ( & V_27 -> V_28 ,
L_6 ,
V_29 , ( unsigned long ) V_26 , V_81 ,
V_79 ) ;
V_93 = F_52 () ;
if ( V_93 == NULL ) {
V_3 = - V_44 ;
goto V_92;
}
V_93 -> V_93 = V_94 ;
V_93 -> V_85 = V_85 ;
if ( F_53 ( V_2 ) <= 0x2 ) {
* ( V_95 * ) & V_93 -> V_96 [ 0 ] = F_54 ( V_26 ) ;
* ( V_95 * ) & V_93 -> V_96 [ 8 ] = F_54 ( V_81 ) ;
* ( V_95 * ) & V_93 -> V_96 [ 16 ] = F_54 ( V_80 ) ;
* ( V_97 * ) & V_93 -> V_96 [ 24 ] = F_55 ( 0 ) ;
V_93 -> V_96 [ 24 ] = V_78 -> V_98 ;
* ( V_97 * ) & V_93 -> V_96 [ 28 ] = F_55 ( 0 ) ;
V_93 -> V_101 = 32 ;
} else {
* ( V_95 * ) & V_93 -> V_102 [ 0 ] = F_54 ( V_26 ) ;
* ( V_97 * ) & V_93 -> V_102 [ 8 ] = F_55 ( V_81 ) ;
* ( V_97 * ) & V_93 -> V_102 [ 12 ] = F_55 ( 0 ) ;
* ( V_95 * ) & V_93 -> V_102 [ 16 ] = F_54 ( V_80 ) ;
* ( V_97 * ) & V_93 -> V_102 [ 24 ] = F_55 ( V_78 -> V_98 << 24 ) ;
* ( V_97 * ) & V_93 -> V_102 [ 28 ] = F_55 ( 0 ) ;
V_93 -> V_103 = 0x5ULL << 44 ;
V_93 -> V_101 = 40 ;
}
V_93 -> V_104 = 8 ;
* ( V_19 * ) & V_93 -> V_105 [ 0 ] = 0ULL ;
V_3 = F_56 ( V_2 , V_93 ) ;
V_78 -> V_106 = V_93 -> V_106 ;
V_78 -> V_107 = V_93 -> V_107 ;
V_78 -> V_108 = V_93 -> V_108 ;
if ( ( V_3 < 0 ) && ( V_3 != - V_111 ) ) {
F_57 ( V_93 ) ;
goto V_92;
}
V_3 = F_59 ( V_82 , V_83 , V_81 ) ;
if ( V_3 ) {
V_3 = - V_73 ;
F_57 ( V_93 ) ;
goto V_92;
}
if ( ( ( V_93 -> V_106 == V_112 ) &&
( V_93 -> V_107 != 0x02 ) ) ||
( ( V_93 -> V_106 == V_109 ) &&
( V_93 -> V_107 != 0x00 ) ) ) {
V_3 = - V_110 ;
F_57 ( V_93 ) ;
goto V_92;
}
V_78 -> V_17 -= V_81 ;
V_80 += V_81 ;
V_82 += V_81 ;
V_79 -- ;
F_57 ( V_93 ) ;
}
V_3 = 0 ;
V_92:
F_21 ( V_2 , V_89 , V_83 , V_26 ) ;
return V_3 ;
}
static int F_60 ( struct V_7 * V_8 , struct V_113 * V_13 )
{
int V_3 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_27 * V_27 = V_8 -> V_2 -> V_27 ;
struct V_12 * V_22 ;
unsigned long V_114 ;
unsigned long V_115 ;
if ( ( V_13 -> V_116 == 0x0 ) || ( V_13 -> V_17 == 0 ) )
return - V_65 ;
V_114 = ( V_13 -> V_116 & V_87 ) ;
V_115 = F_61 ( V_13 -> V_17 + ( V_13 -> V_116 & ~ V_87 ) , V_69 ) ;
V_22 = F_30 ( sizeof( struct V_12 ) , V_67 ) ;
if ( V_22 == NULL )
return - V_44 ;
F_41 ( V_22 , V_117 ) ;
V_3 = F_62 ( V_2 , V_22 , ( void * ) V_114 , V_115 , NULL ) ;
if ( V_3 != 0 ) {
F_16 ( & V_27 -> V_28 ,
L_7 , V_29 , V_3 ) ;
F_22 ( V_22 ) ;
return V_3 ;
}
F_9 ( V_8 , V_22 ) ;
return 0 ;
}
static int F_63 ( struct V_7 * V_8 , struct V_113 * V_13 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_12 * V_22 ;
unsigned long V_114 ;
unsigned long V_115 ;
if ( V_13 -> V_116 == 0x0 )
return - V_65 ;
V_114 = ( V_13 -> V_116 & V_87 ) ;
V_115 = F_61 ( V_13 -> V_17 + ( V_13 -> V_116 & ~ V_87 ) , V_69 ) ;
V_22 = F_11 ( V_8 , V_114 , V_115 , NULL ) ;
if ( V_22 == NULL )
return - V_118 ;
F_10 ( V_8 , V_22 ) ;
F_23 ( V_2 , V_22 , NULL ) ;
F_22 ( V_22 ) ;
return 0 ;
}
static int F_64 ( struct V_7 * V_8 , struct V_119 * V_91 )
{
unsigned int V_30 ;
struct V_12 * V_22 ;
struct V_1 * V_2 = V_8 -> V_2 ;
for ( V_30 = 0 ; V_30 < V_120 ; V_30 ++ ) {
V_22 = & V_91 -> V_121 [ V_30 ] ;
if ( F_65 ( V_22 ) ) {
F_14 ( V_8 , V_22 ) ;
F_23 ( V_2 , V_22 , V_91 ) ;
}
if ( V_91 -> V_122 [ V_30 ] . V_123 != NULL )
F_66 ( V_2 , & V_91 -> V_122 [ V_30 ] ) ;
}
return 0 ;
}
static int F_67 ( struct V_7 * V_8 , struct V_119 * V_91 )
{
int V_3 ;
unsigned int V_124 , V_30 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_90 * V_93 = & V_91 -> V_93 ;
struct V_12 * V_13 ;
const char * type = L_8 ;
for ( V_30 = 0 , V_124 = 0x00 ; V_124 <= 0x58 ;
V_30 ++ , V_124 += 0x08 ) {
V_19 V_16 ;
T_1 V_60 ;
T_5 V_125 = 0 ;
V_19 V_126 ;
V_126 = F_68 ( V_93 -> V_103 , V_124 ) ;
switch ( V_126 ) {
case V_127 :
break;
case V_128 :
case V_129 : {
V_16 = F_69 ( * ( ( V_95 * ) & V_93 ->
V_102 [ V_124 ] ) ) ;
V_125 = F_70 ( * ( ( V_97 * ) & V_93 ->
V_102 [ V_124 + 0x08 ] ) ) ;
if ( V_125 == 0x0 ) {
* ( ( V_95 * ) & V_93 -> V_102 [ V_124 ] ) =
F_54 ( 0x0 ) ;
break;
}
V_13 = F_15 ( V_8 , V_16 , V_125 ,
& V_60 , NULL ) ;
if ( V_13 == NULL ) {
V_3 = - V_73 ;
goto V_130;
}
* ( ( V_95 * ) & V_93 -> V_102 [ V_124 ] ) =
F_54 ( V_60 ) ;
break;
}
case V_131 :
case V_132 : {
int V_133 ;
V_16 = F_69 ( * ( ( V_95 * )
& V_93 -> V_102 [ V_124 ] ) ) ;
V_125 = F_70 ( * ( ( V_97 * )
& V_93 -> V_102 [ V_124 + 0x08 ] ) ) ;
if ( V_125 == 0x0 ) {
* ( ( V_95 * ) & V_93 -> V_102 [ V_124 ] ) =
F_54 ( 0x0 ) ;
break;
}
V_13 = F_11 ( V_8 , V_16 , V_125 , NULL ) ;
if ( V_13 != NULL ) {
type = L_9 ;
V_133 = ( V_16 -
( V_19 ) V_13 -> V_20 ) / V_69 ;
} else {
type = L_10 ;
V_13 = & V_91 -> V_121 [ V_30 ] ;
F_41 ( V_13 ,
V_35 ) ;
V_3 = F_62 ( V_2 , V_13 , ( void * ) V_16 ,
V_125 , V_91 ) ;
if ( V_3 != 0 )
goto V_130;
F_13 ( V_8 , V_13 ) ;
V_133 = 0 ;
}
V_3 = F_71 ( V_2 , & V_91 -> V_122 [ V_30 ] ,
( void T_4 * ) V_16 ,
V_125 ) ;
if ( V_3 != 0 )
goto V_130;
F_72 ( V_2 , & V_91 -> V_122 [ V_30 ] ,
& V_13 -> V_134 [ V_133 ] ) ;
* ( ( V_95 * ) & V_93 -> V_102 [ V_124 ] ) =
F_54 ( V_91 -> V_122 [ V_30 ] . V_135 ) ;
break;
}
default:
V_3 = - V_65 ;
goto V_130;
}
}
return 0 ;
V_130:
F_64 ( V_8 , V_91 ) ;
return V_3 ;
}
static int F_73 ( struct V_7 * V_8 ,
struct V_90 * V_93 )
{
int V_3 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_119 * V_91 = F_31 ( V_93 , struct V_119 , V_93 ) ;
V_3 = F_67 ( V_8 , V_91 ) ;
if ( V_3 != 0 )
return V_3 ;
V_3 = F_56 ( V_2 , V_93 ) ;
F_64 ( V_8 , V_91 ) ;
return V_3 ;
}
static int F_74 ( struct V_7 * V_8 ,
unsigned long V_136 , int V_137 )
{
int V_3 ;
struct V_90 * V_93 ;
struct V_119 * V_91 ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_93 = F_52 () ;
if ( V_93 == NULL )
return - V_44 ;
V_91 = F_31 ( V_93 , struct V_119 , V_93 ) ;
if ( F_49 ( V_93 , ( void T_4 * ) V_136 , sizeof( * V_93 ) ) ) {
F_57 ( V_93 ) ;
return - V_73 ;
}
if ( ! V_137 )
V_3 = F_73 ( V_8 , V_93 ) ;
else
V_3 = F_56 ( V_2 , V_93 ) ;
if ( F_59 ( ( void T_4 * ) V_136 , V_93 ,
sizeof( * V_93 ) - V_138 ) ) {
F_57 ( V_93 ) ;
return - V_73 ;
}
F_57 ( V_93 ) ;
return V_3 ;
}
static long F_75 ( struct V_41 * V_42 , unsigned int V_93 ,
unsigned long V_136 )
{
int V_3 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) V_42 -> V_48 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_27 * V_27 = V_2 -> V_27 ;
struct V_139 T_4 * V_140 ;
V_19 V_141 ;
T_5 V_142 ;
if ( F_76 ( V_27 ) )
return - V_110 ;
if ( F_77 ( V_93 ) != V_143 )
return - V_65 ;
switch ( V_93 ) {
case V_144 :
F_78 ( V_2 -> V_145 , (enum V_146 T_4 * ) V_136 ) ;
return 0 ;
case V_147 : {
V_140 = (struct V_139 T_4 * ) V_136 ;
if ( F_79 ( V_142 , & V_140 -> V_148 ) )
return - V_73 ;
if ( ( V_142 >= V_2 -> V_149 ) || ( V_142 & 0x7 ) )
return - V_65 ;
V_141 = F_80 ( V_2 , V_142 ) ;
F_78 ( V_141 , & V_140 -> V_150 ) ;
return 0 ;
}
case V_151 : {
V_140 = (struct V_139 T_4 * ) V_136 ;
if ( ! F_44 ( V_71 ) )
return - V_152 ;
if ( ( V_42 -> V_153 & V_154 ) == V_155 )
return - V_152 ;
if ( F_79 ( V_142 , & V_140 -> V_148 ) )
return - V_73 ;
if ( ( V_142 >= V_2 -> V_149 ) || ( V_142 & 0x7 ) )
return - V_65 ;
if ( F_79 ( V_141 , & V_140 -> V_150 ) )
return - V_73 ;
F_81 ( V_2 , V_142 , V_141 ) ;
return 0 ;
}
case V_156 : {
V_140 = (struct V_139 T_4 * ) V_136 ;
if ( F_79 ( V_142 , & V_140 -> V_148 ) )
return - V_73 ;
if ( ( V_142 >= V_2 -> V_149 ) || ( V_142 & 0x3 ) )
return - V_65 ;
V_141 = F_82 ( V_2 , V_142 ) ;
F_78 ( V_141 , & V_140 -> V_150 ) ;
return 0 ;
}
case V_157 : {
V_140 = (struct V_139 T_4 * ) V_136 ;
if ( ! F_44 ( V_71 ) )
return - V_152 ;
if ( ( V_42 -> V_153 & V_154 ) == V_155 )
return - V_152 ;
if ( F_79 ( V_142 , & V_140 -> V_148 ) )
return - V_73 ;
if ( ( V_142 >= V_2 -> V_149 ) || ( V_142 & 0x3 ) )
return - V_65 ;
if ( F_79 ( V_141 , & V_140 -> V_150 ) )
return - V_73 ;
F_83 ( V_2 , V_142 , V_141 ) ;
return 0 ;
}
case V_158 : {
struct V_77 V_78 ;
if ( ! F_84 ( V_2 ) )
return - V_152 ;
if ( ( V_42 -> V_153 & V_154 ) == V_155 )
return - V_152 ;
if ( F_49 ( & V_78 , ( void T_4 * ) V_136 ,
sizeof( V_78 ) ) )
return - V_73 ;
V_3 = F_47 ( V_8 , & V_78 ) ;
if ( F_59 ( ( void T_4 * ) V_136 , & V_78 , sizeof( V_78 ) ) )
return - V_73 ;
return V_3 ;
}
case V_159 : {
struct V_77 V_78 ;
if ( ! F_84 ( V_2 ) )
return - V_152 ;
if ( F_85 ( V_2 ) )
return - V_160 ;
if ( F_49 ( & V_78 , ( void T_4 * ) V_136 , sizeof( V_78 ) ) )
return - V_73 ;
V_3 = F_58 ( V_8 , & V_78 ) ;
if ( F_59 ( ( void T_4 * ) V_136 , & V_78 , sizeof( V_78 ) ) )
return - V_73 ;
return V_3 ;
}
case V_161 : {
struct V_113 V_13 ;
if ( F_49 ( & V_13 , ( void T_4 * ) V_136 , sizeof( V_13 ) ) )
return - V_73 ;
return F_60 ( V_8 , & V_13 ) ;
}
case V_162 : {
struct V_113 V_13 ;
if ( F_49 ( & V_13 , ( void T_4 * ) V_136 , sizeof( V_13 ) ) )
return - V_73 ;
return F_63 ( V_8 , & V_13 ) ;
}
case V_163 :
return F_74 ( V_8 , V_136 , 0 ) ;
case V_164 : {
if ( ! F_44 ( V_71 ) )
return - V_152 ;
return F_74 ( V_8 , V_136 , 1 ) ;
}
default:
return - V_65 ;
}
return V_3 ;
}
static long F_86 ( struct V_41 * V_42 , unsigned int V_93 ,
unsigned long V_136 )
{
return F_75 ( V_42 , V_93 , V_136 ) ;
}
static int F_87 ( struct V_1 * V_2 )
{
return V_2 -> V_28 != NULL ;
}
int F_88 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_27 * V_27 = V_2 -> V_27 ;
V_3 = F_89 ( & V_2 -> V_165 , 0 ,
V_166 , V_167 ) ;
if ( V_3 < 0 ) {
F_16 ( & V_27 -> V_28 , L_11 ) ;
goto V_168;
}
F_90 ( & V_2 -> V_46 , & V_169 ) ;
V_2 -> V_46 . V_9 = V_170 ;
V_3 = F_91 ( & V_2 -> V_46 , V_2 -> V_165 , 1 ) ;
if ( V_3 < 0 ) {
F_16 ( & V_27 -> V_28 , L_12 ) ;
goto V_171;
}
V_2 -> V_28 = F_92 ( V_2 -> V_172 ,
& V_2 -> V_27 -> V_28 ,
V_2 -> V_165 , V_2 ,
V_173 ,
V_167 L_13 ,
V_2 -> V_174 ) ;
if ( F_93 ( V_2 -> V_28 ) ) {
V_3 = F_94 ( V_2 -> V_28 ) ;
goto V_175;
}
V_3 = F_95 ( V_2 ) ;
if ( V_3 != 0 )
goto V_176;
return 0 ;
V_176:
F_96 ( V_2 -> V_172 , V_2 -> V_165 ) ;
V_175:
F_97 ( & V_2 -> V_46 ) ;
V_171:
F_98 ( V_2 -> V_165 , V_166 ) ;
V_168:
V_2 -> V_28 = NULL ;
return V_3 ;
}
static int F_99 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned int V_30 ;
struct V_27 * V_27 = V_2 -> V_27 ;
if ( ! F_1 ( V_2 ) )
return 0 ;
F_100 ( & V_27 -> V_28 , L_14 , V_29 ) ;
V_3 = F_25 ( V_2 , V_177 ) ;
if ( V_3 > 0 ) {
for ( V_30 = 0 ; ( V_30 < V_178 ) &&
F_1 ( V_2 ) ; V_30 ++ ) {
F_101 ( & V_27 -> V_28 , L_15 , V_30 ) ;
F_102 () ;
F_103 ( 1000 ) ;
}
if ( ! F_1 ( V_2 ) )
return 0 ;
F_100 ( & V_27 -> V_28 ,
L_16 , V_29 ) ;
V_3 = F_27 ( V_2 , V_179 ) ;
if ( V_3 ) {
for ( V_30 = 0 ; ( V_30 < V_178 ) &&
F_1 ( V_2 ) ; V_30 ++ ) {
F_100 ( & V_27 -> V_28 , L_15 , V_30 ) ;
F_102 () ;
F_103 ( 1000 ) ;
}
}
}
return 0 ;
}
int F_104 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_27 * V_27 = V_2 -> V_27 ;
if ( ! F_87 ( V_2 ) )
return 1 ;
F_99 ( V_2 ) ;
V_3 = F_105 ( & V_2 -> V_46 . V_180 . V_181 . V_182 ) ;
if ( V_3 != 1 ) {
F_16 ( & V_27 -> V_28 ,
L_17 , V_29 , V_3 ) ;
F_106 ( L_18 ) ;
}
F_107 ( V_2 ) ;
F_96 ( V_2 -> V_172 , V_2 -> V_165 ) ;
F_97 ( & V_2 -> V_46 ) ;
F_98 ( V_2 -> V_165 , V_166 ) ;
V_2 -> V_28 = NULL ;
return 0 ;
}
