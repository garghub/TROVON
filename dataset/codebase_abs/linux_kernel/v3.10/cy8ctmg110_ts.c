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
if ( V_11 != V_7 + 1 ) {
F_6 ( & V_10 -> V_13 , L_1 ) ;
return V_11 < 0 ? V_11 : - V_14 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_5 ,
unsigned char * V_15 , unsigned char V_7 , unsigned char V_16 )
{
struct V_9 * V_10 = V_5 -> V_10 ;
int V_11 ;
struct V_17 V_18 [ 2 ] = {
{
. V_19 = V_10 -> V_19 ,
. V_7 = 1 ,
. V_20 = & V_16
} ,
{
. V_19 = V_10 -> V_19 ,
. V_21 = V_22 ,
. V_7 = V_7 ,
. V_20 = V_15
}
} ;
V_11 = F_8 ( V_10 -> V_23 , V_18 , 2 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_5 )
{
struct V_24 * V_25 = V_5 -> V_25 ;
unsigned char V_26 [ V_27 ] ;
int V_28 , V_29 ;
memset ( V_26 , 0 , V_27 ) ;
if ( F_7 ( V_5 , V_26 , 9 , V_30 ) != 0 )
return - V_14 ;
V_29 = V_26 [ 2 ] << 8 | V_26 [ 3 ] ;
V_28 = V_26 [ 0 ] << 8 | V_26 [ 1 ] ;
if ( V_26 [ 8 ] == 0 ) {
F_10 ( V_25 , V_31 , 0 ) ;
} else {
F_10 ( V_25 , V_31 , 1 ) ;
F_11 ( V_25 , V_32 , V_28 ) ;
F_11 ( V_25 , V_33 , V_29 ) ;
}
F_12 ( V_25 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , bool V_34 )
{
unsigned char V_26 [ 3 ] ;
if ( V_34 ) {
V_26 [ 0 ] = 0x00 ;
V_26 [ 1 ] = 0xff ;
V_26 [ 2 ] = 5 ;
} else {
V_26 [ 0 ] = 0x10 ;
V_26 [ 1 ] = 0xff ;
V_26 [ 2 ] = 0 ;
}
return F_3 ( V_2 , V_35 , 3 , V_26 ) ;
}
static T_1 F_14 ( int V_36 , void * V_37 )
{
struct V_1 * V_5 = V_37 ;
F_9 ( V_5 ) ;
return V_38 ;
}
static int F_15 ( struct V_9 * V_10 ,
const struct V_39 * V_40 )
{
const struct V_41 * V_42 = V_10 -> V_13 . V_43 ;
struct V_1 * V_2 ;
struct V_24 * V_24 ;
int V_44 ;
if ( V_42 == NULL ) {
F_6 ( & V_10 -> V_13 , L_2 ) ;
return - V_45 ;
}
if ( ! F_16 ( V_10 -> V_23 ,
V_46 ) )
return - V_14 ;
V_2 = F_17 ( sizeof( struct V_1 ) , V_47 ) ;
V_24 = F_18 () ;
if ( ! V_2 || ! V_24 ) {
V_44 = - V_48 ;
goto V_49;
}
V_2 -> V_10 = V_10 ;
V_2 -> V_25 = V_24 ;
V_2 -> V_4 = V_42 -> V_4 ;
V_2 -> V_50 = V_42 -> V_50 ;
snprintf ( V_2 -> V_51 , sizeof( V_2 -> V_51 ) ,
L_3 , F_19 ( & V_10 -> V_13 ) ) ;
V_24 -> V_52 = V_53 L_4 ;
V_24 -> V_51 = V_2 -> V_51 ;
V_24 -> V_40 . V_54 = V_55 ;
V_24 -> V_13 . V_56 = & V_10 -> V_13 ;
V_24 -> V_57 [ 0 ] = F_20 ( V_58 ) | F_20 ( V_59 ) ;
V_24 -> V_60 [ F_21 ( V_31 ) ] = F_20 ( V_31 ) ;
F_22 ( V_24 , V_32 ,
V_61 , V_62 , 4 , 0 ) ;
F_22 ( V_24 , V_33 ,
V_63 , V_64 , 4 , 0 ) ;
if ( V_2 -> V_4 ) {
V_44 = F_23 ( V_2 -> V_4 , NULL ) ;
if ( V_44 ) {
F_6 ( & V_10 -> V_13 ,
L_5 ,
V_2 -> V_4 ) ;
goto V_49;
}
}
F_1 ( V_2 , true ) ;
F_13 ( V_2 , false ) ;
V_44 = F_23 ( V_2 -> V_50 , L_6 ) ;
if ( V_44 < 0 ) {
F_6 ( & V_10 -> V_13 ,
L_7 ,
V_2 -> V_50 , V_44 ) ;
goto V_65;
}
V_44 = F_24 ( V_2 -> V_50 ) ;
if ( V_44 < 0 ) {
F_6 ( & V_10 -> V_13 ,
L_8 ,
V_2 -> V_50 , V_44 ) ;
goto V_66;
}
V_10 -> V_36 = F_25 ( V_2 -> V_50 ) ;
if ( V_10 -> V_36 < 0 ) {
V_44 = V_10 -> V_36 ;
F_6 ( & V_10 -> V_13 ,
L_9 ,
V_2 -> V_50 , V_44 ) ;
goto V_66;
}
V_44 = F_26 ( V_10 -> V_36 , NULL , F_14 ,
V_67 | V_68 ,
L_10 , V_2 ) ;
if ( V_44 < 0 ) {
F_6 ( & V_10 -> V_13 ,
L_11 , V_10 -> V_36 , V_44 ) ;
goto V_66;
}
V_44 = F_27 ( V_24 ) ;
if ( V_44 )
goto V_69;
F_28 ( V_10 , V_2 ) ;
F_29 ( & V_10 -> V_13 , 1 ) ;
return 0 ;
V_69:
F_30 ( V_10 -> V_36 , V_2 ) ;
V_66:
F_31 ( V_2 -> V_50 ) ;
V_65:
F_13 ( V_2 , true ) ;
F_1 ( V_2 , false ) ;
if ( V_2 -> V_4 )
F_31 ( V_2 -> V_4 ) ;
V_49:
F_32 ( V_24 ) ;
F_33 ( V_2 ) ;
return V_44 ;
}
static int F_34 ( struct V_70 * V_13 )
{
struct V_9 * V_10 = F_35 ( V_13 ) ;
struct V_1 * V_2 = F_36 ( V_10 ) ;
if ( F_37 ( & V_10 -> V_13 ) )
F_38 ( V_10 -> V_36 ) ;
else {
F_13 ( V_2 , true ) ;
F_1 ( V_2 , false ) ;
}
return 0 ;
}
static int F_39 ( struct V_70 * V_13 )
{
struct V_9 * V_10 = F_35 ( V_13 ) ;
struct V_1 * V_2 = F_36 ( V_10 ) ;
if ( F_37 ( & V_10 -> V_13 ) )
F_40 ( V_10 -> V_36 ) ;
else {
F_1 ( V_2 , true ) ;
F_13 ( V_2 , false ) ;
}
return 0 ;
}
static int F_41 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_36 ( V_10 ) ;
F_13 ( V_2 , true ) ;
F_1 ( V_2 , false ) ;
F_30 ( V_10 -> V_36 , V_2 ) ;
F_42 ( V_2 -> V_25 ) ;
F_31 ( V_2 -> V_50 ) ;
if ( V_2 -> V_4 )
F_31 ( V_2 -> V_4 ) ;
F_33 ( V_2 ) ;
return 0 ;
}
