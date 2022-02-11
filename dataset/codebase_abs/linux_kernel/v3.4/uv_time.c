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
else
return F_7 ( V_4 , V_13 ) &
V_14 ;
}
static int F_8 ( int V_1 , T_1 V_15 )
{
T_1 V_3 ;
unsigned long V_2 = F_2 ( V_1 ) | V_5 ;
int V_4 = F_9 ( V_1 ) ;
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
if ( F_10 ( NULL ) <= V_15 )
return 0 ;
return ! F_5 ( V_4 ) ;
}
static T_2 void F_11 ( void )
{
int V_23 ;
F_12 (bid) {
F_13 ( V_24 [ V_23 ] ) ;
}
F_13 ( V_24 ) ;
}
static T_2 int F_14 ( void )
{
int V_1 ;
V_24 = F_15 ( V_25 * sizeof( void * ) , V_26 ) ;
if ( ! V_24 )
return - V_27 ;
memset ( V_24 , 0 , V_25 * sizeof( void * ) ) ;
F_16 (cpu) {
int V_28 = F_17 ( V_1 ) ;
int V_23 = F_18 ( V_1 ) ;
int V_29 = F_19 ( V_1 ) -> V_30 ;
struct V_31 * V_32 = V_24 [ V_23 ] ;
if ( ! V_32 ) {
V_32 = F_20 ( sizeof( struct V_31 ) +
( F_21 ( V_23 ) *
2 * sizeof( T_1 ) ) ,
V_26 , V_28 ) ;
if ( ! V_32 ) {
F_11 () ;
return - V_27 ;
}
F_22 ( & V_32 -> V_33 ) ;
V_32 -> V_34 = F_21 ( V_23 ) ;
V_32 -> V_35 = - 1 ;
V_24 [ V_23 ] = V_32 ;
}
V_32 -> V_1 [ V_29 ] . V_36 = V_1 ;
V_32 -> V_1 [ V_29 ] . V_15 = V_37 ;
}
return 0 ;
}
static void F_23 ( struct V_31 * V_32 , int V_4 )
{
T_1 V_38 = V_37 ;
int V_39 , V_29 = - 1 ;
V_32 -> V_35 = - 1 ;
for ( V_39 = 0 ; V_39 < V_32 -> V_34 ; V_39 ++ ) {
T_1 exp = V_32 -> V_1 [ V_39 ] . V_15 ;
if ( exp < V_38 ) {
V_29 = V_39 ;
V_38 = exp ;
}
}
if ( V_29 >= 0 ) {
V_32 -> V_35 = V_29 ;
V_39 = V_32 -> V_1 [ V_29 ] . V_36 ;
if ( F_8 ( V_39 , V_38 ) )
F_1 ( V_39 ) ;
} else {
F_4 ( V_4 , V_16 ,
V_17 ) ;
}
}
static int F_24 ( int V_1 , T_1 V_15 )
{
int V_4 = F_9 ( V_1 ) ;
int V_23 = F_18 ( V_1 ) ;
struct V_31 * V_32 = V_24 [ V_23 ] ;
int V_29 = F_19 ( V_1 ) -> V_30 ;
T_1 * V_40 = & V_32 -> V_1 [ V_29 ] . V_15 ;
unsigned long V_41 ;
int V_35 ;
F_25 ( & V_32 -> V_33 , V_41 ) ;
V_35 = V_32 -> V_35 ;
* V_40 = V_15 ;
if ( V_35 < 0 || V_29 == V_35 ||
V_15 < V_32 -> V_1 [ V_35 ] . V_15 ) {
V_32 -> V_35 = V_29 ;
if ( F_8 ( V_1 , V_15 ) ) {
* V_40 = V_37 ;
F_23 ( V_32 , V_4 ) ;
F_26 ( & V_32 -> V_33 , V_41 ) ;
return - V_42 ;
}
}
F_26 ( & V_32 -> V_33 , V_41 ) ;
return 0 ;
}
static int F_27 ( int V_1 , int V_43 )
{
int V_4 = F_9 ( V_1 ) ;
int V_23 = F_18 ( V_1 ) ;
struct V_31 * V_32 = V_24 [ V_23 ] ;
int V_29 = F_19 ( V_1 ) -> V_30 ;
T_1 * V_40 = & V_32 -> V_1 [ V_29 ] . V_15 ;
unsigned long V_41 ;
int V_44 = 0 ;
F_25 ( & V_32 -> V_33 , V_41 ) ;
if ( ( V_32 -> V_35 == V_29 && F_10 ( NULL ) >= * V_40 ) || V_43 )
V_44 = 1 ;
if ( V_44 ) {
* V_40 = V_37 ;
if ( V_32 -> V_35 == V_29 )
F_23 ( V_32 , V_4 ) ;
}
F_26 ( & V_32 -> V_33 , V_41 ) ;
return V_44 ;
}
static T_3 F_10 ( struct V_45 * V_46 )
{
unsigned long V_47 ;
if ( F_28 () == 1 )
V_47 = 0 ;
else
V_47 = ( F_29 () * V_48 ) % V_49 ;
return ( T_3 ) F_30 ( V_50 | V_47 ) ;
}
static int F_31 ( unsigned long V_51 ,
struct V_52 * V_53 )
{
int V_54 = F_32 ( V_53 -> V_55 ) ;
return F_24 ( V_54 , V_51 + F_10 ( NULL ) ) ;
}
static void F_33 ( enum V_56 V_57 ,
struct V_52 * V_58 )
{
int V_54 = F_32 ( V_58 -> V_55 ) ;
switch ( V_57 ) {
case V_59 :
case V_60 :
case V_61 :
break;
case V_62 :
case V_63 :
F_27 ( V_54 , 1 ) ;
break;
}
}
static void F_34 ( void )
{
int V_1 = F_35 () ;
struct V_52 * V_53 = & F_36 ( V_64 , V_1 ) ;
if ( ! V_53 || ! V_53 -> V_65 )
return;
if ( F_27 ( V_1 , 0 ) != 1 )
return;
V_53 -> V_65 ( V_53 ) ;
}
static int T_2 F_37 ( char * V_66 )
{
V_67 = 1 ;
return 1 ;
}
static T_2 void F_38 ( struct V_68 * V_69 )
{
struct V_52 * V_53 = & F_39 ( V_64 ) ;
* V_53 = V_70 ;
V_53 -> V_55 = F_40 ( F_35 () ) ;
F_41 ( V_53 ) ;
}
static T_2 int F_42 ( void )
{
int V_44 ;
if ( ! F_43 () )
return - V_71 ;
V_44 = F_44 ( & V_72 , V_73 ) ;
if ( V_44 )
F_45 ( V_74 L_1 , V_44 ) ;
else
F_45 ( V_74 L_2 ,
V_73 / ( unsigned long ) 1E6 ) ;
if ( V_44 || ! V_67 || V_75 )
return V_44 ;
V_44 = F_14 () ;
if ( V_44 )
goto error;
V_75 = F_34 ;
V_70 . V_76 = F_46 ( V_73 ,
V_77 , V_70 . V_78 ) ;
V_70 . V_79 = V_77 /
V_73 ;
V_70 . V_80 = V_72 . V_81 *
( V_77 / V_73 ) ;
V_44 = F_47 ( F_38 ) ;
if ( V_44 ) {
V_75 = NULL ;
F_11 () ;
goto error;
}
F_45 ( V_74 L_3 ) ;
return 0 ;
error:
F_48 ( & V_72 ) ;
F_45 ( V_74 L_4 , V_44 ) ;
return V_44 ;
}
