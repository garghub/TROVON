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
return V_17 ;
V_15 = F_19 ( V_18 , V_14 ) ;
if ( F_20 ( V_15 != V_17 ) ) {
F_21 ( V_14 ) ;
return V_15 ;
}
F_22 ( V_14 ) ;
F_5 ( V_2 ) ;
return V_17 ;
}
static void F_23 ( int V_1 , unsigned long V_19 )
{
F_24 ( V_1 , 1 ) ;
#ifdef F_25
if ( F_26 ( V_20 ) &&
( F_27 ( V_1 , F_28 ( F_2 () ) ) ) )
F_29 ( V_1 , V_19 ) ;
else
#endif
F_9 ( V_1 , V_21 ) ;
}
void F_30 ( int V_1 )
{
F_9 ( V_1 , V_21 ) ;
}
static T_2 F_31 ( int V_15 , void * V_22 )
{
int V_1 = F_2 () ;
F_24 ( V_1 , 0 ) ;
F_9 ( V_1 , 0xff ) ;
return F_32 () ;
}
static int T_3 F_33 ( int V_23 , unsigned long V_24 ,
unsigned long V_25 )
{
char * V_26 ;
int V_27 , V_1 = - 1 ;
F_34 (i) {
if ( ! F_35 ( V_27 ) )
continue;
if ( V_23 == F_36 ( V_27 ) ) {
V_1 = V_27 ;
break;
}
}
if ( V_1 == - 1 )
return 0 ;
V_26 = F_37 ( V_28 , L_1 ,
V_1 , V_23 ) ;
if ( ! F_38 ( V_24 , V_25 , V_26 ) ) {
F_39 ( L_2
L_3 ,
V_1 , V_23 ) ;
return - V_29 ;
}
V_3 [ V_1 ] = F_40 ( V_24 , V_25 ) ;
F_41 ( V_1 , V_24 ) ;
if ( ! V_3 [ V_1 ] ) {
F_39 ( L_4
L_5 ,
V_1 , V_23 , V_24 ) ;
F_42 ( V_24 , V_25 ) ;
return - V_30 ;
}
return 0 ;
}
static int T_3 F_43 ( struct V_31 * V_32 ,
unsigned int * V_33 )
{
unsigned int V_34 ;
const T_4 * V_35 ;
int V_27 ;
int V_36 ;
int V_37 = 0 ;
V_35 = F_44 ( V_32 , L_6 , & V_34 ) ;
F_45 ( ( V_35 == NULL ) || ( V_34 != 2 * sizeof( V_38 ) ) ) ;
if ( V_35 ) {
* V_33 = F_46 ( V_35 , 1 ) ;
if ( V_34 >= 2 * sizeof( V_38 ) )
V_37 = F_46 ( V_35 + 1 , 1 ) ;
}
V_35 = F_44 ( V_32 , L_7 , & V_34 ) ;
if ( ! V_35 ) {
F_47 ( L_8 ) ;
return - 1 ;
}
V_36 = ( F_48 ( V_32 ) + F_49 ( V_32 ) ) * 4 ;
if ( ( ( V_34 % V_36 ) != 0 )
|| ( V_37 && ( V_37 != ( V_34 / V_36 ) ) ) ) {
F_47 ( L_9 ,
V_34 / V_36 , V_37 ) ;
return - 1 ;
}
for ( V_27 = 0 ; V_27 < ( V_34 / V_36 ) ; V_27 ++ ) {
struct V_39 V_40 ;
int V_41 ;
V_41 = F_50 ( V_32 , V_27 , & V_40 ) ;
if ( V_41 ) {
F_47 ( L_10
L_11 , * V_33 , V_41 ) ;
return - 1 ;
}
if ( F_33 ( * V_33 , V_40 . V_42 , F_51 ( & V_40 ) ) )
return - 1 ;
( * V_33 ) ++ ;
}
return 0 ;
}
int T_3 F_52 ( void )
{
struct V_31 * V_32 ;
V_38 V_33 = 0 ;
int V_43 = 0 ;
F_53 (np, NULL, L_12 )
if ( F_43 ( V_32 , & V_33 ) == 0 )
V_43 = 1 ;
if ( ! V_43 ) {
F_54 (np,
L_13 ) {
if ( F_43 ( V_32 , & V_33 ) == 0 )
V_43 = 1 ;
}
}
if ( V_43 == 0 )
return - V_44 ;
V_45 = & V_46 ;
return 0 ;
}
