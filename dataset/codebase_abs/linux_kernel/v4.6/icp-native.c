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
if ( F_26 ( V_20 ) ) {
if ( F_27 ( V_1 , F_28 ( F_29 () ) ) ) {
F_30 ( V_1 , V_19 ) ;
F_31 () ;
return;
}
F_31 () ;
}
#endif
F_9 ( V_1 , V_21 ) ;
}
void F_32 ( int V_1 )
{
unsigned long V_22 ;
V_22 = V_23 [ V_1 ] . V_24 . V_22 ;
F_33 ( ( T_1 * ) ( V_22 + V_25 ) , V_21 ) ;
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
F_9 ( V_1 , V_21 ) ;
}
static T_2 F_37 ( int V_15 , void * V_26 )
{
int V_1 = F_2 () ;
F_24 ( V_1 , 0 ) ;
F_9 ( V_1 , 0xff ) ;
return F_38 () ;
}
static int T_3 F_39 ( int V_27 , unsigned long V_28 ,
unsigned long V_29 )
{
char * V_30 ;
int V_31 , V_1 = - 1 ;
F_40 (i) {
if ( ! F_41 ( V_31 ) )
continue;
if ( V_27 == F_42 ( V_31 ) ) {
V_1 = V_31 ;
break;
}
}
if ( V_1 == - 1 )
return 0 ;
V_30 = F_43 ( V_32 , L_2 ,
V_1 , V_27 ) ;
if ( ! F_44 ( V_28 , V_29 , V_30 ) ) {
F_45 ( L_3
L_4 ,
V_1 , V_27 ) ;
return - V_33 ;
}
V_3 [ V_1 ] = F_46 ( V_28 , V_29 ) ;
F_47 ( V_1 , V_28 ) ;
if ( ! V_3 [ V_1 ] ) {
F_45 ( L_5
L_6 ,
V_1 , V_27 , V_28 ) ;
F_48 ( V_28 , V_29 ) ;
return - V_34 ;
}
return 0 ;
}
static int T_3 F_49 ( struct V_35 * V_36 ,
unsigned int * V_37 )
{
unsigned int V_38 ;
const T_4 * V_39 ;
int V_31 ;
int V_40 ;
int V_41 = 0 ;
V_39 = F_50 ( V_36 , L_7 , & V_38 ) ;
F_51 ( ( V_39 == NULL ) || ( V_38 != 2 * sizeof( V_42 ) ) ) ;
if ( V_39 ) {
* V_37 = F_52 ( V_39 , 1 ) ;
if ( V_38 >= 2 * sizeof( V_42 ) )
V_41 = F_52 ( V_39 + 1 , 1 ) ;
}
V_39 = F_50 ( V_36 , L_8 , & V_38 ) ;
if ( ! V_39 ) {
F_35 ( L_9 ) ;
return - 1 ;
}
V_40 = ( F_53 ( V_36 ) + F_54 ( V_36 ) ) * 4 ;
if ( ( ( V_38 % V_40 ) != 0 )
|| ( V_41 && ( V_41 != ( V_38 / V_40 ) ) ) ) {
F_35 ( L_10 ,
V_38 / V_40 , V_41 ) ;
return - 1 ;
}
for ( V_31 = 0 ; V_31 < ( V_38 / V_40 ) ; V_31 ++ ) {
struct V_43 V_44 ;
int V_45 ;
V_45 = F_55 ( V_36 , V_31 , & V_44 ) ;
if ( V_45 ) {
F_35 ( L_11
L_12 , * V_37 , V_45 ) ;
return - 1 ;
}
if ( F_39 ( * V_37 , V_44 . V_46 , F_56 ( & V_44 ) ) )
return - 1 ;
( * V_37 ) ++ ;
}
return 0 ;
}
int T_3 F_57 ( void )
{
struct V_35 * V_36 ;
V_42 V_37 = 0 ;
int V_47 = 0 ;
F_58 (np, NULL, L_13 )
if ( F_49 ( V_36 , & V_37 ) == 0 )
V_47 = 1 ;
if ( ! V_47 ) {
F_59 (np,
L_14 ) {
if ( F_49 ( V_36 , & V_37 ) == 0 )
V_47 = 1 ;
}
}
if ( V_47 == 0 )
return - V_48 ;
V_49 = & V_50 ;
return 0 ;
}
