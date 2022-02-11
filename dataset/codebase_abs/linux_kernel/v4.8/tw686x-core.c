static const char * F_1 ( unsigned int V_1 )
{
switch ( V_1 ) {
case V_2 :
return L_1 ;
case V_3 :
return L_2 ;
case V_4 :
return L_3 ;
default:
return L_4 ;
}
}
static int F_2 ( char * V_5 , struct V_6 * V_7 )
{
return sprintf ( V_5 , F_1 ( V_8 ) ) ;
}
static int F_3 ( const char * V_9 , struct V_6 * V_7 )
{
if ( ! strcasecmp ( V_9 , F_1 ( V_2 ) ) )
V_8 = V_2 ;
else if ( ! strcasecmp ( V_9 , F_1 ( V_3 ) ) )
V_8 = V_3 ;
else if ( ! strcasecmp ( V_9 , F_1 ( V_4 ) ) )
V_8 = V_4 ;
else
return - V_10 ;
return 0 ;
}
void F_4 ( struct V_11 * V_12 , unsigned int V_13 )
{
T_1 V_14 = F_5 ( V_12 , V_15 ) ;
T_1 V_16 = F_5 ( V_12 , V_17 ) ;
V_14 &= ~ F_6 ( V_13 ) ;
V_16 &= ~ F_6 ( V_13 ) ;
V_12 -> V_18 &= ~ F_6 ( V_13 ) ;
V_12 -> V_19 &= ~ F_6 ( V_13 ) ;
if ( ! V_14 )
V_16 = 0 ;
F_7 ( V_12 , V_15 , V_14 ) ;
F_7 ( V_12 , V_17 , V_16 ) ;
}
void F_8 ( struct V_11 * V_12 , unsigned int V_13 )
{
T_1 V_14 = F_5 ( V_12 , V_15 ) ;
T_1 V_16 = F_5 ( V_12 , V_17 ) ;
V_12 -> V_18 |= V_14 | F_6 ( V_13 ) ;
V_12 -> V_19 |= V_16 | V_20 | F_6 ( V_13 ) ;
}
static void F_9 ( unsigned long V_21 )
{
struct V_11 * V_12 = (struct V_11 * ) V_21 ;
unsigned long V_22 ;
F_10 ( & V_12 -> V_23 , V_22 ) ;
F_7 ( V_12 , V_15 , V_12 -> V_18 ) ;
F_7 ( V_12 , V_17 , V_12 -> V_19 ) ;
V_12 -> V_18 = 0 ;
V_12 -> V_19 = 0 ;
F_11 ( & V_12 -> V_23 , V_22 ) ;
}
static void F_12 ( struct V_11 * V_12 , unsigned int V_24 )
{
T_1 V_14 , V_16 ;
V_14 = F_5 ( V_12 , V_15 ) ;
V_16 = F_5 ( V_12 , V_17 ) ;
V_12 -> V_18 |= V_14 ;
V_12 -> V_19 |= V_16 ;
F_7 ( V_12 , V_15 , V_14 & ~ V_24 ) ;
if ( ( V_14 & ~ V_24 ) == 0 ) {
F_13 ( & V_12 -> V_25 -> V_12 , L_5 ) ;
V_16 &= ~ V_20 ;
}
F_7 ( V_12 , V_17 , V_16 & ~ V_24 ) ;
}
static T_2 F_14 ( int V_26 , void * V_27 )
{
struct V_11 * V_12 = (struct V_11 * ) V_27 ;
unsigned int V_28 , V_29 , V_30 ;
T_1 V_31 , V_32 , V_33 , V_34 , V_35 ;
T_1 V_36 , V_14 , V_37 , V_38 ;
unsigned long V_22 ;
V_36 = F_5 ( V_12 , V_39 ) ;
V_31 = F_5 ( V_12 , V_40 ) ;
if ( ! V_36 && ! F_15 ( V_31 ) )
return V_41 ;
if ( V_36 & V_42 ) {
F_13 ( & V_12 -> V_25 -> V_12 ,
L_6 ) ;
V_30 = ~ 0 ;
goto V_43;
}
F_10 ( & V_12 -> V_23 , V_22 ) ;
V_14 = F_5 ( V_12 , V_15 ) ;
F_11 ( & V_12 -> V_23 , V_22 ) ;
V_37 = V_14 & 0xff ;
V_32 = ~ ( V_31 & 0xff ) & V_37 ;
V_33 = V_31 >> 24 ;
V_34 = V_31 >> 16 ;
V_35 = V_32 & ( V_33 | V_34 ) ;
V_30 = 0 ;
V_38 = F_5 ( V_12 , V_44 ) ;
V_28 = ( V_36 & V_37 ) | V_35 ;
V_29 = ( V_36 & V_14 ) >> 8 ;
if ( V_28 )
F_16 ( V_12 , V_28 , V_38 ,
V_31 , & V_30 ) ;
if ( V_29 )
F_17 ( V_12 , V_29 , V_38 ) ;
V_43:
if ( V_30 ) {
F_10 ( & V_12 -> V_23 , V_22 ) ;
F_12 ( V_12 , V_30 ) ;
F_11 ( & V_12 -> V_23 , V_22 ) ;
F_18 ( & V_12 -> V_45 ,
V_46 + F_19 ( 100 ) ) ;
}
return V_47 ;
}
static void F_20 ( struct V_48 * V_49 )
{
struct V_11 * V_12 = F_21 ( V_49 , struct V_11 ,
V_49 ) ;
unsigned int V_50 ;
for ( V_50 = 0 ; V_50 < F_22 ( V_12 ) ; V_50 ++ )
F_23 ( & V_12 -> V_51 [ V_50 ] . V_52 ) ;
F_24 ( & V_12 -> V_49 ) ;
F_25 ( V_12 -> V_53 ) ;
F_25 ( V_12 -> V_51 ) ;
F_25 ( V_12 ) ;
}
static int F_26 ( struct V_25 * V_25 ,
const struct V_54 * V_55 )
{
struct V_11 * V_12 ;
int V_56 ;
V_12 = F_27 ( sizeof( * V_12 ) , V_57 ) ;
if ( ! V_12 )
return - V_58 ;
V_12 -> type = V_55 -> V_59 ;
V_12 -> V_8 = V_8 ;
sprintf ( V_12 -> V_60 , L_7 , V_25 -> V_61 ) ;
V_12 -> V_51 = F_28 ( F_22 ( V_12 ) ,
sizeof( * V_12 -> V_51 ) , V_57 ) ;
if ( ! V_12 -> V_51 ) {
V_56 = - V_58 ;
goto V_62;
}
V_12 -> V_53 = F_28 ( F_22 ( V_12 ) ,
sizeof( * V_12 -> V_53 ) , V_57 ) ;
if ( ! V_12 -> V_53 ) {
V_56 = - V_58 ;
goto V_63;
}
F_29 ( L_8 , V_12 -> V_60 ,
F_30 ( V_25 ) , V_25 -> V_26 ,
( unsigned long ) F_31 ( V_25 , 0 ) ,
F_1 ( V_8 ) ) ;
V_12 -> V_25 = V_25 ;
if ( F_32 ( V_25 ) ) {
V_56 = - V_64 ;
goto V_65;
}
F_33 ( V_25 ) ;
V_56 = F_34 ( V_25 , F_35 ( 32 ) ) ;
if ( V_56 ) {
F_36 ( & V_25 -> V_12 , L_9 ) ;
V_56 = - V_64 ;
goto V_66;
}
V_56 = F_37 ( V_25 , V_12 -> V_60 ) ;
if ( V_56 ) {
F_36 ( & V_25 -> V_12 , L_10 ) ;
goto V_66;
}
V_12 -> V_67 = F_38 ( V_25 , 0 ) ;
if ( ! V_12 -> V_67 ) {
F_36 ( & V_25 -> V_12 , L_11 ) ;
V_56 = - V_58 ;
goto V_68;
}
F_7 ( V_12 , V_69 , 0x0f ) ;
F_39 ( 1 ) ;
F_7 ( V_12 , V_70 [ 0 ] , 0x3f ) ;
if ( F_22 ( V_12 ) > 4 )
F_7 ( V_12 , V_70 [ 1 ] , 0x3f ) ;
F_7 ( V_12 , V_17 , 0 ) ;
F_7 ( V_12 , V_15 , 0 ) ;
F_7 ( V_12 , V_71 , 0xffffff04 ) ;
F_7 ( V_12 , V_72 , 0x140c8584 ) ;
F_7 ( V_12 , V_73 , V_74 ) ;
F_40 ( & V_12 -> V_23 ) ;
V_56 = F_41 ( V_25 -> V_26 , F_14 , V_75 ,
V_12 -> V_60 , V_12 ) ;
if ( V_56 < 0 ) {
F_36 ( & V_25 -> V_12 , L_12 ) ;
goto V_76;
}
F_42 ( & V_12 -> V_45 ,
F_9 , ( unsigned long ) V_12 ) ;
V_12 -> V_49 . V_77 = F_20 ;
V_56 = F_43 ( V_12 ) ;
if ( V_56 ) {
F_36 ( & V_25 -> V_12 , L_13 ) ;
goto V_78;
}
V_56 = F_44 ( V_12 ) ;
if ( V_56 )
F_45 ( & V_25 -> V_12 , L_14 ) ;
F_46 ( V_25 , V_12 ) ;
return 0 ;
V_78:
V_78 ( V_25 -> V_26 , V_12 ) ;
V_76:
F_47 ( V_25 , V_12 -> V_67 ) ;
V_68:
F_48 ( V_25 ) ;
V_66:
F_49 ( V_25 ) ;
V_65:
F_25 ( V_12 -> V_53 ) ;
V_63:
F_25 ( V_12 -> V_51 ) ;
V_62:
F_25 ( V_12 ) ;
return V_56 ;
}
static void F_50 ( struct V_25 * V_25 )
{
struct V_11 * V_12 = F_51 ( V_25 ) ;
unsigned long V_22 ;
V_78 ( V_25 -> V_26 , V_12 ) ;
F_52 ( V_12 ) ;
F_53 ( V_12 ) ;
F_54 ( & V_12 -> V_45 ) ;
F_47 ( V_25 , V_12 -> V_67 ) ;
F_48 ( V_25 ) ;
F_49 ( V_25 ) ;
F_10 ( & V_12 -> V_23 , V_22 ) ;
V_12 -> V_25 = NULL ;
F_11 ( & V_12 -> V_23 , V_22 ) ;
F_55 ( & V_12 -> V_49 ) ;
}
