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
unsigned long V_24 ;
F_15 ( V_22 ) ;
F_17 ( & V_11 -> V_25 , V_24 ) ;
if ( V_20 -> V_12 . V_15 ) {
if ( ! V_20 -> V_13 ) {
F_7 ( & V_20 -> V_14 ) ;
}
goto V_26;
}
F_11 ( V_11 , V_7 ) ;
V_20 -> V_12 . V_15 = F_18 ( V_20 -> V_27 , V_7 >> V_28 , V_29 ,
F_19 ( V_30 ) ) ;
if ( ! V_20 -> V_12 . V_15 ) {
F_20 ( & V_11 -> V_12 . V_17 , L_2
L_3 ) ;
goto V_26;
}
V_11 -> V_16 += V_7 ;
F_10 ( & V_11 -> V_12 . V_17 , L_1 ,
V_11 -> V_16 , V_11 -> V_18 ) ;
V_26:
V_20 -> V_13 ++ ;
F_21 ( & V_11 -> V_25 , V_24 ) ;
return V_20 -> V_12 . V_15 ;
}
static void
F_22 ( struct V_2 * V_3 )
{
struct F_3 * V_20 = F_3 ( V_3 ) ;
struct V_10 * V_11 = V_20 -> V_11 ;
struct V_21 * V_22 = V_11 -> V_12 . V_17 . V_23 -> V_22 ;
F_23 ( V_22 ) ;
}
static void
F_24 ( struct V_2 * V_3 )
{
struct V_8 * V_20 = V_8 ( V_3 ) ;
struct V_10 * V_11 = V_20 -> V_12 . V_11 ;
struct V_21 * V_22 = V_11 -> V_12 . V_17 . V_23 -> V_22 ;
unsigned long V_24 ;
F_17 ( & V_11 -> V_25 , V_24 ) ;
if ( F_6 ( V_20 -> V_13 == 0 ) )
goto V_26;
if ( -- V_20 -> V_13 == 0 )
F_25 ( & V_20 -> V_14 , & V_11 -> V_19 ) ;
V_26:
F_21 ( & V_11 -> V_25 , V_24 ) ;
F_26 () ;
F_23 ( V_22 ) ;
}
static T_3
F_27 ( struct V_2 * V_3 , T_1 V_6 )
{
struct F_3 * V_20 = F_3 ( V_3 ) ;
return V_20 -> V_15 [ V_6 / 4 ] ;
}
static void
F_28 ( struct V_2 * V_3 , T_1 V_6 , T_3 V_31 )
{
struct F_3 * V_20 = F_3 ( V_3 ) ;
V_20 -> V_15 [ V_6 / 4 ] = V_31 ;
}
static void
F_29 ( struct V_2 * V_3 , struct V_32 * V_33 , T_1 V_6 )
{
struct F_3 * V_20 = F_3 ( V_3 ) ;
F_30 ( V_33 , V_6 , & V_20 -> V_5 ) ;
}
static void *
F_31 ( struct V_2 * V_3 )
{
struct V_34 * V_20 = V_34 ( V_3 ) ;
struct V_10 * V_11 = V_20 -> V_12 . V_11 ;
struct V_23 * V_35 = V_11 -> V_12 . V_17 . V_23 -> V_35 ;
if ( F_32 ( ! V_20 -> V_12 . V_15 ) )
goto V_26;
F_33 ( V_35 , V_20 -> V_12 . V_5 . V_7 << V_28 , V_20 -> V_12 . V_15 ,
V_20 -> V_36 , & V_11 -> V_37 ) ;
V_26:
return V_20 ;
}
static void *
F_34 ( struct V_2 * V_3 )
{
struct V_8 * V_20 = V_8 ( V_3 ) ;
struct V_10 * V_11 = V_20 -> V_12 . V_11 ;
struct V_23 * V_35 = V_11 -> V_12 . V_17 . V_23 -> V_35 ;
struct V_38 * V_39 ;
unsigned long V_24 ;
int V_40 ;
if ( F_32 ( F_12 ( & V_20 -> V_12 . V_5 . V_41 ) ) )
goto V_26;
F_17 ( & V_11 -> V_25 , V_24 ) ;
if ( V_20 -> V_12 . V_15 )
F_5 ( V_20 ) ;
F_21 ( & V_11 -> V_25 , V_24 ) ;
V_39 = F_13 ( & V_20 -> V_12 . V_5 . V_41 , struct V_38 ,
V_42 ) ;
V_39 -> V_6 &= ~ F_35 ( V_11 -> V_43 - V_11 -> V_44 ) ;
for ( V_40 = 0 ; V_40 < V_20 -> V_12 . V_5 . V_7 ; V_40 ++ ) {
F_36 ( V_11 -> V_45 ,
( V_39 -> V_6 + V_40 ) << V_11 -> V_44 , V_46 ) ;
F_37 ( V_35 , V_20 -> V_47 [ V_40 ] , V_46 ,
V_48 ) ;
F_38 ( V_20 -> V_27 [ V_40 ] ) ;
}
F_39 ( V_11 -> V_49 ) ;
F_40 ( V_11 -> V_50 , & V_39 ) ;
F_41 ( V_11 -> V_49 ) ;
V_26:
return V_20 ;
}
static int
F_42 ( struct V_10 * V_11 , T_3 V_51 , T_3 V_52 ,
struct F_3 * * V_53 )
{
struct V_34 * V_20 ;
struct V_54 * V_17 = & V_11 -> V_12 . V_17 ;
struct V_23 * V_35 = V_17 -> V_23 -> V_35 ;
if ( ! ( V_20 = F_43 ( sizeof( * V_20 ) , V_55 ) ) )
return - V_56 ;
* V_53 = & V_20 -> V_12 ;
F_44 ( & V_57 , & V_20 -> V_12 . V_3 ) ;
V_20 -> V_12 . V_15 = F_45 ( V_35 , V_51 << V_28 ,
& V_20 -> V_36 , V_55 ,
& V_11 -> V_37 ) ;
if ( ! V_20 -> V_12 . V_15 ) {
F_20 ( V_17 , L_4 ) ;
return - V_56 ;
}
if ( F_32 ( V_20 -> V_36 & ( V_52 - 1 ) ) )
F_46 ( V_17 ,
L_5 ,
& V_20 -> V_36 , V_52 ) ;
V_20 -> V_39 . type = 12 ;
V_20 -> V_39 . V_6 = V_20 -> V_36 >> 12 ;
V_20 -> V_39 . V_58 = ( V_51 << V_28 ) >> 12 ;
V_20 -> V_12 . V_5 . V_6 = V_20 -> V_36 ;
F_47 ( & V_20 -> V_12 . V_5 . V_41 ) ;
F_25 ( & V_20 -> V_39 . V_42 , & V_20 -> V_12 . V_5 . V_41 ) ;
return 0 ;
}
static int
F_48 ( struct V_10 * V_11 , T_3 V_51 , T_3 V_52 ,
struct F_3 * * V_53 )
{
struct V_8 * V_20 ;
struct V_54 * V_17 = & V_11 -> V_12 . V_17 ;
struct V_23 * V_35 = V_17 -> V_23 -> V_35 ;
struct V_38 * V_39 ;
int V_59 ;
int V_40 ;
if ( ! ( V_20 = F_43 ( sizeof( * V_20 ) + ( ( sizeof( V_20 -> V_27 [ 0 ] ) +
sizeof( * V_20 -> V_47 ) ) * V_51 ) , V_55 ) ) )
return - V_56 ;
* V_53 = & V_20 -> V_12 ;
V_20 -> V_47 = ( void * ) ( V_20 -> V_27 + V_51 ) ;
F_44 ( & V_60 , & V_20 -> V_12 . V_3 ) ;
for ( V_40 = 0 ; V_40 < V_51 ; V_40 ++ ) {
struct V_61 * V_62 = F_49 ( V_55 ) ;
T_4 V_63 ;
if ( V_62 == NULL ) {
V_59 = - V_56 ;
goto V_64;
}
V_20 -> V_27 [ V_40 ] = V_62 ;
V_63 = F_50 ( V_35 , V_62 , 0 , V_46 , V_48 ) ;
if ( F_51 ( V_35 , V_63 ) ) {
F_20 ( V_17 , L_6 ) ;
V_59 = - V_56 ;
goto V_64;
}
V_20 -> V_47 [ V_40 ] = V_63 ;
}
F_39 ( V_11 -> V_49 ) ;
V_59 = F_52 ( V_11 -> V_50 , 0 , 1 , V_51 , V_51 ,
V_52 >> V_11 -> V_44 , & V_39 ) ;
F_41 ( V_11 -> V_49 ) ;
if ( V_59 ) {
F_20 ( V_17 , L_7 ) ;
goto V_64;
}
for ( V_40 = 0 ; V_40 < V_51 ; V_40 ++ ) {
T_3 V_6 = ( V_39 -> V_6 + V_40 ) << V_11 -> V_44 ;
V_59 = F_53 ( V_11 -> V_45 , V_6 , V_20 -> V_47 [ V_40 ] ,
V_46 , V_65 | V_66 ) ;
if ( V_59 < 0 ) {
F_20 ( V_17 , L_8 , V_59 ) ;
while ( V_40 -- > 0 ) {
V_6 -= V_46 ;
F_36 ( V_11 -> V_45 , V_6 , V_46 ) ;
}
goto V_67;
}
}
V_39 -> V_6 |= F_35 ( V_11 -> V_43 - V_11 -> V_44 ) ;
V_20 -> V_12 . V_5 . V_6 = ( ( T_1 ) V_39 -> V_6 ) << V_11 -> V_44 ;
F_47 ( & V_20 -> V_12 . V_5 . V_41 ) ;
F_25 ( & V_39 -> V_42 , & V_20 -> V_12 . V_5 . V_41 ) ;
return 0 ;
V_67:
F_39 ( V_11 -> V_49 ) ;
F_40 ( V_11 -> V_50 , & V_39 ) ;
F_41 ( V_11 -> V_49 ) ;
V_64:
for ( V_40 = 0 ; V_40 < V_51 && V_20 -> V_27 [ V_40 ] != NULL ; V_40 ++ ) {
T_4 V_68 = V_20 -> V_47 [ V_40 ] ;
if ( V_68 )
F_37 ( V_35 , V_68 , V_46 ,
V_48 ) ;
F_38 ( V_20 -> V_27 [ V_40 ] ) ;
}
return V_59 ;
}
static int
F_54 ( struct V_69 * V_12 , T_3 V_7 , T_3 V_52 , bool V_70 ,
struct V_2 * * V_71 )
{
struct V_10 * V_11 = V_10 ( V_12 ) ;
struct V_54 * V_17 = & V_11 -> V_12 . V_17 ;
struct F_3 * V_20 = NULL ;
int V_59 ;
F_10 ( V_17 , L_9 , V_72 ,
V_11 -> V_45 ? L_10 : L_11 , V_7 , V_52 ) ;
V_7 = F_55 ( F_56 ( V_7 , V_46 ) , V_46 ) ;
V_52 = F_55 ( F_56 ( V_52 , V_46 ) , V_46 ) ;
if ( V_11 -> V_45 )
V_59 = F_48 ( V_11 , V_7 >> V_28 ,
V_52 , & V_20 ) ;
else
V_59 = F_42 ( V_11 , V_7 >> V_28 ,
V_52 , & V_20 ) ;
* V_71 = V_20 ? & V_20 -> V_3 : NULL ;
if ( V_59 )
return V_59 ;
V_20 -> V_11 = V_11 ;
V_20 -> V_5 . V_7 = V_7 >> 12 ;
V_20 -> V_5 . V_73 = 0 ;
V_20 -> V_5 . V_74 = 12 ;
F_10 ( V_17 , L_12 ,
V_7 , V_52 , V_20 -> V_5 . V_6 ) ;
return 0 ;
}
static void *
F_57 ( struct V_69 * V_12 )
{
struct V_10 * V_11 = V_10 ( V_12 ) ;
if ( ! F_12 ( & V_11 -> V_19 ) )
F_46 ( & V_12 -> V_17 , L_13 ) ;
if ( V_11 -> V_16 != 0 )
F_46 ( & V_12 -> V_17 , L_14
L_15 , V_11 -> V_16 ) ;
return V_11 ;
}
int
F_58 ( struct V_75 * V_23 , int V_76 ,
struct V_69 * * V_77 )
{
struct V_78 * V_79 = V_23 -> V_80 -> V_81 ( V_23 ) ;
struct V_10 * V_11 ;
if ( ! ( V_11 = F_43 ( sizeof( * V_11 ) , V_55 ) ) )
return - V_56 ;
F_59 ( & V_10 , V_23 , V_76 , & V_11 -> V_12 ) ;
F_60 ( & V_11 -> V_25 ) ;
* V_77 = & V_11 -> V_12 ;
V_11 -> V_16 = 0 ;
V_11 -> V_18 = 0x100000 ;
F_47 ( & V_11 -> V_19 ) ;
if ( V_79 -> V_82 . V_45 ) {
V_11 -> V_49 = & V_79 -> V_82 . V_83 ;
V_11 -> V_50 = & V_79 -> V_82 . V_50 ;
V_11 -> V_45 = V_79 -> V_82 . V_45 ;
V_11 -> V_44 = V_79 -> V_82 . V_84 ;
V_11 -> V_43 = V_79 -> V_80 -> V_43 ;
F_61 ( & V_11 -> V_12 . V_17 , L_16 ) ;
} else {
F_62 ( & V_11 -> V_37 ) ;
F_63 ( V_85 , & V_11 -> V_37 ) ;
F_63 ( V_86 , & V_11 -> V_37 ) ;
F_63 ( V_87 , & V_11 -> V_37 ) ;
F_61 ( & V_11 -> V_12 . V_17 , L_17 ) ;
}
return 0 ;
}
