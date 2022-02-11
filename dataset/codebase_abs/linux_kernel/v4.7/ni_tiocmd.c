static void F_1 ( struct V_1 * V_2 ,
bool V_3 , bool V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
unsigned int V_7 = V_2 -> V_8 ;
unsigned int V_9 ;
unsigned int V_10 ;
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
V_30 = F_9 ( V_2 , true , V_36 ) ;
V_23 -> V_28 -> V_37 = NULL ;
return V_30 ;
}
static int F_10 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
struct V_5 * V_6 = V_2 -> V_6 ;
unsigned int V_7 = V_2 -> V_8 ;
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
}
F_2 ( V_2 , F_13 ( V_7 ) , V_42 , 0 ) ;
F_1 ( V_2 , true , true ) ;
if ( V_27 -> V_43 == V_44 ) {
V_28 -> V_37 = & F_5 ;
} else {
V_28 -> V_37 = NULL ;
F_7 ( V_2 -> V_34 ) ;
if ( V_27 -> V_43 == V_45 )
V_30 = F_9 ( V_2 , true , V_36 ) ;
else if ( V_27 -> V_43 == V_46 )
V_30 = F_9 ( V_2 , true , V_27 -> V_31 ) ;
}
return V_30 ;
}
static int F_14 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
F_15 ( V_2 -> V_6 -> V_21 -> V_47 ,
L_1 ) ;
return - V_48 ;
}
static int F_16 ( struct V_22 * V_23 )
{
struct V_26 * V_27 = & V_23 -> V_28 -> V_27 ;
struct V_1 * V_2 = V_23 -> V_25 ;
unsigned int V_7 = V_2 -> V_8 ;
int V_49 = 0 ;
unsigned int V_50 ;
int V_51 = 0 ;
if ( V_27 -> V_52 == V_46 ) {
V_49 = 1 ;
V_50 = V_27 -> V_53 ;
} else if ( V_27 -> V_54 == V_46 ) {
V_49 = 1 ;
V_50 = V_27 -> V_55 ;
}
if ( V_49 )
V_51 = F_17 ( V_2 , 0 , V_50 ) ;
if ( V_27 -> V_29 & V_56 ) {
F_2 ( V_2 , F_18 ( V_7 ) ,
F_19 ( V_7 ) ,
F_19 ( V_7 ) ) ;
}
return V_51 ;
}
int F_20 ( struct V_20 * V_21 , struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
struct V_38 * V_28 = V_23 -> V_28 ;
struct V_26 * V_27 = & V_28 -> V_27 ;
int V_51 = 0 ;
unsigned long V_29 ;
F_6 ( & V_2 -> V_33 , V_29 ) ;
if ( ! V_2 -> V_34 ) {
F_15 ( V_2 -> V_6 -> V_21 -> V_47 ,
L_2 ) ;
F_15 ( V_2 -> V_6 -> V_21 -> V_47 ,
L_3 ) ;
V_51 = - V_35 ;
} else {
V_51 = F_16 ( V_23 ) ;
if ( V_51 == 0 ) {
if ( V_27 -> V_29 & V_57 )
V_51 = F_14 ( V_23 ) ;
else
V_51 = F_10 ( V_23 ) ;
}
}
F_8 ( & V_2 -> V_33 , V_29 ) ;
return V_51 ;
}
int F_21 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
struct V_26 * V_27 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
int V_58 = 0 ;
unsigned int V_59 ;
V_59 = V_45 | V_44 | V_60 ;
if ( F_22 ( V_2 -> V_6 ) )
V_59 |= V_46 ;
V_58 |= F_23 ( & V_27 -> V_43 , V_59 ) ;
V_58 |= F_23 ( & V_27 -> V_52 ,
V_61 | V_46 | V_60 ) ;
V_58 |= F_23 ( & V_27 -> V_54 ,
V_45 | V_46 | V_60 ) ;
V_58 |= F_23 ( & V_27 -> V_62 , V_63 ) ;
V_58 |= F_23 ( & V_27 -> V_64 , V_65 ) ;
if ( V_58 )
return 1 ;
V_58 |= F_24 ( V_27 -> V_43 ) ;
V_58 |= F_24 ( V_27 -> V_52 ) ;
V_58 |= F_24 ( V_27 -> V_54 ) ;
if ( V_27 -> V_54 != V_45 && V_27 -> V_52 != V_61 )
V_58 |= - V_32 ;
if ( V_58 )
return 2 ;
switch ( V_27 -> V_43 ) {
case V_45 :
case V_44 :
case V_60 :
V_58 |= F_25 ( & V_27 -> V_31 , 0 ) ;
break;
case V_46 :
break;
}
if ( V_27 -> V_52 != V_46 )
V_58 |= F_25 ( & V_27 -> V_53 , 0 ) ;
if ( V_27 -> V_54 != V_46 )
V_58 |= F_25 ( & V_27 -> V_55 , 0 ) ;
V_58 |= F_25 ( & V_27 -> V_66 ,
V_27 -> V_67 ) ;
V_58 |= F_25 ( & V_27 -> V_68 , 0 ) ;
if ( V_58 )
return 3 ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 )
{
unsigned int V_7 = V_2 -> V_8 ;
unsigned long V_29 ;
F_9 ( V_2 , false , 0 ) ;
F_6 ( & V_2 -> V_33 , V_29 ) ;
if ( V_2 -> V_34 )
F_27 ( V_2 -> V_34 ) ;
F_8 ( & V_2 -> V_33 , V_29 ) ;
F_1 ( V_2 , false , false ) ;
F_2 ( V_2 , F_18 ( V_7 ) ,
F_19 ( V_7 ) , 0x0 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
unsigned long V_29 ;
int V_51 = 0 ;
switch ( V_2 -> V_6 -> V_13 ) {
case V_15 :
case V_16 :
return 1 ;
case V_14 :
F_6 ( & V_2 -> V_33 , V_29 ) ;
{
if ( ! V_2 -> V_34 ||
V_2 -> V_34 -> V_40 != V_41 ||
( F_29 ( V_2 -> V_34 ) ) ) {
V_51 = 1 ;
}
}
F_8 ( & V_2 -> V_33 , V_29 ) ;
break;
}
return V_51 ;
}
static void F_30 ( struct V_1 * V_2 ,
int * V_69 ,
int * V_70 ,
int * V_71 )
{
unsigned int V_7 = V_2 -> V_8 ;
const unsigned short V_72 = F_31 ( V_2 ,
F_32 ( V_7 ) ) ;
const unsigned short V_73 = F_31 ( V_2 ,
F_33 ( V_7 ) ) ;
unsigned int V_74 = 0 ;
if ( V_69 )
* V_69 = 0 ;
if ( V_70 )
* V_70 = 0 ;
if ( V_71 )
* V_71 = 0 ;
if ( V_72 & F_34 ( V_7 ) ) {
V_74 |= F_35 ( V_7 ) ;
if ( V_69 ) {
if ( V_2 -> V_6 -> V_13 !=
V_16 )
* V_69 = 1 ;
}
}
if ( V_72 & F_36 ( V_7 ) ) {
V_74 |= F_37 ( V_7 ) ;
if ( V_70 )
* V_70 = 1 ;
}
if ( V_73 & V_75 )
V_74 |= V_76 ;
if ( V_73 & V_77 ) {
if ( F_28 ( V_2 ) )
V_74 |= V_78 ;
}
if ( V_74 )
F_38 ( V_2 , V_74 , F_39 ( V_7 ) ) ;
if ( F_40 ( V_2 , F_41 ( V_7 ) ) &
V_79 ) {
if ( F_31 ( V_2 , F_42 ( V_7 ) ) &
F_43 ( V_7 ) ) {
F_44 ( V_2 -> V_6 -> V_21 -> V_47 ,
L_4 ,
V_80 ) ;
if ( V_71 )
* V_71 = 1 ;
}
}
}
void F_45 ( struct V_1 * V_2 )
{
F_30 ( V_2 , NULL , NULL , NULL ) ;
}
void F_46 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
unsigned int V_7 = V_2 -> V_8 ;
unsigned long V_29 ;
int V_69 ;
int V_70 ;
int V_71 ;
F_30 ( V_2 , & V_69 , & V_70 ,
& V_71 ) ;
if ( V_69 ) {
F_47 ( V_2 -> V_6 -> V_21 -> V_47 ,
L_5 , V_80 ) ;
V_23 -> V_28 -> V_81 |= V_82 ;
}
if ( V_71 )
V_23 -> V_28 -> V_81 |= V_83 ;
switch ( V_2 -> V_6 -> V_13 ) {
case V_15 :
case V_16 :
if ( F_31 ( V_2 , F_48 ( V_7 ) ) &
V_84 ) {
F_47 ( V_2 -> V_6 -> V_21 -> V_47 ,
L_6 , V_80 ) ;
V_23 -> V_28 -> V_81 |= V_82 ;
}
break;
case V_14 :
break;
}
F_6 ( & V_2 -> V_33 , V_29 ) ;
if ( V_2 -> V_34 )
F_49 ( V_2 -> V_34 , V_23 , true ) ;
F_8 ( & V_2 -> V_33 , V_29 ) ;
}
void F_50 ( struct V_1 * V_2 ,
struct V_85 * V_34 )
{
unsigned long V_29 ;
F_6 ( & V_2 -> V_33 , V_29 ) ;
V_2 -> V_34 = V_34 ;
F_8 ( & V_2 -> V_33 , V_29 ) ;
}
static int T_1 F_51 ( void )
{
return 0 ;
}
static void T_2 F_52 ( void )
{
}
