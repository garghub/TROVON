static void T_1 F_1 ( unsigned long V_1 ,
T_2 V_2 ,
T_3 V_3 ,
int V_4 ,
int V_5 ,
int type )
{
struct V_6 * V_7 ;
struct V_8 V_9 [ 4 ] ;
unsigned int V_10 = 1 , V_11 ;
struct V_12 V_13 [ 4 ] = {
F_2 ( L_1 , V_3 ) ,
F_2 ( L_2 , type ) ,
F_3 ( L_3 , V_1 ) ,
{ }
} ;
char * V_14 , * V_15 ;
int V_16 ;
struct V_17 * V_18 ;
V_18 = F_4 ( sizeof( * V_18 ) , V_19 ) ;
if ( ! V_18 ) {
F_5 ( L_4 ) ;
} else {
V_18 -> type = type ;
V_18 -> V_2 = V_2 ;
V_18 -> V_20 = V_1 ;
V_18 -> V_3 = V_3 ;
V_18 -> V_21 = V_22 ;
V_22 = V_18 ;
}
V_14 = L_5 ;
V_15 = L_6 ;
switch ( type ) {
case V_23 :
V_14 = L_7 ;
V_15 = L_8 ;
V_5 = 1 ;
V_11 = 1 ;
break;
case V_24 :
V_11 = 3 ;
break;
case V_25 :
case V_26 :
V_11 = 2 ;
break;
default:
F_6 ( L_9 , type ) ;
return;
}
V_7 = F_7 ( V_14 , V_27 ) ;
if ( ! V_7 ) {
F_6 ( L_10 ) ;
return;
}
V_7 -> V_28 = V_15 ;
if ( type == V_23 )
goto V_29;
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
V_9 [ 0 ] . V_30 = V_1 ;
V_9 [ 0 ] . V_31 = V_9 [ 0 ] . V_30 + V_5 - 1 ;
V_9 [ 0 ] . V_14 = L_11 ;
V_9 [ 0 ] . V_2 = V_2 ;
if ( V_11 > 1 ) {
V_9 [ 1 ] . V_30 = V_9 [ 0 ] . V_30 + V_5 ;
V_9 [ 1 ] . V_31 = V_9 [ 1 ] . V_30 + V_5 - 1 ;
V_9 [ 1 ] . V_14 = L_12 ;
V_9 [ 1 ] . V_2 = V_2 ;
V_10 ++ ;
}
if ( V_11 > 2 ) {
V_9 [ 2 ] . V_30 = V_9 [ 1 ] . V_30 + V_5 ;
V_9 [ 2 ] . V_31 = V_9 [ 2 ] . V_30 + V_5 - 1 ;
V_9 [ 2 ] . V_14 = L_13 ;
V_9 [ 2 ] . V_2 = V_2 ;
V_10 ++ ;
}
if ( V_4 ) {
V_9 [ V_10 ] . V_30 = V_4 ;
V_9 [ V_10 ] . V_31 = V_4 ;
V_9 [ V_10 ] . V_14 = L_14 ;
V_9 [ V_10 ] . V_2 = V_32 ;
V_10 ++ ;
}
V_16 = F_8 ( V_7 , V_9 , V_10 ) ;
if ( V_16 ) {
F_9 ( & V_7 -> V_33 ,
L_15 , V_16 ) ;
goto V_34;
}
V_29:
V_16 = F_10 ( V_7 , V_13 ) ;
if ( V_16 ) {
F_9 ( & V_7 -> V_33 ,
L_16 , V_16 ) ;
goto V_34;
}
V_16 = F_11 ( V_7 ) ;
if ( V_16 ) {
F_9 ( & V_7 -> V_33 , L_17 , V_16 ) ;
goto V_34;
}
V_27 ++ ;
return;
V_34:
F_12 ( V_7 ) ;
}
int F_13 ( int type , T_2 V_2 , unsigned long V_1 )
{
struct V_17 * V_18 = V_22 ;
while ( V_18 ) {
if ( V_18 -> type == type &&
V_18 -> V_2 == V_2 &&
V_18 -> V_20 == V_1 )
return V_18 -> V_3 ;
V_18 = V_18 -> V_21 ;
}
return 0 ;
}
static void T_1 F_14 ( const struct V_35 * V_36 )
{
const T_3 * V_37 = ( const T_3 * ) V_36 ;
T_2 V_2 = V_38 ;
unsigned long V_1 ;
T_3 V_39 = V_36 -> V_40 ;
T_3 V_3 ;
int V_4 = 0 , V_5 ;
int type ;
if ( V_39 < V_41 )
return;
type = V_37 [ V_42 ] ;
V_3 = V_37 [ V_43 ] ;
memcpy ( & V_1 , V_37 + V_44 , sizeof( unsigned long ) ) ;
if ( V_39 >= V_45 ) {
if ( type == V_23 ) {
V_5 = 0 ;
V_2 = 0 ;
V_1 = V_37 [ V_44 ] >> 1 ;
if ( V_1 == 0 ) {
V_1 = V_37 [ V_43 ] >> 1 ;
V_3 = 0 ;
}
} else {
if ( V_1 & 1 ) {
V_1 &= V_46 ;
} else {
V_2 = V_47 ;
}
V_1 |= ( V_37 [ V_48 ] >> 4 ) & 1 ;
V_4 = V_37 [ V_49 ] ;
switch ( ( V_37 [ V_48 ] >> 6 ) & 3 ) {
case 0 :
V_5 = 1 ;
break;
case 1 :
V_5 = 4 ;
break;
case 2 :
V_5 = 16 ;
break;
default:
F_6 ( L_18 ) ;
return;
}
}
} else {
V_1 = V_1 & V_46 ;
V_5 = 1 ;
}
F_1 ( V_1 , V_2 , V_3 , V_4 ,
V_5 , type ) ;
}
static int T_1 F_15 ( void )
{
const struct V_50 * V_33 = NULL ;
while ( ( V_33 = F_16 ( V_51 , NULL , V_33 ) ) )
F_14 ( ( const struct V_35 * ) V_33 -> V_52 ) ;
return 0 ;
}
