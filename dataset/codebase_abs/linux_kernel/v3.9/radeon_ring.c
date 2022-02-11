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
if ( V_5 -> V_7 && ! V_5 -> V_7 -> V_31 ) {
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
if ( V_2 -> V_47 . V_48 )
V_46 = F_37 ( V_2 -> V_47 . V_47 [ V_3 -> V_49 / 4 ] ) ;
else
V_46 = F_38 ( V_3 -> V_50 ) ;
V_3 -> V_46 = ( V_46 & V_3 -> V_51 ) >> V_3 -> V_52 ;
V_3 -> V_42 = ( V_3 -> V_46 + ( V_3 -> V_53 / 4 ) ) ;
V_3 -> V_42 -= V_3 -> V_40 ;
V_3 -> V_42 &= V_3 -> V_41 ;
if ( ! V_3 -> V_42 ) {
V_3 -> V_42 = V_3 -> V_53 / 4 ;
}
}
int F_39 ( struct V_1 * V_2 , struct V_26 * V_3 , unsigned V_54 )
{
int V_10 ;
if ( V_54 > ( V_3 -> V_53 / 4 ) )
return - V_55 ;
V_54 = ( V_54 + V_3 -> V_56 ) & ~ V_3 -> V_56 ;
while ( V_54 > ( V_3 -> V_42 - 1 ) ) {
F_36 ( V_2 , V_3 ) ;
if ( V_54 < V_3 -> V_42 ) {
break;
}
V_10 = F_40 ( V_2 , V_3 -> V_43 ) ;
if ( V_10 )
return V_10 ;
}
V_3 -> V_39 = V_54 ;
V_3 -> V_57 = V_3 -> V_40 ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 , struct V_26 * V_3 , unsigned V_54 )
{
int V_10 ;
F_41 ( & V_2 -> V_58 ) ;
V_10 = F_39 ( V_2 , V_3 , V_54 ) ;
if ( V_10 ) {
F_42 ( & V_2 -> V_58 ) ;
return V_10 ;
}
return 0 ;
}
void F_43 ( struct V_1 * V_2 , struct V_26 * V_3 )
{
while ( V_3 -> V_40 & V_3 -> V_56 ) {
F_34 ( V_3 , V_3 -> V_59 ) ;
}
F_44 () ;
F_45 ( V_3 -> V_60 , ( V_3 -> V_40 << V_3 -> V_52 ) & V_3 -> V_51 ) ;
( void ) F_38 ( V_3 -> V_60 ) ;
}
void F_23 ( struct V_1 * V_2 , struct V_26 * V_3 )
{
F_43 ( V_2 , V_3 ) ;
F_42 ( & V_2 -> V_58 ) ;
}
void F_46 ( struct V_26 * V_3 )
{
V_3 -> V_40 = V_3 -> V_57 ;
}
void F_21 ( struct V_1 * V_2 , struct V_26 * V_3 )
{
F_46 ( V_3 ) ;
F_42 ( & V_2 -> V_58 ) ;
}
void F_47 ( struct V_1 * V_2 , struct V_26 * V_3 )
{
int V_10 ;
F_36 ( V_2 , V_3 ) ;
if ( V_3 -> V_46 == V_3 -> V_40 ) {
V_10 = F_39 ( V_2 , V_3 , 1 ) ;
if ( ! V_10 ) {
F_34 ( V_3 , V_3 -> V_59 ) ;
F_43 ( V_2 , V_3 ) ;
}
}
}
void F_48 ( struct V_26 * V_3 )
{
V_3 -> V_61 = V_3 -> V_46 ;
V_3 -> V_62 = V_63 ;
}
bool F_49 ( struct V_1 * V_2 , struct V_26 * V_3 )
{
unsigned long V_64 , V_65 ;
T_1 V_46 ;
V_64 = V_63 ;
if ( ! F_50 ( V_64 , V_3 -> V_62 ) ) {
F_48 ( V_3 ) ;
return false ;
}
V_46 = F_38 ( V_3 -> V_50 ) ;
V_3 -> V_46 = ( V_46 & V_3 -> V_51 ) >> V_3 -> V_52 ;
if ( V_3 -> V_46 != V_3 -> V_61 ) {
F_48 ( V_3 ) ;
return false ;
}
V_65 = F_51 ( V_64 - V_3 -> V_62 ) ;
if ( V_66 && V_65 >= V_66 ) {
F_3 ( V_2 -> V_13 , L_9 , V_65 ) ;
return true ;
}
return false ;
}
unsigned F_52 ( struct V_1 * V_2 , struct V_26 * V_3 ,
T_1 * * V_67 )
{
unsigned V_8 , V_16 , V_9 ;
F_41 ( & V_2 -> V_58 ) ;
* V_67 = NULL ;
if ( V_3 -> V_68 == NULL ) {
F_42 ( & V_2 -> V_58 ) ;
return 0 ;
}
if ( ! F_53 ( V_2 , V_3 -> V_43 ) ) {
F_42 ( & V_2 -> V_58 ) ;
return 0 ;
}
if ( V_3 -> V_69 )
V_16 = F_38 ( V_3 -> V_69 ) ;
else if ( V_2 -> V_47 . V_48 )
V_16 = F_37 ( * V_3 -> V_70 ) ;
else {
F_42 ( & V_2 -> V_58 ) ;
return 0 ;
}
V_8 = V_3 -> V_40 + ( V_3 -> V_53 / 4 ) ;
V_8 -= V_16 ;
V_8 &= V_3 -> V_41 ;
if ( V_8 == 0 ) {
F_42 ( & V_2 -> V_58 ) ;
return 0 ;
}
* V_67 = F_54 ( V_8 , sizeof( T_1 ) , V_71 ) ;
if ( ! * V_67 ) {
F_42 ( & V_2 -> V_58 ) ;
return 0 ;
}
for ( V_9 = 0 ; V_9 < V_8 ; ++ V_9 ) {
( * V_67 ) [ V_9 ] = V_3 -> V_3 [ V_16 ++ ] ;
V_16 &= V_3 -> V_41 ;
}
F_42 ( & V_2 -> V_58 ) ;
return V_8 ;
}
int F_55 ( struct V_1 * V_2 , struct V_26 * V_3 ,
unsigned V_8 , T_1 * V_67 )
{
int V_9 , V_10 ;
if ( ! V_8 || ! V_67 )
return 0 ;
V_10 = F_14 ( V_2 , V_3 , V_8 ) ;
if ( V_10 )
return V_10 ;
for ( V_9 = 0 ; V_9 < V_8 ; ++ V_9 ) {
F_34 ( V_3 , V_67 [ V_9 ] ) ;
}
F_23 ( V_2 , V_3 ) ;
F_56 ( V_67 ) ;
return 0 ;
}
int F_57 ( struct V_1 * V_2 , struct V_26 * V_3 , unsigned V_53 ,
unsigned V_49 , unsigned V_50 , unsigned V_60 ,
T_2 V_52 , T_2 V_51 , T_2 V_59 )
{
int V_10 ;
V_3 -> V_53 = V_53 ;
V_3 -> V_49 = V_49 ;
V_3 -> V_50 = V_50 ;
V_3 -> V_60 = V_60 ;
V_3 -> V_52 = V_52 ;
V_3 -> V_51 = V_51 ;
V_3 -> V_59 = V_59 ;
if ( V_3 -> V_68 == NULL ) {
V_10 = F_58 ( V_2 , V_3 -> V_53 , V_72 , true ,
V_34 ,
NULL , & V_3 -> V_68 ) ;
if ( V_10 ) {
F_3 ( V_2 -> V_13 , L_10 , V_10 ) ;
return V_10 ;
}
V_10 = F_59 ( V_3 -> V_68 , false ) ;
if ( F_60 ( V_10 != 0 ) )
return V_10 ;
V_10 = F_61 ( V_3 -> V_68 , V_34 ,
& V_3 -> V_17 ) ;
if ( V_10 ) {
F_62 ( V_3 -> V_68 ) ;
F_3 ( V_2 -> V_13 , L_11 , V_10 ) ;
return V_10 ;
}
V_10 = F_63 ( V_3 -> V_68 ,
( void * * ) & V_3 -> V_3 ) ;
F_62 ( V_3 -> V_68 ) ;
if ( V_10 ) {
F_3 ( V_2 -> V_13 , L_12 , V_10 ) ;
return V_10 ;
}
}
V_3 -> V_41 = ( V_3 -> V_53 / 4 ) - 1 ;
V_3 -> V_42 = V_3 -> V_53 / 4 ;
if ( V_2 -> V_47 . V_48 ) {
T_2 V_73 = V_74 + ( V_3 -> V_43 * 4 ) ;
V_3 -> V_75 = V_2 -> V_47 . V_17 + V_73 ;
V_3 -> V_70 = & V_2 -> V_47 . V_47 [ V_73 / 4 ] ;
}
if ( F_64 ( V_2 , V_3 ) ) {
F_33 ( L_13 ) ;
}
F_48 ( V_3 ) ;
return 0 ;
}
void F_65 ( struct V_1 * V_2 , struct V_26 * V_3 )
{
int V_10 ;
struct V_76 * V_68 ;
F_41 ( & V_2 -> V_58 ) ;
V_68 = V_3 -> V_68 ;
V_3 -> V_29 = false ;
V_3 -> V_3 = NULL ;
V_3 -> V_68 = NULL ;
F_42 ( & V_2 -> V_58 ) ;
if ( V_68 ) {
V_10 = F_59 ( V_68 , false ) ;
if ( F_66 ( V_10 == 0 ) ) {
F_67 ( V_68 ) ;
F_68 ( V_68 ) ;
F_62 ( V_68 ) ;
}
F_69 ( & V_68 ) ;
}
}
static int F_70 ( struct V_77 * V_78 , void * V_67 )
{
struct V_79 * V_80 = (struct V_79 * ) V_78 -> V_81 ;
struct V_82 * V_13 = V_80 -> V_83 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_84 ;
int V_85 = * ( int * ) V_80 -> V_86 -> V_67 ;
struct V_26 * V_3 = & V_2 -> V_3 [ V_85 ] ;
unsigned V_87 , V_9 , V_88 ;
T_2 V_89 ;
F_36 ( V_2 , V_3 ) ;
V_87 = ( V_3 -> V_53 / 4 ) - V_3 -> V_42 ;
V_89 = F_38 ( V_3 -> V_60 ) >> V_3 -> V_52 ;
F_71 ( V_78 , L_14 , V_3 -> V_60 , V_89 , V_89 ) ;
V_89 = F_38 ( V_3 -> V_50 ) >> V_3 -> V_52 ;
F_71 ( V_78 , L_15 , V_3 -> V_50 , V_89 , V_89 ) ;
if ( V_3 -> V_69 ) {
F_71 ( V_78 , L_16 , V_3 -> V_69 ,
F_38 ( V_3 -> V_69 ) ) ;
}
F_71 ( V_78 , L_17 , V_3 -> V_40 , V_3 -> V_40 ) ;
F_71 ( V_78 , L_18 , V_3 -> V_46 , V_3 -> V_46 ) ;
F_71 ( V_78 , L_19 , V_3 -> V_90 ) ;
F_71 ( V_78 , L_20 , V_3 -> V_91 ) ;
F_71 ( V_78 , L_21 , V_3 -> V_42 ) ;
F_71 ( V_78 , L_22 , V_87 ) ;
V_9 = ( V_3 -> V_46 + V_3 -> V_41 + 1 - 32 ) & V_3 -> V_41 ;
for ( V_88 = 0 ; V_88 <= ( V_87 + 32 ) ; V_88 ++ ) {
F_71 ( V_78 , L_23 , V_9 , V_3 -> V_3 [ V_9 ] ) ;
V_9 = ( V_9 + 1 ) & V_3 -> V_41 ;
}
return 0 ;
}
static int F_72 ( struct V_77 * V_78 , void * V_67 )
{
struct V_79 * V_80 = (struct V_79 * ) V_78 -> V_81 ;
struct V_82 * V_13 = V_80 -> V_83 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_84 ;
F_73 ( & V_2 -> V_11 , V_78 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 , struct V_26 * V_3 )
{
#if F_74 ( V_92 )
unsigned V_9 ;
for ( V_9 = 0 ; V_9 < F_75 ( V_93 ) ; ++ V_9 ) {
struct V_94 * V_95 = & V_93 [ V_9 ] ;
int V_85 = * ( int * ) V_93 [ V_9 ] . V_67 ;
unsigned V_10 ;
if ( & V_2 -> V_3 [ V_85 ] != V_3 )
continue;
V_10 = F_76 ( V_2 , V_95 , 1 ) ;
if ( V_10 )
return V_10 ;
}
#endif
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
#if F_74 ( V_92 )
return F_76 ( V_2 , V_96 , 1 ) ;
#else
return 0 ;
#endif
}
