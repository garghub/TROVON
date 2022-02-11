static int T_1 F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
F_2 ( V_2 , 128 , 0 , 0 , & V_4 , NULL ) ;
return 0 ;
}
static int T_1 F_3 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
static int V_5 = V_6 ;
F_2 ( V_2 , 32 , V_5 , 0 , & V_4 , NULL ) ;
V_5 += 32 ;
return 0 ;
}
static void T_1 F_4 ( void )
{
F_5 () ;
F_6 ( V_7 ) ;
}
static void T_1 F_7 ( void )
{
F_8 () ;
}
static void T_1 F_9 ( void )
{
F_10 () ;
}
static void T_1 F_11 ( enum V_8 V_9 )
{
struct V_1 * V_2 , * V_10 = NULL ;
struct V_11 * V_12 ;
const T_2 * V_13 = F_12 () ;
T_3 * V_14 ;
T_2 V_15 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ ) {
V_2 = F_13 ( V_10 , NULL , L_1 ) ;
if ( ! V_2 )
return;
V_10 = V_2 ;
V_12 = F_14 ( sizeof( * V_12 ) + 6 , V_17 ) ;
if ( ! V_12 )
return;
V_12 -> V_18 = V_12 + 1 ;
V_12 -> V_19 = 6 ;
V_12 -> V_20 = F_15 ( L_2 , V_17 ) ;
if ( ! V_12 -> V_20 ) {
F_16 ( V_12 ) ;
return;
}
V_14 = V_12 -> V_18 ;
switch ( V_9 ) {
case V_21 :
V_14 [ 0 ] = 0x00 ;
V_14 [ 1 ] = 0x04 ;
V_14 [ 2 ] = 0x9f ;
break;
case V_22 :
V_14 [ 0 ] = 0xc0 ;
V_14 [ 1 ] = 0xe5 ;
V_14 [ 2 ] = 0x4e ;
break;
}
V_15 = V_13 [ V_16 ] ;
V_14 [ 3 ] = ( V_15 >> 16 ) & 0xff ;
V_14 [ 4 ] = ( V_15 >> 8 ) & 0xff ;
V_14 [ 5 ] = ( V_15 >> 0 ) & 0xff ;
F_17 ( V_2 , V_12 ) ;
}
}
static void T_1 F_18 ( void )
{
V_23 . V_24 = V_25 ;
V_23 . V_26 = F_19 ( V_25 ) ;
V_23 . V_27 = 32 ;
V_23 . V_28 = V_29 ;
}
static inline void F_20 ( void )
{
struct V_30 * V_30 = F_21 ( L_3 , NULL ) ;
if ( ! F_22 ( V_30 ) )
F_23 ( V_30 ) ;
}
static void T_1 F_24 ( void )
{
F_20 () ;
F_11 ( V_21 ) ;
V_23 . V_24 = V_31 ;
V_23 . V_26 = F_19 ( V_31 ) ;
V_23 . V_27 = 32 ;
V_23 . V_28 = V_29 ;
}
static void T_1 F_25 ( void )
{
F_20 () ;
F_11 ( V_22 ) ;
V_23 . V_24 = V_32 ;
V_23 . V_26 = F_19 ( V_32 ) ;
V_23 . V_27 = 16 ;
V_23 . V_28 = V_33 ;
}
static int F_26 ( struct V_34 * V_35 )
{
V_35 -> V_36 |= V_37 ;
return 0 ;
}
static void T_1 F_27 ( void )
{
F_20 () ;
if ( F_28 ( V_38 ) )
F_29 ( V_39 , V_40 ,
F_26 ) ;
V_23 . V_24 = V_41 ;
V_23 . V_26 = F_19 ( V_41 ) ;
V_23 . V_27 = 32 ;
V_23 . V_28 = V_29 ;
}
static void T_1 F_30 ( void )
{
if ( F_31 ( L_4 ) )
F_24 () ;
else if ( F_31 ( L_5 ) )
F_18 () ;
else if ( F_31 ( L_6 ) )
F_25 () ;
else if ( F_31 ( L_7 ) )
F_27 () ;
F_32 ( NULL , V_42 ,
V_43 , NULL ) ;
}
