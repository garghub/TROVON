static int F_1 ( T_1 V_1 )
{
T_2 V_2 ;
union V_3 V_4 [ 2 ] , * V_5 ;
struct V_6 V_7 ;
struct V_8 V_9 = { V_10 , NULL } ;
V_7 . V_11 = 2 ;
V_7 . V_12 = & V_4 [ 0 ] ;
V_4 [ 0 ] . type = V_13 ;
V_4 [ 0 ] . integer . V_14 = V_15 ;
V_4 [ 1 ] . type = V_13 ;
V_4 [ 1 ] . integer . V_14 = V_15 ;
V_2 = F_2 ( V_1 , NULL , & V_7 , & V_9 ) ;
if ( F_3 ( V_2 ) ) {
F_4 ( L_1 , V_16 , F_5 ( V_2 ) ) ;
return - V_17 ;
}
V_5 = (union V_3 * ) V_9 . V_12 ;
if ( V_5 && ( V_5 -> type == V_18 ) )
F_4 ( V_19 L_2 , * ( ( V_20 * ) ( V_5 -> V_9 . V_12 ) + 2 ) ) ;
F_6 ( V_9 . V_12 ) ;
return 0 ;
}
static int F_7 ( T_1 V_1 , int V_21 , T_3 V_14 )
{
T_2 V_2 ;
union V_3 V_4 [ 2 ] ;
struct V_6 V_7 ;
struct V_8 V_9 = { V_10 , NULL } ;
T_4 V_22 [ 4 ] = { 0 } ;
if ( ! V_1 )
return - V_23 ;
V_7 . V_11 = 2 ;
V_7 . V_12 = & V_4 [ 0 ] ;
V_4 [ 0 ] . type = V_13 ;
V_4 [ 0 ] . integer . V_14 = V_21 ;
V_22 [ 2 ] = V_14 & 0xff ;
V_22 [ 3 ] = ( V_14 >> 8 ) & 0xff ;
V_4 [ 1 ] . type = V_18 ;
V_4 [ 1 ] . V_9 . V_24 = 4 ;
V_4 [ 1 ] . V_9 . V_12 = V_22 ;
V_2 = F_2 ( V_1 , NULL , & V_7 , & V_9 ) ;
if ( F_3 ( V_2 ) ) {
F_4 ( L_1 , V_16 , F_5 ( V_2 ) ) ;
return - V_17 ;
}
F_6 ( V_9 . V_12 ) ;
return 0 ;
}
static int F_8 ( T_1 V_1 , int V_25 )
{
return F_7 ( V_1 , V_26 , V_25 ) ;
}
static int F_9 ( T_1 V_1 , int V_27 )
{
return F_7 ( V_1 , V_28 , V_27 ) ;
}
static int F_10 ( T_1 V_1 , int V_27 )
{
return F_7 ( V_1 , V_29 , V_27 ) ;
}
static int F_11 ( T_1 V_1 , int V_30 )
{
return F_7 ( V_1 , V_31 , V_30 ) ;
}
static int F_12 ( T_1 V_1 , int V_30 )
{
return F_7 ( V_1 , V_32 , V_30 ) ;
}
static int F_13 ( enum V_33 V_34 )
{
int V_30 ;
if ( V_34 == V_35 )
V_30 = V_36 ;
else
V_30 = V_37 ;
F_11 ( V_38 . V_39 , V_30 ) ;
F_9 ( V_38 . V_39 , V_30 ) ;
F_10 ( V_38 . V_39 , V_30 ) ;
F_12 ( V_38 . V_39 , V_30 ) ;
return 0 ;
}
static int F_14 ( enum V_33 V_34 ,
enum V_40 V_25 )
{
if ( V_34 == V_35 )
return 0 ;
F_8 ( V_38 . V_39 , V_25 ) ;
return 0 ;
}
static bool F_15 ( struct V_41 * V_42 )
{
T_1 V_43 , V_39 ;
T_2 V_2 ;
V_43 = F_16 ( & V_42 -> V_44 ) ;
if ( ! V_43 )
return false ;
V_2 = F_17 ( V_43 , L_3 , & V_39 ) ;
if ( F_3 ( V_2 ) )
return false ;
V_38 . V_43 = V_43 ;
V_38 . V_39 = V_39 ;
return true ;
}
static int F_18 ( void )
{
F_1 ( V_38 . V_39 ) ;
return 0 ;
}
static int F_19 ( struct V_41 * V_42 )
{
if ( V_38 . V_43 == F_16 ( & V_42 -> V_44 ) )
return V_35 ;
else
return V_45 ;
}
static bool F_20 ( void )
{
char V_46 [ 255 ] = { 0 } ;
struct V_8 V_9 = { sizeof( V_46 ) , V_46 } ;
struct V_41 * V_42 = NULL ;
bool V_47 = false ;
int V_48 = 0 ;
while ( ( V_42 = F_21 ( V_49 << 8 , V_42 ) ) != NULL ) {
V_48 ++ ;
V_47 |= ( F_15 ( V_42 ) == true ) ;
}
if ( V_47 && V_48 == 2 ) {
F_22 ( V_38 . V_39 , V_50 , & V_9 ) ;
F_4 ( V_19 L_4 ,
V_46 ) ;
V_38 . V_51 = true ;
return true ;
}
return false ;
}
void F_23 ( void )
{
bool V_52 ;
V_52 = F_20 () ;
if ( ! V_52 )
return;
F_24 ( & V_53 ) ;
}
void F_25 ( void )
{
F_26 () ;
}
