static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
const struct V_5 * V_6 ,
struct V_7 * V_8 )
{
int V_9 = V_6 -> V_10 & 0xf ;
int V_11 = 0 , V_12 ;
T_1 V_13 = F_2 ( V_3 , V_4 ) ;
T_2 V_14 , V_15 = V_6 -> args [ V_16 ] ;
T_3 V_17 = 0 ;
void * V_18 = NULL ;
T_4 V_19 ;
if ( F_3 ( V_9 > V_20 ) ) {
V_19 = V_21 * sizeof( T_2 ) ;
V_18 = F_4 ( F_5 ( V_19 ) , V_22 ) ;
if ( ! V_18 )
return - V_23 ;
if ( V_24 == V_25 ) {
T_5 * args = V_18 ;
for ( V_12 = 0 ; V_12 < V_21 ; V_12 ++ )
args [ V_12 ] = F_6 ( V_6 -> args [ V_12 +
V_16 ] ) ;
} else {
T_6 * args = V_18 ;
for ( V_12 = 0 ; V_12 < V_21 ; V_12 ++ )
args [ V_12 ] = F_7 ( V_6 -> args [ V_12 +
V_16 ] ) ;
}
V_17 = F_8 ( V_2 , V_18 , V_19 ,
V_26 ) ;
if ( F_9 ( V_2 , V_17 ) ) {
F_10 ( V_18 ) ;
return - V_23 ;
}
V_15 = V_17 ;
}
do {
F_11 ( & V_27 ) ;
V_14 = F_12 ( V_28 ,
V_24 ,
V_29 , V_13 ) ;
do {
F_13 ( V_14 , V_6 -> V_10 , V_6 -> args [ 0 ] ,
V_6 -> args [ 1 ] , V_6 -> args [ 2 ] , V_15 , 0 , 0 ,
V_8 ) ;
} while ( V_8 -> V_30 == V_31 );
F_14 ( & V_27 ) ;
if ( V_8 -> V_30 == V_32 ) {
if ( V_11 ++ > V_33 )
break;
F_15 ( V_34 ) ;
}
} while ( V_8 -> V_30 == V_32 );
if ( V_18 ) {
F_16 ( V_2 , V_17 , V_19 , V_26 ) ;
F_10 ( V_18 ) ;
}
if ( V_8 -> V_30 < 0 )
return F_17 ( V_8 -> V_30 ) ;
return 0 ;
}
int F_18 ( void * V_35 , const T_7 * V_36 )
{
return - V_37 ;
}
int F_19 ( struct V_1 * V_2 , void * V_35 ,
const T_7 * V_36 )
{
return - V_37 ;
}
void F_20 ( T_1 V_38 )
{
}
int F_21 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_39 ;
struct V_5 V_6 = { 0 } ;
struct V_7 V_8 ;
V_6 . V_10 = F_22 ( 1 ) ;
V_6 . args [ 0 ] = F_2 ( V_3 , V_4 ) |
( V_29 << V_40 ) ;
V_39 = F_1 ( V_2 , V_41 , V_42 ,
& V_6 , & V_8 ) ;
return V_39 ? : V_8 . V_43 ;
}
int F_23 ( struct V_1 * V_2 , struct V_44 * V_45 ,
T_1 V_46 , T_1 * V_47 )
{
int V_39 ;
struct V_5 V_6 = { 0 } ;
struct V_7 V_8 ;
if ( V_46 > V_48 )
return - V_49 ;
V_6 . args [ 0 ] = V_45 [ 0 ] . V_50 ;
V_6 . args [ 1 ] = V_45 [ 0 ] . V_51 ;
V_6 . args [ 2 ] = V_45 [ 1 ] . V_50 ;
V_6 . args [ 3 ] = V_45 [ 1 ] . V_51 ;
V_6 . args [ 4 ] = V_45 [ 2 ] . V_50 ;
V_6 . args [ 5 ] = V_45 [ 2 ] . V_51 ;
V_6 . args [ 6 ] = V_45 [ 3 ] . V_50 ;
V_6 . args [ 7 ] = V_45 [ 3 ] . V_51 ;
V_6 . args [ 8 ] = V_45 [ 4 ] . V_50 ;
V_6 . args [ 9 ] = V_45 [ 4 ] . V_51 ;
V_6 . V_10 = F_22 ( 10 ) ;
V_39 = F_1 ( V_2 , V_52 , V_53 , & V_6 ,
& V_8 ) ;
* V_47 = V_8 . V_43 ;
return V_39 ;
}
void F_24 ( void )
{
T_2 V_14 ;
struct V_7 V_8 ;
T_1 V_54 = F_2 ( V_41 , V_42 ) ;
V_14 = F_12 ( V_55 , V_56 ,
V_29 , V_54 ) ;
F_13 ( V_14 , F_22 ( 1 ) , V_14 & ( ~ F_25 ( V_57 ) ) ,
0 , 0 , 0 , 0 , 0 , & V_8 ) ;
if ( ! V_8 . V_30 && V_8 . V_43 )
V_24 = V_56 ;
else
V_24 = V_25 ;
}
bool F_26 ( struct V_1 * V_2 , T_1 V_58 )
{
int V_39 ;
struct V_5 V_6 = { 0 } ;
struct V_7 V_8 ;
V_6 . args [ 0 ] = V_58 ;
V_6 . V_10 = F_22 ( 1 ) ;
V_39 = F_1 ( V_2 , V_59 ,
V_60 ,
& V_6 , & V_8 ) ;
return V_39 ? false : ! ! V_8 . V_43 ;
}
int F_27 ( struct V_1 * V_2 , T_1 V_58 ,
T_3 V_61 )
{
int V_39 ;
struct V_5 V_6 = { 0 } ;
struct V_7 V_8 ;
V_6 . args [ 0 ] = V_58 ;
V_6 . args [ 1 ] = V_61 ;
V_6 . V_10 = F_22 ( 2 , V_62 , V_63 ) ;
V_39 = F_1 ( V_2 , V_59 , V_64 ,
& V_6 , & V_8 ) ;
return V_39 ? : V_8 . V_43 ;
}
int F_28 ( struct V_1 * V_2 , T_1 V_58 ,
T_8 V_50 , T_8 V_65 )
{
int V_39 ;
struct V_5 V_6 = { 0 } ;
struct V_7 V_8 ;
V_6 . args [ 0 ] = V_58 ;
V_6 . args [ 1 ] = V_50 ;
V_6 . args [ 2 ] = V_65 ;
V_6 . V_10 = F_22 ( 3 ) ;
V_39 = F_1 ( V_2 , V_59 , V_66 ,
& V_6 , & V_8 ) ;
return V_39 ? : V_8 . V_43 ;
}
int F_29 ( struct V_1 * V_2 , T_1 V_58 )
{
int V_39 ;
struct V_5 V_6 = { 0 } ;
struct V_7 V_8 ;
V_6 . args [ 0 ] = V_58 ;
V_6 . V_10 = F_22 ( 1 ) ;
V_39 = F_1 ( V_2 , V_59 ,
V_67 ,
& V_6 , & V_8 ) ;
return V_39 ? : V_8 . V_43 ;
}
int F_30 ( struct V_1 * V_2 , T_1 V_58 )
{
int V_39 ;
struct V_5 V_6 = { 0 } ;
struct V_7 V_8 ;
V_6 . args [ 0 ] = V_58 ;
V_6 . V_10 = F_22 ( 1 ) ;
V_39 = F_1 ( V_2 , V_59 , V_68 ,
& V_6 , & V_8 ) ;
return V_39 ? : V_8 . V_43 ;
}
int F_31 ( struct V_1 * V_2 , bool V_69 )
{
struct V_5 V_6 = { 0 } ;
struct V_7 V_8 ;
int V_39 ;
V_6 . args [ 0 ] = V_69 ;
V_6 . args [ 1 ] = 0 ;
V_6 . V_10 = F_22 ( 2 ) ;
V_39 = F_1 ( V_2 , V_59 , V_70 , & V_6 ,
& V_8 ) ;
return V_39 ? : V_8 . V_43 ;
}
