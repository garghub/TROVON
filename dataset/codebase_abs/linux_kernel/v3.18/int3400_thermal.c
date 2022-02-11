static int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 = { V_5 , NULL } ;
union V_6 * V_7 , * V_8 ;
int V_9 , V_10 ;
int V_11 = 0 ;
T_1 V_12 ;
V_12 = F_2 ( V_2 -> V_13 -> V_14 , L_1 , NULL , & V_4 ) ;
if ( F_3 ( V_12 ) )
return - V_15 ;
V_7 = (union V_6 * ) V_4 . V_16 ;
if ( V_7 -> type != V_17 ) {
V_11 = - V_18 ;
goto V_19;
}
for ( V_9 = 0 ; V_9 < V_7 -> V_20 . V_21 ; V_9 ++ ) {
V_8 = & V_7 -> V_20 . V_22 [ V_9 ] ;
if ( V_8 -> type != V_23 ) {
V_11 = - V_18 ;
goto V_19;
}
if ( V_8 -> V_24 . V_25 != 16 ) {
V_11 = - V_18 ;
goto V_19;
}
for ( V_10 = 0 ; V_10 < V_26 ; V_10 ++ ) {
T_2 V_27 [ 16 ] ;
F_4 ( V_28 [ V_10 ] , V_27 ) ;
if ( ! strncmp ( V_27 , V_8 -> V_24 . V_16 , 16 ) ) {
V_2 -> V_29 |= ( 1 << V_10 ) ;
break;
}
}
}
V_19:
F_5 ( V_4 . V_16 ) ;
return V_11 ;
}
static int F_6 ( T_3 V_14 ,
enum V_30 V_27 , bool V_31 )
{
T_4 V_32 , V_4 [ 2 ] ;
T_1 V_12 ;
int V_11 = 0 ;
struct V_33 V_34 = {
. V_35 = V_28 [ V_27 ] ,
. V_36 = 1 ,
. V_37 . V_25 = 8 ,
} ;
V_4 [ V_38 ] = 0 ;
V_4 [ V_39 ] = V_31 ;
V_34 . V_37 . V_16 = V_4 ;
V_12 = F_7 ( V_14 , & V_34 ) ;
if ( F_8 ( V_12 ) ) {
V_32 = * ( ( T_4 * ) ( V_34 . V_32 . V_16 + 4 ) ) ;
if ( V_32 != V_31 )
V_11 = - V_40 ;
} else
V_11 = - V_40 ;
F_5 ( V_34 . V_32 . V_16 ) ;
return V_11 ;
}
static int F_9 ( struct V_41 * V_42 ,
unsigned long * V_43 )
{
* V_43 = 20 * 1000 ;
return 0 ;
}
static int F_10 ( struct V_41 * V_42 ,
enum V_44 * V_45 )
{
struct V_1 * V_2 = V_42 -> V_46 ;
if ( ! V_2 )
return - V_18 ;
* V_45 = V_2 -> V_45 ;
return 0 ;
}
static int F_11 ( struct V_41 * V_42 ,
enum V_44 V_45 )
{
struct V_1 * V_2 = V_42 -> V_46 ;
bool V_31 ;
int V_11 = 0 ;
if ( ! V_2 )
return - V_18 ;
if ( V_45 == V_47 )
V_31 = true ;
else if ( V_45 == V_48 )
V_31 = false ;
else
return - V_18 ;
if ( V_31 != V_2 -> V_45 ) {
V_2 -> V_45 = V_31 ;
V_11 = F_6 ( V_2 -> V_13 -> V_14 ,
V_49 , V_31 ) ;
}
return V_11 ;
}
static int F_12 ( struct V_50 * V_51 )
{
struct V_52 * V_13 = F_13 ( & V_51 -> V_53 ) ;
struct V_1 * V_2 ;
int V_11 ;
if ( ! V_13 )
return - V_15 ;
V_2 = F_14 ( sizeof( struct V_1 ) , V_54 ) ;
if ( ! V_2 )
return - V_55 ;
V_2 -> V_13 = V_13 ;
V_11 = F_1 ( V_2 ) ;
if ( V_11 )
goto V_56;
V_11 = F_15 ( V_2 -> V_13 -> V_14 , & V_2 -> V_57 ,
& V_2 -> V_58 , true ) ;
if ( V_11 )
goto V_56;
V_11 = F_16 ( V_2 -> V_13 -> V_14 , & V_2 -> V_59 ,
& V_2 -> V_60 , true ) ;
if ( V_11 )
goto V_61;
F_17 ( V_51 , V_2 ) ;
if ( V_2 -> V_29 & 1 << V_49 ) {
V_62 . V_63 = F_10 ;
V_62 . V_64 = F_11 ;
}
V_2 -> V_42 = F_18 ( L_2 , 0 , 0 ,
V_2 , & V_62 ,
& V_65 , 0 , 0 ) ;
if ( F_19 ( V_2 -> V_42 ) ) {
V_11 = F_20 ( V_2 -> V_42 ) ;
goto V_66;
}
V_2 -> V_67 = F_21 (
V_2 -> V_13 -> V_14 ) ;
return 0 ;
V_66:
F_5 ( V_2 -> V_60 ) ;
V_61:
F_5 ( V_2 -> V_58 ) ;
V_56:
F_5 ( V_2 ) ;
return V_11 ;
}
static int F_22 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = F_23 ( V_51 ) ;
if ( ! V_2 -> V_67 )
F_24 ( V_2 -> V_13 -> V_14 ) ;
F_25 ( V_2 -> V_42 ) ;
F_5 ( V_2 -> V_60 ) ;
F_5 ( V_2 -> V_58 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
