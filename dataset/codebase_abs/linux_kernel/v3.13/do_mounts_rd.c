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
int V_16 = - 1 ;
unsigned char * V_17 ;
const char * V_18 ;
unsigned long V_19 ;
V_17 = F_5 ( V_7 , V_20 ) ;
if ( ! V_17 )
return - V_21 ;
V_9 = (struct V_8 * ) V_17 ;
V_11 = (struct V_10 * ) V_17 ;
V_13 = (struct V_12 * ) V_17 ;
V_15 = (struct V_14 * ) V_17 ;
memset ( V_17 , 0xe5 , V_7 ) ;
F_6 ( V_4 , V_5 * V_22 , 0 ) ;
F_7 ( V_4 , V_17 , V_7 ) ;
* V_6 = F_8 ( V_17 , V_7 , & V_18 ) ;
if ( V_18 ) {
F_9 ( V_23 L_1 ,
V_18 , V_5 ) ;
if ( ! * V_6 )
F_9 ( V_24
L_2 ,
V_18 ) ;
V_16 = 0 ;
goto V_25;
}
if ( V_11 -> V_26 == V_27 &&
V_11 -> V_28 == V_29 ) {
F_9 ( V_23
L_3 ,
V_5 ) ;
V_16 = ( F_10 ( V_11 -> V_7 ) + V_22 - 1 ) >> V_30 ;
goto V_25;
}
if ( V_13 -> V_31 == V_32 ) {
F_9 ( V_23
L_4 ,
V_5 ) ;
V_16 = ( V_13 -> V_7 + V_22 - 1 ) >> V_30 ;
goto V_25;
}
if ( F_11 ( V_15 -> V_33 ) == V_34 ) {
F_9 ( V_23
L_5 ,
V_5 ) ;
V_16 = ( F_12 ( V_15 -> V_35 ) + V_22 - 1 )
>> V_30 ;
goto V_25;
}
F_6 ( V_4 , V_5 * V_22 + 0x200 , 0 ) ;
F_7 ( V_4 , V_17 , V_7 ) ;
if ( V_13 -> V_31 == V_32 ) {
F_9 ( V_23
L_4 ,
V_5 ) ;
V_16 = ( V_13 -> V_7 + V_22 - 1 ) >> V_30 ;
goto V_25;
}
F_6 ( V_4 , ( V_5 + 1 ) * V_22 , 0 ) ;
F_7 ( V_4 , V_17 , V_7 ) ;
if ( V_9 -> V_33 == V_36 ||
V_9 -> V_33 == V_37 ) {
F_9 ( V_23
L_6 ,
V_5 ) ;
V_16 = V_9 -> V_38 << V_9 -> V_39 ;
goto V_25;
}
V_19 = F_13 ( V_17 ) ;
if ( V_19 ) {
F_9 ( V_23
L_7 ,
V_5 ) ;
V_16 = V_19 ;
goto V_25;
}
F_9 ( V_23
L_8 ,
V_5 ) ;
V_25:
F_6 ( V_4 , V_5 * V_22 , 0 ) ;
F_14 ( V_17 ) ;
return V_16 ;
}
int T_1 F_15 ( char * V_40 )
{
int V_41 = 0 ;
int V_42 , V_43 ;
unsigned long V_44 , V_45 ;
int V_16 , V_46 , V_47 ;
char * V_17 = NULL ;
unsigned short V_48 = 0 ;
T_2 V_6 = NULL ;
#if ! F_16 ( V_49 )
char V_50 [ 4 ] = { '|' , '/' , '-' , '\\' } ;
#endif
V_43 = F_17 ( L_9 , V_51 , 0 ) ;
if ( V_43 < 0 )
goto V_52;
V_42 = F_17 ( V_40 , V_53 , 0 ) ;
if ( V_42 < 0 )
goto V_54;
V_16 = F_4 ( V_42 , V_3 , & V_6 ) ;
if ( V_16 < 0 )
goto V_25;
if ( V_16 == 0 ) {
if ( F_18 ( V_42 , V_43 , V_6 ) == 0 )
goto V_55;
goto V_25;
}
if ( F_19 ( V_43 , V_56 , ( unsigned long ) & V_44 ) < 0 )
V_44 = 0 ;
else
V_44 >>= 1 ;
if ( V_16 > V_44 ) {
F_9 ( L_10 ,
V_16 , V_44 ) ;
goto V_25;
}
if ( F_19 ( V_42 , V_56 , ( unsigned long ) & V_45 ) < 0 )
V_45 = 0 ;
else
V_45 >>= 1 ;
if ( strcmp ( V_40 , L_11 ) == 0 )
V_45 = V_16 ;
if ( V_45 == 0 ) {
F_9 ( V_57 L_12 ) ;
goto V_25;
}
V_17 = F_5 ( V_22 , V_20 ) ;
if ( ! V_17 ) {
F_9 ( V_57 L_13 ) ;
goto V_25;
}
F_9 ( V_23 L_14 ,
V_16 , ( ( V_16 - 1 ) / V_45 ) + 1 , V_16 > V_45 ? L_15 : L_16 ) ;
for ( V_46 = 0 , V_47 = 1 ; V_46 < V_16 ; V_46 ++ ) {
if ( V_46 && ( V_46 % V_45 == 0 ) ) {
F_9 ( L_17 , V_47 ++ ) ;
V_48 = 0 ;
if ( F_20 ( V_42 ) ) {
F_9 ( L_18 ) ;
goto V_54;
}
F_21 ( L_19 , V_47 ) ;
V_42 = F_17 ( V_40 , V_53 , 0 ) ;
if ( V_42 < 0 ) {
F_9 ( L_20 ) ;
goto V_54;
}
F_9 ( L_21 , V_47 ) ;
}
F_7 ( V_42 , V_17 , V_22 ) ;
F_22 ( V_43 , V_17 , V_22 ) ;
#if ! F_16 ( V_49 )
if ( ! ( V_46 % 16 ) ) {
F_9 ( L_22 , V_50 [ V_48 & 0x3 ] ) ;
V_48 ++ ;
}
#endif
}
F_9 ( L_23 ) ;
V_55:
V_41 = 1 ;
V_25:
F_20 ( V_42 ) ;
V_54:
F_20 ( V_43 ) ;
V_52:
F_14 ( V_17 ) ;
F_23 ( L_9 ) ;
return V_41 ;
}
int T_1 F_24 ( int V_19 )
{
if ( V_2 )
F_21 ( L_24 ) ;
F_25 ( L_25 , V_58 ) ;
F_25 ( L_9 , F_26 ( V_59 , V_19 ) ) ;
return F_15 ( L_25 ) ;
}
static int T_1 F_27 ( void * V_17 , unsigned int V_60 )
{
int V_61 = F_7 ( V_62 , V_17 , V_60 ) ;
if ( V_61 < 0 )
F_9 ( V_57 L_26 ) ;
else if ( V_61 == 0 )
F_9 ( V_57 L_27 ) ;
return V_61 ;
}
static int T_1 F_28 ( void * V_63 , unsigned int V_64 )
{
int V_65 = F_22 ( V_66 , V_63 , V_64 ) ;
if ( V_65 != V_64 ) {
if ( V_67 == 0 )
F_9 ( V_57
L_28 ,
V_65 , V_64 ) ;
V_67 = 1 ;
return - 1 ;
}
return V_64 ;
}
static void T_1 error ( char * V_68 )
{
F_9 ( V_57 L_29 , V_68 ) ;
V_69 = 1 ;
V_67 = 1 ;
}
static int T_1 F_18 ( int V_42 , int V_43 , T_2 V_70 )
{
int V_71 ;
V_62 = V_42 ;
V_66 = V_43 ;
if ( ! V_70 ) {
F_29 ( L_30
L_31 ) ;
F_30 ( L_32 ) ;
}
V_71 = V_70 ( NULL , 0 , F_27 , F_28 , NULL , NULL , error ) ;
if ( V_67 )
V_71 = 1 ;
return V_71 ;
}
