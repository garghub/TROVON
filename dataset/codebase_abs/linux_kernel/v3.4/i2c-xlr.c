static inline void F_1 ( T_1 T_2 * V_1 , unsigned int V_2 , T_1 V_3 )
{
F_2 ( V_3 , V_1 + V_2 ) ;
}
static inline T_1 F_3 ( T_1 T_2 * V_1 , unsigned int V_2 )
{
return F_4 ( V_1 + V_2 ) ;
}
static int F_5 ( struct V_4 * V_5 , T_3 V_6 ,
T_4 * V_7 , T_3 V_8 )
{
struct V_9 * V_10 = & V_5 -> V_10 ;
unsigned long V_11 , V_12 , V_13 ;
T_1 V_14 ;
int V_15 , V_16 ;
T_4 V_17 , V_18 ;
V_17 = V_7 [ 0 ] ;
F_1 ( V_5 -> V_19 , V_20 , V_17 ) ;
F_1 ( V_5 -> V_19 , V_21 , V_8 ) ;
F_1 ( V_5 -> V_19 , V_22 , V_23 ) ;
F_1 ( V_5 -> V_19 , V_24 , V_6 - 1 ) ;
V_11 = F_6 ( V_25 ) ;
V_12 = V_26 + V_11 ;
V_16 = 0 ;
V_15 = 1 ;
V_27:
if ( V_6 == 1 ) {
F_1 ( V_5 -> V_19 , V_28 ,
V_29 ) ;
} else {
F_1 ( V_5 -> V_19 , V_30 , V_7 [ V_15 ] ) ;
F_1 ( V_5 -> V_19 , V_28 ,
V_31 ) ;
}
while ( ! V_16 ) {
V_13 = V_26 ;
V_14 = F_3 ( V_5 -> V_19 , V_32 ) ;
if ( V_14 & V_33 ) {
V_15 ++ ;
V_18 = ( V_15 < V_6 ) ? V_7 [ V_15 ] : 0 ;
F_1 ( V_5 -> V_19 , V_30 , V_18 ) ;
V_12 = V_26 + V_11 ;
}
V_16 = F_7 ( V_13 , V_12 ) ;
if ( V_14 & V_34 ) {
if ( V_16 )
break;
goto V_27;
}
if ( V_14 & V_35 )
return - V_36 ;
if ( ( V_14 & V_37 ) == 0 && V_15 >= V_6 )
return 0 ;
}
F_8 ( & V_10 -> V_38 , L_1 ) ;
return - V_39 ;
}
static int F_9 ( struct V_4 * V_5 , T_3 V_6 , T_4 * V_7 , T_3 V_8 )
{
struct V_9 * V_10 = & V_5 -> V_10 ;
T_1 V_14 ;
unsigned long V_11 , V_12 , V_13 ;
int V_40 , V_16 ;
T_4 V_18 ;
F_1 ( V_5 -> V_19 , V_22 , V_41 ) ;
F_1 ( V_5 -> V_19 , V_24 , V_6 ) ;
F_1 ( V_5 -> V_19 , V_21 , V_8 ) ;
V_11 = F_6 ( V_25 ) ;
V_12 = V_26 + V_11 ;
V_16 = 0 ;
V_40 = 0 ;
V_27:
F_1 ( V_5 -> V_19 , V_28 , V_42 ) ;
while ( ! V_16 ) {
V_13 = V_26 ;
V_14 = F_3 ( V_5 -> V_19 , V_32 ) ;
if ( V_14 & V_43 ) {
if ( V_40 > V_6 )
return - V_36 ;
V_18 = F_3 ( V_5 -> V_19 , V_44 ) ;
if ( V_40 < V_6 )
V_7 [ V_40 ] = V_18 ;
V_40 ++ ;
V_12 = V_26 + V_11 ;
}
V_16 = F_7 ( V_13 , V_12 ) ;
if ( V_14 & V_34 ) {
if ( V_16 )
break;
goto V_27;
}
if ( V_14 & V_35 )
return - V_36 ;
if ( ( V_14 & V_37 ) == 0 )
return 0 ;
}
F_8 ( & V_10 -> V_38 , L_2 ) ;
return - V_39 ;
}
static int F_10 ( struct V_9 * V_10 ,
struct V_45 * V_46 , int V_47 )
{
struct V_45 * V_48 ;
int V_49 ;
int V_50 = 0 ;
struct V_4 * V_5 = F_11 ( V_10 ) ;
for ( V_49 = 0 ; V_50 == 0 && V_49 < V_47 ; V_49 ++ ) {
V_48 = & V_46 [ V_49 ] ;
if ( V_48 -> V_51 & V_52 )
V_50 = F_9 ( V_5 , V_48 -> V_6 , & V_48 -> V_7 [ 0 ] ,
V_48 -> V_8 ) ;
else
V_50 = F_5 ( V_5 , V_48 -> V_6 , & V_48 -> V_7 [ 0 ] ,
V_48 -> V_8 ) ;
}
return ( V_50 != 0 ) ? V_50 : V_47 ;
}
static T_1 F_12 ( struct V_9 * V_10 )
{
return V_53 | V_54 ;
}
static int T_5 F_13 ( struct V_55 * V_56 )
{
struct V_4 * V_5 ;
struct V_57 * V_58 ;
int V_50 ;
V_5 = F_14 ( & V_56 -> V_38 , sizeof( * V_5 ) , V_59 ) ;
if ( ! V_5 )
return - V_60 ;
V_58 = F_15 ( V_56 , V_61 , 0 ) ;
V_5 -> V_19 = F_16 ( & V_56 -> V_38 , V_58 ) ;
if ( ! V_5 -> V_19 ) {
F_8 ( & V_56 -> V_38 , L_3 ) ;
return - V_62 ;
}
V_5 -> V_10 . V_38 . V_63 = & V_56 -> V_38 ;
V_5 -> V_10 . V_64 = V_65 ;
V_5 -> V_10 . V_66 = V_5 ;
V_5 -> V_10 . V_67 = & V_68 ;
V_5 -> V_10 . V_69 = V_56 -> V_70 ;
V_5 -> V_10 . V_71 = V_72 ;
snprintf ( V_5 -> V_10 . V_73 , sizeof( V_5 -> V_10 . V_73 ) , L_4 ) ;
F_17 ( & V_5 -> V_10 , V_5 ) ;
V_50 = F_18 ( & V_5 -> V_10 ) ;
if ( V_50 < 0 ) {
F_8 ( & V_5 -> V_10 . V_38 , L_5 ) ;
return V_50 ;
}
F_19 ( V_56 , V_5 ) ;
F_20 ( & V_5 -> V_10 . V_38 , L_6 ) ;
return 0 ;
}
static int T_6 F_21 ( struct V_55 * V_56 )
{
struct V_4 * V_5 ;
V_5 = F_22 ( V_56 ) ;
F_23 ( & V_5 -> V_10 ) ;
F_19 ( V_56 , NULL ) ;
return 0 ;
}
