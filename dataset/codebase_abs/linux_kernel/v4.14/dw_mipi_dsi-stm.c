static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
F_1 ( V_2 , V_3 , F_3 ( V_2 , V_3 ) | V_6 ) ;
}
static inline void F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
F_1 ( V_2 , V_3 , F_3 ( V_2 , V_3 ) & ~ V_6 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_6 , T_1 V_4 )
{
F_1 ( V_2 , V_3 , ( F_3 ( V_2 , V_3 ) & ~ V_6 ) | V_4 ) ;
}
static enum V_7 F_8 ( enum V_8 V_9 )
{
switch ( V_9 ) {
case V_10 :
return V_11 ;
case V_12 :
return V_13 ;
case V_14 :
return V_15 ;
case V_16 :
return V_17 ;
default:
F_9 ( L_1 ) ;
}
return V_11 ;
}
static int F_10 ( int V_18 , int V_19 , int V_20 , int V_21 )
{
if ( V_19 * V_21 )
return F_11 ( V_18 * V_20 , V_19 * V_21 ) ;
return 0 ;
}
static int F_12 ( int V_18 , int V_22 ,
int * V_19 , int * V_20 , int * V_21 )
{
int V_23 , V_24 , V_25 , V_26 , V_27 ;
int V_28 , V_29 , V_30 , V_31 ;
if ( ( V_18 <= 0 ) || ( V_22 <= 0 ) )
return - V_32 ;
V_28 = V_33 * 2 * V_34 ;
V_29 = V_35 * 2 * V_36 ;
V_31 = 1000000 ;
for ( V_23 = V_37 ; V_23 <= V_38 ; V_23 ++ ) {
V_26 = ( ( V_28 * V_23 ) / ( 2 * V_18 ) ) + 1 ;
V_27 = ( V_29 * V_23 ) / ( 2 * V_18 ) ;
if ( V_26 >= V_39 )
break;
if ( V_26 < V_40 )
V_26 = V_40 ;
if ( V_27 > V_39 )
V_27 = V_39 ;
for ( V_24 = V_36 ; V_24 <= V_34 ; V_24 *= 2 ) {
V_25 = F_11 ( V_23 * V_24 * V_22 , V_18 ) ;
if ( ( V_25 < V_26 ) || ( V_25 > V_27 ) )
continue;
V_30 = F_10 ( V_18 , V_23 , V_25 , V_24 ) -
V_22 ;
if ( V_30 < 0 )
V_30 = - V_30 ;
if ( V_30 < V_31 ) {
* V_19 = V_23 ;
* V_20 = V_25 ;
* V_21 = V_24 ;
V_31 = V_30 ;
}
if ( ! V_30 )
return 0 ;
}
}
return 0 ;
}
static int F_13 ( void * V_41 )
{
struct V_1 * V_2 = V_41 ;
T_1 V_4 ;
int V_42 ;
F_5 ( V_2 , V_43 , V_44 | V_45 ) ;
V_42 = F_14 ( V_2 -> V_5 + V_46 , V_4 , V_4 & V_47 ,
V_48 , V_49 ) ;
if ( V_42 )
F_9 ( L_2 ) ;
F_5 ( V_2 , V_43 , V_50 ) ;
V_42 = F_14 ( V_2 -> V_5 + V_46 , V_4 , V_4 & V_51 ,
V_48 , V_49 ) ;
if ( V_42 )
F_9 ( L_3 ) ;
F_5 ( V_2 , V_52 , V_53 ) ;
return 0 ;
}
static int
F_15 ( void * V_41 , struct V_54 * V_55 ,
unsigned long V_56 , T_1 V_57 , T_1 V_58 ,
unsigned int * V_59 )
{
struct V_1 * V_2 = V_41 ;
unsigned int V_19 , V_20 , V_21 , V_60 , V_61 ;
int V_42 , V_62 ;
T_1 V_4 ;
V_60 = ( unsigned int ) ( F_16 ( V_2 -> V_63 ) / 1000 ) ;
V_62 = F_17 ( V_58 ) ;
V_61 = V_55 -> clock * V_62 / V_57 ;
V_61 = ( V_61 * 12 ) / 10 ;
if ( V_61 > V_35 ) {
V_61 = V_35 ;
F_18 ( L_4 ) ;
}
if ( V_61 < V_33 ) {
V_61 = V_33 ;
F_18 ( L_5 ) ;
}
V_19 = 0 ;
V_20 = 0 ;
V_21 = 0 ;
V_42 = F_12 ( V_60 , V_61 , & V_19 , & V_20 , & V_21 ) ;
if ( V_42 )
F_18 ( L_6 ) ;
V_61 = F_10 ( V_60 , V_19 , V_20 , V_21 ) ;
F_7 ( V_2 , V_43 , V_64 | V_65 | V_66 ,
( V_20 << 2 ) | ( V_19 << 11 ) | ( ( F_19 ( V_21 ) - 1 ) << 16 ) ) ;
V_4 = 4000000 / V_61 ;
F_7 ( V_2 , V_67 , V_68 , V_4 ) ;
F_6 ( V_2 , V_69 , V_70 ) ;
F_7 ( V_2 , V_69 , V_71 ,
F_8 ( V_58 ) << 1 ) ;
* V_59 = V_61 / 1000 ;
F_9 ( L_7 ,
V_60 , V_61 , * V_59 ) ;
return 0 ;
}
static int F_20 ( struct V_72 * V_73 )
{
struct V_74 * V_75 = & V_73 -> V_75 ;
struct V_1 * V_2 ;
struct V_76 * V_77 ;
int V_42 ;
V_2 = F_21 ( V_75 , sizeof( * V_2 ) , V_78 ) ;
if ( ! V_2 )
return - V_79 ;
V_77 = F_22 ( V_73 , V_80 , 0 ) ;
if ( ! V_77 ) {
F_23 ( L_8 ) ;
return - V_81 ;
}
V_2 -> V_5 = F_24 ( V_75 , V_77 ) ;
if ( F_25 ( V_2 -> V_5 ) ) {
F_23 ( L_9 ) ;
return F_26 ( V_2 -> V_5 ) ;
}
V_2 -> V_63 = F_27 ( V_75 , L_10 ) ;
if ( F_25 ( V_2 -> V_63 ) ) {
V_42 = F_26 ( V_2 -> V_63 ) ;
F_28 ( V_75 , L_11 , V_42 ) ;
return V_42 ;
}
V_42 = F_29 ( V_2 -> V_63 ) ;
if ( V_42 ) {
F_28 ( V_75 , L_12 , V_82 ) ;
return V_42 ;
}
V_83 . V_5 = V_2 -> V_5 ;
V_83 . V_41 = V_2 ;
V_42 = F_30 ( V_73 , & V_83 ) ;
if ( V_42 ) {
F_23 ( L_13 ) ;
F_31 ( V_2 -> V_63 ) ;
}
return V_42 ;
}
static int F_32 ( struct V_72 * V_73 )
{
struct V_1 * V_2 = V_83 . V_41 ;
F_31 ( V_2 -> V_63 ) ;
F_33 ( V_73 ) ;
return 0 ;
}
