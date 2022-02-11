static void F_1 ( int V_1 )
{
unsigned long V_2 , V_3 ;
int V_4 ;
V_2 = F_2 ( V_1 ) ;
V_4 = F_3 ( V_2 ) ;
V_2 |= V_5 ;
V_3 = ( 1UL << V_6 ) |
( V_2 << V_7 ) |
( V_8 << V_9 ) ;
F_4 ( V_4 , V_10 , V_3 ) ;
}
static int F_5 ( int V_4 )
{
if ( F_6 () )
return F_7 ( V_4 , V_11 ) &
V_12 ;
else if ( F_8 () )
return F_7 ( V_4 , V_13 ) &
V_14 ;
return 0 ;
}
static int F_9 ( int V_1 , T_1 V_15 )
{
T_1 V_3 ;
unsigned long V_2 = F_2 ( V_1 ) | V_5 ;
int V_4 = F_10 ( V_1 ) ;
F_4 ( V_4 , V_16 ,
V_17 ) ;
F_4 ( V_4 , V_18 , - 1L ) ;
if ( F_6 () )
F_4 ( V_4 , V_19 ,
V_12 ) ;
else
F_4 ( V_4 , V_20 ,
V_14 ) ;
V_3 = ( V_8 << V_21 ) |
( ( T_1 ) V_2 << V_22 ) ;
F_4 ( V_4 , V_16 , V_3 ) ;
F_4 ( V_4 , V_18 , V_15 ) ;
if ( F_11 ( NULL ) <= V_15 )
return 0 ;
return ! F_5 ( V_4 ) ;
}
static T_2 void F_12 ( void )
{
int V_23 ;
F_13 (bid) {
F_14 ( V_24 [ V_23 ] ) ;
}
F_14 ( V_24 ) ;
}
static T_2 int F_15 ( void )
{
int V_1 ;
V_24 = F_16 ( V_25 * sizeof( void * ) , V_26 ) ;
if ( ! V_24 )
return - V_27 ;
F_17 (cpu) {
int V_28 = F_18 ( V_1 ) ;
int V_23 = F_19 ( V_1 ) ;
int V_29 = F_20 ( V_1 ) ;
struct V_30 * V_31 = V_24 [ V_23 ] ;
if ( ! V_31 ) {
V_31 = F_21 ( sizeof( struct V_30 ) +
( F_22 ( V_23 ) *
2 * sizeof( T_1 ) ) ,
V_26 , V_28 ) ;
if ( ! V_31 ) {
F_12 () ;
return - V_27 ;
}
F_23 ( & V_31 -> V_32 ) ;
V_31 -> V_33 = F_22 ( V_23 ) ;
V_31 -> V_34 = - 1 ;
V_24 [ V_23 ] = V_31 ;
}
V_31 -> V_1 [ V_29 ] . V_35 = V_1 ;
V_31 -> V_1 [ V_29 ] . V_15 = V_36 ;
}
return 0 ;
}
static void F_24 ( struct V_30 * V_31 , int V_4 )
{
T_1 V_37 = V_36 ;
int V_38 , V_29 = - 1 ;
V_31 -> V_34 = - 1 ;
for ( V_38 = 0 ; V_38 < V_31 -> V_33 ; V_38 ++ ) {
T_1 exp = V_31 -> V_1 [ V_38 ] . V_15 ;
if ( exp < V_37 ) {
V_29 = V_38 ;
V_37 = exp ;
}
}
if ( V_29 >= 0 ) {
V_31 -> V_34 = V_29 ;
V_38 = V_31 -> V_1 [ V_29 ] . V_35 ;
if ( F_9 ( V_38 , V_37 ) )
F_1 ( V_38 ) ;
} else {
F_4 ( V_4 , V_16 ,
V_17 ) ;
}
}
static int F_25 ( int V_1 , T_1 V_15 )
{
int V_4 = F_10 ( V_1 ) ;
int V_23 = F_19 ( V_1 ) ;
struct V_30 * V_31 = V_24 [ V_23 ] ;
int V_29 = F_20 ( V_1 ) ;
T_1 * V_39 = & V_31 -> V_1 [ V_29 ] . V_15 ;
unsigned long V_40 ;
int V_34 ;
F_26 ( & V_31 -> V_32 , V_40 ) ;
V_34 = V_31 -> V_34 ;
* V_39 = V_15 ;
if ( V_34 < 0 || V_29 == V_34 ||
V_15 < V_31 -> V_1 [ V_34 ] . V_15 ) {
V_31 -> V_34 = V_29 ;
if ( F_9 ( V_1 , V_15 ) ) {
* V_39 = V_36 ;
F_24 ( V_31 , V_4 ) ;
F_27 ( & V_31 -> V_32 , V_40 ) ;
return - V_41 ;
}
}
F_27 ( & V_31 -> V_32 , V_40 ) ;
return 0 ;
}
static int F_28 ( int V_1 , int V_42 )
{
int V_4 = F_10 ( V_1 ) ;
int V_23 = F_19 ( V_1 ) ;
struct V_30 * V_31 = V_24 [ V_23 ] ;
int V_29 = F_20 ( V_1 ) ;
T_1 * V_39 = & V_31 -> V_1 [ V_29 ] . V_15 ;
unsigned long V_40 ;
int V_43 = 0 ;
F_26 ( & V_31 -> V_32 , V_40 ) ;
if ( ( V_31 -> V_34 == V_29 && F_11 ( NULL ) >= * V_39 ) || V_42 )
V_43 = 1 ;
if ( V_43 ) {
* V_39 = V_36 ;
if ( V_31 -> V_34 == V_29 )
F_24 ( V_31 , V_4 ) ;
}
F_27 ( & V_31 -> V_32 , V_40 ) ;
return V_43 ;
}
static T_3 F_11 ( struct V_44 * V_45 )
{
unsigned long V_46 ;
if ( F_29 () == 1 )
V_46 = 0 ;
else
V_46 = ( F_30 () * V_47 ) % V_48 ;
return ( T_3 ) F_31 ( V_49 | V_46 ) ;
}
static int F_32 ( unsigned long V_50 ,
struct V_51 * V_52 )
{
int V_53 = F_33 ( V_52 -> V_54 ) ;
return F_25 ( V_53 , V_50 + F_11 ( NULL ) ) ;
}
static int F_34 ( struct V_51 * V_55 )
{
int V_53 = F_33 ( V_55 -> V_54 ) ;
F_28 ( V_53 , 1 ) ;
return 0 ;
}
static void F_35 ( void )
{
int V_1 = F_36 () ;
struct V_51 * V_52 = & F_37 ( V_56 , V_1 ) ;
if ( ! V_52 || ! V_52 -> V_57 )
return;
if ( F_28 ( V_1 , 0 ) != 1 )
return;
V_52 -> V_57 ( V_52 ) ;
}
static int T_2 F_38 ( char * V_58 )
{
V_59 = 1 ;
return 1 ;
}
static T_2 void F_39 ( struct V_60 * V_61 )
{
struct V_51 * V_52 = F_40 ( & V_56 ) ;
* V_52 = V_62 ;
V_52 -> V_54 = F_41 ( F_36 () ) ;
F_42 ( V_52 ) ;
}
static T_2 int F_43 ( void )
{
int V_43 ;
if ( ! F_44 () )
return - V_63 ;
V_43 = F_45 ( & V_64 , V_65 ) ;
if ( V_43 )
F_46 ( V_66 L_1 , V_43 ) ;
else
F_46 ( V_66 L_2 ,
V_65 / ( unsigned long ) 1E6 ) ;
if ( V_43 || ! V_59 || V_67 )
return V_43 ;
V_43 = F_15 () ;
if ( V_43 )
goto error;
V_67 = F_35 ;
V_62 . V_68 = F_47 ( V_65 ,
V_69 , V_62 . V_70 ) ;
V_62 . V_71 = V_69 /
V_65 ;
V_62 . V_72 = V_64 . V_73 *
( V_69 / V_65 ) ;
V_43 = F_48 ( F_39 ) ;
if ( V_43 ) {
V_67 = NULL ;
F_12 () ;
goto error;
}
F_46 ( V_66 L_3 ) ;
return 0 ;
error:
F_49 ( & V_64 ) ;
F_46 ( V_66 L_4 , V_43 ) ;
return V_43 ;
}
