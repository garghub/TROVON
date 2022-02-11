static inline struct V_1 *
F_1 ( int V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ )
if ( V_5 [ V_3 ] . V_6 )
if ( V_5 [ V_3 ] . V_6 -> V_7 == V_2 )
return ( V_5 [ V_3 ] . V_6 ) ;
return (struct V_1 * ) 0 ;
}
static inline void
F_2 ( struct V_8 * V_9 , int V_10 )
{
T_1 V_11 ;
V_11 . V_12 = V_9 -> V_6 -> V_7 ;
V_11 . V_10 = V_10 ;
V_11 . V_13 = V_9 -> V_14 ;
V_9 -> V_6 -> V_15 . V_16 ( & V_11 ) ;
}
static inline void
F_3 ( struct V_8 * V_9 )
{
T_1 V_11 ;
if ( ! V_9 -> V_17 )
return;
if ( V_9 -> V_17 -> V_18 . V_19 == V_20 )
return;
V_11 . V_12 = V_9 -> V_6 -> V_7 ;
V_11 . V_10 = V_21 ;
V_11 . V_13 = V_9 -> V_14 ;
if ( V_9 -> V_6 -> V_22 == V_23 )
sprintf ( V_11 . V_24 . V_25 , L_1 , V_9 -> V_17 -> V_18 . V_26 & 0x7f ,
V_9 -> V_17 -> V_18 . V_19 & 0x7f ) ;
else
sprintf ( V_11 . V_24 . V_25 , L_2 , V_9 -> V_17 -> V_18 . V_26 & 0x7f ,
V_9 -> V_17 -> V_18 . V_19 & 0x7f ) ;
V_9 -> V_6 -> V_15 . V_16 ( & V_11 ) ;
}
static inline void
F_4 ( struct V_27 * V_28 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
F_5 ( V_28 , V_30 ) ;
V_9 -> V_31 = 0 ;
V_9 -> V_6 -> V_32 ( V_9 -> V_6 , V_33 , ( void * ) ( long ) V_9 -> V_14 ) ;
}
static void
F_6 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
T_1 V_11 ;
int V_35 ;
if ( ! V_9 -> V_36 )
return;
V_9 -> V_6 -> V_32 ( V_9 -> V_6 , V_37 , ( void * ) ( long ) V_9 -> V_14 ) ;
F_5 ( V_28 , V_38 ) ;
if ( V_9 -> V_39 & 1 )
F_7 ( V_9 , 0 , L_3 ) ;
V_11 . V_12 = V_9 -> V_6 -> V_7 ;
V_11 . V_10 = ( ( V_9 -> V_14 < 2 ) ? V_40 : V_41 ) ;
V_11 . V_13 = V_9 -> V_14 ;
V_11 . V_24 . V_42 . V_43 = 7 ;
V_11 . V_24 . V_42 . V_44 = 0 ;
V_11 . V_24 . V_42 . V_45 = 0 ;
V_11 . V_24 . V_42 . V_46 = 0 ;
sprintf ( V_11 . V_24 . V_42 . V_47 , L_4 , V_9 -> V_14 + 1 ) ;
sprintf ( V_11 . V_24 . V_42 . V_48 , L_5 , V_9 -> V_6 -> V_7 ) ;
V_35 = V_9 -> V_6 -> V_15 . V_16 ( & V_11 ) ;
if ( V_9 -> V_39 & 1 )
F_7 ( V_9 , 1 , L_6 , V_35 ) ;
if ( ! V_35 ) {
V_9 -> V_6 -> V_32 ( V_9 -> V_6 , V_33 , ( void * ) ( long ) V_9 -> V_14 ) ;
F_5 ( V_28 , V_30 ) ;
}
}
static void
F_8 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
F_5 ( V_28 , V_49 ) ;
if ( V_9 -> V_39 & 1 )
F_7 ( V_9 , 0 , L_7 ) ;
F_2 ( V_9 , V_50 ) ;
F_9 ( V_9 , 0 ) ;
V_9 -> V_51 -> V_52 . V_53 ( V_9 -> V_51 , V_54 | V_55 , NULL ) ;
}
static void
F_10 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
F_11 ( & V_9 -> V_56 , 60 ) ;
F_11 ( & V_9 -> V_57 , 73 ) ;
V_9 -> V_58 = V_9 -> V_59 ;
V_9 -> V_60 = 0 ;
V_9 -> V_6 -> V_32 ( V_9 -> V_6 , V_37 , ( void * ) ( long ) V_9 -> V_14 ) ;
if ( V_9 -> V_36 ) {
F_8 ( V_28 , V_34 , V_13 ) ;
} else {
F_5 ( V_28 , V_61 ) ;
V_9 -> V_62 -> V_52 . V_53 ( V_9 -> V_62 , V_63 | V_55 , V_9 ) ;
}
}
static void
F_12 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
F_11 ( & V_9 -> V_56 , 60 ) ;
F_11 ( & V_9 -> V_57 , 73 ) ;
V_9 -> V_58 = V_9 -> V_59 ;
V_9 -> V_60 = 0 ;
V_9 -> V_6 -> V_32 ( V_9 -> V_6 , V_37 , ( void * ) ( long ) V_9 -> V_14 ) ;
if ( V_9 -> V_36 ) {
F_8 ( V_28 , V_34 , V_13 ) ;
} else {
F_5 ( V_28 , V_61 ) ;
V_9 -> V_62 -> V_52 . V_53 ( V_9 -> V_62 , V_64 | V_55 , V_9 ) ;
}
}
static void
F_13 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
T_1 V_11 ;
F_5 ( V_28 , V_65 ) ;
V_9 -> V_66 = ! 0 ;
if ( V_9 -> V_67 -> V_68 )
strcpy ( V_11 . V_24 . V_25 , V_9 -> V_67 -> V_68 ) ;
else
V_11 . V_24 . V_25 [ 0 ] = 0 ;
if ( V_9 -> V_39 & 1 )
F_7 ( V_9 , 0 , L_8 , V_11 . V_24 . V_25 ) ;
V_11 . V_12 = V_9 -> V_6 -> V_7 ;
V_11 . V_10 = V_69 ;
V_11 . V_13 = V_9 -> V_14 ;
V_9 -> V_6 -> V_15 . V_16 ( & V_11 ) ;
V_9 -> V_6 -> V_32 ( V_9 -> V_6 , V_70 , ( void * ) ( long ) V_9 -> V_14 ) ;
}
static void
F_14 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
T_1 V_11 ;
int V_35 ;
V_9 -> V_6 -> V_32 ( V_9 -> V_6 , V_37 , ( void * ) ( long ) V_9 -> V_14 ) ;
if ( 1 ) {
F_5 ( V_28 , V_38 ) ;
if ( V_9 -> V_39 & 1 )
F_7 ( V_9 , 0 , ( V_9 -> V_14 < 2 ) ? L_9 : L_10 ) ;
V_11 . V_12 = V_9 -> V_6 -> V_7 ;
V_11 . V_10 = ( ( V_9 -> V_14 < 2 ) ? V_40 : V_41 ) ;
V_11 . V_13 = V_9 -> V_14 ;
memcpy ( & V_11 . V_24 . V_42 , & V_9 -> V_17 -> V_18 . V_42 , sizeof( V_71 ) ) ;
V_35 = V_9 -> V_6 -> V_15 . V_16 ( & V_11 ) ;
if ( V_9 -> V_39 & 1 )
F_7 ( V_9 , 1 , L_6 , V_35 ) ;
switch ( V_35 ) {
case 1 :
F_11 ( & V_9 -> V_56 , 61 ) ;
F_5 ( V_28 , V_72 ) ;
V_9 -> V_62 -> V_52 . V_53 ( V_9 -> V_62 , V_73 | V_55 , V_9 -> V_17 ) ;
break;
case 5 :
case 4 :
F_11 ( & V_9 -> V_56 , 61 ) ;
F_5 ( V_28 , V_74 ) ;
V_9 -> V_62 -> V_52 . V_53 ( V_9 -> V_62 , V_75 | V_55 , V_9 -> V_17 ) ;
if ( V_35 == 5 ) {
memcpy ( & V_9 -> V_42 , & V_11 . V_24 . V_42 , sizeof( V_71 ) ) ;
V_9 -> V_62 -> V_52 . V_53 ( V_9 -> V_62 , V_76 | V_55 , V_9 -> V_17 ) ;
}
break;
case 2 :
break;
case 3 :
F_11 ( & V_9 -> V_56 , 61 ) ;
V_9 -> V_62 -> V_52 . V_53 ( V_9 -> V_62 , V_77 | V_55 , V_9 -> V_17 ) ;
break;
case 0 :
default:
V_9 -> V_62 -> V_52 . V_53 ( V_9 -> V_62 , V_78 | V_55 , V_9 -> V_17 ) ;
V_9 -> V_6 -> V_32 ( V_9 -> V_6 , V_33 , ( void * ) ( long ) V_9 -> V_14 ) ;
F_5 ( V_28 , V_30 ) ;
break;
}
} else {
V_9 -> V_62 -> V_52 . V_53 ( V_9 -> V_62 , V_78 | V_55 , V_9 -> V_17 ) ;
V_9 -> V_6 -> V_32 ( V_9 -> V_6 , V_33 , ( void * ) ( long ) V_9 -> V_14 ) ;
}
}
static void
F_15 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
F_5 ( V_28 , V_79 ) ;
V_9 -> V_62 -> V_52 . V_53 ( V_9 -> V_62 , V_63 | V_80 , V_9 -> V_17 ) ;
}
static void
F_16 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
F_5 ( V_28 , V_72 ) ;
V_9 -> V_62 -> V_52 . V_53 ( V_9 -> V_62 , V_73 | V_55 , V_9 -> V_17 ) ;
}
static void
F_17 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
V_9 -> V_62 -> V_52 . V_53 ( V_9 -> V_62 , V_76 | V_55 , V_9 -> V_17 ) ;
}
static void
F_18 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
F_5 ( V_28 , V_49 ) ;
if ( V_9 -> V_39 & 1 )
F_7 ( V_9 , 0 , L_7 ) ;
F_2 ( V_9 , V_50 ) ;
V_9 -> V_58 = V_9 -> V_59 ;
V_9 -> V_60 = ! 0 ;
F_9 ( V_9 , ! 0 ) ;
V_9 -> V_51 -> V_52 . V_53 ( V_9 -> V_51 , V_54 | V_55 , NULL ) ;
}
static void
F_19 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
if ( V_9 -> V_36 ) {
F_18 ( V_28 , V_34 , V_13 ) ;
} else {
F_5 ( V_28 , V_79 ) ;
#ifdef F_20
V_9 -> V_62 -> V_52 . V_53 ( V_9 -> V_62 , V_73 | V_55 , V_9 -> V_17 ) ;
#endif
V_9 -> V_62 -> V_52 . V_53 ( V_9 -> V_62 , V_63 | V_80 , V_9 -> V_17 ) ;
}
}
static void
F_21 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
V_9 -> V_62 -> V_52 . V_53 ( V_9 -> V_62 , V_81 | V_55 , V_9 -> V_17 ) ;
}
static void
F_22 ( struct V_27 * V_28 , struct V_8 * V_9 )
{
T_1 V_11 ;
V_11 . V_12 = V_9 -> V_6 -> V_7 ;
V_11 . V_10 = V_21 ;
V_11 . V_13 = V_9 -> V_14 ;
sprintf ( V_11 . V_24 . V_25 , L_11 ) ;
V_9 -> V_6 -> V_15 . V_16 ( & V_11 ) ;
if ( V_9 -> V_39 & 1 )
F_7 ( V_9 , 0 , L_12 ) ;
F_2 ( V_9 , V_82 ) ;
F_4 ( V_28 ) ;
}
static void
F_23 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
if ( V_9 -> V_36 ) {
F_22 ( V_28 , V_9 ) ;
} else {
F_5 ( V_28 , V_83 ) ;
if ( V_9 -> V_17 )
V_9 -> V_17 -> V_18 . V_19 = 0x10 ;
V_9 -> V_62 -> V_52 . V_53 ( V_9 -> V_62 , V_84 | V_55 ,
V_9 -> V_17 ) ;
}
}
static void
F_24 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
if ( V_9 -> V_36 ) {
F_22 ( V_28 , V_9 ) ;
} else {
F_5 ( V_28 , V_83 ) ;
if ( V_9 -> V_17 )
V_9 -> V_17 -> V_18 . V_19 = 0x15 ;
V_9 -> V_62 -> V_52 . V_53 ( V_9 -> V_62 , V_84 | V_55 ,
V_9 -> V_17 ) ;
}
}
static void
F_25 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
if ( V_9 -> V_36 ) {
F_22 ( V_28 , V_9 ) ;
} else {
if ( V_9 -> V_39 & 1 )
F_7 ( V_9 , 0 , L_12 ) ;
F_3 ( V_9 ) ;
F_2 ( V_9 , V_82 ) ;
F_4 ( V_28 ) ;
}
}
static void
F_26 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
if ( V_9 -> V_36 ) {
F_22 ( V_28 , V_9 ) ;
return;
}
#ifndef F_27
if ( V_9 -> V_17 )
V_9 -> V_17 -> V_18 . V_19 = 0x15 ;
V_9 -> V_62 -> V_52 . V_53 ( V_9 -> V_62 , V_85 | V_55 , V_9 -> V_17 ) ;
F_25 ( V_28 , V_34 , V_13 ) ;
#else
F_28 ( & V_9 -> V_56 , 40 , V_86 , NULL , 63 ) ;
F_5 ( V_28 , V_72 ) ;
V_9 -> V_62 -> V_52 . V_53 ( V_9 -> V_62 , V_73 | V_55 , V_9 -> V_17 ) ;
#endif
}
static void
F_29 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
V_9 -> V_66 = 0 ;
F_5 ( V_28 , V_87 ) ;
V_9 -> V_51 -> V_52 . V_53 ( V_9 -> V_51 , V_88 | V_55 , NULL ) ;
}
static void
F_30 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
if ( V_9 -> V_36 ) {
F_22 ( V_28 , V_9 ) ;
} else {
F_23 ( V_28 , V_34 , V_13 ) ;
}
}
static void
F_31 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
F_32 ( V_9 ) ;
F_30 ( V_28 , V_34 , V_13 ) ;
}
static void
F_33 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
if ( V_9 -> V_39 & 1 )
F_7 ( V_9 , 0 , L_13 ) ;
F_2 ( V_9 , V_89 ) ;
F_31 ( V_28 , V_34 , V_13 ) ;
}
static void
F_34 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
F_5 ( V_28 , V_90 ) ;
V_9 -> V_66 = 0 ;
if ( V_9 -> V_39 & 1 )
F_7 ( V_9 , 0 , L_13 ) ;
F_2 ( V_9 , V_89 ) ;
F_32 ( V_9 ) ;
}
static void
F_35 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
V_9 -> V_66 = 0 ;
F_5 ( V_28 , V_91 ) ;
V_9 -> V_51 -> V_52 . V_53 ( V_9 -> V_51 , V_88 | V_55 , NULL ) ;
}
static void
F_36 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
F_32 ( V_9 ) ;
F_25 ( V_28 , V_34 , V_13 ) ;
}
static void
F_37 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
if ( V_9 -> V_39 & 1 )
F_7 ( V_9 , 0 , L_13 ) ;
F_2 ( V_9 , V_89 ) ;
F_36 ( V_28 , V_34 , V_13 ) ;
}
static void
F_38 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
V_9 -> V_66 = 0 ;
V_9 -> V_51 -> V_52 . V_53 ( V_9 -> V_51 , V_88 | V_55 , NULL ) ;
F_37 ( V_28 , V_34 , V_13 ) ;
}
static void
F_39 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
if ( V_9 -> V_36 ) {
F_22 ( V_28 , V_9 ) ;
} else {
F_5 ( V_28 , V_92 ) ;
V_9 -> V_62 -> V_52 . V_53 ( V_9 -> V_62 , V_93 | V_55 ,
V_9 -> V_17 ) ;
}
}
static void
F_40 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
F_32 ( V_9 ) ;
F_39 ( V_28 , V_34 , V_13 ) ;
}
static void
F_41 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
if ( V_9 -> V_39 & 1 )
F_7 ( V_9 , 0 , L_13 ) ;
F_2 ( V_9 , V_89 ) ;
F_40 ( V_28 , V_34 , V_13 ) ;
}
static void
F_42 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
T_1 V_11 ;
V_11 . V_12 = V_9 -> V_6 -> V_7 ;
V_11 . V_10 = V_94 ;
V_11 . V_13 = V_9 -> V_14 ;
sprintf ( V_11 . V_24 . V_25 , L_4 , V_9 -> V_17 -> V_18 . V_95 ) ;
V_9 -> V_6 -> V_15 . V_16 ( & V_11 ) ;
}
static void
F_43 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
if ( V_9 -> V_39 & 1 )
F_7 ( V_9 , 0 , L_12 ) ;
F_2 ( V_9 , V_82 ) ;
}
static void
F_44 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
if ( V_9 -> V_39 & 1 )
F_7 ( V_9 , 0 , L_12 ) ;
F_2 ( V_9 , V_82 ) ;
F_4 ( V_28 ) ;
}
static void
F_45 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
F_5 ( V_28 , V_83 ) ;
}
static void
F_46 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
T_1 V_11 ;
F_5 ( V_28 , V_30 ) ;
V_11 . V_12 = V_9 -> V_6 -> V_7 ;
V_11 . V_10 = V_21 ;
V_11 . V_13 = V_9 -> V_14 ;
sprintf ( V_11 . V_24 . V_25 , L_14 , 0 , 0x2f ) ;
V_9 -> V_6 -> V_15 . V_16 ( & V_11 ) ;
F_2 ( V_9 , V_82 ) ;
V_9 -> V_31 = 0 ;
V_9 -> V_6 -> V_32 ( V_9 -> V_6 , V_33 , ( void * ) ( long ) V_9 -> V_14 ) ;
}
static void
F_47 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
F_32 ( V_9 ) ;
F_46 ( V_28 , V_34 , V_13 ) ;
}
static void
F_48 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
if ( V_9 -> V_39 & 1 )
F_7 ( V_9 , 0 , L_13 ) ;
F_2 ( V_9 , V_89 ) ;
F_47 ( V_28 , V_34 , V_13 ) ;
}
static void
F_49 ( struct V_27 * V_28 , int V_34 , void * V_13 )
{
struct V_8 * V_9 = V_28 -> V_29 ;
V_9 -> V_66 = 0 ;
V_9 -> V_51 -> V_52 . V_53 ( V_9 -> V_51 , V_88 | V_55 , NULL ) ;
F_48 ( V_28 , V_34 , V_13 ) ;
}
int T_2
F_50 ( void )
{
V_96 . V_97 = V_98 ;
V_96 . V_99 = V_100 ;
V_96 . V_101 = V_101 ;
V_96 . V_102 = V_102 ;
return F_51 ( & V_96 , V_103 , F_52 ( V_103 ) ) ;
}
void
F_53 ( void )
{
F_54 ( & V_96 ) ;
}
static void
F_32 ( struct V_8 * V_9 )
{
struct V_104 * V_105 = V_9 -> V_51 ;
if ( F_55 ( V_106 , & V_9 -> V_31 ) ) {
V_9 -> V_67 -> V_107 ( V_9 -> V_67 ) ;
switch ( V_9 -> V_58 ) {
case ( V_108 ) :
F_56 ( V_105 ) ;
break;
case ( V_109 ) :
case ( V_110 ) :
case ( V_111 ) :
case ( V_112 ) :
case ( V_113 ) :
F_57 ( V_105 ) ;
break;
}
}
}
static struct V_8
* F_58 ( struct V_104 * V_105 , int V_114 )
{
struct V_1 * V_6 = V_105 -> V_115 . V_116 ;
struct V_8 * V_9 = V_105 -> V_52 . V_29 ;
int V_3 ;
if ( F_59 ( V_117 , & V_6 -> V_118 ) )
V_3 = 1 ;
else
V_3 = 0 ;
if ( ! V_114 ) {
V_3 = 2 ;
V_9 += 2 ;
}
while ( V_3 < ( ( V_114 ) ? V_6 -> V_119 : ( 2 + V_120 ) ) ) {
if ( V_9 -> V_28 . V_121 == V_30 )
return ( V_9 ) ;
V_9 ++ ;
V_3 ++ ;
}
if ( V_114 ) {
V_3 = 2 ;
V_9 = V_105 -> V_52 . V_29 ;
V_9 += V_3 ;
while ( V_3 < ( 2 + V_120 ) ) {
if ( V_9 -> V_28 . V_121 == V_30 )
return ( V_9 ) ;
V_9 ++ ;
V_3 ++ ;
}
}
return ( NULL ) ;
}
static void F_60 ( struct V_1 * V_6 , int V_14 , T_3 V_122 )
{ T_1 V_11 ;
V_11 . V_12 = V_6 -> V_7 ;
V_11 . V_10 = V_123 ;
V_11 . V_13 = V_14 ;
V_11 . V_24 . V_25 [ 0 ] = V_122 ;
V_6 -> V_15 . V_16 ( & V_11 ) ;
}
static void
F_61 ( struct V_104 * V_105 , int V_124 , void * V_13 )
{
struct V_125 * V_126 = V_13 ;
struct V_1 * V_6 = V_105 -> V_115 . V_116 ;
struct V_8 * V_9 ;
if ( ! V_126 )
return;
if ( V_124 == ( V_63 | V_127 ) ) {
if ( ! ( V_9 = F_58 ( V_126 -> V_105 , V_126 -> V_18 . V_128 ) ) ) {
V_126 -> V_18 . V_19 = 0x11 ;
V_126 -> V_105 -> V_52 . V_53 ( V_126 -> V_105 , V_85 | V_55 , V_126 ) ;
} else {
V_9 -> V_17 = V_126 ;
V_126 -> V_14 = V_9 ;
F_62 ( & V_9 -> V_28 , V_129 , NULL ) ;
}
return;
}
if ( ! ( V_9 = V_126 -> V_14 ) )
return;
switch ( V_124 ) {
case ( V_77 | V_127 ) :
F_62 ( & V_9 -> V_28 , V_129 , NULL ) ;
break;
case ( V_84 | V_127 ) :
F_62 ( & V_9 -> V_28 , V_130 , NULL ) ;
break;
case ( V_93 | V_131 ) :
F_62 ( & V_9 -> V_28 , V_132 , NULL ) ;
break;
case ( V_81 | V_131 ) :
F_62 ( & V_9 -> V_28 , V_132 , NULL ) ;
break;
case ( V_64 | V_131 ) :
F_62 ( & V_9 -> V_28 , V_133 , NULL ) ;
break;
case ( V_134 ) :
F_62 ( & V_9 -> V_28 , V_132 , NULL ) ;
break;
case ( V_93 | V_127 ) :
F_62 ( & V_9 -> V_28 , V_132 , NULL ) ;
break;
case ( V_135 | V_127 ) :
F_62 ( & V_9 -> V_28 , V_136 , NULL ) ;
break;
case ( V_63 | V_131 ) :
F_62 ( & V_9 -> V_28 , V_133 , NULL ) ;
break;
case ( V_137 | V_127 ) :
F_62 ( & V_9 -> V_28 , V_138 , NULL ) ;
break;
case ( V_139 ) :
F_62 ( & V_9 -> V_28 , V_140 , NULL ) ;
break;
case ( V_141 ) :
F_62 ( & V_9 -> V_28 , V_142 , NULL ) ;
break;
case ( V_143 ) :
F_62 ( & V_9 -> V_28 , V_144 , NULL ) ;
break;
case ( V_145 ) :
F_62 ( & V_9 -> V_28 , V_132 , NULL ) ;
break;
case ( V_75 | V_127 ) :
case ( V_146 | V_127 ) :
case ( V_73 | V_127 ) :
case ( V_147 | V_127 ) :
case ( V_148 | V_127 ) :
break;
case ( V_76 | V_127 ) :
F_60 ( V_6 , V_9 -> V_14 , V_126 -> V_149 ) ;
break;
default:
if ( V_9 -> V_39 & 0x800 ) {
F_63 ( V_9 -> V_6 , L_15 ,
L_16 ,
V_9 -> V_14 , V_124 ) ;
}
}
}
static void
F_64 ( struct V_104 * V_105 , int V_124 , void * V_13 ) {
F_65 ( V_150 L_17 , V_124 , ( long ) V_13 ) ;
}
static int
F_66 ( struct V_104 * * V_151 ) {
* V_151 = F_67 ( sizeof( struct V_104 ) , V_152 ) ;
if ( ! * V_151 )
return - V_153 ;
( * V_151 ) -> V_154 = NULL ;
( * V_151 ) -> V_115 . V_155 = F_64 ;
( * V_151 ) -> V_115 . V_156 = F_64 ;
( * V_151 ) -> V_115 . V_157 = F_64 ;
( * V_151 ) -> V_158 . V_159 = F_64 ;
( * V_151 ) -> V_158 . V_160 = F_64 ;
( * V_151 ) -> V_158 . V_161 = F_64 ;
( * V_151 ) -> V_162 . V_163 = F_64 ;
( * V_151 ) -> V_162 . V_164 = F_64 ;
( * V_151 ) -> V_162 . V_165 = F_64 ;
( * V_151 ) -> V_52 . V_53 = F_64 ;
( * V_151 ) -> V_166 . V_167 = F_64 ;
return 0 ;
}
static int
F_68 ( struct V_8 * V_9 )
{
struct V_104 * V_105 ;
struct V_1 * V_6 = V_9 -> V_6 ;
char V_168 [ 16 ] ;
int V_169 ;
V_169 = F_66 ( & V_9 -> V_62 ) ;
if ( V_169 )
return V_169 ;
V_105 = V_9 -> V_62 ;
V_105 -> V_154 = NULL ;
F_69 ( V_6 , V_105 ) ;
F_70 ( V_105 , V_6 ) ;
V_105 -> V_158 . V_170 = 0 ;
V_105 -> V_158 . V_171 = - 1 ;
V_105 -> V_158 . V_172 = 0 ;
F_71 ( V_173 , & V_105 -> V_158 . V_172 ) ;
F_71 ( V_174 , & V_105 -> V_158 . V_172 ) ;
F_71 ( V_175 , & V_105 -> V_158 . V_172 ) ;
V_105 -> V_158 . V_176 = V_177 ;
V_105 -> V_158 . V_178 = 1 ;
V_105 -> V_158 . V_179 = 1000 ;
V_105 -> V_158 . V_180 = 3 ;
V_105 -> V_158 . V_181 = 10000 ;
if ( F_59 ( V_117 , & V_6 -> V_118 ) )
sprintf ( V_168 , L_18 , V_9 -> V_14 ) ;
else
sprintf ( V_168 , L_19 ) ;
F_72 ( V_105 , V_168 ) ;
F_73 ( V_105 , V_9 ) ;
V_105 -> V_52 . V_29 = V_9 ;
V_105 -> V_162 . V_165 = F_61 ;
return 0 ;
}
static void
F_74 ( struct V_8 * V_9 )
{
struct V_104 * V_105 = V_9 -> V_62 ;
if ( ! V_105 )
return;
F_56 ( V_105 ) ;
F_75 ( V_105 ) ;
F_76 ( V_105 -> V_115 . V_116 , V_105 ) ;
F_77 ( V_105 ) ;
V_9 -> V_62 = NULL ;
}
void
F_78 ( struct V_1 * V_182 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
F_11 ( & V_182 -> V_183 [ V_3 ] . V_56 , 74 ) ;
F_11 ( & V_182 -> V_183 [ V_3 ] . V_57 , 75 ) ;
if ( V_3 || F_59 ( V_117 , & V_182 -> V_118 ) )
F_74 ( V_182 -> V_183 + V_3 ) ;
if ( V_182 -> V_183 [ V_3 ] . V_51 ) {
F_32 ( V_182 -> V_183 + V_3 ) ;
F_77 ( V_182 -> V_183 [ V_3 ] . V_51 ) ;
V_182 -> V_183 [ V_3 ] . V_51 = NULL ;
} else
F_65 ( V_150 L_20 , V_3 ) ;
if ( V_3 || F_59 ( V_117 , & V_182 -> V_118 ) ) {
F_74 ( V_182 -> V_183 + V_3 ) ;
} else
V_182 -> V_183 [ V_3 ] . V_62 = NULL ;
}
}
static void
F_79 ( struct V_104 * V_105 , int V_124 , void * V_13 )
{
struct V_8 * V_9 = (struct V_8 * ) V_105 -> V_52 . V_29 ;
struct V_184 * V_185 = V_13 ;
switch ( V_124 ) {
case ( V_186 | V_127 ) :
if ( V_9 -> V_66 ) {
if ( V_9 -> V_39 & 0x800 )
F_7 ( V_9 , 0 , L_21 , V_185 -> V_187 ) ;
V_9 -> V_6 -> V_15 . V_188 ( V_9 -> V_6 -> V_7 , V_9 -> V_14 , V_185 ) ;
} else {
F_7 ( V_9 , 0 , L_22 ) ;
F_80 ( V_185 ) ;
}
break;
case ( V_54 | V_127 ) :
case ( V_54 | V_131 ) :
F_62 ( & V_9 -> V_28 , V_189 , NULL ) ;
break;
case ( V_88 | V_127 ) :
case ( V_88 | V_131 ) :
F_62 ( & V_9 -> V_28 , V_190 , NULL ) ;
break;
default:
F_65 ( V_150 L_23 ,
V_124 ) ;
break;
}
}
static void
F_81 ( struct V_104 * V_105 , int V_124 , void * V_13 )
{
struct V_8 * V_9 = (struct V_8 * ) V_105 -> V_52 . V_29 ;
struct V_184 * V_185 = V_13 ;
switch ( V_124 ) {
case ( V_191 | V_127 ) :
if ( V_9 -> V_66 ) {
if ( V_9 -> V_39 & 0x800 )
F_7 ( V_9 , 0 , L_24 , V_185 -> V_187 ) ;
V_9 -> V_6 -> V_15 . V_188 ( V_9 -> V_6 -> V_7 , V_9 -> V_14 , V_185 ) ;
} else {
F_7 ( V_9 , 0 , L_25 ) ;
F_80 ( V_185 ) ;
}
break;
case ( V_192 | V_127 ) :
case ( V_192 | V_131 ) :
F_62 ( & V_9 -> V_28 , V_189 , NULL ) ;
break;
case ( V_193 | V_127 ) :
case ( V_193 | V_131 ) :
F_62 ( & V_9 -> V_28 , V_190 , NULL ) ;
break;
default:
F_65 ( V_150 L_26 ,
V_124 ) ;
break;
}
}
void
F_82 ( struct V_104 * V_105 , int V_187 )
{
struct V_8 * V_9 = V_105 -> V_52 . V_29 ;
T_1 V_11 ;
if ( V_9 -> V_39 & 0x800 )
F_7 ( V_9 , 0 , L_27 , V_187 ) ;
V_11 . V_12 = V_9 -> V_6 -> V_7 ;
V_11 . V_10 = V_194 ;
V_11 . V_13 = V_9 -> V_14 ;
V_11 . V_24 . V_195 = V_187 ;
V_9 -> V_6 -> V_15 . V_16 ( & V_11 ) ;
}
static int
F_9 ( struct V_8 * V_9 , int V_60 )
{
struct V_104 * V_105 = V_9 -> V_51 ;
struct V_1 * V_6 = V_9 -> V_6 ;
char V_168 [ 16 ] ;
V_105 -> V_115 . V_116 = V_6 ;
if ( V_9 -> V_36 )
V_105 -> V_115 . V_196 = V_9 -> V_14 & 1 ;
else
V_105 -> V_115 . V_196 = V_9 -> V_17 -> V_18 . V_128 - 1 ;
switch ( V_9 -> V_58 ) {
case ( V_108 ) :
case ( V_109 ) :
V_105 -> V_115 . V_197 = V_198 ;
break;
case ( V_110 ) :
V_105 -> V_115 . V_197 = V_199 ;
break;
case ( V_111 ) :
V_105 -> V_115 . V_197 = V_200 ;
break;
case ( V_112 ) :
V_105 -> V_115 . V_197 = V_201 ;
break;
case ( V_113 ) :
V_105 -> V_115 . V_197 = V_202 ;
break;
}
V_9 -> V_67 -> V_68 = NULL ;
if ( V_9 -> V_67 -> V_203 ( V_105 , V_9 -> V_67 ) )
return ( - 1 ) ;
V_105 -> V_158 . V_172 = 0 ;
F_71 ( V_204 , & V_105 -> V_158 . V_172 ) ;
V_105 -> V_158 . V_176 = V_205 ;
if ( ! V_60 )
F_71 ( V_175 , & V_105 -> V_158 . V_172 ) ;
V_105 -> V_158 . V_179 = 1000 ;
V_105 -> V_158 . V_178 = 7 ;
V_105 -> V_158 . V_180 = 4 ;
V_105 -> V_158 . V_181 = 5000 ;
V_105 -> V_162 . V_39 = 0 ;
switch ( V_9 -> V_58 ) {
case ( V_108 ) :
sprintf ( V_168 , L_28 , V_9 -> V_14 ) ;
F_72 ( V_105 , V_168 ) ;
F_83 ( V_105 , V_9 ) ;
V_105 -> V_158 . V_161 = F_79 ;
V_105 -> V_52 . V_29 = V_9 ;
F_55 ( V_206 , & V_105 -> V_52 . V_172 ) ;
F_71 ( V_207 , & V_105 -> V_52 . V_172 ) ;
V_105 -> V_158 . V_208 . V_39 = V_9 -> V_39 & 16 ;
V_105 -> V_158 . V_39 = V_9 -> V_39 & 64 ;
break;
case ( V_109 ) :
case ( V_110 ) :
case ( V_111 ) :
case ( V_112 ) :
case ( V_113 ) :
V_105 -> V_115 . V_155 = F_81 ;
V_105 -> V_52 . V_29 = V_9 ;
F_71 ( V_206 , & V_105 -> V_52 . V_172 ) ;
F_55 ( V_207 , & V_105 -> V_52 . V_172 ) ;
F_84 ( V_105 ) ;
F_83 ( V_105 , V_9 ) ;
break;
}
F_71 ( V_106 , & V_9 -> V_31 ) ;
return ( 0 ) ;
}
static void
F_85 ( struct V_104 * V_105 , int V_124 , void * V_13 )
{
struct V_8 * V_9 = (struct V_8 * ) V_105 -> V_52 . V_29 ;
struct V_184 * V_185 = V_13 ;
switch ( V_124 ) {
case ( V_186 | V_55 ) :
F_7 ( V_9 , 0 , L_29 ) ;
F_80 ( V_185 ) ;
break;
case ( V_54 | V_55 ) :
V_105 -> V_158 . V_160 ( V_105 , V_192 | V_55 , NULL ) ;
break;
case ( V_88 | V_55 ) :
break;
default:
F_65 ( V_150 L_30 ,
V_124 ) ;
break;
}
}
static void
F_86 ( struct V_104 * V_105 , int V_124 , void * V_13 )
{
struct V_8 * V_9 = (struct V_8 * ) V_105 -> V_52 . V_29 ;
struct V_184 * V_185 = V_13 ;
int V_3 , V_34 = V_209 ;
switch ( V_124 ) {
case ( V_191 | V_127 ) :
F_7 ( V_9 , 0 , L_29 ) ;
F_80 ( V_185 ) ;
break;
case ( V_192 | V_127 ) :
case ( V_192 | V_131 ) :
V_34 = V_210 ;
case ( V_193 | V_127 ) :
case ( V_193 | V_131 ) :
if ( F_59 ( V_117 , & V_9 -> V_6 -> V_118 ) )
V_3 = 1 ;
else
V_3 = 0 ;
while ( V_3 < 2 ) {
F_62 ( & V_9 -> V_28 , V_34 , NULL ) ;
V_9 ++ ;
V_3 ++ ;
}
break;
default:
F_65 ( V_150
L_31 , V_124 ) ;
break;
}
}
static void
F_87 ( struct V_1 * V_182 , int V_211 )
{
int V_3 ;
struct V_8 * V_9 = V_182 -> V_183 ;
for ( V_3 = 0 ; V_3 < ( 2 + V_120 ) ; V_3 ++ ) {
V_9 [ V_3 ] . V_39 = V_211 ;
V_9 [ V_3 ] . V_28 . V_39 = V_211 & 2 ;
V_9 [ V_3 ] . V_62 -> V_158 . V_208 . V_39 = V_211 & 8 ;
V_9 [ V_3 ] . V_51 -> V_158 . V_208 . V_39 = V_211 & 0x10 ;
V_9 [ V_3 ] . V_62 -> V_158 . V_39 = V_211 & 0x20 ;
V_9 [ V_3 ] . V_51 -> V_158 . V_39 = V_211 & 0x40 ;
V_9 [ V_3 ] . V_62 -> V_162 . V_212 . V_39 = V_211 & 0x80 ;
V_9 [ V_3 ] . V_51 -> V_162 . V_212 . V_39 = V_211 & 0x100 ;
V_9 [ V_3 ] . V_51 -> V_166 . V_213 . V_39 = V_211 & 0x200 ;
V_9 [ V_3 ] . V_51 -> V_166 . V_39 = V_211 & 0x200 ;
V_9 [ V_3 ] . V_62 -> V_115 . V_214 . V_39 = V_211 & 0x1000 ;
V_9 [ V_3 ] . V_51 -> V_115 . V_214 . V_39 = V_211 & 0x2000 ;
}
if ( V_211 & 4 )
V_182 -> V_39 |= V_215 ;
else
V_182 -> V_39 &= ~ V_215 ;
}
static void
F_88 ( struct V_8 * V_9 , T_4 * V_216 )
{
char * V_217 = V_218 ;
V_217 += F_89 ( V_217 , ( V_219 * ) V_216 , ( V_216 -> V_220 > 50 ) ? 50 : V_216 -> V_220 ) ;
V_217 -- ;
* V_217 = 0 ;
F_63 ( V_9 -> V_6 , L_15 , L_32 , V_9 -> V_14 , V_218 ) ;
}
static void
F_90 ( struct V_8 * V_9 , T_4 * V_216 ) {
if ( ( V_216 -> V_18 [ 0 ] != 3 ) || ( V_216 -> V_18 [ 1 ] != 0 ) )
return;
if ( V_216 -> V_18 [ 2 ] < 3 )
return;
if ( V_216 -> V_18 [ 4 ] != 0 )
return;
switch ( V_216 -> V_18 [ 3 ] ) {
case 4 :
strncpy ( V_9 -> V_42 . V_48 , & V_216 -> V_18 [ 5 ] , V_216 -> V_18 [ 5 ] + 1 ) ;
F_62 ( & V_9 -> V_28 , V_221 , V_216 ) ;
break;
case 5 :
strncpy ( V_9 -> V_42 . V_48 , & V_216 -> V_18 [ 5 ] , V_216 -> V_18 [ 5 ] + 1 ) ;
if ( V_9 -> V_28 . V_121 == V_30 ) {
F_62 ( & V_9 -> V_28 , V_222 , V_216 ) ;
} else {
F_11 ( & V_9 -> V_57 , 72 ) ;
F_91 ( & V_9 -> V_57 , 80 , V_222 , V_216 , 73 ) ;
}
break;
}
}
static void
F_92 ( struct V_8 * V_9 , struct V_1 * V_6 , T_4 * V_216 ) {
if ( ( V_6 -> V_223 == V_224 ) || ( V_6 -> V_223 == V_225 ) ||
( V_6 -> V_223 == V_226 ) ) {
if ( V_6 -> V_227 . V_228 . V_229 ) {
V_6 -> V_32 ( V_6 , V_230 , V_216 -> V_18 ) ;
}
}
}
static int
F_93 ( struct V_1 * V_6 , int V_231 )
{
T_1 V_11 ;
int V_3 , V_232 ;
if ( ( V_231 < 0 ) || ( V_231 > 2 ) )
return ( - V_233 ) ;
V_6 -> V_119 = 0 ;
for ( V_232 = 0 ; V_232 < 2 ; V_232 ++ ) {
V_11 . V_12 = V_6 -> V_7 ;
V_11 . V_10 = V_234 ;
V_11 . V_13 = V_232 ;
if ( V_232 >= V_231 )
V_11 . V_24 . V_25 [ 0 ] = 0 ;
else
V_11 . V_24 . V_25 [ 0 ] = 1 ;
V_3 = V_6 -> V_15 . V_16 ( & V_11 ) ;
if ( V_3 ) return ( - V_233 ) ;
if ( V_232 < V_231 )
V_6 -> V_119 ++ ;
}
return ( 0 ) ;
}
int
F_94 ( T_1 * V_11 )
{
struct V_1 * V_182 = F_1 ( V_11 -> V_12 ) ;
struct V_104 * V_105 ;
struct V_8 * V_9 ;
int V_3 ;
T_5 V_25 ;
if ( ! V_182 ) {
F_65 ( V_235
L_33 ,
V_11 -> V_10 , V_11 -> V_12 ) ;
return - V_236 ;
}
switch ( V_11 -> V_10 ) {
case ( V_237 ) :
V_9 = V_182 -> V_183 + V_11 -> V_13 ;
break;
case ( V_238 ) :
V_9 = V_182 -> V_183 + ( V_11 -> V_13 & 0xff ) ;
if ( V_9 -> V_39 & 1 )
F_7 ( V_9 , 1 , L_34 ,
V_182 -> V_239 + 1 , V_11 -> V_13 >> 8 ) ;
V_9 -> V_59 = V_11 -> V_13 >> 8 ;
break;
case ( V_240 ) :
V_9 = V_182 -> V_183 + ( V_11 -> V_13 & 0xff ) ;
if ( V_9 -> V_39 & 1 )
F_7 ( V_9 , 1 , L_35 ,
V_182 -> V_239 + 1 , V_11 -> V_13 >> 8 ) ;
V_9 -> V_241 = V_11 -> V_13 >> 8 ;
break;
case ( V_242 ) :
V_9 = V_182 -> V_183 + ( V_11 -> V_13 & 0xff ) ;
if ( V_9 -> V_39 & 1 )
F_7 ( V_9 , 1 , L_36 ,
V_11 -> V_24 . V_42 . V_47 , V_11 -> V_24 . V_42 . V_48 ,
V_11 -> V_24 . V_42 . V_43 , V_11 -> V_24 . V_42 . V_44 ) ;
memcpy ( & V_9 -> V_42 , & V_11 -> V_24 . V_42 , sizeof( V_71 ) ) ;
if ( ! strcmp ( V_9 -> V_42 . V_47 , L_37 ) )
V_9 -> V_42 . V_47 [ 0 ] = '\0' ;
if ( V_9 -> V_28 . V_121 == V_30 ) {
F_62 ( & V_9 -> V_28 , V_243 , NULL ) ;
} else {
F_11 ( & V_9 -> V_57 , 70 ) ;
F_91 ( & V_9 -> V_57 , 50 , V_243 , NULL , 71 ) ;
}
break;
case ( V_244 ) :
V_9 = V_182 -> V_183 + V_11 -> V_13 ;
if ( V_9 -> V_39 & 1 )
F_7 ( V_9 , 1 , L_38 ) ;
F_62 ( & V_9 -> V_28 , V_245 , NULL ) ;
break;
case ( V_246 ) :
V_9 = V_182 -> V_183 + V_11 -> V_13 ;
memcpy ( & V_9 -> V_42 , & V_11 -> V_24 . V_42 , sizeof( V_71 ) ) ;
if ( V_9 -> V_39 & 1 )
F_7 ( V_9 , 1 , L_39 ) ;
F_62 ( & V_9 -> V_28 , V_247 , NULL ) ;
break;
case ( V_248 ) :
V_9 = V_182 -> V_183 + V_11 -> V_13 ;
if ( V_9 -> V_39 & 1 )
F_7 ( V_9 , 1 , L_40 ) ;
F_62 ( & V_9 -> V_28 , V_86 , NULL ) ;
break;
case ( V_249 ) :
V_9 = V_182 -> V_183 + V_11 -> V_13 ;
if ( V_9 -> V_39 & 1 )
F_88 ( V_9 , & V_11 -> V_24 . V_250 ) ;
if ( V_11 -> V_24 . V_250 . V_220 < 8 )
break;
switch ( V_11 -> V_24 . V_250 . V_251 ) {
case V_252 :
if ( V_11 -> V_24 . V_250 . V_253 == V_254 )
F_90 ( V_9 , & V_11 -> V_24 . V_250 ) ;
break;
case V_255 :
if ( V_11 -> V_24 . V_250 . V_253 == V_254 )
F_92 ( V_9 , V_182 , & V_11 -> V_24 . V_250 ) ;
break;
default:
break;
}
break;
case ( V_256 ) :
switch ( V_11 -> V_13 ) {
case ( 0 ) :
V_25 = * ( unsigned int * ) V_11 -> V_24 . V_25 ;
F_95 ( V_182 -> V_239 , V_25 ) ;
break;
case ( 1 ) :
V_25 = * ( unsigned int * ) V_11 -> V_24 . V_25 ;
F_87 ( V_182 , V_25 ) ;
F_65 ( V_257 L_41 ,
V_182 -> V_239 + 1 , V_25 ) ;
F_63 ( V_182 , L_42 ,
L_43 , V_182 -> V_239 + 1 , V_25 ) ;
break;
case ( 2 ) :
V_25 = * ( unsigned int * ) V_11 -> V_24 . V_25 ;
V_182 -> V_183 [ 0 ] . V_51 -> V_115 . V_258 = V_25 ;
V_182 -> V_183 [ 1 ] . V_51 -> V_115 . V_258 = V_25 ;
F_63 ( V_182 , L_44 , L_45 ,
V_182 -> V_239 + 1 , V_25 ) ;
F_65 ( V_257 L_46 ,
V_182 -> V_239 + 1 , V_25 ) ;
break;
case ( 5 ) :
V_25 = * ( unsigned int * ) V_11 -> V_24 . V_25 ;
if ( ( V_25 < 1 ) || ( V_25 > 2 ) ) {
F_63 ( V_182 , L_47 ,
L_48 , V_25 ) ;
F_65 ( V_150 L_49 ,
V_25 ) ;
} else {
V_25 -- ;
V_9 = V_182 -> V_183 + V_25 ;
V_9 -> V_36 = 1 ;
F_63 ( V_182 , L_50 ,
L_51 ,
V_182 -> V_239 + 1 , V_25 + 1 ) ;
V_9 -> V_62 -> V_115 . V_155 = F_86 ;
V_9 -> V_62 -> V_52 . V_53 = F_85 ;
V_9 -> V_62 -> V_52 . V_53 ( V_9 -> V_62 ,
V_54 | V_55 , NULL ) ;
}
break;
case ( 6 ) :
V_25 = * ( unsigned int * ) V_11 -> V_24 . V_25 ;
if ( V_182 -> V_259 )
V_182 -> V_259 -> V_158 . V_160 ( V_182 -> V_259 ,
V_260 | V_55 , ( void * ) ( long ) V_25 ) ;
break;
case ( 7 ) :
V_25 = * ( unsigned int * ) V_11 -> V_24 . V_25 ;
if ( F_59 ( V_117 , & V_182 -> V_118 ) ) {
F_65 ( V_235 L_52 ) ;
} else if ( V_25 ) {
F_71 ( V_261 , & V_182 -> V_183 [ 0 ] . V_62 -> V_158 . V_172 ) ;
F_71 ( V_262 , & V_182 -> V_183 [ 0 ] . V_62 -> V_158 . V_172 ) ;
V_182 -> V_183 [ 0 ] . V_62 -> V_158 . V_171 = 0 ;
F_63 ( V_182 , L_53 , L_54 ) ;
F_65 ( V_257 L_55 ) ;
F_65 ( V_263 L_56 ) ;
V_182 -> V_183 [ 0 ] . V_62 -> V_52 . V_53 ( V_182 -> V_183 [ 0 ] . V_62 ,
V_54 | V_55 , NULL ) ;
} else {
F_55 ( V_261 , & V_182 -> V_183 [ 0 ] . V_62 -> V_158 . V_172 ) ;
F_55 ( V_262 , & V_182 -> V_183 [ 0 ] . V_62 -> V_158 . V_172 ) ;
F_63 ( V_182 , L_53 , L_57 ) ;
F_65 ( V_257 L_58 ) ;
}
break;
case ( 8 ) :
V_25 = * ( unsigned int * ) V_11 -> V_24 . V_25 ;
V_9 = V_182 -> V_183 + ( V_25 & 1 ) ;
V_25 = V_25 >> 1 ;
if ( V_25 == 127 ) {
F_55 ( V_262 , & V_9 -> V_62 -> V_158 . V_172 ) ;
V_9 -> V_62 -> V_158 . V_171 = - 1 ;
F_63 ( V_182 , L_53 , L_59 ) ;
F_65 ( V_257 L_60 ) ;
} else {
F_71 ( V_262 , & V_9 -> V_62 -> V_158 . V_172 ) ;
V_9 -> V_62 -> V_158 . V_171 = V_25 ;
F_63 ( V_182 , L_53 , L_61 , V_25 ) ;
F_65 ( V_257 L_62 ,
V_25 ) ;
}
V_9 -> V_62 -> V_52 . V_53 ( V_9 -> V_62 ,
V_54 | V_55 , NULL ) ;
break;
case ( 11 ) :
V_25 = V_182 -> V_39 & V_215 ;
V_182 -> V_39 = * ( unsigned int * ) V_11 -> V_24 . V_25 ;
V_182 -> V_39 |= V_25 ;
F_63 ( V_5 [ 0 ] . V_6 , L_63 ,
L_64 ,
V_182 -> V_239 + 1 , V_182 -> V_39 ) ;
F_65 ( V_257 L_65 ,
V_182 -> V_239 + 1 , V_182 -> V_39 ) ;
break;
case ( 13 ) :
V_182 -> V_183 [ 0 ] . V_62 -> V_162 . V_39 = * ( unsigned int * ) V_11 -> V_24 . V_25 ;
V_182 -> V_183 [ 1 ] . V_62 -> V_162 . V_39 = * ( unsigned int * ) V_11 -> V_24 . V_25 ;
F_63 ( V_5 [ 0 ] . V_6 , L_66 ,
L_67 , V_182 -> V_239 + 1 ,
* ( unsigned int * ) V_11 -> V_24 . V_25 ) ;
F_65 ( V_257 L_68 ,
V_182 -> V_239 + 1 , * ( unsigned int * ) V_11 -> V_24 . V_25 ) ;
break;
case ( 10 ) :
V_3 = * ( unsigned int * ) V_11 -> V_24 . V_25 ;
return ( F_93 ( V_182 , V_3 ) ) ;
default:
if ( V_182 -> V_264 )
return ( V_182 -> V_264 ( V_182 , V_11 ) ) ;
F_65 ( V_257 L_69 ,
( int ) V_11 -> V_13 ) ;
return ( - V_233 ) ;
}
break;
case ( V_265 ) :
V_9 = V_182 -> V_183 + V_11 -> V_13 ;
if ( V_9 -> V_39 & 1 )
F_7 ( V_9 , 1 , L_70 ) ;
F_62 ( & V_9 -> V_28 , V_266 , NULL ) ;
break;
case ( V_267 ) :
V_9 = V_182 -> V_183 + V_11 -> V_13 ;
if ( V_9 -> V_39 & 1 )
F_7 ( V_9 , 1 , L_71 ) ;
F_62 ( & V_9 -> V_28 , V_268 , NULL ) ;
break;
case ( V_269 ) :
V_9 = V_182 -> V_183 + V_11 -> V_13 ;
if ( V_9 -> V_39 & 1 )
F_7 ( V_9 , 1 , L_72 ) ;
memcpy ( & V_9 -> V_42 , & V_11 -> V_24 . V_42 , sizeof( V_71 ) ) ;
F_62 ( & V_9 -> V_28 , V_270 , NULL ) ;
break;
case ( V_271 ) :
for ( V_105 = V_182 -> V_259 ; V_105 ; V_105 = V_105 -> V_154 )
if ( V_105 -> V_22 == ( V_11 -> V_13 & 0xFF ) )
return ( V_105 -> V_52 . V_272 ( V_105 , V_11 ) ) ;
return ( - V_233 ) ;
break;
default:
if ( V_182 -> V_264 )
return ( V_182 -> V_264 ( V_182 , V_11 ) ) ;
return ( - V_233 ) ;
}
return ( 0 ) ;
}
int
F_96 ( int V_273 , int V_14 , int V_274 , struct V_184 * V_185 )
{
struct V_1 * V_182 = F_1 ( V_273 ) ;
struct V_8 * V_9 ;
struct V_104 * V_105 ;
int V_187 = V_185 -> V_187 ;
struct V_184 * V_275 ;
if ( ! V_182 ) {
F_65 ( V_235
L_73 ) ;
return - V_236 ;
}
V_9 = V_182 -> V_183 + V_14 ;
V_105 = V_9 -> V_51 ;
if ( ! V_9 -> V_66 ) {
F_7 ( V_9 , 1 , L_74 ) ;
return - V_276 ;
}
if ( V_187 > V_205 ) {
F_7 ( V_9 , 1 , L_75 , V_187 ) ;
F_65 ( V_150 L_76 ,
V_187 ) ;
return - V_233 ;
}
if ( V_187 ) {
if ( ( V_187 + V_9 -> V_67 -> V_277 ) > V_278 ) {
if ( V_9 -> V_39 & 0x800 )
F_7 ( V_9 , 1 , L_77 , V_187 ) ;
return 0 ;
} else if ( V_9 -> V_39 & 0x800 )
F_7 ( V_9 , 1 , L_78 , V_187 , V_9 -> V_67 -> V_277 , V_278 ) ;
V_275 = F_97 ( V_185 , V_152 ) ;
if ( V_275 ) {
V_275 -> V_279 = V_275 -> V_187 ;
if ( ! V_274 )
V_275 -> V_280 = V_281 ;
if ( V_9 -> V_58 == V_108 )
V_105 -> V_162 . V_163 ( V_105 , V_186 | V_55 , V_275 ) ;
else {
V_9 -> V_67 -> V_277 += V_187 ;
V_105 -> V_158 . V_160 ( V_105 , V_191 | V_55 , V_275 ) ;
}
F_80 ( V_185 ) ;
} else
V_187 = 0 ;
}
return ( V_187 ) ;
}
