T_1 F_1 ( void )
{
return F_2 ( V_1 ) ;
}
T_2 * F_3 ( int type )
{
int V_2 = F_2 ( V_1 ) ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ ) {
if ( V_1 [ V_3 ] . V_4 == type ) {
return & V_1 [ V_3 ] ;
}
}
fprintf ( V_5 , L_1 ,
type ) ;
return NULL ;
}
void F_4 ( T_2 * V_6 , T_3 V_7 )
{
T_1 V_3 ;
int V_8 ;
int V_9 ;
int V_10 ;
int V_11 ;
T_4 * V_12 ;
union V_13 * V_14 ;
T_5 V_15 [ 65536 ] ;
struct V_16 * V_17 ;
V_17 = F_5 ( struct V_16 , 1 ) ;
V_17 -> V_18 = V_19 ;
V_17 -> V_20 = V_21 ;
V_17 -> V_22 = V_6 -> V_23 ;
memset ( V_17 , 0 , sizeof( struct V_16 ) ) ;
memset ( V_15 , 0 , sizeof( V_15 ) ) ;
V_14 = & V_17 -> V_24 ;
if ( V_6 -> V_25 )
memcpy ( V_14 , V_6 -> V_25 , V_6 -> V_26 ) ;
if ( V_6 -> V_27 )
memcpy ( V_15 , V_6 -> V_27 , V_6 -> V_28 ) ;
for ( V_3 = 0 ; V_3 < V_7 ; V_3 ++ ) {
if ( V_6 -> V_29 > 0 ) {
V_10 = ( rand () % V_6 -> V_29 + 1 ) ;
}
else {
V_10 = 0 ;
}
V_11 = V_6 -> V_28 + V_10 ;
V_17 -> V_30 = V_11 ;
V_17 -> V_31 = V_11 ;
V_17 -> V_32 . V_33 = V_3 ;
for ( V_8 = V_6 -> V_26 ; V_8 < ( int ) sizeof( * V_14 ) ; V_8 ++ ) {
( ( T_5 * ) V_14 ) [ V_8 ] = ( rand () % 0x100 ) ;
}
for ( V_8 = V_6 -> V_28 ; V_8 < V_11 ; V_8 ++ ) {
if ( ( int ) ( 100.0 * rand () / ( V_34 + 1.0 ) ) < 3 && V_8 < ( V_10 - 3 ) ) {
memcpy ( & V_15 [ V_8 ] , L_2 , 3 ) ;
V_8 += 2 ;
} else {
V_15 [ V_8 ] = ( rand () % 0x100 ) ;
}
}
if ( ! F_6 ( V_6 -> V_35 , V_17 , V_15 , & V_9 , & V_12 ) ) {
fprintf ( V_5 , L_3 ,
V_6 -> V_36 , F_7 ( V_9 ) ) ;
switch ( V_9 ) {
case V_37 :
fprintf ( V_5 ,
L_4 ,
F_8 ( V_38 ) ) ;
break;
case V_39 :
fprintf ( V_5 ,
L_5 ,
F_8 ( V_38 ) ) ;
break;
case V_40 :
fprintf ( V_5 ,
L_6 ,
F_8 ( V_38 ) ) ;
break;
case V_41 :
fprintf ( V_5 ,
L_7 ,
F_8 ( V_38 ) ,
V_12 != NULL ? V_12 : L_8 ) ;
F_9 ( V_12 ) ;
break;
default:
break;
}
}
}
F_9 ( V_17 ) ;
}
T_6 F_10 ( T_2 * V_6 )
{
int V_9 ;
if ( ! F_11 ( V_6 -> V_35 , & V_9 ) ) {
fprintf ( V_5 , L_9 ,
V_6 -> V_36 , F_7 ( V_9 ) ) ;
return FALSE ;
}
return TRUE ;
}
void F_12 ( T_2 * V_6 , char * V_42 , int V_29 )
{
int V_9 ;
if ( strcmp ( V_42 , L_10 ) == 0 ) {
V_6 -> V_35 = F_13 ( V_38 ,
V_6 -> V_23 , V_29 , FALSE , & V_9 ) ;
V_6 -> V_36 = L_11 ;
} else {
V_6 -> V_35 = F_14 ( V_42 , V_38 ,
V_6 -> V_23 , V_29 , FALSE , & V_9 ) ;
V_6 -> V_36 = V_42 ;
}
if ( ! V_6 -> V_35 ) {
fprintf ( V_5 , L_12 , V_6 -> V_36 ) ;
exit ( 2 ) ;
}
if ( V_29 <= V_6 -> V_28 ) {
fprintf ( V_5 , L_13
L_14 , V_6 -> V_28 ) ;
fprintf ( V_5 , L_15 , V_29 ) ;
exit ( 1 ) ;
} else {
V_6 -> V_29 = V_29 - V_6 -> V_28 ;
}
}
void
F_15 ( void )
{
unsigned int V_43 ;
T_7 V_44 ;
#ifndef F_16
int V_45 ;
T_8 V_46 ;
#define F_17 "/dev/urandom"
V_45 = F_18 ( F_17 , V_47 ) ;
if ( V_45 == - 1 ) {
if ( V_48 != V_49 ) {
fprintf ( V_5 ,
L_16 F_17 L_17 ,
F_19 ( V_48 ) ) ;
exit ( 2 ) ;
}
goto V_50;
}
V_46 = F_20 ( V_45 , & V_43 , sizeof V_43 ) ;
if ( V_46 == - 1 ) {
fprintf ( V_5 ,
L_18 F_17 L_19 ,
F_19 ( V_48 ) ) ;
exit ( 2 ) ;
}
if ( ( V_51 ) V_46 != sizeof V_43 ) {
fprintf ( V_5 ,
L_20 F_17 L_21 ,
( unsigned long ) sizeof V_43 , ( long ) V_46 ) ;
exit ( 2 ) ;
}
srand ( V_43 ) ;
F_21 ( V_45 ) ;
return;
V_50:
#endif
V_44 = time ( NULL ) ;
V_43 = ( unsigned int ) V_44 ;
srand ( V_43 ) ;
}
int F_22 ( char * string )
{
int V_2 = F_2 ( V_1 ) ;
int V_3 ;
if ( ! string ) {
return V_1 [ rand () % V_2 ] . V_4 ;
}
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ ) {
if ( F_23 ( V_1 [ V_3 ] . V_52 , string ) == 0 ) {
return V_1 [ V_3 ] . V_4 ;
}
}
fprintf ( V_5 , L_22 , string ) ;
return - 1 ;
}
void F_24 ( char * * * V_53 , char * * * V_54 )
{
unsigned V_3 ;
unsigned V_55 ;
V_55 = F_1 () ;
* V_53 = F_5 ( char * , V_55 + 1 ) ;
* V_54 = F_5 ( char * , V_55 + 1 ) ;
for ( V_3 = 0 ; V_3 < V_55 ; V_3 ++ ) {
( * V_53 ) [ V_3 ] = F_25 ( V_1 [ V_3 ] . V_52 ) ;
( * V_54 ) [ V_3 ] = F_25 ( V_1 [ V_3 ] . V_56 ) ;
}
}
