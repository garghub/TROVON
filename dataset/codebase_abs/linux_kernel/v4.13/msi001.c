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
struct V_10 * V_6 = V_4 -> V_6 ;
int V_11 ;
T_1 V_12 ;
F_6 ( & V_6 -> V_4 , L_1 ,
V_7 , V_8 , V_9 ) ;
V_12 = 1 << 0 ;
V_12 |= ( 59 - V_9 ) << 4 ;
V_12 |= 0 << 10 ;
V_12 |= ( 1 - V_8 ) << 12 ;
V_12 |= ( 1 - V_7 ) << 13 ;
V_12 |= 4 << 14 ;
V_12 |= 0 << 17 ;
V_11 = F_3 ( V_4 , V_12 ) ;
if ( V_11 )
goto V_13;
return 0 ;
V_13:
F_6 ( & V_6 -> V_4 , L_2 , V_11 ) ;
return V_11 ;
}
static int F_7 ( struct V_1 * V_4 )
{
struct V_10 * V_6 = V_4 -> V_6 ;
int V_11 , V_14 ;
unsigned int V_15 , V_16 , V_17 , V_18 , V_19 , V_20 , V_21 ;
T_1 V_12 ;
T_2 V_22 ;
T_3 V_23 , V_24 ;
static const struct {
T_1 V_25 ;
T_3 V_23 ;
T_3 V_20 ;
} V_26 [] = {
{ 50000000 , 0xe1 , 16 } ,
{ 108000000 , 0x42 , 32 } ,
{ 330000000 , 0x44 , 16 } ,
{ 960000000 , 0x48 , 4 } ,
{ ~ 0U , 0x50 , 2 } ,
} ;
static const struct {
T_1 V_27 ;
T_3 V_24 ;
} V_28 [] = {
{ 0 , 0x03 } ,
{ 450000 , 0x02 } ,
{ 1620000 , 0x01 } ,
{ 2048000 , 0x00 } ,
} ;
static const struct {
T_1 V_27 ;
T_3 V_29 ;
} V_30 [] = {
{ 200000 , 0x00 } ,
{ 300000 , 0x01 } ,
{ 600000 , 0x02 } ,
{ 1536000 , 0x03 } ,
{ 5000000 , 0x04 } ,
{ 6000000 , 0x05 } ,
{ 7000000 , 0x06 } ,
{ 8000000 , 0x07 } ,
} ;
unsigned int V_31 = V_4 -> V_32 ;
unsigned int V_33 ;
unsigned int V_34 = 0 ;
#define F_8 24000000
#define F_9 4
#define F_10 div_lo
F_6 ( & V_6 -> V_4 , L_3 , V_31 , V_34 ) ;
for ( V_14 = 0 ; V_14 < F_11 ( V_26 ) ; V_14 ++ ) {
if ( V_31 <= V_26 [ V_14 ] . V_25 ) {
V_23 = V_26 [ V_14 ] . V_23 ;
V_20 = V_26 [ V_14 ] . V_20 ;
break;
}
}
if ( V_14 == F_11 ( V_26 ) ) {
V_11 = - V_35 ;
goto V_13;
}
if ( ( V_23 >> 0 ) & 0x1 )
V_21 = 5 * F_8 ;
else
V_21 = 0 ;
for ( V_14 = 0 ; V_14 < F_11 ( V_28 ) ; V_14 ++ ) {
if ( V_34 == V_28 [ V_14 ] . V_27 ) {
V_24 = V_28 [ V_14 ] . V_24 ;
break;
}
}
if ( V_14 == F_11 ( V_28 ) ) {
V_11 = - V_35 ;
goto V_13;
}
V_33 = V_4 -> V_33 -> V_29 ;
V_33 = F_12 ( V_33 , 200000U , 8000000U ) ;
for ( V_14 = 0 ; V_14 < F_11 ( V_30 ) ; V_14 ++ ) {
if ( V_33 <= V_30 [ V_14 ] . V_27 ) {
V_33 = V_30 [ V_14 ] . V_29 ;
break;
}
}
if ( V_14 == F_11 ( V_30 ) ) {
V_11 = - V_35 ;
goto V_13;
}
V_4 -> V_33 -> V_29 = V_30 [ V_14 ] . V_27 ;
F_6 ( & V_6 -> V_4 , L_4 , V_30 [ V_14 ] . V_27 ) ;
V_22 = ( T_2 ) ( V_31 + V_34 + V_21 ) * V_20 ;
V_16 = F_13 ( V_22 , F_9 * F_8 , & V_17 ) ;
V_18 = ( F_9 * F_8 ) / F_10 ;
V_19 = F_14 ( ( T_2 ) V_17 * V_18 , ( F_9 * F_8 ) ) ;
V_15 = F_15 ( V_18 , V_19 ) ;
V_18 /= V_15 ;
V_19 /= V_15 ;
V_15 = F_16 ( V_18 , 4095 ) ;
V_18 = F_17 ( V_18 , V_15 ) ;
V_19 = F_17 ( V_19 , V_15 ) ;
V_15 = ( unsigned int ) F_8 * F_9 * V_16 ;
V_15 += ( unsigned int ) F_8 * F_9 * V_19 / V_18 ;
V_15 /= V_20 ;
F_6 ( & V_6 -> V_4 ,
L_5 ,
V_31 , V_15 , V_22 , V_16 , V_18 , V_19 , V_20 ) ;
V_11 = F_3 ( V_4 , 0x00000e ) ;
if ( V_11 )
goto V_13;
V_11 = F_3 ( V_4 , 0x000003 ) ;
if ( V_11 )
goto V_13;
V_12 = 0 << 0 ;
V_12 |= V_23 << 4 ;
V_12 |= V_24 << 12 ;
V_12 |= V_33 << 14 ;
V_12 |= 0x02 << 17 ;
V_12 |= 0x00 << 20 ;
V_11 = F_3 ( V_4 , V_12 ) ;
if ( V_11 )
goto V_13;
V_12 = 5 << 0 ;
V_12 |= V_18 << 4 ;
V_12 |= 1 << 19 ;
V_12 |= 1 << 21 ;
V_11 = F_3 ( V_4 , V_12 ) ;
if ( V_11 )
goto V_13;
V_12 = 2 << 0 ;
V_12 |= V_19 << 4 ;
V_12 |= V_16 << 16 ;
V_11 = F_3 ( V_4 , V_12 ) ;
if ( V_11 )
goto V_13;
V_11 = F_5 ( V_4 , V_4 -> V_7 -> V_36 . V_29 ,
V_4 -> V_8 -> V_36 . V_29 , V_4 -> V_9 -> V_36 . V_29 ) ;
if ( V_11 )
goto V_13;
V_12 = 6 << 0 ;
V_12 |= 63 << 4 ;
V_12 |= 4095 << 10 ;
V_11 = F_3 ( V_4 , V_12 ) ;
if ( V_11 )
goto V_13;
return 0 ;
V_13:
F_6 ( & V_6 -> V_4 , L_2 , V_11 ) ;
return V_11 ;
}
static int F_18 ( struct V_2 * V_3 , int V_37 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_10 * V_6 = V_4 -> V_6 ;
int V_11 ;
F_6 ( & V_6 -> V_4 , L_6 , V_37 ) ;
if ( V_37 )
V_11 = 0 ;
else
V_11 = F_3 ( V_4 , 0x000000 ) ;
return V_11 ;
}
static int F_19 ( struct V_2 * V_3 , struct V_38 * V_39 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_10 * V_6 = V_4 -> V_6 ;
F_6 ( & V_6 -> V_4 , L_7 , V_39 -> V_40 ) ;
F_20 ( V_39 -> V_41 , L_8 , sizeof( V_39 -> V_41 ) ) ;
V_39 -> type = V_42 ;
V_39 -> V_43 = V_44 | V_45 ;
V_39 -> V_46 = 49000000 ;
V_39 -> V_47 = 960000000 ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 , const struct V_38 * V_39 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_10 * V_6 = V_4 -> V_6 ;
F_6 ( & V_6 -> V_4 , L_7 , V_39 -> V_40 ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 , struct V_48 * V_49 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_10 * V_6 = V_4 -> V_6 ;
F_6 ( & V_6 -> V_4 , L_9 , V_49 -> V_50 ) ;
V_49 -> V_51 = V_4 -> V_32 ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 ,
const struct V_48 * V_49 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_10 * V_6 = V_4 -> V_6 ;
unsigned int V_52 ;
F_6 ( & V_6 -> V_4 , L_10 ,
V_49 -> V_50 , V_49 -> type , V_49 -> V_51 ) ;
if ( V_49 -> V_51 < ( ( V_53 [ 0 ] . V_47 + V_53 [ 1 ] . V_46 ) / 2 ) )
V_52 = 0 ;
else
V_52 = 1 ;
V_4 -> V_32 = F_24 (unsigned int, f->frequency,
bands[band].rangelow, bands[band].rangehigh) ;
return F_7 ( V_4 ) ;
}
static int F_25 ( struct V_2 * V_3 ,
struct V_54 * V_52 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_10 * V_6 = V_4 -> V_6 ;
F_6 ( & V_6 -> V_4 , L_11 ,
V_52 -> V_50 , V_52 -> type , V_52 -> V_40 ) ;
if ( V_52 -> V_40 >= F_11 ( V_53 ) )
return - V_35 ;
V_52 -> V_43 = V_53 [ V_52 -> V_40 ] . V_43 ;
V_52 -> V_46 = V_53 [ V_52 -> V_40 ] . V_46 ;
V_52 -> V_47 = V_53 [ V_52 -> V_40 ] . V_47 ;
return 0 ;
}
static int F_26 ( struct V_55 * V_56 )
{
struct V_1 * V_4 = F_2 ( V_56 -> V_57 , struct V_1 , V_58 ) ;
struct V_10 * V_6 = V_4 -> V_6 ;
int V_11 ;
F_6 ( & V_6 -> V_4 , L_12 ,
V_56 -> V_59 , V_56 -> V_41 , V_56 -> V_29 , V_56 -> V_60 , V_56 -> V_61 ,
V_56 -> V_62 ) ;
switch ( V_56 -> V_59 ) {
case V_63 :
case V_64 :
V_11 = F_7 ( V_4 ) ;
break;
case V_65 :
V_11 = F_5 ( V_4 , V_4 -> V_7 -> V_29 ,
V_4 -> V_8 -> V_36 . V_29 ,
V_4 -> V_9 -> V_36 . V_29 ) ;
break;
case V_66 :
V_11 = F_5 ( V_4 , V_4 -> V_7 -> V_36 . V_29 ,
V_4 -> V_8 -> V_29 ,
V_4 -> V_9 -> V_36 . V_29 ) ;
break;
case V_67 :
V_11 = F_5 ( V_4 , V_4 -> V_7 -> V_36 . V_29 ,
V_4 -> V_8 -> V_36 . V_29 ,
V_4 -> V_9 -> V_29 ) ;
break;
default:
F_6 ( & V_6 -> V_4 , L_13 , V_56 -> V_59 ) ;
V_11 = - V_35 ;
}
return V_11 ;
}
static int F_27 ( struct V_10 * V_6 )
{
struct V_1 * V_4 ;
int V_11 ;
F_6 ( & V_6 -> V_4 , L_14 ) ;
V_4 = F_28 ( sizeof( * V_4 ) , V_68 ) ;
if ( ! V_4 ) {
V_11 = - V_69 ;
goto V_13;
}
V_4 -> V_6 = V_6 ;
V_4 -> V_32 = V_53 [ 0 ] . V_46 ;
F_29 ( & V_4 -> V_3 , V_6 , & V_70 ) ;
F_30 ( & V_4 -> V_58 , 5 ) ;
V_4 -> V_71 = F_31 ( & V_4 -> V_58 , & V_72 ,
V_63 , 0 , 1 , 1 , 1 ) ;
V_4 -> V_33 = F_31 ( & V_4 -> V_58 , & V_72 ,
V_64 , 200000 , 8000000 , 1 , 200000 ) ;
F_32 ( 2 , & V_4 -> V_71 , 0 , false ) ;
V_4 -> V_7 = F_31 ( & V_4 -> V_58 , & V_72 ,
V_65 , 0 , 1 , 1 , 1 ) ;
V_4 -> V_8 = F_31 ( & V_4 -> V_58 , & V_72 ,
V_66 , 0 , 1 , 1 , 1 ) ;
V_4 -> V_9 = F_31 ( & V_4 -> V_58 , & V_72 ,
V_67 , 0 , 59 , 1 , 0 ) ;
if ( V_4 -> V_58 . error ) {
V_11 = V_4 -> V_58 . error ;
F_33 ( & V_6 -> V_4 , L_15 ) ;
goto V_73;
}
V_4 -> V_3 . V_74 = & V_4 -> V_58 ;
return 0 ;
V_73:
F_34 ( & V_4 -> V_58 ) ;
F_35 ( V_4 ) ;
V_13:
return V_11 ;
}
static int F_36 ( struct V_10 * V_6 )
{
struct V_2 * V_3 = F_37 ( V_6 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_6 ( & V_6 -> V_4 , L_14 ) ;
F_38 ( & V_4 -> V_3 ) ;
F_34 ( & V_4 -> V_58 ) ;
F_35 ( V_4 ) ;
return 0 ;
}
