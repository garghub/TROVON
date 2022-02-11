static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_5 * V_7 ;
#if F_2 ( V_8 )
struct V_9 * V_10 ;
struct V_9 * V_11 ;
#endif
V_4 = F_3 ( V_2 , struct V_3 , V_12 ) ;
F_4 (iter4, tmp4, &iface->addr4_list) {
F_5 ( V_6 ) ;
F_6 ( F_7 ( V_6 ) ) ;
}
#if F_2 ( V_8 )
F_8 (iter6, tmp6, &iface->addr6_list) {
F_9 ( V_10 ) ;
F_6 ( F_10 ( V_10 ) ) ;
}
#endif
F_6 ( V_4 ) ;
}
static T_1 F_11 ( int V_13 )
{
return V_13 & ( F_12 ( V_14 ) -> V_15 - 1 ) ;
}
static struct V_3 * F_13 ( int V_13 )
{
T_1 V_16 ;
struct V_17 * V_18 ;
struct V_3 * V_19 ;
V_16 = F_11 ( V_13 ) ;
V_18 = & F_12 ( V_14 ) -> V_20 [ V_16 ] ;
F_14 (iter, bkt_list, list)
if ( V_19 -> V_21 && V_19 -> V_13 == V_13 )
return V_19 ;
return NULL ;
}
static int F_15 ( struct V_3 * V_4 ,
const struct V_22 * V_23 ,
const struct V_22 * V_24 ,
T_1 V_25 )
{
int V_26 ;
struct V_27 * V_2 ;
V_2 = F_16 ( sizeof( * V_2 ) , V_28 ) ;
if ( V_2 == NULL )
return - V_29 ;
V_2 -> V_30 . V_23 = V_23 -> V_31 & V_24 -> V_31 ;
V_2 -> V_30 . V_24 = V_24 -> V_31 ;
V_2 -> V_30 . V_21 = 1 ;
V_2 -> V_25 = V_25 ;
F_17 ( & V_32 ) ;
V_26 = F_18 ( & V_2 -> V_30 , & V_4 -> V_33 ) ;
F_19 ( & V_32 ) ;
if ( V_26 != 0 )
F_6 ( V_2 ) ;
return V_26 ;
}
static int F_20 ( struct V_3 * V_4 ,
const struct V_34 * V_23 ,
const struct V_34 * V_24 ,
T_1 V_25 )
{
int V_26 ;
struct V_35 * V_2 ;
V_2 = F_16 ( sizeof( * V_2 ) , V_28 ) ;
if ( V_2 == NULL )
return - V_29 ;
V_2 -> V_30 . V_23 = * V_23 ;
V_2 -> V_30 . V_23 . V_36 [ 0 ] &= V_24 -> V_36 [ 0 ] ;
V_2 -> V_30 . V_23 . V_36 [ 1 ] &= V_24 -> V_36 [ 1 ] ;
V_2 -> V_30 . V_23 . V_36 [ 2 ] &= V_24 -> V_36 [ 2 ] ;
V_2 -> V_30 . V_23 . V_36 [ 3 ] &= V_24 -> V_36 [ 3 ] ;
V_2 -> V_30 . V_24 = * V_24 ;
V_2 -> V_30 . V_21 = 1 ;
V_2 -> V_25 = V_25 ;
F_17 ( & V_32 ) ;
V_26 = F_21 ( & V_2 -> V_30 , & V_4 -> V_37 ) ;
F_19 ( & V_32 ) ;
if ( V_26 != 0 )
F_6 ( V_2 ) ;
return 0 ;
}
static struct V_3 * F_22 ( int V_13 )
{
T_1 V_16 ;
struct V_3 * V_4 ;
V_4 = F_16 ( sizeof( * V_4 ) , V_28 ) ;
if ( V_4 == NULL )
return NULL ;
V_4 -> V_13 = V_13 ;
F_23 ( & V_4 -> V_33 ) ;
F_23 ( & V_4 -> V_37 ) ;
V_4 -> V_21 = 1 ;
F_17 ( & V_32 ) ;
if ( V_13 > 0 ) {
V_16 = F_11 ( V_13 ) ;
if ( F_13 ( V_13 ) != NULL )
goto V_38;
F_24 ( & V_4 -> V_30 ,
& F_12 ( V_14 ) -> V_20 [ V_16 ] ) ;
} else {
F_23 ( & V_4 -> V_30 ) ;
if ( F_12 ( V_39 ) != NULL )
goto V_38;
F_25 ( V_39 , V_4 ) ;
}
F_19 ( & V_32 ) ;
return V_4 ;
V_38:
F_19 ( & V_32 ) ;
F_6 ( V_4 ) ;
return NULL ;
}
int F_26 ( struct V_40 * V_40 ,
const char * V_41 ,
const void * V_23 ,
const void * V_24 ,
T_1 V_42 ,
T_1 V_25 ,
struct V_43 * V_44 )
{
int V_26 ;
int V_13 ;
struct V_45 * V_46 ;
struct V_3 * V_4 ;
struct V_47 * V_48 = NULL ;
char * V_49 = NULL ;
T_1 V_50 ;
if ( V_42 != sizeof( struct V_22 ) &&
V_42 != sizeof( struct V_34 ) )
return - V_51 ;
F_27 () ;
if ( V_41 != NULL ) {
V_46 = F_28 ( V_40 , V_41 ) ;
if ( V_46 == NULL ) {
V_26 = - V_52 ;
goto V_53;
}
V_13 = V_46 -> V_13 ;
V_4 = F_13 ( V_13 ) ;
} else {
V_13 = 0 ;
V_4 = F_29 ( V_39 ) ;
}
if ( V_4 == NULL ) {
V_4 = F_22 ( V_13 ) ;
if ( V_4 == NULL ) {
V_26 = - V_29 ;
goto V_53;
}
}
V_48 = F_30 ( V_54 ,
V_44 ) ;
switch ( V_42 ) {
case sizeof( struct V_22 ) : {
const struct V_22 * V_55 = V_23 ;
const struct V_22 * V_56 = V_24 ;
V_26 = F_15 ( V_4 , V_55 , V_56 , V_25 ) ;
if ( V_48 != NULL )
F_31 ( V_48 , 1 ,
V_41 ,
V_55 -> V_31 ,
V_56 -> V_31 ) ;
break;
}
#if F_2 ( V_8 )
case sizeof( struct V_34 ) : {
const struct V_34 * V_57 = V_23 ;
const struct V_34 * V_58 = V_24 ;
V_26 = F_20 ( V_4 , V_57 , V_58 , V_25 ) ;
if ( V_48 != NULL )
F_32 ( V_48 , 1 ,
V_41 ,
V_57 , V_58 ) ;
break;
}
#endif
default:
V_26 = - V_51 ;
}
if ( V_26 == 0 )
F_33 ( & V_59 ) ;
V_53:
F_34 () ;
if ( V_48 != NULL ) {
if ( F_35 ( V_25 ,
& V_49 ,
& V_50 ) == 0 ) {
F_36 ( V_48 , L_1 , V_49 ) ;
F_37 ( V_49 , V_50 ) ;
}
F_36 ( V_48 , L_2 , V_26 == 0 ? 1 : 0 ) ;
F_38 ( V_48 ) ;
}
return V_26 ;
}
static int F_39 ( struct V_40 * V_40 ,
struct V_3 * V_4 ,
const struct V_22 * V_23 ,
const struct V_22 * V_24 ,
struct V_43 * V_44 )
{
struct V_5 * V_60 ;
struct V_27 * V_2 ;
struct V_47 * V_48 ;
struct V_45 * V_46 ;
char * V_49 ;
T_1 V_50 ;
F_17 ( & V_32 ) ;
V_60 = F_40 ( V_23 -> V_31 , V_24 -> V_31 ,
& V_4 -> V_33 ) ;
F_19 ( & V_32 ) ;
if ( V_60 != NULL )
V_2 = F_7 ( V_60 ) ;
else
V_2 = NULL ;
V_48 = F_30 ( V_61 ,
V_44 ) ;
if ( V_48 != NULL ) {
V_46 = F_41 ( V_40 , V_4 -> V_13 ) ;
F_31 ( V_48 , 1 ,
( V_46 != NULL ? V_46 -> V_62 : NULL ) ,
V_23 -> V_31 , V_24 -> V_31 ) ;
if ( V_46 != NULL )
F_42 ( V_46 ) ;
if ( V_2 != NULL &&
F_35 ( V_2 -> V_25 ,
& V_49 , & V_50 ) == 0 ) {
F_36 ( V_48 , L_1 , V_49 ) ;
F_37 ( V_49 , V_50 ) ;
}
F_36 ( V_48 , L_2 , V_2 != NULL ? 1 : 0 ) ;
F_38 ( V_48 ) ;
}
if ( V_2 == NULL )
return - V_63 ;
F_43 ( V_2 , V_12 ) ;
return 0 ;
}
static int F_44 ( struct V_40 * V_40 ,
struct V_3 * V_4 ,
const struct V_34 * V_23 ,
const struct V_34 * V_24 ,
struct V_43 * V_44 )
{
struct V_9 * V_60 ;
struct V_35 * V_2 ;
struct V_47 * V_48 ;
struct V_45 * V_46 ;
char * V_49 ;
T_1 V_50 ;
F_17 ( & V_32 ) ;
V_60 = F_45 ( V_23 , V_24 , & V_4 -> V_37 ) ;
F_19 ( & V_32 ) ;
if ( V_60 != NULL )
V_2 = F_10 ( V_60 ) ;
else
V_2 = NULL ;
V_48 = F_30 ( V_61 ,
V_44 ) ;
if ( V_48 != NULL ) {
V_46 = F_41 ( V_40 , V_4 -> V_13 ) ;
F_32 ( V_48 , 1 ,
( V_46 != NULL ? V_46 -> V_62 : NULL ) ,
V_23 , V_24 ) ;
if ( V_46 != NULL )
F_42 ( V_46 ) ;
if ( V_2 != NULL &&
F_35 ( V_2 -> V_25 ,
& V_49 , & V_50 ) == 0 ) {
F_36 ( V_48 , L_1 , V_49 ) ;
F_37 ( V_49 , V_50 ) ;
}
F_36 ( V_48 , L_2 , V_2 != NULL ? 1 : 0 ) ;
F_38 ( V_48 ) ;
}
if ( V_2 == NULL )
return - V_63 ;
F_43 ( V_2 , V_12 ) ;
return 0 ;
}
static void F_46 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
#if F_2 ( V_8 )
struct V_9 * V_10 ;
#endif
F_17 ( & V_32 ) ;
F_47 (iter4, &iface->addr4_list)
goto V_64;
#if F_2 ( V_8 )
F_48 (iter6, &iface->addr6_list)
goto V_64;
#endif
V_4 -> V_21 = 0 ;
if ( V_4 -> V_13 > 0 )
F_49 ( & V_4 -> V_30 ) ;
else
F_50 ( V_39 , NULL ) ;
F_19 ( & V_32 ) ;
F_51 ( & V_4 -> V_12 , F_1 ) ;
return;
V_64:
F_19 ( & V_32 ) ;
}
int F_52 ( struct V_40 * V_40 ,
const char * V_41 ,
const void * V_23 ,
const void * V_24 ,
T_1 V_42 ,
struct V_43 * V_44 )
{
int V_26 ;
struct V_45 * V_46 ;
struct V_3 * V_4 ;
if ( V_42 != sizeof( struct V_22 ) &&
V_42 != sizeof( struct V_34 ) )
return - V_51 ;
F_27 () ;
if ( V_41 != NULL ) {
V_46 = F_28 ( V_40 , V_41 ) ;
if ( V_46 == NULL ) {
V_26 = - V_52 ;
goto V_65;
}
V_4 = F_13 ( V_46 -> V_13 ) ;
} else
V_4 = F_29 ( V_39 ) ;
if ( V_4 == NULL ) {
V_26 = - V_63 ;
goto V_65;
}
switch ( V_42 ) {
case sizeof( struct V_22 ) :
V_26 = F_39 ( V_40 ,
V_4 , V_23 , V_24 ,
V_44 ) ;
break;
#if F_2 ( V_8 )
case sizeof( struct V_34 ) :
V_26 = F_44 ( V_40 ,
V_4 , V_23 , V_24 ,
V_44 ) ;
break;
#endif
default:
V_26 = - V_51 ;
}
if ( V_26 == 0 ) {
F_46 ( V_4 ) ;
F_53 ( & V_59 ) ;
}
V_65:
F_34 () ;
return V_26 ;
}
static int F_54 ( struct V_66 * V_67 ,
unsigned long V_68 , void * V_69 )
{
struct V_45 * V_46 = F_55 ( V_69 ) ;
struct V_3 * V_4 = NULL ;
if ( ! F_56 ( F_57 ( V_46 ) , & V_70 ) )
return V_71 ;
if ( V_68 == V_72 ) {
F_17 ( & V_32 ) ;
V_4 = F_13 ( V_46 -> V_13 ) ;
if ( V_4 != NULL && V_4 -> V_21 ) {
V_4 -> V_21 = 0 ;
F_49 ( & V_4 -> V_30 ) ;
} else
V_4 = NULL ;
F_19 ( & V_32 ) ;
}
if ( V_4 != NULL )
F_51 ( & V_4 -> V_12 , F_1 ) ;
return V_71 ;
}
static void F_58 ( T_2 V_73 ,
struct V_43 * V_44 )
{
struct V_47 * V_48 ;
T_2 V_74 ;
V_74 = V_75 ;
V_75 = V_73 ;
V_48 = F_30 ( V_76 ,
V_44 ) ;
if ( V_48 != NULL ) {
F_36 ( V_48 ,
L_3 , V_73 , V_74 ) ;
F_38 ( V_48 ) ;
}
}
static int F_59 ( struct V_77 * V_78 ,
void * * V_23 ,
void * * V_24 ,
T_1 * V_79 )
{
T_1 V_42 ;
if ( V_78 -> V_80 [ V_81 ] ) {
V_42 = F_60 ( V_78 -> V_80 [ V_81 ] ) ;
if ( V_42 != sizeof( struct V_22 ) &&
V_42 != F_60 ( V_78 -> V_80 [ V_82 ] ) )
return - V_51 ;
* V_79 = V_42 ;
* V_23 = F_61 ( V_78 -> V_80 [ V_81 ] ) ;
* V_24 = F_61 ( V_78 -> V_80 [ V_82 ] ) ;
return 0 ;
} else if ( V_78 -> V_80 [ V_83 ] ) {
V_42 = F_60 ( V_78 -> V_80 [ V_83 ] ) ;
if ( V_42 != sizeof( struct V_34 ) &&
V_42 != F_60 ( V_78 -> V_80 [ V_84 ] ) )
return - V_51 ;
* V_79 = V_42 ;
* V_23 = F_61 ( V_78 -> V_80 [ V_83 ] ) ;
* V_24 = F_61 ( V_78 -> V_80 [ V_84 ] ) ;
return 0 ;
}
return - V_51 ;
}
static int F_62 ( struct V_85 * V_86 , struct V_77 * V_78 )
{
T_2 V_73 ;
struct V_43 V_44 ;
if ( V_78 -> V_80 [ V_87 ] ) {
V_73 = F_63 ( V_78 -> V_80 [ V_87 ] ) ;
if ( V_73 == 1 || V_73 == 0 ) {
F_64 ( V_86 , & V_44 ) ;
F_58 ( V_73 , & V_44 ) ;
return 0 ;
}
}
return - V_51 ;
}
static int F_65 ( struct V_85 * V_86 , struct V_77 * V_78 )
{
int V_26 = - V_51 ;
struct V_85 * V_88 ;
void * V_89 ;
V_88 = F_66 ( V_90 , V_91 ) ;
if ( V_88 == NULL )
goto V_92;
V_89 = F_67 ( V_88 , V_78 , & V_93 ,
0 , V_94 ) ;
if ( V_89 == NULL ) {
V_26 = - V_29 ;
goto V_92;
}
V_26 = F_68 ( V_88 ,
V_87 ,
V_75 ) ;
if ( V_26 != 0 )
goto V_92;
F_69 ( V_88 , V_89 ) ;
return F_70 ( V_88 , V_78 ) ;
V_92:
F_71 ( V_88 ) ;
return V_26 ;
}
static int F_72 ( struct V_85 * V_86 ,
struct V_77 * V_78 )
{
int V_26 ;
char * V_41 ;
void * V_23 ;
void * V_24 ;
T_1 V_42 ;
T_1 V_25 ;
struct V_43 V_44 ;
if ( ! V_78 -> V_80 [ V_95 ] ||
! V_78 -> V_80 [ V_96 ] ||
! ( ( ! V_78 -> V_80 [ V_81 ] ||
! V_78 -> V_80 [ V_82 ] ) ^
( ! V_78 -> V_80 [ V_83 ] ||
! V_78 -> V_80 [ V_84 ] ) ) )
return - V_51 ;
F_64 ( V_86 , & V_44 ) ;
V_26 = F_59 ( V_78 , & V_23 , & V_24 , & V_42 ) ;
if ( V_26 != 0 )
return V_26 ;
V_41 = F_61 ( V_78 -> V_80 [ V_96 ] ) ;
V_26 = F_73 (
F_61 ( V_78 -> V_80 [ V_95 ] ) ,
F_60 ( V_78 -> V_80 [ V_95 ] ) ,
& V_25 ) ;
if ( V_26 != 0 )
return V_26 ;
return F_26 ( & V_70 ,
V_41 , V_23 , V_24 , V_42 , V_25 ,
& V_44 ) ;
}
static int F_74 ( struct V_85 * V_86 ,
struct V_77 * V_78 )
{
int V_26 ;
void * V_23 ;
void * V_24 ;
T_1 V_42 ;
T_1 V_25 ;
struct V_43 V_44 ;
if ( ! V_78 -> V_80 [ V_95 ] ||
! ( ( ! V_78 -> V_80 [ V_81 ] ||
! V_78 -> V_80 [ V_82 ] ) ^
( ! V_78 -> V_80 [ V_83 ] ||
! V_78 -> V_80 [ V_84 ] ) ) )
return - V_51 ;
F_64 ( V_86 , & V_44 ) ;
V_26 = F_59 ( V_78 , & V_23 , & V_24 , & V_42 ) ;
if ( V_26 != 0 )
return V_26 ;
V_26 = F_73 (
F_61 ( V_78 -> V_80 [ V_95 ] ) ,
F_60 ( V_78 -> V_80 [ V_95 ] ) ,
& V_25 ) ;
if ( V_26 != 0 )
return V_26 ;
return F_26 ( & V_70 ,
NULL , V_23 , V_24 , V_42 , V_25 ,
& V_44 ) ;
}
static int F_75 ( struct V_85 * V_86 ,
struct V_77 * V_78 )
{
int V_26 ;
char * V_41 ;
void * V_23 ;
void * V_24 ;
T_1 V_42 ;
struct V_43 V_44 ;
if ( ! V_78 -> V_80 [ V_96 ] ||
! ( ( ! V_78 -> V_80 [ V_81 ] ||
! V_78 -> V_80 [ V_82 ] ) ^
( ! V_78 -> V_80 [ V_83 ] ||
! V_78 -> V_80 [ V_84 ] ) ) )
return - V_51 ;
F_64 ( V_86 , & V_44 ) ;
V_26 = F_59 ( V_78 , & V_23 , & V_24 , & V_42 ) ;
if ( V_26 != 0 )
return V_26 ;
V_41 = F_61 ( V_78 -> V_80 [ V_96 ] ) ;
return F_52 ( & V_70 ,
V_41 , V_23 , V_24 , V_42 ,
& V_44 ) ;
}
static int F_76 ( struct V_85 * V_86 ,
struct V_77 * V_78 )
{
int V_26 ;
void * V_23 ;
void * V_24 ;
T_1 V_42 ;
struct V_43 V_44 ;
if ( ! ( ( ! V_78 -> V_80 [ V_81 ] ||
! V_78 -> V_80 [ V_82 ] ) ^
( ! V_78 -> V_80 [ V_83 ] ||
! V_78 -> V_80 [ V_84 ] ) ) )
return - V_51 ;
F_64 ( V_86 , & V_44 ) ;
V_26 = F_59 ( V_78 , & V_23 , & V_24 , & V_42 ) ;
if ( V_26 != 0 )
return V_26 ;
return F_52 ( & V_70 ,
NULL , V_23 , V_24 , V_42 ,
& V_44 ) ;
}
static int F_77 ( T_1 V_97 ,
const struct V_3 * V_4 ,
const struct V_27 * V_55 ,
const struct V_35 * V_57 ,
void * V_98 )
{
int V_26 = - V_29 ;
struct V_99 * V_100 = V_98 ;
struct V_45 * V_46 ;
void * V_89 ;
T_1 V_25 ;
char * V_49 ;
T_1 V_50 ;
V_89 = F_78 ( V_100 -> V_86 , F_79 ( V_100 -> V_101 -> V_86 ) . V_102 ,
V_100 -> V_103 , & V_93 ,
V_104 , V_97 ) ;
if ( V_89 == NULL )
goto V_105;
if ( V_4 -> V_13 > 0 ) {
V_46 = F_41 ( & V_70 , V_4 -> V_13 ) ;
if ( ! V_46 ) {
V_26 = - V_52 ;
goto V_105;
}
V_26 = F_80 ( V_100 -> V_86 ,
V_96 , V_46 -> V_62 ) ;
F_42 ( V_46 ) ;
if ( V_26 != 0 )
goto V_105;
}
if ( V_55 ) {
struct V_22 V_106 ;
V_106 . V_31 = V_55 -> V_30 . V_23 ;
V_26 = F_81 ( V_100 -> V_86 ,
V_81 ,
sizeof( struct V_22 ) ,
& V_106 ) ;
if ( V_26 != 0 )
goto V_105;
V_106 . V_31 = V_55 -> V_30 . V_24 ;
V_26 = F_81 ( V_100 -> V_86 ,
V_82 ,
sizeof( struct V_22 ) ,
& V_106 ) ;
if ( V_26 != 0 )
goto V_105;
V_25 = V_55 -> V_25 ;
} else {
V_26 = F_81 ( V_100 -> V_86 ,
V_83 ,
sizeof( struct V_34 ) ,
& V_57 -> V_30 . V_23 ) ;
if ( V_26 != 0 )
goto V_105;
V_26 = F_81 ( V_100 -> V_86 ,
V_84 ,
sizeof( struct V_34 ) ,
& V_57 -> V_30 . V_24 ) ;
if ( V_26 != 0 )
goto V_105;
V_25 = V_57 -> V_25 ;
}
V_26 = F_35 ( V_25 , & V_49 , & V_50 ) ;
if ( V_26 != 0 )
goto V_105;
V_26 = F_81 ( V_100 -> V_86 ,
V_95 ,
V_50 ,
V_49 ) ;
F_37 ( V_49 , V_50 ) ;
if ( V_26 != 0 )
goto V_105;
V_100 -> V_103 ++ ;
F_69 ( V_100 -> V_86 , V_89 ) ;
return 0 ;
V_105:
F_82 ( V_100 -> V_86 , V_89 ) ;
return V_26 ;
}
static int F_83 ( struct V_85 * V_86 ,
struct V_107 * V_108 )
{
struct V_99 V_100 ;
T_1 V_109 = V_108 -> args [ 0 ] ;
T_1 V_110 = V_108 -> args [ 1 ] ;
T_1 V_111 ;
T_1 V_112 = 0 , V_113 = 0 , V_114 = 0 ;
struct V_3 * V_4 ;
struct V_17 * V_115 ;
struct V_5 * V_55 ;
#if F_2 ( V_8 )
struct V_9 * V_57 ;
#endif
V_100 . V_101 = V_108 ;
V_100 . V_86 = V_86 ;
V_100 . V_103 = V_108 -> V_116 -> V_117 ;
F_27 () ;
for ( V_111 = V_109 ;
V_111 < F_29 ( V_14 ) -> V_15 ;
V_111 ++ , V_112 = 0 , V_113 = 0 , V_114 = 0 ) {
V_115 = & F_29 ( V_14 ) -> V_20 [ V_111 ] ;
F_14 (iface, iter_list, list) {
if ( ! V_4 -> V_21 ||
V_112 ++ < V_110 )
continue;
F_47 (addr4,
&iface->addr4_list) {
if ( V_113 ++ < V_108 -> args [ 2 ] )
continue;
if ( F_77 (
V_118 ,
V_4 ,
F_7 ( V_55 ) ,
NULL ,
& V_100 ) < 0 ) {
V_113 -- ;
V_112 -- ;
goto V_119;
}
}
#if F_2 ( V_8 )
F_48 (addr6,
&iface->addr6_list) {
if ( V_114 ++ < V_108 -> args [ 3 ] )
continue;
if ( F_77 (
V_118 ,
V_4 ,
NULL ,
F_10 ( V_57 ) ,
& V_100 ) < 0 ) {
V_114 -- ;
V_112 -- ;
goto V_119;
}
}
#endif
}
}
V_119:
F_34 () ;
V_108 -> args [ 0 ] = V_111 ;
V_108 -> args [ 1 ] = V_112 ;
V_108 -> args [ 2 ] = V_113 ;
V_108 -> args [ 3 ] = V_114 ;
return V_86 -> V_79 ;
}
static int F_84 ( struct V_85 * V_86 ,
struct V_107 * V_108 )
{
struct V_99 V_100 ;
struct V_3 * V_4 ;
T_1 V_113 = 0 , V_114 = 0 ;
struct V_5 * V_55 ;
#if F_2 ( V_8 )
struct V_9 * V_57 ;
#endif
V_100 . V_101 = V_108 ;
V_100 . V_86 = V_86 ;
V_100 . V_103 = V_108 -> V_116 -> V_117 ;
F_27 () ;
V_4 = F_29 ( V_39 ) ;
if ( V_4 == NULL || ! V_4 -> V_21 )
goto V_120;
F_47 (addr4, &iface->addr4_list) {
if ( V_113 ++ < V_108 -> args [ 0 ] )
continue;
if ( F_77 ( V_121 ,
V_4 ,
F_7 ( V_55 ) ,
NULL ,
& V_100 ) < 0 ) {
V_113 -- ;
goto V_120;
}
}
#if F_2 ( V_8 )
F_48 (addr6, &iface->addr6_list) {
if ( V_114 ++ < V_108 -> args [ 1 ] )
continue;
if ( F_77 ( V_121 ,
V_4 ,
NULL ,
F_10 ( V_57 ) ,
& V_100 ) < 0 ) {
V_114 -- ;
goto V_120;
}
}
#endif
V_120:
F_34 () ;
V_108 -> args [ 0 ] = V_113 ;
V_108 -> args [ 1 ] = V_114 ;
return V_86 -> V_79 ;
}
int T_3 F_85 ( void )
{
return F_86 ( & V_93 ,
V_122 ) ;
}
int T_3 F_87 ( T_1 V_15 )
{
T_1 V_19 ;
struct V_123 * V_124 ;
if ( V_15 == 0 )
return - V_51 ;
V_124 = F_88 ( sizeof( * V_124 ) , V_91 ) ;
if ( V_124 == NULL )
return - V_29 ;
V_124 -> V_15 = 1 << V_15 ;
V_124 -> V_20 = F_89 ( V_124 -> V_15 ,
sizeof( struct V_17 ) ,
V_91 ) ;
if ( V_124 -> V_20 == NULL ) {
F_6 ( V_124 ) ;
return - V_29 ;
}
for ( V_19 = 0 ; V_19 < V_124 -> V_15 ; V_19 ++ )
F_23 ( & V_124 -> V_20 [ V_19 ] ) ;
F_17 ( & V_32 ) ;
F_25 ( V_14 , V_124 ) ;
F_19 ( & V_32 ) ;
F_90 ( & V_125 ) ;
return 0 ;
}
int F_91 ( const struct V_85 * V_86 ,
T_4 V_126 ,
struct V_127 * V_128 )
{
struct V_3 * V_4 ;
F_27 () ;
V_4 = F_13 ( V_86 -> V_129 ) ;
if ( V_4 == NULL )
V_4 = F_29 ( V_39 ) ;
if ( V_4 == NULL || ! V_4 -> V_21 )
goto V_130;
switch ( V_126 ) {
case V_131 : {
struct V_132 * V_133 ;
struct V_5 * V_55 ;
V_133 = F_92 ( V_86 ) ;
V_55 = F_93 ( V_133 -> V_134 ,
& V_4 -> V_33 ) ;
if ( V_55 == NULL )
goto V_130;
V_128 -> V_135 . V_25 = F_7 ( V_55 ) -> V_25 ;
break;
}
#if F_2 ( V_8 )
case V_136 : {
struct V_137 * V_138 ;
struct V_9 * V_57 ;
V_138 = F_94 ( V_86 ) ;
V_57 = F_95 ( & V_138 -> V_134 ,
& V_4 -> V_37 ) ;
if ( V_57 == NULL )
goto V_130;
V_128 -> V_135 . V_25 = F_10 ( V_57 ) -> V_25 ;
break;
}
#endif
default:
goto V_130;
}
F_34 () ;
V_128 -> V_139 |= V_140 ;
V_128 -> type = V_141 ;
return 0 ;
V_130:
F_34 () ;
if ( V_75 == 0 )
return - V_142 ;
V_128 -> type = V_141 ;
return 0 ;
}
int T_3 F_96 ( void )
{
int V_26 ;
struct V_143 * V_2 ;
struct V_43 V_44 ;
F_97 ( V_144 , & V_44 . V_25 ) ;
V_44 . V_145 = V_146 ;
V_44 . V_147 = 0 ;
V_2 = F_16 ( sizeof( * V_2 ) , V_91 ) ;
if ( V_2 == NULL )
return - V_29 ;
V_2 -> V_148 . type = V_141 ;
V_26 = F_98 ( V_2 , & V_44 ) ;
if ( V_26 != 0 )
return V_26 ;
F_58 ( 1 , & V_44 ) ;
return 0 ;
}
