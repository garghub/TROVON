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
int F_11 ( struct V_1 * V_2 , struct V_4 * V_5 ,
struct V_4 * V_23 )
{
struct V_24 * V_3 = & V_2 -> V_3 [ V_5 -> V_3 ] ;
bool V_25 = false ;
int V_9 , V_10 = 0 ;
if ( ! V_5 -> V_26 || ! V_3 -> V_27 ) {
F_3 ( V_2 -> V_13 , L_2 ) ;
return - V_28 ;
}
V_10 = F_12 ( V_2 , V_3 , 64 + V_21 * 8 ) ;
if ( V_10 ) {
F_3 ( V_2 -> V_13 , L_3 , V_10 ) ;
return V_10 ;
}
for ( V_9 = 0 ; V_9 < V_21 ; ++ V_9 ) {
struct V_29 * V_15 = V_5 -> V_22 [ V_9 ] ;
if ( F_13 ( V_15 , V_5 -> V_3 ) ) {
V_25 = true ;
F_14 ( V_2 , V_5 -> V_14 ,
V_15 -> V_3 , V_5 -> V_3 ) ;
F_15 ( V_15 , V_5 -> V_3 ) ;
}
}
if ( ! V_25 ) {
F_8 ( V_2 , & V_5 -> V_14 , NULL ) ;
}
if ( V_5 -> V_7 && ! V_5 -> V_7 -> V_30 ) {
F_16 ( V_2 , V_5 -> V_3 , V_5 -> V_7 ) ;
}
if ( V_23 ) {
F_17 ( V_2 , V_23 -> V_3 , V_23 ) ;
F_8 ( V_2 , & V_23 -> V_14 , NULL ) ;
}
F_17 ( V_2 , V_5 -> V_3 , V_5 ) ;
V_10 = F_18 ( V_2 , & V_5 -> V_15 , V_5 -> V_3 ) ;
if ( V_10 ) {
F_3 ( V_2 -> V_13 , L_4 , V_10 ) ;
F_19 ( V_2 , V_3 ) ;
return V_10 ;
}
if ( V_23 ) {
V_23 -> V_15 = F_20 ( V_5 -> V_15 ) ;
}
if ( V_5 -> V_7 && ! V_5 -> V_7 -> V_30 ) {
V_5 -> V_7 -> V_30 = F_20 ( V_5 -> V_15 ) ;
}
F_21 ( V_2 , V_3 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 )
{
int V_10 ;
if ( V_2 -> V_31 ) {
return 0 ;
}
V_10 = F_23 ( V_2 , & V_2 -> V_11 ,
V_32 * 64 * 1024 ,
V_33 ) ;
if ( V_10 ) {
return V_10 ;
}
V_10 = F_24 ( V_2 , & V_2 -> V_11 ) ;
if ( V_10 ) {
return V_10 ;
}
V_2 -> V_31 = true ;
if ( F_25 ( V_2 ) ) {
F_3 ( V_2 -> V_13 , L_5 ) ;
}
return 0 ;
}
void F_26 ( struct V_1 * V_2 )
{
if ( V_2 -> V_31 ) {
F_27 ( V_2 , & V_2 -> V_11 ) ;
F_28 ( V_2 , & V_2 -> V_11 ) ;
V_2 -> V_31 = false ;
}
}
int F_29 ( struct V_1 * V_2 )
{
unsigned V_9 ;
int V_10 ;
for ( V_9 = 0 ; V_9 < V_21 ; ++ V_9 ) {
struct V_24 * V_3 = & V_2 -> V_3 [ V_9 ] ;
if ( ! V_3 -> V_27 )
continue;
V_10 = F_30 ( V_2 , V_9 , V_3 ) ;
if ( V_10 ) {
V_3 -> V_27 = false ;
if ( V_9 == V_34 ) {
F_31 ( L_6 , V_10 ) ;
V_2 -> V_35 = false ;
return V_10 ;
} else {
F_31 ( L_7 , V_9 , V_10 ) ;
}
}
}
return 0 ;
}
void F_32 ( struct V_24 * V_3 , T_1 V_36 )
{
#if V_37
if ( V_3 -> V_38 <= 0 ) {
F_31 ( L_8 ) ;
}
#endif
V_3 -> V_3 [ V_3 -> V_39 ++ ] = V_36 ;
V_3 -> V_39 &= V_3 -> V_40 ;
V_3 -> V_38 -- ;
V_3 -> V_41 -- ;
}
bool F_33 ( struct V_1 * V_2 ,
struct V_24 * V_3 )
{
switch ( V_3 -> V_42 ) {
case V_34 :
case V_43 :
case V_44 :
return true ;
default:
return false ;
}
}
void F_34 ( struct V_1 * V_2 , struct V_24 * V_3 )
{
T_2 V_45 ;
if ( V_2 -> V_46 . V_47 )
V_45 = F_35 ( V_2 -> V_46 . V_46 [ V_3 -> V_48 / 4 ] ) ;
else
V_45 = F_36 ( V_3 -> V_49 ) ;
V_3 -> V_45 = ( V_45 & V_3 -> V_50 ) >> V_3 -> V_51 ;
V_3 -> V_41 = ( V_3 -> V_45 + ( V_3 -> V_52 / 4 ) ) ;
V_3 -> V_41 -= V_3 -> V_39 ;
V_3 -> V_41 &= V_3 -> V_40 ;
if ( ! V_3 -> V_41 ) {
V_3 -> V_41 = V_3 -> V_52 / 4 ;
}
}
int F_37 ( struct V_1 * V_2 , struct V_24 * V_3 , unsigned V_53 )
{
int V_10 ;
V_53 = ( V_53 + V_3 -> V_54 ) & ~ V_3 -> V_54 ;
while ( V_53 > ( V_3 -> V_41 - 1 ) ) {
F_34 ( V_2 , V_3 ) ;
if ( V_53 < V_3 -> V_41 ) {
break;
}
V_10 = F_38 ( V_2 , V_3 -> V_42 ) ;
if ( V_10 )
return V_10 ;
}
V_3 -> V_38 = V_53 ;
V_3 -> V_55 = V_3 -> V_39 ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 , struct V_24 * V_3 , unsigned V_53 )
{
int V_10 ;
F_39 ( & V_2 -> V_56 ) ;
V_10 = F_37 ( V_2 , V_3 , V_53 ) ;
if ( V_10 ) {
F_40 ( & V_2 -> V_56 ) ;
return V_10 ;
}
return 0 ;
}
void F_41 ( struct V_1 * V_2 , struct V_24 * V_3 )
{
while ( V_3 -> V_39 & V_3 -> V_54 ) {
F_32 ( V_3 , V_3 -> V_57 ) ;
}
F_42 () ;
F_43 ( V_3 -> V_58 , ( V_3 -> V_39 << V_3 -> V_51 ) & V_3 -> V_50 ) ;
( void ) F_36 ( V_3 -> V_58 ) ;
}
void F_21 ( struct V_1 * V_2 , struct V_24 * V_3 )
{
F_41 ( V_2 , V_3 ) ;
F_40 ( & V_2 -> V_56 ) ;
}
void F_44 ( struct V_24 * V_3 )
{
V_3 -> V_39 = V_3 -> V_55 ;
}
void F_19 ( struct V_1 * V_2 , struct V_24 * V_3 )
{
F_44 ( V_3 ) ;
F_40 ( & V_2 -> V_56 ) ;
}
void F_45 ( struct V_1 * V_2 , struct V_24 * V_3 )
{
int V_10 ;
F_34 ( V_2 , V_3 ) ;
if ( V_3 -> V_45 == V_3 -> V_39 ) {
V_10 = F_37 ( V_2 , V_3 , 1 ) ;
if ( ! V_10 ) {
F_32 ( V_3 , V_3 -> V_57 ) ;
F_41 ( V_2 , V_3 ) ;
}
}
}
void F_46 ( struct V_24 * V_3 )
{
V_3 -> V_59 = V_3 -> V_45 ;
V_3 -> V_60 = V_61 ;
}
bool F_47 ( struct V_1 * V_2 , struct V_24 * V_3 )
{
unsigned long V_62 , V_63 ;
T_1 V_45 ;
V_62 = V_61 ;
if ( ! F_48 ( V_62 , V_3 -> V_60 ) ) {
F_46 ( V_3 ) ;
return false ;
}
V_45 = F_36 ( V_3 -> V_49 ) ;
V_3 -> V_45 = ( V_45 & V_3 -> V_50 ) >> V_3 -> V_51 ;
if ( V_3 -> V_45 != V_3 -> V_59 ) {
F_46 ( V_3 ) ;
return false ;
}
V_63 = F_49 ( V_62 - V_3 -> V_60 ) ;
if ( V_64 && V_63 >= V_64 ) {
F_3 ( V_2 -> V_13 , L_9 , V_63 ) ;
return true ;
}
return false ;
}
unsigned F_50 ( struct V_1 * V_2 , struct V_24 * V_3 ,
T_1 * * V_65 )
{
unsigned V_8 , V_16 , V_9 ;
F_39 ( & V_2 -> V_56 ) ;
* V_65 = NULL ;
if ( V_3 -> V_66 == NULL ) {
F_40 ( & V_2 -> V_56 ) ;
return 0 ;
}
if ( ! F_51 ( V_2 , V_3 -> V_42 ) ) {
F_40 ( & V_2 -> V_56 ) ;
return 0 ;
}
if ( V_3 -> V_67 )
V_16 = F_36 ( V_3 -> V_67 ) ;
else if ( V_2 -> V_46 . V_47 )
V_16 = F_35 ( * V_3 -> V_68 ) ;
else {
F_40 ( & V_2 -> V_56 ) ;
return 0 ;
}
V_8 = V_3 -> V_39 + ( V_3 -> V_52 / 4 ) ;
V_8 -= V_16 ;
V_8 &= V_3 -> V_40 ;
if ( V_8 == 0 ) {
F_40 ( & V_2 -> V_56 ) ;
return 0 ;
}
* V_65 = F_52 ( V_8 , sizeof( T_1 ) , V_69 ) ;
if ( ! * V_65 ) {
F_40 ( & V_2 -> V_56 ) ;
return 0 ;
}
for ( V_9 = 0 ; V_9 < V_8 ; ++ V_9 ) {
( * V_65 ) [ V_9 ] = V_3 -> V_3 [ V_16 ++ ] ;
V_16 &= V_3 -> V_40 ;
}
F_40 ( & V_2 -> V_56 ) ;
return V_8 ;
}
int F_53 ( struct V_1 * V_2 , struct V_24 * V_3 ,
unsigned V_8 , T_1 * V_65 )
{
int V_9 , V_10 ;
if ( ! V_8 || ! V_65 )
return 0 ;
V_10 = F_12 ( V_2 , V_3 , V_8 ) ;
if ( V_10 )
return V_10 ;
for ( V_9 = 0 ; V_9 < V_8 ; ++ V_9 ) {
F_32 ( V_3 , V_65 [ V_9 ] ) ;
}
F_21 ( V_2 , V_3 ) ;
F_54 ( V_65 ) ;
return 0 ;
}
int F_55 ( struct V_1 * V_2 , struct V_24 * V_3 , unsigned V_52 ,
unsigned V_48 , unsigned V_49 , unsigned V_58 ,
T_2 V_51 , T_2 V_50 , T_2 V_57 )
{
int V_10 ;
V_3 -> V_52 = V_52 ;
V_3 -> V_48 = V_48 ;
V_3 -> V_49 = V_49 ;
V_3 -> V_58 = V_58 ;
V_3 -> V_51 = V_51 ;
V_3 -> V_50 = V_50 ;
V_3 -> V_57 = V_57 ;
if ( V_3 -> V_66 == NULL ) {
V_10 = F_56 ( V_2 , V_3 -> V_52 , V_70 , true ,
V_33 ,
NULL , & V_3 -> V_66 ) ;
if ( V_10 ) {
F_3 ( V_2 -> V_13 , L_10 , V_10 ) ;
return V_10 ;
}
V_10 = F_57 ( V_3 -> V_66 , false ) ;
if ( F_58 ( V_10 != 0 ) )
return V_10 ;
V_10 = F_59 ( V_3 -> V_66 , V_33 ,
& V_3 -> V_17 ) ;
if ( V_10 ) {
F_60 ( V_3 -> V_66 ) ;
F_3 ( V_2 -> V_13 , L_11 , V_10 ) ;
return V_10 ;
}
V_10 = F_61 ( V_3 -> V_66 ,
( void * * ) & V_3 -> V_3 ) ;
F_60 ( V_3 -> V_66 ) ;
if ( V_10 ) {
F_3 ( V_2 -> V_13 , L_12 , V_10 ) ;
return V_10 ;
}
}
V_3 -> V_40 = ( V_3 -> V_52 / 4 ) - 1 ;
V_3 -> V_41 = V_3 -> V_52 / 4 ;
if ( V_2 -> V_46 . V_47 ) {
T_2 V_71 = V_72 + ( V_3 -> V_42 * 4 ) ;
V_3 -> V_73 = V_2 -> V_46 . V_17 + V_71 ;
V_3 -> V_68 = & V_2 -> V_46 . V_46 [ V_71 / 4 ] ;
}
if ( F_62 ( V_2 , V_3 ) ) {
F_31 ( L_13 ) ;
}
F_46 ( V_3 ) ;
return 0 ;
}
void F_63 ( struct V_1 * V_2 , struct V_24 * V_3 )
{
int V_10 ;
struct V_74 * V_66 ;
F_39 ( & V_2 -> V_56 ) ;
V_66 = V_3 -> V_66 ;
V_3 -> V_27 = false ;
V_3 -> V_3 = NULL ;
V_3 -> V_66 = NULL ;
F_40 ( & V_2 -> V_56 ) ;
if ( V_66 ) {
V_10 = F_57 ( V_66 , false ) ;
if ( F_64 ( V_10 == 0 ) ) {
F_65 ( V_66 ) ;
F_66 ( V_66 ) ;
F_60 ( V_66 ) ;
}
F_67 ( & V_66 ) ;
}
}
static int F_68 ( struct V_75 * V_76 , void * V_65 )
{
struct V_77 * V_78 = (struct V_77 * ) V_76 -> V_79 ;
struct V_80 * V_13 = V_78 -> V_81 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_82 ;
int V_83 = * ( int * ) V_78 -> V_84 -> V_65 ;
struct V_24 * V_3 = & V_2 -> V_3 [ V_83 ] ;
unsigned V_85 , V_9 , V_86 ;
F_34 ( V_2 , V_3 ) ;
V_85 = ( V_3 -> V_52 / 4 ) - V_3 -> V_41 ;
F_69 ( V_76 , L_14 , V_3 -> V_58 , F_36 ( V_3 -> V_58 ) ) ;
F_69 ( V_76 , L_15 , V_3 -> V_49 , F_36 ( V_3 -> V_49 ) ) ;
if ( V_3 -> V_67 ) {
F_69 ( V_76 , L_16 , V_3 -> V_67 ,
F_36 ( V_3 -> V_67 ) ) ;
}
F_69 ( V_76 , L_17 , V_3 -> V_39 ) ;
F_69 ( V_76 , L_18 , V_3 -> V_45 ) ;
F_69 ( V_76 , L_19 , V_3 -> V_41 ) ;
F_69 ( V_76 , L_20 , V_85 ) ;
V_9 = V_3 -> V_45 ;
for ( V_86 = 0 ; V_86 <= V_85 ; V_86 ++ ) {
F_69 ( V_76 , L_21 , V_9 , V_3 -> V_3 [ V_9 ] ) ;
V_9 = ( V_9 + 1 ) & V_3 -> V_40 ;
}
return 0 ;
}
static int F_70 ( struct V_75 * V_76 , void * V_65 )
{
struct V_77 * V_78 = (struct V_77 * ) V_76 -> V_79 ;
struct V_80 * V_13 = V_78 -> V_81 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_82 ;
F_71 ( & V_2 -> V_11 , V_76 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , struct V_24 * V_3 )
{
#if F_72 ( V_87 )
unsigned V_9 ;
for ( V_9 = 0 ; V_9 < F_73 ( V_88 ) ; ++ V_9 ) {
struct V_89 * V_90 = & V_88 [ V_9 ] ;
int V_83 = * ( int * ) V_88 [ V_9 ] . V_65 ;
unsigned V_10 ;
if ( & V_2 -> V_3 [ V_83 ] != V_3 )
continue;
V_10 = F_74 ( V_2 , V_90 , 1 ) ;
if ( V_10 )
return V_10 ;
}
#endif
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
#if F_72 ( V_87 )
return F_74 ( V_2 , V_91 , 1 ) ;
#else
return 0 ;
#endif
}
