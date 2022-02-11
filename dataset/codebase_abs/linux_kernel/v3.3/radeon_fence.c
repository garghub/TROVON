static void F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
if ( V_2 -> V_5 . V_6 ) {
* V_2 -> V_7 [ V_4 ] . V_8 = F_2 ( V_3 ) ;
} else {
F_3 ( V_2 -> V_7 [ V_4 ] . V_9 , V_3 ) ;
}
}
static T_1 F_4 ( struct V_1 * V_2 , int V_4 )
{
T_1 V_3 = 0 ;
if ( V_2 -> V_5 . V_6 ) {
V_3 = F_5 ( * V_2 -> V_7 [ V_4 ] . V_8 ) ;
} else {
V_3 = F_6 ( V_2 -> V_7 [ V_4 ] . V_9 ) ;
}
return V_3 ;
}
int F_7 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
unsigned long V_12 ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
if ( V_11 -> V_14 ) {
F_9 ( & V_2 -> V_13 , V_12 ) ;
return 0 ;
}
V_11 -> V_3 = F_10 ( 1 , & V_2 -> V_7 [ V_11 -> V_4 ] . V_3 ) ;
if ( ! V_2 -> V_4 [ V_11 -> V_4 ] . V_15 )
F_1 ( V_2 , V_11 -> V_3 , V_11 -> V_4 ) ;
else
F_11 ( V_2 , V_11 -> V_4 , V_11 ) ;
F_12 ( V_2 -> V_16 , V_11 -> V_3 ) ;
V_11 -> V_14 = true ;
F_13 ( & V_11 -> V_17 , & V_2 -> V_7 [ V_11 -> V_4 ] . V_14 ) ;
F_9 ( & V_2 -> V_13 , V_12 ) ;
return 0 ;
}
static bool F_14 ( struct V_1 * V_2 , int V_4 )
{
struct V_10 * V_11 ;
struct V_18 * V_19 , * V_20 ;
T_2 V_3 ;
bool V_21 = false ;
unsigned long V_22 ;
V_3 = F_4 ( V_2 , V_4 ) ;
if ( V_3 != V_2 -> V_7 [ V_4 ] . V_23 ) {
V_2 -> V_7 [ V_4 ] . V_23 = V_3 ;
V_2 -> V_7 [ V_4 ] . V_24 = V_25 ;
V_2 -> V_7 [ V_4 ] . V_26 = V_27 ;
} else {
V_22 = V_25 ;
if ( F_15 ( V_22 , V_2 -> V_7 [ V_4 ] . V_24 ) ) {
V_22 -= V_2 -> V_7 [ V_4 ] . V_24 ;
if ( F_15 ( V_2 -> V_7 [ V_4 ] . V_26 , V_22 ) ) {
V_2 -> V_7 [ V_4 ] . V_26 -= V_22 ;
} else {
V_2 -> V_7 [ V_4 ] . V_26 = 1 ;
}
} else {
V_2 -> V_7 [ V_4 ] . V_24 = V_22 ;
}
return false ;
}
V_20 = NULL ;
F_16 (i, &rdev->fence_drv[ring].emitted) {
V_11 = F_17 ( V_19 , struct V_10 , V_17 ) ;
if ( V_11 -> V_3 == V_3 ) {
V_20 = V_19 ;
break;
}
}
if ( V_20 ) {
V_19 = V_20 ;
do {
V_20 = V_19 -> V_28 ;
F_13 ( V_19 , & V_2 -> V_7 [ V_4 ] . V_29 ) ;
V_11 = F_17 ( V_19 , struct V_10 , V_17 ) ;
V_11 -> V_29 = true ;
V_19 = V_20 ;
} while ( V_19 != & V_2 -> V_7 [ V_4 ] . V_14 );
V_21 = true ;
}
return V_21 ;
}
static void F_18 ( struct V_30 * V_30 )
{
unsigned long V_12 ;
struct V_10 * V_11 ;
V_11 = F_19 ( V_30 , struct V_10 , V_30 ) ;
F_8 ( & V_11 -> V_2 -> V_13 , V_12 ) ;
F_20 ( & V_11 -> V_17 ) ;
V_11 -> V_14 = false ;
F_9 ( & V_11 -> V_2 -> V_13 , V_12 ) ;
if ( V_11 -> V_31 )
F_21 ( V_11 -> V_2 , V_11 -> V_31 ) ;
F_22 ( V_11 ) ;
}
int F_23 ( struct V_1 * V_2 ,
struct V_10 * * V_11 ,
int V_4 )
{
unsigned long V_12 ;
* V_11 = F_24 ( sizeof( struct V_10 ) , V_32 ) ;
if ( ( * V_11 ) == NULL ) {
return - V_33 ;
}
F_25 ( & ( ( * V_11 ) -> V_30 ) ) ;
( * V_11 ) -> V_2 = V_2 ;
( * V_11 ) -> V_14 = false ;
( * V_11 ) -> V_29 = false ;
( * V_11 ) -> V_3 = 0 ;
( * V_11 ) -> V_4 = V_4 ;
( * V_11 ) -> V_31 = NULL ;
F_26 ( & ( * V_11 ) -> V_17 ) ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
F_27 ( & ( * V_11 ) -> V_17 , & V_2 -> V_7 [ V_4 ] . V_34 ) ;
F_9 ( & V_2 -> V_13 , V_12 ) ;
return 0 ;
}
bool F_28 ( struct V_10 * V_11 )
{
unsigned long V_12 ;
bool V_29 = false ;
if ( ! V_11 )
return true ;
if ( V_11 -> V_2 -> V_35 )
return true ;
F_8 ( & V_11 -> V_2 -> V_13 , V_12 ) ;
V_29 = V_11 -> V_29 ;
if ( V_11 -> V_2 -> V_36 ) {
V_29 = true ;
}
if ( ! V_11 -> V_14 ) {
F_29 ( 1 , L_1 , V_11 ) ;
V_29 = true ;
}
if ( ! V_29 ) {
F_14 ( V_11 -> V_2 , V_11 -> V_4 ) ;
V_29 = V_11 -> V_29 ;
}
F_9 ( & V_11 -> V_2 -> V_13 , V_12 ) ;
return V_29 ;
}
int F_30 ( struct V_10 * V_11 , bool V_37 )
{
struct V_1 * V_2 ;
unsigned long V_12 , V_38 ;
T_1 V_3 ;
int V_39 ;
if ( V_11 == NULL ) {
F_29 ( 1 , L_2 , V_11 ) ;
return 0 ;
}
V_2 = V_11 -> V_2 ;
if ( F_28 ( V_11 ) ) {
return 0 ;
}
V_38 = V_2 -> V_7 [ V_11 -> V_4 ] . V_26 ;
V_40:
V_3 = V_2 -> V_7 [ V_11 -> V_4 ] . V_23 ;
F_31 ( V_2 -> V_16 , V_3 ) ;
if ( V_37 ) {
F_32 ( V_2 , V_11 -> V_4 ) ;
V_39 = F_33 ( V_2 -> V_7 [ V_11 -> V_4 ] . V_41 ,
F_28 ( V_11 ) , V_38 ) ;
F_34 ( V_2 , V_11 -> V_4 ) ;
if ( F_35 ( V_39 < 0 ) ) {
return V_39 ;
}
} else {
F_32 ( V_2 , V_11 -> V_4 ) ;
V_39 = F_36 ( V_2 -> V_7 [ V_11 -> V_4 ] . V_41 ,
F_28 ( V_11 ) , V_38 ) ;
F_34 ( V_2 , V_11 -> V_4 ) ;
}
F_37 ( V_2 -> V_16 , V_3 ) ;
if ( F_35 ( ! F_28 ( V_11 ) ) ) {
if ( V_39 ) {
V_38 = V_39 ;
goto V_40;
}
if ( V_3 == V_2 -> V_7 [ V_11 -> V_4 ] . V_23 &&
F_38 ( V_2 , & V_2 -> V_4 [ V_11 -> V_4 ] ) ) {
F_39 ( V_42 L_3 ,
V_11 -> V_3 , V_3 ) ;
V_2 -> V_35 = true ;
V_39 = F_40 ( V_2 ) ;
if ( V_39 )
return V_39 ;
F_1 ( V_2 , V_11 -> V_3 , V_11 -> V_4 ) ;
V_2 -> V_35 = false ;
}
V_38 = V_27 ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
V_2 -> V_7 [ V_11 -> V_4 ] . V_26 = V_27 ;
V_2 -> V_7 [ V_11 -> V_4 ] . V_24 = V_25 ;
F_9 ( & V_2 -> V_13 , V_12 ) ;
goto V_40;
}
return 0 ;
}
int F_41 ( struct V_1 * V_2 , int V_4 )
{
unsigned long V_12 ;
struct V_10 * V_11 ;
int V_39 ;
if ( V_2 -> V_35 ) {
return 0 ;
}
F_8 ( & V_2 -> V_13 , V_12 ) ;
if ( F_42 ( & V_2 -> V_7 [ V_4 ] . V_14 ) ) {
F_9 ( & V_2 -> V_13 , V_12 ) ;
return 0 ;
}
V_11 = F_17 ( V_2 -> V_7 [ V_4 ] . V_14 . V_43 ,
struct V_10 , V_17 ) ;
F_43 ( V_11 ) ;
F_9 ( & V_2 -> V_13 , V_12 ) ;
V_39 = F_30 ( V_11 , false ) ;
F_44 ( & V_11 ) ;
return V_39 ;
}
int F_45 ( struct V_1 * V_2 , int V_4 )
{
unsigned long V_12 ;
struct V_10 * V_11 ;
int V_39 ;
if ( V_2 -> V_35 ) {
return 0 ;
}
F_8 ( & V_2 -> V_13 , V_12 ) ;
if ( F_42 ( & V_2 -> V_7 [ V_4 ] . V_14 ) ) {
F_9 ( & V_2 -> V_13 , V_12 ) ;
return 0 ;
}
V_11 = F_17 ( V_2 -> V_7 [ V_4 ] . V_14 . V_28 ,
struct V_10 , V_17 ) ;
F_43 ( V_11 ) ;
F_9 ( & V_2 -> V_13 , V_12 ) ;
V_39 = F_30 ( V_11 , false ) ;
F_44 ( & V_11 ) ;
return V_39 ;
}
struct V_10 * F_43 ( struct V_10 * V_11 )
{
F_46 ( & V_11 -> V_30 ) ;
return V_11 ;
}
void F_44 ( struct V_10 * * V_11 )
{
struct V_10 * V_44 = * V_11 ;
* V_11 = NULL ;
if ( V_44 ) {
F_47 ( & V_44 -> V_30 , F_18 ) ;
}
}
void F_48 ( struct V_1 * V_2 , int V_4 )
{
unsigned long V_12 ;
bool V_21 ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
V_21 = F_14 ( V_2 , V_4 ) ;
F_9 ( & V_2 -> V_13 , V_12 ) ;
if ( V_21 ) {
F_49 ( & V_2 -> V_7 [ V_4 ] . V_41 ) ;
}
}
int F_50 ( struct V_1 * V_2 , int V_4 )
{
unsigned long V_12 ;
int V_45 = 0 ;
F_51 ( & V_2 -> V_13 , V_12 ) ;
if ( ! V_2 -> V_7 [ V_4 ] . V_46 ) {
F_52 ( & V_2 -> V_13 , V_12 ) ;
return 0 ;
}
if ( ! F_42 ( & V_2 -> V_7 [ V_4 ] . V_14 ) ) {
struct V_18 * V_47 ;
F_16 (ptr, &rdev->fence_drv[ring].emitted) {
if ( ++ V_45 >= 3 )
break;
}
}
F_52 ( & V_2 -> V_13 , V_12 ) ;
return V_45 ;
}
int F_53 ( struct V_1 * V_2 , int V_4 )
{
unsigned long V_12 ;
T_3 V_48 ;
int V_39 ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
F_54 ( V_2 , V_2 -> V_7 [ V_4 ] . V_9 ) ;
if ( V_2 -> V_5 . V_49 ) {
V_2 -> V_7 [ V_4 ] . V_9 = 0 ;
V_48 = V_50 + V_4 * 4 ;
} else {
V_39 = F_55 ( V_2 , & V_2 -> V_7 [ V_4 ] . V_9 ) ;
if ( V_39 ) {
F_56 ( V_2 -> V_51 , L_4 ) ;
F_9 ( & V_2 -> V_13 , V_12 ) ;
return V_39 ;
}
V_48 = V_52 +
V_2 -> V_7 [ V_4 ] . V_9 -
V_2 -> V_53 . V_54 ;
}
V_2 -> V_7 [ V_4 ] . V_8 = & V_2 -> V_5 . V_5 [ V_48 / 4 ] ;
V_2 -> V_7 [ V_4 ] . V_55 = V_2 -> V_5 . V_55 + V_48 ;
F_1 ( V_2 , F_57 ( & V_2 -> V_7 [ V_4 ] . V_3 ) , V_4 ) ;
V_2 -> V_7 [ V_4 ] . V_46 = true ;
F_58 ( L_5 ,
V_4 , V_2 -> V_7 [ V_4 ] . V_55 , V_2 -> V_7 [ V_4 ] . V_8 ) ;
F_9 ( & V_2 -> V_13 , V_12 ) ;
return 0 ;
}
static void F_59 ( struct V_1 * V_2 , int V_4 )
{
V_2 -> V_7 [ V_4 ] . V_9 = - 1 ;
V_2 -> V_7 [ V_4 ] . V_8 = NULL ;
V_2 -> V_7 [ V_4 ] . V_55 = 0 ;
F_60 ( & V_2 -> V_7 [ V_4 ] . V_3 , 0 ) ;
F_26 ( & V_2 -> V_7 [ V_4 ] . V_34 ) ;
F_26 ( & V_2 -> V_7 [ V_4 ] . V_14 ) ;
F_26 ( & V_2 -> V_7 [ V_4 ] . V_29 ) ;
F_61 ( & V_2 -> V_7 [ V_4 ] . V_41 ) ;
V_2 -> V_7 [ V_4 ] . V_46 = false ;
}
int F_62 ( struct V_1 * V_2 )
{
unsigned long V_12 ;
int V_4 ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
for ( V_4 = 0 ; V_4 < V_56 ; V_4 ++ ) {
F_59 ( V_2 , V_4 ) ;
}
F_9 ( & V_2 -> V_13 , V_12 ) ;
if ( F_63 ( V_2 ) ) {
F_56 ( V_2 -> V_51 , L_6 ) ;
}
return 0 ;
}
void F_64 ( struct V_1 * V_2 )
{
unsigned long V_12 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_56 ; V_4 ++ ) {
if ( ! V_2 -> V_7 [ V_4 ] . V_46 )
continue;
F_45 ( V_2 , V_4 ) ;
F_49 ( & V_2 -> V_7 [ V_4 ] . V_41 ) ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
F_54 ( V_2 , V_2 -> V_7 [ V_4 ] . V_9 ) ;
F_9 ( & V_2 -> V_13 , V_12 ) ;
V_2 -> V_7 [ V_4 ] . V_46 = false ;
}
}
static int F_65 ( struct V_57 * V_58 , void * V_59 )
{
struct V_60 * V_61 = (struct V_60 * ) V_58 -> V_62 ;
struct V_63 * V_51 = V_61 -> V_64 -> V_51 ;
struct V_1 * V_2 = V_51 -> V_65 ;
struct V_10 * V_11 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_56 ; ++ V_19 ) {
if ( ! V_2 -> V_7 [ V_19 ] . V_46 )
continue;
F_66 ( V_58 , L_7 , V_19 ) ;
F_66 ( V_58 , L_8 ,
F_4 ( V_2 , V_19 ) ) ;
if ( ! F_42 ( & V_2 -> V_7 [ V_19 ] . V_14 ) ) {
V_11 = F_17 ( V_2 -> V_7 [ V_19 ] . V_14 . V_28 ,
struct V_10 , V_17 ) ;
F_66 ( V_58 , L_9 ,
V_11 , V_11 -> V_3 ) ;
}
}
return 0 ;
}
int F_63 ( struct V_1 * V_2 )
{
#if F_67 ( V_66 )
return F_68 ( V_2 , V_67 , 1 ) ;
#else
return 0 ;
#endif
}
