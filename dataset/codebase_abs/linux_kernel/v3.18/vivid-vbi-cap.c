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
T_1 * V_40 = F_6 ( & V_39 -> V_41 , 0 ) ;
F_4 ( V_2 , & V_22 ) ;
V_39 -> V_41 . V_42 . V_43 = V_2 -> V_44 ;
if ( V_2 -> V_45 == V_46 )
V_39 -> V_41 . V_42 . V_43 /= 2 ;
F_1 ( V_2 , V_39 -> V_41 . V_42 . V_43 ) ;
memset ( V_40 , 0x10 , F_7 ( & V_39 -> V_41 , 0 ) ) ;
if ( ! F_8 ( V_2 -> V_47 ) )
F_9 ( & V_2 -> V_5 , & V_22 , V_40 ) ;
F_10 ( & V_39 -> V_41 . V_42 . V_48 ) ;
V_39 -> V_41 . V_42 . V_48 . V_49 += V_2 -> V_50 ;
}
void F_11 ( struct V_1 * V_2 , struct V_38 * V_39 )
{
struct V_51 * V_40 = F_6 ( & V_39 -> V_41 , 0 ) ;
V_39 -> V_41 . V_42 . V_43 = V_2 -> V_44 ;
if ( V_2 -> V_45 == V_46 )
V_39 -> V_41 . V_42 . V_43 /= 2 ;
F_1 ( V_2 , V_39 -> V_41 . V_42 . V_43 ) ;
memset ( V_40 , 0 , F_7 ( & V_39 -> V_41 , 0 ) ) ;
if ( ! F_8 ( V_2 -> V_47 ) ) {
unsigned V_52 ;
for ( V_52 = 0 ; V_52 < 25 ; V_52 ++ )
V_40 [ V_52 ] = V_2 -> V_5 . V_11 [ V_52 ] ;
}
F_10 ( & V_39 -> V_41 . V_42 . V_48 ) ;
V_39 -> V_41 . V_42 . V_48 . V_49 += V_2 -> V_50 ;
}
static int F_12 ( struct V_53 * V_54 , const struct V_55 * V_56 ,
unsigned * V_57 , unsigned * V_58 ,
unsigned V_59 [] , void * V_60 [] )
{
struct V_1 * V_2 = F_13 ( V_54 ) ;
bool V_6 = V_2 -> V_7 & V_8 ;
unsigned V_61 = V_54 -> type == V_62 ?
36 * sizeof( struct V_51 ) :
1440 * 2 * ( V_6 ? 12 : 18 ) ;
if ( ! F_14 ( V_2 ) )
return - V_63 ;
V_59 [ 0 ] = V_61 ;
if ( V_54 -> V_64 + * V_57 < 2 )
* V_57 = 2 - V_54 -> V_64 ;
* V_58 = 1 ;
return 0 ;
}
static int F_15 ( struct V_65 * V_41 )
{
struct V_1 * V_2 = F_13 ( V_41 -> V_53 ) ;
bool V_6 = V_2 -> V_7 & V_8 ;
unsigned V_61 = V_41 -> V_53 -> type == V_62 ?
36 * sizeof( struct V_51 ) :
1440 * 2 * ( V_6 ? 12 : 18 ) ;
F_16 ( V_2 , 1 , L_1 , V_66 ) ;
if ( V_2 -> V_67 ) {
V_2 -> V_67 = false ;
return - V_63 ;
}
if ( F_7 ( V_41 , 0 ) < V_61 ) {
F_16 ( V_2 , 1 , L_2 ,
V_66 , F_7 ( V_41 , 0 ) , V_61 ) ;
return - V_63 ;
}
F_17 ( V_41 , 0 , V_61 ) ;
return 0 ;
}
static void F_18 ( struct V_65 * V_41 )
{
struct V_1 * V_2 = F_13 ( V_41 -> V_53 ) ;
struct V_38 * V_39 = F_19 ( V_41 , struct V_38 , V_41 ) ;
F_16 ( V_2 , 1 , L_1 , V_66 ) ;
F_20 ( & V_2 -> V_68 ) ;
F_21 ( & V_39 -> V_69 , & V_2 -> V_70 ) ;
F_22 ( & V_2 -> V_68 ) ;
}
static int F_23 ( struct V_53 * V_54 , unsigned V_33 )
{
struct V_1 * V_2 = F_13 ( V_54 ) ;
int V_71 ;
F_16 ( V_2 , 1 , L_1 , V_66 ) ;
V_2 -> V_44 = 0 ;
if ( V_2 -> V_72 ) {
V_2 -> V_72 = false ;
V_71 = - V_63 ;
} else {
V_71 = F_24 ( V_2 , & V_2 -> V_73 ) ;
}
if ( V_71 ) {
struct V_38 * V_39 , * V_74 ;
F_25 (buf, tmp, &dev->vbi_cap_active, list) {
F_26 ( & V_39 -> V_69 ) ;
F_27 ( & V_39 -> V_41 , V_75 ) ;
}
}
return V_71 ;
}
static void F_28 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_13 ( V_54 ) ;
F_16 ( V_2 , 1 , L_1 , V_66 ) ;
F_29 ( V_2 , & V_2 -> V_73 ) ;
}
int F_30 ( struct V_76 * V_76 , void * V_77 ,
struct V_55 * V_78 )
{
struct V_1 * V_2 = F_31 ( V_76 ) ;
struct V_21 * V_22 = & V_78 -> V_56 . V_22 ;
if ( ! F_14 ( V_2 ) || ! V_2 -> V_79 )
return - V_63 ;
F_4 ( V_2 , V_22 ) ;
return 0 ;
}
int F_32 ( struct V_76 * V_76 , void * V_77 ,
struct V_55 * V_78 )
{
struct V_1 * V_2 = F_31 ( V_76 ) ;
int V_80 = F_30 ( V_76 , V_77 , V_78 ) ;
if ( V_80 )
return V_80 ;
if ( V_2 -> V_81 && F_33 ( & V_2 -> V_82 ) )
return - V_83 ;
V_2 -> V_81 = false ;
V_2 -> V_84 . V_85 -> type = V_86 ;
return 0 ;
}
void F_34 ( struct V_87 * V_22 , T_2 V_88 )
{
V_22 -> V_89 = sizeof( struct V_51 ) * 36 ;
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
unsigned V_52 ;
for ( V_52 = 7 ; V_52 <= 18 ; V_52 ++ )
V_22 -> V_90 [ 0 ] [ V_52 ] =
V_22 -> V_90 [ 1 ] [ V_52 ] = V_93 ;
V_22 -> V_90 [ 0 ] [ 23 ] = V_92 ;
}
}
int F_35 ( struct V_76 * V_76 , void * V_94 , struct V_55 * V_56 )
{
struct V_1 * V_2 = F_31 ( V_76 ) ;
struct V_87 * V_22 = & V_56 -> V_56 . V_95 ;
if ( ! F_14 ( V_2 ) || ! V_2 -> V_96 )
return - V_63 ;
F_34 ( V_22 , V_2 -> V_97 ) ;
return 0 ;
}
int F_36 ( struct V_76 * V_76 , void * V_94 , struct V_55 * V_56 )
{
struct V_1 * V_2 = F_31 ( V_76 ) ;
struct V_87 * V_22 = & V_56 -> V_56 . V_95 ;
bool V_6 = V_2 -> V_7 & V_8 ;
T_2 V_88 = V_22 -> V_88 ;
if ( ! F_14 ( V_2 ) || ! V_2 -> V_96 )
return - V_63 ;
V_88 &= V_6 ? V_91 :
V_92 | V_93 ;
F_34 ( V_22 , V_88 ) ;
return 0 ;
}
int F_37 ( struct V_76 * V_76 , void * V_94 , struct V_55 * V_56 )
{
struct V_1 * V_2 = F_31 ( V_76 ) ;
struct V_87 * V_22 = & V_56 -> V_56 . V_95 ;
int V_80 = F_36 ( V_76 , V_94 , V_56 ) ;
if ( V_80 )
return V_80 ;
if ( ! V_2 -> V_81 && F_33 ( & V_2 -> V_82 ) )
return - V_83 ;
V_2 -> V_97 = V_22 -> V_88 ;
V_2 -> V_81 = true ;
V_2 -> V_84 . V_85 -> type = V_62 ;
return 0 ;
}
int F_38 ( struct V_76 * V_76 , void * V_94 , struct V_98 * V_99 )
{
struct V_1 * V_2 = F_31 ( V_76 ) ;
struct V_100 * V_101 = F_39 ( V_76 ) ;
bool V_6 ;
if ( V_101 -> V_102 == V_103 ) {
V_6 = V_2 -> V_7 & V_8 ;
if ( ! F_14 ( V_2 ) || ! V_2 -> V_96 ||
V_99 -> type != V_62 )
return - V_63 ;
} else {
V_6 = V_2 -> V_104 & V_8 ;
if ( ! F_40 ( V_2 ) || ! V_2 -> V_105 ||
V_99 -> type != V_106 )
return - V_63 ;
}
V_99 -> V_88 = V_6 ? V_91 :
V_92 | V_93 ;
if ( V_6 ) {
V_99 -> V_90 [ 0 ] [ 21 ] = V_91 ;
V_99 -> V_90 [ 1 ] [ 21 ] = V_91 ;
} else {
unsigned V_52 ;
for ( V_52 = 7 ; V_52 <= 18 ; V_52 ++ )
V_99 -> V_90 [ 0 ] [ V_52 ] =
V_99 -> V_90 [ 1 ] [ V_52 ] = V_93 ;
V_99 -> V_90 [ 0 ] [ 23 ] = V_92 ;
}
return 0 ;
}
