bool F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 , unsigned int V_4 ,
unsigned int V_5 , T_1 V_6 , T_1 V_7 )
{
unsigned int V_8 ;
if ( ! V_3 || ! V_4 ) {
V_2 -> V_9 = 0 ;
V_2 -> V_10 = V_6 ;
V_2 -> y1 = 0 ;
V_2 -> V_11 = V_7 ;
return true ;
}
V_2 -> V_9 = ~ 0 ;
V_2 -> y1 = ~ 0 ;
V_2 -> V_10 = 0 ;
V_2 -> V_11 = 0 ;
for ( V_8 = 0 ; V_8 < V_4 ; V_8 ++ ) {
if ( V_5 & V_12 )
V_8 ++ ;
V_2 -> V_9 = F_2 ( V_2 -> V_9 , V_3 [ V_8 ] . V_9 ) ;
V_2 -> V_10 = F_3 ( V_2 -> V_10 , V_3 [ V_8 ] . V_10 ) ;
V_2 -> y1 = F_2 ( V_2 -> y1 , V_3 [ V_8 ] . y1 ) ;
V_2 -> V_11 = F_3 ( V_2 -> V_11 , V_3 [ V_8 ] . V_11 ) ;
}
if ( V_2 -> V_10 > V_6 || V_2 -> V_11 > V_7 ||
V_2 -> V_9 >= V_2 -> V_10 || V_2 -> y1 >= V_2 -> V_11 ) {
F_4 ( L_1 ,
V_2 -> V_9 , V_2 -> V_10 , V_2 -> y1 , V_2 -> V_11 ) ;
V_2 -> V_9 = 0 ;
V_2 -> y1 = 0 ;
V_2 -> V_10 = V_6 ;
V_2 -> V_11 = V_7 ;
}
return ( V_2 -> V_10 - V_2 -> V_9 ) == V_6 &&
( V_2 -> V_11 - V_2 -> y1 ) == V_7 ;
}
void F_5 ( void * V_2 , void * V_13 , struct V_14 * V_15 ,
struct V_1 * V_16 )
{
unsigned int V_17 = F_6 ( V_15 -> V_18 -> V_18 , 0 ) ;
unsigned int V_19 = V_15 -> V_20 [ 0 ] ;
void * V_3 = V_13 + ( V_16 -> y1 * V_19 ) + ( V_16 -> V_9 * V_17 ) ;
T_2 V_21 = ( V_16 -> V_10 - V_16 -> V_9 ) * V_17 ;
unsigned int V_22 ;
for ( V_22 = V_16 -> y1 ; V_22 < V_16 -> V_11 ; V_22 ++ ) {
memcpy ( V_2 , V_3 , V_21 ) ;
V_3 += V_19 ;
V_2 += V_21 ;
}
}
void F_7 ( T_3 * V_2 , void * V_13 , struct V_14 * V_15 ,
struct V_1 * V_16 )
{
T_2 V_21 = ( V_16 -> V_10 - V_16 -> V_9 ) * sizeof( T_3 ) ;
unsigned int V_23 , V_22 ;
T_3 * V_3 , * V_24 ;
V_24 = F_8 ( V_21 , V_25 ) ;
if ( ! V_24 )
return;
for ( V_22 = V_16 -> y1 ; V_22 < V_16 -> V_11 ; V_22 ++ ) {
V_3 = V_13 + ( V_22 * V_15 -> V_20 [ 0 ] ) ;
V_3 += V_16 -> V_9 ;
memcpy ( V_24 , V_3 , V_21 ) ;
V_3 = V_24 ;
for ( V_23 = V_16 -> V_9 ; V_23 < V_16 -> V_10 ; V_23 ++ )
* V_2 ++ = F_9 ( * V_3 ++ ) ;
}
F_10 ( V_24 ) ;
}
void F_11 ( T_3 * V_2 , void * V_13 ,
struct V_14 * V_15 ,
struct V_1 * V_16 , bool V_26 )
{
T_2 V_21 = ( V_16 -> V_10 - V_16 -> V_9 ) * sizeof( T_1 ) ;
unsigned int V_23 , V_22 ;
T_1 * V_3 , * V_24 ;
T_3 V_27 ;
V_24 = F_8 ( V_21 , V_25 ) ;
if ( ! V_24 )
return;
for ( V_22 = V_16 -> y1 ; V_22 < V_16 -> V_11 ; V_22 ++ ) {
V_3 = V_13 + ( V_22 * V_15 -> V_20 [ 0 ] ) ;
V_3 += V_16 -> V_9 ;
memcpy ( V_24 , V_3 , V_21 ) ;
V_3 = V_24 ;
for ( V_23 = V_16 -> V_9 ; V_23 < V_16 -> V_10 ; V_23 ++ ) {
V_27 = ( ( * V_3 & 0x00F80000 ) >> 8 ) |
( ( * V_3 & 0x0000FC00 ) >> 5 ) |
( ( * V_3 & 0x000000F8 ) >> 3 ) ;
V_3 ++ ;
if ( V_26 )
* V_2 ++ = F_9 ( V_27 ) ;
else
* V_2 ++ = V_27 ;
}
}
F_10 ( V_24 ) ;
}
void F_12 ( T_4 * V_2 , void * V_13 , struct V_14 * V_15 ,
struct V_1 * V_16 )
{
unsigned int V_21 = ( V_16 -> V_10 - V_16 -> V_9 ) * sizeof( T_1 ) ;
unsigned int V_23 , V_22 ;
void * V_24 ;
T_1 * V_3 ;
if ( F_13 ( V_15 -> V_18 -> V_18 != V_28 ) )
return;
V_24 = F_8 ( V_21 , V_25 ) ;
if ( ! V_24 )
return;
for ( V_22 = V_16 -> y1 ; V_22 < V_16 -> V_11 ; V_22 ++ ) {
V_3 = V_13 + ( V_22 * V_15 -> V_20 [ 0 ] ) ;
V_3 += V_16 -> V_9 ;
memcpy ( V_24 , V_3 , V_21 ) ;
V_3 = V_24 ;
for ( V_23 = V_16 -> V_9 ; V_23 < V_16 -> V_10 ; V_23 ++ ) {
T_4 V_29 = ( * V_3 & 0x00ff0000 ) >> 16 ;
T_4 V_30 = ( * V_3 & 0x0000ff00 ) >> 8 ;
T_4 V_31 = * V_3 & 0x000000ff ;
* V_2 ++ = ( 3 * V_29 + 6 * V_30 + V_31 ) / 10 ;
V_3 ++ ;
}
}
F_10 ( V_24 ) ;
}
struct V_32 * F_14 ( struct V_33 * V_34 )
{
struct V_32 * V_35 ;
struct V_36 * V_37 ;
V_37 = F_15 ( V_34 -> V_38 , L_2 , 0 ) ;
if ( ! V_37 )
return NULL ;
V_35 = F_16 ( V_37 ) ;
F_17 ( V_37 ) ;
if ( ! V_35 )
return F_18 ( - V_39 ) ;
if ( ! V_35 -> V_40 . V_41 ) {
V_35 -> V_40 . V_41 = V_35 -> V_40 . V_42 ;
F_4 ( L_3 ,
V_35 -> V_40 . V_41 ) ;
}
return V_35 ;
}
int F_19 ( struct V_32 * V_35 )
{
unsigned int V_43 ;
int V_44 ;
if ( ! V_35 )
return 0 ;
V_43 = V_35 -> V_40 . V_45 ;
V_35 -> V_40 . V_45 &= ~ V_46 ;
F_4 ( L_4 , V_43 ,
V_35 -> V_40 . V_45 ) ;
V_44 = F_20 ( V_35 ) ;
if ( V_44 )
F_21 ( L_5 , V_44 ) ;
return V_44 ;
}
int F_22 ( struct V_32 * V_35 )
{
unsigned int V_43 ;
int V_44 ;
if ( ! V_35 )
return 0 ;
V_43 = V_35 -> V_40 . V_45 ;
V_35 -> V_40 . V_45 |= V_46 ;
F_4 ( L_4 , V_43 ,
V_35 -> V_40 . V_45 ) ;
V_44 = F_20 ( V_35 ) ;
if ( V_44 )
F_21 ( L_6 , V_44 ) ;
return V_44 ;
}
T_2 F_23 ( struct V_47 * V_48 , T_2 V_49 )
{
T_2 V_44 ;
V_44 = F_2 ( F_24 ( V_48 ) , V_48 -> V_50 -> V_51 ) ;
if ( V_49 )
V_44 = F_2 ( V_44 , V_49 ) ;
if ( V_52 )
V_44 = F_25 ( T_2 , V_44 , V_52 ) ;
V_44 &= ~ 0x3 ;
if ( V_44 < 4 )
V_44 = 4 ;
return V_44 ;
}
bool F_26 ( struct V_47 * V_48 , T_4 V_53 )
{
T_1 V_54 = V_48 -> V_50 -> V_55 ;
if ( V_53 == 8 )
return true ;
if ( ! V_54 ) {
F_27 ( & V_48 -> V_34 ,
L_7 ) ;
return false ;
}
if ( V_54 & F_28 ( V_53 ) )
return true ;
return false ;
}
static void
F_29 ( struct V_47 * V_48 , struct V_56 * V_57 ,
const void * V_24 , int V_58 , bool V_59 )
{
T_1 V_60 = V_57 -> V_60 ? V_57 -> V_60 : V_48 -> V_61 ;
char V_62 [ 3 * 32 ] ;
F_30 ( V_24 , V_57 -> V_21 , 16 ,
F_31 ( V_57 -> V_63 , 8 ) ,
V_62 , sizeof( V_62 ) , false ) ;
F_32 ( V_64
L_8 , V_58 ,
V_60 > 1000000 ? V_60 / 1000000 : V_60 / 1000 ,
V_60 > 1000000 ? L_9 : L_10 , V_57 -> V_63 , V_57 -> V_21 ,
V_59 ? L_11 : L_12 , V_62 , V_57 -> V_21 > 16 ? L_13 : L_14 ) ;
}
void F_33 ( struct V_47 * V_48 , struct V_65 * V_66 )
{
struct V_56 * V_67 ;
struct V_68 * V_69 ;
int V_8 = 0 ;
F_34 (pos, &m->transfers) {
V_67 = F_35 ( V_69 , struct V_56 , V_70 ) ;
if ( V_67 -> V_71 )
F_29 ( V_48 , V_67 , V_67 -> V_71 , V_8 , true ) ;
if ( V_67 -> V_72 )
F_29 ( V_48 , V_67 , V_67 -> V_72 , V_8 , false ) ;
V_8 ++ ;
}
}
int F_36 ( struct V_47 * V_48 , T_1 V_60 ,
struct V_56 * V_73 , T_4 V_53 , const void * V_24 ,
T_2 V_21 )
{
struct V_56 V_57 = {
. V_63 = V_53 ,
. V_60 = V_60 ,
} ;
struct V_65 V_66 ;
T_3 * V_74 = NULL ;
T_2 V_75 ;
T_2 V_76 ;
int V_44 = 0 ;
if ( F_37 ( V_53 != 8 && V_53 != 16 ) )
return - V_77 ;
V_75 = F_23 ( V_48 , 0 ) ;
if ( V_78 & V_79 )
F_38 ( L_15 ,
V_80 , V_53 , V_75 ) ;
if ( V_53 == 16 && ! F_26 ( V_48 , 16 ) ) {
V_57 . V_63 = 8 ;
if ( F_39 () ) {
V_74 = F_8 ( F_2 ( V_21 , V_75 ) , V_25 ) ;
if ( ! V_74 )
return - V_81 ;
}
}
F_40 ( & V_66 ) ;
if ( V_73 )
F_41 ( V_73 , & V_66 ) ;
F_41 ( & V_57 , & V_66 ) ;
while ( V_21 ) {
V_76 = F_2 ( V_21 , V_75 ) ;
V_57 . V_71 = V_24 ;
V_57 . V_21 = V_76 ;
if ( V_74 ) {
const T_3 * V_82 = V_24 ;
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < V_76 / 2 ; V_8 ++ )
V_74 [ V_8 ] = F_9 ( V_82 [ V_8 ] ) ;
V_57 . V_71 = V_74 ;
}
V_24 += V_76 ;
V_21 -= V_76 ;
F_42 ( V_48 , & V_66 ) ;
V_44 = F_43 ( V_48 , & V_66 ) ;
if ( V_44 )
return V_44 ;
}
return 0 ;
}
