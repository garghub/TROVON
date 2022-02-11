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
unsigned long V_27 ;
int V_28 = F_16 ( V_16 , 10 , & V_27 ) ;
if ( V_28 < 0 )
return V_28 ;
V_27 = V_27 / 500 ;
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
unsigned long V_27 ;
int V_28 = F_16 ( V_16 , 10 , & V_27 ) ;
if ( V_28 < 0 )
return V_28 ;
V_27 = V_27 / 500 ;
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
unsigned long V_27 ;
int V_28 = F_16 ( V_16 , 10 , & V_27 ) ;
if ( V_28 < 0 )
return V_28 ;
V_27 = V_27 / 500 ;
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
return sprintf ( V_16 , L_5 , V_24 -> V_25 >> V_29 ,
V_24 -> V_25 & V_30 ) ;
}
static int F_24 ( struct V_31 * V_32 )
{
int V_33 , V_34 , V_35 , V_36 = 0 ;
T_4 V_37 ;
int V_38 = 0 ;
int V_39 = 0 ;
struct V_18 * V_19 = F_25 ( V_32 ) ;
for ( V_33 = 0 ; V_33 < V_40 ; V_33 ++ )
V_39 += F_26 ( V_19 -> V_41 [ V_33 ] & 0x7fff ) ;
V_19 -> V_42 = F_27 ( sizeof( * V_19 -> V_42 ) * V_39 * V_43 ,
V_44 ) ;
if ( ! V_19 -> V_42 )
return - V_45 ;
V_19 -> V_46 = 0 ;
for ( V_33 = 0 ; V_33 < V_40 ; V_33 ++ ) {
V_37 = V_19 -> V_41 [ V_33 ] ;
for ( V_34 = 0 ; V_34 < V_47 ; V_34 ++ , V_37 >>= 1 ) {
struct V_48 * V_49 ;
V_35 = F_6 ( V_33 , V_34 ) ;
if ( ! ( V_37 & 0x1 ) )
continue;
V_36 ++ ;
V_49 = V_19 -> V_42 + V_19 -> V_46 ;
snprintf ( V_49 -> V_50 , V_51 ,
L_6 , V_36 ) ;
V_49 -> V_52 . V_53 . V_24 . V_50 = V_49 -> V_50 ;
V_49 -> V_52 . V_53 . V_24 . V_54 = V_55 ;
V_49 -> V_52 . V_53 . V_56 = F_23 ;
V_49 -> V_52 . V_25 = V_35 ;
F_28 ( & V_49 -> V_52 . V_53 . V_24 ) ;
V_38 = F_29 ( & V_32 -> V_13 ,
& V_49 -> V_52 . V_53 ) ;
if ( V_38 )
goto V_57;
V_19 -> V_46 ++ ;
V_49 = V_19 -> V_42 + V_19 -> V_46 ;
snprintf ( V_49 -> V_50 , V_51 ,
L_7 , V_36 ) ;
V_49 -> V_52 . V_53 . V_24 . V_50 = V_49 -> V_50 ;
V_49 -> V_52 . V_53 . V_24 . V_54 = V_55 ;
V_49 -> V_52 . V_53 . V_56 = F_22 ;
V_49 -> V_52 . V_25 = V_35 ;
F_28 ( & V_49 -> V_52 . V_53 . V_24 ) ;
V_38 = F_29 ( & V_32 -> V_13 ,
& V_49 -> V_52 . V_53 ) ;
if ( V_38 )
goto V_57;
V_19 -> V_46 ++ ;
V_49 = V_19 -> V_42 + V_19 -> V_46 ;
snprintf ( V_49 -> V_50 , V_51 ,
L_8 , V_36 ) ;
V_49 -> V_52 . V_53 . V_24 . V_50 = V_49 -> V_50 ;
V_49 -> V_52 . V_53 . V_24 . V_54 = V_58 | V_55 ;
V_49 -> V_52 . V_53 . V_56 = F_19 ;
V_49 -> V_52 . V_53 . V_59 = F_15 ;
V_49 -> V_52 . V_25 = V_35 ;
F_28 ( & V_49 -> V_52 . V_53 . V_24 ) ;
V_38 = F_29 ( & V_32 -> V_13 ,
& V_49 -> V_52 . V_53 ) ;
if ( V_38 )
goto V_57;
V_19 -> V_46 ++ ;
V_49 = V_19 -> V_42 + V_19 -> V_46 ;
snprintf ( V_49 -> V_50 , V_51 ,
L_9 , V_36 ) ;
V_49 -> V_52 . V_53 . V_24 . V_50 = V_49 -> V_50 ;
V_49 -> V_52 . V_53 . V_24 . V_54 = V_58 | V_55 ;
V_49 -> V_52 . V_53 . V_56 = F_20 ;
V_49 -> V_52 . V_53 . V_59 = F_17 ;
V_49 -> V_52 . V_25 = V_35 ;
F_28 ( & V_49 -> V_52 . V_53 . V_24 ) ;
V_38 = F_29 ( & V_32 -> V_13 ,
& V_49 -> V_52 . V_53 ) ;
if ( V_38 )
goto V_57;
V_19 -> V_46 ++ ;
V_49 = V_19 -> V_42 + V_19 -> V_46 ;
snprintf ( V_49 -> V_50 , V_51 ,
L_10 , V_36 ) ;
V_49 -> V_52 . V_53 . V_24 . V_50 = V_49 -> V_50 ;
V_49 -> V_52 . V_53 . V_24 . V_54 = V_58 | V_55 ;
V_49 -> V_52 . V_53 . V_56 = F_21 ;
V_49 -> V_52 . V_53 . V_59 = F_18 ;
V_49 -> V_52 . V_25 = V_35 ;
F_28 ( & V_49 -> V_52 . V_53 . V_24 ) ;
V_38 = F_29 ( & V_32 -> V_13 ,
& V_49 -> V_52 . V_53 ) ;
if ( V_38 )
goto V_57;
V_19 -> V_46 ++ ;
V_49 = V_19 -> V_42 + V_19 -> V_46 ;
snprintf ( V_49 -> V_50 , V_51 ,
L_11 , V_36 ) ;
V_49 -> V_52 . V_53 . V_24 . V_50 = V_49 -> V_50 ;
V_49 -> V_52 . V_53 . V_24 . V_54 = V_55 ;
V_49 -> V_52 . V_53 . V_56 = F_12 ;
V_49 -> V_52 . V_25 = V_35 ;
F_28 ( & V_49 -> V_52 . V_53 . V_24 ) ;
V_38 = F_29 ( & V_32 -> V_13 ,
& V_49 -> V_52 . V_53 ) ;
if ( V_38 )
goto V_57;
V_19 -> V_46 ++ ;
}
}
V_38 = F_29 ( & V_32 -> V_13 , & V_60 ) ;
if ( V_38 )
goto V_57;
V_19 -> V_61 = F_30 ( & V_32 -> V_13 ) ;
if ( F_31 ( V_19 -> V_61 ) ) {
V_38 = F_32 ( V_19 -> V_61 ) ;
goto V_57;
}
return V_38 ;
V_57:
F_33 ( & V_32 -> V_13 , & V_60 ) ;
for ( V_33 = 0 ; V_33 < V_19 -> V_46 ; V_33 ++ )
F_33 ( & V_32 -> V_13 , & V_19 -> V_42 [ V_33 ] . V_52 . V_53 ) ;
F_34 ( V_19 -> V_42 ) ;
return V_38 ;
}
static int F_35 ( void )
{
int V_38 = - V_62 ;
V_63 = F_36 ( V_17 , 0 ) ;
if ( ! V_63 )
return - V_45 ;
V_38 = F_37 ( V_63 ) ;
if ( V_38 )
goto V_64;
return 0 ;
V_64:
F_38 ( V_63 ) ;
return V_38 ;
}
static int F_39 ( struct V_18 * V_19 ,
unsigned long V_65 )
{
struct V_66 * V_67 ;
T_5 V_68 ;
int V_38 = - V_62 ;
V_67 = F_40 ( V_69 ,
V_65 ,
NULL ) ;
if ( ! V_67 )
return - V_62 ;
if ( F_41 ( V_67 , V_70 , & V_68 ) )
goto V_71;
V_19 -> V_72 = V_68 ;
if ( F_41 ( V_67 , V_73 , & V_68 ) )
goto V_71;
V_19 -> V_74 = V_68 ;
if ( V_19 -> V_74 < V_4 * V_75 ) {
F_42 ( & V_67 -> V_13 , L_12 ) ;
goto V_71;
}
V_38 = 0 ;
V_71:
F_43 ( V_67 ) ;
return V_38 ;
}
static int F_44 ( T_4 * V_41 , unsigned long V_76 )
{
struct V_66 * V_67 ;
T_4 V_77 ;
int V_38 = - V_62 ;
V_67 = F_40 ( V_69 , V_76 , NULL ) ;
if ( ! V_67 )
return - V_62 ;
if ( F_45 ( V_67 , V_78 , & V_77 ) )
goto V_71;
V_41 [ 0 ] = V_77 ;
if ( F_45 ( V_67 , V_79 , & V_77 ) )
goto V_71;
V_41 [ 1 ] = V_77 ;
V_38 = 0 ;
V_71:
F_43 ( V_67 ) ;
return V_38 ;
}
static int F_46 ( struct V_31 * V_32 )
{
struct V_18 * V_19 ;
struct V_80 * V_81 ;
int V_33 , V_38 ;
V_19 = F_27 ( sizeof( * V_19 ) , V_44 ) ;
if ( ! V_19 )
return - V_45 ;
V_33 = 0 ;
do {
V_38 = F_39 ( V_19 , V_82 [ V_33 ] . V_64 ) ;
if ( V_38 == 0 )
break;
V_33 ++ ;
} while ( V_82 [ V_33 ] . V_64 );
if ( V_38 )
goto V_64;
V_38 = F_44 ( & V_19 -> V_41 [ 0 ] , V_82 [ V_33 ] . V_83 ) ;
if ( V_38 )
goto V_64;
F_44 ( & V_19 -> V_41 [ 2 ] , V_82 [ V_33 ] . V_83 + 1 ) ;
V_81 = F_47 ( V_19 -> V_72 , V_19 -> V_74 , V_17 ) ;
if ( ! V_81 ) {
V_38 = - V_84 ;
goto V_64;
}
V_19 -> V_21 = F_48 ( V_19 -> V_72 , V_19 -> V_74 ) ;
if ( ! V_19 -> V_21 ) {
V_38 = - V_84 ;
goto V_85;
}
F_49 ( V_32 , V_19 ) ;
V_38 = F_24 ( V_32 ) ;
if ( V_38 )
goto V_86;
return V_38 ;
V_86:
F_50 ( V_19 -> V_21 ) ;
F_49 ( V_32 , NULL ) ;
V_85:
F_51 ( V_19 -> V_72 , V_19 -> V_74 ) ;
V_64:
F_34 ( V_19 ) ;
return V_38 ;
}
static int F_52 ( struct V_31 * V_32 )
{
int V_33 ;
struct V_18 * V_19 = F_25 ( V_32 ) ;
F_53 ( V_19 -> V_61 ) ;
F_33 ( & V_32 -> V_13 , & V_60 ) ;
for ( V_33 = 0 ; V_33 < V_19 -> V_46 ; V_33 ++ )
F_33 ( & V_32 -> V_13 , & V_19 -> V_42 [ V_33 ] . V_52 . V_53 ) ;
F_34 ( V_19 -> V_42 ) ;
F_50 ( V_19 -> V_21 ) ;
F_51 ( V_19 -> V_72 , V_19 -> V_74 ) ;
F_49 ( V_32 , NULL ) ;
F_34 ( V_19 ) ;
return 0 ;
}
static int T_6 F_54 ( void )
{
int V_38 ;
V_38 = F_55 ( & V_87 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_35 () ;
if ( V_38 )
F_56 ( & V_87 ) ;
return V_38 ;
}
static void T_7 F_57 ( void )
{
F_58 ( V_63 ) ;
F_56 ( & V_87 ) ;
}
