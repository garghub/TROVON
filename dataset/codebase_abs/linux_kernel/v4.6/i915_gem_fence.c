static void F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
T_1 V_9 , V_10 ;
int V_11 ;
if ( F_2 ( V_2 ) -> V_12 >= 6 ) {
V_9 = F_3 ( V_3 ) ;
V_10 = F_4 ( V_3 ) ;
V_11 = V_13 ;
} else {
V_9 = F_5 ( V_3 ) ;
V_10 = F_6 ( V_3 ) ;
V_11 = V_14 ;
}
F_7 ( V_9 , 0 ) ;
F_8 ( V_9 ) ;
if ( V_5 ) {
T_2 V_15 = F_9 ( V_5 ) ;
T_3 V_16 ;
if ( V_5 -> V_17 != V_18 ) {
T_4 V_19 = V_5 -> V_20 *
( V_5 -> V_17 == V_21 ? 32 : 8 ) ;
V_15 = ( V_15 / V_19 ) * V_19 ;
}
V_16 = ( T_3 ) ( ( F_10 ( V_5 ) + V_15 - 4096 ) &
0xfffff000 ) << 32 ;
V_16 |= F_10 ( V_5 ) & 0xfffff000 ;
V_16 |= ( T_3 ) ( ( V_5 -> V_20 / 128 ) - 1 ) << V_11 ;
if ( V_5 -> V_17 == V_21 )
V_16 |= 1 << V_22 ;
V_16 |= V_23 ;
F_7 ( V_10 , V_16 >> 32 ) ;
F_8 ( V_10 ) ;
F_7 ( V_9 , V_16 ) ;
F_8 ( V_9 ) ;
} else {
F_7 ( V_10 , 0 ) ;
F_8 ( V_10 ) ;
}
}
static void F_11 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
T_2 V_16 ;
if ( V_5 ) {
T_2 V_15 = F_9 ( V_5 ) ;
int V_24 ;
int V_25 ;
F_12 ( ( F_10 ( V_5 ) & ~ V_26 ) ||
( V_15 & - V_15 ) != V_15 ||
( F_10 ( V_5 ) & ( V_15 - 1 ) ) ,
L_1 ,
F_10 ( V_5 ) , V_5 -> V_27 , V_15 ) ;
if ( V_5 -> V_17 == V_21 && F_13 ( V_2 ) )
V_25 = 128 ;
else
V_25 = 512 ;
V_24 = V_5 -> V_20 / V_25 ;
V_24 = F_14 ( V_24 ) - 1 ;
V_16 = F_10 ( V_5 ) ;
if ( V_5 -> V_17 == V_21 )
V_16 |= 1 << V_28 ;
V_16 |= F_15 ( V_15 ) ;
V_16 |= V_24 << V_29 ;
V_16 |= V_30 ;
} else
V_16 = 0 ;
F_7 ( F_16 ( V_3 ) , V_16 ) ;
F_8 ( F_16 ( V_3 ) ) ;
}
static void F_17 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
T_4 V_16 ;
if ( V_5 ) {
T_2 V_15 = F_9 ( V_5 ) ;
T_4 V_24 ;
F_12 ( ( F_10 ( V_5 ) & ~ V_31 ) ||
( V_15 & - V_15 ) != V_15 ||
( F_10 ( V_5 ) & ( V_15 - 1 ) ) ,
L_2 ,
F_10 ( V_5 ) , V_15 ) ;
V_24 = V_5 -> V_20 / 128 ;
V_24 = F_14 ( V_24 ) - 1 ;
V_16 = F_10 ( V_5 ) ;
if ( V_5 -> V_17 == V_21 )
V_16 |= 1 << V_28 ;
V_16 |= F_18 ( V_15 ) ;
V_16 |= V_24 << V_29 ;
V_16 |= V_30 ;
} else
V_16 = 0 ;
F_7 ( F_16 ( V_3 ) , V_16 ) ;
F_8 ( F_16 ( V_3 ) ) ;
}
inline static bool F_19 ( struct V_4 * V_5 )
{
return V_5 && V_5 -> V_32 . V_33 & V_34 ;
}
static void F_20 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
if ( F_19 ( V_7 -> V_35 [ V_3 ] . V_5 ) )
F_21 () ;
F_12 ( V_5 && ( ! V_5 -> V_20 || ! V_5 -> V_17 ) ,
L_3 ,
V_5 -> V_20 , V_5 -> V_17 ) ;
if ( F_22 ( V_2 ) )
F_17 ( V_2 , V_3 , V_5 ) ;
else if ( F_23 ( V_2 ) )
F_11 ( V_2 , V_3 , V_5 ) ;
else if ( F_2 ( V_2 ) -> V_12 >= 4 )
F_1 ( V_2 , V_3 , V_5 ) ;
if ( F_19 ( V_5 ) )
F_21 () ;
}
static inline int F_24 ( struct V_6 * V_7 ,
struct V_36 * V_37 )
{
return V_37 - V_7 -> V_35 ;
}
static void F_25 ( struct V_4 * V_5 ,
struct V_36 * V_37 ,
bool V_38 )
{
struct V_6 * V_7 = V_5 -> V_32 . V_2 -> V_8 ;
int V_3 = F_24 ( V_7 , V_37 ) ;
F_20 ( V_5 -> V_32 . V_2 , V_3 , V_38 ? V_5 : NULL ) ;
if ( V_38 ) {
V_5 -> V_39 = V_3 ;
V_37 -> V_5 = V_5 ;
F_26 ( & V_37 -> V_40 , & V_7 -> V_41 . V_42 ) ;
} else {
V_5 -> V_39 = V_43 ;
V_37 -> V_5 = NULL ;
F_27 ( & V_37 -> V_40 ) ;
}
V_5 -> V_44 = false ;
}
static inline void F_28 ( struct V_4 * V_5 )
{
if ( V_5 -> V_17 )
F_29 ( V_5 ) ;
V_5 -> V_44 = false ;
V_5 -> V_39 = V_43 ;
}
static int
F_30 ( struct V_4 * V_5 )
{
if ( V_5 -> V_45 ) {
int V_46 = F_31 ( V_5 -> V_45 ) ;
if ( V_46 )
return V_46 ;
F_32 ( & V_5 -> V_45 , NULL ) ;
}
return 0 ;
}
int
F_33 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_32 . V_2 -> V_8 ;
struct V_36 * V_37 ;
int V_46 ;
V_46 = F_30 ( V_5 ) ;
if ( V_46 )
return V_46 ;
if ( V_5 -> V_39 == V_43 )
return 0 ;
V_37 = & V_7 -> V_35 [ V_5 -> V_39 ] ;
if ( F_34 ( V_37 -> V_47 ) )
return - V_48 ;
F_28 ( V_5 ) ;
F_25 ( V_5 , V_37 , false ) ;
return 0 ;
}
static struct V_36 *
F_35 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_36 * V_3 , * V_49 ;
int V_50 ;
V_49 = NULL ;
for ( V_50 = 0 ; V_50 < V_7 -> V_51 ; V_50 ++ ) {
V_3 = & V_7 -> V_35 [ V_50 ] ;
if ( ! V_3 -> V_5 )
return V_3 ;
if ( ! V_3 -> V_47 )
V_49 = V_3 ;
}
if ( V_49 == NULL )
goto V_52;
F_36 (reg, &dev_priv->mm.fence_list, lru_list) {
if ( V_3 -> V_47 )
continue;
return V_3 ;
}
V_52:
if ( F_37 ( V_2 ) )
return F_38 ( - V_53 ) ;
return F_38 ( - V_54 ) ;
}
int
F_39 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_32 . V_2 ;
struct V_6 * V_7 = V_2 -> V_8 ;
bool V_38 = V_5 -> V_17 != V_18 ;
struct V_36 * V_3 ;
int V_46 ;
if ( V_5 -> V_44 ) {
V_46 = F_30 ( V_5 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_5 -> V_39 != V_43 ) {
V_3 = & V_7 -> V_35 [ V_5 -> V_39 ] ;
if ( ! V_5 -> V_44 ) {
F_26 ( & V_3 -> V_40 ,
& V_7 -> V_41 . V_42 ) ;
return 0 ;
}
} else if ( V_38 ) {
if ( F_34 ( ! V_5 -> V_27 ) )
return - V_55 ;
V_3 = F_35 ( V_2 ) ;
if ( F_40 ( V_3 ) )
return F_41 ( V_3 ) ;
if ( V_3 -> V_5 ) {
struct V_4 * V_56 = V_3 -> V_5 ;
V_46 = F_30 ( V_56 ) ;
if ( V_46 )
return V_46 ;
F_28 ( V_56 ) ;
}
} else
return 0 ;
F_25 ( V_5 , V_3 , V_38 ) ;
return 0 ;
}
bool
F_42 ( struct V_4 * V_5 )
{
if ( V_5 -> V_39 != V_43 ) {
struct V_6 * V_7 = V_5 -> V_32 . V_2 -> V_8 ;
struct V_57 * V_58 = F_43 ( V_5 ) ;
F_34 ( ! V_58 ||
V_7 -> V_35 [ V_5 -> V_39 ] . V_47 >
V_58 -> V_47 ) ;
V_7 -> V_35 [ V_5 -> V_39 ] . V_47 ++ ;
return true ;
} else
return false ;
}
void
F_44 ( struct V_4 * V_5 )
{
if ( V_5 -> V_39 != V_43 ) {
struct V_6 * V_7 = V_5 -> V_32 . V_2 -> V_8 ;
F_34 ( V_7 -> V_35 [ V_5 -> V_39 ] . V_47 <= 0 ) ;
V_7 -> V_35 [ V_5 -> V_39 ] . V_47 -- ;
}
}
void F_45 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_7 -> V_51 ; V_50 ++ ) {
struct V_36 * V_3 = & V_7 -> V_35 [ V_50 ] ;
if ( V_3 -> V_5 ) {
F_25 ( V_3 -> V_5 , V_3 ,
V_3 -> V_5 -> V_17 ) ;
} else {
F_20 ( V_2 , V_50 , NULL ) ;
}
}
}
void
F_46 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
T_4 V_59 = V_60 ;
T_4 V_61 = V_60 ;
if ( F_2 ( V_2 ) -> V_12 >= 8 || F_47 ( V_2 ) ) {
V_59 = V_62 ;
V_61 = V_62 ;
} else if ( F_2 ( V_2 ) -> V_12 >= 6 ) {
if ( V_7 -> V_63 ) {
if ( F_48 ( V_64 ) &
V_65 ) {
V_59 = V_66 ;
V_61 = V_67 ;
} else {
V_59 = V_62 ;
V_61 = V_62 ;
}
} else {
T_4 V_68 , V_69 ;
V_68 = F_48 ( V_70 ) ;
V_69 = F_48 ( V_71 ) ;
V_68 &= V_72 | V_73 ;
V_69 &= V_72 | V_73 ;
if ( V_68 == V_69 ) {
V_59 = V_66 ;
V_61 = V_67 ;
} else {
V_59 = V_62 ;
V_61 = V_62 ;
}
}
} else if ( F_49 ( V_2 ) ) {
V_59 = V_66 ;
V_61 = V_67 ;
} else if ( F_22 ( V_2 ) ) {
V_59 = V_62 ;
V_61 = V_62 ;
} else if ( F_50 ( V_2 ) || ( F_23 ( V_2 ) && ! F_51 ( V_2 ) ) ) {
T_4 V_74 ;
V_74 = F_48 ( V_75 ) ;
switch ( V_74 & V_76 ) {
case V_77 :
case V_78 :
V_59 = V_62 ;
V_61 = V_62 ;
break;
case V_79 :
if ( V_74 & V_80 ) {
V_59 = V_66 ;
V_61 = V_67 ;
} else if ( ( V_74 & V_81 ) == 0 ) {
V_59 = V_82 ;
V_61 = V_83 ;
} else {
V_59 = V_84 ;
V_61 = V_85 ;
}
break;
}
if ( F_52 ( V_2 ) &&
! ( F_48 ( V_86 ) & V_87 ) ) {
V_59 = V_60 ;
V_61 = V_60 ;
}
if ( V_74 == 0xffffffff ) {
F_53 ( L_4
L_5 ) ;
V_59 = V_60 ;
V_61 = V_60 ;
}
} else {
if ( F_54 ( V_88 ) == F_54 ( V_89 ) ) {
V_59 = V_66 ;
V_61 = V_67 ;
}
}
if ( V_59 == V_60 ||
V_61 == V_60 ) {
V_7 -> V_90 |= V_91 ;
V_59 = V_62 ;
V_61 = V_62 ;
}
V_7 -> V_41 . V_92 = V_59 ;
V_7 -> V_41 . V_93 = V_61 ;
}
static void
F_55 ( struct V_94 * V_94 )
{
char V_95 [ 64 ] ;
char * V_96 ;
int V_50 ;
V_96 = F_56 ( V_94 ) ;
for ( V_50 = 0 ; V_50 < V_97 ; V_50 += 128 ) {
memcpy ( V_95 , & V_96 [ V_50 ] , 64 ) ;
memcpy ( & V_96 [ V_50 ] , & V_96 [ V_50 + 64 ] , 64 ) ;
memcpy ( & V_96 [ V_50 + 64 ] , V_95 , 64 ) ;
}
F_57 ( V_94 ) ;
}
void
F_58 ( struct V_4 * V_5 )
{
struct V_98 V_99 ;
int V_50 ;
if ( V_5 -> V_100 == NULL )
return;
V_50 = 0 ;
F_59 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
struct V_94 * V_94 = F_60 ( & V_99 ) ;
char V_101 = F_61 ( V_94 ) >> 17 ;
if ( ( V_101 & 0x1 ) !=
( F_62 ( V_50 , V_5 -> V_100 ) != 0 ) ) {
F_55 ( V_94 ) ;
F_63 ( V_94 ) ;
}
V_50 ++ ;
}
}
void
F_64 ( struct V_4 * V_5 )
{
struct V_98 V_99 ;
int V_102 = V_5 -> V_32 . V_15 >> V_103 ;
int V_50 ;
if ( V_5 -> V_100 == NULL ) {
V_5 -> V_100 = F_65 ( F_66 ( V_102 ) ,
sizeof( long ) , V_104 ) ;
if ( V_5 -> V_100 == NULL ) {
F_53 ( L_6
L_7 ) ;
return;
}
}
V_50 = 0 ;
F_59 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
if ( F_61 ( F_60 ( & V_99 ) ) & ( 1 << 17 ) )
F_67 ( V_50 , V_5 -> V_100 ) ;
else
F_68 ( V_50 , V_5 -> V_100 ) ;
V_50 ++ ;
}
}
