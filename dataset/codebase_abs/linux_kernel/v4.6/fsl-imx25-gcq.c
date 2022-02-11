static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
T_2 V_5 ;
F_2 ( V_4 -> V_6 , V_7 , & V_5 ) ;
if ( V_5 & V_8 ) {
F_3 ( V_4 -> V_6 , V_9 ,
V_10 , V_10 ) ;
F_4 ( & V_4 -> V_11 ) ;
}
F_3 ( V_4 -> V_6 , V_12 , V_13 , 0 ) ;
F_5 ( V_4 -> V_6 , V_7 , V_14 |
V_15 | V_16 |
V_8 | V_17 ) ;
return V_18 ;
}
static int F_6 ( struct V_19 * V_20 ,
struct V_21 const * V_22 ,
struct V_3 * V_4 ,
int * V_23 )
{
long V_24 ;
T_2 V_2 ;
F_5 ( V_4 -> V_6 , V_25 ,
F_7 ( 0 , V_22 -> V_26 ) ) ;
F_3 ( V_4 -> V_6 , V_9 , V_10 , 0 ) ;
F_3 ( V_4 -> V_6 , V_12 , V_13 ,
V_13 ) ;
V_24 = F_8 (
& V_4 -> V_11 , V_27 ) ;
if ( V_24 < 0 ) {
F_9 ( V_20 , L_1 ) ;
return V_24 ;
} else if ( V_24 == 0 ) {
F_9 ( V_20 , L_2 ) ;
return - V_28 ;
}
F_2 ( V_4 -> V_6 , V_29 , & V_2 ) ;
* V_23 = F_10 ( V_2 ) ;
return V_30 ;
}
static int F_11 ( struct V_31 * V_32 ,
struct V_21 const * V_22 , int * V_23 ,
int * V_33 , long V_34 )
{
struct V_3 * V_4 = F_12 ( V_32 ) ;
int V_35 ;
switch ( V_34 ) {
case V_36 :
F_13 ( & V_32 -> V_37 ) ;
V_35 = F_6 ( & V_32 -> V_20 , V_22 , V_4 , V_23 ) ;
F_14 ( & V_32 -> V_37 ) ;
return V_35 ;
case V_38 :
* V_23 = V_4 -> V_39 [ V_22 -> V_26 ] ;
* V_33 = 12 ;
return V_40 ;
default:
return - V_41 ;
}
}
static int F_15 ( struct V_42 * V_43 ,
struct V_3 * V_4 )
{
struct V_44 * V_45 = V_43 -> V_20 . V_46 ;
struct V_44 * V_47 ;
struct V_19 * V_20 = & V_43 -> V_20 ;
unsigned int V_48 [ 4 ] = {} ;
int V_35 , V_49 ;
for ( V_49 = 0 ; V_49 < V_50 ; ++ V_49 )
F_5 ( V_4 -> V_6 , F_16 ( V_49 ) ,
V_51 |
V_52 |
V_53 |
V_54 |
F_17 ( V_49 ) |
V_55 ) ;
V_4 -> V_56 [ V_57 ] = NULL ;
V_4 -> V_56 [ V_58 ] =
F_18 ( & V_43 -> V_20 , L_3 ) ;
V_4 -> V_56 [ V_59 ] =
F_18 ( & V_43 -> V_20 , L_4 ) ;
V_4 -> V_56 [ V_60 ] =
F_18 ( & V_43 -> V_20 , L_5 ) ;
F_19 (np, child) {
T_2 V_61 ;
T_2 V_62 = V_54 ;
T_2 V_63 = V_55 ;
V_35 = F_20 ( V_47 , L_6 , & V_61 ) ;
if ( V_35 ) {
F_9 ( V_20 , L_7 ) ;
return V_35 ;
}
if ( V_61 >= V_50 ) {
F_9 ( V_20 ,
L_8 ) ;
return - V_41 ;
}
F_20 ( V_47 , L_9 , & V_62 ) ;
F_20 ( V_47 , L_10 , & V_63 ) ;
switch ( V_62 ) {
case V_58 :
case V_59 :
case V_60 :
if ( F_21 ( V_4 -> V_56 [ V_62 ] ) ) {
F_9 ( V_20 , L_11 ,
V_64 [ V_62 ] ) ;
return F_22 ( V_4 -> V_56 [ V_62 ] ) ;
}
V_4 -> V_39 [ V_61 ] =
F_23 ( V_4 -> V_56 [ V_62 ] ) ;
V_4 -> V_39 [ V_61 ] /= 1000 ;
break;
case V_57 :
V_4 -> V_39 [ V_61 ] = 2500 ;
break;
default:
F_9 ( V_20 , L_12 , V_62 ) ;
return - V_41 ;
}
++ V_48 [ V_62 ] ;
V_62 = F_24 ( V_62 ) ;
V_63 = F_25 ( V_63 ) ;
if ( ( V_62 & V_65 ) != V_62 ) {
F_9 ( V_20 , L_13 ) ;
return - V_41 ;
}
if ( ( V_63 & V_66 ) != V_63 ) {
F_9 ( V_20 , L_14 ) ;
return - V_41 ;
}
F_3 ( V_4 -> V_6 , F_16 ( V_61 ) ,
V_65 |
V_66 ,
V_62 | V_63 ) ;
}
F_3 ( V_4 -> V_6 , V_12 ,
V_67 | V_68 ,
V_67 | V_68 ) ;
F_5 ( V_4 -> V_6 , V_12 ,
V_69 | V_70 ) ;
for ( V_49 = 0 ; V_49 != 4 ; ++ V_49 ) {
if ( ! V_48 [ V_49 ] ) {
if ( ! F_26 ( V_4 -> V_56 [ V_49 ] ) )
F_27 ( V_4 -> V_56 [ V_49 ] ) ;
V_4 -> V_56 [ V_49 ] = NULL ;
}
}
return 0 ;
}
static int F_28 ( struct V_42 * V_43 )
{
struct V_31 * V_32 ;
struct V_3 * V_4 ;
struct V_71 * V_72 = F_29 ( V_43 -> V_20 . V_73 ) ;
struct V_19 * V_20 = & V_43 -> V_20 ;
struct V_74 * V_75 ;
void T_3 * V_76 ;
int V_35 ;
int V_49 ;
V_32 = F_30 ( & V_43 -> V_20 , sizeof( * V_4 ) ) ;
if ( ! V_32 )
return - V_77 ;
V_4 = F_12 ( V_32 ) ;
V_75 = F_31 ( V_43 , V_78 , 0 ) ;
V_76 = F_32 ( V_20 , V_75 ) ;
if ( F_21 ( V_76 ) )
return F_22 ( V_76 ) ;
V_4 -> V_6 = F_33 ( V_20 , V_76 , & V_79 ) ;
if ( F_21 ( V_4 -> V_6 ) ) {
F_9 ( V_20 , L_15 ) ;
return F_22 ( V_4 -> V_6 ) ;
}
F_34 ( & V_4 -> V_11 ) ;
V_35 = F_15 ( V_43 , V_4 ) ;
if ( V_35 )
return V_35 ;
for ( V_49 = 0 ; V_49 != 4 ; ++ V_49 ) {
if ( ! V_4 -> V_56 [ V_49 ] )
continue;
V_35 = F_35 ( V_4 -> V_56 [ V_49 ] ) ;
if ( V_35 )
goto V_80;
}
V_4 -> V_81 = V_72 -> V_81 ;
V_35 = F_36 ( V_4 -> V_81 ) ;
if ( V_35 ) {
F_9 ( V_20 , L_16 ) ;
goto V_82;
}
V_4 -> V_1 = F_37 ( V_43 , 0 ) ;
if ( V_4 -> V_1 <= 0 ) {
F_9 ( V_20 , L_17 ) ;
V_35 = V_4 -> V_1 ;
if ( ! V_35 )
V_35 = - V_83 ;
goto V_84;
}
V_35 = F_38 ( V_4 -> V_1 , F_1 , 0 , V_43 -> V_85 , V_4 ) ;
if ( V_35 ) {
F_9 ( V_20 , L_18 ) ;
goto V_84;
}
V_32 -> V_20 . V_73 = & V_43 -> V_20 ;
V_32 -> V_86 = V_87 ;
V_32 -> V_88 = F_39 ( V_87 ) ;
V_32 -> V_89 = & V_90 ;
V_32 -> V_85 = V_91 ;
V_35 = F_40 ( V_32 ) ;
if ( V_35 ) {
F_9 ( V_20 , L_19 ) ;
goto V_92;
}
F_41 ( V_43 , V_32 ) ;
return 0 ;
V_92:
F_42 ( V_4 -> V_1 , V_4 ) ;
V_84:
F_43 ( V_4 -> V_81 ) ;
V_82:
V_49 = 4 ;
V_80:
for (; V_49 -- > 0 ; ) {
if ( V_4 -> V_56 [ V_49 ] )
F_44 ( V_4 -> V_56 [ V_49 ] ) ;
}
return V_35 ;
}
static int F_45 ( struct V_42 * V_43 )
{
struct V_31 * V_32 = F_46 ( V_43 ) ;
struct V_3 * V_4 = F_12 ( V_32 ) ;
int V_49 ;
F_47 ( V_32 ) ;
F_42 ( V_4 -> V_1 , V_4 ) ;
F_43 ( V_4 -> V_81 ) ;
for ( V_49 = 4 ; V_49 -- > 0 ; ) {
if ( V_4 -> V_56 [ V_49 ] )
F_44 ( V_4 -> V_56 [ V_49 ] ) ;
}
return 0 ;
}
