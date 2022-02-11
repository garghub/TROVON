static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = V_2 -> V_6 [ 0 ] ;
V_4 = F_2 ( sizeof( struct V_3 ) , V_7 ) ;
if ( ! V_4 ) {
F_3 ( & V_6 -> V_8 , L_1 ,
V_9 , sizeof( struct V_3 ) ) ;
return - V_10 ;
}
F_4 ( V_6 , V_4 ) ;
return 0 ;
}
static int F_5 ( struct V_11 * V_12 , struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_5 * V_13 ;
int V_14 = 0 ;
F_6 ( L_2 , V_9 , V_6 -> V_15 ) ;
V_13 = V_2 -> V_6 [ 1 ] ;
F_7 ( & V_13 -> V_6 , V_12 ) ;
F_8 ( V_6 -> V_16 , V_2 -> V_8 ,
F_9 ( V_2 -> V_8 ,
V_6 -> V_17 ) ,
V_6 -> V_16 -> V_18 ,
V_6 -> V_16 -> V_19 ,
V_20 , V_6 ) ;
V_14 = F_10 ( V_6 -> V_16 , V_7 ) ;
if ( V_14 )
F_3 ( & V_6 -> V_8 ,
L_3 ,
V_9 , V_14 ) ;
return V_14 ;
}
static void F_11 ( struct V_5 * V_6 )
{
F_6 ( L_2 , V_9 , V_6 -> V_15 ) ;
F_12 ( V_6 -> V_16 ) ;
}
static void V_20 ( struct V_21 * V_21 )
{
struct V_5 * V_6 = V_21 -> V_22 ;
unsigned char * V_23 = V_21 -> V_18 ;
struct V_24 * V_25 = (struct V_24 * ) & V_23 [ 0 ] ;
int V_26 = V_21 -> V_26 ;
int V_14 ;
int V_27 ;
F_6 ( L_2 , V_9 , V_6 -> V_15 ) ;
if ( V_26 ) {
F_6 ( L_4 ,
V_9 , V_26 ) ;
return;
}
if ( V_28 && V_25 -> V_29 != 0x30 ) {
if ( V_21 -> V_30 ) {
F_13 ( V_31 L_5 ,
__FILE__ , V_25 -> V_32 ) ;
for ( V_27 = 0 ; V_27 < ( V_25 -> V_32 +
V_33 ) ; V_27 ++ )
F_13 ( L_6 , V_23 [ V_27 ] ) ;
F_13 ( L_7 ) ;
}
}
if ( V_21 -> V_30 && V_25 -> V_32 ) {
struct V_11 * V_12 = F_14 ( & V_6 -> V_6 ) ;
F_15 ( V_12 , V_23 + V_34 ,
V_25 -> V_32 ) ;
F_16 ( V_12 ) ;
F_17 ( V_12 ) ;
}
F_8 ( V_21 , V_6 -> V_2 -> V_8 ,
F_9 ( V_6 -> V_2 -> V_8 ,
V_6 -> V_17 ) ,
V_21 -> V_18 , V_21 -> V_19 ,
V_20 , V_6 ) ;
V_14 = F_10 ( V_21 , V_35 ) ;
if ( V_14 )
F_3 ( & V_6 -> V_8 ,
L_8 ,
V_9 , V_14 ) ;
}
static int F_18 ( struct V_11 * V_12 , struct V_5 * V_6 ,
const unsigned char * V_36 , int V_37 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_5 * V_13 = V_2 -> V_6 [ 1 ] ;
struct V_3 * V_4 = F_19 ( V_6 ) ;
struct V_24 * V_25 = (struct V_24 * )
V_13 -> V_38 -> V_18 ;
int V_14 ;
F_6 ( L_2 , V_9 , V_6 -> V_15 ) ;
if ( V_37 == 0 ) {
F_6 ( L_9 , V_9 ) ;
return 0 ;
}
F_20 ( & V_13 -> V_39 ) ;
if ( V_13 -> V_40 ) {
F_21 ( & V_13 -> V_39 ) ;
F_6 ( L_10 , V_9 ) ;
return 0 ;
}
V_13 -> V_40 = 1 ;
F_21 ( & V_13 -> V_39 ) ;
V_37 = ( V_37 > V_41 ) ? V_41 : V_37 ;
memcpy ( V_13 -> V_38 -> V_18 + V_34 ,
V_36 , V_37 ) ;
F_22 ( V_28 , & V_6 -> V_8 , V_9 , V_37 ,
V_13 -> V_38 -> V_18 ) ;
V_25 -> V_42 = V_4 -> V_43 ++ ;
V_25 -> V_32 = V_37 ;
V_25 -> V_29 = 0x03 ;
V_25 -> V_44 = 0x00 ;
V_13 -> V_38 -> V_19 = 64 ;
V_13 -> V_38 -> V_8 = V_2 -> V_8 ;
V_14 = F_10 ( V_13 -> V_38 , V_35 ) ;
if ( V_14 ) {
V_13 -> V_40 = 0 ;
F_3 ( & V_6 -> V_8 ,
L_11 ,
V_9 , V_14 ) ;
} else
V_14 = V_37 ;
return V_14 ;
}
static int F_23 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = V_12 -> V_45 ;
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_5 * V_13 = V_2 -> V_6 [ 1 ] ;
int V_46 = 0 ;
if ( V_13 -> V_40 )
V_46 = V_13 -> V_47 - V_33 ;
F_6 ( L_12 , V_9 , V_46 ) ;
return V_46 ;
}
static void F_24 ( struct V_21 * V_21 )
{
struct V_5 * V_6 = V_21 -> V_22 ;
int V_26 = V_21 -> V_26 ;
F_6 ( L_13 , V_9 , V_6 -> V_15 ) ;
V_6 -> V_40 = 0 ;
if ( V_26 ) {
F_6 ( L_14 ,
V_9 , V_26 ) ;
return;
}
F_25 ( V_6 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_5 * V_13 = V_2 -> V_6 [ 1 ] ;
F_6 ( L_15 , V_9 ) ;
F_12 ( V_13 -> V_38 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 [ 0 ] ;
F_6 ( L_15 , V_9 ) ;
F_28 ( F_19 ( V_6 ) ) ;
}
static int T_1 F_29 ( void )
{
int V_48 ;
V_48 = F_30 ( & V_49 ) ;
if ( V_48 )
goto V_50;
V_48 = F_31 ( & V_51 ) ;
if ( V_48 )
goto V_52;
F_13 (KERN_INFO KBUILD_MODNAME L_16 DRIVER_VERSION L_17
DRIVER_DESC L_7 ) ;
return 0 ;
V_52:
F_32 ( & V_49 ) ;
V_50:
return V_48 ;
}
static void T_2 F_33 ( void )
{
F_34 ( & V_51 ) ;
F_32 ( & V_49 ) ;
}
