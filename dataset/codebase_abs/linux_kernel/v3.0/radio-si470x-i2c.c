int F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 [ V_5 ] ;
struct V_6 V_7 [ 1 ] = {
{ V_2 -> V_8 -> V_9 , V_10 , sizeof( T_1 ) * V_5 ,
( void * ) V_4 } ,
} ;
if ( F_2 ( V_2 -> V_8 -> V_11 , V_7 , 1 ) != 1 )
return - V_12 ;
V_2 -> V_13 [ V_3 ] = F_3 ( V_4 [ F_4 ( V_3 ) ] ) ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 , int V_3 )
{
int V_14 ;
T_1 V_4 [ V_15 ] ;
struct V_6 V_7 [ 1 ] = {
{ V_2 -> V_8 -> V_9 , 0 , sizeof( T_1 ) * V_15 ,
( void * ) V_4 } ,
} ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ )
V_4 [ V_14 ] = F_6 ( V_2 -> V_13 [ F_7 ( V_14 ) ] ) ;
if ( F_2 ( V_2 -> V_8 -> V_11 , V_7 , 1 ) != 1 )
return - V_12 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_14 ;
T_1 V_4 [ V_5 ] ;
struct V_6 V_7 [ 1 ] = {
{ V_2 -> V_8 -> V_9 , V_10 , sizeof( T_1 ) * V_5 ,
( void * ) V_4 } ,
} ;
if ( F_2 ( V_2 -> V_8 -> V_11 , V_7 , 1 ) != 1 )
return - V_12 ;
for ( V_14 = 0 ; V_14 < V_5 ; V_14 ++ )
V_2 -> V_13 [ V_14 ] = F_3 ( V_4 [ F_4 ( V_14 ) ] ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_10 ( struct V_16 * V_16 )
{
struct V_1 * V_2 = F_11 ( V_16 ) ;
int V_17 = 0 ;
F_12 ( & V_2 -> V_18 ) ;
V_2 -> V_19 ++ ;
if ( V_2 -> V_19 == 1 ) {
V_17 = F_13 ( V_2 ) ;
if ( V_17 < 0 )
goto V_20;
V_2 -> V_13 [ V_21 ] |= V_22 ;
V_2 -> V_13 [ V_21 ] |= V_23 ;
V_2 -> V_13 [ V_21 ] &= ~ V_24 ;
V_2 -> V_13 [ V_21 ] |= 0x1 << 2 ;
V_17 = F_5 ( V_2 , V_21 ) ;
}
V_20:
F_14 ( & V_2 -> V_18 ) ;
return V_17 ;
}
int F_15 ( struct V_16 * V_16 )
{
struct V_1 * V_2 = F_11 ( V_16 ) ;
int V_17 = 0 ;
if ( ! V_2 )
return - V_25 ;
F_12 ( & V_2 -> V_18 ) ;
V_2 -> V_19 -- ;
if ( V_2 -> V_19 == 0 )
V_17 = F_16 ( V_2 ) ;
F_14 ( & V_2 -> V_18 ) ;
return V_17 ;
}
int F_17 ( struct V_16 * V_16 , void * V_26 ,
struct V_27 * V_28 )
{
F_18 ( V_28 -> V_29 , V_30 , sizeof( V_28 -> V_29 ) ) ;
F_18 ( V_28 -> V_31 , V_32 , sizeof( V_28 -> V_31 ) ) ;
V_28 -> V_33 = V_34 ;
V_28 -> V_35 = V_36 |
V_37 | V_38 ;
return 0 ;
}
static T_2 F_19 ( int V_39 , void * V_40 )
{
struct V_1 * V_2 = V_40 ;
unsigned char V_3 ;
unsigned char V_41 ;
unsigned short V_42 ;
unsigned short V_43 ;
unsigned char V_44 [ 3 ] ;
int V_17 = 0 ;
V_17 = F_1 ( V_2 , V_45 ) ;
if ( V_17 < 0 )
goto V_46;
if ( V_2 -> V_13 [ V_45 ] & V_47 )
F_20 ( & V_2 -> V_48 ) ;
if ( ( V_2 -> V_13 [ V_21 ] & V_49 ) == 0 )
goto V_46;
for ( V_3 = 1 ; V_3 < V_50 ; V_3 ++ ) {
V_17 = F_1 ( V_2 , V_45 + V_3 ) ;
if ( V_17 < 0 )
goto V_46;
}
if ( ( V_2 -> V_13 [ V_45 ] & V_51 ) == 0 )
goto V_46;
for ( V_41 = 0 ; V_41 < 4 ; V_41 ++ ) {
switch ( V_41 ) {
default:
V_42 = ( V_2 -> V_13 [ V_45 ] &
V_52 ) >> 9 ;
V_43 = V_2 -> V_13 [ V_53 ] ;
break;
case 1 :
V_42 = ( V_2 -> V_13 [ V_54 ] &
V_55 ) >> 14 ;
V_43 = V_2 -> V_13 [ V_56 ] ;
break;
case 2 :
V_42 = ( V_2 -> V_13 [ V_54 ] &
V_57 ) >> 12 ;
V_43 = V_2 -> V_13 [ V_58 ] ;
break;
case 3 :
V_42 = ( V_2 -> V_13 [ V_54 ] &
V_59 ) >> 10 ;
V_43 = V_2 -> V_13 [ V_60 ] ;
break;
} ;
F_21 ( V_43 , & V_44 ) ;
V_44 [ 2 ] = V_41 ;
V_44 [ 2 ] |= V_41 << 3 ;
if ( V_42 > V_61 )
V_44 [ 2 ] |= 0x80 ;
else if ( V_42 > 0 )
V_44 [ 2 ] |= 0x40 ;
memcpy ( & V_2 -> V_62 [ V_2 -> V_63 ] , & V_44 , 3 ) ;
V_2 -> V_63 += 3 ;
if ( V_2 -> V_63 >= V_2 -> V_64 )
V_2 -> V_63 = 0 ;
if ( V_2 -> V_63 == V_2 -> V_65 ) {
V_2 -> V_65 += 3 ;
if ( V_2 -> V_65 >= V_2 -> V_64 )
V_2 -> V_65 = 0 ;
}
}
if ( V_2 -> V_63 != V_2 -> V_65 )
F_22 ( & V_2 -> V_66 ) ;
V_46:
return V_67 ;
}
static int T_3 F_23 ( struct V_68 * V_8 ,
const struct V_69 * V_70 )
{
struct V_1 * V_2 ;
int V_17 = 0 ;
unsigned char V_71 = 0 ;
V_2 = F_24 ( sizeof( struct V_1 ) , V_72 ) ;
if ( ! V_2 ) {
V_17 = - V_73 ;
goto V_74;
}
V_2 -> V_19 = 0 ;
V_2 -> V_8 = V_8 ;
F_25 ( & V_2 -> V_18 ) ;
V_2 -> V_75 = F_26 () ;
if ( ! V_2 -> V_75 ) {
V_17 = - V_73 ;
goto V_76;
}
memcpy ( V_2 -> V_75 , & V_77 ,
sizeof( V_77 ) ) ;
F_27 ( V_2 -> V_75 , V_2 ) ;
V_2 -> V_13 [ V_78 ] = V_79 ;
if ( F_5 ( V_2 , V_78 ) < 0 ) {
V_17 = - V_12 ;
goto V_80;
}
F_28 ( 110 ) ;
if ( F_8 ( V_2 ) < 0 ) {
V_17 = - V_12 ;
goto V_80;
}
F_29 ( & V_8 -> V_81 , L_1 ,
V_2 -> V_13 [ V_82 ] , V_2 -> V_13 [ V_83 ] ) ;
if ( ( V_2 -> V_13 [ V_83 ] & V_84 ) < V_85 ) {
F_30 ( & V_8 -> V_81 ,
L_2
L_3 , V_85 ) ;
F_30 ( & V_8 -> V_81 ,
L_4 ,
V_2 -> V_13 [ V_83 ] & V_84 ) ;
V_71 = 1 ;
}
if ( V_71 == 1 ) {
F_30 ( & V_8 -> V_81 ,
L_5 ) ;
F_30 ( & V_8 -> V_81 ,
L_6
L_7 ) ;
}
F_31 ( V_2 , 87.5 * V_86 ) ;
V_2 -> V_64 = V_87 * 3 ;
V_2 -> V_62 = F_32 ( V_2 -> V_64 , V_72 ) ;
if ( ! V_2 -> V_62 ) {
V_17 = - V_12 ;
goto V_80;
}
V_2 -> V_63 = 0 ;
V_2 -> V_65 = 0 ;
F_33 ( & V_2 -> V_66 ) ;
V_2 -> V_88 = true ;
F_34 ( & V_2 -> V_48 ) ;
V_17 = F_35 ( V_8 -> V_39 , NULL , F_19 ,
V_89 , V_30 , V_2 ) ;
if ( V_17 ) {
F_36 ( & V_8 -> V_81 , L_8 ) ;
goto V_90;
}
V_17 = F_37 ( V_2 -> V_75 , V_91 ,
V_92 ) ;
if ( V_17 ) {
F_30 ( & V_8 -> V_81 , L_9 ) ;
goto V_93;
}
F_38 ( V_8 , V_2 ) ;
return 0 ;
V_93:
F_39 ( V_8 -> V_39 , V_2 ) ;
V_90:
F_40 ( V_2 -> V_62 ) ;
V_80:
F_41 ( V_2 -> V_75 ) ;
V_76:
F_40 ( V_2 ) ;
V_74:
return V_17 ;
}
static T_4 int F_42 ( struct V_68 * V_8 )
{
struct V_1 * V_2 = F_43 ( V_8 ) ;
F_39 ( V_8 -> V_39 , V_2 ) ;
F_44 ( V_2 -> V_75 ) ;
F_40 ( V_2 ) ;
return 0 ;
}
static int F_45 ( struct V_94 * V_81 )
{
struct V_68 * V_8 = F_46 ( V_81 ) ;
struct V_1 * V_2 = F_43 ( V_8 ) ;
V_2 -> V_13 [ V_78 ] |= V_95 ;
if ( F_5 ( V_2 , V_78 ) < 0 )
return - V_12 ;
return 0 ;
}
static int F_47 ( struct V_94 * V_81 )
{
struct V_68 * V_8 = F_46 ( V_81 ) ;
struct V_1 * V_2 = F_43 ( V_8 ) ;
V_2 -> V_13 [ V_78 ] |= V_79 ;
if ( F_5 ( V_2 , V_78 ) < 0 )
return - V_12 ;
F_28 ( 110 ) ;
return 0 ;
}
static int T_5 F_48 ( void )
{
F_49 (KERN_INFO DRIVER_DESC L_10 DRIVER_VERSION L_11 ) ;
return F_50 ( & V_96 ) ;
}
static void T_6 F_51 ( void )
{
F_52 ( & V_96 ) ;
}
