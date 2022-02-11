static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_5 , L_1 ) ;
if ( V_4 -> V_6 ) {
F_4 ( V_1 ) ;
V_4 -> V_6 = false ;
}
F_5 ( V_4 -> V_7 ) ;
return V_8 ;
}
int F_6 ( struct V_3 * V_4 )
{
int V_9 = 0 ;
T_2 V_10 ;
unsigned long V_11 ;
F_3 ( V_12 , L_2 ) ;
F_3 ( ERROR , L_3 , V_4 -> V_1 ) ;
V_9 = F_7 ( V_4 -> V_1 , F_1 ,
V_4 -> V_13 , L_4 ,
& V_4 -> V_14 [ 1 ] -> V_15 -> V_16 ) ;
if ( V_9 != 0 )
return V_9 ;
F_8 ( & V_4 -> V_17 ) ;
F_9 ( & V_4 -> V_17 , V_11 ) ;
V_4 -> V_6 = true ;
F_10 ( & V_4 -> V_17 , V_11 ) ;
V_9 = F_11 ( V_4 -> V_1 ) ;
if ( V_9 != 0 )
return V_9 ;
V_4 -> V_18 = true ;
V_10 = F_12 ( V_4 , V_19 , & V_9 ) ;
V_10 |= 1 << V_20 | 1 << V_21 | 1 ;
F_13 ( V_4 , V_19 , V_10 , & V_9 ) ;
V_10 = V_22 | V_23 ;
if ( V_4 -> V_13 & V_24 )
V_10 |= V_25 ;
F_13 ( V_4 , V_26 , V_10 , & V_9 ) ;
return 0 ;
}
int F_14 ( struct V_3 * V_4 )
{
F_3 ( V_12 , L_2 ) ;
F_13 ( V_4 , V_26 , 0 , NULL ) ;
F_13 ( V_4 , V_19 , 0 , NULL ) ;
if ( V_4 -> V_18 ) {
F_15 ( V_4 -> V_1 ) ;
V_4 -> V_18 = false ;
}
F_16 ( V_4 -> V_1 , & V_4 -> V_14 [ 1 ] -> V_15 -> V_16 ) ;
V_4 -> V_6 = false ;
return 0 ;
}
static void F_1 ( struct V_27 * V_14 )
{
struct V_3 * V_4 = F_2 ( & V_14 -> V_15 -> V_16 ) ;
F_3 ( V_5 , L_5 ) ;
F_5 ( V_4 -> V_7 ) ;
}
static void F_17 ( struct V_27 * V_14 )
{
}
int F_6 ( struct V_3 * V_4 )
{
F_3 ( V_12 , L_2 ) ;
F_18 ( V_4 -> V_14 [ 1 ] ) ;
F_19 ( V_4 -> V_14 [ 1 ] , F_1 ) ;
F_19 ( V_4 -> V_14 [ 2 ] , F_17 ) ;
F_20 ( V_4 -> V_14 [ 1 ] ) ;
return 0 ;
}
int F_14 ( struct V_3 * V_4 )
{
F_3 ( V_12 , L_2 ) ;
F_18 ( V_4 -> V_14 [ 1 ] ) ;
F_21 ( V_4 -> V_14 [ 2 ] ) ;
F_21 ( V_4 -> V_14 [ 1 ] ) ;
F_20 ( V_4 -> V_14 [ 1 ] ) ;
return 0 ;
}
int
F_22 ( struct V_3 * V_4 , T_3 V_28 )
{
int V_29 = 0 , V_30 ;
T_2 V_31 [ 3 ] ;
T_4 V_32 ;
V_31 [ 0 ] = ( V_28 >> 8 ) & V_33 ;
V_31 [ 1 ] = ( V_28 >> 16 ) & V_34 ;
V_31 [ 2 ] = ( V_28 >> 24 ) & V_35 ;
for ( V_30 = 0 ; V_30 < 3 ; V_30 ++ ) {
V_32 = 0 ;
do {
if ( V_32 )
F_23 ( 1000 , 2000 ) ;
V_29 = F_24 ( V_4 , V_36 ,
V_20 , V_37 + V_30 ,
& V_31 [ V_30 ] ) ;
} while ( V_29 != 0 && V_32 ++ < V_38 );
if ( V_29 ) {
F_3 ( ERROR , L_6 ,
V_37 + V_30 ) ;
break;
}
}
return V_29 ;
}
int
F_25 ( struct V_3 * V_4 , T_3 V_31 ,
void * V_10 , bool V_39 )
{
T_2 V_40 , V_41 ;
T_3 V_42 ;
T_4 V_32 = 0 ;
int V_9 ;
if ( ( V_31 & ~ V_43 ) == 0 ) {
V_40 = V_44 ;
V_41 = 1 ;
} else if ( ( V_31 & ~ V_45 ) == 0 ) {
V_40 = V_20 ;
V_41 = 1 ;
} else {
V_40 = V_20 ;
V_41 = 4 ;
V_42 = V_31 & ~ V_46 ;
if ( V_42 != V_4 -> V_47 ) {
V_9 = F_22 ( V_4 , V_42 ) ;
if ( V_9 != 0 ) {
memset ( V_10 , 0xFF , V_41 ) ;
return V_9 ;
}
V_4 -> V_47 = V_42 ;
}
V_31 &= V_46 ;
V_31 |= V_48 ;
}
do {
if ( ! V_39 )
memset ( V_10 , 0 , V_41 ) ;
if ( V_32 )
F_23 ( 1000 , 2000 ) ;
if ( V_41 == 1 )
V_9 = F_24 ( V_4 , V_39 ,
V_40 , V_31 , V_10 ) ;
else
V_9 = F_26 ( V_4 , V_39 ,
V_40 , V_31 , V_10 , 4 ) ;
} while ( V_9 != 0 && V_32 ++ < V_38 );
if ( V_9 != 0 )
F_3 ( ERROR , L_7 , V_9 ) ;
return V_9 ;
}
T_2 F_12 ( struct V_3 * V_4 , T_3 V_31 , int * V_9 )
{
T_2 V_10 ;
int V_49 ;
F_3 ( V_50 , L_8 , V_31 ) ;
F_18 ( V_4 -> V_14 [ 1 ] ) ;
V_49 = F_25 ( V_4 , V_31 , & V_10 , false ) ;
F_20 ( V_4 -> V_14 [ 1 ] ) ;
F_3 ( V_50 , L_9 , V_10 ) ;
if ( V_9 )
* V_9 = V_49 ;
return V_10 ;
}
T_3 F_27 ( struct V_3 * V_4 , T_3 V_31 , int * V_9 )
{
T_3 V_10 ;
int V_49 ;
F_3 ( V_50 , L_8 , V_31 ) ;
F_18 ( V_4 -> V_14 [ 1 ] ) ;
V_49 = F_25 ( V_4 , V_31 , & V_10 , false ) ;
F_20 ( V_4 -> V_14 [ 1 ] ) ;
F_3 ( V_50 , L_10 , V_10 ) ;
if ( V_9 )
* V_9 = V_49 ;
return V_10 ;
}
void F_13 ( struct V_3 * V_4 , T_3 V_31 ,
T_2 V_10 , int * V_9 )
{
int V_49 ;
F_3 ( V_50 , L_11 , V_31 , V_10 ) ;
F_18 ( V_4 -> V_14 [ 1 ] ) ;
V_49 = F_25 ( V_4 , V_31 , & V_10 , true ) ;
F_20 ( V_4 -> V_14 [ 1 ] ) ;
if ( V_9 )
* V_9 = V_49 ;
}
void F_28 ( struct V_3 * V_4 , T_3 V_31 ,
T_3 V_10 , int * V_9 )
{
int V_49 ;
F_3 ( V_50 , L_12 , V_31 , V_10 ) ;
F_18 ( V_4 -> V_14 [ 1 ] ) ;
V_49 = F_25 ( V_4 , V_31 , & V_10 , true ) ;
F_20 ( V_4 -> V_14 [ 1 ] ) ;
if ( V_9 )
* V_9 = V_49 ;
}
static int F_29 ( struct V_3 * V_4 , T_5 V_51 ,
T_5 V_11 , T_5 V_52 , T_3 * V_31 )
{
T_5 V_53 = * V_31 & ~ V_46 ;
int V_29 = 0 ;
if ( V_11 & V_54 )
return - V_55 ;
if ( V_53 != V_4 -> V_47 ) {
V_29 = F_22 ( V_4 , V_53 ) ;
if ( V_29 )
return V_29 ;
V_4 -> V_47 = V_53 ;
}
* V_31 &= V_46 ;
if ( V_52 == 4 )
* V_31 |= V_48 ;
return 0 ;
}
int
F_30 ( struct V_3 * V_4 , T_3 V_31 , T_5 V_51 ,
T_5 V_11 , T_2 * V_56 , T_5 V_57 )
{
struct V_58 * V_59 ;
int V_29 ;
V_59 = F_31 ( V_57 ) ;
if ( ! V_59 ) {
F_3 ( ERROR , L_13 ,
V_57 ) ;
return - V_60 ;
}
V_29 = F_32 ( V_4 , V_31 , V_51 , V_11 , V_59 ) ;
if ( ! V_29 )
memcpy ( V_56 , V_59 -> V_10 , V_57 ) ;
F_33 ( V_59 ) ;
return V_29 ;
}
int
F_32 ( struct V_3 * V_4 , T_3 V_31 , T_5 V_51 ,
T_5 V_11 , struct V_58 * V_61 )
{
T_5 V_62 ;
T_5 V_52 ;
int V_29 = 0 ;
F_3 ( V_50 , L_14 ,
V_51 , V_31 , V_61 -> V_63 ) ;
F_18 ( V_4 -> V_14 [ 1 ] ) ;
V_52 = ( V_11 & V_64 ) ? 4 : 2 ;
V_29 = F_29 ( V_4 , V_51 , V_11 , V_52 , & V_31 ) ;
if ( V_29 )
goto V_65;
V_62 = ( V_11 & V_66 ) ? V_67 : V_68 ;
V_29 = F_34 ( V_4 , V_62 , V_69 ,
V_51 , V_31 , V_61 ) ;
V_65:
F_20 ( V_4 -> V_14 [ 1 ] ) ;
return V_29 ;
}
int F_35 ( struct V_3 * V_4 , T_3 V_31 , T_5 V_51 ,
T_5 V_11 , struct V_70 * V_71 )
{
T_5 V_62 ;
T_5 V_52 ;
int V_29 = 0 ;
F_3 ( V_50 , L_14 ,
V_51 , V_31 , V_71 -> V_72 ) ;
F_18 ( V_4 -> V_14 [ 1 ] ) ;
V_52 = ( V_11 & V_64 ) ? 4 : 2 ;
V_29 = F_29 ( V_4 , V_51 , V_11 , V_52 , & V_31 ) ;
if ( V_29 )
goto V_65;
V_62 = ( V_11 & V_66 ) ? V_67 : V_68 ;
V_29 = F_36 ( V_4 , V_62 , V_69 , V_51 , V_31 ,
V_71 ) ;
V_65:
F_20 ( V_4 -> V_14 [ 1 ] ) ;
return V_29 ;
}
int
F_37 ( struct V_3 * V_4 , T_3 V_31 , T_5 V_51 ,
T_5 V_11 , T_2 * V_56 , T_5 V_57 )
{
struct V_58 * V_59 ;
int V_29 ;
V_59 = F_31 ( V_57 ) ;
if ( ! V_59 ) {
F_3 ( ERROR , L_13 ,
V_57 ) ;
return - V_60 ;
}
memcpy ( V_59 -> V_10 , V_56 , V_57 ) ;
V_29 = F_38 ( V_4 , V_31 , V_51 , V_11 , V_59 ) ;
F_33 ( V_59 ) ;
return V_29 ;
}
int
F_38 ( struct V_3 * V_4 , T_3 V_31 , T_5 V_51 ,
T_5 V_11 , struct V_58 * V_61 )
{
T_5 V_62 ;
T_5 V_52 ;
T_5 V_53 = V_31 & ~ V_46 ;
int V_29 = 0 ;
F_3 ( V_50 , L_14 ,
V_51 , V_31 , V_61 -> V_63 ) ;
if ( V_11 & V_54 )
return - V_55 ;
F_18 ( V_4 -> V_14 [ 1 ] ) ;
if ( V_53 != V_4 -> V_47 ) {
V_29 = F_22 ( V_4 , V_53 ) ;
if ( V_29 )
goto V_65;
V_4 -> V_47 = V_53 ;
}
V_31 &= V_46 ;
V_62 = ( V_11 & V_66 ) ? V_67 : V_68 ;
V_52 = ( V_11 & V_64 ) ? 4 : 2 ;
if ( V_52 == 4 )
V_31 |= V_48 ;
V_29 = F_34 ( V_4 , V_62 , V_36 , V_51 ,
V_31 , V_61 ) ;
V_65:
F_20 ( V_4 -> V_14 [ 1 ] ) ;
return V_29 ;
}
int F_39 ( struct V_3 * V_4 , T_5 V_73 , T_3 V_31 ,
T_2 * V_56 , T_5 V_57 )
{
struct V_58 * V_59 ;
bool V_39 = V_73 ? V_36 : V_69 ;
int V_29 ;
V_31 &= V_46 ;
V_31 |= V_48 ;
V_59 = F_31 ( V_57 ) ;
if ( ! V_59 ) {
F_3 ( ERROR , L_13 ,
V_57 ) ;
return - V_60 ;
}
if ( V_39 )
memcpy ( V_59 -> V_10 , V_56 , V_57 ) ;
V_29 = F_34 ( V_4 , V_68 , V_39 ,
V_20 , V_31 , V_59 ) ;
if ( ! V_29 && ! V_39 )
memcpy ( V_56 , V_59 -> V_10 , V_57 ) ;
F_33 ( V_59 ) ;
return V_29 ;
}
int F_40 ( struct V_3 * V_4 , T_5 V_51 )
{
char V_74 = ( char ) V_51 ;
F_3 ( V_12 , L_15 ) ;
F_18 ( V_4 -> V_14 [ 1 ] ) ;
F_24 ( V_4 , V_36 , V_44 ,
V_75 , & V_74 ) ;
F_20 ( V_4 -> V_14 [ 1 ] ) ;
F_3 ( V_12 , L_16 ) ;
return 0 ;
}
int F_41 ( struct V_3 * V_4 )
{
T_3 V_76 = 0 ;
int V_9 = 0 ;
V_9 = F_42 ( V_4 ) ;
if ( V_9 )
goto V_77;
V_76 = V_78 ;
V_4 -> V_47 = V_78 ;
V_4 -> V_7 = F_43 ( V_76 , V_4 ) ;
if ( ! V_4 -> V_7 ) {
F_3 ( ERROR , L_17 ) ;
V_9 = - V_79 ;
goto V_77;
}
V_77:
if ( V_9 )
F_44 ( V_4 ) ;
return V_9 ;
}
int F_44 ( struct V_3 * V_4 )
{
if ( V_4 -> V_7 ) {
F_45 ( V_4 -> V_7 ) ;
V_4 -> V_7 = NULL ;
}
F_46 ( V_4 ) ;
V_4 -> V_47 = 0 ;
return 0 ;
}
void F_47 ( struct V_3 * V_4 , bool V_80 )
{
if ( V_80 )
F_48 ( V_4 -> V_7 , V_81 ) ;
else
F_48 ( V_4 -> V_7 , 0 ) ;
}
