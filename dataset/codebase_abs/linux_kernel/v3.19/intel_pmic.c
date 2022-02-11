static int F_1 ( int V_1 , struct V_2 * V_3 ,
int V_4 , int * V_5 , int * V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_4 ; V_7 ++ ) {
if ( V_3 [ V_7 ] . V_1 == V_1 ) {
* V_5 = V_3 [ V_7 ] . V_5 ;
if ( V_6 )
* V_6 = V_3 [ V_7 ] . V_6 ;
return 0 ;
}
}
return - V_8 ;
}
static int F_2 ( struct V_9 * V_10 , int V_4 , int V_11 )
{
int V_7 , V_12 , V_13 , V_14 ;
for ( V_7 = 0 ; V_7 < V_4 - 1 ; V_7 ++ ) {
if ( ( V_11 >= V_10 [ V_7 ] . V_11 && V_11 <= V_10 [ V_7 + 1 ] . V_11 ) ||
( V_11 <= V_10 [ V_7 ] . V_11 && V_11 >= V_10 [ V_7 + 1 ] . V_11 ) )
break;
}
if ( V_7 == V_4 - 1 )
return - V_8 ;
V_12 = V_10 [ V_7 + 1 ] . V_14 - V_10 [ V_7 ] . V_14 ;
V_13 = V_10 [ V_7 + 1 ] . V_11 - V_10 [ V_7 ] . V_11 ;
V_14 = V_10 [ V_7 ] . V_14 + ( V_11 - V_10 [ V_7 ] . V_11 ) * V_12 / V_13 ;
return V_14 ;
}
static int F_3 ( struct V_9 * V_10 , int V_4 , int V_14 )
{
int V_7 , V_12 , V_13 , V_11 ;
for ( V_7 = 0 ; V_7 < V_4 - 1 ; V_7 ++ ) {
if ( V_14 >= V_10 [ V_7 ] . V_14 && V_14 <= V_10 [ V_7 + 1 ] . V_14 )
break;
}
if ( V_7 == V_4 - 1 )
return - V_8 ;
V_12 = V_10 [ V_7 + 1 ] . V_14 - V_10 [ V_7 ] . V_14 ;
V_13 = V_10 [ V_7 + 1 ] . V_11 - V_10 [ V_7 ] . V_11 ;
V_11 = V_10 [ V_7 ] . V_11 + ( V_14 - V_10 [ V_7 ] . V_14 ) * V_13 / V_12 ;
return V_11 ;
}
static void F_4 ( struct V_15 * V_16 ,
T_1 V_17 , struct V_18 * V_19 )
{
struct V_20 V_21 = { V_22 , NULL } ;
union V_23 * V_24 , * V_25 ;
int * V_10 , V_7 ;
T_2 V_26 ;
V_26 = F_5 ( V_17 , L_1 , NULL , & V_21 ) ;
if ( F_6 ( V_26 ) )
return;
V_24 = (union V_23 * ) V_21 . V_27 ;
if ( ! V_24 || ( V_24 -> type != V_28 ) ||
( V_24 -> V_29 . V_4 % 2 ) || ( V_24 -> V_29 . V_4 < 4 ) )
goto V_30;
V_10 = F_7 ( V_19 , sizeof( int ) * V_24 -> V_29 . V_4 ,
V_31 ) ;
if ( ! V_10 )
goto V_30;
for ( V_7 = 0 ; V_7 < V_24 -> V_29 . V_4 ; V_7 ++ ) {
V_25 = & V_24 -> V_29 . V_32 [ V_7 ] ;
if ( V_25 -> type != V_33 ) {
F_8 ( V_19 , V_10 ) ;
goto V_30;
}
V_10 [ V_7 ] = ( V_34 ) V_25 -> integer . V_35 ;
}
V_16 -> V_10 = (struct V_9 * ) V_10 ;
V_16 -> V_36 = V_24 -> V_29 . V_4 / 2 ;
V_30:
F_9 ( V_21 . V_27 ) ;
}
static T_2 F_10 ( T_3 V_37 ,
T_4 V_1 , T_3 V_38 , T_5 * V_39 ,
void * V_40 , void * V_41 )
{
struct V_15 * V_16 = V_41 ;
struct V_42 * V_42 = V_16 -> V_42 ;
struct V_43 * V_44 = V_16 -> V_45 ;
int V_5 , V_6 , V_46 ;
if ( V_38 != 32 || ! V_39 )
return V_47 ;
if ( V_37 == V_48 && ! ( * V_39 == 0 || * V_39 == 1 ) )
return V_47 ;
V_46 = F_1 ( V_1 , V_44 -> V_49 ,
V_44 -> V_50 , & V_5 , & V_6 ) ;
if ( V_46 == - V_8 )
return V_47 ;
F_11 ( & V_16 -> V_51 ) ;
V_46 = V_37 == V_52 ?
V_44 -> V_53 ( V_42 , V_5 , V_6 , V_39 ) :
V_44 -> V_54 ( V_42 , V_5 , V_6 , * V_39 == 1 ) ;
F_12 ( & V_16 -> V_51 ) ;
return V_46 ? V_55 : V_56 ;
}
static int F_13 ( struct V_15 * V_16 ,
int V_5 , T_5 * V_35 )
{
int V_57 , V_14 ;
if ( ! V_16 -> V_45 -> V_58 )
return - V_59 ;
V_57 = V_16 -> V_45 -> V_58 ( V_16 -> V_42 , V_5 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( ! V_16 -> V_10 ) {
* V_35 = V_57 ;
return 0 ;
}
V_14 = F_2 ( V_16 -> V_10 , V_16 -> V_36 , V_57 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_35 = V_14 ;
return 0 ;
}
static int F_14 ( struct V_15 * V_16 , int V_5 ,
T_3 V_37 , T_5 * V_35 )
{
return V_37 == V_52 ?
F_13 ( V_16 , V_5 , V_35 ) : - V_60 ;
}
static int F_15 ( struct V_15 * V_16 , int V_5 ,
T_3 V_37 , T_5 * V_35 )
{
int V_57 ;
if ( V_37 == V_52 )
return F_13 ( V_16 , V_5 , V_35 ) ;
if ( ! V_16 -> V_45 -> V_61 )
return - V_59 ;
if ( V_16 -> V_10 ) {
V_57 = F_3 ( V_16 -> V_10 , V_16 -> V_36 ,
* V_35 ) ;
if ( V_57 < 0 )
return V_57 ;
} else {
V_57 = * V_35 ;
}
return V_16 -> V_45 -> V_61 ( V_16 -> V_42 , V_5 , V_57 ) ;
}
static int F_16 ( struct V_15 * V_16 , int V_5 ,
T_3 V_37 , T_5 * V_35 )
{
struct V_43 * V_44 = V_16 -> V_45 ;
struct V_42 * V_42 = V_16 -> V_42 ;
if ( ! V_44 -> V_62 || ! V_44 -> V_63 )
return - V_59 ;
if ( V_37 == V_52 )
return V_44 -> V_62 ( V_42 , V_5 , V_35 ) ;
if ( * V_35 != 0 && * V_35 != 1 )
return - V_60 ;
return V_44 -> V_63 ( V_42 , V_5 , * V_35 ) ;
}
static bool F_17 ( int V_1 )
{
return ( V_1 <= 0x3c ) && ! ( V_1 % 12 ) ;
}
static bool F_18 ( int V_1 )
{
return ( V_1 >= 4 && V_1 <= 0x40 && ! ( ( V_1 - 4 ) % 12 ) ) ||
( V_1 >= 8 && V_1 <= 0x44 && ! ( ( V_1 - 8 ) % 12 ) ) ;
}
static bool F_19 ( int V_1 )
{
return V_1 >= 0x48 && V_1 <= 0x5c ;
}
static T_2 F_20 ( T_3 V_37 ,
T_4 V_1 , T_3 V_38 , T_5 * V_39 ,
void * V_40 , void * V_41 )
{
struct V_15 * V_16 = V_41 ;
struct V_43 * V_44 = V_16 -> V_45 ;
int V_5 , V_46 ;
if ( V_38 != 32 || ! V_39 )
return V_47 ;
V_46 = F_1 ( V_1 , V_44 -> V_64 ,
V_44 -> V_65 , & V_5 , NULL ) ;
if ( V_46 == - V_8 )
return V_47 ;
F_11 ( & V_16 -> V_51 ) ;
if ( F_17 ( V_1 ) )
V_46 = F_14 ( V_16 , V_5 , V_37 , V_39 ) ;
else if ( F_18 ( V_1 ) )
V_46 = F_15 ( V_16 , V_5 , V_37 , V_39 ) ;
else if ( F_19 ( V_1 ) )
V_46 = F_16 ( V_16 , V_5 , V_37 , V_39 ) ;
else
V_46 = - V_60 ;
F_12 ( & V_16 -> V_51 ) ;
if ( V_46 < 0 ) {
if ( V_46 == - V_60 )
return V_47 ;
else
return V_55 ;
}
return V_56 ;
}
int F_21 ( struct V_18 * V_19 , T_1 V_17 ,
struct V_42 * V_42 ,
struct V_43 * V_44 )
{
T_2 V_26 ;
struct V_15 * V_16 ;
if ( ! V_19 || ! V_42 || ! V_44 )
return - V_60 ;
if ( ! V_17 )
return - V_66 ;
V_16 = F_22 ( V_19 , sizeof( * V_16 ) , V_31 ) ;
if ( ! V_16 )
return - V_67 ;
F_23 ( & V_16 -> V_51 ) ;
V_16 -> V_42 = V_42 ;
F_4 ( V_16 , V_17 , V_19 ) ;
V_26 = F_24 ( V_17 ,
V_68 ,
F_10 ,
NULL , V_16 ) ;
if ( F_6 ( V_26 ) )
return - V_66 ;
V_26 = F_24 ( V_17 ,
V_69 ,
F_20 ,
NULL , V_16 ) ;
if ( F_6 ( V_26 ) ) {
F_25 ( V_17 , V_68 ,
F_10 ) ;
return - V_66 ;
}
V_16 -> V_45 = V_44 ;
return 0 ;
}
