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
V_5 -> V_13 [ V_10 ] = F_4 ( sizeof( * V_5 -> V_13 [ 0 ] ) , V_14 ) ;
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
V_5 = F_4 ( sizeof( * V_5 ) , V_14 ) ;
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
V_5 = F_4 ( sizeof( * V_5 ) + V_9 * sizeof( V_5 -> V_5 . V_13 [ 0 ] ) , V_14 ) ;
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
int V_38 , V_9 , V_55 ;
struct V_22 * V_25 ;
if ( V_44 == 0 ) {
V_25 = F_11 ( - V_56 ) ;
goto V_15;
}
V_52 = F_17 ( V_7 -> V_57 -> V_58 , V_46 , V_44 ,
V_48 , 0 ) ;
if ( F_15 ( V_52 ) )
return ( void * ) V_52 ;
V_38 = V_52 -> V_59 ;
V_5 = F_13 ( V_38 , V_7 ) ;
if ( F_15 ( V_5 ) ) {
V_25 = (struct V_22 * ) V_5 ;
F_18 ( V_52 ) ;
goto V_15;
}
V_5 -> V_5 . V_39 = V_46 ;
V_5 -> V_5 . V_40 = V_47 ;
V_5 -> V_5 . V_44 = V_44 ;
V_5 -> V_5 . V_60 = F_19 ( V_52 ) ;
V_5 -> V_5 . V_29 = V_48 ;
V_5 -> V_52 = V_52 ;
if ( F_20 ( V_52 -> V_61 ) )
V_5 -> V_5 . V_62 = F_21 ( V_52 -> V_61 ) ;
V_9 = 0 ;
V_38 = 0 ;
F_22 (umem->sg_head.sgl, sg, umem->nmap, entry) {
void * V_42 ;
V_42 = F_23 ( F_24 ( V_54 ) ) ;
if ( ! V_42 ) {
V_25 = F_11 ( - V_56 ) ;
goto V_15;
}
V_5 -> V_5 . V_13 [ V_9 ] -> V_41 [ V_38 ] . V_42 = V_42 ;
V_5 -> V_5 . V_13 [ V_9 ] -> V_41 [ V_38 ] . V_44 = V_52 -> V_61 ;
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
int F_25 ( struct V_22 * V_30 )
{
struct V_24 * V_5 = F_26 ( V_30 ) ;
int V_25 = 0 ;
unsigned long V_63 ;
F_7 ( V_5 -> V_64 ) ;
F_27 ( & V_5 -> V_5 ) ;
F_28 ( & V_5 -> V_5 ) ;
V_63 = F_29 ( & V_5 -> V_5 . V_17 ,
5 * V_65 ) ;
if ( ! V_63 ) {
F_30 ( & V_5 -> V_5 ) ;
V_25 = - V_66 ;
goto V_20;
}
F_8 ( & V_5 -> V_5 ) ;
if ( V_5 -> V_52 )
F_18 ( V_5 -> V_52 ) ;
F_7 ( V_5 ) ;
V_20:
return V_25 ;
}
struct V_22 * F_31 ( struct V_6 * V_7 ,
enum V_67 V_68 ,
T_2 V_69 )
{
struct V_24 * V_5 ;
if ( V_68 != V_70 )
return F_11 ( - V_56 ) ;
V_5 = F_13 ( V_69 , V_7 ) ;
if ( F_15 ( V_5 ) )
return (struct V_22 * ) V_5 ;
V_5 -> V_64 = F_32 ( V_69 , sizeof( T_1 ) , V_14 ) ;
if ( ! V_5 -> V_64 )
goto V_71;
return & V_5 -> V_30 ;
V_71:
F_25 ( & V_5 -> V_30 ) ;
return F_11 ( - V_21 ) ;
}
static int F_33 ( struct V_22 * V_30 , T_1 V_43 )
{
struct V_24 * V_5 = F_26 ( V_30 ) ;
if ( F_34 ( V_5 -> V_72 == V_5 -> V_5 . V_19 ) )
return - V_21 ;
V_5 -> V_64 [ V_5 -> V_72 ++ ] = V_43 ;
return 0 ;
}
int F_35 ( struct V_22 * V_30 ,
struct V_53 * V_54 ,
int V_73 )
{
struct V_24 * V_5 = F_26 ( V_30 ) ;
V_5 -> V_72 = 0 ;
return F_36 ( V_30 , V_54 , V_73 , F_33 ) ;
}
struct V_2 * F_37 ( struct V_6 * V_7 , int V_48 ,
struct V_74 * V_75 )
{
struct V_1 * V_76 ;
int V_9 ;
struct V_2 * V_25 ;
int V_11 = - V_21 ;
V_9 = ( V_75 -> V_77 + V_12 - 1 ) / V_12 ;
V_76 = F_4 ( sizeof( * V_76 ) + V_9 * sizeof( V_76 -> V_5 . V_13 [ 0 ] ) , V_14 ) ;
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
V_76 -> V_5 . V_62 = V_75 -> V_62 ;
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
int F_38 ( struct V_2 * V_3 , T_1 * V_78 ,
int V_79 , T_1 V_40 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_80 * V_81 ;
unsigned long V_82 ;
int V_9 , V_38 , V_10 ;
T_2 V_83 ;
int V_25 ;
V_10 = F_39 ( & V_76 -> V_5 . V_18 ) ;
if ( V_10 > 2 )
return - V_66 ;
if ( V_79 > V_76 -> V_5 . V_19 ) {
V_25 = - V_56 ;
goto V_15;
}
V_81 = & F_40 ( V_3 -> V_84 ) -> V_85 ;
F_41 ( & V_81 -> V_86 , V_82 ) ;
V_76 -> V_5 . V_39 = V_40 ;
V_76 -> V_5 . V_40 = V_40 ;
V_83 = 1 << V_76 -> V_5 . V_62 ;
V_76 -> V_5 . V_44 = V_79 * V_83 ;
V_9 = 0 ;
V_38 = 0 ;
for ( V_10 = 0 ; V_10 < V_79 ; V_10 ++ ) {
V_76 -> V_5 . V_13 [ V_9 ] -> V_41 [ V_38 ] . V_42 = ( void * ) V_78 [ V_10 ] ;
V_76 -> V_5 . V_13 [ V_9 ] -> V_41 [ V_38 ] . V_44 = V_83 ;
if ( ++ V_38 == V_12 ) {
V_9 ++ ;
V_38 = 0 ;
}
}
F_42 ( & V_81 -> V_86 , V_82 ) ;
V_25 = 0 ;
V_15:
return V_25 ;
}
int F_43 ( struct V_87 * V_88 )
{
struct V_1 * V_76 ;
struct V_80 * V_81 ;
unsigned long V_82 ;
F_44 (fmr, fmr_list, ibfmr.list) {
V_81 = & F_40 ( V_76 -> V_3 . V_84 ) -> V_85 ;
F_41 ( & V_81 -> V_86 , V_82 ) ;
V_76 -> V_5 . V_39 = 0 ;
V_76 -> V_5 . V_40 = 0 ;
V_76 -> V_5 . V_44 = 0 ;
F_42 ( & V_81 -> V_86 , V_82 ) ;
}
return 0 ;
}
int F_45 ( struct V_2 * V_3 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
int V_25 = 0 ;
unsigned long V_63 ;
F_27 ( & V_76 -> V_5 ) ;
F_28 ( & V_76 -> V_5 ) ;
V_63 = F_29 ( & V_76 -> V_5 . V_17 ,
5 * V_65 ) ;
if ( ! V_63 ) {
F_30 ( & V_76 -> V_5 ) ;
V_25 = - V_66 ;
goto V_20;
}
F_8 ( & V_76 -> V_5 ) ;
F_7 ( V_76 ) ;
V_20:
return V_25 ;
}
void F_46 ( struct V_89 * V_90 )
{
struct V_4 * V_5 = F_2 ( V_90 , struct V_4 , V_90 ) ;
F_47 ( & V_5 -> V_17 ) ;
}
