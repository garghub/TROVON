static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 -> V_5 ; V_4 ++ ) {
struct V_6 * V_7 ;
V_7 = V_3 -> V_7 + V_4 ;
if ( ! strncmp ( V_7 -> V_8 -> V_9 , V_10 ,
strlen ( V_10 ) ) )
return V_7 -> V_8 ;
}
return NULL ;
}
static int F_2 ( struct V_11 * V_12 ,
struct V_13 * V_14 , int V_15 )
{
struct V_16 * V_17 = V_12 -> V_17 ;
struct V_2 * V_3 = V_17 -> V_3 ;
struct V_1 * V_8 ;
int V_18 ;
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 ) {
F_3 ( V_3 -> V_19 , L_1 ) ;
return - V_20 ;
}
if ( ! F_4 ( V_15 ) )
return 0 ;
V_18 = F_5 ( V_8 , V_21 ,
0 , V_22 ) ;
if ( V_18 < 0 ) {
F_3 ( V_3 -> V_19 , L_2 , V_18 ) ;
return V_18 ;
}
return 0 ;
}
static int F_6 ( struct V_23 * V_24 ,
struct V_25 * V_26 )
{
struct V_6 * V_7 = V_24 -> V_27 ;
struct V_1 * V_8 = V_7 -> V_8 ;
int V_18 ;
V_18 = F_7 ( V_8 , 0 , V_28 ,
V_29 , F_8 ( V_26 ) * 512 ) ;
if ( V_18 < 0 ) {
F_3 ( V_7 -> V_19 , L_3 , V_18 ) ;
return V_18 ;
}
V_18 = F_5 ( V_8 , V_30 ,
F_8 ( V_26 ) * 512 , V_22 ) ;
if ( V_18 < 0 ) {
F_3 ( V_7 -> V_19 , L_2 , V_18 ) ;
return V_18 ;
}
return 0 ;
}
static int F_9 ( struct V_6 * V_31 )
{
int V_18 ;
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_1 * V_8 = V_31 -> V_8 ;
struct V_34 * V_35 = F_10 ( V_31 -> V_3 ) ;
F_11 ( V_33 ,
V_36 |
V_37 |
V_38 |
V_39 ,
V_40 ) ;
V_18 = F_12 ( V_8 , 0xF , 0xF , 4 , 24 ) ;
if ( V_18 < 0 ) {
F_3 ( V_31 -> V_19 , L_4 , V_18 ) ;
return V_18 ;
}
V_18 = F_13 ( V_31 -> V_3 , L_5 ,
V_41 , & V_35 -> V_42 ,
NULL , 0 ) ;
if ( V_18 ) {
F_3 ( V_31 -> V_19 , L_6 , V_18 ) ;
return V_18 ;
}
V_18 = F_13 ( V_31 -> V_3 , L_7 ,
V_43 , & V_35 -> V_44 ,
NULL , 0 ) ;
if ( V_18 ) {
F_3 ( V_31 -> V_19 , L_8 , V_18 ) ;
return V_18 ;
}
F_14 ( V_33 , & V_35 -> V_42 , & V_35 -> V_44 ) ;
return V_18 ;
}
static int F_15 ( struct V_6 * V_7 ,
struct V_25 * V_26 )
{
struct V_45 * V_46 = F_16 ( V_26 ,
V_47 ) ;
struct V_45 * V_48 = F_16 ( V_26 ,
V_49 ) ;
V_46 -> V_50 = V_46 -> V_51 = 48000 ;
V_48 -> V_50 = V_48 -> V_51 = 2 ;
F_17 ( V_26 , V_52 ) ;
return 0 ;
}
static int F_18 ( struct V_23 * V_24 )
{
return F_19 ( V_24 -> V_31 , 0 ,
V_47 ,
& V_53 ) ;
}
static int F_20 ( struct V_54 * V_55 )
{
int V_56 = 0 ;
struct V_34 * V_57 ;
V_57 = F_21 ( & V_55 -> V_19 , sizeof( * V_57 ) , V_58 ) ;
if ( ! V_57 )
return - V_59 ;
V_60 . V_19 = & V_55 -> V_19 ;
F_22 ( & V_60 , V_57 ) ;
V_56 = F_23 ( & V_55 -> V_19 , & V_60 ) ;
if ( V_56 ) {
F_3 ( & V_55 -> V_19 ,
L_9 , V_56 ) ;
return V_56 ;
}
F_24 ( V_55 , & V_60 ) ;
return V_56 ;
}
