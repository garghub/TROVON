static unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned int V_4 ;
V_4 = V_3 / V_2 -> V_5 -> V_6 ;
if ( V_4 >= V_2 -> V_5 -> V_7 )
V_4 = V_2 -> V_5 -> V_7 - 1 ;
return V_4 ;
}
static int F_2 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned int V_4 = F_1 ( V_2 , V_3 ) ;
return F_3 ( V_2 -> V_8 [ V_4 ] . V_9 ) ;
}
static int F_4 ( struct V_10 * V_11 ,
unsigned int V_12 , unsigned int V_13 , unsigned int V_14 ,
unsigned int V_15 )
{
struct V_1 * V_2 = F_5 ( V_11 ) ;
V_14 <<= V_15 ;
V_14 |= F_6 ( V_12 ) | F_7 ( V_13 ) ;
V_2 -> V_16 [ 0 ] . V_17 = F_8 ( V_14 ) ;
return F_9 ( V_2 -> V_18 , & V_2 -> V_16 [ 0 ] . V_19 [ 1 ] , 3 ) ;
}
static int F_10 ( struct V_10 * V_11 , unsigned int V_12 ,
unsigned int V_13 , unsigned int V_14 , unsigned int V_15 )
{
int V_20 ;
F_11 ( & V_11 -> V_21 ) ;
V_20 = F_4 ( V_11 , V_12 , V_13 , V_14 , V_15 ) ;
F_12 ( & V_11 -> V_21 ) ;
return V_20 ;
}
static int F_13 ( struct V_10 * V_11 , unsigned int type ,
unsigned int V_13 )
{
struct V_1 * V_2 = F_5 ( V_11 ) ;
int V_20 ;
struct V_22 V_23 [] = {
{
. V_24 = & V_2 -> V_16 [ 0 ] . V_19 [ 1 ] ,
. V_25 = 3 ,
. V_26 = 1 ,
} , {
. V_27 = & V_2 -> V_16 [ 1 ] . V_19 [ 1 ] ,
. V_25 = 3 ,
} ,
} ;
F_11 ( & V_11 -> V_21 ) ;
V_2 -> V_16 [ 0 ] . V_17 = F_8 ( F_6 ( V_28 ) |
F_7 ( V_29 ) |
F_14 ( type ) |
F_15 ( V_13 ) ) ;
V_20 = F_16 ( V_2 -> V_18 , V_23 , F_17 ( V_23 ) ) ;
if ( V_20 >= 0 )
V_20 = F_18 ( V_2 -> V_16 [ 1 ] . V_17 ) & 0xffff ;
F_12 ( & V_11 -> V_21 ) ;
return V_20 ;
}
static T_1 F_19 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
char * V_34 )
{
struct V_10 * V_11 = F_20 ( V_31 ) ;
struct V_1 * V_2 = F_5 ( V_11 ) ;
return sprintf ( V_34 , L_1 , ( bool ) ( V_2 -> V_35 & V_36 ) ) ;
}
static int F_21 ( struct V_10 * V_11 , unsigned int V_37 ,
unsigned int V_38 )
{
struct V_1 * V_2 = F_5 ( V_11 ) ;
unsigned int V_20 ;
F_11 ( & V_11 -> V_21 ) ;
V_2 -> V_35 |= V_37 ;
V_2 -> V_35 &= ~ V_38 ;
V_20 = F_4 ( V_11 , V_28 ,
V_39 , V_2 -> V_35 , 0 ) ;
F_12 ( & V_11 -> V_21 ) ;
return V_20 ;
}
static T_1 F_22 ( struct V_30 * V_31 ,
struct V_32 * V_33 , const char * V_34 , T_2 V_25 )
{
struct V_10 * V_11 = F_20 ( V_31 ) ;
bool V_40 ;
int V_20 ;
V_20 = F_23 ( V_34 , & V_40 ) ;
if ( V_20 )
return V_20 ;
if ( V_40 )
V_20 = F_21 ( V_11 , V_36 , 0 ) ;
else
V_20 = F_21 ( V_11 , 0 , V_36 ) ;
return V_20 ? V_20 : V_25 ;
}
static int F_24 ( struct V_10 * V_11 ,
struct V_41 const * V_42 ,
int V_14 ,
int V_43 ,
long V_44 )
{
struct V_1 * V_2 = F_5 ( V_11 ) ;
int V_45 = ( 1 << V_42 -> V_46 . V_47 ) ;
unsigned int V_48 ;
switch ( V_44 ) {
case V_49 :
if ( V_14 >= V_45 || V_14 < 0 )
return - V_50 ;
return F_10 ( V_11 , V_51 ,
V_42 -> V_52 , V_14 , V_42 -> V_46 . V_15 ) ;
case V_53 :
if ( V_14 >= V_45 || V_14 < 0 )
return - V_50 ;
return F_10 ( V_11 , V_54 ,
V_42 -> V_52 , V_14 , V_42 -> V_46 . V_15 ) ;
case V_55 :
if ( V_14 >= V_45 || V_14 < 0 )
return - V_50 ;
return F_10 ( V_11 , V_56 ,
V_42 -> V_52 , V_14 , V_42 -> V_46 . V_15 ) ;
case V_57 :
if ( V_14 <= - V_45 || V_14 > 0 )
return - V_50 ;
V_14 = - V_14 ;
V_14 >>= ( V_42 -> V_46 . V_47 - 14 ) ;
V_48 = F_1 ( V_2 , V_42 -> V_3 ) ;
return F_10 ( V_11 , V_28 ,
F_25 ( V_48 ) , V_14 , 0 ) ;
default:
break;
}
return - V_50 ;
}
static int F_26 ( struct V_10 * V_11 ,
struct V_41 const * V_42 ,
int * V_14 ,
int * V_43 ,
long V_58 )
{
struct V_1 * V_2 = F_5 ( V_11 ) ;
unsigned int V_48 ;
int V_59 ;
int V_20 ;
switch ( V_58 ) {
case V_49 :
V_20 = F_13 ( V_11 , V_60 ,
V_42 -> V_52 ) ;
if ( V_20 < 0 )
return V_20 ;
* V_14 = V_20 >> V_42 -> V_46 . V_15 ;
return V_61 ;
case V_62 :
V_59 = F_2 ( V_2 , V_42 -> V_3 ) * 4 * 100 ;
if ( V_59 < 0 )
return V_59 ;
V_59 >>= ( V_42 -> V_46 . V_47 ) ;
* V_14 = V_59 / 100000 ;
* V_43 = ( V_59 % 100000 ) * 10 ;
return V_63 ;
case V_53 :
V_20 = F_13 ( V_11 , V_64 ,
V_42 -> V_52 ) ;
if ( V_20 < 0 )
return V_20 ;
* V_14 = V_20 ;
return V_61 ;
case V_55 :
V_20 = F_13 ( V_11 , V_65 ,
V_42 -> V_52 ) ;
if ( V_20 < 0 )
return V_20 ;
* V_14 = V_20 ;
return V_61 ;
case V_57 :
V_48 = F_1 ( V_2 , V_42 -> V_3 ) ;
V_20 = F_13 ( V_11 , V_66 ,
F_25 ( V_48 ) ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 <<= ( V_42 -> V_46 . V_47 - 14 ) ;
* V_14 = - V_20 ;
return V_61 ;
}
return - V_50 ;
}
static int F_27 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_5 ( V_11 ) ;
struct V_41 * V_67 ;
unsigned int V_4 ;
V_67 = F_28 ( V_2 -> V_5 -> V_68 ,
sizeof( struct V_41 ) , V_69 ) ;
if ( ! V_67 )
return - V_70 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 -> V_68 ; ++ V_4 ) {
V_67 [ V_4 ] = V_2 -> V_5 -> V_71 ;
V_67 [ V_4 ] . V_3 = V_4 ;
V_67 [ V_4 ] . V_52 = F_29 ( V_4 ) ;
}
V_11 -> V_67 = V_67 ;
return 0 ;
}
static int F_30 ( struct V_72 * V_18 )
{
enum V_73 type = F_31 ( V_18 ) -> V_74 ;
struct V_10 * V_11 ;
struct V_1 * V_2 ;
unsigned int V_4 ;
int V_20 ;
V_11 = F_32 ( sizeof( * V_2 ) ) ;
if ( V_11 == NULL ) {
F_33 ( & V_18 -> V_31 , L_2 ) ;
return - V_70 ;
}
V_2 = F_5 ( V_11 ) ;
F_34 ( V_18 , V_11 ) ;
V_2 -> V_5 = & V_75 [ type ] ;
V_2 -> V_18 = V_18 ;
V_11 -> V_31 . V_76 = & V_18 -> V_31 ;
V_11 -> V_77 = F_31 ( V_18 ) -> V_77 ;
V_11 -> V_78 = & V_79 ;
V_11 -> V_80 = V_81 ;
V_11 -> V_68 = V_2 -> V_5 -> V_68 ;
V_20 = F_27 ( V_11 ) ;
if ( V_20 ) {
F_33 ( & V_18 -> V_31 , L_3 , V_20 ) ;
goto V_82;
}
for ( V_4 = 0 ; V_4 < V_2 -> V_5 -> V_7 ; ++ V_4 )
V_2 -> V_8 [ V_4 ] . V_83 = V_84 [ V_4 ] ;
V_20 = F_35 ( & V_2 -> V_18 -> V_31 , V_2 -> V_5 -> V_7 ,
V_2 -> V_8 ) ;
if ( V_20 ) {
F_33 ( & V_18 -> V_31 , L_4 , V_20 ) ;
goto V_85;
}
V_20 = F_36 ( V_2 -> V_5 -> V_7 , V_2 -> V_8 ) ;
if ( V_20 ) {
F_33 ( & V_18 -> V_31 , L_5 , V_20 ) ;
goto V_86;
}
V_20 = F_37 ( V_11 ) ;
if ( V_20 ) {
F_33 ( & V_18 -> V_31 , L_6 , V_20 ) ;
goto V_87;
}
return 0 ;
V_87:
F_38 ( V_2 -> V_5 -> V_7 , V_2 -> V_8 ) ;
V_86:
F_39 ( V_2 -> V_5 -> V_7 , V_2 -> V_8 ) ;
V_85:
F_40 ( V_11 -> V_67 ) ;
V_82:
F_41 ( V_11 ) ;
return V_20 ;
}
static int F_42 ( struct V_72 * V_18 )
{
struct V_10 * V_11 = F_43 ( V_18 ) ;
struct V_1 * V_2 = F_5 ( V_11 ) ;
F_44 ( V_11 ) ;
F_40 ( V_11 -> V_67 ) ;
F_38 ( V_2 -> V_5 -> V_7 , V_2 -> V_8 ) ;
F_39 ( V_2 -> V_5 -> V_7 , V_2 -> V_8 ) ;
F_41 ( V_11 ) ;
return 0 ;
}
