static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
F_3 ( F_4 ( V_2 ) ) ;
F_5 ( V_2 ) ;
}
static int F_6 ( struct V_3 * V_3 , T_1 * V_4 )
{
struct V_1 * V_2 = F_7 ( V_3 -> V_5 , struct V_1 , V_5 ) ;
int V_6 ;
T_2 V_7 ;
F_5 ( V_2 ) ;
V_2 -> V_8 = V_4 -> V_9 ;
if ( V_4 -> V_10 ) {
if ( V_4 -> V_11 ) {
F_8 ( V_2 , V_4 -> V_7 , V_4 -> V_12 , & V_6 ) ;
V_7 = F_9 ( V_2 , V_4 -> V_12 , & V_6 ) ;
V_4 -> V_7 = V_7 ;
} else {
F_8 ( V_2 , V_4 -> V_7 , V_4 -> V_12 , & V_6 ) ;
}
} else {
V_7 = F_9 ( V_2 , V_4 -> V_12 , & V_6 ) ;
V_4 -> V_7 = V_7 ;
}
F_2 ( V_2 ) ;
if ( V_6 )
F_10 ( & V_2 -> V_5 , L_1 , V_6 ) ;
return V_6 ;
}
static int F_11 ( struct V_3 * V_3 , T_3 * V_4 )
{
struct V_1 * V_2 = F_7 ( V_3 -> V_5 , struct V_1 , V_5 ) ;
int V_13 , V_6 ;
F_5 ( V_2 ) ;
V_2 -> V_8 = V_4 -> V_9 ;
V_2 -> V_14 = V_4 -> V_15 ;
if ( V_4 -> V_16 )
V_13 = V_4 -> V_17 * V_4 -> V_15 ;
else
V_13 = V_4 -> V_17 ;
if ( V_4 -> V_10 ) {
V_6 = F_12 ( V_2 , V_4 -> V_12 ,
( void * ) V_4 -> V_18 , V_13 ) ;
} else {
V_6 = F_13 ( V_2 , ( void * ) V_4 -> V_18 ,
V_4 -> V_12 , V_13 ) ;
}
F_2 ( V_2 ) ;
if ( V_6 )
F_10 ( & V_2 -> V_5 , L_2 , V_6 ) ;
return V_6 ;
}
static int F_14 ( struct V_1 * V_2 ,
const struct V_19 * V_20 )
{
struct V_3 * V_3 ;
int V_21 , V_6 ;
V_21 = - 1 ;
if ( F_15 ( V_22 ) ) {
V_21 = F_16 ( V_2 -> V_5 . V_23 , 0 ) ;
if ( V_21 < 0 )
V_21 = V_24 ;
}
F_17 ( & V_2 -> V_5 , L_3 ) ;
V_6 = F_18 ( & V_3 , & V_2 -> V_5 , V_25 , V_21 ,
& V_26 ) ;
if ( V_6 ) {
F_10 ( & V_2 -> V_5 , L_4 ) ;
return V_6 ;
}
F_19 ( V_2 , V_3 ) ;
V_3 -> V_5 = & V_2 -> V_5 ;
F_20 ( & V_2 -> V_5 , L_5 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_22 ( F_4 ( V_2 ) ) ;
}
static int F_23 ( struct V_3 * V_5 )
{
struct V_1 * V_2 = F_7 ( V_5 -> V_5 , struct V_1 , V_5 ) ;
int V_6 = 0 ;
F_5 ( V_2 ) ;
V_6 = F_24 ( V_2 , F_1 ) ;
F_2 ( V_2 ) ;
if ( V_6 < 0 ) {
F_10 ( & V_2 -> V_5 , L_6 , V_6 ) ;
V_6 = - V_27 ;
}
return V_6 ;
}
static void F_25 ( struct V_3 * V_5 )
{
struct V_1 * V_2 = F_7 ( V_5 -> V_5 , struct V_1 , V_5 ) ;
int V_6 ;
F_17 ( & V_2 -> V_5 , L_7 ) ;
F_5 ( V_2 ) ;
V_6 = F_26 ( V_2 ) ;
if ( V_6 < 0 )
F_10 ( & V_2 -> V_5 , L_8 , V_6 ) ;
F_2 ( V_2 ) ;
F_20 ( & V_2 -> V_5 , L_9 ) ;
}
static int F_27 ( void )
{
return 1 ;
}
static int F_28 ( struct V_3 * V_3 , T_4 V_28 )
{
struct V_1 * V_2 = F_29 ( V_3 -> V_5 ) ;
T_1 V_4 ;
int V_6 ;
V_4 . V_10 = 1 ;
V_4 . V_9 = 0 ;
V_4 . V_11 = 0 ;
V_4 . V_12 = 0x10c ;
V_4 . V_7 = ( T_2 ) V_28 ;
V_6 = F_6 ( V_3 , & V_4 ) ;
if ( V_6 ) {
F_10 ( & V_2 -> V_5 , L_10 ) ;
goto V_29;
}
V_4 . V_12 = 0x10d ;
V_4 . V_7 = ( T_2 ) ( V_28 >> 8 ) ;
V_6 = F_6 ( V_3 , & V_4 ) ;
if ( V_6 ) {
F_10 ( & V_2 -> V_5 , L_11 ) ;
goto V_29;
}
V_4 . V_12 = 0x10e ;
V_4 . V_7 = ( T_2 ) ( V_28 >> 16 ) ;
V_6 = F_6 ( V_3 , & V_4 ) ;
if ( V_6 ) {
F_10 ( & V_2 -> V_5 , L_12 ) ;
goto V_29;
}
return 1 ;
V_29:
return 0 ;
}
static int F_30 ( struct V_3 * V_3 , T_4 V_15 )
{
struct V_1 * V_2 = F_29 ( V_3 -> V_5 ) ;
T_1 V_4 ;
int V_6 ;
V_4 . V_10 = 1 ;
V_4 . V_9 = 0 ;
V_4 . V_11 = 0 ;
V_4 . V_12 = 0x10 ;
V_4 . V_7 = ( T_2 ) V_15 ;
V_6 = F_6 ( V_3 , & V_4 ) ;
if ( V_6 ) {
F_10 ( & V_2 -> V_5 , L_13 ) ;
goto V_29;
}
V_4 . V_12 = 0x11 ;
V_4 . V_7 = ( T_2 ) ( V_15 >> 8 ) ;
V_6 = F_6 ( V_3 , & V_4 ) ;
if ( V_6 ) {
F_10 ( & V_2 -> V_5 , L_14 ) ;
goto V_29;
}
return 1 ;
V_29:
return 0 ;
}
static int F_31 ( struct V_3 * V_3 , T_4 V_15 )
{
struct V_1 * V_2 = F_29 ( V_3 -> V_5 ) ;
T_1 V_4 ;
int V_6 ;
V_4 . V_10 = 1 ;
V_4 . V_9 = 0 ;
V_4 . V_11 = 0 ;
V_4 . V_12 = 0x110 ;
V_4 . V_7 = ( T_2 ) V_15 ;
V_6 = F_6 ( V_3 , & V_4 ) ;
if ( V_6 ) {
F_10 ( & V_2 -> V_5 , L_15 ) ;
goto V_29;
}
V_4 . V_12 = 0x111 ;
V_4 . V_7 = ( T_2 ) ( V_15 >> 8 ) ;
V_6 = F_6 ( V_3 , & V_4 ) ;
if ( V_6 ) {
F_10 ( & V_2 -> V_5 , L_16 ) ;
goto V_29;
}
return 1 ;
V_29:
return 0 ;
}
static int F_32 ( struct V_3 * V_3 , T_4 V_30 , T_4 V_7 )
{
struct V_1 * V_2 = F_29 ( V_3 -> V_5 ) ;
int V_6 ;
V_7 = F_33 ( V_7 ) ;
if ( ( V_30 >= 0xf0 ) && ( V_30 <= 0xff ) ) {
T_1 V_4 ;
V_4 . V_10 = 1 ;
V_4 . V_9 = 0 ;
V_4 . V_11 = 0 ;
V_4 . V_12 = V_30 ;
V_4 . V_7 = V_7 ;
V_6 = F_6 ( V_3 , & V_4 ) ;
if ( V_6 ) {
F_10 ( & V_2 -> V_5 ,
L_17 , V_30 ) ;
goto V_29;
}
} else {
T_3 V_4 ;
if ( ! F_28 ( V_3 , V_30 ) )
goto V_29;
V_4 . V_10 = 1 ;
V_4 . V_9 = 0 ;
V_4 . V_12 = 0x10f ;
V_4 . V_16 = 0 ;
V_4 . V_31 = 1 ;
V_4 . V_17 = 4 ;
V_4 . V_18 = ( T_2 * ) & V_7 ;
V_4 . V_15 = V_32 . V_15 ;
V_6 = F_11 ( V_3 , & V_4 ) ;
if ( V_6 ) {
F_10 ( & V_2 -> V_5 ,
L_18 , V_30 ) ;
goto V_29;
}
}
return 1 ;
V_29:
return 0 ;
}
static int F_34 ( struct V_3 * V_3 , T_4 V_30 , T_2 * V_33 , T_4 V_13 )
{
struct V_1 * V_2 = F_29 ( V_3 -> V_5 ) ;
T_4 V_15 = V_32 . V_15 ;
T_3 V_4 ;
int V_34 , V_35 , V_6 ;
V_4 . V_10 = 1 ;
if ( V_30 > 0 ) {
if ( V_13 & 0x3 ) {
V_13 += 4 ;
V_13 &= ~ 0x3 ;
}
V_4 . V_9 = 0 ;
V_4 . V_12 = 0x10f ;
} else {
if ( V_13 & 0x3 ) {
V_13 += 4 ;
V_13 &= ~ 0x3 ;
}
V_4 . V_9 = 1 ;
V_4 . V_12 = 0 ;
}
V_34 = V_13 / V_15 ;
V_35 = V_13 % V_15 ;
if ( V_34 > 0 ) {
V_4 . V_16 = 1 ;
V_4 . V_31 = 1 ;
V_4 . V_17 = V_34 ;
V_4 . V_18 = V_33 ;
V_4 . V_15 = V_15 ;
if ( V_30 > 0 ) {
if ( ! F_28 ( V_3 , V_30 ) )
goto V_29;
}
V_6 = F_11 ( V_3 , & V_4 ) ;
if ( V_6 ) {
F_10 ( & V_2 -> V_5 ,
L_19 , V_30 ) ;
goto V_29;
}
if ( V_30 > 0 )
V_30 += V_34 * V_15 ;
V_33 += V_34 * V_15 ;
}
if ( V_35 > 0 ) {
V_4 . V_16 = 0 ;
V_4 . V_31 = 1 ;
V_4 . V_17 = V_35 ;
V_4 . V_18 = V_33 ;
V_4 . V_15 = V_15 ;
if ( V_30 > 0 ) {
if ( ! F_28 ( V_3 , V_30 ) )
goto V_29;
}
V_6 = F_11 ( V_3 , & V_4 ) ;
if ( V_6 ) {
F_10 ( & V_2 -> V_5 ,
L_20 , V_30 ) ;
goto V_29;
}
}
return 1 ;
V_29:
return 0 ;
}
static int F_35 ( struct V_3 * V_3 , T_4 V_30 , T_4 * V_7 )
{
struct V_1 * V_2 = F_29 ( V_3 -> V_5 ) ;
int V_6 ;
if ( ( V_30 >= 0xf0 ) && ( V_30 <= 0xff ) ) {
T_1 V_4 ;
V_4 . V_10 = 0 ;
V_4 . V_9 = 0 ;
V_4 . V_11 = 0 ;
V_4 . V_12 = V_30 ;
V_6 = F_6 ( V_3 , & V_4 ) ;
if ( V_6 ) {
F_10 ( & V_2 -> V_5 ,
L_17 , V_30 ) ;
goto V_29;
}
* V_7 = V_4 . V_7 ;
} else {
T_3 V_4 ;
if ( ! F_28 ( V_3 , V_30 ) )
goto V_29;
V_4 . V_10 = 0 ;
V_4 . V_9 = 0 ;
V_4 . V_12 = 0x10f ;
V_4 . V_16 = 0 ;
V_4 . V_31 = 1 ;
V_4 . V_17 = 4 ;
V_4 . V_18 = ( T_2 * ) V_7 ;
V_4 . V_15 = V_32 . V_15 ;
V_6 = F_11 ( V_3 , & V_4 ) ;
if ( V_6 ) {
F_10 ( & V_2 -> V_5 ,
L_21 , V_30 ) ;
goto V_29;
}
}
* V_7 = F_33 ( * V_7 ) ;
return 1 ;
V_29:
return 0 ;
}
static int F_36 ( struct V_3 * V_3 , T_4 V_30 , T_2 * V_33 , T_4 V_13 )
{
struct V_1 * V_2 = F_29 ( V_3 -> V_5 ) ;
T_4 V_15 = V_32 . V_15 ;
T_3 V_4 ;
int V_34 , V_35 , V_6 ;
V_4 . V_10 = 0 ;
if ( V_30 > 0 ) {
if ( V_13 & 0x3 ) {
V_13 += 4 ;
V_13 &= ~ 0x3 ;
}
V_4 . V_9 = 0 ;
V_4 . V_12 = 0x10f ;
} else {
if ( V_13 & 0x3 ) {
V_13 += 4 ;
V_13 &= ~ 0x3 ;
}
V_4 . V_9 = 1 ;
V_4 . V_12 = 0 ;
}
V_34 = V_13 / V_15 ;
V_35 = V_13 % V_15 ;
if ( V_34 > 0 ) {
V_4 . V_16 = 1 ;
V_4 . V_31 = 1 ;
V_4 . V_17 = V_34 ;
V_4 . V_18 = V_33 ;
V_4 . V_15 = V_15 ;
if ( V_30 > 0 ) {
if ( ! F_28 ( V_3 , V_30 ) )
goto V_29;
}
V_6 = F_11 ( V_3 , & V_4 ) ;
if ( V_6 ) {
F_10 ( & V_2 -> V_5 ,
L_22 , V_30 ) ;
goto V_29;
}
if ( V_30 > 0 )
V_30 += V_34 * V_15 ;
V_33 += V_34 * V_15 ;
}
if ( V_35 > 0 ) {
V_4 . V_16 = 0 ;
V_4 . V_31 = 1 ;
V_4 . V_17 = V_35 ;
V_4 . V_18 = V_33 ;
V_4 . V_15 = V_15 ;
if ( V_30 > 0 ) {
if ( ! F_28 ( V_3 , V_30 ) )
goto V_29;
}
V_6 = F_11 ( V_3 , & V_4 ) ;
if ( V_6 ) {
F_10 ( & V_2 -> V_5 ,
L_23 , V_30 ) ;
goto V_29;
}
}
return 1 ;
V_29:
return 0 ;
}
static int F_37 ( struct V_3 * V_3 )
{
return 1 ;
}
static int F_38 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = F_29 ( V_3 -> V_5 ) ;
T_1 V_4 ;
int V_36 , V_6 ;
T_4 V_37 ;
memset ( & V_32 , 0 , sizeof( V_38 ) ) ;
V_32 . V_39 = ( V_3 -> V_40 ) ;
if ( ! F_27 () ) {
F_10 ( & V_2 -> V_5 , L_24 ) ;
return 0 ;
} else {
return 0 ;
}
V_4 . V_10 = 1 ;
V_4 . V_9 = 0 ;
V_4 . V_11 = 1 ;
V_4 . V_12 = 0x100 ;
V_4 . V_7 = 0x80 ;
V_6 = F_6 ( V_3 , & V_4 ) ;
if ( V_6 ) {
F_10 ( & V_2 -> V_5 , L_25 ) ;
goto V_29;
}
if ( ! F_30 ( V_3 , V_41 ) ) {
F_10 ( & V_2 -> V_5 , L_26 ) ;
goto V_29;
}
V_32 . V_15 = V_41 ;
V_4 . V_10 = 1 ;
V_4 . V_9 = 0 ;
V_4 . V_11 = 1 ;
V_4 . V_12 = 0x2 ;
V_4 . V_7 = 0x2 ;
V_6 = F_6 ( V_3 , & V_4 ) ;
if ( V_6 ) {
F_10 ( & V_2 -> V_5 ,
L_27 ) ;
goto V_29;
}
V_4 . V_10 = 0 ;
V_4 . V_9 = 0 ;
V_4 . V_11 = 0 ;
V_4 . V_12 = 0x3 ;
V_36 = 3 ;
do {
V_4 . V_7 = 0 ;
V_6 = F_6 ( V_3 , & V_4 ) ;
if ( V_6 ) {
F_10 ( & V_2 -> V_5 ,
L_28 ) ;
goto V_29;
}
if ( V_4 . V_7 == 0x2 )
break;
} while ( V_36 -- );
if ( V_36 <= 0 ) {
F_10 ( & V_2 -> V_5 , L_29 ) ;
goto V_29;
}
if ( ! F_31 ( V_3 , V_41 ) ) {
F_10 ( & V_2 -> V_5 , L_30 ) ;
goto V_29;
}
V_4 . V_10 = 1 ;
V_4 . V_9 = 0 ;
V_4 . V_11 = 1 ;
V_4 . V_12 = 0x4 ;
V_4 . V_7 = 0x3 ;
V_6 = F_6 ( V_3 , & V_4 ) ;
if ( V_6 ) {
F_10 ( & V_2 -> V_5 , L_31 ) ;
goto V_29;
}
if ( ! F_35 ( V_3 , 0x1000 , & V_37 ) ) {
F_10 ( & V_2 -> V_5 , L_32 ) ;
goto V_29;
}
F_10 ( & V_2 -> V_5 , L_33 , V_37 ) ;
if ( ( V_37 & 0xfff ) > 0x2a0 )
V_32 . V_42 = 1 ;
else
V_32 . V_42 = 0 ;
F_20 ( & V_2 -> V_5 , L_34 , V_32 . V_42 ) ;
return 1 ;
V_29:
return 0 ;
}
static int F_39 ( struct V_3 * V_3 , T_4 * V_13 )
{
T_4 V_43 ;
T_1 V_4 ;
V_4 . V_10 = 0 ;
V_4 . V_9 = 0 ;
V_4 . V_11 = 0 ;
V_4 . V_12 = 0xf2 ;
V_4 . V_7 = 0 ;
F_6 ( V_3 , & V_4 ) ;
V_43 = V_4 . V_7 ;
V_4 . V_12 = 0xf3 ;
V_4 . V_7 = 0 ;
F_6 ( V_3 , & V_4 ) ;
V_43 |= ( V_4 . V_7 << 8 ) ;
* V_13 = V_43 ;
return 1 ;
}
static int F_40 ( struct V_3 * V_3 , T_4 * V_44 )
{
struct V_1 * V_2 = F_29 ( V_3 -> V_5 ) ;
T_4 V_43 ;
T_1 V_4 ;
F_39 ( V_3 , & V_43 ) ;
if ( ! V_32 . V_39 ) {
int V_45 ;
V_4 . V_9 = 1 ;
V_4 . V_12 = 0x04 ;
V_4 . V_7 = 0 ;
F_6 ( V_3 , & V_4 ) ;
if ( V_4 . V_7 & F_41 ( 0 ) )
V_43 |= V_46 ;
if ( V_4 . V_7 & F_41 ( 2 ) )
V_43 |= V_47 ;
if ( V_4 . V_7 & F_41 ( 3 ) )
V_43 |= V_48 ;
if ( V_4 . V_7 & F_41 ( 4 ) )
V_43 |= V_49 ;
if ( V_4 . V_7 & F_41 ( 5 ) )
V_43 |= V_50 ;
if ( V_4 . V_7 & F_41 ( 6 ) )
V_43 |= V_51 ;
for ( V_45 = V_32 . V_52 ; V_45 < V_53 ; V_45 ++ ) {
if ( ( V_43 >> ( V_54 + V_45 ) ) & 0x1 ) {
F_10 ( & V_2 -> V_5 ,
L_35 ,
V_43 , V_4 . V_7 ) ;
break;
}
}
} else {
T_4 V_55 ;
V_4 . V_10 = 0 ;
V_4 . V_9 = 0 ;
V_4 . V_11 = 0 ;
V_4 . V_12 = 0xf7 ;
V_4 . V_7 = 0 ;
F_6 ( V_3 , & V_4 ) ;
V_55 = V_4 . V_7 & 0x1f ;
V_43 |= ( ( V_55 >> 0 ) << V_54 ) ;
}
* V_44 = V_43 ;
return 1 ;
}
static int F_42 ( struct V_3 * V_3 , T_4 V_56 )
{
struct V_1 * V_2 = F_29 ( V_3 -> V_5 ) ;
int V_6 ;
if ( V_32 . V_42 ) {
T_4 V_57 ;
if ( V_32 . V_39 ) {
T_4 V_58 ;
V_58 = V_56 & ( F_41 ( V_59 ) - 1 ) ;
V_57 = V_58 ;
} else {
V_57 = 0 ;
}
if ( ( V_56 & V_60 ) == V_60 )
V_57 |= F_41 ( 5 ) ;
if ( ( V_56 & V_61 ) == V_61 )
V_57 |= F_41 ( 6 ) ;
if ( ( V_56 & V_62 ) == V_62 )
V_57 |= F_41 ( 7 ) ;
if ( V_57 ) {
T_1 V_4 ;
V_4 . V_10 = 1 ;
V_4 . V_9 = 0 ;
V_4 . V_11 = 0 ;
V_4 . V_12 = 0xf8 ;
V_4 . V_7 = V_57 ;
V_6 = F_6 ( V_3 , & V_4 ) ;
if ( V_6 ) {
F_10 ( & V_2 -> V_5 ,
L_36 ,
__LINE__ ) ;
goto V_29;
}
}
} else {
if ( V_32 . V_39 ) {
T_4 V_58 ;
V_58 = V_56 & ( F_41 ( V_53 ) - 1 ) ;
if ( V_58 ) {
int V_45 ;
V_6 = 1 ;
for ( V_45 = 0 ; V_45 < V_32 . V_52 ; V_45 ++ ) {
if ( V_58 & 1 ) {
T_1 V_4 ;
V_4 . V_10 = 1 ;
V_4 . V_9 = 0 ;
V_4 . V_11 = 0 ;
V_4 . V_12 = 0xf8 ;
V_4 . V_7 = F_41 ( V_45 ) ;
V_6 = F_6 ( V_3 , & V_4 ) ;
if ( V_6 ) {
F_10 ( & V_2 -> V_5 ,
L_36 ,
__LINE__ ) ;
goto V_29;
}
}
if ( ! V_6 )
break;
V_58 >>= 1 ;
}
if ( ! V_6 )
goto V_29;
for ( V_45 = V_32 . V_52 ; V_45 < V_53 ; V_45 ++ ) {
if ( V_58 & 1 )
F_10 ( & V_2 -> V_5 ,
L_37 ,
V_45 ) ;
V_58 >>= 1 ;
}
}
}
{
T_4 V_63 ;
V_63 = 0 ;
if ( ( V_56 & V_60 ) == V_60 )
V_63 |= F_41 ( 0 ) ;
if ( ( V_56 & V_61 ) == V_61 )
V_63 |= F_41 ( 1 ) ;
if ( ( V_56 & V_62 ) == V_62 )
V_63 |= F_41 ( 2 ) ;
if ( V_63 ) {
T_1 V_4 ;
V_4 . V_10 = 1 ;
V_4 . V_9 = 0 ;
V_4 . V_11 = 0 ;
V_4 . V_12 = 0xf6 ;
V_4 . V_7 = V_63 ;
V_6 = F_6 ( V_3 , & V_4 ) ;
if ( V_6 ) {
F_10 ( & V_2 -> V_5 ,
L_38 ,
__LINE__ ) ;
goto V_29;
}
}
}
}
return 1 ;
V_29:
return 0 ;
}
static int F_43 ( struct V_3 * V_3 , int V_52 )
{
struct V_1 * V_2 = F_29 ( V_3 -> V_5 ) ;
T_4 V_57 ;
if ( V_52 > V_53 ) {
F_10 ( & V_2 -> V_5 , L_39 , V_52 ) ;
return 0 ;
}
if ( V_52 > V_59 ) {
F_10 ( & V_2 -> V_5 ,
L_40 ) ;
return 0 ;
}
V_32 . V_52 = V_52 ;
if ( ! F_35 ( V_3 , V_64 , & V_57 ) ) {
F_10 ( & V_2 -> V_5 , L_41 ) ;
return 0 ;
}
V_57 &= ~ F_41 ( 8 ) ;
if ( ! F_32 ( V_3 , V_64 , V_57 ) ) {
F_10 ( & V_2 -> V_5 , L_42 ) ;
return 0 ;
}
if ( V_32 . V_39 ) {
T_4 V_57 ;
int V_6 , V_45 ;
V_6 = F_35 ( V_3 , V_65 , & V_57 ) ;
if ( ! V_6 ) {
F_10 ( & V_2 -> V_5 , L_43 ,
V_65 ) ;
return 0 ;
}
V_57 |= F_41 ( 8 ) ;
V_6 = F_32 ( V_3 , V_65 , V_57 ) ;
if ( ! V_6 ) {
F_10 ( & V_2 -> V_5 , L_44 ,
V_65 ) ;
return 0 ;
}
V_6 = F_35 ( V_3 , V_66 , & V_57 ) ;
if ( ! V_6 ) {
F_10 ( & V_2 -> V_5 , L_43 ,
V_66 ) ;
return 0 ;
}
for ( V_45 = 0 ; ( V_45 < 5 ) && ( V_52 > 0 ) ; V_45 ++ , V_52 -- )
V_57 |= F_41 ( ( 27 + V_45 ) ) ;
V_6 = F_32 ( V_3 , V_66 , V_57 ) ;
if ( ! V_6 ) {
F_10 ( & V_2 -> V_5 , L_44 ,
V_66 ) ;
return 0 ;
}
if ( V_52 ) {
V_6 = F_35 ( V_3 , V_67 , & V_57 ) ;
if ( ! V_6 ) {
F_10 ( & V_2 -> V_5 ,
L_43 ,
V_67 ) ;
return 0 ;
}
for ( V_45 = 0 ; ( V_45 < 3 ) && ( V_52 > 0 ) ; V_45 ++ , V_52 -- )
V_57 |= F_41 ( V_45 ) ;
V_6 = F_35 ( V_3 , V_67 , & V_57 ) ;
if ( ! V_6 ) {
F_10 ( & V_2 -> V_5 ,
L_44 ,
V_67 ) ;
return 0 ;
}
}
}
return 1 ;
}
