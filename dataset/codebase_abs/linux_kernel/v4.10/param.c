static int F_1 ( unsigned int * V_1 ,
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
F_2 ( & V_5 -> V_10 -> V_11 , L_1 ,
V_3 -> V_12 ) ;
return 0 ;
case V_13 :
F_2 ( & V_5 -> V_10 -> V_11 , L_2 ,
V_3 -> V_12 ) ;
return 0 ;
}
break;
case V_14 :
if ( * V_1 >= V_3 -> V_15 . V_16 . V_17 && * V_1 <= V_3 -> V_15 . V_16 . V_18 ) {
F_2 ( & V_5 -> V_10 -> V_11 , L_3 ,
V_3 -> V_12 , * V_1 ) ;
return 0 ;
}
break;
case V_19 : {
int V_20 ;
struct V_21 * V_22 ;
for ( V_20 = 0 ; V_20 < V_3 -> V_15 . V_23 . V_24 ; V_20 ++ ) {
V_22 = & V_3 -> V_15 . V_23 . V_25 [ V_20 ] ;
if ( * V_1 == V_22 -> V_20 ) {
if ( V_22 -> V_26 [ 0 ] != '\0' )
F_2 ( & V_5 -> V_10 -> V_11 , L_4 ,
V_22 -> V_26 ) ;
return 0 ;
}
}
}
break;
default:
F_3 () ;
}
F_2 ( & V_5 -> V_10 -> V_11 , L_5 ,
V_3 -> V_12 , * V_1 , V_3 -> V_27 ) ;
* V_1 = V_3 -> V_7 ;
return - 1 ;
}
void F_4 ( struct V_4 * V_5 )
{
struct V_28 * V_29 = & V_5 -> V_29 ;
int V_30 = V_5 -> V_31 ;
if ( V_30 >= V_32 ) {
F_5 ( & V_5 -> V_10 -> V_11 ,
L_6 , V_30 ) ;
F_5 ( & V_5 -> V_10 -> V_11 ,
L_7 ) ;
}
{
static const struct V_2 V_3 = {
. type = V_14 ,
. V_12 = L_8 ,
. V_27 = L_9
F_6 ( V_33 ) ,
. V_7 = V_33 ,
. V_15 = { . V_16 = { . V_17 = V_34 ,
. V_18 = V_35 } }
} ;
if ( V_36 > V_30 ) {
V_5 -> V_37 = V_38 [ V_30 ] ;
F_1 ( & V_5 -> V_37 , & V_3 ,
V_5 ) ;
} else {
V_5 -> V_37 = V_3 . V_7 ;
}
}
{
static const struct V_2 V_3 = {
. type = V_14 ,
. V_12 = L_10 ,
. V_27 = L_9
F_6 ( V_39 ) ,
. V_7 = V_39 ,
. V_15 = { . V_16 = { . V_17 = V_40 ,
. V_18 = V_41 } }
} ;
if ( V_42 > V_30 ) {
V_5 -> V_43 = V_44 [ V_30 ] ;
F_1 ( & V_5 -> V_43 , & V_3 ,
V_5 ) ;
} else {
V_5 -> V_43 = V_3 . V_7 ;
}
}
{
static struct V_2 V_3 = {
. type = V_14 ,
. V_12 = L_11 ,
. V_27 = L_9
F_6 ( V_45 ) ,
. V_7 = V_45 ,
. V_15 = { . V_16 = { . V_17 = V_46 ,
. V_18 = V_47 } }
} ;
if ( V_48 > V_30 ) {
V_5 -> V_49 = V_50 [ V_30 ] ;
F_1 ( & V_5 -> V_49 , & V_3 ,
V_5 ) ;
} else {
V_5 -> V_49 = V_3 . V_7 ;
}
}
{
static const struct V_2 V_3 = {
. type = V_14 ,
. V_12 = L_12 ,
. V_27 = L_9
F_6 ( V_51 ) ,
. V_7 = V_51 ,
. V_15 = { . V_16 = { . V_17 = V_52 ,
. V_18 = V_53 } }
} ;
if ( V_54 > V_30 ) {
V_5 -> V_55 = V_56 [ V_30 ] ;
F_1 ( & V_5 -> V_55 , & V_3 ,
V_5 ) ;
} else {
V_5 -> V_55 = V_3 . V_7 ;
}
}
{
static const struct V_2 V_3 = {
. type = V_14 ,
. V_12 = L_13 ,
. V_27 = L_9
F_6 ( V_57 ) ,
. V_7 = V_57 ,
. V_15 = { . V_16 = { . V_17 = V_58 ,
. V_18 = V_59 } }
} ;
if ( V_60 > V_30 ) {
V_5 -> V_61 = V_62 [ V_30 ] ;
if ( ( V_5 -> V_61 > 4 ) &&
F_1 ( & V_5 -> V_61 , & V_3 , V_5 ) )
V_5 -> V_61 = V_3 . V_7 ;
} else {
V_5 -> V_61 = V_3 . V_7 ;
if ( V_5 -> V_61 > 4 )
F_2 ( & V_5 -> V_10 -> V_11 ,
L_14 , V_3 . V_12 ,
V_5 -> V_61 ) ;
}
V_5 -> V_63 = V_5 -> V_61 ;
switch ( V_5 -> V_61 ) {
case 0 :
F_2 ( & V_5 -> V_10 -> V_11 , L_15 ,
V_3 . V_12 ) ;
break;
case 1 :
F_2 ( & V_5 -> V_10 -> V_11 ,
L_16 , V_3 . V_12 ) ;
V_5 -> V_61 = 20000 ;
break;
case 2 :
F_2 ( & V_5 -> V_10 -> V_11 ,
L_17 ,
V_3 . V_12 ) ;
V_5 -> V_63 = V_3 . V_7 ;
case 3 :
F_2 ( & V_5 -> V_10 -> V_11 ,
L_18 ,
V_3 . V_12 ) ;
V_5 -> V_61 = 20000 ;
break;
case 4 :
F_2 ( & V_5 -> V_10 -> V_11 ,
L_19 ,
V_3 . V_12 ) ;
break;
default:
V_5 -> V_63 &= ~ 3 ;
break;
}
}
{
static struct V_2 V_3 = {
. type = V_14 ,
. V_12 = L_20 ,
#ifndef F_7
. V_27 = L_21 ,
. V_7 = V_64 ,
. V_15 = { . V_16 = { . V_17 = 0 ,
. V_18 = 0 } }
#endif
} ;
#ifdef F_7
if ( V_5 -> V_65 & V_66 ) {
V_3 . V_27 = F_8 ( L_22 ,
V_67 ) ;
V_3 . V_7 = V_68 ;
V_3 . V_15 . V_16 . V_18 = V_68 ;
} else {
V_3 . V_27 = F_8 ( L_23 , V_67 ) ;
V_3 . V_7 = V_69 ;
V_3 . V_15 . V_16 . V_18 = V_69 ;
}
if ( ! V_3 . V_27 ) {
F_9 ( & V_5 -> V_10 -> V_11 ,
L_24 ) ;
return;
}
#endif
if ( V_70 > V_30 ) {
unsigned int V_71 = V_72 [ V_30 ] ;
F_1 ( & V_71 , & V_3 , V_5 ) ;
V_5 -> V_71 = V_71 ;
} else {
V_5 -> V_71 = V_3 . V_7 ;
}
#ifdef F_7
F_10 ( V_3 . V_27 ) ;
#endif
}
{
static const struct V_2 V_3 = {
. type = V_8 ,
. V_12 = L_25 ,
. V_27 = L_26 ,
. V_7 = V_13
} ;
if ( V_73 > V_30 ) {
unsigned int V_74 = V_75 [ V_30 ] ;
F_1 ( & V_74 , & V_3 , V_5 ) ;
if ( ( V_5 -> V_65 & V_76 ) && V_74 )
V_5 -> V_65 |= V_77 ;
}
}
{
static const struct V_2 V_3 = {
. type = V_8 ,
. V_12 = L_27 ,
. V_27 = L_28 ,
. V_7 = V_9
} ;
if ( V_78 > V_30 ) {
unsigned int V_79 = V_80 [ V_30 ] ;
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
. V_12 = L_29 ,
. V_27 = L_28 ,
. V_7 = V_9
} ;
bool V_84 = V_3 . V_7 ;
if ( V_85 > V_30 ) {
unsigned int V_86 = V_87 [ V_30 ] ;
F_1 ( & V_86 , & V_3 , V_5 ) ;
V_84 = V_86 ;
}
if ( V_29 -> V_88 . type == V_89 )
F_11 ( V_29 ,
V_84 ) ;
}
{
static const struct V_2 V_3 = {
. type = V_8 ,
. V_12 = L_30 ,
. V_27 = L_28 ,
. V_7 = V_9
} ;
if ( V_5 -> V_65 & V_90 ) {
if ( V_91 > V_30 ) {
unsigned int V_92 =
V_93 [ V_30 ] ;
F_1 ( & V_92 , & V_3 ,
V_5 ) ;
if ( V_92 )
V_5 -> V_65 |= V_94 ;
} else {
if ( V_3 . V_7 )
V_5 -> V_65 |= V_94 ;
}
}
}
}
