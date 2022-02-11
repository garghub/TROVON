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
V_17 -> V_18 |= V_21 ;
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
if ( V_24 -> V_16 > * V_3 )
return - V_31 ;
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
static int F_5 ( struct V_32 * V_33 , struct V_1 V_2 [] ,
int V_3 )
{
struct V_34 * V_35 = V_33 -> V_36 ;
struct V_37 * V_38 = V_35 -> V_38 ;
const T_2 V_12 = V_35 -> V_39 ;
int V_40 ;
int V_41 ;
T_1 * V_42 = NULL ;
T_1 * V_43 = NULL ;
int V_44 ;
struct V_45 V_17 ;
V_40 = F_1 ( V_2 , V_3 ) ;
if ( V_40 < 0 ) {
F_6 ( V_38 , L_1 , V_40 ) ;
V_44 = V_40 ;
goto exit;
}
V_41 = F_3 ( V_2 , V_3 ) ;
if ( V_41 < 0 ) {
F_6 ( V_38 , L_2 , V_41 ) ;
V_44 = V_41 ;
goto exit;
}
if ( V_40 <= F_7 ( V_35 -> V_46 ) ) {
V_42 = V_35 -> V_46 ;
} else {
V_42 = F_8 ( V_40 , V_47 ) ;
if ( V_42 == NULL ) {
V_44 = - V_48 ;
goto exit;
}
}
if ( V_41 <= F_7 ( V_35 -> V_49 ) ) {
V_43 = V_35 -> V_49 ;
} else {
V_43 = F_8 ( V_41 , V_47 ) ;
if ( V_43 == NULL ) {
V_44 = - V_48 ;
goto exit;
}
}
F_2 ( V_42 , V_2 , V_3 , V_12 ) ;
V_17 . V_50 = 0 ;
V_17 . V_51 = V_52 ;
V_17 . V_53 = V_42 ;
V_17 . V_54 = V_40 ;
V_17 . V_55 = V_43 ;
V_17 . V_56 = V_41 ;
V_44 = V_35 -> V_57 -> V_58 ( V_35 -> V_57 , & V_17 ) ;
if ( V_44 < 0 )
goto exit;
V_44 = F_4 ( V_43 , V_2 , & V_3 ) ;
if ( V_44 < 0 )
goto exit;
V_44 = V_3 ;
exit:
if ( V_42 != V_35 -> V_46 )
F_9 ( V_42 ) ;
if ( V_43 != V_35 -> V_49 )
F_9 ( V_43 ) ;
return V_44 ;
}
static T_3 F_10 ( struct V_32 * V_33 )
{
return V_59 | V_60 ;
}
static int F_11 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = V_62 -> V_38 . V_65 ;
struct V_66 * V_57 = F_12 ( V_62 -> V_38 . V_67 ) ;
struct V_37 * V_38 = & V_62 -> V_38 ;
struct V_34 * V_35 = NULL ;
T_3 V_39 ;
int V_68 ;
if ( ! V_57 -> V_58 ) {
F_13 ( V_38 , L_3 ) ;
return - V_69 ;
}
V_35 = F_14 ( V_38 , sizeof( * V_35 ) , V_47 ) ;
if ( V_35 == NULL )
return - V_48 ;
V_68 = F_15 ( V_64 , L_4 , & V_39 ) ;
if ( V_68 ) {
F_13 ( V_38 , L_5 ) ;
return V_68 ;
}
V_35 -> V_39 = V_39 ;
V_35 -> V_57 = V_57 ;
V_35 -> V_38 = V_38 ;
V_35 -> V_33 . V_70 = V_71 ;
F_16 ( V_35 -> V_33 . V_72 , L_6 , sizeof( V_35 -> V_33 . V_72 ) ) ;
V_35 -> V_33 . V_73 = & V_74 ;
V_35 -> V_33 . V_36 = V_35 ;
V_35 -> V_33 . V_38 . V_67 = & V_62 -> V_38 ;
V_35 -> V_33 . V_38 . V_65 = V_64 ;
V_68 = F_17 ( & V_35 -> V_33 ) ;
if ( V_68 ) {
F_13 ( V_38 , L_7 ) ;
return V_68 ;
}
F_18 ( V_62 , V_35 ) ;
return V_68 ;
}
static int F_19 ( struct V_61 * V_38 )
{
struct V_34 * V_35 = F_20 ( V_38 ) ;
F_21 ( & V_35 -> V_33 ) ;
return 0 ;
}
