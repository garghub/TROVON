static int
F_1 ( struct V_1 * V_2 , int V_3 ,
T_1 V_4 , T_1 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 ;
V_8 = (* V_7 -> V_9 )( V_2 , V_3 ,
V_4 , V_5 ) ;
return V_8 ;
}
static int
F_2 ( struct V_1 * V_2 , T_2 V_10 , bool V_11 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_3 = V_12 ;
int V_8 ;
if ( V_11 )
V_3 |= V_13 ;
else
V_3 |= V_14 ;
V_7 -> V_10 = V_10 ;
V_7 -> V_15 = true ;
V_8 = F_1 ( V_2 , V_3 , 0 , NULL ) ;
return V_8 ;
}
static void
F_3 ( struct V_1 * V_2 , bool V_11 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_3 = V_16 ;
if ( V_11 )
V_3 |= V_13 ;
else
V_3 |= V_14 ;
if ( V_7 -> V_15 ) {
( void ) F_1 ( V_2 , V_3 , 0 , NULL ) ;
V_7 -> V_15 = false ;
}
}
static int
F_4 ( struct V_1 * V_2 , T_3 V_17 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 ;
if ( ! V_7 -> V_15 )
return - V_18 ;
V_8 = F_1 ( V_2 , V_14 , V_17 , NULL ) ;
return V_8 ;
}
static int
F_5 ( struct V_1 * V_2 , T_3 * V_19 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 ;
if ( ! V_7 -> V_15 )
return - V_18 ;
V_8 = F_1 ( V_2 , V_13 , 0 , V_19 ) ;
return V_8 ;
}
static int
F_6 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
int V_22 )
{
int V_8 = 0 ;
bool V_11 = false ;
int V_23 ;
int V_24 ;
for ( V_23 = 0 ; V_23 < V_22 ; V_23 ++ ) {
T_2 V_25 = V_21 [ V_23 ] . V_25 ;
T_3 * V_26 = V_21 [ V_23 ] . V_26 ;
V_11 = ( V_21 [ V_23 ] . V_27 & V_28 ) != 0 ;
V_8 = F_2 ( V_2 , V_21 [ V_23 ] . V_29 , V_11 ) ;
if ( V_8 < 0 )
break;
if ( V_11 ) {
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
V_8 = F_5 ( V_2 , & V_26 [ V_24 ] ) ;
if ( V_8 < 0 )
break;
}
} else {
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
V_8 = F_4 ( V_2 , V_26 [ V_24 ] ) ;
if ( V_8 < 0 )
break;
}
}
if ( V_8 < 0 )
break;
}
if ( V_8 >= 0 )
V_8 = V_22 ;
F_3 ( V_2 , V_11 ) ;
F_7 ( L_1 , V_8 ) ;
return V_8 ;
}
static T_4
F_8 ( struct V_1 * V_2 )
{
return V_30 | V_31 |
V_32 |
V_33 |
V_34 ;
}
static void
F_9 ( struct V_1 * V_2 )
{
( void ) F_2 ( V_2 , 0 , false ) ;
( void ) F_3 ( V_2 , false ) ;
}
static int
F_10 ( struct V_1 * V_2 )
{
V_2 -> V_35 = & V_36 ;
V_2 -> V_37 = 3 ;
F_9 ( V_2 ) ;
return 0 ;
}
int
F_11 ( struct V_1 * V_2 )
{
int error ;
error = F_10 ( V_2 ) ;
if ( error )
return error ;
error = F_12 ( V_2 ) ;
return error ;
}
