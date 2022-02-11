static void F_1 ( const char * V_1 ,
struct V_2 * V_3 )
{
int V_4 ;
static const struct V_5 V_5 [] = {
{ V_6 , L_1 ,
L_2 } ,
{ V_7 , L_1 , L_3 } ,
{ V_8 , L_4 ,
L_5 } ,
{ V_9 , L_6 ,
L_7 } ,
{ V_10 , L_6 , L_3 } ,
{ V_11 , L_8 , L_3 } ,
{ V_12 , L_9 , L_3 } ,
{ V_13 , L_4 ,
L_10 } ,
{ V_14 , L_11 ,
L_2 } ,
{ V_15 , L_4 ,
L_12 } ,
{ V_16 , L_11 , L_3 } ,
{ V_17 , L_4 , L_3 } ,
{ V_18 , L_4 ,
L_13 } ,
{ V_19 , L_4 ,
L_14 } ,
{ V_20 , L_4 ,
L_15 } ,
{ V_21 , L_4 ,
L_16 } ,
{ V_22 , L_4 ,
L_17 } ,
} ;
if ( ! V_3 -> V_23 . V_24 . V_5 ) {
F_2 ( L_18 , V_1 ) ;
return;
}
F_2 ( L_19 , V_1 ,
F_3 ( V_3 -> V_23 . V_24 . V_23 . V_25 ) ) ;
for ( V_4 = 0 ; V_4 < F_4 ( V_5 ) ; V_4 ++ )
if ( F_3 ( V_3 -> V_23 . V_24 . V_5 ) &
V_5 [ V_4 ] . V_5 )
F_2 ( L_20 , V_1 ,
V_5 [ V_4 ] . V_26 ,
V_5 [ V_4 ] . V_27 ) ;
}
static void F_5 ( const char * V_1 ,
struct V_2 * V_3 )
{
int V_4 ;
static const struct V_5 V_5 [] = {
{ V_28 , L_21 ,
L_22 } ,
{ V_29 , L_21 ,
L_23 } ,
{ V_30 , L_21 ,
L_24 } ,
{ V_31 , L_21 ,
L_25 } ,
{ V_32 , L_21 ,
L_26 } ,
{ V_33 , L_21 ,
L_27 } ,
{ V_34 , L_21 ,
L_28 } ,
{ V_35 , L_21 ,
L_29 } ,
{ V_36 , L_21 ,
L_30 } ,
{ V_37 , L_21 ,
L_31 } ,
{ V_38 , L_21 ,
L_32 } ,
{ V_39 , L_21 ,
L_33 } ,
{ V_40 , L_21 ,
L_34 } ,
{ V_41 , L_35 ,
L_36 } ,
} ;
if ( ! V_3 -> V_23 . V_24 . V_5 ) {
F_2 ( L_37 , V_1 ) ;
return;
}
F_2 ( L_38 , V_1 ,
F_3 ( V_3 -> V_23 . V_24 . V_23 . V_42 ) ) ;
for ( V_4 = 0 ; V_4 < F_4 ( V_5 ) ; V_4 ++ )
if ( F_3 ( V_3 -> V_23 . V_24 . V_5 ) &
V_5 [ V_4 ] . V_5 )
F_2 ( L_20 , V_1 ,
V_5 [ V_4 ] . V_26 ,
V_5 [ V_4 ] . V_27 ) ;
}
static void F_6 ( const char * V_1 ,
struct V_2 * V_3 )
{
T_1 type = V_3 -> V_23 . V_24 . V_43 ;
switch ( type ) {
case V_44 :
F_1 ( V_1 , V_3 ) ;
break;
case V_45 :
F_5 ( V_1 , V_3 ) ;
break;
default:
F_2 ( L_39 ,
V_1 , type ) ;
break;
}
}
static void F_7 ( struct V_2 * V_3 )
{
const char * V_1 , * V_46 , * V_47 ;
static const char * V_48 [] = {
L_40 ,
L_41 ,
L_42 ,
L_43 ,
L_44 ,
L_45 ,
L_46 ,
L_47 ,
L_48 ,
L_49 ,
L_50 ,
L_51
} ;
if ( V_3 -> V_49 < V_50 ) {
F_8 ( L_52 ,
V_3 -> V_49 ) ;
return;
}
switch ( V_3 -> V_51 ) {
case V_52 :
V_1 = V_53 ;
V_46 = L_53 ;
break;
case V_54 :
V_1 = V_55 ;
V_46 = L_54 ;
break;
case V_56 :
V_1 = V_57 ;
V_46 = L_55 ;
break;
case V_58 :
default:
V_1 = V_57 ;
V_46 = L_56 ;
break;
}
F_2 ( L_57 ,
V_1 , V_46 ,
V_3 -> V_59 == V_60 ?
L_58 : L_59 ) ;
V_47 = V_3 -> type < F_4 ( V_48 ) ?
V_48 [ V_3 -> type ]
: L_60 ;
F_2 ( L_61 , V_1 , V_47 ) ;
F_2 ( L_62 , V_1 , F_9 ( V_3 -> V_61 ) ) ;
if ( ( V_3 -> type == V_62 ) ||
( V_3 -> type == V_63 ) )
F_2 ( L_63 , V_1 ,
F_9 ( V_3 -> V_64 ) ) ;
if ( V_3 -> V_49 < V_65 )
return;
if ( V_3 -> type == V_66 )
F_6 ( V_1 , V_3 ) ;
}
static void F_10 ( struct V_67 * V_68 )
{
unsigned long V_69 ;
struct V_2 * V_3 ;
struct V_70 * V_71 ;
T_1 V_59 ;
struct V_72 V_73 ;
int V_74 = 0 ;
F_11 ( & V_75 , V_69 ) ;
while ( ! F_12 ( & V_76 ) ) {
V_71 = F_13 ( V_76 . V_77 ,
struct V_70 , V_78 ) ;
F_14 ( & V_71 -> V_78 ) ;
F_15 ( & V_75 , V_69 ) ;
V_3 = (struct V_2 * ) & V_71 -> V_3 ;
F_7 ( V_3 ) ;
V_59 = V_3 -> V_59 ;
F_16 ( V_71 ) ;
if ( V_59 != V_60 )
V_74 = 1 ;
F_11 ( & V_75 , V_69 ) ;
}
F_15 ( & V_75 , V_69 ) ;
if ( V_74 ) {
int V_79 ;
while ( F_17 ( F_18 ( & V_73 ) , sizeof( V_73 ) ) == V_80 ) {
T_2 type ;
type = F_3 ( V_73 . V_81 ) ;
if ( type != V_82 )
continue;
V_3 = (struct V_2 * ) & V_73 . V_83 [ 0 ] ;
F_7 ( V_3 ) ;
}
V_79 = F_19 ( V_84 ,
L_64 ) ;
if ( V_79 == V_85 ) {
F_20 ( L_65 ,
V_84 ) ;
}
F_21 ( L_64 ) ;
}
}
static int F_22 ( struct V_86 * V_87 ,
unsigned long V_81 , void * V_73 )
{
unsigned long V_69 ;
struct V_2 * V_3 ;
struct V_72 * V_88 = V_73 ;
struct V_70 * V_71 ;
if ( V_81 != V_82 )
return 0 ;
V_3 = (struct V_2 * ) & V_88 -> V_83 [ 0 ] ;
V_71 = F_23 ( sizeof( * V_71 ) , V_89 ) ;
if ( ! V_71 ) {
F_8 ( L_66 ) ;
return - V_90 ;
}
memcpy ( & V_71 -> V_3 , V_3 , sizeof( struct V_2 ) ) ;
F_11 ( & V_75 , V_69 ) ;
F_24 ( & V_71 -> V_78 , & V_76 ) ;
F_15 ( & V_75 , V_69 ) ;
F_25 ( & V_91 ) ;
return 0 ;
}
int T_3 F_26 ( void )
{
int V_79 ;
if ( ! V_92 ) {
V_79 = F_27 (
V_82 , & V_93 ) ;
if ( V_79 ) {
F_8 ( L_67 ,
V_94 , V_79 ) ;
return V_79 ;
}
V_92 = 1 ;
}
return 0 ;
}
