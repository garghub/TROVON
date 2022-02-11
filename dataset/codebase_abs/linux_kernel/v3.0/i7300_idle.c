static int F_1 ( void )
{
T_1 V_1 ;
V_1 = F_2 ( V_2 + V_3 ) ;
if ( V_1 )
F_3 ( V_1 , V_2 + V_3 ) ;
F_4 ( V_4 , V_2 + V_5 ) ;
return 0 ;
}
static void F_5 ( void )
{
int V_6 ;
T_2 V_7 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ ) {
F_4 ( V_9 ,
V_2 + V_5 ) ;
F_6 ( 10 ) ;
V_7 = F_7 ( V_2 + V_10 ) &
V_11 ;
if ( V_7 != V_12 )
break;
}
if ( V_6 == V_8 ) {
F_8 ( L_1 ,
V_8 ) ;
}
}
static int T_3 F_9 ( T_4 * V_13 ,
struct V_14 * V_15 , unsigned long V_16 )
{
T_2 V_17 ;
memset ( V_15 , 0 , 2048 ) ;
memset ( ( T_4 * ) V_15 + 2048 , 0xab , 1024 ) ;
V_15 [ 0 ] . V_18 = 1024 ;
V_15 [ 0 ] . V_13 = 0 ;
V_15 [ 0 ] . V_19 = V_16 + 2048 ;
V_15 [ 0 ] . V_20 = V_16 + 1024 ;
V_15 [ 0 ] . V_21 = 0 ;
F_4 ( V_9 , V_2 + V_5 ) ;
F_4 ( V_4 , V_2 + V_5 ) ;
F_6 ( 1000 ) ;
V_17 = F_7 ( V_2 + V_10 ) &
V_11 ;
if ( V_17 != V_22 ) {
F_4 ( V_9 ,
V_2 + V_5 ) ;
return - 1 ;
}
if ( * ( T_1 * ) ( ( T_4 * ) V_15 + 3068 ) != 0xabababab ||
* ( T_1 * ) ( ( T_4 * ) V_15 + 2044 ) != 0xabababab ) {
F_8 ( L_2 ,
* ( T_1 * ) ( ( T_4 * ) V_15 + 2048 ) ,
* ( T_1 * ) ( ( T_4 * ) V_15 + 1024 ) ,
* ( T_1 * ) ( ( T_4 * ) V_15 + 3072 ) ) ;
return - 1 ;
}
return 0 ;
}
static int T_3 F_10 ( void )
{
T_4 V_23 , V_24 , V_25 ;
T_5 V_26 ;
V_27 = ( T_4 * ) F_11 ( F_12 ( V_28 , 0 ) ,
F_13 ( V_28 , 0 ) ) ;
if ( ! V_27 ) {
F_14 (KERN_ERR I7300_PRINT L_3 ) ;
goto V_29;
}
V_23 = F_15 ( V_27 + V_30 ) ;
if ( V_23 != V_31 ) {
F_14 (KERN_ERR I7300_PRINT L_4 ,
ver >> 4 , ver & 0xf ) ;
goto V_32;
}
V_24 = F_15 ( V_27 + V_33 ) ;
if ( ! V_24 ) {
F_14 (KERN_ERR I7300_PRINT L_5
L_6 ,
chan_count) ;
goto V_32;
}
V_25 = V_24 - 1 ;
V_2 = F_16 ( V_27 , V_25 ) ;
V_26 = F_17 ( V_2 + V_34 ) ;
if ( V_26 & V_35 ) {
F_14 (KERN_ERR I7300_PRINT L_7 , ioat_chan) ;
goto V_32;
}
F_18 ( V_35 ,
V_2 + V_34 ) ;
V_36 = (struct V_14 * ) F_19 (
& V_37 , 4096 ,
( V_38 * ) & V_39 , V_40 ) ;
if ( ! V_36 ) {
F_14 (KERN_ERR I7300_PRINT L_8 ) ;
goto V_41;
}
F_3 ( V_39 & 0xffffffffUL ,
V_2 + V_42 ) ;
F_3 ( V_39 >> 32 ,
V_2 + V_43 ) ;
if ( F_9 ( V_27 , V_36 , V_39 ) ) {
F_14 (KERN_ERR I7300_PRINT L_9 ) ;
goto V_44;
}
V_36 [ 0 ] . V_13 = V_45 | V_46 ;
V_36 [ 0 ] . V_19 = V_39 + 2048 ;
V_36 [ 0 ] . V_20 = V_39 + 3072 ;
V_36 [ 0 ] . V_18 = 128 ;
V_36 [ 0 ] . V_21 = V_39 + sizeof( struct V_14 ) ;
V_36 [ 1 ] . V_13 = V_36 [ 0 ] . V_13 ;
V_36 [ 1 ] . V_19 = V_36 [ 0 ] . V_19 ;
V_36 [ 1 ] . V_20 = V_36 [ 0 ] . V_20 ;
V_36 [ 1 ] . V_18 = V_36 [ 0 ] . V_18 ;
V_36 [ 1 ] . V_21 = V_39 ;
return 0 ;
V_44:
F_20 ( & V_37 , 4096 , ( void * ) V_36 , 0 ) ;
V_41:
F_18 ( 0 , V_2 + V_34 ) ;
V_32:
F_21 ( V_27 ) ;
V_29:
return - V_47 ;
}
static void T_6 F_22 ( void )
{
int V_6 ;
T_2 V_17 ;
F_5 () ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ ) {
F_4 ( V_9 ,
V_2 + V_5 ) ;
V_17 = F_7 ( V_2 + V_10 ) &
V_11 ;
if ( V_17 != V_12 ) {
F_18 ( 0 , V_2 + V_34 ) ;
break;
}
F_6 ( 1000 ) ;
}
V_17 = F_7 ( V_2 + V_10 ) &
V_11 ;
if ( V_17 == V_12 ) {
F_14 (KERN_ERR I7300_PRINT L_10
L_11 ) ;
return;
}
F_20 ( & V_37 , 4096 , ( void * ) V_36 , 0 ) ;
F_21 ( V_27 ) ;
}
static int F_23 ( void )
{
T_1 V_48 ;
T_4 V_49 ;
F_24 ( V_50 , V_51 , & V_52 ) ;
F_24 ( V_50 , V_53 , & V_54 ) ;
F_25 ( V_50 , V_55 , & V_56 ) ;
F_24 ( V_50 , V_57 , & V_49 ) ;
F_8 ( L_12 ,
V_52 ,
V_54 ) ;
F_8 ( L_13 ,
V_56 ,
V_49 ) ;
if ( V_49 == 0 ) {
V_48 = V_56 | V_58 ;
F_26 ( V_50 , V_55 , V_48 ) ;
return 0 ;
} else {
F_8 ( L_14 ) ;
return - V_47 ;
}
}
static void F_27 ( void )
{
F_26 ( V_50 , V_55 , V_56 ) ;
F_28 ( V_50 , V_53 , V_54 ) ;
F_28 ( V_50 , V_51 , V_52 ) ;
}
static void F_29 ( void )
{
T_4 V_59 ;
T_4 V_60 ;
V_59 = V_52 & ~ V_61 ;
F_28 ( V_50 , V_51 , V_59 ) ;
V_60 = V_62 ;
if ( F_30 ( V_60 > V_63 ) )
V_60 = V_63 ;
F_28 ( V_50 , V_53 , V_60 ) ;
V_59 = V_52 | V_61 ;
F_28 ( V_50 , V_51 , V_59 ) ;
}
static void F_31 ( void )
{
T_4 V_59 ;
T_4 V_64 ;
V_59 = V_52 & ~ V_61 ;
F_28 ( V_50 , V_51 , V_59 ) ;
F_28 ( V_50 , V_53 , V_54 ) ;
F_28 ( V_50 , V_51 , V_52 ) ;
F_24 ( V_50 , V_51 , & V_64 ) ;
F_32 ( V_64 != V_52 ) ;
}
static int F_33 ( void )
{
if ( V_65 >= V_66 )
return 0 ;
#ifdef F_34
V_67 ++ ;
#endif
return 1 ;
}
static int F_35 ( struct V_68 * V_69 , unsigned long V_70 ,
void * V_71 )
{
unsigned long V_72 ;
T_7 V_73 ;
static T_7 V_74 ;
static int V_75 = 1 ;
if ( ! V_62 )
return 0 ;
if ( F_30 ( V_75 ) ) {
V_75 = 0 ;
V_74 = F_36 () ;
}
F_37 ( & V_76 , V_72 ) ;
if ( V_70 == V_77 ) {
F_38 ( F_39 () , V_78 ) ;
if ( F_40 ( V_78 ) != F_41 () )
goto V_79;
V_73 = F_36 () ;
V_74 = V_73 ;
if ( F_33 () )
goto V_79;
V_80 = 1 ;
V_81 ++ ;
V_82 = V_73 ;
F_29 () ;
F_1 () ;
} else if ( V_70 == V_83 ) {
F_42 ( F_39 () , V_78 ) ;
if ( F_40 ( V_78 ) == ( F_41 () - 1 ) ) {
T_2 V_84 ;
V_73 = F_36 () ;
V_84 = F_43 ( F_44
( V_73 , V_74 ) ) ;
V_65 =
( ( 100 - V_85 ) * V_65 +
V_85 * V_84 ) / 100 ;
if ( V_80 ) {
T_7 V_86 ;
V_86 = F_44 ( V_73 , V_82 ) ;
V_87 += F_43 ( V_86 ) ;
F_5 () ;
F_31 () ;
V_80 = 0 ;
}
}
}
V_79:
F_45 ( & V_76 , V_72 ) ;
return 0 ;
}
int F_46 ( struct V_88 * V_88 , struct V_89 * V_90 )
{
V_90 -> V_91 = V_88 -> V_92 ;
return 0 ;
}
static T_8 F_47 ( struct V_89 * V_90 , char T_9 * V_93 , T_10 V_94 ,
T_11 * V_95 )
{
unsigned long * V_96 = V_90 -> V_91 ;
char V_97 [ 32 ] ;
int V_98 ;
V_98 = snprintf ( V_97 , 32 , L_15 , * V_96 ) ;
return F_48 ( V_93 , V_94 , V_95 , V_97 , V_98 ) ;
}
static int T_3 F_49 ( void )
{
F_50 ( & V_76 ) ;
V_87 = 0 ;
if ( F_51 ( & V_50 , & V_28 , V_99 ) )
return - V_47 ;
if ( F_23 () )
return - V_47 ;
if ( F_10 () )
return - V_47 ;
if ( ! F_52 ( & V_78 , V_40 ) )
return - V_100 ;
V_101 = F_53 ( L_16 , NULL ) ;
if ( V_101 ) {
int V_6 = 0 ;
while ( V_102 [ V_6 ] . V_103 != NULL ) {
V_102 [ V_6 ] . V_89 = F_54 (
V_102 [ V_6 ] . V_104 ,
V_105 ,
V_101 ,
V_102 [ V_6 ] . V_103 ,
& V_106 ) ;
V_6 ++ ;
}
}
F_55 ( & V_107 ) ;
F_14 ( V_108 L_17 , V_109 ) ;
return 0 ;
}
static void T_6 F_56 ( void )
{
F_57 ( & V_107 ) ;
F_58 ( V_78 ) ;
if ( V_101 ) {
int V_6 = 0 ;
while ( V_102 [ V_6 ] . V_89 != NULL ) {
F_59 ( V_102 [ V_6 ] . V_89 ) ;
V_6 ++ ;
}
F_59 ( V_101 ) ;
}
F_27 () ;
F_22 () ;
}
