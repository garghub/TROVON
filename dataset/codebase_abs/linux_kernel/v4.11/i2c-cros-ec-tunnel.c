static int F_1 ( const struct V_1 V_2 [] , int V_3 )
{
int V_4 ;
int V_5 ;
V_5 = sizeof( struct V_6 ) ;
V_5 += V_3 * sizeof( struct V_7 ) ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
if ( ! ( V_2 [ V_4 ] . V_8 & V_9 ) )
V_5 += V_2 [ V_4 ] . V_10 ;
return V_5 ;
}
static int F_2 ( T_1 * V_11 , const struct V_1 V_2 [] ,
int V_3 , T_2 V_12 )
{
struct V_6 * V_13 ;
T_1 * V_14 ;
int V_4 ;
V_14 = V_11 + sizeof( struct V_6 ) +
V_3 * sizeof( struct V_7 ) ;
V_13 = (struct V_6 * ) V_11 ;
V_13 -> V_15 = V_12 ;
V_13 -> V_16 = V_3 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
const struct V_1 * V_1 = & V_2 [ V_4 ] ;
struct V_7 * V_17 = & V_13 -> V_17 [ V_4 ] ;
V_17 -> V_10 = V_1 -> V_10 ;
V_17 -> V_18 = V_1 -> V_19 ;
if ( V_1 -> V_8 & V_20 )
return - V_21 ;
if ( V_1 -> V_8 & V_9 ) {
V_17 -> V_18 |= V_22 ;
} else {
memcpy ( V_14 , V_1 -> V_11 , V_17 -> V_10 ) ;
V_14 += V_17 -> V_10 ;
}
}
return 0 ;
}
static int F_3 ( struct V_1 V_2 [] , int V_3 )
{
int V_5 ;
int V_4 ;
V_5 = sizeof( struct V_23 ) ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
if ( V_2 [ V_4 ] . V_8 & V_9 )
V_5 += V_2 [ V_4 ] . V_10 ;
return V_5 ;
}
static int F_4 ( const T_1 * V_11 , struct V_1 V_2 [] ,
int * V_3 )
{
const struct V_23 * V_24 ;
const T_1 * V_25 ;
int V_4 ;
V_25 = V_11 + sizeof( struct V_23 ) ;
V_24 = ( const struct V_23 * ) V_11 ;
if ( V_24 -> V_26 & V_27 )
return - V_28 ;
else if ( V_24 -> V_26 & V_29 )
return - V_30 ;
else if ( V_24 -> V_26 & V_31 )
return - V_32 ;
if ( V_24 -> V_16 > * V_3 )
return - V_33 ;
* V_3 = V_24 -> V_16 ;
for ( V_4 = 0 ; V_4 < * V_3 ; V_4 ++ ) {
struct V_1 * V_1 = & V_2 [ V_4 ] ;
if ( V_2 [ V_4 ] . V_8 & V_9 ) {
memcpy ( V_1 -> V_11 , V_25 , V_1 -> V_10 ) ;
V_25 += V_1 -> V_10 ;
}
}
return 0 ;
}
static int F_5 ( struct V_34 * V_35 , struct V_1 V_2 [] ,
int V_3 )
{
struct V_36 * V_37 = V_35 -> V_38 ;
struct V_39 * V_40 = V_37 -> V_40 ;
const T_2 V_12 = V_37 -> V_41 ;
int V_42 ;
int V_43 ;
int V_44 ;
int V_45 ;
struct V_46 * V_17 ;
V_42 = F_1 ( V_2 , V_3 ) ;
if ( V_42 < 0 ) {
F_6 ( V_40 , L_1 , V_42 ) ;
return V_42 ;
}
V_43 = F_3 ( V_2 , V_3 ) ;
if ( V_43 < 0 ) {
F_6 ( V_40 , L_2 , V_43 ) ;
return V_43 ;
}
V_44 = F_7 ( V_42 , V_43 ) ;
V_17 = F_8 ( sizeof( * V_17 ) + V_44 , V_47 ) ;
if ( ! V_17 )
return - V_48 ;
V_45 = F_2 ( V_17 -> V_49 , V_2 , V_3 , V_12 ) ;
if ( V_45 ) {
F_9 ( V_40 , L_3 , V_45 ) ;
goto exit;
}
V_17 -> V_50 = 0 ;
V_17 -> V_51 = V_52 ;
V_17 -> V_53 = V_42 ;
V_17 -> V_54 = V_43 ;
V_45 = F_10 ( V_37 -> V_55 , V_17 ) ;
if ( V_45 < 0 ) {
F_9 ( V_40 , L_4 , V_45 ) ;
goto exit;
}
V_45 = F_4 ( V_17 -> V_49 , V_2 , & V_3 ) ;
if ( V_45 < 0 )
goto exit;
V_45 = V_3 ;
exit:
F_11 ( V_17 ) ;
return V_45 ;
}
static T_3 F_12 ( struct V_34 * V_35 )
{
return V_56 | V_57 ;
}
static int F_13 ( struct V_58 * V_59 )
{
struct V_60 * V_61 = V_59 -> V_40 . V_62 ;
struct V_63 * V_55 = F_14 ( V_59 -> V_40 . V_64 ) ;
struct V_39 * V_40 = & V_59 -> V_40 ;
struct V_36 * V_37 = NULL ;
T_3 V_41 ;
int V_65 ;
if ( ! V_55 -> V_66 ) {
F_9 ( V_40 , L_5 ) ;
return - V_21 ;
}
V_37 = F_15 ( V_40 , sizeof( * V_37 ) , V_47 ) ;
if ( V_37 == NULL )
return - V_48 ;
V_65 = F_16 ( V_61 , L_6 , & V_41 ) ;
if ( V_65 ) {
F_9 ( V_40 , L_7 ) ;
return V_65 ;
}
V_37 -> V_41 = V_41 ;
V_37 -> V_55 = V_55 ;
V_37 -> V_40 = V_40 ;
V_37 -> V_35 . V_67 = V_68 ;
F_17 ( V_37 -> V_35 . V_69 , L_8 , sizeof( V_37 -> V_35 . V_69 ) ) ;
V_37 -> V_35 . V_70 = & V_71 ;
V_37 -> V_35 . V_38 = V_37 ;
V_37 -> V_35 . V_40 . V_64 = & V_59 -> V_40 ;
V_37 -> V_35 . V_40 . V_62 = V_61 ;
V_37 -> V_35 . V_72 = V_73 ;
V_65 = F_18 ( & V_37 -> V_35 ) ;
if ( V_65 )
return V_65 ;
F_19 ( V_59 , V_37 ) ;
return V_65 ;
}
static int F_20 ( struct V_58 * V_40 )
{
struct V_36 * V_37 = F_21 ( V_40 ) ;
F_22 ( & V_37 -> V_35 ) ;
return 0 ;
}
