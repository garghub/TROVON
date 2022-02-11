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
V_2 = V_4 -> V_28 ;
if ( ! V_2 -> V_29 . V_30 && ! V_2 -> V_31 ) {
F_13 ( & V_2 -> V_32 -> V_32 ,
L_5
L_6 ) ;
return;
}
F_14 ( V_2 -> V_32 == NULL ) ;
V_26 = F_15 ( V_2 -> V_32 , V_24 + 1 ) ;
if ( V_26 == NULL )
return;
F_16 ( V_26 , V_19 , V_24 ) ;
V_26 -> V_33 = F_17 ( V_34 ) ;
F_18 ( V_26 ) ;
F_10 ( V_2 , V_19 , V_24 ) ;
V_27 = F_19 ( V_26 ) ;
if ( ! V_27 ) {
V_2 -> V_32 -> V_35 . V_36 ++ ;
V_2 -> V_32 -> V_35 . V_37 += V_24 ;
} else
++ V_2 -> V_32 -> V_35 . V_38 ;
F_1 ( V_2 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_10 * V_4 ;
struct V_25 * V_26 ;
int V_39 , V_40 , V_41 ;
V_4 = V_2 -> V_4 ;
V_2 -> V_31 = true ;
if ( F_21 ( V_42 , & V_2 -> V_18 ) )
return 0 ;
while ( ( V_26 = F_22 ( & V_2 -> V_43 ) ) != NULL ) {
V_40 = V_26 -> V_40 ;
V_41 = F_23 ( V_4 ) ;
if ( ! V_41 )
break;
if ( V_41 > V_44 )
V_41 = V_44 ;
if ( V_40 > V_41 )
V_40 = V_41 ;
if ( ! V_45 ) {
V_39 = V_4 -> V_46 -> V_47 ( V_4 , V_26 -> V_19 , V_40 ) ;
F_1 ( V_2 ) ;
} else {
V_39 = V_40 ;
F_12 ( V_4 , V_26 -> V_19 , NULL , V_40 ) ;
}
V_2 -> V_32 -> V_35 . V_48 ++ ;
V_2 -> V_32 -> V_35 . V_49 += V_39 ;
if ( V_39 < 0 )
goto error;
F_24 ( V_26 , V_39 ) ;
if ( V_26 -> V_40 == 0 ) {
struct V_25 * V_50 = F_25 ( & V_2 -> V_43 ) ;
F_26 ( V_50 != V_26 ) ;
if ( F_27 () )
F_28 ( V_26 ) ;
else
F_29 ( V_26 ) ;
}
}
if ( V_2 -> V_43 . V_51 <= V_52 &&
F_30 ( V_53 , & V_2 -> V_18 ) &&
V_2 -> V_29 . V_54 != NULL )
V_2 -> V_29 . V_54 ( V_2 -> V_32 , V_55 ) ;
F_31 ( V_42 , & V_2 -> V_18 ) ;
return 0 ;
error:
F_31 ( V_42 , & V_2 -> V_18 ) ;
return V_39 ;
}
static int F_32 ( struct V_25 * V_26 , struct V_56 * V_32 )
{
struct V_1 * V_2 ;
F_14 ( V_32 == NULL ) ;
V_2 = F_33 ( V_32 ) ;
if ( V_2 -> V_43 . V_51 > V_57 &&
! F_21 ( V_53 , & V_2 -> V_18 ) &&
V_2 -> V_29 . V_54 != NULL )
V_2 -> V_29 . V_54 ( V_2 -> V_32 , V_58 ) ;
F_34 ( & V_2 -> V_43 , V_26 ) ;
return F_20 ( V_2 ) ;
}
static void F_35 ( struct V_10 * V_4 )
{
struct V_1 * V_2 ;
V_2 = V_4 -> V_28 ;
F_14 ( V_2 == NULL ) ;
F_26 ( V_2 -> V_4 != V_4 ) ;
F_20 ( V_2 ) ;
}
static void F_36 ( struct V_59 * V_60 )
{
struct V_61 V_62 ;
struct V_1 * V_2 , * V_50 ;
F_37 ( & V_63 ) ;
F_38 ( & V_64 , & V_62 ) ;
F_39 ( & V_63 ) ;
if ( ! F_40 ( & V_62 ) ) {
F_41 () ;
F_42 (ser, tmp, &list, node) {
F_43 ( V_2 -> V_32 ) ;
F_44 ( V_2 -> V_32 ) ;
F_8 ( V_2 ) ;
}
F_45 () ;
}
}
static int F_46 ( struct V_10 * V_4 )
{
struct V_1 * V_2 ;
struct V_56 * V_32 ;
char V_12 [ 64 ] ;
int V_65 ;
if ( V_4 -> V_46 -> V_47 == NULL )
return - V_66 ;
if ( ! F_47 ( V_67 ) && ! F_47 ( V_68 ) )
return - V_69 ;
F_36 ( NULL ) ;
V_65 = snprintf ( V_12 , sizeof( V_12 ) , L_7 , V_4 -> V_12 ) ;
if ( V_65 >= V_70 )
return - V_71 ;
V_32 = F_48 ( sizeof( * V_2 ) , V_12 , V_72 ,
V_73 ) ;
if ( ! V_32 )
return - V_74 ;
V_2 = F_33 ( V_32 ) ;
V_2 -> V_4 = F_49 ( V_4 ) ;
V_2 -> V_32 = V_32 ;
F_2 ( V_2 , V_4 ) ;
V_4 -> V_75 = V_76 ;
V_4 -> V_28 = V_2 ;
F_50 ( V_77 , & V_4 -> V_23 ) ;
F_41 () ;
V_65 = F_51 ( V_32 ) ;
if ( V_65 ) {
F_45 () ;
F_52 ( V_32 ) ;
return - V_78 ;
}
F_37 ( & V_63 ) ;
F_53 ( & V_2 -> V_79 , & V_80 ) ;
F_39 ( & V_63 ) ;
F_45 () ;
F_54 ( V_32 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static void F_55 ( struct V_10 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_28 ;
F_56 ( V_2 -> V_4 ) ;
F_37 ( & V_63 ) ;
F_57 ( & V_2 -> V_79 , & V_64 ) ;
F_39 ( & V_63 ) ;
F_58 ( & V_81 ) ;
}
static int F_59 ( void )
{
int V_65 ;
V_65 = F_60 ( V_82 , & V_83 ) ;
if ( V_65 < 0 ) {
F_61 ( L_8 , V_82 ,
V_65 ) ;
return V_65 ;
}
return V_65 ;
}
static void V_73 ( struct V_56 * V_32 )
{
struct V_1 * V_84 = F_33 ( V_32 ) ;
V_32 -> V_85 = 0 ;
V_32 -> V_86 = & V_86 ;
V_32 -> type = V_87 ;
V_32 -> V_23 = V_88 | V_89 ;
V_32 -> V_90 = V_91 ;
V_32 -> V_92 |= V_93 ;
V_32 -> V_94 = true ;
F_62 ( & V_84 -> V_43 ) ;
V_84 -> V_29 . V_95 = V_96 ;
V_84 -> V_29 . V_97 = true ;
V_84 -> V_29 . V_30 = V_98 ;
V_84 -> V_29 . V_99 = V_100 ;
V_84 -> V_32 = V_32 ;
}
static int F_63 ( struct V_56 * V_32 )
{
F_64 ( V_32 ) ;
return 0 ;
}
static int F_65 ( struct V_56 * V_32 )
{
F_54 ( V_32 ) ;
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
F_37 ( & V_63 ) ;
F_68 ( & V_80 , & V_64 ) ;
F_39 ( & V_63 ) ;
F_36 ( NULL ) ;
F_69 ( & V_81 ) ;
F_70 ( V_82 ) ;
F_9 ( V_13 ) ;
}
