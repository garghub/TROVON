struct V_1 * F_1 ( T_1 V_2 )
{
struct V_1 * V_3 ;
#ifdef F_2
T_1 V_4 ;
#endif
F_3 ( V_5 ) ;
V_3 = F_4 ( V_6 ) ;
if ( ! V_3 ) {
F_5 ( NULL ) ;
}
F_6 ( V_7 -> V_8 ++ ) ;
#ifdef F_2
V_4 = V_7 -> V_8 -
V_7 -> V_9 ;
if ( V_4 > V_7 -> V_10 ) {
V_7 -> V_10 = V_4 ;
}
#endif
V_3 -> V_2 . integer = V_2 ;
F_7 ( V_3 , V_11 ) ;
F_5 ( V_3 ) ;
}
void F_8 ( struct V_1 * V_3 )
{
union V_12 * V_13 ;
F_9 ( V_14 ) ;
F_10 ( V_3 ) ;
V_13 = V_3 -> V_15 ;
if ( V_13 && ( V_13 -> V_16 . type == V_17 ) ) {
if ( V_13 -> V_18 . V_19 ) {
V_13 -> V_18 . V_19 ( V_3 , V_13 -> V_18 . V_20 ) ;
}
F_11 ( V_13 ) ;
}
( void ) F_12 ( V_6 , V_3 ) ;
F_6 ( V_7 -> V_9 ++ ) ;
F_13 ( ( V_21 , L_1 ,
V_3 , V_22 ) ) ;
}
void F_14 ( struct V_1 * V_3 )
{
struct V_1 * V_23 ;
struct V_1 * V_24 ;
struct V_1 * V_25 ;
F_15 ( V_26 , V_3 ) ;
V_23 = V_3 -> V_27 ;
V_24 = NULL ;
V_25 = V_23 -> V_28 ;
while ( V_25 != V_3 ) {
V_24 = V_25 ;
V_25 = V_25 -> V_29 ;
}
if ( V_24 ) {
V_24 -> V_29 = V_3 -> V_29 ;
} else {
V_23 -> V_28 = V_3 -> V_29 ;
}
F_8 ( V_3 ) ;
V_30 ;
}
void F_16 ( struct V_31 * V_32 , struct V_1 * V_23 ,
struct V_1 * V_3 ,
T_2 type )
{
T_3 V_33 = 0 ;
struct V_1 * V_34 ;
F_3 ( V_35 ) ;
if ( V_32 ) {
V_33 = V_32 -> V_33 ;
if ( ( V_32 -> V_36 ) &&
( V_23 != V_32 -> V_37 ) ) {
V_32 -> V_36 -> V_38 . V_39 |=
V_40 ;
}
}
V_3 -> V_29 = NULL ;
V_3 -> V_27 = V_23 ;
V_34 = V_23 -> V_28 ;
if ( ! V_34 ) {
V_23 -> V_28 = V_3 ;
} else {
while ( V_34 -> V_29 ) {
V_34 = V_34 -> V_29 ;
}
V_34 -> V_29 = V_3 ;
}
V_3 -> V_33 = V_33 ;
V_3 -> type = ( V_41 ) type ;
F_13 ( ( V_42 ,
L_2 ,
F_17 ( V_3 ) ,
F_18 ( V_3 -> type ) , V_3 , V_33 ,
F_17 ( V_23 ) ,
F_18 ( V_23 -> type ) ,
V_23 ) ) ;
V_30 ;
}
void F_19 ( struct V_1 * V_23 )
{
struct V_1 * V_25 ;
struct V_1 * V_43 ;
F_15 ( V_44 , V_23 ) ;
if ( ! V_23 ) {
V_30 ;
}
V_25 = V_23 -> V_28 ;
while ( V_25 ) {
if ( V_25 -> V_28 ) {
F_20 ( ( V_45 , L_3 ,
V_23 , V_25 ) ) ;
}
V_43 = V_25 ;
V_25 = V_25 -> V_29 ;
F_8 ( V_43 ) ;
} ;
V_23 -> V_28 = NULL ;
V_30 ;
}
void F_21 ( struct V_1 * V_23 )
{
struct V_1 * V_34 = NULL ;
T_1 V_46 = 1 ;
T_4 V_47 ;
F_3 ( V_48 ) ;
if ( ! V_23 ) {
V_30 ;
}
V_47 = F_22 ( V_49 ) ;
if ( F_23 ( V_47 ) ) {
V_30 ;
}
while ( V_46 > 0 ) {
V_34 = F_24 ( V_23 , V_34 ) ;
if ( V_34 ) {
F_10 ( V_34 ) ;
if ( V_34 -> V_28 ) {
V_46 ++ ;
V_23 = V_34 ;
V_34 = NULL ;
}
} else {
V_46 -- ;
F_19 ( V_23 ) ;
V_34 = V_23 ;
V_23 = V_23 -> V_27 ;
}
}
( void ) F_25 ( V_49 ) ;
V_30 ;
}
void F_26 ( T_3 V_33 )
{
struct V_1 * V_34 ;
struct V_1 * V_50 ;
struct V_1 * V_23 ;
T_1 V_46 ;
T_4 V_47 ;
F_27 ( V_51 , V_33 ) ;
if ( V_33 == 0 ) {
V_30 ;
}
V_47 = F_22 ( V_49 ) ;
if ( F_23 ( V_47 ) ) {
V_30 ;
}
V_50 = NULL ;
V_23 = V_52 ;
V_34 = NULL ;
V_46 = 1 ;
while ( V_46 > 0 ) {
V_34 = F_24 ( V_23 , V_34 ) ;
if ( V_50 ) {
F_19 ( V_50 ) ;
F_14 ( V_50 ) ;
V_50 = NULL ;
}
if ( V_34 ) {
if ( V_34 -> V_33 == V_33 ) {
F_10 ( V_34 ) ;
}
if ( V_34 -> V_28 ) {
V_46 ++ ;
V_23 = V_34 ;
V_34 = NULL ;
} else if ( V_34 -> V_33 == V_33 ) {
V_50 = V_34 ;
}
} else {
V_46 -- ;
if ( V_46 != 0 ) {
if ( V_23 -> V_33 == V_33 ) {
V_50 = V_23 ;
}
}
V_34 = V_23 ;
V_23 = V_23 -> V_27 ;
}
}
( void ) F_25 ( V_49 ) ;
V_30 ;
}
