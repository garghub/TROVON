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
V_25 -> V_30 = V_31 | V_32 |
V_33 | V_34 | V_35 ;
V_25 -> V_36 = V_25 -> V_30 | V_37 ;
return 0 ;
}
static T_2 F_19 ( int V_38 , void * V_39 )
{
struct V_1 * V_2 = V_39 ;
unsigned char V_3 ;
unsigned char V_40 ;
unsigned short V_41 ;
unsigned short V_42 ;
unsigned char V_43 [ 3 ] ;
int V_17 = 0 ;
V_17 = F_1 ( V_2 , V_44 ) ;
if ( V_17 < 0 )
goto V_45;
if ( V_2 -> V_13 [ V_44 ] & V_46 )
F_20 ( & V_2 -> V_47 ) ;
if ( ( V_2 -> V_13 [ V_19 ] & V_48 ) == 0 )
goto V_45;
for ( V_3 = 1 ; V_3 < V_49 ; V_3 ++ ) {
V_17 = F_1 ( V_2 , V_44 + V_3 ) ;
if ( V_17 < 0 )
goto V_45;
}
if ( ( V_2 -> V_13 [ V_44 ] & V_50 ) == 0 )
goto V_45;
for ( V_40 = 0 ; V_40 < 4 ; V_40 ++ ) {
switch ( V_40 ) {
default:
V_41 = ( V_2 -> V_13 [ V_44 ] &
V_51 ) >> 9 ;
V_42 = V_2 -> V_13 [ V_52 ] ;
break;
case 1 :
V_41 = ( V_2 -> V_13 [ V_53 ] &
V_54 ) >> 14 ;
V_42 = V_2 -> V_13 [ V_55 ] ;
break;
case 2 :
V_41 = ( V_2 -> V_13 [ V_53 ] &
V_56 ) >> 12 ;
V_42 = V_2 -> V_13 [ V_57 ] ;
break;
case 3 :
V_41 = ( V_2 -> V_13 [ V_53 ] &
V_58 ) >> 10 ;
V_42 = V_2 -> V_13 [ V_59 ] ;
break;
} ;
F_21 ( V_42 , & V_43 ) ;
V_43 [ 2 ] = V_40 ;
V_43 [ 2 ] |= V_40 << 3 ;
if ( V_41 > V_60 )
V_43 [ 2 ] |= 0x80 ;
else if ( V_41 > 0 )
V_43 [ 2 ] |= 0x40 ;
memcpy ( & V_2 -> V_61 [ V_2 -> V_62 ] , & V_43 , 3 ) ;
V_2 -> V_62 += 3 ;
if ( V_2 -> V_62 >= V_2 -> V_63 )
V_2 -> V_62 = 0 ;
if ( V_2 -> V_62 == V_2 -> V_64 ) {
V_2 -> V_64 += 3 ;
if ( V_2 -> V_64 >= V_2 -> V_63 )
V_2 -> V_64 = 0 ;
}
}
if ( V_2 -> V_62 != V_2 -> V_64 )
F_22 ( & V_2 -> V_65 ) ;
V_45:
return V_66 ;
}
static int T_3 F_23 ( struct V_67 * V_8 ,
const struct V_68 * V_69 )
{
struct V_1 * V_2 ;
int V_17 = 0 ;
unsigned char V_70 = 0 ;
V_2 = F_24 ( sizeof( struct V_1 ) , V_71 ) ;
if ( ! V_2 ) {
V_17 = - V_72 ;
goto V_73;
}
V_2 -> V_8 = V_8 ;
V_2 -> V_74 = 1 ;
F_25 ( & V_2 -> V_75 ) ;
F_26 ( & V_2 -> V_47 ) ;
V_2 -> V_76 = V_77 ;
F_27 ( & V_2 -> V_76 , V_2 ) ;
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
V_70 = 1 ;
}
if ( V_70 == 1 ) {
F_30 ( & V_8 -> V_81 ,
L_5 ) ;
F_30 ( & V_8 -> V_81 ,
L_6
L_7 ) ;
}
F_31 ( V_2 , 87.5 * V_86 ) ;
V_2 -> V_63 = V_87 * 3 ;
V_2 -> V_61 = F_32 ( V_2 -> V_63 , V_71 ) ;
if ( ! V_2 -> V_61 ) {
V_17 = - V_12 ;
goto V_80;
}
V_2 -> V_62 = 0 ;
V_2 -> V_64 = 0 ;
F_33 ( & V_2 -> V_65 ) ;
V_17 = F_34 ( V_8 -> V_38 , NULL , F_19 ,
V_88 , V_27 , V_2 ) ;
if ( V_17 ) {
F_35 ( & V_8 -> V_81 , L_8 ) ;
goto V_89;
}
V_17 = F_36 ( & V_2 -> V_76 , V_90 ,
V_91 ) ;
if ( V_17 ) {
F_30 ( & V_8 -> V_81 , L_9 ) ;
goto V_92;
}
F_37 ( V_8 , V_2 ) ;
return 0 ;
V_92:
F_38 ( V_8 -> V_38 , V_2 ) ;
V_89:
F_39 ( V_2 -> V_61 ) ;
V_80:
F_39 ( V_2 ) ;
V_73:
return V_17 ;
}
static T_4 int F_40 ( struct V_67 * V_8 )
{
struct V_1 * V_2 = F_41 ( V_8 ) ;
F_38 ( V_8 -> V_38 , V_2 ) ;
F_42 ( & V_2 -> V_76 ) ;
F_39 ( V_2 ) ;
return 0 ;
}
static int F_43 ( struct V_93 * V_81 )
{
struct V_67 * V_8 = F_44 ( V_81 ) ;
struct V_1 * V_2 = F_41 ( V_8 ) ;
V_2 -> V_13 [ V_78 ] |= V_94 ;
if ( F_5 ( V_2 , V_78 ) < 0 )
return - V_12 ;
return 0 ;
}
static int F_45 ( struct V_93 * V_81 )
{
struct V_67 * V_8 = F_44 ( V_81 ) ;
struct V_1 * V_2 = F_41 ( V_8 ) ;
V_2 -> V_13 [ V_78 ] |= V_79 ;
if ( F_5 ( V_2 , V_78 ) < 0 )
return - V_12 ;
F_28 ( 110 ) ;
return 0 ;
}
