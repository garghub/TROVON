static inline T_1 F_1 ( void )
{
return ( T_1 ) F_2 ( V_1 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
T_2 V_4 ;
char V_5 [ 16 ] ;
int V_6 , V_7 = - 1 ;
struct {
T_3 V_8 ;
T_3 V_9 ;
} V_10 ;
V_6 = F_4 ( L_1 , V_11 ) ;
if ( V_6 == - 1 )
return - 1 ;
V_4 = F_5 ( V_6 , V_5 , sizeof( V_5 ) ) ;
if ( V_4 != sizeof( V_5 ) )
goto error;
if ( V_5 [ 0 ] != 0x7f || V_5 [ 1 ] != 'E' || V_5 [ 2 ] != 'L' || V_5 [ 3 ] != 'F' )
goto error;
V_4 = F_5 ( V_6 , & V_10 , sizeof( V_10 ) ) ;
if ( V_4 != sizeof( V_10 ) )
goto error;
V_3 -> V_12 = V_10 . V_9 ;
V_7 = 0 ;
error:
F_6 ( V_6 ) ;
return V_7 ;
}
static inline T_4
F_7 ( void )
{
#if F_8 ( V_13 ) || F_8 ( V_14 )
unsigned int V_15 , V_16 ;
asm volatile("rdtsc" : "=a" (low), "=d" (high));
return V_15 | ( ( T_4 ) V_16 ) << 32 ;
#else
return 0 ;
#endif
}
static inline T_4
F_9 ( const struct V_17 * V_18 )
{
return ( ( T_4 ) V_18 -> V_19 * V_20 ) + V_18 -> V_21 ;
}
static inline T_4
F_10 ( void )
{
struct V_17 V_18 ;
int V_7 ;
if ( V_22 )
return F_7 () ;
V_7 = F_11 ( V_23 , & V_18 ) ;
if ( V_7 )
return 0 ;
return F_9 ( & V_18 ) ;
}
static int
F_12 ( void )
{
char V_24 [ 32 ] ;
char * V_25 , * V_26 ;
struct V_27 V_27 ;
T_5 V_28 ;
int V_7 ;
time ( & V_28 ) ;
localtime_r ( & V_28 , & V_27 ) ;
V_25 = getenv ( L_2 ) ;
if ( ! V_25 )
V_25 = getenv ( L_3 ) ;
if ( ! V_25 )
V_25 = L_4 ;
strftime ( V_24 , sizeof( V_24 ) , V_29 L_5 , & V_27 ) ;
snprintf ( V_30 , V_31 - 1 , L_6 , V_25 ) ;
V_7 = F_13 ( V_30 , 0755 ) ;
if ( V_7 == - 1 ) {
if ( V_32 != V_33 ) {
F_14 ( L_7 , V_30 ) ;
return - 1 ;
}
}
snprintf ( V_30 , V_31 - 1 , L_8 , V_25 ) ;
V_7 = F_13 ( V_30 , 0755 ) ;
if ( V_7 == - 1 ) {
if ( V_32 != V_33 ) {
F_14 ( L_9 , V_30 ) ;
return - 1 ;
}
}
snprintf ( V_30 , V_31 - 1 , L_10 , V_25 , V_24 ) ;
V_26 = F_15 ( V_30 ) ;
if ( V_26 != V_30 ) {
F_14 ( L_9 , V_30 ) ;
return - 1 ;
}
return 0 ;
}
static int
F_16 ( int V_6 )
{
long V_34 ;
V_34 = F_17 ( V_35 ) ;
if ( V_34 == - 1 )
return - 1 ;
V_36 = F_18 ( NULL , V_34 , V_37 | V_38 , V_39 , V_6 , 0 ) ;
return ( V_36 == V_40 ) ? - 1 : 0 ;
}
static void
F_19 ( void )
{
long V_34 ;
if ( ! V_36 )
return;
V_34 = F_17 ( V_35 ) ;
if ( V_34 == - 1 )
return;
F_20 ( V_36 , V_34 ) ;
}
static void
F_21 ( void )
{
char * V_24 = getenv ( L_11 ) ;
if ( ! V_24 || ! * V_24 || ! strcmp ( V_24 , L_12 ) )
return;
V_22 = 1 ;
}
void * F_22 ( void )
{
char V_41 [ V_31 ] ;
struct V_2 V_42 ;
int V_6 ;
T_6 * V_43 ;
F_21 () ;
if ( ! F_10 () ) {
if ( V_22 )
F_23 ( L_13 ) ;
else
F_23 ( L_14 , V_23 ) ;
}
memset ( & V_42 , 0 , sizeof( V_42 ) ) ;
F_12 () ;
snprintf ( V_41 , V_31 , L_15 , V_30 , F_24 () ) ;
V_6 = F_4 ( V_41 , V_44 | V_45 | V_46 , 0666 ) ;
if ( V_6 == - 1 )
return NULL ;
if ( F_16 ( V_6 ) ) {
F_23 ( L_16 ) ;
return NULL ;
}
V_43 = fdopen ( V_6 , L_17 ) ;
if ( ! V_43 ) {
F_14 ( L_18 , V_41 ) ;
F_6 ( V_6 ) ;
goto error;
}
F_23 ( L_19 , V_41 ) ;
if ( F_3 ( & V_42 ) ) {
F_14 ( L_20 ) ;
goto error;
}
V_42 . V_47 = V_48 ;
V_42 . V_49 = V_50 ;
V_42 . V_51 = sizeof( V_42 ) ;
V_42 . V_52 = F_24 () ;
V_42 . V_53 = F_10 () ;
if ( V_22 )
V_42 . V_54 |= V_55 ;
if ( ! fwrite ( & V_42 , sizeof( V_42 ) , 1 , V_43 ) ) {
F_14 ( L_21 ) ;
goto error;
}
return V_43 ;
error:
fclose ( V_43 ) ;
return NULL ;
}
int
F_25 ( void * V_56 )
{
struct V_57 V_58 ;
T_6 * V_43 = V_56 ;
if ( ! V_43 ) {
F_23 ( L_22 ) ;
return - 1 ;
}
V_58 . V_26 . V_5 = V_59 ;
V_58 . V_26 . V_51 = sizeof( V_58 ) ;
V_58 . V_26 . V_53 = F_10 () ;
if ( ! fwrite ( & V_58 , sizeof( V_58 ) , 1 , V_43 ) )
return - 1 ;
fclose ( V_43 ) ;
V_43 = NULL ;
F_19 () ;
return 0 ;
}
int
F_26 ( void * V_56 , char const * V_60 ,
T_4 V_61 , void const * V_62 , unsigned int const V_63 )
{
static int V_64 = 1 ;
struct V_65 V_58 ;
T_7 V_66 ;
T_6 * V_43 = V_56 ;
int V_7 = - 1 ;
if ( V_63 == 0 )
return 0 ;
if ( ! V_43 ) {
F_23 ( L_23 ) ;
return - 1 ;
}
V_66 = strlen ( V_60 ) + 1 ;
V_58 . V_26 . V_5 = V_67 ;
V_58 . V_26 . V_51 = sizeof( V_58 ) + V_66 ;
V_58 . V_26 . V_53 = F_10 () ;
V_58 . V_68 = V_63 ;
V_58 . V_61 = V_61 ;
V_58 . V_69 = V_61 ;
V_58 . V_52 = F_24 () ;
V_58 . V_70 = F_1 () ;
if ( V_62 )
V_58 . V_26 . V_51 += V_63 ;
F_27 ( V_43 ) ;
V_58 . V_71 = V_64 ++ ;
V_7 = F_28 ( & V_58 , sizeof( V_58 ) , 1 , V_43 ) ;
F_28 ( V_60 , V_66 , 1 , V_43 ) ;
if ( V_62 )
F_28 ( V_62 , V_63 , 1 , V_43 ) ;
F_29 ( V_43 ) ;
V_7 = 0 ;
return V_7 ;
}
int
F_30 ( void * V_56 , T_4 V_62 , const char * V_72 ,
T_8 * V_73 , int V_74 )
{
struct V_75 V_58 ;
T_7 V_4 , V_76 , V_63 , V_77 ;
T_4 V_78 ;
const char * V_79 = V_72 ;
T_6 * V_43 = V_56 ;
int V_80 ;
if ( ! V_74 )
return 0 ;
if ( ! V_43 ) {
F_23 ( L_24 ) ;
return - 1 ;
}
V_77 = strlen ( V_72 ) + 1 ;
V_58 . V_26 . V_5 = V_81 ;
V_63 = sizeof( V_58 ) ;
V_58 . V_26 . V_53 = F_10 () ;
V_58 . V_69 = ( T_4 ) ( V_82 ) V_62 ;
V_58 . V_83 = V_74 ;
V_63 += V_74 * sizeof( struct V_84 ) ;
V_63 += V_77 * V_74 ;
V_58 . V_26 . V_51 = V_63 ;
F_27 ( V_43 ) ;
V_4 = F_28 ( & V_58 , sizeof( V_58 ) , 1 , V_43 ) ;
if ( V_4 != 1 )
goto error;
for ( V_80 = 0 ; V_80 < V_74 ; V_80 ++ ) {
V_78 = ( T_4 ) V_73 [ V_80 ] . V_85 ;
V_76 = sizeof( V_78 ) ;
V_4 = F_28 ( & V_78 , V_76 , 1 , V_43 ) ;
if ( V_4 != 1 )
goto error;
V_76 = sizeof( V_73 [ 0 ] . V_86 ) ;
V_4 = F_28 ( & V_73 [ V_80 ] . V_86 , V_76 , 1 , V_43 ) ;
if ( V_4 != 1 )
goto error;
V_76 = sizeof( V_73 [ 0 ] . V_87 ) ;
V_4 = F_28 ( & V_73 [ V_80 ] . V_87 , V_76 , 1 , V_43 ) ;
if ( V_4 != 1 )
goto error;
V_4 = F_28 ( V_79 , V_77 , 1 , V_43 ) ;
if ( V_4 != 1 )
goto error;
}
F_29 ( V_43 ) ;
return 0 ;
error:
F_29 ( V_43 ) ;
return - 1 ;
}
