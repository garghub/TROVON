static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 , struct V_6 * V_7 ,
int V_8 )
{
int V_9 , V_10 = 0 ;
int V_11 = 0 ;
V_9 = ( V_8 + V_12 - 1 ) / V_12 ;
for (; V_10 < V_9 ; V_10 ++ ) {
V_5 -> V_13 [ V_10 ] = F_4 ( sizeof * V_5 -> V_13 [ 0 ] , V_14 ) ;
if ( ! V_5 -> V_13 [ V_10 ] )
goto V_15;
}
V_5 -> V_16 = V_9 ;
F_5 ( & V_5 -> V_17 ) ;
F_6 ( & V_5 -> V_18 , 1 ) ;
V_5 -> V_7 = V_7 ;
V_5 -> V_19 = V_8 ;
V_20:
return V_11 ;
V_15:
while ( V_10 )
F_7 ( V_5 -> V_13 [ -- V_10 ] ) ;
V_11 = - V_21 ;
goto V_20;
}
static void F_8 ( struct V_4 * V_5 )
{
int V_10 = V_5 -> V_16 ;
V_5 -> V_16 = 0 ;
while ( V_10 )
F_7 ( V_5 -> V_13 [ -- V_10 ] ) ;
}
struct V_22 * F_9 ( struct V_6 * V_7 , int V_23 )
{
struct V_24 * V_5 = NULL ;
struct V_22 * V_25 ;
int V_11 ;
if ( F_10 ( V_7 ) -> V_26 ) {
V_25 = F_11 ( - V_27 ) ;
goto V_15;
}
V_5 = F_4 ( sizeof *V_5 , V_14 ) ;
if ( ! V_5 ) {
V_25 = F_11 ( - V_21 ) ;
goto V_15;
}
V_11 = F_3 ( & V_5 -> V_5 , V_7 , 0 ) ;
if ( V_11 ) {
V_25 = F_11 ( V_11 ) ;
goto V_15;
}
V_11 = F_12 ( & V_5 -> V_5 , 1 ) ;
if ( V_11 ) {
V_25 = F_11 ( V_11 ) ;
goto V_28;
}
V_5 -> V_5 . V_29 = V_23 ;
V_25 = & V_5 -> V_30 ;
V_31:
return V_25 ;
V_28:
F_8 ( & V_5 -> V_5 ) ;
V_15:
F_7 ( V_5 ) ;
goto V_31;
}
static struct V_24 * F_13 ( int V_8 , struct V_6 * V_7 )
{
struct V_24 * V_5 ;
int V_11 = - V_21 ;
int V_9 ;
V_9 = ( V_8 + V_12 - 1 ) / V_12 ;
V_5 = F_4 ( sizeof *V_5 + V_9 * sizeof V_5 -> V_5 . V_13 [ 0 ] , V_14 ) ;
if ( ! V_5 )
goto V_15;
V_11 = F_3 ( & V_5 -> V_5 , V_7 , V_8 ) ;
if ( V_11 )
goto V_15;
V_11 = F_12 ( & V_5 -> V_5 , 0 ) ;
if ( V_11 )
goto V_28;
V_5 -> V_30 . V_32 = V_5 -> V_5 . V_32 ;
V_5 -> V_30 . V_33 = V_5 -> V_5 . V_32 ;
V_31:
return V_5 ;
V_28:
F_8 ( & V_5 -> V_5 ) ;
V_15:
F_7 ( V_5 ) ;
V_5 = F_11 ( V_11 ) ;
goto V_31;
}
struct V_22 * F_14 ( struct V_6 * V_7 ,
struct V_34 * V_35 ,
int V_36 , int V_23 , T_1 * V_37 )
{
struct V_24 * V_5 ;
int V_38 , V_9 , V_10 ;
struct V_22 * V_25 ;
V_5 = F_13 ( V_36 , V_7 ) ;
if ( F_15 ( V_5 ) ) {
V_25 = (struct V_22 * ) V_5 ;
goto V_15;
}
V_5 -> V_5 . V_39 = * V_37 ;
V_5 -> V_5 . V_40 = * V_37 ;
V_5 -> V_5 . V_29 = V_23 ;
V_9 = 0 ;
V_38 = 0 ;
for ( V_10 = 0 ; V_10 < V_36 ; V_10 ++ ) {
V_5 -> V_5 . V_13 [ V_9 ] -> V_41 [ V_38 ] . V_42 = ( void * ) V_35 [ V_10 ] . V_43 ;
V_5 -> V_5 . V_13 [ V_9 ] -> V_41 [ V_38 ] . V_44 = V_35 [ V_10 ] . V_45 ;
V_5 -> V_5 . V_44 += V_35 [ V_10 ] . V_45 ;
V_38 ++ ;
if ( V_38 == V_12 ) {
V_9 ++ ;
V_38 = 0 ;
}
}
V_25 = & V_5 -> V_30 ;
V_15:
return V_25 ;
}
struct V_22 * F_16 ( struct V_6 * V_7 , T_1 V_46 , T_1 V_44 ,
T_1 V_47 , int V_48 ,
struct V_49 * V_50 )
{
struct V_24 * V_5 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
int V_38 , V_9 , V_10 ;
struct V_22 * V_25 ;
if ( V_44 == 0 ) {
V_25 = F_11 ( - V_55 ) ;
goto V_15;
}
V_52 = F_17 ( V_7 -> V_56 -> V_57 , V_46 , V_44 ,
V_48 , 0 ) ;
if ( F_15 ( V_52 ) )
return ( void * ) V_52 ;
V_38 = 0 ;
F_18 (chunk, &umem->chunk_list, list)
V_38 += V_54 -> V_58 ;
V_5 = F_13 ( V_38 , V_7 ) ;
if ( F_15 ( V_5 ) ) {
V_25 = (struct V_22 * ) V_5 ;
F_19 ( V_52 ) ;
goto V_15;
}
V_5 -> V_5 . V_39 = V_46 ;
V_5 -> V_5 . V_40 = V_47 ;
V_5 -> V_5 . V_44 = V_44 ;
V_5 -> V_5 . V_59 = V_52 -> V_59 ;
V_5 -> V_5 . V_29 = V_48 ;
V_5 -> V_52 = V_52 ;
if ( F_20 ( V_52 -> V_60 ) )
V_5 -> V_5 . V_61 = F_21 ( V_52 -> V_60 ) ;
V_9 = 0 ;
V_38 = 0 ;
F_18 (chunk, &umem->chunk_list, list) {
for ( V_10 = 0 ; V_10 < V_54 -> V_58 ; V_10 ++ ) {
void * V_42 ;
V_42 = F_22 ( F_23 ( & V_54 -> V_62 [ V_10 ] ) ) ;
if ( ! V_42 ) {
V_25 = F_11 ( - V_55 ) ;
goto V_15;
}
V_5 -> V_5 . V_13 [ V_9 ] -> V_41 [ V_38 ] . V_42 = V_42 ;
V_5 -> V_5 . V_13 [ V_9 ] -> V_41 [ V_38 ] . V_44 = V_52 -> V_60 ;
V_38 ++ ;
if ( V_38 == V_12 ) {
V_9 ++ ;
V_38 = 0 ;
}
}
}
V_25 = & V_5 -> V_30 ;
V_15:
return V_25 ;
}
int F_24 ( struct V_22 * V_30 )
{
struct V_24 * V_5 = F_25 ( V_30 ) ;
int V_25 = 0 ;
unsigned long V_63 ;
F_26 ( & V_5 -> V_5 ) ;
F_27 ( & V_5 -> V_5 ) ;
V_63 = F_28 ( & V_5 -> V_5 . V_17 ,
5 * V_64 ) ;
if ( ! V_63 ) {
F_29 ( & V_5 -> V_5 ) ;
V_25 = - V_65 ;
goto V_20;
}
F_8 ( & V_5 -> V_5 ) ;
if ( V_5 -> V_52 )
F_19 ( V_5 -> V_52 ) ;
F_7 ( V_5 ) ;
V_20:
return V_25 ;
}
struct V_22 * F_30 ( struct V_6 * V_7 , int V_66 )
{
struct V_24 * V_5 ;
V_5 = F_13 ( V_66 , V_7 ) ;
if ( F_15 ( V_5 ) )
return (struct V_22 * ) V_5 ;
return & V_5 -> V_30 ;
}
struct V_67 *
F_31 ( struct V_68 * V_69 , int V_70 )
{
unsigned V_45 = V_70 * sizeof( T_1 ) ;
struct V_67 * V_71 ;
if ( V_45 > V_72 )
return F_11 ( - V_55 ) ;
V_71 = F_4 ( sizeof *V_71 , V_14 ) ;
if ( ! V_71 )
return F_11 ( - V_21 ) ;
V_71 -> V_62 = F_4 ( V_45 , V_14 ) ;
if ( ! V_71 -> V_62 )
goto V_73;
return V_71 ;
V_73:
F_7 ( V_71 ) ;
return F_11 ( - V_21 ) ;
}
void F_32 ( struct V_67 * V_71 )
{
F_7 ( V_71 -> V_62 ) ;
F_7 ( V_71 ) ;
}
struct V_2 * F_33 ( struct V_6 * V_7 , int V_48 ,
struct V_74 * V_75 )
{
struct V_1 * V_76 ;
int V_9 ;
struct V_2 * V_25 ;
int V_11 = - V_21 ;
V_9 = ( V_75 -> V_77 + V_12 - 1 ) / V_12 ;
V_76 = F_4 ( sizeof *V_76 + V_9 * sizeof V_76 -> V_5 . V_13 [ 0 ] , V_14 ) ;
if ( ! V_76 )
goto V_15;
V_11 = F_3 ( & V_76 -> V_5 , V_7 , V_75 -> V_77 ) ;
if ( V_11 )
goto V_15;
V_11 = F_12 ( & V_76 -> V_5 , 0 ) ;
if ( V_11 )
goto V_28;
V_76 -> V_3 . V_33 = V_76 -> V_5 . V_32 ;
V_76 -> V_3 . V_32 = V_76 -> V_5 . V_32 ;
V_76 -> V_5 . V_29 = V_48 ;
V_76 -> V_5 . V_19 = V_75 -> V_77 ;
V_76 -> V_5 . V_61 = V_75 -> V_61 ;
V_25 = & V_76 -> V_3 ;
V_31:
return V_25 ;
V_28:
F_8 ( & V_76 -> V_5 ) ;
V_15:
F_7 ( V_76 ) ;
V_25 = F_11 ( V_11 ) ;
goto V_31;
}
int F_34 ( struct V_2 * V_3 , T_1 * V_62 ,
int V_78 , T_1 V_40 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_79 * V_80 ;
unsigned long V_81 ;
int V_9 , V_38 , V_10 ;
T_2 V_82 ;
int V_25 ;
V_10 = F_35 ( & V_76 -> V_5 . V_18 ) ;
if ( V_10 > 2 )
return - V_65 ;
if ( V_78 > V_76 -> V_5 . V_19 ) {
V_25 = - V_55 ;
goto V_15;
}
V_80 = & F_36 ( V_3 -> V_83 ) -> V_84 ;
F_37 ( & V_80 -> V_85 , V_81 ) ;
V_76 -> V_5 . V_39 = V_40 ;
V_76 -> V_5 . V_40 = V_40 ;
V_82 = 1 << V_76 -> V_5 . V_61 ;
V_76 -> V_5 . V_44 = V_78 * V_82 ;
V_9 = 0 ;
V_38 = 0 ;
for ( V_10 = 0 ; V_10 < V_78 ; V_10 ++ ) {
V_76 -> V_5 . V_13 [ V_9 ] -> V_41 [ V_38 ] . V_42 = ( void * ) V_62 [ V_10 ] ;
V_76 -> V_5 . V_13 [ V_9 ] -> V_41 [ V_38 ] . V_44 = V_82 ;
if ( ++ V_38 == V_12 ) {
V_9 ++ ;
V_38 = 0 ;
}
}
F_38 ( & V_80 -> V_85 , V_81 ) ;
V_25 = 0 ;
V_15:
return V_25 ;
}
int F_39 ( struct V_86 * V_87 )
{
struct V_1 * V_76 ;
struct V_79 * V_80 ;
unsigned long V_81 ;
F_18 (fmr, fmr_list, ibfmr.list) {
V_80 = & F_36 ( V_76 -> V_3 . V_83 ) -> V_84 ;
F_37 ( & V_80 -> V_85 , V_81 ) ;
V_76 -> V_5 . V_39 = 0 ;
V_76 -> V_5 . V_40 = 0 ;
V_76 -> V_5 . V_44 = 0 ;
F_38 ( & V_80 -> V_85 , V_81 ) ;
}
return 0 ;
}
int F_40 ( struct V_2 * V_3 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
int V_25 = 0 ;
unsigned long V_63 ;
F_26 ( & V_76 -> V_5 ) ;
F_27 ( & V_76 -> V_5 ) ;
V_63 = F_28 ( & V_76 -> V_5 . V_17 ,
5 * V_64 ) ;
if ( ! V_63 ) {
F_29 ( & V_76 -> V_5 ) ;
V_25 = - V_65 ;
goto V_20;
}
F_8 ( & V_76 -> V_5 ) ;
F_7 ( V_76 ) ;
V_20:
return V_25 ;
}
void F_41 ( struct V_88 * V_89 )
{
struct V_4 * V_5 = F_2 ( V_89 , struct V_4 , V_89 ) ;
F_42 ( & V_5 -> V_17 ) ;
}
