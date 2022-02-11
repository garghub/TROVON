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
F_9 ( V_7 , V_8 , V_4 ) ;
F_10 ( V_7 ) ;
}
static void F_11 ( void )
{
if ( V_9 )
F_12 ( V_10 , V_11 ) ;
else
F_13 ( V_10 , V_11 ) ;
V_9 = ! V_9 ;
}
static void F_14 ( void )
{
int V_4 ;
V_4 = F_15 ( V_10 , V_12 ) ;
V_13 = ! V_4 ^ ! V_9 ;
if ( ! V_4 )
return;
F_11 () ;
}
static void F_16 ( void )
{
F_9 ( V_14 , V_15 , ! V_13 ) ;
F_10 ( V_14 ) ;
}
static T_1 F_17 ( struct V_16 * V_3 ,
struct V_17 * V_18 , char * V_19 )
{
const char * V_20 = V_21 [ V_22 ] ;
return sprintf ( V_19 , L_4 , V_20 ) ;
}
static T_1 F_18 ( struct V_16 * V_3 ,
struct V_17 * V_18 ,
const char * V_19 , T_2 V_23 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < F_19 ( V_21 ) ; V_24 ++ ) {
const char * V_20 = V_21 [ V_24 ] ;
if ( strlen ( V_20 ) != V_23 || strncasecmp ( V_20 , V_19 , V_23 ) )
continue;
V_22 = V_24 ;
return V_23 ;
}
return - V_25 ;
}
static void F_20 ( bool V_26 )
{
int V_27 ;
T_3 V_28 ;
do {
V_27 = F_21 ( & V_28 ) ;
if ( V_27 || ! V_28 )
break;
F_22 ( V_6 L_5 , V_28 ) ;
switch ( V_28 ) {
case V_29 :
case V_30 :
case V_31 :
case V_32 :
F_1 () ;
break;
case V_33 :
F_5 () ;
break;
}
if ( V_28 == V_34 && V_26 )
F_6 () ;
} while ( V_28 );
if ( V_27 )
F_8 ( V_6 L_6 ) ;
}
static void F_23 ( struct V_35 * V_36 )
{
F_20 ( true ) ;
}
static T_4 F_24 ( int V_37 , void * V_38 )
{
struct V_39 * V_40 = V_38 ;
T_5 V_41 ;
T_5 V_42 ;
V_41 = F_25 ( V_43 + V_44 ) ;
F_26 ( V_41 | 0xffff , V_43 + V_44 ) ;
V_42 = F_25 ( V_43 + V_45 ) ;
F_26 ( 0xffffffff , V_43 + V_45 ) ;
F_27 ( & V_40 -> V_3 , L_7 , V_41 , V_42 ) ;
if ( V_41 & V_46 && ! ( V_41 & V_47 ) ) {
F_28 ( V_48 , V_49 , 1 ) ;
F_10 ( V_48 ) ;
F_28 ( V_48 , V_49 , 0 ) ;
F_10 ( V_48 ) ;
}
if ( V_42 & V_50 ) {
F_13 ( V_51 , V_52 ) ;
F_29 ( & V_53 ) ;
}
F_13 ( V_10 , V_52 ) ;
F_13 ( V_10 , V_54 ) ;
F_14 () ;
F_16 () ;
return V_55 ;
}
static int F_30 ( struct V_39 * V_40 , T_6 V_4 )
{
if ( F_31 ( & V_48 -> V_3 ) )
F_32 ( V_56 ) ;
else
F_33 ( V_56 ) ;
if ( F_31 ( & V_7 -> V_3 ) )
F_34 ( V_34 ) ;
else
F_35 ( V_34 ) ;
if ( ! F_31 ( & V_14 -> V_3 ) ) {
F_12 ( V_10 , V_57 ) ;
} else if ( ( V_13 && V_22 == V_58 ) ||
( ! V_13 && V_22 == V_59 ) ) {
F_11 () ;
F_13 ( V_10 , V_52 ) ;
F_13 ( V_10 , V_54 ) ;
F_13 ( V_10 , V_57 ) ;
}
return 0 ;
}
static int F_36 ( struct V_39 * V_40 )
{
F_14 () ;
F_16 () ;
F_13 ( V_10 , V_57 ) ;
F_37 ( V_60 ) ;
F_1 () ;
F_5 () ;
return 0 ;
}
static int T_7 F_38 ( struct V_39 * V_40 )
{
T_5 V_61 , V_62 ;
T_5 V_41 ;
int V_27 ;
F_39 ( 0x51400020 , V_61 , V_62 ) ;
V_63 = ( V_61 >> 20 ) & 15 ;
if ( V_63 ) {
F_40 ( & V_40 -> V_3 , L_8 , V_63 ) ;
} else {
F_40 ( & V_40 -> V_3 , L_9 ) ;
V_63 = 3 ;
V_61 |= 0x00300000 ;
F_41 ( 0x51400020 , V_61 ) ;
}
if ( V_63 < 8 ) {
V_61 = F_42 ( V_64 ) ;
V_61 |= 1 << V_63 ;
F_43 ( V_61 , V_64 ) ;
} else {
V_61 = F_42 ( V_65 ) ;
V_61 |= 1 << ( V_63 - 8 ) ;
F_43 ( V_61 , V_65 ) ;
}
V_41 = F_25 ( V_43 + V_44 ) ;
F_26 ( ( V_56 << 16 ) | 0xffff , V_43 + V_44 ) ;
V_27 = F_44 ( V_63 , F_24 , 0 , V_66 , V_40 ) ;
if ( V_27 )
F_45 ( & V_40 -> V_3 , L_10 ) ;
return V_27 ;
}
static int T_7 F_46 ( void )
{
int V_27 ;
V_27 = F_47 ( V_51 , L_11 ) ;
if ( V_27 )
return V_27 ;
F_48 ( V_51 ) ;
F_13 ( V_51 , V_52 ) ;
F_13 ( V_51 , V_54 ) ;
F_13 ( V_51 , V_57 ) ;
F_49 ( V_51 , 7 , 1 ) ;
F_50 ( 7 , V_63 ) ;
return 0 ;
}
static void F_51 ( void )
{
F_52 ( V_51 ) ;
}
static int T_7 F_53 ( void )
{
int V_27 ;
V_27 = F_47 ( V_10 , L_12 ) ;
if ( V_27 )
return V_27 ;
F_48 ( V_10 ) ;
F_12 ( V_10 , V_11 ) ;
V_9 = 0 ;
F_12 ( V_10 , V_57 ) ;
F_12 ( V_10 , V_67 ) ;
F_12 ( V_10 , V_68 ) ;
F_13 ( V_10 , V_52 ) ;
F_13 ( V_10 , V_54 ) ;
F_49 ( V_10 , 6 , 1 ) ;
F_54 ( 6 , V_63 ) ;
F_13 ( V_10 , V_57 ) ;
return 0 ;
}
static void F_55 ( void )
{
F_52 ( V_10 ) ;
}
static int T_7 F_56 ( struct V_39 * V_40 )
{
int V_27 ;
V_48 = F_57 () ;
if ( ! V_48 )
return - V_69 ;
V_48 -> V_70 = L_13 ;
V_48 -> V_71 = V_66 L_14 ;
F_58 ( V_72 , V_48 -> V_73 ) ;
F_58 ( V_49 , V_48 -> V_74 ) ;
V_48 -> V_3 . V_75 = & V_40 -> V_3 ;
F_59 ( & V_48 -> V_3 , 1 ) ;
V_27 = F_60 ( V_48 ) ;
if ( V_27 ) {
F_45 ( & V_40 -> V_3 , L_15 , V_27 ) ;
F_61 ( V_48 ) ;
}
return V_27 ;
}
static void F_62 ( void )
{
F_63 ( V_48 ) ;
F_61 ( V_48 ) ;
}
static int T_7 F_64 ( struct V_39 * V_40 )
{
int V_27 ;
V_7 = F_57 () ;
if ( ! V_7 )
return - V_69 ;
V_7 -> V_70 = L_16 ;
V_7 -> V_71 = V_66 L_17 ;
F_58 ( V_76 , V_7 -> V_73 ) ;
F_58 ( V_8 , V_7 -> V_77 ) ;
V_7 -> V_3 . V_75 = & V_40 -> V_3 ;
F_65 ( & V_7 -> V_3 , true ) ;
V_27 = F_60 ( V_7 ) ;
if ( V_27 ) {
F_45 ( & V_40 -> V_3 , L_18 , V_27 ) ;
F_61 ( V_7 ) ;
}
return V_27 ;
}
static void F_66 ( void )
{
F_63 ( V_7 ) ;
F_61 ( V_7 ) ;
}
static int T_7 F_67 ( struct V_39 * V_40 )
{
int V_27 ;
V_14 = F_57 () ;
if ( ! V_14 )
return - V_69 ;
V_14 -> V_70 = L_19 ;
V_14 -> V_71 = V_66 L_20 ;
F_58 ( V_76 , V_14 -> V_73 ) ;
F_58 ( V_15 , V_14 -> V_77 ) ;
V_14 -> V_3 . V_75 = & V_40 -> V_3 ;
F_65 ( & V_14 -> V_3 , true ) ;
V_27 = F_60 ( V_14 ) ;
if ( V_27 ) {
F_45 ( & V_40 -> V_3 , L_21 , V_27 ) ;
goto V_78;
}
V_27 = F_68 ( & V_14 -> V_3 , & V_79 ) ;
if ( V_27 ) {
F_45 ( & V_40 -> V_3 , L_22 , V_27 ) ;
goto V_80;
}
return 0 ;
V_80:
F_63 ( V_14 ) ;
V_78:
F_61 ( V_14 ) ;
return V_27 ;
}
static void F_69 ( void )
{
F_70 ( & V_14 -> V_3 , & V_79 ) ;
F_63 ( V_14 ) ;
F_61 ( V_14 ) ;
}
static int T_7 F_71 ( struct V_39 * V_40 )
{
struct V_81 * V_82 ;
int V_27 ;
if ( ! F_72 () )
return - V_83 ;
V_27 = F_73 ( V_40 ) ;
if ( V_27 )
return V_27 ;
V_82 = F_74 ( V_40 , V_84 , 0 ) ;
if ( ! V_82 ) {
F_45 ( & V_40 -> V_3 , L_23 ) ;
return - V_85 ;
}
V_43 = V_82 -> V_86 ;
V_27 = F_56 ( V_40 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_64 ( V_40 ) ;
if ( V_27 )
goto V_87;
V_27 = F_67 ( V_40 ) ;
if ( V_27 )
goto V_88;
V_27 = F_53 () ;
if ( V_27 )
goto V_89;
V_27 = F_46 () ;
if ( V_27 )
goto V_90;
F_26 ( V_91 | V_92 ,
V_43 + V_93 ) ;
F_26 ( 0xffffffff , V_43 + V_45 ) ;
F_20 ( false ) ;
F_6 () ;
F_14 () ;
F_16 () ;
V_27 = F_38 ( V_40 ) ;
if ( V_27 )
goto V_94;
F_37 ( V_60 ) ;
return V_27 ;
V_94:
F_51 () ;
V_90:
F_55 () ;
V_89:
F_69 () ;
V_88:
F_66 () ;
V_87:
F_62 () ;
return V_27 ;
}
static int T_8 F_75 ( struct V_39 * V_40 )
{
F_76 ( V_40 ) ;
F_77 ( V_63 , V_40 ) ;
F_78 ( & V_53 ) ;
F_51 () ;
F_55 () ;
F_69 () ;
F_66 () ;
F_62 () ;
V_43 = 0 ;
return 0 ;
}
static int T_9 F_79 ( void )
{
return F_80 ( & V_95 ) ;
}
