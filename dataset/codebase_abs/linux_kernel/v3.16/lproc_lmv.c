static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_7 * V_8 ;
F_2 ( V_5 != NULL ) ;
V_8 = & V_5 -> V_9 . V_10 . V_8 ;
return F_3 ( V_2 , L_1 , V_8 -> V_11 ) ;
}
static T_1 F_4 ( char * V_12 , int V_13 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
if ( ! strncmp ( V_16 [ V_14 ] , V_12 , V_13 ) )
return V_14 ;
}
return V_17 ;
}
static const char * F_5 ( T_1 V_18 )
{
F_2 ( V_18 < V_15 ) ;
return V_16 [ V_18 ] ;
}
static int F_6 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_19 * V_10 ;
F_2 ( V_5 != NULL ) ;
V_10 = & V_5 -> V_9 . V_10 ;
return F_3 ( V_2 , L_2 , F_5 ( V_10 -> V_20 ) ) ;
}
static T_2 F_7 ( struct V_21 * V_21 ,
const char T_3 * V_22 ,
T_4 V_23 , T_5 * V_24 )
{
struct V_4 * V_5 = ( (struct V_1 * ) V_21 -> V_25 ) -> V_6 ;
char V_26 [ V_27 + 1 ] ;
int V_13 = V_23 ;
T_1 V_28 ;
struct V_19 * V_10 ;
if ( F_8 ( V_26 , V_22 , V_27 ) )
return - V_29 ;
F_2 ( V_5 != NULL ) ;
V_10 = & V_5 -> V_9 . V_10 ;
if ( V_13 > V_27 )
V_13 = V_27 ;
if ( V_26 [ V_13 - 1 ] == '\n' )
V_13 -- ;
V_26 [ V_13 ] = '\0' ;
V_28 = F_4 ( V_26 , V_13 ) ;
if ( V_28 != V_17 ) {
F_9 ( & V_10 -> V_30 ) ;
V_10 -> V_20 = V_28 ;
F_10 ( & V_10 -> V_30 ) ;
} else {
F_11 ( L_3 , V_26 ) ;
return - V_31 ;
}
return V_23 ;
}
static int F_12 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_7 * V_8 ;
F_2 ( V_5 != NULL ) ;
V_8 = & V_5 -> V_9 . V_10 . V_8 ;
return F_3 ( V_2 , L_1 , V_8 -> V_32 ) ;
}
static int F_13 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_19 * V_10 ;
F_2 ( V_5 != NULL ) ;
V_10 = & V_5 -> V_9 . V_10 ;
return F_3 ( V_2 , L_2 , V_10 -> V_8 . V_33 . V_34 ) ;
}
static void * F_14 ( struct V_1 * V_35 , T_5 * V_36 )
{
struct V_4 * V_5 = V_35 -> V_6 ;
struct V_19 * V_10 = & V_5 -> V_9 . V_10 ;
return ( * V_36 >= V_10 -> V_8 . V_11 ) ? NULL : V_10 -> V_37 [ * V_36 ] ;
}
static void F_15 ( struct V_1 * V_35 , void * V_3 )
{
return;
}
static void * F_16 ( struct V_1 * V_35 , void * V_3 , T_5 * V_36 )
{
struct V_4 * V_5 = V_35 -> V_6 ;
struct V_19 * V_10 = & V_5 -> V_9 . V_10 ;
++ * V_36 ;
return ( * V_36 >= V_10 -> V_8 . V_11 ) ? NULL : V_10 -> V_37 [ * V_36 ] ;
}
static int F_17 ( struct V_1 * V_35 , void * V_3 )
{
struct V_38 * V_39 = V_3 ;
if ( V_39 == NULL )
return 0 ;
return F_3 ( V_35 , L_4 , V_39 -> V_40 ,
V_39 -> V_41 . V_34 , V_39 -> V_42 ? L_5 : L_6 ) ;
}
static int F_18 ( struct V_43 * V_43 , struct V_21 * V_21 )
{
struct V_1 * V_44 ;
int V_45 ;
V_45 = F_19 ( V_21 , & V_46 ) ;
if ( V_45 )
return V_45 ;
V_44 = V_21 -> V_25 ;
V_44 -> V_6 = F_20 ( V_43 ) ;
return 0 ;
}
void F_21 ( struct V_47 * V_48 )
{
V_48 -> V_49 = V_50 ;
V_48 -> V_51 = V_52 ;
}
