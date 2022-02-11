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
bool V_16 = V_14 == V_17 ;
unsigned int V_18 = F_8 ( V_4 -> V_15 ) ;
T_3 V_19 = V_18 * ( V_16 ? 32 : 8 ) ;
T_3 V_20 = F_9 ( ( T_3 ) V_4 -> V_21 . V_20 , V_19 ) ;
V_8 = ( ( V_4 -> V_21 . V_22 + V_20 - 4096 ) & 0xfffff000 ) << 32 ;
V_8 |= V_4 -> V_21 . V_22 & 0xfffff000 ;
V_8 |= ( T_2 ) ( ( V_18 / 128 ) - 1 ) << V_7 ;
if ( V_16 )
V_8 |= F_10 ( V_23 ) ;
V_8 |= V_24 ;
}
if ( ! V_25 ) {
struct V_26 * V_27 = V_2 -> V_9 ;
F_11 ( V_5 , 0 ) ;
F_12 ( V_5 ) ;
F_11 ( V_6 , F_13 ( V_8 ) ) ;
F_11 ( V_5 , F_14 ( V_8 ) ) ;
F_12 ( V_5 ) ;
}
}
static void F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_3 V_8 ;
V_8 = 0 ;
if ( V_4 ) {
unsigned int V_14 = F_7 ( V_4 -> V_15 ) ;
bool V_16 = V_14 == V_17 ;
unsigned int V_18 = F_8 ( V_4 -> V_15 ) ;
int V_28 ;
int V_29 ;
F_16 ( ( V_4 -> V_21 . V_22 & ~ V_30 ) ||
! F_17 ( V_4 -> V_21 . V_20 ) ||
( V_4 -> V_21 . V_22 & ( V_4 -> V_21 . V_20 - 1 ) ) ,
L_1 ,
V_4 -> V_21 . V_22 ,
F_18 ( V_4 ) ,
V_4 -> V_21 . V_20 ) ;
if ( V_16 && F_19 ( V_2 -> V_9 ) )
V_29 = 128 ;
else
V_29 = 512 ;
V_28 = V_18 / V_29 ;
V_28 = F_20 ( V_28 ) - 1 ;
V_8 = V_4 -> V_21 . V_22 ;
if ( V_16 )
V_8 |= F_10 ( V_31 ) ;
V_8 |= F_21 ( V_4 -> V_21 . V_20 ) ;
V_8 |= V_28 << V_32 ;
V_8 |= V_33 ;
}
if ( ! V_25 ) {
struct V_26 * V_27 = V_2 -> V_9 ;
T_1 V_34 = F_22 ( V_2 -> V_11 ) ;
F_11 ( V_34 , V_8 ) ;
F_12 ( V_34 ) ;
}
}
static void F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_3 V_8 ;
V_8 = 0 ;
if ( V_4 ) {
unsigned int V_14 = F_7 ( V_4 -> V_15 ) ;
bool V_16 = V_14 == V_17 ;
unsigned int V_18 = F_8 ( V_4 -> V_15 ) ;
T_3 V_28 ;
F_16 ( ( V_4 -> V_21 . V_22 & ~ V_35 ) ||
! F_17 ( V_4 -> V_21 . V_20 ) ||
( V_4 -> V_21 . V_22 & ( V_4 -> V_21 . V_20 - 1 ) ) ,
L_2 ,
V_4 -> V_21 . V_22 , V_4 -> V_21 . V_20 ) ;
V_28 = V_18 / 128 ;
V_28 = F_20 ( V_28 ) - 1 ;
V_8 = V_4 -> V_21 . V_22 ;
if ( V_16 )
V_8 |= F_10 ( V_31 ) ;
V_8 |= F_24 ( V_4 -> V_21 . V_20 ) ;
V_8 |= V_28 << V_32 ;
V_8 |= V_33 ;
}
if ( ! V_25 ) {
struct V_26 * V_27 = V_2 -> V_9 ;
T_1 V_34 = F_22 ( V_2 -> V_11 ) ;
F_11 ( V_34 , V_8 ) ;
F_12 ( V_34 ) ;
}
}
static void F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( F_26 ( V_2 -> V_9 ) )
F_23 ( V_2 , V_4 ) ;
else if ( F_27 ( V_2 -> V_9 ) )
F_15 ( V_2 , V_4 ) ;
else
F_1 ( V_2 , V_4 ) ;
V_2 -> V_36 = false ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_37 ;
if ( V_4 ) {
if ( ! F_18 ( V_4 ) )
return - V_38 ;
if ( F_16 ( ! F_8 ( V_4 -> V_15 ) ||
! F_7 ( V_4 -> V_15 ) ,
L_3 ,
F_8 ( V_4 -> V_15 ) ,
F_7 ( V_4 -> V_15 ) ) )
return - V_38 ;
V_37 = F_29 ( & V_4 -> V_39 ,
& V_4 -> V_15 -> V_40 . V_41 -> V_42 ) ;
if ( V_37 )
return V_37 ;
}
if ( V_2 -> V_4 ) {
V_37 = F_29 ( & V_2 -> V_4 -> V_39 ,
& V_2 -> V_4 -> V_15 -> V_40 . V_41 -> V_42 ) ;
if ( V_37 )
return V_37 ;
}
if ( V_2 -> V_4 && V_2 -> V_4 != V_4 ) {
F_30 ( V_2 -> V_4 -> V_15 ) ;
V_2 -> V_4 -> V_2 = NULL ;
V_2 -> V_4 = NULL ;
F_31 ( & V_2 -> V_43 , & V_2 -> V_9 -> V_44 . V_45 ) ;
}
F_25 ( V_2 , V_4 ) ;
if ( V_4 ) {
if ( V_2 -> V_4 != V_4 ) {
V_4 -> V_2 = V_2 ;
V_2 -> V_4 = V_4 ;
}
F_32 ( & V_2 -> V_43 , & V_2 -> V_9 -> V_44 . V_45 ) ;
}
return 0 ;
}
int
F_33 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_34 ( F_35 ( V_4 -> V_46 -> V_41 ) ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_47 )
return - V_48 ;
return F_28 ( V_2 , NULL ) ;
}
static struct V_1 * F_36 ( struct V_26 * V_27 )
{
struct V_1 * V_2 ;
F_37 (fence, &dev_priv->mm.fence_list, link) {
if ( V_2 -> V_47 )
continue;
return V_2 ;
}
if ( F_38 ( & V_27 -> V_49 ) )
return F_39 ( - V_50 ) ;
return F_39 ( - V_51 ) ;
}
int
F_40 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_3 * V_52 = F_41 ( V_4 -> V_15 ) ? V_4 : NULL ;
F_34 ( F_35 ( V_4 -> V_46 -> V_41 ) ) ;
if ( V_4 -> V_2 ) {
V_2 = V_4 -> V_2 ;
if ( ! V_2 -> V_36 ) {
F_32 ( & V_2 -> V_43 ,
& V_2 -> V_9 -> V_44 . V_45 ) ;
return 0 ;
}
} else if ( V_52 ) {
V_2 = F_36 ( F_35 ( V_4 -> V_46 -> V_41 ) ) ;
if ( F_42 ( V_2 ) )
return F_43 ( V_2 ) ;
} else
return 0 ;
return F_28 ( V_2 , V_52 ) ;
}
void F_44 ( struct V_26 * V_27 )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < V_27 -> V_54 ; V_53 ++ ) {
struct V_1 * V_34 = & V_27 -> V_55 [ V_53 ] ;
struct V_3 * V_4 = V_34 -> V_4 ;
if ( V_4 && ! F_41 ( V_4 -> V_15 ) ) {
F_45 ( ! V_34 -> V_36 ) ;
F_45 ( ! F_46 ( & V_4 -> V_15 -> V_56 ) ) ;
F_31 ( & V_34 -> V_43 , & V_27 -> V_44 . V_45 ) ;
V_4 -> V_2 = NULL ;
V_4 = NULL ;
}
F_25 ( V_34 , V_4 ) ;
V_34 -> V_4 = V_4 ;
}
}
void
F_47 ( struct V_26 * V_27 )
{
T_4 V_57 = V_58 ;
T_4 V_59 = V_58 ;
if ( F_48 ( V_27 ) >= 8 || F_49 ( V_27 ) ) {
V_57 = V_60 ;
V_59 = V_60 ;
} else if ( F_48 ( V_27 ) >= 6 ) {
if ( V_27 -> V_61 ) {
if ( F_50 ( V_62 ) &
V_63 ) {
V_57 = V_64 ;
V_59 = V_65 ;
} else {
V_57 = V_60 ;
V_59 = V_60 ;
}
} else {
T_4 V_66 , V_67 ;
V_66 = F_50 ( V_68 ) ;
V_67 = F_50 ( V_69 ) ;
V_66 &= V_70 | V_71 ;
V_67 &= V_70 | V_71 ;
if ( V_66 == V_67 ) {
V_57 = V_64 ;
V_59 = V_65 ;
} else {
V_57 = V_60 ;
V_59 = V_60 ;
}
}
} else if ( F_51 ( V_27 ) ) {
V_57 = V_64 ;
V_59 = V_65 ;
} else if ( F_26 ( V_27 ) ) {
V_57 = V_60 ;
V_59 = V_60 ;
} else if ( F_52 ( V_27 ) || ( F_27 ( V_27 ) &&
! F_53 ( V_27 ) ) ) {
T_4 V_72 ;
V_72 = F_50 ( V_73 ) ;
switch ( V_72 & V_74 ) {
case V_75 :
case V_76 :
V_57 = V_60 ;
V_59 = V_60 ;
break;
case V_77 :
if ( V_72 & V_78 ) {
V_57 = V_64 ;
V_59 = V_65 ;
} else if ( ( V_72 & V_79 ) == 0 ) {
V_57 = V_80 ;
V_59 = V_81 ;
} else {
V_57 = V_82 ;
V_59 = V_83 ;
}
break;
}
if ( F_54 ( V_27 ) &&
! ( F_50 ( V_84 ) & V_85 ) ) {
V_57 = V_58 ;
V_59 = V_58 ;
}
if ( V_72 == 0xffffffff ) {
F_55 ( L_4
L_5 ) ;
V_57 = V_58 ;
V_59 = V_58 ;
}
} else {
if ( F_56 ( V_86 ) == F_56 ( V_87 ) ) {
V_57 = V_64 ;
V_59 = V_65 ;
}
}
if ( V_57 == V_58 ||
V_59 == V_58 ) {
V_27 -> V_88 |= V_89 ;
V_57 = V_60 ;
V_59 = V_60 ;
}
V_27 -> V_44 . V_90 = V_57 ;
V_27 -> V_44 . V_91 = V_59 ;
}
static void
F_57 ( struct V_92 * V_92 )
{
char V_93 [ 64 ] ;
char * V_94 ;
int V_53 ;
V_94 = F_58 ( V_92 ) ;
for ( V_53 = 0 ; V_53 < V_95 ; V_53 += 128 ) {
memcpy ( V_93 , & V_94 [ V_53 ] , 64 ) ;
memcpy ( & V_94 [ V_53 ] , & V_94 [ V_53 + 64 ] , 64 ) ;
memcpy ( & V_94 [ V_53 + 64 ] , V_93 , 64 ) ;
}
F_59 ( V_92 ) ;
}
void
F_60 ( struct V_96 * V_15 ,
struct V_97 * V_98 )
{
struct V_99 V_99 ;
struct V_92 * V_92 ;
int V_53 ;
if ( V_15 -> V_100 == NULL )
return;
V_53 = 0 ;
F_61 (page, sgt_iter, pages) {
char V_101 = F_62 ( V_92 ) >> 17 ;
if ( ( V_101 & 0x1 ) != ( F_63 ( V_53 , V_15 -> V_100 ) != 0 ) ) {
F_57 ( V_92 ) ;
F_64 ( V_92 ) ;
}
V_53 ++ ;
}
}
void
F_65 ( struct V_96 * V_15 ,
struct V_97 * V_98 )
{
const unsigned int V_102 = V_15 -> V_40 . V_20 >> V_103 ;
struct V_99 V_99 ;
struct V_92 * V_92 ;
int V_53 ;
if ( V_15 -> V_100 == NULL ) {
V_15 -> V_100 = F_66 ( F_67 ( V_102 ) ,
sizeof( long ) , V_104 ) ;
if ( V_15 -> V_100 == NULL ) {
F_55 ( L_6
L_7 ) ;
return;
}
}
V_53 = 0 ;
F_61 (page, sgt_iter, pages) {
if ( F_62 ( V_92 ) & ( 1 << 17 ) )
F_68 ( V_53 , V_15 -> V_100 ) ;
else
F_69 ( V_53 , V_15 -> V_100 ) ;
V_53 ++ ;
}
}
