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
struct V_27 * V_16 = V_26 ;
struct V_27 V_28 ;
if ( V_16 -> V_29 != 2 )
return - V_30 ;
V_17 = V_16 -> args [ 0 ] ;
for ( V_3 = 0 ; V_3 < V_25 ; V_3 ++ )
F_13 ( V_23 , V_24 + V_3 , V_17 + V_3 ,
& V_31 ,
V_23 -> V_32 ) ;
V_28 . V_33 = V_23 -> V_34 -> V_35 ;
if ( V_12 -> V_36 ) {
V_28 . V_29 = 1 ;
V_28 . args [ 0 ] = V_16 -> args [ 0 ] ;
} else {
V_28 . V_29 = 3 ;
V_28 . args [ 0 ] = V_37 ;
V_28 . args [ 1 ] = V_16 -> args [ 0 ] ;
V_28 . args [ 2 ] = V_16 -> args [ 1 ] ;
}
return F_14 ( V_23 , V_24 , V_25 , & V_28 ) ;
}
static int T_3 F_15 ( struct V_38 * V_39 ,
struct V_38 * V_34 )
{
struct V_22 * V_23 , * V_40 ;
struct V_41 * V_42 ;
int V_43 , V_44 ;
V_40 = F_16 ( V_34 ) ;
if ( ! V_40 ) {
F_17 ( L_1 ) ;
return - V_30 ;
}
V_12 = F_18 ( sizeof( * V_12 ) , V_45 ) ;
if ( ! V_12 )
return - V_46 ;
V_12 -> V_6 = F_19 ( V_39 , 0 , L_2 ) ;
if ( F_20 ( V_12 -> V_6 ) ) {
F_17 ( L_3 ) ;
V_43 = F_21 ( V_12 -> V_6 ) ;
goto V_47;
}
V_42 = F_22 ( V_39 , L_4 ) ;
if ( F_20 ( V_42 ) ) {
V_43 = F_21 ( V_42 ) ;
F_17 ( L_5 ) ;
goto V_48;
}
F_23 ( V_42 , V_49 , & V_44 ) ;
V_12 -> V_21 = 0x1 << V_44 ;
V_23 = F_24 ( V_40 , 0 ,
V_4 , V_39 ,
& V_50 , V_12 ) ;
if ( ! V_23 ) {
V_43 = - V_46 ;
goto V_48;
}
if ( F_25 ( V_23 -> V_34 -> V_35 , L_6 ) )
V_12 -> V_36 = true ;
F_26 ( & V_51 ) ;
return 0 ;
V_48:
F_27 ( V_12 -> V_6 ) ;
V_47:
F_28 ( V_12 ) ;
return V_43 ;
}
