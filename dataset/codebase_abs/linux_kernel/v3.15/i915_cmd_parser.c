static T_1 F_1 ( T_1 V_1 )
{
T_1 V_2 = ( V_1 & V_3 ) >> V_4 ;
T_1 V_5 =
( V_1 & V_6 ) >> V_7 ;
if ( V_2 == V_8 )
return 0x3F ;
else if ( V_2 == V_9 ) {
if ( V_5 == V_10 )
return 0xFFFF ;
else
return 0xFF ;
}
F_2 ( L_1 , V_1 ) ;
return 0 ;
}
static T_1 F_3 ( T_1 V_1 )
{
T_1 V_2 = ( V_1 & V_3 ) >> V_4 ;
T_1 V_5 =
( V_1 & V_6 ) >> V_7 ;
if ( V_2 == V_8 )
return 0x3F ;
else if ( V_2 == V_9 ) {
if ( V_5 == V_10 )
return 0xFFF ;
else
return 0xFF ;
}
F_2 ( L_2 , V_1 ) ;
return 0 ;
}
static T_1 F_4 ( T_1 V_1 )
{
T_1 V_2 = ( V_1 & V_3 ) >> V_4 ;
if ( V_2 == V_8 )
return 0x3F ;
else if ( V_2 == V_11 )
return 0xFF ;
F_2 ( L_3 , V_1 ) ;
return 0 ;
}
static void F_5 ( struct V_12 * V_13 )
{
int V_14 ;
if ( ! V_13 -> V_15 || V_13 -> V_16 == 0 )
return;
for ( V_14 = 0 ; V_14 < V_13 -> V_16 ; V_14 ++ ) {
const struct V_17 * V_18 = & V_13 -> V_15 [ V_14 ] ;
T_1 V_19 = 0 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_18 -> V_21 ; V_20 ++ ) {
const struct V_22 * V_23 =
& V_18 -> V_18 [ V_14 ] ;
T_1 V_24 = V_23 -> V_25 . V_26 & V_23 -> V_25 . V_27 ;
if ( V_24 < V_19 )
F_6 ( L_4 ,
V_13 -> V_28 , V_14 , V_20 , V_24 , V_19 ) ;
V_19 = V_24 ;
}
}
}
static void F_7 ( int V_29 , const T_1 * V_30 , int V_31 )
{
int V_14 ;
T_1 V_19 = 0 ;
for ( V_14 = 0 ; V_14 < V_31 ; V_14 ++ ) {
T_1 V_24 = V_30 [ V_14 ] ;
if ( V_24 < V_19 )
F_6 ( L_5 ,
V_29 , V_14 , V_24 , V_19 ) ;
V_19 = V_24 ;
}
}
static void F_8 ( struct V_12 * V_13 )
{
F_7 ( V_13 -> V_28 , V_13 -> V_30 , V_13 -> V_31 ) ;
F_7 ( V_13 -> V_28 , V_13 -> V_32 , V_13 -> V_33 ) ;
}
void F_9 ( struct V_12 * V_13 )
{
if ( ! F_10 ( V_13 -> V_34 ) )
return;
switch ( V_13 -> V_28 ) {
case V_35 :
V_13 -> V_36 = F_1 ;
break;
case V_37 :
V_13 -> V_36 = F_3 ;
break;
case V_38 :
V_13 -> V_36 = F_4 ;
break;
case V_39 :
V_13 -> V_36 = F_3 ;
break;
default:
F_6 ( L_6 ,
V_13 -> V_28 ) ;
F_11 () ;
}
F_5 ( V_13 ) ;
F_8 ( V_13 ) ;
}
static const struct V_22 *
F_12 ( const struct V_17 * V_18 ,
T_1 V_1 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_18 -> V_21 ; V_14 ++ ) {
const struct V_22 * V_23 = & V_18 -> V_18 [ V_14 ] ;
T_1 V_40 = V_23 -> V_25 . V_27 & V_1 ;
T_1 V_41 = V_23 -> V_25 . V_26 & V_23 -> V_25 . V_27 ;
if ( V_40 == V_41 )
return V_23 ;
}
return NULL ;
}
static const struct V_22 *
F_13 ( struct V_12 * V_13 ,
T_1 V_1 ,
struct V_22 * V_42 )
{
T_1 V_27 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_13 -> V_16 ; V_14 ++ ) {
const struct V_22 * V_23 ;
V_23 = F_12 ( & V_13 -> V_15 [ V_14 ] , V_1 ) ;
if ( V_23 )
return V_23 ;
}
V_27 = V_13 -> V_36 ( V_1 ) ;
if ( ! V_27 )
return NULL ;
F_14 ( ! V_42 ) ;
V_42 -> V_43 = V_44 ;
V_42 -> V_45 . V_27 = V_27 ;
return V_42 ;
}
static bool F_15 ( const T_1 * V_18 , int V_21 , T_1 V_46 )
{
if ( V_18 && V_21 != 0 ) {
int V_14 ;
for ( V_14 = 0 ; V_14 < V_21 ; V_14 ++ ) {
if ( V_18 [ V_14 ] == V_46 )
return true ;
}
}
return false ;
}
static T_1 * F_16 ( struct V_47 * V_48 )
{
int V_14 ;
void * V_46 = NULL ;
struct V_49 V_50 ;
struct V_51 * * V_52 ;
V_52 = F_17 ( V_48 -> V_53 . V_54 >> V_55 , sizeof( * V_52 ) ) ;
if ( V_52 == NULL ) {
F_2 ( L_7 ) ;
goto V_56;
}
V_14 = 0 ;
F_18 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
V_52 [ V_14 ] = F_19 ( & V_50 ) ;
V_14 ++ ;
}
V_46 = F_20 ( V_52 , V_14 , 0 , V_57 ) ;
if ( V_46 == NULL ) {
F_2 ( L_8 ) ;
goto V_56;
}
V_56:
if ( V_52 )
F_21 ( V_52 ) ;
return ( T_1 * ) V_46 ;
}
bool F_22 ( struct V_12 * V_13 )
{
if ( ! V_13 -> V_15 )
return false ;
return ( V_58 . V_59 == 1 ) ;
}
int F_23 ( struct V_12 * V_13 ,
struct V_47 * V_60 ,
T_1 V_61 ,
bool V_62 )
{
int V_63 = 0 ;
T_1 * V_25 , * V_64 , * V_65 ;
struct V_22 V_42 = { 0 } ;
int V_66 = 0 ;
V_63 = F_24 ( V_60 , & V_66 ) ;
if ( V_63 ) {
F_2 ( L_9 ) ;
return V_63 ;
}
V_64 = F_16 ( V_60 ) ;
if ( ! V_64 ) {
F_2 ( L_10 ) ;
F_25 ( V_60 ) ;
return - V_67 ;
}
if ( V_66 )
F_26 ( ( char * ) V_64 , V_60 -> V_53 . V_54 ) ;
V_25 = V_64 + ( V_61 / sizeof( * V_25 ) ) ;
V_65 = V_25 + ( V_60 -> V_53 . V_54 / sizeof( * V_65 ) ) ;
while ( V_25 < V_65 ) {
const struct V_22 * V_23 ;
T_1 V_45 ;
if ( * V_25 == V_68 )
break;
V_23 = F_13 ( V_13 , * V_25 , & V_42 ) ;
if ( ! V_23 ) {
F_2 ( L_11 ,
* V_25 ) ;
V_63 = - V_69 ;
break;
}
if ( V_23 -> V_43 & V_70 )
V_45 = V_23 -> V_45 . V_71 ;
else
V_45 = ( ( * V_25 & V_23 -> V_45 . V_27 ) + V_72 ) ;
if ( ( V_65 - V_25 ) < V_45 ) {
F_2 ( L_12 ,
* V_25 ,
V_45 ,
( unsigned long ) ( V_65 - V_25 ) ) ;
V_63 = - V_69 ;
break;
}
if ( V_23 -> V_43 & V_73 ) {
F_2 ( L_13 , * V_25 ) ;
V_63 = - V_69 ;
break;
}
if ( ( V_23 -> V_43 & V_74 ) && ! V_62 ) {
F_2 ( L_14 ,
* V_25 ) ;
V_63 = - V_69 ;
break;
}
if ( V_23 -> V_43 & V_75 ) {
T_1 V_76 = V_25 [ V_23 -> V_77 . V_78 ] & V_23 -> V_77 . V_27 ;
if ( ! F_15 ( V_13 -> V_30 ,
V_13 -> V_31 , V_76 ) ) {
if ( ! V_62 ||
! F_15 ( V_13 -> V_32 ,
V_13 -> V_33 ,
V_76 ) ) {
F_2 ( L_15 ,
V_76 ,
* V_25 ,
V_13 -> V_28 ) ;
V_63 = - V_69 ;
break;
}
}
}
if ( V_23 -> V_43 & V_79 ) {
int V_14 ;
for ( V_14 = 0 ; V_14 < V_80 ; V_14 ++ ) {
T_1 V_81 ;
if ( V_23 -> V_82 [ V_14 ] . V_27 == 0 )
break;
V_81 = V_25 [ V_23 -> V_82 [ V_14 ] . V_78 ] &
V_23 -> V_82 [ V_14 ] . V_27 ;
if ( V_81 != V_23 -> V_82 [ V_14 ] . V_83 ) {
F_2 ( L_16 ,
* V_25 ,
V_23 -> V_82 [ V_14 ] . V_27 ,
V_23 -> V_82 [ V_14 ] . V_83 ,
V_81 , V_13 -> V_28 ) ;
V_63 = - V_69 ;
break;
}
}
if ( V_63 )
break;
}
V_25 += V_45 ;
}
if ( V_25 >= V_65 ) {
F_2 ( L_17 ) ;
V_63 = - V_69 ;
}
F_27 ( V_64 ) ;
F_25 ( V_60 ) ;
return V_63 ;
}
