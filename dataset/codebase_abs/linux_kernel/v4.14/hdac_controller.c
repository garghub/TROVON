static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 1000 ; V_3 > 0 ; V_3 -- ) {
if ( F_2 ( V_2 , V_4 ) & V_5 )
break;
F_3 ( 1 ) ;
}
if ( V_3 <= 0 )
F_4 ( V_2 -> V_6 , L_1 ,
F_2 ( V_2 , V_4 ) ) ;
F_5 ( V_2 , V_4 , 0 ) ;
for ( V_3 = 1000 ; V_3 > 0 ; V_3 -- ) {
if ( F_2 ( V_2 , V_4 ) == 0 )
break;
F_3 ( 1 ) ;
}
if ( V_3 <= 0 )
F_4 ( V_2 -> V_6 , L_2 ,
F_2 ( V_2 , V_4 ) ) ;
}
void F_6 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_7 ) ;
V_2 -> V_8 . V_9 = V_2 -> V_10 . V_9 ;
V_2 -> V_8 . V_11 = ( V_12 * ) V_2 -> V_10 . V_13 ;
F_8 ( V_2 , V_14 , ( V_15 ) V_2 -> V_8 . V_9 ) ;
F_8 ( V_2 , V_16 , F_9 ( V_2 -> V_8 . V_9 ) ) ;
F_10 ( V_2 , V_17 , 0x02 ) ;
F_5 ( V_2 , V_18 , 0 ) ;
F_5 ( V_2 , V_4 , V_5 ) ;
if ( ! V_2 -> V_19 )
F_1 ( V_2 ) ;
F_10 ( V_2 , V_20 , V_21 ) ;
V_2 -> V_22 . V_9 = V_2 -> V_10 . V_9 + 2048 ;
V_2 -> V_22 . V_11 = ( V_12 * ) ( V_2 -> V_10 . V_13 + 2048 ) ;
V_2 -> V_22 . V_23 = V_2 -> V_22 . V_24 = 0 ;
memset ( V_2 -> V_22 . V_25 , 0 , sizeof( V_2 -> V_22 . V_25 ) ) ;
F_8 ( V_2 , V_26 , ( V_15 ) V_2 -> V_22 . V_9 ) ;
F_8 ( V_2 , V_27 , F_9 ( V_2 -> V_22 . V_9 ) ) ;
F_10 ( V_2 , V_28 , 0x02 ) ;
F_5 ( V_2 , V_29 , V_30 ) ;
F_5 ( V_2 , V_31 , 1 ) ;
F_10 ( V_2 , V_32 , V_33 | V_34 ) ;
F_11 ( & V_2 -> V_7 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
V_3 = V_35 + F_13 ( 100 ) ;
while ( ( F_14 ( V_2 , V_32 ) & V_33 )
&& F_15 ( V_35 , V_3 ) )
F_3 ( 10 ) ;
V_3 = V_35 + F_13 ( 100 ) ;
while ( ( F_14 ( V_2 , V_20 ) & V_21 )
&& F_15 ( V_35 , V_3 ) )
F_3 ( 10 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_7 ) ;
F_10 ( V_2 , V_32 , 0 ) ;
F_10 ( V_2 , V_20 , 0 ) ;
F_11 ( & V_2 -> V_7 ) ;
F_12 ( V_2 ) ;
F_7 ( & V_2 -> V_7 ) ;
F_17 ( V_2 , V_36 , V_37 , 0 ) ;
F_11 ( & V_2 -> V_7 ) ;
}
static unsigned int F_18 ( V_15 V_38 )
{
unsigned int V_9 = V_38 >> 28 ;
if ( F_19 ( V_9 >= V_39 ) )
V_9 = 0 ;
return V_9 ;
}
int F_20 ( struct V_1 * V_2 , unsigned int V_40 )
{
unsigned int V_9 = F_18 ( V_40 ) ;
unsigned int V_23 , V_24 ;
F_7 ( & V_2 -> V_7 ) ;
V_2 -> V_41 [ F_18 ( V_40 ) ] = V_40 ;
V_23 = F_2 ( V_2 , V_18 ) ;
if ( V_23 == 0xffff ) {
F_11 ( & V_2 -> V_7 ) ;
return - V_42 ;
}
V_23 ++ ;
V_23 %= V_43 ;
V_24 = F_2 ( V_2 , V_4 ) ;
if ( V_23 == V_24 ) {
F_11 ( & V_2 -> V_7 ) ;
return - V_44 ;
}
V_2 -> V_22 . V_25 [ V_9 ] ++ ;
V_2 -> V_8 . V_11 [ V_23 ] = F_21 ( V_40 ) ;
F_5 ( V_2 , V_18 , V_23 ) ;
F_11 ( & V_2 -> V_7 ) ;
return 0 ;
}
void F_22 ( struct V_1 * V_2 )
{
unsigned int V_24 , V_23 ;
unsigned int V_9 ;
V_15 V_45 , V_46 ;
V_23 = F_2 ( V_2 , V_29 ) ;
if ( V_23 == 0xffff ) {
return;
}
if ( V_23 == V_2 -> V_22 . V_23 )
return;
V_2 -> V_22 . V_23 = V_23 ;
while ( V_2 -> V_22 . V_24 != V_23 ) {
V_2 -> V_22 . V_24 ++ ;
V_2 -> V_22 . V_24 %= V_47 ;
V_24 = V_2 -> V_22 . V_24 << 1 ;
V_46 = F_23 ( V_2 -> V_22 . V_11 [ V_24 + 1 ] ) ;
V_45 = F_23 ( V_2 -> V_22 . V_11 [ V_24 ] ) ;
V_9 = V_46 & 0xf ;
if ( V_9 >= V_39 ) {
F_4 ( V_2 -> V_6 ,
L_3 ,
V_45 , V_46 , V_2 -> V_22 . V_24 , V_23 ) ;
F_24 () ;
} else if ( V_46 & V_48 )
F_25 ( V_2 , V_45 , V_46 ) ;
else if ( V_2 -> V_22 . V_25 [ V_9 ] ) {
V_2 -> V_22 . V_45 [ V_9 ] = V_45 ;
V_2 -> V_22 . V_25 [ V_9 ] -- ;
} else {
F_26 ( V_2 -> V_6 ,
L_4 ,
V_45 , V_46 , V_2 -> V_41 [ V_9 ] ) ;
}
}
}
int F_27 ( struct V_1 * V_2 , unsigned int V_9 ,
unsigned int * V_45 )
{
unsigned long V_3 ;
unsigned long V_49 ;
V_3 = V_35 + F_13 ( 1000 ) ;
for ( V_49 = 0 ; ; V_49 ++ ) {
F_7 ( & V_2 -> V_7 ) ;
if ( ! V_2 -> V_22 . V_25 [ V_9 ] ) {
if ( V_45 )
* V_45 = V_2 -> V_22 . V_45 [ V_9 ] ;
F_11 ( & V_2 -> V_7 ) ;
return 0 ;
}
F_11 ( & V_2 -> V_7 ) ;
if ( F_28 ( V_35 , V_3 ) )
break;
if ( V_49 > 3000 )
F_29 ( 2 ) ;
else {
F_3 ( 10 ) ;
F_30 () ;
}
}
return - V_42 ;
}
int F_31 ( struct V_1 * V_2 )
{
unsigned int V_50 ;
unsigned int V_51 ;
unsigned int V_52 = 0 ;
V_51 = F_2 ( V_2 , V_53 ) ;
do {
V_50 = F_32 ( V_2 , V_51 ) ;
F_33 ( V_2 -> V_6 , L_5 ,
( V_50 & V_54 ) >> V_55 ) ;
F_33 ( V_2 -> V_6 , L_6 ,
( V_50 & V_56 ) >> V_57 ) ;
if ( V_50 == - 1 ) {
F_33 ( V_2 -> V_6 , L_7 ) ;
break;
}
switch ( ( V_50 & V_56 ) >> V_57 ) {
case V_58 :
F_33 ( V_2 -> V_6 , L_8 ) ;
V_2 -> V_59 = V_2 -> V_60 + V_51 ;
break;
case V_61 :
F_33 ( V_2 -> V_6 , L_9 , V_51 ) ;
V_2 -> V_62 = V_2 -> V_60 + V_51 ;
break;
case V_63 :
F_33 ( V_2 -> V_6 , L_10 , V_51 ) ;
V_2 -> V_64 = V_2 -> V_60 + V_51 ;
break;
case V_65 :
F_33 ( V_2 -> V_6 , L_11 ) ;
V_2 -> V_66 = V_2 -> V_60 + V_51 ;
break;
case V_67 :
F_33 ( V_2 -> V_6 , L_12 ) ;
V_2 -> V_68 = V_2 -> V_60 + V_51 ;
break;
default:
F_33 ( V_2 -> V_6 , L_13 , V_50 ) ;
break;
}
V_52 ++ ;
if ( V_52 > V_69 ) {
F_4 ( V_2 -> V_6 , L_14 ) ;
break;
}
V_51 = V_50 & V_70 ;
} while ( V_51 );
return 0 ;
}
void F_34 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_17 ( V_2 , V_36 , V_71 , 0 ) ;
V_3 = V_35 + F_13 ( 100 ) ;
while ( ( F_14 ( V_2 , V_36 ) & V_71 ) &&
F_15 ( V_35 , V_3 ) )
F_35 ( 500 , 1000 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_37 ( V_2 , V_36 , 0 , V_71 ) ;
V_3 = V_35 + F_13 ( 100 ) ;
while ( ! F_14 ( V_2 , V_36 ) && F_15 ( V_35 , V_3 ) )
F_35 ( 500 , 1000 ) ;
}
static int F_38 ( struct V_1 * V_2 , bool V_72 )
{
if ( ! V_72 )
goto V_73;
F_5 ( V_2 , V_74 , V_75 ) ;
F_34 ( V_2 ) ;
F_35 ( 500 , 1000 ) ;
F_36 ( V_2 ) ;
F_35 ( 1000 , 1200 ) ;
V_73:
if ( ! F_14 ( V_2 , V_36 ) ) {
F_33 ( V_2 -> V_6 , L_15 ) ;
return - V_76 ;
}
F_17 ( V_2 , V_36 , 0 , V_37 ) ;
if ( ! V_2 -> V_77 ) {
V_2 -> V_77 = F_2 ( V_2 , V_74 ) ;
F_33 ( V_2 -> V_6 , L_16 , V_2 -> V_77 ) ;
}
return 0 ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_78 , 0 , V_79 | V_80 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_81 * V_82 ;
F_41 (azx_dev, &bus->stream_list, list)
F_42 ( V_82 , V_83 , V_84 , 0 ) ;
F_10 ( V_2 , V_78 , 0 ) ;
F_17 ( V_2 , V_78 , V_79 | V_80 , 0 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_81 * V_82 ;
F_41 (azx_dev, &bus->stream_list, list)
F_44 ( V_82 , V_85 , V_84 ) ;
F_5 ( V_2 , V_74 , V_75 ) ;
F_10 ( V_2 , V_86 , V_87 ) ;
F_8 ( V_2 , V_88 , V_79 | V_89 ) ;
}
bool F_45 ( struct V_1 * V_2 , bool V_72 )
{
if ( V_2 -> V_90 )
return false ;
F_38 ( V_2 , V_72 ) ;
F_43 ( V_2 ) ;
F_39 ( V_2 ) ;
F_6 ( V_2 ) ;
if ( V_2 -> V_91 && V_2 -> V_92 . V_9 ) {
F_8 ( V_2 , V_93 , ( V_15 ) V_2 -> V_92 . V_9 ) ;
F_8 ( V_2 , V_94 , F_9 ( V_2 -> V_92 . V_9 ) ) ;
}
V_2 -> V_90 = true ;
return true ;
}
void F_46 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_90 )
return;
F_40 ( V_2 ) ;
F_43 ( V_2 ) ;
F_16 ( V_2 ) ;
if ( V_2 -> V_92 . V_9 ) {
F_8 ( V_2 , V_93 , 0 ) ;
F_8 ( V_2 , V_94 , 0 ) ;
}
V_2 -> V_90 = false ;
}
int F_47 ( struct V_1 * V_2 , unsigned int V_95 ,
void (* F_48)( struct V_1 * ,
struct V_81 * ) )
{
struct V_81 * V_82 ;
T_1 V_96 ;
int V_97 = 0 ;
F_41 (azx_dev, &bus->stream_list, list) {
if ( V_95 & V_82 -> V_98 ) {
V_96 = F_49 ( V_82 , V_85 ) ;
F_44 ( V_82 , V_85 , V_84 ) ;
V_97 |= 1 << V_82 -> V_99 ;
if ( ! V_82 -> V_100 || ! V_82 -> V_101 ||
! ( V_96 & V_102 ) )
continue;
if ( F_48 )
F_48 ( V_2 , V_82 ) ;
}
}
return V_97 ;
}
int F_50 ( struct V_1 * V_2 )
{
struct V_81 * V_103 ;
int V_104 = 0 ;
int V_105 ;
F_41 (s, &bus->stream_list, list) {
V_105 = V_2 -> V_106 -> V_107 ( V_2 , V_108 ,
V_109 , & V_103 -> V_110 ) ;
V_104 ++ ;
if ( V_105 < 0 )
return - V_111 ;
}
if ( F_51 ( ! V_104 ) )
return - V_112 ;
V_105 = V_2 -> V_106 -> V_107 ( V_2 , V_108 ,
V_104 * 8 , & V_2 -> V_92 ) ;
if ( V_105 < 0 )
return - V_111 ;
F_41 (s, &bus->stream_list, list)
V_103 -> V_92 = ( V_12 * ) ( V_2 -> V_92 . V_13 + V_103 -> V_99 * 8 ) ;
return V_2 -> V_106 -> V_107 ( V_2 , V_108 ,
V_113 , & V_2 -> V_10 ) ;
}
void F_52 ( struct V_1 * V_2 )
{
struct V_81 * V_103 ;
F_41 (s, &bus->stream_list, list) {
if ( V_103 -> V_110 . V_13 )
V_2 -> V_106 -> V_114 ( V_2 , & V_103 -> V_110 ) ;
}
if ( V_2 -> V_10 . V_13 )
V_2 -> V_106 -> V_114 ( V_2 , & V_2 -> V_10 ) ;
if ( V_2 -> V_92 . V_13 )
V_2 -> V_106 -> V_114 ( V_2 , & V_2 -> V_92 ) ;
}
