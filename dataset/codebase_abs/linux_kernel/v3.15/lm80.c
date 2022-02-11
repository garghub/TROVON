static inline unsigned char F_1 ( unsigned V_1 , unsigned div )
{
if ( V_1 == 0 )
return 255 ;
V_1 = F_2 ( V_1 , 1 , 1000000 ) ;
return F_2 ( ( 1350000 + V_1 * div / 2 ) / ( V_1 * div ) , 1 , 254 ) ;
}
static inline long F_3 ( T_1 V_2 )
{
long V_3 ;
V_2 >>= 4 ;
if ( V_2 < 0x0800 )
V_3 = 625 * ( long ) V_2 ;
else
V_3 = ( ( long ) V_2 - 0x01000 ) * 625 ;
return V_3 / 10 ;
}
static T_2 F_4 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
int V_9 = F_5 ( V_7 ) -> V_10 ;
struct V_11 * V_12 = F_6 ( V_5 ) ;
if ( F_7 ( V_12 ) )
return F_8 ( V_12 ) ;
return sprintf ( V_8 , L_1 , F_9 ( V_12 -> V_13 [ V_9 ] ) ) ;
}
static T_2 F_10 ( struct V_4 * V_5 , struct V_6 * V_7 ,
const char * V_8 , T_3 V_14 )
{
int V_9 = F_5 ( V_7 ) -> V_10 ;
struct V_11 * V_12 = F_11 ( V_5 ) ;
struct V_15 * V_16 = V_12 -> V_16 ;
unsigned long V_17 ;
int V_18 = F_12 ( V_8 , 10 , & V_17 ) ;
if ( V_18 < 0 )
return V_18 ;
F_13 ( & V_12 -> V_19 ) ;
V_12 -> V_20 [ V_9 ] = F_1 ( V_17 , F_9 ( V_12 -> V_13 [ V_9 ] ) ) ;
F_14 ( V_16 , F_15 ( V_9 + 1 ) , V_12 -> V_20 [ V_9 ] ) ;
F_16 ( & V_12 -> V_19 ) ;
return V_14 ;
}
static T_2 F_17 ( struct V_4 * V_5 , struct V_6 * V_7 ,
const char * V_8 , T_3 V_14 )
{
int V_9 = F_5 ( V_7 ) -> V_10 ;
struct V_11 * V_12 = F_11 ( V_5 ) ;
struct V_15 * V_16 = V_12 -> V_16 ;
unsigned long V_21 , V_17 ;
T_4 V_22 ;
int V_18 = F_12 ( V_8 , 10 , & V_17 ) ;
if ( V_18 < 0 )
return V_18 ;
F_13 ( & V_12 -> V_19 ) ;
V_21 = F_18 ( V_12 -> V_20 [ V_9 ] ,
F_9 ( V_12 -> V_13 [ V_9 ] ) ) ;
switch ( V_17 ) {
case 1 :
V_12 -> V_13 [ V_9 ] = 0 ;
break;
case 2 :
V_12 -> V_13 [ V_9 ] = 1 ;
break;
case 4 :
V_12 -> V_13 [ V_9 ] = 2 ;
break;
case 8 :
V_12 -> V_13 [ V_9 ] = 3 ;
break;
default:
F_19 ( V_5 ,
L_2 ,
V_17 ) ;
F_16 ( & V_12 -> V_19 ) ;
return - V_23 ;
}
V_22 = ( F_20 ( V_16 , V_24 ) & ~ ( 3 << ( 2 * ( V_9 + 1 ) ) ) )
| ( V_12 -> V_13 [ V_9 ] << ( 2 * ( V_9 + 1 ) ) ) ;
F_14 ( V_16 , V_24 , V_22 ) ;
V_12 -> V_20 [ V_9 ] = F_1 ( V_21 , F_9 ( V_12 -> V_13 [ V_9 ] ) ) ;
F_14 ( V_16 , F_15 ( V_9 + 1 ) , V_12 -> V_20 [ V_9 ] ) ;
F_16 ( & V_12 -> V_19 ) ;
return V_14 ;
}
static T_2 F_21 ( struct V_4 * V_5 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_11 * V_12 = F_6 ( V_5 ) ;
if ( F_7 ( V_12 ) )
return F_8 ( V_12 ) ;
return sprintf ( V_8 , L_3 , F_3 ( V_12 -> V_2 ) ) ;
}
static T_2 F_22 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_11 * V_12 = F_6 ( V_5 ) ;
if ( F_7 ( V_12 ) )
return F_8 ( V_12 ) ;
return sprintf ( V_8 , L_4 , V_12 -> V_25 ) ;
}
static T_2 F_23 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
int V_26 = F_5 ( V_7 ) -> V_10 ;
struct V_11 * V_12 = F_6 ( V_5 ) ;
if ( F_7 ( V_12 ) )
return F_8 ( V_12 ) ;
return sprintf ( V_8 , L_4 , ( V_12 -> V_25 >> V_26 ) & 1 ) ;
}
static int F_24 ( struct V_15 * V_16 , struct V_27 * V_28 )
{
struct V_29 * V_30 = V_16 -> V_30 ;
int V_31 , V_32 , V_33 , V_34 ;
const char * V_35 = NULL ;
if ( ! F_25 ( V_30 , V_36 ) )
return - V_37 ;
if ( ( F_20 ( V_16 , V_38 ) & 0xc0 )
|| ( F_20 ( V_16 , V_39 ) & 0x80 ) )
return - V_37 ;
V_33 = F_20 ( V_16 , V_40 ) ;
V_34 = F_20 ( V_16 , V_41 ) ;
if ( V_33 == 0x01 && V_34 == 0x08 ) {
if ( F_20 ( V_16 , V_42 ) & 0xfe )
return - V_37 ;
V_35 = L_5 ;
} else {
for ( V_31 = 0x2a ; V_31 <= 0x3d ; V_31 ++ ) {
V_32 = F_26 ( V_16 , V_31 ) ;
if ( ( F_26 ( V_16 , V_31 + 0x40 ) != V_32 )
|| ( F_26 ( V_16 , V_31 + 0x80 ) != V_32 )
|| ( F_26 ( V_16 , V_31 + 0xc0 ) != V_32 ) )
return - V_37 ;
}
V_35 = L_6 ;
}
F_27 ( V_28 -> type , V_35 , V_43 ) ;
return 0 ;
}
static int F_28 ( struct V_15 * V_16 ,
const struct V_44 * V_45 )
{
struct V_4 * V_5 = & V_16 -> V_5 ;
struct V_4 * V_46 ;
struct V_11 * V_12 ;
V_12 = F_29 ( V_5 , sizeof( struct V_11 ) , V_47 ) ;
if ( ! V_12 )
return - V_48 ;
V_12 -> V_16 = V_16 ;
F_30 ( & V_12 -> V_19 ) ;
F_31 ( V_16 ) ;
V_12 -> V_20 [ 0 ] = F_20 ( V_16 , F_15 ( 1 ) ) ;
V_12 -> V_20 [ 1 ] = F_20 ( V_16 , F_15 ( 2 ) ) ;
V_46 = F_32 ( V_5 , V_16 -> V_35 ,
V_12 , V_49 ) ;
return F_33 ( V_46 ) ;
}
static int F_20 ( struct V_15 * V_16 , T_4 V_22 )
{
return F_26 ( V_16 , V_22 ) ;
}
static int F_14 ( struct V_15 * V_16 , T_4 V_22 , T_4 V_50 )
{
return F_34 ( V_16 , V_22 , V_50 ) ;
}
static void F_31 ( struct V_15 * V_16 )
{
F_14 ( V_16 , V_39 , 0x80 ) ;
F_14 ( V_16 , V_51 , 0x08 ) ;
F_14 ( V_16 , V_39 , 0x01 ) ;
}
static struct V_11 * F_6 ( struct V_4 * V_5 )
{
struct V_11 * V_12 = F_11 ( V_5 ) ;
struct V_15 * V_16 = V_12 -> V_16 ;
int V_31 ;
int V_52 ;
int V_53 ;
struct V_11 * V_54 = V_12 ;
F_13 ( & V_12 -> V_19 ) ;
if ( V_12 -> error )
F_31 ( V_16 ) ;
if ( F_35 ( V_55 , V_12 -> V_56 + 2 * V_57 ) || ! V_12 -> V_58 ) {
F_36 ( V_5 , L_7 ) ;
for ( V_31 = 0 ; V_31 <= 6 ; V_31 ++ ) {
V_52 = F_20 ( V_16 , F_37 ( V_31 ) ) ;
if ( V_52 < 0 )
goto abort;
V_12 -> V_59 [ V_31 ] = V_52 ;
V_52 = F_20 ( V_16 , F_38 ( V_31 ) ) ;
if ( V_52 < 0 )
goto abort;
V_12 -> V_60 [ V_31 ] = V_52 ;
V_52 = F_20 ( V_16 , F_39 ( V_31 ) ) ;
if ( V_52 < 0 )
goto abort;
V_12 -> V_61 [ V_31 ] = V_52 ;
}
V_52 = F_20 ( V_16 , V_62 ) ;
if ( V_52 < 0 )
goto abort;
V_12 -> V_63 [ 0 ] = V_52 ;
V_52 = F_20 ( V_16 , F_15 ( 1 ) ) ;
if ( V_52 < 0 )
goto abort;
V_12 -> V_20 [ 0 ] = V_52 ;
V_52 = F_20 ( V_16 , V_64 ) ;
if ( V_52 < 0 )
goto abort;
V_12 -> V_63 [ 1 ] = V_52 ;
V_52 = F_20 ( V_16 , F_15 ( 2 ) ) ;
if ( V_52 < 0 )
goto abort;
V_12 -> V_20 [ 1 ] = V_52 ;
V_53 = V_52 = F_20 ( V_16 , V_65 ) ;
if ( V_52 < 0 )
goto abort;
V_52 = F_20 ( V_16 , V_51 ) ;
if ( V_52 < 0 )
goto abort;
V_12 -> V_2 = ( V_53 << 8 ) | ( V_52 & 0xf0 ) ;
V_52 = F_20 ( V_16 , V_66 ) ;
if ( V_52 < 0 )
goto abort;
V_12 -> V_67 = V_52 ;
V_52 = F_20 ( V_16 , V_68 ) ;
if ( V_52 < 0 )
goto abort;
V_12 -> V_69 = V_52 ;
V_52 = F_20 ( V_16 , V_70 ) ;
if ( V_52 < 0 )
goto abort;
V_12 -> V_71 = V_52 ;
V_52 = F_20 ( V_16 , V_72 ) ;
if ( V_52 < 0 )
goto abort;
V_12 -> V_73 = V_52 ;
V_52 = F_20 ( V_16 , V_24 ) ;
if ( V_52 < 0 )
goto abort;
V_12 -> V_13 [ 0 ] = ( V_52 >> 2 ) & 0x03 ;
V_12 -> V_13 [ 1 ] = ( V_52 >> 4 ) & 0x03 ;
V_53 = V_52 = F_20 ( V_16 , V_74 ) ;
if ( V_52 < 0 )
goto abort;
V_52 = F_20 ( V_16 , V_38 ) ;
if ( V_52 < 0 )
goto abort;
V_12 -> V_25 = V_53 + ( V_52 << 8 ) ;
V_12 -> V_56 = V_55 ;
V_12 -> V_58 = 1 ;
V_12 -> error = 0 ;
}
goto V_75;
abort:
V_54 = F_40 ( V_52 ) ;
V_12 -> V_58 = 0 ;
V_12 -> error = 1 ;
V_75:
F_16 ( & V_12 -> V_19 ) ;
return V_54 ;
}
