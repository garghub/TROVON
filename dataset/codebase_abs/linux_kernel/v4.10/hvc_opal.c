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
unsigned int V_23 , V_24 , V_25 = 0 ;
const T_3 * V_26 ;
if ( F_19 ( V_19 -> V_19 . V_27 , L_5 ) ) {
V_22 = V_28 ;
V_21 = & V_29 ;
} else if ( F_19 ( V_19 -> V_19 . V_27 ,
L_6 ) ) {
V_22 = V_30 ;
V_21 = & V_31 ;
} else {
F_20 ( L_7 ,
V_19 -> V_19 . V_27 -> V_32 ) ;
return - V_33 ;
}
V_26 = F_21 ( V_19 -> V_19 . V_27 , L_8 , NULL ) ;
V_23 = V_26 ? F_22 ( V_26 ) : 0 ;
if ( V_6 [ V_23 ] == & V_34 ) {
V_5 = V_6 [ V_23 ] ;
V_25 = 1 ;
} else if ( V_6 [ V_23 ] == NULL ) {
V_5 = F_23 ( sizeof( struct V_4 ) , V_35 ) ;
if ( ! V_5 )
return - V_36 ;
V_5 -> V_22 = V_22 ;
V_6 [ V_23 ] = V_5 ;
if ( V_22 == V_30 )
F_24 ( & V_5 -> V_8 , V_37 , V_38 ,
V_23 , 0 ) ;
F_25 ( V_23 , V_23 , V_21 ) ;
} else {
F_20 ( L_9 ,
V_19 -> V_19 . V_27 -> V_32 , V_23 ) ;
return - V_33 ;
}
F_26 ( L_10 , V_23 ,
V_22 == V_28 ? L_11 : L_12 ,
V_19 -> V_19 . V_27 -> V_32 ,
V_25 ? L_13 : L_14 ) ;
V_24 = F_27 ( V_19 -> V_19 . V_27 , 0 ) ;
if ( ! V_24 ) {
F_26 ( L_15 ,
V_23 ) ;
V_24 = F_28 ( F_29 ( V_39 ) ) ;
}
if ( ! V_24 ) {
F_20 ( L_16 ,
V_19 -> V_19 . V_27 -> V_32 ) ;
return V_24 ;
}
V_10 = F_30 ( V_23 , V_24 , V_21 , V_40 ) ;
if ( F_31 ( V_10 ) )
return F_32 ( V_10 ) ;
V_10 -> V_41 = V_42 ;
F_33 ( & V_19 -> V_19 , V_10 ) ;
return 0 ;
}
static int F_34 ( struct V_18 * V_19 )
{
struct V_9 * V_10 = F_35 ( & V_19 -> V_19 ) ;
int V_12 , V_23 ;
V_23 = V_10 -> V_1 ;
V_12 = F_36 ( V_10 ) ;
if ( V_12 == 0 ) {
if ( V_6 [ V_23 ] != & V_34 )
F_37 ( V_6 [ V_23 ] ) ;
V_6 [ V_23 ] = NULL ;
}
return V_12 ;
}
static int T_4 F_38 ( void )
{
if ( ! F_39 ( V_43 ) )
return - V_7 ;
return F_40 ( & V_44 ) ;
}
static void F_41 ( char V_45 )
{
unsigned int V_23 = V_46 ;
int V_3 = - 1 ;
if ( V_45 == '\n' )
F_41 ( '\r' ) ;
do {
switch( V_34 . V_22 ) {
case V_28 :
V_3 = V_38 ( V_23 , & V_45 , 1 ) ;
break;
case V_30 :
V_3 = F_4 ( V_23 , & V_45 , 1 ) ;
break;
}
} while( V_3 == 0 || V_3 == - V_47 );
}
static int F_42 ( void )
{
unsigned int V_23 = V_46 ;
int V_12 = 0 ;
char V_45 ;
switch( V_34 . V_22 ) {
case V_28 :
V_12 = V_37 ( V_23 , & V_45 , 1 ) ;
break;
case V_30 :
V_12 = F_1 ( V_23 , & V_45 , 1 ) ;
break;
}
if ( ! V_12 )
return - 1 ;
return V_45 ;
}
static int F_43 ( void )
{
int V_48 ;
for (; ; ) {
V_48 = F_42 () ;
if ( V_48 == - 1 ) {
volatile unsigned long V_49 ;
for ( V_49 = 0 ; V_49 < 2000000 ; V_49 ++ )
;
} else {
return V_48 ;
}
}
}
static void F_44 ( void )
{
V_50 = F_41 ;
V_51 = F_43 ;
V_52 = F_42 ;
V_53 = 0x200 ;
}
void T_4 F_45 ( void )
{
struct V_54 * V_55 = F_46 ( V_56 ) ;
const T_3 * V_23 ;
const struct V_20 * V_21 ;
T_5 V_57 ;
if ( ! V_55 ) {
struct V_54 * V_58 , * V_59 ;
V_58 = F_47 ( L_17 ) ;
if ( V_58 )
F_7 ( L_18 ) ;
if ( ! V_58 ) {
V_58 = F_47 ( L_19 ) ;
if ( V_58 )
F_7 ( L_20
L_21 ) ;
}
if ( ! V_58 )
return;
F_48 (opal, np) {
if ( ! strcmp ( V_59 -> V_60 , L_22 ) ) {
V_55 = V_59 ;
break;
}
}
F_49 ( V_58 ) ;
}
if ( ! V_55 )
return;
V_23 = F_21 ( V_55 , L_8 , NULL ) ;
V_57 = V_23 ? F_22 ( V_23 ) : 0 ;
if ( V_57 >= V_61 )
return;
V_6 [ V_57 ] = & V_34 ;
if ( F_19 ( V_55 , L_5 ) ) {
V_34 . V_22 = V_28 ;
V_21 = & V_29 ;
F_7 ( L_23 ) ;
}
else if ( F_19 ( V_55 , L_6 ) ) {
V_34 . V_22 = V_30 ;
V_21 = & V_31 ;
F_24 ( & V_34 . V_8 , V_37 ,
V_38 , V_57 , 1 ) ;
F_50 ( & V_34 . V_8 ) ;
F_7 ( L_24 ) ;
} else
goto V_62;
V_46 = V_57 ;
F_44 () ;
F_51 ( L_25 , V_57 , NULL ) ;
F_25 ( V_57 , V_57 , V_21 ) ;
V_62:
F_49 ( V_55 ) ;
}
void T_4 F_52 ( void )
{
T_5 V_57 = V_63 ;
V_6 [ V_57 ] = & V_34 ;
V_34 . V_22 = V_28 ;
V_46 = V_57 ;
F_44 () ;
}
void T_4 F_53 ( void )
{
T_5 V_57 = V_63 ;
V_6 [ V_57 ] = & V_34 ;
V_46 = V_57 ;
F_44 () ;
F_24 ( & V_34 . V_8 , V_37 , V_38 ,
V_57 , 1 ) ;
F_50 ( & V_34 . V_8 ) ;
}
