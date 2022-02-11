static int F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
if ( V_3 > V_2 -> V_4 || V_4 < V_2 -> V_3 )
return - V_5 ;
return 0 ;
}
static int F_2 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_10 = F_4 ( V_7 ) ;
int V_11 , V_12 = 2 ;
V_11 = F_5 ( V_9 -> V_13 , V_14 + V_10 / 2 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_10 % 2 == 0 )
V_11 = ( V_11 & V_15 ) >> 2 ;
else
V_11 = ( V_11 & V_16 ) >> 6 ;
if ( V_9 -> V_13 -> V_17 == V_18 )
V_12 = 0 ;
else if ( V_10 == 0 )
V_12 = 1 ;
return V_19 [ V_12 ] [ V_11 ] ;
}
static int F_6 ( struct V_6 * V_7 , int V_20 ,
int V_21 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_10 = F_4 ( V_7 ) ;
int V_22 = 0 ;
int V_23 , V_12 = 2 ;
if ( V_9 -> V_13 -> V_17 == V_18 )
V_12 = 0 ;
else if ( V_10 == 0 )
V_12 = 1 ;
for ( V_23 = V_24 - 1 ; V_23 >= 0 ; V_23 -- ) {
if ( ( V_20 <= V_19 [ V_12 ] [ V_23 ] ) &&
( V_19 [ V_12 ] [ V_23 ] <= V_21 ) ) {
V_22 = V_23 ;
break;
}
}
if ( V_23 < 0 )
return - V_5 ;
if ( V_10 % 2 == 0 )
return F_7 ( V_9 -> V_13 ,
V_14 + V_10 / 2 ,
V_15 ,
V_22 << 2 ) ;
else
return F_7 ( V_9 -> V_13 ,
V_14 + V_10 / 2 ,
V_16 ,
V_22 << 6 ) ;
}
static int F_8 ( struct V_6 * V_7 ,
unsigned int V_25 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_26 = F_4 ( V_7 ) ;
int V_27 ;
if ( ( V_26 == V_28 ) && ( V_9 -> V_13 -> V_17 == V_18 )
&& ( V_25 >= V_29 ) ) {
V_27 = ( ( V_29 * V_2 -> V_30 )
+ V_2 -> V_3 ) ;
V_27 += ( V_25 - V_29 )
* ( V_31 ) ;
} else {
V_27 = ( V_25 * V_2 -> V_30 ) + V_2 -> V_3 ;
}
if ( V_27 > V_2 -> V_4 )
return - V_5 ;
return V_27 ;
}
static int F_9 ( struct V_6 * V_7 ,
int V_3 , int V_4 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_26 = F_4 ( V_7 ) ;
int V_11 , V_32 ;
V_11 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_3 < V_2 -> V_3 )
V_3 = V_2 -> V_3 ;
if ( ( V_26 == V_28 ) && ( V_9 -> V_13 -> V_17 == V_18 )
&& ( V_3 >= V_33 ) ) {
V_32 = V_29 +
F_10 ( V_3 - V_33 ,
V_31 ) ;
} else {
V_32 = F_10 ( V_3 - V_2 -> V_3 , V_2 -> V_30 ) ;
}
V_11 = F_8 ( V_7 , V_32 ) ;
if ( V_11 < 0 )
return V_11 ;
return V_32 ;
}
static inline struct V_1 * F_11 ( T_1 V_17 ,
int V_26 )
{
struct V_1 * V_2 ;
int V_23 ;
switch ( V_17 ) {
case V_18 :
for ( V_23 = 0 ; V_23 < F_12 ( V_1 ) ; V_23 ++ ) {
V_2 = & V_1 [ V_23 ] ;
if ( V_2 -> V_34 . V_26 == V_26 )
return V_2 ;
}
break;
case V_35 :
case V_36 :
case V_37 :
for ( V_23 = 0 ; V_23 < F_12 ( V_38 ) ; V_23 ++ ) {
V_2 = & V_38 [ V_23 ] ;
if ( V_2 -> V_34 . V_26 == V_26 )
return V_2 ;
}
break;
}
return NULL ;
}
static int F_13 ( struct V_39 * V_40 )
{
struct V_41 V_42 = { } ;
struct V_8 * V_9 ;
struct V_13 * V_13 ;
struct V_43 * V_44 ;
V_9 = F_14 ( & V_40 -> V_45 , sizeof( struct V_8 ) ,
V_46 ) ;
if ( ! V_9 )
return - V_47 ;
V_13 = F_15 ( V_40 -> V_45 . V_48 ) ;
V_44 = F_16 ( V_13 -> V_45 ) ;
V_9 -> V_13 = V_13 ;
V_9 -> V_2 = F_11 ( V_9 -> V_13 -> V_17 ,
V_40 -> V_26 ) ;
if ( V_9 -> V_2 == NULL ) {
F_17 ( & V_40 -> V_45 , L_1 ) ;
return - V_5 ;
}
V_42 . V_45 = & V_40 -> V_45 ;
V_42 . V_49 = V_9 ;
V_42 . V_50 = V_13 -> V_50 ;
if ( V_44 && V_44 -> V_51 ) {
V_42 . V_52 = V_44 -> V_51 [ V_40 -> V_26 ] ;
} else {
#ifdef F_18
struct V_53 * V_54 , * V_55 ;
V_54 = F_19 ( V_13 -> V_45 -> V_56 ) ;
if ( ! V_54 )
return - V_57 ;
V_54 = F_20 ( V_54 , L_2 ) ;
if ( ! V_54 )
return - V_57 ;
F_21 (nproot, np) {
if ( ! F_22 ( V_55 -> V_58 ,
V_9 -> V_2 -> V_34 . V_58 ) ) {
V_42 . V_52 = F_23 (
& V_40 -> V_45 , V_55 ) ;
V_42 . V_56 = V_55 ;
break;
}
}
F_24 ( V_54 ) ;
#endif
}
V_9 -> V_7 = F_25 ( & V_9 -> V_2 -> V_34 ,
& V_42 ) ;
if ( F_26 ( V_9 -> V_7 ) ) {
F_17 ( & V_40 -> V_45 , L_3 ,
V_9 -> V_2 -> V_34 . V_58 ) ;
return F_27 ( V_9 -> V_7 ) ;
}
F_28 ( V_40 , V_9 ) ;
return 0 ;
}
static int F_29 ( struct V_39 * V_40 )
{
struct V_8 * V_9 = F_30 ( V_40 ) ;
F_31 ( V_9 -> V_7 ) ;
return 0 ;
}
static int T_2 F_32 ( void )
{
return F_33 ( & V_59 ) ;
}
static void T_3 F_34 ( void )
{
F_35 ( & V_59 ) ;
}
