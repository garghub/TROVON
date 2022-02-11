void F_1 ( unsigned V_1 , unsigned V_2 , void * V_3 )
{
unsigned long V_4 = V_3 ? F_2 ( V_3 ) : 0 ;
V_5 [ V_2 ] [ V_1 ] = V_4 ;
F_3 ( & V_5 [ V_2 ] [ V_1 ] ) ;
}
void F_4 ( unsigned V_1 , unsigned V_2 ,
unsigned long V_6 , unsigned long V_7 )
{
unsigned long * V_8 = & V_9 [ V_2 ] [ V_1 ] [ 0 ] ;
V_8 [ 0 ] = V_6 ;
V_8 [ 1 ] = V_7 ;
F_5 ( V_8 , 2 * sizeof( * V_8 ) ) ;
}
int T_1 F_6 ( const struct V_10 * V_11 )
{
if ( V_12 )
return - V_13 ;
V_12 = V_11 ;
return 0 ;
}
bool F_7 ( void )
{
return ( V_12 ) ? true : false ;
}
static inline bool F_8 ( unsigned int V_2 )
{
int V_14 , V_15 ;
for ( V_14 = 0 , V_15 = 0 ; V_14 < V_16 ; V_14 ++ )
V_15 |= V_17 [ V_2 ] [ V_14 ] ;
return ! V_15 ;
}
int F_9 ( unsigned int V_1 , unsigned int V_2 )
{
bool V_18 , V_19 ;
int V_20 = 0 ;
if ( ! V_12 )
return - V_21 ;
F_10 () ;
if ( V_12 -> V_22 )
return V_12 -> V_22 ( V_1 , V_2 ) ;
F_11 ( L_1 , V_23 , V_1 , V_2 ) ;
F_12 () ;
F_13 ( & V_24 ) ;
V_18 = ! V_17 [ V_2 ] [ V_1 ] ;
V_19 = F_8 ( V_2 ) ;
V_17 [ V_2 ] [ V_1 ] ++ ;
F_14 ( V_17 [ V_2 ] [ V_1 ] != 1 &&
V_17 [ V_2 ] [ V_1 ] != 2 ) ;
if ( V_19 )
V_20 = V_12 -> V_25 ( V_2 ) ;
if ( V_18 && ! V_20 )
V_20 = V_12 -> V_26 ( V_1 , V_2 ) ;
F_15 ( & V_24 ) ;
F_16 () ;
return V_20 ;
}
void F_17 ( void )
{
unsigned int V_27 , V_1 , V_2 ;
bool V_28 , V_29 ;
T_2 V_30 ;
if ( F_18 ( ! V_12 ) )
return;
F_14 ( ! F_19 () ) ;
F_20 () ;
if ( V_12 -> V_31 ) {
V_12 -> V_31 () ;
goto V_32;
}
V_27 = F_21 () ;
V_1 = F_22 ( V_27 , 0 ) ;
V_2 = F_22 ( V_27 , 1 ) ;
F_11 ( L_1 , V_23 , V_1 , V_2 ) ;
F_23 ( V_1 , V_2 ) ;
F_13 ( & V_24 ) ;
F_14 ( F_24 ( V_2 ) != V_33 ) ;
V_17 [ V_2 ] [ V_1 ] -- ;
F_14 ( V_17 [ V_2 ] [ V_1 ] != 0 &&
V_17 [ V_2 ] [ V_1 ] != 1 ) ;
V_28 = ! V_17 [ V_2 ] [ V_1 ] ;
V_29 = F_8 ( V_2 ) ;
if ( V_29 && F_25 ( V_1 , V_2 ) ) {
V_12 -> V_34 ( V_1 , V_2 ) ;
V_12 -> V_35 ( V_2 ) ;
F_15 ( & V_24 ) ;
V_12 -> V_36 () ;
F_26 ( V_2 , V_37 ) ;
} else {
if ( V_28 )
V_12 -> V_34 ( V_1 , V_2 ) ;
F_15 ( & V_24 ) ;
V_12 -> V_38 () ;
}
F_27 ( V_1 , V_2 ) ;
if ( V_28 )
F_28 () ;
V_32:
V_30 = ( T_2 ) ( unsigned long ) F_2 ( V_39 ) ;
V_30 ( F_2 ( V_40 ) ) ;
F_29 () ;
}
int F_30 ( unsigned int V_1 , unsigned int V_2 )
{
int V_20 ;
if ( F_18 ( ! V_12 || ! V_12 -> V_41 ) )
return - V_21 ;
V_20 = V_12 -> V_41 ( V_1 , V_2 ) ;
if ( V_20 )
F_31 ( L_2 ,
V_23 , V_1 , V_2 , V_20 ) ;
return V_20 ;
}
void F_32 ( T_3 V_42 )
{
if ( F_18 ( ! V_12 ) )
return;
if ( V_12 -> V_43 ) {
T_2 V_30 ;
F_14 ( ! F_19 () ) ;
F_20 () ;
V_12 -> V_43 ( V_42 ) ;
V_30 = ( T_2 ) ( unsigned long ) F_2 ( V_39 ) ;
V_30 ( F_2 ( V_40 ) ) ;
F_29 () ;
}
if ( V_12 -> V_44 ) {
unsigned int V_27 = F_21 () ;
unsigned int V_1 = F_22 ( V_27 , 0 ) ;
unsigned int V_2 = F_22 ( V_27 , 1 ) ;
F_13 ( & V_24 ) ;
V_12 -> V_44 ( V_1 , V_2 ) ;
F_15 ( & V_24 ) ;
}
F_17 () ;
}
int F_33 ( void )
{
unsigned int V_27 , V_1 , V_2 ;
bool V_45 , V_46 ;
unsigned long V_47 ;
if ( ! V_12 )
return - V_21 ;
if ( V_12 -> V_48 ) {
V_12 -> V_48 () ;
return 0 ;
}
V_27 = F_21 () ;
V_1 = F_22 ( V_27 , 0 ) ;
V_2 = F_22 ( V_27 , 1 ) ;
F_34 ( V_47 ) ;
F_13 ( & V_24 ) ;
V_45 = ! V_17 [ V_2 ] [ V_1 ] ;
V_46 = F_8 ( V_2 ) ;
if ( V_46 && V_12 -> V_49 )
V_12 -> V_49 ( V_2 ) ;
if ( V_45 )
V_17 [ V_2 ] [ V_1 ] = 1 ;
if ( V_12 -> V_50 )
V_12 -> V_50 ( V_1 , V_2 ) ;
F_15 ( & V_24 ) ;
F_35 ( V_47 ) ;
return 0 ;
}
static int T_1 F_36 ( unsigned long V_51 )
{
void (* F_37)( void ) = ( void * ) V_51 ;
unsigned int V_27 = F_21 () ;
unsigned int V_1 = F_22 ( V_27 , 0 ) ;
unsigned int V_2 = F_22 ( V_27 , 1 ) ;
T_2 V_30 ;
F_1 ( V_1 , V_2 , V_52 ) ;
F_20 () ;
F_23 ( V_1 , V_2 ) ;
F_14 ( ! F_25 ( V_1 , V_2 ) ) ;
F_37 () ;
F_26 ( V_2 , V_37 ) ;
F_27 ( V_1 , V_2 ) ;
V_30 = ( T_2 ) ( unsigned long ) F_2 ( V_39 ) ;
V_30 ( F_2 ( V_40 ) ) ;
F_29 () ;
}
int T_1 F_38 ( void (* F_37)( void ) )
{
int V_20 ;
F_12 () ;
F_39 () ;
V_20 = F_40 () ;
if ( ! V_20 ) {
V_20 = F_41 ( ( unsigned long ) F_37 , F_36 ) ;
F_42 () ;
}
F_43 () ;
F_16 () ;
if ( V_20 )
F_44 ( L_3 , V_23 , V_20 ) ;
return V_20 ;
}
void F_23 ( unsigned int V_1 , unsigned int V_2 )
{
V_53 . V_54 [ V_2 ] . V_55 [ V_1 ] . V_1 = V_56 ;
F_3 ( & V_53 . V_54 [ V_2 ] . V_55 [ V_1 ] . V_1 ) ;
}
void F_27 ( unsigned int V_1 , unsigned int V_2 )
{
F_45 () ;
V_53 . V_54 [ V_2 ] . V_55 [ V_1 ] . V_1 = V_57 ;
F_3 ( & V_53 . V_54 [ V_2 ] . V_55 [ V_1 ] . V_1 ) ;
F_46 () ;
}
void F_26 ( unsigned int V_2 , int V_58 )
{
F_45 () ;
V_53 . V_54 [ V_2 ] . V_2 = V_58 ;
F_3 ( & V_53 . V_54 [ V_2 ] . V_2 ) ;
F_46 () ;
}
bool F_25 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned int V_14 ;
struct V_59 * V_60 = & V_53 . V_54 [ V_2 ] ;
V_60 -> V_2 = V_61 ;
F_3 ( & V_60 -> V_2 ) ;
F_47 ( & V_60 -> V_62 ) ;
if ( V_60 -> V_62 == V_63 )
goto abort;
F_47 ( & V_60 -> V_55 ) ;
for ( V_14 = 0 ; V_14 < V_16 ; V_14 ++ ) {
int V_64 ;
if ( V_14 == V_1 )
continue;
while ( 1 ) {
V_64 = V_60 -> V_55 [ V_14 ] . V_1 ;
if ( V_64 != V_56 )
break;
F_48 () ;
F_47 ( & V_60 -> V_55 [ V_14 ] . V_1 ) ;
}
switch ( V_64 ) {
case V_57 :
continue;
default:
goto abort;
}
}
return true ;
abort:
F_26 ( V_2 , V_33 ) ;
return false ;
}
int F_24 ( unsigned int V_2 )
{
F_47 ( & V_53 . V_54 [ V_2 ] . V_2 ) ;
return V_53 . V_54 [ V_2 ] . V_2 ;
}
int T_1 F_49 (
void (* F_50)( unsigned int V_65 ) )
{
unsigned int V_14 , V_66 , V_27 , V_67 ;
F_51 ( V_68 * V_69 != sizeof V_53 ) ;
F_14 ( ( unsigned long ) & V_53 & ( V_70 - 1 ) ) ;
for ( V_14 = 0 ; V_14 < V_69 ; V_14 ++ ) {
V_53 . V_54 [ V_14 ] . V_2 = V_37 ;
V_53 . V_54 [ V_14 ] . V_62 = V_71 ;
for ( V_66 = 0 ; V_66 < V_16 ; V_66 ++ )
V_53 . V_54 [ V_14 ] . V_55 [ V_66 ] . V_1 = V_57 ;
}
V_27 = F_21 () ;
V_67 = F_22 ( V_27 , 1 ) ;
F_52 (i) {
V_17 [ V_67 ] [ V_14 ] = 1 ;
V_53 . V_54 [ V_67 ] . V_55 [ V_14 ] . V_1 = V_72 ;
}
V_53 . V_54 [ V_67 ] . V_2 = V_33 ;
F_3 ( & V_53 ) ;
if ( F_50 ) {
V_73 = F_2 ( F_50 ) ;
F_3 ( & V_73 ) ;
}
return 0 ;
}
