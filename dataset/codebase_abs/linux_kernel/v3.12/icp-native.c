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
F_9 ( V_1 , V_20 ) ;
}
void F_25 ( int V_1 )
{
F_9 ( V_1 , V_20 ) ;
}
static T_2 F_26 ( int V_15 , void * V_21 )
{
int V_1 = F_2 () ;
F_24 ( V_1 , 0 ) ;
F_9 ( V_1 , 0xff ) ;
return F_27 () ;
}
static int T_3 F_28 ( int V_22 , unsigned long V_23 ,
unsigned long V_24 )
{
char * V_25 ;
int V_26 , V_1 = - 1 ;
F_29 (i) {
if ( ! F_30 ( V_26 ) )
continue;
if ( V_22 == F_31 ( V_26 ) ) {
V_1 = V_26 ;
break;
}
}
if ( V_1 == - 1 )
return 0 ;
V_25 = F_32 ( V_27 , L_1 ,
V_1 , V_22 ) ;
if ( ! F_33 ( V_23 , V_24 , V_25 ) ) {
F_34 ( L_2
L_3 ,
V_1 , V_22 ) ;
return - V_28 ;
}
V_3 [ V_1 ] = F_35 ( V_23 , V_24 ) ;
F_36 ( V_1 , V_23 ) ;
if ( ! V_3 [ V_1 ] ) {
F_34 ( L_4
L_5 ,
V_1 , V_22 , V_23 ) ;
F_37 ( V_23 , V_24 ) ;
return - V_29 ;
}
return 0 ;
}
static int T_3 F_38 ( struct V_30 * V_31 ,
unsigned int * V_32 )
{
unsigned int V_33 ;
const T_4 * V_34 ;
int V_26 ;
int V_35 ;
int V_36 = 0 ;
V_34 = F_39 ( V_31 , L_6 , & V_33 ) ;
F_40 ( ( V_34 == NULL ) || ( V_33 != 2 * sizeof( V_37 ) ) ) ;
if ( V_34 ) {
* V_32 = F_41 ( V_34 , 1 ) ;
if ( V_33 >= 2 * sizeof( V_37 ) )
V_36 = F_41 ( V_34 + 1 , 1 ) ;
}
V_34 = F_39 ( V_31 , L_7 , & V_33 ) ;
if ( ! V_34 ) {
F_42 ( L_8 ) ;
return - 1 ;
}
V_35 = ( F_43 ( V_31 ) + F_44 ( V_31 ) ) * 4 ;
if ( ( ( V_33 % V_35 ) != 0 )
|| ( V_36 && ( V_36 != ( V_33 / V_35 ) ) ) ) {
F_42 ( L_9 ,
V_33 / V_35 , V_36 ) ;
return - 1 ;
}
for ( V_26 = 0 ; V_26 < ( V_33 / V_35 ) ; V_26 ++ ) {
struct V_38 V_39 ;
int V_40 ;
V_40 = F_45 ( V_31 , V_26 , & V_39 ) ;
if ( V_40 ) {
F_42 ( L_10
L_11 , * V_32 , V_40 ) ;
return - 1 ;
}
if ( F_28 ( * V_32 , V_39 . V_41 , F_46 ( & V_39 ) ) )
return - 1 ;
( * V_32 ) ++ ;
}
return 0 ;
}
int T_3 F_47 ( void )
{
struct V_30 * V_31 ;
V_37 V_32 = 0 ;
int V_42 = 0 ;
F_48 (np, NULL, L_12 )
if ( F_38 ( V_31 , & V_32 ) == 0 )
V_42 = 1 ;
if ( ! V_42 ) {
F_49 (np,
L_13 ) {
if ( F_38 ( V_31 , & V_32 ) == 0 )
V_42 = 1 ;
}
}
if ( V_42 == 0 )
return - V_43 ;
V_44 = & V_45 ;
return 0 ;
}
