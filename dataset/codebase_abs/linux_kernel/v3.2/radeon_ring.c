T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 [ V_2 -> V_7 ] ;
T_1 V_8 , V_9 ;
T_1 V_10 = 0 ;
int V_11 ;
V_8 = ( V_3 * 4 ) / V_12 ;
V_9 = ( V_3 * 4 ) % V_12 ;
if ( V_5 -> V_13 [ 0 ] == V_8 )
return V_5 -> V_14 [ 0 ] [ V_9 / 4 ] ;
if ( V_5 -> V_13 [ 1 ] == V_8 )
return V_5 -> V_14 [ 1 ] [ V_9 / 4 ] ;
V_11 = F_2 ( V_2 , V_8 ) ;
if ( V_11 < 0 ) {
V_2 -> V_15 = V_11 ;
return 0 ;
}
V_10 = V_5 -> V_14 [ V_11 ] [ V_9 / 4 ] ;
return V_10 ;
}
void F_3 ( struct V_16 * V_17 , T_2 V_18 )
{
#if V_19
if ( V_17 -> V_20 . V_21 <= 0 ) {
F_4 ( L_1 ) ;
}
#endif
V_17 -> V_20 . V_22 [ V_17 -> V_20 . V_23 ++ ] = V_18 ;
V_17 -> V_20 . V_23 &= V_17 -> V_20 . V_24 ;
V_17 -> V_20 . V_21 -- ;
V_17 -> V_20 . V_25 -- ;
}
void F_5 ( struct V_16 * V_17 )
{
struct V_26 * V_27 , * V_28 ;
F_6 (ib, n, &rdev->ib_pool.bogus_ib, list) {
F_7 ( & V_27 -> V_29 ) ;
F_8 ( V_27 -> V_30 ) ;
F_9 ( V_27 ) ;
}
}
void F_10 ( struct V_16 * V_17 , struct V_26 * V_27 )
{
struct V_26 * V_31 ;
V_31 = F_11 ( sizeof( * V_31 ) , V_32 ) ;
if ( V_31 == NULL )
return;
V_31 -> V_30 = F_12 ( V_27 -> V_33 * 4 ) ;
if ( V_31 -> V_30 == NULL ) {
F_9 ( V_31 ) ;
return;
}
memcpy ( V_31 -> V_30 , V_27 -> V_30 , V_27 -> V_33 * 4 ) ;
V_31 -> V_33 = V_27 -> V_33 ;
F_13 ( & V_17 -> V_34 . V_35 ) ;
F_14 ( & V_31 -> V_29 , & V_17 -> V_34 . V_36 ) ;
F_15 ( & V_17 -> V_34 . V_35 ) ;
}
int F_16 ( struct V_16 * V_17 , struct V_26 * * V_27 )
{
struct V_37 * V_38 ;
struct V_26 * V_39 ;
int V_40 = 0 , V_41 , V_42 ;
* V_27 = NULL ;
V_40 = F_17 ( V_17 , & V_38 ) ;
if ( V_40 ) {
F_18 ( V_17 -> V_43 , L_2 ) ;
return V_40 ;
}
F_13 ( & V_17 -> V_34 . V_35 ) ;
for ( V_41 = V_17 -> V_34 . V_44 , V_42 = 0 , V_39 = NULL ; V_42 < V_45 ; V_42 ++ , V_41 ++ ) {
V_41 &= ( V_45 - 1 ) ;
if ( V_17 -> V_34 . V_46 [ V_41 ] . free ) {
V_39 = & V_17 -> V_34 . V_46 [ V_41 ] ;
break;
}
}
if ( V_39 == NULL ) {
F_18 ( V_17 -> V_43 , L_3 ) ;
F_15 ( & V_17 -> V_34 . V_35 ) ;
F_19 ( & V_38 ) ;
return - V_47 ;
}
V_17 -> V_34 . V_44 = ( V_39 -> V_3 + 1 ) & ( V_45 - 1 ) ;
V_39 -> free = false ;
if ( V_39 -> V_38 ) {
F_15 ( & V_17 -> V_34 . V_35 ) ;
V_40 = F_20 ( V_39 -> V_38 , false ) ;
if ( V_40 ) {
F_18 ( V_17 -> V_43 , L_4 ,
V_39 -> V_3 , ( unsigned long ) V_39 -> V_48 , V_39 -> V_33 ) ;
F_13 ( & V_17 -> V_34 . V_35 ) ;
V_39 -> free = true ;
F_15 ( & V_17 -> V_34 . V_35 ) ;
F_19 ( & V_38 ) ;
return V_40 ;
}
F_13 ( & V_17 -> V_34 . V_35 ) ;
}
F_19 ( & V_39 -> V_38 ) ;
V_39 -> V_38 = V_38 ;
V_39 -> V_33 = 0 ;
F_15 ( & V_17 -> V_34 . V_35 ) ;
* V_27 = V_39 ;
return 0 ;
}
void F_21 ( struct V_16 * V_17 , struct V_26 * * V_27 )
{
struct V_26 * V_49 = * V_27 ;
* V_27 = NULL ;
if ( V_49 == NULL ) {
return;
}
if ( ! V_49 -> V_38 -> V_50 )
F_19 ( & V_49 -> V_38 ) ;
F_13 ( & V_17 -> V_34 . V_35 ) ;
V_49 -> free = true ;
F_15 ( & V_17 -> V_34 . V_35 ) ;
}
int F_22 ( struct V_16 * V_17 , struct V_26 * V_27 )
{
int V_40 = 0 ;
if ( ! V_27 -> V_33 || ! V_17 -> V_20 . V_51 ) {
F_4 ( L_5 , V_27 -> V_3 ) ;
return - V_52 ;
}
V_40 = F_23 ( V_17 , 64 ) ;
if ( V_40 ) {
F_4 ( L_6 , V_40 ) ;
return V_40 ;
}
F_24 ( V_17 , V_27 ) ;
F_25 ( V_17 , V_27 -> V_38 ) ;
F_13 ( & V_17 -> V_34 . V_35 ) ;
V_27 -> free = true ;
F_15 ( & V_17 -> V_34 . V_35 ) ;
F_26 ( V_17 ) ;
return 0 ;
}
int F_27 ( struct V_16 * V_17 )
{
void * V_30 ;
T_3 V_48 ;
int V_41 ;
int V_40 = 0 ;
if ( V_17 -> V_34 . V_53 )
return 0 ;
F_28 ( & V_17 -> V_34 . V_36 ) ;
V_40 = F_29 ( V_17 , V_45 * 64 * 1024 ,
V_12 , true , V_54 ,
& V_17 -> V_34 . V_53 ) ;
if ( V_40 ) {
F_4 ( L_7 , V_40 ) ;
return V_40 ;
}
V_40 = F_30 ( V_17 -> V_34 . V_53 , false ) ;
if ( F_31 ( V_40 != 0 ) )
return V_40 ;
V_40 = F_32 ( V_17 -> V_34 . V_53 , V_54 , & V_48 ) ;
if ( V_40 ) {
F_33 ( V_17 -> V_34 . V_53 ) ;
F_4 ( L_8 , V_40 ) ;
return V_40 ;
}
V_40 = F_34 ( V_17 -> V_34 . V_53 , & V_30 ) ;
F_33 ( V_17 -> V_34 . V_53 ) ;
if ( V_40 ) {
F_4 ( L_9 , V_40 ) ;
return V_40 ;
}
for ( V_41 = 0 ; V_41 < V_45 ; V_41 ++ ) {
unsigned V_55 ;
V_55 = V_41 * 64 * 1024 ;
V_17 -> V_34 . V_46 [ V_41 ] . V_48 = V_48 + V_55 ;
V_17 -> V_34 . V_46 [ V_41 ] . V_30 = V_30 + V_55 ;
V_17 -> V_34 . V_46 [ V_41 ] . V_3 = V_41 ;
V_17 -> V_34 . V_46 [ V_41 ] . V_33 = 0 ;
V_17 -> V_34 . V_46 [ V_41 ] . free = true ;
}
V_17 -> V_34 . V_44 = 0 ;
V_17 -> V_34 . V_51 = true ;
F_35 ( L_10 ) ;
if ( F_36 ( V_17 ) ) {
F_4 ( L_11 ) ;
}
return V_40 ;
}
void F_37 ( struct V_16 * V_17 )
{
int V_40 ;
struct V_56 * V_53 ;
if ( ! V_17 -> V_34 . V_51 ) {
return;
}
F_13 ( & V_17 -> V_34 . V_35 ) ;
F_5 ( V_17 ) ;
V_53 = V_17 -> V_34 . V_53 ;
V_17 -> V_34 . V_53 = NULL ;
F_15 ( & V_17 -> V_34 . V_35 ) ;
if ( V_53 ) {
V_40 = F_30 ( V_53 , false ) ;
if ( F_38 ( V_40 == 0 ) ) {
F_39 ( V_53 ) ;
F_40 ( V_53 ) ;
F_33 ( V_53 ) ;
}
F_41 ( & V_53 ) ;
}
}
void F_42 ( struct V_16 * V_17 )
{
if ( V_17 -> V_57 . V_58 )
V_17 -> V_20 . V_59 = F_43 ( V_17 -> V_57 . V_57 [ V_60 / 4 ] ) ;
else {
if ( V_17 -> V_61 >= V_62 )
V_17 -> V_20 . V_59 = F_44 ( V_63 ) ;
else
V_17 -> V_20 . V_59 = F_44 ( V_64 ) ;
}
V_17 -> V_20 . V_25 = ( V_17 -> V_20 . V_59 + ( V_17 -> V_20 . V_65 / 4 ) ) ;
V_17 -> V_20 . V_25 -= V_17 -> V_20 . V_23 ;
V_17 -> V_20 . V_25 &= V_17 -> V_20 . V_24 ;
if ( ! V_17 -> V_20 . V_25 ) {
V_17 -> V_20 . V_25 = V_17 -> V_20 . V_65 / 4 ;
}
}
int F_45 ( struct V_16 * V_17 , unsigned V_66 )
{
int V_40 ;
V_66 = ( V_66 + V_17 -> V_20 . V_67 ) & ~ V_17 -> V_20 . V_67 ;
while ( V_66 > ( V_17 -> V_20 . V_25 - 1 ) ) {
F_42 ( V_17 ) ;
if ( V_66 < V_17 -> V_20 . V_25 ) {
break;
}
V_40 = F_46 ( V_17 ) ;
if ( V_40 )
return V_40 ;
}
V_17 -> V_20 . V_21 = V_66 ;
V_17 -> V_20 . V_68 = V_17 -> V_20 . V_23 ;
return 0 ;
}
int F_23 ( struct V_16 * V_17 , unsigned V_66 )
{
int V_40 ;
F_13 ( & V_17 -> V_20 . V_35 ) ;
V_40 = F_45 ( V_17 , V_66 ) ;
if ( V_40 ) {
F_15 ( & V_17 -> V_20 . V_35 ) ;
return V_40 ;
}
return 0 ;
}
void F_47 ( struct V_16 * V_17 )
{
unsigned V_69 ;
unsigned V_41 ;
V_69 = ( V_17 -> V_20 . V_67 + 1 ) -
( V_17 -> V_20 . V_23 & V_17 -> V_20 . V_67 ) ;
for ( V_41 = 0 ; V_41 < V_69 ; V_41 ++ ) {
F_3 ( V_17 , 2 << 30 ) ;
}
F_48 () ;
F_49 ( V_17 ) ;
}
void F_26 ( struct V_16 * V_17 )
{
F_47 ( V_17 ) ;
F_15 ( & V_17 -> V_20 . V_35 ) ;
}
void F_50 ( struct V_16 * V_17 )
{
V_17 -> V_20 . V_23 = V_17 -> V_20 . V_68 ;
F_15 ( & V_17 -> V_20 . V_35 ) ;
}
int F_51 ( struct V_16 * V_17 , unsigned V_65 )
{
int V_40 ;
V_17 -> V_20 . V_65 = V_65 ;
if ( V_17 -> V_20 . V_70 == NULL ) {
V_40 = F_29 ( V_17 , V_17 -> V_20 . V_65 , V_12 , true ,
V_54 ,
& V_17 -> V_20 . V_70 ) ;
if ( V_40 ) {
F_18 ( V_17 -> V_43 , L_12 , V_40 ) ;
return V_40 ;
}
V_40 = F_30 ( V_17 -> V_20 . V_70 , false ) ;
if ( F_31 ( V_40 != 0 ) )
return V_40 ;
V_40 = F_32 ( V_17 -> V_20 . V_70 , V_54 ,
& V_17 -> V_20 . V_48 ) ;
if ( V_40 ) {
F_33 ( V_17 -> V_20 . V_70 ) ;
F_18 ( V_17 -> V_43 , L_13 , V_40 ) ;
return V_40 ;
}
V_40 = F_34 ( V_17 -> V_20 . V_70 ,
( void * * ) & V_17 -> V_20 . V_22 ) ;
F_33 ( V_17 -> V_20 . V_70 ) ;
if ( V_40 ) {
F_18 ( V_17 -> V_43 , L_14 , V_40 ) ;
return V_40 ;
}
}
V_17 -> V_20 . V_24 = ( V_17 -> V_20 . V_65 / 4 ) - 1 ;
V_17 -> V_20 . V_25 = V_17 -> V_20 . V_65 / 4 ;
return 0 ;
}
void F_52 ( struct V_16 * V_17 )
{
int V_40 ;
struct V_56 * V_70 ;
F_13 ( & V_17 -> V_20 . V_35 ) ;
V_70 = V_17 -> V_20 . V_70 ;
V_17 -> V_20 . V_22 = NULL ;
V_17 -> V_20 . V_70 = NULL ;
F_15 ( & V_17 -> V_20 . V_35 ) ;
if ( V_70 ) {
V_40 = F_30 ( V_70 , false ) ;
if ( F_38 ( V_40 == 0 ) ) {
F_39 ( V_70 ) ;
F_40 ( V_70 ) ;
F_33 ( V_70 ) ;
}
F_41 ( & V_70 ) ;
}
}
static int F_53 ( struct V_71 * V_72 , void * V_73 )
{
struct V_74 * V_75 = (struct V_74 * ) V_72 -> V_76 ;
struct V_26 * V_27 = V_75 -> V_77 -> V_73 ;
unsigned V_41 ;
if ( V_27 == NULL ) {
return 0 ;
}
F_54 ( V_72 , L_15 , V_27 -> V_3 ) ;
F_54 ( V_72 , L_16 , V_27 -> V_38 ) ;
F_54 ( V_72 , L_17 , V_27 -> V_33 ) ;
for ( V_41 = 0 ; V_41 < V_27 -> V_33 ; V_41 ++ ) {
F_54 ( V_72 , L_18 , V_41 , V_27 -> V_30 [ V_41 ] ) ;
}
return 0 ;
}
static int F_55 ( struct V_71 * V_72 , void * V_73 )
{
struct V_74 * V_75 = (struct V_74 * ) V_72 -> V_76 ;
struct V_16 * V_17 = V_75 -> V_77 -> V_73 ;
struct V_26 * V_27 ;
unsigned V_41 ;
F_13 ( & V_17 -> V_34 . V_35 ) ;
if ( F_56 ( & V_17 -> V_34 . V_36 ) ) {
F_15 ( & V_17 -> V_34 . V_35 ) ;
F_54 ( V_72 , L_19 ) ;
return 0 ;
}
V_27 = F_57 ( & V_17 -> V_34 . V_36 , struct V_26 , V_29 ) ;
F_58 ( & V_27 -> V_29 ) ;
F_15 ( & V_17 -> V_34 . V_35 ) ;
F_54 ( V_72 , L_17 , V_27 -> V_33 ) ;
for ( V_41 = 0 ; V_41 < V_27 -> V_33 ; V_41 ++ ) {
F_54 ( V_72 , L_18 , V_41 , V_27 -> V_30 [ V_41 ] ) ;
}
F_8 ( V_27 -> V_30 ) ;
F_9 ( V_27 ) ;
return 0 ;
}
int F_36 ( struct V_16 * V_17 )
{
#if F_59 ( V_78 )
unsigned V_41 ;
int V_40 ;
V_79 [ 0 ] . V_73 = V_17 ;
V_40 = F_60 ( V_17 , V_79 , 1 ) ;
if ( V_40 )
return V_40 ;
for ( V_41 = 0 ; V_41 < V_45 ; V_41 ++ ) {
sprintf ( V_80 [ V_41 ] , L_20 , V_41 ) ;
V_81 [ V_41 ] . V_82 = V_80 [ V_41 ] ;
V_81 [ V_41 ] . V_83 = & F_53 ;
V_81 [ V_41 ] . V_84 = 0 ;
V_81 [ V_41 ] . V_73 = & V_17 -> V_34 . V_46 [ V_41 ] ;
}
return F_60 ( V_17 , V_81 ,
V_45 ) ;
#else
return 0 ;
#endif
}
