static inline T_1 F_1 ( T_2 V_1 )
{
return F_2 ( V_1 ) & 0xff ;
}
static inline int F_3 ( T_2 V_1 , T_1 V_2 )
{
if ( F_1 ( V_1 ) == V_2 )
return 0 ;
return - V_3 ;
}
static int F_4 ( T_2 V_1 , T_1 V_2 )
{
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < 20 ; V_4 ++ ) {
if ( ! F_3 ( V_1 , V_2 ) )
return 0 ;
F_5 ( 5 ) ;
}
return - V_5 ;
}
static void F_6 ( void )
{
F_5 ( 200 ) ;
if ( F_2 ( 0x1604 ) != V_6 ) {
F_7 ( 0x11 , 0x1610 ) ;
F_7 ( 0x01 , 0x161f ) ;
}
}
static int F_8 ( void )
{
F_6 () ;
return F_4 ( 0x1604 , V_6 ) ;
}
static inline void F_9 ( void )
{
F_2 ( 0x161f ) ;
F_2 ( 0x1604 ) ;
F_6 () ;
}
static int F_10 ( unsigned int V_1 , T_1 * V_2 )
{
int V_7 ;
F_11 ( & V_8 ) ;
V_7 = F_8 () ;
if ( V_7 )
goto V_9;
* V_2 = F_2 ( V_1 ) ;
F_9 () ;
V_9:
F_12 ( & V_8 ) ;
return V_7 ;
}
static int F_13 ( unsigned int V_10 , unsigned int V_11 ,
int * V_12 , int * V_13 )
{
if ( F_8 () )
return - V_5 ;
* V_13 = F_14 ( V_11 ) ;
* V_12 = F_14 ( V_10 ) ;
V_14 = F_2 ( V_15 ) ;
F_9 () ;
if ( V_16 & V_17 )
* V_12 = - * V_12 ;
if ( V_16 & V_18 )
* V_13 = - * V_13 ;
return 0 ;
}
static int F_15 ( unsigned int V_10 , unsigned int V_11 ,
int * V_19 , int * V_20 )
{
int V_7 ;
F_11 ( & V_8 ) ;
V_7 = F_13 ( V_10 , V_11 , V_19 , V_20 ) ;
F_12 ( & V_8 ) ;
return V_7 ;
}
static int F_16 ( void )
{
int V_21 , V_7 = - V_22 ;
F_11 ( & V_8 ) ;
F_7 ( 0x13 , 0x1610 ) ;
F_7 ( 0x01 , 0x161f ) ;
if ( F_4 ( 0x161f , 0x00 ) )
goto V_9;
if ( F_3 ( 0x1611 , 0x03 ) &&
F_3 ( 0x1611 , 0x02 ) &&
F_3 ( 0x1611 , 0x01 ) )
goto V_9;
F_17 ( V_23 L_1 ,
F_1 ( 0x1611 ) ) ;
F_7 ( 0x17 , 0x1610 ) ;
F_7 ( 0x81 , 0x1611 ) ;
F_7 ( 0x01 , 0x161f ) ;
if ( F_4 ( 0x161f , 0x00 ) )
goto V_9;
if ( F_4 ( 0x1611 , 0x00 ) )
goto V_9;
if ( F_4 ( 0x1612 , 0x60 ) )
goto V_9;
if ( F_4 ( 0x1613 , 0x00 ) )
goto V_9;
F_7 ( 0x14 , 0x1610 ) ;
F_7 ( 0x01 , 0x1611 ) ;
F_7 ( 0x01 , 0x161f ) ;
if ( F_4 ( 0x161f , 0x00 ) )
goto V_9;
F_7 ( 0x10 , 0x1610 ) ;
F_7 ( 0xc8 , 0x1611 ) ;
F_7 ( 0x00 , 0x1612 ) ;
F_7 ( 0x02 , 0x1613 ) ;
F_7 ( 0x01 , 0x161f ) ;
if ( F_4 ( 0x161f , 0x00 ) )
goto V_9;
if ( F_8 () )
goto V_9;
if ( F_4 ( 0x1611 , 0x00 ) )
goto V_9;
for ( V_21 = V_24 ; V_21 > 0 ; V_21 -= V_25 ) {
int V_12 , V_13 ;
F_13 ( V_26 , V_27 , & V_12 , & V_13 ) ;
if ( ! F_4 ( 0x1611 , 0x02 ) ) {
V_7 = 0 ;
break;
}
F_18 ( V_25 ) ;
}
V_9:
F_12 ( & V_8 ) ;
return V_7 ;
}
static int F_19 ( struct V_28 * V_29 )
{
int V_7 ;
V_7 = F_16 () ;
if ( V_7 )
return V_7 ;
F_20 ( L_2 ) ;
return 0 ;
}
static int F_21 ( struct V_28 * V_29 )
{
return F_16 () ;
}
static void F_22 ( void )
{
F_13 ( V_26 , V_27 , & V_30 , & V_31 ) ;
}
static void F_23 ( struct V_32 * V_29 )
{
struct V_33 * V_33 = V_29 -> V_34 ;
int V_12 , V_13 ;
F_11 ( & V_8 ) ;
if ( F_13 ( V_26 , V_27 , & V_12 , & V_13 ) )
goto V_9;
F_24 ( V_33 , V_35 , V_12 - V_30 ) ;
F_24 ( V_33 , V_36 , V_13 - V_31 ) ;
F_25 ( V_33 ) ;
V_9:
F_12 ( & V_8 ) ;
}
static T_3 F_26 ( struct V_37 * V_29 ,
struct V_38 * V_39 , char * V_40 )
{
int V_7 , V_12 , V_13 ;
V_7 = F_15 ( V_26 , V_27 , & V_12 , & V_13 ) ;
if ( V_7 )
return V_7 ;
return sprintf ( V_40 , L_3 , V_12 , V_13 ) ;
}
static T_3 F_27 ( struct V_37 * V_29 ,
struct V_38 * V_39 , char * V_40 )
{
int V_7 , V_12 , V_13 ;
V_7 = F_15 ( V_41 , V_42 , & V_12 , & V_13 ) ;
if ( V_7 )
return V_7 ;
return sprintf ( V_40 , L_3 , V_12 , V_13 ) ;
}
static T_3 F_28 ( struct V_37 * V_29 ,
struct V_38 * V_39 , char * V_40 )
{
T_1 V_43 ;
int V_7 ;
V_7 = F_10 ( V_44 , & V_43 ) ;
if ( V_7 < 0 )
return V_7 ;
return sprintf ( V_40 , L_4 , V_43 ) ;
}
static T_3 F_29 ( struct V_37 * V_29 ,
struct V_38 * V_39 , char * V_40 )
{
T_1 V_43 ;
int V_7 ;
V_7 = F_10 ( V_45 , & V_43 ) ;
if ( V_7 < 0 )
return V_7 ;
return sprintf ( V_40 , L_4 , V_43 ) ;
}
static T_3 F_30 ( struct V_37 * V_29 ,
struct V_38 * V_39 ,
char * V_40 )
{
return sprintf ( V_40 , L_4 , F_31 ( V_14 ) ) ;
}
static T_3 F_32 ( struct V_37 * V_29 ,
struct V_38 * V_39 ,
char * V_40 )
{
return sprintf ( V_40 , L_4 , F_33 ( V_14 ) ) ;
}
static T_3 F_34 ( struct V_37 * V_29 ,
struct V_38 * V_39 , char * V_40 )
{
return sprintf ( V_40 , L_3 , V_30 , V_31 ) ;
}
static T_3 F_35 ( struct V_37 * V_29 ,
struct V_38 * V_39 ,
const char * V_40 , T_4 V_46 )
{
F_11 ( & V_8 ) ;
F_22 () ;
F_12 ( & V_8 ) ;
return V_46 ;
}
static T_3 F_36 ( struct V_37 * V_29 ,
struct V_38 * V_39 , char * V_40 )
{
return sprintf ( V_40 , L_4 , V_16 ) ;
}
static T_3 F_37 ( struct V_37 * V_29 ,
struct V_38 * V_39 ,
const char * V_40 , T_4 V_46 )
{
int V_47 ;
if ( sscanf ( V_40 , L_5 , & V_47 ) != 1 ||
V_47 < 0 || V_47 > V_48 )
return - V_3 ;
V_16 = V_47 ;
F_22 () ;
return V_46 ;
}
static int T_5 F_38 ( const struct V_49 * V_50 )
{
F_20 ( L_6 , V_50 -> V_51 ) ;
return 1 ;
}
static int T_5 F_39 ( const struct V_49 * V_50 )
{
V_16 = ( unsigned long ) V_50 -> V_52 ;
F_20 ( L_7 , V_16 ) ;
return F_38 ( V_50 ) ;
}
static int T_5 F_40 ( void )
{
struct V_33 * V_53 ;
int V_7 ;
if ( ! F_41 ( V_54 ) ) {
F_42 ( L_8 ) ;
V_7 = - V_55 ;
goto V_9;
}
if ( ! F_43 ( V_56 , V_57 , L_9 ) ) {
V_7 = - V_22 ;
goto V_9;
}
V_7 = F_44 ( & V_58 ) ;
if ( V_7 )
goto V_59;
V_60 = F_45 ( L_9 , - 1 , NULL , 0 ) ;
if ( F_46 ( V_60 ) ) {
V_7 = F_47 ( V_60 ) ;
goto V_61;
}
V_7 = F_48 ( & V_60 -> V_29 . V_62 , & V_63 ) ;
if ( V_7 )
goto V_64;
V_65 = F_49 () ;
if ( ! V_65 ) {
V_7 = - V_66 ;
goto V_67;
}
V_65 -> V_68 = F_23 ;
V_65 -> V_69 = V_70 ;
F_22 () ;
V_53 = V_65 -> V_34 ;
V_53 -> V_71 = L_9 ;
V_53 -> V_72 = L_10 ;
V_53 -> V_50 . V_73 = V_74 ;
V_53 -> V_29 . V_75 = & V_60 -> V_29 ;
V_53 -> V_76 [ 0 ] = F_50 ( V_77 ) ;
F_51 ( V_53 , V_35 ,
- 256 , 256 , V_78 , V_79 ) ;
F_51 ( V_53 , V_36 ,
- 256 , 256 , V_78 , V_79 ) ;
V_7 = F_52 ( V_65 ) ;
if ( V_7 )
goto V_80;
F_20 ( L_11 ) ;
return 0 ;
V_80:
F_53 ( V_65 ) ;
V_67:
F_54 ( & V_60 -> V_29 . V_62 , & V_63 ) ;
V_64:
F_55 ( V_60 ) ;
V_61:
F_56 ( & V_58 ) ;
V_59:
F_57 ( V_56 , V_57 ) ;
V_9:
F_42 ( L_12 , V_7 ) ;
return V_7 ;
}
static void T_6 F_58 ( void )
{
F_59 ( V_65 ) ;
F_53 ( V_65 ) ;
F_54 ( & V_60 -> V_29 . V_62 , & V_63 ) ;
F_55 ( V_60 ) ;
F_56 ( & V_58 ) ;
F_57 ( V_56 , V_57 ) ;
F_20 ( L_13 ) ;
}
