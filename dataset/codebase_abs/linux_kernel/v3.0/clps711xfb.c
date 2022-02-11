static int
F_1 ( T_1 V_1 , T_1 V_2 , T_1 V_3 , T_1 V_4 ,
T_1 V_5 , struct V_6 * V_7 )
{
unsigned int V_8 , V_9 , V_10 , V_11 ;
if ( V_1 >= ( 1 << V_7 -> V_12 . V_13 ) )
return 1 ;
V_8 = ( V_2 * 77 + V_3 * 151 + V_4 * 28 ) >> 20 ;
if ( F_2 () ) {
V_8 = 15 - V_8 ;
}
V_10 = 4 * ( V_1 & 7 ) ;
V_8 <<= V_10 ;
V_9 = 15 << V_10 ;
V_8 &= V_9 ;
V_1 = V_1 < 8 ? V_14 : V_15 ;
V_11 = F_3 ( V_1 ) ;
V_11 = ( V_11 & ~ V_9 ) | V_8 ;
F_4 ( V_11 , V_1 ) ;
return 0 ;
}
static int
F_5 ( struct V_16 * V_12 , struct V_6 * V_7 )
{
V_12 -> V_5 . V_17 = 0 ;
V_12 -> V_5 . V_18 = 0 ;
V_12 -> V_5 . V_19 = 0 ;
V_12 -> V_2 . V_17 = 0 ;
V_12 -> V_2 . V_18 = 0 ;
V_12 -> V_2 . V_19 = V_12 -> V_13 ;
V_12 -> V_3 = V_12 -> V_2 ;
V_12 -> V_4 = V_12 -> V_2 ;
if ( V_12 -> V_13 > 4 )
return - V_20 ;
return 0 ;
}
static int
F_6 ( struct V_6 * V_7 )
{
unsigned int V_21 , V_22 , V_23 ;
switch ( V_7 -> V_12 . V_13 ) {
case 1 :
V_7 -> V_24 . V_25 = V_26 ;
break;
case 2 :
V_7 -> V_24 . V_25 = V_27 ;
break;
case 4 :
V_7 -> V_24 . V_25 = V_27 ;
break;
}
V_7 -> V_24 . V_28 = V_7 -> V_12 . V_29 * V_7 -> V_12 . V_13 / 8 ;
V_21 = ( V_7 -> V_12 . V_29 * V_7 -> V_12 . V_30 * V_7 -> V_12 . V_13 ) / 128 - 1 ;
V_21 |= ( ( V_7 -> V_12 . V_29 / 16 ) - 1 ) << 13 ;
V_21 |= V_31 << 25 ;
V_23 = 9 * V_7 -> V_12 . V_23 / 244140 - 1 ;
V_21 |= V_23 << 19 ;
if ( V_7 -> V_12 . V_13 == 4 )
V_21 |= V_32 ;
if ( V_7 -> V_12 . V_13 >= 2 )
V_21 |= V_33 ;
V_22 = F_3 ( V_34 ) ;
F_4 ( V_22 & ~ V_35 , V_34 ) ;
F_4 ( V_21 , V_36 ) ;
F_4 ( V_22 | V_35 , V_34 ) ;
return 0 ;
}
static int F_7 ( int V_37 , struct V_6 * V_7 )
{
if ( V_37 ) {
if ( F_2 () ) {
F_8 ( F_9 ( V_38 ) & ~ V_39 , V_38 ) ;
F_8 ( F_9 ( V_38 ) & ~ V_40 , V_38 ) ;
F_10 ( 100 ) ;
F_8 ( F_9 ( V_38 ) & ~ V_41 , V_38 ) ;
F_4 ( F_3 ( V_34 ) & ~ V_35 ,
V_34 ) ;
}
} else {
if ( F_2 () ) {
F_4 ( F_3 ( V_34 ) | V_35 ,
V_34 ) ;
F_8 ( F_9 ( V_38 ) | V_41 , V_38 ) ;
F_10 ( 100 ) ;
F_8 ( F_9 ( V_38 ) | V_40 ,
V_38 ) ;
F_8 ( F_9 ( V_38 ) | V_39 , V_38 ) ;
}
}
return 0 ;
}
static int F_11 ( struct V_42 * V_43 , void * V_44 )
{
if ( F_2 () ) {
F_12 ( V_43 , L_1 ,
( F_9 ( V_38 ) & V_39 ) ? 1 : 0 ) ;
}
return 0 ;
}
static int F_13 ( struct V_45 * V_45 , struct V_46 * V_46 )
{
return F_14 ( V_46 , F_11 , NULL ) ;
}
static T_2 F_15 ( struct V_46 * V_46 , const char * V_47 ,
T_3 V_48 , T_4 * V_49 )
{
unsigned char V_50 ;
int V_51 ;
if ( V_48 < 1 ) {
return - V_20 ;
}
if ( F_16 ( & V_50 , V_47 , 1 ) )
return - V_52 ;
V_51 = V_50 - '0' ;
if ( F_2 () ) {
unsigned char V_53 ;
V_53 = F_9 ( V_38 ) ;
if ( V_51 ) {
V_53 |= V_39 ;
} else {
V_53 &= ~ V_39 ;
}
F_8 ( V_53 , V_38 ) ;
}
return V_48 ;
}
static void T_5 F_17 ( struct V_6 * V_7 )
{
unsigned int V_21 , V_22 , V_54 ;
unsigned long V_55 = V_56 ;
void * V_57 = ( void * ) V_56 ;
V_7 -> V_12 . V_29 = 640 ;
V_7 -> V_12 . V_30 = 240 ;
V_7 -> V_12 . V_13 = 4 ;
V_7 -> V_12 . V_58 = V_59 ;
V_7 -> V_12 . V_60 = - 1 ;
V_7 -> V_12 . V_61 = - 1 ;
V_7 -> V_12 . V_23 = 93006 ;
V_22 = F_3 ( V_34 ) ;
if ( V_22 & V_35 ) {
V_21 = F_3 ( V_36 ) ;
switch ( V_21 & ( V_32 | V_33 ) ) {
case V_32 | V_33 :
V_7 -> V_12 . V_13 = 4 ;
break;
case V_33 :
V_7 -> V_12 . V_13 = 2 ;
break;
default:
V_7 -> V_12 . V_13 = 1 ;
break;
}
V_7 -> V_12 . V_29 = ( ( ( V_21 >> 13 ) & 0x3f ) + 1 ) * 16 ;
V_7 -> V_12 . V_30 = ( ( ( V_21 & 0x1fff ) + 1 ) * 128 ) /
( V_7 -> V_12 . V_29 *
V_7 -> V_12 . V_13 ) ;
V_7 -> V_12 . V_23 = ( ( ( V_21 >> 19 ) & 0x3f ) + 1 ) * 244140 / 9 ;
V_31 = ( V_21 >> 25 ) & 0x1f ;
}
V_7 -> V_12 . V_62 = V_7 -> V_12 . V_29 ;
V_7 -> V_12 . V_63 = V_7 -> V_12 . V_30 ;
V_7 -> V_12 . V_64 = V_7 -> V_12 . V_13 > 1 ;
V_54 = V_7 -> V_12 . V_62 * V_7 -> V_12 . V_63 * V_7 -> V_12 . V_13 / 8 ;
if ( V_54 <= 38400 ) {
F_18 ( V_65 L_2 ) ;
}
if ( ( V_22 & V_35 ) == 0 ) {
memset ( V_57 , 0 , V_54 ) ;
}
V_7 -> V_66 = V_57 ;
V_7 -> V_24 . V_67 = V_55 ;
V_7 -> V_24 . V_68 = F_19 ( V_54 ) ;
V_7 -> V_24 . type = V_69 ;
}
int T_5 F_20 ( void )
{
int V_70 = - V_71 ;
if ( F_21 ( L_3 , NULL ) )
return - V_72 ;
V_73 = F_22 ( sizeof( * V_73 ) , V_74 ) ;
if ( ! V_73 )
goto V_75;
strcpy ( V_73 -> V_24 . V_76 , L_4 ) ;
V_73 -> V_77 = & V_78 ;
V_73 -> V_79 = V_80 ;
F_17 ( V_73 ) ;
F_23 ( & V_73 -> V_81 , V_82 , 0 ) ;
if ( ! F_24 ( L_5 , 0444 , NULL , & V_83 ) ) {
F_18 ( L_6 ) ;
return - V_20 ;
}
if ( F_25 () ) {
V_84 = V_85 ;
V_86 |= ( V_87 | V_88 | V_89 | V_90 ) ;
}
if ( F_2 () ) {
F_8 ( F_9 ( V_38 ) | V_41 , V_38 ) ;
F_10 ( 100 ) ;
F_8 ( F_9 ( V_38 ) | V_40 , V_38 ) ;
F_8 ( F_9 ( V_38 ) | V_39 , V_38 ) ;
}
V_70 = F_26 ( V_73 ) ;
V_75: return V_70 ;
}
static void T_6 F_27 ( void )
{
F_28 ( V_73 ) ;
F_29 ( V_73 ) ;
if ( F_25 () ) {
V_84 = 0 ;
V_86 &= ~ ( V_87 | V_88 | V_89 | V_90 ) ;
}
}
