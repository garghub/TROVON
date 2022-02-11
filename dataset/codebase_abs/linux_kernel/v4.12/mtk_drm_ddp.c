static unsigned int F_1 ( enum V_1 V_2 ,
enum V_1 V_3 ,
unsigned int * V_4 )
{
unsigned int V_5 ;
if ( V_2 == V_6 && V_3 == V_7 ) {
* V_4 = V_8 ;
V_5 = V_9 ;
} else if ( V_2 == V_6 && V_3 == V_10 ) {
* V_4 = V_11 ;
V_5 = V_12 ;
} else if ( V_2 == V_13 && V_3 == V_10 ) {
* V_4 = V_14 ;
V_5 = V_15 ;
} else if ( V_2 == V_16 && V_3 == V_17 ) {
* V_4 = V_18 ;
V_5 = V_19 ;
} else if ( V_2 == V_20 && V_3 == V_21 ) {
* V_4 = V_22 ;
V_5 = V_23 ;
} else if ( V_2 == V_24 && V_3 == V_25 ) {
* V_4 = V_26 ;
V_5 = V_27 ;
} else if ( V_2 == V_25 && V_3 == V_28 ) {
* V_4 = V_29 ;
V_5 = V_30 ;
} else {
V_5 = 0 ;
}
return V_5 ;
}
static unsigned int F_2 ( enum V_1 V_2 ,
enum V_1 V_3 ,
unsigned int * V_4 )
{
unsigned int V_5 ;
if ( V_2 == V_6 && V_3 == V_7 ) {
* V_4 = V_31 ;
V_5 = V_32 ;
} else if ( V_2 == V_25 && V_3 == V_28 ) {
* V_4 = V_33 ;
V_5 = V_34 ;
} else if ( V_2 == V_20 && V_3 == V_21 ) {
* V_4 = V_35 ;
V_5 = V_36 ;
} else if ( V_2 == V_37 && V_3 == V_17 ) {
* V_4 = V_38 ;
V_5 = V_39 ;
} else {
V_5 = 0 ;
}
return V_5 ;
}
static void F_3 ( void T_1 * V_40 ,
enum V_1 V_2 ,
enum V_1 V_3 )
{
if ( V_2 == V_37 && V_3 == V_17 )
F_4 ( V_41 ,
V_40 + V_42 ) ;
}
void F_5 ( void T_1 * V_40 ,
enum V_1 V_2 ,
enum V_1 V_3 )
{
unsigned int V_4 , V_5 , V_43 ;
V_5 = F_1 ( V_2 , V_3 , & V_4 ) ;
if ( V_5 ) {
V_43 = F_6 ( V_40 + V_4 ) | V_5 ;
F_4 ( V_43 , V_40 + V_4 ) ;
}
F_3 ( V_40 , V_2 , V_3 ) ;
V_5 = F_2 ( V_2 , V_3 , & V_4 ) ;
if ( V_5 ) {
V_43 = F_6 ( V_40 + V_4 ) | V_5 ;
F_4 ( V_43 , V_40 + V_4 ) ;
}
}
void F_7 ( void T_1 * V_40 ,
enum V_1 V_2 ,
enum V_1 V_3 )
{
unsigned int V_4 , V_5 , V_43 ;
V_5 = F_1 ( V_2 , V_3 , & V_4 ) ;
if ( V_5 ) {
V_43 = F_6 ( V_40 + V_4 ) & ~ V_5 ;
F_4 ( V_43 , V_40 + V_4 ) ;
}
V_5 = F_2 ( V_2 , V_3 , & V_4 ) ;
if ( V_5 ) {
V_43 = F_6 ( V_40 + V_4 ) & ~ V_5 ;
F_4 ( V_43 , V_40 + V_4 ) ;
}
}
struct V_44 * F_8 ( struct V_45 * V_46 , unsigned int V_47 )
{
struct V_48 * V_49 = F_9 ( V_46 ) ;
if ( V_47 >= 10 )
return F_10 ( - V_50 ) ;
if ( V_49 -> V_51 [ V_47 ] . V_52 )
return F_10 ( - V_53 ) ;
V_49 -> V_51 [ V_47 ] . V_52 = true ;
return & V_49 -> V_51 [ V_47 ] ;
}
void F_11 ( struct V_44 * V_51 )
{
struct V_48 * V_49 = F_12 ( V_51 , struct V_48 ,
V_51 [ V_51 -> V_47 ] ) ;
F_13 ( & V_49 -> V_51 [ V_51 -> V_47 ] != V_51 ) ;
V_51 -> V_52 = false ;
}
int F_14 ( struct V_44 * V_51 )
{
struct V_48 * V_49 = F_12 ( V_51 , struct V_48 ,
V_51 [ V_51 -> V_47 ] ) ;
return F_15 ( V_49 -> V_54 ) ;
}
void F_16 ( struct V_44 * V_51 )
{
struct V_48 * V_49 = F_12 ( V_51 , struct V_48 ,
V_51 [ V_51 -> V_47 ] ) ;
F_17 ( V_49 -> V_54 ) ;
}
void F_18 ( struct V_44 * V_51 ,
enum V_1 V_47 )
{
struct V_48 * V_49 = F_12 ( V_51 , struct V_48 ,
V_51 [ V_51 -> V_47 ] ) ;
unsigned int V_43 ;
F_13 ( & V_49 -> V_51 [ V_51 -> V_47 ] != V_51 ) ;
switch ( V_47 ) {
case V_17 :
V_43 = V_55 ;
break;
case V_56 :
V_43 = V_55 ;
break;
case V_28 :
V_43 = V_57 ;
break;
default:
V_43 = F_6 ( V_49 -> V_58 + F_19 ( V_51 -> V_47 ) ) ;
V_43 |= V_49 -> V_59 [ V_47 ] ;
F_4 ( V_43 , V_49 -> V_58 + F_19 ( V_51 -> V_47 ) ) ;
return;
}
F_4 ( V_43 , V_49 -> V_58 + F_20 ( V_51 -> V_47 ) ) ;
}
void F_21 ( struct V_44 * V_51 ,
enum V_1 V_47 )
{
struct V_48 * V_49 = F_12 ( V_51 , struct V_48 ,
V_51 [ V_51 -> V_47 ] ) ;
unsigned int V_43 ;
F_13 ( & V_49 -> V_51 [ V_51 -> V_47 ] != V_51 ) ;
switch ( V_47 ) {
case V_17 :
case V_56 :
case V_28 :
F_4 ( V_60 ,
V_49 -> V_58 + F_20 ( V_51 -> V_47 ) ) ;
break;
default:
V_43 = F_6 ( V_49 -> V_58 + F_19 ( V_51 -> V_47 ) ) ;
V_43 &= ~ ( V_49 -> V_59 [ V_47 ] ) ;
F_4 ( V_43 , V_49 -> V_58 + F_19 ( V_51 -> V_47 ) ) ;
break;
}
}
void F_22 ( struct V_44 * V_51 )
{
struct V_48 * V_49 = F_12 ( V_51 , struct V_48 ,
V_51 [ V_51 -> V_47 ] ) ;
F_13 ( & V_49 -> V_51 [ V_51 -> V_47 ] != V_51 ) ;
F_23 ( 1 , V_49 -> V_58 + F_24 ( V_51 -> V_47 ) ) ;
}
void F_25 ( struct V_44 * V_51 )
{
struct V_48 * V_49 = F_12 ( V_51 , struct V_48 ,
V_51 [ V_51 -> V_47 ] ) ;
F_13 ( & V_49 -> V_51 [ V_51 -> V_47 ] != V_51 ) ;
F_23 ( 0 , V_49 -> V_58 + F_24 ( V_51 -> V_47 ) ) ;
}
void F_26 ( struct V_44 * V_51 )
{
struct V_48 * V_49 = F_12 ( V_51 , struct V_48 ,
V_51 [ V_51 -> V_47 ] ) ;
T_2 V_61 ;
F_23 ( 1 , V_49 -> V_58 + F_24 ( V_51 -> V_47 ) ) ;
F_23 ( 1 , V_49 -> V_58 + F_27 ( V_51 -> V_47 ) ) ;
if ( F_28 ( V_49 -> V_58 + F_27 ( V_51 -> V_47 ) ,
V_61 , V_61 & V_62 , 1 , 10000 ) )
F_29 ( L_1 , V_51 -> V_47 ) ;
}
void F_30 ( struct V_44 * V_51 )
{
struct V_48 * V_49 = F_12 ( V_51 , struct V_48 ,
V_51 [ V_51 -> V_47 ] ) ;
F_23 ( 0 , V_49 -> V_58 + F_27 ( V_51 -> V_47 ) ) ;
}
static int F_31 ( struct V_63 * V_64 )
{
struct V_45 * V_46 = & V_64 -> V_46 ;
struct V_48 * V_49 ;
struct V_65 * V_58 ;
int V_66 ;
V_49 = F_32 ( V_46 , sizeof( * V_49 ) , V_67 ) ;
if ( ! V_49 )
return - V_68 ;
for ( V_66 = 0 ; V_66 < 10 ; V_66 ++ )
V_49 -> V_51 [ V_66 ] . V_47 = V_66 ;
V_49 -> V_54 = F_33 ( V_46 , NULL ) ;
if ( F_34 ( V_49 -> V_54 ) ) {
F_35 ( V_46 , L_2 ) ;
return F_36 ( V_49 -> V_54 ) ;
}
V_58 = F_37 ( V_64 , V_69 , 0 ) ;
V_49 -> V_58 = F_38 ( V_46 , V_58 ) ;
if ( F_34 ( V_49 -> V_58 ) ) {
F_35 ( V_46 , L_3 ) ;
return F_36 ( V_49 -> V_58 ) ;
}
V_49 -> V_59 = F_39 ( V_46 ) ;
F_40 ( V_64 , V_49 ) ;
return 0 ;
}
static int F_41 ( struct V_63 * V_64 )
{
return 0 ;
}
