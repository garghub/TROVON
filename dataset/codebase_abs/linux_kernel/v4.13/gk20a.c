static enum V_1
F_1 ( struct V_2 * V_3 )
{
return V_4 ;
}
static T_1
F_2 ( struct V_2 * V_3 )
{
return F_3 ( V_3 ) -> V_5 . V_6 ;
}
static T_1
F_4 ( struct V_2 * V_3 )
{
return ( T_1 ) F_3 ( V_3 ) -> V_5 . V_7 << 12 ;
}
static void
F_5 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 . V_11 ;
F_6 ( V_9 -> V_13 ) ;
F_7 ( & V_9 -> V_14 ) ;
F_8 ( V_9 -> V_12 . V_15 ) ;
V_9 -> V_12 . V_15 = NULL ;
V_11 -> V_16 -= F_9 ( & V_9 -> V_12 . V_3 ) ;
F_10 ( & V_11 -> V_12 . V_17 , L_1 , V_11 -> V_16 ,
V_11 -> V_18 ) ;
}
static void
F_11 ( struct V_10 * V_11 , const T_1 V_7 )
{
while ( V_11 -> V_16 + V_7 > V_11 -> V_18 ) {
if ( F_12 ( & V_11 -> V_19 ) )
break;
F_5 (
F_13 ( & V_11 -> V_19 ,
struct V_8 , V_14 ) ) ;
}
}
static void T_2 *
F_14 ( struct V_2 * V_3 )
{
struct F_3 * V_20 = F_3 ( V_3 ) ;
struct V_10 * V_11 = V_20 -> V_11 ;
struct V_21 * V_22 = V_11 -> V_12 . V_17 . V_23 -> V_22 ;
F_15 ( V_22 ) ;
return V_20 -> V_15 ;
}
static void T_2 *
F_16 ( struct V_2 * V_3 )
{
struct V_8 * V_20 = V_8 ( V_3 ) ;
struct V_10 * V_11 = V_20 -> V_12 . V_11 ;
struct V_21 * V_22 = V_11 -> V_12 . V_17 . V_23 -> V_22 ;
const T_1 V_7 = F_9 ( V_3 ) ;
F_15 ( V_22 ) ;
F_17 ( & V_11 -> V_24 ) ;
if ( V_20 -> V_12 . V_15 ) {
if ( ! V_20 -> V_13 ) {
F_7 ( & V_20 -> V_14 ) ;
}
goto V_25;
}
F_11 ( V_11 , V_7 ) ;
V_20 -> V_12 . V_15 = F_18 ( V_20 -> V_26 , V_7 >> V_27 , V_28 ,
F_19 ( V_29 ) ) ;
if ( ! V_20 -> V_12 . V_15 ) {
F_20 ( & V_11 -> V_12 . V_17 , L_2
L_3 ) ;
goto V_25;
}
V_11 -> V_16 += V_7 ;
F_10 ( & V_11 -> V_12 . V_17 , L_1 ,
V_11 -> V_16 , V_11 -> V_18 ) ;
V_25:
V_20 -> V_13 ++ ;
F_21 ( & V_11 -> V_24 ) ;
return V_20 -> V_12 . V_15 ;
}
static void
F_22 ( struct V_2 * V_3 )
{
struct F_3 * V_20 = F_3 ( V_3 ) ;
struct V_10 * V_11 = V_20 -> V_11 ;
struct V_21 * V_22 = V_11 -> V_12 . V_17 . V_23 -> V_22 ;
F_23 () ;
F_24 ( V_22 ) ;
}
static void
F_25 ( struct V_2 * V_3 )
{
struct V_8 * V_20 = V_8 ( V_3 ) ;
struct V_10 * V_11 = V_20 -> V_12 . V_11 ;
struct V_21 * V_22 = V_11 -> V_12 . V_17 . V_23 -> V_22 ;
F_17 ( & V_11 -> V_24 ) ;
if ( F_6 ( V_20 -> V_13 == 0 ) )
goto V_25;
if ( -- V_20 -> V_13 == 0 )
F_26 ( & V_20 -> V_14 , & V_11 -> V_19 ) ;
V_25:
F_21 ( & V_11 -> V_24 ) ;
F_23 () ;
F_24 ( V_22 ) ;
}
static T_3
F_27 ( struct V_2 * V_3 , T_1 V_6 )
{
struct F_3 * V_20 = F_3 ( V_3 ) ;
return V_20 -> V_15 [ V_6 / 4 ] ;
}
static void
F_28 ( struct V_2 * V_3 , T_1 V_6 , T_3 V_30 )
{
struct F_3 * V_20 = F_3 ( V_3 ) ;
V_20 -> V_15 [ V_6 / 4 ] = V_30 ;
}
static void
F_29 ( struct V_2 * V_3 , struct V_31 * V_32 , T_1 V_6 )
{
struct F_3 * V_20 = F_3 ( V_3 ) ;
F_30 ( V_32 , V_6 , & V_20 -> V_5 ) ;
}
static void *
F_31 ( struct V_2 * V_3 )
{
struct V_33 * V_20 = V_33 ( V_3 ) ;
struct V_10 * V_11 = V_20 -> V_12 . V_11 ;
struct V_23 * V_34 = V_11 -> V_12 . V_17 . V_23 -> V_34 ;
if ( F_32 ( ! V_20 -> V_12 . V_15 ) )
goto V_25;
F_33 ( V_34 , V_20 -> V_12 . V_5 . V_7 << V_27 , V_20 -> V_12 . V_15 ,
V_20 -> V_35 , V_11 -> V_36 ) ;
V_25:
return V_20 ;
}
static void *
F_34 ( struct V_2 * V_3 )
{
struct V_8 * V_20 = V_8 ( V_3 ) ;
struct V_10 * V_11 = V_20 -> V_12 . V_11 ;
struct V_23 * V_34 = V_11 -> V_12 . V_17 . V_23 -> V_34 ;
struct V_37 * V_38 = V_20 -> V_12 . V_5 . V_5 ;
int V_39 ;
if ( F_32 ( ! V_38 ) )
goto V_25;
F_17 ( & V_11 -> V_24 ) ;
if ( V_20 -> V_12 . V_15 )
F_5 ( V_20 ) ;
F_21 ( & V_11 -> V_24 ) ;
V_38 -> V_6 &= ~ F_35 ( V_11 -> V_40 - V_11 -> V_41 ) ;
for ( V_39 = 0 ; V_39 < V_20 -> V_12 . V_5 . V_7 ; V_39 ++ ) {
F_36 ( V_11 -> V_42 ,
( V_38 -> V_6 + V_39 ) << V_11 -> V_41 , V_43 ) ;
F_37 ( V_34 , V_20 -> V_44 [ V_39 ] , V_43 ,
V_45 ) ;
F_38 ( V_20 -> V_26 [ V_39 ] ) ;
}
F_17 ( V_11 -> V_46 ) ;
F_39 ( V_11 -> V_47 , & V_38 ) ;
F_21 ( V_11 -> V_46 ) ;
V_25:
return V_20 ;
}
static int
F_40 ( struct V_10 * V_11 , T_3 V_48 , T_3 V_49 ,
struct F_3 * * V_50 )
{
struct V_33 * V_20 ;
struct V_51 * V_17 = & V_11 -> V_12 . V_17 ;
struct V_23 * V_34 = V_17 -> V_23 -> V_34 ;
if ( ! ( V_20 = F_41 ( sizeof( * V_20 ) , V_52 ) ) )
return - V_53 ;
* V_50 = & V_20 -> V_12 ;
F_42 ( & V_54 , & V_20 -> V_12 . V_3 ) ;
V_20 -> V_12 . V_15 = F_43 ( V_34 , V_48 << V_27 ,
& V_20 -> V_35 , V_52 ,
V_11 -> V_36 ) ;
if ( ! V_20 -> V_12 . V_15 ) {
F_20 ( V_17 , L_4 ) ;
return - V_53 ;
}
if ( F_32 ( V_20 -> V_35 & ( V_49 - 1 ) ) )
F_44 ( V_17 ,
L_5 ,
& V_20 -> V_35 , V_49 ) ;
V_20 -> V_38 . type = 12 ;
V_20 -> V_38 . V_6 = V_20 -> V_35 >> 12 ;
V_20 -> V_38 . V_55 = ( V_48 << V_27 ) >> 12 ;
V_20 -> V_12 . V_5 . V_6 = V_20 -> V_35 ;
V_20 -> V_12 . V_5 . V_5 = & V_20 -> V_38 ;
return 0 ;
}
static int
F_45 ( struct V_10 * V_11 , T_3 V_48 , T_3 V_49 ,
struct F_3 * * V_50 )
{
struct V_8 * V_20 ;
struct V_51 * V_17 = & V_11 -> V_12 . V_17 ;
struct V_23 * V_34 = V_17 -> V_23 -> V_34 ;
struct V_37 * V_38 ;
int V_56 ;
int V_39 ;
if ( ! ( V_20 = F_41 ( sizeof( * V_20 ) + ( ( sizeof( V_20 -> V_26 [ 0 ] ) +
sizeof( * V_20 -> V_44 ) ) * V_48 ) , V_52 ) ) )
return - V_53 ;
* V_50 = & V_20 -> V_12 ;
V_20 -> V_44 = ( void * ) ( V_20 -> V_26 + V_48 ) ;
F_42 ( & V_57 , & V_20 -> V_12 . V_3 ) ;
for ( V_39 = 0 ; V_39 < V_48 ; V_39 ++ ) {
struct V_58 * V_59 = F_46 ( V_52 ) ;
T_4 V_60 ;
if ( V_59 == NULL ) {
V_56 = - V_53 ;
goto V_61;
}
V_20 -> V_26 [ V_39 ] = V_59 ;
V_60 = F_47 ( V_34 , V_59 , 0 , V_43 , V_45 ) ;
if ( F_48 ( V_34 , V_60 ) ) {
F_20 ( V_17 , L_6 ) ;
V_56 = - V_53 ;
goto V_61;
}
V_20 -> V_44 [ V_39 ] = V_60 ;
}
F_17 ( V_11 -> V_46 ) ;
V_56 = F_49 ( V_11 -> V_47 , 0 , 1 , V_48 , V_48 ,
V_49 >> V_11 -> V_41 , & V_38 ) ;
F_21 ( V_11 -> V_46 ) ;
if ( V_56 ) {
F_20 ( V_17 , L_7 ) ;
goto V_61;
}
for ( V_39 = 0 ; V_39 < V_48 ; V_39 ++ ) {
T_3 V_6 = ( V_38 -> V_6 + V_39 ) << V_11 -> V_41 ;
V_56 = F_50 ( V_11 -> V_42 , V_6 , V_20 -> V_44 [ V_39 ] ,
V_43 , V_62 | V_63 ) ;
if ( V_56 < 0 ) {
F_20 ( V_17 , L_8 , V_56 ) ;
while ( V_39 -- > 0 ) {
V_6 -= V_43 ;
F_36 ( V_11 -> V_42 , V_6 , V_43 ) ;
}
goto V_64;
}
}
V_38 -> V_6 |= F_35 ( V_11 -> V_40 - V_11 -> V_41 ) ;
V_20 -> V_12 . V_5 . V_6 = ( ( T_1 ) V_38 -> V_6 ) << V_11 -> V_41 ;
V_20 -> V_12 . V_5 . V_5 = V_38 ;
return 0 ;
V_64:
F_17 ( V_11 -> V_46 ) ;
F_39 ( V_11 -> V_47 , & V_38 ) ;
F_21 ( V_11 -> V_46 ) ;
V_61:
for ( V_39 = 0 ; V_39 < V_48 && V_20 -> V_26 [ V_39 ] != NULL ; V_39 ++ ) {
T_4 V_65 = V_20 -> V_44 [ V_39 ] ;
if ( V_65 )
F_37 ( V_34 , V_65 , V_43 ,
V_45 ) ;
F_38 ( V_20 -> V_26 [ V_39 ] ) ;
}
return V_56 ;
}
static int
F_51 ( struct V_66 * V_12 , T_3 V_7 , T_3 V_49 , bool V_67 ,
struct V_2 * * V_68 )
{
struct V_10 * V_11 = V_10 ( V_12 ) ;
struct V_51 * V_17 = & V_11 -> V_12 . V_17 ;
struct F_3 * V_20 = NULL ;
int V_56 ;
F_10 ( V_17 , L_9 , V_69 ,
V_11 -> V_42 ? L_10 : L_11 , V_7 , V_49 ) ;
V_7 = F_52 ( F_53 ( V_7 , V_43 ) , V_43 ) ;
V_49 = F_52 ( F_53 ( V_49 , V_43 ) , V_43 ) ;
if ( V_11 -> V_42 )
V_56 = F_45 ( V_11 , V_7 >> V_27 ,
V_49 , & V_20 ) ;
else
V_56 = F_40 ( V_11 , V_7 >> V_27 ,
V_49 , & V_20 ) ;
* V_68 = V_20 ? & V_20 -> V_3 : NULL ;
if ( V_56 )
return V_56 ;
V_20 -> V_11 = V_11 ;
V_20 -> V_5 . V_7 = V_7 >> 12 ;
V_20 -> V_5 . V_70 = 0 ;
V_20 -> V_5 . V_71 = 12 ;
F_10 ( V_17 , L_12 ,
V_7 , V_49 , V_20 -> V_5 . V_6 ) ;
return 0 ;
}
static void *
F_54 ( struct V_66 * V_12 )
{
struct V_10 * V_11 = V_10 ( V_12 ) ;
if ( ! F_12 ( & V_11 -> V_19 ) )
F_44 ( & V_12 -> V_17 , L_13 ) ;
if ( V_11 -> V_16 != 0 )
F_44 ( & V_12 -> V_17 , L_14
L_15 , V_11 -> V_16 ) ;
return V_11 ;
}
int
F_55 ( struct V_72 * V_23 , int V_73 ,
struct V_66 * * V_74 )
{
struct V_75 * V_76 = V_23 -> V_77 -> V_78 ( V_23 ) ;
struct V_10 * V_11 ;
if ( ! ( V_11 = F_41 ( sizeof( * V_11 ) , V_52 ) ) )
return - V_53 ;
F_56 ( & V_10 , V_23 , V_73 , & V_11 -> V_12 ) ;
F_57 ( & V_11 -> V_24 ) ;
* V_74 = & V_11 -> V_12 ;
V_11 -> V_16 = 0 ;
V_11 -> V_18 = 0x100000 ;
F_58 ( & V_11 -> V_19 ) ;
if ( V_76 -> V_79 . V_42 ) {
V_11 -> V_46 = & V_76 -> V_79 . V_80 ;
V_11 -> V_47 = & V_76 -> V_79 . V_47 ;
V_11 -> V_42 = V_76 -> V_79 . V_42 ;
V_11 -> V_41 = V_76 -> V_79 . V_81 ;
V_11 -> V_40 = V_76 -> V_77 -> V_40 ;
F_59 ( & V_11 -> V_12 . V_17 , L_16 ) ;
} else {
V_11 -> V_36 = V_82 |
V_83 |
V_84 ;
F_59 ( & V_11 -> V_12 . V_17 , L_17 ) ;
}
return 0 ;
}
