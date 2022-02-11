int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 , struct V_6 * V_7 ,
unsigned V_8 )
{
int V_9 , V_10 ;
V_10 = F_2 ( V_2 , & V_2 -> V_11 , & V_5 -> V_12 , V_8 , 256 , true ) ;
if ( V_10 ) {
F_3 ( V_2 -> V_13 , L_1 , V_10 ) ;
return V_10 ;
}
V_10 = F_4 ( V_2 , & V_5 -> V_14 ) ;
if ( V_10 ) {
return V_10 ;
}
V_5 -> V_3 = V_3 ;
V_5 -> V_15 = NULL ;
V_5 -> V_16 = F_5 ( V_5 -> V_12 ) ;
V_5 -> V_7 = V_7 ;
if ( V_7 ) {
V_5 -> V_17 = V_5 -> V_12 -> V_18 + V_19 ;
} else {
V_5 -> V_17 = F_6 ( V_5 -> V_12 ) ;
}
V_5 -> V_20 = false ;
for ( V_9 = 0 ; V_9 < V_21 ; ++ V_9 )
V_5 -> V_22 [ V_9 ] = NULL ;
return 0 ;
}
void F_7 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
F_8 ( V_2 , & V_5 -> V_14 , V_5 -> V_15 ) ;
F_9 ( V_2 , & V_5 -> V_12 , V_5 -> V_15 ) ;
F_10 ( & V_5 -> V_15 ) ;
}
void F_11 ( struct V_4 * V_5 , struct V_23 * V_15 )
{
struct V_23 * V_24 ;
if ( ! V_15 )
return;
V_24 = V_5 -> V_22 [ V_15 -> V_3 ] ;
V_5 -> V_22 [ V_15 -> V_3 ] = F_12 ( V_15 , V_24 ) ;
}
int F_13 ( struct V_1 * V_2 , struct V_4 * V_5 ,
struct V_4 * V_25 )
{
struct V_26 * V_3 = & V_2 -> V_3 [ V_5 -> V_3 ] ;
bool V_27 = false ;
int V_9 , V_10 = 0 ;
if ( ! V_5 -> V_28 || ! V_3 -> V_29 ) {
F_3 ( V_2 -> V_13 , L_2 ) ;
return - V_30 ;
}
V_10 = F_14 ( V_2 , V_3 , 64 + V_21 * 8 ) ;
if ( V_10 ) {
F_3 ( V_2 -> V_13 , L_3 , V_10 ) ;
return V_10 ;
}
for ( V_9 = 0 ; V_9 < V_21 ; ++ V_9 ) {
struct V_23 * V_15 = V_5 -> V_22 [ V_9 ] ;
if ( F_15 ( V_15 , V_5 -> V_3 ) ) {
V_27 = true ;
F_16 ( V_2 , V_5 -> V_14 ,
V_15 -> V_3 , V_5 -> V_3 ) ;
F_17 ( V_15 , V_5 -> V_3 ) ;
}
}
if ( ! V_27 ) {
F_8 ( V_2 , & V_5 -> V_14 , NULL ) ;
}
if ( V_5 -> V_7 ) {
F_18 ( V_2 , V_5 -> V_3 , V_5 -> V_7 ) ;
}
if ( V_25 ) {
F_19 ( V_2 , V_25 -> V_3 , V_25 ) ;
F_8 ( V_2 , & V_25 -> V_14 , NULL ) ;
}
F_19 ( V_2 , V_5 -> V_3 , V_5 ) ;
V_10 = F_20 ( V_2 , & V_5 -> V_15 , V_5 -> V_3 ) ;
if ( V_10 ) {
F_3 ( V_2 -> V_13 , L_4 , V_10 ) ;
F_21 ( V_2 , V_3 ) ;
return V_10 ;
}
if ( V_25 ) {
V_25 -> V_15 = F_22 ( V_5 -> V_15 ) ;
}
if ( V_5 -> V_7 && ! V_5 -> V_7 -> V_31 ) {
V_5 -> V_7 -> V_31 = F_22 ( V_5 -> V_15 ) ;
}
F_23 ( V_2 , V_3 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 )
{
int V_10 ;
if ( V_2 -> V_32 ) {
return 0 ;
}
V_10 = F_25 ( V_2 , & V_2 -> V_11 ,
V_33 * 64 * 1024 ,
V_34 ) ;
if ( V_10 ) {
return V_10 ;
}
V_10 = F_26 ( V_2 , & V_2 -> V_11 ) ;
if ( V_10 ) {
return V_10 ;
}
V_2 -> V_32 = true ;
if ( F_27 ( V_2 ) ) {
F_3 ( V_2 -> V_13 , L_5 ) ;
}
return 0 ;
}
void F_28 ( struct V_1 * V_2 )
{
if ( V_2 -> V_32 ) {
F_29 ( V_2 , & V_2 -> V_11 ) ;
F_30 ( V_2 , & V_2 -> V_11 ) ;
V_2 -> V_32 = false ;
}
}
int F_31 ( struct V_1 * V_2 )
{
unsigned V_9 ;
int V_10 ;
for ( V_9 = 0 ; V_9 < V_21 ; ++ V_9 ) {
struct V_26 * V_3 = & V_2 -> V_3 [ V_9 ] ;
if ( ! V_3 -> V_29 )
continue;
V_10 = F_32 ( V_2 , V_9 , V_3 ) ;
if ( V_10 ) {
V_3 -> V_29 = false ;
if ( V_9 == V_35 ) {
F_33 ( L_6 , V_10 ) ;
V_2 -> V_36 = false ;
return V_10 ;
} else {
F_33 ( L_7 , V_9 , V_10 ) ;
}
}
}
return 0 ;
}
void F_34 ( struct V_26 * V_3 , T_1 V_37 )
{
#if V_38
if ( V_3 -> V_39 <= 0 ) {
F_33 ( L_8 ) ;
}
#endif
V_3 -> V_3 [ V_3 -> V_40 ++ ] = V_37 ;
V_3 -> V_40 &= V_3 -> V_41 ;
V_3 -> V_39 -- ;
V_3 -> V_42 -- ;
}
bool F_35 ( struct V_1 * V_2 ,
struct V_26 * V_3 )
{
switch ( V_3 -> V_43 ) {
case V_35 :
case V_44 :
case V_45 :
return true ;
default:
return false ;
}
}
void F_36 ( struct V_1 * V_2 , struct V_26 * V_3 )
{
T_2 V_46 ;
if ( V_2 -> V_47 . V_48 && V_3 != & V_2 -> V_3 [ V_49 ] )
V_46 = F_37 ( V_2 -> V_47 . V_47 [ V_3 -> V_50 / 4 ] ) ;
else
V_46 = F_38 ( V_3 -> V_51 ) ;
V_3 -> V_46 = ( V_46 & V_3 -> V_52 ) >> V_3 -> V_53 ;
V_3 -> V_42 = ( V_3 -> V_46 + ( V_3 -> V_54 / 4 ) ) ;
V_3 -> V_42 -= V_3 -> V_40 ;
V_3 -> V_42 &= V_3 -> V_41 ;
if ( ! V_3 -> V_42 ) {
V_3 -> V_42 = V_3 -> V_54 / 4 ;
}
}
int F_39 ( struct V_1 * V_2 , struct V_26 * V_3 , unsigned V_55 )
{
int V_10 ;
if ( V_55 > ( V_3 -> V_54 / 4 ) )
return - V_56 ;
F_36 ( V_2 , V_3 ) ;
if ( V_3 -> V_42 == ( V_3 -> V_54 / 4 ) ) {
F_40 ( V_3 ) ;
}
V_55 = ( V_55 + V_3 -> V_57 ) & ~ V_3 -> V_57 ;
while ( V_55 > ( V_3 -> V_42 - 1 ) ) {
F_36 ( V_2 , V_3 ) ;
if ( V_55 < V_3 -> V_42 ) {
break;
}
V_10 = F_41 ( V_2 , V_3 -> V_43 ) ;
if ( V_10 )
return V_10 ;
}
V_3 -> V_39 = V_55 ;
V_3 -> V_58 = V_3 -> V_40 ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 , struct V_26 * V_3 , unsigned V_55 )
{
int V_10 ;
F_42 ( & V_2 -> V_59 ) ;
V_10 = F_39 ( V_2 , V_3 , V_55 ) ;
if ( V_10 ) {
F_43 ( & V_2 -> V_59 ) ;
return V_10 ;
}
return 0 ;
}
void F_44 ( struct V_1 * V_2 , struct V_26 * V_3 )
{
while ( V_3 -> V_40 & V_3 -> V_57 ) {
F_34 ( V_3 , V_3 -> V_60 ) ;
}
F_45 () ;
F_46 ( V_3 -> V_61 , ( V_3 -> V_40 << V_3 -> V_53 ) & V_3 -> V_52 ) ;
( void ) F_38 ( V_3 -> V_61 ) ;
}
void F_23 ( struct V_1 * V_2 , struct V_26 * V_3 )
{
F_44 ( V_2 , V_3 ) ;
F_43 ( & V_2 -> V_59 ) ;
}
void F_47 ( struct V_26 * V_3 )
{
V_3 -> V_40 = V_3 -> V_58 ;
}
void F_21 ( struct V_1 * V_2 , struct V_26 * V_3 )
{
F_47 ( V_3 ) ;
F_43 ( & V_2 -> V_59 ) ;
}
void F_48 ( struct V_1 * V_2 , struct V_26 * V_3 )
{
int V_10 ;
F_36 ( V_2 , V_3 ) ;
if ( V_3 -> V_46 == V_3 -> V_40 ) {
V_10 = F_39 ( V_2 , V_3 , 1 ) ;
if ( ! V_10 ) {
F_34 ( V_3 , V_3 -> V_60 ) ;
F_44 ( V_2 , V_3 ) ;
}
}
}
void F_40 ( struct V_26 * V_3 )
{
V_3 -> V_62 = V_3 -> V_46 ;
V_3 -> V_63 = V_64 ;
}
bool F_49 ( struct V_1 * V_2 , struct V_26 * V_3 )
{
unsigned long V_65 , V_66 ;
T_1 V_46 ;
V_65 = V_64 ;
if ( ! F_50 ( V_65 , V_3 -> V_63 ) ) {
F_40 ( V_3 ) ;
return false ;
}
V_46 = F_38 ( V_3 -> V_51 ) ;
V_3 -> V_46 = ( V_46 & V_3 -> V_52 ) >> V_3 -> V_53 ;
if ( V_3 -> V_46 != V_3 -> V_62 ) {
F_40 ( V_3 ) ;
return false ;
}
V_66 = F_51 ( V_65 - V_3 -> V_63 ) ;
if ( V_67 && V_66 >= V_67 ) {
F_3 ( V_2 -> V_13 , L_9 , V_66 ) ;
return true ;
}
return false ;
}
unsigned F_52 ( struct V_1 * V_2 , struct V_26 * V_3 ,
T_1 * * V_68 )
{
unsigned V_8 , V_16 , V_9 ;
F_42 ( & V_2 -> V_59 ) ;
* V_68 = NULL ;
if ( V_3 -> V_69 == NULL ) {
F_43 ( & V_2 -> V_59 ) ;
return 0 ;
}
if ( ! F_53 ( V_2 , V_3 -> V_43 ) ) {
F_43 ( & V_2 -> V_59 ) ;
return 0 ;
}
if ( V_3 -> V_70 )
V_16 = F_38 ( V_3 -> V_70 ) ;
else if ( V_2 -> V_47 . V_48 )
V_16 = F_37 ( * V_3 -> V_71 ) ;
else {
F_43 ( & V_2 -> V_59 ) ;
return 0 ;
}
V_8 = V_3 -> V_40 + ( V_3 -> V_54 / 4 ) ;
V_8 -= V_16 ;
V_8 &= V_3 -> V_41 ;
if ( V_8 == 0 ) {
F_43 ( & V_2 -> V_59 ) ;
return 0 ;
}
* V_68 = F_54 ( V_8 , sizeof( T_1 ) , V_72 ) ;
if ( ! * V_68 ) {
F_43 ( & V_2 -> V_59 ) ;
return 0 ;
}
for ( V_9 = 0 ; V_9 < V_8 ; ++ V_9 ) {
( * V_68 ) [ V_9 ] = V_3 -> V_3 [ V_16 ++ ] ;
V_16 &= V_3 -> V_41 ;
}
F_43 ( & V_2 -> V_59 ) ;
return V_8 ;
}
int F_55 ( struct V_1 * V_2 , struct V_26 * V_3 ,
unsigned V_8 , T_1 * V_68 )
{
int V_9 , V_10 ;
if ( ! V_8 || ! V_68 )
return 0 ;
V_10 = F_14 ( V_2 , V_3 , V_8 ) ;
if ( V_10 )
return V_10 ;
for ( V_9 = 0 ; V_9 < V_8 ; ++ V_9 ) {
F_34 ( V_3 , V_68 [ V_9 ] ) ;
}
F_23 ( V_2 , V_3 ) ;
F_56 ( V_68 ) ;
return 0 ;
}
int F_57 ( struct V_1 * V_2 , struct V_26 * V_3 , unsigned V_54 ,
unsigned V_50 , unsigned V_51 , unsigned V_61 ,
T_2 V_53 , T_2 V_52 , T_2 V_60 )
{
int V_10 ;
V_3 -> V_54 = V_54 ;
V_3 -> V_50 = V_50 ;
V_3 -> V_51 = V_51 ;
V_3 -> V_61 = V_61 ;
V_3 -> V_53 = V_53 ;
V_3 -> V_52 = V_52 ;
V_3 -> V_60 = V_60 ;
if ( V_3 -> V_69 == NULL ) {
V_10 = F_58 ( V_2 , V_3 -> V_54 , V_73 , true ,
V_34 ,
NULL , & V_3 -> V_69 ) ;
if ( V_10 ) {
F_3 ( V_2 -> V_13 , L_10 , V_10 ) ;
return V_10 ;
}
V_10 = F_59 ( V_3 -> V_69 , false ) ;
if ( F_60 ( V_10 != 0 ) )
return V_10 ;
V_10 = F_61 ( V_3 -> V_69 , V_34 ,
& V_3 -> V_17 ) ;
if ( V_10 ) {
F_62 ( V_3 -> V_69 ) ;
F_3 ( V_2 -> V_13 , L_11 , V_10 ) ;
return V_10 ;
}
V_10 = F_63 ( V_3 -> V_69 ,
( void * * ) & V_3 -> V_3 ) ;
F_62 ( V_3 -> V_69 ) ;
if ( V_10 ) {
F_3 ( V_2 -> V_13 , L_12 , V_10 ) ;
return V_10 ;
}
}
V_3 -> V_41 = ( V_3 -> V_54 / 4 ) - 1 ;
V_3 -> V_42 = V_3 -> V_54 / 4 ;
if ( V_2 -> V_47 . V_48 ) {
T_2 V_74 = V_75 + ( V_3 -> V_43 * 4 ) ;
V_3 -> V_76 = V_2 -> V_47 . V_17 + V_74 ;
V_3 -> V_71 = & V_2 -> V_47 . V_47 [ V_74 / 4 ] ;
}
if ( F_64 ( V_2 , V_3 ) ) {
F_33 ( L_13 ) ;
}
F_40 ( V_3 ) ;
return 0 ;
}
void F_65 ( struct V_1 * V_2 , struct V_26 * V_3 )
{
int V_10 ;
struct V_77 * V_69 ;
F_42 ( & V_2 -> V_59 ) ;
V_69 = V_3 -> V_69 ;
V_3 -> V_29 = false ;
V_3 -> V_3 = NULL ;
V_3 -> V_69 = NULL ;
F_43 ( & V_2 -> V_59 ) ;
if ( V_69 ) {
V_10 = F_59 ( V_69 , false ) ;
if ( F_66 ( V_10 == 0 ) ) {
F_67 ( V_69 ) ;
F_68 ( V_69 ) ;
F_62 ( V_69 ) ;
}
F_69 ( & V_69 ) ;
}
}
static int F_70 ( struct V_78 * V_79 , void * V_68 )
{
struct V_80 * V_81 = (struct V_80 * ) V_79 -> V_82 ;
struct V_83 * V_13 = V_81 -> V_84 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_85 ;
int V_86 = * ( int * ) V_81 -> V_87 -> V_68 ;
struct V_26 * V_3 = & V_2 -> V_3 [ V_86 ] ;
unsigned V_88 , V_9 , V_89 ;
T_2 V_90 ;
F_36 ( V_2 , V_3 ) ;
V_88 = ( V_3 -> V_54 / 4 ) - V_3 -> V_42 ;
V_90 = F_38 ( V_3 -> V_61 ) >> V_3 -> V_53 ;
F_71 ( V_79 , L_14 , V_3 -> V_61 , V_90 , V_90 ) ;
V_90 = F_38 ( V_3 -> V_51 ) >> V_3 -> V_53 ;
F_71 ( V_79 , L_15 , V_3 -> V_51 , V_90 , V_90 ) ;
if ( V_3 -> V_70 ) {
F_71 ( V_79 , L_16 , V_3 -> V_70 ,
F_38 ( V_3 -> V_70 ) ) ;
}
F_71 ( V_79 , L_17 , V_3 -> V_40 , V_3 -> V_40 ) ;
F_71 ( V_79 , L_18 , V_3 -> V_46 , V_3 -> V_46 ) ;
F_71 ( V_79 , L_19 , V_3 -> V_91 ) ;
F_71 ( V_79 , L_20 , V_3 -> V_92 ) ;
F_71 ( V_79 , L_21 , V_3 -> V_42 ) ;
F_71 ( V_79 , L_22 , V_88 ) ;
V_9 = ( V_3 -> V_46 + V_3 -> V_41 + 1 - 32 ) & V_3 -> V_41 ;
for ( V_89 = 0 ; V_89 <= ( V_88 + 32 ) ; V_89 ++ ) {
F_71 ( V_79 , L_23 , V_9 , V_3 -> V_3 [ V_9 ] ) ;
V_9 = ( V_9 + 1 ) & V_3 -> V_41 ;
}
return 0 ;
}
static int F_72 ( struct V_78 * V_79 , void * V_68 )
{
struct V_80 * V_81 = (struct V_80 * ) V_79 -> V_82 ;
struct V_83 * V_13 = V_81 -> V_84 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_85 ;
F_73 ( & V_2 -> V_11 , V_79 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 , struct V_26 * V_3 )
{
#if F_74 ( V_93 )
unsigned V_9 ;
for ( V_9 = 0 ; V_9 < F_75 ( V_94 ) ; ++ V_9 ) {
struct V_95 * V_96 = & V_94 [ V_9 ] ;
int V_86 = * ( int * ) V_94 [ V_9 ] . V_68 ;
unsigned V_10 ;
if ( & V_2 -> V_3 [ V_86 ] != V_3 )
continue;
V_10 = F_76 ( V_2 , V_96 , 1 ) ;
if ( V_10 )
return V_10 ;
}
#endif
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
#if F_74 ( V_93 )
return F_76 ( V_2 , V_97 , 1 ) ;
#else
return 0 ;
#endif
}
