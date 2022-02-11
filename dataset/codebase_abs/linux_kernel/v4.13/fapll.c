static bool F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_4 ) ;
if ( V_2 -> V_5 )
return ! ( V_3 & V_6 ) ;
else
return ! ! ( V_3 & V_6 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_4 ) ;
if ( V_2 -> V_5 )
V_3 &= ~ V_6 ;
else
V_3 |= V_6 ;
F_4 ( V_3 , V_2 -> V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_4 ) ;
if ( V_2 -> V_5 )
V_3 |= V_6 ;
else
V_3 &= ~ V_6 ;
F_4 ( V_3 , V_2 -> V_4 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_7 = V_8 ;
T_1 V_3 ;
while ( ( V_3 = F_2 ( V_2 -> V_4 ) ) ) {
if ( V_3 & V_9 )
return 0 ;
if ( V_7 -- <= 0 )
break;
F_7 ( 1 ) ;
}
F_8 ( L_1 , V_2 -> V_10 ) ;
return - V_11 ;
}
static int F_9 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_10 ( V_13 ) ;
T_1 V_3 = F_2 ( V_2 -> V_4 ) ;
V_3 |= V_14 ;
F_4 ( V_3 , V_2 -> V_4 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static void F_11 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_10 ( V_13 ) ;
T_1 V_3 = F_2 ( V_2 -> V_4 ) ;
V_3 &= ~ V_14 ;
F_4 ( V_3 , V_2 -> V_4 ) ;
}
static int F_12 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_10 ( V_13 ) ;
T_1 V_3 = F_2 ( V_2 -> V_4 ) ;
return V_3 & V_14 ;
}
static unsigned long F_13 ( struct V_12 * V_13 ,
unsigned long V_15 )
{
struct V_1 * V_2 = F_10 ( V_13 ) ;
T_1 V_16 , V_17 , V_3 ;
T_2 V_18 ;
if ( F_1 ( V_2 ) )
return V_15 ;
V_18 = V_15 ;
V_3 = F_2 ( V_2 -> V_4 ) ;
V_17 = ( V_3 >> 8 ) & 0xff ;
if ( V_17 )
F_14 ( V_18 , V_17 ) ;
V_16 = V_3 >> 16 ;
if ( V_16 )
V_18 *= V_16 ;
return V_18 ;
}
static T_3 F_15 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_10 ( V_13 ) ;
if ( F_1 ( V_2 ) )
return 1 ;
return 0 ;
}
static int F_16 ( unsigned long V_18 ,
unsigned long V_15 ,
T_1 * V_19 , T_1 * V_20 )
{
if ( V_18 < V_15 ) {
F_17 ( L_2 ) ;
return - V_21 ;
}
* V_20 = V_18 / V_15 ;
if ( * V_20 > V_22 )
return - V_21 ;
* V_19 = 1 ;
return 0 ;
}
static long F_18 ( struct V_12 * V_13 , unsigned long V_18 ,
unsigned long * V_15 )
{
T_1 V_19 , V_20 ;
int error ;
if ( ! V_18 )
return - V_21 ;
error = F_16 ( V_18 , * V_15 ,
& V_19 , & V_20 ) ;
if ( error )
return error ;
V_18 = * V_15 / V_19 ;
V_18 *= V_20 ;
return V_18 ;
}
static int F_19 ( struct V_12 * V_13 , unsigned long V_18 ,
unsigned long V_15 )
{
struct V_1 * V_2 = F_10 ( V_13 ) ;
T_1 V_19 , V_20 , V_3 ;
int error ;
if ( ! V_18 )
return - V_21 ;
error = F_16 ( V_18 , V_15 ,
& V_19 , & V_20 ) ;
if ( error )
return error ;
F_3 ( V_2 ) ;
V_3 = F_2 ( V_2 -> V_4 ) ;
V_3 &= ~ V_23 ;
V_3 |= V_19 << V_24 ;
V_3 |= V_20 << V_25 ;
F_4 ( V_3 , V_2 -> V_4 ) ;
if ( F_12 ( V_13 ) )
F_6 ( V_2 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_20 ( struct V_12 * V_13 )
{
struct V_26 * V_27 = F_21 ( V_13 ) ;
T_1 V_3 = F_2 ( V_27 -> V_2 -> V_4 + V_28 ) ;
V_3 &= ~ ( 1 << V_27 -> V_29 ) ;
F_4 ( V_3 , V_27 -> V_2 -> V_4 + V_28 ) ;
return 0 ;
}
static void F_22 ( struct V_12 * V_13 )
{
struct V_26 * V_27 = F_21 ( V_13 ) ;
T_1 V_3 = F_2 ( V_27 -> V_2 -> V_4 + V_28 ) ;
V_3 |= 1 << V_27 -> V_29 ;
F_4 ( V_3 , V_27 -> V_2 -> V_4 + V_28 ) ;
}
static int F_23 ( struct V_12 * V_13 )
{
struct V_26 * V_27 = F_21 ( V_13 ) ;
T_1 V_3 = F_2 ( V_27 -> V_2 -> V_4 + V_28 ) ;
return ! ( V_3 & ( 1 << V_27 -> V_29 ) ) ;
}
static unsigned long F_24 ( struct V_12 * V_13 ,
unsigned long V_15 )
{
struct V_26 * V_27 = F_21 ( V_13 ) ;
T_1 V_30 ;
T_2 V_18 ;
if ( ! V_27 -> div )
return 32768 ;
if ( F_1 ( V_27 -> V_2 ) )
return V_15 ;
V_18 = V_15 ;
if ( V_27 -> V_31 ) {
T_1 V_3 , V_32 , V_33 , V_34 ;
V_3 = F_2 ( V_27 -> V_31 ) ;
V_32 = ( V_3 >> 24 ) & 0xf ;
V_33 = V_3 & 0xffffff ;
V_34 = ( V_32 * 10000000 ) + V_33 ;
V_18 *= 10000000 ;
F_14 ( V_18 , V_34 ) ;
V_18 *= V_35 ;
}
V_30 = F_2 ( V_27 -> div ) & V_36 ;
return F_25 ( V_18 , V_30 ) ;
}
static unsigned long F_26 ( struct V_12 * V_13 ,
unsigned long V_15 )
{
struct V_26 * V_27 = F_21 ( V_13 ) ;
unsigned long V_37 , V_38 ;
T_1 V_39 ;
V_37 = F_24 ( V_13 , V_15 ) ;
V_39 = F_2 ( V_27 -> div ) & V_36 ;
V_38 = V_37 * V_39 ;
return V_38 ;
}
static T_1 F_27 ( struct V_26 * V_27 ,
unsigned long V_18 ,
unsigned long V_15 )
{
T_1 V_39 , V_32 = 0 , V_33 = 0 , V_3 ;
V_39 = F_25 ( ( T_2 ) V_15 * V_35 , V_18 ) ;
V_39 = V_39 / V_40 ;
if ( V_39 > V_36 )
return - V_21 ;
if ( ! V_39 )
V_39 = 1 ;
for (; V_39 < V_36 ; V_39 ++ ) {
V_32 = F_25 ( ( T_2 ) V_15 *
V_35 *
10000000 ,
V_18 * V_39 ) ;
V_33 = V_32 % 10000000 ;
V_32 /= 10000000 ;
if ( V_32 <= V_40 )
break;
}
if ( V_32 > V_40 )
return - V_21 ;
V_3 = F_2 ( V_27 -> V_31 ) ;
V_3 &= ~ 0x1fffffff ;
V_3 |= ( V_32 & V_40 ) << 24 ;
V_3 |= ( V_33 & 0xffffff ) ;
V_3 |= V_41 ;
F_4 ( V_3 , V_27 -> V_31 ) ;
return V_39 ;
}
static long F_28 ( struct V_12 * V_13 , unsigned long V_18 ,
unsigned long * V_15 )
{
struct V_26 * V_27 = F_21 ( V_13 ) ;
struct V_1 * V_2 = V_27 -> V_2 ;
unsigned long V_42 ;
if ( F_1 ( V_2 ) || ! V_27 -> div || ! V_18 )
return - V_21 ;
if ( ! V_27 -> V_31 ) {
unsigned long V_38 ;
T_1 V_43 ;
V_38 = F_26 ( V_13 , * V_15 ) ;
V_43 = F_29 ( V_38 , V_18 ) ;
V_42 = F_29 ( V_38 , V_43 ) ;
goto V_44;
}
V_42 = * V_15 * V_35 ;
if ( V_18 > V_42 )
goto V_44;
V_42 = F_25 ( V_42 , V_40 * V_36 ) ;
if ( V_18 < V_42 )
goto V_44;
V_42 = V_18 ;
V_44:
return V_42 ;
}
static int F_30 ( struct V_12 * V_13 , unsigned long V_18 ,
unsigned long V_15 )
{
struct V_26 * V_27 = F_21 ( V_13 ) ;
struct V_1 * V_2 = V_27 -> V_2 ;
unsigned long V_38 , V_45 = 0 ;
T_1 V_39 = 0 , V_3 ;
if ( F_1 ( V_2 ) || ! V_27 -> div || ! V_18 )
return - V_21 ;
V_38 = F_26 ( V_13 , V_15 ) ;
if ( V_38 < V_18 ) {
if ( ! V_27 -> V_31 )
return - V_21 ;
} else {
V_39 = F_29 ( V_38 , V_18 ) ;
if ( V_39 && ( V_39 <= V_36 ) )
V_45 = F_29 ( V_38 , V_39 ) ;
if ( ! V_27 -> V_31 && ! V_45 )
return - V_21 ;
}
if ( ( V_45 != V_18 ) && V_27 -> V_31 )
V_39 = F_27 ( V_27 ,
V_18 ,
V_15 ) ;
V_3 = F_2 ( V_27 -> div ) ;
V_3 &= ~ V_36 ;
V_3 |= V_39 ;
V_3 |= V_46 ;
F_4 ( V_3 , V_27 -> div ) ;
return 0 ;
}
static struct V_47 * T_4 F_31 ( struct V_1 * V_2 ,
void T_5 * V_31 ,
void T_5 * div ,
int V_29 ,
const char * V_10 ,
const char * V_48 ,
struct V_47 * V_49 )
{
struct V_50 * V_51 ;
struct V_26 * V_27 ;
V_51 = F_32 ( sizeof( * V_51 ) , V_52 ) ;
if ( ! V_51 )
return F_33 ( - V_53 ) ;
V_51 -> V_54 = & V_55 ;
V_51 -> V_10 = V_10 ;
V_51 -> V_56 = & V_48 ;
V_51 -> V_57 = 1 ;
V_27 = F_32 ( sizeof( * V_27 ) , V_52 ) ;
if ( ! V_27 )
goto free;
V_27 -> V_2 = V_2 ;
V_27 -> V_29 = V_29 ;
V_27 -> V_31 = V_31 ;
V_27 -> div = div ;
V_27 -> V_10 = V_10 ;
V_27 -> V_13 . V_51 = V_51 ;
V_27 -> V_58 = V_49 ;
return F_34 ( NULL , & V_27 -> V_13 ) ;
free:
F_35 ( V_27 ) ;
F_35 ( V_51 ) ;
return F_33 ( - V_53 ) ;
}
static void T_4 F_36 ( struct V_59 * V_60 )
{
struct V_1 * V_2 ;
struct V_50 * V_51 = NULL ;
const char * V_61 [ 2 ] ;
struct V_47 * V_49 ;
int V_62 ;
V_2 = F_32 ( sizeof( * V_2 ) , V_52 ) ;
if ( ! V_2 )
return;
V_2 -> V_63 . V_64 = F_32 ( sizeof( struct V_47 * ) *
V_65 + 1 ,
V_52 ) ;
if ( ! V_2 -> V_63 . V_64 )
goto free;
V_51 = F_32 ( sizeof( * V_51 ) , V_52 ) ;
if ( ! V_51 )
goto free;
V_51 -> V_54 = & V_66 ;
V_51 -> V_10 = V_60 -> V_10 ;
V_51 -> V_57 = F_37 ( V_60 ) ;
if ( V_51 -> V_57 != 2 ) {
F_8 ( L_3 , V_60 -> V_10 ) ;
goto free;
}
F_38 ( V_60 , V_61 , 2 ) ;
V_51 -> V_56 = V_61 ;
V_2 -> V_67 = F_39 ( V_60 , 0 ) ;
if ( F_40 ( V_2 -> V_67 ) ) {
F_8 ( L_4 , V_60 -> V_10 ) ;
goto free;
}
V_2 -> V_68 = F_39 ( V_60 , 1 ) ;
if ( F_40 ( V_2 -> V_68 ) ) {
F_8 ( L_5 , V_60 -> V_10 ) ;
goto free;
}
V_2 -> V_4 = F_41 ( V_60 , 0 ) ;
if ( ! V_2 -> V_4 ) {
F_8 ( L_6 , V_60 -> V_10 ) ;
goto free;
}
if ( F_42 ( V_2 -> V_4 ) )
V_2 -> V_5 = true ;
V_2 -> V_10 = V_60 -> V_10 ;
V_2 -> V_13 . V_51 = V_51 ;
V_49 = F_34 ( NULL , & V_2 -> V_13 ) ;
if ( F_40 ( V_49 ) )
goto V_69;
V_2 -> V_63 . V_64 [ 0 ] = V_49 ;
V_2 -> V_63 . V_70 ++ ;
for ( V_62 = 0 ; V_62 < V_65 ; V_62 ++ ) {
const char * V_71 ;
void T_5 * V_31 , * div ;
struct V_47 * V_72 ;
int V_73 ;
T_1 V_3 ;
if ( F_43 ( V_60 , L_7 ,
V_62 , & V_71 ) )
continue;
if ( F_44 ( V_60 , L_8 , V_62 ,
& V_73 ) )
V_73 = V_62 ;
V_31 = V_2 -> V_4 + ( V_73 * 8 ) ;
div = V_31 + 4 ;
if ( F_45 ( V_31 ) ) {
V_31 = NULL ;
div = NULL ;
} else {
V_3 = F_2 ( V_31 ) ;
if ( ! V_3 )
V_31 = NULL ;
}
V_72 = F_31 ( V_2 , V_31 , div , V_73 ,
V_71 , V_60 -> V_10 ,
V_49 ) ;
if ( F_40 ( V_72 ) )
continue;
V_2 -> V_63 . V_64 [ V_73 ] = V_72 ;
V_2 -> V_63 . V_70 ++ ;
F_46 ( V_72 , V_71 , NULL ) ;
}
F_47 ( V_60 , V_74 , & V_2 -> V_63 ) ;
F_35 ( V_51 ) ;
return;
V_69:
F_48 ( V_2 -> V_4 ) ;
free:
if ( V_2 -> V_68 )
F_49 ( V_2 -> V_68 ) ;
if ( V_2 -> V_67 )
F_49 ( V_2 -> V_67 ) ;
F_35 ( V_2 -> V_63 . V_64 ) ;
F_35 ( V_2 ) ;
F_35 ( V_51 ) ;
}
