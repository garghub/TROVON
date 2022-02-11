static void F_1 ( T_1 * V_1 , T_1 * V_2 , T_1 V_3 , int V_4 )
{
T_1 V_5 ;
if ( V_4 > 0 )
V_4 -- ;
else
V_4 = 0 ;
V_5 = V_3 + V_4 ;
if ( ( * V_1 == 0 ) && ( * V_2 == 0 ) ) {
* V_1 = V_3 ;
* V_2 = V_5 ;
} else if ( * V_1 <= * V_2 ) {
if ( V_3 < * V_1 )
* V_1 = V_3 ;
if ( V_5 > * V_2 )
* V_2 = V_5 ;
} else {
if ( V_3 <= * V_2 ) {
if ( V_5 > * V_2 )
* V_2 = V_5 ;
} else if ( V_5 > * V_1 ) {
if ( V_3 < * V_1 )
* V_1 = V_3 ;
}
else if ( ( V_5 - * V_2 ) < ( * V_1 - V_3 ) )
* V_2 = V_5 ;
else
* V_1 = V_3 ;
}
}
static void F_2 ( struct V_6 * V_7 )
{
unsigned long V_1 , V_4 ;
T_1 * V_8 = & V_7 -> V_9 . V_10 -> V_11 [ 9 ] ;
T_1 * V_12 = & V_7 -> V_9 . V_10 -> V_11 [ 10 ] ;
T_1 * V_13 = & V_7 -> V_9 . V_10 -> V_11 [ 11 ] ;
int V_14 ;
if ( V_7 -> V_9 . V_15 . V_16 <= 0 ||
V_7 -> V_9 . V_15 . V_17 == NULL )
return;
if ( ! ( * V_8 & V_18 ) )
* V_8 |= V_19 ;
* V_8 |= V_20 | V_18 ;
for ( V_14 = 0 ; V_14 < V_7 -> V_9 . V_15 . V_16 ; V_14 ++ ) {
V_1 = V_7 -> V_9 . V_15 . V_17 [ V_14 ] . V_21 ;
V_4 = V_7 -> V_9 . V_15 . V_17 [ V_14 ] . V_4 ;
if ( V_1 < V_22 ) {
V_4 += V_1 ;
V_1 = 0 ;
} else {
V_1 -= V_22 ;
V_4 += V_22 ;
}
F_1 ( V_12 , V_13 , V_1 , V_4 ) ;
}
}
static void F_3 ( struct V_6 * V_7 )
{
unsigned long V_1 , V_4 ;
T_1 * V_8 = & V_7 -> V_9 . V_10 -> V_11 [ 9 ] ;
T_1 * V_12 = & V_7 -> V_9 . V_10 -> V_11 [ 10 ] ;
T_1 * V_13 = & V_7 -> V_9 . V_10 -> V_11 [ 11 ] ;
int V_14 ;
if ( V_7 -> V_9 . V_15 . V_23 <= 0 ||
V_7 -> V_9 . V_15 . V_24 == NULL )
return;
if ( * V_8 & V_25 && * V_8 & V_26 ) {
* V_8 &= ~ V_26 ;
* V_12 = 0 ;
* V_13 = - 1UL ;
} else {
* V_8 &= ~ V_26 ;
* V_8 |= V_25 ;
for ( V_14 = 0 ; V_14 < V_7 -> V_9 . V_15 . V_23 ; V_14 ++ ) {
V_1 = V_7 -> V_9 . V_15 . V_24 [ V_14 ] . V_21 ;
V_4 = V_7 -> V_9 . V_15 . V_24 [ V_14 ] . V_4 ;
F_1 ( V_12 , V_13 , V_1 , V_4 ) ;
}
}
}
void F_4 ( struct V_6 * V_7 )
{
V_7 -> V_9 . V_15 . V_27 = V_7 -> V_9 . V_10 -> V_11 [ 0 ] ;
V_7 -> V_9 . V_15 . V_8 = V_7 -> V_9 . V_10 -> V_11 [ 9 ] ;
V_7 -> V_9 . V_15 . V_12 = V_7 -> V_9 . V_10 -> V_11 [ 10 ] ;
V_7 -> V_9 . V_15 . V_13 = V_7 -> V_9 . V_10 -> V_11 [ 11 ] ;
}
void F_5 ( struct V_6 * V_7 )
{
V_7 -> V_9 . V_10 -> V_11 [ 0 ] = V_7 -> V_9 . V_15 . V_27 ;
V_7 -> V_9 . V_10 -> V_11 [ 9 ] = V_7 -> V_9 . V_15 . V_8 ;
V_7 -> V_9 . V_10 -> V_11 [ 10 ] = V_7 -> V_9 . V_15 . V_12 ;
V_7 -> V_9 . V_10 -> V_11 [ 11 ] = V_7 -> V_9 . V_15 . V_13 ;
}
void F_6 ( struct V_6 * V_7 )
{
if ( F_7 ( V_7 ) ) {
V_7 -> V_9 . V_10 -> V_11 [ 0 ] &= ~ 0x800ul ;
V_7 -> V_9 . V_10 -> V_11 [ 9 ] |= V_20 ;
V_7 -> V_9 . V_10 -> V_11 [ 10 ] = 0 ;
V_7 -> V_9 . V_10 -> V_11 [ 11 ] = - 1UL ;
}
if ( F_8 ( V_7 ) ) {
F_2 ( V_7 ) ;
F_3 ( V_7 ) ;
}
if ( V_7 -> V_9 . V_10 -> V_11 [ 9 ] & V_28 )
V_7 -> V_9 . V_10 -> V_11 [ 9 ] &= ~ V_28 ;
}
static int F_9 ( struct V_6 * V_7 ,
struct V_29 * V_30 ,
struct V_31 * V_32 )
{
int V_33 = 0 ;
V_32 -> V_4 = V_30 -> V_4 ;
V_32 -> V_21 = V_30 -> V_21 ;
V_32 -> V_34 = V_30 -> V_34 ;
V_32 -> V_35 = NULL ;
if ( V_32 -> V_4 < 0 || V_32 -> V_4 > V_36 )
return - V_37 ;
V_32 -> V_35 = F_10 ( V_30 -> V_4 , V_38 ) ;
if ( ! V_32 -> V_35 )
return - V_39 ;
V_33 = F_11 ( V_7 , V_32 -> V_34 , V_32 -> V_35 ,
V_32 -> V_4 ) ;
if ( V_33 ) {
F_12 ( V_32 -> V_35 ) ;
V_32 -> V_35 = NULL ;
}
return V_33 ;
}
int F_13 ( struct V_6 * V_7 ,
struct V_40 * V_41 )
{
int V_33 = 0 , V_42 = 0 , V_43 = 0 , V_14 ;
struct V_29 * V_30 = NULL ;
struct V_31 * V_32 = NULL ;
struct V_44 * V_45 = NULL ;
if ( V_41 -> V_9 . V_16 <= 0 || ! V_41 -> V_9 . V_46 )
return 0 ;
else if ( V_41 -> V_9 . V_16 > V_47 )
return - V_37 ;
V_30 = F_14 ( V_41 -> V_9 . V_46 ,
sizeof( * V_30 ) * V_41 -> V_9 . V_16 ) ;
if ( F_15 ( V_30 ) )
return F_16 ( V_30 ) ;
for ( V_14 = 0 ; V_14 < V_41 -> V_9 . V_16 ; V_14 ++ ) {
switch ( V_30 [ V_14 ] . type ) {
case V_48 :
V_42 ++ ;
break;
case V_49 :
V_43 ++ ;
break;
default:
break;
}
}
if ( V_42 > 0 ) {
V_32 = F_17 ( V_42 ,
sizeof( * V_32 ) ,
V_38 ) ;
if ( ! V_32 ) {
V_33 = - V_39 ;
goto error;
}
}
if ( V_43 > 0 ) {
V_45 = F_17 ( V_43 ,
sizeof( * V_45 ) ,
V_38 ) ;
if ( ! V_45 ) {
V_33 = - V_39 ;
goto error;
}
}
for ( V_42 = 0 , V_43 = 0 , V_14 = 0 ; V_14 < V_41 -> V_9 . V_16 ; V_14 ++ ) {
switch ( V_30 [ V_14 ] . type ) {
case V_48 :
V_33 = F_9 ( V_7 , & V_30 [ V_14 ] ,
& V_32 [ V_42 ] ) ;
if ( V_33 )
goto error;
V_42 ++ ;
break;
case V_49 :
V_45 [ V_43 ] . V_4 = V_30 [ V_14 ] . V_4 ;
V_45 [ V_43 ] . V_21 = V_30 [ V_14 ] . V_21 ;
V_43 ++ ;
break;
}
}
V_7 -> V_9 . V_15 . V_16 = V_43 ;
V_7 -> V_9 . V_15 . V_17 = V_45 ;
V_7 -> V_9 . V_15 . V_23 = V_42 ;
V_7 -> V_9 . V_15 . V_24 = V_32 ;
return 0 ;
error:
F_12 ( V_30 ) ;
F_12 ( V_32 ) ;
F_12 ( V_45 ) ;
return V_33 ;
}
void F_18 ( struct V_6 * V_7 )
{
int V_14 ;
struct V_31 * V_24 = NULL ;
for ( V_14 = 0 ; V_14 < V_7 -> V_9 . V_15 . V_23 ; V_14 ++ ) {
V_24 = & V_7 -> V_9 . V_15 . V_24 [ V_14 ] ;
F_12 ( V_24 -> V_35 ) ;
V_24 -> V_35 = NULL ;
}
F_12 ( V_7 -> V_9 . V_15 . V_24 ) ;
V_7 -> V_9 . V_15 . V_24 = NULL ;
F_12 ( V_7 -> V_9 . V_15 . V_17 ) ;
V_7 -> V_9 . V_15 . V_17 = NULL ;
V_7 -> V_9 . V_15 . V_23 = 0 ;
V_7 -> V_9 . V_15 . V_16 = 0 ;
}
static inline int F_19 ( T_1 V_21 , T_1 V_50 , T_1 V_51 )
{
if ( V_50 <= V_51 )
return ( V_21 >= V_50 ) && ( V_21 <= V_51 ) ;
else
return ( V_21 <= V_50 ) && ( V_21 >= V_51 ) ;
}
static struct V_44 * F_20 ( struct V_6 * V_7 ,
unsigned long V_21 )
{
struct V_44 * V_45 = V_7 -> V_9 . V_15 . V_17 ;
int V_14 ;
if ( V_7 -> V_9 . V_15 . V_16 == 0 )
return NULL ;
for ( V_14 = 0 ; V_14 < V_7 -> V_9 . V_15 . V_16 ; V_14 ++ ) {
if ( V_21 == V_45 -> V_21 )
goto V_52;
if ( V_45 -> V_4 > 0 &&
F_19 ( V_21 , V_45 -> V_21 , F_21 ( V_45 ) ) )
goto V_52;
V_45 ++ ;
}
return NULL ;
V_52:
return V_45 ;
}
static struct V_31 * F_22 ( struct V_6 * V_7 )
{
int V_14 ;
struct V_31 * V_32 = NULL ;
void * V_53 = NULL ;
if ( V_7 -> V_9 . V_15 . V_23 == 0 )
return NULL ;
for ( V_14 = 0 ; V_14 < V_7 -> V_9 . V_15 . V_23 ; V_14 ++ ) {
V_32 = & V_7 -> V_9 . V_15 . V_24 [ V_14 ] ;
if ( ! V_32 || ! V_32 -> V_35 || V_32 -> V_4 <= 0 )
continue;
V_53 = F_10 ( V_32 -> V_4 , V_38 ) ;
if ( ! V_53 )
continue;
if ( ! F_11 ( V_7 , V_32 -> V_34 , V_53 ,
V_32 -> V_4 ) ) {
if ( memcmp ( V_53 , V_32 -> V_35 , V_32 -> V_4 ) ) {
F_12 ( V_53 ) ;
return V_32 ;
}
}
F_12 ( V_53 ) ;
V_53 = NULL ;
}
return NULL ;
}
void F_23 ( struct V_6 * V_7 )
{
V_7 -> V_54 -> V_55 = V_56 ;
V_7 -> V_57 &= ~ V_58 ;
}
static int F_24 ( struct V_6 * V_7 , T_2 V_59 ,
unsigned long V_60 )
{
struct V_61 * V_62 = & V_7 -> V_54 -> V_63 . V_9 ;
struct V_31 * V_32 = NULL ;
struct V_44 * V_45 = NULL ;
unsigned long V_21 = V_7 -> V_9 . V_10 -> V_64 . V_21 ;
if ( F_8 ( V_7 ) ) {
if ( F_25 ( V_59 ) &&
V_7 -> V_9 . V_15 . V_23 > 0 ) {
V_32 = F_22 ( V_7 ) ;
if ( V_32 ) {
V_62 -> V_21 = V_32 -> V_21 ;
V_62 -> type = V_48 ;
goto V_65;
}
}
if ( F_26 ( V_59 ) &&
V_7 -> V_9 . V_15 . V_16 > 0 ) {
V_45 = F_20 ( V_7 , V_21 ) ;
if ( V_45 && ( V_21 != V_60 ) ) {
V_62 -> V_21 = V_21 ;
V_62 -> type = V_49 ;
V_7 -> V_9 . V_15 . V_66 = V_21 ;
goto V_65;
}
V_45 = F_20 ( V_7 , V_60 ) ;
if ( V_45 && V_7 -> V_9 . V_15 . V_66 != V_60 ) {
V_62 -> V_21 = V_60 ;
V_62 -> type = V_49 ;
goto V_65;
}
}
}
if ( F_7 ( V_7 ) && F_26 ( V_59 ) ) {
V_62 -> V_21 = V_21 ;
V_62 -> type = V_67 ;
goto V_65;
}
return 0 ;
V_65:
return 1 ;
}
static int F_27 ( struct V_6 * V_7 , unsigned long * V_21 )
{
T_2 V_68 = 0 ;
T_3 V_69 [ 3 ] ;
int V_70 ;
if ( V_7 -> V_9 . V_10 -> V_71 == V_72 ) {
* V_21 = V_7 -> V_9 . V_10 -> V_60 ;
V_70 = F_28 ( V_7 , * V_21 , & V_69 , 2 ) ;
if ( V_70 )
return V_70 ;
if ( V_69 [ 0 ] >> 8 == 0x44 )
V_68 = 4 ;
if ( ( V_69 [ 0 ] & 0xff0f ) == 0xc600 )
V_68 = 6 ;
} else {
* V_21 = F_29 ( V_7 -> V_9 . V_10 -> V_64 ,
F_30 ( V_7 ) ) ;
if ( V_7 -> V_9 . V_10 -> V_73 & 0x01 ) {
V_68 = ( V_7 -> V_9 . V_10 -> V_73 & 0x60 ) >> 4 ;
if ( ! V_68 )
V_68 = 4 ;
}
}
if ( V_68 ) {
V_70 = F_28 ( V_7 , * V_21 , & V_69 , V_68 ) ;
if ( V_70 )
return V_70 ;
if ( V_68 == 6 ) {
T_4 V_74 = * ( ( T_4 * ) ( V_69 + 1 ) ) ;
* V_21 += ( T_1 ) ( V_75 ) V_74 * 2 ;
} else {
T_5 V_76 = ( V_69 [ 1 ] & 0xf000 ) >> 12 ;
T_5 V_77 = V_69 [ 1 ] & 0x0fff ;
T_5 V_78 = V_69 [ 0 ] & 0x000f ;
* V_21 = V_76 ? V_7 -> V_54 -> V_79 . V_80 . V_81 [ V_76 ] : 0 ;
* V_21 += V_78 ? V_7 -> V_54 -> V_79 . V_80 . V_81 [ V_78 ] : 0 ;
* V_21 += V_77 ;
}
* V_21 = F_31 ( V_7 , * V_21 ) ;
}
return 0 ;
}
int F_32 ( struct V_6 * V_7 )
{
const T_1 V_12 = V_7 -> V_9 . V_10 -> V_11 [ 10 ] ;
const T_1 V_13 = V_7 -> V_9 . V_10 -> V_11 [ 11 ] ;
const T_2 V_82 = F_30 ( V_7 ) ;
struct V_83 V_84 = {
. V_85 = V_86 ,
. V_87 = V_88 ,
. V_89 = F_29 ( V_7 -> V_9 . V_10 -> V_64 , V_82 ) ,
} ;
unsigned long V_90 ;
int V_70 ;
if ( ! F_33 ( V_7 ) )
return F_34 ( V_7 , & V_84 ) ;
if ( F_24 ( V_7 , V_84 . V_87 , V_84 . V_89 ) )
V_7 -> V_57 |= V_58 ;
if ( ! F_35 ( V_7 ) ||
! ( V_7 -> V_9 . V_10 -> V_11 [ 9 ] & V_20 ) )
return 0 ;
V_70 = F_27 ( V_7 , & V_90 ) ;
if ( V_70 < 0 )
return V_70 ;
if ( V_70 )
return F_36 ( V_7 , V_91 ) ;
if ( F_19 ( V_90 , V_12 , V_13 ) )
return F_34 ( V_7 , & V_84 ) ;
return 0 ;
}
static int F_37 ( struct V_6 * V_7 )
{
const T_2 V_59 = V_7 -> V_9 . V_10 -> V_59 ;
T_1 V_21 = V_7 -> V_9 . V_10 -> V_64 . V_21 ;
T_1 V_8 = V_7 -> V_9 . V_10 -> V_11 [ 9 ] ;
T_1 V_12 = V_7 -> V_9 . V_10 -> V_11 [ 10 ] ;
T_1 V_13 = V_7 -> V_9 . V_10 -> V_11 [ 11 ] ;
T_2 V_92 = V_59 & ( V_8 >> 24 ) & V_93 ;
unsigned long V_90 ;
int V_70 ;
if ( ! F_35 ( V_7 ) )
V_92 = 0 ;
if ( V_92 & V_94 &&
V_8 & V_19 &&
! F_19 ( V_21 , V_12 , V_13 ) )
V_92 &= ~ V_94 ;
if ( V_92 & V_88 ) {
V_70 = F_27 ( V_7 , & V_90 ) ;
if ( V_70 < 0 )
return V_70 ;
if ( V_70 || ! F_19 ( V_90 , V_12 , V_13 ) )
V_92 &= ~ V_88 ;
}
V_7 -> V_9 . V_10 -> V_59 = V_92 ;
if ( ! V_92 )
V_7 -> V_9 . V_10 -> V_95 &= ~ V_86 ;
return 0 ;
}
int F_38 ( struct V_6 * V_7 )
{
int V_70 , V_96 ;
if ( F_24 ( V_7 , V_7 -> V_9 . V_10 -> V_59 ,
V_7 -> V_9 . V_10 -> V_60 ) )
V_7 -> V_57 |= V_58 ;
V_70 = F_37 ( V_7 ) ;
if ( V_70 )
return V_70 ;
if ( V_7 -> V_9 . V_10 -> V_95 == V_97 ) {
V_7 -> V_9 . V_10 -> V_95 = 0 ;
V_96 = F_39 ( V_7 -> V_9 . V_10 -> V_64 ) . V_98 ;
if ( ( ( V_96 == V_99 ) ^ F_40 ( V_7 ) ) &&
( F_41 ( V_7 ) || F_42 ( V_7 ) ) )
V_7 -> V_9 . V_10 -> V_95 = V_97 ;
if ( V_96 == V_100 && ! F_40 ( V_7 ) &&
( F_41 ( V_7 ) || F_43 ( V_7 ) ) )
V_7 -> V_9 . V_10 -> V_95 = V_97 ;
}
return 0 ;
}
