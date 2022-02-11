static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 , V_9 , V_10 , V_11 ;
int V_12 ;
int V_13 = 0 ;
for ( V_8 = 0 ; V_8 < V_6 -> V_8 ; V_8 ++ ) {
V_12 = F_2 ( V_6 -> V_14 ) ;
F_3 ( V_12 , V_2 -> V_15 + V_16 ) ;
for ( V_9 = 0 ; V_9 < V_17 ; V_9 ++ ) {
V_13 = F_4 ( V_2 -> V_15 + V_16 ) ;
F_5 ( 10 ) ;
if ( V_13 & V_18 )
break;
}
if ( V_9 >= V_17 )
return - V_19 ;
V_10 = F_4 ( V_2 -> V_15 + V_20 ) ;
V_11 = F_4 ( V_2 -> V_15 + V_20 ) ;
V_7 [ V_8 ] = ( V_10 << 4 ) | ( V_11 >> 4 ) ;
}
return V_8 ;
}
static int F_6 ( unsigned int * V_21 , unsigned int V_22 )
{
int V_9 ;
unsigned int V_23 ;
V_23 = 10000 ;
for ( V_9 = 0 ; V_9 < 8 ; V_9 ++ ) {
if ( ( 2 * ( * V_21 ) ) < ( V_23 * 11 ) )
break;
V_23 *= 10 ;
}
* V_21 = V_23 ;
return V_9 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_24 * V_25 )
{
int V_26 = 0 ;
int V_27 ;
V_26 |= F_8 ( & V_25 -> V_28 , V_29 ) ;
V_26 |= F_8 ( & V_25 -> V_30 , V_31 ) ;
V_26 |= F_8 ( & V_25 -> V_32 , V_29 ) ;
V_26 |= F_8 ( & V_25 -> V_33 , V_34 ) ;
V_26 |= F_8 ( & V_25 -> V_35 , V_34 | V_36 ) ;
if ( V_26 )
return 1 ;
V_26 |= F_9 ( V_25 -> V_35 ) ;
if ( V_26 )
return 2 ;
V_26 |= F_10 ( & V_25 -> V_37 , 0 ) ;
V_26 |= F_11 ( & V_25 -> V_38 , 1000000000 ) ;
V_26 |= F_12 ( & V_25 -> V_38 ,
V_39 ) ;
V_26 |= F_10 ( & V_25 -> V_40 , V_25 -> V_41 ) ;
if ( V_25 -> V_35 == V_34 )
V_26 |= F_12 ( & V_25 -> V_42 , 2 ) ;
else
V_26 |= F_10 ( & V_25 -> V_42 , 0 ) ;
if ( V_26 )
return 3 ;
V_27 = V_25 -> V_38 ;
F_6 ( & V_25 -> V_38 , V_25 -> V_22 & V_43 ) ;
if ( V_27 != V_25 -> V_38 )
V_26 ++ ;
if ( V_26 )
return 4 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_44 * V_45 = V_2 -> V_46 ;
struct V_24 * V_25 = & V_4 -> V_47 -> V_25 ;
int V_12 ;
int V_48 ;
V_48 =
F_6 ( & V_25 -> V_38 ,
V_25 -> V_22 & V_43 ) ;
V_12 = F_2 ( V_25 -> V_49 [ 0 ] ) ;
V_45 -> V_50 = V_25 -> V_42 ;
F_3 ( V_12 | V_51 | ( V_48 << 5 ) , V_2 -> V_15 + V_16 ) ;
return 0 ;
}
static T_1 F_14 ( int V_52 , void * V_53 )
{
int V_11 , V_10 ;
struct V_1 * V_2 = V_53 ;
struct V_44 * V_45 = V_2 -> V_46 ;
struct V_3 * V_4 = V_2 -> V_54 ;
int V_7 ;
if ( ! V_2 -> V_55 ) {
F_15 ( V_2 , L_1 ) ;
return V_56 ;
}
V_10 = F_4 ( V_2 -> V_15 + V_20 ) ;
V_11 = F_4 ( V_2 -> V_15 + V_20 ) ;
V_7 = ( V_10 << 4 ) | ( V_11 >> 4 ) ;
if ( ! ( -- V_45 -> V_50 ) ) {
int V_9 ;
F_3 ( 0 , V_2 -> V_15 + V_16 ) ;
for ( V_9 = 0 ; V_9 < V_17 ; V_9 ++ ) {
if ( F_4 ( V_2 -> V_15 + V_16 ) & V_18 )
break;
}
F_4 ( V_2 -> V_15 + V_20 ) ;
F_4 ( V_2 -> V_15 + V_20 ) ;
V_4 -> V_47 -> V_57 |= V_58 ;
}
F_16 ( V_2 , V_4 ) ;
return V_56 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_59 * V_60 )
{
struct V_44 * V_45 ;
struct V_3 * V_4 ;
int V_61 ;
int V_9 ;
V_61 = F_18 ( V_2 , V_60 -> V_62 [ 0 ] , V_63 ) ;
if ( V_61 )
return V_61 ;
F_3 ( 0 , V_2 -> V_15 + V_16 ) ;
F_5 ( 100 ) ;
if ( F_4 ( V_2 -> V_15 + V_16 ) & V_64 ) {
F_19 ( V_2 -> V_65 , L_2 ) ;
return - V_66 ;
}
V_9 = F_4 ( V_2 -> V_15 + V_20 ) ;
V_9 = F_4 ( V_2 -> V_15 + V_20 ) ;
if ( V_60 -> V_62 [ 1 ] ) {
V_61 = F_20 ( V_60 -> V_62 [ 1 ] , F_14 , 0 ,
V_2 -> V_67 , V_2 ) ;
if ( V_61 == 0 )
V_2 -> V_52 = V_60 -> V_62 [ 1 ] ;
}
V_61 = F_21 ( V_2 , 1 ) ;
if ( V_61 )
return V_61 ;
V_45 = F_22 ( V_2 , sizeof( * V_45 ) ) ;
if ( ! V_45 )
return - V_68 ;
V_4 = & V_2 -> V_69 [ 0 ] ;
V_4 -> type = V_70 ;
V_4 -> V_71 = V_72 | V_73 ;
V_4 -> V_74 = 16 ;
V_4 -> V_75 = F_1 ;
V_4 -> V_76 = 0xfff ;
V_4 -> V_77 = & V_78 ;
if ( V_2 -> V_52 ) {
V_2 -> V_54 = V_4 ;
V_4 -> V_71 |= V_79 ;
V_4 -> V_80 = 1 ;
V_4 -> V_81 = F_13 ;
V_4 -> V_82 = F_7 ;
}
return 0 ;
}
