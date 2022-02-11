static int F_1 ( T_1 V_1 , char * V_2 , int V_3 )
{
struct V_4 * V_5 = V_6 [ V_1 ] ;
if ( F_2 ( ! V_5 ) )
return - V_7 ;
return F_3 ( & V_5 -> V_8 , V_2 , V_3 ) ;
}
static int F_4 ( T_1 V_1 , const char * V_2 , int V_3 )
{
struct V_4 * V_5 = V_6 [ V_1 ] ;
if ( F_2 ( ! V_5 ) )
return - V_7 ;
return F_5 ( & V_5 -> V_8 , V_2 , V_3 ) ;
}
static int F_6 ( struct V_9 * V_10 , int V_11 )
{
struct V_4 * V_5 = V_6 [ V_10 -> V_1 ] ;
int V_12 ;
F_7 ( L_1 , V_10 -> V_1 ) ;
V_12 = F_8 ( V_10 , V_11 ) ;
if ( V_12 )
return V_12 ;
return F_9 ( & V_5 -> V_8 , V_10 ) ;
}
static void F_10 ( struct V_9 * V_10 , int V_11 )
{
struct V_4 * V_5 = V_6 [ V_10 -> V_1 ] ;
F_7 ( L_2 , V_10 -> V_1 ) ;
F_11 ( & V_5 -> V_8 , V_10 ) ;
F_12 ( V_10 , V_11 ) ;
}
void F_13 ( struct V_9 * V_10 , int V_11 )
{
struct V_4 * V_5 = V_6 [ V_10 -> V_1 ] ;
F_7 ( L_3 , V_10 -> V_1 ) ;
F_11 ( & V_5 -> V_8 , V_10 ) ;
F_14 ( V_10 , V_11 ) ;
}
static int F_15 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_6 [ V_10 -> V_1 ] ;
if ( ! V_5 )
return - V_13 ;
return V_5 -> V_8 . V_14 ;
}
static int F_16 ( struct V_9 * V_10 , unsigned int V_15 ,
unsigned int V_16 )
{
struct V_4 * V_5 = V_6 [ V_10 -> V_1 ] ;
F_7 ( L_4 ,
V_10 -> V_1 , V_15 , V_16 ) ;
if ( V_15 & V_17 )
F_17 ( & V_5 -> V_8 , 1 ) ;
else if ( V_16 & V_17 )
F_17 ( & V_5 -> V_8 , 0 ) ;
return 0 ;
}
static int F_18 ( struct V_18 * V_19 )
{
const struct V_20 * V_21 ;
struct V_9 * V_10 ;
struct V_4 * V_5 ;
T_2 V_22 ;
unsigned int V_23 , V_24 = 0 ;
const T_3 * V_25 ;
if ( F_19 ( V_19 -> V_19 . V_26 , L_5 ) ) {
V_22 = V_27 ;
V_21 = & V_28 ;
} else if ( F_19 ( V_19 -> V_19 . V_26 ,
L_6 ) ) {
V_22 = V_29 ;
V_21 = & V_30 ;
} else {
F_20 ( L_7 ,
V_19 -> V_19 . V_26 -> V_31 ) ;
return - V_32 ;
}
V_25 = F_21 ( V_19 -> V_19 . V_26 , L_8 , NULL ) ;
V_23 = V_25 ? F_22 ( V_25 ) : 0 ;
if ( V_6 [ V_23 ] == & V_33 ) {
V_5 = V_6 [ V_23 ] ;
V_24 = 1 ;
} else if ( V_6 [ V_23 ] == NULL ) {
V_5 = F_23 ( sizeof( struct V_4 ) , V_34 ) ;
if ( ! V_5 )
return - V_35 ;
V_5 -> V_22 = V_22 ;
V_6 [ V_23 ] = V_5 ;
if ( V_22 == V_29 )
F_24 ( & V_5 -> V_8 , V_36 , V_37 ,
V_23 , 0 ) ;
F_25 ( V_23 , V_23 , V_21 ) ;
} else {
F_20 ( L_9 ,
V_19 -> V_19 . V_26 -> V_31 , V_23 ) ;
return - V_32 ;
}
F_26 ( L_10 , V_23 ,
V_22 == V_27 ? L_11 : L_12 ,
V_19 -> V_19 . V_26 -> V_31 ,
V_24 ? L_13 : L_14 ) ;
V_10 = F_27 ( V_23 , 0 , V_21 , V_38 ) ;
if ( F_28 ( V_10 ) )
return F_29 ( V_10 ) ;
F_30 ( & V_19 -> V_19 , V_10 ) ;
return 0 ;
}
static int F_31 ( struct V_18 * V_19 )
{
struct V_9 * V_10 = F_32 ( & V_19 -> V_19 ) ;
int V_12 , V_23 ;
V_23 = V_10 -> V_1 ;
V_12 = F_33 ( V_10 ) ;
if ( V_12 == 0 ) {
if ( V_6 [ V_23 ] != & V_33 )
F_34 ( V_6 [ V_23 ] ) ;
V_6 [ V_23 ] = NULL ;
}
return V_12 ;
}
static int T_4 F_35 ( void )
{
if ( ! F_36 ( V_39 ) )
return - V_7 ;
return F_37 ( & V_40 ) ;
}
static void T_5 F_38 ( void )
{
F_39 ( & V_40 ) ;
}
static void F_40 ( char V_41 )
{
unsigned int V_23 = V_42 ;
int V_3 = - 1 ;
if ( V_41 == '\n' )
F_40 ( '\r' ) ;
do {
switch( V_33 . V_22 ) {
case V_27 :
V_3 = V_37 ( V_23 , & V_41 , 1 ) ;
break;
case V_29 :
V_3 = F_4 ( V_23 , & V_41 , 1 ) ;
break;
}
} while( V_3 == 0 || V_3 == - V_43 );
}
static int F_41 ( void )
{
unsigned int V_23 = V_42 ;
int V_12 = 0 ;
char V_41 ;
switch( V_33 . V_22 ) {
case V_27 :
V_12 = V_36 ( V_23 , & V_41 , 1 ) ;
break;
case V_29 :
V_12 = F_1 ( V_23 , & V_41 , 1 ) ;
break;
}
if ( ! V_12 )
return - 1 ;
return V_41 ;
}
static int F_42 ( void )
{
int V_44 ;
for (; ; ) {
V_44 = F_41 () ;
if ( V_44 == - 1 ) {
volatile unsigned long V_45 ;
for ( V_45 = 0 ; V_45 < 2000000 ; V_45 ++ )
;
} else {
return V_44 ;
}
}
}
static void F_43 ( void )
{
V_46 = F_40 ;
V_47 = F_42 ;
V_48 = F_41 ;
V_49 = 0x200 ;
}
void T_4 F_44 ( void )
{
struct V_50 * V_51 = NULL ;
const T_3 * V_23 ;
const char * V_52 = NULL ;
const struct V_20 * V_21 ;
T_6 V_53 ;
if ( V_54 )
V_52 = F_21 ( V_54 , L_15 , NULL ) ;
if ( V_52 ) {
V_51 = F_45 ( V_52 ) ;
if ( ! V_51 ) {
F_20 ( L_16 ) ;
return;
}
} else {
struct V_50 * V_55 , * V_56 ;
V_55 = F_45 ( L_17 ) ;
if ( V_55 )
F_7 ( L_18 ) ;
if ( ! V_55 ) {
V_55 = F_45 ( L_19 ) ;
if ( V_55 )
F_7 ( L_20
L_21 ) ;
}
if ( ! V_55 )
return;
F_46 (opal, np) {
if ( ! strcmp ( V_56 -> V_52 , L_22 ) ) {
V_51 = V_56 ;
break;
}
}
F_47 ( V_55 ) ;
}
if ( ! V_51 )
return;
V_23 = F_21 ( V_51 , L_8 , NULL ) ;
V_53 = V_23 ? F_22 ( V_23 ) : 0 ;
if ( V_53 >= V_57 )
return;
V_6 [ V_53 ] = & V_33 ;
if ( F_19 ( V_51 , L_5 ) ) {
V_33 . V_22 = V_27 ;
V_21 = & V_28 ;
F_7 ( L_23 ) ;
}
else if ( F_19 ( V_51 , L_6 ) ) {
V_33 . V_22 = V_29 ;
V_21 = & V_30 ;
F_24 ( & V_33 . V_8 , V_36 ,
V_37 , V_53 , 1 ) ;
F_48 ( & V_33 . V_8 ) ;
F_7 ( L_24 ) ;
} else
goto V_58;
V_42 = V_53 ;
F_43 () ;
F_49 ( L_25 , V_53 , NULL ) ;
F_25 ( V_53 , V_53 , V_21 ) ;
V_58:
F_47 ( V_51 ) ;
}
void T_4 F_50 ( void )
{
T_6 V_53 = V_59 ;
V_6 [ V_53 ] = & V_33 ;
V_33 . V_22 = V_27 ;
V_42 = V_53 ;
F_43 () ;
}
void T_4 F_51 ( void )
{
T_6 V_53 = V_59 ;
V_6 [ V_53 ] = & V_33 ;
V_42 = V_53 ;
F_43 () ;
F_24 ( & V_33 . V_8 , V_36 , V_37 ,
V_53 , 1 ) ;
F_48 ( & V_33 . V_8 ) ;
}
