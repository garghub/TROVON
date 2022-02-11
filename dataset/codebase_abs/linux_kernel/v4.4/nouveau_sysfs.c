static inline struct V_1 *
V_1 ( struct V_2 * V_3 )
{
return F_1 ( V_3 ) ;
}
static T_1
F_2 ( struct V_2 * V_3 , struct V_4 * V_5 , char * V_6 )
{
struct V_7 * V_8 = V_7 ( V_1 ( V_3 ) ) ;
struct V_9 V_10 = {} ;
T_2 V_11 = V_12 ;
char * V_13 = V_6 ;
int V_14 , V_15 ;
V_14 = F_3 ( & V_8 -> V_16 , V_17 ,
& V_10 , sizeof( V_10 ) ) ;
if ( V_14 )
return V_14 ;
for ( V_15 = 0 ; V_15 < V_10 . V_18 + 1 ; V_15 ++ ) {
const T_3 V_19 = V_15 < V_10 . V_18 ? V_15 :
V_20 ;
struct V_21 V_22 = {
. V_19 = V_19 ,
. V_23 = 0 ,
} ;
V_14 = F_3 ( & V_8 -> V_16 , V_24 ,
& V_22 , sizeof( V_22 ) ) ;
if ( V_14 )
return V_14 ;
if ( V_15 < V_10 . V_18 )
F_4 ( V_13 , V_11 , L_1 , V_22 . V_19 ) ;
else
F_4 ( V_13 , V_11 , L_2 , V_10 . V_25 == 0 ? L_3 :
V_10 . V_25 == 1 ? L_4 :
L_5 ) ;
V_22 . V_23 = 0 ;
do {
V_22 . V_19 = V_19 ;
V_14 = F_3 ( & V_8 -> V_16 ,
V_24 ,
& V_22 , sizeof( V_22 ) ) ;
if ( V_14 )
return V_14 ;
F_4 ( V_13 , V_11 , L_6 , V_22 . V_26 , V_22 . V_27 ) ;
if ( V_22 . V_27 != V_22 . V_28 )
F_4 ( V_13 , V_11 , L_7 , V_22 . V_28 ) ;
F_4 ( V_13 , V_11 , L_8 , V_22 . V_29 ) ;
} while ( V_22 . V_23 );
if ( V_19 >= 0 ) {
if ( V_10 . V_30 == V_19 )
F_4 ( V_13 , V_11 , L_9 ) ;
if ( V_10 . V_31 == V_19 )
F_4 ( V_13 , V_11 , L_10 ) ;
if ( V_10 . V_32 == V_19 )
F_4 ( V_13 , V_11 , L_11 ) ;
} else {
if ( V_10 . V_30 < - 1 )
F_4 ( V_13 , V_11 , L_9 ) ;
if ( V_10 . V_31 < - 1 )
F_4 ( V_13 , V_11 , L_10 ) ;
}
F_4 ( V_13 , V_11 , L_12 ) ;
}
return strlen ( V_6 ) ;
}
static T_1
F_5 ( struct V_2 * V_3 , struct V_4 * V_5 ,
const char * V_13 , T_2 V_18 )
{
struct V_7 * V_8 = V_7 ( V_1 ( V_3 ) ) ;
struct V_33 args = { . V_25 = - V_34 } ;
long V_35 , V_14 ;
char * V_36 ;
if ( ( V_36 = strchr ( V_13 , '\n' ) ) )
* V_36 = '\0' ;
if ( ! strncasecmp ( V_13 , L_13 , 3 ) ) {
args . V_25 = 0 ;
V_13 += 3 ;
} else
if ( ! strncasecmp ( V_13 , L_14 , 3 ) ) {
args . V_25 = 1 ;
V_13 += 3 ;
}
if ( ! strcasecmp ( V_13 , L_15 ) )
args . V_37 = V_38 ;
else
if ( ! strcasecmp ( V_13 , L_16 ) )
args . V_37 = V_39 ;
else {
V_14 = F_6 ( V_13 , 16 , & V_35 ) ;
if ( V_14 )
return V_14 ;
args . V_37 = V_35 ;
}
V_14 = F_3 ( & V_8 -> V_16 , V_40 ,
& args , sizeof( args ) ) ;
if ( V_14 < 0 )
return V_14 ;
return V_18 ;
}
void
F_7 ( struct V_1 * V_41 )
{
struct V_7 * V_8 = V_7 ( V_41 ) ;
struct V_42 * V_43 = V_42 ( V_41 ) ;
struct V_44 * V_2 = & V_43 -> V_2 ;
if ( V_8 && V_8 -> V_16 . V_45 ) {
F_8 ( F_9 ( V_2 ) -> V_41 , & V_46 ) ;
F_10 ( & V_8 -> V_16 ) ;
}
V_43 -> V_8 = NULL ;
F_11 ( V_8 ) ;
}
int
F_12 ( struct V_1 * V_41 )
{
struct V_42 * V_43 = V_42 ( V_41 ) ;
struct V_44 * V_2 = & V_43 -> V_2 ;
struct V_7 * V_8 ;
int V_14 ;
if ( ! V_47 )
return 0 ;
V_8 = V_43 -> V_8 = F_13 ( sizeof( * V_8 ) , V_48 ) ;
if ( ! V_8 )
return - V_49 ;
V_14 = F_14 ( & V_2 -> V_50 , 0 , V_51 ,
NULL , 0 , & V_8 -> V_16 ) ;
if ( V_14 == 0 )
F_15 ( F_9 ( V_2 ) -> V_41 , & V_46 ) ;
return 0 ;
}
