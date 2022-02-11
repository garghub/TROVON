static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_4 , T_1 V_5 )
{
return F_4 ( V_4 -> V_6 , & V_5 , 3 ) ;
}
static int F_5 ( struct V_1 * V_4 , int V_7 , int V_8 ,
int V_9 )
{
int V_10 ;
T_1 V_11 ;
F_6 ( & V_4 -> V_6 -> V_12 , L_1 , V_13 ,
V_7 , V_8 , V_9 ) ;
V_11 = 1 << 0 ;
V_11 |= ( 59 - V_9 ) << 4 ;
V_11 |= 0 << 10 ;
V_11 |= ( 1 - V_8 ) << 12 ;
V_11 |= ( 1 - V_7 ) << 13 ;
V_11 |= 4 << 14 ;
V_11 |= 0 << 17 ;
V_10 = F_3 ( V_4 , V_11 ) ;
if ( V_10 )
goto V_14;
return 0 ;
V_14:
F_6 ( & V_4 -> V_6 -> V_12 , L_2 , V_13 , V_10 ) ;
return V_10 ;
}
static int F_7 ( struct V_1 * V_4 )
{
int V_10 , V_15 ;
unsigned int V_16 , V_17 , V_18 , V_19 , V_20 , V_21 , V_22 ;
T_1 V_11 ;
T_2 V_23 , V_24 ;
T_3 V_25 , V_26 , V_27 ;
static const struct {
T_1 V_28 ;
T_3 V_25 ;
T_3 V_27 ;
} V_29 [] = {
{ 50000000 , 0xe1 , 16 } ,
{ 108000000 , 0x42 , 32 } ,
{ 330000000 , 0x44 , 16 } ,
{ 960000000 , 0x48 , 4 } ,
{ ~ 0U , 0x50 , 2 } ,
} ;
static const struct {
T_1 V_30 ;
T_3 V_26 ;
} V_31 [] = {
{ 0 , 0x03 } ,
{ 450000 , 0x02 } ,
{ 1620000 , 0x01 } ,
{ 2048000 , 0x00 } ,
} ;
static const struct {
T_1 V_30 ;
T_3 V_32 ;
} V_33 [] = {
{ 200000 , 0x00 } ,
{ 300000 , 0x01 } ,
{ 600000 , 0x02 } ,
{ 1536000 , 0x03 } ,
{ 5000000 , 0x04 } ,
{ 6000000 , 0x05 } ,
{ 7000000 , 0x06 } ,
{ 8000000 , 0x07 } ,
} ;
unsigned int V_34 = V_4 -> V_35 ;
unsigned int V_36 ;
unsigned int V_37 = 0 ;
#define F_8 24000000
#define F_9 4
#define F_10 1
F_6 ( & V_4 -> V_6 -> V_12 ,
L_3 ,
V_13 , V_34 , V_37 ) ;
for ( V_15 = 0 ; V_15 < F_11 ( V_29 ) ; V_15 ++ ) {
if ( V_34 <= V_29 [ V_15 ] . V_28 ) {
V_25 = V_29 [ V_15 ] . V_25 ;
V_27 = V_29 [ V_15 ] . V_27 ;
break;
}
}
if ( V_15 == F_11 ( V_29 ) ) {
V_10 = - V_38 ;
goto V_14;
}
if ( ( V_25 >> 0 ) & 0x1 )
V_22 = 5 * F_8 ;
else
V_22 = 0 ;
for ( V_15 = 0 ; V_15 < F_11 ( V_31 ) ; V_15 ++ ) {
if ( V_37 == V_31 [ V_15 ] . V_30 ) {
V_26 = V_31 [ V_15 ] . V_26 ;
break;
}
}
if ( V_15 == F_11 ( V_31 ) ) {
V_10 = - V_38 ;
goto V_14;
}
V_36 = V_4 -> V_36 -> V_32 ;
V_36 = F_12 ( V_36 , 200000U , 8000000U ) ;
for ( V_15 = 0 ; V_15 < F_11 ( V_33 ) ; V_15 ++ ) {
if ( V_36 <= V_33 [ V_15 ] . V_30 ) {
V_36 = V_33 [ V_15 ] . V_32 ;
break;
}
}
if ( V_15 == F_11 ( V_33 ) ) {
V_10 = - V_38 ;
goto V_14;
}
V_4 -> V_36 -> V_32 = V_33 [ V_15 ] . V_30 ;
F_6 ( & V_4 -> V_6 -> V_12 , L_4 ,
V_13 , V_33 [ V_15 ] . V_30 ) ;
V_23 = ( T_2 ) ( V_34 + V_37 + V_22 ) * V_27 ;
V_24 = V_23 ;
V_17 = F_13 ( V_24 , F_8 * F_9 ) ;
V_16 = ( unsigned int ) V_24 ;
V_20 = F_10 * V_27 ;
V_18 = ( F_8 * F_9 ) / V_20 ;
V_19 = 1ul * V_18 * V_17 / ( F_8 * F_9 ) ;
V_21 = F_14 ( V_18 , V_19 ) ;
V_18 /= V_21 ;
V_19 /= V_21 ;
V_21 = F_15 ( V_18 , 4095 ) ;
V_18 = F_16 ( V_18 , V_21 ) ;
V_19 = F_16 ( V_19 , V_21 ) ;
V_21 = 1ul * F_8 * F_9 * V_16 ;
V_21 += 1ul * F_8 * F_9 * V_19 / V_18 ;
V_21 /= V_27 ;
F_6 ( & V_4 -> V_6 -> V_12 ,
L_5 ,
V_13 , V_34 , V_21 , V_16 , V_18 , V_19 ) ;
V_10 = F_3 ( V_4 , 0x00000e ) ;
if ( V_10 )
goto V_14;
V_10 = F_3 ( V_4 , 0x000003 ) ;
if ( V_10 )
goto V_14;
V_11 = 0 << 0 ;
V_11 |= V_25 << 4 ;
V_11 |= V_26 << 12 ;
V_11 |= V_36 << 14 ;
V_11 |= 0x02 << 17 ;
V_11 |= 0x00 << 20 ;
V_10 = F_3 ( V_4 , V_11 ) ;
if ( V_10 )
goto V_14;
V_11 = 5 << 0 ;
V_11 |= V_18 << 4 ;
V_11 |= 1 << 19 ;
V_11 |= 1 << 21 ;
V_10 = F_3 ( V_4 , V_11 ) ;
if ( V_10 )
goto V_14;
V_11 = 2 << 0 ;
V_11 |= V_19 << 4 ;
V_11 |= V_16 << 16 ;
V_10 = F_3 ( V_4 , V_11 ) ;
if ( V_10 )
goto V_14;
V_10 = F_5 ( V_4 , V_4 -> V_7 -> V_39 . V_32 , V_4 -> V_8 -> V_39 . V_32 ,
V_4 -> V_9 -> V_39 . V_32 ) ;
if ( V_10 )
goto V_14;
V_11 = 6 << 0 ;
V_11 |= 63 << 4 ;
V_11 |= 4095 << 10 ;
V_10 = F_3 ( V_4 , V_11 ) ;
if ( V_10 )
goto V_14;
return 0 ;
V_14:
F_6 ( & V_4 -> V_6 -> V_12 , L_2 , V_13 , V_10 ) ;
return V_10 ;
}
static int F_17 ( struct V_2 * V_3 , int V_40 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_10 ;
F_6 ( & V_4 -> V_6 -> V_12 , L_6 , V_13 , V_40 ) ;
if ( V_40 )
V_10 = 0 ;
else
V_10 = F_3 ( V_4 , 0x000000 ) ;
return V_10 ;
}
static int F_18 ( struct V_2 * V_3 , struct V_41 * V_42 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_6 ( & V_4 -> V_6 -> V_12 , L_7 , V_13 , V_42 -> V_43 ) ;
F_19 ( V_42 -> V_44 , L_8 , sizeof( V_42 -> V_44 ) ) ;
V_42 -> type = V_45 ;
V_42 -> V_46 = V_47 | V_48 ;
V_42 -> V_49 = 49000000 ;
V_42 -> V_50 = 960000000 ;
return 0 ;
}
static int F_20 ( struct V_2 * V_3 , const struct V_41 * V_42 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_6 ( & V_4 -> V_6 -> V_12 , L_7 , V_13 , V_42 -> V_43 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 , struct V_51 * V_52 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_6 ( & V_4 -> V_6 -> V_12 , L_9 , V_13 , V_52 -> V_53 ) ;
V_52 -> V_54 = V_4 -> V_35 ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 ,
const struct V_51 * V_52 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_55 ;
F_6 ( & V_4 -> V_6 -> V_12 , L_10 ,
V_13 , V_52 -> V_53 , V_52 -> type , V_52 -> V_54 ) ;
if ( V_52 -> V_54 < ( ( V_56 [ 0 ] . V_50 + V_56 [ 1 ] . V_49 ) / 2 ) )
V_55 = 0 ;
else
V_55 = 1 ;
V_4 -> V_35 = F_23 (unsigned int, f->frequency,
bands[band].rangelow, bands[band].rangehigh) ;
return F_7 ( V_4 ) ;
}
static int F_24 ( struct V_2 * V_3 ,
struct V_57 * V_55 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_6 ( & V_4 -> V_6 -> V_12 , L_11 ,
V_13 , V_55 -> V_53 , V_55 -> type , V_55 -> V_43 ) ;
if ( V_55 -> V_43 >= F_11 ( V_56 ) )
return - V_38 ;
V_55 -> V_46 = V_56 [ V_55 -> V_43 ] . V_46 ;
V_55 -> V_49 = V_56 [ V_55 -> V_43 ] . V_49 ;
V_55 -> V_50 = V_56 [ V_55 -> V_43 ] . V_50 ;
return 0 ;
}
static int F_25 ( struct V_58 * V_59 )
{
struct V_1 * V_4 = F_2 ( V_59 -> V_60 , struct V_1 , V_61 ) ;
int V_10 ;
F_6 ( & V_4 -> V_6 -> V_12 ,
L_12 ,
V_13 , V_59 -> V_62 , V_59 -> V_44 , V_59 -> V_32 ,
V_59 -> V_63 , V_59 -> V_64 , V_59 -> V_65 ) ;
switch ( V_59 -> V_62 ) {
case V_66 :
case V_67 :
V_10 = F_7 ( V_4 ) ;
break;
case V_68 :
V_10 = F_5 ( V_4 , V_4 -> V_7 -> V_32 ,
V_4 -> V_8 -> V_39 . V_32 , V_4 -> V_9 -> V_39 . V_32 ) ;
break;
case V_69 :
V_10 = F_5 ( V_4 , V_4 -> V_7 -> V_39 . V_32 ,
V_4 -> V_8 -> V_32 , V_4 -> V_9 -> V_39 . V_32 ) ;
break;
case V_70 :
V_10 = F_5 ( V_4 , V_4 -> V_7 -> V_39 . V_32 ,
V_4 -> V_8 -> V_39 . V_32 , V_4 -> V_9 -> V_32 ) ;
break;
default:
F_6 ( & V_4 -> V_6 -> V_12 , L_13 ,
V_13 , V_59 -> V_62 ) ;
V_10 = - V_38 ;
}
return V_10 ;
}
static int F_26 ( struct V_71 * V_6 )
{
struct V_1 * V_4 ;
int V_10 ;
F_6 ( & V_6 -> V_12 , L_14 , V_13 ) ;
V_4 = F_27 ( sizeof( struct V_1 ) , V_72 ) ;
if ( V_4 == NULL ) {
V_10 = - V_73 ;
F_6 ( & V_6 -> V_12 , L_15 ) ;
goto V_74;
}
V_4 -> V_6 = V_6 ;
V_4 -> V_35 = V_56 [ 0 ] . V_49 ;
F_28 ( & V_4 -> V_3 , V_6 , & V_75 ) ;
F_29 ( & V_4 -> V_61 , 5 ) ;
V_4 -> V_76 = F_30 ( & V_4 -> V_61 , & V_77 ,
V_66 , 0 , 1 , 1 , 1 ) ;
V_4 -> V_36 = F_30 ( & V_4 -> V_61 , & V_77 ,
V_67 , 200000 , 8000000 , 1 , 200000 ) ;
F_31 ( 2 , & V_4 -> V_76 , 0 , false ) ;
V_4 -> V_7 = F_30 ( & V_4 -> V_61 , & V_77 ,
V_68 , 0 , 1 , 1 , 1 ) ;
V_4 -> V_8 = F_30 ( & V_4 -> V_61 , & V_77 ,
V_69 , 0 , 1 , 1 , 1 ) ;
V_4 -> V_9 = F_30 ( & V_4 -> V_61 , & V_77 ,
V_70 , 0 , 59 , 1 , 0 ) ;
if ( V_4 -> V_61 . error ) {
V_10 = V_4 -> V_61 . error ;
F_32 ( & V_4 -> V_6 -> V_12 , L_16 ) ;
goto V_78;
}
V_4 -> V_3 . V_79 = & V_4 -> V_61 ;
return 0 ;
V_78:
F_33 ( & V_4 -> V_61 ) ;
V_74:
F_34 ( V_4 ) ;
return V_10 ;
}
static int F_35 ( struct V_71 * V_6 )
{
struct V_2 * V_3 = F_36 ( V_6 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_6 ( & V_6 -> V_12 , L_14 , V_13 ) ;
F_37 ( & V_4 -> V_3 ) ;
F_33 ( & V_4 -> V_61 ) ;
F_34 ( V_4 ) ;
return 0 ;
}
