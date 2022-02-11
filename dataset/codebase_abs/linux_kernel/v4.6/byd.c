static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_5 * V_6 = V_1 -> V_6 ;
F_2 ( V_6 , V_7 , V_3 -> V_8 ) ;
F_2 ( V_6 , V_9 , V_3 -> V_8 ) ;
F_3 ( V_6 , V_10 , V_3 -> V_11 ) ;
F_3 ( V_6 , V_12 , V_3 -> V_13 ) ;
F_2 ( V_6 , V_14 , V_3 -> V_15 ) ;
F_2 ( V_6 , V_16 , V_3 -> V_17 ) ;
F_4 ( V_6 ) ;
}
static void F_5 ( unsigned long V_18 )
{
struct V_1 * V_1 = (struct V_1 * ) V_18 ;
struct V_2 * V_3 = V_1 -> V_4 ;
F_6 ( V_1 -> V_19 . V_20 ) ;
V_3 -> V_8 = false ;
F_1 ( V_1 ) ;
F_7 ( V_1 -> V_19 . V_20 ) ;
V_3 -> V_11 = V_21 / 2 ;
V_3 -> V_13 = V_22 / 2 ;
}
static T_1 F_8 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
T_2 * V_23 = V_1 -> V_24 ;
if ( V_1 -> V_25 > 0 && ! ( V_23 [ 0 ] & V_26 ) ) {
F_9 ( V_1 , L_1 ,
V_23 [ 0 ] ) ;
return V_27 ;
}
if ( V_1 -> V_25 < V_1 -> V_28 )
return V_29 ;
switch ( V_23 [ 3 ] ) {
case V_30 :
if ( ! V_3 -> V_8 ) {
F_10 (jiffies) V_31 =
V_3 -> V_32 + V_33 ;
V_3 -> V_8 = F_11 ( V_34 , V_31 ) ;
V_3 -> V_11 = V_23 [ 1 ] * ( V_21 / 256 ) ;
V_3 -> V_13 = ( 255 - V_23 [ 2 ] ) * ( V_22 / 256 ) ;
}
break;
case V_35 : {
T_3 V_36 = V_23 [ 0 ] & V_37 ? ~ 0xFF : 0 ;
T_3 V_38 = V_23 [ 0 ] & V_39 ? ~ 0xFF : 0 ;
T_4 V_40 = V_36 | ( int ) V_23 [ 1 ] ;
T_4 V_41 = V_38 | ( int ) V_23 [ 2 ] ;
V_3 -> V_11 += V_40 * V_42 ;
V_3 -> V_13 -= V_41 * V_42 ;
V_3 -> V_8 = true ;
break;
}
default:
F_9 ( V_1 ,
L_2 ,
V_1 -> V_24 [ 0 ] , V_1 -> V_24 [ 1 ] ,
V_1 -> V_24 [ 2 ] , V_1 -> V_24 [ 3 ] ) ;
return V_27 ;
}
V_3 -> V_15 = V_23 [ 0 ] & V_43 ;
V_3 -> V_17 = V_23 [ 0 ] & V_44 ;
F_1 ( V_1 ) ;
if ( V_3 -> V_8 ) {
V_3 -> V_32 = V_34 ;
F_12 ( & V_3 -> V_45 , V_34 + V_33 ) ;
}
return V_46 ;
}
static int F_13 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = & V_1 -> V_19 ;
T_2 V_47 [ 4 ] ;
T_5 V_48 ;
const struct {
T_6 V_49 ;
T_2 V_50 ;
} V_51 [] = {
{ V_52 , 0xC8 } ,
{ V_52 , 0x64 } ,
{ V_52 , 0x50 } ,
{ V_53 , 0 } ,
{ V_54 , 0 } ,
{ 0x10E2 , 0x00 } ,
{ 0x10E0 , 0x02 } ,
{ 0x14E0 , 0x01 } ,
{ V_55 , 0x01 } ,
{ V_56 , 0x04 } ,
{ V_57 , 0x02 } ,
{ V_58 , 0x04 } ,
{ V_59 , 0x04 } ,
{ V_60 , 0x01 } ,
{ V_61 , 0x00 } ,
{ V_62 , 0x02 } ,
{ V_63 , 0x04 } ,
{ V_64 , 0x04 } ,
{ V_65 , 0x00 } ,
{ V_66 , 0x00 } ,
{ V_67 , 0x00 } ,
{ V_68 , 0x00 } ,
{ V_69 , 0x02 } ,
{ 0x10E0 , 0x00 } ,
{ 0x10E2 , 0x01 } ,
} ;
for ( V_48 = 0 ; V_48 < F_14 ( V_51 ) ; ++ V_48 ) {
memset ( V_47 , 0 , sizeof( V_47 ) ) ;
V_47 [ 0 ] = V_51 [ V_48 ] . V_50 ;
if ( F_15 ( V_19 , V_47 , V_51 [ V_48 ] . V_49 ) )
return - V_70 ;
}
F_16 ( V_1 , V_71 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_1 )
{
int V_72 = 0 , error = 0 ;
F_18 ( V_1 , L_3 ) ;
do {
F_19 ( V_1 ) ;
if ( V_72 )
F_20 ( 1 ) ;
error = F_21 ( V_1 , 0 ) ;
} while ( error && ++ V_72 < 3 );
if ( error )
return error ;
F_18 ( V_1 , L_4 , V_72 ) ;
error = F_13 ( V_1 ) ;
if ( error ) {
F_22 ( V_1 , L_5 ) ;
return error ;
}
return 0 ;
}
static void F_23 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
if ( V_3 ) {
F_24 ( & V_3 -> V_45 ) ;
F_25 ( V_1 -> V_4 ) ;
V_1 -> V_4 = NULL ;
}
}
int F_21 ( struct V_1 * V_1 , bool V_73 )
{
struct V_19 * V_19 = & V_1 -> V_19 ;
T_2 V_47 [ 4 ] = { 0x03 , 0x00 , 0x00 , 0x00 } ;
if ( F_15 ( V_19 , V_47 , V_74 ) )
return - 1 ;
if ( F_15 ( V_19 , V_47 , V_74 ) )
return - 1 ;
if ( F_15 ( V_19 , V_47 , V_74 ) )
return - 1 ;
if ( F_15 ( V_19 , V_47 , V_74 ) )
return - 1 ;
if ( F_15 ( V_19 , V_47 , V_75 ) )
return - 1 ;
if ( V_47 [ 1 ] != 0x03 || V_47 [ 2 ] != 0x64 )
return - V_76 ;
F_18 ( V_1 , L_6 ) ;
if ( V_73 ) {
V_1 -> V_77 = L_7 ;
V_1 -> V_78 = L_8 ;
}
return 0 ;
}
int F_26 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_6 ;
struct V_2 * V_3 ;
if ( F_19 ( V_1 ) )
return - V_70 ;
if ( F_13 ( V_1 ) )
return - V_70 ;
V_3 = F_27 ( sizeof( * V_3 ) , V_79 ) ;
if ( ! V_3 )
return - V_80 ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
F_28 ( & V_3 -> V_45 , F_5 , ( unsigned long ) V_1 ) ;
V_1 -> V_4 = V_3 ;
V_1 -> V_81 = F_23 ;
V_1 -> V_82 = F_17 ;
V_1 -> V_83 = F_8 ;
V_1 -> V_28 = 4 ;
V_1 -> V_84 = 0 ;
F_29 ( V_85 , V_6 -> V_86 ) ;
F_29 ( V_7 , V_6 -> V_87 ) ;
F_29 ( V_9 , V_6 -> V_87 ) ;
F_29 ( V_14 , V_6 -> V_87 ) ;
F_29 ( V_16 , V_6 -> V_87 ) ;
F_30 ( V_88 , V_6 -> V_87 ) ;
F_29 ( V_89 , V_6 -> V_90 ) ;
F_31 ( V_6 , V_10 , 0 , V_21 , 0 , 0 ) ;
F_31 ( V_6 , V_12 , 0 , V_22 , 0 , 0 ) ;
F_32 ( V_6 , V_10 , V_91 ) ;
F_32 ( V_6 , V_12 , V_91 ) ;
F_30 ( V_92 , V_6 -> V_90 ) ;
F_30 ( V_93 , V_6 -> V_94 ) ;
F_30 ( V_95 , V_6 -> V_94 ) ;
return 0 ;
}
