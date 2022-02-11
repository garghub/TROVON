static int F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 ;
if ( V_2 -> V_5 . V_6 <= 1 )
return 0 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_6 ; V_4 ++ )
if ( V_2 -> V_5 . V_7 [ V_4 ] . V_8 & V_3 )
return V_4 ;
return - V_9 ;
}
static bool F_2 ( struct V_10 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_11 ;
struct V_12 V_13 = {
. V_14 = V_15 ,
} ;
V_13 . V_16 = 0 ;
V_13 . V_4 = V_5 -> V_17 ;
while ( ! F_3 ( V_2 , V_4 , V_18 , NULL , & V_13 ) ) {
V_13 . V_16 ++ ;
switch ( V_13 . V_13 ) {
case V_19 :
case V_20 :
case V_21 :
case V_22 :
V_5 -> V_13 = V_13 . V_13 ;
return true ;
default:
break;
}
}
return false ;
}
static int F_4 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = F_5 ( V_24 ) ;
int V_27 ;
if ( ! F_2 ( & V_26 -> V_28 ) ) {
F_6 ( V_26 , L_1 ,
V_26 -> V_28 . V_11 -> V_29 ) ;
return - V_9 ;
}
F_7 ( V_26 , L_2 ,
V_26 -> V_28 . V_11 -> V_29 , V_26 -> V_28 . V_13 ) ;
V_27 = F_8 ( & V_26 -> V_30 ) ;
if ( V_27 < 0 ) {
F_6 ( V_26 , L_3 ) ;
return V_27 ;
}
return F_9 ( V_26 ) ;
}
static void F_10 ( struct V_23 * V_24 ,
struct V_1 * V_11 ,
struct V_31 * V_32 )
{
struct V_25 * V_26 = F_5 ( V_24 ) ;
F_7 ( V_26 , L_4 , V_11 -> V_29 ) ;
F_11 ( V_26 ) ;
V_26 -> V_28 . V_11 = NULL ;
}
static int F_12 ( struct V_23 * V_24 ,
struct V_1 * V_11 ,
struct V_31 * V_32 )
{
struct V_25 * V_26 = F_5 ( V_24 ) ;
int V_27 ;
F_13 ( V_11 , V_26 ) ;
V_27 = F_1 ( V_11 , V_33 ) ;
if ( V_27 < 0 )
return V_27 ;
V_26 -> V_28 . V_17 = V_27 ;
V_27 = F_1 ( V_11 , V_34 ) ;
V_26 -> V_28 . V_35 = V_27 < 0 ? 0 : V_27 ;
V_26 -> V_28 . V_11 = V_11 ;
F_7 ( V_26 , L_5 ,
V_11 -> V_29 , V_26 -> V_28 . V_17 ,
V_26 -> V_28 . V_35 ) ;
return 0 ;
}
static int F_14 ( struct V_25 * V_26 ,
struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_40 V_41 ;
int V_27 ;
V_27 = F_15 ( F_16 ( V_37 ) , & V_41 ) ;
if ( V_27 ) {
F_6 ( V_26 , L_6 ) ;
return - V_9 ;
}
V_39 -> type = V_41 . V_42 ;
switch ( V_39 -> type ) {
case V_43 :
F_7 ( V_26 , L_7 ) ;
V_39 -> V_8 = V_41 . V_44 . V_45 . V_8 ;
break;
case V_46 :
F_7 ( V_26 , L_8 ) ;
V_39 -> V_8 = 0 ;
break;
default:
F_6 ( V_26 , L_9 ) ;
return - V_9 ;
}
return 0 ;
}
static int F_17 ( struct V_25 * V_26 )
{
struct V_36 * V_37 , * V_47 ;
int V_27 ;
V_26 -> V_28 . V_32 . V_48 . V_49 . V_49 = NULL ;
V_26 -> V_28 . V_11 = NULL ;
V_37 = F_18 ( V_26 -> V_50 -> V_51 , 0 , 0 ) ;
if ( ! V_37 )
return 0 ;
V_47 = F_19 ( V_37 ) ;
if ( ! V_47 ) {
F_6 ( V_26 , L_10 ) ;
F_20 ( V_37 ) ;
return - V_9 ;
}
F_20 ( V_47 ) ;
V_27 = F_14 ( V_26 , V_37 , & V_26 -> V_28 . V_39 ) ;
F_20 ( V_37 ) ;
if ( V_27 )
return V_27 ;
V_26 -> V_28 . V_32 . V_48 . V_49 . V_49 = F_16 ( V_47 ) ;
V_26 -> V_28 . V_32 . V_52 = V_53 ;
return 0 ;
}
static int F_21 ( struct V_25 * V_26 )
{
struct V_31 * * V_54 = NULL ;
int V_27 ;
V_27 = F_17 ( V_26 ) ;
if ( V_27 )
return V_27 ;
if ( ! V_26 -> V_28 . V_32 . V_48 . V_49 . V_49 ) {
F_7 ( V_26 , L_11 ) ;
return - V_55 ;
}
V_54 = F_22 ( V_26 -> V_50 , sizeof( * V_54 ) , V_56 ) ;
if ( V_54 == NULL )
return - V_57 ;
V_54 [ 0 ] = & V_26 -> V_28 . V_32 ;
F_7 ( V_26 , L_12 ,
F_23 ( V_54 [ 0 ] -> V_48 . V_49 . V_49 ) ) ;
V_26 -> V_24 . V_58 = 1 ;
V_26 -> V_24 . V_54 = V_54 ;
V_26 -> V_24 . V_59 = F_12 ;
V_26 -> V_24 . V_60 = F_10 ;
V_26 -> V_24 . V_61 = F_4 ;
V_27 = F_24 ( & V_26 -> V_30 , & V_26 -> V_24 ) ;
if ( V_27 < 0 ) {
F_6 ( V_26 , L_13 ) ;
return V_27 ;
}
return 0 ;
}
static int F_25 ( struct V_62 * V_63 )
{
const struct V_64 * V_48 ;
struct V_25 * V_26 ;
struct V_65 * V_66 ;
int V_67 , V_27 ;
V_26 = F_22 ( & V_63 -> V_50 , sizeof( * V_26 ) , V_56 ) ;
if ( ! V_26 )
return - V_57 ;
V_48 = F_26 ( F_27 ( V_68 ) , & V_63 -> V_50 ) ;
if ( ! V_48 )
return - V_55 ;
V_26 -> V_50 = & V_63 -> V_50 ;
V_26 -> V_69 = (enum V_70 ) V_48 -> V_71 ;
V_66 = F_28 ( V_63 , V_72 , 0 ) ;
if ( V_66 == NULL )
return - V_9 ;
V_26 -> V_73 = F_29 ( V_26 -> V_50 , V_66 ) ;
if ( F_30 ( V_26 -> V_73 ) )
return F_31 ( V_26 -> V_73 ) ;
V_67 = F_32 ( V_63 , 0 ) ;
if ( V_67 < 0 )
return V_67 ;
V_27 = F_33 ( V_26 , V_67 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_21 ( V_26 ) ;
if ( V_27 < 0 )
goto error;
F_34 ( & V_63 -> V_50 , true ) ;
F_35 ( & V_63 -> V_50 ) ;
F_36 ( V_63 , V_26 ) ;
return 0 ;
error:
F_37 ( V_26 ) ;
return V_27 ;
}
static int F_38 ( struct V_62 * V_63 )
{
struct V_25 * V_26 = F_39 ( V_63 ) ;
F_40 ( & V_63 -> V_50 ) ;
F_41 ( & V_26 -> V_24 ) ;
F_37 ( V_26 ) ;
return 0 ;
}
