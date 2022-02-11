static int F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
int * V_5 )
{
int V_6 ;
* V_4 = F_2 ( sizeof( struct V_3 ) , V_7 ) ;
if ( ! * V_4 )
return - V_8 ;
F_3 ( & V_2 -> V_9 ) ;
V_6 = F_4 ( & V_2 -> V_10 , * V_4 ,
1 , 0 , V_7 ) ;
if ( V_6 < 0 ) {
F_5 ( & V_2 -> V_9 ) ;
F_6 ( * V_4 ) ;
return V_6 ;
}
* V_5 = V_6 ;
F_7 ( & ( * V_4 ) -> V_11 ) ;
( * V_4 ) -> V_12 = 0 ;
( * V_4 ) -> V_13 = NULL ;
F_3 ( & ( * V_4 ) -> V_11 ) ;
F_5 ( & V_2 -> V_9 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 , int V_5 )
{
struct V_3 * V_14 ;
F_3 ( & V_2 -> V_9 ) ;
V_14 = F_9 ( & V_2 -> V_10 , V_5 ) ;
if ( V_14 ) {
F_3 ( & V_14 -> V_11 ) ;
F_10 ( & V_2 -> V_10 , V_5 ) ;
F_5 ( & V_14 -> V_11 ) ;
F_11 ( V_14 ) ;
}
F_5 ( & V_2 -> V_9 ) ;
}
static int F_12 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_3 * V_14 ,
struct V_19 * V_20 ,
unsigned V_12 )
{
struct V_21 * V_13 ;
struct V_22 * V_23 = V_16 -> V_24 . V_25 ;
struct V_22 * V_26 = V_16 -> V_24 . V_27 ;
struct V_22 * V_28 = V_16 -> V_24 . V_29 ;
bool V_30 = false ;
unsigned V_31 ;
V_13 = F_13 ( V_12 , sizeof( struct V_21 ) ) ;
if ( ! V_13 )
return - V_8 ;
memset ( V_13 , 0 , V_12 * sizeof( struct V_21 ) ) ;
for ( V_31 = 0 ; V_31 < V_12 ; ++ V_31 ) {
struct V_21 * V_32 = & V_13 [ V_31 ] ;
struct V_33 * V_34 ;
V_34 = F_14 ( V_16 -> V_35 , V_18 , V_20 [ V_31 ] . V_36 ) ;
if ( ! V_34 )
goto V_37;
V_32 -> V_38 = F_15 ( F_16 ( V_34 ) ) ;
F_17 ( V_34 ) ;
V_32 -> V_39 = V_20 [ V_31 ] . V_40 ;
V_32 -> V_41 = V_32 -> V_38 -> V_42 ;
V_32 -> V_43 = V_32 -> V_41 ;
if ( V_32 -> V_43 == V_44 )
V_32 -> V_43 |= V_45 ;
if ( F_18 ( V_32 -> V_38 -> V_46 . V_47 ) ) {
V_30 = true ;
V_32 -> V_41 = V_45 ;
V_32 -> V_43 = V_45 ;
}
V_32 -> V_48 . V_49 = & V_32 -> V_38 -> V_46 ;
V_32 -> V_48 . V_50 = true ;
if ( V_32 -> V_41 == V_51 )
V_23 = V_32 -> V_38 ;
if ( V_32 -> V_41 == V_52 )
V_26 = V_32 -> V_38 ;
if ( V_32 -> V_41 == V_53 )
V_28 = V_32 -> V_38 ;
F_19 ( V_14 , V_32 -> V_38 ) ;
}
for ( V_31 = 0 ; V_31 < V_14 -> V_12 ; ++ V_31 )
F_20 ( & V_14 -> V_13 [ V_31 ] . V_38 ) ;
F_21 ( V_14 -> V_13 ) ;
V_14 -> V_23 = V_23 ;
V_14 -> V_26 = V_26 ;
V_14 -> V_28 = V_28 ;
V_14 -> V_30 = V_30 ;
V_14 -> V_13 = V_13 ;
V_14 -> V_12 = V_12 ;
return 0 ;
V_37:
F_21 ( V_13 ) ;
return - V_54 ;
}
struct V_3 *
F_22 ( struct V_1 * V_2 , int V_5 )
{
struct V_3 * V_4 ;
F_3 ( & V_2 -> V_9 ) ;
V_4 = F_9 ( & V_2 -> V_10 , V_5 ) ;
if ( V_4 )
F_3 ( & V_4 -> V_11 ) ;
F_5 ( & V_2 -> V_9 ) ;
return V_4 ;
}
void F_23 ( struct V_3 * V_14 )
{
F_5 ( & V_14 -> V_11 ) ;
}
void F_11 ( struct V_3 * V_14 )
{
unsigned V_31 ;
for ( V_31 = 0 ; V_31 < V_14 -> V_12 ; ++ V_31 )
F_20 ( & V_14 -> V_13 [ V_31 ] . V_38 ) ;
F_24 ( & V_14 -> V_11 ) ;
F_21 ( V_14 -> V_13 ) ;
F_6 ( V_14 ) ;
}
int F_25 ( struct V_55 * V_56 , void * V_57 ,
struct V_17 * V_18 )
{
const T_1 V_58 = sizeof( struct V_19 ) ;
struct V_15 * V_16 = V_56 -> V_59 ;
struct V_1 * V_2 = V_18 -> V_60 ;
union V_61 * args = V_57 ;
T_1 V_62 = args -> V_63 . V_64 ;
const void T_2 * V_65 = ( const void * ) ( long ) args -> V_63 . V_66 ;
struct V_19 * V_20 ;
struct V_3 * V_14 ;
int V_6 ;
V_20 = F_13 ( args -> V_63 . V_67 ,
sizeof( struct V_19 ) ) ;
if ( ! V_20 )
return - V_8 ;
V_6 = - V_68 ;
if ( F_26 ( V_58 == args -> V_63 . V_69 ) ) {
unsigned long V_70 = args -> V_63 . V_67 *
args -> V_63 . V_69 ;
if ( F_27 ( V_20 , V_65 , V_70 ) )
goto V_37;
} else {
unsigned long V_70 = F_28 ( args -> V_63 . V_69 , V_58 ) ;
unsigned V_31 ;
memset ( V_20 , 0 , args -> V_63 . V_67 * V_58 ) ;
for ( V_31 = 0 ; V_31 < args -> V_63 . V_67 ; ++ V_31 ) {
if ( F_27 ( & V_20 [ V_31 ] , V_65 , V_70 ) )
goto V_37;
V_65 += args -> V_63 . V_69 ;
}
}
switch ( args -> V_63 . V_71 ) {
case V_72 :
V_6 = F_1 ( V_2 , & V_14 , & V_62 ) ;
if ( V_6 )
goto V_37;
V_6 = F_12 ( V_16 , V_18 , V_14 , V_20 ,
args -> V_63 . V_67 ) ;
F_23 ( V_14 ) ;
if ( V_6 )
goto V_37;
break;
case V_73 :
F_8 ( V_2 , V_62 ) ;
V_62 = 0 ;
break;
case V_74 :
V_6 = - V_54 ;
V_14 = F_22 ( V_2 , V_62 ) ;
if ( ! V_14 )
goto V_37;
V_6 = F_12 ( V_16 , V_18 , V_14 , V_20 ,
args -> V_63 . V_67 ) ;
F_23 ( V_14 ) ;
if ( V_6 )
goto V_37;
break;
default:
V_6 = - V_75 ;
goto V_37;
}
memset ( args , 0 , sizeof( * args ) ) ;
args -> V_76 . V_64 = V_62 ;
F_21 ( V_20 ) ;
return 0 ;
V_37:
F_21 ( V_20 ) ;
return V_6 ;
}
