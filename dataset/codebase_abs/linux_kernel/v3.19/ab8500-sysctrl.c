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
V_10 = V_9 -> V_13 ( V_9 , V_14 , & V_7 ) ;
if ( ! V_10 && V_7 . V_15 ) {
V_5 = true ;
break;
}
}
if ( ! V_5 )
goto V_16;
V_9 = F_4 ( L_5 ) ;
if ( V_9 ) {
V_10 = V_9 -> V_13 ( V_9 , V_17 ,
& V_7 ) ;
if ( ! V_10 && V_7 . V_15 != V_18 ) {
F_5 ( V_19
L_6
L_7 ,
V_3 [ V_4 ] ) ;
F_6 ( L_8 ) ;
}
}
V_16:
F_7 ( & V_2 ) ;
if ( ! F_8 ( V_20 , & V_2 , & V_1 ) ) {
( void ) F_9 ( V_21 ,
V_22 |
V_23 ) ;
( void ) F_8 ( V_24 , & V_1 , NULL ) ;
}
}
static inline bool F_10 ( T_2 V_25 )
{
return ( ( V_25 == V_26 ) ||
( V_25 == V_27 ) ) ;
}
int F_11 ( T_3 V_28 , T_2 * V_29 )
{
T_2 V_25 ;
if ( V_11 == NULL )
return - V_30 ;
V_25 = ( V_28 >> 8 ) ;
if ( ! F_10 ( V_25 ) )
return - V_30 ;
return F_12 ( V_11 , V_25 ,
( T_2 ) ( V_28 & 0xFF ) , V_29 ) ;
}
int F_13 ( T_3 V_28 , T_2 V_31 , T_2 V_29 )
{
T_2 V_25 ;
if ( V_11 == NULL )
return - V_30 ;
V_25 = ( V_28 >> 8 ) ;
if ( ! F_10 ( V_25 ) )
return - V_30 ;
return F_14 ( V_11 , V_25 ,
( T_2 ) ( V_28 & 0xFF ) , V_31 , V_29 ) ;
}
static int F_15 ( struct V_32 * V_33 )
{
struct V_34 * V_34 = F_16 ( V_33 -> V_35 . V_36 ) ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
V_38 = F_17 ( V_33 -> V_35 . V_36 ) ;
if ( ! V_38 )
return - V_30 ;
V_11 = & V_33 -> V_35 ;
if ( ! V_41 )
V_41 = F_1 ;
V_40 = V_38 -> V_42 ;
if ( V_40 ) {
int V_43 , V_10 , V_4 , V_44 ;
if ( F_18 ( V_34 ) )
V_43 = V_45 ;
else
V_43 = V_46 ;
for ( V_4 = V_47 ; V_4 <= V_43 ; V_4 ++ ) {
V_44 = V_4 - V_47 ;
V_10 = F_13 ( V_4 , 0xff ,
V_40 -> V_48 [ V_44 ] ) ;
F_19 ( & V_33 -> V_35 ,
L_9 ,
V_44 + 1 ,
V_40 -> V_48 [ V_44 ] ) ;
if ( V_10 < 0 ) {
F_20 ( & V_33 -> V_35 ,
L_10
L_11 , V_44 + 1 , V_10 ) ;
}
}
}
return 0 ;
}
static int F_21 ( struct V_32 * V_33 )
{
V_11 = NULL ;
if ( V_41 == F_1 )
V_41 = NULL ;
return 0 ;
}
static int T_4 F_22 ( void )
{
return F_23 ( & V_49 ) ;
}
