void F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
F_2 ( 1 ) ;
}
void F_3 ( unsigned int V_1 , struct V_2 * V_3 )
{
T_1 V_4 ;
unsigned int V_5 = 0 ;
if ( V_1 & V_6 )
V_5 = V_7 ;
else if ( V_1 & V_8 )
V_5 = V_9 ;
else if ( V_1 & V_10 )
V_5 = V_11 ;
else if ( V_1 & V_12 )
V_5 = V_13 ;
else if ( V_1 & V_14 )
V_5 = V_15 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_16 = V_17 ;
V_4 . V_5 = V_5 ;
V_4 . V_18 = ( void V_19 * ) F_4 ( V_3 ) ;
F_5 ( V_17 , & V_4 , V_20 ) ;
}
void F_6 ( struct V_21 * V_22 )
{
if ( V_20 -> V_23 && ! F_7 ( V_24 ) )
F_8 ( & V_20 -> V_25 . V_26 ) ;
if ( V_22 -> V_23 ) {
struct V_26 * V_27 = & V_22 -> V_25 . V_26 ;
if ( F_9 ( V_28 ) == V_27
&& V_27 -> V_29 == F_10 () )
F_11 ( F_12 ( V_22 ) ,
V_24 ) ;
else
F_13 ( F_12 ( V_22 ) ,
V_24 ) ;
}
}
void F_14 ( void )
{
memset ( & V_20 -> V_25 . V_26 , 0 , sizeof( struct V_26 ) ) ;
F_15 ( V_20 ) ;
F_16 ( V_24 ) ;
}
void F_17 ( void )
{
F_18 () ;
if ( ! F_7 ( V_24 ) )
F_8 ( & V_20 -> V_25 . V_26 ) ;
F_19 () ;
}
void F_20 ( void )
{
F_18 () ;
if ( F_21 ( V_24 ) ) {
struct V_26 * V_27 = & V_20 -> V_25 . V_26 ;
F_22 ( V_27 ) ;
F_23 ( V_28 , V_27 ) ;
V_27 -> V_29 = F_10 () ;
}
F_19 () ;
}
void F_24 ( struct V_26 * V_30 )
{
F_18 () ;
F_22 ( V_30 ) ;
if ( F_21 ( V_24 ) ) {
struct V_26 * V_27 = & V_20 -> V_25 . V_26 ;
F_23 ( V_28 , V_27 ) ;
V_27 -> V_29 = F_10 () ;
}
F_19 () ;
}
void F_15 ( struct V_21 * V_31 )
{
V_31 -> V_25 . V_26 . V_29 = V_32 ;
}
void F_25 ( T_2 V_33 )
{
if ( F_26 () ) {
struct V_34 * V_35 = F_27 (
F_28 () ? & V_36 : & V_37 ) ;
F_29 ( V_33 > 32 ) ;
F_30 ( V_35 , F_31 ( V_33 , 2 ) ) ;
} else {
F_18 () ;
if ( V_20 -> V_23 &&
! F_32 ( V_24 ) )
F_8 ( & V_20 -> V_25 . V_26 ) ;
F_23 ( V_28 , NULL ) ;
}
}
void F_33 ( void )
{
if ( F_26 () ) {
struct V_34 * V_35 = F_27 (
F_28 () ? & V_36 : & V_37 ) ;
F_34 ( V_35 ) ;
} else {
F_19 () ;
}
}
static int F_35 ( struct V_38 * V_39 ,
unsigned long V_40 , void * V_41 )
{
switch ( V_40 ) {
case V_42 :
if ( V_20 -> V_23 && ! F_7 ( V_24 ) )
F_8 ( & V_20 -> V_25 . V_26 ) ;
F_23 ( V_28 , NULL ) ;
break;
case V_43 :
if ( V_20 -> V_23 )
F_16 ( V_24 ) ;
break;
case V_44 :
default:
return V_45 ;
}
return V_46 ;
}
static void F_36 ( void )
{
F_37 ( & V_47 ) ;
}
static inline void F_36 ( void ) { }
static int F_38 ( struct V_38 * V_48 ,
unsigned long V_49 ,
void * V_50 )
{
unsigned int V_29 = ( long ) V_50 ;
switch ( V_49 ) {
case V_51 :
case V_52 :
F_39 ( V_28 , V_29 ) = NULL ;
break;
}
return V_46 ;
}
static inline void F_40 ( void )
{
F_41 ( & V_53 ) ;
}
static inline void F_40 ( void ) { }
static int T_3 F_42 ( void )
{
if ( V_54 & V_55 ) {
F_36 () ;
F_40 () ;
} else {
F_43 ( L_1 ) ;
}
if ( ! ( V_54 & V_56 ) )
F_43 ( L_2 ) ;
return 0 ;
}
