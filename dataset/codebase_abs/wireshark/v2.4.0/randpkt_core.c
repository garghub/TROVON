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
T_1 V_3 , V_8 ;
int V_9 ;
T_1 V_10 ;
T_1 V_11 ;
T_4 * V_12 ;
union V_13 * V_14 ;
T_5 * V_15 ;
struct V_16 * V_17 ;
V_17 = F_5 ( struct V_16 , 1 ) ;
V_15 = ( T_5 * ) F_6 ( 65536 ) ;
V_17 -> V_18 = V_19 ;
V_17 -> V_20 = V_21 ;
V_17 -> V_22 = V_6 -> V_23 ;
V_14 = & V_17 -> V_24 ;
if ( V_6 -> V_25 )
memcpy ( V_14 , V_6 -> V_25 , V_6 -> V_26 ) ;
if ( V_6 -> V_27 )
memcpy ( V_15 , V_6 -> V_27 , V_6 -> V_28 ) ;
for ( V_3 = 0 ; V_3 < V_7 ; V_3 ++ ) {
if ( V_6 -> V_29 > 0 ) {
V_10 = F_7 ( V_30 , 0 , V_6 -> V_29 + 1 ) ;
}
else {
V_10 = 0 ;
}
V_11 = V_6 -> V_28 + V_10 ;
V_17 -> V_31 = V_11 ;
V_17 -> V_32 = V_11 ;
V_17 -> V_33 . V_34 = V_3 ;
for ( V_8 = V_6 -> V_26 ; V_8 < ( int ) sizeof( * V_14 ) ; V_8 ++ ) {
( ( T_5 * ) V_14 ) [ V_8 ] = F_7 ( V_30 , 0 , 0x100 ) ;
}
for ( V_8 = V_6 -> V_28 ; V_8 < V_11 ; V_8 ++ ) {
if ( ( int ) ( 100.0 * F_8 ( V_30 ) ) < 3 && V_8 < ( V_10 - 3 ) ) {
memcpy ( & V_15 [ V_8 ] , L_2 , 3 ) ;
V_8 += 2 ;
} else {
V_15 [ V_8 ] = F_7 ( V_30 , 0 , 0x100 ) ;
}
}
if ( ! F_9 ( V_6 -> V_35 , V_17 , V_15 , & V_9 , & V_12 ) ) {
F_10 ( L_3 , NULL ,
V_6 -> V_36 , V_9 , V_12 , 0 ,
V_37 ) ;
}
}
F_11 ( V_17 ) ;
F_11 ( V_15 ) ;
}
T_6 F_12 ( T_2 * V_6 )
{
int V_9 ;
T_6 V_38 = TRUE ;
if ( ! F_13 ( V_6 -> V_35 , & V_9 ) ) {
F_14 ( V_6 -> V_36 , V_9 ) ;
V_38 = FALSE ;
}
if ( V_30 != NULL ) {
F_15 ( V_30 ) ;
V_30 = NULL ;
}
return V_38 ;
}
int F_16 ( T_2 * V_6 , char * V_39 , int V_29 )
{
int V_9 ;
if ( V_30 == NULL ) {
V_30 = F_17 () ;
}
F_18 () ;
if ( strcmp ( V_39 , L_4 ) == 0 ) {
V_6 -> V_35 = F_19 ( V_37 ,
V_6 -> V_23 , V_29 , FALSE , & V_9 ) ;
V_6 -> V_36 = L_5 ;
} else {
V_6 -> V_35 = F_20 ( V_39 , V_37 ,
V_6 -> V_23 , V_29 , FALSE , & V_9 ) ;
V_6 -> V_36 = V_39 ;
}
if ( ! V_6 -> V_35 ) {
F_21 ( L_3 , V_39 ,
V_9 , V_37 ) ;
return V_40 ;
}
if ( V_29 <= V_6 -> V_28 ) {
fprintf ( V_5 , L_6
L_7 , V_6 -> V_28 ) ;
fprintf ( V_5 , L_8 , V_29 ) ;
return V_41 ;
} else {
V_6 -> V_29 = V_29 - V_6 -> V_28 ;
}
return V_42 ;
}
int F_22 ( char * string )
{
int V_2 = F_2 ( V_1 ) ;
int V_3 ;
if ( ! string ) {
return V_1 [ F_23 ( 0 , V_2 ) ] . V_4 ;
}
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ ) {
if ( F_24 ( V_1 [ V_3 ] . V_43 , string ) == 0 ) {
return V_1 [ V_3 ] . V_4 ;
}
}
fprintf ( V_5 , L_9 , string ) ;
return - 1 ;
}
void F_25 ( char * * * V_44 , char * * * V_45 )
{
unsigned V_3 ;
unsigned V_46 ;
V_46 = F_1 () ;
* V_44 = F_5 ( char * , V_46 + 1 ) ;
* V_45 = F_5 ( char * , V_46 + 1 ) ;
for ( V_3 = 0 ; V_3 < V_46 ; V_3 ++ ) {
( * V_44 ) [ V_3 ] = F_26 ( V_1 [ V_3 ] . V_43 ) ;
( * V_45 ) [ V_3 ] = F_26 ( V_1 [ V_3 ] . V_47 ) ;
}
}
