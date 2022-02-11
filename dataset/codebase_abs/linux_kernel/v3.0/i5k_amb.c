static unsigned long F_1 ( unsigned int V_1 )
{
return V_2 + V_3 +
V_4 * V_1 ;
}
static unsigned long F_2 ( unsigned int V_1 )
{
return V_2 + V_5 +
V_4 * V_1 ;
}
static unsigned long F_3 ( unsigned int V_1 )
{
return V_2 + V_6 +
V_4 * V_1 ;
}
static unsigned long F_4 ( unsigned int V_1 )
{
return V_2 + V_7 +
V_4 * V_1 ;
}
static unsigned long F_5 ( unsigned int V_1 )
{
return V_2 + V_8 +
V_4 * V_1 ;
}
static unsigned long F_6 ( unsigned int V_9 , unsigned int V_10 )
{
return V_9 * V_11 + V_10 ;
}
static T_1 F_7 ( struct V_12 * V_13 , struct V_14 * V_15 ,
char * V_16 )
{
return sprintf ( V_16 , L_1 , V_17 ) ;
}
static T_2 F_8 ( struct V_18 * V_19 , unsigned long V_20 )
{
return F_9 ( V_19 -> V_21 + V_20 ) ;
}
static void F_10 ( struct V_18 * V_19 , unsigned long V_20 ,
T_2 V_22 )
{
F_11 ( V_22 , V_19 -> V_21 + V_20 ) ;
}
static T_1 F_12 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_23 * V_24 = F_13 ( V_15 ) ;
struct V_18 * V_19 = F_14 ( V_13 ) ;
if ( ! ( F_8 ( V_19 , F_1 ( V_24 -> V_25 ) ) & 0x20 ) &&
( F_8 ( V_19 , F_1 ( V_24 -> V_25 ) ) & 0x8 ) )
return sprintf ( V_16 , L_2 ) ;
else
return sprintf ( V_16 , L_3 ) ;
}
static T_1 F_15 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
const char * V_16 ,
T_3 V_26 )
{
struct V_23 * V_24 = F_13 ( V_15 ) ;
struct V_18 * V_19 = F_14 ( V_13 ) ;
unsigned long V_27 = F_16 ( V_16 , NULL , 10 ) / 500 ;
if ( V_27 > 255 )
V_27 = 255 ;
F_10 ( V_19 , F_2 ( V_24 -> V_25 ) , V_27 ) ;
return V_26 ;
}
static T_1 F_17 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
const char * V_16 ,
T_3 V_26 )
{
struct V_23 * V_24 = F_13 ( V_15 ) ;
struct V_18 * V_19 = F_14 ( V_13 ) ;
unsigned long V_27 = F_16 ( V_16 , NULL , 10 ) / 500 ;
if ( V_27 > 255 )
V_27 = 255 ;
F_10 ( V_19 , F_3 ( V_24 -> V_25 ) , V_27 ) ;
return V_26 ;
}
static T_1 F_18 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
const char * V_16 ,
T_3 V_26 )
{
struct V_23 * V_24 = F_13 ( V_15 ) ;
struct V_18 * V_19 = F_14 ( V_13 ) ;
unsigned long V_27 = F_16 ( V_16 , NULL , 10 ) / 500 ;
if ( V_27 > 255 )
V_27 = 255 ;
F_10 ( V_19 , F_4 ( V_24 -> V_25 ) , V_27 ) ;
return V_26 ;
}
static T_1 F_19 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_23 * V_24 = F_13 ( V_15 ) ;
struct V_18 * V_19 = F_14 ( V_13 ) ;
return sprintf ( V_16 , L_4 ,
500 * F_8 ( V_19 , F_2 ( V_24 -> V_25 ) ) ) ;
}
static T_1 F_20 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_23 * V_24 = F_13 ( V_15 ) ;
struct V_18 * V_19 = F_14 ( V_13 ) ;
return sprintf ( V_16 , L_4 ,
500 * F_8 ( V_19 , F_3 ( V_24 -> V_25 ) ) ) ;
}
static T_1 F_21 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_23 * V_24 = F_13 ( V_15 ) ;
struct V_18 * V_19 = F_14 ( V_13 ) ;
return sprintf ( V_16 , L_4 ,
500 * F_8 ( V_19 , F_4 ( V_24 -> V_25 ) ) ) ;
}
static T_1 F_22 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_23 * V_24 = F_13 ( V_15 ) ;
struct V_18 * V_19 = F_14 ( V_13 ) ;
return sprintf ( V_16 , L_4 ,
500 * F_8 ( V_19 , F_5 ( V_24 -> V_25 ) ) ) ;
}
static T_1 F_23 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_23 * V_24 = F_13 ( V_15 ) ;
return sprintf ( V_16 , L_5 , V_24 -> V_25 >> V_28 ,
V_24 -> V_25 & V_29 ) ;
}
static int T_4 F_24 ( struct V_30 * V_31 )
{
int V_32 , V_33 , V_34 , V_35 = 0 ;
T_5 V_36 ;
int V_37 = 0 ;
int V_38 = 0 ;
struct V_18 * V_19 = F_25 ( V_31 ) ;
for ( V_32 = 0 ; V_32 < V_39 ; V_32 ++ )
V_38 += F_26 ( V_19 -> V_40 [ V_32 ] & 0x7fff ) ;
V_19 -> V_41 = F_27 ( sizeof( * V_19 -> V_41 ) * V_38 * V_42 ,
V_43 ) ;
if ( ! V_19 -> V_41 )
return - V_44 ;
V_19 -> V_45 = 0 ;
for ( V_32 = 0 ; V_32 < V_39 ; V_32 ++ ) {
V_36 = V_19 -> V_40 [ V_32 ] ;
for ( V_33 = 0 ; V_33 < V_46 ; V_33 ++ , V_36 >>= 1 ) {
struct V_47 * V_48 ;
V_34 = F_6 ( V_32 , V_33 ) ;
if ( ! ( V_36 & 0x1 ) )
continue;
V_35 ++ ;
V_48 = V_19 -> V_41 + V_19 -> V_45 ;
snprintf ( V_48 -> V_49 , V_50 ,
L_6 , V_35 ) ;
V_48 -> V_51 . V_52 . V_24 . V_49 = V_48 -> V_49 ;
V_48 -> V_51 . V_52 . V_24 . V_53 = V_54 ;
V_48 -> V_51 . V_52 . V_55 = F_23 ;
V_48 -> V_51 . V_25 = V_34 ;
F_28 ( & V_48 -> V_51 . V_52 . V_24 ) ;
V_37 = F_29 ( & V_31 -> V_13 ,
& V_48 -> V_51 . V_52 ) ;
if ( V_37 )
goto V_56;
V_19 -> V_45 ++ ;
V_48 = V_19 -> V_41 + V_19 -> V_45 ;
snprintf ( V_48 -> V_49 , V_50 ,
L_7 , V_35 ) ;
V_48 -> V_51 . V_52 . V_24 . V_49 = V_48 -> V_49 ;
V_48 -> V_51 . V_52 . V_24 . V_53 = V_54 ;
V_48 -> V_51 . V_52 . V_55 = F_22 ;
V_48 -> V_51 . V_25 = V_34 ;
F_28 ( & V_48 -> V_51 . V_52 . V_24 ) ;
V_37 = F_29 ( & V_31 -> V_13 ,
& V_48 -> V_51 . V_52 ) ;
if ( V_37 )
goto V_56;
V_19 -> V_45 ++ ;
V_48 = V_19 -> V_41 + V_19 -> V_45 ;
snprintf ( V_48 -> V_49 , V_50 ,
L_8 , V_35 ) ;
V_48 -> V_51 . V_52 . V_24 . V_49 = V_48 -> V_49 ;
V_48 -> V_51 . V_52 . V_24 . V_53 = V_57 | V_54 ;
V_48 -> V_51 . V_52 . V_55 = F_19 ;
V_48 -> V_51 . V_52 . V_58 = F_15 ;
V_48 -> V_51 . V_25 = V_34 ;
F_28 ( & V_48 -> V_51 . V_52 . V_24 ) ;
V_37 = F_29 ( & V_31 -> V_13 ,
& V_48 -> V_51 . V_52 ) ;
if ( V_37 )
goto V_56;
V_19 -> V_45 ++ ;
V_48 = V_19 -> V_41 + V_19 -> V_45 ;
snprintf ( V_48 -> V_49 , V_50 ,
L_9 , V_35 ) ;
V_48 -> V_51 . V_52 . V_24 . V_49 = V_48 -> V_49 ;
V_48 -> V_51 . V_52 . V_24 . V_53 = V_57 | V_54 ;
V_48 -> V_51 . V_52 . V_55 = F_20 ;
V_48 -> V_51 . V_52 . V_58 = F_17 ;
V_48 -> V_51 . V_25 = V_34 ;
F_28 ( & V_48 -> V_51 . V_52 . V_24 ) ;
V_37 = F_29 ( & V_31 -> V_13 ,
& V_48 -> V_51 . V_52 ) ;
if ( V_37 )
goto V_56;
V_19 -> V_45 ++ ;
V_48 = V_19 -> V_41 + V_19 -> V_45 ;
snprintf ( V_48 -> V_49 , V_50 ,
L_10 , V_35 ) ;
V_48 -> V_51 . V_52 . V_24 . V_49 = V_48 -> V_49 ;
V_48 -> V_51 . V_52 . V_24 . V_53 = V_57 | V_54 ;
V_48 -> V_51 . V_52 . V_55 = F_21 ;
V_48 -> V_51 . V_52 . V_58 = F_18 ;
V_48 -> V_51 . V_25 = V_34 ;
F_28 ( & V_48 -> V_51 . V_52 . V_24 ) ;
V_37 = F_29 ( & V_31 -> V_13 ,
& V_48 -> V_51 . V_52 ) ;
if ( V_37 )
goto V_56;
V_19 -> V_45 ++ ;
V_48 = V_19 -> V_41 + V_19 -> V_45 ;
snprintf ( V_48 -> V_49 , V_50 ,
L_11 , V_35 ) ;
V_48 -> V_51 . V_52 . V_24 . V_49 = V_48 -> V_49 ;
V_48 -> V_51 . V_52 . V_24 . V_53 = V_54 ;
V_48 -> V_51 . V_52 . V_55 = F_12 ;
V_48 -> V_51 . V_25 = V_34 ;
F_28 ( & V_48 -> V_51 . V_52 . V_24 ) ;
V_37 = F_29 ( & V_31 -> V_13 ,
& V_48 -> V_51 . V_52 ) ;
if ( V_37 )
goto V_56;
V_19 -> V_45 ++ ;
}
}
V_37 = F_29 ( & V_31 -> V_13 , & V_59 ) ;
if ( V_37 )
goto V_56;
V_19 -> V_60 = F_30 ( & V_31 -> V_13 ) ;
if ( F_31 ( V_19 -> V_60 ) ) {
V_37 = F_32 ( V_19 -> V_60 ) ;
goto V_56;
}
return V_37 ;
V_56:
F_33 ( & V_31 -> V_13 , & V_59 ) ;
for ( V_32 = 0 ; V_32 < V_19 -> V_45 ; V_32 ++ )
F_33 ( & V_31 -> V_13 , & V_19 -> V_41 [ V_32 ] . V_51 . V_52 ) ;
F_34 ( V_19 -> V_41 ) ;
return V_37 ;
}
static int T_4 F_35 ( void )
{
int V_37 = - V_61 ;
V_62 = F_36 ( V_17 , 0 ) ;
if ( ! V_62 )
return - V_44 ;
V_37 = F_37 ( V_62 ) ;
if ( V_37 )
goto V_63;
return 0 ;
V_63:
F_38 ( V_62 ) ;
return V_37 ;
}
static int T_4 F_39 ( struct V_18 * V_19 ,
unsigned long V_64 )
{
struct V_65 * V_66 ;
T_6 V_67 ;
int V_37 = - V_61 ;
V_66 = F_40 ( V_68 ,
V_64 ,
NULL ) ;
if ( ! V_66 )
return - V_61 ;
if ( F_41 ( V_66 , V_69 , & V_67 ) )
goto V_70;
V_19 -> V_71 = V_67 ;
if ( F_41 ( V_66 , V_72 , & V_67 ) )
goto V_70;
V_19 -> V_73 = V_67 ;
if ( V_19 -> V_73 < V_4 * V_74 ) {
F_42 ( & V_66 -> V_13 , L_12 ) ;
goto V_70;
}
V_19 -> V_75 = V_64 ;
V_37 = 0 ;
V_70:
F_43 ( V_66 ) ;
return V_37 ;
}
static int T_4 F_44 ( T_5 * V_40 , unsigned long V_76 )
{
struct V_65 * V_66 ;
T_5 V_77 ;
int V_37 = - V_61 ;
V_66 = F_40 ( V_68 , V_76 , NULL ) ;
if ( ! V_66 )
return - V_61 ;
if ( F_45 ( V_66 , V_78 , & V_77 ) )
goto V_70;
V_40 [ 0 ] = V_77 ;
if ( F_45 ( V_66 , V_79 , & V_77 ) )
goto V_70;
V_40 [ 1 ] = V_77 ;
V_37 = 0 ;
V_70:
F_43 ( V_66 ) ;
return V_37 ;
}
static unsigned long F_46 ( struct V_18 * V_19 ,
unsigned long V_80 )
{
switch ( V_19 -> V_75 ) {
case V_81 :
return V_82 + V_80 ;
case V_83 :
return V_84 + V_80 ;
default:
F_47 () ;
}
}
static int T_4 F_48 ( struct V_30 * V_31 )
{
struct V_18 * V_19 ;
struct V_85 * V_86 ;
int V_32 ;
int V_37 = - V_61 ;
V_19 = F_27 ( sizeof( * V_19 ) , V_43 ) ;
if ( ! V_19 )
return - V_44 ;
V_32 = 0 ;
do {
V_37 = F_39 ( V_19 , V_87 [ V_32 ] ) ;
V_32 ++ ;
} while ( V_37 && V_87 [ V_32 ] );
if ( V_37 )
goto V_63;
V_37 = F_44 ( & V_19 -> V_40 [ 0 ] ,
F_46 ( V_19 , 0 ) ) ;
if ( V_37 )
goto V_63;
F_44 ( & V_19 -> V_40 [ 2 ] ,
F_46 ( V_19 , 1 ) ) ;
V_86 = F_49 ( V_19 -> V_71 , V_19 -> V_73 , V_17 ) ;
if ( ! V_86 ) {
V_37 = - V_88 ;
goto V_63;
}
V_19 -> V_21 = F_50 ( V_19 -> V_71 , V_19 -> V_73 ) ;
if ( ! V_19 -> V_21 ) {
V_37 = - V_88 ;
goto V_89;
}
F_51 ( V_31 , V_19 ) ;
V_37 = F_24 ( V_31 ) ;
if ( V_37 )
goto V_90;
return V_37 ;
V_90:
F_52 ( V_19 -> V_21 ) ;
F_51 ( V_31 , NULL ) ;
V_89:
F_53 ( V_19 -> V_71 , V_19 -> V_73 ) ;
V_63:
F_34 ( V_19 ) ;
return V_37 ;
}
static int T_7 F_54 ( struct V_30 * V_31 )
{
int V_32 ;
struct V_18 * V_19 = F_25 ( V_31 ) ;
F_55 ( V_19 -> V_60 ) ;
F_33 ( & V_31 -> V_13 , & V_59 ) ;
for ( V_32 = 0 ; V_32 < V_19 -> V_45 ; V_32 ++ )
F_33 ( & V_31 -> V_13 , & V_19 -> V_41 [ V_32 ] . V_51 . V_52 ) ;
F_34 ( V_19 -> V_41 ) ;
F_52 ( V_19 -> V_21 ) ;
F_53 ( V_19 -> V_71 , V_19 -> V_73 ) ;
F_51 ( V_31 , NULL ) ;
F_34 ( V_19 ) ;
return 0 ;
}
static int T_8 F_56 ( void )
{
int V_37 ;
V_37 = F_57 ( & V_91 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_35 () ;
if ( V_37 )
F_58 ( & V_91 ) ;
return V_37 ;
}
static void T_9 F_59 ( void )
{
F_60 ( V_62 ) ;
F_58 ( & V_91 ) ;
}
