static int F_1 ( T_1 V_1 , T_2 * V_2 ,
int V_3 , int V_4 )
{
T_3 V_5 ;
union V_6 V_7 [ 2 ] , * V_8 ;
struct V_9 V_10 ;
struct V_11 V_12 = { V_13 , NULL } ;
V_10 . V_14 = 2 ;
V_10 . V_15 = & V_7 [ 0 ] ;
V_7 [ 0 ] . type = V_16 ;
V_7 [ 0 ] . integer . V_17 = V_3 ;
V_7 [ 1 ] . type = V_16 ;
V_7 [ 1 ] . integer . V_17 = V_4 ;
V_5 = F_2 ( V_1 , NULL , & V_10 , & V_12 ) ;
if ( F_3 ( V_5 ) ) {
F_4 ( L_1 , F_5 ( V_5 ) ) ;
return - V_18 ;
}
V_8 = (union V_6 * ) V_12 . V_15 ;
memcpy ( V_2 + V_3 , V_8 -> V_12 . V_15 , V_8 -> V_12 . V_19 ) ;
V_4 = V_8 -> V_12 . V_19 ;
F_6 ( V_12 . V_15 ) ;
return V_4 ;
}
bool F_7 ( struct V_20 * V_21 )
{
if ( ! V_22 . V_23 )
return false ;
if ( V_22 . V_24 == F_8 ( & V_21 -> V_25 ) )
return false ;
return true ;
}
int F_9 ( T_2 * V_2 , int V_3 , int V_4 )
{
return F_1 ( V_22 . V_1 , V_2 , V_3 , V_4 ) ;
}
static int F_10 ( T_1 V_26 )
{
T_3 V_5 ;
union V_6 V_27 [ 2 ] , * V_8 ;
struct V_9 V_28 ;
struct V_11 V_12 = { V_13 , NULL } ;
V_28 . V_14 = 2 ;
V_28 . V_15 = & V_27 [ 0 ] ;
V_27 [ 0 ] . type = V_16 ;
V_27 [ 0 ] . integer . V_17 = V_29 ;
V_27 [ 1 ] . type = V_16 ;
V_27 [ 1 ] . integer . V_17 = V_29 ;
V_5 = F_2 ( V_26 , NULL , & V_28 , & V_12 ) ;
if ( F_3 ( V_5 ) ) {
F_4 ( L_2 , V_30 , F_5 ( V_5 ) ) ;
return - V_31 ;
}
V_8 = (union V_6 * ) V_12 . V_15 ;
if ( V_8 && ( V_8 -> type == V_32 ) )
F_4 ( V_33 L_3 , * ( ( V_34 * ) ( V_8 -> V_12 . V_15 ) + 2 ) ) ;
F_6 ( V_12 . V_15 ) ;
return 0 ;
}
static int F_11 ( T_1 V_26 , int V_35 , T_4 V_17 )
{
T_3 V_5 ;
union V_6 V_27 [ 2 ] ;
struct V_9 V_28 ;
struct V_11 V_12 = { V_13 , NULL } ;
T_2 V_36 [ 4 ] = { 0 } ;
if ( ! V_26 )
return - V_37 ;
V_28 . V_14 = 2 ;
V_28 . V_15 = & V_27 [ 0 ] ;
V_27 [ 0 ] . type = V_16 ;
V_27 [ 0 ] . integer . V_17 = V_35 ;
V_36 [ 2 ] = V_17 & 0xff ;
V_36 [ 3 ] = ( V_17 >> 8 ) & 0xff ;
V_27 [ 1 ] . type = V_32 ;
V_27 [ 1 ] . V_12 . V_19 = 4 ;
V_27 [ 1 ] . V_12 . V_15 = V_36 ;
V_5 = F_2 ( V_26 , NULL , & V_28 , & V_12 ) ;
if ( F_3 ( V_5 ) ) {
F_4 ( L_2 , V_30 , F_5 ( V_5 ) ) ;
return - V_31 ;
}
F_6 ( V_12 . V_15 ) ;
return 0 ;
}
static int F_12 ( T_1 V_26 , int V_38 )
{
return F_11 ( V_26 , V_39 , V_38 ) ;
}
static int F_13 ( T_1 V_26 , int V_40 )
{
return F_11 ( V_26 , V_41 , V_40 ) ;
}
static int F_14 ( T_1 V_26 , int V_40 )
{
return F_11 ( V_26 , V_42 , V_40 ) ;
}
static int F_15 ( T_1 V_26 , int V_43 )
{
return F_11 ( V_26 , V_44 , V_43 ) ;
}
static int F_16 ( T_1 V_26 , int V_43 )
{
return F_11 ( V_26 , V_45 , V_43 ) ;
}
static int F_17 ( enum V_46 V_47 )
{
int V_43 ;
if ( V_47 == V_48 )
V_43 = V_49 ;
else
V_43 = V_50 ;
F_15 ( V_22 . V_51 , V_43 ) ;
F_13 ( V_22 . V_51 , V_43 ) ;
F_14 ( V_22 . V_51 , V_43 ) ;
F_16 ( V_22 . V_51 , V_43 ) ;
return 0 ;
}
static int F_18 ( enum V_46 V_47 ,
enum V_52 V_38 )
{
if ( V_47 == V_48 )
return 0 ;
F_12 ( V_22 . V_51 , V_38 ) ;
return 0 ;
}
static bool F_19 ( struct V_20 * V_21 )
{
T_1 V_24 , V_51 , V_1 ;
T_3 V_5 ;
V_24 = F_8 ( & V_21 -> V_25 ) ;
if ( ! V_24 )
return false ;
V_5 = F_20 ( V_24 , L_4 , & V_51 ) ;
if ( F_3 ( V_5 ) )
return false ;
V_5 = F_20 ( V_24 , L_5 , & V_1 ) ;
if ( F_3 ( V_5 ) )
return false ;
V_22 . V_24 = V_24 ;
V_22 . V_51 = V_51 ;
V_22 . V_1 = V_1 ;
return true ;
}
static int F_21 ( void )
{
F_10 ( V_22 . V_51 ) ;
return 0 ;
}
static int F_22 ( struct V_20 * V_21 )
{
if ( V_22 . V_24 == F_8 ( & V_21 -> V_25 ) )
return V_48 ;
else
return V_53 ;
}
static bool F_23 ( void )
{
char V_54 [ 255 ] = { 0 } ;
struct V_11 V_12 = { sizeof( V_54 ) , V_54 } ;
struct V_20 * V_21 = NULL ;
bool V_55 = false ;
int V_56 = 0 ;
while ( ( V_21 = F_24 ( V_57 << 8 , V_21 ) ) != NULL ) {
V_56 ++ ;
V_55 |= ( F_19 ( V_21 ) == true ) ;
}
if ( V_55 && V_56 == 2 ) {
F_25 ( V_22 . V_51 , V_58 , & V_12 ) ;
F_4 ( V_33 L_6 ,
V_54 ) ;
V_22 . V_23 = true ;
return true ;
}
return false ;
}
void F_26 ( void )
{
bool V_59 ;
V_59 = F_23 () ;
if ( ! V_59 )
return;
F_27 ( & V_60 ) ;
}
void F_28 ( void )
{
F_29 () ;
}
