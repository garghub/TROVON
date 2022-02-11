void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
F_2 (ib, n, &rdev->ib_pool.bogus_ib, list) {
F_3 ( & V_4 -> V_6 ) ;
F_4 ( V_4 -> V_7 ) ;
F_5 ( V_4 ) ;
}
}
void F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_3 * V_8 ;
V_8 = F_7 ( sizeof( * V_8 ) , V_9 ) ;
if ( V_8 == NULL )
return;
V_8 -> V_7 = F_8 ( V_4 -> V_10 * 4 ) ;
if ( V_8 -> V_7 == NULL ) {
F_5 ( V_8 ) ;
return;
}
memcpy ( V_8 -> V_7 , V_4 -> V_7 , V_4 -> V_10 * 4 ) ;
V_8 -> V_10 = V_4 -> V_10 ;
F_9 ( & V_2 -> V_11 . V_12 ) ;
F_10 ( & V_8 -> V_6 , & V_2 -> V_11 . V_13 ) ;
F_11 ( & V_2 -> V_11 . V_12 ) ;
}
int F_12 ( struct V_1 * V_2 , struct V_3 * * V_4 )
{
struct V_14 * V_15 ;
struct V_3 * V_16 ;
int V_17 = 0 , V_18 , V_19 ;
* V_4 = NULL ;
V_17 = F_13 ( V_2 , & V_15 ) ;
if ( V_17 ) {
F_14 ( V_2 -> V_20 , L_1 ) ;
return V_17 ;
}
F_9 ( & V_2 -> V_11 . V_12 ) ;
for ( V_18 = V_2 -> V_11 . V_21 , V_19 = 0 , V_16 = NULL ; V_19 < V_22 ; V_19 ++ , V_18 ++ ) {
V_18 &= ( V_22 - 1 ) ;
if ( V_2 -> V_11 . V_23 [ V_18 ] . free ) {
V_16 = & V_2 -> V_11 . V_23 [ V_18 ] ;
break;
}
}
if ( V_16 == NULL ) {
F_14 ( V_2 -> V_20 , L_2 ) ;
F_11 ( & V_2 -> V_11 . V_12 ) ;
F_15 ( & V_15 ) ;
return - V_24 ;
}
V_2 -> V_11 . V_21 = ( V_16 -> V_25 + 1 ) & ( V_22 - 1 ) ;
V_16 -> free = false ;
if ( V_16 -> V_15 ) {
F_11 ( & V_2 -> V_11 . V_12 ) ;
V_17 = F_16 ( V_16 -> V_15 , false ) ;
if ( V_17 ) {
F_14 ( V_2 -> V_20 , L_3 ,
V_16 -> V_25 , ( unsigned long ) V_16 -> V_26 , V_16 -> V_10 ) ;
F_9 ( & V_2 -> V_11 . V_12 ) ;
V_16 -> free = true ;
F_11 ( & V_2 -> V_11 . V_12 ) ;
F_15 ( & V_15 ) ;
return V_17 ;
}
F_9 ( & V_2 -> V_11 . V_12 ) ;
}
F_15 ( & V_16 -> V_15 ) ;
V_16 -> V_15 = V_15 ;
V_16 -> V_10 = 0 ;
F_11 ( & V_2 -> V_11 . V_12 ) ;
* V_4 = V_16 ;
return 0 ;
}
void F_17 ( struct V_1 * V_2 , struct V_3 * * V_4 )
{
struct V_3 * V_27 = * V_4 ;
* V_4 = NULL ;
if ( V_27 == NULL ) {
return;
}
if ( ! V_27 -> V_15 -> V_28 )
F_15 ( & V_27 -> V_15 ) ;
F_9 ( & V_2 -> V_11 . V_12 ) ;
V_27 -> free = true ;
F_11 ( & V_2 -> V_11 . V_12 ) ;
}
int F_18 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_17 = 0 ;
if ( ! V_4 -> V_10 || ! V_2 -> V_29 . V_30 ) {
F_19 ( L_4 , V_4 -> V_25 ) ;
return - V_31 ;
}
V_17 = F_20 ( V_2 , 64 ) ;
if ( V_17 ) {
F_19 ( L_5 , V_17 ) ;
return V_17 ;
}
F_21 ( V_2 , V_4 ) ;
F_22 ( V_2 , V_4 -> V_15 ) ;
F_9 ( & V_2 -> V_11 . V_12 ) ;
V_4 -> free = true ;
F_11 ( & V_2 -> V_11 . V_12 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 )
{
void * V_7 ;
T_1 V_26 ;
int V_18 ;
int V_17 = 0 ;
if ( V_2 -> V_11 . V_32 )
return 0 ;
F_25 ( & V_2 -> V_11 . V_13 ) ;
V_17 = F_26 ( V_2 , V_22 * 64 * 1024 ,
V_33 , true , V_34 ,
& V_2 -> V_11 . V_32 ) ;
if ( V_17 ) {
F_19 ( L_6 , V_17 ) ;
return V_17 ;
}
V_17 = F_27 ( V_2 -> V_11 . V_32 , false ) ;
if ( F_28 ( V_17 != 0 ) )
return V_17 ;
V_17 = F_29 ( V_2 -> V_11 . V_32 , V_34 , & V_26 ) ;
if ( V_17 ) {
F_30 ( V_2 -> V_11 . V_32 ) ;
F_19 ( L_7 , V_17 ) ;
return V_17 ;
}
V_17 = F_31 ( V_2 -> V_11 . V_32 , & V_7 ) ;
F_30 ( V_2 -> V_11 . V_32 ) ;
if ( V_17 ) {
F_19 ( L_8 , V_17 ) ;
return V_17 ;
}
for ( V_18 = 0 ; V_18 < V_22 ; V_18 ++ ) {
unsigned V_35 ;
V_35 = V_18 * 64 * 1024 ;
V_2 -> V_11 . V_23 [ V_18 ] . V_26 = V_26 + V_35 ;
V_2 -> V_11 . V_23 [ V_18 ] . V_7 = V_7 + V_35 ;
V_2 -> V_11 . V_23 [ V_18 ] . V_25 = V_18 ;
V_2 -> V_11 . V_23 [ V_18 ] . V_10 = 0 ;
V_2 -> V_11 . V_23 [ V_18 ] . free = true ;
}
V_2 -> V_11 . V_21 = 0 ;
V_2 -> V_11 . V_30 = true ;
F_32 ( L_9 ) ;
if ( F_33 ( V_2 ) ) {
F_19 ( L_10 ) ;
}
return V_17 ;
}
void F_34 ( struct V_1 * V_2 )
{
int V_17 ;
struct V_36 * V_32 ;
if ( ! V_2 -> V_11 . V_30 ) {
return;
}
F_9 ( & V_2 -> V_11 . V_12 ) ;
F_1 ( V_2 ) ;
V_32 = V_2 -> V_11 . V_32 ;
V_2 -> V_11 . V_32 = NULL ;
F_11 ( & V_2 -> V_11 . V_12 ) ;
if ( V_32 ) {
V_17 = F_27 ( V_32 , false ) ;
if ( F_35 ( V_17 == 0 ) ) {
F_36 ( V_32 ) ;
F_37 ( V_32 ) ;
F_30 ( V_32 ) ;
}
F_38 ( & V_32 ) ;
}
}
void F_39 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 . V_38 )
V_2 -> V_29 . V_39 = F_40 ( V_2 -> V_37 . V_37 [ V_40 / 4 ] ) ;
else {
if ( V_2 -> V_41 >= V_42 )
V_2 -> V_29 . V_39 = F_41 ( V_43 ) ;
else
V_2 -> V_29 . V_39 = F_41 ( V_44 ) ;
}
V_2 -> V_29 . V_45 = ( V_2 -> V_29 . V_39 + ( V_2 -> V_29 . V_46 / 4 ) ) ;
V_2 -> V_29 . V_45 -= V_2 -> V_29 . V_47 ;
V_2 -> V_29 . V_45 &= V_2 -> V_29 . V_48 ;
if ( ! V_2 -> V_29 . V_45 ) {
V_2 -> V_29 . V_45 = V_2 -> V_29 . V_46 / 4 ;
}
}
int F_42 ( struct V_1 * V_2 , unsigned V_49 )
{
int V_17 ;
V_49 = ( V_49 + V_2 -> V_29 . V_50 ) & ~ V_2 -> V_29 . V_50 ;
while ( V_49 > ( V_2 -> V_29 . V_45 - 1 ) ) {
F_39 ( V_2 ) ;
if ( V_49 < V_2 -> V_29 . V_45 ) {
break;
}
V_17 = F_43 ( V_2 ) ;
if ( V_17 )
return V_17 ;
}
V_2 -> V_29 . V_51 = V_49 ;
V_2 -> V_29 . V_52 = V_2 -> V_29 . V_47 ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 , unsigned V_49 )
{
int V_17 ;
F_9 ( & V_2 -> V_29 . V_12 ) ;
V_17 = F_42 ( V_2 , V_49 ) ;
if ( V_17 ) {
F_11 ( & V_2 -> V_29 . V_12 ) ;
return V_17 ;
}
return 0 ;
}
void F_44 ( struct V_1 * V_2 )
{
unsigned V_53 ;
unsigned V_18 ;
V_53 = ( V_2 -> V_29 . V_50 + 1 ) -
( V_2 -> V_29 . V_47 & V_2 -> V_29 . V_50 ) ;
for ( V_18 = 0 ; V_18 < V_53 ; V_18 ++ ) {
F_45 ( V_2 , 2 << 30 ) ;
}
F_46 () ;
F_47 ( V_2 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
F_44 ( V_2 ) ;
F_11 ( & V_2 -> V_29 . V_12 ) ;
}
void F_48 ( struct V_1 * V_2 )
{
V_2 -> V_29 . V_47 = V_2 -> V_29 . V_52 ;
F_11 ( & V_2 -> V_29 . V_12 ) ;
}
int F_49 ( struct V_1 * V_2 , unsigned V_46 )
{
int V_17 ;
V_2 -> V_29 . V_46 = V_46 ;
if ( V_2 -> V_29 . V_54 == NULL ) {
V_17 = F_26 ( V_2 , V_2 -> V_29 . V_46 , V_33 , true ,
V_34 ,
& V_2 -> V_29 . V_54 ) ;
if ( V_17 ) {
F_14 ( V_2 -> V_20 , L_11 , V_17 ) ;
return V_17 ;
}
V_17 = F_27 ( V_2 -> V_29 . V_54 , false ) ;
if ( F_28 ( V_17 != 0 ) )
return V_17 ;
V_17 = F_29 ( V_2 -> V_29 . V_54 , V_34 ,
& V_2 -> V_29 . V_26 ) ;
if ( V_17 ) {
F_30 ( V_2 -> V_29 . V_54 ) ;
F_14 ( V_2 -> V_20 , L_12 , V_17 ) ;
return V_17 ;
}
V_17 = F_31 ( V_2 -> V_29 . V_54 ,
( void * * ) & V_2 -> V_29 . V_55 ) ;
F_30 ( V_2 -> V_29 . V_54 ) ;
if ( V_17 ) {
F_14 ( V_2 -> V_20 , L_13 , V_17 ) ;
return V_17 ;
}
}
V_2 -> V_29 . V_48 = ( V_2 -> V_29 . V_46 / 4 ) - 1 ;
V_2 -> V_29 . V_45 = V_2 -> V_29 . V_46 / 4 ;
return 0 ;
}
void F_50 ( struct V_1 * V_2 )
{
int V_17 ;
struct V_36 * V_54 ;
F_9 ( & V_2 -> V_29 . V_12 ) ;
V_54 = V_2 -> V_29 . V_54 ;
V_2 -> V_29 . V_55 = NULL ;
V_2 -> V_29 . V_54 = NULL ;
F_11 ( & V_2 -> V_29 . V_12 ) ;
if ( V_54 ) {
V_17 = F_27 ( V_54 , false ) ;
if ( F_35 ( V_17 == 0 ) ) {
F_36 ( V_54 ) ;
F_37 ( V_54 ) ;
F_30 ( V_54 ) ;
}
F_38 ( & V_54 ) ;
}
}
static int F_51 ( struct V_56 * V_57 , void * V_58 )
{
struct V_59 * V_60 = (struct V_59 * ) V_57 -> V_61 ;
struct V_3 * V_4 = V_60 -> V_62 -> V_58 ;
unsigned V_18 ;
if ( V_4 == NULL ) {
return 0 ;
}
F_52 ( V_57 , L_14 , V_4 -> V_25 ) ;
F_52 ( V_57 , L_15 , V_4 -> V_15 ) ;
F_52 ( V_57 , L_16 , V_4 -> V_10 ) ;
for ( V_18 = 0 ; V_18 < V_4 -> V_10 ; V_18 ++ ) {
F_52 ( V_57 , L_17 , V_18 , V_4 -> V_7 [ V_18 ] ) ;
}
return 0 ;
}
static int F_53 ( struct V_56 * V_57 , void * V_58 )
{
struct V_59 * V_60 = (struct V_59 * ) V_57 -> V_61 ;
struct V_1 * V_2 = V_60 -> V_62 -> V_58 ;
struct V_3 * V_4 ;
unsigned V_18 ;
F_9 ( & V_2 -> V_11 . V_12 ) ;
if ( F_54 ( & V_2 -> V_11 . V_13 ) ) {
F_11 ( & V_2 -> V_11 . V_12 ) ;
F_52 ( V_57 , L_18 ) ;
return 0 ;
}
V_4 = F_55 ( & V_2 -> V_11 . V_13 , struct V_3 , V_6 ) ;
F_56 ( & V_4 -> V_6 ) ;
F_11 ( & V_2 -> V_11 . V_12 ) ;
F_52 ( V_57 , L_16 , V_4 -> V_10 ) ;
for ( V_18 = 0 ; V_18 < V_4 -> V_10 ; V_18 ++ ) {
F_52 ( V_57 , L_17 , V_18 , V_4 -> V_7 [ V_18 ] ) ;
}
F_4 ( V_4 -> V_7 ) ;
F_5 ( V_4 ) ;
return 0 ;
}
int F_33 ( struct V_1 * V_2 )
{
#if F_57 ( V_63 )
unsigned V_18 ;
int V_17 ;
V_64 [ 0 ] . V_58 = V_2 ;
V_17 = F_58 ( V_2 , V_64 , 1 ) ;
if ( V_17 )
return V_17 ;
for ( V_18 = 0 ; V_18 < V_22 ; V_18 ++ ) {
sprintf ( V_65 [ V_18 ] , L_19 , V_18 ) ;
V_66 [ V_18 ] . V_67 = V_65 [ V_18 ] ;
V_66 [ V_18 ] . V_68 = & F_51 ;
V_66 [ V_18 ] . V_69 = 0 ;
V_66 [ V_18 ] . V_58 = & V_2 -> V_11 . V_23 [ V_18 ] ;
}
return F_58 ( V_2 , V_66 ,
V_22 ) ;
#else
return 0 ;
#endif
}
