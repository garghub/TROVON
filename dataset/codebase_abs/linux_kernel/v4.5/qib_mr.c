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
struct V_22 * F_14 ( struct V_6 * V_7 , T_1 V_34 , T_1 V_35 ,
T_1 V_36 , int V_37 ,
struct V_38 * V_39 )
{
struct V_24 * V_5 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
int V_44 , V_9 , V_45 ;
struct V_22 * V_25 ;
if ( V_35 == 0 ) {
V_25 = F_11 ( - V_46 ) ;
goto V_15;
}
V_41 = F_15 ( V_7 -> V_47 -> V_48 , V_34 , V_35 ,
V_37 , 0 ) ;
if ( F_16 ( V_41 ) )
return ( void * ) V_41 ;
V_44 = V_41 -> V_49 ;
V_5 = F_13 ( V_44 , V_7 ) ;
if ( F_16 ( V_5 ) ) {
V_25 = (struct V_22 * ) V_5 ;
F_17 ( V_41 ) ;
goto V_15;
}
V_5 -> V_5 . V_50 = V_34 ;
V_5 -> V_5 . V_51 = V_36 ;
V_5 -> V_5 . V_35 = V_35 ;
V_5 -> V_5 . V_52 = F_18 ( V_41 ) ;
V_5 -> V_5 . V_29 = V_37 ;
V_5 -> V_41 = V_41 ;
if ( F_19 ( V_41 -> V_53 ) )
V_5 -> V_5 . V_54 = F_20 ( V_41 -> V_53 ) ;
V_9 = 0 ;
V_44 = 0 ;
F_21 (umem->sg_head.sgl, sg, umem->nmap, entry) {
void * V_55 ;
V_55 = F_22 ( F_23 ( V_43 ) ) ;
if ( ! V_55 ) {
V_25 = F_11 ( - V_46 ) ;
goto V_15;
}
V_5 -> V_5 . V_13 [ V_9 ] -> V_56 [ V_44 ] . V_55 = V_55 ;
V_5 -> V_5 . V_13 [ V_9 ] -> V_56 [ V_44 ] . V_35 = V_41 -> V_53 ;
V_44 ++ ;
if ( V_44 == V_12 ) {
V_9 ++ ;
V_44 = 0 ;
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
unsigned long V_57 ;
F_7 ( V_5 -> V_58 ) ;
F_26 ( & V_5 -> V_5 ) ;
F_27 ( & V_5 -> V_5 ) ;
V_57 = F_28 ( & V_5 -> V_5 . V_17 ,
5 * V_59 ) ;
if ( ! V_57 ) {
F_29 ( & V_5 -> V_5 ) ;
V_25 = - V_60 ;
goto V_20;
}
F_8 ( & V_5 -> V_5 ) ;
if ( V_5 -> V_41 )
F_17 ( V_5 -> V_41 ) ;
F_7 ( V_5 ) ;
V_20:
return V_25 ;
}
struct V_22 * F_30 ( struct V_6 * V_7 ,
enum V_61 V_62 ,
T_2 V_63 )
{
struct V_24 * V_5 ;
if ( V_62 != V_64 )
return F_11 ( - V_46 ) ;
V_5 = F_13 ( V_63 , V_7 ) ;
if ( F_16 ( V_5 ) )
return (struct V_22 * ) V_5 ;
V_5 -> V_58 = F_31 ( V_63 , sizeof( T_1 ) , V_14 ) ;
if ( ! V_5 -> V_58 )
goto V_65;
return & V_5 -> V_30 ;
V_65:
F_24 ( & V_5 -> V_30 ) ;
return F_11 ( - V_21 ) ;
}
static int F_32 ( struct V_22 * V_30 , T_1 V_66 )
{
struct V_24 * V_5 = F_25 ( V_30 ) ;
if ( F_33 ( V_5 -> V_67 == V_5 -> V_5 . V_19 ) )
return - V_21 ;
V_5 -> V_58 [ V_5 -> V_67 ++ ] = V_66 ;
return 0 ;
}
int F_34 ( struct V_22 * V_30 ,
struct V_42 * V_43 ,
int V_68 )
{
struct V_24 * V_5 = F_25 ( V_30 ) ;
V_5 -> V_67 = 0 ;
return F_35 ( V_30 , V_43 , V_68 , F_32 ) ;
}
struct V_2 * F_36 ( struct V_6 * V_7 , int V_37 ,
struct V_69 * V_70 )
{
struct V_1 * V_71 ;
int V_9 ;
struct V_2 * V_25 ;
int V_11 = - V_21 ;
V_9 = ( V_70 -> V_72 + V_12 - 1 ) / V_12 ;
V_71 = F_4 ( sizeof( * V_71 ) + V_9 * sizeof( V_71 -> V_5 . V_13 [ 0 ] ) , V_14 ) ;
if ( ! V_71 )
goto V_15;
V_11 = F_3 ( & V_71 -> V_5 , V_7 , V_70 -> V_72 ) ;
if ( V_11 )
goto V_15;
V_11 = F_12 ( & V_71 -> V_5 , 0 ) ;
if ( V_11 )
goto V_28;
V_71 -> V_3 . V_33 = V_71 -> V_5 . V_32 ;
V_71 -> V_3 . V_32 = V_71 -> V_5 . V_32 ;
V_71 -> V_5 . V_29 = V_37 ;
V_71 -> V_5 . V_19 = V_70 -> V_72 ;
V_71 -> V_5 . V_54 = V_70 -> V_54 ;
V_25 = & V_71 -> V_3 ;
V_31:
return V_25 ;
V_28:
F_8 ( & V_71 -> V_5 ) ;
V_15:
F_7 ( V_71 ) ;
V_25 = F_11 ( V_11 ) ;
goto V_31;
}
int F_37 ( struct V_2 * V_3 , T_1 * V_73 ,
int V_74 , T_1 V_51 )
{
struct V_1 * V_71 = F_1 ( V_3 ) ;
struct V_75 * V_76 ;
unsigned long V_77 ;
int V_9 , V_44 , V_10 ;
T_2 V_78 ;
int V_25 ;
V_10 = F_38 ( & V_71 -> V_5 . V_18 ) ;
if ( V_10 > 2 )
return - V_60 ;
if ( V_74 > V_71 -> V_5 . V_19 ) {
V_25 = - V_46 ;
goto V_15;
}
V_76 = & F_39 ( V_3 -> V_79 ) -> V_80 ;
F_40 ( & V_76 -> V_81 , V_77 ) ;
V_71 -> V_5 . V_50 = V_51 ;
V_71 -> V_5 . V_51 = V_51 ;
V_78 = 1 << V_71 -> V_5 . V_54 ;
V_71 -> V_5 . V_35 = V_74 * V_78 ;
V_9 = 0 ;
V_44 = 0 ;
for ( V_10 = 0 ; V_10 < V_74 ; V_10 ++ ) {
V_71 -> V_5 . V_13 [ V_9 ] -> V_56 [ V_44 ] . V_55 = ( void * ) V_73 [ V_10 ] ;
V_71 -> V_5 . V_13 [ V_9 ] -> V_56 [ V_44 ] . V_35 = V_78 ;
if ( ++ V_44 == V_12 ) {
V_9 ++ ;
V_44 = 0 ;
}
}
F_41 ( & V_76 -> V_81 , V_77 ) ;
V_25 = 0 ;
V_15:
return V_25 ;
}
int F_42 ( struct V_82 * V_83 )
{
struct V_1 * V_71 ;
struct V_75 * V_76 ;
unsigned long V_77 ;
F_43 (fmr, fmr_list, ibfmr.list) {
V_76 = & F_39 ( V_71 -> V_3 . V_79 ) -> V_80 ;
F_40 ( & V_76 -> V_81 , V_77 ) ;
V_71 -> V_5 . V_50 = 0 ;
V_71 -> V_5 . V_51 = 0 ;
V_71 -> V_5 . V_35 = 0 ;
F_41 ( & V_76 -> V_81 , V_77 ) ;
}
return 0 ;
}
int F_44 ( struct V_2 * V_3 )
{
struct V_1 * V_71 = F_1 ( V_3 ) ;
int V_25 = 0 ;
unsigned long V_57 ;
F_26 ( & V_71 -> V_5 ) ;
F_27 ( & V_71 -> V_5 ) ;
V_57 = F_28 ( & V_71 -> V_5 . V_17 ,
5 * V_59 ) ;
if ( ! V_57 ) {
F_29 ( & V_71 -> V_5 ) ;
V_25 = - V_60 ;
goto V_20;
}
F_8 ( & V_71 -> V_5 ) ;
F_7 ( V_71 ) ;
V_20:
return V_25 ;
}
void F_45 ( struct V_84 * V_85 )
{
struct V_4 * V_5 = F_2 ( V_85 , struct V_4 , V_85 ) ;
F_46 ( & V_5 -> V_17 ) ;
}
