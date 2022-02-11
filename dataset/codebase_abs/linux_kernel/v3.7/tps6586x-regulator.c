static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) -> V_4 ;
}
static int F_3 ( struct V_2 * V_3 ,
unsigned V_5 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_8 , V_9 , V_10 = F_5 ( V_3 ) ;
T_1 V_11 ;
V_9 = V_5 << ( F_6 ( V_3 -> V_12 -> V_13 ) - 1 ) ;
V_11 = V_3 -> V_12 -> V_13 ;
V_8 = F_7 ( V_4 , V_3 -> V_12 -> V_14 , V_9 , V_11 ) ;
if ( V_8 )
return V_8 ;
switch ( V_10 ) {
case V_15 :
case V_16 :
case V_17 :
case V_18 :
V_8 = F_8 ( V_4 , V_7 -> V_19 , 1 << V_7 -> V_20 ) ;
break;
}
return V_8 ;
}
static inline int F_9 ( struct V_1 * V_4 ,
struct V_6 * V_7 )
{
T_1 V_21 , V_22 ;
int V_8 ;
if ( V_7 -> V_23 [ 0 ] == V_7 -> V_23 [ 1 ] &&
V_7 -> V_24 [ 0 ] == V_7 -> V_24 [ 1 ] )
return 0 ;
V_8 = F_10 ( V_4 , V_7 -> V_23 [ 0 ] , & V_21 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_10 ( V_4 , V_7 -> V_23 [ 1 ] , & V_22 ) ;
if ( V_8 )
return V_8 ;
if ( ! ( V_22 & ( 1 << V_7 -> V_24 [ 1 ] ) ) )
return 0 ;
if ( ! ( V_21 & ( 1 << V_7 -> V_24 [ 0 ] ) ) ) {
V_8 = F_8 ( V_4 , V_7 -> V_23 [ 0 ] ,
1 << V_7 -> V_24 [ 0 ] ) ;
if ( V_8 )
return V_8 ;
}
return F_11 ( V_4 , V_7 -> V_23 [ 1 ] ,
1 << V_7 -> V_24 [ 1 ] ) ;
}
static int F_12 ( struct V_25 * V_26 )
{
struct V_1 * V_4 = V_26 -> V_27 . V_4 ;
struct V_28 * V_29 = V_26 -> V_27 . V_30 ;
struct V_31 * V_32 = V_29 -> V_33 ;
T_1 V_34 ;
if ( V_32 == NULL )
return 0 ;
if ( ! ( V_32 -> V_35 & V_36 ) )
return 0 ;
switch ( V_26 -> V_37 ) {
case V_17 :
V_34 = V_38 ;
break;
case V_18 :
V_34 = V_39 ;
break;
default:
F_13 ( & V_26 -> V_27 , L_1 ) ;
return - V_40 ;
}
return F_14 ( V_4 , V_34 ,
V_32 -> V_35 & V_41 ) ;
}
static inline struct V_6 * F_15 ( int V_37 )
{
struct V_6 * V_7 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < F_16 ( V_6 ) ; V_42 ++ ) {
V_7 = & V_6 [ V_42 ] ;
if ( V_7 -> V_12 . V_37 == V_37 )
return V_7 ;
}
return NULL ;
}
static int T_2 F_17 ( struct V_25 * V_26 )
{
struct V_6 * V_7 = NULL ;
struct V_43 V_44 = { } ;
struct V_2 * V_3 ;
int V_37 = V_26 -> V_37 ;
int V_45 ;
F_18 ( & V_26 -> V_27 , L_2 , V_37 ) ;
V_7 = F_15 ( V_37 ) ;
if ( V_7 == NULL ) {
F_19 ( & V_26 -> V_27 , L_3 ) ;
return - V_40 ;
}
V_45 = F_9 ( V_26 -> V_27 . V_4 , V_7 ) ;
if ( V_45 )
return V_45 ;
V_44 . V_27 = V_26 -> V_27 . V_4 ;
V_44 . V_46 = V_26 -> V_27 . V_46 ;
V_44 . V_47 = V_26 -> V_27 . V_30 ;
V_44 . V_33 = V_7 ;
V_3 = F_20 ( & V_7 -> V_12 , & V_44 ) ;
if ( F_21 ( V_3 ) ) {
F_19 ( & V_26 -> V_27 , L_4 ,
V_7 -> V_12 . V_48 ) ;
return F_22 ( V_3 ) ;
}
F_23 ( V_26 , V_3 ) ;
return F_12 ( V_26 ) ;
}
static int T_3 F_24 ( struct V_25 * V_26 )
{
struct V_2 * V_3 = F_25 ( V_26 ) ;
F_26 ( V_3 ) ;
return 0 ;
}
static int T_4 F_27 ( void )
{
return F_28 ( & V_49 ) ;
}
static void T_5 F_29 ( void )
{
F_30 ( & V_49 ) ;
}
