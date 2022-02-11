static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_5 , T_1 V_6 )
{
T_1 V_7 ;
struct V_8 V_9 ;
T_1 V_10 [ 2 ] ;
int V_11 = 0 ;
struct V_12 * V_13 = F_2 ( V_2 ) ;
V_7 = V_13 -> V_14 [ V_3 ] ;
V_7 &= ~ V_5 ;
V_7 |= V_4 << V_6 ;
V_10 [ 0 ] = V_3 ;
V_10 [ 1 ] = V_7 ;
V_9 . V_15 = V_2 -> V_15 ;
V_9 . V_16 = 0 ;
V_9 . V_17 = 2 ;
V_9 . V_18 = V_10 ;
V_11 = F_3 ( V_2 -> V_19 , & V_9 , 1 ) ;
if ( V_11 < 0 ) {
F_4 ( & V_2 -> V_20 , L_1 , V_11 ) ;
return V_11 ;
}
V_13 -> V_14 [ V_3 ] = V_7 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_21 , T_1 * V_22 )
{
struct V_8 V_9 [ 2 ] ;
T_1 V_10 [ 2 ] ;
int V_11 ;
V_10 [ 0 ] = V_3 ;
V_9 [ 0 ] . V_15 = V_2 -> V_15 ;
V_9 [ 0 ] . V_16 = V_23 ;
V_9 [ 0 ] . V_17 = 1 ;
V_9 [ 0 ] . V_18 = V_10 ;
V_9 [ 1 ] . V_15 = V_2 -> V_15 ;
V_9 [ 1 ] . V_16 = V_24 ;
V_9 [ 1 ] . V_17 = V_21 ;
V_9 [ 1 ] . V_18 = V_22 ;
V_11 = F_3 ( V_2 -> V_19 , V_9 , 2 ) ;
if ( V_11 < 0 ) {
F_4 ( & V_2 -> V_20 , L_2 ) ;
return V_11 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_2 ( V_2 ) ;
T_1 V_25 ;
int V_11 ;
V_11 = F_5 ( V_2 , V_26 , 1 , & V_25 ) ;
if ( V_11 < 0 ) {
F_4 ( & V_2 -> V_20 , L_3 ) ;
return V_11 ;
}
if ( V_25 != V_27 ) {
F_4 ( & V_2 -> V_20 , L_4 ) ;
return - V_28 ;
}
V_11 = F_1 ( V_2 ,
V_29 ,
V_30 ,
V_31 ,
V_32 ) ;
if ( V_11 < 0 ) {
F_4 ( & V_2 -> V_20 , L_5 ) ;
return V_11 ;
}
V_11 = F_5 ( V_2 , V_33 , 3 , V_13 -> V_34 ) ;
if ( V_11 < 0 ) {
F_4 ( & V_2 -> V_20 , L_6 ) ;
return V_11 ;
}
V_13 -> V_35 [ 0 ] = ( ( V_13 -> V_34 [ 0 ] + 128 ) * 30 ) >> 8 ;
V_13 -> V_35 [ 1 ] = ( ( V_13 -> V_34 [ 1 ] + 128 ) * 30 ) >> 8 ;
V_13 -> V_35 [ 2 ] = ( ( V_13 -> V_34 [ 2 ] + 128 ) * 30 ) >> 8 ;
return 0 ;
}
static T_2 F_7 ( struct V_36 * V_20 , struct V_37 * V_38 ,
char * V_18 )
{
struct V_39 * V_40 = F_8 ( V_20 ) ;
struct V_12 * V_13 = V_40 -> V_41 ;
return sprintf ( V_18 , L_7 , V_13 -> V_42 ) ;
}
static T_2 F_9 ( struct V_36 * V_20 , struct V_37 * V_38 ,
const char * V_18 , T_3 V_43 )
{
struct V_39 * V_40 = F_8 ( V_20 ) ;
struct V_12 * V_13 = V_40 -> V_41 ;
struct V_1 * V_2 = V_13 -> V_2 ;
unsigned long V_44 ;
int V_11 ;
if ( F_10 ( V_18 , 10 , & V_44 ) )
return - V_45 ;
if ( V_44 > 1 ) {
F_4 ( V_20 , L_8 ) ;
return - V_45 ;
}
F_11 ( & V_13 -> V_46 ) ;
if ( V_13 -> V_42 != V_44 ) {
V_11 = F_1 ( V_2 ,
V_29 ,
( T_1 ) V_44 ,
V_31 ,
V_32 ) ;
if ( V_11 < 0 ) {
F_4 ( & V_2 -> V_20 , L_9 ) ;
F_12 ( & V_13 -> V_46 ) ;
return V_11 ;
}
V_13 -> V_42 = V_44 ;
}
F_12 ( & V_13 -> V_46 ) ;
return V_43 ;
}
static T_2 F_13 ( struct V_36 * V_20 , struct V_37 * V_38 ,
char * V_18 )
{
struct V_39 * V_40 = F_8 ( V_20 ) ;
struct V_12 * V_13 = V_40 -> V_41 ;
struct V_47 * V_48 = F_14 ( V_38 ) ;
return sprintf ( V_18 , L_10 , V_13 -> V_35 [ V_48 -> V_49 ] ) ;
}
static int F_15 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
T_1 V_50 ;
T_4 V_51 = V_52 ;
int V_11 ;
while ( V_51 ) {
F_16 ( V_53 ) ;
if ( F_17 ( V_13 -> V_54 ) )
break;
V_51 -= V_53 ;
}
if ( ! V_51 ) {
F_4 ( & V_2 -> V_20 , L_11 ) ;
return - V_45 ;
}
V_11 = F_5 ( V_2 , V_55 , 1 , & V_50 ) ;
if ( V_11 < 0 ) {
F_4 ( & V_2 -> V_20 , L_12 ) ;
return V_11 ;
}
return V_50 ;
}
static int F_18 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
T_1 V_50 ;
T_4 V_51 = V_52 ;
int V_11 ;
while ( V_51 ) {
F_16 ( V_53 ) ;
V_11 = F_5 ( V_2 , V_55 , 1 , & V_50 ) ;
if ( V_11 < 0 ) {
F_4 ( & V_2 -> V_20 , L_12 ) ;
return V_11 ;
}
if ( V_50 )
break;
V_51 -= V_53 ;
}
if ( ! V_51 ) {
F_4 ( & V_2 -> V_20 , L_11 ) ;
return - V_45 ;
}
return V_50 ;
}
static T_2 F_19 ( struct V_36 * V_20 , struct V_37 * V_38 ,
char * V_18 )
{
struct V_39 * V_40 = F_8 ( V_20 ) ;
struct V_12 * V_13 = V_40 -> V_41 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_47 * V_48 = F_14 ( V_38 ) ;
T_5 V_56 ;
T_6 V_57 ;
T_1 V_50 ;
int V_11 ;
F_11 ( & V_13 -> V_46 ) ;
if ( V_13 -> V_42 == 0 ) {
F_4 ( & V_2 -> V_20 , L_13 ) ;
V_11 = - V_58 ;
goto exit;
}
V_11 = F_1 ( V_2 ,
V_29 ,
V_59 ,
V_31 ,
V_32 ) ;
if ( V_11 < 0 ) {
F_4 ( & V_2 -> V_20 , L_14 ) ;
goto exit;
}
if ( V_13 -> V_54 )
V_11 = F_15 ( V_13 ) ;
else
V_11 = F_18 ( V_13 ) ;
if ( V_11 < 0 )
goto exit;
V_50 = V_11 ;
if ( V_50 & V_60 ) {
V_11 = F_5 ( V_2 , V_61 , 1 , & V_50 ) ;
if ( V_11 < 0 ) {
F_4 ( & V_2 -> V_20 , L_15 ) ;
goto exit;
}
if ( V_50 & ( V_62 |
V_63 ) ) {
F_4 ( & V_2 -> V_20 , L_16 ,
V_50 ) ;
V_11 = - V_45 ;
goto exit;
}
}
V_11 = F_5 ( V_2 , V_48 -> V_49 , 2 , ( T_1 * ) & V_56 ) ;
if ( V_11 < 0 ) {
F_4 ( & V_2 -> V_20 , L_17 ) ;
goto exit;
}
F_12 ( & V_13 -> V_46 ) ;
V_57 = ( T_6 ) ( F_20 ( V_56 ) ) ;
V_57 = F_21 ( T_6 , V_57 , - 4096 , 4095 ) ;
return sprintf ( V_18 , L_18 , V_57 ) ;
exit:
F_12 ( & V_13 -> V_46 ) ;
return V_11 ;
}
static int F_22 ( struct V_1 * V_2 ,
const struct V_64 * V_65 )
{
struct V_12 * V_13 ;
int V_66 ;
V_13 = F_23 ( sizeof( struct V_12 ) , V_67 ) ;
if ( ! V_13 ) {
F_4 ( & V_2 -> V_20 , L_19 ) ;
V_66 = - V_68 ;
goto exit;
}
F_24 ( V_2 , V_13 ) ;
V_13 -> V_2 = V_2 ;
F_25 ( & V_13 -> V_46 ) ;
V_13 -> V_69 = V_2 -> V_70 ;
V_13 -> V_54 = F_26 ( V_2 -> V_70 ) ;
if ( V_13 -> V_54 > 0 ) {
V_66 = F_27 ( V_13 -> V_54 , L_20 ) ;
if ( V_66 < 0 ) {
F_4 ( & V_2 -> V_20 ,
L_21 ,
V_13 -> V_54 , V_66 ) ;
goto V_71;
}
V_66 = F_28 ( V_13 -> V_54 ) ;
if ( V_66 < 0 ) {
F_4 ( & V_2 -> V_20 ,
L_22 ,
V_13 -> V_54 , V_66 ) ;
goto V_72;
}
} else
V_13 -> V_54 = 0 ;
V_66 = F_6 ( V_2 ) ;
if ( V_66 < 0 ) {
F_4 ( & V_2 -> V_20 , L_23 ) ;
goto V_72;
}
V_13 -> V_40 = F_29 ( 0 ) ;
if ( V_13 -> V_40 == NULL ) {
V_66 = - V_68 ;
goto V_72;
}
V_13 -> V_40 -> V_20 . V_73 = & V_2 -> V_20 ;
V_13 -> V_40 -> V_74 = & V_75 ;
V_13 -> V_40 -> V_41 = ( void * ) ( V_13 ) ;
V_13 -> V_40 -> V_76 = V_77 ;
V_66 = F_30 ( V_13 -> V_40 ) ;
if ( V_66 < 0 )
goto V_78;
return 0 ;
V_78:
F_31 ( V_13 -> V_40 ) ;
V_72:
if ( V_13 -> V_54 )
F_32 ( V_13 -> V_54 ) ;
V_71:
F_33 ( V_13 ) ;
exit:
return V_66 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_2 ( V_2 ) ;
F_35 ( V_13 -> V_40 ) ;
F_31 ( V_13 -> V_40 ) ;
if ( V_13 -> V_54 )
F_32 ( V_13 -> V_54 ) ;
F_33 ( V_13 ) ;
return 0 ;
}
static int T_7 F_36 ( void )
{
return F_37 ( & V_79 ) ;
}
static void T_8 F_38 ( void )
{
F_39 ( & V_79 ) ;
}
