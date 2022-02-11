static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 , V_6 ;
int V_7 ;
T_2 V_8 ;
if ( F_2 ( V_2 -> V_9 ) -> V_10 >= 6 ) {
V_5 = F_3 ( V_2 -> V_11 ) ;
V_6 = F_4 ( V_2 -> V_11 ) ;
V_7 = V_12 ;
} else {
V_5 = F_5 ( V_2 -> V_11 ) ;
V_6 = F_6 ( V_2 -> V_11 ) ;
V_7 = V_13 ;
}
V_8 = 0 ;
if ( V_4 ) {
unsigned int V_14 = F_7 ( V_4 -> V_15 ) ;
F_8 ( ! F_9 ( V_4 ) ) ;
F_8 ( ! F_10 ( V_4 -> V_16 . V_17 , V_18 ) ) ;
F_8 ( ! F_10 ( V_4 -> V_19 , V_18 ) ) ;
F_8 ( ! F_10 ( V_14 , 128 ) ) ;
V_8 = ( V_4 -> V_16 . V_17 + V_4 -> V_19 - V_18 ) << 32 ;
V_8 |= V_4 -> V_16 . V_17 ;
V_8 |= ( T_2 ) ( ( V_14 / 128 ) - 1 ) << V_7 ;
if ( F_11 ( V_4 -> V_15 ) == V_20 )
V_8 |= F_12 ( V_21 ) ;
V_8 |= V_22 ;
}
if ( ! V_23 ) {
struct V_24 * V_25 = V_2 -> V_9 ;
F_13 ( V_5 , 0 ) ;
F_14 ( V_5 ) ;
F_13 ( V_6 , F_15 ( V_8 ) ) ;
F_13 ( V_5 , F_16 ( V_8 ) ) ;
F_14 ( V_5 ) ;
}
}
static void F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_3 V_8 ;
V_8 = 0 ;
if ( V_4 ) {
unsigned int V_26 = F_11 ( V_4 -> V_15 ) ;
bool V_27 = V_26 == V_20 ;
unsigned int V_14 = F_7 ( V_4 -> V_15 ) ;
F_8 ( ! F_9 ( V_4 ) ) ;
F_8 ( V_4 -> V_16 . V_17 & ~ V_28 ) ;
F_8 ( ! F_18 ( V_4 -> V_19 ) ) ;
F_8 ( ! F_10 ( V_4 -> V_16 . V_17 , V_4 -> V_19 ) ) ;
if ( V_27 && F_19 ( V_2 -> V_9 ) )
V_14 /= 128 ;
else
V_14 /= 512 ;
F_8 ( ! F_18 ( V_14 ) ) ;
V_8 = V_4 -> V_16 . V_17 ;
if ( V_27 )
V_8 |= F_12 ( V_29 ) ;
V_8 |= F_20 ( V_4 -> V_19 ) ;
V_8 |= F_21 ( V_14 ) << V_30 ;
V_8 |= V_31 ;
}
if ( ! V_23 ) {
struct V_24 * V_25 = V_2 -> V_9 ;
T_1 V_32 = F_22 ( V_2 -> V_11 ) ;
F_13 ( V_32 , V_8 ) ;
F_14 ( V_32 ) ;
}
}
static void F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_3 V_8 ;
V_8 = 0 ;
if ( V_4 ) {
unsigned int V_14 = F_7 ( V_4 -> V_15 ) ;
F_8 ( ! F_9 ( V_4 ) ) ;
F_8 ( V_4 -> V_16 . V_17 & ~ V_33 ) ;
F_8 ( ! F_18 ( V_4 -> V_19 ) ) ;
F_8 ( ! F_18 ( V_14 / 128 ) ) ;
F_8 ( ! F_10 ( V_4 -> V_16 . V_17 , V_4 -> V_19 ) ) ;
V_8 = V_4 -> V_16 . V_17 ;
if ( F_11 ( V_4 -> V_15 ) == V_20 )
V_8 |= F_12 ( V_29 ) ;
V_8 |= F_24 ( V_4 -> V_19 ) ;
V_8 |= F_21 ( V_14 / 128 ) << V_30 ;
V_8 |= V_31 ;
}
if ( ! V_23 ) {
struct V_24 * V_25 = V_2 -> V_9 ;
T_1 V_32 = F_22 ( V_2 -> V_11 ) ;
F_13 ( V_32 , V_8 ) ;
F_14 ( V_32 ) ;
}
}
static void F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( F_26 ( V_2 -> V_9 ) )
F_23 ( V_2 , V_4 ) ;
else if ( F_27 ( V_2 -> V_9 ) )
F_17 ( V_2 , V_4 ) ;
else
F_1 ( V_2 , V_4 ) ;
V_2 -> V_34 = false ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_35 ;
if ( V_4 ) {
if ( ! F_9 ( V_4 ) )
return - V_36 ;
if ( F_29 ( ! F_7 ( V_4 -> V_15 ) ||
! F_11 ( V_4 -> V_15 ) ,
L_1 ,
F_7 ( V_4 -> V_15 ) ,
F_11 ( V_4 -> V_15 ) ) )
return - V_36 ;
V_35 = F_30 ( & V_4 -> V_37 ,
& V_4 -> V_15 -> V_38 . V_39 -> V_40 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_2 -> V_4 ) {
V_35 = F_30 ( & V_2 -> V_4 -> V_37 ,
& V_2 -> V_4 -> V_15 -> V_38 . V_39 -> V_40 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_2 -> V_4 && V_2 -> V_4 != V_4 ) {
F_31 ( V_2 -> V_4 -> V_15 ) ;
V_2 -> V_4 -> V_2 = NULL ;
V_2 -> V_4 = NULL ;
F_32 ( & V_2 -> V_41 , & V_2 -> V_9 -> V_42 . V_43 ) ;
}
F_25 ( V_2 , V_4 ) ;
if ( V_4 ) {
if ( V_2 -> V_4 != V_4 ) {
V_4 -> V_2 = V_2 ;
V_2 -> V_4 = V_4 ;
}
F_33 ( & V_2 -> V_41 , & V_2 -> V_9 -> V_42 . V_43 ) ;
}
return 0 ;
}
int
F_34 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_35 ( V_4 -> V_44 -> V_9 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_45 )
return - V_46 ;
return F_28 ( V_2 , NULL ) ;
}
static struct V_1 * F_36 ( struct V_24 * V_25 )
{
struct V_1 * V_2 ;
F_37 (fence, &dev_priv->mm.fence_list, link) {
if ( V_2 -> V_45 )
continue;
return V_2 ;
}
if ( F_38 ( V_25 ) )
return F_39 ( - V_47 ) ;
return F_39 ( - V_48 ) ;
}
int
F_40 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_3 * V_49 = F_41 ( V_4 -> V_15 ) ? V_4 : NULL ;
F_35 ( V_4 -> V_44 -> V_9 ) ;
if ( V_4 -> V_2 ) {
V_2 = V_4 -> V_2 ;
if ( ! V_2 -> V_34 ) {
F_33 ( & V_2 -> V_41 ,
& V_2 -> V_9 -> V_42 . V_43 ) ;
return 0 ;
}
} else if ( V_49 ) {
V_2 = F_36 ( V_4 -> V_44 -> V_9 ) ;
if ( F_42 ( V_2 ) )
return F_43 ( V_2 ) ;
} else
return 0 ;
return F_28 ( V_2 , V_49 ) ;
}
void F_44 ( struct V_24 * V_25 )
{
int V_50 ;
F_45 ( & V_25 -> V_51 . V_40 ) ;
for ( V_50 = 0 ; V_50 < V_25 -> V_52 ; V_50 ++ ) {
struct V_1 * V_2 = & V_25 -> V_53 [ V_50 ] ;
if ( V_2 -> V_4 )
F_31 ( V_2 -> V_4 -> V_15 ) ;
}
}
void F_46 ( struct V_24 * V_25 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_25 -> V_52 ; V_50 ++ ) {
struct V_1 * V_32 = & V_25 -> V_53 [ V_50 ] ;
struct V_3 * V_4 = V_32 -> V_4 ;
if ( V_4 && ! F_41 ( V_4 -> V_15 ) ) {
F_8 ( ! V_32 -> V_34 ) ;
F_8 ( ! F_47 ( & V_4 -> V_15 -> V_54 ) ) ;
F_32 ( & V_32 -> V_41 , & V_25 -> V_42 . V_43 ) ;
V_4 -> V_2 = NULL ;
V_4 = NULL ;
}
F_25 ( V_32 , V_4 ) ;
V_32 -> V_4 = V_4 ;
}
}
void
F_48 ( struct V_24 * V_25 )
{
T_4 V_55 = V_56 ;
T_4 V_57 = V_56 ;
if ( F_49 ( V_25 ) >= 8 || F_50 ( V_25 ) ) {
V_55 = V_58 ;
V_57 = V_58 ;
} else if ( F_49 ( V_25 ) >= 6 ) {
if ( V_25 -> V_59 ) {
if ( F_51 ( V_60 ) &
V_61 ) {
V_55 = V_62 ;
V_57 = V_63 ;
} else {
V_55 = V_58 ;
V_57 = V_58 ;
}
} else {
T_4 V_64 , V_65 ;
V_64 = F_51 ( V_66 ) ;
V_65 = F_51 ( V_67 ) ;
V_64 &= V_68 | V_69 ;
V_65 &= V_68 | V_69 ;
if ( V_64 == V_65 ) {
V_55 = V_62 ;
V_57 = V_63 ;
} else {
V_55 = V_58 ;
V_57 = V_58 ;
}
}
} else if ( F_52 ( V_25 ) ) {
V_55 = V_62 ;
V_57 = V_63 ;
} else if ( F_26 ( V_25 ) ) {
V_55 = V_58 ;
V_57 = V_58 ;
} else if ( F_53 ( V_25 ) ||
F_54 ( V_25 ) || F_55 ( V_25 ) ) {
T_4 V_70 ;
V_70 = F_51 ( V_71 ) ;
switch ( V_70 & V_72 ) {
case V_73 :
case V_74 :
V_55 = V_58 ;
V_57 = V_58 ;
break;
case V_75 :
if ( V_70 & V_76 ) {
V_55 = V_62 ;
V_57 = V_63 ;
} else if ( ( V_70 & V_77 ) == 0 ) {
V_55 = V_78 ;
V_57 = V_79 ;
} else {
V_55 = V_80 ;
V_57 = V_81 ;
}
break;
}
if ( F_56 ( V_25 ) &&
! ( F_51 ( V_82 ) & V_83 ) ) {
V_55 = V_56 ;
V_57 = V_56 ;
}
if ( V_70 == 0xffffffff ) {
F_57 ( L_2
L_3 ) ;
V_55 = V_56 ;
V_57 = V_56 ;
}
} else {
if ( F_58 ( V_84 ) == F_58 ( V_85 ) ) {
V_55 = V_62 ;
V_57 = V_63 ;
}
}
if ( V_55 == V_56 ||
V_57 == V_56 ) {
V_25 -> V_86 |= V_87 ;
V_55 = V_58 ;
V_57 = V_58 ;
}
V_25 -> V_42 . V_88 = V_55 ;
V_25 -> V_42 . V_89 = V_57 ;
}
static void
F_59 ( struct V_90 * V_90 )
{
char V_91 [ 64 ] ;
char * V_92 ;
int V_50 ;
V_92 = F_60 ( V_90 ) ;
for ( V_50 = 0 ; V_50 < V_93 ; V_50 += 128 ) {
memcpy ( V_91 , & V_92 [ V_50 ] , 64 ) ;
memcpy ( & V_92 [ V_50 ] , & V_92 [ V_50 + 64 ] , 64 ) ;
memcpy ( & V_92 [ V_50 + 64 ] , V_91 , 64 ) ;
}
F_61 ( V_90 ) ;
}
void
F_62 ( struct V_94 * V_15 ,
struct V_95 * V_96 )
{
struct V_97 V_97 ;
struct V_90 * V_90 ;
int V_50 ;
if ( V_15 -> V_98 == NULL )
return;
V_50 = 0 ;
F_63 (page, sgt_iter, pages) {
char V_99 = F_64 ( V_90 ) >> 17 ;
if ( ( V_99 & 0x1 ) != ( F_65 ( V_50 , V_15 -> V_98 ) != 0 ) ) {
F_59 ( V_90 ) ;
F_66 ( V_90 ) ;
}
V_50 ++ ;
}
}
void
F_67 ( struct V_94 * V_15 ,
struct V_95 * V_96 )
{
const unsigned int V_100 = V_15 -> V_38 . V_101 >> V_102 ;
struct V_97 V_97 ;
struct V_90 * V_90 ;
int V_50 ;
if ( V_15 -> V_98 == NULL ) {
V_15 -> V_98 = F_68 ( F_69 ( V_100 ) ,
sizeof( long ) , V_103 ) ;
if ( V_15 -> V_98 == NULL ) {
F_57 ( L_4
L_5 ) ;
return;
}
}
V_50 = 0 ;
F_63 (page, sgt_iter, pages) {
if ( F_64 ( V_90 ) & ( 1 << 17 ) )
F_70 ( V_50 , V_15 -> V_98 ) ;
else
F_71 ( V_50 , V_15 -> V_98 ) ;
V_50 ++ ;
}
}
