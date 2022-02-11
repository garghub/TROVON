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
V_28 -> V_33 = V_34 |
V_35 | V_36 ;
return 0 ;
}
static T_2 F_19 ( int V_37 , void * V_38 )
{
struct V_1 * V_2 = V_38 ;
unsigned char V_3 ;
unsigned char V_39 ;
unsigned short V_40 ;
unsigned short V_41 ;
unsigned char V_42 [ 3 ] ;
int V_17 = 0 ;
V_17 = F_1 ( V_2 , V_43 ) ;
if ( V_17 < 0 )
goto V_44;
if ( V_2 -> V_13 [ V_43 ] & V_45 )
F_20 ( & V_2 -> V_46 ) ;
if ( ( V_2 -> V_13 [ V_21 ] & V_47 ) == 0 )
goto V_44;
for ( V_3 = 1 ; V_3 < V_48 ; V_3 ++ ) {
V_17 = F_1 ( V_2 , V_43 + V_3 ) ;
if ( V_17 < 0 )
goto V_44;
}
if ( ( V_2 -> V_13 [ V_43 ] & V_49 ) == 0 )
goto V_44;
for ( V_39 = 0 ; V_39 < 4 ; V_39 ++ ) {
switch ( V_39 ) {
default:
V_40 = ( V_2 -> V_13 [ V_43 ] &
V_50 ) >> 9 ;
V_41 = V_2 -> V_13 [ V_51 ] ;
break;
case 1 :
V_40 = ( V_2 -> V_13 [ V_52 ] &
V_53 ) >> 14 ;
V_41 = V_2 -> V_13 [ V_54 ] ;
break;
case 2 :
V_40 = ( V_2 -> V_13 [ V_52 ] &
V_55 ) >> 12 ;
V_41 = V_2 -> V_13 [ V_56 ] ;
break;
case 3 :
V_40 = ( V_2 -> V_13 [ V_52 ] &
V_57 ) >> 10 ;
V_41 = V_2 -> V_13 [ V_58 ] ;
break;
} ;
F_21 ( V_41 , & V_42 ) ;
V_42 [ 2 ] = V_39 ;
V_42 [ 2 ] |= V_39 << 3 ;
if ( V_40 > V_59 )
V_42 [ 2 ] |= 0x80 ;
else if ( V_40 > 0 )
V_42 [ 2 ] |= 0x40 ;
memcpy ( & V_2 -> V_60 [ V_2 -> V_61 ] , & V_42 , 3 ) ;
V_2 -> V_61 += 3 ;
if ( V_2 -> V_61 >= V_2 -> V_62 )
V_2 -> V_61 = 0 ;
if ( V_2 -> V_61 == V_2 -> V_63 ) {
V_2 -> V_63 += 3 ;
if ( V_2 -> V_63 >= V_2 -> V_62 )
V_2 -> V_63 = 0 ;
}
}
if ( V_2 -> V_61 != V_2 -> V_63 )
F_22 ( & V_2 -> V_64 ) ;
V_44:
return V_65 ;
}
static int T_3 F_23 ( struct V_66 * V_8 ,
const struct V_67 * V_68 )
{
struct V_1 * V_2 ;
int V_17 = 0 ;
unsigned char V_69 = 0 ;
V_2 = F_24 ( sizeof( struct V_1 ) , V_70 ) ;
if ( ! V_2 ) {
V_17 = - V_71 ;
goto V_72;
}
V_2 -> V_19 = 0 ;
V_2 -> V_8 = V_8 ;
F_25 ( & V_2 -> V_18 ) ;
V_2 -> V_73 = F_26 () ;
if ( ! V_2 -> V_73 ) {
V_17 = - V_71 ;
goto V_74;
}
memcpy ( V_2 -> V_73 , & V_75 ,
sizeof( V_75 ) ) ;
F_27 ( V_2 -> V_73 , V_2 ) ;
V_2 -> V_13 [ V_76 ] = V_77 ;
if ( F_5 ( V_2 , V_76 ) < 0 ) {
V_17 = - V_12 ;
goto V_78;
}
F_28 ( 110 ) ;
if ( F_8 ( V_2 ) < 0 ) {
V_17 = - V_12 ;
goto V_78;
}
F_29 ( & V_8 -> V_79 , L_1 ,
V_2 -> V_13 [ V_80 ] , V_2 -> V_13 [ V_81 ] ) ;
if ( ( V_2 -> V_13 [ V_81 ] & V_82 ) < V_83 ) {
F_30 ( & V_8 -> V_79 ,
L_2
L_3 , V_83 ) ;
F_30 ( & V_8 -> V_79 ,
L_4 ,
V_2 -> V_13 [ V_81 ] & V_82 ) ;
V_69 = 1 ;
}
if ( V_69 == 1 ) {
F_30 ( & V_8 -> V_79 ,
L_5 ) ;
F_30 ( & V_8 -> V_79 ,
L_6
L_7 ) ;
}
F_31 ( V_2 , 87.5 * V_84 ) ;
V_2 -> V_62 = V_85 * 3 ;
V_2 -> V_60 = F_32 ( V_2 -> V_62 , V_70 ) ;
if ( ! V_2 -> V_60 ) {
V_17 = - V_12 ;
goto V_78;
}
V_2 -> V_61 = 0 ;
V_2 -> V_63 = 0 ;
F_33 ( & V_2 -> V_64 ) ;
V_2 -> V_86 = true ;
F_34 ( & V_2 -> V_46 ) ;
V_17 = F_35 ( V_8 -> V_37 , NULL , F_19 ,
V_87 , V_30 , V_2 ) ;
if ( V_17 ) {
F_36 ( & V_8 -> V_79 , L_8 ) ;
goto V_88;
}
V_17 = F_37 ( V_2 -> V_73 , V_89 ,
V_90 ) ;
if ( V_17 ) {
F_30 ( & V_8 -> V_79 , L_9 ) ;
goto V_91;
}
F_38 ( V_8 , V_2 ) ;
return 0 ;
V_91:
F_39 ( V_8 -> V_37 , V_2 ) ;
V_88:
F_40 ( V_2 -> V_60 ) ;
V_78:
F_41 ( V_2 -> V_73 ) ;
V_74:
F_40 ( V_2 ) ;
V_72:
return V_17 ;
}
static T_4 int F_42 ( struct V_66 * V_8 )
{
struct V_1 * V_2 = F_43 ( V_8 ) ;
F_39 ( V_8 -> V_37 , V_2 ) ;
F_44 ( V_2 -> V_73 ) ;
F_40 ( V_2 ) ;
return 0 ;
}
static int F_45 ( struct V_92 * V_79 )
{
struct V_66 * V_8 = F_46 ( V_79 ) ;
struct V_1 * V_2 = F_43 ( V_8 ) ;
V_2 -> V_13 [ V_76 ] |= V_93 ;
if ( F_5 ( V_2 , V_76 ) < 0 )
return - V_12 ;
return 0 ;
}
static int F_47 ( struct V_92 * V_79 )
{
struct V_66 * V_8 = F_46 ( V_79 ) ;
struct V_1 * V_2 = F_43 ( V_8 ) ;
V_2 -> V_13 [ V_76 ] |= V_77 ;
if ( F_5 ( V_2 , V_76 ) < 0 )
return - V_12 ;
F_28 ( 110 ) ;
return 0 ;
}
