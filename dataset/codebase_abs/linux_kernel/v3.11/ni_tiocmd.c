static void F_1 ( struct V_1 * V_2 , short V_3 ,
short V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
unsigned V_7 = 0 ;
if ( V_3 ) {
if ( V_4 )
V_7 |= V_8 ;
else
V_7 |= V_9 ;
}
F_2 ( V_2 ,
F_3 ( V_2 -> V_10 ) ,
V_8 | V_9 ,
V_7 ) ;
switch ( V_6 -> V_11 ) {
case V_12 :
break;
case V_13 :
case V_14 :
{
unsigned V_15 = 0 ;
if ( V_3 ) {
V_15 |= V_16 ;
V_15 |= V_17 ;
}
if ( V_4 == 0 )
V_15 |= V_18 ;
F_2 ( V_2 ,
F_4 ( V_2 ->
V_10 ) ,
V_16 | V_17 |
V_18 , V_15 ) ;
}
break;
}
}
static int F_5 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
unsigned int V_23 )
{
unsigned long V_24 ;
int V_25 = 0 ;
struct V_1 * V_2 = V_22 -> V_26 ;
F_6 ( V_2 == NULL ) ;
if ( V_23 != 0 )
return - V_27 ;
F_7 ( & V_2 -> V_28 , V_24 ) ;
if ( V_2 -> V_29 )
F_8 ( V_2 -> V_29 ) ;
else
V_25 = - V_30 ;
F_9 ( & V_2 -> V_28 , V_24 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_10 ( V_2 , 1 , V_31 ) ;
V_22 -> V_32 -> V_33 = NULL ;
return V_25 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_34 * V_32 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_35 * V_36 = & V_32 -> V_36 ;
int V_25 = 0 ;
F_12 ( V_32 , V_32 -> V_37 ) ;
V_2 -> V_29 -> V_38 = V_39 ;
switch ( V_6 -> V_11 ) {
case V_13 :
case V_14 :
F_13 ( V_2 -> V_29 , 32 , 32 ) ;
break;
case V_12 :
F_13 ( V_2 -> V_29 , 16 , 32 ) ;
break;
default:
F_14 () ;
break;
}
F_2 ( V_2 , F_15 ( V_2 -> V_10 ) ,
V_40 , 0 ) ;
F_1 ( V_2 , 1 , 1 ) ;
switch ( V_36 -> V_41 ) {
case V_42 :
V_32 -> V_33 = NULL ;
F_8 ( V_2 -> V_29 ) ;
V_25 = F_10 ( V_2 , 1 , V_31 ) ;
break;
case V_43 :
V_32 -> V_33 = & F_5 ;
break;
case V_44 :
V_32 -> V_33 = NULL ;
F_8 ( V_2 -> V_29 ) ;
V_25 = F_10 ( V_2 , 1 , V_36 -> V_45 ) ;
break;
case V_46 :
V_32 -> V_33 = NULL ;
F_8 ( V_2 -> V_29 ) ;
break;
default:
F_14 () ;
break;
}
return V_25 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_34 * V_32 )
{
F_17 ( V_2 -> V_6 -> V_20 -> V_47 ,
L_1 ) ;
return - V_48 ;
V_2 -> V_29 -> V_38 = V_49 ;
F_13 ( V_2 -> V_29 , 32 , 32 ) ;
F_1 ( V_2 , 1 , 0 ) ;
F_8 ( V_2 -> V_29 ) ;
return F_10 ( V_2 , 1 , V_31 ) ;
}
static int F_18 ( struct V_1 * V_2 , struct V_34 * V_32 )
{
struct V_35 * V_36 = & V_32 -> V_36 ;
int V_50 = 0 ;
unsigned V_51 ;
int V_25 = 0 ;
if ( V_36 -> V_52 == V_44 ) {
V_50 = 1 ;
V_51 = V_36 -> V_53 ;
} else if ( V_36 -> V_54 == V_44 ) {
V_50 = 1 ;
V_51 = V_36 -> V_55 ;
}
if ( V_50 )
V_25 = F_19 ( V_2 , 0 , V_51 ) ;
if ( V_36 -> V_24 & V_56 ) {
F_2 ( V_2 ,
F_20 ( V_2 ->
V_10 ) ,
F_21 ( V_2 ->
V_10 ) ,
F_21 ( V_2 ->
V_10 ) ) ;
}
return V_25 ;
}
int F_22 ( struct V_1 * V_2 , struct V_34 * V_32 )
{
struct V_35 * V_36 = & V_32 -> V_36 ;
int V_25 = 0 ;
unsigned long V_24 ;
F_7 ( & V_2 -> V_28 , V_24 ) ;
if ( V_2 -> V_29 == NULL ) {
F_17 ( V_2 -> V_6 -> V_20 -> V_47 ,
L_2 ) ;
F_17 ( V_2 -> V_6 -> V_20 -> V_47 ,
L_3 ) ;
V_25 = - V_30 ;
} else {
V_25 = F_18 ( V_2 , V_32 ) ;
if ( V_25 == 0 ) {
if ( V_36 -> V_24 & V_57 )
V_25 = F_16 ( V_2 , V_32 ) ;
else
V_25 = F_11 ( V_2 , V_32 ) ;
}
}
F_9 ( & V_2 -> V_28 , V_24 ) ;
return V_25 ;
}
int F_23 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
int V_58 = 0 ;
unsigned int V_59 ;
V_59 = V_42 | V_43 | V_46 ;
if ( F_24 ( V_2 -> V_6 ) )
V_59 |= V_44 ;
V_58 |= F_25 ( & V_36 -> V_41 , V_59 ) ;
V_58 |= F_25 ( & V_36 -> V_52 ,
V_60 | V_44 | V_46 ) ;
V_58 |= F_25 ( & V_36 -> V_54 ,
V_42 | V_44 | V_46 ) ;
V_58 |= F_25 ( & V_36 -> V_61 , V_62 ) ;
V_58 |= F_25 ( & V_36 -> V_63 , V_64 ) ;
if ( V_58 )
return 1 ;
V_58 |= F_26 ( V_36 -> V_41 ) ;
V_58 |= F_26 ( V_36 -> V_52 ) ;
V_58 |= F_26 ( V_36 -> V_54 ) ;
if ( V_36 -> V_54 != V_42 && V_36 -> V_52 != V_60 )
V_58 |= - V_27 ;
if ( V_58 )
return 2 ;
if ( V_36 -> V_41 != V_44 )
V_58 |= F_27 ( & V_36 -> V_45 , 0 ) ;
if ( V_36 -> V_52 != V_44 )
V_58 |= F_27 ( & V_36 -> V_53 , 0 ) ;
if ( V_36 -> V_54 != V_44 )
V_58 |= F_27 ( & V_36 -> V_55 , 0 ) ;
V_58 |= F_27 ( & V_36 -> V_65 , V_36 -> V_66 ) ;
V_58 |= F_27 ( & V_36 -> V_67 , 0 ) ;
if ( V_58 )
return 3 ;
if ( V_58 )
return 4 ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 )
{
unsigned long V_24 ;
F_10 ( V_2 , 0 , 0 ) ;
F_7 ( & V_2 -> V_28 , V_24 ) ;
if ( V_2 -> V_29 )
F_29 ( V_2 -> V_29 ) ;
F_9 ( & V_2 -> V_28 , V_24 ) ;
F_1 ( V_2 , 0 , 0 ) ;
F_2 ( V_2 ,
F_20 ( V_2 -> V_10 ) ,
F_21 ( V_2 -> V_10 ) ,
0x0 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
unsigned long V_24 ;
int V_25 = 0 ;
switch ( V_2 -> V_6 -> V_11 ) {
case V_13 :
case V_14 :
return 1 ;
break;
case V_12 :
F_7 ( & V_2 -> V_28 , V_24 ) ;
{
if ( V_2 -> V_29 == NULL ||
V_2 -> V_29 -> V_38 != V_39 ||
( F_31 ( V_2 -> V_29 ) ) ) {
V_25 = 1 ;
}
}
F_9 ( & V_2 -> V_28 , V_24 ) ;
break;
}
return V_25 ;
}
void F_32 ( struct V_1 * V_2 , int * V_68 ,
int * V_69 , int * V_70 ,
int * V_71 )
{
const unsigned short V_72 = F_33 ( V_2 ,
F_34
( V_2 ->
V_10 ) ) ;
const unsigned short V_73 = F_33 ( V_2 ,
F_35
( V_2 ->
V_10 ) ) ;
unsigned V_74 = 0 ;
if ( V_68 )
* V_68 = 0 ;
if ( V_69 )
* V_69 = 0 ;
if ( V_70 )
* V_70 = 0 ;
if ( V_71 )
* V_71 = 0 ;
if ( V_72 & F_36 ( V_2 -> V_10 ) ) {
V_74 |= F_37 ( V_2 -> V_10 ) ;
if ( V_68 ) {
if ( V_2 -> V_6 -> V_11 !=
V_14 ) {
* V_68 = 1 ;
}
}
}
if ( V_72 & F_38 ( V_2 -> V_10 ) ) {
V_74 |= F_39 ( V_2 -> V_10 ) ;
if ( V_69 )
* V_69 = 1 ;
}
if ( V_73 & V_75 )
V_74 |= V_76 ;
if ( V_73 & V_77 ) {
if ( F_30 ( V_2 ) )
V_74 |= V_78 ;
}
if ( V_74 )
F_40 ( V_2 , V_74 ,
F_41
( V_2 -> V_10 ) ) ;
if ( F_42
( V_2 ,
F_43 ( V_2 -> V_10 ) ) &
V_79 ) {
if ( V_72 & F_44 ( V_2 -> V_10 ) ) {
if ( V_71 )
* V_71 = 1 ;
}
if ( F_33 ( V_2 ,
F_45
( V_2 -> V_10 ) ) &
F_46 ( V_2 -> V_10 ) ) {
F_47 ( V_2 -> V_6 -> V_20 -> V_47 ,
L_4 ,
V_80 ) ;
if ( V_70 )
* V_70 = 1 ;
}
}
}
void F_48 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
unsigned V_81 ;
unsigned long V_24 ;
int V_68 ;
int V_69 ;
int V_70 ;
F_32 ( V_2 , & V_68 , & V_69 ,
& V_70 , NULL ) ;
if ( V_68 ) {
F_49 ( V_2 -> V_6 -> V_20 -> V_47 ,
L_5 , V_80 ) ;
V_22 -> V_32 -> V_82 |= V_83 ;
}
if ( V_70 )
V_22 -> V_32 -> V_82 |= V_84 ;
switch ( V_2 -> V_6 -> V_11 ) {
case V_13 :
case V_14 :
if ( F_33 ( V_2 ,
F_50
( V_2 -> V_10 ) ) & V_85 ) {
F_49 ( V_2 -> V_6 -> V_20 -> V_47 ,
L_6 , V_80 ) ;
V_22 -> V_32 -> V_82 |= V_83 ;
}
break;
case V_12 :
break;
}
F_7 ( & V_2 -> V_28 , V_24 ) ;
if ( V_2 -> V_29 == NULL ) {
F_9 ( & V_2 -> V_28 , V_24 ) ;
return;
}
V_81 = F_51 ( V_2 -> V_29 ) ;
if ( V_81 & V_86 ) {
F_52 ( V_87 ,
V_2 -> V_29 -> V_88 -> V_89 +
F_53 ( V_2 -> V_29 -> V_90 ) ) ;
}
F_54 ( V_2 -> V_29 , V_22 -> V_32 ) ;
F_9 ( & V_2 -> V_28 , V_24 ) ;
}
void F_55 ( struct V_1 * V_2 ,
struct V_91 * V_29 )
{
unsigned long V_24 ;
F_7 ( & V_2 -> V_28 , V_24 ) ;
V_2 -> V_29 = V_29 ;
F_9 ( & V_2 -> V_28 , V_24 ) ;
}
static int T_1 F_56 ( void )
{
return 0 ;
}
static void T_2 F_57 ( void )
{
}
