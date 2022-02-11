int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 , unsigned V_6 )
{
int V_7 ;
V_7 = F_2 ( V_2 , & V_2 -> V_8 , & V_5 -> V_9 , V_6 , 256 , true ) ;
if ( V_7 ) {
F_3 ( V_2 -> V_10 , L_1 , V_7 ) ;
return V_7 ;
}
V_7 = F_4 ( V_2 , & V_5 -> V_11 , V_3 ) ;
if ( V_7 ) {
F_3 ( V_2 -> V_10 , L_2 , V_7 ) ;
F_5 ( V_2 , & V_5 -> V_9 , NULL ) ;
return V_7 ;
}
V_5 -> V_12 = F_6 ( V_5 -> V_9 ) ;
V_5 -> V_13 = F_7 ( V_5 -> V_9 ) ;
V_5 -> V_14 = 0 ;
V_5 -> V_15 = false ;
V_5 -> V_16 = NULL ;
return 0 ;
}
void F_8 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
F_9 ( V_2 , V_5 -> V_16 , V_5 -> V_11 ) ;
F_5 ( V_2 , & V_5 -> V_9 , V_5 -> V_11 ) ;
F_10 ( & V_5 -> V_11 ) ;
}
int F_11 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
struct V_17 * V_3 = & V_2 -> V_3 [ V_5 -> V_11 -> V_3 ] ;
int V_7 = 0 ;
if ( ! V_5 -> V_18 || ! V_3 -> V_19 ) {
F_3 ( V_2 -> V_10 , L_3 ) ;
return - V_20 ;
}
V_7 = F_12 ( V_2 , V_3 , 64 ) ;
if ( V_7 ) {
F_3 ( V_2 -> V_10 , L_4 , V_7 ) ;
return V_7 ;
}
F_13 ( V_2 , V_5 -> V_11 -> V_3 , V_5 ) ;
F_14 ( V_2 , V_5 -> V_11 ) ;
F_15 ( V_2 , V_3 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 )
{
int V_7 ;
if ( V_2 -> V_21 ) {
return 0 ;
}
V_7 = F_17 ( V_2 , & V_2 -> V_8 ,
V_22 * 64 * 1024 ,
V_23 ) ;
if ( V_7 ) {
return V_7 ;
}
V_2 -> V_21 = true ;
if ( F_18 ( V_2 ) ) {
F_3 ( V_2 -> V_10 , L_5 ) ;
}
return 0 ;
}
void F_19 ( struct V_1 * V_2 )
{
if ( V_2 -> V_21 ) {
F_20 ( V_2 , & V_2 -> V_8 ) ;
V_2 -> V_21 = false ;
}
}
int F_21 ( struct V_1 * V_2 )
{
return F_22 ( V_2 , & V_2 -> V_8 ) ;
}
int F_23 ( struct V_1 * V_2 )
{
return F_24 ( V_2 , & V_2 -> V_8 ) ;
}
int F_25 ( struct V_1 * V_2 )
{
unsigned V_24 ;
int V_7 ;
for ( V_24 = 0 ; V_24 < V_25 ; ++ V_24 ) {
struct V_17 * V_3 = & V_2 -> V_3 [ V_24 ] ;
if ( ! V_3 -> V_19 )
continue;
V_7 = F_26 ( V_2 , V_24 , V_3 ) ;
if ( V_7 ) {
V_3 -> V_19 = false ;
if ( V_24 == V_26 ) {
F_27 ( L_6 , V_7 ) ;
V_2 -> V_27 = false ;
return V_7 ;
} else {
F_27 ( L_7 , V_24 , V_7 ) ;
}
}
}
return 0 ;
}
void F_28 ( struct V_17 * V_3 , T_1 V_28 )
{
#if V_29
if ( V_3 -> V_30 <= 0 ) {
F_27 ( L_8 ) ;
}
#endif
V_3 -> V_3 [ V_3 -> V_31 ++ ] = V_28 ;
V_3 -> V_31 &= V_3 -> V_32 ;
V_3 -> V_30 -- ;
V_3 -> V_33 -- ;
}
int F_29 ( struct V_1 * V_2 , struct V_17 * V_3 )
{
if ( V_2 -> V_34 < V_35 )
return V_26 ;
if ( V_2 -> V_34 >= V_36 ) {
if ( V_3 == & V_2 -> V_3 [ V_37 ] )
return V_37 ;
else if ( V_3 == & V_2 -> V_3 [ V_38 ] )
return V_38 ;
}
return V_26 ;
}
void F_30 ( struct V_1 * V_2 , struct V_17 * V_3 )
{
T_2 V_39 ;
if ( V_2 -> V_40 . V_41 )
V_39 = F_31 ( V_2 -> V_40 . V_40 [ V_3 -> V_42 / 4 ] ) ;
else
V_39 = F_32 ( V_3 -> V_43 ) ;
V_3 -> V_39 = ( V_39 & V_3 -> V_44 ) >> V_3 -> V_45 ;
V_3 -> V_33 = ( V_3 -> V_39 + ( V_3 -> V_46 / 4 ) ) ;
V_3 -> V_33 -= V_3 -> V_31 ;
V_3 -> V_33 &= V_3 -> V_32 ;
if ( ! V_3 -> V_33 ) {
V_3 -> V_33 = V_3 -> V_46 / 4 ;
}
}
int F_33 ( struct V_1 * V_2 , struct V_17 * V_3 , unsigned V_47 )
{
int V_7 ;
V_47 = ( V_47 + V_3 -> V_48 ) & ~ V_3 -> V_48 ;
while ( V_47 > ( V_3 -> V_33 - 1 ) ) {
F_30 ( V_2 , V_3 ) ;
if ( V_47 < V_3 -> V_33 ) {
break;
}
V_7 = F_34 ( V_2 , F_29 ( V_2 , V_3 ) ) ;
if ( V_7 )
return V_7 ;
}
V_3 -> V_30 = V_47 ;
V_3 -> V_49 = V_3 -> V_31 ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 , struct V_17 * V_3 , unsigned V_47 )
{
int V_7 ;
F_35 ( & V_2 -> V_50 ) ;
V_7 = F_33 ( V_2 , V_3 , V_47 ) ;
if ( V_7 ) {
F_36 ( & V_2 -> V_50 ) ;
return V_7 ;
}
return 0 ;
}
void F_37 ( struct V_1 * V_2 , struct V_17 * V_3 )
{
unsigned V_51 ;
unsigned V_24 ;
V_51 = ( V_3 -> V_48 + 1 ) -
( V_3 -> V_31 & V_3 -> V_48 ) ;
for ( V_24 = 0 ; V_24 < V_51 ; V_24 ++ ) {
F_28 ( V_3 , V_3 -> V_52 ) ;
}
F_38 () ;
F_39 ( V_3 -> V_53 , ( V_3 -> V_31 << V_3 -> V_45 ) & V_3 -> V_44 ) ;
( void ) F_32 ( V_3 -> V_53 ) ;
}
void F_15 ( struct V_1 * V_2 , struct V_17 * V_3 )
{
F_37 ( V_2 , V_3 ) ;
F_36 ( & V_2 -> V_50 ) ;
}
void F_40 ( struct V_17 * V_3 )
{
V_3 -> V_31 = V_3 -> V_49 ;
}
void F_41 ( struct V_1 * V_2 , struct V_17 * V_3 )
{
F_40 ( V_3 ) ;
F_36 ( & V_2 -> V_50 ) ;
}
void F_42 ( struct V_1 * V_2 , struct V_17 * V_3 )
{
int V_7 ;
F_30 ( V_2 , V_3 ) ;
if ( V_3 -> V_39 == V_3 -> V_31 ) {
V_7 = F_33 ( V_2 , V_3 , 1 ) ;
if ( ! V_7 ) {
F_28 ( V_3 , V_3 -> V_52 ) ;
F_37 ( V_2 , V_3 ) ;
}
}
}
void F_43 ( struct V_17 * V_3 )
{
V_3 -> V_54 = V_3 -> V_39 ;
V_3 -> V_55 = V_56 ;
}
bool F_44 ( struct V_1 * V_2 , struct V_17 * V_3 )
{
unsigned long V_57 , V_58 ;
T_1 V_39 ;
V_57 = V_56 ;
if ( ! F_45 ( V_57 , V_3 -> V_55 ) ) {
F_43 ( V_3 ) ;
return false ;
}
V_39 = F_32 ( V_3 -> V_43 ) ;
V_3 -> V_39 = ( V_39 & V_3 -> V_44 ) >> V_3 -> V_45 ;
if ( V_3 -> V_39 != V_3 -> V_54 ) {
F_43 ( V_3 ) ;
return false ;
}
V_58 = F_46 ( V_57 - V_3 -> V_55 ) ;
if ( V_59 && V_58 >= V_59 ) {
F_3 ( V_2 -> V_10 , L_9 , V_58 ) ;
return true ;
}
return false ;
}
int F_47 ( struct V_1 * V_2 , struct V_17 * V_3 , unsigned V_46 ,
unsigned V_42 , unsigned V_43 , unsigned V_53 ,
T_2 V_45 , T_2 V_44 , T_2 V_52 )
{
int V_7 ;
V_3 -> V_46 = V_46 ;
V_3 -> V_42 = V_42 ;
V_3 -> V_43 = V_43 ;
V_3 -> V_53 = V_53 ;
V_3 -> V_45 = V_45 ;
V_3 -> V_44 = V_44 ;
V_3 -> V_52 = V_52 ;
if ( V_3 -> V_60 == NULL ) {
V_7 = F_48 ( V_2 , V_3 -> V_46 , V_61 , true ,
V_23 ,
NULL , & V_3 -> V_60 ) ;
if ( V_7 ) {
F_3 ( V_2 -> V_10 , L_10 , V_7 ) ;
return V_7 ;
}
V_7 = F_49 ( V_3 -> V_60 , false ) ;
if ( F_50 ( V_7 != 0 ) )
return V_7 ;
V_7 = F_51 ( V_3 -> V_60 , V_23 ,
& V_3 -> V_13 ) ;
if ( V_7 ) {
F_52 ( V_3 -> V_60 ) ;
F_3 ( V_2 -> V_10 , L_11 , V_7 ) ;
return V_7 ;
}
V_7 = F_53 ( V_3 -> V_60 ,
( void * * ) & V_3 -> V_3 ) ;
F_52 ( V_3 -> V_60 ) ;
if ( V_7 ) {
F_3 ( V_2 -> V_10 , L_12 , V_7 ) ;
return V_7 ;
}
}
V_3 -> V_32 = ( V_3 -> V_46 / 4 ) - 1 ;
V_3 -> V_33 = V_3 -> V_46 / 4 ;
if ( F_54 ( V_2 , V_3 ) ) {
F_27 ( L_13 ) ;
}
return 0 ;
}
void F_55 ( struct V_1 * V_2 , struct V_17 * V_3 )
{
int V_7 ;
struct V_62 * V_60 ;
F_35 ( & V_2 -> V_50 ) ;
V_60 = V_3 -> V_60 ;
V_3 -> V_19 = false ;
V_3 -> V_3 = NULL ;
V_3 -> V_60 = NULL ;
F_36 ( & V_2 -> V_50 ) ;
if ( V_60 ) {
V_7 = F_49 ( V_60 , false ) ;
if ( F_56 ( V_7 == 0 ) ) {
F_57 ( V_60 ) ;
F_58 ( V_60 ) ;
F_52 ( V_60 ) ;
}
F_59 ( & V_60 ) ;
}
}
static int F_60 ( struct V_63 * V_64 , void * V_65 )
{
struct V_66 * V_67 = (struct V_66 * ) V_64 -> V_68 ;
struct V_69 * V_10 = V_67 -> V_70 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_71 ;
int V_72 = * ( int * ) V_67 -> V_73 -> V_65 ;
struct V_17 * V_3 = & V_2 -> V_3 [ V_72 ] ;
unsigned V_74 , V_24 , V_75 ;
F_30 ( V_2 , V_3 ) ;
V_74 = ( V_3 -> V_46 / 4 ) - V_3 -> V_33 ;
F_61 ( V_64 , L_14 , V_3 -> V_53 , F_32 ( V_3 -> V_53 ) ) ;
F_61 ( V_64 , L_15 , V_3 -> V_43 , F_32 ( V_3 -> V_43 ) ) ;
F_61 ( V_64 , L_16 , V_3 -> V_31 ) ;
F_61 ( V_64 , L_17 , V_3 -> V_39 ) ;
F_61 ( V_64 , L_18 , V_3 -> V_33 ) ;
F_61 ( V_64 , L_19 , V_74 ) ;
V_24 = V_3 -> V_39 ;
for ( V_75 = 0 ; V_75 <= V_74 ; V_75 ++ ) {
F_61 ( V_64 , L_20 , V_24 , V_3 -> V_3 [ V_24 ] ) ;
V_24 = ( V_24 + 1 ) & V_3 -> V_32 ;
}
return 0 ;
}
static int F_62 ( struct V_63 * V_64 , void * V_65 )
{
struct V_66 * V_67 = (struct V_66 * ) V_64 -> V_68 ;
struct V_69 * V_10 = V_67 -> V_70 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_71 ;
F_63 ( & V_2 -> V_8 , V_64 ) ;
return 0 ;
}
int F_54 ( struct V_1 * V_2 , struct V_17 * V_3 )
{
#if F_64 ( V_76 )
unsigned V_24 ;
for ( V_24 = 0 ; V_24 < F_65 ( V_77 ) ; ++ V_24 ) {
struct V_78 * V_79 = & V_77 [ V_24 ] ;
int V_72 = * ( int * ) V_77 [ V_24 ] . V_65 ;
unsigned V_7 ;
if ( & V_2 -> V_3 [ V_72 ] != V_3 )
continue;
V_7 = F_66 ( V_2 , V_79 , 1 ) ;
if ( V_7 )
return V_7 ;
}
#endif
return 0 ;
}
int F_18 ( struct V_1 * V_2 )
{
#if F_64 ( V_76 )
return F_66 ( V_2 , V_80 , 1 ) ;
#else
return 0 ;
#endif
}
