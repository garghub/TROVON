static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
int V_4 ;
struct V_5 * V_6 = V_2 -> V_7 -> V_6 . V_8 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_9 ; V_4 ++ ) {
struct V_10 * V_11 ;
int V_12 = 0 ;
unsigned int V_13 = V_2 -> V_14 [ V_4 ] ;
bool V_15 = V_4 >= V_3 ? true : false ;
V_11 = F_2 ( V_6 , V_13 , ! V_15 ) ;
if ( F_3 ( V_11 ) == - V_16 )
continue;
else if ( F_4 ( V_11 ) )
return F_3 ( V_11 ) ;
F_5 ( V_11 ) ;
if ( V_15 )
V_12 = F_6 ( V_6 , V_13 ) ;
else
V_12 = F_7 ( V_6 , V_13 ) ;
if ( V_12 )
return V_12 ;
}
return 0 ;
}
static int F_8 ( struct V_17 * V_18 ,
unsigned long * V_19 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
* V_19 = V_2 -> V_9 - 1 ;
return 0 ;
}
static int F_9 ( struct V_17 * V_18 ,
unsigned long * V_19 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
* V_19 = V_2 -> V_21 ;
return 0 ;
}
static int F_10 ( struct V_17 * V_18 ,
unsigned long V_19 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
struct V_7 * V_22 = V_2 -> V_7 ;
struct V_5 * V_6 = V_22 -> V_6 . V_8 ;
int V_12 ;
if ( V_19 == V_2 -> V_21 )
return 0 ;
F_11 ( V_6 , L_1 , V_19 ) ;
if ( V_19 >= V_2 -> V_9 )
return - V_23 ;
V_12 = F_1 ( V_2 , V_19 ) ;
if ( V_12 )
return V_12 ;
V_2 -> V_21 = V_19 ;
return 0 ;
}
static unsigned long
F_12 ( struct V_1 * V_2 , unsigned long V_13 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_9 ; V_4 ++ ) {
if ( V_2 -> V_14 [ V_4 ] == V_13 )
return V_4 ;
}
return V_24 ;
}
static unsigned long F_13 ( struct V_7 * V_22 , unsigned long V_13 )
{
struct V_5 * V_6 = V_22 -> V_6 . V_8 ;
unsigned long V_25 ;
struct V_10 * V_11 ;
V_11 = F_2 ( V_6 , V_13 , true ) ;
if ( F_3 ( V_11 ) == - V_16 )
V_11 = F_2 ( V_6 , V_13 , false ) ;
if ( F_4 ( V_11 ) ) {
F_14 ( V_6 , L_2 ,
V_13 , F_3 ( V_11 ) ) ;
return 0 ;
}
V_25 = F_15 ( V_11 ) / 1000 ;
F_5 ( V_11 ) ;
if ( V_25 == 0 ) {
F_14 ( V_6 ,
L_3 ,
V_13 ) ;
}
return V_25 ;
}
static unsigned long
F_16 ( struct V_1 * V_2 , unsigned long V_13 )
{
struct V_7 * V_22 = V_2 -> V_7 ;
unsigned long V_25 ;
if ( ! V_2 -> V_26 -> F_16 )
return 0 ;
V_25 = F_13 ( V_22 , V_13 ) ;
if ( V_25 == 0 )
return 0 ;
return V_2 -> V_26 -> F_16 ( V_22 , V_25 ) ;
}
static unsigned long
F_17 ( struct V_1 * V_2 , unsigned long V_13 ,
unsigned long V_25 )
{
T_1 V_27 ;
T_2 V_28 ;
struct V_29 * V_30 = V_2 -> V_26 ;
if ( V_30 -> F_17 )
return V_30 -> F_17 ( V_2 -> V_7 , V_13 ,
V_25 ) ;
V_28 = V_13 / 1000000 ;
V_27 = ( T_1 ) V_30 -> V_31 * V_28 * V_25 * V_25 ;
F_18 ( V_27 , 1000000000 ) ;
return V_27 ;
}
static inline unsigned long F_19 ( struct V_1 * V_2 ,
unsigned long V_13 ,
unsigned long V_25 )
{
return F_16 ( V_2 , V_13 ) + F_17 ( V_2 , V_13 ,
V_25 ) ;
}
static int F_20 ( struct V_17 * V_18 ,
struct V_32 * V_33 ,
T_2 * V_27 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
struct V_7 * V_22 = V_2 -> V_7 ;
struct V_34 * V_35 = & V_22 -> V_36 ;
unsigned long V_19 ;
unsigned long V_13 = V_35 -> V_37 ;
unsigned long V_25 ;
T_2 V_38 = 0 ;
T_2 V_39 = 0 ;
int V_40 ;
V_19 = F_12 ( V_2 , V_13 ) ;
if ( V_19 == V_24 ) {
V_40 = - V_41 ;
goto V_42;
}
if ( V_2 -> V_26 -> V_43 ) {
V_25 = F_13 ( V_22 , V_13 ) ;
if ( V_25 == 0 ) {
V_40 = - V_23 ;
goto V_42;
}
V_40 = V_2 -> V_26 -> V_43 ( V_22 , V_27 , V_13 , V_25 ) ;
if ( ! V_40 ) {
V_19 = V_2 -> V_44 ;
V_2 -> V_45 = V_2 -> V_46 [ V_19 ] ;
V_2 -> V_45 *= V_47 ;
if ( * V_27 > 1 )
V_2 -> V_45 /= * V_27 ;
} else {
goto V_42;
}
} else {
V_38 = V_2 -> V_46 [ V_19 ] ;
V_38 *= V_35 -> V_48 ;
V_38 /= V_35 -> V_49 ;
V_39 = F_16 ( V_2 , V_13 ) ;
* V_27 = V_38 + V_39 ;
}
F_21 ( V_18 , V_35 , V_13 , V_38 ,
V_39 , * V_27 ) ;
return 0 ;
V_42:
V_2 -> V_45 = V_47 ;
return V_40 ;
}
static int F_22 ( struct V_17 * V_18 ,
struct V_32 * V_33 ,
unsigned long V_19 ,
T_2 * V_27 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
unsigned long V_13 ;
T_2 V_39 ;
if ( V_19 >= V_2 -> V_9 )
return - V_23 ;
V_13 = V_2 -> V_14 [ V_19 ] ;
V_39 = F_16 ( V_2 , V_13 ) ;
* V_27 = V_2 -> V_46 [ V_19 ] + V_39 ;
return 0 ;
}
static int F_23 ( struct V_17 * V_18 ,
struct V_32 * V_33 ,
T_2 V_27 , unsigned long * V_19 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
struct V_7 * V_22 = V_2 -> V_7 ;
struct V_34 * V_35 = & V_22 -> V_36 ;
unsigned long V_13 = V_35 -> V_37 ;
unsigned long V_48 ;
T_3 V_38 ;
T_2 V_39 ;
T_3 V_50 ;
int V_4 ;
if ( V_2 -> V_26 -> V_43 ) {
V_50 = V_27 * V_2 -> V_45 ;
V_50 /= V_47 ;
} else {
V_39 = F_16 ( V_2 , V_13 ) ;
V_38 = V_27 - V_39 ;
V_38 = V_38 > 0 ? V_38 : 0 ;
V_48 = V_35 -> V_48 ? : 1 ;
V_50 = ( V_38 * V_35 -> V_49 ) / V_48 ;
}
for ( V_4 = 0 ; V_4 < V_2 -> V_9 - 1 ; V_4 ++ )
if ( V_50 >= V_2 -> V_46 [ V_4 ] )
break;
* V_19 = V_4 ;
V_2 -> V_44 = V_4 ;
F_24 ( V_18 , V_13 , * V_19 , V_27 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_7 * V_22 = V_2 -> V_7 ;
struct V_5 * V_6 = V_22 -> V_6 . V_8 ;
int V_12 , V_51 ;
unsigned long V_13 ;
T_2 * V_46 = NULL ;
T_2 * V_14 ;
int V_4 ;
V_51 = F_26 ( V_6 ) ;
if ( V_2 -> V_26 ) {
V_46 = F_27 ( V_51 , sizeof( * V_46 ) ,
V_52 ) ;
if ( ! V_46 )
return - V_53 ;
}
V_14 = F_27 ( V_51 , sizeof( * V_14 ) ,
V_52 ) ;
if ( ! V_14 ) {
V_12 = - V_53 ;
goto V_54;
}
for ( V_4 = 0 , V_13 = V_55 ; V_4 < V_51 ; V_4 ++ , V_13 -- ) {
unsigned long V_27 , V_25 ;
struct V_10 * V_11 ;
V_11 = F_28 ( V_6 , & V_13 ) ;
if ( F_4 ( V_11 ) ) {
V_12 = F_3 ( V_11 ) ;
goto V_56;
}
V_25 = F_15 ( V_11 ) / 1000 ;
F_5 ( V_11 ) ;
if ( V_2 -> V_26 ) {
if ( V_2 -> V_26 -> V_43 )
V_27 = F_19 ( V_2 , V_13 , V_25 ) ;
else
V_27 = F_17 ( V_2 , V_13 , V_25 ) ;
F_11 ( V_6 , L_4 ,
V_13 / 1000000 , V_25 , V_27 , V_27 ) ;
V_46 [ V_4 ] = V_27 ;
}
V_14 [ V_4 ] = V_13 ;
}
if ( V_2 -> V_26 )
V_2 -> V_46 = V_46 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_9 = V_51 ;
return 0 ;
V_56:
F_29 ( V_14 ) ;
V_54:
F_29 ( V_46 ) ;
return V_12 ;
}
struct V_17 *
F_30 ( struct V_57 * V_58 , struct V_7 * V_22 ,
struct V_29 * V_30 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 ;
char V_59 [ V_60 ] ;
int V_61 ;
V_2 = F_31 ( sizeof( * V_2 ) , V_52 ) ;
if ( ! V_2 )
return F_32 ( - V_53 ) ;
V_2 -> V_7 = V_22 ;
if ( V_30 ) {
V_2 -> V_26 = V_30 ;
V_62 . V_63 =
F_20 ;
V_62 . V_64 = F_22 ;
V_62 . V_65 = F_23 ;
}
V_61 = F_25 ( V_2 ) ;
if ( V_61 )
goto V_66;
V_61 = F_33 ( & V_67 , 0 , 0 , V_52 ) ;
if ( V_61 < 0 )
goto V_56;
V_2 -> V_68 = V_61 ;
snprintf ( V_59 , sizeof( V_59 ) , L_5 , V_2 -> V_68 ) ;
V_18 = F_34 ( V_58 , V_59 , V_2 ,
& V_62 ) ;
if ( F_4 ( V_18 ) ) {
V_61 = F_3 ( V_18 ) ;
F_35 ( V_22 -> V_6 . V_8 ,
L_6 ,
V_61 ) ;
goto V_69;
}
V_2 -> V_18 = V_18 ;
return V_18 ;
V_69:
F_36 ( & V_67 , V_2 -> V_68 ) ;
V_56:
F_29 ( V_2 -> V_46 ) ;
F_29 ( V_2 -> V_14 ) ;
V_66:
F_29 ( V_2 ) ;
return F_32 ( V_61 ) ;
}
struct V_17 *
F_37 ( struct V_57 * V_58 , struct V_7 * V_22 )
{
return F_30 ( V_58 , V_22 , NULL ) ;
}
struct V_17 * F_38 ( struct V_7 * V_22 )
{
return F_37 ( NULL , V_22 ) ;
}
void F_39 ( struct V_17 * V_18 )
{
struct V_1 * V_2 ;
if ( ! V_18 )
return;
V_2 = V_18 -> V_20 ;
F_40 ( V_2 -> V_18 ) ;
F_36 ( & V_67 , V_2 -> V_68 ) ;
F_29 ( V_2 -> V_46 ) ;
F_29 ( V_2 -> V_14 ) ;
F_29 ( V_2 ) ;
}
