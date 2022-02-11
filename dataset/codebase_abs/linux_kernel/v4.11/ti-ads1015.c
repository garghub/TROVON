static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return ( V_3 == V_4 ) ;
}
static int F_2 ( struct V_5 * V_6 , bool V_7 )
{
int V_8 ;
struct V_1 * V_2 = F_3 ( V_6 -> V_9 ) ;
if ( V_7 ) {
V_8 = F_4 ( V_2 ) ;
if ( V_8 < 0 )
F_5 ( V_2 ) ;
} else {
F_6 ( V_2 ) ;
V_8 = F_7 ( V_2 ) ;
}
return V_8 ;
}
static
int F_8 ( struct V_5 * V_6 , int V_10 , int * V_11 )
{
int V_8 , V_12 , V_13 , V_14 ;
bool V_15 ;
if ( V_10 < 0 || V_10 >= V_16 )
return - V_17 ;
V_12 = V_6 -> V_18 [ V_10 ] . V_12 ;
V_13 = V_6 -> V_18 [ V_10 ] . V_19 ;
V_8 = F_9 ( V_6 -> V_9 , V_4 ,
V_20 |
V_21 ,
V_10 << V_22 |
V_12 << V_23 ,
& V_15 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_15 ) {
V_14 = F_10 ( V_24 , V_6 -> V_19 [ V_13 ] ) ;
F_11 ( V_14 , V_14 + 1 ) ;
}
return F_12 ( V_6 -> V_9 , V_25 , V_11 ) ;
}
static T_1 F_13 ( int V_26 , void * V_27 )
{
struct V_28 * V_29 = V_27 ;
struct V_30 * V_31 = V_29 -> V_31 ;
struct V_5 * V_6 = F_14 ( V_31 ) ;
T_2 V_32 [ 8 ] ;
int V_10 , V_8 , V_33 ;
memset ( V_32 , 0 , sizeof( V_32 ) ) ;
F_15 ( & V_6 -> V_34 ) ;
V_10 = F_16 ( V_31 -> V_35 ,
V_31 -> V_36 ) ;
V_8 = F_8 ( V_6 , V_10 , & V_33 ) ;
if ( V_8 < 0 ) {
F_17 ( & V_6 -> V_34 ) ;
goto V_37;
}
V_32 [ 0 ] = V_33 ;
F_17 ( & V_6 -> V_34 ) ;
F_18 ( V_31 , V_32 ,
F_19 ( V_31 ) ) ;
V_37:
F_20 ( V_31 -> V_38 ) ;
return V_39 ;
}
static int F_21 ( struct V_5 * V_6 , int V_10 ,
int V_40 , int V_41 )
{
int V_42 , V_8 , V_43 = - 1 ;
for ( V_42 = 0 ; V_42 < F_22 ( V_44 ) ; V_42 ++ )
if ( V_44 [ V_42 ] . V_40 == V_40 &&
V_44 [ V_42 ] . V_41 == V_41 ) {
V_43 = V_42 ;
break;
}
if ( V_43 < 0 )
return - V_17 ;
V_8 = F_23 ( V_6 -> V_9 , V_4 ,
V_21 ,
V_43 << V_23 ) ;
if ( V_8 < 0 )
return V_8 ;
V_6 -> V_18 [ V_10 ] . V_12 = V_43 ;
return 0 ;
}
static int F_24 ( struct V_5 * V_6 , int V_10 , int V_45 )
{
int V_42 , V_8 , V_43 = - 1 ;
for ( V_42 = 0 ; V_42 < F_22 ( V_46 ) ; V_42 ++ )
if ( V_6 -> V_19 [ V_42 ] == V_45 ) {
V_43 = V_42 ;
break;
}
if ( V_43 < 0 )
return - V_17 ;
V_8 = F_23 ( V_6 -> V_9 , V_4 ,
V_47 ,
V_43 << V_48 ) ;
if ( V_8 < 0 )
return V_8 ;
V_6 -> V_18 [ V_10 ] . V_19 = V_43 ;
return 0 ;
}
static int F_25 ( struct V_30 * V_31 ,
struct V_49 const * V_10 , int * V_11 ,
int * V_50 , long V_51 )
{
int V_8 , V_52 ;
struct V_5 * V_6 = F_14 ( V_31 ) ;
F_15 ( & V_31 -> V_53 ) ;
F_15 ( & V_6 -> V_34 ) ;
switch ( V_51 ) {
case V_54 : {
int V_55 = V_10 -> V_56 . V_55 ;
if ( F_26 ( V_31 ) ) {
V_8 = - V_57 ;
break;
}
V_8 = F_2 ( V_6 , true ) ;
if ( V_8 < 0 )
break;
V_8 = F_8 ( V_6 , V_10 -> V_58 , V_11 ) ;
if ( V_8 < 0 ) {
F_2 ( V_6 , false ) ;
break;
}
* V_11 = F_27 ( * V_11 >> V_55 , 15 - V_55 ) ;
V_8 = F_2 ( V_6 , false ) ;
if ( V_8 < 0 )
break;
V_8 = V_59 ;
break;
}
case V_60 :
V_52 = V_6 -> V_18 [ V_10 -> V_58 ] . V_12 ;
* V_11 = V_44 [ V_52 ] . V_40 ;
* V_50 = V_44 [ V_52 ] . V_41 ;
V_8 = V_61 ;
break;
case V_62 :
V_52 = V_6 -> V_18 [ V_10 -> V_58 ] . V_19 ;
* V_11 = V_6 -> V_19 [ V_52 ] ;
V_8 = V_59 ;
break;
default:
V_8 = - V_17 ;
break;
}
F_17 ( & V_6 -> V_34 ) ;
F_17 ( & V_31 -> V_53 ) ;
return V_8 ;
}
static int F_28 ( struct V_30 * V_31 ,
struct V_49 const * V_10 , int V_11 ,
int V_50 , long V_51 )
{
struct V_5 * V_6 = F_14 ( V_31 ) ;
int V_8 ;
F_15 ( & V_6 -> V_34 ) ;
switch ( V_51 ) {
case V_60 :
V_8 = F_21 ( V_6 , V_10 -> V_58 , V_11 , V_50 ) ;
break;
case V_62 :
V_8 = F_24 ( V_6 , V_10 -> V_58 , V_11 ) ;
break;
default:
V_8 = - V_17 ;
break;
}
F_17 ( & V_6 -> V_34 ) ;
return V_8 ;
}
static int F_29 ( struct V_30 * V_31 )
{
return F_2 ( F_14 ( V_31 ) , true ) ;
}
static int F_30 ( struct V_30 * V_31 )
{
return F_2 ( F_14 ( V_31 ) , false ) ;
}
static int F_31 ( struct V_63 * V_64 )
{
struct V_30 * V_31 = F_32 ( V_64 ) ;
struct V_5 * V_6 = F_14 ( V_31 ) ;
struct V_65 * V_66 ;
if ( ! V_64 -> V_2 . V_67 ||
! F_33 ( V_64 -> V_2 . V_67 , NULL ) )
return - V_17 ;
F_34 (client->dev.of_node, node) {
T_3 V_68 ;
unsigned int V_69 ;
unsigned int V_12 = V_70 ;
unsigned int V_19 = V_71 ;
if ( F_35 ( V_66 , L_1 , & V_68 ) ) {
F_36 ( & V_64 -> V_2 , L_2 ,
V_66 -> V_72 ) ;
continue;
}
V_69 = V_68 ;
if ( V_69 >= V_16 ) {
F_36 ( & V_64 -> V_2 ,
L_3 ,
V_69 , V_66 -> V_72 ) ;
continue;
}
if ( ! F_35 ( V_66 , L_4 , & V_68 ) ) {
V_12 = V_68 ;
if ( V_12 > 6 ) {
F_36 ( & V_64 -> V_2 , L_5 ,
V_66 -> V_72 ) ;
F_37 ( V_66 ) ;
return - V_17 ;
}
}
if ( ! F_35 ( V_66 , L_6 , & V_68 ) ) {
V_19 = V_68 ;
if ( V_19 > 7 ) {
F_36 ( & V_64 -> V_2 ,
L_7 ,
V_66 -> V_72 ) ;
F_37 ( V_66 ) ;
return - V_17 ;
}
}
V_6 -> V_18 [ V_69 ] . V_12 = V_12 ;
V_6 -> V_18 [ V_69 ] . V_19 = V_19 ;
}
return 0 ;
}
static void F_38 ( struct V_63 * V_64 )
{
unsigned int V_73 ;
struct V_30 * V_31 = F_32 ( V_64 ) ;
struct V_5 * V_6 = F_14 ( V_31 ) ;
struct V_74 * V_75 = F_39 ( & V_64 -> V_2 ) ;
if ( V_75 ) {
memcpy ( V_6 -> V_18 , V_75 -> V_18 ,
sizeof( V_6 -> V_18 ) ) ;
return;
}
#ifdef F_40
if ( ! F_31 ( V_64 ) )
return;
#endif
for ( V_73 = 0 ; V_73 < V_16 ; ++ V_73 ) {
V_6 -> V_18 [ V_73 ] . V_12 = V_70 ;
V_6 -> V_18 [ V_73 ] . V_19 = V_71 ;
}
}
static int F_41 ( struct V_63 * V_64 ,
const struct V_76 * V_77 )
{
struct V_30 * V_31 ;
struct V_5 * V_6 ;
int V_8 ;
V_31 = F_42 ( & V_64 -> V_2 , sizeof( * V_6 ) ) ;
if ( ! V_31 )
return - V_78 ;
V_6 = F_14 ( V_31 ) ;
F_43 ( V_64 , V_31 ) ;
F_44 ( & V_6 -> V_34 ) ;
V_31 -> V_2 . V_79 = & V_64 -> V_2 ;
V_31 -> V_2 . V_67 = V_64 -> V_2 . V_67 ;
V_31 -> V_80 = V_81 ;
V_31 -> V_82 = V_83 ;
switch ( V_77 -> V_84 ) {
case V_85 :
V_31 -> V_86 = V_87 ;
V_31 -> V_88 = F_22 ( V_87 ) ;
V_31 -> V_89 = & V_90 ;
V_6 -> V_19 = ( unsigned int * ) & V_46 ;
break;
case V_91 :
V_31 -> V_86 = V_92 ;
V_31 -> V_88 = F_22 ( V_92 ) ;
V_31 -> V_89 = & V_93 ;
V_6 -> V_19 = ( unsigned int * ) & V_94 ;
break;
}
F_38 ( V_64 ) ;
V_6 -> V_9 = F_45 ( V_64 , & V_95 ) ;
if ( F_46 ( V_6 -> V_9 ) ) {
F_36 ( & V_64 -> V_2 , L_8 ) ;
return F_47 ( V_6 -> V_9 ) ;
}
V_8 = F_48 ( V_31 , NULL ,
F_13 ,
& V_96 ) ;
if ( V_8 < 0 ) {
F_36 ( & V_64 -> V_2 , L_9 ) ;
return V_8 ;
}
V_8 = F_49 ( & V_64 -> V_2 ) ;
if ( V_8 )
goto V_97;
F_50 ( & V_64 -> V_2 , V_98 ) ;
F_51 ( & V_64 -> V_2 ) ;
F_52 ( & V_64 -> V_2 ) ;
V_8 = F_53 ( V_31 ) ;
if ( V_8 < 0 ) {
F_36 ( & V_64 -> V_2 , L_10 ) ;
goto V_97;
}
return 0 ;
V_97:
F_54 ( V_31 ) ;
return V_8 ;
}
static int F_55 ( struct V_63 * V_64 )
{
struct V_30 * V_31 = F_32 ( V_64 ) ;
struct V_5 * V_6 = F_14 ( V_31 ) ;
F_56 ( V_31 ) ;
F_57 ( & V_64 -> V_2 ) ;
F_58 ( & V_64 -> V_2 ) ;
F_5 ( & V_64 -> V_2 ) ;
F_54 ( V_31 ) ;
return F_23 ( V_6 -> V_9 , V_4 ,
V_99 ,
V_100 << V_101 ) ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = F_32 ( F_60 ( V_2 ) ) ;
struct V_5 * V_6 = F_14 ( V_31 ) ;
return F_23 ( V_6 -> V_9 , V_4 ,
V_99 ,
V_100 << V_101 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = F_32 ( F_60 ( V_2 ) ) ;
struct V_5 * V_6 = F_14 ( V_31 ) ;
return F_23 ( V_6 -> V_9 , V_4 ,
V_99 ,
V_102 << V_101 ) ;
}
