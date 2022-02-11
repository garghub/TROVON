static int F_1 ( T_1 V_1 , char * V_2 , int V_3 )
{
struct V_4 * V_5 = V_6 [ V_1 ] ;
unsigned long V_7 ;
unsigned long V_8 ;
int V_9 ;
if ( F_2 ( ! V_5 ) )
return 0 ;
F_3 ( & V_5 -> V_10 , V_8 ) ;
if ( V_5 -> V_11 == 0 ) {
V_5 -> V_12 = 0 ;
V_5 -> V_11 = F_4 ( V_5 -> V_13 , V_5 -> V_2 , V_3 ) ;
for ( V_7 = 1 ; V_7 < V_5 -> V_11 ; ++ V_7 ) {
if ( V_5 -> V_2 [ V_7 ] == 0 && V_5 -> V_2 [ V_7 - 1 ] == '\r' ) {
-- V_5 -> V_11 ;
if ( V_7 < V_5 -> V_11 ) {
memmove ( & V_5 -> V_2 [ V_7 ] , & V_5 -> V_2 [ V_7 + 1 ] ,
V_5 -> V_11 - V_7 ) ;
}
}
}
}
V_9 = F_5 ( V_3 , V_5 -> V_11 ) ;
memcpy ( V_2 , & V_5 -> V_2 [ V_5 -> V_12 ] , V_9 ) ;
V_5 -> V_12 += V_9 ;
V_5 -> V_11 -= V_9 ;
F_6 ( & V_5 -> V_10 , V_8 ) ;
return V_9 ;
}
static int F_7 ( T_1 V_1 , const char * V_2 , int V_3 )
{
struct V_4 * V_5 = V_6 [ V_1 ] ;
if ( F_2 ( ! V_5 ) )
return 0 ;
return F_8 ( V_5 -> V_13 , V_2 , V_3 ) ;
}
static int F_9 ( T_1 V_1 , char * V_2 , int V_3 )
{
struct V_4 * V_5 = V_6 [ V_1 ] ;
if ( F_2 ( ! V_5 ) )
return 0 ;
return F_10 ( & V_5 -> V_14 , V_2 , V_3 ) ;
}
static int F_11 ( T_1 V_1 , const char * V_2 , int V_3 )
{
struct V_4 * V_5 = V_6 [ V_1 ] ;
if ( F_2 ( ! V_5 ) )
return 0 ;
return F_12 ( & V_5 -> V_14 , V_2 , V_3 ) ;
}
static int F_13 ( struct V_15 * V_16 , int V_17 )
{
struct V_4 * V_5 = V_6 [ V_16 -> V_1 ] ;
int V_18 ;
F_14 ( L_1 , V_5 -> V_13 ) ;
V_18 = F_15 ( V_16 , V_17 ) ;
if ( V_18 )
return V_18 ;
return F_16 ( & V_5 -> V_14 , V_16 ) ;
}
static void F_17 ( struct V_15 * V_16 , int V_17 )
{
struct V_4 * V_5 = V_6 [ V_16 -> V_1 ] ;
F_14 ( L_2 , V_5 -> V_13 ) ;
F_18 ( & V_5 -> V_14 , V_16 ) ;
F_19 ( V_16 , V_17 ) ;
}
void F_20 ( struct V_15 * V_16 , int V_17 )
{
struct V_4 * V_5 = V_6 [ V_16 -> V_1 ] ;
F_14 ( L_3 , V_5 -> V_13 ) ;
F_18 ( & V_5 -> V_14 , V_16 ) ;
F_21 ( V_16 , V_17 ) ;
}
static int F_22 ( struct V_15 * V_16 )
{
struct V_4 * V_5 = V_6 [ V_16 -> V_1 ] ;
if ( ! V_5 )
return - V_19 ;
return V_5 -> V_14 . V_20 ;
}
static int F_23 ( struct V_15 * V_16 , unsigned int V_21 ,
unsigned int V_22 )
{
struct V_4 * V_5 = V_6 [ V_16 -> V_1 ] ;
F_14 ( L_4 ,
V_5 -> V_13 , V_21 , V_22 ) ;
if ( V_21 & V_23 )
F_24 ( & V_5 -> V_14 , 1 ) ;
else if ( V_22 & V_23 )
F_24 ( & V_5 -> V_14 , 0 ) ;
return 0 ;
}
static int T_2 F_25 ( struct V_24 * V_25 ,
const struct V_26 * V_27 )
{
const struct V_28 * V_29 ;
struct V_15 * V_16 ;
struct V_4 * V_5 ;
T_3 V_30 ;
int V_7 , V_13 = - 1 ;
if ( ! V_25 || ! V_27 )
return - V_31 ;
if ( F_26 ( V_25 -> V_32 . V_33 , L_5 ) ) {
V_30 = V_34 ;
V_29 = & V_35 ;
} else if ( F_26 ( V_25 -> V_32 . V_33 , L_6 ) ) {
V_30 = V_36 ;
V_29 = & V_37 ;
} else {
F_27 ( L_7 , V_25 -> V_32 . V_33 -> V_38 ) ;
return - V_39 ;
}
F_14 ( L_8 ,
V_25 -> V_32 . V_33 -> V_38 ,
V_30 == V_34 ? L_9 : L_10 ) ;
if ( V_6 [ 0 ] == & V_40 &&
V_25 -> V_41 == V_40 . V_13 ) {
V_5 = V_6 [ 0 ] ;
V_13 = 0 ;
F_14 ( L_11 ) ;
}
else {
for ( V_7 = 0 ; V_7 < V_42 && V_13 < 0 ; V_7 ++ )
if ( ! V_6 [ V_7 ] )
V_13 = V_7 ;
F_14 ( L_12 , V_13 ) ;
if ( V_13 < 0 )
return - V_43 ;
V_5 = F_28 ( sizeof( struct V_4 ) , V_44 ) ;
if ( ! V_5 )
return - V_45 ;
V_5 -> V_13 = V_25 -> V_41 ;
V_5 -> V_30 = V_30 ;
F_29 ( & V_5 -> V_10 ) ;
V_6 [ V_13 ] = V_5 ;
F_30 ( & V_5 -> V_14 , F_4 , F_8 ,
V_5 -> V_13 , 0 ) ;
}
V_16 = F_31 ( V_13 , V_25 -> V_46 , V_29 , V_47 ) ;
if ( F_32 ( V_16 ) )
return F_33 ( V_16 ) ;
F_34 ( & V_25 -> V_32 , V_16 ) ;
return 0 ;
}
static int T_4 F_35 ( struct V_24 * V_25 )
{
struct V_15 * V_16 = F_36 ( & V_25 -> V_32 ) ;
int V_18 , V_13 ;
V_13 = V_16 -> V_1 ;
V_18 = F_37 ( V_16 ) ;
if ( V_18 == 0 ) {
if ( V_6 [ V_13 ] != & V_40 )
F_38 ( V_6 [ V_13 ] ) ;
V_6 [ V_13 ] = NULL ;
}
return V_18 ;
}
static int T_5 F_39 ( void )
{
int V_18 ;
if ( F_40 ( V_48 ) )
return - V_49 ;
V_18 = F_41 ( & V_50 ) ;
return V_18 ;
}
static void T_6 F_42 ( void )
{
F_43 ( & V_50 ) ;
}
static void F_44 ( char V_51 )
{
int V_3 = - 1 ;
if ( V_51 == '\n' )
F_44 ( '\r' ) ;
do {
switch( V_40 . V_30 ) {
case V_34 :
V_3 = F_7 ( 0 , & V_51 , 1 ) ;
break;
case V_36 :
V_3 = F_11 ( 0 , & V_51 , 1 ) ;
break;
}
} while( V_3 == 0 );
}
static int F_45 ( void )
{
int V_18 = 0 ;
char V_51 ;
switch( V_40 . V_30 ) {
case V_34 :
V_18 = F_1 ( 0 , & V_51 , 1 ) ;
break;
case V_36 :
V_18 = F_9 ( 0 , & V_51 , 1 ) ;
break;
}
if ( ! V_18 )
return - 1 ;
return V_51 ;
}
static int F_46 ( void )
{
int V_52 ;
for (; ; ) {
V_52 = F_45 () ;
if ( V_52 == - 1 ) {
volatile unsigned long V_53 ;
for ( V_53 = 0 ; V_53 < 2000000 ; V_53 ++ )
;
} else {
return V_52 ;
}
}
}
void T_5 F_47 ( void )
{
struct V_54 * V_55 ;
const T_7 * V_13 ;
const char * V_56 ;
const struct V_28 * V_29 ;
if ( ! V_57 )
return;
V_56 = F_48 ( V_57 , L_13 , NULL ) ;
if ( V_56 == NULL )
return;
V_55 = F_49 ( V_56 ) ;
if ( ! V_55 )
return;
V_56 = F_48 ( V_55 , L_14 , NULL ) ;
if ( ! V_56 ) {
F_50 ( V_58 L_15 ) ;
goto V_59;
}
if ( strncmp ( V_56 , L_16 , 3 ) != 0 )
goto V_59;
V_13 = F_48 ( V_55 , L_17 , NULL ) ;
if ( V_13 == NULL )
goto V_59;
V_40 . V_13 = * V_13 ;
F_29 ( & V_40 . V_10 ) ;
V_6 [ 0 ] = & V_40 ;
if ( F_26 ( V_55 , L_5 ) ) {
V_40 . V_30 = V_34 ;
V_29 = & V_35 ;
}
else if ( F_26 ( V_55 , L_6 ) ) {
V_40 . V_30 = V_36 ;
V_29 = & V_37 ;
F_30 ( & V_40 . V_14 , F_4 , F_8 ,
V_40 . V_13 , 1 ) ;
F_51 ( & V_40 . V_14 ) ;
} else
goto V_59;
V_60 = F_44 ;
V_61 = F_46 ;
V_62 = F_45 ;
#ifdef F_52
if ( V_40 . V_30 == V_36 )
goto V_59;
#endif
F_53 ( L_18 , 0 , NULL ) ;
F_54 ( 0 , 0 , V_29 ) ;
V_59:
F_55 ( V_55 ) ;
}
void T_5 F_56 ( void )
{
V_6 [ 0 ] = & V_40 ;
V_40 . V_13 = 0 ;
V_40 . V_30 = V_34 ;
F_29 ( & V_40 . V_10 ) ;
V_60 = F_44 ;
V_61 = F_46 ;
V_62 = F_45 ;
}
void T_5 F_57 ( void )
{
V_6 [ 0 ] = & V_40 ;
V_40 . V_13 = V_63 ;
V_40 . V_30 = V_36 ;
F_29 ( & V_40 . V_10 ) ;
V_60 = F_44 ;
V_61 = F_46 ;
V_62 = F_45 ;
F_30 ( & V_40 . V_14 , F_4 , F_8 ,
V_40 . V_13 , 1 ) ;
F_51 ( & V_40 . V_14 ) ;
}
