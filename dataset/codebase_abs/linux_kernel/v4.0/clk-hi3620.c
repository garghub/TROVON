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
unsigned long V_15 ,
unsigned long V_16 ,
unsigned long * V_17 ,
struct V_11 * * V_18 )
{
struct V_19 * V_20 = F_11 ( V_12 ) ;
unsigned long V_21 = 0 ;
if ( ( V_14 <= 13000000 ) && ( V_20 -> V_22 == V_23 ) ) {
V_14 = 13000000 ;
V_21 = 26000000 ;
} else if ( V_14 <= 26000000 ) {
V_14 = 25000000 ;
V_21 = 180000000 ;
} else if ( V_14 <= 52000000 ) {
V_14 = 50000000 ;
V_21 = 360000000 ;
} else if ( V_14 <= 100000000 ) {
V_14 = 100000000 ;
V_21 = 720000000 ;
} else {
V_14 = 180000000 ;
V_21 = 1440000000 ;
}
* V_17 = V_21 ;
return V_14 ;
}
static T_2 F_12 ( T_2 V_24 , T_2 V_25 , T_2 V_26 , T_2 V_27 )
{
T_2 V_28 ;
for ( V_28 = 0 ; V_28 < V_27 ; V_28 ++ ) {
if ( V_25 % 2 )
V_24 |= 1 << ( V_26 + V_28 ) ;
else
V_24 &= ~ ( 1 << ( V_26 + V_28 ) ) ;
V_25 = V_25 >> 1 ;
}
return V_24 ;
}
static int F_13 ( struct V_11 * V_12 , unsigned long V_14 )
{
struct V_19 * V_20 = F_11 ( V_12 ) ;
unsigned long V_29 ;
T_2 V_30 , V_31 , div , V_24 ;
static F_14 ( V_32 ) ;
switch ( V_14 ) {
case 13000000 :
V_30 = 3 ;
V_31 = 1 ;
div = 1 ;
break;
case 25000000 :
V_30 = 13 ;
V_31 = 6 ;
div = 6 ;
break;
case 50000000 :
V_30 = 3 ;
V_31 = 6 ;
div = 6 ;
break;
case 100000000 :
V_30 = 6 ;
V_31 = 4 ;
div = 6 ;
break;
case 180000000 :
V_30 = 6 ;
V_31 = 4 ;
div = 7 ;
break;
default:
return - V_33 ;
}
F_15 ( & V_32 , V_29 ) ;
V_24 = F_16 ( V_20 -> V_34 ) ;
V_24 &= ~ ( 1 << V_20 -> V_35 ) ;
F_17 ( V_24 , V_20 -> V_34 ) ;
V_24 = F_16 ( V_20 -> V_36 ) ;
V_24 = F_12 ( V_24 , V_30 , V_20 -> V_37 , V_20 -> V_38 ) ;
F_17 ( V_24 , V_20 -> V_36 ) ;
V_24 = F_16 ( V_20 -> V_39 ) ;
V_24 = F_12 ( V_24 , V_31 , V_20 -> V_40 , V_20 -> V_41 ) ;
F_17 ( V_24 , V_20 -> V_39 ) ;
V_24 = F_16 ( V_20 -> V_42 ) ;
V_24 = F_12 ( V_24 , div , V_20 -> V_43 , V_20 -> V_44 ) ;
F_17 ( V_24 , V_20 -> V_42 ) ;
V_24 = F_16 ( V_20 -> V_34 ) ;
V_24 |= 1 << V_20 -> V_35 ;
F_17 ( V_24 , V_20 -> V_34 ) ;
F_18 ( & V_32 , V_29 ) ;
return 0 ;
}
static int F_19 ( struct V_11 * V_12 )
{
struct V_19 * V_20 = F_11 ( V_12 ) ;
unsigned long V_14 ;
if ( V_20 -> V_22 == V_23 )
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
static struct V_45 * F_21 ( struct V_46 * V_47 ,
void T_3 * V_48 , struct V_1 * V_2 )
{
struct V_19 * V_20 ;
struct V_45 * V_45 ;
struct V_49 V_50 ;
V_20 = F_22 ( sizeof( * V_20 ) , V_51 ) ;
if ( ! V_20 ) {
F_23 ( L_1 , V_52 ) ;
return F_24 ( - V_53 ) ;
}
V_50 . V_54 = V_47 -> V_54 ;
V_50 . V_55 = & V_56 ;
V_50 . V_29 = V_47 -> V_29 | V_57 ;
V_50 . V_58 = ( V_47 -> V_59 ? & V_47 -> V_59 : NULL ) ;
V_50 . V_60 = ( V_47 -> V_59 ? 1 : 0 ) ;
V_20 -> V_12 . V_50 = & V_50 ;
V_20 -> V_22 = V_47 -> V_22 ;
V_20 -> V_34 = V_48 + V_47 -> V_34 ;
V_20 -> V_35 = V_47 -> V_35 ;
V_20 -> V_42 = V_48 + V_47 -> V_42 ;
V_20 -> V_43 = V_47 -> V_43 ;
V_20 -> V_44 = V_47 -> V_44 ;
V_20 -> V_39 = V_48 + V_47 -> V_39 ;
V_20 -> V_40 = V_47 -> V_40 ;
V_20 -> V_41 = V_47 -> V_41 ;
V_20 -> V_36 = V_48 + V_47 -> V_36 ;
V_20 -> V_37 = V_47 -> V_37 ;
V_20 -> V_38 = V_47 -> V_38 ;
V_45 = F_25 ( NULL , & V_20 -> V_12 ) ;
if ( F_26 ( F_27 ( V_45 ) ) )
F_28 ( V_20 ) ;
return V_45 ;
}
static void T_1 F_29 ( struct V_1 * V_61 )
{
void T_3 * V_48 ;
int V_28 , V_62 = F_4 ( V_63 ) ;
struct V_64 * V_4 ;
if ( ! V_61 ) {
F_23 ( L_2 ) ;
return;
}
V_48 = F_30 ( V_61 , 0 ) ;
if ( ! V_48 ) {
F_23 ( L_3 ) ;
return;
}
V_4 = F_22 ( sizeof( * V_4 ) , V_51 ) ;
if ( F_26 ( ! V_4 ) )
return;
V_4 -> V_65 = F_22 ( sizeof( struct V_45 * ) * V_62 , V_51 ) ;
if ( ! V_4 -> V_65 ) {
F_23 ( L_1 , V_52 ) ;
return;
}
for ( V_28 = 0 ; V_28 < V_62 ; V_28 ++ ) {
struct V_46 * V_47 = & V_63 [ V_28 ] ;
V_4 -> V_65 [ V_47 -> V_22 ] =
F_21 ( V_47 , V_48 , V_61 ) ;
}
V_4 -> V_66 = V_62 ;
F_31 ( V_61 , V_67 , V_4 ) ;
}
