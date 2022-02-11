int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 , T_1 V_6 ,
int * V_7 )
{
struct V_8 * V_9 ;
void * V_10 ;
int V_11 ;
V_9 = F_2 ( V_2 , V_4 , V_5 ) ;
if ( ! V_9 )
return - V_12 ;
F_3 ( & V_4 -> V_13 . V_14 ) ;
if ( V_9 -> V_15 ) {
F_4 ( V_9 -> V_15 -> V_16 ) ;
* V_7 = F_5 ( V_9 -> V_15 -> V_16 , V_6 ) ;
F_6 ( V_9 ) ;
F_7 ( & V_4 -> V_13 . V_14 ) ;
return 0 ;
}
if ( V_9 -> V_17 ) {
F_4 ( V_9 -> V_17 ) ;
* V_7 = F_5 ( V_9 -> V_17 , V_6 ) ;
F_6 ( V_9 ) ;
} else {
V_10 = V_2 -> V_18 -> V_19 ( V_2 , V_9 , V_6 ) ;
if ( F_8 ( V_10 ) ) {
F_6 ( V_9 ) ;
F_7 ( & V_4 -> V_13 . V_14 ) ;
return F_9 ( V_10 ) ;
}
V_9 -> V_17 = V_10 ;
* V_7 = F_5 ( V_10 , V_6 ) ;
}
V_11 = F_10 ( & V_4 -> V_13 ,
V_9 -> V_17 , V_5 ) ;
if ( V_11 ) {
F_6 ( V_9 ) ;
F_7 ( & V_4 -> V_13 . V_14 ) ;
return V_11 ;
}
F_7 ( & V_4 -> V_13 . V_14 ) ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_7 , T_1 * V_5 )
{
struct V_20 * V_20 ;
struct V_8 * V_9 ;
int V_11 ;
V_20 = F_12 ( V_7 ) ;
if ( F_8 ( V_20 ) )
return F_9 ( V_20 ) ;
F_3 ( & V_4 -> V_13 . V_14 ) ;
V_11 = F_13 ( & V_4 -> V_13 ,
V_20 , V_5 ) ;
if ( ! V_11 ) {
V_11 = 0 ;
goto V_21;
}
V_9 = V_2 -> V_18 -> V_22 ( V_2 , V_20 ) ;
if ( F_8 ( V_9 ) ) {
V_11 = F_9 ( V_9 ) ;
goto V_21;
}
V_11 = F_14 ( V_4 , V_9 , V_5 ) ;
F_6 ( V_9 ) ;
if ( V_11 )
goto V_21;
V_11 = F_10 ( & V_4 -> V_13 ,
V_20 , * V_5 ) ;
if ( V_11 )
goto V_23;
F_7 ( & V_4 -> V_13 . V_14 ) ;
return 0 ;
V_23:
F_15 ( V_9 ) ;
V_21:
F_16 ( V_20 ) ;
F_7 ( & V_4 -> V_13 . V_14 ) ;
return V_11 ;
}
int F_17 ( struct V_1 * V_2 , void * V_24 ,
struct V_3 * V_4 )
{
struct V_25 * args = V_24 ;
T_1 V_6 ;
if ( ! F_18 ( V_2 , V_26 ) )
return - V_27 ;
if ( ! V_2 -> V_18 -> V_28 )
return - V_29 ;
if ( args -> V_6 & ~ V_30 )
return - V_27 ;
V_6 = args -> V_6 & V_30 ;
return V_2 -> V_18 -> V_28 ( V_2 , V_4 ,
args -> V_5 , V_6 , & args -> V_31 ) ;
}
int F_19 ( struct V_1 * V_2 , void * V_24 ,
struct V_3 * V_4 )
{
struct V_25 * args = V_24 ;
if ( ! F_18 ( V_2 , V_26 ) )
return - V_27 ;
if ( ! V_2 -> V_18 -> V_32 )
return - V_29 ;
return V_2 -> V_18 -> V_32 ( V_2 , V_4 ,
args -> V_31 , & args -> V_5 ) ;
}
struct V_33 * F_20 ( struct V_34 * * V_35 , int V_36 )
{
struct V_33 * V_37 = NULL ;
struct V_38 * V_39 ;
int V_40 ;
int V_11 ;
V_37 = F_21 ( sizeof( struct V_33 ) , V_41 ) ;
if ( ! V_37 )
goto V_42;
V_11 = F_22 ( V_37 , V_36 , V_41 ) ;
if ( V_11 )
goto V_42;
F_23 (sg->sgl, iter, nr_pages, i)
F_24 ( V_39 , V_35 [ V_40 ] , V_43 , 0 ) ;
return V_37 ;
V_42:
F_25 ( V_37 ) ;
return NULL ;
}
int F_26 ( struct V_33 * V_44 , struct V_34 * * V_35 ,
T_2 * V_45 , int V_46 )
{
unsigned V_47 ;
struct V_38 * V_37 ;
struct V_34 * V_34 ;
T_3 V_48 , V_49 ;
int V_50 ;
T_2 V_51 ;
V_50 = 0 ;
F_23 (sgt->sgl, sg, sgt->nents, count) {
V_48 = V_37 -> V_52 ;
V_49 = V_37 -> V_49 ;
V_34 = F_27 ( V_37 ) ;
V_51 = F_28 ( V_37 ) ;
while ( V_48 > 0 ) {
if ( F_29 ( V_50 >= V_46 ) )
return - 1 ;
V_35 [ V_50 ] = V_34 ;
if ( V_45 )
V_45 [ V_50 ] = V_51 ;
V_34 ++ ;
V_51 += V_43 ;
V_48 -= V_43 ;
V_50 ++ ;
}
}
return 0 ;
}
void F_30 ( struct V_8 * V_9 , struct V_33 * V_37 )
{
struct V_53 * V_54 ;
struct V_20 * V_20 ;
V_54 = V_9 -> V_15 ;
if ( V_37 )
F_31 ( V_54 , V_37 , V_55 ) ;
V_20 = V_54 -> V_16 ;
F_32 ( V_54 -> V_16 , V_54 ) ;
F_16 ( V_20 ) ;
}
void F_33 ( struct V_56 * V_57 )
{
F_34 ( & V_57 -> V_58 ) ;
F_35 ( & V_57 -> V_14 ) ;
}
void F_36 ( struct V_56 * V_57 )
{
struct V_59 * V_60 , * V_61 ;
F_37 (member, safe, &prime_fpriv->head, entry) {
F_38 ( & V_60 -> V_62 ) ;
F_25 ( V_60 ) ;
}
}
int F_10 ( struct V_56 * V_57 , struct V_20 * V_20 , T_1 V_5 )
{
struct V_59 * V_60 ;
V_60 = F_21 ( sizeof( * V_60 ) , V_41 ) ;
if ( ! V_60 )
return - V_63 ;
V_60 -> V_20 = V_20 ;
V_60 -> V_5 = V_5 ;
F_39 ( & V_60 -> V_62 , & V_57 -> V_58 ) ;
return 0 ;
}
int F_13 ( struct V_56 * V_57 , struct V_20 * V_20 , T_1 * V_5 )
{
struct V_59 * V_60 ;
F_40 (member, &prime_fpriv->head, entry) {
if ( V_60 -> V_20 == V_20 ) {
* V_5 = V_60 -> V_5 ;
return 0 ;
}
}
return - V_12 ;
}
void F_41 ( struct V_56 * V_57 , struct V_20 * V_20 )
{
struct V_59 * V_60 , * V_61 ;
F_3 ( & V_57 -> V_14 ) ;
F_37 (member, safe, &prime_fpriv->head, entry) {
if ( V_60 -> V_20 == V_20 ) {
F_38 ( & V_60 -> V_62 ) ;
F_25 ( V_60 ) ;
}
}
F_7 ( & V_57 -> V_14 ) ;
}
