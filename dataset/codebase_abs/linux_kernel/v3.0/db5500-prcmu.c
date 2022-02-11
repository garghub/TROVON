int F_1 ( T_1 V_1 , T_1 V_2 , T_1 * V_3 , T_1 V_4 )
{
int V_5 ;
if ( ( V_4 < 1 ) || ( 4 < V_4 ) )
return - V_6 ;
F_2 ( & V_7 . V_8 ) ;
while ( F_3 ( V_9 ) & F_4 ( 5 ) )
F_5 () ;
F_6 ( V_1 , V_10 ) ;
F_6 ( V_2 , V_11 ) ;
F_6 ( V_4 , V_12 ) ;
F_6 ( V_13 , V_14 ) ;
F_7 ( F_4 ( 5 ) , V_15 ) ;
F_8 ( & V_7 . V_16 ) ;
V_5 = 0 ;
if ( ( V_7 . V_17 . V_18 == V_13 ) &&
( V_7 . V_17 . V_19 == V_20 ) )
memcpy ( V_3 , V_7 . V_17 . V_3 , ( V_21 ) V_4 ) ;
else
V_5 = - V_22 ;
F_9 ( & V_7 . V_8 ) ;
return V_5 ;
}
int F_10 ( T_1 V_1 , T_1 V_2 , T_1 * V_3 , T_1 V_4 )
{
int V_5 ;
if ( ( V_4 < 1 ) || ( 4 < V_4 ) )
return - V_6 ;
F_2 ( & V_7 . V_8 ) ;
while ( F_3 ( V_9 ) & F_4 ( 5 ) )
F_5 () ;
F_6 ( V_1 , V_10 ) ;
F_6 ( V_2 , V_11 ) ;
F_6 ( V_4 , V_12 ) ;
F_11 ( V_23 , V_3 , V_4 ) ;
F_6 ( V_24 , V_14 ) ;
F_7 ( F_4 ( 5 ) , V_15 ) ;
F_8 ( & V_7 . V_16 ) ;
if ( ( V_7 . V_17 . V_18 == V_24 ) &&
( V_7 . V_17 . V_19 == V_20 ) )
V_5 = 0 ;
else
V_5 = - V_22 ;
F_9 ( & V_7 . V_8 ) ;
return V_5 ;
}
int F_12 ( void )
{
int V_25 ;
F_7 ( V_26 , V_27 ) ;
F_7 ( V_28 , V_29 ) ;
F_7 ( V_30 , V_31 ) ;
F_7 ( V_32 ,
V_33 ) ;
F_7 ( V_34 , V_35 ) ;
F_7 ( V_36 , V_37 ) ;
F_7 ( V_38 , V_39 ) ;
for ( V_25 = 0 ; V_25 < 10 ; V_25 ++ ) {
if ( ( F_3 ( V_40 ) &
V_41 ) == V_41 )
break;
F_13 ( 100 ) ;
}
F_7 ( V_26 , V_42 ) ;
return 0 ;
}
int F_14 ( void )
{
F_7 ( V_43 , V_37 ) ;
F_7 ( V_44 , V_35 ) ;
return 0 ;
}
int F_15 ( void )
{
F_7 ( V_45 , V_46 ) ;
F_7 ( V_47 , V_48 ) ;
return 0 ;
}
static void F_16 ( void )
{
unsigned long V_49 ;
F_17 ( & V_50 . V_8 , V_49 ) ;
while ( F_3 ( V_9 ) & F_4 ( 0 ) )
F_5 () ;
F_6 ( V_51 , V_52 ) ;
F_7 ( F_4 ( 0 ) , V_15 ) ;
F_18 ( & V_50 . V_8 , V_49 ) ;
}
static inline void F_19 ( T_1 V_53 , T_1 V_18 )
{
F_20 ( L_1 ,
V_18 , V_53 ) ;
}
static bool F_21 ( void )
{
bool V_5 ;
T_1 V_18 ;
V_18 = F_22 ( V_54 ) ;
switch ( V_18 ) {
case V_55 :
V_5 = true ;
break;
default:
F_19 ( 0 , V_18 ) ;
V_5 = false ;
break;
}
F_7 ( F_4 ( 0 ) , V_56 ) ;
return V_5 ;
}
static bool F_23 ( void )
{
F_7 ( F_4 ( 1 ) , V_56 ) ;
return false ;
}
static bool F_24 ( void )
{
F_7 ( F_4 ( 2 ) , V_56 ) ;
return false ;
}
static bool F_25 ( void )
{
F_7 ( F_4 ( 3 ) , V_56 ) ;
return false ;
}
static bool F_26 ( void )
{
F_7 ( F_4 ( 4 ) , V_56 ) ;
return false ;
}
static bool F_27 ( void )
{
T_1 V_18 ;
V_18 = F_22 ( V_57 ) ;
switch ( V_18 ) {
case V_13 :
F_28 ( V_7 . V_17 . V_3 , V_58 , 4 ) ;
case V_24 :
V_7 . V_17 . V_18 = V_18 ;
V_7 . V_17 . V_19 = F_22 ( V_59 ) ;
F_29 ( & V_7 . V_16 ) ;
break;
default:
F_19 ( 5 , V_18 ) ;
break;
}
F_7 ( F_4 ( 5 ) , V_56 ) ;
return false ;
}
static bool F_30 ( void )
{
F_7 ( F_4 ( 6 ) , V_56 ) ;
return false ;
}
static bool F_31 ( void )
{
F_7 ( F_4 ( 7 ) , V_56 ) ;
return false ;
}
static T_2 F_32 ( int V_60 , void * V_61 )
{
T_3 V_62 ;
T_1 V_53 ;
T_2 V_5 ;
V_62 = ( F_3 ( V_63 ) & V_64 ) ;
if ( F_33 ( ! V_62 ) )
return V_65 ;
V_5 = V_66 ;
for ( V_53 = 0 ; V_62 ; V_53 ++ ) {
if ( V_62 & F_4 ( V_53 ) ) {
V_62 -= F_4 ( V_53 ) ;
if ( V_67 [ V_53 ] ( ) )
V_5 = V_68 ;
}
}
return V_5 ;
}
static T_2 F_34 ( int V_60 , void * V_61 )
{
F_16 () ;
return V_66 ;
}
void T_4 F_35 ( void )
{
V_69 = F_36 ( V_70 ) ;
F_37 ( & V_50 . V_8 ) ;
F_38 ( & V_7 . V_8 ) ;
F_39 ( & V_7 . V_16 ) ;
}
int T_4 F_40 ( void )
{
int V_5 = 0 ;
if ( F_41 () || ! F_42 () )
return - V_71 ;
F_7 ( V_64 , V_56 ) ;
V_5 = F_43 ( V_72 , F_32 ,
F_34 , 0 , L_2 , NULL ) ;
if ( V_5 < 0 ) {
F_44 ( L_3 ) ;
return - V_73 ;
}
return 0 ;
}
