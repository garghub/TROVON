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
V_13 = F_13 ( V_12 , sizeof( struct V_21 ) ) ;
if ( ! V_13 )
return - V_8 ;
memset ( V_13 , 0 , V_12 * sizeof( struct V_21 ) ) ;
for ( V_32 = 0 ; V_32 < V_12 ; ++ V_32 ) {
struct V_21 * V_33 ;
struct V_34 * V_35 ;
struct V_22 * V_36 ;
struct V_37 * V_38 ;
V_35 = F_14 ( V_18 , V_20 [ V_32 ] . V_39 ) ;
if ( ! V_35 ) {
V_6 = - V_40 ;
goto V_41;
}
V_36 = F_15 ( F_16 ( V_35 ) ) ;
F_17 ( V_35 ) ;
V_38 = F_18 ( V_36 -> V_42 . V_43 ) ;
if ( V_38 ) {
if ( V_38 != V_44 -> V_45 ) {
F_19 ( & V_36 ) ;
V_6 = - V_46 ;
goto V_41;
}
V_33 = & V_13 [ -- V_31 ] ;
} else {
V_33 = & V_13 [ V_30 ++ ] ;
}
V_33 -> V_47 = V_36 ;
V_33 -> V_48 = F_20 ( V_20 [ V_32 ] . V_49 ,
V_50 ) ;
V_33 -> V_51 . V_36 = & V_33 -> V_47 -> V_42 ;
V_33 -> V_51 . V_52 = true ;
if ( V_33 -> V_47 -> V_53 == V_54 )
V_23 = V_33 -> V_47 ;
if ( V_33 -> V_47 -> V_53 == V_55 )
V_26 = V_33 -> V_47 ;
if ( V_33 -> V_47 -> V_53 == V_56 )
V_28 = V_33 -> V_47 ;
F_21 ( V_14 , V_33 -> V_47 ) ;
}
for ( V_32 = 0 ; V_32 < V_14 -> V_12 ; ++ V_32 )
F_19 ( & V_14 -> V_13 [ V_32 ] . V_47 ) ;
F_22 ( V_14 -> V_13 ) ;
V_14 -> V_23 = V_23 ;
V_14 -> V_26 = V_26 ;
V_14 -> V_28 = V_28 ;
V_14 -> V_31 = V_31 ;
V_14 -> V_13 = V_13 ;
V_14 -> V_12 = V_12 ;
return 0 ;
V_41:
while ( V_32 -- )
F_19 ( & V_13 [ V_32 ] . V_47 ) ;
F_22 ( V_13 ) ;
return V_6 ;
}
struct V_3 *
F_23 ( struct V_1 * V_2 , int V_5 )
{
struct V_3 * V_4 ;
F_3 ( & V_2 -> V_9 ) ;
V_4 = F_9 ( & V_2 -> V_10 , V_5 ) ;
if ( V_4 )
F_3 ( & V_4 -> V_11 ) ;
F_5 ( & V_2 -> V_9 ) ;
return V_4 ;
}
void F_24 ( struct V_3 * V_14 ,
struct V_57 * V_58 )
{
struct V_57 V_59 [ V_60 ] ;
unsigned V_32 ;
for ( V_32 = 0 ; V_32 < V_60 ; V_32 ++ )
F_25 ( & V_59 [ V_32 ] ) ;
for ( V_32 = 0 ; V_32 < V_14 -> V_12 ; V_32 ++ ) {
unsigned V_48 = V_14 -> V_13 [ V_32 ] . V_48 ;
F_26 ( & V_14 -> V_13 [ V_32 ] . V_51 . V_61 ,
& V_59 [ V_48 ] ) ;
V_14 -> V_13 [ V_32 ] . V_62 = NULL ;
}
for ( V_32 = 0 ; V_32 < V_60 ; V_32 ++ )
F_27 ( & V_59 [ V_32 ] , V_58 ) ;
}
void F_28 ( struct V_3 * V_14 )
{
F_5 ( & V_14 -> V_11 ) ;
}
void F_11 ( struct V_3 * V_14 )
{
unsigned V_32 ;
for ( V_32 = 0 ; V_32 < V_14 -> V_12 ; ++ V_32 )
F_19 ( & V_14 -> V_13 [ V_32 ] . V_47 ) ;
F_29 ( & V_14 -> V_11 ) ;
F_22 ( V_14 -> V_13 ) ;
F_6 ( V_14 ) ;
}
int F_30 ( struct V_63 * V_64 , void * V_65 ,
struct V_17 * V_18 )
{
const T_1 V_66 = sizeof( struct V_19 ) ;
struct V_15 * V_16 = V_64 -> V_67 ;
struct V_1 * V_2 = V_18 -> V_68 ;
union V_69 * args = V_65 ;
T_1 V_70 = args -> V_71 . V_72 ;
const void T_2 * V_73 = ( const void * ) ( long ) args -> V_71 . V_74 ;
struct V_19 * V_20 ;
struct V_3 * V_14 ;
int V_6 ;
V_20 = F_13 ( args -> V_71 . V_75 ,
sizeof( struct V_19 ) ) ;
if ( ! V_20 )
return - V_8 ;
V_6 = - V_76 ;
if ( F_31 ( V_66 == args -> V_71 . V_77 ) ) {
unsigned long V_78 = args -> V_71 . V_75 *
args -> V_71 . V_77 ;
if ( F_32 ( V_20 , V_73 , V_78 ) )
goto V_41;
} else {
unsigned long V_78 = F_20 ( args -> V_71 . V_77 , V_66 ) ;
unsigned V_32 ;
memset ( V_20 , 0 , args -> V_71 . V_75 * V_66 ) ;
for ( V_32 = 0 ; V_32 < args -> V_71 . V_75 ; ++ V_32 ) {
if ( F_32 ( & V_20 [ V_32 ] , V_73 , V_78 ) )
goto V_41;
V_73 += args -> V_71 . V_77 ;
}
}
switch ( args -> V_71 . V_79 ) {
case V_80 :
V_6 = F_1 ( V_2 , & V_14 , & V_70 ) ;
if ( V_6 )
goto V_41;
V_6 = F_12 ( V_16 , V_18 , V_14 , V_20 ,
args -> V_71 . V_75 ) ;
F_28 ( V_14 ) ;
if ( V_6 )
goto V_41;
break;
case V_81 :
F_8 ( V_2 , V_70 ) ;
V_70 = 0 ;
break;
case V_82 :
V_6 = - V_40 ;
V_14 = F_23 ( V_2 , V_70 ) ;
if ( ! V_14 )
goto V_41;
V_6 = F_12 ( V_16 , V_18 , V_14 , V_20 ,
args -> V_71 . V_75 ) ;
F_28 ( V_14 ) ;
if ( V_6 )
goto V_41;
break;
default:
V_6 = - V_83 ;
goto V_41;
}
memset ( args , 0 , sizeof( * args ) ) ;
args -> V_84 . V_72 = V_70 ;
F_22 ( V_20 ) ;
return 0 ;
V_41:
F_22 ( V_20 ) ;
return V_6 ;
}
