T_1 F_1 ( T_1 * V_1 ,
T_1 V_2 , enum V_3 V_4 )
{
T_1 V_5 = 0 ;
int V_6 = 0 ;
for ( V_6 = 0 ; V_6 < F_2 ( V_7 ) && V_5 < V_2 ; V_6 ++ )
if ( V_7 [ V_6 ] . V_8 & V_4 )
V_1 [ V_5 ++ ] = V_7 [ V_6 ] . V_9 ;
return V_5 ;
}
static int F_3 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
unsigned int * V_14 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
return F_5 ( V_13 ,
V_16 -> V_17 [ 0 ] . V_18 , V_14 ) ;
}
static void F_6 ( struct V_10 * V_11 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
int V_6 , V_19 = F_7 ( V_11 -> V_9 ) ;
F_8 ( L_1 , V_11 -> V_20 . V_21 , V_11 ) ;
F_9 ( V_11 ) ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
struct V_22 * V_22 = & V_16 -> V_17 [ V_6 ] ;
if ( V_22 -> V_18 )
F_10 ( V_22 -> V_18 ) ;
}
F_11 ( V_16 ) ;
}
static int F_12 ( struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned V_23 , unsigned V_24 ,
struct V_25 * V_26 , unsigned V_27 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_27 ; V_6 ++ ) {
F_13 ( V_11 , V_26 [ V_6 ] . V_28 , V_26 [ V_6 ] . y1 ,
V_26 [ V_6 ] . V_29 - V_26 [ V_6 ] . V_28 ,
V_26 [ V_6 ] . V_30 - V_26 [ V_6 ] . y1 ) ;
}
return 0 ;
}
void F_14 ( struct V_10 * V_11 , int V_31 , int V_32 ,
struct V_33 * V_34 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
const struct V_35 * V_35 = V_16 -> V_35 ;
struct V_22 * V_22 = & V_16 -> V_17 [ 0 ] ;
unsigned int V_36 ;
V_36 = V_22 -> V_36 +
( V_31 * V_35 -> V_17 [ 0 ] . V_37 ) +
( V_32 * V_22 -> V_38 / V_35 -> V_17 [ 0 ] . V_39 ) ;
V_34 -> V_40 = V_35 -> V_8 ;
V_34 -> V_41 = V_22 -> V_41 + V_36 ;
V_34 -> V_42 = V_22 -> V_38 / V_35 -> V_17 [ 0 ] . V_37 ;
if ( V_35 -> V_8 == V_43 ) {
V_22 = & V_16 -> V_17 [ 1 ] ;
V_36 = V_22 -> V_36 +
( V_31 * V_35 -> V_17 [ 1 ] . V_37 ) +
( V_32 * V_22 -> V_38 / V_35 -> V_17 [ 1 ] . V_39 ) ;
V_34 -> V_44 = V_22 -> V_41 + V_36 ;
} else {
V_34 -> V_44 = 0 ;
}
}
int F_15 ( struct V_10 * V_45 ,
struct V_10 * V_46 , void * V_47 ,
void (* F_16)( void * V_47 , struct V_48 * V_18 ) )
{
int V_49 = 0 , V_6 , V_50 , V_51 ;
struct V_15 * V_52 = F_4 ( V_45 ) ;
struct V_15 * V_53 = F_4 ( V_46 ) ;
V_50 = V_45 ? F_7 ( V_45 -> V_9 ) : 0 ;
V_51 = V_46 ? F_7 ( V_46 -> V_9 ) : 0 ;
for ( V_6 = 0 ; V_6 < F_17 ( V_50 , V_51 ) ; V_6 ++ ) {
struct V_22 * V_54 , * V_55 ;
V_54 = ( V_6 < V_50 ) ? & V_52 -> V_17 [ V_6 ] : NULL ;
V_55 = ( V_6 < V_51 ) ? & V_53 -> V_17 [ V_6 ] : NULL ;
if ( V_54 ) {
F_16 ( V_47 , V_54 -> V_18 ) ;
V_54 -> V_41 = 0 ;
}
if ( V_55 && ! V_49 )
V_49 = F_18 ( V_55 -> V_18 , & V_55 -> V_41 , true ) ;
}
if ( V_49 ) {
for ( V_6 = 0 ; V_6 < V_51 ; V_6 ++ ) {
struct V_22 * V_55 = & V_52 -> V_17 [ V_6 ] ;
if ( V_55 -> V_41 ) {
F_16 ( V_47 , V_55 -> V_18 ) ;
V_55 -> V_41 = 0 ;
}
}
}
return V_49 ;
}
struct V_48 * F_19 ( struct V_10 * V_11 , int V_56 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
if ( V_56 >= F_7 ( V_11 -> V_9 ) )
return NULL ;
return V_16 -> V_17 [ V_56 ] . V_18 ;
}
struct V_57 * F_20 (
struct V_10 * V_11 , struct V_57 * V_58 )
{
struct V_59 * V_60 = V_11 -> V_60 ;
struct V_61 * V_62 = & V_60 -> V_63 . V_62 ;
struct V_57 * V_64 = V_58 ;
if ( ! V_58 ) {
return F_21 ( V_62 , F_22 ( * V_58 ) , V_65 ) ;
}
F_23 (connector, connector_list, head) {
if ( V_64 != V_58 ) {
struct V_66 * V_67 = V_64 -> V_67 ;
struct V_68 * V_69 = V_67 ? V_67 -> V_69 : NULL ;
if ( V_69 && V_69 -> V_11 == V_11 ) {
return V_64 ;
}
}
}
return NULL ;
}
void F_13 ( struct V_10 * V_11 ,
int V_31 , int V_32 , int V_70 , int V_71 )
{
struct V_57 * V_64 = NULL ;
F_24 ( L_2 , V_31 , V_32 , V_70 , V_71 , V_11 ) ;
while ( ( V_64 = F_20 ( V_11 , V_64 ) ) ) {
if ( V_64 -> V_67 && V_64 -> V_67 -> V_69 ) {
struct V_68 * V_69 = V_64 -> V_67 -> V_69 ;
int V_72 = F_17 ( 0 , V_31 - V_69 -> V_31 ) ;
int V_73 = F_17 ( 0 , V_32 - V_69 -> V_32 ) ;
int V_74 = V_70 + ( V_31 - V_69 -> V_31 ) - V_72 ;
int V_75 = V_71 + ( V_32 - V_69 -> V_32 ) - V_73 ;
F_25 ( V_64 , V_72 , V_73 , V_74 , V_75 ) ;
}
}
}
void F_26 ( struct V_10 * V_11 , struct V_76 * V_77 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
int V_6 , V_19 = F_7 ( V_11 -> V_9 ) ;
F_27 ( V_77 , L_3 , V_11 -> V_78 , V_11 -> V_79 ,
( char * ) & V_11 -> V_9 ) ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
struct V_22 * V_22 = & V_16 -> V_17 [ V_6 ] ;
F_27 ( V_77 , L_4 ,
V_6 , V_22 -> V_36 , V_22 -> V_38 ) ;
F_28 ( V_22 -> V_18 , V_77 ) ;
}
}
struct V_10 * F_29 ( struct V_59 * V_60 ,
struct V_12 * V_80 , struct V_81 * V_82 )
{
struct V_48 * V_83 [ 4 ] ;
struct V_10 * V_11 ;
int V_49 ;
V_49 = F_30 ( V_60 , V_80 , V_82 -> V_9 ,
V_83 , V_82 -> V_84 ) ;
if ( V_49 )
return F_31 ( V_49 ) ;
V_11 = F_32 ( V_60 , V_82 , V_83 ) ;
if ( F_33 ( V_11 ) ) {
int V_6 , V_19 = F_7 ( V_82 -> V_9 ) ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ )
F_10 ( V_83 [ V_6 ] ) ;
return V_11 ;
}
return V_11 ;
}
struct V_10 * F_32 ( struct V_59 * V_60 ,
struct V_81 * V_82 , struct V_48 * * V_83 )
{
struct V_15 * V_16 ;
struct V_10 * V_11 = NULL ;
const struct V_35 * V_35 = NULL ;
int V_49 , V_6 , V_19 = F_7 ( V_82 -> V_9 ) ;
F_8 ( L_5 ,
V_60 , V_82 , V_82 -> V_78 , V_82 -> V_79 ,
( char * ) & V_82 -> V_9 ) ;
for ( V_6 = 0 ; V_6 < F_2 ( V_7 ) ; V_6 ++ ) {
if ( V_7 [ V_6 ] . V_9 == V_82 -> V_9 ) {
V_35 = & V_7 [ V_6 ] ;
break;
}
}
if ( ! V_35 ) {
F_34 ( V_60 -> V_60 , L_6 ,
( char * ) & V_82 -> V_9 ) ;
V_49 = - V_85 ;
goto V_86;
}
V_16 = F_35 ( sizeof( * V_16 ) , V_87 ) ;
if ( ! V_16 ) {
F_34 ( V_60 -> V_60 , L_7 ) ;
V_49 = - V_88 ;
goto V_86;
}
V_11 = & V_16 -> V_20 ;
V_49 = F_36 ( V_60 , V_11 , & V_89 ) ;
if ( V_49 ) {
F_34 ( V_60 -> V_60 , L_8 , V_49 ) ;
goto V_86;
}
F_8 ( L_9 , V_11 -> V_20 . V_21 , V_11 ) ;
V_16 -> V_35 = V_35 ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
struct V_22 * V_22 = & V_16 -> V_17 [ V_6 ] ;
int V_90 , V_38 = V_82 -> V_91 [ V_6 ] ;
if ( V_38 < ( V_82 -> V_78 * V_35 -> V_17 [ V_6 ] . V_37 ) ) {
F_34 ( V_60 -> V_60 , L_10 ,
V_38 , V_82 -> V_78 * V_35 -> V_17 [ V_6 ] . V_37 ) ;
V_49 = - V_85 ;
goto V_86;
}
V_90 = V_38 * V_82 -> V_79 / V_35 -> V_17 [ V_6 ] . V_39 ;
if ( V_90 > ( V_83 [ V_6 ] -> V_90 - V_82 -> V_92 [ V_6 ] ) ) {
F_34 ( V_60 -> V_60 , L_11 ,
V_83 [ V_6 ] -> V_90 - V_82 -> V_92 [ V_6 ] , V_90 ) ;
V_49 = - V_85 ;
goto V_86;
}
V_22 -> V_18 = V_83 [ V_6 ] ;
V_22 -> V_36 = V_82 -> V_92 [ V_6 ] ;
V_22 -> V_38 = V_38 ;
V_22 -> V_41 = 0 ;
}
F_37 ( V_11 , V_82 ) ;
return V_11 ;
V_86:
if ( V_11 ) {
F_6 ( V_11 ) ;
}
return F_31 ( V_49 ) ;
}
