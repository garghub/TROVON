static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_9 * V_10 ;
V_10 = & V_7 -> V_11 . V_12 . V_10 ;
return sprintf ( V_5 , L_1 , V_10 -> V_13 ) ;
}
static enum V_14 F_3 ( char * V_15 , int V_16 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ ) {
if ( ! strncmp ( V_19 [ V_17 ] , V_15 , V_16 ) )
return V_17 ;
}
return V_20 ;
}
static const char * F_4 ( enum V_14 V_21 )
{
F_5 ( V_21 < V_18 ) ;
return V_19 [ V_21 ] ;
}
static T_1 F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_22 * V_12 ;
V_12 = & V_7 -> V_11 . V_12 ;
return sprintf ( V_5 , L_2 , F_4 ( V_12 -> V_23 ) ) ;
}
static T_1 F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_24 ,
T_2 V_25 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
char V_26 [ V_27 + 1 ] ;
enum V_14 V_28 ;
struct V_22 * V_12 = & V_7 -> V_11 . V_12 ;
memcpy ( V_26 , V_24 , V_27 ) ;
if ( V_25 > V_27 )
V_25 = V_27 ;
if ( V_26 [ V_25 - 1 ] == '\n' )
V_25 -- ;
V_26 [ V_25 ] = '\0' ;
V_28 = F_3 ( V_26 , V_25 ) ;
if ( V_28 != V_20 ) {
F_8 ( & V_12 -> V_29 ) ;
V_12 -> V_23 = V_28 ;
F_9 ( & V_12 -> V_29 ) ;
} else {
return - V_30 ;
}
return V_25 ;
}
static T_1 F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_9 * V_10 ;
V_10 = & V_7 -> V_11 . V_12 . V_10 ;
return sprintf ( V_5 , L_1 , V_10 -> V_31 ) ;
}
static int F_11 ( struct V_32 * V_33 , void * V_34 )
{
struct V_6 * V_7 = (struct V_6 * ) V_33 -> V_35 ;
struct V_22 * V_12 ;
F_5 ( V_7 ) ;
V_12 = & V_7 -> V_11 . V_12 ;
F_12 ( V_33 , L_2 , V_12 -> V_10 . V_36 . V_37 ) ;
return 0 ;
}
static void * F_13 ( struct V_32 * V_38 , T_3 * V_39 )
{
struct V_6 * V_7 = V_38 -> V_35 ;
struct V_22 * V_12 = & V_7 -> V_11 . V_12 ;
return ( * V_39 >= V_12 -> V_10 . V_13 ) ? NULL : V_12 -> V_40 [ * V_39 ] ;
}
static void F_14 ( struct V_32 * V_38 , void * V_34 )
{
return;
}
static void * F_15 ( struct V_32 * V_38 , void * V_34 , T_3 * V_39 )
{
struct V_6 * V_7 = V_38 -> V_35 ;
struct V_22 * V_12 = & V_7 -> V_11 . V_12 ;
++ * V_39 ;
return ( * V_39 >= V_12 -> V_10 . V_13 ) ? NULL : V_12 -> V_40 [ * V_39 ] ;
}
static int F_16 ( struct V_32 * V_38 , void * V_34 )
{
struct V_41 * V_42 = V_34 ;
if ( ! V_42 )
return 0 ;
F_12 ( V_38 , L_3 ,
V_42 -> V_43 , V_42 -> V_44 . V_37 ,
V_42 -> V_45 ? L_4 : L_5 ) ;
return 0 ;
}
static int F_17 ( struct V_46 * V_46 , struct V_47 * V_47 )
{
struct V_32 * V_48 ;
int V_49 ;
V_49 = F_18 ( V_47 , & V_50 ) ;
if ( V_49 )
return V_49 ;
V_48 = V_47 -> V_51 ;
V_48 -> V_35 = V_46 -> V_52 ;
return 0 ;
}
void F_19 ( struct V_53 * V_54 )
{
V_54 -> V_55 = & V_56 ;
V_54 -> V_57 = V_58 ;
}
