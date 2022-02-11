T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 [ V_2 -> V_7 ] ;
T_1 V_8 , V_9 ;
T_1 V_10 = 0 ;
int V_11 ;
V_8 = ( V_3 * 4 ) / V_12 ;
V_9 = ( V_3 * 4 ) % V_12 ;
if ( V_5 -> V_13 [ 0 ] == V_8 )
return V_5 -> V_14 [ 0 ] [ V_9 / 4 ] ;
if ( V_5 -> V_13 [ 1 ] == V_8 )
return V_5 -> V_14 [ 1 ] [ V_9 / 4 ] ;
V_11 = F_2 ( V_2 , V_8 ) ;
if ( V_11 < 0 ) {
V_2 -> V_15 = V_11 ;
return 0 ;
}
V_10 = V_5 -> V_14 [ V_11 ] [ V_9 / 4 ] ;
return V_10 ;
}
void F_3 ( struct V_16 * V_17 , T_2 V_18 )
{
#if V_19
if ( V_17 -> V_20 <= 0 ) {
F_4 ( L_1 ) ;
}
#endif
V_17 -> V_17 [ V_17 -> V_21 ++ ] = V_18 ;
V_17 -> V_21 &= V_17 -> V_22 ;
V_17 -> V_20 -- ;
V_17 -> V_23 -- ;
}
bool F_5 ( struct V_24 * V_25 , struct V_26 * V_27 )
{
bool V_28 = false ;
if ( V_27 -> V_29 && V_27 -> V_29 -> V_30 ) {
if ( F_6 ( V_27 -> V_29 ) ) {
F_7 ( & V_27 -> V_29 ) ;
F_8 ( V_25 , & V_27 -> V_31 ) ;
V_28 = true ;
}
}
return V_28 ;
}
int F_9 ( struct V_24 * V_25 , int V_17 ,
struct V_26 * * V_27 , unsigned V_32 )
{
struct V_33 * V_29 ;
unsigned V_34 = 0 ;
int V_35 = 0 , V_36 , V_3 ;
* V_27 = NULL ;
V_32 = F_10 ( V_32 , 256 ) ;
V_35 = F_11 ( V_25 , & V_29 , V_17 ) ;
if ( V_35 ) {
F_12 ( V_25 -> V_37 , L_2 ) ;
return V_35 ;
}
F_13 ( & V_25 -> V_38 . V_39 ) ;
V_3 = V_25 -> V_38 . V_40 ;
V_41:
if ( V_34 > 5 ) {
F_12 ( V_25 -> V_37 , L_3 ) ;
F_14 ( & V_25 -> V_38 . V_39 ) ;
F_7 ( & V_29 ) ;
return - V_42 ;
}
V_34 ++ ;
for ( V_36 = 0 ; V_36 < V_43 ; V_36 ++ ) {
F_5 ( V_25 , & V_25 -> V_38 . V_44 [ V_3 ] ) ;
if ( V_25 -> V_38 . V_44 [ V_3 ] . V_29 == NULL ) {
V_35 = F_15 ( V_25 , & V_25 -> V_38 . V_45 ,
& V_25 -> V_38 . V_44 [ V_3 ] . V_31 ,
V_32 , 256 ) ;
if ( ! V_35 ) {
* V_27 = & V_25 -> V_38 . V_44 [ V_3 ] ;
( * V_27 ) -> V_46 = V_25 -> V_38 . V_45 . V_47 ;
( * V_27 ) -> V_46 += ( ( * V_27 ) -> V_31 . V_48 >> 2 ) ;
( * V_27 ) -> V_49 = V_25 -> V_38 . V_45 . V_49 ;
( * V_27 ) -> V_49 += ( * V_27 ) -> V_31 . V_48 ;
( * V_27 ) -> V_29 = V_29 ;
( * V_27 ) -> V_50 = 0 ;
V_25 -> V_38 . V_40 = ( 1 + V_3 ) ;
V_25 -> V_38 . V_40 &= ( V_43 - 1 ) ;
F_14 ( & V_25 -> V_38 . V_39 ) ;
return 0 ;
}
}
V_3 = ( V_3 + 1 ) & ( V_43 - 1 ) ;
}
for ( V_36 = 0 ; V_36 < V_43 ; V_36 ++ ) {
if ( V_25 -> V_38 . V_44 [ V_3 ] . V_29 && V_25 -> V_38 . V_44 [ V_3 ] . V_29 -> V_30 ) {
V_35 = F_16 ( V_25 -> V_38 . V_44 [ V_3 ] . V_29 , false ) ;
if ( ! V_35 ) {
goto V_41;
}
break;
}
V_3 = ( V_3 + 1 ) & ( V_43 - 1 ) ;
}
F_14 ( & V_25 -> V_38 . V_39 ) ;
F_7 ( & V_29 ) ;
return V_35 ;
}
void F_17 ( struct V_24 * V_25 , struct V_26 * * V_27 )
{
struct V_26 * V_51 = * V_27 ;
* V_27 = NULL ;
if ( V_51 == NULL ) {
return;
}
F_13 ( & V_25 -> V_38 . V_39 ) ;
if ( V_51 -> V_29 && ! V_51 -> V_29 -> V_30 ) {
F_8 ( V_25 , & V_51 -> V_31 ) ;
F_7 ( & V_51 -> V_29 ) ;
}
F_14 ( & V_25 -> V_38 . V_39 ) ;
}
int F_18 ( struct V_24 * V_25 , struct V_26 * V_27 )
{
struct V_16 * V_17 = & V_25 -> V_17 [ V_27 -> V_29 -> V_17 ] ;
int V_35 = 0 ;
if ( ! V_27 -> V_52 || ! V_17 -> V_53 ) {
F_4 ( L_4 , V_27 -> V_3 ) ;
return - V_54 ;
}
V_35 = F_19 ( V_25 , V_17 , 64 ) ;
if ( V_35 ) {
F_4 ( L_5 , V_35 ) ;
return V_35 ;
}
F_20 ( V_25 , V_27 -> V_29 -> V_17 , V_27 ) ;
F_21 ( V_25 , V_27 -> V_29 ) ;
F_22 ( V_25 , V_17 ) ;
return 0 ;
}
int F_23 ( struct V_24 * V_25 )
{
struct V_55 V_51 ;
int V_36 , V_35 ;
V_35 = F_24 ( V_25 , & V_51 ,
V_43 * 64 * 1024 ,
V_56 ) ;
if ( V_35 ) {
return V_35 ;
}
F_13 ( & V_25 -> V_38 . V_39 ) ;
if ( V_25 -> V_38 . V_53 ) {
F_14 ( & V_25 -> V_38 . V_39 ) ;
F_25 ( V_25 , & V_51 ) ;
return 0 ;
}
V_25 -> V_38 . V_45 = V_51 ;
F_26 ( & V_25 -> V_38 . V_45 . V_31 ) ;
for ( V_36 = 0 ; V_36 < V_43 ; V_36 ++ ) {
V_25 -> V_38 . V_44 [ V_36 ] . V_29 = NULL ;
V_25 -> V_38 . V_44 [ V_36 ] . V_3 = V_36 ;
V_25 -> V_38 . V_44 [ V_36 ] . V_52 = 0 ;
F_26 ( & V_25 -> V_38 . V_44 [ V_36 ] . V_31 . V_57 ) ;
}
V_25 -> V_38 . V_40 = 0 ;
V_25 -> V_38 . V_53 = true ;
F_27 ( L_6 ) ;
if ( F_28 ( V_25 ) ) {
F_4 ( L_7 ) ;
}
if ( F_29 ( V_25 ) ) {
F_4 ( L_8 ) ;
}
F_14 ( & V_25 -> V_38 . V_39 ) ;
return 0 ;
}
void F_30 ( struct V_24 * V_25 )
{
unsigned V_36 ;
F_13 ( & V_25 -> V_38 . V_39 ) ;
if ( V_25 -> V_38 . V_53 ) {
for ( V_36 = 0 ; V_36 < V_43 ; V_36 ++ ) {
F_8 ( V_25 , & V_25 -> V_38 . V_44 [ V_36 ] . V_31 ) ;
F_7 ( & V_25 -> V_38 . V_44 [ V_36 ] . V_29 ) ;
}
F_25 ( V_25 , & V_25 -> V_38 . V_45 ) ;
V_25 -> V_38 . V_53 = false ;
}
F_14 ( & V_25 -> V_38 . V_39 ) ;
}
int F_31 ( struct V_24 * V_25 )
{
return F_32 ( V_25 , & V_25 -> V_38 . V_45 ) ;
}
int F_33 ( struct V_24 * V_25 )
{
return F_34 ( V_25 , & V_25 -> V_38 . V_45 ) ;
}
int F_35 ( struct V_24 * V_25 , struct V_16 * V_17 )
{
if ( V_25 -> V_58 < V_59 )
return V_60 ;
if ( V_25 -> V_58 >= V_61 ) {
if ( V_17 == & V_25 -> V_17 [ V_62 ] )
return V_62 ;
else if ( V_17 == & V_25 -> V_17 [ V_63 ] )
return V_63 ;
}
return V_60 ;
}
void F_36 ( struct V_24 * V_25 , struct V_16 * V_17 )
{
T_1 V_64 ;
if ( V_25 -> V_65 . V_66 )
V_64 = F_37 ( V_25 -> V_65 . V_65 [ V_17 -> V_67 / 4 ] ) ;
else
V_64 = F_38 ( V_17 -> V_68 ) ;
V_17 -> V_64 = ( V_64 & V_17 -> V_69 ) >> V_17 -> V_70 ;
V_17 -> V_23 = ( V_17 -> V_64 + ( V_17 -> V_71 / 4 ) ) ;
V_17 -> V_23 -= V_17 -> V_21 ;
V_17 -> V_23 &= V_17 -> V_22 ;
if ( ! V_17 -> V_23 ) {
V_17 -> V_23 = V_17 -> V_71 / 4 ;
}
}
int F_39 ( struct V_24 * V_25 , struct V_16 * V_17 , unsigned V_72 )
{
int V_35 ;
V_72 = ( V_72 + V_17 -> V_73 ) & ~ V_17 -> V_73 ;
while ( V_72 > ( V_17 -> V_23 - 1 ) ) {
F_36 ( V_25 , V_17 ) ;
if ( V_72 < V_17 -> V_23 ) {
break;
}
V_35 = F_40 ( V_25 , F_35 ( V_25 , V_17 ) ) ;
if ( V_35 )
return V_35 ;
}
V_17 -> V_20 = V_72 ;
V_17 -> V_74 = V_17 -> V_21 ;
return 0 ;
}
int F_19 ( struct V_24 * V_25 , struct V_16 * V_17 , unsigned V_72 )
{
int V_35 ;
F_41 ( & V_17 -> V_39 ) ;
V_35 = F_39 ( V_25 , V_17 , V_72 ) ;
if ( V_35 ) {
F_42 ( & V_17 -> V_39 ) ;
return V_35 ;
}
return 0 ;
}
void F_43 ( struct V_24 * V_25 , struct V_16 * V_17 )
{
unsigned V_75 ;
unsigned V_36 ;
V_75 = ( V_17 -> V_73 + 1 ) -
( V_17 -> V_21 & V_17 -> V_73 ) ;
for ( V_36 = 0 ; V_36 < V_75 ; V_36 ++ ) {
F_3 ( V_17 , V_17 -> V_76 ) ;
}
F_44 () ;
F_45 ( V_17 -> V_77 , ( V_17 -> V_21 << V_17 -> V_70 ) & V_17 -> V_69 ) ;
( void ) F_38 ( V_17 -> V_77 ) ;
}
void F_22 ( struct V_24 * V_25 , struct V_16 * V_17 )
{
F_43 ( V_25 , V_17 ) ;
F_42 ( & V_17 -> V_39 ) ;
}
void F_46 ( struct V_24 * V_25 , struct V_16 * V_17 )
{
V_17 -> V_21 = V_17 -> V_74 ;
F_42 ( & V_17 -> V_39 ) ;
}
int F_47 ( struct V_24 * V_25 , struct V_16 * V_17 , unsigned V_71 ,
unsigned V_67 , unsigned V_68 , unsigned V_77 ,
T_1 V_70 , T_1 V_69 , T_1 V_76 )
{
int V_35 ;
V_17 -> V_71 = V_71 ;
V_17 -> V_67 = V_67 ;
V_17 -> V_68 = V_68 ;
V_17 -> V_77 = V_77 ;
V_17 -> V_70 = V_70 ;
V_17 -> V_69 = V_69 ;
V_17 -> V_76 = V_76 ;
if ( V_17 -> V_78 == NULL ) {
V_35 = F_48 ( V_25 , V_17 -> V_71 , V_12 , true ,
V_56 ,
& V_17 -> V_78 ) ;
if ( V_35 ) {
F_12 ( V_25 -> V_37 , L_9 , V_35 ) ;
return V_35 ;
}
V_35 = F_49 ( V_17 -> V_78 , false ) ;
if ( F_50 ( V_35 != 0 ) )
return V_35 ;
V_35 = F_51 ( V_17 -> V_78 , V_56 ,
& V_17 -> V_49 ) ;
if ( V_35 ) {
F_52 ( V_17 -> V_78 ) ;
F_12 ( V_25 -> V_37 , L_10 , V_35 ) ;
return V_35 ;
}
V_35 = F_53 ( V_17 -> V_78 ,
( void * * ) & V_17 -> V_17 ) ;
F_52 ( V_17 -> V_78 ) ;
if ( V_35 ) {
F_12 ( V_25 -> V_37 , L_11 , V_35 ) ;
return V_35 ;
}
}
V_17 -> V_22 = ( V_17 -> V_71 / 4 ) - 1 ;
V_17 -> V_23 = V_17 -> V_71 / 4 ;
return 0 ;
}
void F_54 ( struct V_24 * V_25 , struct V_16 * V_17 )
{
int V_35 ;
struct V_79 * V_78 ;
F_41 ( & V_17 -> V_39 ) ;
V_78 = V_17 -> V_78 ;
V_17 -> V_17 = NULL ;
V_17 -> V_78 = NULL ;
F_42 ( & V_17 -> V_39 ) ;
if ( V_78 ) {
V_35 = F_49 ( V_78 , false ) ;
if ( F_55 ( V_35 == 0 ) ) {
F_56 ( V_78 ) ;
F_57 ( V_78 ) ;
F_52 ( V_78 ) ;
}
F_58 ( & V_78 ) ;
}
}
static int F_59 ( struct V_80 * V_81 , void * V_82 )
{
struct V_83 * V_84 = (struct V_83 * ) V_81 -> V_85 ;
struct V_86 * V_37 = V_84 -> V_87 -> V_37 ;
struct V_24 * V_25 = V_37 -> V_88 ;
int V_89 = * ( int * ) V_84 -> V_90 -> V_82 ;
struct V_16 * V_17 = & V_25 -> V_17 [ V_89 ] ;
unsigned V_91 , V_36 , V_92 ;
F_36 ( V_25 , V_17 ) ;
V_91 = ( V_17 -> V_71 / 4 ) - V_17 -> V_23 ;
F_60 ( V_81 , L_12 , V_17 -> V_77 , F_38 ( V_17 -> V_77 ) ) ;
F_60 ( V_81 , L_13 , V_17 -> V_68 , F_38 ( V_17 -> V_68 ) ) ;
F_60 ( V_81 , L_14 , V_17 -> V_21 ) ;
F_60 ( V_81 , L_15 , V_17 -> V_64 ) ;
F_60 ( V_81 , L_16 , V_17 -> V_23 ) ;
F_60 ( V_81 , L_17 , V_91 ) ;
V_36 = V_17 -> V_64 ;
for ( V_92 = 0 ; V_92 <= V_91 ; V_92 ++ ) {
F_60 ( V_81 , L_18 , V_36 , V_17 -> V_17 [ V_36 ] ) ;
V_36 = ( V_36 + 1 ) & V_17 -> V_22 ;
}
return 0 ;
}
static int F_61 ( struct V_80 * V_81 , void * V_82 )
{
struct V_83 * V_84 = (struct V_83 * ) V_81 -> V_85 ;
struct V_26 * V_27 = V_84 -> V_90 -> V_82 ;
unsigned V_36 ;
if ( V_27 == NULL ) {
return 0 ;
}
F_60 ( V_81 , L_19 , V_27 -> V_3 ) ;
F_60 ( V_81 , L_20 , V_27 -> V_29 ) ;
F_60 ( V_81 , L_21 , V_27 -> V_52 ) ;
for ( V_36 = 0 ; V_36 < V_27 -> V_52 ; V_36 ++ ) {
F_60 ( V_81 , L_22 , V_36 , V_27 -> V_46 [ V_36 ] ) ;
}
return 0 ;
}
int F_29 ( struct V_24 * V_25 )
{
#if F_62 ( V_93 )
if ( V_25 -> V_58 >= V_61 )
return F_63 ( V_25 , V_94 ,
F_64 ( V_94 ) ) ;
else
return F_63 ( V_25 , V_94 , 1 ) ;
#else
return 0 ;
#endif
}
int F_28 ( struct V_24 * V_25 )
{
#if F_62 ( V_93 )
unsigned V_36 ;
for ( V_36 = 0 ; V_36 < V_43 ; V_36 ++ ) {
sprintf ( V_95 [ V_36 ] , L_23 , V_36 ) ;
V_96 [ V_36 ] . V_97 = V_95 [ V_36 ] ;
V_96 [ V_36 ] . V_98 = & F_61 ;
V_96 [ V_36 ] . V_99 = 0 ;
V_96 [ V_36 ] . V_82 = & V_25 -> V_38 . V_44 [ V_36 ] ;
}
return F_63 ( V_25 , V_96 ,
V_43 ) ;
#else
return 0 ;
#endif
}
