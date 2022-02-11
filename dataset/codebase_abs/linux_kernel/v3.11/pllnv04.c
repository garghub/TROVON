static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 ,
int * V_6 , int * V_7 , int * V_8 )
{
int V_9 = F_2 ( V_2 ) -> V_10 . V_11 ;
int V_12 = V_4 -> V_13 . V_14 , V_15 = V_4 -> V_13 . V_16 ;
int V_17 = V_4 -> V_13 . V_18 , V_19 = V_4 -> V_13 . V_20 ;
int V_21 = V_4 -> V_13 . V_22 , V_23 = V_4 -> V_13 . V_24 ;
int V_25 = V_4 -> V_13 . V_26 ;
int V_27 = V_4 -> V_13 . V_28 ;
int V_29 = V_4 -> V_30 ;
int V_31 = V_4 -> V_32 ;
int V_33 = V_4 -> V_34 ;
int V_35 , V_36 , V_37 , V_38 ;
int V_39 , V_40 ;
int V_41 , V_42 = V_43 ;
int V_44 = 0 ;
if ( V_9 < 0x17 || V_9 == 0x1a || V_9 == 0x20 ) {
if ( V_5 > 250000 )
V_19 = 6 ;
if ( V_5 > 340000 )
V_19 = 2 ;
} else if ( V_9 < 0x40 ) {
if ( V_5 > 150000 )
V_19 = 6 ;
if ( V_5 > 200000 )
V_19 = 4 ;
if ( V_5 > 340000 )
V_19 = 2 ;
}
V_38 = 1 << V_31 ;
if ( ( V_5 * V_38 ) < V_12 ) {
V_12 = V_5 * V_31 ;
V_15 = V_12 * 2 ;
}
if ( V_5 + V_5 / 200 > V_15 )
V_15 = V_5 + V_5 / 200 ;
for ( V_37 = V_29 ; V_37 <= V_31 ; V_37 ++ ) {
V_38 = 1 << V_37 ;
V_39 = V_5 * V_38 ;
if ( V_39 < V_12 )
continue;
if ( V_39 > V_15 )
return V_44 ;
for ( V_35 = V_17 ; V_35 <= V_19 ; V_35 ++ ) {
if ( V_33 / V_35 < V_25 )
return V_44 ;
if ( V_33 / V_35 > V_27 )
continue;
V_36 = ( V_39 * V_35 + V_33 / 2 ) / V_33 ;
if ( V_36 < V_21 )
continue;
if ( V_36 > V_23 )
break;
V_40 = ( ( V_36 * V_33 + V_38 / 2 ) / V_38 + V_35 / 2 ) / V_35 ;
V_41 = abs ( V_40 - V_5 ) ;
if ( V_41 < V_42 ) {
V_42 = V_41 ;
V_44 = V_40 ;
* V_6 = V_36 ;
* V_7 = V_35 ;
* V_8 = V_37 ;
if ( V_41 == 0 )
return V_44 ;
}
}
}
return V_44 ;
}
static int
F_3 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 ,
int * V_45 , int * V_46 , int * V_47 , int * V_48 , int * V_8 )
{
int V_49 = F_2 ( V_2 ) -> V_10 . V_11 ;
int V_50 = V_4 -> V_13 . V_14 , V_51 = V_4 -> V_13 . V_16 ;
int V_52 = V_4 -> V_53 . V_14 , V_54 = V_4 -> V_53 . V_16 ;
int V_55 = V_4 -> V_13 . V_26 , V_56 = V_4 -> V_53 . V_26 ;
int V_57 = V_4 -> V_13 . V_28 , V_58 = V_4 -> V_53 . V_28 ;
int V_59 = V_4 -> V_13 . V_18 , V_60 = V_4 -> V_13 . V_20 ;
int V_61 = V_4 -> V_13 . V_22 , V_62 = V_4 -> V_13 . V_24 ;
int V_63 = V_4 -> V_53 . V_18 , V_64 = V_4 -> V_53 . V_20 ;
int V_65 = V_4 -> V_53 . V_22 , V_66 = V_4 -> V_53 . V_24 ;
int V_67 = V_4 -> V_32 ;
int V_33 = V_4 -> V_34 ;
bool V_68 = ( V_63 == V_64 && V_65 == V_66 ) ;
int V_69 , V_70 , V_71 , V_72 , V_73 ;
int V_39 , V_74 , V_75 , V_76 ;
int V_41 , V_42 = V_43 ;
int V_44 = 0 ;
int V_53 = ( V_54 - V_54 / 200 ) / 2 ;
for ( V_73 = 0 ; V_5 && V_73 < V_67 && V_5 <= ( V_53 >> V_73 ) ; V_73 ++ )
;
V_39 = V_5 << V_73 ;
if ( V_54 < V_5 + V_5 / 200 )
V_54 = V_5 + V_5 / 200 ;
for ( V_69 = V_59 ; V_69 <= V_60 ; V_69 ++ ) {
if ( V_33 / V_69 < V_55 )
return V_44 ;
if ( V_33 / V_69 > V_57 )
continue;
for ( V_70 = V_61 ; V_70 <= V_62 ; V_70 ++ ) {
V_74 = V_33 * V_70 / V_69 ;
if ( V_74 < V_50 )
continue;
if ( V_74 > V_51 )
break;
for ( V_71 = V_63 ; V_71 <= V_64 ; V_71 ++ ) {
if ( V_74 / V_71 < V_56 )
break;
if ( V_74 / V_71 > V_58 )
continue;
V_72 = ( V_39 * V_71 + V_74 / 2 ) / V_74 ;
if ( V_72 < V_65 )
continue;
if ( V_72 > V_66 )
break;
if ( ! V_68 ) {
if ( V_49 < 0x60 )
if ( V_72 / V_71 < 4 || V_72 / V_71 > 10 )
continue;
V_75 = V_74 * V_72 / V_71 ;
if ( V_75 < V_52 )
break;
if ( V_75 > V_54 )
continue;
} else
V_75 = V_74 ;
V_76 = V_75 >> V_73 ;
V_41 = abs ( V_76 - V_5 ) ;
if ( V_41 < V_42 ) {
V_42 = V_41 ;
V_44 = V_76 ;
* V_45 = V_70 ;
* V_46 = V_69 ;
* V_47 = V_72 ;
* V_48 = V_71 ;
* V_8 = V_73 ;
if ( V_41 == 0 )
return V_44 ;
}
}
}
}
return V_44 ;
}
int
F_4 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 V_77 ,
int * V_70 , int * V_69 , int * V_72 , int * V_71 , int * V_38 )
{
int V_78 ;
if ( ! V_4 -> V_53 . V_16 ) {
V_78 = F_1 ( V_2 , V_4 , V_77 , V_70 , V_69 , V_38 ) ;
* V_72 = 1 ;
* V_71 = 1 ;
} else {
V_78 = F_3 ( V_2 , V_4 , V_77 , V_70 , V_69 , V_72 , V_71 , V_38 ) ;
}
if ( ! V_78 )
F_5 ( V_2 , L_1 ) ;
return V_78 ;
}
