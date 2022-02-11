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
for ( V_31 = 0 ; V_31 < V_25 ; ++ V_31 ) {
struct V_21 * V_3 = & V_2 -> V_3 [ V_31 ] ;
if ( ! V_3 -> V_23 )
continue;
V_9 = F_28 ( V_2 , V_31 , V_3 ) ;
if ( V_9 ) {
V_3 -> V_23 = false ;
if ( V_31 == V_32 ) {
F_29 ( L_7 , V_9 ) ;
V_2 -> V_33 = false ;
return V_9 ;
} else {
F_29 ( L_8 , V_31 , V_9 ) ;
}
}
}
return 0 ;
}
void F_30 ( struct V_21 * V_3 , T_1 V_34 )
{
#if V_35
if ( V_3 -> V_36 <= 0 ) {
F_29 ( L_9 ) ;
}
#endif
V_3 -> V_3 [ V_3 -> V_37 ++ ] = V_34 ;
V_3 -> V_37 &= V_3 -> V_38 ;
V_3 -> V_36 -- ;
V_3 -> V_39 -- ;
}
bool F_31 ( struct V_1 * V_2 ,
struct V_21 * V_3 )
{
switch ( V_3 -> V_40 ) {
case V_32 :
case V_41 :
case V_42 :
return true ;
default:
return false ;
}
}
T_2 F_32 ( struct V_1 * V_2 ,
struct V_21 * V_3 )
{
T_2 V_43 ;
if ( V_2 -> V_44 . V_45 )
V_43 = F_33 ( V_2 -> V_44 . V_44 [ V_3 -> V_46 / 4 ] ) ;
else
V_43 = F_34 ( V_3 -> V_47 ) ;
return V_43 ;
}
T_2 F_35 ( struct V_1 * V_2 ,
struct V_21 * V_3 )
{
T_2 V_37 ;
V_37 = F_34 ( V_3 -> V_48 ) ;
return V_37 ;
}
void F_36 ( struct V_1 * V_2 ,
struct V_21 * V_3 )
{
F_37 ( V_3 -> V_48 , V_3 -> V_37 ) ;
( void ) F_34 ( V_3 -> V_48 ) ;
}
void F_38 ( struct V_1 * V_2 , struct V_21 * V_3 )
{
V_3 -> V_43 = F_39 ( V_2 , V_3 ) ;
V_3 -> V_39 = ( V_3 -> V_43 + ( V_3 -> V_49 / 4 ) ) ;
V_3 -> V_39 -= V_3 -> V_37 ;
V_3 -> V_39 &= V_3 -> V_38 ;
if ( ! V_3 -> V_39 ) {
V_3 -> V_39 = V_3 -> V_49 / 4 ;
}
}
int F_40 ( struct V_1 * V_2 , struct V_21 * V_3 , unsigned V_50 )
{
int V_9 ;
if ( V_50 > ( V_3 -> V_49 / 4 ) )
return - V_51 ;
F_38 ( V_2 , V_3 ) ;
if ( V_3 -> V_39 == ( V_3 -> V_49 / 4 ) ) {
F_41 ( V_3 ) ;
}
V_50 = ( V_50 + V_3 -> V_52 ) & ~ V_3 -> V_52 ;
while ( V_50 > ( V_3 -> V_39 - 1 ) ) {
F_38 ( V_2 , V_3 ) ;
if ( V_50 < V_3 -> V_39 ) {
break;
}
V_9 = F_42 ( V_2 , V_3 -> V_40 ) ;
if ( V_9 )
return V_9 ;
}
V_3 -> V_36 = V_50 ;
V_3 -> V_53 = V_3 -> V_37 ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 , struct V_21 * V_3 , unsigned V_50 )
{
int V_9 ;
F_43 ( & V_2 -> V_54 ) ;
V_9 = F_40 ( V_2 , V_3 , V_50 ) ;
if ( V_9 ) {
F_44 ( & V_2 -> V_54 ) ;
return V_9 ;
}
return 0 ;
}
void F_45 ( struct V_1 * V_2 , struct V_21 * V_3 )
{
while ( V_3 -> V_37 & V_3 -> V_52 ) {
F_30 ( V_3 , V_3 -> V_55 ) ;
}
F_46 () ;
F_47 ( V_2 , V_3 ) ;
}
void F_19 ( struct V_1 * V_2 , struct V_21 * V_3 )
{
F_45 ( V_2 , V_3 ) ;
F_44 ( & V_2 -> V_54 ) ;
}
void F_48 ( struct V_21 * V_3 )
{
V_3 -> V_37 = V_3 -> V_53 ;
}
void F_14 ( struct V_1 * V_2 , struct V_21 * V_3 )
{
F_48 ( V_3 ) ;
F_44 ( & V_2 -> V_54 ) ;
}
void F_49 ( struct V_1 * V_2 , struct V_21 * V_3 )
{
int V_9 ;
F_38 ( V_2 , V_3 ) ;
if ( V_3 -> V_43 == V_3 -> V_37 ) {
V_9 = F_40 ( V_2 , V_3 , 1 ) ;
if ( ! V_9 ) {
F_30 ( V_3 , V_3 -> V_55 ) ;
F_45 ( V_2 , V_3 ) ;
}
}
}
void F_41 ( struct V_21 * V_3 )
{
V_3 -> V_56 = V_3 -> V_43 ;
V_3 -> V_57 = V_58 ;
}
bool F_50 ( struct V_1 * V_2 , struct V_21 * V_3 )
{
unsigned long V_59 , V_60 ;
V_59 = V_58 ;
if ( ! F_51 ( V_59 , V_3 -> V_57 ) ) {
F_41 ( V_3 ) ;
return false ;
}
V_3 -> V_43 = F_39 ( V_2 , V_3 ) ;
if ( V_3 -> V_43 != V_3 -> V_56 ) {
F_41 ( V_3 ) ;
return false ;
}
V_60 = F_52 ( V_59 - V_3 -> V_57 ) ;
if ( V_61 && V_60 >= V_61 ) {
F_3 ( V_2 -> V_12 , L_10 , V_60 ) ;
return true ;
}
return false ;
}
unsigned F_53 ( struct V_1 * V_2 , struct V_21 * V_3 ,
T_1 * * V_62 )
{
unsigned V_8 , V_15 , V_31 ;
F_43 ( & V_2 -> V_54 ) ;
* V_62 = NULL ;
if ( V_3 -> V_63 == NULL ) {
F_44 ( & V_2 -> V_54 ) ;
return 0 ;
}
if ( ! F_54 ( V_2 , V_3 -> V_40 ) ) {
F_44 ( & V_2 -> V_54 ) ;
return 0 ;
}
if ( V_3 -> V_64 )
V_15 = F_34 ( V_3 -> V_64 ) ;
else if ( V_2 -> V_44 . V_45 )
V_15 = F_33 ( * V_3 -> V_65 ) ;
else {
F_44 ( & V_2 -> V_54 ) ;
return 0 ;
}
V_8 = V_3 -> V_37 + ( V_3 -> V_49 / 4 ) ;
V_8 -= V_15 ;
V_8 &= V_3 -> V_38 ;
if ( V_8 == 0 ) {
F_44 ( & V_2 -> V_54 ) ;
return 0 ;
}
* V_62 = F_55 ( V_8 , sizeof( T_1 ) , V_66 ) ;
if ( ! * V_62 ) {
F_44 ( & V_2 -> V_54 ) ;
return 0 ;
}
for ( V_31 = 0 ; V_31 < V_8 ; ++ V_31 ) {
( * V_62 ) [ V_31 ] = V_3 -> V_3 [ V_15 ++ ] ;
V_15 &= V_3 -> V_38 ;
}
F_44 ( & V_2 -> V_54 ) ;
return V_8 ;
}
int F_56 ( struct V_1 * V_2 , struct V_21 * V_3 ,
unsigned V_8 , T_1 * V_62 )
{
int V_31 , V_9 ;
if ( ! V_8 || ! V_62 )
return 0 ;
V_9 = F_12 ( V_2 , V_3 , V_8 ) ;
if ( V_9 )
return V_9 ;
for ( V_31 = 0 ; V_31 < V_8 ; ++ V_31 ) {
F_30 ( V_3 , V_62 [ V_31 ] ) ;
}
F_19 ( V_2 , V_3 ) ;
F_57 ( V_62 ) ;
return 0 ;
}
int F_58 ( struct V_1 * V_2 , struct V_21 * V_3 , unsigned V_49 ,
unsigned V_46 , unsigned V_47 , unsigned V_48 , T_2 V_55 )
{
int V_9 ;
V_3 -> V_49 = V_49 ;
V_3 -> V_46 = V_46 ;
V_3 -> V_47 = V_47 ;
V_3 -> V_48 = V_48 ;
V_3 -> V_55 = V_55 ;
if ( V_3 -> V_63 == NULL ) {
V_9 = F_59 ( V_2 , V_3 -> V_49 , V_67 , true ,
V_30 ,
NULL , & V_3 -> V_63 ) ;
if ( V_9 ) {
F_3 ( V_2 -> V_12 , L_11 , V_9 ) ;
return V_9 ;
}
V_9 = F_60 ( V_3 -> V_63 , false ) ;
if ( F_61 ( V_9 != 0 ) )
return V_9 ;
V_9 = F_62 ( V_3 -> V_63 , V_30 ,
& V_3 -> V_16 ) ;
if ( V_9 ) {
F_63 ( V_3 -> V_63 ) ;
F_3 ( V_2 -> V_12 , L_12 , V_9 ) ;
return V_9 ;
}
V_9 = F_64 ( V_3 -> V_63 ,
( void * * ) & V_3 -> V_3 ) ;
F_63 ( V_3 -> V_63 ) ;
if ( V_9 ) {
F_3 ( V_2 -> V_12 , L_13 , V_9 ) ;
return V_9 ;
}
}
V_3 -> V_38 = ( V_3 -> V_49 / 4 ) - 1 ;
V_3 -> V_39 = V_3 -> V_49 / 4 ;
if ( V_2 -> V_44 . V_45 ) {
T_2 V_68 = V_69 + ( V_3 -> V_40 * 4 ) ;
V_3 -> V_70 = V_2 -> V_44 . V_16 + V_68 ;
V_3 -> V_65 = & V_2 -> V_44 . V_44 [ V_68 / 4 ] ;
}
if ( F_65 ( V_2 , V_3 ) ) {
F_29 ( L_14 ) ;
}
F_41 ( V_3 ) ;
return 0 ;
}
void F_66 ( struct V_1 * V_2 , struct V_21 * V_3 )
{
int V_9 ;
struct V_71 * V_63 ;
F_43 ( & V_2 -> V_54 ) ;
V_63 = V_3 -> V_63 ;
V_3 -> V_23 = false ;
V_3 -> V_3 = NULL ;
V_3 -> V_63 = NULL ;
F_44 ( & V_2 -> V_54 ) ;
if ( V_63 ) {
V_9 = F_60 ( V_63 , false ) ;
if ( F_67 ( V_9 == 0 ) ) {
F_68 ( V_63 ) ;
F_69 ( V_63 ) ;
F_63 ( V_63 ) ;
}
F_70 ( & V_63 ) ;
}
}
static int F_71 ( struct V_72 * V_73 , void * V_62 )
{
struct V_74 * V_75 = (struct V_74 * ) V_73 -> V_76 ;
struct V_77 * V_12 = V_75 -> V_78 -> V_12 ;
struct V_1 * V_2 = V_12 -> V_79 ;
int V_80 = * ( int * ) V_75 -> V_81 -> V_62 ;
struct V_21 * V_3 = & V_2 -> V_3 [ V_80 ] ;
unsigned V_82 , V_31 , V_83 ;
T_2 V_84 ;
F_38 ( V_2 , V_3 ) ;
V_82 = ( V_3 -> V_49 / 4 ) - V_3 -> V_39 ;
V_84 = F_72 ( V_2 , V_3 ) ;
F_73 ( V_73 , L_15 , V_3 -> V_48 , V_84 , V_84 ) ;
V_84 = F_39 ( V_2 , V_3 ) ;
F_73 ( V_73 , L_16 , V_3 -> V_47 , V_84 , V_84 ) ;
if ( V_3 -> V_64 ) {
F_73 ( V_73 , L_17 , V_3 -> V_64 ,
F_34 ( V_3 -> V_64 ) ) ;
}
F_73 ( V_73 , L_18 , V_3 -> V_37 , V_3 -> V_37 ) ;
F_73 ( V_73 , L_19 , V_3 -> V_43 , V_3 -> V_43 ) ;
F_73 ( V_73 , L_20 , V_3 -> V_85 ) ;
F_73 ( V_73 , L_21 , V_3 -> V_86 ) ;
F_73 ( V_73 , L_22 , V_3 -> V_39 ) ;
F_73 ( V_73 , L_23 , V_82 ) ;
V_31 = ( V_3 -> V_43 + V_3 -> V_38 + 1 - 32 ) & V_3 -> V_38 ;
if ( V_3 -> V_23 ) {
for ( V_83 = 0 ; V_83 <= ( V_82 + 32 ) ; V_83 ++ ) {
F_73 ( V_73 , L_24 , V_31 , V_3 -> V_3 [ V_31 ] ) ;
V_31 = ( V_31 + 1 ) & V_3 -> V_38 ;
}
}
return 0 ;
}
static int F_74 ( struct V_72 * V_73 , void * V_62 )
{
struct V_74 * V_75 = (struct V_74 * ) V_73 -> V_76 ;
struct V_77 * V_12 = V_75 -> V_78 -> V_12 ;
struct V_1 * V_2 = V_12 -> V_79 ;
F_75 ( & V_2 -> V_10 , V_73 ) ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 , struct V_21 * V_3 )
{
#if F_76 ( V_87 )
unsigned V_31 ;
for ( V_31 = 0 ; V_31 < F_77 ( V_88 ) ; ++ V_31 ) {
struct V_89 * V_90 = & V_88 [ V_31 ] ;
int V_80 = * ( int * ) V_88 [ V_31 ] . V_62 ;
unsigned V_9 ;
if ( & V_2 -> V_3 [ V_80 ] != V_3 )
continue;
V_9 = F_78 ( V_2 , V_90 , 1 ) ;
if ( V_9 )
return V_9 ;
}
#endif
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
#if F_76 ( V_87 )
return F_78 ( V_2 , V_91 , 1 ) ;
#else
return 0 ;
#endif
}
