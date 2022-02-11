static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
if ( V_2 -> V_4 )
F_2 ( V_2 -> V_4 , 1 - V_3 ) ;
}
static int F_3 ( struct V_1 * V_5 , unsigned char V_6 ,
unsigned char V_7 , unsigned char * V_8 )
{
struct V_9 * V_10 = V_5 -> V_10 ;
int V_11 ;
unsigned char V_12 [ 6 ] ;
F_4 ( V_7 > 5 ) ;
V_12 [ 0 ] = V_6 ;
memcpy ( V_12 + 1 , V_8 , V_7 ) ;
V_11 = F_5 ( V_10 , V_12 , V_7 + 1 ) ;
if ( V_11 != 1 ) {
F_6 ( & V_10 -> V_13 , L_1 ) ;
return V_11 ? V_11 : - V_14 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_5 ,
unsigned char * V_15 , unsigned char V_7 , unsigned char V_16 )
{
struct V_9 * V_10 = V_5 -> V_10 ;
int V_11 ;
struct V_17 V_18 [ 2 ] = {
{ V_10 -> V_19 , 0 , 1 , & V_16 } ,
{ V_10 -> V_19 , V_20 , V_7 , V_15 }
} ;
V_11 = F_8 ( V_10 -> V_21 , V_18 , 2 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_5 )
{
struct V_22 * V_23 = V_5 -> V_23 ;
unsigned char V_24 [ V_25 ] ;
int V_26 , V_27 ;
memset ( V_24 , 0 , V_25 ) ;
if ( F_7 ( V_5 , V_24 , 9 , V_28 ) != 0 )
return - V_14 ;
V_27 = V_24 [ 2 ] << 8 | V_24 [ 3 ] ;
V_26 = V_24 [ 0 ] << 8 | V_24 [ 1 ] ;
if ( V_24 [ 8 ] == 0 ) {
F_10 ( V_23 , V_29 , 0 ) ;
} else {
F_10 ( V_23 , V_29 , 1 ) ;
F_11 ( V_23 , V_30 , V_26 ) ;
F_11 ( V_23 , V_31 , V_27 ) ;
}
F_12 ( V_23 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , bool V_32 )
{
unsigned char V_24 [ 3 ] ;
if ( V_32 ) {
V_24 [ 0 ] = 0x00 ;
V_24 [ 1 ] = 0xff ;
V_24 [ 2 ] = 5 ;
} else {
V_24 [ 0 ] = 0x10 ;
V_24 [ 1 ] = 0xff ;
V_24 [ 2 ] = 0 ;
}
return F_3 ( V_2 , V_33 , 3 , V_24 ) ;
}
static T_1 F_14 ( int V_34 , void * V_35 )
{
struct V_1 * V_5 = V_35 ;
F_9 ( V_5 ) ;
return V_36 ;
}
static int T_2 F_15 ( struct V_9 * V_10 ,
const struct V_37 * V_38 )
{
const struct V_39 * V_40 = V_10 -> V_13 . V_41 ;
struct V_1 * V_2 ;
struct V_22 * V_22 ;
int V_42 ;
if ( V_40 == NULL ) {
F_6 ( & V_10 -> V_13 , L_2 ) ;
return - V_43 ;
}
if ( ! F_16 ( V_10 -> V_21 ,
V_44 ) )
return - V_14 ;
V_2 = F_17 ( sizeof( struct V_1 ) , V_45 ) ;
V_22 = F_18 () ;
if ( ! V_2 || ! V_22 ) {
V_42 = - V_46 ;
goto V_47;
}
V_2 -> V_10 = V_10 ;
V_2 -> V_23 = V_22 ;
snprintf ( V_2 -> V_48 , sizeof( V_2 -> V_48 ) ,
L_3 , F_19 ( & V_10 -> V_13 ) ) ;
V_22 -> V_49 = V_50 L_4 ;
V_22 -> V_48 = V_2 -> V_48 ;
V_22 -> V_38 . V_51 = V_52 ;
V_22 -> V_13 . V_53 = & V_10 -> V_13 ;
V_22 -> V_54 [ 0 ] = F_20 ( V_55 ) | F_20 ( V_56 ) ;
V_22 -> V_57 [ F_21 ( V_29 ) ] = F_20 ( V_29 ) ;
F_22 ( V_22 , V_30 ,
V_58 , V_59 , 4 , 0 ) ;
F_22 ( V_22 , V_31 ,
V_60 , V_61 , 4 , 0 ) ;
if ( V_2 -> V_4 ) {
V_42 = F_23 ( V_2 -> V_4 , NULL ) ;
if ( V_42 ) {
F_6 ( & V_10 -> V_13 ,
L_5 ,
V_2 -> V_4 ) ;
goto V_47;
}
}
F_1 ( V_2 , true ) ;
F_13 ( V_2 , false ) ;
V_42 = F_23 ( V_2 -> V_62 , L_6 ) ;
if ( V_42 < 0 ) {
F_6 ( & V_10 -> V_13 ,
L_7 ,
V_2 -> V_62 , V_42 ) ;
goto V_63;
}
V_42 = F_24 ( V_2 -> V_62 ) ;
if ( V_42 < 0 ) {
F_6 ( & V_10 -> V_13 ,
L_8 ,
V_2 -> V_62 , V_42 ) ;
goto V_64;
}
V_10 -> V_34 = F_25 ( V_2 -> V_62 ) ;
if ( V_10 -> V_34 < 0 ) {
V_42 = V_10 -> V_34 ;
F_6 ( & V_10 -> V_13 ,
L_9 ,
V_2 -> V_62 , V_42 ) ;
goto V_64;
}
V_42 = F_26 ( V_10 -> V_34 , NULL , F_14 ,
V_65 , L_10 , V_2 ) ;
if ( V_42 < 0 ) {
F_6 ( & V_10 -> V_13 ,
L_11 , V_10 -> V_34 , V_42 ) ;
goto V_64;
}
V_42 = F_27 ( V_22 ) ;
if ( V_42 )
goto V_66;
F_28 ( V_10 , V_2 ) ;
F_29 ( & V_10 -> V_13 , 1 ) ;
return 0 ;
V_66:
F_30 ( V_10 -> V_34 , V_2 ) ;
V_64:
F_31 ( V_2 -> V_62 ) ;
V_63:
F_13 ( V_2 , true ) ;
F_1 ( V_2 , false ) ;
if ( V_2 -> V_4 )
F_31 ( V_2 -> V_4 ) ;
V_47:
F_32 ( V_22 ) ;
F_33 ( V_2 ) ;
return V_42 ;
}
static int F_34 ( struct V_67 * V_13 )
{
struct V_9 * V_10 = F_35 ( V_13 ) ;
struct V_1 * V_2 = F_36 ( V_10 ) ;
if ( F_37 ( & V_10 -> V_13 ) )
F_38 ( V_10 -> V_34 ) ;
else {
F_13 ( V_2 , true ) ;
F_1 ( V_2 , false ) ;
}
return 0 ;
}
static int F_39 ( struct V_67 * V_13 )
{
struct V_9 * V_10 = F_35 ( V_13 ) ;
struct V_1 * V_2 = F_36 ( V_10 ) ;
if ( F_37 ( & V_10 -> V_13 ) )
F_40 ( V_10 -> V_34 ) ;
else {
F_1 ( V_2 , true ) ;
F_13 ( V_2 , false ) ;
}
return 0 ;
}
static int T_3 F_41 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_36 ( V_10 ) ;
F_13 ( V_2 , true ) ;
F_1 ( V_2 , false ) ;
F_30 ( V_10 -> V_34 , V_2 ) ;
F_42 ( V_2 -> V_23 ) ;
F_31 ( V_2 -> V_62 ) ;
if ( V_2 -> V_4 )
F_31 ( V_2 -> V_4 ) ;
F_33 ( V_2 ) ;
return 0 ;
}
static int T_4 F_43 ( void )
{
return F_44 ( & V_68 ) ;
}
static void T_5 F_45 ( void )
{
F_46 ( & V_68 ) ;
}
