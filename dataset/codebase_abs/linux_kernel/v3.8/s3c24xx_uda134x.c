static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
#ifdef F_2
struct V_4 * V_5 = V_2 -> V_5 ;
#endif
F_3 ( & V_6 ) ;
F_4 ( L_1 , V_7 , V_8 ) ;
if ( V_8 == 0 ) {
V_9 = F_5 ( & V_10 -> V_11 , L_2 ) ;
if ( F_6 ( V_9 ) ) {
F_7 ( V_12 L_3 , V_7 ) ;
V_3 = F_8 ( V_9 ) ;
} else {
V_13 = F_5 ( & V_10 -> V_11 ,
L_4 ) ;
if ( F_6 ( V_13 ) ) {
F_7 ( V_12 L_5 ,
V_7 ) ;
F_9 ( V_9 ) ;
V_3 = F_8 ( V_13 ) ;
}
}
if ( ! V_3 ) {
int V_14 , V_15 ;
for ( V_14 = 0 ; V_14 < 2 ; V_14 ++ ) {
int V_16 = V_14 ? 256 : 384 ;
V_17 [ V_14 * 33 ] = F_10 ( V_9 ) / V_16 ;
for ( V_15 = 1 ; V_15 < 33 ; V_15 ++ )
V_17 [ V_14 * 33 + V_15 ] = F_10 ( V_13 ) /
( V_15 * V_16 ) ;
}
}
}
V_8 += 1 ;
F_11 ( & V_6 ) ;
if ( ! V_3 ) {
#ifdef F_2
V_3 = F_12 ( V_5 , 0 ,
V_18 ,
& V_19 ) ;
if ( V_3 < 0 )
F_7 ( V_12 L_6 ,
V_7 ) ;
#endif
}
return V_3 ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_3 ( & V_6 ) ;
F_4 ( L_1 , V_7 , V_8 ) ;
V_8 -= 1 ;
if ( V_8 == 0 ) {
F_9 ( V_9 ) ;
V_9 = NULL ;
F_9 ( V_13 ) ;
V_13 = NULL ;
}
F_11 ( & V_6 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = V_2 -> V_24 ;
struct V_25 * V_26 = V_23 -> V_26 ;
struct V_25 * V_27 = V_23 -> V_27 ;
unsigned int V_28 = 0 ;
int V_3 = 0 ;
int V_29 , V_30 ;
unsigned long V_31 = F_15 ( V_21 ) ;
long V_32 , V_33 ;
unsigned int div ;
int V_14 , V_34 ;
V_32 = 999999 ;
V_34 = 0 ;
for ( V_14 = 0 ; V_14 < 2 * 33 ; V_14 ++ ) {
V_33 = V_17 [ V_14 ] - V_31 ;
if ( V_33 < 0 )
V_33 = - V_33 ;
if ( V_33 < V_32 ) {
V_32 = V_33 ;
V_34 = V_14 ;
}
}
if ( V_34 / 33 == 1 )
V_30 = V_35 ;
else
V_30 = V_36 ;
if ( V_34 % 33 == 0 ) {
V_29 = V_37 ;
div = 1 ;
} else {
V_29 = V_38 ;
div = V_34 % 33 ;
}
F_4 ( L_7 , V_7 , V_31 , V_34 ) ;
V_28 = ( V_30 == V_36 ? 384 : 256 ) * V_31 ;
F_4 ( L_8 , V_7 ,
V_30 == V_36 ? L_9 : L_10 ,
V_29 == V_37 ? L_11 : L_12 ,
div , V_28 , V_32 ) ;
if ( ( V_32 * 100 / V_31 ) > 5 ) {
F_7 ( V_12 L_13
L_14 ,
V_32 * 100 / V_31 ) ;
return - V_39 ;
}
V_3 = F_16 ( V_26 , V_40 |
V_41 | V_42 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_16 ( V_27 , V_40 |
V_41 | V_42 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_17 ( V_27 , V_29 , V_28 ,
V_43 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_18 ( V_27 , V_44 , V_30 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_18 ( V_27 , V_45 ,
V_46 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_18 ( V_27 , V_47 ,
F_19 ( div , div ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_17 ( V_26 , 0 , V_28 ,
V_48 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static void F_20 ( int V_49 )
{
F_21 ( V_50 -> V_51 , V_49 > 0 ) ;
}
static void F_22 ( int V_49 )
{
F_21 ( V_50 -> V_52 , V_49 > 0 ) ;
}
static void F_23 ( int V_49 )
{
F_21 ( V_50 -> V_53 , V_49 > 0 ) ;
}
static int F_24 ( int V_54 , char * V_55 )
{
if ( F_25 ( V_54 , L_15 ) < 0 ) {
F_7 ( V_12 L_16
L_17 , V_55 ) ;
return - V_56 ;
}
F_26 ( V_54 , 0 ) ;
return 0 ;
}
static int F_27 ( struct V_57 * V_58 )
{
int V_3 ;
F_7 ( V_59 L_18 ) ;
V_50 = V_58 -> V_11 . V_60 ;
if ( V_50 == NULL ) {
F_7 ( V_12 L_16
L_19 ) ;
return - V_61 ;
}
V_62 . V_63 = V_50 -> V_63 ;
V_62 . V_64 = V_50 -> V_64 ;
if ( F_24 ( V_50 -> V_51 ,
L_20 ) < 0 )
return - V_56 ;
if ( F_24 ( V_50 -> V_52 ,
L_21 ) < 0 ) {
F_28 ( V_50 -> V_51 ) ;
return - V_56 ;
}
if ( F_24 ( V_50 -> V_53 ,
L_22 ) < 0 ) {
F_28 ( V_50 -> V_51 ) ;
F_28 ( V_50 -> V_52 ) ;
return - V_56 ;
}
V_10 = F_29 ( L_23 , - 1 ) ;
if ( ! V_10 ) {
F_7 ( V_12 L_16
L_24 ) ;
return - V_65 ;
}
F_30 ( V_10 ,
& V_66 ) ;
F_31 ( V_10 , & V_62 , sizeof( V_62 ) ) ;
V_3 = F_32 ( V_10 ) ;
if ( V_3 ) {
F_7 ( V_12 L_25 ) ;
F_33 ( V_10 ) ;
}
return V_3 ;
}
static int F_34 ( struct V_57 * V_58 )
{
F_35 ( V_10 ) ;
F_28 ( V_50 -> V_51 ) ;
F_28 ( V_50 -> V_52 ) ;
F_28 ( V_50 -> V_53 ) ;
return 0 ;
}
