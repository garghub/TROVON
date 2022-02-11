int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 , struct V_6 * V_7 ,
unsigned V_8 )
{
int V_9 ;
V_9 = F_2 ( V_2 , & V_2 -> V_10 , & V_5 -> V_11 , V_8 , 256 ) ;
if ( V_9 ) {
F_3 ( V_2 -> V_12 , L_1 , V_9 ) ;
return V_9 ;
}
V_9 = F_4 ( V_2 , & V_5 -> V_13 ) ;
if ( V_9 ) {
return V_9 ;
}
V_5 -> V_3 = V_3 ;
V_5 -> V_14 = NULL ;
V_5 -> V_15 = F_5 ( V_5 -> V_11 ) ;
V_5 -> V_7 = V_7 ;
if ( V_7 ) {
V_5 -> V_16 = V_5 -> V_11 -> V_17 + V_18 ;
} else {
V_5 -> V_16 = F_6 ( V_5 -> V_11 ) ;
}
V_5 -> V_19 = false ;
return 0 ;
}
void F_7 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
F_8 ( V_2 , & V_5 -> V_13 , V_5 -> V_14 ) ;
F_9 ( V_2 , & V_5 -> V_11 , V_5 -> V_14 ) ;
F_10 ( & V_5 -> V_14 ) ;
}
int F_11 ( struct V_1 * V_2 , struct V_4 * V_5 ,
struct V_4 * V_20 )
{
struct V_21 * V_3 = & V_2 -> V_3 [ V_5 -> V_3 ] ;
int V_9 = 0 ;
if ( ! V_5 -> V_22 || ! V_3 -> V_23 ) {
F_3 ( V_2 -> V_12 , L_2 ) ;
return - V_24 ;
}
V_9 = F_12 ( V_2 , V_3 , 64 + V_25 * 8 ) ;
if ( V_9 ) {
F_3 ( V_2 -> V_12 , L_3 , V_9 ) ;
return V_9 ;
}
if ( V_5 -> V_7 ) {
struct V_26 * V_27 ;
V_27 = F_13 ( V_2 , V_5 -> V_7 , V_5 -> V_3 ) ;
F_14 ( V_5 -> V_13 , V_27 ) ;
}
V_9 = F_15 ( V_2 , V_5 -> V_13 , V_5 -> V_3 ) ;
if ( V_9 ) {
F_3 ( V_2 -> V_12 , L_4 , V_9 ) ;
F_16 ( V_2 , V_3 ) ;
return V_9 ;
}
if ( V_5 -> V_7 )
F_17 ( V_2 , V_5 -> V_7 , V_5 -> V_3 ) ;
if ( V_20 ) {
F_18 ( V_2 , V_20 -> V_3 , V_20 ) ;
F_8 ( V_2 , & V_20 -> V_13 , NULL ) ;
}
F_18 ( V_2 , V_5 -> V_3 , V_5 ) ;
V_9 = F_19 ( V_2 , & V_5 -> V_14 , V_5 -> V_3 ) ;
if ( V_9 ) {
F_3 ( V_2 -> V_12 , L_5 , V_9 ) ;
F_16 ( V_2 , V_3 ) ;
return V_9 ;
}
if ( V_20 ) {
V_20 -> V_14 = F_20 ( V_5 -> V_14 ) ;
}
if ( V_5 -> V_7 )
F_21 ( V_2 , V_5 -> V_7 , V_5 -> V_14 ) ;
F_22 ( V_2 , V_3 ) ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
int V_9 ;
if ( V_2 -> V_28 ) {
return 0 ;
}
V_9 = F_24 ( V_2 , & V_2 -> V_10 ,
V_29 * 64 * 1024 ,
V_30 ,
V_31 ) ;
if ( V_9 ) {
return V_9 ;
}
V_9 = F_25 ( V_2 , & V_2 -> V_10 ) ;
if ( V_9 ) {
return V_9 ;
}
V_2 -> V_28 = true ;
if ( F_26 ( V_2 ) ) {
F_3 ( V_2 -> V_12 , L_6 ) ;
}
return 0 ;
}
void F_27 ( struct V_1 * V_2 )
{
if ( V_2 -> V_28 ) {
F_28 ( V_2 , & V_2 -> V_10 ) ;
F_29 ( V_2 , & V_2 -> V_10 ) ;
V_2 -> V_28 = false ;
}
}
int F_30 ( struct V_1 * V_2 )
{
unsigned V_32 ;
int V_9 ;
for ( V_32 = 0 ; V_32 < V_33 ; ++ V_32 ) {
struct V_21 * V_3 = & V_2 -> V_3 [ V_32 ] ;
if ( ! V_3 -> V_23 )
continue;
V_9 = F_31 ( V_2 , V_32 , V_3 ) ;
if ( V_9 ) {
V_3 -> V_23 = false ;
V_2 -> V_34 = false ;
if ( V_32 == V_35 ) {
F_32 ( L_7 , V_9 ) ;
V_2 -> V_36 = false ;
return V_9 ;
} else {
F_32 ( L_8 , V_32 , V_9 ) ;
}
}
}
return 0 ;
}
void F_33 ( struct V_21 * V_3 , T_1 V_37 )
{
#if V_38
if ( V_3 -> V_39 <= 0 ) {
F_32 ( L_9 ) ;
}
#endif
V_3 -> V_3 [ V_3 -> V_40 ++ ] = V_37 ;
V_3 -> V_40 &= V_3 -> V_41 ;
V_3 -> V_39 -- ;
V_3 -> V_42 -- ;
}
bool F_34 ( struct V_1 * V_2 ,
struct V_21 * V_3 )
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
void F_35 ( struct V_1 * V_2 , struct V_21 * V_3 )
{
T_1 V_46 = F_36 ( V_2 , V_3 ) ;
V_3 -> V_42 = V_46 + ( V_3 -> V_47 / 4 ) ;
V_3 -> V_42 -= V_3 -> V_40 ;
V_3 -> V_42 &= V_3 -> V_41 ;
if ( ! V_3 -> V_42 ) {
V_3 -> V_42 = V_3 -> V_47 / 4 ;
F_37 ( V_2 , V_3 ) ;
}
}
int F_38 ( struct V_1 * V_2 , struct V_21 * V_3 , unsigned V_48 )
{
int V_9 ;
if ( V_48 > ( V_3 -> V_47 / 4 ) )
return - V_49 ;
F_35 ( V_2 , V_3 ) ;
V_48 = ( V_48 + V_3 -> V_50 ) & ~ V_3 -> V_50 ;
while ( V_48 > ( V_3 -> V_42 - 1 ) ) {
F_35 ( V_2 , V_3 ) ;
if ( V_48 < V_3 -> V_42 ) {
break;
}
V_9 = F_39 ( V_2 , V_3 -> V_43 ) ;
if ( V_9 )
return V_9 ;
}
V_3 -> V_39 = V_48 ;
V_3 -> V_51 = V_3 -> V_40 ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 , struct V_21 * V_3 , unsigned V_48 )
{
int V_9 ;
F_40 ( & V_2 -> V_52 ) ;
V_9 = F_38 ( V_2 , V_3 , V_48 ) ;
if ( V_9 ) {
F_41 ( & V_2 -> V_52 ) ;
return V_9 ;
}
return 0 ;
}
void F_42 ( struct V_1 * V_2 , struct V_21 * V_3 )
{
while ( V_3 -> V_40 & V_3 -> V_50 ) {
F_33 ( V_3 , V_3 -> V_53 ) ;
}
F_43 () ;
F_44 ( V_2 , V_3 ) ;
}
void F_22 ( struct V_1 * V_2 , struct V_21 * V_3 )
{
F_42 ( V_2 , V_3 ) ;
F_41 ( & V_2 -> V_52 ) ;
}
void F_45 ( struct V_21 * V_3 )
{
V_3 -> V_40 = V_3 -> V_51 ;
}
void F_16 ( struct V_1 * V_2 , struct V_21 * V_3 )
{
F_45 ( V_3 ) ;
F_41 ( & V_2 -> V_52 ) ;
}
void F_37 ( struct V_1 * V_2 ,
struct V_21 * V_3 )
{
F_46 ( & V_3 -> V_54 , F_36 ( V_2 , V_3 ) ) ;
F_47 ( & V_3 -> V_55 , V_56 ) ;
}
bool F_48 ( struct V_1 * V_2 , struct V_21 * V_3 )
{
T_1 V_46 = F_36 ( V_2 , V_3 ) ;
T_2 V_57 = F_49 ( & V_3 -> V_55 ) ;
T_2 V_58 ;
if ( V_46 != F_50 ( & V_3 -> V_54 ) ) {
F_37 ( V_2 , V_3 ) ;
return false ;
}
V_58 = F_51 ( V_56 - V_57 ) ;
if ( V_59 && V_58 >= V_59 ) {
F_3 ( V_2 -> V_12 , L_10 ,
V_3 -> V_43 , V_58 ) ;
return true ;
}
return false ;
}
unsigned F_52 ( struct V_1 * V_2 , struct V_21 * V_3 ,
T_1 * * V_60 )
{
unsigned V_8 , V_15 , V_32 ;
F_40 ( & V_2 -> V_52 ) ;
* V_60 = NULL ;
if ( V_3 -> V_61 == NULL ) {
F_41 ( & V_2 -> V_52 ) ;
return 0 ;
}
if ( ! F_53 ( V_2 , V_3 -> V_43 ) ) {
F_41 ( & V_2 -> V_52 ) ;
return 0 ;
}
if ( V_3 -> V_62 )
V_15 = F_54 ( V_3 -> V_62 ) ;
else if ( V_2 -> V_63 . V_64 )
V_15 = F_55 ( * V_3 -> V_65 ) ;
else {
F_41 ( & V_2 -> V_52 ) ;
return 0 ;
}
V_8 = V_3 -> V_40 + ( V_3 -> V_47 / 4 ) ;
V_8 -= V_15 ;
V_8 &= V_3 -> V_41 ;
if ( V_8 == 0 ) {
F_41 ( & V_2 -> V_52 ) ;
return 0 ;
}
* V_60 = F_56 ( V_8 , sizeof( T_1 ) , V_66 ) ;
if ( ! * V_60 ) {
F_41 ( & V_2 -> V_52 ) ;
return 0 ;
}
for ( V_32 = 0 ; V_32 < V_8 ; ++ V_32 ) {
( * V_60 ) [ V_32 ] = V_3 -> V_3 [ V_15 ++ ] ;
V_15 &= V_3 -> V_41 ;
}
F_41 ( & V_2 -> V_52 ) ;
return V_8 ;
}
int F_57 ( struct V_1 * V_2 , struct V_21 * V_3 ,
unsigned V_8 , T_1 * V_60 )
{
int V_32 , V_9 ;
if ( ! V_8 || ! V_60 )
return 0 ;
V_9 = F_12 ( V_2 , V_3 , V_8 ) ;
if ( V_9 )
return V_9 ;
for ( V_32 = 0 ; V_32 < V_8 ; ++ V_32 ) {
F_33 ( V_3 , V_60 [ V_32 ] ) ;
}
F_22 ( V_2 , V_3 ) ;
F_58 ( V_60 ) ;
return 0 ;
}
int F_59 ( struct V_1 * V_2 , struct V_21 * V_3 , unsigned V_47 ,
unsigned V_67 , T_3 V_53 )
{
int V_9 ;
V_3 -> V_47 = V_47 ;
V_3 -> V_67 = V_67 ;
V_3 -> V_53 = V_53 ;
if ( V_3 -> V_61 == NULL ) {
V_9 = F_60 ( V_2 , V_3 -> V_47 , V_68 , true ,
V_31 ,
NULL , & V_3 -> V_61 ) ;
if ( V_9 ) {
F_3 ( V_2 -> V_12 , L_11 , V_9 ) ;
return V_9 ;
}
V_9 = F_61 ( V_3 -> V_61 , false ) ;
if ( F_62 ( V_9 != 0 ) )
return V_9 ;
V_9 = F_63 ( V_3 -> V_61 , V_31 ,
& V_3 -> V_16 ) ;
if ( V_9 ) {
F_64 ( V_3 -> V_61 ) ;
F_3 ( V_2 -> V_12 , L_12 , V_9 ) ;
return V_9 ;
}
V_9 = F_65 ( V_3 -> V_61 ,
( void * * ) & V_3 -> V_3 ) ;
F_64 ( V_3 -> V_61 ) ;
if ( V_9 ) {
F_3 ( V_2 -> V_12 , L_13 , V_9 ) ;
return V_9 ;
}
}
V_3 -> V_41 = ( V_3 -> V_47 / 4 ) - 1 ;
V_3 -> V_42 = V_3 -> V_47 / 4 ;
if ( V_2 -> V_63 . V_64 ) {
T_3 V_69 = V_70 + ( V_3 -> V_43 * 4 ) ;
V_3 -> V_71 = V_2 -> V_63 . V_16 + V_69 ;
V_3 -> V_65 = & V_2 -> V_63 . V_63 [ V_69 / 4 ] ;
}
if ( F_66 ( V_2 , V_3 ) ) {
F_32 ( L_14 ) ;
}
F_37 ( V_2 , V_3 ) ;
return 0 ;
}
void F_67 ( struct V_1 * V_2 , struct V_21 * V_3 )
{
int V_9 ;
struct V_72 * V_61 ;
F_40 ( & V_2 -> V_52 ) ;
V_61 = V_3 -> V_61 ;
V_3 -> V_23 = false ;
V_3 -> V_3 = NULL ;
V_3 -> V_61 = NULL ;
F_41 ( & V_2 -> V_52 ) ;
if ( V_61 ) {
V_9 = F_61 ( V_61 , false ) ;
if ( F_68 ( V_9 == 0 ) ) {
F_69 ( V_61 ) ;
F_70 ( V_61 ) ;
F_64 ( V_61 ) ;
}
F_71 ( & V_61 ) ;
}
}
static int F_72 ( struct V_73 * V_74 , void * V_60 )
{
struct V_75 * V_76 = (struct V_75 * ) V_74 -> V_77 ;
struct V_78 * V_12 = V_76 -> V_79 -> V_12 ;
struct V_1 * V_2 = V_12 -> V_80 ;
int V_81 = * ( int * ) V_76 -> V_82 -> V_60 ;
struct V_21 * V_3 = & V_2 -> V_3 [ V_81 ] ;
T_1 V_46 , V_40 , V_83 ;
unsigned V_84 , V_32 , V_85 ;
F_35 ( V_2 , V_3 ) ;
V_84 = ( V_3 -> V_47 / 4 ) - V_3 -> V_42 ;
V_40 = F_73 ( V_2 , V_3 ) ;
F_74 ( V_74 , L_15 ,
V_40 , V_40 ) ;
V_46 = F_36 ( V_2 , V_3 ) ;
F_74 ( V_74 , L_16 ,
V_46 , V_46 ) ;
if ( V_3 -> V_62 ) {
V_83 = F_54 ( V_3 -> V_62 ) ;
F_74 ( V_74 , L_17 ,
V_3 -> V_62 , V_83 , V_83 ) ;
} else
V_83 = ~ 0 ;
F_74 ( V_74 , L_18 ,
V_3 -> V_40 , V_3 -> V_40 ) ;
F_74 ( V_74 , L_19 ,
V_3 -> V_86 ) ;
F_74 ( V_74 , L_20 ,
V_3 -> V_87 ) ;
F_74 ( V_74 , L_21 , V_3 -> V_42 ) ;
F_74 ( V_74 , L_22 , V_84 ) ;
if ( ! V_3 -> V_23 )
return 0 ;
V_32 = ( V_46 + V_3 -> V_41 + 1 - 32 ) & V_3 -> V_41 ;
for ( V_85 = 0 ; V_85 <= ( V_84 + 32 ) ; V_85 ++ ) {
F_74 ( V_74 , L_23 , V_32 , V_3 -> V_3 [ V_32 ] ) ;
if ( V_46 == V_32 )
F_75 ( V_74 , L_24 ) ;
if ( V_83 == V_32 )
F_75 ( V_74 , L_25 ) ;
F_75 ( V_74 , L_26 ) ;
V_32 = ( V_32 + 1 ) & V_3 -> V_41 ;
}
return 0 ;
}
static int F_76 ( struct V_73 * V_74 , void * V_60 )
{
struct V_75 * V_76 = (struct V_75 * ) V_74 -> V_77 ;
struct V_78 * V_12 = V_76 -> V_79 -> V_12 ;
struct V_1 * V_2 = V_12 -> V_80 ;
F_77 ( & V_2 -> V_10 , V_74 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 , struct V_21 * V_3 )
{
#if F_78 ( V_88 )
unsigned V_32 ;
for ( V_32 = 0 ; V_32 < F_79 ( V_89 ) ; ++ V_32 ) {
struct V_90 * V_91 = & V_89 [ V_32 ] ;
int V_81 = * ( int * ) V_89 [ V_32 ] . V_60 ;
unsigned V_9 ;
if ( & V_2 -> V_3 [ V_81 ] != V_3 )
continue;
V_9 = F_80 ( V_2 , V_91 , 1 ) ;
if ( V_9 )
return V_9 ;
}
#endif
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
#if F_78 ( V_88 )
return F_80 ( V_2 , V_92 , 1 ) ;
#else
return 0 ;
#endif
}
