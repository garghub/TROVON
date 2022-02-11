static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
struct V_4 * F_3 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 ;
struct V_4 * V_10 ;
V_9 = F_4 ( sizeof *V_9 , V_11 ) ;
if ( ! V_9 ) {
V_10 = F_5 ( - V_12 ) ;
goto V_13;
}
V_9 -> V_9 . V_14 = V_7 ;
V_10 = & V_9 -> V_15 ;
V_13:
return V_10 ;
}
static struct V_8 * F_6 ( int V_16 ,
struct V_17 * V_18 )
{
struct V_8 * V_9 ;
int V_19 , V_20 = 0 ;
V_19 = ( V_16 + V_21 - 1 ) / V_21 ;
V_9 = F_7 ( sizeof *V_9 + V_19 * sizeof V_9 -> V_9 . V_22 [ 0 ] , V_11 ) ;
if ( ! V_9 )
goto V_23;
for (; V_20 < V_19 ; V_20 ++ ) {
V_9 -> V_9 . V_22 [ V_20 ] = F_7 ( sizeof * V_9 -> V_9 . V_22 [ 0 ] , V_11 ) ;
if ( ! V_9 -> V_9 . V_22 [ V_20 ] )
goto V_13;
}
V_9 -> V_9 . V_24 = V_19 ;
if ( ! F_8 ( V_18 , & V_9 -> V_9 ) )
goto V_13;
V_9 -> V_15 . V_25 = V_9 -> V_15 . V_26 = V_9 -> V_9 . V_26 ;
goto V_23;
V_13:
while ( V_20 ) {
V_20 -- ;
F_9 ( V_9 -> V_9 . V_22 [ V_20 ] ) ;
}
F_9 ( V_9 ) ;
V_9 = NULL ;
V_23:
return V_9 ;
}
struct V_4 * F_10 ( struct V_5 * V_6 ,
struct V_27 * V_28 ,
int V_29 , int V_7 , T_1 * V_30 )
{
struct V_8 * V_9 ;
int V_31 , V_19 , V_20 ;
struct V_4 * V_10 ;
V_9 = F_6 ( V_29 , & F_11 ( V_6 -> V_32 ) -> V_18 ) ;
if ( V_9 == NULL ) {
V_10 = F_5 ( - V_12 ) ;
goto V_13;
}
V_9 -> V_9 . V_6 = V_6 ;
V_9 -> V_9 . V_33 = * V_30 ;
V_9 -> V_9 . V_34 = * V_30 ;
V_9 -> V_9 . V_35 = 0 ;
V_9 -> V_9 . V_36 = 0 ;
V_9 -> V_9 . V_14 = V_7 ;
V_9 -> V_9 . V_37 = V_29 ;
V_9 -> V_38 = NULL ;
V_19 = 0 ;
V_31 = 0 ;
for ( V_20 = 0 ; V_20 < V_29 ; V_20 ++ ) {
V_9 -> V_9 . V_22 [ V_19 ] -> V_39 [ V_31 ] . V_40 = ( void * ) V_28 [ V_20 ] . V_41 ;
V_9 -> V_9 . V_22 [ V_19 ] -> V_39 [ V_31 ] . V_35 = V_28 [ V_20 ] . V_42 ;
V_9 -> V_9 . V_35 += V_28 [ V_20 ] . V_42 ;
V_31 ++ ;
if ( V_31 == V_21 ) {
V_19 ++ ;
V_31 = 0 ;
}
}
V_10 = & V_9 -> V_15 ;
V_13:
return V_10 ;
}
struct V_4 * F_12 ( struct V_5 * V_6 , T_1 V_43 , T_1 V_35 ,
T_1 V_44 , int V_45 ,
struct V_46 * V_47 )
{
struct V_8 * V_9 ;
struct V_48 * V_38 ;
int V_31 , V_19 , V_49 ;
struct V_50 * V_51 ;
struct V_4 * V_10 ;
if ( V_35 == 0 ) {
V_10 = F_5 ( - V_52 ) ;
goto V_13;
}
V_38 = F_13 ( V_6 -> V_53 -> V_54 , V_43 , V_35 ,
V_45 , 0 ) ;
if ( F_14 ( V_38 ) )
return ( void * ) V_38 ;
V_31 = V_38 -> V_55 ;
V_9 = F_6 ( V_31 , & F_11 ( V_6 -> V_32 ) -> V_18 ) ;
if ( ! V_9 ) {
V_10 = F_5 ( - V_12 ) ;
F_15 ( V_38 ) ;
goto V_13;
}
V_9 -> V_9 . V_6 = V_6 ;
V_9 -> V_9 . V_33 = V_43 ;
V_9 -> V_9 . V_34 = V_44 ;
V_9 -> V_9 . V_35 = V_35 ;
V_9 -> V_9 . V_36 = F_16 ( V_38 ) ;
V_9 -> V_9 . V_14 = V_45 ;
V_9 -> V_9 . V_37 = V_31 ;
V_9 -> V_38 = V_38 ;
V_19 = 0 ;
V_31 = 0 ;
F_17 (umem->sg_head.sgl, sg, umem->nmap, entry) {
void * V_40 ;
V_40 = F_18 ( F_19 ( V_51 ) ) ;
if ( ! V_40 ) {
V_10 = F_5 ( - V_52 ) ;
goto V_13;
}
V_9 -> V_9 . V_22 [ V_19 ] -> V_39 [ V_31 ] . V_40 = V_40 ;
V_9 -> V_9 . V_22 [ V_19 ] -> V_39 [ V_31 ] . V_35 = V_38 -> V_56 ;
V_31 ++ ;
if ( V_31 == V_21 ) {
V_19 ++ ;
V_31 = 0 ;
}
}
V_10 = & V_9 -> V_15 ;
V_13:
return V_10 ;
}
int F_20 ( struct V_4 * V_15 )
{
struct V_8 * V_9 = F_21 ( V_15 ) ;
int V_20 ;
F_22 ( & F_11 ( V_15 -> V_32 ) -> V_18 , V_15 -> V_26 ) ;
V_20 = V_9 -> V_9 . V_24 ;
while ( V_20 ) {
V_20 -- ;
F_9 ( V_9 -> V_9 . V_22 [ V_20 ] ) ;
}
if ( V_9 -> V_38 )
F_15 ( V_9 -> V_38 ) ;
F_9 ( V_9 ) ;
return 0 ;
}
struct V_2 * F_23 ( struct V_5 * V_6 , int V_45 ,
struct V_57 * V_58 )
{
struct V_1 * V_59 ;
int V_19 , V_20 = 0 ;
struct V_2 * V_10 ;
V_19 = ( V_58 -> V_60 + V_21 - 1 ) / V_21 ;
V_59 = F_7 ( sizeof *V_59 + V_19 * sizeof V_59 -> V_9 . V_22 [ 0 ] , V_11 ) ;
if ( ! V_59 )
goto V_13;
for (; V_20 < V_19 ; V_20 ++ ) {
V_59 -> V_9 . V_22 [ V_20 ] = F_7 ( sizeof * V_59 -> V_9 . V_22 [ 0 ] ,
V_11 ) ;
if ( ! V_59 -> V_9 . V_22 [ V_20 ] )
goto V_13;
}
V_59 -> V_9 . V_24 = V_19 ;
if ( ! F_8 ( & F_11 ( V_6 -> V_32 ) -> V_18 , & V_59 -> V_9 ) )
goto V_13;
V_59 -> V_3 . V_25 = V_59 -> V_3 . V_26 = V_59 -> V_9 . V_26 ;
V_59 -> V_9 . V_6 = V_6 ;
V_59 -> V_9 . V_33 = 0 ;
V_59 -> V_9 . V_34 = 0 ;
V_59 -> V_9 . V_35 = 0 ;
V_59 -> V_9 . V_36 = 0 ;
V_59 -> V_9 . V_14 = V_45 ;
V_59 -> V_9 . V_37 = V_58 -> V_60 ;
V_59 -> V_61 = V_58 -> V_61 ;
V_10 = & V_59 -> V_3 ;
goto V_23;
V_13:
while ( V_20 )
F_9 ( V_59 -> V_9 . V_22 [ -- V_20 ] ) ;
F_9 ( V_59 ) ;
V_10 = F_5 ( - V_12 ) ;
V_23:
return V_10 ;
}
int F_24 ( struct V_2 * V_3 , T_1 * V_62 ,
int V_63 , T_1 V_34 )
{
struct V_1 * V_59 = F_1 ( V_3 ) ;
struct V_17 * V_64 ;
unsigned long V_65 ;
int V_19 , V_31 , V_20 ;
T_2 V_66 ;
int V_10 ;
if ( V_63 > V_59 -> V_9 . V_37 ) {
V_10 = - V_52 ;
goto V_13;
}
V_64 = & F_11 ( V_3 -> V_32 ) -> V_18 ;
F_25 ( & V_64 -> V_67 , V_65 ) ;
V_59 -> V_9 . V_33 = V_34 ;
V_59 -> V_9 . V_34 = V_34 ;
V_66 = 1 << V_59 -> V_61 ;
V_59 -> V_9 . V_35 = V_63 * V_66 ;
V_19 = 0 ;
V_31 = 0 ;
V_66 = 1 << V_59 -> V_61 ;
for ( V_20 = 0 ; V_20 < V_63 ; V_20 ++ ) {
V_59 -> V_9 . V_22 [ V_19 ] -> V_39 [ V_31 ] . V_40 = ( void * ) V_62 [ V_20 ] ;
V_59 -> V_9 . V_22 [ V_19 ] -> V_39 [ V_31 ] . V_35 = V_66 ;
if ( ++ V_31 == V_21 ) {
V_19 ++ ;
V_31 = 0 ;
}
}
F_26 ( & V_64 -> V_67 , V_65 ) ;
V_10 = 0 ;
V_13:
return V_10 ;
}
int F_27 ( struct V_68 * V_69 )
{
struct V_1 * V_59 ;
struct V_17 * V_64 ;
unsigned long V_65 ;
F_28 (fmr, fmr_list, ibfmr.list) {
V_64 = & F_11 ( V_59 -> V_3 . V_32 ) -> V_18 ;
F_25 ( & V_64 -> V_67 , V_65 ) ;
V_59 -> V_9 . V_33 = 0 ;
V_59 -> V_9 . V_34 = 0 ;
V_59 -> V_9 . V_35 = 0 ;
F_26 ( & V_64 -> V_67 , V_65 ) ;
}
return 0 ;
}
int F_29 ( struct V_2 * V_3 )
{
struct V_1 * V_59 = F_1 ( V_3 ) ;
int V_20 ;
F_22 ( & F_11 ( V_3 -> V_32 ) -> V_18 , V_3 -> V_26 ) ;
V_20 = V_59 -> V_9 . V_24 ;
while ( V_20 )
F_9 ( V_59 -> V_9 . V_22 [ -- V_20 ] ) ;
F_9 ( V_59 ) ;
return 0 ;
}
