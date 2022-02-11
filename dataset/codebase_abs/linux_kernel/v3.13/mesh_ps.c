static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 ;
struct V_1 * V_10 ;
int V_11 = sizeof( * V_9 ) ;
T_1 V_12 ;
V_10 = F_2 ( V_7 -> V_13 . V_14 + V_11 + 2 ) ;
if ( ! V_10 )
return NULL ;
F_3 ( V_10 , V_7 -> V_13 . V_14 ) ;
V_9 = (struct V_8 * ) F_4 ( V_10 , V_11 ) ;
V_12 = F_5 ( V_15 | V_16 ) ;
F_6 ( V_9 , & V_12 , V_3 -> V_3 . V_17 ,
V_5 -> V_18 . V_17 ) ;
V_9 -> V_19 = V_12 ;
V_9 -> V_20 = 0 ;
memcpy ( V_9 -> V_21 , V_3 -> V_3 . V_17 , V_22 ) ;
memset ( F_4 ( V_10 , 2 ) , 0 , 2 ) ;
F_7 ( V_5 , V_3 , V_9 ) ;
return V_10 ;
}
static void F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_10 ;
V_10 = F_1 ( V_3 ) ;
if ( ! V_10 )
return;
F_9 ( V_3 -> V_5 , L_1 ,
V_3 -> V_3 . V_17 ) ;
if ( ! F_10 ( V_3 , V_23 ) ) {
T_2 * V_24 = F_11 ( ( void * ) V_10 -> V_25 ) ;
V_24 [ 0 ] |= V_26 ;
}
F_12 ( V_3 -> V_5 , V_10 ) ;
}
T_3 F_13 ( struct V_4 * V_5 )
{
struct V_27 * V_28 = & V_5 -> V_29 . V_30 ;
struct V_2 * V_3 ;
bool V_31 = false ;
int V_32 = 0 ;
int V_33 = 0 ;
T_3 V_34 = 0 ;
enum V_35 V_36 ;
F_14 () ;
F_15 (sta, &sdata->local->sta_list, list) {
if ( V_5 != V_3 -> V_5 )
continue;
switch ( V_3 -> V_37 ) {
case V_38 :
case V_39 :
case V_40 :
V_31 = true ;
break;
case V_41 :
if ( V_3 -> V_42 == V_43 )
V_32 ++ ;
else if ( V_3 -> V_42 == V_44 )
V_33 ++ ;
break;
default:
break;
}
}
F_16 () ;
if ( V_31 ) {
F_9 ( V_5 , L_2 ) ;
V_36 = V_45 ;
} else if ( V_32 || V_33 ) {
F_9 ( V_5 , L_3 ) ;
V_36 = V_44 ;
} else {
F_9 ( V_5 , L_4 ) ;
V_36 = V_28 -> V_46 . V_47 ;
}
if ( V_28 -> V_36 != V_36 ||
! V_28 -> V_48 != ! V_32 ||
! V_28 -> V_49 != ! V_33 )
V_34 = V_50 ;
V_28 -> V_36 = V_36 ;
V_28 -> V_48 = V_32 ;
V_28 -> V_49 = V_33 ;
return V_34 ;
}
T_3 F_17 ( struct V_2 * V_3 ,
enum V_35 V_51 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
if ( V_3 -> V_42 == V_51 )
return 0 ;
F_9 ( V_5 , L_5 ,
V_51 , V_3 -> V_3 . V_17 ) ;
V_3 -> V_42 = V_51 ;
if ( V_3 -> V_37 == V_41 )
F_8 ( V_3 ) ;
return F_13 ( V_5 ) ;
}
void F_7 ( struct V_4 * V_5 ,
struct V_2 * V_3 ,
struct V_8 * V_52 )
{
enum V_35 V_51 ;
T_2 * V_24 ;
if ( F_18 ( F_19 ( V_52 -> V_21 ) &&
F_20 ( V_52 -> V_19 ) &&
! V_3 ) )
return;
if ( F_19 ( V_52 -> V_21 ) &&
F_20 ( V_52 -> V_19 ) &&
V_3 -> V_37 == V_41 )
V_51 = V_3 -> V_42 ;
else
V_51 = V_5 -> V_29 . V_30 . V_36 ;
if ( V_51 == V_45 )
V_52 -> V_19 &= F_5 ( ~ V_53 ) ;
else
V_52 -> V_19 |= F_5 ( V_53 ) ;
if ( ! F_20 ( V_52 -> V_19 ) )
return;
V_24 = F_11 ( V_52 ) ;
if ( ( F_19 ( V_52 -> V_21 ) &&
V_51 == V_44 ) ||
( F_21 ( V_52 -> V_21 ) &&
V_5 -> V_29 . V_30 . V_49 > 0 ) )
V_24 [ 1 ] |= ( V_54 >> 8 ) ;
else
V_24 [ 1 ] &= ~ ( V_54 >> 8 ) ;
}
void F_22 ( struct V_2 * V_3 )
{
enum V_35 V_51 ;
bool V_55 ;
if ( V_3 -> V_56 < V_57 )
return;
if ( V_3 -> V_37 == V_41 &&
V_3 -> V_58 != V_59 )
V_51 = V_3 -> V_58 ;
else
V_51 = V_3 -> V_36 ;
V_55 = ( V_51 != V_45 ) ;
if ( V_3 -> V_37 != V_41 ) {
F_23 ( V_3 , V_60 ) ;
F_23 ( V_3 , V_61 ) ;
} else if ( ! V_55 ) {
F_23 ( V_3 , V_60 ) ;
}
if ( F_10 ( V_3 , V_23 ) == V_55 )
return;
if ( V_55 ) {
F_24 ( V_3 , V_23 ) ;
F_25 ( & V_3 -> V_5 -> V_29 . V_30 . V_62 . V_63 ) ;
F_9 ( V_3 -> V_5 , L_6 ,
V_3 -> V_3 . V_17 ) ;
} else {
F_26 ( V_3 ) ;
}
}
static void F_27 ( struct V_2 * V_3 ,
struct V_8 * V_52 )
{
enum V_35 V_51 ;
T_2 * V_24 = F_11 ( V_52 ) ;
if ( F_28 ( V_52 -> V_19 ) ) {
if ( V_24 [ 1 ] & ( V_54 >> 8 ) )
V_51 = V_44 ;
else
V_51 = V_43 ;
} else {
V_51 = V_45 ;
}
if ( V_3 -> V_58 == V_51 )
return;
F_9 ( V_3 -> V_5 , L_7 ,
V_3 -> V_3 . V_17 , V_51 ) ;
V_3 -> V_58 = V_51 ;
F_22 ( V_3 ) ;
}
static void F_29 ( struct V_2 * V_3 ,
struct V_8 * V_52 )
{
enum V_35 V_51 ;
if ( F_28 ( V_52 -> V_19 ) )
V_51 = V_44 ;
else
V_51 = V_45 ;
if ( V_3 -> V_36 == V_51 )
return;
F_9 ( V_3 -> V_5 , L_8 ,
V_3 -> V_3 . V_17 , V_51 ) ;
V_3 -> V_36 = V_51 ;
F_22 ( V_3 ) ;
}
void F_30 ( struct V_2 * V_3 ,
struct V_8 * V_52 )
{
if ( F_19 ( V_52 -> V_21 ) &&
F_20 ( V_52 -> V_19 ) ) {
F_27 ( V_3 , V_52 ) ;
F_31 ( F_11 ( V_52 ) ,
V_3 , false , false ) ;
} else {
F_29 ( V_3 , V_52 ) ;
}
}
static void F_32 ( struct V_2 * V_3 , bool V_64 , bool V_65 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_1 * V_10 ;
struct V_8 * V_9 ;
struct V_66 * V_67 ;
T_2 * V_24 ;
V_10 = F_1 ( V_3 ) ;
if ( ! V_10 )
return;
V_9 = (struct V_8 * ) V_10 -> V_25 ;
if ( ! V_65 )
V_9 -> V_19 |=
F_5 ( V_68 ) ;
V_24 = F_11 ( V_9 ) ;
if ( V_64 )
V_24 [ 1 ] |= ( V_69 >> 8 ) ;
if ( V_65 )
V_24 [ 0 ] |= V_26 ;
V_67 = F_33 ( V_10 ) ;
V_67 -> V_70 |= V_71 |
V_72 ;
F_9 ( V_5 , L_9 ,
V_64 ? L_10 : L_11 , V_65 ? L_12 : L_11 , V_3 -> V_3 . V_17 ) ;
F_12 ( V_5 , V_10 ) ;
}
static void F_34 ( struct V_2 * V_3 ,
struct V_73 * V_74 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_1 * V_75 , * V_10 = F_35 ( V_74 ) ;
struct V_8 * V_52 = (struct V_8 * ) V_10 -> V_25 ;
struct V_66 * V_67 ;
if ( F_20 ( V_52 -> V_19 ) )
return;
V_75 = F_1 ( V_3 ) ;
if ( ! V_75 )
return;
F_9 ( V_5 , L_13 ,
V_3 -> V_3 . V_17 ) ;
V_75 -> V_76 = 1 ;
F_36 ( V_75 , V_77 ) ;
F_37 ( V_5 , V_75 ) ;
V_67 = F_33 ( V_75 ) ;
V_67 -> V_78 . V_18 = & V_5 -> V_18 ;
V_67 -> V_70 |= V_79 ;
F_38 ( V_74 , V_75 ) ;
}
static void F_39 ( struct V_2 * V_3 , int V_80 )
{
struct V_6 * V_7 = V_3 -> V_5 -> V_7 ;
int V_81 ;
struct V_73 V_74 ;
struct V_1 * V_10 ;
bool V_82 = false ;
F_40 ( & V_74 ) ;
for ( V_81 = 0 ; V_81 < V_83 ; V_81 ++ ) {
while ( V_80 != 0 ) {
V_10 = F_41 ( & V_3 -> V_84 [ V_81 ] ) ;
if ( ! V_10 ) {
V_10 = F_41 (
& V_3 -> V_85 [ V_81 ] ) ;
if ( V_10 )
V_7 -> V_86 -- ;
}
if ( ! V_10 )
break;
V_80 -- ;
F_38 ( & V_74 , V_10 ) ;
}
if ( ! F_42 ( & V_3 -> V_84 [ V_81 ] ) ||
! F_42 ( & V_3 -> V_85 [ V_81 ] ) )
V_82 = true ;
}
if ( F_42 ( & V_74 ) ) {
F_32 ( V_3 , false , true ) ;
return;
}
if ( F_10 ( V_3 , V_60 ) )
F_34 ( V_3 , & V_74 ) ;
F_9 ( V_3 -> V_5 , L_14 ,
F_43 ( & V_74 ) , V_3 -> V_3 . V_17 ) ;
F_44 (&frames, skb) {
struct V_66 * V_67 = F_33 ( V_10 ) ;
struct V_8 * V_52 = ( void * ) V_10 -> V_25 ;
V_67 -> V_70 |= V_71 ;
if ( V_82 || ! F_45 ( & V_74 , V_10 ) )
V_52 -> V_19 |=
F_5 ( V_68 ) ;
else
V_52 -> V_19 &=
F_5 ( ~ V_68 ) ;
if ( F_45 ( & V_74 , V_10 ) &&
F_20 ( V_52 -> V_19 ) ) {
T_2 * V_87 = F_11 ( V_52 ) ;
* V_87 |= V_26 ;
V_67 -> V_70 |= V_72 ;
}
}
F_46 ( V_7 , & V_74 ) ;
F_47 ( V_3 ) ;
}
void F_31 ( T_2 * V_24 , struct V_2 * V_3 ,
bool V_88 , bool V_89 )
{
T_2 V_64 = V_24 [ 1 ] & ( V_69 >> 8 ) ;
T_2 V_65 = V_24 [ 0 ] & V_26 ;
if ( V_88 ) {
if ( V_64 && V_89 )
F_24 ( V_3 , V_61 ) ;
if ( V_65 )
F_23 ( V_3 , V_60 ) ;
else if ( V_89 &&
F_10 ( V_3 , V_23 ) &&
! F_48 ( V_3 , V_60 ) )
F_39 ( V_3 , - 1 ) ;
} else {
if ( V_65 )
F_23 ( V_3 , V_61 ) ;
else if ( V_3 -> V_42 != V_45 )
F_24 ( V_3 , V_61 ) ;
if ( V_64 && ! F_48 ( V_3 , V_60 ) )
F_39 ( V_3 , - 1 ) ;
}
}
void F_49 ( struct V_2 * V_3 ,
struct V_90 * V_91 )
{
int V_81 , V_92 = 0 ;
bool V_93 = false ;
if ( V_3 -> V_37 == V_41 )
V_93 = F_50 ( V_91 -> V_94 , V_91 -> V_95 ,
F_51 ( V_3 -> V_96 ) % V_97 ) ;
if ( V_93 )
F_9 ( V_3 -> V_5 , L_15 ,
V_3 -> V_3 . V_17 ) ;
if ( F_10 ( V_3 , V_23 ) &&
( ! V_91 -> V_98 || ! F_51 ( * V_91 -> V_98 ) ) )
return;
if ( ! F_10 ( V_3 , V_60 ) )
for ( V_81 = 0 ; V_81 < V_83 ; V_81 ++ )
V_92 += F_43 ( & V_3 -> V_85 [ V_81 ] ) +
F_43 ( & V_3 -> V_84 [ V_81 ] ) ;
if ( ! V_93 && ! V_92 )
return;
if ( V_3 -> V_37 == V_41 )
F_32 ( V_3 , V_93 , ! V_92 ) ;
else
F_39 ( V_3 , 1 ) ;
}
