static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 = V_5 ;
while ( F_2 ( V_2 -> V_6 + V_7 ) != V_3 ) {
V_4 -- ;
if ( V_4 == 0 )
return - V_8 ;
if ( V_4 <= V_9 )
F_3 ( 0 ) ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_4 = V_10 ;
if ( V_2 -> V_11 )
return 0 ;
F_5 ( 0x00 , V_2 -> V_6 + V_7 ) ;
if ( F_1 ( V_2 , V_12 ) ) {
F_6 ( 1 ,
L_1 ) ;
return - V_13 ;
}
while ( F_2 ( V_2 -> V_6 + V_14 ) != 0xAC ) {
V_4 -- ;
if ( V_4 == 0 ) {
F_6 ( 1 ,
L_2 ) ;
return - V_13 ;
}
F_3 ( 0 ) ;
}
V_4 = V_10 ;
while ( F_2 ( V_2 -> V_6 + V_7 ) != V_15 ) {
V_4 -- ;
if ( V_4 == 0 ) {
F_6 ( 1 ,
L_3 ) ;
return - V_13 ;
}
F_3 ( 0 ) ;
}
V_2 -> V_11 = 1 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
T_1 V_16 , T_1 V_17 , int V_18 )
{
int V_19 = V_18 ;
for (; ; ) {
if ( F_4 ( V_2 ) != 0 )
return - V_13 ;
F_5 ( V_16 , V_2 -> V_6 + V_7 ) ;
V_2 -> V_11 = 0 ;
if ( F_1 ( V_2 , V_15 ) ) {
if ( V_18 ) {
F_6 ( 3 , L_4
L_5
L_6 , V_18 ) ;
F_8 ( V_20 ) ;
F_9 ( V_21 ) ;
V_18 -- ;
continue;
}
if ( V_19 )
F_6 ( 1 , L_4
L_7
L_8 , ( int ) V_16 ) ;
return - V_8 ;
}
F_5 ( V_17 , V_2 -> V_6 + V_14 ) ;
return 0 ;
}
}
static int F_10 ( struct V_1 * V_2 ,
T_1 V_16 , T_1 V_17 , T_1 * V_22 , int V_23 , int V_18 )
{
int V_24 ;
V_24 = F_7 ( V_2 , V_16 , V_17 , V_18 ) ;
if ( V_24 )
return V_24 ;
for ( V_24 = 0 ; V_24 < V_23 ; V_24 ++ ) {
if ( F_1 ( V_2 , V_25 ) ) {
F_6 ( V_18 ? 1 : 3 ,
L_9
L_10 ,
( int ) V_16 , ( int ) V_17 ) ;
break;
}
V_22 [ V_24 ] = F_11 ( V_2 -> V_6 + V_14 ) ;
}
F_4 ( V_2 ) ;
return V_24 ;
}
static int F_12 ( struct V_1 * V_2 ,
T_1 V_16 , T_1 V_17 , T_1 * V_22 , int V_23 )
{
int V_24 , V_4 = V_10 ;
V_24 = F_7 ( V_2 , V_16 , V_17 ,
V_26 ) ;
if ( V_24 )
return V_24 ;
for ( V_24 = 0 ; V_24 < V_23 ; V_24 ++ ) {
if ( F_1 ( V_2 , V_27 ) ) {
F_6 ( 1 , L_9
L_11 ,
( int ) V_16 , ( int ) V_17 ) ;
break;
}
F_5 ( V_22 [ V_24 ] , V_2 -> V_6 + V_14 ) ;
}
if ( F_1 ( V_2 , V_25 ) ) {
F_6 ( 1 , L_12
L_13 , ( int ) V_16 ,
( int ) V_17 ) ;
return - V_13 ;
}
while ( F_2 ( V_2 -> V_6 + V_14 ) != 0xAC ) {
V_4 -- ;
if ( V_4 == 0 ) {
F_6 ( 1 , L_14
L_15 ,
( int ) V_16 , ( int ) V_17 ) ;
return - V_13 ;
}
F_3 ( 0 ) ;
}
F_4 ( V_2 ) ;
return V_24 ;
}
static int T_2
F_13 ( struct V_1 * V_2 ,
T_1 V_17 )
{
T_1 V_28 , V_29 , V_22 [ 3 ] ;
int V_24 , V_30 = - V_31 ;
if ( V_32 [ V_17 ] >= V_33 &&
V_32 [ V_17 ] <= V_34 ) {
F_6 ( 2 , L_16
L_17 ,
V_32 [ V_17 ] , ( int ) V_17 ) ;
return V_32 [ V_17 ] ;
}
if ( F_10 ( V_2 , V_35 , V_17 , & V_28 ,
1 , V_26 ) != 1 )
return - V_31 ;
if ( ( V_28 < 10u ) || ( V_28 > 250u ) ) {
F_14 ( L_18
L_19 ,
( int ) V_17 , ( int ) V_28 ) ;
return V_34 ;
}
F_6 ( 2 , L_20 , ( int ) V_17 ) ;
if ( V_28 <= 240u ) {
V_22 [ 0 ] = V_36 ;
V_22 [ 1 ] = 245 ;
V_22 [ 2 ] = 250 ;
V_29 = V_37 ;
} else {
V_22 [ 0 ] = V_38 ;
V_22 [ 1 ] = 5 ;
V_22 [ 2 ] = 10 ;
V_29 = V_39 ;
}
if ( F_12 ( V_2 , V_35 + 2 , V_17 ,
V_22 , 3 ) != 3 )
goto V_40;
F_8 ( V_20 ) ;
F_9 ( V_41 / 50 ) ;
if ( F_10 ( V_2 , V_42 , 0 , V_22 , 3 ,
V_26 ) != 3 )
goto V_40;
if ( V_22 [ V_17 / 8 ] & ( 0x01 << ( V_17 % 8 ) ) ) {
if ( F_10 ( V_2 , V_35 + 1 ,
V_17 , V_22 , 3 ,
V_26 ) != 3 )
goto V_40;
if ( V_22 [ 0 ] & V_29 ) {
F_6 ( 2 , L_21 ) ;
V_30 = V_33 ;
goto V_40;
} else
F_6 ( 2 , L_22
L_23 ) ;
} else
F_6 ( 2 , L_24
L_25 ) ;
V_22 [ 0 ] = V_43 ;
V_22 [ 1 ] = 5 ;
V_22 [ 2 ] = 10 ;
if ( F_12 ( V_2 , V_35 + 2 , V_17 ,
V_22 , 3 ) != 3 )
goto V_40;
F_8 ( V_20 ) ;
F_9 ( V_41 / 20 ) ;
if ( F_10 ( V_2 , V_42 , 0 , V_22 , 3 ,
V_26 ) != 3 )
goto V_40;
if ( V_22 [ V_17 / 8 ] & ( 0x01 << ( V_17 % 8 ) ) ) {
if ( F_10 ( V_2 , V_35 + 1 ,
V_17 , V_22 , 3 ,
V_26 ) != 3 )
goto V_40;
if ( V_22 [ 0 ] & V_44 ) {
F_6 ( 2 , L_26 ) ;
V_30 = V_45 ;
goto V_40;
} else
F_6 ( 2 , L_27
L_28 ) ;
} else
F_6 ( 2 , L_29
L_25 ) ;
V_30 = V_34 ;
V_40:
for ( V_24 = 0 ; V_24 < 3 ; V_24 ++ )
if ( F_12 ( V_2 , V_35 + 2 ,
V_17 , V_2 -> V_46 [ V_17 ] ,
3 ) == 3 )
break;
if ( V_24 == 3 ) {
F_15 ( L_30 ,
V_47 , V_48 ) ;
return - V_31 ;
}
return V_30 ;
}
static void T_2
F_16 ( struct V_1 * V_2 )
{
int V_24 ;
if ( V_49 > 0 && V_49 <= V_50 ) {
V_2 -> V_51 = V_49 ;
F_6 ( 2 , L_31
L_32 ,
( int ) V_2 -> V_51 ) ;
return;
}
F_6 ( 2 , L_33 ) ;
for ( V_24 = 0 ; V_24 < V_50 ; V_24 ++ ) {
if ( V_2 -> V_52 [ V_24 ] [ 0 ] & ~ 0xC9 ) {
F_6 ( 2 , L_34
L_35 ,
V_24 , ( unsigned int ) V_2 -> V_52 [ V_24 ] [ 0 ] ) ;
break;
}
if ( V_2 -> V_52 [ V_24 ] [ 1 ] <
V_53 ) {
F_6 ( 2 , L_34
L_36
L_37 , V_24 ,
( int ) V_2 -> V_52 [ V_24 ] [ 1 ] ,
( int ) V_53 ) ;
break;
}
if ( V_2 -> V_52 [ V_24 ] [ 1 ] >
V_54 ) {
F_6 ( 2 , L_34
L_36
L_38 , V_24 ,
( int ) V_2 -> V_52 [ V_24 ] [ 1 ] ,
( int ) V_54 ) ;
break;
}
}
V_2 -> V_51 = V_24 ;
F_6 ( 2 , L_39 ,
( int ) V_2 -> V_51 ) ;
}
static void T_2
F_17 ( struct V_1 * V_2 )
{
int V_24 , V_55 ;
if ( V_56 > 0 && V_56 <= V_57 ) {
V_2 -> V_56 = V_56 ;
F_6 ( 2 , L_40
L_41 , ( int ) V_2 -> V_56 ) ;
return;
}
F_6 ( 2 , L_42 ) ;
for ( V_24 = 0 ; V_24 < V_57 ; V_24 ++ ) {
if ( V_2 -> V_58 [ V_24 ] [ 0 ] & ~ 0x8F ) {
F_6 ( 2 , L_43
L_44 ,
V_24 , ( unsigned int ) V_2 -> V_58 [ V_24 ] [ 0 ] ) ;
break;
}
for ( V_55 = 0 ; V_55 < V_2 -> V_59 [ V_45 ] ;
V_55 ++ ) {
if ( V_2 -> V_60 [ V_45 ] [ V_55 ] ==
( V_2 -> V_58 [ V_24 ] [ 0 ] & 0x0F ) )
break;
}
if ( V_55 == V_2 -> V_59 [ V_45 ] ) {
F_6 ( 2 , L_43
L_45
L_46 , V_24 ,
V_2 -> V_58 [ V_24 ] [ 0 ] & 0x0F ) ;
break;
}
for ( V_55 = 1 ; V_55 < 5 ; V_55 ++ ) {
T_1 V_61 ;
if ( ( V_24 == 0 ) && ( ( V_55 == 1 ) || ( V_55 == 2 ) ) )
V_61 = 77 ;
else
V_61 = V_62 [ V_55 ] ;
if ( V_2 -> V_58 [ V_24 ] [ V_55 ] < V_61 ) {
F_6 ( 2 , L_47
L_48
L_49
L_50 , V_24 , V_55 ,
( int ) V_2 -> V_58 [ V_24 ] [ V_55 ] ,
( int ) V_61 ) ;
goto V_63;
}
if ( V_2 -> V_58 [ V_24 ] [ V_55 ] > V_64 [ V_55 ] ) {
F_6 ( 2 , L_47
L_48
L_51
L_50 , V_24 , V_55 ,
( int ) V_2 -> V_58 [ V_24 ] [ V_55 ] ,
( int ) V_64 [ V_55 ] ) ;
goto V_63;
}
}
if ( V_2 -> V_58 [ V_24 ] [ 1 ] >= V_2 -> V_58 [ V_24 ] [ 2 ] ) {
F_6 ( 2 , L_43
L_52
L_53 , V_24 ,
( int ) V_2 -> V_58 [ V_24 ] [ 1 ] ,
( int ) V_2 -> V_58 [ V_24 ] [ 2 ] ) ;
break;
}
if ( V_2 -> V_58 [ V_24 ] [ 3 ] >= V_2 -> V_58 [ V_24 ] [ 4 ] ) {
F_6 ( 2 , L_43
L_54
L_55 , V_24 ,
( int ) V_2 -> V_58 [ V_24 ] [ 3 ] ,
( int ) V_2 -> V_58 [ V_24 ] [ 4 ] ) ;
break;
}
}
V_63:
V_2 -> V_56 = V_24 ;
F_6 ( 2 , L_56 , ( int ) V_2 -> V_56 ) ;
}
static T_3 F_18 ( struct V_65 * V_66 ,
struct V_67 * V_68 , char * V_22 )
{
struct V_69 * V_70 = F_19 ( V_68 ) ;
struct V_1 * V_2 = F_20 ( V_66 ) ;
if ( ! V_2 )
return - V_13 ;
return sprintf ( V_22 , L_57 , ( V_2 -> V_71 [ V_70 -> V_72 ] *
V_2 -> V_73 [ V_70 -> V_72 ] + 128 ) / 255 ) ;
}
static T_3 F_21 ( struct V_65 * V_66 ,
struct V_67 * V_68 , char * V_22 )
{
struct V_69 * V_70 = F_19 ( V_68 ) ;
struct V_1 * V_2 = F_22 ( V_66 ) ;
return sprintf ( V_22 , L_57 ,
( V_2 -> V_46 [ V_70 -> V_72 ] [ V_70 -> V_74 ] *
V_2 -> V_73 [ V_70 -> V_72 ] + 128 ) / 255 ) ;
}
static T_3 F_23 ( struct V_65 * V_66 ,
struct V_67 * V_68 , char * V_22 )
{
struct V_69 * V_70 = F_19 ( V_68 ) ;
struct V_1 * V_2 = F_20 ( V_66 ) ;
if ( ! V_2 )
return - V_13 ;
return sprintf ( V_22 , L_57 , ( V_2 -> V_75 [ V_70 -> V_72 ] *
V_76 + 128 ) / 255 ) ;
}
static T_3 F_24 ( struct V_65 * V_66 ,
struct V_67 * V_68 , char * V_22 )
{
struct V_69 * V_70 = F_19 ( V_68 ) ;
struct V_1 * V_2 = F_22 ( V_66 ) ;
return sprintf ( V_22 , L_57 ,
( V_2 -> V_52 [ V_70 -> V_72 ] [ V_70 -> V_74 ] *
V_76 + 128 ) / 255 ) ;
}
static T_3 F_25 ( struct V_65 * V_66 , struct V_67
* V_68 , const char * V_22 , T_4 V_23 )
{
struct V_69 * V_70 = F_19 ( V_68 ) ;
struct V_1 * V_2 = F_22 ( V_66 ) ;
unsigned long V_28 ;
T_3 V_30 ;
V_30 = F_26 ( V_22 , 10 , & V_28 ) ;
if ( V_30 )
return V_30 ;
V_30 = V_23 ;
V_28 = ( V_28 * 255 + V_2 -> V_73 [ V_70 -> V_72 ] / 2 ) /
V_2 -> V_73 [ V_70 -> V_72 ] ;
if ( V_28 > 255 )
return - V_77 ;
F_27 ( & V_2 -> V_78 ) ;
if ( V_2 -> V_46 [ V_70 -> V_72 ] [ V_70 -> V_74 ] != V_28 ) {
T_1 V_79 = V_2 -> V_46 [ V_70 -> V_72 ] [ V_70 -> V_74 ] ;
V_2 -> V_46 [ V_70 -> V_72 ] [ V_70 -> V_74 ] = V_28 ;
if ( F_12 ( V_2 , V_35 + 2 ,
V_70 -> V_72 , V_2 -> V_46 [ V_70 -> V_72 ] ,
3 ) <= V_70 -> V_74 ) {
V_2 -> V_46 [ V_70 -> V_72 ] [ V_70 -> V_74 ] = V_79 ;
V_30 = - V_13 ;
}
}
F_28 ( & V_2 -> V_78 ) ;
return V_30 ;
}
static T_3 F_29 ( struct V_65 * V_66 , struct V_67
* V_68 , const char * V_22 , T_4 V_23 )
{
struct V_69 * V_70 = F_19 ( V_68 ) ;
struct V_1 * V_2 = F_22 ( V_66 ) ;
unsigned long V_28 ;
T_3 V_30 ;
V_30 = F_26 ( V_22 , 10 , & V_28 ) ;
if ( V_30 )
return V_30 ;
V_30 = V_23 ;
V_28 = ( V_28 * 255 + V_76 / 2 ) / V_76 ;
if ( V_28 < V_53 ||
V_28 > V_54 )
return - V_77 ;
F_27 ( & V_2 -> V_78 ) ;
if ( V_2 -> V_52 [ V_70 -> V_72 ] [ V_70 -> V_74 ] != V_28 ) {
T_1 V_79 = V_2 -> V_52 [ V_70 -> V_72 ] [ V_70 -> V_74 ] ;
V_2 -> V_52 [ V_70 -> V_72 ] [ V_70 -> V_74 ] = V_28 ;
if ( F_12 ( V_2 , V_80 + 2 ,
V_70 -> V_72 , V_2 -> V_52 [ V_70 -> V_72 ] ,
2 ) <= V_70 -> V_74 ) {
V_2 -> V_52 [ V_70 -> V_72 ] [ V_70 -> V_74 ] = V_79 ;
V_30 = - V_13 ;
}
}
F_28 ( & V_2 -> V_78 ) ;
return V_30 ;
}
static T_3 F_30 ( struct V_65 * V_66 ,
struct V_67 * V_68 , char * V_22 )
{
struct V_69 * V_70 = F_19 ( V_68 ) ;
struct V_1 * V_2 = F_20 ( V_66 ) ;
if ( ! V_2 )
return - V_13 ;
if ( ( V_2 -> V_81 [ V_70 -> V_72 / 8 ] & ( 0x01 << ( V_70 -> V_72 % 8 ) ) ) &&
( V_2 -> V_46 [ V_70 -> V_72 ] [ 0 ] & V_70 -> V_74 ) )
return sprintf ( V_22 , L_58 ) ;
else
return sprintf ( V_22 , L_59 ) ;
}
static T_3 F_31 ( struct V_65 * V_66 ,
struct V_67 * V_68 , char * V_22 )
{
struct V_69 * V_70 = F_19 ( V_68 ) ;
struct V_1 * V_2 = F_20 ( V_66 ) ;
if ( ! V_2 )
return - V_13 ;
if ( V_2 -> V_81 [ 2 ] & ( 0x01 << V_70 -> V_72 ) )
return sprintf ( V_22 , L_58 ) ;
else
return sprintf ( V_22 , L_59 ) ;
}
static T_3 F_32 ( struct V_65 * V_66 ,
struct V_67 * V_68 , char * V_22 )
{
struct V_69 * V_70 = F_19 ( V_68 ) ;
struct V_1 * V_2 = F_22 ( V_66 ) ;
if ( V_2 -> V_46 [ V_70 -> V_72 ] [ 0 ] & V_70 -> V_74 )
return sprintf ( V_22 , L_58 ) ;
else
return sprintf ( V_22 , L_59 ) ;
}
static T_3 F_33 ( struct V_65 * V_66 ,
struct V_67 * V_68 , char * V_22 )
{
struct V_69 * V_70 = F_19 ( V_68 ) ;
struct V_1 * V_2 = F_22 ( V_66 ) ;
if ( V_2 -> V_52 [ V_70 -> V_72 ] [ 0 ] & V_70 -> V_74 )
return sprintf ( V_22 , L_58 ) ;
else
return sprintf ( V_22 , L_59 ) ;
}
static T_3 F_34 ( struct V_65 * V_66 ,
struct V_67 * V_68 , const char * V_22 , T_4 V_23 )
{
struct V_69 * V_70 = F_19 ( V_68 ) ;
struct V_1 * V_2 = F_22 ( V_66 ) ;
T_3 V_30 ;
T_1 V_79 ;
unsigned long V_82 ;
V_30 = F_26 ( V_22 , 10 , & V_82 ) ;
if ( V_30 )
return V_30 ;
V_30 = V_23 ;
F_27 ( & V_2 -> V_78 ) ;
V_79 = V_2 -> V_46 [ V_70 -> V_72 ] [ 0 ] ;
if ( V_82 )
V_2 -> V_46 [ V_70 -> V_72 ] [ 0 ] |= V_70 -> V_74 ;
else
V_2 -> V_46 [ V_70 -> V_72 ] [ 0 ] &= ~ V_70 -> V_74 ;
if ( ( V_2 -> V_46 [ V_70 -> V_72 ] [ 0 ] != V_79 ) &&
( F_12 ( V_2 ,
V_35 + 2 , V_70 -> V_72 ,
V_2 -> V_46 [ V_70 -> V_72 ] , 3 ) < 1 ) ) {
V_2 -> V_46 [ V_70 -> V_72 ] [ 0 ] = V_79 ;
V_30 = - V_13 ;
}
F_28 ( & V_2 -> V_78 ) ;
return V_30 ;
}
static T_3 F_35 ( struct V_65 * V_66 ,
struct V_67 * V_68 , const char * V_22 , T_4 V_23 )
{
struct V_69 * V_70 = F_19 ( V_68 ) ;
struct V_1 * V_2 = F_22 ( V_66 ) ;
T_3 V_30 ;
T_1 V_79 ;
unsigned long V_82 ;
V_30 = F_26 ( V_22 , 10 , & V_82 ) ;
if ( V_30 )
return V_30 ;
V_30 = V_23 ;
F_27 ( & V_2 -> V_78 ) ;
V_79 = V_2 -> V_52 [ V_70 -> V_72 ] [ 0 ] ;
if ( V_82 )
V_2 -> V_52 [ V_70 -> V_72 ] [ 0 ] |= V_70 -> V_74 ;
else
V_2 -> V_52 [ V_70 -> V_72 ] [ 0 ] &= ~ V_70 -> V_74 ;
if ( ( V_2 -> V_52 [ V_70 -> V_72 ] [ 0 ] != V_79 ) &&
( F_12 ( V_2 ,
V_80 + 2 , V_70 -> V_72 ,
V_2 -> V_52 [ V_70 -> V_72 ] , 2 ) < 1 ) ) {
V_2 -> V_52 [ V_70 -> V_72 ] [ 0 ] = V_79 ;
V_30 = - V_13 ;
}
F_28 ( & V_2 -> V_78 ) ;
return V_30 ;
}
static T_3 F_36 ( struct V_65 * V_66 ,
struct V_67 * V_68 , char * V_22 )
{
struct V_69 * V_70 = F_19 ( V_68 ) ;
struct V_1 * V_2 = F_22 ( V_66 ) ;
return sprintf ( V_22 , L_57 , V_2 -> V_58 [ V_70 -> V_72 ] [ V_70 -> V_74 ] *
V_83 [ V_70 -> V_74 ] ) ;
}
static T_3 F_37 ( struct V_65 * V_66 , struct V_67
* V_68 , const char * V_22 , T_4 V_23 )
{
struct V_69 * V_70 = F_19 ( V_68 ) ;
struct V_1 * V_2 = F_22 ( V_66 ) ;
T_1 V_61 ;
unsigned long V_28 ;
T_3 V_30 ;
V_30 = F_26 ( V_22 , 10 , & V_28 ) ;
if ( V_30 )
return V_30 ;
V_30 = V_23 ;
V_28 = ( V_28 + V_83 [ V_70 -> V_74 ] / 2 ) /
V_83 [ V_70 -> V_74 ] ;
if ( ( V_70 -> V_72 == 0 ) && ( ( V_70 -> V_74 == 1 ) || ( V_70 -> V_74 == 2 ) ) )
V_61 = 77 ;
else
V_61 = V_62 [ V_70 -> V_74 ] ;
if ( V_28 < V_61 || V_28 > V_64 [ V_70 -> V_74 ] )
return - V_77 ;
F_27 ( & V_2 -> V_78 ) ;
if ( ( V_70 -> V_74 & 1 ) &&
( V_28 >= V_2 -> V_58 [ V_70 -> V_72 ] [ V_70 -> V_74 + 1 ] ) )
V_30 = - V_77 ;
else if ( ! ( V_70 -> V_74 & 1 ) &&
( V_28 <= V_2 -> V_58 [ V_70 -> V_72 ] [ V_70 -> V_74 - 1 ] ) )
V_30 = - V_77 ;
else if ( V_2 -> V_58 [ V_70 -> V_72 ] [ V_70 -> V_74 ] != V_28 ) {
T_1 V_79 = V_2 -> V_58 [ V_70 -> V_72 ] [ V_70 -> V_74 ] ;
V_2 -> V_58 [ V_70 -> V_72 ] [ V_70 -> V_74 ] = V_28 ;
if ( F_12 ( V_2 , V_84 + 1 ,
V_70 -> V_72 , V_2 -> V_58 [ V_70 -> V_72 ] ,
5 ) <= V_70 -> V_74 ) {
V_2 -> V_58 [ V_70 -> V_72 ] [ V_70 -> V_74 ] =
V_79 ;
V_30 = - V_13 ;
}
}
F_28 ( & V_2 -> V_78 ) ;
return V_30 ;
}
static T_3 F_38 ( struct V_65 * V_66 ,
struct V_67 * V_68 , char * V_22 )
{
struct V_69 * V_70 = F_19 ( V_68 ) ;
struct V_1 * V_2 = F_22 ( V_66 ) ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_59 [ V_45 ] ; V_24 ++ )
if ( V_2 -> V_60 [ V_45 ] [ V_24 ] ==
( V_2 -> V_58 [ V_70 -> V_72 ] [ 0 ] & 0x0F ) )
return sprintf ( V_22 , L_57 , V_24 + 1 ) ;
return - V_85 ;
}
static T_3 F_39 ( struct V_65 * V_66 , struct V_67
* V_68 , const char * V_22 , T_4 V_23 )
{
struct V_69 * V_70 = F_19 ( V_68 ) ;
struct V_1 * V_2 = F_22 ( V_66 ) ;
T_3 V_30 ;
unsigned long V_28 ;
T_1 V_79 ;
T_1 V_86 ;
V_30 = F_26 ( V_22 , 10 , & V_28 ) ;
if ( V_30 )
return V_30 ;
if ( V_28 == 0 || V_28 > V_2 -> V_59 [ V_45 ] )
return - V_77 ;
V_28 -= 1 ;
V_30 = V_23 ;
F_27 ( & V_2 -> V_78 ) ;
V_79 = V_2 -> V_58 [ V_70 -> V_72 ] [ 0 ] ;
V_86 = V_2 -> V_60 [ V_45 ] [ V_28 ] ;
V_2 -> V_58 [ V_70 -> V_72 ] [ 0 ] &= 0xF0 ;
V_2 -> V_58 [ V_70 -> V_72 ] [ 0 ] |= V_86 ;
if ( V_2 -> V_58 [ V_70 -> V_72 ] [ 0 ] != V_79 ) {
if ( F_12 ( V_2 , V_84 + 1 , V_70 -> V_72 ,
V_2 -> V_58 [ V_70 -> V_72 ] , 5 ) < 1 ) {
V_2 -> V_58 [ V_70 -> V_72 ] [ 0 ] = V_79 ;
V_30 = - V_13 ;
}
}
F_28 ( & V_2 -> V_78 ) ;
return V_30 ;
}
static T_3 F_40 ( struct V_65 * V_66 ,
struct V_67 * V_68 , char * V_22 )
{
struct V_69 * V_70 = F_19 ( V_68 ) ;
struct V_1 * V_2 = F_22 ( V_66 ) ;
int V_87 = 0 ;
if ( V_2 -> V_58 [ V_70 -> V_72 ] [ 0 ] & V_88 )
V_87 = 2 ;
return sprintf ( V_22 , L_57 , V_87 ) ;
}
static T_3 F_41 ( struct V_65 * V_66 , struct V_67
* V_68 , const char * V_22 , T_4 V_23 )
{
struct V_69 * V_70 = F_19 ( V_68 ) ;
struct V_1 * V_2 = F_22 ( V_66 ) ;
T_1 V_79 ;
T_3 V_30 ;
unsigned long V_89 ;
V_30 = F_26 ( V_22 , 10 , & V_89 ) ;
if ( V_30 )
return V_30 ;
V_30 = V_23 ;
F_27 ( & V_2 -> V_78 ) ;
V_79 = V_2 -> V_58 [ V_70 -> V_72 ] [ 0 ] ;
switch ( V_89 ) {
case 0 :
V_2 -> V_58 [ V_70 -> V_72 ] [ 0 ] &=
~ V_88 ;
break;
case 2 :
V_2 -> V_58 [ V_70 -> V_72 ] [ 0 ] |= V_88 ;
break;
default:
V_30 = - V_77 ;
}
if ( ( V_2 -> V_58 [ V_70 -> V_72 ] [ 0 ] != V_79 ) &&
( F_12 ( V_2 , V_84 + 1 ,
V_70 -> V_72 , V_2 -> V_58 [ V_70 -> V_72 ] ,
5 ) < 1 ) ) {
V_2 -> V_58 [ V_70 -> V_72 ] [ 0 ] = V_79 ;
V_30 = - V_13 ;
}
F_28 ( & V_2 -> V_78 ) ;
return V_30 ;
}
static T_3 F_42 ( struct V_65 * V_66 ,
struct V_67 * V_68 , char * V_22 )
{
return sprintf ( V_22 , L_60 , V_90 ) ;
}
static int T_2 F_43 ( struct V_91 * V_92 )
{
struct V_1 * V_2 ;
int V_24 , V_55 , V_93 , V_94 , V_95 , V_87 = - V_31 ;
char * V_96 ;
const T_1 V_97 [ V_98 ] = {
0x00 , 0x01 , 0x03 , 0x04 , 0x0A , 0x08 , 0x0E , 0x02 ,
0x09 , 0x06 , 0x05 , 0x0B , 0x0F , 0x0D , 0x07 , 0x0C } ;
V_2 = F_44 ( sizeof( struct V_1 ) , V_99 ) ;
if ( ! V_2 )
return - V_100 ;
V_2 -> V_6 = F_45 ( V_92 , V_101 , 0 ) -> V_102 ;
F_46 ( & V_2 -> V_78 ) ;
F_47 ( V_92 , V_2 ) ;
if ( F_2 ( V_2 -> V_6 + V_7 ) == V_15 )
V_2 -> V_11 = 1 ;
if ( F_10 ( V_2 , V_42 , 0 ,
V_2 -> V_81 , 3 , V_26 ) != 3 )
goto V_103;
for ( V_24 = 0 ; V_24 < V_98 ; V_24 ++ ) {
if ( F_10 ( V_2 , V_35 , V_24 ,
& V_2 -> V_71 [ V_24 ] , 1 ,
V_26 ) != 1 )
goto V_103;
if ( F_10 ( V_2 , V_35 + 1 , V_24 ,
V_2 -> V_46 [ V_24 ] , 3 ,
V_26 ) != 3 )
goto V_103;
}
for ( V_24 = 0 ; V_24 < V_50 ; V_24 ++ ) {
if ( F_10 ( V_2 , V_80 , V_24 ,
& V_2 -> V_75 [ V_24 ] , 1 ,
V_26 ) != 1 )
goto V_103;
if ( F_10 ( V_2 , V_80 + 1 , V_24 ,
V_2 -> V_52 [ V_24 ] , 2 ,
V_26 ) != 2 )
goto V_103;
}
for ( V_24 = 0 ; V_24 < V_57 ; V_24 ++ ) {
if ( F_10 ( V_2 , V_84 , V_24 ,
V_2 -> V_58 [ V_24 ] , 5 ,
V_26 ) != 5 )
goto V_103;
}
V_2 -> V_104 = V_105 ;
V_95 = 0 ;
V_96 = V_2 -> V_106 ;
V_94 = V_107 ;
for ( V_24 = 0 ; V_24 < V_98 ; V_24 ++ ) {
V_87 = F_13 ( V_2 , V_97 [ V_24 ] ) ;
if ( V_87 < 0 )
goto V_103;
if ( V_87 == V_34 )
continue;
for ( V_55 = 0 ; V_55 < ( V_87 ? 7 : 9 ) ; V_55 ++ ) {
V_93 = snprintf ( V_96 , V_94 ,
V_108 [ V_87 ] [ V_55 ] . V_109 .
V_70 . V_110 , V_2 -> V_59 [ V_87 ] + V_87 )
+ 1 ;
V_2 -> V_111 [ V_95 ] =
V_108 [ V_87 ] [ V_55 ] ;
V_2 -> V_111 [ V_95 ] . V_109 . V_70 . V_110 =
V_96 ;
V_2 -> V_111 [ V_95 ] . V_72 = V_97 [ V_24 ] ;
V_96 += V_93 ;
V_94 -= V_93 ;
V_95 ++ ;
}
V_2 -> V_73 [ V_97 [ V_24 ] ] =
V_112 [ V_87 ] ;
V_2 -> V_60 [ V_87 ] [ V_2 -> V_59 [ V_87 ] ] =
V_97 [ V_24 ] ;
V_2 -> V_59 [ V_87 ] ++ ;
}
F_16 ( V_2 ) ;
for ( V_24 = 0 ; V_24 < V_2 -> V_51 ; V_24 ++ ) {
for ( V_55 = 0 ; V_55 < F_48 ( V_113 ) ; V_55 ++ ) {
V_93 = snprintf ( V_96 , V_94 ,
V_113 [ V_55 ] . V_109 . V_70 . V_110 ,
V_24 + 1 ) + 1 ;
V_2 -> V_111 [ V_95 ] =
V_113 [ V_55 ] ;
V_2 -> V_111 [ V_95 ] . V_109 . V_70 . V_110 =
V_96 ;
V_2 -> V_111 [ V_95 ] . V_72 = V_24 ;
V_96 += V_93 ;
V_94 -= V_93 ;
V_95 ++ ;
}
}
F_17 ( V_2 ) ;
for ( V_24 = 0 ; V_24 < V_2 -> V_56 ; V_24 ++ ) {
for ( V_55 = 0 ; V_55 < F_48 ( V_114 ) ; V_55 ++ ) {
V_93 = snprintf ( V_96 , V_94 ,
V_114 [ V_55 ] . V_109 . V_70 . V_110 ,
V_24 + 1 ) + 1 ;
V_2 -> V_111 [ V_95 ] =
V_114 [ V_55 ] ;
V_2 -> V_111 [ V_95 ] . V_109 . V_70 . V_110 =
V_96 ;
V_2 -> V_111 [ V_95 ] . V_72 = V_24 ;
V_96 += V_93 ;
V_94 -= V_93 ;
V_95 ++ ;
}
}
if ( V_94 < 0 ) {
F_15 ( L_61 ,
V_47 , V_48 ) ;
V_87 = - V_115 ;
goto V_103;
}
F_49 ( L_62 ) ;
for ( V_24 = 0 ; V_24 < V_95 ; V_24 ++ )
if ( F_50 ( & V_92 -> V_66 ,
& V_2 -> V_111 [ V_24 ] . V_109 ) )
goto V_103;
for ( V_24 = 0 ; V_24 < F_48 ( V_116 ) ; V_24 ++ )
if ( F_50 ( & V_92 -> V_66 ,
& V_116 [ V_24 ] . V_109 ) )
goto V_103;
V_2 -> V_117 = F_51 ( & V_92 -> V_66 ) ;
if ( ! F_52 ( V_2 -> V_117 ) )
return 0 ;
V_87 = F_53 ( V_2 -> V_117 ) ;
V_103:
for ( V_24 = 0 ; V_2 -> V_111 [ V_24 ] . V_109 . V_70 . V_110 ; V_24 ++ )
F_54 ( & V_92 -> V_66 , & V_2 -> V_111 [ V_24 ] . V_109 ) ;
for ( V_24 = 0 ; V_24 < F_48 ( V_116 ) ; V_24 ++ )
F_54 ( & V_92 -> V_66 ,
& V_116 [ V_24 ] . V_109 ) ;
F_47 ( V_92 , NULL ) ;
F_55 ( V_2 ) ;
return V_87 ;
}
static int T_5 F_56 ( struct V_91 * V_92 )
{
int V_24 ;
struct V_1 * V_2 = F_57 ( V_92 ) ;
F_58 ( V_2 -> V_117 ) ;
for ( V_24 = 0 ; V_2 -> V_111 [ V_24 ] . V_109 . V_70 . V_110 ; V_24 ++ )
F_54 ( & V_92 -> V_66 , & V_2 -> V_111 [ V_24 ] . V_109 ) ;
for ( V_24 = 0 ; V_24 < F_48 ( V_116 ) ; V_24 ++ )
F_54 ( & V_92 -> V_66 ,
& V_116 [ V_24 ] . V_109 ) ;
F_47 ( V_92 , NULL ) ;
F_55 ( V_2 ) ;
return 0 ;
}
static struct V_1 * F_20 ( struct V_65 * V_66 )
{
int V_24 , V_118 ;
struct V_1 * V_2 = F_22 ( V_66 ) ;
char V_119 = 1 ;
F_27 ( & V_2 -> V_78 ) ;
if ( F_59 ( V_105 , V_2 -> V_104 + V_41 ) ) {
V_119 = 0 ;
V_118 = F_10 ( V_2 , V_42 , 0 ,
V_2 -> V_81 , 3 , 0 ) ;
if ( V_118 != 3 )
goto V_120;
for ( V_24 = 0 ; V_24 < V_98 ; V_24 ++ ) {
V_118 = F_10 ( V_2 , V_35 ,
V_24 , & V_2 -> V_71 [ V_24 ] , 1 , 0 ) ;
if ( V_118 != 1 )
goto V_120;
V_118 = F_10 ( V_2 , V_35 + 1 ,
V_24 , V_2 -> V_46 [ V_24 ] , 3 , 0 ) ;
if ( V_118 != 3 )
goto V_120;
}
for ( V_24 = 0 ; V_24 < V_2 -> V_51 ; V_24 ++ ) {
V_118 = F_10 ( V_2 , V_80 , V_24 ,
& V_2 -> V_75 [ V_24 ] , 1 , 0 ) ;
if ( V_118 != 1 )
goto V_120;
}
V_119 = 1 ;
V_2 -> V_121 = 0 ;
V_120:
if ( ! V_119 && ( V_118 == - V_8 || V_118 >= 0 ) ) {
if ( V_2 -> V_121 < 255u )
V_2 -> V_121 ++ ;
if ( V_2 -> V_121 <= V_122 ) {
F_6 ( 3 , L_63
L_64 ) ;
V_119 = 1 ;
} else
F_6 ( 1 , L_65
L_66 ,
( int ) V_2 -> V_121 ) ;
}
if ( V_119 )
V_2 -> V_104 = V_105 ;
}
F_28 ( & V_2 -> V_78 ) ;
if ( V_119 )
return V_2 ;
else
return NULL ;
}
static int F_60 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = F_22 ( V_66 ) ;
F_27 ( & V_2 -> V_78 ) ;
return 0 ;
}
static int F_61 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = F_22 ( V_66 ) ;
if ( F_2 ( V_2 -> V_6 + V_7 ) != V_15 )
V_2 -> V_11 = 0 ;
F_28 ( & V_2 -> V_78 ) ;
return 0 ;
}
static int T_6 F_62 ( void )
{
T_1 V_123 = F_2 ( V_124 + V_14 ) ;
T_1 V_125 = F_2 ( V_124 + V_7 ) ;
if ( ( ( V_125 == 0x00 ) || ( V_125 == 0x08 ) ) &&
( ( V_123 == 0x00 ) || ( V_123 == 0xAC ) ) )
return V_124 ;
F_6 ( 2 , L_67
L_68 , ( unsigned int ) V_125 , ( unsigned int ) V_123 ) ;
if ( V_126 ) {
F_49 ( L_69 ) ;
return V_124 ;
}
return - V_31 ;
}
static int T_6 F_63 ( void )
{
int V_86 , V_118 ;
struct V_127 V_87 = { . V_128 = V_101 } ;
const char * V_129 = F_64 ( V_130 ) ;
if ( ! V_126 && ( ! V_129 ||
strcmp ( V_129 , L_70 ) ) )
return - V_31 ;
V_86 = F_62 () ;
if ( V_86 < 0 )
return V_86 ;
V_118 = F_65 ( & V_131 ) ;
if ( V_118 )
goto exit;
V_132 = F_66 ( V_90 , V_86 ) ;
if ( ! V_132 ) {
F_15 ( L_71 ) ;
V_118 = - V_100 ;
goto V_133;
}
V_87 . V_102 = V_86 ;
V_87 . V_134 = V_86 + V_135 - 1 ;
V_87 . V_110 = V_90 ;
V_118 = F_67 ( V_132 , & V_87 , 1 ) ;
if ( V_118 ) {
F_15 ( L_72 , V_118 ) ;
goto V_136;
}
V_118 = F_68 ( V_132 ) ;
if ( V_118 ) {
F_15 ( L_73 , V_118 ) ;
goto V_136;
}
return 0 ;
V_136:
F_69 ( V_132 ) ;
V_133:
F_70 ( & V_131 ) ;
exit:
return V_118 ;
}
static void T_7 F_71 ( void )
{
F_72 ( V_132 ) ;
F_70 ( & V_131 ) ;
}
