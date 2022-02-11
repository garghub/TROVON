static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_5 = F_3 ( V_7 -> V_8 , V_3 , V_4 ) ;
if ( V_5 )
F_4 ( & V_2 -> V_9 , L_1 ,
V_10 , V_3 , V_4 , V_5 ) ;
return V_5 ;
}
static void F_5 ( struct V_6 * V_7 ,
enum V_11 V_12 , bool V_13 )
{
int V_5 , V_4 ;
F_6 ( & V_7 -> V_2 -> V_9 , L_2 , V_10 , V_12 , V_13 ) ;
V_4 = 1 << V_12 ;
if ( V_12 == V_14 )
V_4 = V_15 ;
V_5 = F_7 ( V_7 -> V_8 , V_16 , V_4 ,
V_13 ? V_4 : 0 ) ;
if ( V_5 )
F_4 ( & V_7 -> V_2 -> V_9 , L_3 , V_10 , V_5 ) ;
}
static int F_8 ( struct V_17 * V_18 ,
enum V_19 V_20 )
{
unsigned int V_3 , V_21 ;
struct V_22 * V_23 = F_9 ( V_18 ,
struct V_22 ,
V_18 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_23 -> V_7 ;
F_6 ( V_18 -> V_9 , L_4 , V_20 ,
V_23 -> V_24 ) ;
if ( V_20 == V_25 ) {
F_5 ( V_7 , V_23 -> V_24 , false ) ;
return 0 ;
}
if ( V_23 -> V_24 > V_26 ) {
F_4 ( V_18 -> V_9 , L_5 , V_10 ) ;
return - V_27 ;
}
if ( V_23 -> V_24 >= V_28 ) {
V_3 = V_29 ;
V_21 = ( V_23 -> V_24 - V_28 ) * 2 ;
} else {
V_3 = V_30 ;
V_21 = V_23 -> V_24 * 2 ;
}
F_5 ( V_7 , V_23 -> V_24 , true ) ;
return F_7 ( V_7 -> V_8 , V_3 , 3 << V_21 ,
-- V_20 << V_21 ) ;
}
static int F_10 ( struct V_31 * V_9 , const char * V_32 , char * V_33 )
{
int V_5 ;
const char * V_34 ;
V_5 = F_11 ( V_9 , V_32 , & V_34 ) ;
if ( V_5 )
return V_5 ;
strncpy ( V_33 , V_34 , V_35 ) ;
return 0 ;
}
static int F_12 ( struct V_6 * V_7 )
{
int V_36 , V_37 , V_5 = - V_38 ;
static const char * V_39 [ V_14 ] = {
L_6 ,
L_7 ,
L_8 ,
L_9 ,
L_10 ,
L_11
} ;
for ( V_36 = 0 ; V_36 < V_14 ; V_36 ++ ) {
V_37 = F_10 ( & V_7 -> V_2 -> V_9 , V_39 [ V_36 ] ,
V_7 -> V_40 [ V_36 ] . V_41 ) ;
if ( V_37 )
continue;
V_7 -> V_40 [ V_36 ] . V_18 . V_41 = V_7 -> V_40 [ V_36 ] . V_41 ;
V_7 -> V_40 [ V_36 ] . V_18 . V_42 = V_25 ;
V_7 -> V_40 [ V_36 ] . V_18 . V_43 = V_44 ;
V_7 -> V_40 [ V_36 ] . V_18 . V_45 =
F_8 ;
V_7 -> V_40 [ V_36 ] . V_24 = V_36 ;
V_7 -> V_40 [ V_36 ] . V_7 = V_7 ;
V_5 = F_13 ( & V_7 -> V_2 -> V_9 ,
& V_7 -> V_40 [ V_36 ] . V_18 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_7 -> V_2 -> V_9 ,
L_12 ,
V_7 -> V_40 [ V_36 ] . V_18 . V_41 ) ;
break;
}
}
return V_5 ;
}
static int F_14 ( struct V_6 * V_7 ,
T_1 V_46 , T_1 V_47 , T_1 V_48 , T_1 V_49 ,
enum V_50 V_51 , enum V_52 V_53 )
{
int V_5 ;
struct V_54 line = {
{
{
. V_47 = V_47 ,
. V_48 = V_48 ,
. V_49 = V_49 ,
. V_53 = V_53 ,
. V_51 = V_51
}
}
} ;
if ( V_46 >= V_55 )
return - V_27 ;
V_5 = F_1 ( V_7 -> V_2 ,
V_56 + V_46 * 2 ,
line . V_57 . V_58 ) ;
if ( V_5 )
return V_5 ;
return F_1 ( V_7 -> V_2 ,
V_56 + V_46 * 2 + 1 ,
line . V_57 . V_59 ) ;
}
static int F_15 ( struct V_6 * V_7 )
{
int V_5 ;
V_5 = F_1 ( V_7 -> V_2 , V_16 , 0 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_1 ( V_7 -> V_2 , V_60 ,
V_61 | V_62 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_1 ( V_7 -> V_2 , V_63 ,
V_64 | V_65 ) ;
if ( V_5 )
return V_5 ;
return F_14 ( V_7 , 0 , V_66 , V_67 , V_68 , V_69 ,
V_70 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
const struct V_71 * V_72 )
{
int V_73 ;
struct V_6 * V_7 ;
V_7 = F_17 ( & V_2 -> V_9 , sizeof( * V_7 ) , V_74 ) ;
if ( ! V_7 )
return - V_75 ;
V_7 -> V_2 = V_2 ;
V_7 -> V_76 = F_18 ( & V_2 -> V_9 , L_13 ,
V_77 ) ;
if ( F_19 ( V_7 -> V_76 ) ) {
V_73 = F_20 ( V_7 -> V_76 ) ;
F_4 ( & V_2 -> V_9 , L_14 , V_73 ) ;
return V_73 ;
}
V_7 -> V_8 = F_21 ( V_2 , & V_78 ) ;
if ( F_19 ( V_7 -> V_8 ) ) {
int V_79 = F_20 ( V_7 -> V_8 ) ;
F_4 ( & V_2 -> V_9 , L_15 ,
V_79 ) ;
return V_79 ;
}
F_22 ( V_2 , V_7 ) ;
V_73 = F_15 ( V_7 ) ;
if ( V_73 ) {
F_4 ( & V_2 -> V_9 , L_16 ,
V_73 ) ;
return V_73 ;
}
V_73 = F_12 ( V_7 ) ;
if ( V_73 ) {
F_4 ( & V_2 -> V_9 , L_17 ,
V_73 ) ;
return V_73 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
F_5 ( V_7 , V_14 , false ) ;
F_24 ( V_7 -> V_76 , 0 ) ;
return 0 ;
}
