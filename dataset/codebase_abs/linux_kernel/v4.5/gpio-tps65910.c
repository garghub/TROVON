static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
unsigned int V_6 ;
F_3 ( V_5 , V_7 + V_3 , & V_6 ) ;
if ( V_6 & V_8 )
return 1 ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 , unsigned V_3 ,
int V_9 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
if ( V_9 )
F_5 ( V_5 , V_7 + V_3 ,
V_10 ) ;
else
F_6 ( V_5 , V_7 + V_3 ,
V_10 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_3 ,
int V_9 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
F_4 ( V_2 , V_3 , V_9 ) ;
return F_5 ( V_5 , V_7 + V_3 ,
V_11 ) ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
return F_6 ( V_5 , V_7 + V_3 ,
V_11 ) ;
}
static struct V_12 * F_9 ( struct V_13 * V_14 ,
struct V_5 * V_5 , int V_15 )
{
struct V_12 * V_12 = V_5 -> V_16 ;
unsigned int V_17 [ V_18 ] ;
int V_19 = F_10 ( V_15 , V_18 ) ;
int V_20 ;
int V_21 ;
V_12 -> V_22 = - 1 ;
V_20 = F_11 ( V_5 -> V_14 -> V_23 ,
L_1 , V_17 , V_19 ) ;
if ( V_20 < 0 ) {
F_12 ( V_14 , L_2 ) ;
return V_12 ;
}
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ )
V_12 -> V_24 [ V_21 ] = ( V_17 [ V_21 ] != 0 ) ;
return V_12 ;
}
static struct V_12 * F_9 ( struct V_13 * V_14 ,
struct V_5 * V_5 , int V_15 )
{
return NULL ;
}
static int F_13 ( struct V_25 * V_26 )
{
struct V_5 * V_5 = F_14 ( V_26 -> V_14 . V_27 ) ;
struct V_12 * V_28 = F_15 ( V_5 -> V_14 ) ;
struct V_4 * V_4 ;
int V_20 ;
int V_29 ;
V_4 = F_16 ( & V_26 -> V_14 ,
sizeof( * V_4 ) , V_30 ) ;
if ( ! V_4 )
return - V_31 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_1 . V_32 = V_33 ;
V_4 -> V_1 . V_34 = V_5 -> V_35 -> V_36 ;
switch ( F_17 ( V_5 ) ) {
case V_37 :
V_4 -> V_1 . V_19 = V_38 ;
break;
case V_39 :
V_4 -> V_1 . V_19 = V_40 ;
break;
default:
return - V_41 ;
}
V_4 -> V_1 . V_42 = true ;
V_4 -> V_1 . V_43 = F_8 ;
V_4 -> V_1 . V_44 = F_7 ;
V_4 -> V_1 . V_45 = F_4 ;
V_4 -> V_1 . V_46 = F_1 ;
V_4 -> V_1 . V_27 = & V_26 -> V_14 ;
#ifdef F_18
V_4 -> V_1 . V_23 = V_5 -> V_14 -> V_23 ;
#endif
if ( V_28 && V_28 -> V_22 )
V_4 -> V_1 . V_47 = V_28 -> V_22 ;
else
V_4 -> V_1 . V_47 = - 1 ;
if ( ! V_28 && V_5 -> V_14 -> V_23 )
V_28 = F_9 ( & V_26 -> V_14 , V_5 ,
V_4 -> V_1 . V_19 ) ;
if ( ! V_28 )
goto V_48;
for ( V_29 = 0 ; V_29 < V_4 -> V_1 . V_19 ; ++ V_29 ) {
if ( ! V_28 -> V_24 [ V_29 ] )
continue;
V_20 = F_5 ( V_5 ,
V_7 + V_29 , V_49 ) ;
if ( V_20 < 0 )
F_19 ( V_5 -> V_14 ,
L_3 , V_20 ) ;
}
V_48:
V_20 = F_20 ( & V_4 -> V_1 , V_4 ) ;
if ( V_20 < 0 ) {
F_21 ( & V_26 -> V_14 , L_4 , V_20 ) ;
return V_20 ;
}
F_22 ( V_26 , V_4 ) ;
return V_20 ;
}
static int F_23 ( struct V_25 * V_26 )
{
struct V_4 * V_4 = F_24 ( V_26 ) ;
F_25 ( & V_4 -> V_1 ) ;
return 0 ;
}
static int T_1 F_26 ( void )
{
return F_27 ( & V_50 ) ;
}
static void T_2 F_28 ( void )
{
F_29 ( & V_50 ) ;
}
