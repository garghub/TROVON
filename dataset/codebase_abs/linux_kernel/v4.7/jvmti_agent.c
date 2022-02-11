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
F_7 ( void )
{
#if F_8 ( V_14 ) || F_8 ( V_15 )
unsigned int V_16 , V_17 ;
asm volatile("rdtsc" : "=a" (low), "=d" (high));
return V_16 | ( ( T_4 ) V_17 ) << 32 ;
#else
return 0 ;
#endif
}
static inline T_4
F_9 ( const struct V_18 * V_19 )
{
return ( ( T_4 ) V_19 -> V_20 * V_21 ) + V_19 -> V_22 ;
}
static inline T_4
F_10 ( void )
{
struct V_18 V_19 ;
int V_7 ;
if ( V_23 )
return F_7 () ;
V_7 = F_11 ( V_24 , & V_19 ) ;
if ( V_7 )
return 0 ;
return F_9 ( & V_19 ) ;
}
static int
F_12 ( void )
{
char V_25 [ 32 ] ;
char * V_26 , * V_27 ;
struct V_28 V_28 ;
T_5 V_29 ;
int V_7 ;
time ( & V_29 ) ;
localtime_r ( & V_29 , & V_28 ) ;
V_26 = getenv ( L_2 ) ;
if ( ! V_26 )
V_26 = getenv ( L_3 ) ;
if ( ! V_26 )
V_26 = L_4 ;
strftime ( V_25 , sizeof( V_25 ) , V_30 L_5 , & V_28 ) ;
snprintf ( V_31 , V_32 - 1 , L_6 , V_26 ) ;
V_7 = F_13 ( V_31 , 0755 ) ;
if ( V_7 == - 1 ) {
if ( V_33 != V_34 ) {
F_14 ( L_7 , V_31 ) ;
return - 1 ;
}
}
snprintf ( V_31 , V_32 - 1 , L_8 , V_26 ) ;
V_7 = F_13 ( V_31 , 0755 ) ;
if ( V_7 == - 1 ) {
if ( V_33 != V_34 ) {
F_14 ( L_9 , V_31 ) ;
return - 1 ;
}
}
snprintf ( V_31 , V_32 - 1 , L_10 , V_26 , V_25 ) ;
V_27 = F_15 ( V_31 ) ;
if ( V_27 != V_31 ) {
F_14 ( L_9 , V_31 ) ;
return - 1 ;
}
return 0 ;
}
static int
F_16 ( int V_6 )
{
long V_35 ;
V_35 = F_17 ( V_36 ) ;
if ( V_35 == - 1 )
return - 1 ;
V_37 = F_18 ( NULL , V_35 , V_38 | V_39 , V_40 , V_6 , 0 ) ;
return ( V_37 == V_41 ) ? - 1 : 0 ;
}
static void
F_19 ( void )
{
long V_35 ;
if ( ! V_37 )
return;
V_35 = F_17 ( V_36 ) ;
if ( V_35 == - 1 )
return;
F_20 ( V_37 , V_35 ) ;
}
static void
F_21 ( void )
{
char * V_25 = getenv ( L_11 ) ;
if ( ! V_25 || ! * V_25 || ! strcmp ( V_25 , L_12 ) )
return;
V_23 = 1 ;
}
void * F_22 ( void )
{
int V_42 ;
char V_43 [ V_32 ] ;
struct V_2 V_44 ;
int V_6 ;
T_6 * V_45 ;
F_21 () ;
if ( ! F_10 () ) {
if ( V_23 )
F_23 ( L_13 ) ;
else
F_23 ( L_14 , V_24 ) ;
}
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
F_12 () ;
snprintf ( V_43 , V_32 , L_15 , V_31 , F_24 () ) ;
V_6 = F_4 ( V_43 , V_46 | V_47 | V_48 , 0666 ) ;
if ( V_6 == - 1 )
return NULL ;
if ( F_16 ( V_6 ) ) {
F_23 ( L_16 ) ;
return NULL ;
}
V_45 = fdopen ( V_6 , L_17 ) ;
if ( ! V_45 ) {
F_14 ( L_18 , V_43 ) ;
F_6 ( V_6 ) ;
goto error;
}
F_23 ( L_19 , V_43 ) ;
if ( F_3 ( & V_44 ) ) {
F_14 ( L_20 ) ;
goto error;
}
V_44 . V_49 = V_50 ;
V_44 . V_51 = V_52 ;
V_44 . V_53 = sizeof( V_44 ) ;
V_44 . V_54 = F_24 () ;
V_42 = F_25 ( V_44 . V_53 ) ;
V_44 . V_53 += V_42 ;
V_44 . V_55 = F_10 () ;
if ( V_23 )
V_44 . V_56 |= V_57 ;
if ( ! fwrite ( & V_44 , sizeof( V_44 ) , 1 , V_45 ) ) {
F_14 ( L_21 ) ;
goto error;
}
if ( V_42 && ! fwrite ( V_58 , V_42 , 1 , V_45 ) ) {
F_14 ( L_22 ) ;
goto error;
}
return V_45 ;
error:
fclose ( V_45 ) ;
return NULL ;
}
int
F_26 ( void * V_59 )
{
struct V_60 V_61 ;
T_6 * V_45 = V_59 ;
if ( ! V_45 ) {
F_23 ( L_23 ) ;
return - 1 ;
}
V_61 . V_27 . V_5 = V_62 ;
V_61 . V_27 . V_53 = sizeof( V_61 ) ;
V_61 . V_27 . V_55 = F_10 () ;
if ( ! fwrite ( & V_61 , sizeof( V_61 ) , 1 , V_45 ) )
return - 1 ;
fclose ( V_45 ) ;
V_45 = NULL ;
F_19 () ;
return 0 ;
}
int
F_27 ( void * V_59 , char const * V_63 ,
T_4 V_64 , void const * V_65 , unsigned int const V_66 )
{
static int V_67 = 1 ;
struct V_68 V_61 ;
T_7 V_69 ;
T_7 V_70 ;
T_6 * V_45 = V_59 ;
int V_7 = - 1 ;
if ( V_66 == 0 )
return 0 ;
if ( ! V_45 ) {
F_23 ( L_24 ) ;
return - 1 ;
}
V_69 = strlen ( V_63 ) + 1 ;
V_61 . V_27 . V_5 = V_71 ;
V_61 . V_27 . V_53 = sizeof( V_61 ) + V_69 ;
V_70 = F_25 ( V_61 . V_27 . V_53 ) ;
V_61 . V_27 . V_53 += V_70 ;
V_61 . V_27 . V_55 = F_10 () ;
V_61 . V_72 = V_66 ;
V_61 . V_64 = V_64 ;
V_61 . V_73 = V_64 ;
V_61 . V_54 = F_24 () ;
V_61 . V_74 = F_1 () ;
if ( V_65 )
V_61 . V_27 . V_53 += V_66 ;
F_28 ( V_45 ) ;
V_61 . V_75 = V_67 ++ ;
V_7 = F_29 ( & V_61 , sizeof( V_61 ) , 1 , V_45 ) ;
F_29 ( V_63 , V_69 , 1 , V_45 ) ;
if ( V_70 )
F_29 ( V_58 , V_70 , 1 , V_45 ) ;
if ( V_65 )
F_29 ( V_65 , V_66 , 1 , V_45 ) ;
F_30 ( V_45 ) ;
V_7 = 0 ;
return V_7 ;
}
int
F_31 ( void * V_59 , T_4 V_65 , const char * V_76 ,
T_8 * V_77 , int V_78 )
{
struct V_79 V_61 ;
T_7 V_4 , V_80 , V_66 , V_81 ;
T_7 V_70 ;
T_4 V_82 ;
const char * V_83 = V_76 ;
T_6 * V_45 = V_59 ;
int V_84 ;
if ( ! V_78 )
return 0 ;
if ( ! V_45 ) {
F_23 ( L_25 ) ;
return - 1 ;
}
V_81 = strlen ( V_76 ) + 1 ;
V_61 . V_27 . V_5 = V_85 ;
V_66 = sizeof( V_61 ) ;
V_61 . V_27 . V_55 = F_10 () ;
V_61 . V_73 = ( T_4 ) ( V_86 ) V_65 ;
V_61 . V_87 = V_78 ;
V_66 += V_78 * sizeof( struct V_88 ) ;
V_66 += V_81 * V_78 ;
V_70 = F_25 ( V_66 ) ;
V_61 . V_27 . V_53 = V_66 + V_70 ;
F_28 ( V_45 ) ;
V_4 = F_29 ( & V_61 , sizeof( V_61 ) , 1 , V_45 ) ;
if ( V_4 != 1 )
goto error;
for ( V_84 = 0 ; V_84 < V_78 ; V_84 ++ ) {
V_82 = ( T_4 ) V_77 [ V_84 ] . V_89 ;
V_80 = sizeof( V_82 ) ;
V_4 = F_29 ( & V_82 , V_80 , 1 , V_45 ) ;
if ( V_4 != 1 )
goto error;
V_80 = sizeof( V_77 [ 0 ] . V_90 ) ;
V_4 = F_29 ( & V_77 [ V_84 ] . V_90 , V_80 , 1 , V_45 ) ;
if ( V_4 != 1 )
goto error;
V_80 = sizeof( V_77 [ 0 ] . V_91 ) ;
V_4 = F_29 ( & V_77 [ V_84 ] . V_91 , V_80 , 1 , V_45 ) ;
if ( V_4 != 1 )
goto error;
V_4 = F_29 ( V_83 , V_81 , 1 , V_45 ) ;
if ( V_4 != 1 )
goto error;
}
if ( V_70 )
V_4 = F_29 ( V_58 , V_70 , 1 , V_45 ) ;
if ( V_4 != 1 )
goto error;
F_30 ( V_45 ) ;
return 0 ;
error:
F_30 ( V_45 ) ;
return - 1 ;
}
