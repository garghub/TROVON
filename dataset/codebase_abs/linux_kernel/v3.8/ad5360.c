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
struct V_22 V_23 ;
int V_20 ;
struct V_24 V_25 [] = {
{
. V_26 = & V_2 -> V_16 [ 0 ] . V_19 [ 1 ] ,
. V_27 = 3 ,
. V_28 = 1 ,
} , {
. V_29 = & V_2 -> V_16 [ 1 ] . V_19 [ 1 ] ,
. V_27 = 3 ,
} ,
} ;
F_14 ( & V_23 ) ;
F_15 ( & V_25 [ 0 ] , & V_23 ) ;
F_15 ( & V_25 [ 1 ] , & V_23 ) ;
F_11 ( & V_11 -> V_21 ) ;
V_2 -> V_16 [ 0 ] . V_17 = F_8 ( F_6 ( V_30 ) |
F_7 ( V_31 ) |
F_16 ( type ) |
F_17 ( V_13 ) ) ;
V_20 = F_18 ( V_2 -> V_18 , & V_23 ) ;
if ( V_20 >= 0 )
V_20 = F_19 ( V_2 -> V_16 [ 1 ] . V_17 ) & 0xffff ;
F_12 ( & V_11 -> V_21 ) ;
return V_20 ;
}
static T_1 F_20 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
struct V_10 * V_11 = F_21 ( V_33 ) ;
struct V_1 * V_2 = F_5 ( V_11 ) ;
return sprintf ( V_36 , L_1 , ( bool ) ( V_2 -> V_37 & V_38 ) ) ;
}
static int F_22 ( struct V_10 * V_11 , unsigned int V_39 ,
unsigned int V_40 )
{
struct V_1 * V_2 = F_5 ( V_11 ) ;
unsigned int V_20 ;
F_11 ( & V_11 -> V_21 ) ;
V_2 -> V_37 |= V_39 ;
V_2 -> V_37 &= ~ V_40 ;
V_20 = F_4 ( V_11 , V_30 ,
V_41 , V_2 -> V_37 , 0 ) ;
F_12 ( & V_11 -> V_21 ) ;
return V_20 ;
}
static T_1 F_23 ( struct V_32 * V_33 ,
struct V_34 * V_35 , const char * V_36 , T_2 V_27 )
{
struct V_10 * V_11 = F_21 ( V_33 ) ;
bool V_42 ;
int V_20 ;
V_20 = F_24 ( V_36 , & V_42 ) ;
if ( V_20 )
return V_20 ;
if ( V_42 )
V_20 = F_22 ( V_11 , V_38 , 0 ) ;
else
V_20 = F_22 ( V_11 , 0 , V_38 ) ;
return V_20 ? V_20 : V_27 ;
}
static int F_25 ( struct V_10 * V_11 ,
struct V_43 const * V_44 ,
int V_14 ,
int V_45 ,
long V_46 )
{
struct V_1 * V_2 = F_5 ( V_11 ) ;
int V_47 = ( 1 << V_44 -> V_48 . V_49 ) ;
unsigned int V_50 ;
switch ( V_46 ) {
case V_51 :
if ( V_14 >= V_47 || V_14 < 0 )
return - V_52 ;
return F_10 ( V_11 , V_53 ,
V_44 -> V_54 , V_14 , V_44 -> V_48 . V_15 ) ;
case V_55 :
if ( V_14 >= V_47 || V_14 < 0 )
return - V_52 ;
return F_10 ( V_11 , V_56 ,
V_44 -> V_54 , V_14 , V_44 -> V_48 . V_15 ) ;
case V_57 :
if ( V_14 >= V_47 || V_14 < 0 )
return - V_52 ;
return F_10 ( V_11 , V_58 ,
V_44 -> V_54 , V_14 , V_44 -> V_48 . V_15 ) ;
case V_59 :
if ( V_14 <= - V_47 || V_14 > 0 )
return - V_52 ;
V_14 = - V_14 ;
V_14 >>= ( V_44 -> V_48 . V_49 - 14 ) ;
V_50 = F_1 ( V_2 , V_44 -> V_3 ) ;
return F_10 ( V_11 , V_30 ,
F_26 ( V_50 ) , V_14 , 0 ) ;
default:
break;
}
return - V_52 ;
}
static int F_27 ( struct V_10 * V_11 ,
struct V_43 const * V_44 ,
int * V_14 ,
int * V_45 ,
long V_23 )
{
struct V_1 * V_2 = F_5 ( V_11 ) ;
unsigned int V_50 ;
int V_60 ;
int V_20 ;
switch ( V_23 ) {
case V_51 :
V_20 = F_13 ( V_11 , V_61 ,
V_44 -> V_54 ) ;
if ( V_20 < 0 )
return V_20 ;
* V_14 = V_20 >> V_44 -> V_48 . V_15 ;
return V_62 ;
case V_63 :
V_60 = F_2 ( V_2 , V_44 -> V_3 ) * 4 * 100 ;
if ( V_60 < 0 )
return V_60 ;
V_60 >>= ( V_44 -> V_48 . V_49 ) ;
* V_14 = V_60 / 100000 ;
* V_45 = ( V_60 % 100000 ) * 10 ;
return V_64 ;
case V_55 :
V_20 = F_13 ( V_11 , V_65 ,
V_44 -> V_54 ) ;
if ( V_20 < 0 )
return V_20 ;
* V_14 = V_20 ;
return V_62 ;
case V_57 :
V_20 = F_13 ( V_11 , V_66 ,
V_44 -> V_54 ) ;
if ( V_20 < 0 )
return V_20 ;
* V_14 = V_20 ;
return V_62 ;
case V_59 :
V_50 = F_1 ( V_2 , V_44 -> V_3 ) ;
V_20 = F_13 ( V_11 , V_67 ,
F_26 ( V_50 ) ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 <<= ( V_44 -> V_48 . V_49 - 14 ) ;
* V_14 = - V_20 ;
return V_62 ;
}
return - V_52 ;
}
static int F_28 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_5 ( V_11 ) ;
struct V_43 * V_68 ;
unsigned int V_4 ;
V_68 = F_29 ( V_2 -> V_5 -> V_69 ,
sizeof( struct V_43 ) , V_70 ) ;
if ( ! V_68 )
return - V_71 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 -> V_69 ; ++ V_4 ) {
V_68 [ V_4 ] = V_2 -> V_5 -> V_72 ;
V_68 [ V_4 ] . V_3 = V_4 ;
V_68 [ V_4 ] . V_54 = F_30 ( V_4 ) ;
}
V_11 -> V_68 = V_68 ;
return 0 ;
}
static int F_31 ( struct V_73 * V_18 )
{
enum V_74 type = F_32 ( V_18 ) -> V_75 ;
struct V_10 * V_11 ;
struct V_1 * V_2 ;
unsigned int V_4 ;
int V_20 ;
V_11 = F_33 ( sizeof( * V_2 ) ) ;
if ( V_11 == NULL ) {
F_34 ( & V_18 -> V_33 , L_2 ) ;
return - V_71 ;
}
V_2 = F_5 ( V_11 ) ;
F_35 ( V_18 , V_11 ) ;
V_2 -> V_5 = & V_76 [ type ] ;
V_2 -> V_18 = V_18 ;
V_11 -> V_33 . V_77 = & V_18 -> V_33 ;
V_11 -> V_78 = F_32 ( V_18 ) -> V_78 ;
V_11 -> V_79 = & V_80 ;
V_11 -> V_81 = V_82 ;
V_11 -> V_69 = V_2 -> V_5 -> V_69 ;
V_20 = F_28 ( V_11 ) ;
if ( V_20 ) {
F_34 ( & V_18 -> V_33 , L_3 , V_20 ) ;
goto V_83;
}
for ( V_4 = 0 ; V_4 < V_2 -> V_5 -> V_7 ; ++ V_4 )
V_2 -> V_8 [ V_4 ] . V_84 = V_85 [ V_4 ] ;
V_20 = F_36 ( & V_2 -> V_18 -> V_33 , V_2 -> V_5 -> V_7 ,
V_2 -> V_8 ) ;
if ( V_20 ) {
F_34 ( & V_18 -> V_33 , L_4 , V_20 ) ;
goto V_86;
}
V_20 = F_37 ( V_2 -> V_5 -> V_7 , V_2 -> V_8 ) ;
if ( V_20 ) {
F_34 ( & V_18 -> V_33 , L_5 , V_20 ) ;
goto V_87;
}
V_20 = F_38 ( V_11 ) ;
if ( V_20 ) {
F_34 ( & V_18 -> V_33 , L_6 , V_20 ) ;
goto V_88;
}
return 0 ;
V_88:
F_39 ( V_2 -> V_5 -> V_7 , V_2 -> V_8 ) ;
V_87:
F_40 ( V_2 -> V_5 -> V_7 , V_2 -> V_8 ) ;
V_86:
F_41 ( V_11 -> V_68 ) ;
V_83:
F_42 ( V_11 ) ;
return V_20 ;
}
static int F_43 ( struct V_73 * V_18 )
{
struct V_10 * V_11 = F_44 ( V_18 ) ;
struct V_1 * V_2 = F_5 ( V_11 ) ;
F_45 ( V_11 ) ;
F_41 ( V_11 -> V_68 ) ;
F_39 ( V_2 -> V_5 -> V_7 , V_2 -> V_8 ) ;
F_40 ( V_2 -> V_5 -> V_7 , V_2 -> V_8 ) ;
F_42 ( V_11 ) ;
return 0 ;
}
