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
static void F_25 ( char V_24 )
{
int V_3 = - 1 ;
if ( ! V_6 [ 0 ] )
return;
if ( V_24 == '\n' )
F_25 ( '\r' ) ;
do {
switch( V_6 [ 0 ] -> V_25 ) {
case V_26 :
V_3 = F_7 ( 0 , & V_24 , 1 ) ;
break;
case V_27 :
V_3 = F_11 ( 0 , & V_24 , 1 ) ;
break;
}
} while( V_3 == 0 );
}
static int F_26 ( void )
{
int V_18 = 0 ;
char V_24 ;
if ( ! V_6 [ 0 ] )
return - 1 ;
switch( V_6 [ 0 ] -> V_25 ) {
case V_26 :
V_18 = F_1 ( 0 , & V_24 , 1 ) ;
break;
case V_27 :
V_18 = F_9 ( 0 , & V_24 , 1 ) ;
break;
}
if ( ! V_18 )
return - 1 ;
return V_24 ;
}
static int F_27 ( void )
{
int V_28 ;
if ( ! V_6 [ 0 ] )
return - 1 ;
for (; ; ) {
V_28 = F_26 () ;
if ( V_28 == - 1 ) {
volatile unsigned long V_29 ;
for ( V_29 = 0 ; V_29 < 2000000 ; V_29 ++ )
;
} else {
return V_28 ;
}
}
}
static int F_28 ( struct V_30 * V_31 ,
const struct V_32 * V_33 )
{
const struct V_34 * V_35 ;
struct V_15 * V_16 ;
struct V_4 * V_5 ;
T_2 V_25 ;
int V_7 , V_13 = - 1 ;
if ( ! V_31 || ! V_33 )
return - V_36 ;
if ( F_29 ( V_31 -> V_37 . V_38 , L_5 ) ) {
V_25 = V_26 ;
V_35 = & V_39 ;
} else if ( F_29 ( V_31 -> V_37 . V_38 , L_6 ) ) {
V_25 = V_27 ;
V_35 = & V_40 ;
} else {
F_30 ( L_7 , V_31 -> V_37 . V_38 -> V_41 ) ;
return - V_42 ;
}
F_14 ( L_8 ,
V_31 -> V_37 . V_38 -> V_41 ,
V_25 == V_26 ? L_9 : L_10 ) ;
if ( V_6 [ 0 ] == & V_43 &&
V_31 -> V_44 == V_43 . V_13 ) {
V_5 = V_6 [ 0 ] ;
V_13 = 0 ;
F_14 ( L_11 ) ;
}
else {
for ( V_7 = 0 ; V_7 < V_45 && V_13 < 0 ; V_7 ++ )
if ( ! V_6 [ V_7 ] )
V_13 = V_7 ;
F_14 ( L_12 , V_13 ) ;
if ( V_13 < 0 )
return - V_46 ;
V_5 = F_31 ( sizeof( struct V_4 ) , V_47 ) ;
if ( ! V_5 )
return - V_48 ;
V_5 -> V_13 = V_31 -> V_44 ;
V_5 -> V_25 = V_25 ;
F_32 ( & V_5 -> V_10 ) ;
V_6 [ V_13 ] = V_5 ;
F_33 ( & V_5 -> V_14 , F_4 , F_8 ,
V_5 -> V_13 , 0 ) ;
}
V_16 = F_34 ( V_13 , V_31 -> V_49 , V_35 , V_50 ) ;
if ( F_35 ( V_16 ) )
return F_36 ( V_16 ) ;
F_37 ( & V_31 -> V_37 , V_16 ) ;
if ( V_16 -> V_51 == 0 && ! V_52 ) {
V_52 = F_25 ;
V_53 = F_27 ;
V_54 = F_26 ;
}
return 0 ;
}
static int F_38 ( struct V_30 * V_31 )
{
struct V_15 * V_16 = F_39 ( & V_31 -> V_37 ) ;
int V_18 , V_13 ;
V_13 = V_16 -> V_1 ;
V_18 = F_40 ( V_16 ) ;
if ( V_18 == 0 ) {
if ( V_6 [ V_13 ] != & V_43 )
F_41 ( V_6 [ V_13 ] ) ;
V_6 [ V_13 ] = NULL ;
}
return V_18 ;
}
static int T_3 F_42 ( void )
{
int V_18 ;
V_18 = F_43 ( & V_55 ) ;
return V_18 ;
}
static void T_4 F_44 ( void )
{
F_45 ( & V_55 ) ;
}
void T_3 F_46 ( void )
{
struct V_56 * V_57 ;
const T_5 * V_13 ;
const char * V_58 ;
const struct V_34 * V_35 ;
if ( ! V_59 )
return;
V_58 = F_47 ( V_59 , L_13 , NULL ) ;
if ( V_58 == NULL )
return;
V_57 = F_48 ( V_58 ) ;
if ( ! V_57 )
return;
V_58 = F_47 ( V_57 , L_14 , NULL ) ;
if ( ! V_58 ) {
F_49 ( V_60 L_15 ) ;
goto V_61;
}
if ( strncmp ( V_58 , L_16 , 3 ) != 0 )
goto V_61;
V_13 = F_47 ( V_57 , L_17 , NULL ) ;
if ( V_13 == NULL )
goto V_61;
V_43 . V_13 = * V_13 ;
F_32 ( & V_43 . V_10 ) ;
V_6 [ 0 ] = & V_43 ;
if ( F_29 ( V_57 , L_5 ) ) {
V_43 . V_25 = V_26 ;
V_35 = & V_39 ;
}
else if ( F_29 ( V_57 , L_6 ) ) {
V_43 . V_25 = V_27 ;
V_35 = & V_40 ;
F_33 ( & V_43 . V_14 , F_4 , F_8 ,
V_43 . V_13 , 1 ) ;
F_50 ( & V_43 . V_14 ) ;
} else
goto V_61;
V_52 = F_25 ;
V_53 = F_27 ;
V_54 = F_26 ;
#ifdef F_51
if ( V_43 . V_25 == V_27 )
goto V_61;
#endif
F_52 ( L_18 , 0 , NULL ) ;
F_53 ( 0 , 0 , V_35 ) ;
V_61:
F_54 ( V_57 ) ;
}
void T_3 F_55 ( void )
{
V_6 [ 0 ] = & V_43 ;
V_43 . V_13 = 0 ;
V_43 . V_25 = V_26 ;
F_32 ( & V_43 . V_10 ) ;
V_52 = F_25 ;
V_53 = F_27 ;
V_54 = F_26 ;
}
void T_3 F_56 ( void )
{
V_6 [ 0 ] = & V_43 ;
V_43 . V_13 = V_62 ;
V_43 . V_25 = V_27 ;
F_32 ( & V_43 . V_10 ) ;
V_52 = F_25 ;
V_53 = F_27 ;
V_54 = F_26 ;
F_33 ( & V_43 . V_14 , F_4 , F_8 ,
V_43 . V_13 , 1 ) ;
F_50 ( & V_43 . V_14 ) ;
}
