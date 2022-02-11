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
struct V_7 *
F_13 ( struct V_1 * V_18 ,
const struct V_19 * V_20 ,
struct V_3 * * V_4 ,
int V_21 )
{
struct V_9 * V_10 ;
int V_11 ;
int V_22 ;
V_10 = F_14 ( sizeof( * V_10 ) , V_23 ) ;
if ( ! V_10 )
return F_15 ( - V_24 ) ;
for ( V_11 = 0 ; V_11 < V_21 ; V_11 ++ ) {
V_22 = F_1 ( V_18 , V_4 [ V_11 ] ) ;
if ( V_22 < 0 )
goto V_25;
V_10 -> V_4 [ V_11 ] = V_4 [ V_11 ] ;
V_10 -> V_26 [ V_11 ] = V_4 [ V_11 ] -> V_26
+ V_20 -> V_27 [ V_11 ] ;
}
F_16 ( V_18 , & V_10 -> V_8 , V_20 ) ;
V_22 = F_17 ( V_18 , & V_10 -> V_8 , & V_28 ) ;
if ( V_22 < 0 ) {
F_4 ( L_2 ) ;
goto V_25;
}
return & V_10 -> V_8 ;
V_25:
F_10 ( V_10 ) ;
return F_15 ( V_22 ) ;
}
static struct V_7 *
F_18 ( struct V_1 * V_18 , struct V_15 * V_16 ,
const struct V_19 * V_20 )
{
const struct V_29 * V_30 = F_19 ( V_18 , V_20 ) ;
struct V_3 * V_4 [ V_31 ] ;
struct V_12 * V_13 ;
struct V_7 * V_8 ;
int V_11 ;
int V_22 ;
for ( V_11 = 0 ; V_11 < V_30 -> V_32 ; V_11 ++ ) {
unsigned int V_33 = ( V_11 == 0 ) ? V_20 -> V_33 :
F_20 ( V_20 -> V_33 , V_30 -> V_34 ) ;
unsigned long V_35 = V_33 * V_20 -> V_36 [ V_11 ] +
V_20 -> V_27 [ V_11 ] ;
V_13 = F_21 ( V_16 , V_20 -> V_37 [ V_11 ] ) ;
if ( ! V_13 ) {
F_4 ( L_3 ) ;
V_22 = - V_38 ;
goto V_25;
}
V_4 [ V_11 ] = F_22 ( V_13 ) ;
if ( V_35 > V_4 [ V_11 ] -> V_35 ) {
V_11 ++ ;
V_22 = - V_6 ;
goto V_25;
}
}
V_8 = F_13 ( V_18 , V_20 , V_4 , V_11 ) ;
if ( F_23 ( V_8 ) ) {
V_22 = F_24 ( V_8 ) ;
goto V_25;
}
return V_8 ;
V_25:
while ( V_11 -- )
F_9 ( & V_4 [ V_11 ] -> V_14 ) ;
return F_15 ( V_22 ) ;
}
T_1 F_25 ( struct V_7 * V_8 , int V_39 )
{
struct V_9 * V_10 = F_6 ( V_8 ) ;
if ( F_26 ( V_39 >= V_31 ) )
return 0 ;
return V_10 -> V_26 [ V_39 ] ;
}
void F_27 ( struct V_1 * V_18 )
{
V_18 -> V_40 . V_41 = 0 ;
V_18 -> V_40 . V_42 = 0 ;
V_18 -> V_40 . V_43 = 4096 ;
V_18 -> V_40 . V_44 = 4096 ;
V_18 -> V_40 . V_45 = & V_46 ;
V_18 -> V_40 . V_47 = & V_48 ;
V_18 -> V_40 . V_49 = true ;
}
