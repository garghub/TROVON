static unsigned int F_1 ( enum V_1 V_2 ,
enum V_1 V_3 ,
unsigned int * V_4 )
{
unsigned int V_5 ;
if ( V_2 == V_6 && V_3 == V_7 ) {
* V_4 = V_8 ;
V_5 = V_9 ;
} else if ( V_2 == V_10 && V_3 == V_11 ) {
* V_4 = V_12 ;
V_5 = V_13 ;
} else if ( V_2 == V_14 && V_3 == V_15 ) {
* V_4 = V_16 ;
V_5 = V_17 ;
} else if ( V_2 == V_18 && V_3 == V_19 ) {
* V_4 = V_20 ;
V_5 = V_21 ;
} else if ( V_2 == V_22 && V_3 == V_23 ) {
* V_4 = V_24 ;
V_5 = V_25 ;
} else if ( V_2 == V_23 && V_3 == V_26 ) {
* V_4 = V_27 ;
V_5 = V_28 ;
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
* V_4 = V_29 ;
V_5 = V_30 ;
} else if ( V_2 == V_23 && V_3 == V_26 ) {
* V_4 = V_31 ;
V_5 = V_32 ;
} else if ( V_2 == V_18 && V_3 == V_19 ) {
* V_4 = V_33 ;
V_5 = V_34 ;
} else {
V_5 = 0 ;
}
return V_5 ;
}
void F_3 ( void T_1 * V_35 ,
enum V_1 V_2 ,
enum V_1 V_3 )
{
unsigned int V_4 , V_5 , V_36 ;
V_5 = F_1 ( V_2 , V_3 , & V_4 ) ;
if ( V_5 ) {
V_36 = F_4 ( V_35 + V_4 ) | V_5 ;
F_5 ( V_36 , V_35 + V_4 ) ;
}
V_5 = F_2 ( V_2 , V_3 , & V_4 ) ;
if ( V_5 ) {
V_36 = F_4 ( V_35 + V_4 ) | V_5 ;
F_5 ( V_36 , V_35 + V_4 ) ;
}
}
void F_6 ( void T_1 * V_35 ,
enum V_1 V_2 ,
enum V_1 V_3 )
{
unsigned int V_4 , V_5 , V_36 ;
V_5 = F_1 ( V_2 , V_3 , & V_4 ) ;
if ( V_5 ) {
V_36 = F_4 ( V_35 + V_4 ) & ~ V_5 ;
F_5 ( V_36 , V_35 + V_4 ) ;
}
V_5 = F_2 ( V_2 , V_3 , & V_4 ) ;
if ( V_5 ) {
V_36 = F_4 ( V_35 + V_4 ) & ~ V_5 ;
F_5 ( V_36 , V_35 + V_4 ) ;
}
}
struct V_37 * F_7 ( struct V_38 * V_39 , unsigned int V_40 )
{
struct V_41 * V_42 = F_8 ( V_39 ) ;
if ( V_40 >= 10 )
return F_9 ( - V_43 ) ;
if ( V_42 -> V_44 [ V_40 ] . V_45 )
return F_9 ( - V_46 ) ;
V_42 -> V_44 [ V_40 ] . V_45 = true ;
return & V_42 -> V_44 [ V_40 ] ;
}
void F_10 ( struct V_37 * V_44 )
{
struct V_41 * V_42 = F_11 ( V_44 , struct V_41 ,
V_44 [ V_44 -> V_40 ] ) ;
F_12 ( & V_42 -> V_44 [ V_44 -> V_40 ] != V_44 ) ;
V_44 -> V_45 = false ;
}
int F_13 ( struct V_37 * V_44 )
{
struct V_41 * V_42 = F_11 ( V_44 , struct V_41 ,
V_44 [ V_44 -> V_40 ] ) ;
return F_14 ( V_42 -> V_47 ) ;
}
void F_15 ( struct V_37 * V_44 )
{
struct V_41 * V_42 = F_11 ( V_44 , struct V_41 ,
V_44 [ V_44 -> V_40 ] ) ;
F_16 ( V_42 -> V_47 ) ;
}
void F_17 ( struct V_37 * V_44 ,
enum V_1 V_40 )
{
struct V_41 * V_42 = F_11 ( V_44 , struct V_41 ,
V_44 [ V_44 -> V_40 ] ) ;
unsigned int V_36 ;
F_12 ( & V_42 -> V_44 [ V_44 -> V_40 ] != V_44 ) ;
switch ( V_40 ) {
case V_15 :
V_36 = V_48 ;
break;
case V_49 :
V_36 = V_48 ;
break;
case V_26 :
V_36 = V_50 ;
break;
default:
V_36 = F_4 ( V_42 -> V_51 + F_18 ( V_44 -> V_40 ) ) ;
V_36 |= V_52 [ V_40 ] ;
F_5 ( V_36 , V_42 -> V_51 + F_18 ( V_44 -> V_40 ) ) ;
return;
}
F_5 ( V_36 , V_42 -> V_51 + F_19 ( V_44 -> V_40 ) ) ;
}
void F_20 ( struct V_37 * V_44 ,
enum V_1 V_40 )
{
struct V_41 * V_42 = F_11 ( V_44 , struct V_41 ,
V_44 [ V_44 -> V_40 ] ) ;
unsigned int V_36 ;
F_12 ( & V_42 -> V_44 [ V_44 -> V_40 ] != V_44 ) ;
switch ( V_40 ) {
case V_15 :
case V_49 :
case V_26 :
F_5 ( V_53 ,
V_42 -> V_51 + F_19 ( V_44 -> V_40 ) ) ;
break;
default:
V_36 = F_4 ( V_42 -> V_51 + F_18 ( V_44 -> V_40 ) ) ;
V_36 &= ~ V_52 [ V_40 ] ;
F_5 ( V_36 , V_42 -> V_51 + F_18 ( V_44 -> V_40 ) ) ;
break;
}
}
void F_21 ( struct V_37 * V_44 )
{
struct V_41 * V_42 = F_11 ( V_44 , struct V_41 ,
V_44 [ V_44 -> V_40 ] ) ;
F_12 ( & V_42 -> V_44 [ V_44 -> V_40 ] != V_44 ) ;
F_22 ( 1 , V_42 -> V_51 + F_23 ( V_44 -> V_40 ) ) ;
}
void F_24 ( struct V_37 * V_44 )
{
struct V_41 * V_42 = F_11 ( V_44 , struct V_41 ,
V_44 [ V_44 -> V_40 ] ) ;
F_12 ( & V_42 -> V_44 [ V_44 -> V_40 ] != V_44 ) ;
F_22 ( 0 , V_42 -> V_51 + F_23 ( V_44 -> V_40 ) ) ;
}
static int F_25 ( struct V_54 * V_55 )
{
struct V_38 * V_39 = & V_55 -> V_39 ;
struct V_41 * V_42 ;
struct V_56 * V_51 ;
int V_57 ;
V_42 = F_26 ( V_39 , sizeof( * V_42 ) , V_58 ) ;
if ( ! V_42 )
return - V_59 ;
for ( V_57 = 0 ; V_57 < 10 ; V_57 ++ )
V_42 -> V_44 [ V_57 ] . V_40 = V_57 ;
V_42 -> V_47 = F_27 ( V_39 , NULL ) ;
if ( F_28 ( V_42 -> V_47 ) ) {
F_29 ( V_39 , L_1 ) ;
return F_30 ( V_42 -> V_47 ) ;
}
V_51 = F_31 ( V_55 , V_60 , 0 ) ;
V_42 -> V_51 = F_32 ( V_39 , V_51 ) ;
if ( F_28 ( V_42 -> V_51 ) ) {
F_29 ( V_39 , L_2 ) ;
return F_30 ( V_42 -> V_51 ) ;
}
F_33 ( V_55 , V_42 ) ;
return 0 ;
}
static int F_34 ( struct V_54 * V_55 )
{
return 0 ;
}
