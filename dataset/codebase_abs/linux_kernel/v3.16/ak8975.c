static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_5 , T_1 V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
T_1 V_11 ;
int V_12 ;
V_11 = ( V_10 -> V_13 [ V_3 ] & ~ V_5 ) | ( V_4 << V_6 ) ;
V_12 = F_4 ( V_2 , V_3 , V_11 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_1 , V_12 ) ;
return V_12 ;
}
V_10 -> V_13 [ V_3 ] = V_11 ;
return 0 ;
}
static T_2 F_6 ( int V_15 , void * V_10 )
{
struct V_9 * V_16 = V_10 ;
F_7 ( 0 , & V_16 -> V_17 ) ;
F_8 ( & V_16 -> V_18 ) ;
return V_19 ;
}
static int F_9 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_20 ;
int V_15 ;
if ( V_2 -> V_15 )
V_15 = V_2 -> V_15 ;
else
V_15 = F_10 ( V_10 -> V_21 ) ;
V_20 = F_11 ( V_15 , F_6 ,
V_22 | V_23 ,
F_12 ( & V_2 -> V_14 ) , V_10 ) ;
if ( V_20 < 0 ) {
F_5 ( & V_2 -> V_14 ,
L_2 ,
V_15 , V_10 -> V_21 , V_20 ) ;
return V_20 ;
}
F_13 ( & V_10 -> V_18 ) ;
F_14 ( 0 , & V_10 -> V_17 ) ;
V_10 -> V_24 = V_15 ;
return V_20 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
T_1 V_25 ;
int V_12 ;
V_12 = F_16 ( V_2 , V_26 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_3 ) ;
return V_12 ;
}
V_25 = V_12 ;
if ( V_25 != V_27 ) {
F_5 ( & V_2 -> V_14 , L_4 ) ;
return - V_28 ;
}
V_12 = F_1 ( V_2 ,
V_29 ,
V_30 ,
V_31 ,
V_32 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_5 ) ;
return V_12 ;
}
V_12 = F_17 ( V_2 , V_33 ,
3 , V_10 -> V_34 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_6 ) ;
return V_12 ;
}
V_12 = F_1 ( V_2 ,
V_29 ,
V_35 ,
V_31 ,
V_32 ) ;
if ( V_10 -> V_21 > 0 || V_2 -> V_15 ) {
V_12 = F_9 ( V_10 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 ,
L_7 ) ;
return V_12 ;
}
}
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_8 ) ;
return V_12 ;
}
if ( V_10 -> V_36 == V_37 ) {
V_10 -> V_38 [ 0 ] = F_18 ( V_10 -> V_34 [ 0 ] ) ;
V_10 -> V_38 [ 1 ] = F_18 ( V_10 -> V_34 [ 1 ] ) ;
V_10 -> V_38 [ 2 ] = F_18 ( V_10 -> V_34 [ 2 ] ) ;
} else {
V_10 -> V_38 [ 0 ] = F_19 ( V_10 -> V_34 [ 0 ] ) ;
V_10 -> V_38 [ 1 ] = F_19 ( V_10 -> V_34 [ 1 ] ) ;
V_10 -> V_38 [ 2 ] = F_19 ( V_10 -> V_34 [ 2 ] ) ;
}
return 0 ;
}
static int F_20 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_3 V_39 = V_40 ;
int V_12 ;
while ( V_39 ) {
F_21 ( V_41 ) ;
if ( F_22 ( V_10 -> V_21 ) )
break;
V_39 -= V_41 ;
}
if ( ! V_39 ) {
F_5 ( & V_2 -> V_14 , L_9 ) ;
return - V_42 ;
}
V_12 = F_16 ( V_2 , V_43 ) ;
if ( V_12 < 0 )
F_5 ( & V_2 -> V_14 , L_10 ) ;
return V_12 ;
}
static int F_23 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_1 V_44 ;
T_3 V_39 = V_40 ;
int V_12 ;
while ( V_39 ) {
F_21 ( V_41 ) ;
V_12 = F_16 ( V_2 , V_43 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_10 ) ;
return V_12 ;
}
V_44 = V_12 ;
if ( V_44 )
break;
V_39 -= V_41 ;
}
if ( ! V_39 ) {
F_5 ( & V_2 -> V_14 , L_9 ) ;
return - V_42 ;
}
return V_44 ;
}
static int F_24 ( struct V_9 * V_10 )
{
int V_12 ;
V_12 = F_25 ( V_10 -> V_18 ,
F_26 ( 0 , & V_10 -> V_17 ) ,
V_45 ) ;
F_14 ( 0 , & V_10 -> V_17 ) ;
return V_12 > 0 ? 0 : - V_46 ;
}
static int F_27 ( struct V_7 * V_8 , int V_47 , int * V_4 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_12 ;
F_28 ( & V_10 -> V_48 ) ;
V_12 = F_1 ( V_2 ,
V_29 ,
V_49 ,
V_31 ,
V_32 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_11 ) ;
goto exit;
}
if ( V_10 -> V_24 )
V_12 = F_24 ( V_10 ) ;
else if ( F_29 ( V_10 -> V_21 ) )
V_12 = F_20 ( V_10 ) ;
else
V_12 = F_23 ( V_10 ) ;
if ( V_12 < 0 )
goto exit;
if ( V_12 & V_50 ) {
V_12 = F_16 ( V_2 , V_51 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_12 ) ;
goto exit;
}
if ( V_12 & ( V_52 |
V_53 ) ) {
F_5 ( & V_2 -> V_14 , L_13 , V_12 ) ;
V_12 = - V_42 ;
goto exit;
}
}
V_12 = F_30 ( V_2 , V_54 [ V_47 ] ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_14 ) ;
goto exit;
}
F_31 ( & V_10 -> V_48 ) ;
* V_4 = F_32 ( V_55 , V_12 , - 4096 , 4095 ) ;
return V_56 ;
exit:
F_31 ( & V_10 -> V_48 ) ;
return V_12 ;
}
static int F_33 ( struct V_7 * V_8 ,
struct V_57 const * V_58 ,
int * V_4 , int * V_59 ,
long V_5 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
switch ( V_5 ) {
case V_60 :
return F_27 ( V_8 , V_58 -> V_61 , V_4 ) ;
case V_62 :
* V_4 = 0 ;
* V_59 = V_10 -> V_38 [ V_58 -> V_61 ] ;
return V_63 ;
}
return - V_42 ;
}
static char * F_34 ( struct V_64 * V_14 ,
enum V_65 * V_36 )
{
const struct V_66 * V_67 ;
V_67 = F_35 ( V_14 -> V_68 -> V_69 , V_14 ) ;
if ( ! V_67 )
return NULL ;
* V_36 = ( int ) V_67 -> V_70 ;
return ( char * ) F_12 ( V_14 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
const struct V_71 * V_67 )
{
struct V_9 * V_10 ;
struct V_7 * V_8 ;
int V_21 ;
int V_72 ;
char * V_73 = NULL ;
if ( V_2 -> V_14 . V_74 )
V_21 = * ( int * ) ( V_2 -> V_14 . V_74 ) ;
else if ( V_2 -> V_14 . V_75 )
V_21 = F_37 ( V_2 -> V_14 . V_75 , 0 ) ;
else
V_21 = - 1 ;
if ( V_21 == - V_76 )
return - V_76 ;
if ( F_29 ( V_21 ) ) {
V_72 = F_38 ( V_21 , V_77 , L_15 ) ;
if ( V_72 < 0 ) {
F_5 ( & V_2 -> V_14 ,
L_16 ,
V_21 , V_72 ) ;
goto exit;
}
}
V_8 = F_39 ( sizeof( * V_10 ) ) ;
if ( V_8 == NULL ) {
V_72 = - V_78 ;
goto V_79;
}
V_10 = F_3 ( V_8 ) ;
F_40 ( V_2 , V_8 ) ;
V_10 -> V_2 = V_2 ;
V_10 -> V_21 = V_21 ;
V_10 -> V_24 = 0 ;
if ( V_67 ) {
V_10 -> V_36 =
(enum V_65 ) ( V_67 -> V_70 ) ;
V_73 = ( char * ) V_67 -> V_73 ;
} else if ( F_41 ( & V_2 -> V_14 ) )
V_73 = F_34 ( & V_2 -> V_14 , & V_10 -> V_36 ) ;
else {
V_72 = - V_80 ;
goto V_81;
}
F_42 ( & V_2 -> V_14 , L_17 , V_73 ) ;
V_72 = F_15 ( V_2 ) ;
if ( V_72 < 0 ) {
F_5 ( & V_2 -> V_14 , L_18 ) ;
goto V_81;
}
V_10 -> V_2 = V_2 ;
F_43 ( & V_10 -> V_48 ) ;
V_10 -> V_21 = V_21 ;
V_8 -> V_14 . V_82 = & V_2 -> V_14 ;
V_8 -> V_83 = V_84 ;
V_8 -> V_85 = F_44 ( V_84 ) ;
V_8 -> V_86 = & V_87 ;
V_8 -> V_88 = V_89 ;
V_8 -> V_73 = V_73 ;
V_72 = F_45 ( V_8 ) ;
if ( V_72 < 0 )
goto V_81;
return 0 ;
V_81:
F_46 ( V_8 ) ;
if ( V_10 -> V_24 )
F_47 ( V_10 -> V_24 , V_10 ) ;
V_79:
if ( F_29 ( V_21 ) )
F_48 ( V_21 ) ;
exit:
return V_72 ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
F_50 ( V_8 ) ;
if ( V_10 -> V_24 )
F_47 ( V_10 -> V_24 , V_10 ) ;
if ( F_29 ( V_10 -> V_21 ) )
F_48 ( V_10 -> V_21 ) ;
F_46 ( V_8 ) ;
return 0 ;
}
