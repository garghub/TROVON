static int F_1 ( struct V_1 * V_2 )
{
return V_3 ;
}
static const char * F_2 ( struct V_1 * V_2 ,
unsigned V_4 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return V_6 -> V_7 -> V_8 [ V_4 ] . V_9 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_4 ,
const unsigned * * V_8 ,
unsigned * V_10 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
* V_8 = & V_6 -> V_7 -> V_8 [ V_4 ] . V_11 ;
* V_10 = 1 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
return F_6 ( V_12 ) ;
}
static const char * F_7 ( struct V_1 * V_2 , unsigned V_4 )
{
return V_12 [ V_4 ] ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_4 ,
const char * const * * V_13 ,
unsigned * const V_14 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
* V_13 = V_6 -> V_15 ;
* V_14 = V_3 ;
return 0 ;
}
static void F_9 ( int V_16 , int * V_17 , int * V_18 )
{
* V_18 = ( V_16 % V_19 ) * 2 ;
* V_17 = F_10 ( V_16 / V_19 ) ;
if ( * V_18 >= V_19 ) {
* V_18 -= V_19 ;
* V_17 += 1 ;
}
}
static int F_11 ( struct V_1 * V_2 , unsigned V_4 ,
unsigned V_20 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
int V_21 , V_22 ;
T_1 V_17 ;
F_9 ( V_20 , & V_22 , & V_21 ) ;
V_17 = F_12 ( V_6 -> V_23 + V_22 ) ;
V_17 &= ~ ( 3 << V_21 ) ;
V_17 |= ( V_4 << V_21 ) ;
F_13 ( V_17 , V_6 -> V_23 + V_22 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_24 ,
struct V_25 * V_26 ,
unsigned V_27 )
{
struct V_5 * V_6 = F_3 ( V_24 ) ;
int V_21 , V_22 ;
T_1 V_17 ;
F_9 ( V_27 , & V_22 , & V_21 ) ;
V_17 = F_12 ( V_6 -> V_23 + V_22 ) ;
if ( ( V_17 & ( 3 << V_21 ) ) != 0 )
return - V_28 ;
return 0 ;
}
static int F_15 ( struct V_29 * V_30 , unsigned V_31 )
{
struct V_5 * V_6 = F_16 ( V_30 ) ;
int V_22 = F_17 ( V_31 / V_19 ) ;
int V_21 = V_31 % V_19 ;
T_1 V_32 ;
unsigned long V_33 ;
F_18 ( & V_6 -> V_34 , V_33 ) ;
V_32 = F_12 ( V_6 -> V_23 + V_22 ) ;
V_32 &= ~ F_19 ( V_21 ) ;
F_13 ( V_32 , V_6 -> V_23 + V_22 ) ;
F_20 ( & V_6 -> V_34 , V_33 ) ;
return 0 ;
}
static int F_21 ( struct V_29 * V_30 , unsigned V_31 ,
int V_35 )
{
struct V_5 * V_6 = F_16 ( V_30 ) ;
int V_22 = F_17 ( V_31 / V_19 ) ;
int V_21 = V_31 % V_19 ;
T_1 V_32 ;
unsigned long V_33 ;
F_22 ( V_30 , V_31 , V_35 ) ;
F_18 ( & V_6 -> V_34 , V_33 ) ;
V_32 = F_12 ( V_6 -> V_23 + V_22 ) ;
V_32 |= F_19 ( V_21 ) ;
F_13 ( V_32 , V_6 -> V_23 + V_22 ) ;
F_20 ( & V_6 -> V_34 , V_33 ) ;
return 0 ;
}
static int F_23 ( struct V_29 * V_30 , unsigned V_31 )
{
struct V_5 * V_6 = F_16 ( V_30 ) ;
int V_22 = F_24 ( V_31 / V_19 ) ;
int V_21 = V_31 % V_19 ;
T_1 V_36 ;
V_36 = F_12 ( V_6 -> V_23 + V_22 ) ;
return ! ! ( V_36 & F_19 ( V_21 ) ) ;
}
static void F_22 ( struct V_29 * V_30 , unsigned V_31 , int V_35 )
{
struct V_5 * V_6 = F_16 ( V_30 ) ;
int V_22 = F_25 ( V_31 / V_19 ) ;
int V_21 = V_31 % V_19 ;
T_1 V_37 ;
unsigned long V_33 ;
F_18 ( & V_6 -> V_34 , V_33 ) ;
V_37 = F_12 ( V_6 -> V_23 + V_22 ) ;
if ( V_35 )
V_37 |= F_19 ( V_21 ) ;
else
V_37 &= ~ F_19 ( V_21 ) ;
F_13 ( V_37 , V_6 -> V_23 + V_22 ) ;
F_20 ( & V_6 -> V_34 , V_33 ) ;
}
static int F_26 ( struct V_5 * V_6 , struct V_38 * V_39 )
{
struct V_29 * V_30 = & V_6 -> V_30 ;
int V_40 ;
V_30 -> V_41 = V_42 ;
V_30 -> V_43 = V_6 -> V_44 ;
V_30 -> V_45 = V_46 ;
V_30 -> free = V_47 ;
V_30 -> V_48 = F_15 ;
V_30 -> V_49 = F_21 ;
V_30 -> V_50 = F_23 ;
V_30 -> V_51 = F_22 ;
V_30 -> V_52 = - 1 ;
V_30 -> V_53 = V_3 ;
V_30 -> V_54 = V_39 ;
V_30 -> V_55 = 2 ;
F_27 ( & V_6 -> V_34 ) ;
V_40 = F_28 ( V_30 , V_6 ) ;
if ( V_40 < 0 )
return V_40 ;
V_40 = F_29 ( V_30 , F_30 ( V_6 -> V_44 ) , 0 , 0 ,
V_3 ) ;
if ( V_40 < 0 ) {
F_31 ( V_30 ) ;
return V_40 ;
}
return 0 ;
}
static int F_32 ( struct V_56 * V_57 )
{
struct V_5 * V_6 ;
struct V_58 * V_59 ;
struct V_60 * V_8 ;
struct V_61 * V_62 ;
char * V_15 ;
int V_63 = strlen ( L_1 ) + 1 ;
int V_64 , V_65 , V_40 ;
V_6 = F_33 ( & V_57 -> V_44 , sizeof( * V_6 ) , V_66 ) ;
if ( ! V_6 )
return - V_67 ;
V_59 = F_34 ( V_57 , V_68 , 0 ) ;
V_6 -> V_23 = F_35 ( & V_57 -> V_44 , V_59 ) ;
if ( F_36 ( V_6 -> V_23 ) )
return F_37 ( V_6 -> V_23 ) ;
V_8 = F_33 ( & V_57 -> V_44 , sizeof( * V_8 ) * V_3 , V_66 ) ;
if ( ! V_8 )
return - V_67 ;
V_15 = F_33 ( & V_57 -> V_44 , V_63 * V_3 ,
V_66 ) ;
if ( ! V_15 )
return - V_67 ;
for ( V_64 = 0 ; V_64 < V_69 ; V_64 ++ ) {
for ( V_65 = 0 ; V_65 < V_19 ; V_65 ++ ) {
int V_70 = V_64 * V_19 + V_65 ;
char * V_9 = & V_15 [ V_70 * V_63 ] ;
snprintf ( V_9 , V_63 , L_2 , 'A' + V_64 , '0' + V_65 ) ;
V_8 [ V_70 ] . V_11 = V_70 ;
V_8 [ V_70 ] . V_9 = V_9 ;
V_6 -> V_15 [ V_70 ] = V_9 ;
}
}
V_62 = F_33 ( & V_57 -> V_44 , sizeof( * V_62 ) , V_66 ) ;
if ( ! V_62 )
return - V_67 ;
V_62 -> V_9 = V_42 ,
V_62 -> V_71 = V_72 ,
V_62 -> V_73 = & V_74 ,
V_62 -> V_75 = & V_76 ,
V_62 -> V_77 = V_3 ;
V_62 -> V_8 = V_8 ;
V_6 -> V_7 = V_62 ;
V_6 -> V_44 = & V_57 -> V_44 ;
V_6 -> V_78 = F_38 ( V_62 , & V_57 -> V_44 , V_6 ) ;
if ( F_36 ( V_6 -> V_78 ) ) {
F_39 ( & V_57 -> V_44 , L_3 ) ;
return F_37 ( V_6 -> V_78 ) ;
}
V_40 = F_26 ( V_6 , V_57 -> V_44 . V_54 ) ;
if ( V_40 < 0 ) {
F_40 ( V_6 -> V_78 ) ;
return V_40 ;
}
return 0 ;
}
static int F_41 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_42 ( V_57 ) ;
F_40 ( V_6 -> V_78 ) ;
F_31 ( & V_6 -> V_30 ) ;
return 0 ;
}
