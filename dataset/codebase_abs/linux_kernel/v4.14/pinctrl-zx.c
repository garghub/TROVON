static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * * V_6 , T_1 * V_7 )
{
return F_2 ( V_2 , V_4 , V_6 ,
V_7 , V_8 ) ;
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_9 ,
unsigned int V_10 )
{
struct V_11 * V_12 = F_4 ( V_2 ) ;
struct V_13 * V_14 = V_12 -> V_14 ;
const struct V_15 * V_16 = V_14 -> V_17 + V_10 ;
struct V_18 * V_19 = V_16 -> V_20 ;
struct V_21 * V_22 ;
T_1 V_23 , V_24 , V_25 ;
struct V_26 * V_27 ;
unsigned long V_28 ;
T_1 V_29 , V_30 ;
if ( ! V_19 )
return - V_31 ;
V_22 = V_19 -> V_32 ;
V_23 = ( 1 << V_19 -> V_33 ) - 1 ;
V_24 = V_19 -> V_24 ;
V_25 = V_19 -> V_25 ;
V_27 = F_5 ( V_2 , V_9 ) ;
if ( ! V_27 )
return - V_31 ;
while ( V_22 -> V_34 ) {
if ( strcmp ( V_22 -> V_34 , V_27 -> V_34 ) == 0 )
break;
V_22 ++ ;
}
V_30 = V_22 -> V_35 ;
F_6 ( & V_12 -> V_36 , V_28 ) ;
if ( V_19 -> V_37 ) {
T_2 V_38 = V_16 -> V_39 / 16 * 4 ;
T_2 V_40 = ( V_16 -> V_39 % 16 ) * 2 ;
if ( V_30 & V_41 ) {
V_29 = F_7 ( V_12 -> V_42 + V_38 ) ;
V_29 &= ~ ( 0x3 << V_40 ) ;
V_29 |= ( V_30 & 0x3 ) << V_40 ;
F_8 ( V_29 , V_12 -> V_42 + V_38 ) ;
} else {
V_29 = F_7 ( V_12 -> V_43 + V_24 ) ;
V_29 &= ~ ( V_23 << V_25 ) ;
V_29 |= ( V_30 & V_23 ) << V_25 ;
F_8 ( V_29 , V_12 -> V_43 + V_24 ) ;
V_29 = F_7 ( V_12 -> V_42 + V_38 ) ;
V_29 &= ~ ( 0x3 << V_40 ) ;
V_29 |= V_44 << V_40 ;
F_8 ( V_29 , V_12 -> V_42 + V_38 ) ;
}
} else {
V_29 = F_7 ( V_12 -> V_43 + V_24 ) ;
V_29 &= ~ ( V_23 << V_25 ) ;
V_29 |= ( V_30 & V_23 ) << V_25 ;
F_8 ( V_29 , V_12 -> V_43 + V_24 ) ;
}
F_9 ( & V_12 -> V_36 , V_28 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_45 ,
unsigned long * V_46 )
{
struct V_11 * V_12 = F_4 ( V_2 ) ;
struct V_13 * V_14 = V_12 -> V_14 ;
const struct V_15 * V_16 = V_14 -> V_17 + V_45 ;
struct V_18 * V_19 = V_16 -> V_20 ;
enum V_47 V_48 = F_11 ( * V_46 ) ;
T_1 V_29 ;
if ( ! V_19 )
return - V_31 ;
V_29 = F_7 ( V_12 -> V_42 + V_19 -> V_49 ) ;
V_29 = V_29 >> V_19 -> V_50 ;
switch ( V_48 ) {
case V_51 :
V_29 &= V_52 ;
V_29 = ! ! V_29 ;
if ( V_29 == 0 )
return - V_31 ;
break;
case V_53 :
V_29 &= V_54 ;
V_29 = ! ! V_29 ;
if ( V_29 == 0 )
return - V_31 ;
break;
case V_55 :
V_29 &= V_56 ;
V_29 = ! ! V_29 ;
if ( V_29 == 0 )
return - V_31 ;
break;
case V_57 :
V_29 &= V_58 ;
V_29 = V_29 >> V_59 ;
break;
case V_60 :
V_29 &= V_61 ;
V_29 = ! ! V_29 ;
break;
default:
return - V_62 ;
}
* V_46 = F_12 ( V_48 , V_29 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , unsigned int V_45 ,
unsigned long * V_63 , unsigned int V_64 )
{
struct V_11 * V_12 = F_4 ( V_2 ) ;
struct V_13 * V_14 = V_12 -> V_14 ;
const struct V_15 * V_16 = V_14 -> V_17 + V_45 ;
struct V_18 * V_19 = V_16 -> V_20 ;
enum V_47 V_48 ;
T_1 V_29 , V_65 ;
int V_66 ;
if ( ! V_19 )
return - V_31 ;
V_29 = F_7 ( V_12 -> V_42 + V_19 -> V_49 ) ;
for ( V_66 = 0 ; V_66 < V_64 ; V_66 ++ ) {
V_48 = F_11 ( V_63 [ V_66 ] ) ;
V_65 = F_14 ( V_63 [ V_66 ] ) ;
switch ( V_48 ) {
case V_51 :
V_29 |= V_52 << V_19 -> V_50 ;
break;
case V_53 :
V_29 |= V_54 << V_19 -> V_50 ;
break;
case V_55 :
V_29 |= V_56 << V_19 -> V_50 ;
break;
case V_57 :
V_29 &= ~ ( V_58 << V_19 -> V_50 ) ;
V_29 |= F_15 ( V_65 ) << V_19 -> V_50 ;
break;
case V_60 :
if ( V_65 )
V_29 |= V_61 << V_19 -> V_50 ;
else
V_29 &= ~ V_61 << V_19 -> V_50 ;
break;
default:
return - V_62 ;
}
}
F_8 ( V_29 , V_12 -> V_42 + V_19 -> V_49 ) ;
return 0 ;
}
static int F_16 ( struct V_67 * V_68 )
{
struct V_11 * V_12 = F_17 ( V_68 ) ;
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_26 * V_69 ;
int V_70 ;
struct V_71 * V_72 ;
int V_73 ;
int V_66 ;
V_73 = V_14 -> V_74 ;
V_72 = F_18 ( & V_68 -> V_75 , V_73 * sizeof( * V_72 ) ,
V_76 ) ;
if ( ! V_72 )
return - V_77 ;
for ( V_66 = 0 ; V_66 < V_73 ; V_66 ++ ) {
const struct V_15 * V_16 = V_14 -> V_17 + V_66 ;
struct V_71 * V_78 = V_72 + V_66 ;
V_78 -> V_34 = V_16 -> V_34 ;
V_78 -> V_17 = ( int * ) & V_16 -> V_39 ;
V_78 -> V_79 = 1 ;
F_19 ( & V_2 -> V_80 , V_66 , V_78 ) ;
}
V_2 -> V_81 = V_73 ;
V_69 = F_20 ( V_14 -> V_74 , sizeof( * V_69 ) , V_76 ) ;
if ( ! V_69 )
return - V_77 ;
V_70 = 0 ;
for ( V_66 = 0 ; V_66 < V_14 -> V_74 ; V_66 ++ ) {
const struct V_15 * V_16 = V_14 -> V_17 + V_66 ;
struct V_18 * V_19 = V_16 -> V_20 ;
struct V_21 * V_22 ;
if ( ! V_19 )
continue;
V_22 = V_19 -> V_32 ;
while ( V_22 -> V_34 ) {
struct V_26 * V_27 = V_69 ;
while ( V_27 -> V_34 ) {
if ( strcmp ( V_22 -> V_34 , V_27 -> V_34 ) == 0 ) {
V_27 -> V_82 ++ ;
break;
}
V_27 ++ ;
}
if ( ! V_27 -> V_34 ) {
V_27 -> V_34 = V_22 -> V_34 ;
V_27 -> V_82 = 1 ;
F_19 ( & V_2 -> V_83 ,
V_70 ++ , V_27 ) ;
}
V_22 ++ ;
}
}
V_2 -> V_84 = V_70 ;
V_69 = F_21 ( V_69 , V_70 * sizeof( * V_69 ) ,
V_76 ) ;
for ( V_66 = 0 ; V_66 < V_14 -> V_74 ; V_66 ++ ) {
const struct V_15 * V_16 = V_14 -> V_17 + V_66 ;
struct V_18 * V_19 = V_16 -> V_20 ;
struct V_21 * V_22 ;
if ( ! V_19 )
continue;
V_22 = V_19 -> V_32 ;
while ( V_22 -> V_34 ) {
struct V_26 * V_27 ;
const char * * V_78 ;
int V_85 ;
for ( V_85 = 0 ; V_85 < V_70 ; V_85 ++ )
if ( strcmp ( V_69 [ V_85 ] . V_34 , V_22 -> V_34 ) == 0 )
break;
V_27 = V_69 + V_85 ;
if ( ! V_27 -> V_86 ) {
V_27 -> V_86 = F_18 ( & V_68 -> V_75 ,
V_27 -> V_82 *
sizeof( * V_27 -> V_86 ) ,
V_76 ) ;
if ( ! V_27 -> V_86 ) {
F_22 ( V_69 ) ;
return - V_77 ;
}
}
V_78 = V_27 -> V_86 ;
while ( * V_78 )
V_78 ++ ;
* V_78 = V_16 -> V_34 ;
V_22 ++ ;
}
}
return 0 ;
}
int F_23 ( struct V_67 * V_68 ,
struct V_13 * V_14 )
{
struct V_87 * V_88 ;
struct V_11 * V_12 ;
struct V_3 * V_89 ;
struct V_90 * V_91 ;
int V_92 ;
V_12 = F_18 ( & V_68 -> V_75 , sizeof( * V_12 ) , V_76 ) ;
if ( ! V_12 )
return - V_77 ;
F_24 ( & V_12 -> V_36 ) ;
V_91 = F_25 ( V_68 , V_93 , 0 ) ;
V_12 -> V_43 = F_26 ( & V_68 -> V_75 , V_91 ) ;
if ( F_27 ( V_12 -> V_43 ) )
return F_28 ( V_12 -> V_43 ) ;
V_89 = F_29 ( V_68 -> V_75 . V_94 , L_1 , 0 ) ;
if ( ! V_89 ) {
F_30 ( & V_68 -> V_75 , L_2 ) ;
return - V_95 ;
}
V_12 -> V_42 = F_31 ( V_89 , 0 ) ;
if ( ! V_12 -> V_42 )
return - V_77 ;
V_12 -> V_75 = & V_68 -> V_75 ;
V_12 -> V_14 = V_14 ;
V_88 = F_18 ( & V_68 -> V_75 , sizeof( * V_88 ) , V_76 ) ;
if ( ! V_88 )
return - V_77 ;
V_88 -> V_34 = F_32 ( & V_68 -> V_75 ) ;
V_88 -> V_96 = V_97 ;
V_88 -> V_17 = V_14 -> V_17 ;
V_88 -> V_74 = V_14 -> V_74 ;
V_88 -> V_98 = & V_99 ;
V_88 -> V_100 = & V_101 ;
V_88 -> V_102 = & V_103 ;
V_12 -> V_2 = F_33 ( & V_68 -> V_75 , V_88 , V_12 ) ;
if ( F_27 ( V_12 -> V_2 ) ) {
V_92 = F_28 ( V_12 -> V_2 ) ;
F_30 ( & V_68 -> V_75 , L_3 , V_92 ) ;
return V_92 ;
}
F_34 ( V_68 , V_12 ) ;
V_92 = F_16 ( V_68 ) ;
if ( V_92 ) {
F_30 ( & V_68 -> V_75 , L_4 , V_92 ) ;
return V_92 ;
}
F_35 ( & V_68 -> V_75 , L_5 ) ;
return 0 ;
}
