static inline void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 =
V_2 -> V_4 -> V_5 << 5 |
V_2 -> V_4 -> V_6 << 3 |
V_2 -> V_4 -> V_7 << 2 |
V_2 -> V_4 -> V_8 -> V_9 << 1 ;
}
static inline void F_2 ( struct V_1 * V_2 , struct V_10 * V_4 )
{
V_2 -> V_11 =
F_3 ( V_4 -> V_12 , V_13 ) ;
if ( ! F_4 ( V_2 -> V_11 ) ) {
F_5 ( L_1 , V_14 ,
V_2 -> V_11 ,
& V_2 -> V_15 ) ;
F_5 ( L_2 , V_14 ,
V_2 -> V_11 ,
& V_2 -> V_16 ) ;
F_6 ( L_3 , V_14 ,
V_2 -> V_11 ,
( V_17 * ) & V_2 -> V_18 ) ;
F_7 ( L_4 , V_14 ,
V_2 -> V_11 ,
& V_2 -> V_3 ) ;
}
V_2 -> V_15 . V_19 = V_2 -> V_20 ;
V_2 -> V_15 . V_21 = 0 ;
V_2 -> V_16 . V_19 = V_2 -> V_22 ;
V_2 -> V_16 . V_21 = 0 ;
}
static inline void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_11 ) ;
}
static inline void F_10 ( struct V_1 * V_2 , const T_1 * V_19 , int V_21 )
{
if ( V_21 > sizeof( V_2 -> V_22 ) )
V_21 = sizeof( V_2 -> V_22 ) ;
memcpy ( V_2 -> V_22 , V_19 , V_21 ) ;
V_2 -> V_16 . V_19 = V_2 -> V_22 ;
V_2 -> V_16 . V_21 = V_21 ;
}
static inline void F_11 ( struct V_1 * V_2 , const T_1 * V_19 , int V_21 )
{
if ( V_21 > sizeof( V_2 -> V_20 ) )
V_21 = sizeof( V_2 -> V_20 ) ;
memcpy ( V_2 -> V_20 , V_19 , V_21 ) ;
V_2 -> V_15 . V_19 = V_2 -> V_20 ;
V_2 -> V_15 . V_21 = V_21 ;
}
static inline void F_2 ( struct V_1 * V_2 , struct V_10 * V_4 )
{
}
static inline void F_8 ( struct V_1 * V_2 )
{
}
static inline void F_1 ( struct V_1 * V_2 )
{
}
static inline void F_10 ( struct V_1 * V_2 , const T_1 * V_19 , int V_21 )
{
}
static inline void F_11 ( struct V_1 * V_2 , const T_1 * V_19 , int V_21 )
{
}
static void F_12 ( struct V_10 * V_4 , const T_1 * V_19 ,
char * V_23 , int V_24 )
{
struct V_25 * V_26 = NULL ;
struct V_1 * V_2 ;
int V_27 ;
T_1 * V_28 ;
V_2 = V_4 -> V_29 ;
if ( ! V_2 -> V_30 . V_31 && ! V_2 -> V_32 ) {
F_13 ( & V_2 -> V_33 -> V_33 ,
L_5
L_6 ) ;
return;
}
F_14 ( V_2 -> V_33 == NULL ) ;
V_26 = F_15 ( V_2 -> V_33 , V_24 + 1 ) ;
if ( V_26 == NULL )
return;
V_28 = F_16 ( V_26 , V_24 ) ;
memcpy ( V_28 , V_19 , V_24 ) ;
V_26 -> V_34 = F_17 ( V_35 ) ;
F_18 ( V_26 ) ;
F_10 ( V_2 , V_19 , V_24 ) ;
V_27 = F_19 ( V_26 ) ;
if ( ! V_27 ) {
V_2 -> V_33 -> V_36 . V_37 ++ ;
V_2 -> V_33 -> V_36 . V_38 += V_24 ;
} else
++ V_2 -> V_33 -> V_36 . V_39 ;
F_1 ( V_2 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_10 * V_4 ;
struct V_25 * V_26 ;
int V_40 , V_41 , V_42 ;
V_4 = V_2 -> V_4 ;
V_2 -> V_32 = true ;
if ( F_21 ( V_43 , & V_2 -> V_18 ) )
return 0 ;
while ( ( V_26 = F_22 ( & V_2 -> V_44 ) ) != NULL ) {
V_41 = V_26 -> V_41 ;
V_42 = F_23 ( V_4 ) ;
if ( ! V_42 )
break;
if ( V_42 > V_45 )
V_42 = V_45 ;
if ( V_41 > V_42 )
V_41 = V_42 ;
if ( ! V_46 ) {
V_40 = V_4 -> V_47 -> V_48 ( V_4 , V_26 -> V_19 , V_41 ) ;
F_1 ( V_2 ) ;
} else {
V_40 = V_41 ;
F_12 ( V_4 , V_26 -> V_19 , NULL , V_41 ) ;
}
V_2 -> V_33 -> V_36 . V_49 ++ ;
V_2 -> V_33 -> V_36 . V_50 += V_40 ;
if ( V_40 < 0 )
goto error;
F_24 ( V_26 , V_40 ) ;
if ( V_26 -> V_41 == 0 ) {
struct V_25 * V_51 = F_25 ( & V_2 -> V_44 ) ;
F_26 ( V_51 != V_26 ) ;
if ( F_27 () )
F_28 ( V_26 ) ;
else
F_29 ( V_26 ) ;
}
}
if ( V_2 -> V_44 . V_52 <= V_53 &&
F_30 ( V_54 , & V_2 -> V_18 ) &&
V_2 -> V_30 . V_55 != NULL )
V_2 -> V_30 . V_55 ( V_2 -> V_33 , V_56 ) ;
F_31 ( V_43 , & V_2 -> V_18 ) ;
return 0 ;
error:
F_31 ( V_43 , & V_2 -> V_18 ) ;
return V_40 ;
}
static int F_32 ( struct V_25 * V_26 , struct V_57 * V_33 )
{
struct V_1 * V_2 ;
F_14 ( V_33 == NULL ) ;
V_2 = F_33 ( V_33 ) ;
if ( V_2 -> V_44 . V_52 > V_58 &&
! F_21 ( V_54 , & V_2 -> V_18 ) &&
V_2 -> V_30 . V_55 != NULL )
V_2 -> V_30 . V_55 ( V_2 -> V_33 , V_59 ) ;
F_34 ( & V_2 -> V_44 , V_26 ) ;
return F_20 ( V_2 ) ;
}
static void F_35 ( struct V_10 * V_4 )
{
struct V_1 * V_2 ;
V_2 = V_4 -> V_29 ;
F_14 ( V_2 == NULL ) ;
F_26 ( V_2 -> V_4 != V_4 ) ;
F_20 ( V_2 ) ;
}
static void F_36 ( struct V_60 * V_61 )
{
struct V_62 V_63 ;
struct V_1 * V_2 , * V_51 ;
F_37 ( & V_64 ) ;
F_38 ( & V_65 , & V_63 ) ;
F_39 ( & V_64 ) ;
if ( ! F_40 ( & V_63 ) ) {
F_41 () ;
F_42 (ser, tmp, &list, node) {
F_43 ( V_2 -> V_33 ) ;
F_44 ( V_2 -> V_33 ) ;
F_8 ( V_2 ) ;
}
F_45 () ;
}
}
static int F_46 ( struct V_10 * V_4 )
{
struct V_1 * V_2 ;
struct V_57 * V_33 ;
char V_12 [ 64 ] ;
int V_66 ;
if ( V_4 -> V_47 -> V_48 == NULL )
return - V_67 ;
if ( ! F_47 ( V_68 ) && ! F_47 ( V_69 ) )
return - V_70 ;
F_36 ( NULL ) ;
V_66 = snprintf ( V_12 , sizeof( V_12 ) , L_7 , V_4 -> V_12 ) ;
if ( V_66 >= V_71 )
return - V_72 ;
V_33 = F_48 ( sizeof( * V_2 ) , V_12 , V_73 ,
V_74 ) ;
if ( ! V_33 )
return - V_75 ;
V_2 = F_33 ( V_33 ) ;
V_2 -> V_4 = F_49 ( V_4 ) ;
V_2 -> V_33 = V_33 ;
F_2 ( V_2 , V_4 ) ;
V_4 -> V_76 = V_77 ;
V_4 -> V_29 = V_2 ;
F_50 ( V_78 , & V_4 -> V_23 ) ;
F_41 () ;
V_66 = F_51 ( V_33 ) ;
if ( V_66 ) {
F_45 () ;
F_52 ( V_33 ) ;
return - V_79 ;
}
F_37 ( & V_64 ) ;
F_53 ( & V_2 -> V_80 , & V_81 ) ;
F_39 ( & V_64 ) ;
F_45 () ;
F_54 ( V_33 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static void F_55 ( struct V_10 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_29 ;
F_56 ( V_2 -> V_4 ) ;
F_37 ( & V_64 ) ;
F_57 ( & V_2 -> V_80 , & V_65 ) ;
F_39 ( & V_64 ) ;
F_58 ( & V_82 ) ;
}
static int F_59 ( void )
{
int V_66 ;
V_66 = F_60 ( V_83 , & V_84 ) ;
if ( V_66 < 0 ) {
F_61 ( L_8 , V_83 ,
V_66 ) ;
return V_66 ;
}
return V_66 ;
}
static void V_74 ( struct V_57 * V_33 )
{
struct V_1 * V_85 = F_33 ( V_33 ) ;
V_33 -> V_86 = 0 ;
V_33 -> V_87 = & V_87 ;
V_33 -> type = V_88 ;
V_33 -> V_23 = V_89 | V_90 ;
V_33 -> V_91 = V_92 ;
V_33 -> V_93 |= V_94 ;
V_33 -> V_95 = F_52 ;
F_62 ( & V_85 -> V_44 ) ;
V_85 -> V_30 . V_96 = V_97 ;
V_85 -> V_30 . V_98 = true ;
V_85 -> V_30 . V_31 = V_99 ;
V_85 -> V_30 . V_100 = V_101 ;
V_85 -> V_33 = V_33 ;
}
static int F_63 ( struct V_57 * V_33 )
{
F_64 ( V_33 ) ;
return 0 ;
}
static int F_65 ( struct V_57 * V_33 )
{
F_54 ( V_33 ) ;
return 0 ;
}
static int T_2 F_66 ( void )
{
int V_27 ;
V_27 = F_59 () ;
V_13 = F_3 ( L_9 , NULL ) ;
return V_27 ;
}
static void T_3 F_67 ( void )
{
F_37 ( & V_64 ) ;
F_68 ( & V_81 , & V_65 ) ;
F_39 ( & V_64 ) ;
F_36 ( NULL ) ;
F_69 ( & V_82 ) ;
F_70 ( V_83 ) ;
F_9 ( V_13 ) ;
}
