int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned long V_5 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_2 -> V_10 ) ;
const T_1 * V_11 = V_4 -> V_12 ;
T_1 * V_13 = V_4 -> V_14 ;
unsigned int V_15 = ( ( 8 * V_4 -> V_16 + 7 ) / 8 ) ;
unsigned int V_16 , V_17 , V_18 ;
T_2 V_19 ;
enum {
V_20 ,
V_21 ,
V_22 ,
V_23 ,
V_24 ,
V_25
} V_26 = V_20 ;
do {
switch ( V_26 ) {
case V_20 :
{
if ( V_5 & V_27 ) {
if ( ! V_11 ) {
F_3 ( V_7 ,
L_1 ) ;
return - V_28 ;
}
V_9 -> V_29 = ( ( V_2 -> V_30
<< V_31 )
& V_32 ) ;
V_9 -> V_29 |= V_33 ;
V_9 -> V_29 |= * V_11 ;
V_11 ++ ;
V_15 -- ;
if ( V_15 ) {
V_26 = V_21 ;
break;
} else {
F_4 ( V_7 , L_2 ,
V_9 -> V_29 & V_34 ) ;
}
}
if ( V_11 && V_15 ) {
V_26 = V_22 ;
break;
}
if ( V_13 && V_15 ) {
V_26 = V_23 ;
break;
}
if ( V_5 & V_35 )
V_26 = V_24 ;
else
V_26 = V_25 ;
break;
}
case V_21 :
{
V_19 = 0 ;
V_17 = 0 ;
V_18 = 0 ;
while ( V_15 > 0 ) {
if ( V_17 < 3 ) {
V_19 = ( V_19 << 8 ) | ( * V_11 ++ ) ;
V_17 ++ ;
} else if ( ( V_18 < 15 ) && ( * V_11 == 0 ) ) {
V_18 ++ ;
V_11 ++ ;
} else {
break;
}
V_15 -- ;
}
V_9 -> V_29 &= ~ ( V_36 | V_37 ) ;
V_9 -> V_29 |= ( V_17 << V_38 ) |
( V_18 << V_39 ) ;
if ( V_17 > 0 )
F_5 ( V_19 , V_40 ) ;
F_4 ( V_7 , L_3 ,
V_9 -> V_29 & V_34 ,
V_17 , V_19 , V_18 ) ;
if ( V_15 > 0 ) {
V_26 = V_22 ;
} else if ( V_5 & V_35 ) {
V_26 = V_24 ;
} else {
V_26 = V_25 ;
}
break;
}
case V_22 :
{
V_9 -> V_29 |= V_41 ;
V_16 = 0 ;
V_19 = 0 ;
do {
if ( V_15 -- )
V_19 |= ( * V_11 ++ ) << ( 8 * V_16 ++ ) ;
if ( ( V_5 & V_35 )
&& ( V_15 == 0 ) ) {
V_9 -> V_29 &=
~ V_33 ;
}
if ( ( V_16 == 4 ) || ( V_15 == 0 ) ) {
F_5 ( V_19 , V_42 ) ;
F_5 ( V_9 -> V_29
| ( V_16 << V_43 ) ,
V_44 ) ;
V_16 = 0 ;
V_19 = 0 ;
V_9 -> V_29 &= ~ ( V_36
| V_37 ) ;
}
} while ( V_15 );
V_26 = V_25 ;
break;
}
case V_23 :
{
V_9 -> V_29 &= ~ V_41 ;
do {
if ( ( V_5 & V_35 )
&& ( V_15 <= 4 ) ) {
V_9 -> V_29 &=
~ V_33 ;
}
V_16 = ( V_15 > 4 ) ? 4 : V_15 ;
V_15 -= V_16 ;
F_5 ( V_9 -> V_29
| ( V_16 << V_43 ) , V_44 ) ;
V_9 -> V_29 &= ~ ( V_36
| V_37 ) ;
do {
V_19 = F_6 ( V_45 ) ;
if ( V_19 & V_46 ) {
F_3 ( V_7 , L_4 ) ;
F_3 ( V_7 , L_5 , V_19 ) ;
F_5 ( V_46 ,
V_45 ) ;
return - V_47 ;
}
} while ( V_19 & V_48 );
V_19 = F_6 ( V_42 ) ;
do {
* V_13 = ( V_19 & 0xFF ) ;
V_13 ++ ;
V_19 >>= 8 ;
V_16 -- ;
} while ( V_16 );
} while ( V_15 );
V_26 = V_25 ;
break;
}
case V_24 :
{
V_9 -> V_29 &= ~ V_33 ;
F_5 ( V_9 -> V_29 | ( 0 << V_43 ) ,
V_44 ) ;
V_19 = F_6 ( V_45 ) ;
if ( V_19 & V_46 ) {
F_3 ( V_7 , L_6 , V_19 ) ;
F_5 ( V_46 , V_45 ) ;
return - V_47 ;
}
V_26 = V_25 ;
break;
}
case V_25 :
break;
}
} while ( V_26 != V_25 );
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
unsigned int V_49 ;
unsigned long V_5 ;
F_8 ( & V_50 , V_5 ) ;
if ( V_2 -> V_51 >= V_52 ) {
F_9 ( 0 , V_53 , V_54 ) ;
V_49 = 1 ;
} else {
F_9 ( V_53 , 0 , V_54 ) ;
for ( V_49 = 1 ; V_49 < 7 ; V_49 ++ ) {
if ( V_55 / V_49 <= V_2 -> V_51 )
break;
}
}
F_10 ( V_56
| V_57
| V_58 ,
( V_49 << V_59 )
| ( V_49 << ( V_60 + 1 ) ) ,
V_61 ) ;
F_5 ( ( V_62 & ( 0x8 | 0x4 ) ) , V_63 ) ;
F_5 ( V_64 | V_65 ,
V_66 ) ;
F_5 ( V_67 , V_68 ) ;
F_10 ( V_69 , V_70 , V_71 ) ;
F_11 ( & V_50 , V_5 ) ;
return 0 ;
}
static int F_12 ( struct V_72 * V_10 ,
struct V_73 * V_74 )
{
struct V_8 * V_9 = F_2 ( V_10 ) ;
struct V_3 * V_4 ;
unsigned long V_75 ;
unsigned long V_5 ;
int V_76 = 0 ;
V_9 -> V_29 = 0 ;
V_74 -> V_77 = 0 ;
V_75 = V_27 ;
F_13 (t, &m->transfers, transfer_list) {
if ( F_14 ( & V_4 -> V_78 , & V_74 -> V_79 ) )
V_75 |= V_35 ;
F_8 ( & V_50 , V_5 ) ;
V_76 = F_1 ( V_74 -> V_2 , V_4 , V_75 ) ;
F_11 ( & V_50 , V_5 ) ;
if ( V_76 )
break;
V_74 -> V_77 += V_4 -> V_16 ;
F_15 ( V_4 -> V_80 || V_4 -> V_81 ) ;
V_75 = 0 ;
}
V_74 -> V_82 = V_76 ;
F_16 ( V_10 ) ;
return 0 ;
}
static int F_17 ( struct V_83 * V_84 )
{
struct V_8 * V_9 ;
struct V_72 * V_10 ;
int V_76 ;
if ( F_18 () != V_85 ) {
F_3 ( & V_84 -> V_7 , L_7 ) ;
return - V_86 ;
}
V_10 = F_19 ( & V_84 -> V_7 , sizeof( * V_9 ) ) ;
if ( ! V_10 )
return - V_87 ;
V_9 = F_2 ( V_10 ) ;
V_9 -> V_10 = V_10 ;
V_10 -> V_88 = V_89 ;
V_10 -> V_5 = V_90 ;
V_10 -> V_91 = F_7 ;
V_10 -> V_92 = F_12 ;
V_10 -> V_7 . V_93 = V_84 -> V_7 . V_93 ;
V_76 = F_20 ( & V_84 -> V_7 , V_10 ) ;
if ( V_76 )
F_21 ( V_10 ) ;
return V_76 ;
}
