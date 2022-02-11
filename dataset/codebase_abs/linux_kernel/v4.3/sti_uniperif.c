static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 . V_6 ;
struct V_8 * V_9 ;
int V_10 ;
if ( ! V_6 -> V_11 )
return 0 ;
for ( V_10 = 0 ; V_10 < V_6 -> V_11 ; V_10 ++ ) {
V_9 = & V_6 -> V_12 [ V_10 ] ;
V_9 -> V_13 = V_6 -> V_14 -> V_15 ;
V_9 -> V_16 = V_6 -> V_14 -> V_15 ;
}
return F_3 ( V_2 , V_6 -> V_12 , V_6 -> V_11 ) ;
}
int F_4 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
struct V_1 * V_2 )
{
struct V_21 * V_22 ;
int V_23 ;
V_23 = F_5 ( V_20 ) * V_24 ;
V_22 = F_6 ( V_2 , V_18 ) ;
V_22 -> V_25 = V_23 ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 , unsigned int V_26 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_7 . V_6 -> V_27 = V_26 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 . V_6 ;
int V_28 ;
if ( V_6 -> V_29 != V_30 ) {
F_9 ( V_6 -> V_31 , L_1 ,
V_32 , ( int ) V_6 -> V_29 ) ;
return - V_33 ;
}
V_28 = F_10 ( V_6 -> V_31 ) ;
if ( V_28 )
F_9 ( V_6 -> V_31 , L_2 ,
V_32 ) ;
return V_28 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 . V_6 ;
int V_28 ;
if ( F_12 ( V_2 -> V_31 -> V_34 , L_3 ) ) {
V_28 = F_13 ( V_6 ) ;
if ( V_28 )
return V_28 ;
}
V_28 = F_14 ( V_6 -> V_31 ) ;
if ( V_28 )
F_9 ( V_6 -> V_31 , L_2 ,
V_32 ) ;
return V_28 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_35 * V_7 = & V_4 -> V_7 ;
if ( F_12 ( V_2 -> V_31 -> V_34 , L_3 ) )
F_16 ( V_2 , & V_7 -> V_22 , NULL ) ;
else
F_16 ( V_2 , NULL , & V_7 -> V_22 ) ;
V_7 -> V_22 . V_36 = V_7 -> V_6 -> V_37 ;
V_7 -> V_22 . V_38 = V_39 ;
return F_1 ( V_2 ) ;
}
static int F_17 ( struct V_40 * V_41 ,
struct V_3 * V_4 )
{
const char * V_42 ;
int V_28 ;
struct V_16 * V_31 = & V_4 -> V_43 -> V_31 ;
struct V_35 * V_7 = & V_4 -> V_7 ;
struct V_44 * V_2 = V_4 -> V_2 ;
struct V_45 * V_46 ;
struct V_5 * V_6 ;
V_6 = F_18 ( V_31 , sizeof( * V_6 ) , V_47 ) ;
if ( ! V_6 )
return - V_48 ;
* V_2 = V_49 ;
V_28 = F_19 ( V_41 , L_4 , & V_42 ) ;
if ( V_28 < 0 ) {
F_9 ( V_31 , L_5 , V_32 ) ;
return - V_50 ;
}
V_2 -> V_51 = V_42 ;
V_6 -> V_52 = F_20 ( V_4 -> V_43 , V_53 , 0 ) ;
if ( ! V_6 -> V_52 ) {
F_9 ( V_31 , L_6 ) ;
return - V_54 ;
}
V_6 -> V_55 = F_21 ( V_31 , V_6 -> V_52 ) ;
if ( F_22 ( V_6 -> V_55 ) )
return F_23 ( V_6 -> V_55 ) ;
V_6 -> V_37 = V_6 -> V_52 -> V_56 +
F_24 ( V_6 ) ;
V_6 -> V_57 = F_25 ( V_4 -> V_43 , 0 ) ;
if ( V_6 -> V_57 < 0 ) {
F_9 ( V_31 , L_7 ) ;
return - V_58 ;
}
V_7 -> V_6 = V_6 ;
if ( F_12 ( V_41 , L_3 ) ) {
F_26 ( V_4 -> V_43 , V_6 ) ;
V_46 = & V_2 -> V_59 ;
} else {
F_27 ( V_4 -> V_43 , V_6 ) ;
V_46 = & V_2 -> V_60 ;
}
V_2 -> V_61 = V_6 -> V_62 ;
V_46 -> V_63 = V_2 -> V_51 ;
V_46 -> V_64 = V_6 -> V_65 -> V_64 ;
V_46 -> V_66 = V_6 -> V_65 -> V_66 ;
V_46 -> V_67 = V_6 -> V_65 -> V_67 ;
V_46 -> V_68 = V_6 -> V_65 -> V_68 ;
return 0 ;
}
static int F_28 ( struct V_69 * V_43 )
{
struct V_3 * V_4 ;
struct V_40 * V_41 = V_43 -> V_31 . V_34 ;
int V_28 ;
V_4 = F_18 ( & V_43 -> V_31 , sizeof( * V_4 ) , V_47 ) ;
if ( ! V_4 )
return - V_48 ;
V_4 -> V_2 = F_18 ( & V_43 -> V_31 , sizeof( * V_4 -> V_2 ) , V_47 ) ;
if ( ! V_4 -> V_2 )
return - V_48 ;
V_4 -> V_43 = V_43 ;
V_28 = F_17 ( V_41 , V_4 ) ;
F_29 ( & V_43 -> V_31 , V_4 ) ;
V_28 = F_30 ( & V_43 -> V_31 ,
& V_70 ,
V_4 -> V_2 , 1 ) ;
if ( V_28 < 0 )
return V_28 ;
return F_31 ( & V_43 -> V_31 ,
& V_71 , 0 ) ;
}
