static void F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_8 , V_9 ;
int V_10 ;
if ( F_3 ( V_2 ) -> V_11 >= 6 ) {
V_8 = F_4 ( V_3 ) ;
V_9 = F_5 ( V_3 ) ;
V_10 = V_12 ;
} else {
V_8 = F_6 ( V_3 ) ;
V_9 = F_7 ( V_3 ) ;
V_10 = V_13 ;
}
F_8 ( V_8 , 0 ) ;
F_9 ( V_8 ) ;
if ( V_5 ) {
T_2 V_14 = F_10 ( V_5 ) ;
T_3 V_15 ;
if ( V_5 -> V_16 != V_17 ) {
T_4 V_18 = V_5 -> V_19 *
( V_5 -> V_16 == V_20 ? 32 : 8 ) ;
V_14 = ( V_14 / V_18 ) * V_18 ;
}
V_15 = ( T_3 ) ( ( F_11 ( V_5 ) + V_14 - 4096 ) &
0xfffff000 ) << 32 ;
V_15 |= F_11 ( V_5 ) & 0xfffff000 ;
V_15 |= ( T_3 ) ( ( V_5 -> V_19 / 128 ) - 1 ) << V_10 ;
if ( V_5 -> V_16 == V_20 )
V_15 |= 1 << V_21 ;
V_15 |= V_22 ;
F_8 ( V_9 , V_15 >> 32 ) ;
F_9 ( V_9 ) ;
F_8 ( V_8 , V_15 ) ;
F_9 ( V_8 ) ;
} else {
F_8 ( V_9 , 0 ) ;
F_9 ( V_9 ) ;
}
}
static void F_12 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_2 V_15 ;
if ( V_5 ) {
T_2 V_14 = F_10 ( V_5 ) ;
int V_23 ;
int V_24 ;
F_13 ( ( F_11 ( V_5 ) & ~ V_25 ) ||
( V_14 & - V_14 ) != V_14 ||
( F_11 ( V_5 ) & ( V_14 - 1 ) ) ,
L_1 ,
F_11 ( V_5 ) , V_5 -> V_26 , V_14 ) ;
if ( V_5 -> V_16 == V_20 && F_14 ( V_2 ) )
V_24 = 128 ;
else
V_24 = 512 ;
V_23 = V_5 -> V_19 / V_24 ;
V_23 = F_15 ( V_23 ) - 1 ;
V_15 = F_11 ( V_5 ) ;
if ( V_5 -> V_16 == V_20 )
V_15 |= 1 << V_27 ;
V_15 |= F_16 ( V_14 ) ;
V_15 |= V_23 << V_28 ;
V_15 |= V_29 ;
} else
V_15 = 0 ;
F_8 ( F_17 ( V_3 ) , V_15 ) ;
F_9 ( F_17 ( V_3 ) ) ;
}
static void F_18 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_4 V_15 ;
if ( V_5 ) {
T_2 V_14 = F_10 ( V_5 ) ;
T_4 V_23 ;
F_13 ( ( F_11 ( V_5 ) & ~ V_30 ) ||
( V_14 & - V_14 ) != V_14 ||
( F_11 ( V_5 ) & ( V_14 - 1 ) ) ,
L_2 ,
F_11 ( V_5 ) , V_14 ) ;
V_23 = V_5 -> V_19 / 128 ;
V_23 = F_15 ( V_23 ) - 1 ;
V_15 = F_11 ( V_5 ) ;
if ( V_5 -> V_16 == V_20 )
V_15 |= 1 << V_27 ;
V_15 |= F_19 ( V_14 ) ;
V_15 |= V_23 << V_28 ;
V_15 |= V_29 ;
} else
V_15 = 0 ;
F_8 ( F_17 ( V_3 ) , V_15 ) ;
F_9 ( F_17 ( V_3 ) ) ;
}
inline static bool F_20 ( struct V_4 * V_5 )
{
return V_5 && V_5 -> V_31 . V_32 & V_33 ;
}
static void F_21 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( F_20 ( V_7 -> V_34 [ V_3 ] . V_5 ) )
F_22 () ;
F_13 ( V_5 && ( ! V_5 -> V_19 || ! V_5 -> V_16 ) ,
L_3 ,
V_5 -> V_19 , V_5 -> V_16 ) ;
if ( F_23 ( V_2 ) )
F_18 ( V_2 , V_3 , V_5 ) ;
else if ( F_24 ( V_2 ) )
F_12 ( V_2 , V_3 , V_5 ) ;
else if ( F_3 ( V_2 ) -> V_11 >= 4 )
F_1 ( V_2 , V_3 , V_5 ) ;
if ( F_20 ( V_5 ) )
F_22 () ;
}
static inline int F_25 ( struct V_6 * V_7 ,
struct V_35 * V_36 )
{
return V_36 - V_7 -> V_34 ;
}
static void F_26 ( struct V_4 * V_5 ,
struct V_35 * V_36 ,
bool V_37 )
{
struct V_6 * V_7 = F_2 ( V_5 -> V_31 . V_2 ) ;
int V_3 = F_25 ( V_7 , V_36 ) ;
F_21 ( V_5 -> V_31 . V_2 , V_3 , V_37 ? V_5 : NULL ) ;
if ( V_37 ) {
V_5 -> V_38 = V_3 ;
V_36 -> V_5 = V_5 ;
F_27 ( & V_36 -> V_39 , & V_7 -> V_40 . V_41 ) ;
} else {
V_5 -> V_38 = V_42 ;
V_36 -> V_5 = NULL ;
F_28 ( & V_36 -> V_39 ) ;
}
V_5 -> V_43 = false ;
}
static inline void F_29 ( struct V_4 * V_5 )
{
if ( V_5 -> V_16 )
F_30 ( V_5 ) ;
V_5 -> V_43 = false ;
V_5 -> V_38 = V_42 ;
}
static int
F_31 ( struct V_4 * V_5 )
{
if ( V_5 -> V_44 ) {
int V_45 = F_32 ( V_5 -> V_44 ) ;
if ( V_45 )
return V_45 ;
F_33 ( & V_5 -> V_44 , NULL ) ;
}
return 0 ;
}
int
F_34 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 -> V_31 . V_2 ) ;
struct V_35 * V_36 ;
int V_45 ;
V_45 = F_31 ( V_5 ) ;
if ( V_45 )
return V_45 ;
if ( V_5 -> V_38 == V_42 )
return 0 ;
V_36 = & V_7 -> V_34 [ V_5 -> V_38 ] ;
if ( F_35 ( V_36 -> V_46 ) )
return - V_47 ;
F_29 ( V_5 ) ;
F_26 ( V_5 , V_36 , false ) ;
return 0 ;
}
static struct V_35 *
F_36 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_35 * V_3 , * V_48 ;
int V_49 ;
V_48 = NULL ;
for ( V_49 = 0 ; V_49 < V_7 -> V_50 ; V_49 ++ ) {
V_3 = & V_7 -> V_34 [ V_49 ] ;
if ( ! V_3 -> V_5 )
return V_3 ;
if ( ! V_3 -> V_46 )
V_48 = V_3 ;
}
if ( V_48 == NULL )
goto V_51;
F_37 (reg, &dev_priv->mm.fence_list, lru_list) {
if ( V_3 -> V_46 )
continue;
return V_3 ;
}
V_51:
if ( F_38 ( V_2 ) )
return F_39 ( - V_52 ) ;
return F_39 ( - V_53 ) ;
}
int
F_40 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_31 . V_2 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
bool V_37 = V_5 -> V_16 != V_17 ;
struct V_35 * V_3 ;
int V_45 ;
if ( V_5 -> V_43 ) {
V_45 = F_31 ( V_5 ) ;
if ( V_45 )
return V_45 ;
}
if ( V_5 -> V_38 != V_42 ) {
V_3 = & V_7 -> V_34 [ V_5 -> V_38 ] ;
if ( ! V_5 -> V_43 ) {
F_27 ( & V_3 -> V_39 ,
& V_7 -> V_40 . V_41 ) ;
return 0 ;
}
} else if ( V_37 ) {
if ( F_35 ( ! V_5 -> V_26 ) )
return - V_54 ;
V_3 = F_36 ( V_2 ) ;
if ( F_41 ( V_3 ) )
return F_42 ( V_3 ) ;
if ( V_3 -> V_5 ) {
struct V_4 * V_55 = V_3 -> V_5 ;
V_45 = F_31 ( V_55 ) ;
if ( V_45 )
return V_45 ;
F_29 ( V_55 ) ;
}
} else
return 0 ;
F_26 ( V_5 , V_3 , V_37 ) ;
return 0 ;
}
bool
F_43 ( struct V_4 * V_5 )
{
if ( V_5 -> V_38 != V_42 ) {
struct V_6 * V_7 = F_2 ( V_5 -> V_31 . V_2 ) ;
struct V_56 * V_57 = F_44 ( V_5 ) ;
F_35 ( ! V_57 ||
V_7 -> V_34 [ V_5 -> V_38 ] . V_46 >
V_57 -> V_46 ) ;
V_7 -> V_34 [ V_5 -> V_38 ] . V_46 ++ ;
return true ;
} else
return false ;
}
void
F_45 ( struct V_4 * V_5 )
{
if ( V_5 -> V_38 != V_42 ) {
struct V_6 * V_7 = F_2 ( V_5 -> V_31 . V_2 ) ;
F_35 ( V_7 -> V_34 [ V_5 -> V_38 ] . V_46 <= 0 ) ;
V_7 -> V_34 [ V_5 -> V_38 ] . V_46 -- ;
}
}
void F_46 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_7 -> V_50 ; V_49 ++ ) {
struct V_35 * V_3 = & V_7 -> V_34 [ V_49 ] ;
if ( V_3 -> V_5 ) {
F_26 ( V_3 -> V_5 , V_3 ,
V_3 -> V_5 -> V_16 ) ;
} else {
F_21 ( V_2 , V_49 , NULL ) ;
}
}
}
void
F_47 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_4 V_58 = V_59 ;
T_4 V_60 = V_59 ;
if ( F_3 ( V_2 ) -> V_11 >= 8 || F_48 ( V_2 ) ) {
V_58 = V_61 ;
V_60 = V_61 ;
} else if ( F_3 ( V_2 ) -> V_11 >= 6 ) {
if ( V_7 -> V_62 ) {
if ( F_49 ( V_63 ) &
V_64 ) {
V_58 = V_65 ;
V_60 = V_66 ;
} else {
V_58 = V_61 ;
V_60 = V_61 ;
}
} else {
T_4 V_67 , V_68 ;
V_67 = F_49 ( V_69 ) ;
V_68 = F_49 ( V_70 ) ;
V_67 &= V_71 | V_72 ;
V_68 &= V_71 | V_72 ;
if ( V_67 == V_68 ) {
V_58 = V_65 ;
V_60 = V_66 ;
} else {
V_58 = V_61 ;
V_60 = V_61 ;
}
}
} else if ( F_50 ( V_2 ) ) {
V_58 = V_65 ;
V_60 = V_66 ;
} else if ( F_23 ( V_2 ) ) {
V_58 = V_61 ;
V_60 = V_61 ;
} else if ( F_51 ( V_2 ) || ( F_24 ( V_2 ) && ! F_52 ( V_2 ) ) ) {
T_4 V_73 ;
V_73 = F_49 ( V_74 ) ;
switch ( V_73 & V_75 ) {
case V_76 :
case V_77 :
V_58 = V_61 ;
V_60 = V_61 ;
break;
case V_78 :
if ( V_73 & V_79 ) {
V_58 = V_65 ;
V_60 = V_66 ;
} else if ( ( V_73 & V_80 ) == 0 ) {
V_58 = V_81 ;
V_60 = V_82 ;
} else {
V_58 = V_83 ;
V_60 = V_84 ;
}
break;
}
if ( F_53 ( V_2 ) &&
! ( F_49 ( V_85 ) & V_86 ) ) {
V_58 = V_59 ;
V_60 = V_59 ;
}
if ( V_73 == 0xffffffff ) {
F_54 ( L_4
L_5 ) ;
V_58 = V_59 ;
V_60 = V_59 ;
}
} else {
if ( F_55 ( V_87 ) == F_55 ( V_88 ) ) {
V_58 = V_65 ;
V_60 = V_66 ;
}
}
if ( V_58 == V_59 ||
V_60 == V_59 ) {
V_7 -> V_89 |= V_90 ;
V_58 = V_61 ;
V_60 = V_61 ;
}
V_7 -> V_40 . V_91 = V_58 ;
V_7 -> V_40 . V_92 = V_60 ;
}
static void
F_56 ( struct V_93 * V_93 )
{
char V_94 [ 64 ] ;
char * V_95 ;
int V_49 ;
V_95 = F_57 ( V_93 ) ;
for ( V_49 = 0 ; V_49 < V_96 ; V_49 += 128 ) {
memcpy ( V_94 , & V_95 [ V_49 ] , 64 ) ;
memcpy ( & V_95 [ V_49 ] , & V_95 [ V_49 + 64 ] , 64 ) ;
memcpy ( & V_95 [ V_49 + 64 ] , V_94 , 64 ) ;
}
F_58 ( V_93 ) ;
}
void
F_59 ( struct V_4 * V_5 )
{
struct V_97 V_97 ;
struct V_93 * V_93 ;
int V_49 ;
if ( V_5 -> V_98 == NULL )
return;
V_49 = 0 ;
F_60 (page, sgt_iter, obj->pages) {
char V_99 = F_61 ( V_93 ) >> 17 ;
if ( ( V_99 & 0x1 ) !=
( F_62 ( V_49 , V_5 -> V_98 ) != 0 ) ) {
F_56 ( V_93 ) ;
F_63 ( V_93 ) ;
}
V_49 ++ ;
}
}
void
F_64 ( struct V_4 * V_5 )
{
struct V_97 V_97 ;
struct V_93 * V_93 ;
int V_100 = V_5 -> V_31 . V_14 >> V_101 ;
int V_49 ;
if ( V_5 -> V_98 == NULL ) {
V_5 -> V_98 = F_65 ( F_66 ( V_100 ) ,
sizeof( long ) , V_102 ) ;
if ( V_5 -> V_98 == NULL ) {
F_54 ( L_6
L_7 ) ;
return;
}
}
V_49 = 0 ;
F_60 (page, sgt_iter, obj->pages) {
if ( F_61 ( V_93 ) & ( 1 << 17 ) )
F_67 ( V_49 , V_5 -> V_98 ) ;
else
F_68 ( V_49 , V_5 -> V_98 ) ;
V_49 ++ ;
}
}
