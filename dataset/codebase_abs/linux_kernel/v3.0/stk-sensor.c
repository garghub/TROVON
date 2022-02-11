static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 = 0 ;
int V_6 = 0 ;
if ( F_2 ( V_2 , V_7 , V_3 ) )
return 1 ;
if ( F_2 ( V_2 , V_8 , V_4 ) )
return 1 ;
if ( F_2 ( V_2 , V_9 , V_10 ) )
return 1 ;
do {
if ( F_3 ( V_2 , V_11 , & V_6 ) )
return 1 ;
V_5 ++ ;
} while ( V_6 == 0 && V_5 < V_12 );
if ( V_6 != V_13 ) {
if ( V_6 )
F_4 ( L_1 ,
V_6 ) ;
return 1 ;
} else
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
int V_5 = 0 ;
int V_6 = 0 ;
if ( F_2 ( V_2 , V_14 , V_3 ) )
return 1 ;
if ( F_2 ( V_2 , V_9 , V_15 ) )
return 1 ;
do {
if ( F_3 ( V_2 , V_11 , & V_6 ) )
return 1 ;
V_5 ++ ;
} while ( V_6 == 0 && V_5 < V_12 );
if ( V_6 != V_16 ) {
if ( V_6 )
F_4 ( L_2 ,
V_6 ) ;
return 1 ;
}
if ( F_3 ( V_2 , V_17 , & V_6 ) )
return 1 ;
* V_4 = ( T_1 ) V_6 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
int V_20 ;
if ( V_19 == NULL )
return 0 ;
while ( V_19 -> V_3 != 0xff || V_19 -> V_4 != 0xff ) {
V_20 = F_1 ( V_2 , V_19 -> V_3 , V_19 -> V_4 ) ;
if ( V_20 != 0 )
return V_20 ;
V_19 ++ ;
}
return 0 ;
}
int F_7 ( struct V_1 * V_2 )
{
T_1 V_21 ;
return F_5 ( V_2 , V_22 , & V_21 )
|| F_1 ( V_2 , V_22 , V_21 | V_23 ) ;
}
int F_8 ( struct V_1 * V_2 )
{
T_1 V_21 ;
return F_5 ( V_2 , V_22 , & V_21 )
|| F_1 ( V_2 , V_22 , V_21 & ~ V_23 ) ;
}
int F_9 ( struct V_1 * V_2 )
{
T_1 V_24 = 0 ;
T_1 V_25 = 0 ;
if ( F_2 ( V_2 , V_26 , V_27 )
|| F_2 ( V_2 , V_28 , V_29 )
|| F_1 ( V_2 , V_30 , V_31 ) ) {
F_4 ( L_3 ) ;
return - V_32 ;
}
F_10 ( 10 ) ;
if ( F_5 ( V_2 , V_33 , & V_25 )
|| F_5 ( V_2 , V_34 , & V_24 ) ) {
F_4 ( L_4 ) ;
return - V_32 ;
}
if ( V_25 != 0x7f || V_24 != 0xa2 ) {
F_4 ( L_5 ) ;
return - V_32 ;
}
if ( F_5 ( V_2 , V_35 , & V_25 )
|| F_5 ( V_2 , V_36 , & V_24 ) ) {
F_4 ( L_6 ) ;
return - V_32 ;
}
F_6 ( V_2 , V_37 ) ;
F_10 ( 10 ) ;
F_11 ( L_7
L_8 , V_25 , V_24 , V_29 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
int V_38 , int V_39 , int V_40 , int V_41 )
{
int V_20 ;
unsigned char V_42 ;
V_20 = F_1 ( V_2 , V_43 , ( V_38 >> 3 ) & 0xff ) ;
V_20 += F_1 ( V_2 , V_44 , ( V_39 >> 3 ) & 0xff ) ;
V_20 += F_5 ( V_2 , V_45 , & V_42 ) ;
V_42 = ( V_42 & 0xc0 ) | ( ( V_39 & 0x7 ) << 3 ) | ( V_38 & 0x7 ) ;
F_10 ( 10 ) ;
V_20 += F_1 ( V_2 , V_45 , V_42 ) ;
V_20 += F_1 ( V_2 , V_46 , ( V_40 >> 3 ) & 0xff ) ;
V_20 += F_1 ( V_2 , V_47 , ( V_41 >> 3 ) & 0xff ) ;
V_20 += F_5 ( V_2 , V_48 , & V_42 ) ;
V_42 = ( V_42 & 0xc0 ) | ( ( V_41 & 0x7 ) << 3 ) | ( V_40 & 0x7 ) ;
F_10 ( 10 ) ;
V_20 += F_1 ( V_2 , V_48 , V_42 ) ;
return V_20 ;
}
int F_13 ( struct V_1 * V_2 )
{
int V_49 ;
unsigned V_50 ;
int V_51 ;
struct V_18 * V_19 ;
switch ( V_2 -> V_52 . V_53 ) {
case V_54 : V_49 = V_55 ;
V_50 = 604 ;
break;
case V_56 : V_49 = V_57 ;
V_50 = 267 ;
break;
case V_58 : V_49 = V_59 ;
V_50 = 412 ;
break;
case V_60 : V_49 = V_61 ;
V_50 = 11 ;
break;
case V_62 : V_49 = V_63 ;
V_50 = 0 ;
break;
default: F_4 ( L_9 , V_2 -> V_52 . V_53 ) ;
return - V_64 ;
}
switch ( V_2 -> V_52 . V_65 ) {
case V_66 :
V_49 |= V_67 ;
V_19 = V_68 ;
break;
case V_69 :
V_49 |= V_67 ;
V_19 = V_70 ;
break;
case V_71 :
V_49 |= V_72 ;
V_19 = V_73 ;
break;
case V_74 :
V_49 |= V_72 ;
V_19 = V_75 ;
break;
case V_76 :
V_49 |= V_77 ;
V_19 = V_78 ;
break;
default: F_4 ( L_10 ) ;
return - V_64 ;
}
F_1 ( V_2 , V_30 , V_49 ) ;
F_10 ( 50 ) ;
F_6 ( V_2 , V_19 ) ;
V_51 = ( V_2 -> V_52 . V_79 ? V_80 : 0 )
| ( V_2 -> V_52 . V_81 ? V_82 : 0 ) ;
F_1 ( V_2 , V_83 , V_51 ) ;
if ( V_2 -> V_52 . V_65 == V_76
&& ! V_2 -> V_52 . V_79 )
F_1 ( V_2 , V_84 , 0x08 ) ;
F_1 ( V_2 , V_85 , V_50 >> 8 ) ;
F_1 ( V_2 , V_86 , V_50 & 0xff ) ;
F_10 ( 50 ) ;
switch ( V_2 -> V_52 . V_53 ) {
case V_60 :
if ( F_12 ( V_2 , 302 , 1582 , 6 , 486 ) )
F_4 ( L_11 ) ;
break;
case V_62 :
case V_58 :
case V_56 :
case V_54 :
break;
}
F_10 ( 10 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 , int V_87 )
{
if ( V_87 < 0 || V_87 > 0xff )
return - V_88 ;
F_1 ( V_2 , V_89 , F_15 ( 0x00 , V_87 - 6 ) ) ;
F_1 ( V_2 , V_90 , F_16 ( 0xff , V_87 + 6 ) ) ;
return 0 ;
}
