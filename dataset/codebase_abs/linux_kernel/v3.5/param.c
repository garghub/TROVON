static int T_1 F_1 ( unsigned int * V_1 ,
const struct V_2 * V_3 ,
struct V_4 * V_5 )
{
if ( * V_1 == V_6 ) {
* V_1 = V_3 -> V_7 ;
return 0 ;
}
switch ( V_3 -> type ) {
case V_8 :
switch ( * V_1 ) {
case V_9 :
F_2 ( L_1 , V_3 -> V_10 ) ;
return 0 ;
case V_11 :
F_2 ( L_2 , V_3 -> V_10 ) ;
return 0 ;
}
break;
case V_12 :
if ( * V_1 >= V_3 -> V_13 . V_14 . V_15 && * V_1 <= V_3 -> V_13 . V_14 . V_16 ) {
F_2 ( L_3 , V_3 -> V_10 , * V_1 ) ;
return 0 ;
}
break;
case V_17 : {
int V_18 ;
struct V_19 * V_20 ;
for ( V_18 = 0 ; V_18 < V_3 -> V_13 . V_21 . V_22 ; V_18 ++ ) {
V_20 = & V_3 -> V_13 . V_21 . V_23 [ V_18 ] ;
if ( * V_1 == V_20 -> V_18 ) {
if ( V_20 -> V_24 [ 0 ] != '\0' )
F_2 ( L_4 , V_20 -> V_24 ) ;
return 0 ;
}
}
}
break;
default:
F_3 () ;
}
F_2 ( L_5 , V_3 -> V_10 , * V_1 ,
V_3 -> V_25 ) ;
* V_1 = V_3 -> V_7 ;
return - 1 ;
}
void T_1 F_4 ( struct V_4 * V_5 )
{
struct V_26 * V_27 = & V_5 -> V_27 ;
int V_28 = V_5 -> V_29 ;
if ( V_28 >= V_30 ) {
F_5 ( L_6 , V_28 ) ;
F_5 ( L_7 ) ;
}
{
static const struct V_2 V_3 = {
. type = V_12 ,
. V_10 = L_8 ,
. V_25 = L_9
F_6 ( V_31 ) ,
. V_7 = V_31 ,
. V_13 = { . V_14 = { . V_15 = V_32 ,
. V_16 = V_33 } }
} ;
if ( V_34 > V_28 ) {
V_5 -> V_35 = V_36 [ V_28 ] ;
F_1 ( & V_5 -> V_35 , & V_3 ,
V_5 ) ;
} else {
V_5 -> V_35 = V_3 . V_7 ;
}
}
{
static const struct V_2 V_3 = {
. type = V_12 ,
. V_10 = L_10 ,
. V_25 = L_9
F_6 ( V_37 ) ,
. V_7 = V_37 ,
. V_13 = { . V_14 = { . V_15 = V_38 ,
. V_16 = V_39 } }
} ;
if ( V_40 > V_28 ) {
V_5 -> V_41 = V_42 [ V_28 ] ;
F_1 ( & V_5 -> V_41 , & V_3 ,
V_5 ) ;
} else {
V_5 -> V_41 = V_3 . V_7 ;
}
}
{
static struct V_2 V_3 = {
. type = V_12 ,
. V_10 = L_11 ,
. V_25 = L_9
F_6 ( V_43 ) ,
. V_7 = V_43 ,
. V_13 = { . V_14 = { . V_15 = V_44 ,
. V_16 = V_45 } }
} ;
if ( V_46 > V_28 ) {
V_5 -> V_47 = V_48 [ V_28 ] ;
F_1 ( & V_5 -> V_47 , & V_3 ,
V_5 ) ;
} else {
V_5 -> V_47 = V_3 . V_7 ;
}
}
{
static const struct V_2 V_3 = {
. type = V_12 ,
. V_10 = L_12 ,
. V_25 = L_9
F_6 ( V_49 ) ,
. V_7 = V_49 ,
. V_13 = { . V_14 = { . V_15 = V_50 ,
. V_16 = V_51 } }
} ;
if ( V_52 > V_28 ) {
V_5 -> V_53 = V_54 [ V_28 ] ;
F_1 ( & V_5 -> V_53 , & V_3 ,
V_5 ) ;
} else {
V_5 -> V_53 = V_3 . V_7 ;
}
}
{
static const struct V_2 V_3 = {
. type = V_12 ,
. V_10 = L_13 ,
. V_25 = L_9
F_6 ( V_55 ) ,
. V_7 = V_55 ,
. V_13 = { . V_14 = { . V_15 = V_56 ,
. V_16 = V_57 } }
} ;
if ( V_58 > V_28 ) {
V_5 -> V_59 = V_60 [ V_28 ] ;
if ( ( V_5 -> V_59 > 4 ) &&
F_1 ( & V_5 -> V_59 , & V_3 , V_5 ) )
V_5 -> V_59 = V_3 . V_7 ;
} else {
V_5 -> V_59 = V_3 . V_7 ;
if ( V_5 -> V_59 > 4 )
F_2 ( L_14 , V_3 . V_10 ,
V_5 -> V_59 ) ;
}
V_5 -> V_61 = V_5 -> V_59 ;
switch ( V_5 -> V_59 ) {
case 0 :
F_2 ( L_15 , V_3 . V_10 ) ;
break;
case 1 :
F_2 ( L_16 , V_3 . V_10 ) ;
V_5 -> V_59 = 20000 ;
break;
case 3 :
F_2 ( L_17 ,
V_3 . V_10 ) ;
V_5 -> V_59 = 20000 ;
break;
case 4 :
F_2 ( L_18 ,
V_3 . V_10 ) ;
break;
default:
V_5 -> V_61 &= ~ 3 ;
break;
}
}
{
static struct V_2 V_3 = {
. type = V_12 ,
. V_10 = L_19 ,
#ifndef F_7
. V_25 = L_20 ,
. V_7 = V_62 ,
. V_13 = { . V_14 = { . V_15 = 0 ,
. V_16 = 0 } }
#endif
} ;
#ifdef F_7
if ( V_5 -> V_63 & V_64 ) {
V_3 . V_25 = F_8 ( L_21 ,
V_65 ) ;
V_3 . V_7 = V_66 ;
V_3 . V_13 . V_14 . V_16 = V_66 ;
} else {
V_3 . V_25 = F_8 ( L_22 , V_65 ) ;
V_3 . V_7 = V_67 ;
V_3 . V_13 . V_14 . V_16 = V_67 ;
}
if ( ! V_3 . V_25 ) {
F_9 ( & V_5 -> V_68 -> V_69 ,
L_23 ) ;
return;
}
#endif
if ( V_70 > V_28 ) {
unsigned int V_71 = V_72 [ V_28 ] ;
F_1 ( & V_71 , & V_3 , V_5 ) ;
V_5 -> V_71 = V_71 ;
} else {
V_5 -> V_71 = V_3 . V_7 ;
}
#ifdef F_7
F_10 ( V_3 . V_25 ) ;
#endif
}
{
static const struct V_2 V_3 = {
. type = V_8 ,
. V_10 = L_24 ,
. V_25 = L_25 ,
. V_7 = V_11
} ;
if ( V_73 > V_28 ) {
unsigned int V_74 = V_75 [ V_28 ] ;
F_1 ( & V_74 , & V_3 , V_5 ) ;
if ( ( V_5 -> V_63 & V_76 )
&& V_74 )
V_5 -> V_63 |= V_77 ;
}
}
{
static const struct V_2 V_3 = {
. type = V_8 ,
. V_10 = L_26 ,
. V_25 = L_27 ,
. V_7 = V_9
} ;
if ( V_78 > V_28 ) {
unsigned int V_79 = V_80 [ V_28 ] ;
F_1 ( & V_79 , & V_3 , V_5 ) ;
if ( V_79 == V_9 ) {
V_5 -> V_81 |= V_82 ;
V_5 -> V_81 |= V_83 ;
}
} else {
V_5 -> V_81 |= V_82 ;
V_5 -> V_81 |= V_83 ;
}
}
{
static const struct V_2 V_3 = {
. type = V_8 ,
. V_10 = L_28 ,
. V_25 = L_27 ,
. V_7 = V_9
} ;
if ( V_84 > V_28 ) {
unsigned int V_85 = V_86 [ V_28 ] ;
F_1 ( & V_85 , & V_3 , V_5 ) ;
if ( V_27 -> V_87 . type == V_88 )
F_11 ( V_27 ,
V_85 ) ;
} else {
if ( V_27 -> V_87 . type == V_88 )
F_11 ( V_27 ,
V_3 . V_7 ) ;
}
}
{
static const struct V_2 V_3 = {
. type = V_8 ,
. V_10 = L_29 ,
. V_25 = L_27 ,
. V_7 = V_9
} ;
if ( V_5 -> V_63 & V_89 ) {
if ( V_90 > V_28 ) {
unsigned int V_91 = V_92 [ V_28 ] ;
F_1 ( & V_91 , & V_3 ,
V_5 ) ;
if ( V_91 )
V_5 -> V_63 |= V_93 ;
} else {
if ( V_3 . V_7 )
V_5 -> V_63 |= V_93 ;
}
}
}
}
