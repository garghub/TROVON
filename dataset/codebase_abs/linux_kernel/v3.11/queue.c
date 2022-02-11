static inline void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 -> V_5 ++ == 0 ) {
F_2 ( L_1 ,
V_2 -> V_6 ) ;
F_3 ( V_4 -> V_7 -> V_8 , V_2 -> V_6 ) ;
}
}
static inline void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_5 ( ! V_2 -> V_5 ) ;
if ( -- V_2 -> V_5 == 0 ) {
F_2 ( L_2 ,
V_2 -> V_6 ) ;
F_6 ( V_4 -> V_7 -> V_8 , V_2 -> V_6 ) ;
}
}
static inline void F_7 ( T_1 V_9 , T_2 * V_10 ,
T_2 * V_6 , T_2 * V_11 ,
T_2 * V_12 )
{
* V_12 = ( V_9 >> 0 ) & 0xFF ;
* V_11 = ( V_9 >> 8 ) & 0xFF ;
* V_6 = ( V_9 >> 16 ) & 0xFF ;
* V_10 = ( V_9 >> 24 ) & 0xFF ;
}
static inline T_1 F_8 ( T_2 V_10 , T_2 V_6 ,
T_2 V_11 , T_2 V_12 )
{
return ( ( T_1 ) V_12 << 0 ) |
( ( T_1 ) V_11 << 8 ) |
( ( T_1 ) V_6 << 16 ) |
( ( T_1 ) V_10 << 24 ) ;
}
static void F_9 ( struct V_3 * V_4 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 , * V_17 ;
F_10 (item, tmp, gc_list, head) {
F_11 ( & V_16 -> V_18 ) ;
V_4 -> V_19 ( V_4 -> V_7 , V_16 -> V_20 , & V_16 -> V_21 ) ;
F_12 ( V_16 ) ;
}
}
static void F_13 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_15 * V_22 ;
V_22 = F_14 ( sizeof( struct V_15 ) ,
V_23 ) ;
F_5 ( ! V_22 ) ;
memcpy ( V_22 , V_16 , sizeof( struct V_15 ) ) ;
F_15 ( & V_22 -> V_18 , V_14 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_13 * V_18 ,
bool V_24 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_15 * V_16 = NULL , * V_17 ;
bool V_25 = false ;
F_10 (item, tmp, &queue->queue, head) {
if ( V_26 - V_16 -> V_27 < V_2 -> V_28 )
break;
-- V_2 -> V_29 ;
-- V_2 -> V_30 [ V_16 -> V_21 . V_31 ] ;
F_17 ( & V_4 -> V_32 ) ;
-- V_4 -> V_29 ;
if ( ! -- V_4 -> V_30 [ V_16 -> V_21 . V_31 ] )
V_25 = true ;
F_18 ( & V_4 -> V_32 ) ;
F_19 ( V_4 -> V_7 ) ;
F_13 ( V_18 , V_16 ) ;
V_16 -> V_20 = NULL ;
F_20 ( & V_16 -> V_18 , & V_2 -> V_33 ) ;
}
if ( V_25 )
F_21 ( & V_4 -> V_34 ) ;
if ( V_2 -> V_35 ) {
if ( V_2 -> V_29 <= ( V_2 -> V_36 >> 1 ) ) {
V_2 -> V_35 = false ;
if ( V_24 )
F_4 ( V_2 ) ;
} else if ( V_16 ) {
unsigned long V_37 = V_16 -> V_27 + V_2 -> V_28 ;
F_22 ( & V_2 -> V_38 , V_37 ) ;
F_23 ( & V_4 -> V_7 -> V_39 ,
V_37 - V_26 ) ;
}
}
}
static void F_24 ( unsigned long V_40 )
{
F_25 ( V_41 ) ;
struct V_1 * V_2 =
(struct V_1 * ) V_40 ;
F_17 ( & V_2 -> V_32 ) ;
F_16 ( V_2 , & V_41 , true ) ;
F_18 ( & V_2 -> V_32 ) ;
F_9 ( V_2 -> V_4 , & V_41 ) ;
}
int F_26 ( struct V_3 * V_4 ,
T_3 V_42 ,
T_4 V_19 ,
struct V_43 * V_7 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_42 = V_42 ;
V_4 -> V_19 = V_19 ;
V_4 -> V_7 = V_7 ;
F_27 ( & V_4 -> V_32 ) ;
F_28 ( & V_4 -> V_34 ) ;
V_4 -> V_30 = F_29 ( sizeof( int ) * V_42 ,
V_44 ) ;
if ( ! V_4 -> V_30 )
return - V_45 ;
return 0 ;
}
int F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_2 V_6 ,
T_3 V_36 ,
unsigned long V_28 )
{
T_3 V_46 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_36 = V_36 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_28 = V_28 ;
F_31 ( & V_2 -> V_2 ) ;
F_31 ( & V_2 -> V_47 ) ;
F_31 ( & V_2 -> V_33 ) ;
F_27 ( & V_2 -> V_32 ) ;
F_32 ( & V_2 -> V_38 ) ;
V_2 -> V_38 . V_48 = ( unsigned long ) V_2 ;
V_2 -> V_38 . V_49 = F_24 ;
V_2 -> V_50 = F_29 ( sizeof( struct V_15 ) * V_36 ,
V_44 ) ;
if ( ! V_2 -> V_50 )
return - V_45 ;
V_2 -> V_30 = F_29 ( sizeof( int ) * V_4 -> V_42 ,
V_44 ) ;
if ( ! V_2 -> V_30 ) {
F_12 ( V_2 -> V_50 ) ;
V_2 -> V_50 = NULL ;
return - V_45 ;
}
for ( V_46 = 0 ; V_46 < V_36 ; ++ V_46 )
F_15 ( & V_2 -> V_50 [ V_46 ] . V_18 , & V_2 -> V_33 ) ;
return 0 ;
}
int F_33 ( struct V_1 * V_2 )
{
int V_46 ;
F_25 ( V_14 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_15 * V_16 , * V_17 ;
F_17 ( & V_2 -> V_32 ) ;
V_2 -> V_51 ++ ;
F_34 ( & V_2 -> V_2 , & V_2 -> V_47 ) ;
F_10 (item, tmp, &queue->pending, head) {
F_35 ( ! V_16 -> V_20 ) ;
F_13 ( & V_14 , V_16 ) ;
V_16 -> V_20 = NULL ;
F_20 ( & V_16 -> V_18 , & V_2 -> V_33 ) ;
}
V_2 -> V_29 = 0 ;
V_2 -> V_52 = 0 ;
F_17 ( & V_4 -> V_32 ) ;
for ( V_46 = 0 ; V_46 < V_4 -> V_42 ; ++ V_46 ) {
V_4 -> V_29 -= V_2 -> V_30 [ V_46 ] ;
V_4 -> V_30 [ V_46 ] -= V_2 -> V_30 [ V_46 ] ;
V_2 -> V_30 [ V_46 ] = 0 ;
}
F_18 ( & V_4 -> V_32 ) ;
if ( V_2 -> V_35 ) {
V_2 -> V_35 = false ;
F_4 ( V_2 ) ;
}
F_18 ( & V_2 -> V_32 ) ;
F_21 ( & V_4 -> V_34 ) ;
F_9 ( V_4 , & V_14 ) ;
return 0 ;
}
void F_36 ( struct V_3 * V_4 )
{
F_12 ( V_4 -> V_30 ) ;
V_4 -> V_30 = NULL ;
}
void F_37 ( struct V_1 * V_2 )
{
F_33 ( V_2 ) ;
F_38 ( & V_2 -> V_38 ) ;
F_31 ( & V_2 -> V_33 ) ;
F_12 ( V_2 -> V_50 ) ;
F_12 ( V_2 -> V_30 ) ;
V_2 -> V_50 = NULL ;
V_2 -> V_30 = NULL ;
V_2 -> V_36 = 0 ;
}
T_3 F_39 ( struct V_1 * V_2 ,
T_1 V_53 )
{
T_3 V_54 ;
int V_46 , V_55 ;
T_3 V_42 = V_2 -> V_4 -> V_42 ;
if ( ! V_53 )
return 0 ;
F_17 ( & V_2 -> V_32 ) ;
if ( V_53 == ( T_1 ) - 1 ) {
V_54 = V_2 -> V_29 - V_2 -> V_52 ;
} else {
V_54 = 0 ;
for ( V_46 = 0 , V_55 = 1 ; V_46 < V_42 ; ++ V_46 , V_55 <<= 1 ) {
if ( V_53 & V_55 )
V_54 += V_2 -> V_30 [ V_46 ] ;
}
}
F_18 ( & V_2 -> V_32 ) ;
return V_54 ;
}
int F_40 ( struct V_1 * V_2 ,
struct V_56 * V_20 ,
struct V_57 * V_21 )
{
int V_54 = 0 ;
F_25 ( V_14 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_21 -> V_31 >= V_2 -> V_4 -> V_42 )
return - V_58 ;
F_17 ( & V_2 -> V_32 ) ;
if ( ! F_35 ( F_41 ( & V_2 -> V_33 ) ) ) {
struct V_15 * V_16 = F_42 (
& V_2 -> V_33 , struct V_15 , V_18 ) ;
F_5 ( V_16 -> V_20 ) ;
F_20 ( & V_16 -> V_18 , & V_2 -> V_2 ) ;
V_16 -> V_20 = V_20 ;
V_16 -> V_21 = * V_21 ;
V_16 -> V_51 = 0 ;
V_16 -> V_9 = F_8 ( V_2 -> V_51 ,
V_2 -> V_6 ,
V_16 -> V_51 ,
V_16 - V_2 -> V_50 ) ;
V_16 -> V_27 = V_26 ;
++ V_2 -> V_29 ;
++ V_2 -> V_30 [ V_21 -> V_31 ] ;
F_17 ( & V_4 -> V_32 ) ;
++ V_4 -> V_29 ;
++ V_4 -> V_30 [ V_21 -> V_31 ] ;
F_18 ( & V_4 -> V_32 ) ;
if ( V_2 -> V_35 == false &&
V_2 -> V_29 >=
( V_2 -> V_36 - ( F_43 () - 1 ) ) ) {
V_2 -> V_35 = true ;
F_1 ( V_2 ) ;
F_22 ( & V_2 -> V_38 , V_26 ) ;
}
} else {
V_54 = - V_59 ;
}
F_18 ( & V_2 -> V_32 ) ;
return V_54 ;
}
int F_44 ( struct V_1 * V_2 ,
T_1 V_53 ,
struct V_60 * * V_61 ,
struct V_62 * * V_63 ,
const struct V_57 * * V_21 )
{
int V_54 = - V_59 ;
struct V_15 * V_16 ;
struct V_3 * V_4 = V_2 -> V_4 ;
bool V_25 = false ;
F_17 ( & V_2 -> V_32 ) ;
F_45 (item, &queue->queue, head) {
if ( V_53 & F_46 ( V_16 -> V_21 . V_31 ) ) {
V_54 = 0 ;
break;
}
}
if ( ! F_35 ( V_54 ) ) {
* V_61 = (struct V_60 * ) V_16 -> V_20 -> V_48 ;
* V_63 = F_47 ( V_16 -> V_20 ) ;
* V_21 = & V_16 -> V_21 ;
( * V_61 ) -> V_9 = V_16 -> V_9 ;
F_20 ( & V_16 -> V_18 , & V_2 -> V_47 ) ;
++ V_2 -> V_52 ;
-- V_2 -> V_30 [ V_16 -> V_21 . V_31 ] ;
V_16 -> V_64 = V_26 ;
F_17 ( & V_4 -> V_32 ) ;
-- V_4 -> V_29 ;
if ( ! -- V_4 -> V_30 [ V_16 -> V_21 . V_31 ] )
V_25 = true ;
F_18 ( & V_4 -> V_32 ) ;
}
F_18 ( & V_2 -> V_32 ) ;
if ( V_25 )
F_21 ( & V_4 -> V_34 ) ;
return V_54 ;
}
int F_48 ( struct V_1 * V_2 , T_1 V_9 )
{
int V_54 = 0 ;
T_2 V_10 , V_6 , V_11 , V_12 ;
struct V_15 * V_16 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_7 ( V_9 , & V_10 , & V_6 ,
& V_11 , & V_12 ) ;
V_16 = & V_2 -> V_50 [ V_12 ] ;
F_17 ( & V_2 -> V_32 ) ;
F_5 ( V_6 != V_2 -> V_6 ) ;
if ( V_10 != V_2 -> V_51 ) {
V_54 = - V_59 ;
} else if ( V_12 >= ( unsigned ) V_2 -> V_36 ) {
F_35 ( 1 ) ;
V_54 = - V_58 ;
} else if ( V_16 -> V_51 != V_11 ) {
F_35 ( 1 ) ;
V_54 = - V_59 ;
} else {
-- V_2 -> V_52 ;
++ V_2 -> V_30 [ V_16 -> V_21 . V_31 ] ;
F_17 ( & V_4 -> V_32 ) ;
++ V_4 -> V_29 ;
++ V_4 -> V_30 [ V_16 -> V_21 . V_31 ] ;
F_18 ( & V_4 -> V_32 ) ;
V_16 -> V_51 = ++ V_11 ;
V_16 -> V_9 = F_8 ( V_10 ,
V_6 ,
V_11 ,
V_12 ) ;
F_49 ( & V_16 -> V_18 , & V_2 -> V_2 ) ;
}
F_18 ( & V_2 -> V_32 ) ;
return V_54 ;
}
int F_50 ( struct V_1 * V_2 )
{
struct V_15 * V_16 , * V_17 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_17 ( & V_2 -> V_32 ) ;
F_51 (item, tmp, &queue->pending, head) {
-- V_2 -> V_52 ;
++ V_2 -> V_30 [ V_16 -> V_21 . V_31 ] ;
F_17 ( & V_4 -> V_32 ) ;
++ V_4 -> V_29 ;
++ V_4 -> V_30 [ V_16 -> V_21 . V_31 ] ;
F_18 ( & V_4 -> V_32 ) ;
++ V_16 -> V_51 ;
V_16 -> V_9 = F_8 ( V_2 -> V_51 ,
V_2 -> V_6 ,
V_16 -> V_51 ,
V_16 - V_2 -> V_50 ) ;
F_49 ( & V_16 -> V_18 , & V_2 -> V_2 ) ;
}
F_18 ( & V_2 -> V_32 ) ;
return 0 ;
}
int F_52 ( struct V_1 * V_2 , T_1 V_9 )
{
int V_54 = 0 ;
T_2 V_10 , V_6 , V_11 , V_12 ;
struct V_15 * V_16 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_56 * V_65 = NULL ;
struct V_57 V_66 ;
F_7 ( V_9 , & V_10 , & V_6 ,
& V_11 , & V_12 ) ;
V_16 = & V_2 -> V_50 [ V_12 ] ;
F_17 ( & V_2 -> V_32 ) ;
F_5 ( V_6 != V_2 -> V_6 ) ;
if ( V_10 != V_2 -> V_51 ) {
V_54 = - V_59 ;
} else if ( V_12 >= ( unsigned ) V_2 -> V_36 ) {
F_35 ( 1 ) ;
V_54 = - V_58 ;
} else if ( V_16 -> V_51 != V_11 ) {
F_35 ( 1 ) ;
V_54 = - V_59 ;
} else {
V_66 = V_16 -> V_21 ;
V_65 = V_16 -> V_20 ;
V_16 -> V_20 = NULL ;
-- V_2 -> V_52 ;
-- V_2 -> V_29 ;
++ V_2 -> V_67 ;
++ V_16 -> V_51 ;
F_49 ( & V_16 -> V_18 , & V_2 -> V_33 ) ;
if ( V_2 -> V_35 &&
( V_2 -> V_29 <= ( V_2 -> V_36 >> 1 ) ) ) {
V_2 -> V_35 = false ;
F_4 ( V_2 ) ;
}
}
F_18 ( & V_2 -> V_32 ) ;
if ( V_65 )
V_4 -> V_19 ( V_4 -> V_7 , V_65 , & V_66 ) ;
return V_54 ;
}
int F_53 ( struct V_1 * V_2 , T_1 V_9 ,
struct V_56 * * V_20 ,
const struct V_57 * * V_21 )
{
int V_54 = 0 ;
T_2 V_10 , V_6 , V_11 , V_12 ;
struct V_15 * V_16 ;
F_7 ( V_9 , & V_10 , & V_6 ,
& V_11 , & V_12 ) ;
V_16 = & V_2 -> V_50 [ V_12 ] ;
F_17 ( & V_2 -> V_32 ) ;
F_5 ( V_6 != V_2 -> V_6 ) ;
if ( V_10 != V_2 -> V_51 ) {
V_54 = - V_59 ;
} else if ( V_12 >= ( unsigned ) V_2 -> V_36 ) {
F_35 ( 1 ) ;
V_54 = - V_58 ;
} else if ( V_16 -> V_51 != V_11 ) {
F_35 ( 1 ) ;
V_54 = - V_59 ;
} else {
* V_20 = V_16 -> V_20 ;
* V_21 = & V_16 -> V_21 ;
}
F_18 ( & V_2 -> V_32 ) ;
return V_54 ;
}
void F_54 ( struct V_1 * V_2 )
{
F_17 ( & V_2 -> V_32 ) ;
F_1 ( V_2 ) ;
F_18 ( & V_2 -> V_32 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
F_17 ( & V_2 -> V_32 ) ;
F_4 ( V_2 ) ;
F_18 ( & V_2 -> V_32 ) ;
}
bool F_56 ( struct V_1 * V_2 ,
unsigned long * V_68 ,
T_1 V_69 )
{
struct V_15 * V_16 ;
bool V_54 ;
F_17 ( & V_2 -> V_32 ) ;
V_54 = ! F_41 ( & V_2 -> V_47 ) ;
if ( V_54 ) {
F_45 (item, &queue->pending, head) {
if ( V_16 -> V_9 != V_69 )
if ( F_57 ( V_16 -> V_64 ,
* V_68 ) )
* V_68 = V_16 -> V_64 ;
}
}
F_18 ( & V_2 -> V_32 ) ;
return V_54 ;
}
bool F_58 ( struct V_3 * V_4 ,
T_1 V_53 )
{
bool V_70 = true ;
F_17 ( & V_4 -> V_32 ) ;
if ( V_53 == ( T_1 ) - 1 ) {
V_70 = V_4 -> V_29 == 0 ;
} else {
int V_46 ;
for ( V_46 = 0 ; V_46 < V_4 -> V_42 ; ++ V_46 ) {
if ( V_53 & F_46 ( V_46 ) ) {
if ( V_4 -> V_30 [ V_46 ] ) {
V_70 = false ;
break;
}
}
}
}
F_18 ( & V_4 -> V_32 ) ;
return V_70 ;
}
