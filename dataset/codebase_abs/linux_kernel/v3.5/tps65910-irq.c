static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
unsigned int V_4 ;
T_2 V_5 ;
T_2 V_6 ;
int V_7 ;
F_2 ( V_3 , V_8 , & V_4 ) ;
V_5 = V_4 ;
F_2 ( V_3 , V_9 , & V_4 ) ;
V_5 |= V_4 << 8 ;
switch ( F_3 ( V_3 ) ) {
case V_10 :
F_2 ( V_3 , V_11 , & V_4 ) ;
V_5 |= V_4 << 16 ;
}
F_2 ( V_3 , V_12 , & V_4 ) ;
V_6 = V_4 ;
F_2 ( V_3 , V_13 , & V_4 ) ;
V_6 |= V_4 << 8 ;
switch ( F_3 ( V_3 ) ) {
case V_10 :
F_2 ( V_3 , V_14 , & V_4 ) ;
V_6 |= V_4 << 16 ;
}
V_5 &= ~ V_6 ;
if ( ! V_5 )
return V_15 ;
for ( V_7 = 0 ; V_7 < V_3 -> V_16 ; V_7 ++ ) {
if ( ! ( V_5 & ( 1 << V_7 ) ) )
continue;
F_4 ( F_5 ( V_3 -> V_17 , V_7 ) ) ;
}
V_4 = V_5 & 0xFF ;
V_5 >>= 8 ;
F_6 ( V_3 , V_8 , V_4 ) ;
V_4 = V_5 & 0xFF ;
F_6 ( V_3 , V_9 , V_4 ) ;
switch ( F_3 ( V_3 ) ) {
case V_10 :
V_4 = V_5 >> 8 ;
F_6 ( V_3 , V_11 , V_4 ) ;
}
return V_18 ;
}
static void F_7 ( struct V_2 * V_19 )
{
struct V_3 * V_3 = F_8 ( V_19 ) ;
F_9 ( & V_3 -> V_20 ) ;
}
static void F_10 ( struct V_2 * V_19 )
{
struct V_3 * V_3 = F_8 ( V_19 ) ;
T_2 V_21 ;
unsigned int V_4 ;
F_2 ( V_3 , V_12 , & V_4 ) ;
V_21 = V_4 ;
F_2 ( V_3 , V_13 , & V_4 ) ;
V_21 |= V_4 << 8 ;
switch ( F_3 ( V_3 ) ) {
case V_10 :
F_2 ( V_3 , V_14 , & V_4 ) ;
V_21 |= V_4 << 16 ;
}
if ( V_3 -> V_6 != V_21 ) {
V_4 = V_3 -> V_6 & 0xFF ;
F_6 ( V_3 , V_12 , V_4 ) ;
V_4 = V_3 -> V_6 >> 8 & 0xFF ;
F_6 ( V_3 , V_13 , V_4 ) ;
switch ( F_3 ( V_3 ) ) {
case V_10 :
V_4 = V_3 -> V_6 >> 16 ;
F_6 ( V_3 , V_14 , V_4 ) ;
}
}
F_11 ( & V_3 -> V_20 ) ;
}
static void F_12 ( struct V_2 * V_19 )
{
struct V_3 * V_3 = F_8 ( V_19 ) ;
V_3 -> V_6 &= ~ ( 1 << V_19 -> V_22 ) ;
}
static void F_13 ( struct V_2 * V_19 )
{
struct V_3 * V_3 = F_8 ( V_19 ) ;
V_3 -> V_6 |= ( 1 << V_19 -> V_22 ) ;
}
static int F_14 ( struct V_2 * V_19 , unsigned int V_23 )
{
struct V_3 * V_3 = F_8 ( V_19 ) ;
return F_15 ( V_3 -> V_24 , V_23 ) ;
}
static int F_16 ( struct V_25 * V_26 , unsigned int V_27 ,
T_3 V_28 )
{
struct V_3 * V_3 = V_26 -> V_29 ;
F_17 ( V_27 , V_3 ) ;
F_18 ( V_27 , & V_30 , V_31 ) ;
F_19 ( V_27 , 1 ) ;
#ifdef F_20
F_21 ( V_27 , V_32 ) ;
#else
F_22 ( V_27 ) ;
#endif
return 0 ;
}
int F_23 ( struct V_3 * V_3 , int V_1 ,
struct V_33 * V_34 )
{
int V_35 ;
int V_36 = V_37 ;
if ( ! V_1 ) {
F_24 ( V_3 -> V_38 , L_1 ) ;
return - V_39 ;
}
if ( ! V_34 ) {
F_24 ( V_3 -> V_38 , L_2 ) ;
return - V_39 ;
}
switch ( F_3 ( V_3 ) ) {
case V_40 :
V_3 -> V_16 = V_41 ;
break;
case V_10 :
V_3 -> V_16 = V_42 ;
break;
}
if ( V_34 -> V_43 > 0 ) {
V_34 -> V_43 = F_25 ( V_34 -> V_43 , 0 ,
V_3 -> V_16 , - 1 ) ;
if ( V_34 -> V_43 < 0 ) {
F_24 ( V_3 -> V_38 , L_3 ,
V_34 -> V_43 ) ;
return V_34 -> V_43 ;
}
}
V_3 -> V_6 = 0xFFFFFF ;
F_26 ( & V_3 -> V_20 ) ;
V_3 -> V_24 = V_1 ;
V_3 -> V_43 = V_34 -> V_43 ;
if ( V_34 -> V_43 > 0 )
V_3 -> V_17 = F_27 ( V_3 -> V_38 -> V_44 ,
V_3 -> V_16 ,
V_34 -> V_43 ,
0 ,
& V_45 , V_3 ) ;
else
V_3 -> V_17 = F_28 ( V_3 -> V_38 -> V_44 ,
V_3 -> V_16 ,
& V_45 , V_3 ) ;
if ( ! V_3 -> V_17 ) {
F_29 ( V_3 -> V_38 , L_4 ) ;
return - V_46 ;
}
V_35 = F_30 ( V_1 , NULL , F_1 , V_36 ,
L_5 , V_3 ) ;
F_31 ( V_1 , V_47 ) ;
if ( V_35 != 0 )
F_29 ( V_3 -> V_38 , L_6 , V_35 ) ;
return V_35 ;
}
int F_32 ( struct V_3 * V_3 )
{
if ( V_3 -> V_24 )
F_33 ( V_3 -> V_24 , V_3 ) ;
return 0 ;
}
