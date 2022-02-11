static unsigned int F_1 ( void T_1 * V_1 , int V_2 )
{
T_2 V_3 ;
V_3 = ( F_2 ( V_1 ) >> V_2 ) & 0x7 ;
if ( V_3 > 6 )
return 0 ;
return V_3 ;
}
static unsigned long F_3 ( struct V_4 * V_5 ,
unsigned long V_6 )
{
struct V_7 * V_8 = F_4 ( V_5 ) ;
unsigned int div ;
div = F_1 ( V_8 -> V_9 , V_8 -> V_10 ) ;
div *= F_1 ( V_8 -> V_11 , V_8 -> V_12 ) ;
return F_5 ( ( V_13 ) V_6 , div ) ;
}
static int F_6 ( const struct V_14 * V_15 ,
void T_1 * V_1 , T_3 * V_16 ,
struct V_17 * V_18 , struct V_4 * * V_5 )
{
const struct V_19 * V_20 = NULL , * V_21 = NULL ,
* V_22 = NULL ;
struct V_4 * V_23 = NULL , * V_24 = NULL , * V_25 = NULL ;
if ( V_15 -> V_23 ) {
struct V_26 * V_27 ;
V_23 = V_15 -> V_23 ;
V_27 = F_7 ( V_23 ) ;
V_27 -> V_16 = V_16 ;
V_20 = V_23 -> V_28 -> V_29 ;
V_27 -> V_1 = V_1 + ( V_13 ) V_27 -> V_1 ;
}
if ( V_15 -> V_24 ) {
struct V_30 * V_31 ;
V_24 = V_15 -> V_24 ;
V_31 = F_8 ( V_24 ) ;
V_31 -> V_16 = V_16 ;
V_21 = V_24 -> V_28 -> V_29 ;
V_31 -> V_1 = V_1 + ( V_13 ) V_31 -> V_1 ;
V_31 -> V_32 = V_33 ;
}
if ( V_15 -> V_25 ) {
V_25 = V_15 -> V_25 ;
V_22 = V_25 -> V_28 -> V_29 ;
if ( V_15 -> V_34 ) {
struct V_7 * V_35 ;
V_35 = F_4 ( V_25 ) ;
V_35 -> V_9 = V_1 + ( V_13 ) V_35 -> V_9 ;
V_35 -> V_11 = V_1 + ( V_13 ) V_35 -> V_11 ;
} else {
struct V_36 * V_35 = F_9 ( V_25 ) ;
const struct V_37 * V_38 ;
int V_39 = 0 ;
V_35 -> V_1 = V_1 + ( V_13 ) V_35 -> V_1 ;
for ( V_38 = V_35 -> V_40 ; V_38 -> div ; V_38 ++ )
V_39 ++ ;
V_35 -> V_41 = F_10 ( V_39 ) ;
V_35 -> V_16 = V_16 ;
}
}
* V_5 = F_11 ( V_18 , V_15 -> V_42 , V_15 -> V_43 ,
V_15 -> V_44 , V_23 ,
V_20 , V_25 , V_22 ,
V_24 , V_21 , V_45 ) ;
if ( F_12 ( * V_5 ) )
return F_13 ( * V_5 ) ;
return 0 ;
}
static int F_14 ( struct V_46 * V_47 )
{
struct V_48 * V_49 ;
struct V_50 * V_51 = V_47 -> V_18 . V_52 ;
const struct V_14 * V_15 ;
struct V_17 * V_18 = & V_47 -> V_18 ;
int V_53 = 0 , V_54 , V_55 ;
struct V_56 * V_57 ;
void T_1 * V_1 ;
V_15 = F_15 ( V_18 ) ;
if ( ! V_15 )
return - V_58 ;
while ( V_15 [ V_53 ] . V_42 )
V_53 ++ ;
V_57 = F_16 ( V_47 , V_59 , 0 ) ;
V_1 = F_17 ( V_18 , V_57 ) ;
if ( F_12 ( V_1 ) )
return F_13 ( V_1 ) ;
V_49 = F_18 ( V_18 , sizeof( * V_49 ) , V_60 ) ;
if ( ! V_49 )
return - V_61 ;
V_49 -> V_62 = F_18 ( V_18 , sizeof( * V_49 -> V_62 ) +
sizeof( * V_49 -> V_62 -> V_63 ) * V_53 ,
V_60 ) ;
if ( ! V_49 -> V_62 )
return - V_61 ;
V_49 -> V_62 -> V_64 = V_53 ;
F_19 ( & V_49 -> V_16 ) ;
for ( V_54 = 0 ; V_54 < V_53 ; V_54 ++ ) {
struct V_4 * * V_5 = & V_49 -> V_62 -> V_63 [ V_54 ] ;
if ( F_6 ( & V_15 [ V_54 ] , V_1 ,
& V_49 -> V_16 , V_18 , V_5 ) )
F_20 ( V_18 , L_1 ,
V_15 [ V_54 ] . V_42 ) ;
}
V_55 = F_21 ( V_51 , V_65 ,
V_49 -> V_62 ) ;
if ( V_55 ) {
for ( V_54 = 0 ; V_54 < V_53 ; V_54 ++ )
F_22 ( V_49 -> V_62 -> V_63 [ V_54 ] ) ;
return V_55 ;
}
F_23 ( V_47 , V_49 ) ;
return 0 ;
}
static int F_24 ( struct V_46 * V_47 )
{
struct V_48 * V_15 = F_25 ( V_47 ) ;
struct V_66 * V_62 = V_15 -> V_62 ;
int V_54 ;
F_26 ( V_47 -> V_18 . V_52 ) ;
for ( V_54 = 0 ; V_54 < V_62 -> V_64 ; V_54 ++ )
F_22 ( V_62 -> V_63 [ V_54 ] ) ;
return 0 ;
}
