static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
F_2 ( V_7 , V_6 -> V_8 ) ;
F_2 ( V_9 , V_6 -> V_10 ) ;
F_3 ( V_6 , V_9 , 0 , 256 , 0 , 0 ) ;
}
static void F_4 ( struct V_5 * V_6 , const T_1 * V_11 , int V_12 )
{
int V_13 ;
F_5 ( V_6 , V_14 , ( V_11 [ 3 ] << 8 ) | V_11 [ 2 ] ) ;
F_5 ( V_6 , V_15 , ( V_11 [ 5 ] << 8 ) | V_11 [ 4 ] ) ;
V_13 = 0 ;
if ( V_11 [ 1 ] & 0x80 )
V_13 = ( V_11 [ 7 ] << 8 ) | V_11 [ 6 ] ;
F_5 ( V_6 , V_9 , V_13 ) ;
if ( V_11 [ 1 ] & 0x03 ) {
F_6 ( V_6 , V_7 , 1 ) ;
F_7 ( V_6 ) ;
}
if ( V_11 [ 1 ] & 0x04 )
F_6 ( V_6 , V_7 , 0 ) ;
F_7 ( V_6 ) ;
}
static int F_8 ( struct V_1 * V_2 , struct V_16 * V_17 ,
T_1 * V_11 , int V_12 )
{
struct V_3 * V_4 ;
if ( ! ( V_2 -> V_18 & V_19 ) || F_9 ( & V_2 -> V_20 ) )
return 0 ;
V_4 = F_10 ( & V_2 -> V_20 , struct V_3 , V_21 ) ;
switch ( V_17 -> V_22 ) {
case 0 :
if ( V_11 [ 0 ] == 'T' ) {
F_4 ( V_4 -> V_6 , V_11 , V_12 ) ;
return 1 ;
}
break;
default:
F_11 ( V_2 , L_1 , V_17 -> V_22 ) ;
break;
}
return 0 ;
}
static int F_12 ( struct V_23 * V_24 , T_1 V_25 ,
void * V_11 )
{
unsigned int V_26 ;
T_1 V_27 ;
if ( V_25 == V_28 ) {
V_26 = F_13 ( V_24 , 0 ) ;
V_27 = V_29 ;
} else if ( V_25 == V_30 ) {
V_26 = F_14 ( V_24 , 0 ) ;
V_27 = V_31 ;
} else
return - V_32 ;
return F_15 ( V_24 , V_26 , V_25 ,
V_27 | V_33 | V_34 ,
0 , 0 , V_11 , V_35 ,
V_36 ) ;
}
static int F_16 ( struct V_23 * V_24 )
{
return F_15 ( V_24 , F_13 ( V_24 , 0 ) ,
V_37 ,
V_29 | V_33 | V_34 ,
0 , 0 , NULL , 0 , V_38 ) ;
}
static void F_17 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = F_18 ( V_40 , struct V_41 , V_40 . V_40 ) ;
struct V_23 * V_24 = V_42 -> V_43 ;
unsigned char * V_44 = V_42 -> V_44 ;
int V_45 ;
V_45 = F_16 ( V_24 ) ;
if ( V_45 < 0 ) {
F_19 ( & V_24 -> V_24 , L_2 ,
V_45 ) ;
goto V_46;
}
* V_44 = V_47 ;
V_45 = F_12 ( V_24 , V_28 , V_44 ) ;
if ( V_45 < 0 ) {
F_19 ( & V_24 -> V_24 , L_3 ,
V_45 ) ;
goto V_46;
}
V_45 = F_12 ( V_24 , V_30 , V_44 ) ;
if ( V_45 < 0 ) {
F_19 ( & V_24 -> V_24 , L_4 ,
V_45 ) ;
goto V_46;
}
if ( * V_44 != 'A' ) {
V_45 = F_12 ( V_24 , V_30 ,
V_44 ) ;
if ( V_45 < 0 ) {
F_19 ( & V_24 -> V_24 , L_5 ,
V_45 ) ;
goto V_46;
}
}
V_46:
V_45 = F_16 ( V_24 ) ;
if ( V_45 < 0 )
F_19 ( & V_24 -> V_24 , L_6 ,
V_45 ) ;
F_20 ( V_48 , & V_42 -> V_40 , V_49 ) ;
}
static bool F_21 ( struct V_23 * V_24 )
{
return V_50 && F_22 ( V_24 -> V_51 . V_52 ) == 0x10d ;
}
static int F_23 ( struct V_1 * V_2 , const struct V_53 * V_22 )
{
struct V_41 * V_42 ;
int V_45 ;
V_42 = F_24 ( sizeof( * V_42 ) , V_54 ) ;
if ( ! V_42 )
return - V_55 ;
F_25 ( & V_42 -> V_40 , F_17 ) ;
V_42 -> V_43 = F_26 ( F_27 ( V_2 -> V_24 . V_56 ) ) ;
F_28 ( V_2 , V_42 ) ;
V_45 = F_29 ( V_2 ) ;
if ( V_45 ) {
F_30 ( V_2 , L_7 ) ;
goto V_57;
}
V_45 = F_31 ( V_2 , V_58 ) ;
if ( V_45 ) {
F_30 ( V_2 , L_8 ) ;
goto V_57;
}
if ( F_21 ( V_42 -> V_43 ) ) {
F_11 ( V_2 , L_9 ) ;
F_20 ( V_48 , & V_42 -> V_40 , V_49 ) ;
}
return 0 ;
V_57:
F_32 ( V_42 ) ;
return V_45 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = F_34 ( V_2 ) ;
F_35 ( V_2 ) ;
F_36 ( V_48 ) ;
F_32 ( V_42 ) ;
}
static int T_2 F_37 ( void )
{
int V_45 ;
V_48 = F_38 ( L_10 ) ;
if ( ! V_48 )
return - V_55 ;
V_45 = F_39 ( & V_59 ) ;
if ( V_45 )
F_40 ( V_48 ) ;
return V_45 ;
}
static void T_3 F_41 ( void )
{
F_42 ( & V_59 ) ;
F_40 ( V_48 ) ;
}
