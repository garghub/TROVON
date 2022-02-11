static int F_1 ( struct V_1 * V_1 , unsigned short V_2 )
{
if ( ! V_1 -> V_3 )
return 0 ;
switch ( V_2 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
return 1 ;
default:
return 0 ;
}
}
void F_2 ( struct V_1 * V_1 )
{
int V_10 ;
V_10 = F_3 ( V_1 , V_11 , 0 ) ;
if ( V_10 == 0 ) {
F_4 ( V_1 -> V_12 , L_1 ) ;
F_5 ( & V_1 -> V_13 ) ;
F_6 ( V_1 -> V_3 ) ;
V_1 -> V_3 = 1 ;
F_7 ( & V_1 -> V_13 ) ;
} else {
F_8 ( V_1 -> V_12 , L_2 , V_10 ) ;
}
}
int F_9 ( struct V_1 * V_1 )
{
int V_10 ;
V_10 = F_3 ( V_1 , V_11 , 0x9716 ) ;
if ( V_10 == 0 ) {
F_4 ( V_1 -> V_12 , L_3 ) ;
F_5 ( & V_1 -> V_13 ) ;
F_6 ( ! V_1 -> V_3 ) ;
V_1 -> V_3 = 0 ;
F_7 ( & V_1 -> V_13 ) ;
}
return V_10 ;
}
static int F_10 ( struct V_1 * V_1 , unsigned short V_2 ,
int V_14 , void * V_15 )
{
int V_10 , V_16 ;
T_1 * V_17 = V_15 ;
F_11 ( V_14 % 2 ) ;
F_11 ( V_14 <= 0 ) ;
V_10 = V_1 -> V_18 ( V_1 , V_2 , V_14 , V_15 ) ;
if ( V_10 < 0 )
return V_10 ;
for ( V_16 = 0 ; V_16 < V_14 / 2 ; V_16 ++ ) {
V_17 [ V_16 ] = F_12 ( V_17 [ V_16 ] ) ;
F_4 ( V_1 -> V_12 , L_4 ,
V_17 [ V_16 ] , V_2 + V_16 , V_2 + V_16 ) ;
}
return 0 ;
}
int F_13 ( struct V_1 * V_1 , unsigned short V_2 )
{
unsigned short V_19 ;
int V_10 ;
F_5 ( & V_1 -> V_13 ) ;
V_10 = F_10 ( V_1 , V_2 , 2 , & V_19 ) ;
F_7 ( & V_1 -> V_13 ) ;
if ( V_10 < 0 )
return V_10 ;
else
return V_19 ;
}
int F_14 ( struct V_1 * V_1 , unsigned short V_2 ,
int V_20 , T_1 * V_17 )
{
int V_10 ;
F_5 ( & V_1 -> V_13 ) ;
V_10 = F_10 ( V_1 , V_2 , V_20 * 2 , V_17 ) ;
F_7 ( & V_1 -> V_13 ) ;
return V_10 ;
}
static int F_15 ( struct V_1 * V_1 , unsigned short V_2 ,
int V_14 , void * V_21 )
{
T_1 * V_17 = V_21 ;
int V_16 ;
F_11 ( V_14 % 2 ) ;
F_11 ( V_14 <= 0 ) ;
for ( V_16 = 0 ; V_16 < V_14 / 2 ; V_16 ++ ) {
if ( F_1 ( V_1 , V_2 ) )
return - V_22 ;
F_4 ( V_1 -> V_12 , L_5 ,
V_17 [ V_16 ] , V_2 + V_16 , V_2 + V_16 ) ;
V_17 [ V_16 ] = F_16 ( V_17 [ V_16 ] ) ;
}
return V_1 -> V_23 ( V_1 , V_2 , V_14 , V_21 ) ;
}
int F_3 ( struct V_1 * V_1 , unsigned short V_2 ,
unsigned short V_19 )
{
int V_10 ;
F_5 ( & V_1 -> V_13 ) ;
V_10 = F_15 ( V_1 , V_2 , 2 , & V_19 ) ;
F_7 ( & V_1 -> V_13 ) ;
return V_10 ;
}
int F_17 ( struct V_1 * V_1 , unsigned short V_2 ,
unsigned short V_24 , unsigned short V_19 )
{
int V_10 ;
T_1 V_25 ;
F_5 ( & V_1 -> V_13 ) ;
V_10 = F_10 ( V_1 , V_2 , 2 , & V_25 ) ;
if ( V_10 < 0 )
goto V_26;
V_25 &= ~ V_24 ;
V_25 |= V_19 ;
V_10 = F_15 ( V_1 , V_2 , 2 , & V_25 ) ;
V_26:
F_7 ( & V_1 -> V_13 ) ;
return V_10 ;
}
int F_18 ( struct V_1 * V_1 , enum V_27 V_28 )
{
int V_10 , V_21 , V_29 , V_30 ;
V_29 = F_13 ( V_1 , V_31 ) ;
V_29 &= V_32 ;
F_5 ( & V_1 -> V_33 ) ;
V_10 = F_17 ( V_1 , V_34 ,
V_35 , V_35 ) ;
if ( V_10 < 0 ) {
F_8 ( V_1 -> V_12 , L_6 , V_10 ) ;
goto V_26;
}
V_21 = V_28 ;
V_10 = F_3 ( V_1 , V_36 ,
1 << V_21 ) ;
if ( V_10 < 0 ) {
F_8 ( V_1 -> V_12 , L_7 , V_10 ) ;
goto V_26;
}
F_19 ( & V_1 -> V_37 ) ;
V_10 = F_17 ( V_1 , V_34 ,
V_38 , V_38 ) ;
if ( V_10 < 0 ) {
F_8 ( V_1 -> V_12 , L_8 , V_10 ) ;
goto V_39;
}
if ( V_29 ) {
V_30 = 5 ;
while ( V_30 ) {
F_20 ( 1 ) ;
V_10 = F_13 ( V_1 ,
V_40 ) ;
if ( V_10 < 0 ) {
F_8 ( V_1 -> V_12 ,
L_9 , V_10 ) ;
goto V_39;
}
if ( V_10 & V_32 ) {
F_3 ( V_1 ,
V_40 ,
V_32 ) ;
break;
} else {
F_8 ( V_1 -> V_12 ,
L_10 ) ;
V_10 = - V_41 ;
goto V_39;
}
}
} else {
if ( ! F_21 ( & V_1 -> V_37 ,
F_22 ( 500 ) ) ) {
F_8 ( V_1 -> V_12 , L_11 ) ;
V_10 = - V_41 ;
goto V_39;
}
}
V_10 = F_13 ( V_1 , V_42 ) ;
if ( V_10 < 0 ) {
F_8 ( V_1 -> V_12 , L_12 , V_10 ) ;
} else {
V_21 = ( ( V_10 & V_43 )
>> V_44 ) - 1 ;
if ( V_21 == 14 )
V_21 = V_45 ;
if ( V_21 != V_28 ) {
F_8 ( V_1 -> V_12 , L_13 ,
V_21 , V_28 ) ;
V_10 = - V_46 ;
} else {
V_10 &= V_47 ;
}
}
V_39:
F_17 ( V_1 , V_34 , V_35 , 0 ) ;
V_26:
F_7 ( & V_1 -> V_33 ) ;
return V_10 ;
}
static T_2 F_23 ( int V_48 , void * V_49 )
{
struct V_1 * V_1 = V_49 ;
F_24 ( & V_1 -> V_37 ) ;
return V_50 ;
}
int F_25 ( struct V_1 * V_1 , enum V_27 V_28 )
{
int V_10 ;
V_10 = F_18 ( V_1 , V_28 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 *= 1465 ;
return V_10 ;
}
int F_26 ( struct V_1 * V_1 , unsigned long V_51 , int V_48 )
{
struct V_52 * V_53 = V_1 -> V_12 -> V_54 ;
int V_55 ;
enum V_56 V_57 ;
int V_10 , V_16 ;
F_27 ( & V_1 -> V_13 ) ;
F_27 ( & V_1 -> V_58 ) ;
F_27 ( & V_1 -> V_33 ) ;
F_28 ( & V_1 -> V_37 ) ;
F_29 ( V_1 -> V_12 , V_1 ) ;
V_10 = F_13 ( V_1 , V_59 ) ;
if ( V_10 < 0 ) {
F_8 ( V_1 -> V_12 , L_14 , V_10 ) ;
goto V_60;
}
switch ( V_10 ) {
case 0x6204 :
case 0x6246 :
break;
default:
F_8 ( V_1 -> V_12 , L_15 , V_10 ) ;
V_10 = - V_46 ;
goto V_60;
}
V_10 = F_13 ( V_1 , V_61 ) ;
if ( V_10 < 0 ) {
F_8 ( V_1 -> V_12 , L_16 , V_10 ) ;
goto V_60;
}
V_55 = ( V_10 & V_62 ) >> V_63 ;
V_10 = F_13 ( V_1 , V_64 ) ;
if ( V_10 < 0 ) {
F_8 ( V_1 -> V_12 , L_17 , V_10 ) ;
goto V_60;
}
if ( V_10 == 0 ) {
F_30 ( V_1 -> V_12 , L_18 ) ;
V_10 = V_51 ;
}
switch ( V_10 ) {
case V_65 :
V_57 = V_65 ;
V_1 -> V_66 = 16 ;
V_1 -> V_67 = 1 ;
if ( V_55 > 0 ) {
V_1 -> V_68 = 1 ;
V_1 -> V_69 = 1 ;
}
F_30 ( V_1 -> V_12 , L_19 , 'A' + V_55 ) ;
break;
case V_70 :
V_57 = V_70 ;
V_1 -> V_66 = 16 ;
V_1 -> V_67 = 1 ;
if ( V_55 > 0 ) {
V_1 -> V_68 = 1 ;
V_1 -> V_69 = 1 ;
}
F_30 ( V_1 -> V_12 , L_20 , 'A' + V_55 ) ;
break;
case V_71 :
V_57 = V_71 ;
V_1 -> V_66 = 16 ;
V_1 -> V_67 = 1 ;
if ( V_55 > 0 ) {
V_1 -> V_68 = 1 ;
V_1 -> V_69 = 1 ;
}
F_30 ( V_1 -> V_12 , L_21 , 'A' + V_55 ) ;
break;
case V_72 :
V_57 = V_72 ;
V_1 -> V_66 = 12 ;
F_30 ( V_1 -> V_12 , L_22 , 'A' + V_55 ) ;
break;
case V_73 :
V_57 = V_73 ;
V_1 -> V_66 = 12 ;
F_30 ( V_1 -> V_12 , L_23 , 'A' + V_55 ) ;
break;
case V_74 :
V_57 = V_74 ;
V_1 -> V_66 = 12 ;
F_30 ( V_1 -> V_12 , L_24 , 'A' + V_55 ) ;
break;
case V_75 :
V_57 = V_75 ;
V_1 -> V_66 = 12 ;
F_30 ( V_1 -> V_12 , L_25 , 'A' + V_55 ) ;
break;
default:
F_8 ( V_1 -> V_12 , L_26 , V_10 ) ;
V_10 = - V_46 ;
goto V_60;
}
if ( V_57 != V_51 )
F_31 ( V_1 -> V_12 , L_27 ,
V_51 ) ;
V_10 = F_13 ( V_1 , V_11 ) ;
if ( V_10 < 0 ) {
F_8 ( V_1 -> V_12 , L_28 , V_10 ) ;
goto V_60;
}
if ( V_10 != 0 ) {
F_31 ( V_1 -> V_12 , L_29 ,
V_10 ) ;
F_3 ( V_1 , V_11 , 0 ) ;
}
V_1 -> V_3 = 1 ;
if ( V_53 && V_53 -> V_76 ) {
V_10 = V_53 -> V_76 ( V_1 ) ;
if ( V_10 != 0 ) {
F_8 ( V_1 -> V_12 , L_30 , V_10 ) ;
goto V_60;
}
}
if ( V_53 ) {
for ( V_16 = 0 ; V_16 < F_32 ( V_53 -> V_77 ) ; V_16 ++ ) {
if ( ! V_53 -> V_77 [ V_16 ] )
continue;
F_3 ( V_1 ,
V_78 + V_16 ,
V_53 -> V_77 [ V_16 ] & 0xffff ) ;
}
}
V_10 = F_33 ( V_1 , V_48 ) ;
if ( V_10 != 0 )
goto V_60;
if ( V_1 -> V_79 ) {
V_10 = F_34 ( V_1 -> V_79 +
V_80 ,
NULL , F_23 , 0 ,
L_31 , V_1 ) ;
if ( V_10 < 0 )
F_8 ( V_1 -> V_12 , L_32 ,
V_10 ) ;
}
switch ( V_57 ) {
case V_65 :
V_10 = F_35 ( V_1 -> V_12 , - 1 ,
V_81 , F_32 ( V_81 ) ,
NULL , V_1 -> V_79 ) ;
break;
case V_70 :
V_10 = F_35 ( V_1 -> V_12 , - 1 ,
V_82 , F_32 ( V_82 ) ,
NULL , V_1 -> V_79 ) ;
break;
case V_71 :
V_10 = F_35 ( V_1 -> V_12 , - 1 ,
V_83 , F_32 ( V_83 ) ,
NULL , V_1 -> V_79 ) ;
break;
case V_72 :
case V_73 :
case V_74 :
case V_75 :
V_10 = F_35 ( V_1 -> V_12 , - 1 ,
V_84 , F_32 ( V_84 ) ,
NULL , V_1 -> V_79 ) ;
break;
default:
F_36 () ;
}
if ( V_10 != 0 ) {
F_8 ( V_1 -> V_12 , L_33 ) ;
goto V_85;
}
if ( V_53 && V_53 -> V_86 ) {
V_10 = F_35 ( V_1 -> V_12 , - 1 , V_87 ,
F_32 ( V_87 ) , NULL ,
V_1 -> V_79 ) ;
if ( V_10 < 0 )
F_8 ( V_1 -> V_12 , L_34 ,
V_10 ) ;
}
F_37 ( V_1 ) ;
if ( V_53 && V_53 -> V_88 ) {
V_10 = V_53 -> V_88 ( V_1 ) ;
if ( V_10 != 0 ) {
F_8 ( V_1 -> V_12 , L_35 , V_10 ) ;
goto V_85;
}
}
return 0 ;
V_85:
F_38 ( V_1 ) ;
V_60:
F_39 ( V_1 -> V_12 ) ;
F_40 ( V_1 ) ;
return V_10 ;
}
void F_41 ( struct V_1 * V_1 )
{
F_42 ( V_1 ) ;
F_39 ( V_1 -> V_12 ) ;
if ( V_1 -> V_79 )
F_43 ( V_1 -> V_79 + V_80 , V_1 ) ;
F_38 ( V_1 ) ;
F_40 ( V_1 ) ;
}
int F_44 ( struct V_1 * V_1 )
{
int V_2 , V_24 ;
if ( V_1 -> V_67 ) {
V_2 = F_13 ( V_1 , V_89 ) ;
V_24 = V_90 |
V_91 |
V_92 |
V_93 | V_94 |
V_95 | V_96 |
V_97 ;
if ( V_2 & V_24 )
V_2 = F_13 ( V_1 ,
V_98 ) ;
if ( V_2 & V_24 ) {
F_30 ( V_1 -> V_12 ,
L_36 ,
V_2 & V_24 ) ;
F_3 ( V_1 , V_98 ,
V_2 & V_24 ) ;
}
}
return 0 ;
}
