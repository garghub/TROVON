static void F_1 ( struct V_1 * V_2 , short V_3 ,
short V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
unsigned V_7 = V_2 -> V_8 ;
unsigned V_9 = 0 ;
if ( V_3 ) {
if ( V_4 )
V_9 |= V_10 ;
else
V_9 |= V_11 ;
}
F_2 ( V_2 , F_3 ( V_7 ) ,
V_10 | V_11 ,
V_9 ) ;
switch ( V_6 -> V_12 ) {
case V_13 :
break;
case V_14 :
case V_15 :
{
unsigned V_16 = 0 ;
if ( V_3 ) {
V_16 |= V_17 ;
V_16 |= V_18 ;
}
if ( V_4 == 0 )
V_16 |= V_19 ;
F_2 ( V_2 , F_4 ( V_7 ) ,
V_17 | V_18 |
V_19 , V_16 ) ;
}
break;
}
}
static int F_5 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
unsigned int V_24 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
struct V_26 * V_27 = & V_23 -> V_28 -> V_27 ;
unsigned long V_29 ;
int V_30 = 0 ;
F_6 ( V_2 == NULL ) ;
if ( V_24 != V_27 -> V_31 )
return - V_32 ;
F_7 ( & V_2 -> V_33 , V_29 ) ;
if ( V_2 -> V_34 )
F_8 ( V_2 -> V_34 ) ;
else
V_30 = - V_35 ;
F_9 ( & V_2 -> V_33 , V_29 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_10 ( V_2 , 1 , V_36 ) ;
V_23 -> V_28 -> V_37 = NULL ;
return V_30 ;
}
static int F_11 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
struct V_5 * V_6 = V_2 -> V_6 ;
unsigned V_7 = V_2 -> V_8 ;
struct V_38 * V_28 = V_23 -> V_28 ;
struct V_26 * V_27 = & V_28 -> V_27 ;
int V_30 = 0 ;
F_12 ( V_23 , V_28 -> V_39 ) ;
V_2 -> V_34 -> V_40 = V_41 ;
switch ( V_6 -> V_12 ) {
case V_14 :
case V_15 :
F_13 ( V_2 -> V_34 , 32 , 32 ) ;
break;
case V_13 :
F_13 ( V_2 -> V_34 , 16 , 32 ) ;
break;
default:
F_14 () ;
break;
}
F_2 ( V_2 , F_15 ( V_7 ) , V_42 , 0 ) ;
F_1 ( V_2 , 1 , 1 ) ;
switch ( V_27 -> V_31 ) {
case V_43 :
V_28 -> V_37 = NULL ;
F_8 ( V_2 -> V_34 ) ;
V_30 = F_10 ( V_2 , 1 , V_36 ) ;
break;
case V_44 :
V_28 -> V_37 = & F_5 ;
break;
case V_45 :
V_28 -> V_37 = NULL ;
F_8 ( V_2 -> V_34 ) ;
V_30 = F_10 ( V_2 , 1 , V_27 -> V_46 ) ;
break;
case V_47 :
V_28 -> V_37 = NULL ;
F_8 ( V_2 -> V_34 ) ;
break;
default:
F_14 () ;
break;
}
return V_30 ;
}
static int F_16 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
F_17 ( V_2 -> V_6 -> V_21 -> V_48 ,
L_1 ) ;
return - V_49 ;
V_2 -> V_34 -> V_40 = V_50 ;
F_13 ( V_2 -> V_34 , 32 , 32 ) ;
F_1 ( V_2 , 1 , 0 ) ;
F_8 ( V_2 -> V_34 ) ;
return F_10 ( V_2 , 1 , V_36 ) ;
}
static int F_18 ( struct V_22 * V_23 )
{
struct V_26 * V_27 = & V_23 -> V_28 -> V_27 ;
struct V_1 * V_2 = V_23 -> V_25 ;
unsigned V_7 = V_2 -> V_8 ;
int V_51 = 0 ;
unsigned V_52 ;
int V_30 = 0 ;
if ( V_27 -> V_53 == V_45 ) {
V_51 = 1 ;
V_52 = V_27 -> V_54 ;
} else if ( V_27 -> V_55 == V_45 ) {
V_51 = 1 ;
V_52 = V_27 -> V_56 ;
}
if ( V_51 )
V_30 = F_19 ( V_2 , 0 , V_52 ) ;
if ( V_27 -> V_29 & V_57 ) {
F_2 ( V_2 , F_20 ( V_7 ) ,
F_21 ( V_7 ) ,
F_21 ( V_7 ) ) ;
}
return V_30 ;
}
int F_22 ( struct V_20 * V_21 , struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
struct V_38 * V_28 = V_23 -> V_28 ;
struct V_26 * V_27 = & V_28 -> V_27 ;
int V_30 = 0 ;
unsigned long V_29 ;
F_7 ( & V_2 -> V_33 , V_29 ) ;
if ( V_2 -> V_34 == NULL ) {
F_17 ( V_2 -> V_6 -> V_21 -> V_48 ,
L_2 ) ;
F_17 ( V_2 -> V_6 -> V_21 -> V_48 ,
L_3 ) ;
V_30 = - V_35 ;
} else {
V_30 = F_18 ( V_23 ) ;
if ( V_30 == 0 ) {
if ( V_27 -> V_29 & V_58 )
V_30 = F_16 ( V_23 ) ;
else
V_30 = F_11 ( V_23 ) ;
}
}
F_9 ( & V_2 -> V_33 , V_29 ) ;
return V_30 ;
}
int F_23 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
struct V_26 * V_27 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
int V_59 = 0 ;
unsigned int V_60 ;
V_60 = V_43 | V_44 | V_47 ;
if ( F_24 ( V_2 -> V_6 ) )
V_60 |= V_45 ;
V_59 |= F_25 ( & V_27 -> V_31 , V_60 ) ;
V_59 |= F_25 ( & V_27 -> V_53 ,
V_61 | V_45 | V_47 ) ;
V_59 |= F_25 ( & V_27 -> V_55 ,
V_43 | V_45 | V_47 ) ;
V_59 |= F_25 ( & V_27 -> V_62 , V_63 ) ;
V_59 |= F_25 ( & V_27 -> V_64 , V_65 ) ;
if ( V_59 )
return 1 ;
V_59 |= F_26 ( V_27 -> V_31 ) ;
V_59 |= F_26 ( V_27 -> V_53 ) ;
V_59 |= F_26 ( V_27 -> V_55 ) ;
if ( V_27 -> V_55 != V_43 && V_27 -> V_53 != V_61 )
V_59 |= - V_32 ;
if ( V_59 )
return 2 ;
switch ( V_27 -> V_31 ) {
case V_43 :
case V_44 :
case V_47 :
V_59 |= F_27 ( & V_27 -> V_46 , 0 ) ;
break;
case V_45 :
break;
}
if ( V_27 -> V_53 != V_45 )
V_59 |= F_27 ( & V_27 -> V_54 , 0 ) ;
if ( V_27 -> V_55 != V_45 )
V_59 |= F_27 ( & V_27 -> V_56 , 0 ) ;
V_59 |= F_27 ( & V_27 -> V_66 , V_27 -> V_67 ) ;
V_59 |= F_27 ( & V_27 -> V_68 , 0 ) ;
if ( V_59 )
return 3 ;
if ( V_59 )
return 4 ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 )
{
unsigned V_7 = V_2 -> V_8 ;
unsigned long V_29 ;
F_10 ( V_2 , 0 , 0 ) ;
F_7 ( & V_2 -> V_33 , V_29 ) ;
if ( V_2 -> V_34 )
F_29 ( V_2 -> V_34 ) ;
F_9 ( & V_2 -> V_33 , V_29 ) ;
F_1 ( V_2 , 0 , 0 ) ;
F_2 ( V_2 , F_20 ( V_7 ) ,
F_21 ( V_7 ) , 0x0 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
unsigned long V_29 ;
int V_30 = 0 ;
switch ( V_2 -> V_6 -> V_12 ) {
case V_14 :
case V_15 :
return 1 ;
break;
case V_13 :
F_7 ( & V_2 -> V_33 , V_29 ) ;
{
if ( V_2 -> V_34 == NULL ||
V_2 -> V_34 -> V_40 != V_41 ||
( F_31 ( V_2 -> V_34 ) ) ) {
V_30 = 1 ;
}
}
F_9 ( & V_2 -> V_33 , V_29 ) ;
break;
}
return V_30 ;
}
void F_32 ( struct V_1 * V_2 , int * V_69 ,
int * V_70 , int * V_71 ,
int * V_72 )
{
unsigned V_7 = V_2 -> V_8 ;
const unsigned short V_73 = F_33 ( V_2 ,
F_34 ( V_7 ) ) ;
const unsigned short V_74 = F_33 ( V_2 ,
F_35 ( V_7 ) ) ;
unsigned V_75 = 0 ;
if ( V_69 )
* V_69 = 0 ;
if ( V_70 )
* V_70 = 0 ;
if ( V_71 )
* V_71 = 0 ;
if ( V_72 )
* V_72 = 0 ;
if ( V_73 & F_36 ( V_7 ) ) {
V_75 |= F_37 ( V_7 ) ;
if ( V_69 ) {
if ( V_2 -> V_6 -> V_12 !=
V_15 ) {
* V_69 = 1 ;
}
}
}
if ( V_73 & F_38 ( V_7 ) ) {
V_75 |= F_39 ( V_7 ) ;
if ( V_70 )
* V_70 = 1 ;
}
if ( V_74 & V_76 )
V_75 |= V_77 ;
if ( V_74 & V_78 ) {
if ( F_30 ( V_2 ) )
V_75 |= V_79 ;
}
if ( V_75 )
F_40 ( V_2 , V_75 , F_41 ( V_7 ) ) ;
if ( F_42 ( V_2 , F_43 ( V_7 ) ) &
V_80 ) {
if ( V_73 & F_44 ( V_7 ) ) {
if ( V_72 )
* V_72 = 1 ;
}
if ( F_33 ( V_2 , F_45 ( V_7 ) ) &
F_46 ( V_7 ) ) {
F_47 ( V_2 -> V_6 -> V_21 -> V_48 ,
L_4 ,
V_81 ) ;
if ( V_71 )
* V_71 = 1 ;
}
}
}
void F_48 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
unsigned V_7 = V_2 -> V_8 ;
unsigned V_82 ;
unsigned long V_29 ;
int V_69 ;
int V_70 ;
int V_71 ;
F_32 ( V_2 , & V_69 , & V_70 ,
& V_71 , NULL ) ;
if ( V_69 ) {
F_49 ( V_2 -> V_6 -> V_21 -> V_48 ,
L_5 , V_81 ) ;
V_23 -> V_28 -> V_83 |= V_84 ;
}
if ( V_71 )
V_23 -> V_28 -> V_83 |= V_85 ;
switch ( V_2 -> V_6 -> V_12 ) {
case V_14 :
case V_15 :
if ( F_33 ( V_2 , F_50 ( V_7 ) ) &
V_86 ) {
F_49 ( V_2 -> V_6 -> V_21 -> V_48 ,
L_6 , V_81 ) ;
V_23 -> V_28 -> V_83 |= V_84 ;
}
break;
case V_13 :
break;
}
F_7 ( & V_2 -> V_33 , V_29 ) ;
if ( V_2 -> V_34 == NULL ) {
F_9 ( & V_2 -> V_33 , V_29 ) ;
return;
}
V_82 = F_51 ( V_2 -> V_34 ) ;
if ( V_82 & V_87 ) {
F_52 ( V_88 ,
V_2 -> V_34 -> V_89 -> V_90 +
F_53 ( V_2 -> V_34 -> V_91 ) ) ;
}
F_54 ( V_2 -> V_34 , V_23 ) ;
F_9 ( & V_2 -> V_33 , V_29 ) ;
}
void F_55 ( struct V_1 * V_2 ,
struct V_92 * V_34 )
{
unsigned long V_29 ;
F_7 ( & V_2 -> V_33 , V_29 ) ;
V_2 -> V_34 = V_34 ;
F_9 ( & V_2 -> V_33 , V_29 ) ;
}
static int T_1 F_56 ( void )
{
return 0 ;
}
static void T_2 F_57 ( void )
{
}
