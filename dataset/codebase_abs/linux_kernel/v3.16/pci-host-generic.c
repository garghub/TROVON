static void T_1 * F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
T_2 V_11 = V_2 -> V_12 - V_9 -> V_13 . V_14 . V_15 ;
return V_9 -> V_13 . V_16 [ V_11 ] + ( ( V_3 << 8 ) | V_4 ) ;
}
static void T_1 * F_2 ( struct V_1 * V_2 ,
unsigned int V_3 ,
int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
T_2 V_11 = V_2 -> V_12 - V_9 -> V_13 . V_14 . V_15 ;
return V_9 -> V_13 . V_16 [ V_11 ] + ( ( V_3 << 12 ) | V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_17 , T_3 * V_18 )
{
void T_1 * V_19 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
V_19 = V_9 -> V_13 . V_20 -> V_21 ( V_2 , V_3 , V_4 ) ;
switch ( V_17 ) {
case 1 :
* V_18 = F_4 ( V_19 ) ;
break;
case 2 :
* V_18 = F_5 ( V_19 ) ;
break;
default:
* V_18 = F_6 ( V_19 ) ;
}
return V_22 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_17 , T_3 V_18 )
{
void T_1 * V_19 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
V_19 = V_9 -> V_13 . V_20 -> V_21 ( V_2 , V_3 , V_4 ) ;
switch ( V_17 ) {
case 1 :
F_8 ( V_18 , V_19 ) ;
break;
case 2 :
F_9 ( V_18 , V_19 ) ;
break;
default:
F_10 ( V_18 , V_19 ) ;
}
return V_22 ;
}
static int F_11 ( struct V_23 * V_24 ,
struct V_25 * V_26 ,
struct V_27 * V_28 ,
T_2 * V_29 )
{
static T_4 V_30 = F_12 ( 0 ) ;
int V_31 , V_11 , V_32 ;
unsigned int V_33 ;
if ( ! F_13 ( V_26 -> V_34 ) )
return - V_35 ;
V_32 = ( V_36 + 1 ) / V_37 ;
V_11 = F_14 ( & V_30 ) ;
if ( V_11 > V_32 )
return - V_38 ;
V_33 = ( V_11 - 1 ) * V_37 ;
V_31 = F_15 ( V_33 , V_26 -> V_34 ) ;
if ( V_31 )
return V_31 ;
F_16 ( V_26 , V_24 -> V_39 , V_28 ) ;
V_28 -> V_15 = V_33 ;
V_28 -> V_40 = V_28 -> V_15 + V_26 -> V_17 - 1 ;
* V_29 = V_33 - V_26 -> V_41 ;
return 0 ;
}
static int F_17 ( struct V_23 * V_24 ,
struct V_25 * V_26 ,
struct V_27 * V_28 ,
T_2 * V_29 )
{
F_16 ( V_26 , V_24 -> V_39 , V_28 ) ;
* V_29 = V_26 -> V_34 - V_26 -> V_41 ;
return 0 ;
}
static void F_18 ( struct V_8 * V_9 )
{
struct V_42 * V_16 ;
F_19 (win, &pci->resources, list)
F_20 ( V_16 -> V_28 ) ;
F_21 ( & V_9 -> V_43 ) ;
}
static int F_22 ( struct V_8 * V_9 )
{
struct V_25 V_26 ;
struct V_44 V_45 ;
int V_31 , V_46 = 0 ;
struct V_23 * V_24 = V_9 -> V_47 . V_24 . V_48 ;
struct V_49 * V_50 = V_24 -> V_39 ;
if ( F_23 ( & V_45 , V_50 ) ) {
F_24 ( V_24 , L_1 ) ;
return - V_35 ;
}
F_25 (&parser, &range) {
struct V_27 * V_48 , * V_28 ;
T_2 V_29 ;
T_3 V_51 = V_26 . V_52 & V_53 ;
V_28 = F_26 ( V_24 , sizeof( * V_28 ) , V_54 ) ;
if ( ! V_28 ) {
V_31 = - V_55 ;
goto V_56;
}
switch ( V_51 ) {
case V_57 :
V_48 = & V_58 ;
V_31 = F_11 ( V_24 , & V_26 , V_28 , & V_29 ) ;
break;
case V_59 :
V_48 = & V_60 ;
V_31 = F_17 ( V_24 , & V_26 , V_28 , & V_29 ) ;
V_46 |= ! ( V_28 -> V_52 & V_61 || V_31 ) ;
break;
default:
V_31 = - V_35 ;
continue;
}
if ( V_31 ) {
F_27 ( V_24 ,
L_2 ,
V_31 , V_51 , V_26 . V_17 ) ;
continue;
}
V_31 = F_28 ( V_48 , V_28 ) ;
if ( V_31 )
goto V_56;
F_29 ( & V_9 -> V_43 , V_28 , V_29 ) ;
}
if ( ! V_46 ) {
F_24 ( V_24 , L_3 ) ;
V_31 = - V_35 ;
goto V_56;
}
return 0 ;
V_56:
F_18 ( V_9 ) ;
return V_31 ;
}
static int F_30 ( struct V_8 * V_9 )
{
int V_31 ;
T_5 V_62 ;
T_2 V_63 ;
struct V_27 * V_14 ;
struct V_23 * V_24 = V_9 -> V_47 . V_24 . V_48 ;
struct V_49 * V_50 = V_24 -> V_39 ;
if ( F_31 ( V_50 , & V_9 -> V_13 . V_14 ) )
V_9 -> V_13 . V_14 = (struct V_27 ) {
. V_64 = V_50 -> V_64 ,
. V_15 = 0 ,
. V_40 = 0xff ,
. V_52 = V_65 ,
} ;
V_31 = F_32 ( V_50 , 0 , & V_9 -> V_13 . V_28 ) ;
if ( V_31 ) {
F_24 ( V_24 , L_4 ) ;
return V_31 ;
}
V_9 -> V_13 . V_16 = F_33 ( V_24 , F_34 ( & V_9 -> V_13 . V_14 ) ,
sizeof( * V_9 -> V_13 . V_16 ) , V_54 ) ;
if ( ! V_9 -> V_13 . V_16 )
return - V_55 ;
V_62 = V_9 -> V_13 . V_14 . V_15 +
( F_34 ( & V_9 -> V_13 . V_28 ) >> V_9 -> V_13 . V_20 -> V_66 ) - 1 ;
V_9 -> V_13 . V_14 . V_40 = F_35 ( T_2 , V_9 -> V_13 . V_14 . V_40 ,
V_62 ) ;
if ( ! F_36 ( V_24 , V_9 -> V_13 . V_28 . V_15 ,
F_34 ( & V_9 -> V_13 . V_28 ) ,
L_5 ) )
return - V_55 ;
V_14 = & V_9 -> V_13 . V_14 ;
for ( V_63 = V_14 -> V_15 ; V_63 <= V_14 -> V_40 ; ++ V_63 ) {
T_3 V_11 = V_63 - V_14 -> V_15 ;
T_3 V_67 = 1 << V_9 -> V_13 . V_20 -> V_66 ;
V_9 -> V_13 . V_16 [ V_11 ] = F_37 ( V_24 ,
V_9 -> V_13 . V_28 . V_15 + V_63 * V_67 ,
V_67 ) ;
if ( ! V_9 -> V_13 . V_16 [ V_11 ] )
return - V_55 ;
}
F_38 ( & V_9 -> V_43 , V_14 ) ;
return 0 ;
}
static int F_39 ( int V_68 , struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_40 ( & V_9 -> V_43 , & V_6 -> V_43 ) ;
return 1 ;
}
static int F_41 ( struct V_69 * V_70 )
{
int V_31 ;
const char * type ;
const struct V_71 * V_72 ;
const int * V_73 ;
struct V_23 * V_24 = & V_70 -> V_24 ;
struct V_49 * V_50 = V_24 -> V_39 ;
struct V_8 * V_9 = F_42 ( V_24 , sizeof( * V_9 ) , V_54 ) ;
struct V_74 V_75 = {
. V_76 = 1 ,
. V_10 = ( void * * ) & V_9 ,
. V_77 = F_39 ,
. V_78 = V_79 ,
. V_20 = & V_80 ,
} ;
if ( ! V_9 )
return - V_55 ;
type = F_43 ( V_50 , L_6 , NULL ) ;
if ( ! type || strcmp ( type , L_7 ) ) {
F_24 ( V_24 , L_8 , type ) ;
return - V_35 ;
}
V_73 = F_43 ( V_81 , L_9 , NULL ) ;
if ( V_73 ) {
if ( * V_73 )
F_44 ( V_82 ) ;
else
F_45 ( V_82 ) ;
}
V_72 = F_46 ( V_83 , V_50 ) ;
V_9 -> V_13 . V_20 = V_72 -> V_84 ;
V_9 -> V_47 . V_24 . V_48 = V_24 ;
F_47 ( & V_9 -> V_47 . V_85 ) ;
F_47 ( & V_9 -> V_43 ) ;
V_31 = F_22 ( V_9 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_30 ( V_9 ) ;
if ( V_31 ) {
F_18 ( V_9 ) ;
return V_31 ;
}
F_48 ( V_24 , & V_75 ) ;
return 0 ;
}
