static void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 )
{
struct V_5 * V_6 =
F_2 ( V_2 -> V_7 [ V_3 ] ) ;
if ( F_3 ( V_4 ) ) {
V_2 -> V_8 [ V_3 ] = true ;
return;
}
if ( V_4 != V_9 ) {
V_2 -> V_10 [ V_3 ] = 0 ;
F_4 ( & V_2 -> V_11 [ V_3 ] ) ;
return;
}
F_5 ( V_6 , V_2 -> V_12 [ V_3 ] ) ;
V_2 -> V_12 [ V_3 ] = 0 ;
if ( ! F_6 ( V_6 ) )
F_4 ( & V_2 -> V_11 [ V_3 ] ) ;
}
static void F_7 ( struct V_13 * V_14 , int V_4 ,
void * V_15 , T_1 V_16 ,
void * V_17 )
{
struct V_1 * V_2 =
F_8 ( V_17 , struct V_1 , V_18 [ 0 ] ) ;
F_1 ( V_2 , 0 , V_4 ) ;
}
static void F_9 ( struct V_13 * V_14 , int V_4 ,
void * V_15 , T_1 V_16 ,
void * V_17 )
{
struct V_1 * V_2 =
F_8 ( V_17 , struct V_1 , V_18 [ 1 ] ) ;
F_1 ( V_2 , 1 , V_4 ) ;
}
static inline void F_10 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_19 , T_2 V_20 )
{
V_2 -> V_21 [ V_3 ] [ V_19 ] = F_11 ( V_20 ) ;
}
static void F_12 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_5 * V_6 =
F_2 ( V_2 -> V_7 [ V_3 ] ) ;
T_2 * V_22 = ( T_2 * ) V_2 -> V_21 [ V_3 ] ;
int V_23 , V_24 ;
struct V_25 * V_26 = F_13 ( V_2 -> V_27 ) ;
unsigned long long V_28 ;
int V_29 ;
T_3 V_30 ;
if ( V_6 == NULL || F_6 ( V_6 ) )
return;
if ( V_2 -> V_12 [ V_3 ] > 0 || V_2 -> V_8 [ V_3 ] )
return;
if ( F_14 ( V_2 -> V_10 [ V_3 ] , F_15 () ) ) {
F_4 ( & V_2 -> V_11 [ V_3 ] ) ;
return;
}
V_24 = F_16 ( V_6 , V_22 ,
V_31 ) ;
if ( V_24 <= 0 )
return;
for ( V_23 = V_24 - 1 ; V_23 >= 0 ; V_23 -- )
F_10 ( V_2 , V_3 , V_23 , V_22 [ V_23 ] ) ;
if ( V_3 == 0 ) {
V_28 = V_2 -> V_32 -> V_33 -> V_34 ;
V_30 = F_7 ;
} else {
V_28 = V_2 -> V_32 -> V_33 -> V_35 ;
V_30 = F_9 ;
}
V_2 -> V_10 [ V_3 ] = F_17 ( F_15 () ,
V_24 * 8 * V_36 / 31250 ) ;
V_2 -> V_12 [ V_3 ] = V_24 ;
V_29 = V_26 -> V_29 ;
F_18 () ;
F_19 ( V_26 -> V_14 , & V_2 -> V_18 [ V_3 ] ,
V_37 ,
V_26 -> V_38 , V_29 , V_26 -> V_39 ,
V_28 , & V_2 -> V_21 [ V_3 ] , V_24 * 4 ,
V_30 , & V_2 -> V_18 [ V_3 ] ) ;
}
static void F_20 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_8 ( V_41 , struct V_1 , V_11 [ 0 ] ) ;
F_12 ( V_2 , 0 ) ;
}
static void F_21 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_8 ( V_41 , struct V_1 , V_11 [ 1 ] ) ;
F_12 ( V_2 , 1 ) ;
}
static void F_22 ( struct V_13 * V_14 , struct V_42 * V_43 ,
int V_44 , int V_45 , int V_46 ,
int V_29 , unsigned long long V_47 ,
void * V_15 , T_1 V_16 , void * V_17 )
{
struct V_1 * V_2 = V_17 ;
T_4 * V_22 = V_15 ;
T_5 V_48 ;
T_2 V_20 ;
unsigned int V_19 ;
struct V_5 * V_6 ;
int V_23 ;
F_23 ( V_14 , V_43 , V_9 ) ;
for ( V_23 = 0 ; V_23 < V_16 / 4 ; V_23 ++ ) {
V_48 = F_24 ( V_22 [ V_23 ] ) ;
V_19 = ( V_48 >> 8 ) & 0xff ;
if ( V_19 > 0 ) {
V_6 = F_2 ( V_2 -> V_49 [ 0 ] ) ;
if ( V_6 != NULL ) {
V_20 = V_48 & 0xff ;
F_25 ( V_6 , & V_20 , 1 ) ;
}
}
V_19 = ( V_48 >> 24 ) & 0xff ;
if ( V_19 > 0 ) {
V_6 = F_2 ( V_2 -> V_49 [ 1 ] ) ;
if ( V_6 != NULL ) {
V_20 = ( V_48 >> 16 ) & 0xff ;
F_25 ( V_6 , & V_20 , 1 ) ;
}
}
}
}
static int F_26 ( struct V_1 * V_2 , int V_23 )
{
struct V_50 V_51 ;
int V_52 ;
V_2 -> V_53 . V_16 = V_31 * 4 ;
V_2 -> V_53 . V_54 = F_22 ;
V_2 -> V_53 . V_17 = V_2 ;
V_51 . V_55 = 0x000100000000ull * V_23 ;
V_51 . V_56 = V_51 . V_55 + V_2 -> V_53 . V_16 ;
V_52 = F_27 ( & V_2 -> V_53 , & V_51 ) ;
if ( V_52 >= 0 ) {
if ( V_2 -> V_53 . V_47 & 0x0000ffffffff ) {
F_28 ( & V_2 -> V_53 ) ;
V_52 = - V_57 ;
}
}
return V_52 ;
}
int F_29 ( struct V_1 * V_2 )
{
struct V_13 * V_13 = F_13 ( V_2 -> V_27 ) -> V_14 ;
T_5 V_28 ;
T_4 V_58 ;
V_28 = ( V_13 -> V_38 << 16 ) | ( V_2 -> V_53 . V_47 >> 32 ) ;
V_58 = F_11 ( V_28 ) ;
return F_30 ( V_2 -> V_27 , V_59 ,
V_2 -> V_32 -> V_33 -> V_60 ,
& V_58 , sizeof( V_58 ) , 0 ) ;
}
int F_31 ( struct V_1 * V_2 )
{
int V_23 , V_52 ;
for ( V_23 = 0 ; V_23 < 0xffff ; V_23 ++ ) {
V_52 = F_26 ( V_2 , V_23 ) ;
if ( V_52 != - V_61 && V_52 != - V_57 )
break;
}
if ( V_52 < 0 )
return V_52 ;
V_52 = F_29 ( V_2 ) ;
if ( V_52 < 0 )
return V_52 ;
F_32 ( & V_2 -> V_11 [ 0 ] , F_20 ) ;
F_32 ( & V_2 -> V_11 [ 1 ] , F_21 ) ;
return 0 ;
}
void F_33 ( struct V_1 * V_2 )
{
T_4 V_58 ;
if ( V_2 -> V_53 . V_17 == NULL )
return;
V_2 -> V_53 . V_17 = NULL ;
V_58 = F_11 ( 0x00000000 ) ;
F_30 ( V_2 -> V_27 , V_59 ,
V_2 -> V_32 -> V_33 -> V_60 ,
& V_58 , sizeof( V_58 ) , 0 ) ;
F_28 ( & V_2 -> V_53 ) ;
}
