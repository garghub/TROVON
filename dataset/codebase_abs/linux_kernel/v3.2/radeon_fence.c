static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_4 . V_5 ) {
T_1 V_6 ;
if ( V_2 -> V_4 . V_7 )
V_6 = V_8 + V_2 -> V_9 . V_10 - V_2 -> V_11 . V_12 ;
else
V_6 = V_13 + V_2 -> V_9 . V_10 - V_2 -> V_11 . V_12 ;
V_2 -> V_4 . V_4 [ V_6 / 4 ] = F_2 ( V_3 ) ;
} else
F_3 ( V_2 -> V_9 . V_10 , V_3 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( V_2 -> V_4 . V_5 ) {
T_1 V_6 ;
if ( V_2 -> V_4 . V_7 )
V_6 = V_8 + V_2 -> V_9 . V_10 - V_2 -> V_11 . V_12 ;
else
V_6 = V_13 + V_2 -> V_9 . V_10 - V_2 -> V_11 . V_12 ;
V_3 = F_5 ( V_2 -> V_4 . V_4 [ V_6 / 4 ] ) ;
} else
V_3 = F_6 ( V_2 -> V_9 . V_10 ) ;
return V_3 ;
}
int F_7 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
unsigned long V_16 ;
F_8 ( & V_2 -> V_9 . V_17 , V_16 ) ;
if ( V_15 -> V_18 ) {
F_9 ( & V_2 -> V_9 . V_17 , V_16 ) ;
return 0 ;
}
V_15 -> V_3 = F_10 ( 1 , & V_2 -> V_9 . V_3 ) ;
if ( ! V_2 -> V_19 . V_20 )
F_1 ( V_2 , V_15 -> V_3 ) ;
else
F_11 ( V_2 , V_15 ) ;
F_12 ( V_2 -> V_21 , V_15 -> V_3 ) ;
V_15 -> V_18 = true ;
F_13 ( & V_15 -> V_22 , & V_2 -> V_9 . V_18 ) ;
F_9 ( & V_2 -> V_9 . V_17 , V_16 ) ;
return 0 ;
}
static bool F_14 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
struct V_23 * V_24 , * V_25 ;
T_2 V_3 ;
bool V_26 = false ;
unsigned long V_27 ;
V_3 = F_4 ( V_2 ) ;
if ( V_3 != V_2 -> V_9 . V_28 ) {
V_2 -> V_9 . V_28 = V_3 ;
V_2 -> V_9 . V_29 = V_30 ;
V_2 -> V_9 . V_31 = V_32 ;
} else {
V_27 = V_30 ;
if ( F_15 ( V_27 , V_2 -> V_9 . V_29 ) ) {
V_27 -= V_2 -> V_9 . V_29 ;
if ( F_15 ( V_2 -> V_9 . V_31 , V_27 ) ) {
V_2 -> V_9 . V_31 -= V_27 ;
} else {
V_2 -> V_9 . V_31 = 1 ;
}
} else {
V_2 -> V_9 . V_29 = V_27 ;
}
return false ;
}
V_25 = NULL ;
F_16 (i, &rdev->fence_drv.emited) {
V_15 = F_17 ( V_24 , struct V_14 , V_22 ) ;
if ( V_15 -> V_3 == V_3 ) {
V_25 = V_24 ;
break;
}
}
if ( V_25 ) {
V_24 = V_25 ;
do {
V_25 = V_24 -> V_33 ;
F_13 ( V_24 , & V_2 -> V_9 . V_34 ) ;
V_15 = F_17 ( V_24 , struct V_14 , V_22 ) ;
V_15 -> V_34 = true ;
V_24 = V_25 ;
} while ( V_24 != & V_2 -> V_9 . V_18 );
V_26 = true ;
}
return V_26 ;
}
static void F_18 ( struct V_35 * V_35 )
{
unsigned long V_16 ;
struct V_14 * V_15 ;
V_15 = F_19 ( V_35 , struct V_14 , V_35 ) ;
F_8 ( & V_15 -> V_2 -> V_9 . V_17 , V_16 ) ;
F_20 ( & V_15 -> V_22 ) ;
V_15 -> V_18 = false ;
F_9 ( & V_15 -> V_2 -> V_9 . V_17 , V_16 ) ;
F_21 ( V_15 ) ;
}
int F_22 ( struct V_1 * V_2 , struct V_14 * * V_15 )
{
unsigned long V_16 ;
* V_15 = F_23 ( sizeof( struct V_14 ) , V_36 ) ;
if ( ( * V_15 ) == NULL ) {
return - V_37 ;
}
F_24 ( & ( ( * V_15 ) -> V_35 ) ) ;
( * V_15 ) -> V_2 = V_2 ;
( * V_15 ) -> V_18 = false ;
( * V_15 ) -> V_34 = false ;
( * V_15 ) -> V_3 = 0 ;
F_25 ( & ( * V_15 ) -> V_22 ) ;
F_8 ( & V_2 -> V_9 . V_17 , V_16 ) ;
F_26 ( & ( * V_15 ) -> V_22 , & V_2 -> V_9 . V_38 ) ;
F_9 ( & V_2 -> V_9 . V_17 , V_16 ) ;
return 0 ;
}
bool F_27 ( struct V_14 * V_15 )
{
unsigned long V_16 ;
bool V_34 = false ;
if ( ! V_15 )
return true ;
if ( V_15 -> V_2 -> V_39 )
return true ;
F_8 ( & V_15 -> V_2 -> V_9 . V_17 , V_16 ) ;
V_34 = V_15 -> V_34 ;
if ( V_15 -> V_2 -> V_40 ) {
V_34 = true ;
}
if ( ! V_15 -> V_18 ) {
F_28 ( 1 , L_1 , V_15 ) ;
V_34 = true ;
}
if ( ! V_34 ) {
F_14 ( V_15 -> V_2 ) ;
V_34 = V_15 -> V_34 ;
}
F_9 ( & V_15 -> V_2 -> V_9 . V_17 , V_16 ) ;
return V_34 ;
}
int F_29 ( struct V_14 * V_15 , bool V_41 )
{
struct V_1 * V_2 ;
unsigned long V_16 , V_42 ;
T_1 V_3 ;
int V_43 ;
if ( V_15 == NULL ) {
F_28 ( 1 , L_2 , V_15 ) ;
return 0 ;
}
V_2 = V_15 -> V_2 ;
if ( F_27 ( V_15 ) ) {
return 0 ;
}
V_42 = V_2 -> V_9 . V_31 ;
V_44:
V_3 = V_2 -> V_9 . V_28 ;
F_30 ( V_2 -> V_21 , V_3 ) ;
if ( V_41 ) {
F_31 ( V_2 ) ;
V_43 = F_32 ( V_2 -> V_9 . V_45 ,
F_27 ( V_15 ) , V_42 ) ;
F_33 ( V_2 ) ;
if ( F_34 ( V_43 < 0 ) ) {
return V_43 ;
}
} else {
F_31 ( V_2 ) ;
V_43 = F_35 ( V_2 -> V_9 . V_45 ,
F_27 ( V_15 ) , V_42 ) ;
F_33 ( V_2 ) ;
}
F_36 ( V_2 -> V_21 , V_3 ) ;
if ( F_34 ( ! F_27 ( V_15 ) ) ) {
if ( V_43 ) {
V_42 = V_43 ;
goto V_44;
}
if ( V_3 == V_2 -> V_9 . V_28 && F_37 ( V_2 ) ) {
F_38 ( V_46 L_3 ,
V_15 -> V_3 , V_3 ) ;
V_2 -> V_39 = true ;
V_43 = F_39 ( V_2 ) ;
if ( V_43 )
return V_43 ;
F_1 ( V_2 , V_15 -> V_3 ) ;
V_2 -> V_39 = false ;
}
V_42 = V_32 ;
F_8 ( & V_2 -> V_9 . V_17 , V_16 ) ;
V_2 -> V_9 . V_31 = V_32 ;
V_2 -> V_9 . V_29 = V_30 ;
F_9 ( & V_2 -> V_9 . V_17 , V_16 ) ;
goto V_44;
}
return 0 ;
}
int F_40 ( struct V_1 * V_2 )
{
unsigned long V_16 ;
struct V_14 * V_15 ;
int V_43 ;
if ( V_2 -> V_39 ) {
return 0 ;
}
F_8 ( & V_2 -> V_9 . V_17 , V_16 ) ;
if ( F_41 ( & V_2 -> V_9 . V_18 ) ) {
F_9 ( & V_2 -> V_9 . V_17 , V_16 ) ;
return 0 ;
}
V_15 = F_17 ( V_2 -> V_9 . V_18 . V_47 ,
struct V_14 , V_22 ) ;
F_42 ( V_15 ) ;
F_9 ( & V_2 -> V_9 . V_17 , V_16 ) ;
V_43 = F_29 ( V_15 , false ) ;
F_43 ( & V_15 ) ;
return V_43 ;
}
int F_44 ( struct V_1 * V_2 )
{
unsigned long V_16 ;
struct V_14 * V_15 ;
int V_43 ;
if ( V_2 -> V_39 ) {
return 0 ;
}
F_8 ( & V_2 -> V_9 . V_17 , V_16 ) ;
if ( F_41 ( & V_2 -> V_9 . V_18 ) ) {
F_9 ( & V_2 -> V_9 . V_17 , V_16 ) ;
return 0 ;
}
V_15 = F_17 ( V_2 -> V_9 . V_18 . V_33 ,
struct V_14 , V_22 ) ;
F_42 ( V_15 ) ;
F_9 ( & V_2 -> V_9 . V_17 , V_16 ) ;
V_43 = F_29 ( V_15 , false ) ;
F_43 ( & V_15 ) ;
return V_43 ;
}
struct V_14 * F_42 ( struct V_14 * V_15 )
{
F_45 ( & V_15 -> V_35 ) ;
return V_15 ;
}
void F_43 ( struct V_14 * * V_15 )
{
struct V_14 * V_48 = * V_15 ;
* V_15 = NULL ;
if ( V_48 ) {
F_46 ( & V_48 -> V_35 , F_18 ) ;
}
}
void F_47 ( struct V_1 * V_2 )
{
unsigned long V_16 ;
bool V_26 ;
F_8 ( & V_2 -> V_9 . V_17 , V_16 ) ;
V_26 = F_14 ( V_2 ) ;
F_9 ( & V_2 -> V_9 . V_17 , V_16 ) ;
if ( V_26 ) {
F_48 ( & V_2 -> V_9 . V_45 ) ;
}
}
int F_49 ( struct V_1 * V_2 )
{
unsigned long V_16 ;
int V_43 ;
F_8 ( & V_2 -> V_9 . V_17 , V_16 ) ;
V_43 = F_50 ( V_2 , & V_2 -> V_9 . V_10 ) ;
if ( V_43 ) {
F_51 ( V_2 -> V_49 , L_4 ) ;
F_9 ( & V_2 -> V_9 . V_17 , V_16 ) ;
return V_43 ;
}
F_1 ( V_2 , 0 ) ;
F_52 ( & V_2 -> V_9 . V_3 , 0 ) ;
F_25 ( & V_2 -> V_9 . V_38 ) ;
F_25 ( & V_2 -> V_9 . V_18 ) ;
F_25 ( & V_2 -> V_9 . V_34 ) ;
F_53 ( & V_2 -> V_9 . V_45 ) ;
V_2 -> V_9 . V_50 = true ;
F_9 ( & V_2 -> V_9 . V_17 , V_16 ) ;
if ( F_54 ( V_2 ) ) {
F_51 ( V_2 -> V_49 , L_5 ) ;
}
return 0 ;
}
void F_55 ( struct V_1 * V_2 )
{
unsigned long V_16 ;
if ( ! V_2 -> V_9 . V_50 )
return;
F_48 ( & V_2 -> V_9 . V_45 ) ;
F_8 ( & V_2 -> V_9 . V_17 , V_16 ) ;
F_56 ( V_2 , V_2 -> V_9 . V_10 ) ;
F_9 ( & V_2 -> V_9 . V_17 , V_16 ) ;
V_2 -> V_9 . V_50 = false ;
}
static int F_57 ( struct V_51 * V_52 , void * V_53 )
{
struct V_54 * V_55 = (struct V_54 * ) V_52 -> V_56 ;
struct V_57 * V_49 = V_55 -> V_58 -> V_49 ;
struct V_1 * V_2 = V_49 -> V_59 ;
struct V_14 * V_15 ;
F_58 ( V_52 , L_6 ,
F_4 ( V_2 ) ) ;
if ( ! F_41 ( & V_2 -> V_9 . V_18 ) ) {
V_15 = F_17 ( V_2 -> V_9 . V_18 . V_33 ,
struct V_14 , V_22 ) ;
F_58 ( V_52 , L_7 ,
V_15 , V_15 -> V_3 ) ;
}
return 0 ;
}
int F_54 ( struct V_1 * V_2 )
{
#if F_59 ( V_60 )
return F_60 ( V_2 , V_61 , 1 ) ;
#else
return 0 ;
#endif
}
