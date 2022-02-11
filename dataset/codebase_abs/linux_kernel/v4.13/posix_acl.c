static struct V_1 * * F_1 ( struct V_2 * V_2 , int type )
{
switch ( type ) {
case V_3 :
return & V_2 -> V_4 ;
case V_5 :
return & V_2 -> V_6 ;
default:
F_2 () ;
}
}
struct V_1 * F_3 ( struct V_2 * V_2 , int type )
{
struct V_1 * * V_7 = F_1 ( V_2 , type ) ;
struct V_1 * V_8 ;
for (; ; ) {
F_4 () ;
V_8 = F_5 ( * V_7 ) ;
if ( ! V_8 || F_6 ( V_8 ) ||
F_7 ( & V_8 -> V_9 ) )
break;
F_8 () ;
F_9 () ;
}
F_8 () ;
return V_8 ;
}
struct V_1 * F_10 ( struct V_2 * V_2 , int type )
{
return F_5 ( * F_1 ( V_2 , type ) ) ;
}
void F_11 ( struct V_2 * V_2 , int type , struct V_1 * V_8 )
{
struct V_1 * * V_7 = F_1 ( V_2 , type ) ;
struct V_1 * V_10 ;
V_10 = F_12 ( V_7 , F_13 ( V_8 ) ) ;
if ( ! F_6 ( V_10 ) )
F_14 ( V_10 ) ;
}
static void F_15 ( struct V_1 * * V_7 )
{
struct V_1 * V_10 ;
V_10 = F_12 ( V_7 , V_11 ) ;
if ( ! F_6 ( V_10 ) )
F_14 ( V_10 ) ;
}
void F_16 ( struct V_2 * V_2 , int type )
{
F_15 ( F_1 ( V_2 , type ) ) ;
}
void F_17 ( struct V_2 * V_2 )
{
F_15 ( & V_2 -> V_4 ) ;
F_15 ( & V_2 -> V_6 ) ;
}
struct V_1 * F_18 ( struct V_2 * V_2 , int type )
{
void * V_12 ;
struct V_1 * * V_7 ;
struct V_1 * V_8 ;
V_8 = F_3 ( V_2 , type ) ;
if ( ! F_6 ( V_8 ) )
return V_8 ;
if ( ! F_19 ( V_2 ) )
return NULL ;
V_12 = F_20 ( V_13 ) ;
V_7 = F_1 ( V_2 , type ) ;
if ( F_21 ( V_7 , V_11 , V_12 ) != V_11 )
;
if ( ! V_2 -> V_14 -> F_18 ) {
F_11 ( V_2 , type , NULL ) ;
return NULL ;
}
V_8 = V_2 -> V_14 -> F_18 ( V_2 , type ) ;
if ( F_22 ( V_8 ) ) {
F_21 ( V_7 , V_12 , V_11 ) ;
return V_8 ;
}
F_13 ( V_8 ) ;
if ( F_23 ( F_21 ( V_7 , V_12 , V_8 ) != V_12 ) )
F_14 ( V_8 ) ;
return V_8 ;
}
void
F_24 ( struct V_1 * V_8 , int V_15 )
{
F_25 ( & V_8 -> V_9 , 1 ) ;
V_8 -> V_16 = V_15 ;
}
struct V_1 *
F_26 ( int V_15 , T_1 V_17 )
{
const T_2 V_18 = sizeof( struct V_1 ) +
V_15 * sizeof( struct V_19 ) ;
struct V_1 * V_8 = F_27 ( V_18 , V_17 ) ;
if ( V_8 )
F_24 ( V_8 , V_15 ) ;
return V_8 ;
}
static struct V_1 *
F_28 ( const struct V_1 * V_8 , T_1 V_17 )
{
struct V_1 * V_20 = NULL ;
if ( V_8 ) {
int V_18 = sizeof( struct V_1 ) + V_8 -> V_16 *
sizeof( struct V_19 ) ;
V_20 = F_29 ( V_8 , V_18 , V_17 ) ;
if ( V_20 )
F_25 ( & V_20 -> V_9 , 1 ) ;
}
return V_20 ;
}
int
F_30 ( struct V_21 * V_22 , const struct V_1 * V_8 )
{
const struct V_19 * V_23 , * V_24 ;
int V_25 = V_26 ;
int V_27 = 0 ;
F_31 (pa, acl, pe) {
if ( V_23 -> V_28 & ~ ( V_29 | V_30 | V_31 ) )
return - V_32 ;
switch ( V_23 -> V_33 ) {
case V_26 :
if ( V_25 == V_26 ) {
V_25 = V_34 ;
break;
}
return - V_32 ;
case V_34 :
if ( V_25 != V_34 )
return - V_32 ;
if ( ! F_32 ( V_22 , V_23 -> V_35 ) )
return - V_32 ;
V_27 = 1 ;
break;
case V_36 :
if ( V_25 == V_34 ) {
V_25 = V_37 ;
break;
}
return - V_32 ;
case V_37 :
if ( V_25 != V_37 )
return - V_32 ;
if ( ! F_33 ( V_22 , V_23 -> V_38 ) )
return - V_32 ;
V_27 = 1 ;
break;
case V_39 :
if ( V_25 != V_37 )
return - V_32 ;
V_25 = V_40 ;
break;
case V_40 :
if ( V_25 == V_40 ||
( V_25 == V_37 && ! V_27 ) ) {
V_25 = 0 ;
break;
}
return - V_32 ;
default:
return - V_32 ;
}
}
if ( V_25 == 0 )
return 0 ;
return - V_32 ;
}
int
F_34 ( const struct V_1 * V_8 , T_3 * V_41 )
{
const struct V_19 * V_23 , * V_24 ;
T_3 V_42 = 0 ;
int V_43 = 0 ;
if ( ! V_8 )
return 0 ;
F_31 (pa, acl, pe) {
switch ( V_23 -> V_33 ) {
case V_26 :
V_42 |= ( V_23 -> V_28 & V_44 ) << 6 ;
break;
case V_36 :
V_42 |= ( V_23 -> V_28 & V_44 ) << 3 ;
break;
case V_40 :
V_42 |= V_23 -> V_28 & V_44 ;
break;
case V_39 :
V_42 = ( V_42 & ~ V_45 ) |
( ( V_23 -> V_28 & V_44 ) << 3 ) ;
V_43 = 1 ;
break;
case V_34 :
case V_37 :
V_43 = 1 ;
break;
default:
return - V_32 ;
}
}
if ( V_41 )
* V_41 = ( * V_41 & ~ V_46 ) | V_42 ;
return V_43 ;
}
struct V_1 *
F_35 ( T_3 V_42 , T_1 V_17 )
{
struct V_1 * V_8 = F_26 ( 3 , V_17 ) ;
if ( ! V_8 )
return F_36 ( - V_47 ) ;
V_8 -> V_48 [ 0 ] . V_33 = V_26 ;
V_8 -> V_48 [ 0 ] . V_28 = ( V_42 & V_49 ) >> 6 ;
V_8 -> V_48 [ 1 ] . V_33 = V_36 ;
V_8 -> V_48 [ 1 ] . V_28 = ( V_42 & V_45 ) >> 3 ;
V_8 -> V_48 [ 2 ] . V_33 = V_40 ;
V_8 -> V_48 [ 2 ] . V_28 = ( V_42 & V_44 ) ;
return V_8 ;
}
int
F_37 ( struct V_2 * V_2 , const struct V_1 * V_8 , int V_50 )
{
const struct V_19 * V_23 , * V_24 , * V_51 ;
int V_52 = 0 ;
V_50 &= V_53 | V_54 | V_55 | V_56 ;
F_31 (pa, acl, pe) {
switch( V_23 -> V_33 ) {
case V_26 :
if ( F_38 ( V_2 -> V_57 , F_39 () ) )
goto V_58;
break;
case V_34 :
if ( F_38 ( V_23 -> V_35 , F_39 () ) )
goto V_59;
break;
case V_36 :
if ( F_40 ( V_2 -> V_60 ) ) {
V_52 = 1 ;
if ( ( V_23 -> V_28 & V_50 ) == V_50 )
goto V_59;
}
break;
case V_37 :
if ( F_40 ( V_23 -> V_38 ) ) {
V_52 = 1 ;
if ( ( V_23 -> V_28 & V_50 ) == V_50 )
goto V_59;
}
break;
case V_39 :
break;
case V_40 :
if ( V_52 )
return - V_61 ;
else
goto V_58;
default:
return - V_62 ;
}
}
return - V_62 ;
V_59:
for ( V_51 = V_23 + 1 ; V_51 != V_24 ; V_51 ++ ) {
if ( V_51 -> V_33 == V_39 ) {
if ( ( V_23 -> V_28 & V_51 -> V_28 & V_50 ) == V_50 )
return 0 ;
return - V_61 ;
}
}
V_58:
if ( ( V_23 -> V_28 & V_50 ) == V_50 )
return 0 ;
return - V_61 ;
}
static int F_41 ( struct V_1 * V_8 , T_3 * V_41 )
{
struct V_19 * V_23 , * V_24 ;
struct V_19 * V_63 = NULL , * V_51 = NULL ;
T_3 V_42 = * V_41 ;
int V_43 = 0 ;
F_31 (pa, acl, pe) {
switch( V_23 -> V_33 ) {
case V_26 :
V_23 -> V_28 &= ( V_42 >> 6 ) | ~ V_44 ;
V_42 &= ( V_23 -> V_28 << 6 ) | ~ V_49 ;
break;
case V_34 :
case V_37 :
V_43 = 1 ;
break;
case V_36 :
V_63 = V_23 ;
break;
case V_40 :
V_23 -> V_28 &= V_42 | ~ V_44 ;
V_42 &= V_23 -> V_28 | ~ V_44 ;
break;
case V_39 :
V_51 = V_23 ;
V_43 = 1 ;
break;
default:
return - V_62 ;
}
}
if ( V_51 ) {
V_51 -> V_28 &= ( V_42 >> 3 ) | ~ V_44 ;
V_42 &= ( V_51 -> V_28 << 3 ) | ~ V_45 ;
} else {
if ( ! V_63 )
return - V_62 ;
V_63 -> V_28 &= ( V_42 >> 3 ) | ~ V_44 ;
V_42 &= ( V_63 -> V_28 << 3 ) | ~ V_45 ;
}
* V_41 = ( * V_41 & ~ V_46 ) | V_42 ;
return V_43 ;
}
static int F_42 ( struct V_1 * V_8 , T_3 V_42 )
{
struct V_19 * V_63 = NULL , * V_51 = NULL ;
struct V_19 * V_23 , * V_24 ;
F_31 (pa, acl, pe) {
switch( V_23 -> V_33 ) {
case V_26 :
V_23 -> V_28 = ( V_42 & V_49 ) >> 6 ;
break;
case V_34 :
case V_37 :
break;
case V_36 :
V_63 = V_23 ;
break;
case V_39 :
V_51 = V_23 ;
break;
case V_40 :
V_23 -> V_28 = ( V_42 & V_44 ) ;
break;
default:
return - V_62 ;
}
}
if ( V_51 ) {
V_51 -> V_28 = ( V_42 & V_45 ) >> 3 ;
} else {
if ( ! V_63 )
return - V_62 ;
V_63 -> V_28 = ( V_42 & V_45 ) >> 3 ;
}
return 0 ;
}
int
F_43 ( struct V_1 * * V_8 , T_1 V_64 , T_3 * V_41 )
{
struct V_1 * V_20 = F_28 ( * V_8 , V_64 ) ;
int V_65 = - V_47 ;
if ( V_20 ) {
V_65 = F_41 ( V_20 , V_41 ) ;
if ( V_65 < 0 ) {
F_14 ( V_20 ) ;
V_20 = NULL ;
}
}
F_14 ( * V_8 ) ;
* V_8 = V_20 ;
return V_65 ;
}
int
F_44 ( struct V_1 * * V_8 , T_1 V_64 , T_3 V_42 )
{
struct V_1 * V_20 = F_28 ( * V_8 , V_64 ) ;
int V_65 = - V_47 ;
if ( V_20 ) {
V_65 = F_42 ( V_20 , V_42 ) ;
if ( V_65 ) {
F_14 ( V_20 ) ;
V_20 = NULL ;
}
}
F_14 ( * V_8 ) ;
* V_8 = V_20 ;
return V_65 ;
}
int
F_45 ( struct V_2 * V_2 , T_3 V_42 )
{
struct V_1 * V_8 ;
int V_66 = 0 ;
if ( ! F_19 ( V_2 ) )
return 0 ;
if ( ! V_2 -> V_14 -> V_67 )
return - V_68 ;
V_8 = F_18 ( V_2 , V_3 ) ;
if ( F_46 ( V_8 ) ) {
if ( V_8 == F_36 ( - V_68 ) )
return 0 ;
return F_47 ( V_8 ) ;
}
V_66 = F_44 ( & V_8 , V_69 , V_42 ) ;
if ( V_66 )
return V_66 ;
V_66 = V_2 -> V_14 -> V_67 ( V_2 , V_8 , V_3 ) ;
F_14 ( V_8 ) ;
return V_66 ;
}
int
F_48 ( struct V_2 * V_70 , T_3 * V_42 ,
struct V_1 * * V_71 , struct V_1 * * V_8 )
{
struct V_1 * V_7 ;
struct V_1 * V_20 ;
int V_66 ;
* V_8 = NULL ;
* V_71 = NULL ;
if ( F_49 ( * V_42 ) || ! F_19 ( V_70 ) )
return 0 ;
V_7 = F_18 ( V_70 , V_5 ) ;
if ( ! V_7 || V_7 == F_36 ( - V_68 ) ) {
* V_42 &= ~ F_50 () ;
return 0 ;
}
if ( F_22 ( V_7 ) )
return F_47 ( V_7 ) ;
V_66 = - V_47 ;
V_20 = F_28 ( V_7 , V_72 ) ;
if ( ! V_20 )
goto V_73;
V_66 = F_41 ( V_20 , V_42 ) ;
if ( V_66 < 0 )
goto V_74;
if ( V_66 == 0 )
F_14 ( V_20 ) ;
else
* V_8 = V_20 ;
if ( ! F_51 ( * V_42 ) )
F_14 ( V_7 ) ;
else
* V_71 = V_7 ;
return 0 ;
V_74:
F_14 ( V_20 ) ;
V_73:
F_14 ( V_7 ) ;
return V_66 ;
}
int F_52 ( struct V_2 * V_2 , T_3 * V_41 ,
struct V_1 * * V_8 )
{
T_3 V_42 = V_2 -> V_75 ;
int error ;
error = F_34 ( * V_8 , & V_42 ) ;
if ( error < 0 )
return error ;
if ( error == 0 )
* V_8 = NULL ;
if ( ! F_40 ( V_2 -> V_60 ) &&
! F_53 ( V_2 , V_76 ) )
V_42 &= ~ V_77 ;
* V_41 = V_42 ;
return 0 ;
}
static void F_54 (
struct V_21 * V_78 , struct V_21 * V_79 ,
void * V_80 , T_2 V_18 )
{
struct V_81 * V_82 = V_80 ;
struct V_83 * V_84 = ( void * ) ( V_82 + 1 ) , * V_85 ;
int V_15 ;
T_4 V_86 ;
T_5 V_87 ;
if ( ! V_80 )
return;
if ( V_18 < sizeof( struct V_81 ) )
return;
if ( V_82 -> V_88 != F_55 ( V_89 ) )
return;
V_15 = F_56 ( V_18 ) ;
if ( V_15 < 0 )
return;
if ( V_15 == 0 )
return;
for ( V_85 = V_84 + V_15 ; V_84 != V_85 ; V_84 ++ ) {
switch( F_57 ( V_84 -> V_33 ) ) {
case V_34 :
V_86 = F_58 ( V_79 , F_59 ( V_84 -> V_90 ) ) ;
V_84 -> V_90 = F_55 ( F_60 ( V_78 , V_86 ) ) ;
break;
case V_37 :
V_87 = F_61 ( V_79 , F_59 ( V_84 -> V_90 ) ) ;
V_84 -> V_90 = F_55 ( F_62 ( V_78 , V_87 ) ) ;
break;
default:
break;
}
}
}
void F_63 ( void * V_80 , T_2 V_18 )
{
struct V_21 * V_22 = F_64 () ;
if ( V_22 == & V_91 )
return;
F_54 ( & V_91 , V_22 , V_80 , V_18 ) ;
}
void F_65 ( void * V_80 , T_2 V_18 )
{
struct V_21 * V_22 = F_64 () ;
if ( V_22 == & V_91 )
return;
F_54 ( V_22 , & V_91 , V_80 , V_18 ) ;
}
struct V_1 *
F_66 ( struct V_21 * V_22 ,
const void * V_80 , T_2 V_18 )
{
const struct V_81 * V_82 = V_80 ;
const struct V_83 * V_84 = ( const void * ) ( V_82 + 1 ) , * V_85 ;
int V_15 ;
struct V_1 * V_8 ;
struct V_19 * V_92 ;
if ( ! V_80 )
return NULL ;
if ( V_18 < sizeof( struct V_81 ) )
return F_36 ( - V_32 ) ;
if ( V_82 -> V_88 != F_55 ( V_89 ) )
return F_36 ( - V_68 ) ;
V_15 = F_56 ( V_18 ) ;
if ( V_15 < 0 )
return F_36 ( - V_32 ) ;
if ( V_15 == 0 )
return NULL ;
V_8 = F_26 ( V_15 , V_72 ) ;
if ( ! V_8 )
return F_36 ( - V_47 ) ;
V_92 = V_8 -> V_48 ;
for ( V_85 = V_84 + V_15 ; V_84 != V_85 ; V_92 ++ , V_84 ++ ) {
V_92 -> V_33 = F_57 ( V_84 -> V_33 ) ;
V_92 -> V_28 = F_57 ( V_84 -> V_28 ) ;
switch( V_92 -> V_33 ) {
case V_26 :
case V_36 :
case V_39 :
case V_40 :
break;
case V_34 :
V_92 -> V_35 =
F_58 ( V_22 ,
F_59 ( V_84 -> V_90 ) ) ;
if ( ! F_67 ( V_92 -> V_35 ) )
goto V_93;
break;
case V_37 :
V_92 -> V_38 =
F_61 ( V_22 ,
F_59 ( V_84 -> V_90 ) ) ;
if ( ! F_68 ( V_92 -> V_38 ) )
goto V_93;
break;
default:
goto V_93;
}
}
return V_8 ;
V_93:
F_14 ( V_8 ) ;
return F_36 ( - V_32 ) ;
}
int
F_69 ( struct V_21 * V_22 , const struct V_1 * V_8 ,
void * V_94 , T_2 V_18 )
{
struct V_81 * V_95 = V_94 ;
struct V_83 * V_96 ;
int V_97 , V_98 ;
V_97 = F_70 ( V_8 -> V_16 ) ;
if ( ! V_94 )
return V_97 ;
if ( V_97 > V_18 )
return - V_99 ;
V_96 = ( void * ) ( V_95 + 1 ) ;
V_95 -> V_88 = F_55 ( V_89 ) ;
for ( V_98 = 0 ; V_98 < V_8 -> V_16 ; V_98 ++ , V_96 ++ ) {
const struct V_19 * V_92 = & V_8 -> V_48 [ V_98 ] ;
V_96 -> V_33 = F_71 ( V_92 -> V_33 ) ;
V_96 -> V_28 = F_71 ( V_92 -> V_28 ) ;
switch( V_92 -> V_33 ) {
case V_34 :
V_96 -> V_90 =
F_55 ( F_60 ( V_22 , V_92 -> V_35 ) ) ;
break;
case V_37 :
V_96 -> V_90 =
F_55 ( F_62 ( V_22 , V_92 -> V_38 ) ) ;
break;
default:
V_96 -> V_90 = F_55 ( V_100 ) ;
break;
}
}
return V_97 ;
}
static int
F_72 ( const struct V_101 * V_102 ,
struct V_103 * V_104 , struct V_2 * V_2 ,
const char * V_105 , void * V_80 , T_2 V_18 )
{
struct V_1 * V_8 ;
int error ;
if ( ! F_19 ( V_2 ) )
return - V_68 ;
if ( F_49 ( V_2 -> V_75 ) )
return - V_68 ;
V_8 = F_18 ( V_2 , V_102 -> V_17 ) ;
if ( F_22 ( V_8 ) )
return F_47 ( V_8 ) ;
if ( V_8 == NULL )
return - V_106 ;
error = F_69 ( & V_91 , V_8 , V_80 , V_18 ) ;
F_14 ( V_8 ) ;
return error ;
}
int
F_73 ( struct V_2 * V_2 , int type , struct V_1 * V_8 )
{
if ( ! F_19 ( V_2 ) )
return - V_68 ;
if ( ! V_2 -> V_14 -> V_67 )
return - V_68 ;
if ( type == V_5 && ! F_51 ( V_2 -> V_75 ) )
return V_8 ? - V_61 : 0 ;
if ( ! F_74 ( V_2 ) )
return - V_107 ;
if ( V_8 ) {
int V_66 = F_30 ( V_2 -> V_108 -> V_109 , V_8 ) ;
if ( V_66 )
return V_66 ;
}
return V_2 -> V_14 -> V_67 ( V_2 , V_8 , type ) ;
}
static int
F_75 ( const struct V_101 * V_102 ,
struct V_103 * V_104 , struct V_2 * V_2 ,
const char * V_105 , const void * V_80 ,
T_2 V_18 , int V_17 )
{
struct V_1 * V_8 = NULL ;
int V_66 ;
if ( V_80 ) {
V_8 = F_66 ( & V_91 , V_80 , V_18 ) ;
if ( F_22 ( V_8 ) )
return F_47 ( V_8 ) ;
}
V_66 = F_73 ( V_2 , V_102 -> V_17 , V_8 ) ;
F_14 ( V_8 ) ;
return V_66 ;
}
static bool
F_76 ( struct V_103 * V_103 )
{
return F_19 ( F_77 ( V_103 ) ) ;
}
int F_78 ( struct V_2 * V_2 , struct V_1 * V_8 , int type )
{
int error ;
if ( type == V_3 ) {
error = F_52 ( V_2 ,
& V_2 -> V_75 , & V_8 ) ;
if ( error )
return error ;
}
V_2 -> V_110 = F_79 ( V_2 ) ;
F_11 ( V_2 , type , V_8 ) ;
return 0 ;
}
int F_80 ( struct V_2 * V_70 , struct V_2 * V_2 )
{
struct V_1 * V_71 , * V_8 ;
int error ;
error = F_48 ( V_70 , & V_2 -> V_75 , & V_71 , & V_8 ) ;
if ( error )
return error ;
F_11 ( V_2 , V_5 , V_71 ) ;
F_11 ( V_2 , V_3 , V_8 ) ;
if ( V_71 )
F_14 ( V_71 ) ;
if ( V_8 )
F_14 ( V_8 ) ;
return 0 ;
}
