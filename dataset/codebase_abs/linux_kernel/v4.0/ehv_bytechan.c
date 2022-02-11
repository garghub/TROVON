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
const T_1 * V_8 ;
if ( ! V_6 || ! F_6 ( V_6 , L_1 ) )
return 0 ;
V_9 = F_7 ( V_6 , 0 ) ;
if ( V_9 == V_10 ) {
F_8 ( L_2 , V_6 -> V_11 ) ;
return 0 ;
}
V_8 = F_9 ( V_6 , L_3 , NULL ) ;
if ( ! V_8 ) {
F_8 ( L_4 ,
V_6 -> V_12 ) ;
return 0 ;
}
V_13 = F_10 ( * V_8 ) ;
return 1 ;
}
static void F_11 ( const char V_14 )
{
int V_15 , V_16 ;
do {
V_16 = 1 ;
V_15 = F_12 ( V_17 ,
& V_16 , & V_14 ) ;
} while ( V_15 == V_18 );
}
static void F_13 ( char V_19 )
{
if ( V_19 == '\n' )
F_11 ( '\r' ) ;
F_11 ( V_19 ) ;
}
void T_2 F_14 ( void )
{
unsigned int V_20 , V_21 ;
unsigned int V_15 ;
V_15 = F_15 ( V_17 ,
& V_20 , & V_21 ) ;
if ( V_15 )
return;
V_22 = F_13 ;
F_16 () ;
F_17 ( L_5 ,
V_17 ) ;
}
static int F_18 ( unsigned int V_23 , const char * V_24 ,
unsigned int V_16 )
{
unsigned int V_25 ;
int V_15 = 0 ;
while ( V_16 ) {
V_25 = F_19 (unsigned int, count, EV_BYTE_CHANNEL_MAX_BYTES) ;
do {
V_15 = F_12 ( V_23 , & V_25 , V_24 ) ;
} while ( V_15 == V_18 );
V_16 -= V_25 ;
V_24 += V_25 ;
}
return V_15 ;
}
static void F_20 ( struct V_26 * V_27 , const char * V_24 ,
unsigned int V_16 )
{
char V_28 [ V_29 ] ;
unsigned int V_30 , V_31 = 0 ;
char V_19 ;
for ( V_30 = 0 ; V_30 < V_16 ; V_30 ++ ) {
V_19 = * V_24 ++ ;
if ( V_19 == '\n' )
V_28 [ V_31 ++ ] = '\r' ;
V_28 [ V_31 ++ ] = V_19 ;
if ( V_31 >= ( V_29 - 1 ) ) {
if ( F_18 ( V_13 , V_28 , V_31 ) )
return;
V_31 = 0 ;
}
}
if ( V_31 )
F_18 ( V_13 , V_28 , V_31 ) ;
}
static struct V_32 * F_21 ( struct V_26 * V_27 , int * V_33 )
{
* V_33 = V_27 -> V_33 ;
return V_34 ;
}
static int T_2 F_22 ( void )
{
if ( ! F_5 () ) {
F_23 ( L_6 ) ;
return - V_35 ;
}
#ifdef F_24
if ( V_13 != V_17 )
F_25 ( L_7 ,
V_17 ) ;
#endif
F_26 ( V_36 . V_12 , V_36 . V_33 , NULL ) ;
F_27 ( & V_36 ) ;
F_28 ( L_8 ,
V_13 ) ;
return 0 ;
}
static T_3 F_29 ( int V_37 , void * V_14 )
{
struct V_1 * V_2 = V_14 ;
unsigned int V_20 , V_21 , V_25 ;
int V_16 ;
char V_38 [ V_29 ] ;
int V_15 ;
F_15 ( V_2 -> V_23 , & V_20 , & V_21 ) ;
V_16 = F_30 ( & V_2 -> V_39 , V_20 ) ;
while ( V_16 > 0 ) {
V_25 = F_19 (unsigned int, count, sizeof(buffer)) ;
F_31 ( V_2 -> V_23 , & V_25 , V_38 ) ;
V_15 = F_32 ( & V_2 -> V_39 , V_38 , V_25 ) ;
if ( V_15 != V_25 )
break;
V_16 -= V_25 ;
}
F_33 ( & V_2 -> V_39 ) ;
return V_40 ;
}
static void F_34 ( struct V_1 * V_2 )
{
unsigned int V_16 ;
unsigned int V_25 , V_15 ;
unsigned long V_41 ;
do {
F_35 ( & V_2 -> V_42 , V_41 ) ;
V_25 = F_19 (unsigned int,
CIRC_CNT_TO_END(bc->head, bc->tail, BUF_SIZE),
EV_BYTE_CHANNEL_MAX_BYTES) ;
V_15 = F_12 ( V_2 -> V_23 , & V_25 , V_2 -> V_43 + V_2 -> V_44 ) ;
if ( ! V_15 || ( V_15 == V_18 ) )
V_2 -> V_44 = ( V_2 -> V_44 + V_25 ) & ( V_45 - 1 ) ;
V_16 = F_36 ( V_2 -> V_46 , V_2 -> V_44 , V_45 ) ;
F_37 ( & V_2 -> V_42 , V_41 ) ;
} while ( V_16 && ! V_15 );
F_35 ( & V_2 -> V_42 , V_41 ) ;
if ( F_36 ( V_2 -> V_46 , V_2 -> V_44 , V_45 ) )
F_1 ( V_2 ) ;
else
F_3 ( V_2 ) ;
F_37 ( & V_2 -> V_42 , V_41 ) ;
}
static T_3 F_38 ( int V_37 , void * V_14 )
{
struct V_1 * V_2 = V_14 ;
F_34 ( V_2 ) ;
F_39 ( & V_2 -> V_39 ) ;
return V_40 ;
}
static int F_40 ( struct V_47 * V_48 , const unsigned char * V_24 ,
int V_16 )
{
struct V_1 * V_2 = V_48 -> V_49 ;
unsigned long V_41 ;
unsigned int V_25 ;
unsigned int V_50 = 0 ;
while ( 1 ) {
F_35 ( & V_2 -> V_42 , V_41 ) ;
V_25 = F_41 ( V_2 -> V_46 , V_2 -> V_44 , V_45 ) ;
if ( V_16 < V_25 )
V_25 = V_16 ;
if ( V_25 ) {
memcpy ( V_2 -> V_43 + V_2 -> V_46 , V_24 , V_25 ) ;
V_2 -> V_46 = ( V_2 -> V_46 + V_25 ) & ( V_45 - 1 ) ;
}
F_37 ( & V_2 -> V_42 , V_41 ) ;
if ( ! V_25 )
break;
V_24 += V_25 ;
V_16 -= V_25 ;
V_50 += V_25 ;
}
F_34 ( V_2 ) ;
return V_50 ;
}
static int F_42 ( struct V_47 * V_48 , struct V_51 * V_52 )
{
struct V_1 * V_2 = & V_53 [ V_48 -> V_33 ] ;
if ( ! V_2 -> V_54 )
return - V_35 ;
return F_43 ( & V_2 -> V_39 , V_48 , V_52 ) ;
}
static void F_44 ( struct V_47 * V_48 , struct V_51 * V_52 )
{
struct V_1 * V_2 = & V_53 [ V_48 -> V_33 ] ;
if ( V_2 -> V_54 )
F_45 ( & V_2 -> V_39 , V_48 , V_52 ) ;
}
static int F_46 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = V_48 -> V_49 ;
unsigned long V_41 ;
int V_16 ;
F_35 ( & V_2 -> V_42 , V_41 ) ;
V_16 = F_47 ( V_2 -> V_46 , V_2 -> V_44 , V_45 ) ;
F_37 ( & V_2 -> V_42 , V_41 ) ;
return V_16 ;
}
static void F_48 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = V_48 -> V_49 ;
F_49 ( V_2 -> V_55 ) ;
}
static void F_50 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = V_48 -> V_49 ;
F_2 ( V_2 -> V_55 ) ;
}
static void F_51 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = V_48 -> V_49 ;
F_34 ( V_2 ) ;
F_52 ( & V_2 -> V_39 ) ;
}
static int F_53 ( struct V_56 * V_39 ,
struct V_47 * V_48 )
{
struct V_1 * V_2 = F_54 ( V_39 , struct V_1 , V_39 ) ;
int V_15 ;
V_48 -> V_49 = V_2 ;
V_15 = F_55 ( V_2 -> V_55 , F_29 , 0 , L_9 , V_2 ) ;
if ( V_15 < 0 ) {
F_56 ( V_2 -> V_54 , L_10 ,
V_2 -> V_55 , V_15 ) ;
return V_15 ;
}
V_2 -> V_3 = 1 ;
V_15 = F_55 ( V_2 -> V_4 , F_38 , 0 , L_9 , V_2 ) ;
if ( V_15 < 0 ) {
F_56 ( V_2 -> V_54 , L_11 ,
V_2 -> V_4 , V_15 ) ;
F_57 ( V_2 -> V_55 , V_2 ) ;
return V_15 ;
}
F_3 ( V_2 ) ;
return 0 ;
}
static void F_58 ( struct V_56 * V_39 )
{
struct V_1 * V_2 = F_54 ( V_39 , struct V_1 , V_39 ) ;
F_57 ( V_2 -> V_4 , V_2 ) ;
F_57 ( V_2 -> V_55 , V_2 ) ;
}
static int F_59 ( struct V_57 * V_58 )
{
struct V_5 * V_6 = V_58 -> V_54 . V_59 ;
struct V_1 * V_2 ;
const T_1 * V_8 ;
unsigned int V_23 ;
int V_15 ;
static unsigned int V_33 = 1 ;
unsigned int V_30 ;
V_8 = F_9 ( V_6 , L_3 , NULL ) ;
if ( ! V_8 ) {
F_56 ( & V_58 -> V_54 , L_12 ,
V_6 -> V_12 ) ;
return - V_35 ;
}
V_23 = F_10 ( * V_8 ) ;
V_30 = ( V_23 == V_13 ) ? 0 : V_33 ++ ;
V_2 = & V_53 [ V_30 ] ;
V_2 -> V_23 = V_23 ;
V_2 -> V_46 = 0 ;
V_2 -> V_44 = 0 ;
F_60 ( & V_2 -> V_42 ) ;
V_2 -> V_55 = F_7 ( V_6 , 0 ) ;
V_2 -> V_4 = F_7 ( V_6 , 1 ) ;
if ( ( V_2 -> V_55 == V_10 ) || ( V_2 -> V_4 == V_10 ) ) {
F_56 ( & V_58 -> V_54 , L_13 ,
V_6 -> V_12 ) ;
V_15 = - V_35 ;
goto error;
}
F_61 ( & V_2 -> V_39 ) ;
V_2 -> V_39 . V_60 = & V_61 ;
V_2 -> V_54 = F_62 ( & V_2 -> V_39 , V_34 , V_30 ,
& V_58 -> V_54 ) ;
if ( F_63 ( V_2 -> V_54 ) ) {
V_15 = F_64 ( V_2 -> V_54 ) ;
F_56 ( & V_58 -> V_54 , L_14 , V_15 ) ;
goto error;
}
F_65 ( & V_58 -> V_54 , V_2 ) ;
F_66 ( & V_58 -> V_54 , L_15 ,
V_34 -> V_12 , V_30 , V_2 -> V_23 ) ;
return 0 ;
error:
F_67 ( & V_2 -> V_39 ) ;
F_68 ( V_2 -> V_4 ) ;
F_68 ( V_2 -> V_55 ) ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
return V_15 ;
}
static int F_69 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = F_70 ( & V_58 -> V_54 ) ;
F_71 ( V_34 , V_2 - V_53 ) ;
F_67 ( & V_2 -> V_39 ) ;
F_68 ( V_2 -> V_4 ) ;
F_68 ( V_2 -> V_55 ) ;
return 0 ;
}
static int T_2 F_72 ( void )
{
struct V_5 * V_6 ;
unsigned int V_16 = 0 ;
int V_15 ;
F_28 ( L_16 ) ;
F_73 (np, NULL, L_1 )
V_16 ++ ;
if ( ! V_16 )
return - V_35 ;
V_53 = F_74 ( V_16 * sizeof( struct V_1 ) , V_62 ) ;
if ( ! V_53 )
return - V_63 ;
V_34 = F_75 ( V_16 ) ;
if ( ! V_34 ) {
V_15 = - V_63 ;
goto error;
}
V_34 -> V_64 = L_9 ;
V_34 -> V_12 = V_36 . V_12 ;
V_34 -> type = V_65 ;
V_34 -> V_66 = V_67 ;
V_34 -> V_68 = V_69 ;
V_34 -> V_41 = V_70 | V_71 ;
F_76 ( V_34 , & V_72 ) ;
V_15 = F_77 ( V_34 ) ;
if ( V_15 ) {
F_8 ( L_17 , V_15 ) ;
goto error;
}
V_15 = F_78 ( & V_73 ) ;
if ( V_15 ) {
F_8 ( L_18 ,
V_15 ) ;
goto error;
}
return 0 ;
error:
if ( V_34 ) {
F_79 ( V_34 ) ;
F_80 ( V_34 ) ;
}
F_81 ( V_53 ) ;
return V_15 ;
}
static void T_4 F_82 ( void )
{
F_83 ( & V_73 ) ;
F_79 ( V_34 ) ;
F_80 ( V_34 ) ;
F_81 ( V_53 ) ;
}
