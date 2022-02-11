static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , int V_4 , unsigned long * V_5 )
{
unsigned long V_6 = V_3 ;
unsigned int V_7 ;
V_7 = V_2 [ V_4 ] . V_7 ? 256 : 1 ;
V_6 = ( ( ( 2 * V_6 / 10000 ) * V_2 [ V_4 ] . V_8 ) / ( V_7 * V_2 [ V_4 ] . V_9 ) ) ;
if ( V_5 )
* V_5 = ( V_6 / ( 1 << V_2 [ V_4 ] . V_10 ) ) * 10000 ;
return V_6 * 10000 ;
}
static long F_2 ( struct V_11 * V_12 , unsigned long V_13 ,
unsigned long * V_3 , int * V_4 )
{
struct V_14 * V_15 = F_3 ( V_12 ) ;
unsigned long V_16 , V_17 , V_6 = 0 ;
unsigned long V_18 =
F_4 ( F_5 ( F_5 ( V_12 -> V_19 ) ) ) ;
if ( ! V_3 ) {
F_6 ( L_1 , V_20 ) ;
return - V_21 ;
}
for ( * V_4 = 0 ; * V_4 < V_15 -> V_22 -> V_23 ; ( * V_4 ) ++ ) {
V_16 = V_6 ;
V_17 = * V_3 ;
* V_3 = F_1 ( V_15 -> V_22 -> V_2 , V_18 , * V_4 ,
& V_6 ) ;
if ( V_13 < V_6 ) {
if ( * V_4 ) {
V_6 = V_16 ;
* V_3 = V_17 ;
( * V_4 ) -- ;
}
break;
}
}
return V_6 ;
}
static long F_7 ( struct V_11 * V_12 , unsigned long V_13 ,
unsigned long * V_3 )
{
int V_24 ;
return F_2 ( V_12 , V_13 , V_3 , & V_24 ) ;
}
static unsigned long F_8 ( struct V_11 * V_12 , unsigned long
V_25 )
{
struct V_14 * V_15 = F_3 ( V_12 ) ;
unsigned long V_26 = 0 ;
unsigned int V_10 ;
if ( V_15 -> V_22 -> V_27 )
F_9 ( V_15 -> V_22 -> V_27 , V_26 ) ;
V_10 = F_10 ( V_15 -> V_22 -> V_28 ) ;
if ( V_15 -> V_22 -> V_27 )
F_11 ( V_15 -> V_22 -> V_27 , V_26 ) ;
V_10 = ( V_10 >> V_29 ) & V_30 ;
return V_25 / ( 1 << V_10 ) ;
}
static int F_12 ( struct V_11 * V_12 , unsigned long V_13 ,
unsigned long V_3 )
{
struct V_14 * V_15 = F_3 ( V_12 ) ;
struct V_1 * V_2 = V_15 -> V_22 -> V_2 ;
unsigned long V_26 = 0 , V_31 ;
int V_32 ;
F_2 ( V_12 , V_13 , NULL , & V_32 ) ;
if ( V_15 -> V_22 -> V_27 )
F_9 ( V_15 -> V_22 -> V_27 , V_26 ) ;
V_31 = F_10 ( V_15 -> V_22 -> V_28 ) ;
V_31 &= ~ ( V_30 << V_29 ) ;
V_31 |= ( V_2 [ V_32 ] . V_10 & V_30 ) << V_29 ;
F_13 ( V_31 , V_15 -> V_22 -> V_28 ) ;
if ( V_15 -> V_22 -> V_27 )
F_11 ( V_15 -> V_22 -> V_27 , V_26 ) ;
return 0 ;
}
static inline unsigned long F_14 ( struct V_11 * V_12 ,
unsigned long V_3 , int V_4 )
{
struct V_33 * V_22 = F_15 ( V_12 ) ;
return F_1 ( V_22 -> V_2 , V_3 , V_4 , NULL ) ;
}
static long F_16 ( struct V_11 * V_12 , unsigned long V_13 ,
unsigned long * V_3 )
{
struct V_33 * V_22 = F_15 ( V_12 ) ;
int V_24 ;
return F_17 ( V_12 , V_13 , * V_3 , F_14 ,
V_22 -> V_23 , & V_24 ) ;
}
static unsigned long F_18 ( struct V_11 * V_12 ,
unsigned long V_25 )
{
struct V_33 * V_22 = F_15 ( V_12 ) ;
unsigned long V_26 = 0 ;
unsigned int V_34 = 2 , V_35 = 0 , V_31 , V_7 = 0 ;
if ( V_22 -> V_27 )
F_9 ( V_22 -> V_27 , V_26 ) ;
V_7 = ( F_10 ( V_22 -> V_36 ) >> V_37 ) & V_38 ;
V_31 = F_10 ( V_22 -> V_28 ) ;
if ( V_22 -> V_27 )
F_11 ( V_22 -> V_27 , V_26 ) ;
V_35 = ( V_31 >> V_39 ) & V_40 ;
if ( ! V_7 ) {
V_34 *= ( V_31 >> V_41 ) & V_42 ;
} else {
V_34 *= ( V_31 >> V_43 ) & V_44 ;
V_35 *= 256 ;
}
if ( ! V_35 ) {
F_19 ( 1 , L_2 , V_20 ) ;
return 0 ;
}
return ( ( ( V_25 / 10000 ) * V_34 ) / V_35 ) * 10000 ;
}
static int F_20 ( struct V_11 * V_12 , unsigned long V_13 ,
unsigned long V_3 )
{
struct V_33 * V_22 = F_15 ( V_12 ) ;
struct V_1 * V_2 = V_22 -> V_2 ;
unsigned long V_26 = 0 , V_31 ;
int V_32 ;
F_17 ( V_12 , V_13 , V_3 , F_14 , V_22 -> V_23 ,
& V_32 ) ;
if ( V_22 -> V_27 )
F_9 ( V_22 -> V_27 , V_26 ) ;
V_31 = F_10 ( V_22 -> V_36 ) ;
V_31 &= ~ ( V_38 << V_37 ) ;
V_31 |= ( V_2 [ V_32 ] . V_7 & V_38 ) << V_37 ;
F_13 ( V_31 , V_22 -> V_36 ) ;
V_31 = F_10 ( V_22 -> V_28 ) ;
V_31 &= ~ ( V_40 << V_39 ) ;
V_31 |= ( V_2 [ V_32 ] . V_9 & V_40 ) << V_39 ;
V_31 &= ~ ( V_44 << V_43 ) ;
if ( V_2 [ V_32 ] . V_7 )
V_31 |= ( V_2 [ V_32 ] . V_8 & V_44 ) <<
V_43 ;
else
V_31 |= ( V_2 [ V_32 ] . V_8 & V_42 ) <<
V_41 ;
F_13 ( V_31 , V_22 -> V_28 ) ;
if ( V_22 -> V_27 )
F_11 ( V_22 -> V_27 , V_26 ) ;
return 0 ;
}
struct V_19 * F_21 ( const char * V_45 , const char * V_46 ,
const char * V_47 , const char * V_48 ,
unsigned long V_26 , void T_1 * V_36 , void T_1
* V_28 , struct V_1 * V_2 , T_2 V_23 ,
T_3 * V_27 , struct V_19 * * V_49 ,
struct V_19 * * V_50 )
{
struct V_33 * V_22 ;
struct V_14 * V_15 ;
struct V_19 * V_51 , * V_52 , * V_53 ;
struct V_54 V_55 , V_56 ;
const char * * V_57 ;
if ( ! V_45 || ! V_46 || ! V_48 || ! V_36 || ! V_28 ||
! V_2 || ! V_23 ) {
F_6 ( L_3 ) ;
return F_22 ( - V_21 ) ;
}
V_22 = F_23 ( sizeof( * V_22 ) , V_58 ) ;
if ( ! V_22 ) {
F_6 ( L_4 ) ;
return F_22 ( - V_59 ) ;
}
V_15 = F_23 ( sizeof( * V_15 ) , V_58 ) ;
if ( ! V_15 ) {
F_6 ( L_5 ) ;
goto V_60;
}
V_22 -> V_36 = V_36 ;
V_22 -> V_28 = V_28 ;
V_22 -> V_2 = V_2 ;
V_22 -> V_23 = V_23 ;
V_22 -> V_27 = V_27 ;
V_22 -> V_12 . V_61 = & V_55 ;
V_15 -> V_22 = V_22 ;
V_15 -> V_12 . V_61 = & V_56 ;
if ( V_47 ) {
V_53 = F_24 ( NULL , V_47 ,
V_48 , 0 , V_36 , V_62 , 0 , V_27 ) ;
if ( F_25 ( V_53 ) )
goto V_63;
if ( V_50 )
* V_50 = V_53 ;
V_57 = & V_47 ;
} else {
V_57 = & V_48 ;
}
V_55 . V_64 = V_45 ;
V_55 . V_65 = & V_66 ;
V_55 . V_26 = V_26 ;
V_55 . V_67 = V_57 ;
V_55 . V_68 = 1 ;
V_56 . V_64 = V_46 ;
V_56 . V_65 = & V_69 ;
V_56 . V_26 = V_70 ;
V_56 . V_67 = & V_45 ;
V_56 . V_68 = 1 ;
V_51 = F_26 ( NULL , & V_22 -> V_12 ) ;
if ( F_25 ( V_51 ) )
goto V_63;
V_52 = F_26 ( NULL , & V_15 -> V_12 ) ;
if ( F_25 ( V_52 ) )
goto V_63;
if ( V_49 )
* V_49 = V_52 ;
return V_51 ;
V_63:
F_27 ( V_15 ) ;
V_60:
F_27 ( V_22 ) ;
F_6 ( L_6 ) ;
return F_22 ( - V_59 ) ;
}
