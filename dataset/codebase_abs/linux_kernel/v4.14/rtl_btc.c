void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 ) {
F_3 ( V_4 , L_1 ) ;
return;
}
F_4 ( V_6 , V_4 ) ;
}
void F_5 ( struct V_1 * V_2 , T_1 * V_7 , T_1 V_8 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_9 ;
if ( ! V_6 )
return;
V_9 = sizeof( V_6 -> V_10 ) ;
if ( V_9 > V_8 )
V_9 = V_8 ;
memcpy ( V_6 -> V_10 , V_7 , V_9 ) ;
}
T_1 F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 )
return 0 ;
return V_6 -> V_11 . V_12 ;
}
T_1 F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 )
return 0 ;
return V_6 -> V_11 . V_13 ;
}
bool F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 )
return false ;
return V_6 -> V_11 . V_14 ;
}
bool F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 )
return false ;
return V_6 -> V_11 . V_15 ;
}
void F_10 ( struct V_1 * V_2 , T_1 * V_16 ,
T_1 * V_17 , T_1 * V_18 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 ) {
* V_16 = false ;
* V_17 = false ;
return;
}
if ( V_16 )
* V_16 = V_6 -> V_11 . V_19 ;
if ( V_17 )
* V_17 = V_6 -> V_11 . V_20 ;
if ( V_18 )
* V_18 = V_6 -> V_11 . V_21 ;
}
static void F_11 ( struct V_1 * V_2 , bool V_22 )
{
if ( V_22 )
V_2 -> V_6 . V_23 =
F_12 ( sizeof( struct V_24 ) , V_25 ) ;
else
V_2 -> V_6 . V_26 =
F_12 ( sizeof( struct V_5 ) , V_25 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_14 ( V_2 -> V_6 . V_26 ) ;
V_2 -> V_6 . V_26 = NULL ;
F_14 ( V_2 -> V_6 . V_23 ) ;
V_2 -> V_6 . V_23 = NULL ;
}
void F_15 ( struct V_1 * V_2 )
{
F_11 ( V_2 , false ) ;
F_16 ( V_2 ) ;
F_17 ( V_2 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
F_11 ( V_2 , true ) ;
F_19 ( V_2 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
F_13 ( V_2 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
}
void F_22 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 )
return;
F_23 ( V_6 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_27 ;
V_27 = F_25 ( V_2 ) ;
F_26 ( V_2 , V_28 , V_29 ,
L_2 , V_30 , V_27 ) ;
if ( ! V_6 )
return;
F_27 ( V_6 , ! V_27 ) ;
F_28 ( V_6 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_24 * V_31 = F_30 ( V_2 ) ;
if ( ! V_31 )
return;
F_31 ( V_31 ) ;
}
void F_32 ( struct V_1 * V_2 , T_1 type )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 )
return;
F_33 ( V_6 , type ) ;
if ( type == V_32 ) {
F_34 ( V_6 , 1 ) ;
F_34 ( V_6 , 0 ) ;
}
}
void F_35 ( struct V_1 * V_2 , T_1 type )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 )
return;
F_36 ( V_6 , type ) ;
}
void F_37 ( struct V_1 * V_2 , T_1 V_33 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 )
return;
F_34 ( V_6 , V_33 ) ;
}
void F_38 ( struct V_1 * V_2 , T_1 V_33 )
{
struct V_34 * V_35 = V_34 ( V_2 ) ;
struct V_24 * V_31 = F_30 ( V_2 ) ;
T_1 V_36 = ( V_35 -> V_37 == V_38 ) ;
if ( ! V_31 )
return;
F_39 ( V_31 , V_36 ) ;
}
void F_40 ( struct V_1 * V_2 , T_1 V_39 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 )
return;
F_41 ( V_6 , V_39 ) ;
}
void F_42 ( struct V_1 * V_2 ,
enum V_40 V_41 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 )
return;
F_43 ( V_6 , V_41 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 )
return;
F_45 ( V_6 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 )
return;
F_47 ( V_6 ) ;
}
void F_48 ( struct V_1 * V_2 , T_1 * V_42 , T_1 V_43 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 )
return;
F_49 ( V_6 , V_42 , V_43 ) ;
}
void F_50 ( struct V_1 * V_2 , T_1 * V_42 , T_1 V_43 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_44 , V_45 , V_8 ;
T_2 V_46 ;
T_1 V_47 ;
T_1 * V_48 ;
if ( ! V_6 )
return;
if ( ( V_43 < 4 ) || ( ! V_42 ) )
return;
V_44 = V_42 [ 0 ] ;
if ( V_44 != 1 )
return;
V_8 = V_42 [ 1 ] >> 4 ;
V_45 = V_42 [ 2 ] >> 4 ;
V_48 = & V_42 [ 3 ] ;
switch ( V_45 ) {
case V_49 :
V_46 = V_42 [ 3 ] | ( V_42 [ 4 ] << 8 ) ;
V_47 = V_42 [ 5 ] ;
V_6 -> V_11 . V_46 = V_46 ;
V_6 -> V_11 . V_47 = V_47 ;
break;
case V_50 :
V_6 -> V_11 . V_51 = F_51 ( * ( V_52 * ) V_48 ) ;
break;
case V_53 :
V_6 -> V_11 . V_54 = F_51 ( * ( V_52 * ) V_48 ) ;
break;
case V_55 :
V_6 -> V_11 . V_56 = F_52 ( * ( V_57 * ) V_48 ) ;
break;
case V_58 :
V_6 -> V_11 . V_59 = V_42 [ 3 ] |
( V_42 [ 4 ] << 8 ) ;
break;
case V_60 :
V_6 -> V_11 . V_61 = V_42 [ 3 ] |
( V_42 [ 4 ] << 8 ) ;
break;
case V_62 :
V_6 -> V_11 . V_63 = V_42 [ 3 ] ;
break;
case V_64 :
V_6 -> V_11 . V_65 = V_42 [ 3 ] |
( V_42 [ 4 ] << 8 ) |
( V_42 [ 5 ] << 16 ) |
( V_42 [ 6 ] << 24 ) ;
break;
case V_66 :
V_6 -> V_11 . V_67 = V_42 [ 3 ] ;
break;
}
F_26 ( V_2 , V_68 , V_69 ,
L_3 , V_45 ) ;
F_53 ( & V_6 -> V_70 ) ;
}
bool F_54 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 )
return false ;
return V_6 -> V_11 . V_71 ;
}
bool F_55 ( struct V_1 * V_2 )
{
bool V_72 = false ;
T_3 V_73 ;
T_3 V_74 = 0x5ea42b , V_75 = 0x5ea42b ;
T_3 V_76 ;
T_3 V_77 = 0x504 ;
V_73 = F_56 ( V_2 , V_77 ) ;
if ( F_57 ( V_2 ) ) {
if ( V_73 != V_74 ) {
V_76 = V_74 ;
V_72 = true ;
}
} else {
if ( V_73 != V_75 ) {
V_76 = V_75 ;
V_72 = true ;
}
}
if ( V_72 )
F_58 ( V_2 , V_77 , V_76 ) ;
return true ;
}
bool F_59 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 )
return true ;
if ( V_6 -> V_11 . V_78 )
return true ;
else
return false ;
}
void F_60 ( struct V_1 * V_2 , T_1 V_79 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 )
return;
return F_61 ( V_6 , V_79 ) ;
}
void F_62 ( struct V_1 * V_2 , T_1 V_80 ,
bool V_81 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 type = V_82 ;
if ( ! V_6 )
return;
switch ( V_80 ) {
case V_83 :
if ( V_81 )
type = V_84 ;
else
type = V_85 ;
break;
case V_38 :
type = V_86 ;
break;
}
if ( type != V_82 )
F_63 ( V_6 , type ) ;
}
void F_64 ( struct V_1 * V_2 , T_1 V_80 ,
bool V_81 )
{
struct V_24 * V_31 = F_30 ( V_2 ) ;
T_1 V_36 = ( V_80 == V_38 ) ;
if ( ! V_31 )
return;
F_65 ( V_31 , V_36 ) ;
}
struct V_87 * F_66 ( void )
{
return & V_88 ;
}
enum V_40 F_67 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = V_1 ( V_90 ) ;
struct V_91 * V_92 = V_91 ( V_1 ( V_90 ) ) ;
enum V_40 V_93 = V_94 ;
T_1 V_95 = ( V_92 -> V_96 == V_97 ) ? 1 : 0 ;
if ( V_95 || V_2 -> V_98 . V_99 >= V_100 )
V_93 = V_101 ;
return V_93 ;
}
T_1 F_25 ( struct V_1 * V_2 )
{
return V_2 -> V_6 . V_102 . V_6 ;
}
