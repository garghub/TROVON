static int T_1 F_1 ( char * V_1 )
{
V_2 = 1 ;
F_2 ( L_1 ) ;
return 1 ;
}
static inline int F_3 ( struct V_3 * V_4 , T_2 V_5 )
{
switch ( F_4 ( V_5 ) ) {
case V_6 :
if ( F_5 ( V_5 ) )
V_4 -> V_4 [ F_5 ( V_5 ) ] =
( V_7 ) V_4 -> V_4 [ F_6 ( V_5 ) ] +
( V_7 ) F_7 ( V_5 ) ;
return 0 ;
case V_8 :
if ( F_8 ( V_9 ) )
break;
if ( F_5 ( V_5 ) )
V_4 -> V_4 [ F_5 ( V_5 ) ] =
( V_10 ) V_4 -> V_4 [ F_6 ( V_5 ) ] +
( V_10 ) F_7 ( V_5 ) ;
return 0 ;
case V_11 :
case V_12 :
case V_13 :
case V_14 :
return - V_15 ;
case V_16 :
switch ( F_9 ( V_5 ) ) {
case V_17 :
if ( F_10 ( V_5 ) )
V_4 -> V_4 [ F_10 ( V_5 ) ] =
V_4 -> V_4 [ F_6 ( V_5 ) ] |
V_4 -> V_4 [ F_5 ( V_5 ) ] ;
return 0 ;
case V_18 :
if ( F_6 ( V_5 ) )
break;
if ( F_10 ( V_5 ) )
V_4 -> V_4 [ F_10 ( V_5 ) ] =
( V_7 ) ( ( ( T_2 ) V_4 -> V_4 [ F_5 ( V_5 ) ] ) <<
F_11 ( V_5 ) ) ;
return 0 ;
case V_19 :
if ( F_6 ( V_5 ) )
break;
if ( F_10 ( V_5 ) )
V_4 -> V_4 [ F_10 ( V_5 ) ] =
( V_7 ) ( ( ( T_2 ) V_4 -> V_4 [ F_5 ( V_5 ) ] ) >>
F_11 ( V_5 ) ) ;
return 0 ;
case V_20 :
if ( F_11 ( V_5 ) )
break;
if ( F_10 ( V_5 ) )
V_4 -> V_4 [ F_10 ( V_5 ) ] =
( V_7 ) ( ( T_2 ) V_4 -> V_4 [ F_6 ( V_5 ) ] +
( T_2 ) V_4 -> V_4 [ F_5 ( V_5 ) ] ) ;
return 0 ;
case V_21 :
if ( F_11 ( V_5 ) )
break;
if ( F_10 ( V_5 ) )
V_4 -> V_4 [ F_10 ( V_5 ) ] =
( V_7 ) ( ( T_2 ) V_4 -> V_4 [ F_6 ( V_5 ) ] -
( T_2 ) V_4 -> V_4 [ F_5 ( V_5 ) ] ) ;
return 0 ;
case V_22 :
if ( F_8 ( V_9 ) || F_6 ( V_5 ) )
break;
if ( F_10 ( V_5 ) )
V_4 -> V_4 [ F_10 ( V_5 ) ] =
( V_10 ) ( ( ( V_23 ) V_4 -> V_4 [ F_5 ( V_5 ) ] ) <<
F_11 ( V_5 ) ) ;
return 0 ;
case V_24 :
if ( F_8 ( V_9 ) || F_6 ( V_5 ) )
break;
if ( F_10 ( V_5 ) )
V_4 -> V_4 [ F_10 ( V_5 ) ] =
( V_10 ) ( ( ( V_23 ) V_4 -> V_4 [ F_5 ( V_5 ) ] ) >>
F_11 ( V_5 ) ) ;
return 0 ;
case V_25 :
if ( F_8 ( V_9 ) || F_11 ( V_5 ) )
break;
if ( F_10 ( V_5 ) )
V_4 -> V_4 [ F_10 ( V_5 ) ] =
( V_23 ) V_4 -> V_4 [ F_6 ( V_5 ) ] +
( V_23 ) V_4 -> V_4 [ F_5 ( V_5 ) ] ;
return 0 ;
case V_26 :
if ( F_8 ( V_9 ) || F_11 ( V_5 ) )
break;
if ( F_10 ( V_5 ) )
V_4 -> V_4 [ F_10 ( V_5 ) ] =
( V_10 ) ( ( V_23 ) V_4 -> V_4 [ F_6 ( V_5 ) ] -
( V_23 ) V_4 -> V_4 [ F_5 ( V_5 ) ] ) ;
return 0 ;
}
break;
default:
F_12 ( L_2 ,
V_5 , F_4 ( V_5 ) ) ;
}
return V_27 ;
}
static int F_13 ( struct V_3 * V_4 , T_2 V_5 )
{
T_2 V_28 ;
T_2 V_29 ;
V_28 = V_30 -> V_31 . V_32 . V_33 ;
V_29 = V_34 [ F_5 ( V_5 ) >> 2 ] ;
if ( ( ( V_28 & V_29 ) == 0 ) && F_10 ( V_5 ) )
V_4 -> V_4 [ F_10 ( V_5 ) ] = V_4 -> V_4 [ F_6 ( V_5 ) ] ;
F_14 ( V_35 ) ;
return 0 ;
}
static int F_15 ( struct V_3 * V_4 , T_2 V_5 )
{
T_2 V_28 ;
T_2 V_29 ;
V_28 = V_30 -> V_31 . V_32 . V_33 ;
V_29 = V_34 [ F_5 ( V_5 ) >> 2 ] ;
if ( ( ( V_28 & V_29 ) != 0 ) && F_10 ( V_5 ) )
V_4 -> V_4 [ F_10 ( V_5 ) ] = V_4 -> V_4 [ F_6 ( V_5 ) ] ;
F_14 ( V_35 ) ;
return 0 ;
}
static int F_16 ( struct V_3 * V_4 , T_2 V_5 )
{
int V_36 ;
unsigned long V_37 , V_38 , V_39 ;
T_2 V_40 ;
if ( F_17 ( V_4 ) )
return V_27 ;
V_39 = V_4 -> V_41 ;
V_4 -> V_41 -= 4 ;
V_38 = V_4 -> V_41 ;
V_36 = F_18 ( V_4 ) ;
if ( V_36 < 0 )
return V_42 ;
V_37 = V_4 -> V_41 ;
V_36 = F_19 ( V_40 , ( T_2 V_43 * ) V_39 ) ;
if ( V_36 )
return V_44 ;
F_20 ( V_45 ) ;
if ( V_40 ) {
V_36 = F_3 ( V_4 , V_40 ) ;
if ( V_36 > 0 ) {
V_4 -> V_41 = V_39 ;
V_36 = F_21 ( V_4 , V_40 , V_37 ) ;
if ( V_36 == V_27 )
V_36 = V_42 ;
F_14 ( V_46 ) ;
}
}
return V_36 ;
}
static int F_22 ( struct V_3 * V_4 , T_2 V_5 )
{
if ( ( ( V_4 -> V_4 [ F_5 ( V_5 ) ] ) == 0 ) && F_10 ( V_5 ) )
V_4 -> V_4 [ F_10 ( V_5 ) ] = V_4 -> V_4 [ F_6 ( V_5 ) ] ;
F_14 ( V_35 ) ;
return 0 ;
}
static int F_23 ( struct V_3 * V_4 , T_2 V_5 )
{
if ( ( ( V_4 -> V_4 [ F_5 ( V_5 ) ] ) != 0 ) && F_10 ( V_5 ) )
V_4 -> V_4 [ F_10 ( V_5 ) ] = V_4 -> V_4 [ F_6 ( V_5 ) ] ;
F_14 ( V_35 ) ;
return 0 ;
}
static int F_24 ( struct V_3 * V_4 , T_2 V_5 )
{
if ( F_10 ( V_5 ) )
V_4 -> V_4 [ F_10 ( V_5 ) ] = V_4 -> V_47 ;
F_14 ( V_48 ) ;
return 0 ;
}
static int F_25 ( struct V_3 * V_4 , T_2 V_5 )
{
V_4 -> V_47 = V_4 -> V_4 [ F_6 ( V_5 ) ] ;
F_14 ( V_48 ) ;
return 0 ;
}
static int F_26 ( struct V_3 * V_4 , T_2 V_5 )
{
if ( F_10 ( V_5 ) )
V_4 -> V_4 [ F_10 ( V_5 ) ] = V_4 -> V_49 ;
F_14 ( V_48 ) ;
return 0 ;
}
static int F_27 ( struct V_3 * V_4 , T_2 V_5 )
{
V_4 -> V_49 = V_4 -> V_4 [ F_6 ( V_5 ) ] ;
F_14 ( V_48 ) ;
return 0 ;
}
static int F_28 ( struct V_3 * V_4 , T_2 V_5 )
{
V_10 V_50 ;
V_7 V_51 , V_52 ;
V_51 = V_4 -> V_4 [ F_5 ( V_5 ) ] ;
V_52 = V_4 -> V_4 [ F_6 ( V_5 ) ] ;
V_50 = ( V_10 ) V_51 * ( V_10 ) V_52 ;
V_52 = V_50 ;
V_4 -> V_49 = ( V_10 ) V_52 ;
V_51 = V_50 >> 32 ;
V_50 = ( V_10 ) V_51 ;
V_4 -> V_47 = V_50 ;
F_14 ( V_53 ) ;
return 0 ;
}
static int F_29 ( struct V_3 * V_4 , T_2 V_5 )
{
V_23 V_50 ;
T_2 V_51 , V_52 ;
V_51 = V_4 -> V_4 [ F_5 ( V_5 ) ] ;
V_52 = V_4 -> V_4 [ F_6 ( V_5 ) ] ;
V_50 = ( V_23 ) V_51 * ( V_23 ) V_52 ;
V_51 = V_50 ;
V_4 -> V_49 = ( V_10 ) V_51 ;
V_4 -> V_47 = ( V_10 ) ( V_50 >> 32 ) ;
F_14 ( V_53 ) ;
return 0 ;
}
static int F_30 ( struct V_3 * V_4 , T_2 V_5 )
{
V_7 V_51 , V_52 ;
V_51 = V_4 -> V_4 [ F_5 ( V_5 ) ] ;
V_52 = V_4 -> V_4 [ F_6 ( V_5 ) ] ;
V_4 -> V_49 = ( V_10 ) ( V_52 / V_51 ) ;
V_4 -> V_47 = ( V_10 ) ( V_52 % V_51 ) ;
F_14 ( V_54 ) ;
return 0 ;
}
static int F_31 ( struct V_3 * V_4 , T_2 V_5 )
{
T_2 V_51 , V_52 ;
V_51 = V_4 -> V_4 [ F_5 ( V_5 ) ] ;
V_52 = V_4 -> V_4 [ F_6 ( V_5 ) ] ;
V_4 -> V_49 = ( V_10 ) ( V_52 / V_51 ) ;
V_4 -> V_47 = ( V_10 ) ( V_52 % V_51 ) ;
F_14 ( V_54 ) ;
return 0 ;
}
static int F_32 ( struct V_3 * V_4 , T_2 V_5 )
{
V_10 V_50 ;
V_10 V_51 , V_52 ;
if ( F_8 ( V_9 ) )
return V_27 ;
V_51 = V_4 -> V_4 [ F_5 ( V_5 ) ] ;
V_52 = V_4 -> V_4 [ F_6 ( V_5 ) ] ;
V_50 = V_51 * V_52 ;
V_4 -> V_49 = V_50 ;
__asm__ __volatile__(
"dmuh %0, %1, %2\t\n"
: "=r"(res)
: "r"(rt), "r"(rs));
V_4 -> V_47 = V_50 ;
F_14 ( V_53 ) ;
return 0 ;
}
static int F_33 ( struct V_3 * V_4 , T_2 V_5 )
{
V_23 V_50 ;
V_23 V_51 , V_52 ;
if ( F_8 ( V_9 ) )
return V_27 ;
V_51 = V_4 -> V_4 [ F_5 ( V_5 ) ] ;
V_52 = V_4 -> V_4 [ F_6 ( V_5 ) ] ;
V_50 = V_51 * V_52 ;
V_4 -> V_49 = V_50 ;
__asm__ __volatile__(
"dmuhu %0, %1, %2\t\n"
: "=r"(res)
: "r"(rt), "r"(rs));
V_4 -> V_47 = V_50 ;
F_14 ( V_53 ) ;
return 0 ;
}
static int F_34 ( struct V_3 * V_4 , T_2 V_5 )
{
V_10 V_51 , V_52 ;
if ( F_8 ( V_9 ) )
return V_27 ;
V_51 = V_4 -> V_4 [ F_5 ( V_5 ) ] ;
V_52 = V_4 -> V_4 [ F_6 ( V_5 ) ] ;
V_4 -> V_49 = V_52 / V_51 ;
V_4 -> V_47 = V_52 % V_51 ;
F_14 ( V_54 ) ;
return 0 ;
}
static int F_35 ( struct V_3 * V_4 , T_2 V_5 )
{
V_23 V_51 , V_52 ;
if ( F_8 ( V_9 ) )
return V_27 ;
V_51 = V_4 -> V_4 [ F_5 ( V_5 ) ] ;
V_52 = V_4 -> V_4 [ F_6 ( V_5 ) ] ;
V_4 -> V_49 = V_52 / V_51 ;
V_4 -> V_47 = V_52 % V_51 ;
F_14 ( V_54 ) ;
return 0 ;
}
static int F_36 ( struct V_3 * V_4 , T_2 V_5 )
{
V_10 V_50 ;
V_7 V_51 , V_52 ;
V_51 = V_4 -> V_4 [ F_5 ( V_5 ) ] ;
V_52 = V_4 -> V_4 [ F_6 ( V_5 ) ] ;
V_50 = ( V_10 ) V_51 * ( V_10 ) V_52 ;
V_51 = V_4 -> V_47 ;
V_52 = V_4 -> V_49 ;
V_50 += ( ( ( ( V_10 ) V_51 ) << 32 ) | ( T_2 ) V_52 ) ;
V_51 = V_50 ;
V_4 -> V_49 = ( V_10 ) V_51 ;
V_52 = V_50 >> 32 ;
V_4 -> V_47 = ( V_10 ) V_52 ;
F_14 ( V_55 ) ;
return 0 ;
}
static int F_37 ( struct V_3 * V_4 , T_2 V_5 )
{
V_23 V_50 ;
T_2 V_51 , V_52 ;
V_51 = V_4 -> V_4 [ F_5 ( V_5 ) ] ;
V_52 = V_4 -> V_4 [ F_6 ( V_5 ) ] ;
V_50 = ( V_23 ) V_51 * ( V_23 ) V_52 ;
V_51 = V_4 -> V_47 ;
V_52 = V_4 -> V_49 ;
V_50 += ( ( ( ( V_10 ) V_51 ) << 32 ) | ( T_2 ) V_52 ) ;
V_51 = V_50 ;
V_4 -> V_49 = ( V_10 ) V_51 ;
V_52 = V_50 >> 32 ;
V_4 -> V_47 = ( V_10 ) V_52 ;
F_14 ( V_55 ) ;
return 0 ;
}
static int F_38 ( struct V_3 * V_4 , T_2 V_5 )
{
V_10 V_50 ;
V_7 V_51 , V_52 ;
V_51 = V_4 -> V_4 [ F_5 ( V_5 ) ] ;
V_52 = V_4 -> V_4 [ F_6 ( V_5 ) ] ;
V_50 = ( V_10 ) V_51 * ( V_10 ) V_52 ;
V_51 = V_4 -> V_47 ;
V_52 = V_4 -> V_49 ;
V_50 = ( ( ( ( V_10 ) V_51 ) << 32 ) | ( T_2 ) V_52 ) - V_50 ;
V_51 = V_50 ;
V_4 -> V_49 = ( V_10 ) V_51 ;
V_52 = V_50 >> 32 ;
V_4 -> V_47 = ( V_10 ) V_52 ;
F_14 ( V_55 ) ;
return 0 ;
}
static int F_39 ( struct V_3 * V_4 , T_2 V_5 )
{
V_23 V_50 ;
T_2 V_51 , V_52 ;
V_51 = V_4 -> V_4 [ F_5 ( V_5 ) ] ;
V_52 = V_4 -> V_4 [ F_6 ( V_5 ) ] ;
V_50 = ( V_23 ) V_51 * ( V_23 ) V_52 ;
V_51 = V_4 -> V_47 ;
V_52 = V_4 -> V_49 ;
V_50 = ( ( ( ( V_10 ) V_51 ) << 32 ) | ( T_2 ) V_52 ) - V_50 ;
V_51 = V_50 ;
V_4 -> V_49 = ( V_10 ) V_51 ;
V_52 = V_50 >> 32 ;
V_4 -> V_47 = ( V_10 ) V_52 ;
F_14 ( V_55 ) ;
return 0 ;
}
static int F_40 ( struct V_3 * V_4 , T_2 V_5 )
{
V_10 V_50 ;
V_7 V_51 , V_52 ;
if ( ! F_10 ( V_5 ) )
return 0 ;
V_51 = V_4 -> V_4 [ F_5 ( V_5 ) ] ;
V_52 = V_4 -> V_4 [ F_6 ( V_5 ) ] ;
V_50 = ( V_10 ) V_51 * ( V_10 ) V_52 ;
V_52 = V_50 ;
V_4 -> V_4 [ F_10 ( V_5 ) ] = ( V_10 ) V_52 ;
F_14 ( V_53 ) ;
return 0 ;
}
static int F_41 ( struct V_3 * V_4 , T_2 V_5 )
{
T_2 V_50 ;
T_2 V_52 ;
if ( ! F_10 ( V_5 ) )
return 0 ;
V_52 = V_4 -> V_4 [ F_6 ( V_5 ) ] ;
__asm__ __volatile__("clz %0, %1" : "=r"(res) : "r"(rs));
V_4 -> V_4 [ F_10 ( V_5 ) ] = V_50 ;
F_14 ( V_56 ) ;
return 0 ;
}
static int F_42 ( struct V_3 * V_4 , T_2 V_5 )
{
T_2 V_50 ;
T_2 V_52 ;
if ( ! F_10 ( V_5 ) )
return 0 ;
V_52 = V_4 -> V_4 [ F_6 ( V_5 ) ] ;
__asm__ __volatile__("clo %0, %1" : "=r"(res) : "r"(rs));
V_4 -> V_4 [ F_10 ( V_5 ) ] = V_50 ;
F_14 ( V_56 ) ;
return 0 ;
}
static int F_43 ( struct V_3 * V_4 , T_2 V_5 )
{
V_23 V_50 ;
V_23 V_52 ;
if ( F_8 ( V_9 ) )
return V_27 ;
if ( ! F_10 ( V_5 ) )
return 0 ;
V_52 = V_4 -> V_4 [ F_6 ( V_5 ) ] ;
__asm__ __volatile__("dclz %0, %1" : "=r"(res) : "r"(rs));
V_4 -> V_4 [ F_10 ( V_5 ) ] = V_50 ;
F_14 ( V_56 ) ;
return 0 ;
}
static int F_44 ( struct V_3 * V_4 , T_2 V_5 )
{
V_23 V_50 ;
V_23 V_52 ;
if ( F_8 ( V_9 ) )
return V_27 ;
if ( ! F_10 ( V_5 ) )
return 0 ;
V_52 = V_4 -> V_4 [ F_6 ( V_5 ) ] ;
__asm__ __volatile__("dclo %0, %1" : "=r"(res) : "r"(rs));
V_4 -> V_4 [ F_10 ( V_5 ) ] = V_50 ;
F_14 ( V_56 ) ;
return 0 ;
}
static inline int F_45 ( struct V_3 * V_4 , T_2 V_57 ,
struct V_58 * V_59 )
{
struct V_58 * V_60 ;
int V_36 ;
for ( V_60 = V_59 ; V_60 -> V_61 ; V_60 ++ ) {
if ( ( V_57 & V_60 -> V_62 ) == V_60 -> V_63 ) {
V_36 = ( V_60 -> V_61 ) ( V_4 , V_57 ) ;
return V_36 ;
}
}
return V_27 ;
}
int F_46 ( struct V_3 * V_4 , T_2 V_57 , unsigned long * V_33 )
{
int V_36 = 0 ;
unsigned long V_64 ;
T_2 V_40 ;
unsigned long V_65 , V_38 , V_39 , V_66 , V_50 , V_52 , V_51 ;
void V_43 * V_67 = NULL ;
int V_68 = 0 ;
V_69:
V_66 = V_4 -> V_4 [ 31 ] ;
V_38 = V_4 -> V_41 ;
V_36 = F_47 ( V_4 ) ;
if ( V_36 < 0 ) {
F_48 () ;
return V_42 ;
}
F_12 ( L_3 ,
V_57 , V_38 , V_68 ) ;
switch ( F_4 ( V_57 ) ) {
case V_16 :
V_36 = F_45 ( V_4 , V_57 , V_70 ) ;
if ( V_36 < 0 ) {
V_4 -> V_71 |= V_72 ;
goto V_73;
}
break;
case V_74 :
V_36 = F_45 ( V_4 , V_57 , V_75 ) ;
break;
case V_76 :
V_51 = F_5 ( V_57 ) ;
V_52 = F_6 ( V_57 ) ;
switch ( V_51 ) {
case V_77 :
if ( ( long ) V_4 -> V_4 [ V_52 ] >= F_7 ( V_57 ) )
F_49 ( V_4 , 0 , 0 , L_4 ) ;
F_14 ( V_78 ) ;
break;
case V_79 :
if ( V_4 -> V_4 [ V_52 ] >= F_50 ( V_57 ) )
F_49 ( V_4 , 0 , 0 , L_5 ) ;
F_14 ( V_78 ) ;
break;
case V_80 :
if ( ( long ) V_4 -> V_4 [ V_52 ] < F_7 ( V_57 ) )
F_49 ( V_4 , 0 , 0 , L_6 ) ;
F_14 ( V_78 ) ;
break;
case V_81 :
if ( V_4 -> V_4 [ V_52 ] < F_50 ( V_57 ) )
F_49 ( V_4 , 0 , 0 , L_7 ) ;
F_14 ( V_78 ) ;
break;
case V_82 :
if ( V_4 -> V_4 [ V_52 ] == F_7 ( V_57 ) )
F_49 ( V_4 , 0 , 0 , L_8 ) ;
F_14 ( V_78 ) ;
break;
case V_83 :
if ( V_4 -> V_4 [ V_52 ] != F_7 ( V_57 ) )
F_49 ( V_4 , 0 , 0 , L_9 ) ;
F_14 ( V_78 ) ;
break;
case V_84 :
case V_85 :
case V_86 :
case V_87 :
if ( F_17 ( V_4 ) ) {
V_36 = V_27 ;
break;
}
V_4 -> V_4 [ 31 ] = V_66 ;
V_4 -> V_41 = V_38 ;
V_36 = F_18 ( V_4 ) ;
if ( V_36 < 0 )
return V_42 ;
if ( V_36 != V_88 )
break;
V_65 = V_4 -> V_41 ;
V_39 = V_38 + 4 ;
V_36 = F_19 ( V_40 , ( T_2 V_43 * ) V_39 ) ;
if ( V_36 ) {
V_36 = V_44 ;
break;
}
switch ( V_51 ) {
case V_84 :
F_20 ( V_89 ) ;
break;
case V_85 :
F_20 ( V_90 ) ;
break;
case V_86 :
F_20 ( V_91 ) ;
break;
case V_87 :
F_20 ( V_92 ) ;
break;
}
switch ( F_4 ( V_40 ) ) {
case V_13 :
case V_14 :
case V_11 :
case V_12 :
V_4 -> V_71 |= V_72 ;
goto V_73;
}
if ( V_40 ) {
V_36 = F_3 ( V_4 , V_40 ) ;
if ( V_36 > 0 ) {
V_36 = F_21 ( V_4 , V_40 , V_65 ) ;
if ( V_36 == V_27 )
V_36 = V_42 ;
F_14 ( V_46 ) ;
}
}
break;
case V_93 :
case V_94 :
if ( F_17 ( V_4 ) ) {
V_36 = V_27 ;
break;
}
V_4 -> V_4 [ 31 ] = V_66 ;
V_4 -> V_41 = V_38 ;
V_36 = F_18 ( V_4 ) ;
if ( V_36 < 0 )
return V_42 ;
V_65 = V_4 -> V_41 ;
V_39 = V_38 + 4 ;
V_36 = F_19 ( V_40 , ( T_2 V_43 * ) V_39 ) ;
if ( V_36 ) {
V_36 = V_44 ;
break;
}
switch ( V_51 ) {
case V_93 :
F_20 ( V_95 ) ;
break;
case V_94 :
F_20 ( V_96 ) ;
break;
}
switch ( F_4 ( V_40 ) ) {
case V_13 :
case V_14 :
case V_11 :
case V_12 :
V_4 -> V_71 |= V_72 ;
goto V_73;
}
if ( V_40 ) {
V_36 = F_3 ( V_4 , V_40 ) ;
if ( V_36 > 0 ) {
V_36 = F_21 ( V_4 , V_40 , V_65 ) ;
if ( V_36 == V_27 )
V_36 = V_42 ;
F_14 ( V_46 ) ;
}
}
break;
default:
V_4 -> V_4 [ 31 ] = V_66 ;
V_4 -> V_41 = V_38 ;
V_36 = V_27 ;
break;
}
break;
case V_97 :
case V_98 :
case V_99 :
case V_100 :
if ( F_17 ( V_4 ) ) {
V_36 = V_27 ;
break;
}
V_4 -> V_4 [ 31 ] = V_66 ;
V_4 -> V_41 = V_38 ;
V_36 = F_18 ( V_4 ) ;
if ( V_36 < 0 )
return V_42 ;
if ( V_36 != V_88 )
break;
V_65 = V_4 -> V_41 ;
V_39 = V_38 + 4 ;
V_36 = F_19 ( V_40 , ( T_2 V_43 * ) V_39 ) ;
if ( V_36 ) {
V_36 = V_44 ;
break;
}
switch ( F_4 ( V_57 ) ) {
case V_97 :
F_20 ( V_101 ) ;
break;
case V_98 :
F_20 ( V_102 ) ;
break;
case V_99 :
F_20 ( V_103 ) ;
break;
case V_100 :
F_20 ( V_104 ) ;
break;
}
switch ( F_4 ( V_40 ) ) {
case V_13 :
case V_14 :
case V_11 :
case V_12 :
V_4 -> V_71 |= V_72 ;
goto V_73;
}
if ( V_40 ) {
V_36 = F_3 ( V_4 , V_40 ) ;
if ( V_36 > 0 ) {
V_36 = F_21 ( V_4 , V_40 , V_65 ) ;
if ( V_36 == V_27 )
V_36 = V_42 ;
F_14 ( V_46 ) ;
}
}
break;
case V_11 :
case V_12 :
case V_13 :
case V_14 :
V_73:
V_4 -> V_4 [ 31 ] = V_66 ;
V_4 -> V_41 = V_38 ;
if ( ! F_51 () ) {
V_36 = F_52 () ;
F_53 () ;
}
F_54 ( 1 ) ;
V_36 = F_55 ( V_4 , & V_30 -> V_31 . V_32 , 0 ,
& V_67 ) ;
* V_33 = V_30 -> V_31 . V_32 . V_33 ;
V_30 -> V_31 . V_32 . V_33 &= ~ V_105 ;
F_56 ( 1 ) ;
if ( V_36 )
V_30 -> V_31 . V_106 = ( unsigned long ) V_67 ;
F_14 ( V_107 ) ;
break;
case V_108 :
V_51 = V_4 -> V_4 [ F_5 ( V_57 ) ] ;
V_64 = V_4 -> V_4 [ F_6 ( V_57 ) ] + F_7 ( V_57 ) ;
if ( ! F_57 ( V_109 , V_64 , 4 ) ) {
V_30 -> V_31 . V_106 = V_64 ;
V_36 = V_44 ;
break;
}
__asm__ __volatile__(
" .set push\n"
" .set reorder\n"
#ifdef F_58
"1:" LB "%1, 0(%2)\n"
INS "%0, %1, 24, 8\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
ADDIU "%2, %2, -1\n"
"2:" LB "%1, 0(%2)\n"
INS "%0, %1, 16, 8\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
ADDIU "%2, %2, -1\n"
"3:" LB "%1, 0(%2)\n"
INS "%0, %1, 8, 8\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
ADDIU "%2, %2, -1\n"
"4:" LB "%1, 0(%2)\n"
INS "%0, %1, 0, 8\n"
#else
"1:" LB "%1, 0(%2)\n"
INS "%0, %1, 24, 8\n"
ADDIU "%2, %2, 1\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
"2:" LB "%1, 0(%2)\n"
INS "%0, %1, 16, 8\n"
ADDIU "%2, %2, 1\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
"3:" LB "%1, 0(%2)\n"
INS "%0, %1, 8, 8\n"
ADDIU "%2, %2, 1\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
"4:" LB "%1, 0(%2)\n"
INS "%0, %1, 0, 8\n"
#endif
"9: sll %0, %0, 0\n"
"10:\n"
" .insn\n"
" .section .fixup,\"ax\"\n"
"8: li %3,%4\n"
" j 10b\n"
" .previous\n"
" .section __ex_table,\"a\"\n"
STR(PTR) " 1b,8b\n"
STR(PTR) " 2b,8b\n"
STR(PTR) " 3b,8b\n"
STR(PTR) " 4b,8b\n"
" .previous\n"
" .set pop\n"
: "+&r"(rt), "=&r"(rs),
"+&r"(vaddr), "+&r"(err)
: "i"(SIGSEGV));
if ( F_5 ( V_57 ) && ! V_36 )
V_4 -> V_4 [ F_5 ( V_57 ) ] = V_51 ;
F_14 ( V_110 ) ;
break;
case V_111 :
V_51 = V_4 -> V_4 [ F_5 ( V_57 ) ] ;
V_64 = V_4 -> V_4 [ F_6 ( V_57 ) ] + F_7 ( V_57 ) ;
if ( ! F_57 ( V_109 , V_64 , 4 ) ) {
V_30 -> V_31 . V_106 = V_64 ;
V_36 = V_44 ;
break;
}
__asm__ __volatile__(
" .set push\n"
" .set reorder\n"
#ifdef F_58
"1:" LB "%1, 0(%2)\n"
INS "%0, %1, 0, 8\n"
ADDIU "%2, %2, 1\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
"2:" LB "%1, 0(%2)\n"
INS "%0, %1, 8, 8\n"
ADDIU "%2, %2, 1\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
"3:" LB "%1, 0(%2)\n"
INS "%0, %1, 16, 8\n"
ADDIU "%2, %2, 1\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
"4:" LB "%1, 0(%2)\n"
INS "%0, %1, 24, 8\n"
" sll %0, %0, 0\n"
#else
"1:" LB "%1, 0(%2)\n"
INS "%0, %1, 0, 8\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
ADDIU "%2, %2, -1\n"
"2:" LB "%1, 0(%2)\n"
INS "%0, %1, 8, 8\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
ADDIU "%2, %2, -1\n"
"3:" LB "%1, 0(%2)\n"
INS "%0, %1, 16, 8\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
ADDIU "%2, %2, -1\n"
"4:" LB "%1, 0(%2)\n"
INS "%0, %1, 24, 8\n"
" sll %0, %0, 0\n"
#endif
"9:\n"
"10:\n"
" .insn\n"
" .section .fixup,\"ax\"\n"
"8: li %3,%4\n"
" j 10b\n"
" .previous\n"
" .section __ex_table,\"a\"\n"
STR(PTR) " 1b,8b\n"
STR(PTR) " 2b,8b\n"
STR(PTR) " 3b,8b\n"
STR(PTR) " 4b,8b\n"
" .previous\n"
" .set pop\n"
: "+&r"(rt), "=&r"(rs),
"+&r"(vaddr), "+&r"(err)
: "i"(SIGSEGV));
if ( F_5 ( V_57 ) && ! V_36 )
V_4 -> V_4 [ F_5 ( V_57 ) ] = V_51 ;
F_14 ( V_110 ) ;
break;
case V_112 :
V_51 = V_4 -> V_4 [ F_5 ( V_57 ) ] ;
V_64 = V_4 -> V_4 [ F_6 ( V_57 ) ] + F_7 ( V_57 ) ;
if ( ! F_57 ( V_113 , V_64 , 4 ) ) {
V_30 -> V_31 . V_106 = V_64 ;
V_36 = V_44 ;
break;
}
__asm__ __volatile__(
" .set push\n"
" .set reorder\n"
#ifdef F_58
EXT "%1, %0, 24, 8\n"
"1:" SB "%1, 0(%2)\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
ADDIU "%2, %2, -1\n"
EXT "%1, %0, 16, 8\n"
"2:" SB "%1, 0(%2)\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
ADDIU "%2, %2, -1\n"
EXT "%1, %0, 8, 8\n"
"3:" SB "%1, 0(%2)\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
ADDIU "%2, %2, -1\n"
EXT "%1, %0, 0, 8\n"
"4:" SB "%1, 0(%2)\n"
#else
EXT "%1, %0, 24, 8\n"
"1:" SB "%1, 0(%2)\n"
ADDIU "%2, %2, 1\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
EXT "%1, %0, 16, 8\n"
"2:" SB "%1, 0(%2)\n"
ADDIU "%2, %2, 1\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
EXT "%1, %0, 8, 8\n"
"3:" SB "%1, 0(%2)\n"
ADDIU "%2, %2, 1\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
EXT "%1, %0, 0, 8\n"
"4:" SB "%1, 0(%2)\n"
#endif
"9:\n"
" .insn\n"
" .section .fixup,\"ax\"\n"
"8: li %3,%4\n"
" j 9b\n"
" .previous\n"
" .section __ex_table,\"a\"\n"
STR(PTR) " 1b,8b\n"
STR(PTR) " 2b,8b\n"
STR(PTR) " 3b,8b\n"
STR(PTR) " 4b,8b\n"
" .previous\n"
" .set pop\n"
: "+&r"(rt), "=&r"(rs),
"+&r"(vaddr), "+&r"(err)
: "i"(SIGSEGV)
: "memory");
F_14 ( V_114 ) ;
break;
case V_115 :
V_51 = V_4 -> V_4 [ F_5 ( V_57 ) ] ;
V_64 = V_4 -> V_4 [ F_6 ( V_57 ) ] + F_7 ( V_57 ) ;
if ( ! F_57 ( V_113 , V_64 , 4 ) ) {
V_30 -> V_31 . V_106 = V_64 ;
V_36 = V_44 ;
break;
}
__asm__ __volatile__(
" .set push\n"
" .set reorder\n"
#ifdef F_58
EXT "%1, %0, 0, 8\n"
"1:" SB "%1, 0(%2)\n"
ADDIU "%2, %2, 1\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
EXT "%1, %0, 8, 8\n"
"2:" SB "%1, 0(%2)\n"
ADDIU "%2, %2, 1\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
EXT "%1, %0, 16, 8\n"
"3:" SB "%1, 0(%2)\n"
ADDIU "%2, %2, 1\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
EXT "%1, %0, 24, 8\n"
"4:" SB "%1, 0(%2)\n"
#else
EXT "%1, %0, 0, 8\n"
"1:" SB "%1, 0(%2)\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
ADDIU "%2, %2, -1\n"
EXT "%1, %0, 8, 8\n"
"2:" SB "%1, 0(%2)\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
ADDIU "%2, %2, -1\n"
EXT "%1, %0, 16, 8\n"
"3:" SB "%1, 0(%2)\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
ADDIU "%2, %2, -1\n"
EXT "%1, %0, 24, 8\n"
"4:" SB "%1, 0(%2)\n"
#endif
"9:\n"
" .insn\n"
" .section .fixup,\"ax\"\n"
"8: li %3,%4\n"
" j 9b\n"
" .previous\n"
" .section __ex_table,\"a\"\n"
STR(PTR) " 1b,8b\n"
STR(PTR) " 2b,8b\n"
STR(PTR) " 3b,8b\n"
STR(PTR) " 4b,8b\n"
" .previous\n"
" .set pop\n"
: "+&r"(rt), "=&r"(rs),
"+&r"(vaddr), "+&r"(err)
: "i"(SIGSEGV)
: "memory");
F_14 ( V_114 ) ;
break;
case V_116 :
if ( F_8 ( V_9 ) ) {
V_36 = V_27 ;
break;
}
V_51 = V_4 -> V_4 [ F_5 ( V_57 ) ] ;
V_64 = V_4 -> V_4 [ F_6 ( V_57 ) ] + F_7 ( V_57 ) ;
if ( ! F_57 ( V_109 , V_64 , 8 ) ) {
V_30 -> V_31 . V_106 = V_64 ;
V_36 = V_44 ;
break;
}
__asm__ __volatile__(
" .set push\n"
" .set reorder\n"
#ifdef F_58
"1: lb %1, 0(%2)\n"
" dinsu %0, %1, 56, 8\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
"2: lb %1, 0(%2)\n"
" dinsu %0, %1, 48, 8\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
"3: lb %1, 0(%2)\n"
" dinsu %0, %1, 40, 8\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
"4: lb %1, 0(%2)\n"
" dinsu %0, %1, 32, 8\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
"5: lb %1, 0(%2)\n"
" dins %0, %1, 24, 8\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
"6: lb %1, 0(%2)\n"
" dins %0, %1, 16, 8\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
"7: lb %1, 0(%2)\n"
" dins %0, %1, 8, 8\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
"0: lb %1, 0(%2)\n"
" dins %0, %1, 0, 8\n"
#else
"1: lb %1, 0(%2)\n"
" dinsu %0, %1, 56, 8\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
"2: lb %1, 0(%2)\n"
" dinsu %0, %1, 48, 8\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
"3: lb %1, 0(%2)\n"
" dinsu %0, %1, 40, 8\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
"4: lb %1, 0(%2)\n"
" dinsu %0, %1, 32, 8\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
"5: lb %1, 0(%2)\n"
" dins %0, %1, 24, 8\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
"6: lb %1, 0(%2)\n"
" dins %0, %1, 16, 8\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
"7: lb %1, 0(%2)\n"
" dins %0, %1, 8, 8\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
"0: lb %1, 0(%2)\n"
" dins %0, %1, 0, 8\n"
#endif
"9:\n"
" .insn\n"
" .section .fixup,\"ax\"\n"
"8: li %3,%4\n"
" j 9b\n"
" .previous\n"
" .section __ex_table,\"a\"\n"
STR(PTR) " 1b,8b\n"
STR(PTR) " 2b,8b\n"
STR(PTR) " 3b,8b\n"
STR(PTR) " 4b,8b\n"
STR(PTR) " 5b,8b\n"
STR(PTR) " 6b,8b\n"
STR(PTR) " 7b,8b\n"
STR(PTR) " 0b,8b\n"
" .previous\n"
" .set pop\n"
: "+&r"(rt), "=&r"(rs),
"+&r"(vaddr), "+&r"(err)
: "i"(SIGSEGV));
if ( F_5 ( V_57 ) && ! V_36 )
V_4 -> V_4 [ F_5 ( V_57 ) ] = V_51 ;
F_14 ( V_110 ) ;
break;
case V_117 :
if ( F_8 ( V_9 ) ) {
V_36 = V_27 ;
break;
}
V_51 = V_4 -> V_4 [ F_5 ( V_57 ) ] ;
V_64 = V_4 -> V_4 [ F_6 ( V_57 ) ] + F_7 ( V_57 ) ;
if ( ! F_57 ( V_109 , V_64 , 8 ) ) {
V_30 -> V_31 . V_106 = V_64 ;
V_36 = V_44 ;
break;
}
__asm__ __volatile__(
" .set push\n"
" .set reorder\n"
#ifdef F_58
"1: lb %1, 0(%2)\n"
" dins %0, %1, 0, 8\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
"2: lb %1, 0(%2)\n"
" dins %0, %1, 8, 8\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
"3: lb %1, 0(%2)\n"
" dins %0, %1, 16, 8\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
"4: lb %1, 0(%2)\n"
" dins %0, %1, 24, 8\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
"5: lb %1, 0(%2)\n"
" dinsu %0, %1, 32, 8\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
"6: lb %1, 0(%2)\n"
" dinsu %0, %1, 40, 8\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
"7: lb %1, 0(%2)\n"
" dinsu %0, %1, 48, 8\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
"0: lb %1, 0(%2)\n"
" dinsu %0, %1, 56, 8\n"
#else
"1: lb %1, 0(%2)\n"
" dins %0, %1, 0, 8\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
"2: lb %1, 0(%2)\n"
" dins %0, %1, 8, 8\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
"3: lb %1, 0(%2)\n"
" dins %0, %1, 16, 8\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
"4: lb %1, 0(%2)\n"
" dins %0, %1, 24, 8\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
"5: lb %1, 0(%2)\n"
" dinsu %0, %1, 32, 8\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
"6: lb %1, 0(%2)\n"
" dinsu %0, %1, 40, 8\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
"7: lb %1, 0(%2)\n"
" dinsu %0, %1, 48, 8\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
"0: lb %1, 0(%2)\n"
" dinsu %0, %1, 56, 8\n"
#endif
"9:\n"
" .insn\n"
" .section .fixup,\"ax\"\n"
"8: li %3,%4\n"
" j 9b\n"
" .previous\n"
" .section __ex_table,\"a\"\n"
STR(PTR) " 1b,8b\n"
STR(PTR) " 2b,8b\n"
STR(PTR) " 3b,8b\n"
STR(PTR) " 4b,8b\n"
STR(PTR) " 5b,8b\n"
STR(PTR) " 6b,8b\n"
STR(PTR) " 7b,8b\n"
STR(PTR) " 0b,8b\n"
" .previous\n"
" .set pop\n"
: "+&r"(rt), "=&r"(rs),
"+&r"(vaddr), "+&r"(err)
: "i"(SIGSEGV));
if ( F_5 ( V_57 ) && ! V_36 )
V_4 -> V_4 [ F_5 ( V_57 ) ] = V_51 ;
F_14 ( V_110 ) ;
break;
case V_118 :
if ( F_8 ( V_9 ) ) {
V_36 = V_27 ;
break;
}
V_51 = V_4 -> V_4 [ F_5 ( V_57 ) ] ;
V_64 = V_4 -> V_4 [ F_6 ( V_57 ) ] + F_7 ( V_57 ) ;
if ( ! F_57 ( V_113 , V_64 , 8 ) ) {
V_30 -> V_31 . V_106 = V_64 ;
V_36 = V_44 ;
break;
}
__asm__ __volatile__(
" .set push\n"
" .set reorder\n"
#ifdef F_58
" dextu %1, %0, 56, 8\n"
"1: sb %1, 0(%2)\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
" dextu %1, %0, 48, 8\n"
"2: sb %1, 0(%2)\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
" dextu %1, %0, 40, 8\n"
"3: sb %1, 0(%2)\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
" dextu %1, %0, 32, 8\n"
"4: sb %1, 0(%2)\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
" dext %1, %0, 24, 8\n"
"5: sb %1, 0(%2)\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
" dext %1, %0, 16, 8\n"
"6: sb %1, 0(%2)\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
" dext %1, %0, 8, 8\n"
"7: sb %1, 0(%2)\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
" dext %1, %0, 0, 8\n"
"0: sb %1, 0(%2)\n"
#else
" dextu %1, %0, 56, 8\n"
"1: sb %1, 0(%2)\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" dextu %1, %0, 48, 8\n"
"2: sb %1, 0(%2)\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" dextu %1, %0, 40, 8\n"
"3: sb %1, 0(%2)\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" dextu %1, %0, 32, 8\n"
"4: sb %1, 0(%2)\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" dext %1, %0, 24, 8\n"
"5: sb %1, 0(%2)\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" dext %1, %0, 16, 8\n"
"6: sb %1, 0(%2)\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" dext %1, %0, 8, 8\n"
"7: sb %1, 0(%2)\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" dext %1, %0, 0, 8\n"
"0: sb %1, 0(%2)\n"
#endif
"9:\n"
" .insn\n"
" .section .fixup,\"ax\"\n"
"8: li %3,%4\n"
" j 9b\n"
" .previous\n"
" .section __ex_table,\"a\"\n"
STR(PTR) " 1b,8b\n"
STR(PTR) " 2b,8b\n"
STR(PTR) " 3b,8b\n"
STR(PTR) " 4b,8b\n"
STR(PTR) " 5b,8b\n"
STR(PTR) " 6b,8b\n"
STR(PTR) " 7b,8b\n"
STR(PTR) " 0b,8b\n"
" .previous\n"
" .set pop\n"
: "+&r"(rt), "=&r"(rs),
"+&r"(vaddr), "+&r"(err)
: "i"(SIGSEGV)
: "memory");
F_14 ( V_114 ) ;
break;
case V_119 :
if ( F_8 ( V_9 ) ) {
V_36 = V_27 ;
break;
}
V_51 = V_4 -> V_4 [ F_5 ( V_57 ) ] ;
V_64 = V_4 -> V_4 [ F_6 ( V_57 ) ] + F_7 ( V_57 ) ;
if ( ! F_57 ( V_113 , V_64 , 8 ) ) {
V_30 -> V_31 . V_106 = V_64 ;
V_36 = V_44 ;
break;
}
__asm__ __volatile__(
" .set push\n"
" .set reorder\n"
#ifdef F_58
" dext %1, %0, 0, 8\n"
"1: sb %1, 0(%2)\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" dext %1, %0, 8, 8\n"
"2: sb %1, 0(%2)\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" dext %1, %0, 16, 8\n"
"3: sb %1, 0(%2)\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" dext %1, %0, 24, 8\n"
"4: sb %1, 0(%2)\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" dextu %1, %0, 32, 8\n"
"5: sb %1, 0(%2)\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" dextu %1, %0, 40, 8\n"
"6: sb %1, 0(%2)\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" dextu %1, %0, 48, 8\n"
"7: sb %1, 0(%2)\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" dextu %1, %0, 56, 8\n"
"0: sb %1, 0(%2)\n"
#else
" dext %1, %0, 0, 8\n"
"1: sb %1, 0(%2)\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
" dext %1, %0, 8, 8\n"
"2: sb %1, 0(%2)\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
" dext %1, %0, 16, 8\n"
"3: sb %1, 0(%2)\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
" dext %1, %0, 24, 8\n"
"4: sb %1, 0(%2)\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
" dextu %1, %0, 32, 8\n"
"5: sb %1, 0(%2)\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
" dextu %1, %0, 40, 8\n"
"6: sb %1, 0(%2)\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
" dextu %1, %0, 48, 8\n"
"7: sb %1, 0(%2)\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
" dextu %1, %0, 56, 8\n"
"0: sb %1, 0(%2)\n"
#endif
"9:\n"
" .insn\n"
" .section .fixup,\"ax\"\n"
"8: li %3,%4\n"
" j 9b\n"
" .previous\n"
" .section __ex_table,\"a\"\n"
STR(PTR) " 1b,8b\n"
STR(PTR) " 2b,8b\n"
STR(PTR) " 3b,8b\n"
STR(PTR) " 4b,8b\n"
STR(PTR) " 5b,8b\n"
STR(PTR) " 6b,8b\n"
STR(PTR) " 7b,8b\n"
STR(PTR) " 0b,8b\n"
" .previous\n"
" .set pop\n"
: "+&r"(rt), "=&r"(rs),
"+&r"(vaddr), "+&r"(err)
: "i"(SIGSEGV)
: "memory");
F_14 ( V_114 ) ;
break;
case V_120 :
V_64 = V_4 -> V_4 [ F_6 ( V_57 ) ] + F_7 ( V_57 ) ;
if ( V_64 & 0x3 ) {
V_30 -> V_31 . V_106 = V_64 ;
V_36 = V_121 ;
break;
}
if ( ! F_57 ( V_109 , V_64 , 4 ) ) {
V_30 -> V_31 . V_106 = V_64 ;
V_36 = V_121 ;
break;
}
if ( ! V_122 ) {
F_59 ( L_10 ) ;
V_36 = V_123 ;
break;
}
__asm__ __volatile__(
"1:\n"
"ll %0, 0(%2)\n"
"2:\n"
".insn\n"
".section .fixup,\"ax\"\n"
"3:\n"
"li %1, %3\n"
"j 2b\n"
".previous\n"
".section __ex_table,\"a\"\n"
STR(PTR) " 1b,3b\n"
".previous\n"
: "=&r"(res), "+&r"(err)
: "r"(vaddr), "i"(SIGSEGV)
: "memory");
if ( F_5 ( V_57 ) && ! V_36 )
V_4 -> V_4 [ F_5 ( V_57 ) ] = V_50 ;
F_14 ( V_124 ) ;
break;
case V_125 :
V_64 = V_4 -> V_4 [ F_6 ( V_57 ) ] + F_7 ( V_57 ) ;
if ( V_64 & 0x3 ) {
V_30 -> V_31 . V_106 = V_64 ;
V_36 = V_121 ;
break;
}
if ( ! F_57 ( V_113 , V_64 , 4 ) ) {
V_30 -> V_31 . V_106 = V_64 ;
V_36 = V_121 ;
break;
}
if ( ! V_122 ) {
F_59 ( L_10 ) ;
V_36 = V_123 ;
break;
}
V_50 = V_4 -> V_4 [ F_5 ( V_57 ) ] ;
__asm__ __volatile__(
"1:\n"
"sc %0, 0(%2)\n"
"2:\n"
".insn\n"
".section .fixup,\"ax\"\n"
"3:\n"
"li %1, %3\n"
"j 2b\n"
".previous\n"
".section __ex_table,\"a\"\n"
STR(PTR) " 1b,3b\n"
".previous\n"
: "+&r"(res), "+&r"(err)
: "r"(vaddr), "i"(SIGSEGV));
if ( F_5 ( V_57 ) && ! V_36 )
V_4 -> V_4 [ F_5 ( V_57 ) ] = V_50 ;
F_14 ( V_124 ) ;
break;
case V_126 :
if ( F_8 ( V_9 ) ) {
V_36 = V_27 ;
break;
}
V_64 = V_4 -> V_4 [ F_6 ( V_57 ) ] + F_7 ( V_57 ) ;
if ( V_64 & 0x7 ) {
V_30 -> V_31 . V_106 = V_64 ;
V_36 = V_121 ;
break;
}
if ( ! F_57 ( V_109 , V_64 , 8 ) ) {
V_30 -> V_31 . V_106 = V_64 ;
V_36 = V_121 ;
break;
}
if ( ! V_122 ) {
F_59 ( L_10 ) ;
V_36 = V_123 ;
break;
}
__asm__ __volatile__(
"1:\n"
"lld %0, 0(%2)\n"
"2:\n"
".insn\n"
".section .fixup,\"ax\"\n"
"3:\n"
"li %1, %3\n"
"j 2b\n"
".previous\n"
".section __ex_table,\"a\"\n"
STR(PTR) " 1b,3b\n"
".previous\n"
: "=&r"(res), "+&r"(err)
: "r"(vaddr), "i"(SIGSEGV)
: "memory");
if ( F_5 ( V_57 ) && ! V_36 )
V_4 -> V_4 [ F_5 ( V_57 ) ] = V_50 ;
F_14 ( V_124 ) ;
break;
case V_127 :
if ( F_8 ( V_9 ) ) {
V_36 = V_27 ;
break;
}
V_64 = V_4 -> V_4 [ F_6 ( V_57 ) ] + F_7 ( V_57 ) ;
if ( V_64 & 0x7 ) {
V_30 -> V_31 . V_106 = V_64 ;
V_36 = V_121 ;
break;
}
if ( ! F_57 ( V_113 , V_64 , 8 ) ) {
V_30 -> V_31 . V_106 = V_64 ;
V_36 = V_121 ;
break;
}
if ( ! V_122 ) {
F_59 ( L_10 ) ;
V_36 = V_123 ;
break;
}
V_50 = V_4 -> V_4 [ F_5 ( V_57 ) ] ;
__asm__ __volatile__(
"1:\n"
"scd %0, 0(%2)\n"
"2:\n"
".insn\n"
".section .fixup,\"ax\"\n"
"3:\n"
"li %1, %3\n"
"j 2b\n"
".previous\n"
".section __ex_table,\"a\"\n"
STR(PTR) " 1b,3b\n"
".previous\n"
: "+&r"(res), "+&r"(err)
: "r"(vaddr), "i"(SIGSEGV));
if ( F_5 ( V_57 ) && ! V_36 )
V_4 -> V_4 [ F_5 ( V_57 ) ] = V_50 ;
F_14 ( V_124 ) ;
break;
case V_128 :
break;
default:
V_36 = V_27 ;
}
if ( ! V_36 && ( V_68 ++ < V_129 ) ) {
V_4 -> V_71 &= ~ V_72 ;
V_36 = F_60 ( V_57 , ( T_2 V_43 * ) V_4 -> V_41 ) ;
if ( ! V_36 )
goto V_69;
if ( V_36 < 0 )
V_36 = V_44 ;
}
if ( V_36 && ( V_36 != V_42 ) ) {
V_4 -> V_4 [ 31 ] = V_66 ;
V_4 -> V_41 = V_38 ;
}
if ( V_68 && ( V_36 == V_27 ) )
V_36 = 0 ;
return V_36 ;
}
static int F_61 ( struct V_130 * V_1 , void * V_131 )
{
F_62 ( V_1 , L_11 ) ;
F_62 ( V_1 , L_12 ,
( unsigned long ) F_63 ( V_132 . V_35 ) ,
( unsigned long ) F_63 ( V_133 . V_35 ) ) ;
F_62 ( V_1 , L_13 ,
( unsigned long ) F_63 ( V_132 . V_48 ) ,
( unsigned long ) F_63 ( V_133 . V_48 ) ) ;
F_62 ( V_1 , L_14 ,
( unsigned long ) F_63 ( V_132 . V_53 ) ,
( unsigned long ) F_63 ( V_133 . V_53 ) ) ;
F_62 ( V_1 , L_15 ,
( unsigned long ) F_63 ( V_132 . V_54 ) ,
( unsigned long ) F_63 ( V_133 . V_54 ) ) ;
F_62 ( V_1 , L_16 ,
( unsigned long ) F_63 ( V_132 . V_55 ) ,
( unsigned long ) F_63 ( V_133 . V_55 ) ) ;
F_62 ( V_1 , L_17 ,
( unsigned long ) F_63 ( V_132 . V_56 ) ,
( unsigned long ) F_63 ( V_133 . V_56 ) ) ;
F_62 ( V_1 , L_18 ,
( unsigned long ) F_63 ( V_132 . V_78 ) ,
( unsigned long ) F_63 ( V_133 . V_78 ) ) ;
F_62 ( V_1 , L_19 ,
( unsigned long ) F_63 ( V_132 . V_107 ) ,
( unsigned long ) F_63 ( V_133 . V_107 ) ) ;
F_62 ( V_1 , L_20 ,
( unsigned long ) F_63 ( V_132 . V_110 ) ,
( unsigned long ) F_63 ( V_133 . V_110 ) ) ;
F_62 ( V_1 , L_21 ,
( unsigned long ) F_63 ( V_132 . V_114 ) ,
( unsigned long ) F_63 ( V_133 . V_114 ) ) ;
F_62 ( V_1 , L_22 ,
( unsigned long ) F_63 ( V_132 . V_124 ) ,
( unsigned long ) F_63 ( V_133 . V_124 ) ) ;
F_62 ( V_1 , L_23 ,
( unsigned long ) F_63 ( V_132 . V_46 ) ,
( unsigned long ) F_63 ( V_133 . V_46 ) ) ;
F_62 ( V_1 , L_24 ,
( unsigned long ) F_63 ( V_134 . V_45 ) ) ;
F_62 ( V_1 , L_25 ,
( unsigned long ) F_63 ( V_134 . V_89 ) ) ;
F_62 ( V_1 , L_26 ,
( unsigned long ) F_63 ( V_134 . V_90 ) ) ;
F_62 ( V_1 , L_27 ,
( unsigned long ) F_63 ( V_134 . V_135 ) ) ;
F_62 ( V_1 , L_28 ,
( unsigned long ) F_63 ( V_134 . V_136 ) ) ;
F_62 ( V_1 , L_29 ,
( unsigned long ) F_63 ( V_134 . V_95 ) ) ;
F_62 ( V_1 , L_30 ,
( unsigned long ) F_63 ( V_134 . V_96 ) ) ;
F_62 ( V_1 , L_31 ,
( unsigned long ) F_63 ( V_134 . V_101 ) ) ;
F_62 ( V_1 , L_32 ,
( unsigned long ) F_63 ( V_134 . V_102 ) ) ;
F_62 ( V_1 , L_33 ,
( unsigned long ) F_63 ( V_134 . V_103 ) ) ;
F_62 ( V_1 , L_34 ,
( unsigned long ) F_63 ( V_134 . V_104 ) ) ;
return 0 ;
}
static int F_64 ( struct V_130 * V_1 , void * V_131 )
{
F_61 ( V_1 , V_131 ) ;
F_65 ( ( V_132 ) . V_35 , 0 ) ;
F_65 ( ( V_133 ) . V_35 , 0 ) ;
F_65 ( ( V_132 ) . V_48 , 0 ) ;
F_65 ( ( V_133 ) . V_48 , 0 ) ;
F_65 ( ( V_132 ) . V_53 , 0 ) ;
F_65 ( ( V_133 ) . V_53 , 0 ) ;
F_65 ( ( V_132 ) . V_54 , 0 ) ;
F_65 ( ( V_133 ) . V_54 , 0 ) ;
F_65 ( ( V_132 ) . V_55 , 0 ) ;
F_65 ( ( V_133 ) . V_55 , 0 ) ;
F_65 ( ( V_132 ) . V_56 , 0 ) ;
F_65 ( ( V_133 ) . V_56 , 0 ) ;
F_65 ( ( V_132 ) . V_78 , 0 ) ;
F_65 ( ( V_133 ) . V_78 , 0 ) ;
F_65 ( ( V_132 ) . V_107 , 0 ) ;
F_65 ( ( V_133 ) . V_107 , 0 ) ;
F_65 ( ( V_132 ) . V_110 , 0 ) ;
F_65 ( ( V_133 ) . V_110 , 0 ) ;
F_65 ( ( V_132 ) . V_114 , 0 ) ;
F_65 ( ( V_133 ) . V_114 , 0 ) ;
F_65 ( ( V_132 ) . V_124 , 0 ) ;
F_65 ( ( V_133 ) . V_124 , 0 ) ;
F_65 ( ( V_132 ) . V_46 , 0 ) ;
F_65 ( ( V_133 ) . V_46 , 0 ) ;
F_65 ( ( V_134 ) . V_45 , 0 ) ;
F_65 ( ( V_134 ) . V_89 , 0 ) ;
F_65 ( ( V_134 ) . V_90 , 0 ) ;
F_65 ( ( V_134 ) . V_135 , 0 ) ;
F_65 ( ( V_134 ) . V_136 , 0 ) ;
F_65 ( ( V_134 ) . V_95 , 0 ) ;
F_65 ( ( V_134 ) . V_96 , 0 ) ;
F_65 ( ( V_134 ) . V_101 , 0 ) ;
F_65 ( ( V_134 ) . V_102 , 0 ) ;
F_65 ( ( V_134 ) . V_103 , 0 ) ;
F_65 ( ( V_134 ) . V_104 , 0 ) ;
return 0 ;
}
static int F_66 ( struct V_137 * V_137 , struct V_138 * V_138 )
{
return F_67 ( V_138 , F_61 , V_137 -> V_139 ) ;
}
static int F_68 ( struct V_137 * V_137 , struct V_138 * V_138 )
{
return F_67 ( V_138 , F_64 , V_137 -> V_139 ) ;
}
static int T_1 F_69 ( void )
{
struct V_140 * V_141 ;
if ( ! V_142 )
return - V_143 ;
V_141 = F_70 ( L_35 , V_144 ,
V_142 , NULL ,
& V_145 ) ;
if ( ! V_141 )
return - V_146 ;
V_141 = F_70 ( L_36 , V_144 ,
V_142 , NULL ,
& V_147 ) ;
if ( ! V_141 )
return - V_146 ;
return 0 ;
}
