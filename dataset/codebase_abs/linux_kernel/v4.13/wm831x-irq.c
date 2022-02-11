static inline int F_1 ( struct V_1 * V_2 )
{
return V_3 - 1 + V_2 -> V_4 ;
}
static inline struct V_1 * F_2 ( struct V_5 * V_5 ,
int V_6 )
{
return & V_7 [ V_6 ] ;
}
static void F_3 ( struct V_2 * V_8 )
{
struct V_5 * V_5 = F_4 ( V_8 ) ;
F_5 ( & V_5 -> V_9 ) ;
}
static void F_6 ( struct V_2 * V_8 )
{
struct V_5 * V_5 = F_4 ( V_8 ) ;
int V_10 ;
for ( V_10 = 0 ; V_10 < F_7 ( V_5 -> V_11 ) ; V_10 ++ ) {
if ( V_5 -> V_11 [ V_10 ] ) {
F_8 ( V_5 , V_12 + V_10 ,
V_13 | V_14 ,
V_5 -> V_11 [ V_10 ] ) ;
V_5 -> V_11 [ V_10 ] = 0 ;
}
}
for ( V_10 = 0 ; V_10 < F_7 ( V_5 -> V_15 ) ; V_10 ++ ) {
if ( V_5 -> V_15 [ V_10 ] != V_5 -> V_16 [ V_10 ] ) {
F_9 ( V_5 -> V_17 , L_1 ,
V_18 + V_10 ,
V_5 -> V_15 [ V_10 ] ) ;
V_5 -> V_16 [ V_10 ] = V_5 -> V_15 [ V_10 ] ;
F_10 ( V_5 ,
V_18 + V_10 ,
V_5 -> V_15 [ V_10 ] ) ;
}
}
F_11 ( & V_5 -> V_9 ) ;
}
static void F_12 ( struct V_2 * V_8 )
{
struct V_5 * V_5 = F_4 ( V_8 ) ;
struct V_1 * V_2 = F_2 ( V_5 ,
V_8 -> V_19 ) ;
V_5 -> V_15 [ V_2 -> V_4 - 1 ] &= ~ V_2 -> V_20 ;
}
static void F_13 ( struct V_2 * V_8 )
{
struct V_5 * V_5 = F_4 ( V_8 ) ;
struct V_1 * V_2 = F_2 ( V_5 ,
V_8 -> V_19 ) ;
V_5 -> V_15 [ V_2 -> V_4 - 1 ] |= V_2 -> V_20 ;
}
static int F_14 ( struct V_2 * V_8 , unsigned int type )
{
struct V_5 * V_5 = F_4 ( V_8 ) ;
int V_6 ;
V_6 = V_8 -> V_19 ;
if ( V_6 < V_21 || V_6 > V_22 ) {
if ( V_6 >= 0 && V_6 < V_23 )
return 0 ;
else
return - V_24 ;
}
V_6 -= V_21 ;
V_5 -> V_25 [ V_6 ] = false ;
V_5 -> V_26 [ V_6 ] = false ;
switch ( type ) {
case V_27 :
V_5 -> V_11 [ V_6 ] = 0x10000 | V_13 ;
break;
case V_28 :
V_5 -> V_11 [ V_6 ] = 0x10000 | V_14 ;
break;
case V_29 :
V_5 -> V_11 [ V_6 ] = 0x10000 ;
break;
case V_30 :
V_5 -> V_11 [ V_6 ] = 0x10000 | V_14 ;
V_5 -> V_26 [ V_6 ] = true ;
break;
case V_31 :
V_5 -> V_11 [ V_6 ] = 0x10000 ;
V_5 -> V_25 [ V_6 ] = true ;
break;
default:
return - V_24 ;
}
return 0 ;
}
static T_1 F_15 ( int V_6 , void * V_8 )
{
struct V_5 * V_5 = V_8 ;
unsigned int V_10 ;
int V_32 , V_33 , V_34 ;
int V_35 [ V_36 ] = { 0 } ;
int V_37 [ V_36 ] = { 0 } ;
int * V_38 ;
V_32 = F_16 ( V_5 , V_39 ) ;
if ( V_32 < 0 ) {
F_17 ( V_5 -> V_17 , L_2 ,
V_32 ) ;
goto V_40;
}
if ( V_32 & V_41 )
F_18 ( F_19 ( V_5 -> V_42 ,
V_43 ) ) ;
if ( V_32 & V_44 )
F_18 ( F_19 ( V_5 -> V_42 ,
V_45 ) ) ;
V_32 &= ~ ( V_46 | V_47 ) ;
for ( V_10 = 0 ; V_10 < F_7 ( V_7 ) ; V_10 ++ ) {
int V_48 = V_7 [ V_10 ] . V_4 - 1 ;
if ( ! ( V_32 & V_7 [ V_10 ] . V_32 ) )
continue;
V_38 = & V_35 [ V_48 ] ;
if ( ! V_37 [ V_48 ] ) {
V_33 = F_1 ( & V_7 [ V_10 ] ) ;
* V_38 = F_16 ( V_5 , V_33 ) ;
if ( * V_38 < 0 ) {
F_17 ( V_5 -> V_17 ,
L_3 ,
* V_38 ) ;
goto V_40;
}
V_37 [ V_48 ] = 1 ;
* V_38 &= ~ V_5 -> V_15 [ V_48 ] ;
F_10 ( V_5 , V_33 , * V_38 ) ;
}
if ( * V_38 & V_7 [ V_10 ] . V_20 )
F_18 ( F_19 ( V_5 -> V_42 ,
V_10 ) ) ;
if ( V_32 == V_49 &&
V_5 -> V_26 [ V_10 - V_21 ] ) {
V_34 = F_16 ( V_5 , V_50 ) ;
while ( V_34 & 1 << ( V_10 - V_21 ) ) {
F_18 ( F_19 ( V_5 -> V_42 ,
V_10 ) ) ;
V_34 = F_16 ( V_5 ,
V_50 ) ;
}
}
if ( V_32 == V_49 &&
V_5 -> V_25 [ V_10 - V_21 ] ) {
V_34 = F_16 ( V_5 , V_50 ) ;
while ( ! ( V_34 & 1 << ( V_10 - V_21 ) ) ) {
F_18 ( F_19 ( V_5 -> V_42 ,
V_10 ) ) ;
V_34 = F_16 ( V_5 ,
V_50 ) ;
}
}
}
V_40:
return V_51 ;
}
static int F_20 ( struct V_42 * V_52 , unsigned int V_53 ,
T_2 V_54 )
{
F_21 ( V_53 , V_52 -> V_55 ) ;
F_22 ( V_53 , & V_56 , V_57 ) ;
F_23 ( V_53 , 1 ) ;
F_24 ( V_53 ) ;
return 0 ;
}
int F_25 ( struct V_5 * V_5 , int V_6 )
{
struct V_58 * V_59 = & V_5 -> V_59 ;
struct V_42 * V_60 ;
int V_10 , V_34 , V_61 ;
F_26 ( & V_5 -> V_9 ) ;
for ( V_10 = 0 ; V_10 < F_7 ( V_5 -> V_15 ) ; V_10 ++ ) {
V_5 -> V_15 [ V_10 ] = 0xffff ;
V_5 -> V_16 [ V_10 ] = 0xffff ;
F_10 ( V_5 , V_18 + V_10 ,
0xffff ) ;
}
if ( V_59 -> V_61 ) {
V_61 = F_27 ( V_59 -> V_61 , 0 ,
V_23 , 0 ) ;
if ( V_61 < 0 ) {
F_28 ( V_5 -> V_17 , L_4 ,
V_61 ) ;
V_61 = 0 ;
}
} else {
V_61 = 0 ;
}
if ( V_61 )
V_60 = F_29 ( V_5 -> V_17 -> V_62 ,
F_7 ( V_7 ) ,
V_61 , 0 ,
& V_63 ,
V_5 ) ;
else
V_60 = F_30 ( V_5 -> V_17 -> V_62 ,
F_7 ( V_7 ) ,
& V_63 ,
V_5 ) ;
if ( ! V_60 ) {
F_28 ( V_5 -> V_17 , L_5 ) ;
return - V_24 ;
}
if ( V_59 -> V_64 )
V_10 = 0 ;
else
V_10 = V_65 ;
F_8 ( V_5 , V_66 ,
V_65 , V_10 ) ;
V_5 -> V_6 = V_6 ;
V_5 -> V_42 = V_60 ;
if ( V_6 ) {
V_34 = F_31 ( V_6 ) ;
if ( V_34 != 0 ) {
F_28 ( V_5 -> V_17 ,
L_6 ,
V_34 ) ;
}
V_34 = F_32 ( V_6 , NULL , F_15 ,
V_67 | V_68 ,
L_7 , V_5 ) ;
if ( V_34 != 0 ) {
F_17 ( V_5 -> V_17 , L_8 ,
V_6 , V_34 ) ;
return V_34 ;
}
} else {
F_28 ( V_5 -> V_17 ,
L_9 ) ;
}
F_10 ( V_5 , V_69 , 0 ) ;
return 0 ;
}
void F_33 ( struct V_5 * V_5 )
{
if ( V_5 -> V_6 )
F_34 ( V_5 -> V_6 , V_5 ) ;
}
