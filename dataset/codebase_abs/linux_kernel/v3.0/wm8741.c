static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 , 0 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
F_4 ( V_5 , V_6 ,
F_5 ( V_6 ) ) ;
F_6 ( V_5 , V_7 , F_5 ( V_7 ) ) ;
return 0 ;
}
static int F_7 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_12 * V_13 = F_8 ( V_2 ) ;
if ( ! V_13 -> V_14 ) {
F_9 ( V_2 -> V_15 ,
L_1 ) ;
return - V_16 ;
}
F_10 ( V_9 -> V_17 , 0 ,
V_18 ,
V_13 -> V_19 ) ;
return 0 ;
}
static int F_11 ( struct V_8 * V_9 ,
struct V_20 * V_21 ,
struct V_10 * V_11 )
{
struct V_22 * V_23 = V_9 -> V_24 ;
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_12 * V_13 = F_8 ( V_2 ) ;
T_1 V_25 = F_12 ( V_2 , V_26 ) & 0x1FC ;
int V_27 ;
for ( V_27 = 0 ; V_27 < F_5 ( V_28 ) ; V_27 ++ ) {
if ( V_13 -> V_14 / F_13 ( V_21 ) ==
V_28 [ V_27 ] . V_29 )
break;
}
if ( V_27 == F_5 ( V_28 ) ) {
F_9 ( V_2 -> V_15 , L_2 ,
V_13 -> V_14 / F_13 ( V_21 ) ) ;
return - V_16 ;
}
switch ( F_14 ( V_21 ) ) {
case V_30 :
break;
case V_31 :
V_25 |= 0x0001 ;
break;
case V_32 :
V_25 |= 0x0002 ;
break;
case V_33 :
V_25 |= 0x0003 ;
break;
default:
F_15 ( V_2 -> V_15 , L_3 ,
F_14 ( V_21 ) ) ;
return - V_16 ;
}
F_15 ( V_2 -> V_15 , L_4 ,
F_14 ( V_21 ) ) ;
F_2 ( V_2 , V_26 , V_25 ) ;
return 0 ;
}
static int F_16 ( struct V_10 * V_34 ,
int V_35 , unsigned int V_36 , int V_37 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_12 * V_13 = F_8 ( V_2 ) ;
F_15 ( V_2 -> V_15 , L_5 , V_36 ) ;
switch ( V_36 ) {
case 11289600 :
V_13 -> V_19 = & V_38 ;
V_13 -> V_14 = V_36 ;
return 0 ;
case 12288000 :
V_13 -> V_19 = & V_39 ;
V_13 -> V_14 = V_36 ;
return 0 ;
case 16384000 :
V_13 -> V_19 = & V_40 ;
V_13 -> V_14 = V_36 ;
return 0 ;
case 16934400 :
V_13 -> V_19 = & V_41 ;
V_13 -> V_14 = V_36 ;
return 0 ;
case 18432000 :
V_13 -> V_19 = & V_42 ;
V_13 -> V_14 = V_36 ;
return 0 ;
case 22579200 :
case 33868800 :
V_13 -> V_19 = & V_43 ;
V_13 -> V_14 = V_36 ;
return 0 ;
case 24576000 :
V_13 -> V_19 = & V_44 ;
V_13 -> V_14 = V_36 ;
return 0 ;
case 36864000 :
V_13 -> V_19 = & V_45 ;
V_13 -> V_14 = V_36 ;
return 0 ;
}
return - V_16 ;
}
static int F_17 ( struct V_10 * V_34 ,
unsigned int V_46 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
T_1 V_25 = F_12 ( V_2 , V_26 ) & 0x1C3 ;
switch ( V_46 & V_47 ) {
case V_48 :
break;
default:
return - V_16 ;
}
switch ( V_46 & V_49 ) {
case V_50 :
V_25 |= 0x0008 ;
break;
case V_51 :
break;
case V_52 :
V_25 |= 0x0004 ;
break;
case V_53 :
V_25 |= 0x0003 ;
break;
case V_54 :
V_25 |= 0x0013 ;
break;
default:
return - V_16 ;
}
switch ( V_46 & V_55 ) {
case V_56 :
break;
case V_57 :
V_25 |= 0x0010 ;
break;
case V_58 :
V_25 |= 0x0020 ;
break;
case V_59 :
V_25 |= 0x0030 ;
break;
default:
return - V_16 ;
}
F_15 ( V_2 -> V_15 , L_6 ,
V_46 & V_49 ,
( ( V_46 & V_55 ) ) ) ;
F_2 ( V_2 , V_26 , V_25 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
T_1 * V_60 = V_2 -> V_61 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_62 ; V_27 ++ ) {
if ( V_60 [ V_27 ] == V_63 [ V_27 ] || V_3 == V_27 )
continue;
F_2 ( V_2 , V_27 , V_60 [ V_27 ] ) ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_8 ( V_2 ) ;
int V_64 = 0 ;
V_64 = F_20 ( V_2 , 7 , 9 , V_13 -> V_65 ) ;
if ( V_64 != 0 ) {
F_9 ( V_2 -> V_15 , L_7 , V_64 ) ;
return V_64 ;
}
V_64 = F_1 ( V_2 ) ;
if ( V_64 < 0 ) {
F_9 ( V_2 -> V_15 , L_8 ) ;
return V_64 ;
}
F_21 ( V_2 , V_66 ,
V_67 , V_67 ) ;
F_21 ( V_2 , V_68 ,
V_69 , V_69 ) ;
F_21 ( V_2 , V_70 ,
V_71 , V_71 ) ;
F_21 ( V_2 , V_70 ,
V_72 , V_72 ) ;
F_22 ( V_2 , V_73 ,
F_5 ( V_73 ) ) ;
F_3 ( V_2 ) ;
F_15 ( V_2 -> V_15 , L_9 ) ;
return V_64 ;
}
static int F_23 ( struct V_74 * V_75 ,
const struct V_76 * V_77 )
{
struct V_12 * V_13 ;
int V_64 , V_27 ;
V_13 = F_24 ( sizeof( struct V_12 ) , V_78 ) ;
if ( V_13 == NULL )
return - V_79 ;
for ( V_27 = 0 ; V_27 < F_5 ( V_13 -> V_80 ) ; V_27 ++ )
V_13 -> V_80 [ V_27 ] . V_81 = V_82 [ V_27 ] ;
V_64 = F_25 ( & V_75 -> V_15 , F_5 ( V_13 -> V_80 ) ,
V_13 -> V_80 ) ;
if ( V_64 != 0 ) {
F_9 ( & V_75 -> V_15 , L_10 , V_64 ) ;
goto V_83;
}
V_64 = F_26 ( F_5 ( V_13 -> V_80 ) ,
V_13 -> V_80 ) ;
if ( V_64 != 0 ) {
F_9 ( & V_75 -> V_15 , L_11 , V_64 ) ;
goto V_84;
}
F_27 ( V_75 , V_13 ) ;
V_13 -> V_65 = V_85 ;
V_64 = F_28 ( & V_75 -> V_15 ,
& V_86 , & V_87 , 1 ) ;
if ( V_64 < 0 )
goto V_88;
return V_64 ;
V_88:
F_29 ( F_5 ( V_13 -> V_80 ) , V_13 -> V_80 ) ;
V_84:
F_30 ( F_5 ( V_13 -> V_80 ) , V_13 -> V_80 ) ;
V_83:
F_31 ( V_13 ) ;
return V_64 ;
}
static int F_32 ( struct V_74 * V_89 )
{
struct V_12 * V_13 = F_33 ( V_89 ) ;
F_34 ( & V_89 -> V_15 ) ;
F_30 ( F_5 ( V_13 -> V_80 ) , V_13 -> V_80 ) ;
F_31 ( F_33 ( V_89 ) ) ;
return 0 ;
}
static int T_2 F_35 ( void )
{
int V_64 = 0 ;
#if F_36 ( V_90 ) || F_36 ( V_91 )
V_64 = F_37 ( & V_92 ) ;
if ( V_64 != 0 )
F_38 ( L_12 , V_64 ) ;
#endif
return V_64 ;
}
static void T_3 F_39 ( void )
{
#if F_36 ( V_90 ) || F_36 ( V_91 )
F_40 ( & V_92 ) ;
#endif
}
