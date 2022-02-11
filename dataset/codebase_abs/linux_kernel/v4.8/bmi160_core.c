static enum V_1 F_1 ( enum V_2 V_3 )
{
switch ( V_3 ) {
case V_4 :
return V_5 ;
case V_6 :
return V_7 ;
default:
return - V_8 ;
}
}
static
int F_2 ( struct V_9 * V_10 , enum V_1 V_11 ,
bool V_12 )
{
int V_13 ;
T_1 V_14 ;
if ( V_12 )
V_14 = V_15 [ V_11 ] . V_16 ;
else
V_14 = V_15 [ V_11 ] . V_17 ;
V_13 = F_3 ( V_10 -> V_18 , V_19 , V_14 ) ;
if ( V_13 < 0 )
return V_13 ;
F_4 ( V_20 [ V_11 ] . V_21 , V_20 [ V_11 ] . V_22 ) ;
return 0 ;
}
static
int F_5 ( struct V_9 * V_10 , enum V_1 V_11 ,
int V_23 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_25 [ V_11 ] . V_26 ; V_24 ++ )
if ( V_25 [ V_11 ] . V_27 [ V_24 ] . V_23 == V_23 )
break;
if ( V_24 == V_25 [ V_11 ] . V_26 )
return - V_8 ;
return F_3 ( V_10 -> V_18 , V_15 [ V_11 ] . V_28 ,
V_25 [ V_11 ] . V_27 [ V_24 ] . V_29 ) ;
}
static
int F_6 ( struct V_9 * V_10 , enum V_1 V_11 ,
int * V_23 )
{
int V_24 , V_13 , V_30 ;
V_13 = F_7 ( V_10 -> V_18 , V_15 [ V_11 ] . V_28 , & V_30 ) ;
if ( V_13 < 0 )
return V_13 ;
for ( V_24 = 0 ; V_24 < V_25 [ V_11 ] . V_26 ; V_24 ++ )
if ( V_25 [ V_11 ] . V_27 [ V_24 ] . V_29 == V_30 ) {
* V_23 = V_25 [ V_11 ] . V_27 [ V_24 ] . V_23 ;
return 0 ;
}
return - V_8 ;
}
static int F_8 ( struct V_9 * V_10 , int V_31 ,
int V_32 , int * V_30 )
{
T_1 V_33 ;
int V_13 ;
T_2 V_34 ;
enum V_1 V_11 = F_1 ( V_31 ) ;
V_33 = V_15 [ V_11 ] . V_10 + ( V_32 - V_35 ) * sizeof( T_2 ) ;
V_13 = F_9 ( V_10 -> V_18 , V_33 , & V_34 , sizeof( T_2 ) ) ;
if ( V_13 < 0 )
return V_13 ;
* V_30 = F_10 ( F_11 ( V_34 ) , 15 ) ;
return 0 ;
}
static
int F_12 ( struct V_9 * V_10 , enum V_1 V_11 ,
int V_36 , int V_37 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_38 [ V_11 ] . V_26 ; V_24 ++ )
if ( V_38 [ V_11 ] . V_27 [ V_24 ] . V_36 == V_36 &&
V_38 [ V_11 ] . V_27 [ V_24 ] . V_37 == V_37 )
break;
if ( V_24 >= V_38 [ V_11 ] . V_26 )
return - V_8 ;
return F_13 ( V_10 -> V_18 ,
V_15 [ V_11 ] . V_39 ,
V_15 [ V_11 ] . V_40 ,
V_38 [ V_11 ] . V_27 [ V_24 ] . V_29 ) ;
}
static int F_14 ( struct V_9 * V_10 , enum V_1 V_11 ,
int * V_36 , int * V_37 )
{
int V_24 , V_30 , V_13 ;
V_13 = F_7 ( V_10 -> V_18 , V_15 [ V_11 ] . V_39 , & V_30 ) ;
if ( V_13 < 0 )
return V_13 ;
V_30 &= V_15 [ V_11 ] . V_40 ;
for ( V_24 = 0 ; V_24 < V_38 [ V_11 ] . V_26 ; V_24 ++ )
if ( V_30 == V_38 [ V_11 ] . V_27 [ V_24 ] . V_29 )
break;
if ( V_24 >= V_38 [ V_11 ] . V_26 )
return - V_8 ;
* V_36 = V_38 [ V_11 ] . V_27 [ V_24 ] . V_36 ;
* V_37 = V_38 [ V_11 ] . V_27 [ V_24 ] . V_37 ;
return 0 ;
}
static T_3 F_15 ( int V_41 , void * V_42 )
{
struct V_43 * V_44 = V_42 ;
struct V_45 * V_46 = V_44 -> V_46 ;
struct V_9 * V_10 = F_16 ( V_46 ) ;
T_4 V_47 [ 16 ] ;
int V_24 , V_13 , V_48 = 0 , V_49 = V_50 ;
T_2 V_34 ;
F_17 (i, indio_dev->active_scan_mask,
indio_dev->masklength) {
V_13 = F_9 ( V_10 -> V_18 , V_49 + V_24 * sizeof( T_2 ) ,
& V_34 , sizeof( T_2 ) ) ;
if ( V_13 < 0 )
goto V_51;
V_47 [ V_48 ++ ] = V_34 ;
}
F_18 ( V_46 , V_47 ,
F_19 ( V_46 ) ) ;
V_51:
F_20 ( V_46 -> V_52 ) ;
return V_53 ;
}
static int F_21 ( struct V_45 * V_46 ,
struct V_54 const * V_55 ,
int * V_30 , int * V_56 , long V_57 )
{
int V_13 ;
struct V_9 * V_10 = F_16 ( V_46 ) ;
switch ( V_57 ) {
case V_58 :
V_13 = F_8 ( V_10 , V_55 -> type , V_55 -> V_59 , V_30 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_60 ;
case V_61 :
* V_30 = 0 ;
V_13 = F_6 ( V_10 ,
F_1 ( V_55 -> type ) , V_56 ) ;
return V_13 < 0 ? V_13 : V_62 ;
case V_63 :
V_13 = F_14 ( V_10 , F_1 ( V_55 -> type ) ,
V_30 , V_56 ) ;
return V_13 < 0 ? V_13 : V_62 ;
default:
return - V_8 ;
}
return 0 ;
}
static int F_22 ( struct V_45 * V_46 ,
struct V_54 const * V_55 ,
int V_30 , int V_56 , long V_57 )
{
struct V_9 * V_10 = F_16 ( V_46 ) ;
switch ( V_57 ) {
case V_61 :
return F_5 ( V_10 ,
F_1 ( V_55 -> type ) , V_56 ) ;
break;
case V_63 :
return F_12 ( V_10 , F_1 ( V_55 -> type ) ,
V_30 , V_56 ) ;
default:
return - V_8 ;
}
return 0 ;
}
static const char * F_23 ( struct V_64 * V_65 )
{
const struct V_66 * V_67 ;
V_67 = F_24 ( V_65 -> V_68 -> V_69 , V_65 ) ;
if ( ! V_67 )
return NULL ;
return F_25 ( V_65 ) ;
}
static int F_26 ( struct V_9 * V_10 , bool V_70 )
{
int V_13 ;
unsigned int V_30 ;
struct V_64 * V_65 = F_27 ( V_10 -> V_18 ) ;
V_13 = F_3 ( V_10 -> V_18 , V_19 , V_71 ) ;
if ( V_13 < 0 )
return V_13 ;
F_4 ( V_72 , V_72 + 1 ) ;
if ( V_70 ) {
V_13 = F_7 ( V_10 -> V_18 , V_73 , & V_30 ) ;
if ( V_13 < 0 )
return V_13 ;
}
V_13 = F_7 ( V_10 -> V_18 , V_74 , & V_30 ) ;
if ( V_13 < 0 ) {
F_28 ( V_65 , L_1 ) ;
return V_13 ;
}
if ( V_30 != V_75 ) {
F_28 ( V_65 , L_2 ,
V_30 , V_75 ) ;
return - V_76 ;
}
V_13 = F_2 ( V_10 , V_5 , true ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_2 ( V_10 , V_7 , true ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static void F_29 ( struct V_9 * V_10 )
{
F_2 ( V_10 , V_7 , false ) ;
F_2 ( V_10 , V_5 , false ) ;
}
int F_30 ( struct V_64 * V_65 , struct V_18 * V_18 ,
const char * V_77 , bool V_70 )
{
struct V_45 * V_46 ;
struct V_9 * V_10 ;
int V_13 ;
V_46 = F_31 ( V_65 , sizeof( * V_10 ) ) ;
if ( ! V_46 )
return - V_78 ;
V_10 = F_16 ( V_46 ) ;
F_32 ( V_65 , V_46 ) ;
V_10 -> V_18 = V_18 ;
V_13 = F_26 ( V_10 , V_70 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( ! V_77 && F_33 ( V_65 ) )
V_77 = F_23 ( V_65 ) ;
V_46 -> V_65 . V_79 = V_65 ;
V_46 -> V_80 = V_81 ;
V_46 -> V_82 = F_34 ( V_81 ) ;
V_46 -> V_77 = V_77 ;
V_46 -> V_83 = V_84 ;
V_46 -> V_85 = & V_86 ;
V_13 = F_35 ( V_46 , NULL ,
F_15 , NULL ) ;
if ( V_13 < 0 )
goto V_87;
V_13 = F_36 ( V_46 ) ;
if ( V_13 < 0 )
goto V_88;
return 0 ;
V_88:
F_37 ( V_46 ) ;
V_87:
F_29 ( V_10 ) ;
return V_13 ;
}
void F_38 ( struct V_64 * V_65 )
{
struct V_45 * V_46 = F_39 ( V_65 ) ;
struct V_9 * V_10 = F_16 ( V_46 ) ;
F_40 ( V_46 ) ;
F_37 ( V_46 ) ;
F_29 ( V_10 ) ;
}
