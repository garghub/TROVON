static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
F_3 ( V_2 -> V_6 -> V_7 , 0 ) ,
V_8 ,
V_9 | V_10 | V_11 ,
0 ,
0 ,
V_4 ,
sizeof( struct V_3 ) ,
V_12 ) ;
if ( V_5 < 0 )
F_4 ( & V_2 -> V_7 ,
L_1 , V_5 ) ;
F_5 ( & V_2 -> V_7 ,
L_2 ,
V_4 -> V_13 , V_4 -> V_14 , V_4 -> V_15 ,
V_4 -> V_16 , V_4 -> V_17 ) ;
return V_5 ;
}
static unsigned long F_6 ( const T_1 V_18 )
{
unsigned long V_19 = 0 ;
V_19 = ( ( V_18 & V_20 ) ? V_21 : 0 )
| ( ( V_18 & V_22 ) ? V_23 : 0 )
;
return V_19 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned long * V_24 )
{
int V_5 ;
T_2 * V_25 ;
T_1 V_18 ;
V_25 = F_8 ( V_26 , V_27 ) ;
if ( ! V_25 )
return - V_28 ;
V_25 [ 0 ] = 0xff ;
V_25 [ 1 ] = 0xff ;
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
F_9 ( V_2 -> V_6 -> V_7 , 0 ) ,
V_29 ,
V_9 | V_30 ,
0 ,
0 ,
V_25 , V_26 ,
10000
) ;
if ( V_5 != V_26 ) {
F_4 ( & V_2 -> V_7 , L_3 , V_5 ) ;
if ( V_5 >= 0 )
V_5 = - V_31 ;
} else {
V_18 = F_10 ( V_25 ) ;
F_5 ( & V_2 -> V_7 , L_4 ,
V_25 [ 0 ] , V_25 [ 1 ] ) ;
* V_24 = F_6 ( V_18 ) ;
}
F_11 ( V_25 ) ;
return V_5 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_32 * V_33 ;
V_33 = F_8 ( sizeof( * V_33 ) , V_27 ) ;
if ( ! V_33 )
return - V_28 ;
V_33 -> V_34 . V_13 = 5 ;
V_33 -> V_34 . V_14 = V_35 ;
V_33 -> V_34 . V_15 = V_36 ;
V_33 -> V_34 . V_16 = 0 ;
V_33 -> V_34 . V_17 = 1 ;
V_33 -> V_37 = 0 ;
F_13 ( & V_33 -> V_38 ) ;
F_14 ( V_2 , V_33 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_32 * V_33 ;
V_33 = F_16 ( V_2 ) ;
F_11 ( V_33 ) ;
return 0 ;
}
static int F_17 ( struct V_39 * V_40 , struct V_1 * V_2 )
{
struct V_32 * V_33 = F_16 ( V_2 ) ;
int V_41 = 0 ;
int V_5 ;
unsigned long V_37 ;
struct V_3 * V_34 ;
unsigned long V_42 ;
V_34 = F_8 ( sizeof( * V_34 ) , V_27 ) ;
if ( ! V_34 )
return - V_28 ;
V_34 -> V_13 = 5 ;
V_34 -> V_14 = V_35 ;
V_34 -> V_15 = V_36 ;
V_34 -> V_16 = 0 ;
V_34 -> V_17 = 1 ;
F_1 ( V_2 , V_34 ) ;
F_18 ( & V_33 -> V_38 , V_42 ) ;
V_33 -> V_34 . V_13 = V_34 -> V_13 ;
V_33 -> V_34 . V_14 = V_34 -> V_14 ;
V_33 -> V_34 . V_15 = V_34 -> V_15 ;
V_33 -> V_34 . V_16 = V_34 -> V_16 ;
V_33 -> V_34 . V_17 = V_34 -> V_17 ;
F_19 ( & V_33 -> V_38 , V_42 ) ;
V_5 = F_20 ( V_40 , V_2 ) ;
if ( V_5 ) {
V_41 = V_5 ;
goto V_43;
}
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
F_3 ( V_2 -> V_6 -> V_7 , 0 ) ,
V_44 ,
V_9 | V_10 | V_11 ,
V_45 ,
0 ,
NULL ,
0 ,
V_12 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_7 , L_5 , V_5 ) ;
V_41 = V_5 ;
goto V_46;
} else
F_5 ( & V_2 -> V_7 , L_6 , V_47 ) ;
V_5 = F_7 ( V_2 , & V_37 ) ;
if ( V_5 < 0 ) {
V_41 = V_5 ;
goto V_48;
}
F_18 ( & V_33 -> V_38 , V_42 ) ;
V_33 -> V_37 = V_37 ;
F_19 ( & V_33 -> V_38 , V_42 ) ;
F_5 ( & V_2 -> V_7 , L_7 , V_47 ,
V_37 ) ;
return 0 ;
V_48:
F_2 ( V_2 -> V_6 -> V_7 ,
F_3 ( V_2 -> V_6 -> V_7 , 0 ) ,
V_44 ,
V_9 | V_10 ,
V_49 ,
0 ,
NULL , 0 ,
V_12 ) ;
V_46:
F_21 ( V_2 ) ;
V_43:
F_11 ( V_34 ) ;
return V_41 ;
}
static void F_22 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
F_3 ( V_2 -> V_6 -> V_7 , 0 ) ,
V_44 ,
V_9 | V_10 ,
V_49 ,
0 ,
NULL , 0 ,
V_12 ) ;
if ( V_5 < 0 )
F_4 ( & V_2 -> V_7 , L_8 , V_5 ) ;
F_21 ( V_2 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
void * V_50 , T_3 V_51 )
{
unsigned char * V_52 = V_50 ;
int V_53 ;
V_53 = F_24 ( & V_2 -> V_54 , V_52 + V_55 , V_51 ,
& V_2 -> V_38 ) ;
F_25 ( V_53 , V_52 ) ;
return V_53 + V_55 ;
}
static void F_26 ( struct V_56 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
unsigned char * V_58 = V_56 -> V_59 ;
unsigned V_60 ;
if ( ! V_56 -> V_61 )
return;
if ( V_56 -> V_61 <= V_55 ) {
F_5 ( & V_2 -> V_7 , L_9 , V_47 ) ;
return;
}
V_60 = F_10 ( V_58 ) ;
if ( V_60 > V_56 -> V_61 - V_55 ) {
F_5 ( & V_2 -> V_7 , L_10 , V_47 ) ;
V_60 = V_56 -> V_61 - V_55 ;
}
F_27 ( & V_2 -> V_2 , V_58 + V_55 , V_60 ) ;
F_28 ( & V_2 -> V_2 ) ;
}
static void F_29 ( struct V_39 * V_40 ,
struct V_1 * V_2 ,
struct V_62 * V_63 )
{
struct V_32 * V_33 = F_16 ( V_2 ) ;
struct V_64 * V_7 = & V_2 -> V_7 ;
unsigned int V_65 = V_40 -> V_66 . V_67 ;
unsigned int V_68 = V_63 -> V_67 ;
unsigned int V_69 = V_40 -> V_66 . V_70 ;
unsigned int V_71 = V_63 -> V_70 ;
struct V_3 * V_34 ;
unsigned long V_42 ;
T_4 V_72 ;
V_34 = F_8 ( sizeof( * V_34 ) , V_27 ) ;
if ( ! V_34 )
return;
F_18 ( & V_33 -> V_38 , V_42 ) ;
V_72 = F_30 ( V_40 ) ;
switch ( V_72 ) {
case 0 :
break;
case 1200 :
V_33 -> V_34 . V_14 = V_73 ;
break;
case 2400 :
V_33 -> V_34 . V_14 = V_74 ;
break;
case 4800 :
V_33 -> V_34 . V_14 = V_75 ;
break;
case 9600 :
V_33 -> V_34 . V_14 = V_35 ;
break;
case 19200 :
V_33 -> V_34 . V_14 = V_76 ;
break;
case 38400 :
V_33 -> V_34 . V_14 = V_77 ;
break;
case 57600 :
V_33 -> V_34 . V_14 = V_78 ;
break;
case 115200 :
V_33 -> V_34 . V_14 = V_79 ;
break;
default:
F_5 ( V_7 , L_11 ) ;
V_33 -> V_34 . V_14 = V_35 ;
V_72 = 9600 ;
break;
}
F_31 ( V_40 , V_72 , V_72 ) ;
if ( ( V_69 & V_80 ) != ( V_71 & V_80 ) ) {
switch ( V_69 & V_80 ) {
case V_81 :
F_5 ( V_7 , L_12 , V_47 ) ;
F_19 ( & V_33 -> V_38 , V_42 ) ;
goto V_82;
case V_83 :
F_5 ( V_7 , L_13 , V_47 ) ;
F_19 ( & V_33 -> V_38 , V_42 ) ;
goto V_82;
case V_84 :
V_33 -> V_34 . V_15 = V_85 ;
break;
case V_86 :
V_33 -> V_34 . V_15 = V_36 ;
break;
default:
F_4 ( V_7 , L_14 ) ;
V_33 -> V_34 . V_15 = V_36 ;
break;
}
}
if ( ( V_69 & ( V_87 | V_88 ) ) != ( V_71 & ( V_87 | V_88 ) )
|| ( V_69 & V_89 ) != ( V_71 & V_89 ) ) {
V_40 -> V_66 . V_70 &= ~ ( V_87 | V_88 | V_89 ) ;
}
if ( ( V_65 & V_90 ) != ( V_68 & V_90 )
|| ( V_65 & V_91 ) != ( V_68 & V_91 )
|| ( V_69 & V_92 ) != ( V_71 & V_92 ) ) {
V_40 -> V_66 . V_70 &= ~ V_92 ;
}
memcpy ( V_34 , & V_33 -> V_34 , sizeof( * V_34 ) ) ;
F_19 ( & V_33 -> V_38 , V_42 ) ;
F_1 ( V_2 , V_34 ) ;
V_82:
F_11 ( V_34 ) ;
}
static int F_32 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_93 ;
struct V_32 * V_33 = F_16 ( V_2 ) ;
unsigned long V_42 ;
int V_5 ;
unsigned long V_37 ;
V_5 = F_7 ( V_2 , & V_37 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_7 ,
L_15 , V_5 ) ;
return V_5 ;
}
F_18 ( & V_33 -> V_38 , V_42 ) ;
V_33 -> V_37 = V_37 ;
F_19 ( & V_33 -> V_38 , V_42 ) ;
F_5 ( & V_2 -> V_7 , L_7 , V_47 , V_37 ) ;
return ( int ) V_37 ;
}
