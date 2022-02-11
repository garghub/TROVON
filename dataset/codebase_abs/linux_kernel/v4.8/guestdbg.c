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
int V_33 = 0 , V_42 = 0 , V_43 = 0 , V_14 , V_44 ;
struct V_29 * V_30 = NULL ;
struct V_31 * V_32 = NULL ;
struct V_45 * V_46 = NULL ;
if ( V_41 -> V_9 . V_16 <= 0 || ! V_41 -> V_9 . V_47 )
return 0 ;
else if ( V_41 -> V_9 . V_16 > V_48 )
return - V_37 ;
V_44 = V_41 -> V_9 . V_16 * sizeof( struct V_29 ) ;
V_30 = F_10 ( V_44 , V_38 ) ;
if ( ! V_30 ) {
V_33 = - V_39 ;
goto error;
}
if ( F_14 ( V_30 , V_41 -> V_9 . V_47 , V_44 ) ) {
V_33 = - V_49 ;
goto error;
}
for ( V_14 = 0 ; V_14 < V_41 -> V_9 . V_16 ; V_14 ++ ) {
switch ( V_30 [ V_14 ] . type ) {
case V_50 :
V_42 ++ ;
break;
case V_51 :
V_43 ++ ;
break;
default:
break;
}
}
V_44 = V_42 * sizeof( struct V_31 ) ;
if ( V_44 > 0 ) {
V_32 = F_10 ( V_44 , V_38 ) ;
if ( ! V_32 ) {
V_33 = - V_39 ;
goto error;
}
}
V_44 = V_43 * sizeof( struct V_45 ) ;
if ( V_44 > 0 ) {
V_46 = F_10 ( V_44 , V_38 ) ;
if ( ! V_46 ) {
V_33 = - V_39 ;
goto error;
}
}
for ( V_42 = 0 , V_43 = 0 , V_14 = 0 ; V_14 < V_41 -> V_9 . V_16 ; V_14 ++ ) {
switch ( V_30 [ V_14 ] . type ) {
case V_50 :
V_33 = F_9 ( V_7 , & V_30 [ V_14 ] ,
& V_32 [ V_42 ] ) ;
if ( V_33 )
goto error;
V_42 ++ ;
break;
case V_51 :
V_46 [ V_43 ] . V_4 = V_30 [ V_14 ] . V_4 ;
V_46 [ V_43 ] . V_21 = V_30 [ V_14 ] . V_21 ;
V_43 ++ ;
break;
}
}
V_7 -> V_9 . V_15 . V_16 = V_43 ;
V_7 -> V_9 . V_15 . V_17 = V_46 ;
V_7 -> V_9 . V_15 . V_23 = V_42 ;
V_7 -> V_9 . V_15 . V_24 = V_32 ;
return 0 ;
error:
F_12 ( V_30 ) ;
F_12 ( V_32 ) ;
F_12 ( V_46 ) ;
return V_33 ;
}
void F_15 ( struct V_6 * V_7 )
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
static inline int F_16 ( T_1 V_21 , T_1 V_52 , T_1 V_53 )
{
if ( V_52 <= V_53 )
return ( V_21 >= V_52 ) && ( V_21 <= V_53 ) ;
else
return ( V_21 <= V_52 ) && ( V_21 >= V_53 ) ;
}
static struct V_45 * F_17 ( struct V_6 * V_7 ,
unsigned long V_21 )
{
struct V_45 * V_46 = V_7 -> V_9 . V_15 . V_17 ;
int V_14 ;
if ( V_7 -> V_9 . V_15 . V_16 == 0 )
return NULL ;
for ( V_14 = 0 ; V_14 < V_7 -> V_9 . V_15 . V_16 ; V_14 ++ ) {
if ( V_21 == V_46 -> V_21 )
goto V_54;
if ( V_46 -> V_4 > 0 &&
F_16 ( V_21 , V_46 -> V_21 , F_18 ( V_46 ) ) )
goto V_54;
V_46 ++ ;
}
return NULL ;
V_54:
return V_46 ;
}
static struct V_31 * F_19 ( struct V_6 * V_7 )
{
int V_14 ;
struct V_31 * V_32 = NULL ;
void * V_55 = NULL ;
if ( V_7 -> V_9 . V_15 . V_23 == 0 )
return NULL ;
for ( V_14 = 0 ; V_14 < V_7 -> V_9 . V_15 . V_23 ; V_14 ++ ) {
V_32 = & V_7 -> V_9 . V_15 . V_24 [ V_14 ] ;
if ( ! V_32 || ! V_32 -> V_35 || V_32 -> V_4 <= 0 )
continue;
V_55 = F_10 ( V_32 -> V_4 , V_38 ) ;
if ( ! V_55 )
continue;
if ( ! F_11 ( V_7 , V_32 -> V_34 , V_55 ,
V_32 -> V_4 ) ) {
if ( memcmp ( V_55 , V_32 -> V_35 , V_32 -> V_4 ) ) {
F_12 ( V_55 ) ;
return V_32 ;
}
}
F_12 ( V_55 ) ;
V_55 = NULL ;
}
return NULL ;
}
void F_20 ( struct V_6 * V_7 )
{
V_7 -> V_56 -> V_57 = V_58 ;
V_7 -> V_59 &= ~ V_60 ;
}
static int F_21 ( struct V_6 * V_7 )
{
T_2 V_61 = ( V_7 -> V_9 . V_10 -> V_61 << 24 ) ;
struct V_62 * V_63 = & V_7 -> V_56 -> V_64 . V_9 ;
struct V_31 * V_32 = NULL ;
struct V_45 * V_46 = NULL ;
unsigned long V_21 = V_7 -> V_9 . V_10 -> V_65 . V_21 ;
unsigned long V_66 = V_7 -> V_9 . V_10 -> V_66 ;
if ( F_8 ( V_7 ) ) {
if ( F_22 ( V_61 ) &&
V_7 -> V_9 . V_15 . V_23 > 0 ) {
V_32 = F_19 ( V_7 ) ;
if ( V_32 ) {
V_63 -> V_21 = V_32 -> V_21 ;
V_63 -> type = V_50 ;
goto V_67;
}
}
if ( F_23 ( V_61 ) &&
V_7 -> V_9 . V_15 . V_16 > 0 ) {
V_46 = F_17 ( V_7 , V_21 ) ;
if ( V_46 && ( V_21 != V_66 ) ) {
V_63 -> V_21 = V_21 ;
V_63 -> type = V_51 ;
V_7 -> V_9 . V_15 . V_68 = V_21 ;
goto V_67;
}
V_46 = F_17 ( V_7 , V_66 ) ;
if ( V_46 && V_7 -> V_9 . V_15 . V_68 != V_66 ) {
V_63 -> V_21 = V_66 ;
V_63 -> type = V_51 ;
goto V_67;
}
}
}
if ( F_7 ( V_7 ) && F_23 ( V_61 ) ) {
V_63 -> V_21 = V_21 ;
V_63 -> type = V_69 ;
goto V_67;
}
return 0 ;
V_67:
return 1 ;
}
int F_24 ( struct V_6 * V_7 )
{
const T_3 V_70 = F_25 ( V_7 ) ;
struct V_71 V_72 = {
. V_73 = V_74 ,
. V_75 = V_20 >> 24 ,
. V_76 = F_26 ( V_7 -> V_9 . V_10 -> V_65 , V_70 ) ,
} ;
return F_27 ( V_7 , & V_72 ) ;
}
static void F_28 ( struct V_6 * V_7 )
{
T_2 V_61 = V_7 -> V_9 . V_10 -> V_61 << 24 ;
T_1 V_66 = V_7 -> V_9 . V_10 -> V_66 ;
T_1 V_21 = V_7 -> V_9 . V_10 -> V_65 . V_21 ;
T_1 V_8 = V_7 -> V_9 . V_10 -> V_11 [ 9 ] ;
T_1 V_12 = V_7 -> V_9 . V_10 -> V_11 [ 10 ] ;
T_1 V_13 = V_7 -> V_9 . V_10 -> V_11 [ 11 ] ;
T_2 V_77 = V_61 & V_8 & V_78 ;
if ( ! F_29 ( V_7 ) )
V_77 = 0 ;
if ( V_77 & V_18 &&
V_8 & V_19 &&
! F_16 ( V_21 , V_12 , V_13 ) )
V_77 &= ~ V_18 ;
if ( V_77 & V_20 &&
! F_16 ( V_66 , V_12 , V_13 ) )
V_77 &= ~ V_20 ;
V_7 -> V_9 . V_10 -> V_61 = V_77 >> 24 ;
if ( ! V_77 )
V_7 -> V_9 . V_10 -> V_79 &= ~ V_74 ;
}
void F_30 ( struct V_6 * V_7 )
{
int V_80 ;
if ( F_21 ( V_7 ) )
V_7 -> V_59 |= V_60 ;
F_28 ( V_7 ) ;
if ( V_7 -> V_9 . V_10 -> V_79 == V_81 ) {
V_7 -> V_9 . V_10 -> V_79 = 0 ;
V_80 = F_31 ( V_7 -> V_9 . V_10 -> V_65 ) . V_82 ;
if ( ( ( V_80 == V_83 ) ^ F_32 ( V_7 ) ) &&
( F_33 ( V_7 ) || F_34 ( V_7 ) ) )
V_7 -> V_9 . V_10 -> V_79 = V_81 ;
if ( V_80 == V_84 && ! F_32 ( V_7 ) &&
( F_33 ( V_7 ) || F_35 ( V_7 ) ) )
V_7 -> V_9 . V_10 -> V_79 = V_81 ;
}
}
