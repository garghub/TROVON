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
F_4 ( V_20 [ V_11 ] , V_20 [ V_11 ] + 1000 ) ;
return 0 ;
}
static
int F_5 ( struct V_9 * V_10 , enum V_1 V_11 ,
int V_21 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_23 [ V_11 ] . V_24 ; V_22 ++ )
if ( V_23 [ V_11 ] . V_25 [ V_22 ] . V_21 == V_21 )
break;
if ( V_22 == V_23 [ V_11 ] . V_24 )
return - V_8 ;
return F_3 ( V_10 -> V_18 , V_15 [ V_11 ] . V_26 ,
V_23 [ V_11 ] . V_25 [ V_22 ] . V_27 ) ;
}
static
int F_6 ( struct V_9 * V_10 , enum V_1 V_11 ,
int * V_21 )
{
int V_22 , V_13 , V_28 ;
V_13 = F_7 ( V_10 -> V_18 , V_15 [ V_11 ] . V_26 , & V_28 ) ;
if ( V_13 < 0 )
return V_13 ;
for ( V_22 = 0 ; V_22 < V_23 [ V_11 ] . V_24 ; V_22 ++ )
if ( V_23 [ V_11 ] . V_25 [ V_22 ] . V_27 == V_28 ) {
* V_21 = V_23 [ V_11 ] . V_25 [ V_22 ] . V_21 ;
return 0 ;
}
return - V_8 ;
}
static int F_8 ( struct V_9 * V_10 , int V_29 ,
int V_30 , int * V_28 )
{
T_1 V_31 ;
int V_13 ;
T_2 V_32 ;
enum V_1 V_11 = F_1 ( V_29 ) ;
V_31 = V_15 [ V_11 ] . V_10 + ( V_30 - V_33 ) * sizeof( V_32 ) ;
V_13 = F_9 ( V_10 -> V_18 , V_31 , & V_32 , sizeof( V_32 ) ) ;
if ( V_13 < 0 )
return V_13 ;
* V_28 = F_10 ( F_11 ( V_32 ) , 15 ) ;
return 0 ;
}
static
int F_12 ( struct V_9 * V_10 , enum V_1 V_11 ,
int V_34 , int V_35 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_36 [ V_11 ] . V_24 ; V_22 ++ )
if ( V_36 [ V_11 ] . V_25 [ V_22 ] . V_34 == V_34 &&
V_36 [ V_11 ] . V_25 [ V_22 ] . V_35 == V_35 )
break;
if ( V_22 >= V_36 [ V_11 ] . V_24 )
return - V_8 ;
return F_13 ( V_10 -> V_18 ,
V_15 [ V_11 ] . V_37 ,
V_15 [ V_11 ] . V_38 ,
V_36 [ V_11 ] . V_25 [ V_22 ] . V_27 ) ;
}
static int F_14 ( struct V_9 * V_10 , enum V_1 V_11 ,
int * V_34 , int * V_35 )
{
int V_22 , V_28 , V_13 ;
V_13 = F_7 ( V_10 -> V_18 , V_15 [ V_11 ] . V_37 , & V_28 ) ;
if ( V_13 < 0 )
return V_13 ;
V_28 &= V_15 [ V_11 ] . V_38 ;
for ( V_22 = 0 ; V_22 < V_36 [ V_11 ] . V_24 ; V_22 ++ )
if ( V_28 == V_36 [ V_11 ] . V_25 [ V_22 ] . V_27 )
break;
if ( V_22 >= V_36 [ V_11 ] . V_24 )
return - V_8 ;
* V_34 = V_36 [ V_11 ] . V_25 [ V_22 ] . V_34 ;
* V_35 = V_36 [ V_11 ] . V_25 [ V_22 ] . V_35 ;
return 0 ;
}
static T_3 F_15 ( int V_39 , void * V_40 )
{
struct V_41 * V_42 = V_40 ;
struct V_43 * V_44 = V_42 -> V_44 ;
struct V_9 * V_10 = F_16 ( V_44 ) ;
T_2 V_45 [ 16 ] ;
int V_22 , V_13 , V_46 = 0 , V_47 = V_48 ;
T_2 V_32 ;
F_17 (i, indio_dev->active_scan_mask,
indio_dev->masklength) {
V_13 = F_9 ( V_10 -> V_18 , V_47 + V_22 * sizeof( V_32 ) ,
& V_32 , sizeof( V_32 ) ) ;
if ( V_13 < 0 )
goto V_49;
V_45 [ V_46 ++ ] = V_32 ;
}
F_18 ( V_44 , V_45 ,
F_19 ( V_44 ) ) ;
V_49:
F_20 ( V_44 -> V_50 ) ;
return V_51 ;
}
static int F_21 ( struct V_43 * V_44 ,
struct V_52 const * V_53 ,
int * V_28 , int * V_54 , long V_55 )
{
int V_13 ;
struct V_9 * V_10 = F_16 ( V_44 ) ;
switch ( V_55 ) {
case V_56 :
V_13 = F_8 ( V_10 , V_53 -> type , V_53 -> V_57 , V_28 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_58 ;
case V_59 :
* V_28 = 0 ;
V_13 = F_6 ( V_10 ,
F_1 ( V_53 -> type ) , V_54 ) ;
return V_13 < 0 ? V_13 : V_60 ;
case V_61 :
V_13 = F_14 ( V_10 , F_1 ( V_53 -> type ) ,
V_28 , V_54 ) ;
return V_13 < 0 ? V_13 : V_60 ;
default:
return - V_8 ;
}
return 0 ;
}
static int F_22 ( struct V_43 * V_44 ,
struct V_52 const * V_53 ,
int V_28 , int V_54 , long V_55 )
{
struct V_9 * V_10 = F_16 ( V_44 ) ;
switch ( V_55 ) {
case V_59 :
return F_5 ( V_10 ,
F_1 ( V_53 -> type ) , V_54 ) ;
break;
case V_61 :
return F_12 ( V_10 , F_1 ( V_53 -> type ) ,
V_28 , V_54 ) ;
default:
return - V_8 ;
}
return 0 ;
}
static const char * F_23 ( struct V_62 * V_63 )
{
const struct V_64 * V_65 ;
V_65 = F_24 ( V_63 -> V_66 -> V_67 , V_63 ) ;
if ( ! V_65 )
return NULL ;
return F_25 ( V_63 ) ;
}
static int F_26 ( struct V_9 * V_10 , bool V_68 )
{
int V_13 ;
unsigned int V_28 ;
struct V_62 * V_63 = F_27 ( V_10 -> V_18 ) ;
V_13 = F_3 ( V_10 -> V_18 , V_19 , V_69 ) ;
if ( V_13 < 0 )
return V_13 ;
F_4 ( V_70 , V_70 + 1 ) ;
if ( V_68 ) {
V_13 = F_7 ( V_10 -> V_18 , V_71 , & V_28 ) ;
if ( V_13 < 0 )
return V_13 ;
}
V_13 = F_7 ( V_10 -> V_18 , V_72 , & V_28 ) ;
if ( V_13 < 0 ) {
F_28 ( V_63 , L_1 ) ;
return V_13 ;
}
if ( V_28 != V_73 ) {
F_28 ( V_63 , L_2 ,
V_28 , V_73 ) ;
return - V_74 ;
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
int F_30 ( struct V_62 * V_63 , struct V_18 * V_18 ,
const char * V_75 , bool V_68 )
{
struct V_43 * V_44 ;
struct V_9 * V_10 ;
int V_13 ;
V_44 = F_31 ( V_63 , sizeof( * V_10 ) ) ;
if ( ! V_44 )
return - V_76 ;
V_10 = F_16 ( V_44 ) ;
F_32 ( V_63 , V_44 ) ;
V_10 -> V_18 = V_18 ;
V_13 = F_26 ( V_10 , V_68 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( ! V_75 && F_33 ( V_63 ) )
V_75 = F_23 ( V_63 ) ;
V_44 -> V_63 . V_77 = V_63 ;
V_44 -> V_78 = V_79 ;
V_44 -> V_80 = F_34 ( V_79 ) ;
V_44 -> V_75 = V_75 ;
V_44 -> V_81 = V_82 ;
V_44 -> V_83 = & V_84 ;
V_13 = F_35 ( V_44 , NULL ,
F_15 , NULL ) ;
if ( V_13 < 0 )
goto V_85;
V_13 = F_36 ( V_44 ) ;
if ( V_13 < 0 )
goto V_86;
return 0 ;
V_86:
F_37 ( V_44 ) ;
V_85:
F_29 ( V_10 ) ;
return V_13 ;
}
void F_38 ( struct V_62 * V_63 )
{
struct V_43 * V_44 = F_39 ( V_63 ) ;
struct V_9 * V_10 = F_16 ( V_44 ) ;
F_40 ( V_44 ) ;
F_37 ( V_44 ) ;
F_29 ( V_10 ) ;
}
