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
union V_12 * V_14 ;
F_9 ( V_15 ) ;
F_10 ( V_3 ) ;
V_13 = V_3 -> V_16 ;
while ( V_13 && ( V_13 -> V_17 . type == V_18 ) ) {
if ( V_13 -> V_19 . V_20 ) {
V_13 -> V_19 . V_20 ( V_3 , V_13 -> V_19 . V_21 ) ;
}
V_14 = V_13 -> V_17 . V_22 ;
F_11 ( V_13 ) ;
V_13 = V_14 ;
}
if ( V_3 == V_23 ) {
return;
}
( void ) F_12 ( V_6 , V_3 ) ;
F_6 ( V_7 -> V_9 ++ ) ;
F_13 ( ( V_24 , L_1 ,
V_3 , V_25 ) ) ;
}
void F_14 ( struct V_1 * V_3 )
{
struct V_1 * V_26 ;
struct V_1 * V_27 ;
struct V_1 * V_28 ;
F_15 ( V_29 , V_3 ) ;
V_26 = V_3 -> V_30 ;
V_27 = NULL ;
V_28 = V_26 -> V_31 ;
while ( V_28 != V_3 ) {
V_27 = V_28 ;
V_28 = V_28 -> V_32 ;
}
if ( V_27 ) {
V_27 -> V_32 = V_3 -> V_32 ;
} else {
V_26 -> V_31 = V_3 -> V_32 ;
}
F_8 ( V_3 ) ;
V_33 ;
}
void F_16 ( struct V_34 * V_35 , struct V_1 * V_26 ,
struct V_1 * V_3 ,
T_2 type )
{
T_3 V_36 = 0 ;
struct V_1 * V_37 ;
F_3 ( V_38 ) ;
if ( V_35 ) {
V_36 = V_35 -> V_36 ;
if ( ( V_35 -> V_39 ) &&
( V_26 != V_35 -> V_40 ) ) {
V_35 -> V_39 -> V_41 . V_42 |=
V_43 ;
}
}
V_3 -> V_32 = NULL ;
V_3 -> V_30 = V_26 ;
V_37 = V_26 -> V_31 ;
if ( ! V_37 ) {
V_26 -> V_31 = V_3 ;
} else {
while ( V_37 -> V_32 ) {
V_37 = V_37 -> V_32 ;
}
V_37 -> V_32 = V_3 ;
}
V_3 -> V_36 = V_36 ;
V_3 -> type = ( V_44 ) type ;
F_13 ( ( V_45 ,
L_2 ,
F_17 ( V_3 ) ,
F_18 ( V_3 -> type ) , V_3 , V_36 ,
F_17 ( V_26 ) ,
F_18 ( V_26 -> type ) ,
V_26 ) ) ;
V_33 ;
}
void F_19 ( struct V_1 * V_26 )
{
struct V_1 * V_28 ;
struct V_1 * V_46 ;
F_15 ( V_47 , V_26 ) ;
if ( ! V_26 ) {
V_33 ;
}
V_28 = V_26 -> V_31 ;
while ( V_28 ) {
if ( V_28 -> V_31 ) {
F_20 ( ( V_48 , L_3 ,
V_26 , V_28 ) ) ;
}
V_46 = V_28 ;
V_28 = V_28 -> V_32 ;
F_8 ( V_46 ) ;
} ;
V_26 -> V_31 = NULL ;
V_33 ;
}
void F_21 ( struct V_1 * V_26 )
{
struct V_1 * V_37 = NULL ;
T_1 V_49 = 1 ;
T_4 V_50 ;
F_3 ( V_51 ) ;
if ( ! V_26 ) {
V_33 ;
}
V_50 = F_22 ( V_52 ) ;
if ( F_23 ( V_50 ) ) {
V_33 ;
}
while ( V_49 > 0 ) {
V_37 = F_24 ( V_26 , V_37 ) ;
if ( V_37 ) {
F_10 ( V_37 ) ;
if ( V_37 -> V_31 ) {
V_49 ++ ;
V_26 = V_37 ;
V_37 = NULL ;
}
} else {
V_49 -- ;
F_19 ( V_26 ) ;
V_37 = V_26 ;
V_26 = V_26 -> V_30 ;
}
}
( void ) F_25 ( V_52 ) ;
V_33 ;
}
void F_26 ( T_3 V_36 )
{
struct V_1 * V_37 ;
struct V_1 * V_53 ;
struct V_1 * V_26 ;
T_1 V_49 ;
T_4 V_50 ;
F_27 ( V_54 , V_36 ) ;
if ( V_36 == 0 ) {
V_33 ;
}
V_50 = F_22 ( V_52 ) ;
if ( F_23 ( V_50 ) ) {
V_33 ;
}
V_53 = NULL ;
V_26 = V_23 ;
V_37 = NULL ;
V_49 = 1 ;
while ( V_49 > 0 ) {
V_37 = F_24 ( V_26 , V_37 ) ;
if ( V_53 ) {
F_19 ( V_53 ) ;
F_14 ( V_53 ) ;
V_53 = NULL ;
}
if ( V_37 ) {
if ( V_37 -> V_36 == V_36 ) {
F_10 ( V_37 ) ;
}
if ( V_37 -> V_31 ) {
V_49 ++ ;
V_26 = V_37 ;
V_37 = NULL ;
} else if ( V_37 -> V_36 == V_36 ) {
V_53 = V_37 ;
}
} else {
V_49 -- ;
if ( V_49 != 0 ) {
if ( V_26 -> V_36 == V_36 ) {
V_53 = V_26 ;
}
}
V_37 = V_26 ;
V_26 = V_26 -> V_30 ;
}
}
( void ) F_25 ( V_52 ) ;
V_33 ;
}
