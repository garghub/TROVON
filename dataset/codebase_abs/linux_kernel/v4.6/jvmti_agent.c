static inline T_1 F_1 ( void )
{
return ( T_1 ) F_2 ( V_1 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
T_2 V_4 ;
char V_5 [ 16 ] ;
int V_6 , V_7 = - 1 ;
int V_8 = - 1 ;
struct {
T_3 V_9 ;
T_3 V_10 ;
} V_11 ;
V_6 = F_4 ( L_1 , V_12 ) ;
if ( V_6 == - 1 )
return - 1 ;
V_4 = F_5 ( V_6 , V_5 , sizeof( V_5 ) ) ;
if ( V_4 != sizeof( V_5 ) )
goto error;
if ( V_5 [ 0 ] != 0x7f || V_5 [ 1 ] != 'E' || V_5 [ 2 ] != 'L' || V_5 [ 3 ] != 'F' )
goto error;
V_4 = F_5 ( V_6 , & V_11 , sizeof( V_11 ) ) ;
if ( V_4 != sizeof( V_11 ) )
goto error;
V_8 = V_11 . V_10 ;
if ( V_8 < 0 )
V_8 = 0 ;
V_3 -> V_13 = V_8 ;
V_7 = 0 ;
error:
F_6 ( V_6 ) ;
return V_7 ;
}
static inline T_4
F_7 ( const struct V_14 * V_15 )
{
return ( ( T_4 ) V_15 -> V_16 * V_17 ) + V_15 -> V_18 ;
}
static inline T_4
F_8 ( void )
{
struct V_14 V_15 ;
int V_7 ;
V_7 = F_9 ( V_19 , & V_15 ) ;
if ( V_7 )
return 0 ;
return F_7 ( & V_15 ) ;
}
static int
F_10 ( void )
{
char V_20 [ 32 ] ;
char * V_21 , * V_22 ;
struct V_23 V_23 ;
T_5 V_24 ;
int V_7 ;
time ( & V_24 ) ;
localtime_r ( & V_24 , & V_23 ) ;
V_21 = getenv ( L_2 ) ;
if ( ! V_21 )
V_21 = getenv ( L_3 ) ;
if ( ! V_21 )
V_21 = L_4 ;
strftime ( V_20 , sizeof( V_20 ) , V_25 L_5 , & V_23 ) ;
snprintf ( V_26 , V_27 - 1 , L_6 , V_21 ) ;
V_7 = F_11 ( V_26 , 0755 ) ;
if ( V_7 == - 1 ) {
if ( V_28 != V_29 ) {
F_12 ( L_7 , V_26 ) ;
return - 1 ;
}
}
snprintf ( V_26 , V_27 - 1 , L_8 , V_21 ) ;
V_7 = F_11 ( V_26 , 0755 ) ;
if ( V_7 == - 1 ) {
if ( V_28 != V_29 ) {
F_12 ( L_9 , V_26 ) ;
return - 1 ;
}
}
snprintf ( V_26 , V_27 - 1 , L_10 , V_21 , V_20 ) ;
V_22 = F_13 ( V_26 ) ;
if ( V_22 != V_26 ) {
F_12 ( L_9 , V_26 ) ;
return - 1 ;
}
return 0 ;
}
static int
F_14 ( int V_6 )
{
long V_30 ;
V_30 = F_15 ( V_31 ) ;
if ( V_30 == - 1 )
return - 1 ;
V_32 = F_16 ( NULL , V_30 , V_33 | V_34 , V_35 , V_6 , 0 ) ;
return ( V_32 == V_36 ) ? - 1 : 0 ;
}
static void
F_17 ( void )
{
long V_30 ;
if ( ! V_32 )
return;
V_30 = F_15 ( V_31 ) ;
if ( V_30 == - 1 )
return;
F_18 ( V_32 , V_30 ) ;
}
void * F_19 ( void )
{
int V_37 ;
char V_38 [ V_27 ] ;
struct V_2 V_39 ;
int V_6 ;
T_6 * V_40 ;
if ( ! F_8 () )
F_20 ( L_11 , V_19 ) ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
F_10 () ;
snprintf ( V_38 , V_27 , L_12 , V_26 , F_21 () ) ;
V_6 = F_4 ( V_38 , V_41 | V_42 | V_43 , 0666 ) ;
if ( V_6 == - 1 )
return NULL ;
if ( F_14 ( V_6 ) ) {
F_20 ( L_13 ) ;
return NULL ;
}
V_40 = fdopen ( V_6 , L_14 ) ;
if ( ! V_40 ) {
F_12 ( L_15 , V_38 ) ;
F_6 ( V_6 ) ;
goto error;
}
F_20 ( L_16 , V_38 ) ;
if ( F_3 ( & V_39 ) ) {
F_12 ( L_17 ) ;
goto error;
}
V_39 . V_44 = V_45 ;
V_39 . V_46 = V_47 ;
V_39 . V_48 = sizeof( V_39 ) ;
V_39 . V_49 = F_21 () ;
V_37 = F_22 ( V_39 . V_48 ) ;
V_39 . V_48 += V_37 ;
V_39 . V_50 = F_8 () ;
if ( ! fwrite ( & V_39 , sizeof( V_39 ) , 1 , V_40 ) ) {
F_12 ( L_18 ) ;
goto error;
}
if ( V_37 && ! fwrite ( V_51 , V_37 , 1 , V_40 ) ) {
F_12 ( L_19 ) ;
goto error;
}
return V_40 ;
error:
fclose ( V_40 ) ;
return NULL ;
}
int
F_23 ( void * V_52 )
{
struct V_53 V_54 ;
T_6 * V_40 = V_52 ;
if ( ! V_40 ) {
F_20 ( L_20 ) ;
return - 1 ;
}
V_54 . V_22 . V_5 = V_55 ;
V_54 . V_22 . V_48 = sizeof( V_54 ) ;
V_54 . V_22 . V_50 = F_8 () ;
if ( ! fwrite ( & V_54 , sizeof( V_54 ) , 1 , V_40 ) )
return - 1 ;
fclose ( V_40 ) ;
V_40 = NULL ;
F_17 () ;
return 0 ;
}
int
F_24 ( void * V_52 , char const * V_56 ,
T_4 V_57 , void const * V_58 , unsigned int const V_59 )
{
static int V_60 = 1 ;
struct V_61 V_54 ;
T_7 V_62 ;
T_7 V_63 ;
T_6 * V_40 = V_52 ;
int V_7 = - 1 ;
if ( V_59 == 0 )
return 0 ;
if ( ! V_40 ) {
F_20 ( L_21 ) ;
return - 1 ;
}
V_62 = strlen ( V_56 ) + 1 ;
V_54 . V_22 . V_5 = V_64 ;
V_54 . V_22 . V_48 = sizeof( V_54 ) + V_62 ;
V_63 = F_22 ( V_54 . V_22 . V_48 ) ;
V_54 . V_22 . V_48 += V_63 ;
V_54 . V_22 . V_50 = F_8 () ;
V_54 . V_65 = V_59 ;
V_54 . V_57 = V_57 ;
V_54 . V_66 = V_57 ;
V_54 . V_49 = F_21 () ;
V_54 . V_67 = F_1 () ;
if ( V_58 )
V_54 . V_22 . V_48 += V_59 ;
F_25 ( V_40 ) ;
V_54 . V_68 = V_60 ++ ;
V_7 = F_26 ( & V_54 , sizeof( V_54 ) , 1 , V_40 ) ;
F_26 ( V_56 , V_62 , 1 , V_40 ) ;
if ( V_63 )
F_26 ( V_51 , V_63 , 1 , V_40 ) ;
if ( V_58 )
F_26 ( V_58 , V_59 , 1 , V_40 ) ;
F_27 ( V_40 ) ;
V_7 = 0 ;
return V_7 ;
}
int
F_28 ( void * V_52 , T_4 V_58 , const char * V_69 ,
T_8 * V_70 , int V_71 )
{
struct V_72 V_54 ;
T_7 V_4 , V_73 , V_59 , V_74 ;
T_7 V_63 ;
T_4 V_75 ;
const char * V_76 = V_69 ;
T_6 * V_40 = V_52 ;
int V_77 ;
if ( ! V_71 )
return 0 ;
if ( ! V_40 ) {
F_20 ( L_22 ) ;
return - 1 ;
}
V_74 = strlen ( V_69 ) + 1 ;
V_54 . V_22 . V_5 = V_78 ;
V_59 = sizeof( V_54 ) ;
V_54 . V_22 . V_50 = F_8 () ;
V_54 . V_66 = ( T_4 ) ( V_79 ) V_58 ;
V_54 . V_80 = V_71 ;
V_59 += V_71 * sizeof( struct V_81 ) ;
V_59 += V_74 * V_71 ;
V_63 = F_22 ( V_59 ) ;
V_54 . V_22 . V_48 = V_59 + V_63 ;
F_25 ( V_40 ) ;
V_4 = F_26 ( & V_54 , sizeof( V_54 ) , 1 , V_40 ) ;
if ( V_4 != 1 )
goto error;
for ( V_77 = 0 ; V_77 < V_71 ; V_77 ++ ) {
V_75 = ( T_4 ) V_70 [ V_77 ] . V_82 ;
V_73 = sizeof( V_75 ) ;
V_4 = F_26 ( & V_75 , V_73 , 1 , V_40 ) ;
if ( V_4 != 1 )
goto error;
V_73 = sizeof( V_70 [ 0 ] . V_83 ) ;
V_4 = F_26 ( & V_70 [ V_77 ] . V_83 , V_73 , 1 , V_40 ) ;
if ( V_4 != 1 )
goto error;
V_73 = sizeof( V_70 [ 0 ] . V_84 ) ;
V_4 = F_26 ( & V_70 [ V_77 ] . V_84 , V_73 , 1 , V_40 ) ;
if ( V_4 != 1 )
goto error;
V_4 = F_26 ( V_76 , V_74 , 1 , V_40 ) ;
if ( V_4 != 1 )
goto error;
}
if ( V_63 )
V_4 = F_26 ( V_51 , V_63 , 1 , V_40 ) ;
if ( V_4 != 1 )
goto error;
F_27 ( V_40 ) ;
return 0 ;
error:
F_27 ( V_40 ) ;
return - 1 ;
}
