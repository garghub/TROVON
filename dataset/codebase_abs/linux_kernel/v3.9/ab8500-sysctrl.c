void F_1 ( void )
{
T_1 V_1 ;
T_1 V_2 ;
static char * V_3 [] = { L_1 , L_2 } ;
int V_4 ;
bool V_5 = false ;
union V_6 V_7 ;
struct V_8 * V_9 ;
int V_10 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_3 ) ; V_4 ++ ) {
V_9 = F_3 ( V_3 [ V_4 ] ) ;
if ( ! V_9 )
continue;
V_10 = V_9 -> V_11 ( V_9 , V_12 , & V_7 ) ;
if ( ! V_10 && V_7 . V_13 ) {
V_5 = true ;
break;
}
}
if ( ! V_5 )
goto V_14;
V_9 = F_3 ( L_3 ) ;
if ( V_9 ) {
V_10 = V_9 -> V_11 ( V_9 , V_15 ,
& V_7 ) ;
if ( ! V_10 && V_7 . V_13 != V_16 ) {
F_4 ( V_17
L_4
L_5 ,
V_3 [ V_4 ] ) ;
F_5 ( L_6 ) ;
}
}
V_14:
F_6 ( & V_2 ) ;
if ( ! F_7 ( V_18 , & V_2 , & V_1 ) ) {
( void ) F_8 ( V_19 ,
V_20 |
V_21 ) ;
( void ) F_7 ( V_22 , & V_1 , NULL ) ;
}
}
static inline bool F_9 ( T_2 V_23 )
{
return ( ( V_23 == V_24 ) ||
( V_23 == V_25 ) ) ;
}
int F_10 ( T_3 V_26 , T_2 * V_27 )
{
T_2 V_23 ;
if ( V_28 == NULL )
return - V_29 ;
V_23 = ( V_26 >> 8 ) ;
if ( ! F_9 ( V_23 ) )
return - V_30 ;
return F_11 ( V_28 , V_23 ,
( T_2 ) ( V_26 & 0xFF ) , V_27 ) ;
}
int F_12 ( T_3 V_26 , T_2 V_31 , T_2 V_27 )
{
T_2 V_23 ;
if ( V_28 == NULL )
return - V_29 ;
V_23 = ( V_26 >> 8 ) ;
if ( ! F_9 ( V_23 ) )
return - V_30 ;
return F_13 ( V_28 , V_23 ,
( T_2 ) ( V_26 & 0xFF ) , V_31 , V_27 ) ;
}
static int F_14 ( struct V_32 * V_33 )
{
struct V_34 * V_35 ;
struct V_36 * V_37 ;
V_28 = & V_33 -> V_38 ;
V_35 = F_15 ( V_33 -> V_38 . V_39 ) ;
if ( V_35 -> V_40 )
V_40 = F_1 ;
V_37 = V_35 -> V_41 ;
if ( V_37 ) {
int V_10 , V_4 , V_42 ;
for ( V_4 = V_43 ;
V_4 <= V_44 ; V_4 ++ ) {
V_42 = V_4 - V_43 ;
V_10 = F_12 ( V_4 , 0xff ,
V_37 -> V_45 [ V_42 ] ) ;
F_16 ( & V_33 -> V_38 ,
L_7 ,
V_42 + 1 ,
V_37 -> V_45 [ V_42 ] ) ;
if ( V_10 < 0 ) {
F_17 ( & V_33 -> V_38 ,
L_8
L_9 , V_42 + 1 , V_10 ) ;
}
}
}
return 0 ;
}
static int F_18 ( struct V_32 * V_33 )
{
V_28 = NULL ;
return 0 ;
}
static int T_4 F_19 ( void )
{
return F_20 ( & V_46 ) ;
}
