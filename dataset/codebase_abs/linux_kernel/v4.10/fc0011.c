static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 V_5 [ 2 ] = { V_3 , V_4 } ;
struct V_6 V_7 = { . V_8 = V_2 -> V_8 ,
. V_9 = 0 , . V_5 = V_5 , . V_10 = 2 } ;
if ( F_2 ( V_2 -> V_11 , & V_7 , 1 ) != 1 ) {
F_3 ( & V_2 -> V_11 -> V_12 ,
L_1 ,
V_3 , V_4 ) ;
return - V_13 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
T_1 V_14 ;
struct V_6 V_7 [ 2 ] = {
{ . V_8 = V_2 -> V_8 ,
. V_9 = 0 , . V_5 = & V_3 , . V_10 = 1 } ,
{ . V_8 = V_2 -> V_8 ,
. V_9 = V_15 , . V_5 = V_4 ? : & V_14 , . V_10 = 1 } ,
} ;
if ( F_2 ( V_2 -> V_11 , V_7 , 2 ) != 2 ) {
F_3 ( & V_2 -> V_11 -> V_12 ,
L_2 , V_3 ) ;
return - V_13 ;
}
return 0 ;
}
static void F_5 ( struct V_16 * V_17 )
{
F_6 ( V_17 -> V_18 ) ;
V_17 -> V_18 = NULL ;
}
static int F_7 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
int V_19 ;
if ( F_8 ( ! V_17 -> V_20 ) )
return - V_21 ;
V_19 = V_17 -> V_20 ( V_2 -> V_11 , V_22 ,
V_23 , V_2 -> V_8 ) ;
if ( V_19 ) {
F_3 ( & V_2 -> V_11 -> V_12 , L_3 ) ;
return V_19 ;
}
V_19 = V_17 -> V_20 ( V_2 -> V_11 , V_22 ,
V_24 , V_2 -> V_8 ) ;
if ( V_19 ) {
F_3 ( & V_2 -> V_11 -> V_12 , L_4 ) ;
return V_19 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_19 ;
V_19 = F_1 ( V_2 , V_25 , V_26 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_1 ( V_2 , V_25 , V_27 ) ;
if ( V_19 )
return V_19 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 * V_28 )
{
int V_19 ;
V_19 = F_1 ( V_2 , V_25 , V_27 ) ;
if ( V_19 )
return V_19 ;
F_11 ( 10000 , 20000 ) ;
V_19 = F_4 ( V_2 , V_25 , V_28 ) ;
if ( V_19 )
return V_19 ;
return 0 ;
}
static int F_12 ( struct V_16 * V_17 )
{
struct V_29 * V_30 = & V_17 -> V_31 ;
struct V_1 * V_2 = V_17 -> V_18 ;
int V_19 ;
unsigned int V_32 , V_33 ;
T_2 V_34 = V_30 -> V_35 / 1000 ;
T_2 V_36 = V_30 -> V_37 / 1000 ;
T_2 V_38 , V_39 , V_40 , V_41 , V_42 ;
T_1 V_43 , V_44 , V_45 , V_46 ;
T_1 V_47 [ V_48 ] = { } ;
V_47 [ V_49 ] = 0x0F ;
V_47 [ V_50 ] = 0x3E ;
V_47 [ V_51 ] = 0xB8 ;
V_47 [ V_52 ] = 0x80 ;
V_47 [ V_53 ] = 0x04 ;
V_19 = F_1 ( V_2 , V_49 , V_47 [ V_49 ] ) ;
V_19 |= F_1 ( V_2 , V_50 , V_47 [ V_50 ] ) ;
V_19 |= F_1 ( V_2 , V_51 , V_47 [ V_51 ] ) ;
V_19 |= F_1 ( V_2 , V_52 , V_47 [ V_52 ] ) ;
V_19 |= F_1 ( V_2 , V_53 , V_47 [ V_53 ] ) ;
if ( V_19 )
return - V_13 ;
if ( V_34 < 54000 ) {
V_38 = V_34 * 64 ;
V_47 [ V_54 ] = 0x82 ;
} else if ( V_34 < 108000 ) {
V_38 = V_34 * 32 ;
V_47 [ V_54 ] = 0x42 ;
} else if ( V_34 < 216000 ) {
V_38 = V_34 * 16 ;
V_47 [ V_54 ] = 0x22 ;
} else if ( V_34 < 432000 ) {
V_38 = V_34 * 8 ;
V_47 [ V_54 ] = 0x12 ;
} else {
V_38 = V_34 * 4 ;
V_47 [ V_54 ] = 0x0A ;
}
V_41 = V_38 / 18000 ;
F_8 ( V_41 > 0xFF ) ;
V_40 = V_38 - V_41 * 18000 ;
V_40 = ( V_40 << 15 ) / 18000 ;
if ( V_40 >= 16384 )
V_40 += 32786 ;
if ( ! V_40 )
V_39 = 0 ;
else
V_39 = F_13 ( T_2 , V_40 , 512 , 65024 ) ;
V_47 [ V_55 ] = V_39 >> 8 ;
V_47 [ V_56 ] = V_39 ;
V_42 = V_41 ;
if ( V_38 - V_41 * 18000 >= 9000 )
V_42 += 1 ;
V_44 = V_42 / 8 ;
V_43 = V_42 - V_44 * 8 ;
if ( V_43 < 2 ) {
V_44 -= 1 ;
V_43 += 8 ;
}
if ( V_44 > 0x1F ) {
V_44 = 0x1F ;
V_43 = 0xF ;
}
if ( V_43 >= V_44 ) {
F_14 ( & V_2 -> V_11 -> V_12 ,
L_5 ,
( unsigned int ) ( T_1 ) V_43 , ( unsigned int ) ( T_1 ) V_44 ) ;
}
V_47 [ V_57 ] = V_43 ;
V_47 [ V_58 ] = V_44 ;
switch ( V_36 ) {
case 8000 :
break;
case 7000 :
V_47 [ V_59 ] |= V_60 ;
break;
default:
F_14 ( & V_2 -> V_11 -> V_12 , L_6 ,
V_36 ) ;
V_36 = 6000 ;
case 6000 :
V_47 [ V_59 ] |= V_61 ;
break;
}
if ( V_38 < 2320000 ) {
V_45 = 0 ;
V_47 [ V_59 ] &= ~ ( V_62 | V_63 ) ;
} else if ( V_38 < 3080000 ) {
V_45 = 1 ;
V_47 [ V_59 ] &= ~ ( V_62 | V_63 ) ;
V_47 [ V_59 ] |= V_62 ;
} else {
V_45 = 2 ;
V_47 [ V_59 ] &= ~ ( V_62 | V_63 ) ;
V_47 [ V_59 ] |= V_63 ;
}
if ( V_34 < 45000 ) {
V_47 [ V_57 ] = 0x6 ;
V_47 [ V_58 ] = 0x11 ;
}
V_47 [ V_59 ] |= V_64 ;
for ( V_32 = V_57 ; V_32 <= V_59 ; V_32 ++ ) {
V_19 = F_1 ( V_2 , V_32 , V_47 [ V_32 ] ) ;
if ( V_19 )
return V_19 ;
}
V_19 = F_9 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_10 ( V_2 , & V_46 ) ;
if ( V_19 )
return V_19 ;
V_33 = 0 ;
while ( ! ( V_46 & V_65 ) && V_33 < 3 ) {
V_19 = V_17 -> V_20 ( V_2 -> V_11 , V_22 ,
V_24 , V_2 -> V_8 ) ;
if ( V_19 ) {
F_3 ( & V_2 -> V_11 -> V_12 , L_7 ) ;
return V_19 ;
}
V_19 = 0 ;
for ( V_32 = V_57 ; V_32 <= V_59 ; V_32 ++ )
V_19 |= F_1 ( V_2 , V_32 , V_47 [ V_32 ] ) ;
V_19 |= F_1 ( V_2 , V_49 , V_47 [ V_49 ] ) ;
V_19 |= F_1 ( V_2 , V_50 , V_47 [ V_50 ] ) ;
V_19 |= F_1 ( V_2 , V_51 , V_47 [ V_51 ] ) ;
V_19 |= F_1 ( V_2 , V_52 , V_47 [ V_52 ] ) ;
V_19 |= F_1 ( V_2 , V_53 , V_47 [ V_53 ] ) ;
if ( V_19 )
return - V_13 ;
V_19 = F_9 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_10 ( V_2 , & V_46 ) ;
if ( V_19 )
return V_19 ;
V_33 ++ ;
}
if ( ! ( V_46 & V_65 ) ) {
F_3 ( & V_2 -> V_11 -> V_12 ,
L_8 ,
( unsigned int ) V_46 ) ;
return - V_13 ;
}
V_46 &= V_66 ;
switch ( V_45 ) {
default:
F_8 ( 1 ) ;
case 0 :
if ( V_46 < 8 ) {
V_47 [ V_59 ] &= ~ ( V_62 | V_63 ) ;
V_47 [ V_59 ] |= V_62 ;
V_19 = F_1 ( V_2 , V_59 ,
V_47 [ V_59 ] ) ;
if ( V_19 )
return V_19 ;
V_19 = F_9 ( V_2 ) ;
if ( V_19 )
return V_19 ;
} else {
V_47 [ V_59 ] &= ~ ( V_62 | V_63 ) ;
V_19 = F_1 ( V_2 , V_59 ,
V_47 [ V_59 ] ) ;
if ( V_19 )
return V_19 ;
}
break;
case 1 :
if ( V_46 < 5 ) {
V_47 [ V_59 ] &= ~ ( V_62 | V_63 ) ;
V_47 [ V_59 ] |= V_63 ;
V_19 = F_1 ( V_2 , V_59 ,
V_47 [ V_59 ] ) ;
if ( V_19 )
return V_19 ;
V_19 = F_9 ( V_2 ) ;
if ( V_19 )
return V_19 ;
} else if ( V_46 <= 48 ) {
V_47 [ V_59 ] &= ~ ( V_62 | V_63 ) ;
V_47 [ V_59 ] |= V_62 ;
V_19 = F_1 ( V_2 , V_59 ,
V_47 [ V_59 ] ) ;
if ( V_19 )
return V_19 ;
} else {
V_47 [ V_59 ] &= ~ ( V_62 | V_63 ) ;
V_19 = F_1 ( V_2 , V_59 ,
V_47 [ V_59 ] ) ;
if ( V_19 )
return V_19 ;
V_19 = F_9 ( V_2 ) ;
if ( V_19 )
return V_19 ;
}
break;
case 2 :
if ( V_46 > 53 ) {
V_47 [ V_59 ] &= ~ ( V_62 | V_63 ) ;
V_47 [ V_59 ] |= V_62 ;
V_19 = F_1 ( V_2 , V_59 ,
V_47 [ V_59 ] ) ;
if ( V_19 )
return V_19 ;
V_19 = F_9 ( V_2 ) ;
if ( V_19 )
return V_19 ;
} else {
V_47 [ V_59 ] &= ~ ( V_62 | V_63 ) ;
V_47 [ V_59 ] |= V_63 ;
V_19 = F_1 ( V_2 , V_59 ,
V_47 [ V_59 ] ) ;
if ( V_19 )
return V_19 ;
}
break;
}
V_19 = F_10 ( V_2 , NULL ) ;
if ( V_19 )
return V_19 ;
F_11 ( 10000 , 50000 ) ;
V_19 = F_4 ( V_2 , V_53 , & V_47 [ V_53 ] ) ;
if ( V_19 )
return V_19 ;
V_47 [ V_53 ] |= V_67 ;
V_19 = F_1 ( V_2 , V_53 , V_47 [ V_53 ] ) ;
if ( V_19 )
return V_19 ;
V_47 [ V_68 ] = 0xB ;
V_19 = F_1 ( V_2 , V_68 , V_47 [ V_68 ] ) ;
if ( V_19 )
return V_19 ;
F_15 ( & V_2 -> V_11 -> V_12 , L_9 ,
( unsigned int ) V_47 [ V_57 ] ,
( unsigned int ) V_47 [ V_58 ] ,
( unsigned int ) V_47 [ V_55 ] ,
( unsigned int ) V_47 [ V_56 ] ,
( unsigned int ) V_47 [ V_54 ] ,
( unsigned int ) V_47 [ V_59 ] ,
( unsigned int ) V_46 , V_33 ,
( unsigned int ) V_36 ) ;
V_2 -> V_35 = V_30 -> V_35 ;
V_2 -> V_36 = V_30 -> V_37 ;
return 0 ;
}
static int F_16 ( struct V_16 * V_17 , T_2 * V_35 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
* V_35 = V_2 -> V_35 ;
return 0 ;
}
static int F_17 ( struct V_16 * V_17 , T_2 * V_35 )
{
* V_35 = 0 ;
return 0 ;
}
static int F_18 ( struct V_16 * V_17 , T_2 * V_36 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
* V_36 = V_2 -> V_36 ;
return 0 ;
}
struct V_16 * F_19 ( struct V_16 * V_17 ,
struct V_69 * V_11 ,
const struct V_70 * V_71 )
{
struct V_1 * V_2 ;
V_2 = F_20 ( sizeof( struct V_1 ) , V_72 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_11 = V_11 ;
V_2 -> V_8 = V_71 -> V_73 ;
V_17 -> V_18 = V_2 ;
V_17 -> V_74 . V_75 = V_76 ;
F_21 ( & V_2 -> V_11 -> V_12 , L_10 ) ;
return V_17 ;
}
