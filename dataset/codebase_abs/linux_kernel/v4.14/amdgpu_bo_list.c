static void F_1 ( struct V_1 * V_2 )
{
unsigned V_3 ;
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 ,
V_6 ) ;
for ( V_3 = 0 ; V_3 < V_5 -> V_7 ; ++ V_3 )
F_3 ( & V_5 -> V_8 [ V_3 ] . V_9 ) ;
F_4 ( & V_5 -> V_10 ) ;
F_5 ( V_5 -> V_8 ) ;
F_6 ( V_5 , V_11 ) ;
}
static int F_7 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
struct V_16 * V_17 ,
unsigned V_7 ,
int * V_18 )
{
int V_19 ;
struct V_20 * V_21 = V_15 -> V_22 ;
struct V_4 * V_5 ;
V_5 = F_8 ( sizeof( struct V_4 ) , V_23 ) ;
if ( ! V_5 )
return - V_24 ;
F_9 ( & V_5 -> V_10 ) ;
F_10 ( & V_5 -> V_6 ) ;
V_19 = F_11 ( V_13 , V_15 , V_5 , V_17 , V_7 ) ;
if ( V_19 ) {
F_12 ( V_5 ) ;
return V_19 ;
}
F_13 ( & V_21 -> V_25 ) ;
V_19 = F_14 ( & V_21 -> V_26 , V_5 , 1 , 0 , V_23 ) ;
F_15 ( & V_21 -> V_25 ) ;
if ( V_19 < 0 ) {
F_16 ( V_5 ) ;
return V_19 ;
}
* V_18 = V_19 ;
return 0 ;
}
static void F_17 ( struct V_20 * V_21 , int V_18 )
{
struct V_4 * V_5 ;
F_13 ( & V_21 -> V_25 ) ;
V_5 = F_18 ( & V_21 -> V_26 , V_18 ) ;
F_15 ( & V_21 -> V_25 ) ;
if ( V_5 )
F_19 ( & V_5 -> V_6 , F_1 ) ;
}
static int F_11 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
struct V_4 * V_5 ,
struct V_16 * V_17 ,
unsigned V_7 )
{
struct V_27 * V_8 ;
struct V_28 * V_29 = V_13 -> V_30 . V_31 ;
struct V_28 * V_32 = V_13 -> V_30 . V_33 ;
struct V_28 * V_34 = V_13 -> V_30 . V_35 ;
unsigned V_36 = 0 , V_37 = V_7 ;
unsigned V_3 ;
int V_19 ;
unsigned long V_38 = 0 ;
V_8 = F_20 ( V_7 , sizeof( struct V_27 ) , V_23 ) ;
if ( ! V_8 )
return - V_24 ;
memset ( V_8 , 0 , V_7 * sizeof( struct V_27 ) ) ;
for ( V_3 = 0 ; V_3 < V_7 ; ++ V_3 ) {
struct V_27 * V_39 ;
struct V_40 * V_41 ;
struct V_28 * V_42 ;
struct V_43 * V_44 ;
V_41 = F_21 ( V_15 , V_17 [ V_3 ] . V_45 ) ;
if ( ! V_41 ) {
V_19 = - V_46 ;
goto V_47;
}
V_42 = F_22 ( F_23 ( V_41 ) ) ;
F_24 ( V_41 ) ;
V_44 = F_25 ( V_42 -> V_48 . V_49 ) ;
if ( V_44 ) {
if ( V_44 != V_50 -> V_51 ) {
F_3 ( & V_42 ) ;
V_19 = - V_52 ;
goto V_47;
}
V_39 = & V_8 [ -- V_37 ] ;
} else {
V_39 = & V_8 [ V_36 ++ ] ;
}
V_39 -> V_9 = V_42 ;
V_39 -> V_53 = F_26 ( V_17 [ V_3 ] . V_54 ,
V_55 ) ;
V_39 -> V_56 . V_42 = & V_39 -> V_9 -> V_48 ;
V_39 -> V_56 . V_57 = ! V_39 -> V_9 -> V_58 ;
if ( V_39 -> V_9 -> V_59 == V_60 )
V_29 = V_39 -> V_9 ;
if ( V_39 -> V_9 -> V_59 == V_61 )
V_32 = V_39 -> V_9 ;
if ( V_39 -> V_9 -> V_59 == V_62 )
V_34 = V_39 -> V_9 ;
V_38 += F_27 ( V_39 -> V_9 ) ;
F_28 ( V_5 , V_39 -> V_9 ) ;
}
for ( V_3 = 0 ; V_3 < V_5 -> V_7 ; ++ V_3 )
F_3 ( & V_5 -> V_8 [ V_3 ] . V_9 ) ;
F_5 ( V_5 -> V_8 ) ;
V_5 -> V_29 = V_29 ;
V_5 -> V_32 = V_32 ;
V_5 -> V_34 = V_34 ;
V_5 -> V_37 = V_37 ;
V_5 -> V_8 = V_8 ;
V_5 -> V_7 = V_7 ;
F_29 ( V_5 -> V_7 , V_38 ) ;
return 0 ;
V_47:
while ( V_3 -- )
F_3 ( & V_8 [ V_3 ] . V_9 ) ;
F_5 ( V_8 ) ;
return V_19 ;
}
struct V_4 *
F_30 ( struct V_20 * V_21 , int V_18 )
{
struct V_4 * V_63 ;
F_31 () ;
V_63 = F_32 ( & V_21 -> V_26 , V_18 ) ;
if ( V_63 ) {
if ( F_33 ( & V_63 -> V_6 ) ) {
F_34 () ;
F_13 ( & V_63 -> V_10 ) ;
} else {
F_34 () ;
V_63 = NULL ;
}
} else {
F_34 () ;
}
return V_63 ;
}
void F_35 ( struct V_4 * V_5 ,
struct V_64 * V_65 )
{
struct V_64 V_66 [ V_67 ] ;
unsigned V_3 ;
for ( V_3 = 0 ; V_3 < V_67 ; V_3 ++ )
F_36 ( & V_66 [ V_3 ] ) ;
for ( V_3 = 0 ; V_3 < V_5 -> V_7 ; V_3 ++ ) {
unsigned V_53 = V_5 -> V_8 [ V_3 ] . V_53 ;
F_37 ( & V_5 -> V_8 [ V_3 ] . V_56 . V_68 ,
& V_66 [ V_53 ] ) ;
V_5 -> V_8 [ V_3 ] . V_69 = NULL ;
}
for ( V_3 = 0 ; V_3 < V_67 ; V_3 ++ )
F_38 ( & V_66 [ V_3 ] , V_65 ) ;
}
void F_39 ( struct V_4 * V_5 )
{
F_15 ( & V_5 -> V_10 ) ;
F_19 ( & V_5 -> V_6 , F_1 ) ;
}
void F_16 ( struct V_4 * V_5 )
{
unsigned V_3 ;
for ( V_3 = 0 ; V_3 < V_5 -> V_7 ; ++ V_3 )
F_3 ( & V_5 -> V_8 [ V_3 ] . V_9 ) ;
F_4 ( & V_5 -> V_10 ) ;
F_5 ( V_5 -> V_8 ) ;
F_12 ( V_5 ) ;
}
int F_40 ( struct V_70 * V_71 , void * V_72 ,
struct V_14 * V_15 )
{
const T_1 V_73 = sizeof( struct V_16 ) ;
struct V_12 * V_13 = V_71 -> V_74 ;
struct V_20 * V_21 = V_15 -> V_22 ;
union V_75 * args = V_72 ;
T_1 V_76 = args -> V_77 . V_78 ;
const void T_2 * V_79 = F_41 ( args -> V_77 . V_80 ) ;
struct V_16 * V_17 ;
struct V_4 * V_5 ;
int V_19 ;
V_17 = F_20 ( args -> V_77 . V_81 ,
sizeof( struct V_16 ) , V_23 ) ;
if ( ! V_17 )
return - V_24 ;
V_19 = - V_82 ;
if ( F_42 ( V_73 == args -> V_77 . V_83 ) ) {
unsigned long V_84 = args -> V_77 . V_81 *
args -> V_77 . V_83 ;
if ( F_43 ( V_17 , V_79 , V_84 ) )
goto V_47;
} else {
unsigned long V_84 = F_26 ( args -> V_77 . V_83 , V_73 ) ;
unsigned V_3 ;
memset ( V_17 , 0 , args -> V_77 . V_81 * V_73 ) ;
for ( V_3 = 0 ; V_3 < args -> V_77 . V_81 ; ++ V_3 ) {
if ( F_43 ( & V_17 [ V_3 ] , V_79 , V_84 ) )
goto V_47;
V_79 += args -> V_77 . V_83 ;
}
}
switch ( args -> V_77 . V_85 ) {
case V_86 :
V_19 = F_7 ( V_13 , V_15 , V_17 , args -> V_77 . V_81 ,
& V_76 ) ;
if ( V_19 )
goto V_47;
break;
case V_87 :
F_17 ( V_21 , V_76 ) ;
V_76 = 0 ;
break;
case V_88 :
V_19 = - V_46 ;
V_5 = F_30 ( V_21 , V_76 ) ;
if ( ! V_5 )
goto V_47;
V_19 = F_11 ( V_13 , V_15 , V_5 , V_17 ,
args -> V_77 . V_81 ) ;
F_39 ( V_5 ) ;
if ( V_19 )
goto V_47;
break;
default:
V_19 = - V_89 ;
goto V_47;
}
memset ( args , 0 , sizeof( * args ) ) ;
args -> V_90 . V_78 = V_76 ;
F_5 ( V_17 ) ;
return 0 ;
V_47:
F_5 ( V_17 ) ;
return V_19 ;
}
