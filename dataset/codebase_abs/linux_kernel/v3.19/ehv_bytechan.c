static void F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 ) {
F_2 ( V_2 -> V_4 ) ;
V_2 -> V_3 = 1 ;
}
}
static void F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 ) {
F_4 ( V_2 -> V_4 ) ;
V_2 -> V_3 = 0 ;
}
}
static int F_5 ( void )
{
struct V_5 * V_6 = V_7 ;
const char * V_8 = NULL ;
const T_1 * V_9 ;
if ( ! V_6 || ! F_6 ( V_6 , L_1 ) )
return 0 ;
V_10 = F_7 ( V_6 , 0 ) ;
if ( V_10 == V_11 ) {
F_8 ( L_2 , V_6 -> V_12 ) ;
return 0 ;
}
V_9 = F_9 ( V_6 , L_3 , NULL ) ;
if ( ! V_9 ) {
F_8 ( L_4 ,
V_6 -> V_13 ) ;
return 0 ;
}
V_14 = F_10 ( * V_9 ) ;
return 1 ;
}
static void F_11 ( const char V_15 )
{
int V_16 , V_17 ;
do {
V_17 = 1 ;
V_16 = F_12 ( V_18 ,
& V_17 , & V_15 ) ;
} while ( V_16 == V_19 );
}
static void F_13 ( char V_20 )
{
if ( V_20 == '\n' )
F_11 ( '\r' ) ;
F_11 ( V_20 ) ;
}
void T_2 F_14 ( void )
{
unsigned int V_21 , V_22 ;
unsigned int V_16 ;
V_16 = F_15 ( V_18 ,
& V_21 , & V_22 ) ;
if ( V_16 )
return;
V_23 = F_13 ;
F_16 () ;
F_17 ( L_5 ,
V_18 ) ;
}
static int F_18 ( unsigned int V_24 , const char * V_25 ,
unsigned int V_17 )
{
unsigned int V_26 ;
int V_16 = 0 ;
while ( V_17 ) {
V_26 = F_19 (unsigned int, count, EV_BYTE_CHANNEL_MAX_BYTES) ;
do {
V_16 = F_12 ( V_24 , & V_26 , V_25 ) ;
} while ( V_16 == V_19 );
V_17 -= V_26 ;
V_25 += V_26 ;
}
return V_16 ;
}
static void F_20 ( struct V_27 * V_28 , const char * V_25 ,
unsigned int V_17 )
{
char V_29 [ V_30 ] ;
unsigned int V_31 , V_32 = 0 ;
char V_20 ;
for ( V_31 = 0 ; V_31 < V_17 ; V_31 ++ ) {
V_20 = * V_25 ++ ;
if ( V_20 == '\n' )
V_29 [ V_32 ++ ] = '\r' ;
V_29 [ V_32 ++ ] = V_20 ;
if ( V_32 >= ( V_30 - 1 ) ) {
if ( F_18 ( V_14 , V_29 , V_32 ) )
return;
V_32 = 0 ;
}
}
if ( V_32 )
F_18 ( V_14 , V_29 , V_32 ) ;
}
static struct V_33 * F_21 ( struct V_27 * V_28 , int * V_34 )
{
* V_34 = V_28 -> V_34 ;
return V_35 ;
}
static int T_2 F_22 ( void )
{
if ( ! F_5 () ) {
F_23 ( L_6 ) ;
return - V_36 ;
}
#ifdef F_24
if ( V_14 != V_18 )
F_25 ( L_7 ,
V_18 ) ;
#endif
F_26 ( V_37 . V_13 , V_37 . V_34 , NULL ) ;
F_27 ( & V_37 ) ;
F_28 ( L_8 ,
V_14 ) ;
return 0 ;
}
static T_3 F_29 ( int V_38 , void * V_15 )
{
struct V_1 * V_2 = V_15 ;
unsigned int V_21 , V_22 , V_26 ;
int V_17 ;
char V_39 [ V_30 ] ;
int V_16 ;
F_15 ( V_2 -> V_24 , & V_21 , & V_22 ) ;
V_17 = F_30 ( & V_2 -> V_40 , V_21 ) ;
while ( V_17 > 0 ) {
V_26 = F_19 (unsigned int, count, sizeof(buffer)) ;
F_31 ( V_2 -> V_24 , & V_26 , V_39 ) ;
V_16 = F_32 ( & V_2 -> V_40 , V_39 , V_26 ) ;
if ( V_16 != V_26 )
break;
V_17 -= V_26 ;
}
F_33 ( & V_2 -> V_40 ) ;
return V_41 ;
}
static void F_34 ( struct V_1 * V_2 )
{
unsigned int V_17 ;
unsigned int V_26 , V_16 ;
unsigned long V_42 ;
do {
F_35 ( & V_2 -> V_43 , V_42 ) ;
V_26 = F_19 (unsigned int,
CIRC_CNT_TO_END(bc->head, bc->tail, BUF_SIZE),
EV_BYTE_CHANNEL_MAX_BYTES) ;
V_16 = F_12 ( V_2 -> V_24 , & V_26 , V_2 -> V_44 + V_2 -> V_45 ) ;
if ( ! V_16 || ( V_16 == V_19 ) )
V_2 -> V_45 = ( V_2 -> V_45 + V_26 ) & ( V_46 - 1 ) ;
V_17 = F_36 ( V_2 -> V_47 , V_2 -> V_45 , V_46 ) ;
F_37 ( & V_2 -> V_43 , V_42 ) ;
} while ( V_17 && ! V_16 );
F_35 ( & V_2 -> V_43 , V_42 ) ;
if ( F_36 ( V_2 -> V_47 , V_2 -> V_45 , V_46 ) )
F_1 ( V_2 ) ;
else
F_3 ( V_2 ) ;
F_37 ( & V_2 -> V_43 , V_42 ) ;
}
static T_3 F_38 ( int V_38 , void * V_15 )
{
struct V_1 * V_2 = V_15 ;
F_34 ( V_2 ) ;
F_39 ( & V_2 -> V_40 ) ;
return V_41 ;
}
static int F_40 ( struct V_48 * V_49 , const unsigned char * V_25 ,
int V_17 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
unsigned long V_42 ;
unsigned int V_26 ;
unsigned int V_51 = 0 ;
while ( 1 ) {
F_35 ( & V_2 -> V_43 , V_42 ) ;
V_26 = F_41 ( V_2 -> V_47 , V_2 -> V_45 , V_46 ) ;
if ( V_17 < V_26 )
V_26 = V_17 ;
if ( V_26 ) {
memcpy ( V_2 -> V_44 + V_2 -> V_47 , V_25 , V_26 ) ;
V_2 -> V_47 = ( V_2 -> V_47 + V_26 ) & ( V_46 - 1 ) ;
}
F_37 ( & V_2 -> V_43 , V_42 ) ;
if ( ! V_26 )
break;
V_25 += V_26 ;
V_17 -= V_26 ;
V_51 += V_26 ;
}
F_34 ( V_2 ) ;
return V_51 ;
}
static int F_42 ( struct V_48 * V_49 , struct V_52 * V_53 )
{
struct V_1 * V_2 = & V_54 [ V_49 -> V_34 ] ;
if ( ! V_2 -> V_55 )
return - V_36 ;
return F_43 ( & V_2 -> V_40 , V_49 , V_53 ) ;
}
static void F_44 ( struct V_48 * V_49 , struct V_52 * V_53 )
{
struct V_1 * V_2 = & V_54 [ V_49 -> V_34 ] ;
if ( V_2 -> V_55 )
F_45 ( & V_2 -> V_40 , V_49 , V_53 ) ;
}
static int F_46 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
unsigned long V_42 ;
int V_17 ;
F_35 ( & V_2 -> V_43 , V_42 ) ;
V_17 = F_47 ( V_2 -> V_47 , V_2 -> V_45 , V_46 ) ;
F_37 ( & V_2 -> V_43 , V_42 ) ;
return V_17 ;
}
static void F_48 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
F_49 ( V_2 -> V_56 ) ;
}
static void F_50 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
F_2 ( V_2 -> V_56 ) ;
}
static void F_51 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
F_34 ( V_2 ) ;
F_52 ( & V_2 -> V_40 ) ;
}
static int F_53 ( struct V_57 * V_40 ,
struct V_48 * V_49 )
{
struct V_1 * V_2 = F_54 ( V_40 , struct V_1 , V_40 ) ;
int V_16 ;
V_49 -> V_50 = V_2 ;
V_16 = F_55 ( V_2 -> V_56 , F_29 , 0 , L_9 , V_2 ) ;
if ( V_16 < 0 ) {
F_56 ( V_2 -> V_55 , L_10 ,
V_2 -> V_56 , V_16 ) ;
return V_16 ;
}
V_2 -> V_3 = 1 ;
V_16 = F_55 ( V_2 -> V_4 , F_38 , 0 , L_9 , V_2 ) ;
if ( V_16 < 0 ) {
F_56 ( V_2 -> V_55 , L_11 ,
V_2 -> V_4 , V_16 ) ;
F_57 ( V_2 -> V_56 , V_2 ) ;
return V_16 ;
}
F_3 ( V_2 ) ;
return 0 ;
}
static void F_58 ( struct V_57 * V_40 )
{
struct V_1 * V_2 = F_54 ( V_40 , struct V_1 , V_40 ) ;
F_57 ( V_2 -> V_4 , V_2 ) ;
F_57 ( V_2 -> V_56 , V_2 ) ;
}
static int F_59 ( struct V_58 * V_59 )
{
struct V_5 * V_6 = V_59 -> V_55 . V_60 ;
struct V_1 * V_2 ;
const T_1 * V_9 ;
unsigned int V_24 ;
int V_16 ;
static unsigned int V_34 = 1 ;
unsigned int V_31 ;
V_9 = F_9 ( V_6 , L_3 , NULL ) ;
if ( ! V_9 ) {
F_56 ( & V_59 -> V_55 , L_12 ,
V_6 -> V_13 ) ;
return - V_36 ;
}
V_24 = F_10 ( * V_9 ) ;
V_31 = ( V_24 == V_14 ) ? 0 : V_34 ++ ;
V_2 = & V_54 [ V_31 ] ;
V_2 -> V_24 = V_24 ;
V_2 -> V_47 = 0 ;
V_2 -> V_45 = 0 ;
F_60 ( & V_2 -> V_43 ) ;
V_2 -> V_56 = F_7 ( V_6 , 0 ) ;
V_2 -> V_4 = F_7 ( V_6 , 1 ) ;
if ( ( V_2 -> V_56 == V_11 ) || ( V_2 -> V_4 == V_11 ) ) {
F_56 ( & V_59 -> V_55 , L_13 ,
V_6 -> V_13 ) ;
V_16 = - V_36 ;
goto error;
}
F_61 ( & V_2 -> V_40 ) ;
V_2 -> V_40 . V_61 = & V_62 ;
V_2 -> V_55 = F_62 ( & V_2 -> V_40 , V_35 , V_31 ,
& V_59 -> V_55 ) ;
if ( F_63 ( V_2 -> V_55 ) ) {
V_16 = F_64 ( V_2 -> V_55 ) ;
F_56 ( & V_59 -> V_55 , L_14 , V_16 ) ;
goto error;
}
F_65 ( & V_59 -> V_55 , V_2 ) ;
F_66 ( & V_59 -> V_55 , L_15 ,
V_35 -> V_13 , V_31 , V_2 -> V_24 ) ;
return 0 ;
error:
F_67 ( & V_2 -> V_40 ) ;
F_68 ( V_2 -> V_4 ) ;
F_68 ( V_2 -> V_56 ) ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
return V_16 ;
}
static int F_69 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = F_70 ( & V_59 -> V_55 ) ;
F_71 ( V_35 , V_2 - V_54 ) ;
F_67 ( & V_2 -> V_40 ) ;
F_68 ( V_2 -> V_4 ) ;
F_68 ( V_2 -> V_56 ) ;
return 0 ;
}
static int T_2 F_72 ( void )
{
struct V_5 * V_6 ;
unsigned int V_17 = 0 ;
int V_16 ;
F_28 ( L_16 ) ;
F_73 (np, NULL, L_1 )
V_17 ++ ;
if ( ! V_17 )
return - V_36 ;
V_54 = F_74 ( V_17 * sizeof( struct V_1 ) , V_63 ) ;
if ( ! V_54 )
return - V_64 ;
V_35 = F_75 ( V_17 ) ;
if ( ! V_35 ) {
V_16 = - V_64 ;
goto error;
}
V_35 -> V_65 = L_9 ;
V_35 -> V_13 = V_37 . V_13 ;
V_35 -> type = V_66 ;
V_35 -> V_67 = V_68 ;
V_35 -> V_69 = V_70 ;
V_35 -> V_42 = V_71 | V_72 ;
F_76 ( V_35 , & V_73 ) ;
V_16 = F_77 ( V_35 ) ;
if ( V_16 ) {
F_8 ( L_17 , V_16 ) ;
goto error;
}
V_16 = F_78 ( & V_74 ) ;
if ( V_16 ) {
F_8 ( L_18 ,
V_16 ) ;
goto error;
}
return 0 ;
error:
if ( V_35 ) {
F_79 ( V_35 ) ;
F_80 ( V_35 ) ;
}
F_81 ( V_54 ) ;
return V_16 ;
}
static void T_4 F_82 ( void )
{
F_83 ( & V_74 ) ;
F_79 ( V_35 ) ;
F_80 ( V_35 ) ;
F_81 ( V_54 ) ;
}
