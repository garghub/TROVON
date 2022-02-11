struct V_1 * * F_1 ( struct V_2 * V_2 , int type )
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
struct V_1 * V_8 = F_4 ( * V_7 ) ;
if ( V_8 ) {
F_5 ( & V_2 -> V_9 ) ;
V_8 = * V_7 ;
if ( V_8 != V_10 )
V_8 = F_6 ( V_8 ) ;
F_7 ( & V_2 -> V_9 ) ;
}
return V_8 ;
}
struct V_1 * F_8 ( struct V_2 * V_2 , int type )
{
return F_9 ( * F_1 ( V_2 , type ) ) ;
}
void F_10 ( struct V_2 * V_2 , int type , struct V_1 * V_8 )
{
struct V_1 * * V_7 = F_1 ( V_2 , type ) ;
struct V_1 * V_11 ;
F_5 ( & V_2 -> V_9 ) ;
V_11 = * V_7 ;
F_11 ( * V_7 , F_6 ( V_8 ) ) ;
F_7 ( & V_2 -> V_9 ) ;
if ( V_11 != V_10 )
F_12 ( V_11 ) ;
}
void F_13 ( struct V_2 * V_2 , int type )
{
struct V_1 * * V_7 = F_1 ( V_2 , type ) ;
struct V_1 * V_11 ;
F_5 ( & V_2 -> V_9 ) ;
V_11 = * V_7 ;
* V_7 = V_10 ;
F_7 ( & V_2 -> V_9 ) ;
if ( V_11 != V_10 )
F_12 ( V_11 ) ;
}
void F_14 ( struct V_2 * V_2 )
{
struct V_1 * V_12 , * V_13 ;
F_5 ( & V_2 -> V_9 ) ;
V_12 = V_2 -> V_4 ;
V_13 = V_2 -> V_6 ;
V_2 -> V_4 = V_2 -> V_6 = V_10 ;
F_7 ( & V_2 -> V_9 ) ;
if ( V_12 != V_10 )
F_12 ( V_12 ) ;
if ( V_13 != V_10 )
F_12 ( V_13 ) ;
}
struct V_1 * F_15 ( struct V_2 * V_2 , int type )
{
struct V_1 * V_8 ;
V_8 = F_3 ( V_2 , type ) ;
if ( V_8 != V_10 )
return V_8 ;
if ( ! F_16 ( V_2 ) )
return NULL ;
if ( ! V_2 -> V_14 -> F_15 ) {
F_10 ( V_2 , type , NULL ) ;
return NULL ;
}
return V_2 -> V_14 -> F_15 ( V_2 , type ) ;
}
void
F_17 ( struct V_1 * V_8 , int V_15 )
{
F_18 ( & V_8 -> V_16 , 1 ) ;
V_8 -> V_17 = V_15 ;
}
struct V_1 *
F_19 ( int V_15 , T_1 V_18 )
{
const T_2 V_19 = sizeof( struct V_1 ) +
V_15 * sizeof( struct V_20 ) ;
struct V_1 * V_8 = F_20 ( V_19 , V_18 ) ;
if ( V_8 )
F_17 ( V_8 , V_15 ) ;
return V_8 ;
}
static struct V_1 *
F_21 ( const struct V_1 * V_8 , T_1 V_18 )
{
struct V_1 * V_21 = NULL ;
if ( V_8 ) {
int V_19 = sizeof( struct V_1 ) + V_8 -> V_17 *
sizeof( struct V_20 ) ;
V_21 = F_22 ( V_8 , V_19 , V_18 ) ;
if ( V_21 )
F_18 ( & V_21 -> V_16 , 1 ) ;
}
return V_21 ;
}
int
F_23 ( const struct V_1 * V_8 )
{
const struct V_20 * V_22 , * V_23 ;
int V_24 = V_25 ;
int V_26 = 0 ;
F_24 (pa, acl, pe) {
if ( V_22 -> V_27 & ~ ( V_28 | V_29 | V_30 ) )
return - V_31 ;
switch ( V_22 -> V_32 ) {
case V_25 :
if ( V_24 == V_25 ) {
V_24 = V_33 ;
break;
}
return - V_31 ;
case V_33 :
if ( V_24 != V_33 )
return - V_31 ;
if ( ! F_25 ( V_22 -> V_34 ) )
return - V_31 ;
V_26 = 1 ;
break;
case V_35 :
if ( V_24 == V_33 ) {
V_24 = V_36 ;
break;
}
return - V_31 ;
case V_36 :
if ( V_24 != V_36 )
return - V_31 ;
if ( ! F_26 ( V_22 -> V_37 ) )
return - V_31 ;
V_26 = 1 ;
break;
case V_38 :
if ( V_24 != V_36 )
return - V_31 ;
V_24 = V_39 ;
break;
case V_39 :
if ( V_24 == V_39 ||
( V_24 == V_36 && ! V_26 ) ) {
V_24 = 0 ;
break;
}
return - V_31 ;
default:
return - V_31 ;
}
}
if ( V_24 == 0 )
return 0 ;
return - V_31 ;
}
int
F_27 ( const struct V_1 * V_8 , T_3 * V_40 )
{
const struct V_20 * V_22 , * V_23 ;
T_3 V_41 = 0 ;
int V_42 = 0 ;
if ( ! V_8 )
return 0 ;
F_24 (pa, acl, pe) {
switch ( V_22 -> V_32 ) {
case V_25 :
V_41 |= ( V_22 -> V_27 & V_43 ) << 6 ;
break;
case V_35 :
V_41 |= ( V_22 -> V_27 & V_43 ) << 3 ;
break;
case V_39 :
V_41 |= V_22 -> V_27 & V_43 ;
break;
case V_38 :
V_41 = ( V_41 & ~ V_44 ) |
( ( V_22 -> V_27 & V_43 ) << 3 ) ;
V_42 = 1 ;
break;
case V_33 :
case V_36 :
V_42 = 1 ;
break;
default:
return - V_31 ;
}
}
if ( V_40 )
* V_40 = ( * V_40 & ~ V_45 ) | V_41 ;
return V_42 ;
}
struct V_1 *
F_28 ( T_3 V_41 , T_1 V_18 )
{
struct V_1 * V_8 = F_19 ( 3 , V_18 ) ;
if ( ! V_8 )
return F_29 ( - V_46 ) ;
V_8 -> V_47 [ 0 ] . V_32 = V_25 ;
V_8 -> V_47 [ 0 ] . V_27 = ( V_41 & V_48 ) >> 6 ;
V_8 -> V_47 [ 1 ] . V_32 = V_35 ;
V_8 -> V_47 [ 1 ] . V_27 = ( V_41 & V_44 ) >> 3 ;
V_8 -> V_47 [ 2 ] . V_32 = V_39 ;
V_8 -> V_47 [ 2 ] . V_27 = ( V_41 & V_43 ) ;
return V_8 ;
}
int
F_30 ( struct V_2 * V_2 , const struct V_1 * V_8 , int V_49 )
{
const struct V_20 * V_22 , * V_23 , * V_50 ;
int V_51 = 0 ;
V_49 &= V_52 | V_53 | V_54 | V_55 ;
F_24 (pa, acl, pe) {
switch( V_22 -> V_32 ) {
case V_25 :
if ( F_31 ( V_2 -> V_56 , F_32 () ) )
goto V_57;
break;
case V_33 :
if ( F_31 ( V_22 -> V_34 , F_32 () ) )
goto V_58;
break;
case V_35 :
if ( F_33 ( V_2 -> V_59 ) ) {
V_51 = 1 ;
if ( ( V_22 -> V_27 & V_49 ) == V_49 )
goto V_58;
}
break;
case V_36 :
if ( F_33 ( V_22 -> V_37 ) ) {
V_51 = 1 ;
if ( ( V_22 -> V_27 & V_49 ) == V_49 )
goto V_58;
}
break;
case V_38 :
break;
case V_39 :
if ( V_51 )
return - V_60 ;
else
goto V_57;
default:
return - V_61 ;
}
}
return - V_61 ;
V_58:
for ( V_50 = V_22 + 1 ; V_50 != V_23 ; V_50 ++ ) {
if ( V_50 -> V_32 == V_38 ) {
if ( ( V_22 -> V_27 & V_50 -> V_27 & V_49 ) == V_49 )
return 0 ;
return - V_60 ;
}
}
V_57:
if ( ( V_22 -> V_27 & V_49 ) == V_49 )
return 0 ;
return - V_60 ;
}
static int F_34 ( struct V_1 * V_8 , T_3 * V_40 )
{
struct V_20 * V_22 , * V_23 ;
struct V_20 * V_62 = NULL , * V_50 = NULL ;
T_3 V_41 = * V_40 ;
int V_42 = 0 ;
F_24 (pa, acl, pe) {
switch( V_22 -> V_32 ) {
case V_25 :
V_22 -> V_27 &= ( V_41 >> 6 ) | ~ V_43 ;
V_41 &= ( V_22 -> V_27 << 6 ) | ~ V_48 ;
break;
case V_33 :
case V_36 :
V_42 = 1 ;
break;
case V_35 :
V_62 = V_22 ;
break;
case V_39 :
V_22 -> V_27 &= V_41 | ~ V_43 ;
V_41 &= V_22 -> V_27 | ~ V_43 ;
break;
case V_38 :
V_50 = V_22 ;
V_42 = 1 ;
break;
default:
return - V_61 ;
}
}
if ( V_50 ) {
V_50 -> V_27 &= ( V_41 >> 3 ) | ~ V_43 ;
V_41 &= ( V_50 -> V_27 << 3 ) | ~ V_44 ;
} else {
if ( ! V_62 )
return - V_61 ;
V_62 -> V_27 &= ( V_41 >> 3 ) | ~ V_43 ;
V_41 &= ( V_62 -> V_27 << 3 ) | ~ V_44 ;
}
* V_40 = ( * V_40 & ~ V_45 ) | V_41 ;
return V_42 ;
}
static int F_35 ( struct V_1 * V_8 , T_3 V_41 )
{
struct V_20 * V_62 = NULL , * V_50 = NULL ;
struct V_20 * V_22 , * V_23 ;
F_24 (pa, acl, pe) {
switch( V_22 -> V_32 ) {
case V_25 :
V_22 -> V_27 = ( V_41 & V_48 ) >> 6 ;
break;
case V_33 :
case V_36 :
break;
case V_35 :
V_62 = V_22 ;
break;
case V_38 :
V_50 = V_22 ;
break;
case V_39 :
V_22 -> V_27 = ( V_41 & V_43 ) ;
break;
default:
return - V_61 ;
}
}
if ( V_50 ) {
V_50 -> V_27 = ( V_41 & V_44 ) >> 3 ;
} else {
if ( ! V_62 )
return - V_61 ;
V_62 -> V_27 = ( V_41 & V_44 ) >> 3 ;
}
return 0 ;
}
int
F_36 ( struct V_1 * * V_8 , T_1 V_63 , T_3 * V_40 )
{
struct V_1 * V_21 = F_21 ( * V_8 , V_63 ) ;
int V_64 = - V_46 ;
if ( V_21 ) {
V_64 = F_34 ( V_21 , V_40 ) ;
if ( V_64 < 0 ) {
F_12 ( V_21 ) ;
V_21 = NULL ;
}
}
F_12 ( * V_8 ) ;
* V_8 = V_21 ;
return V_64 ;
}
int
F_37 ( struct V_1 * * V_8 , T_1 V_63 , T_3 V_41 )
{
struct V_1 * V_21 = F_21 ( * V_8 , V_63 ) ;
int V_64 = - V_46 ;
if ( V_21 ) {
V_64 = F_35 ( V_21 , V_41 ) ;
if ( V_64 ) {
F_12 ( V_21 ) ;
V_21 = NULL ;
}
}
F_12 ( * V_8 ) ;
* V_8 = V_21 ;
return V_64 ;
}
int
F_38 ( struct V_2 * V_2 , T_3 V_41 )
{
struct V_1 * V_8 ;
int V_65 = 0 ;
if ( ! F_16 ( V_2 ) )
return 0 ;
if ( ! V_2 -> V_14 -> V_66 )
return - V_67 ;
V_8 = F_15 ( V_2 , V_3 ) ;
if ( F_39 ( V_8 ) ) {
if ( V_8 == F_29 ( - V_67 ) )
return 0 ;
return F_40 ( V_8 ) ;
}
V_65 = F_37 ( & V_8 , V_68 , V_41 ) ;
if ( V_65 )
return V_65 ;
V_65 = V_2 -> V_14 -> V_66 ( V_2 , V_8 , V_3 ) ;
F_12 ( V_8 ) ;
return V_65 ;
}
int
F_41 ( struct V_2 * V_69 , T_3 * V_41 ,
struct V_1 * * V_70 , struct V_1 * * V_8 )
{
struct V_1 * V_7 ;
int V_65 ;
if ( F_42 ( * V_41 ) || ! F_16 ( V_69 ) )
goto V_71;
V_7 = F_15 ( V_69 , V_5 ) ;
if ( F_43 ( V_7 ) ) {
if ( V_7 == F_29 ( - V_67 ) )
goto V_72;
return F_40 ( V_7 ) ;
}
if ( ! V_7 )
goto V_72;
* V_8 = F_21 ( V_7 , V_73 ) ;
if ( ! * V_8 )
goto V_74;
V_65 = F_34 ( * V_8 , V_41 ) ;
if ( V_65 < 0 )
goto V_75;
if ( V_65 == 0 ) {
F_12 ( * V_8 ) ;
* V_8 = NULL ;
}
if ( ! F_44 ( * V_41 ) ) {
F_12 ( V_7 ) ;
* V_70 = NULL ;
} else {
* V_70 = V_7 ;
}
return 0 ;
V_72:
* V_41 &= ~ F_45 () ;
V_71:
* V_70 = NULL ;
* V_8 = NULL ;
return 0 ;
V_75:
F_12 ( * V_8 ) ;
V_74:
F_12 ( V_7 ) ;
return - V_46 ;
}
static void F_46 (
struct V_76 * V_77 , struct V_76 * V_78 ,
void * V_79 , T_2 V_19 )
{
T_4 * V_80 = ( T_4 * ) V_79 ;
T_5 * V_81 = ( T_5 * ) ( V_80 + 1 ) , * V_82 ;
int V_15 ;
T_6 V_83 ;
T_7 V_84 ;
if ( ! V_79 )
return;
if ( V_19 < sizeof( T_4 ) )
return;
if ( V_80 -> V_85 != F_47 ( V_86 ) )
return;
V_15 = F_48 ( V_19 ) ;
if ( V_15 < 0 )
return;
if ( V_15 == 0 )
return;
for ( V_82 = V_81 + V_15 ; V_81 != V_82 ; V_81 ++ ) {
switch( F_49 ( V_81 -> V_32 ) ) {
case V_33 :
V_83 = F_50 ( V_78 , F_51 ( V_81 -> V_87 ) ) ;
V_81 -> V_87 = F_47 ( F_52 ( V_77 , V_83 ) ) ;
break;
case V_36 :
V_84 = F_53 ( V_78 , F_51 ( V_81 -> V_87 ) ) ;
V_81 -> V_87 = F_47 ( F_54 ( V_77 , V_84 ) ) ;
break;
default:
break;
}
}
}
void F_55 ( void * V_79 , T_2 V_19 )
{
struct V_76 * V_88 = F_56 () ;
if ( V_88 == & V_89 )
return;
F_46 ( & V_89 , V_88 , V_79 , V_19 ) ;
}
void F_57 ( void * V_79 , T_2 V_19 )
{
struct V_76 * V_88 = F_56 () ;
if ( V_88 == & V_89 )
return;
F_46 ( V_88 , & V_89 , V_79 , V_19 ) ;
}
struct V_1 *
F_58 ( struct V_76 * V_88 ,
const void * V_79 , T_2 V_19 )
{
T_4 * V_80 = ( T_4 * ) V_79 ;
T_5 * V_81 = ( T_5 * ) ( V_80 + 1 ) , * V_82 ;
int V_15 ;
struct V_1 * V_8 ;
struct V_20 * V_90 ;
if ( ! V_79 )
return NULL ;
if ( V_19 < sizeof( T_4 ) )
return F_29 ( - V_31 ) ;
if ( V_80 -> V_85 != F_47 ( V_86 ) )
return F_29 ( - V_67 ) ;
V_15 = F_48 ( V_19 ) ;
if ( V_15 < 0 )
return F_29 ( - V_31 ) ;
if ( V_15 == 0 )
return NULL ;
V_8 = F_19 ( V_15 , V_73 ) ;
if ( ! V_8 )
return F_29 ( - V_46 ) ;
V_90 = V_8 -> V_47 ;
for ( V_82 = V_81 + V_15 ; V_81 != V_82 ; V_90 ++ , V_81 ++ ) {
V_90 -> V_32 = F_49 ( V_81 -> V_32 ) ;
V_90 -> V_27 = F_49 ( V_81 -> V_27 ) ;
switch( V_90 -> V_32 ) {
case V_25 :
case V_35 :
case V_38 :
case V_39 :
break;
case V_33 :
V_90 -> V_34 =
F_50 ( V_88 ,
F_51 ( V_81 -> V_87 ) ) ;
if ( ! F_25 ( V_90 -> V_34 ) )
goto V_91;
break;
case V_36 :
V_90 -> V_37 =
F_53 ( V_88 ,
F_51 ( V_81 -> V_87 ) ) ;
if ( ! F_26 ( V_90 -> V_37 ) )
goto V_91;
break;
default:
goto V_91;
}
}
return V_8 ;
V_91:
F_12 ( V_8 ) ;
return F_29 ( - V_31 ) ;
}
int
F_59 ( struct V_76 * V_88 , const struct V_1 * V_8 ,
void * V_92 , T_2 V_19 )
{
T_4 * V_93 = ( T_4 * ) V_92 ;
T_5 * V_94 ;
int V_95 , V_96 ;
V_95 = F_60 ( V_8 -> V_17 ) ;
if ( ! V_92 )
return V_95 ;
if ( V_95 > V_19 )
return - V_97 ;
V_94 = V_93 -> V_47 ;
V_93 -> V_85 = F_47 ( V_86 ) ;
for ( V_96 = 0 ; V_96 < V_8 -> V_17 ; V_96 ++ , V_94 ++ ) {
const struct V_20 * V_90 = & V_8 -> V_47 [ V_96 ] ;
V_94 -> V_32 = F_61 ( V_90 -> V_32 ) ;
V_94 -> V_27 = F_61 ( V_90 -> V_27 ) ;
switch( V_90 -> V_32 ) {
case V_33 :
V_94 -> V_87 =
F_47 ( F_52 ( V_88 , V_90 -> V_34 ) ) ;
break;
case V_36 :
V_94 -> V_87 =
F_47 ( F_54 ( V_88 , V_90 -> V_37 ) ) ;
break;
default:
V_94 -> V_87 = F_47 ( V_98 ) ;
break;
}
}
return V_95 ;
}
static int
F_62 ( struct V_99 * V_99 , const char * V_100 ,
void * V_79 , T_2 V_19 , int type )
{
struct V_1 * V_8 ;
int error ;
if ( ! F_16 ( V_99 -> V_101 ) )
return - V_67 ;
if ( F_63 ( V_99 ) )
return - V_67 ;
V_8 = F_15 ( V_99 -> V_101 , type ) ;
if ( F_43 ( V_8 ) )
return F_40 ( V_8 ) ;
if ( V_8 == NULL )
return - V_102 ;
error = F_59 ( & V_89 , V_8 , V_79 , V_19 ) ;
F_12 ( V_8 ) ;
return error ;
}
static int
F_64 ( struct V_99 * V_99 , const char * V_100 ,
const void * V_79 , T_2 V_19 , int V_18 , int type )
{
struct V_2 * V_2 = V_99 -> V_101 ;
struct V_1 * V_8 = NULL ;
int V_65 ;
if ( ! F_16 ( V_2 ) )
return - V_67 ;
if ( ! V_2 -> V_14 -> V_66 )
return - V_67 ;
if ( type == V_5 && ! F_44 ( V_2 -> V_103 ) )
return V_79 ? - V_60 : 0 ;
if ( ! F_65 ( V_2 ) )
return - V_104 ;
if ( V_79 ) {
V_8 = F_58 ( & V_89 , V_79 , V_19 ) ;
if ( F_43 ( V_8 ) )
return F_40 ( V_8 ) ;
if ( V_8 ) {
V_65 = F_23 ( V_8 ) ;
if ( V_65 )
goto V_105;
}
}
V_65 = V_2 -> V_14 -> V_66 ( V_2 , V_8 , type ) ;
V_105:
F_12 ( V_8 ) ;
return V_65 ;
}
static T_2
F_66 ( struct V_99 * V_99 , char * V_106 , T_2 V_107 ,
const char * V_100 , T_2 V_108 , int type )
{
const char * V_109 ;
T_2 V_19 ;
if ( ! F_16 ( V_99 -> V_101 ) )
return - V_67 ;
if ( F_63 ( V_99 ) )
return - V_67 ;
if ( type == V_3 )
V_109 = V_110 ;
else
V_109 = V_111 ;
V_19 = strlen ( V_109 ) + 1 ;
if ( V_106 && V_19 <= V_107 )
memcpy ( V_106 , V_109 , V_19 ) ;
return V_19 ;
}
int F_67 ( struct V_2 * V_2 , struct V_1 * V_8 , int type )
{
int error ;
if ( type == V_3 ) {
error = F_27 ( V_8 , & V_2 -> V_103 ) ;
if ( error < 0 )
return 0 ;
if ( error == 0 )
V_8 = NULL ;
}
V_2 -> V_112 = V_113 ;
F_10 ( V_2 , type , V_8 ) ;
return 0 ;
}
int F_68 ( struct V_2 * V_69 , struct V_2 * V_2 )
{
struct V_1 * V_70 , * V_8 ;
int error ;
error = F_41 ( V_69 , & V_2 -> V_103 , & V_70 , & V_8 ) ;
if ( error )
return error ;
F_10 ( V_2 , V_5 , V_70 ) ;
F_10 ( V_2 , V_3 , V_8 ) ;
if ( V_70 )
F_12 ( V_70 ) ;
if ( V_8 )
F_12 ( V_8 ) ;
return 0 ;
}
