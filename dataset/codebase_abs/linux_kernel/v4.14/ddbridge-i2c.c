static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
unsigned long V_7 ;
T_1 V_8 ;
F_2 ( V_6 , ( V_3 << 9 ) | V_4 , V_2 -> V_9 + V_10 ) ;
V_7 = F_3 ( & V_2 -> V_11 , V_12 ) ;
V_8 = F_4 ( V_6 , V_2 -> V_9 + V_10 ) ;
if ( V_7 == 0 ) {
F_5 ( V_6 -> V_6 , L_1 ,
V_6 -> V_13 , V_2 -> V_13 , V_2 -> V_14 ) ;
{
T_1 V_15 = F_4 ( V_6 , V_16 ) ;
F_5 ( V_6 -> V_6 , L_2 , V_15 ) ;
if ( V_2 -> V_14 ) {
T_1 V_17 = F_4 ( V_6 ,
F_6 ( V_2 -> V_14 ) |
V_16 ) ;
F_5 ( V_6 -> V_6 , L_3 ,
V_2 -> V_14 , V_17 ) ;
}
if ( V_15 & 1 ) {
F_2 ( V_6 , V_15 & 1 , V_18 ) ;
} else {
T_1 V_19 = F_4 ( V_6 ,
V_2 -> V_9 + V_20 ) ;
F_5 ( V_6 -> V_6 , L_4 ,
V_8 , V_19 ) ;
}
}
return - V_21 ;
}
if ( V_8 & 0x70000 )
return - V_21 ;
return 0 ;
}
static int F_7 ( struct V_22 * V_23 ,
struct V_24 V_25 [] , int V_26 )
{
struct V_1 * V_2 = (struct V_1 * ) F_8 ( V_23 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_2 V_27 = 0 ;
V_27 = V_25 [ 0 ] . V_27 ;
if ( V_25 [ 0 ] . V_28 > V_2 -> V_29 )
return - V_21 ;
switch ( V_26 ) {
case 1 :
if ( V_25 [ 0 ] . V_30 & V_31 ) {
F_2 ( V_6 , V_25 [ 0 ] . V_28 << 16 ,
V_2 -> V_9 + V_32 ) ;
if ( F_1 ( V_2 , V_27 , 3 ) )
break;
F_9 ( V_6 , V_25 [ 0 ] . V_33 ,
V_2 -> V_34 , V_25 [ 0 ] . V_28 ) ;
return V_26 ;
}
F_10 ( V_6 , V_2 -> V_35 , V_25 [ 0 ] . V_33 , V_25 [ 0 ] . V_28 ) ;
F_2 ( V_6 , V_25 [ 0 ] . V_28 , V_2 -> V_9 + V_32 ) ;
if ( F_1 ( V_2 , V_27 , 2 ) )
break;
return V_26 ;
case 2 :
if ( ( V_25 [ 0 ] . V_30 & V_31 ) == V_31 )
break;
if ( ( V_25 [ 1 ] . V_30 & V_31 ) != V_31 )
break;
if ( V_25 [ 1 ] . V_28 > V_2 -> V_29 )
break;
F_10 ( V_6 , V_2 -> V_35 , V_25 [ 0 ] . V_33 , V_25 [ 0 ] . V_28 ) ;
F_2 ( V_6 , V_25 [ 0 ] . V_28 | ( V_25 [ 1 ] . V_28 << 16 ) ,
V_2 -> V_9 + V_32 ) ;
if ( F_1 ( V_2 , V_27 , 1 ) )
break;
F_9 ( V_6 , V_25 [ 1 ] . V_33 ,
V_2 -> V_34 ,
V_25 [ 1 ] . V_28 ) ;
return V_26 ;
default:
break;
}
return - V_21 ;
}
static T_1 F_11 ( struct V_22 * V_36 )
{
return V_37 | V_38 ;
}
void F_12 ( struct V_5 * V_6 )
{
int V_39 ;
struct V_1 * V_2 ;
for ( V_39 = 0 ; V_39 < V_6 -> V_40 ; V_39 ++ ) {
V_2 = & V_6 -> V_2 [ V_39 ] ;
F_13 ( & V_2 -> V_36 ) ;
}
}
static void F_14 ( unsigned long V_41 )
{
struct V_1 * V_2 = (struct V_1 * ) V_41 ;
F_15 ( & V_2 -> V_11 ) ;
}
static int F_16 ( struct V_5 * V_6 , struct V_1 * V_2 ,
const struct V_42 * V_43 , int V_14 ,
int V_39 , int V_26 )
{
struct V_22 * V_36 ;
V_2 -> V_13 = V_39 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_29 = V_43 -> V_44 -> V_45 ;
V_2 -> V_35 = F_6 ( V_14 ) |
( V_43 -> V_44 -> V_46 + V_2 -> V_29 * V_39 ) ;
V_2 -> V_34 = V_2 -> V_35 ;
V_2 -> V_9 = F_6 ( V_14 ) |
( V_43 -> V_2 -> V_46 + V_43 -> V_2 -> V_45 * V_39 ) ;
F_2 ( V_6 , V_47 , V_2 -> V_9 + V_48 ) ;
F_2 ( V_6 , ( ( V_2 -> V_34 & 0xffff ) << 16 ) | ( V_2 -> V_35 & 0xffff ) ,
V_2 -> V_9 + V_49 ) ;
F_17 ( & V_2 -> V_11 ) ;
V_36 = & V_2 -> V_36 ;
F_18 ( V_36 , V_2 ) ;
#ifdef F_19
V_36 -> V_50 = F_19 | V_51 ;
#else
#ifdef V_51
V_36 -> V_50 = V_51 ;
#endif
#endif
snprintf ( V_36 -> V_52 , V_53 , L_5 ,
V_6 -> V_13 , V_2 -> V_14 , V_39 ) ;
V_36 -> V_54 = & V_55 ;
V_36 -> V_56 = ( void * ) V_2 ;
V_36 -> V_6 . V_57 = V_6 -> V_6 ;
return F_20 ( V_36 ) ;
}
int F_21 ( struct V_5 * V_6 )
{
int V_7 = 0 ;
T_1 V_39 , V_58 , V_26 = 0 , V_59 , V_46 ;
struct V_1 * V_2 ;
struct V_22 * V_36 ;
const struct V_42 * V_43 ;
for ( V_59 = 0 ; V_59 < V_60 ; V_59 ++ ) {
if ( ! V_6 -> V_14 [ V_59 ] . V_61 )
continue;
V_43 = V_6 -> V_14 [ V_59 ] . V_61 -> V_43 ;
if ( ! V_43 || ! V_43 -> V_2 )
continue;
V_46 = V_43 -> V_62 ;
for ( V_39 = 0 ; V_39 < V_43 -> V_2 -> V_26 ; V_39 ++ ) {
if ( ! ( V_6 -> V_14 [ V_59 ] . V_61 -> V_63 & ( 1 << V_39 ) ) )
continue;
V_2 = & V_6 -> V_2 [ V_26 ] ;
V_6 -> V_64 [ V_59 ] [ V_39 + V_46 ] = ( unsigned long ) V_2 ;
V_6 -> V_65 [ V_59 ] [ V_39 + V_46 ] = F_14 ;
V_7 = F_16 ( V_6 , V_2 , V_43 , V_59 , V_39 , V_26 ) ;
if ( V_7 )
break;
V_26 ++ ;
}
}
if ( V_7 ) {
for ( V_58 = 0 ; V_58 < V_26 ; V_58 ++ ) {
V_2 = & V_6 -> V_2 [ V_58 ] ;
V_36 = & V_2 -> V_36 ;
F_13 ( V_36 ) ;
}
} else
V_6 -> V_40 = V_26 ;
return V_7 ;
}
