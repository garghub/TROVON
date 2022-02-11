static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
F_3 ( F_4 ( V_2 ) ) ;
F_5 ( V_2 ) ;
}
static int F_6 ( struct V_3 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_2 = F_7 ( V_3 -> V_6 , struct V_1 , V_6 ) ;
int V_7 ;
T_1 V_8 ;
F_5 ( V_2 ) ;
V_2 -> V_9 = V_5 -> V_10 ;
if ( V_5 -> V_11 ) {
if ( V_5 -> V_12 ) {
F_8 ( V_2 , V_5 -> V_8 , V_5 -> V_13 , & V_7 ) ;
V_8 = F_9 ( V_2 , V_5 -> V_13 , & V_7 ) ;
V_5 -> V_8 = V_8 ;
} else {
F_8 ( V_2 , V_5 -> V_8 , V_5 -> V_13 , & V_7 ) ;
}
} else {
V_8 = F_9 ( V_2 , V_5 -> V_13 , & V_7 ) ;
V_5 -> V_8 = V_8 ;
}
F_2 ( V_2 ) ;
if ( V_7 )
F_10 ( & V_2 -> V_6 , L_1 , V_14 , V_7 ) ;
return V_7 ;
}
static int F_11 ( struct V_3 * V_3 , struct V_15 * V_5 )
{
struct V_1 * V_2 = F_7 ( V_3 -> V_6 , struct V_1 , V_6 ) ;
int V_16 , V_7 ;
F_5 ( V_2 ) ;
V_2 -> V_9 = V_5 -> V_10 ;
V_2 -> V_17 = V_5 -> V_18 ;
if ( V_5 -> V_19 )
V_16 = V_5 -> V_20 * V_5 -> V_18 ;
else
V_16 = V_5 -> V_20 ;
if ( V_5 -> V_11 ) {
V_7 = F_12 ( V_2 , V_5 -> V_13 ,
( void * ) V_5 -> V_21 , V_16 ) ;
} else {
V_7 = F_13 ( V_2 , ( void * ) V_5 -> V_21 ,
V_5 -> V_13 , V_16 ) ;
}
F_2 ( V_2 ) ;
if ( V_7 )
F_10 ( & V_2 -> V_6 , L_1 , V_14 , V_7 ) ;
return V_7 ;
}
static int F_14 ( struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_3 * V_3 ;
int V_24 , V_7 ;
V_24 = - 1 ;
if ( F_15 ( V_25 ) ) {
V_24 = F_16 ( V_2 -> V_6 . V_26 , 0 ) ;
if ( V_24 < 0 )
V_24 = V_27 ;
}
F_17 ( & V_2 -> V_6 , L_2 ) ;
V_7 = F_18 ( & V_3 , & V_2 -> V_6 , V_28 , V_24 ,
& V_29 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 , L_3 ) ;
return V_7 ;
}
F_19 ( V_2 , V_3 ) ;
V_3 -> V_6 = & V_2 -> V_6 ;
F_20 ( & V_2 -> V_6 , L_4 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_22 ( F_4 ( V_2 ) ) ;
}
static int F_23 ( struct V_3 * V_3 )
{
struct V_4 V_5 ;
int V_7 ;
struct V_1 * V_2 = F_24 ( V_3 -> V_6 ) ;
V_5 . V_11 = 1 ;
V_5 . V_10 = 0 ;
V_5 . V_12 = 0 ;
V_5 . V_13 = 0x6 ;
V_5 . V_8 = 0x8 ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 , L_5 ) ;
return V_7 ;
}
return 0 ;
}
static int F_25 ( struct V_30 * V_6 )
{
struct V_1 * V_2 = F_24 ( V_6 ) ;
struct V_3 * V_3 = F_4 ( V_2 ) ;
int V_7 ;
F_20 ( V_6 , L_6 ) ;
F_26 ( V_3 ) ;
if ( ! V_3 -> V_31 ) {
F_27 ( V_3 ) ;
} else {
F_28 ( V_3 ) ;
F_29 ( V_3 ) ;
}
V_7 = F_23 ( V_3 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 , L_7 ) ;
return V_7 ;
}
F_5 ( V_2 ) ;
return 0 ;
}
static int F_30 ( struct V_30 * V_6 )
{
struct V_1 * V_2 = F_24 ( V_6 ) ;
struct V_3 * V_3 = F_4 ( V_2 ) ;
F_20 ( V_6 , L_8 ) ;
F_2 ( V_2 ) ;
F_26 ( V_3 ) ;
F_31 ( V_3 , true ) ;
if ( V_3 -> V_31 )
F_32 ( V_3 ) ;
F_29 ( V_3 ) ;
return 0 ;
}
static int F_33 ( struct V_3 * V_6 )
{
struct V_1 * V_2 = F_7 ( V_6 -> V_6 , struct V_1 , V_6 ) ;
int V_7 = 0 ;
F_5 ( V_2 ) ;
V_7 = F_34 ( V_2 , F_1 ) ;
F_2 ( V_2 ) ;
if ( V_7 < 0 ) {
F_10 ( & V_2 -> V_6 , L_9 , V_7 ) ;
V_7 = - V_32 ;
}
return V_7 ;
}
static void F_35 ( struct V_3 * V_6 )
{
struct V_1 * V_2 = F_7 ( V_6 -> V_6 , struct V_1 , V_6 ) ;
int V_7 ;
F_5 ( V_2 ) ;
V_7 = F_36 ( V_2 ) ;
if ( V_7 < 0 )
F_10 ( & V_2 -> V_6 , L_10 , V_7 ) ;
F_2 ( V_2 ) ;
}
static int F_37 ( struct V_3 * V_3 , T_2 V_33 )
{
struct V_1 * V_2 = F_24 ( V_3 -> V_6 ) ;
struct V_4 V_5 ;
int V_7 ;
V_5 . V_11 = 1 ;
V_5 . V_10 = 0 ;
V_5 . V_12 = 0 ;
V_5 . V_13 = 0x10c ;
V_5 . V_8 = ( T_1 ) V_33 ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 , L_11 ) ;
goto V_34;
}
V_5 . V_13 = 0x10d ;
V_5 . V_8 = ( T_1 ) ( V_33 >> 8 ) ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 , L_12 ) ;
goto V_34;
}
V_5 . V_13 = 0x10e ;
V_5 . V_8 = ( T_1 ) ( V_33 >> 16 ) ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 , L_13 ) ;
goto V_34;
}
return 1 ;
V_34:
return 0 ;
}
static int F_38 ( struct V_3 * V_3 , T_2 V_18 )
{
struct V_1 * V_2 = F_24 ( V_3 -> V_6 ) ;
struct V_4 V_5 ;
int V_7 ;
V_5 . V_11 = 1 ;
V_5 . V_10 = 0 ;
V_5 . V_12 = 0 ;
V_5 . V_13 = 0x10 ;
V_5 . V_8 = ( T_1 ) V_18 ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 , L_14 ) ;
goto V_34;
}
V_5 . V_13 = 0x11 ;
V_5 . V_8 = ( T_1 ) ( V_18 >> 8 ) ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 , L_15 ) ;
goto V_34;
}
return 1 ;
V_34:
return 0 ;
}
static int F_39 ( struct V_3 * V_3 , T_2 V_18 )
{
struct V_1 * V_2 = F_24 ( V_3 -> V_6 ) ;
struct V_4 V_5 ;
int V_7 ;
V_5 . V_11 = 1 ;
V_5 . V_10 = 0 ;
V_5 . V_12 = 0 ;
V_5 . V_13 = 0x110 ;
V_5 . V_8 = ( T_1 ) V_18 ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 , L_16 ) ;
goto V_34;
}
V_5 . V_13 = 0x111 ;
V_5 . V_8 = ( T_1 ) ( V_18 >> 8 ) ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 , L_17 ) ;
goto V_34;
}
return 1 ;
V_34:
return 0 ;
}
static int F_40 ( struct V_3 * V_3 , T_2 V_35 , T_2 V_8 )
{
struct V_1 * V_2 = F_24 ( V_3 -> V_6 ) ;
int V_7 ;
V_8 = F_41 ( V_8 ) ;
if ( ( V_35 >= 0xf0 ) && ( V_35 <= 0xff ) ) {
struct V_4 V_5 ;
V_5 . V_11 = 1 ;
V_5 . V_10 = 0 ;
V_5 . V_12 = 0 ;
V_5 . V_13 = V_35 ;
V_5 . V_8 = V_8 ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 ,
L_18 , V_35 ) ;
goto V_34;
}
} else {
struct V_15 V_5 ;
if ( ! F_37 ( V_3 , V_35 ) )
goto V_34;
V_5 . V_11 = 1 ;
V_5 . V_10 = 0 ;
V_5 . V_13 = 0x10f ;
V_5 . V_19 = 0 ;
V_5 . V_36 = 1 ;
V_5 . V_20 = 4 ;
V_5 . V_21 = ( T_1 * ) & V_8 ;
V_5 . V_18 = V_37 . V_18 ;
V_7 = F_11 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 ,
L_19 , V_35 ) ;
goto V_34;
}
}
return 1 ;
V_34:
return 0 ;
}
static int F_42 ( struct V_3 * V_3 , T_2 V_35 , T_1 * V_38 , T_2 V_16 )
{
struct V_1 * V_2 = F_24 ( V_3 -> V_6 ) ;
T_2 V_18 = V_37 . V_18 ;
struct V_15 V_5 ;
int V_39 , V_40 , V_7 ;
V_5 . V_11 = 1 ;
if ( V_35 > 0 ) {
if ( V_16 & 0x3 ) {
V_16 += 4 ;
V_16 &= ~ 0x3 ;
}
V_5 . V_10 = 0 ;
V_5 . V_13 = 0x10f ;
} else {
if ( V_16 & 0x3 ) {
V_16 += 4 ;
V_16 &= ~ 0x3 ;
}
V_5 . V_10 = 1 ;
V_5 . V_13 = 0 ;
}
V_39 = V_16 / V_18 ;
V_40 = V_16 % V_18 ;
if ( V_39 > 0 ) {
V_5 . V_19 = 1 ;
V_5 . V_36 = 1 ;
V_5 . V_20 = V_39 ;
V_5 . V_21 = V_38 ;
V_5 . V_18 = V_18 ;
if ( V_35 > 0 ) {
if ( ! F_37 ( V_3 , V_35 ) )
goto V_34;
}
V_7 = F_11 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 ,
L_20 , V_35 ) ;
goto V_34;
}
if ( V_35 > 0 )
V_35 += V_39 * V_18 ;
V_38 += V_39 * V_18 ;
}
if ( V_40 > 0 ) {
V_5 . V_19 = 0 ;
V_5 . V_36 = 1 ;
V_5 . V_20 = V_40 ;
V_5 . V_21 = V_38 ;
V_5 . V_18 = V_18 ;
if ( V_35 > 0 ) {
if ( ! F_37 ( V_3 , V_35 ) )
goto V_34;
}
V_7 = F_11 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 ,
L_21 , V_35 ) ;
goto V_34;
}
}
return 1 ;
V_34:
return 0 ;
}
static int F_43 ( struct V_3 * V_3 , T_2 V_35 , T_2 * V_8 )
{
struct V_1 * V_2 = F_24 ( V_3 -> V_6 ) ;
int V_7 ;
if ( ( V_35 >= 0xf0 ) && ( V_35 <= 0xff ) ) {
struct V_4 V_5 ;
V_5 . V_11 = 0 ;
V_5 . V_10 = 0 ;
V_5 . V_12 = 0 ;
V_5 . V_13 = V_35 ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 ,
L_18 , V_35 ) ;
goto V_34;
}
* V_8 = V_5 . V_8 ;
} else {
struct V_15 V_5 ;
if ( ! F_37 ( V_3 , V_35 ) )
goto V_34;
V_5 . V_11 = 0 ;
V_5 . V_10 = 0 ;
V_5 . V_13 = 0x10f ;
V_5 . V_19 = 0 ;
V_5 . V_36 = 1 ;
V_5 . V_20 = 4 ;
V_5 . V_21 = ( T_1 * ) V_8 ;
V_5 . V_18 = V_37 . V_18 ;
V_7 = F_11 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 ,
L_22 , V_35 ) ;
goto V_34;
}
}
* V_8 = F_41 ( * V_8 ) ;
return 1 ;
V_34:
return 0 ;
}
static int F_44 ( struct V_3 * V_3 , T_2 V_35 , T_1 * V_38 , T_2 V_16 )
{
struct V_1 * V_2 = F_24 ( V_3 -> V_6 ) ;
T_2 V_18 = V_37 . V_18 ;
struct V_15 V_5 ;
int V_39 , V_40 , V_7 ;
V_5 . V_11 = 0 ;
if ( V_35 > 0 ) {
if ( V_16 & 0x3 ) {
V_16 += 4 ;
V_16 &= ~ 0x3 ;
}
V_5 . V_10 = 0 ;
V_5 . V_13 = 0x10f ;
} else {
if ( V_16 & 0x3 ) {
V_16 += 4 ;
V_16 &= ~ 0x3 ;
}
V_5 . V_10 = 1 ;
V_5 . V_13 = 0 ;
}
V_39 = V_16 / V_18 ;
V_40 = V_16 % V_18 ;
if ( V_39 > 0 ) {
V_5 . V_19 = 1 ;
V_5 . V_36 = 1 ;
V_5 . V_20 = V_39 ;
V_5 . V_21 = V_38 ;
V_5 . V_18 = V_18 ;
if ( V_35 > 0 ) {
if ( ! F_37 ( V_3 , V_35 ) )
goto V_34;
}
V_7 = F_11 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 ,
L_23 , V_35 ) ;
goto V_34;
}
if ( V_35 > 0 )
V_35 += V_39 * V_18 ;
V_38 += V_39 * V_18 ;
}
if ( V_40 > 0 ) {
V_5 . V_19 = 0 ;
V_5 . V_36 = 1 ;
V_5 . V_20 = V_40 ;
V_5 . V_21 = V_38 ;
V_5 . V_18 = V_18 ;
if ( V_35 > 0 ) {
if ( ! F_37 ( V_3 , V_35 ) )
goto V_34;
}
V_7 = F_11 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 ,
L_24 , V_35 ) ;
goto V_34;
}
}
return 1 ;
V_34:
return 0 ;
}
static int F_45 ( struct V_3 * V_3 )
{
return 1 ;
}
static int F_31 ( struct V_3 * V_3 , bool V_41 )
{
struct V_1 * V_2 = F_24 ( V_3 -> V_6 ) ;
struct V_4 V_5 ;
int V_42 , V_7 ;
T_2 V_43 ;
if ( ! V_41 ) {
memset ( & V_37 , 0 , sizeof( struct V_44 ) ) ;
V_37 . V_45 = V_3 -> V_46 ;
}
V_5 . V_11 = 1 ;
V_5 . V_10 = 0 ;
V_5 . V_12 = 1 ;
V_5 . V_13 = 0x100 ;
V_5 . V_8 = 0x80 ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 , L_25 ) ;
goto V_34;
}
if ( ! F_38 ( V_3 , V_47 ) ) {
F_10 ( & V_2 -> V_6 , L_26 ) ;
goto V_34;
}
V_37 . V_18 = V_47 ;
V_5 . V_11 = 1 ;
V_5 . V_10 = 0 ;
V_5 . V_12 = 1 ;
V_5 . V_13 = 0x2 ;
V_5 . V_8 = 0x2 ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 ,
L_27 ) ;
goto V_34;
}
V_5 . V_11 = 0 ;
V_5 . V_10 = 0 ;
V_5 . V_12 = 0 ;
V_5 . V_13 = 0x3 ;
V_42 = 3 ;
do {
V_5 . V_8 = 0 ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 ,
L_28 ) ;
goto V_34;
}
if ( V_5 . V_8 == 0x2 )
break;
} while ( V_42 -- );
if ( V_42 <= 0 ) {
F_10 ( & V_2 -> V_6 , L_29 ) ;
goto V_34;
}
if ( ! F_39 ( V_3 , V_47 ) ) {
F_10 ( & V_2 -> V_6 , L_30 ) ;
goto V_34;
}
V_5 . V_11 = 1 ;
V_5 . V_10 = 0 ;
V_5 . V_12 = 1 ;
V_5 . V_13 = 0x4 ;
V_5 . V_8 = 0x3 ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 , L_31 ) ;
goto V_34;
}
if ( ! V_41 ) {
if ( ! F_43 ( V_3 , 0x1000 , & V_43 ) ) {
F_10 ( & V_2 -> V_6 , L_32 ) ;
goto V_34;
}
F_10 ( & V_2 -> V_6 , L_33 , V_43 ) ;
if ( ( V_43 & 0xfff ) > 0x2a0 )
V_37 . V_48 = 1 ;
else
V_37 . V_48 = 0 ;
F_20 ( & V_2 -> V_6 , L_34 ,
V_37 . V_48 ) ;
}
return 1 ;
V_34:
return 0 ;
}
static int F_46 ( struct V_3 * V_3 , T_2 * V_16 )
{
T_2 V_49 ;
struct V_4 V_5 ;
V_5 . V_11 = 0 ;
V_5 . V_10 = 0 ;
V_5 . V_12 = 0 ;
V_5 . V_13 = 0xf2 ;
V_5 . V_8 = 0 ;
F_6 ( V_3 , & V_5 ) ;
V_49 = V_5 . V_8 ;
V_5 . V_13 = 0xf3 ;
V_5 . V_8 = 0 ;
F_6 ( V_3 , & V_5 ) ;
V_49 |= ( V_5 . V_8 << 8 ) ;
* V_16 = V_49 ;
return 1 ;
}
static int F_47 ( struct V_3 * V_3 , T_2 * V_50 )
{
struct V_1 * V_2 = F_24 ( V_3 -> V_6 ) ;
T_2 V_49 ;
struct V_4 V_5 ;
F_46 ( V_3 , & V_49 ) ;
if ( ! V_37 . V_45 ) {
int V_51 ;
V_5 . V_10 = 1 ;
V_5 . V_13 = 0x04 ;
V_5 . V_8 = 0 ;
F_6 ( V_3 , & V_5 ) ;
if ( V_5 . V_8 & F_48 ( 0 ) )
V_49 |= V_52 ;
if ( V_5 . V_8 & F_48 ( 2 ) )
V_49 |= V_53 ;
if ( V_5 . V_8 & F_48 ( 3 ) )
V_49 |= V_54 ;
if ( V_5 . V_8 & F_48 ( 4 ) )
V_49 |= V_55 ;
if ( V_5 . V_8 & F_48 ( 5 ) )
V_49 |= V_56 ;
if ( V_5 . V_8 & F_48 ( 6 ) )
V_49 |= V_57 ;
for ( V_51 = V_37 . V_58 ; V_51 < V_59 ; V_51 ++ ) {
if ( ( V_49 >> ( V_60 + V_51 ) ) & 0x1 ) {
F_10 ( & V_2 -> V_6 ,
L_35 ,
V_49 , V_5 . V_8 ) ;
break;
}
}
} else {
T_2 V_61 ;
V_5 . V_11 = 0 ;
V_5 . V_10 = 0 ;
V_5 . V_12 = 0 ;
V_5 . V_13 = 0xf7 ;
V_5 . V_8 = 0 ;
F_6 ( V_3 , & V_5 ) ;
V_61 = V_5 . V_8 & 0x1f ;
V_49 |= ( ( V_61 >> 0 ) << V_60 ) ;
}
* V_50 = V_49 ;
return 1 ;
}
static int F_49 ( struct V_3 * V_3 , T_2 V_62 )
{
struct V_1 * V_2 = F_24 ( V_3 -> V_6 ) ;
int V_7 ;
if ( V_37 . V_48 ) {
T_2 V_63 ;
if ( V_37 . V_45 ) {
T_2 V_64 ;
V_64 = V_62 & ( F_48 ( V_65 ) - 1 ) ;
V_63 = V_64 ;
} else {
V_63 = 0 ;
}
if ( ( V_62 & V_66 ) == V_66 )
V_63 |= F_48 ( 5 ) ;
if ( ( V_62 & V_67 ) == V_67 )
V_63 |= F_48 ( 6 ) ;
if ( ( V_62 & V_68 ) == V_68 )
V_63 |= F_48 ( 7 ) ;
if ( V_63 ) {
struct V_4 V_5 ;
V_5 . V_11 = 1 ;
V_5 . V_10 = 0 ;
V_5 . V_12 = 0 ;
V_5 . V_13 = 0xf8 ;
V_5 . V_8 = V_63 ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 ,
L_36 ,
__LINE__ ) ;
goto V_34;
}
}
} else {
if ( V_37 . V_45 ) {
T_2 V_64 ;
V_64 = V_62 & ( F_48 ( V_59 ) - 1 ) ;
if ( V_64 ) {
int V_51 ;
V_7 = 1 ;
for ( V_51 = 0 ; V_51 < V_37 . V_58 ; V_51 ++ ) {
if ( V_64 & 1 ) {
struct V_4 V_5 ;
V_5 . V_11 = 1 ;
V_5 . V_10 = 0 ;
V_5 . V_12 = 0 ;
V_5 . V_13 = 0xf8 ;
V_5 . V_8 = F_48 ( V_51 ) ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 ,
L_36 ,
__LINE__ ) ;
goto V_34;
}
}
if ( ! V_7 )
break;
V_64 >>= 1 ;
}
if ( ! V_7 )
goto V_34;
for ( V_51 = V_37 . V_58 ; V_51 < V_59 ; V_51 ++ ) {
if ( V_64 & 1 )
F_10 ( & V_2 -> V_6 ,
L_37 ,
V_51 ) ;
V_64 >>= 1 ;
}
}
}
{
T_2 V_69 ;
V_69 = 0 ;
if ( ( V_62 & V_66 ) == V_66 )
V_69 |= F_48 ( 0 ) ;
if ( ( V_62 & V_67 ) == V_67 )
V_69 |= F_48 ( 1 ) ;
if ( ( V_62 & V_68 ) == V_68 )
V_69 |= F_48 ( 2 ) ;
if ( V_69 ) {
struct V_4 V_5 ;
V_5 . V_11 = 1 ;
V_5 . V_10 = 0 ;
V_5 . V_12 = 0 ;
V_5 . V_13 = 0xf6 ;
V_5 . V_8 = V_69 ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 ,
L_38 ,
__LINE__ ) ;
goto V_34;
}
}
}
}
return 1 ;
V_34:
return 0 ;
}
static int F_50 ( struct V_3 * V_3 , int V_58 )
{
struct V_1 * V_2 = F_24 ( V_3 -> V_6 ) ;
T_2 V_63 ;
if ( V_58 > V_59 ) {
F_10 ( & V_2 -> V_6 , L_39 , V_58 ) ;
return 0 ;
}
if ( V_58 > V_65 ) {
F_10 ( & V_2 -> V_6 ,
L_40 ) ;
return 0 ;
}
V_37 . V_58 = V_58 ;
if ( ! F_43 ( V_3 , V_70 , & V_63 ) ) {
F_10 ( & V_2 -> V_6 , L_41 ) ;
return 0 ;
}
V_63 &= ~ F_48 ( 8 ) ;
if ( ! F_40 ( V_3 , V_70 , V_63 ) ) {
F_10 ( & V_2 -> V_6 , L_42 ) ;
return 0 ;
}
if ( V_37 . V_45 ) {
T_2 V_63 ;
int V_7 , V_51 ;
V_7 = F_43 ( V_3 , V_71 , & V_63 ) ;
if ( ! V_7 ) {
F_10 ( & V_2 -> V_6 , L_43 ,
V_71 ) ;
return 0 ;
}
V_63 |= F_48 ( 8 ) ;
V_7 = F_40 ( V_3 , V_71 , V_63 ) ;
if ( ! V_7 ) {
F_10 ( & V_2 -> V_6 , L_44 ,
V_71 ) ;
return 0 ;
}
V_7 = F_43 ( V_3 , V_72 , & V_63 ) ;
if ( ! V_7 ) {
F_10 ( & V_2 -> V_6 , L_43 ,
V_72 ) ;
return 0 ;
}
for ( V_51 = 0 ; ( V_51 < 5 ) && ( V_58 > 0 ) ; V_51 ++ , V_58 -- )
V_63 |= F_48 ( ( 27 + V_51 ) ) ;
V_7 = F_40 ( V_3 , V_72 , V_63 ) ;
if ( ! V_7 ) {
F_10 ( & V_2 -> V_6 , L_44 ,
V_72 ) ;
return 0 ;
}
if ( V_58 ) {
V_7 = F_43 ( V_3 , V_73 , & V_63 ) ;
if ( ! V_7 ) {
F_10 ( & V_2 -> V_6 ,
L_43 ,
V_73 ) ;
return 0 ;
}
for ( V_51 = 0 ; ( V_51 < 3 ) && ( V_58 > 0 ) ; V_51 ++ , V_58 -- )
V_63 |= F_48 ( V_51 ) ;
V_7 = F_43 ( V_3 , V_73 , & V_63 ) ;
if ( ! V_7 ) {
F_10 ( & V_2 -> V_6 ,
L_44 ,
V_73 ) ;
return 0 ;
}
}
}
return 1 ;
}
