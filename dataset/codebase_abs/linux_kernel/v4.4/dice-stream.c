int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int * V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_6 ) ; V_5 ++ ) {
if ( ! ( V_2 -> V_7 & F_3 ( V_5 ) ) )
continue;
if ( V_6 [ V_5 ] != V_3 )
continue;
* V_4 = ( V_5 - 1 ) / 2 ;
return 0 ;
}
return - V_8 ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
T_1 V_11 ;
V_11 = F_5 ( ( V_12 ) - 1 ) ;
if ( V_10 == & V_2 -> V_13 )
F_6 ( V_2 , V_14 ,
& V_11 , sizeof( V_11 ) ) ;
else
F_7 ( V_2 , V_15 ,
& V_11 , sizeof( V_11 ) ) ;
F_8 ( V_10 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
unsigned int V_16 )
{
T_1 V_11 ;
int V_17 ;
V_17 = F_10 ( V_10 , V_16 ,
F_11 ( V_2 -> V_18 ) -> V_19 ) ;
if ( V_17 < 0 )
goto V_20;
V_11 = F_5 ( V_10 -> V_11 ) ;
if ( V_10 == & V_2 -> V_13 )
V_17 = F_6 ( V_2 , V_14 ,
& V_11 , sizeof( V_11 ) ) ;
else
V_17 = F_7 ( V_2 , V_15 ,
& V_11 , sizeof( V_11 ) ) ;
if ( V_17 < 0 )
F_4 ( V_2 , V_10 ) ;
V_20:
return V_17 ;
}
static void F_12 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
F_13 ( V_22 ) ;
F_14 ( V_22 ) ;
if ( V_22 == & V_2 -> V_23 )
F_4 ( V_2 , & V_2 -> V_13 ) ;
else
F_4 ( V_2 , & V_2 -> V_24 ) ;
}
static int F_15 ( struct V_1 * V_2 , struct V_21 * V_22 ,
unsigned int V_3 )
{
struct V_9 * V_10 ;
unsigned int V_5 , V_4 , V_25 , V_26 ;
bool V_27 ;
int V_17 ;
V_17 = F_1 ( V_2 , V_3 , & V_4 ) ;
if ( V_17 < 0 )
goto V_20;
if ( V_22 == & V_2 -> V_23 ) {
V_10 = & V_2 -> V_13 ;
V_25 = V_2 -> V_28 [ V_4 ] ;
V_26 = V_2 -> V_29 [ V_4 ] ;
} else {
V_10 = & V_2 -> V_24 ;
V_25 = V_2 -> V_30 [ V_4 ] ;
V_26 = V_2 -> V_31 [ V_4 ] ;
}
V_27 = V_4 > 1 ;
if ( V_27 ) {
V_3 /= 2 ;
V_25 *= 2 ;
}
V_17 = F_16 ( V_22 , V_3 , V_25 , V_26 ,
V_27 ) ;
if ( V_17 < 0 )
goto V_20;
if ( V_27 ) {
V_25 /= 2 ;
for ( V_5 = 0 ; V_5 < V_25 ; V_5 ++ ) {
F_17 ( V_22 , V_5 , V_5 * 2 ) ;
F_17 ( V_22 , V_5 + V_25 ,
V_5 * 2 + 1 ) ;
}
}
V_17 = F_9 ( V_2 , V_10 ,
F_18 ( V_22 ) ) ;
if ( V_17 < 0 ) {
F_19 ( & V_2 -> V_18 -> V_32 ,
L_1 ) ;
goto V_20;
}
V_17 = F_20 ( V_22 , V_10 -> V_11 ,
F_11 ( V_2 -> V_18 ) -> V_19 ) ;
if ( V_17 < 0 )
F_4 ( V_2 , V_10 ) ;
V_20:
return V_17 ;
}
static int F_21 ( struct V_1 * V_2 , enum V_33 * V_34 )
{
V_12 V_35 ;
int V_17 ;
V_17 = F_22 ( V_2 , & V_35 ) ;
if ( V_17 < 0 )
goto V_20;
switch ( V_35 ) {
case V_36 :
case V_37 :
case V_38 :
V_17 = - V_39 ;
break;
case V_40 :
* V_34 = 0 ;
break;
default:
* V_34 = V_41 ;
break;
}
V_20:
return V_17 ;
}
int F_23 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_21 * V_42 , * V_43 ;
unsigned int V_44 ;
enum V_33 V_34 ;
int V_17 = 0 ;
if ( V_2 -> V_45 == 0 )
goto V_20;
V_17 = F_21 ( V_2 , & V_34 ) ;
if ( V_17 < 0 )
goto V_20;
if ( V_34 == V_41 ) {
V_42 = & V_2 -> V_23 ;
V_43 = & V_2 -> V_46 ;
} else {
V_42 = & V_2 -> V_46 ;
V_43 = & V_2 -> V_23 ;
}
if ( F_24 ( V_42 ) || F_24 ( V_43 ) )
F_12 ( V_2 , V_42 ) ;
V_17 = F_25 ( V_2 , & V_44 ) ;
if ( V_17 < 0 ) {
F_19 ( & V_2 -> V_18 -> V_32 ,
L_2 ) ;
goto V_20;
}
if ( V_3 == 0 )
V_3 = V_44 ;
if ( V_3 != V_44 )
F_12 ( V_2 , V_42 ) ;
if ( ! F_26 ( V_42 ) ) {
F_12 ( V_2 , V_43 ) ;
F_27 ( V_2 ) ;
F_28 ( V_34 , V_42 , V_43 ) ;
V_17 = F_29 ( V_2 , V_3 ) ;
if ( V_17 < 0 ) {
F_19 ( & V_2 -> V_18 -> V_32 ,
L_3 ) ;
goto V_20;
}
V_17 = F_15 ( V_2 , V_42 , V_3 ) ;
if ( V_17 < 0 ) {
F_19 ( & V_2 -> V_18 -> V_32 ,
L_4 ) ;
goto V_20;
}
V_17 = F_15 ( V_2 , V_43 , V_3 ) ;
if ( V_17 < 0 ) {
F_19 ( & V_2 -> V_18 -> V_32 ,
L_5 ) ;
F_12 ( V_2 , V_42 ) ;
goto V_20;
}
V_17 = F_30 ( V_2 ) ;
if ( V_17 < 0 ) {
F_19 ( & V_2 -> V_18 -> V_32 ,
L_6 ) ;
F_12 ( V_2 , V_42 ) ;
F_12 ( V_2 , V_43 ) ;
goto V_20;
}
if ( ! F_31 ( V_42 , V_47 ) ||
! F_31 ( V_43 , V_47 ) ) {
F_27 ( V_2 ) ;
F_12 ( V_2 , V_42 ) ;
F_12 ( V_2 , V_43 ) ;
V_17 = - V_48 ;
}
}
V_20:
return V_17 ;
}
void F_32 ( struct V_1 * V_2 )
{
if ( V_2 -> V_45 > 0 )
return;
F_27 ( V_2 ) ;
F_12 ( V_2 , & V_2 -> V_23 ) ;
F_12 ( V_2 , & V_2 -> V_46 ) ;
}
static int F_33 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_17 ;
struct V_9 * V_10 ;
enum V_49 V_50 ;
if ( V_22 == & V_2 -> V_23 ) {
V_10 = & V_2 -> V_13 ;
V_50 = V_51 ;
} else {
V_10 = & V_2 -> V_24 ;
V_50 = V_52 ;
}
V_17 = F_34 ( V_10 , V_2 -> V_18 ) ;
if ( V_17 < 0 )
goto V_20;
V_10 -> V_53 = 0x00000000ffffffffuLL ;
V_17 = F_35 ( V_22 , V_2 -> V_18 , V_50 , V_54 ) ;
if ( V_17 < 0 ) {
F_36 ( V_22 ) ;
F_37 ( V_10 ) ;
}
V_20:
return V_17 ;
}
static void F_38 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_9 * V_10 ;
if ( V_22 == & V_2 -> V_23 )
V_10 = & V_2 -> V_13 ;
else
V_10 = & V_2 -> V_24 ;
F_36 ( V_22 ) ;
F_37 ( V_10 ) ;
}
int F_39 ( struct V_1 * V_2 )
{
int V_17 ;
V_2 -> V_45 = 0 ;
V_17 = F_33 ( V_2 , & V_2 -> V_23 ) ;
if ( V_17 < 0 )
goto V_20;
V_17 = F_33 ( V_2 , & V_2 -> V_46 ) ;
if ( V_17 < 0 )
F_38 ( V_2 , & V_2 -> V_23 ) ;
V_20:
return V_17 ;
}
void F_40 ( struct V_1 * V_2 )
{
F_27 ( V_2 ) ;
F_38 ( V_2 , & V_2 -> V_23 ) ;
F_38 ( V_2 , & V_2 -> V_46 ) ;
V_2 -> V_45 = 0 ;
}
void F_41 ( struct V_1 * V_2 )
{
V_2 -> V_55 = false ;
F_12 ( V_2 , & V_2 -> V_46 ) ;
F_12 ( V_2 , & V_2 -> V_23 ) ;
F_42 ( & V_2 -> V_24 ) ;
F_42 ( & V_2 -> V_13 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
V_2 -> V_56 = true ;
F_44 ( & V_2 -> V_57 ) ;
}
int F_45 ( struct V_1 * V_2 )
{
int V_17 ;
F_46 ( & V_2 -> V_58 ) ;
if ( V_2 -> V_59 < 0 ) {
V_17 = - V_60 ;
goto V_61;
}
if ( V_2 -> V_59 ++ == 0 )
F_43 ( V_2 ) ;
V_17 = 0 ;
V_61:
F_47 ( & V_2 -> V_58 ) ;
return V_17 ;
}
void F_48 ( struct V_1 * V_2 )
{
F_46 ( & V_2 -> V_58 ) ;
if ( F_49 ( V_2 -> V_59 <= 0 ) )
goto V_61;
if ( -- V_2 -> V_59 == 0 )
F_43 ( V_2 ) ;
V_61:
F_47 ( & V_2 -> V_58 ) ;
}
