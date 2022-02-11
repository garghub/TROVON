static int F_1 ( T_1 V_1 )
{
int V_2 ;
if ( V_1 == 0 )
return 0 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
if ( ( V_1 >> V_2 ) == V_4 )
break;
}
return V_2 + 1 ;
}
static inline int F_2 ( int V_5 )
{
return V_4 << ( V_5 - 1 ) ;
}
static void F_3 ( struct V_6 * V_7 )
{
F_4 ( V_7 , V_8 , V_9 ) ;
F_4 ( V_7 , V_8 , V_10 ) ;
}
static int F_5 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_15 * V_16 = F_6 ( V_12 ) ;
struct V_6 * V_7 = V_16 -> V_7 ;
T_1 V_17 [ V_18 ] ;
int V_19 ;
F_3 ( V_7 ) ;
V_19 = F_7 ( V_7 , V_20 , V_17 , V_18 ) ;
if ( V_19 )
return V_19 ;
V_14 -> V_21 = V_17 [ V_22 ] ;
V_14 -> V_23 = V_17 [ V_24 ] ;
V_14 -> V_25 = V_17 [ V_26 ] ;
V_14 -> V_27 = V_17 [ V_28 ] ;
V_14 -> V_29 = V_17 [ V_30 ] - V_31 ;
V_14 -> V_32 = V_17 [ V_33 ] + V_34 - 1900 ;
V_14 -> V_5 = F_1 ( V_17 [ V_35 ] ) ;
return 0 ;
}
static int F_8 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_15 * V_16 = F_6 ( V_12 ) ;
struct V_6 * V_7 = V_16 -> V_7 ;
T_1 V_17 [ V_18 - 1 ] ;
int V_19 , V_2 , V_36 ;
V_36 = V_14 -> V_32 + 1900 - V_34 ;
if ( V_36 < 0 ) {
F_9 ( V_7 -> V_12 , L_1 , V_36 ) ;
return - V_37 ;
}
V_17 [ V_22 ] = V_14 -> V_21 ;
V_17 [ V_24 ] = V_14 -> V_23 ;
V_17 [ V_26 ] = V_14 -> V_25 ;
V_17 [ V_28 ] = V_14 -> V_27 ;
V_17 [ V_30 ] = V_14 -> V_29 + V_31 ;
V_17 [ V_33 ] = V_36 ;
for ( V_2 = 0 ; V_2 < F_10 ( V_17 ) ; V_2 ++ ) {
V_19 = F_4 ( V_7 , V_20 + V_2 , V_17 [ V_2 ] ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static int F_11 ( struct V_11 * V_12 , struct V_38 * V_39 )
{
struct V_15 * V_16 = F_6 ( V_12 ) ;
struct V_6 * V_7 = V_16 -> V_7 ;
struct V_13 * V_14 = & V_39 -> time ;
T_1 V_40 , V_17 [ V_18 ] ;
int V_19 ;
V_40 = V_41 [ V_16 -> V_39 ] ;
V_19 = F_7 ( V_7 , V_40 , V_17 , V_18 ) ;
if ( V_19 )
return V_19 ;
V_14 -> V_21 = V_17 [ V_22 ] ;
V_14 -> V_23 = V_17 [ V_24 ] ;
V_14 -> V_25 = V_17 [ V_26 ] ;
V_14 -> V_27 = V_17 [ V_28 ] ;
V_14 -> V_29 = V_17 [ V_30 ] - V_31 ;
V_14 -> V_32 = V_17 [ V_33 ] + V_34 - 1900 ;
V_14 -> V_5 = F_1 ( V_17 [ V_35 ] ) ;
V_39 -> V_42 = V_17 [ V_35 ] & V_43 ;
return 0 ;
}
static int F_12 ( struct V_11 * V_12 , struct V_38 * V_39 )
{
struct V_15 * V_16 = F_6 ( V_12 ) ;
struct V_6 * V_7 = V_16 -> V_7 ;
struct V_13 * V_14 = & V_39 -> time ;
T_1 V_40 , V_17 [ V_18 ] ;
int V_19 , V_2 , V_36 ;
V_36 = V_14 -> V_32 + 1900 - V_34 ;
if ( V_36 < 0 ) {
F_9 ( V_7 -> V_12 , L_1 , V_36 ) ;
return - V_37 ;
}
V_17 [ V_22 ] = V_14 -> V_21 ;
V_17 [ V_24 ] = V_14 -> V_23 ;
V_17 [ V_26 ] = V_14 -> V_25 ;
V_17 [ V_28 ] = V_14 -> V_27 ;
V_17 [ V_30 ] = V_14 -> V_29 + V_31 ;
V_17 [ V_33 ] = V_36 ;
V_17 [ V_35 ] = F_2 ( V_14 -> V_5 ) ;
for ( V_2 = 0 ; V_2 < F_10 ( V_17 ) ; V_2 ++ ) {
V_40 = V_41 [ V_16 -> V_39 ] + V_2 ;
V_19 = F_4 ( V_7 , V_40 , V_17 [ V_2 ] ) ;
if ( V_19 )
return V_19 ;
}
V_39 -> V_42 = 1 ;
V_40 = V_44 [ V_16 -> V_39 ] ;
return F_13 ( V_7 , V_40 , V_43 ,
V_39 -> V_42 << V_45 ) ;
}
static int F_14 ( struct V_11 * V_12 , unsigned int V_46 )
{
struct V_15 * V_16 = F_6 ( V_12 ) ;
struct V_6 * V_7 = V_16 -> V_7 ;
T_1 V_47 , V_48 ;
if ( ! V_16 -> V_49 )
return - V_50 ;
V_47 = V_51 [ V_16 -> V_39 ] ;
V_48 = V_52 [ V_16 -> V_39 ] ;
return F_13 ( V_7 , V_53 , V_47 , V_46 << V_48 ) ;
}
static T_2 F_15 ( int V_49 , void * V_54 )
{
struct V_15 * V_16 = V_54 ;
F_16 ( V_16 -> V_55 , 1 , V_56 ) ;
return V_57 ;
}
static int F_17 ( struct V_58 * V_59 ,
struct V_15 * V_16 )
{
struct V_60 * V_61 ;
struct V_6 * V_7 = V_16 -> V_7 ;
struct V_62 * V_63 = V_7 -> V_63 ;
int V_49 ;
V_16 -> V_49 = 0 ;
V_61 = F_18 ( V_59 , V_64 , V_65 ) ;
if ( ! V_61 )
return 0 ;
if ( V_16 -> V_39 == V_66 )
V_49 = V_61 -> V_67 ;
else
V_49 = V_61 -> V_68 ;
V_16 -> V_49 = F_19 ( V_63 , V_49 ) ;
return F_20 ( & V_59 -> V_12 , V_16 -> V_49 , NULL ,
F_15 ,
0 , V_65 , V_16 ) ;
}
static int F_21 ( struct V_58 * V_59 )
{
struct V_6 * V_7 = F_6 ( V_59 -> V_12 . V_69 ) ;
struct V_15 * V_16 ;
struct V_11 * V_12 = & V_59 -> V_12 ;
V_16 = F_22 ( V_12 , sizeof( struct V_15 ) , V_70 ) ;
if ( ! V_16 )
return - V_71 ;
V_16 -> V_7 = V_7 ;
V_16 -> V_39 = V_7 -> V_72 ? V_7 -> V_72 -> V_73 : V_74 ;
F_23 ( V_59 , V_16 ) ;
F_24 ( V_12 , 1 ) ;
V_16 -> V_55 = F_25 ( L_2 , V_12 ,
& V_75 , V_76 ) ;
if ( F_26 ( V_16 -> V_55 ) ) {
F_9 ( V_12 , L_3 ) ;
return F_27 ( V_16 -> V_55 ) ;
}
if ( F_17 ( V_59 , V_16 ) )
F_28 ( V_7 -> V_12 , L_4 ) ;
return 0 ;
}
static int F_29 ( struct V_58 * V_59 )
{
struct V_15 * V_16 = F_30 ( V_59 ) ;
F_31 ( V_16 -> V_55 ) ;
F_23 ( V_59 , NULL ) ;
return 0 ;
}
