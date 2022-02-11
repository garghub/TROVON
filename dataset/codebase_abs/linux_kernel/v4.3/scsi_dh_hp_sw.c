static int F_1 ( struct V_1 * V_2 , unsigned char * V_3 )
{
struct V_4 V_5 ;
int V_6 ;
V_6 = F_2 ( V_3 , V_7 , & V_5 ) ;
if ( ! V_6 ) {
F_3 ( V_8 , V_2 ,
L_1 ,
V_9 ) ;
V_6 = V_10 ;
goto V_11;
}
switch ( V_5 . V_12 ) {
case V_13 :
V_6 = V_14 ;
break;
case V_15 :
if ( ( V_5 . V_16 == 0x04 ) && ( V_5 . V_17 == 2 ) ) {
V_6 = V_18 ;
break;
}
default:
F_3 ( V_8 , V_2 ,
L_2 ,
V_9 , V_5 . V_12 , V_5 . V_16 ,
V_5 . V_17 ) ;
break;
}
V_11:
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
struct V_21 * V_22 ;
int V_6 ;
V_23:
V_22 = F_5 ( V_2 -> V_24 , V_25 , V_26 ) ;
if ( F_6 ( V_22 ) )
return V_27 ;
F_7 ( V_22 ) ;
V_22 -> V_28 |= V_29 | V_30 |
V_31 ;
V_22 -> V_32 = F_8 ( V_33 ) ;
V_22 -> V_34 [ 0 ] = V_33 ;
V_22 -> V_35 = V_36 ;
V_22 -> V_3 = V_20 -> V_3 ;
memset ( V_22 -> V_3 , 0 , V_7 ) ;
V_22 -> V_37 = 0 ;
V_6 = F_9 ( V_22 -> V_38 , NULL , V_22 , 1 ) ;
if ( V_6 == - V_39 ) {
if ( V_22 -> V_37 > 0 ) {
V_6 = F_1 ( V_2 , V_20 -> V_3 ) ;
} else {
F_3 ( V_8 , V_2 ,
L_3 ,
V_9 , V_22 -> V_40 ) ;
V_6 = V_10 ;
}
} else {
V_20 -> V_41 = V_42 ;
V_6 = V_43 ;
}
if ( V_6 == V_14 ) {
F_10 ( V_22 ) ;
goto V_23;
}
if ( V_6 == V_18 ) {
V_20 -> V_41 = V_44 ;
V_6 = V_43 ;
}
F_10 ( V_22 ) ;
return V_6 ;
}
static int F_11 ( struct V_1 * V_2 , unsigned char * V_3 )
{
struct V_4 V_5 ;
int V_45 ;
V_45 = F_2 ( V_3 , V_7 , & V_5 ) ;
if ( ! V_45 ) {
F_3 ( V_8 , V_2 ,
L_4
L_5 ,
V_9 ) ;
return V_10 ;
}
switch ( V_5 . V_12 ) {
case V_15 :
if ( ( V_5 . V_16 == 0x04 ) && ( V_5 . V_17 == 3 ) ) {
V_45 = V_46 ;
break;
}
default:
F_3 ( V_8 , V_2 ,
L_6 ,
V_9 , V_5 . V_12 , V_5 . V_16 ,
V_5 . V_17 ) ;
V_45 = V_10 ;
}
return V_45 ;
}
static void F_12 ( struct V_21 * V_22 , int error )
{
struct V_19 * V_20 = V_22 -> V_47 ;
unsigned V_48 = V_43 ;
if ( error || F_13 ( V_22 -> V_40 ) != V_49 ||
F_14 ( V_22 -> V_40 ) != V_50 ) {
F_3 ( V_8 , V_20 -> V_2 ,
L_7 ,
V_9 , V_22 -> V_40 ) ;
V_48 = V_10 ;
goto V_11;
}
if ( V_22 -> V_37 > 0 ) {
V_48 = F_11 ( V_20 -> V_2 , V_20 -> V_3 ) ;
if ( V_48 == V_46 ) {
V_48 = V_10 ;
if ( -- V_20 -> V_51 ) {
F_10 ( V_22 ) ;
V_48 = F_15 ( V_20 ) ;
if ( V_48 == V_43 )
return;
}
}
}
V_11:
V_22 -> V_47 = NULL ;
F_16 ( V_22 -> V_38 , V_22 ) ;
if ( V_20 -> V_52 ) {
V_20 -> V_52 ( V_20 -> V_53 , V_48 ) ;
V_20 -> V_52 = V_20 -> V_53 = NULL ;
}
return;
}
static int F_15 ( struct V_19 * V_20 )
{
struct V_21 * V_22 ;
V_22 = F_5 ( V_20 -> V_2 -> V_24 , V_25 , V_54 ) ;
if ( F_6 ( V_22 ) )
return V_27 ;
F_7 ( V_22 ) ;
V_22 -> V_28 |= V_29 | V_30 |
V_31 ;
V_22 -> V_32 = F_8 ( V_55 ) ;
V_22 -> V_34 [ 0 ] = V_55 ;
V_22 -> V_34 [ 4 ] = 1 ;
V_22 -> V_35 = V_36 ;
V_22 -> V_3 = V_20 -> V_3 ;
memset ( V_22 -> V_3 , 0 , V_7 ) ;
V_22 -> V_37 = 0 ;
V_22 -> V_47 = V_20 ;
F_17 ( V_22 -> V_38 , NULL , V_22 , 1 , F_12 ) ;
return V_43 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_19 * V_20 = V_2 -> V_56 ;
int V_6 = V_57 ;
if ( V_20 -> V_41 != V_42 ) {
V_6 = V_58 ;
V_22 -> V_28 |= V_59 ;
}
return V_6 ;
}
static int F_19 ( struct V_1 * V_2 ,
T_1 V_60 , void * V_61 )
{
int V_6 = V_43 ;
struct V_19 * V_20 = V_2 -> V_56 ;
V_6 = F_4 ( V_2 , V_20 ) ;
if ( V_6 == V_43 && V_20 -> V_41 == V_44 ) {
V_20 -> V_51 = V_20 -> V_62 ;
V_20 -> V_52 = V_60 ;
V_20 -> V_53 = V_61 ;
V_6 = F_15 ( V_20 ) ;
if ( V_6 == V_43 )
return 0 ;
V_20 -> V_52 = V_20 -> V_53 = NULL ;
}
if ( V_60 )
V_60 ( V_61 , V_6 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
int V_6 ;
V_20 = F_21 ( sizeof( * V_20 ) , V_63 ) ;
if ( ! V_20 )
return - V_64 ;
V_20 -> V_41 = V_65 ;
V_20 -> V_62 = V_66 ;
V_20 -> V_2 = V_2 ;
V_6 = F_4 ( V_2 , V_20 ) ;
if ( V_6 != V_43 || V_20 -> V_41 == V_65 )
goto V_67;
F_3 ( V_68 , V_2 , L_8 ,
V_9 , V_20 -> V_41 == V_42 ?
L_9 : L_10 ) ;
V_2 -> V_56 = V_20 ;
return 0 ;
V_67:
F_22 ( V_20 ) ;
return - V_69 ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_22 ( V_2 -> V_56 ) ;
V_2 -> V_56 = NULL ;
}
static int T_2 F_24 ( void )
{
return F_25 ( & V_70 ) ;
}
static void T_3 F_26 ( void )
{
F_27 ( & V_70 ) ;
}
