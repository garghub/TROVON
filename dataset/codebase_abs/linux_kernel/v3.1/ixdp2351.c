static void F_1 ( struct V_1 * V_2 )
{
* V_3 = F_2 ( V_2 -> V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
* V_5 = F_2 ( V_2 -> V_4 ) ;
}
static void F_4 ( unsigned int V_4 , struct V_6 * V_7 )
{
T_1 V_8 =
* V_9 & V_10 ;
int V_11 ;
V_7 -> V_1 . V_12 -> V_13 ( & V_7 -> V_1 ) ;
for ( V_11 = 0 ; V_11 < V_14 ; V_11 ++ ) {
if ( V_8 & ( 1 << V_11 ) ) {
int V_15 =
F_5 ( V_16 + V_11 ) ;
F_6 ( V_15 ) ;
}
}
V_7 -> V_1 . V_12 -> V_17 ( & V_7 -> V_1 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
* V_18 = F_8 ( V_2 -> V_4 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
* V_19 = F_8 ( V_2 -> V_4 ) ;
}
static void F_10 ( unsigned int V_4 , struct V_6 * V_7 )
{
T_1 V_8 =
* V_20 & V_21 ;
int V_11 ;
V_7 -> V_1 . V_12 -> V_22 ( & V_7 -> V_1 ) ;
for ( V_11 = 0 ; V_11 < V_23 ; V_11 ++ ) {
if ( V_8 & ( 1 << V_11 ) ) {
int V_15 =
F_5 ( V_24 + V_11 ) ;
F_6 ( V_15 ) ;
}
}
V_7 -> V_1 . V_12 -> V_17 ( & V_7 -> V_1 ) ;
}
void T_2 F_11 ( void )
{
int V_4 ;
* V_3 = ( T_1 ) - 1 ;
* V_18 = ( T_1 ) - 1 ;
* V_25 = 0 ;
* V_26 = 0 ;
F_12 () ;
for ( V_4 = F_5 ( V_16 ) ;
V_4 <
F_5 ( V_16 + V_14 ) ;
V_4 ++ ) {
if ( F_2 ( V_4 ) & V_10 ) {
F_13 ( V_4 , V_27 ) ;
F_14 ( V_4 , & V_28 ,
V_29 ) ;
}
}
for ( V_4 = F_5 ( V_24 ) ;
V_4 <
F_5 ( V_24 + V_23 ) ;
V_4 ++ ) {
if ( F_8 ( V_4 ) & V_21 ) {
F_13 ( V_4 , V_27 ) ;
F_14 ( V_4 , & V_30 ,
V_29 ) ;
}
}
F_15 ( V_31 , F_4 ) ;
F_15 ( V_32 , F_10 ) ;
}
static int T_2 F_16 ( const struct V_33 * V_34 , T_3 V_35 , T_3 V_36 )
{
T_3 V_37 = V_34 -> V_37 -> V_38 ;
T_4 V_39 = F_17 ( F_18 ( V_34 -> V_40 ) , V_36 ) ;
struct V_41 * V_42 = V_34 -> V_37 ;
if ( ! V_37 )
return - 1 ;
while ( ( V_42 -> V_43 != NULL ) && ( V_42 -> V_43 -> V_43 != NULL ) )
V_42 = V_42 -> V_43 ;
switch ( V_42 -> V_44 -> V_40 | ( V_42 -> V_44 -> V_37 -> V_38 << 8 ) ) {
case 0x0008 :
if ( V_42 == V_34 -> V_37 ) {
switch ( V_39 ) {
case F_17 ( 1 , 1 ) :
return V_45 ;
case F_17 ( 1 , 2 ) :
return V_46 ;
case F_17 ( 0 , 1 ) :
case F_17 ( 2 , 4 ) :
return V_47 ;
case F_17 ( 0 , 2 ) :
case F_17 ( 2 , 1 ) :
return V_48 ;
case F_17 ( 0 , 3 ) :
case F_17 ( 2 , 2 ) :
return V_49 ;
case F_17 ( 0 , 4 ) :
case F_17 ( 2 , 3 ) :
return V_50 ;
}
} else {
return - 1 ;
}
break;
case 0x0010 :
if ( V_42 == V_34 -> V_37 ) {
switch ( V_39 ) {
case F_17 ( 0 , 1 ) :
case F_17 ( 0 , 2 ) :
case F_17 ( 0 , 3 ) :
case F_17 ( 0 , 4 ) :
return V_51 ;
case F_17 ( 1 , 1 ) :
case F_17 ( 1 , 2 ) :
case F_17 ( 1 , 3 ) :
case F_17 ( 1 , 4 ) :
return V_52 ;
case F_17 ( 2 , 1 ) :
case F_17 ( 2 , 2 ) :
case F_17 ( 2 , 3 ) :
case F_17 ( 2 , 4 ) :
case F_17 ( 3 , 1 ) :
case F_17 ( 3 , 2 ) :
case F_17 ( 3 , 3 ) :
case F_17 ( 3 , 4 ) :
return V_53 ;
}
} else {
return - 1 ;
}
break;
}
return - 1 ;
}
int T_2 F_19 ( void )
{
if ( F_20 () )
F_21 ( & V_54 ) ;
return 0 ;
}
static void T_2 F_22 ( void )
{
F_23 () ;
F_24 ( V_55 , F_25 ( V_55 ) ) ;
}
static void T_2 F_26 ( void )
{
F_27 ( & V_56 ) ;
V_57 [ 0 ] |= V_58 ;
V_57 [ 1 ] |= V_58 ;
V_57 [ 2 ] |= V_58 ;
V_57 [ 3 ] |= V_58 ;
F_28 () ;
}
