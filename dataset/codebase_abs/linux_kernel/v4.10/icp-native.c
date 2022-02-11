static inline unsigned int F_1 ( void )
{
int V_1 = F_2 () ;
unsigned int V_2 ;
V_2 = F_3 () ;
if ( V_2 )
return V_2 ;
return F_4 ( & V_3 [ V_1 ] -> V_2 . V_4 ) ;
}
static inline void F_5 ( unsigned int V_5 )
{
int V_1 = F_2 () ;
F_6 ( & V_3 [ V_1 ] -> V_2 . V_4 , V_5 ) ;
}
static inline void F_7 ( T_1 V_5 )
{
int V_1 = F_2 () ;
F_8 ( & V_3 [ V_1 ] -> V_2 . V_6 [ 0 ] , V_5 ) ;
}
static inline void F_9 ( int V_7 , T_1 V_5 )
{
F_8 ( & V_3 [ V_7 ] -> V_8 . V_6 [ 0 ] , V_5 ) ;
}
static void F_10 ( unsigned char V_9 )
{
F_11 ( V_9 ) ;
F_7 ( V_9 ) ;
F_12 () ;
}
void F_13 ( struct V_10 * V_11 )
{
unsigned int V_12 = ( unsigned int ) F_14 ( V_11 ) ;
F_12 () ;
F_5 ( ( F_15 () << 24 ) | V_12 ) ;
}
static void F_16 ( void )
{
int V_1 = F_2 () ;
F_9 ( V_1 , 0xff ) ;
}
static void F_17 ( void )
{
F_5 ( ( 0x00 << 24 ) | V_13 ) ;
}
static unsigned int F_18 ( void )
{
unsigned int V_2 = F_1 () ;
unsigned int V_14 = V_2 & 0x00ffffff ;
unsigned int V_15 ;
if ( V_14 == V_16 )
return 0 ;
V_15 = F_19 ( V_17 , V_14 ) ;
if ( F_20 ( V_15 ) ) {
F_21 ( V_14 ) ;
return V_15 ;
}
F_22 ( V_14 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static void F_23 ( int V_1 , unsigned long V_18 )
{
F_24 ( V_1 , 1 ) ;
#ifdef F_25
if ( F_26 ( V_19 ) ) {
if ( F_27 ( V_1 , F_28 ( F_29 () ) ) ) {
F_30 ( V_1 , V_18 ) ;
F_31 () ;
return;
}
F_31 () ;
}
#endif
F_9 ( V_1 , V_20 ) ;
}
void F_32 ( int V_1 )
{
unsigned long V_21 ;
V_21 = V_22 [ V_1 ] . V_23 . V_21 ;
F_33 ( ( T_1 * ) ( V_21 + V_24 ) , V_20 ) ;
}
void F_34 ( void )
{
unsigned int V_2 = F_1 () ;
unsigned int V_14 = V_2 & 0x00ffffff ;
if ( V_14 == V_16 )
return;
if ( V_14 == V_13 ) {
int V_1 = F_2 () ;
F_24 ( V_1 , 0 ) ;
F_9 ( V_1 , 0xff ) ;
} else {
F_35 ( L_1 ,
V_14 ) ;
F_22 ( V_14 ) ;
}
F_5 ( V_2 ) ;
}
void F_36 ( int V_1 )
{
F_9 ( V_1 , V_20 ) ;
}
static T_2 F_37 ( int V_15 , void * V_25 )
{
int V_1 = F_2 () ;
F_24 ( V_1 , 0 ) ;
F_9 ( V_1 , 0xff ) ;
return F_38 () ;
}
static int T_3 F_39 ( int V_26 , unsigned long V_27 ,
unsigned long V_28 )
{
char * V_29 ;
int V_30 , V_1 = - 1 ;
F_40 (i) {
if ( ! F_41 ( V_30 ) )
continue;
if ( V_26 == F_42 ( V_30 ) ) {
V_1 = V_30 ;
break;
}
}
if ( V_1 == - 1 )
return 0 ;
V_29 = F_43 ( V_31 , L_2 ,
V_1 , V_26 ) ;
if ( ! F_44 ( V_27 , V_28 , V_29 ) ) {
F_45 ( L_3
L_4 ,
V_1 , V_26 ) ;
return - V_32 ;
}
V_3 [ V_1 ] = F_46 ( V_27 , V_28 ) ;
F_47 ( V_1 , V_27 ) ;
if ( ! V_3 [ V_1 ] ) {
F_45 ( L_5
L_6 ,
V_1 , V_26 , V_27 ) ;
F_48 ( V_27 , V_28 ) ;
return - V_33 ;
}
return 0 ;
}
static int T_3 F_49 ( struct V_34 * V_35 ,
unsigned int * V_36 )
{
unsigned int V_37 ;
const T_4 * V_38 ;
int V_30 ;
int V_39 ;
int V_40 = 0 ;
V_38 = F_50 ( V_35 , L_7 , & V_37 ) ;
F_51 ( ( V_38 == NULL ) || ( V_37 != 2 * sizeof( V_41 ) ) ) ;
if ( V_38 ) {
* V_36 = F_52 ( V_38 , 1 ) ;
if ( V_37 >= 2 * sizeof( V_41 ) )
V_40 = F_52 ( V_38 + 1 , 1 ) ;
}
V_38 = F_50 ( V_35 , L_8 , & V_37 ) ;
if ( ! V_38 ) {
F_35 ( L_9 ) ;
return - 1 ;
}
V_39 = ( F_53 ( V_35 ) + F_54 ( V_35 ) ) * 4 ;
if ( ( ( V_37 % V_39 ) != 0 )
|| ( V_40 && ( V_40 != ( V_37 / V_39 ) ) ) ) {
F_35 ( L_10 ,
V_37 / V_39 , V_40 ) ;
return - 1 ;
}
for ( V_30 = 0 ; V_30 < ( V_37 / V_39 ) ; V_30 ++ ) {
struct V_42 V_43 ;
int V_44 ;
V_44 = F_55 ( V_35 , V_30 , & V_43 ) ;
if ( V_44 ) {
F_35 ( L_11
L_12 , * V_36 , V_44 ) ;
return - 1 ;
}
if ( F_39 ( * V_36 , V_43 . V_45 , F_56 ( & V_43 ) ) )
return - 1 ;
( * V_36 ) ++ ;
}
return 0 ;
}
int T_3 F_57 ( void )
{
struct V_34 * V_35 ;
V_41 V_36 = 0 ;
int V_46 = 0 ;
F_58 (np, NULL, L_13 )
if ( F_49 ( V_35 , & V_36 ) == 0 )
V_46 = 1 ;
if ( ! V_46 ) {
F_59 (np,
L_14 ) {
if ( F_49 ( V_35 , & V_36 ) == 0 )
V_46 = 1 ;
}
}
if ( V_46 == 0 )
return - V_47 ;
V_48 = & V_49 ;
return 0 ;
}
