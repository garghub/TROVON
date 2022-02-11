static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_7 )
{
unsigned int V_8 ;
V_8 = F_2 ( V_2 -> V_9 + V_10 ) ;
if ( V_8 & V_11 )
return 0 ;
return - V_12 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_13 )
{
int V_14 , V_15 , V_16 ;
int V_17 ;
int V_18 ;
for ( V_14 = 0 ; V_14 < V_6 -> V_14 ; V_14 ++ ) {
V_17 = F_4 ( V_6 -> V_19 ) ;
F_5 ( V_17 , V_2 -> V_9 + V_10 ) ;
V_18 = F_6 ( V_2 , V_4 , V_6 , F_1 , 0 ) ;
if ( V_18 )
return V_18 ;
V_15 = F_2 ( V_2 -> V_9 + V_20 ) ;
V_16 = F_2 ( V_2 -> V_9 + V_20 ) ;
V_13 [ V_14 ] = ( V_15 << 4 ) | ( V_16 >> 4 ) ;
}
return V_14 ;
}
static int F_7 ( unsigned int * V_21 , unsigned int V_22 )
{
int V_23 ;
unsigned int V_24 ;
V_24 = 10000 ;
for ( V_23 = 0 ; V_23 < 8 ; V_23 ++ ) {
if ( ( 2 * ( * V_21 ) ) < ( V_24 * 11 ) )
break;
V_24 *= 10 ;
}
* V_21 = V_24 ;
return V_23 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_25 * V_26 )
{
int V_27 = 0 ;
unsigned int V_28 ;
V_27 |= F_9 ( & V_26 -> V_29 , V_30 ) ;
V_27 |= F_9 ( & V_26 -> V_31 , V_32 ) ;
V_27 |= F_9 ( & V_26 -> V_33 , V_30 ) ;
V_27 |= F_9 ( & V_26 -> V_34 , V_35 ) ;
V_27 |= F_9 ( & V_26 -> V_36 , V_35 | V_37 ) ;
if ( V_27 )
return 1 ;
V_27 |= F_10 ( V_26 -> V_36 ) ;
if ( V_27 )
return 2 ;
V_27 |= F_11 ( & V_26 -> V_38 , 0 ) ;
V_27 |= F_12 ( & V_26 -> V_39 , 1000000000 ) ;
V_27 |= F_13 ( & V_26 -> V_39 ,
V_40 ) ;
V_27 |= F_11 ( & V_26 -> V_41 , V_26 -> V_42 ) ;
if ( V_26 -> V_36 == V_35 )
V_27 |= F_13 ( & V_26 -> V_43 , 2 ) ;
else
V_27 |= F_11 ( & V_26 -> V_43 , 0 ) ;
if ( V_27 )
return 3 ;
V_28 = V_26 -> V_39 ;
F_7 ( & V_28 , V_26 -> V_22 ) ;
V_27 |= F_11 ( & V_26 -> V_39 , V_28 ) ;
if ( V_27 )
return 4 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_44 * V_45 = V_2 -> V_46 ;
struct V_25 * V_26 = & V_4 -> V_47 -> V_26 ;
int V_17 ;
int V_48 ;
V_48 = F_7 ( & V_26 -> V_39 , V_26 -> V_22 ) ;
V_17 = F_4 ( V_26 -> V_49 [ 0 ] ) ;
V_45 -> V_50 = V_26 -> V_43 ;
F_5 ( V_17 | V_51 | ( V_48 << 5 ) , V_2 -> V_9 + V_10 ) ;
return 0 ;
}
static T_1 F_15 ( int V_52 , void * V_53 )
{
int V_16 , V_15 ;
struct V_1 * V_2 = V_53 ;
struct V_44 * V_45 = V_2 -> V_46 ;
struct V_3 * V_4 = V_2 -> V_54 ;
int V_13 ;
if ( ! V_2 -> V_55 ) {
F_16 ( V_2 -> V_56 , L_1 ) ;
return V_57 ;
}
V_15 = F_2 ( V_2 -> V_9 + V_20 ) ;
V_16 = F_2 ( V_2 -> V_9 + V_20 ) ;
V_13 = ( V_15 << 4 ) | ( V_16 >> 4 ) ;
if ( ! ( -- V_45 -> V_50 ) ) {
int V_23 ;
F_5 ( 0 , V_2 -> V_9 + V_10 ) ;
for ( V_23 = 0 ; V_23 < V_58 ; V_23 ++ ) {
if ( F_2 ( V_2 -> V_9 + V_10 ) & V_11 )
break;
}
F_2 ( V_2 -> V_9 + V_20 ) ;
F_2 ( V_2 -> V_9 + V_20 ) ;
V_4 -> V_47 -> V_59 |= V_60 ;
}
F_17 ( V_2 , V_4 ) ;
return V_57 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_61 * V_62 )
{
struct V_44 * V_45 ;
struct V_3 * V_4 ;
int V_18 ;
int V_23 ;
V_18 = F_19 ( V_2 , V_62 -> V_63 [ 0 ] , 0x2 ) ;
if ( V_18 )
return V_18 ;
F_5 ( 0 , V_2 -> V_9 + V_10 ) ;
F_20 ( 100 ) ;
if ( F_2 ( V_2 -> V_9 + V_10 ) & V_64 ) {
F_16 ( V_2 -> V_56 , L_2 ) ;
return - V_65 ;
}
V_23 = F_2 ( V_2 -> V_9 + V_20 ) ;
V_23 = F_2 ( V_2 -> V_9 + V_20 ) ;
if ( V_62 -> V_63 [ 1 ] ) {
V_18 = F_21 ( V_62 -> V_63 [ 1 ] , F_15 , 0 ,
V_2 -> V_66 , V_2 ) ;
if ( V_18 == 0 )
V_2 -> V_52 = V_62 -> V_63 [ 1 ] ;
}
V_18 = F_22 ( V_2 , 1 ) ;
if ( V_18 )
return V_18 ;
V_45 = F_23 ( V_2 , sizeof( * V_45 ) ) ;
if ( ! V_45 )
return - V_67 ;
V_4 = & V_2 -> V_68 [ 0 ] ;
V_4 -> type = V_69 ;
V_4 -> V_70 = V_71 | V_72 ;
V_4 -> V_73 = 16 ;
V_4 -> V_74 = F_3 ;
V_4 -> V_75 = 0xfff ;
V_4 -> V_76 = & V_77 ;
if ( V_2 -> V_52 ) {
V_2 -> V_54 = V_4 ;
V_4 -> V_70 |= V_78 ;
V_4 -> V_79 = 1 ;
V_4 -> V_80 = F_14 ;
V_4 -> V_81 = F_8 ;
}
return 0 ;
}
