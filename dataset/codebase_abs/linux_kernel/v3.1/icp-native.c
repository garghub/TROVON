static inline unsigned int F_1 ( void )
{
int V_1 = F_2 () ;
return F_3 ( & V_2 [ V_1 ] -> V_3 . V_4 ) ;
}
static inline void F_4 ( unsigned int V_5 )
{
int V_1 = F_2 () ;
F_5 ( & V_2 [ V_1 ] -> V_3 . V_4 , V_5 ) ;
}
static inline void F_6 ( T_1 V_5 )
{
int V_1 = F_2 () ;
F_7 ( & V_2 [ V_1 ] -> V_3 . V_6 [ 0 ] , V_5 ) ;
}
static inline void F_8 ( int V_7 , T_1 V_5 )
{
F_7 ( & V_2 [ V_7 ] -> V_8 . V_6 [ 0 ] , V_5 ) ;
}
static void F_9 ( unsigned char V_9 )
{
F_10 ( V_9 ) ;
F_6 ( V_9 ) ;
F_11 () ;
}
static void F_12 ( struct V_10 * V_11 )
{
unsigned int V_12 = ( unsigned int ) F_13 ( V_11 ) ;
F_11 () ;
F_4 ( ( F_14 () << 24 ) | V_12 ) ;
}
static void F_15 ( void )
{
int V_1 = F_2 () ;
F_8 ( V_1 , 0xff ) ;
}
static void F_16 ( void )
{
F_4 ( ( 0x00 << 24 ) | V_13 ) ;
}
static unsigned int F_17 ( void )
{
unsigned int V_3 = F_1 () ;
unsigned int V_14 = V_3 & 0x00ffffff ;
unsigned int V_15 ;
if ( V_14 == V_16 )
return V_17 ;
V_15 = F_18 ( V_18 , V_14 ) ;
if ( F_19 ( V_15 != V_17 ) ) {
F_20 ( V_14 ) ;
return V_15 ;
}
F_21 ( V_14 ) ;
F_4 ( V_3 ) ;
return V_17 ;
}
static void F_22 ( int V_1 , unsigned long V_19 )
{
F_8 ( V_1 , V_20 ) ;
}
void F_23 ( int V_1 )
{
F_8 ( V_1 , V_20 ) ;
}
static T_2 F_24 ( int V_15 , void * V_21 )
{
int V_1 = F_2 () ;
F_8 ( V_1 , 0xff ) ;
return F_25 () ;
}
static int T_3 F_26 ( int V_22 , unsigned long V_23 ,
unsigned long V_24 )
{
char * V_25 ;
int V_26 , V_1 = - 1 ;
F_27 (i) {
if ( ! F_28 ( V_26 ) )
continue;
if ( V_22 == F_29 ( V_26 ) ) {
V_1 = V_26 ;
break;
}
}
if ( V_1 == - 1 )
return 0 ;
V_25 = F_30 ( V_27 , L_1 ,
V_1 , V_22 ) ;
if ( ! F_31 ( V_23 , V_24 , V_25 ) ) {
F_32 ( L_2
L_3 ,
V_1 , V_22 ) ;
return - V_28 ;
}
V_2 [ V_1 ] = F_33 ( V_23 , V_24 ) ;
F_34 ( V_1 , V_23 ) ;
if ( ! V_2 [ V_1 ] ) {
F_32 ( L_4
L_5 ,
V_1 , V_22 , V_23 ) ;
F_35 ( V_23 , V_24 ) ;
return - V_29 ;
}
return 0 ;
}
static int T_3 F_36 ( struct V_30 * V_31 ,
unsigned int * V_32 )
{
unsigned int V_33 ;
const T_4 * V_34 ;
int V_26 ;
int V_35 ;
int V_36 = 0 ;
V_34 = F_37 ( V_31 , L_6 , & V_33 ) ;
F_38 ( ( V_34 == NULL ) || ( V_33 != 2 * sizeof( T_4 ) ) ) ;
if ( V_34 ) {
* V_32 = F_39 ( V_34 , 1 ) ;
if ( V_33 >= 2 * sizeof( T_4 ) )
V_36 = F_39 ( V_34 + 1 , 1 ) ;
}
V_34 = F_37 ( V_31 , L_7 , & V_33 ) ;
if ( ! V_34 ) {
F_40 ( L_8 ) ;
return - 1 ;
}
V_35 = ( F_41 ( V_31 ) + F_42 ( V_31 ) ) * 4 ;
if ( ( ( V_33 % V_35 ) != 0 )
|| ( V_36 && ( V_36 != ( V_33 / V_35 ) ) ) ) {
F_40 ( L_9 ,
V_33 / V_35 , V_36 ) ;
return - 1 ;
}
for ( V_26 = 0 ; V_26 < ( V_33 / V_35 ) ; V_26 ++ ) {
struct V_37 V_38 ;
int V_39 ;
V_39 = F_43 ( V_31 , V_26 , & V_38 ) ;
if ( V_39 ) {
F_40 ( L_10
L_11 , * V_32 , V_39 ) ;
return - 1 ;
}
if ( F_26 ( * V_32 , V_38 . V_40 , F_44 ( & V_38 ) ) )
return - 1 ;
( * V_32 ) ++ ;
}
return 0 ;
}
int F_45 ( void )
{
struct V_30 * V_31 ;
T_4 V_32 = 0 ;
int V_41 = 0 ;
F_46 (np, NULL, L_12 )
if ( F_36 ( V_31 , & V_32 ) == 0 )
V_41 = 1 ;
if ( ! V_41 ) {
F_47 (np,
L_13 ) {
if ( F_36 ( V_31 , & V_32 ) == 0 )
V_41 = 1 ;
}
}
if ( V_41 == 0 )
return - V_42 ;
V_43 = & V_44 ;
return 0 ;
}
