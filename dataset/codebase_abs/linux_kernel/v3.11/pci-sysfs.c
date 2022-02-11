static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 , int V_7 )
{
unsigned long V_8 ;
if ( V_6 == V_9 )
V_8 = V_7 ? V_2 -> V_10 : V_2 -> V_11 ;
else
V_8 = V_7 ? V_2 -> V_12 : V_2 -> V_13 ;
V_4 -> V_14 += V_8 >> V_15 ;
return F_2 ( V_4 , V_4 -> V_16 , V_4 -> V_14 ,
V_4 -> V_17 - V_4 -> V_16 ,
V_4 -> V_18 ) ;
}
static int F_3 ( struct V_19 * V_20 , int V_21 ,
struct V_3 * V_4 , int V_7 )
{
unsigned long V_22 , V_23 , V_24 ;
int V_25 = V_7 ? 5 : 0 ;
V_22 = ( V_4 -> V_17 - V_4 -> V_16 ) >> V_15 ;
V_23 = V_4 -> V_14 ;
V_24 = ( ( F_4 ( V_20 , V_21 ) - 1 ) >> ( V_15 - V_25 ) ) + 1 ;
if ( V_23 < V_24 && V_24 - V_23 >= V_22 )
return 1 ;
F_5 ( 1 , L_1
L_2 ,
V_26 -> V_27 , V_7 ? L_3 : L_4 , V_23 , V_23 + V_22 ,
F_6 ( V_20 ) , V_21 , V_24 ) ;
return 0 ;
}
static int F_7 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_3 * V_4 , int V_7 )
{
struct V_19 * V_20 = F_8 ( F_9 ( V_29 ,
struct V_32 , V_29 ) ) ;
struct V_33 * V_34 = V_31 -> V_35 ;
enum V_5 V_6 ;
struct V_36 V_37 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ )
if ( V_34 == & V_20 -> V_33 [ V_38 ] )
break;
if ( V_38 >= V_39 )
return - V_40 ;
if ( ! F_3 ( V_20 , V_38 , V_4 , V_7 ) )
return - V_41 ;
if ( F_10 ( V_34 -> V_23 ) )
return - V_41 ;
F_11 ( V_20 , & V_37 , V_34 ) ;
V_4 -> V_14 += V_37 . V_23 >> ( V_15 - ( V_7 ? 5 : 0 ) ) ;
V_6 = V_34 -> V_42 & V_43 ? V_9 : V_44 ;
return F_1 ( V_20 -> V_45 , V_4 , V_6 , V_7 ) ;
}
static int F_12 ( struct V_46 * V_47 , struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_3 * V_4 )
{
return F_7 ( V_29 , V_31 , V_4 , 1 ) ;
}
static int F_13 ( struct V_46 * V_47 , struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_3 * V_4 )
{
return F_7 ( V_29 , V_31 , V_4 , 0 ) ;
}
void F_14 ( struct V_19 * V_20 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ ) {
struct V_30 * V_48 ;
V_48 = V_20 -> V_48 [ V_38 ] ;
if ( V_48 ) {
F_15 ( & V_20 -> V_49 . V_29 , V_48 ) ;
F_16 ( V_48 ) ;
}
V_48 = V_20 -> V_50 [ V_38 ] ;
if ( V_48 ) {
F_15 ( & V_20 -> V_49 . V_29 , V_48 ) ;
F_16 ( V_48 ) ;
}
}
}
static int F_17 ( struct V_19 * V_20 , int V_21 )
{
struct V_36 V_37 ;
struct V_1 * V_2 = V_20 -> V_45 ;
long V_51 ;
unsigned long V_52 ;
F_11 ( V_20 , & V_37 , & V_20 -> V_33 [ V_21 ] ) ;
V_51 = ( long ) ( V_2 -> V_11 - V_2 -> V_10 ) ;
V_52 = V_51 >= 0x400000000UL ? 0x20000000 : 0x8000000 ;
return V_37 . V_53 < V_52 ;
}
static int F_18 ( struct V_19 * V_20 , int V_21 , char * V_54 ,
char * V_55 , struct V_30 * V_48 ,
unsigned long V_7 )
{
T_1 V_24 = F_4 ( V_20 , V_21 ) ;
sprintf ( V_54 , L_5 , V_21 , V_55 ) ;
V_48 -> V_56 = V_7 ? F_12 :
F_13 ;
V_48 -> V_31 . V_54 = V_54 ;
V_48 -> V_31 . V_57 = V_58 | V_59 ;
V_48 -> V_24 = V_7 ? V_24 << 5 : V_24 ;
V_48 -> V_35 = & V_20 -> V_33 [ V_21 ] ;
return F_19 ( & V_20 -> V_49 . V_29 , V_48 ) ;
}
static int F_20 ( struct V_19 * V_20 , int V_21 )
{
int V_60 , V_61 , V_62 = 0 , V_63 = 1 ;
unsigned long V_64 , V_65 ;
struct V_30 * V_31 ;
struct V_1 * V_2 = V_20 -> V_45 ;
char * V_55 , * V_66 ;
V_55 = L_4 ;
V_61 = 10 ;
if ( V_20 -> V_33 [ V_21 ] . V_42 & V_43 ) {
V_64 = V_2 -> V_10 ;
V_65 = V_2 -> V_11 ;
if ( V_64 && ! F_17 ( V_20 , V_21 ) ) {
V_64 = 0 ;
V_55 = L_6 ;
V_61 = 16 ;
}
} else {
V_64 = V_2 -> V_12 ;
V_65 = V_2 -> V_13 ;
}
if ( V_64 ) {
V_55 = L_7 ;
V_61 = 17 ;
if ( V_65 ) {
V_62 = 16 ;
V_63 = 2 ;
}
}
V_31 = F_21 ( sizeof( * V_31 ) * V_63 + V_61 + V_62 , V_67 ) ;
if ( ! V_31 )
return - V_68 ;
V_66 = ( char * ) ( V_31 + V_63 ) ;
V_20 -> V_48 [ V_21 ] = V_31 ;
V_60 = F_18 ( V_20 , V_21 , V_66 , V_55 , V_31 ,
V_64 ) ;
if ( V_60 || V_63 == 1 )
return V_60 ;
V_66 += V_61 ;
V_31 ++ ;
V_20 -> V_50 [ V_21 ] = V_31 ;
return F_18 ( V_20 , V_21 , V_66 , L_6 , V_31 , 0 ) ;
}
int F_22 ( struct V_19 * V_20 )
{
int V_38 ;
int V_60 ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ ) {
if ( ! F_4 ( V_20 , V_38 ) )
continue;
V_60 = F_20 ( V_20 , V_38 ) ;
if ( V_60 ) {
F_14 ( V_20 ) ;
return V_60 ;
}
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned long V_69 , int V_7 )
{
unsigned long V_22 , V_23 , V_24 ;
V_22 = ( V_4 -> V_17 - V_4 -> V_16 ) >> V_15 ;
V_23 = V_4 -> V_14 ;
V_24 = ( ( V_69 - 1 ) >> V_15 ) + 1 ;
if ( V_23 < V_24 && V_24 - V_23 >= V_22 )
return 1 ;
F_5 ( 1 , L_8
L_2 ,
V_26 -> V_27 , V_7 ? L_3 : L_4 , V_23 , V_23 + V_22 ,
V_2 -> V_70 , V_24 ) ;
return 0 ;
}
static inline int F_24 ( struct V_1 * V_2 ,
enum V_5 V_6 )
{
unsigned long V_8 ;
V_8 = ( V_6 == V_9 ) ? V_2 -> V_10 :
V_2 -> V_12 ;
return V_8 != 0 ;
}
int F_25 ( struct V_71 * V_72 , struct V_3 * V_4 ,
enum V_5 V_6 )
{
struct V_1 * V_2 = V_72 -> V_45 ;
int V_7 = F_24 ( V_2 , V_6 ) ;
unsigned long V_69 ;
V_69 = ( V_6 == V_9 ) ? V_72 -> V_73 -> V_24 :
V_72 -> V_74 -> V_24 ;
if ( ! F_23 ( V_2 , V_4 , V_69 , V_7 ) )
return - V_41 ;
return F_1 ( V_2 , V_4 , V_6 , V_7 ) ;
}
void F_26 ( struct V_71 * V_72 , enum V_5 V_6 )
{
struct V_1 * V_2 = V_72 -> V_45 ;
if ( ! F_24 ( V_2 , V_6 ) )
return;
if ( V_6 == V_9 ) {
V_72 -> V_73 -> V_31 . V_54 = L_9 ;
V_72 -> V_73 -> V_24 <<= 5 ;
} else {
V_72 -> V_74 -> V_31 . V_54 = L_10 ;
V_72 -> V_74 -> V_24 <<= 5 ;
}
return;
}
int F_27 ( struct V_71 * V_72 , T_2 V_75 , T_3 * V_76 , T_1 V_24 )
{
struct V_1 * V_2 = V_72 -> V_45 ;
V_75 += V_2 -> V_77 -> V_23 ;
switch( V_24 ) {
case 1 :
* ( ( V_78 * ) V_76 ) = F_28 ( V_75 ) ;
return 1 ;
case 2 :
if ( V_75 & 1 )
return - V_41 ;
* ( ( V_79 * ) V_76 ) = F_29 ( V_75 ) ;
return 2 ;
case 4 :
if ( V_75 & 3 )
return - V_41 ;
* ( ( T_3 * ) V_76 ) = F_30 ( V_75 ) ;
return 4 ;
}
return - V_41 ;
}
int F_31 ( struct V_71 * V_72 , T_2 V_75 , T_3 V_76 , T_1 V_24 )
{
struct V_1 * V_2 = V_72 -> V_45 ;
V_75 += V_2 -> V_77 -> V_23 ;
switch( V_24 ) {
case 1 :
F_32 ( V_75 , V_76 ) ;
return 1 ;
case 2 :
if ( V_75 & 1 )
return - V_41 ;
F_33 ( V_75 , V_76 ) ;
return 2 ;
case 4 :
if ( V_75 & 3 )
return - V_41 ;
F_34 ( V_75 , V_76 ) ;
return 4 ;
}
return - V_41 ;
}
