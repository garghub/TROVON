static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_3 * V_4 = 0 ;
T_3 * V_5 = 0 ;
T_4 * V_6 = 0 ;
T_5 V_7 = 0 ;
T_5 V_8 ;
T_6 V_9 ;
unsigned int V_10 ;
const T_7 * V_11 ;
T_8 V_12 ;
unsigned int V_13 ;
F_2 ( V_2 -> V_14 , V_15 , V_16 ) ;
F_3 ( V_2 -> V_14 , V_17 ) ;
if ( V_3 ) {
V_6 = F_4 ( V_3 , V_18 , V_1 , V_7 , - 1 ,
V_19 ) ;
V_4 = F_5 ( V_6 , V_20 ) ;
}
V_12 = F_6 ( V_1 , V_7 , & V_8 ) ;
V_9 = V_8 - V_7 ;
if ( V_9 != 0 ) {
if ( V_4 ) {
V_6 = F_7 ( V_4 , V_21 ,
V_1 , V_7 , V_9 , V_12 ) ;
V_5 = F_5 ( V_6 ,
V_22 ) ;
for ( V_10 = 0 ; V_10 < V_23 ; V_10 ++ ) {
F_8 ( V_5 , V_1 ,
V_7 , V_9 , L_1 ,
F_9 ( V_12 ,
V_24 [ V_10 ] . V_25 , sizeof ( V_12 ) * 8 ,
V_24 [ V_10 ] . V_26 ,
V_24 [ V_10 ] . V_27 ) ) ;
}
}
}
V_7 = V_8 ;
if ( ! F_10 ( V_1 , V_7 , & V_8 ) )
return;
V_7 = V_8 ;
V_13 = F_6 ( V_1 , V_7 , & V_8 ) ;
V_9 = V_8 - V_7 ;
if ( V_9 != 0 ) {
if ( V_4 )
F_7 ( V_4 , V_28 ,
V_1 , V_7 , V_9 , V_13 ) ;
}
V_7 = V_8 ;
if ( ! F_10 ( V_1 , V_7 , & V_8 ) )
return;
V_7 = V_8 ;
V_11 = F_11 ( V_1 , V_7 , & V_8 , & V_9 ) ;
if ( V_11 == NULL )
return;
if ( V_4 )
F_8 ( V_4 , V_1 , V_7 , V_9 ,
L_2 ,
( V_29 ) V_9 , V_11 ) ;
F_12 ( V_2 -> V_14 , V_17 ,
L_3 ,
( V_29 ) V_9 , V_11 ,
F_13 ( V_13 , V_30 , L_4 ) ) ;
V_7 = V_8 ;
if ( ! V_4 )
return;
if ( ! F_10 ( V_1 , V_7 , & V_8 ) )
return;
V_7 = V_8 ;
V_11 = F_14 ( V_1 , V_7 , & V_8 , & V_9 ) ;
if ( V_11 == NULL )
return;
F_8 ( V_4 , V_1 , V_7 + 1 , V_9 ,
L_5 ,
( V_29 ) V_9 , V_11 ) ;
V_7 = V_8 ;
if ( ! F_10 ( V_1 , V_7 , & V_8 ) )
return;
V_7 = V_8 ;
V_11 = F_14 ( V_1 , V_7 , & V_8 , & V_9 ) ;
if ( V_11 == NULL )
return;
F_8 ( V_4 , V_1 , V_7 + 1 , V_9 ,
L_6 ,
( V_29 ) V_9 , V_11 ) ;
V_7 = V_8 ;
if ( ! F_10 ( V_1 , V_7 , & V_8 ) )
return;
V_7 = V_8 ;
V_11 = F_14 ( V_1 , V_7 , & V_8 , & V_9 ) ;
if ( V_11 == NULL )
return;
F_8 ( V_4 , V_1 , V_7 + 1 , V_9 ,
L_7 ,
( V_29 ) V_9 , V_11 ) ;
V_7 = V_8 ;
return;
}
static T_6
F_6 ( T_1 * V_1 , T_5 V_7 , T_5 * V_8 )
{
int V_31 ;
T_6 V_10 = 0 ;
while ( isxdigit ( V_31 = F_15 ( V_1 , V_7 ) ) ) {
if ( isdigit ( V_31 ) )
V_31 -= '0' ;
else if ( isupper ( V_31 ) )
V_31 -= 'A' - 10 ;
else if ( islower ( V_31 ) )
V_31 -= 'a' - 10 ;
else
V_31 = 0 ;
V_10 = 16 * V_10 + V_31 ;
V_7 ++ ;
}
* V_8 = V_7 ;
return V_10 ;
}
static T_9
F_10 ( T_1 * V_1 , T_5 V_7 , T_5 * V_8 )
{
int V_31 ;
while ( ( V_31 = F_15 ( V_1 , V_7 ) ) == ' ' )
V_7 ++ ;
if ( V_31 == '\r' || V_31 == '\n' )
return FALSE ;
* V_8 = V_7 ;
return TRUE ;
}
static const T_7 *
F_14 ( T_1 * V_1 , T_5 V_7 , T_5 * V_8 , T_6 * V_9 )
{
int V_31 ;
const T_7 * V_32 = NULL ;
T_6 V_33 = 0 ;
T_5 V_34 ;
V_31 = F_15 ( V_1 , V_7 ) ;
if ( V_31 == '"' ) {
V_34 = F_16 ( V_1 , V_7 + 1 , - 1 , '"' ) ;
if ( V_34 != - 1 ) {
V_7 ++ ;
V_33 = V_34 - V_7 ;
V_32 = F_17 ( V_1 , V_7 , V_33 ) ;
V_7 = V_34 + 1 ;
}
}
* V_8 = V_7 ;
* V_9 = V_33 ;
return V_32 ;
}
static const T_7 *
F_11 ( T_1 * V_1 , T_5 V_7 , T_5 * V_8 , T_6 * V_9 )
{
const T_7 * V_32 = NULL ;
T_6 V_33 = 0 ;
T_5 V_34 ;
V_34 = F_18 ( V_1 , V_7 , - 1 , L_8 , NULL ) ;
if ( V_34 != - 1 ) {
V_33 = V_34 - V_7 ;
V_32 = F_17 ( V_1 , V_7 , V_33 ) ;
V_7 = V_34 ;
}
* V_8 = V_7 ;
* V_9 = V_33 ;
return V_32 ;
}
void
F_19 ( void )
{
static T_10 V_35 [] = {
{ & V_21 ,
{ L_9 , L_10 , V_36 , V_37 ,
NULL , 0x0 , NULL , V_38 } } ,
{ & V_28 ,
{ L_11 , L_12 , V_39 , V_37 ,
F_20 ( V_30 ) , 0x0 , NULL , V_38 } }
} ;
static T_5 * V_40 [] = {
& V_20 ,
& V_22
} ;
V_18 = F_21 (
L_13 ,
L_14 , L_15 ) ;
F_22 ( V_18 , V_35 , F_23 ( V_35 ) ) ;
F_24 ( V_40 , F_23 ( V_40 ) ) ;
}
void
F_25 ( void )
{
T_11 V_41 ;
V_41 = F_26 ( F_1 , V_18 ) ;
F_27 ( L_16 , V_42 , V_41 ) ;
}
