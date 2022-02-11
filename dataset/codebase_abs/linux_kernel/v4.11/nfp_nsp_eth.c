static unsigned int F_1 ( enum F_1 V_1 )
{
unsigned int V_2 [] = {
[ V_3 ] = 0 ,
[ V_4 ] = V_5 ,
[ V_6 ] = V_7 ,
[ V_8 ] = V_9 ,
[ V_10 ] = V_11 ,
[ V_12 ] = V_13 ,
} ;
if ( V_1 >= F_2 ( V_2 ) )
return 0 ;
return V_2 [ V_1 ] ;
}
static void F_3 ( T_1 * V_14 , const T_1 * V_15 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ )
V_14 [ V_17 - V_16 - 1 ] = V_15 [ V_16 ] ;
}
static void
F_4 ( const struct V_18 * V_15 , unsigned int V_19 ,
struct V_20 * V_14 )
{
unsigned int V_1 ;
T_2 V_21 , V_22 ;
V_21 = F_5 ( V_15 -> V_21 ) ;
V_22 = F_5 ( V_15 -> V_22 ) ;
V_14 -> V_23 = F_6 ( V_24 , V_21 ) ;
V_14 -> V_19 = V_19 ;
V_14 -> V_25 = V_19 / V_26 ;
V_14 -> V_27 = V_19 % V_26 ;
V_14 -> V_28 = F_6 ( V_29 , V_21 ) ;
V_14 -> V_30 = F_6 ( V_31 , V_22 ) ;
V_14 -> V_32 = F_6 ( V_33 , V_22 ) ;
V_14 -> V_34 = F_6 ( V_35 , V_22 ) ;
V_1 = F_1 ( F_6 ( V_36 , V_22 ) ) ;
V_14 -> V_37 = V_14 -> V_28 * V_1 ;
F_3 ( V_14 -> V_38 , V_15 -> V_38 ) ;
snprintf ( V_14 -> V_39 , sizeof( V_14 -> V_39 ) - 1 , L_1 ,
F_6 ( V_40 , V_21 ) ,
F_6 ( V_41 , V_21 ) ) ;
}
struct V_42 * F_7 ( struct V_43 * V_44 )
{
struct V_42 * V_45 ;
struct V_46 * V_47 ;
V_47 = F_8 ( V_44 ) ;
if ( F_9 ( V_47 ) )
return NULL ;
V_45 = F_10 ( V_44 , V_47 ) ;
F_11 ( V_47 ) ;
return V_45 ;
}
struct V_42 *
F_10 ( struct V_43 * V_44 , struct V_46 * V_47 )
{
struct V_18 * V_48 ;
struct V_42 * V_49 ;
unsigned int V_50 ;
int V_16 , V_51 , V_45 ;
V_48 = F_12 ( V_52 , V_53 ) ;
if ( ! V_48 )
return NULL ;
V_45 = F_13 ( V_47 , V_48 , V_52 ) ;
if ( V_45 < 0 ) {
F_14 ( V_44 , L_2 , V_45 ) ;
F_15 ( V_48 ) ;
return NULL ;
}
V_50 = V_45 ;
if ( ! V_50 ) {
for ( V_16 = 0 ; V_16 < V_54 ; V_16 ++ )
if ( V_48 [ V_16 ] . V_21 & V_55 )
V_50 ++ ;
}
V_49 = F_12 ( sizeof( * V_49 ) +
sizeof( struct V_20 ) * V_50 , V_53 ) ;
if ( ! V_49 ) {
F_15 ( V_48 ) ;
return NULL ;
}
V_49 -> V_56 = V_50 ;
for ( V_16 = 0 , V_51 = 0 ; V_16 < V_54 ; V_16 ++ )
if ( V_48 [ V_16 ] . V_21 & V_55 )
F_4 ( & V_48 [ V_16 ] , V_16 ,
& V_49 -> V_57 [ V_51 ++ ] ) ;
F_15 ( V_48 ) ;
return V_49 ;
}
int F_16 ( struct V_43 * V_44 , unsigned int V_58 , bool V_59 )
{
struct V_18 * V_48 ;
struct V_46 * V_47 ;
T_2 V_60 ;
int V_45 ;
V_48 = F_12 ( V_52 , V_53 ) ;
if ( ! V_48 )
return - V_61 ;
V_47 = F_8 ( V_44 ) ;
if ( F_9 ( V_47 ) ) {
F_15 ( V_48 ) ;
return F_17 ( V_47 ) ;
}
V_45 = F_13 ( V_47 , V_48 , V_52 ) ;
if ( V_45 < 0 ) {
F_14 ( V_44 , L_2 , V_45 ) ;
goto V_62;
}
if ( ! ( V_48 [ V_58 ] . V_21 & V_55 ) ) {
F_18 ( V_44 , L_3 ,
V_58 ) ;
V_45 = - V_63 ;
goto V_62;
}
V_60 = F_5 ( V_48 [ V_58 ] . V_22 ) ;
if ( V_59 == F_6 ( V_64 , V_60 ) ) {
V_45 = 0 ;
goto V_62;
}
V_60 = F_5 ( V_48 [ V_58 ] . V_65 ) ;
V_60 &= ~ V_64 ;
V_60 |= F_19 ( V_64 , V_59 ) ;
V_48 [ V_58 ] . V_65 = F_20 ( V_60 ) ;
V_45 = F_21 ( V_47 , V_48 , V_52 ) ;
V_62:
F_11 ( V_47 ) ;
F_15 ( V_48 ) ;
return V_45 < 0 ? V_45 : 0 ;
}
