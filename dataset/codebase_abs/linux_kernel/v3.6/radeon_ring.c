int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 , unsigned V_6 )
{
int V_7 , V_8 ;
V_8 = F_2 ( V_2 , & V_2 -> V_9 , & V_5 -> V_10 , V_6 , 256 , true ) ;
if ( V_8 ) {
F_3 ( V_2 -> V_11 , L_1 , V_8 ) ;
return V_8 ;
}
V_8 = F_4 ( V_2 , & V_5 -> V_12 ) ;
if ( V_8 ) {
return V_8 ;
}
V_5 -> V_3 = V_3 ;
V_5 -> V_13 = NULL ;
V_5 -> V_14 = F_5 ( V_5 -> V_10 ) ;
V_5 -> V_15 = F_6 ( V_5 -> V_10 ) ;
V_5 -> V_16 = 0 ;
V_5 -> V_17 = false ;
for ( V_7 = 0 ; V_7 < V_18 ; ++ V_7 )
V_5 -> V_19 [ V_7 ] = NULL ;
return 0 ;
}
void F_7 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
F_8 ( V_2 , & V_5 -> V_12 , V_5 -> V_13 ) ;
F_9 ( V_2 , & V_5 -> V_10 , V_5 -> V_13 ) ;
F_10 ( & V_5 -> V_13 ) ;
}
int F_11 ( struct V_1 * V_2 , struct V_4 * V_5 ,
struct V_4 * V_20 )
{
struct V_21 * V_3 = & V_2 -> V_3 [ V_5 -> V_3 ] ;
bool V_22 = false ;
int V_7 , V_8 = 0 ;
if ( ! V_5 -> V_23 || ! V_3 -> V_24 ) {
F_3 ( V_2 -> V_11 , L_2 ) ;
return - V_25 ;
}
V_8 = F_12 ( V_2 , V_3 , 64 + V_18 * 8 ) ;
if ( V_8 ) {
F_3 ( V_2 -> V_11 , L_3 , V_8 ) ;
return V_8 ;
}
for ( V_7 = 0 ; V_7 < V_18 ; ++ V_7 ) {
struct V_26 * V_13 = V_5 -> V_19 [ V_7 ] ;
if ( F_13 ( V_13 , V_5 -> V_3 ) ) {
V_22 = true ;
F_14 ( V_2 , V_5 -> V_12 ,
V_13 -> V_3 , V_5 -> V_3 ) ;
F_15 ( V_13 , V_5 -> V_3 ) ;
}
}
if ( ! V_22 ) {
F_8 ( V_2 , & V_5 -> V_12 , NULL ) ;
}
if ( V_20 ) {
F_16 ( V_2 , V_20 -> V_3 , V_20 ) ;
F_8 ( V_2 , & V_20 -> V_12 , NULL ) ;
}
F_16 ( V_2 , V_5 -> V_3 , V_5 ) ;
V_8 = F_17 ( V_2 , & V_5 -> V_13 , V_5 -> V_3 ) ;
if ( V_8 ) {
F_3 ( V_2 -> V_11 , L_4 , V_8 ) ;
F_18 ( V_2 , V_3 ) ;
return V_8 ;
}
if ( V_20 ) {
V_20 -> V_13 = F_19 ( V_5 -> V_13 ) ;
}
F_20 ( V_2 , V_3 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
int V_8 ;
if ( V_2 -> V_27 ) {
return 0 ;
}
V_8 = F_22 ( V_2 , & V_2 -> V_9 ,
V_28 * 64 * 1024 ,
V_29 ) ;
if ( V_8 ) {
return V_8 ;
}
V_8 = F_23 ( V_2 , & V_2 -> V_9 ) ;
if ( V_8 ) {
return V_8 ;
}
V_2 -> V_27 = true ;
if ( F_24 ( V_2 ) ) {
F_3 ( V_2 -> V_11 , L_5 ) ;
}
return 0 ;
}
void F_25 ( struct V_1 * V_2 )
{
if ( V_2 -> V_27 ) {
F_26 ( V_2 , & V_2 -> V_9 ) ;
F_27 ( V_2 , & V_2 -> V_9 ) ;
V_2 -> V_27 = false ;
}
}
int F_28 ( struct V_1 * V_2 )
{
unsigned V_7 ;
int V_8 ;
for ( V_7 = 0 ; V_7 < V_18 ; ++ V_7 ) {
struct V_21 * V_3 = & V_2 -> V_3 [ V_7 ] ;
if ( ! V_3 -> V_24 )
continue;
V_8 = F_29 ( V_2 , V_7 , V_3 ) ;
if ( V_8 ) {
V_3 -> V_24 = false ;
if ( V_7 == V_30 ) {
F_30 ( L_6 , V_8 ) ;
V_2 -> V_31 = false ;
return V_8 ;
} else {
F_30 ( L_7 , V_7 , V_8 ) ;
}
}
}
return 0 ;
}
void F_31 ( struct V_21 * V_3 , T_1 V_32 )
{
#if V_33
if ( V_3 -> V_34 <= 0 ) {
F_30 ( L_8 ) ;
}
#endif
V_3 -> V_3 [ V_3 -> V_35 ++ ] = V_32 ;
V_3 -> V_35 &= V_3 -> V_36 ;
V_3 -> V_34 -- ;
V_3 -> V_37 -- ;
}
bool F_32 ( struct V_1 * V_2 ,
struct V_21 * V_3 )
{
switch ( V_3 -> V_38 ) {
case V_30 :
case V_39 :
case V_40 :
return true ;
default:
return false ;
}
}
void F_33 ( struct V_1 * V_2 , struct V_21 * V_3 )
{
T_2 V_41 ;
if ( V_2 -> V_42 . V_43 )
V_41 = F_34 ( V_2 -> V_42 . V_42 [ V_3 -> V_44 / 4 ] ) ;
else
V_41 = F_35 ( V_3 -> V_45 ) ;
V_3 -> V_41 = ( V_41 & V_3 -> V_46 ) >> V_3 -> V_47 ;
V_3 -> V_37 = ( V_3 -> V_41 + ( V_3 -> V_48 / 4 ) ) ;
V_3 -> V_37 -= V_3 -> V_35 ;
V_3 -> V_37 &= V_3 -> V_36 ;
if ( ! V_3 -> V_37 ) {
V_3 -> V_37 = V_3 -> V_48 / 4 ;
}
}
int F_36 ( struct V_1 * V_2 , struct V_21 * V_3 , unsigned V_49 )
{
int V_8 ;
V_49 = ( V_49 + V_3 -> V_50 ) & ~ V_3 -> V_50 ;
while ( V_49 > ( V_3 -> V_37 - 1 ) ) {
F_33 ( V_2 , V_3 ) ;
if ( V_49 < V_3 -> V_37 ) {
break;
}
V_8 = F_37 ( V_2 , V_3 -> V_38 ) ;
if ( V_8 )
return V_8 ;
}
V_3 -> V_34 = V_49 ;
V_3 -> V_51 = V_3 -> V_35 ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 , struct V_21 * V_3 , unsigned V_49 )
{
int V_8 ;
F_38 ( & V_2 -> V_52 ) ;
V_8 = F_36 ( V_2 , V_3 , V_49 ) ;
if ( V_8 ) {
F_39 ( & V_2 -> V_52 ) ;
return V_8 ;
}
return 0 ;
}
void F_40 ( struct V_1 * V_2 , struct V_21 * V_3 )
{
while ( V_3 -> V_35 & V_3 -> V_50 ) {
F_31 ( V_3 , V_3 -> V_53 ) ;
}
F_41 () ;
F_42 ( V_3 -> V_54 , ( V_3 -> V_35 << V_3 -> V_47 ) & V_3 -> V_46 ) ;
( void ) F_35 ( V_3 -> V_54 ) ;
}
void F_20 ( struct V_1 * V_2 , struct V_21 * V_3 )
{
F_40 ( V_2 , V_3 ) ;
F_39 ( & V_2 -> V_52 ) ;
}
void F_43 ( struct V_21 * V_3 )
{
V_3 -> V_35 = V_3 -> V_51 ;
}
void F_18 ( struct V_1 * V_2 , struct V_21 * V_3 )
{
F_43 ( V_3 ) ;
F_39 ( & V_2 -> V_52 ) ;
}
void F_44 ( struct V_1 * V_2 , struct V_21 * V_3 )
{
int V_8 ;
F_33 ( V_2 , V_3 ) ;
if ( V_3 -> V_41 == V_3 -> V_35 ) {
V_8 = F_36 ( V_2 , V_3 , 1 ) ;
if ( ! V_8 ) {
F_31 ( V_3 , V_3 -> V_53 ) ;
F_40 ( V_2 , V_3 ) ;
}
}
}
void F_45 ( struct V_21 * V_3 )
{
V_3 -> V_55 = V_3 -> V_41 ;
V_3 -> V_56 = V_57 ;
}
bool F_46 ( struct V_1 * V_2 , struct V_21 * V_3 )
{
unsigned long V_58 , V_59 ;
T_1 V_41 ;
V_58 = V_57 ;
if ( ! F_47 ( V_58 , V_3 -> V_56 ) ) {
F_45 ( V_3 ) ;
return false ;
}
V_41 = F_35 ( V_3 -> V_45 ) ;
V_3 -> V_41 = ( V_41 & V_3 -> V_46 ) >> V_3 -> V_47 ;
if ( V_3 -> V_41 != V_3 -> V_55 ) {
F_45 ( V_3 ) ;
return false ;
}
V_59 = F_48 ( V_58 - V_3 -> V_56 ) ;
if ( V_60 && V_59 >= V_60 ) {
F_3 ( V_2 -> V_11 , L_9 , V_59 ) ;
return true ;
}
return false ;
}
unsigned F_49 ( struct V_1 * V_2 , struct V_21 * V_3 ,
T_1 * * V_61 )
{
unsigned V_6 , V_14 , V_7 ;
F_38 ( & V_2 -> V_52 ) ;
* V_61 = NULL ;
if ( V_3 -> V_62 == NULL ) {
F_39 ( & V_2 -> V_52 ) ;
return 0 ;
}
if ( ! F_50 ( V_2 , V_3 -> V_38 ) ) {
F_39 ( & V_2 -> V_52 ) ;
return 0 ;
}
if ( V_3 -> V_63 )
V_14 = F_35 ( V_3 -> V_63 ) ;
else if ( V_2 -> V_42 . V_43 )
V_14 = F_34 ( * V_3 -> V_64 ) ;
else {
F_39 ( & V_2 -> V_52 ) ;
return 0 ;
}
V_6 = V_3 -> V_35 + ( V_3 -> V_48 / 4 ) ;
V_6 -= V_14 ;
V_6 &= V_3 -> V_36 ;
if ( V_6 == 0 ) {
F_39 ( & V_2 -> V_52 ) ;
return 0 ;
}
* V_61 = F_51 ( V_6 , sizeof( T_1 ) , V_65 ) ;
if ( ! * V_61 ) {
F_39 ( & V_2 -> V_52 ) ;
return 0 ;
}
for ( V_7 = 0 ; V_7 < V_6 ; ++ V_7 ) {
( * V_61 ) [ V_7 ] = V_3 -> V_3 [ V_14 ++ ] ;
V_14 &= V_3 -> V_36 ;
}
F_39 ( & V_2 -> V_52 ) ;
return V_6 ;
}
int F_52 ( struct V_1 * V_2 , struct V_21 * V_3 ,
unsigned V_6 , T_1 * V_61 )
{
int V_7 , V_8 ;
if ( ! V_6 || ! V_61 )
return 0 ;
V_8 = F_12 ( V_2 , V_3 , V_6 ) ;
if ( V_8 )
return V_8 ;
for ( V_7 = 0 ; V_7 < V_6 ; ++ V_7 ) {
F_31 ( V_3 , V_61 [ V_7 ] ) ;
}
F_20 ( V_2 , V_3 ) ;
F_53 ( V_61 ) ;
return 0 ;
}
int F_54 ( struct V_1 * V_2 , struct V_21 * V_3 , unsigned V_48 ,
unsigned V_44 , unsigned V_45 , unsigned V_54 ,
T_2 V_47 , T_2 V_46 , T_2 V_53 )
{
int V_8 ;
V_3 -> V_48 = V_48 ;
V_3 -> V_44 = V_44 ;
V_3 -> V_45 = V_45 ;
V_3 -> V_54 = V_54 ;
V_3 -> V_47 = V_47 ;
V_3 -> V_46 = V_46 ;
V_3 -> V_53 = V_53 ;
if ( V_3 -> V_62 == NULL ) {
V_8 = F_55 ( V_2 , V_3 -> V_48 , V_66 , true ,
V_29 ,
NULL , & V_3 -> V_62 ) ;
if ( V_8 ) {
F_3 ( V_2 -> V_11 , L_10 , V_8 ) ;
return V_8 ;
}
V_8 = F_56 ( V_3 -> V_62 , false ) ;
if ( F_57 ( V_8 != 0 ) )
return V_8 ;
V_8 = F_58 ( V_3 -> V_62 , V_29 ,
& V_3 -> V_15 ) ;
if ( V_8 ) {
F_59 ( V_3 -> V_62 ) ;
F_3 ( V_2 -> V_11 , L_11 , V_8 ) ;
return V_8 ;
}
V_8 = F_60 ( V_3 -> V_62 ,
( void * * ) & V_3 -> V_3 ) ;
F_59 ( V_3 -> V_62 ) ;
if ( V_8 ) {
F_3 ( V_2 -> V_11 , L_12 , V_8 ) ;
return V_8 ;
}
}
V_3 -> V_36 = ( V_3 -> V_48 / 4 ) - 1 ;
V_3 -> V_37 = V_3 -> V_48 / 4 ;
if ( V_2 -> V_42 . V_43 ) {
T_2 V_67 = V_68 + ( V_3 -> V_38 * 4 ) ;
V_3 -> V_69 = V_2 -> V_42 . V_15 + V_67 ;
V_3 -> V_64 = & V_2 -> V_42 . V_42 [ V_67 / 4 ] ;
}
if ( F_61 ( V_2 , V_3 ) ) {
F_30 ( L_13 ) ;
}
F_45 ( V_3 ) ;
return 0 ;
}
void F_62 ( struct V_1 * V_2 , struct V_21 * V_3 )
{
int V_8 ;
struct V_70 * V_62 ;
F_38 ( & V_2 -> V_52 ) ;
V_62 = V_3 -> V_62 ;
V_3 -> V_24 = false ;
V_3 -> V_3 = NULL ;
V_3 -> V_62 = NULL ;
F_39 ( & V_2 -> V_52 ) ;
if ( V_62 ) {
V_8 = F_56 ( V_62 , false ) ;
if ( F_63 ( V_8 == 0 ) ) {
F_64 ( V_62 ) ;
F_65 ( V_62 ) ;
F_59 ( V_62 ) ;
}
F_66 ( & V_62 ) ;
}
}
static int F_67 ( struct V_71 * V_72 , void * V_61 )
{
struct V_73 * V_74 = (struct V_73 * ) V_72 -> V_75 ;
struct V_76 * V_11 = V_74 -> V_77 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_78 ;
int V_79 = * ( int * ) V_74 -> V_80 -> V_61 ;
struct V_21 * V_3 = & V_2 -> V_3 [ V_79 ] ;
unsigned V_81 , V_7 , V_82 ;
F_33 ( V_2 , V_3 ) ;
V_81 = ( V_3 -> V_48 / 4 ) - V_3 -> V_37 ;
F_68 ( V_72 , L_14 , V_3 -> V_54 , F_35 ( V_3 -> V_54 ) ) ;
F_68 ( V_72 , L_15 , V_3 -> V_45 , F_35 ( V_3 -> V_45 ) ) ;
if ( V_3 -> V_63 ) {
F_68 ( V_72 , L_16 , V_3 -> V_63 ,
F_35 ( V_3 -> V_63 ) ) ;
}
F_68 ( V_72 , L_17 , V_3 -> V_35 ) ;
F_68 ( V_72 , L_18 , V_3 -> V_41 ) ;
F_68 ( V_72 , L_19 , V_3 -> V_37 ) ;
F_68 ( V_72 , L_20 , V_81 ) ;
V_7 = V_3 -> V_41 ;
for ( V_82 = 0 ; V_82 <= V_81 ; V_82 ++ ) {
F_68 ( V_72 , L_21 , V_7 , V_3 -> V_3 [ V_7 ] ) ;
V_7 = ( V_7 + 1 ) & V_3 -> V_36 ;
}
return 0 ;
}
static int F_69 ( struct V_71 * V_72 , void * V_61 )
{
struct V_73 * V_74 = (struct V_73 * ) V_72 -> V_75 ;
struct V_76 * V_11 = V_74 -> V_77 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_78 ;
F_70 ( & V_2 -> V_9 , V_72 ) ;
return 0 ;
}
int F_61 ( struct V_1 * V_2 , struct V_21 * V_3 )
{
#if F_71 ( V_83 )
unsigned V_7 ;
for ( V_7 = 0 ; V_7 < F_72 ( V_84 ) ; ++ V_7 ) {
struct V_85 * V_86 = & V_84 [ V_7 ] ;
int V_79 = * ( int * ) V_84 [ V_7 ] . V_61 ;
unsigned V_8 ;
if ( & V_2 -> V_3 [ V_79 ] != V_3 )
continue;
V_8 = F_73 ( V_2 , V_86 , 1 ) ;
if ( V_8 )
return V_8 ;
}
#endif
return 0 ;
}
int F_24 ( struct V_1 * V_2 )
{
#if F_71 ( V_83 )
return F_73 ( V_2 , V_87 , 1 ) ;
#else
return 0 ;
#endif
}
