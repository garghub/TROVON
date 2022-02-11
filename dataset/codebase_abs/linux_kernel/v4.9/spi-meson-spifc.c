static int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = V_4 + F_2 ( 5 ) ;
T_1 V_5 ;
do {
F_3 ( V_2 -> V_6 , V_7 , & V_5 ) ;
if ( V_5 & V_8 )
return 0 ;
F_4 () ;
} while ( ! F_5 ( V_4 , V_3 ) );
return - V_9 ;
}
static void F_6 ( struct V_1 * V_2 , T_2 * V_10 ,
int V_11 )
{
T_1 V_5 ;
int V_12 = 0 ;
while ( V_12 < V_11 ) {
F_3 ( V_2 -> V_6 , V_13 + V_12 , & V_5 ) ;
if ( V_11 - V_12 >= 4 ) {
* ( ( T_1 * ) V_10 ) = V_5 ;
V_10 += 4 ;
} else {
memcpy ( V_10 , & V_5 , V_11 - V_12 ) ;
break;
}
V_12 += 4 ;
}
}
static void F_7 ( struct V_1 * V_2 , const T_2 * V_10 ,
int V_11 )
{
T_1 V_5 ;
int V_12 = 0 ;
while ( V_12 < V_11 ) {
if ( V_11 - V_12 >= 4 )
V_5 = * ( T_1 * ) V_10 ;
else
memcpy ( & V_5 , V_10 , V_11 - V_12 ) ;
F_8 ( V_2 -> V_6 , V_13 + V_12 , V_5 ) ;
V_10 += 4 ;
V_12 += 4 ;
}
}
static void F_9 ( struct V_1 * V_2 , T_1 V_14 )
{
unsigned long V_15 , V_16 ;
int V_17 ;
V_15 = F_10 ( V_2 -> V_18 ) ;
V_17 = F_11 ( int , V_15 / V_14 - 1 , 1 ) ;
F_12 ( V_2 -> V_19 , L_1 , V_15 ,
V_14 , V_17 ) ;
V_16 = ( V_17 << V_20 ) & V_21 ;
V_16 |= ( V_17 << V_22 ) & V_23 ;
V_16 |= ( ( ( V_17 + 1 ) / 2 - 1 ) << V_24 ) &
V_25 ;
F_8 ( V_2 -> V_6 , V_26 , V_16 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
int V_29 , int V_11 , bool V_30 ,
bool V_31 )
{
bool V_32 = true ;
int V_33 ;
if ( V_28 -> V_34 )
F_7 ( V_2 , V_28 -> V_34 + V_29 , V_11 ) ;
F_14 ( V_2 -> V_6 , V_35 , V_36 ,
V_37 ) ;
F_8 ( V_2 -> V_6 , V_38 ,
( 8 * V_11 - 1 ) << V_39 ) ;
F_14 ( V_2 -> V_6 , V_35 , V_40 ,
V_40 ) ;
if ( V_31 ) {
if ( V_30 )
V_32 = V_28 -> V_41 ;
else
V_32 = ! V_28 -> V_41 ;
}
F_14 ( V_2 -> V_6 , V_42 , V_43 ,
V_32 ? V_43 : 0 ) ;
F_14 ( V_2 -> V_6 , V_7 , V_8 , 0 ) ;
F_14 ( V_2 -> V_6 , V_44 , V_45 , V_45 ) ;
V_33 = F_1 ( V_2 ) ;
if ( ! V_33 && V_28 -> V_46 )
F_6 ( V_2 , V_28 -> V_46 + V_29 , V_11 ) ;
return V_33 ;
}
static int F_15 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_27 * V_28 )
{
struct V_1 * V_2 = F_16 ( V_48 ) ;
int V_11 , V_51 = 0 , V_33 = 0 ;
F_9 ( V_2 , V_28 -> V_52 ) ;
F_14 ( V_2 -> V_6 , V_53 , V_54 , 0 ) ;
while ( V_51 < V_28 -> V_11 && ! V_33 ) {
V_11 = F_17 ( int , V_28 -> V_11 - V_51 , V_55 ) ;
V_33 = F_13 ( V_2 , V_28 , V_51 , V_11 ,
F_18 ( V_48 , V_28 ) ,
V_51 + V_11 >= V_28 -> V_11 ) ;
V_51 += V_11 ;
}
F_14 ( V_2 -> V_6 , V_53 , V_54 ,
V_54 ) ;
return V_33 ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_14 ( V_2 -> V_6 , V_7 , V_56 ,
V_56 ) ;
F_14 ( V_2 -> V_6 , V_35 , V_57 , 0 ) ;
F_14 ( V_2 -> V_6 , V_7 , V_58 , 0 ) ;
}
static int F_20 ( struct V_59 * V_60 )
{
struct V_47 * V_48 ;
struct V_1 * V_2 ;
struct V_61 * V_62 ;
void T_3 * V_63 ;
unsigned int V_64 ;
int V_33 = 0 ;
V_48 = F_21 ( & V_60 -> V_19 , sizeof( struct V_1 ) ) ;
if ( ! V_48 )
return - V_65 ;
F_22 ( V_60 , V_48 ) ;
V_2 = F_16 ( V_48 ) ;
V_2 -> V_19 = & V_60 -> V_19 ;
V_62 = F_23 ( V_60 , V_66 , 0 ) ;
V_63 = F_24 ( V_2 -> V_19 , V_62 ) ;
if ( F_25 ( V_63 ) ) {
V_33 = F_26 ( V_63 ) ;
goto V_67;
}
V_2 -> V_6 = F_27 ( V_2 -> V_19 , V_63 ,
& V_68 ) ;
if ( F_25 ( V_2 -> V_6 ) ) {
V_33 = F_26 ( V_2 -> V_6 ) ;
goto V_67;
}
V_2 -> V_18 = F_28 ( V_2 -> V_19 , NULL ) ;
if ( F_25 ( V_2 -> V_18 ) ) {
F_29 ( V_2 -> V_19 , L_2 ) ;
V_33 = F_26 ( V_2 -> V_18 ) ;
goto V_67;
}
V_33 = F_30 ( V_2 -> V_18 ) ;
if ( V_33 ) {
F_29 ( V_2 -> V_19 , L_3 ) ;
goto V_67;
}
V_64 = F_10 ( V_2 -> V_18 ) ;
V_48 -> V_69 = 1 ;
V_48 -> V_19 . V_70 = V_60 -> V_19 . V_70 ;
V_48 -> V_71 = F_31 ( 8 ) ;
V_48 -> V_72 = true ;
V_48 -> V_73 = F_15 ;
V_48 -> V_74 = V_64 >> 6 ;
V_48 -> V_75 = V_64 >> 1 ;
F_19 ( V_2 ) ;
F_32 ( V_2 -> V_19 ) ;
F_33 ( V_2 -> V_19 ) ;
V_33 = F_34 ( V_2 -> V_19 , V_48 ) ;
if ( V_33 ) {
F_29 ( V_2 -> V_19 , L_4 ) ;
goto V_76;
}
return 0 ;
V_76:
F_35 ( V_2 -> V_18 ) ;
V_67:
F_36 ( V_48 ) ;
return V_33 ;
}
static int F_37 ( struct V_59 * V_60 )
{
struct V_47 * V_48 = F_38 ( V_60 ) ;
struct V_1 * V_2 = F_16 ( V_48 ) ;
F_39 ( & V_60 -> V_19 ) ;
F_35 ( V_2 -> V_18 ) ;
F_40 ( & V_60 -> V_19 ) ;
return 0 ;
}
static int F_41 ( struct V_77 * V_19 )
{
struct V_47 * V_48 = F_42 ( V_19 ) ;
struct V_1 * V_2 = F_16 ( V_48 ) ;
int V_33 ;
V_33 = F_43 ( V_48 ) ;
if ( V_33 )
return V_33 ;
if ( ! F_44 ( V_19 ) )
F_35 ( V_2 -> V_18 ) ;
return 0 ;
}
static int F_45 ( struct V_77 * V_19 )
{
struct V_47 * V_48 = F_42 ( V_19 ) ;
struct V_1 * V_2 = F_16 ( V_48 ) ;
int V_33 ;
if ( ! F_44 ( V_19 ) ) {
V_33 = F_30 ( V_2 -> V_18 ) ;
if ( V_33 )
return V_33 ;
}
F_19 ( V_2 ) ;
V_33 = F_46 ( V_48 ) ;
if ( V_33 )
F_35 ( V_2 -> V_18 ) ;
return V_33 ;
}
static int F_47 ( struct V_77 * V_19 )
{
struct V_47 * V_48 = F_42 ( V_19 ) ;
struct V_1 * V_2 = F_16 ( V_48 ) ;
F_35 ( V_2 -> V_18 ) ;
return 0 ;
}
static int F_48 ( struct V_77 * V_19 )
{
struct V_47 * V_48 = F_42 ( V_19 ) ;
struct V_1 * V_2 = F_16 ( V_48 ) ;
return F_30 ( V_2 -> V_18 ) ;
}
