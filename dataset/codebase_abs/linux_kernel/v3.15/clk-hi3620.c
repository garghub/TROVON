static void T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 , V_5 ) ;
if ( ! V_4 )
return;
F_3 ( V_6 ,
F_4 ( V_6 ) ,
V_4 ) ;
F_5 ( V_7 ,
F_4 ( V_7 ) ,
V_4 ) ;
F_6 ( V_8 , F_4 ( V_8 ) ,
V_4 ) ;
F_7 ( V_9 , F_4 ( V_9 ) ,
V_4 ) ;
F_8 ( V_10 ,
F_4 ( V_10 ) ,
V_4 ) ;
}
static unsigned long F_9 ( struct V_11 * V_12 ,
unsigned long V_13 )
{
switch ( V_13 ) {
case 26000000 :
return 13000000 ;
case 180000000 :
return 25000000 ;
case 360000000 :
return 50000000 ;
case 720000000 :
return 100000000 ;
case 1440000000 :
return 180000000 ;
default:
return V_13 ;
}
}
static long F_10 ( struct V_11 * V_12 , unsigned long V_14 ,
unsigned long * V_15 ,
struct V_16 * * V_17 )
{
struct V_18 * V_19 = F_11 ( V_12 ) ;
unsigned long V_20 = 0 ;
if ( ( V_14 <= 13000000 ) && ( V_19 -> V_21 == V_22 ) ) {
V_14 = 13000000 ;
V_20 = 26000000 ;
} else if ( V_14 <= 26000000 ) {
V_14 = 25000000 ;
V_20 = 180000000 ;
} else if ( V_14 <= 52000000 ) {
V_14 = 50000000 ;
V_20 = 360000000 ;
} else if ( V_14 <= 100000000 ) {
V_14 = 100000000 ;
V_20 = 720000000 ;
} else {
V_14 = 180000000 ;
V_20 = 1440000000 ;
}
* V_15 = V_20 ;
return V_14 ;
}
static T_2 F_12 ( T_2 V_23 , T_2 V_24 , T_2 V_25 , T_2 V_26 )
{
T_2 V_27 ;
for ( V_27 = 0 ; V_27 < V_26 ; V_27 ++ ) {
if ( V_24 % 2 )
V_23 |= 1 << ( V_25 + V_27 ) ;
else
V_23 &= ~ ( 1 << ( V_25 + V_27 ) ) ;
V_24 = V_24 >> 1 ;
}
return V_23 ;
}
static int F_13 ( struct V_11 * V_12 , unsigned long V_14 )
{
struct V_18 * V_19 = F_11 ( V_12 ) ;
unsigned long V_28 ;
T_2 V_29 , V_30 , div , V_23 ;
static F_14 ( V_31 ) ;
switch ( V_14 ) {
case 13000000 :
V_29 = 3 ;
V_30 = 1 ;
div = 1 ;
break;
case 25000000 :
V_29 = 13 ;
V_30 = 6 ;
div = 6 ;
break;
case 50000000 :
V_29 = 3 ;
V_30 = 6 ;
div = 6 ;
break;
case 100000000 :
V_29 = 6 ;
V_30 = 4 ;
div = 6 ;
break;
case 180000000 :
V_29 = 6 ;
V_30 = 4 ;
div = 7 ;
break;
default:
return - V_32 ;
}
F_15 ( & V_31 , V_28 ) ;
V_23 = F_16 ( V_19 -> V_33 ) ;
V_23 &= ~ ( 1 << V_19 -> V_34 ) ;
F_17 ( V_23 , V_19 -> V_33 ) ;
V_23 = F_16 ( V_19 -> V_35 ) ;
V_23 = F_12 ( V_23 , V_29 , V_19 -> V_36 , V_19 -> V_37 ) ;
F_17 ( V_23 , V_19 -> V_35 ) ;
V_23 = F_16 ( V_19 -> V_38 ) ;
V_23 = F_12 ( V_23 , V_30 , V_19 -> V_39 , V_19 -> V_40 ) ;
F_17 ( V_23 , V_19 -> V_38 ) ;
V_23 = F_16 ( V_19 -> V_41 ) ;
V_23 = F_12 ( V_23 , div , V_19 -> V_42 , V_19 -> V_43 ) ;
F_17 ( V_23 , V_19 -> V_41 ) ;
V_23 = F_16 ( V_19 -> V_33 ) ;
V_23 |= 1 << V_19 -> V_34 ;
F_17 ( V_23 , V_19 -> V_33 ) ;
F_18 ( & V_31 , V_28 ) ;
return 0 ;
}
static int F_19 ( struct V_11 * V_12 )
{
struct V_18 * V_19 = F_11 ( V_12 ) ;
unsigned long V_14 ;
if ( V_19 -> V_21 == V_22 )
V_14 = 13000000 ;
else
V_14 = 25000000 ;
return F_13 ( V_12 , V_14 ) ;
}
static int F_20 ( struct V_11 * V_12 , unsigned long V_14 ,
unsigned long V_13 )
{
return F_13 ( V_12 , V_14 ) ;
}
static struct V_16 * F_21 ( struct V_44 * V_45 ,
void T_3 * V_46 , struct V_1 * V_2 )
{
struct V_18 * V_19 ;
struct V_16 * V_16 ;
struct V_47 V_48 ;
V_19 = F_22 ( sizeof( * V_19 ) , V_49 ) ;
if ( ! V_19 ) {
F_23 ( L_1 , V_50 ) ;
return F_24 ( - V_51 ) ;
}
V_48 . V_52 = V_45 -> V_52 ;
V_48 . V_53 = & V_54 ;
V_48 . V_28 = V_45 -> V_28 | V_55 ;
V_48 . V_56 = ( V_45 -> V_57 ? & V_45 -> V_57 : NULL ) ;
V_48 . V_58 = ( V_45 -> V_57 ? 1 : 0 ) ;
V_19 -> V_12 . V_48 = & V_48 ;
V_19 -> V_21 = V_45 -> V_21 ;
V_19 -> V_33 = V_46 + V_45 -> V_33 ;
V_19 -> V_34 = V_45 -> V_34 ;
V_19 -> V_41 = V_46 + V_45 -> V_41 ;
V_19 -> V_42 = V_45 -> V_42 ;
V_19 -> V_43 = V_45 -> V_43 ;
V_19 -> V_38 = V_46 + V_45 -> V_38 ;
V_19 -> V_39 = V_45 -> V_39 ;
V_19 -> V_40 = V_45 -> V_40 ;
V_19 -> V_35 = V_46 + V_45 -> V_35 ;
V_19 -> V_36 = V_45 -> V_36 ;
V_19 -> V_37 = V_45 -> V_37 ;
V_16 = F_25 ( NULL , & V_19 -> V_12 ) ;
if ( F_26 ( F_27 ( V_16 ) ) )
F_28 ( V_19 ) ;
return V_16 ;
}
static void T_1 F_29 ( struct V_1 * V_59 )
{
void T_3 * V_46 ;
int V_27 , V_60 = F_4 ( V_61 ) ;
struct V_62 * V_4 ;
if ( ! V_59 ) {
F_23 ( L_2 ) ;
return;
}
V_46 = F_30 ( V_59 , 0 ) ;
if ( ! V_46 ) {
F_23 ( L_3 ) ;
return;
}
V_4 = F_22 ( sizeof( * V_4 ) , V_49 ) ;
if ( F_26 ( ! V_4 ) )
return;
V_4 -> V_63 = F_22 ( sizeof( struct V_16 * ) * V_60 , V_49 ) ;
if ( ! V_4 -> V_63 ) {
F_23 ( L_1 , V_50 ) ;
return;
}
for ( V_27 = 0 ; V_27 < V_60 ; V_27 ++ ) {
struct V_44 * V_45 = & V_61 [ V_27 ] ;
V_4 -> V_63 [ V_45 -> V_21 ] =
F_21 ( V_45 , V_46 , V_59 ) ;
}
V_4 -> V_64 = V_60 ;
F_31 ( V_59 , V_65 , V_4 ) ;
}
