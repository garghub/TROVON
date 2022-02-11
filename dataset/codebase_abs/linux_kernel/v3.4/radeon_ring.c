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
( * V_27 ) -> V_51 = false ;
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
struct V_26 * V_52 = * V_27 ;
* V_27 = NULL ;
if ( V_52 == NULL ) {
return;
}
F_13 ( & V_25 -> V_38 . V_39 ) ;
if ( V_52 -> V_29 && ! V_52 -> V_29 -> V_30 ) {
F_8 ( V_25 , & V_52 -> V_31 ) ;
F_7 ( & V_52 -> V_29 ) ;
}
F_14 ( & V_25 -> V_38 . V_39 ) ;
}
int F_18 ( struct V_24 * V_25 , struct V_26 * V_27 )
{
struct V_16 * V_17 = & V_25 -> V_17 [ V_27 -> V_29 -> V_17 ] ;
int V_35 = 0 ;
if ( ! V_27 -> V_53 || ! V_17 -> V_54 ) {
F_4 ( L_4 , V_27 -> V_3 ) ;
return - V_55 ;
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
struct V_56 V_52 ;
int V_36 , V_35 ;
V_35 = F_24 ( V_25 , & V_52 ,
V_43 * 64 * 1024 ,
V_57 ) ;
if ( V_35 ) {
return V_35 ;
}
F_13 ( & V_25 -> V_38 . V_39 ) ;
if ( V_25 -> V_38 . V_54 ) {
F_14 ( & V_25 -> V_38 . V_39 ) ;
F_25 ( V_25 , & V_52 ) ;
return 0 ;
}
V_25 -> V_38 . V_45 = V_52 ;
F_26 ( & V_25 -> V_38 . V_45 . V_31 ) ;
for ( V_36 = 0 ; V_36 < V_43 ; V_36 ++ ) {
V_25 -> V_38 . V_44 [ V_36 ] . V_29 = NULL ;
V_25 -> V_38 . V_44 [ V_36 ] . V_3 = V_36 ;
V_25 -> V_38 . V_44 [ V_36 ] . V_53 = 0 ;
F_26 ( & V_25 -> V_38 . V_44 [ V_36 ] . V_31 . V_58 ) ;
}
V_25 -> V_38 . V_40 = 0 ;
V_25 -> V_38 . V_54 = true ;
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
if ( V_25 -> V_38 . V_54 ) {
for ( V_36 = 0 ; V_36 < V_43 ; V_36 ++ ) {
F_8 ( V_25 , & V_25 -> V_38 . V_44 [ V_36 ] . V_31 ) ;
F_7 ( & V_25 -> V_38 . V_44 [ V_36 ] . V_29 ) ;
}
F_25 ( V_25 , & V_25 -> V_38 . V_45 ) ;
V_25 -> V_38 . V_54 = false ;
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
if ( V_25 -> V_59 < V_60 )
return V_61 ;
if ( V_25 -> V_59 >= V_62 ) {
if ( V_17 == & V_25 -> V_17 [ V_63 ] )
return V_63 ;
else if ( V_17 == & V_25 -> V_17 [ V_64 ] )
return V_64 ;
}
return V_61 ;
}
void F_36 ( struct V_24 * V_25 , struct V_16 * V_17 )
{
T_1 V_65 ;
if ( V_25 -> V_66 . V_67 )
V_65 = F_37 ( V_25 -> V_66 . V_66 [ V_17 -> V_68 / 4 ] ) ;
else
V_65 = F_38 ( V_17 -> V_69 ) ;
V_17 -> V_65 = ( V_65 & V_17 -> V_70 ) >> V_17 -> V_71 ;
V_17 -> V_23 = ( V_17 -> V_65 + ( V_17 -> V_72 / 4 ) ) ;
V_17 -> V_23 -= V_17 -> V_21 ;
V_17 -> V_23 &= V_17 -> V_22 ;
if ( ! V_17 -> V_23 ) {
V_17 -> V_23 = V_17 -> V_72 / 4 ;
}
}
int F_39 ( struct V_24 * V_25 , struct V_16 * V_17 , unsigned V_73 )
{
int V_35 ;
V_73 = ( V_73 + V_17 -> V_74 ) & ~ V_17 -> V_74 ;
while ( V_73 > ( V_17 -> V_23 - 1 ) ) {
F_36 ( V_25 , V_17 ) ;
if ( V_73 < V_17 -> V_23 ) {
break;
}
V_35 = F_40 ( V_25 , F_35 ( V_25 , V_17 ) ) ;
if ( V_35 )
return V_35 ;
}
V_17 -> V_20 = V_73 ;
V_17 -> V_75 = V_17 -> V_21 ;
return 0 ;
}
int F_19 ( struct V_24 * V_25 , struct V_16 * V_17 , unsigned V_73 )
{
int V_35 ;
F_41 ( & V_17 -> V_39 ) ;
V_35 = F_39 ( V_25 , V_17 , V_73 ) ;
if ( V_35 ) {
F_42 ( & V_17 -> V_39 ) ;
return V_35 ;
}
return 0 ;
}
void F_43 ( struct V_24 * V_25 , struct V_16 * V_17 )
{
unsigned V_76 ;
unsigned V_36 ;
V_76 = ( V_17 -> V_74 + 1 ) -
( V_17 -> V_21 & V_17 -> V_74 ) ;
for ( V_36 = 0 ; V_36 < V_76 ; V_36 ++ ) {
F_3 ( V_17 , V_17 -> V_77 ) ;
}
F_44 () ;
F_45 ( V_17 -> V_78 , ( V_17 -> V_21 << V_17 -> V_71 ) & V_17 -> V_70 ) ;
( void ) F_38 ( V_17 -> V_78 ) ;
}
void F_22 ( struct V_24 * V_25 , struct V_16 * V_17 )
{
F_43 ( V_25 , V_17 ) ;
F_42 ( & V_17 -> V_39 ) ;
}
void F_46 ( struct V_24 * V_25 , struct V_16 * V_17 )
{
V_17 -> V_21 = V_17 -> V_75 ;
F_42 ( & V_17 -> V_39 ) ;
}
int F_47 ( struct V_24 * V_25 , struct V_16 * V_17 , unsigned V_72 ,
unsigned V_68 , unsigned V_69 , unsigned V_78 ,
T_1 V_71 , T_1 V_70 , T_1 V_77 )
{
int V_35 ;
V_17 -> V_72 = V_72 ;
V_17 -> V_68 = V_68 ;
V_17 -> V_69 = V_69 ;
V_17 -> V_78 = V_78 ;
V_17 -> V_71 = V_71 ;
V_17 -> V_70 = V_70 ;
V_17 -> V_77 = V_77 ;
if ( V_17 -> V_79 == NULL ) {
V_35 = F_48 ( V_25 , V_17 -> V_72 , V_12 , true ,
V_57 ,
& V_17 -> V_79 ) ;
if ( V_35 ) {
F_12 ( V_25 -> V_37 , L_9 , V_35 ) ;
return V_35 ;
}
V_35 = F_49 ( V_17 -> V_79 , false ) ;
if ( F_50 ( V_35 != 0 ) )
return V_35 ;
V_35 = F_51 ( V_17 -> V_79 , V_57 ,
& V_17 -> V_49 ) ;
if ( V_35 ) {
F_52 ( V_17 -> V_79 ) ;
F_12 ( V_25 -> V_37 , L_10 , V_35 ) ;
return V_35 ;
}
V_35 = F_53 ( V_17 -> V_79 ,
( void * * ) & V_17 -> V_17 ) ;
F_52 ( V_17 -> V_79 ) ;
if ( V_35 ) {
F_12 ( V_25 -> V_37 , L_11 , V_35 ) ;
return V_35 ;
}
}
V_17 -> V_22 = ( V_17 -> V_72 / 4 ) - 1 ;
V_17 -> V_23 = V_17 -> V_72 / 4 ;
return 0 ;
}
void F_54 ( struct V_24 * V_25 , struct V_16 * V_17 )
{
int V_35 ;
struct V_80 * V_79 ;
F_41 ( & V_17 -> V_39 ) ;
V_79 = V_17 -> V_79 ;
V_17 -> V_17 = NULL ;
V_17 -> V_79 = NULL ;
F_42 ( & V_17 -> V_39 ) ;
if ( V_79 ) {
V_35 = F_49 ( V_79 , false ) ;
if ( F_55 ( V_35 == 0 ) ) {
F_56 ( V_79 ) ;
F_57 ( V_79 ) ;
F_52 ( V_79 ) ;
}
F_58 ( & V_79 ) ;
}
}
static int F_59 ( struct V_81 * V_82 , void * V_83 )
{
struct V_84 * V_85 = (struct V_84 * ) V_82 -> V_86 ;
struct V_87 * V_37 = V_85 -> V_88 -> V_37 ;
struct V_24 * V_25 = V_37 -> V_89 ;
int V_90 = * ( int * ) V_85 -> V_91 -> V_83 ;
struct V_16 * V_17 = & V_25 -> V_17 [ V_90 ] ;
unsigned V_92 , V_36 , V_93 ;
F_36 ( V_25 , V_17 ) ;
V_92 = ( V_17 -> V_72 / 4 ) - V_17 -> V_23 ;
F_60 ( V_82 , L_12 , V_17 -> V_78 , F_38 ( V_17 -> V_78 ) ) ;
F_60 ( V_82 , L_13 , V_17 -> V_69 , F_38 ( V_17 -> V_69 ) ) ;
F_60 ( V_82 , L_14 , V_17 -> V_21 ) ;
F_60 ( V_82 , L_15 , V_17 -> V_65 ) ;
F_60 ( V_82 , L_16 , V_17 -> V_23 ) ;
F_60 ( V_82 , L_17 , V_92 ) ;
V_36 = V_17 -> V_65 ;
for ( V_93 = 0 ; V_93 <= V_92 ; V_93 ++ ) {
F_60 ( V_82 , L_18 , V_36 , V_17 -> V_17 [ V_36 ] ) ;
V_36 = ( V_36 + 1 ) & V_17 -> V_22 ;
}
return 0 ;
}
static int F_61 ( struct V_81 * V_82 , void * V_83 )
{
struct V_84 * V_85 = (struct V_84 * ) V_82 -> V_86 ;
struct V_87 * V_37 = V_85 -> V_88 -> V_37 ;
struct V_24 * V_25 = V_37 -> V_89 ;
struct V_26 * V_27 = & V_25 -> V_38 . V_44 [ * ( ( unsigned * ) V_85 -> V_91 -> V_83 ) ] ;
unsigned V_36 ;
if ( V_27 == NULL ) {
return 0 ;
}
F_60 ( V_82 , L_19 , V_27 -> V_3 ) ;
F_60 ( V_82 , L_20 , V_27 -> V_29 ) ;
F_60 ( V_82 , L_21 , V_27 -> V_53 ) ;
for ( V_36 = 0 ; V_36 < V_27 -> V_53 ; V_36 ++ ) {
F_60 ( V_82 , L_22 , V_36 , V_27 -> V_46 [ V_36 ] ) ;
}
return 0 ;
}
int F_29 ( struct V_24 * V_25 )
{
#if F_62 ( V_94 )
if ( V_25 -> V_59 >= V_62 )
return F_63 ( V_25 , V_95 ,
F_64 ( V_95 ) ) ;
else
return F_63 ( V_25 , V_95 , 1 ) ;
#else
return 0 ;
#endif
}
int F_28 ( struct V_24 * V_25 )
{
#if F_62 ( V_94 )
unsigned V_36 ;
for ( V_36 = 0 ; V_36 < V_43 ; V_36 ++ ) {
sprintf ( V_96 [ V_36 ] , L_23 , V_36 ) ;
V_97 [ V_36 ] = V_36 ;
V_98 [ V_36 ] . V_99 = V_96 [ V_36 ] ;
V_98 [ V_36 ] . V_100 = & F_61 ;
V_98 [ V_36 ] . V_101 = 0 ;
V_98 [ V_36 ] . V_83 = & V_97 [ V_36 ] ;
}
return F_63 ( V_25 , V_98 ,
V_43 ) ;
#else
return 0 ;
#endif
}
