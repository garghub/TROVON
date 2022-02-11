static void F_1 ( void )
{
struct V_1 * V_2 = F_2 ( L_1 ) ;
if ( V_2 ) {
F_3 ( V_2 ) ;
F_4 ( V_2 -> V_3 ) ;
}
}
static void F_5 ( void )
{
struct V_1 * V_2 = F_2 ( L_2 ) ;
if ( V_2 ) {
F_3 ( V_2 ) ;
F_4 ( V_2 -> V_3 ) ;
}
}
static void F_6 ( void )
{
unsigned char V_4 ;
if ( F_7 ( V_5 , NULL , 0 , & V_4 , 1 ) ) {
F_8 ( V_6 L_3 ) ;
return;
}
if ( ! ! F_9 ( V_7 , V_8 -> V_9 ) == V_4 )
return;
F_10 ( V_8 , V_7 , V_4 ) ;
F_11 ( V_8 ) ;
F_12 ( & V_8 -> V_3 , 0 ) ;
}
static void F_13 ( void )
{
if ( V_10 )
F_14 ( V_11 , V_12 ) ;
else
F_15 ( V_11 , V_12 ) ;
V_10 = ! V_10 ;
}
static void F_16 ( void )
{
int V_4 ;
V_4 = F_17 ( V_11 , V_13 ) ;
V_14 = ! V_4 ^ ! V_10 ;
if ( ! V_4 )
return;
F_13 () ;
}
static void F_18 ( void )
{
if ( ! ! F_9 ( V_15 , V_16 -> V_9 ) == ! V_14 )
return;
F_10 ( V_16 , V_15 , ! V_14 ) ;
F_11 ( V_16 ) ;
F_12 ( & V_16 -> V_3 , 0 ) ;
}
static T_1 F_19 ( struct V_17 * V_3 ,
struct V_18 * V_19 , char * V_20 )
{
const char * V_21 = V_22 [ V_23 ] ;
return sprintf ( V_20 , L_4 , V_21 ) ;
}
static T_1 F_20 ( struct V_17 * V_3 ,
struct V_18 * V_19 ,
const char * V_20 , T_2 V_24 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < F_21 ( V_22 ) ; V_25 ++ ) {
const char * V_21 = V_22 [ V_25 ] ;
if ( strlen ( V_21 ) != V_24 || strncasecmp ( V_21 , V_20 , V_24 ) )
continue;
V_23 = V_25 ;
return V_24 ;
}
return - V_26 ;
}
static void F_22 ( bool V_27 )
{
int V_28 ;
T_3 V_29 ;
do {
V_28 = F_23 ( & V_29 ) ;
if ( V_28 || ! V_29 )
break;
F_24 ( V_6 L_5 , V_29 ) ;
switch ( V_29 ) {
case V_30 :
case V_31 :
case V_32 :
case V_33 :
F_1 () ;
break;
case V_34 :
F_5 () ;
break;
}
if ( V_29 == V_35 && V_27 )
F_6 () ;
} while ( V_29 );
if ( V_28 )
F_8 ( V_6 L_6 ) ;
}
static void F_25 ( struct V_36 * V_37 )
{
F_22 ( true ) ;
}
static T_4 F_26 ( int V_38 , void * V_39 )
{
struct V_40 * V_41 = V_39 ;
T_5 V_42 ;
T_5 V_43 ;
V_42 = F_27 ( V_44 + V_45 ) ;
F_28 ( V_42 | 0xffff , V_44 + V_45 ) ;
V_43 = F_27 ( V_44 + V_46 ) ;
F_28 ( 0xffffffff , V_44 + V_46 ) ;
F_29 ( & V_41 -> V_3 , L_7 , V_42 , V_43 ) ;
if ( V_42 & V_47 ) {
if ( ! ( V_42 & V_48 ) ) {
F_30 ( V_49 , V_50 , 1 ) ;
F_11 ( V_49 ) ;
F_30 ( V_49 , V_50 , 0 ) ;
F_11 ( V_49 ) ;
}
F_12 ( & V_49 -> V_3 , 0 ) ;
}
if ( ( V_42 & ( V_51 | V_48 ) ) ==
( V_51 | V_48 ) ) {
struct V_17 * V_52 = F_31 (
& V_53 , NULL , L_8 ) ;
if ( V_52 ) {
F_12 ( V_52 , 0 ) ;
F_4 ( V_52 ) ;
}
}
if ( V_43 & V_54 ) {
F_15 ( V_55 , V_56 ) ;
F_32 ( & V_57 ) ;
}
F_15 ( V_11 , V_56 ) ;
F_15 ( V_11 , V_58 ) ;
F_16 () ;
F_18 () ;
return V_59 ;
}
static int F_33 ( struct V_40 * V_41 , T_6 V_4 )
{
if ( F_34 ( & V_49 -> V_3 ) )
F_35 ( V_60 ) ;
else
F_36 ( V_60 ) ;
if ( F_34 ( & V_8 -> V_3 ) )
F_37 ( V_35 ) ;
else
F_38 ( V_35 ) ;
if ( ! F_34 ( & V_16 -> V_3 ) ) {
F_14 ( V_11 , V_61 ) ;
} else if ( ( V_14 && V_23 == V_62 ) ||
( ! V_14 && V_23 == V_63 ) ) {
F_13 () ;
F_15 ( V_11 , V_56 ) ;
F_15 ( V_11 , V_58 ) ;
F_15 ( V_11 , V_61 ) ;
}
return 0 ;
}
static int F_39 ( struct V_40 * V_41 )
{
F_16 () ;
F_18 () ;
F_15 ( V_11 , V_61 ) ;
F_40 ( V_64 ) ;
F_1 () ;
F_5 () ;
return 0 ;
}
static int F_41 ( struct V_40 * V_41 )
{
T_5 V_65 , V_66 ;
T_5 V_42 ;
int V_28 ;
F_42 ( 0x51400020 , V_65 , V_66 ) ;
V_67 = ( V_65 >> 20 ) & 15 ;
if ( V_67 ) {
F_43 ( & V_41 -> V_3 , L_9 , V_67 ) ;
} else {
F_43 ( & V_41 -> V_3 , L_10 ) ;
V_67 = 3 ;
V_65 |= 0x00300000 ;
F_44 ( 0x51400020 , V_65 ) ;
}
if ( V_67 < 8 ) {
V_65 = F_45 ( V_68 ) ;
V_65 |= 1 << V_67 ;
F_46 ( V_65 , V_68 ) ;
} else {
V_65 = F_45 ( V_69 ) ;
V_65 |= 1 << ( V_67 - 8 ) ;
F_46 ( V_65 , V_69 ) ;
}
V_42 = F_27 ( V_44 + V_45 ) ;
F_28 ( ( ( V_60 | V_70 ) << 16 ) | 0xffff ,
V_44 + V_45 ) ;
V_28 = F_47 ( V_67 , F_26 , 0 , V_71 , V_41 ) ;
if ( V_28 )
F_48 ( & V_41 -> V_3 , L_11 ) ;
return V_28 ;
}
static int F_49 ( void )
{
int V_28 ;
V_28 = F_50 ( V_55 , L_12 ) ;
if ( V_28 )
return V_28 ;
F_51 ( V_55 ) ;
F_15 ( V_55 , V_56 ) ;
F_15 ( V_55 , V_58 ) ;
F_15 ( V_55 , V_61 ) ;
F_52 ( V_55 , 7 , 1 ) ;
F_53 ( 7 , V_67 ) ;
return 0 ;
}
static void F_54 ( void )
{
F_55 ( V_55 ) ;
}
static int F_56 ( void )
{
int V_28 ;
V_28 = F_50 ( V_11 , L_13 ) ;
if ( V_28 )
return V_28 ;
F_51 ( V_11 ) ;
F_14 ( V_11 , V_12 ) ;
V_10 = 0 ;
F_14 ( V_11 , V_61 ) ;
F_14 ( V_11 , V_72 ) ;
F_14 ( V_11 , V_73 ) ;
F_15 ( V_11 , V_56 ) ;
F_15 ( V_11 , V_58 ) ;
F_52 ( V_11 , 6 , 1 ) ;
F_57 ( 6 , V_67 ) ;
F_15 ( V_11 , V_61 ) ;
return 0 ;
}
static void F_58 ( void )
{
F_55 ( V_11 ) ;
}
static int F_59 ( struct V_40 * V_41 )
{
int V_28 ;
V_49 = F_60 () ;
if ( ! V_49 )
return - V_74 ;
V_49 -> V_75 = L_14 ;
V_49 -> V_76 = V_71 L_15 ;
F_61 ( V_77 , V_49 -> V_78 ) ;
F_61 ( V_50 , V_49 -> V_79 ) ;
V_49 -> V_3 . V_80 = & V_41 -> V_3 ;
F_62 ( & V_49 -> V_3 , 1 ) ;
V_28 = F_63 ( V_49 ) ;
if ( V_28 ) {
F_48 ( & V_41 -> V_3 , L_16 , V_28 ) ;
F_64 ( V_49 ) ;
}
return V_28 ;
}
static void F_65 ( void )
{
F_66 ( V_49 ) ;
F_64 ( V_49 ) ;
}
static int F_67 ( struct V_40 * V_41 )
{
int V_28 ;
V_8 = F_60 () ;
if ( ! V_8 )
return - V_74 ;
V_8 -> V_75 = L_17 ;
V_8 -> V_76 = V_71 L_18 ;
F_61 ( V_81 , V_8 -> V_78 ) ;
F_61 ( V_7 , V_8 -> V_82 ) ;
V_8 -> V_3 . V_80 = & V_41 -> V_3 ;
F_68 ( & V_8 -> V_3 , true ) ;
V_28 = F_63 ( V_8 ) ;
if ( V_28 ) {
F_48 ( & V_41 -> V_3 , L_19 , V_28 ) ;
F_64 ( V_8 ) ;
}
return V_28 ;
}
static void F_69 ( void )
{
F_66 ( V_8 ) ;
F_64 ( V_8 ) ;
}
static int F_70 ( struct V_40 * V_41 )
{
int V_28 ;
V_16 = F_60 () ;
if ( ! V_16 )
return - V_74 ;
V_16 -> V_75 = L_20 ;
V_16 -> V_76 = V_71 L_21 ;
F_61 ( V_81 , V_16 -> V_78 ) ;
F_61 ( V_15 , V_16 -> V_82 ) ;
V_16 -> V_3 . V_80 = & V_41 -> V_3 ;
F_68 ( & V_16 -> V_3 , true ) ;
V_28 = F_63 ( V_16 ) ;
if ( V_28 ) {
F_48 ( & V_41 -> V_3 , L_22 , V_28 ) ;
goto V_83;
}
V_28 = F_71 ( & V_16 -> V_3 , & V_84 ) ;
if ( V_28 ) {
F_48 ( & V_41 -> V_3 , L_23 , V_28 ) ;
goto V_85;
}
return 0 ;
V_85:
F_66 ( V_16 ) ;
V_83:
F_64 ( V_16 ) ;
return V_28 ;
}
static void F_72 ( void )
{
F_73 ( & V_16 -> V_3 , & V_84 ) ;
F_66 ( V_16 ) ;
F_64 ( V_16 ) ;
}
static int F_74 ( struct V_40 * V_41 )
{
struct V_86 * V_87 ;
int V_28 ;
if ( ! F_75 () )
return - V_88 ;
V_28 = F_76 ( V_41 ) ;
if ( V_28 )
return V_28 ;
V_87 = F_77 ( V_41 , V_89 , 0 ) ;
if ( ! V_87 ) {
F_48 ( & V_41 -> V_3 , L_24 ) ;
return - V_90 ;
}
V_44 = V_87 -> V_91 ;
V_28 = F_59 ( V_41 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_67 ( V_41 ) ;
if ( V_28 )
goto V_92;
V_28 = F_70 ( V_41 ) ;
if ( V_28 )
goto V_93;
V_28 = F_56 () ;
if ( V_28 )
goto V_94;
V_28 = F_49 () ;
if ( V_28 )
goto V_95;
F_28 ( V_96 | V_97 ,
V_44 + V_98 ) ;
F_28 ( 0xffffffff , V_44 + V_46 ) ;
F_22 ( false ) ;
F_6 () ;
F_16 () ;
F_18 () ;
V_28 = F_41 ( V_41 ) ;
if ( V_28 )
goto V_99;
F_40 ( V_64 ) ;
return V_28 ;
V_99:
F_54 () ;
V_95:
F_58 () ;
V_94:
F_72 () ;
V_93:
F_69 () ;
V_92:
F_65 () ;
return V_28 ;
}
static int F_78 ( struct V_40 * V_41 )
{
F_79 ( V_41 ) ;
F_80 ( V_67 , V_41 ) ;
F_81 ( & V_57 ) ;
F_54 () ;
F_58 () ;
F_72 () ;
F_69 () ;
F_65 () ;
V_44 = 0 ;
return 0 ;
}
static int T_7 F_82 ( void )
{
return F_83 ( & V_100 ) ;
}
