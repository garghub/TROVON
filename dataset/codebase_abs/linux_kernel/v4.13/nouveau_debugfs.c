static int
F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_7 * V_8 = V_7 ( V_5 -> V_9 -> V_10 ) ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 . V_13 ; V_11 ++ )
F_2 ( V_2 , L_1 , V_8 -> V_12 . V_3 [ V_11 ] ) ;
return 0 ;
}
static int
F_3 ( struct V_1 * V_2 , void * V_3 )
{
struct V_14 * V_8 = V_2 -> V_6 ;
struct V_15 * V_16 = V_15 ( V_8 ) ;
struct V_17 * V_18 = & V_16 -> V_18 ;
struct V_19 V_20 = {} ;
int V_21 , V_11 ;
if ( ! V_16 )
return - V_22 ;
V_21 = F_4 ( V_18 , V_23 , & V_20 , sizeof( V_20 ) ) ;
if ( V_21 )
return V_21 ;
for ( V_11 = 0 ; V_11 < V_20 . V_24 + 1 ; V_11 ++ ) {
const T_1 V_25 = V_11 < V_20 . V_24 ? V_11 :
V_26 ;
struct V_27 V_28 = {
. V_25 = V_25 ,
. V_29 = 0 ,
} ;
V_21 = F_4 ( V_18 , V_30 ,
& V_28 , sizeof( V_28 ) ) ;
if ( V_21 )
return V_21 ;
if ( V_11 < V_20 . V_24 )
F_2 ( V_2 , L_2 , V_28 . V_25 ) ;
else
F_2 ( V_2 , L_3 , V_20 . V_31 == 0 ? L_4 :
V_20 . V_31 == 1 ? L_5 : L_6 ) ;
V_28 . V_29 = 0 ;
do {
V_28 . V_25 = V_25 ;
V_21 = F_4 ( V_18 , V_30 ,
& V_28 , sizeof( V_28 ) ) ;
if ( V_21 )
return V_21 ;
F_2 ( V_2 , L_7 , V_28 . V_32 , V_28 . V_33 ) ;
if ( V_28 . V_33 != V_28 . V_34 )
F_2 ( V_2 , L_8 , V_28 . V_34 ) ;
F_2 ( V_2 , L_9 , V_28 . V_35 ) ;
} while ( V_28 . V_29 );
if ( V_25 >= 0 ) {
if ( V_20 . V_36 == V_25 )
F_2 ( V_2 , L_10 ) ;
if ( V_20 . V_37 == V_25 )
F_2 ( V_2 , L_11 ) ;
if ( V_20 . V_38 == V_25 )
F_2 ( V_2 , L_12 ) ;
} else {
if ( V_20 . V_36 < - 1 )
F_2 ( V_2 , L_10 ) ;
if ( V_20 . V_37 < - 1 )
F_2 ( V_2 , L_11 ) ;
}
F_2 ( V_2 , L_13 ) ;
}
return 0 ;
}
static T_2
F_5 ( struct V_39 * V_39 , const char T_3 * V_40 ,
T_4 V_41 , T_5 * V_42 )
{
struct V_1 * V_2 = V_39 -> V_43 ;
struct V_14 * V_8 = V_2 -> V_6 ;
struct V_15 * V_16 = V_15 ( V_8 ) ;
struct V_17 * V_18 = & V_16 -> V_18 ;
struct V_44 args = { . V_31 = - V_45 } ;
char V_46 [ 32 ] = {} , * V_47 , * V_48 = V_46 ;
long V_49 , V_21 ;
if ( ! V_16 )
return - V_22 ;
if ( V_41 >= sizeof( V_46 ) )
return - V_45 ;
if ( F_6 ( V_46 , V_40 , V_41 ) )
return - V_50 ;
if ( ( V_47 = strchr ( V_46 , '\n' ) ) )
* V_47 = '\0' ;
if ( ! strncasecmp ( V_48 , L_14 , 3 ) ) {
args . V_31 = 0 ;
V_48 += 3 ;
} else
if ( ! strncasecmp ( V_48 , L_15 , 3 ) ) {
args . V_31 = 1 ;
V_48 += 3 ;
}
if ( ! strcasecmp ( V_48 , L_16 ) )
args . V_51 = V_52 ;
else
if ( ! strcasecmp ( V_48 , L_17 ) )
args . V_51 = V_53 ;
else {
V_21 = F_7 ( V_48 , 16 , & V_49 ) ;
if ( V_21 )
return V_21 ;
args . V_51 = V_49 ;
}
V_21 = F_4 ( V_18 , V_54 , & args , sizeof( args ) ) ;
if ( V_21 < 0 )
return V_21 ;
return V_41 ;
}
static int
F_8 ( struct V_55 * V_55 , struct V_39 * V_39 )
{
return F_9 ( V_39 , F_3 , V_55 -> V_56 ) ;
}
int
F_10 ( struct V_57 * V_9 )
{
struct V_58 * V_58 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < F_11 ( V_59 ) ; V_11 ++ ) {
V_58 = F_12 ( V_59 [ V_11 ] . V_32 ,
V_60 | V_61 ,
V_9 -> V_62 , V_9 -> V_10 ,
V_59 [ V_11 ] . V_63 ) ;
if ( ! V_58 )
return - V_64 ;
}
return F_13 ( V_65 ,
V_66 ,
V_9 -> V_62 , V_9 ) ;
}
int
F_14 ( struct V_7 * V_8 )
{
int V_21 ;
V_8 -> V_16 = F_15 ( sizeof( * V_8 -> V_16 ) , V_67 ) ;
if ( ! V_8 -> V_16 )
return - V_64 ;
V_21 = F_16 ( & V_8 -> V_68 . V_69 . V_70 , 0 ,
V_71 , NULL , 0 ,
& V_8 -> V_16 -> V_18 ) ;
if ( V_21 )
return V_21 ;
return 0 ;
}
void
F_17 ( struct V_7 * V_8 )
{
if ( V_8 -> V_16 && V_8 -> V_16 -> V_18 . V_72 )
F_18 ( & V_8 -> V_16 -> V_18 ) ;
F_19 ( V_8 -> V_16 ) ;
V_8 -> V_16 = NULL ;
}
