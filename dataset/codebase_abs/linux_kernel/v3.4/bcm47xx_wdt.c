static inline void F_1 ( void )
{
switch ( V_1 ) {
#ifdef F_2
case V_2 :
F_3 ( & V_3 . V_4 , 0xfffffff ) ;
break;
#endif
#ifdef F_4
case V_5 :
F_5 ( & V_3 . V_6 . V_7 . V_8 ,
0xfffffff ) ;
break;
#endif
}
}
static inline int F_6 ( void )
{
switch ( V_1 ) {
#ifdef F_2
case V_2 :
return F_3 ( & V_3 . V_4 , 0 ) ;
#endif
#ifdef F_4
case V_5 :
F_5 ( & V_3 . V_6 . V_7 . V_8 , 0 ) ;
return 0 ;
#endif
}
return - V_9 ;
}
static void F_7 ( unsigned long V_10 )
{
if ( ! F_8 ( & V_11 ) ) {
F_1 () ;
F_9 ( & V_12 , V_13 + V_14 ) ;
} else {
F_10 ( L_1 ) ;
}
}
static inline void F_11 ( void )
{
F_12 ( & V_11 , V_15 ) ;
}
static void F_13 ( void )
{
F_11 () ;
F_7 ( 0 ) ;
}
static void F_14 ( void )
{
F_15 ( & V_12 ) ;
F_6 () ;
}
static void F_16 ( void )
{
F_14 () ;
}
static int F_17 ( int V_16 )
{
if ( ( V_16 <= 0 ) || ( V_16 > V_17 ) )
return - V_9 ;
V_15 = V_16 ;
return 0 ;
}
static int F_18 ( struct V_18 * V_18 , struct V_19 * V_19 )
{
if ( F_19 ( 0 , & V_20 ) )
return - V_21 ;
F_13 () ;
return F_20 ( V_18 , V_19 ) ;
}
static int F_21 ( struct V_18 * V_18 , struct V_19 * V_19 )
{
if ( V_22 == 42 ) {
F_16 () ;
} else {
F_10 ( L_2 ) ;
F_13 () ;
}
F_22 ( 0 , & V_20 ) ;
V_22 = 0 ;
return 0 ;
}
static T_1 F_23 ( struct V_19 * V_19 , const char T_2 * V_23 ,
T_3 V_24 , T_4 * V_25 )
{
if ( V_24 ) {
if ( ! V_26 ) {
T_3 V_27 ;
V_22 = 0 ;
for ( V_27 = 0 ; V_27 != V_24 ; V_27 ++ ) {
char V_28 ;
if ( F_24 ( V_28 , V_23 + V_27 ) )
return - V_29 ;
if ( V_28 == 'V' )
V_22 = 42 ;
}
}
F_11 () ;
}
return V_24 ;
}
static long F_25 ( struct V_19 * V_19 ,
unsigned int V_30 , unsigned long V_31 )
{
void T_2 * V_32 = ( void T_2 * ) V_31 ;
int T_2 * V_33 = V_32 ;
int V_34 , V_35 = - V_9 ;
switch ( V_30 ) {
case V_36 :
return F_26 ( V_32 , & V_37 ,
sizeof( V_37 ) ) ? - V_29 : 0 ;
case V_38 :
case V_39 :
return F_27 ( 0 , V_33 ) ;
case V_40 :
if ( F_24 ( V_34 , V_33 ) )
return - V_29 ;
if ( V_34 & V_41 ) {
F_16 () ;
V_35 = 0 ;
}
if ( V_34 & V_42 ) {
F_13 () ;
V_35 = 0 ;
}
return V_35 ;
case V_43 :
F_11 () ;
return 0 ;
case V_44 :
if ( F_24 ( V_34 , V_33 ) )
return - V_29 ;
if ( F_17 ( V_34 ) )
return - V_9 ;
F_11 () ;
case V_45 :
return F_27 ( V_15 , V_33 ) ;
default:
return - V_46 ;
}
}
static int F_28 ( struct V_47 * V_48 ,
unsigned long V_49 , void * V_10 )
{
if ( V_49 == V_50 || V_49 == V_51 )
F_16 () ;
return V_52 ;
}
static int T_5 F_29 ( void )
{
int V_53 ;
if ( F_6 () < 0 )
return - V_54 ;
F_30 ( & V_12 , F_7 , 0L ) ;
if ( F_17 ( V_15 ) ) {
F_17 ( V_55 ) ;
F_31 ( L_3 ,
( V_17 + 1 ) , V_15 ) ;
}
V_53 = F_32 ( & V_56 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_33 ( & V_57 ) ;
if ( V_53 ) {
F_34 ( & V_56 ) ;
return V_53 ;
}
F_31 ( L_4 ,
V_15 , V_26 ? L_5 : L_6 ) ;
return 0 ;
}
static void T_6 F_35 ( void )
{
if ( ! V_26 )
F_16 () ;
F_36 ( & V_57 ) ;
F_34 ( & V_56 ) ;
}
