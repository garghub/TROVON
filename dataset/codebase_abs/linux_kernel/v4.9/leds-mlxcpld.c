static enum
V_1 F_1 ( void )
{
const char * V_2 ;
int V_3 ;
V_2 = F_2 ( V_4 ) ;
if ( ! V_2 )
return V_5 ;
for ( V_3 = 1 ; V_3 < F_3 ( V_6 ) ; V_3 ++ ) {
if ( strstr ( V_2 , V_6 [ V_3 ] ) )
return V_3 ;
}
return V_5 ;
}
static void F_4 ( T_1 V_7 , T_2 V_8 , T_2 V_9 ,
T_2 * V_10 )
{
T_3 V_11 = V_7 + V_8 ;
if ( V_9 == 0 )
F_5 ( * V_10 , V_11 ) ;
else
* V_10 = F_6 ( V_11 ) ;
}
static void F_7 ( T_2 V_12 , T_2 V_13 , T_2 V_14 )
{
T_2 V_15 , V_16 ;
F_8 ( & V_17 -> V_18 ) ;
F_4 ( V_19 , V_13 , 1 ,
& V_16 ) ;
V_15 = ( V_12 == 0xf0 ) ? V_14 : ( V_14 << 4 ) ;
V_16 = ( V_16 & V_12 ) | V_15 ;
F_4 ( V_19 , V_13 , 0 ,
& V_16 ) ;
F_9 ( & V_17 -> V_18 ) ;
}
static void F_10 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
struct V_24 * V_25 = F_11 ( V_21 ) ;
if ( V_23 ) {
F_7 ( V_25 -> V_26 . V_12 , V_25 -> V_26 . V_8 ,
V_25 -> V_26 . V_27 ) ;
return;
}
F_7 ( V_25 -> V_26 . V_12 , V_25 -> V_26 . V_8 ,
V_28 ) ;
}
static int F_12 ( struct V_20 * V_21 ,
unsigned long * V_29 ,
unsigned long * V_30 )
{
struct V_24 * V_25 = F_11 ( V_21 ) ;
if ( ! ( * V_29 == 0 && * V_30 == 0 ) &&
! ( * V_29 == V_31 &&
* V_30 == V_31 ) &&
! ( * V_29 == V_32 &&
* V_30 == V_32 ) )
return - V_33 ;
if ( * V_29 == V_32 )
F_7 ( V_25 -> V_26 . V_12 , V_25 -> V_26 . V_8 ,
V_25 -> V_26 . V_27 +
V_34 ) ;
else
F_7 ( V_25 -> V_26 . V_12 , V_25 -> V_26 . V_8 ,
V_25 -> V_26 . V_27 +
V_35 ) ;
return 0 ;
}
static int F_13 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
int V_3 ;
int V_40 ;
V_39 -> V_25 = F_14 ( V_37 , sizeof( struct V_24 ) *
V_39 -> V_41 , V_42 ) ;
if ( ! V_39 -> V_25 )
return - V_43 ;
for ( V_3 = 0 ; V_3 < V_39 -> V_41 ; V_3 ++ ) {
V_39 -> V_25 [ V_3 ] . V_44 . V_45 = V_39 -> V_46 [ V_3 ] . V_45 ;
V_39 -> V_25 [ V_3 ] . V_44 . V_47 = V_39 -> V_46 [ V_3 ] . V_47 ;
V_39 -> V_25 [ V_3 ] . V_44 . V_48 = 1 ;
V_39 -> V_25 [ V_3 ] . V_44 . V_49 = F_10 ;
V_39 -> V_25 [ V_3 ] . V_44 . V_50 = F_12 ;
V_39 -> V_25 [ V_3 ] . V_44 . V_51 = V_52 ;
V_40 = F_15 ( V_37 , & V_39 -> V_25 [ V_3 ] . V_44 ) ;
if ( V_40 )
return V_40 ;
V_39 -> V_25 [ V_3 ] . V_26 . V_8 = V_17 -> V_46 [ V_3 ] . V_8 ;
V_39 -> V_25 [ V_3 ] . V_26 . V_12 = V_17 -> V_46 [ V_3 ] . V_12 ;
V_39 -> V_25 [ V_3 ] . V_26 . V_27 =
V_17 -> V_46 [ V_3 ] . V_27 ;
if ( V_17 -> V_46 [ V_3 ] . V_47 )
F_10 ( & V_39 -> V_25 [ V_3 ] . V_44 ,
V_17 -> V_46 [ V_3 ] . V_47 ) ;
}
return 0 ;
}
static int T_4 F_16 ( struct V_53 * V_54 )
{
enum V_1 V_55 =
F_1 () ;
V_17 = F_14 ( & V_54 -> V_37 , sizeof( * V_17 ) ,
V_42 ) ;
if ( ! V_17 )
return - V_43 ;
V_17 -> V_54 = V_54 ;
switch ( V_55 ) {
case V_56 :
V_17 -> V_46 = V_57 ;
V_17 -> V_41 =
F_3 ( V_57 ) ;
break;
default:
V_17 -> V_46 = V_58 ;
V_17 -> V_41 =
F_3 ( V_58 ) ;
break;
}
F_17 ( & V_17 -> V_18 ) ;
return F_13 ( & V_54 -> V_37 , V_17 ) ;
}
static int T_4 F_18 ( void )
{
struct V_53 * V_54 ;
int V_40 ;
V_54 = F_19 ( V_59 , - 1 , NULL , 0 ) ;
if ( F_20 ( V_54 ) ) {
F_21 ( L_1 ) ;
return F_22 ( V_54 ) ;
}
V_40 = F_23 ( & V_60 , F_16 ) ;
if ( V_40 ) {
F_21 ( L_2 ) ;
F_24 ( V_54 ) ;
}
return V_40 ;
}
static void T_5 F_25 ( void )
{
F_24 ( V_17 -> V_54 ) ;
F_26 ( & V_60 ) ;
}
