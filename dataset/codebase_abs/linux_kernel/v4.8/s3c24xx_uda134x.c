static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
#ifdef F_2
struct V_8 * V_9 = V_2 -> V_9 ;
#endif
int V_10 = 0 ;
F_3 ( & V_11 ) ;
F_4 ( L_1 , V_12 , V_13 ) ;
if ( V_13 == 0 ) {
V_14 = F_5 ( & V_15 -> V_16 , L_2 ) ;
if ( F_6 ( V_14 ) ) {
F_7 ( V_17 L_3 , V_12 ) ;
V_10 = F_8 ( V_14 ) ;
} else {
V_18 = F_5 ( V_7 -> V_16 , L_4 ) ;
if ( F_6 ( V_18 ) ) {
F_7 ( V_17 L_5 ,
V_12 ) ;
F_9 ( V_14 ) ;
V_10 = F_8 ( V_18 ) ;
}
}
if ( ! V_10 ) {
int V_19 , V_20 ;
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
int V_21 = V_19 ? 256 : 384 ;
V_22 [ V_19 * 33 ] = F_10 ( V_14 ) / V_21 ;
for ( V_20 = 1 ; V_20 < 33 ; V_20 ++ )
V_22 [ V_19 * 33 + V_20 ] = F_10 ( V_18 ) /
( V_20 * V_21 ) ;
}
}
}
V_13 += 1 ;
F_11 ( & V_11 ) ;
if ( ! V_10 ) {
#ifdef F_2
V_10 = F_12 ( V_9 , 0 ,
V_23 ,
& V_24 ) ;
if ( V_10 < 0 )
F_7 ( V_17 L_6 ,
V_12 ) ;
#endif
}
return V_10 ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_3 ( & V_11 ) ;
F_4 ( L_1 , V_12 , V_13 ) ;
V_13 -= 1 ;
if ( V_13 == 0 ) {
F_9 ( V_14 ) ;
V_14 = NULL ;
F_9 ( V_18 ) ;
V_18 = NULL ;
}
F_11 ( & V_11 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_27 = V_4 -> V_27 ;
struct V_6 * V_7 = V_4 -> V_7 ;
unsigned int V_28 = 0 ;
int V_10 = 0 ;
int V_29 , V_30 ;
unsigned long V_31 = F_15 ( V_26 ) ;
long V_32 , V_33 ;
unsigned int div ;
int V_19 , V_34 ;
V_32 = 999999 ;
V_34 = 0 ;
for ( V_19 = 0 ; V_19 < 2 * 33 ; V_19 ++ ) {
V_33 = V_22 [ V_19 ] - V_31 ;
if ( V_33 < 0 )
V_33 = - V_33 ;
if ( V_33 < V_32 ) {
V_32 = V_33 ;
V_34 = V_19 ;
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
F_4 ( L_7 , V_12 , V_31 , V_34 ) ;
V_28 = ( V_30 == V_36 ? 384 : 256 ) * V_31 ;
F_4 ( L_8 , V_12 ,
V_30 == V_36 ? L_9 : L_10 ,
V_29 == V_37 ? L_11 : L_12 ,
div , V_28 , V_32 ) ;
if ( ( V_32 * 100 / V_31 ) > 5 ) {
F_7 ( V_17 L_13
L_14 ,
V_32 * 100 / V_31 ) ;
return - V_39 ;
}
V_10 = F_16 ( V_7 , V_29 , V_28 ,
V_40 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_17 ( V_7 , V_41 , V_30 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_17 ( V_7 , V_42 ,
V_43 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_17 ( V_7 , V_44 ,
F_18 ( div , div ) ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_16 ( V_27 , 0 , V_28 ,
V_45 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
static void F_19 ( int V_46 )
{
F_20 ( V_47 -> V_48 , V_46 > 0 ) ;
}
static void F_21 ( int V_46 )
{
F_20 ( V_47 -> V_49 , V_46 > 0 ) ;
}
static void F_22 ( int V_46 )
{
F_20 ( V_47 -> V_50 , V_46 > 0 ) ;
}
static int F_23 ( int V_51 , char * V_52 )
{
if ( F_24 ( V_51 , L_15 ) < 0 ) {
F_7 ( V_17 L_16
L_17 , V_52 ) ;
return - V_53 ;
}
F_25 ( V_51 , 0 ) ;
return 0 ;
}
static int F_26 ( struct V_54 * V_55 )
{
int V_10 ;
F_7 ( V_56 L_18 ) ;
V_47 = V_55 -> V_16 . V_57 ;
if ( V_47 == NULL ) {
F_7 ( V_17 L_16
L_19 ) ;
return - V_58 ;
}
V_59 . V_60 = V_47 -> V_60 ;
V_59 . V_61 = V_47 -> V_61 ;
if ( F_23 ( V_47 -> V_48 ,
L_20 ) < 0 )
return - V_53 ;
if ( F_23 ( V_47 -> V_49 ,
L_21 ) < 0 ) {
F_27 ( V_47 -> V_48 ) ;
return - V_53 ;
}
if ( F_23 ( V_47 -> V_50 ,
L_22 ) < 0 ) {
F_27 ( V_47 -> V_48 ) ;
F_27 ( V_47 -> V_49 ) ;
return - V_53 ;
}
V_15 = F_28 ( L_23 , - 1 ) ;
if ( ! V_15 ) {
F_7 ( V_17 L_16
L_24 ) ;
return - V_62 ;
}
F_29 ( V_15 ,
& V_63 ) ;
F_30 ( V_15 , & V_59 , sizeof( V_59 ) ) ;
V_10 = F_31 ( V_15 ) ;
if ( V_10 ) {
F_7 ( V_17 L_25 ) ;
F_32 ( V_15 ) ;
}
return V_10 ;
}
static int F_33 ( struct V_54 * V_55 )
{
F_34 ( V_15 ) ;
F_27 ( V_47 -> V_48 ) ;
F_27 ( V_47 -> V_49 ) ;
F_27 ( V_47 -> V_50 ) ;
return 0 ;
}
