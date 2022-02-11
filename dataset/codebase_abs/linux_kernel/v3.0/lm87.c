static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 , V_3 ) ;
}
static inline int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_4 ( V_2 , V_3 , V_4 ) ;
}
static void F_5 ( struct V_5 * V_6 , const char * V_7 , int V_8 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_9 * V_10 = F_7 ( V_2 ) ;
long V_11 = F_8 ( V_7 , NULL , 10 ) ;
F_9 ( & V_10 -> V_12 ) ;
V_10 -> V_13 [ V_8 ] = F_10 ( V_11 , V_10 -> V_14 [ V_8 ] ) ;
F_3 ( V_2 , V_8 < 6 ? F_11 ( V_8 ) :
F_12 ( V_8 - 6 ) , V_10 -> V_13 [ V_8 ] ) ;
F_13 ( & V_10 -> V_12 ) ;
}
static void F_14 ( struct V_5 * V_6 , const char * V_7 , int V_8 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_9 * V_10 = F_7 ( V_2 ) ;
long V_11 = F_8 ( V_7 , NULL , 10 ) ;
F_9 ( & V_10 -> V_12 ) ;
V_10 -> V_15 [ V_8 ] = F_10 ( V_11 , V_10 -> V_14 [ V_8 ] ) ;
F_3 ( V_2 , V_8 < 6 ? F_15 ( V_8 ) :
F_16 ( V_8 - 6 ) , V_10 -> V_15 [ V_8 ] ) ;
F_13 ( & V_10 -> V_12 ) ;
}
static void F_17 ( struct V_5 * V_6 , const char * V_7 , int V_8 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_9 * V_10 = F_7 ( V_2 ) ;
long V_11 = F_8 ( V_7 , NULL , 10 ) ;
F_9 ( & V_10 -> V_12 ) ;
V_10 -> V_16 [ V_8 ] = F_18 ( V_11 ) ;
F_3 ( V_2 , V_17 [ V_8 ] , V_10 -> V_16 [ V_8 ] ) ;
F_13 ( & V_10 -> V_12 ) ;
}
static void F_19 ( struct V_5 * V_6 , const char * V_7 , int V_8 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_9 * V_10 = F_7 ( V_2 ) ;
long V_11 = F_8 ( V_7 , NULL , 10 ) ;
F_9 ( & V_10 -> V_12 ) ;
V_10 -> V_18 [ V_8 ] = F_18 ( V_11 ) ;
F_3 ( V_2 , V_19 [ V_8 ] , V_10 -> V_18 [ V_8 ] ) ;
F_13 ( & V_10 -> V_12 ) ;
}
static T_2 F_20 ( struct V_5 * V_6 , struct V_20 * V_21 , char * V_7 )
{
struct V_9 * V_10 = F_21 ( V_6 ) ;
return sprintf ( V_7 , L_1 , F_22 ( V_10 -> V_22 ) ) ;
}
static T_2 F_23 ( struct V_5 * V_6 , struct V_20 * V_21 , char * V_7 )
{
struct V_9 * V_10 = F_21 ( V_6 ) ;
return sprintf ( V_7 , L_1 , F_22 ( V_10 -> V_23 ) ) ;
}
static void F_24 ( struct V_5 * V_6 , const char * V_7 , int V_8 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_9 * V_10 = F_7 ( V_2 ) ;
long V_11 = F_8 ( V_7 , NULL , 10 ) ;
F_9 ( & V_10 -> V_12 ) ;
V_10 -> V_24 [ V_8 ] = F_25 ( V_11 ,
F_26 ( V_10 -> V_25 [ V_8 ] ) ) ;
F_3 ( V_2 , F_27 ( V_8 ) , V_10 -> V_24 [ V_8 ] ) ;
F_13 ( & V_10 -> V_12 ) ;
}
static T_2 F_28 ( struct V_5 * V_6 , const char * V_7 ,
T_3 V_26 , int V_8 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_9 * V_10 = F_7 ( V_2 ) ;
long V_11 = F_8 ( V_7 , NULL , 10 ) ;
unsigned long V_27 ;
T_1 V_3 ;
F_9 ( & V_10 -> V_12 ) ;
V_27 = F_29 ( V_10 -> V_24 [ V_8 ] ,
F_26 ( V_10 -> V_25 [ V_8 ] ) ) ;
switch ( V_11 ) {
case 1 : V_10 -> V_25 [ V_8 ] = 0 ; break;
case 2 : V_10 -> V_25 [ V_8 ] = 1 ; break;
case 4 : V_10 -> V_25 [ V_8 ] = 2 ; break;
case 8 : V_10 -> V_25 [ V_8 ] = 3 ; break;
default:
F_13 ( & V_10 -> V_12 ) ;
return - V_28 ;
}
V_3 = F_1 ( V_2 , V_29 ) ;
switch ( V_8 ) {
case 0 :
V_3 = ( V_3 & 0xCF ) | ( V_10 -> V_25 [ 0 ] << 4 ) ;
break;
case 1 :
V_3 = ( V_3 & 0x3F ) | ( V_10 -> V_25 [ 1 ] << 6 ) ;
break;
}
F_3 ( V_2 , V_29 , V_3 ) ;
V_10 -> V_24 [ V_8 ] = F_25 ( V_27 , V_11 ) ;
F_3 ( V_2 , F_27 ( V_8 ) ,
V_10 -> V_24 [ V_8 ] ) ;
F_13 ( & V_10 -> V_12 ) ;
return V_26 ;
}
static T_2 F_30 ( struct V_5 * V_6 , struct V_20 * V_21 , char * V_7 )
{
struct V_9 * V_10 = F_21 ( V_6 ) ;
return sprintf ( V_7 , L_1 , V_10 -> V_30 ) ;
}
static T_2 F_31 ( struct V_5 * V_6 , struct V_20 * V_21 , char * V_7 )
{
struct V_9 * V_10 = F_21 ( V_6 ) ;
return sprintf ( V_7 , L_1 , F_32 ( V_10 -> V_31 , V_10 -> V_32 ) ) ;
}
static T_2 F_33 ( struct V_5 * V_6 , struct V_20 * V_21 , char * V_7 )
{
struct V_9 * V_10 = F_34 ( V_6 ) ;
return sprintf ( V_7 , L_1 , V_10 -> V_32 ) ;
}
static T_2 F_35 ( struct V_5 * V_6 , struct V_20 * V_21 , const char * V_7 , T_3 V_26 )
{
struct V_9 * V_10 = F_34 ( V_6 ) ;
V_10 -> V_32 = F_36 ( V_7 , NULL , 10 ) ;
return V_26 ;
}
static T_2 F_37 ( struct V_5 * V_6 , struct V_20 * V_21 , char * V_7 )
{
struct V_9 * V_10 = F_21 ( V_6 ) ;
return sprintf ( V_7 , L_1 , F_38 ( V_10 -> V_33 ) ) ;
}
static T_2 F_39 ( struct V_5 * V_6 , struct V_20 * V_21 , const char * V_7 , T_3 V_26 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_9 * V_10 = F_7 ( V_2 ) ;
long V_11 = F_8 ( V_7 , NULL , 10 ) ;
F_9 ( & V_10 -> V_12 ) ;
V_10 -> V_33 = F_40 ( V_11 ) ;
F_3 ( V_2 , V_34 , V_10 -> V_33 ) ;
F_13 ( & V_10 -> V_12 ) ;
return V_26 ;
}
static T_2 F_41 ( struct V_5 * V_6 , struct V_20 * V_21 ,
char * V_7 )
{
struct V_9 * V_10 = F_21 ( V_6 ) ;
int V_35 = F_42 ( V_21 ) -> V_36 ;
return sprintf ( V_7 , L_2 , ( V_10 -> V_30 >> V_35 ) & 1 ) ;
}
static int F_43 ( struct V_1 * V_37 ,
struct V_38 * V_39 )
{
struct V_40 * V_41 = V_37 -> V_41 ;
const char * V_42 ;
T_1 V_43 , V_44 ;
if ( ! F_44 ( V_41 , V_45 ) )
return - V_46 ;
if ( F_1 ( V_37 , V_47 ) & 0x80 )
return - V_46 ;
V_43 = F_1 ( V_37 , V_48 ) ;
V_44 = F_1 ( V_37 , V_49 ) ;
if ( V_43 == 0x02
&& ( V_44 >= 0x01 && V_44 <= 0x08 ) )
V_42 = L_3 ;
else if ( V_43 == 0x41
&& ( V_44 & 0xf0 ) == 0x10 )
V_42 = L_4 ;
else {
F_45 ( & V_41 -> V_6 , L_5 ,
V_37 -> V_50 ) ;
return - V_46 ;
}
F_46 ( V_39 -> type , V_42 , V_51 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_37 ,
const struct V_52 * V_53 )
{
struct V_9 * V_10 ;
int V_54 ;
V_10 = F_48 ( sizeof( struct V_9 ) , V_55 ) ;
if ( ! V_10 ) {
V_54 = - V_56 ;
goto exit;
}
F_49 ( V_37 , V_10 ) ;
V_10 -> V_57 = 0 ;
F_50 ( & V_10 -> V_12 ) ;
F_51 ( V_37 ) ;
V_10 -> V_14 [ 0 ] = 2500 ;
V_10 -> V_14 [ 1 ] = 2700 ;
V_10 -> V_14 [ 2 ] = ( V_10 -> V_58 & V_59 ) ? 5000 : 3300 ;
V_10 -> V_14 [ 3 ] = 5000 ;
V_10 -> V_14 [ 4 ] = 12000 ;
V_10 -> V_14 [ 5 ] = 2700 ;
V_10 -> V_14 [ 6 ] = 1875 ;
V_10 -> V_14 [ 7 ] = 1875 ;
if ( ( V_54 = F_52 ( & V_37 -> V_6 . V_60 , & V_61 ) ) )
goto V_62;
if ( V_10 -> V_58 & F_53 ( 0 ) ) {
if ( ( V_54 = F_54 ( & V_37 -> V_6 ,
& V_63 ) )
|| ( V_54 = F_54 ( & V_37 -> V_6 ,
& V_64 ) )
|| ( V_54 = F_54 ( & V_37 -> V_6 ,
& V_65 ) )
|| ( V_54 = F_54 ( & V_37 -> V_6 ,
& V_66 . V_67 ) ) )
goto V_68;
} else {
if ( ( V_54 = F_54 ( & V_37 -> V_6 ,
& V_69 ) )
|| ( V_54 = F_54 ( & V_37 -> V_6 ,
& V_70 ) )
|| ( V_54 = F_54 ( & V_37 -> V_6 ,
& V_71 ) )
|| ( V_54 = F_54 ( & V_37 -> V_6 ,
& V_72 . V_67 ) ) )
goto V_68;
}
if ( V_10 -> V_58 & F_53 ( 1 ) ) {
if ( ( V_54 = F_54 ( & V_37 -> V_6 ,
& V_73 ) )
|| ( V_54 = F_54 ( & V_37 -> V_6 ,
& V_74 ) )
|| ( V_54 = F_54 ( & V_37 -> V_6 ,
& V_75 ) )
|| ( V_54 = F_54 ( & V_37 -> V_6 ,
& V_76 . V_67 ) ) )
goto V_68;
} else {
if ( ( V_54 = F_54 ( & V_37 -> V_6 ,
& V_77 ) )
|| ( V_54 = F_54 ( & V_37 -> V_6 ,
& V_78 ) )
|| ( V_54 = F_54 ( & V_37 -> V_6 ,
& V_79 ) )
|| ( V_54 = F_54 ( & V_37 -> V_6 ,
& V_80 . V_67 ) ) )
goto V_68;
}
if ( V_10 -> V_58 & V_81 ) {
if ( ( V_54 = F_54 ( & V_37 -> V_6 ,
& V_82 ) )
|| ( V_54 = F_54 ( & V_37 -> V_6 ,
& V_83 ) )
|| ( V_54 = F_54 ( & V_37 -> V_6 ,
& V_84 ) )
|| ( V_54 = F_54 ( & V_37 -> V_6 ,
& V_85 ) )
|| ( V_54 = F_54 ( & V_37 -> V_6 ,
& V_86 . V_67 ) )
|| ( V_54 = F_54 ( & V_37 -> V_6 ,
& V_87 . V_67 ) ) )
goto V_68;
} else {
if ( ( V_54 = F_54 ( & V_37 -> V_6 ,
& V_88 ) )
|| ( V_54 = F_54 ( & V_37 -> V_6 ,
& V_89 ) )
|| ( V_54 = F_54 ( & V_37 -> V_6 ,
& V_90 ) )
|| ( V_54 = F_54 ( & V_37 -> V_6 ,
& V_91 . V_67 ) )
|| ( V_54 = F_54 ( & V_37 -> V_6 ,
& V_92 ) )
|| ( V_54 = F_54 ( & V_37 -> V_6 ,
& V_93 ) )
|| ( V_54 = F_54 ( & V_37 -> V_6 ,
& V_94 ) )
|| ( V_54 = F_54 ( & V_37 -> V_6 ,
& V_95 . V_67 ) ) )
goto V_68;
}
if ( ! ( V_10 -> V_58 & V_96 ) ) {
V_10 -> V_32 = F_55 () ;
if ( ( V_54 = F_54 ( & V_37 -> V_6 ,
& V_97 ) )
|| ( V_54 = F_54 ( & V_37 -> V_6 ,
& V_98 ) ) )
goto V_68;
}
V_10 -> V_99 = F_56 ( & V_37 -> V_6 ) ;
if ( F_57 ( V_10 -> V_99 ) ) {
V_54 = F_58 ( V_10 -> V_99 ) ;
goto V_68;
}
return 0 ;
V_68:
F_59 ( & V_37 -> V_6 . V_60 , & V_61 ) ;
F_59 ( & V_37 -> V_6 . V_60 , & V_100 ) ;
V_62:
F_3 ( V_37 , V_47 , V_10 -> V_101 ) ;
F_60 ( V_10 ) ;
exit:
return V_54 ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_7 ( V_2 ) ;
if ( V_2 -> V_6 . V_102 ) {
V_10 -> V_58 = * ( T_1 * ) V_2 -> V_6 . V_102 ;
F_3 ( V_2 ,
V_103 , V_10 -> V_58 ) ;
} else {
V_10 -> V_58 = F_1 ( V_2 , V_103 ) ;
}
V_10 -> V_101 = F_1 ( V_2 , V_47 ) & 0x6F ;
if ( ! ( V_10 -> V_101 & 0x01 ) ) {
int V_104 ;
for ( V_104 = 1 ; V_104 < 6 ; V_104 ++ ) {
F_3 ( V_2 , F_11 ( V_104 ) , 0x00 ) ;
F_3 ( V_2 , F_15 ( V_104 ) , 0xFF ) ;
}
for ( V_104 = 0 ; V_104 < 2 ; V_104 ++ ) {
F_3 ( V_2 , V_19 [ V_104 ] , 0x7F ) ;
F_3 ( V_2 , V_17 [ V_104 ] , 0x00 ) ;
F_3 ( V_2 , F_12 ( V_104 ) , 0x00 ) ;
F_3 ( V_2 , F_16 ( V_104 ) , 0xFF ) ;
}
if ( V_10 -> V_58 & V_81 ) {
F_3 ( V_2 , V_19 [ 2 ] , 0x7F ) ;
F_3 ( V_2 , V_17 [ 2 ] , 0x00 ) ;
} else {
F_3 ( V_2 , F_11 ( 0 ) , 0x00 ) ;
F_3 ( V_2 , F_15 ( 0 ) , 0xFF ) ;
}
}
if ( ( V_10 -> V_101 & 0x09 ) != 0x01 )
F_3 ( V_2 , V_47 ,
( V_10 -> V_101 & 0x77 ) | 0x01 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_7 ( V_2 ) ;
F_62 ( V_10 -> V_99 ) ;
F_59 ( & V_2 -> V_6 . V_60 , & V_61 ) ;
F_59 ( & V_2 -> V_6 . V_60 , & V_100 ) ;
F_3 ( V_2 , V_47 , V_10 -> V_101 ) ;
F_60 ( V_10 ) ;
return 0 ;
}
static struct V_9 * F_21 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_9 * V_10 = F_7 ( V_2 ) ;
F_9 ( & V_10 -> V_12 ) ;
if ( F_63 ( V_105 , V_10 -> V_106 + V_107 ) || ! V_10 -> V_57 ) {
int V_104 , V_108 ;
F_45 ( & V_2 -> V_6 , L_6 ) ;
V_104 = ( V_10 -> V_58 & V_81 ) ? 1 : 0 ;
V_108 = ( V_10 -> V_58 & V_81 ) ? 5 : 6 ;
for (; V_104 < V_108 ; V_104 ++ ) {
V_10 -> V_109 [ V_104 ] = F_1 ( V_2 ,
F_64 ( V_104 ) ) ;
V_10 -> V_13 [ V_104 ] = F_1 ( V_2 ,
F_11 ( V_104 ) ) ;
V_10 -> V_15 [ V_104 ] = F_1 ( V_2 ,
F_15 ( V_104 ) ) ;
}
for ( V_104 = 0 ; V_104 < 2 ; V_104 ++ ) {
if ( V_10 -> V_58 & F_53 ( V_104 ) ) {
V_10 -> V_109 [ 6 + V_104 ] = F_1 ( V_2 ,
F_65 ( V_104 ) ) ;
V_10 -> V_15 [ 6 + V_104 ] = F_1 ( V_2 ,
F_16 ( V_104 ) ) ;
V_10 -> V_13 [ 6 + V_104 ] = F_1 ( V_2 ,
F_12 ( V_104 ) ) ;
} else {
V_10 -> V_110 [ V_104 ] = F_1 ( V_2 ,
F_66 ( V_104 ) ) ;
V_10 -> V_24 [ V_104 ] = F_1 ( V_2 ,
F_27 ( V_104 ) ) ;
}
}
V_108 = ( V_10 -> V_58 & V_81 ) ? 3 : 2 ;
for ( V_104 = 0 ; V_104 < V_108 ; V_104 ++ ) {
V_10 -> V_111 [ V_104 ] = F_1 ( V_2 ,
V_112 [ V_104 ] ) ;
V_10 -> V_18 [ V_104 ] = F_1 ( V_2 ,
V_19 [ V_104 ] ) ;
V_10 -> V_16 [ V_104 ] = F_1 ( V_2 ,
V_17 [ V_104 ] ) ;
}
V_104 = F_1 ( V_2 , V_113 ) ;
V_108 = F_1 ( V_2 , V_114 ) ;
V_10 -> V_22 = V_27 ( V_104 , V_108 ) ;
V_104 = F_1 ( V_2 , V_115 ) ;
V_108 = F_1 ( V_2 , V_116 ) ;
V_10 -> V_23 = V_27 ( V_104 , V_108 ) ;
V_104 = F_1 ( V_2 , V_29 ) ;
V_10 -> V_25 [ 0 ] = ( V_104 >> 4 ) & 0x03 ;
V_10 -> V_25 [ 1 ] = ( V_104 >> 6 ) & 0x03 ;
V_10 -> V_31 = ( V_104 & 0x0F )
| ( F_1 ( V_2 , V_117 ) & 0x01 )
<< 4 ;
V_10 -> V_30 = F_1 ( V_2 , V_118 )
| ( F_1 ( V_2 , V_119 )
<< 8 ) ;
V_10 -> V_33 = F_1 ( V_2 , V_34 ) ;
V_10 -> V_106 = V_105 ;
V_10 -> V_57 = 1 ;
}
F_13 ( & V_10 -> V_12 ) ;
return V_10 ;
}
static int T_4 F_67 ( void )
{
return F_68 ( & V_120 ) ;
}
static void T_5 F_69 ( void )
{
F_70 ( & V_120 ) ;
}
