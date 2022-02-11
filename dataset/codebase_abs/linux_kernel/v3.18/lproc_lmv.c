static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_7 * V_8 ;
F_2 ( V_5 != NULL ) ;
V_8 = & V_5 -> V_9 . V_10 . V_8 ;
return F_3 ( V_2 , L_1 , V_8 -> V_11 ) ;
}
static enum V_12 F_4 ( char * V_13 , int V_14 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
if ( ! strncmp ( V_17 [ V_15 ] , V_13 , V_14 ) )
return V_15 ;
}
return V_18 ;
}
static const char * F_5 ( enum V_12 V_19 )
{
F_2 ( V_19 < V_16 ) ;
return V_17 [ V_19 ] ;
}
static int F_6 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_20 * V_10 ;
F_2 ( V_5 != NULL ) ;
V_10 = & V_5 -> V_9 . V_10 ;
return F_3 ( V_2 , L_2 , F_5 ( V_10 -> V_21 ) ) ;
}
static T_1 F_7 ( struct V_22 * V_22 ,
const char T_2 * V_23 ,
T_3 V_24 , T_4 * V_25 )
{
struct V_4 * V_5 = ( (struct V_1 * ) V_22 -> V_26 ) -> V_6 ;
char V_27 [ V_28 + 1 ] ;
int V_14 = V_24 ;
enum V_12 V_29 ;
struct V_20 * V_10 ;
if ( F_8 ( V_27 , V_23 , V_28 ) )
return - V_30 ;
F_2 ( V_5 != NULL ) ;
V_10 = & V_5 -> V_9 . V_10 ;
if ( V_14 > V_28 )
V_14 = V_28 ;
if ( V_27 [ V_14 - 1 ] == '\n' )
V_14 -- ;
V_27 [ V_14 ] = '\0' ;
V_29 = F_4 ( V_27 , V_14 ) ;
if ( V_29 != V_18 ) {
F_9 ( & V_10 -> V_31 ) ;
V_10 -> V_21 = V_29 ;
F_10 ( & V_10 -> V_31 ) ;
} else {
F_11 ( L_3 , V_27 ) ;
return - V_32 ;
}
return V_24 ;
}
static int F_12 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_7 * V_8 ;
F_2 ( V_5 != NULL ) ;
V_8 = & V_5 -> V_9 . V_10 . V_8 ;
return F_3 ( V_2 , L_1 , V_8 -> V_33 ) ;
}
static int F_13 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_20 * V_10 ;
F_2 ( V_5 != NULL ) ;
V_10 = & V_5 -> V_9 . V_10 ;
return F_3 ( V_2 , L_2 , V_10 -> V_8 . V_34 . V_35 ) ;
}
static void * F_14 ( struct V_1 * V_36 , T_4 * V_37 )
{
struct V_4 * V_5 = V_36 -> V_6 ;
struct V_20 * V_10 = & V_5 -> V_9 . V_10 ;
return ( * V_37 >= V_10 -> V_8 . V_11 ) ? NULL : V_10 -> V_38 [ * V_37 ] ;
}
static void F_15 ( struct V_1 * V_36 , void * V_3 )
{
return;
}
static void * F_16 ( struct V_1 * V_36 , void * V_3 , T_4 * V_37 )
{
struct V_4 * V_5 = V_36 -> V_6 ;
struct V_20 * V_10 = & V_5 -> V_9 . V_10 ;
++ * V_37 ;
return ( * V_37 >= V_10 -> V_8 . V_11 ) ? NULL : V_10 -> V_38 [ * V_37 ] ;
}
static int F_17 ( struct V_1 * V_36 , void * V_3 )
{
struct V_39 * V_40 = V_3 ;
if ( V_40 == NULL )
return 0 ;
return F_3 ( V_36 , L_4 , V_40 -> V_41 ,
V_40 -> V_42 . V_35 , V_40 -> V_43 ? L_5 : L_6 ) ;
}
static int F_18 ( struct V_44 * V_44 , struct V_22 * V_22 )
{
struct V_1 * V_45 ;
int V_46 ;
V_46 = F_19 ( V_22 , & V_47 ) ;
if ( V_46 )
return V_46 ;
V_45 = V_22 -> V_26 ;
V_45 -> V_6 = F_20 ( V_44 ) ;
return 0 ;
}
void F_21 ( struct V_48 * V_49 )
{
V_49 -> V_50 = V_51 ;
V_49 -> V_52 = V_53 ;
}
