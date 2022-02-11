static void F_1 ( const unsigned char * V_1 , unsigned char * V_2 ,
int V_3 )
{
for (; V_3 > 0 ; V_3 -= 6 ) {
V_2 [ 2 ] = V_1 [ 0 ] | ( V_1 [ 1 ] << 4 ) ;
V_2 [ 1 ] = V_1 [ 2 ] | ( V_1 [ 3 ] << 4 ) ;
V_2 [ 0 ] = V_1 [ 4 ] | ( V_1 [ 5 ] << 4 ) ;
V_1 += 6 ;
V_2 += 3 ;
}
}
static void F_2 ( struct V_4 * V_5 , int V_6 )
{
V_5 -> V_7 [ V_8 ] = V_6 ;
F_3 ( & V_5 -> V_9 , V_5 -> V_7 ,
sizeof( V_10 ) ) ;
}
static void F_4 ( struct V_4 * V_5 )
{
F_5 ( V_5 -> V_11 , V_12 ) ;
F_6 ( & V_5 -> V_13 , V_14 ,
V_15 , ( unsigned long ) V_5 ) ;
}
static void V_15 ( unsigned long V_2 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 ;
struct V_16 * V_9 = & V_5 -> V_9 ;
if ( V_5 -> V_11 >= V_17 )
return;
V_5 -> V_11 = V_18 ;
F_6 ( & V_5 -> V_13 , V_14 ,
V_15 , ( unsigned long ) V_5 ) ;
F_7 ( V_9 ) ;
}
static void F_8 ( struct V_4 * V_5 )
{
F_5 ( V_5 -> V_11 , V_19 ) ;
F_6 ( & V_5 -> V_20 , V_21 ,
V_22 , ( unsigned long ) V_5 ) ;
}
static void V_22 ( unsigned long V_2 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 ;
F_5 ( V_5 -> V_11 ,
V_23 ) ;
F_2 ( V_5 , 1 ) ;
F_6 ( & V_5 -> V_20 , V_24 ,
V_25 , ( unsigned long ) V_5 ) ;
}
static void V_25 ( unsigned long V_2 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 ;
F_5 ( V_5 -> V_11 ,
V_26 ) ;
F_9 ( & V_5 -> V_27 , & V_5 -> V_9 , 0 ,
V_28 ) ;
}
static void F_10 ( struct V_4 * V_5 )
{
F_5 ( V_5 -> V_11 ,
V_29 ) ;
F_11 ( & V_5 -> V_30 ) ;
}
static void F_12 ( struct V_31 * V_32 )
{
struct V_4 * V_5 =
F_13 ( V_32 , struct V_4 , V_30 ) ;
struct V_16 * V_9 = & V_5 -> V_9 ;
F_5 ( V_5 -> V_11 , V_33 ) ;
F_14 ( & V_5 -> V_9 ) ;
F_15 ( 0 , 0 , V_9 -> V_34 ) ;
F_16 ( V_9 -> V_34 ) ;
}
void F_17 ( struct V_4 * V_5 )
{
const unsigned char * V_35 = V_5 -> V_9 . V_36 ;
switch ( V_35 [ 0 ] ) {
case V_37 | V_38 :
switch ( V_35 [ 1 ] ) {
case V_39 :
V_5 -> V_40 = V_35 [ 2 ] ;
break;
case V_41 :
V_5 -> V_42 = V_35 [ 2 ] ;
}
break;
case V_43 | V_44 :
case V_43 | V_38 :
V_5 -> V_45 = V_35 [ 1 ] ;
F_9 ( & V_5 -> V_27 , & V_5 -> V_9 , 0 ,
V_28 ) ;
break;
case V_46 :
F_18 ( V_5 -> V_9 . V_34 , L_1 ) ;
break;
case V_47 :
if ( memcmp ( V_35 + 1 , V_48 + 1 ,
V_49 - 1 ) == 0 ) {
if ( V_5 -> V_9 . V_50 ==
V_51 ) {
switch ( V_5 -> V_27 . V_52 ) {
case V_28 :
F_1 ( V_35 +
V_49 ,
( unsigned char * )
& V_5 -> V_53 ,
( sizeof
( V_5 -> V_53 .
V_54 ) +
sizeof( V_5 ->
V_53 .
V_55 )
/ 2 ) * 2 ) ;
F_9
( & V_5 -> V_27 , & V_5 -> V_9 ,
1 , V_56 ) ;
break;
case V_56 :
F_1 ( V_35 +
V_49 ,
( unsigned char * )
& V_5 ->
V_53 . V_55 +
sizeof( V_5 -> V_53 .
V_55 )
/ 2 ,
sizeof( V_5 -> V_53 .
V_55 )
/ 2 * 2 ) ;
F_9
( & V_5 -> V_27 , & V_5 -> V_9 ,
2 , V_57 ) ;
}
} else {
F_19 ( F_20
( V_5 -> V_9 . V_34 ,
L_2 ,
V_5 -> V_9 . V_50 ) ) ;
F_21 ( & V_5 -> V_27 ) ;
}
} else if ( memcmp ( V_35 + 1 , V_58 + 1 ,
sizeof( V_58 ) - 2 ) == 0 ) {
memcpy ( V_5 -> V_59 ,
V_35 + sizeof( V_58 ) - 1 ,
sizeof( V_5 -> V_59 ) ) ;
F_21 ( & V_5 -> V_27 ) ;
F_10 ( V_5 ) ;
} else if ( memcmp ( V_35 + 1 , V_60 + 1 ,
sizeof( V_60 ) - 1 ) == 0 ) {
memcpy ( V_5 -> V_61 ,
V_35 + sizeof( V_60 ) ,
sizeof( V_5 -> V_61 ) ) ;
} else if ( memcmp ( V_35 + 1 , V_62 + 1 ,
sizeof( V_62 ) - 1 ) == 0 ) {
F_8 ( V_5 ) ;
} else if ( memcmp ( V_35 + 1 , V_63 + 1 ,
sizeof( V_63 ) - 1 ) == 0 ) {
V_22 ( ( unsigned long ) V_5 ) ;
}
break;
case V_64 :
break;
default:
F_19 ( F_20
( V_5 -> V_9 . V_34 ,
L_3 , V_35 [ 0 ] ) ) ;
}
}
static T_1 F_22 ( struct V_65 * V_66 ,
struct V_67 * V_68 , char * V_35 )
{
struct V_4 * V_5 =
F_23 ( F_24 ( V_66 ) ) ;
return sprintf ( V_35 , L_4 , V_5 -> V_40 ) ;
}
static T_1 F_25 ( struct V_65 * V_66 ,
struct V_67 * V_68 ,
const char * V_35 , T_2 V_69 )
{
struct V_4 * V_5 =
F_23 ( F_24 ( V_66 ) ) ;
T_3 V_70 ;
int V_71 ;
V_71 = F_26 ( V_35 , 10 , & V_70 ) ;
if ( V_71 )
return V_71 ;
if ( F_27 ( & V_5 -> V_9 , V_39 ,
V_70 ) == 0 )
V_5 -> V_40 = V_70 ;
return V_69 ;
}
static T_1 F_28 ( struct V_65 * V_66 ,
struct V_67 * V_68 , char * V_35 )
{
struct V_4 * V_5 =
F_23 ( F_24 ( V_66 ) ) ;
return sprintf ( V_35 , L_4 , V_5 -> V_45 ) ;
}
static T_1 F_29 ( struct V_65 * V_66 ,
struct V_67 * V_68 ,
const char * V_35 , T_2 V_69 )
{
struct V_4 * V_5 =
F_23 ( F_24 ( V_66 ) ) ;
T_3 V_70 ;
int V_71 ;
V_71 = F_26 ( V_35 , 10 , & V_70 ) ;
if ( V_71 )
return V_71 ;
if ( F_30 ( & V_5 -> V_9 , V_70 ) == 0 )
V_5 -> V_45 = V_70 ;
return V_69 ;
}
static T_1 F_31 ( struct V_65 * V_66 ,
struct V_67 * V_68 , char * V_35 )
{
struct V_4 * V_5 =
F_23 ( F_24 ( V_66 ) ) ;
return sprintf ( V_35 , L_4 ,
V_5 -> V_7 [ V_8 ] ) ;
}
static T_1 F_32 ( struct V_65 * V_66 ,
struct V_67 * V_68 ,
const char * V_35 , T_2 V_69 )
{
struct V_4 * V_5 =
F_23 ( F_24 ( V_66 ) ) ;
T_3 V_70 ;
int V_71 ;
V_71 = F_26 ( V_35 , 10 , & V_70 ) ;
if ( V_71 )
return V_71 ;
F_2 ( V_5 , V_70 ? 1 : 0 ) ;
return V_69 ;
}
static T_1 F_33 ( struct V_65 * V_66 ,
struct V_67 * V_68 , char * V_35 )
{
struct V_4 * V_5 =
F_23 ( F_24 ( V_66 ) ) ;
return sprintf ( V_35 , L_4 , V_5 -> V_42 ) ;
}
static T_1 F_34 ( struct V_65 * V_66 ,
struct V_67 * V_68 ,
const char * V_35 , T_2 V_69 )
{
struct V_4 * V_5 =
F_23 ( F_24 ( V_66 ) ) ;
T_3 V_70 ;
int V_71 ;
V_71 = F_26 ( V_35 , 10 , & V_70 ) ;
if ( V_71 )
return V_71 ;
if ( F_27 ( & V_5 -> V_9 , V_41 ,
V_70 ) == 0 )
V_5 -> V_42 = V_70 ;
return V_69 ;
}
static T_1 F_35 ( char * V_35 , const char * V_2 , int V_72 )
{
int V_73 ;
memcpy ( V_35 , V_2 , V_72 ) ;
for ( V_73 = V_72 ; V_73 -- ; ) {
char V_74 = V_35 [ V_73 ] ;
if ( ( V_74 != 0 ) && ( V_74 != ' ' ) )
break;
}
V_35 [ V_73 + 1 ] = '\n' ;
return V_73 + 2 ;
}
static T_1 F_36 ( struct V_65 * V_66 ,
struct V_67 * V_68 , char * V_35 )
{
struct V_4 * V_5 =
F_23 ( F_24 ( V_66 ) ) ;
F_37 ( & V_5 -> V_27 ) ;
return F_35 ( V_35 , V_5 -> V_53 . V_54 ,
sizeof( V_5 -> V_53 . V_54 ) ) ;
}
static T_1 F_38 ( struct V_65 * V_66 ,
struct V_67 * V_68 , char * V_35 )
{
struct V_4 * V_5 =
F_23 ( F_24 ( V_66 ) ) ;
F_37 ( & V_5 -> V_27 ) ;
return F_35 ( V_35 , V_5 -> V_59 , sizeof( V_5 -> V_59 ) ) ;
}
static T_1 F_39 ( struct V_65 * V_66 ,
struct V_67 * V_68 , char * V_35 )
{
struct V_4 * V_5 =
F_23 ( F_24 ( V_66 ) ) ;
int V_75 ;
V_75 = F_37 ( & V_5 -> V_27 ) ;
if ( V_75 < 0 )
return V_75 ;
memcpy ( V_35 , & V_5 -> V_53 . V_55 ,
sizeof( V_5 -> V_53 . V_55 ) ) ;
return sizeof( V_5 -> V_53 . V_55 ) ;
}
static T_1 F_40 ( struct V_65 * V_66 ,
struct V_67 * V_68 , char * V_35 )
{
struct V_4 * V_5 =
F_23 ( F_24 ( V_66 ) ) ;
return sprintf ( V_35 , L_5 , V_5 -> V_61 ) ;
}
static char * F_41 ( struct V_4 * V_5 ,
int V_76 , int V_77 )
{
return F_42 ( & V_5 -> V_9 , V_78 , V_76 ,
V_77 ) ;
}
static T_1 F_43 ( struct V_65 * V_66 ,
struct V_67 * V_68 ,
const char * V_35 , T_2 V_69 )
{
struct V_4 * V_5 =
F_23 ( F_24 ( V_66 ) ) ;
int V_77 ;
int V_73 ;
char * V_79 ;
V_69 -= V_69 % 3 ;
V_77 = V_69 * 2 ;
V_79 = F_41 ( V_5 , V_80 , V_77 ) ;
if ( ! V_79 )
return 0 ;
for ( V_73 = 0 ; V_73 < V_69 ; V_73 += 3 ) {
const unsigned char * V_81 = V_35 + V_73 ;
char * V_82 = V_79 + V_83 + V_73 * 2 ;
V_82 [ 0 ] = V_81 [ 2 ] & 0x0f ;
V_82 [ 1 ] = V_81 [ 2 ] >> 4 ;
V_82 [ 2 ] = V_81 [ 1 ] & 0x0f ;
V_82 [ 3 ] = V_81 [ 1 ] >> 4 ;
V_82 [ 4 ] = V_81 [ 0 ] & 0x0f ;
V_82 [ 5 ] = V_81 [ 0 ] >> 4 ;
}
F_44 ( & V_5 -> V_9 , V_79 , V_77 ) ;
F_45 ( V_79 ) ;
return V_69 ;
}
static void F_46 ( struct V_84 * V_85 )
{
struct V_4 * V_5 = F_23 ( V_85 ) ;
if ( V_5 == NULL )
return;
F_47 ( & V_5 -> V_9 ) ;
F_48 ( & V_5 -> V_13 ) ;
F_48 ( & V_5 -> V_20 ) ;
F_49 ( & V_5 -> V_30 ) ;
F_50 ( & V_5 -> V_27 , 2 ) ;
F_50 ( & V_5 -> V_27 , 1 ) ;
F_51 ( & V_5 -> V_27 ) ;
F_45 ( V_5 -> V_7 ) ;
}
static int F_16 ( struct V_65 * V_66 )
{
int V_86 ;
F_52 ( F_53 ( V_66 , & V_87 ) ) ;
F_52 ( F_53 ( V_66 , & V_88 ) ) ;
F_52 ( F_53 ( V_66 , & V_89 ) ) ;
F_52 ( F_53 ( V_66 , & V_90 ) ) ;
F_52 ( F_53 ( V_66 , & V_91 ) ) ;
F_52 ( F_53 ( V_66 , & V_92 ) ) ;
F_52 ( F_53 ( V_66 , & V_93 ) ) ;
F_52 ( F_53 ( V_66 , & V_94 ) ) ;
#ifdef F_54
F_52 ( F_53 ( V_66 , & V_95 ) ) ;
F_52 ( F_53 ( V_66 , & V_96 ) ) ;
#endif
return 0 ;
}
static int F_55 ( struct V_84 * V_85 ,
struct V_4 * V_5 )
{
int V_86 ;
F_56 ( & V_5 -> V_13 ) ;
F_56 ( & V_5 -> V_20 ) ;
F_57 ( & V_5 -> V_30 , F_12 ) ;
if ( ( V_85 == NULL ) || ( V_5 == NULL ) )
return - V_97 ;
V_86 = F_58 ( & V_5 -> V_27 , V_48 ,
sizeof( V_48 ) ) ;
if ( V_86 < 0 ) {
F_20 ( & V_85 -> V_66 , L_6 ) ;
return V_86 ;
}
V_86 = F_59 ( & V_5 -> V_27 , V_98 ,
sizeof( V_98 ) , 1 ) ;
if ( V_86 < 0 ) {
F_20 ( & V_85 -> V_66 , L_6 ) ;
return V_86 ;
}
V_86 = F_59 ( & V_5 -> V_27 , V_58 ,
sizeof( V_58 ) , 2 ) ;
if ( V_86 < 0 ) {
F_20 ( & V_85 -> V_66 , L_6 ) ;
return V_86 ;
}
V_5 -> V_7 = F_60 ( V_10 ,
sizeof( V_10 ) , V_99 ) ;
if ( V_5 -> V_7 == NULL ) {
F_20 ( & V_85 -> V_66 , L_6 ) ;
return - V_100 ;
}
V_86 = F_61 ( & V_5 -> V_9 ) ;
if ( V_86 < 0 )
return V_86 ;
V_86 = F_62 ( & V_5 -> V_9 ) ;
if ( V_86 < 0 )
return V_86 ;
F_4 ( V_5 ) ;
return 0 ;
}
int F_63 ( struct V_84 * V_85 ,
struct V_4 * V_5 )
{
int V_86 = F_55 ( V_85 , V_5 ) ;
if ( V_86 < 0 )
F_46 ( V_85 ) ;
return V_86 ;
}
void F_64 ( struct V_84 * V_85 )
{
struct V_65 * V_66 ;
if ( V_85 == NULL )
return;
V_66 = & V_85 -> V_66 ;
if ( V_66 != NULL ) {
F_65 ( 0 , 0 , V_66 ) ;
F_66 ( V_66 , & V_87 ) ;
F_66 ( V_66 , & V_88 ) ;
F_66 ( V_66 , & V_89 ) ;
F_66 ( V_66 , & V_90 ) ;
F_66 ( V_66 , & V_91 ) ;
F_66 ( V_66 , & V_92 ) ;
F_66 ( V_66 , & V_93 ) ;
F_66 ( V_66 , & V_94 ) ;
#ifdef F_54
F_66 ( V_66 , & V_95 ) ;
F_66 ( V_66 , & V_96 ) ;
#endif
}
F_46 ( V_85 ) ;
}
