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
unsigned int V_11 ;
V_11 = F_5 ( ( V_12 ) - 1 ) ;
if ( V_10 == & V_2 -> V_13 )
F_6 ( V_2 , V_14 ,
& V_11 , 4 ) ;
else
F_7 ( V_2 , V_15 ,
& V_11 , 4 ) ;
F_8 ( V_10 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
unsigned int V_16 )
{
unsigned int V_11 ;
int V_17 ;
V_17 = F_10 ( V_10 , V_16 ,
F_11 ( V_2 -> V_18 ) -> V_19 ) ;
if ( V_17 < 0 )
goto V_20;
V_11 = F_5 ( V_10 -> V_11 ) ;
if ( V_10 == & V_2 -> V_13 )
V_17 = F_6 ( V_2 , V_14 ,
& V_11 , 4 ) ;
else
V_17 = F_7 ( V_2 , V_15 ,
& V_11 , 4 ) ;
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
int V_17 ;
V_17 = F_1 ( V_2 , V_3 , & V_4 ) ;
if ( V_17 < 0 )
goto V_20;
if ( V_22 == & V_2 -> V_23 ) {
V_10 = & V_2 -> V_13 ;
V_25 = V_2 -> V_27 [ V_4 ] ;
V_26 = V_2 -> V_28 [ V_4 ] ;
} else {
V_10 = & V_2 -> V_24 ;
V_25 = V_2 -> V_29 [ V_4 ] ;
V_26 = V_2 -> V_30 [ V_4 ] ;
}
if ( V_4 > 1 ) {
V_3 /= 2 ;
V_25 *= 2 ;
V_22 -> V_31 = true ;
} else {
V_22 -> V_31 = false ;
}
F_16 ( V_22 , V_3 , V_25 , V_26 ) ;
if ( V_4 > 1 ) {
V_25 /= 2 ;
for ( V_5 = 0 ; V_5 < V_25 ; V_5 ++ ) {
V_22 -> V_32 [ V_5 ] = V_5 * 2 ;
V_22 -> V_32 [ V_5 + V_25 ] = V_5 * 2 + 1 ;
}
}
V_17 = F_9 ( V_2 , V_10 ,
F_17 ( V_22 ) ) ;
if ( V_17 < 0 ) {
F_18 ( & V_2 -> V_18 -> V_33 ,
L_1 ) ;
goto V_20;
}
V_17 = F_19 ( V_22 , V_10 -> V_11 ,
F_11 ( V_2 -> V_18 ) -> V_19 ) ;
if ( V_17 < 0 )
F_4 ( V_2 , V_10 ) ;
V_20:
return V_17 ;
}
static int F_20 ( struct V_1 * V_2 , enum V_34 * V_35 )
{
V_12 V_36 ;
int V_17 ;
V_17 = F_21 ( V_2 , & V_36 ) ;
if ( V_17 < 0 )
goto V_20;
switch ( V_36 ) {
case V_37 :
case V_38 :
case V_39 :
V_17 = - V_40 ;
break;
case V_41 :
* V_35 = 0 ;
break;
default:
* V_35 = V_42 ;
break;
}
V_20:
return V_17 ;
}
int F_22 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_21 * V_43 , * V_44 ;
unsigned int V_45 ;
enum V_34 V_35 ;
int V_17 = 0 ;
if ( V_2 -> V_46 == 0 )
goto V_20;
V_17 = F_20 ( V_2 , & V_35 ) ;
if ( V_17 < 0 )
goto V_20;
if ( V_35 == V_42 ) {
V_43 = & V_2 -> V_23 ;
V_44 = & V_2 -> V_47 ;
} else {
V_43 = & V_2 -> V_47 ;
V_44 = & V_2 -> V_23 ;
}
if ( F_23 ( V_43 ) || F_23 ( V_44 ) )
F_12 ( V_2 , V_43 ) ;
V_17 = F_24 ( V_2 , & V_45 ) ;
if ( V_17 < 0 ) {
F_18 ( & V_2 -> V_18 -> V_33 ,
L_2 ) ;
goto V_20;
}
if ( V_3 == 0 )
V_3 = V_45 ;
if ( V_3 != V_45 )
F_12 ( V_2 , V_43 ) ;
if ( ! F_25 ( V_43 ) ) {
F_12 ( V_2 , V_44 ) ;
F_26 ( V_2 ) ;
F_27 ( V_35 , V_43 , V_44 ) ;
V_17 = F_28 ( V_2 , V_3 ) ;
if ( V_17 < 0 ) {
F_18 ( & V_2 -> V_18 -> V_33 ,
L_3 ) ;
goto V_20;
}
V_17 = F_15 ( V_2 , V_43 , V_3 ) ;
if ( V_17 < 0 ) {
F_18 ( & V_2 -> V_18 -> V_33 ,
L_4 ) ;
goto V_20;
}
V_17 = F_15 ( V_2 , V_44 , V_3 ) ;
if ( V_17 < 0 ) {
F_18 ( & V_2 -> V_18 -> V_33 ,
L_5 ) ;
F_12 ( V_2 , V_43 ) ;
goto V_20;
}
V_17 = F_29 ( V_2 ) ;
if ( V_17 < 0 ) {
F_18 ( & V_2 -> V_18 -> V_33 ,
L_6 ) ;
F_12 ( V_2 , V_43 ) ;
F_12 ( V_2 , V_44 ) ;
goto V_20;
}
if ( ! F_30 ( V_43 , V_48 ) ||
! F_30 ( V_44 , V_48 ) ) {
F_26 ( V_2 ) ;
F_12 ( V_2 , V_43 ) ;
F_12 ( V_2 , V_44 ) ;
V_17 = - V_49 ;
}
}
V_20:
return V_17 ;
}
void F_31 ( struct V_1 * V_2 )
{
if ( V_2 -> V_46 > 0 )
return;
F_26 ( V_2 ) ;
F_12 ( V_2 , & V_2 -> V_23 ) ;
F_12 ( V_2 , & V_2 -> V_47 ) ;
}
static int F_32 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_17 ;
struct V_9 * V_10 ;
enum V_50 V_51 ;
if ( V_22 == & V_2 -> V_23 ) {
V_10 = & V_2 -> V_13 ;
V_51 = V_52 ;
} else {
V_10 = & V_2 -> V_24 ;
V_51 = V_53 ;
}
V_17 = F_33 ( V_10 , V_2 -> V_18 ) ;
if ( V_17 < 0 )
goto V_20;
V_10 -> V_54 = 0x00000000ffffffffuLL ;
V_17 = F_34 ( V_22 , V_2 -> V_18 , V_51 , V_55 ) ;
if ( V_17 < 0 ) {
F_35 ( V_22 ) ;
F_36 ( V_10 ) ;
}
V_20:
return V_17 ;
}
static void F_37 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_9 * V_10 ;
if ( V_22 == & V_2 -> V_23 )
V_10 = & V_2 -> V_13 ;
else
V_10 = & V_2 -> V_24 ;
F_35 ( V_22 ) ;
F_36 ( V_10 ) ;
}
int F_38 ( struct V_1 * V_2 )
{
int V_17 ;
V_2 -> V_46 = 0 ;
V_17 = F_32 ( V_2 , & V_2 -> V_23 ) ;
if ( V_17 < 0 )
goto V_20;
V_17 = F_32 ( V_2 , & V_2 -> V_47 ) ;
if ( V_17 < 0 )
F_37 ( V_2 , & V_2 -> V_23 ) ;
V_20:
return V_17 ;
}
void F_39 ( struct V_1 * V_2 )
{
F_26 ( V_2 ) ;
F_37 ( V_2 , & V_2 -> V_23 ) ;
F_37 ( V_2 , & V_2 -> V_47 ) ;
V_2 -> V_46 = 0 ;
}
void F_40 ( struct V_1 * V_2 )
{
V_2 -> V_56 = false ;
F_12 ( V_2 , & V_2 -> V_47 ) ;
F_12 ( V_2 , & V_2 -> V_23 ) ;
F_41 ( & V_2 -> V_24 ) ;
F_41 ( & V_2 -> V_13 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
V_2 -> V_57 = true ;
F_43 ( & V_2 -> V_58 ) ;
}
int F_44 ( struct V_1 * V_2 )
{
int V_17 ;
F_45 ( & V_2 -> V_59 ) ;
if ( V_2 -> V_60 < 0 ) {
V_17 = - V_61 ;
goto V_62;
}
if ( V_2 -> V_60 ++ == 0 )
F_42 ( V_2 ) ;
V_17 = 0 ;
V_62:
F_46 ( & V_2 -> V_59 ) ;
return V_17 ;
}
void F_47 ( struct V_1 * V_2 )
{
F_45 ( & V_2 -> V_59 ) ;
if ( F_48 ( V_2 -> V_60 <= 0 ) )
goto V_62;
if ( -- V_2 -> V_60 == 0 )
F_42 ( V_2 ) ;
V_62:
F_46 ( & V_2 -> V_59 ) ;
}
