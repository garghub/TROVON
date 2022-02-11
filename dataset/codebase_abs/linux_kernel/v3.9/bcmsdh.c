static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 . V_8 ;
F_3 ( V_9 , L_1 ) ;
if ( V_6 -> V_10 ) {
F_4 ( V_1 ) ;
V_6 -> V_10 = false ;
}
F_5 ( V_6 -> V_11 ) ;
return V_12 ;
}
int F_6 ( struct V_5 * V_6 )
{
int V_13 = 0 ;
T_2 V_14 ;
unsigned long V_15 ;
F_3 ( V_16 , L_2 , V_6 -> V_1 ) ;
V_13 = F_7 ( V_6 -> V_1 , F_1 ,
V_6 -> V_17 , L_3 ,
& V_6 -> V_18 [ 1 ] -> V_19 ) ;
if ( V_13 != 0 )
return V_13 ;
F_8 ( & V_6 -> V_20 ) ;
F_9 ( & V_6 -> V_20 , V_15 ) ;
V_6 -> V_10 = true ;
F_10 ( & V_6 -> V_20 , V_15 ) ;
V_13 = F_11 ( V_6 -> V_1 ) ;
if ( V_13 != 0 )
return V_13 ;
V_6 -> V_21 = true ;
F_12 ( V_6 -> V_18 [ 1 ] ) ;
V_14 = F_13 ( V_6 , V_22 , & V_13 ) ;
V_14 |= 1 << V_23 | 1 << V_24 | 1 ;
F_14 ( V_6 , V_22 , V_14 , & V_13 ) ;
V_14 = V_25 | V_26 ;
if ( V_6 -> V_17 & V_27 )
V_14 |= V_28 ;
F_14 ( V_6 , V_29 , V_14 , & V_13 ) ;
F_15 ( V_6 -> V_18 [ 1 ] ) ;
return 0 ;
}
int F_16 ( struct V_5 * V_6 )
{
F_3 ( V_16 , L_4 ) ;
F_12 ( V_6 -> V_18 [ 1 ] ) ;
F_14 ( V_6 , V_29 , 0 , NULL ) ;
F_14 ( V_6 , V_22 , 0 , NULL ) ;
F_15 ( V_6 -> V_18 [ 1 ] ) ;
if ( V_6 -> V_21 ) {
F_17 ( V_6 -> V_1 ) ;
V_6 -> V_21 = false ;
}
F_18 ( V_6 -> V_1 , & V_6 -> V_18 [ 1 ] -> V_19 ) ;
V_6 -> V_10 = false ;
return 0 ;
}
static void F_1 ( struct V_30 * V_18 )
{
struct V_3 * V_4 = F_2 ( & V_18 -> V_19 ) ;
struct V_5 * V_6 = V_4 -> V_7 . V_8 ;
F_3 ( V_9 , L_5 ) ;
F_5 ( V_6 -> V_11 ) ;
}
static void F_19 ( struct V_30 * V_18 )
{
}
int F_6 ( struct V_5 * V_6 )
{
F_3 ( V_16 , L_4 ) ;
F_12 ( V_6 -> V_18 [ 1 ] ) ;
F_20 ( V_6 -> V_18 [ 1 ] , F_1 ) ;
F_20 ( V_6 -> V_18 [ 2 ] , F_19 ) ;
F_15 ( V_6 -> V_18 [ 1 ] ) ;
return 0 ;
}
int F_16 ( struct V_5 * V_6 )
{
F_3 ( V_16 , L_4 ) ;
F_12 ( V_6 -> V_18 [ 1 ] ) ;
F_21 ( V_6 -> V_18 [ 2 ] ) ;
F_21 ( V_6 -> V_18 [ 1 ] ) ;
F_15 ( V_6 -> V_18 [ 1 ] ) ;
return 0 ;
}
int
F_22 ( struct V_5 * V_6 , T_3 V_31 )
{
int V_32 = 0 , V_33 ;
T_2 V_34 [ 3 ] ;
T_4 V_35 ;
V_34 [ 0 ] = ( V_31 >> 8 ) & V_36 ;
V_34 [ 1 ] = ( V_31 >> 16 ) & V_37 ;
V_34 [ 2 ] = ( V_31 >> 24 ) & V_38 ;
for ( V_33 = 0 ; V_33 < 3 ; V_33 ++ ) {
V_35 = 0 ;
do {
if ( V_35 )
F_23 ( 1000 , 2000 ) ;
V_32 = F_24 ( V_6 , V_39 ,
V_23 , V_40 + V_33 ,
& V_34 [ V_33 ] ) ;
} while ( V_32 != 0 && V_35 ++ < V_41 );
if ( V_32 ) {
F_25 ( L_6 ,
V_40 + V_33 ) ;
break;
}
}
return V_32 ;
}
int
F_26 ( struct V_5 * V_6 , T_3 V_34 ,
void * V_14 , bool V_42 )
{
T_2 V_43 , V_44 ;
T_3 V_45 ;
T_4 V_35 = 0 ;
int V_13 ;
if ( ( V_34 & ~ V_46 ) == 0 ) {
V_43 = V_47 ;
V_44 = 1 ;
} else if ( ( V_34 & ~ V_48 ) == 0 ) {
V_43 = V_23 ;
V_44 = 1 ;
} else {
V_43 = V_23 ;
V_44 = 4 ;
V_45 = V_34 & ~ V_49 ;
if ( V_45 != V_6 -> V_50 ) {
V_13 = F_22 ( V_6 , V_45 ) ;
if ( V_13 != 0 ) {
memset ( V_14 , 0xFF , V_44 ) ;
return V_13 ;
}
V_6 -> V_50 = V_45 ;
}
V_34 &= V_49 ;
V_34 |= V_51 ;
}
do {
if ( ! V_42 )
memset ( V_14 , 0 , V_44 ) ;
if ( V_35 )
F_23 ( 1000 , 2000 ) ;
if ( V_44 == 1 )
V_13 = F_24 ( V_6 , V_42 ,
V_43 , V_34 , V_14 ) ;
else
V_13 = F_27 ( V_6 , V_42 ,
V_43 , V_34 , V_14 , 4 ) ;
} while ( V_13 != 0 && V_35 ++ < V_41 );
if ( V_13 != 0 )
F_25 ( L_7 , V_13 ) ;
return V_13 ;
}
T_2 F_13 ( struct V_5 * V_6 , T_3 V_34 , int * V_13 )
{
T_2 V_14 ;
int V_52 ;
F_3 ( V_53 , L_8 , V_34 ) ;
V_52 = F_26 ( V_6 , V_34 , & V_14 , false ) ;
F_3 ( V_53 , L_9 , V_14 ) ;
if ( V_13 )
* V_13 = V_52 ;
return V_14 ;
}
T_3 F_28 ( struct V_5 * V_6 , T_3 V_34 , int * V_13 )
{
T_3 V_14 ;
int V_52 ;
F_3 ( V_53 , L_8 , V_34 ) ;
V_52 = F_26 ( V_6 , V_34 , & V_14 , false ) ;
F_3 ( V_53 , L_10 , V_14 ) ;
if ( V_13 )
* V_13 = V_52 ;
return V_14 ;
}
void F_14 ( struct V_5 * V_6 , T_3 V_34 ,
T_2 V_14 , int * V_13 )
{
int V_52 ;
F_3 ( V_53 , L_11 , V_34 , V_14 ) ;
V_52 = F_26 ( V_6 , V_34 , & V_14 , true ) ;
if ( V_13 )
* V_13 = V_52 ;
}
void F_29 ( struct V_5 * V_6 , T_3 V_34 ,
T_3 V_14 , int * V_13 )
{
int V_52 ;
F_3 ( V_53 , L_12 , V_34 , V_14 ) ;
V_52 = F_26 ( V_6 , V_34 , & V_14 , true ) ;
if ( V_13 )
* V_13 = V_52 ;
}
static int F_30 ( struct V_5 * V_6 , T_5 V_54 ,
T_5 V_15 , T_5 V_55 , T_3 * V_34 )
{
T_5 V_56 = * V_34 & ~ V_49 ;
int V_32 = 0 ;
if ( V_15 & V_57 )
return - V_58 ;
if ( V_56 != V_6 -> V_50 ) {
V_32 = F_22 ( V_6 , V_56 ) ;
if ( V_32 )
return V_32 ;
V_6 -> V_50 = V_56 ;
}
* V_34 &= V_49 ;
if ( V_55 == 4 )
* V_34 |= V_51 ;
return 0 ;
}
int
F_31 ( struct V_5 * V_6 , T_3 V_34 , T_5 V_54 ,
T_5 V_15 , T_2 * V_59 , T_5 V_60 )
{
struct V_61 * V_62 ;
int V_32 ;
V_62 = F_32 ( V_60 ) ;
if ( ! V_62 ) {
F_25 ( L_13 ,
V_60 ) ;
return - V_63 ;
}
V_32 = F_33 ( V_6 , V_34 , V_54 , V_15 , V_62 ) ;
if ( ! V_32 )
memcpy ( V_59 , V_62 -> V_14 , V_60 ) ;
F_34 ( V_62 ) ;
return V_32 ;
}
int
F_33 ( struct V_5 * V_6 , T_3 V_34 , T_5 V_54 ,
T_5 V_15 , struct V_61 * V_64 )
{
T_5 V_65 ;
T_5 V_55 ;
int V_32 = 0 ;
F_3 ( V_53 , L_14 ,
V_54 , V_34 , V_64 -> V_66 ) ;
V_55 = ( V_15 & V_67 ) ? 4 : 2 ;
V_32 = F_30 ( V_6 , V_54 , V_15 , V_55 , & V_34 ) ;
if ( V_32 )
goto V_68;
V_65 = ( V_15 & V_69 ) ? V_70 : V_71 ;
V_32 = F_35 ( V_6 , V_65 , V_72 ,
V_54 , V_34 , V_64 ) ;
V_68:
return V_32 ;
}
int F_36 ( struct V_5 * V_6 , T_3 V_34 , T_5 V_54 ,
T_5 V_15 , struct V_73 * V_74 )
{
T_5 V_65 ;
T_5 V_55 ;
int V_32 = 0 ;
F_3 ( V_53 , L_14 ,
V_54 , V_34 , V_74 -> V_75 ) ;
V_55 = ( V_15 & V_67 ) ? 4 : 2 ;
V_32 = F_30 ( V_6 , V_54 , V_15 , V_55 , & V_34 ) ;
if ( V_32 )
goto V_68;
V_65 = ( V_15 & V_69 ) ? V_70 : V_71 ;
V_32 = F_37 ( V_6 , V_65 , V_72 , V_54 , V_34 ,
V_74 ) ;
V_68:
return V_32 ;
}
int
F_38 ( struct V_5 * V_6 , T_3 V_34 , T_5 V_54 ,
T_5 V_15 , T_2 * V_59 , T_5 V_60 )
{
struct V_61 * V_62 ;
int V_32 ;
V_62 = F_32 ( V_60 ) ;
if ( ! V_62 ) {
F_25 ( L_13 ,
V_60 ) ;
return - V_63 ;
}
memcpy ( V_62 -> V_14 , V_59 , V_60 ) ;
V_32 = F_39 ( V_6 , V_34 , V_54 , V_15 , V_62 ) ;
F_34 ( V_62 ) ;
return V_32 ;
}
int
F_39 ( struct V_5 * V_6 , T_3 V_34 , T_5 V_54 ,
T_5 V_15 , struct V_61 * V_64 )
{
T_5 V_65 ;
T_5 V_55 ;
T_5 V_56 = V_34 & ~ V_49 ;
int V_32 = 0 ;
F_3 ( V_53 , L_14 ,
V_54 , V_34 , V_64 -> V_66 ) ;
if ( V_15 & V_57 )
return - V_58 ;
if ( V_56 != V_6 -> V_50 ) {
V_32 = F_22 ( V_6 , V_56 ) ;
if ( V_32 )
goto V_68;
V_6 -> V_50 = V_56 ;
}
V_34 &= V_49 ;
V_65 = ( V_15 & V_69 ) ? V_70 : V_71 ;
V_55 = ( V_15 & V_67 ) ? 4 : 2 ;
if ( V_55 == 4 )
V_34 |= V_51 ;
V_32 = F_35 ( V_6 , V_65 , V_39 , V_54 ,
V_34 , V_64 ) ;
V_68:
return V_32 ;
}
int F_40 ( struct V_5 * V_6 , T_5 V_76 , T_3 V_34 ,
T_2 * V_59 , T_5 V_60 )
{
struct V_61 * V_62 ;
bool V_42 = V_76 ? V_39 : V_72 ;
int V_32 ;
V_34 &= V_49 ;
V_34 |= V_51 ;
V_62 = F_32 ( V_60 ) ;
if ( ! V_62 ) {
F_25 ( L_13 ,
V_60 ) ;
return - V_63 ;
}
if ( V_42 )
memcpy ( V_62 -> V_14 , V_59 , V_60 ) ;
V_32 = F_35 ( V_6 , V_71 , V_42 ,
V_23 , V_34 , V_62 ) ;
if ( ! V_32 && ! V_42 )
memcpy ( V_59 , V_62 -> V_14 , V_60 ) ;
F_34 ( V_62 ) ;
return V_32 ;
}
int F_41 ( struct V_5 * V_6 , T_5 V_54 )
{
char V_77 = ( char ) V_54 ;
F_3 ( V_16 , L_15 ) ;
F_24 ( V_6 , V_39 , V_47 ,
V_78 , & V_77 ) ;
F_3 ( V_16 , L_16 ) ;
return 0 ;
}
int F_42 ( struct V_5 * V_6 )
{
T_3 V_79 = 0 ;
int V_13 = 0 ;
V_13 = F_43 ( V_6 ) ;
if ( V_13 )
goto V_80;
V_79 = V_81 ;
V_6 -> V_11 = F_44 ( V_79 , V_6 ) ;
if ( ! V_6 -> V_11 ) {
F_25 ( L_17 ) ;
V_13 = - V_82 ;
goto V_80;
}
V_80:
if ( V_13 )
F_45 ( V_6 ) ;
return V_13 ;
}
int F_45 ( struct V_5 * V_6 )
{
V_6 -> V_4 -> V_83 = V_84 ;
if ( V_6 -> V_11 ) {
F_46 ( V_6 -> V_11 ) ;
V_6 -> V_11 = NULL ;
}
F_47 ( V_6 ) ;
V_6 -> V_50 = 0 ;
return 0 ;
}
void F_48 ( struct V_5 * V_6 , bool V_85 )
{
if ( V_85 )
F_49 ( V_6 -> V_11 , V_86 ) ;
else
F_49 ( V_6 -> V_11 , 0 ) ;
}
