static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
int V_8 ;
V_8 = F_2 ( V_7 , F_3 ( V_7 , 0 ) ,
0x32 , 0x40 , V_3 ? 0x01 : 0x00 , 0x00 , NULL , 0 , V_9 ) ;
if ( V_8 < 0 )
F_4 ( V_5 ,
L_1 ,
V_3 ? L_2 : L_3 , V_8 ) ;
else
F_5 ( L_4 , V_3 ? L_2 : L_3 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
unsigned char * V_10 = V_2 -> V_11 ;
int V_8 ;
V_10 [ 0 ] = 0x1c ;
V_10 [ 1 ] = 0x50 ;
V_8 = F_2 ( V_7 , F_3 ( V_7 , 0 ) ,
0x01 , 0x40 , 0x0b , 0x00 , V_10 , 2 , V_9 ) ;
if ( V_8 < 0 )
F_4 ( V_5 , L_5 , V_12 , V_8 ) ;
V_10 [ 0 ] = 0x32 ;
V_10 [ 1 ] = 0x00 ;
V_8 = F_2 ( V_7 , F_3 ( V_7 , 0 ) ,
0x01 , 0x40 , 0x02 , 0x00 , V_10 , 2 , V_9 ) ;
if ( V_8 < 0 )
F_4 ( V_5 , L_6 , V_12 , V_8 ) ;
V_10 [ 0 ] = 0x01 ;
V_10 [ 1 ] = 0x00 ;
V_10 [ 2 ] = 0x01 ;
V_8 = F_2 ( V_7 , F_3 ( V_7 , 0 ) ,
0x01 , 0x40 , 0x03 , 0x00 , V_10 , 3 , V_9 ) ;
if ( V_8 < 0 )
F_4 ( V_5 , L_7 , V_12 , V_8 ) ;
V_10 [ 0 ] = 0x01 ;
V_10 [ 1 ] = 0x00 ;
V_10 [ 2 ] = 0x01 ;
V_8 = F_2 ( V_7 , F_3 ( V_7 , 0 ) ,
0x01 , 0x40 , 0x04 , 0x00 , V_10 , 3 , V_9 ) ;
if ( V_8 < 0 )
F_4 ( V_5 , L_8 , V_12 , V_8 ) ;
V_10 [ 0 ] = V_2 -> V_13 . V_14 ;
V_8 = F_2 ( V_7 , F_3 ( V_7 , 0 ) ,
0x01 , 0x40 , 0x11 , 0x00 , V_10 , 1 , V_9 ) ;
if ( V_8 < 0 )
F_4 ( V_5 , L_9 , V_12 , V_8 ) ;
V_8 = F_2 ( V_7 , F_3 ( V_7 , 0 ) ,
0x01 , 0x40 , 0x14 , 0x00 ,
V_2 -> V_13 . V_15 ,
V_16 , V_9 ) ;
if ( V_8 < 0 )
F_4 ( V_5 , L_10 , V_12 , V_8 ) ;
V_10 [ 0 ] = V_2 -> V_13 . V_17 & 0xff ;
V_10 [ 1 ] = V_2 -> V_13 . V_17 >> 8 ;
V_8 = F_2 ( V_7 , F_3 ( V_7 , 0 ) ,
0x01 , 0x40 , 0x12 , 0x00 , V_10 , 2 , V_9 ) ;
if ( V_8 < 0 )
F_4 ( V_5 , L_11 , V_12 , V_8 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
const struct V_18 * V_19 ,
const struct V_18 * V_20 )
{
unsigned char * V_21 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
int V_22 ;
int V_8 = 0 ;
int V_23 ;
F_8 ( V_5 , L_12 , V_12 ) ;
if ( ! ( V_21 = ( unsigned char * ) F_9 ( V_24 ) ) ) {
V_8 = - V_25 ;
F_8 ( V_5 , L_13 , V_12 ) ;
goto V_26;
}
if ( ! F_10 ( V_7 , 2 ) ) {
V_8 = - V_27 ;
F_8 ( V_5 , L_14 , V_12 ) ;
goto V_28;
}
if ( V_29 ) {
V_8 = F_11 ( V_7 , F_12 ( V_7 , V_30 ) ,
V_21 , 0x200 , & V_22 , 2000 ) ;
if ( V_8 < 0 && V_8 != - V_31 )
F_4 ( V_5 , L_15 , V_12 , V_8 ) ;
else
F_8 ( V_5 , L_16 , V_12 , V_8 ) ;
}
for ( V_23 = 0 ; V_23 < V_19 -> V_32 ; V_23 += V_33 ) {
int V_34 = F_13 ( int , V_33 , V_19 -> V_32 - V_23 ) ;
memcpy ( V_21 , V_19 -> V_35 + V_23 , V_34 ) ;
V_8 = F_11 ( V_7 , F_14 ( V_7 , V_30 ) ,
V_21 , V_34 , & V_22 , V_36 ) ;
if ( V_8 < 0 ) {
F_15 ( V_5 , L_17 , V_12 , V_8 ) ;
goto V_28;
}
F_8 ( V_5 , L_18 , V_12 , V_19 -> V_32 ) ;
}
V_8 = F_11 ( V_7 , F_12 ( V_7 , V_30 ) ,
V_21 , 0x200 , & V_22 , V_36 ) ;
if ( V_8 < 0 ) {
F_15 ( V_5 , L_19 , V_12 , V_8 ) ;
goto V_28;
}
F_8 ( V_5 , L_20 , V_12 , V_22 ) ;
for ( V_23 = 0 ; V_23 < V_20 -> V_32 ; V_23 += V_33 ) {
int V_34 = F_13 ( int , V_33 , V_20 -> V_32 - V_23 ) ;
memcpy ( V_21 , V_20 -> V_35 + V_23 , V_34 ) ;
V_8 = F_11 ( V_7 , F_14 ( V_7 , V_30 ) ,
V_21 , V_34 , & V_22 , V_36 ) ;
if ( V_8 < 0 ) {
F_15 ( V_5 , L_21 , V_12 , V_8 ) ;
goto V_28;
}
}
F_8 ( V_5 , L_22 , V_12 , V_20 -> V_32 ) ;
V_8 = F_11 ( V_7 , F_12 ( V_7 , V_30 ) ,
V_21 , 0x200 , & V_22 , V_36 ) ;
if ( V_8 < 0 ) {
F_15 ( V_5 , L_23 , V_12 , V_8 ) ;
goto V_28;
}
F_8 ( V_5 , L_24 , V_12 , V_22 ) ;
F_16 ( 1000 ) ;
if ( ( V_8 = F_17 ( V_7 , V_37 , V_2 -> V_13 . V_38 ) ) < 0 ) {
F_15 ( V_5 , L_25 , V_12 , V_2 -> V_13 . V_38 , V_8 ) ;
goto V_28;
}
if ( V_39 )
F_1 ( V_2 , 1 ) ;
F_6 ( V_2 ) ;
V_8 = 0 ;
V_28:
F_18 ( ( unsigned long ) V_21 ) ;
V_26:
return V_8 ;
}
static int F_19 ( struct V_4 * V_5 , struct V_40 * V_41 ,
int V_42 , const struct V_18 * * V_43 )
{
struct V_44 * V_45 = & V_41 -> V_45 ;
const T_1 V_46 = F_20 ( F_21 ( V_41 ) -> V_47 . V_46 ) ;
const T_2 V_48 = V_46 >> 8 ;
const T_2 V_49 = V_46 & 0xff ;
char V_10 [ 24 ] ;
sprintf ( V_10 , L_26 , V_42 , V_48 , V_49 ) ;
F_8 ( V_5 , L_27 , V_12 , V_10 ) ;
if ( F_22 ( V_43 , V_10 , V_45 ) ) {
sprintf ( V_10 , L_28 , V_42 , V_48 ) ;
F_8 ( V_5 , L_27 , V_12 , V_10 ) ;
if ( F_22 ( V_43 , V_10 , V_45 ) ) {
sprintf ( V_10 , L_29 , V_42 ) ;
F_8 ( V_5 , L_27 , V_12 , V_10 ) ;
if ( F_22 ( V_43 , V_10 , V_45 ) ) {
F_15 ( V_5 , L_30 , V_12 , V_42 ) ;
return - V_50 ;
}
}
}
F_23 ( V_5 , L_31 , V_42 , V_10 ) ;
return 0 ;
}
static int F_24 ( struct V_4 * V_5 , struct V_40 * V_41 )
{
const struct V_18 * V_19 , * V_20 ;
struct V_1 * V_2 = V_5 -> V_51 ;
int V_8 ;
if ( ( V_8 = F_19 ( V_5 , V_41 , 1 , & V_19 ) ) < 0 )
return V_8 ;
if ( ( V_8 = F_19 ( V_5 , V_41 , 2 , & V_20 ) ) < 0 ) {
F_25 ( V_19 ) ;
return V_8 ;
}
if ( ( V_8 = F_7 ( V_2 , V_19 , V_20 ) ) < 0 )
F_15 ( V_5 , L_32 , V_12 , V_8 ) ;
F_25 ( V_20 ) ;
F_25 ( V_19 ) ;
return V_8 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
unsigned char * V_10 = V_2 -> V_11 ;
int V_8 ;
memset ( V_10 , 0 , 16 ) ;
V_8 = F_2 ( V_7 , F_27 ( V_7 , 0 ) ,
0x12 , 0xc0 , 0x07 , 0x00 , V_10 + V_52 , V_53 ,
V_9 ) ;
if ( V_8 < 0 ) {
F_28 ( V_5 , L_33 , V_12 ) ;
return V_8 ;
}
V_8 = F_2 ( V_7 , F_27 ( V_7 , 0 ) ,
0x12 , 0xc0 , 0x0b , 0x00 , V_10 + V_54 , V_55 ,
V_9 ) ;
if ( V_8 < 0 ) {
F_28 ( V_5 , L_34 , V_12 ) ;
return V_8 ;
}
V_8 = F_2 ( V_7 , F_27 ( V_7 , 0 ) ,
0x12 , 0xc0 , 0x0d , 0x00 , V_10 + V_56 , V_57 ,
V_9 ) ;
if ( V_8 < 0 ) {
F_28 ( V_5 , L_35 , V_12 ) ;
return V_8 ;
}
V_8 = F_2 ( V_7 , F_27 ( V_7 , 0 ) ,
0x01 , 0xc0 , 0x0e , 0x00 , V_10 + V_58 , V_59 ,
V_9 ) ;
if ( V_8 < 0 ) {
F_28 ( V_5 , L_36 , V_12 ) ;
return V_8 ;
}
V_8 = F_2 ( V_7 , F_27 ( V_7 , 0 ) ,
0x01 , 0xc0 , 0x0f , 0x00 , V_10 + V_60 , V_61 ,
V_9 ) ;
if ( V_8 < 0 ) {
F_28 ( V_5 , L_37 , V_12 ) ;
return V_8 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
unsigned char * V_10 = V_2 -> V_11 ;
int V_8 ;
F_28 ( V_5 , L_12 , V_12 ) ;
memset ( V_10 , 0 , 2 ) ;
V_8 = F_2 ( V_7 , F_27 ( V_7 , 0 ) ,
0x12 , 0xc0 , 0x04 , 0x00 ,
V_10 , 2 , V_9 ) ;
if ( V_8 < 0 )
F_30 ( V_5 , L_38 , V_8 ) ;
else
F_28 ( V_5 , L_39 ,
V_12 , V_8 , V_10 [ 0 ] , V_10 [ 1 ] ) ;
return V_8 ;
}
static void F_31 ( struct V_62 * V_63 )
{
struct V_1 * V_2 =
F_32 ( V_63 , struct V_1 ,
V_64 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_65 * V_65 = V_5 -> V_65 ;
unsigned char * V_10 = V_2 -> V_11 ;
int V_66 , V_67 , V_8 ;
unsigned char V_68 ;
#ifdef F_33
F_28 ( V_5 , L_12 , V_12 ) ;
#endif
V_8 = F_26 ( V_2 ) ;
if ( V_8 < 0 ) {
F_30 ( V_5 , L_40 , V_8 ) ;
V_2 -> V_69 = F_34 ( 2 * V_2 -> V_69 , V_70 ) ;
return;
}
V_2 -> V_69 = F_35 ( V_2 -> V_69 / 2 , V_71 ) ;
V_68 = V_10 [ V_52 ] ;
if ( ( V_68 != V_2 -> V_72 ) || ! V_68 ) {
F_28 ( V_5 , L_41 , V_12 , V_68 ) ;
switch ( V_68 ) {
case 0 :
F_36 ( V_65 , V_73 ) ;
if ( V_2 -> V_72 )
F_37 ( V_5 , L_42 ) ;
V_8 = F_29 ( V_2 ) ;
break;
case 0x08 :
F_36 ( V_65 , V_74 ) ;
F_37 ( V_5 , L_43 ) ;
break;
case 0x10 :
F_36 ( V_65 , V_73 ) ;
F_37 ( V_5 , L_44 ) ;
break;
case 0x20 :
V_66 = V_10 [ V_54 ] | ( V_10 [ V_54 + 1 ] << 8 )
| ( V_10 [ V_54 + 2 ] << 16 ) | ( V_10 [ V_54 + 3 ] << 24 ) ;
V_67 = V_10 [ V_54 + 4 ] | ( V_10 [ V_54 + 5 ] << 8 )
| ( V_10 [ V_54 + 6 ] << 16 ) | ( V_10 [ V_54 + 7 ] << 24 ) ;
if ( ! ( V_66 & 0x0000ffff ) && ! ( V_67 & 0x0000ffff ) ) {
V_66 >>= 16 ;
V_67 >>= 16 ;
}
V_65 -> V_75 = V_66 * 1000 / 424 ;
F_36 ( V_65 , V_76 ) ;
F_37 ( V_5 ,
L_45 ,
V_66 , V_67 ) ;
break;
default:
F_36 ( V_65 , V_74 ) ;
F_37 ( V_5 , L_46 , V_68 ) ;
break;
}
V_2 -> V_72 = V_68 ;
}
}
static void F_38 ( unsigned long V_35 )
{
struct V_1 * V_2 = ( void * ) V_35 ;
F_39 ( & V_2 -> V_64 ) ;
if ( V_2 -> V_69 < V_70 )
F_40 ( & V_2 -> V_77 , V_78 + F_41 ( V_2 -> V_69 ) ) ;
else
F_30 ( V_2 -> V_5 , L_47 ) ;
}
static void F_42 ( unsigned long V_35 )
{
struct V_1 * V_2 = ( void * ) V_35 ;
struct V_79 * V_80 = V_2 -> V_80 ;
int V_8 ;
F_28 ( V_2 -> V_5 , L_12 , V_12 ) ;
if ( V_80 ) {
V_8 = F_43 ( V_80 , V_81 ) ;
if ( ! V_8 )
F_39 ( & V_2 -> V_64 ) ;
else {
F_28 ( V_2 -> V_5 , L_48 , V_12 , V_8 ) ;
F_40 ( & V_2 -> V_82 , V_78 + F_41 ( V_83 ) ) ;
}
}
}
static void F_44 ( struct V_79 * V_80 )
{
struct V_1 * V_2 = V_80 -> V_84 ;
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_85 = V_80 -> V_22 ;
int V_68 = V_80 -> V_68 ;
int V_8 ;
static const unsigned char V_86 [ 6 ] = { 0xa1 , 0x00 , 0x01 , 0x00 , 0x00 , 0x00 } ;
static const unsigned char V_87 [ 6 ] = { 0xa1 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
F_28 ( V_5 , L_12 , V_12 ) ;
if ( V_68 < 0 ) {
F_28 ( V_5 , L_49 , V_12 , V_68 ) ;
goto V_88;
}
if ( ( V_85 == 6 ) && ! memcmp ( V_86 , V_2 -> V_89 , 6 ) ) {
F_45 ( & V_2 -> V_77 ) ;
F_37 ( V_5 , L_50 ) ;
} else if ( ( V_85 == 6 ) && ! memcmp ( V_87 , V_2 -> V_89 , 6 ) ) {
F_37 ( V_5 , L_51 ) ;
} else {
int V_90 ;
F_28 ( V_5 , L_52 , V_12 , V_85 ) ;
for ( V_90 = 0 ; V_90 < V_85 ; V_90 ++ )
F_46 ( L_53 , V_2 -> V_89 [ V_90 ] ) ;
F_46 ( L_54 ) ;
goto V_88;
}
if ( ( V_80 = V_2 -> V_80 ) ) {
V_8 = F_43 ( V_80 , V_81 ) ;
F_39 ( & V_2 -> V_64 ) ;
if ( V_8 < 0 ) {
F_28 ( V_5 , L_48 , V_12 , V_8 ) ;
goto V_88;
}
}
return;
V_88:
if ( ( V_80 = V_2 -> V_80 ) )
F_40 ( & V_2 -> V_82 , V_78 + F_41 ( V_83 ) ) ;
}
static int F_47 ( struct V_4 * V_5 , struct V_65 * V_65 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_1 * V_2 = V_5 -> V_51 ;
int V_90 , V_8 ;
unsigned char V_91 [ 13 ] ;
F_28 ( V_5 , L_12 , V_12 ) ;
memset ( V_65 -> V_92 , 0 , sizeof( V_65 -> V_92 ) ) ;
if ( F_48 ( V_7 , V_7 -> V_47 . V_93 , V_91 , sizeof( V_91 ) ) == 12 ) {
for ( V_90 = 0 ; V_90 < 6 ; V_90 ++ )
V_65 -> V_92 [ V_90 ] = ( F_49 ( V_91 [ V_90 * 2 ] ) << 4 ) +
F_49 ( V_91 [ V_90 * 2 + 1 ] ) ;
}
V_8 = F_29 ( V_2 ) ;
if ( V_2 -> V_80 ) {
V_8 = F_43 ( V_2 -> V_80 , V_24 ) ;
if ( V_8 < 0 ) {
F_28 ( V_5 , L_55 , V_12 , V_8 ) ;
F_50 ( V_2 -> V_80 ) ;
V_2 -> V_80 = NULL ;
}
}
F_40 ( & V_2 -> V_77 , V_78 + F_41 ( 1000 ) ) ;
return 0 ;
}
static void F_51 ( struct V_4 * V_5 , struct V_65 * V_65 )
{
struct V_1 * V_2 = V_5 -> V_51 ;
struct V_79 * V_80 = V_2 -> V_80 ;
F_28 ( V_5 , L_12 , V_12 ) ;
F_52 ( & V_2 -> V_77 ) ;
V_2 -> V_80 = NULL ;
F_53 () ;
F_54 ( V_80 ) ;
F_52 ( & V_2 -> V_82 ) ;
F_54 ( V_80 ) ;
F_52 ( & V_2 -> V_82 ) ;
F_50 ( V_80 ) ;
F_55 ( & V_2 -> V_64 ) ;
}
static int F_56 ( struct V_40 * V_41 )
{
return 0 ;
}
static int F_57 ( struct V_40 * V_41 )
{
return 0 ;
}
static void F_58 ( struct V_6 * V_7 ,
int V_94 )
{
struct V_40 * V_95 ;
int V_90 ;
for ( V_90 = 0 ; V_90 < V_94 ; V_90 ++ )
if ( ( V_95 = F_10 ( V_7 , V_90 ) ) ) {
F_59 ( V_95 , NULL ) ;
F_60 ( & V_96 , V_95 ) ;
}
}
static int F_61 ( struct V_4 * V_5 ,
struct V_40 * V_41 ,
const struct V_97 * V_98 )
{
struct V_6 * V_7 = F_21 ( V_41 ) ;
struct V_40 * V_95 , * V_99 ;
struct V_1 * V_2 ;
int V_100 = V_41 -> V_38 -> V_101 . V_102 ;
int V_94 = V_7 -> V_103 -> V_101 . V_104 ;
int V_90 , V_8 ;
int V_105 ;
F_8 ( V_5 , L_12 , V_12 ) ;
if ( V_7 -> V_47 . V_106 != V_107 ) {
F_15 ( V_5 , L_56 , V_12 , V_7 -> V_47 . V_106 ) ;
return - V_27 ;
}
if ( ! ( V_99 = F_10 ( V_7 , V_37 ) ) ) {
F_15 ( V_5 , L_57 , V_12 ) ;
return - V_27 ;
}
for ( V_90 = 0 ; V_90 < V_94 ; V_90 ++ ) {
V_95 = F_10 ( V_7 , V_90 ) ;
if ( ( V_90 != V_100 ) && V_95 ) {
V_8 = F_62 ( & V_96 , V_95 , V_5 ) ;
if ( V_8 < 0 ) {
F_15 ( V_5 , L_58 , V_12 , V_90 , V_8 ) ;
F_58 ( V_7 , V_90 ) ;
return V_8 ;
}
}
}
V_2 = F_63 ( sizeof( * V_2 ) , V_24 ) ;
if ( ! V_2 ) {
F_15 ( V_5 , L_59 , V_12 ) ;
V_8 = - V_25 ;
goto V_108;
}
V_2 -> V_5 = V_5 ;
V_2 -> V_13 . V_38 = V_38 ;
V_2 -> V_13 . V_17 = V_17 ;
V_2 -> V_13 . V_14 = V_14 ;
memcpy ( V_2 -> V_13 . V_15 , V_109 , V_16 ) ;
memcpy ( V_2 -> V_13 . V_15 , V_15 , V_110 ) ;
V_105 = V_111 ;
if ( V_2 -> V_13 . V_38 )
if ( ( V_8 = F_17 ( V_7 , V_37 , V_2 -> V_13 . V_38 ) ) < 0 ) {
F_15 ( V_5 , L_60 , V_12 , V_2 -> V_13 . V_38 , V_8 ) ;
V_2 -> V_13 . V_38 = 0 ;
}
if ( ! V_2 -> V_13 . V_38 && V_105 )
if ( ( V_8 = F_17 ( V_7 , V_37 , V_112 ) ) < 0 ) {
F_8 ( V_5 , L_60 , V_12 , V_112 , V_8 ) ;
V_105 = 0 ;
}
if ( V_105 ) {
const struct V_113 * V_101 = V_99 -> V_114 ;
const T_3 V_115 = V_116 | V_5 -> V_117 -> V_118 ;
V_105 = 0 ;
for ( V_90 = 0 ; V_90 < V_101 -> V_101 . V_119 ; V_90 ++ ) {
const struct V_120 * V_121 = & V_101 -> V_122 [ V_90 ] . V_101 ;
if ( ( V_121 -> V_123 == V_115 ) ) {
V_105 =
F_64 ( V_121 ) ;
break;
}
}
if ( ! V_105 )
F_23 ( V_5 , L_61 ) ;
}
if ( ! V_105 && ! V_2 -> V_13 . V_38 )
if ( ( V_8 = F_17 ( V_7 , V_37 , V_124 ) ) < 0 ) {
F_15 ( V_5 , L_60 , V_12 , V_124 , V_8 ) ;
goto V_125;
}
if ( ! V_2 -> V_13 . V_38 )
V_2 -> V_13 . V_38 = V_105 ? V_112 : V_124 ;
V_5 -> V_126 |= ( V_105 ? V_127 : 0 ) ;
F_65 ( & V_2 -> V_64 , F_31 ) ;
F_66 ( & V_2 -> V_77 ) ;
V_2 -> V_77 . V_128 = F_38 ;
V_2 -> V_77 . V_35 = ( unsigned long ) V_2 ;
V_2 -> V_72 = 0xff ;
V_2 -> V_69 = V_71 ;
F_66 ( & V_2 -> V_82 ) ;
V_2 -> V_82 . V_128 = F_42 ;
V_2 -> V_82 . V_35 = ( unsigned long ) V_2 ;
V_2 -> V_80 = F_67 ( 0 , V_24 ) ;
if ( V_2 -> V_80 )
F_68 ( V_2 -> V_80 , V_7 ,
F_69 ( V_7 , V_129 ) ,
V_2 -> V_89 , sizeof( V_2 -> V_89 ) ,
F_44 , V_2 , 50 ) ;
else
F_8 ( V_5 , L_62 , V_12 ) ;
V_8 = F_2 ( V_7 , F_27 ( V_7 , 0 ) ,
0x12 , 0xc0 , 0x07 , 0x00 ,
V_2 -> V_11 + V_52 , V_53 , 500 ) ;
V_5 -> V_126 |= ( V_8 == V_53 ? V_130 : 0 ) ;
F_8 ( V_5 , L_63 , V_12 , V_5 -> V_126 & V_130 ? L_64 : L_65 ) ;
if ( ! ( V_5 -> V_126 & V_130 ) )
if ( ( V_8 = F_70 ( V_7 ) ) < 0 ) {
F_15 ( V_5 , L_66 , V_12 , V_8 ) ;
goto V_125;
}
V_5 -> V_51 = V_2 ;
return 0 ;
V_125:
F_50 ( V_2 -> V_80 ) ;
F_71 ( V_2 ) ;
V_108:
F_58 ( V_7 , V_94 ) ;
return V_8 ;
}
static void F_72 ( struct V_4 * V_5 , struct V_40 * V_41 )
{
struct V_6 * V_7 = F_21 ( V_41 ) ;
struct V_1 * V_2 = V_5 -> V_51 ;
F_8 ( V_5 , L_12 , V_12 ) ;
F_58 ( V_7 , V_7 -> V_103 -> V_101 . V_104 ) ;
F_50 ( V_2 -> V_80 ) ;
F_71 ( V_2 ) ;
}
static int F_73 ( struct V_40 * V_41 , const struct V_97 * V_98 )
{
return F_74 ( V_41 , V_98 , & V_131 ) ;
}
