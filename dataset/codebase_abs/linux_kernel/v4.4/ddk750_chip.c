T_1 F_1 ( void )
{
unsigned short V_1 ;
char V_2 ;
T_1 V_3 ;
V_1 = V_4 ;
V_2 = V_5 ;
if ( V_1 == 0x718 )
V_3 = V_6 ;
else if ( V_1 == 0x750 ) {
V_3 = V_7 ;
if ( V_2 == V_8 )
V_3 = V_9 ;
} else
V_3 = V_10 ;
return V_3 ;
}
static unsigned int F_2 ( void )
{
unsigned int V_11 ;
unsigned int V_12 , V_13 , V_14 , V_15 ;
if ( F_1 () == V_9 )
return F_3 ( 130 ) ;
V_11 = F_4 ( V_16 ) ;
V_12 = F_5 ( V_11 , V_17 , V_12 ) ;
V_13 = F_5 ( V_11 , V_17 , V_13 ) ;
V_14 = F_5 ( V_11 , V_17 , V_14 ) ;
V_15 = F_5 ( V_11 , V_17 , V_15 ) ;
return V_18 * V_12 / V_13 / ( 1 << V_14 ) / ( 1 << V_15 ) ;
}
static void F_6 ( unsigned int V_19 )
{
T_2 V_20 ;
unsigned int V_21 ;
if ( F_1 () == V_9 )
return;
if ( V_19 ) {
V_20 . V_22 = V_18 ;
V_20 . V_23 = V_24 ;
V_21 = F_7 ( V_19 , & V_20 ) ;
F_8 ( V_16 , F_9 ( & V_20 ) ) ;
}
}
static void F_10 ( unsigned int V_19 )
{
unsigned int V_25 , V_26 ;
if ( F_1 () == V_9 )
return;
if ( V_19 ) {
if ( V_19 > F_3 ( 336 ) )
V_19 = F_3 ( 336 ) ;
V_26 = F_11 ( F_2 () , V_19 ) ;
V_25 = F_4 ( V_27 ) ;
switch ( V_26 ) {
default:
case 1 :
V_25 = F_12 ( V_25 , V_27 , V_28 , V_29 ) ;
break;
case 2 :
V_25 = F_12 ( V_25 , V_27 , V_28 , V_30 ) ;
break;
case 3 :
V_25 = F_12 ( V_25 , V_27 , V_28 , V_31 ) ;
break;
case 4 :
V_25 = F_12 ( V_25 , V_27 , V_28 , V_32 ) ;
break;
}
F_13 ( V_25 ) ;
}
}
static void F_14 ( unsigned int V_19 )
{
unsigned int V_25 , V_26 ;
if ( F_1 () == V_9 )
return;
if ( V_19 ) {
if ( V_19 > F_3 ( 190 ) )
V_19 = F_3 ( 190 ) ;
V_26 = F_11 ( F_2 () , V_19 ) ;
V_25 = F_4 ( V_27 ) ;
switch ( V_26 ) {
default:
case 3 :
V_25 = F_12 ( V_25 , V_27 , V_33 , V_31 ) ;
break;
case 4 :
V_25 = F_12 ( V_25 , V_27 , V_33 , V_32 ) ;
break;
case 6 :
V_25 = F_12 ( V_25 , V_27 , V_33 , V_34 ) ;
break;
case 8 :
V_25 = F_12 ( V_25 , V_27 , V_33 , V_35 ) ;
break;
}
F_13 ( V_25 ) ;
}
}
unsigned int F_15 ( void )
{
unsigned int V_36 ;
unsigned int V_37 ;
if ( F_1 () == V_9 )
return V_38 ;
V_36 = F_4 ( V_39 ) ;
V_36 = F_12 ( V_36 , V_39 , V_40 , V_41 ) ;
F_8 ( V_39 , V_36 ) ;
V_36 = F_5 ( F_4 ( V_42 ) , V_42 , V_43 ) ;
switch ( V_36 ) {
case V_44 :
V_37 = V_45 ; break;
case V_46 :
V_37 = V_47 ; break;
case V_48 :
V_37 = V_49 ; break;
case V_50 :
V_37 = V_38 ; break;
default:
V_37 = 0 ;
break;
}
return V_37 ;
}
int F_16 ( T_3 * V_51 )
{
unsigned int V_25 ;
if ( V_51 -> V_52 != 0 )
V_51 -> V_52 = 0 ;
F_17 ( V_51 -> V_52 ) ;
V_25 = F_4 ( V_27 ) ;
V_25 = F_12 ( V_25 , V_27 , V_53 , V_41 ) ;
V_25 = F_12 ( V_25 , V_27 , V_54 , V_41 ) ;
F_13 ( V_25 ) ;
if ( F_1 () != V_9 ) {
V_25 = F_4 ( V_55 ) ;
V_25 = F_12 ( V_25 , V_55 , V_56 , V_57 ) ;
V_25 = F_12 ( V_25 , V_55 , V_58 , V_59 ) ;
F_8 ( V_55 , V_25 ) ;
} else {
#if F_18 ( V_60 ) || F_18 ( V_61 )
F_19 ( 0x88 , 0x3d4 ) ;
F_19 ( 0x06 , 0x3d5 ) ;
#endif
}
F_6 ( F_3 ( ( unsigned int ) V_51 -> V_62 ) ) ;
F_10 ( F_3 ( V_51 -> V_63 ) ) ;
F_14 ( F_3 ( V_51 -> V_64 ) ) ;
if ( V_51 -> V_65 == 1 ) {
V_25 = F_4 ( V_42 ) ;
V_25 = F_12 ( V_25 , V_42 , V_66 , V_67 ) ;
F_8 ( V_42 , V_25 ) ;
V_25 = F_12 ( V_25 , V_42 , V_66 , V_68 ) ;
F_8 ( V_42 , V_25 ) ;
}
if ( V_51 -> V_69 == 1 ) {
F_20 ( 0 ) ;
V_25 = F_4 ( V_70 ) ;
V_25 = F_12 ( V_25 , V_70 , V_71 , V_72 ) ;
F_8 ( V_70 , V_25 ) ;
V_25 = F_4 ( V_73 ) ;
V_25 = F_12 ( V_25 , V_73 , V_71 , V_72 ) ;
F_8 ( V_73 , V_25 ) ;
V_25 = F_4 ( V_74 ) ;
V_25 = F_12 ( V_25 , V_74 , V_71 , V_72 ) ;
F_8 ( V_74 , V_25 ) ;
V_25 = F_4 ( V_75 ) ;
V_25 = F_12 ( V_25 , V_75 , V_76 , ABORT ) ;
F_8 ( V_75 , V_25 ) ;
F_21 ( 0 ) ;
}
return 0 ;
}
unsigned int F_7 ( unsigned int V_77 , T_2 * V_20 )
{
int V_13 , V_12 , V_78 , V_79 ;
int V_80 ;
unsigned int V_81 , V_82 , V_83 , V_84 ;
unsigned int V_85 , V_86 ;
unsigned int V_87 , V_88 ;
const int V_89 = 3 ;
int V_90 ;
if ( F_1 () == V_9 ) {
return V_77 ;
}
V_88 = 0 ;
V_80 = ~ 0 ;
V_86 = V_77 / 1000 ;
V_85 = V_20 -> V_22 / 1000 ;
if ( V_20 -> V_23 == V_24 )
V_90 = 3 ;
for ( V_13 = 15 ; V_13 > 1 ; V_13 -- ) {
V_81 = V_13 * V_86 ;
V_82 = V_81 / V_85 ;
V_83 = V_81 % V_85 ;
V_84 = ( V_83 * 10000 / V_85 ) ;
for ( V_79 = V_90 ; V_79 >= 0 ; V_79 -- ) {
V_78 = ( 1 << V_79 ) ;
V_12 = V_82 * V_78 ;
V_12 += V_84 * V_78 / 10000 ;
V_12 += ( V_84 * V_78 % 10000 ) > 5000 ? 1 : 0 ;
if ( V_12 < 256 && V_12 > 0 ) {
unsigned int V_91 ;
V_87 = V_20 -> V_22 * V_12 / V_13 / V_78 ;
V_91 = F_22 ( V_87 , V_77 ) ;
if ( V_91 < V_80 ) {
V_20 -> V_12 = V_12 ;
V_20 -> V_13 = V_13 ;
V_20 -> V_15 = 0 ;
if ( V_79 > V_89 )
V_20 -> V_15 = V_79 - V_89 ;
V_20 -> V_14 = V_79 - V_20 -> V_15 ;
V_80 = V_91 ;
V_88 = V_87 ;
}
}
}
}
return V_88 ;
}
unsigned int F_9 ( T_2 * V_92 )
{
unsigned int V_93 = 0 ;
V_93 =
F_12 ( 0 , V_17 , V_94 , V_95 )
| F_12 ( 0 , V_17 , V_96 , V_41 )
| F_12 ( 0 , V_17 , V_97 , V_98 )
#ifndef F_23
| F_24 ( 0 , V_17 , V_15 , V_92 -> V_15 )
#endif
| F_24 ( 0 , V_17 , V_14 , V_92 -> V_14 )
| F_24 ( 0 , V_17 , V_13 , V_92 -> V_13 )
| F_24 ( 0 , V_17 , V_12 , V_92 -> V_12 ) ;
return V_93 ;
}
