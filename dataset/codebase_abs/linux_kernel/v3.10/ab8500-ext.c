static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 ;
if ( V_5 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_1 ) ;
return - V_7 ;
}
if ( V_5 -> V_8 && V_5 -> V_8 -> V_9 )
V_6 = V_5 -> V_10 ;
else
V_6 = V_5 -> V_11 ;
V_3 = F_5 ( V_5 -> V_12 ,
V_5 -> V_13 , V_5 -> V_14 ,
V_5 -> V_15 , V_6 ) ;
if ( V_3 < 0 ) {
F_3 ( F_4 ( V_5 -> V_2 ) ,
L_2 ) ;
return V_3 ;
}
F_6 ( F_4 ( V_2 ) ,
L_3 ,
V_5 -> V_16 . V_17 , V_5 -> V_13 , V_5 -> V_14 ,
V_5 -> V_15 , V_6 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 ;
if ( V_5 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_1 ) ;
return - V_7 ;
}
if ( V_5 -> V_8 && V_5 -> V_8 -> V_9 )
V_6 = V_5 -> V_18 ;
else
V_6 = 0 ;
V_3 = F_5 ( V_5 -> V_12 ,
V_5 -> V_13 , V_5 -> V_14 ,
V_5 -> V_15 , V_6 ) ;
if ( V_3 < 0 ) {
F_3 ( F_4 ( V_5 -> V_2 ) ,
L_4 ) ;
return V_3 ;
}
F_6 ( F_4 ( V_2 ) , L_5
L_6 ,
V_5 -> V_16 . V_17 , V_5 -> V_13 , V_5 -> V_14 ,
V_5 -> V_15 , V_6 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 ;
if ( V_5 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_1 ) ;
return - V_7 ;
}
V_3 = F_9 ( V_5 -> V_12 ,
V_5 -> V_13 , V_5 -> V_14 , & V_6 ) ;
if ( V_3 < 0 ) {
F_3 ( F_4 ( V_2 ) ,
L_7 , V_5 -> V_14 ) ;
return V_3 ;
}
F_6 ( F_4 ( V_2 ) , L_8
L_6 ,
V_5 -> V_16 . V_17 , V_5 -> V_13 , V_5 -> V_14 ,
V_5 -> V_15 , V_6 ) ;
if ( ( ( V_6 & V_5 -> V_15 ) == V_5 -> V_19 ) ||
( ( V_6 & V_5 -> V_15 ) == V_5 -> V_10 ) )
return 1 ;
else
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned int V_20 )
{
int V_3 = 0 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 ;
if ( V_5 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_1 ) ;
return - V_7 ;
}
switch ( V_20 ) {
case V_21 :
V_6 = V_5 -> V_10 ;
break;
case V_22 :
V_6 = V_5 -> V_19 ;
break;
default:
return - V_7 ;
}
if ( F_8 ( V_2 ) &&
! ( V_5 -> V_8 && V_5 -> V_8 -> V_9 ) ) {
V_3 = F_5 ( V_5 -> V_12 ,
V_5 -> V_13 , V_5 -> V_14 ,
V_5 -> V_15 , V_6 ) ;
if ( V_3 < 0 ) {
F_3 ( F_4 ( V_2 ) ,
L_9 ) ;
return V_3 ;
}
F_6 ( F_4 ( V_2 ) ,
L_10
L_11 ,
V_5 -> V_16 . V_17 , V_5 -> V_13 , V_5 -> V_14 ,
V_5 -> V_15 , V_6 ) ;
}
V_5 -> V_11 = V_6 ;
return 0 ;
}
static unsigned int F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_3 ;
if ( V_5 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_1 ) ;
return - V_7 ;
}
if ( V_5 -> V_11 == V_5 -> V_10 )
V_3 = V_21 ;
else if ( V_5 -> V_11 == V_5 -> V_19 )
V_3 = V_22 ;
else
V_3 = - V_7 ;
return V_3 ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned V_23 )
{
struct V_24 * V_25 = V_2 -> V_26 ;
if ( V_25 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_12 ) ;
return - V_7 ;
}
if ( V_25 -> V_27 && V_25 -> V_28 ) {
if ( V_25 -> V_27 == V_25 -> V_28 )
return V_25 -> V_27 ;
}
return - V_7 ;
}
int F_13 ( struct V_29 * V_30 )
{
struct V_31 * V_31 = F_14 ( V_30 -> V_12 . V_32 ) ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
struct V_37 V_38 = { } ;
int V_39 , V_40 ;
if ( ! V_31 ) {
F_3 ( & V_30 -> V_12 , L_13 ) ;
return - V_7 ;
}
V_34 = F_15 ( V_31 -> V_12 ) ;
if ( ! V_34 ) {
F_3 ( & V_30 -> V_12 , L_14 ) ;
return - V_7 ;
}
V_36 = V_34 -> V_41 ;
if ( ! V_36 ) {
F_3 ( & V_30 -> V_12 , L_15 ) ;
return - V_7 ;
}
if ( V_36 -> V_42 != F_16 ( V_4 ) ) {
F_3 ( & V_30 -> V_12 , L_16 ) ;
return - V_7 ;
}
if ( F_17 ( V_31 ) ) {
struct V_4 * V_5 ;
V_5 = & V_4 [ V_43 ] ;
V_5 -> V_11 = 0x30 ;
V_5 -> V_10 = 0x30 ;
V_5 -> V_19 = 0x10 ;
}
for ( V_39 = 0 ; V_39 < F_16 ( V_4 ) ; V_39 ++ ) {
struct V_4 * V_5 = NULL ;
V_5 = & V_4 [ V_39 ] ;
V_5 -> V_12 = & V_30 -> V_12 ;
V_5 -> V_8 = (struct V_44 * )
V_36 -> V_45 [ V_39 ] . V_46 ;
V_38 . V_12 = & V_30 -> V_12 ;
V_38 . V_47 = & V_36 -> V_45 [ V_39 ] ;
V_38 . V_46 = V_5 ;
V_5 -> V_2 = F_18 ( & V_5 -> V_16 , & V_38 ) ;
if ( F_19 ( V_5 -> V_2 ) ) {
V_40 = F_20 ( V_5 -> V_2 ) ;
F_3 ( & V_30 -> V_12 , L_17 ,
V_5 -> V_16 . V_17 ) ;
while ( -- V_39 >= 0 ) {
V_5 = & V_4 [ V_39 ] ;
F_21 ( V_5 -> V_2 ) ;
}
return V_40 ;
}
F_6 ( F_4 ( V_5 -> V_2 ) ,
L_18 , V_5 -> V_16 . V_17 ) ;
}
return 0 ;
}
void F_22 ( struct V_29 * V_30 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < F_16 ( V_4 ) ; V_39 ++ ) {
struct V_4 * V_5 = NULL ;
V_5 = & V_4 [ V_39 ] ;
F_23 ( F_4 ( V_5 -> V_2 ) ,
L_19 , V_5 -> V_16 . V_17 ) ;
F_21 ( V_5 -> V_2 ) ;
}
}
