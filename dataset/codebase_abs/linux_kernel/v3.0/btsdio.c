static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
F_2 ( L_1 , V_2 -> V_6 -> V_7 ) ;
F_3 ( V_4 , 4 ) ;
V_4 -> V_2 [ 0 ] = ( V_4 -> V_8 & 0x0000ff ) ;
V_4 -> V_2 [ 1 ] = ( V_4 -> V_8 & 0x00ff00 ) >> 8 ;
V_4 -> V_2 [ 2 ] = ( V_4 -> V_8 & 0xff0000 ) >> 16 ;
V_4 -> V_2 [ 3 ] = F_4 ( V_4 ) -> V_9 ;
V_5 = F_5 ( V_2 -> V_10 , V_11 , V_4 -> V_2 , V_4 -> V_8 ) ;
if ( V_5 < 0 ) {
F_6 ( V_4 , 4 ) ;
F_7 ( V_2 -> V_10 , 0x01 , V_12 , NULL ) ;
return V_5 ;
}
V_2 -> V_6 -> V_13 . V_14 += V_4 -> V_8 ;
F_8 ( V_4 ) ;
return 0 ;
}
static void F_9 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_10 ( V_16 , struct V_1 , V_16 ) ;
struct V_3 * V_4 ;
int V_5 ;
F_2 ( L_1 , V_2 -> V_6 -> V_7 ) ;
F_11 ( V_2 -> V_10 ) ;
while ( ( V_4 = F_12 ( & V_2 -> V_17 ) ) ) {
V_5 = F_1 ( V_2 , V_4 ) ;
if ( V_5 < 0 ) {
V_2 -> V_6 -> V_13 . V_18 ++ ;
F_13 ( & V_2 -> V_17 , V_4 ) ;
break;
}
}
F_14 ( V_2 -> V_10 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
T_1 V_19 [ 4 ] V_20 ( ( F_16 ( 4 ) ) ) ;
struct V_3 * V_4 ;
int V_5 , V_8 ;
F_2 ( L_1 , V_2 -> V_6 -> V_7 ) ;
V_5 = F_17 ( V_2 -> V_10 , V_19 , V_21 , 4 ) ;
if ( V_5 < 0 )
return V_5 ;
V_8 = V_19 [ 0 ] | ( V_19 [ 1 ] << 8 ) | ( V_19 [ 2 ] << 16 ) ;
if ( V_8 < 4 || V_8 > 65543 )
return - V_22 ;
V_4 = F_18 ( V_8 - 4 , V_23 ) ;
if ( ! V_4 ) {
return - V_24 ;
}
F_19 ( V_4 , V_8 - 4 ) ;
V_5 = F_17 ( V_2 -> V_10 , V_4 -> V_2 , V_21 , V_8 - 4 ) ;
if ( V_5 < 0 ) {
F_8 ( V_4 ) ;
return V_5 ;
}
V_2 -> V_6 -> V_13 . V_25 += V_8 ;
V_4 -> V_26 = ( void * ) V_2 -> V_6 ;
F_4 ( V_4 ) -> V_9 = V_19 [ 3 ] ;
V_5 = F_20 ( V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
F_7 ( V_2 -> V_10 , 0x00 , V_27 , NULL ) ;
return 0 ;
}
static void F_21 ( struct V_28 * V_10 )
{
struct V_1 * V_2 = F_22 ( V_10 ) ;
int V_29 ;
F_2 ( L_1 , V_2 -> V_6 -> V_7 ) ;
V_29 = F_23 ( V_10 , V_30 , NULL ) ;
if ( V_29 & 0x01 ) {
F_7 ( V_10 , 0x01 , V_31 , NULL ) ;
if ( F_15 ( V_2 ) < 0 ) {
V_2 -> V_6 -> V_13 . V_32 ++ ;
F_7 ( V_2 -> V_10 , 0x01 , V_27 , NULL ) ;
}
}
}
static int F_24 ( struct V_33 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_34 ;
int V_5 ;
F_2 ( L_1 , V_6 -> V_7 ) ;
if ( F_25 ( V_35 , & V_6 -> V_36 ) )
return 0 ;
F_11 ( V_2 -> V_10 ) ;
V_5 = F_26 ( V_2 -> V_10 ) ;
if ( V_5 < 0 ) {
F_27 ( V_35 , & V_6 -> V_36 ) ;
goto V_37;
}
V_5 = F_28 ( V_2 -> V_10 , F_21 ) ;
if ( V_5 < 0 ) {
F_29 ( V_2 -> V_10 ) ;
F_27 ( V_35 , & V_6 -> V_36 ) ;
goto V_37;
}
if ( V_2 -> V_10 -> V_38 == V_39 )
F_7 ( V_2 -> V_10 , 0x00 , V_40 , NULL ) ;
F_7 ( V_2 -> V_10 , 0x01 , V_41 , NULL ) ;
V_37:
F_14 ( V_2 -> V_10 ) ;
return V_5 ;
}
static int F_30 ( struct V_33 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_34 ;
F_2 ( L_1 , V_6 -> V_7 ) ;
if ( ! F_31 ( V_35 , & V_6 -> V_36 ) )
return 0 ;
F_11 ( V_2 -> V_10 ) ;
F_7 ( V_2 -> V_10 , 0x00 , V_41 , NULL ) ;
F_32 ( V_2 -> V_10 ) ;
F_29 ( V_2 -> V_10 ) ;
F_14 ( V_2 -> V_10 ) ;
return 0 ;
}
static int F_33 ( struct V_33 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_34 ;
F_2 ( L_1 , V_6 -> V_7 ) ;
F_34 ( & V_2 -> V_17 ) ;
return 0 ;
}
static int F_35 ( struct V_3 * V_4 )
{
struct V_33 * V_6 = (struct V_33 * ) V_4 -> V_26 ;
struct V_1 * V_2 = V_6 -> V_34 ;
F_2 ( L_1 , V_6 -> V_7 ) ;
if ( ! F_36 ( V_35 , & V_6 -> V_36 ) )
return - V_42 ;
switch ( F_4 ( V_4 ) -> V_9 ) {
case V_43 :
V_6 -> V_13 . V_44 ++ ;
break;
case V_45 :
V_6 -> V_13 . V_46 ++ ;
break;
case V_47 :
V_6 -> V_13 . V_48 ++ ;
break;
default:
return - V_22 ;
}
F_37 ( & V_2 -> V_17 , V_4 ) ;
F_38 ( & V_2 -> V_16 ) ;
return 0 ;
}
static void F_39 ( struct V_33 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_34 ;
F_2 ( L_1 , V_6 -> V_7 ) ;
F_40 ( V_2 ) ;
}
static int F_41 ( struct V_28 * V_10 ,
const struct V_49 * V_50 )
{
struct V_1 * V_2 ;
struct V_33 * V_6 ;
struct V_51 * V_52 = V_10 -> V_53 ;
int V_5 ;
F_2 ( L_2 , V_10 , V_50 , V_10 -> V_38 ) ;
while ( V_52 ) {
F_2 ( L_3 , V_52 -> V_54 , V_52 -> V_55 ) ;
V_52 = V_52 -> V_56 ;
}
V_2 = F_42 ( sizeof( * V_2 ) , V_23 ) ;
if ( ! V_2 )
return - V_24 ;
V_2 -> V_10 = V_10 ;
F_43 ( & V_2 -> V_16 , F_9 ) ;
F_44 ( & V_2 -> V_17 ) ;
V_6 = F_45 () ;
if ( ! V_6 ) {
F_40 ( V_2 ) ;
return - V_24 ;
}
V_6 -> V_57 = V_58 ;
V_6 -> V_34 = V_2 ;
if ( V_50 -> V_38 == V_59 )
V_6 -> V_60 = V_61 ;
else
V_6 -> V_60 = V_62 ;
V_2 -> V_6 = V_6 ;
F_46 ( V_6 , & V_10 -> V_26 ) ;
V_6 -> V_63 = F_24 ;
V_6 -> V_64 = F_30 ;
V_6 -> V_65 = F_33 ;
V_6 -> V_66 = F_35 ;
V_6 -> V_67 = F_39 ;
V_6 -> V_68 = V_69 ;
V_5 = F_47 ( V_6 ) ;
if ( V_5 < 0 ) {
F_48 ( V_6 ) ;
F_40 ( V_2 ) ;
return V_5 ;
}
F_49 ( V_10 , V_2 ) ;
return 0 ;
}
static void F_50 ( struct V_28 * V_10 )
{
struct V_1 * V_2 = F_22 ( V_10 ) ;
struct V_33 * V_6 ;
F_2 ( L_4 , V_10 ) ;
if ( ! V_2 )
return;
V_6 = V_2 -> V_6 ;
F_49 ( V_10 , NULL ) ;
F_51 ( V_6 ) ;
F_48 ( V_6 ) ;
}
static int T_2 F_52 ( void )
{
F_53 ( L_5 , V_70 ) ;
return F_54 ( & V_71 ) ;
}
static void T_3 F_55 ( void )
{
F_56 ( & V_71 ) ;
}
