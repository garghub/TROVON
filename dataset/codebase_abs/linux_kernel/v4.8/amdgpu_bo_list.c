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
unsigned V_30 = 0 , V_31 = V_12 ;
unsigned V_32 ;
int V_6 ;
unsigned long V_33 = 0 ;
V_13 = F_13 ( V_12 , sizeof( struct V_21 ) ) ;
if ( ! V_13 )
return - V_8 ;
memset ( V_13 , 0 , V_12 * sizeof( struct V_21 ) ) ;
for ( V_32 = 0 ; V_32 < V_12 ; ++ V_32 ) {
struct V_21 * V_34 ;
struct V_35 * V_36 ;
struct V_22 * V_37 ;
struct V_38 * V_39 ;
V_36 = F_14 ( V_18 , V_20 [ V_32 ] . V_40 ) ;
if ( ! V_36 ) {
V_6 = - V_41 ;
goto V_42;
}
V_37 = F_15 ( F_16 ( V_36 ) ) ;
F_17 ( V_36 ) ;
V_39 = F_18 ( V_37 -> V_43 . V_44 ) ;
if ( V_39 ) {
if ( V_39 != V_45 -> V_46 ) {
F_19 ( & V_37 ) ;
V_6 = - V_47 ;
goto V_42;
}
V_34 = & V_13 [ -- V_31 ] ;
} else {
V_34 = & V_13 [ V_30 ++ ] ;
}
V_34 -> V_48 = V_37 ;
V_34 -> V_49 = F_20 ( V_20 [ V_32 ] . V_50 ,
V_51 ) ;
V_34 -> V_52 . V_37 = & V_34 -> V_48 -> V_43 ;
V_34 -> V_52 . V_53 = true ;
if ( V_34 -> V_48 -> V_54 == V_55 )
V_23 = V_34 -> V_48 ;
if ( V_34 -> V_48 -> V_54 == V_56 )
V_26 = V_34 -> V_48 ;
if ( V_34 -> V_48 -> V_54 == V_57 )
V_28 = V_34 -> V_48 ;
V_33 += F_21 ( V_34 -> V_48 ) ;
F_22 ( V_14 , V_34 -> V_48 ) ;
}
for ( V_32 = 0 ; V_32 < V_14 -> V_12 ; ++ V_32 )
F_19 ( & V_14 -> V_13 [ V_32 ] . V_48 ) ;
F_23 ( V_14 -> V_13 ) ;
V_14 -> V_23 = V_23 ;
V_14 -> V_26 = V_26 ;
V_14 -> V_28 = V_28 ;
V_14 -> V_31 = V_31 ;
V_14 -> V_13 = V_13 ;
V_14 -> V_12 = V_12 ;
F_24 ( V_14 -> V_12 , V_33 ) ;
return 0 ;
V_42:
while ( V_32 -- )
F_19 ( & V_13 [ V_32 ] . V_48 ) ;
F_23 ( V_13 ) ;
return V_6 ;
}
struct V_3 *
F_25 ( struct V_1 * V_2 , int V_5 )
{
struct V_3 * V_4 ;
F_3 ( & V_2 -> V_9 ) ;
V_4 = F_9 ( & V_2 -> V_10 , V_5 ) ;
if ( V_4 )
F_3 ( & V_4 -> V_11 ) ;
F_5 ( & V_2 -> V_9 ) ;
return V_4 ;
}
void F_26 ( struct V_3 * V_14 ,
struct V_58 * V_59 )
{
struct V_58 V_60 [ V_61 ] ;
unsigned V_32 ;
for ( V_32 = 0 ; V_32 < V_61 ; V_32 ++ )
F_27 ( & V_60 [ V_32 ] ) ;
for ( V_32 = 0 ; V_32 < V_14 -> V_12 ; V_32 ++ ) {
unsigned V_49 = V_14 -> V_13 [ V_32 ] . V_49 ;
F_28 ( & V_14 -> V_13 [ V_32 ] . V_52 . V_62 ,
& V_60 [ V_49 ] ) ;
V_14 -> V_13 [ V_32 ] . V_63 = NULL ;
}
for ( V_32 = 0 ; V_32 < V_61 ; V_32 ++ )
F_29 ( & V_60 [ V_32 ] , V_59 ) ;
}
void F_30 ( struct V_3 * V_14 )
{
F_5 ( & V_14 -> V_11 ) ;
}
void F_11 ( struct V_3 * V_14 )
{
unsigned V_32 ;
for ( V_32 = 0 ; V_32 < V_14 -> V_12 ; ++ V_32 )
F_19 ( & V_14 -> V_13 [ V_32 ] . V_48 ) ;
F_31 ( & V_14 -> V_11 ) ;
F_23 ( V_14 -> V_13 ) ;
F_6 ( V_14 ) ;
}
int F_32 ( struct V_64 * V_65 , void * V_66 ,
struct V_17 * V_18 )
{
const T_1 V_67 = sizeof( struct V_19 ) ;
struct V_15 * V_16 = V_65 -> V_68 ;
struct V_1 * V_2 = V_18 -> V_69 ;
union V_70 * args = V_66 ;
T_1 V_71 = args -> V_72 . V_73 ;
const void T_2 * V_74 = ( const void * ) ( long ) args -> V_72 . V_75 ;
struct V_19 * V_20 ;
struct V_3 * V_14 ;
int V_6 ;
V_20 = F_13 ( args -> V_72 . V_76 ,
sizeof( struct V_19 ) ) ;
if ( ! V_20 )
return - V_8 ;
V_6 = - V_77 ;
if ( F_33 ( V_67 == args -> V_72 . V_78 ) ) {
unsigned long V_79 = args -> V_72 . V_76 *
args -> V_72 . V_78 ;
if ( F_34 ( V_20 , V_74 , V_79 ) )
goto V_42;
} else {
unsigned long V_79 = F_20 ( args -> V_72 . V_78 , V_67 ) ;
unsigned V_32 ;
memset ( V_20 , 0 , args -> V_72 . V_76 * V_67 ) ;
for ( V_32 = 0 ; V_32 < args -> V_72 . V_76 ; ++ V_32 ) {
if ( F_34 ( & V_20 [ V_32 ] , V_74 , V_79 ) )
goto V_42;
V_74 += args -> V_72 . V_78 ;
}
}
switch ( args -> V_72 . V_80 ) {
case V_81 :
V_6 = F_1 ( V_2 , & V_14 , & V_71 ) ;
if ( V_6 )
goto V_42;
V_6 = F_12 ( V_16 , V_18 , V_14 , V_20 ,
args -> V_72 . V_76 ) ;
F_30 ( V_14 ) ;
if ( V_6 )
goto V_42;
break;
case V_82 :
F_8 ( V_2 , V_71 ) ;
V_71 = 0 ;
break;
case V_83 :
V_6 = - V_41 ;
V_14 = F_25 ( V_2 , V_71 ) ;
if ( ! V_14 )
goto V_42;
V_6 = F_12 ( V_16 , V_18 , V_14 , V_20 ,
args -> V_72 . V_76 ) ;
F_30 ( V_14 ) ;
if ( V_6 )
goto V_42;
break;
default:
V_6 = - V_84 ;
goto V_42;
}
memset ( args , 0 , sizeof( * args ) ) ;
args -> V_85 . V_73 = V_71 ;
F_23 ( V_20 ) ;
return 0 ;
V_42:
F_23 ( V_20 ) ;
return V_6 ;
}
