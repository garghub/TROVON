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
F_6 ( & V_4 -> V_6 -> V_12 , L_1 ,
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
goto V_13;
return 0 ;
V_13:
F_6 ( & V_4 -> V_6 -> V_12 , L_2 , V_10 ) ;
return V_10 ;
}
static int F_7 ( struct V_1 * V_4 )
{
int V_10 , V_14 ;
unsigned int V_15 , V_16 , V_17 , V_18 , V_19 , V_20 , V_21 ;
T_1 V_11 ;
T_2 V_22 , V_23 ;
T_3 V_24 , V_25 , V_26 ;
static const struct {
T_1 V_27 ;
T_3 V_24 ;
T_3 V_26 ;
} V_28 [] = {
{ 50000000 , 0xe1 , 16 } ,
{ 108000000 , 0x42 , 32 } ,
{ 330000000 , 0x44 , 16 } ,
{ 960000000 , 0x48 , 4 } ,
{ ~ 0U , 0x50 , 2 } ,
} ;
static const struct {
T_1 V_29 ;
T_3 V_25 ;
} V_30 [] = {
{ 0 , 0x03 } ,
{ 450000 , 0x02 } ,
{ 1620000 , 0x01 } ,
{ 2048000 , 0x00 } ,
} ;
static const struct {
T_1 V_29 ;
T_3 V_31 ;
} V_32 [] = {
{ 200000 , 0x00 } ,
{ 300000 , 0x01 } ,
{ 600000 , 0x02 } ,
{ 1536000 , 0x03 } ,
{ 5000000 , 0x04 } ,
{ 6000000 , 0x05 } ,
{ 7000000 , 0x06 } ,
{ 8000000 , 0x07 } ,
} ;
unsigned int V_33 = V_4 -> V_34 ;
unsigned int V_35 ;
unsigned int V_36 = 0 ;
#define F_8 24000000
#define F_9 4
#define F_10 1
F_6 ( & V_4 -> V_6 -> V_12 , L_3 , V_33 , V_36 ) ;
for ( V_14 = 0 ; V_14 < F_11 ( V_28 ) ; V_14 ++ ) {
if ( V_33 <= V_28 [ V_14 ] . V_27 ) {
V_24 = V_28 [ V_14 ] . V_24 ;
V_26 = V_28 [ V_14 ] . V_26 ;
break;
}
}
if ( V_14 == F_11 ( V_28 ) ) {
V_10 = - V_37 ;
goto V_13;
}
if ( ( V_24 >> 0 ) & 0x1 )
V_21 = 5 * F_8 ;
else
V_21 = 0 ;
for ( V_14 = 0 ; V_14 < F_11 ( V_30 ) ; V_14 ++ ) {
if ( V_36 == V_30 [ V_14 ] . V_29 ) {
V_25 = V_30 [ V_14 ] . V_25 ;
break;
}
}
if ( V_14 == F_11 ( V_30 ) ) {
V_10 = - V_37 ;
goto V_13;
}
V_35 = V_4 -> V_35 -> V_31 ;
V_35 = F_12 ( V_35 , 200000U , 8000000U ) ;
for ( V_14 = 0 ; V_14 < F_11 ( V_32 ) ; V_14 ++ ) {
if ( V_35 <= V_32 [ V_14 ] . V_29 ) {
V_35 = V_32 [ V_14 ] . V_31 ;
break;
}
}
if ( V_14 == F_11 ( V_32 ) ) {
V_10 = - V_37 ;
goto V_13;
}
V_4 -> V_35 -> V_31 = V_32 [ V_14 ] . V_29 ;
F_6 ( & V_4 -> V_6 -> V_12 , L_4 , V_32 [ V_14 ] . V_29 ) ;
V_22 = ( T_2 ) ( V_33 + V_36 + V_21 ) * V_26 ;
V_23 = V_22 ;
V_16 = F_13 ( V_23 , F_8 * F_9 ) ;
V_15 = ( unsigned int ) V_23 ;
V_19 = F_10 * V_26 ;
V_17 = ( F_8 * F_9 ) / V_19 ;
V_18 = 1ul * V_17 * V_16 / ( F_8 * F_9 ) ;
V_20 = F_14 ( V_17 , V_18 ) ;
V_17 /= V_20 ;
V_18 /= V_20 ;
V_20 = F_15 ( V_17 , 4095 ) ;
V_17 = F_16 ( V_17 , V_20 ) ;
V_18 = F_16 ( V_18 , V_20 ) ;
V_20 = 1ul * F_8 * F_9 * V_15 ;
V_20 += 1ul * F_8 * F_9 * V_18 / V_17 ;
V_20 /= V_26 ;
F_6 ( & V_4 -> V_6 -> V_12 , L_5 ,
V_33 , V_20 , V_15 , V_17 , V_18 ) ;
V_10 = F_3 ( V_4 , 0x00000e ) ;
if ( V_10 )
goto V_13;
V_10 = F_3 ( V_4 , 0x000003 ) ;
if ( V_10 )
goto V_13;
V_11 = 0 << 0 ;
V_11 |= V_24 << 4 ;
V_11 |= V_25 << 12 ;
V_11 |= V_35 << 14 ;
V_11 |= 0x02 << 17 ;
V_11 |= 0x00 << 20 ;
V_10 = F_3 ( V_4 , V_11 ) ;
if ( V_10 )
goto V_13;
V_11 = 5 << 0 ;
V_11 |= V_17 << 4 ;
V_11 |= 1 << 19 ;
V_11 |= 1 << 21 ;
V_10 = F_3 ( V_4 , V_11 ) ;
if ( V_10 )
goto V_13;
V_11 = 2 << 0 ;
V_11 |= V_18 << 4 ;
V_11 |= V_15 << 16 ;
V_10 = F_3 ( V_4 , V_11 ) ;
if ( V_10 )
goto V_13;
V_10 = F_5 ( V_4 , V_4 -> V_7 -> V_38 . V_31 , V_4 -> V_8 -> V_38 . V_31 ,
V_4 -> V_9 -> V_38 . V_31 ) ;
if ( V_10 )
goto V_13;
V_11 = 6 << 0 ;
V_11 |= 63 << 4 ;
V_11 |= 4095 << 10 ;
V_10 = F_3 ( V_4 , V_11 ) ;
if ( V_10 )
goto V_13;
return 0 ;
V_13:
F_6 ( & V_4 -> V_6 -> V_12 , L_2 , V_10 ) ;
return V_10 ;
}
static int F_17 ( struct V_2 * V_3 , int V_39 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_10 ;
F_6 ( & V_4 -> V_6 -> V_12 , L_6 , V_39 ) ;
if ( V_39 )
V_10 = 0 ;
else
V_10 = F_3 ( V_4 , 0x000000 ) ;
return V_10 ;
}
static int F_18 ( struct V_2 * V_3 , struct V_40 * V_41 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_6 ( & V_4 -> V_6 -> V_12 , L_7 , V_41 -> V_42 ) ;
F_19 ( V_41 -> V_43 , L_8 , sizeof( V_41 -> V_43 ) ) ;
V_41 -> type = V_44 ;
V_41 -> V_45 = V_46 | V_47 ;
V_41 -> V_48 = 49000000 ;
V_41 -> V_49 = 960000000 ;
return 0 ;
}
static int F_20 ( struct V_2 * V_3 , const struct V_40 * V_41 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_6 ( & V_4 -> V_6 -> V_12 , L_7 , V_41 -> V_42 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 , struct V_50 * V_51 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_6 ( & V_4 -> V_6 -> V_12 , L_9 , V_51 -> V_52 ) ;
V_51 -> V_53 = V_4 -> V_34 ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 ,
const struct V_50 * V_51 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_54 ;
F_6 ( & V_4 -> V_6 -> V_12 , L_10 ,
V_51 -> V_52 , V_51 -> type , V_51 -> V_53 ) ;
if ( V_51 -> V_53 < ( ( V_55 [ 0 ] . V_49 + V_55 [ 1 ] . V_48 ) / 2 ) )
V_54 = 0 ;
else
V_54 = 1 ;
V_4 -> V_34 = F_23 (unsigned int, f->frequency,
bands[band].rangelow, bands[band].rangehigh) ;
return F_7 ( V_4 ) ;
}
static int F_24 ( struct V_2 * V_3 ,
struct V_56 * V_54 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_6 ( & V_4 -> V_6 -> V_12 , L_11 ,
V_54 -> V_52 , V_54 -> type , V_54 -> V_42 ) ;
if ( V_54 -> V_42 >= F_11 ( V_55 ) )
return - V_37 ;
V_54 -> V_45 = V_55 [ V_54 -> V_42 ] . V_45 ;
V_54 -> V_48 = V_55 [ V_54 -> V_42 ] . V_48 ;
V_54 -> V_49 = V_55 [ V_54 -> V_42 ] . V_49 ;
return 0 ;
}
static int F_25 ( struct V_57 * V_58 )
{
struct V_1 * V_4 = F_2 ( V_58 -> V_59 , struct V_1 , V_60 ) ;
int V_10 ;
F_6 ( & V_4 -> V_6 -> V_12 ,
L_12 ,
V_58 -> V_61 , V_58 -> V_43 , V_58 -> V_31 ,
V_58 -> V_62 , V_58 -> V_63 , V_58 -> V_64 ) ;
switch ( V_58 -> V_61 ) {
case V_65 :
case V_66 :
V_10 = F_7 ( V_4 ) ;
break;
case V_67 :
V_10 = F_5 ( V_4 , V_4 -> V_7 -> V_31 ,
V_4 -> V_8 -> V_38 . V_31 , V_4 -> V_9 -> V_38 . V_31 ) ;
break;
case V_68 :
V_10 = F_5 ( V_4 , V_4 -> V_7 -> V_38 . V_31 ,
V_4 -> V_8 -> V_31 , V_4 -> V_9 -> V_38 . V_31 ) ;
break;
case V_69 :
V_10 = F_5 ( V_4 , V_4 -> V_7 -> V_38 . V_31 ,
V_4 -> V_8 -> V_38 . V_31 , V_4 -> V_9 -> V_31 ) ;
break;
default:
F_6 ( & V_4 -> V_6 -> V_12 , L_13 , V_58 -> V_61 ) ;
V_10 = - V_37 ;
}
return V_10 ;
}
static int F_26 ( struct V_70 * V_6 )
{
struct V_1 * V_4 ;
int V_10 ;
F_6 ( & V_6 -> V_12 , L_14 ) ;
V_4 = F_27 ( sizeof( struct V_1 ) , V_71 ) ;
if ( V_4 == NULL ) {
V_10 = - V_72 ;
F_6 ( & V_6 -> V_12 , L_15 ) ;
goto V_73;
}
V_4 -> V_6 = V_6 ;
V_4 -> V_34 = V_55 [ 0 ] . V_48 ;
F_28 ( & V_4 -> V_3 , V_6 , & V_74 ) ;
F_29 ( & V_4 -> V_60 , 5 ) ;
V_4 -> V_75 = F_30 ( & V_4 -> V_60 , & V_76 ,
V_65 , 0 , 1 , 1 , 1 ) ;
V_4 -> V_35 = F_30 ( & V_4 -> V_60 , & V_76 ,
V_66 , 200000 , 8000000 , 1 , 200000 ) ;
F_31 ( 2 , & V_4 -> V_75 , 0 , false ) ;
V_4 -> V_7 = F_30 ( & V_4 -> V_60 , & V_76 ,
V_67 , 0 , 1 , 1 , 1 ) ;
V_4 -> V_8 = F_30 ( & V_4 -> V_60 , & V_76 ,
V_68 , 0 , 1 , 1 , 1 ) ;
V_4 -> V_9 = F_30 ( & V_4 -> V_60 , & V_76 ,
V_69 , 0 , 59 , 1 , 0 ) ;
if ( V_4 -> V_60 . error ) {
V_10 = V_4 -> V_60 . error ;
F_32 ( & V_4 -> V_6 -> V_12 , L_16 ) ;
goto V_77;
}
V_4 -> V_3 . V_78 = & V_4 -> V_60 ;
return 0 ;
V_77:
F_33 ( & V_4 -> V_60 ) ;
V_73:
F_34 ( V_4 ) ;
return V_10 ;
}
static int F_35 ( struct V_70 * V_6 )
{
struct V_2 * V_3 = F_36 ( V_6 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_6 ( & V_6 -> V_12 , L_14 ) ;
F_37 ( & V_4 -> V_3 ) ;
F_33 ( & V_4 -> V_60 ) ;
F_34 ( V_4 ) ;
return 0 ;
}
