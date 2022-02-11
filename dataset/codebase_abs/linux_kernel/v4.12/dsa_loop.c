static enum V_1 F_1 ( struct V_2 * V_3 )
{
F_2 ( V_3 -> V_4 , L_1 , V_5 ) ;
return V_6 ;
}
static int F_3 ( struct V_2 * V_3 )
{
F_2 ( V_3 -> V_4 , L_1 , V_5 ) ;
return 0 ;
}
static int F_4 ( struct V_2 * V_3 , T_1 * V_7 )
{
F_2 ( V_3 -> V_4 , L_1 , V_5 ) ;
return 0 ;
}
static int F_5 ( struct V_2 * V_3 , int V_8 , int V_9 )
{
struct V_10 * V_11 = V_3 -> V_12 ;
struct V_13 * V_14 = V_11 -> V_14 ;
F_2 ( V_3 -> V_4 , L_1 , V_5 ) ;
return F_6 ( V_14 , V_11 -> V_15 + V_8 , V_9 ) ;
}
static int F_7 ( struct V_2 * V_3 , int V_8 ,
int V_9 , T_2 V_16 )
{
struct V_10 * V_11 = V_3 -> V_12 ;
struct V_13 * V_14 = V_11 -> V_14 ;
F_2 ( V_3 -> V_4 , L_1 , V_5 ) ;
return F_8 ( V_14 , V_11 -> V_15 + V_8 , V_9 , V_16 ) ;
}
static int F_9 ( struct V_2 * V_3 , int V_8 ,
struct V_17 * V_18 )
{
F_2 ( V_3 -> V_4 , L_1 , V_5 ) ;
return 0 ;
}
static void F_10 ( struct V_2 * V_3 , int V_8 ,
struct V_17 * V_18 )
{
F_2 ( V_3 -> V_4 , L_1 , V_5 ) ;
}
static void F_11 ( struct V_2 * V_3 , int V_8 ,
T_1 V_19 )
{
F_2 ( V_3 -> V_4 , L_1 , V_5 ) ;
}
static int F_12 ( struct V_2 * V_3 , int V_8 ,
bool V_20 )
{
F_2 ( V_3 -> V_4 , L_1 , V_5 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 , int V_8 ,
const struct V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_10 * V_11 = V_3 -> V_12 ;
struct V_13 * V_14 = V_11 -> V_14 ;
F_2 ( V_3 -> V_4 , L_1 , V_5 ) ;
F_14 ( V_14 , V_11 -> V_15 + V_8 , V_25 ) ;
if ( V_22 -> V_26 > V_27 )
return - V_28 ;
return 0 ;
}
static void F_15 ( struct V_2 * V_3 , int V_8 ,
const struct V_21 * V_22 ,
struct V_23 * V_24 )
{
bool V_29 = V_22 -> V_30 & V_31 ;
bool V_32 = V_22 -> V_30 & V_33 ;
struct V_10 * V_11 = V_3 -> V_12 ;
struct V_13 * V_14 = V_11 -> V_14 ;
struct V_34 * V_35 ;
T_2 V_36 ;
F_2 ( V_3 -> V_4 , L_1 , V_5 ) ;
F_14 ( V_14 , V_11 -> V_15 + V_8 , V_25 ) ;
for ( V_36 = V_22 -> V_37 ; V_36 <= V_22 -> V_26 ; ++ V_36 ) {
V_35 = & V_11 -> V_38 [ V_36 ] ;
V_35 -> V_39 |= F_16 ( V_8 ) ;
if ( V_29 )
V_35 -> V_29 |= F_16 ( V_8 ) ;
else
V_35 -> V_29 &= ~ F_16 ( V_8 ) ;
}
if ( V_32 )
V_11 -> V_32 = V_36 ;
}
static int F_17 ( struct V_2 * V_3 , int V_8 ,
const struct V_21 * V_22 )
{
bool V_29 = V_22 -> V_30 & V_31 ;
struct V_10 * V_11 = V_3 -> V_12 ;
struct V_13 * V_14 = V_11 -> V_14 ;
struct V_34 * V_35 ;
T_2 V_36 , V_32 = V_11 -> V_32 ;
F_2 ( V_3 -> V_4 , L_1 , V_5 ) ;
F_14 ( V_14 , V_11 -> V_15 + V_8 , V_25 ) ;
for ( V_36 = V_22 -> V_37 ; V_36 <= V_22 -> V_26 ; ++ V_36 ) {
V_35 = & V_11 -> V_38 [ V_36 ] ;
V_35 -> V_39 &= ~ F_16 ( V_8 ) ;
if ( V_29 )
V_35 -> V_29 &= ~ F_16 ( V_8 ) ;
if ( V_32 == V_36 )
V_32 = 1 ;
}
V_11 -> V_32 = V_32 ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 , int V_8 ,
struct V_21 * V_22 ,
int (* F_19)( struct V_40 * V_41 ) )
{
struct V_10 * V_11 = V_3 -> V_12 ;
struct V_13 * V_14 = V_11 -> V_14 ;
struct V_34 * V_35 ;
T_2 V_36 , V_42 = 0 ;
int V_43 = 0 ;
F_2 ( V_3 -> V_4 , L_1 , V_5 ) ;
F_14 ( V_14 , V_11 -> V_15 + V_8 , V_25 ) ;
for ( V_36 = V_42 ; V_36 < V_27 ; V_36 ++ ) {
V_35 = & V_11 -> V_38 [ V_36 ] ;
if ( ! ( V_35 -> V_39 & F_16 ( V_8 ) ) )
continue;
V_22 -> V_37 = V_22 -> V_26 = V_36 ;
V_22 -> V_30 = 0 ;
if ( V_35 -> V_29 & F_16 ( V_8 ) )
V_22 -> V_30 |= V_31 ;
if ( V_11 -> V_32 == V_36 )
V_22 -> V_30 |= V_33 ;
V_43 = F_19 ( & V_22 -> V_41 ) ;
if ( V_43 )
break;
}
return V_43 ;
}
static int F_20 ( struct V_44 * V_45 )
{
struct V_46 * V_47 = V_45 -> V_4 . V_48 ;
struct V_10 * V_11 ;
struct V_2 * V_3 ;
if ( ! V_47 )
return - V_49 ;
F_21 ( & V_45 -> V_4 , L_2 ,
V_47 -> V_50 , V_47 -> V_51 ) ;
V_3 = F_22 ( & V_45 -> V_4 , V_52 ) ;
if ( ! V_3 )
return - V_53 ;
V_11 = F_23 ( & V_45 -> V_4 , sizeof( * V_11 ) , V_54 ) ;
if ( ! V_11 )
return - V_53 ;
V_11 -> V_55 = F_24 ( & V_56 , V_47 -> V_55 ) ;
if ( ! V_11 -> V_55 )
return - V_57 ;
V_47 -> V_58 . V_55 [ V_59 ] = & V_11 -> V_55 -> V_4 ;
V_3 -> V_4 = & V_45 -> V_4 ;
V_3 -> V_60 = & V_61 ;
V_3 -> V_12 = V_11 ;
V_11 -> V_14 = V_45 -> V_14 ;
F_25 ( & V_45 -> V_4 , V_3 ) ;
return F_26 ( V_3 , V_3 -> V_4 ) ;
}
static void F_27 ( struct V_44 * V_45 )
{
struct V_2 * V_3 = F_28 ( & V_45 -> V_4 ) ;
struct V_10 * V_11 = V_3 -> V_12 ;
F_29 ( V_3 ) ;
F_30 ( V_11 -> V_55 ) ;
}
static void F_31 ( void )
{
unsigned int V_62 ;
for ( V_62 = 0 ; V_62 < V_63 ; V_62 ++ )
if ( V_64 [ V_62 ] )
F_32 ( V_64 [ V_62 ] ) ;
}
static int T_3 F_33 ( void )
{
struct V_65 V_66 = {
. V_67 = 1 ,
. V_68 = V_69 ,
. V_70 = V_71 ,
} ;
unsigned int V_62 ;
for ( V_62 = 0 ; V_62 < V_63 ; V_62 ++ )
V_64 [ V_62 ] = F_34 ( V_72 , & V_66 , - 1 , NULL ) ;
return F_35 ( & V_73 ) ;
}
static void T_4 F_36 ( void )
{
F_37 ( & V_73 ) ;
F_31 () ;
}
