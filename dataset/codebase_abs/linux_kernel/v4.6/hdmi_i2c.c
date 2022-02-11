static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
F_2 ( V_3 , V_4 ,
V_5 ) ;
F_2 ( V_3 , V_4 ,
V_6 ) ;
F_2 ( V_3 , V_7 ,
F_3 ( 2 ) |
F_4 ( 10 ) ) ;
F_2 ( V_3 , V_8 ,
F_5 ( 0xff ) ) ;
F_2 ( V_3 , V_9 ,
V_10 |
F_6 ( 27 ) ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_11 * V_12 = V_3 -> V_12 ;
T_1 V_13 = 0xffff ;
T_1 V_14 ;
do {
-- V_13 ;
F_2 ( V_3 , V_15 ,
V_16 |
V_17 ) ;
V_14 = F_8 ( V_3 , V_15 ) ;
} while ( ( V_14 & V_18 ) && V_13 );
if ( ! V_13 ) {
F_9 ( V_12 -> V_12 , L_1 ) ;
return - V_19 ;
}
V_2 -> V_20 = false ;
return 0 ;
}
static bool V_20 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
if ( ! V_2 -> V_20 ) {
T_1 V_14 ;
V_14 = F_8 ( V_3 , V_15 ) ;
if ( ( V_14 & V_17 ) &&
( V_14 & V_18 ) ) {
V_2 -> V_20 = true ;
F_2 ( V_3 , V_15 ,
V_16 ) ;
}
}
return V_2 -> V_20 ;
}
static int F_10 ( struct V_21 * V_22 ,
struct V_23 * V_24 , int V_25 )
{
struct V_1 * V_2 = F_11 ( V_22 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_11 * V_12 = V_3 -> V_12 ;
static const T_1 V_26 [] = {
V_27 , V_28 ,
V_29 , V_30 ,
} ;
int V_31 [ V_32 ] ;
int V_33 , V_34 , V_35 , V_36 = 0 ;
T_1 V_37 , V_38 , V_39 ;
V_25 = F_12 ( V_25 , V_32 ) ;
F_13 ( ! ( F_8 ( V_3 , V_40 ) & V_41 ) ) ;
if ( V_25 == 0 )
return V_25 ;
F_1 ( V_2 ) ;
V_33 = F_7 ( V_2 ) ;
if ( V_33 )
return V_33 ;
for ( V_34 = 0 ; V_34 < V_25 ; V_34 ++ ) {
struct V_23 * V_42 = & V_24 [ V_34 ] ;
T_1 V_43 = V_42 -> V_44 << 1 ;
if ( V_42 -> V_45 & V_46 )
V_43 |= 1 ;
V_38 = F_14 ( V_43 ) |
F_15 ( V_47 ) ;
if ( V_34 == 0 ) {
V_38 |= F_16 ( 0 ) |
V_48 ;
}
F_2 ( V_3 , V_49 , V_38 ) ;
V_36 ++ ;
V_31 [ V_34 ] = V_36 ;
if ( V_42 -> V_45 & V_46 ) {
V_36 += V_42 -> V_50 ;
} else {
for ( V_35 = 0 ; V_35 < V_42 -> V_50 ; V_35 ++ ) {
V_38 = F_14 ( V_42 -> V_51 [ V_35 ] ) |
F_15 ( V_47 ) ;
F_2 ( V_3 , V_49 , V_38 ) ;
V_36 ++ ;
}
}
V_39 = F_17 ( V_42 -> V_50 ) |
F_18 (
( V_42 -> V_45 & V_46 ) ? V_52 : V_47 ) |
V_53 ;
if ( V_34 == ( V_25 - 1 ) )
V_39 |= V_54 ;
F_2 ( V_3 , F_19 ( V_34 ) , V_39 ) ;
}
F_2 ( V_3 , V_4 ,
F_20 ( V_25 - 1 ) |
V_55 ) ;
V_33 = F_21 ( V_2 -> V_56 , V_20 ( V_2 ) , V_57 / 4 ) ;
if ( V_33 <= 0 ) {
if ( V_33 == 0 )
V_33 = - V_19 ;
F_22 ( V_12 -> V_12 , L_2 , V_33 ) ;
F_23 ( L_3 ,
F_8 ( V_3 , V_58 ) ,
F_8 ( V_3 , V_59 ) ,
F_8 ( V_3 , V_15 ) ) ;
return V_33 ;
}
V_37 = F_8 ( V_3 , V_58 ) ;
for ( V_34 = 0 ; V_34 < V_25 ; V_34 ++ ) {
struct V_23 * V_42 = & V_24 [ V_34 ] ;
if ( ! ( V_42 -> V_45 & V_46 ) )
continue;
if ( V_37 & V_26 [ V_34 ] ) {
F_23 ( L_4 , V_37 ) ;
break;
}
V_38 = F_15 ( V_52 ) |
F_16 ( V_31 [ V_34 ] ) |
V_48 ;
F_2 ( V_3 , V_49 , V_38 ) ;
F_8 ( V_3 , V_49 ) ;
for ( V_35 = 0 ; V_35 < V_42 -> V_50 ; V_35 ++ ) {
V_38 = F_8 ( V_3 , V_49 ) ;
V_42 -> V_51 [ V_35 ] = F_24 ( V_38 , F_14 ) ;
}
}
return V_34 ;
}
static T_2 F_25 ( struct V_21 * V_60 )
{
return V_61 | V_62 ;
}
void F_26 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_11 ( V_22 ) ;
if ( V_20 ( V_2 ) )
F_27 ( & V_2 -> V_56 ) ;
}
void F_28 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_11 ( V_22 ) ;
F_29 ( V_22 ) ;
F_30 ( V_2 ) ;
}
struct V_21 * F_31 ( struct V_3 * V_3 )
{
struct V_11 * V_12 = V_3 -> V_12 ;
struct V_1 * V_2 ;
struct V_21 * V_22 = NULL ;
int V_33 ;
V_2 = F_32 ( sizeof( * V_2 ) , V_63 ) ;
if ( ! V_2 ) {
V_33 = - V_64 ;
goto V_65;
}
V_22 = & V_2 -> V_66 ;
V_2 -> V_3 = V_3 ;
F_33 ( & V_2 -> V_56 ) ;
V_22 -> V_67 = V_68 ;
V_22 -> V_69 = V_70 ;
snprintf ( V_22 -> V_71 , sizeof( V_22 -> V_71 ) , L_5 ) ;
V_22 -> V_12 . V_72 = & V_3 -> V_73 -> V_12 ;
V_22 -> V_74 = & V_75 ;
V_33 = F_34 ( V_22 ) ;
if ( V_33 ) {
F_9 ( V_12 -> V_12 , L_6 , V_33 ) ;
goto V_65;
}
return V_22 ;
V_65:
if ( V_22 )
F_28 ( V_22 ) ;
return F_35 ( V_33 ) ;
}
