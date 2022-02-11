static int
F_1 ( int V_1 )
{
struct V_2 V_3 ;
V_3 . V_1 = V_1 ;
if ( F_2 ( V_4 , & V_3 ) )
return - V_5 ;
return V_3 . V_6 ;
}
static void
F_3 ( int V_6 )
{
struct V_2 V_3 ;
if ( V_6 < V_7 ||
V_6 > V_8 )
return;
V_3 . V_6 = V_6 ;
if ( F_2 ( V_9 , & V_3 ) )
F_4 ( V_10 L_1 ,
V_11 , V_6 ) ;
}
static T_1
F_5 ( int V_1 , void * V_12 )
{
return V_13 ;
}
static T_1
F_6 ( int V_1 , void * V_12 )
{
F_7 () ;
return V_13 ;
}
static void
F_8 ( unsigned int V_14 , unsigned int V_15 ,
struct V_16 * V_17 , int V_18 )
{
int V_1 = 0 ;
if ( V_19 ) {
switch ( V_15 ) {
case V_20 :
snprintf ( F_9 ( V_21 , V_14 ) ,
sizeof( F_9 ( V_21 , V_14 ) ) ,
L_2 , V_17 -> V_22 , V_14 ) ;
V_1 = F_10 ( V_23 , V_14 ,
V_17 -> V_24 , V_17 -> V_25 ,
F_9 ( V_21 , V_14 ) , V_17 -> V_12 ) ;
F_9 ( V_26 , V_14 ) = V_1 ;
break;
case V_27 :
snprintf ( F_9 ( V_28 , V_14 ) ,
sizeof( F_9 ( V_28 , V_14 ) ) ,
L_2 , V_17 -> V_22 , V_14 ) ;
V_1 = F_11 ( V_29 , V_14 ,
V_17 -> V_24 , V_17 -> V_25 ,
F_9 ( V_28 , V_14 ) , V_17 -> V_12 ) ;
F_9 ( V_30 , V_14 ) = V_1 ;
break;
case V_31 :
snprintf ( F_9 ( V_32 , V_14 ) ,
sizeof( F_9 ( V_32 , V_14 ) ) ,
L_2 , V_17 -> V_22 , V_14 ) ;
V_1 = F_11 ( V_33 , V_14 ,
V_17 -> V_24 , V_17 -> V_25 ,
F_9 ( V_32 , V_14 ) , V_17 -> V_12 ) ;
F_9 ( V_34 , V_14 ) = V_1 ;
break;
case V_35 :
snprintf ( F_9 ( V_36 , V_14 ) ,
sizeof( F_9 ( V_36 , V_14 ) ) ,
L_2 , V_17 -> V_22 , V_14 ) ;
V_1 = F_10 ( V_37 , V_14 ,
V_17 -> V_24 ,
V_17 -> V_25 ,
F_9 ( V_36 , V_14 ) ,
V_17 -> V_12 ) ;
F_9 ( V_38 , V_14 ) = V_1 ;
break;
case V_39 :
snprintf ( F_9 ( V_40 , V_14 ) ,
sizeof( F_9 ( V_40 , V_14 ) ) ,
L_2 , V_17 -> V_22 , V_14 ) ;
V_1 = F_11 ( V_41 , V_14 ,
V_17 -> V_24 ,
V_17 -> V_25 ,
F_9 ( V_40 , V_14 ) ,
V_17 -> V_12 ) ;
F_9 ( V_42 , V_14 ) = V_1 ;
break;
case V_43 :
snprintf ( F_9 ( V_44 , V_14 ) ,
sizeof( F_9 ( V_44 , V_14 ) ) ,
L_2 , V_17 -> V_22 , V_14 ) ;
V_1 = F_11 ( V_45 , V_14 ,
V_17 -> V_24 ,
V_17 -> V_25 ,
F_9 ( V_44 , V_14 ) ,
V_17 -> V_12 ) ;
F_9 ( V_46 , V_14 ) = V_1 ;
break;
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
break;
default:
F_4 ( V_10 L_3
L_4 , V_15 ) ;
break;
}
F_12 ( V_1 < 0 ) ;
if ( V_1 > 0 ) {
F_13 ( V_1 , V_52 ) ;
}
}
if ( ! V_14 && V_18 ) {
F_12 ( V_53 == V_54 ) ;
V_55 [ V_53 ] . V_1 = V_15 ;
V_55 [ V_53 ] . V_17 = V_17 ;
V_53 ++ ;
if ( ! V_19 )
V_56 ++ ;
}
}
static void
F_14 ( T_2 V_15 , struct V_16 * V_17 )
{
F_8 ( F_15 () , V_15 , V_17 , 1 ) ;
}
static void
F_16 ( void )
{
int V_57 ;
V_19 = 1 ;
for ( V_57 = 0 ; V_57 < V_56 ; V_57 ++ )
F_8 ( F_15 () ,
V_55 [ V_57 ] . V_1 ,
V_55 [ V_57 ] . V_17 , 0 ) ;
}
static int F_17 ( struct V_58 * V_59 ,
unsigned long V_17 , void * V_60 )
{
unsigned int V_14 = ( unsigned long ) V_60 ;
if ( V_17 == V_61 ) {
if ( F_9 ( V_46 , V_14 ) >= 0 ) {
F_18 ( F_9 ( V_46 , V_14 ) ,
NULL ) ;
F_9 ( V_46 , V_14 ) = - 1 ;
}
if ( F_9 ( V_42 , V_14 ) >= 0 ) {
F_18 ( F_9 ( V_42 , V_14 ) ,
NULL ) ;
F_9 ( V_42 , V_14 ) = - 1 ;
}
if ( F_9 ( V_38 , V_14 ) >= 0 ) {
F_18 ( F_9 ( V_38 , V_14 ) , NULL ) ;
F_9 ( V_38 , V_14 ) = - 1 ;
}
if ( F_9 ( V_34 , V_14 ) >= 0 ) {
F_18 ( F_9 ( V_34 , V_14 ) , NULL ) ;
F_9 ( V_34 , V_14 ) = - 1 ;
}
if ( F_9 ( V_30 , V_14 ) >= 0 ) {
F_18 ( F_9 ( V_30 , V_14 ) ,
NULL ) ;
F_9 ( V_30 , V_14 ) = - 1 ;
}
if ( F_9 ( V_26 , V_14 ) >= 0 ) {
F_18 ( F_9 ( V_26 , V_14 ) ,
NULL ) ;
F_9 ( V_26 , V_14 ) = - 1 ;
}
}
return V_62 ;
}
void F_19 ( unsigned int V_14 )
{
#ifdef F_20
unsigned int V_57 ;
for ( V_57 = 0 ; V_57 < V_53 ; V_57 ++ )
F_8 ( V_14 , V_55 [ V_57 ] . V_1 ,
V_55 [ V_57 ] . V_17 , 0 ) ;
#endif
}
void F_21 ( void )
{
#ifdef F_20
unsigned int V_14 = F_15 () ;
struct V_63 V_64 = {
. type = V_65 ,
. V_66 = { . V_67 = ( unsigned long ) & V_68 } ,
} ;
if ( V_14 == 0 ) {
#ifdef F_22
F_23 ( & V_69 ) ;
#endif
return;
}
F_12 ( F_24 ( V_70 , & V_64 ) ) ;
#endif
}
void T_3
F_25 ( void )
{
struct V_63 V_64 = {
. type = V_65 ,
. V_66 = { . V_67 = ( unsigned long ) & V_68 } ,
} ;
F_26 () ;
F_12 ( F_24 ( V_70 , & V_64 ) ) ;
V_71 = F_16 ;
}
void
F_27 ( int V_14 , int V_6 , int V_72 , int V_73 )
{
#ifdef F_20
if ( F_28 ( V_6 == V_74 ) ) {
F_19 ( V_14 ) ;
F_29 ( V_14 , V_6 ) ;
return;
}
#endif
switch ( V_6 ) {
case V_31 :
F_30 ( V_14 , V_33 ) ;
break;
case V_27 :
F_30 ( V_14 , V_29 ) ;
break;
case V_39 :
F_30 ( V_14 , V_41 ) ;
break;
case V_43 :
F_30 ( V_14 , V_45 ) ;
break;
case V_20 : {
static int V_75 = 0 ;
if ( ! V_75 ) {
F_29 ( V_14 , V_20 ) ;
V_75 = 1 ;
break;
}
}
default:
F_4 ( V_10 L_5 ,
V_6 ) ;
F_31 ( 0 ) ;
break;
}
}
static void T_3
F_32 ( void )
{
#ifdef F_20
F_33 ( V_31 , & V_76 ) ;
F_33 ( V_27 , & V_77 ) ;
F_33 ( V_78 , & V_79 ) ;
#endif
}
static void
F_34 ( unsigned int V_6 )
{
( void ) F_35 ( V_6 ) ;
}
