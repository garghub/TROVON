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
static void T_2 *
F_5 ( struct V_2 * V_3 )
{
#if F_6 ( V_8 ) || F_6 ( V_9 )
struct V_10 * V_11 = V_10 ( V_3 ) ;
struct V_12 * V_13 = V_11 -> V_14 . V_15 -> V_14 . V_16 . V_12 -> V_13 ;
int V_17 = F_7 ( V_3 ) >> 12 ;
struct V_18 * V_19 [ V_17 ] ;
int V_20 ;
V_19 [ 0 ] = F_8 ( F_9 ( V_13 , V_11 -> V_21 ) >> V_22 ) ;
for ( V_20 = 1 ; V_20 < V_17 ; V_20 ++ )
V_19 [ V_20 ] = V_19 [ 0 ] + V_20 ;
return F_10 ( V_19 , V_17 , V_23 , F_11 ( V_24 ) ) ;
#else
F_12 () ;
return NULL ;
#endif
}
static void T_2 *
F_13 ( struct V_2 * V_3 )
{
struct V_25 * V_11 = V_25 ( V_3 ) ;
int V_17 = F_7 ( V_3 ) >> 12 ;
return F_10 ( V_11 -> V_19 , V_17 , V_23 ,
F_11 ( V_24 ) ) ;
}
static void
F_14 ( struct V_26 * V_15 , const T_1 V_7 )
{
while ( V_15 -> V_27 + V_7 > V_15 -> V_28 ) {
struct F_3 * V_29 ;
if ( F_15 ( & V_15 -> V_30 ) )
break;
V_29 = F_16 ( & V_15 -> V_30 , struct F_3 ,
V_31 ) ;
F_17 ( & V_29 -> V_31 ) ;
F_18 ( V_29 -> V_32 ) ;
V_29 -> V_32 = NULL ;
V_15 -> V_27 -= F_7 ( & V_29 -> V_3 ) ;
F_19 ( & V_15 -> V_14 . V_16 , L_1 ,
V_15 -> V_27 , V_15 -> V_28 ) ;
}
}
static void T_2 *
F_20 ( struct V_2 * V_3 )
{
struct F_3 * V_11 = F_3 ( V_3 ) ;
struct V_26 * V_15 = V_11 -> V_15 ;
struct V_33 * V_34 = V_15 -> V_14 . V_16 . V_12 -> V_34 ;
const T_1 V_7 = F_7 ( V_3 ) ;
unsigned long V_35 ;
F_21 ( V_34 ) ;
F_22 ( & V_15 -> V_36 , V_35 ) ;
if ( V_11 -> V_32 ) {
F_17 ( & V_11 -> V_31 ) ;
goto V_37;
}
F_14 ( V_15 , V_7 ) ;
V_11 -> V_32 = V_15 -> V_38 ( V_3 ) ;
if ( ! V_11 -> V_32 ) {
F_23 ( & V_15 -> V_14 . V_16 , L_2
L_3 ) ;
goto V_37;
}
V_15 -> V_27 += V_7 ;
F_19 ( & V_15 -> V_14 . V_16 , L_4 ,
V_15 -> V_27 , V_15 -> V_28 ) ;
V_37:
F_24 ( & V_15 -> V_36 , V_35 ) ;
return V_11 -> V_32 ;
}
static void
F_25 ( struct V_2 * V_3 )
{
struct F_3 * V_11 = F_3 ( V_3 ) ;
struct V_26 * V_15 = V_11 -> V_15 ;
struct V_33 * V_34 = V_15 -> V_14 . V_16 . V_12 -> V_34 ;
unsigned long V_35 ;
F_22 ( & V_15 -> V_36 , V_35 ) ;
F_26 ( & V_11 -> V_31 , & V_15 -> V_30 ) ;
F_24 ( & V_15 -> V_36 , V_35 ) ;
F_27 () ;
F_28 ( V_34 ) ;
}
static T_3
F_29 ( struct V_2 * V_3 , T_1 V_6 )
{
struct F_3 * V_11 = F_3 ( V_3 ) ;
return V_11 -> V_32 [ V_6 / 4 ] ;
}
static void
F_30 ( struct V_2 * V_3 , T_1 V_6 , T_3 V_39 )
{
struct F_3 * V_11 = F_3 ( V_3 ) ;
V_11 -> V_32 [ V_6 / 4 ] = V_39 ;
}
static void
F_31 ( struct V_2 * V_3 , struct V_40 * V_41 , T_1 V_6 )
{
struct F_3 * V_11 = F_3 ( V_3 ) ;
F_32 ( V_41 , V_6 , & V_11 -> V_5 ) ;
}
static void
F_33 ( struct F_3 * V_11 )
{
struct V_26 * V_15 = V_11 -> V_15 ;
struct F_3 * V_29 ;
unsigned long V_35 ;
F_22 ( & V_15 -> V_36 , V_35 ) ;
if ( ! V_11 -> V_32 )
goto V_37;
F_34 (obj, &imem->vaddr_lru, vaddr_node) {
if ( V_29 == V_11 ) {
F_17 ( & V_29 -> V_31 ) ;
break;
}
}
F_18 ( V_11 -> V_32 ) ;
V_11 -> V_32 = NULL ;
V_15 -> V_27 -= F_7 ( & V_11 -> V_3 ) ;
F_19 ( & V_15 -> V_14 . V_16 , L_4 ,
V_15 -> V_27 , V_15 -> V_28 ) ;
V_37:
F_24 ( & V_15 -> V_36 , V_35 ) ;
}
static void *
F_35 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = V_10 ( V_3 ) ;
struct V_26 * V_15 = V_11 -> V_14 . V_15 ;
struct V_12 * V_13 = V_15 -> V_14 . V_16 . V_12 -> V_13 ;
F_33 ( & V_11 -> V_14 ) ;
if ( F_36 ( ! V_11 -> V_42 ) )
goto V_37;
F_37 ( V_13 , V_11 -> V_14 . V_5 . V_7 << V_22 , V_11 -> V_42 ,
V_11 -> V_21 , & V_15 -> V_43 ) ;
V_37:
return V_11 ;
}
static void *
F_38 ( struct V_2 * V_3 )
{
struct V_25 * V_11 = V_25 ( V_3 ) ;
struct V_26 * V_15 = V_11 -> V_14 . V_15 ;
struct V_12 * V_13 = V_15 -> V_14 . V_16 . V_12 -> V_13 ;
struct V_44 * V_45 ;
int V_20 ;
F_33 ( & V_11 -> V_14 ) ;
if ( F_36 ( F_15 ( & V_11 -> V_14 . V_5 . V_46 ) ) )
goto V_37;
V_45 = F_16 ( & V_11 -> V_14 . V_5 . V_46 , struct V_44 ,
V_47 ) ;
V_45 -> V_6 &= ~ F_39 ( V_15 -> V_48 - V_15 -> V_49 ) ;
for ( V_20 = 0 ; V_20 < V_11 -> V_14 . V_5 . V_7 ; V_20 ++ ) {
F_40 ( V_15 -> V_50 ,
( V_45 -> V_6 + V_20 ) << V_15 -> V_49 , V_51 ) ;
F_41 ( V_13 , V_11 -> V_52 [ V_20 ] , V_51 ,
V_53 ) ;
F_42 ( V_11 -> V_19 [ V_20 ] ) ;
}
F_43 ( V_15 -> V_54 ) ;
F_44 ( V_15 -> V_55 , & V_45 ) ;
F_45 ( V_15 -> V_54 ) ;
V_37:
return V_11 ;
}
static int
F_46 ( struct V_26 * V_15 , T_3 V_17 , T_3 V_56 ,
struct F_3 * * V_57 )
{
struct V_10 * V_11 ;
struct V_58 * V_16 = & V_15 -> V_14 . V_16 ;
struct V_12 * V_13 = V_16 -> V_12 -> V_13 ;
if ( ! ( V_11 = F_47 ( sizeof( * V_11 ) , V_59 ) ) )
return - V_60 ;
* V_57 = & V_11 -> V_14 ;
F_48 ( & V_61 , & V_11 -> V_14 . V_3 ) ;
V_11 -> V_42 = F_49 ( V_13 , V_17 << V_22 ,
& V_11 -> V_21 , V_59 ,
& V_15 -> V_43 ) ;
if ( ! V_11 -> V_42 ) {
F_23 ( V_16 , L_5 ) ;
return - V_60 ;
}
if ( F_36 ( V_11 -> V_21 & ( V_56 - 1 ) ) )
F_50 ( V_16 ,
L_6 ,
& V_11 -> V_21 , V_56 ) ;
V_11 -> V_45 . type = 12 ;
V_11 -> V_45 . V_6 = V_11 -> V_21 >> 12 ;
V_11 -> V_45 . V_62 = ( V_17 << V_22 ) >> 12 ;
V_11 -> V_14 . V_5 . V_6 = V_11 -> V_21 ;
F_51 ( & V_11 -> V_14 . V_5 . V_46 ) ;
F_26 ( & V_11 -> V_45 . V_47 , & V_11 -> V_14 . V_5 . V_46 ) ;
return 0 ;
}
static int
F_52 ( struct V_26 * V_15 , T_3 V_17 , T_3 V_56 ,
struct F_3 * * V_57 )
{
struct V_25 * V_11 ;
struct V_58 * V_16 = & V_15 -> V_14 . V_16 ;
struct V_12 * V_13 = V_16 -> V_12 -> V_13 ;
struct V_44 * V_45 ;
int V_63 ;
int V_20 ;
if ( ! ( V_11 = F_47 ( sizeof( * V_11 ) + ( ( sizeof( V_11 -> V_19 [ 0 ] ) +
sizeof( * V_11 -> V_52 ) ) * V_17 ) , V_59 ) ) )
return - V_60 ;
* V_57 = & V_11 -> V_14 ;
V_11 -> V_52 = ( void * ) ( V_11 -> V_19 + V_17 ) ;
F_48 ( & V_64 , & V_11 -> V_14 . V_3 ) ;
for ( V_20 = 0 ; V_20 < V_17 ; V_20 ++ ) {
struct V_18 * V_65 = F_53 ( V_59 ) ;
T_4 V_66 ;
if ( V_65 == NULL ) {
V_63 = - V_60 ;
goto V_67;
}
V_11 -> V_19 [ V_20 ] = V_65 ;
V_66 = F_54 ( V_13 , V_65 , 0 , V_51 , V_53 ) ;
if ( F_55 ( V_13 , V_66 ) ) {
F_23 ( V_16 , L_7 ) ;
V_63 = - V_60 ;
goto V_67;
}
V_11 -> V_52 [ V_20 ] = V_66 ;
}
F_43 ( V_15 -> V_54 ) ;
V_63 = F_56 ( V_15 -> V_55 , 0 , 1 , V_17 , V_17 ,
V_56 >> V_15 -> V_49 , & V_45 ) ;
F_45 ( V_15 -> V_54 ) ;
if ( V_63 ) {
F_23 ( V_16 , L_8 ) ;
goto V_67;
}
for ( V_20 = 0 ; V_20 < V_17 ; V_20 ++ ) {
T_3 V_6 = ( V_45 -> V_6 + V_20 ) << V_15 -> V_49 ;
V_63 = F_57 ( V_15 -> V_50 , V_6 , V_11 -> V_52 [ V_20 ] ,
V_51 , V_68 | V_69 ) ;
if ( V_63 < 0 ) {
F_23 ( V_16 , L_9 , V_63 ) ;
while ( V_20 -- > 0 ) {
V_6 -= V_51 ;
F_40 ( V_15 -> V_50 , V_6 , V_51 ) ;
}
goto V_70;
}
}
V_45 -> V_6 |= F_39 ( V_15 -> V_48 - V_15 -> V_49 ) ;
V_11 -> V_14 . V_5 . V_6 = ( ( T_1 ) V_45 -> V_6 ) << V_15 -> V_49 ;
F_51 ( & V_11 -> V_14 . V_5 . V_46 ) ;
F_26 ( & V_45 -> V_47 , & V_11 -> V_14 . V_5 . V_46 ) ;
return 0 ;
V_70:
F_43 ( V_15 -> V_54 ) ;
F_44 ( V_15 -> V_55 , & V_45 ) ;
F_45 ( V_15 -> V_54 ) ;
V_67:
for ( V_20 = 0 ; V_20 < V_17 && V_11 -> V_19 [ V_20 ] != NULL ; V_20 ++ ) {
T_4 V_71 = V_11 -> V_52 [ V_20 ] ;
if ( V_71 )
F_41 ( V_13 , V_71 , V_51 ,
V_53 ) ;
F_42 ( V_11 -> V_19 [ V_20 ] ) ;
}
return V_63 ;
}
static int
F_58 ( struct V_72 * V_14 , T_3 V_7 , T_3 V_56 , bool V_73 ,
struct V_2 * * V_74 )
{
struct V_26 * V_15 = V_26 ( V_14 ) ;
struct V_58 * V_16 = & V_15 -> V_14 . V_16 ;
struct F_3 * V_11 = NULL ;
int V_63 ;
F_19 ( V_16 , L_10 , V_75 ,
V_15 -> V_50 ? L_11 : L_12 , V_7 , V_56 ) ;
V_7 = F_59 ( F_60 ( V_7 , V_51 ) , V_51 ) ;
V_56 = F_59 ( F_60 ( V_56 , V_51 ) , V_51 ) ;
if ( V_15 -> V_50 )
V_63 = F_52 ( V_15 , V_7 >> V_22 ,
V_56 , & V_11 ) ;
else
V_63 = F_46 ( V_15 , V_7 >> V_22 ,
V_56 , & V_11 ) ;
* V_74 = V_11 ? & V_11 -> V_3 : NULL ;
if ( V_63 )
return V_63 ;
V_11 -> V_15 = V_15 ;
V_11 -> V_5 . V_7 = V_7 >> 12 ;
V_11 -> V_5 . V_76 = 0 ;
V_11 -> V_5 . V_77 = 12 ;
F_19 ( V_16 , L_13 ,
V_7 , V_56 , V_11 -> V_5 . V_6 ) ;
return 0 ;
}
static void *
F_61 ( struct V_72 * V_14 )
{
struct V_26 * V_15 = V_26 ( V_14 ) ;
if ( ! F_15 ( & V_15 -> V_30 ) )
F_50 ( & V_14 -> V_16 , L_14 ) ;
if ( V_15 -> V_27 != 0 )
F_50 ( & V_14 -> V_16 , L_15
L_16 , V_15 -> V_27 ) ;
return V_15 ;
}
int
F_62 ( struct V_78 * V_12 , int V_79 ,
struct V_72 * * V_80 )
{
struct V_81 * V_82 = V_12 -> V_83 -> V_84 ( V_12 ) ;
struct V_26 * V_15 ;
if ( ! ( V_15 = F_47 ( sizeof( * V_15 ) , V_59 ) ) )
return - V_60 ;
F_63 ( & V_26 , V_12 , V_79 , & V_15 -> V_14 ) ;
F_64 ( & V_15 -> V_36 ) ;
* V_80 = & V_15 -> V_14 ;
V_15 -> V_27 = 0 ;
V_15 -> V_28 = 0x100000 ;
F_51 ( & V_15 -> V_30 ) ;
if ( V_82 -> V_85 . V_50 ) {
V_15 -> V_54 = & V_82 -> V_85 . V_86 ;
V_15 -> V_55 = & V_82 -> V_85 . V_55 ;
V_15 -> V_50 = V_82 -> V_85 . V_50 ;
V_15 -> V_49 = V_82 -> V_85 . V_87 ;
V_15 -> V_38 = F_13 ;
V_15 -> V_48 = V_82 -> V_83 -> V_48 ;
F_65 ( & V_15 -> V_14 . V_16 , L_17 ) ;
} else {
F_66 ( & V_15 -> V_43 ) ;
F_67 ( V_88 , & V_15 -> V_43 ) ;
F_67 ( V_89 , & V_15 -> V_43 ) ;
F_67 ( V_90 , & V_15 -> V_43 ) ;
F_67 ( V_91 , & V_15 -> V_43 ) ;
V_15 -> V_38 = F_5 ;
F_65 ( & V_15 -> V_14 . V_16 , L_18 ) ;
}
return 0 ;
}
