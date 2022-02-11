struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
if ( V_4 >= V_7 )
return NULL ;
return V_6 -> V_8 [ V_4 ] ;
}
static void F_3 ( struct V_2 * V_3 )
{
struct V_5 * V_9 = F_2 ( V_3 ) ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_7 ; V_10 ++ )
F_4 ( V_9 -> V_8 [ V_10 ] ) ;
F_5 ( V_3 ) ;
F_6 ( V_9 ) ;
}
static int F_7 ( struct V_2 * V_3 ,
struct V_11 * V_12 ,
unsigned int * V_13 )
{
struct V_5 * V_9 = F_2 ( V_3 ) ;
return F_8 ( V_12 ,
V_9 -> V_8 [ 0 ] , V_13 ) ;
}
static int F_9 ( struct V_2 * V_3 ,
struct V_11 * V_14 ,
unsigned int V_15 , unsigned int V_16 ,
struct V_17 * V_18 ,
unsigned int V_19 )
{
F_10 ( V_3 -> V_20 ) ;
return 0 ;
}
static struct V_5 *
F_11 ( struct V_21 * V_20 , const struct V_22 * V_23 ,
struct V_1 * * V_8 , unsigned int V_24 )
{
struct V_5 * V_9 ;
int V_25 ;
int V_10 ;
V_9 = F_12 ( sizeof( * V_9 ) , V_26 ) ;
if ( ! V_9 )
return F_13 ( - V_27 ) ;
F_14 ( & V_9 -> V_3 , V_23 ) ;
for ( V_10 = 0 ; V_10 < V_24 ; V_10 ++ )
V_9 -> V_8 [ V_10 ] = V_8 [ V_10 ] ;
V_25 = F_15 ( V_20 , & V_9 -> V_3 ,
& V_28 ) ;
if ( V_25 ) {
F_16 ( V_20 -> V_20 , L_1 ,
V_25 ) ;
F_6 ( V_9 ) ;
return F_13 ( V_25 ) ;
}
return V_9 ;
}
static struct V_2 *
F_17 ( struct V_21 * V_20 , struct V_11 * V_12 ,
const struct V_22 * V_23 )
{
struct V_5 * V_9 ;
struct V_1 * V_29 [ V_7 ] ;
struct V_1 * V_8 ;
unsigned int V_30 ;
unsigned int V_31 ;
int V_24 ;
int V_25 ;
int V_10 ;
V_30 = F_18 ( V_23 -> V_32 ) ;
V_31 = F_19 ( V_23 -> V_32 ) ;
V_24 = F_20 ( F_21 ( V_23 -> V_32 ) ,
V_7 ) ;
for ( V_10 = 0 ; V_10 < V_24 ; V_10 ++ ) {
unsigned int V_33 = V_23 -> V_33 / ( V_10 ? V_30 : 1 ) ;
unsigned int V_34 = V_23 -> V_34 / ( V_10 ? V_31 : 1 ) ;
unsigned int V_35 ;
V_8 = F_22 ( V_12 , V_23 -> V_36 [ V_10 ] ) ;
if ( ! V_8 ) {
F_16 ( V_20 -> V_20 , L_2 ) ;
V_25 = - V_37 ;
goto V_38;
}
V_35 = ( V_34 - 1 ) * V_23 -> V_39 [ V_10 ] +
V_23 -> V_40 [ V_10 ] +
V_33 * F_23 ( V_23 -> V_32 , V_10 ) ;
if ( V_8 -> V_41 < V_35 ) {
F_4 ( V_8 ) ;
V_25 = - V_42 ;
goto V_38;
}
V_29 [ V_10 ] = V_8 ;
}
V_9 = F_11 ( V_20 , V_23 , V_29 , V_10 ) ;
if ( F_24 ( V_9 ) ) {
V_25 = F_25 ( V_9 ) ;
goto V_38;
}
return & V_9 -> V_3 ;
V_38:
for ( V_10 -- ; V_10 >= 0 ; V_10 -- )
F_4 ( V_29 [ V_10 ] ) ;
return F_13 ( V_25 ) ;
}
static void F_26 ( struct V_21 * V_20 )
{
struct V_43 * V_44 = V_20 -> V_45 ;
struct V_46 * V_47 = & V_44 -> V_48 ;
if ( V_47 )
F_27 ( V_47 ) ;
}
static void
F_28 ( struct V_49 * V_50 )
{
struct V_21 * V_20 = V_50 -> V_20 ;
F_29 ( V_20 , V_50 ) ;
F_30 ( V_20 , V_50 ) ;
F_31 ( V_20 , V_50 ,
V_51 ) ;
F_32 ( V_50 ) ;
F_33 ( V_20 , V_50 ) ;
F_34 ( V_20 , V_50 ) ;
}
struct V_2 *
F_35 ( struct V_21 * V_20 ,
const struct V_22 * V_23 ,
struct V_1 * V_8 )
{
struct V_5 * V_9 ;
V_9 = F_11 ( V_20 , V_23 , & V_8 , 1 ) ;
if ( F_24 ( V_9 ) )
return NULL ;
return & V_9 -> V_3 ;
}
void F_36 ( struct V_21 * V_20 )
{
V_20 -> V_52 . V_53 = 0 ;
V_20 -> V_52 . V_54 = 0 ;
V_20 -> V_52 . V_55 = 4096 ;
V_20 -> V_52 . V_56 = 4096 ;
V_20 -> V_52 . V_57 = & V_58 ;
V_20 -> V_52 . V_59 = & V_60 ;
}
