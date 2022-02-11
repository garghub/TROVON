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
static int F_11 ( struct V_6 * V_7 ,
unsigned int V_25 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_26 = F_4 ( V_7 ) ;
int V_11 ;
V_11 = F_7 ( V_9 -> V_13 , V_7 -> V_34 -> V_35 ,
V_7 -> V_34 -> V_36 , V_25 ) ;
if ( V_11 < 0 )
return V_11 ;
switch ( V_26 ) {
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
V_11 = F_7 ( V_9 -> V_13 , V_42 ,
V_2 -> V_43 , V_2 -> V_43 ) ;
break;
}
return V_11 ;
}
static int F_12 ( struct V_6 * V_7 ,
unsigned int V_44 ,
unsigned int V_45 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_26 = F_4 ( V_7 ) ;
int V_11 = 0 ;
switch ( V_26 ) {
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
V_11 = ( V_45 - V_44 ) * V_2 -> V_30 / 6250 ;
break;
}
return V_11 ;
}
static inline struct V_1 * F_13 ( T_1 V_17 ,
int V_26 )
{
struct V_1 * V_2 ;
int V_23 ;
switch ( V_17 ) {
case V_18 :
for ( V_23 = 0 ; V_23 < F_14 ( V_1 ) ; V_23 ++ ) {
V_2 = & V_1 [ V_23 ] ;
if ( V_2 -> V_46 . V_26 == V_26 )
return V_2 ;
}
break;
case V_47 :
case V_48 :
case V_49 :
case V_50 :
for ( V_23 = 0 ; V_23 < F_14 ( V_51 ) ; V_23 ++ ) {
V_2 = & V_51 [ V_23 ] ;
if ( V_2 -> V_46 . V_26 == V_26 )
return V_2 ;
}
break;
}
return NULL ;
}
static int F_15 ( struct V_52 * V_53 )
{
const struct V_54 * V_55 = F_16 ( V_53 ) ;
struct V_56 V_57 = { } ;
struct V_8 * V_9 ;
struct V_13 * V_13 ;
struct V_58 * V_59 ;
V_9 = F_17 ( & V_53 -> V_60 , sizeof( struct V_8 ) ,
V_61 ) ;
if ( ! V_9 )
return - V_62 ;
V_13 = F_18 ( V_53 -> V_60 . V_63 ) ;
V_59 = F_19 ( V_13 -> V_60 ) ;
V_9 -> V_13 = V_13 ;
V_9 -> V_2 = F_13 ( V_9 -> V_13 -> V_17 ,
V_55 -> V_26 ) ;
if ( V_9 -> V_2 == NULL ) {
F_20 ( & V_53 -> V_60 , L_1 ) ;
return - V_5 ;
}
V_57 . V_60 = & V_53 -> V_60 ;
V_57 . V_64 = V_9 ;
V_57 . V_65 = V_13 -> V_65 ;
if ( V_59 && V_59 -> V_66 ) {
V_57 . V_67 = V_59 -> V_66 [ V_55 -> V_26 ] ;
} else {
#ifdef F_21
struct V_68 * V_69 = V_13 -> V_60 -> V_70 ;
struct V_68 * V_71 ;
if ( ! V_69 )
return - V_72 ;
V_69 = F_22 ( V_69 , L_2 ) ;
if ( ! V_69 )
return - V_72 ;
F_23 (nproot, np) {
if ( ! F_24 ( V_71 -> V_73 ,
V_9 -> V_2 -> V_46 . V_73 ) ) {
V_57 . V_67 = F_25 (
& V_53 -> V_60 , V_71 ,
& V_9 -> V_2 -> V_46 ) ;
V_57 . V_70 = V_71 ;
break;
}
}
F_26 ( V_69 ) ;
#endif
}
V_9 -> V_7 = F_27 ( & V_53 -> V_60 ,
& V_9 -> V_2 -> V_46 ,
& V_57 ) ;
if ( F_28 ( V_9 -> V_7 ) ) {
F_20 ( & V_53 -> V_60 , L_3 ,
V_9 -> V_2 -> V_46 . V_73 ) ;
return F_29 ( V_9 -> V_7 ) ;
}
F_30 ( V_53 , V_9 ) ;
return 0 ;
}
static int T_2 F_31 ( void )
{
return F_32 ( & V_74 ) ;
}
static void T_3 F_33 ( void )
{
F_34 ( & V_74 ) ;
}
