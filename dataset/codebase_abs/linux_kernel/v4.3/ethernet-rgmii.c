static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
union V_4 V_5 ;
union V_6 V_7 ;
union V_8 V_9 ;
int V_10 = F_2 ( V_2 -> V_11 ) ;
int V_12 = F_3 ( V_2 -> V_11 ) ;
V_5 . V_13 = F_4 ( F_5 ( V_12 ,
V_10 ) ) ;
V_5 . V_14 . V_15 = V_3 ;
F_6 ( F_5 ( V_12 , V_10 ) ,
V_5 . V_13 ) ;
V_7 . V_13 = F_4 ( V_16 ) ;
if ( V_3 )
V_7 . V_14 . V_17 |= 1ull << V_2 -> V_11 ;
else
V_7 . V_14 . V_17 &=
0xffffffffull ^ ( 1ull << V_2 -> V_11 ) ;
F_6 ( V_16 , V_7 . V_13 ) ;
V_9 . V_13 = F_4 ( F_7 ( V_12 ,
V_10 ) ) ;
F_6 ( F_7 ( V_12 , V_10 ) ,
V_9 . V_13 ) ;
}
static void F_8 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
unsigned long V_20 = 0 ;
T_1 V_21 ;
int V_22 = ( V_2 -> V_23 == NULL ) ;
F_10 ( F_11 () ) ;
if ( V_22 ) {
F_12 ( & V_24 , V_20 ) ;
} else {
F_13 ( & V_2 -> V_23 -> V_25 -> V_26 ) ;
}
V_21 = F_14 ( V_2 -> V_11 ) ;
if ( V_21 . V_13 == V_2 -> V_21 ) {
if ( V_21 . V_14 . V_27 == 10 ) {
int V_10 = F_2 ( V_2 -> V_11 ) ;
int V_12 = F_3 ( V_2 -> V_11 ) ;
union V_8 V_9 ;
V_9 . V_13 =
F_4 ( F_7
( V_12 , V_10 ) ) ;
if ( V_9 . V_14 . V_28 ) {
F_1 ( V_2 , false ) ;
F_15 ( L_1 ,
V_19 -> V_29 ) ;
}
}
if ( V_22 )
F_16 ( & V_24 , V_20 ) ;
else
F_17 ( & V_2 -> V_23 -> V_25 -> V_26 ) ;
return;
}
F_1 ( V_2 , true ) ;
if ( V_2 -> V_23 == NULL ) {
V_21 = F_18 ( V_2 -> V_11 ) ;
V_2 -> V_21 = V_21 . V_13 ;
}
if ( V_22 )
F_16 ( & V_24 , V_20 ) ;
else
F_17 ( & V_2 -> V_23 -> V_25 -> V_26 ) ;
if ( V_2 -> V_23 == NULL ) {
if ( V_21 . V_14 . V_30 ) {
if ( ! F_19 ( V_19 ) )
F_20 ( V_19 ) ;
} else if ( F_19 ( V_19 ) ) {
F_21 ( V_19 ) ;
}
F_22 ( V_2 , V_21 ) ;
}
}
static int F_23 ( int V_10 )
{
int V_12 ;
int V_31 = 0 ;
for ( V_12 = 0 ;
V_12 < F_24 ( V_10 ) ;
V_12 ++ ) {
union V_8 V_32 ;
V_32 . V_13 = F_4 ( F_7
( V_12 , V_10 ) ) ;
V_32 . V_13 &= F_4 ( F_25
( V_12 , V_10 ) ) ;
if ( V_32 . V_14 . V_33 || V_32 . V_14 . V_34 ||
V_32 . V_14 . V_35 ) {
struct V_18 * V_19 =
V_36 [ F_26
( V_10 , V_12 ) ] ;
struct V_1 * V_2 = F_9 ( V_19 ) ;
if ( V_19 && ! F_27 ( & V_37 ) )
F_28 ( V_38 ,
& V_2 -> V_39 ) ;
V_32 . V_13 = 0 ;
V_32 . V_14 . V_33 = 1 ;
V_32 . V_14 . V_34 = 1 ;
V_32 . V_14 . V_35 = 1 ;
F_6 ( F_7 ( V_12 , V_10 ) ,
V_32 . V_13 ) ;
V_31 ++ ;
}
}
return V_31 ;
}
static T_2 F_29 ( int V_40 , void * V_41 )
{
union V_42 V_43 ;
int V_31 = 0 ;
V_43 . V_13 = F_4 ( V_44 ) ;
if ( V_43 . V_14 . V_45 )
V_31 += F_23 ( 0 ) ;
if ( V_43 . V_14 . V_46 )
V_31 += F_23 ( 1 ) ;
return V_31 ? V_47 : V_48 ;
}
int F_30 ( struct V_18 * V_19 )
{
return F_31 ( V_19 , F_8 , false ) ;
}
static void F_32 ( struct V_49 * V_50 )
{
struct V_1 * V_2 =
F_33 ( V_50 , struct V_1 , V_39 ) ;
F_8 ( V_36 [ V_2 -> V_11 ] ) ;
}
int F_34 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
int V_51 ;
F_35 ( V_19 ) ;
F_36 ( & V_2 -> V_39 , F_32 ) ;
if ( V_52 == 0 ) {
V_51 = F_37 ( V_53 , F_29 ,
V_54 , L_2 , & V_52 ) ;
if ( V_51 != 0 )
return V_51 ;
}
V_52 ++ ;
if ( ( ( V_2 -> V_55 == V_56 )
&& ( V_2 -> V_11 == 0 ) )
|| ( V_2 -> V_55 == V_57 ) ) {
if ( ! F_38 () ) {
union V_58 V_59 ;
int V_10 = F_2 ( V_2 -> V_11 ) ;
int V_12 = F_3 ( V_2 -> V_11 ) ;
V_59 . V_13 = 0 ;
V_59 . V_14 . V_33 = 1 ;
V_59 . V_14 . V_34 = 1 ;
V_59 . V_14 . V_35 = 1 ;
F_6 ( F_25 ( V_12 , V_10 ) ,
V_59 . V_13 ) ;
}
}
return 0 ;
}
void F_39 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
F_40 ( V_19 ) ;
if ( ( ( V_2 -> V_55 == V_56 )
&& ( V_2 -> V_11 == 0 ) )
|| ( V_2 -> V_55 == V_57 ) ) {
if ( ! F_38 () ) {
union V_58 V_59 ;
int V_10 = F_2 ( V_2 -> V_11 ) ;
int V_12 = F_3 ( V_2 -> V_11 ) ;
V_59 . V_13 =
F_4 ( F_25
( V_12 , V_10 ) ) ;
V_59 . V_14 . V_33 = 0 ;
V_59 . V_14 . V_34 = 0 ;
V_59 . V_14 . V_35 = 0 ;
F_6 ( F_25 ( V_12 , V_10 ) ,
V_59 . V_13 ) ;
}
}
V_52 -- ;
if ( V_52 == 0 )
F_41 ( V_53 , & V_52 ) ;
F_42 ( & V_2 -> V_39 ) ;
}
