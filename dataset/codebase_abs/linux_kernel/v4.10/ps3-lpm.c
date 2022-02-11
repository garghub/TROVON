static struct V_1 * F_1 ( void )
{
F_2 ( ! V_2 || ! V_2 -> V_3 ) ;
return & V_2 -> V_3 -> V_4 ;
}
void F_3 ( T_1 V_5 )
{
asm volatile("nop;nop;nop;nop;nop;nop;nop;nop;nop;");
F_4 ( V_6 , V_5 ) ;
asm volatile("nop;nop;nop;nop;nop;nop;nop;nop;nop;");
}
void F_5 ( T_1 V_7 , T_1 V_8 , T_1 V_9 )
{
T_1 V_5 ;
V_5 = ( F_6 () & 0x00000000FFFFFFFFULL ) |
V_10 ;
V_5 = ( ( V_7 << 56 ) & V_11 ) |
( V_8 << 48 ) | ( V_9 << 32 ) | V_5 ;
F_3 ( V_5 ) ;
}
T_2 F_7 ( T_2 V_12 , T_2 V_13 )
{
int V_14 ;
T_1 V_15 ;
T_1 V_16 ;
if ( V_13 >= V_17 ) {
F_8 ( F_1 () , L_1 , V_18 ,
__LINE__ , V_13 ) ;
return 0 ;
}
V_14 = F_9 ( V_2 -> V_19 , 0 , 0 , 0 , 0 , & V_15 ,
& V_16 ) ;
if ( V_14 ) {
F_10 ( F_1 () , L_2
L_3 , V_18 , __LINE__ , V_13 ,
F_11 ( V_14 ) ) ;
return 0 ;
}
switch ( V_13 ) {
case 0 :
return V_15 >> 32 ;
case 1 :
return V_15 & V_20 ;
case 2 :
return V_16 >> 32 ;
case 3 :
return V_16 & V_20 ;
default:
F_12 () ;
}
return 0 ;
}
void F_13 ( T_2 V_12 , T_2 V_13 , T_2 V_21 )
{
T_1 V_15 ;
T_1 V_22 ;
T_1 V_16 ;
T_1 V_23 ;
int V_14 ;
if ( V_13 >= V_17 ) {
F_8 ( F_1 () , L_1 , V_18 ,
__LINE__ , V_13 ) ;
return;
}
switch ( V_13 ) {
case 0 :
V_15 = ( T_1 ) V_21 << 32 ;
V_22 = V_24 ;
V_16 = 0x0 ;
V_23 = 0x0 ;
break;
case 1 :
V_15 = ( T_1 ) V_21 ;
V_22 = V_20 ;
V_16 = 0x0 ;
V_23 = 0x0 ;
break;
case 2 :
V_15 = 0x0 ;
V_22 = 0x0 ;
V_16 = ( T_1 ) V_21 << 32 ;
V_23 = V_24 ;
break;
case 3 :
V_15 = 0x0 ;
V_22 = 0x0 ;
V_16 = ( T_1 ) V_21 ;
V_23 = V_20 ;
break;
default:
F_12 () ;
}
V_14 = F_9 ( V_2 -> V_19 ,
V_15 , V_22 ,
V_16 , V_23 ,
& V_15 , & V_16 ) ;
if ( V_14 )
F_10 ( F_1 () , L_2
L_4 , V_18 , __LINE__ ,
V_13 , V_21 , F_11 ( V_14 ) ) ;
}
T_2 F_14 ( T_2 V_12 , T_2 V_25 )
{
T_2 V_21 ;
T_2 V_13 = V_25 & ( V_17 - 1 ) ;
V_21 = F_7 ( V_12 , V_13 ) ;
if ( F_15 ( V_12 , V_13 ) == 16 )
V_21 = ( V_25 < V_17 ) ? ( V_21 >> 16 ) : ( V_21 & 0xffff ) ;
return V_21 ;
}
void F_16 ( T_2 V_12 , T_2 V_25 , T_2 V_21 )
{
T_2 V_13 ;
T_2 V_26 ;
V_13 = V_25 & ( V_17 - 1 ) ;
if ( F_15 ( V_12 , V_13 ) == 16 ) {
V_26 = F_7 ( V_12 , V_13 ) ;
if ( V_25 < V_17 )
V_21 = ( V_21 << 16 ) | ( V_26 & 0xffff ) ;
else
V_21 = ( V_21 & 0xffff ) | ( V_26 & 0xffff0000 ) ;
}
F_13 ( V_12 , V_13 , V_21 ) ;
}
T_2 F_17 ( T_2 V_12 , T_2 V_25 )
{
return 0 ;
}
void F_18 ( T_2 V_12 , T_2 V_25 , T_2 V_21 )
{
int V_14 ;
static const T_1 V_27 = 0xFFFFFFFFFFFFFFFFULL ;
T_1 V_28 ;
if ( V_25 >= V_29 ) {
F_8 ( F_1 () , L_5 , V_18 ,
__LINE__ , V_25 ) ;
return;
}
V_14 = F_19 ( V_2 -> V_19 , V_25 , V_21 , V_27 ,
& V_28 ) ;
if ( V_14 )
F_10 ( F_1 () , L_6
L_7 , V_18 , __LINE__ , V_25 ,
F_11 ( V_14 ) ) ;
}
T_2 F_20 ( T_2 V_12 , enum V_30 V_31 )
{
int V_14 = 0 ;
T_1 V_21 = 0 ;
switch ( V_31 ) {
case V_32 :
return V_2 -> V_33 . V_32 ;
case V_34 :
return V_35 ;
case V_36 :
return V_2 -> V_33 . V_36 ;
case V_37 :
V_14 = F_21 ( V_2 -> V_19 , 0 , 0 , & V_21 ) ;
if ( V_14 ) {
V_21 = 0 ;
F_8 ( F_1 () , L_8
L_9 , V_18 , __LINE__ , V_31 ,
F_11 ( V_14 ) ) ;
}
return ( T_2 ) V_21 ;
case V_38 :
return V_2 -> V_33 . V_38 ;
case V_39 :
return V_2 -> V_33 . V_39 ;
case V_40 :
V_14 = F_22 ( V_2 -> V_19 ,
& V_21 ) ;
if ( V_14 ) {
V_21 = 0 ;
F_8 ( F_1 () , L_10
L_9 , V_18 , __LINE__ , V_31 ,
F_11 ( V_14 ) ) ;
}
return ( T_2 ) V_21 ;
case V_41 :
return 0 ;
default:
F_8 ( F_1 () , L_11 , V_18 ,
__LINE__ , V_31 ) ;
F_12 () ;
break;
}
return 0 ;
}
void F_23 ( T_2 V_12 , enum V_30 V_31 , T_2 V_21 )
{
int V_14 = 0 ;
T_1 V_42 ;
switch ( V_31 ) {
case V_38 :
if ( V_21 != V_2 -> V_33 . V_38 )
V_14 = F_24 ( V_2 -> V_19 ,
V_21 ,
V_43 ,
& V_42 ) ;
V_2 -> V_33 . V_38 = V_21 ;
break;
case V_39 :
if ( V_21 != V_2 -> V_33 . V_39 )
V_14 = F_25 ( V_2 -> V_19 ,
V_21 ,
V_43 ,
& V_42 ) ;
V_2 -> V_33 . V_39 = V_21 ;
break;
case V_32 :
if ( V_44 )
V_21 |= ( V_45 |
V_46 ) ;
if ( V_21 != V_2 -> V_33 . V_32 )
V_14 = F_26 ( V_2 -> V_19 ,
V_21 ,
V_43 ,
0 , 0 , & V_42 ,
& V_42 ) ;
V_2 -> V_33 . V_32 = V_21 ;
break;
case V_37 :
V_14 = F_21 ( V_2 -> V_19 , V_21 ,
V_43 , & V_42 ) ;
break;
case V_36 :
if ( V_21 != V_2 -> V_33 . V_36 )
V_14 = F_27 ( V_2 -> V_19 ,
V_21 ,
V_43 ,
& V_42 ) ;
V_2 -> V_33 . V_36 = V_21 ;
break;
case V_34 :
case V_41 :
case V_40 :
break;
default:
F_8 ( F_1 () , L_11 , V_18 ,
__LINE__ , V_31 ) ;
F_12 () ;
break;
}
if ( V_14 )
F_10 ( F_1 () , L_12
L_9 , V_18 , __LINE__ , V_31 ,
F_11 ( V_14 ) ) ;
}
T_2 F_15 ( T_2 V_12 , T_2 V_13 )
{
T_2 V_47 ;
if ( V_13 >= V_17 ) {
F_8 ( F_1 () , L_1 , V_18 ,
__LINE__ , V_13 ) ;
return 0 ;
}
V_47 = F_20 ( V_12 , V_32 ) ;
return ( V_47 & F_28 ( V_13 ) ) ? 16 : 32 ;
}
void F_29 ( T_2 V_12 , T_2 V_13 , T_2 V_48 )
{
T_2 V_47 ;
if ( V_13 >= V_17 ) {
F_8 ( F_1 () , L_1 , V_18 ,
__LINE__ , V_13 ) ;
return;
}
V_47 = F_20 ( V_12 , V_32 ) ;
switch ( V_48 ) {
case 16 :
V_47 |= F_28 ( V_13 ) ;
F_23 ( V_12 , V_32 , V_47 ) ;
break;
case 32 :
V_47 &= ~ F_28 ( V_13 ) ;
F_23 ( V_12 , V_32 , V_47 ) ;
break;
default:
F_12 () ;
}
}
static T_1 F_30 ( T_1 V_49 )
{
if ( V_49 == 2 )
V_49 = 3 ;
if ( V_49 <= 6 )
return V_50 + V_49 ;
else if ( V_49 == 7 )
return V_51 ;
else
return V_52 ;
}
static T_1 F_31 ( T_1 V_49 )
{
switch ( V_49 ) {
case 2 :
case 3 :
case 4 :
V_49 += 2 ;
break;
case 5 :
V_49 = 8 ;
break;
default:
break;
}
return V_53 + V_49 ;
}
static T_1 F_32 ( T_1 V_49 )
{
return V_54 + V_49 ;
}
static T_1 F_33 ( T_1 V_49 )
{
switch ( V_49 ) {
case 3 :
V_49 = 4 ;
break;
case 4 :
V_49 = 6 ;
break;
default:
break;
}
return V_55 + V_49 ;
}
static T_1 F_34 ( T_1 V_49 ,
T_1 V_56 )
{
switch ( V_49 ) {
case 3 :
case 4 :
case 5 :
V_49 += 1 ;
break;
default:
break;
}
switch ( V_56 ) {
case 4 :
case 5 :
case 6 :
V_56 += 2 ;
break;
case 7 :
case 8 :
case 9 :
case 10 :
V_56 += 4 ;
break;
case 11 :
case 12 :
case 13 :
V_56 += 5 ;
break;
default:
break;
}
if ( V_49 <= 5 )
return ( V_57 + V_49 ) ;
else
return ( V_57 + V_49
+ V_56 - 1 ) ;
}
static T_1 F_35 ( T_1 V_49 )
{
return V_58 + V_49 ;
}
static T_1 F_36 ( T_1 V_49 )
{
return V_59 + V_49 ;
}
static T_1 F_37 ( T_1 V_60 )
{
T_1 V_61 ;
T_1 V_49 ;
T_1 V_56 ;
V_49 = 0 ;
V_56 = 0 ;
V_61 = 0 ;
if ( V_60 < 1000 ) {
if ( V_60 < 100 ) {
if ( 20 <= V_60 && V_60 < 30 ) {
V_61 = 2 ;
V_49 = V_60 - 20 ;
} else if ( 30 <= V_60 && V_60 < 40 ) {
V_61 = 3 ;
V_49 = V_60 - 30 ;
} else if ( 40 <= V_60 && V_60 < 50 ) {
V_61 = 4 ;
V_49 = V_60 - 40 ;
} else if ( 50 <= V_60 && V_60 < 60 ) {
V_61 = 5 ;
V_49 = V_60 - 50 ;
} else if ( 60 <= V_60 && V_60 < 70 ) {
V_61 = 6 ;
V_49 = V_60 - 60 ;
} else if ( 70 <= V_60 && V_60 < 80 ) {
V_61 = 7 ;
V_49 = V_60 - 70 ;
} else if ( 80 <= V_60 && V_60 < 90 ) {
V_61 = 8 ;
V_49 = V_60 - 80 ;
}
} else if ( 200 <= V_60 && V_60 < 300 ) {
V_61 = 2 ;
V_49 = V_60 - 200 ;
} else if ( 600 <= V_60 && V_60 < 700 ) {
V_61 = 6 ;
V_49 = 5 ;
V_56 = V_60 - 650 ;
}
} else if ( 6000 <= V_60 && V_60 < 7000 ) {
V_61 = 6 ;
V_49 = 5 ;
V_56 = V_60 - 6500 ;
}
switch ( V_61 ) {
case 2 :
return F_30 ( V_49 ) ;
case 3 :
return F_31 ( V_49 ) ;
case 4 :
return F_32 ( V_49 ) ;
case 5 :
return F_33 ( V_49 ) ;
case 6 :
return F_34 ( V_49 ,
V_56 ) ;
case 7 :
return F_35 ( V_49 ) ;
case 8 :
return F_36 ( V_49 ) ;
default:
F_8 ( F_1 () , L_13 , V_18 ,
__LINE__ , V_60 ) ;
F_12 () ;
break;
}
return 0 ;
}
static T_1 F_38 ( T_3 V_62 )
{
switch ( V_62 ) {
case 1 :
return 0xF000 ;
case 2 :
return 0x0F00 ;
case 4 :
return 0x00F0 ;
case 8 :
default:
return 0x000F ;
}
}
static int F_39 ( T_1 V_63 , T_1 V_64 ,
T_1 V_65 , T_1 V_66 , T_1 V_67 , T_1 V_68 )
{
int V_69 ;
V_69 = F_40 ( V_2 -> V_19 , V_63 , V_64 ,
V_65 , V_66 , V_67 , V_68 ) ;
if ( V_69 )
F_10 ( F_1 () ,
L_14 ,
V_18 , __LINE__ , V_69 , V_63 , V_64 ,
V_65 , V_66 , V_67 , V_68 ) ;
return V_69 ;
}
int F_41 ( T_1 V_70 , T_3 V_71 , T_4 V_72 ,
T_3 V_73 )
{
int V_69 ;
T_1 V_63 ;
T_1 V_64 ;
T_1 V_65 ;
T_1 V_66 , V_67 , V_68 ;
if ( V_70 == 0 )
return F_39 ( 0 , 0 , 0 , 0 , 0 , 0 ) ;
V_63 =
F_37 ( V_70 ) ;
V_64 = F_38 ( V_73 ) ;
switch ( V_70 ) {
case V_74 :
V_65 = 1 ;
V_65 = V_65 << ( 63 - V_71 ) ;
break;
case V_75 :
V_65 = 1 ;
V_65 = ( V_65 << ( 63 - V_71 ) ) | 0x3 ;
break;
default:
V_65 = 0 ;
break;
}
V_66 = 1 ;
if ( V_76 <= V_70 &&
V_70 < V_77 )
V_67 = V_72 ;
else
V_67 = V_2 -> V_78 ;
V_68 = 0 ;
V_69 = F_39 ( V_63 , V_64 , V_65 ,
V_66 , V_67 , V_68 ) ;
if ( V_69 )
F_10 ( F_1 () , L_15 ,
V_18 , __LINE__ , V_69 ) ;
return V_69 ;
}
T_2 F_42 ( int V_12 )
{
return F_43 ( V_12 ) ;
}
void F_44 ( T_2 V_12 )
{
int V_14 ;
T_1 V_79 ;
int V_80 = 0 ;
V_2 -> V_81 = 0 ;
if ( V_44 ) {
if ( ! ( V_2 -> V_33 . V_36 &
( V_82
| V_83 ) ) ) {
V_14 = F_27 ( V_2 -> V_19 ,
( V_84 |
V_85 |
V_86 |
V_87 ) ,
0xFFFFFFFFFFFFFFFFULL , & V_79 ) ;
if ( V_14 )
F_10 ( F_1 () , L_16
L_17
L_18 , V_18 , __LINE__ ,
F_11 ( V_14 ) ) ;
V_80 = ! V_14 ;
}
}
V_14 = F_45 ( V_2 -> V_19 ) ;
if ( V_14 )
F_10 ( F_1 () , L_19 ,
V_18 , __LINE__ , F_11 ( V_14 ) ) ;
if ( V_44 && ! V_14 && V_80 )
F_3 ( F_6 () | V_88 ) ;
}
void F_46 ( T_2 V_12 )
{
int V_14 ;
T_1 V_79 ;
F_3 ( F_6 () | V_89 ) ;
V_14 = F_47 ( V_2 -> V_19 , & V_79 ) ;
if ( V_14 ) {
if ( V_14 != V_90 )
F_10 ( F_1 () , L_20 ,
V_18 , __LINE__ , F_11 ( V_14 ) ) ;
return;
}
V_2 -> V_81 = V_79 ;
F_8 ( F_1 () , L_21 , V_18 , __LINE__ ,
V_2 -> V_81 , V_2 -> V_81 ) ;
}
int F_48 ( unsigned long V_91 , void * V_92 , unsigned long V_93 ,
unsigned long * V_94 )
{
int V_14 ;
* V_94 = 0 ;
if ( ! V_2 -> V_95 )
return - V_96 ;
if ( V_91 >= V_2 -> V_81 )
return 0 ;
V_93 = F_49 ( T_1 , V_93 , V_2 -> V_81 - V_91 ) ;
while ( * V_94 < V_93 ) {
const unsigned long V_97 = V_93 - * V_94 ;
T_1 V_79 ;
V_14 = F_50 ( V_2 -> V_19 , V_91 ,
V_97 , & V_79 ) ;
if ( V_14 ) {
F_8 ( F_1 () , L_22 ,
V_18 , __LINE__ , V_97 , V_91 ) ;
F_10 ( F_1 () , L_23
L_24 , V_18 , __LINE__ ,
F_11 ( V_14 ) ) ;
return V_14 == V_90 ? - V_98 : - V_99 ;
}
memcpy ( V_92 , V_2 -> V_95 , V_79 ) ;
V_92 += V_79 ;
* V_94 += V_79 ;
V_91 += V_79 ;
}
F_8 ( F_1 () , L_25 , V_18 , __LINE__ ,
* V_94 ) ;
return 0 ;
}
int F_51 ( unsigned long V_91 , void T_5 * V_92 ,
unsigned long V_93 , unsigned long * V_94 )
{
int V_14 ;
* V_94 = 0 ;
if ( ! V_2 -> V_95 )
return - V_96 ;
if ( V_91 >= V_2 -> V_81 )
return 0 ;
V_93 = F_49 ( T_1 , V_93 , V_2 -> V_81 - V_91 ) ;
while ( * V_94 < V_93 ) {
const unsigned long V_97 = V_93 - * V_94 ;
T_1 V_79 ;
V_14 = F_50 ( V_2 -> V_19 , V_91 ,
V_97 , & V_79 ) ;
if ( V_14 ) {
F_8 ( F_1 () , L_22 ,
V_18 , __LINE__ , V_97 , V_91 ) ;
F_10 ( F_1 () , L_23
L_24 , V_18 , __LINE__ ,
F_11 ( V_14 ) ) ;
return V_14 == V_90 ? - V_98 : - V_99 ;
}
V_14 = F_52 ( V_92 , V_2 -> V_95 , V_79 ) ;
if ( V_14 ) {
F_8 ( F_1 () , L_26 ,
V_18 , __LINE__ , V_79 , V_92 ) ;
F_10 ( F_1 () , L_27 ,
V_18 , __LINE__ , V_14 ) ;
return - V_100 ;
}
V_92 += V_79 ;
* V_94 += V_79 ;
V_91 += V_79 ;
}
F_8 ( F_1 () , L_25 , V_18 , __LINE__ ,
* V_94 ) ;
return 0 ;
}
T_2 F_53 ( T_2 V_12 )
{
return F_20 ( V_12 , V_40 ) ;
}
void F_54 ( T_2 V_12 , T_2 V_101 , T_2 V_27 )
{
if ( V_27 )
F_23 ( V_12 , V_40 , V_27 ) ;
}
void F_55 ( T_2 V_12 )
{
F_53 ( V_12 ) ;
F_23 ( V_12 , V_40 , 0 ) ;
}
int F_56 ( enum V_102 V_103 , void * V_95 ,
T_1 V_104 )
{
int V_14 ;
T_1 V_105 ;
F_2 ( ! V_2 ) ;
F_2 ( V_103 != V_106
&& V_103 != V_107 ) ;
if ( V_103 == V_106 && V_95 )
F_8 ( F_1 () , L_28 , V_18 , __LINE__ ) ;
if ( ! F_57 ( & V_2 -> V_108 , 1 , 1 ) ) {
F_8 ( F_1 () , L_29 , V_18 , __LINE__ ) ;
return - V_98 ;
}
if ( V_103 == V_106 ) {
V_2 -> V_104 = 0 ;
V_2 -> V_109 = NULL ;
V_2 -> V_95 = NULL ;
} else if ( V_95 ) {
if ( V_95 != ( void * ) F_58 ( ( unsigned long ) V_95 , 128 )
|| V_104 != F_58 ( V_104 , 128 ) ) {
F_10 ( F_1 () , L_30 ,
V_18 , __LINE__ ) ;
V_14 = - V_99 ;
goto V_110;
}
V_2 -> V_104 = V_104 ;
V_2 -> V_109 = NULL ;
V_2 -> V_95 = V_95 ;
} else {
V_2 -> V_104 = V_111 ;
V_2 -> V_109 = F_59 (
V_2 -> V_104 + 127 , V_112 ) ;
if ( ! V_2 -> V_109 ) {
F_10 ( F_1 () , L_31
L_32 , V_18 , __LINE__ ) ;
V_14 = - V_113 ;
goto V_114;
}
V_2 -> V_95 = ( void * ) F_58 (
( unsigned long ) V_2 -> V_109 , 128 ) ;
}
V_14 = F_60 ( V_2 -> V_115 , V_103 , 0 , 0 ,
F_61 ( F_62 ( V_2 -> V_95 ) ) ,
V_2 -> V_104 , & V_2 -> V_19 ,
& V_2 -> V_116 , & V_105 ) ;
if ( V_14 ) {
F_10 ( F_1 () , L_33 ,
V_18 , __LINE__ , F_11 ( V_14 ) ) ;
V_14 = - V_99 ;
goto V_117;
}
V_2 -> V_33 . V_32 = V_118 ;
V_2 -> V_33 . V_36 = V_118 ;
V_2 -> V_33 . V_38 = V_118 ;
V_2 -> V_33 . V_39 = V_118 ;
F_8 ( F_1 () , L_34
L_35 , V_18 , __LINE__ , V_2 -> V_19 ,
V_2 -> V_116 , V_105 ) ;
return 0 ;
V_117:
F_63 ( V_2 -> V_109 ) ;
V_2 -> V_109 = NULL ;
V_114:
V_110:
F_64 ( & V_2 -> V_108 ) ;
return V_14 ;
}
int F_65 ( void )
{
F_8 ( F_1 () , L_36 , V_18 , __LINE__ ) ;
F_66 ( V_2 -> V_19 ) ;
V_2 -> V_19 = 0 ;
F_63 ( V_2 -> V_109 ) ;
V_2 -> V_109 = NULL ;
F_64 ( & V_2 -> V_108 ) ;
return 0 ;
}
static int F_67 ( struct V_119 * V_120 )
{
F_8 ( & V_120 -> V_4 , L_37 , V_18 , __LINE__ ) ;
if ( V_2 ) {
F_68 ( & V_120 -> V_4 , L_38 ,
V_18 , __LINE__ ) ;
return - V_98 ;
}
V_2 = F_59 ( sizeof( * V_2 ) , V_112 ) ;
if ( ! V_2 )
return - V_113 ;
V_2 -> V_3 = V_120 ;
V_2 -> V_115 = V_120 -> V_121 . V_115 ;
V_2 -> V_78 = V_120 -> V_121 . V_78 ;
V_2 -> V_122 = V_120 -> V_121 . V_122 ;
F_68 ( & V_120 -> V_4 , L_39 , V_18 , __LINE__ ) ;
return 0 ;
}
static int F_69 ( struct V_119 * V_120 )
{
F_8 ( & V_120 -> V_4 , L_40 , V_18 , __LINE__ ) ;
F_65 () ;
F_63 ( V_2 ) ;
V_2 = NULL ;
F_68 ( & V_120 -> V_4 , L_39 , V_18 , __LINE__ ) ;
return 0 ;
}
static int T_6 F_70 ( void )
{
F_71 ( L_41 , V_18 , __LINE__ ) ;
return F_72 ( & V_123 ) ;
}
static void T_7 F_73 ( void )
{
F_71 ( L_41 , V_18 , __LINE__ ) ;
F_74 ( & V_123 ) ;
}
