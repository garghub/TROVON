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
void F_44 ( struct V_53 * V_41 )
{
struct V_26 * V_27 = F_35 ( V_41 ) ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_27 -> V_55 ; V_54 ++ ) {
struct V_1 * V_34 = & V_27 -> V_56 [ V_54 ] ;
struct V_3 * V_4 = V_34 -> V_4 ;
if ( V_4 && ! F_41 ( V_4 -> V_15 ) ) {
F_45 ( ! V_34 -> V_36 ) ;
F_45 ( V_4 -> V_15 -> V_57 ) ;
F_31 ( & V_34 -> V_43 , & V_27 -> V_44 . V_45 ) ;
V_4 -> V_2 = NULL ;
V_4 = NULL ;
}
F_25 ( V_34 , V_4 ) ;
V_34 -> V_4 = V_4 ;
}
}
void
F_46 ( struct V_53 * V_41 )
{
struct V_26 * V_27 = F_35 ( V_41 ) ;
T_4 V_58 = V_59 ;
T_4 V_60 = V_59 ;
if ( F_2 ( V_41 ) -> V_10 >= 8 || F_47 ( V_41 ) ) {
V_58 = V_61 ;
V_60 = V_61 ;
} else if ( F_2 ( V_41 ) -> V_10 >= 6 ) {
if ( V_27 -> V_62 ) {
if ( F_48 ( V_63 ) &
V_64 ) {
V_58 = V_65 ;
V_60 = V_66 ;
} else {
V_58 = V_61 ;
V_60 = V_61 ;
}
} else {
T_4 V_67 , V_68 ;
V_67 = F_48 ( V_69 ) ;
V_68 = F_48 ( V_70 ) ;
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
} else if ( F_49 ( V_41 ) ) {
V_58 = V_65 ;
V_60 = V_66 ;
} else if ( F_26 ( V_41 ) ) {
V_58 = V_61 ;
V_60 = V_61 ;
} else if ( F_50 ( V_41 ) || ( F_27 ( V_41 ) && ! F_51 ( V_41 ) ) ) {
T_4 V_73 ;
V_73 = F_48 ( V_74 ) ;
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
if ( F_52 ( V_41 ) &&
! ( F_48 ( V_85 ) & V_86 ) ) {
V_58 = V_59 ;
V_60 = V_59 ;
}
if ( V_73 == 0xffffffff ) {
F_53 ( L_4
L_5 ) ;
V_58 = V_59 ;
V_60 = V_59 ;
}
} else {
if ( F_54 ( V_87 ) == F_54 ( V_88 ) ) {
V_58 = V_65 ;
V_60 = V_66 ;
}
}
if ( V_58 == V_59 ||
V_60 == V_59 ) {
V_27 -> V_89 |= V_90 ;
V_58 = V_61 ;
V_60 = V_61 ;
}
V_27 -> V_44 . V_91 = V_58 ;
V_27 -> V_44 . V_92 = V_60 ;
}
static void
F_55 ( struct V_93 * V_93 )
{
char V_94 [ 64 ] ;
char * V_95 ;
int V_54 ;
V_95 = F_56 ( V_93 ) ;
for ( V_54 = 0 ; V_54 < V_96 ; V_54 += 128 ) {
memcpy ( V_94 , & V_95 [ V_54 ] , 64 ) ;
memcpy ( & V_95 [ V_54 ] , & V_95 [ V_54 + 64 ] , 64 ) ;
memcpy ( & V_95 [ V_54 + 64 ] , V_94 , 64 ) ;
}
F_57 ( V_93 ) ;
}
void
F_58 ( struct V_97 * V_15 )
{
struct V_98 V_98 ;
struct V_93 * V_93 ;
int V_54 ;
if ( V_15 -> V_99 == NULL )
return;
V_54 = 0 ;
F_59 (page, sgt_iter, obj->pages) {
char V_100 = F_60 ( V_93 ) >> 17 ;
if ( ( V_100 & 0x1 ) !=
( F_61 ( V_54 , V_15 -> V_99 ) != 0 ) ) {
F_55 ( V_93 ) ;
F_62 ( V_93 ) ;
}
V_54 ++ ;
}
}
void
F_63 ( struct V_97 * V_15 )
{
struct V_98 V_98 ;
struct V_93 * V_93 ;
int V_101 = V_15 -> V_40 . V_20 >> V_102 ;
int V_54 ;
if ( V_15 -> V_99 == NULL ) {
V_15 -> V_99 = F_64 ( F_65 ( V_101 ) ,
sizeof( long ) , V_103 ) ;
if ( V_15 -> V_99 == NULL ) {
F_53 ( L_6
L_7 ) ;
return;
}
}
V_54 = 0 ;
F_59 (page, sgt_iter, obj->pages) {
if ( F_60 ( V_93 ) & ( 1 << 17 ) )
F_66 ( V_54 , V_15 -> V_99 ) ;
else
F_67 ( V_54 , V_15 -> V_99 ) ;
V_54 ++ ;
}
}
