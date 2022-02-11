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
int F_9 ( struct V_16 * V_16 )
{
struct V_1 * V_2 = F_10 ( V_16 ) ;
int V_17 = F_11 ( V_16 ) ;
if ( V_17 )
return V_17 ;
if ( F_12 ( V_16 ) ) {
V_17 = F_13 ( V_2 ) ;
if ( V_17 < 0 )
goto V_18;
V_2 -> V_13 [ V_19 ] |= V_20 ;
V_2 -> V_13 [ V_19 ] |= V_21 ;
V_2 -> V_13 [ V_19 ] &= ~ V_22 ;
V_2 -> V_13 [ V_19 ] |= 0x1 << 2 ;
V_17 = F_5 ( V_2 , V_19 ) ;
}
V_18:
if ( V_17 )
F_14 ( V_16 ) ;
return V_17 ;
}
int F_15 ( struct V_16 * V_16 )
{
struct V_1 * V_2 = F_10 ( V_16 ) ;
if ( F_12 ( V_16 ) )
F_16 ( V_2 ) ;
return F_14 ( V_16 ) ;
}
int F_17 ( struct V_16 * V_16 , void * V_23 ,
struct V_24 * V_25 )
{
F_18 ( V_25 -> V_26 , V_27 , sizeof( V_25 -> V_26 ) ) ;
F_18 ( V_25 -> V_28 , V_29 , sizeof( V_25 -> V_28 ) ) ;
V_25 -> V_30 = V_31 |
V_32 | V_33 ;
return 0 ;
}
static T_2 F_19 ( int V_34 , void * V_35 )
{
struct V_1 * V_2 = V_35 ;
unsigned char V_3 ;
unsigned char V_36 ;
unsigned short V_37 ;
unsigned short V_38 ;
unsigned char V_39 [ 3 ] ;
int V_17 = 0 ;
V_17 = F_1 ( V_2 , V_40 ) ;
if ( V_17 < 0 )
goto V_41;
if ( V_2 -> V_13 [ V_40 ] & V_42 )
F_20 ( & V_2 -> V_43 ) ;
if ( ( V_2 -> V_13 [ V_19 ] & V_44 ) == 0 )
goto V_41;
for ( V_3 = 1 ; V_3 < V_45 ; V_3 ++ ) {
V_17 = F_1 ( V_2 , V_40 + V_3 ) ;
if ( V_17 < 0 )
goto V_41;
}
if ( ( V_2 -> V_13 [ V_40 ] & V_46 ) == 0 )
goto V_41;
for ( V_36 = 0 ; V_36 < 4 ; V_36 ++ ) {
switch ( V_36 ) {
default:
V_37 = ( V_2 -> V_13 [ V_40 ] &
V_47 ) >> 9 ;
V_38 = V_2 -> V_13 [ V_48 ] ;
break;
case 1 :
V_37 = ( V_2 -> V_13 [ V_49 ] &
V_50 ) >> 14 ;
V_38 = V_2 -> V_13 [ V_51 ] ;
break;
case 2 :
V_37 = ( V_2 -> V_13 [ V_49 ] &
V_52 ) >> 12 ;
V_38 = V_2 -> V_13 [ V_53 ] ;
break;
case 3 :
V_37 = ( V_2 -> V_13 [ V_49 ] &
V_54 ) >> 10 ;
V_38 = V_2 -> V_13 [ V_55 ] ;
break;
} ;
F_21 ( V_38 , & V_39 ) ;
V_39 [ 2 ] = V_36 ;
V_39 [ 2 ] |= V_36 << 3 ;
if ( V_37 > V_56 )
V_39 [ 2 ] |= 0x80 ;
else if ( V_37 > 0 )
V_39 [ 2 ] |= 0x40 ;
memcpy ( & V_2 -> V_57 [ V_2 -> V_58 ] , & V_39 , 3 ) ;
V_2 -> V_58 += 3 ;
if ( V_2 -> V_58 >= V_2 -> V_59 )
V_2 -> V_58 = 0 ;
if ( V_2 -> V_58 == V_2 -> V_60 ) {
V_2 -> V_60 += 3 ;
if ( V_2 -> V_60 >= V_2 -> V_59 )
V_2 -> V_60 = 0 ;
}
}
if ( V_2 -> V_58 != V_2 -> V_60 )
F_22 ( & V_2 -> V_61 ) ;
V_41:
return V_62 ;
}
static int T_3 F_23 ( struct V_63 * V_8 ,
const struct V_64 * V_65 )
{
struct V_1 * V_2 ;
int V_17 = 0 ;
unsigned char V_66 = 0 ;
V_2 = F_24 ( sizeof( struct V_1 ) , V_67 ) ;
if ( ! V_2 ) {
V_17 = - V_68 ;
goto V_69;
}
V_2 -> V_8 = V_8 ;
F_25 ( & V_2 -> V_70 ) ;
V_2 -> V_71 = V_72 ;
F_26 ( & V_2 -> V_71 , V_2 ) ;
V_2 -> V_13 [ V_73 ] = V_74 ;
if ( F_5 ( V_2 , V_73 ) < 0 ) {
V_17 = - V_12 ;
goto V_75;
}
F_27 ( 110 ) ;
if ( F_8 ( V_2 ) < 0 ) {
V_17 = - V_12 ;
goto V_75;
}
F_28 ( & V_8 -> V_76 , L_1 ,
V_2 -> V_13 [ V_77 ] , V_2 -> V_13 [ V_78 ] ) ;
if ( ( V_2 -> V_13 [ V_78 ] & V_79 ) < V_80 ) {
F_29 ( & V_8 -> V_76 ,
L_2
L_3 , V_80 ) ;
F_29 ( & V_8 -> V_76 ,
L_4 ,
V_2 -> V_13 [ V_78 ] & V_79 ) ;
V_66 = 1 ;
}
if ( V_66 == 1 ) {
F_29 ( & V_8 -> V_76 ,
L_5 ) ;
F_29 ( & V_8 -> V_76 ,
L_6
L_7 ) ;
}
F_30 ( V_2 , 87.5 * V_81 ) ;
V_2 -> V_59 = V_82 * 3 ;
V_2 -> V_57 = F_31 ( V_2 -> V_59 , V_67 ) ;
if ( ! V_2 -> V_57 ) {
V_17 = - V_12 ;
goto V_75;
}
V_2 -> V_58 = 0 ;
V_2 -> V_60 = 0 ;
F_32 ( & V_2 -> V_61 ) ;
V_2 -> V_83 = true ;
F_33 ( & V_2 -> V_43 ) ;
V_17 = F_34 ( V_8 -> V_34 , NULL , F_19 ,
V_84 , V_27 , V_2 ) ;
if ( V_17 ) {
F_35 ( & V_8 -> V_76 , L_8 ) ;
goto V_85;
}
V_17 = F_36 ( & V_2 -> V_71 , V_86 ,
V_87 ) ;
if ( V_17 ) {
F_29 ( & V_8 -> V_76 , L_9 ) ;
goto V_88;
}
F_37 ( V_8 , V_2 ) ;
return 0 ;
V_88:
F_38 ( V_8 -> V_34 , V_2 ) ;
V_85:
F_39 ( V_2 -> V_57 ) ;
V_75:
F_39 ( V_2 ) ;
V_69:
return V_17 ;
}
static T_4 int F_40 ( struct V_63 * V_8 )
{
struct V_1 * V_2 = F_41 ( V_8 ) ;
F_38 ( V_8 -> V_34 , V_2 ) ;
F_42 ( & V_2 -> V_71 ) ;
F_39 ( V_2 ) ;
return 0 ;
}
static int F_43 ( struct V_89 * V_76 )
{
struct V_63 * V_8 = F_44 ( V_76 ) ;
struct V_1 * V_2 = F_41 ( V_8 ) ;
V_2 -> V_13 [ V_73 ] |= V_90 ;
if ( F_5 ( V_2 , V_73 ) < 0 )
return - V_12 ;
return 0 ;
}
static int F_45 ( struct V_89 * V_76 )
{
struct V_63 * V_8 = F_44 ( V_76 ) ;
struct V_1 * V_2 = F_41 ( V_8 ) ;
V_2 -> V_13 [ V_73 ] |= V_74 ;
if ( F_5 ( V_2 , V_73 ) < 0 )
return - V_12 ;
F_27 ( 110 ) ;
return 0 ;
}
