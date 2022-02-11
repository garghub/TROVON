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
V_14 = F_10 ( V_24 , V_25 [ V_13 ] ) ;
F_11 ( V_14 , V_14 + 1 ) ;
}
return F_12 ( V_6 -> V_9 , V_26 , V_11 ) ;
}
static T_1 F_13 ( int V_27 , void * V_28 )
{
struct V_29 * V_30 = V_28 ;
struct V_31 * V_32 = V_30 -> V_32 ;
struct V_5 * V_6 = F_14 ( V_32 ) ;
T_2 V_33 [ 8 ] ;
int V_10 , V_8 , V_34 ;
memset ( V_33 , 0 , sizeof( V_33 ) ) ;
F_15 ( & V_6 -> V_35 ) ;
V_10 = F_16 ( V_32 -> V_36 ,
V_32 -> V_37 ) ;
V_8 = F_8 ( V_6 , V_10 , & V_34 ) ;
if ( V_8 < 0 ) {
F_17 ( & V_6 -> V_35 ) ;
goto V_38;
}
V_33 [ 0 ] = V_34 ;
F_17 ( & V_6 -> V_35 ) ;
F_18 ( V_32 , V_33 , F_19 () ) ;
V_38:
F_20 ( V_32 -> V_39 ) ;
return V_40 ;
}
static int F_21 ( struct V_5 * V_6 , int V_10 ,
int V_41 , int V_42 )
{
int V_43 , V_8 , V_44 = - 1 ;
for ( V_43 = 0 ; V_43 < F_22 ( V_45 ) ; V_43 ++ )
if ( V_45 [ V_43 ] . V_41 == V_41 &&
V_45 [ V_43 ] . V_42 == V_42 ) {
V_44 = V_43 ;
break;
}
if ( V_44 < 0 )
return - V_17 ;
V_8 = F_23 ( V_6 -> V_9 , V_4 ,
V_21 ,
V_44 << V_23 ) ;
if ( V_8 < 0 )
return V_8 ;
V_6 -> V_18 [ V_10 ] . V_12 = V_44 ;
return 0 ;
}
static int F_24 ( struct V_5 * V_6 , int V_10 , int V_46 )
{
int V_43 , V_8 , V_44 = - 1 ;
for ( V_43 = 0 ; V_43 < F_22 ( V_25 ) ; V_43 ++ )
if ( V_25 [ V_43 ] == V_46 ) {
V_44 = V_43 ;
break;
}
if ( V_44 < 0 )
return - V_17 ;
V_8 = F_23 ( V_6 -> V_9 , V_4 ,
V_47 ,
V_44 << V_48 ) ;
if ( V_8 < 0 )
return V_8 ;
V_6 -> V_18 [ V_10 ] . V_19 = V_44 ;
return 0 ;
}
static int F_25 ( struct V_31 * V_32 ,
struct V_49 const * V_10 , int * V_11 ,
int * V_50 , long V_51 )
{
int V_8 , V_52 ;
struct V_5 * V_6 = F_14 ( V_32 ) ;
F_15 ( & V_32 -> V_53 ) ;
F_15 ( & V_6 -> V_35 ) ;
switch ( V_51 ) {
case V_54 :
if ( F_26 ( V_32 ) ) {
V_8 = - V_55 ;
break;
}
V_8 = F_2 ( V_6 , true ) ;
if ( V_8 < 0 )
break;
V_8 = F_8 ( V_6 , V_10 -> V_56 , V_11 ) ;
if ( V_8 < 0 ) {
F_2 ( V_6 , false ) ;
break;
}
* V_11 = F_27 ( * V_11 >> 4 , 11 ) ;
V_8 = F_2 ( V_6 , false ) ;
if ( V_8 < 0 )
break;
V_8 = V_57 ;
break;
case V_58 :
V_52 = V_6 -> V_18 [ V_10 -> V_56 ] . V_12 ;
* V_11 = V_45 [ V_52 ] . V_41 ;
* V_50 = V_45 [ V_52 ] . V_42 ;
V_8 = V_59 ;
break;
case V_60 :
V_52 = V_6 -> V_18 [ V_10 -> V_56 ] . V_19 ;
* V_11 = V_25 [ V_52 ] ;
V_8 = V_57 ;
break;
default:
V_8 = - V_17 ;
break;
}
F_17 ( & V_6 -> V_35 ) ;
F_17 ( & V_32 -> V_53 ) ;
return V_8 ;
}
static int F_28 ( struct V_31 * V_32 ,
struct V_49 const * V_10 , int V_11 ,
int V_50 , long V_51 )
{
struct V_5 * V_6 = F_14 ( V_32 ) ;
int V_8 ;
F_15 ( & V_6 -> V_35 ) ;
switch ( V_51 ) {
case V_58 :
V_8 = F_21 ( V_6 , V_10 -> V_56 , V_11 , V_50 ) ;
break;
case V_60 :
V_8 = F_24 ( V_6 , V_10 -> V_56 , V_11 ) ;
break;
default:
V_8 = - V_17 ;
break;
}
F_17 ( & V_6 -> V_35 ) ;
return V_8 ;
}
static int F_29 ( struct V_31 * V_32 )
{
return F_2 ( F_14 ( V_32 ) , true ) ;
}
static int F_30 ( struct V_31 * V_32 )
{
return F_2 ( F_14 ( V_32 ) , false ) ;
}
static int F_31 ( struct V_61 * V_62 )
{
struct V_5 * V_6 = F_32 ( V_62 ) ;
struct V_63 * V_64 ;
if ( ! V_62 -> V_2 . V_65 ||
! F_33 ( V_62 -> V_2 . V_65 , NULL ) )
return - V_17 ;
F_34 (client->dev.of_node, node) {
T_3 V_66 ;
unsigned int V_67 ;
unsigned int V_12 = V_68 ;
unsigned int V_19 = V_69 ;
if ( F_35 ( V_64 , L_1 , & V_66 ) ) {
F_36 ( & V_62 -> V_2 , L_2 ,
V_64 -> V_70 ) ;
continue;
}
V_67 = V_66 ;
if ( V_67 >= V_16 ) {
F_36 ( & V_62 -> V_2 ,
L_3 ,
V_67 , V_64 -> V_70 ) ;
continue;
}
if ( ! F_35 ( V_64 , L_4 , & V_66 ) ) {
V_12 = V_66 ;
if ( V_12 > 6 ) {
F_36 ( & V_62 -> V_2 , L_5 ,
V_64 -> V_70 ) ;
return - V_17 ;
}
}
if ( ! F_35 ( V_64 , L_6 , & V_66 ) ) {
V_19 = V_66 ;
if ( V_19 > 7 ) {
F_36 ( & V_62 -> V_2 ,
L_7 ,
V_64 -> V_70 ) ;
return - V_17 ;
}
}
V_6 -> V_18 [ V_67 ] . V_12 = V_12 ;
V_6 -> V_18 [ V_67 ] . V_19 = V_19 ;
}
return 0 ;
}
static void F_37 ( struct V_61 * V_62 )
{
unsigned int V_71 ;
struct V_31 * V_32 = F_32 ( V_62 ) ;
struct V_5 * V_6 = F_14 ( V_32 ) ;
struct V_72 * V_73 = F_38 ( & V_62 -> V_2 ) ;
if ( V_73 ) {
memcpy ( V_6 -> V_18 , V_73 -> V_18 ,
sizeof( V_6 -> V_18 ) ) ;
return;
}
#ifdef F_39
if ( ! F_31 ( V_62 ) )
return;
#endif
for ( V_71 = 0 ; V_71 < V_16 ; ++ V_71 ) {
V_6 -> V_18 [ V_71 ] . V_12 = V_68 ;
V_6 -> V_18 [ V_71 ] . V_19 = V_69 ;
}
}
static int F_40 ( struct V_61 * V_62 ,
const struct V_74 * V_75 )
{
struct V_31 * V_32 ;
struct V_5 * V_6 ;
int V_8 ;
V_32 = F_41 ( & V_62 -> V_2 , sizeof( * V_6 ) ) ;
if ( ! V_32 )
return - V_76 ;
V_6 = F_14 ( V_32 ) ;
F_42 ( V_62 , V_32 ) ;
F_43 ( & V_6 -> V_35 ) ;
V_32 -> V_2 . V_77 = & V_62 -> V_2 ;
V_32 -> V_78 = & V_79 ;
V_32 -> V_80 = V_81 ;
V_32 -> V_82 = V_83 ;
V_32 -> V_84 = F_22 ( V_83 ) ;
V_32 -> V_85 = V_86 ;
F_37 ( V_62 ) ;
V_6 -> V_9 = F_44 ( V_62 , & V_87 ) ;
if ( F_45 ( V_6 -> V_9 ) ) {
F_36 ( & V_62 -> V_2 , L_8 ) ;
return F_46 ( V_6 -> V_9 ) ;
}
V_8 = F_47 ( V_32 , NULL ,
F_13 ,
& V_88 ) ;
if ( V_8 < 0 ) {
F_36 ( & V_62 -> V_2 , L_9 ) ;
return V_8 ;
}
V_8 = F_48 ( & V_62 -> V_2 ) ;
if ( V_8 )
goto V_89;
F_49 ( & V_62 -> V_2 , V_90 ) ;
F_50 ( & V_62 -> V_2 ) ;
F_51 ( & V_62 -> V_2 ) ;
V_8 = F_52 ( V_32 ) ;
if ( V_8 < 0 ) {
F_36 ( & V_62 -> V_2 , L_10 ) ;
goto V_89;
}
return 0 ;
V_89:
F_53 ( V_32 ) ;
return V_8 ;
}
static int F_54 ( struct V_61 * V_62 )
{
struct V_31 * V_32 = F_32 ( V_62 ) ;
struct V_5 * V_6 = F_14 ( V_32 ) ;
F_55 ( V_32 ) ;
F_56 ( & V_62 -> V_2 ) ;
F_57 ( & V_62 -> V_2 ) ;
F_5 ( & V_62 -> V_2 ) ;
F_53 ( V_32 ) ;
return F_23 ( V_6 -> V_9 , V_4 ,
V_91 ,
V_92 << V_93 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = F_32 ( F_59 ( V_2 ) ) ;
struct V_5 * V_6 = F_14 ( V_32 ) ;
return F_23 ( V_6 -> V_9 , V_4 ,
V_91 ,
V_92 << V_93 ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = F_32 ( F_59 ( V_2 ) ) ;
struct V_5 * V_6 = F_14 ( V_32 ) ;
return F_23 ( V_6 -> V_9 , V_4 ,
V_91 ,
V_94 << V_93 ) ;
}
