static int T_1 F_1 ( void )
{
T_2 * V_1 ;
struct V_2 * V_3 ;
unsigned long V_4 = 0 ;
char * V_5 ;
int V_6 ;
V_1 = F_2 ( V_7 . V_3 -> V_8 ) ;
for ( V_6 = 0 ; V_6 < ( int ) V_7 . V_3 -> V_9 ; ++ V_6 ) {
if ( F_3 ( V_1 [ V_6 ] . V_10 , V_11 ) == 0 ) {
V_4 = V_1 [ V_6 ] . V_12 ;
break;
}
}
if ( ! V_4 )
return - V_13 ;
V_3 = F_2 ( V_4 ) ;
if ( strncmp ( V_3 -> V_14 , L_1 , 4 ) != 0 ) {
F_4 ( V_15 L_2 ) ;
return - V_13 ;
}
V_5 = ( char * ) ( V_3 + 1 ) ;
for ( V_6 = 0 ; V_6 < V_3 -> V_16 ; V_6 ++ ) {
switch ( * V_5 ) {
case V_17 :
break;
default:
F_4 ( V_18 L_3
L_4 , * V_5 ) ;
return - V_13 ;
}
V_5 += F_5 ( * V_5 ) ;
}
V_19 = V_3 ;
return 0 ;
}
int F_6 ( T_3 V_10 , struct V_20 * V_21 ,
enum V_22 V_23 , T_4 V_24 ,
T_4 V_25 , T_4 V_26 , T_4 V_27 , T_4 V_28 , T_4 V_29 , T_4 V_30 ,
T_4 V_31 )
{
struct V_32 V_33 [ 6 ] ;
unsigned long V_34 = 0 ;
int V_6 ;
char * V_5 ;
if ( ! V_19 )
return - 1 ;
V_5 = ( char * ) ( V_19 + 1 ) ;
for ( V_6 = 0 ; V_6 < V_19 -> V_16 ; V_6 ++ ) {
if ( * V_5 == V_17 ) {
T_5 * V_4 = ( void * ) V_5 ;
if ( ! F_3 ( V_10 , V_4 -> V_10 ) ) {
T_6 V_35 ;
struct V_36 V_36 ;
V_36 . V_37 = F_2 ( V_4 -> V_35 ) ;
V_36 . V_38 = F_2 ( V_4 -> V_38 ) ;
V_35 = ( T_6 ) & V_36 ;
F_7 ( V_33 ) ;
if ( V_23 == V_39 )
F_8 ( & V_40 , V_34 ) ;
else if ( V_23 == V_41 )
F_9 ( V_34 ) ;
else
F_10 () ;
* V_21 = (* V_35)( V_24 , V_25 , V_26 , V_27 ,
V_28 , V_29 , V_30 , V_31 ) ;
if ( V_23 == V_39 )
F_11 ( & V_40 ,
V_34 ) ;
else if ( V_23 == V_41 )
F_12 ( V_34 ) ;
else
F_13 () ;
F_14 ( V_33 ) ;
return 0 ;
}
}
V_5 += F_5 ( * V_5 ) ;
}
return - 1 ;
}
int F_15 ( T_3 V_10 , struct V_20 * V_21 ,
T_4 V_24 , T_4 V_25 , T_4 V_26 , T_4 V_27 , T_4 V_28 ,
T_4 V_29 , T_4 V_30 , T_4 V_31 )
{
struct V_32 V_33 [ 6 ] ;
unsigned long V_34 ;
T_4 V_42 [ 8 ] ;
char * V_5 ;
int V_6 ;
if ( ! V_19 )
return - 1 ;
V_5 = ( char * ) ( V_19 + 1 ) ;
for ( V_6 = 0 ; V_6 < V_19 -> V_16 ; V_6 ++ ) {
if ( * V_5 == V_17 ) {
T_5 * V_4 = ( void * ) V_5 ;
if ( ! F_3 ( V_10 , V_4 -> V_10 ) ) {
T_6 V_35 ;
struct V_36 V_36 ;
V_36 . V_37 = ( void * ) V_4 -> V_35 ;
V_36 . V_38 = ( void * ) V_4 -> V_38 ;
V_35 = ( T_6 ) & V_36 ;
V_42 [ 0 ] = V_24 ;
V_42 [ 1 ] = V_25 ;
V_42 [ 2 ] = V_26 ;
V_42 [ 3 ] = V_27 ;
V_42 [ 4 ] = V_28 ;
V_42 [ 5 ] = V_29 ;
V_42 [ 6 ] = V_30 ;
V_42 [ 7 ] = V_31 ;
F_7 ( V_33 ) ;
F_8 ( & V_40 , V_34 ) ;
* V_21 = F_16 ( V_35 , V_42 ) ;
F_11 ( & V_40 , V_34 ) ;
F_14 ( V_33 ) ;
return 0 ;
}
}
V_5 += F_5 ( * V_5 ) ;
}
return - 1 ;
}
static void T_7 F_17 ( void )
{
}
