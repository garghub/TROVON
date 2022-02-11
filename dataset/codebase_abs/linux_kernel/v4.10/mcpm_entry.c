static void F_1 ( unsigned int V_1 , unsigned int V_2 )
{
V_3 . V_4 [ V_2 ] . V_5 [ V_1 ] . V_1 = V_6 ;
F_2 ( & V_3 . V_4 [ V_2 ] . V_5 [ V_1 ] . V_1 ) ;
}
static void F_3 ( unsigned int V_1 , unsigned int V_2 )
{
F_4 () ;
V_3 . V_4 [ V_2 ] . V_5 [ V_1 ] . V_1 = V_7 ;
F_2 ( & V_3 . V_4 [ V_2 ] . V_5 [ V_1 ] . V_1 ) ;
F_5 () ;
}
static void F_6 ( unsigned int V_2 , int V_8 )
{
F_4 () ;
V_3 . V_4 [ V_2 ] . V_2 = V_8 ;
F_2 ( & V_3 . V_4 [ V_2 ] . V_2 ) ;
F_5 () ;
}
static bool F_7 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned int V_9 ;
struct V_10 * V_11 = & V_3 . V_4 [ V_2 ] ;
V_11 -> V_2 = V_12 ;
F_2 ( & V_11 -> V_2 ) ;
F_8 ( & V_11 -> V_13 ) ;
if ( V_11 -> V_13 == V_14 )
goto abort;
F_8 ( & V_11 -> V_5 ) ;
for ( V_9 = 0 ; V_9 < V_15 ; V_9 ++ ) {
int V_16 ;
if ( V_9 == V_1 )
continue;
while ( 1 ) {
V_16 = V_11 -> V_5 [ V_9 ] . V_1 ;
if ( V_16 != V_6 )
break;
F_9 () ;
F_8 ( & V_11 -> V_5 [ V_9 ] . V_1 ) ;
}
switch ( V_16 ) {
case V_7 :
continue;
default:
goto abort;
}
}
return true ;
abort:
F_6 ( V_2 , V_17 ) ;
return false ;
}
static int F_10 ( unsigned int V_2 )
{
F_8 ( & V_3 . V_4 [ V_2 ] . V_2 ) ;
return V_3 . V_4 [ V_2 ] . V_2 ;
}
void F_11 ( unsigned V_1 , unsigned V_2 , void * V_18 )
{
unsigned long V_19 = V_18 ? F_12 ( V_18 ) : 0 ;
V_20 [ V_2 ] [ V_1 ] = V_19 ;
F_2 ( & V_20 [ V_2 ] [ V_1 ] ) ;
}
void F_13 ( unsigned V_1 , unsigned V_2 ,
unsigned long V_21 , unsigned long V_22 )
{
unsigned long * V_23 = & V_24 [ V_2 ] [ V_1 ] [ 0 ] ;
V_23 [ 0 ] = V_21 ;
V_23 [ 1 ] = V_22 ;
F_14 ( V_23 , 2 * sizeof( * V_23 ) ) ;
}
int T_1 F_15 ( const struct V_25 * V_26 )
{
if ( V_27 )
return - V_28 ;
V_27 = V_26 ;
return 0 ;
}
bool F_16 ( void )
{
return ( V_27 ) ? true : false ;
}
static inline bool F_17 ( unsigned int V_2 )
{
int V_9 , V_29 ;
for ( V_9 = 0 , V_29 = 0 ; V_9 < V_15 ; V_9 ++ )
V_29 |= V_30 [ V_2 ] [ V_9 ] ;
return ! V_29 ;
}
int F_18 ( unsigned int V_1 , unsigned int V_2 )
{
bool V_31 , V_32 ;
int V_33 = 0 ;
F_19 ( L_1 , V_34 , V_1 , V_2 ) ;
if ( ! V_27 )
return - V_35 ;
F_20 () ;
F_21 () ;
F_22 ( & V_36 ) ;
V_31 = ! V_30 [ V_2 ] [ V_1 ] ;
V_32 = F_17 ( V_2 ) ;
V_30 [ V_2 ] [ V_1 ] ++ ;
F_23 ( V_30 [ V_2 ] [ V_1 ] != 1 &&
V_30 [ V_2 ] [ V_1 ] != 2 ) ;
if ( V_32 )
V_33 = V_27 -> V_37 ( V_2 ) ;
if ( V_31 && ! V_33 )
V_33 = V_27 -> V_38 ( V_1 , V_2 ) ;
F_24 ( & V_36 ) ;
F_25 () ;
return V_33 ;
}
void F_26 ( void )
{
unsigned int V_39 , V_1 , V_2 ;
bool V_40 , V_41 ;
T_2 V_42 ;
V_39 = F_27 () ;
V_1 = F_28 ( V_39 , 0 ) ;
V_2 = F_28 ( V_39 , 1 ) ;
F_19 ( L_1 , V_34 , V_1 , V_2 ) ;
if ( F_29 ( ! V_27 ) )
return;
F_23 ( ! F_30 () ) ;
F_31 () ;
F_1 ( V_1 , V_2 ) ;
F_22 ( & V_36 ) ;
F_23 ( F_10 ( V_2 ) != V_17 ) ;
V_30 [ V_2 ] [ V_1 ] -- ;
F_23 ( V_30 [ V_2 ] [ V_1 ] != 0 &&
V_30 [ V_2 ] [ V_1 ] != 1 ) ;
V_40 = ! V_30 [ V_2 ] [ V_1 ] ;
V_41 = F_17 ( V_2 ) ;
if ( V_41 && F_7 ( V_1 , V_2 ) ) {
V_27 -> V_43 ( V_1 , V_2 ) ;
V_27 -> V_44 ( V_2 ) ;
F_24 ( & V_36 ) ;
V_27 -> V_45 () ;
F_6 ( V_2 , V_46 ) ;
} else {
if ( V_40 )
V_27 -> V_43 ( V_1 , V_2 ) ;
F_24 ( & V_36 ) ;
V_27 -> V_47 () ;
}
F_3 ( V_1 , V_2 ) ;
if ( V_40 )
F_32 () ;
V_42 = ( T_2 ) ( unsigned long ) F_12 ( V_48 ) ;
V_42 ( F_12 ( V_49 ) ) ;
F_33 () ;
}
int F_34 ( unsigned int V_1 , unsigned int V_2 )
{
int V_33 ;
if ( F_29 ( ! V_27 || ! V_27 -> V_50 ) )
return - V_35 ;
V_33 = V_27 -> V_50 ( V_1 , V_2 ) ;
if ( V_33 )
F_35 ( L_2 ,
V_34 , V_1 , V_2 , V_33 ) ;
return V_33 ;
}
void F_36 ( void )
{
if ( F_29 ( ! V_27 ) )
return;
if ( V_27 -> V_51 ) {
unsigned int V_39 = F_27 () ;
unsigned int V_1 = F_28 ( V_39 , 0 ) ;
unsigned int V_2 = F_28 ( V_39 , 1 ) ;
F_22 ( & V_36 ) ;
V_27 -> V_51 ( V_1 , V_2 ) ;
F_24 ( & V_36 ) ;
}
F_26 () ;
}
int F_37 ( void )
{
unsigned int V_39 , V_1 , V_2 ;
bool V_52 , V_53 ;
unsigned long V_54 ;
if ( ! V_27 )
return - V_35 ;
V_39 = F_27 () ;
V_1 = F_28 ( V_39 , 0 ) ;
V_2 = F_28 ( V_39 , 1 ) ;
F_38 ( V_54 ) ;
F_22 ( & V_36 ) ;
V_52 = ! V_30 [ V_2 ] [ V_1 ] ;
V_53 = F_17 ( V_2 ) ;
if ( V_53 && V_27 -> V_55 )
V_27 -> V_55 ( V_2 ) ;
if ( V_52 )
V_30 [ V_2 ] [ V_1 ] = 1 ;
if ( V_27 -> V_56 )
V_27 -> V_56 ( V_1 , V_2 ) ;
F_24 ( & V_36 ) ;
F_39 ( V_54 ) ;
return 0 ;
}
static int T_1 F_40 ( unsigned long V_57 )
{
void (* F_41)( void ) = ( void * ) V_57 ;
unsigned int V_39 = F_27 () ;
unsigned int V_1 = F_28 ( V_39 , 0 ) ;
unsigned int V_2 = F_28 ( V_39 , 1 ) ;
T_2 V_42 ;
F_11 ( V_1 , V_2 , V_58 ) ;
F_31 () ;
F_1 ( V_1 , V_2 ) ;
F_23 ( ! F_7 ( V_1 , V_2 ) ) ;
F_41 () ;
F_6 ( V_2 , V_46 ) ;
F_3 ( V_1 , V_2 ) ;
V_42 = ( T_2 ) ( unsigned long ) F_12 ( V_48 ) ;
V_42 ( F_12 ( V_49 ) ) ;
F_33 () ;
}
int T_1 F_42 ( void (* F_41)( void ) )
{
int V_33 ;
F_21 () ;
F_43 () ;
V_33 = F_44 () ;
if ( ! V_33 ) {
V_33 = F_45 ( ( unsigned long ) F_41 , F_40 ) ;
F_46 () ;
}
F_47 () ;
F_25 () ;
if ( V_33 )
F_48 ( L_3 , V_34 , V_33 ) ;
return V_33 ;
}
int T_1 F_49 (
void (* F_50)( unsigned int V_59 ) )
{
unsigned int V_9 , V_60 , V_39 , V_61 ;
F_51 ( V_62 * V_63 != sizeof V_3 ) ;
F_23 ( ( unsigned long ) & V_3 & ( V_64 - 1 ) ) ;
for ( V_9 = 0 ; V_9 < V_63 ; V_9 ++ ) {
V_3 . V_4 [ V_9 ] . V_2 = V_46 ;
V_3 . V_4 [ V_9 ] . V_13 = V_65 ;
for ( V_60 = 0 ; V_60 < V_15 ; V_60 ++ )
V_3 . V_4 [ V_9 ] . V_5 [ V_60 ] . V_1 = V_7 ;
}
V_39 = F_27 () ;
V_61 = F_28 ( V_39 , 1 ) ;
F_52 (i) {
V_30 [ V_61 ] [ V_9 ] = 1 ;
V_3 . V_4 [ V_61 ] . V_5 [ V_9 ] . V_1 = V_66 ;
}
V_3 . V_4 [ V_61 ] . V_2 = V_17 ;
F_2 ( & V_3 ) ;
if ( F_50 ) {
V_67 = F_12 ( F_50 ) ;
F_2 ( & V_67 ) ;
}
return 0 ;
}
