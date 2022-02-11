static int
F_1 ( unsigned int * V_1 , const struct V_2 * V_3 )
{
if ( * V_1 == V_4 ) {
* V_1 = V_3 -> V_5 ;
return 0 ;
}
switch ( V_3 -> type ) {
case V_6 :
switch ( * V_1 ) {
case V_7 :
F_2 ( L_1 , V_3 -> V_8 ) ;
return 0 ;
case V_9 :
F_2 ( L_2 , V_3 -> V_8 ) ;
return 0 ;
}
break;
case V_10 :
if ( * V_1 >= V_3 -> V_11 . V_12 . V_13 && * V_1 <= V_3 -> V_11 . V_12 . V_14 ) {
F_2 ( L_3 , V_3 -> V_8 , * V_1 ) ;
return 0 ;
}
break;
case V_15 : {
int V_16 ;
const struct V_17 * V_18 ;
for ( V_16 = 0 ; V_16 < V_3 -> V_11 . V_19 . V_20 ; V_16 ++ ) {
V_18 = & V_3 -> V_11 . V_19 . V_21 [ V_16 ] ;
if ( * V_1 == V_18 -> V_16 ) {
if ( V_18 -> V_22 [ 0 ] != '\0' )
F_2 ( L_4 , V_18 -> V_22 ) ;
return 0 ;
}
}
}
break;
default:
F_3 () ;
}
F_2 ( L_5 , V_3 -> V_8 , * V_1 , V_3 -> V_23 ) ;
* V_1 = V_3 -> V_5 ;
return - 1 ;
}
void
F_4 ( struct V_24 * V_25 )
{
int V_26 = V_25 -> V_27 ;
if ( V_26 >= V_28 ) {
F_5 ( L_6 , V_26 ) ;
F_5 ( L_7 ) ;
}
{
static const struct V_2 V_3 = {
. type = V_10 ,
. V_8 = L_8 ,
. V_23 = L_9 F_6 ( V_29 ) ,
. V_5 = V_29 ,
. V_11 = { . V_12 = { . V_13 = V_30 ,
. V_14 = V_31 } }
} ;
struct V_32 * V_33 = & V_25 -> V_33 ;
if ( V_34 > V_26 ) {
V_33 -> V_35 = V_36 [ V_26 ] ;
F_1 ( & V_33 -> V_35 , & V_3 ) ;
} else {
V_33 -> V_35 = V_3 . V_5 ;
}
V_33 -> V_35 = F_7 ( V_33 -> V_35 , V_37 ) ;
}
{
static const struct V_2 V_3 = {
. type = V_10 ,
. V_8 = L_10 ,
. V_23 = L_9 F_6 ( V_38 ) ,
. V_5 = V_38 ,
. V_11 = { . V_12 = { . V_13 = V_39 ,
. V_14 = V_40 } }
} ;
struct V_32 * V_41 = & V_25 -> V_41 ;
if ( V_42 > V_26 ) {
V_41 -> V_35 = V_43 [ V_26 ] ;
F_1 ( & V_41 -> V_35 , & V_3 ) ;
} else {
V_41 -> V_35 = V_3 . V_5 ;
}
V_41 -> V_35 = F_7 ( V_41 -> V_35 , V_44 ) ;
}
{
static const struct V_2 V_3 = {
. type = V_6 ,
. V_8 = L_11 ,
. V_23 = L_12 ,
. V_5 = V_7
} ;
if ( V_45 > V_26 ) {
unsigned int V_46 = V_47 [ V_26 ] ;
F_1 ( & V_46 , & V_3 ) ;
V_25 -> V_46 = V_46 ;
} else {
V_25 -> V_46 = V_3 . V_5 ;
}
}
{
static const struct V_17 V_48 [] = {
{ V_49 , L_13 } ,
{ V_50 , L_14 } ,
{ V_51 , L_15 } ,
{ V_52 , L_16 } ,
{ V_53 , L_17 }
} ;
static const struct V_2 V_3 = {
. type = V_15 ,
. V_8 = L_18 ,
. V_23 = L_19 ,
. V_5 = V_51 ,
. V_11 = { . V_19 = { . V_20 = F_8 ( V_48 ) ,
. V_21 = V_48 } }
} ;
if ( V_54 > V_26 ) {
unsigned int V_55 = V_56 [ V_26 ] ;
F_1 ( & V_55 , & V_3 ) ;
V_25 -> V_57 . V_55 . type = V_55 ;
} else {
V_25 -> V_57 . V_55 . type = V_3 . V_5 ;
}
}
{
static const struct V_2 V_3 = {
. type = V_10 ,
. V_8 = L_20 ,
. V_23 = L_9 F_6 ( V_58 ) ,
. V_5 = V_58 ,
. V_11 = { . V_12 = { . V_13 = V_59 ,
. V_14 = V_60 } }
} ;
if ( V_61 > V_26 ) {
V_25 -> V_57 . V_55 . V_62 = V_63 [ V_26 ] ;
F_1 ( & V_25 -> V_57 . V_55 . V_62 , & V_3 ) ;
} else {
V_25 -> V_57 . V_55 . V_62 = V_3 . V_5 ;
}
if ( ! ( V_25 -> V_57 . V_55 . type & V_51 ) )
F_2 ( L_21 ) ;
}
{
static const struct V_2 V_3 = {
. type = V_10 ,
. V_8 = L_22 ,
. V_23 = L_9 F_6 ( V_64 ) ,
. V_5 = V_64 ,
. V_11 = { . V_12 = { . V_13 = V_65 ,
. V_14 = V_66 } }
} ;
if ( V_67 > V_26 ) {
V_25 -> V_57 . V_55 . V_68 = V_69 [ V_26 ] ;
F_1 ( & V_25 -> V_57 . V_55 . V_68 , & V_3 ) ;
} else {
V_25 -> V_57 . V_55 . V_68 = V_3 . V_5 ;
}
if ( ! ( V_25 -> V_57 . V_55 . type & V_51 ) )
F_2 ( L_23 ) ;
}
{
static const struct V_2 V_3 = {
. type = V_10 ,
. V_8 = L_24 ,
. V_23 = L_9 F_6 ( V_70 ) ,
. V_5 = V_70 ,
. V_11 = { . V_12 = { . V_13 = V_71 ,
. V_14 = V_72 } }
} ;
if ( V_73 > V_26 ) {
unsigned int V_74 = V_75 [ V_26 ] ;
F_1 ( & V_74 , & V_3 ) ;
V_25 -> V_57 . V_55 . V_74 = V_74 ;
} else {
V_25 -> V_57 . V_55 . V_74 = V_3 . V_5 ;
}
if ( ! ( V_25 -> V_57 . V_55 . type & V_51 ) )
F_2 ( L_25 ) ;
}
if ( V_25 -> V_57 . V_55 . type & V_51 ) {
if ( V_25 -> V_57 . V_55 . V_62 < ( V_25 -> V_57 . V_55 . V_68 + 8 ) ) {
F_2 ( L_26 ) ;
V_25 -> V_57 . V_55 . V_62 = V_58 ;
V_25 -> V_57 . V_55 . V_68 = V_64 ;
}
}
{
static const struct V_2 V_3 = {
. type = V_10 ,
. V_8 = L_27 ,
. V_23 = L_9 F_6 ( V_76 ) ,
. V_5 = V_76 ,
. V_11 = { . V_12 = { . V_13 = V_77 ,
. V_14 = V_78 } }
} ;
if ( V_79 > V_26 ) {
V_25 -> V_80 = V_81 [ V_26 ] ;
F_1 ( & V_25 -> V_80 , & V_3 ) ;
} else {
V_25 -> V_80 = V_3 . V_5 ;
}
}
{
static const struct V_2 V_3 = {
. type = V_10 ,
. V_8 = L_28 ,
. V_23 = L_9 F_6 ( V_82 ) ,
. V_5 = V_82 ,
. V_11 = { . V_12 = { . V_13 = V_83 ,
. V_14 = V_84 } }
} ;
if ( V_85 > V_26 ) {
V_25 -> V_86 = V_87 [ V_26 ] ;
F_1 ( & V_25 -> V_86 , & V_3 ) ;
} else {
V_25 -> V_86 = V_3 . V_5 ;
}
}
{
static const struct V_2 V_3 = {
. type = V_6 ,
. V_8 = L_29 ,
. V_23 = L_12 ,
. V_5 = V_7
} ;
if ( V_88 > V_26 ) {
unsigned int V_89 = V_90 [ V_26 ] ;
F_1 ( & V_89 , & V_3 ) ;
V_25 -> V_91 = V_89 ;
} else {
V_25 -> V_91 = V_3 . V_5 ;
}
}
}
