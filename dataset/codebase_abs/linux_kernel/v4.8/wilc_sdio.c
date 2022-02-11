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
F_10 ( & V_2 -> V_6 , L_1 , V_7 ) ;
return V_7 ;
}
static int F_11 ( struct V_3 * V_3 , struct V_14 * V_5 )
{
struct V_1 * V_2 = F_7 ( V_3 -> V_6 , struct V_1 , V_6 ) ;
int V_15 , V_7 ;
F_5 ( V_2 ) ;
V_2 -> V_9 = V_5 -> V_10 ;
V_2 -> V_16 = V_5 -> V_17 ;
if ( V_5 -> V_18 )
V_15 = V_5 -> V_19 * V_5 -> V_17 ;
else
V_15 = V_5 -> V_19 ;
if ( V_5 -> V_11 ) {
V_7 = F_12 ( V_2 , V_5 -> V_13 ,
( void * ) V_5 -> V_20 , V_15 ) ;
} else {
V_7 = F_13 ( V_2 , ( void * ) V_5 -> V_20 ,
V_5 -> V_13 , V_15 ) ;
}
F_2 ( V_2 ) ;
if ( V_7 )
F_10 ( & V_2 -> V_6 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_14 ( struct V_1 * V_2 ,
const struct V_21 * V_22 )
{
struct V_3 * V_3 ;
int V_23 , V_7 ;
V_23 = - 1 ;
if ( F_15 ( V_24 ) ) {
V_23 = F_16 ( V_2 -> V_6 . V_25 , 0 ) ;
if ( V_23 < 0 )
V_23 = V_26 ;
}
F_17 ( & V_2 -> V_6 , L_3 ) ;
V_7 = F_18 ( & V_3 , & V_2 -> V_6 , V_27 , V_23 ,
& V_28 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 , L_4 ) ;
return V_7 ;
}
F_19 ( V_2 , V_3 ) ;
V_3 -> V_6 = & V_2 -> V_6 ;
F_20 ( & V_2 -> V_6 , L_5 ) ;
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
F_10 ( & V_2 -> V_6 , L_6 ) ;
return V_7 ;
}
return 0 ;
}
static int F_25 ( struct V_29 * V_6 )
{
struct V_1 * V_2 = F_24 ( V_6 ) ;
struct V_3 * V_3 = F_4 ( V_2 ) ;
int V_7 ;
F_20 ( V_6 , L_7 ) ;
F_26 ( V_3 ) ;
if ( ! V_3 -> V_30 ) {
F_27 ( V_3 ) ;
} else {
F_28 ( V_3 ) ;
F_29 ( V_3 ) ;
}
V_7 = F_23 ( V_3 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 , L_8 ) ;
return V_7 ;
}
F_5 ( V_2 ) ;
return 0 ;
}
static int F_30 ( struct V_29 * V_6 )
{
struct V_1 * V_2 = F_24 ( V_6 ) ;
struct V_3 * V_3 = F_4 ( V_2 ) ;
F_20 ( V_6 , L_9 ) ;
F_2 ( V_2 ) ;
F_26 ( V_3 ) ;
F_31 ( V_3 , true ) ;
if ( V_3 -> V_30 )
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
F_10 ( & V_2 -> V_6 , L_10 , V_7 ) ;
V_7 = - V_31 ;
}
return V_7 ;
}
static void F_35 ( struct V_3 * V_6 )
{
struct V_1 * V_2 = F_7 ( V_6 -> V_6 , struct V_1 , V_6 ) ;
int V_7 ;
F_17 ( & V_2 -> V_6 , L_11 ) ;
F_5 ( V_2 ) ;
V_7 = F_36 ( V_2 ) ;
if ( V_7 < 0 )
F_10 ( & V_2 -> V_6 , L_12 , V_7 ) ;
F_2 ( V_2 ) ;
F_20 ( & V_2 -> V_6 , L_13 ) ;
}
static int F_37 ( struct V_3 * V_3 , T_2 V_32 )
{
struct V_1 * V_2 = F_24 ( V_3 -> V_6 ) ;
struct V_4 V_5 ;
int V_7 ;
V_5 . V_11 = 1 ;
V_5 . V_10 = 0 ;
V_5 . V_12 = 0 ;
V_5 . V_13 = 0x10c ;
V_5 . V_8 = ( T_1 ) V_32 ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 , L_14 ) ;
goto V_33;
}
V_5 . V_13 = 0x10d ;
V_5 . V_8 = ( T_1 ) ( V_32 >> 8 ) ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 , L_15 ) ;
goto V_33;
}
V_5 . V_13 = 0x10e ;
V_5 . V_8 = ( T_1 ) ( V_32 >> 16 ) ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 , L_16 ) ;
goto V_33;
}
return 1 ;
V_33:
return 0 ;
}
static int F_38 ( struct V_3 * V_3 , T_2 V_17 )
{
struct V_1 * V_2 = F_24 ( V_3 -> V_6 ) ;
struct V_4 V_5 ;
int V_7 ;
V_5 . V_11 = 1 ;
V_5 . V_10 = 0 ;
V_5 . V_12 = 0 ;
V_5 . V_13 = 0x10 ;
V_5 . V_8 = ( T_1 ) V_17 ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 , L_17 ) ;
goto V_33;
}
V_5 . V_13 = 0x11 ;
V_5 . V_8 = ( T_1 ) ( V_17 >> 8 ) ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 , L_18 ) ;
goto V_33;
}
return 1 ;
V_33:
return 0 ;
}
static int F_39 ( struct V_3 * V_3 , T_2 V_17 )
{
struct V_1 * V_2 = F_24 ( V_3 -> V_6 ) ;
struct V_4 V_5 ;
int V_7 ;
V_5 . V_11 = 1 ;
V_5 . V_10 = 0 ;
V_5 . V_12 = 0 ;
V_5 . V_13 = 0x110 ;
V_5 . V_8 = ( T_1 ) V_17 ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 , L_19 ) ;
goto V_33;
}
V_5 . V_13 = 0x111 ;
V_5 . V_8 = ( T_1 ) ( V_17 >> 8 ) ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 , L_20 ) ;
goto V_33;
}
return 1 ;
V_33:
return 0 ;
}
static int F_40 ( struct V_3 * V_3 , T_2 V_34 , T_2 V_8 )
{
struct V_1 * V_2 = F_24 ( V_3 -> V_6 ) ;
int V_7 ;
V_8 = F_41 ( V_8 ) ;
if ( ( V_34 >= 0xf0 ) && ( V_34 <= 0xff ) ) {
struct V_4 V_5 ;
V_5 . V_11 = 1 ;
V_5 . V_10 = 0 ;
V_5 . V_12 = 0 ;
V_5 . V_13 = V_34 ;
V_5 . V_8 = V_8 ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 ,
L_21 , V_34 ) ;
goto V_33;
}
} else {
struct V_14 V_5 ;
if ( ! F_37 ( V_3 , V_34 ) )
goto V_33;
V_5 . V_11 = 1 ;
V_5 . V_10 = 0 ;
V_5 . V_13 = 0x10f ;
V_5 . V_18 = 0 ;
V_5 . V_35 = 1 ;
V_5 . V_19 = 4 ;
V_5 . V_20 = ( T_1 * ) & V_8 ;
V_5 . V_17 = V_36 . V_17 ;
V_7 = F_11 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 ,
L_22 , V_34 ) ;
goto V_33;
}
}
return 1 ;
V_33:
return 0 ;
}
static int F_42 ( struct V_3 * V_3 , T_2 V_34 , T_1 * V_37 , T_2 V_15 )
{
struct V_1 * V_2 = F_24 ( V_3 -> V_6 ) ;
T_2 V_17 = V_36 . V_17 ;
struct V_14 V_5 ;
int V_38 , V_39 , V_7 ;
V_5 . V_11 = 1 ;
if ( V_34 > 0 ) {
if ( V_15 & 0x3 ) {
V_15 += 4 ;
V_15 &= ~ 0x3 ;
}
V_5 . V_10 = 0 ;
V_5 . V_13 = 0x10f ;
} else {
if ( V_15 & 0x3 ) {
V_15 += 4 ;
V_15 &= ~ 0x3 ;
}
V_5 . V_10 = 1 ;
V_5 . V_13 = 0 ;
}
V_38 = V_15 / V_17 ;
V_39 = V_15 % V_17 ;
if ( V_38 > 0 ) {
V_5 . V_18 = 1 ;
V_5 . V_35 = 1 ;
V_5 . V_19 = V_38 ;
V_5 . V_20 = V_37 ;
V_5 . V_17 = V_17 ;
if ( V_34 > 0 ) {
if ( ! F_37 ( V_3 , V_34 ) )
goto V_33;
}
V_7 = F_11 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 ,
L_23 , V_34 ) ;
goto V_33;
}
if ( V_34 > 0 )
V_34 += V_38 * V_17 ;
V_37 += V_38 * V_17 ;
}
if ( V_39 > 0 ) {
V_5 . V_18 = 0 ;
V_5 . V_35 = 1 ;
V_5 . V_19 = V_39 ;
V_5 . V_20 = V_37 ;
V_5 . V_17 = V_17 ;
if ( V_34 > 0 ) {
if ( ! F_37 ( V_3 , V_34 ) )
goto V_33;
}
V_7 = F_11 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 ,
L_24 , V_34 ) ;
goto V_33;
}
}
return 1 ;
V_33:
return 0 ;
}
static int F_43 ( struct V_3 * V_3 , T_2 V_34 , T_2 * V_8 )
{
struct V_1 * V_2 = F_24 ( V_3 -> V_6 ) ;
int V_7 ;
if ( ( V_34 >= 0xf0 ) && ( V_34 <= 0xff ) ) {
struct V_4 V_5 ;
V_5 . V_11 = 0 ;
V_5 . V_10 = 0 ;
V_5 . V_12 = 0 ;
V_5 . V_13 = V_34 ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 ,
L_21 , V_34 ) ;
goto V_33;
}
* V_8 = V_5 . V_8 ;
} else {
struct V_14 V_5 ;
if ( ! F_37 ( V_3 , V_34 ) )
goto V_33;
V_5 . V_11 = 0 ;
V_5 . V_10 = 0 ;
V_5 . V_13 = 0x10f ;
V_5 . V_18 = 0 ;
V_5 . V_35 = 1 ;
V_5 . V_19 = 4 ;
V_5 . V_20 = ( T_1 * ) V_8 ;
V_5 . V_17 = V_36 . V_17 ;
V_7 = F_11 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 ,
L_25 , V_34 ) ;
goto V_33;
}
}
* V_8 = F_41 ( * V_8 ) ;
return 1 ;
V_33:
return 0 ;
}
static int F_44 ( struct V_3 * V_3 , T_2 V_34 , T_1 * V_37 , T_2 V_15 )
{
struct V_1 * V_2 = F_24 ( V_3 -> V_6 ) ;
T_2 V_17 = V_36 . V_17 ;
struct V_14 V_5 ;
int V_38 , V_39 , V_7 ;
V_5 . V_11 = 0 ;
if ( V_34 > 0 ) {
if ( V_15 & 0x3 ) {
V_15 += 4 ;
V_15 &= ~ 0x3 ;
}
V_5 . V_10 = 0 ;
V_5 . V_13 = 0x10f ;
} else {
if ( V_15 & 0x3 ) {
V_15 += 4 ;
V_15 &= ~ 0x3 ;
}
V_5 . V_10 = 1 ;
V_5 . V_13 = 0 ;
}
V_38 = V_15 / V_17 ;
V_39 = V_15 % V_17 ;
if ( V_38 > 0 ) {
V_5 . V_18 = 1 ;
V_5 . V_35 = 1 ;
V_5 . V_19 = V_38 ;
V_5 . V_20 = V_37 ;
V_5 . V_17 = V_17 ;
if ( V_34 > 0 ) {
if ( ! F_37 ( V_3 , V_34 ) )
goto V_33;
}
V_7 = F_11 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 ,
L_26 , V_34 ) ;
goto V_33;
}
if ( V_34 > 0 )
V_34 += V_38 * V_17 ;
V_37 += V_38 * V_17 ;
}
if ( V_39 > 0 ) {
V_5 . V_18 = 0 ;
V_5 . V_35 = 1 ;
V_5 . V_19 = V_39 ;
V_5 . V_20 = V_37 ;
V_5 . V_17 = V_17 ;
if ( V_34 > 0 ) {
if ( ! F_37 ( V_3 , V_34 ) )
goto V_33;
}
V_7 = F_11 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 ,
L_27 , V_34 ) ;
goto V_33;
}
}
return 1 ;
V_33:
return 0 ;
}
static int F_45 ( struct V_3 * V_3 )
{
return 1 ;
}
static int F_31 ( struct V_3 * V_3 , bool V_40 )
{
struct V_1 * V_2 = F_24 ( V_3 -> V_6 ) ;
struct V_4 V_5 ;
int V_41 , V_7 ;
T_2 V_42 ;
if ( ! V_40 ) {
memset ( & V_36 , 0 , sizeof( struct V_43 ) ) ;
V_36 . V_44 = V_3 -> V_45 ;
}
V_5 . V_11 = 1 ;
V_5 . V_10 = 0 ;
V_5 . V_12 = 1 ;
V_5 . V_13 = 0x100 ;
V_5 . V_8 = 0x80 ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 , L_28 ) ;
goto V_33;
}
if ( ! F_38 ( V_3 , V_46 ) ) {
F_10 ( & V_2 -> V_6 , L_29 ) ;
goto V_33;
}
V_36 . V_17 = V_46 ;
V_5 . V_11 = 1 ;
V_5 . V_10 = 0 ;
V_5 . V_12 = 1 ;
V_5 . V_13 = 0x2 ;
V_5 . V_8 = 0x2 ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 ,
L_30 ) ;
goto V_33;
}
V_5 . V_11 = 0 ;
V_5 . V_10 = 0 ;
V_5 . V_12 = 0 ;
V_5 . V_13 = 0x3 ;
V_41 = 3 ;
do {
V_5 . V_8 = 0 ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 ,
L_31 ) ;
goto V_33;
}
if ( V_5 . V_8 == 0x2 )
break;
} while ( V_41 -- );
if ( V_41 <= 0 ) {
F_10 ( & V_2 -> V_6 , L_32 ) ;
goto V_33;
}
if ( ! F_39 ( V_3 , V_46 ) ) {
F_10 ( & V_2 -> V_6 , L_33 ) ;
goto V_33;
}
V_5 . V_11 = 1 ;
V_5 . V_10 = 0 ;
V_5 . V_12 = 1 ;
V_5 . V_13 = 0x4 ;
V_5 . V_8 = 0x3 ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 , L_34 ) ;
goto V_33;
}
if ( ! V_40 ) {
if ( ! F_43 ( V_3 , 0x1000 , & V_42 ) ) {
F_10 ( & V_2 -> V_6 , L_35 ) ;
goto V_33;
}
F_10 ( & V_2 -> V_6 , L_36 , V_42 ) ;
if ( ( V_42 & 0xfff ) > 0x2a0 )
V_36 . V_47 = 1 ;
else
V_36 . V_47 = 0 ;
F_20 ( & V_2 -> V_6 , L_37 ,
V_36 . V_47 ) ;
}
return 1 ;
V_33:
return 0 ;
}
static int F_46 ( struct V_3 * V_3 , T_2 * V_15 )
{
T_2 V_48 ;
struct V_4 V_5 ;
V_5 . V_11 = 0 ;
V_5 . V_10 = 0 ;
V_5 . V_12 = 0 ;
V_5 . V_13 = 0xf2 ;
V_5 . V_8 = 0 ;
F_6 ( V_3 , & V_5 ) ;
V_48 = V_5 . V_8 ;
V_5 . V_13 = 0xf3 ;
V_5 . V_8 = 0 ;
F_6 ( V_3 , & V_5 ) ;
V_48 |= ( V_5 . V_8 << 8 ) ;
* V_15 = V_48 ;
return 1 ;
}
static int F_47 ( struct V_3 * V_3 , T_2 * V_49 )
{
struct V_1 * V_2 = F_24 ( V_3 -> V_6 ) ;
T_2 V_48 ;
struct V_4 V_5 ;
F_46 ( V_3 , & V_48 ) ;
if ( ! V_36 . V_44 ) {
int V_50 ;
V_5 . V_10 = 1 ;
V_5 . V_13 = 0x04 ;
V_5 . V_8 = 0 ;
F_6 ( V_3 , & V_5 ) ;
if ( V_5 . V_8 & F_48 ( 0 ) )
V_48 |= V_51 ;
if ( V_5 . V_8 & F_48 ( 2 ) )
V_48 |= V_52 ;
if ( V_5 . V_8 & F_48 ( 3 ) )
V_48 |= V_53 ;
if ( V_5 . V_8 & F_48 ( 4 ) )
V_48 |= V_54 ;
if ( V_5 . V_8 & F_48 ( 5 ) )
V_48 |= V_55 ;
if ( V_5 . V_8 & F_48 ( 6 ) )
V_48 |= V_56 ;
for ( V_50 = V_36 . V_57 ; V_50 < V_58 ; V_50 ++ ) {
if ( ( V_48 >> ( V_59 + V_50 ) ) & 0x1 ) {
F_10 ( & V_2 -> V_6 ,
L_38 ,
V_48 , V_5 . V_8 ) ;
break;
}
}
} else {
T_2 V_60 ;
V_5 . V_11 = 0 ;
V_5 . V_10 = 0 ;
V_5 . V_12 = 0 ;
V_5 . V_13 = 0xf7 ;
V_5 . V_8 = 0 ;
F_6 ( V_3 , & V_5 ) ;
V_60 = V_5 . V_8 & 0x1f ;
V_48 |= ( ( V_60 >> 0 ) << V_59 ) ;
}
* V_49 = V_48 ;
return 1 ;
}
static int F_49 ( struct V_3 * V_3 , T_2 V_61 )
{
struct V_1 * V_2 = F_24 ( V_3 -> V_6 ) ;
int V_7 ;
if ( V_36 . V_47 ) {
T_2 V_62 ;
if ( V_36 . V_44 ) {
T_2 V_63 ;
V_63 = V_61 & ( F_48 ( V_64 ) - 1 ) ;
V_62 = V_63 ;
} else {
V_62 = 0 ;
}
if ( ( V_61 & V_65 ) == V_65 )
V_62 |= F_48 ( 5 ) ;
if ( ( V_61 & V_66 ) == V_66 )
V_62 |= F_48 ( 6 ) ;
if ( ( V_61 & V_67 ) == V_67 )
V_62 |= F_48 ( 7 ) ;
if ( V_62 ) {
struct V_4 V_5 ;
V_5 . V_11 = 1 ;
V_5 . V_10 = 0 ;
V_5 . V_12 = 0 ;
V_5 . V_13 = 0xf8 ;
V_5 . V_8 = V_62 ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 ,
L_39 ,
__LINE__ ) ;
goto V_33;
}
}
} else {
if ( V_36 . V_44 ) {
T_2 V_63 ;
V_63 = V_61 & ( F_48 ( V_58 ) - 1 ) ;
if ( V_63 ) {
int V_50 ;
V_7 = 1 ;
for ( V_50 = 0 ; V_50 < V_36 . V_57 ; V_50 ++ ) {
if ( V_63 & 1 ) {
struct V_4 V_5 ;
V_5 . V_11 = 1 ;
V_5 . V_10 = 0 ;
V_5 . V_12 = 0 ;
V_5 . V_13 = 0xf8 ;
V_5 . V_8 = F_48 ( V_50 ) ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 ,
L_39 ,
__LINE__ ) ;
goto V_33;
}
}
if ( ! V_7 )
break;
V_63 >>= 1 ;
}
if ( ! V_7 )
goto V_33;
for ( V_50 = V_36 . V_57 ; V_50 < V_58 ; V_50 ++ ) {
if ( V_63 & 1 )
F_10 ( & V_2 -> V_6 ,
L_40 ,
V_50 ) ;
V_63 >>= 1 ;
}
}
}
{
T_2 V_68 ;
V_68 = 0 ;
if ( ( V_61 & V_65 ) == V_65 )
V_68 |= F_48 ( 0 ) ;
if ( ( V_61 & V_66 ) == V_66 )
V_68 |= F_48 ( 1 ) ;
if ( ( V_61 & V_67 ) == V_67 )
V_68 |= F_48 ( 2 ) ;
if ( V_68 ) {
struct V_4 V_5 ;
V_5 . V_11 = 1 ;
V_5 . V_10 = 0 ;
V_5 . V_12 = 0 ;
V_5 . V_13 = 0xf6 ;
V_5 . V_8 = V_68 ;
V_7 = F_6 ( V_3 , & V_5 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_6 ,
L_41 ,
__LINE__ ) ;
goto V_33;
}
}
}
}
return 1 ;
V_33:
return 0 ;
}
static int F_50 ( struct V_3 * V_3 , int V_57 )
{
struct V_1 * V_2 = F_24 ( V_3 -> V_6 ) ;
T_2 V_62 ;
if ( V_57 > V_58 ) {
F_10 ( & V_2 -> V_6 , L_42 , V_57 ) ;
return 0 ;
}
if ( V_57 > V_64 ) {
F_10 ( & V_2 -> V_6 ,
L_43 ) ;
return 0 ;
}
V_36 . V_57 = V_57 ;
if ( ! F_43 ( V_3 , V_69 , & V_62 ) ) {
F_10 ( & V_2 -> V_6 , L_44 ) ;
return 0 ;
}
V_62 &= ~ F_48 ( 8 ) ;
if ( ! F_40 ( V_3 , V_69 , V_62 ) ) {
F_10 ( & V_2 -> V_6 , L_45 ) ;
return 0 ;
}
if ( V_36 . V_44 ) {
T_2 V_62 ;
int V_7 , V_50 ;
V_7 = F_43 ( V_3 , V_70 , & V_62 ) ;
if ( ! V_7 ) {
F_10 ( & V_2 -> V_6 , L_46 ,
V_70 ) ;
return 0 ;
}
V_62 |= F_48 ( 8 ) ;
V_7 = F_40 ( V_3 , V_70 , V_62 ) ;
if ( ! V_7 ) {
F_10 ( & V_2 -> V_6 , L_47 ,
V_70 ) ;
return 0 ;
}
V_7 = F_43 ( V_3 , V_71 , & V_62 ) ;
if ( ! V_7 ) {
F_10 ( & V_2 -> V_6 , L_46 ,
V_71 ) ;
return 0 ;
}
for ( V_50 = 0 ; ( V_50 < 5 ) && ( V_57 > 0 ) ; V_50 ++ , V_57 -- )
V_62 |= F_48 ( ( 27 + V_50 ) ) ;
V_7 = F_40 ( V_3 , V_71 , V_62 ) ;
if ( ! V_7 ) {
F_10 ( & V_2 -> V_6 , L_47 ,
V_71 ) ;
return 0 ;
}
if ( V_57 ) {
V_7 = F_43 ( V_3 , V_72 , & V_62 ) ;
if ( ! V_7 ) {
F_10 ( & V_2 -> V_6 ,
L_46 ,
V_72 ) ;
return 0 ;
}
for ( V_50 = 0 ; ( V_50 < 3 ) && ( V_57 > 0 ) ; V_50 ++ , V_57 -- )
V_62 |= F_48 ( V_50 ) ;
V_7 = F_43 ( V_3 , V_72 , & V_62 ) ;
if ( ! V_7 ) {
F_10 ( & V_2 -> V_6 ,
L_47 ,
V_72 ) ;
return 0 ;
}
}
}
return 1 ;
}
