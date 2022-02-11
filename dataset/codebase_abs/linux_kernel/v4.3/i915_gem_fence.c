static void F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_9 ;
int V_10 ;
if ( F_2 ( V_2 ) -> V_11 >= 6 ) {
V_9 = V_12 ;
V_10 = V_13 ;
} else {
V_9 = V_14 ;
V_10 = V_15 ;
}
V_9 += V_3 * 8 ;
F_3 ( V_9 , 0 ) ;
F_4 ( V_9 ) ;
if ( V_5 ) {
T_1 V_16 = F_5 ( V_5 ) ;
T_2 V_17 ;
if ( V_5 -> V_18 != V_19 ) {
T_3 V_20 = V_5 -> V_21 *
( V_5 -> V_18 == V_22 ? 32 : 8 ) ;
V_16 = ( V_16 / V_20 ) * V_20 ;
}
V_17 = ( T_2 ) ( ( F_6 ( V_5 ) + V_16 - 4096 ) &
0xfffff000 ) << 32 ;
V_17 |= F_6 ( V_5 ) & 0xfffff000 ;
V_17 |= ( T_2 ) ( ( V_5 -> V_21 / 128 ) - 1 ) << V_10 ;
if ( V_5 -> V_18 == V_22 )
V_17 |= 1 << V_23 ;
V_17 |= V_24 ;
F_3 ( V_9 + 4 , V_17 >> 32 ) ;
F_4 ( V_9 + 4 ) ;
F_3 ( V_9 + 0 , V_17 ) ;
F_4 ( V_9 ) ;
} else {
F_3 ( V_9 + 4 , 0 ) ;
F_4 ( V_9 + 4 ) ;
}
}
static void F_7 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
T_1 V_17 ;
if ( V_5 ) {
T_1 V_16 = F_5 ( V_5 ) ;
int V_25 ;
int V_26 ;
F_8 ( ( F_6 ( V_5 ) & ~ V_27 ) ||
( V_16 & - V_16 ) != V_16 ||
( F_6 ( V_5 ) & ( V_16 - 1 ) ) ,
L_1 ,
F_6 ( V_5 ) , V_5 -> V_28 , V_16 ) ;
if ( V_5 -> V_18 == V_22 && F_9 ( V_2 ) )
V_26 = 128 ;
else
V_26 = 512 ;
V_25 = V_5 -> V_21 / V_26 ;
V_25 = F_10 ( V_25 ) - 1 ;
V_17 = F_6 ( V_5 ) ;
if ( V_5 -> V_18 == V_22 )
V_17 |= 1 << V_29 ;
V_17 |= F_11 ( V_16 ) ;
V_17 |= V_25 << V_30 ;
V_17 |= V_31 ;
} else
V_17 = 0 ;
if ( V_3 < 8 )
V_3 = V_32 + V_3 * 4 ;
else
V_3 = V_33 + ( V_3 - 8 ) * 4 ;
F_3 ( V_3 , V_17 ) ;
F_4 ( V_3 ) ;
}
static void F_12 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
T_3 V_17 ;
if ( V_5 ) {
T_1 V_16 = F_5 ( V_5 ) ;
T_3 V_25 ;
F_8 ( ( F_6 ( V_5 ) & ~ V_34 ) ||
( V_16 & - V_16 ) != V_16 ||
( F_6 ( V_5 ) & ( V_16 - 1 ) ) ,
L_2 ,
F_6 ( V_5 ) , V_16 ) ;
V_25 = V_5 -> V_21 / 128 ;
V_25 = F_10 ( V_25 ) - 1 ;
V_17 = F_6 ( V_5 ) ;
if ( V_5 -> V_18 == V_22 )
V_17 |= 1 << V_29 ;
V_17 |= F_13 ( V_16 ) ;
V_17 |= V_25 << V_30 ;
V_17 |= V_31 ;
} else
V_17 = 0 ;
F_3 ( V_32 + V_3 * 4 , V_17 ) ;
F_4 ( V_32 + V_3 * 4 ) ;
}
inline static bool F_14 ( struct V_4 * V_5 )
{
return V_5 && V_5 -> V_35 . V_36 & V_37 ;
}
static void F_15 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
if ( F_14 ( V_7 -> V_38 [ V_3 ] . V_5 ) )
F_16 () ;
F_8 ( V_5 && ( ! V_5 -> V_21 || ! V_5 -> V_18 ) ,
L_3 ,
V_5 -> V_21 , V_5 -> V_18 ) ;
if ( F_17 ( V_2 ) )
F_12 ( V_2 , V_3 , V_5 ) ;
else if ( F_18 ( V_2 ) )
F_7 ( V_2 , V_3 , V_5 ) ;
else if ( F_2 ( V_2 ) -> V_11 >= 4 )
F_1 ( V_2 , V_3 , V_5 ) ;
if ( F_14 ( V_5 ) )
F_16 () ;
}
static inline int F_19 ( struct V_6 * V_7 ,
struct V_39 * V_40 )
{
return V_40 - V_7 -> V_38 ;
}
static void F_20 ( struct V_4 * V_5 ,
struct V_39 * V_40 ,
bool V_41 )
{
struct V_6 * V_7 = V_5 -> V_35 . V_2 -> V_8 ;
int V_3 = F_19 ( V_7 , V_40 ) ;
F_15 ( V_5 -> V_35 . V_2 , V_3 , V_41 ? V_5 : NULL ) ;
if ( V_41 ) {
V_5 -> V_9 = V_3 ;
V_40 -> V_5 = V_5 ;
F_21 ( & V_40 -> V_42 , & V_7 -> V_43 . V_44 ) ;
} else {
V_5 -> V_9 = V_45 ;
V_40 -> V_5 = NULL ;
F_22 ( & V_40 -> V_42 ) ;
}
V_5 -> V_46 = false ;
}
static inline void F_23 ( struct V_4 * V_5 )
{
if ( V_5 -> V_18 )
F_24 ( V_5 ) ;
V_5 -> V_46 = false ;
V_5 -> V_9 = V_45 ;
}
static int
F_25 ( struct V_4 * V_5 )
{
if ( V_5 -> V_47 ) {
int V_48 = F_26 ( V_5 -> V_47 ) ;
if ( V_48 )
return V_48 ;
F_27 ( & V_5 -> V_47 , NULL ) ;
}
return 0 ;
}
int
F_28 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_35 . V_2 -> V_8 ;
struct V_39 * V_40 ;
int V_48 ;
V_48 = F_25 ( V_5 ) ;
if ( V_48 )
return V_48 ;
if ( V_5 -> V_9 == V_45 )
return 0 ;
V_40 = & V_7 -> V_38 [ V_5 -> V_9 ] ;
if ( F_29 ( V_40 -> V_49 ) )
return - V_50 ;
F_23 ( V_5 ) ;
F_20 ( V_5 , V_40 , false ) ;
return 0 ;
}
static struct V_39 *
F_30 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_39 * V_3 , * V_51 ;
int V_52 ;
V_51 = NULL ;
for ( V_52 = V_7 -> V_53 ; V_52 < V_7 -> V_54 ; V_52 ++ ) {
V_3 = & V_7 -> V_38 [ V_52 ] ;
if ( ! V_3 -> V_5 )
return V_3 ;
if ( ! V_3 -> V_49 )
V_51 = V_3 ;
}
if ( V_51 == NULL )
goto V_55;
F_31 (reg, &dev_priv->mm.fence_list, lru_list) {
if ( V_3 -> V_49 )
continue;
return V_3 ;
}
V_55:
if ( F_32 ( V_2 ) )
return F_33 ( - V_56 ) ;
return F_33 ( - V_57 ) ;
}
int
F_34 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_35 . V_2 ;
struct V_6 * V_7 = V_2 -> V_8 ;
bool V_41 = V_5 -> V_18 != V_19 ;
struct V_39 * V_3 ;
int V_48 ;
if ( V_5 -> V_46 ) {
V_48 = F_25 ( V_5 ) ;
if ( V_48 )
return V_48 ;
}
if ( V_5 -> V_9 != V_45 ) {
V_3 = & V_7 -> V_38 [ V_5 -> V_9 ] ;
if ( ! V_5 -> V_46 ) {
F_21 ( & V_3 -> V_42 ,
& V_7 -> V_43 . V_44 ) ;
return 0 ;
}
} else if ( V_41 ) {
if ( F_29 ( ! V_5 -> V_28 ) )
return - V_58 ;
V_3 = F_30 ( V_2 ) ;
if ( F_35 ( V_3 ) )
return F_36 ( V_3 ) ;
if ( V_3 -> V_5 ) {
struct V_4 * V_59 = V_3 -> V_5 ;
V_48 = F_25 ( V_59 ) ;
if ( V_48 )
return V_48 ;
F_23 ( V_59 ) ;
}
} else
return 0 ;
F_20 ( V_5 , V_3 , V_41 ) ;
return 0 ;
}
bool
F_37 ( struct V_4 * V_5 )
{
if ( V_5 -> V_9 != V_45 ) {
struct V_6 * V_7 = V_5 -> V_35 . V_2 -> V_8 ;
struct V_60 * V_61 = F_38 ( V_5 ) ;
F_29 ( ! V_61 ||
V_7 -> V_38 [ V_5 -> V_9 ] . V_49 >
V_61 -> V_49 ) ;
V_7 -> V_38 [ V_5 -> V_9 ] . V_49 ++ ;
return true ;
} else
return false ;
}
void
F_39 ( struct V_4 * V_5 )
{
if ( V_5 -> V_9 != V_45 ) {
struct V_6 * V_7 = V_5 -> V_35 . V_2 -> V_8 ;
F_29 ( V_7 -> V_38 [ V_5 -> V_9 ] . V_49 <= 0 ) ;
V_7 -> V_38 [ V_5 -> V_9 ] . V_49 -- ;
}
}
void F_40 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_52 ;
for ( V_52 = 0 ; V_52 < V_7 -> V_54 ; V_52 ++ ) {
struct V_39 * V_3 = & V_7 -> V_38 [ V_52 ] ;
if ( V_3 -> V_5 ) {
F_20 ( V_3 -> V_5 , V_3 ,
V_3 -> V_5 -> V_18 ) ;
} else {
F_15 ( V_2 , V_52 , NULL ) ;
}
}
}
void
F_41 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
T_3 V_62 = V_63 ;
T_3 V_64 = V_63 ;
if ( F_2 ( V_2 ) -> V_11 >= 8 || F_42 ( V_2 ) ) {
V_62 = V_65 ;
V_64 = V_65 ;
} else if ( F_2 ( V_2 ) -> V_11 >= 6 ) {
if ( V_7 -> V_66 ) {
if ( F_43 ( V_67 ) &
V_68 ) {
V_62 = V_69 ;
V_64 = V_70 ;
} else {
V_62 = V_65 ;
V_64 = V_65 ;
}
} else {
T_3 V_71 , V_72 ;
V_71 = F_43 ( V_73 ) ;
V_72 = F_43 ( V_74 ) ;
V_71 &= V_75 | V_76 ;
V_72 &= V_75 | V_76 ;
if ( V_71 == V_72 ) {
V_62 = V_69 ;
V_64 = V_70 ;
} else {
V_62 = V_65 ;
V_64 = V_65 ;
}
}
} else if ( F_44 ( V_2 ) ) {
V_62 = V_69 ;
V_64 = V_70 ;
} else if ( F_17 ( V_2 ) ) {
V_62 = V_65 ;
V_64 = V_65 ;
} else if ( F_45 ( V_2 ) || ( F_18 ( V_2 ) && ! F_46 ( V_2 ) ) ) {
T_3 V_77 ;
V_77 = F_43 ( V_78 ) ;
switch ( V_77 & V_79 ) {
case V_80 :
case V_81 :
V_62 = V_65 ;
V_64 = V_65 ;
break;
case V_82 :
if ( V_77 & V_83 ) {
V_62 = V_69 ;
V_64 = V_70 ;
} else if ( ( V_77 & V_84 ) == 0 ) {
V_62 = V_85 ;
V_64 = V_86 ;
} else {
V_62 = V_87 ;
V_64 = V_88 ;
}
break;
}
if ( F_47 ( V_2 ) ) {
T_3 V_89 = F_43 ( V_90 ) ;
if ( ! ( V_89 & V_91 ) )
V_7 -> V_92 |= V_93 ;
}
if ( V_77 == 0xffffffff ) {
F_48 ( L_4
L_5 ) ;
V_62 = V_63 ;
V_64 = V_63 ;
}
} else {
if ( F_49 ( V_94 ) != F_49 ( V_95 ) ) {
V_62 = V_65 ;
V_64 = V_65 ;
} else {
V_62 = V_69 ;
V_64 = V_70 ;
}
}
V_7 -> V_43 . V_96 = V_62 ;
V_7 -> V_43 . V_97 = V_64 ;
}
static void
F_50 ( struct V_98 * V_98 )
{
char V_99 [ 64 ] ;
char * V_100 ;
int V_52 ;
V_100 = F_51 ( V_98 ) ;
for ( V_52 = 0 ; V_52 < V_101 ; V_52 += 128 ) {
memcpy ( V_99 , & V_100 [ V_52 ] , 64 ) ;
memcpy ( & V_100 [ V_52 ] , & V_100 [ V_52 + 64 ] , 64 ) ;
memcpy ( & V_100 [ V_52 + 64 ] , V_99 , 64 ) ;
}
F_52 ( V_98 ) ;
}
void
F_53 ( struct V_4 * V_5 )
{
struct V_102 V_103 ;
int V_52 ;
if ( V_5 -> V_104 == NULL )
return;
V_52 = 0 ;
F_54 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
struct V_98 * V_98 = F_55 ( & V_103 ) ;
char V_105 = F_56 ( V_98 ) >> 17 ;
if ( ( V_105 & 0x1 ) !=
( F_57 ( V_52 , V_5 -> V_104 ) != 0 ) ) {
F_50 ( V_98 ) ;
F_58 ( V_98 ) ;
}
V_52 ++ ;
}
}
void
F_59 ( struct V_4 * V_5 )
{
struct V_102 V_103 ;
int V_106 = V_5 -> V_35 . V_16 >> V_107 ;
int V_52 ;
if ( V_5 -> V_104 == NULL ) {
V_5 -> V_104 = F_60 ( F_61 ( V_106 ) ,
sizeof( long ) , V_108 ) ;
if ( V_5 -> V_104 == NULL ) {
F_48 ( L_6
L_7 ) ;
return;
}
}
V_52 = 0 ;
F_54 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
if ( F_56 ( F_55 ( & V_103 ) ) & ( 1 << 17 ) )
F_62 ( V_52 , V_5 -> V_104 ) ;
else
F_63 ( V_52 , V_5 -> V_104 ) ;
V_52 ++ ;
}
}
