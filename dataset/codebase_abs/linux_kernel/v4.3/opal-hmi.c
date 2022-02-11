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
switch ( V_3 -> V_23 . V_24 . V_43 ) {
case V_44 :
F_1 ( V_1 , V_3 ) ;
break;
case V_45 :
F_5 ( V_1 , V_3 ) ;
break;
case V_46 :
F_2 ( L_39 , V_1 ) ;
break;
}
}
static void F_7 ( struct V_2 * V_3 )
{
const char * V_1 , * V_47 , * V_48 ;
static const char * V_49 [] = {
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
if ( V_3 -> V_50 < V_51 ) {
F_8 ( L_52 ,
V_3 -> V_50 ) ;
return;
}
switch ( V_3 -> V_52 ) {
case V_53 :
V_1 = V_54 ;
V_47 = L_53 ;
break;
case V_55 :
V_1 = V_56 ;
V_47 = L_54 ;
break;
case V_57 :
V_1 = V_58 ;
V_47 = L_55 ;
break;
case V_59 :
default:
V_1 = V_58 ;
V_47 = L_56 ;
break;
}
F_2 ( L_57 ,
V_1 , V_47 ,
V_3 -> V_60 == V_61 ?
L_58 : L_59 ) ;
V_48 = V_3 -> type < F_4 ( V_49 ) ?
V_49 [ V_3 -> type ]
: L_60 ;
F_2 ( L_61 , V_1 , V_48 ) ;
F_2 ( L_62 , V_1 , F_9 ( V_3 -> V_62 ) ) ;
if ( ( V_3 -> type == V_63 ) ||
( V_3 -> type == V_64 ) )
F_2 ( L_63 , V_1 ,
F_9 ( V_3 -> V_65 ) ) ;
if ( V_3 -> V_50 < V_66 )
return;
if ( V_3 -> type == V_67 )
F_6 ( V_1 , V_3 ) ;
}
static void F_10 ( struct V_68 * V_69 )
{
unsigned long V_70 ;
struct V_2 * V_3 ;
struct V_71 * V_72 ;
T_1 V_60 ;
struct V_73 V_74 ;
int V_75 = 0 ;
F_11 ( & V_76 , V_70 ) ;
while ( ! F_12 ( & V_77 ) ) {
V_72 = F_13 ( V_77 . V_78 ,
struct V_71 , V_79 ) ;
F_14 ( & V_72 -> V_79 ) ;
F_15 ( & V_76 , V_70 ) ;
V_3 = (struct V_2 * ) & V_72 -> V_3 ;
F_7 ( V_3 ) ;
V_60 = V_3 -> V_60 ;
F_16 ( V_72 ) ;
if ( V_60 != V_61 )
V_75 = 1 ;
F_11 ( & V_76 , V_70 ) ;
}
F_15 ( & V_76 , V_70 ) ;
if ( V_75 ) {
int V_80 ;
while ( F_17 ( F_18 ( & V_74 ) , sizeof( V_74 ) ) == V_81 ) {
T_2 type ;
type = F_3 ( V_74 . V_82 ) ;
if ( type != V_83 )
continue;
V_3 = (struct V_2 * ) & V_74 . V_84 [ 0 ] ;
F_7 ( V_3 ) ;
}
V_80 = F_19 ( V_85 ,
L_64 ) ;
if ( V_80 == V_86 ) {
F_20 ( L_65 ,
V_85 ) ;
}
F_21 ( L_64 ) ;
}
}
static int F_22 ( struct V_87 * V_88 ,
unsigned long V_82 , void * V_74 )
{
unsigned long V_70 ;
struct V_2 * V_3 ;
struct V_73 * V_89 = V_74 ;
struct V_71 * V_72 ;
if ( V_82 != V_83 )
return 0 ;
V_3 = (struct V_2 * ) & V_89 -> V_84 [ 0 ] ;
V_72 = F_23 ( sizeof( * V_72 ) , V_90 ) ;
if ( ! V_72 ) {
F_8 ( L_66 ) ;
return - V_91 ;
}
memcpy ( & V_72 -> V_3 , V_3 , sizeof( struct V_2 ) ) ;
F_11 ( & V_76 , V_70 ) ;
F_24 ( & V_72 -> V_79 , & V_77 ) ;
F_15 ( & V_76 , V_70 ) ;
F_25 ( & V_92 ) ;
return 0 ;
}
int T_3 F_26 ( void )
{
int V_80 ;
if ( ! V_93 ) {
V_80 = F_27 (
V_83 , & V_94 ) ;
if ( V_80 ) {
F_8 ( L_67 ,
V_95 , V_80 ) ;
return V_80 ;
}
V_93 = 1 ;
}
return 0 ;
}
