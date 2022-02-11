static int
F_1 ( struct V_1 * clock , struct V_2 * V_3 , int V_4 ,
int * V_5 , int * V_6 , int * V_7 )
{
int V_8 = F_2 ( clock ) -> V_9 . V_10 ;
int V_11 = V_3 -> V_12 . V_13 , V_14 = V_3 -> V_12 . V_15 ;
int V_16 = V_3 -> V_12 . V_17 , V_18 = V_3 -> V_12 . V_19 ;
int V_20 = V_3 -> V_12 . V_21 , V_22 = V_3 -> V_12 . V_23 ;
int V_24 = V_3 -> V_12 . V_25 ;
int V_26 = V_3 -> V_12 . V_27 ;
int V_28 = V_3 -> V_29 ;
int V_30 = V_3 -> V_31 ;
int V_32 = V_3 -> V_33 ;
int V_34 , V_35 , V_36 , V_37 ;
int V_38 , V_39 ;
int V_40 , V_41 = V_42 ;
int V_43 = 0 ;
if ( V_8 < 0x17 || V_8 == 0x1a || V_8 == 0x20 ) {
if ( V_4 > 250000 )
V_18 = 6 ;
if ( V_4 > 340000 )
V_18 = 2 ;
} else if ( V_8 < 0x40 ) {
if ( V_4 > 150000 )
V_18 = 6 ;
if ( V_4 > 200000 )
V_18 = 4 ;
if ( V_4 > 340000 )
V_18 = 2 ;
}
V_37 = 1 << V_30 ;
if ( ( V_4 * V_37 ) < V_11 ) {
V_11 = V_4 * V_30 ;
V_14 = V_11 * 2 ;
}
if ( V_4 + V_4 / 200 > V_14 )
V_14 = V_4 + V_4 / 200 ;
for ( V_36 = V_28 ; V_36 <= V_30 ; V_36 ++ ) {
V_37 = 1 << V_36 ;
V_38 = V_4 * V_37 ;
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
V_40 = abs ( V_39 - V_4 ) ;
if ( V_40 < V_41 ) {
V_41 = V_40 ;
V_43 = V_39 ;
* V_5 = V_35 ;
* V_6 = V_34 ;
* V_7 = V_36 ;
if ( V_40 == 0 )
return V_43 ;
}
}
}
return V_43 ;
}
static int
F_3 ( struct V_1 * clock , struct V_2 * V_3 , int V_4 ,
int * V_44 , int * V_45 , int * V_46 , int * V_47 , int * V_7 )
{
int V_48 = F_2 ( clock ) -> V_9 . V_10 ;
int V_49 = V_3 -> V_12 . V_13 , V_50 = V_3 -> V_12 . V_15 ;
int V_51 = V_3 -> V_52 . V_13 , V_53 = V_3 -> V_52 . V_15 ;
int V_54 = V_3 -> V_12 . V_25 , V_55 = V_3 -> V_52 . V_25 ;
int V_56 = V_3 -> V_12 . V_27 , V_57 = V_3 -> V_52 . V_27 ;
int V_58 = V_3 -> V_12 . V_17 , V_59 = V_3 -> V_12 . V_19 ;
int V_60 = V_3 -> V_12 . V_21 , V_61 = V_3 -> V_12 . V_23 ;
int V_62 = V_3 -> V_52 . V_17 , V_63 = V_3 -> V_52 . V_19 ;
int V_64 = V_3 -> V_52 . V_21 , V_65 = V_3 -> V_52 . V_23 ;
int V_66 = V_3 -> V_31 ;
int V_32 = V_3 -> V_33 ;
bool V_67 = ( V_62 == V_63 && V_64 == V_65 ) ;
int V_68 , V_69 , V_70 , V_71 , V_72 ;
int V_38 , V_73 , V_74 , V_75 ;
int V_40 , V_41 = V_42 ;
int V_43 = 0 ;
int V_52 = ( V_53 - V_53 / 200 ) / 2 ;
for ( V_72 = 0 ; V_4 && V_72 < V_66 && V_4 <= ( V_52 >> V_72 ) ; V_72 ++ )
;
V_38 = V_4 << V_72 ;
if ( V_53 < V_4 + V_4 / 200 )
V_53 = V_4 + V_4 / 200 ;
for ( V_68 = V_58 ; V_68 <= V_59 ; V_68 ++ ) {
if ( V_32 / V_68 < V_54 )
return V_43 ;
if ( V_32 / V_68 > V_56 )
continue;
for ( V_69 = V_60 ; V_69 <= V_61 ; V_69 ++ ) {
V_73 = V_32 * V_69 / V_68 ;
if ( V_73 < V_49 )
continue;
if ( V_73 > V_50 )
break;
for ( V_70 = V_62 ; V_70 <= V_63 ; V_70 ++ ) {
if ( V_73 / V_70 < V_55 )
break;
if ( V_73 / V_70 > V_57 )
continue;
V_71 = ( V_38 * V_70 + V_73 / 2 ) / V_73 ;
if ( V_71 < V_64 )
continue;
if ( V_71 > V_65 )
break;
if ( ! V_67 ) {
if ( V_48 < 0x60 )
if ( V_71 / V_70 < 4 || V_71 / V_70 > 10 )
continue;
V_74 = V_73 * V_71 / V_70 ;
if ( V_74 < V_51 )
break;
if ( V_74 > V_53 )
continue;
} else
V_74 = V_73 ;
V_75 = V_74 >> V_72 ;
V_40 = abs ( V_75 - V_4 ) ;
if ( V_40 < V_41 ) {
V_41 = V_40 ;
V_43 = V_75 ;
* V_44 = V_69 ;
* V_45 = V_68 ;
* V_46 = V_71 ;
* V_47 = V_70 ;
* V_7 = V_72 ;
if ( V_40 == 0 )
return V_43 ;
}
}
}
}
return V_43 ;
}
int
F_4 ( struct V_1 * V_4 , struct V_2 * V_3 , T_1 V_76 ,
int * V_69 , int * V_68 , int * V_71 , int * V_70 , int * V_37 )
{
int V_77 ;
if ( ! V_3 -> V_52 . V_15 ) {
V_77 = F_1 ( V_4 , V_3 , V_76 , V_69 , V_68 , V_37 ) ;
* V_71 = 1 ;
* V_70 = 1 ;
} else {
V_77 = F_3 ( V_4 , V_3 , V_76 , V_69 , V_68 , V_71 , V_70 , V_37 ) ;
}
if ( ! V_77 )
F_5 ( V_4 , L_1 ) ;
return V_77 ;
}
