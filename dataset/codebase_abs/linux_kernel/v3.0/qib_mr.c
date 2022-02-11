static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
struct V_4 * F_3 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 = F_4 ( V_6 -> V_10 ) ;
struct V_11 * V_12 ;
struct V_4 * V_13 ;
unsigned long V_14 ;
if ( F_5 ( V_6 ) -> V_15 ) {
V_13 = F_6 ( - V_16 ) ;
goto V_17;
}
V_12 = F_7 ( sizeof *V_12 , V_18 ) ;
if ( ! V_12 ) {
V_13 = F_6 ( - V_19 ) ;
goto V_17;
}
V_12 -> V_12 . V_20 = V_7 ;
F_8 ( & V_12 -> V_12 . V_21 , 0 ) ;
F_9 ( & V_9 -> V_22 . V_23 , V_14 ) ;
if ( ! V_9 -> V_24 )
V_9 -> V_24 = & V_12 -> V_12 ;
F_10 ( & V_9 -> V_22 . V_23 , V_14 ) ;
V_13 = & V_12 -> V_25 ;
V_17:
return V_13 ;
}
static struct V_11 * F_11 ( int V_26 , struct V_27 * V_22 )
{
struct V_11 * V_12 ;
int V_28 , V_29 = 0 ;
V_28 = ( V_26 + V_30 - 1 ) / V_30 ;
V_12 = F_12 ( sizeof *V_12 + V_28 * sizeof V_12 -> V_12 . V_31 [ 0 ] , V_18 ) ;
if ( ! V_12 )
goto V_32;
for (; V_29 < V_28 ; V_29 ++ ) {
V_12 -> V_12 . V_31 [ V_29 ] = F_12 ( sizeof * V_12 -> V_12 . V_31 [ 0 ] , V_18 ) ;
if ( ! V_12 -> V_12 . V_31 [ V_29 ] )
goto V_17;
}
V_12 -> V_12 . V_33 = V_28 ;
V_12 -> V_12 . V_34 = 0 ;
V_12 -> V_12 . V_35 = V_26 ;
if ( ! F_13 ( V_22 , & V_12 -> V_12 ) )
goto V_17;
V_12 -> V_25 . V_36 = V_12 -> V_12 . V_36 ;
V_12 -> V_25 . V_37 = V_12 -> V_12 . V_36 ;
F_8 ( & V_12 -> V_12 . V_21 , 0 ) ;
goto V_32;
V_17:
while ( V_29 )
F_14 ( V_12 -> V_12 . V_31 [ -- V_29 ] ) ;
F_14 ( V_12 ) ;
V_12 = NULL ;
V_32:
return V_12 ;
}
struct V_4 * F_15 ( struct V_5 * V_6 ,
struct V_38 * V_39 ,
int V_40 , int V_7 , T_1 * V_41 )
{
struct V_11 * V_12 ;
int V_42 , V_28 , V_29 ;
struct V_4 * V_13 ;
V_12 = F_11 ( V_40 , & F_4 ( V_6 -> V_10 ) -> V_22 ) ;
if ( V_12 == NULL ) {
V_13 = F_6 ( - V_19 ) ;
goto V_17;
}
V_12 -> V_12 . V_6 = V_6 ;
V_12 -> V_12 . V_43 = * V_41 ;
V_12 -> V_12 . V_44 = * V_41 ;
V_12 -> V_12 . V_45 = 0 ;
V_12 -> V_12 . V_46 = 0 ;
V_12 -> V_12 . V_20 = V_7 ;
V_12 -> V_47 = NULL ;
V_28 = 0 ;
V_42 = 0 ;
for ( V_29 = 0 ; V_29 < V_40 ; V_29 ++ ) {
V_12 -> V_12 . V_31 [ V_28 ] -> V_48 [ V_42 ] . V_49 = ( void * ) V_39 [ V_29 ] . V_50 ;
V_12 -> V_12 . V_31 [ V_28 ] -> V_48 [ V_42 ] . V_45 = V_39 [ V_29 ] . V_51 ;
V_12 -> V_12 . V_45 += V_39 [ V_29 ] . V_51 ;
V_42 ++ ;
if ( V_42 == V_30 ) {
V_28 ++ ;
V_42 = 0 ;
}
}
V_13 = & V_12 -> V_25 ;
V_17:
return V_13 ;
}
struct V_4 * F_16 ( struct V_5 * V_6 , T_1 V_52 , T_1 V_45 ,
T_1 V_53 , int V_54 ,
struct V_55 * V_56 )
{
struct V_11 * V_12 ;
struct V_57 * V_47 ;
struct V_58 * V_59 ;
int V_42 , V_28 , V_29 ;
struct V_4 * V_13 ;
if ( V_45 == 0 ) {
V_13 = F_6 ( - V_60 ) ;
goto V_17;
}
V_47 = F_17 ( V_6 -> V_61 -> V_62 , V_52 , V_45 ,
V_54 , 0 ) ;
if ( F_18 ( V_47 ) )
return ( void * ) V_47 ;
V_42 = 0 ;
F_19 (chunk, &umem->chunk_list, list)
V_42 += V_59 -> V_63 ;
V_12 = F_11 ( V_42 , & F_4 ( V_6 -> V_10 ) -> V_22 ) ;
if ( ! V_12 ) {
V_13 = F_6 ( - V_19 ) ;
F_20 ( V_47 ) ;
goto V_17;
}
V_12 -> V_12 . V_6 = V_6 ;
V_12 -> V_12 . V_43 = V_52 ;
V_12 -> V_12 . V_44 = V_53 ;
V_12 -> V_12 . V_45 = V_45 ;
V_12 -> V_12 . V_46 = V_47 -> V_46 ;
V_12 -> V_12 . V_20 = V_54 ;
V_12 -> V_47 = V_47 ;
if ( F_21 ( V_47 -> V_64 ) )
V_12 -> V_12 . V_34 = F_22 ( V_47 -> V_64 ) ;
V_28 = 0 ;
V_42 = 0 ;
F_19 (chunk, &umem->chunk_list, list) {
for ( V_29 = 0 ; V_29 < V_59 -> V_63 ; V_29 ++ ) {
void * V_49 ;
V_49 = F_23 ( F_24 ( & V_59 -> V_65 [ V_29 ] ) ) ;
if ( ! V_49 ) {
V_13 = F_6 ( - V_60 ) ;
goto V_17;
}
V_12 -> V_12 . V_31 [ V_28 ] -> V_48 [ V_42 ] . V_49 = V_49 ;
V_12 -> V_12 . V_31 [ V_28 ] -> V_48 [ V_42 ] . V_45 = V_47 -> V_64 ;
V_42 ++ ;
if ( V_42 == V_30 ) {
V_28 ++ ;
V_42 = 0 ;
}
}
}
V_13 = & V_12 -> V_25 ;
V_17:
return V_13 ;
}
int F_25 ( struct V_4 * V_25 )
{
struct V_11 * V_12 = F_26 ( V_25 ) ;
struct V_8 * V_9 = F_4 ( V_25 -> V_10 ) ;
int V_13 ;
int V_29 ;
V_13 = F_27 ( V_9 , & V_12 -> V_12 ) ;
if ( V_13 )
return V_13 ;
V_29 = V_12 -> V_12 . V_33 ;
while ( V_29 )
F_14 ( V_12 -> V_12 . V_31 [ -- V_29 ] ) ;
if ( V_12 -> V_47 )
F_20 ( V_12 -> V_47 ) ;
F_14 ( V_12 ) ;
return 0 ;
}
struct V_4 * F_28 ( struct V_5 * V_6 , int V_66 )
{
struct V_11 * V_12 ;
V_12 = F_11 ( V_66 , & F_4 ( V_6 -> V_10 ) -> V_22 ) ;
if ( V_12 == NULL )
return F_6 ( - V_19 ) ;
V_12 -> V_12 . V_6 = V_6 ;
V_12 -> V_12 . V_43 = 0 ;
V_12 -> V_12 . V_44 = 0 ;
V_12 -> V_12 . V_45 = 0 ;
V_12 -> V_12 . V_46 = 0 ;
V_12 -> V_12 . V_20 = 0 ;
V_12 -> V_47 = NULL ;
return & V_12 -> V_25 ;
}
struct V_67 *
F_29 ( struct V_68 * V_69 , int V_70 )
{
unsigned V_51 = V_70 * sizeof( T_1 ) ;
struct V_67 * V_71 ;
if ( V_51 > V_72 )
return F_6 ( - V_60 ) ;
V_71 = F_12 ( sizeof *V_71 , V_18 ) ;
if ( ! V_71 )
return F_6 ( - V_19 ) ;
V_71 -> V_65 = F_12 ( V_51 , V_18 ) ;
if ( ! V_71 -> V_65 )
goto V_73;
return V_71 ;
V_73:
F_14 ( V_71 ) ;
return F_6 ( - V_19 ) ;
}
void F_30 ( struct V_67 * V_71 )
{
F_14 ( V_71 -> V_65 ) ;
F_14 ( V_71 ) ;
}
struct V_2 * F_31 ( struct V_5 * V_6 , int V_54 ,
struct V_74 * V_75 )
{
struct V_1 * V_76 ;
int V_28 , V_29 = 0 ;
struct V_2 * V_13 ;
V_28 = ( V_75 -> V_77 + V_30 - 1 ) / V_30 ;
V_76 = F_12 ( sizeof *V_76 + V_28 * sizeof V_76 -> V_12 . V_31 [ 0 ] , V_18 ) ;
if ( ! V_76 )
goto V_17;
for (; V_29 < V_28 ; V_29 ++ ) {
V_76 -> V_12 . V_31 [ V_29 ] = F_12 ( sizeof * V_76 -> V_12 . V_31 [ 0 ] ,
V_18 ) ;
if ( ! V_76 -> V_12 . V_31 [ V_29 ] )
goto V_17;
}
V_76 -> V_12 . V_33 = V_28 ;
if ( ! F_13 ( & F_4 ( V_6 -> V_10 ) -> V_22 , & V_76 -> V_12 ) )
goto V_17;
V_76 -> V_3 . V_37 = V_76 -> V_12 . V_36 ;
V_76 -> V_3 . V_36 = V_76 -> V_12 . V_36 ;
V_76 -> V_12 . V_6 = V_6 ;
V_76 -> V_12 . V_43 = 0 ;
V_76 -> V_12 . V_44 = 0 ;
V_76 -> V_12 . V_45 = 0 ;
V_76 -> V_12 . V_46 = 0 ;
V_76 -> V_12 . V_20 = V_54 ;
V_76 -> V_12 . V_35 = V_75 -> V_77 ;
V_76 -> V_12 . V_34 = V_75 -> V_34 ;
F_8 ( & V_76 -> V_12 . V_21 , 0 ) ;
V_13 = & V_76 -> V_3 ;
goto V_32;
V_17:
while ( V_29 )
F_14 ( V_76 -> V_12 . V_31 [ -- V_29 ] ) ;
F_14 ( V_76 ) ;
V_13 = F_6 ( - V_19 ) ;
V_32:
return V_13 ;
}
int F_32 ( struct V_2 * V_3 , T_1 * V_65 ,
int V_78 , T_1 V_44 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_27 * V_79 ;
unsigned long V_14 ;
int V_28 , V_42 , V_29 ;
T_2 V_80 ;
int V_13 ;
if ( F_33 ( & V_76 -> V_12 . V_21 ) )
return - V_81 ;
if ( V_78 > V_76 -> V_12 . V_35 ) {
V_13 = - V_60 ;
goto V_17;
}
V_79 = & F_4 ( V_3 -> V_10 ) -> V_22 ;
F_9 ( & V_79 -> V_23 , V_14 ) ;
V_76 -> V_12 . V_43 = V_44 ;
V_76 -> V_12 . V_44 = V_44 ;
V_80 = 1 << V_76 -> V_12 . V_34 ;
V_76 -> V_12 . V_45 = V_78 * V_80 ;
V_28 = 0 ;
V_42 = 0 ;
for ( V_29 = 0 ; V_29 < V_78 ; V_29 ++ ) {
V_76 -> V_12 . V_31 [ V_28 ] -> V_48 [ V_42 ] . V_49 = ( void * ) V_65 [ V_29 ] ;
V_76 -> V_12 . V_31 [ V_28 ] -> V_48 [ V_42 ] . V_45 = V_80 ;
if ( ++ V_42 == V_30 ) {
V_28 ++ ;
V_42 = 0 ;
}
}
F_10 ( & V_79 -> V_23 , V_14 ) ;
V_13 = 0 ;
V_17:
return V_13 ;
}
int F_34 ( struct V_82 * V_83 )
{
struct V_1 * V_76 ;
struct V_27 * V_79 ;
unsigned long V_14 ;
F_19 (fmr, fmr_list, ibfmr.list) {
V_79 = & F_4 ( V_76 -> V_3 . V_10 ) -> V_22 ;
F_9 ( & V_79 -> V_23 , V_14 ) ;
V_76 -> V_12 . V_43 = 0 ;
V_76 -> V_12 . V_44 = 0 ;
V_76 -> V_12 . V_45 = 0 ;
F_10 ( & V_79 -> V_23 , V_14 ) ;
}
return 0 ;
}
int F_35 ( struct V_2 * V_3 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
int V_13 ;
int V_29 ;
V_13 = F_27 ( F_4 ( V_3 -> V_10 ) , & V_76 -> V_12 ) ;
if ( V_13 )
return V_13 ;
V_29 = V_76 -> V_12 . V_33 ;
while ( V_29 )
F_14 ( V_76 -> V_12 . V_31 [ -- V_29 ] ) ;
F_14 ( V_76 ) ;
return 0 ;
}
