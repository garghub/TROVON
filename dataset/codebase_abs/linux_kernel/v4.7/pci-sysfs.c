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
if ( V_34 -> V_41 & V_42 && F_10 ( V_34 -> V_23 ) )
return - V_43 ;
if ( ! F_3 ( V_20 , V_38 , V_4 , V_7 ) )
return - V_43 ;
F_11 ( V_20 -> V_44 , & V_37 , V_34 ) ;
V_4 -> V_14 += V_37 . V_23 >> ( V_15 - ( V_7 ? 5 : 0 ) ) ;
V_6 = V_34 -> V_41 & V_42 ? V_9 : V_45 ;
return F_1 ( V_20 -> V_46 , V_4 , V_6 , V_7 ) ;
}
static int F_12 ( struct V_47 * V_48 , struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_3 * V_4 )
{
return F_7 ( V_29 , V_31 , V_4 , 1 ) ;
}
static int F_13 ( struct V_47 * V_48 , struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_3 * V_4 )
{
return F_7 ( V_29 , V_31 , V_4 , 0 ) ;
}
void F_14 ( struct V_19 * V_20 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ ) {
struct V_30 * V_49 ;
V_49 = V_20 -> V_49 [ V_38 ] ;
if ( V_49 ) {
F_15 ( & V_20 -> V_50 . V_29 , V_49 ) ;
F_16 ( V_49 ) ;
}
V_49 = V_20 -> V_51 [ V_38 ] ;
if ( V_49 ) {
F_15 ( & V_20 -> V_50 . V_29 , V_49 ) ;
F_16 ( V_49 ) ;
}
}
}
static int F_17 ( struct V_19 * V_20 , int V_21 )
{
struct V_36 V_37 ;
struct V_1 * V_2 = V_20 -> V_46 ;
long V_52 ;
unsigned long V_53 ;
F_11 ( V_20 -> V_44 , & V_37 , & V_20 -> V_33 [ V_21 ] ) ;
V_52 = ( long ) ( V_2 -> V_11 - V_2 -> V_10 ) ;
V_53 = V_52 >= 0x400000000UL ? 0x20000000 : 0x8000000 ;
return V_37 . V_54 < V_53 ;
}
static int F_18 ( struct V_19 * V_20 , int V_21 , char * V_55 ,
char * V_56 , struct V_30 * V_49 ,
unsigned long V_7 )
{
T_1 V_24 = F_4 ( V_20 , V_21 ) ;
sprintf ( V_55 , L_5 , V_21 , V_56 ) ;
V_49 -> V_57 = V_7 ? F_12 :
F_13 ;
V_49 -> V_31 . V_55 = V_55 ;
V_49 -> V_31 . V_58 = V_59 | V_60 ;
V_49 -> V_24 = V_7 ? V_24 << 5 : V_24 ;
V_49 -> V_35 = & V_20 -> V_33 [ V_21 ] ;
return F_19 ( & V_20 -> V_50 . V_29 , V_49 ) ;
}
static int F_20 ( struct V_19 * V_20 , int V_21 )
{
int V_61 , V_62 , V_63 = 0 , V_64 = 1 ;
unsigned long V_65 , V_66 ;
struct V_30 * V_31 ;
struct V_1 * V_2 = V_20 -> V_46 ;
char * V_56 , * V_67 ;
V_56 = L_4 ;
V_62 = 10 ;
if ( V_20 -> V_33 [ V_21 ] . V_41 & V_42 ) {
V_65 = V_2 -> V_10 ;
V_66 = V_2 -> V_11 ;
if ( V_65 && ! F_17 ( V_20 , V_21 ) ) {
V_65 = 0 ;
V_56 = L_6 ;
V_62 = 16 ;
}
} else {
V_65 = V_2 -> V_12 ;
V_66 = V_2 -> V_13 ;
}
if ( V_65 ) {
V_56 = L_7 ;
V_62 = 17 ;
if ( V_66 ) {
V_63 = 16 ;
V_64 = 2 ;
}
}
V_31 = F_21 ( sizeof( * V_31 ) * V_64 + V_62 + V_63 , V_68 ) ;
if ( ! V_31 )
return - V_69 ;
V_67 = ( char * ) ( V_31 + V_64 ) ;
V_20 -> V_49 [ V_21 ] = V_31 ;
V_61 = F_18 ( V_20 , V_21 , V_67 , V_56 , V_31 ,
V_65 ) ;
if ( V_61 || V_64 == 1 )
return V_61 ;
V_67 += V_62 ;
V_31 ++ ;
V_20 -> V_51 [ V_21 ] = V_31 ;
return F_18 ( V_20 , V_21 , V_67 , L_6 , V_31 , 0 ) ;
}
int F_22 ( struct V_19 * V_20 )
{
int V_38 ;
int V_61 ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ ) {
if ( ! F_4 ( V_20 , V_38 ) )
continue;
V_61 = F_20 ( V_20 , V_38 ) ;
if ( V_61 ) {
F_14 ( V_20 ) ;
return V_61 ;
}
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned long V_70 , int V_7 )
{
unsigned long V_22 , V_23 , V_24 ;
V_22 = ( V_4 -> V_17 - V_4 -> V_16 ) >> V_15 ;
V_23 = V_4 -> V_14 ;
V_24 = ( ( V_70 - 1 ) >> V_15 ) + 1 ;
if ( V_23 < V_24 && V_24 - V_23 >= V_22 )
return 1 ;
F_5 ( 1 , L_8
L_2 ,
V_26 -> V_27 , V_7 ? L_3 : L_4 , V_23 , V_23 + V_22 ,
V_2 -> V_71 , V_24 ) ;
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
int F_25 ( struct V_72 * V_44 , struct V_3 * V_4 ,
enum V_5 V_6 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
int V_7 = F_24 ( V_2 , V_6 ) ;
unsigned long V_70 ;
V_70 = ( V_6 == V_9 ) ? V_44 -> V_73 -> V_24 :
V_44 -> V_74 -> V_24 ;
if ( ! F_23 ( V_2 , V_4 , V_70 , V_7 ) )
return - V_43 ;
return F_1 ( V_2 , V_4 , V_6 , V_7 ) ;
}
void F_26 ( struct V_72 * V_44 , enum V_5 V_6 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
if ( ! F_24 ( V_2 , V_6 ) )
return;
if ( V_6 == V_9 ) {
V_44 -> V_73 -> V_31 . V_55 = L_9 ;
V_44 -> V_73 -> V_24 <<= 5 ;
} else {
V_44 -> V_74 -> V_31 . V_55 = L_10 ;
V_44 -> V_74 -> V_24 <<= 5 ;
}
return;
}
int F_27 ( struct V_72 * V_44 , T_2 V_75 , T_3 * V_76 , T_1 V_24 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
V_75 += V_2 -> V_77 -> V_23 ;
switch( V_24 ) {
case 1 :
* ( ( V_78 * ) V_76 ) = F_28 ( V_75 ) ;
return 1 ;
case 2 :
if ( V_75 & 1 )
return - V_43 ;
* ( ( V_79 * ) V_76 ) = F_29 ( V_75 ) ;
return 2 ;
case 4 :
if ( V_75 & 3 )
return - V_43 ;
* ( ( T_3 * ) V_76 ) = F_30 ( V_75 ) ;
return 4 ;
}
return - V_43 ;
}
int F_31 ( struct V_72 * V_44 , T_2 V_75 , T_3 V_76 , T_1 V_24 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
V_75 += V_2 -> V_77 -> V_23 ;
switch( V_24 ) {
case 1 :
F_32 ( V_75 , V_76 ) ;
return 1 ;
case 2 :
if ( V_75 & 1 )
return - V_43 ;
F_33 ( V_75 , V_76 ) ;
return 2 ;
case 4 :
if ( V_75 & 3 )
return - V_43 ;
F_34 ( V_75 , V_76 ) ;
return 4 ;
}
return - V_43 ;
}
