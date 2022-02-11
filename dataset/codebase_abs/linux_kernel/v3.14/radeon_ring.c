int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 , struct V_6 * V_7 ,
unsigned V_8 )
{
int V_9 ;
V_9 = F_2 ( V_2 , & V_2 -> V_10 , & V_5 -> V_11 , V_8 , 256 , true ) ;
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
V_9 = F_13 ( V_2 , V_5 -> V_13 , V_5 -> V_3 ) ;
if ( V_9 ) {
F_3 ( V_2 -> V_12 , L_4 , V_9 ) ;
F_14 ( V_2 , V_3 ) ;
return V_9 ;
}
if ( V_5 -> V_7 ) {
F_15 ( V_2 , V_5 -> V_3 , V_5 -> V_7 ) ;
}
if ( V_20 ) {
F_16 ( V_2 , V_20 -> V_3 , V_20 ) ;
F_8 ( V_2 , & V_20 -> V_13 , NULL ) ;
}
F_16 ( V_2 , V_5 -> V_3 , V_5 ) ;
V_9 = F_17 ( V_2 , & V_5 -> V_14 , V_5 -> V_3 ) ;
if ( V_9 ) {
F_3 ( V_2 -> V_12 , L_5 , V_9 ) ;
F_14 ( V_2 , V_3 ) ;
return V_9 ;
}
if ( V_20 ) {
V_20 -> V_14 = F_18 ( V_5 -> V_14 ) ;
}
if ( V_5 -> V_7 && ! V_5 -> V_7 -> V_26 ) {
V_5 -> V_7 -> V_26 = F_18 ( V_5 -> V_14 ) ;
}
F_19 ( V_2 , V_3 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 )
{
int V_9 ;
if ( V_2 -> V_27 ) {
return 0 ;
}
V_9 = F_21 ( V_2 , & V_2 -> V_10 ,
V_28 * 64 * 1024 ,
V_29 ,
V_30 ) ;
if ( V_9 ) {
return V_9 ;
}
V_9 = F_22 ( V_2 , & V_2 -> V_10 ) ;
if ( V_9 ) {
return V_9 ;
}
V_2 -> V_27 = true ;
if ( F_23 ( V_2 ) ) {
F_3 ( V_2 -> V_12 , L_6 ) ;
}
return 0 ;
}
void F_24 ( struct V_1 * V_2 )
{
if ( V_2 -> V_27 ) {
F_25 ( V_2 , & V_2 -> V_10 ) ;
F_26 ( V_2 , & V_2 -> V_10 ) ;
V_2 -> V_27 = false ;
}
}
int F_27 ( struct V_1 * V_2 )
{
unsigned V_31 ;
int V_9 ;
for ( V_31 = 0 ; V_31 < V_32 ; ++ V_31 ) {
struct V_21 * V_3 = & V_2 -> V_3 [ V_31 ] ;
if ( ! V_3 -> V_23 )
continue;
V_9 = F_28 ( V_2 , V_31 , V_3 ) ;
if ( V_9 ) {
V_3 -> V_23 = false ;
if ( V_31 == V_33 ) {
F_29 ( L_7 , V_9 ) ;
V_2 -> V_34 = false ;
return V_9 ;
} else {
F_29 ( L_8 , V_31 , V_9 ) ;
}
}
}
return 0 ;
}
void F_30 ( struct V_21 * V_3 , T_1 V_35 )
{
#if V_36
if ( V_3 -> V_37 <= 0 ) {
F_29 ( L_9 ) ;
}
#endif
V_3 -> V_3 [ V_3 -> V_38 ++ ] = V_35 ;
V_3 -> V_38 &= V_3 -> V_39 ;
V_3 -> V_37 -- ;
V_3 -> V_40 -- ;
}
bool F_31 ( struct V_1 * V_2 ,
struct V_21 * V_3 )
{
switch ( V_3 -> V_41 ) {
case V_33 :
case V_42 :
case V_43 :
return true ;
default:
return false ;
}
}
void F_32 ( struct V_1 * V_2 , struct V_21 * V_3 )
{
V_3 -> V_44 = F_33 ( V_2 , V_3 ) ;
V_3 -> V_40 = ( V_3 -> V_44 + ( V_3 -> V_45 / 4 ) ) ;
V_3 -> V_40 -= V_3 -> V_38 ;
V_3 -> V_40 &= V_3 -> V_39 ;
if ( ! V_3 -> V_40 ) {
V_3 -> V_40 = V_3 -> V_45 / 4 ;
}
}
int F_34 ( struct V_1 * V_2 , struct V_21 * V_3 , unsigned V_46 )
{
int V_9 ;
if ( V_46 > ( V_3 -> V_45 / 4 ) )
return - V_47 ;
F_32 ( V_2 , V_3 ) ;
if ( V_3 -> V_40 == ( V_3 -> V_45 / 4 ) ) {
F_35 ( V_3 ) ;
}
V_46 = ( V_46 + V_3 -> V_48 ) & ~ V_3 -> V_48 ;
while ( V_46 > ( V_3 -> V_40 - 1 ) ) {
F_32 ( V_2 , V_3 ) ;
if ( V_46 < V_3 -> V_40 ) {
break;
}
V_9 = F_36 ( V_2 , V_3 -> V_41 ) ;
if ( V_9 )
return V_9 ;
}
V_3 -> V_37 = V_46 ;
V_3 -> V_49 = V_3 -> V_38 ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 , struct V_21 * V_3 , unsigned V_46 )
{
int V_9 ;
F_37 ( & V_2 -> V_50 ) ;
V_9 = F_34 ( V_2 , V_3 , V_46 ) ;
if ( V_9 ) {
F_38 ( & V_2 -> V_50 ) ;
return V_9 ;
}
return 0 ;
}
void F_39 ( struct V_1 * V_2 , struct V_21 * V_3 )
{
while ( V_3 -> V_38 & V_3 -> V_48 ) {
F_30 ( V_3 , V_3 -> V_51 ) ;
}
F_40 () ;
F_41 ( V_2 , V_3 ) ;
}
void F_19 ( struct V_1 * V_2 , struct V_21 * V_3 )
{
F_39 ( V_2 , V_3 ) ;
F_38 ( & V_2 -> V_50 ) ;
}
void F_42 ( struct V_21 * V_3 )
{
V_3 -> V_38 = V_3 -> V_49 ;
}
void F_14 ( struct V_1 * V_2 , struct V_21 * V_3 )
{
F_42 ( V_3 ) ;
F_38 ( & V_2 -> V_50 ) ;
}
void F_43 ( struct V_1 * V_2 , struct V_21 * V_3 )
{
int V_9 ;
F_32 ( V_2 , V_3 ) ;
if ( V_3 -> V_44 == V_3 -> V_38 ) {
V_9 = F_34 ( V_2 , V_3 , 1 ) ;
if ( ! V_9 ) {
F_30 ( V_3 , V_3 -> V_51 ) ;
F_39 ( V_2 , V_3 ) ;
}
}
}
void F_35 ( struct V_21 * V_3 )
{
V_3 -> V_52 = V_3 -> V_44 ;
V_3 -> V_53 = V_54 ;
}
bool F_44 ( struct V_1 * V_2 , struct V_21 * V_3 )
{
unsigned long V_55 , V_56 ;
V_55 = V_54 ;
if ( ! F_45 ( V_55 , V_3 -> V_53 ) ) {
F_35 ( V_3 ) ;
return false ;
}
V_3 -> V_44 = F_33 ( V_2 , V_3 ) ;
if ( V_3 -> V_44 != V_3 -> V_52 ) {
F_35 ( V_3 ) ;
return false ;
}
V_56 = F_46 ( V_55 - V_3 -> V_53 ) ;
if ( V_57 && V_56 >= V_57 ) {
F_3 ( V_2 -> V_12 , L_10 , V_56 ) ;
return true ;
}
return false ;
}
unsigned F_47 ( struct V_1 * V_2 , struct V_21 * V_3 ,
T_1 * * V_58 )
{
unsigned V_8 , V_15 , V_31 ;
F_37 ( & V_2 -> V_50 ) ;
* V_58 = NULL ;
if ( V_3 -> V_59 == NULL ) {
F_38 ( & V_2 -> V_50 ) ;
return 0 ;
}
if ( ! F_48 ( V_2 , V_3 -> V_41 ) ) {
F_38 ( & V_2 -> V_50 ) ;
return 0 ;
}
if ( V_3 -> V_60 )
V_15 = F_49 ( V_3 -> V_60 ) ;
else if ( V_2 -> V_61 . V_62 )
V_15 = F_50 ( * V_3 -> V_63 ) ;
else {
F_38 ( & V_2 -> V_50 ) ;
return 0 ;
}
V_8 = V_3 -> V_38 + ( V_3 -> V_45 / 4 ) ;
V_8 -= V_15 ;
V_8 &= V_3 -> V_39 ;
if ( V_8 == 0 ) {
F_38 ( & V_2 -> V_50 ) ;
return 0 ;
}
* V_58 = F_51 ( V_8 , sizeof( T_1 ) , V_64 ) ;
if ( ! * V_58 ) {
F_38 ( & V_2 -> V_50 ) ;
return 0 ;
}
for ( V_31 = 0 ; V_31 < V_8 ; ++ V_31 ) {
( * V_58 ) [ V_31 ] = V_3 -> V_3 [ V_15 ++ ] ;
V_15 &= V_3 -> V_39 ;
}
F_38 ( & V_2 -> V_50 ) ;
return V_8 ;
}
int F_52 ( struct V_1 * V_2 , struct V_21 * V_3 ,
unsigned V_8 , T_1 * V_58 )
{
int V_31 , V_9 ;
if ( ! V_8 || ! V_58 )
return 0 ;
V_9 = F_12 ( V_2 , V_3 , V_8 ) ;
if ( V_9 )
return V_9 ;
for ( V_31 = 0 ; V_31 < V_8 ; ++ V_31 ) {
F_30 ( V_3 , V_58 [ V_31 ] ) ;
}
F_19 ( V_2 , V_3 ) ;
F_53 ( V_58 ) ;
return 0 ;
}
int F_54 ( struct V_1 * V_2 , struct V_21 * V_3 , unsigned V_45 ,
unsigned V_65 , T_2 V_51 )
{
int V_9 ;
V_3 -> V_45 = V_45 ;
V_3 -> V_65 = V_65 ;
V_3 -> V_51 = V_51 ;
if ( V_3 -> V_59 == NULL ) {
V_9 = F_55 ( V_2 , V_3 -> V_45 , V_66 , true ,
V_30 ,
NULL , & V_3 -> V_59 ) ;
if ( V_9 ) {
F_3 ( V_2 -> V_12 , L_11 , V_9 ) ;
return V_9 ;
}
V_9 = F_56 ( V_3 -> V_59 , false ) ;
if ( F_57 ( V_9 != 0 ) )
return V_9 ;
V_9 = F_58 ( V_3 -> V_59 , V_30 ,
& V_3 -> V_16 ) ;
if ( V_9 ) {
F_59 ( V_3 -> V_59 ) ;
F_3 ( V_2 -> V_12 , L_12 , V_9 ) ;
return V_9 ;
}
V_9 = F_60 ( V_3 -> V_59 ,
( void * * ) & V_3 -> V_3 ) ;
F_59 ( V_3 -> V_59 ) ;
if ( V_9 ) {
F_3 ( V_2 -> V_12 , L_13 , V_9 ) ;
return V_9 ;
}
}
V_3 -> V_39 = ( V_3 -> V_45 / 4 ) - 1 ;
V_3 -> V_40 = V_3 -> V_45 / 4 ;
if ( V_2 -> V_61 . V_62 ) {
T_2 V_67 = V_68 + ( V_3 -> V_41 * 4 ) ;
V_3 -> V_69 = V_2 -> V_61 . V_16 + V_67 ;
V_3 -> V_63 = & V_2 -> V_61 . V_61 [ V_67 / 4 ] ;
}
if ( F_61 ( V_2 , V_3 ) ) {
F_29 ( L_14 ) ;
}
F_35 ( V_3 ) ;
return 0 ;
}
void F_62 ( struct V_1 * V_2 , struct V_21 * V_3 )
{
int V_9 ;
struct V_70 * V_59 ;
F_37 ( & V_2 -> V_50 ) ;
V_59 = V_3 -> V_59 ;
V_3 -> V_23 = false ;
V_3 -> V_3 = NULL ;
V_3 -> V_59 = NULL ;
F_38 ( & V_2 -> V_50 ) ;
if ( V_59 ) {
V_9 = F_56 ( V_59 , false ) ;
if ( F_63 ( V_9 == 0 ) ) {
F_64 ( V_59 ) ;
F_65 ( V_59 ) ;
F_59 ( V_59 ) ;
}
F_66 ( & V_59 ) ;
}
}
static int F_67 ( struct V_71 * V_72 , void * V_58 )
{
struct V_73 * V_74 = (struct V_73 * ) V_72 -> V_75 ;
struct V_76 * V_12 = V_74 -> V_77 -> V_12 ;
struct V_1 * V_2 = V_12 -> V_78 ;
int V_79 = * ( int * ) V_74 -> V_80 -> V_58 ;
struct V_21 * V_3 = & V_2 -> V_3 [ V_79 ] ;
T_1 V_44 , V_38 , V_81 ;
unsigned V_82 , V_31 , V_83 ;
F_32 ( V_2 , V_3 ) ;
V_82 = ( V_3 -> V_45 / 4 ) - V_3 -> V_40 ;
V_38 = F_68 ( V_2 , V_3 ) ;
F_69 ( V_72 , L_15 ,
V_38 , V_38 ) ;
V_44 = F_33 ( V_2 , V_3 ) ;
F_69 ( V_72 , L_16 ,
V_44 , V_44 ) ;
if ( V_3 -> V_60 ) {
V_81 = F_49 ( V_3 -> V_60 ) ;
F_69 ( V_72 , L_17 ,
V_3 -> V_60 , V_81 , V_81 ) ;
} else
V_81 = ~ 0 ;
F_69 ( V_72 , L_18 ,
V_3 -> V_38 , V_3 -> V_38 ) ;
F_69 ( V_72 , L_19 ,
V_3 -> V_44 , V_3 -> V_44 ) ;
F_69 ( V_72 , L_20 ,
V_3 -> V_84 ) ;
F_69 ( V_72 , L_21 ,
V_3 -> V_85 ) ;
F_69 ( V_72 , L_22 , V_3 -> V_40 ) ;
F_69 ( V_72 , L_23 , V_82 ) ;
if ( ! V_3 -> V_23 )
return 0 ;
V_31 = ( V_44 + V_3 -> V_39 + 1 - 32 ) & V_3 -> V_39 ;
for ( V_83 = 0 ; V_83 <= ( V_82 + 32 ) ; V_83 ++ ) {
F_69 ( V_72 , L_24 , V_31 , V_3 -> V_3 [ V_31 ] ) ;
if ( V_44 == V_31 )
F_70 ( V_72 , L_25 ) ;
if ( V_81 == V_31 )
F_70 ( V_72 , L_26 ) ;
F_70 ( V_72 , L_27 ) ;
V_31 = ( V_31 + 1 ) & V_3 -> V_39 ;
}
return 0 ;
}
static int F_71 ( struct V_71 * V_72 , void * V_58 )
{
struct V_73 * V_74 = (struct V_73 * ) V_72 -> V_75 ;
struct V_76 * V_12 = V_74 -> V_77 -> V_12 ;
struct V_1 * V_2 = V_12 -> V_78 ;
F_72 ( & V_2 -> V_10 , V_72 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_21 * V_3 )
{
#if F_73 ( V_86 )
unsigned V_31 ;
for ( V_31 = 0 ; V_31 < F_74 ( V_87 ) ; ++ V_31 ) {
struct V_88 * V_89 = & V_87 [ V_31 ] ;
int V_79 = * ( int * ) V_87 [ V_31 ] . V_58 ;
unsigned V_9 ;
if ( & V_2 -> V_3 [ V_79 ] != V_3 )
continue;
V_9 = F_75 ( V_2 , V_89 , 1 ) ;
if ( V_9 )
return V_9 ;
}
#endif
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
#if F_73 ( V_86 )
return F_75 ( V_2 , V_90 , 1 ) ;
#else
return 0 ;
#endif
}
