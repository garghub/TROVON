static int F_1 ( struct V_1 * V_1 , T_1 V_2 , int V_3 , T_2 * V_4 )
{
int V_5 , V_6 = 0 ;
F_2 ( V_2 + V_3 > F_3 ( V_1 -> V_7 ) ) ;
for ( V_5 = V_2 ; V_5 < V_2 + V_3 ; V_5 ++ )
if ( V_8 [ V_5 ] . V_9 ) {
V_6 = V_1 -> V_10 ( V_1 -> V_11 , V_2 ,
V_3 , V_4 ) ;
if ( V_6 != 0 )
return V_6 ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ )
V_4 [ V_5 ] = F_4 ( V_4 [ V_5 ] ) ;
return 0 ;
}
memcpy ( V_4 , & V_1 -> V_7 [ V_2 ] , V_3 * sizeof( T_2 ) ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_1 , T_1 V_2 , int V_3 ,
T_2 * V_12 )
{
int V_6 , V_5 ;
F_2 ( V_2 + V_3 > F_3 ( V_1 -> V_7 ) ) ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ ) {
F_2 ( ! V_8 [ V_2 + V_5 ] . V_13 ) ;
V_1 -> V_7 [ V_2 + V_5 ] = V_12 [ V_5 ] ;
V_12 [ V_5 ] = F_6 ( V_12 [ V_5 ] ) ;
}
V_6 = V_1 -> V_14 ( V_1 -> V_11 , V_2 , V_3 , V_12 ) ;
if ( V_6 != 0 )
return - V_15 ;
return 0 ;
}
T_2 F_7 ( struct V_1 * V_1 , T_1 V_2 )
{
T_2 V_16 ;
F_8 ( & V_1 -> V_17 ) ;
F_1 ( V_1 , V_2 , 1 , & V_16 ) ;
F_9 ( & V_1 -> V_17 ) ;
return V_16 ;
}
int F_10 ( struct V_1 * V_1 , T_1 V_2 , int V_18 , T_2 * V_19 )
{
int V_6 ;
F_8 ( & V_1 -> V_17 ) ;
V_6 = F_1 ( V_1 , V_2 , V_18 , V_19 ) ;
F_9 ( & V_1 -> V_17 ) ;
return V_6 ;
}
int F_11 ( struct V_1 * V_1 , T_1 V_2 , T_2 V_20 , T_2 V_16 )
{
T_2 V_21 ;
int V_6 ;
F_8 ( & V_1 -> V_17 ) ;
V_6 = F_1 ( V_1 , V_2 , 1 , & V_21 ) ;
V_21 = ( V_21 & ~ V_20 ) | V_16 ;
if ( V_6 == 0 )
V_6 = F_5 ( V_1 , V_2 , 1 , & V_21 ) ;
F_9 ( & V_1 -> V_17 ) ;
return V_6 ;
}
void F_12 ( struct V_1 * V_1 )
{
int V_5 ;
F_8 ( & V_1 -> V_17 ) ;
for ( V_5 = 0 ; V_5 < F_3 ( V_1 -> V_7 ) ; V_5 ++ )
if ( V_8 [ V_5 ] . V_22 )
V_1 -> V_7 [ V_5 ] = V_8 [ V_5 ] . V_23 ;
F_9 ( & V_1 -> V_17 ) ;
}
static int F_13 ( struct V_1 * V_1 )
{
struct V_24 V_25 = {
. V_26 = L_1 ,
. V_27 = V_1 ,
. V_28 = sizeof( * V_1 ) ,
} ;
return F_14 ( V_1 -> V_29 , - 1 , & V_25 , 1 , NULL , 0 ) ;
}
static int F_15 ( struct V_1 * V_1 ,
struct V_30 * V_31 )
{
T_2 V_2 ;
int V_6 , V_5 ;
F_16 ( & V_1 -> V_17 ) ;
F_17 ( V_1 -> V_29 , V_1 ) ;
V_6 = V_1 -> V_10 ( V_1 -> V_11 , V_32 , 1 , & V_2 ) ;
if ( V_6 != 0 ) {
F_18 ( V_1 -> V_29 , L_2 ) ;
return - V_15 ;
}
if ( F_4 ( V_2 ) != V_8 [ V_32 ] . V_23 ) {
F_18 ( V_1 -> V_29 , L_3 ,
F_4 ( V_2 ) ) ;
return - V_33 ;
}
V_6 = V_1 -> V_10 ( V_1 -> V_11 , 0 ,
F_3 ( V_1 -> V_7 ) ,
V_1 -> V_7 ) ;
if ( V_6 != 0 ) {
F_18 ( V_1 -> V_29 , L_4 ) ;
return - V_15 ;
}
for ( V_5 = 0 ; V_5 < F_3 ( V_1 -> V_7 ) ; V_5 ++ )
V_1 -> V_7 [ V_5 ] = F_4 ( V_1 -> V_7 [ V_5 ] ) ;
if ( ! ( V_1 -> V_7 [ V_34 ] & V_35 ) )
for ( V_5 = 0 ; V_5 < F_3 ( V_1 -> V_7 ) ; V_5 ++ )
if ( V_8 [ V_5 ] . V_22 )
V_1 -> V_7 [ V_5 ] = V_8 [ V_5 ] . V_23 ;
V_6 = F_1 ( V_1 , V_36 , 1 , & V_2 ) ;
if ( V_6 != 0 ) {
F_18 ( V_1 -> V_29 , L_5 , V_6 ) ;
return V_6 ;
}
V_2 = ( V_2 & V_37 ) >> V_38 ;
F_19 ( V_1 -> V_29 , L_6 , V_2 ) ;
V_6 = F_13 ( V_1 ) ;
if ( V_6 != 0 ) {
F_18 ( V_1 -> V_29 , L_7 ) ;
goto V_39;
}
if ( V_31 && V_31 -> V_40 ) {
V_6 = V_31 -> V_40 ( V_1 -> V_29 ) ;
if ( V_6 != 0 ) {
F_18 ( V_1 -> V_29 , L_8 ,
V_6 ) ;
goto V_39;
}
} else
F_20 ( V_1 -> V_29 , L_9 ) ;
return 0 ;
V_39:
F_21 ( V_1 -> V_29 ) ;
return V_6 ;
}
static void F_22 ( struct V_1 * V_1 )
{
F_21 ( V_1 -> V_29 ) ;
}
static int F_23 ( void * V_11 , char V_2 , int V_18 , T_2 * V_4 )
{
struct V_41 * V_42 = V_11 ;
struct V_43 V_44 [ 2 ] ;
int V_6 ;
V_44 [ 0 ] . V_45 = V_42 -> V_45 ;
V_44 [ 0 ] . V_46 = 0 ;
V_44 [ 0 ] . V_47 = 1 ;
V_44 [ 0 ] . V_48 = & V_2 ;
V_44 [ 1 ] . V_45 = V_42 -> V_45 ;
V_44 [ 1 ] . V_46 = V_49 ;
V_44 [ 1 ] . V_47 = V_18 * sizeof( T_2 ) ;
V_44 [ 1 ] . V_48 = ( T_1 * ) V_4 ;
V_6 = F_24 ( V_42 -> V_50 , V_44 , 2 ) ;
if ( V_6 == 2 )
V_6 = 0 ;
else if ( V_6 >= 0 )
V_6 = - V_15 ;
return V_6 ;
}
static int F_25 ( void * V_11 , char V_2 , int V_18 , const T_2 * V_12 )
{
struct V_41 * V_42 = V_11 ;
T_1 * V_51 ;
int V_6 ;
V_51 = F_26 ( ( V_18 * sizeof( T_2 ) ) + 1 , V_52 ) ;
if ( V_51 == NULL )
return - V_53 ;
V_51 [ 0 ] = V_2 ;
memcpy ( & V_51 [ 1 ] , V_12 , V_18 * sizeof( T_2 ) ) ;
V_6 = F_27 ( V_42 , V_51 , ( V_18 * sizeof( T_2 ) ) + 1 ) ;
if ( V_6 == ( V_18 * 2 ) + 1 )
V_6 = 0 ;
else if ( V_6 >= 0 )
V_6 = - V_15 ;
F_28 ( V_51 ) ;
return V_6 ;
}
static int F_29 ( struct V_41 * V_42 ,
const struct V_54 * V_55 )
{
struct V_1 * V_1 ;
int V_6 ;
V_1 = F_30 ( sizeof( struct V_1 ) , V_52 ) ;
if ( V_1 == NULL ) {
V_6 = - V_53 ;
goto V_56;
}
V_1 -> V_11 = V_42 ;
V_1 -> V_10 = F_23 ;
V_1 -> V_14 = F_25 ;
V_1 -> V_29 = & V_42 -> V_29 ;
F_31 ( V_42 , V_1 ) ;
V_6 = F_15 ( V_1 , V_42 -> V_29 . V_27 ) ;
if ( V_6 != 0 )
goto V_57;
return 0 ;
V_57:
F_28 ( V_1 ) ;
V_56:
return V_6 ;
}
static int F_32 ( struct V_41 * V_42 )
{
struct V_1 * V_1 = F_33 ( V_42 ) ;
F_22 ( V_1 ) ;
F_28 ( V_1 ) ;
return 0 ;
}
static int T_3 F_34 ( void )
{
int V_6 = - V_33 ;
#if F_35 ( V_58 ) || F_35 ( V_59 )
V_6 = F_36 ( & V_60 ) ;
if ( V_6 != 0 )
F_37 ( L_10 , V_6 ) ;
#endif
return V_6 ;
}
static void T_4 F_38 ( void )
{
#if F_35 ( V_58 ) || F_35 ( V_59 )
F_39 ( & V_60 ) ;
#endif
}
