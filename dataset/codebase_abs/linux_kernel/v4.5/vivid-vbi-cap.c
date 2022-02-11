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
unsigned V_56 [] , void * V_57 [] )
{
struct V_1 * V_2 = F_13 ( V_53 ) ;
bool V_6 = V_2 -> V_7 & V_8 ;
unsigned V_58 = V_53 -> type == V_59 ?
36 * sizeof( struct V_50 ) :
1440 * 2 * ( V_6 ? 12 : 18 ) ;
if ( ! F_14 ( V_2 ) )
return - V_60 ;
V_56 [ 0 ] = V_58 ;
if ( V_53 -> V_61 + * V_54 < 2 )
* V_54 = 2 - V_53 -> V_61 ;
* V_55 = 1 ;
return 0 ;
}
static int F_15 ( struct V_62 * V_41 )
{
struct V_1 * V_2 = F_13 ( V_41 -> V_52 ) ;
bool V_6 = V_2 -> V_7 & V_8 ;
unsigned V_58 = V_41 -> V_52 -> type == V_59 ?
36 * sizeof( struct V_50 ) :
1440 * 2 * ( V_6 ? 12 : 18 ) ;
F_16 ( V_2 , 1 , L_1 , V_63 ) ;
if ( V_2 -> V_64 ) {
V_2 -> V_64 = false ;
return - V_60 ;
}
if ( F_7 ( V_41 , 0 ) < V_58 ) {
F_16 ( V_2 , 1 , L_2 ,
V_63 , F_7 ( V_41 , 0 ) , V_58 ) ;
return - V_60 ;
}
F_17 ( V_41 , 0 , V_58 ) ;
return 0 ;
}
static void F_18 ( struct V_62 * V_41 )
{
struct V_65 * V_40 = F_19 ( V_41 ) ;
struct V_1 * V_2 = F_13 ( V_41 -> V_52 ) ;
struct V_38 * V_39 = F_20 ( V_40 , struct V_38 , V_41 ) ;
F_16 ( V_2 , 1 , L_1 , V_63 ) ;
F_21 ( & V_2 -> V_66 ) ;
F_22 ( & V_39 -> V_67 , & V_2 -> V_68 ) ;
F_23 ( & V_2 -> V_66 ) ;
}
static int F_24 ( struct V_52 * V_53 , unsigned V_33 )
{
struct V_1 * V_2 = F_13 ( V_53 ) ;
int V_69 ;
F_16 ( V_2 , 1 , L_1 , V_63 ) ;
V_2 -> V_44 = 0 ;
if ( V_2 -> V_70 ) {
V_2 -> V_70 = false ;
V_69 = - V_60 ;
} else {
V_69 = F_25 ( V_2 , & V_2 -> V_71 ) ;
}
if ( V_69 ) {
struct V_38 * V_39 , * V_72 ;
F_26 (buf, tmp, &dev->vbi_cap_active, list) {
F_27 ( & V_39 -> V_67 ) ;
F_28 ( & V_39 -> V_41 . V_42 ,
V_73 ) ;
}
}
return V_69 ;
}
static void F_29 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = F_13 ( V_53 ) ;
F_16 ( V_2 , 1 , L_1 , V_63 ) ;
F_30 ( V_2 , & V_2 -> V_71 ) ;
}
int F_31 ( struct V_74 * V_74 , void * V_75 ,
struct V_76 * V_77 )
{
struct V_1 * V_2 = F_32 ( V_74 ) ;
struct V_21 * V_22 = & V_77 -> V_78 . V_22 ;
if ( ! F_14 ( V_2 ) || ! V_2 -> V_79 )
return - V_60 ;
F_4 ( V_2 , V_22 ) ;
return 0 ;
}
int F_33 ( struct V_74 * V_74 , void * V_75 ,
struct V_76 * V_77 )
{
struct V_1 * V_2 = F_32 ( V_74 ) ;
int V_80 = F_31 ( V_74 , V_75 , V_77 ) ;
if ( V_80 )
return V_80 ;
if ( V_2 -> V_81 && F_34 ( & V_2 -> V_82 ) )
return - V_83 ;
V_2 -> V_81 = false ;
V_2 -> V_84 . V_85 -> type = V_86 ;
return 0 ;
}
void F_35 ( struct V_87 * V_22 , T_2 V_88 )
{
V_22 -> V_89 = sizeof( struct V_50 ) * 36 ;
V_22 -> V_88 = V_88 ;
memset ( V_22 -> V_90 , 0 , sizeof( V_22 -> V_90 ) ) ;
memset ( V_22 -> V_37 , 0 , sizeof( V_22 -> V_37 ) ) ;
if ( V_22 -> V_88 == 0 )
return;
if ( V_22 -> V_88 & V_91 ) {
V_22 -> V_90 [ 0 ] [ 21 ] = V_91 ;
V_22 -> V_90 [ 1 ] [ 21 ] = V_91 ;
}
if ( V_22 -> V_88 & V_92 ) {
unsigned V_51 ;
for ( V_51 = 7 ; V_51 <= 18 ; V_51 ++ )
V_22 -> V_90 [ 0 ] [ V_51 ] =
V_22 -> V_90 [ 1 ] [ V_51 ] = V_93 ;
V_22 -> V_90 [ 0 ] [ 23 ] = V_92 ;
}
}
int F_36 ( struct V_74 * V_74 , void * V_94 , struct V_76 * V_78 )
{
struct V_1 * V_2 = F_32 ( V_74 ) ;
struct V_87 * V_22 = & V_78 -> V_78 . V_95 ;
if ( ! F_14 ( V_2 ) || ! V_2 -> V_96 )
return - V_60 ;
F_35 ( V_22 , V_2 -> V_97 ) ;
return 0 ;
}
int F_37 ( struct V_74 * V_74 , void * V_94 , struct V_76 * V_78 )
{
struct V_1 * V_2 = F_32 ( V_74 ) ;
struct V_87 * V_22 = & V_78 -> V_78 . V_95 ;
bool V_6 = V_2 -> V_7 & V_8 ;
T_2 V_88 = V_22 -> V_88 ;
if ( ! F_14 ( V_2 ) || ! V_2 -> V_96 )
return - V_60 ;
V_88 &= V_6 ? V_91 :
V_92 | V_93 ;
F_35 ( V_22 , V_88 ) ;
return 0 ;
}
int F_38 ( struct V_74 * V_74 , void * V_94 , struct V_76 * V_78 )
{
struct V_1 * V_2 = F_32 ( V_74 ) ;
struct V_87 * V_22 = & V_78 -> V_78 . V_95 ;
int V_80 = F_37 ( V_74 , V_94 , V_78 ) ;
if ( V_80 )
return V_80 ;
if ( ! V_2 -> V_81 && F_34 ( & V_2 -> V_82 ) )
return - V_83 ;
V_2 -> V_97 = V_22 -> V_88 ;
V_2 -> V_81 = true ;
V_2 -> V_84 . V_85 -> type = V_59 ;
return 0 ;
}
int F_39 ( struct V_74 * V_74 , void * V_94 , struct V_98 * V_99 )
{
struct V_1 * V_2 = F_32 ( V_74 ) ;
struct V_100 * V_101 = F_40 ( V_74 ) ;
bool V_6 ;
if ( V_101 -> V_102 == V_103 ) {
V_6 = V_2 -> V_7 & V_8 ;
if ( ! F_14 ( V_2 ) || ! V_2 -> V_96 ||
V_99 -> type != V_59 )
return - V_60 ;
} else {
V_6 = V_2 -> V_104 & V_8 ;
if ( ! F_41 ( V_2 ) || ! V_2 -> V_105 ||
V_99 -> type != V_106 )
return - V_60 ;
}
V_99 -> V_88 = V_6 ? V_91 :
V_92 | V_93 ;
if ( V_6 ) {
V_99 -> V_90 [ 0 ] [ 21 ] = V_91 ;
V_99 -> V_90 [ 1 ] [ 21 ] = V_91 ;
} else {
unsigned V_51 ;
for ( V_51 = 7 ; V_51 <= 18 ; V_51 ++ )
V_99 -> V_90 [ 0 ] [ V_51 ] =
V_99 -> V_90 [ 1 ] [ V_51 ] = V_93 ;
V_99 -> V_90 [ 0 ] [ 23 ] = V_92 ;
}
return 0 ;
}
