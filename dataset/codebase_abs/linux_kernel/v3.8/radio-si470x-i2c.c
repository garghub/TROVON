int F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 [ V_5 ] ;
struct V_6 V_7 [ 1 ] = {
{
. V_8 = V_2 -> V_9 -> V_8 ,
. V_10 = V_11 ,
. V_12 = sizeof( T_1 ) * V_5 ,
. V_4 = ( void * ) V_4
} ,
} ;
if ( F_2 ( V_2 -> V_9 -> V_13 , V_7 , 1 ) != 1 )
return - V_14 ;
V_2 -> V_15 [ V_3 ] = F_3 ( V_4 [ F_4 ( V_3 ) ] ) ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 , int V_3 )
{
int V_16 ;
T_1 V_4 [ V_17 ] ;
struct V_6 V_7 [ 1 ] = {
{
. V_8 = V_2 -> V_9 -> V_8 ,
. V_12 = sizeof( T_1 ) * V_17 ,
. V_4 = ( void * ) V_4
} ,
} ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ )
V_4 [ V_16 ] = F_6 ( V_2 -> V_15 [ F_7 ( V_16 ) ] ) ;
if ( F_2 ( V_2 -> V_9 -> V_13 , V_7 , 1 ) != 1 )
return - V_14 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_16 ;
T_1 V_4 [ V_5 ] ;
struct V_6 V_7 [ 1 ] = {
{
. V_8 = V_2 -> V_9 -> V_8 ,
. V_10 = V_11 ,
. V_12 = sizeof( T_1 ) * V_5 ,
. V_4 = ( void * ) V_4
} ,
} ;
if ( F_2 ( V_2 -> V_9 -> V_13 , V_7 , 1 ) != 1 )
return - V_14 ;
for ( V_16 = 0 ; V_16 < V_5 ; V_16 ++ )
V_2 -> V_15 [ V_16 ] = F_3 ( V_4 [ F_4 ( V_16 ) ] ) ;
return 0 ;
}
int F_9 ( struct V_18 * V_18 )
{
struct V_1 * V_2 = F_10 ( V_18 ) ;
int V_19 = F_11 ( V_18 ) ;
if ( V_19 )
return V_19 ;
if ( F_12 ( V_18 ) ) {
V_19 = F_13 ( V_2 ) ;
if ( V_19 < 0 )
goto V_20;
V_2 -> V_15 [ V_21 ] |= V_22 ;
V_2 -> V_15 [ V_21 ] |= V_23 ;
V_2 -> V_15 [ V_21 ] &= ~ V_24 ;
V_2 -> V_15 [ V_21 ] |= 0x1 << 2 ;
V_19 = F_5 ( V_2 , V_21 ) ;
}
V_20:
if ( V_19 )
F_14 ( V_18 ) ;
return V_19 ;
}
int F_15 ( struct V_18 * V_18 )
{
struct V_1 * V_2 = F_10 ( V_18 ) ;
if ( F_12 ( V_18 ) )
F_16 ( V_2 ) ;
return F_14 ( V_18 ) ;
}
int F_17 ( struct V_18 * V_18 , void * V_25 ,
struct V_26 * V_27 )
{
F_18 ( V_27 -> V_28 , V_29 , sizeof( V_27 -> V_28 ) ) ;
F_18 ( V_27 -> V_30 , V_31 , sizeof( V_27 -> V_30 ) ) ;
V_27 -> V_32 = V_33 | V_34 |
V_35 | V_36 | V_37 ;
V_27 -> V_38 = V_27 -> V_32 | V_39 ;
return 0 ;
}
static T_2 F_19 ( int V_40 , void * V_41 )
{
struct V_1 * V_2 = V_41 ;
unsigned char V_3 ;
unsigned char V_42 ;
unsigned short V_43 ;
unsigned short V_44 ;
unsigned char V_45 [ 3 ] ;
int V_19 = 0 ;
V_19 = F_1 ( V_2 , V_46 ) ;
if ( V_19 < 0 )
goto V_47;
if ( V_2 -> V_15 [ V_46 ] & V_48 )
F_20 ( & V_2 -> V_49 ) ;
if ( ( V_2 -> V_15 [ V_21 ] & V_50 ) == 0 )
goto V_47;
for ( V_3 = 1 ; V_3 < V_51 ; V_3 ++ ) {
V_19 = F_1 ( V_2 , V_46 + V_3 ) ;
if ( V_19 < 0 )
goto V_47;
}
if ( ( V_2 -> V_15 [ V_46 ] & V_52 ) == 0 )
goto V_47;
for ( V_42 = 0 ; V_42 < 4 ; V_42 ++ ) {
switch ( V_42 ) {
default:
V_43 = ( V_2 -> V_15 [ V_46 ] &
V_53 ) >> 9 ;
V_44 = V_2 -> V_15 [ V_54 ] ;
break;
case 1 :
V_43 = ( V_2 -> V_15 [ V_55 ] &
V_56 ) >> 14 ;
V_44 = V_2 -> V_15 [ V_57 ] ;
break;
case 2 :
V_43 = ( V_2 -> V_15 [ V_55 ] &
V_58 ) >> 12 ;
V_44 = V_2 -> V_15 [ V_59 ] ;
break;
case 3 :
V_43 = ( V_2 -> V_15 [ V_55 ] &
V_60 ) >> 10 ;
V_44 = V_2 -> V_15 [ V_61 ] ;
break;
}
F_21 ( V_44 , & V_45 ) ;
V_45 [ 2 ] = V_42 ;
V_45 [ 2 ] |= V_42 << 3 ;
if ( V_43 > V_62 )
V_45 [ 2 ] |= 0x80 ;
else if ( V_43 > 0 )
V_45 [ 2 ] |= 0x40 ;
memcpy ( & V_2 -> V_63 [ V_2 -> V_64 ] , & V_45 , 3 ) ;
V_2 -> V_64 += 3 ;
if ( V_2 -> V_64 >= V_2 -> V_65 )
V_2 -> V_64 = 0 ;
if ( V_2 -> V_64 == V_2 -> V_66 ) {
V_2 -> V_66 += 3 ;
if ( V_2 -> V_66 >= V_2 -> V_65 )
V_2 -> V_66 = 0 ;
}
}
if ( V_2 -> V_64 != V_2 -> V_66 )
F_22 ( & V_2 -> V_67 ) ;
V_47:
return V_68 ;
}
static int F_23 ( struct V_69 * V_9 ,
const struct V_70 * V_71 )
{
struct V_1 * V_2 ;
int V_19 = 0 ;
unsigned char V_72 = 0 ;
V_2 = F_24 ( sizeof( struct V_1 ) , V_73 ) ;
if ( ! V_2 ) {
V_19 = - V_74 ;
goto V_75;
}
V_2 -> V_9 = V_9 ;
V_2 -> V_76 = 1 ;
F_25 ( & V_2 -> V_77 ) ;
F_26 ( & V_2 -> V_49 ) ;
V_2 -> V_78 = V_79 ;
F_27 ( & V_2 -> V_78 , V_2 ) ;
V_2 -> V_15 [ V_80 ] = V_81 ;
if ( F_5 ( V_2 , V_80 ) < 0 ) {
V_19 = - V_14 ;
goto V_82;
}
F_28 ( 110 ) ;
if ( F_8 ( V_2 ) < 0 ) {
V_19 = - V_14 ;
goto V_82;
}
F_29 ( & V_9 -> V_83 , L_1 ,
V_2 -> V_15 [ V_84 ] , V_2 -> V_15 [ V_85 ] ) ;
if ( ( V_2 -> V_15 [ V_85 ] & V_86 ) < V_87 ) {
F_30 ( & V_9 -> V_83 ,
L_2
L_3 , V_87 ) ;
F_30 ( & V_9 -> V_83 ,
L_4 ,
V_2 -> V_15 [ V_85 ] & V_86 ) ;
V_72 = 1 ;
}
if ( V_72 == 1 ) {
F_30 ( & V_9 -> V_83 ,
L_5 ) ;
F_30 ( & V_9 -> V_83 ,
L_6
L_7 ) ;
}
F_31 ( V_2 , 87.5 * V_88 ) ;
V_2 -> V_65 = V_89 * 3 ;
V_2 -> V_63 = F_32 ( V_2 -> V_65 , V_73 ) ;
if ( ! V_2 -> V_63 ) {
V_19 = - V_14 ;
goto V_82;
}
V_2 -> V_64 = 0 ;
V_2 -> V_66 = 0 ;
F_33 ( & V_2 -> V_67 ) ;
V_19 = F_34 ( V_9 -> V_40 , NULL , F_19 ,
V_90 , V_29 , V_2 ) ;
if ( V_19 ) {
F_35 ( & V_9 -> V_83 , L_8 ) ;
goto V_91;
}
V_19 = F_36 ( & V_2 -> V_78 , V_92 ,
V_93 ) ;
if ( V_19 ) {
F_30 ( & V_9 -> V_83 , L_9 ) ;
goto V_94;
}
F_37 ( V_9 , V_2 ) ;
return 0 ;
V_94:
F_38 ( V_9 -> V_40 , V_2 ) ;
V_91:
F_39 ( V_2 -> V_63 ) ;
V_82:
F_39 ( V_2 ) ;
V_75:
return V_19 ;
}
static int F_40 ( struct V_69 * V_9 )
{
struct V_1 * V_2 = F_41 ( V_9 ) ;
F_38 ( V_9 -> V_40 , V_2 ) ;
F_42 ( & V_2 -> V_78 ) ;
F_39 ( V_2 ) ;
return 0 ;
}
static int F_43 ( struct V_95 * V_83 )
{
struct V_69 * V_9 = F_44 ( V_83 ) ;
struct V_1 * V_2 = F_41 ( V_9 ) ;
V_2 -> V_15 [ V_80 ] |= V_96 ;
if ( F_5 ( V_2 , V_80 ) < 0 )
return - V_14 ;
return 0 ;
}
static int F_45 ( struct V_95 * V_83 )
{
struct V_69 * V_9 = F_44 ( V_83 ) ;
struct V_1 * V_2 = F_41 ( V_9 ) ;
V_2 -> V_15 [ V_80 ] |= V_81 ;
if ( F_5 ( V_2 , V_80 ) < 0 )
return - V_14 ;
F_28 ( 110 ) ;
return 0 ;
}
