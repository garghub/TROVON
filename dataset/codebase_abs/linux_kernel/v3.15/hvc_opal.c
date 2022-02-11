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
static int F_18 ( struct V_18 * V_19 ,
unsigned long V_20 , void * V_21 )
{
if ( V_20 & V_22 )
F_19 () ;
return 0 ;
}
static int F_20 ( struct V_23 * V_24 )
{
const struct V_25 * V_26 ;
struct V_9 * V_10 ;
struct V_4 * V_5 ;
T_2 V_27 ;
unsigned int V_28 , V_29 = 0 ;
const T_3 * V_30 ;
if ( F_21 ( V_24 -> V_24 . V_31 , L_5 ) ) {
V_27 = V_32 ;
V_26 = & V_33 ;
} else if ( F_21 ( V_24 -> V_24 . V_31 ,
L_6 ) ) {
V_27 = V_34 ;
V_26 = & V_35 ;
} else {
F_22 ( L_7 ,
V_24 -> V_24 . V_31 -> V_36 ) ;
return - V_37 ;
}
V_30 = F_23 ( V_24 -> V_24 . V_31 , L_8 , NULL ) ;
V_28 = V_30 ? F_24 ( V_30 ) : 0 ;
if ( V_6 [ V_28 ] == & V_38 ) {
V_5 = V_6 [ V_28 ] ;
V_29 = 1 ;
} else if ( V_6 [ V_28 ] == NULL ) {
V_5 = F_25 ( sizeof( struct V_4 ) , V_39 ) ;
if ( ! V_5 )
return - V_40 ;
V_5 -> V_27 = V_27 ;
V_6 [ V_28 ] = V_5 ;
if ( V_27 == V_34 )
F_26 ( & V_5 -> V_8 , V_41 , V_42 ,
V_28 , 0 ) ;
F_27 ( V_28 , V_28 , V_26 ) ;
} else {
F_22 ( L_9 ,
V_24 -> V_24 . V_31 -> V_36 , V_28 ) ;
return - V_37 ;
}
F_28 ( L_10 , V_28 ,
V_27 == V_32 ? L_11 : L_12 ,
V_24 -> V_24 . V_31 -> V_36 ,
V_29 ? L_13 : L_14 ) ;
V_10 = F_29 ( V_28 , 0 , V_26 , V_43 ) ;
if ( F_30 ( V_10 ) )
return F_31 ( V_10 ) ;
F_32 ( & V_24 -> V_24 , V_10 ) ;
if ( ! V_44 ) {
F_33 ( & V_45 ) ;
V_44 = true ;
}
return 0 ;
}
static int F_34 ( struct V_23 * V_24 )
{
struct V_9 * V_10 = F_35 ( & V_24 -> V_24 ) ;
int V_12 , V_28 ;
V_28 = V_10 -> V_1 ;
V_12 = F_36 ( V_10 ) ;
if ( V_12 == 0 ) {
if ( V_6 [ V_28 ] != & V_38 )
F_37 ( V_6 [ V_28 ] ) ;
V_6 [ V_28 ] = NULL ;
}
return V_12 ;
}
static int T_4 F_38 ( void )
{
if ( ! F_39 ( V_46 ) )
return - V_7 ;
return F_40 ( & V_47 ) ;
}
static void F_41 ( char V_48 )
{
unsigned int V_28 = V_49 ;
int V_3 = - 1 ;
if ( V_48 == '\n' )
F_41 ( '\r' ) ;
do {
switch( V_38 . V_27 ) {
case V_32 :
V_3 = V_42 ( V_28 , & V_48 , 1 ) ;
break;
case V_34 :
V_3 = F_4 ( V_28 , & V_48 , 1 ) ;
break;
}
} while( V_3 == 0 || V_3 == - V_50 );
}
static int F_42 ( void )
{
unsigned int V_28 = V_49 ;
int V_12 = 0 ;
char V_48 ;
switch( V_38 . V_27 ) {
case V_32 :
V_12 = V_41 ( V_28 , & V_48 , 1 ) ;
break;
case V_34 :
V_12 = F_1 ( V_28 , & V_48 , 1 ) ;
break;
}
if ( ! V_12 )
return - 1 ;
return V_48 ;
}
static int F_43 ( void )
{
int V_51 ;
for (; ; ) {
V_51 = F_42 () ;
if ( V_51 == - 1 ) {
volatile unsigned long V_52 ;
for ( V_52 = 0 ; V_52 < 2000000 ; V_52 ++ )
;
} else {
return V_51 ;
}
}
}
static void F_44 ( void )
{
V_53 = F_41 ;
V_54 = F_43 ;
V_55 = F_42 ;
V_56 = 0x200 ;
}
void T_4 F_45 ( void )
{
struct V_57 * V_58 = NULL ;
const T_3 * V_28 ;
const char * V_59 = NULL ;
const struct V_25 * V_26 ;
T_5 V_60 ;
if ( V_61 )
V_59 = F_23 ( V_61 , L_15 , NULL ) ;
if ( V_59 ) {
V_58 = F_46 ( V_59 ) ;
if ( ! V_58 ) {
F_22 ( L_16 ) ;
return;
}
} else {
struct V_57 * V_62 , * V_63 ;
V_62 = F_46 ( L_17 ) ;
if ( V_62 )
F_7 ( L_18 ) ;
if ( ! V_62 ) {
V_62 = F_46 ( L_19 ) ;
if ( V_62 )
F_7 ( L_20
L_21 ) ;
}
if ( ! V_62 )
return;
F_47 (opal, np) {
if ( ! strcmp ( V_63 -> V_59 , L_22 ) ) {
V_58 = V_63 ;
break;
}
}
F_48 ( V_62 ) ;
}
if ( ! V_58 )
return;
V_28 = F_23 ( V_58 , L_8 , NULL ) ;
V_60 = V_28 ? F_24 ( V_28 ) : 0 ;
if ( V_60 >= V_64 )
return;
V_6 [ V_60 ] = & V_38 ;
if ( F_21 ( V_58 , L_5 ) ) {
V_38 . V_27 = V_32 ;
V_26 = & V_33 ;
F_7 ( L_23 ) ;
}
else if ( F_21 ( V_58 , L_6 ) ) {
V_38 . V_27 = V_34 ;
V_26 = & V_35 ;
F_26 ( & V_38 . V_8 , V_41 ,
V_42 , V_60 , 1 ) ;
F_49 ( & V_38 . V_8 ) ;
F_7 ( L_24 ) ;
} else
goto V_65;
V_49 = V_60 ;
F_44 () ;
F_50 ( L_25 , V_60 , NULL ) ;
F_27 ( V_60 , V_60 , V_26 ) ;
V_65:
F_48 ( V_58 ) ;
}
void T_4 F_51 ( void )
{
T_5 V_60 = V_66 ;
V_6 [ V_60 ] = & V_38 ;
V_38 . V_27 = V_32 ;
V_49 = V_60 ;
F_44 () ;
}
void T_4 F_52 ( void )
{
T_5 V_60 = V_66 ;
V_6 [ V_60 ] = & V_38 ;
V_49 = V_60 ;
F_44 () ;
F_26 ( & V_38 . V_8 , V_41 , V_42 ,
V_60 , 1 ) ;
F_49 ( & V_38 . V_8 ) ;
}
