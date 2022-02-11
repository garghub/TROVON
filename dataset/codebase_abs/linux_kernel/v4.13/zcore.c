int F_1 ( void T_1 * V_1 , unsigned long V_2 , T_2 V_3 )
{
unsigned long V_4 , V_5 ;
if ( ! V_6 )
return - V_7 ;
while ( V_3 ) {
if ( F_2 ( V_8 , V_2 / V_9 + 2 , 1 ) ) {
F_3 ( L_1 ) ;
return - V_10 ;
}
V_4 = V_2 % V_9 ;
V_5 = F_4 ( V_9 - V_4 , V_3 ) ;
if ( F_5 ( V_1 , V_8 + V_4 , V_5 ) )
return - V_11 ;
V_2 += V_5 ;
V_1 += V_5 ;
V_3 -= V_5 ;
}
return 0 ;
}
int F_6 ( void * V_1 , unsigned long V_2 , T_2 V_3 )
{
unsigned long V_4 , V_5 ;
if ( ! V_6 )
return - V_7 ;
while ( V_3 ) {
if ( F_2 ( V_8 , V_2 / V_9 + 2 , 1 ) ) {
F_3 ( L_1 ) ;
return - V_10 ;
}
V_4 = V_2 % V_9 ;
V_5 = F_4 ( V_9 - V_4 , V_3 ) ;
memcpy ( V_1 , V_8 + V_4 , V_5 ) ;
V_2 += V_5 ;
V_1 += V_5 ;
V_3 -= V_5 ;
}
return 0 ;
}
static int T_3 F_7 ( void )
{
struct V_12 * V_13 ;
V_13 = F_8 () ;
if ( ! V_13 )
return - V_14 ;
if ( F_6 ( V_8 , V_15 , 512 ) < 0 ) {
F_3 ( L_2 ) ;
return - V_10 ;
}
F_9 ( V_13 , V_8 ) ;
return 0 ;
}
static void F_10 ( void )
{
F_11 ( V_16 , NULL ) ;
V_6 = 0 ;
}
static T_4 F_12 ( struct V_17 * V_18 , char T_1 * V_19 ,
T_2 V_3 , T_5 * V_20 )
{
return F_13 ( V_19 , V_3 , V_20 , V_18 -> V_21 ,
V_22 . V_23 . V_24 * V_25 ) ;
}
static int F_14 ( struct V_26 * V_26 , struct V_17 * V_18 )
{
struct V_27 * V_28 ;
char * V_19 ;
int V_29 = 0 ;
V_19 = F_15 ( V_22 . V_23 . V_24 * V_25 , V_30 ) ;
if ( ! V_19 ) {
return - V_14 ;
}
F_16 (memory, reg) {
sprintf ( V_19 + ( V_29 ++ * V_25 ) , L_3 ,
( unsigned long long ) V_28 -> V_31 ,
( unsigned long long ) V_28 -> V_32 ) ;
}
V_18 -> V_21 = V_19 ;
return F_17 ( V_26 , V_18 ) ;
}
static int F_18 ( struct V_26 * V_26 , struct V_17 * V_18 )
{
F_19 ( V_18 -> V_21 ) ;
return 0 ;
}
static T_4 F_20 ( struct V_17 * V_18 , const char T_1 * V_19 ,
T_2 V_3 , T_5 * V_20 )
{
if ( V_33 ) {
F_11 ( V_34 , V_33 ) ;
F_11 ( V_35 , NULL ) ;
}
return V_3 ;
}
static int F_21 ( struct V_26 * V_26 , struct V_17 * V_18 )
{
return F_17 ( V_26 , V_18 ) ;
}
static int F_22 ( struct V_26 * V_26 , struct V_17 * V_18 )
{
return 0 ;
}
static T_4 F_23 ( struct V_17 * V_18 , char T_1 * V_19 ,
T_2 V_3 , T_5 * V_20 )
{
static char V_36 [ 18 ] ;
if ( V_6 )
snprintf ( V_36 , sizeof( V_36 ) , L_4 , V_37 . V_38 ) ;
else
snprintf ( V_36 , sizeof( V_36 ) , L_5 ) ;
return F_13 ( V_19 , V_3 , V_20 , V_36 , strlen ( V_36 ) ) ;
}
static T_4 F_24 ( struct V_17 * V_18 , const char T_1 * V_19 ,
T_2 V_3 , T_5 * V_20 )
{
char V_39 ;
if ( * V_20 != 0 )
return - V_40 ;
if ( F_25 ( & V_39 , V_19 , 1 ) )
return - V_11 ;
if ( V_39 != '0' )
return - V_41 ;
F_10 () ;
return V_3 ;
}
static int T_3 F_26 ( void )
{
if ( ! V_37 . V_38 ) {
F_3 ( L_6 ) ;
return - V_42 ;
}
return 0 ;
}
static int T_3 F_27 ( void )
{
struct V_43 V_43 ;
int V_44 ;
V_44 = F_6 ( & V_43 , V_45 , sizeof( V_43 ) ) ;
if ( V_44 )
return V_44 ;
if ( V_43 . V_46 == 0 )
return 0 ;
V_33 = ( void * ) F_28 ( V_30 ) ;
if ( ! V_33 )
return - V_14 ;
if ( V_43 . V_46 < V_37 . V_38 )
V_44 = F_6 ( V_33 , V_43 . V_46 , V_9 ) ;
else
V_44 = F_29 ( V_33 , ( void * ) V_43 . V_46 , V_9 ) ;
if ( V_44 || ( V_47 V_48 ) F_30 ( V_33 , V_33 -> V_49 . V_50 , 0 ) !=
V_43 . V_51 ) {
F_3 ( L_7 ) ;
F_31 ( ( unsigned long ) V_33 ) ;
V_33 = NULL ;
}
return 0 ;
}
static int T_3 F_32 ( void )
{
unsigned char V_52 ;
int V_44 ;
if ( V_53 . type != V_54 )
return - V_7 ;
if ( V_55 )
return - V_7 ;
V_56 = F_33 ( L_8 , 4 , 1 , 4 * sizeof( long ) ) ;
F_34 ( V_56 , & V_57 ) ;
F_35 ( V_56 , 6 ) ;
F_3 ( L_9 , V_53 . V_58 . V_59 . V_60 . V_61 ) ;
F_3 ( L_10 , ( unsigned long long ) V_53 . V_58 . V_59 . V_62 ) ;
F_3 ( L_11 , ( unsigned long long ) V_53 . V_58 . V_59 . V_63 ) ;
V_44 = F_36 () ;
if ( V_44 )
goto V_64;
V_44 = F_26 () ;
if ( V_44 )
goto V_64;
V_6 = 1 ;
V_44 = F_6 ( & V_52 , V_65 , 1 ) ;
if ( V_44 )
goto V_64;
if ( V_52 == V_66 ) {
F_37 ( L_12
L_13 ) ;
V_44 = - V_41 ;
goto V_64;
}
F_37 ( L_14 ) ;
V_44 = F_7 () ;
if ( V_44 )
goto V_64;
V_44 = F_27 () ;
if ( V_44 )
goto V_64;
V_67 = F_38 ( L_8 , NULL ) ;
if ( ! V_67 ) {
V_44 = - V_14 ;
goto V_64;
}
V_68 = F_39 ( L_15 , V_69 , V_67 ,
NULL , & V_70 ) ;
if ( ! V_68 ) {
V_44 = - V_14 ;
goto V_71;
}
V_72 = F_39 ( L_16 , V_69 , V_67 ,
NULL , & V_73 ) ;
if ( ! V_72 ) {
V_44 = - V_14 ;
goto V_74;
}
V_75 = F_39 ( L_17 , V_69 | V_76 , V_67 ,
NULL , & V_77 ) ;
if ( ! V_75 ) {
V_44 = - V_14 ;
goto V_78;
}
return 0 ;
V_78:
F_40 ( V_72 ) ;
V_74:
F_40 ( V_68 ) ;
V_71:
F_40 ( V_67 ) ;
V_64:
F_11 ( V_16 , NULL ) ;
return V_44 ;
}
