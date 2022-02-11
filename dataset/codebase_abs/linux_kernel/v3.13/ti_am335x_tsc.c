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
V_8 -> V_42 = V_28 ;
F_13 ( V_8 -> V_4 , V_8 -> V_42 ) ;
}
static void F_14 ( struct V_1 * V_8 ,
T_1 * V_43 , T_1 * V_44 , T_1 * V_45 , T_1 * V_46 )
{
unsigned int V_47 = F_1 ( V_8 , V_48 ) ;
unsigned int V_49 = ~ 0 , V_50 = ~ 0 ;
unsigned int V_51 = ~ 0 , V_52 = ~ 0 ;
unsigned int V_53 , V_54 ;
unsigned int V_11 , V_55 ;
unsigned int V_56 = V_8 -> V_33 ;
* V_45 = * V_46 = 0 ;
if ( V_47 % ( V_56 * 2 + 2 ) )
V_47 -= V_47 % ( V_56 * 2 + 2 ) ;
for ( V_11 = 0 ; V_11 < V_47 ; V_11 ++ ) {
V_53 = F_1 ( V_8 , V_57 ) ;
V_55 = ( V_53 & 0xf0000 ) >> 16 ;
V_53 &= 0xfff ;
if ( V_55 < V_56 ) {
V_54 = abs ( V_53 - V_49 ) ;
if ( V_54 < V_51 ) {
V_51 = V_54 ;
* V_43 = V_53 ;
}
V_49 = V_53 ;
} else if ( V_55 < V_56 * 2 ) {
V_54 = abs ( V_53 - V_50 ) ;
if ( V_54 < V_52 ) {
V_52 = V_54 ;
* V_44 = V_53 ;
}
V_50 = V_53 ;
} else if ( V_55 < V_56 * 2 + 1 ) {
* V_45 = V_53 ;
} else if ( V_55 < V_56 * 2 + 2 ) {
* V_46 = V_53 ;
}
}
}
static T_2 F_15 ( int V_58 , void * V_59 )
{
struct V_1 * V_8 = V_59 ;
struct V_60 * V_60 = V_8 -> V_61 ;
unsigned int V_62 , V_63 = 0 ;
unsigned int V_43 = 0 , V_44 = 0 ;
unsigned int V_45 , V_46 , V_64 ;
unsigned int V_65 ;
V_62 = F_1 ( V_8 , V_66 ) ;
if ( V_62 & V_67 ) {
F_14 ( V_8 , & V_43 , & V_44 , & V_45 , & V_46 ) ;
if ( V_8 -> V_68 && V_45 != 0 && V_46 != 0 ) {
V_64 = V_45 - V_46 ;
V_64 *= V_43 ;
V_64 *= V_8 -> V_69 ;
V_64 /= V_46 ;
V_64 = ( V_64 + 2047 ) >> 12 ;
if ( V_64 <= V_70 ) {
F_16 ( V_60 , V_71 , V_43 ) ;
F_16 ( V_60 , V_72 , V_44 ) ;
F_16 ( V_60 , V_73 , V_64 ) ;
F_17 ( V_60 , V_74 , 1 ) ;
F_18 ( V_60 ) ;
}
}
V_63 |= V_67 ;
}
F_19 ( V_75 ) ;
V_62 = F_1 ( V_8 , V_76 ) ;
if ( V_62 & V_77 ) {
V_65 = F_1 ( V_8 , V_78 ) ;
if ( V_65 == V_79 ) {
V_8 -> V_68 = false ;
F_17 ( V_60 , V_74 , 0 ) ;
F_16 ( V_60 , V_73 , 0 ) ;
F_18 ( V_60 ) ;
} else {
V_8 -> V_68 = true ;
}
V_63 |= V_77 ;
}
if ( V_62 & V_80 ) {
F_3 ( V_8 , V_81 , 0x00 ) ;
F_3 ( V_8 , V_82 , V_80 ) ;
}
if ( V_63 ) {
F_3 ( V_8 , V_66 , V_63 ) ;
F_13 ( V_8 -> V_4 , V_8 -> V_42 ) ;
return V_83 ;
}
return V_84 ;
}
static int F_20 ( struct V_85 * V_86 ,
struct V_1 * V_8 )
{
struct V_87 * V_88 = V_86 -> V_59 . V_89 ;
int V_90 ;
if ( ! V_88 )
return - V_14 ;
V_90 = F_21 ( V_88 , L_1 , & V_8 -> V_31 ) ;
if ( V_90 < 0 )
return V_90 ;
switch ( V_8 -> V_31 ) {
case 4 :
case 5 :
case 8 :
break;
default:
return - V_14 ;
}
V_90 = F_21 ( V_88 , L_2 ,
& V_8 -> V_69 ) ;
if ( V_90 < 0 )
return V_90 ;
V_90 = F_21 ( V_88 , L_3 ,
& V_8 -> V_33 ) ;
if ( V_90 < 0 )
V_90 = F_21 ( V_88 , L_4 ,
& V_8 -> V_33 ) ;
if ( V_90 < 0 )
return V_90 ;
return F_22 ( V_88 , L_5 ,
V_8 -> V_13 , F_7 ( V_8 -> V_13 ) ) ;
}
static int F_23 ( struct V_85 * V_86 )
{
struct V_1 * V_8 ;
struct V_60 * V_60 ;
struct V_91 * V_92 = F_24 ( V_86 ) ;
int V_90 ;
V_8 = F_25 ( sizeof( struct V_1 ) , V_93 ) ;
V_60 = F_26 () ;
if ( ! V_8 || ! V_60 ) {
F_27 ( & V_86 -> V_59 , L_6 ) ;
V_90 = - V_94 ;
goto V_95;
}
V_92 -> V_6 = V_8 ;
V_8 -> V_4 = V_92 ;
V_8 -> V_61 = V_60 ;
V_8 -> V_58 = V_92 -> V_58 ;
V_90 = F_20 ( V_86 , V_8 ) ;
if ( V_90 ) {
F_27 ( & V_86 -> V_59 , L_7 ) ;
goto V_95;
}
V_90 = F_28 ( V_8 -> V_58 , F_15 ,
V_96 , V_86 -> V_59 . V_97 -> V_98 , V_8 ) ;
if ( V_90 ) {
F_27 ( & V_86 -> V_59 , L_8 ) ;
goto V_95;
}
F_3 ( V_8 , V_99 , V_67 ) ;
V_90 = F_5 ( V_8 ) ;
if ( V_90 ) {
F_27 ( & V_86 -> V_59 , L_9 ) ;
goto V_100;
}
F_8 ( V_8 ) ;
F_3 ( V_8 , V_101 ,
V_8 -> V_33 * 2 + 2 - 1 ) ;
V_60 -> V_98 = L_10 ;
V_60 -> V_59 . V_102 = & V_86 -> V_59 ;
V_60 -> V_103 [ 0 ] = F_29 ( V_104 ) | F_29 ( V_105 ) ;
V_60 -> V_106 [ F_30 ( V_74 ) ] = F_29 ( V_74 ) ;
F_31 ( V_60 , V_71 , 0 , V_70 , 0 , 0 ) ;
F_31 ( V_60 , V_72 , 0 , V_70 , 0 , 0 ) ;
F_31 ( V_60 , V_73 , 0 , V_70 , 0 , 0 ) ;
V_90 = F_32 ( V_60 ) ;
if ( V_90 )
goto V_100;
F_33 ( V_86 , V_8 ) ;
return 0 ;
V_100:
F_34 ( V_8 -> V_58 , V_8 ) ;
V_95:
F_35 ( V_60 ) ;
F_36 ( V_8 ) ;
return V_90 ;
}
static int F_37 ( struct V_85 * V_86 )
{
struct V_1 * V_8 = F_38 ( V_86 ) ;
T_1 V_107 ;
F_34 ( V_8 -> V_58 , V_8 ) ;
V_107 = 2 * V_8 -> V_33 + 2 ;
V_107 = ( 1 << V_107 ) - 1 ;
F_39 ( V_8 -> V_4 , V_107 ) ;
F_40 ( V_8 -> V_61 ) ;
F_36 ( V_8 ) ;
return 0 ;
}
static int F_41 ( struct V_108 * V_59 )
{
struct V_1 * V_8 = F_42 ( V_59 ) ;
struct V_91 * V_92 ;
unsigned int V_109 ;
V_92 = F_24 ( F_43 ( V_59 ) ) ;
if ( F_44 ( V_92 -> V_59 ) ) {
V_109 = F_1 ( V_8 , V_99 ) ;
F_3 ( V_8 , V_99 ,
( V_109 | V_80 ) ) ;
F_3 ( V_8 , V_81 , V_110 ) ;
}
return 0 ;
}
static int F_45 ( struct V_108 * V_59 )
{
struct V_1 * V_8 = F_42 ( V_59 ) ;
struct V_91 * V_92 ;
V_92 = F_24 ( F_43 ( V_59 ) ) ;
if ( F_44 ( V_92 -> V_59 ) ) {
F_3 ( V_8 , V_81 ,
0x00 ) ;
F_3 ( V_8 , V_82 , V_80 ) ;
}
F_8 ( V_8 ) ;
F_3 ( V_8 , V_101 ,
V_8 -> V_33 * 2 + 2 - 1 ) ;
return 0 ;
}
