static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_11 ;
V_11 = F_2 ( V_9 -> V_12 + V_13 ) ;
if ( ( V_11 & V_14 ) == 0 )
return 0 ;
return - V_15 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_16 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_17 = F_4 ( V_6 -> V_18 ) ;
unsigned int V_19 = F_5 ( V_6 -> V_18 ) ;
int V_20 ;
unsigned int V_21 ;
int V_22 ;
V_21 = F_2 ( V_9 -> V_12 + V_23 ) ;
if ( ( V_21 & V_24 ) != V_25 ) {
V_21 &= ~ V_24 ;
V_21 |= V_25 ;
F_6 ( V_21 , V_9 -> V_12 + V_23 ) ;
}
F_6 ( V_26 , V_9 -> V_12 + V_27 ) ;
F_6 ( V_19 , V_9 -> V_12 + V_28 ) ;
F_6 ( F_7 ( V_17 , V_17 ) , V_9 -> V_12 + V_29 ) ;
for ( V_20 = 0 ; V_20 < V_6 -> V_20 ; V_20 ++ ) {
F_8 ( 0 , V_9 -> V_30 + V_31 ) ;
V_22 = F_9 ( V_2 , V_4 , V_6 , F_1 , 0 ) ;
if ( V_22 )
return V_22 ;
V_16 [ V_20 ] = F_10 ( V_9 -> V_30 + V_32 ) ;
}
return V_20 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_16 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_17 = F_4 ( V_6 -> V_18 ) ;
unsigned int V_33 = V_4 -> V_34 [ V_17 ] ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_6 -> V_20 ; V_35 ++ ) {
V_33 = V_16 [ V_35 ] ;
F_8 ( V_33 , V_9 -> V_30 + F_12 ( V_17 ) ) ;
}
V_4 -> V_34 [ V_17 ] = V_33 ;
return V_6 -> V_20 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_16 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_33 ;
V_33 = F_2 ( V_9 -> V_12 + V_36 ) ;
V_16 [ 1 ] = V_33 & 0x0f ;
return V_6 -> V_20 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_16 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( F_15 ( V_4 , V_16 ) )
F_6 ( V_4 -> V_37 , V_9 -> V_12 + V_36 ) ;
V_16 [ 1 ] = V_4 -> V_37 ;
return V_6 -> V_20 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_16 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_38 ;
switch ( V_16 [ 0 ] ) {
case V_39 :
switch ( V_16 [ 1 ] ) {
case 0 :
V_38 = V_40 ;
break;
case 1 :
V_38 = 0 ;
break;
default:
return - V_41 ;
}
F_6 ( V_38 , V_9 -> V_12 + V_42 ) ;
break;
case V_43 :
V_38 = F_2 ( V_9 -> V_12 + V_42 ) ;
if ( V_38 & V_40 ) {
V_16 [ 1 ] = 0 ;
V_16 [ 2 ] = V_44 ;
} else {
V_16 [ 1 ] = 1 ;
V_16 [ 2 ] = 0 ;
}
break;
default:
return - V_41 ;
}
return V_6 -> V_20 ;
}
static unsigned int F_17 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_11 ;
V_11 = F_2 ( V_9 -> V_12 + V_13 ) ;
if ( V_11 & V_45 )
return V_46 ;
return V_47 ;
}
static bool F_18 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_11 ;
V_11 = F_2 ( V_9 -> V_12 + V_13 ) ;
return V_11 & V_48 ;
}
static bool F_19 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_11 ;
V_11 = F_2 ( V_9 -> V_12 + V_13 ) ;
return V_11 & V_49 ;
}
static int F_20 ( struct V_1 * V_2 ,
unsigned long V_50 )
{
struct V_51 * V_52 = F_21 ( V_2 ) ;
struct V_8 * V_9 ;
struct V_3 * V_4 ;
int V_22 ;
V_9 = F_22 ( V_2 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_53 ;
V_22 = F_23 ( V_2 ) ;
if ( V_22 )
return V_22 ;
V_9 -> V_30 = F_24 ( V_52 , 2 ) ;
V_9 -> V_12 = F_24 ( V_52 , 3 ) ;
V_2 -> V_54 = F_24 ( V_52 , 4 ) ;
V_2 -> V_55 = F_25 ( V_9 -> V_12 + V_56 ,
F_17 ( V_2 ) ,
V_57 , 0 ) ;
if ( ! V_2 -> V_55 )
return - V_53 ;
V_22 = F_26 ( V_2 , 6 ) ;
if ( V_22 )
return V_22 ;
V_4 = & V_2 -> V_58 [ 0 ] ;
V_4 -> type = V_59 ;
V_4 -> V_60 = V_61 ;
if ( F_18 ( V_2 ) ) {
V_4 -> V_60 |= V_62 ;
V_4 -> V_63 = 16 ;
} else {
V_4 -> V_60 |= V_64 ;
V_4 -> V_63 = 8 ;
}
V_4 -> V_65 = 0xffff ;
V_4 -> V_66 = F_19 ( V_2 ) ? & V_67
: & V_68 ;
V_4 -> V_69 = F_3 ;
V_4 = & V_2 -> V_58 [ 1 ] ;
V_4 -> type = V_70 ;
V_4 -> V_60 = V_71 ;
V_4 -> V_63 = 2 ;
V_4 -> V_65 = 0xfff ;
V_4 -> V_66 = & V_72 ;
V_4 -> V_73 = F_11 ;
V_22 = F_27 ( V_4 ) ;
if ( V_22 )
return V_22 ;
V_4 = & V_2 -> V_58 [ 2 ] ;
V_22 = F_28 ( V_2 , V_4 , NULL , V_74 ) ;
if ( V_22 )
return V_22 ;
V_4 = & V_2 -> V_58 [ 3 ] ;
V_4 -> type = V_75 ;
V_4 -> V_60 = V_61 ;
V_4 -> V_63 = 4 ;
V_4 -> V_65 = 1 ;
V_4 -> V_66 = & V_76 ;
V_4 -> V_77 = F_13 ;
V_4 = & V_2 -> V_58 [ 4 ] ;
V_4 -> type = V_78 ;
V_4 -> V_60 = V_71 ;
V_4 -> V_63 = 4 ;
V_4 -> V_65 = 1 ;
V_4 -> V_66 = & V_76 ;
V_4 -> V_77 = F_14 ;
V_4 = & V_2 -> V_58 [ 5 ] ;
F_29 ( V_4 , V_2 -> V_55 ) ;
V_2 -> V_55 -> V_79 = F_16 ;
F_30 ( V_2 -> V_55 , 1 , true ) ;
F_30 ( V_2 -> V_55 , 2 , true ) ;
return 0 ;
}
static int F_31 ( struct V_51 * V_2 ,
const struct V_80 * V_81 )
{
return F_32 ( V_2 , & V_82 ,
V_81 -> V_83 ) ;
}
