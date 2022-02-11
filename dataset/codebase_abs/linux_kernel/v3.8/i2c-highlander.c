static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 -> V_3 + V_4 ) | V_5 , V_2 -> V_3 + V_4 ) ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 -> V_3 + V_4 ) & ~ V_5 , V_2 -> V_3 + V_4 ) ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 -> V_3 + V_4 ) | V_6 , V_2 -> V_3 + V_4 ) ;
}
static inline void F_6 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 -> V_3 + V_4 ) | V_7 , V_2 -> V_3 + V_4 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_8 ;
V_8 = F_3 ( V_2 -> V_3 + V_9 ) ;
V_8 |= V_10 ;
if ( V_11 )
V_8 &= ~ V_12 ;
else
V_8 |= V_12 ;
F_2 ( V_8 , V_2 -> V_3 + V_9 ) ;
}
static void F_8 ( T_2 * V_13 , T_1 * V_14 , int V_15 )
{
for (; V_15 > 1 ; V_15 -= 2 ) {
* V_14 ++ = F_9 ( ( V_16 * ) V_13 ) ;
V_13 += 2 ;
}
if ( V_15 )
* V_14 = * V_13 << 8 ;
}
static void F_10 ( T_1 * V_13 , T_2 * V_14 , int V_15 )
{
for (; V_15 > 1 ; V_15 -= 2 ) {
* ( V_16 * ) V_14 = F_11 ( V_13 ++ ) ;
V_14 += 2 ;
}
if ( V_15 )
* V_14 = * V_13 >> 8 ;
}
static void F_12 ( struct V_1 * V_2 ,
T_2 V_17 , int V_15 )
{
unsigned int V_18 ;
T_1 V_19 = ( V_17 << 8 ) | V_17 ;
for ( V_18 = 0 ; V_18 < V_15 ; V_18 += 2 ) {
if ( V_15 - V_18 == 1 )
V_19 = V_17 << 8 ;
F_2 ( V_19 , V_2 -> V_3 + V_20 + V_18 ) ;
F_13 ( V_2 -> V_2 , L_1 , V_18 / 2 , V_19 ) ;
}
}
static int F_14 ( struct V_1 * V_2 )
{
unsigned long V_21 ;
V_21 = V_22 + F_15 ( V_23 ) ;
while ( F_3 ( V_2 -> V_3 + V_4 ) & V_24 ) {
if ( F_16 ( V_22 , V_21 ) ) {
F_17 ( V_2 -> V_2 , L_2 ) ;
return - V_25 ;
}
F_18 ( 1 ) ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 -> V_3 + V_4 ) | V_26 , V_2 -> V_3 + V_4 ) ;
return F_14 ( V_2 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
T_1 V_27 = F_3 ( V_2 -> V_3 + V_4 ) ;
if ( ( V_27 & ( V_7 | V_28 ) ) == V_28 ) {
F_17 ( V_2 -> V_2 , L_3 ) ;
return F_19 ( V_2 ) ;
}
return 0 ;
}
static T_3 F_21 ( int V_29 , void * V_30 )
{
struct V_1 * V_2 = V_30 ;
F_6 ( V_2 ) ;
F_22 ( & V_2 -> V_31 ) ;
return V_32 ;
}
static void F_23 ( struct V_1 * V_2 )
{
unsigned long V_21 ;
T_1 V_33 ;
V_21 = V_22 + F_15 ( V_23 ) ;
for (; ; ) {
V_33 = F_3 ( V_2 -> V_3 + V_4 ) ;
if ( V_33 & V_7 )
return;
if ( F_16 ( V_22 , V_21 ) )
break;
F_24 () ;
F_25 () ;
}
F_26 ( V_2 -> V_2 , L_4 ) ;
}
static inline int F_27 ( struct V_1 * V_2 )
{
if ( V_2 -> V_29 )
F_28 ( & V_2 -> V_31 ,
F_15 ( V_23 ) ) ;
else
F_23 ( V_2 ) ;
return F_20 ( V_2 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_18 , V_34 ;
T_1 V_35 [ 16 ] ;
if ( F_14 ( V_2 ) )
return - V_36 ;
F_5 ( V_2 ) ;
if ( F_27 ( V_2 ) ) {
F_26 ( V_2 -> V_2 , L_5 ) ;
return - V_36 ;
}
if ( V_37 && F_30 ( V_22 , V_2 -> V_38 +
F_15 ( V_37 ) ) )
F_18 ( F_31 ( ( V_2 -> V_38 +
F_15 ( V_37 ) ) - V_22 ) ) ;
V_34 = ( V_2 -> V_39 + 1 ) >> 1 ;
for ( V_18 = 0 ; V_18 < V_34 ; V_18 ++ ) {
V_35 [ V_18 ] = F_3 ( V_2 -> V_3 + V_40 + ( V_18 * sizeof( T_1 ) ) ) ;
F_13 ( V_2 -> V_2 , L_6 , V_18 , V_35 [ V_18 ] ) ;
}
F_10 ( V_35 , V_2 -> V_41 , V_2 -> V_39 ) ;
V_2 -> V_38 = V_22 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_18 , V_34 ;
T_1 V_35 [ 16 ] ;
F_8 ( V_2 -> V_41 , V_35 , V_2 -> V_39 ) ;
V_34 = ( V_2 -> V_39 + 1 ) >> 1 ;
for ( V_18 = 0 ; V_18 < V_34 ; V_18 ++ ) {
F_2 ( V_35 [ V_18 ] , V_2 -> V_3 + V_40 + ( V_18 * sizeof( T_1 ) ) ) ;
F_13 ( V_2 -> V_2 , L_7 , V_18 , V_35 [ V_18 ] ) ;
}
if ( F_14 ( V_2 ) )
return - V_36 ;
F_5 ( V_2 ) ;
return F_27 ( V_2 ) ;
}
static int F_33 ( struct V_42 * V_43 , T_1 V_44 ,
unsigned short V_45 , char V_46 ,
T_2 V_17 , int V_47 ,
union V_48 * V_35 )
{
struct V_1 * V_2 = F_34 ( V_43 ) ;
T_1 V_27 ;
F_35 ( & V_2 -> V_31 ) ;
F_13 ( V_2 -> V_2 , L_8 ,
V_44 , V_17 , V_46 , V_47 ) ;
switch ( V_47 ) {
case V_49 :
V_2 -> V_41 = & V_35 -> V_50 ;
V_2 -> V_39 = 1 ;
break;
case V_51 :
V_2 -> V_41 = & V_35 -> V_52 [ 1 ] ;
V_2 -> V_39 = V_35 -> V_52 [ 0 ] ;
break;
default:
F_26 ( V_2 -> V_2 , L_9 , V_47 ) ;
return - V_53 ;
}
V_27 = F_3 ( V_2 -> V_3 + V_9 ) ;
V_27 &= ~ ( V_54 | V_55 ) ;
switch ( V_2 -> V_39 ) {
case 1 :
break;
case 8 :
V_27 |= V_54 ;
break;
case 16 :
V_27 |= V_55 ;
break;
case 32 :
V_27 |= ( V_54 | V_55 ) ;
break;
default:
F_26 ( V_2 -> V_2 , L_10 , V_2 -> V_39 ) ;
return - V_53 ;
}
F_2 ( V_27 , V_2 -> V_3 + V_9 ) ;
F_6 ( V_2 ) ;
F_2 ( ( V_44 << 1 ) | V_46 , V_2 -> V_3 + V_56 ) ;
F_12 ( V_2 , V_17 , V_2 -> V_39 ) ;
if ( V_46 == V_57 )
return F_29 ( V_2 ) ;
else
return F_32 ( V_2 ) ;
}
static T_4 F_36 ( struct V_42 * V_58 )
{
return V_59 | V_60 ;
}
static int F_37 ( struct V_61 * V_62 )
{
struct V_1 * V_2 ;
struct V_42 * V_43 ;
struct V_63 * V_64 ;
int V_65 ;
V_64 = F_38 ( V_62 , V_66 , 0 ) ;
if ( F_39 ( ! V_64 ) ) {
F_26 ( & V_62 -> V_2 , L_11 ) ;
return - V_67 ;
}
V_2 = F_40 ( sizeof( struct V_1 ) , V_68 ) ;
if ( F_39 ( ! V_2 ) )
return - V_69 ;
V_2 -> V_3 = F_41 ( V_64 -> V_70 , F_42 ( V_64 ) ) ;
if ( F_39 ( ! V_2 -> V_3 ) ) {
V_65 = - V_71 ;
goto V_72;
}
V_2 -> V_2 = & V_62 -> V_2 ;
F_43 ( V_62 , V_2 ) ;
V_2 -> V_29 = F_44 ( V_62 , 0 ) ;
if ( V_73 )
V_2 -> V_29 = 0 ;
if ( V_2 -> V_29 ) {
V_65 = F_45 ( V_2 -> V_29 , F_21 , 0 ,
V_62 -> V_74 , V_2 ) ;
if ( F_39 ( V_65 ) )
goto V_75;
F_1 ( V_2 ) ;
} else {
F_46 ( & V_62 -> V_2 , L_12 ) ;
F_4 ( V_2 ) ;
}
V_2 -> V_38 = V_22 ;
F_7 ( V_2 ) ;
V_43 = & V_2 -> V_58 ;
F_47 ( V_43 , V_2 ) ;
V_43 -> V_76 = V_77 ;
V_43 -> V_78 = V_79 ;
F_48 ( V_43 -> V_74 , L_13 , sizeof( V_43 -> V_74 ) ) ;
V_43 -> V_80 = & V_81 ;
V_43 -> V_2 . V_82 = & V_62 -> V_2 ;
V_43 -> V_83 = V_62 -> V_84 ;
V_65 = F_19 ( V_2 ) ;
if ( F_39 ( V_65 ) ) {
F_26 ( & V_62 -> V_2 , L_14 ) ;
goto V_85;
}
V_65 = F_49 ( V_43 ) ;
if ( F_39 ( V_65 ) ) {
F_26 ( & V_62 -> V_2 , L_15 ) ;
goto V_85;
}
return 0 ;
V_85:
if ( V_2 -> V_29 )
F_50 ( V_2 -> V_29 , V_2 ) ;
V_75:
F_51 ( V_2 -> V_3 ) ;
V_72:
F_52 ( V_2 ) ;
F_43 ( V_62 , NULL ) ;
return V_65 ;
}
static int F_53 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_54 ( V_62 ) ;
F_55 ( & V_2 -> V_58 ) ;
if ( V_2 -> V_29 )
F_50 ( V_2 -> V_29 , V_2 ) ;
F_51 ( V_2 -> V_3 ) ;
F_52 ( V_2 ) ;
F_43 ( V_62 , NULL ) ;
return 0 ;
}
