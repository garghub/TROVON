static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned V_5 ;
unsigned V_6 ;
unsigned type ;
int V_7 ;
T_1 V_8 ;
switch ( V_4 -> V_9 ) {
case V_10 :
if ( V_4 -> V_11 ) {
type = V_12 ;
V_6 = V_4 -> V_11 - 1 ;
} else if ( V_4 -> V_13 && V_4 -> V_14 ) {
type = V_15 ;
if ( V_4 -> V_16 )
V_6 = V_17 ;
else if ( V_4 -> V_18 == 600 )
V_6 = V_19 ;
else if ( V_4 -> V_18 == 10000 )
V_6 = V_20 ;
else
V_6 = V_21 ;
} else if ( V_4 -> V_13 ) {
type = V_22 ;
if ( V_4 -> V_11 )
V_6 = V_4 -> V_11 ;
else
V_6 = V_23 ;
} else {
type = V_24 ;
V_6 = ! ! V_4 -> V_25 ;
if ( V_4 -> V_26 )
V_6 |= F_2 ( 1 ) ;
}
V_5 = V_4 -> V_27 ;
break;
case V_28 :
if ( V_4 -> V_14 ) {
type = V_29 ;
V_5 = V_4 -> V_30 ;
V_6 = V_4 -> V_25 ;
if ( V_4 -> V_26 )
V_6 |= F_2 ( 1 ) ;
} else {
type = V_31 ;
V_5 = V_4 -> V_32 ;
V_6 = 0 ;
}
break;
case V_33 :
V_5 = ( V_4 -> V_34 / 5 ) - 1 ;
if ( V_4 -> V_11 ) {
type = V_35 ;
V_6 = V_4 -> V_11 - 1 ;
} else {
type = V_36 ;
V_6 = V_4 -> V_25 ;
if ( V_4 -> V_26 )
V_6 |= F_2 ( 1 ) ;
}
break;
default:
return - V_37 ;
}
V_8 = type << 5 | V_5 << 2 | V_6 ;
V_7 = F_3 ( V_2 -> V_38 , V_4 -> V_39 , V_8 ) ;
if ( V_7 )
F_4 ( V_2 -> V_40 , L_1 ) ;
return V_7 ;
}
static int F_5 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_6 ( V_42 ) ;
return V_2 -> V_43 ;
}
static const char * F_7 ( struct V_41 * V_42 ,
unsigned V_44 )
{
return V_45 [ V_44 ] ;
}
static int F_8 ( struct V_41 * V_42 ,
unsigned V_44 ,
const unsigned * * V_46 ,
unsigned * V_47 )
{
struct V_1 * V_2 = F_6 ( V_42 ) ;
* V_46 = & V_2 -> V_48 . V_46 [ V_44 ] . V_49 ;
* V_47 = 1 ;
return 0 ;
}
static int F_9 ( struct V_41 * V_42 )
{
return F_10 ( V_50 ) ;
}
static const char * F_11 ( struct V_41 * V_42 ,
unsigned V_51 )
{
return V_50 [ V_51 ] ;
}
static int F_12 ( struct V_41 * V_42 ,
unsigned V_51 ,
const char * const * * V_52 ,
unsigned * const V_53 )
{
struct V_1 * V_2 = F_6 ( V_42 ) ;
* V_52 = V_45 ;
* V_53 = V_2 -> V_43 ;
return 0 ;
}
static int F_13 ( struct V_41 * V_42 ,
unsigned V_51 ,
unsigned V_44 )
{
struct V_1 * V_2 = F_6 ( V_42 ) ;
struct V_3 * V_4 = V_2 -> V_48 . V_46 [ V_44 ] . V_54 ;
V_4 -> V_9 = V_51 ;
F_1 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_14 ( struct V_41 * V_42 ,
unsigned int V_55 ,
unsigned long * V_56 )
{
struct V_1 * V_2 = F_6 ( V_42 ) ;
struct V_3 * V_4 = V_2 -> V_48 . V_46 [ V_55 ] . V_54 ;
unsigned V_57 = F_15 ( * V_56 ) ;
unsigned V_58 ;
switch ( V_57 ) {
case V_59 :
V_58 = V_4 -> V_18 ;
break;
case V_60 :
V_58 = V_4 -> V_16 ;
break;
case V_61 :
V_58 = V_4 -> V_13 ;
break;
case V_62 :
V_58 = V_4 -> V_25 ;
break;
case V_63 :
V_58 = V_4 -> V_27 ;
break;
case V_64 :
V_58 = V_4 -> V_34 ;
break;
case V_65 :
V_58 = V_4 -> V_11 ;
break;
case V_66 :
V_58 = V_4 -> V_32 ;
break;
case V_67 :
V_58 = V_4 -> V_30 ;
break;
case V_68 :
V_58 = V_4 -> V_26 ;
break;
default:
return - V_37 ;
}
* V_56 = F_16 ( V_57 , V_58 ) ;
return 0 ;
}
static int F_17 ( struct V_41 * V_42 ,
unsigned int V_55 ,
unsigned long * V_69 ,
unsigned V_70 )
{
struct V_1 * V_2 = F_6 ( V_42 ) ;
struct V_3 * V_4 = V_2 -> V_48 . V_46 [ V_55 ] . V_54 ;
unsigned V_57 ;
unsigned V_58 ;
unsigned V_71 ;
for ( V_71 = 0 ; V_71 < V_70 ; V_71 ++ ) {
V_57 = F_15 ( V_69 [ V_71 ] ) ;
V_58 = F_18 ( V_69 [ V_71 ] ) ;
switch ( V_57 ) {
case V_59 :
V_4 -> V_18 = V_58 ;
break;
case V_60 :
V_4 -> V_16 = true ;
break;
case V_61 :
V_4 -> V_13 = true ;
break;
case V_62 :
V_4 -> V_14 = true ;
V_4 -> V_25 = ! ! V_58 ;
break;
case V_63 :
V_4 -> V_27 = V_58 ;
break;
case V_64 :
V_4 -> V_34 = V_58 ;
break;
case V_65 :
V_4 -> V_11 = V_58 ;
break;
case V_66 :
V_4 -> V_32 = V_58 ;
break;
case V_67 :
V_4 -> V_30 = V_58 ;
break;
case V_68 :
V_4 -> V_26 = ! ! V_58 ;
break;
default:
F_4 ( V_2 -> V_40 ,
L_2 ,
V_57 ) ;
return - V_37 ;
}
}
F_1 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_19 ( struct V_72 * V_73 ,
unsigned V_55 )
{
struct V_1 * V_2 = F_20 ( V_73 ) ;
struct V_3 * V_4 = V_2 -> V_48 . V_46 [ V_55 ] . V_54 ;
switch ( V_4 -> V_9 ) {
case V_10 :
V_4 -> V_13 = true ;
break;
case V_28 :
V_4 -> V_13 = true ;
V_4 -> V_14 = true ;
break;
case V_33 :
return - V_37 ;
}
F_1 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_21 ( struct V_72 * V_73 ,
unsigned V_55 ,
int V_74 )
{
struct V_1 * V_2 = F_20 ( V_73 ) ;
struct V_3 * V_4 = V_2 -> V_48 . V_46 [ V_55 ] . V_54 ;
switch ( V_4 -> V_9 ) {
case V_10 :
V_4 -> V_14 = true ;
break;
case V_28 :
V_4 -> V_13 = false ;
V_4 -> V_14 = true ;
break;
case V_33 :
V_4 -> V_13 = false ;
V_4 -> V_14 = true ;
break;
}
F_1 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_22 ( struct V_72 * V_73 , unsigned V_55 )
{
struct V_1 * V_2 = F_20 ( V_73 ) ;
struct V_3 * V_4 = V_2 -> V_48 . V_46 [ V_55 ] . V_54 ;
bool V_75 ;
int V_7 ;
if ( ! V_4 -> V_13 )
return ! ! V_4 -> V_25 ;
V_7 = F_23 ( V_4 -> V_76 , V_77 , & V_75 ) ;
if ( ! V_7 )
V_7 = ! ! V_75 ;
return V_7 ;
}
static void F_24 ( struct V_72 * V_73 , unsigned V_55 , int V_74 )
{
struct V_1 * V_2 = F_20 ( V_73 ) ;
struct V_3 * V_4 = V_2 -> V_48 . V_46 [ V_55 ] . V_54 ;
V_4 -> V_25 = ! ! V_74 ;
F_1 ( V_2 , V_4 ) ;
}
static int F_25 ( struct V_72 * V_73 ,
const struct V_78 * V_79 ,
T_2 * V_80 )
{
if ( V_73 -> V_81 < 2 )
return - V_37 ;
if ( V_80 )
* V_80 = V_79 -> args [ 1 ] ;
return V_79 -> args [ 0 ] - 1 ;
}
static int F_26 ( struct V_72 * V_73 , unsigned V_55 )
{
struct V_1 * V_2 = F_20 ( V_73 ) ;
struct V_3 * V_4 = V_2 -> V_48 . V_46 [ V_55 ] . V_54 ;
return V_4 -> V_76 ;
}
static void F_27 ( struct V_82 * V_83 ,
struct V_41 * V_42 ,
struct V_72 * V_73 ,
unsigned V_55 ,
unsigned V_84 )
{
struct V_1 * V_2 = F_20 ( V_73 ) ;
struct V_3 * V_4 = V_2 -> V_48 . V_46 [ V_55 ] . V_54 ;
static const char * const V_85 [] = {
L_3 , L_4 , L_5 , L_6 , L_7 , L_8 , L_9 ,
L_10
} ;
static const char * const V_86 [] = {
L_11 , L_12 , L_13 , L_14 , L_15 , L_8 , L_9 ,
L_10 ,
} ;
F_28 ( V_83 , L_16 , V_55 + 1 ) ;
switch ( V_4 -> V_9 ) {
case V_10 :
F_29 ( V_83 , L_17 ) ;
if ( V_4 -> V_11 ) {
F_28 ( V_83 , L_18 , V_4 -> V_11 ) ;
} else if ( V_4 -> V_13 && V_4 -> V_14 ) {
if ( V_4 -> V_16 )
F_29 ( V_83 , L_19 ) ;
else
F_28 ( V_83 , L_20 , V_4 -> V_18 ) ;
} else if ( V_4 -> V_13 ) {
if ( V_4 -> V_11 )
F_28 ( V_83 , L_21 , V_4 -> V_11 ) ;
else
F_29 ( V_83 , L_22 ) ;
} else if ( V_4 -> V_14 ) {
F_29 ( V_83 , L_23 ) ;
if ( ! V_4 -> V_26 ) {
F_29 ( V_83 , V_4 -> V_25 ?
L_24 : L_25 ) ;
} else {
F_29 ( V_83 , V_4 -> V_25 ?
L_26 : L_27 ) ;
}
}
break;
case V_28 :
F_29 ( V_83 , L_28 ) ;
if ( V_4 -> V_14 ) {
F_28 ( V_83 , L_29 , V_85 [ V_4 -> V_30 ] ) ;
if ( ! V_4 -> V_26 ) {
F_29 ( V_83 , V_4 -> V_25 ?
L_24 : L_25 ) ;
} else {
F_29 ( V_83 , V_4 -> V_25 ?
L_26 : L_27 ) ;
}
} else {
F_28 ( V_83 , L_30 , V_86 [ V_4 -> V_32 ] ) ;
}
break;
case V_33 :
F_28 ( V_83 , L_31 , V_4 -> V_34 ) ;
if ( V_4 -> V_11 ) {
F_28 ( V_83 , L_32 , V_4 -> V_11 ) ;
} else {
if ( ! V_4 -> V_26 ) {
F_29 ( V_83 , V_4 -> V_25 ?
L_24 : L_25 ) ;
} else {
F_29 ( V_83 , V_4 -> V_25 ?
L_26 : L_27 ) ;
}
}
break;
}
}
static void F_30 ( struct V_82 * V_83 , struct V_72 * V_73 )
{
unsigned V_84 = V_73 -> V_87 ;
unsigned V_71 ;
for ( V_71 = 0 ; V_71 < V_73 -> V_88 ; V_71 ++ , V_84 ++ ) {
F_27 ( V_83 , NULL , V_73 , V_71 , V_84 ) ;
F_29 ( V_83 , L_33 ) ;
}
}
static int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_8 ;
unsigned V_5 ;
unsigned V_6 ;
unsigned type ;
int V_7 ;
V_7 = F_32 ( V_2 -> V_38 , V_4 -> V_39 , & V_8 ) ;
if ( V_7 ) {
F_4 ( V_2 -> V_40 , L_34 ) ;
return V_7 ;
}
type = ( V_8 >> 5 ) & 7 ;
V_5 = ( V_8 >> 2 ) & 7 ;
V_6 = ( V_8 ) & 3 ;
switch ( type ) {
case V_22 :
V_4 -> V_9 = V_10 ;
V_4 -> V_13 = true ;
V_4 -> V_27 = V_5 ;
V_4 -> V_11 = V_6 ;
break;
case V_24 :
V_4 -> V_9 = V_10 ;
V_4 -> V_14 = true ;
V_4 -> V_27 = V_5 ;
V_4 -> V_25 = ! ! ( V_6 & F_2 ( 0 ) ) ;
V_4 -> V_26 = ! ! ( V_6 & F_2 ( 1 ) ) ;
break;
case V_15 :
V_4 -> V_9 = V_10 ;
V_4 -> V_13 = true ;
V_4 -> V_14 = true ;
V_4 -> V_27 = V_5 ;
switch ( V_6 ) {
case V_19 :
V_4 -> V_18 = 600 ;
break;
case V_17 :
V_4 -> V_16 = true ;
break;
case V_20 :
V_4 -> V_18 = 10000 ;
break;
case V_21 :
V_4 -> V_18 = 30000 ;
break;
}
break;
case V_31 :
V_4 -> V_9 = V_28 ;
V_4 -> V_13 = true ;
V_4 -> V_32 = V_5 ;
break;
case V_29 :
V_4 -> V_9 = V_28 ;
V_4 -> V_14 = true ;
V_4 -> V_30 = V_5 ;
V_4 -> V_25 = ! ! ( V_6 & F_2 ( 0 ) ) ;
V_4 -> V_26 = ! ! ( V_6 & F_2 ( 1 ) ) ;
break;
case V_36 :
V_4 -> V_9 = V_33 ;
V_4 -> V_34 = 5 * ( V_5 + 1 ) ;
V_4 -> V_25 = ! ! ( V_6 & F_2 ( 0 ) ) ;
V_4 -> V_26 = ! ! ( V_6 & F_2 ( 1 ) ) ;
break;
case V_35 :
V_4 -> V_9 = V_33 ;
V_4 -> V_11 = V_6 + 1 ;
V_4 -> V_34 = 5 * ( V_5 + 1 ) ;
break;
case V_12 :
V_4 -> V_9 = V_10 ;
V_4 -> V_27 = V_5 ;
if ( V_6 >= 1 )
V_4 -> V_11 = V_6 ;
break;
}
return 0 ;
}
static int F_33 ( struct V_89 * V_90 )
{
struct V_3 * V_91 ;
struct V_92 * V_46 ;
struct V_1 * V_2 ;
int V_7 ;
int V_71 , V_43 ;
V_2 = F_34 ( & V_90 -> V_40 , sizeof( * V_2 ) , V_93 ) ;
if ( ! V_2 )
return - V_94 ;
V_2 -> V_40 = & V_90 -> V_40 ;
V_43 = F_35 ( V_90 ) ;
if ( ! V_43 )
return - V_37 ;
if ( V_43 < 0 )
return V_43 ;
V_2 -> V_43 = V_43 ;
V_2 -> V_38 = F_36 ( V_90 -> V_40 . V_95 , NULL ) ;
if ( ! V_2 -> V_38 ) {
F_4 ( & V_90 -> V_40 , L_35 ) ;
return - V_96 ;
}
V_2 -> V_48 = V_97 ;
V_2 -> V_48 . V_43 = V_2 -> V_43 ;
V_46 = F_37 ( & V_90 -> V_40 ,
V_2 -> V_48 . V_43 ,
sizeof( struct V_92 ) ,
V_93 ) ;
if ( ! V_46 )
return - V_94 ;
V_91 = F_37 ( & V_90 -> V_40 ,
V_2 -> V_48 . V_43 ,
sizeof( struct V_3 ) ,
V_93 ) ;
if ( ! V_91 )
return - V_94 ;
for ( V_71 = 0 ; V_71 < V_2 -> V_48 . V_43 ; V_71 ++ ) {
V_91 [ V_71 ] . V_39 = F_38 ( V_71 ) ;
V_91 [ V_71 ] . V_76 = F_39 ( V_90 , V_71 ) ;
if ( V_91 [ V_71 ] . V_76 < 0 ) {
F_4 ( & V_90 -> V_40 ,
L_36 , V_71 ) ;
return V_91 [ V_71 ] . V_76 ;
}
V_7 = F_31 ( V_2 , & V_91 [ V_71 ] ) ;
if ( V_7 )
return V_7 ;
V_46 [ V_71 ] . V_49 = V_71 ;
V_46 [ V_71 ] . V_98 = V_45 [ V_71 ] ;
V_46 [ V_71 ] . V_54 = & V_91 [ V_71 ] ;
}
V_2 -> V_48 . V_46 = V_46 ;
V_2 -> V_48 . V_99 = F_10 ( V_100 ) ;
V_2 -> V_48 . V_101 = V_100 ;
#ifdef F_40
V_2 -> V_48 . V_102 = V_103 ;
#endif
V_2 -> V_2 = F_41 ( & V_90 -> V_40 , & V_2 -> V_48 , V_2 ) ;
if ( F_42 ( V_2 -> V_2 ) ) {
F_4 ( & V_90 -> V_40 , L_37 ) ;
return F_43 ( V_2 -> V_2 ) ;
}
V_2 -> V_73 = V_104 ;
V_2 -> V_73 . V_87 = - 1 ;
V_2 -> V_73 . V_95 = & V_90 -> V_40 ;
V_2 -> V_73 . V_105 = V_90 -> V_40 . V_105 ;
V_2 -> V_73 . V_81 = 2 ;
V_2 -> V_73 . V_106 = F_44 ( V_2 -> V_40 ) ;
V_2 -> V_73 . V_88 = V_2 -> V_43 ;
V_7 = F_45 ( & V_2 -> V_73 , V_2 ) ;
if ( V_7 ) {
F_4 ( & V_90 -> V_40 , L_38 ) ;
return V_7 ;
}
V_7 = F_46 ( & V_2 -> V_73 ,
F_44 ( V_2 -> V_40 ) ,
0 , 0 , V_2 -> V_73 . V_88 ) ;
if ( V_7 ) {
F_4 ( V_2 -> V_40 , L_39 ) ;
goto V_107;
}
F_47 ( V_90 , V_2 ) ;
F_48 ( & V_90 -> V_40 , L_40 ) ;
return 0 ;
V_107:
F_49 ( & V_2 -> V_73 ) ;
return V_7 ;
}
static int F_50 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_51 ( V_90 ) ;
F_49 ( & V_2 -> V_73 ) ;
return 0 ;
}
