static unsigned int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_2 ( V_2 -> V_4 -> V_5 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_6 , unsigned int V_3 ,
unsigned int V_7 )
{
F_4 ( V_7 , V_6 -> V_4 -> V_5 + V_3 ) ;
}
static int F_5 ( struct V_1 * V_8 )
{
T_1 V_9 [ 4 ] ;
T_1 V_10 [ 4 ] ;
int V_11 , V_12 ;
for ( V_11 = 0 ; V_11 < 4 ; V_11 ++ ) {
V_9 [ V_11 ] = ( V_8 -> V_13 [ V_11 ] & 0xF0 ) >> 4 ;
V_10 [ V_11 ] = V_8 -> V_13 [ V_11 ] & 0x0F ;
if ( F_6 ( V_9 [ V_11 ] > 7 ) )
return - V_14 ;
if ( F_6 ( V_10 [ V_11 ] > F_7 ( V_15 ) ) )
return - V_14 ;
}
for ( V_11 = 0 ; V_11 < 4 ; V_11 ++ ) {
int V_16 ;
int V_17 ;
V_16 = V_9 [ V_11 ] ;
V_17 = V_10 [ V_11 ] ;
V_12 = V_15 [ V_17 ] ;
if ( V_12 == 0 )
return - V_14 ;
switch ( V_17 ) {
case 0 :
V_8 -> V_18 = V_12 ;
V_8 -> V_19 = V_16 ;
break;
case 1 :
V_8 -> V_20 = V_12 ;
V_8 -> V_21 = V_16 ;
break;
case 2 :
V_8 -> V_22 = V_12 ;
V_8 -> V_23 = V_16 ;
break;
case 3 :
V_8 -> V_24 = V_12 ;
V_8 -> V_25 = V_16 ;
break;
}
}
return 0 ;
}
static void F_8 ( struct V_1 * V_8 )
{
unsigned int V_26 ;
int V_11 ;
int V_27 ;
T_1 V_28 ;
V_26 = V_29 |
V_30 | V_8 -> V_18 ;
switch ( V_8 -> V_31 ) {
case 4 :
V_26 |= F_9 ( V_8 -> V_23 ) | V_8 -> V_20 ;
break;
case 5 :
V_26 |= V_8 -> V_24 |
V_32 | V_8 -> V_20 |
V_8 -> V_22 ;
break;
case 8 :
V_26 |= F_9 ( V_8 -> V_23 ) | V_8 -> V_20 ;
break;
}
V_27 = V_8 -> V_33 ;
for ( V_11 = 0 ; V_11 < V_27 ; V_11 ++ ) {
F_3 ( V_8 , F_10 ( V_11 ) , V_26 ) ;
F_3 ( V_8 , F_11 ( V_11 ) , V_34 ) ;
}
V_26 = 0 ;
V_26 = V_29 |
V_30 | V_8 -> V_24 |
V_35 ;
switch ( V_8 -> V_31 ) {
case 4 :
V_26 |= V_8 -> V_22 | F_9 ( V_8 -> V_19 ) ;
break;
case 5 :
V_26 |= V_8 -> V_18 | V_32 |
V_8 -> V_20 | V_8 -> V_22 ;
break;
case 8 :
V_26 |= V_8 -> V_22 | F_9 ( V_8 -> V_19 ) ;
break;
}
V_27 = V_8 -> V_33 * 2 ;
for ( V_11 = V_8 -> V_33 ; V_11 < V_27 ; V_11 ++ ) {
F_3 ( V_8 , F_10 ( V_11 ) , V_26 ) ;
F_3 ( V_8 , F_11 ( V_11 ) , V_34 ) ;
}
V_26 = V_8 -> V_18 | V_8 -> V_24 |
V_36 | V_37 |
V_38 | F_12 ( V_8 -> V_23 ) ;
F_3 ( V_8 , V_39 , V_26 ) ;
F_3 ( V_8 , V_40 , V_41 ) ;
V_26 = V_29 |
V_30 | V_8 -> V_22 |
V_8 -> V_20 | V_35 |
F_9 ( V_8 -> V_19 ) ;
F_3 ( V_8 , F_10 ( V_27 ) , V_26 ) ;
F_3 ( V_8 , F_11 ( V_27 ) ,
V_34 ) ;
V_27 ++ ;
V_26 |= F_9 ( V_8 -> V_25 ) ;
F_3 ( V_8 , F_10 ( V_27 ) , V_26 ) ;
F_3 ( V_8 , F_11 ( V_27 ) ,
V_34 ) ;
V_28 = ( 1 << ( V_27 + 2 ) ) - 1 ;
F_13 ( V_8 -> V_4 , V_28 ) ;
}
static void F_14 ( struct V_1 * V_8 ,
T_1 * V_42 , T_1 * V_43 , T_1 * V_44 , T_1 * V_45 )
{
unsigned int V_46 = F_1 ( V_8 , V_47 ) ;
unsigned int V_48 = ~ 0 , V_49 = ~ 0 ;
unsigned int V_50 = ~ 0 , V_51 = ~ 0 ;
unsigned int V_52 , V_53 ;
unsigned int V_11 , V_54 ;
unsigned int V_55 = V_8 -> V_33 ;
* V_44 = * V_45 = 0 ;
if ( V_46 % ( V_55 * 2 + 2 ) )
V_46 -= V_46 % ( V_55 * 2 + 2 ) ;
for ( V_11 = 0 ; V_11 < V_46 ; V_11 ++ ) {
V_52 = F_1 ( V_8 , V_56 ) ;
V_54 = ( V_52 & 0xf0000 ) >> 16 ;
V_52 &= 0xfff ;
if ( V_54 < V_55 ) {
V_53 = abs ( V_52 - V_48 ) ;
if ( V_53 < V_50 ) {
V_50 = V_53 ;
* V_42 = V_52 ;
}
V_48 = V_52 ;
} else if ( V_54 < V_55 * 2 ) {
V_53 = abs ( V_52 - V_49 ) ;
if ( V_53 < V_51 ) {
V_51 = V_53 ;
* V_43 = V_52 ;
}
V_49 = V_52 ;
} else if ( V_54 < V_55 * 2 + 1 ) {
* V_44 = V_52 ;
} else if ( V_54 < V_55 * 2 + 2 ) {
* V_45 = V_52 ;
}
}
}
static T_2 F_15 ( int V_57 , void * V_58 )
{
struct V_1 * V_8 = V_58 ;
struct V_59 * V_59 = V_8 -> V_60 ;
unsigned int V_61 , V_62 = 0 ;
unsigned int V_42 = 0 , V_43 = 0 ;
unsigned int V_44 , V_45 , V_63 ;
unsigned int V_64 ;
V_61 = F_1 ( V_8 , V_65 ) ;
if ( V_61 & V_66 ) {
F_14 ( V_8 , & V_42 , & V_43 , & V_44 , & V_45 ) ;
if ( V_8 -> V_67 && V_44 != 0 && V_45 != 0 ) {
V_63 = V_44 - V_45 ;
V_63 *= V_42 ;
V_63 *= V_8 -> V_68 ;
V_63 /= V_45 ;
V_63 = ( V_63 + 2047 ) >> 12 ;
if ( V_63 <= V_69 ) {
F_16 ( V_59 , V_70 , V_42 ) ;
F_16 ( V_59 , V_71 , V_43 ) ;
F_16 ( V_59 , V_72 , V_63 ) ;
F_17 ( V_59 , V_73 , 1 ) ;
F_18 ( V_59 ) ;
}
}
V_62 |= V_66 ;
}
F_19 ( V_74 ) ;
V_61 = F_1 ( V_8 , V_75 ) ;
if ( V_61 & V_76 ) {
V_64 = F_1 ( V_8 , V_77 ) ;
if ( V_64 == V_78 ) {
V_8 -> V_67 = false ;
F_17 ( V_59 , V_73 , 0 ) ;
F_16 ( V_59 , V_72 , 0 ) ;
F_18 ( V_59 ) ;
} else {
V_8 -> V_67 = true ;
}
V_62 |= V_76 ;
}
if ( V_61 & V_79 ) {
F_3 ( V_8 , V_80 , 0x00 ) ;
F_3 ( V_8 , V_81 , V_79 ) ;
}
if ( V_62 ) {
F_3 ( V_8 , V_65 , V_62 ) ;
F_20 ( V_8 -> V_4 ) ;
return V_82 ;
}
return V_83 ;
}
static int F_21 ( struct V_84 * V_85 ,
struct V_1 * V_8 )
{
struct V_86 * V_87 = V_85 -> V_58 . V_88 ;
int V_89 ;
if ( ! V_87 )
return - V_14 ;
V_89 = F_22 ( V_87 , L_1 , & V_8 -> V_31 ) ;
if ( V_89 < 0 )
return V_89 ;
switch ( V_8 -> V_31 ) {
case 4 :
case 5 :
case 8 :
break;
default:
return - V_14 ;
}
V_89 = F_22 ( V_87 , L_2 ,
& V_8 -> V_68 ) ;
if ( V_89 < 0 )
return V_89 ;
V_89 = F_22 ( V_87 , L_3 ,
& V_8 -> V_33 ) ;
if ( V_89 < 0 )
return V_89 ;
return F_23 ( V_87 , L_4 ,
V_8 -> V_13 , F_7 ( V_8 -> V_13 ) ) ;
}
static int F_24 ( struct V_84 * V_85 )
{
struct V_1 * V_8 ;
struct V_59 * V_59 ;
struct V_90 * V_91 = F_25 ( V_85 ) ;
int V_89 ;
V_8 = F_26 ( sizeof( struct V_1 ) , V_92 ) ;
V_59 = F_27 () ;
if ( ! V_8 || ! V_59 ) {
F_28 ( & V_85 -> V_58 , L_5 ) ;
V_89 = - V_93 ;
goto V_94;
}
V_91 -> V_6 = V_8 ;
V_8 -> V_4 = V_91 ;
V_8 -> V_60 = V_59 ;
V_8 -> V_57 = V_91 -> V_57 ;
V_89 = F_21 ( V_85 , V_8 ) ;
if ( V_89 ) {
F_28 ( & V_85 -> V_58 , L_6 ) ;
goto V_94;
}
V_89 = F_29 ( V_8 -> V_57 , F_15 ,
0 , V_85 -> V_58 . V_95 -> V_96 , V_8 ) ;
if ( V_89 ) {
F_28 ( & V_85 -> V_58 , L_7 ) ;
goto V_94;
}
F_3 ( V_8 , V_97 , V_66 ) ;
V_89 = F_5 ( V_8 ) ;
if ( V_89 ) {
F_28 ( & V_85 -> V_58 , L_8 ) ;
goto V_98;
}
F_8 ( V_8 ) ;
F_3 ( V_8 , V_99 ,
V_8 -> V_33 * 2 + 2 - 1 ) ;
V_59 -> V_96 = L_9 ;
V_59 -> V_58 . V_100 = & V_85 -> V_58 ;
V_59 -> V_101 [ 0 ] = F_30 ( V_102 ) | F_30 ( V_103 ) ;
V_59 -> V_104 [ F_31 ( V_73 ) ] = F_30 ( V_73 ) ;
F_32 ( V_59 , V_70 , 0 , V_69 , 0 , 0 ) ;
F_32 ( V_59 , V_71 , 0 , V_69 , 0 , 0 ) ;
F_32 ( V_59 , V_72 , 0 , V_69 , 0 , 0 ) ;
V_89 = F_33 ( V_59 ) ;
if ( V_89 )
goto V_98;
F_34 ( V_85 , V_8 ) ;
return 0 ;
V_98:
F_35 ( V_8 -> V_57 , V_8 ) ;
V_94:
F_36 ( V_59 ) ;
F_37 ( V_8 ) ;
return V_89 ;
}
static int F_38 ( struct V_84 * V_85 )
{
struct V_1 * V_8 = F_39 ( V_85 ) ;
T_1 V_105 ;
F_35 ( V_8 -> V_57 , V_8 ) ;
V_105 = 2 * V_8 -> V_33 + 2 ;
V_105 = ( 1 << V_105 ) - 1 ;
F_40 ( V_8 -> V_4 , V_105 ) ;
F_41 ( V_8 -> V_60 ) ;
F_37 ( V_8 ) ;
return 0 ;
}
static int F_42 ( struct V_106 * V_58 )
{
struct V_1 * V_8 = F_43 ( V_58 ) ;
struct V_90 * V_91 ;
unsigned int V_107 ;
V_91 = F_25 ( F_44 ( V_58 ) ) ;
if ( F_45 ( V_91 -> V_58 ) ) {
V_107 = F_1 ( V_8 , V_97 ) ;
F_3 ( V_8 , V_97 ,
( V_107 | V_79 ) ) ;
F_3 ( V_8 , V_80 , V_108 ) ;
}
return 0 ;
}
static int F_46 ( struct V_106 * V_58 )
{
struct V_1 * V_8 = F_43 ( V_58 ) ;
struct V_90 * V_91 ;
V_91 = F_25 ( F_44 ( V_58 ) ) ;
if ( F_45 ( V_91 -> V_58 ) ) {
F_3 ( V_8 , V_80 ,
0x00 ) ;
F_3 ( V_8 , V_81 , V_79 ) ;
}
F_8 ( V_8 ) ;
F_3 ( V_8 , V_99 ,
V_8 -> V_33 * 2 + 2 - 1 ) ;
return 0 ;
}
