static inline void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ )
V_2 -> V_5 [ V_3 ] = F_2 ( V_2 -> V_6 + F_3 ( V_3 ) ) ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ )
F_5 ( V_2 -> V_5 [ V_3 ] , V_2 -> V_6 + F_3 ( V_3 ) ) ;
}
static int F_6 ( struct V_7 * V_8 ,
unsigned long V_9 , void * V_10 )
{
switch ( V_9 ) {
case V_11 :
F_1 ( V_12 ) ;
break;
case V_13 :
case V_14 :
F_4 ( V_12 ) ;
break;
}
return V_15 ;
}
static void F_7 ( struct V_16 * V_2 )
{
T_1 V_17 = V_2 -> V_17 ;
struct V_1 * V_18 = V_2 -> V_18 ;
T_2 V_19 ;
V_19 = F_2 ( V_18 -> V_6 + F_3 ( V_17 ) ) ;
V_19 &= V_20 ;
F_8 ( V_19 & ~ V_18 -> V_21 ) ;
F_5 ( V_18 -> V_21 ,
V_18 -> V_6 + F_3 ( V_17 ) ) ;
F_9 ( V_2 ) ;
}
static void F_10 ( struct V_16 * V_2 )
{
T_1 V_17 = V_2 -> V_17 ;
struct V_1 * V_18 = V_2 -> V_18 ;
F_5 ( 0x0 , V_18 -> V_6 + F_3 ( V_17 ) ) ;
F_11 ( V_2 ) ;
}
static int F_12 ( struct V_22 * V_23 , unsigned int V_24 ,
unsigned int V_25 , void * V_26 )
{
int V_3 ;
T_1 V_17 ;
struct V_27 * V_28 = V_26 ;
struct V_27 V_29 ;
if ( ! F_13 ( V_23 -> V_30 ) )
return - V_31 ;
if ( V_28 -> V_32 != 2 )
return - V_31 ;
V_17 = V_28 -> V_33 [ 0 ] ;
for ( V_3 = 0 ; V_3 < V_25 ; V_3 ++ )
F_14 ( V_23 , V_24 + V_3 , V_17 + V_3 ,
& V_34 ,
V_23 -> V_35 ) ;
V_29 . V_36 = V_23 -> V_30 -> V_36 ;
if ( V_12 -> V_37 ) {
V_29 . V_32 = 1 ;
V_29 . V_33 [ 0 ] = V_28 -> V_33 [ 0 ] ;
} else {
V_29 . V_32 = 3 ;
V_29 . V_33 [ 0 ] = V_38 ;
V_29 . V_33 [ 1 ] = V_28 -> V_33 [ 0 ] ;
V_29 . V_33 [ 2 ] = V_28 -> V_33 [ 1 ] ;
}
return F_15 ( V_23 , V_24 , V_25 ,
& V_29 ) ;
}
static int F_16 ( struct V_22 * V_39 ,
struct V_27 * V_28 ,
unsigned long * V_17 ,
unsigned int * type )
{
if ( F_8 ( V_28 -> V_32 < 2 ) )
return - V_31 ;
* V_17 = V_28 -> V_33 [ 0 ] ;
* type = V_28 -> V_33 [ 1 ] & V_40 ;
return 0 ;
}
static int T_3 F_17 ( struct V_41 * V_42 ,
struct V_41 * V_30 )
{
struct V_22 * V_23 , * V_43 ;
struct V_44 * V_45 ;
int V_46 , V_47 ;
V_43 = F_18 ( V_30 ) ;
if ( ! V_43 ) {
F_19 ( L_1 ) ;
return - V_31 ;
}
V_12 = F_20 ( sizeof( * V_12 ) , V_48 ) ;
if ( ! V_12 )
return - V_49 ;
V_12 -> V_6 = F_21 ( V_42 , 0 , L_2 ) ;
if ( F_22 ( V_12 -> V_6 ) ) {
F_19 ( L_3 ) ;
V_46 = F_23 ( V_12 -> V_6 ) ;
goto V_50;
}
V_45 = F_24 ( V_42 , L_4 ) ;
if ( F_22 ( V_45 ) ) {
V_46 = F_23 ( V_45 ) ;
F_19 ( L_5 ) ;
goto V_51;
}
F_25 ( V_45 , V_52 , & V_47 ) ;
V_12 -> V_21 = 0x1 << V_47 ;
V_23 = F_26 ( V_43 , 0 ,
V_4 , V_42 ,
& V_53 , V_12 ) ;
if ( ! V_23 ) {
V_46 = - V_49 ;
goto V_51;
}
if ( F_27 ( F_13 ( V_23 -> V_30 ) ,
L_6 ) )
V_12 -> V_37 = true ;
F_28 ( & V_54 ) ;
return 0 ;
V_51:
F_29 ( V_12 -> V_6 ) ;
V_50:
F_30 ( V_12 ) ;
return V_46 ;
}
