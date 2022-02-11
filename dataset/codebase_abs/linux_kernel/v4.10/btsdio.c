static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
F_2 ( L_1 , V_2 -> V_6 -> V_7 ) ;
F_3 ( V_4 , 4 ) ;
V_4 -> V_2 [ 0 ] = ( V_4 -> V_8 & 0x0000ff ) ;
V_4 -> V_2 [ 1 ] = ( V_4 -> V_8 & 0x00ff00 ) >> 8 ;
V_4 -> V_2 [ 2 ] = ( V_4 -> V_8 & 0xff0000 ) >> 16 ;
V_4 -> V_2 [ 3 ] = F_4 ( V_4 ) ;
V_5 = F_5 ( V_2 -> V_9 , V_10 , V_4 -> V_2 , V_4 -> V_8 ) ;
if ( V_5 < 0 ) {
F_6 ( V_4 , 4 ) ;
F_7 ( V_2 -> V_9 , 0x01 , V_11 , NULL ) ;
return V_5 ;
}
V_2 -> V_6 -> V_12 . V_13 += V_4 -> V_8 ;
F_8 ( V_4 ) ;
return 0 ;
}
static void F_9 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_10 ( V_15 , struct V_1 , V_15 ) ;
struct V_3 * V_4 ;
int V_5 ;
F_2 ( L_1 , V_2 -> V_6 -> V_7 ) ;
F_11 ( V_2 -> V_9 ) ;
while ( ( V_4 = F_12 ( & V_2 -> V_16 ) ) ) {
V_5 = F_1 ( V_2 , V_4 ) ;
if ( V_5 < 0 ) {
V_2 -> V_6 -> V_12 . V_17 ++ ;
F_13 ( & V_2 -> V_16 , V_4 ) ;
break;
}
}
F_14 ( V_2 -> V_9 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
T_1 V_18 [ 4 ] V_19 ( ( F_16 ( 4 ) ) ) ;
struct V_3 * V_4 ;
int V_5 , V_8 ;
F_2 ( L_1 , V_2 -> V_6 -> V_7 ) ;
V_5 = F_17 ( V_2 -> V_9 , V_18 , V_20 , 4 ) ;
if ( V_5 < 0 )
return V_5 ;
V_8 = V_18 [ 0 ] | ( V_18 [ 1 ] << 8 ) | ( V_18 [ 2 ] << 16 ) ;
if ( V_8 < 4 || V_8 > 65543 )
return - V_21 ;
V_4 = F_18 ( V_8 - 4 , V_22 ) ;
if ( ! V_4 ) {
return - V_23 ;
}
F_19 ( V_4 , V_8 - 4 ) ;
V_5 = F_17 ( V_2 -> V_9 , V_4 -> V_2 , V_20 , V_8 - 4 ) ;
if ( V_5 < 0 ) {
F_8 ( V_4 ) ;
return V_5 ;
}
V_2 -> V_6 -> V_12 . V_24 += V_8 ;
F_4 ( V_4 ) = V_18 [ 3 ] ;
V_5 = F_20 ( V_2 -> V_6 , V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
F_7 ( V_2 -> V_9 , 0x00 , V_25 , NULL ) ;
return 0 ;
}
static void F_21 ( struct V_26 * V_9 )
{
struct V_1 * V_2 = F_22 ( V_9 ) ;
int V_27 ;
F_2 ( L_1 , V_2 -> V_6 -> V_7 ) ;
V_27 = F_23 ( V_9 , V_28 , NULL ) ;
if ( V_27 & 0x01 ) {
F_7 ( V_9 , 0x01 , V_29 , NULL ) ;
if ( F_15 ( V_2 ) < 0 ) {
V_2 -> V_6 -> V_12 . V_30 ++ ;
F_7 ( V_2 -> V_9 , 0x01 , V_25 , NULL ) ;
}
}
}
static int F_24 ( struct V_31 * V_6 )
{
struct V_1 * V_2 = F_25 ( V_6 ) ;
int V_5 ;
F_2 ( L_1 , V_6 -> V_7 ) ;
F_11 ( V_2 -> V_9 ) ;
V_5 = F_26 ( V_2 -> V_9 ) ;
if ( V_5 < 0 )
goto V_32;
V_5 = F_27 ( V_2 -> V_9 , F_21 ) ;
if ( V_5 < 0 ) {
F_28 ( V_2 -> V_9 ) ;
goto V_32;
}
if ( V_2 -> V_9 -> V_33 == V_34 )
F_7 ( V_2 -> V_9 , 0x00 , V_35 , NULL ) ;
F_7 ( V_2 -> V_9 , 0x01 , V_36 , NULL ) ;
V_32:
F_14 ( V_2 -> V_9 ) ;
return V_5 ;
}
static int F_29 ( struct V_31 * V_6 )
{
struct V_1 * V_2 = F_25 ( V_6 ) ;
F_2 ( L_1 , V_6 -> V_7 ) ;
F_11 ( V_2 -> V_9 ) ;
F_7 ( V_2 -> V_9 , 0x00 , V_36 , NULL ) ;
F_30 ( V_2 -> V_9 ) ;
F_28 ( V_2 -> V_9 ) ;
F_14 ( V_2 -> V_9 ) ;
return 0 ;
}
static int F_31 ( struct V_31 * V_6 )
{
struct V_1 * V_2 = F_25 ( V_6 ) ;
F_2 ( L_1 , V_6 -> V_7 ) ;
F_32 ( & V_2 -> V_16 ) ;
return 0 ;
}
static int F_33 ( struct V_31 * V_6 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_25 ( V_6 ) ;
F_2 ( L_1 , V_6 -> V_7 ) ;
switch ( F_4 ( V_4 ) ) {
case V_37 :
V_6 -> V_12 . V_38 ++ ;
break;
case V_39 :
V_6 -> V_12 . V_40 ++ ;
break;
case V_41 :
V_6 -> V_12 . V_42 ++ ;
break;
default:
return - V_21 ;
}
F_34 ( & V_2 -> V_16 , V_4 ) ;
F_35 ( & V_2 -> V_15 ) ;
return 0 ;
}
static int F_36 ( struct V_26 * V_9 ,
const struct V_43 * V_44 )
{
struct V_1 * V_2 ;
struct V_31 * V_6 ;
struct V_45 * V_46 = V_9 -> V_47 ;
int V_5 ;
F_2 ( L_2 , V_9 , V_44 , V_9 -> V_33 ) ;
while ( V_46 ) {
F_2 ( L_3 , V_46 -> V_48 , V_46 -> V_49 ) ;
V_46 = V_46 -> V_50 ;
}
V_2 = F_37 ( & V_9 -> V_51 , sizeof( * V_2 ) , V_22 ) ;
if ( ! V_2 )
return - V_23 ;
V_2 -> V_9 = V_9 ;
F_38 ( & V_2 -> V_15 , F_9 ) ;
F_39 ( & V_2 -> V_16 ) ;
V_6 = F_40 () ;
if ( ! V_6 )
return - V_23 ;
V_6 -> V_52 = V_53 ;
F_41 ( V_6 , V_2 ) ;
if ( V_44 -> V_33 == V_54 )
V_6 -> V_55 = V_56 ;
else
V_6 -> V_55 = V_57 ;
V_2 -> V_6 = V_6 ;
F_42 ( V_6 , & V_9 -> V_51 ) ;
V_6 -> V_58 = F_24 ;
V_6 -> V_59 = F_29 ;
V_6 -> V_60 = F_31 ;
V_6 -> V_61 = F_33 ;
if ( V_9 -> V_62 == 0x0104 && V_9 -> V_63 == 0x00c5 )
F_43 ( V_64 , & V_6 -> V_65 ) ;
V_5 = F_44 ( V_6 ) ;
if ( V_5 < 0 ) {
F_45 ( V_6 ) ;
return V_5 ;
}
F_46 ( V_9 , V_2 ) ;
return 0 ;
}
static void F_47 ( struct V_26 * V_9 )
{
struct V_1 * V_2 = F_22 ( V_9 ) ;
struct V_31 * V_6 ;
F_2 ( L_4 , V_9 ) ;
if ( ! V_2 )
return;
V_6 = V_2 -> V_6 ;
F_46 ( V_9 , NULL ) ;
F_48 ( V_6 ) ;
F_45 ( V_6 ) ;
}
static int T_2 F_49 ( void )
{
F_50 ( L_5 , V_66 ) ;
return F_51 ( & V_67 ) ;
}
static void T_3 F_52 ( void )
{
F_53 ( & V_67 ) ;
}
