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
V_9 -> V_21 = 0 ;
memcpy ( V_9 -> V_22 , V_3 -> V_3 . V_17 , V_23 ) ;
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
if ( ! F_10 ( V_3 , V_24 ) ) {
T_2 * V_25 = F_11 ( ( void * ) V_10 -> V_26 ) ;
V_25 [ 0 ] |= V_27 ;
}
F_12 ( V_3 -> V_5 , V_10 ) ;
}
T_3 F_13 ( struct V_4 * V_5 )
{
struct V_28 * V_29 = & V_5 -> V_30 . V_31 ;
struct V_2 * V_3 ;
bool V_32 = false ;
int V_33 = 0 ;
int V_34 = 0 ;
T_3 V_35 = 0 ;
enum V_36 V_37 ;
F_14 () ;
F_15 (sta, &sdata->local->sta_list, list) {
if ( V_5 != V_3 -> V_5 )
continue;
switch ( V_3 -> V_31 -> V_38 ) {
case V_39 :
case V_40 :
case V_41 :
V_32 = true ;
break;
case V_42 :
if ( V_3 -> V_31 -> V_43 == V_44 )
V_33 ++ ;
else if ( V_3 -> V_31 -> V_43 == V_45 )
V_34 ++ ;
break;
default:
break;
}
}
F_16 () ;
if ( V_32 ) {
F_9 ( V_5 , L_2 ) ;
V_37 = V_46 ;
} else if ( V_33 || V_34 ) {
F_9 ( V_5 , L_3 ) ;
V_37 = V_45 ;
} else {
F_9 ( V_5 , L_4 ) ;
V_37 = V_29 -> V_47 . V_48 ;
}
if ( V_29 -> V_37 != V_37 ||
! V_29 -> V_49 != ! V_33 ||
! V_29 -> V_50 != ! V_34 )
V_35 = V_51 ;
V_29 -> V_37 = V_37 ;
V_29 -> V_49 = V_33 ;
V_29 -> V_50 = V_34 ;
return V_35 ;
}
T_3 F_17 ( struct V_2 * V_3 ,
enum V_36 V_52 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
if ( V_3 -> V_31 -> V_43 == V_52 )
return 0 ;
F_9 ( V_5 , L_5 ,
V_52 , V_3 -> V_3 . V_17 ) ;
V_3 -> V_31 -> V_43 = V_52 ;
if ( V_3 -> V_31 -> V_38 == V_42 )
F_8 ( V_3 ) ;
return F_13 ( V_5 ) ;
}
void F_7 ( struct V_4 * V_5 ,
struct V_2 * V_3 ,
struct V_8 * V_53 )
{
enum V_36 V_52 ;
T_2 * V_25 ;
if ( F_18 ( F_19 ( V_53 -> V_22 ) &&
F_20 ( V_53 -> V_19 ) &&
! V_3 ) )
return;
if ( F_19 ( V_53 -> V_22 ) &&
F_20 ( V_53 -> V_19 ) &&
V_3 -> V_31 -> V_38 == V_42 )
V_52 = V_3 -> V_31 -> V_43 ;
else
V_52 = V_5 -> V_30 . V_31 . V_37 ;
if ( V_52 == V_46 )
V_53 -> V_19 &= F_5 ( ~ V_54 ) ;
else
V_53 -> V_19 |= F_5 ( V_54 ) ;
if ( ! F_20 ( V_53 -> V_19 ) )
return;
V_25 = F_11 ( V_53 ) ;
if ( ( F_19 ( V_53 -> V_22 ) &&
V_52 == V_45 ) ||
( F_21 ( V_53 -> V_22 ) &&
V_5 -> V_30 . V_31 . V_50 > 0 ) )
V_25 [ 1 ] |= ( V_55 >> 8 ) ;
else
V_25 [ 1 ] &= ~ ( V_55 >> 8 ) ;
}
void F_22 ( struct V_2 * V_3 )
{
enum V_36 V_52 ;
bool V_56 ;
if ( V_3 -> V_57 < V_58 )
return;
if ( V_3 -> V_31 -> V_38 == V_42 &&
V_3 -> V_31 -> V_59 != V_60 )
V_52 = V_3 -> V_31 -> V_59 ;
else
V_52 = V_3 -> V_31 -> V_37 ;
V_56 = ( V_52 != V_46 ) ;
if ( V_3 -> V_31 -> V_38 != V_42 ) {
F_23 ( V_3 , V_61 ) ;
F_23 ( V_3 , V_62 ) ;
} else if ( ! V_56 ) {
F_23 ( V_3 , V_61 ) ;
}
if ( F_10 ( V_3 , V_24 ) == V_56 )
return;
if ( V_56 ) {
F_24 ( V_3 , V_24 ) ;
F_25 ( & V_3 -> V_5 -> V_30 . V_31 . V_63 . V_64 ) ;
F_9 ( V_3 -> V_5 , L_6 ,
V_3 -> V_3 . V_17 ) ;
} else {
F_26 ( V_3 ) ;
}
}
static void F_27 ( struct V_2 * V_3 ,
struct V_8 * V_53 )
{
enum V_36 V_52 ;
T_2 * V_25 = F_11 ( V_53 ) ;
if ( F_28 ( V_53 -> V_19 ) ) {
if ( V_25 [ 1 ] & ( V_55 >> 8 ) )
V_52 = V_45 ;
else
V_52 = V_44 ;
} else {
V_52 = V_46 ;
}
if ( V_3 -> V_31 -> V_59 == V_52 )
return;
F_9 ( V_3 -> V_5 , L_7 ,
V_3 -> V_3 . V_17 , V_52 ) ;
V_3 -> V_31 -> V_59 = V_52 ;
F_22 ( V_3 ) ;
}
static void F_29 ( struct V_2 * V_3 ,
struct V_8 * V_53 )
{
enum V_36 V_52 ;
if ( F_28 ( V_53 -> V_19 ) )
V_52 = V_45 ;
else
V_52 = V_46 ;
if ( V_3 -> V_31 -> V_37 == V_52 )
return;
F_9 ( V_3 -> V_5 , L_8 ,
V_3 -> V_3 . V_17 , V_52 ) ;
V_3 -> V_31 -> V_37 = V_52 ;
F_22 ( V_3 ) ;
}
void F_30 ( struct V_2 * V_3 ,
struct V_8 * V_53 )
{
if ( F_19 ( V_53 -> V_22 ) &&
F_20 ( V_53 -> V_19 ) ) {
F_27 ( V_3 , V_53 ) ;
F_31 ( F_11 ( V_53 ) ,
V_3 , false , false ) ;
} else {
F_29 ( V_3 , V_53 ) ;
}
}
static void F_32 ( struct V_2 * V_3 , bool V_65 , bool V_66 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_1 * V_10 ;
struct V_8 * V_9 ;
struct V_67 * V_68 ;
T_2 * V_25 ;
V_10 = F_1 ( V_3 ) ;
if ( ! V_10 )
return;
V_9 = (struct V_8 * ) V_10 -> V_26 ;
if ( ! V_66 )
V_9 -> V_19 |=
F_5 ( V_69 ) ;
V_25 = F_11 ( V_9 ) ;
if ( V_65 )
V_25 [ 1 ] |= ( V_70 >> 8 ) ;
if ( V_66 )
V_25 [ 0 ] |= V_27 ;
V_68 = F_33 ( V_10 ) ;
V_68 -> V_71 |= V_72 |
V_73 ;
F_9 ( V_5 , L_9 ,
V_65 ? L_10 : L_11 , V_66 ? L_12 : L_11 , V_3 -> V_3 . V_17 ) ;
F_12 ( V_5 , V_10 ) ;
}
static void F_34 ( struct V_2 * V_3 ,
struct V_74 * V_75 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_1 * V_76 , * V_10 = F_35 ( V_75 ) ;
struct V_8 * V_53 = (struct V_8 * ) V_10 -> V_26 ;
struct V_67 * V_68 ;
if ( F_20 ( V_53 -> V_19 ) )
return;
V_76 = F_1 ( V_3 ) ;
if ( ! V_76 )
return;
F_9 ( V_5 , L_13 ,
V_3 -> V_3 . V_17 ) ;
V_76 -> V_77 = 1 ;
F_36 ( V_76 , V_78 ) ;
F_37 ( V_5 , V_76 ) ;
V_68 = F_33 ( V_76 ) ;
V_68 -> V_79 . V_18 = & V_5 -> V_18 ;
V_68 -> V_71 |= V_80 ;
F_38 ( V_75 , V_76 ) ;
}
static void F_39 ( struct V_2 * V_3 , int V_81 )
{
struct V_6 * V_7 = V_3 -> V_5 -> V_7 ;
int V_82 ;
struct V_74 V_75 ;
struct V_1 * V_10 ;
bool V_83 = false ;
F_40 ( & V_75 ) ;
for ( V_82 = 0 ; V_82 < V_84 ; V_82 ++ ) {
while ( V_81 != 0 ) {
V_10 = F_41 ( & V_3 -> V_85 [ V_82 ] ) ;
if ( ! V_10 ) {
V_10 = F_41 (
& V_3 -> V_86 [ V_82 ] ) ;
if ( V_10 )
V_7 -> V_87 -- ;
}
if ( ! V_10 )
break;
V_81 -- ;
F_38 ( & V_75 , V_10 ) ;
}
if ( ! F_42 ( & V_3 -> V_85 [ V_82 ] ) ||
! F_42 ( & V_3 -> V_86 [ V_82 ] ) )
V_83 = true ;
}
if ( F_42 ( & V_75 ) ) {
F_32 ( V_3 , false , true ) ;
return;
}
if ( F_10 ( V_3 , V_61 ) )
F_34 ( V_3 , & V_75 ) ;
F_9 ( V_3 -> V_5 , L_14 ,
F_43 ( & V_75 ) , V_3 -> V_3 . V_17 ) ;
F_44 (&frames, skb) {
struct V_67 * V_68 = F_33 ( V_10 ) ;
struct V_8 * V_53 = ( void * ) V_10 -> V_26 ;
V_68 -> V_71 |= V_72 ;
if ( V_83 || ! F_45 ( & V_75 , V_10 ) )
V_53 -> V_19 |=
F_5 ( V_69 ) ;
else
V_53 -> V_19 &=
F_5 ( ~ V_69 ) ;
if ( F_45 ( & V_75 , V_10 ) &&
F_20 ( V_53 -> V_19 ) ) {
T_2 * V_88 = F_11 ( V_53 ) ;
* V_88 |= V_27 ;
V_68 -> V_71 |= V_73 ;
}
}
F_46 ( V_7 , & V_75 ) ;
F_47 ( V_3 ) ;
}
void F_31 ( T_2 * V_25 , struct V_2 * V_3 ,
bool V_89 , bool V_90 )
{
T_2 V_65 = V_25 [ 1 ] & ( V_70 >> 8 ) ;
T_2 V_66 = V_25 [ 0 ] & V_27 ;
if ( V_89 ) {
if ( V_65 && V_90 )
F_24 ( V_3 , V_62 ) ;
if ( V_66 )
F_23 ( V_3 , V_61 ) ;
else if ( V_90 &&
F_10 ( V_3 , V_24 ) &&
! F_48 ( V_3 , V_61 ) )
F_39 ( V_3 , - 1 ) ;
} else {
if ( V_66 )
F_23 ( V_3 , V_62 ) ;
else if ( V_3 -> V_31 -> V_43 != V_46 )
F_24 ( V_3 , V_62 ) ;
if ( V_65 && ! F_48 ( V_3 , V_61 ) )
F_39 ( V_3 , - 1 ) ;
}
}
void F_49 ( struct V_2 * V_3 ,
struct V_91 * V_92 )
{
int V_82 , V_93 = 0 ;
bool V_94 = false ;
if ( V_3 -> V_31 -> V_38 == V_42 )
V_94 = F_50 ( V_92 -> V_95 , V_92 -> V_96 ,
V_3 -> V_31 -> V_97 ) ;
if ( V_94 )
F_9 ( V_3 -> V_5 , L_15 ,
V_3 -> V_3 . V_17 ) ;
if ( F_10 ( V_3 , V_24 ) &&
( ! V_92 -> V_98 || ! F_51 ( * V_92 -> V_98 ) ) )
return;
if ( ! F_10 ( V_3 , V_61 ) )
for ( V_82 = 0 ; V_82 < V_84 ; V_82 ++ )
V_93 += F_43 ( & V_3 -> V_86 [ V_82 ] ) +
F_43 ( & V_3 -> V_85 [ V_82 ] ) ;
if ( ! V_94 && ! V_93 )
return;
if ( V_3 -> V_31 -> V_38 == V_42 )
F_32 ( V_3 , V_94 , ! V_93 ) ;
else
F_39 ( V_3 , 1 ) ;
}
