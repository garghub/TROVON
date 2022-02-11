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
static void F_23 ( int V_1 )
{
F_24 ( V_1 , 1 ) ;
F_9 ( V_1 , V_18 ) ;
}
void F_25 ( int V_1 )
{
void T_2 * V_19 ;
V_19 = V_20 [ V_1 ] . V_21 . V_19 ;
F_26 () ;
F_27 ( V_18 , V_19 + V_22 ) ;
}
void F_28 ( void )
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
F_29 ( L_1 ,
V_14 ) ;
F_22 ( V_14 ) ;
}
F_5 ( V_2 ) ;
}
void F_30 ( int V_1 )
{
F_9 ( V_1 , V_18 ) ;
}
static T_3 F_31 ( int V_15 , void * V_23 )
{
int V_1 = F_2 () ;
F_24 ( V_1 , 0 ) ;
F_9 ( V_1 , 0xff ) ;
return F_32 () ;
}
static int T_4 F_33 ( int V_24 , unsigned long V_25 ,
unsigned long V_26 )
{
char * V_27 ;
int V_28 , V_1 = - 1 ;
F_34 (i) {
if ( ! F_35 ( V_28 ) )
continue;
if ( V_24 == F_36 ( V_28 ) ) {
V_1 = V_28 ;
break;
}
}
if ( V_1 == - 1 )
return 0 ;
V_27 = F_37 ( V_29 , L_2 ,
V_1 , V_24 ) ;
if ( ! F_38 ( V_25 , V_26 , V_27 ) ) {
F_39 ( L_3
L_4 ,
V_1 , V_24 ) ;
return - V_30 ;
}
V_3 [ V_1 ] = F_40 ( V_25 , V_26 ) ;
F_41 ( V_1 , V_25 ) ;
if ( ! V_3 [ V_1 ] ) {
F_39 ( L_5
L_6 ,
V_1 , V_24 , V_25 ) ;
F_42 ( V_25 , V_26 ) ;
return - V_31 ;
}
return 0 ;
}
static int T_4 F_43 ( struct V_32 * V_33 ,
unsigned int * V_34 )
{
unsigned int V_35 ;
const T_5 * V_36 ;
int V_28 ;
int V_37 ;
int V_38 = 0 ;
V_36 = F_44 ( V_33 , L_7 , & V_35 ) ;
F_45 ( ( V_36 == NULL ) || ( V_35 != 2 * sizeof( V_39 ) ) ) ;
if ( V_36 ) {
* V_34 = F_46 ( V_36 , 1 ) ;
if ( V_35 >= 2 * sizeof( V_39 ) )
V_38 = F_46 ( V_36 + 1 , 1 ) ;
}
V_36 = F_44 ( V_33 , L_8 , & V_35 ) ;
if ( ! V_36 ) {
F_29 ( L_9 ) ;
return - 1 ;
}
V_37 = ( F_47 ( V_33 ) + F_48 ( V_33 ) ) * 4 ;
if ( ( ( V_35 % V_37 ) != 0 )
|| ( V_38 && ( V_38 != ( V_35 / V_37 ) ) ) ) {
F_29 ( L_10 ,
V_35 / V_37 , V_38 ) ;
return - 1 ;
}
for ( V_28 = 0 ; V_28 < ( V_35 / V_37 ) ; V_28 ++ ) {
struct V_40 V_41 ;
int V_42 ;
V_42 = F_49 ( V_33 , V_28 , & V_41 ) ;
if ( V_42 ) {
F_29 ( L_11
L_12 , * V_34 , V_42 ) ;
return - 1 ;
}
if ( F_33 ( * V_34 , V_41 . V_43 , F_50 ( & V_41 ) ) )
return - 1 ;
( * V_34 ) ++ ;
}
return 0 ;
}
int T_4 F_51 ( void )
{
struct V_32 * V_33 ;
V_39 V_34 = 0 ;
int V_44 = 0 ;
F_52 (np, NULL, L_13 )
if ( F_43 ( V_33 , & V_34 ) == 0 )
V_44 = 1 ;
if ( ! V_44 ) {
F_53 (np,
L_14 ) {
if ( F_43 ( V_33 , & V_34 ) == 0 )
V_44 = 1 ;
}
}
if ( V_44 == 0 )
return - V_45 ;
V_46 = & V_47 ;
return 0 ;
}
