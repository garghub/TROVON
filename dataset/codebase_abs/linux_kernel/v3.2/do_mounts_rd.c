static int T_1 F_1 ( char * V_1 )
{
V_2 = F_2 ( V_1 , NULL , 0 ) & 1 ;
return 1 ;
}
static int T_1 F_3 ( char * V_1 )
{
V_3 = F_2 ( V_1 , NULL , 0 ) ;
return 1 ;
}
static int T_1
F_4 ( int V_4 , int V_5 , T_2 * V_6 )
{
const int V_7 = 512 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
int V_18 = - 1 ;
unsigned char * V_19 ;
const char * V_20 ;
V_19 = F_5 ( V_7 , V_21 ) ;
if ( ! V_19 )
return - V_22 ;
V_9 = (struct V_8 * ) V_19 ;
V_11 = (struct V_10 * ) V_19 ;
V_13 = (struct V_12 * ) V_19 ;
V_15 = (struct V_14 * ) V_19 ;
V_17 = (struct V_16 * ) V_19 ;
memset ( V_19 , 0xe5 , V_7 ) ;
F_6 ( V_4 , V_5 * V_23 , 0 ) ;
F_7 ( V_4 , V_19 , V_7 ) ;
* V_6 = F_8 ( V_19 , V_7 , & V_20 ) ;
if ( V_20 ) {
F_9 ( V_24 L_1 ,
V_20 , V_5 ) ;
if ( ! * V_6 )
F_9 ( V_25
L_2 ,
V_20 ) ;
V_18 = 0 ;
goto V_26;
}
if ( V_13 -> V_27 == V_28 &&
V_13 -> V_29 == V_30 ) {
F_9 ( V_24
L_3 ,
V_5 ) ;
V_18 = ( F_10 ( V_13 -> V_7 ) + V_23 - 1 ) >> V_31 ;
goto V_26;
}
if ( V_15 -> V_32 == V_33 ) {
F_9 ( V_24
L_4 ,
V_5 ) ;
V_18 = ( V_15 -> V_7 + V_23 - 1 ) >> V_31 ;
goto V_26;
}
if ( F_11 ( V_17 -> V_34 ) == V_35 ) {
F_9 ( V_24
L_5 ,
V_5 ) ;
V_18 = ( F_12 ( V_17 -> V_36 ) + V_23 - 1 )
>> V_31 ;
goto V_26;
}
F_6 ( V_4 , V_5 * V_23 + 0x200 , 0 ) ;
F_7 ( V_4 , V_19 , V_7 ) ;
if ( V_15 -> V_32 == V_33 ) {
F_9 ( V_24
L_4 ,
V_5 ) ;
V_18 = ( V_15 -> V_7 + V_23 - 1 ) >> V_31 ;
goto V_26;
}
F_6 ( V_4 , ( V_5 + 1 ) * V_23 , 0 ) ;
F_7 ( V_4 , V_19 , V_7 ) ;
if ( V_9 -> V_34 == V_37 ||
V_9 -> V_34 == V_38 ) {
F_9 ( V_24
L_6 ,
V_5 ) ;
V_18 = V_9 -> V_39 << V_9 -> V_40 ;
goto V_26;
}
if ( V_11 -> V_34 == F_13 ( V_41 ) ) {
F_9 ( V_24
L_7 ,
V_5 ) ;
V_18 = F_11 ( V_11 -> V_42 ) <<
F_11 ( V_11 -> V_43 ) ;
goto V_26;
}
F_9 ( V_24
L_8 ,
V_5 ) ;
V_26:
F_6 ( V_4 , V_5 * V_23 , 0 ) ;
F_14 ( V_19 ) ;
return V_18 ;
}
int T_1 F_15 ( char * V_44 )
{
int V_45 = 0 ;
int V_46 , V_47 ;
unsigned long V_48 , V_49 ;
int V_18 , V_50 , V_51 ;
char * V_19 = NULL ;
unsigned short V_52 = 0 ;
T_2 V_6 = NULL ;
#if ! F_16 ( V_53 ) && ! F_16 ( V_54 )
char V_55 [ 4 ] = { '|' , '/' , '-' , '\\' } ;
#endif
V_47 = F_17 ( ( const char V_56 V_57 * ) L_9 , V_58 , 0 ) ;
if ( V_47 < 0 )
goto V_59;
V_46 = F_17 ( V_44 , V_60 , 0 ) ;
if ( V_46 < 0 )
goto V_61;
V_18 = F_4 ( V_46 , V_3 , & V_6 ) ;
if ( V_18 < 0 )
goto V_26;
if ( V_18 == 0 ) {
if ( F_18 ( V_46 , V_47 , V_6 ) == 0 )
goto V_62;
goto V_26;
}
if ( F_19 ( V_47 , V_63 , ( unsigned long ) & V_48 ) < 0 )
V_48 = 0 ;
else
V_48 >>= 1 ;
if ( V_18 > V_48 ) {
F_9 ( L_10 ,
V_18 , V_48 ) ;
goto V_26;
}
if ( F_19 ( V_46 , V_63 , ( unsigned long ) & V_49 ) < 0 )
V_49 = 0 ;
else
V_49 >>= 1 ;
if ( strcmp ( V_44 , L_11 ) == 0 )
V_49 = V_18 ;
if ( V_49 == 0 ) {
F_9 ( V_64 L_12 ) ;
goto V_26;
}
V_19 = F_5 ( V_23 , V_21 ) ;
if ( ! V_19 ) {
F_9 ( V_64 L_13 ) ;
goto V_26;
}
F_9 ( V_24 L_14 ,
V_18 , ( ( V_18 - 1 ) / V_49 ) + 1 , V_18 > V_49 ? L_15 : L_16 ) ;
for ( V_50 = 0 , V_51 = 1 ; V_50 < V_18 ; V_50 ++ ) {
if ( V_50 && ( V_50 % V_49 == 0 ) ) {
F_9 ( L_17 , V_51 ++ ) ;
V_52 = 0 ;
if ( F_20 ( V_46 ) ) {
F_9 ( L_18 ) ;
goto V_61;
}
F_21 ( L_19 , V_51 ) ;
V_46 = F_17 ( V_44 , V_60 , 0 ) ;
if ( V_46 < 0 ) {
F_9 ( L_20 ) ;
goto V_61;
}
F_9 ( L_21 , V_51 ) ;
}
F_7 ( V_46 , V_19 , V_23 ) ;
F_22 ( V_47 , V_19 , V_23 ) ;
#if ! F_16 ( V_53 ) && ! F_16 ( V_54 )
if ( ! ( V_50 % 16 ) ) {
F_9 ( L_22 , V_55 [ V_52 & 0x3 ] ) ;
V_52 ++ ;
}
#endif
}
F_9 ( L_23 ) ;
V_62:
V_45 = 1 ;
V_26:
F_20 ( V_46 ) ;
V_61:
F_20 ( V_47 ) ;
V_59:
F_14 ( V_19 ) ;
F_23 ( ( const char V_56 V_57 * ) L_9 ) ;
return V_45 ;
}
int T_1 F_24 ( int V_65 )
{
if ( V_2 )
F_21 ( L_24 ) ;
F_25 ( L_25 , V_66 ) ;
F_25 ( L_9 , F_26 ( V_67 , V_65 ) ) ;
return F_15 ( L_25 ) ;
}
static int T_1 F_27 ( void * V_19 , unsigned int V_68 )
{
int V_69 = F_7 ( V_70 , V_19 , V_68 ) ;
if ( V_69 < 0 )
F_9 ( V_64 L_26 ) ;
else if ( V_69 == 0 )
F_9 ( V_64 L_27 ) ;
return V_69 ;
}
static int T_1 F_28 ( void * V_71 , unsigned int V_72 )
{
int V_73 = F_22 ( V_74 , V_71 , V_72 ) ;
if ( V_73 != V_72 ) {
if ( V_75 == 0 )
F_9 ( V_64
L_28 ,
V_73 , V_72 ) ;
V_75 = 1 ;
return - 1 ;
}
return V_72 ;
}
static void T_1 error ( char * V_76 )
{
F_9 ( V_64 L_29 , V_76 ) ;
V_77 = 1 ;
V_75 = 1 ;
}
static int T_1 F_18 ( int V_46 , int V_47 , T_2 V_78 )
{
int V_79 ;
V_70 = V_46 ;
V_74 = V_47 ;
V_79 = V_78 ( NULL , 0 , F_27 , F_28 , NULL , NULL , error ) ;
if ( V_75 )
V_79 = 1 ;
return V_79 ;
}
