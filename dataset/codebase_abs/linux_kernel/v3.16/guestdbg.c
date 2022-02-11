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
* V_13 = V_27 ;
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
V_7 -> V_9 . V_15 . V_28 = V_7 -> V_9 . V_10 -> V_11 [ 0 ] ;
V_7 -> V_9 . V_15 . V_8 = V_7 -> V_9 . V_10 -> V_11 [ 9 ] ;
V_7 -> V_9 . V_15 . V_12 = V_7 -> V_9 . V_10 -> V_11 [ 10 ] ;
V_7 -> V_9 . V_15 . V_13 = V_7 -> V_9 . V_10 -> V_11 [ 11 ] ;
}
void F_5 ( struct V_6 * V_7 )
{
V_7 -> V_9 . V_10 -> V_11 [ 0 ] = V_7 -> V_9 . V_15 . V_28 ;
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
V_7 -> V_9 . V_10 -> V_11 [ 11 ] = V_27 ;
}
if ( F_8 ( V_7 ) ) {
F_2 ( V_7 ) ;
F_3 ( V_7 ) ;
}
if ( V_7 -> V_9 . V_10 -> V_11 [ 9 ] & V_29 )
V_7 -> V_9 . V_10 -> V_11 [ 9 ] &= ~ V_29 ;
}
static int F_9 ( struct V_6 * V_7 ,
struct V_30 * V_31 ,
struct V_32 * V_33 )
{
int V_34 = 0 ;
V_33 -> V_4 = V_31 -> V_4 ;
V_33 -> V_21 = V_31 -> V_21 ;
V_33 -> V_35 = V_31 -> V_35 ;
V_33 -> V_36 = NULL ;
if ( V_33 -> V_4 < 0 || V_33 -> V_4 > V_37 )
return - V_38 ;
V_33 -> V_36 = F_10 ( V_31 -> V_4 , V_39 ) ;
if ( ! V_33 -> V_36 )
return - V_40 ;
V_34 = F_11 ( V_7 , V_33 -> V_35 , V_33 -> V_36 ,
V_33 -> V_4 ) ;
if ( V_34 ) {
F_12 ( V_33 -> V_36 ) ;
V_33 -> V_36 = NULL ;
}
return V_34 ;
}
int F_13 ( struct V_6 * V_7 ,
struct V_41 * V_42 )
{
int V_34 = 0 , V_43 = 0 , V_44 = 0 , V_14 , V_45 ;
struct V_30 * V_31 = NULL ;
struct V_32 * V_33 = NULL ;
struct V_46 * V_47 = NULL ;
if ( V_42 -> V_9 . V_16 <= 0 || ! V_42 -> V_9 . V_48 )
return 0 ;
else if ( V_42 -> V_9 . V_16 > V_49 )
return - V_38 ;
V_45 = V_42 -> V_9 . V_16 * sizeof( struct V_30 ) ;
V_31 = F_10 ( V_45 , V_39 ) ;
if ( ! V_31 ) {
V_34 = - V_40 ;
goto error;
}
if ( F_14 ( V_31 , V_42 -> V_9 . V_48 , V_45 ) ) {
V_34 = - V_50 ;
goto error;
}
for ( V_14 = 0 ; V_14 < V_42 -> V_9 . V_16 ; V_14 ++ ) {
switch ( V_31 [ V_14 ] . type ) {
case V_51 :
V_43 ++ ;
break;
case V_52 :
V_44 ++ ;
break;
default:
break;
}
}
V_45 = V_43 * sizeof( struct V_32 ) ;
if ( V_45 > 0 ) {
V_33 = F_10 ( V_45 , V_39 ) ;
if ( ! V_33 ) {
V_34 = - V_40 ;
goto error;
}
}
V_45 = V_44 * sizeof( struct V_46 ) ;
if ( V_45 > 0 ) {
V_47 = F_10 ( V_45 , V_39 ) ;
if ( ! V_47 ) {
V_34 = - V_40 ;
goto error;
}
}
for ( V_43 = 0 , V_44 = 0 , V_14 = 0 ; V_14 < V_42 -> V_9 . V_16 ; V_14 ++ ) {
switch ( V_31 [ V_14 ] . type ) {
case V_51 :
V_34 = F_9 ( V_7 , & V_31 [ V_14 ] ,
& V_33 [ V_43 ] ) ;
if ( V_34 )
goto error;
V_43 ++ ;
break;
case V_52 :
V_47 [ V_44 ] . V_4 = V_31 [ V_14 ] . V_4 ;
V_47 [ V_44 ] . V_21 = V_31 [ V_14 ] . V_21 ;
V_44 ++ ;
break;
}
}
V_7 -> V_9 . V_15 . V_16 = V_44 ;
V_7 -> V_9 . V_15 . V_17 = V_47 ;
V_7 -> V_9 . V_15 . V_23 = V_43 ;
V_7 -> V_9 . V_15 . V_24 = V_33 ;
return 0 ;
error:
F_12 ( V_31 ) ;
F_12 ( V_33 ) ;
F_12 ( V_47 ) ;
return V_34 ;
}
void F_15 ( struct V_6 * V_7 )
{
int V_14 ;
struct V_32 * V_24 = NULL ;
for ( V_14 = 0 ; V_14 < V_7 -> V_9 . V_15 . V_23 ; V_14 ++ ) {
V_24 = & V_7 -> V_9 . V_15 . V_24 [ V_14 ] ;
F_12 ( V_24 -> V_36 ) ;
V_24 -> V_36 = NULL ;
}
F_12 ( V_7 -> V_9 . V_15 . V_24 ) ;
V_7 -> V_9 . V_15 . V_24 = NULL ;
F_12 ( V_7 -> V_9 . V_15 . V_17 ) ;
V_7 -> V_9 . V_15 . V_17 = NULL ;
V_7 -> V_9 . V_15 . V_23 = 0 ;
V_7 -> V_9 . V_15 . V_16 = 0 ;
}
static inline int F_16 ( T_1 V_21 , T_1 V_53 , T_1 V_54 )
{
if ( V_53 <= V_54 )
return ( V_21 >= V_53 ) && ( V_21 <= V_54 ) ;
else
return ( V_21 <= V_53 ) && ( V_21 >= V_54 ) ;
}
static struct V_46 * F_17 ( struct V_6 * V_7 ,
unsigned long V_21 )
{
struct V_46 * V_47 = V_7 -> V_9 . V_15 . V_17 ;
int V_14 ;
if ( V_7 -> V_9 . V_15 . V_16 == 0 )
return NULL ;
for ( V_14 = 0 ; V_14 < V_7 -> V_9 . V_15 . V_16 ; V_14 ++ ) {
if ( V_21 == V_47 -> V_21 )
goto V_55;
if ( V_47 -> V_4 > 0 &&
F_16 ( V_21 , V_47 -> V_21 , F_18 ( V_47 ) ) )
goto V_55;
V_47 ++ ;
}
return NULL ;
V_55:
return V_47 ;
}
static struct V_32 * F_19 ( struct V_6 * V_7 )
{
int V_14 ;
struct V_32 * V_33 = NULL ;
void * V_56 = NULL ;
if ( V_7 -> V_9 . V_15 . V_23 == 0 )
return NULL ;
for ( V_14 = 0 ; V_14 < V_7 -> V_9 . V_15 . V_23 ; V_14 ++ ) {
V_33 = & V_7 -> V_9 . V_15 . V_24 [ V_14 ] ;
if ( ! V_33 || ! V_33 -> V_36 || V_33 -> V_4 <= 0 )
continue;
V_56 = F_10 ( V_33 -> V_4 , V_39 ) ;
if ( ! V_56 )
continue;
if ( ! F_11 ( V_7 , V_33 -> V_35 , V_56 ,
V_33 -> V_4 ) ) {
if ( memcmp ( V_56 , V_33 -> V_36 , V_33 -> V_4 ) ) {
F_12 ( V_56 ) ;
return V_33 ;
}
}
F_12 ( V_56 ) ;
V_56 = NULL ;
}
return NULL ;
}
void F_20 ( struct V_6 * V_7 )
{
V_7 -> V_57 -> V_58 = V_59 ;
V_7 -> V_60 &= ~ V_61 ;
}
static int F_21 ( struct V_6 * V_7 )
{
T_2 V_62 = ( V_7 -> V_9 . V_10 -> V_62 << 24 ) ;
struct V_63 * V_64 = & V_7 -> V_57 -> V_65 . V_9 ;
struct V_32 * V_33 = NULL ;
struct V_46 * V_47 = NULL ;
unsigned long V_21 = V_7 -> V_9 . V_10 -> V_66 . V_21 ;
unsigned long V_67 = V_7 -> V_9 . V_10 -> V_67 ;
if ( F_8 ( V_7 ) ) {
if ( F_22 ( V_62 ) &&
V_7 -> V_9 . V_15 . V_23 > 0 ) {
V_33 = F_19 ( V_7 ) ;
if ( V_33 ) {
V_64 -> V_21 = V_33 -> V_21 ;
V_64 -> type = V_51 ;
goto V_68;
}
}
if ( F_23 ( V_62 ) &&
V_7 -> V_9 . V_15 . V_16 > 0 ) {
V_47 = F_17 ( V_7 , V_21 ) ;
if ( V_47 && ( V_21 != V_67 ) ) {
V_64 -> V_21 = V_21 ;
V_64 -> type = V_52 ;
V_7 -> V_9 . V_15 . V_69 = V_21 ;
goto V_68;
}
V_47 = F_17 ( V_7 , V_67 ) ;
if ( V_47 && V_7 -> V_9 . V_15 . V_69 != V_67 ) {
V_64 -> V_21 = V_67 ;
V_64 -> type = V_52 ;
goto V_68;
}
}
}
if ( F_7 ( V_7 ) && F_23 ( V_62 ) ) {
V_64 -> V_21 = V_21 ;
V_64 -> type = V_70 ;
goto V_68;
}
return 0 ;
V_68:
return 1 ;
}
static void F_24 ( struct V_6 * V_7 )
{
T_2 V_62 = V_7 -> V_9 . V_10 -> V_62 << 24 ;
T_1 V_67 = V_7 -> V_9 . V_10 -> V_67 ;
T_1 V_21 = V_7 -> V_9 . V_10 -> V_66 . V_21 ;
T_1 V_8 = V_7 -> V_9 . V_10 -> V_11 [ 9 ] ;
T_1 V_12 = V_7 -> V_9 . V_10 -> V_11 [ 10 ] ;
T_1 V_13 = V_7 -> V_9 . V_10 -> V_11 [ 11 ] ;
T_2 V_71 = V_62 & V_8 & V_72 ;
if ( ! F_25 ( V_7 ) )
V_71 = 0 ;
if ( V_71 & V_18 &&
V_8 & V_19 &&
! F_16 ( V_21 , V_12 , V_13 ) )
V_71 &= ~ V_18 ;
if ( V_71 & V_20 &&
! F_16 ( V_67 , V_12 , V_13 ) )
V_71 &= ~ V_20 ;
V_7 -> V_9 . V_10 -> V_62 = V_71 >> 24 ;
if ( ! V_71 )
V_7 -> V_9 . V_10 -> V_73 &= ~ V_74 ;
}
void F_26 ( struct V_6 * V_7 )
{
if ( F_21 ( V_7 ) )
V_7 -> V_60 |= V_61 ;
F_24 ( V_7 ) ;
}
