static inline struct V_1 *
V_1 ( struct V_2 * V_3 )
{
return F_1 ( V_3 ) ;
}
static T_1
F_2 ( struct V_2 * V_3 , struct V_4 * V_5 , char * V_6 )
{
struct V_7 * V_8 = V_7 ( V_1 ( V_3 ) ) ;
struct V_9 V_10 ;
T_2 V_11 = V_12 ;
char * V_13 = V_6 ;
int V_14 , V_15 ;
V_14 = F_3 ( V_8 -> V_16 , V_17 , & V_10 , sizeof( V_10 ) ) ;
if ( V_14 )
return V_14 ;
for ( V_15 = 0 ; V_15 < V_10 . V_18 + 1 ; V_15 ++ ) {
const T_3 V_19 = V_15 < V_10 . V_18 ? V_15 :
V_20 ;
struct V_21 V_22 = {
. V_19 = V_19 ,
. V_23 = 0 ,
} ;
V_14 = F_3 ( V_8 -> V_16 , V_24 ,
& V_22 , sizeof( V_22 ) ) ;
if ( V_14 )
return V_14 ;
if ( V_15 < V_10 . V_18 )
F_4 ( V_13 , V_11 , L_1 , V_22 . V_19 ) ;
else
F_4 ( V_13 , V_11 , L_2 ) ;
V_22 . V_23 = 0 ;
do {
V_22 . V_19 = V_19 ;
V_14 = F_3 ( V_8 -> V_16 , V_24 ,
& V_22 , sizeof( V_22 ) ) ;
if ( V_14 )
return V_14 ;
F_4 ( V_13 , V_11 , L_3 , V_22 . V_25 , V_22 . V_26 ) ;
if ( V_22 . V_26 != V_22 . V_27 )
F_4 ( V_13 , V_11 , L_4 , V_22 . V_27 ) ;
F_4 ( V_13 , V_11 , L_5 , V_22 . V_28 ) ;
} while ( V_22 . V_23 );
if ( ( V_19 >= 0 && V_10 . V_29 == V_19 ) ||
( V_19 < 0 && V_10 . V_30 < 0 ) )
F_4 ( V_13 , V_11 , L_6 ) ;
F_4 ( V_13 , V_11 , L_7 ) ;
}
return strlen ( V_6 ) ;
}
static T_1
F_5 ( struct V_2 * V_3 , struct V_4 * V_5 ,
const char * V_13 , T_2 V_18 )
{
struct V_7 * V_8 = V_7 ( V_1 ( V_3 ) ) ;
struct V_31 args ;
long V_32 , V_14 ;
char * V_33 ;
if ( ( V_33 = strchr ( V_13 , '\n' ) ) )
* V_33 = '\0' ;
if ( ! strcasecmp ( V_13 , L_8 ) )
args . V_19 = V_34 ;
else
if ( ! strcasecmp ( V_13 , L_9 ) )
args . V_19 = V_35 ;
else {
V_14 = F_6 ( V_13 , 16 , & V_32 ) ;
if ( V_14 )
return V_14 ;
args . V_19 = V_32 ;
}
V_14 = F_3 ( V_8 -> V_16 , V_36 , & args , sizeof( args ) ) ;
if ( V_14 < 0 )
return V_14 ;
return V_18 ;
}
void
F_7 ( struct V_1 * V_37 )
{
struct V_7 * V_8 = V_7 ( V_37 ) ;
struct V_38 * V_39 = V_38 ( V_37 ) ;
struct V_40 * V_2 = F_8 ( V_39 -> V_2 ) ;
if ( V_8 -> V_16 ) {
F_9 ( F_10 ( V_2 ) , & V_41 ) ;
F_11 ( F_12 ( V_39 ) , V_42 , V_43 ) ;
}
V_39 -> V_8 = NULL ;
F_13 ( V_8 ) ;
}
int
F_14 ( struct V_1 * V_37 )
{
struct V_38 * V_39 = V_38 ( V_37 ) ;
struct V_40 * V_2 = F_8 ( V_39 -> V_2 ) ;
struct V_7 * V_8 ;
int V_14 ;
V_8 = V_39 -> V_8 = F_15 ( sizeof( * V_8 ) , V_44 ) ;
if ( ! V_8 )
return - V_45 ;
V_14 = F_16 ( F_12 ( V_39 ) , V_42 , V_43 ,
V_46 , NULL , 0 , & V_8 -> V_16 ) ;
if ( V_14 == 0 )
F_17 ( F_10 ( V_2 ) , & V_41 ) ;
return 0 ;
}
