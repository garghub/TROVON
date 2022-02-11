static T_1 F_1 ( const union V_1 * V_2 )
{
return F_2 ( ( T_1 ) V_2 -> V_3 ) * sizeof( unsigned long ) ;
}
static struct V_4 * F_3 ( union V_1 * V_2 )
{
struct V_5 * V_6 ;
int V_7 = - V_8 ;
T_1 V_9 ;
if ( ! F_4 ( V_10 ) )
return F_5 ( - V_11 ) ;
if ( V_2 -> V_3 == 0 || V_2 -> V_12 != 4 ||
V_2 -> V_13 != 4 || V_2 -> V_14 & ~ V_15 )
return F_5 ( - V_8 ) ;
V_6 = F_6 ( sizeof( * V_6 ) , V_16 ) ;
if ( ! V_6 )
return F_5 ( - V_17 ) ;
V_6 -> V_18 . V_19 = V_2 -> V_19 ;
V_6 -> V_18 . V_12 = V_2 -> V_12 ;
V_6 -> V_18 . V_13 = V_2 -> V_13 ;
V_6 -> V_18 . V_3 = V_2 -> V_3 ;
V_6 -> V_18 . V_14 = V_2 -> V_14 ;
V_6 -> V_18 . V_20 = F_7 ( V_2 ) ;
V_9 = ( T_1 ) V_6 -> V_18 . V_3 * sizeof( struct V_21 * ) ;
V_9 += F_1 ( V_2 ) * F_8 () ;
if ( V_9 >= V_22 - V_23 )
goto V_24;
V_6 -> V_18 . V_25 = F_9 ( V_9 , V_23 ) >> V_26 ;
V_7 = F_10 ( V_6 -> V_18 . V_25 ) ;
if ( V_7 )
goto V_24;
V_7 = - V_17 ;
V_6 -> V_27 = F_11 ( F_1 ( V_2 ) ,
F_12 (unsigned long) ,
V_28 | V_29 ) ;
if ( ! V_6 -> V_27 )
goto V_24;
V_6 -> V_30 = F_13 ( V_6 -> V_18 . V_3 *
sizeof( struct V_21 * ) ,
V_6 -> V_18 . V_20 ) ;
if ( ! V_6 -> V_30 )
goto V_24;
F_14 ( & V_31 ) ;
F_15 ( & V_6 -> V_32 , & V_33 ) ;
F_16 ( & V_31 ) ;
return & V_6 -> V_18 ;
V_24:
F_17 ( V_6 -> V_27 ) ;
F_18 ( V_6 ) ;
return F_5 ( V_7 ) ;
}
static void F_19 ( struct V_4 * V_18 )
{
struct V_5 * V_6 = F_20 ( V_18 , struct V_5 , V_18 ) ;
int V_34 , V_35 ;
F_14 ( & V_31 ) ;
F_21 ( & V_6 -> V_32 ) ;
F_16 ( & V_31 ) ;
F_22 () ;
F_23 (cpu) {
unsigned long * V_36 = F_24 ( V_6 -> V_27 , V_35 ) ;
while ( ! F_25 ( V_36 , V_6 -> V_18 . V_3 ) )
F_26 () ;
}
for ( V_34 = 0 ; V_34 < V_6 -> V_18 . V_3 ; V_34 ++ ) {
struct V_21 * V_37 ;
V_37 = V_6 -> V_30 [ V_34 ] ;
if ( ! V_37 )
continue;
F_27 ( V_37 -> V_37 ) ;
F_18 ( V_37 ) ;
}
F_17 ( V_6 -> V_27 ) ;
F_28 ( V_6 -> V_30 ) ;
F_18 ( V_6 ) ;
}
static int F_29 ( struct V_4 * V_18 , void * V_38 , void * V_39 )
{
struct V_5 * V_6 = F_20 ( V_18 , struct V_5 , V_18 ) ;
T_2 V_40 = V_38 ? * ( T_2 * ) V_38 : V_22 ;
T_2 * V_41 = V_39 ;
if ( V_40 >= V_6 -> V_18 . V_3 ) {
* V_41 = 0 ;
return 0 ;
}
if ( V_40 == V_6 -> V_18 . V_3 - 1 )
return - V_42 ;
* V_41 = V_40 + 1 ;
return 0 ;
}
void F_30 ( struct V_4 * V_18 , T_2 V_43 )
{
struct V_5 * V_6 = F_20 ( V_18 , struct V_5 , V_18 ) ;
unsigned long * V_36 = F_31 ( V_6 -> V_27 ) ;
F_32 ( V_43 , V_36 ) ;
}
void F_33 ( struct V_4 * V_18 )
{
struct V_5 * V_6 = F_20 ( V_18 , struct V_5 , V_18 ) ;
unsigned long * V_36 = F_31 ( V_6 -> V_27 ) ;
T_2 V_43 ;
F_34 (bit, bitmap, map->max_entries) {
struct V_21 * V_37 = F_35 ( V_6 -> V_30 [ V_43 ] ) ;
struct V_44 * V_45 ;
if ( F_36 ( ! V_37 ) )
continue;
F_37 ( V_43 , V_36 ) ;
V_45 = V_37 -> V_37 ;
if ( F_38 ( V_45 -> V_46 -> V_47 ) )
V_45 -> V_46 -> V_47 ( V_45 ) ;
}
}
struct V_44 * F_39 ( struct V_4 * V_18 , T_2 V_38 )
{
struct V_5 * V_6 = F_20 ( V_18 , struct V_5 , V_18 ) ;
struct V_21 * V_37 ;
if ( V_38 >= V_18 -> V_3 )
return NULL ;
V_37 = F_35 ( V_6 -> V_30 [ V_38 ] ) ;
return V_37 ? V_37 -> V_37 : NULL ;
}
static void * F_40 ( struct V_4 * V_18 , void * V_38 )
{
struct V_44 * V_37 = F_39 ( V_18 , * ( T_2 * ) V_38 ) ;
return V_37 ? & V_37 -> V_48 : NULL ;
}
static void F_41 ( struct V_21 * V_37 )
{
if ( V_37 -> V_37 -> V_46 -> V_47 ) {
struct V_44 * V_49 = V_37 -> V_37 ;
unsigned long * V_36 ;
int V_35 ;
F_23 (cpu) {
V_36 = F_24 ( V_37 -> V_6 -> V_27 , V_35 ) ;
F_37 ( V_37 -> V_43 , V_36 ) ;
V_49 -> V_46 -> V_47 ( V_37 -> V_37 ) ;
}
}
}
static void F_42 ( struct V_50 * V_51 )
{
struct V_21 * V_37 ;
V_37 = F_20 ( V_51 , struct V_21 , V_51 ) ;
F_41 ( V_37 ) ;
F_27 ( V_37 -> V_37 ) ;
F_18 ( V_37 ) ;
}
static int F_43 ( struct V_4 * V_18 , void * V_38 )
{
struct V_5 * V_6 = F_20 ( V_18 , struct V_5 , V_18 ) ;
struct V_21 * V_52 ;
int V_53 = * ( T_2 * ) V_38 ;
if ( V_53 >= V_18 -> V_3 )
return - V_8 ;
V_52 = F_44 ( & V_6 -> V_30 [ V_53 ] , NULL ) ;
if ( V_52 )
F_45 ( & V_52 -> V_51 , F_42 ) ;
return 0 ;
}
static int F_46 ( struct V_4 * V_18 , void * V_38 , void * V_54 ,
T_1 V_14 )
{
struct V_5 * V_6 = F_20 ( V_18 , struct V_5 , V_18 ) ;
struct V_55 * V_55 = V_56 -> V_57 -> V_58 ;
struct V_21 * V_37 , * V_52 ;
T_2 V_34 = * ( T_2 * ) V_38 ;
T_2 V_48 = * ( T_2 * ) V_54 ;
if ( F_36 ( V_14 > V_59 ) )
return - V_8 ;
if ( F_36 ( V_34 >= V_6 -> V_18 . V_3 ) )
return - V_60 ;
if ( F_36 ( V_14 == V_61 ) )
return - V_62 ;
if ( ! V_48 ) {
V_37 = NULL ;
} else {
V_37 = F_47 ( sizeof( * V_37 ) , V_63 | V_29 ,
V_18 -> V_20 ) ;
if ( ! V_37 )
return - V_17 ;
V_37 -> V_37 = F_48 ( V_55 , V_48 ) ;
if ( ! V_37 -> V_37 ) {
F_18 ( V_37 ) ;
return - V_8 ;
}
V_37 -> V_43 = V_34 ;
V_37 -> V_6 = V_6 ;
}
V_52 = F_44 ( & V_6 -> V_30 [ V_34 ] , V_37 ) ;
if ( V_52 )
F_45 ( & V_52 -> V_51 , F_42 ) ;
return 0 ;
}
static int F_49 ( struct V_64 * V_65 ,
T_3 V_66 , void * V_67 )
{
struct V_44 * V_45 = F_50 ( V_67 ) ;
struct V_5 * V_6 ;
int V_34 ;
switch ( V_66 ) {
case V_68 :
F_51 () ;
F_52 (dtab, &dev_map_list, list) {
for ( V_34 = 0 ; V_34 < V_6 -> V_18 . V_3 ; V_34 ++ ) {
struct V_21 * V_37 , * V_69 ;
V_37 = F_35 ( V_6 -> V_30 [ V_34 ] ) ;
if ( ! V_37 ||
V_37 -> V_37 -> V_48 != V_45 -> V_48 )
continue;
V_69 = F_53 ( & V_6 -> V_30 [ V_34 ] , V_37 , NULL ) ;
if ( V_37 == V_69 )
F_45 ( & V_37 -> V_51 ,
F_42 ) ;
}
}
F_54 () ;
break;
default:
break;
}
return V_70 ;
}
static int T_4 F_55 ( void )
{
F_56 ( & V_71 ) ;
return 0 ;
}
