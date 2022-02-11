static unsigned long F_1 ( unsigned long V_1 , const void * V_2 ,
T_1 V_3 )
{
T_1 V_4 ;
unsigned long * V_5 = ( unsigned long * ) V_2 ;
for ( V_4 = 0 ; V_4 < V_3 / sizeof( V_1 ) ; V_4 ++ ) {
V_1 = ( V_1 << ( ( sizeof( V_1 ) * 8 ) - 7 ) ) | ( V_1 >> 7 ) ;
V_1 ^= V_5 [ V_4 ] ;
}
return V_1 ;
}
static unsigned long F_2 ( void )
{
unsigned long V_1 = 0 ;
V_1 = F_1 ( V_1 , V_6 , sizeof( V_6 ) ) ;
V_1 = F_1 ( V_1 , V_7 , sizeof( * V_7 ) ) ;
return V_1 ;
}
static bool F_3 ( struct V_8 * V_9 , struct V_8 * V_10 )
{
if ( V_9 -> V_11 + V_9 -> V_3 <= V_10 -> V_11 )
return false ;
if ( V_9 -> V_11 >= V_10 -> V_11 + V_10 -> V_3 )
return false ;
return true ;
}
static void F_4 ( unsigned long V_12 , unsigned long V_13 ,
unsigned long V_14 )
{
unsigned long V_15 = V_7 -> V_16 . V_15 ;
T_2 V_17 , V_18 ;
T_2 V_19 , V_20 ;
char * V_5 ;
V_21 [ V_22 ] . V_11 = V_12 ;
V_21 [ V_22 ] . V_3 = ( V_14 + V_15 ) - V_12 ;
F_5 ( V_21 [ V_22 ] . V_11 ,
V_21 [ V_22 ] . V_3 ) ;
V_17 = ( T_2 ) V_7 -> V_23 << 32 ;
V_17 |= V_7 -> V_16 . V_24 ;
V_18 = ( T_2 ) V_7 -> V_25 << 32 ;
V_18 |= V_7 -> V_16 . V_26 ;
V_21 [ V_27 ] . V_11 = V_17 ;
V_21 [ V_27 ] . V_3 = V_18 ;
V_19 = ( T_2 ) V_7 -> V_28 << 32 ;
V_19 |= V_7 -> V_16 . V_29 ;
V_5 = ( char * ) ( unsigned long ) V_19 ;
for ( V_20 = 0 ; V_5 [ V_20 ++ ] ; )
;
V_21 [ V_30 ] . V_11 = V_19 ;
V_21 [ V_30 ] . V_3 = V_20 ;
F_5 ( V_21 [ V_30 ] . V_11 ,
V_21 [ V_30 ] . V_3 ) ;
V_21 [ V_31 ] . V_11 = ( unsigned long ) V_7 ;
V_21 [ V_31 ] . V_3 = sizeof( * V_7 ) ;
F_5 ( V_21 [ V_31 ] . V_11 ,
V_21 [ V_31 ] . V_3 ) ;
#ifdef F_6
F_5 ( 0 , V_32 ) ;
#endif
}
static bool F_7 ( struct V_8 * V_33 ,
struct V_8 * V_34 )
{
int V_4 ;
struct V_35 * V_5 ;
unsigned long V_36 = V_33 -> V_11 + V_33 -> V_3 ;
bool V_37 = false ;
for ( V_4 = 0 ; V_4 < V_38 ; V_4 ++ ) {
if ( F_3 ( V_33 , & V_21 [ V_4 ] ) &&
V_21 [ V_4 ] . V_11 < V_36 ) {
* V_34 = V_21 [ V_4 ] ;
V_36 = V_34 -> V_11 ;
V_37 = true ;
}
}
V_5 = (struct V_35 * ) ( unsigned long ) V_7 -> V_16 . V_35 ;
while ( V_5 ) {
struct V_8 V_39 ;
V_39 . V_11 = ( unsigned long ) V_5 ;
V_39 . V_3 = sizeof( * V_5 ) + V_5 -> V_40 ;
if ( F_3 ( V_33 , & V_39 ) && ( V_39 . V_11 < V_36 ) ) {
* V_34 = V_39 ;
V_36 = V_34 -> V_11 ;
V_37 = true ;
}
V_5 = (struct V_35 * ) ( unsigned long ) V_5 -> V_41 ;
}
return V_37 ;
}
static void F_8 ( struct V_8 * V_42 , unsigned long V_43 )
{
struct V_44 V_44 ;
if ( V_45 == V_46 )
return;
V_44 . V_47 = V_42 -> V_11 ;
V_44 . V_48 = ( V_42 -> V_3 - V_43 ) /
V_49 + 1 ;
if ( V_44 . V_48 > 0 ) {
V_50 [ V_45 ++ ] = V_44 ;
V_51 += V_44 . V_48 ;
}
}
static unsigned long F_9 ( void )
{
unsigned long V_52 ;
int V_4 ;
if ( V_51 == 0 )
return 0 ;
V_52 = F_10 ( L_1 ) % V_51 ;
for ( V_4 = 0 ; V_4 < V_45 ; V_4 ++ ) {
if ( V_52 >= V_50 [ V_4 ] . V_48 ) {
V_52 -= V_50 [ V_4 ] . V_48 ;
continue;
}
return V_50 [ V_4 ] . V_47 + V_52 * V_49 ;
}
if ( V_4 == V_45 )
F_11 ( L_2 ) ;
return 0 ;
}
static void F_12 ( struct V_53 * V_54 ,
unsigned long V_55 ,
unsigned long V_43 )
{
struct V_8 V_42 , V_34 ;
struct V_44 V_44 ;
unsigned long V_56 ;
if ( V_54 -> type != V_57 )
return;
if ( F_13 ( V_58 ) && V_54 -> V_47 >= V_59 )
return;
if ( V_54 -> V_47 + V_54 -> V_3 < V_55 )
return;
V_42 . V_11 = V_54 -> V_47 ;
V_42 . V_3 = V_54 -> V_3 ;
while ( V_45 < V_46 ) {
V_56 = V_42 . V_11 ;
if ( V_42 . V_11 < V_55 )
V_42 . V_11 = V_55 ;
V_42 . V_11 = F_14 ( V_42 . V_11 , V_49 ) ;
if ( V_42 . V_11 > V_54 -> V_47 + V_54 -> V_3 )
return;
V_42 . V_3 -= V_42 . V_11 - V_56 ;
if ( F_13 ( V_58 ) &&
V_42 . V_11 + V_42 . V_3 > V_59 )
V_42 . V_3 = V_59 - V_42 . V_11 ;
if ( V_42 . V_3 < V_43 )
return;
if ( ! F_7 ( & V_42 , & V_34 ) ) {
F_8 ( & V_42 , V_43 ) ;
return;
}
if ( V_34 . V_11 > V_42 . V_11 + V_43 ) {
struct V_8 V_60 ;
V_60 . V_11 = V_42 . V_11 ;
V_60 . V_3 = V_34 . V_11 - V_42 . V_11 ;
F_8 ( & V_60 , V_43 ) ;
}
if ( V_34 . V_11 + V_34 . V_3 >= V_42 . V_11 + V_42 . V_3 )
return;
V_42 . V_3 -= V_34 . V_11 - V_42 . V_11 + V_34 . V_3 ;
V_42 . V_11 = V_34 . V_11 + V_34 . V_3 ;
}
}
static unsigned long F_15 ( unsigned long V_55 ,
unsigned long V_43 )
{
int V_4 ;
unsigned long V_47 ;
V_55 = F_14 ( V_55 , V_49 ) ;
for ( V_4 = 0 ; V_4 < V_7 -> V_61 ; V_4 ++ ) {
F_12 ( & V_7 -> V_62 [ V_4 ] , V_55 ,
V_43 ) ;
if ( V_45 == V_46 ) {
F_11 ( L_3 ) ;
break;
}
}
return F_9 () ;
}
static unsigned long F_16 ( unsigned long V_55 ,
unsigned long V_43 )
{
unsigned long V_63 , V_64 ;
V_55 = F_14 ( V_55 , V_49 ) ;
V_43 = F_14 ( V_43 , V_49 ) ;
V_63 = ( V_59 - V_55 - V_43 ) /
V_49 + 1 ;
V_64 = F_10 ( L_4 ) % V_63 ;
return V_64 * V_49 + V_55 ;
}
void F_17 ( unsigned long V_12 ,
unsigned long V_13 ,
unsigned long * V_14 ,
unsigned long V_65 ,
unsigned long * V_66 )
{
unsigned long V_64 , V_67 ;
* V_66 = * V_14 ;
if ( F_18 ( L_5 ) ) {
F_19 ( L_6 ) ;
return;
}
V_7 -> V_16 . V_68 |= V_69 ;
F_20 () ;
F_4 ( V_12 , V_13 , * V_14 ) ;
V_67 = F_21 ( * V_14 , 512UL << 20 ) ;
V_64 = F_15 ( V_67 , V_65 ) ;
if ( ! V_64 ) {
F_19 ( L_7 ) ;
} else {
if ( * V_14 != V_64 ) {
F_5 ( V_64 , V_65 ) ;
* V_14 = V_64 ;
}
}
F_22 () ;
if ( F_13 ( V_70 ) )
V_64 = F_16 ( V_71 , V_65 ) ;
* V_66 = V_64 ;
}
