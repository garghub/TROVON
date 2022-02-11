static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
T_1 * V_5 )
{
int V_6 ;
T_2 V_7 = V_8 [ V_4 ] [ 0 ] & V_9 ;
T_2 V_10 = V_8 [ V_4 ] [ 1 ] ;
F_2 ( & V_2 -> V_11 ) ;
V_6 = F_3 ( V_2 -> V_12 ,
V_13 , V_7 ) ;
if ( V_6 ) {
F_4 ( V_2 -> V_14 , L_1 ,
V_13 , V_7 ) ;
F_5 ( & V_2 -> V_11 ) ;
return V_6 ;
}
F_6 ( 1000 , 2000 ) ;
V_6 = F_7 ( V_2 -> V_12 , V_10 ) ;
if ( V_6 < 0 ) {
F_4 ( V_2 -> V_14 , L_2 ,
V_10 ) ;
F_5 ( & V_2 -> V_11 ) ;
return V_6 ;
}
* V_5 = V_6 ;
F_5 ( & V_2 -> V_11 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
T_1 * V_15 ,
enum V_16 * V_17 )
{
enum V_3 V_18 [] = {
V_19 ,
V_20 ,
V_21
} ;
unsigned int V_22 ;
int V_6 ;
for ( V_22 = 0 ; V_22 < F_9 ( V_18 ) ; ++ V_22 ) {
V_6 = F_1 ( V_2 , V_18 [ V_22 ] , V_15 ) ;
if ( V_6 )
return V_6 ;
if ( * V_15 > 0 ) {
* V_17 = V_18 [ V_22 ] ;
return 0 ;
}
}
return - V_23 ;
}
static int F_10 ( struct V_24 * V_25 ,
struct V_26 const * V_27 ,
int * V_28 , int * V_29 , long V_30 )
{
struct V_1 * V_14 = F_11 ( V_25 ) ;
enum V_16 V_31 ;
const unsigned int * V_17 ;
T_1 V_32 ;
int V_6 ;
switch ( V_30 ) {
case V_33 :
switch ( V_27 -> V_34 ) {
case V_35 :
V_6 = F_1 ( V_14 , V_36 ,
& V_32 ) ;
if ( V_6 )
return - V_37 ;
* V_28 = F_12 ( V_32 ) ;
return V_38 ;
case V_39 :
V_6 = F_1 ( V_14 , V_40 ,
& V_32 ) ;
if ( V_6 )
return - V_37 ;
* V_28 = F_13 ( V_32 ) ;
return V_38 ;
}
break;
case V_41 :
* V_28 = V_42 ;
return V_38 ;
case V_43 :
switch ( V_27 -> V_34 ) {
case V_35 :
* V_28 = V_44 ;
* V_29 = V_45 ;
return V_46 ;
case V_39 :
* V_28 = V_47 ;
return V_38 ;
}
break;
case V_48 :
switch ( V_27 -> V_34 ) {
case V_49 :
V_6 = F_8 ( V_14 , & V_32 ,
& V_31 ) ;
if ( V_6 )
return - V_37 ;
V_17 = V_50 [ V_31 ] ;
V_32 -= V_17 [ V_51 ] ;
* V_28 = F_13 ( V_32 ) *
V_17 [ V_52 ] ;
* V_29 = 1000000 ;
return V_46 ;
case V_53 :
V_6 = F_8 ( V_14 , & V_32 ,
& V_31 ) ;
if ( V_6 )
return - V_37 ;
V_17 = V_50 [ V_31 ] ;
V_32 -= V_17 [ V_51 ] ;
* V_28 = F_13 ( V_32 ) *
V_17 [ V_52 ] ;
* V_29 = V_14 -> V_54 ;
return V_46 ;
case V_55 :
V_6 = F_1 ( V_14 , V_40 ,
& V_32 ) ;
if ( V_6 )
return - V_37 ;
V_32 -= V_42 ;
* V_28 = F_13 ( V_32 ) *
V_47 ;
V_6 = F_8 ( V_14 , & V_32 ,
& V_31 ) ;
if ( V_6 )
return - V_37 ;
V_17 = V_50 [ V_31 ] ;
V_32 -= V_17 [ V_51 ] ;
* V_28 *= F_13 ( V_32 ) *
V_17 [ V_52 ] / 1000 ;
* V_29 = V_14 -> V_54 ;
return V_46 ;
}
break;
}
return - V_37 ;
}
static T_3 F_14 ( struct V_56 * V_14 ,
struct V_57 * V_58 ,
char * V_59 )
{
struct V_1 * V_2 = F_11 ( F_15 ( V_14 ) ) ;
unsigned int V_22 , V_60 ;
V_22 = V_2 -> V_54 / 1000000 ;
V_60 = V_2 -> V_54 % 1000000 ;
return sprintf ( V_59 , L_3 , V_22 , V_60 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_12 * V_61 = V_2 -> V_12 ;
T_1 V_62 ;
int V_6 ;
if ( ! F_17 ( V_61 -> V_63 ,
V_64 |
V_65 ) ) {
F_4 ( V_2 -> V_14 ,
L_4 ) ;
return - V_37 ;
}
V_6 = F_1 ( V_2 , V_36 , & V_62 ) ;
if ( V_6 )
return V_6 ;
V_62 = V_6 & V_66 ;
if ( ( V_62 > V_67 &&
V_62 < V_68 ) ||
V_62 > V_69 ) {
F_4 ( V_2 -> V_14 ,
L_5 ,
V_62 ) ;
return - V_23 ;
}
V_6 = F_3 ( V_2 -> V_12 ,
V_13 , 0 ) ;
if ( V_6 ) {
F_4 ( V_2 -> V_14 , L_1 ,
V_13 , 0 ) ;
return V_6 ;
}
V_6 = F_3 ( V_2 -> V_12 ,
V_70 , 0 ) ;
if ( V_6 ) {
F_4 ( V_2 -> V_14 , L_1 ,
V_70 , 0 ) ;
return V_6 ;
}
F_6 ( 1000 , 2000 ) ;
return 0 ;
}
static int F_18 ( struct V_12 * V_61 ,
const struct V_71 * V_72 )
{
const char * const V_73 = L_6 ;
const struct V_74 * V_75 = V_61 -> V_14 . V_75 ;
const struct V_76 * V_77 =
F_19 ( V_78 , & V_61 -> V_14 ) ;
struct V_1 * V_2 ;
struct V_24 * V_25 ;
unsigned int V_79 ;
int V_6 ;
V_25 = F_20 ( & V_61 -> V_14 , sizeof( * V_2 ) ) ;
if ( ! V_25 )
return - V_80 ;
F_21 ( V_61 , V_25 ) ;
V_2 = F_11 ( V_25 ) ;
V_2 -> V_14 = & V_61 -> V_14 ;
V_2 -> V_12 = V_61 ;
F_22 ( & V_2 -> V_11 ) ;
V_6 = F_23 ( V_75 , V_73 , & V_79 ) ;
if ( V_6 ) {
F_4 ( & V_61 -> V_14 ,
L_7 ,
V_73 , V_75 ) ;
return V_6 ;
}
V_2 -> V_54 = V_79 ;
V_6 = F_16 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_25 -> V_14 . V_81 = & V_61 -> V_14 ;
V_25 -> V_14 . V_75 = V_61 -> V_14 . V_75 ;
V_25 -> V_82 = V_77 -> V_83 ;
V_25 -> V_84 = V_85 ;
V_25 -> V_86 = & V_87 ;
V_25 -> V_88 = V_89 ;
V_25 -> V_90 = F_9 ( V_89 ) ;
return F_24 ( & V_61 -> V_14 , V_25 ) ;
}
