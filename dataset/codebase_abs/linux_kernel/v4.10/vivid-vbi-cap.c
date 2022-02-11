static void F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
bool V_6 = V_2 -> V_7 & V_8 ;
F_2 ( V_5 , V_6 , V_3 ) ;
if ( ! V_6 ) {
if ( V_2 -> V_9 ) {
if ( V_2 -> V_10 ) {
V_5 -> V_11 [ 12 ] . V_11 [ 0 ] = V_2 -> V_12 [ 0 ] ;
V_5 -> V_11 [ 12 ] . V_11 [ 1 ] = V_2 -> V_12 [ 1 ] ;
} else {
V_5 -> V_11 [ 12 ] . V_13 = 0 ;
}
} else {
switch ( F_3 ( & V_2 -> V_14 ) ) {
case V_15 :
V_5 -> V_11 [ 12 ] . V_11 [ 0 ] = 0x01 ;
break;
case V_16 :
V_5 -> V_11 [ 12 ] . V_11 [ 0 ] = 0x0b ;
break;
case V_17 :
V_5 -> V_11 [ 12 ] . V_11 [ 0 ] = 0x07 ;
break;
case V_18 :
default:
V_5 -> V_11 [ 12 ] . V_11 [ 0 ] = 0x08 ;
break;
}
}
} else if ( V_2 -> V_9 && V_6 ) {
if ( V_2 -> V_19 [ 0 ] ) {
V_5 -> V_11 [ 0 ] . V_11 [ 0 ] = V_2 -> V_20 [ 0 ] [ 0 ] ;
V_5 -> V_11 [ 0 ] . V_11 [ 1 ] = V_2 -> V_20 [ 0 ] [ 1 ] ;
} else {
V_5 -> V_11 [ 0 ] . V_13 = 0 ;
}
if ( V_2 -> V_19 [ 1 ] ) {
V_5 -> V_11 [ 1 ] . V_11 [ 0 ] = V_2 -> V_20 [ 1 ] [ 0 ] ;
V_5 -> V_11 [ 1 ] . V_11 [ 1 ] = V_2 -> V_20 [ 1 ] [ 1 ] ;
} else {
V_5 -> V_11 [ 1 ] . V_13 = 0 ;
}
}
}
static void F_4 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
bool V_6 = V_2 -> V_7 & V_8 ;
V_22 -> V_23 = 27000000 ;
V_22 -> V_24 = 24 ;
V_22 -> V_25 = 1440 ;
V_22 -> V_26 = V_27 ;
V_22 -> V_28 [ 0 ] = V_6 ? V_29 + 9 : V_30 + 5 ;
V_22 -> V_28 [ 1 ] = V_6 ? V_31 + 9 : V_32 + 5 ;
V_22 -> V_33 [ 0 ] = V_22 -> V_33 [ 1 ] = V_6 ? 12 : 18 ;
V_22 -> V_34 = V_2 -> V_35 ? V_36 : 0 ;
V_22 -> V_37 [ 0 ] = 0 ;
V_22 -> V_37 [ 1 ] = 0 ;
}
void F_5 ( struct V_1 * V_2 , struct V_38 * V_39 )
{
struct V_21 V_22 ;
T_1 * V_40 = F_6 ( & V_39 -> V_41 . V_42 , 0 ) ;
F_4 ( V_2 , & V_22 ) ;
V_39 -> V_41 . V_43 = V_2 -> V_44 ;
if ( V_2 -> V_45 == V_46 )
V_39 -> V_41 . V_43 /= 2 ;
F_1 ( V_2 , V_39 -> V_41 . V_43 ) ;
memset ( V_40 , 0x10 , F_7 ( & V_39 -> V_41 . V_42 , 0 ) ) ;
if ( ! F_8 ( V_2 -> V_47 ) )
F_9 ( & V_2 -> V_5 , & V_22 , V_40 ) ;
V_39 -> V_41 . V_42 . V_48 = F_10 () + V_2 -> V_49 ;
}
void F_11 ( struct V_1 * V_2 ,
struct V_38 * V_39 )
{
struct V_50 * V_40 =
F_6 ( & V_39 -> V_41 . V_42 , 0 ) ;
V_39 -> V_41 . V_43 = V_2 -> V_44 ;
if ( V_2 -> V_45 == V_46 )
V_39 -> V_41 . V_43 /= 2 ;
F_1 ( V_2 , V_39 -> V_41 . V_43 ) ;
memset ( V_40 , 0 , F_7 ( & V_39 -> V_41 . V_42 , 0 ) ) ;
if ( ! F_8 ( V_2 -> V_47 ) ) {
unsigned V_51 ;
for ( V_51 = 0 ; V_51 < 25 ; V_51 ++ )
V_40 [ V_51 ] = V_2 -> V_5 . V_11 [ V_51 ] ;
}
V_39 -> V_41 . V_42 . V_48 = F_10 () + V_2 -> V_49 ;
}
static int F_12 ( struct V_52 * V_53 ,
unsigned * V_54 , unsigned * V_55 ,
unsigned V_56 [] , struct V_57 * V_58 [] )
{
struct V_1 * V_2 = F_13 ( V_53 ) ;
bool V_6 = V_2 -> V_7 & V_8 ;
unsigned V_59 = V_53 -> type == V_60 ?
36 * sizeof( struct V_50 ) :
1440 * 2 * ( V_6 ? 12 : 18 ) ;
if ( ! F_14 ( V_2 ) )
return - V_61 ;
V_56 [ 0 ] = V_59 ;
if ( V_53 -> V_62 + * V_54 < 2 )
* V_54 = 2 - V_53 -> V_62 ;
* V_55 = 1 ;
return 0 ;
}
static int F_15 ( struct V_63 * V_41 )
{
struct V_1 * V_2 = F_13 ( V_41 -> V_52 ) ;
bool V_6 = V_2 -> V_7 & V_8 ;
unsigned V_59 = V_41 -> V_52 -> type == V_60 ?
36 * sizeof( struct V_50 ) :
1440 * 2 * ( V_6 ? 12 : 18 ) ;
F_16 ( V_2 , 1 , L_1 , V_64 ) ;
if ( V_2 -> V_65 ) {
V_2 -> V_65 = false ;
return - V_61 ;
}
if ( F_7 ( V_41 , 0 ) < V_59 ) {
F_16 ( V_2 , 1 , L_2 ,
V_64 , F_7 ( V_41 , 0 ) , V_59 ) ;
return - V_61 ;
}
F_17 ( V_41 , 0 , V_59 ) ;
return 0 ;
}
static void F_18 ( struct V_63 * V_41 )
{
struct V_66 * V_40 = F_19 ( V_41 ) ;
struct V_1 * V_2 = F_13 ( V_41 -> V_52 ) ;
struct V_38 * V_39 = F_20 ( V_40 , struct V_38 , V_41 ) ;
F_16 ( V_2 , 1 , L_1 , V_64 ) ;
F_21 ( & V_2 -> V_67 ) ;
F_22 ( & V_39 -> V_68 , & V_2 -> V_69 ) ;
F_23 ( & V_2 -> V_67 ) ;
}
static int F_24 ( struct V_52 * V_53 , unsigned V_33 )
{
struct V_1 * V_2 = F_13 ( V_53 ) ;
int V_70 ;
F_16 ( V_2 , 1 , L_1 , V_64 ) ;
V_2 -> V_44 = 0 ;
if ( V_2 -> V_71 ) {
V_2 -> V_71 = false ;
V_70 = - V_61 ;
} else {
V_70 = F_25 ( V_2 , & V_2 -> V_72 ) ;
}
if ( V_70 ) {
struct V_38 * V_39 , * V_73 ;
F_26 (buf, tmp, &dev->vbi_cap_active, list) {
F_27 ( & V_39 -> V_68 ) ;
F_28 ( & V_39 -> V_41 . V_42 ,
V_74 ) ;
}
}
return V_70 ;
}
static void F_29 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = F_13 ( V_53 ) ;
F_16 ( V_2 , 1 , L_1 , V_64 ) ;
F_30 ( V_2 , & V_2 -> V_72 ) ;
}
int F_31 ( struct V_75 * V_75 , void * V_76 ,
struct V_77 * V_78 )
{
struct V_1 * V_2 = F_32 ( V_75 ) ;
struct V_21 * V_22 = & V_78 -> V_79 . V_22 ;
if ( ! F_14 ( V_2 ) || ! V_2 -> V_80 )
return - V_61 ;
F_4 ( V_2 , V_22 ) ;
return 0 ;
}
int F_33 ( struct V_75 * V_75 , void * V_76 ,
struct V_77 * V_78 )
{
struct V_1 * V_2 = F_32 ( V_75 ) ;
int V_81 = F_31 ( V_75 , V_76 , V_78 ) ;
if ( V_81 )
return V_81 ;
if ( V_2 -> V_82 && F_34 ( & V_2 -> V_83 ) )
return - V_84 ;
V_2 -> V_82 = false ;
V_2 -> V_85 . V_86 -> type = V_87 ;
return 0 ;
}
void F_35 ( struct V_88 * V_22 , T_2 V_89 )
{
V_22 -> V_90 = sizeof( struct V_50 ) * 36 ;
V_22 -> V_89 = V_89 ;
memset ( V_22 -> V_91 , 0 , sizeof( V_22 -> V_91 ) ) ;
memset ( V_22 -> V_37 , 0 , sizeof( V_22 -> V_37 ) ) ;
if ( V_22 -> V_89 == 0 )
return;
if ( V_22 -> V_89 & V_92 ) {
V_22 -> V_91 [ 0 ] [ 21 ] = V_92 ;
V_22 -> V_91 [ 1 ] [ 21 ] = V_92 ;
}
if ( V_22 -> V_89 & V_93 ) {
unsigned V_51 ;
for ( V_51 = 7 ; V_51 <= 18 ; V_51 ++ )
V_22 -> V_91 [ 0 ] [ V_51 ] =
V_22 -> V_91 [ 1 ] [ V_51 ] = V_94 ;
V_22 -> V_91 [ 0 ] [ 23 ] = V_93 ;
}
}
int F_36 ( struct V_75 * V_75 , void * V_95 , struct V_77 * V_79 )
{
struct V_1 * V_2 = F_32 ( V_75 ) ;
struct V_88 * V_22 = & V_79 -> V_79 . V_96 ;
if ( ! F_14 ( V_2 ) || ! V_2 -> V_97 )
return - V_61 ;
F_35 ( V_22 , V_2 -> V_98 ) ;
return 0 ;
}
int F_37 ( struct V_75 * V_75 , void * V_95 , struct V_77 * V_79 )
{
struct V_1 * V_2 = F_32 ( V_75 ) ;
struct V_88 * V_22 = & V_79 -> V_79 . V_96 ;
bool V_6 = V_2 -> V_7 & V_8 ;
T_2 V_89 = V_22 -> V_89 ;
if ( ! F_14 ( V_2 ) || ! V_2 -> V_97 )
return - V_61 ;
V_89 &= V_6 ? V_92 :
V_93 | V_94 ;
F_35 ( V_22 , V_89 ) ;
return 0 ;
}
int F_38 ( struct V_75 * V_75 , void * V_95 , struct V_77 * V_79 )
{
struct V_1 * V_2 = F_32 ( V_75 ) ;
struct V_88 * V_22 = & V_79 -> V_79 . V_96 ;
int V_81 = F_37 ( V_75 , V_95 , V_79 ) ;
if ( V_81 )
return V_81 ;
if ( ! V_2 -> V_82 && F_34 ( & V_2 -> V_83 ) )
return - V_84 ;
V_2 -> V_98 = V_22 -> V_89 ;
V_2 -> V_82 = true ;
V_2 -> V_85 . V_86 -> type = V_60 ;
return 0 ;
}
int F_39 ( struct V_75 * V_75 , void * V_95 , struct V_99 * V_100 )
{
struct V_1 * V_2 = F_32 ( V_75 ) ;
struct V_101 * V_102 = F_40 ( V_75 ) ;
bool V_6 ;
if ( V_102 -> V_103 == V_104 ) {
V_6 = V_2 -> V_7 & V_8 ;
if ( ! F_14 ( V_2 ) || ! V_2 -> V_97 ||
V_100 -> type != V_60 )
return - V_61 ;
} else {
V_6 = V_2 -> V_105 & V_8 ;
if ( ! F_41 ( V_2 ) || ! V_2 -> V_106 ||
V_100 -> type != V_107 )
return - V_61 ;
}
V_100 -> V_89 = V_6 ? V_92 :
V_93 | V_94 ;
if ( V_6 ) {
V_100 -> V_91 [ 0 ] [ 21 ] = V_92 ;
V_100 -> V_91 [ 1 ] [ 21 ] = V_92 ;
} else {
unsigned V_51 ;
for ( V_51 = 7 ; V_51 <= 18 ; V_51 ++ )
V_100 -> V_91 [ 0 ] [ V_51 ] =
V_100 -> V_91 [ 1 ] [ V_51 ] = V_94 ;
V_100 -> V_91 [ 0 ] [ 23 ] = V_93 ;
}
return 0 ;
}
