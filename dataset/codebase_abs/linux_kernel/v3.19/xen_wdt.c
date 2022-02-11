static inline T_1 F_1 ( void )
{
V_1 . V_2 = V_2 ;
return F_2 ( F_3 () ) . V_3 + V_2 ;
}
static int F_4 ( void )
{
T_1 V_4 ;
int V_5 ;
F_5 ( & V_6 ) ;
V_4 = F_1 () ;
if ( ! V_1 . V_7 )
V_5 = F_6 ( V_8 , & V_1 ) ;
else
V_5 = - V_9 ;
if ( V_5 > 0 ) {
V_1 . V_7 = V_5 ;
V_10 = V_4 ;
V_5 = 0 ;
} else
F_7 ( ! V_5 ) ;
F_8 ( & V_6 ) ;
return V_5 ;
}
static int F_9 ( void )
{
int V_5 = 0 ;
F_5 ( & V_6 ) ;
V_1 . V_2 = 0 ;
if ( V_1 . V_7 )
V_5 = F_6 ( V_8 , & V_1 ) ;
if ( ! V_5 )
V_1 . V_7 = 0 ;
F_8 ( & V_6 ) ;
return V_5 ;
}
static int F_10 ( void )
{
T_1 V_4 ;
int V_5 ;
F_5 ( & V_6 ) ;
V_4 = F_1 () ;
if ( V_1 . V_7 )
V_5 = F_6 ( V_8 , & V_1 ) ;
else
V_5 = - V_11 ;
if ( ! V_5 )
V_10 = V_4 ;
F_8 ( & V_6 ) ;
return V_5 ;
}
static int F_11 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
int V_5 ;
if ( F_12 ( & V_14 , true ) )
return - V_9 ;
V_5 = F_4 () ;
if ( V_5 == - V_9 )
V_5 = F_10 () ;
return V_5 ? : F_13 ( V_12 , V_13 ) ;
}
static int F_14 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
int V_5 = 0 ;
if ( V_15 )
V_5 = F_9 () ;
else {
F_15 ( L_1 ) ;
F_10 () ;
}
V_14 = V_5 ;
V_15 = false ;
return V_5 ;
}
static T_2 F_16 ( struct V_13 * V_13 , const char T_3 * V_16 ,
T_4 V_17 , T_5 * V_18 )
{
if ( V_17 ) {
if ( ! V_19 ) {
T_4 V_20 ;
V_15 = false ;
for ( V_20 = 0 ; V_20 != V_17 ; V_20 ++ ) {
char V_21 ;
if ( F_17 ( V_21 , V_16 + V_20 ) )
return - V_22 ;
if ( V_21 == 'V' )
V_15 = true ;
}
}
F_10 () ;
}
return V_17 ;
}
static long F_18 ( struct V_13 * V_13 , unsigned int V_23 ,
unsigned long V_24 )
{
int V_25 , V_26 = - V_27 ;
int V_28 ;
int T_3 * V_29 = ( void T_3 * ) V_24 ;
static const struct V_30 V_31 = {
. V_32 = V_33 | V_34 ,
. V_35 = 0 ,
. V_36 = V_37 ,
} ;
switch ( V_23 ) {
case V_38 :
return F_19 ( V_29 , & V_31 , sizeof( V_31 ) ) ? - V_22 : 0 ;
case V_39 :
case V_40 :
return F_20 ( 0 , V_29 ) ;
case V_41 :
if ( F_17 ( V_25 , V_29 ) )
return - V_22 ;
if ( V_25 & V_42 )
V_26 = F_9 () ;
if ( V_25 & V_43 ) {
V_26 = F_4 () ;
if ( V_26 == - V_9 )
V_26 = F_10 () ;
}
return V_26 ;
case V_44 :
F_10 () ;
return 0 ;
case V_45 :
if ( F_17 ( V_28 , V_29 ) )
return - V_22 ;
if ( ! V_28 )
return - V_27 ;
V_2 = V_28 ;
F_10 () ;
case V_46 :
return F_20 ( V_2 , V_29 ) ;
case V_47 :
V_26 = V_10 - F_2 ( F_3 () ) . V_3 ;
return F_20 ( V_26 , V_29 ) ;
}
return - V_48 ;
}
static int F_21 ( struct V_49 * V_50 )
{
struct V_51 V_52 = { . V_7 = ~ 0 } ;
int V_53 = F_6 ( V_8 , & V_52 ) ;
switch ( V_53 ) {
case - V_27 :
if ( ! V_2 ) {
V_2 = V_54 ;
F_22 ( L_2 , V_2 ) ;
}
V_53 = F_23 ( & V_55 ) ;
if ( V_53 ) {
F_24 ( L_3 ,
V_56 , V_53 ) ;
break;
}
F_22 ( L_4 ,
V_2 , V_19 ) ;
break;
case - V_57 :
F_22 ( L_5 ) ;
V_53 = - V_58 ;
break;
default:
F_22 ( L_6 , V_53 ) ;
break;
}
return V_53 ;
}
static int F_25 ( struct V_49 * V_50 )
{
if ( ! V_19 )
F_9 () ;
F_26 ( & V_55 ) ;
return 0 ;
}
static void F_27 ( struct V_49 * V_50 )
{
F_9 () ;
}
static int F_28 ( struct V_49 * V_50 , T_6 V_59 )
{
F_29 (wdt.id) V_7 = V_1 . V_7 ;
int V_60 = F_9 () ;
V_1 . V_7 = V_7 ;
return V_60 ;
}
static int F_30 ( struct V_49 * V_50 )
{
if ( ! V_1 . V_7 )
return 0 ;
V_1 . V_7 = 0 ;
return F_4 () ;
}
static int T_7 F_31 ( void )
{
int V_5 ;
if ( ! F_32 () )
return - V_58 ;
F_22 ( L_7 , V_61 ) ;
V_5 = F_33 ( & V_62 ) ;
if ( V_5 )
return V_5 ;
V_49 = F_34 ( V_37 ,
- 1 , NULL , 0 ) ;
if ( F_35 ( V_49 ) ) {
V_5 = F_36 ( V_49 ) ;
F_37 ( & V_62 ) ;
}
return V_5 ;
}
static void T_8 F_38 ( void )
{
F_39 ( V_49 ) ;
F_37 ( & V_62 ) ;
F_22 ( L_8 ) ;
}
