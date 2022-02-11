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
F_23 () ;
F_24 ( V_22 ) ;
}
static void
F_25 ( struct V_2 * V_3 )
{
struct V_8 * V_20 = V_8 ( V_3 ) ;
struct V_10 * V_11 = V_20 -> V_12 . V_11 ;
struct V_21 * V_22 = V_11 -> V_12 . V_17 . V_23 -> V_22 ;
unsigned long V_24 ;
F_17 ( & V_11 -> V_25 , V_24 ) ;
if ( F_6 ( V_20 -> V_13 == 0 ) )
goto V_26;
if ( -- V_20 -> V_13 == 0 )
F_26 ( & V_20 -> V_14 , & V_11 -> V_19 ) ;
V_26:
F_21 ( & V_11 -> V_25 , V_24 ) ;
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
V_20 -> V_36 , V_11 -> V_37 ) ;
V_26:
return V_20 ;
}
static void *
F_34 ( struct V_2 * V_3 )
{
struct V_8 * V_20 = V_8 ( V_3 ) ;
struct V_10 * V_11 = V_20 -> V_12 . V_11 ;
struct V_23 * V_35 = V_11 -> V_12 . V_17 . V_23 -> V_35 ;
struct V_38 * V_39 = V_20 -> V_12 . V_5 . V_5 ;
unsigned long V_24 ;
int V_40 ;
if ( F_32 ( ! V_39 ) )
goto V_26;
F_17 ( & V_11 -> V_25 , V_24 ) ;
if ( V_20 -> V_12 . V_15 )
F_5 ( V_20 ) ;
F_21 ( & V_11 -> V_25 , V_24 ) ;
V_39 -> V_6 &= ~ F_35 ( V_11 -> V_41 - V_11 -> V_42 ) ;
for ( V_40 = 0 ; V_40 < V_20 -> V_12 . V_5 . V_7 ; V_40 ++ ) {
F_36 ( V_11 -> V_43 ,
( V_39 -> V_6 + V_40 ) << V_11 -> V_42 , V_44 ) ;
F_37 ( V_35 , V_20 -> V_45 [ V_40 ] , V_44 ,
V_46 ) ;
F_38 ( V_20 -> V_27 [ V_40 ] ) ;
}
F_39 ( V_11 -> V_47 ) ;
F_40 ( V_11 -> V_48 , & V_39 ) ;
F_41 ( V_11 -> V_47 ) ;
V_26:
return V_20 ;
}
static int
F_42 ( struct V_10 * V_11 , T_3 V_49 , T_3 V_50 ,
struct F_3 * * V_51 )
{
struct V_34 * V_20 ;
struct V_52 * V_17 = & V_11 -> V_12 . V_17 ;
struct V_23 * V_35 = V_17 -> V_23 -> V_35 ;
if ( ! ( V_20 = F_43 ( sizeof( * V_20 ) , V_53 ) ) )
return - V_54 ;
* V_51 = & V_20 -> V_12 ;
F_44 ( & V_55 , & V_20 -> V_12 . V_3 ) ;
V_20 -> V_12 . V_15 = F_45 ( V_35 , V_49 << V_28 ,
& V_20 -> V_36 , V_53 ,
V_11 -> V_37 ) ;
if ( ! V_20 -> V_12 . V_15 ) {
F_20 ( V_17 , L_4 ) ;
return - V_54 ;
}
if ( F_32 ( V_20 -> V_36 & ( V_50 - 1 ) ) )
F_46 ( V_17 ,
L_5 ,
& V_20 -> V_36 , V_50 ) ;
V_20 -> V_39 . type = 12 ;
V_20 -> V_39 . V_6 = V_20 -> V_36 >> 12 ;
V_20 -> V_39 . V_56 = ( V_49 << V_28 ) >> 12 ;
V_20 -> V_12 . V_5 . V_6 = V_20 -> V_36 ;
V_20 -> V_12 . V_5 . V_5 = & V_20 -> V_39 ;
return 0 ;
}
static int
F_47 ( struct V_10 * V_11 , T_3 V_49 , T_3 V_50 ,
struct F_3 * * V_51 )
{
struct V_8 * V_20 ;
struct V_52 * V_17 = & V_11 -> V_12 . V_17 ;
struct V_23 * V_35 = V_17 -> V_23 -> V_35 ;
struct V_38 * V_39 ;
int V_57 ;
int V_40 ;
if ( ! ( V_20 = F_43 ( sizeof( * V_20 ) + ( ( sizeof( V_20 -> V_27 [ 0 ] ) +
sizeof( * V_20 -> V_45 ) ) * V_49 ) , V_53 ) ) )
return - V_54 ;
* V_51 = & V_20 -> V_12 ;
V_20 -> V_45 = ( void * ) ( V_20 -> V_27 + V_49 ) ;
F_44 ( & V_58 , & V_20 -> V_12 . V_3 ) ;
for ( V_40 = 0 ; V_40 < V_49 ; V_40 ++ ) {
struct V_59 * V_60 = F_48 ( V_53 ) ;
T_4 V_61 ;
if ( V_60 == NULL ) {
V_57 = - V_54 ;
goto V_62;
}
V_20 -> V_27 [ V_40 ] = V_60 ;
V_61 = F_49 ( V_35 , V_60 , 0 , V_44 , V_46 ) ;
if ( F_50 ( V_35 , V_61 ) ) {
F_20 ( V_17 , L_6 ) ;
V_57 = - V_54 ;
goto V_62;
}
V_20 -> V_45 [ V_40 ] = V_61 ;
}
F_39 ( V_11 -> V_47 ) ;
V_57 = F_51 ( V_11 -> V_48 , 0 , 1 , V_49 , V_49 ,
V_50 >> V_11 -> V_42 , & V_39 ) ;
F_41 ( V_11 -> V_47 ) ;
if ( V_57 ) {
F_20 ( V_17 , L_7 ) ;
goto V_62;
}
for ( V_40 = 0 ; V_40 < V_49 ; V_40 ++ ) {
T_3 V_6 = ( V_39 -> V_6 + V_40 ) << V_11 -> V_42 ;
V_57 = F_52 ( V_11 -> V_43 , V_6 , V_20 -> V_45 [ V_40 ] ,
V_44 , V_63 | V_64 ) ;
if ( V_57 < 0 ) {
F_20 ( V_17 , L_8 , V_57 ) ;
while ( V_40 -- > 0 ) {
V_6 -= V_44 ;
F_36 ( V_11 -> V_43 , V_6 , V_44 ) ;
}
goto V_65;
}
}
V_39 -> V_6 |= F_35 ( V_11 -> V_41 - V_11 -> V_42 ) ;
V_20 -> V_12 . V_5 . V_6 = ( ( T_1 ) V_39 -> V_6 ) << V_11 -> V_42 ;
V_20 -> V_12 . V_5 . V_5 = V_39 ;
return 0 ;
V_65:
F_39 ( V_11 -> V_47 ) ;
F_40 ( V_11 -> V_48 , & V_39 ) ;
F_41 ( V_11 -> V_47 ) ;
V_62:
for ( V_40 = 0 ; V_40 < V_49 && V_20 -> V_27 [ V_40 ] != NULL ; V_40 ++ ) {
T_4 V_66 = V_20 -> V_45 [ V_40 ] ;
if ( V_66 )
F_37 ( V_35 , V_66 , V_44 ,
V_46 ) ;
F_38 ( V_20 -> V_27 [ V_40 ] ) ;
}
return V_57 ;
}
static int
F_53 ( struct V_67 * V_12 , T_3 V_7 , T_3 V_50 , bool V_68 ,
struct V_2 * * V_69 )
{
struct V_10 * V_11 = V_10 ( V_12 ) ;
struct V_52 * V_17 = & V_11 -> V_12 . V_17 ;
struct F_3 * V_20 = NULL ;
int V_57 ;
F_10 ( V_17 , L_9 , V_70 ,
V_11 -> V_43 ? L_10 : L_11 , V_7 , V_50 ) ;
V_7 = F_54 ( F_55 ( V_7 , V_44 ) , V_44 ) ;
V_50 = F_54 ( F_55 ( V_50 , V_44 ) , V_44 ) ;
if ( V_11 -> V_43 )
V_57 = F_47 ( V_11 , V_7 >> V_28 ,
V_50 , & V_20 ) ;
else
V_57 = F_42 ( V_11 , V_7 >> V_28 ,
V_50 , & V_20 ) ;
* V_69 = V_20 ? & V_20 -> V_3 : NULL ;
if ( V_57 )
return V_57 ;
V_20 -> V_11 = V_11 ;
V_20 -> V_5 . V_7 = V_7 >> 12 ;
V_20 -> V_5 . V_71 = 0 ;
V_20 -> V_5 . V_72 = 12 ;
F_10 ( V_17 , L_12 ,
V_7 , V_50 , V_20 -> V_5 . V_6 ) ;
return 0 ;
}
static void *
F_56 ( struct V_67 * V_12 )
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
F_57 ( struct V_73 * V_23 , int V_74 ,
struct V_67 * * V_75 )
{
struct V_76 * V_77 = V_23 -> V_78 -> V_79 ( V_23 ) ;
struct V_10 * V_11 ;
if ( ! ( V_11 = F_43 ( sizeof( * V_11 ) , V_53 ) ) )
return - V_54 ;
F_58 ( & V_10 , V_23 , V_74 , & V_11 -> V_12 ) ;
F_59 ( & V_11 -> V_25 ) ;
* V_75 = & V_11 -> V_12 ;
V_11 -> V_16 = 0 ;
V_11 -> V_18 = 0x100000 ;
F_60 ( & V_11 -> V_19 ) ;
if ( V_77 -> V_80 . V_43 ) {
V_11 -> V_47 = & V_77 -> V_80 . V_81 ;
V_11 -> V_48 = & V_77 -> V_80 . V_48 ;
V_11 -> V_43 = V_77 -> V_80 . V_43 ;
V_11 -> V_42 = V_77 -> V_80 . V_82 ;
V_11 -> V_41 = V_77 -> V_78 -> V_41 ;
F_61 ( & V_11 -> V_12 . V_17 , L_16 ) ;
} else {
V_11 -> V_37 = V_83 |
V_84 |
V_85 ;
F_61 ( & V_11 -> V_12 . V_17 , L_17 ) ;
}
return 0 ;
}
