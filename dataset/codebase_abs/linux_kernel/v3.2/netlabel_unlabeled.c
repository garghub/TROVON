static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_5 * V_7 ;
#if F_2 ( V_8 ) || F_2 ( V_9 )
struct V_10 * V_11 ;
struct V_10 * V_12 ;
#endif
V_4 = F_3 ( V_2 , struct V_3 , V_13 ) ;
F_4 (iter4, tmp4, &iface->addr4_list) {
F_5 ( V_6 ) ;
F_6 ( F_7 ( V_6 ) ) ;
}
#if F_2 ( V_8 ) || F_2 ( V_9 )
F_8 (iter6, tmp6, &iface->addr6_list) {
F_9 ( V_11 ) ;
F_6 ( F_10 ( V_11 ) ) ;
}
#endif
F_6 ( V_4 ) ;
}
static T_1 F_11 ( int V_14 )
{
return V_14 & ( F_12 ( V_15 ) -> V_16 - 1 ) ;
}
static struct V_3 * F_13 ( int V_14 )
{
T_1 V_17 ;
struct V_18 * V_19 ;
struct V_3 * V_20 ;
V_17 = F_11 ( V_14 ) ;
V_19 = & F_12 ( V_15 ) -> V_21 [ V_17 ] ;
F_14 (iter, bkt_list, list)
if ( V_20 -> V_22 && V_20 -> V_14 == V_14 )
return V_20 ;
return NULL ;
}
static int F_15 ( struct V_3 * V_4 ,
const struct V_23 * V_24 ,
const struct V_23 * V_25 ,
T_1 V_26 )
{
int V_27 ;
struct V_28 * V_2 ;
V_2 = F_16 ( sizeof( * V_2 ) , V_29 ) ;
if ( V_2 == NULL )
return - V_30 ;
V_2 -> V_31 . V_24 = V_24 -> V_32 & V_25 -> V_32 ;
V_2 -> V_31 . V_25 = V_25 -> V_32 ;
V_2 -> V_31 . V_22 = 1 ;
V_2 -> V_26 = V_26 ;
F_17 ( & V_33 ) ;
V_27 = F_18 ( & V_2 -> V_31 , & V_4 -> V_34 ) ;
F_19 ( & V_33 ) ;
if ( V_27 != 0 )
F_6 ( V_2 ) ;
return V_27 ;
}
static int F_20 ( struct V_3 * V_4 ,
const struct V_35 * V_24 ,
const struct V_35 * V_25 ,
T_1 V_26 )
{
int V_27 ;
struct V_36 * V_2 ;
V_2 = F_16 ( sizeof( * V_2 ) , V_29 ) ;
if ( V_2 == NULL )
return - V_30 ;
F_21 ( & V_2 -> V_31 . V_24 , V_24 ) ;
V_2 -> V_31 . V_24 . V_37 [ 0 ] &= V_25 -> V_37 [ 0 ] ;
V_2 -> V_31 . V_24 . V_37 [ 1 ] &= V_25 -> V_37 [ 1 ] ;
V_2 -> V_31 . V_24 . V_37 [ 2 ] &= V_25 -> V_37 [ 2 ] ;
V_2 -> V_31 . V_24 . V_37 [ 3 ] &= V_25 -> V_37 [ 3 ] ;
F_21 ( & V_2 -> V_31 . V_25 , V_25 ) ;
V_2 -> V_31 . V_22 = 1 ;
V_2 -> V_26 = V_26 ;
F_17 ( & V_33 ) ;
V_27 = F_22 ( & V_2 -> V_31 , & V_4 -> V_38 ) ;
F_19 ( & V_33 ) ;
if ( V_27 != 0 )
F_6 ( V_2 ) ;
return 0 ;
}
static struct V_3 * F_23 ( int V_14 )
{
T_1 V_17 ;
struct V_3 * V_4 ;
V_4 = F_16 ( sizeof( * V_4 ) , V_29 ) ;
if ( V_4 == NULL )
return NULL ;
V_4 -> V_14 = V_14 ;
F_24 ( & V_4 -> V_34 ) ;
F_24 ( & V_4 -> V_38 ) ;
V_4 -> V_22 = 1 ;
F_17 ( & V_33 ) ;
if ( V_14 > 0 ) {
V_17 = F_11 ( V_14 ) ;
if ( F_13 ( V_14 ) != NULL )
goto V_39;
F_25 ( & V_4 -> V_31 ,
& F_12 ( V_15 ) -> V_21 [ V_17 ] ) ;
} else {
F_24 ( & V_4 -> V_31 ) ;
if ( F_12 ( V_40 ) != NULL )
goto V_39;
F_26 ( V_40 , V_4 ) ;
}
F_19 ( & V_33 ) ;
return V_4 ;
V_39:
F_19 ( & V_33 ) ;
F_6 ( V_4 ) ;
return NULL ;
}
int F_27 ( struct V_41 * V_41 ,
const char * V_42 ,
const void * V_24 ,
const void * V_25 ,
T_1 V_43 ,
T_1 V_26 ,
struct V_44 * V_45 )
{
int V_27 ;
int V_14 ;
struct V_46 * V_47 ;
struct V_3 * V_4 ;
struct V_48 * V_49 = NULL ;
char * V_50 = NULL ;
T_1 V_51 ;
if ( V_43 != sizeof( struct V_23 ) &&
V_43 != sizeof( struct V_35 ) )
return - V_52 ;
F_28 () ;
if ( V_42 != NULL ) {
V_47 = F_29 ( V_41 , V_42 ) ;
if ( V_47 == NULL ) {
V_27 = - V_53 ;
goto V_54;
}
V_14 = V_47 -> V_14 ;
V_4 = F_13 ( V_14 ) ;
} else {
V_14 = 0 ;
V_4 = F_30 ( V_40 ) ;
}
if ( V_4 == NULL ) {
V_4 = F_23 ( V_14 ) ;
if ( V_4 == NULL ) {
V_27 = - V_30 ;
goto V_54;
}
}
V_49 = F_31 ( V_55 ,
V_45 ) ;
switch ( V_43 ) {
case sizeof( struct V_23 ) : {
const struct V_23 * V_56 = V_24 ;
const struct V_23 * V_57 = V_25 ;
V_27 = F_15 ( V_4 , V_56 , V_57 , V_26 ) ;
if ( V_49 != NULL )
F_32 ( V_49 , 1 ,
V_42 ,
V_56 -> V_32 ,
V_57 -> V_32 ) ;
break;
}
#if F_2 ( V_8 ) || F_2 ( V_9 )
case sizeof( struct V_35 ) : {
const struct V_35 * V_58 = V_24 ;
const struct V_35 * V_59 = V_25 ;
V_27 = F_20 ( V_4 , V_58 , V_59 , V_26 ) ;
if ( V_49 != NULL )
F_33 ( V_49 , 1 ,
V_42 ,
V_58 , V_59 ) ;
break;
}
#endif
default:
V_27 = - V_52 ;
}
if ( V_27 == 0 )
F_34 ( & V_60 ) ;
V_54:
F_35 () ;
if ( V_49 != NULL ) {
if ( F_36 ( V_26 ,
& V_50 ,
& V_51 ) == 0 ) {
F_37 ( V_49 , L_1 , V_50 ) ;
F_38 ( V_50 , V_51 ) ;
}
F_37 ( V_49 , L_2 , V_27 == 0 ? 1 : 0 ) ;
F_39 ( V_49 ) ;
}
return V_27 ;
}
static int F_40 ( struct V_41 * V_41 ,
struct V_3 * V_4 ,
const struct V_23 * V_24 ,
const struct V_23 * V_25 ,
struct V_44 * V_45 )
{
struct V_5 * V_61 ;
struct V_28 * V_2 ;
struct V_48 * V_49 ;
struct V_46 * V_47 ;
char * V_50 ;
T_1 V_51 ;
F_17 ( & V_33 ) ;
V_61 = F_41 ( V_24 -> V_32 , V_25 -> V_32 ,
& V_4 -> V_34 ) ;
F_19 ( & V_33 ) ;
if ( V_61 != NULL )
V_2 = F_7 ( V_61 ) ;
else
V_2 = NULL ;
V_49 = F_31 ( V_62 ,
V_45 ) ;
if ( V_49 != NULL ) {
V_47 = F_42 ( V_41 , V_4 -> V_14 ) ;
F_32 ( V_49 , 1 ,
( V_47 != NULL ? V_47 -> V_63 : NULL ) ,
V_24 -> V_32 , V_25 -> V_32 ) ;
if ( V_47 != NULL )
F_43 ( V_47 ) ;
if ( V_2 != NULL &&
F_36 ( V_2 -> V_26 ,
& V_50 , & V_51 ) == 0 ) {
F_37 ( V_49 , L_1 , V_50 ) ;
F_38 ( V_50 , V_51 ) ;
}
F_37 ( V_49 , L_2 , V_2 != NULL ? 1 : 0 ) ;
F_39 ( V_49 ) ;
}
if ( V_2 == NULL )
return - V_64 ;
F_44 ( V_2 , V_13 ) ;
return 0 ;
}
static int F_45 ( struct V_41 * V_41 ,
struct V_3 * V_4 ,
const struct V_35 * V_24 ,
const struct V_35 * V_25 ,
struct V_44 * V_45 )
{
struct V_10 * V_61 ;
struct V_36 * V_2 ;
struct V_48 * V_49 ;
struct V_46 * V_47 ;
char * V_50 ;
T_1 V_51 ;
F_17 ( & V_33 ) ;
V_61 = F_46 ( V_24 , V_25 , & V_4 -> V_38 ) ;
F_19 ( & V_33 ) ;
if ( V_61 != NULL )
V_2 = F_10 ( V_61 ) ;
else
V_2 = NULL ;
V_49 = F_31 ( V_62 ,
V_45 ) ;
if ( V_49 != NULL ) {
V_47 = F_42 ( V_41 , V_4 -> V_14 ) ;
F_33 ( V_49 , 1 ,
( V_47 != NULL ? V_47 -> V_63 : NULL ) ,
V_24 , V_25 ) ;
if ( V_47 != NULL )
F_43 ( V_47 ) ;
if ( V_2 != NULL &&
F_36 ( V_2 -> V_26 ,
& V_50 , & V_51 ) == 0 ) {
F_37 ( V_49 , L_1 , V_50 ) ;
F_38 ( V_50 , V_51 ) ;
}
F_37 ( V_49 , L_2 , V_2 != NULL ? 1 : 0 ) ;
F_39 ( V_49 ) ;
}
if ( V_2 == NULL )
return - V_64 ;
F_44 ( V_2 , V_13 ) ;
return 0 ;
}
static void F_47 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
#if F_2 ( V_8 ) || F_2 ( V_9 )
struct V_10 * V_11 ;
#endif
F_17 ( & V_33 ) ;
F_48 (iter4, &iface->addr4_list)
goto V_65;
#if F_2 ( V_8 ) || F_2 ( V_9 )
F_49 (iter6, &iface->addr6_list)
goto V_65;
#endif
V_4 -> V_22 = 0 ;
if ( V_4 -> V_14 > 0 )
F_50 ( & V_4 -> V_31 ) ;
else
F_26 ( V_40 , NULL ) ;
F_19 ( & V_33 ) ;
F_51 ( & V_4 -> V_13 , F_1 ) ;
return;
V_65:
F_19 ( & V_33 ) ;
}
int F_52 ( struct V_41 * V_41 ,
const char * V_42 ,
const void * V_24 ,
const void * V_25 ,
T_1 V_43 ,
struct V_44 * V_45 )
{
int V_27 ;
struct V_46 * V_47 ;
struct V_3 * V_4 ;
if ( V_43 != sizeof( struct V_23 ) &&
V_43 != sizeof( struct V_35 ) )
return - V_52 ;
F_28 () ;
if ( V_42 != NULL ) {
V_47 = F_29 ( V_41 , V_42 ) ;
if ( V_47 == NULL ) {
V_27 = - V_53 ;
goto V_66;
}
V_4 = F_13 ( V_47 -> V_14 ) ;
} else
V_4 = F_30 ( V_40 ) ;
if ( V_4 == NULL ) {
V_27 = - V_64 ;
goto V_66;
}
switch ( V_43 ) {
case sizeof( struct V_23 ) :
V_27 = F_40 ( V_41 ,
V_4 , V_24 , V_25 ,
V_45 ) ;
break;
#if F_2 ( V_8 ) || F_2 ( V_9 )
case sizeof( struct V_35 ) :
V_27 = F_45 ( V_41 ,
V_4 , V_24 , V_25 ,
V_45 ) ;
break;
#endif
default:
V_27 = - V_52 ;
}
if ( V_27 == 0 ) {
F_47 ( V_4 ) ;
F_53 ( & V_60 ) ;
}
V_66:
F_35 () ;
return V_27 ;
}
static int F_54 ( struct V_67 * V_68 ,
unsigned long V_69 ,
void * V_70 )
{
struct V_46 * V_47 = V_70 ;
struct V_3 * V_4 = NULL ;
if ( ! F_55 ( F_56 ( V_47 ) , & V_71 ) )
return V_72 ;
if ( V_69 == V_73 ) {
F_17 ( & V_33 ) ;
V_4 = F_13 ( V_47 -> V_14 ) ;
if ( V_4 != NULL && V_4 -> V_22 ) {
V_4 -> V_22 = 0 ;
F_50 ( & V_4 -> V_31 ) ;
} else
V_4 = NULL ;
F_19 ( & V_33 ) ;
}
if ( V_4 != NULL )
F_51 ( & V_4 -> V_13 , F_1 ) ;
return V_72 ;
}
static void F_57 ( T_2 V_74 ,
struct V_44 * V_45 )
{
struct V_48 * V_49 ;
T_2 V_75 ;
V_75 = V_76 ;
V_76 = V_74 ;
V_49 = F_31 ( V_77 ,
V_45 ) ;
if ( V_49 != NULL ) {
F_37 ( V_49 ,
L_3 , V_74 , V_75 ) ;
F_39 ( V_49 ) ;
}
}
static int F_58 ( struct V_78 * V_79 ,
void * * V_24 ,
void * * V_25 ,
T_1 * V_80 )
{
T_1 V_43 ;
if ( V_79 -> V_81 [ V_82 ] ) {
V_43 = F_59 ( V_79 -> V_81 [ V_82 ] ) ;
if ( V_43 != sizeof( struct V_23 ) &&
V_43 != F_59 ( V_79 -> V_81 [ V_83 ] ) )
return - V_52 ;
* V_80 = V_43 ;
* V_24 = F_60 ( V_79 -> V_81 [ V_82 ] ) ;
* V_25 = F_60 ( V_79 -> V_81 [ V_83 ] ) ;
return 0 ;
} else if ( V_79 -> V_81 [ V_84 ] ) {
V_43 = F_59 ( V_79 -> V_81 [ V_84 ] ) ;
if ( V_43 != sizeof( struct V_35 ) &&
V_43 != F_59 ( V_79 -> V_81 [ V_85 ] ) )
return - V_52 ;
* V_80 = V_43 ;
* V_24 = F_60 ( V_79 -> V_81 [ V_84 ] ) ;
* V_25 = F_60 ( V_79 -> V_81 [ V_85 ] ) ;
return 0 ;
}
return - V_52 ;
}
static int F_61 ( struct V_86 * V_87 , struct V_78 * V_79 )
{
T_2 V_74 ;
struct V_44 V_45 ;
if ( V_79 -> V_81 [ V_88 ] ) {
V_74 = F_62 ( V_79 -> V_81 [ V_88 ] ) ;
if ( V_74 == 1 || V_74 == 0 ) {
F_63 ( V_87 , & V_45 ) ;
F_57 ( V_74 , & V_45 ) ;
return 0 ;
}
}
return - V_52 ;
}
static int F_64 ( struct V_86 * V_87 , struct V_78 * V_79 )
{
int V_27 = - V_52 ;
struct V_86 * V_89 ;
void * V_90 ;
V_89 = F_65 ( V_91 , V_92 ) ;
if ( V_89 == NULL )
goto V_93;
V_90 = F_66 ( V_89 , V_79 , & V_94 ,
0 , V_95 ) ;
if ( V_90 == NULL ) {
V_27 = - V_30 ;
goto V_93;
}
V_27 = F_67 ( V_89 ,
V_88 ,
V_76 ) ;
if ( V_27 != 0 )
goto V_93;
F_68 ( V_89 , V_90 ) ;
return F_69 ( V_89 , V_79 ) ;
V_93:
F_70 ( V_89 ) ;
return V_27 ;
}
static int F_71 ( struct V_86 * V_87 ,
struct V_78 * V_79 )
{
int V_27 ;
char * V_42 ;
void * V_24 ;
void * V_25 ;
T_1 V_43 ;
T_1 V_26 ;
struct V_44 V_45 ;
if ( ! V_79 -> V_81 [ V_96 ] ||
! V_79 -> V_81 [ V_97 ] ||
! ( ( ! V_79 -> V_81 [ V_82 ] ||
! V_79 -> V_81 [ V_83 ] ) ^
( ! V_79 -> V_81 [ V_84 ] ||
! V_79 -> V_81 [ V_85 ] ) ) )
return - V_52 ;
F_63 ( V_87 , & V_45 ) ;
V_27 = F_58 ( V_79 , & V_24 , & V_25 , & V_43 ) ;
if ( V_27 != 0 )
return V_27 ;
V_42 = F_60 ( V_79 -> V_81 [ V_97 ] ) ;
V_27 = F_72 (
F_60 ( V_79 -> V_81 [ V_96 ] ) ,
F_59 ( V_79 -> V_81 [ V_96 ] ) ,
& V_26 ) ;
if ( V_27 != 0 )
return V_27 ;
return F_27 ( & V_71 ,
V_42 , V_24 , V_25 , V_43 , V_26 ,
& V_45 ) ;
}
static int F_73 ( struct V_86 * V_87 ,
struct V_78 * V_79 )
{
int V_27 ;
void * V_24 ;
void * V_25 ;
T_1 V_43 ;
T_1 V_26 ;
struct V_44 V_45 ;
if ( ! V_79 -> V_81 [ V_96 ] ||
! ( ( ! V_79 -> V_81 [ V_82 ] ||
! V_79 -> V_81 [ V_83 ] ) ^
( ! V_79 -> V_81 [ V_84 ] ||
! V_79 -> V_81 [ V_85 ] ) ) )
return - V_52 ;
F_63 ( V_87 , & V_45 ) ;
V_27 = F_58 ( V_79 , & V_24 , & V_25 , & V_43 ) ;
if ( V_27 != 0 )
return V_27 ;
V_27 = F_72 (
F_60 ( V_79 -> V_81 [ V_96 ] ) ,
F_59 ( V_79 -> V_81 [ V_96 ] ) ,
& V_26 ) ;
if ( V_27 != 0 )
return V_27 ;
return F_27 ( & V_71 ,
NULL , V_24 , V_25 , V_43 , V_26 ,
& V_45 ) ;
}
static int F_74 ( struct V_86 * V_87 ,
struct V_78 * V_79 )
{
int V_27 ;
char * V_42 ;
void * V_24 ;
void * V_25 ;
T_1 V_43 ;
struct V_44 V_45 ;
if ( ! V_79 -> V_81 [ V_97 ] ||
! ( ( ! V_79 -> V_81 [ V_82 ] ||
! V_79 -> V_81 [ V_83 ] ) ^
( ! V_79 -> V_81 [ V_84 ] ||
! V_79 -> V_81 [ V_85 ] ) ) )
return - V_52 ;
F_63 ( V_87 , & V_45 ) ;
V_27 = F_58 ( V_79 , & V_24 , & V_25 , & V_43 ) ;
if ( V_27 != 0 )
return V_27 ;
V_42 = F_60 ( V_79 -> V_81 [ V_97 ] ) ;
return F_52 ( & V_71 ,
V_42 , V_24 , V_25 , V_43 ,
& V_45 ) ;
}
static int F_75 ( struct V_86 * V_87 ,
struct V_78 * V_79 )
{
int V_27 ;
void * V_24 ;
void * V_25 ;
T_1 V_43 ;
struct V_44 V_45 ;
if ( ! ( ( ! V_79 -> V_81 [ V_82 ] ||
! V_79 -> V_81 [ V_83 ] ) ^
( ! V_79 -> V_81 [ V_84 ] ||
! V_79 -> V_81 [ V_85 ] ) ) )
return - V_52 ;
F_63 ( V_87 , & V_45 ) ;
V_27 = F_58 ( V_79 , & V_24 , & V_25 , & V_43 ) ;
if ( V_27 != 0 )
return V_27 ;
return F_52 ( & V_71 ,
NULL , V_24 , V_25 , V_43 ,
& V_45 ) ;
}
static int F_76 ( T_1 V_98 ,
const struct V_3 * V_4 ,
const struct V_28 * V_56 ,
const struct V_36 * V_58 ,
void * V_99 )
{
int V_27 = - V_30 ;
struct V_100 * V_101 = V_99 ;
struct V_46 * V_47 ;
void * V_90 ;
T_1 V_26 ;
char * V_50 ;
T_1 V_51 ;
V_90 = F_77 ( V_101 -> V_87 , F_78 ( V_101 -> V_102 -> V_87 ) . V_103 ,
V_101 -> V_104 , & V_94 ,
V_105 , V_98 ) ;
if ( V_90 == NULL )
goto V_106;
if ( V_4 -> V_14 > 0 ) {
V_47 = F_42 ( & V_71 , V_4 -> V_14 ) ;
if ( ! V_47 ) {
V_27 = - V_53 ;
goto V_106;
}
V_27 = F_79 ( V_101 -> V_87 ,
V_97 , V_47 -> V_63 ) ;
F_43 ( V_47 ) ;
if ( V_27 != 0 )
goto V_106;
}
if ( V_56 ) {
struct V_23 V_107 ;
V_107 . V_32 = V_56 -> V_31 . V_24 ;
V_27 = F_80 ( V_101 -> V_87 ,
V_82 ,
sizeof( struct V_23 ) ,
& V_107 ) ;
if ( V_27 != 0 )
goto V_106;
V_107 . V_32 = V_56 -> V_31 . V_25 ;
V_27 = F_80 ( V_101 -> V_87 ,
V_83 ,
sizeof( struct V_23 ) ,
& V_107 ) ;
if ( V_27 != 0 )
goto V_106;
V_26 = V_56 -> V_26 ;
} else {
V_27 = F_80 ( V_101 -> V_87 ,
V_84 ,
sizeof( struct V_35 ) ,
& V_58 -> V_31 . V_24 ) ;
if ( V_27 != 0 )
goto V_106;
V_27 = F_80 ( V_101 -> V_87 ,
V_85 ,
sizeof( struct V_35 ) ,
& V_58 -> V_31 . V_25 ) ;
if ( V_27 != 0 )
goto V_106;
V_26 = V_58 -> V_26 ;
}
V_27 = F_36 ( V_26 , & V_50 , & V_51 ) ;
if ( V_27 != 0 )
goto V_106;
V_27 = F_80 ( V_101 -> V_87 ,
V_96 ,
V_51 ,
V_50 ) ;
F_38 ( V_50 , V_51 ) ;
if ( V_27 != 0 )
goto V_106;
V_101 -> V_104 ++ ;
return F_68 ( V_101 -> V_87 , V_90 ) ;
V_106:
F_81 ( V_101 -> V_87 , V_90 ) ;
return V_27 ;
}
static int F_82 ( struct V_86 * V_87 ,
struct V_108 * V_109 )
{
struct V_100 V_101 ;
T_1 V_110 = V_109 -> args [ 0 ] ;
T_1 V_111 = V_109 -> args [ 1 ] ;
T_1 V_112 = V_109 -> args [ 2 ] ;
T_1 V_113 = V_109 -> args [ 3 ] ;
T_1 V_114 ;
T_1 V_115 = 0 , V_116 = 0 , V_117 = 0 ;
struct V_3 * V_4 ;
struct V_18 * V_118 ;
struct V_5 * V_56 ;
#if F_2 ( V_8 ) || F_2 ( V_9 )
struct V_10 * V_58 ;
#endif
V_101 . V_102 = V_109 ;
V_101 . V_87 = V_87 ;
V_101 . V_104 = V_109 -> V_119 -> V_120 ;
F_28 () ;
for ( V_114 = V_110 ;
V_114 < F_30 ( V_15 ) -> V_16 ;
V_114 ++ , V_115 = 0 , V_116 = 0 , V_117 = 0 ) {
V_118 = & F_30 ( V_15 ) -> V_21 [ V_114 ] ;
F_14 (iface, iter_list, list) {
if ( ! V_4 -> V_22 ||
V_115 ++ < V_111 )
continue;
F_48 (addr4,
&iface->addr4_list) {
if ( V_116 ++ < V_112 )
continue;
if ( F_76 (
V_121 ,
V_4 ,
F_7 ( V_56 ) ,
NULL ,
& V_101 ) < 0 ) {
V_116 -- ;
V_115 -- ;
goto V_122;
}
}
#if F_2 ( V_8 ) || F_2 ( V_9 )
F_49 (addr6,
&iface->addr6_list) {
if ( V_117 ++ < V_113 )
continue;
if ( F_76 (
V_121 ,
V_4 ,
NULL ,
F_10 ( V_58 ) ,
& V_101 ) < 0 ) {
V_117 -- ;
V_115 -- ;
goto V_122;
}
}
#endif
}
}
V_122:
F_35 () ;
V_109 -> args [ 0 ] = V_110 ;
V_109 -> args [ 1 ] = V_111 ;
V_109 -> args [ 2 ] = V_112 ;
V_109 -> args [ 3 ] = V_113 ;
return V_87 -> V_80 ;
}
static int F_83 ( struct V_86 * V_87 ,
struct V_108 * V_109 )
{
struct V_100 V_101 ;
struct V_3 * V_4 ;
T_1 V_112 = V_109 -> args [ 0 ] ;
T_1 V_113 = V_109 -> args [ 1 ] ;
T_1 V_116 = 0 ;
struct V_5 * V_56 ;
#if F_2 ( V_8 ) || F_2 ( V_9 )
T_1 V_117 = 0 ;
struct V_10 * V_58 ;
#endif
V_101 . V_102 = V_109 ;
V_101 . V_87 = V_87 ;
V_101 . V_104 = V_109 -> V_119 -> V_120 ;
F_28 () ;
V_4 = F_30 ( V_40 ) ;
if ( V_4 == NULL || ! V_4 -> V_22 )
goto V_123;
F_48 (addr4, &iface->addr4_list) {
if ( V_116 ++ < V_112 )
continue;
if ( F_76 ( V_124 ,
V_4 ,
F_7 ( V_56 ) ,
NULL ,
& V_101 ) < 0 ) {
V_116 -- ;
goto V_123;
}
}
#if F_2 ( V_8 ) || F_2 ( V_9 )
F_49 (addr6, &iface->addr6_list) {
if ( V_117 ++ < V_113 )
continue;
if ( F_76 ( V_124 ,
V_4 ,
NULL ,
F_10 ( V_58 ) ,
& V_101 ) < 0 ) {
V_117 -- ;
goto V_123;
}
}
#endif
V_123:
F_35 () ;
V_109 -> args [ 0 ] = V_112 ;
V_109 -> args [ 1 ] = V_113 ;
return V_87 -> V_80 ;
}
int T_3 F_84 ( void )
{
return F_85 ( & V_94 ,
V_125 , F_86 ( V_125 ) ) ;
}
int T_3 F_87 ( T_1 V_16 )
{
T_1 V_20 ;
struct V_126 * V_127 ;
if ( V_16 == 0 )
return - V_52 ;
V_127 = F_88 ( sizeof( * V_127 ) , V_92 ) ;
if ( V_127 == NULL )
return - V_30 ;
V_127 -> V_16 = 1 << V_16 ;
V_127 -> V_21 = F_89 ( V_127 -> V_16 ,
sizeof( struct V_18 ) ,
V_92 ) ;
if ( V_127 -> V_21 == NULL ) {
F_6 ( V_127 ) ;
return - V_30 ;
}
for ( V_20 = 0 ; V_20 < V_127 -> V_16 ; V_20 ++ )
F_24 ( & V_127 -> V_21 [ V_20 ] ) ;
F_28 () ;
F_17 ( & V_33 ) ;
F_26 ( V_15 , V_127 ) ;
F_19 ( & V_33 ) ;
F_35 () ;
F_90 ( & V_128 ) ;
return 0 ;
}
int F_91 ( const struct V_86 * V_87 ,
T_4 V_129 ,
struct V_130 * V_131 )
{
struct V_3 * V_4 ;
F_28 () ;
V_4 = F_13 ( V_87 -> V_132 ) ;
if ( V_4 == NULL )
V_4 = F_30 ( V_40 ) ;
if ( V_4 == NULL || ! V_4 -> V_22 )
goto V_133;
switch ( V_129 ) {
case V_134 : {
struct V_135 * V_136 ;
struct V_5 * V_56 ;
V_136 = F_92 ( V_87 ) ;
V_56 = F_93 ( V_136 -> V_137 ,
& V_4 -> V_34 ) ;
if ( V_56 == NULL )
goto V_133;
V_131 -> V_138 . V_26 = F_7 ( V_56 ) -> V_26 ;
break;
}
#if F_2 ( V_8 ) || F_2 ( V_9 )
case V_139 : {
struct V_140 * V_141 ;
struct V_10 * V_58 ;
V_141 = F_94 ( V_87 ) ;
V_58 = F_95 ( & V_141 -> V_137 ,
& V_4 -> V_38 ) ;
if ( V_58 == NULL )
goto V_133;
V_131 -> V_138 . V_26 = F_10 ( V_58 ) -> V_26 ;
break;
}
#endif
default:
goto V_133;
}
F_35 () ;
V_131 -> V_142 |= V_143 ;
V_131 -> type = V_144 ;
return 0 ;
V_133:
F_35 () ;
if ( V_76 == 0 )
return - V_145 ;
V_131 -> type = V_144 ;
return 0 ;
}
int T_3 F_96 ( void )
{
int V_27 ;
struct V_146 * V_2 ;
struct V_44 V_45 ;
F_97 ( V_147 , & V_45 . V_26 ) ;
V_45 . V_148 = 0 ;
V_45 . V_149 = 0 ;
V_2 = F_16 ( sizeof( * V_2 ) , V_92 ) ;
if ( V_2 == NULL )
return - V_30 ;
V_2 -> type = V_144 ;
V_27 = F_98 ( V_2 , & V_45 ) ;
if ( V_27 != 0 )
return V_27 ;
F_57 ( 1 , & V_45 ) ;
return 0 ;
}
