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
F_16 () ;
memset ( & V_20 -> V_25 . V_26 , 0 , sizeof( struct V_26 ) ) ;
F_17 ( V_20 ) ;
F_18 ( V_24 ) ;
F_19 () ;
}
void F_20 ( void )
{
if ( ! F_7 () )
return;
F_16 () ;
if ( ! F_8 ( V_24 ) )
F_9 ( & V_20 -> V_25 . V_26 ) ;
F_19 () ;
}
void F_21 ( void )
{
if ( ! F_7 () )
return;
F_16 () ;
if ( F_22 ( V_24 ) ) {
struct V_26 * V_27 = & V_20 -> V_25 . V_26 ;
F_23 ( V_27 ) ;
F_24 ( V_28 , V_27 ) ;
V_27 -> V_29 = F_11 () ;
}
F_19 () ;
}
void F_25 ( struct V_26 * V_30 )
{
if ( ! F_7 () )
return;
F_16 () ;
F_23 ( V_30 ) ;
if ( F_22 ( V_24 ) ) {
struct V_26 * V_27 = & V_20 -> V_25 . V_26 ;
F_24 ( V_28 , V_27 ) ;
V_27 -> V_29 = F_11 () ;
}
F_19 () ;
}
void F_17 ( struct V_21 * V_31 )
{
V_31 -> V_25 . V_26 . V_29 = V_32 ;
}
void F_26 ( void )
{
if ( F_2 ( ! F_7 () ) )
return;
F_27 ( ! F_28 () ) ;
F_16 () ;
F_24 ( V_33 , true ) ;
if ( V_20 -> V_23 && ! F_29 ( V_24 ) )
F_9 ( & V_20 -> V_25 . V_26 ) ;
F_24 ( V_28 , NULL ) ;
F_30 () ;
F_19 () ;
}
void F_31 ( void )
{
bool V_34 ;
if ( ! F_7 () )
return;
V_34 = F_32 ( V_33 , false ) ;
F_2 ( ! V_34 ) ;
F_33 () ;
}
void F_34 ( void )
{
if ( ! F_7 () )
return;
F_2 ( F_35 () ) ;
if ( F_28 () )
F_26 () ;
else {
F_9 ( F_36 ( & V_35 ) ) ;
F_24 ( V_36 , true ) ;
}
}
void F_37 ( void )
{
if ( ! F_7 () )
return;
if ( F_32 ( V_36 , false ) )
F_23 ( F_36 ( & V_35 ) ) ;
else
F_31 () ;
}
static int F_38 ( struct V_37 * V_38 ,
unsigned long V_39 , void * V_40 )
{
switch ( V_39 ) {
case V_41 :
if ( V_20 -> V_23 && ! F_8 ( V_24 ) )
F_9 ( & V_20 -> V_25 . V_26 ) ;
F_39 ( V_28 , NULL ) ;
break;
case V_42 :
if ( V_20 -> V_23 )
F_18 ( V_24 ) ;
break;
case V_43 :
default:
return V_44 ;
}
return V_45 ;
}
static void T_2 F_40 ( void )
{
F_41 ( & V_46 ) ;
}
static inline void F_40 ( void ) { }
static int F_42 ( unsigned int V_29 )
{
F_43 ( V_28 , V_29 ) = NULL ;
return 0 ;
}
static inline void F_44 ( void )
{
F_45 ( V_47 , L_1 ,
NULL , F_42 ) ;
}
static inline void F_44 ( void ) { }
static int T_2 F_46 ( void )
{
if ( V_48 & V_49 ) {
F_40 () ;
F_44 () ;
} else {
F_47 ( L_2 ) ;
}
if ( ! ( V_48 & V_50 ) )
F_47 ( L_3 ) ;
return 0 ;
}
