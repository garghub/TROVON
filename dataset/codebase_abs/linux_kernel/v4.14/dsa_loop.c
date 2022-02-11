static enum V_1 F_1 ( struct V_2 * V_3 )
{
F_2 ( V_3 -> V_4 , L_1 , V_5 ) ;
return V_6 ;
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_3 -> V_11 ; V_10 ++ )
memcpy ( V_8 -> V_12 [ V_10 ] . V_13 , V_14 ,
sizeof( V_14 ) ) ;
F_2 ( V_3 -> V_4 , L_1 , V_5 ) ;
return 0 ;
}
static int F_4 ( struct V_2 * V_3 )
{
return V_15 ;
}
static void F_5 ( struct V_2 * V_3 , int V_16 , T_1 * V_17 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_15 ; V_10 ++ )
memcpy ( V_17 + V_10 * V_18 ,
V_8 -> V_12 [ V_16 ] . V_13 [ V_10 ] . V_19 , V_18 ) ;
}
static void F_6 ( struct V_2 * V_3 , int V_16 ,
T_2 * V_17 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_15 ; V_10 ++ )
V_17 [ V_10 ] = V_8 -> V_12 [ V_16 ] . V_13 [ V_10 ] . V_20 ;
}
static int F_7 ( struct V_2 * V_3 , T_3 * V_21 )
{
F_2 ( V_3 -> V_4 , L_1 , V_5 ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 , int V_16 , int V_22 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
struct V_23 * V_24 = V_8 -> V_24 ;
int V_25 ;
F_2 ( V_3 -> V_4 , L_1 , V_5 ) ;
V_25 = F_9 ( V_24 , V_8 -> V_26 + V_16 , V_22 ) ;
if ( V_25 < 0 )
V_8 -> V_12 [ V_16 ] . V_13 [ V_27 ] . V_20 ++ ;
else
V_8 -> V_12 [ V_16 ] . V_13 [ V_28 ] . V_20 ++ ;
return V_25 ;
}
static int F_10 ( struct V_2 * V_3 , int V_16 ,
int V_22 , T_4 V_29 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
struct V_23 * V_24 = V_8 -> V_24 ;
int V_25 ;
F_2 ( V_3 -> V_4 , L_1 , V_5 ) ;
V_25 = F_11 ( V_24 , V_8 -> V_26 + V_16 , V_22 , V_29 ) ;
if ( V_25 < 0 )
V_8 -> V_12 [ V_16 ] . V_13 [ V_30 ] . V_20 ++ ;
else
V_8 -> V_12 [ V_16 ] . V_13 [ V_31 ] . V_20 ++ ;
return V_25 ;
}
static int F_12 ( struct V_2 * V_3 , int V_16 ,
struct V_32 * V_33 )
{
F_2 ( V_3 -> V_4 , L_1 , V_5 ) ;
return 0 ;
}
static void F_13 ( struct V_2 * V_3 , int V_16 ,
struct V_32 * V_33 )
{
F_2 ( V_3 -> V_4 , L_1 , V_5 ) ;
}
static void F_14 ( struct V_2 * V_3 , int V_16 ,
T_3 V_34 )
{
F_2 ( V_3 -> V_4 , L_1 , V_5 ) ;
}
static int F_15 ( struct V_2 * V_3 , int V_16 ,
bool V_35 )
{
F_2 ( V_3 -> V_4 , L_1 , V_5 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 , int V_16 ,
const struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
struct V_23 * V_24 = V_8 -> V_24 ;
F_2 ( V_3 -> V_4 , L_1 , V_5 ) ;
F_17 ( V_24 , V_8 -> V_26 + V_16 , V_40 ) ;
if ( V_37 -> V_41 > V_42 )
return - V_43 ;
return 0 ;
}
static void F_18 ( struct V_2 * V_3 , int V_16 ,
const struct V_36 * V_37 ,
struct V_38 * V_39 )
{
bool V_44 = V_37 -> V_45 & V_46 ;
bool V_47 = V_37 -> V_45 & V_48 ;
struct V_7 * V_8 = V_3 -> V_9 ;
struct V_23 * V_24 = V_8 -> V_24 ;
struct V_49 * V_50 ;
T_4 V_51 ;
F_2 ( V_3 -> V_4 , L_1 , V_5 ) ;
F_17 ( V_24 , V_8 -> V_26 + V_16 , V_40 ) ;
for ( V_51 = V_37 -> V_52 ; V_51 <= V_37 -> V_41 ; ++ V_51 ) {
V_50 = & V_8 -> V_53 [ V_51 ] ;
V_50 -> V_54 |= F_19 ( V_16 ) ;
if ( V_44 )
V_50 -> V_44 |= F_19 ( V_16 ) ;
else
V_50 -> V_44 &= ~ F_19 ( V_16 ) ;
}
if ( V_47 )
V_8 -> V_47 = V_51 ;
}
static int F_20 ( struct V_2 * V_3 , int V_16 ,
const struct V_36 * V_37 )
{
bool V_44 = V_37 -> V_45 & V_46 ;
struct V_7 * V_8 = V_3 -> V_9 ;
struct V_23 * V_24 = V_8 -> V_24 ;
struct V_49 * V_50 ;
T_4 V_51 , V_47 = V_8 -> V_47 ;
F_2 ( V_3 -> V_4 , L_1 , V_5 ) ;
F_17 ( V_24 , V_8 -> V_26 + V_16 , V_40 ) ;
for ( V_51 = V_37 -> V_52 ; V_51 <= V_37 -> V_41 ; ++ V_51 ) {
V_50 = & V_8 -> V_53 [ V_51 ] ;
V_50 -> V_54 &= ~ F_19 ( V_16 ) ;
if ( V_44 )
V_50 -> V_44 &= ~ F_19 ( V_16 ) ;
if ( V_47 == V_51 )
V_47 = 1 ;
}
V_8 -> V_47 = V_47 ;
return 0 ;
}
static int F_21 ( struct V_55 * V_56 )
{
struct V_57 * V_58 = V_56 -> V_4 . V_59 ;
struct V_7 * V_8 ;
struct V_2 * V_3 ;
if ( ! V_58 )
return - V_60 ;
F_22 ( & V_56 -> V_4 , L_2 ,
V_58 -> V_19 , V_58 -> V_61 ) ;
V_3 = F_23 ( & V_56 -> V_4 , V_62 ) ;
if ( ! V_3 )
return - V_63 ;
V_8 = F_24 ( & V_56 -> V_4 , sizeof( * V_8 ) , V_64 ) ;
if ( ! V_8 )
return - V_63 ;
V_8 -> V_65 = F_25 ( & V_66 , V_58 -> V_65 ) ;
if ( ! V_8 -> V_65 )
return - V_67 ;
V_58 -> V_68 . V_65 [ V_69 ] = & V_8 -> V_65 -> V_4 ;
V_3 -> V_4 = & V_56 -> V_4 ;
V_3 -> V_70 = & V_71 ;
V_3 -> V_9 = V_8 ;
V_8 -> V_24 = V_56 -> V_24 ;
F_26 ( & V_56 -> V_4 , V_3 ) ;
return F_27 ( V_3 ) ;
}
static void F_28 ( struct V_55 * V_56 )
{
struct V_2 * V_3 = F_29 ( & V_56 -> V_4 ) ;
struct V_7 * V_8 = V_3 -> V_9 ;
F_30 ( V_3 ) ;
F_31 ( V_8 -> V_65 ) ;
}
static int T_5 F_32 ( void )
{
struct V_72 V_73 = {
. V_74 = 1 ,
. V_75 = V_76 ,
. V_77 = V_78 ,
} ;
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_79 ; V_10 ++ )
V_80 [ V_10 ] = F_33 ( V_81 , & V_73 , - 1 , NULL ) ;
return F_34 ( & V_82 ) ;
}
static void T_6 F_35 ( void )
{
unsigned int V_10 ;
F_36 ( & V_82 ) ;
for ( V_10 = 0 ; V_10 < V_79 ; V_10 ++ )
if ( ! F_37 ( V_80 [ V_10 ] ) )
F_38 ( V_80 [ V_10 ] ) ;
}
