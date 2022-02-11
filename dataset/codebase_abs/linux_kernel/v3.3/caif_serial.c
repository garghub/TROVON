static inline void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 =
V_2 -> V_4 -> V_5 << 5 |
V_2 -> V_4 -> V_6 << 4 |
V_2 -> V_4 -> V_7 << 3 |
V_2 -> V_4 -> V_8 << 2 |
V_2 -> V_4 -> V_9 << 1 |
V_2 -> V_4 -> V_10 ;
}
static inline void F_2 ( struct V_1 * V_2 , struct V_11 * V_4 )
{
V_2 -> V_12 =
F_3 ( V_4 -> V_13 , V_14 ) ;
if ( ! F_4 ( V_2 -> V_12 ) ) {
F_5 ( L_1 , V_15 ,
V_2 -> V_12 ,
& V_2 -> V_16 ) ;
F_5 ( L_2 , V_15 ,
V_2 -> V_12 ,
& V_2 -> V_17 ) ;
F_6 ( L_3 , V_15 ,
V_2 -> V_12 ,
( V_18 * ) & V_2 -> V_19 ) ;
F_7 ( L_4 , V_15 ,
V_2 -> V_12 ,
& V_2 -> V_3 ) ;
}
V_2 -> V_16 . V_20 = V_2 -> V_21 ;
V_2 -> V_16 . V_22 = 0 ;
V_2 -> V_17 . V_20 = V_2 -> V_23 ;
V_2 -> V_17 . V_22 = 0 ;
}
static inline void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_12 ) ;
}
static inline void F_10 ( struct V_1 * V_2 , const T_1 * V_20 , int V_22 )
{
if ( V_22 > sizeof( V_2 -> V_23 ) )
V_22 = sizeof( V_2 -> V_23 ) ;
memcpy ( V_2 -> V_23 , V_20 , V_22 ) ;
V_2 -> V_17 . V_20 = V_2 -> V_23 ;
V_2 -> V_17 . V_22 = V_22 ;
}
static inline void F_11 ( struct V_1 * V_2 , const T_1 * V_20 , int V_22 )
{
if ( V_22 > sizeof( V_2 -> V_21 ) )
V_22 = sizeof( V_2 -> V_21 ) ;
memcpy ( V_2 -> V_21 , V_20 , V_22 ) ;
V_2 -> V_16 . V_20 = V_2 -> V_21 ;
V_2 -> V_16 . V_22 = V_22 ;
}
static inline void F_2 ( struct V_1 * V_2 , struct V_11 * V_4 )
{
}
static inline void F_8 ( struct V_1 * V_2 )
{
}
static inline void F_1 ( struct V_1 * V_2 )
{
}
static inline void F_10 ( struct V_1 * V_2 , const T_1 * V_20 , int V_22 )
{
}
static inline void F_11 ( struct V_1 * V_2 , const T_1 * V_20 , int V_22 )
{
}
static void F_12 ( struct V_11 * V_4 , const T_1 * V_20 ,
char * V_24 , int V_25 )
{
struct V_26 * V_27 = NULL ;
struct V_1 * V_2 ;
int V_28 ;
T_1 * V_29 ;
V_2 = V_4 -> V_30 ;
if ( ! V_2 -> V_31 . V_32 && ! V_2 -> V_33 ) {
F_13 ( & V_2 -> V_34 -> V_34 ,
L_5
L_6 ) ;
return;
}
F_14 ( V_2 -> V_34 == NULL ) ;
V_27 = F_15 ( V_2 -> V_34 , V_25 + 1 ) ;
if ( V_27 == NULL )
return;
V_29 = F_16 ( V_27 , V_25 ) ;
memcpy ( V_29 , V_20 , V_25 ) ;
V_27 -> V_35 = F_17 ( V_36 ) ;
F_18 ( V_27 ) ;
V_27 -> V_34 = V_2 -> V_34 ;
F_10 ( V_2 , V_20 , V_25 ) ;
V_28 = F_19 ( V_27 ) ;
if ( ! V_28 ) {
V_2 -> V_34 -> V_37 . V_38 ++ ;
V_2 -> V_34 -> V_37 . V_39 += V_25 ;
} else
++ V_2 -> V_34 -> V_37 . V_40 ;
F_1 ( V_2 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_11 * V_4 ;
struct V_26 * V_27 ;
int V_41 , V_42 , V_43 ;
V_4 = V_2 -> V_4 ;
V_2 -> V_33 = true ;
if ( F_21 ( V_44 , & V_2 -> V_19 ) )
return 0 ;
while ( ( V_27 = F_22 ( & V_2 -> V_45 ) ) != NULL ) {
V_42 = V_27 -> V_42 ;
V_43 = F_23 ( V_4 ) ;
if ( ! V_43 )
break;
if ( V_43 > V_46 )
V_43 = V_46 ;
if ( V_42 > V_43 )
V_42 = V_43 ;
if ( ! V_47 ) {
V_41 = V_4 -> V_48 -> V_49 ( V_4 , V_27 -> V_20 , V_42 ) ;
F_1 ( V_2 ) ;
} else {
V_41 = V_42 ;
F_12 ( V_4 , V_27 -> V_20 , NULL , V_42 ) ;
}
V_2 -> V_34 -> V_37 . V_50 ++ ;
V_2 -> V_34 -> V_37 . V_51 += V_41 ;
if ( V_41 < 0 )
goto error;
F_24 ( V_27 , V_41 ) ;
if ( V_27 -> V_42 == 0 ) {
struct V_26 * V_52 = F_25 ( & V_2 -> V_45 ) ;
F_26 ( V_52 != V_27 ) ;
if ( F_27 () )
F_28 ( V_27 ) ;
else
F_29 ( V_27 ) ;
}
}
if ( V_2 -> V_45 . V_53 <= V_54 &&
F_30 ( V_55 , & V_2 -> V_19 ) &&
V_2 -> V_31 . V_56 != NULL )
V_2 -> V_31 . V_56 ( V_2 -> V_34 , V_57 ) ;
F_31 ( V_44 , & V_2 -> V_19 ) ;
return 0 ;
error:
F_31 ( V_44 , & V_2 -> V_19 ) ;
return V_41 ;
}
static int F_32 ( struct V_26 * V_27 , struct V_58 * V_34 )
{
struct V_1 * V_2 ;
F_14 ( V_34 == NULL ) ;
V_2 = F_33 ( V_34 ) ;
if ( V_2 -> V_45 . V_53 > V_59 &&
! F_21 ( V_55 , & V_2 -> V_19 ) &&
V_2 -> V_31 . V_56 != NULL )
V_2 -> V_31 . V_56 ( V_2 -> V_34 , V_60 ) ;
F_34 ( & V_2 -> V_45 , V_27 ) ;
return F_20 ( V_2 ) ;
}
static void F_35 ( struct V_11 * V_4 )
{
struct V_1 * V_2 ;
V_2 = V_4 -> V_30 ;
F_14 ( V_2 == NULL ) ;
F_26 ( V_2 -> V_4 != V_4 ) ;
F_20 ( V_2 ) ;
}
static int F_36 ( struct V_11 * V_4 )
{
struct V_1 * V_2 ;
struct V_58 * V_34 ;
char V_13 [ 64 ] ;
int V_61 ;
if ( V_4 -> V_48 -> V_49 == NULL )
return - V_62 ;
if ( ! F_37 ( V_63 ) && ! F_37 ( V_64 ) )
return - V_65 ;
sprintf ( V_13 , L_7 , V_4 -> V_13 ) ;
V_34 = F_38 ( sizeof( * V_2 ) , V_13 , V_66 ) ;
V_2 = F_33 ( V_34 ) ;
V_2 -> V_4 = F_39 ( V_4 ) ;
V_2 -> V_34 = V_34 ;
F_2 ( V_2 , V_4 ) ;
V_4 -> V_67 = V_68 ;
V_4 -> V_30 = V_2 ;
F_40 ( V_69 , & V_4 -> V_24 ) ;
F_41 () ;
V_61 = F_42 ( V_34 ) ;
if ( V_61 ) {
F_43 () ;
F_44 ( V_34 ) ;
return - V_70 ;
}
F_45 ( & V_2 -> V_71 , & V_72 ) ;
F_43 () ;
F_46 ( V_34 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static void F_47 ( struct V_11 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_30 ;
int V_73 = F_48 () ;
if ( ! V_73 )
F_41 () ;
F_49 ( V_2 -> V_34 ) ;
F_50 ( V_2 -> V_34 ) ;
F_51 ( & V_2 -> V_71 ) ;
F_8 ( V_2 ) ;
F_52 ( V_2 -> V_4 ) ;
if ( ! V_73 )
F_43 () ;
}
static int F_53 ( void )
{
int V_61 ;
V_61 = F_54 ( V_74 , & V_75 ) ;
if ( V_61 < 0 ) {
F_55 ( L_8 , V_74 ,
V_61 ) ;
return V_61 ;
}
return V_61 ;
}
static void V_66 ( struct V_58 * V_34 )
{
struct V_1 * V_76 = F_33 ( V_34 ) ;
V_34 -> V_77 = 0 ;
V_34 -> V_78 = & V_78 ;
V_34 -> type = V_79 ;
V_34 -> V_24 = V_80 | V_81 ;
V_34 -> V_82 = V_83 ;
V_34 -> V_84 = 0 ;
V_34 -> V_85 = F_44 ;
F_56 ( & V_76 -> V_45 ) ;
V_76 -> V_31 . V_86 = V_87 ;
V_76 -> V_31 . V_88 = true ;
V_76 -> V_31 . V_32 = V_89 ;
V_76 -> V_31 . V_90 = V_91 ;
V_76 -> V_34 = V_34 ;
}
static int F_57 ( struct V_58 * V_34 )
{
F_58 ( V_34 ) ;
return 0 ;
}
static int F_59 ( struct V_58 * V_34 )
{
F_46 ( V_34 ) ;
return 0 ;
}
static int T_2 F_60 ( void )
{
int V_28 ;
V_28 = F_53 () ;
V_14 = F_3 ( L_9 , NULL ) ;
return V_28 ;
}
static void T_3 F_61 ( void )
{
struct V_1 * V_2 = NULL ;
struct V_92 * V_71 ;
struct V_92 * V_93 ;
F_62 (node, _tmp, &ser_list) {
V_2 = F_63 ( V_71 , struct V_1 , V_71 ) ;
F_49 ( V_2 -> V_34 ) ;
F_50 ( V_2 -> V_34 ) ;
F_51 ( V_71 ) ;
}
F_64 ( V_74 ) ;
F_9 ( V_14 ) ;
}
