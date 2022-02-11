static void F_1 ( T_1 * V_1 )
{
switch ( F_2 ( V_1 ) ) {
case V_2 :
F_3 ( L_1 ) ;
break;
case V_3 :
F_4 ( L_2 ) ;
break;
default:
F_5 ( L_3 , F_2 ( V_1 ) ) ;
}
}
void F_6 ( void )
{
T_1 V_4 = F_7 ( V_3 - 1 ) ;
F_3 ( L_4 ) ;
F_8 ( & V_4 ) ;
F_9 ( & V_4 ) ;
F_3 ( L_5 ) ;
F_9 ( & V_4 ) ;
F_9 ( & V_4 ) ;
F_1 ( & V_4 ) ;
}
void F_10 ( void )
{
T_1 V_4 = F_7 ( V_3 - 1 ) ;
F_3 ( L_6 ) ;
F_8 ( & V_4 ) ;
F_8 ( & V_4 ) ;
F_8 ( & V_4 ) ;
F_8 ( & V_4 ) ;
F_11 ( 4 , & V_4 ) ;
F_3 ( L_7 ) ;
F_11 ( 4 , & V_4 ) ;
F_1 ( & V_4 ) ;
}
void F_12 ( void )
{
T_1 V_4 = F_7 ( V_3 ) ;
F_3 ( L_8 ) ;
if ( ! F_13 ( & V_4 ) )
F_4 ( L_9 ) ;
F_1 ( & V_4 ) ;
}
void F_14 ( void )
{
T_1 V_4 = F_7 ( V_3 ) ;
F_3 ( L_10 ) ;
if ( ! F_15 ( 6 , & V_4 ) )
F_4 ( L_11 ) ;
F_1 ( & V_4 ) ;
}
static void F_16 ( T_1 * V_1 )
{
switch ( F_2 ( V_1 ) ) {
case V_2 :
F_3 ( L_12 ) ;
break;
case V_3 :
F_4 ( L_13 ) ;
break;
case 0 :
F_4 ( L_14 ) ;
break;
default:
F_5 ( L_15 , F_2 ( V_1 ) ) ;
}
}
void F_17 ( void )
{
T_1 V_5 = F_7 ( 2 ) ;
F_3 ( L_16 ) ;
F_8 ( & V_5 ) ;
F_3 ( L_17 ) ;
F_8 ( & V_5 ) ;
F_16 ( & V_5 ) ;
}
static void F_18 ( T_1 * V_1 , int V_6 )
{
if ( F_2 ( V_1 ) == V_6 ) {
F_4 ( L_18 ,
V_6 ) ;
return;
}
switch ( F_2 ( V_1 ) ) {
case V_2 :
F_3 ( L_19 ) ;
break;
case V_3 :
F_4 ( L_20 ) ;
break;
default:
F_5 ( L_15 , F_2 ( V_1 ) ) ;
}
}
void F_19 ( void )
{
T_1 V_7 = F_7 ( 0 ) ;
F_3 ( L_21 ) ;
F_8 ( & V_7 ) ;
F_18 ( & V_7 , 0 ) ;
}
void F_20 ( void )
{
T_1 V_7 = F_7 ( 0 ) ;
F_3 ( L_22 ) ;
if ( F_21 ( & V_7 ) )
F_4 ( L_23 ) ;
F_18 ( & V_7 , 0 ) ;
}
void F_22 ( void )
{
T_1 V_7 = F_7 ( 3 ) ;
F_3 ( L_24 ) ;
if ( F_23 ( 5 , & V_7 ) )
F_4 ( L_25 ) ;
F_18 ( & V_7 , 3 ) ;
}
static void F_24 ( T_1 * V_1 )
{
switch ( F_2 ( V_1 ) ) {
case 0 :
F_3 ( L_26 ) ;
break;
case V_2 :
F_3 ( L_12 ) ;
break;
case V_3 :
F_4 ( L_13 ) ;
break;
default:
F_3 ( L_27 ,
F_2 ( V_1 ) ) ;
}
}
void F_25 ( void )
{
T_1 V_5 = F_7 ( 0 ) ;
F_3 ( L_28 ) ;
if ( ! F_13 ( & V_5 ) ) {
F_3 ( L_29 ) ;
if ( F_2 ( & V_5 ) == 0 )
F_3 ( L_30 ) ;
else
F_5 ( L_31 ) ;
} else {
F_5 ( L_32 ) ;
}
F_3 ( L_33 ) ;
F_9 ( & V_5 ) ;
F_24 ( & V_5 ) ;
}
void F_26 ( void )
{
T_1 V_5 = F_7 ( 0 ) ;
F_3 ( L_34 ) ;
if ( ! F_15 ( 3 , & V_5 ) ) {
F_3 ( L_29 ) ;
if ( F_2 ( & V_5 ) == 0 )
F_3 ( L_30 ) ;
else
F_5 ( L_35 ) ;
} else {
F_5 ( L_32 ) ;
}
F_3 ( L_36 ) ;
F_11 ( 3 , & V_5 ) ;
F_24 ( & V_5 ) ;
}
static void F_27 ( T_1 * V_1 )
{
switch ( F_2 ( V_1 ) ) {
case V_2 :
F_3 ( L_37 ) ;
break;
case V_3 :
F_4 ( L_38 ) ;
break;
default:
F_5 ( L_15 , F_2 ( V_1 ) ) ;
}
}
void F_28 ( void )
{
T_1 V_8 = F_7 ( V_2 ) ;
F_3 ( L_39 ) ;
F_9 ( & V_8 ) ;
F_27 ( & V_8 ) ;
}
void F_29 ( void )
{
T_1 V_8 = F_7 ( V_2 ) ;
F_3 ( L_40 ) ;
F_8 ( & V_8 ) ;
F_27 ( & V_8 ) ;
}
void F_30 ( void )
{
T_1 V_8 = F_7 ( V_2 ) ;
F_3 ( L_40 ) ;
F_11 ( 8 , & V_8 ) ;
F_27 ( & V_8 ) ;
}
void F_31 ( void )
{
T_1 V_8 = F_7 ( V_2 ) ;
F_3 ( L_41 ) ;
if ( ! F_13 ( & V_8 ) )
F_4 ( L_9 ) ;
F_27 ( & V_8 ) ;
}
void F_32 ( void )
{
T_1 V_8 = F_7 ( V_2 ) ;
F_3 ( L_42 ) ;
if ( ! F_15 ( 7 , & V_8 ) )
F_4 ( L_11 ) ;
F_27 ( & V_8 ) ;
}
void F_33 ( void )
{
T_1 V_8 = F_7 ( V_2 ) ;
F_3 ( L_43 ) ;
if ( F_21 ( & V_8 ) )
F_4 ( L_23 ) ;
F_27 ( & V_8 ) ;
}
void F_34 ( void )
{
T_1 V_8 = F_7 ( V_2 ) ;
F_3 ( L_44 ) ;
if ( F_23 ( 8 , & V_8 ) )
F_4 ( L_25 ) ;
F_27 ( & V_8 ) ;
}
void F_35 ( void )
{
unsigned int V_9 ;
T_2 V_10 = F_36 ( 1 ) ;
for ( V_9 = 0 ; V_9 < V_11 - 1 ; V_9 ++ )
F_37 ( & V_10 ) ;
for ( V_9 = V_11 ; V_9 > 0 ; V_9 -- )
if ( F_38 ( & V_10 ) )
break;
if ( V_9 != 1 )
F_5 ( L_45 , V_9 - 1 ) ;
else
F_3 ( L_46 ) ;
}
void F_39 ( void )
{
unsigned int V_9 ;
T_1 V_10 = F_7 ( 1 ) ;
for ( V_9 = 0 ; V_9 < V_11 - 1 ; V_9 ++ )
F_9 ( & V_10 ) ;
for ( V_9 = V_11 ; V_9 > 0 ; V_9 -- )
if ( F_21 ( & V_10 ) )
break;
if ( V_9 != 1 )
F_5 ( L_47 , V_9 - 1 ) ;
else
F_3 ( L_48 ) ;
}
