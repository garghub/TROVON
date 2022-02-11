int
F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static int
F_3 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_4 ) ;
}
static int
F_4 ( T_1 V_5 )
{
if ( ( V_5 == V_6 ) ||
( V_5 == V_7 ) ||
( V_5 == V_8 ) ||
( V_5 == V_9 ) )
return 1 ;
return 0 ;
}
static struct V_1 *
F_5 ( struct V_10 * V_11 , T_2 V_12 )
{
struct V_1 * V_13 = (struct V_1 * ) & V_11 -> V_13 ;
struct V_14 * V_15 ;
struct V_1 * V_2 ;
F_6 (tmp, &rnhead->sm.sm_list) {
V_2 = (struct V_1 * ) V_15 ;
if ( V_2 -> V_12 == V_12 )
return V_2 ;
}
return NULL ;
}
static struct V_1 *
F_7 ( struct V_10 * V_11 , T_1 * V_16 )
{
struct V_1 * V_13 = (struct V_1 * ) & V_11 -> V_13 ;
struct V_14 * V_15 ;
struct V_1 * V_2 ;
F_6 (tmp, &rnhead->sm.sm_list) {
V_2 = (struct V_1 * ) V_15 ;
if ( ! memcmp ( F_8 ( V_2 ) , V_16 , 8 ) )
return V_2 ;
}
return NULL ;
}
struct V_1 *
F_9 ( struct V_10 * V_11 , T_2 V_17 )
{
struct V_1 * V_13 = (struct V_1 * ) & V_11 -> V_13 ;
struct V_14 * V_15 ;
struct V_1 * V_2 ;
F_6 (tmp, &rnhead->sm.sm_list) {
V_2 = (struct V_1 * ) V_15 ;
if ( V_2 -> V_18 == V_17 )
return V_2 ;
}
return NULL ;
}
static int
F_10 ( struct V_10 * V_11 , T_2 V_19 ,
T_2 * V_20 )
{
struct V_1 * V_13 ;
struct V_14 * V_15 , * V_21 ;
struct V_1 * V_2 ;
struct V_10 * V_22 ;
struct V_23 * V_24 = F_11 ( V_11 ) ;
F_6 (tmp1, &hw->sln_head) {
V_22 = (struct V_10 * ) V_21 ;
if ( V_22 == V_11 )
continue;
V_13 = (struct V_1 * ) & V_22 -> V_13 ;
F_6 (tmp, &rnhead->sm.sm_list) {
V_2 = (struct V_1 * ) V_15 ;
if ( F_1 ( V_2 ) ) {
if ( V_2 -> V_12 == V_19 ) {
* V_20 = F_12 ( V_22 ) ;
return 1 ;
}
}
}
}
return 0 ;
}
static struct V_1 *
F_13 ( struct V_10 * V_11 )
{
struct V_23 * V_24 = F_11 ( V_11 ) ;
struct V_1 * V_2 = F_14 ( V_24 -> V_25 , V_26 ) ;
if ( ! V_2 )
goto V_27;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
if ( F_15 ( V_2 , V_11 ) )
goto V_28;
F_16 ( V_11 , V_29 ) ;
return V_2 ;
V_28:
F_17 ( V_2 , V_24 -> V_25 ) ;
V_27:
F_16 ( V_11 , V_30 ) ;
return NULL ;
}
static void
F_18 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_11 ( F_19 ( V_2 ) ) ;
F_20 ( V_2 ) ;
F_16 ( V_2 -> V_31 , V_32 ) ;
F_17 ( V_2 , V_24 -> V_25 ) ;
}
static struct V_1 *
F_21 ( struct V_10 * V_11 , T_2 V_12 )
{
struct V_1 * V_2 ;
V_2 = F_5 ( V_11 , V_12 ) ;
if ( ! V_2 ) {
V_2 = F_13 ( V_11 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_12 = V_12 ;
}
return V_2 ;
}
void
F_22 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
F_23 ( F_3 ( V_2 ) != 0 ) ;
F_18 ( V_2 ) ;
}
struct V_1 *
F_24 ( struct V_10 * V_11 , T_2 V_19 ,
struct V_33 * V_34 )
{
T_1 V_5 ;
struct V_1 * V_2 , * V_35 ;
T_2 V_20 = 0 ;
T_3 * V_36 ;
V_36 = ( T_3 * ) & V_34 -> V_37 [ 0 ] ;
V_5 =
F_25 ( V_34 -> V_38 ) ;
if ( V_5 == V_39 ) {
F_26 ( V_11 ,
L_1
L_2 , V_5 , V_19 ) ;
return NULL ;
}
V_2 = F_5 ( V_11 , V_19 ) ;
if ( ! V_2 ) {
if ( F_10 ( V_11 , V_19 , & V_20 ) ) {
F_27 ( V_11 ,
L_3 ,
V_19 , V_20 ) ;
return NULL ;
}
V_2 = F_7 ( V_11 , V_34 -> V_16 ) ;
if ( ! V_2 )
goto V_40;
} else {
if ( F_4 ( V_5 ) ) {
V_35 = F_9 ( V_11 ,
( ( F_28 ( * V_36 ) >> 8 ) & V_41 ) ) ;
if ( V_35 == NULL ) {
F_29 ( V_2 ) = V_42 ;
goto V_40;
}
if ( ! memcmp ( F_8 ( V_35 ) , V_34 -> V_16 , 8 ) ) {
if ( V_2 == V_35 )
goto V_43;
F_26 ( V_11 ,
L_4
L_5 ,
V_2 -> V_18 ,
F_30 ( V_34 -> V_16 ) ,
V_19 ) ;
if ( F_1 ( V_2 ) ) {
F_27 ( V_11 ,
L_6
L_7 ,
V_19 ) ;
F_31 ( 0 ) ;
}
F_29 ( V_2 ) = V_42 ;
V_2 = V_35 ;
goto V_43;
}
F_29 ( V_2 ) = V_42 ;
goto V_40;
}
if ( ! memcmp ( F_8 ( V_2 ) , V_34 -> V_16 , 8 ) )
goto V_43;
V_35 = F_7 ( V_11 , V_34 -> V_16 ) ;
if ( V_35 != NULL ) {
F_26 ( V_11 ,
L_8
L_9 , V_19 ,
F_30 ( V_34 -> V_16 ) ,
V_35 -> V_18 ) ;
F_29 ( V_2 ) = V_42 ;
V_2 = V_35 ;
} else {
F_26 ( V_11 ,
L_10
L_11 ,
V_19 ,
F_30 ( F_8 ( V_2 ) ) ) ;
if ( F_1 ( V_2 ) ) {
F_27 ( V_11 ,
L_12
L_13 ,
F_30 ( F_8 ( V_2 ) ) ,
V_19 ) ;
F_31 ( 0 ) ;
}
F_29 ( V_2 ) = V_42 ;
goto V_40;
}
}
V_43:
F_26 ( V_11 , L_14 ,
V_2 , V_19 , F_30 ( V_34 -> V_16 ) ) ;
F_29 ( V_2 ) = V_19 ;
V_2 -> V_44 = V_34 ;
F_16 ( V_11 , V_45 ) ;
return V_2 ;
V_40:
V_2 = F_21 ( V_11 , V_19 ) ;
if ( ! V_2 )
return NULL ;
F_26 ( V_11 , L_15 ,
V_2 , V_19 , F_30 ( V_34 -> V_16 ) ) ;
V_2 -> V_44 = V_34 ;
return V_2 ;
}
static int
F_32 ( struct V_10 * V_11 , struct V_1 * V_2 ,
struct V_33 * V_34 )
{
T_1 null [ 8 ] ;
T_1 V_5 ;
T_1 V_46 ;
T_3 * V_47 ;
V_47 = ( T_3 * ) & V_34 -> V_37 [ 0 ] ;
V_5 =
F_25 ( V_34 -> V_38 ) ;
switch ( V_5 ) {
case V_6 :
V_2 -> V_48 = V_49 ;
if ( ( ( F_28 ( * V_47 ) >> 8 ) & V_41 ) != V_50 ) {
F_33 ( V_11 , L_16 ,
F_29 ( V_2 ) ) ;
return - V_51 ;
}
if ( F_34 ( V_34 -> V_52 ) )
V_11 -> V_53 |= V_54 ;
break;
case V_8 :
V_2 -> V_48 = V_55 ;
if ( ( ( F_28 ( * V_47 ) >> 8 ) & V_41 ) != V_56 ) {
F_33 ( V_11 , L_16 ,
F_29 ( V_2 ) ) ;
return - V_51 ;
}
break;
case V_57 :
case V_58 :
V_2 -> V_48 = V_59 ;
if ( V_34 -> V_60 == V_61 ||
V_34 -> V_60 == V_62 ) {
if ( F_35 (
V_34 -> V_63 ) )
V_2 -> V_64 |= V_65 ;
if ( F_36 ( V_34 -> V_63 ) )
V_2 -> V_64 |= V_66 ;
if ( F_37 ( V_34 -> V_63 ) )
V_2 -> V_64 |= V_67 ;
if ( F_38 ( V_34 -> V_63 ) )
V_2 -> V_48 |= V_68 ;
if ( F_39 ( V_34 -> V_63 ) )
V_2 -> V_48 |= V_69 ;
}
break;
case V_9 :
case V_39 :
V_2 -> V_48 = 0 ;
break;
default:
F_33 ( V_11 , L_17 ,
F_29 ( V_2 ) , V_5 ) ;
return - V_51 ;
}
if ( V_5 == V_58 || V_5 == V_8 ) {
memset ( null , 0 , 8 ) ;
if ( ! memcmp ( V_34 -> V_70 , null , 8 ) ) {
F_33 ( V_11 ,
L_18
L_19 ,
F_29 ( V_2 ) ,
( F_28 ( * V_47 ) & V_41 ) ) ;
return - V_51 ;
}
if ( ! memcmp ( V_34 -> V_16 , null , 8 ) ) {
F_33 ( V_11 ,
L_20
L_19 ,
F_29 ( V_2 ) ,
( F_28 ( * V_47 ) & V_41 ) ) ;
return - V_51 ;
}
}
V_2 -> V_18 = ( F_28 ( * V_47 ) >> 8 ) & V_41 ;
memcpy ( F_40 ( V_2 ) , V_34 -> V_70 , 8 ) ;
memcpy ( F_8 ( V_2 ) , V_34 -> V_16 , 8 ) ;
V_2 -> V_71 . V_72 . V_73 = V_34 -> V_74 ;
V_46 = F_41 ( V_34 -> V_52 ) ;
V_2 -> V_71 . V_75 [ V_46 - 1 ] . V_76 = F_42 ( V_77 ) ;
return 0 ;
}
static void
F_43 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_19 ( V_2 ) ;
struct V_23 * V_24 = F_11 ( V_11 ) ;
F_44 ( & V_24 -> V_78 ) ;
F_45 ( V_2 ) ;
F_46 ( & V_24 -> V_78 ) ;
if ( V_2 -> V_48 & V_68 )
V_11 -> V_79 ++ ;
if ( V_2 -> V_18 == V_80 )
F_47 ( V_11 , ( void * ) V_2 ) ;
}
static void
F_48 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_19 ( V_2 ) ;
struct V_23 * V_24 = F_11 ( V_11 ) ;
F_49 ( V_81 ) ;
int V_82 = 0 ;
if ( ! F_50 ( & V_2 -> V_83 ) ) {
F_51 ( V_24 , L_21 ) ;
F_52 ( & V_2 -> V_83 , & V_81 ) ;
V_82 = 1 ;
}
if ( V_2 -> V_48 & V_68 ) {
V_11 -> V_79 -- ;
V_11 -> V_84 -- ;
}
F_44 ( & V_24 -> V_78 ) ;
F_53 ( V_2 ) ;
F_46 ( & V_24 -> V_78 ) ;
if ( V_82 )
F_54 ( F_55 ( V_24 ) , & V_81 ) ;
}
static void
V_4 ( struct V_1 * V_2 , enum V_85 V_86 )
{
struct V_10 * V_11 = F_19 ( V_2 ) ;
int V_87 = 0 ;
F_16 ( V_2 , V_88 [ V_86 ] ) ;
switch ( V_86 ) {
case V_89 :
case V_90 :
V_87 = F_32 ( V_11 , V_2 , V_2 -> V_44 ) ;
if ( ! V_87 ) {
F_56 ( & V_2 -> V_91 , V_3 ) ;
F_43 ( V_2 ) ;
} else {
F_16 ( V_2 , V_92 ) ;
}
break;
case V_93 :
F_26 ( V_11 ,
L_22
L_23 , F_29 ( V_2 ) , V_86 ) ;
F_16 ( V_2 , V_94 ) ;
break;
default:
F_26 ( V_11 ,
L_24
L_23 , F_29 ( V_2 ) , V_86 ) ;
F_16 ( V_2 , V_95 ) ;
break;
}
}
static void
V_3 ( struct V_1 * V_2 , enum V_85 V_86 )
{
struct V_10 * V_11 = F_19 ( V_2 ) ;
int V_87 = 0 ;
F_16 ( V_2 , V_88 [ V_86 ] ) ;
switch ( V_86 ) {
case V_89 :
case V_90 :
F_26 ( V_11 ,
L_25
L_26 , F_29 ( V_2 ) , V_86 ,
V_2 -> V_18 ) ;
F_16 ( V_2 , V_94 ) ;
break;
case V_96 :
case V_97 :
V_87 = F_32 ( V_11 , V_2 , V_2 -> V_44 ) ;
if ( ! V_87 )
F_43 ( V_2 ) ;
else
F_16 ( V_2 , V_92 ) ;
break;
case V_98 :
F_56 ( & V_2 -> V_91 , V_99 ) ;
F_48 ( V_2 ) ;
break;
case V_93 :
F_56 ( & V_2 -> V_91 , V_99 ) ;
F_48 ( V_2 ) ;
break;
case V_100 :
F_56 ( & V_2 -> V_91 , V_4 ) ;
F_48 ( V_2 ) ;
break;
case V_101 :
F_56 ( & V_2 -> V_91 , V_102 ) ;
F_48 ( V_2 ) ;
break;
default:
F_26 ( V_11 ,
L_27
L_23 , F_29 ( V_2 ) , V_86 ,
V_2 -> V_18 ) ;
F_16 ( V_2 , V_95 ) ;
break;
}
}
static void
V_99 ( struct V_1 * V_2 , enum V_85 V_86 )
{
struct V_10 * V_11 = F_19 ( V_2 ) ;
int V_87 = 0 ;
F_16 ( V_2 , V_88 [ V_86 ] ) ;
switch ( V_86 ) {
case V_89 :
case V_90 :
V_87 = F_32 ( V_11 , V_2 , V_2 -> V_44 ) ;
if ( ! V_87 ) {
F_56 ( & V_2 -> V_91 , V_3 ) ;
F_43 ( V_2 ) ;
} else {
F_16 ( V_2 , V_92 ) ;
F_57 ( & V_2 -> V_91 , V_100 ) ;
}
break;
case V_98 :
F_26 ( V_11 ,
L_25
L_28 , F_29 ( V_2 ) , V_86 ,
V_2 -> V_18 ) ;
F_16 ( V_2 , V_94 ) ;
break;
case V_100 :
F_56 ( & V_2 -> V_91 , V_4 ) ;
break;
case V_101 :
F_56 ( & V_2 -> V_91 , V_102 ) ;
break;
default:
F_26 ( V_11 ,
L_27
L_28 , F_29 ( V_2 ) , V_86 ,
V_2 -> V_18 ) ;
F_16 ( V_2 , V_95 ) ;
break;
}
}
static void
V_102 ( struct V_1 * V_2 , enum V_85 V_86 )
{
struct V_10 * V_11 = F_19 ( V_2 ) ;
int V_87 = 0 ;
F_16 ( V_2 , V_88 [ V_86 ] ) ;
switch ( V_86 ) {
case V_89 :
case V_90 :
V_87 = F_32 ( V_11 , V_2 , V_2 -> V_44 ) ;
if ( ! V_87 ) {
F_56 ( & V_2 -> V_91 , V_3 ) ;
F_43 ( V_2 ) ;
} else {
F_16 ( V_2 , V_92 ) ;
F_57 ( & V_2 -> V_91 , V_100 ) ;
}
break;
case V_100 :
F_56 ( & V_2 -> V_91 , V_4 ) ;
break;
case V_98 :
case V_101 :
F_26 ( V_11 ,
L_29
L_30 , F_29 ( V_2 ) ,
V_86 , V_2 -> V_18 ) ;
break;
default:
F_26 ( V_11 ,
L_31
L_30 , F_29 ( V_2 ) ,
V_86 , V_2 -> V_18 ) ;
F_16 ( V_2 , V_95 ) ;
break;
}
}
void
F_58 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_19 ( V_2 ) ;
if ( F_1 ( V_2 ) )
return;
F_57 ( & V_2 -> V_91 , V_100 ) ;
if ( F_3 ( V_2 ) )
F_22 ( V_11 , V_2 ) ;
}
void
F_59 ( struct V_1 * V_2 , T_1 V_103 )
{
struct V_10 * V_11 = F_19 ( V_2 ) ;
enum V_85 V_86 ;
V_86 = F_60 ( V_103 ) ;
if ( ! V_86 ) {
F_33 ( V_11 , L_32 ,
F_29 ( V_2 ) , V_103 ) ;
F_16 ( V_2 , V_95 ) ;
return;
}
F_16 ( V_2 , V_104 [ V_103 ] ) ;
V_2 -> V_105 = V_2 -> V_106 ;
V_2 -> V_106 = V_103 ;
F_57 ( & V_2 -> V_91 , V_86 ) ;
if ( F_3 ( V_2 ) )
F_22 ( V_11 , V_2 ) ;
}
static int
F_15 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
F_19 ( V_2 ) = V_11 ;
F_61 ( & V_2 -> V_91 , V_4 ) ;
F_62 ( & V_2 -> V_83 ) ;
F_29 ( V_2 ) = V_42 ;
F_63 ( & V_2 -> V_91 . V_107 , & V_11 -> V_13 ) ;
return 0 ;
}
static void
F_20 ( struct V_1 * V_2 )
{
F_64 ( & V_2 -> V_91 . V_107 ) ;
F_23 ( F_50 ( & V_2 -> V_83 ) ) ;
}
