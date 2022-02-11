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
V_4 -> V_16 |= ( V_17 | V_18 ) ;
return F_2 ( V_4 , V_4 -> V_19 , V_4 -> V_14 ,
V_4 -> V_20 - V_4 -> V_19 ,
V_4 -> V_21 ) ;
}
static int F_3 ( struct V_22 * V_23 , int V_24 ,
struct V_3 * V_4 , int V_7 )
{
unsigned long V_25 , V_26 , V_27 ;
int V_28 = V_7 ? 5 : 0 ;
V_25 = ( V_4 -> V_20 - V_4 -> V_19 ) >> V_15 ;
V_26 = V_4 -> V_14 ;
V_27 = ( ( F_4 ( V_23 , V_24 ) - 1 ) >> ( V_15 - V_28 ) ) + 1 ;
if ( V_26 < V_27 && V_27 - V_26 >= V_25 )
return 1 ;
F_5 ( 1 , L_1
L_2 ,
V_29 -> V_30 , V_7 ? L_3 : L_4 , V_26 , V_26 + V_25 ,
F_6 ( V_23 ) , V_24 , V_27 ) ;
return 0 ;
}
static int F_7 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_3 * V_4 , int V_7 )
{
struct V_22 * V_23 = F_8 ( F_9 ( V_32 ,
struct V_35 , V_32 ) ) ;
struct V_36 * V_37 = V_34 -> V_38 ;
enum V_5 V_6 ;
struct V_39 V_40 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_42 ; V_41 ++ )
if ( V_37 == & V_23 -> V_36 [ V_41 ] )
break;
if ( V_41 >= V_42 )
return - V_43 ;
if ( ! F_3 ( V_23 , V_41 , V_4 , V_7 ) )
return - V_44 ;
if ( F_10 ( V_37 -> V_26 ) )
return - V_44 ;
F_11 ( V_23 , & V_40 , V_37 ) ;
V_4 -> V_14 += V_40 . V_26 >> ( V_15 - ( V_7 ? 5 : 0 ) ) ;
V_6 = V_37 -> V_45 & V_46 ? V_9 : V_47 ;
return F_1 ( V_23 -> V_48 , V_4 , V_6 , V_7 ) ;
}
static int F_12 ( struct V_49 * V_50 , struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_3 * V_4 )
{
return F_7 ( V_32 , V_34 , V_4 , 1 ) ;
}
static int F_13 ( struct V_49 * V_50 , struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_3 * V_4 )
{
return F_7 ( V_32 , V_34 , V_4 , 0 ) ;
}
void F_14 ( struct V_22 * V_23 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_42 ; V_41 ++ ) {
struct V_33 * V_51 ;
V_51 = V_23 -> V_51 [ V_41 ] ;
if ( V_51 ) {
F_15 ( & V_23 -> V_52 . V_32 , V_51 ) ;
F_16 ( V_51 ) ;
}
V_51 = V_23 -> V_53 [ V_41 ] ;
if ( V_51 ) {
F_15 ( & V_23 -> V_52 . V_32 , V_51 ) ;
F_16 ( V_51 ) ;
}
}
}
static int F_17 ( struct V_22 * V_23 , int V_24 )
{
struct V_39 V_40 ;
struct V_1 * V_2 = V_23 -> V_48 ;
long V_54 ;
unsigned long V_55 ;
F_11 ( V_23 , & V_40 , & V_23 -> V_36 [ V_24 ] ) ;
V_54 = ( long ) ( V_2 -> V_11 - V_2 -> V_10 ) ;
V_55 = V_54 >= 0x400000000UL ? 0x20000000 : 0x8000000 ;
return V_40 . V_56 < V_55 ;
}
static int F_18 ( struct V_22 * V_23 , int V_24 , char * V_57 ,
char * V_58 , struct V_33 * V_51 ,
unsigned long V_7 )
{
T_1 V_27 = F_4 ( V_23 , V_24 ) ;
sprintf ( V_57 , L_5 , V_24 , V_58 ) ;
V_51 -> V_59 = V_7 ? F_12 :
F_13 ;
V_51 -> V_34 . V_57 = V_57 ;
V_51 -> V_34 . V_60 = V_61 | V_62 ;
V_51 -> V_27 = V_7 ? V_27 << 5 : V_27 ;
V_51 -> V_38 = & V_23 -> V_36 [ V_24 ] ;
return F_19 ( & V_23 -> V_52 . V_32 , V_51 ) ;
}
static int F_20 ( struct V_22 * V_23 , int V_24 )
{
int V_63 , V_64 , V_65 = 0 , V_66 = 1 ;
unsigned long V_67 , V_68 ;
struct V_33 * V_34 ;
struct V_1 * V_2 = V_23 -> V_48 ;
char * V_58 , * V_69 ;
V_58 = L_4 ;
V_64 = 10 ;
if ( V_23 -> V_36 [ V_24 ] . V_45 & V_46 ) {
V_67 = V_2 -> V_10 ;
V_68 = V_2 -> V_11 ;
if ( V_67 && ! F_17 ( V_23 , V_24 ) ) {
V_67 = 0 ;
V_58 = L_6 ;
V_64 = 16 ;
}
} else {
V_67 = V_2 -> V_12 ;
V_68 = V_2 -> V_13 ;
}
if ( V_67 ) {
V_58 = L_7 ;
V_64 = 17 ;
if ( V_68 ) {
V_65 = 16 ;
V_66 = 2 ;
}
}
V_34 = F_21 ( sizeof( * V_34 ) * V_66 + V_64 + V_65 , V_70 ) ;
if ( ! V_34 )
return - V_71 ;
V_69 = ( char * ) ( V_34 + V_66 ) ;
V_23 -> V_51 [ V_24 ] = V_34 ;
V_63 = F_18 ( V_23 , V_24 , V_69 , V_58 , V_34 ,
V_67 ) ;
if ( V_63 || V_66 == 1 )
return V_63 ;
V_69 += V_64 ;
V_34 ++ ;
V_23 -> V_53 [ V_24 ] = V_34 ;
return F_18 ( V_23 , V_24 , V_69 , L_6 , V_34 , 0 ) ;
}
int F_22 ( struct V_22 * V_23 )
{
int V_41 ;
int V_63 ;
for ( V_41 = 0 ; V_41 < V_42 ; V_41 ++ ) {
if ( ! F_4 ( V_23 , V_41 ) )
continue;
V_63 = F_20 ( V_23 , V_41 ) ;
if ( V_63 ) {
F_14 ( V_23 ) ;
return V_63 ;
}
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned long V_72 , int V_7 )
{
unsigned long V_25 , V_26 , V_27 ;
V_25 = ( V_4 -> V_20 - V_4 -> V_19 ) >> V_15 ;
V_26 = V_4 -> V_14 ;
V_27 = ( ( V_72 - 1 ) >> V_15 ) + 1 ;
if ( V_26 < V_27 && V_27 - V_26 >= V_25 )
return 1 ;
F_5 ( 1 , L_8
L_2 ,
V_29 -> V_30 , V_7 ? L_3 : L_4 , V_26 , V_26 + V_25 ,
V_2 -> V_73 , V_27 ) ;
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
int F_25 ( struct V_74 * V_75 , struct V_3 * V_4 ,
enum V_5 V_6 )
{
struct V_1 * V_2 = V_75 -> V_48 ;
int V_7 = F_24 ( V_2 , V_6 ) ;
unsigned long V_72 ;
V_72 = ( V_6 == V_9 ) ? V_75 -> V_76 -> V_27 :
V_75 -> V_77 -> V_27 ;
if ( ! F_23 ( V_2 , V_4 , V_72 , V_7 ) )
return - V_44 ;
return F_1 ( V_2 , V_4 , V_6 , V_7 ) ;
}
void F_26 ( struct V_74 * V_75 , enum V_5 V_6 )
{
struct V_1 * V_2 = V_75 -> V_48 ;
if ( ! F_24 ( V_2 , V_6 ) )
return;
if ( V_6 == V_9 ) {
V_75 -> V_76 -> V_34 . V_57 = L_9 ;
V_75 -> V_76 -> V_27 <<= 5 ;
} else {
V_75 -> V_77 -> V_34 . V_57 = L_10 ;
V_75 -> V_77 -> V_27 <<= 5 ;
}
return;
}
int F_27 ( struct V_74 * V_75 , T_2 V_78 , T_3 * V_79 , T_1 V_27 )
{
struct V_1 * V_2 = V_75 -> V_48 ;
V_78 += V_2 -> V_80 -> V_26 ;
switch( V_27 ) {
case 1 :
* ( ( V_81 * ) V_79 ) = F_28 ( V_78 ) ;
return 1 ;
case 2 :
if ( V_78 & 1 )
return - V_44 ;
* ( ( V_82 * ) V_79 ) = F_29 ( V_78 ) ;
return 2 ;
case 4 :
if ( V_78 & 3 )
return - V_44 ;
* ( ( T_3 * ) V_79 ) = F_30 ( V_78 ) ;
return 4 ;
}
return - V_44 ;
}
int F_31 ( struct V_74 * V_75 , T_2 V_78 , T_3 V_79 , T_1 V_27 )
{
struct V_1 * V_2 = V_75 -> V_48 ;
V_78 += V_2 -> V_80 -> V_26 ;
switch( V_27 ) {
case 1 :
F_32 ( V_78 , V_79 ) ;
return 1 ;
case 2 :
if ( V_78 & 1 )
return - V_44 ;
F_33 ( V_78 , V_79 ) ;
return 2 ;
case 4 :
if ( V_78 & 3 )
return - V_44 ;
F_34 ( V_78 , V_79 ) ;
return 4 ;
}
return - V_44 ;
}
