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
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 ) {
F_3 ( V_3 -> V_18 , L_1 ) ;
return - V_19 ;
}
if ( ! F_4 ( V_15 ) )
return 0 ;
F_5 ( V_8 , V_20 ,
0 , V_21 ) ;
return 0 ;
}
static int F_6 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
struct V_6 * V_7 = V_23 -> V_26 ;
struct V_1 * V_8 = V_7 -> V_8 ;
int V_27 ;
V_27 = F_7 ( V_8 , 0 , V_28 ,
V_29 , F_8 ( V_25 ) * 512 ) ;
if ( V_27 < 0 ) {
F_3 ( V_7 -> V_18 , L_2 , V_27 ) ;
return V_27 ;
}
V_27 = F_5 ( V_8 , V_30 ,
F_8 ( V_25 ) * 512 ,
V_21 ) ;
if ( V_27 < 0 ) {
F_3 ( V_7 -> V_18 , L_3 , V_27 ) ;
return V_27 ;
}
return 0 ;
}
static int F_9 ( struct V_6 * V_31 )
{
int V_27 ;
struct V_1 * V_8 = V_31 -> V_8 ;
struct V_32 * V_33 = V_8 -> V_33 ;
V_27 = F_10 ( V_8 , 0xF , 0xF , 4 , 24 ) ;
if ( V_27 < 0 ) {
F_3 ( V_31 -> V_18 , L_4 , V_27 ) ;
return V_27 ;
}
F_11 ( V_33 ,
V_34
| V_35
| V_36
| V_37
| V_38
| V_39 ,
V_40 ) ;
return 0 ;
}
static int F_12 ( struct V_6 * V_7 ,
struct V_24 * V_25 )
{
struct V_41 * V_42 = F_13 ( V_25 ,
V_43 ) ;
struct V_41 * V_44 = F_13 ( V_25 ,
V_45 ) ;
V_42 -> V_46 = V_42 -> V_47 = 48000 ;
V_44 -> V_46 = V_44 -> V_47 = 2 ;
F_14 ( & V_25 -> V_48 [ V_49 -
V_50 ] ,
V_51 ) ;
return 0 ;
}
static int F_15 ( struct V_22 * V_23 )
{
return F_16 ( V_23 -> V_31 , 0 ,
V_43 ,
& V_52 ) ;
}
static int F_17 ( struct V_53 * V_54 )
{
int V_55 = 0 ;
V_56 . V_18 = & V_54 -> V_18 ;
V_55 = F_18 ( & V_54 -> V_18 , & V_56 ) ;
if ( V_55 ) {
F_3 ( & V_54 -> V_18 ,
L_5 , V_55 ) ;
return V_55 ;
}
F_19 ( V_54 , & V_56 ) ;
return V_55 ;
}
