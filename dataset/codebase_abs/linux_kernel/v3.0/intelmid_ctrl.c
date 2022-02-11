static inline int F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 , int V_5 )
{
F_2 ( ! V_2 ) ;
V_2 -> type = V_6 ;
V_2 -> V_7 = V_3 ;
V_2 -> V_8 . integer . V_5 = V_5 ;
V_2 -> V_8 . integer . V_4 = V_4 ;
return 0 ;
}
static int F_3 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
F_2 ( ! V_2 ) ;
F_2 ( ! V_10 ) ;
V_2 -> type = V_11 ;
V_2 -> V_7 = V_12 ;
V_2 -> V_8 . integer . V_5 = V_13 ;
V_2 -> V_8 . integer . V_4 = V_14 ;
return 0 ;
}
static int F_4 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
F_1 ( V_2 , V_12 ,
V_15 [ V_16 ] . V_17 ,
V_15 [ V_16 ] . V_18 ) ;
return 0 ;
}
static int F_5 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
F_1 ( V_2 , V_19 ,
V_15 [ V_16 ] . V_20 ,
V_15 [ V_16 ] . V_21 ) ;
return 0 ;
}
static int F_6 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
F_1 ( V_2 , V_19 ,
V_15 [ V_16 ] . V_22 ,
V_15 [ V_16 ] . V_23 ) ;
return 0 ;
}
static int F_7 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
F_2 ( ! V_10 ) ;
F_2 ( ! V_2 ) ;
if ( V_10 -> V_24 . V_25 == V_26 )
V_2 -> V_8 . V_27 . V_28 = F_8 ( V_29 ) ;
else
V_2 -> V_8 . V_27 . V_28 = F_8 ( V_30 ) ;
V_2 -> V_7 = V_12 ;
V_2 -> type = V_31 ;
if ( V_2 -> V_8 . V_27 . V_32 >= V_2 -> V_8 . V_27 . V_28 )
V_2 -> V_8 . V_27 . V_32 = 1 ;
if ( V_10 -> V_24 . V_25 == V_26 )
strncpy ( V_2 -> V_8 . V_27 . V_33 ,
V_29 [ V_2 -> V_8 . V_27 . V_32 ] ,
sizeof( V_2 -> V_8 . V_27 . V_33 ) - 1 ) ;
else
strncpy ( V_2 -> V_8 . V_27 . V_33 ,
V_30 [ V_2 -> V_8 . V_27 . V_32 ] ,
sizeof( V_2 -> V_8 . V_27 . V_33 ) - 1 ) ;
return 0 ;
}
static int F_9 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
struct V_34 * V_35 ;
struct V_36 * V_37 ;
F_2 ( ! V_10 ) ;
F_2 ( ! V_2 ) ;
V_37 = V_10 -> V_38 ;
F_2 ( ! V_37 -> V_39 ) ;
V_35 = V_37 -> V_39 -> V_35 ;
if ( V_10 -> V_24 . V_25 == V_26 )
V_2 -> V_8 . V_27 . V_28 = F_8 ( V_40 ) ;
else if ( V_10 -> V_24 . V_25 == V_41 )
V_2 -> V_8 . V_27 . V_28 = F_8 ( V_42 ) ;
else if ( V_10 -> V_24 . V_25 == V_43 ) {
V_2 -> V_8 . V_27 . V_28 = F_8 ( V_44 ) ;
V_35 -> V_45 = V_2 -> V_8 . V_27 . V_28 ;
} else
return - V_46 ;
V_2 -> V_7 = V_12 ;
V_2 -> type = V_31 ;
if ( V_2 -> V_8 . V_27 . V_32 >= V_2 -> V_8 . V_27 . V_28 )
V_2 -> V_8 . V_27 . V_32 = 1 ;
if ( V_10 -> V_24 . V_25 == V_26 )
strncpy ( V_2 -> V_8 . V_27 . V_33 ,
V_40 [ V_2 -> V_8 . V_27 . V_32 ] ,
sizeof( V_2 -> V_8 . V_27 . V_33 ) - 1 ) ;
else if ( V_10 -> V_24 . V_25 == V_41 )
strncpy ( V_2 -> V_8 . V_27 . V_33 ,
V_42 [ V_2 -> V_8 . V_27 . V_32 ] ,
sizeof( V_2 -> V_8 . V_27 . V_33 ) - 1 ) ;
else if ( V_10 -> V_24 . V_25 == V_43 )
strncpy ( V_2 -> V_8 . V_27 . V_33 ,
V_44 [ V_2 -> V_8 . V_27 . V_32 ] ,
sizeof( V_2 -> V_8 . V_27 . V_33 ) - 1 ) ;
else
return - V_46 ;
return 0 ;
}
static int F_10 ( struct V_9 * V_10 ,
struct V_47 * V_48 )
{
int V_49 = 0 , V_50 [ 2 ] = { 0 ,} ;
int V_8 = 0 ;
struct V_36 * V_37 ;
struct V_34 * V_35 ;
F_11 ( L_1 ) ;
F_2 ( ! V_48 ) ;
F_2 ( ! V_10 ) ;
V_37 = V_10 -> V_38 ;
F_2 ( ! V_37 -> V_39 ) ;
V_35 = V_37 -> V_39 -> V_35 ;
F_2 ( ! V_35 ) ;
switch ( V_10 -> V_24 . V_25 ) {
case V_51 :
V_50 [ 0 ] = V_52 ;
V_50 [ 1 ] = V_53 ;
break;
case V_54 :
V_50 [ 0 ] = V_55 ;
break;
case V_56 :
V_50 [ 0 ] = V_57 ;
V_50 [ 1 ] = V_58 ;
break;
default:
return - V_46 ;
}
V_49 = V_35 -> V_59 ( V_50 [ 0 ] , & V_8 ) ;
V_48 -> V_8 . integer . V_8 [ 0 ] = V_8 ;
if ( V_49 )
return V_49 ;
if ( V_10 -> V_24 . V_25 == V_51 ||
V_10 -> V_24 . V_25 == V_56 ) {
V_49 = V_35 -> V_59 ( V_50 [ 1 ] , & V_8 ) ;
V_48 -> V_8 . integer . V_8 [ 1 ] = V_8 ;
}
return V_49 ;
}
static int F_12 ( struct V_9 * V_10 ,
struct V_47 * V_48 )
{
int V_50 = 0 , V_49 = 0 ;
T_1 V_8 = 0 ;
struct V_36 * V_37 ;
struct V_34 * V_35 ;
F_11 ( L_2 ) ;
F_2 ( ! V_48 ) ;
F_2 ( ! V_10 ) ;
V_37 = V_10 -> V_38 ;
F_2 ( ! V_37 -> V_39 ) ;
V_35 = V_37 -> V_39 -> V_35 ;
F_2 ( ! V_35 ) ;
switch ( V_10 -> V_24 . V_25 ) {
case V_60 :
if ( V_37 -> V_61 == V_62 )
V_50 = V_63 ;
else if ( ( V_37 -> V_61 == V_64 ) ||
( V_37 -> V_61 == V_65 ) )
V_50 = V_66 ;
break;
case V_67 :
if ( V_37 -> V_68 == V_69 )
V_50 = V_70 ;
else if ( V_37 -> V_68 == V_71 )
V_50 = V_72 ;
else if ( V_37 -> V_68 == V_73 )
V_50 = V_74 ;
break;
case V_75 :
V_48 -> V_8 . integer . V_8 [ 0 ] = V_37 -> V_76 ;
return 0 ;
default:
return - V_46 ;
}
V_49 = V_35 -> V_77 ( V_50 , & V_8 ) ;
V_48 -> V_8 . integer . V_8 [ 0 ] = V_8 ;
return V_49 ;
}
static int F_13 ( struct V_9 * V_10 ,
struct V_47 * V_48 )
{
int V_49 , V_50 [ 2 ] = { 0 ,} ;
struct V_36 * V_37 ;
struct V_34 * V_35 ;
F_11 ( L_3 ,
V_48 -> V_8 . integer . V_8 [ 0 ] ,
V_48 -> V_8 . integer . V_8 [ 1 ] ) ;
F_2 ( ! V_48 ) ;
F_2 ( ! V_10 ) ;
V_37 = V_10 -> V_38 ;
F_2 ( ! V_37 -> V_39 ) ;
V_35 = V_37 -> V_39 -> V_35 ;
F_2 ( ! V_35 ) ;
switch ( V_10 -> V_24 . V_25 ) {
case V_51 :
V_50 [ 0 ] = V_53 ;
V_50 [ 1 ] = V_52 ;
break;
case V_54 :
V_50 [ 0 ] = V_55 ;
break;
case V_56 :
V_50 [ 0 ] = V_58 ;
V_50 [ 1 ] = V_57 ;
break;
default:
return - V_46 ;
}
V_49 = V_35 -> V_78 ( V_50 [ 0 ] ,
V_48 -> V_8 . integer . V_8 [ 0 ] ) ;
if ( V_49 )
return V_49 ;
if ( V_10 -> V_24 . V_25 == V_51 ||
V_10 -> V_24 . V_25 == V_56 )
V_49 = V_35 -> V_78 ( V_50 [ 1 ] ,
V_48 -> V_8 . integer . V_8 [ 1 ] ) ;
return V_49 ;
}
static int F_14 ( struct V_9 * V_10 ,
struct V_47 * V_48 )
{
int V_50 [ 2 ] = { 0 ,} , V_49 ;
struct V_36 * V_37 ;
struct V_34 * V_35 ;
F_11 ( L_4 ) ;
F_2 ( ! V_48 ) ;
F_2 ( ! V_10 ) ;
V_37 = V_10 -> V_38 ;
F_2 ( ! V_37 -> V_39 ) ;
V_35 = V_37 -> V_39 -> V_35 ;
F_2 ( ! V_35 ) ;
V_10 -> V_79 = V_48 -> V_8 . integer . V_8 [ 0 ] ;
switch ( V_10 -> V_24 . V_25 ) {
case V_60 :
if ( V_37 -> V_61 == V_62 ) {
V_50 [ 0 ] = V_63 ;
V_50 [ 1 ] = V_80 ;
} else if ( ( V_37 -> V_61 == V_64 ) ||
( V_37 -> V_61 == V_65 ) ) {
V_50 [ 0 ] = V_66 ;
V_50 [ 1 ] = V_81 ;
}
break;
case V_67 :
if ( V_37 -> V_68 == V_69 )
V_50 [ 0 ] = V_70 ;
else if ( V_37 -> V_68 == V_71 )
V_50 [ 0 ] = V_72 ;
else if ( V_37 -> V_68 == V_73 )
V_50 [ 0 ] = V_74 ;
break;
case V_75 :
V_50 [ 0 ] = V_82 ;
V_37 -> V_76 = V_48 -> V_8 . integer . V_8 [ 0 ] ;
break;
default:
return - V_46 ;
}
V_49 = V_35 -> V_83 ( V_50 [ 0 ] ,
V_48 -> V_8 . integer . V_8 [ 0 ] ) ;
if ( V_49 )
return V_49 ;
if ( V_10 -> V_24 . V_25 == V_60 )
V_49 = V_35 -> V_83 ( V_50 [ 1 ] ,
V_48 -> V_8 . integer . V_8 [ 0 ] ) ;
return V_49 ;
}
static int F_15 ( struct V_9 * V_10 ,
struct V_47 * V_48 )
{
struct V_36 * V_37 ;
struct V_34 * V_35 ;
F_11 ( L_5 ) ;
F_2 ( ! V_48 ) ;
F_2 ( ! V_10 ) ;
V_37 = V_10 -> V_38 ;
V_35 = V_37 -> V_39 -> V_35 ;
if ( V_37 -> V_84 == V_85 ) {
if ( V_10 -> V_24 . V_25 == V_26 )
V_48 -> V_8 . V_27 . V_32 [ 0 ] =
V_35 -> V_86 ;
else if ( V_10 -> V_24 . V_25 == V_41 )
V_48 -> V_8 . V_27 . V_32 [ 0 ] =
V_35 -> V_87 ;
else if ( V_10 -> V_24 . V_25 == V_43 )
V_48 -> V_8 . V_27 . V_32 [ 0 ] =
V_35 -> V_88 ;
else
return - V_46 ;
} else if ( V_37 -> V_84 == V_89 ) {
if ( V_10 -> V_24 . V_25 == V_26 )
if ( V_35 -> V_86 == V_65 ||
V_35 -> V_86 == V_64 )
V_48 -> V_8 . V_27 . V_32 [ 0 ] = V_65 ;
else if ( V_35 -> V_86 == V_62 )
V_48 -> V_8 . V_27 . V_32 [ 0 ] =
V_62 ;
else
return - V_46 ;
else if ( V_10 -> V_24 . V_25 == V_41 )
V_48 -> V_8 . V_27 . V_32 [ 0 ] =
V_35 -> V_87 ;
else
return - V_46 ;
} else
V_48 -> V_8 . V_27 . V_32 [ 0 ] = V_10 -> V_79 ;
return 0 ;
}
static int F_16 ( struct V_9 * V_10 ,
struct V_47 * V_48 )
{
struct V_36 * V_37 ;
struct V_34 * V_35 ;
int V_49 = 0 , V_90 , V_91 ;
struct V_92 * V_93 ;
F_11 ( L_6 ) ;
F_2 ( ! V_48 ) ;
F_2 ( ! V_10 ) ;
V_91 = - 1 ;
V_37 = V_10 -> V_38 ;
F_2 ( ! V_37 -> V_39 ) ;
V_35 = V_37 -> V_39 -> V_35 ;
F_2 ( ! V_35 ) ;
V_10 -> V_79 = V_48 -> V_8 . V_27 . V_32 [ 0 ] ;
switch ( V_10 -> V_24 . V_25 ) {
case V_26 :
V_49 = V_35 -> V_94 (
V_48 -> V_8 . V_27 . V_32 [ 0 ] ) ;
V_37 -> V_61 = V_48 -> V_8 . V_27 . V_32 [ 0 ] ;
break;
case V_41 :
V_90 = V_37 -> V_39 -> V_95 ;
if ( ( V_90 == V_96 ) || ( V_90 == V_97 ) ) {
V_93 = V_37 -> V_39 -> V_93 ;
if ( V_48 -> V_8 . V_27 . V_32 [ 0 ] == V_73 )
V_91 = 1 ;
else
V_91 = 0 ;
V_93 -> V_98 (
V_99 , & V_91 ) ;
}
V_49 = V_35 -> V_100 (
V_48 -> V_8 . V_27 . V_32 [ 0 ] ) ;
V_37 -> V_68 = V_48 -> V_8 . V_27 . V_32 [ 0 ] ;
break;
case V_43 :
V_49 = V_35 -> V_101 (
V_48 -> V_8 . V_27 . V_32 [ 0 ] ) ;
V_37 -> V_102 = V_48 -> V_8 . V_27 . V_32 [ 0 ] ;
break;
default:
return - V_46 ;
}
V_10 -> V_79 = V_48 -> V_8 . V_27 . V_32 [ 0 ] ;
return V_49 ;
}
static int F_17 ( struct V_9 * V_10 ,
struct V_47 * V_48 )
{
struct V_36 * V_37 ;
struct V_34 * V_35 ;
F_2 ( ! V_48 ) ;
F_2 ( ! V_10 ) ;
V_37 = V_10 -> V_38 ;
V_35 = V_37 -> V_39 -> V_35 ;
if ( V_35 -> V_87 != V_69 ) {
F_11 ( L_7 , V_35 -> V_87 ) ;
return 0 ;
}
if ( V_37 -> V_84 == V_85 )
V_48 -> V_8 . V_27 . V_32 [ 0 ] = V_10 -> V_79 ;
else
F_11 ( L_8 ,
V_37 -> V_84 ) ;
return 0 ;
}
void F_18 ( T_1 V_103 , unsigned int * V_104 )
{
* V_104 |= ( 1 << V_103 ) ;
}
void F_19 ( T_1 V_103 , unsigned int * V_104 )
{
* V_104 &= ~ ( 1 << V_103 ) ;
}
int F_20 ( T_1 V_103 , unsigned int * V_104 )
{
int V_49 ;
V_49 = ( * V_104 & ( 1 << V_103 ) ) ;
return V_49 ;
}
static int F_21 ( struct V_9 * V_10 ,
struct V_47 * V_48 )
{
struct V_36 * V_37 ;
struct V_34 * V_35 ;
int V_105 , V_106 ;
unsigned int V_104 ;
int V_107 ;
int V_108 = F_8 ( V_109 ) ;
F_2 ( ! V_48 ) ;
F_2 ( ! V_10 ) ;
V_37 = V_10 -> V_38 ;
F_2 ( ! V_37 -> V_39 ) ;
V_35 = V_37 -> V_39 -> V_35 ;
F_2 ( ! V_35 ) ;
if ( V_35 -> V_87 != V_69 ) {
F_11 ( L_7 , V_35 -> V_87 ) ;
return 0 ;
}
V_104 = V_35 -> V_104 ;
if ( V_10 -> V_79 > V_48 -> V_8 . V_27 . V_32 [ 0 ] ) {
F_11 ( L_9 ) ;
V_107 = - 1 ;
} else {
F_11 ( L_10 ) ;
V_107 = 1 ;
}
V_106 = V_48 -> V_8 . V_27 . V_32 [ 0 ] ;
F_11 ( L_11 ,
V_106 , V_104 ) ;
for ( V_105 = 0 ; V_105 < V_108 ; V_105 ++ ) {
F_11 ( L_12 ,
V_105 , V_106 ) ;
if ( ! F_20 ( V_106 , & V_104 ) ) {
F_19 ( V_10 -> V_79 ,
& V_104 ) ;
F_18 ( V_106 , & V_104 ) ;
V_10 -> V_79 = V_106 ;
V_35 -> V_104 = V_104 ;
V_35 -> V_110 [ V_10 -> V_24 . V_25 - V_111 ] =
V_10 -> V_79 ;
V_35 -> V_112
( V_10 -> V_24 . V_25 - V_111 ) ;
return 0 ;
}
V_106 += V_107 ;
if ( V_106 > ( V_108 - 1 ) && V_107 == 1 ) {
F_11 ( L_13 ) ;
V_106 = 0 ;
} else if ( V_106 == - 1 && V_107 == - 1 ) {
F_11 ( L_14 ) ;
V_106 = V_108 - 1 ;
}
}
return - V_46 ;
}
static int F_22 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
struct V_36 * V_37 ;
struct V_34 * V_35 ;
V_2 -> V_7 = V_12 ;
V_2 -> type = V_31 ;
V_2 -> V_8 . V_27 . V_28 = F_8 ( V_109 ) ;
V_37 = V_10 -> V_38 ;
F_2 ( ! V_37 -> V_39 ) ;
V_35 = V_37 -> V_39 -> V_35 ;
F_2 ( ! V_35 ) ;
if ( V_2 -> V_8 . V_27 . V_32 >= V_2 -> V_8 . V_27 . V_28 )
V_2 -> V_8 . V_27 . V_32 =
V_2 -> V_8 . V_27 . V_28 - 1 ;
strncpy ( V_2 -> V_8 . V_27 . V_33 ,
V_109 [ V_2 -> V_8 . V_27 . V_32 ] ,
sizeof( V_2 -> V_8 . V_27 . V_33 ) - 1 ) ;
F_18 ( V_10 -> V_79 , & V_35 -> V_104 ) ;
F_11 ( L_15 ,
V_35 -> V_104 ) ;
V_35 -> V_110 [ V_10 -> V_24 . V_25 - V_111 ] =
V_10 -> V_79 ;
return 0 ;
}
