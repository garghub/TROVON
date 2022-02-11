static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_2 V_4 ;
V_4 = V_5 ;
F_2 ( 1 , V_6 ) ;
V_3 = F_3 ( V_7 ) ;
F_2 ( V_3 | 1 << 5 , V_7 ) ;
F_4 ( 300 ) ;
F_5 ( V_4 , V_8 ) ;
F_6 ( V_4 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
F_1 ( V_2 ) ;
F_8 ( V_2 , & V_10 -> V_12 ) ;
F_9 ( V_2 , & V_10 -> V_12 ) ;
if ( F_6 ( V_13 ) & V_14 )
F_10 ( V_2 , & V_10 -> V_12 , V_13 ) ;
if ( F_6 ( V_15 ) & V_14 )
F_10 ( V_2 , & V_10 -> V_12 , V_15 ) ;
return 0 ;
}
static int F_11 ( struct V_16 * V_17 )
{
return V_18 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned long V_19 ;
T_3 V_20 ;
T_4 V_21 ;
T_4 V_22 ;
if ( ! V_10 -> V_23 ) {
F_13 ( V_2 -> V_2 , L_1 ) ;
return - V_24 ;
}
V_20 = V_10 -> V_23 -> V_25 ;
V_22 = V_26 ;
V_19 = V_10 -> V_27 ;
V_21 = ( V_19 * V_28 ) / V_29 ;
V_21 *= V_22 ;
V_21 /= V_20 ;
V_21 /= V_22 ;
if ( V_21 > ( unsigned long long ) V_30 ||
V_21 < ( unsigned long long ) V_31 )
return - V_32 ;
else {
}
return 0 ;
}
static int F_14 ( struct V_16 * V_17 )
{
int V_33 = V_17 -> V_34 . V_35 ;
if ( V_33 < 1 )
V_33 = 1 ;
V_18 = V_33 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_36 ;
struct V_37 V_34 ;
memset ( & V_34 , 0 , sizeof( struct V_37 ) ) ;
V_34 . V_38 = 100 ;
V_34 . type = V_39 ;
V_40 = F_16 ( L_2 ,
NULL , ( void * ) V_2 , & V_41 , & V_34 ) ;
if ( F_17 ( V_40 ) )
return F_18 ( V_40 ) ;
V_36 = F_12 ( V_2 ) ;
if ( V_36 < 0 ) {
F_19 ( V_40 ) ;
V_40 = NULL ;
return V_36 ;
}
V_40 -> V_34 . V_35 = 100 ;
V_40 -> V_34 . V_38 = 100 ;
F_20 ( V_40 ) ;
V_10 -> V_16 = V_40 ;
return 0 ;
}
static inline T_2 F_21 ( T_5 V_42 , T_5 V_43 )
{
int V_44 = ( 0x10 << 24 ) | ( V_42 << 16 ) | ( V_43 << 8 ) ;
T_4 V_45 = 0 ;
struct V_46 * V_47 = F_22 ( 0 , 0 ) ;
F_23 ( V_47 , 0xD0 , V_44 ) ;
F_24 ( V_47 , 0xD4 , & V_45 ) ;
F_25 ( V_47 ) ;
return V_45 ;
}
static inline void F_26 ( T_5 V_42 , T_5 V_43 , T_2 V_21 )
{
int V_44 = ( 0x11 << 24 ) | ( V_42 << 16 ) | ( V_43 << 8 ) | 0xF0 ;
struct V_46 * V_47 = F_22 ( 0 , 0 ) ;
F_23 ( V_47 , 0xD4 , V_21 ) ;
F_23 ( V_47 , 0xD0 , V_44 ) ;
F_25 ( V_47 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
T_2 V_48 ;
int V_49 ;
V_10 -> V_50 = F_21 ( V_51 ,
V_52 ) & 0xFFFF ;
V_10 -> V_53 = F_21 ( V_51 ,
V_54 ) & 0xFFFF ;
V_48 = F_28 ( V_10 -> V_50 + V_55 ) ;
V_48 &= ~ V_56 ;
F_29 ( V_48 , V_10 -> V_50 + V_55 ) ;
for ( V_49 = 0 ; V_49 < 5 ; V_49 ++ ) {
T_2 V_57 = F_28 ( V_10 -> V_50 + V_58 ) ;
if ( ( V_57 & V_56 ) == 0 )
break;
F_4 ( 10 ) ;
}
V_48 = F_28 ( V_10 -> V_53 + V_59 ) ;
V_48 &= ~ V_60 ;
F_29 ( V_48 , V_10 -> V_53 + V_59 ) ;
for ( V_49 = 0 ; V_49 < 5 ; V_49 ++ ) {
T_2 V_57 = F_28 ( V_10 -> V_53 + V_61 ) ;
if ( ( V_57 & V_62 ) == 0 )
break;
F_4 ( 10 ) ;
}
}
static int F_30 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_34 ( struct V_1 * V_2 )
{
T_4 clock ;
struct V_46 * V_47 = F_22 ( 0 , 0 ) ;
struct V_9 * V_10 = V_2 -> V_11 ;
F_23 ( V_47 , 0xD0 , 0xD0050300 ) ;
F_24 ( V_47 , 0xD4 , & clock ) ;
F_25 ( V_47 ) ;
switch ( clock & 0x07 ) {
case 0 :
V_10 -> V_27 = 100 ;
break;
case 1 :
V_10 -> V_27 = 133 ;
break;
case 2 :
V_10 -> V_27 = 150 ;
break;
case 3 :
V_10 -> V_27 = 178 ;
break;
case 4 :
V_10 -> V_27 = 200 ;
break;
case 5 :
case 6 :
case 7 :
V_10 -> V_27 = 266 ;
default:
V_10 -> V_27 = 0 ;
}
}
static int F_35 ( struct V_1 * V_2 )
{
F_34 ( V_2 ) ;
F_36 ( V_2 ) ;
F_37 ( V_2 ) ;
F_5 ( V_63 , 0 ) ;
F_5 ( V_64 , F_6 ( V_64 ) ) ;
return 0 ;
}
