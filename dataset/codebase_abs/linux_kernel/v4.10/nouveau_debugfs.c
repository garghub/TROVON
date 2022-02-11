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
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_14 * V_15 = V_14 ( V_5 -> V_9 -> V_10 ) ;
struct V_16 * V_17 = & V_15 -> V_17 ;
struct V_18 V_19 = {} ;
int V_20 , V_11 ;
if ( ! V_15 )
return - V_21 ;
V_20 = F_4 ( V_17 , V_22 , & V_19 , sizeof( V_19 ) ) ;
if ( V_20 )
return V_20 ;
for ( V_11 = 0 ; V_11 < V_19 . V_23 + 1 ; V_11 ++ ) {
const T_1 V_24 = V_11 < V_19 . V_23 ? V_11 :
V_25 ;
struct V_26 V_27 = {
. V_24 = V_24 ,
. V_28 = 0 ,
} ;
V_20 = F_4 ( V_17 , V_29 ,
& V_27 , sizeof( V_27 ) ) ;
if ( V_20 )
return V_20 ;
if ( V_11 < V_19 . V_23 )
F_2 ( V_2 , L_2 , V_27 . V_24 ) ;
else
F_2 ( V_2 , L_3 , V_19 . V_30 == 0 ? L_4 :
V_19 . V_30 == 1 ? L_5 : L_6 ) ;
V_27 . V_28 = 0 ;
do {
V_27 . V_24 = V_24 ;
V_20 = F_4 ( V_17 , V_29 ,
& V_27 , sizeof( V_27 ) ) ;
if ( V_20 )
return V_20 ;
F_2 ( V_2 , L_7 , V_27 . V_31 , V_27 . V_32 ) ;
if ( V_27 . V_32 != V_27 . V_33 )
F_2 ( V_2 , L_8 , V_27 . V_33 ) ;
F_2 ( V_2 , L_9 , V_27 . V_34 ) ;
} while ( V_27 . V_28 );
if ( V_24 >= 0 ) {
if ( V_19 . V_35 == V_24 )
F_2 ( V_2 , L_10 ) ;
if ( V_19 . V_36 == V_24 )
F_2 ( V_2 , L_11 ) ;
if ( V_19 . V_37 == V_24 )
F_2 ( V_2 , L_12 ) ;
} else {
if ( V_19 . V_35 < - 1 )
F_2 ( V_2 , L_10 ) ;
if ( V_19 . V_36 < - 1 )
F_2 ( V_2 , L_11 ) ;
}
F_2 ( V_2 , L_13 ) ;
}
return 0 ;
}
static T_2
F_5 ( struct V_38 * V_38 , const char T_3 * V_39 ,
T_4 V_40 , T_5 * V_41 )
{
struct V_1 * V_2 = V_38 -> V_42 ;
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_14 * V_15 = V_14 ( V_5 -> V_9 -> V_10 ) ;
struct V_16 * V_17 = & V_15 -> V_17 ;
struct V_43 args = { . V_30 = - V_44 } ;
char V_45 [ 32 ] = {} , * V_46 , * V_47 = V_45 ;
long V_48 , V_20 ;
if ( ! V_15 )
return - V_21 ;
if ( V_40 >= sizeof( V_45 ) )
return - V_44 ;
if ( F_6 ( V_45 , V_39 , V_40 ) )
return - V_49 ;
if ( ( V_46 = strchr ( V_45 , '\n' ) ) )
* V_46 = '\0' ;
if ( ! strncasecmp ( V_47 , L_14 , 3 ) ) {
args . V_30 = 0 ;
V_47 += 3 ;
} else
if ( ! strncasecmp ( V_47 , L_15 , 3 ) ) {
args . V_30 = 1 ;
V_47 += 3 ;
}
if ( ! strcasecmp ( V_47 , L_16 ) )
args . V_50 = V_51 ;
else
if ( ! strcasecmp ( V_47 , L_17 ) )
args . V_50 = V_52 ;
else {
V_20 = F_7 ( V_47 , 16 , & V_48 ) ;
if ( V_20 )
return V_20 ;
args . V_50 = V_48 ;
}
V_20 = F_4 ( V_17 , V_53 , & args , sizeof( args ) ) ;
if ( V_20 < 0 )
return V_20 ;
return V_40 ;
}
static int
F_8 ( struct V_54 * V_54 , struct V_38 * V_38 )
{
return F_9 ( V_38 , F_3 , V_54 -> V_55 ) ;
}
static int
F_10 ( struct V_56 * V_9 ,
const struct V_57 * V_58 )
{
struct V_4 * V_5 ;
V_5 = F_11 ( sizeof( * V_5 ) , V_59 ) ;
if ( V_5 == NULL )
return - V_60 ;
V_5 -> V_9 = V_9 ;
V_5 -> V_61 = ( const void * ) V_58 -> V_62 ;
V_5 -> V_63 = F_12 ( V_58 -> V_31 , V_64 | V_65 ,
V_9 -> V_66 , V_5 , V_58 -> V_62 ) ;
if ( ! V_5 -> V_63 ) {
F_13 ( V_5 ) ;
return - V_60 ;
}
F_14 ( & V_9 -> V_67 ) ;
F_15 ( & V_5 -> V_68 , & V_9 -> V_69 ) ;
F_16 ( & V_9 -> V_67 ) ;
return 0 ;
}
int
F_17 ( struct V_56 * V_9 )
{
int V_11 , V_20 ;
for ( V_11 = 0 ; V_11 < F_18 ( V_57 ) ; V_11 ++ ) {
V_20 = F_10 ( V_9 ,
& V_57 [ V_11 ] ) ;
if ( V_20 )
return V_20 ;
}
return F_19 ( V_70 ,
V_71 ,
V_9 -> V_66 , V_9 ) ;
}
void
F_20 ( struct V_56 * V_9 )
{
int V_11 ;
F_21 ( V_70 , V_71 ,
V_9 ) ;
for ( V_11 = 0 ; V_11 < F_18 ( V_57 ) ; V_11 ++ ) {
F_21 ( (struct V_72 * )
V_57 [ V_11 ] . V_62 ,
1 , V_9 ) ;
}
}
int
F_22 ( struct V_7 * V_8 )
{
int V_20 ;
V_8 -> V_15 = F_23 ( sizeof( * V_8 -> V_15 ) , V_59 ) ;
if ( ! V_8 -> V_15 )
return - V_60 ;
V_20 = F_24 ( & V_8 -> V_73 . V_74 , 0 , V_75 ,
NULL , 0 , & V_8 -> V_15 -> V_17 ) ;
if ( V_20 )
return V_20 ;
return 0 ;
}
void
F_25 ( struct V_7 * V_8 )
{
if ( V_8 -> V_15 && V_8 -> V_15 -> V_17 . V_76 )
F_26 ( & V_8 -> V_15 -> V_17 ) ;
F_13 ( V_8 -> V_15 ) ;
V_8 -> V_15 = NULL ;
}
