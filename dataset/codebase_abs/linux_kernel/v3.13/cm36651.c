static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_3 * V_5 = V_2 -> V_5 ;
int V_6 , V_7 ;
V_2 -> V_8 [ V_9 ] = V_10 |
V_11 ;
V_2 -> V_8 [ V_12 ] = V_13 ;
for ( V_6 = 0 ; V_6 < V_14 ; V_6 ++ ) {
V_7 = F_2 ( V_4 , V_15 [ V_6 ] ,
V_2 -> V_8 [ V_6 ] ) ;
if ( V_7 < 0 )
return V_7 ;
}
V_2 -> V_16 [ V_17 ] = V_18 |
V_19 ;
V_2 -> V_16 [ V_20 ] = V_21 ;
V_2 -> V_16 [ V_22 ] = V_23 ;
V_2 -> V_16 [ V_24 ] = V_25 |
V_26 | V_27 ;
for ( V_6 = 0 ; V_6 < V_28 ; V_6 ++ ) {
V_7 = F_2 ( V_5 , V_29 [ V_6 ] ,
V_2 -> V_16 [ V_6 ] ) ;
if ( V_7 < 0 )
return V_7 ;
}
V_7 = F_2 ( V_4 , V_9 ,
V_30 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_2 ( V_2 -> V_5 ,
V_17 , V_31 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_32 const * V_33 , int * V_34 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_7 = - V_35 ;
switch ( V_33 -> type ) {
case V_36 :
* V_34 = F_4 ( V_4 , V_33 -> V_37 ) ;
if ( * V_34 < 0 )
return V_7 ;
V_7 = F_2 ( V_4 , V_9 ,
V_30 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = V_38 ;
break;
case V_39 :
* V_34 = F_5 ( V_2 -> V_5 ) ;
if ( * V_34 < 0 )
return V_7 ;
if ( ! F_6 ( V_40 , & V_2 -> V_41 ) ) {
V_7 = F_2 ( V_2 -> V_5 ,
V_17 , V_31 ) ;
if ( V_7 < 0 )
return V_7 ;
}
V_7 = V_38 ;
break;
default:
break;
}
return V_7 ;
}
static T_1 F_7 ( int V_42 , void * V_43 )
{
struct V_44 * V_45 = V_43 ;
struct V_1 * V_2 = F_8 ( V_45 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_46 , V_7 ;
T_2 V_47 ;
V_7 = F_5 ( V_2 -> V_48 ) ;
if ( V_7 < 0 ) {
F_9 ( & V_4 -> V_49 ,
L_1 , V_50 , V_7 ) ;
return V_51 ;
}
switch ( V_7 ) {
case V_52 :
V_46 = V_53 ;
break;
case V_54 :
V_46 = V_55 ;
break;
default:
F_9 ( & V_4 -> V_49 ,
L_2 , V_50 , V_7 ) ;
return V_51 ;
}
V_47 = F_10 ( V_39 ,
V_56 ,
V_57 , V_46 ) ;
F_11 ( V_45 , V_47 , F_12 () ) ;
return V_51 ;
}
static int F_13 ( struct V_1 * V_2 , int V_58 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_3 * V_5 = V_2 -> V_5 ;
int V_7 = - V_35 ;
switch ( V_58 ) {
case V_59 :
V_7 = F_2 ( V_4 , V_9 ,
V_2 -> V_8 [ V_9 ] ) ;
break;
case V_56 :
if ( F_6 ( V_40 , & V_2 -> V_41 ) )
return V_40 ;
V_7 = F_2 ( V_5 , V_17 ,
V_2 -> V_16 [ V_17 ] ) ;
break;
case V_60 :
if ( F_6 ( V_40 , & V_2 -> V_41 ) ) {
F_9 ( & V_4 -> V_49 ,
L_3 ) ;
return V_7 ;
}
F_14 ( V_40 , & V_2 -> V_41 ) ;
V_7 = F_2 ( V_5 ,
V_29 [ V_17 ] ,
V_61 | V_62 | V_19 ) ;
if ( V_7 < 0 ) {
F_9 ( & V_4 -> V_49 , L_4 ) ;
return V_7 ;
}
break;
case V_63 :
if ( ! F_6 ( V_40 , & V_2 -> V_41 ) ) {
F_9 ( & V_4 -> V_49 ,
L_5 ) ;
return V_7 ;
}
F_15 ( V_40 , & V_2 -> V_41 ) ;
V_7 = F_2 ( V_5 ,
V_17 , V_31 ) ;
break;
}
if ( V_7 < 0 )
F_9 ( & V_4 -> V_49 , L_6 ) ;
return V_7 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_32 const * V_33 , int * V_34 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_58 , V_7 ;
if ( V_33 -> type == V_36 )
V_58 = V_59 ;
else if ( V_33 -> type == V_39 )
V_58 = V_56 ;
else
return - V_35 ;
V_7 = F_13 ( V_2 , V_58 ) ;
if ( V_7 < 0 ) {
F_9 ( & V_4 -> V_49 , L_7 ) ;
return V_7 ;
}
F_17 ( 50 ) ;
V_7 = F_3 ( V_2 , V_33 , V_34 ) ;
if ( V_7 < 0 ) {
F_9 ( & V_4 -> V_49 , L_8 ) ;
return V_7 ;
}
return V_7 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_32 const * V_33 , int * V_34 )
{
switch ( V_33 -> type ) {
case V_36 :
if ( V_2 -> V_64 [ V_33 -> V_37 ] == V_65 )
* V_34 = 80000 ;
else if ( V_2 -> V_64 [ V_33 -> V_37 ] == V_66 )
* V_34 = 160000 ;
else if ( V_2 -> V_64 [ V_33 -> V_37 ] == V_67 )
* V_34 = 320000 ;
else if ( V_2 -> V_64 [ V_33 -> V_37 ] == V_68 )
* V_34 = 640000 ;
else
return - V_35 ;
break;
case V_39 :
if ( V_2 -> V_69 == V_70 )
* V_34 = 320 ;
else if ( V_2 -> V_69 == V_19 )
* V_34 = 420 ;
else if ( V_2 -> V_69 == V_71 )
* V_34 = 520 ;
else if ( V_2 -> V_69 == V_72 )
* V_34 = 640 ;
else
return - V_35 ;
break;
default:
return - V_35 ;
}
return V_38 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_32 const * V_33 , int V_34 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_3 * V_5 = V_2 -> V_5 ;
int V_73 , V_7 ;
switch ( V_33 -> type ) {
case V_36 :
if ( V_34 == 80000 )
V_73 = V_65 ;
else if ( V_34 == 160000 )
V_73 = V_66 ;
else if ( V_34 == 320000 )
V_73 = V_67 ;
else if ( V_34 == 640000 )
V_73 = V_68 ;
else
return - V_35 ;
V_7 = F_2 ( V_4 , V_74 ,
V_73 >> 2 * ( V_33 -> V_37 ) ) ;
if ( V_7 < 0 ) {
F_9 ( & V_4 -> V_49 , L_9 ) ;
return V_7 ;
}
V_2 -> V_64 [ V_33 -> V_37 ] = V_73 ;
break;
case V_39 :
if ( V_34 == 320 )
V_73 = V_70 ;
else if ( V_34 == 420 )
V_73 = V_19 ;
else if ( V_34 == 520 )
V_73 = V_71 ;
else if ( V_34 == 640 )
V_73 = V_72 ;
else
return - V_35 ;
V_7 = F_2 ( V_5 ,
V_17 , V_73 ) ;
if ( V_7 < 0 ) {
F_9 ( & V_4 -> V_49 , L_10 ) ;
return V_7 ;
}
V_2 -> V_69 = V_73 ;
break;
default:
return - V_35 ;
}
return V_7 ;
}
static int F_20 ( struct V_44 * V_45 ,
struct V_32 const * V_33 ,
int * V_34 , int * V_75 , long V_76 )
{
struct V_1 * V_2 = F_8 ( V_45 ) ;
int V_7 ;
F_21 ( & V_2 -> V_77 ) ;
switch ( V_76 ) {
case V_78 :
V_7 = F_16 ( V_2 , V_33 , V_34 ) ;
break;
case V_79 :
V_7 = F_18 ( V_2 , V_33 , V_34 ) ;
break;
default:
V_7 = - V_35 ;
}
F_22 ( & V_2 -> V_77 ) ;
return V_7 ;
}
static int F_23 ( struct V_44 * V_45 ,
struct V_32 const * V_33 ,
int V_34 , int V_75 , long V_76 )
{
struct V_1 * V_2 = F_8 ( V_45 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_7 = - V_35 ;
if ( V_76 == V_79 ) {
V_7 = F_19 ( V_2 , V_33 , V_34 ) ;
if ( V_7 < 0 )
F_9 ( & V_4 -> V_49 , L_11 ) ;
}
return V_7 ;
}
static int F_24 ( struct V_44 * V_45 ,
T_2 V_80 , int * V_34 )
{
struct V_1 * V_2 = F_8 ( V_45 ) ;
* V_34 = V_2 -> V_16 [ V_20 ] ;
return 0 ;
}
static int F_25 ( struct V_44 * V_45 ,
T_2 V_80 , int V_34 )
{
struct V_1 * V_2 = F_8 ( V_45 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_7 ;
if ( V_34 < 3 || V_34 > 255 )
return - V_35 ;
V_2 -> V_16 [ V_20 ] = V_34 ;
V_7 = F_2 ( V_2 -> V_5 , V_20 ,
V_2 -> V_16 [ V_20 ] ) ;
if ( V_7 < 0 ) {
F_9 ( & V_4 -> V_49 , L_12 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
static int F_26 ( struct V_44 * V_45 ,
T_2 V_80 , int V_81 )
{
struct V_1 * V_2 = F_8 ( V_45 ) ;
int V_58 , V_7 = - V_35 ;
F_21 ( & V_2 -> V_77 ) ;
V_58 = V_81 ? V_60 : V_63 ;
V_7 = F_13 ( V_2 , V_58 ) ;
F_22 ( & V_2 -> V_77 ) ;
return V_7 ;
}
static int F_27 ( struct V_44 * V_45 ,
T_2 V_80 )
{
struct V_1 * V_2 = F_8 ( V_45 ) ;
int V_82 ;
F_21 ( & V_2 -> V_77 ) ;
V_82 = F_6 ( V_40 , & V_2 -> V_41 ) ;
F_22 ( & V_2 -> V_77 ) ;
return V_82 ;
}
static int F_28 ( struct V_3 * V_4 ,
const struct V_83 * V_84 )
{
struct V_1 * V_2 ;
struct V_44 * V_45 ;
int V_7 ;
V_45 = F_29 ( & V_4 -> V_49 , sizeof( * V_2 ) ) ;
if ( ! V_45 )
return - V_85 ;
V_2 = F_8 ( V_45 ) ;
V_2 -> V_86 = F_30 ( & V_4 -> V_49 , L_13 ) ;
if ( F_31 ( V_2 -> V_86 ) ) {
F_9 ( & V_4 -> V_49 , L_14 ) ;
return F_32 ( V_2 -> V_86 ) ;
}
V_7 = F_33 ( V_2 -> V_86 ) ;
if ( V_7 ) {
F_9 ( & V_4 -> V_49 , L_15 ) ;
return V_7 ;
}
F_34 ( V_4 , V_45 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = F_35 ( V_4 -> V_87 ,
V_88 ) ;
V_2 -> V_48 = F_35 ( V_4 -> V_87 , V_89 ) ;
F_36 ( & V_2 -> V_77 ) ;
V_45 -> V_49 . V_90 = & V_4 -> V_49 ;
V_45 -> V_91 = V_92 ;
V_45 -> V_93 = F_37 ( V_92 ) ;
V_45 -> V_94 = & V_95 ;
V_45 -> V_96 = V_84 -> V_96 ;
V_45 -> V_97 = V_98 ;
V_7 = F_1 ( V_2 ) ;
if ( V_7 ) {
F_9 ( & V_4 -> V_49 , L_16 , V_50 ) ;
goto V_99;
}
V_7 = F_38 ( V_4 -> V_42 , NULL , F_7 ,
V_100 | V_101 ,
L_17 , V_45 ) ;
if ( V_7 ) {
F_9 ( & V_4 -> V_49 , L_18 , V_50 ) ;
goto V_99;
}
V_7 = F_39 ( V_45 ) ;
if ( V_7 ) {
F_9 ( & V_4 -> V_49 , L_19 , V_50 ) ;
goto V_102;
}
return 0 ;
V_102:
F_40 ( V_4 -> V_42 , V_45 ) ;
V_99:
F_41 ( V_2 -> V_86 ) ;
return V_7 ;
}
static int F_42 ( struct V_3 * V_4 )
{
struct V_44 * V_45 = F_43 ( V_4 ) ;
struct V_1 * V_2 = F_8 ( V_45 ) ;
F_44 ( V_45 ) ;
F_41 ( V_2 -> V_86 ) ;
F_40 ( V_4 -> V_42 , V_45 ) ;
return 0 ;
}
