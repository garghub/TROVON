static inline T_1 F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_6 * V_7 ,
int * V_8 , int * V_9 )
{
int V_10 ;
V_10 = ( F_6 ( ( V_8 [ 1 ] - V_8 [ 2 ] ) * 137 )
/ ( V_8 [ 0 ] - V_8 [ 2 ] ) ) - F_6 ( 41 ) ;
V_7 -> V_11 = F_7 ( F_6 ( V_9 [ 1 ] - V_9 [ 2 ] ) ,
V_10 - F_6 ( V_12 ) ) ;
V_7 -> V_13 = F_6 ( V_9 [ 2 ] ) - V_7 -> V_11 * V_12 ;
V_7 -> V_14 = F_7 ( F_6 ( V_9 [ 1 ] - V_9 [ 0 ] ) ,
V_10 - F_6 ( V_15 ) ) ;
V_7 -> V_16 = F_6 ( V_9 [ 0 ] ) - V_7 -> V_14 * V_15 ;
}
static int F_8 ( int V_17 )
{
int V_18 , V_19 ;
V_19 = V_17 >= 0 ? V_20 / 2 :
- V_20 / 2 ;
V_18 = ( V_17 + V_19 ) / V_20 ;
return V_18 * V_20 ;
}
static int F_9 ( void * V_21 , int * V_17 )
{
struct V_1 * V_2 = V_21 ;
int V_22 , V_23 , V_24 ;
T_1 V_3 ;
V_3 = F_1 ( V_2 , V_25 ) & V_26 ;
V_23 = F_7 ( F_6 ( V_3 ) - V_2 -> V_7 . V_13 , V_2 -> V_7 . V_11 ) ;
V_24 = F_7 ( F_6 ( V_3 ) - V_2 -> V_7 . V_16 , V_2 -> V_7 . V_14 ) ;
V_22 = F_10 ( ( V_23 + V_24 ) / 2 ) ;
if ( ( V_22 < F_11 ( - 40 ) ) || ( V_22 > F_11 ( 125 ) ) )
return - V_27 ;
* V_17 = F_8 ( V_22 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
int V_22 )
{
int V_28 , V_23 , V_24 ;
V_28 = F_13 ( V_22 , 1000 ) ;
V_23 = V_28 * V_2 -> V_7 . V_11 + V_2 -> V_7 . V_13 ;
V_24 = V_28 * V_2 -> V_7 . V_14 + V_2 -> V_7 . V_16 ;
return F_14 ( ( V_23 + V_24 ) / 2 ) ;
}
static int F_15 ( void * V_21 , int V_29 , int V_30 )
{
struct V_1 * V_2 = V_21 ;
V_29 = F_16 ( V_29 , - 40000 , 125000 ) ;
V_30 = F_16 ( V_30 , - 40000 , 125000 ) ;
F_3 ( V_2 , V_31 ,
F_12 ( V_2 , V_29 ) ) ;
F_3 ( V_2 , V_32 ,
F_12 ( V_2 , V_30 ) ) ;
V_2 -> V_29 = V_29 ;
V_2 -> V_30 = V_30 ;
return 0 ;
}
static void F_17 ( struct V_33 * V_34 , bool V_35 )
{
unsigned int V_36 ;
T_1 V_37 = V_35 ? V_38 | V_39 : 0 ;
for ( V_36 = 0 ; V_36 < V_34 -> V_40 ; V_36 ++ )
F_3 ( V_34 -> V_41 [ V_36 ] , V_42 , V_37 ) ;
}
static T_2 F_18 ( int V_43 , void * V_5 )
{
struct V_33 * V_34 = V_5 ;
T_1 V_44 ;
int V_36 , V_45 = V_46 ;
F_19 ( & V_34 -> V_47 ) ;
for ( V_36 = 0 ; V_36 < V_34 -> V_40 ; V_36 ++ ) {
V_44 = F_1 ( V_34 -> V_41 [ V_36 ] , V_48 ) ;
F_3 ( V_34 -> V_41 [ V_36 ] , V_48 , 0 ) ;
if ( V_44 )
V_45 = V_49 ;
}
if ( V_45 == V_49 )
F_17 ( V_34 , false ) ;
F_20 ( & V_34 -> V_47 ) ;
return V_45 ;
}
static T_2 F_21 ( int V_43 , void * V_5 )
{
struct V_33 * V_34 = V_5 ;
unsigned long V_50 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_34 -> V_40 ; V_36 ++ )
F_22 ( V_34 -> V_41 [ V_36 ] -> V_51 ,
V_52 ) ;
F_23 ( & V_34 -> V_47 , V_50 ) ;
F_17 ( V_34 , true ) ;
F_24 ( & V_34 -> V_47 , V_50 ) ;
return V_46 ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_53 , V_54 ) ;
F_3 ( V_2 , V_53 , 0x0 ) ;
F_26 ( 1000 , 2000 ) ;
F_3 ( V_2 , V_53 , V_55 ) ;
F_3 ( V_2 , V_56 , 0x3F ) ;
F_3 ( V_2 , V_42 , 0 ) ;
F_3 ( V_2 , V_57 , V_38 | V_39 ) ;
F_3 ( V_2 , V_53 ,
V_55 | V_58 | V_54 | V_59 ) ;
F_26 ( 100 , 200 ) ;
F_3 ( V_2 , V_53 ,
V_55 | V_58 | V_54 | V_59 |
V_60 | V_61 ) ;
F_26 ( 1000 , 2000 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
T_1 V_62 ;
V_62 = F_1 ( V_2 , V_63 ) ;
V_62 &= ~ V_64 ;
F_3 ( V_2 , V_63 , V_62 ) ;
F_26 ( 1000 , 2000 ) ;
F_3 ( V_2 , V_56 , 0x3F ) ;
F_3 ( V_2 , V_42 , 0 ) ;
F_3 ( V_2 , V_57 , V_38 | V_39 ) ;
V_62 = F_1 ( V_2 , V_63 ) ;
V_62 |= V_65 ;
F_3 ( V_2 , V_63 , V_62 ) ;
F_26 ( 1000 , 2000 ) ;
}
static int F_28 ( struct V_66 * V_67 )
{
struct V_68 * V_69 = & V_67 -> V_69 ;
F_29 ( V_69 ) ;
F_30 ( V_69 ) ;
return 0 ;
}
static int F_31 ( struct V_66 * V_67 )
{
struct V_33 * V_34 ;
struct V_68 * V_69 = & V_67 -> V_69 ;
struct V_70 * V_71 ;
struct V_72 * V_51 ;
int V_45 , V_43 , V_36 ;
char * V_73 ;
int V_8 [ 3 ] = { 2351 , 1509 , 435 } ;
int V_9 [ V_74 ] [ 3 ] = {
{ 3248 , 2800 , 2221 } ,
{ 3245 , 2795 , 2216 } ,
{ 3250 , 2805 , 2237 } ,
} ;
V_34 = F_32 ( V_69 , sizeof( * V_34 ) , V_75 ) ;
if ( ! V_34 )
return - V_76 ;
V_34 -> V_5 = F_33 ( V_69 ) ;
F_34 ( & V_34 -> V_47 ) ;
F_35 ( V_67 , V_34 ) ;
for ( V_36 = 0 ; V_36 < 2 ; V_36 ++ ) {
V_43 = F_36 ( V_67 , V_36 ) ;
if ( V_43 < 0 )
return V_43 ;
V_73 = F_37 ( V_69 , V_75 , L_1 ,
F_38 ( V_69 ) , V_36 ) ;
if ( ! V_73 )
return - V_76 ;
V_45 = F_39 ( V_69 , V_43 , F_18 ,
F_21 ,
V_77 , V_73 , V_34 ) ;
if ( V_45 )
return V_45 ;
}
F_40 ( V_69 ) ;
F_41 ( V_69 ) ;
for ( V_36 = 0 ; V_36 < V_74 ; V_36 ++ ) {
struct V_1 * V_2 ;
V_71 = F_42 ( V_67 , V_78 , V_36 ) ;
if ( ! V_71 )
break;
V_2 = F_32 ( V_69 , sizeof( * V_2 ) , V_75 ) ;
if ( ! V_2 ) {
V_45 = - V_76 ;
goto V_79;
}
V_2 -> V_4 = F_43 ( V_69 , V_71 ) ;
if ( F_44 ( V_2 -> V_4 ) ) {
V_45 = F_45 ( V_2 -> V_4 ) ;
goto V_79;
}
V_34 -> V_41 [ V_36 ] = V_2 ;
V_34 -> V_5 -> V_80 ( V_2 ) ;
F_5 ( & V_2 -> V_7 , V_8 , V_9 [ V_36 ] ) ;
V_51 = F_46 ( V_69 , V_36 , V_2 ,
& V_81 ) ;
if ( F_44 ( V_51 ) ) {
F_47 ( V_69 , L_2 ) ;
V_45 = F_45 ( V_51 ) ;
goto V_79;
}
V_2 -> V_51 = V_51 ;
V_45 = F_48 ( V_2 -> V_51 ) ;
if ( V_45 < 0 )
goto V_79;
F_49 ( V_69 , L_3 , V_36 , V_45 ) ;
}
V_34 -> V_40 = V_36 ;
if ( ! V_34 -> V_40 ) {
V_45 = - V_82 ;
goto V_79;
}
F_17 ( V_34 , true ) ;
return 0 ;
V_79:
F_28 ( V_67 ) ;
return V_45 ;
}
static int T_3 F_50 ( struct V_68 * V_69 )
{
struct V_33 * V_34 = F_51 ( V_69 ) ;
F_17 ( V_34 , false ) ;
return 0 ;
}
static int T_3 F_52 ( struct V_68 * V_69 )
{
struct V_33 * V_34 = F_51 ( V_69 ) ;
unsigned int V_36 ;
for ( V_36 = 0 ; V_36 < V_34 -> V_40 ; V_36 ++ ) {
struct V_1 * V_2 = V_34 -> V_41 [ V_36 ] ;
V_34 -> V_5 -> V_80 ( V_2 ) ;
F_15 ( V_2 , V_2 -> V_29 , V_2 -> V_30 ) ;
}
F_17 ( V_34 , true ) ;
return 0 ;
}
