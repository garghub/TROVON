static int F_1 ( struct V_1 * V_2 ,
T_1 * V_3 )
{
int V_4 ;
T_1 V_5 ;
V_3 -> V_6 . V_7 = 1 ;
F_2 ( L_1 , V_3 -> V_8 ) ;
V_2 -> V_9 ( V_2 , V_6 , V_10 ) ;
V_2 -> V_9 ( V_2 , V_6 , * V_3 ) ;
for ( V_4 = 0 ; V_4 < V_11 ; V_4 ++ ) {
V_5 = V_2 -> V_12 ( V_2 , V_6 ) ;
if ( ! V_5 . V_6 . V_13 ) {
if ( V_5 . V_6 . V_14 ) {
* V_3 = V_5 ;
F_2 ( L_2 ) ;
return 0 ;
}
} else {
F_2 ( L_3 ) ;
return - V_15 ;
}
}
F_2 ( L_4 ,
V_4 ) ;
return - V_15 ;
}
static int F_3 ( struct V_16 * V_17 ,
T_1 V_3 , T_2 * V_18 )
{
T_1 V_19 ;
int V_20 = V_3 . V_6 . V_21 ,
V_22 ;
if ( V_17 -> V_2 -> V_23 == V_24 )
V_3 . V_6 . V_13 = V_17 -> V_25 ;
V_22 = F_1 ( V_17 -> V_2 , & V_3 ) ;
if ( V_22 != 0 ) {
F_2 ( L_5 ) ;
V_3 . V_6 . V_13 = V_17 -> V_25 ;
V_22 = F_1 ( V_17 -> V_2 , & V_3 ) ;
}
if ( V_22 != 0 ) {
F_2 ( L_6 , V_22 ) ;
return V_22 ;
}
V_18 [ 0 ] = V_3 . V_6 . V_26 ;
if ( V_20 > 0 ) {
V_19 = V_17 -> V_2 -> V_12 ( V_17 -> V_2 , V_27 ) ;
F_2 ( L_7 , V_3 . V_8 , V_19 . V_8 ) ;
V_18 [ 1 ] = V_19 . V_27 . V_28 ;
if ( V_20 > 1 ) V_18 [ 2 ] = V_19 . V_27 . V_29 ;
if ( V_20 > 2 ) V_18 [ 3 ] = V_19 . V_27 . V_30 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 * V_18 )
{
T_1 V_19 ;
int V_20 = V_3 . V_6 . V_21 ;
V_19 . V_8 = 0 ;
V_3 . V_6 . V_26 = V_18 [ 0 ] ;
V_19 . V_27 . V_28 = V_20 > 0 ? V_18 [ 1 ] : 0 ;
V_19 . V_27 . V_29 = V_20 > 1 ? V_18 [ 2 ] : 0 ;
V_19 . V_27 . V_30 = V_20 > 2 ? V_18 [ 3 ] : 0 ;
F_2 ( L_8 , V_3 . V_8 , V_19 . V_8 ) ;
V_2 -> V_9 ( V_2 , V_27 , V_19 ) ;
return F_1 ( V_2 , & V_3 ) ;
}
int F_5 ( struct V_16 * V_17 ,
T_3 V_31 , T_2 V_32 , T_2 V_33 , T_2 * V_18 , T_4 V_20 )
{
int V_22 ;
#ifdef F_6
int V_4 ;
#endif
T_4 V_34 ;
T_1 V_3 ;
F_2 ( L_9 , V_31 ) ;
V_3 . V_8 = 0 ;
V_3 . V_6 . V_32 = V_32 ;
V_3 . V_6 . V_35 = V_31 ;
V_3 . V_6 . V_36 = V_17 -> V_37 ;
#ifdef F_6
F_7 ( V_38 L_10 , V_17 -> V_37 ) ;
if ( V_31 == V_39 )
F_7 ( V_40 L_11 ) ;
else
F_7 ( V_40 L_12 ) ;
F_7 ( V_40 L_13 , V_32 , V_33 ) ;
#endif
if ( V_17 -> V_25 && V_20 == 0 && V_31 == V_41 ) {
V_18 = & V_33 ;
V_20 = 1 ;
}
while ( V_20 != 0 ) {
V_34 = V_20 > 4 ? 4 : V_20 ;
V_3 . V_6 . V_21 = V_34 - 1 ;
V_3 . V_6 . V_42 = V_33 ;
if ( V_31 == V_39 )
V_22 = F_3 ( V_17 , V_3 , V_18 ) ;
else
V_22 = F_4 ( V_17 -> V_2 , V_3 , V_18 ) ;
#ifdef F_6
for ( V_4 = 0 ; V_4 < V_34 ; V_4 ++ )
F_7 ( V_40 L_14 , V_18 [ V_4 ] ) ;
#endif
if ( V_22 < 0 )
return V_22 ;
V_18 += V_34 ;
V_33 += V_34 ;
V_20 -= V_34 ;
}
#ifdef F_6
F_7 ( V_40 L_15 ) ;
#endif
return 0 ;
}
static int F_8 ( struct V_43 * V_44 ,
struct V_45 V_46 [] , int V_47 )
{
struct V_16 * V_17 = F_9 ( V_44 ) ;
int V_4 , V_22 = 0 ;
if ( V_47 == 1 && V_46 [ 0 ] . V_48 == V_49 && V_46 [ 0 ] . V_20 <= 1 )
return 1 ;
if ( F_10 ( & V_17 -> V_2 -> V_50 ) )
return - V_51 ;
for ( V_4 = 0 ; V_4 < V_47 ; V_4 ++ ) {
if ( V_4 + 1 < V_47 && ( V_46 [ V_4 + 1 ] . V_48 == V_49 ) ) {
V_22 = V_17 -> V_2 -> V_52 ( V_17 , V_39 , V_46 [ V_4 ] . V_33 ,
V_46 [ V_4 ] . V_18 [ 0 ] , V_46 [ V_4 + 1 ] . V_18 ,
V_46 [ V_4 + 1 ] . V_20 ) ;
V_4 ++ ;
} else
V_22 = V_17 -> V_2 -> V_52 ( V_17 , V_41 , V_46 [ V_4 ] . V_33 ,
V_46 [ V_4 ] . V_18 [ 0 ] , & V_46 [ V_4 ] . V_18 [ 1 ] ,
V_46 [ V_4 ] . V_20 - 1 ) ;
if ( V_22 < 0 ) {
F_2 ( L_16 ) ;
break;
}
}
F_11 ( & V_17 -> V_2 -> V_50 ) ;
if ( V_22 == 0 )
V_22 = V_47 ;
return V_22 ;
}
static T_5 F_12 ( struct V_43 * V_53 )
{
return V_54 ;
}
int F_13 ( struct V_1 * V_2 )
{
int V_22 ;
F_14 ( & V_2 -> V_50 ) ;
V_2 -> V_55 [ 0 ] . V_2 = V_2 ;
V_2 -> V_55 [ 1 ] . V_2 = V_2 ;
V_2 -> V_55 [ 2 ] . V_2 = V_2 ;
V_2 -> V_55 [ 0 ] . V_37 = V_56 ;
V_2 -> V_55 [ 1 ] . V_37 = V_57 ;
V_2 -> V_55 [ 2 ] . V_37 = V_58 ;
F_15 ( V_2 -> V_55 [ 0 ] . V_44 . V_59 , L_17 ,
sizeof( V_2 -> V_55 [ 0 ] . V_44 . V_59 ) ) ;
F_15 ( V_2 -> V_55 [ 1 ] . V_44 . V_59 , L_18 ,
sizeof( V_2 -> V_55 [ 1 ] . V_44 . V_59 ) ) ;
F_15 ( V_2 -> V_55 [ 2 ] . V_44 . V_59 , L_19 ,
sizeof( V_2 -> V_55 [ 2 ] . V_44 . V_59 ) ) ;
F_16 ( & V_2 -> V_55 [ 0 ] . V_44 , & V_2 -> V_55 [ 0 ] ) ;
F_16 ( & V_2 -> V_55 [ 1 ] . V_44 , & V_2 -> V_55 [ 1 ] ) ;
F_16 ( & V_2 -> V_55 [ 2 ] . V_44 , & V_2 -> V_55 [ 2 ] ) ;
V_2 -> V_55 [ 0 ] . V_44 . V_60 =
V_2 -> V_55 [ 1 ] . V_44 . V_60 =
V_2 -> V_55 [ 2 ] . V_44 . V_60 = & V_61 ;
V_2 -> V_55 [ 0 ] . V_44 . V_62 =
V_2 -> V_55 [ 1 ] . V_44 . V_62 =
V_2 -> V_55 [ 2 ] . V_44 . V_62 = NULL ;
V_2 -> V_55 [ 0 ] . V_44 . V_63 . V_64 =
V_2 -> V_55 [ 1 ] . V_44 . V_63 . V_64 =
V_2 -> V_55 [ 2 ] . V_44 . V_63 . V_64 = V_2 -> V_63 ;
V_22 = F_17 ( & V_2 -> V_55 [ 0 ] . V_44 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_17 ( & V_2 -> V_55 [ 1 ] . V_44 ) ;
if ( V_22 < 0 )
goto V_65;
V_22 = F_17 ( & V_2 -> V_55 [ 2 ] . V_44 ) ;
if ( V_22 < 0 )
goto V_66;
V_2 -> V_67 |= V_68 ;
return 0 ;
V_66:
F_18 ( & V_2 -> V_55 [ 1 ] . V_44 ) ;
V_65:
F_18 ( & V_2 -> V_55 [ 0 ] . V_44 ) ;
return V_22 ;
}
void F_19 ( struct V_1 * V_2 )
{
if ( V_2 -> V_67 & V_68 ) {
F_18 ( & V_2 -> V_55 [ 2 ] . V_44 ) ;
F_18 ( & V_2 -> V_55 [ 1 ] . V_44 ) ;
F_18 ( & V_2 -> V_55 [ 0 ] . V_44 ) ;
}
V_2 -> V_67 &= ~ V_68 ;
}
