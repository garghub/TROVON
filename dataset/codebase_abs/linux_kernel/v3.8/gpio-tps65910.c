static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_2 ) ;
}
static int F_3 ( struct V_2 * V_4 , unsigned V_5 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_6 * V_6 = V_1 -> V_6 ;
unsigned int V_7 ;
F_4 ( V_6 , V_8 + V_5 , & V_7 ) ;
if ( V_7 & V_9 )
return 1 ;
return 0 ;
}
static void F_5 ( struct V_2 * V_4 , unsigned V_5 ,
int V_10 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_6 * V_6 = V_1 -> V_6 ;
if ( V_10 )
F_6 ( V_6 , V_8 + V_5 ,
V_11 ) ;
else
F_7 ( V_6 , V_8 + V_5 ,
V_11 ) ;
}
static int F_8 ( struct V_2 * V_4 , unsigned V_5 ,
int V_10 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_6 * V_6 = V_1 -> V_6 ;
F_5 ( V_4 , V_5 , V_10 ) ;
return F_6 ( V_6 , V_8 + V_5 ,
V_12 ) ;
}
static int F_9 ( struct V_2 * V_4 , unsigned V_5 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_6 * V_6 = V_1 -> V_6 ;
return F_7 ( V_6 , V_8 + V_5 ,
V_12 ) ;
}
static struct V_13 * F_10 ( struct V_14 * V_15 ,
struct V_6 * V_6 , int V_16 )
{
struct V_13 * V_13 = V_6 -> V_17 ;
unsigned int V_18 [ V_19 ] ;
int V_20 = F_11 ( V_16 , V_19 ) ;
int V_21 ;
int V_22 ;
V_13 -> V_23 = - 1 ;
V_21 = F_12 ( V_6 -> V_15 -> V_24 ,
L_1 , V_18 , V_20 ) ;
if ( V_21 < 0 ) {
F_13 ( V_15 , L_2 ) ;
return V_13 ;
}
for ( V_22 = 0 ; V_22 < V_20 ; V_22 ++ )
V_13 -> V_25 [ V_22 ] = ( V_18 [ V_22 ] != 0 ) ;
return V_13 ;
}
static struct V_13 * F_10 ( struct V_14 * V_15 ,
struct V_6 * V_6 , int V_16 )
{
return NULL ;
}
static int F_14 ( struct V_26 * V_27 )
{
struct V_6 * V_6 = F_15 ( V_27 -> V_15 . V_28 ) ;
struct V_13 * V_29 = F_16 ( V_6 -> V_15 ) ;
struct V_1 * V_1 ;
int V_21 ;
int V_30 ;
V_1 = F_17 ( & V_27 -> V_15 ,
sizeof( * V_1 ) , V_31 ) ;
if ( ! V_1 ) {
F_18 ( & V_27 -> V_15 , L_3 ) ;
return - V_32 ;
}
V_1 -> V_6 = V_6 ;
V_1 -> V_2 . V_33 = V_34 ;
V_1 -> V_2 . V_35 = V_6 -> V_36 -> V_37 ;
switch( F_19 ( V_6 ) ) {
case V_38 :
V_1 -> V_2 . V_20 = V_39 ;
break;
case V_40 :
V_1 -> V_2 . V_20 = V_41 ;
break;
default:
return - V_42 ;
}
V_1 -> V_2 . V_43 = 1 ;
V_1 -> V_2 . V_44 = F_9 ;
V_1 -> V_2 . V_45 = F_8 ;
V_1 -> V_2 . V_46 = F_5 ;
V_1 -> V_2 . V_47 = F_3 ;
V_1 -> V_2 . V_15 = & V_27 -> V_15 ;
#ifdef F_20
V_1 -> V_2 . V_24 = V_6 -> V_15 -> V_24 ;
#endif
if ( V_29 && V_29 -> V_23 )
V_1 -> V_2 . V_48 = V_29 -> V_23 ;
else
V_1 -> V_2 . V_48 = - 1 ;
if ( ! V_29 && V_6 -> V_15 -> V_24 )
V_29 = F_10 ( & V_27 -> V_15 , V_6 ,
V_1 -> V_2 . V_20 ) ;
if ( ! V_29 )
goto V_49;
for ( V_30 = 0 ; V_30 < V_1 -> V_2 . V_20 ; ++ V_30 ) {
if ( ! V_29 -> V_25 [ V_30 ] )
continue;
V_21 = F_6 ( V_6 ,
V_8 + V_30 , V_50 ) ;
if ( V_21 < 0 )
F_21 ( V_6 -> V_15 ,
L_4 , V_21 ) ;
}
V_49:
V_21 = F_22 ( & V_1 -> V_2 ) ;
if ( V_21 < 0 ) {
F_18 ( & V_27 -> V_15 , L_5 , V_21 ) ;
return V_21 ;
}
F_23 ( V_27 , V_1 ) ;
return V_21 ;
}
static int F_24 ( struct V_26 * V_27 )
{
struct V_1 * V_1 = F_25 ( V_27 ) ;
return F_26 ( & V_1 -> V_2 ) ;
}
static int T_1 F_27 ( void )
{
return F_28 ( & V_51 ) ;
}
static void T_2 F_29 ( void )
{
F_30 ( & V_51 ) ;
}
