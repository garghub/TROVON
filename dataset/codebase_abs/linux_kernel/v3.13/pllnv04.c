static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 ,
int * V_6 , int * V_7 , int * V_8 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
int V_11 = V_4 -> V_12 . V_13 , V_14 = V_4 -> V_12 . V_15 ;
int V_16 = V_4 -> V_12 . V_17 , V_18 = V_4 -> V_12 . V_19 ;
int V_20 = V_4 -> V_12 . V_21 , V_22 = V_4 -> V_12 . V_23 ;
int V_24 = V_4 -> V_12 . V_25 ;
int V_26 = V_4 -> V_12 . V_27 ;
int V_28 = V_4 -> V_29 ;
int V_30 = V_4 -> V_31 ;
int V_32 = V_4 -> V_33 ;
int V_34 , V_35 , V_36 , V_37 ;
int V_38 , V_39 ;
int V_40 , V_41 = V_42 ;
int V_43 = 0 ;
if ( V_10 -> V_44 . V_45 < 0x60 ) {
int V_46 = V_10 -> V_44 . V_47 ;
if ( V_46 < 0x17 || V_46 == 0x1a || V_46 == 0x20 ) {
if ( V_5 > 250000 )
V_18 = 6 ;
if ( V_5 > 340000 )
V_18 = 2 ;
} else if ( V_46 < 0x40 ) {
if ( V_5 > 150000 )
V_18 = 6 ;
if ( V_5 > 200000 )
V_18 = 4 ;
if ( V_5 > 340000 )
V_18 = 2 ;
}
}
V_37 = 1 << V_30 ;
if ( ( V_5 * V_37 ) < V_11 ) {
V_11 = V_5 * V_30 ;
V_14 = V_11 * 2 ;
}
if ( V_5 + V_5 / 200 > V_14 )
V_14 = V_5 + V_5 / 200 ;
for ( V_36 = V_28 ; V_36 <= V_30 ; V_36 ++ ) {
V_37 = 1 << V_36 ;
V_38 = V_5 * V_37 ;
if ( V_38 < V_11 )
continue;
if ( V_38 > V_14 )
return V_43 ;
for ( V_34 = V_16 ; V_34 <= V_18 ; V_34 ++ ) {
if ( V_32 / V_34 < V_24 )
return V_43 ;
if ( V_32 / V_34 > V_26 )
continue;
V_35 = ( V_38 * V_34 + V_32 / 2 ) / V_32 ;
if ( V_35 < V_20 )
continue;
if ( V_35 > V_22 )
break;
V_39 = ( ( V_35 * V_32 + V_37 / 2 ) / V_37 + V_34 / 2 ) / V_34 ;
V_40 = abs ( V_39 - V_5 ) ;
if ( V_40 < V_41 ) {
V_41 = V_40 ;
V_43 = V_39 ;
* V_6 = V_35 ;
* V_7 = V_34 ;
* V_8 = V_36 ;
if ( V_40 == 0 )
return V_43 ;
}
}
}
return V_43 ;
}
static int
F_2 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 ,
int * V_48 , int * V_49 , int * V_50 , int * V_51 , int * V_8 )
{
int V_52 = V_9 ( V_2 ) -> V_44 . V_47 ;
int V_53 = V_4 -> V_12 . V_13 , V_54 = V_4 -> V_12 . V_15 ;
int V_55 = V_4 -> V_56 . V_13 , V_57 = V_4 -> V_56 . V_15 ;
int V_58 = V_4 -> V_12 . V_25 , V_59 = V_4 -> V_56 . V_25 ;
int V_60 = V_4 -> V_12 . V_27 , V_61 = V_4 -> V_56 . V_27 ;
int V_62 = V_4 -> V_12 . V_17 , V_63 = V_4 -> V_12 . V_19 ;
int V_64 = V_4 -> V_12 . V_21 , V_65 = V_4 -> V_12 . V_23 ;
int V_66 = V_4 -> V_56 . V_17 , V_67 = V_4 -> V_56 . V_19 ;
int V_68 = V_4 -> V_56 . V_21 , V_69 = V_4 -> V_56 . V_23 ;
int V_70 = V_4 -> V_31 ;
int V_32 = V_4 -> V_33 ;
bool V_71 = ( V_66 == V_67 && V_68 == V_69 ) ;
int V_72 , V_73 , V_74 , V_75 , V_76 ;
int V_38 , V_77 , V_78 , V_79 ;
int V_40 , V_41 = V_42 ;
int V_43 = 0 ;
int V_56 = ( V_57 - V_57 / 200 ) / 2 ;
for ( V_76 = 0 ; V_5 && V_76 < V_70 && V_5 <= ( V_56 >> V_76 ) ; V_76 ++ )
;
V_38 = V_5 << V_76 ;
if ( V_57 < V_5 + V_5 / 200 )
V_57 = V_5 + V_5 / 200 ;
for ( V_72 = V_62 ; V_72 <= V_63 ; V_72 ++ ) {
if ( V_32 / V_72 < V_58 )
return V_43 ;
if ( V_32 / V_72 > V_60 )
continue;
for ( V_73 = V_64 ; V_73 <= V_65 ; V_73 ++ ) {
V_77 = V_32 * V_73 / V_72 ;
if ( V_77 < V_53 )
continue;
if ( V_77 > V_54 )
break;
for ( V_74 = V_66 ; V_74 <= V_67 ; V_74 ++ ) {
if ( V_77 / V_74 < V_59 )
break;
if ( V_77 / V_74 > V_61 )
continue;
V_75 = ( V_38 * V_74 + V_77 / 2 ) / V_77 ;
if ( V_75 < V_68 )
continue;
if ( V_75 > V_69 )
break;
if ( ! V_71 ) {
if ( V_52 < 0x60 )
if ( V_75 / V_74 < 4 || V_75 / V_74 > 10 )
continue;
V_78 = V_77 * V_75 / V_74 ;
if ( V_78 < V_55 )
break;
if ( V_78 > V_57 )
continue;
} else
V_78 = V_77 ;
V_79 = V_78 >> V_76 ;
V_40 = abs ( V_79 - V_5 ) ;
if ( V_40 < V_41 ) {
V_41 = V_40 ;
V_43 = V_79 ;
* V_48 = V_73 ;
* V_49 = V_72 ;
* V_50 = V_75 ;
* V_51 = V_74 ;
* V_8 = V_76 ;
if ( V_40 == 0 )
return V_43 ;
}
}
}
}
return V_43 ;
}
int
F_3 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 V_80 ,
int * V_73 , int * V_72 , int * V_75 , int * V_74 , int * V_37 )
{
int V_81 ;
if ( ! V_4 -> V_56 . V_15 || ! V_75 ) {
V_81 = F_1 ( V_2 , V_4 , V_80 , V_73 , V_72 , V_37 ) ;
if ( V_75 ) {
* V_75 = 1 ;
* V_74 = 1 ;
}
} else {
V_81 = F_2 ( V_2 , V_4 , V_80 , V_73 , V_72 , V_75 , V_74 , V_37 ) ;
}
if ( ! V_81 )
F_4 ( V_2 , L_1 ) ;
return V_81 ;
}
