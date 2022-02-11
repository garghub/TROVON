static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 , T_1 * V_5 )
{
const struct V_6 * V_7 = & V_4 -> V_8 . V_9 ;
switch ( V_7 -> V_10 ) {
case 1 :
* V_5 = F_2 ( V_4 -> V_11 ) ;
break;
case 2 :
* V_5 = F_3 ( V_4 -> V_11 ) ;
break;
case 3 :
* V_5 = F_4 ( V_4 -> V_11 ) ;
break;
default:
return - V_12 ;
}
F_5 ( & V_2 -> V_13 -> V_14 , L_1 , * V_5 ,
V_7 -> V_15 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
const struct V_3 * V_4 , T_1 V_5 )
{
const struct V_6 * V_7 = & V_4 -> V_8 . V_9 ;
switch ( V_7 -> V_10 ) {
case 1 :
F_7 ( ( V_16 ) V_5 , V_4 -> V_11 ) ;
break;
case 2 :
F_8 ( ( V_17 ) V_5 , V_4 -> V_11 ) ;
break;
case 3 :
F_9 ( V_5 , V_4 -> V_11 ) ;
break;
default:
return - V_12 ;
}
F_5 ( & V_2 -> V_13 -> V_14 , L_2 , V_5 ,
V_7 -> V_15 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_18 ,
T_1 V_19 , T_1 * V_20 )
{
struct V_3 * V_4 ;
if ( V_18 >= F_11 ( V_2 -> V_21 ) )
return - V_12 ;
if ( ! V_2 -> V_21 [ V_18 ] )
return - V_22 ;
F_5 ( & V_2 -> V_13 -> V_14 , L_3 , V_18 ) ;
F_12 (instr, wdat->instructions[action], node) {
const struct V_23 * V_8 = & V_4 -> V_8 ;
const struct V_6 * V_7 ;
T_1 V_24 , V_5 , V_25 , V_26 , V_27 ;
bool V_28 ;
int V_29 ;
V_7 = & V_8 -> V_9 ;
V_28 = V_8 -> V_30 & V_31 ;
V_24 = V_8 -> V_30 & ~ V_31 ;
V_5 = V_8 -> V_5 ;
V_25 = V_8 -> V_25 ;
switch ( V_24 ) {
case V_32 :
V_29 = F_1 ( V_2 , V_4 , & V_26 ) ;
if ( V_29 )
return V_29 ;
V_26 >>= V_7 -> V_33 ;
V_26 &= V_25 ;
if ( V_20 )
* V_20 = V_26 == V_5 ;
break;
case V_34 :
V_29 = F_1 ( V_2 , V_4 , & V_26 ) ;
if ( V_29 )
return V_29 ;
V_26 >>= V_7 -> V_33 ;
V_26 &= V_25 ;
if ( V_20 )
* V_20 = V_26 ;
break;
case V_35 :
V_26 = V_5 & V_25 ;
V_26 <<= V_7 -> V_33 ;
if ( V_28 ) {
V_29 = F_1 ( V_2 , V_4 , & V_27 ) ;
if ( V_29 )
return V_29 ;
V_27 = V_27 & ~ ( V_25 << V_7 -> V_33 ) ;
V_26 |= V_27 ;
}
V_29 = F_6 ( V_2 , V_4 , V_26 ) ;
if ( V_29 )
return V_29 ;
break;
case V_36 :
V_26 = V_19 ;
V_26 &= V_25 ;
V_26 <<= V_7 -> V_33 ;
if ( V_28 ) {
V_29 = F_1 ( V_2 , V_4 , & V_27 ) ;
if ( V_29 )
return V_29 ;
V_27 = V_27 & ~ ( V_25 << V_7 -> V_33 ) ;
V_26 |= V_27 ;
}
V_29 = F_6 ( V_2 , V_4 , V_26 ) ;
if ( V_29 )
return V_29 ;
break;
default:
F_13 ( & V_2 -> V_13 -> V_14 , L_4 ,
V_24 ) ;
return - V_12 ;
}
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_29 ;
V_29 = F_10 ( V_2 , V_37 , 0 , NULL ) ;
if ( V_29 && V_29 != - V_22 ) {
F_13 ( & V_2 -> V_13 -> V_14 ,
L_5 ) ;
return V_29 ;
}
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
T_1 V_38 = 0 ;
int V_29 ;
V_29 = F_10 ( V_2 , V_39 , 0 , & V_38 ) ;
if ( V_29 && V_29 != - V_22 ) {
F_13 ( & V_2 -> V_13 -> V_14 , L_6 ) ;
return;
}
if ( V_38 )
V_2 -> V_40 . V_41 = V_42 ;
V_29 = F_10 ( V_2 , V_43 , 0 , NULL ) ;
if ( V_29 && V_29 != - V_22 )
F_13 ( & V_2 -> V_13 -> V_14 , L_7 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
T_1 V_44 = 0 ;
int V_29 ;
V_29 = F_10 ( V_2 , V_45 , 0 ,
& V_44 ) ;
if ( V_29 && V_29 != - V_22 )
F_13 ( & V_2 -> V_13 -> V_14 , L_8 ) ;
if ( V_44 )
F_17 ( V_46 , & V_2 -> V_40 . V_47 ) ;
}
static int F_18 ( struct V_48 * V_40 )
{
return F_10 ( F_19 ( V_40 ) ,
V_49 , 0 , NULL ) ;
}
static int F_20 ( struct V_48 * V_40 )
{
return F_10 ( F_19 ( V_40 ) ,
V_50 , 0 , NULL ) ;
}
static int F_21 ( struct V_48 * V_40 )
{
return F_10 ( F_19 ( V_40 ) , V_51 , 0 , NULL ) ;
}
static int F_22 ( struct V_48 * V_40 ,
unsigned int V_52 )
{
struct V_1 * V_2 = F_19 ( V_40 ) ;
unsigned int V_53 ;
int V_29 ;
V_53 = V_52 * 1000 / V_2 -> V_54 ;
V_29 = F_10 ( V_2 , V_55 , V_53 , NULL ) ;
if ( ! V_29 )
V_40 -> V_52 = V_52 ;
return V_29 ;
}
static unsigned int F_23 ( struct V_48 * V_40 )
{
struct V_1 * V_2 = F_19 ( V_40 ) ;
T_1 V_53 = 0 ;
F_10 ( V_2 , V_56 , 0 , & V_53 ) ;
return V_53 * V_2 -> V_54 / 1000 ;
}
static int F_24 ( struct V_57 * V_13 )
{
const struct V_23 * V_58 ;
const struct V_59 * V_60 ;
struct V_1 * V_2 ;
struct V_61 * V_62 ;
void T_2 * * V_63 ;
T_3 V_47 ;
int V_64 , V_29 ;
V_47 = F_25 ( V_65 , 0 ,
(struct V_66 * * ) & V_60 ) ;
if ( F_26 ( V_47 ) )
return - V_67 ;
V_2 = F_27 ( & V_13 -> V_14 , sizeof( * V_2 ) , V_68 ) ;
if ( ! V_2 )
return - V_69 ;
V_63 = F_28 ( & V_13 -> V_14 , V_13 -> V_70 , sizeof( * V_63 ) ,
V_68 ) ;
if ( ! V_63 )
return - V_69 ;
if ( V_60 -> V_71 < 1 )
return - V_12 ;
if ( V_60 -> V_72 > V_60 -> V_73 )
return - V_12 ;
V_2 -> V_54 = V_60 -> V_71 ;
V_2 -> V_40 . V_74 = V_2 -> V_54 * V_60 -> V_72 ;
V_2 -> V_40 . V_75 = V_2 -> V_54 * V_60 -> V_73 ;
V_2 -> V_76 = V_60 -> V_24 & V_77 ;
V_2 -> V_40 . V_78 = & V_79 ;
V_2 -> V_40 . V_80 = & V_81 ;
V_2 -> V_13 = V_13 ;
for ( V_64 = 0 ; V_64 < V_13 -> V_70 ; V_64 ++ ) {
void T_2 * V_11 ;
V_62 = & V_13 -> V_61 [ V_64 ] ;
if ( F_29 ( V_62 ) == V_82 ) {
V_11 = F_30 ( & V_13 -> V_14 , V_62 ) ;
if ( F_31 ( V_11 ) )
return F_32 ( V_11 ) ;
} else if ( F_29 ( V_62 ) == V_83 ) {
V_11 = F_33 ( & V_13 -> V_14 , V_62 -> V_84 , 1 ) ;
if ( ! V_11 )
return - V_69 ;
} else {
F_13 ( & V_13 -> V_14 , L_9 ) ;
return - V_12 ;
}
V_63 [ V_64 ] = V_11 ;
}
V_58 = (struct V_23 * ) ( V_60 + 1 ) ;
for ( V_64 = 0 ; V_64 < V_60 -> V_58 ; V_64 ++ ) {
const struct V_6 * V_7 ;
struct V_3 * V_4 ;
struct V_85 * V_21 ;
unsigned int V_18 ;
struct V_61 V_86 ;
int V_87 ;
V_18 = V_58 [ V_64 ] . V_18 ;
if ( V_18 >= V_88 ) {
F_5 ( & V_13 -> V_14 , L_10 ,
V_18 ) ;
continue;
}
V_4 = F_27 ( & V_13 -> V_14 , sizeof( * V_4 ) , V_68 ) ;
if ( ! V_4 )
return - V_69 ;
F_34 ( & V_4 -> V_89 ) ;
V_4 -> V_8 = V_58 [ V_64 ] ;
V_7 = & V_58 [ V_64 ] . V_9 ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
V_86 . V_84 = V_7 -> V_15 ;
V_86 . V_90 = V_86 . V_84 + V_7 -> V_10 ;
if ( V_7 -> V_91 == V_92 ) {
V_86 . V_24 = V_82 ;
} else if ( V_7 -> V_91 == V_93 ) {
V_86 . V_24 = V_83 ;
} else {
F_5 ( & V_13 -> V_14 , L_11 ,
V_7 -> V_91 ) ;
continue;
}
for ( V_87 = 0 ; V_87 < V_13 -> V_70 ; V_87 ++ ) {
V_62 = & V_13 -> V_61 [ V_87 ] ;
if ( F_35 ( V_62 , & V_86 ) ) {
V_4 -> V_11 = V_63 [ V_87 ] + V_86 . V_84 - V_62 -> V_84 ;
break;
}
}
if ( ! V_4 -> V_11 ) {
F_13 ( & V_13 -> V_14 , L_12 ) ;
return - V_12 ;
}
V_21 = V_2 -> V_21 [ V_18 ] ;
if ( ! V_21 ) {
V_21 = F_27 ( & V_13 -> V_14 ,
sizeof( * V_21 ) , V_68 ) ;
if ( ! V_21 )
return - V_69 ;
F_34 ( V_21 ) ;
V_2 -> V_21 [ V_18 ] = V_21 ;
}
F_36 ( & V_4 -> V_89 , V_21 ) ;
}
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
V_29 = F_14 ( V_2 ) ;
if ( V_29 )
return V_29 ;
F_37 ( V_13 , V_2 ) ;
F_38 ( & V_2 -> V_40 , V_94 ) ;
return F_39 ( & V_13 -> V_14 , & V_2 -> V_40 ) ;
}
static int F_40 ( struct V_95 * V_14 )
{
struct V_57 * V_13 = F_41 ( V_14 ) ;
struct V_1 * V_2 = F_42 ( V_13 ) ;
int V_29 ;
if ( ! F_43 ( & V_2 -> V_40 ) )
return 0 ;
V_2 -> V_96 = false ;
if ( F_44 () == V_97 ||
! V_2 -> V_76 ) {
V_29 = F_20 ( & V_2 -> V_40 ) ;
if ( ! V_29 )
V_2 -> V_96 = true ;
} else {
V_29 = F_21 ( & V_2 -> V_40 ) ;
}
return V_29 ;
}
static int F_45 ( struct V_95 * V_14 )
{
struct V_57 * V_13 = F_41 ( V_14 ) ;
struct V_1 * V_2 = F_42 ( V_13 ) ;
int V_29 ;
if ( ! F_43 ( & V_2 -> V_40 ) )
return 0 ;
if ( ! V_2 -> V_96 ) {
V_29 = F_20 ( & V_2 -> V_40 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_22 ( & V_2 -> V_40 , V_2 -> V_40 . V_52 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_14 ( V_2 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_21 ( & V_2 -> V_40 ) ;
if ( V_29 )
return V_29 ;
}
return F_18 ( & V_2 -> V_40 ) ;
}
