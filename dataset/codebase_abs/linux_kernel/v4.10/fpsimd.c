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
if ( ! F_7 () )
return;
if ( V_20 -> V_23 && ! F_8 ( V_24 ) )
F_9 ( & V_20 -> V_25 . V_26 ) ;
if ( V_22 -> V_23 ) {
struct V_26 * V_27 = & V_22 -> V_25 . V_26 ;
if ( F_10 ( V_28 ) == V_27
&& V_27 -> V_29 == F_11 () )
F_12 ( F_13 ( V_22 ) ,
V_24 ) ;
else
F_14 ( F_13 ( V_22 ) ,
V_24 ) ;
}
}
void F_15 ( void )
{
if ( ! F_7 () )
return;
memset ( & V_20 -> V_25 . V_26 , 0 , sizeof( struct V_26 ) ) ;
F_16 ( V_20 ) ;
F_17 ( V_24 ) ;
}
void F_18 ( void )
{
if ( ! F_7 () )
return;
F_19 () ;
if ( ! F_8 ( V_24 ) )
F_9 ( & V_20 -> V_25 . V_26 ) ;
F_20 () ;
}
void F_21 ( void )
{
if ( ! F_7 () )
return;
F_19 () ;
if ( F_22 ( V_24 ) ) {
struct V_26 * V_27 = & V_20 -> V_25 . V_26 ;
F_23 ( V_27 ) ;
F_24 ( V_28 , V_27 ) ;
V_27 -> V_29 = F_11 () ;
}
F_20 () ;
}
void F_25 ( struct V_26 * V_30 )
{
if ( ! F_7 () )
return;
F_19 () ;
F_23 ( V_30 ) ;
if ( F_22 ( V_24 ) ) {
struct V_26 * V_27 = & V_20 -> V_25 . V_26 ;
F_24 ( V_28 , V_27 ) ;
V_27 -> V_29 = F_11 () ;
}
F_20 () ;
}
void F_16 ( struct V_21 * V_31 )
{
V_31 -> V_25 . V_26 . V_29 = V_32 ;
}
void F_26 ( T_2 V_33 )
{
if ( F_2 ( ! F_7 () ) )
return;
if ( F_27 () ) {
struct V_34 * V_35 = F_28 (
F_29 () ? & V_36 : & V_37 ) ;
F_30 ( V_33 > 32 ) ;
F_31 ( V_35 , F_32 ( V_33 , 2 ) ) ;
} else {
F_19 () ;
if ( V_20 -> V_23 &&
! F_33 ( V_24 ) )
F_9 ( & V_20 -> V_25 . V_26 ) ;
F_24 ( V_28 , NULL ) ;
}
}
void F_34 ( void )
{
if ( ! F_7 () )
return;
if ( F_27 () ) {
struct V_34 * V_35 = F_28 (
F_29 () ? & V_36 : & V_37 ) ;
F_35 ( V_35 ) ;
} else {
F_20 () ;
}
}
static int F_36 ( struct V_38 * V_39 ,
unsigned long V_40 , void * V_41 )
{
switch ( V_40 ) {
case V_42 :
if ( V_20 -> V_23 && ! F_8 ( V_24 ) )
F_9 ( & V_20 -> V_25 . V_26 ) ;
F_24 ( V_28 , NULL ) ;
break;
case V_43 :
if ( V_20 -> V_23 )
F_17 ( V_24 ) ;
break;
case V_44 :
default:
return V_45 ;
}
return V_46 ;
}
static void T_3 F_37 ( void )
{
F_38 ( & V_47 ) ;
}
static inline void F_37 ( void ) { }
static int F_39 ( unsigned int V_29 )
{
F_40 ( V_28 , V_29 ) = NULL ;
return 0 ;
}
static inline void F_41 ( void )
{
F_42 ( V_48 , L_1 ,
NULL , F_39 ) ;
}
static inline void F_41 ( void ) { }
static int T_3 F_43 ( void )
{
if ( V_49 & V_50 ) {
F_37 () ;
F_41 () ;
} else {
F_44 ( L_2 ) ;
}
if ( ! ( V_49 & V_51 ) )
F_44 ( L_3 ) ;
return 0 ;
}
