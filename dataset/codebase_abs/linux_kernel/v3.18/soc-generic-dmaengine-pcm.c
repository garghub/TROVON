static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static struct V_5 * F_3 ( struct V_1 * V_6 ,
struct V_7 * V_8 )
{
if ( ! V_6 -> V_9 [ V_8 -> V_10 ] )
return NULL ;
return V_6 -> V_9 [ V_8 -> V_10 ] -> V_5 -> V_11 ;
}
int F_4 ( struct V_7 * V_8 ,
struct V_12 * V_13 , struct V_14 * V_15 )
{
struct V_16 * V_17 = V_8 -> V_18 ;
struct V_19 * V_20 ;
int V_21 ;
V_20 = F_5 ( V_17 -> V_22 , V_8 ) ;
V_21 = F_6 ( V_8 , V_13 , V_15 ) ;
if ( V_21 )
return V_21 ;
F_7 ( V_8 , V_20 ,
V_15 ) ;
return 0 ;
}
static int F_8 ( struct V_7 * V_8 ,
struct V_12 * V_13 )
{
struct V_16 * V_17 = V_8 -> V_18 ;
struct V_1 * V_6 = F_1 ( V_17 -> V_4 ) ;
struct V_23 * V_9 = F_9 ( V_8 ) ;
int (* F_10)( struct V_7 * V_8 ,
struct V_12 * V_13 ,
struct V_14 * V_15 );
struct V_14 V_15 ;
int V_21 ;
memset ( & V_15 , 0 , sizeof( V_15 ) ) ;
if ( ! V_6 -> V_24 )
F_10 = F_4 ;
else
F_10 = V_6 -> V_24 -> F_10 ;
if ( F_10 ) {
V_21 = F_10 ( V_8 , V_13 , & V_15 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_11 ( V_9 , & V_15 ) ;
if ( V_21 )
return V_21 ;
}
return F_12 ( V_8 , F_13 ( V_13 ) ) ;
}
static int F_14 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = V_8 -> V_18 ;
struct V_1 * V_6 = F_1 ( V_17 -> V_4 ) ;
struct V_5 * V_25 = F_3 ( V_6 , V_8 ) ;
struct V_23 * V_9 = V_6 -> V_9 [ V_8 -> V_10 ] ;
struct V_19 * V_20 ;
struct V_26 V_27 ;
struct V_28 V_29 ;
T_1 V_30 = F_15 ( V_31 ) |
F_15 ( V_32 ) |
F_15 ( V_33 ) ;
int V_34 , V_21 ;
if ( V_6 -> V_24 && V_6 -> V_24 -> V_35 )
return F_16 ( V_8 ,
V_6 -> V_24 -> V_35 ) ;
V_20 = F_5 ( V_17 -> V_22 , V_8 ) ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
V_29 . V_36 = V_37 | V_38 |
V_39 ;
V_29 . V_40 = 2 ;
V_29 . V_41 = V_42 ;
V_29 . V_43 = 256 ;
V_29 . V_44 = F_17 ( V_25 ) ;
V_29 . V_45 = V_46 ;
V_29 . V_47 = V_20 -> V_47 ;
if ( V_6 -> V_48 & V_49 )
V_29 . V_36 |= V_50 ;
V_21 = F_18 ( V_9 , & V_27 ) ;
if ( V_21 == 0 ) {
if ( V_27 . V_51 )
V_29 . V_36 |= V_52 | V_53 ;
if ( V_27 . V_54 <= V_55 )
V_29 . V_36 |= V_50 ;
if ( V_8 -> V_10 == V_56 )
V_30 = V_27 . V_57 ;
else
V_30 = V_27 . V_58 ;
}
for ( V_34 = 0 ; V_34 <= V_59 ; V_34 ++ ) {
int V_60 = F_19 ( V_34 ) ;
switch ( V_60 ) {
case 8 :
case 16 :
case 24 :
case 32 :
case 64 :
if ( V_30 & ( 1 << ( V_60 / 8 ) ) )
V_29 . V_61 |= ( 1LL << V_34 ) ;
break;
default:
break;
}
}
return F_16 ( V_8 , & V_29 ) ;
}
static int F_20 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = V_8 -> V_18 ;
struct V_1 * V_6 = F_1 ( V_17 -> V_4 ) ;
struct V_23 * V_9 = V_6 -> V_9 [ V_8 -> V_10 ] ;
int V_21 ;
V_21 = F_14 ( V_8 ) ;
if ( V_21 )
return V_21 ;
return F_21 ( V_8 , V_9 ) ;
}
static void F_22 ( struct V_62 * V_6 )
{
F_23 ( V_6 ) ;
}
static struct V_23 * F_24 (
struct V_16 * V_17 ,
struct V_7 * V_8 )
{
struct V_1 * V_6 = F_1 ( V_17 -> V_4 ) ;
struct V_19 * V_20 ;
T_2 V_63 = NULL ;
V_20 = F_5 ( V_17 -> V_22 , V_8 ) ;
if ( ( V_6 -> V_48 & V_64 ) && V_6 -> V_9 [ 0 ] )
return V_6 -> V_9 [ 0 ] ;
if ( V_6 -> V_24 && V_6 -> V_24 -> V_65 )
return V_6 -> V_24 -> V_65 ( V_17 , V_8 ) ;
if ( V_6 -> V_24 )
V_63 = V_6 -> V_24 -> V_66 ;
return F_25 ( V_63 , V_20 -> V_67 ) ;
}
static bool F_26 ( struct V_23 * V_9 )
{
struct V_26 V_27 ;
int V_21 ;
V_21 = F_18 ( V_9 , & V_27 ) ;
if ( V_21 != 0 )
return true ;
if ( V_27 . V_54 == V_68 )
return false ;
return true ;
}
static int F_27 ( struct V_16 * V_17 )
{
struct V_1 * V_6 = F_1 ( V_17 -> V_4 ) ;
const struct V_69 * V_24 = V_6 -> V_24 ;
struct V_5 * V_11 = V_17 -> V_4 -> V_11 ;
struct V_19 * V_20 ;
struct V_7 * V_8 ;
T_3 V_70 ;
T_3 V_71 ;
unsigned int V_34 ;
int V_21 ;
if ( V_24 && V_24 -> V_70 ) {
V_70 = V_24 -> V_70 ;
V_71 = V_24 -> V_35 -> V_45 ;
} else {
V_70 = 512 * 1024 ;
V_71 = V_46 ;
}
for ( V_34 = V_56 ; V_34 <= V_72 ; V_34 ++ ) {
V_8 = V_17 -> V_6 -> V_73 [ V_34 ] . V_8 ;
if ( ! V_8 )
continue;
V_20 = F_5 ( V_17 -> V_22 , V_8 ) ;
if ( ! V_6 -> V_9 [ V_34 ] &&
( V_6 -> V_48 & V_74 ) )
V_6 -> V_9 [ V_34 ] = F_28 ( V_11 ,
V_20 -> V_75 ) ;
if ( ! V_6 -> V_9 [ V_34 ] && ( V_6 -> V_48 & V_76 ) ) {
V_6 -> V_9 [ V_34 ] = F_24 ( V_17 ,
V_8 ) ;
}
if ( ! V_6 -> V_9 [ V_34 ] ) {
F_29 ( V_17 -> V_4 -> V_11 ,
L_1 , V_34 ) ;
V_21 = - V_77 ;
goto V_78;
}
V_21 = F_30 ( V_8 ,
V_79 ,
F_3 ( V_6 , V_8 ) ,
V_70 ,
V_71 ) ;
if ( V_21 )
goto V_78;
if ( ! F_26 ( V_6 -> V_9 [ V_34 ] ) )
V_6 -> V_48 |= V_49 ;
}
return 0 ;
V_78:
F_22 ( V_17 -> V_6 ) ;
return V_21 ;
}
static T_4 F_31 (
struct V_7 * V_8 )
{
struct V_16 * V_17 = V_8 -> V_18 ;
struct V_1 * V_6 = F_1 ( V_17 -> V_4 ) ;
if ( V_6 -> V_48 & V_49 )
return F_32 ( V_8 ) ;
else
return F_33 ( V_8 ) ;
}
static int F_34 ( struct V_1 * V_6 ,
struct V_5 * V_11 , const struct V_69 * V_24 )
{
unsigned int V_34 ;
const char * V_80 ;
struct V_23 * V_9 ;
if ( ( V_6 -> V_48 & ( V_81 |
V_74 ) ) ||
! V_11 -> V_82 )
return 0 ;
if ( V_24 && V_24 -> V_25 ) {
F_35 ( V_11 , L_2 ,
F_36 ( V_24 -> V_25 ) ) ;
V_11 = V_24 -> V_25 ;
}
for ( V_34 = V_56 ; V_34 <= V_72 ;
V_34 ++ ) {
if ( V_6 -> V_48 & V_64 )
V_80 = L_3 ;
else
V_80 = V_83 [ V_34 ] ;
if ( V_24 && V_24 -> V_84 [ V_34 ] )
V_80 = V_24 -> V_84 [ V_34 ] ;
V_9 = F_37 ( V_11 , V_80 ) ;
if ( F_38 ( V_9 ) ) {
if ( F_39 ( V_9 ) == - V_85 )
return - V_85 ;
V_6 -> V_9 [ V_34 ] = NULL ;
} else {
V_6 -> V_9 [ V_34 ] = V_9 ;
}
if ( V_6 -> V_48 & V_64 )
break;
}
if ( V_6 -> V_48 & V_64 )
V_6 -> V_9 [ 1 ] = V_6 -> V_9 [ 0 ] ;
return 0 ;
}
static void F_40 ( struct V_1 * V_6 )
{
unsigned int V_34 ;
for ( V_34 = V_56 ; V_34 <= V_72 ;
V_34 ++ ) {
if ( ! V_6 -> V_9 [ V_34 ] )
continue;
F_41 ( V_6 -> V_9 [ V_34 ] ) ;
if ( V_6 -> V_48 & V_64 )
break;
}
}
int F_42 ( struct V_5 * V_11 ,
const struct V_69 * V_24 , unsigned int V_48 )
{
struct V_1 * V_6 ;
int V_21 ;
V_6 = F_43 ( sizeof( * V_6 ) , V_86 ) ;
if ( ! V_6 )
return - V_87 ;
V_6 -> V_24 = V_24 ;
V_6 -> V_48 = V_48 ;
V_21 = F_34 ( V_6 , V_11 , V_24 ) ;
if ( V_21 )
goto V_88;
V_21 = F_44 ( V_11 , & V_6 -> V_4 ,
& V_89 ) ;
if ( V_21 )
goto V_88;
return 0 ;
V_88:
F_40 ( V_6 ) ;
F_45 ( V_6 ) ;
return V_21 ;
}
void F_46 ( struct V_5 * V_11 )
{
struct V_2 * V_4 ;
struct V_1 * V_6 ;
V_4 = F_47 ( V_11 ) ;
if ( ! V_4 )
return;
V_6 = F_1 ( V_4 ) ;
F_48 ( V_4 ) ;
F_40 ( V_6 ) ;
F_45 ( V_6 ) ;
}
