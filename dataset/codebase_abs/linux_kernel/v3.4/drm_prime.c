int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 , T_1 V_6 ,
int * V_7 )
{
struct V_8 * V_9 ;
void * V_10 ;
V_9 = F_2 ( V_2 , V_4 , V_5 ) ;
if ( ! V_9 )
return - V_11 ;
F_3 ( & V_4 -> V_12 . V_13 ) ;
if ( V_9 -> V_14 ) {
F_4 ( V_9 -> V_14 -> V_15 ) ;
* V_7 = F_5 ( V_9 -> V_14 -> V_15 , V_6 ) ;
F_6 ( V_9 ) ;
F_7 ( & V_4 -> V_12 . V_13 ) ;
return 0 ;
}
if ( V_9 -> V_16 ) {
F_4 ( V_9 -> V_16 ) ;
* V_7 = F_5 ( V_9 -> V_16 , V_6 ) ;
F_6 ( V_9 ) ;
} else {
V_10 = V_2 -> V_17 -> V_18 ( V_2 , V_9 , V_6 ) ;
if ( F_8 ( V_10 ) ) {
F_6 ( V_9 ) ;
F_7 ( & V_4 -> V_12 . V_13 ) ;
return F_9 ( V_10 ) ;
}
V_9 -> V_16 = V_10 ;
* V_7 = F_5 ( V_10 , V_6 ) ;
}
F_7 ( & V_4 -> V_12 . V_13 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_7 , T_1 * V_5 )
{
struct V_19 * V_19 ;
struct V_8 * V_9 ;
int V_20 ;
V_19 = F_11 ( V_7 ) ;
if ( F_8 ( V_19 ) )
return F_9 ( V_19 ) ;
F_3 ( & V_4 -> V_12 . V_13 ) ;
V_20 = F_12 ( & V_4 -> V_12 ,
V_19 , V_5 ) ;
if ( ! V_20 ) {
V_20 = 0 ;
goto V_21;
}
V_9 = V_2 -> V_17 -> V_22 ( V_2 , V_19 ) ;
if ( F_8 ( V_9 ) ) {
V_20 = F_9 ( V_9 ) ;
goto V_21;
}
V_20 = F_13 ( V_4 , V_9 , V_5 ) ;
F_6 ( V_9 ) ;
if ( V_20 )
goto V_21;
V_20 = F_14 ( & V_4 -> V_12 ,
V_19 , * V_5 ) ;
if ( V_20 )
goto V_23;
F_7 ( & V_4 -> V_12 . V_13 ) ;
return 0 ;
V_23:
F_15 ( V_9 ) ;
V_21:
F_16 ( V_19 ) ;
F_7 ( & V_4 -> V_12 . V_13 ) ;
return V_20 ;
}
int F_17 ( struct V_1 * V_2 , void * V_24 ,
struct V_3 * V_4 )
{
struct V_25 * args = V_24 ;
T_1 V_6 ;
if ( ! F_18 ( V_2 , V_26 ) )
return - V_27 ;
if ( ! V_2 -> V_17 -> V_28 )
return - V_29 ;
if ( args -> V_6 & ~ V_30 )
return - V_27 ;
V_6 = args -> V_6 & V_30 ;
return V_2 -> V_17 -> V_28 ( V_2 , V_4 ,
args -> V_5 , V_6 , & args -> V_31 ) ;
}
int F_19 ( struct V_1 * V_2 , void * V_24 ,
struct V_3 * V_4 )
{
struct V_25 * args = V_24 ;
if ( ! F_18 ( V_2 , V_26 ) )
return - V_27 ;
if ( ! V_2 -> V_17 -> V_32 )
return - V_29 ;
return V_2 -> V_17 -> V_32 ( V_2 , V_4 ,
args -> V_31 , & args -> V_5 ) ;
}
struct V_33 * F_20 ( struct V_34 * * V_35 , int V_36 )
{
struct V_33 * V_37 = NULL ;
struct V_38 * V_39 ;
int V_40 ;
int V_20 ;
V_37 = F_21 ( sizeof( struct V_33 ) , V_41 ) ;
if ( ! V_37 )
goto V_42;
V_20 = F_22 ( V_37 , V_36 , V_41 ) ;
if ( V_20 )
goto V_42;
F_23 (sg->sgl, iter, nr_pages, i)
F_24 ( V_39 , V_35 [ V_40 ] , V_43 , 0 ) ;
return V_37 ;
V_42:
F_25 ( V_37 ) ;
return NULL ;
}
void F_26 ( struct V_8 * V_9 , struct V_33 * V_37 )
{
struct V_44 * V_45 ;
struct V_19 * V_19 ;
V_45 = V_9 -> V_14 ;
if ( V_37 )
F_27 ( V_45 , V_37 , V_46 ) ;
V_19 = V_45 -> V_15 ;
F_28 ( V_45 -> V_15 , V_45 ) ;
F_16 ( V_19 ) ;
}
void F_29 ( struct V_47 * V_48 )
{
F_30 ( & V_48 -> V_49 ) ;
F_31 ( & V_48 -> V_13 ) ;
}
void F_32 ( struct V_47 * V_48 )
{
struct V_50 * V_51 , * V_52 ;
F_33 (member, safe, &prime_fpriv->head, entry) {
F_34 ( & V_51 -> V_53 ) ;
F_25 ( V_51 ) ;
}
}
int F_14 ( struct V_47 * V_48 , struct V_19 * V_19 , T_1 V_5 )
{
struct V_50 * V_51 ;
V_51 = F_21 ( sizeof( * V_51 ) , V_41 ) ;
if ( ! V_51 )
return - V_54 ;
V_51 -> V_19 = V_19 ;
V_51 -> V_5 = V_5 ;
F_35 ( & V_51 -> V_53 , & V_48 -> V_49 ) ;
return 0 ;
}
int F_12 ( struct V_47 * V_48 , struct V_19 * V_19 , T_1 * V_5 )
{
struct V_50 * V_51 ;
F_36 (member, &prime_fpriv->head, entry) {
if ( V_51 -> V_19 == V_19 ) {
* V_5 = V_51 -> V_5 ;
return 0 ;
}
}
return - V_11 ;
}
void F_37 ( struct V_47 * V_48 , struct V_19 * V_19 )
{
struct V_50 * V_51 , * V_52 ;
F_3 ( & V_48 -> V_13 ) ;
F_33 (member, safe, &prime_fpriv->head, entry) {
if ( V_51 -> V_19 == V_19 ) {
F_34 ( & V_51 -> V_53 ) ;
F_25 ( V_51 ) ;
}
}
F_7 ( & V_48 -> V_13 ) ;
}
