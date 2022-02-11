static void F_1 ( struct V_1 * V_2 ,
bool V_3 , bool V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
unsigned V_7 = V_2 -> V_8 ;
unsigned V_9 ;
unsigned V_10 ;
V_9 = V_11 | V_12 ;
V_10 = 0 ;
if ( V_3 ) {
if ( V_4 )
V_10 |= V_11 ;
else
V_10 |= V_12 ;
}
F_2 ( V_2 , F_3 ( V_7 ) , V_9 , V_10 ) ;
switch ( V_6 -> V_13 ) {
case V_14 :
break;
case V_15 :
case V_16 :
V_9 = V_17 | V_18 | V_19 ;
V_10 = 0 ;
if ( V_3 )
V_10 |= V_17 | V_18 ;
if ( ! V_4 )
V_10 |= V_19 ;
F_2 ( V_2 , F_4 ( V_7 ) , V_9 , V_10 ) ;
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
if ( V_24 != V_27 -> V_31 )
return - V_32 ;
F_6 ( & V_2 -> V_33 , V_29 ) ;
if ( V_2 -> V_34 )
F_7 ( V_2 -> V_34 ) ;
else
V_30 = - V_35 ;
F_8 ( & V_2 -> V_33 , V_29 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_9 ( V_2 , 1 , V_36 ) ;
V_23 -> V_28 -> V_37 = NULL ;
return V_30 ;
}
static int F_10 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
struct V_5 * V_6 = V_2 -> V_6 ;
unsigned V_7 = V_2 -> V_8 ;
struct V_38 * V_28 = V_23 -> V_28 ;
struct V_26 * V_27 = & V_28 -> V_27 ;
int V_30 = 0 ;
F_11 ( V_23 , V_28 -> V_39 ) ;
V_2 -> V_34 -> V_40 = V_41 ;
switch ( V_6 -> V_13 ) {
case V_15 :
case V_16 :
F_12 ( V_2 -> V_34 , 32 , 32 ) ;
break;
case V_14 :
F_12 ( V_2 -> V_34 , 16 , 32 ) ;
break;
default:
F_13 () ;
break;
}
F_2 ( V_2 , F_14 ( V_7 ) , V_42 , 0 ) ;
F_1 ( V_2 , true , true ) ;
if ( V_27 -> V_31 == V_43 ) {
V_28 -> V_37 = & F_5 ;
} else {
V_28 -> V_37 = NULL ;
F_7 ( V_2 -> V_34 ) ;
if ( V_27 -> V_31 == V_44 )
V_30 = F_9 ( V_2 , 1 , V_36 ) ;
else if ( V_27 -> V_31 == V_45 )
V_30 = F_9 ( V_2 , 1 , V_27 -> V_46 ) ;
}
return V_30 ;
}
static int F_15 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
F_16 ( V_2 -> V_6 -> V_21 -> V_47 ,
L_1 ) ;
return - V_48 ;
V_2 -> V_34 -> V_40 = V_49 ;
F_12 ( V_2 -> V_34 , 32 , 32 ) ;
F_1 ( V_2 , true , false ) ;
F_7 ( V_2 -> V_34 ) ;
return F_9 ( V_2 , 1 , V_36 ) ;
}
static int F_17 ( struct V_22 * V_23 )
{
struct V_26 * V_27 = & V_23 -> V_28 -> V_27 ;
struct V_1 * V_2 = V_23 -> V_25 ;
unsigned V_7 = V_2 -> V_8 ;
int V_50 = 0 ;
unsigned V_51 ;
int V_52 = 0 ;
if ( V_27 -> V_53 == V_45 ) {
V_50 = 1 ;
V_51 = V_27 -> V_54 ;
} else if ( V_27 -> V_55 == V_45 ) {
V_50 = 1 ;
V_51 = V_27 -> V_56 ;
}
if ( V_50 )
V_52 = F_18 ( V_2 , 0 , V_51 ) ;
if ( V_27 -> V_29 & V_57 ) {
F_2 ( V_2 , F_19 ( V_7 ) ,
F_20 ( V_7 ) ,
F_20 ( V_7 ) ) ;
}
return V_52 ;
}
int F_21 ( struct V_20 * V_21 , struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
struct V_38 * V_28 = V_23 -> V_28 ;
struct V_26 * V_27 = & V_28 -> V_27 ;
int V_52 = 0 ;
unsigned long V_29 ;
F_6 ( & V_2 -> V_33 , V_29 ) ;
if ( V_2 -> V_34 == NULL ) {
F_16 ( V_2 -> V_6 -> V_21 -> V_47 ,
L_2 ) ;
F_16 ( V_2 -> V_6 -> V_21 -> V_47 ,
L_3 ) ;
V_52 = - V_35 ;
} else {
V_52 = F_17 ( V_23 ) ;
if ( V_52 == 0 ) {
if ( V_27 -> V_29 & V_58 )
V_52 = F_15 ( V_23 ) ;
else
V_52 = F_10 ( V_23 ) ;
}
}
F_8 ( & V_2 -> V_33 , V_29 ) ;
return V_52 ;
}
int F_22 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
struct V_26 * V_27 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
int V_59 = 0 ;
unsigned int V_60 ;
V_60 = V_44 | V_43 | V_61 ;
if ( F_23 ( V_2 -> V_6 ) )
V_60 |= V_45 ;
V_59 |= F_24 ( & V_27 -> V_31 , V_60 ) ;
V_59 |= F_24 ( & V_27 -> V_53 ,
V_62 | V_45 | V_61 ) ;
V_59 |= F_24 ( & V_27 -> V_55 ,
V_44 | V_45 | V_61 ) ;
V_59 |= F_24 ( & V_27 -> V_63 , V_64 ) ;
V_59 |= F_24 ( & V_27 -> V_65 , V_66 ) ;
if ( V_59 )
return 1 ;
V_59 |= F_25 ( V_27 -> V_31 ) ;
V_59 |= F_25 ( V_27 -> V_53 ) ;
V_59 |= F_25 ( V_27 -> V_55 ) ;
if ( V_27 -> V_55 != V_44 && V_27 -> V_53 != V_62 )
V_59 |= - V_32 ;
if ( V_59 )
return 2 ;
switch ( V_27 -> V_31 ) {
case V_44 :
case V_43 :
case V_61 :
V_59 |= F_26 ( & V_27 -> V_46 , 0 ) ;
break;
case V_45 :
break;
}
if ( V_27 -> V_53 != V_45 )
V_59 |= F_26 ( & V_27 -> V_54 , 0 ) ;
if ( V_27 -> V_55 != V_45 )
V_59 |= F_26 ( & V_27 -> V_56 , 0 ) ;
V_59 |= F_26 ( & V_27 -> V_67 , V_27 -> V_68 ) ;
V_59 |= F_26 ( & V_27 -> V_69 , 0 ) ;
if ( V_59 )
return 3 ;
if ( V_59 )
return 4 ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 )
{
unsigned V_7 = V_2 -> V_8 ;
unsigned long V_29 ;
F_9 ( V_2 , 0 , 0 ) ;
F_6 ( & V_2 -> V_33 , V_29 ) ;
if ( V_2 -> V_34 )
F_28 ( V_2 -> V_34 ) ;
F_8 ( & V_2 -> V_33 , V_29 ) ;
F_1 ( V_2 , false , false ) ;
F_2 ( V_2 , F_19 ( V_7 ) ,
F_20 ( V_7 ) , 0x0 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
unsigned long V_29 ;
int V_52 = 0 ;
switch ( V_2 -> V_6 -> V_13 ) {
case V_15 :
case V_16 :
return 1 ;
case V_14 :
F_6 ( & V_2 -> V_33 , V_29 ) ;
{
if ( V_2 -> V_34 == NULL ||
V_2 -> V_34 -> V_40 != V_41 ||
( F_30 ( V_2 -> V_34 ) ) ) {
V_52 = 1 ;
}
}
F_8 ( & V_2 -> V_33 , V_29 ) ;
break;
}
return V_52 ;
}
static void F_31 ( struct V_1 * V_2 ,
int * V_70 ,
int * V_71 ,
int * V_72 ,
int * V_73 )
{
unsigned V_7 = V_2 -> V_8 ;
const unsigned short V_74 = F_32 ( V_2 ,
F_33 ( V_7 ) ) ;
const unsigned short V_75 = F_32 ( V_2 ,
F_34 ( V_7 ) ) ;
unsigned V_76 = 0 ;
if ( V_70 )
* V_70 = 0 ;
if ( V_71 )
* V_71 = 0 ;
if ( V_72 )
* V_72 = 0 ;
if ( V_73 )
* V_73 = 0 ;
if ( V_74 & F_35 ( V_7 ) ) {
V_76 |= F_36 ( V_7 ) ;
if ( V_70 ) {
if ( V_2 -> V_6 -> V_13 !=
V_16 ) {
* V_70 = 1 ;
}
}
}
if ( V_74 & F_37 ( V_7 ) ) {
V_76 |= F_38 ( V_7 ) ;
if ( V_71 )
* V_71 = 1 ;
}
if ( V_75 & V_77 )
V_76 |= V_78 ;
if ( V_75 & V_79 ) {
if ( F_29 ( V_2 ) )
V_76 |= V_80 ;
}
if ( V_76 )
F_39 ( V_2 , V_76 , F_40 ( V_7 ) ) ;
if ( F_41 ( V_2 , F_42 ( V_7 ) ) &
V_81 ) {
if ( V_74 & F_43 ( V_7 ) ) {
if ( V_73 )
* V_73 = 1 ;
}
if ( F_32 ( V_2 , F_44 ( V_7 ) ) &
F_45 ( V_7 ) ) {
F_46 ( V_2 -> V_6 -> V_21 -> V_47 ,
L_4 ,
V_82 ) ;
if ( V_72 )
* V_72 = 1 ;
}
}
}
void F_47 ( struct V_1 * V_2 )
{
F_31 ( V_2 , NULL , NULL , NULL , NULL ) ;
}
void F_48 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
unsigned V_7 = V_2 -> V_8 ;
unsigned V_83 ;
unsigned long V_29 ;
int V_70 ;
int V_71 ;
int V_72 ;
F_31 ( V_2 , & V_70 , & V_71 ,
& V_72 , NULL ) ;
if ( V_70 ) {
F_49 ( V_2 -> V_6 -> V_21 -> V_47 ,
L_5 , V_82 ) ;
V_23 -> V_28 -> V_84 |= V_85 ;
}
if ( V_72 )
V_23 -> V_28 -> V_84 |= V_86 ;
switch ( V_2 -> V_6 -> V_13 ) {
case V_15 :
case V_16 :
if ( F_32 ( V_2 , F_50 ( V_7 ) ) &
V_87 ) {
F_49 ( V_2 -> V_6 -> V_21 -> V_47 ,
L_6 , V_82 ) ;
V_23 -> V_28 -> V_84 |= V_85 ;
}
break;
case V_14 :
break;
}
F_6 ( & V_2 -> V_33 , V_29 ) ;
if ( V_2 -> V_34 == NULL ) {
F_8 ( & V_2 -> V_33 , V_29 ) ;
return;
}
V_83 = F_51 ( V_2 -> V_34 ) ;
if ( V_83 & V_88 ) {
F_52 ( V_89 ,
V_2 -> V_34 -> V_90 -> V_91 +
F_53 ( V_2 -> V_34 -> V_92 ) ) ;
}
F_54 ( V_2 -> V_34 , V_23 ) ;
F_8 ( & V_2 -> V_33 , V_29 ) ;
}
void F_55 ( struct V_1 * V_2 ,
struct V_93 * V_34 )
{
unsigned long V_29 ;
F_6 ( & V_2 -> V_33 , V_29 ) ;
V_2 -> V_34 = V_34 ;
F_8 ( & V_2 -> V_33 , V_29 ) ;
}
static int T_1 F_56 ( void )
{
return 0 ;
}
static void T_2 F_57 ( void )
{
}
