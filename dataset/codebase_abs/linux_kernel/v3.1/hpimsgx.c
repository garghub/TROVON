static T_1 * F_1 ( const struct V_1
* V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_4 [ V_3 ] . V_5 != 0 ; V_3 ++ ) {
if ( V_4 [ V_3 ] . V_5 != V_6
&& V_4 [ V_3 ] . V_5 !=
V_2 -> V_7 -> V_5 )
continue;
if ( V_4 [ V_3 ] . V_8 != V_6
&& V_4 [ V_3 ] . V_8 !=
V_2 -> V_7 -> V_8 )
continue;
if ( V_4 [ V_3 ] . V_9 != V_6
&& V_4 [ V_3 ] . V_9 !=
V_2 -> V_7 -> V_10 )
continue;
if ( V_4 [ V_3 ] . V_11 != V_6
&& V_4 [ V_3 ] . V_11 !=
V_2 -> V_7 -> V_12 )
continue;
return ( T_1 * ) V_4 [ V_3 ] . V_13 ;
}
return NULL ;
}
static inline void F_2 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
if ( ( V_15 -> V_18 < V_19 )
&& V_20 [ V_15 -> V_18 ] )
V_20 [ V_15 -> V_18 ] ( V_15 , V_17 ) ;
else
F_3 ( V_17 , V_15 -> V_21 , V_15 -> V_22 ,
V_23 ) ;
}
static void F_4 ( struct V_14 * V_15 , struct V_16 * V_17 ,
void * V_24 )
{
if ( V_15 -> V_18 != V_25 )
F_5 ( V_26 ,
L_1 ,
V_15 -> V_18 , V_15 -> V_22 ) ;
switch ( V_15 -> V_22 ) {
case V_27 :
F_3 ( V_17 , V_28 ,
V_27 , 0 ) ;
V_17 -> V_29 . V_30 . V_31 = V_32 >> 8 ;
V_17 -> V_29 . V_30 . V_33 = V_32 ;
break;
case V_34 :
F_3 ( V_17 , V_28 , V_34 , 0 ) ;
break;
case V_35 :
F_3 ( V_17 , V_28 , V_35 ,
0 ) ;
F_6 ( V_36 , V_24 ) ;
break;
case V_37 :
F_7 ( & V_38 ) ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
F_8 ( V_36 ) ;
F_3 ( V_17 , V_28 ,
V_37 , 0 ) ;
F_9 ( V_15 , V_17 ) ;
break;
case V_39 :
F_9 ( V_15 , V_17 ) ;
F_6 ( V_36 , V_24 ) ;
F_3 ( V_17 , V_28 ,
V_39 , 0 ) ;
return;
case V_40 :
case V_41 :
F_9 ( V_15 , V_17 ) ;
break;
case V_42 :
F_10 ( V_15 , V_17 ) ;
break;
default:
F_3 ( V_17 , V_28 , V_15 -> V_22 ,
V_43 ) ;
break;
}
}
static void F_11 ( struct V_14 * V_15 , struct V_16 * V_17 ,
void * V_24 )
{
switch ( V_15 -> V_22 ) {
case V_44 :
F_12 ( V_15 , V_17 ) ;
break;
case V_45 :
F_13 ( V_15 , V_17 ) ;
break;
case V_46 :
F_6 ( V_15 -> V_18 , V_24 ) ;
{
struct V_14 V_47 ;
struct V_16 V_48 ;
F_14 ( & V_47 , & V_48 , V_49 ,
V_45 ) ;
V_47 . V_18 = V_15 -> V_18 ;
F_2 ( & V_47 , & V_48 ) ;
}
F_2 ( V_15 , V_17 ) ;
break;
default:
F_2 ( V_15 , V_17 ) ;
break;
}
}
static void F_15 ( struct V_14 * V_15 , struct V_16 * V_17 )
{
switch ( V_15 -> V_22 ) {
case V_50 :
F_16 ( V_15 , V_17 ) ;
break;
case V_51 :
F_17 ( V_15 , V_17 ) ;
break;
default:
F_2 ( V_15 , V_17 ) ;
break;
}
}
static void F_18 ( struct V_14 * V_15 ,
struct V_16 * V_17 , void * V_24 )
{
if ( V_15 -> V_52 >= V_53 [ V_15 -> V_18 ] . V_54 ) {
F_3 ( V_17 , V_55 , V_15 -> V_22 ,
V_56 ) ;
return;
}
switch ( V_15 -> V_22 ) {
case V_57 :
F_19 ( V_15 , V_17 , V_24 ) ;
break;
case V_58 :
F_20 ( V_15 , V_17 , V_24 ) ;
break;
default:
F_2 ( V_15 , V_17 ) ;
break;
}
}
static void F_21 ( struct V_14 * V_15 ,
struct V_16 * V_17 , void * V_24 )
{
if ( V_15 -> V_52 >= V_53 [ V_15 -> V_18 ] . V_59 ) {
F_3 ( V_17 , V_60 , V_15 -> V_22 ,
V_56 ) ;
return;
}
switch ( V_15 -> V_22 ) {
case V_61 :
F_22 ( V_15 , V_17 , V_24 ) ;
break;
case V_62 :
F_23 ( V_15 , V_17 , V_24 ) ;
break;
default:
F_2 ( V_15 , V_17 ) ;
break;
}
}
void F_24 ( struct V_14 * V_15 , struct V_16 * V_17 ,
void * V_24 )
{
F_25 ( V_63 , V_15 ) ;
if ( V_15 -> type != V_64 ) {
F_3 ( V_17 , V_15 -> V_21 , V_15 -> V_22 ,
V_65 ) ;
return;
}
if ( V_15 -> V_18 >= V_19
&& V_15 -> V_18 != V_36 ) {
F_3 ( V_17 , V_15 -> V_21 , V_15 -> V_22 ,
V_66 ) ;
return;
}
switch ( V_15 -> V_21 ) {
case V_28 :
F_4 ( V_15 , V_17 , V_24 ) ;
break;
case V_49 :
F_11 ( V_15 , V_17 , V_24 ) ;
break;
case V_67 :
F_15 ( V_15 , V_17 ) ;
break;
case V_55 :
F_18 ( V_15 , V_17 , V_24 ) ;
break;
case V_60 :
F_21 ( V_15 , V_17 , V_24 ) ;
break;
default:
F_2 ( V_15 , V_17 ) ;
break;
}
F_26 ( V_17 ) ;
}
static void F_12 ( struct V_14 * V_15 , struct V_16 * V_17 )
{
F_5 ( V_68 , L_2 ) ;
memcpy ( V_17 , & V_69 [ V_15 -> V_18 ] ,
sizeof( V_69 [ 0 ] ) ) ;
}
static void F_13 ( struct V_14 * V_15 , struct V_16 * V_17 )
{
F_5 ( V_68 , L_3 ) ;
F_3 ( V_17 , V_49 , V_45 , 0 ) ;
}
static void F_16 ( struct V_14 * V_15 , struct V_16 * V_17 )
{
memcpy ( V_17 , & V_70 [ V_15 -> V_18 ] ,
sizeof( V_70 [ 0 ] ) ) ;
}
static void F_17 ( struct V_14 * V_15 , struct V_16 * V_17 )
{
F_3 ( V_17 , V_67 , V_51 , 0 ) ;
}
static void F_22 ( struct V_14 * V_15 , struct V_16 * V_17 ,
void * V_24 )
{
struct V_14 V_47 ;
struct V_16 V_48 ;
F_3 ( V_17 , V_60 , V_61 , 0 ) ;
F_27 ( & V_38 ) ;
if ( V_71 [ V_15 -> V_18 ] [ V_15 -> V_52 ] . V_72 )
V_17 -> error = V_73 ;
else if ( V_74 [ V_15 -> V_18 ]
[ V_15 -> V_52 ] . V_75 . error )
memcpy ( V_17 ,
& V_74 [ V_15 -> V_18 ] [ V_15 ->
V_52 ] ,
sizeof( V_74 [ 0 ] [ 0 ] ) ) ;
else {
V_71 [ V_15 -> V_18 ] [ V_15 ->
V_52 ] . V_72 = 1 ;
F_28 ( & V_38 ) ;
F_14 ( & V_47 , & V_48 , V_60 ,
V_76 ) ;
V_47 . V_18 = V_15 -> V_18 ;
V_47 . V_52 = V_15 -> V_52 ;
F_2 ( & V_47 , & V_48 ) ;
F_27 ( & V_38 ) ;
if ( V_48 . error ) {
V_71 [ V_15 -> V_18 ] [ V_15 ->
V_52 ] . V_72 = 0 ;
V_17 -> error = V_48 . error ;
} else {
V_71 [ V_15 -> V_18 ] [ V_15 ->
V_52 ] . V_72 = 1 ;
V_71 [ V_15 -> V_18 ] [ V_15 ->
V_52 ] . V_24 = V_24 ;
memcpy ( V_17 ,
& V_74 [ V_15 -> V_18 ]
[ V_15 -> V_52 ] ,
sizeof( V_74 [ 0 ] [ 0 ] ) ) ;
}
}
F_28 ( & V_38 ) ;
}
static void F_23 ( struct V_14 * V_15 , struct V_16 * V_17 ,
void * V_24 )
{
struct V_14 V_47 ;
struct V_16 V_48 ;
F_3 ( V_17 , V_60 , V_62 , 0 ) ;
F_27 ( & V_38 ) ;
if ( V_24 ==
V_71 [ V_15 -> V_18 ] [ V_15 ->
V_52 ] . V_24 ) {
V_71 [ V_15 -> V_18 ] [ V_15 ->
V_52 ] . V_24 = NULL ;
F_28 ( & V_38 ) ;
F_14 ( & V_47 , & V_48 , V_60 ,
V_76 ) ;
V_47 . V_18 = V_15 -> V_18 ;
V_47 . V_52 = V_15 -> V_52 ;
F_2 ( & V_47 , & V_48 ) ;
F_27 ( & V_38 ) ;
if ( V_48 . error ) {
V_71 [ V_15 -> V_18 ] [ V_15 ->
V_52 ] . V_24 = V_24 ;
V_17 -> error = V_48 . error ;
} else {
V_71 [ V_15 -> V_18 ] [ V_15 ->
V_52 ] . V_72 = 0 ;
V_71 [ V_15 -> V_18 ] [ V_15 ->
V_52 ] . V_24 = NULL ;
}
} else {
F_5 ( V_26 ,
L_4 ,
V_24 , V_15 -> V_18 , V_15 -> V_52 ,
V_71 [ V_15 -> V_18 ] [ V_15 ->
V_52 ] . V_24 ) ;
V_17 -> error = V_77 ;
}
F_28 ( & V_38 ) ;
}
static void F_19 ( struct V_14 * V_15 , struct V_16 * V_17 ,
void * V_24 )
{
struct V_14 V_47 ;
struct V_16 V_48 ;
F_3 ( V_17 , V_55 , V_57 , 0 ) ;
F_27 ( & V_38 ) ;
if ( V_78 [ V_15 -> V_18 ] [ V_15 -> V_52 ] . V_72 )
V_17 -> error = V_73 ;
else if ( V_79 [ V_15 -> V_18 ]
[ V_15 -> V_52 ] . V_75 . error )
memcpy ( V_17 ,
& V_79 [ V_15 -> V_18 ] [ V_15 ->
V_52 ] ,
sizeof( V_79 [ 0 ] [ 0 ] ) ) ;
else {
V_78 [ V_15 -> V_18 ] [ V_15 ->
V_52 ] . V_72 = 1 ;
F_28 ( & V_38 ) ;
F_14 ( & V_47 , & V_48 , V_55 ,
V_80 ) ;
V_47 . V_18 = V_15 -> V_18 ;
V_47 . V_52 = V_15 -> V_52 ;
F_2 ( & V_47 , & V_48 ) ;
F_27 ( & V_38 ) ;
if ( V_48 . error ) {
V_78 [ V_15 -> V_18 ] [ V_15 ->
V_52 ] . V_72 = 0 ;
V_17 -> error = V_48 . error ;
} else {
V_78 [ V_15 -> V_18 ] [ V_15 ->
V_52 ] . V_72 = 1 ;
V_78 [ V_15 -> V_18 ] [ V_15 ->
V_52 ] . V_24 = V_24 ;
memcpy ( V_17 ,
& V_79 [ V_15 -> V_18 ]
[ V_15 -> V_52 ] ,
sizeof( V_79 [ 0 ] [ 0 ] ) ) ;
}
}
F_28 ( & V_38 ) ;
}
static void F_20 ( struct V_14 * V_15 , struct V_16 * V_17 ,
void * V_24 )
{
struct V_14 V_47 ;
struct V_16 V_48 ;
F_3 ( V_17 , V_55 , V_58 , 0 ) ;
F_27 ( & V_38 ) ;
if ( V_24 ==
V_78 [ V_15 -> V_18 ] [ V_15 ->
V_52 ] . V_24 ) {
V_78 [ V_15 -> V_18 ] [ V_15 ->
V_52 ] . V_24 = NULL ;
F_28 ( & V_38 ) ;
F_14 ( & V_47 , & V_48 , V_55 ,
V_80 ) ;
V_47 . V_18 = V_15 -> V_18 ;
V_47 . V_52 = V_15 -> V_52 ;
F_2 ( & V_47 , & V_48 ) ;
F_27 ( & V_38 ) ;
if ( V_48 . error ) {
V_78 [ V_15 -> V_18 ] [ V_15 ->
V_52 ] . V_24 = V_24 ;
V_17 -> error = V_48 . error ;
} else {
V_78 [ V_15 -> V_18 ] [ V_15 ->
V_52 ] . V_72 = 0 ;
V_78 [ V_15 -> V_18 ] [ V_15 ->
V_52 ] . V_24 = NULL ;
}
} else {
F_5 ( V_26 ,
L_5 ,
V_24 , V_15 -> V_18 , V_15 -> V_52 ,
V_78 [ V_15 -> V_18 ] [ V_15 ->
V_52 ] . V_24 ) ;
V_17 -> error = V_77 ;
}
F_28 ( & V_38 ) ;
}
static T_2 F_29 ( T_2 V_81 )
{
struct V_14 V_47 ;
struct V_16 V_48 ;
T_2 V_3 ;
F_14 ( & V_47 , & V_48 , V_49 ,
V_44 ) ;
V_47 . V_18 = V_81 ;
F_2 ( & V_47 , & V_48 ) ;
memcpy ( & V_69 [ V_81 ] , & V_48 ,
sizeof( V_69 [ 0 ] ) ) ;
if ( V_48 . error )
return V_48 . error ;
F_14 ( & V_47 , & V_48 , V_49 ,
V_82 ) ;
V_47 . V_18 = V_81 ;
F_2 ( & V_47 , & V_48 ) ;
if ( V_48 . error )
return V_48 . error ;
V_53 [ V_81 ] . V_54 = V_48 . V_29 . V_83 . V_84 . V_54 ;
V_53 [ V_81 ] . V_59 = V_48 . V_29 . V_83 . V_84 . V_59 ;
V_53 [ V_81 ] . type = V_48 . V_29 . V_83 . V_84 . V_85 ;
for ( V_3 = 0 ; V_3 < V_53 [ V_81 ] . V_54 ; V_3 ++ ) {
F_14 ( & V_47 , & V_48 , V_55 ,
V_57 ) ;
V_47 . V_18 = V_81 ;
V_47 . V_52 = V_3 ;
F_2 ( & V_47 , & V_48 ) ;
memcpy ( & V_79 [ V_81 ] [ V_3 ] , & V_48 ,
sizeof( V_79 [ 0 ] [ 0 ] ) ) ;
V_78 [ V_81 ] [ V_3 ] . V_72 = 0 ;
V_78 [ V_81 ] [ V_3 ] . V_24 = NULL ;
}
for ( V_3 = 0 ; V_3 < V_53 [ V_81 ] . V_59 ; V_3 ++ ) {
F_14 ( & V_47 , & V_48 , V_60 ,
V_61 ) ;
V_47 . V_18 = V_81 ;
V_47 . V_52 = V_3 ;
F_2 ( & V_47 , & V_48 ) ;
memcpy ( & V_74 [ V_81 ] [ V_3 ] , & V_48 ,
sizeof( V_74 [ 0 ] [ 0 ] ) ) ;
V_71 [ V_81 ] [ V_3 ] . V_72 = 0 ;
V_71 [ V_81 ] [ V_3 ] . V_24 = NULL ;
}
F_14 ( & V_47 , & V_48 , V_67 , V_50 ) ;
V_47 . V_18 = V_81 ;
F_2 ( & V_47 , & V_48 ) ;
memcpy ( & V_70 [ V_81 ] , & V_48 ,
sizeof( V_70 [ 0 ] ) ) ;
return 0 ;
}
static void F_8 ( T_2 V_18 )
{
int V_3 ;
T_2 V_81 ;
struct V_16 V_48 ;
if ( V_18 == V_36 ) {
for ( V_81 = 0 ; V_81 < V_19 ; V_81 ++ ) {
F_3 ( & V_48 , V_49 ,
V_44 , V_86 ) ;
memcpy ( & V_69 [ V_81 ] , & V_48 ,
sizeof( V_69 [ V_81 ] ) ) ;
F_3 ( & V_48 , V_67 , V_50 ,
V_87 ) ;
memcpy ( & V_70 [ V_81 ] , & V_48 ,
sizeof( V_70 [ V_81 ] ) ) ;
for ( V_3 = 0 ; V_3 < V_88 ; V_3 ++ ) {
F_3 ( & V_48 , V_55 ,
V_57 ,
V_87 ) ;
memcpy ( & V_79 [ V_81 ] [ V_3 ] ,
& V_48 ,
sizeof( V_79 [ V_81 ]
[ V_3 ] ) ) ;
F_3 ( & V_48 , V_60 ,
V_61 ,
V_87 ) ;
memcpy ( & V_74 [ V_81 ] [ V_3 ] ,
& V_48 ,
sizeof( V_74 [ V_81 ]
[ V_3 ] ) ) ;
}
}
} else if ( V_18 < V_19 ) {
V_69 [ V_18 ] . V_75 . error =
V_86 ;
V_70 [ V_18 ] . V_75 . error =
V_87 ;
for ( V_3 = 0 ; V_3 < V_88 ; V_3 ++ ) {
V_79 [ V_18 ] [ V_3 ] . V_75 . error =
V_87 ;
V_74 [ V_18 ] [ V_3 ] . V_75 . error =
V_87 ;
}
}
}
static T_2 F_10 ( struct V_14 * V_15 ,
struct V_16 * V_17
)
{
T_1 * V_89 ;
struct V_16 V_48 ;
F_3 ( & V_48 , V_15 -> V_21 , V_15 -> V_22 ,
V_87 ) ;
V_89 =
F_1 ( V_15 -> V_29 . V_30 . V_90 . V_91 . V_92 ) ;
if ( V_89 ) {
F_25 ( V_63 , V_15 ) ;
V_89 ( V_15 , & V_48 ) ;
} else {
V_17 -> error = V_23 ;
return V_17 -> error ;
}
if ( V_48 . error == 0 ) {
V_20 [ V_48 . V_29 . V_30 . V_18 ] = V_89 ;
F_5 ( V_63 ,
L_6
L_7 ) ;
F_29 ( V_48 . V_29 . V_30 . V_18 ) ;
}
memcpy ( V_17 , & V_48 , V_48 . V_93 ) ;
return V_17 -> error ;
}
static void F_6 ( T_2 V_18 , void * V_24 )
{
int V_3 , V_81 , V_94 ;
if ( ! V_24 )
return;
if ( V_18 == V_36 ) {
V_81 = 0 ;
V_94 = V_19 ;
} else {
V_81 = V_18 ;
V_94 = V_81 + 1 ;
}
for (; V_81 < V_94 ; V_81 ++ ) {
for ( V_3 = 0 ; V_3 < V_88 ; V_3 ++ ) {
if ( V_24 ==
V_78 [ V_81 ] [ V_3 ] . V_24 ) {
struct V_14 V_47 ;
struct V_16 V_48 ;
F_5 ( V_63 ,
L_8 ,
V_81 , V_3 ) ;
F_14 ( & V_47 , & V_48 ,
V_55 , V_80 ) ;
V_47 . V_18 = ( T_2 ) V_81 ;
V_47 . V_52 = ( T_2 ) V_3 ;
F_2 ( & V_47 , & V_48 ) ;
V_47 . V_22 = V_95 ;
F_2 ( & V_47 , & V_48 ) ;
V_47 . V_22 = V_96 ;
F_2 ( & V_47 , & V_48 ) ;
V_78 [ V_81 ] [ V_3 ] . V_72 = 0 ;
V_78 [ V_81 ] [ V_3 ] . V_24 =
NULL ;
}
if ( V_24 == V_71 [ V_81 ] [ V_3 ] . V_24 ) {
struct V_14 V_47 ;
struct V_16 V_48 ;
F_5 ( V_63 ,
L_9 ,
V_81 , V_3 ) ;
F_14 ( & V_47 , & V_48 ,
V_60 , V_76 ) ;
V_47 . V_18 = ( T_2 ) V_81 ;
V_47 . V_52 = ( T_2 ) V_3 ;
F_2 ( & V_47 , & V_48 ) ;
V_47 . V_22 = V_97 ;
F_2 ( & V_47 , & V_48 ) ;
V_47 . V_22 = V_98 ;
F_2 ( & V_47 , & V_48 ) ;
V_71 [ V_81 ] [ V_3 ] . V_72 = 0 ;
V_71 [ V_81 ] [ V_3 ] . V_24 = NULL ;
}
}
}
}
