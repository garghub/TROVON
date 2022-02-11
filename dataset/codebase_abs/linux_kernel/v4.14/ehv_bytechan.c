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
F_8 ( L_2 , V_6 ) ;
return 0 ;
}
V_8 = F_9 ( V_6 , L_3 , NULL ) ;
if ( ! V_8 ) {
F_8 ( L_4 ,
V_6 -> V_11 ) ;
return 0 ;
}
V_12 = F_10 ( * V_8 ) ;
return 1 ;
}
static void F_11 ( const char V_13 )
{
int V_14 , V_15 ;
do {
V_15 = 1 ;
V_14 = F_12 ( V_16 ,
& V_15 , & V_13 ) ;
} while ( V_14 == V_17 );
}
static void F_13 ( char V_18 )
{
if ( V_18 == '\n' )
F_11 ( '\r' ) ;
F_11 ( V_18 ) ;
}
void T_2 F_14 ( void )
{
unsigned int V_19 , V_20 ;
unsigned int V_14 ;
V_14 = F_15 ( V_16 ,
& V_19 , & V_20 ) ;
if ( V_14 )
return;
V_21 = F_13 ;
F_16 () ;
F_17 ( L_5 ,
V_16 ) ;
}
static int F_18 ( unsigned int V_22 , const char * V_23 ,
unsigned int V_15 )
{
unsigned int V_24 ;
int V_14 = 0 ;
while ( V_15 ) {
V_24 = F_19 (unsigned int, count, EV_BYTE_CHANNEL_MAX_BYTES) ;
do {
V_14 = F_12 ( V_22 , & V_24 , V_23 ) ;
} while ( V_14 == V_17 );
V_15 -= V_24 ;
V_23 += V_24 ;
}
return V_14 ;
}
static void F_20 ( struct V_25 * V_26 , const char * V_23 ,
unsigned int V_15 )
{
char V_27 [ V_28 ] ;
unsigned int V_29 , V_30 = 0 ;
char V_18 ;
for ( V_29 = 0 ; V_29 < V_15 ; V_29 ++ ) {
V_18 = * V_23 ++ ;
if ( V_18 == '\n' )
V_27 [ V_30 ++ ] = '\r' ;
V_27 [ V_30 ++ ] = V_18 ;
if ( V_30 >= ( V_28 - 1 ) ) {
if ( F_18 ( V_12 , V_27 , V_30 ) )
return;
V_30 = 0 ;
}
}
if ( V_30 )
F_18 ( V_12 , V_27 , V_30 ) ;
}
static struct V_31 * F_21 ( struct V_25 * V_26 , int * V_32 )
{
* V_32 = V_26 -> V_32 ;
return V_33 ;
}
static int T_2 F_22 ( void )
{
if ( ! F_5 () ) {
F_23 ( L_6 ) ;
return - V_34 ;
}
#ifdef F_24
if ( V_12 != V_16 )
F_25 ( L_7 ,
V_16 ) ;
#endif
F_26 ( V_35 . V_11 , V_35 . V_32 , NULL ) ;
F_27 ( & V_35 ) ;
F_28 ( L_8 ,
V_12 ) ;
return 0 ;
}
static T_3 F_29 ( int V_36 , void * V_13 )
{
struct V_1 * V_2 = V_13 ;
unsigned int V_19 , V_20 , V_24 ;
int V_15 ;
char V_37 [ V_28 ] ;
int V_14 ;
F_15 ( V_2 -> V_22 , & V_19 , & V_20 ) ;
V_15 = F_30 ( & V_2 -> V_38 , V_19 ) ;
while ( V_15 > 0 ) {
V_24 = F_19 (unsigned int, count, sizeof(buffer)) ;
F_31 ( V_2 -> V_22 , & V_24 , V_37 ) ;
V_14 = F_32 ( & V_2 -> V_38 , V_37 , V_24 ) ;
if ( V_14 != V_24 )
break;
V_15 -= V_24 ;
}
F_33 ( & V_2 -> V_38 ) ;
return V_39 ;
}
static void F_34 ( struct V_1 * V_2 )
{
unsigned int V_15 ;
unsigned int V_24 , V_14 ;
unsigned long V_40 ;
do {
F_35 ( & V_2 -> V_41 , V_40 ) ;
V_24 = F_19 (unsigned int,
CIRC_CNT_TO_END(bc->head, bc->tail, BUF_SIZE),
EV_BYTE_CHANNEL_MAX_BYTES) ;
V_14 = F_12 ( V_2 -> V_22 , & V_24 , V_2 -> V_42 + V_2 -> V_43 ) ;
if ( ! V_14 || ( V_14 == V_17 ) )
V_2 -> V_43 = ( V_2 -> V_43 + V_24 ) & ( V_44 - 1 ) ;
V_15 = F_36 ( V_2 -> V_45 , V_2 -> V_43 , V_44 ) ;
F_37 ( & V_2 -> V_41 , V_40 ) ;
} while ( V_15 && ! V_14 );
F_35 ( & V_2 -> V_41 , V_40 ) ;
if ( F_36 ( V_2 -> V_45 , V_2 -> V_43 , V_44 ) )
F_1 ( V_2 ) ;
else
F_3 ( V_2 ) ;
F_37 ( & V_2 -> V_41 , V_40 ) ;
}
static T_3 F_38 ( int V_36 , void * V_13 )
{
struct V_1 * V_2 = V_13 ;
F_34 ( V_2 ) ;
F_39 ( & V_2 -> V_38 ) ;
return V_39 ;
}
static int F_40 ( struct V_46 * V_47 , const unsigned char * V_23 ,
int V_15 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
unsigned long V_40 ;
unsigned int V_24 ;
unsigned int V_49 = 0 ;
while ( 1 ) {
F_35 ( & V_2 -> V_41 , V_40 ) ;
V_24 = F_41 ( V_2 -> V_45 , V_2 -> V_43 , V_44 ) ;
if ( V_15 < V_24 )
V_24 = V_15 ;
if ( V_24 ) {
memcpy ( V_2 -> V_42 + V_2 -> V_45 , V_23 , V_24 ) ;
V_2 -> V_45 = ( V_2 -> V_45 + V_24 ) & ( V_44 - 1 ) ;
}
F_37 ( & V_2 -> V_41 , V_40 ) ;
if ( ! V_24 )
break;
V_23 += V_24 ;
V_15 -= V_24 ;
V_49 += V_24 ;
}
F_34 ( V_2 ) ;
return V_49 ;
}
static int F_42 ( struct V_46 * V_47 , struct V_50 * V_51 )
{
struct V_1 * V_2 = & V_52 [ V_47 -> V_32 ] ;
if ( ! V_2 -> V_53 )
return - V_34 ;
return F_43 ( & V_2 -> V_38 , V_47 , V_51 ) ;
}
static void F_44 ( struct V_46 * V_47 , struct V_50 * V_51 )
{
struct V_1 * V_2 = & V_52 [ V_47 -> V_32 ] ;
if ( V_2 -> V_53 )
F_45 ( & V_2 -> V_38 , V_47 , V_51 ) ;
}
static int F_46 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
unsigned long V_40 ;
int V_15 ;
F_35 ( & V_2 -> V_41 , V_40 ) ;
V_15 = F_47 ( V_2 -> V_45 , V_2 -> V_43 , V_44 ) ;
F_37 ( & V_2 -> V_41 , V_40 ) ;
return V_15 ;
}
static void F_48 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
F_49 ( V_2 -> V_54 ) ;
}
static void F_50 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
F_2 ( V_2 -> V_54 ) ;
}
static void F_51 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
F_34 ( V_2 ) ;
F_52 ( & V_2 -> V_38 ) ;
}
static int F_53 ( struct V_55 * V_38 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 = F_54 ( V_38 , struct V_1 , V_38 ) ;
int V_14 ;
V_47 -> V_48 = V_2 ;
V_14 = F_55 ( V_2 -> V_54 , F_29 , 0 , L_9 , V_2 ) ;
if ( V_14 < 0 ) {
F_56 ( V_2 -> V_53 , L_10 ,
V_2 -> V_54 , V_14 ) ;
return V_14 ;
}
V_2 -> V_3 = 1 ;
V_14 = F_55 ( V_2 -> V_4 , F_38 , 0 , L_9 , V_2 ) ;
if ( V_14 < 0 ) {
F_56 ( V_2 -> V_53 , L_11 ,
V_2 -> V_4 , V_14 ) ;
F_57 ( V_2 -> V_54 , V_2 ) ;
return V_14 ;
}
F_3 ( V_2 ) ;
return 0 ;
}
static void F_58 ( struct V_55 * V_38 )
{
struct V_1 * V_2 = F_54 ( V_38 , struct V_1 , V_38 ) ;
F_57 ( V_2 -> V_4 , V_2 ) ;
F_57 ( V_2 -> V_54 , V_2 ) ;
}
static int F_59 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = V_57 -> V_53 . V_58 ;
struct V_1 * V_2 ;
const T_1 * V_8 ;
unsigned int V_22 ;
int V_14 ;
static unsigned int V_32 = 1 ;
unsigned int V_29 ;
V_8 = F_9 ( V_6 , L_3 , NULL ) ;
if ( ! V_8 ) {
F_56 ( & V_57 -> V_53 , L_12 ,
V_6 -> V_11 ) ;
return - V_34 ;
}
V_22 = F_10 ( * V_8 ) ;
V_29 = ( V_22 == V_12 ) ? 0 : V_32 ++ ;
V_2 = & V_52 [ V_29 ] ;
V_2 -> V_22 = V_22 ;
V_2 -> V_45 = 0 ;
V_2 -> V_43 = 0 ;
F_60 ( & V_2 -> V_41 ) ;
V_2 -> V_54 = F_7 ( V_6 , 0 ) ;
V_2 -> V_4 = F_7 ( V_6 , 1 ) ;
if ( ( V_2 -> V_54 == V_10 ) || ( V_2 -> V_4 == V_10 ) ) {
F_56 ( & V_57 -> V_53 , L_13 ,
V_6 -> V_11 ) ;
V_14 = - V_34 ;
goto error;
}
F_61 ( & V_2 -> V_38 ) ;
V_2 -> V_38 . V_59 = & V_60 ;
V_2 -> V_53 = F_62 ( & V_2 -> V_38 , V_33 , V_29 ,
& V_57 -> V_53 ) ;
if ( F_63 ( V_2 -> V_53 ) ) {
V_14 = F_64 ( V_2 -> V_53 ) ;
F_56 ( & V_57 -> V_53 , L_14 , V_14 ) ;
goto error;
}
F_65 ( & V_57 -> V_53 , V_2 ) ;
F_66 ( & V_57 -> V_53 , L_15 ,
V_33 -> V_11 , V_29 , V_2 -> V_22 ) ;
return 0 ;
error:
F_67 ( & V_2 -> V_38 ) ;
F_68 ( V_2 -> V_4 ) ;
F_68 ( V_2 -> V_54 ) ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
return V_14 ;
}
static int T_2 F_69 ( void )
{
struct V_5 * V_6 ;
unsigned int V_15 = 0 ;
int V_14 ;
F_28 ( L_16 ) ;
F_70 (np, NULL, L_1 )
V_15 ++ ;
if ( ! V_15 )
return - V_34 ;
V_52 = F_71 ( V_15 * sizeof( struct V_1 ) , V_61 ) ;
if ( ! V_52 )
return - V_62 ;
V_33 = F_72 ( V_15 ) ;
if ( ! V_33 ) {
V_14 = - V_62 ;
goto V_63;
}
V_33 -> V_64 = L_9 ;
V_33 -> V_11 = V_35 . V_11 ;
V_33 -> type = V_65 ;
V_33 -> V_66 = V_67 ;
V_33 -> V_68 = V_69 ;
V_33 -> V_40 = V_70 | V_71 ;
F_73 ( V_33 , & V_72 ) ;
V_14 = F_74 ( V_33 ) ;
if ( V_14 ) {
F_8 ( L_17 , V_14 ) ;
goto V_73;
}
V_14 = F_75 ( & V_74 ) ;
if ( V_14 ) {
F_8 ( L_18 ,
V_14 ) ;
goto V_75;
}
return 0 ;
V_75:
F_76 ( V_33 ) ;
V_73:
F_77 ( V_33 ) ;
V_63:
F_78 ( V_52 ) ;
return V_14 ;
}
