static void F_1 ( void )
{
if ( V_1 || V_2 )
F_2 ( V_3 , 1 ) ;
else
F_2 ( V_3 , 0 ) ;
}
static void F_3 ( int V_4 )
{
V_1 = V_4 ;
F_1 () ;
}
static void F_4 ( int V_4 )
{
V_2 = V_4 ;
F_1 () ;
}
static void T_1 F_5 ( void )
{
F_6 () ;
}
static void T_1 F_7 ( void )
{
F_8 () ;
}
static void T_1 F_9 ( enum V_5 V_6 )
{
struct V_7 * V_8 , * V_9 = NULL ;
struct V_10 * V_11 ;
const T_2 * V_12 = F_10 () ;
T_3 * V_13 ;
T_2 V_14 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < 2 ; V_15 ++ ) {
V_8 = F_11 ( V_9 , NULL , L_1 ) ;
if ( ! V_8 )
return;
V_9 = V_8 ;
V_11 = F_12 ( sizeof( * V_11 ) + 6 , V_16 ) ;
if ( ! V_11 )
return;
V_11 -> V_17 = V_11 + 1 ;
V_11 -> V_18 = 6 ;
V_11 -> V_19 = F_13 ( L_2 , V_16 ) ;
if ( ! V_11 -> V_19 ) {
F_14 ( V_11 ) ;
return;
}
V_13 = V_11 -> V_17 ;
switch ( V_6 ) {
case V_20 :
V_13 [ 0 ] = 0x00 ;
V_13 [ 1 ] = 0x04 ;
V_13 [ 2 ] = 0x9f ;
break;
case V_21 :
V_13 [ 0 ] = 0xc0 ;
V_13 [ 1 ] = 0xe5 ;
V_13 [ 2 ] = 0x4e ;
break;
}
V_14 = V_12 [ V_15 ] ;
V_13 [ 3 ] = ( V_14 >> 16 ) & 0xff ;
V_13 [ 4 ] = ( V_14 >> 8 ) & 0xff ;
V_13 [ 5 ] = ( V_14 >> 0 ) & 0xff ;
F_15 ( V_8 , V_11 ) ;
}
}
static void T_1 F_16 ( void )
{
V_22 . V_23 = V_24 ;
V_22 . V_25 = F_17 ( V_24 ) ;
V_22 . V_26 = 32 ;
V_22 . V_27 = V_28 ;
}
static inline void F_18 ( void )
{
struct V_29 * V_29 = F_19 ( L_3 , NULL ) ;
if ( ! F_20 ( V_29 ) )
F_21 ( V_29 ) ;
}
static void T_1 F_22 ( void )
{
F_18 () ;
F_9 ( V_20 ) ;
V_22 . V_23 = V_30 ;
V_22 . V_25 = F_17 ( V_30 ) ;
V_22 . V_26 = 32 ;
V_22 . V_27 = V_28 ;
F_23 ( V_31 ) ;
}
static void T_1 F_24 ( void )
{
if ( ! F_25 ( V_3 , V_32 ,
L_4 ) ) {
V_33 [ 0 ] . V_34 = F_3 ;
V_33 [ 1 ] . V_34 = F_4 ;
}
}
static void T_1 F_26 ( void )
{
V_22 . V_23 = V_35 ;
V_22 . V_25 = F_17 ( V_35 ) ;
V_22 . V_26 = 16 ;
V_22 . V_27 = V_36 ;
}
static int F_27 ( struct V_37 * V_38 )
{
V_38 -> V_39 |= V_40 ;
return 0 ;
}
static void T_1 F_28 ( void )
{
F_18 () ;
if ( F_29 ( V_41 ) )
F_30 ( V_42 , V_43 ,
F_27 ) ;
V_22 . V_23 = V_44 ;
V_22 . V_25 = F_17 ( V_44 ) ;
V_22 . V_26 = 32 ;
V_22 . V_27 = V_28 ;
}
static void T_1 F_31 ( void )
{
struct V_7 * V_8 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
int V_49 ;
F_18 () ;
V_8 = F_11 ( NULL , NULL , L_1 ) ;
V_46 = F_32 ( V_8 ) ;
if ( ! V_46 ) {
F_33 ( L_5 , V_50 ) ;
return;
}
V_48 = F_34 ( & V_46 -> V_51 , L_6 ) ;
if ( F_20 ( V_48 ) ) {
F_33 ( L_7 , V_50 ) ;
return;
}
V_49 = F_35 ( V_52 , F_17 ( V_52 ) ) ;
if ( V_49 ) {
F_33 ( L_8 , V_50 , V_49 ) ;
return;
}
F_2 ( V_53 , 1 ) ;
F_36 ( 26 ) ;
F_2 ( V_54 , 1 ) ;
F_2 ( V_55 , 1 ) ;
F_2 ( V_56 , 1 ) ;
F_37 ( 100 ) ;
F_2 ( V_57 , 1 ) ;
F_38 ( V_48 ) ;
}
static void T_1 F_39 ( void )
{
if ( F_40 ( L_9 ) )
F_22 () ;
else if ( F_40 ( L_10 ) )
F_16 () ;
else if ( F_40 ( L_11 ) )
F_26 () ;
else if ( F_40 ( L_12 ) )
F_28 () ;
F_41 ( NULL , V_58 ,
V_59 , NULL ) ;
if ( F_40 ( L_13 ) )
F_31 () ;
if ( F_40 ( L_9 ) )
F_24 () ;
}
