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
V_25 |= V_19 & V_24 ;
V_10 = F_15 ( V_1 , V_2 , 2 , & V_25 ) ;
V_26:
F_7 ( & V_1 -> V_13 ) ;
return V_10 ;
}
int F_18 ( struct V_1 * V_1 , unsigned long V_27 , int V_28 )
{
struct V_29 * V_30 = V_1 -> V_12 -> V_31 ;
int V_32 , V_33 ;
enum V_34 V_35 ;
int V_10 , V_16 ;
F_19 ( & V_1 -> V_13 ) ;
F_19 ( & V_1 -> V_36 ) ;
F_20 ( V_1 -> V_12 , V_1 ) ;
V_10 = F_13 ( V_1 , V_37 ) ;
if ( V_10 < 0 ) {
F_8 ( V_1 -> V_12 , L_6 , V_10 ) ;
goto V_38;
}
switch ( V_10 ) {
case 0x6204 :
case 0x6246 :
break;
default:
F_8 ( V_1 -> V_12 , L_7 , V_10 ) ;
V_10 = - V_39 ;
goto V_38;
}
V_10 = F_13 ( V_1 , V_40 ) ;
if ( V_10 < 0 ) {
F_8 ( V_1 -> V_12 , L_8 , V_10 ) ;
goto V_38;
}
V_32 = ( V_10 & V_41 ) >> V_42 ;
V_10 = F_13 ( V_1 , V_43 ) ;
if ( V_10 < 0 ) {
F_8 ( V_1 -> V_12 , L_9 , V_10 ) ;
goto V_38;
}
if ( V_10 == 0 ) {
F_21 ( V_1 -> V_12 , L_10 ) ;
V_10 = V_27 ;
}
switch ( V_10 ) {
case V_44 :
V_35 = V_44 ;
V_1 -> V_45 = 16 ;
V_1 -> V_46 = 1 ;
if ( V_32 > 0 ) {
V_1 -> V_47 = 1 ;
V_1 -> V_48 = 1 ;
}
F_21 ( V_1 -> V_12 , L_11 , 'A' + V_32 ) ;
break;
case V_49 :
V_35 = V_49 ;
V_1 -> V_45 = 16 ;
V_1 -> V_46 = 1 ;
if ( V_32 > 0 ) {
V_1 -> V_47 = 1 ;
V_1 -> V_48 = 1 ;
}
F_21 ( V_1 -> V_12 , L_12 , 'A' + V_32 ) ;
break;
case V_50 :
V_35 = V_50 ;
V_1 -> V_45 = 16 ;
V_1 -> V_46 = 1 ;
if ( V_32 > 0 ) {
V_1 -> V_47 = 1 ;
V_1 -> V_48 = 1 ;
}
F_21 ( V_1 -> V_12 , L_13 , 'A' + V_32 ) ;
break;
case V_51 :
V_35 = V_51 ;
V_1 -> V_45 = 12 ;
F_21 ( V_1 -> V_12 , L_14 , 'A' + V_32 ) ;
break;
case V_52 :
V_35 = V_52 ;
V_1 -> V_45 = 12 ;
F_21 ( V_1 -> V_12 , L_15 , 'A' + V_32 ) ;
break;
case V_53 :
V_35 = V_53 ;
V_1 -> V_45 = 12 ;
F_21 ( V_1 -> V_12 , L_16 , 'A' + V_32 ) ;
break;
case V_54 :
V_35 = V_54 ;
V_1 -> V_45 = 12 ;
F_21 ( V_1 -> V_12 , L_17 , 'A' + V_32 ) ;
break;
default:
F_8 ( V_1 -> V_12 , L_18 , V_10 ) ;
V_10 = - V_39 ;
goto V_38;
}
if ( V_35 != V_27 )
F_22 ( V_1 -> V_12 , L_19 ,
V_27 ) ;
V_10 = F_13 ( V_1 , V_11 ) ;
if ( V_10 < 0 ) {
F_8 ( V_1 -> V_12 , L_20 , V_10 ) ;
goto V_38;
}
if ( V_10 != 0 ) {
F_22 ( V_1 -> V_12 , L_21 ,
V_10 ) ;
F_3 ( V_1 , V_11 , 0 ) ;
}
V_1 -> V_3 = 1 ;
if ( V_30 && V_30 -> V_55 ) {
V_10 = V_30 -> V_55 ( V_1 ) ;
if ( V_10 != 0 ) {
F_8 ( V_1 -> V_12 , L_22 , V_10 ) ;
goto V_38;
}
}
if ( V_30 ) {
for ( V_16 = 0 ; V_16 < F_23 ( V_30 -> V_56 ) ; V_16 ++ ) {
if ( ! V_30 -> V_56 [ V_16 ] )
continue;
F_3 ( V_1 ,
V_57 + V_16 ,
V_30 -> V_56 [ V_16 ] & 0xffff ) ;
}
}
if ( V_30 && V_30 -> V_33 )
V_33 = V_30 -> V_33 * 10 ;
else
V_33 = - 1 ;
V_10 = F_24 ( V_1 , V_28 ) ;
if ( V_10 != 0 )
goto V_38;
F_25 ( V_1 ) ;
switch ( V_35 ) {
case V_44 :
V_10 = F_26 ( V_1 -> V_12 , V_33 ,
V_58 , F_23 ( V_58 ) ,
NULL , V_1 -> V_59 ) ;
break;
case V_49 :
V_10 = F_26 ( V_1 -> V_12 , V_33 ,
V_60 , F_23 ( V_60 ) ,
NULL , V_1 -> V_59 ) ;
if ( ! V_30 || ! V_30 -> V_61 )
F_26 ( V_1 -> V_12 , V_33 ,
V_62 , F_23 ( V_62 ) ,
NULL , V_1 -> V_59 ) ;
break;
case V_50 :
V_10 = F_26 ( V_1 -> V_12 , V_33 ,
V_63 , F_23 ( V_63 ) ,
NULL , V_1 -> V_59 ) ;
if ( ! V_30 || ! V_30 -> V_61 )
F_26 ( V_1 -> V_12 , V_33 ,
V_62 , F_23 ( V_62 ) ,
NULL , V_1 -> V_59 ) ;
break;
case V_51 :
case V_52 :
case V_53 :
case V_54 :
V_10 = F_26 ( V_1 -> V_12 , V_33 ,
V_64 , F_23 ( V_64 ) ,
NULL , V_1 -> V_59 ) ;
break;
default:
F_27 () ;
}
if ( V_10 != 0 ) {
F_8 ( V_1 -> V_12 , L_23 ) ;
goto V_65;
}
V_10 = F_13 ( V_1 , V_66 ) ;
if ( V_10 < 0 ) {
F_8 ( V_1 -> V_12 , L_24 , V_10 ) ;
goto V_65;
}
if ( V_10 & V_67 ) {
V_10 = F_26 ( V_1 -> V_12 , V_33 ,
V_68 , F_23 ( V_68 ) ,
NULL , V_1 -> V_59 ) ;
if ( V_10 != 0 ) {
F_8 ( V_1 -> V_12 , L_25 , V_10 ) ;
goto V_65;
}
} else {
F_21 ( V_1 -> V_12 , L_26 ) ;
}
if ( V_30 && V_30 -> V_69 ) {
V_10 = F_26 ( V_1 -> V_12 , V_33 , V_70 ,
F_23 ( V_70 ) , NULL ,
V_1 -> V_59 ) ;
if ( V_10 < 0 )
F_8 ( V_1 -> V_12 , L_27 ,
V_10 ) ;
}
F_28 ( V_1 ) ;
if ( V_30 && V_30 -> V_71 ) {
V_10 = V_30 -> V_71 ( V_1 ) ;
if ( V_10 != 0 ) {
F_8 ( V_1 -> V_12 , L_28 , V_10 ) ;
goto V_65;
}
}
return 0 ;
V_65:
F_29 ( V_1 ) ;
V_38:
F_30 ( V_1 -> V_12 ) ;
F_31 ( V_1 ) ;
return V_10 ;
}
void F_32 ( struct V_1 * V_1 )
{
F_33 ( V_1 ) ;
F_30 ( V_1 -> V_12 ) ;
if ( V_1 -> V_59 )
F_34 ( V_1 -> V_59 + V_72 , V_1 ) ;
F_29 ( V_1 ) ;
F_31 ( V_1 ) ;
}
int F_35 ( struct V_1 * V_1 )
{
int V_2 , V_24 ;
if ( V_1 -> V_46 ) {
V_2 = F_13 ( V_1 , V_73 ) ;
V_24 = V_74 |
V_75 |
V_76 |
V_77 | V_78 |
V_79 | V_80 |
V_81 ;
if ( V_2 & V_24 )
V_2 = F_13 ( V_1 ,
V_82 ) ;
if ( V_2 & V_24 ) {
F_21 ( V_1 -> V_12 ,
L_29 ,
V_2 & V_24 ) ;
F_3 ( V_1 , V_82 ,
V_2 & V_24 ) ;
}
}
return 0 ;
}
