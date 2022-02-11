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
return F_16 ( V_30 -> V_32 + V_31 ) ;
}
static void F_17 ( struct V_29 * V_30 , unsigned V_31 )
{
F_18 ( V_30 -> V_32 + V_31 ) ;
}
static int F_19 ( struct V_29 * V_30 , unsigned V_31 )
{
struct V_5 * V_6 = F_20 ( V_30 , struct V_5 , V_30 ) ;
int V_22 = F_21 ( V_31 / V_19 ) ;
int V_21 = V_31 % V_19 ;
T_1 V_33 ;
unsigned long V_34 ;
F_22 ( & V_6 -> V_35 , V_34 ) ;
V_33 = F_12 ( V_6 -> V_23 + V_22 ) ;
V_33 &= ~ F_23 ( V_21 ) ;
F_13 ( V_33 , V_6 -> V_23 + V_22 ) ;
F_24 ( & V_6 -> V_35 , V_34 ) ;
return 0 ;
}
static int F_25 ( struct V_29 * V_30 , unsigned V_31 ,
int V_36 )
{
struct V_5 * V_6 = F_20 ( V_30 , struct V_5 , V_30 ) ;
int V_22 = F_21 ( V_31 / V_19 ) ;
int V_21 = V_31 % V_19 ;
T_1 V_33 ;
unsigned long V_34 ;
F_26 ( V_30 , V_31 , V_36 ) ;
F_22 ( & V_6 -> V_35 , V_34 ) ;
V_33 = F_12 ( V_6 -> V_23 + V_22 ) ;
V_33 |= F_23 ( V_21 ) ;
F_13 ( V_33 , V_6 -> V_23 + V_22 ) ;
F_24 ( & V_6 -> V_35 , V_34 ) ;
return 0 ;
}
static int F_27 ( struct V_29 * V_30 , unsigned V_31 )
{
struct V_5 * V_6 = F_20 ( V_30 , struct V_5 , V_30 ) ;
int V_22 = F_28 ( V_31 / V_19 ) ;
int V_21 = V_31 % V_19 ;
T_1 V_37 ;
V_37 = F_12 ( V_6 -> V_23 + V_22 ) ;
return ! ! ( V_37 & F_23 ( V_21 ) ) ;
}
static void F_26 ( struct V_29 * V_30 , unsigned V_31 , int V_36 )
{
struct V_5 * V_6 = F_20 ( V_30 , struct V_5 , V_30 ) ;
int V_22 = F_29 ( V_31 / V_19 ) ;
int V_21 = V_31 % V_19 ;
T_1 V_38 ;
unsigned long V_34 ;
F_22 ( & V_6 -> V_35 , V_34 ) ;
V_38 = F_12 ( V_6 -> V_23 + V_22 ) ;
if ( V_36 )
V_38 |= F_23 ( V_21 ) ;
else
V_38 &= ~ F_23 ( V_21 ) ;
F_13 ( V_38 , V_6 -> V_23 + V_22 ) ;
F_24 ( & V_6 -> V_35 , V_34 ) ;
}
static int F_30 ( struct V_5 * V_6 , struct V_39 * V_40 )
{
struct V_29 * V_30 = & V_6 -> V_30 ;
int V_41 ;
V_30 -> V_42 = V_43 ;
V_30 -> V_44 = V_6 -> V_44 ;
V_30 -> V_45 = F_15 ;
V_30 -> free = F_17 ;
V_30 -> V_46 = F_19 ;
V_30 -> V_47 = F_25 ;
V_30 -> V_48 = F_27 ;
V_30 -> V_49 = F_26 ;
V_30 -> V_32 = - 1 ;
V_30 -> V_50 = V_3 ;
V_30 -> V_51 = V_40 ;
V_30 -> V_52 = 2 ;
F_31 ( & V_6 -> V_35 ) ;
V_41 = F_32 ( V_30 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_33 ( V_30 , F_34 ( V_6 -> V_44 ) , 0 , 0 ,
V_3 ) ;
if ( V_41 < 0 ) {
F_35 ( V_30 ) ;
return V_41 ;
}
return 0 ;
}
static int F_36 ( struct V_53 * V_54 )
{
struct V_5 * V_6 ;
struct V_55 * V_56 ;
struct V_57 * V_8 ;
struct V_58 * V_59 ;
char * V_15 ;
int V_60 = strlen ( L_1 ) + 1 ;
int V_61 , V_62 , V_41 ;
V_6 = F_37 ( & V_54 -> V_44 , sizeof( * V_6 ) , V_63 ) ;
if ( ! V_6 )
return - V_64 ;
V_56 = F_38 ( V_54 , V_65 , 0 ) ;
V_6 -> V_23 = F_39 ( & V_54 -> V_44 , V_56 ) ;
if ( F_40 ( V_6 -> V_23 ) )
return F_41 ( V_6 -> V_23 ) ;
V_8 = F_37 ( & V_54 -> V_44 , sizeof( * V_8 ) * V_3 , V_63 ) ;
if ( ! V_8 )
return - V_64 ;
V_15 = F_37 ( & V_54 -> V_44 , V_60 * V_3 ,
V_63 ) ;
if ( ! V_15 )
return - V_64 ;
for ( V_61 = 0 ; V_61 < V_66 ; V_61 ++ ) {
for ( V_62 = 0 ; V_62 < V_19 ; V_62 ++ ) {
int V_67 = V_61 * V_19 + V_62 ;
char * V_9 = & V_15 [ V_67 * V_60 ] ;
snprintf ( V_9 , V_60 , L_2 , 'A' + V_61 , '0' + V_62 ) ;
V_8 [ V_67 ] . V_11 = V_67 ;
V_8 [ V_67 ] . V_9 = V_9 ;
V_6 -> V_15 [ V_67 ] = V_9 ;
}
}
V_59 = F_37 ( & V_54 -> V_44 , sizeof( * V_59 ) , V_63 ) ;
if ( ! V_59 )
return - V_64 ;
V_59 -> V_9 = V_43 ,
V_59 -> V_68 = V_69 ,
V_59 -> V_70 = & V_71 ,
V_59 -> V_72 = & V_73 ,
V_59 -> V_74 = V_3 ;
V_59 -> V_8 = V_8 ;
V_6 -> V_7 = V_59 ;
V_6 -> V_44 = & V_54 -> V_44 ;
V_6 -> V_75 = F_42 ( V_59 , & V_54 -> V_44 , V_6 ) ;
if ( F_40 ( V_6 -> V_75 ) ) {
F_43 ( & V_54 -> V_44 , L_3 ) ;
return F_41 ( V_6 -> V_75 ) ;
}
V_41 = F_30 ( V_6 , V_54 -> V_44 . V_51 ) ;
if ( V_41 < 0 ) {
F_44 ( V_6 -> V_75 ) ;
return V_41 ;
}
return 0 ;
}
static int F_45 ( struct V_53 * V_54 )
{
struct V_5 * V_6 = F_46 ( V_54 ) ;
F_44 ( V_6 -> V_75 ) ;
F_35 ( & V_6 -> V_30 ) ;
return 0 ;
}
