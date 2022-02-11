static T_1
F_1 ( T_2 V_1 , T_3 V_2 , void * V_3 ,
void * * V_4 )
{
long * V_5 = V_3 ;
if ( F_2 ( V_1 , L_1 ) &&
F_2 ( V_1 , L_2 ) ) {
F_3 ( ( V_6 , L_3
L_4 ) ) ;
* V_5 |= V_7 ;
if ( ! F_2 ( V_1 , L_5 ) )
F_4 (KERN_WARNING FW_BUG PREFIX L_6
L_7 ) ;
return V_8 ;
}
return 0 ;
}
long F_5 ( T_2 V_1 )
{
long V_9 = 0 ;
if ( F_2 ( V_1 , L_8 ) || F_2 ( V_1 , L_9 ) )
V_9 |= V_10 ;
if ( F_2 ( V_1 , L_10 ) )
V_9 |= V_11 ;
if ( F_2 ( V_1 , L_11 ) &&
F_2 ( V_1 , L_12 ) &&
F_2 ( V_1 , L_13 ) )
V_9 |= V_12 ;
if ( V_9 )
F_6 ( V_13 , V_1 ,
V_14 , F_1 , NULL ,
& V_9 , NULL ) ;
return V_9 ;
}
static T_1
F_7 ( T_2 V_1 , T_3 V_15 , void * V_3 , void * * V_16 )
{
long * V_5 = V_3 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
const struct V_21 V_22 [] = {
{ V_23 , 0 } ,
{ L_14 , 0 } ,
} ;
if ( F_8 ( V_1 , & V_20 ) )
return V_24 ;
if ( ! F_9 ( V_20 , V_22 ) ) {
V_18 = F_10 ( V_1 ) ;
if ( ! V_18 )
return V_24 ;
F_11 ( V_18 ) ;
* V_5 |= F_5 ( V_1 ) ;
}
return V_24 ;
}
static int F_12 ( const struct V_25 * V_26 )
{
V_27 |= V_28 ;
return 0 ;
}
long F_13 ( T_2 V_29 )
{
long V_30 = 0 ;
struct V_19 * V_31 ;
T_1 V_32 ;
if ( V_33 && V_29 == NULL )
return V_27 ;
if ( ! V_29 ) {
F_6 ( V_13 , V_34 ,
V_14 , F_7 , NULL ,
& V_30 , NULL ) ;
V_27 |= V_30 ;
V_33 = 1 ;
F_14 ( V_35 ) ;
} else {
V_32 = F_8 ( V_29 , & V_31 ) ;
if ( F_15 ( V_32 ) ) {
F_16 ( ( V_36 , V_32 , L_15 ) ) ;
return 0 ;
}
F_6 ( V_13 , V_29 ,
V_14 , F_7 , NULL ,
& V_30 , NULL ) ;
}
F_3 ( ( V_6 , L_16 ,
V_29 ? V_30 : V_27 ,
V_29 ? L_17 : L_18 ,
V_29 ? F_17 ( V_31 ) : L_14 ) ) ;
return V_30 ;
}
static void F_18 ( void )
{
if ( ! V_33 )
F_13 ( NULL ) ;
}
bool F_19 ( void )
{
return V_37 >= V_38 ;
}
void F_20 ( void )
{
F_18 () ;
V_27 |= V_28 ;
}
void F_21 ( void )
{
F_18 () ;
V_27 &= ~ V_28 ;
}
int F_22 ( void )
{
F_18 () ;
if ( V_27 & V_39 )
return 0 ;
else if ( V_27 & V_40 )
return 1 ;
if ( V_27 & V_28 )
return 0 ;
else if ( V_27 & V_41 )
return 1 ;
return V_27 & V_7 ;
}
static int T_4 F_23 ( char * V_42 )
{
if ( V_42 == NULL || * V_42 == '\0' )
return 1 ;
else {
if ( ! strcmp ( L_19 , V_42 ) )
V_27 |=
V_39 ;
if ( ! strcmp ( L_20 , V_42 ) )
V_27 |=
V_40 ;
}
return 1 ;
}
