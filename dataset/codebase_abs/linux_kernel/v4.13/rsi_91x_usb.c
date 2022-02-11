static int F_1 ( struct V_1 * V_2 ,
void * V_3 ,
T_1 V_4 ,
T_2 V_5 )
{
struct V_6 * V_7 = (struct V_6 * ) V_2 -> V_8 ;
int V_9 ;
T_3 V_10 ;
V_9 = F_2 ( V_7 -> V_11 ,
F_3 ( V_7 -> V_11 ,
V_7 -> V_12 [ V_5 - 1 ] ) ,
V_3 ,
V_4 ,
& V_10 ,
V_13 * 5 ) ;
if ( V_9 < 0 ) {
F_4 ( V_14 ,
L_1 , V_9 ) ;
V_7 -> V_15 = 1 ;
}
return V_9 ;
}
static int F_5 ( struct V_1 * V_2 ,
T_2 V_5 ,
T_2 * V_16 ,
T_4 V_17 )
{
struct V_6 * V_7 = (struct V_6 * ) V_2 -> V_8 ;
T_2 * V_18 = V_7 -> V_19 ;
if ( V_7 -> V_15 )
return 0 ;
if ( V_5 == V_20 ) {
memset ( V_18 , 0 , V_21 ) ;
memcpy ( V_18 + V_21 , V_16 , V_17 ) ;
} else {
V_18 = ( ( T_2 * ) V_16 - V_21 ) ;
}
return F_1 ( V_2 ,
V_18 ,
V_17 + V_21 ,
V_5 ) ;
}
static int F_6 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = (struct V_6 * ) V_2 -> V_8 ;
struct V_24 * V_25 ;
struct V_26 * V_5 ;
T_5 V_27 ;
int V_28 , V_29 = 0 ;
V_25 = & ( V_23 -> V_30 [ 0 ] ) ;
for ( V_28 = 0 ; V_28 < V_25 -> V_31 . V_32 ; ++ V_28 ) {
V_5 = & ( V_25 -> V_5 [ V_28 ] . V_31 ) ;
if ( ( ! ( V_7 -> V_33 ) ) &&
( V_5 -> V_34 & V_35 ) &&
( ( V_5 -> V_36 &
V_37 ) ==
V_38 ) ) {
V_27 = V_5 -> V_39 ;
V_7 -> V_40 = V_27 ;
V_7 -> V_33 =
V_5 -> V_34 ;
}
if ( ! V_7 -> V_12 [ V_29 ] &&
! ( V_5 -> V_34 & V_35 ) &&
( ( V_5 -> V_36 & V_37 ) ==
V_38 ) ) {
V_7 -> V_12 [ V_29 ] =
V_5 -> V_34 ;
V_27 = V_5 -> V_39 ;
V_7 -> V_41 [ V_29 ] = V_27 ;
V_29 ++ ;
}
if ( V_29 >= V_42 )
break;
}
if ( ! ( V_7 -> V_33 ) &&
( V_7 -> V_12 [ 0 ] ) )
return - V_43 ;
return 0 ;
}
static int F_7 ( struct V_44 * V_11 ,
T_4 V_45 ,
T_1 * V_46 ,
T_1 V_4 )
{
T_2 * V_3 ;
int V_9 = - V_47 ;
V_3 = F_8 ( 0x04 , V_48 ) ;
if ( ! V_3 )
return V_9 ;
V_9 = F_9 ( V_11 ,
F_10 ( V_11 , 0 ) ,
V_49 ,
V_50 ,
( ( V_45 & 0xffff0000 ) >> 16 ) , ( V_45 & 0xffff ) ,
( void * ) V_3 ,
V_4 ,
V_51 ) ;
* V_46 = ( V_3 [ 0 ] | ( V_3 [ 1 ] << 8 ) ) ;
if ( V_9 < 0 ) {
F_4 ( V_14 ,
L_2 ,
V_52 , V_9 ) ;
}
F_11 ( V_3 ) ;
return V_9 ;
}
static int F_12 ( struct V_44 * V_11 ,
T_4 V_45 ,
T_1 V_46 ,
T_1 V_4 )
{
T_2 * V_53 ;
int V_9 = - V_47 ;
V_53 = F_8 ( 0x04 , V_48 ) ;
if ( ! V_53 )
return V_9 ;
V_53 [ 0 ] = ( V_46 & 0x00ff ) ;
V_53 [ 1 ] = ( V_46 & 0xff00 ) >> 8 ;
V_53 [ 2 ] = 0x0 ;
V_53 [ 3 ] = 0x0 ;
V_9 = F_9 ( V_11 ,
F_13 ( V_11 , 0 ) ,
V_54 ,
V_55 ,
( ( V_45 & 0xffff0000 ) >> 16 ) ,
( V_45 & 0xffff ) ,
( void * ) V_53 ,
V_4 ,
V_56 ) ;
if ( V_9 < 0 ) {
F_4 ( V_14 ,
L_3 ,
V_52 , V_9 ) ;
}
F_11 ( V_53 ) ;
return V_9 ;
}
static void F_14 ( struct V_57 * V_57 )
{
struct V_1 * V_2 = V_57 -> V_58 ;
struct V_6 * V_7 = (struct V_6 * ) V_2 -> V_8 ;
if ( V_57 -> V_9 )
return;
F_15 ( & V_7 -> V_59 . V_60 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = (struct V_6 * ) V_2 -> V_8 ;
struct V_57 * V_57 = V_7 -> V_61 [ 0 ] ;
int V_9 ;
F_17 ( V_57 ,
V_7 -> V_11 ,
F_18 ( V_7 -> V_11 ,
V_7 -> V_33 ) ,
V_57 -> V_62 ,
3000 ,
F_14 ,
V_2 ) ;
V_9 = F_19 ( V_57 , V_48 ) ;
if ( V_9 )
F_4 ( V_14 , L_4 , V_52 ) ;
return V_9 ;
}
static int F_20 ( struct V_1 * V_2 , T_4 V_63 ,
T_2 * V_16 , T_1 V_17 )
{
struct V_6 * V_7 = (struct V_6 * ) V_2 -> V_8 ;
T_2 * V_3 ;
T_1 V_10 ;
int V_9 ;
if ( ! V_63 )
return - V_43 ;
V_3 = F_21 ( V_64 , V_48 ) ;
if ( ! V_3 )
return - V_47 ;
while ( V_17 ) {
V_10 = F_22 ( T_1 , V_17 , V_64 ) ;
V_9 = F_9 ( V_7 -> V_11 ,
F_10 ( V_7 -> V_11 , 0 ) ,
V_49 ,
V_50 ,
( ( V_63 & 0xffff0000 ) >> 16 ) ,
( V_63 & 0xffff ) , ( void * ) V_3 ,
V_10 , V_51 ) ;
if ( V_9 < 0 ) {
F_4 ( V_14 ,
L_5 ,
V_9 ) ;
F_11 ( V_3 ) ;
return V_9 ;
}
memcpy ( V_16 , V_3 , V_10 ) ;
V_17 -= V_10 ;
V_16 += V_10 ;
V_63 += V_10 ;
}
F_11 ( V_3 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , T_4 V_63 ,
T_2 * V_16 , T_1 V_17 )
{
struct V_6 * V_7 = (struct V_6 * ) V_2 -> V_8 ;
T_2 * V_3 ;
T_1 V_10 ;
int V_9 = 0 ;
V_3 = F_21 ( V_64 , V_48 ) ;
if ( ! V_3 )
return - V_47 ;
while ( V_17 ) {
V_10 = F_22 ( T_1 , V_17 , V_64 ) ;
memcpy ( V_3 , V_16 , V_10 ) ;
V_9 = F_9 ( V_7 -> V_11 ,
F_13 ( V_7 -> V_11 , 0 ) ,
V_54 ,
V_55 ,
( ( V_63 & 0xffff0000 ) >> 16 ) ,
( V_63 & 0xffff ) ,
( void * ) V_3 ,
V_10 ,
V_56 ) ;
if ( V_9 < 0 ) {
F_4 ( V_14 ,
L_6 ,
V_9 ) ;
F_11 ( V_3 ) ;
return V_9 ;
}
V_17 -= V_10 ;
V_16 += V_10 ;
V_63 += V_10 ;
}
F_11 ( V_3 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
T_2 * V_65 ,
T_4 V_4 )
{
T_4 V_66 = ( ( V_65 [ 1 ] >> 4 ) & 0xf ) ;
T_2 V_5 ;
V_5 = ( ( V_66 == V_67 ) ? V_20 : V_68 ) ;
return F_5 ( V_2 ,
V_5 ,
( T_2 * ) V_65 ,
V_4 ) ;
}
static int F_25 ( struct V_1 * V_2 , T_4 V_45 ,
T_4 * V_46 , T_1 V_4 )
{
struct V_44 * V_11 =
( (struct V_6 * ) V_2 -> V_8 ) -> V_11 ;
return F_7 ( V_11 , V_45 , ( T_1 * ) V_46 , V_4 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
unsigned long V_45 ,
unsigned long V_46 , T_1 V_4 )
{
struct V_44 * V_11 =
( (struct V_6 * ) V_2 -> V_8 ) -> V_11 ;
return F_12 ( V_11 , V_45 , V_46 , V_4 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
T_4 V_69 ,
T_4 V_70 , T_1 V_71 ,
T_2 * V_72 )
{
T_1 V_73 ;
T_4 V_74 , V_75 ;
T_2 V_76 [ 256 ] ;
int V_9 ;
V_73 = V_70 / V_71 ;
F_4 ( V_77 , L_7 , V_73 ) ;
for ( V_74 = 0 , V_75 = 0 ; V_75 < V_73 ; V_75 ++ , V_74 += V_71 ) {
memset ( V_76 , 0 , V_71 ) ;
memcpy ( V_76 , V_72 + V_74 , V_71 ) ;
V_9 = F_23 ( V_2 , V_69 ,
( T_2 * ) ( V_76 ) ,
V_71 ) ;
if ( V_9 < 0 )
return V_9 ;
F_4 ( V_77 , L_8 , V_52 , V_75 ) ;
V_69 += V_71 ;
}
if ( V_70 % V_71 ) {
memset ( V_76 , 0 , V_71 ) ;
memcpy ( V_76 , V_72 + V_74 ,
V_70 % V_71 ) ;
V_9 = F_23
( V_2 , V_69 ,
( T_2 * ) V_76 ,
V_70 % V_71 ) ;
if ( V_9 < 0 )
return V_9 ;
F_4 ( V_77 ,
L_9 ,
V_74 ) ;
}
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = (struct V_6 * ) V_2 -> V_8 ;
F_29 ( & V_7 -> V_59 ) ;
F_30 ( V_7 -> V_61 [ 0 ] ) ;
F_11 ( V_2 -> V_78 -> V_79 ) ;
F_11 ( V_7 -> V_19 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_22 * V_80 )
{
struct V_6 * V_8 ;
struct V_81 * V_82 = V_2 -> V_78 ;
int V_9 ;
V_8 = F_21 ( sizeof( * V_8 ) , V_48 ) ;
if ( ! V_8 )
return - V_47 ;
V_2 -> V_8 = V_8 ;
V_8 -> V_11 = F_32 ( V_80 ) ;
if ( F_6 ( V_80 , V_2 ) )
return - V_43 ;
V_2 -> V_83 = & V_80 -> V_7 ;
F_33 ( V_80 , V_2 ) ;
V_82 -> V_79 = F_8 ( 2048 , V_48 ) ;
if ( ! V_82 -> V_79 ) {
F_4 ( V_14 , L_10 ,
V_52 ) ;
return - V_47 ;
}
V_8 -> V_19 = F_8 ( 2048 , V_48 ) ;
if ( ! V_8 -> V_19 ) {
V_9 = - V_47 ;
goto V_84;
}
V_8 -> V_61 [ 0 ] = F_34 ( 0 , V_48 ) ;
if ( ! V_8 -> V_61 [ 0 ] ) {
V_9 = - V_47 ;
goto V_85;
}
V_8 -> V_61 [ 0 ] -> V_62 = V_2 -> V_78 -> V_79 ;
V_8 -> V_86 = 252 ;
V_2 -> V_71 = V_8 -> V_86 ;
V_2 -> V_87 = F_16 ;
V_2 -> V_88 = V_89 ;
V_2 -> V_90 = V_91 ;
V_2 -> V_92 = V_93 ;
V_2 -> V_94 = & V_95 ;
F_35 ( & V_8 -> V_59 . V_60 ) ;
V_9 = F_36 ( V_82 , & V_8 -> V_59 ,
V_96 , L_11 ) ;
if ( V_9 ) {
F_4 ( V_14 , L_12 , V_52 ) ;
goto V_97;
}
#ifdef F_37
V_2 -> V_98 = ( V_99 - 1 ) ;
#endif
F_4 ( V_100 , L_13 , V_52 ) ;
return 0 ;
V_97:
F_30 ( V_8 -> V_61 [ 0 ] ) ;
V_85:
F_11 ( V_8 -> V_19 ) ;
V_84:
F_11 ( V_82 -> V_79 ) ;
return V_9 ;
}
static int F_38 ( struct V_22 * V_80 ,
const struct V_101 * V_102 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
T_1 V_103 ;
int V_9 ;
F_4 ( V_100 , L_14 , V_52 ) ;
V_2 = F_39 () ;
if ( ! V_2 ) {
F_4 ( V_14 , L_15 ,
V_52 ) ;
return - V_47 ;
}
V_2 -> V_92 = V_93 ;
V_9 = F_31 ( V_2 , V_80 ) ;
if ( V_9 ) {
F_4 ( V_14 , L_16 ,
V_52 ) ;
goto V_104;
}
F_4 ( V_14 , L_17 , V_52 ) ;
V_7 = (struct V_6 * ) V_2 -> V_8 ;
V_9 = F_7 ( V_7 -> V_11 , V_105 , & V_103 , 2 ) ;
if ( V_9 < 0 )
goto V_106;
else
V_103 &= 1 ;
if ( ! V_103 ) {
F_4 ( V_100 , L_18 ) ;
V_9 = F_40 ( V_2 ) ;
if ( V_9 ) {
F_4 ( V_14 , L_19 ,
V_52 ) ;
goto V_106;
}
F_4 ( V_100 , L_20 , V_52 ) ;
}
V_9 = F_16 ( V_2 ) ;
if ( V_9 )
goto V_106;
return 0 ;
V_106:
F_28 ( V_2 ) ;
V_104:
F_41 ( V_2 ) ;
F_4 ( V_14 , L_21 , V_52 ) ;
return V_9 ;
}
static void F_42 ( struct V_22 * V_80 )
{
struct V_1 * V_2 = F_43 ( V_80 ) ;
if ( ! V_2 )
return;
F_44 ( V_2 ) ;
F_28 ( V_2 ) ;
F_41 ( V_2 ) ;
F_4 ( V_77 , L_22 , V_52 ) ;
}
static int F_45 ( struct V_22 * V_107 , T_6 V_108 )
{
return - V_109 ;
}
static int F_46 ( struct V_22 * V_107 )
{
return - V_109 ;
}
