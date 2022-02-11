void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = true ;
V_2 -> V_3 . V_5 = false ;
}
inline int F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . V_5 ;
}
static void
F_3 ( struct V_1 * V_2 , T_1 * * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
T_1 V_17 ;
int V_18 ;
if ( ! V_6 || ! ( * V_6 ) )
return;
V_17 = F_4 ( ( T_1 ) V_8 -> V_19 ) ;
V_16 = V_2 -> V_20 . V_21 -> V_22 [ V_17 ] ;
V_12 = (struct V_11 * ) * V_6 ;
V_12 -> V_23 . type = F_5 ( V_24 ) ;
V_12 -> V_23 . V_25 = F_5 ( 2 ) ;
V_12 -> V_26 = 0 ;
V_12 -> V_27 = 0 ;
* V_6 += sizeof( * V_12 ) ;
V_14 = (struct V_13 * ) * V_6 ;
V_14 -> V_23 . type = F_5 ( V_28 ) ;
V_14 -> V_23 . V_25 = F_5 ( 2 ) ;
V_14 -> V_29 = V_8 -> V_30 ;
V_14 -> V_14 = V_8 -> V_31 ;
* V_6 += sizeof( * V_14 ) ;
V_10 = (struct V_9 * ) * V_6 ;
V_10 -> type = F_5 ( V_32 ) ;
V_10 -> V_25 = F_5 ( 2 * V_16 -> V_33 + 2 ) ;
* V_6 += sizeof( * V_10 ) ;
* ( * V_6 ) ++ = V_34 ;
* ( * V_6 ) ++ = 2 * V_16 -> V_33 ;
for ( V_18 = 0 ; V_18 < V_16 -> V_33 ; V_18 ++ ) {
* ( * V_6 ) ++ = F_6 (
V_16 -> V_35 [ V_18 ] . V_36 ) ;
* ( * V_6 ) ++ = 1 ;
}
}
int F_7 ( struct V_1 * V_2 , bool V_37 )
{
T_2 V_38 = V_37 ;
if ( ( F_8 ( V_2 ) == V_39 ) && V_38 )
V_38 |= V_40 ;
return F_9 ( V_2 , V_41 ,
V_42 , V_43 , & V_38 , true ) ;
}
void F_10 ( struct V_1 * V_2 , T_1 * * V_6 ,
struct V_7 * V_8 )
{
if ( V_8 -> V_44 ) {
F_7 ( V_2 , true ) ;
V_2 -> V_3 . V_5 = true ;
V_8 -> V_45 |= V_46 ;
F_3 ( V_2 , V_6 , V_8 ) ;
} else {
F_7 ( V_2 , false ) ;
V_2 -> V_3 . V_5 = false ;
V_8 -> V_45 &= ~ V_46 ;
}
}
void F_11 ( struct V_47 * V_48 )
{
struct V_49 V_50 ;
struct V_51 * V_51 = F_12 ( V_48 ) ;
struct V_1 * V_2 =
F_13 ( V_51 , struct V_1 ,
V_52 ) ;
if ( F_14 ( ! V_2 ) )
return;
V_50 = V_2 -> V_53 ;
if ( V_2 -> V_20 . V_54 ) {
F_15 ( V_2 -> V_55 , V_56 ,
L_1 ) ;
F_16 ( V_2 -> V_57 , & V_50 ,
V_58 ,
V_59 ) ;
}
}
int F_17 ( struct V_1 * V_2 ,
struct V_60 * V_61 ,
void * V_62 )
{
struct V_63 * V_64 = & V_61 -> V_65 . V_66 ;
struct V_67 * V_68 = ( void * ) V_62 ;
V_61 -> V_69 = F_5 ( V_70 ) ;
V_61 -> V_71 = F_5 ( V_72 ) ;
F_18 ( & V_61 -> V_71 , sizeof( struct V_63 ) ) ;
V_64 -> V_73 . V_74 = F_5 ( V_75 ) ;
V_64 -> V_73 . V_76 = V_68 -> V_50 -> V_29 -> V_77 ;
V_64 -> V_73 . V_78 = V_68 -> V_50 -> V_79 ;
V_64 -> V_80 = F_19 ( V_68 -> V_81 ) ;
if ( V_68 -> V_81 )
F_15 ( V_2 -> V_55 , V_56 ,
L_2 ,
V_68 -> V_50 -> V_29 -> V_77 ) ;
else
F_15 ( V_2 -> V_55 , V_56 , L_3 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_67 V_68 ;
memset ( & V_68 , 0 , sizeof( struct V_67 ) ) ;
V_68 . V_50 = V_50 ;
V_68 . V_81 = 0 ;
return F_9 ( V_2 , V_70 ,
V_42 , 0 , & V_68 , true ) ;
}
void F_21 ( struct V_1 * V_2 )
{
if ( V_2 -> V_20 . V_54 ) {
if ( F_20 ( V_2 , & V_2 -> V_53 ) )
F_15 ( V_2 -> V_55 , ERROR ,
L_4 ) ;
F_15 ( V_2 -> V_55 , V_56 ,
L_5 ) ;
F_22 ( & V_2 -> V_52 ) ;
F_16 ( V_2 -> V_57 , & V_2 -> V_53 ,
V_82 , V_59 ) ;
}
}
int F_23 ( struct V_1 * V_2 ,
struct V_83 * V_84 )
{
struct V_85 * V_86 ;
struct V_87 * V_88 ;
T_1 * V_89 ;
T_3 V_90 , V_91 ;
V_86 = ( void * ) ( V_84 -> V_92 + sizeof( T_2 ) ) ;
V_90 = V_84 -> V_25 - ( sizeof( struct V_85 ) +
sizeof( T_2 ) ) ;
if ( F_24 ( V_86 -> V_93 ) != V_94 ) {
F_15 ( V_2 -> V_55 , ERROR ,
L_6 ) ;
return - 1 ;
}
V_89 = ( void * ) & V_86 -> V_95 ;
while ( V_90 >= sizeof( struct V_9 ) ) {
V_88 = ( void * ) & V_86 -> V_95 ;
V_91 = F_25 ( V_88 -> V_23 . V_25 ) ;
switch ( F_25 ( V_88 -> V_23 . type ) ) {
case V_96 :
if ( V_88 -> V_97 . V_98 ) {
F_15 ( V_2 -> V_55 , V_56 ,
L_7 ,
V_2 -> V_53 . V_29 -> V_77 ) ;
F_22 ( & V_2 -> V_52 ) ;
F_16 ( V_2 -> V_57 ,
& V_2 -> V_53 ,
V_99 ,
V_59 ) ;
}
break;
default:
break;
}
V_89 += ( V_91 + sizeof( V_88 -> V_23 ) ) ;
V_90 -= ( V_91 + sizeof( V_88 -> V_23 ) ) ;
}
return 0 ;
}
int F_26 ( struct V_1 * V_2 ,
struct V_83 * V_84 )
{
struct V_100 * V_101 ;
V_101 = ( void * ) ( V_84 -> V_92 + sizeof( T_2 ) ) ;
if ( F_24 ( V_101 -> V_102 ) ) {
F_15 ( V_2 -> V_55 , V_56 ,
L_8 ) ;
if ( F_20 ( V_2 , & V_2 -> V_53 ) )
F_15 ( V_2 -> V_55 , ERROR ,
L_9 ) ;
F_27 ( V_2 -> V_55 -> V_21 , & V_2 -> V_53 ,
V_59 ) ;
F_15 ( V_2 -> V_55 , V_56 , L_10 ,
V_101 -> V_103 ) ;
F_15 ( V_2 -> V_55 , V_56 , L_11 ,
V_101 -> V_104 ) ;
} else {
F_15 ( V_2 -> V_55 , V_56 ,
L_12 ) ;
}
return 0 ;
}
void F_28 ( struct V_47 * V_48 )
{
struct V_105 * V_106 ;
struct V_51 * V_51 = F_12 ( V_48 ) ;
struct V_1 * V_2 =
F_13 ( V_51 , struct V_1 ,
V_107 ) ;
if ( F_14 ( ! V_2 ) )
return;
V_106 = & V_2 -> V_106 ;
if ( ! V_106 -> V_108 ) {
F_15 ( V_2 -> V_55 , ERROR ,
L_13 ) ;
return;
}
F_29 ( V_2 , V_106 , V_2 -> V_53 ) ;
if ( F_30 ( V_2 , V_106 ) ) {
F_15 ( V_2 -> V_55 , ERROR ,
L_14 ) ;
return;
}
F_15 ( V_2 -> V_55 , V_56 ,
L_15 ) ;
F_31 ( V_2 -> V_57 , & V_2 -> V_53 ) ;
}
