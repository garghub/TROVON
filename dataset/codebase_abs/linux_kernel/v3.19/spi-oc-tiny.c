static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 ) ;
}
static unsigned int F_3 ( struct V_2 * V_5 , unsigned int V_6 )
{
struct V_1 * V_7 = F_1 ( V_5 ) ;
return F_4 ( F_5 ( V_7 -> V_8 , V_6 * 2 ) , ( 1U << V_7 -> V_9 ) ) - 1 ;
}
static void F_6 ( struct V_2 * V_5 , int V_10 )
{
struct V_1 * V_7 = F_1 ( V_5 ) ;
if ( V_7 -> V_11 > 0 ) {
F_7 ( V_7 -> V_12 [ V_5 -> V_13 ] ,
( V_5 -> V_14 & V_15 ) ? V_10 : ! V_10 ) ;
}
}
static int F_8 ( struct V_2 * V_5 ,
struct V_16 * V_17 )
{
struct V_1 * V_7 = F_1 ( V_5 ) ;
unsigned int V_18 = V_7 -> V_18 ;
if ( V_17 ) {
if ( V_17 -> V_19 && V_17 -> V_19 != V_7 -> V_19 )
V_18 = F_3 ( V_5 , V_17 -> V_19 ) ;
}
F_9 ( V_18 , V_7 -> V_20 + V_21 ) ;
F_9 ( V_7 -> V_14 , V_7 -> V_20 + V_22 ) ;
return 0 ;
}
static int F_10 ( struct V_2 * V_5 )
{
struct V_1 * V_7 = F_1 ( V_5 ) ;
if ( V_5 -> V_23 != V_7 -> V_19 ) {
V_7 -> V_19 = V_5 -> V_23 ;
V_7 -> V_18 = F_3 ( V_5 , V_7 -> V_19 ) ;
}
V_7 -> V_14 = V_5 -> V_14 & ( V_24 | V_25 ) ;
return 0 ;
}
static inline void F_11 ( struct V_1 * V_7 )
{
while ( ! ( F_12 ( V_7 -> V_20 + V_26 ) &
V_27 ) )
F_13 () ;
}
static inline void F_14 ( struct V_1 * V_7 )
{
while ( ! ( F_12 ( V_7 -> V_20 + V_26 ) &
V_28 ) )
F_13 () ;
}
static int F_15 ( struct V_2 * V_5 , struct V_16 * V_17 )
{
struct V_1 * V_7 = F_1 ( V_5 ) ;
const T_1 * V_29 = V_17 -> V_30 ;
T_1 * V_31 = V_17 -> V_32 ;
unsigned int V_33 ;
if ( V_7 -> V_34 >= 0 ) {
V_7 -> V_35 = V_17 -> V_35 ;
V_7 -> V_29 = V_17 -> V_30 ;
V_7 -> V_31 = V_17 -> V_32 ;
V_7 -> V_36 = 0 ;
V_7 -> V_37 = 0 ;
if ( V_17 -> V_35 > 1 ) {
F_16 ( V_7 -> V_29 ? * V_7 -> V_29 ++ : 0 ,
V_7 -> V_20 + V_38 ) ;
V_7 -> V_36 ++ ;
F_16 ( V_7 -> V_29 ? * V_7 -> V_29 ++ : 0 ,
V_7 -> V_20 + V_38 ) ;
V_7 -> V_36 ++ ;
F_16 ( V_27 , V_7 -> V_20 + V_26 ) ;
} else {
F_16 ( V_7 -> V_29 ? * V_7 -> V_29 ++ : 0 ,
V_7 -> V_20 + V_38 ) ;
V_7 -> V_36 ++ ;
F_16 ( V_28 , V_7 -> V_20 + V_26 ) ;
}
F_17 ( & V_7 -> V_39 ) ;
} else {
F_16 ( V_29 ? * V_29 ++ : 0 , V_7 -> V_20 + V_38 ) ;
for ( V_33 = 1 ; V_33 < V_17 -> V_35 ; V_33 ++ ) {
F_16 ( V_29 ? * V_29 ++ : 0 , V_7 -> V_20 + V_38 ) ;
if ( V_31 || ( V_33 != V_17 -> V_35 - 1 ) )
F_11 ( V_7 ) ;
if ( V_31 )
* V_31 ++ = F_12 ( V_7 -> V_20 + V_38 ) ;
}
F_14 ( V_7 ) ;
if ( V_31 )
* V_31 ++ = F_12 ( V_7 -> V_20 + V_40 ) ;
}
return V_17 -> V_35 ;
}
static T_2 F_18 ( int V_34 , void * V_41 )
{
struct V_1 * V_7 = V_41 ;
F_16 ( 0 , V_7 -> V_20 + V_26 ) ;
if ( V_7 -> V_37 + 1 == V_7 -> V_35 ) {
if ( V_7 -> V_31 )
* V_7 -> V_31 ++ = F_12 ( V_7 -> V_20 + V_40 ) ;
V_7 -> V_37 ++ ;
F_19 ( & V_7 -> V_39 ) ;
} else {
if ( V_7 -> V_31 )
* V_7 -> V_31 ++ = F_12 ( V_7 -> V_20 + V_38 ) ;
V_7 -> V_37 ++ ;
if ( V_7 -> V_36 < V_7 -> V_35 ) {
F_16 ( V_7 -> V_29 ? * V_7 -> V_29 ++ : 0 ,
V_7 -> V_20 + V_38 ) ;
V_7 -> V_36 ++ ;
F_16 ( V_27 ,
V_7 -> V_20 + V_26 ) ;
} else {
F_16 ( V_28 ,
V_7 -> V_20 + V_26 ) ;
}
}
return V_42 ;
}
static int F_20 ( struct V_43 * V_44 )
{
struct V_1 * V_7 = F_21 ( V_44 ) ;
struct V_45 * V_46 = V_44 -> V_41 . V_47 ;
unsigned int V_33 ;
const T_3 * V_48 ;
int V_35 ;
if ( ! V_46 )
return 0 ;
V_7 -> V_11 = F_22 ( V_46 ) ;
if ( V_7 -> V_11 > 0 ) {
V_7 -> V_12 = F_23 ( & V_44 -> V_41 ,
V_7 -> V_11 * sizeof( unsigned int ) ,
V_49 ) ;
if ( ! V_7 -> V_12 )
return - V_50 ;
}
for ( V_33 = 0 ; V_33 < V_7 -> V_11 ; V_33 ++ ) {
V_7 -> V_12 [ V_33 ] = F_24 ( V_46 , V_33 , NULL ) ;
if ( V_7 -> V_12 [ V_33 ] < 0 )
return - V_51 ;
}
V_7 -> V_52 . V_4 -> V_41 . V_47 = V_44 -> V_41 . V_47 ;
V_48 = F_25 ( V_44 -> V_41 . V_47 ,
L_1 , & V_35 ) ;
if ( V_48 && V_35 >= sizeof( T_3 ) )
V_7 -> V_8 = F_26 ( V_48 ) ;
V_48 = F_25 ( V_44 -> V_41 . V_47 , L_2 , & V_35 ) ;
if ( V_48 && V_35 >= sizeof( T_3 ) )
V_7 -> V_9 = F_26 ( V_48 ) ;
return 0 ;
}
static int F_20 ( struct V_43 * V_44 )
{
return 0 ;
}
static int F_27 ( struct V_43 * V_44 )
{
struct V_53 * V_54 = F_28 ( & V_44 -> V_41 ) ;
struct V_1 * V_7 ;
struct V_55 * V_4 ;
struct V_56 * V_57 ;
unsigned int V_33 ;
int V_58 = - V_51 ;
V_4 = F_29 ( & V_44 -> V_41 , sizeof( struct V_1 ) ) ;
if ( ! V_4 )
return V_58 ;
V_4 -> V_59 = V_44 -> V_60 ;
V_4 -> V_61 = 255 ;
V_4 -> V_62 = V_24 | V_25 | V_15 ;
V_4 -> V_63 = F_10 ;
V_7 = F_2 ( V_4 ) ;
F_30 ( V_44 , V_7 ) ;
V_7 -> V_52 . V_4 = V_4 ;
V_7 -> V_52 . V_64 = F_8 ;
V_7 -> V_52 . V_65 = F_6 ;
V_7 -> V_52 . V_66 = F_15 ;
V_57 = F_31 ( V_44 , V_67 , 0 ) ;
V_7 -> V_20 = F_32 ( & V_44 -> V_41 , V_57 ) ;
if ( F_33 ( V_7 -> V_20 ) ) {
V_58 = F_34 ( V_7 -> V_20 ) ;
goto exit;
}
V_7 -> V_34 = F_35 ( V_44 , 0 ) ;
if ( V_7 -> V_34 >= 0 ) {
F_36 ( & V_7 -> V_39 ) ;
V_58 = F_37 ( & V_44 -> V_41 , V_7 -> V_34 , F_18 , 0 ,
V_44 -> V_68 , V_7 ) ;
if ( V_58 )
goto exit;
}
if ( V_54 ) {
V_7 -> V_11 = V_54 -> V_11 ;
V_7 -> V_12 = V_54 -> V_12 ;
if ( V_54 -> V_11 && ! V_54 -> V_12 ) {
V_58 = - V_69 ;
goto exit;
}
V_7 -> V_8 = V_54 -> V_8 ;
V_7 -> V_9 = V_54 -> V_9 ;
} else {
V_58 = F_20 ( V_44 ) ;
if ( V_58 )
goto exit;
}
for ( V_33 = 0 ; V_33 < V_7 -> V_11 ; V_33 ++ ) {
V_58 = F_38 ( V_7 -> V_12 [ V_33 ] , F_39 ( & V_44 -> V_41 ) ) ;
if ( V_58 )
goto V_70;
F_40 ( V_7 -> V_12 [ V_33 ] , 1 ) ;
}
V_7 -> V_52 . V_4 -> V_61 = F_41 ( 1 , V_7 -> V_11 ) ;
V_58 = F_42 ( & V_7 -> V_52 ) ;
if ( V_58 )
goto exit;
F_43 ( & V_44 -> V_41 , L_3 , V_7 -> V_20 , V_7 -> V_34 ) ;
return 0 ;
V_70:
while ( V_33 -- > 0 )
F_44 ( V_7 -> V_12 [ V_33 ] ) ;
exit:
F_45 ( V_4 ) ;
return V_58 ;
}
static int F_46 ( struct V_43 * V_44 )
{
struct V_1 * V_7 = F_21 ( V_44 ) ;
struct V_55 * V_4 = V_7 -> V_52 . V_4 ;
unsigned int V_33 ;
F_47 ( & V_7 -> V_52 ) ;
for ( V_33 = 0 ; V_33 < V_7 -> V_11 ; V_33 ++ )
F_44 ( V_7 -> V_12 [ V_33 ] ) ;
F_45 ( V_4 ) ;
return 0 ;
}
