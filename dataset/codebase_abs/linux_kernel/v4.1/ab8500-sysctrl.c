static void F_1 ( void )
{
T_1 V_1 ;
T_1 V_2 ;
static char * V_3 [] = { L_1 , L_2 , L_3 } ;
int V_4 ;
bool V_5 = false ;
union V_6 V_7 ;
struct V_8 * V_9 ;
int V_10 ;
if ( V_11 == NULL ) {
F_2 ( L_4 , V_12 ) ;
return;
}
for ( V_4 = 0 ; V_4 < F_3 ( V_3 ) ; V_4 ++ ) {
V_9 = F_4 ( V_3 [ V_4 ] ) ;
if ( ! V_9 )
continue;
V_10 = F_5 ( V_9 , V_13 ,
& V_7 ) ;
F_6 ( V_9 ) ;
if ( ! V_10 && V_7 . V_14 ) {
V_5 = true ;
break;
}
}
if ( ! V_5 )
goto V_15;
V_9 = F_4 ( L_5 ) ;
if ( V_9 ) {
V_10 = F_5 ( V_9 ,
V_16 , & V_7 ) ;
if ( ! V_10 && V_7 . V_14 != V_17 ) {
F_7 ( V_18
L_6
L_7 ,
V_3 [ V_4 ] ) ;
F_8 ( L_8 ) ;
}
F_6 ( V_9 ) ;
}
V_15:
F_9 ( & V_2 ) ;
if ( ! F_10 ( V_19 , & V_2 , & V_1 ) ) {
( void ) F_11 ( V_20 ,
V_21 |
V_22 ) ;
( void ) F_10 ( V_23 , & V_1 , NULL ) ;
}
}
static inline bool F_12 ( T_2 V_24 )
{
return ( ( V_24 == V_25 ) ||
( V_24 == V_26 ) ) ;
}
int F_13 ( T_3 V_27 , T_2 * V_28 )
{
T_2 V_24 ;
if ( V_11 == NULL )
return - V_29 ;
V_24 = ( V_27 >> 8 ) ;
if ( ! F_12 ( V_24 ) )
return - V_29 ;
return F_14 ( V_11 , V_24 ,
( T_2 ) ( V_27 & 0xFF ) , V_28 ) ;
}
int F_15 ( T_3 V_27 , T_2 V_30 , T_2 V_28 )
{
T_2 V_24 ;
if ( V_11 == NULL )
return - V_29 ;
V_24 = ( V_27 >> 8 ) ;
if ( ! F_12 ( V_24 ) )
return - V_29 ;
return F_16 ( V_11 , V_24 ,
( T_2 ) ( V_27 & 0xFF ) , V_30 , V_28 ) ;
}
static int F_17 ( struct V_31 * V_32 )
{
struct V_33 * V_33 = F_18 ( V_32 -> V_34 . V_35 ) ;
struct V_36 * V_37 ;
struct V_38 * V_39 ;
V_37 = F_19 ( V_32 -> V_34 . V_35 ) ;
if ( ! V_37 )
return - V_29 ;
V_11 = & V_32 -> V_34 ;
if ( ! V_40 )
V_40 = F_1 ;
V_39 = V_37 -> V_41 ;
if ( V_39 ) {
int V_42 , V_10 , V_4 , V_43 ;
if ( F_20 ( V_33 ) )
V_42 = V_44 ;
else
V_42 = V_45 ;
for ( V_4 = V_46 ; V_4 <= V_42 ; V_4 ++ ) {
V_43 = V_4 - V_46 ;
V_10 = F_15 ( V_4 , 0xff ,
V_39 -> V_47 [ V_43 ] ) ;
F_21 ( & V_32 -> V_34 ,
L_9 ,
V_43 + 1 ,
V_39 -> V_47 [ V_43 ] ) ;
if ( V_10 < 0 ) {
F_22 ( & V_32 -> V_34 ,
L_10
L_11 , V_43 + 1 , V_10 ) ;
}
}
}
return 0 ;
}
static int F_23 ( struct V_31 * V_32 )
{
V_11 = NULL ;
if ( V_40 == F_1 )
V_40 = NULL ;
return 0 ;
}
static int T_4 F_24 ( void )
{
return F_25 ( & V_48 ) ;
}
