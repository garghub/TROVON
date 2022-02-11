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
V_4 -> V_16 |= V_17 | V_18 | V_19 ;
return F_2 ( V_4 , V_4 -> V_20 , V_4 -> V_14 ,
V_4 -> V_21 - V_4 -> V_20 ,
V_4 -> V_22 ) ;
}
static int F_3 ( struct V_23 * V_24 , int V_25 ,
struct V_3 * V_4 , int V_7 )
{
unsigned long V_26 , V_27 , V_28 ;
int V_29 = V_7 ? 5 : 0 ;
V_26 = ( V_4 -> V_21 - V_4 -> V_20 ) >> V_15 ;
V_27 = V_4 -> V_14 ;
V_28 = ( ( F_4 ( V_24 , V_25 ) - 1 ) >> ( V_15 - V_29 ) ) + 1 ;
if ( V_27 < V_28 && V_28 - V_27 >= V_26 )
return 1 ;
F_5 ( 1 , L_1
L_2 ,
V_30 -> V_31 , V_7 ? L_3 : L_4 , V_27 , V_27 + V_26 ,
F_6 ( V_24 ) , V_25 , V_28 ) ;
return 0 ;
}
static int F_7 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
struct V_3 * V_4 , int V_7 )
{
struct V_23 * V_24 = F_8 ( F_9 ( V_33 ,
struct V_36 , V_33 ) ) ;
struct V_37 * V_38 = V_35 -> V_39 ;
enum V_5 V_6 ;
struct V_40 V_41 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ )
if ( V_38 == & V_24 -> V_37 [ V_42 ] )
break;
if ( V_42 >= V_43 )
return - V_44 ;
if ( ! F_3 ( V_24 , V_42 , V_4 , V_7 ) )
return - V_45 ;
if ( F_10 ( V_38 -> V_27 ) )
return - V_45 ;
F_11 ( V_24 , & V_41 , V_38 ) ;
V_4 -> V_14 += V_41 . V_27 >> ( V_15 - ( V_7 ? 5 : 0 ) ) ;
V_6 = V_38 -> V_46 & V_47 ? V_9 : V_48 ;
return F_1 ( V_24 -> V_49 , V_4 , V_6 , V_7 ) ;
}
static int F_12 ( struct V_50 * V_51 , struct V_32 * V_33 ,
struct V_34 * V_35 ,
struct V_3 * V_4 )
{
return F_7 ( V_33 , V_35 , V_4 , 1 ) ;
}
static int F_13 ( struct V_50 * V_51 , struct V_32 * V_33 ,
struct V_34 * V_35 ,
struct V_3 * V_4 )
{
return F_7 ( V_33 , V_35 , V_4 , 0 ) ;
}
void F_14 ( struct V_23 * V_24 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
struct V_34 * V_52 ;
V_52 = V_24 -> V_52 [ V_42 ] ;
if ( V_52 ) {
F_15 ( & V_24 -> V_53 . V_33 , V_52 ) ;
F_16 ( V_52 ) ;
}
V_52 = V_24 -> V_54 [ V_42 ] ;
if ( V_52 ) {
F_15 ( & V_24 -> V_53 . V_33 , V_52 ) ;
F_16 ( V_52 ) ;
}
}
}
static int F_17 ( struct V_23 * V_24 , int V_25 )
{
struct V_40 V_41 ;
struct V_1 * V_2 = V_24 -> V_49 ;
long V_55 ;
unsigned long V_56 ;
F_11 ( V_24 , & V_41 , & V_24 -> V_37 [ V_25 ] ) ;
V_55 = ( long ) ( V_2 -> V_11 - V_2 -> V_10 ) ;
V_56 = V_55 >= 0x400000000UL ? 0x20000000 : 0x8000000 ;
return V_41 . V_57 < V_56 ;
}
static int F_18 ( struct V_23 * V_24 , int V_25 , char * V_58 ,
char * V_59 , struct V_34 * V_52 ,
unsigned long V_7 )
{
T_1 V_28 = F_4 ( V_24 , V_25 ) ;
sprintf ( V_58 , L_5 , V_25 , V_59 ) ;
V_52 -> V_60 = V_7 ? F_12 :
F_13 ;
V_52 -> V_35 . V_58 = V_58 ;
V_52 -> V_35 . V_61 = V_62 | V_63 ;
V_52 -> V_28 = V_7 ? V_28 << 5 : V_28 ;
V_52 -> V_39 = & V_24 -> V_37 [ V_25 ] ;
return F_19 ( & V_24 -> V_53 . V_33 , V_52 ) ;
}
static int F_20 ( struct V_23 * V_24 , int V_25 )
{
int V_64 , V_65 , V_66 = 0 , V_67 = 1 ;
unsigned long V_68 , V_69 ;
struct V_34 * V_35 ;
struct V_1 * V_2 = V_24 -> V_49 ;
char * V_59 , * V_70 ;
V_59 = L_4 ;
V_65 = 10 ;
if ( V_24 -> V_37 [ V_25 ] . V_46 & V_47 ) {
V_68 = V_2 -> V_10 ;
V_69 = V_2 -> V_11 ;
if ( V_68 && ! F_17 ( V_24 , V_25 ) ) {
V_68 = 0 ;
V_59 = L_6 ;
V_65 = 16 ;
}
} else {
V_68 = V_2 -> V_12 ;
V_69 = V_2 -> V_13 ;
}
if ( V_68 ) {
V_59 = L_7 ;
V_65 = 17 ;
if ( V_69 ) {
V_66 = 16 ;
V_67 = 2 ;
}
}
V_35 = F_21 ( sizeof( * V_35 ) * V_67 + V_65 + V_66 , V_71 ) ;
if ( ! V_35 )
return - V_72 ;
V_70 = ( char * ) ( V_35 + V_67 ) ;
V_24 -> V_52 [ V_25 ] = V_35 ;
V_64 = F_18 ( V_24 , V_25 , V_70 , V_59 , V_35 ,
V_68 ) ;
if ( V_64 || V_67 == 1 )
return V_64 ;
V_70 += V_65 ;
V_35 ++ ;
V_24 -> V_54 [ V_25 ] = V_35 ;
return F_18 ( V_24 , V_25 , V_70 , L_6 , V_35 , 0 ) ;
}
int F_22 ( struct V_23 * V_24 )
{
int V_42 ;
int V_64 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
if ( ! F_4 ( V_24 , V_42 ) )
continue;
V_64 = F_20 ( V_24 , V_42 ) ;
if ( V_64 ) {
F_14 ( V_24 ) ;
return V_64 ;
}
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned long V_73 , int V_7 )
{
unsigned long V_26 , V_27 , V_28 ;
V_26 = ( V_4 -> V_21 - V_4 -> V_20 ) >> V_15 ;
V_27 = V_4 -> V_14 ;
V_28 = ( ( V_73 - 1 ) >> V_15 ) + 1 ;
if ( V_27 < V_28 && V_28 - V_27 >= V_26 )
return 1 ;
F_5 ( 1 , L_8
L_2 ,
V_30 -> V_31 , V_7 ? L_3 : L_4 , V_27 , V_27 + V_26 ,
V_2 -> V_74 , V_28 ) ;
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
int F_25 ( struct V_75 * V_76 , struct V_3 * V_4 ,
enum V_5 V_6 )
{
struct V_1 * V_2 = V_76 -> V_49 ;
int V_7 = F_24 ( V_2 , V_6 ) ;
unsigned long V_73 ;
V_73 = ( V_6 == V_9 ) ? V_76 -> V_77 -> V_28 :
V_76 -> V_78 -> V_28 ;
if ( ! F_23 ( V_2 , V_4 , V_73 , V_7 ) )
return - V_45 ;
return F_1 ( V_2 , V_4 , V_6 , V_7 ) ;
}
void F_26 ( struct V_75 * V_76 , enum V_5 V_6 )
{
struct V_1 * V_2 = V_76 -> V_49 ;
if ( ! F_24 ( V_2 , V_6 ) )
return;
if ( V_6 == V_9 ) {
V_76 -> V_77 -> V_35 . V_58 = L_9 ;
V_76 -> V_77 -> V_28 <<= 5 ;
} else {
V_76 -> V_78 -> V_35 . V_58 = L_10 ;
V_76 -> V_78 -> V_28 <<= 5 ;
}
return;
}
int F_27 ( struct V_75 * V_76 , T_2 V_79 , T_3 * V_80 , T_1 V_28 )
{
struct V_1 * V_2 = V_76 -> V_49 ;
V_79 += V_2 -> V_81 -> V_27 ;
switch( V_28 ) {
case 1 :
* ( ( V_82 * ) V_80 ) = F_28 ( V_79 ) ;
return 1 ;
case 2 :
if ( V_79 & 1 )
return - V_45 ;
* ( ( V_83 * ) V_80 ) = F_29 ( V_79 ) ;
return 2 ;
case 4 :
if ( V_79 & 3 )
return - V_45 ;
* ( ( T_3 * ) V_80 ) = F_30 ( V_79 ) ;
return 4 ;
}
return - V_45 ;
}
int F_31 ( struct V_75 * V_76 , T_2 V_79 , T_3 V_80 , T_1 V_28 )
{
struct V_1 * V_2 = V_76 -> V_49 ;
V_79 += V_2 -> V_81 -> V_27 ;
switch( V_28 ) {
case 1 :
F_32 ( V_79 , V_80 ) ;
return 1 ;
case 2 :
if ( V_79 & 1 )
return - V_45 ;
F_33 ( V_79 , V_80 ) ;
return 2 ;
case 4 :
if ( V_79 & 3 )
return - V_45 ;
F_34 ( V_79 , V_80 ) ;
return 4 ;
}
return - V_45 ;
}
