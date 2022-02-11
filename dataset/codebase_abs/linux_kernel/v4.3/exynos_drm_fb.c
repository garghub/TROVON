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
F_8 ( V_8 ) ;
for ( V_11 = 0 ; V_11 < F_9 ( V_10 -> V_4 ) ; V_11 ++ ) {
struct V_12 * V_13 ;
if ( V_10 -> V_4 [ V_11 ] == NULL )
continue;
V_13 = & V_10 -> V_4 [ V_11 ] -> V_14 ;
F_10 ( V_13 ) ;
}
F_11 ( V_10 ) ;
V_10 = NULL ;
}
static int F_12 ( struct V_7 * V_8 ,
struct V_15 * V_16 ,
unsigned int * V_17 )
{
struct V_9 * V_10 = F_6 ( V_8 ) ;
return F_13 ( V_16 ,
& V_10 -> V_4 [ 0 ] -> V_14 , V_17 ) ;
}
static int F_14 ( struct V_7 * V_8 ,
struct V_15 * V_16 , unsigned V_5 ,
unsigned V_18 , struct V_19 * V_20 ,
unsigned V_21 )
{
return 0 ;
}
struct V_7 *
F_15 ( struct V_1 * V_22 ,
struct V_23 * V_24 ,
struct V_3 * * V_25 ,
int V_26 )
{
struct V_9 * V_10 ;
int V_11 ;
int V_27 ;
V_10 = F_16 ( sizeof( * V_10 ) , V_28 ) ;
if ( ! V_10 )
return F_17 ( - V_29 ) ;
for ( V_11 = 0 ; V_11 < V_26 ; V_11 ++ ) {
V_27 = F_1 ( V_22 , V_25 [ V_11 ] ) ;
if ( V_27 < 0 )
goto V_30;
V_10 -> V_4 [ V_11 ] = V_25 [ V_11 ] ;
}
F_18 ( & V_10 -> V_8 , V_24 ) ;
V_27 = F_19 ( V_22 , & V_10 -> V_8 , & V_31 ) ;
if ( V_27 < 0 ) {
F_4 ( L_2 ) ;
goto V_30;
}
return & V_10 -> V_8 ;
V_30:
F_11 ( V_10 ) ;
return F_17 ( V_27 ) ;
}
static struct V_7 *
F_20 ( struct V_1 * V_22 , struct V_15 * V_16 ,
struct V_23 * V_24 )
{
struct V_3 * V_32 [ V_33 ] ;
struct V_12 * V_13 ;
struct V_7 * V_8 ;
int V_11 ;
int V_27 ;
for ( V_11 = 0 ; V_11 < F_21 ( V_24 -> V_34 ) ; V_11 ++ ) {
V_13 = F_22 ( V_22 , V_16 ,
V_24 -> V_35 [ V_11 ] ) ;
if ( ! V_13 ) {
F_4 ( L_3 ) ;
V_27 = - V_36 ;
goto V_30;
}
V_32 [ V_11 ] = F_23 ( V_13 ) ;
}
V_8 = F_15 ( V_22 , V_24 , V_32 , V_11 ) ;
if ( F_24 ( V_8 ) ) {
V_27 = F_25 ( V_8 ) ;
goto V_30;
}
return V_8 ;
V_30:
while ( V_11 -- )
F_10 ( & V_32 [ V_11 ] -> V_14 ) ;
return F_17 ( V_27 ) ;
}
struct V_3 * F_26 ( struct V_7 * V_8 ,
int V_37 )
{
struct V_9 * V_10 = F_6 ( V_8 ) ;
struct V_3 * V_13 ;
if ( V_37 >= V_33 )
return NULL ;
V_13 = V_10 -> V_4 [ V_37 ] ;
if ( ! V_13 )
return NULL ;
F_27 ( L_4 , ( unsigned long ) V_13 -> V_38 ) ;
return V_13 ;
}
static void F_28 ( struct V_1 * V_22 )
{
struct V_39 * V_40 = V_22 -> V_41 ;
struct V_42 * V_43 = V_40 -> V_43 ;
if ( V_43 )
F_29 ( V_43 ) ;
else
F_30 ( V_22 ) ;
}
void F_31 ( struct V_1 * V_22 )
{
V_22 -> V_44 . V_45 = 0 ;
V_22 -> V_44 . V_46 = 0 ;
V_22 -> V_44 . V_47 = 4096 ;
V_22 -> V_44 . V_48 = 4096 ;
V_22 -> V_44 . V_49 = & V_50 ;
}
