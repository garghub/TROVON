static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( F_2 ( V_3 , V_4 . V_5 ) ||
! F_3 ( & V_4 ) ) {
F_4 ( & V_4 , V_3 ) ;
F_5 ( V_6 , & V_2 -> V_7 ,
L_1 , V_3 , V_8 ) ;
}
}
static inline T_1 F_6 ( struct V_1 * V_2 )
{
return F_7 ( V_2 -> V_9 ,
F_8 ( V_2 -> V_7 . V_10 ) / 2 ) ;
}
static inline int F_9 ( struct V_1 * V_2 )
{
return F_10 ( F_6 ( V_2 ) , F_11 () ) ;
}
static inline int F_12 ( void )
{
struct V_1 * V_2 = NULL ;
int V_11 = 0 ;
F_13 ( & V_12 ) ;
if ( ! F_14 ( V_13 ) ) {
V_2 = F_15 ( V_13 -> V_14 , struct V_1 ,
V_15 ) ;
V_11 = F_9 ( V_2 ) ;
if ( ! V_11 )
F_1 ( V_2 , F_6 ( V_2 ) ) ;
} else if ( ! F_14 ( & V_16 ) ) {
V_2 = F_15 ( V_16 . V_14 , struct V_1 ,
V_15 ) ;
V_11 = F_16 ( V_2 ) ;
if ( ! V_11 )
F_1 ( V_2 , V_2 -> V_9 ) ;
}
F_17 ( & V_12 ) ;
if ( V_11 )
F_5 ( V_6 , & V_2 -> V_7 , L_2 ) ;
return V_11 ;
}
static void F_18 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_1 * V_19 ;
struct V_17 * V_20 = NULL ;
F_19 (tmp, head, c_list) {
if ( F_20 ( V_2 -> V_9 , V_19 -> V_9 ) ) {
V_20 = & V_19 -> V_15 ;
break;
}
}
F_21 ( & V_2 -> V_15 != V_20 ) ;
F_22 ( & V_2 -> V_15 , V_20 ? : V_18 ) ;
}
static inline int F_23 ( struct V_1 * V_21 )
{
struct V_22 * V_23 = F_24 ( V_21 -> V_24 . V_25 . V_26 ) ;
return F_25 ( & V_23 -> V_27 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_24 ( V_2 -> V_24 . V_25 . V_26 ) ;
if ( F_27 ( & V_2 -> V_7 ) ) {
F_21 ( V_23 -> V_28 == V_2 ) ;
V_23 -> V_28 = NULL ;
} else if ( F_28 ( & V_2 -> V_7 ) ) {
F_29 ( & V_2 -> V_24 . V_25 . V_29 ) ;
}
F_5 ( V_6 , & V_2 -> V_7 , L_3 ) ;
F_29 ( & V_2 -> V_15 ) ;
V_30 [ V_31 ] -- ;
F_30 ( V_2 ) ;
}
static int F_31 ( void * V_32 )
{
struct V_1 * V_2 , * V_19 , * V_14 ;
struct V_26 * V_26 = NULL ;
struct V_33 V_34 = { 0 } ;
int V_35 ;
F_32 ( & V_36 , V_37 ) ;
F_33 ( & V_36 . V_38 ) ;
while ( 1 ) {
F_34 ( V_36 . V_38 ,
! F_35 ( & V_36 ) ||
F_12 () ,
& V_34 ) ;
if ( ! F_35 ( & V_36 ) )
break;
V_14 = NULL ;
F_13 ( & V_12 ) ;
F_36 (ocapa, tmp, ll_capa_list, c_list) {
T_2 V_39 ;
F_21 ( V_2 -> V_7 . V_40 != V_41 ) ;
if ( ! F_9 ( V_2 ) ) {
V_14 = V_2 ;
break;
}
F_29 ( & V_2 -> V_15 ) ;
V_39 = V_42 ;
if ( F_27 ( & V_2 -> V_7 ) &&
! F_37 ( V_2 -> V_24 . V_25 . V_26 -> V_43 ) &&
F_23 ( V_2 ) == 0 &&
! F_38 ( V_2 -> V_24 . V_25 . V_26 ,
& V_39 , V_44 ) ) {
F_5 ( V_6 , & V_2 -> V_7 ,
L_4 ) ;
F_18 ( V_2 , & V_16 ) ;
continue;
}
if ( F_28 ( & V_2 -> V_7 ) &&
F_23 ( V_2 ) == 0 ) {
F_18 ( V_2 , & V_16 ) ;
continue;
}
V_26 = F_39 ( V_2 -> V_24 . V_25 . V_26 ) ;
if ( V_26 == NULL ) {
F_5 ( V_45 , & V_2 -> V_7 ,
L_5 ) ;
continue;
}
F_40 ( V_2 ) ;
V_46 ++ ;
F_17 ( & V_12 ) ;
V_35 = F_41 ( F_42 ( V_26 ) , V_2 ,
V_47 ) ;
F_13 ( & V_12 ) ;
if ( V_35 ) {
F_5 ( V_45 , & V_2 -> V_7 ,
L_6 , V_35 ) ;
V_48 ++ ;
}
}
if ( V_14 )
F_1 ( V_14 , F_6 ( V_14 ) ) ;
F_36 (ocapa, tmp, &ll_idle_capas,
c_list) {
if ( ! F_16 ( V_2 ) ) {
if ( ! V_14 )
F_1 ( V_2 ,
V_2 -> V_9 ) ;
break;
}
if ( F_25 ( & V_2 -> V_49 ) > 1 ) {
F_5 ( V_6 , & V_2 -> V_7 ,
L_7 ,
F_25 ( & V_2 -> V_49 ) ) ;
F_29 ( & V_2 -> V_15 ) ;
continue;
}
F_5 ( V_6 , & V_2 -> V_7 , L_8 ) ;
F_26 ( V_2 ) ;
}
F_17 ( & V_12 ) ;
}
F_32 ( & V_36 , V_50 ) ;
F_33 ( & V_36 . V_38 ) ;
return 0 ;
}
void F_43 ( unsigned long V_32 )
{
F_33 ( & V_36 . V_38 ) ;
}
int F_44 ( void )
{
struct V_51 * V_52 ;
F_45 ( & V_36 . V_38 ) ;
V_52 = F_46 ( F_31 , NULL , L_9 ) ;
if ( F_47 ( V_52 ) ) {
F_48 ( L_10 ,
F_49 ( V_52 ) ) ;
return F_49 ( V_52 ) ;
}
F_50 ( V_36 . V_38 ,
F_35 ( & V_36 ) ) ;
return 0 ;
}
void F_51 ( void )
{
F_32 ( & V_36 , V_53 ) ;
F_33 ( & V_36 . V_38 ) ;
F_50 ( V_36 . V_38 ,
F_52 ( & V_36 ) ) ;
}
struct V_1 * F_53 ( struct V_26 * V_26 , T_2 V_54 )
{
struct V_22 * V_23 = F_24 ( V_26 ) ;
struct V_1 * V_2 ;
int V_55 = 0 ;
if ( ( F_54 ( V_26 ) -> V_56 & V_57 ) == 0 )
return NULL ;
F_21 ( V_54 == V_58 || V_54 == V_59 ||
V_54 == V_41 ) ;
F_13 ( & V_12 ) ;
F_55 (ocapa, &lli->lli_oss_capas, u.cli.lli_list) {
if ( F_16 ( V_2 ) )
continue;
if ( ( V_54 & V_58 ) &&
F_56 ( & V_2 -> V_7 , V_58 ) ) {
V_55 = 1 ;
break;
} else if ( ( V_54 & V_60 ) &&
F_56 ( & V_2 -> V_7 ,
V_60 ) ) {
V_55 = 1 ;
break;
} else if ( ( V_54 & V_41 ) &&
F_56 ( & V_2 -> V_7 , V_54 ) ) {
V_55 = 1 ;
break;
}
}
if ( V_55 ) {
F_21 ( F_57 ( F_58 ( & V_2 -> V_7 ) ,
F_59 ( V_26 ) ) ) ;
F_21 ( V_2 -> V_61 == V_31 ) ;
F_40 ( V_2 ) ;
F_5 ( V_6 , & V_2 -> V_7 , L_11 ) ;
} else {
V_2 = NULL ;
if ( F_25 ( & V_62 ) ) {
F_48 ( L_12 V_63 L_13 V_64 L_14 ,
F_60 ( & V_23 -> V_65 ) , V_54 ) ;
F_61 ( & V_62 , 0 ) ;
}
}
F_17 ( & V_12 ) ;
return V_2 ;
}
struct V_1 * F_62 ( struct V_26 * V_26 )
{
struct V_22 * V_23 = F_24 ( V_26 ) ;
struct V_1 * V_2 ;
F_21 ( V_26 != NULL ) ;
if ( ( F_54 ( V_26 ) -> V_56 & V_66 ) == 0 )
return NULL ;
F_13 ( & V_12 ) ;
V_2 = F_40 ( V_23 -> V_28 ) ;
F_17 ( & V_12 ) ;
if ( ! V_2 && F_25 ( & V_62 ) ) {
F_48 ( L_15 V_63 L_14 , F_60 ( & V_23 -> V_65 ) ) ;
F_61 ( & V_62 , 0 ) ;
}
return V_2 ;
}
static struct V_1 * F_63 ( struct V_26 * V_26 ,
struct V_1 * V_2 )
{
struct V_22 * V_23 = F_24 ( V_26 ) ;
struct V_1 * V_67 = V_23 -> V_28 ;
struct V_68 * V_69 = & V_2 -> V_7 ;
if ( ! V_67 ) {
V_2 -> V_24 . V_25 . V_26 = V_26 ;
V_23 -> V_28 = V_2 ;
V_30 [ V_31 ] ++ ;
F_5 ( V_6 , V_69 , L_16 ) ;
} else {
F_13 ( & V_67 -> V_70 ) ;
V_67 -> V_7 = * V_69 ;
F_17 ( & V_67 -> V_70 ) ;
F_5 ( V_6 , V_69 , L_17 ) ;
F_30 ( V_2 ) ;
V_2 = V_67 ;
}
return V_2 ;
}
static struct V_1 * F_64 ( struct V_26 * V_26 , int V_54 )
{
struct V_22 * V_23 = F_24 ( V_26 ) ;
struct V_1 * V_2 ;
F_55 (ocapa, &lli->lli_oss_capas, u.cli.lli_list) {
if ( ( F_65 ( & V_2 -> V_7 ) & V_54 ) != V_54 )
continue;
F_21 ( F_57 ( F_58 ( & V_2 -> V_7 ) ,
F_59 ( V_26 ) ) ) ;
F_21 ( V_2 -> V_61 == V_31 ) ;
F_5 ( V_6 , & V_2 -> V_7 , L_11 ) ;
return V_2 ;
}
return NULL ;
}
static inline void F_66 ( struct V_26 * V_26 ,
struct V_1 * V_2 )
{
struct V_22 * V_23 = F_24 ( V_26 ) ;
struct V_1 * V_19 ;
struct V_17 * V_14 = NULL ;
F_55 (tmp, &lli->lli_oss_capas, u.cli.lli_list) {
if ( F_67 ( V_2 -> V_9 , V_19 -> V_9 ) ) {
V_14 = & V_19 -> V_24 . V_25 . V_29 ;
break;
}
}
F_21 ( & V_2 -> V_24 . V_25 . V_29 != V_14 ) ;
F_68 ( & V_2 -> V_24 . V_25 . V_29 , V_14 ? : & V_23 -> V_71 ) ;
}
static struct V_1 * F_69 ( struct V_26 * V_26 ,
struct V_1 * V_2 )
{
struct V_1 * V_67 ;
struct V_68 * V_69 = & V_2 -> V_7 ;
F_70 ( F_71 ( V_26 -> V_43 ) ,
L_18 ,
V_26 -> V_43 ) ;
V_67 = F_64 ( V_26 , F_65 ( V_69 ) & V_72 ) ;
if ( ! V_67 ) {
V_2 -> V_24 . V_25 . V_26 = V_26 ;
F_72 ( & V_2 -> V_24 . V_25 . V_29 ) ;
V_30 [ V_31 ] ++ ;
F_5 ( V_6 , V_69 , L_19 ) ;
} else {
F_13 ( & V_67 -> V_70 ) ;
V_67 -> V_7 = * V_69 ;
F_17 ( & V_67 -> V_70 ) ;
F_5 ( V_6 , V_69 , L_20 ) ;
F_30 ( V_2 ) ;
V_2 = V_67 ;
}
F_66 ( V_26 , V_2 ) ;
return V_2 ;
}
struct V_1 * F_73 ( struct V_26 * V_26 , struct V_1 * V_2 )
{
F_13 ( & V_12 ) ;
V_2 = F_27 ( & V_2 -> V_7 ) ? F_63 ( V_26 , V_2 ) :
F_69 ( V_26 , V_2 ) ;
if ( V_2 -> V_7 . V_40 != V_41 ) {
F_74 ( V_2 ) ;
F_29 ( & V_2 -> V_15 ) ;
F_18 ( V_2 , V_13 ) ;
F_1 ( V_2 , F_6 ( V_2 ) ) ;
}
F_17 ( & V_12 ) ;
F_61 ( & V_62 , 1 ) ;
return V_2 ;
}
static inline void F_75 ( struct V_1 * V_21 , T_1 V_73 )
{
V_21 -> V_9 = F_76 ( V_21 -> V_9 , F_8 ( V_73 ) ) ;
}
int V_47 ( struct V_1 * V_2 , struct V_68 * V_69 )
{
struct V_26 * V_26 = V_2 -> V_24 . V_25 . V_26 ;
int V_35 = 0 ;
F_21 ( V_2 ) ;
if ( F_47 ( V_69 ) ) {
V_35 = F_49 ( V_69 ) ;
F_13 ( & V_12 ) ;
if ( V_35 == - V_74 ) {
F_5 ( V_6 , & V_2 -> V_7 ,
L_21 ) ;
V_75 ++ ;
} else {
V_48 ++ ;
if ( V_35 == - V_76 && ! F_16 ( V_2 ) ) {
F_75 ( V_2 , 120 ) ;
F_5 ( V_45 , & V_2 -> V_7 ,
L_22
L_23 ) ;
V_77 ++ ;
GOTO ( V_78 , V_35 ) ;
} else {
F_5 ( V_45 , & V_2 -> V_7 ,
L_24 , V_35 ) ;
}
}
F_29 ( & V_2 -> V_15 ) ;
F_18 ( V_2 , & V_16 ) ;
F_17 ( & V_12 ) ;
F_30 ( V_2 ) ;
F_77 ( V_26 ) ;
return V_35 ;
}
F_13 ( & V_2 -> V_70 ) ;
F_21 ( ! memcmp ( & V_2 -> V_7 , V_69 ,
F_78 ( struct V_68 , V_40 ) ) ) ;
V_2 -> V_7 = * V_69 ;
F_74 ( V_2 ) ;
F_17 ( & V_2 -> V_70 ) ;
F_13 ( & V_12 ) ;
if ( F_28 ( V_69 ) )
F_66 ( V_26 , V_2 ) ;
F_5 ( V_6 , V_69 , L_25 ) ;
V_78:
F_29 ( & V_2 -> V_15 ) ;
F_18 ( V_2 , V_13 ) ;
F_1 ( V_2 , F_6 ( V_2 ) ) ;
F_17 ( & V_12 ) ;
F_30 ( V_2 ) ;
F_77 ( V_26 ) ;
return V_35 ;
}
void F_79 ( struct V_26 * V_26 )
{
struct V_22 * V_23 = F_24 ( V_26 ) ;
if ( ( F_54 ( V_26 ) -> V_56 & ( V_66 | V_57 ) )
== 0 )
return;
if ( ! F_71 ( V_26 -> V_43 ) )
return;
F_80 ( & V_23 -> V_27 ) ;
}
void F_81 ( struct V_26 * V_26 )
{
struct V_22 * V_23 = F_24 ( V_26 ) ;
if ( ( F_54 ( V_26 ) -> V_56 & ( V_66 | V_57 ) )
== 0 )
return;
if ( ! F_71 ( V_26 -> V_43 ) )
return;
F_82 ( & V_23 -> V_27 ) ;
}
void F_83 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_21 ( V_2 -> V_7 . V_40 & V_41 ) ;
F_5 ( V_6 , & V_2 -> V_7 , L_26 ) ;
F_30 ( V_2 ) ;
if ( F_84 ( V_2 -> V_7 . V_40 == V_41 ) ) {
F_13 ( & V_12 ) ;
F_26 ( V_2 ) ;
F_17 ( & V_12 ) ;
}
}
void F_85 ( struct V_26 * V_26 )
{
struct V_22 * V_23 = F_24 ( V_26 ) ;
struct V_1 * V_2 , * V_19 ;
F_13 ( & V_12 ) ;
V_2 = V_23 -> V_28 ;
if ( V_2 )
F_26 ( V_2 ) ;
F_36 (ocapa, tmp, &lli->lli_oss_capas,
u.cli.lli_list)
F_26 ( V_2 ) ;
F_17 ( & V_12 ) ;
}
void F_86 ( struct V_79 * V_80 )
{
if ( V_80 -> V_56 & ( V_66 | V_57 ) )
F_87 ( L_27
L_28
L_29
L_30 ,
V_46 , V_75 ,
V_48 , V_77 ) ;
}
