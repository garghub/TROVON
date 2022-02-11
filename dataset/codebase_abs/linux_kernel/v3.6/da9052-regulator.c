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
if ( V_20 > V_19 [ V_12 ] [ V_24 ] ||
V_21 < V_19 [ V_12 ] [ V_25 ] )
return - V_5 ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 ++ ) {
if ( V_20 <= V_19 [ V_12 ] [ V_23 ] ) {
V_22 = V_23 ;
break;
}
}
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
unsigned int V_27 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_28 = F_4 ( V_7 ) ;
int V_29 ;
if ( ( V_28 == V_30 ) && ( V_9 -> V_13 -> V_17 == V_18 )
&& ( V_27 >= V_31 ) ) {
V_29 = ( ( V_31 * V_2 -> V_32 )
+ V_2 -> V_3 ) ;
V_29 += ( V_27 - V_31 )
* ( V_33 ) ;
} else {
V_29 = ( V_27 * V_2 -> V_32 ) + V_2 -> V_3 ;
}
if ( V_29 > V_2 -> V_4 )
return - V_5 ;
return V_29 ;
}
static int F_9 ( struct V_6 * V_7 ,
int V_3 , int V_4 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_28 = F_4 ( V_7 ) ;
int V_11 , V_34 ;
V_11 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_3 < V_2 -> V_3 )
V_3 = V_2 -> V_3 ;
if ( ( V_28 == V_30 ) && ( V_9 -> V_13 -> V_17 == V_18 )
&& ( V_3 >= V_35 ) ) {
V_34 = V_31 +
F_10 ( V_3 - V_35 ,
V_33 ) ;
} else {
V_34 = F_10 ( V_3 - V_2 -> V_3 , V_2 -> V_32 ) ;
}
V_11 = F_8 ( V_7 , V_34 ) ;
if ( V_11 < 0 )
return V_11 ;
return V_34 ;
}
static int F_11 ( struct V_6 * V_7 ,
unsigned int V_27 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_28 = F_4 ( V_7 ) ;
int V_11 ;
V_11 = F_7 ( V_9 -> V_13 , V_7 -> V_36 -> V_37 ,
V_7 -> V_36 -> V_38 , V_27 ) ;
if ( V_11 < 0 )
return V_11 ;
switch ( V_28 ) {
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
V_11 = F_7 ( V_9 -> V_13 , V_44 ,
V_2 -> V_45 , V_2 -> V_45 ) ;
break;
}
return V_11 ;
}
static inline struct V_1 * F_12 ( T_1 V_17 ,
int V_28 )
{
struct V_1 * V_2 ;
int V_23 ;
switch ( V_17 ) {
case V_18 :
for ( V_23 = 0 ; V_23 < F_13 ( V_1 ) ; V_23 ++ ) {
V_2 = & V_1 [ V_23 ] ;
if ( V_2 -> V_46 . V_28 == V_28 )
return V_2 ;
}
break;
case V_47 :
case V_48 :
case V_49 :
for ( V_23 = 0 ; V_23 < F_13 ( V_50 ) ; V_23 ++ ) {
V_2 = & V_50 [ V_23 ] ;
if ( V_2 -> V_46 . V_28 == V_28 )
return V_2 ;
}
break;
}
return NULL ;
}
static int T_2 F_14 ( struct V_51 * V_52 )
{
struct V_53 V_54 = { } ;
struct V_8 * V_9 ;
struct V_13 * V_13 ;
struct V_55 * V_56 ;
V_9 = F_15 ( & V_52 -> V_57 , sizeof( struct V_8 ) ,
V_58 ) ;
if ( ! V_9 )
return - V_59 ;
V_13 = F_16 ( V_52 -> V_57 . V_60 ) ;
V_56 = V_13 -> V_57 -> V_61 ;
V_9 -> V_13 = V_13 ;
V_9 -> V_2 = F_12 ( V_9 -> V_13 -> V_17 ,
V_52 -> V_28 ) ;
if ( V_9 -> V_2 == NULL ) {
F_17 ( & V_52 -> V_57 , L_1 ) ;
return - V_5 ;
}
V_54 . V_57 = & V_52 -> V_57 ;
V_54 . V_62 = V_9 ;
V_54 . V_63 = V_13 -> V_63 ;
if ( V_56 && V_56 -> V_64 ) {
V_54 . V_65 = V_56 -> V_64 [ V_52 -> V_28 ] ;
} else {
#ifdef F_18
struct V_66 * V_67 = V_13 -> V_57 -> V_68 ;
struct V_66 * V_69 ;
if ( ! V_67 )
return - V_70 ;
V_67 = F_19 ( V_67 , L_2 ) ;
if ( ! V_67 )
return - V_70 ;
F_20 (nproot, np) {
if ( ! F_21 ( V_69 -> V_71 ,
V_9 -> V_2 -> V_46 . V_71 ) ) {
V_54 . V_65 = F_22 (
& V_52 -> V_57 , V_69 ) ;
V_54 . V_68 = V_69 ;
break;
}
}
#endif
}
V_9 -> V_7 = F_23 ( & V_9 -> V_2 -> V_46 ,
& V_54 ) ;
if ( F_24 ( V_9 -> V_7 ) ) {
F_17 ( & V_52 -> V_57 , L_3 ,
V_9 -> V_2 -> V_46 . V_71 ) ;
return F_25 ( V_9 -> V_7 ) ;
}
F_26 ( V_52 , V_9 ) ;
return 0 ;
}
static int T_3 F_27 ( struct V_51 * V_52 )
{
struct V_8 * V_9 = F_28 ( V_52 ) ;
F_29 ( V_9 -> V_7 ) ;
return 0 ;
}
static int T_4 F_30 ( void )
{
return F_31 ( & V_72 ) ;
}
static void T_5 F_32 ( void )
{
F_33 ( & V_72 ) ;
}
