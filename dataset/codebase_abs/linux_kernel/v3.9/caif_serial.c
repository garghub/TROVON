static inline void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 =
V_2 -> V_4 -> V_5 << 5 |
V_2 -> V_4 -> V_6 << 4 |
V_2 -> V_4 -> V_7 << 3 |
V_2 -> V_4 -> V_8 << 2 |
V_2 -> V_4 -> V_9 -> V_10 << 1 |
V_2 -> V_4 -> V_11 ;
}
static inline void F_2 ( struct V_1 * V_2 , struct V_12 * V_4 )
{
V_2 -> V_13 =
F_3 ( V_4 -> V_14 , V_15 ) ;
if ( ! F_4 ( V_2 -> V_13 ) ) {
F_5 ( L_1 , V_16 ,
V_2 -> V_13 ,
& V_2 -> V_17 ) ;
F_5 ( L_2 , V_16 ,
V_2 -> V_13 ,
& V_2 -> V_18 ) ;
F_6 ( L_3 , V_16 ,
V_2 -> V_13 ,
( V_19 * ) & V_2 -> V_20 ) ;
F_7 ( L_4 , V_16 ,
V_2 -> V_13 ,
& V_2 -> V_3 ) ;
}
V_2 -> V_17 . V_21 = V_2 -> V_22 ;
V_2 -> V_17 . V_23 = 0 ;
V_2 -> V_18 . V_21 = V_2 -> V_24 ;
V_2 -> V_18 . V_23 = 0 ;
}
static inline void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_13 ) ;
}
static inline void F_10 ( struct V_1 * V_2 , const T_1 * V_21 , int V_23 )
{
if ( V_23 > sizeof( V_2 -> V_24 ) )
V_23 = sizeof( V_2 -> V_24 ) ;
memcpy ( V_2 -> V_24 , V_21 , V_23 ) ;
V_2 -> V_18 . V_21 = V_2 -> V_24 ;
V_2 -> V_18 . V_23 = V_23 ;
}
static inline void F_11 ( struct V_1 * V_2 , const T_1 * V_21 , int V_23 )
{
if ( V_23 > sizeof( V_2 -> V_22 ) )
V_23 = sizeof( V_2 -> V_22 ) ;
memcpy ( V_2 -> V_22 , V_21 , V_23 ) ;
V_2 -> V_17 . V_21 = V_2 -> V_22 ;
V_2 -> V_17 . V_23 = V_23 ;
}
static inline void F_2 ( struct V_1 * V_2 , struct V_12 * V_4 )
{
}
static inline void F_8 ( struct V_1 * V_2 )
{
}
static inline void F_1 ( struct V_1 * V_2 )
{
}
static inline void F_10 ( struct V_1 * V_2 , const T_1 * V_21 , int V_23 )
{
}
static inline void F_11 ( struct V_1 * V_2 , const T_1 * V_21 , int V_23 )
{
}
static void F_12 ( struct V_12 * V_4 , const T_1 * V_21 ,
char * V_25 , int V_26 )
{
struct V_27 * V_28 = NULL ;
struct V_1 * V_2 ;
int V_29 ;
T_1 * V_30 ;
V_2 = V_4 -> V_31 ;
if ( ! V_2 -> V_32 . V_33 && ! V_2 -> V_34 ) {
F_13 ( & V_2 -> V_35 -> V_35 ,
L_5
L_6 ) ;
return;
}
F_14 ( V_2 -> V_35 == NULL ) ;
V_28 = F_15 ( V_2 -> V_35 , V_26 + 1 ) ;
if ( V_28 == NULL )
return;
V_30 = F_16 ( V_28 , V_26 ) ;
memcpy ( V_30 , V_21 , V_26 ) ;
V_28 -> V_36 = F_17 ( V_37 ) ;
F_18 ( V_28 ) ;
V_28 -> V_35 = V_2 -> V_35 ;
F_10 ( V_2 , V_21 , V_26 ) ;
V_29 = F_19 ( V_28 ) ;
if ( ! V_29 ) {
V_2 -> V_35 -> V_38 . V_39 ++ ;
V_2 -> V_35 -> V_38 . V_40 += V_26 ;
} else
++ V_2 -> V_35 -> V_38 . V_41 ;
F_1 ( V_2 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_12 * V_4 ;
struct V_27 * V_28 ;
int V_42 , V_43 , V_44 ;
V_4 = V_2 -> V_4 ;
V_2 -> V_34 = true ;
if ( F_21 ( V_45 , & V_2 -> V_20 ) )
return 0 ;
while ( ( V_28 = F_22 ( & V_2 -> V_46 ) ) != NULL ) {
V_43 = V_28 -> V_43 ;
V_44 = F_23 ( V_4 ) ;
if ( ! V_44 )
break;
if ( V_44 > V_47 )
V_44 = V_47 ;
if ( V_43 > V_44 )
V_43 = V_44 ;
if ( ! V_48 ) {
V_42 = V_4 -> V_49 -> V_50 ( V_4 , V_28 -> V_21 , V_43 ) ;
F_1 ( V_2 ) ;
} else {
V_42 = V_43 ;
F_12 ( V_4 , V_28 -> V_21 , NULL , V_43 ) ;
}
V_2 -> V_35 -> V_38 . V_51 ++ ;
V_2 -> V_35 -> V_38 . V_52 += V_42 ;
if ( V_42 < 0 )
goto error;
F_24 ( V_28 , V_42 ) ;
if ( V_28 -> V_43 == 0 ) {
struct V_27 * V_53 = F_25 ( & V_2 -> V_46 ) ;
F_26 ( V_53 != V_28 ) ;
if ( F_27 () )
F_28 ( V_28 ) ;
else
F_29 ( V_28 ) ;
}
}
if ( V_2 -> V_46 . V_54 <= V_55 &&
F_30 ( V_56 , & V_2 -> V_20 ) &&
V_2 -> V_32 . V_57 != NULL )
V_2 -> V_32 . V_57 ( V_2 -> V_35 , V_58 ) ;
F_31 ( V_45 , & V_2 -> V_20 ) ;
return 0 ;
error:
F_31 ( V_45 , & V_2 -> V_20 ) ;
return V_42 ;
}
static int F_32 ( struct V_27 * V_28 , struct V_59 * V_35 )
{
struct V_1 * V_2 ;
F_14 ( V_35 == NULL ) ;
V_2 = F_33 ( V_35 ) ;
if ( V_2 -> V_46 . V_54 > V_60 &&
! F_21 ( V_56 , & V_2 -> V_20 ) &&
V_2 -> V_32 . V_57 != NULL )
V_2 -> V_32 . V_57 ( V_2 -> V_35 , V_61 ) ;
F_34 ( & V_2 -> V_46 , V_28 ) ;
return F_20 ( V_2 ) ;
}
static void F_35 ( struct V_12 * V_4 )
{
struct V_1 * V_2 ;
V_2 = V_4 -> V_31 ;
F_14 ( V_2 == NULL ) ;
F_26 ( V_2 -> V_4 != V_4 ) ;
F_20 ( V_2 ) ;
}
static int F_36 ( struct V_12 * V_4 )
{
struct V_1 * V_2 ;
struct V_59 * V_35 ;
char V_14 [ 64 ] ;
int V_62 ;
if ( V_4 -> V_49 -> V_50 == NULL )
return - V_63 ;
if ( ! F_37 ( V_64 ) && ! F_37 ( V_65 ) )
return - V_66 ;
sprintf ( V_14 , L_7 , V_4 -> V_14 ) ;
V_35 = F_38 ( sizeof( * V_2 ) , V_14 , V_67 ) ;
if ( ! V_35 )
return - V_68 ;
V_2 = F_33 ( V_35 ) ;
V_2 -> V_4 = F_39 ( V_4 ) ;
V_2 -> V_35 = V_35 ;
F_2 ( V_2 , V_4 ) ;
V_4 -> V_69 = V_70 ;
V_4 -> V_31 = V_2 ;
F_40 ( V_71 , & V_4 -> V_25 ) ;
F_41 () ;
V_62 = F_42 ( V_35 ) ;
if ( V_62 ) {
F_43 () ;
F_44 ( V_35 ) ;
return - V_72 ;
}
F_45 ( & V_2 -> V_73 , & V_74 ) ;
F_43 () ;
F_46 ( V_35 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static void F_47 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_31 ;
int V_75 = F_48 () ;
if ( ! V_75 )
F_41 () ;
F_49 ( V_2 -> V_35 ) ;
F_50 ( V_2 -> V_35 ) ;
F_51 ( & V_2 -> V_73 ) ;
F_8 ( V_2 ) ;
F_52 ( V_2 -> V_4 ) ;
if ( ! V_75 )
F_43 () ;
}
static int F_53 ( void )
{
int V_62 ;
V_62 = F_54 ( V_76 , & V_77 ) ;
if ( V_62 < 0 ) {
F_55 ( L_8 , V_76 ,
V_62 ) ;
return V_62 ;
}
return V_62 ;
}
static void V_67 ( struct V_59 * V_35 )
{
struct V_1 * V_78 = F_33 ( V_35 ) ;
V_35 -> V_79 = 0 ;
V_35 -> V_80 = & V_80 ;
V_35 -> type = V_81 ;
V_35 -> V_25 = V_82 | V_83 ;
V_35 -> V_84 = V_85 ;
V_35 -> V_86 = 0 ;
V_35 -> V_87 = F_44 ;
F_56 ( & V_78 -> V_46 ) ;
V_78 -> V_32 . V_88 = V_89 ;
V_78 -> V_32 . V_90 = true ;
V_78 -> V_32 . V_33 = V_91 ;
V_78 -> V_32 . V_92 = V_93 ;
V_78 -> V_35 = V_35 ;
}
static int F_57 ( struct V_59 * V_35 )
{
F_58 ( V_35 ) ;
return 0 ;
}
static int F_59 ( struct V_59 * V_35 )
{
F_46 ( V_35 ) ;
return 0 ;
}
static int T_2 F_60 ( void )
{
int V_29 ;
V_29 = F_53 () ;
V_15 = F_3 ( L_9 , NULL ) ;
return V_29 ;
}
static void T_3 F_61 ( void )
{
struct V_1 * V_2 = NULL ;
struct V_94 * V_73 ;
struct V_94 * V_95 ;
F_62 (node, _tmp, &ser_list) {
V_2 = F_63 ( V_73 , struct V_1 , V_73 ) ;
F_49 ( V_2 -> V_35 ) ;
F_50 ( V_2 -> V_35 ) ;
F_51 ( V_73 ) ;
}
F_64 ( V_76 ) ;
F_9 ( V_15 ) ;
}
