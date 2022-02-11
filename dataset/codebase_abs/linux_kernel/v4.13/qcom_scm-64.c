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
struct V_20 V_21 = { . V_22 = V_23 } ;
if ( F_3 ( V_9 > V_24 ) ) {
V_19 = V_25 * sizeof( T_2 ) ;
V_18 = F_4 ( F_5 ( V_19 ) , V_26 ) ;
if ( ! V_18 )
return - V_27 ;
if ( V_28 == V_29 ) {
T_5 * args = V_18 ;
for ( V_12 = 0 ; V_12 < V_25 ; V_12 ++ )
args [ V_12 ] = F_6 ( V_6 -> args [ V_12 +
V_16 ] ) ;
} else {
T_6 * args = V_18 ;
for ( V_12 = 0 ; V_12 < V_25 ; V_12 ++ )
args [ V_12 ] = F_7 ( V_6 -> args [ V_12 +
V_16 ] ) ;
}
V_17 = F_8 ( V_2 , V_18 , V_19 ,
V_30 ) ;
if ( F_9 ( V_2 , V_17 ) ) {
F_10 ( V_18 ) ;
return - V_27 ;
}
V_15 = V_17 ;
}
do {
F_11 ( & V_31 ) ;
V_14 = F_12 ( V_32 ,
V_28 ,
V_33 , V_13 ) ;
V_21 . V_34 . V_35 = 0 ;
do {
F_13 ( V_14 , V_6 -> V_10 , V_6 -> args [ 0 ] ,
V_6 -> args [ 1 ] , V_6 -> args [ 2 ] , V_15 ,
V_21 . V_34 . V_35 , 0 , V_8 , & V_21 ) ;
if ( V_8 -> V_36 == V_37 )
V_14 = V_8 -> V_36 ;
} while ( V_8 -> V_36 == V_37 );
F_14 ( & V_31 ) ;
if ( V_8 -> V_36 == V_38 ) {
if ( V_11 ++ > V_39 )
break;
F_15 ( V_40 ) ;
}
} while ( V_8 -> V_36 == V_38 );
if ( V_18 ) {
F_16 ( V_2 , V_17 , V_19 , V_30 ) ;
F_10 ( V_18 ) ;
}
if ( V_8 -> V_36 < 0 )
return F_17 ( V_8 -> V_36 ) ;
return 0 ;
}
int F_18 ( void * V_41 , const T_7 * V_42 )
{
return - V_43 ;
}
int F_19 ( struct V_1 * V_2 , void * V_41 ,
const T_7 * V_42 )
{
return - V_43 ;
}
void F_20 ( T_1 V_44 )
{
}
int F_21 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_45 ;
struct V_5 V_6 = { 0 } ;
struct V_7 V_8 ;
V_6 . V_10 = F_22 ( 1 ) ;
V_6 . args [ 0 ] = F_2 ( V_3 , V_4 ) |
( V_33 << V_46 ) ;
V_45 = F_1 ( V_2 , V_47 , V_48 ,
& V_6 , & V_8 ) ;
return V_45 ? : V_8 . V_49 ;
}
int F_23 ( struct V_1 * V_2 , struct V_50 * V_51 ,
T_1 V_52 , T_1 * V_53 )
{
int V_45 ;
struct V_5 V_6 = { 0 } ;
struct V_7 V_8 ;
if ( V_52 > V_54 )
return - V_55 ;
V_6 . args [ 0 ] = V_51 [ 0 ] . V_56 ;
V_6 . args [ 1 ] = V_51 [ 0 ] . V_57 ;
V_6 . args [ 2 ] = V_51 [ 1 ] . V_56 ;
V_6 . args [ 3 ] = V_51 [ 1 ] . V_57 ;
V_6 . args [ 4 ] = V_51 [ 2 ] . V_56 ;
V_6 . args [ 5 ] = V_51 [ 2 ] . V_57 ;
V_6 . args [ 6 ] = V_51 [ 3 ] . V_56 ;
V_6 . args [ 7 ] = V_51 [ 3 ] . V_57 ;
V_6 . args [ 8 ] = V_51 [ 4 ] . V_56 ;
V_6 . args [ 9 ] = V_51 [ 4 ] . V_57 ;
V_6 . V_10 = F_22 ( 10 ) ;
V_45 = F_1 ( V_2 , V_58 , V_59 , & V_6 ,
& V_8 ) ;
* V_53 = V_8 . V_49 ;
return V_45 ;
}
void F_24 ( void )
{
T_2 V_14 ;
struct V_7 V_8 ;
T_1 V_60 = F_2 ( V_47 , V_48 ) ;
V_14 = F_12 ( V_61 , V_62 ,
V_33 , V_60 ) ;
F_25 ( V_14 , F_22 ( 1 ) , V_14 & ( ~ F_26 ( V_63 ) ) ,
0 , 0 , 0 , 0 , 0 , & V_8 ) ;
if ( ! V_8 . V_36 && V_8 . V_49 )
V_28 = V_62 ;
else
V_28 = V_29 ;
}
bool F_27 ( struct V_1 * V_2 , T_1 V_64 )
{
int V_45 ;
struct V_5 V_6 = { 0 } ;
struct V_7 V_8 ;
V_6 . args [ 0 ] = V_64 ;
V_6 . V_10 = F_22 ( 1 ) ;
V_45 = F_1 ( V_2 , V_65 ,
V_66 ,
& V_6 , & V_8 ) ;
return V_45 ? false : ! ! V_8 . V_49 ;
}
int F_28 ( struct V_1 * V_2 , T_1 V_64 ,
T_3 V_67 )
{
int V_45 ;
struct V_5 V_6 = { 0 } ;
struct V_7 V_8 ;
V_6 . args [ 0 ] = V_64 ;
V_6 . args [ 1 ] = V_67 ;
V_6 . V_10 = F_22 ( 2 , V_68 , V_69 ) ;
V_45 = F_1 ( V_2 , V_65 , V_70 ,
& V_6 , & V_8 ) ;
return V_45 ? : V_8 . V_49 ;
}
int F_29 ( struct V_1 * V_2 , T_1 V_64 ,
T_8 V_56 , T_8 V_71 )
{
int V_45 ;
struct V_5 V_6 = { 0 } ;
struct V_7 V_8 ;
V_6 . args [ 0 ] = V_64 ;
V_6 . args [ 1 ] = V_56 ;
V_6 . args [ 2 ] = V_71 ;
V_6 . V_10 = F_22 ( 3 ) ;
V_45 = F_1 ( V_2 , V_65 , V_72 ,
& V_6 , & V_8 ) ;
return V_45 ? : V_8 . V_49 ;
}
int F_30 ( struct V_1 * V_2 , T_1 V_64 )
{
int V_45 ;
struct V_5 V_6 = { 0 } ;
struct V_7 V_8 ;
V_6 . args [ 0 ] = V_64 ;
V_6 . V_10 = F_22 ( 1 ) ;
V_45 = F_1 ( V_2 , V_65 ,
V_73 ,
& V_6 , & V_8 ) ;
return V_45 ? : V_8 . V_49 ;
}
int F_31 ( struct V_1 * V_2 , T_1 V_64 )
{
int V_45 ;
struct V_5 V_6 = { 0 } ;
struct V_7 V_8 ;
V_6 . args [ 0 ] = V_64 ;
V_6 . V_10 = F_22 ( 1 ) ;
V_45 = F_1 ( V_2 , V_65 , V_74 ,
& V_6 , & V_8 ) ;
return V_45 ? : V_8 . V_49 ;
}
int F_32 ( struct V_1 * V_2 , bool V_75 )
{
struct V_5 V_6 = { 0 } ;
struct V_7 V_8 ;
int V_45 ;
V_6 . args [ 0 ] = V_75 ;
V_6 . args [ 1 ] = 0 ;
V_6 . V_10 = F_22 ( 2 ) ;
V_45 = F_1 ( V_2 , V_65 , V_76 , & V_6 ,
& V_8 ) ;
return V_45 ? : V_8 . V_49 ;
}
int F_33 ( struct V_1 * V_2 , T_1 V_34 , T_1 V_22 )
{
struct V_5 V_6 = { 0 } ;
struct V_7 V_8 ;
int V_45 ;
V_6 . args [ 0 ] = V_34 ;
V_6 . args [ 1 ] = V_22 ;
V_6 . V_10 = F_22 ( 2 ) ;
V_45 = F_1 ( V_2 , V_77 , V_78 ,
& V_6 , & V_8 ) ;
return V_45 ? : V_8 . V_49 ;
}
int F_34 ( struct V_1 * V_2 , T_1 V_79 , T_1 V_80 )
{
struct V_5 V_6 = { 0 } ;
struct V_7 V_8 ;
int V_45 ;
V_6 . args [ 0 ] = V_79 ;
V_6 . args [ 1 ] = V_80 ;
V_6 . V_10 = F_22 ( 2 ) ;
V_45 = F_1 ( V_2 , V_81 , V_82 ,
& V_6 , & V_8 ) ;
return V_45 ? : V_8 . V_49 ;
}
int F_35 ( struct V_1 * V_2 , T_1 V_80 ,
T_4 * V_71 )
{
struct V_5 V_6 = { 0 } ;
struct V_7 V_8 ;
int V_45 ;
V_6 . args [ 0 ] = V_80 ;
V_6 . V_10 = F_22 ( 1 ) ;
V_45 = F_1 ( V_2 , V_81 ,
V_83 , & V_6 , & V_8 ) ;
if ( V_71 )
* V_71 = V_8 . V_49 ;
return V_45 ? : V_8 . V_84 ;
}
int F_36 ( struct V_1 * V_2 , T_2 V_56 , T_1 V_71 ,
T_1 V_80 )
{
struct V_5 V_6 = { 0 } ;
struct V_7 V_8 ;
int V_45 ;
V_6 . args [ 0 ] = V_56 ;
V_6 . args [ 1 ] = V_71 ;
V_6 . args [ 2 ] = V_80 ;
V_6 . V_10 = F_22 ( 3 , V_69 , V_68 ,
V_68 ) ;
V_45 = F_1 ( V_2 , V_81 ,
V_85 , & V_6 , & V_8 ) ;
if ( V_45 == - V_86 )
V_45 = 0 ;
return V_45 ;
}
