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
if ( F_12 ( V_8 , L_2 , NULL ) )
continue;
V_11 = F_13 ( sizeof( * V_11 ) + 6 , V_16 ) ;
if ( ! V_11 )
return;
V_11 -> V_17 = V_11 + 1 ;
V_11 -> V_18 = 6 ;
V_11 -> V_19 = F_14 ( L_2 , V_16 ) ;
if ( ! V_11 -> V_19 ) {
F_15 ( V_11 ) ;
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
case V_22 :
V_13 [ 0 ] = 0x58 ;
V_13 [ 1 ] = 0xb9 ;
V_13 [ 2 ] = 0xe1 ;
break;
}
V_14 = V_12 [ V_15 ] ;
V_13 [ 3 ] = ( V_14 >> 16 ) & 0xff ;
V_13 [ 4 ] = ( V_14 >> 8 ) & 0xff ;
V_13 [ 5 ] = ( V_14 >> 0 ) & 0xff ;
F_16 ( V_8 , V_11 ) ;
}
}
static void T_1 F_17 ( void )
{
V_23 . V_24 = V_25 ;
V_23 . V_26 = F_18 ( V_25 ) ;
V_23 . V_27 = 32 ;
V_23 . V_28 = V_29 ;
V_23 . V_30 = V_31 |
V_32 ;
}
static inline void F_19 ( void )
{
struct V_33 * V_33 = F_20 ( L_3 , NULL ) ;
if ( ! F_21 ( V_33 ) )
F_22 ( V_33 ) ;
}
static void T_1 F_23 ( void )
{
F_19 () ;
F_9 ( V_20 ) ;
V_23 . V_24 = V_34 ;
V_23 . V_26 = F_18 ( V_34 ) ;
V_23 . V_27 = 32 ;
V_23 . V_28 = V_29 ;
V_23 . V_30 = V_31 |
V_32 ;
F_24 ( V_35 ) ;
}
static void T_1 F_25 ( void )
{
if ( ! F_26 ( V_3 , V_36 ,
L_4 ) ) {
V_37 [ 0 ] . V_38 = F_3 ;
V_37 [ 1 ] . V_38 = F_4 ;
}
}
static void T_1 F_27 ( void )
{
V_23 . V_24 = V_39 ;
V_23 . V_26 = F_18 ( V_39 ) ;
V_23 . V_27 = 16 ;
V_23 . V_28 = V_40 ;
V_23 . V_30 = V_31 ;
}
static void T_1 F_28 ( void )
{
F_19 () ;
}
static int F_29 ( struct V_41 * V_42 )
{
V_42 -> V_43 |= V_44 ;
return 0 ;
}
static void T_1 F_30 ( void )
{
F_19 () ;
if ( F_31 ( V_45 ) )
F_32 ( V_46 , V_47 ,
F_29 ) ;
V_23 . V_24 = V_48 ;
V_23 . V_26 = F_18 ( V_48 ) ;
V_23 . V_27 = 32 ;
V_23 . V_28 = V_29 ;
V_23 . V_30 = V_31 |
V_32 ;
}
static void T_1 F_33 ( void )
{
struct V_7 * V_8 ;
struct V_49 * V_50 ;
struct V_51 * V_52 ;
int V_53 ;
F_19 () ;
V_8 = F_11 ( NULL , NULL , L_1 ) ;
V_50 = F_34 ( V_8 ) ;
if ( ! V_50 ) {
F_35 ( L_5 , V_54 ) ;
return;
}
V_52 = F_36 ( & V_50 -> V_55 , L_6 ) ;
if ( F_21 ( V_52 ) ) {
F_35 ( L_7 , V_54 ) ;
return;
}
V_53 = F_37 ( V_56 , F_18 ( V_56 ) ) ;
if ( V_53 ) {
F_35 ( L_8 , V_54 , V_53 ) ;
return;
}
F_2 ( V_57 , 1 ) ;
F_38 ( 26 ) ;
F_2 ( V_58 , 1 ) ;
F_2 ( V_59 , 1 ) ;
F_2 ( V_60 , 1 ) ;
F_39 ( 100 ) ;
F_2 ( V_61 , 1 ) ;
F_40 ( V_52 ) ;
}
static void T_1 F_41 ( void )
{
F_19 () ;
F_9 ( V_22 ) ;
V_23 . V_24 = V_62 ;
V_23 . V_26 = F_18 ( V_62 ) ;
V_23 . V_27 = 32 ;
V_23 . V_28 = V_40 ;
V_23 . V_30 = V_31 ;
}
static void T_1 F_42 ( void )
{
F_19 () ;
F_9 ( V_22 ) ;
}
static void T_1 F_43 ( void )
{
F_19 () ;
V_23 . V_24 = V_63 ;
V_23 . V_26 = F_18 ( V_63 ) ;
V_23 . V_27 = 16 ;
V_23 . V_28 = V_64 ;
V_23 . V_30 = V_31 |
V_32 ;
}
static void T_1 F_44 ( void )
{
if ( F_45 ( L_9 ) )
F_23 () ;
else if ( F_45 ( L_10 ) )
F_17 () ;
else if ( F_45 ( L_11 ) )
F_27 () ;
else if ( F_45 ( L_12 ) )
F_30 () ;
else if ( F_45 ( L_13 ) )
F_42 () ;
else if ( F_45 ( L_14 ) )
F_41 () ;
else if ( F_45 ( L_15 ) )
F_43 () ;
else if ( F_45 ( L_16 ) )
F_28 () ;
F_46 ( NULL , V_65 ,
V_66 , NULL ) ;
if ( F_45 ( L_17 ) )
F_33 () ;
if ( F_45 ( L_9 ) )
F_25 () ;
}
