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
struct V_28 * F_12 ( struct V_29 * V_30 )
{
struct V_28 * V_31 ;
struct V_32 * V_33 ;
V_33 = F_13 ( V_30 -> V_34 , L_2 , 0 ) ;
if ( ! V_33 )
return NULL ;
V_31 = F_14 ( V_33 ) ;
F_15 ( V_33 ) ;
if ( ! V_31 )
return F_16 ( - V_35 ) ;
if ( ! V_31 -> V_36 . V_37 ) {
V_31 -> V_36 . V_37 = V_31 -> V_36 . V_38 ;
F_4 ( L_3 ,
V_31 -> V_36 . V_37 ) ;
}
return V_31 ;
}
int F_17 ( struct V_28 * V_31 )
{
unsigned int V_39 ;
int V_40 ;
if ( ! V_31 )
return 0 ;
V_39 = V_31 -> V_36 . V_41 ;
V_31 -> V_36 . V_41 &= ~ V_42 ;
F_4 ( L_4 , V_39 ,
V_31 -> V_36 . V_41 ) ;
V_40 = F_18 ( V_31 ) ;
if ( V_40 )
F_19 ( L_5 , V_40 ) ;
return V_40 ;
}
int F_20 ( struct V_28 * V_31 )
{
unsigned int V_39 ;
int V_40 ;
if ( ! V_31 )
return 0 ;
V_39 = V_31 -> V_36 . V_41 ;
V_31 -> V_36 . V_41 |= V_42 ;
F_4 ( L_4 , V_39 ,
V_31 -> V_36 . V_41 ) ;
V_40 = F_18 ( V_31 ) ;
if ( V_40 )
F_19 ( L_6 , V_40 ) ;
return V_40 ;
}
T_2 F_21 ( struct V_43 * V_44 , T_2 V_45 )
{
T_2 V_40 ;
V_40 = F_2 ( F_22 ( V_44 ) , V_44 -> V_46 -> V_47 ) ;
if ( V_45 )
V_40 = F_2 ( V_40 , V_45 ) ;
if ( V_48 )
V_40 = F_23 ( T_2 , V_40 , V_48 ) ;
V_40 &= ~ 0x3 ;
if ( V_40 < 4 )
V_40 = 4 ;
return V_40 ;
}
bool F_24 ( struct V_43 * V_44 , T_4 V_49 )
{
T_1 V_50 = V_44 -> V_46 -> V_51 ;
if ( V_49 == 8 )
return true ;
if ( ! V_50 ) {
F_25 ( & V_44 -> V_30 ,
L_7 ) ;
return false ;
}
if ( V_50 & F_26 ( V_49 ) )
return true ;
return false ;
}
static void
F_27 ( struct V_43 * V_44 , struct V_52 * V_53 ,
const void * V_24 , int V_54 , bool V_55 )
{
T_1 V_56 = V_53 -> V_56 ? V_53 -> V_56 : V_44 -> V_57 ;
char V_58 [ 3 * 32 ] ;
F_28 ( V_24 , V_53 -> V_21 , 16 ,
F_29 ( V_53 -> V_59 , 8 ) ,
V_58 , sizeof( V_58 ) , false ) ;
F_30 ( V_60
L_8 , V_54 ,
V_56 > 1000000 ? V_56 / 1000000 : V_56 / 1000 ,
V_56 > 1000000 ? L_9 : L_10 , V_53 -> V_59 , V_53 -> V_21 ,
V_55 ? L_11 : L_12 , V_58 , V_53 -> V_21 > 16 ? L_13 : L_14 ) ;
}
void F_31 ( struct V_43 * V_44 , struct V_61 * V_62 )
{
struct V_52 * V_63 ;
struct V_64 * V_65 ;
int V_8 = 0 ;
F_32 (pos, &m->transfers) {
V_63 = F_33 ( V_65 , struct V_52 , V_66 ) ;
if ( V_63 -> V_67 )
F_27 ( V_44 , V_63 , V_63 -> V_67 , V_8 , true ) ;
if ( V_63 -> V_68 )
F_27 ( V_44 , V_63 , V_63 -> V_68 , V_8 , false ) ;
V_8 ++ ;
}
}
int F_34 ( struct V_43 * V_44 , T_1 V_56 ,
struct V_52 * V_69 , T_4 V_49 , const void * V_24 ,
T_2 V_21 )
{
struct V_52 V_53 = {
. V_59 = V_49 ,
. V_56 = V_56 ,
} ;
struct V_61 V_62 ;
T_3 * V_70 = NULL ;
T_2 V_71 ;
T_2 V_72 ;
int V_40 = 0 ;
if ( F_35 ( V_49 != 8 && V_49 != 16 ) )
return - V_73 ;
V_71 = F_21 ( V_44 , 0 ) ;
if ( V_74 & V_75 )
F_36 ( L_15 ,
V_76 , V_49 , V_71 ) ;
if ( V_49 == 16 && ! F_24 ( V_44 , 16 ) ) {
V_53 . V_59 = 8 ;
if ( F_37 () ) {
V_70 = F_8 ( F_2 ( V_21 , V_71 ) , V_25 ) ;
if ( ! V_70 )
return - V_77 ;
}
}
F_38 ( & V_62 ) ;
if ( V_69 )
F_39 ( V_69 , & V_62 ) ;
F_39 ( & V_53 , & V_62 ) ;
while ( V_21 ) {
V_72 = F_2 ( V_21 , V_71 ) ;
V_53 . V_67 = V_24 ;
V_53 . V_21 = V_72 ;
if ( V_70 ) {
const T_3 * V_78 = V_24 ;
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < V_72 / 2 ; V_8 ++ )
V_70 [ V_8 ] = F_9 ( V_78 [ V_8 ] ) ;
V_53 . V_67 = V_70 ;
}
V_24 += V_72 ;
V_21 -= V_72 ;
F_40 ( V_44 , & V_62 ) ;
V_40 = F_41 ( V_44 , & V_62 ) ;
if ( V_40 )
return V_40 ;
}
return 0 ;
}
