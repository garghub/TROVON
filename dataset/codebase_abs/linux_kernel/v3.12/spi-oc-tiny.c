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
} else if ( V_29 && V_31 ) {
F_16 ( * V_29 ++ , V_7 -> V_20 + V_38 ) ;
if ( V_17 -> V_35 > 1 ) {
F_16 ( * V_29 ++ , V_7 -> V_20 + V_38 ) ;
for ( V_33 = 2 ; V_33 < V_17 -> V_35 ; V_33 ++ ) {
T_1 V_40 , V_41 = * V_29 ++ ;
F_11 ( V_7 ) ;
V_40 = F_12 ( V_7 -> V_20 + V_38 ) ;
F_16 ( V_41 , V_7 -> V_20 + V_38 ) ;
* V_31 ++ = V_40 ;
}
F_11 ( V_7 ) ;
* V_31 ++ = F_12 ( V_7 -> V_20 + V_38 ) ;
}
F_14 ( V_7 ) ;
* V_31 ++ = F_12 ( V_7 -> V_20 + V_42 ) ;
} else if ( V_31 ) {
F_16 ( 0 , V_7 -> V_20 + V_38 ) ;
if ( V_17 -> V_35 > 1 ) {
F_16 ( 0 ,
V_7 -> V_20 + V_38 ) ;
for ( V_33 = 2 ; V_33 < V_17 -> V_35 ; V_33 ++ ) {
T_1 V_40 ;
F_11 ( V_7 ) ;
V_40 = F_12 ( V_7 -> V_20 + V_38 ) ;
F_16 ( 0 , V_7 -> V_20 + V_38 ) ;
* V_31 ++ = V_40 ;
}
F_11 ( V_7 ) ;
* V_31 ++ = F_12 ( V_7 -> V_20 + V_38 ) ;
}
F_14 ( V_7 ) ;
* V_31 ++ = F_12 ( V_7 -> V_20 + V_42 ) ;
} else if ( V_29 ) {
F_16 ( * V_29 ++ , V_7 -> V_20 + V_38 ) ;
if ( V_17 -> V_35 > 1 ) {
F_16 ( * V_29 ++ , V_7 -> V_20 + V_38 ) ;
for ( V_33 = 2 ; V_33 < V_17 -> V_35 ; V_33 ++ ) {
T_1 V_41 = * V_29 ++ ;
F_11 ( V_7 ) ;
F_16 ( V_41 , V_7 -> V_20 + V_38 ) ;
}
}
F_14 ( V_7 ) ;
} else {
F_16 ( 0 , V_7 -> V_20 + V_38 ) ;
if ( V_17 -> V_35 > 1 ) {
F_16 ( 0 , V_7 -> V_20 + V_38 ) ;
for ( V_33 = 2 ; V_33 < V_17 -> V_35 ; V_33 ++ ) {
F_11 ( V_7 ) ;
F_16 ( 0 , V_7 -> V_20 + V_38 ) ;
}
}
F_14 ( V_7 ) ;
}
return V_17 -> V_35 ;
}
static T_2 F_18 ( int V_34 , void * V_43 )
{
struct V_1 * V_7 = V_43 ;
F_16 ( 0 , V_7 -> V_20 + V_26 ) ;
if ( V_7 -> V_37 + 1 == V_7 -> V_35 ) {
if ( V_7 -> V_31 )
* V_7 -> V_31 ++ = F_12 ( V_7 -> V_20 + V_42 ) ;
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
return V_44 ;
}
static int F_20 ( struct V_45 * V_46 )
{
struct V_1 * V_7 = F_21 ( V_46 ) ;
struct V_47 * V_48 = V_46 -> V_43 . V_49 ;
unsigned int V_33 ;
const T_3 * V_50 ;
int V_35 ;
if ( ! V_48 )
return 0 ;
V_7 -> V_11 = F_22 ( V_48 ) ;
if ( V_7 -> V_11 > 0 ) {
V_7 -> V_12 = F_23 ( & V_46 -> V_43 ,
V_7 -> V_11 * sizeof( unsigned int ) ,
V_51 ) ;
if ( ! V_7 -> V_12 )
return - V_52 ;
}
for ( V_33 = 0 ; V_33 < V_7 -> V_11 ; V_33 ++ ) {
V_7 -> V_12 [ V_33 ] = F_24 ( V_48 , V_33 , NULL ) ;
if ( V_7 -> V_12 [ V_33 ] < 0 )
return - V_53 ;
}
V_7 -> V_54 . V_4 -> V_43 . V_49 = V_46 -> V_43 . V_49 ;
V_50 = F_25 ( V_46 -> V_43 . V_49 ,
L_1 , & V_35 ) ;
if ( V_50 && V_35 >= sizeof( T_3 ) )
V_7 -> V_8 = F_26 ( V_50 ) ;
V_50 = F_25 ( V_46 -> V_43 . V_49 , L_2 , & V_35 ) ;
if ( V_50 && V_35 >= sizeof( T_3 ) )
V_7 -> V_9 = F_26 ( V_50 ) ;
return 0 ;
}
static int F_20 ( struct V_45 * V_46 )
{
return 0 ;
}
static int F_27 ( struct V_45 * V_46 )
{
struct V_55 * V_56 = F_28 ( & V_46 -> V_43 ) ;
struct V_1 * V_7 ;
struct V_57 * V_4 ;
struct V_58 * V_59 ;
unsigned int V_33 ;
int V_60 = - V_53 ;
V_4 = F_29 ( & V_46 -> V_43 , sizeof( struct V_1 ) ) ;
if ( ! V_4 )
return V_60 ;
V_4 -> V_61 = V_46 -> V_62 ;
V_4 -> V_63 = 255 ;
V_4 -> V_64 = V_24 | V_25 | V_15 ;
V_4 -> V_65 = F_10 ;
V_7 = F_2 ( V_4 ) ;
F_30 ( V_46 , V_7 ) ;
V_7 -> V_54 . V_4 = F_31 ( V_4 ) ;
if ( ! V_7 -> V_54 . V_4 )
return V_60 ;
V_7 -> V_54 . V_66 = F_8 ;
V_7 -> V_54 . V_67 = F_6 ;
V_7 -> V_54 . V_68 = F_15 ;
V_59 = F_32 ( V_46 , V_69 , 0 ) ;
V_7 -> V_20 = F_33 ( & V_46 -> V_43 , V_59 ) ;
if ( F_34 ( V_7 -> V_20 ) ) {
V_60 = F_35 ( V_7 -> V_20 ) ;
goto exit;
}
V_7 -> V_34 = F_36 ( V_46 , 0 ) ;
if ( V_7 -> V_34 >= 0 ) {
F_37 ( & V_7 -> V_39 ) ;
V_60 = F_38 ( & V_46 -> V_43 , V_7 -> V_34 , F_18 , 0 ,
V_46 -> V_70 , V_7 ) ;
if ( V_60 )
goto exit;
}
if ( V_56 ) {
V_7 -> V_11 = V_56 -> V_11 ;
V_7 -> V_12 = V_56 -> V_12 ;
if ( V_56 -> V_11 && ! V_56 -> V_12 ) {
V_60 = - V_71 ;
goto exit;
}
V_7 -> V_8 = V_56 -> V_8 ;
V_7 -> V_9 = V_56 -> V_9 ;
} else {
V_60 = F_20 ( V_46 ) ;
if ( V_60 )
goto exit;
}
for ( V_33 = 0 ; V_33 < V_7 -> V_11 ; V_33 ++ ) {
V_60 = F_39 ( V_7 -> V_12 [ V_33 ] , F_40 ( & V_46 -> V_43 ) ) ;
if ( V_60 )
goto V_72;
F_41 ( V_7 -> V_12 [ V_33 ] , 1 ) ;
}
V_7 -> V_54 . V_4 -> V_63 = F_42 ( 1 , V_7 -> V_11 ) ;
V_60 = F_43 ( & V_7 -> V_54 ) ;
if ( V_60 )
goto exit;
F_44 ( & V_46 -> V_43 , L_3 , V_7 -> V_20 , V_7 -> V_34 ) ;
return 0 ;
V_72:
while ( V_33 -- > 0 )
F_45 ( V_7 -> V_12 [ V_33 ] ) ;
exit:
F_46 ( V_4 ) ;
return V_60 ;
}
static int F_47 ( struct V_45 * V_46 )
{
struct V_1 * V_7 = F_21 ( V_46 ) ;
struct V_57 * V_4 = V_7 -> V_54 . V_4 ;
unsigned int V_33 ;
F_48 ( & V_7 -> V_54 ) ;
for ( V_33 = 0 ; V_33 < V_7 -> V_11 ; V_33 ++ )
F_45 ( V_7 -> V_12 [ V_33 ] ) ;
F_46 ( V_4 ) ;
return 0 ;
}
