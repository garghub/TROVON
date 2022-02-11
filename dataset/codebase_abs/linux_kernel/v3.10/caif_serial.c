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
V_26 -> V_33 = V_2 -> V_33 ;
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
static int F_36 ( struct V_10 * V_4 )
{
struct V_1 * V_2 ;
struct V_57 * V_33 ;
char V_12 [ 64 ] ;
int V_60 ;
if ( V_4 -> V_47 -> V_48 == NULL )
return - V_61 ;
if ( ! F_37 ( V_62 ) && ! F_37 ( V_63 ) )
return - V_64 ;
sprintf ( V_12 , L_7 , V_4 -> V_12 ) ;
V_33 = F_38 ( sizeof( * V_2 ) , V_12 , V_65 ) ;
if ( ! V_33 )
return - V_66 ;
V_2 = F_33 ( V_33 ) ;
V_2 -> V_4 = F_39 ( V_4 ) ;
V_2 -> V_33 = V_33 ;
F_2 ( V_2 , V_4 ) ;
V_4 -> V_67 = V_68 ;
V_4 -> V_29 = V_2 ;
F_40 ( V_69 , & V_4 -> V_23 ) ;
F_41 () ;
V_60 = F_42 ( V_33 ) ;
if ( V_60 ) {
F_43 () ;
F_44 ( V_33 ) ;
return - V_70 ;
}
F_45 ( & V_2 -> V_71 , & V_72 ) ;
F_43 () ;
F_46 ( V_33 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static void F_47 ( struct V_10 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_29 ;
int V_73 = F_48 () ;
if ( ! V_73 )
F_41 () ;
F_49 ( V_2 -> V_33 ) ;
F_50 ( V_2 -> V_33 ) ;
F_51 ( & V_2 -> V_71 ) ;
F_8 ( V_2 ) ;
F_52 ( V_2 -> V_4 ) ;
if ( ! V_73 )
F_43 () ;
}
static int F_53 ( void )
{
int V_60 ;
V_60 = F_54 ( V_74 , & V_75 ) ;
if ( V_60 < 0 ) {
F_55 ( L_8 , V_74 ,
V_60 ) ;
return V_60 ;
}
return V_60 ;
}
static void V_65 ( struct V_57 * V_33 )
{
struct V_1 * V_76 = F_33 ( V_33 ) ;
V_33 -> V_77 = 0 ;
V_33 -> V_78 = & V_78 ;
V_33 -> type = V_79 ;
V_33 -> V_23 = V_80 | V_81 ;
V_33 -> V_82 = V_83 ;
V_33 -> V_84 = 0 ;
V_33 -> V_85 = F_44 ;
F_56 ( & V_76 -> V_44 ) ;
V_76 -> V_30 . V_86 = V_87 ;
V_76 -> V_30 . V_88 = true ;
V_76 -> V_30 . V_31 = V_89 ;
V_76 -> V_30 . V_90 = V_91 ;
V_76 -> V_33 = V_33 ;
}
static int F_57 ( struct V_57 * V_33 )
{
F_58 ( V_33 ) ;
return 0 ;
}
static int F_59 ( struct V_57 * V_33 )
{
F_46 ( V_33 ) ;
return 0 ;
}
static int T_2 F_60 ( void )
{
int V_27 ;
V_27 = F_53 () ;
V_13 = F_3 ( L_9 , NULL ) ;
return V_27 ;
}
static void T_3 F_61 ( void )
{
struct V_1 * V_2 = NULL ;
struct V_92 * V_71 ;
struct V_92 * V_93 ;
F_62 (node, _tmp, &ser_list) {
V_2 = F_63 ( V_71 , struct V_1 , V_71 ) ;
F_49 ( V_2 -> V_33 ) ;
F_50 ( V_2 -> V_33 ) ;
F_51 ( V_71 ) ;
}
F_64 ( V_74 ) ;
F_9 ( V_13 ) ;
}
