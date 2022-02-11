unsigned long F_1 ( void )
{
int V_1 ;
unsigned long V_2 = 0 ;
for ( V_1 = 0 ; V_1 < V_3 ; V_1 ++ )
V_2 += V_4 [ V_1 ] . V_5 ;
return V_2 ;
}
void F_2 ( void )
{
F_3 ( L_1 , F_1 () ) ;
F_3 ( L_2 ,
V_6 . V_7 , V_6 . V_8 ,
V_6 . V_9 , V_6 . V_10 ) ;
F_3 ( L_3 ,
F_4 () << ( V_11 - 10 ) ) ;
F_3 ( L_4 , V_12 << ( V_11 - 10 ) ) ;
}
static int F_5 ( struct V_13 * V_13 , T_1 V_14 )
{
int error ;
struct V_15 * V_15 ;
F_6 ( ! F_7 ( V_13 ) ) ;
F_6 ( F_8 ( V_13 ) ) ;
F_6 ( ! F_9 ( V_13 ) ) ;
F_10 ( V_13 ) ;
F_11 ( V_13 ) ;
F_12 ( V_13 , V_14 . V_16 ) ;
V_15 = F_13 ( V_14 ) ;
F_14 ( & V_15 -> V_17 ) ;
error = F_15 ( & V_15 -> V_18 ,
V_14 . V_16 , V_13 ) ;
if ( F_16 ( ! error ) ) {
V_15 -> V_5 ++ ;
F_17 ( V_13 , V_19 ) ;
F_18 ( V_7 ) ;
}
F_19 ( & V_15 -> V_17 ) ;
if ( F_20 ( error ) ) {
F_6 ( error == - V_20 ) ;
F_12 ( V_13 , 0UL ) ;
F_21 ( V_13 ) ;
F_22 ( V_13 ) ;
}
return error ;
}
int F_23 ( struct V_13 * V_13 , T_1 V_14 , T_2 V_21 )
{
int error ;
error = F_24 ( V_21 ) ;
if ( ! error ) {
error = F_5 ( V_13 , V_14 ) ;
F_25 () ;
}
return error ;
}
void F_26 ( struct V_13 * V_13 )
{
T_1 V_14 ;
struct V_15 * V_15 ;
F_6 ( ! F_7 ( V_13 ) ) ;
F_6 ( ! F_8 ( V_13 ) ) ;
F_6 ( F_27 ( V_13 ) ) ;
V_14 . V_16 = F_28 ( V_13 ) ;
V_15 = F_13 ( V_14 ) ;
F_29 ( & V_15 -> V_18 , F_28 ( V_13 ) ) ;
F_12 ( V_13 , 0 ) ;
F_21 ( V_13 ) ;
V_15 -> V_5 -- ;
F_30 ( V_13 , V_19 ) ;
F_18 ( V_8 ) ;
}
int F_31 ( struct V_13 * V_13 )
{
T_1 V_14 ;
int V_22 ;
F_6 ( ! F_7 ( V_13 ) ) ;
F_6 ( ! F_32 ( V_13 ) ) ;
V_14 = F_33 () ;
if ( ! V_14 . V_16 )
return 0 ;
if ( F_20 ( F_34 ( V_13 ) ) )
if ( F_20 ( F_35 ( V_13 ) ) ) {
F_36 ( V_14 , NULL ) ;
return 0 ;
}
V_22 = F_23 ( V_13 , V_14 ,
V_23 | V_24 | V_25 ) ;
if ( ! V_22 ) {
F_37 ( V_13 ) ;
return 1 ;
} else {
F_36 ( V_14 , NULL ) ;
return 0 ;
}
}
void F_38 ( struct V_13 * V_13 )
{
T_1 V_14 ;
struct V_15 * V_15 ;
V_14 . V_16 = F_28 ( V_13 ) ;
V_15 = F_13 ( V_14 ) ;
F_14 ( & V_15 -> V_17 ) ;
F_26 ( V_13 ) ;
F_19 ( & V_15 -> V_17 ) ;
F_36 ( V_14 , V_13 ) ;
F_22 ( V_13 ) ;
}
static inline void F_39 ( struct V_13 * V_13 )
{
if ( F_8 ( V_13 ) && ! F_40 ( V_13 ) && F_41 ( V_13 ) ) {
F_42 ( V_13 ) ;
F_43 ( V_13 ) ;
}
}
void F_44 ( struct V_13 * V_13 )
{
F_39 ( V_13 ) ;
F_22 ( V_13 ) ;
}
void F_45 ( struct V_13 * * V_26 , int V_27 )
{
struct V_13 * * V_28 = V_26 ;
F_46 () ;
while ( V_27 ) {
int V_29 = F_47 ( V_27 , V_30 ) ;
int V_1 ;
for ( V_1 = 0 ; V_1 < V_29 ; V_1 ++ )
F_39 ( V_28 [ V_1 ] ) ;
F_48 ( V_28 , V_29 , 0 ) ;
V_28 += V_29 ;
V_27 -= V_29 ;
}
}
struct V_13 * F_49 ( T_1 V_14 )
{
struct V_13 * V_13 ;
V_13 = F_50 ( F_13 ( V_14 ) , V_14 . V_16 ) ;
if ( V_13 )
F_18 ( V_9 ) ;
F_18 ( V_10 ) ;
return V_13 ;
}
struct V_13 * F_51 ( T_1 V_14 , T_2 V_21 ,
struct V_31 * V_32 , unsigned long V_33 )
{
struct V_13 * V_34 , * V_35 = NULL ;
int V_22 ;
do {
V_34 = F_50 ( F_13 ( V_14 ) ,
V_14 . V_16 ) ;
if ( V_34 )
break;
if ( ! V_35 ) {
V_35 = F_52 ( V_21 , V_32 , V_33 ) ;
if ( ! V_35 )
break;
}
V_22 = F_24 ( V_21 & V_36 ) ;
if ( V_22 )
break;
V_22 = F_53 ( V_14 ) ;
if ( V_22 == - V_20 ) {
F_25 () ;
continue;
}
if ( V_22 ) {
F_25 () ;
break;
}
F_54 ( V_35 ) ;
F_55 ( V_35 ) ;
V_22 = F_5 ( V_35 , V_14 ) ;
if ( F_16 ( ! V_22 ) ) {
F_25 () ;
F_56 ( V_35 ) ;
F_57 ( V_35 ) ;
return V_35 ;
}
F_25 () ;
F_58 ( V_35 ) ;
F_59 ( V_35 ) ;
F_36 ( V_14 , NULL ) ;
} while ( V_22 != - V_37 );
if ( V_35 )
F_22 ( V_35 ) ;
return V_34 ;
}
struct V_13 * F_60 ( T_1 V_14 , T_2 V_21 ,
struct V_31 * V_32 , unsigned long V_33 )
{
struct V_13 * V_13 ;
unsigned long V_38 = F_61 ( V_14 ) ;
unsigned long V_39 , V_40 ;
unsigned long V_41 = ( 1UL << V_42 ) - 1 ;
struct V_43 V_44 ;
V_39 = V_38 & ~ V_41 ;
V_40 = V_38 | V_41 ;
if ( ! V_39 )
V_39 ++ ;
F_62 ( & V_44 ) ;
for ( V_38 = V_39 ; V_38 <= V_40 ; V_38 ++ ) {
V_13 = F_51 ( F_63 ( F_64 ( V_14 ) , V_38 ) ,
V_21 , V_32 , V_33 ) ;
if ( ! V_13 )
continue;
F_22 ( V_13 ) ;
}
F_65 ( & V_44 ) ;
F_46 () ;
return F_51 ( V_14 , V_21 , V_32 , V_33 ) ;
}
