static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_3 ( V_5 ) ;
unsigned long V_7 = V_8 ;
int V_9 , V_10 ;
F_4 ( & V_6 -> V_11 ) ;
if ( F_5 ( V_7 , V_6 -> V_12 +
V_13 )
&& V_6 -> V_14 )
goto V_15;
for ( V_9 = 0 ; V_9 < V_16 ; V_9 ++ ) {
V_10 = F_6 ( V_5 , V_17 [ V_9 ] ) ;
V_6 -> V_18 [ V_17 [ V_9 ] ] = V_10 >> 8 ;
}
V_6 -> V_12 = V_7 ;
V_6 -> V_14 = 1 ;
V_15:
F_7 ( & V_6 -> V_11 ) ;
return V_6 ;
}
static T_1 F_8 ( struct V_2 * V_3 ,
struct V_19 * V_20 ,
char * V_21 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( V_6 -> V_18 [ V_22 ] & V_23 )
return sprintf ( V_21 , L_1 ) ;
return sprintf ( V_21 , L_2 ) ;
}
static int F_9 ( struct V_1 * V_6 )
{
int V_24 , V_25 , V_26 ;
V_24 = V_6 -> V_18 [ V_27 ] & V_28 ;
V_25 = V_6 -> V_18 [ V_29 ] ;
V_25 |= ( ( int ) V_6 -> V_18 [ V_27 ] & 0x80 ) << 1 ;
V_25 |= ( ( int ) V_6 -> V_18 [ V_27 ] & 0x40 ) << 3 ;
V_26 = V_30 * ( V_25 + 8 ) / ( V_24 + 2 ) ;
V_26 /= V_31 [ V_6 -> V_18 [ V_32 ] >>
V_33 ] ;
return V_26 ;
}
static T_1 F_10 ( struct V_2 * V_3 ,
struct V_19 * V_20 ,
char * V_21 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return sprintf ( V_21 , L_3 , F_9 ( V_6 ) ) ;
}
static T_1 F_11 ( struct V_2 * V_3 ,
struct V_19 * V_20 ,
char * V_21 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_26 ;
if ( V_6 -> V_18 [ V_34 ] & V_35 )
V_26 = F_9 ( V_6 ) ;
else {
int V_36 = V_6 -> V_18 [ V_37 ] & V_38 ;
V_26 = V_39 [ V_36 ] ;
if ( V_6 -> V_18 [ V_34 ] & V_40 ) {
switch ( V_26 ) {
case 166666 :
V_26 = 160000 ;
break;
case 333333 :
V_26 = 320000 ;
break;
}
}
}
return sprintf ( V_21 , L_3 , V_26 ) ;
}
static int F_12 ( struct V_1 * V_6 )
{
int V_24 , V_25 , V_26 ;
V_24 = V_6 -> V_18 [ V_41 ] & V_28 ;
V_25 = V_6 -> V_18 [ V_42 ] ;
V_25 |= ( ( int ) V_6 -> V_18 [ V_41 ] & 0x80 ) << 1 ;
V_25 |= ( ( int ) V_6 -> V_18 [ V_41 ] & 0x40 ) << 3 ;
V_26 = V_30 * ( V_25 + 8 ) / ( V_24 + 2 ) ;
V_26 /= V_31 [ V_6 -> V_18 [ V_43 ] &
V_44 ] ;
return V_26 ;
}
static T_1 F_13 ( struct V_2 * V_3 ,
struct V_19 * V_20 ,
char * V_21 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return sprintf ( V_21 , L_3 , F_12 ( V_6 ) ) ;
}
static T_1 F_14 ( struct V_2 * V_3 ,
struct V_19 * V_20 ,
char * V_21 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_26 ;
if ( V_6 -> V_18 [ V_34 ] & V_35 )
V_26 = F_12 ( V_6 ) ;
else
if ( V_6 -> V_18 [ V_34 ] & V_40 &&
V_6 -> V_18 [ V_34 ] & V_45 )
V_26 = 96000 ;
else
V_26 = 100000 ;
return sprintf ( V_21 , L_3 , V_26 ) ;
}
static int F_15 ( struct V_1 * V_6 )
{
int V_24 , V_25 , V_26 ;
V_24 = V_6 -> V_18 [ V_41 ] & V_28 ;
V_25 = V_6 -> V_18 [ V_42 ] ;
V_25 |= ( ( int ) V_6 -> V_18 [ V_41 ] & 0x80 ) << 1 ;
V_25 |= ( ( int ) V_6 -> V_18 [ V_41 ] & 0x40 ) << 3 ;
V_26 = V_30 * ( V_25 + 8 ) / ( V_24 + 2 ) ;
V_26 /= V_31 [ V_6 -> V_18 [ V_43 ] >>
V_46 ] ;
return V_26 ;
}
static T_1 F_16 ( struct V_2 * V_3 ,
struct V_19 * V_20 ,
char * V_21 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return sprintf ( V_21 , L_3 , F_15 ( V_6 ) ) ;
}
static T_1 F_17 ( struct V_2 * V_3 ,
struct V_19 * V_20 ,
char * V_21 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_26 ;
if ( V_6 -> V_18 [ V_34 ] & V_35 )
V_26 = F_15 ( V_6 ) ;
else
V_26 = 33333 ;
return sprintf ( V_21 , L_3 , V_26 ) ;
}
static T_1 F_18 ( struct V_2 * V_3 ,
struct V_19 * V_20 ,
char * V_21 )
{
int V_47 ;
if ( V_20 == & V_48 )
V_47 = 48000 ;
else if ( V_20 == & V_49 )
V_47 = V_30 ;
else
F_19 () ;
return sprintf ( V_21 , L_3 , V_47 ) ;
}
static T_1 F_20 ( struct V_2 * V_3 ,
struct V_19 * V_20 ,
char * V_21 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_50 ;
unsigned long V_51 ;
if ( ! ( V_6 -> V_18 [ V_22 ] & V_23 ) )
return sprintf ( V_21 , L_4 ) ;
if ( V_20 == & V_52 )
V_50 = V_53 ;
else if ( V_20 == & V_54 )
V_50 = V_55 ;
else
F_19 () ;
V_51 = V_6 -> V_18 [ V_50 ] | ( V_6 -> V_18 [ V_50 + 1 ] << 8 ) ;
V_51 &= V_56 ;
V_51 = 500000 * V_51 / 16384 ;
return sprintf ( V_21 , L_5 , V_51 ) ;
}
static int F_21 ( struct V_4 * V_5 ,
struct V_57 * V_58 )
{
struct V_59 * V_60 = V_5 -> V_60 ;
int V_61 , V_2 , V_62 ;
if ( ! F_22 ( V_60 , V_63 ) )
return - V_64 ;
V_61 = F_6 ( V_5 , V_65 ) ;
V_61 >>= 8 ;
V_62 = V_61 >> V_66 ;
V_61 &= V_67 ;
if ( V_61 != V_68 )
return - V_64 ;
V_2 = F_6 ( V_5 , V_69 ) ;
V_2 >>= 8 ;
if ( V_2 != V_70 )
return - V_64 ;
if ( V_62 != V_71 )
F_23 ( & V_60 -> V_3 , L_6 , V_62 ) ;
F_24 ( V_58 -> type , L_7 , V_72 ) ;
return 0 ;
}
static int F_25 ( struct V_4 * V_5 ,
const struct V_73 * V_74 )
{
struct V_1 * V_6 ;
int V_75 ;
V_6 = F_26 ( sizeof( struct V_1 ) , V_76 ) ;
if ( ! V_6 ) {
V_75 = - V_77 ;
goto exit;
}
F_27 ( V_5 , V_6 ) ;
F_28 ( & V_6 -> V_11 ) ;
F_23 ( & V_5 -> V_3 , L_8 , V_5 -> V_78 ) ;
V_6 -> V_79 . V_79 = V_80 ;
V_75 = F_29 ( & V_5 -> V_3 . V_81 , & V_6 -> V_79 ) ;
if ( V_75 )
goto V_82;
return 0 ;
V_82:
F_30 ( V_6 ) ;
exit:
return V_75 ;
}
static int F_31 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
F_32 ( & V_5 -> V_3 . V_81 , & V_6 -> V_79 ) ;
F_30 ( V_6 ) ;
return 0 ;
}
