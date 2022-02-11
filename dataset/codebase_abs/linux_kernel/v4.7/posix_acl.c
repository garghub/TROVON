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
F_30 ( const struct V_1 * V_8 )
{
const struct V_19 * V_21 , * V_22 ;
int V_23 = V_24 ;
int V_25 = 0 ;
F_31 (pa, acl, pe) {
if ( V_21 -> V_26 & ~ ( V_27 | V_28 | V_29 ) )
return - V_30 ;
switch ( V_21 -> V_31 ) {
case V_24 :
if ( V_23 == V_24 ) {
V_23 = V_32 ;
break;
}
return - V_30 ;
case V_32 :
if ( V_23 != V_32 )
return - V_30 ;
if ( ! F_32 ( V_21 -> V_33 ) )
return - V_30 ;
V_25 = 1 ;
break;
case V_34 :
if ( V_23 == V_32 ) {
V_23 = V_35 ;
break;
}
return - V_30 ;
case V_35 :
if ( V_23 != V_35 )
return - V_30 ;
if ( ! F_33 ( V_21 -> V_36 ) )
return - V_30 ;
V_25 = 1 ;
break;
case V_37 :
if ( V_23 != V_35 )
return - V_30 ;
V_23 = V_38 ;
break;
case V_38 :
if ( V_23 == V_38 ||
( V_23 == V_35 && ! V_25 ) ) {
V_23 = 0 ;
break;
}
return - V_30 ;
default:
return - V_30 ;
}
}
if ( V_23 == 0 )
return 0 ;
return - V_30 ;
}
int
F_34 ( const struct V_1 * V_8 , T_3 * V_39 )
{
const struct V_19 * V_21 , * V_22 ;
T_3 V_40 = 0 ;
int V_41 = 0 ;
if ( ! V_8 )
return 0 ;
F_31 (pa, acl, pe) {
switch ( V_21 -> V_31 ) {
case V_24 :
V_40 |= ( V_21 -> V_26 & V_42 ) << 6 ;
break;
case V_34 :
V_40 |= ( V_21 -> V_26 & V_42 ) << 3 ;
break;
case V_38 :
V_40 |= V_21 -> V_26 & V_42 ;
break;
case V_37 :
V_40 = ( V_40 & ~ V_43 ) |
( ( V_21 -> V_26 & V_42 ) << 3 ) ;
V_41 = 1 ;
break;
case V_32 :
case V_35 :
V_41 = 1 ;
break;
default:
return - V_30 ;
}
}
if ( V_39 )
* V_39 = ( * V_39 & ~ V_44 ) | V_40 ;
return V_41 ;
}
struct V_1 *
F_35 ( T_3 V_40 , T_1 V_17 )
{
struct V_1 * V_8 = F_26 ( 3 , V_17 ) ;
if ( ! V_8 )
return F_36 ( - V_45 ) ;
V_8 -> V_46 [ 0 ] . V_31 = V_24 ;
V_8 -> V_46 [ 0 ] . V_26 = ( V_40 & V_47 ) >> 6 ;
V_8 -> V_46 [ 1 ] . V_31 = V_34 ;
V_8 -> V_46 [ 1 ] . V_26 = ( V_40 & V_43 ) >> 3 ;
V_8 -> V_46 [ 2 ] . V_31 = V_38 ;
V_8 -> V_46 [ 2 ] . V_26 = ( V_40 & V_42 ) ;
return V_8 ;
}
int
F_37 ( struct V_2 * V_2 , const struct V_1 * V_8 , int V_48 )
{
const struct V_19 * V_21 , * V_22 , * V_49 ;
int V_50 = 0 ;
V_48 &= V_51 | V_52 | V_53 | V_54 ;
F_31 (pa, acl, pe) {
switch( V_21 -> V_31 ) {
case V_24 :
if ( F_38 ( V_2 -> V_55 , F_39 () ) )
goto V_56;
break;
case V_32 :
if ( F_38 ( V_21 -> V_33 , F_39 () ) )
goto V_57;
break;
case V_34 :
if ( F_40 ( V_2 -> V_58 ) ) {
V_50 = 1 ;
if ( ( V_21 -> V_26 & V_48 ) == V_48 )
goto V_57;
}
break;
case V_35 :
if ( F_40 ( V_21 -> V_36 ) ) {
V_50 = 1 ;
if ( ( V_21 -> V_26 & V_48 ) == V_48 )
goto V_57;
}
break;
case V_37 :
break;
case V_38 :
if ( V_50 )
return - V_59 ;
else
goto V_56;
default:
return - V_60 ;
}
}
return - V_60 ;
V_57:
for ( V_49 = V_21 + 1 ; V_49 != V_22 ; V_49 ++ ) {
if ( V_49 -> V_31 == V_37 ) {
if ( ( V_21 -> V_26 & V_49 -> V_26 & V_48 ) == V_48 )
return 0 ;
return - V_59 ;
}
}
V_56:
if ( ( V_21 -> V_26 & V_48 ) == V_48 )
return 0 ;
return - V_59 ;
}
static int F_41 ( struct V_1 * V_8 , T_3 * V_39 )
{
struct V_19 * V_21 , * V_22 ;
struct V_19 * V_61 = NULL , * V_49 = NULL ;
T_3 V_40 = * V_39 ;
int V_41 = 0 ;
F_31 (pa, acl, pe) {
switch( V_21 -> V_31 ) {
case V_24 :
V_21 -> V_26 &= ( V_40 >> 6 ) | ~ V_42 ;
V_40 &= ( V_21 -> V_26 << 6 ) | ~ V_47 ;
break;
case V_32 :
case V_35 :
V_41 = 1 ;
break;
case V_34 :
V_61 = V_21 ;
break;
case V_38 :
V_21 -> V_26 &= V_40 | ~ V_42 ;
V_40 &= V_21 -> V_26 | ~ V_42 ;
break;
case V_37 :
V_49 = V_21 ;
V_41 = 1 ;
break;
default:
return - V_60 ;
}
}
if ( V_49 ) {
V_49 -> V_26 &= ( V_40 >> 3 ) | ~ V_42 ;
V_40 &= ( V_49 -> V_26 << 3 ) | ~ V_43 ;
} else {
if ( ! V_61 )
return - V_60 ;
V_61 -> V_26 &= ( V_40 >> 3 ) | ~ V_42 ;
V_40 &= ( V_61 -> V_26 << 3 ) | ~ V_43 ;
}
* V_39 = ( * V_39 & ~ V_44 ) | V_40 ;
return V_41 ;
}
static int F_42 ( struct V_1 * V_8 , T_3 V_40 )
{
struct V_19 * V_61 = NULL , * V_49 = NULL ;
struct V_19 * V_21 , * V_22 ;
F_31 (pa, acl, pe) {
switch( V_21 -> V_31 ) {
case V_24 :
V_21 -> V_26 = ( V_40 & V_47 ) >> 6 ;
break;
case V_32 :
case V_35 :
break;
case V_34 :
V_61 = V_21 ;
break;
case V_37 :
V_49 = V_21 ;
break;
case V_38 :
V_21 -> V_26 = ( V_40 & V_42 ) ;
break;
default:
return - V_60 ;
}
}
if ( V_49 ) {
V_49 -> V_26 = ( V_40 & V_43 ) >> 3 ;
} else {
if ( ! V_61 )
return - V_60 ;
V_61 -> V_26 = ( V_40 & V_43 ) >> 3 ;
}
return 0 ;
}
int
F_43 ( struct V_1 * * V_8 , T_1 V_62 , T_3 * V_39 )
{
struct V_1 * V_20 = F_28 ( * V_8 , V_62 ) ;
int V_63 = - V_45 ;
if ( V_20 ) {
V_63 = F_41 ( V_20 , V_39 ) ;
if ( V_63 < 0 ) {
F_14 ( V_20 ) ;
V_20 = NULL ;
}
}
F_14 ( * V_8 ) ;
* V_8 = V_20 ;
return V_63 ;
}
int
F_44 ( struct V_1 * * V_8 , T_1 V_62 , T_3 V_40 )
{
struct V_1 * V_20 = F_28 ( * V_8 , V_62 ) ;
int V_63 = - V_45 ;
if ( V_20 ) {
V_63 = F_42 ( V_20 , V_40 ) ;
if ( V_63 ) {
F_14 ( V_20 ) ;
V_20 = NULL ;
}
}
F_14 ( * V_8 ) ;
* V_8 = V_20 ;
return V_63 ;
}
int
F_45 ( struct V_2 * V_2 , T_3 V_40 )
{
struct V_1 * V_8 ;
int V_64 = 0 ;
if ( ! F_19 ( V_2 ) )
return 0 ;
if ( ! V_2 -> V_14 -> V_65 )
return - V_66 ;
V_8 = F_18 ( V_2 , V_3 ) ;
if ( F_46 ( V_8 ) ) {
if ( V_8 == F_36 ( - V_66 ) )
return 0 ;
return F_47 ( V_8 ) ;
}
V_64 = F_44 ( & V_8 , V_67 , V_40 ) ;
if ( V_64 )
return V_64 ;
V_64 = V_2 -> V_14 -> V_65 ( V_2 , V_8 , V_3 ) ;
F_14 ( V_8 ) ;
return V_64 ;
}
int
F_48 ( struct V_2 * V_68 , T_3 * V_40 ,
struct V_1 * * V_69 , struct V_1 * * V_8 )
{
struct V_1 * V_7 ;
struct V_1 * V_20 ;
int V_64 ;
* V_8 = NULL ;
* V_69 = NULL ;
if ( F_49 ( * V_40 ) || ! F_19 ( V_68 ) )
return 0 ;
V_7 = F_18 ( V_68 , V_5 ) ;
if ( ! V_7 || V_7 == F_36 ( - V_66 ) ) {
* V_40 &= ~ F_50 () ;
return 0 ;
}
if ( F_22 ( V_7 ) )
return F_47 ( V_7 ) ;
V_20 = F_28 ( V_7 , V_70 ) ;
if ( ! V_20 )
goto V_71;
V_64 = F_41 ( V_20 , V_40 ) ;
if ( V_64 < 0 )
goto V_72;
if ( V_64 == 0 )
F_14 ( V_20 ) ;
else
* V_8 = V_20 ;
if ( ! F_51 ( * V_40 ) )
F_14 ( V_7 ) ;
else
* V_69 = V_7 ;
return 0 ;
V_72:
F_14 ( V_20 ) ;
V_71:
F_14 ( V_7 ) ;
return - V_45 ;
}
static void F_52 (
struct V_73 * V_74 , struct V_73 * V_75 ,
void * V_76 , T_2 V_18 )
{
T_4 * V_77 = ( T_4 * ) V_76 ;
T_5 * V_78 = ( T_5 * ) ( V_77 + 1 ) , * V_79 ;
int V_15 ;
T_6 V_80 ;
T_7 V_81 ;
if ( ! V_76 )
return;
if ( V_18 < sizeof( T_4 ) )
return;
if ( V_77 -> V_82 != F_53 ( V_83 ) )
return;
V_15 = F_54 ( V_18 ) ;
if ( V_15 < 0 )
return;
if ( V_15 == 0 )
return;
for ( V_79 = V_78 + V_15 ; V_78 != V_79 ; V_78 ++ ) {
switch( F_55 ( V_78 -> V_31 ) ) {
case V_32 :
V_80 = F_56 ( V_75 , F_57 ( V_78 -> V_84 ) ) ;
V_78 -> V_84 = F_53 ( F_58 ( V_74 , V_80 ) ) ;
break;
case V_35 :
V_81 = F_59 ( V_75 , F_57 ( V_78 -> V_84 ) ) ;
V_78 -> V_84 = F_53 ( F_60 ( V_74 , V_81 ) ) ;
break;
default:
break;
}
}
}
void F_61 ( void * V_76 , T_2 V_18 )
{
struct V_73 * V_85 = F_62 () ;
if ( V_85 == & V_86 )
return;
F_52 ( & V_86 , V_85 , V_76 , V_18 ) ;
}
void F_63 ( void * V_76 , T_2 V_18 )
{
struct V_73 * V_85 = F_62 () ;
if ( V_85 == & V_86 )
return;
F_52 ( V_85 , & V_86 , V_76 , V_18 ) ;
}
struct V_1 *
F_64 ( struct V_73 * V_85 ,
const void * V_76 , T_2 V_18 )
{
T_4 * V_77 = ( T_4 * ) V_76 ;
T_5 * V_78 = ( T_5 * ) ( V_77 + 1 ) , * V_79 ;
int V_15 ;
struct V_1 * V_8 ;
struct V_19 * V_87 ;
if ( ! V_76 )
return NULL ;
if ( V_18 < sizeof( T_4 ) )
return F_36 ( - V_30 ) ;
if ( V_77 -> V_82 != F_53 ( V_83 ) )
return F_36 ( - V_66 ) ;
V_15 = F_54 ( V_18 ) ;
if ( V_15 < 0 )
return F_36 ( - V_30 ) ;
if ( V_15 == 0 )
return NULL ;
V_8 = F_26 ( V_15 , V_70 ) ;
if ( ! V_8 )
return F_36 ( - V_45 ) ;
V_87 = V_8 -> V_46 ;
for ( V_79 = V_78 + V_15 ; V_78 != V_79 ; V_87 ++ , V_78 ++ ) {
V_87 -> V_31 = F_55 ( V_78 -> V_31 ) ;
V_87 -> V_26 = F_55 ( V_78 -> V_26 ) ;
switch( V_87 -> V_31 ) {
case V_24 :
case V_34 :
case V_37 :
case V_38 :
break;
case V_32 :
V_87 -> V_33 =
F_56 ( V_85 ,
F_57 ( V_78 -> V_84 ) ) ;
if ( ! F_32 ( V_87 -> V_33 ) )
goto V_88;
break;
case V_35 :
V_87 -> V_36 =
F_59 ( V_85 ,
F_57 ( V_78 -> V_84 ) ) ;
if ( ! F_33 ( V_87 -> V_36 ) )
goto V_88;
break;
default:
goto V_88;
}
}
return V_8 ;
V_88:
F_14 ( V_8 ) ;
return F_36 ( - V_30 ) ;
}
int
F_65 ( struct V_73 * V_85 , const struct V_1 * V_8 ,
void * V_89 , T_2 V_18 )
{
T_4 * V_90 = ( T_4 * ) V_89 ;
T_5 * V_91 ;
int V_92 , V_93 ;
V_92 = F_66 ( V_8 -> V_16 ) ;
if ( ! V_89 )
return V_92 ;
if ( V_92 > V_18 )
return - V_94 ;
V_91 = V_90 -> V_46 ;
V_90 -> V_82 = F_53 ( V_83 ) ;
for ( V_93 = 0 ; V_93 < V_8 -> V_16 ; V_93 ++ , V_91 ++ ) {
const struct V_19 * V_87 = & V_8 -> V_46 [ V_93 ] ;
V_91 -> V_31 = F_67 ( V_87 -> V_31 ) ;
V_91 -> V_26 = F_67 ( V_87 -> V_26 ) ;
switch( V_87 -> V_31 ) {
case V_32 :
V_91 -> V_84 =
F_53 ( F_58 ( V_85 , V_87 -> V_33 ) ) ;
break;
case V_35 :
V_91 -> V_84 =
F_53 ( F_60 ( V_85 , V_87 -> V_36 ) ) ;
break;
default:
V_91 -> V_84 = F_53 ( V_95 ) ;
break;
}
}
return V_92 ;
}
static int
F_68 ( const struct V_96 * V_97 ,
struct V_98 * V_99 , struct V_2 * V_2 ,
const char * V_100 , void * V_76 , T_2 V_18 )
{
struct V_1 * V_8 ;
int error ;
if ( ! F_19 ( V_2 ) )
return - V_66 ;
if ( F_49 ( V_2 -> V_101 ) )
return - V_66 ;
V_8 = F_18 ( V_2 , V_97 -> V_17 ) ;
if ( F_22 ( V_8 ) )
return F_47 ( V_8 ) ;
if ( V_8 == NULL )
return - V_102 ;
error = F_65 ( & V_86 , V_8 , V_76 , V_18 ) ;
F_14 ( V_8 ) ;
return error ;
}
int
F_69 ( struct V_2 * V_2 , int type , struct V_1 * V_8 )
{
if ( ! F_19 ( V_2 ) )
return - V_66 ;
if ( ! V_2 -> V_14 -> V_65 )
return - V_66 ;
if ( type == V_5 && ! F_51 ( V_2 -> V_101 ) )
return V_8 ? - V_59 : 0 ;
if ( ! F_70 ( V_2 ) )
return - V_103 ;
if ( V_8 ) {
int V_64 = F_30 ( V_8 ) ;
if ( V_64 )
return V_64 ;
}
return V_2 -> V_14 -> V_65 ( V_2 , V_8 , type ) ;
}
static int
F_71 ( const struct V_96 * V_97 ,
struct V_98 * V_99 , struct V_2 * V_2 ,
const char * V_100 , const void * V_76 ,
T_2 V_18 , int V_17 )
{
struct V_1 * V_8 = NULL ;
int V_64 ;
if ( V_76 ) {
V_8 = F_64 ( & V_86 , V_76 , V_18 ) ;
if ( F_22 ( V_8 ) )
return F_47 ( V_8 ) ;
}
V_64 = F_69 ( V_2 , V_97 -> V_17 , V_8 ) ;
F_14 ( V_8 ) ;
return V_64 ;
}
static bool
F_72 ( struct V_98 * V_98 )
{
return F_19 ( F_73 ( V_98 ) ) ;
}
int F_74 ( struct V_2 * V_2 , struct V_1 * V_8 , int type )
{
int error ;
if ( type == V_3 ) {
error = F_34 ( V_8 , & V_2 -> V_101 ) ;
if ( error < 0 )
return 0 ;
if ( error == 0 )
V_8 = NULL ;
}
V_2 -> V_104 = V_105 ;
F_11 ( V_2 , type , V_8 ) ;
return 0 ;
}
int F_75 ( struct V_2 * V_68 , struct V_2 * V_2 )
{
struct V_1 * V_69 , * V_8 ;
int error ;
error = F_48 ( V_68 , & V_2 -> V_101 , & V_69 , & V_8 ) ;
if ( error )
return error ;
F_11 ( V_2 , V_5 , V_69 ) ;
F_11 ( V_2 , V_3 , V_8 ) ;
if ( V_69 )
F_14 ( V_69 ) ;
if ( V_8 )
F_14 ( V_8 ) ;
return 0 ;
}
