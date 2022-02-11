static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = F_2 ( V_2 , V_5 , 3000 ) ;
if ( V_4 )
F_3 ( V_2 -> V_6 , L_1 ,
V_2 -> V_7 . V_8 , V_4 ) ;
return V_4 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_4 = F_5 ( V_2 , V_9 , V_10 , V_11 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_5 ( V_2 , V_5 , V_12 , V_13 ) ;
return V_4 ;
}
static int F_6 ( struct V_1 * V_2 )
{
return F_5 ( V_2 , V_5 , V_12 , 0 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
unsigned int V_14 ;
F_8 ( V_2 , V_5 , V_15 , & V_14 ) ;
F_8 ( V_2 , V_9 , V_16 , & V_14 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_4 ;
unsigned int V_17 , V_14 ;
V_4 = F_8 ( V_2 , V_5 , V_15 , & V_17 ) ;
if ( V_4 )
return V_4 ;
F_8 ( V_2 , V_9 , V_16 , & V_14 ) ;
return V_18 ;
}
static int F_10 ( struct V_1 * V_2 , int V_19 )
{
return F_11 ( & V_2 -> V_7 , V_2 -> V_7 . V_8 ,
V_9 , V_20 ,
V_21 , V_19 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = F_10 ( V_2 , 0 ) ;
if ( ! V_4 )
V_4 = F_11 ( & V_2 -> V_7 , V_2 -> V_7 . V_8 ,
V_22 , V_20 ,
V_23 | V_24 , 1 ) ;
return V_4 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = F_10 ( V_2 , 0 ) ;
if ( ! V_4 )
V_4 = F_11 ( & V_2 -> V_7 , V_2 -> V_7 . V_8 ,
V_22 , V_20 ,
V_23 | V_24 , 1 ) ;
return V_4 ;
}
static int F_14 ( struct V_1 * V_2 , unsigned int V_25 )
{
unsigned int V_26 ;
int V_4 ;
V_26 = 0 ;
if ( V_25 & V_27 )
V_26 |= V_28 ;
V_4 = F_15 ( V_2 , V_22 , V_29 ,
V_28 , V_26 ) ;
if ( V_4 )
return V_4 ;
V_26 = 0 ;
if ( V_25 & V_30 )
V_26 |= V_31 ;
if ( V_25 & V_32 )
V_26 |= V_33 ;
V_4 = F_15 ( V_2 , V_22 , V_34 ,
V_31 | V_33 , V_26 ) ;
if ( V_4 )
return V_4 ;
V_26 = 0 ;
if ( V_25 & V_35 )
V_26 |= V_36 ;
if ( V_25 & V_37 )
V_26 |= V_38 ;
if ( V_25 & V_39 )
V_26 |= V_40 ;
if ( V_25 & V_41 )
V_26 |= V_42 ;
V_4 = F_15 ( V_2 , V_22 , V_43 ,
0xfe0 , V_26 ) ;
return V_4 ;
}
static int F_16 ( struct V_1 * V_2 , int V_44 , int V_45 , int V_46 )
{
return F_11 ( & V_2 -> V_7 , V_2 -> V_7 . V_8 ,
V_9 , V_20 ,
V_47 , V_46 ) ;
}
static int F_17 ( struct V_1 * V_2 , int V_48 , int V_49 )
{
return - 1 ;
}
static int F_18 ( struct V_1 * V_2 , int * V_50 ,
int * V_48 , int * V_49 , int * V_51 )
{
int V_4 ;
unsigned int V_14 ;
if ( V_50 ) {
V_4 = F_8 ( V_2 , V_9 , V_52 , & V_14 ) ;
if ( V_4 )
return V_4 ;
* V_50 = V_14 & 1 ;
if ( ! * V_50 )
return 0 ;
}
V_4 = F_8 ( V_2 , V_22 , V_53 , & V_14 ) ;
if ( V_4 )
return V_4 ;
if ( V_48 ) {
switch ( V_14 & 0x6 ) {
case 0x6 :
* V_48 = V_54 ;
break;
case 0x4 :
* V_48 = V_55 ;
break;
case 0x2 :
* V_48 = V_56 ;
break;
case 0x0 :
* V_48 = V_57 ;
break;
}
}
if ( V_49 )
* V_49 = V_14 & 1 ? V_58 : V_59 ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 , struct V_6 * V_6 , int V_60 ,
const struct V_61 * V_61 )
{
unsigned int V_14 , V_62 , V_63 , V_3 ;
int V_4 ;
F_20 ( V_2 , V_6 , V_60 , & V_64 , V_61 ,
V_65 | V_66 |
V_67 | V_68 | V_69 ,
L_2 ) ;
V_63 = V_60 ? V_70 : V_71 ;
F_21 ( V_6 , V_72 , V_63 , 0 ) ;
F_22 ( 1 ) ;
F_21 ( V_6 , V_72 , V_63 , V_63 ) ;
F_22 ( 1000 ) ;
V_3 = 500 ;
do {
V_4 = F_8 ( V_2 , V_5 , V_20 , & V_14 ) ;
if ( V_4 || V_14 == 0xffff ) {
F_3 ( V_6 , L_3 ,
V_60 , V_4 , V_14 ) ;
goto V_73;
}
V_14 &= V_74 ;
if ( V_14 )
F_22 ( 10 ) ;
} while ( V_14 && -- V_3 );
if ( V_14 ) {
F_3 ( V_6 , L_4 ,
V_60 , V_14 ) ;
goto V_73;
}
V_3 = ( 500 - V_3 ) * 10 + 1000 ;
if ( V_3 > 3000 )
F_3 ( V_6 , L_5 , V_60 , V_3 ) ;
F_8 ( V_2 , V_5 , V_75 , & V_14 ) ;
if ( V_14 != 101 )
F_3 ( V_6 , L_6 ,
V_60 , V_14 ) ;
V_4 = F_8 ( V_2 , V_5 , V_20 , & V_14 ) ;
if ( V_4 )
return V_4 ;
if ( V_14 & V_76 ) {
V_4 = F_15 ( V_2 , V_5 , V_20 ,
V_76 , 0 ) ;
if ( V_4 )
return V_4 ;
F_22 ( 10 ) ;
} else
F_3 ( V_6 , L_7 ,
V_60 ) ;
V_14 = V_62 = 0 ;
F_8 ( V_2 , V_77 , V_78 , & V_14 ) ;
F_8 ( V_2 , V_77 , V_79 , & V_62 ) ;
if ( V_14 != 0x1b || V_62 != 0x1b )
F_3 ( V_6 ,
L_8 ,
V_60 , V_14 , V_62 ) ;
V_73:
return V_4 ;
}
