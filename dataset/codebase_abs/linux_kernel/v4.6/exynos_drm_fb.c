static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_5 ;
if ( F_2 ( V_2 ) )
return 0 ;
V_5 = V_4 -> V_5 ;
if ( F_3 ( V_5 ) ) {
F_4 ( L_1 ) ;
return - V_6 ;
}
return 0 ;
}
static void F_5 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_6 ( V_8 ) ;
unsigned int V_11 ;
F_7 ( V_8 ) ;
for ( V_11 = 0 ; V_11 < F_8 ( V_10 -> V_4 ) ; V_11 ++ ) {
struct V_12 * V_13 ;
if ( V_10 -> V_4 [ V_11 ] == NULL )
continue;
V_13 = & V_10 -> V_4 [ V_11 ] -> V_14 ;
F_9 ( V_13 ) ;
}
F_10 ( V_10 ) ;
V_10 = NULL ;
}
static int F_11 ( struct V_7 * V_8 ,
struct V_15 * V_16 ,
unsigned int * V_17 )
{
struct V_9 * V_10 = F_6 ( V_8 ) ;
return F_12 ( V_16 ,
& V_10 -> V_4 [ 0 ] -> V_14 , V_17 ) ;
}
static int F_13 ( struct V_7 * V_8 ,
struct V_15 * V_16 , unsigned V_5 ,
unsigned V_18 , struct V_19 * V_20 ,
unsigned V_21 )
{
return 0 ;
}
struct V_7 *
F_14 ( struct V_1 * V_22 ,
const struct V_23 * V_24 ,
struct V_3 * * V_4 ,
int V_25 )
{
struct V_9 * V_10 ;
int V_11 ;
int V_26 ;
V_10 = F_15 ( sizeof( * V_10 ) , V_27 ) ;
if ( ! V_10 )
return F_16 ( - V_28 ) ;
for ( V_11 = 0 ; V_11 < V_25 ; V_11 ++ ) {
V_26 = F_1 ( V_22 , V_4 [ V_11 ] ) ;
if ( V_26 < 0 )
goto V_29;
V_10 -> V_4 [ V_11 ] = V_4 [ V_11 ] ;
V_10 -> V_30 [ V_11 ] = V_4 [ V_11 ] -> V_30
+ V_24 -> V_31 [ V_11 ] ;
}
F_17 ( & V_10 -> V_8 , V_24 ) ;
V_26 = F_18 ( V_22 , & V_10 -> V_8 , & V_32 ) ;
if ( V_26 < 0 ) {
F_4 ( L_2 ) ;
goto V_29;
}
return & V_10 -> V_8 ;
V_29:
F_10 ( V_10 ) ;
return F_16 ( V_26 ) ;
}
static struct V_7 *
F_19 ( struct V_1 * V_22 , struct V_15 * V_16 ,
const struct V_23 * V_24 )
{
struct V_3 * V_4 [ V_33 ] ;
struct V_12 * V_13 ;
struct V_7 * V_8 ;
int V_11 ;
int V_26 ;
for ( V_11 = 0 ; V_11 < F_20 ( V_24 -> V_34 ) ; V_11 ++ ) {
V_13 = F_21 ( V_22 , V_16 ,
V_24 -> V_35 [ V_11 ] ) ;
if ( ! V_13 ) {
F_4 ( L_3 ) ;
V_26 = - V_36 ;
goto V_29;
}
V_4 [ V_11 ] = F_22 ( V_13 ) ;
}
V_8 = F_14 ( V_22 , V_24 , V_4 , V_11 ) ;
if ( F_23 ( V_8 ) ) {
V_26 = F_24 ( V_8 ) ;
goto V_29;
}
return V_8 ;
V_29:
while ( V_11 -- )
F_9 ( & V_4 [ V_11 ] -> V_14 ) ;
return F_16 ( V_26 ) ;
}
T_1 F_25 ( struct V_7 * V_8 , int V_37 )
{
struct V_9 * V_10 = F_6 ( V_8 ) ;
if ( V_37 >= V_33 )
return V_38 ;
return V_10 -> V_30 [ V_37 ] ;
}
void F_26 ( struct V_1 * V_22 )
{
V_22 -> V_39 . V_40 = 0 ;
V_22 -> V_39 . V_41 = 0 ;
V_22 -> V_39 . V_42 = 4096 ;
V_22 -> V_39 . V_43 = 4096 ;
V_22 -> V_39 . V_44 = & V_45 ;
}
